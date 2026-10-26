/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SAVEDSKF data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_savedskf_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("media_descriptor","uint16",2,2,SX_ID),
    SX_FIELD("sector_size","uint16",4,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster_minus_one","uint8",6,1,SX_NONE),
    SX_FIELD("cluster_shift","uint8",7,1,SX_NONE),
    SX_FIELD("reserved_sectors","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("first_data_sector","uint16",13,2,SX_NONE),
    SX_FIELD("highest_cluster","uint16",15,2,SX_NONE),
    SX_FIELD("sectors_per_fat","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("root_directory_sector","uint16",18,2,SX_NONE),
    SX_FIELD("checksum","uint32",20,4,SX_CHECKSUM),
    SX_FIELD("cylinder_count","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",28,2,SX_COUNT_PROP),
    SX_FIELD("unknown_1e","byte[4]",30,4,SX_NONE),
    SX_FIELD("stored_sector_count","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("comment_offset","uint16",36,2,SX_OFFSET),
    SX_FIELD("data_offset","uint16",38,2,SX_OFFSET),
};
const sx_layout sxsl_savedskf_header = {0x60330005U,"savedskf_header",sxsl_savedskf_header_fields,SX_COUNT(sxsl_savedskf_header_fields),SX_LE};
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
bool sx_savedskf_build(sx_context*c)
{
bool ok=false;
ok=SXSL_ADD(c,savedskf_header,0);
return ok&&sxsl_finish(c);
}
