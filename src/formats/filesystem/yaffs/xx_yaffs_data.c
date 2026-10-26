/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * YAFFS data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_yaffs_object_header_le_fields[] = {
    SX_FIELD("object_type","uint32",0,4,SX_ID),
    SX_FIELD("parent_object_id","uint32",4,4,SX_ID),
    SX_FIELD("obsolete_name_checksum","uint16",8,2,SX_RESERVED),
    SX_FIELD("name","byte[256]",10,256,SX_NONE),
    SX_FIELD("alignment_padding","byte[2]",266,2,SX_RESERVED),
    SX_FIELD("mode","uint32",268,4,SX_FLAGS),
    SX_FIELD("uid","uint32",272,4,SX_ID),
    SX_FIELD("gid","uint32",276,4,SX_ID),
    SX_FIELD("access_time","uint32",280,4,SX_TIME),
    SX_FIELD("modification_time","uint32",284,4,SX_TIME),
    SX_FIELD("change_time","uint32",288,4,SX_TIME),
    SX_FIELD("file_size_low","uint32",292,4,SX_NONE),
    SX_FIELD("equivalent_object_id","int32",296,4,SX_ID),
    SX_FIELD("alias","byte[160]",300,160,SX_NONE),
    SX_FIELD("device_id","uint32",460,4,SX_ID),
    SX_FIELD("wince_change_time_words","uint32[2]",464,8,SX_NONE),
    SX_FIELD("wince_access_time_words","uint32[2]",472,8,SX_NONE),
    SX_FIELD("wince_modification_time_words","uint32[2]",480,8,SX_NONE),
    SX_FIELD("inband_shadowed_object_id","uint32",488,4,SX_ID),
    SX_FIELD("inband_is_shrink","uint32",492,4,SX_FLAGS),
    SX_FIELD("file_size_high","uint32",496,4,SX_NONE),
    SX_FIELD("reserved","uint32",500,4,SX_RESERVED),
    SX_FIELD("shadows_object","int32",504,4,SX_ID),
    SX_FIELD("is_shrink","uint32",508,4,SX_FLAGS),
};
const sx_layout sx_dm_yaffs_object_header_le = {0x60290045U,"yaffs_object_header_le",sx_dm_yaffs_object_header_le_fields,SX_COUNT(sx_dm_yaffs_object_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_yaffs_object_header_be_fields[] = {
    SX_FIELD("object_type","uint32",0,4,SX_ID),
    SX_FIELD("parent_object_id","uint32",4,4,SX_ID),
    SX_FIELD("obsolete_name_checksum","uint16",8,2,SX_RESERVED),
    SX_FIELD("name","byte[256]",10,256,SX_NONE),
    SX_FIELD("alignment_padding","byte[2]",266,2,SX_RESERVED),
    SX_FIELD("mode","uint32",268,4,SX_FLAGS),
    SX_FIELD("uid","uint32",272,4,SX_ID),
    SX_FIELD("gid","uint32",276,4,SX_ID),
    SX_FIELD("access_time","uint32",280,4,SX_TIME),
    SX_FIELD("modification_time","uint32",284,4,SX_TIME),
    SX_FIELD("change_time","uint32",288,4,SX_TIME),
    SX_FIELD("file_size_low","uint32",292,4,SX_NONE),
    SX_FIELD("equivalent_object_id","int32",296,4,SX_ID),
    SX_FIELD("alias","byte[160]",300,160,SX_NONE),
    SX_FIELD("device_id","uint32",460,4,SX_ID),
    SX_FIELD("wince_change_time_words","uint32[2]",464,8,SX_NONE),
    SX_FIELD("wince_access_time_words","uint32[2]",472,8,SX_NONE),
    SX_FIELD("wince_modification_time_words","uint32[2]",480,8,SX_NONE),
    SX_FIELD("inband_shadowed_object_id","uint32",488,4,SX_ID),
    SX_FIELD("inband_is_shrink","uint32",492,4,SX_FLAGS),
    SX_FIELD("file_size_high","uint32",496,4,SX_NONE),
    SX_FIELD("reserved","uint32",500,4,SX_RESERVED),
    SX_FIELD("shadows_object","int32",504,4,SX_ID),
    SX_FIELD("is_shrink","uint32",508,4,SX_FLAGS),
};
const sx_layout sx_dm_yaffs_object_header_be = {0x6029004dU,"yaffs_object_header_be",sx_dm_yaffs_object_header_be_fields,SX_COUNT(sx_dm_yaffs_object_header_be_fields),SX_BE};
static bool sx_dm_yaffs(sx_context*c){uint8_t h[10];if(!sx_dm_read(c,0,h,10))return false;bool be=sx_dm_u32(h,0,false)>5;return sx_dm_add(c,be?&sx_dm_yaffs_object_header_be:&sx_dm_yaffs_object_header_le,0,512);}
bool sx_yaffs_build(sx_context*c)
{
 return sx_dm_yaffs(c);
}
