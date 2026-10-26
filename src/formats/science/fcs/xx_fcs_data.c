/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FCS data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsh_fcs_header_fields[] = {
    SX_FIELD("version","char[6]",0,6,SX_ID),
    SX_FIELD("reserved","char[4]",6,4,SX_RESERVED),
    SX_FIELD("text_start","ascii_decimal[8]",10,8,SX_OFFSET),
    SX_FIELD("text_end","ascii_decimal[8]",18,8,SX_OFFSET),
    SX_FIELD("data_start","ascii_decimal[8]",26,8,SX_OFFSET),
    SX_FIELD("data_end","ascii_decimal[8]",34,8,SX_OFFSET),
    SX_FIELD("analysis_start","ascii_decimal[8]",42,8,SX_OFFSET),
    SX_FIELD("analysis_end","ascii_decimal[8]",50,8,SX_OFFSET),
};
const sx_layout sxsh_fcs_header = {UINT32_C(0x602a0024),"fcs_header",sxsh_fcs_header_fields,SX_COUNT(sxsh_fcs_header_fields),SX_LE};
bool sx_fcs_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_add(c,&sxsh_fcs_header,0,58);
 return ok&&sxsh_finish(c);
}
