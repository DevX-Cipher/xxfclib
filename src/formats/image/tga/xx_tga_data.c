/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tga data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_tga_footer_fields[] = {
    SX_FIELD("extension_area_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("developer_directory_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("signature", "char[18]", 8, 18, SX_SIGNATURE),
};
const sx_layout sxm_tga_footer = {UINT32_C(0x60060002), "tga_footer", sxm_tga_footer_fields, SX_COUNT(sxm_tga_footer_fields), SX_LE};
bool sx_tga_build(sx_context*c)
{
 uint8_t footer[26];if(c->size<44||!sx_read(c,c->size-26,footer,26)||xx_rt_memcmp(footer+8,"TRUEVISION-XFILE.\0",18))return false;return sx_add(c,&sxm_tga_header,0,18)&&sxm_raw(c,18,(uint64_t)c->size-44)&&sx_add(c,&sxm_tga_footer,c->size-26,26);
}
