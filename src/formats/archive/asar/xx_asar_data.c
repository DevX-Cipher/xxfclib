/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ASAR data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_asar_header_fields[] = {
 SX_FIELD("size_pickle_payload_size","uint32",0,4,SX_SIZE),
 SX_FIELD("header_pickle_size","uint32",4,4,SX_SIZE),
 SX_FIELD("header_pickle_payload_size","uint32",8,4,SX_SIZE),
 SX_FIELD("json_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxal_asar_header = {UINT32_C(0x6020000d),"asar_header",sxal_asar_header_fields,SX_COUNT(sxal_asar_header_fields),SX_LE};
bool sx_asar_build(sx_context*c)
{
 return sxal_add(c,&sxal_asar_header,0);
}
