/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TWS archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_tws_header_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_STRING),
 SX_FIELD("constant13","uint16",13,2,SX_NONE),
 SX_FIELD("zero15","uint16",15,2,SX_RESERVED),
 SX_FIELD("entry_count_minus1","int32",17,4,SX_NONE),
 SX_FIELD("payload_size","int32",21,4,SX_SIZE),
};
const sx_layout sxag_tws_header = {UINT32_C(0x60250035),"tws_header",sxag_tws_header_fields,SX_COUNT(sxag_tws_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_tws_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_STRING),
 SX_FIELD("time","uint16",13,2,SX_NONE),
 SX_FIELD("date","uint16",15,2,SX_NONE),
 SX_FIELD("data_offset","int32",17,4,SX_OFFSET),
 SX_FIELD("data_size","int32",21,4,SX_SIZE),
};
const sx_layout sxag_tws_entry = {UINT32_C(0x60250036),"tws_entry",sxag_tws_entry_fields,SX_COUNT(sxag_tws_entry_fields),SX_LE};
bool sx_tws_build(sx_context*c)
{
 return sxag_fixed(c,&sxag_tws_header,&sxag_tws_entry,25,17,4,false,25,1);
}
