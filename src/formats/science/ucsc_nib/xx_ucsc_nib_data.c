/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ucsc_nib data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_nib_header_le_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("sequence_length", "uint32", 4, 4, SX_COUNT_PROP),
};
const sx_layout sxm_nib_header_le = {UINT32_C(0x60060032), "nib_header_le", sxm_nib_header_le_fields, SX_COUNT(sxm_nib_header_le_fields), SX_LE};
static const xx_data_struct_field_desc sxm_nib_header_be_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("sequence_length", "uint32", 4, 4, SX_COUNT_PROP),
};
const sx_layout sxm_nib_header_be = {UINT32_C(0x60060033), "nib_header_be", sxm_nib_header_be_fields, SX_COUNT(sxm_nib_header_be_fields), SX_BE};
bool sx_ucsc_nib_build(sx_context*c,uint8_t*h,size_t n)
{
 bool be;if(n<8)return false;be=xx_data_get_u32(h,n,0,true)==UINT32_C(0x6be93d3a);if(!be&&xx_data_get_u32(h,n,0,false)!=UINT32_C(0x6be93d3a))return false;return sxm_span(c,8,((uint64_t)xx_data_get_u32(h,n,4,be)+1)/2)&&sxm_fixed(c,be?&sxm_nib_header_be:&sxm_nib_header_le,8);
}
