/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Vice X64 data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_x64_header_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint8",4,1,SX_NONE),
    SX_FIELD("version_minor","uint8",5,1,SX_NONE),
    SX_FIELD("device_type","uint8",6,1,SX_ID),
    SX_FIELD("track_count","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("second_side","uint8",8,1,SX_FLAGS),
    SX_FIELD("error_map_present","uint8",9,1,SX_FLAGS),
    SX_FIELD("reserved","byte[22]",10,22,SX_RESERVED),
    SX_FIELD("description","char[31]",32,31,SX_STRING),
    SX_FIELD("terminator","uint8",63,1,SX_RESERVED),
};
const sx_layout sxse_x64_header = {0x602f0001U,"x64_header",sxse_x64_header_fields,SX_COUNT(sxse_x64_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
bool sx_vice_x64_build(sx_context*c)
{
 return SXSE_ADD(c,x64_header,0,64);
}
#undef SXSE_ADD
