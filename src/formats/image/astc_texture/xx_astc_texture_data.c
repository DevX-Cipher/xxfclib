/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * astc_texture data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_astc_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("block_width", "uint8", 4, 1, SX_NONE),
    SX_FIELD("block_height", "uint8", 5, 1, SX_NONE),
    SX_FIELD("block_depth", "uint8", 6, 1, SX_NONE),
    SX_FIELD("width", "uint24", 7, 3, SX_NONE),
    SX_FIELD("height", "uint24", 10, 3, SX_NONE),
    SX_FIELD("depth", "uint24", 13, 3, SX_NONE),
};
const sx_layout sxm_astc_header = {UINT32_C(0x60060012), "astc_header", sxm_astc_header_fields, SX_COUNT(sxm_astc_header_fields), SX_LE};
bool sx_astc_texture_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=16&&!xx_rt_memcmp(h,"\x13\xab\xa1\x5c",4)&&sxm_fixed(c,&sxm_astc_header,16);
}
