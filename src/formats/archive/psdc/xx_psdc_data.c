/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PSDC data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_psdc_header_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("reserved","uint8[63]",13,63,SX_NONE),
 SX_FIELD("total_size","uint32",76,4,SX_SIZE),
};
const sx_layout sxat_psdc_header = {UINT32_C(0x60640014),"psdc_header",sxat_psdc_header_fields,SX_COUNT(sxat_psdc_header_fields),SX_LE};
bool sx_psdc_build(sx_context*c)
{
 return sxat_add(c,&sxat_psdc_header,0)&&sxat_dcl(c,80,c->size>=80?(uint64_t)c->size-80:0);
}
