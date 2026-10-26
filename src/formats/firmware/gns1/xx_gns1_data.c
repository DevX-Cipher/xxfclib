/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apple C4000 GNS1 baseband firmware data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fm_gns1_ftab_header_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sx_fm_gns1_ftab_header = {0x6022001fU,"gns1_ftab_header",sx_fm_gns1_ftab_header_fields,SX_COUNT(sx_fm_gns1_ftab_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_gns1_ftab_entry_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("size","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sx_fm_gns1_ftab_entry = {0x60220020U,"gns1_ftab_entry",sx_fm_gns1_ftab_entry_fields,SX_COUNT(sx_fm_gns1_ftab_entry_fields),SX_LE};
/* Native reader tests a complete raw segment table before considering FTAB. */
static bool sx_fm_gns_segments(sx_context*c,uint64_t base,uint64_t size)
{
 if(base>INT64_MAX||size>INT64_MAX||size<64||!sx_fm_span(c,(int64_t)base,size))return false;
 uint8_t h[256];if(!sx_fm_read(c,(int64_t)base,h,12))return false;uint32_t first=xx_data_get_u32(h,12,8,false),address=xx_data_get_u32(h,12,4,false);
 if(first<100||first>size||(address&0x00ffffff)||address<0x12000000||address>=0x16000000)return false;
 uint64_t off=0;unsigned n=0,records=0;bool terminal=false;
 while(off+12<=first&&n<=1000){if(!sx_fm_read(c,(int64_t)(base+off),h,12))return false;uint32_t length=xx_data_get_u32(h,12,0,false),addr=xx_data_get_u32(h,12,4,false),at=xx_data_get_u32(h,12,8,false);off+=12;records++;
  if((length==UINT32_MAX&&addr==UINT32_MAX&&at==UINT32_MAX)||(!length&&!addr&&!at)){terminal=true;break;}
  if(!length||addr<0x12000000||addr>=0x16000000||at<first||at>size||length>size-at||++n>1000)return false;
 }
 if(!terminal&&first>off&&first-off<12)terminal=true;if(!terminal||!n)return false;
 while(off<first){size_t z=first-off>sizeof(h)?sizeof(h):(size_t)(first-off);if(!sx_fm_read(c,(int64_t)(base+off),h,z))return false;for(size_t i=0;i<z;i++)if(h[i])return false;off+=z;}
 return sx_fm_table(c,&sx_fm_gns1_segment,(int64_t)base,12,n)&&(records==n||sx_fm_add(c,&sx_fm_gns1_terminator,(int64_t)(base+(uint64_t)n*12),12));
}
static bool sx_fm_gns(sx_context*c)
{
 if(sx_fm_gns_segments(c,0,(uint64_t)c->size))return true;if(c->failed)return false;
 uint8_t magic[8];if(!sx_fm_read(c,32,magic,8)||xx_rt_memcmp(magic,"rkosftab",8))return false;
 uint32_t n,reserved;if(!sx_fm_u32(c,40,false,&n)||!sx_fm_u32(c,44,false,&reserved)||reserved||!n||n>4096||!sx_fm_span(c,48,(uint64_t)n*16))return false;
 if(!sx_fm_add(c,&sx_fm_gns1_ftab_header,32,16)||!sx_fm_table(c,&sx_fm_gns1_ftab_entry,48,16,n))return false;
 uint32_t base=0,size=0;bool found=false;for(uint32_t i=0;i<n;i++){uint8_t e[16];if(!sx_fm_read(c,48+(int64_t)i*16,e,16))return false;if(!xx_rt_memcmp(e,"GNS1",4)){base=xx_data_get_u32(e,16,4,false);size=xx_data_get_u32(e,16,8,false);found=true;}}
 if(found&&!sx_fm_gns_segments(c,base,size))return !c->failed;return !c->failed;
}
bool sx_gns1_build(sx_context*c)
{
    return sx_fm_gns(c);
}
