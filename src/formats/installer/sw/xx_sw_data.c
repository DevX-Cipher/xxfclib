/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SW data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_sw_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("image_revision","ascii_decimal[3]",6,3,SX_NONE),
 SX_FIELD("product_marker","char[1]",9,1,SX_SIGNATURE),
 SX_FIELD("product_revision","ascii_decimal[2]",10,2,SX_NONE),
 SX_FIELD("terminator","uint8",12,1,SX_NONE),
};
const sx_layout sxao_sw_header = {UINT32_C(0x60700001),"sw_header",sxao_sw_header_fields,SX_COUNT(sxao_sw_header_fields),SX_LE};
bool sx_sw_build(sx_context*c)
{
 return sxao_add(c,&sxao_sw_header,0)&&sxao_native_members(c);
}
