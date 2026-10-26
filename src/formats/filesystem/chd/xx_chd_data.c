/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MAME CHD data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_chd_header_v1_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("compression","uint32",20,4,SX_ID),
    SX_FIELD("sectors_per_hunk","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("hunk_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("sectors","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("md5","byte[16]",44,16,SX_CHECKSUM),
    SX_FIELD("parent_md5","byte[16]",60,16,SX_CHECKSUM),
};
const sx_layout sx_dm_chd_header_v1 = {0x60290022U,"chd_header_v1",sx_dm_chd_header_v1_fields,SX_COUNT(sx_dm_chd_header_v1_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_chd_header_v2_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("compression","uint32",20,4,SX_ID),
    SX_FIELD("sectors_per_hunk","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("hunk_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("sectors","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("md5","byte[16]",44,16,SX_CHECKSUM),
    SX_FIELD("parent_md5","byte[16]",60,16,SX_CHECKSUM),
    SX_FIELD("sector_bytes","uint32",76,4,SX_SIZE),
};
const sx_layout sx_dm_chd_header_v2 = {0x60290023U,"chd_header_v2",sx_dm_chd_header_v2_fields,SX_COUNT(sx_dm_chd_header_v2_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_chd_header_v3_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("compression","uint32",20,4,SX_ID),
    SX_FIELD("hunk_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("logical_bytes","uint64",28,8,SX_SIZE),
    SX_FIELD("metadata_offset","uint64",36,8,SX_OFFSET),
    SX_FIELD("md5","byte[16]",44,16,SX_CHECKSUM),
    SX_FIELD("parent_md5","byte[16]",60,16,SX_CHECKSUM),
    SX_FIELD("hunk_bytes","uint32",76,4,SX_SIZE),
    SX_FIELD("sha1","byte[20]",80,20,SX_CHECKSUM),
    SX_FIELD("parent_sha1","byte[20]",100,20,SX_CHECKSUM),
};
const sx_layout sx_dm_chd_header_v3 = {0x60290024U,"chd_header_v3",sx_dm_chd_header_v3_fields,SX_COUNT(sx_dm_chd_header_v3_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_chd_header_v4_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("compression","uint32",20,4,SX_ID),
    SX_FIELD("hunk_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("logical_bytes","uint64",28,8,SX_SIZE),
    SX_FIELD("metadata_offset","uint64",36,8,SX_OFFSET),
    SX_FIELD("hunk_bytes","uint32",44,4,SX_SIZE),
    SX_FIELD("sha1","byte[20]",48,20,SX_CHECKSUM),
    SX_FIELD("parent_sha1","byte[20]",68,20,SX_CHECKSUM),
    SX_FIELD("raw_sha1","byte[20]",88,20,SX_CHECKSUM),
};
const sx_layout sx_dm_chd_header_v4 = {0x60290025U,"chd_header_v4",sx_dm_chd_header_v4_fields,SX_COUNT(sx_dm_chd_header_v4_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_chd_header_v5_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("compressors","uint32[4]",16,16,SX_ID),
    SX_FIELD("logical_bytes","uint64",32,8,SX_SIZE),
    SX_FIELD("map_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("metadata_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("hunk_bytes","uint32",56,4,SX_SIZE),
    SX_FIELD("unit_bytes","uint32",60,4,SX_SIZE),
    SX_FIELD("raw_sha1","byte[20]",64,20,SX_CHECKSUM),
    SX_FIELD("sha1","byte[20]",84,20,SX_CHECKSUM),
    SX_FIELD("parent_sha1","byte[20]",104,20,SX_CHECKSUM),
};
const sx_layout sx_dm_chd_header_v5 = {0x60290026U,"chd_header_v5",sx_dm_chd_header_v5_fields,SX_COUNT(sx_dm_chd_header_v5_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_chd_map_v5_compressed_header_fields[] = {
    SX_FIELD("compressed_length","uint32",0,4,SX_SIZE),
    SX_FIELD("first_data_offset","uint48",4,6,SX_OFFSET),
    SX_FIELD("crc16","uint16",10,2,SX_CHECKSUM),
    SX_FIELD("length_bits","uint8",12,1,SX_NONE),
    SX_FIELD("hunk_bits","uint8",13,1,SX_NONE),
    SX_FIELD("parent_unit_bits","uint8",14,1,SX_NONE),
    SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
};
const sx_layout sx_dm_chd_map_v5_compressed_header = {0x6029002aU,"chd_map_v5_compressed_header",sx_dm_chd_map_v5_compressed_header_fields,SX_COUNT(sx_dm_chd_map_v5_compressed_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_chd_metadata_header_fields[] = {
    SX_FIELD("tag","byte[4]",0,4,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("length","uint24",5,3,SX_SIZE),
    SX_FIELD("next_offset","uint64",8,8,SX_OFFSET),
};
const sx_layout sx_dm_chd_metadata_header = {0x6029002bU,"chd_metadata_header",sx_dm_chd_metadata_header_fields,SX_COUNT(sx_dm_chd_metadata_header_fields),SX_BE};
static bool sx_dm_chd(sx_context*c){uint8_t h[124];if(!sx_dm_read(c,0,h,16)||xx_rt_memcmp(h,"MComprHD",8))return false;uint32_t v=sx_dm_u32(h,12,true),z=sx_dm_u32(h,8,true);const sx_layout*l=v==1?&sx_dm_chd_header_v1:v==2?&sx_dm_chd_header_v2:v==3?&sx_dm_chd_header_v3:v==4?&sx_dm_chd_header_v4:v==5?&sx_dm_chd_header_v5:NULL;static const uint32_t sizes[]={0,76,80,120,108,124};if(!l||z!=sizes[v]||!sx_dm_read(c,0,h,z)||!sx_dm_add(c,l,0,z))return false;uint64_t map=z,meta=0,count=0;const sx_layout*ml=NULL;unsigned stride=0;
 if(v<=2){count=sx_dm_u32(h,28,true);ml=&sx_dm_chd_map_v12;stride=8;}else if(v<=4){count=sx_dm_u32(h,24,true);meta=sx_dm_u64(h,36,true);ml=&sx_dm_chd_map_v34;stride=16;}else{uint32_t hb=sx_dm_u32(h,56,true);uint64_t logical=sx_dm_u64(h,32,true);map=sx_dm_u64(h,40,true);meta=sx_dm_u64(h,48,true);count=hb?logical/hb+(logical%hb!=0):0;if(sx_dm_u32(h,16,true)){if(sx_dm_span(c,map,16)&&!sx_dm_add(c,&sx_dm_chd_map_v5_compressed_header,map,16))return false;}else{ml=&sx_dm_chd_map_v5_uncompressed;stride=4;}}
 if(ml&&count<=UINT64_MAX/stride&&sx_dm_span(c,map,count*stride)&&!sx_dm_table(c,ml,map,stride,count))return false;
 for(unsigned i=0;meta&&i<4096;i++){if(!sx_dm_read(c,meta,h,16))break;uint32_t len=sx_dm_u32(h,4,true)&0xffffff;uint64_t next=sx_dm_u64(h,8,true);if(!sx_dm_span(c,meta,16+(uint64_t)len))break;size_t before=c->count;if(!sx_dm_add(c,&sx_dm_chd_metadata_header,meta,16))return false;if(c->count==before||next==meta)break;meta=next;}return true;}
bool sx_chd_build(sx_context*c)
{
 return sx_dm_chd(c);
}
