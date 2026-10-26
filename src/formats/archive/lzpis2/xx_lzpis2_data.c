/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZPIS2 data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_lzpis2_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 6, SX_SIGNATURE),
};
const sx_layout sxl_lzpis2_header = { UINT32_C(0x600A0019), "lzpis2_header", sxl_lzpis2_header_fields, SX_COUNT(sxl_lzpis2_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_lzpis2_chunk_fields[] = {
    SX_FIELD("original_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("packed_size", "uint16", 2, 2, SX_SIZE),
};
const sx_layout sxl_lzpis2_chunk = { UINT32_C(0x600A001A), "lzpis2_chunk", sxl_lzpis2_chunk_fields, SX_COUNT(sxl_lzpis2_chunk_fields), SX_LE };
static bool sxl_pis(sx_context *c)
{
    int64_t at=6;uint64_t total=0;
    if(!sxl_sig(c,0,"LZPIS2",6)||!sx_add(c,&sxl_lzpis2_header,0,6)||at==c->size)return false;
    while(at<c->size){uint16_t n,z;if(!sx_u16(c,at,false,&n)||!sx_u16(c,at+2,false,&z)||!n||n>4096||!z||!sxl_span(c,at+4,z)||!sx_add(c,&sxl_lzpis2_chunk,at,4))return false;total+=n;if(total>UINT64_C(0x40000000))return false;at+=4+z;}return true;
}
bool sx_lzpis2_build(sx_context*c)
{
    return sxl_pis(c);
}
