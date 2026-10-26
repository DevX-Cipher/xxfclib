/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * farbfeld data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_farbfeld_header_fields[] = {
    SX_FIELD("magic", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("width", "uint32", 8, 4, SX_NONE),
    SX_FIELD("height", "uint32", 12, 4, SX_NONE),
};
const sx_layout sxm_farbfeld_header = {UINT32_C(0x6006000A), "farbfeld_header", sxm_farbfeld_header_fields, SX_COUNT(sxm_farbfeld_header_fields), SX_BE};
bool sx_farbfeld_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=16&&!xx_rt_memcmp(h,"farbfeld",8)&&sxm_fixed(c,&sxm_farbfeld_header,16);
}
