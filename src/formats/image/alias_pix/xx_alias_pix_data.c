/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * alias_pix data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_alias_pix_header_fields[] = {
    SX_FIELD("width", "uint16", 0, 2, SX_NONE),
    SX_FIELD("height", "uint16", 2, 2, SX_NONE),
    SX_FIELD("x_offset", "uint16", 4, 2, SX_NONE),
    SX_FIELD("y_offset", "uint16", 6, 2, SX_NONE),
    SX_FIELD("bits_per_pixel", "uint16", 8, 2, SX_NONE),
};
const sx_layout sxm_alias_pix_header = {UINT32_C(0x60060011), "alias_pix_header", sxm_alias_pix_header_fields, SX_COUNT(sxm_alias_pix_header_fields), SX_BE};
bool sx_alias_pix_build(sx_context*c,size_t n)
{
 return n>=10&&sxm_fixed(c,&sxm_alias_pix_header,10);
}
