/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * font_psf data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_psf1_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("mode", "uint8", 2, 1, SX_FLAGS),
    SX_FIELD("glyph_size", "uint8", 3, 1, SX_SIZE),
};
const sx_layout sxm_psf1_header = {UINT32_C(0x60060022), "psf1_header", sxm_psf1_header_fields, SX_COUNT(sxm_psf1_header_fields), SX_LE};
static const xx_data_struct_field_desc sxm_psf2_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 12, 4, SX_FLAGS),
    SX_FIELD("glyph_count", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("glyph_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("width", "uint32", 28, 4, SX_NONE),
};
const sx_layout sxm_psf2_header = {UINT32_C(0x60060023), "psf2_header", sxm_psf2_header_fields, SX_COUNT(sxm_psf2_header_fields), SX_LE};
bool sx_font_psf_build(sx_context*c,uint8_t*h,size_t n)
{
 if(n>=4&&h[0]==0x36&&h[1]==4)return sxm_fixed(c,&sxm_psf1_header,4);return n>=32&&xx_data_get_u32(h,n,0,false)==UINT32_C(0x864ab572)&&sxm_fixed(c,&sxm_psf2_header,32);
}
