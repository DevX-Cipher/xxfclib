/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sequencing_scf data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_scf_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("samples", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("samples_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("bases", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("left_clip", "uint32", 16, 4, SX_NONE),
    SX_FIELD("right_clip", "uint32", 20, 4, SX_NONE),
    SX_FIELD("bases_offset", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("comments_size", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("comments_offset", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("version", "char[4]", 36, 4, SX_ID),
    SX_FIELD("sample_size", "uint32", 40, 4, SX_SIZE),
    SX_FIELD("code_set", "uint32", 44, 4, SX_ID),
    SX_FIELD("private_size", "uint32", 48, 4, SX_SIZE),
    SX_FIELD("private_offset", "uint32", 52, 4, SX_OFFSET),
    SX_FIELD("spare", "uint32[18]", 56, 72, SX_RESERVED),
};
const sx_layout sxm_scf_header = {UINT32_C(0x60060034), "scf_header", sxm_scf_header_fields, SX_COUNT(sxm_scf_header_fields), SX_BE};
bool sx_sequencing_scf_build(sx_context*c,uint8_t*h,size_t n)
{
 uint32_t samples,bases,width;if(n<128||xx_rt_memcmp(h,".scf",4))return false;samples=xx_data_get_u32(h,n,4,true);bases=xx_data_get_u32(h,n,12,true);width=xx_data_get_u32(h,n,40,true);
        if((width!=1&&width!=2)||!sxm_span(c,xx_data_get_u32(h,n,8,true),(uint64_t)samples*4*width)||!sxm_span(c,xx_data_get_u32(h,n,24,true),(uint64_t)bases*12)||!sxm_span(c,xx_data_get_u32(h,n,32,true),xx_data_get_u32(h,n,28,true))||!sxm_span(c,xx_data_get_u32(h,n,52,true),xx_data_get_u32(h,n,48,true)))return false;
        return sxm_fixed(c,&sxm_scf_header,128);
}
