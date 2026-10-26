/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VHDDynamic data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_vhd_dynamic_header_fields[] = {
    SX_FIELD("cookie","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("data_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("table_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("header_version","uint32",24,4,SX_NONE),
    SX_FIELD("max_table_entries","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",32,4,SX_SIZE),
    SX_FIELD("checksum","uint32",36,4,SX_CHECKSUM),
    SX_FIELD("parent_unique_id","byte[16]",40,16,SX_ID),
    SX_FIELD("parent_timestamp","uint32",56,4,SX_TIME),
    SX_FIELD("reserved","uint32",60,4,SX_RESERVED),
    SX_FIELD("parent_unicode_name","uint16[256]",64,512,SX_NONE),
};
const sx_layout sx_dm_vhd_dynamic_header = {0x60290011U,"vhd_dynamic_header",sx_dm_vhd_dynamic_header_fields,SX_COUNT(sx_dm_vhd_dynamic_header_fields),SX_BE};
static bool sx_dm_vhd(sx_context*c){uint8_t h[576];uint64_t n=(uint64_t)c->size,fs=n%512==511?511:512;if(n<fs||!sx_dm_read(c,n-fs,h,85)||xx_rt_memcmp(h,"conectix",8))return false;const sx_layout*l=fs==511?&sx_dm_vhd_footer_511:&sx_dm_vhd_footer_512;if(!sx_dm_add(c,l,n-fs,fs))return false;unsigned type=sx_dm_u32(h,60,true);uint64_t p=sx_dm_u64(h,16,true);if(type==3||type==4){if(!sx_dm_add(c,&sx_dm_vhd_footer_512,0,512))return false;if(sx_dm_read(c,p,h,576)&&!xx_rt_memcmp(h,"cxsparse",8)&&sx_dm_span(c,p,1024)){if(!sx_dm_add(c,&sx_dm_vhd_dynamic_header,p,576)||!sx_dm_table(c,&sx_dm_vhd_parent_locator,p+576,24,8))return false;uint64_t bat=sx_dm_u64(h,16,true),count=sx_dm_u32(h,28,true);if(sx_dm_span(c,bat,count*4)&&!sx_dm_table(c,&sx_dm_vhd_bat_entry,bat,4,count))return false;}}return true;}
bool sx_vhddynamic_build(sx_context*c)
{
 return sx_dm_vhd(c);
}
