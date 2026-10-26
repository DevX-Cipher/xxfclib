/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * avs_image data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_avs_header_fields[] = {
    SX_FIELD("width", "uint32", 0, 4, SX_NONE),
    SX_FIELD("height", "uint32", 4, 4, SX_NONE),
};
const sx_layout sxm_avs_header = {UINT32_C(0x60060010), "avs_header", sxm_avs_header_fields, SX_COUNT(sxm_avs_header_fields), SX_BE};
bool sx_avs_image_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=8&&xx_data_get_u32(h,n,0,true)&&xx_data_get_u32(h,n,4,true)&&sxm_fixed(c,&sxm_avs_header,8);
}
