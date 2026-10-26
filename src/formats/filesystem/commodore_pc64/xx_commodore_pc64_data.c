/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Commodore Pc64 data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_pc64_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("petscii_name","byte[16]",8,16,SX_NONE),
    SX_FIELD("terminator","uint8",24,1,SX_RESERVED),
    SX_FIELD("record_size","uint8",25,1,SX_SIZE),
};
const sx_layout sxse_pc64_header = {0x602f003fU,"pc64_header",sxse_pc64_header_fields,SX_COUNT(sxse_pc64_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
bool sx_commodore_pc64_build(sx_context*c)
{
 return SXSE_ADD(c,pc64_header,0,26);
}
#undef SXSE_ADD
