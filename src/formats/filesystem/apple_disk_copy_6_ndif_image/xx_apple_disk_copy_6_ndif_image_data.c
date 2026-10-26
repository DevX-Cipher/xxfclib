/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apple Disk Copy 6 NDIF image data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_ndif_bcem_header_fields[] = {
    SX_FIELD("major_version","uint16",0,2,SX_NONE),
    SX_FIELD("minor_version","uint16",2,2,SX_NONE),
    SX_FIELD("name_length","uint8",4,1,SX_SIZE),
    SX_FIELD("name","char[63]",5,63,SX_NONE),
    SX_FIELD("sector_count","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("chunk_size_sectors","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("bs_zero_offset","uint32",76,4,SX_OFFSET),
    SX_FIELD("checksum","uint32",80,4,SX_CHECKSUM),
    SX_FIELD("segmented","uint32",84,4,SX_FLAGS),
    SX_FIELD("unknown","byte[8]",88,8,SX_NONE),
    SX_FIELD("reserved","byte[28]",96,28,SX_RESERVED),
    SX_FIELD("chunk_count","uint32",124,4,SX_COUNT_PROP),
};
const sx_layout sx_dm_ndif_bcem_header = {0x60290058U,"ndif_bcem_header",sx_dm_ndif_bcem_header_fields,SX_COUNT(sx_dm_ndif_bcem_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ndif_resource_fork_header_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("map_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_length","uint32",8,4,SX_SIZE),
    SX_FIELD("map_length","uint32",12,4,SX_SIZE),
};
const sx_layout sx_dm_ndif_resource_fork_header = {0x6029005aU,"ndif_resource_fork_header",sx_dm_ndif_resource_fork_header_fields,SX_COUNT(sx_dm_ndif_resource_fork_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ndif_resource_map_header_fields[] = {
    SX_FIELD("header_copy","byte[16]",0,16,SX_NONE),
    SX_FIELD("next_resource_map","uint32",16,4,SX_POINTER),
    SX_FIELD("file_reference_number","uint16",20,2,SX_ID),
    SX_FIELD("attributes","uint16",22,2,SX_FLAGS),
    SX_FIELD("type_list_offset","uint16",24,2,SX_OFFSET),
    SX_FIELD("name_list_offset","uint16",26,2,SX_OFFSET),
};
const sx_layout sx_dm_ndif_resource_map_header = {0x6029005bU,"ndif_resource_map_header",sx_dm_ndif_resource_map_header_fields,SX_COUNT(sx_dm_ndif_resource_map_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ndif_resource_type_fields[] = {
    SX_FIELD("type","byte[4]",0,4,SX_ID),
    SX_FIELD("count_minus_one","uint16",4,2,SX_NONE),
    SX_FIELD("reference_list_offset","uint16",6,2,SX_OFFSET),
};
const sx_layout sx_dm_ndif_resource_type = {0x6029005cU,"ndif_resource_type",sx_dm_ndif_resource_type_fields,SX_COUNT(sx_dm_ndif_resource_type_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ndif_resource_reference_fields[] = {
    SX_FIELD("resource_id","int16",0,2,SX_ID),
    SX_FIELD("name_offset","uint16",2,2,SX_OFFSET),
    SX_FIELD("attributes","uint8",4,1,SX_FLAGS),
    SX_FIELD("data_offset","uint24",5,3,SX_OFFSET),
    SX_FIELD("handle","uint32",8,4,SX_POINTER),
};
const sx_layout sx_dm_ndif_resource_reference = {0x6029005dU,"ndif_resource_reference",sx_dm_ndif_resource_reference_fields,SX_COUNT(sx_dm_ndif_resource_reference_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ndif_resource_length_fields[] = {
    SX_FIELD("length","uint32",0,4,SX_SIZE),
};
const sx_layout sx_dm_ndif_resource_length = {0x6029005eU,"ndif_resource_length",sx_dm_ndif_resource_length_fields,SX_COUNT(sx_dm_ndif_resource_length_fields),SX_BE};
static bool sx_dm_ndif(sx_context*c){uint8_t h[128];if(!sx_dm_read(c,0,h,128))return false;uint64_t secondary=0;if(xx_crc16_xmodem_calc(0,h,124)==sx_dm_u16(h,124,true)&&(h[122]>=129||sx_dm_u16(h,124,true)))secondary=sx_dm_u16(h,120,true);uint64_t data=128+((secondary+127)&~UINT64_C(127)),df=sx_dm_u32(h,83,true),rs=data+((df+127)&~UINT64_C(127)),rsize=sx_dm_u32(h,87,true);if(!sx_dm_span(c,rs,rsize)||rsize<16||!sx_dm_read(c,rs,h,16)||!sx_dm_add(c,&sx_dm_ndif_resource_fork_header,rs,16))return false;uint64_t rd=sx_dm_u32(h,0,true),map=sx_dm_u32(h,4,true),dl=sx_dm_u32(h,8,true),ml=sx_dm_u32(h,12,true);if(rd<16||rd>rsize||dl>rsize-rd||map<16||map>rsize||ml>rsize-map||ml<30||!sx_dm_read(c,rs+map,h,28))return true;uint64_t to=sx_dm_u16(h,24,true);if(to<28||to>ml-2)return true;if(!sx_dm_add(c,&sx_dm_ndif_resource_map_header,rs+map,28))return false;uint16_t raw;if(!sx_u16(c,(int64_t)(rs+map+to),true,&raw))return false;uint64_t count=((uint32_t)raw+1)&0xffff;if(count>(ml-to-2)/8)return true;if(!sx_dm_add(c,&sx_dm_ndif_resource_type_count,rs+map+to,2))return false;if(!sx_dm_table(c,&sx_dm_ndif_resource_type,rs+map+to+2,8,count))return false;
 for(uint64_t i=0;i<count&&i<4096;i++){if(!sx_dm_read(c,rs+map+to+2+i*8,h,8))return false;bool bcem=!xx_rt_memcmp(h,"bcem",4);uint64_t nr=(uint64_t)sx_dm_u16(h,4,true)+1,rr=to+sx_dm_u16(h,6,true);if(rr>ml||nr>(ml-rr)/12)continue;if(!sx_dm_table(c,&sx_dm_ndif_resource_reference,rs+map+rr,12,nr))return false;for(uint64_t j=0;j<nr&&j<4096&&c->count<24000;j++){if(!sx_dm_read(c,rs+map+rr+j*12,h,12))return false;uint64_t ro=xx_data_get_u24(h+5,3,0,true);bool match=bcem&&sx_dm_u16(h,0,true)==128;if(ro>dl||dl-ro<4)continue;uint32_t len;uint64_t q=rs+rd+ro;if(!sx_u32(c,(int64_t)q,true,&len))return false;if(len>dl-ro-4)continue;if(!sx_dm_add(c,&sx_dm_ndif_resource_length,q,4))return false;if(match&&len>=128&&sx_dm_read(c,q+4,h,128)){uint64_t n=sx_dm_u32(h,124,true);if(n<=(len-128)/12){if(!sx_dm_add(c,&sx_dm_ndif_bcem_header,q+4,128)||!sx_dm_table(c,&sx_dm_ndif_chunk_entry,q+132,12,n))return false;}}}}
 return true;}
bool sx_apple_disk_copy_6_ndif_image_build(sx_context*c)
{
 return sx_dm_ndif(c);
}
