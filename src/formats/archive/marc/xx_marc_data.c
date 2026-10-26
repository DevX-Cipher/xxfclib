/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MARC archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_marc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("entry_count","int32",8,4,SX_COUNT_PROP),
};
const sx_layout sxag_marc_header = {UINT32_C(0x6025002b),"marc_header",sxag_marc_header_fields,SX_COUNT(sxag_marc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_marc_entry_fields[] = {
 SX_FIELD("name","char[56]",0,56,SX_STRING),
 SX_FIELD("data_size","int32",56,4,SX_SIZE),
 SX_FIELD("unknown60","uint32",60,4,SX_NONE),
 SX_FIELD("data_offset","int32",64,4,SX_OFFSET),
};
const sx_layout sxag_marc_entry = {UINT32_C(0x6025002c),"marc_entry",sxag_marc_entry_fields,SX_COUNT(sxag_marc_entry_fields),SX_LE};
bool sx_marc_build(sx_context*c)
{
 return sxag_fixed(c,&sxag_marc_header,&sxag_marc_entry,12,8,4,false,12,0);
}
