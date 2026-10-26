/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dds data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_dds_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("height", "uint32", 12, 4, SX_NONE),
    SX_FIELD("width", "uint32", 16, 4, SX_NONE),
    SX_FIELD("pitch_or_linear_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("depth", "uint32", 24, 4, SX_NONE),
    SX_FIELD("mipmap_count", "uint32", 28, 4, SX_COUNT_PROP),
    SX_FIELD("reserved1", "uint32[11]", 32, 44, SX_RESERVED),
    SX_FIELD("pixel_format_size", "uint32", 76, 4, SX_SIZE),
    SX_FIELD("pixel_format_flags", "uint32", 80, 4, SX_FLAGS),
    SX_FIELD("fourcc", "uint32", 84, 4, SX_ID),
    SX_FIELD("rgb_bit_count", "uint32", 88, 4, SX_NONE),
    SX_FIELD("red_mask", "uint32", 92, 4, SX_FLAGS),
    SX_FIELD("green_mask", "uint32", 96, 4, SX_FLAGS),
    SX_FIELD("blue_mask", "uint32", 100, 4, SX_FLAGS),
    SX_FIELD("alpha_mask", "uint32", 104, 4, SX_FLAGS),
    SX_FIELD("caps", "uint32", 108, 4, SX_FLAGS),
    SX_FIELD("caps2", "uint32", 112, 4, SX_FLAGS),
    SX_FIELD("caps3", "uint32", 116, 4, SX_FLAGS),
    SX_FIELD("caps4", "uint32", 120, 4, SX_FLAGS),
    SX_FIELD("reserved2", "uint32", 124, 4, SX_RESERVED),
};
const sx_layout sxm_dds_header = {UINT32_C(0x60060004), "dds_header", sxm_dds_header_fields, SX_COUNT(sxm_dds_header_fields), SX_LE};
static const xx_data_struct_field_desc sxm_dds_dx10_fields[] = {
    SX_FIELD("dxgi_format", "uint32", 0, 4, SX_ID),
    SX_FIELD("resource_dimension", "uint32", 4, 4, SX_ID),
    SX_FIELD("misc_flag", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("array_size", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("misc_flags2", "uint32", 16, 4, SX_FLAGS),
};
const sx_layout sxm_dds_dx10 = {UINT32_C(0x60060005), "dds_dx10", sxm_dds_dx10_fields, SX_COUNT(sxm_dds_dx10_fields), SX_LE};
bool sx_dds_build(sx_context*c,uint8_t*h,size_t n)
{
 if(n<128||xx_rt_memcmp(h,"DDS ",4)||xx_data_get_u32(h,128,4,false)!=124||xx_data_get_u32(h,128,76,false)!=32||!sx_add(c,&sxm_dds_header,0,128))return false;if(!xx_rt_memcmp(h+84,"DX10",4))return sx_add(c,&sxm_dds_dx10,128,20)&&sxm_tail(c,148);return sxm_tail(c,128);
}
