/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ATARIST data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_atarist_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("text_size", "uint32", 2, 4, SX_SIZE),
    SX_FIELD("data_size", "uint32", 6, 4, SX_SIZE),
    SX_FIELD("bss_size", "uint32", 10, 4, SX_SIZE),
    SX_FIELD("symbol_size", "uint32", 14, 4, SX_SIZE),
    SX_FIELD("reserved", "uint32", 18, 4, SX_RESERVED),
    SX_FIELD("flags", "uint32", 22, 4, SX_FLAGS),
    SX_FIELD("absolute_flag", "uint16", 26, 2, SX_FLAGS),
};
const sx_layout sxl_atarist_header = { UINT32_C(0x600A002D), "atarist_header", sxl_atarist_header_fields, SX_COUNT(sxl_atarist_header_fields), SX_BE };
static const xx_data_struct_field_desc sxl_atarist_symbol_fields[] = {
    SX_FIELD("name", "char[8]", 0, 8, SX_STRING),
    SX_FIELD("type", "uint16", 8, 2, SX_FLAGS),
    SX_FIELD("value", "uint32", 10, 4, SX_NONE),
};
const sx_layout sxl_atarist_symbol = { UINT32_C(0x600A002E), "atarist_symbol", sxl_atarist_symbol_fields, SX_COUNT(sxl_atarist_symbol_fields), SX_BE };
static bool sxl_atari(sx_context *c)
{
    uint32_t text,data,symbols;uint64_t off;
    if(!sxl_sig(c,0,"\x60\x1a",2)||!sx_u32(c,2,true,&text)||!sx_u32(c,6,true,&data)||!sx_u32(c,14,true,&symbols)||!sx_add(c,&sxl_atarist_header,0,28))return false;
    off=28+(uint64_t)text+data;if(!sxl_span(c,28,(uint64_t)text+data)||!sxl_span(c,off,symbols))return false;
    /* Basic DRI flags occupy the upper type byte. Other symbol encodings
     * and extended-name records remain raw rather than being misframed. */
    if(symbols%14)return true;
    for(uint32_t i=0;i<symbols/14;i++){uint16_t type;if(!sx_u16(c,(int64_t)off+(int64_t)i*14+8,true,&type))return false;if(type&0xff)return true;}
    return sx_table(c,&sxl_atarist_symbol,(int64_t)off,14,symbols/14);
}
bool sx_atarist_build(sx_context*c)
{
    return sxl_atari(c);
}
