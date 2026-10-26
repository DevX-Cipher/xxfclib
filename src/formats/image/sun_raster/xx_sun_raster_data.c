/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sun_raster data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_sun_raster_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("width", "uint32", 4, 4, SX_NONE),
    SX_FIELD("height", "uint32", 8, 4, SX_NONE),
    SX_FIELD("depth_bits", "uint32", 12, 4, SX_NONE),
    SX_FIELD("data_length", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("raster_type", "uint32", 20, 4, SX_ID),
    SX_FIELD("map_type", "uint32", 24, 4, SX_ID),
    SX_FIELD("map_length", "uint32", 28, 4, SX_SIZE),
};
const sx_layout sxm_sun_raster_header = {UINT32_C(0x6006000F), "sun_raster_header", sxm_sun_raster_header_fields, SX_COUNT(sxm_sun_raster_header_fields), SX_BE};
bool sx_sun_raster_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=32&&xx_data_get_u32(h,n,0,true)==UINT32_C(0x59a66a95)&&sxm_fixed(c,&sxm_sun_raster_header,32);
}
