/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ASH0 data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_ash0_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("size_word_top_byte", "uint8", 4, 1, SX_NONE),
    SX_FIELD("original_size", "uint24", 5, 3, SX_SIZE),
    SX_FIELD("distance_stream_offset", "uint32", 8, 4, SX_OFFSET),
};
const sx_layout sxl_ash0_header = { UINT32_C(0x600A0007), "ash0_header", sxl_ash0_header_fields, SX_COUNT(sxl_ash0_header_fields), SX_BE };
bool sx_ash0_build(sx_context*c)
{
    uint8_t h[12];uint32_t v;return sxl_sig(c,0,"ASH0",4)&&sx_read(c,4,h,4)&&(h[1]||h[2]||h[3])&&sx_u32(c,8,true,&v)&&v>=16&&sxl_span(c,v,4)&&sx_add(c,&sxl_ash0_header,0,12);
}
