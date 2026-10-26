/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ktx data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_le_length32_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sxm_le_length32 = {UINT32_C(0x6006000D), "le_length32", sxm_le_length32_fields, SX_COUNT(sxm_le_length32_fields), SX_LE};
static const xx_data_struct_field_desc sxm_ktx_header_le_fields[] = {
    SX_FIELD("identifier", "bytes", 0, 12, SX_SIGNATURE),
    SX_FIELD("endianness", "uint32", 12, 4, SX_ID),
    SX_FIELD("gl_type", "uint32", 16, 4, SX_ID),
    SX_FIELD("gl_type_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("gl_format", "uint32", 24, 4, SX_ID),
    SX_FIELD("gl_internal_format", "uint32", 28, 4, SX_ID),
    SX_FIELD("gl_base_internal_format", "uint32", 32, 4, SX_ID),
    SX_FIELD("pixel_width", "uint32", 36, 4, SX_NONE),
    SX_FIELD("pixel_height", "uint32", 40, 4, SX_NONE),
    SX_FIELD("pixel_depth", "uint32", 44, 4, SX_NONE),
    SX_FIELD("array_elements", "uint32", 48, 4, SX_COUNT_PROP),
    SX_FIELD("faces", "uint32", 52, 4, SX_COUNT_PROP),
    SX_FIELD("mipmap_levels", "uint32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("key_value_bytes", "uint32", 60, 4, SX_SIZE),
};
const sx_layout sxm_ktx_header_le = {UINT32_C(0x60060014), "ktx_header_le", sxm_ktx_header_le_fields, SX_COUNT(sxm_ktx_header_le_fields), SX_LE};
static const xx_data_struct_field_desc sxm_ktx_header_be_fields[] = {
    SX_FIELD("identifier", "bytes", 0, 12, SX_SIGNATURE),
    SX_FIELD("endianness", "uint32", 12, 4, SX_ID),
    SX_FIELD("gl_type", "uint32", 16, 4, SX_ID),
    SX_FIELD("gl_type_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("gl_format", "uint32", 24, 4, SX_ID),
    SX_FIELD("gl_internal_format", "uint32", 28, 4, SX_ID),
    SX_FIELD("gl_base_internal_format", "uint32", 32, 4, SX_ID),
    SX_FIELD("pixel_width", "uint32", 36, 4, SX_NONE),
    SX_FIELD("pixel_height", "uint32", 40, 4, SX_NONE),
    SX_FIELD("pixel_depth", "uint32", 44, 4, SX_NONE),
    SX_FIELD("array_elements", "uint32", 48, 4, SX_COUNT_PROP),
    SX_FIELD("faces", "uint32", 52, 4, SX_COUNT_PROP),
    SX_FIELD("mipmap_levels", "uint32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("key_value_bytes", "uint32", 60, 4, SX_SIZE),
};
const sx_layout sxm_ktx_header_be = {UINT32_C(0x60060015), "ktx_header_be", sxm_ktx_header_be_fields, SX_COUNT(sxm_ktx_header_be_fields), SX_BE};
static bool sxm_ktx(sx_context *c,const uint8_t *h)
{
    bool be=xx_data_get_u32(h,64,12,true)==UINT32_C(0x04030201);
    uint32_t meta,levels,faces,layers;uint64_t at=64,end;
    if(xx_rt_memcmp(h,"\xabKTX 11\xbb\r\n\x1a\n",12)||(!be&&xx_data_get_u32(h,64,12,false)!=UINT32_C(0x04030201)))return false;
    meta=xx_data_get_u32(h,64,60,be);levels=xx_data_get_u32(h,64,56,be);faces=xx_data_get_u32(h,64,52,be);layers=xx_data_get_u32(h,64,48,be);
    if(levels>32||(faces!=1&&faces!=6)||!sxm_span(c,at,meta)||!sx_add(c,be?&sxm_ktx_header_be:&sxm_ktx_header_le,0,64))return false;
    end=at+meta;
    while(at<end){uint32_t n;uint64_t padded;
        if(end-at<4||!sx_u32(c,(int64_t)at,be,&n)||!n)return false;padded=((uint64_t)n+3)&~UINT64_C(3);
        if(padded>end-at-4||!sx_add(c,be?&sxm_be_length32:&sxm_le_length32,(int64_t)at,4)||!sxm_raw(c,at+4,padded))return false;at+=4+padded;
    }
    if(!levels)levels=1;
    for(uint32_t i=0;i<levels;i++){uint32_t n,parts=faces==6&&!layers?6:1;uint64_t padded;
        if(!sx_u32(c,(int64_t)at,be,&n)||!n||!sx_add(c,be?&sxm_be_length32:&sxm_le_length32,(int64_t)at,4))return false;
        at+=4;padded=((uint64_t)n+3)&~UINT64_C(3);
        if(!sxm_raw(c,at,padded*parts))return false;at+=padded*parts;
    }
    return sxm_tail(c,at);
}
bool sx_ktx_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=64&&sxm_ktx(c,h);
}
