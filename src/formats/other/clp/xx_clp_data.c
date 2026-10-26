/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CLP data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_clp_header_fields[] = {
 SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("record_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxbx_clp_header = {UINT32_C(0x60300001),"clp_header",sxbx_clp_header_fields,SX_COUNT(sxbx_clp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_clp_record_fields[] = {
 SX_FIELD("format","uint16",0,2,SX_ID),
 SX_FIELD("data_size","int32",2,4,SX_SIZE),
 SX_FIELD("data_offset","int32",6,4,SX_OFFSET),
 SX_FIELD("format_name_or_reserved","uint8[79]",10,79,SX_NONE),
};
const sx_layout sxbx_clp_record = {UINT32_C(0x60300002),"clp_record",sxbx_clp_record_fields,SX_COUNT(sxbx_clp_record_fields),SX_LE};
bool sx_clp_build(sx_context*c)
{
 uint64_t n;return sxbx_word(c,2,2,false,&n)&&sxbx_add(c,&sxbx_clp_header,0)&&sxbx_table(c,&sxbx_clp_record,4,n);
}
