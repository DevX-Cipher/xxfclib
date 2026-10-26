/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Ascend compressed files data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_ascend_header_fields[] = {
 SX_FIELD("year","uint16",0,2,SX_NONE),
 SX_FIELD("month","uint16",2,2,SX_NONE),
 SX_FIELD("day","uint16",4,2,SX_NONE),
 SX_FIELD("hour","uint16",6,2,SX_NONE),
 SX_FIELD("minute","uint16",8,2,SX_NONE),
 SX_FIELD("second","uint16",10,2,SX_NONE),
};
const sx_layout sxag_ascend_header = {UINT32_C(0x60250021),"ascend_header",sxag_ascend_header_fields,SX_COUNT(sxag_ascend_header_fields),SX_LE};
bool sx_ascend_build(sx_context*c)
{
 return sxag_add(c,&sxag_ascend_header,0)&&sxag_add(c,&sxag_archivelegacy_dcl,12);
}
