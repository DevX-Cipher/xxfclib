/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * processing_vlw data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_vlw_header_fields[] = {
    SX_FIELD("glyph_count", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("font_size", "uint32", 8, 4, SX_NONE),
    SX_FIELD("reserved", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("ascent", "uint32", 16, 4, SX_NONE),
    SX_FIELD("descent", "uint32", 20, 4, SX_NONE),
};
const sx_layout sxm_vlw_header = {UINT32_C(0x6006002E), "vlw_header", sxm_vlw_header_fields, SX_COUNT(sxm_vlw_header_fields), SX_BE};
static const xx_data_struct_field_desc sxm_vlw_glyph_fields[] = {
    SX_FIELD("value", "uint32", 0, 4, SX_ID),
    SX_FIELD("height", "uint32", 4, 4, SX_NONE),
    SX_FIELD("width", "uint32", 8, 4, SX_NONE),
    SX_FIELD("set_width", "int32", 12, 4, SX_NONE),
    SX_FIELD("top_extent", "int32", 16, 4, SX_NONE),
    SX_FIELD("left_extent", "int32", 20, 4, SX_NONE),
    SX_FIELD("reserved", "uint32", 24, 4, SX_RESERVED),
};
const sx_layout sxm_vlw_glyph = {UINT32_C(0x6006002F), "vlw_glyph", sxm_vlw_glyph_fields, SX_COUNT(sxm_vlw_glyph_fields), SX_BE};
bool sx_processing_vlw_build(sx_context*c,uint8_t*h,size_t n)
{
 uint32_t count;if(n<24||xx_data_get_u32(h,n,4,true)!=11)return false;count=xx_data_get_u32(h,n,0,true);return count&&count<=4092&&sx_add(c,&sxm_vlw_header,0,24)&&sx_table(c,&sxm_vlw_glyph,24,28,count)&&sxm_tail(c,24+(uint64_t)count*28);
}
