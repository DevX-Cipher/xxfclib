/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * UBI data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_ubi_volume_table_record_fields[] = {
    SX_FIELD("reserved_pebs","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("alignment","uint32",4,4,SX_SIZE),
    SX_FIELD("data_padding","uint32",8,4,SX_SIZE),
    SX_FIELD("volume_type","uint8",12,1,SX_ID),
    SX_FIELD("update_marker","uint8",13,1,SX_FLAGS),
    SX_FIELD("name_length","uint16",14,2,SX_SIZE),
    SX_FIELD("name","char[128]",16,128,SX_NONE),
    SX_FIELD("flags","uint8",144,1,SX_FLAGS),
    SX_FIELD("padding","byte[23]",145,23,SX_RESERVED),
    SX_FIELD("crc","uint32",168,4,SX_CHECKSUM),
};
const sx_layout sx_dm_ubi_volume_table_record = {0x60290034U,"ubi_volume_table_record",sx_dm_ubi_volume_table_record_fields,SX_COUNT(sx_dm_ubi_volume_table_record_fields),SX_BE};
static bool sx_dm_ubi_ec(sx_context*c,uint64_t p,uint8_t*h){return sx_dm_read(c,p,h,64)&&!xx_rt_memcmp(h,"UBI#",4)&&sx_dm_u32(h,60,true)==~xx_crc32_calc(0,h,60);}
static bool sx_dm_ubi(sx_context*c){uint8_t h[172];if(!sx_dm_ubi_ec(c,0,h))return false;uint64_t peb=0;
 for(unsigned pass=0;pass<2&&!peb;pass++)for(uint64_t candidate=1024;candidate<=16777216&&candidate<=(uint64_t)c->size;candidate*=2){for(unsigned k=1;k<=64;k++){uint64_t p=candidate*k;if(!sx_dm_span(c,p,64))break;if(sx_dm_ubi_ec(c,p,h)){peb=candidate;break;}if(!pass)break;bool erased=true;for(unsigned j=0;j<64;j++)if(h[j]!=255){erased=false;break;}if(!erased)break;}if(peb)break;}
 if(!peb&&(uint64_t)c->size<=16777216)peb=(uint64_t)c->size;if(!peb)return sx_dm_add(c,&sx_dm_ubi_erase_counter_header,0,64);
 uint64_t count=(uint64_t)c->size/peb;if(count>8192)count=8192;for(uint64_t i=0;i<count&&c->count<24000;i++){uint64_t p=i*peb;if(!sx_dm_ubi_ec(c,p,h))continue;uint64_t vo=sx_dm_u32(h,16,true),data=sx_dm_u32(h,20,true);if(!sx_dm_add(c,&sx_dm_ubi_erase_counter_header,p,64))return false;if(vo<64||vo>peb-64||data<vo+64||data>=peb||!sx_dm_read(c,p+vo,h,64)||xx_rt_memcmp(h,"UBI!",4)||sx_dm_u32(h,60,true)!=~xx_crc32_calc(0,h,60))continue;if(!sx_dm_add(c,&sx_dm_ubi_volume_identifier_header,p+vo,64))return false;
  if(sx_dm_u32(h,8,true)==0x7fffefffU&&sx_dm_u32(h,12,true)<=1){uint64_t available=peb-data,pad=sx_dm_u32(h,28,true);if(pad>available)continue;available-=pad;for(uint64_t j=0;j<128&&(j+1)*172<=available;j++){uint64_t q=p+data+j*172;if(!sx_dm_read(c,q,h,172))return false;if(sx_dm_u32(h,168,true)==~xx_crc32_calc(0,h,168)&&!sx_dm_add(c,&sx_dm_ubi_volume_table_record,q,172))return false;}}
 }return true;}
bool sx_ubi_build(sx_context*c)
{
 return sx_dm_ubi(c);
}
