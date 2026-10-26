/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HUF data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_huf_header_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("member_count", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("symbol_count", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("directory_offset", "uint32", 6, 4, SX_OFFSET),
};
const sx_layout sxl_huf_header = { UINT32_C(0x600A0013), "huf_header", sxl_huf_header_fields, SX_COUNT(sxl_huf_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_huf_symbol_fields[] = {
    SX_FIELD("symbol", "uint8", 0, 1, SX_NONE),
};
const sx_layout sxl_huf_symbol = { UINT32_C(0x600A0014), "huf_symbol", sxl_huf_symbol_fields, SX_COUNT(sxl_huf_symbol_fields), SX_LE };
static const xx_data_struct_field_desc sxl_huf_directory_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("original_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("data_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("flags", "uint8", 12, 1, SX_FLAGS),
};
const sx_layout sxl_huf_directory = { UINT32_C(0x600A0015), "huf_directory", sxl_huf_directory_fields, SX_COUNT(sxl_huf_directory_fields), SX_LE };
static bool sxl_huf(sx_context *c)
{
    uint16_t count,symbols;uint32_t dir;
    if(!sxl_sig(c,0,"\xbd\x01",2)||!sx_u16(c,2,false,&count)||!count||!sx_u16(c,4,false,&symbols)||!symbols||symbols>256||!sx_u32(c,6,false,&dir)||dir<=10U+symbols||!sx_add(c,&sxl_huf_header,0,10)||!sx_table(c,&sxl_huf_symbol,10,1,symbols)||!sx_table(c,&sxl_huf_directory,dir,13,count))return false;
    for(uint16_t i=0;i<count;i++){uint32_t name,data;int64_t at=dir+(int64_t)i*13;if(!sx_u32(c,at,false,&name)||!sx_u32(c,at+8,false,&data)||name<dir+(uint64_t)count*13||data<dir+(uint64_t)count*13||!sxl_span(c,name,1)||!sxl_span(c,data,1))return false;}
    return true;
}
bool sx_huf_build(sx_context*c)
{
    return sxl_huf(c);
}
