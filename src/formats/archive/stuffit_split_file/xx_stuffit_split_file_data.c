/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * StuffIt split file data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_stuffit_split_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("part_number","uint16",2,2,SX_NONE),
 SX_FIELD("name_size","uint8",4,1,SX_SIZE),
 SX_FIELD("file_name","char[63]",5,63,SX_NONE),
 SX_FIELD("file_type","char[4]",68,4,SX_NONE),
 SX_FIELD("creator","char[4]",72,4,SX_NONE),
 SX_FIELD("finder_flags","uint16",76,2,SX_NONE),
 SX_FIELD("creation_time","uint32",78,4,SX_NONE),
 SX_FIELD("modification_time","uint32",82,4,SX_NONE),
 SX_FIELD("resource_fork_size","uint32",86,4,SX_SIZE),
 SX_FIELD("data_fork_size","uint32",90,4,SX_SIZE),
 SX_FIELD("segment_bookkeeping","uint8[6]",94,6,SX_NONE),
};
const sx_layout sxaf_stuffit_split_header = {UINT32_C(0x603c0009),"stuffit_split_header",sxaf_stuffit_split_header_fields,SX_COUNT(sxaf_stuffit_split_header_fields),SX_BE};
bool sx_stuffit_split_file_build(sx_context*c)
{
 return sxaf_add(c,&sxaf_stuffit_split_header,0);
}
