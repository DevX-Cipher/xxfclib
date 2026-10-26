/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * numpy_npy data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_npy_v1_fields[] = {
    SX_FIELD("magic", "bytes", 0, 6, SX_SIGNATURE),
    SX_FIELD("major", "uint8", 6, 1, SX_ID),
    SX_FIELD("minor", "uint8", 7, 1, SX_ID),
    SX_FIELD("header_length", "uint16", 8, 2, SX_SIZE),
};
const sx_layout sxm_npy_v1 = {UINT32_C(0x60060030), "npy_v1", sxm_npy_v1_fields, SX_COUNT(sxm_npy_v1_fields), SX_LE};
static const xx_data_struct_field_desc sxm_npy_v2_fields[] = {
    SX_FIELD("magic", "bytes", 0, 6, SX_SIGNATURE),
    SX_FIELD("major", "uint8", 6, 1, SX_ID),
    SX_FIELD("minor", "uint8", 7, 1, SX_ID),
    SX_FIELD("header_length", "uint32", 8, 4, SX_SIZE),
};
const sx_layout sxm_npy_v2 = {UINT32_C(0x60060031), "npy_v2", sxm_npy_v2_fields, SX_COUNT(sxm_npy_v2_fields), SX_LE};
bool sx_numpy_npy_build(sx_context*c,uint8_t*h,size_t n)
{
 uint32_t prefix,len;if(n<10||xx_rt_memcmp(h,"\x93NUMPY",6)||h[6]<1||h[6]>3||h[7])return false;prefix=h[6]==1?10:12;if(n<prefix)return false;len=prefix==10?xx_data_get_u16(h,n,8,false):xx_data_get_u32(h,n,8,false);return sxm_span(c,prefix,len)&&sxm_fixed(c,prefix==10?&sxm_npy_v1:&sxm_npy_v2,prefix);
}
