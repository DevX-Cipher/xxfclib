/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZDIET data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_lzdiet_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 6, SX_SIGNATURE),
    SX_FIELD("original_size", "uint32", 6, 4, SX_SIZE),
};
const sx_layout sxl_lzdiet_header = { UINT32_C(0x600A0016), "lzdiet_header", sxl_lzdiet_header_fields, SX_COUNT(sxl_lzdiet_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_lzdiet_chunk_fields[] = {
    SX_FIELD("data_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("packed_size", "uint16", 4, 2, SX_SIZE),
};
const sx_layout sxl_lzdiet_chunk = { UINT32_C(0x600A0017), "lzdiet_chunk", sxl_lzdiet_chunk_fields, SX_COUNT(sxl_lzdiet_chunk_fields), SX_LE };
static const xx_data_struct_field_desc sxl_lzdiet_table_end_fields[] = {
    SX_FIELD("end_marker", "uint32", 0, 4, SX_SIGNATURE),
};
const sx_layout sxl_lzdiet_table_end = { UINT32_C(0x600A0018), "lzdiet_table_end", sxl_lzdiet_table_end_fields, SX_COUNT(sxl_lzdiet_table_end_fields), SX_LE };
static bool sxl_diet(sx_context *c)
{
    uint32_t n;uint64_t previous=0x5fc;bool any=false;
    if(!sxl_sig(c,0,"lZdIeT",6)||!sxl_span(c,0,0x5fc)||!sx_u32(c,6,false,&n)||!n||n>0x40000000U||!sx_add(c,&sxl_lzdiet_header,0,10))return false;
    for(unsigned i=0;i<250;i++){uint32_t off;uint16_t size;int64_t at=32+(int64_t)i*6;if(!sx_u32(c,at,false,&off)||!sx_u16(c,at+4,false,&size))return false;
        if(off==UINT32_MAX)return any&&sx_add(c,&sxl_lzdiet_table_end,at,4);
        if(off<previous||size<6||!sxl_span(c,off,size)||!sx_add(c,&sxl_lzdiet_chunk,at,6))return false;
        previous=(uint64_t)off+size;any=true;
    }return any;
}
bool sx_lzdiet_build(sx_context*c)
{
    return sxl_diet(c);
}
