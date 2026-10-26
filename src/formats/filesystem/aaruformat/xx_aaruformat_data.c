/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Aaruformat data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_aaru2_header_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("application","char[64]",8,64,SX_STRING),
    SX_FIELD("image_major_version","uint8",72,1,SX_ID),
    SX_FIELD("image_minor_version","uint8",73,1,SX_ID),
    SX_FIELD("application_major_version","uint8",74,1,SX_ID),
    SX_FIELD("application_minor_version","uint8",75,1,SX_ID),
    SX_FIELD("media_type","uint32",76,4,SX_ID),
    SX_FIELD("index_offset","uint64",80,8,SX_OFFSET),
    SX_FIELD("creation_time","int64",88,8,SX_TIME),
    SX_FIELD("last_written_time","int64",96,8,SX_TIME),
    SX_FIELD("guid","byte[16]",104,16,SX_ID),
    SX_FIELD("block_alignment_shift","uint8",120,1,SX_NONE),
    SX_FIELD("biggest_sector_size","uint16",121,2,SX_SIZE),
    SX_FIELD("feature_compatible","uint64",123,8,SX_FLAGS),
    SX_FIELD("feature_compatible_readonly","uint64",131,8,SX_FLAGS),
    SX_FIELD("feature_incompatible","uint64",139,8,SX_FLAGS),
};
const sx_layout sxvi_aaru2_header = {0x60530030U,"aaru2_header",sxvi_aaru2_header_fields,SX_COUNT(sxvi_aaru2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_aaru2_ddt_header_fields[] = {
    SX_FIELD("identifier","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("data_type","uint16",4,2,SX_ID),
    SX_FIELD("compression","uint16",6,2,SX_ID),
    SX_FIELD("levels","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("table_level","uint8",9,1,SX_NONE),
    SX_FIELD("previous_level_offset","uint64",10,8,SX_OFFSET),
    SX_FIELD("negative_sectors","uint32",18,4,SX_COUNT_PROP),
    SX_FIELD("blocks","uint64",22,8,SX_COUNT_PROP),
    SX_FIELD("overflow_sectors","uint32",30,4,SX_COUNT_PROP),
    SX_FIELD("start","uint64",34,8,SX_NONE),
    SX_FIELD("block_alignment_shift","uint8",42,1,SX_NONE),
    SX_FIELD("data_shift","uint8",43,1,SX_NONE),
    SX_FIELD("table_shift","uint8",44,1,SX_NONE),
    SX_FIELD("entries","uint64",45,8,SX_COUNT_PROP),
    SX_FIELD("compressed_length","uint64",53,8,SX_SIZE),
    SX_FIELD("length","uint64",61,8,SX_SIZE),
    SX_FIELD("compressed_crc64","uint64",69,8,SX_CHECKSUM),
    SX_FIELD("crc64","uint64",77,8,SX_CHECKSUM),
};
const sx_layout sxvi_aaru2_ddt_header = {0x60530031U,"aaru2_ddt_header",sxvi_aaru2_ddt_header_fields,SX_COUNT(sxvi_aaru2_ddt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_aaru2_ddt_entry_fields[] = {
    SX_FIELD("encoded_location","uint64",0,8,SX_FLAGS),
};
const sx_layout sxvi_aaru2_ddt_entry = {0x60530032U,"aaru2_ddt_entry",sxvi_aaru2_ddt_entry_fields,SX_COUNT(sxvi_aaru2_ddt_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_aaru_index3_fields[] = {
    SX_FIELD("identifier","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("entries","uint64",4,8,SX_COUNT_PROP),
    SX_FIELD("crc64","uint64",12,8,SX_CHECKSUM),
    SX_FIELD("previous","uint64",20,8,SX_OFFSET),
};
const sx_layout sxvi_aaru_index3 = {0x60530033U,"aaru_index3",sxvi_aaru_index3_fields,SX_COUNT(sxvi_aaru_index3_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_aaru_index_entry_fields[] = {
    SX_FIELD("block_type","uint32",0,4,SX_ID),
    SX_FIELD("data_type","uint16",4,2,SX_ID),
    SX_FIELD("offset","uint64",6,8,SX_OFFSET),
};
const sx_layout sxvi_aaru_index_entry = {0x60530034U,"aaru_index_entry",sxvi_aaru_index_entry_fields,SX_COUNT(sxvi_aaru_index_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_aaru_data_header_fields[] = {
    SX_FIELD("identifier","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("data_type","uint16",4,2,SX_ID),
    SX_FIELD("compression","uint16",6,2,SX_ID),
    SX_FIELD("sector_size","uint32",8,4,SX_SIZE),
    SX_FIELD("compressed_length","uint32",12,4,SX_SIZE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("compressed_crc64","uint64",20,8,SX_CHECKSUM),
    SX_FIELD("crc64","uint64",28,8,SX_CHECKSUM),
};
const sx_layout sxvi_aaru_data_header = {0x60530035U,"aaru_data_header",sxvi_aaru_data_header_fields,SX_COUNT(sxvi_aaru_data_header_fields),SX_LE};
#define SXVI_LIMIT 24000U
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
#define SXVI_TABLE(c,l,p,n) sxvi_put(c,&sxvi_##l,p,n)
static bool sxvi_aaru(sx_context*c){uint8_t h[147],b[85];if(!sxvi_read(c,0,h,147)||xx_rt_memcmp(h,"AARUFRMT",8)||h[72]!=2||!SXVI_ADD(c,aaru2_header,0))return false;uint64_t p=sxvi64(h+80,0);if(!sxvi_read(c,p,b,28)||sxvi32(b,0)!=0x33584449U)return true;uint64_t n=sxvi64(b+4,0);if(n>1048576||!sxvi_span(c,p+28,n*14))return true;if(!SXVI_ADD(c,aaru_index3,p)||!SXVI_TABLE(c,aaru_index_entry,p+28,n))return false;
 for(uint64_t i=0;i<n&&c->count<SXVI_LIMIT;i++){uint8_t e[14];if(!sxvi_read(c,p+28+i*14,e,14))return false;uint64_t at=sxvi64(e+6,0);uint32_t type=sxvi32(e,0);if(type==0x4b4c4244U){if(sxvi_read(c,at,b,36)&&sxvi32(b,0)==type&&!SXVI_ADD(c,aaru_data_header,at))return false;}else if(type==0x32544444U&&sxvi_read(c,at,b,85)&&sxvi32(b,0)==type){if(!SXVI_ADD(c,aaru2_ddt_header,at))return false;uint64_t count=sxvi64(b+45,0),len=sxvi64(b+61,0);if(!sxvi16(b+6,0)&&count<=1048576&&count*8==len&&sxvi_span(c,at+85,len)&&!SXVI_TABLE(c,aaru2_ddt_entry,at+85,count))return false;}}
 return true;
}
bool sx_aaruformat_build(sx_context*c)
{
 return sxvi_aaru(c);
}
#undef SXVI_LIMIT
#undef SXVI_ADD
#undef SXVI_TABLE
