/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TNEF data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_tnef_header_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("key", "uint16", 4, 2, SX_ID),
};
const sx_layout sx_p_tnef_header = { UINT32_C(0x60070035), "tnef_header", sx_p_tnef_header_fields, SX_COUNT(sx_p_tnef_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_tnef_checksum_fields[] = {
    SX_FIELD("checksum", "uint16", 0, 2, SX_CHECKSUM),
};
const sx_layout sx_p_tnef_checksum = { UINT32_C(0x60070037), "tnef_checksum", sx_p_tnef_checksum_fields, SX_COUNT(sx_p_tnef_checksum_fields), SX_LE };
static bool sx_p_tnef(sx_context *c)
{
    if(!sx_p_sig(c,0,"\x78\x9f\x3e\x22",4)||!sx_add(c,&sx_p_tnef_header,0,6))return false;int64_t off=6;
    while(off<c->size){uint8_t level;uint32_t n;if(!sx_p_byte(c,off,&level)||(level!=1&&level!=2)||!sx_u32(c,off+5,false,&n)||!sx_add(c,&sx_p_tnef_attribute,off,9))return false;off+=9;if(!sx_p_span(c,off,(uint64_t)n+2)||!sx_add(c,&sx_p_tnef_checksum,off+n,2))return false;off+=n+2;}return true;
}
bool sx_tnef_build(sx_context*c)
{
    return sx_p_tnef(c);
}
