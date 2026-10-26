/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pkm_texture data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_pkm_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "char[2]", 4, 2, SX_ID),
    SX_FIELD("texture_format", "uint16", 6, 2, SX_ID),
    SX_FIELD("encoded_width", "uint16", 8, 2, SX_NONE),
    SX_FIELD("encoded_height", "uint16", 10, 2, SX_NONE),
    SX_FIELD("width", "uint16", 12, 2, SX_NONE),
    SX_FIELD("height", "uint16", 14, 2, SX_NONE),
};
const sx_layout sxm_pkm_header = {UINT32_C(0x60060013), "pkm_header", sxm_pkm_header_fields, SX_COUNT(sxm_pkm_header_fields), SX_BE};
bool sx_pkm_texture_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=16&&(!xx_rt_memcmp(h,"PKM 10",6)||!xx_rt_memcmp(h,"PKM 20",6))&&sxm_fixed(c,&sxm_pkm_header,16);
}
