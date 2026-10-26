/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pcx data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_pcx_header_fields[] = {
    SX_FIELD("manufacturer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 1, 1, SX_NONE),
    SX_FIELD("encoding", "uint8", 2, 1, SX_ID),
    SX_FIELD("bits_per_pixel", "uint8", 3, 1, SX_NONE),
    SX_FIELD("xmin", "uint16", 4, 2, SX_NONE),
    SX_FIELD("ymin", "uint16", 6, 2, SX_NONE),
    SX_FIELD("xmax", "uint16", 8, 2, SX_NONE),
    SX_FIELD("ymax", "uint16", 10, 2, SX_NONE),
    SX_FIELD("horizontal_dpi", "uint16", 12, 2, SX_NONE),
    SX_FIELD("vertical_dpi", "uint16", 14, 2, SX_NONE),
    SX_FIELD("palette16", "uint8[48]", 16, 48, SX_NONE),
    SX_FIELD("reserved", "uint8", 64, 1, SX_RESERVED),
    SX_FIELD("color_planes", "uint8", 65, 1, SX_COUNT_PROP),
    SX_FIELD("bytes_per_line", "uint16", 66, 2, SX_SIZE),
    SX_FIELD("palette_info", "uint16", 68, 2, SX_ID),
    SX_FIELD("horizontal_screen_size", "uint16", 70, 2, SX_NONE),
    SX_FIELD("vertical_screen_size", "uint16", 72, 2, SX_NONE),
    SX_FIELD("filler", "uint8[54]", 74, 54, SX_RESERVED),
};
const sx_layout sxm_pcx_header = {UINT32_C(0x60060003), "pcx_header", sxm_pcx_header_fields, SX_COUNT(sxm_pcx_header_fields), SX_LE};
bool sx_pcx_build(sx_context*c,uint8_t*h)
{
 return h[0]==10&&sxm_fixed(c,&sxm_pcx_header,128);
}
