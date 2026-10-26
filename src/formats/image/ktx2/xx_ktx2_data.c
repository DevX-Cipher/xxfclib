/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ktx2 data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_ktx2_header_fields[] = {
    SX_FIELD("identifier", "bytes", 0, 12, SX_SIGNATURE),
    SX_FIELD("vk_format", "uint32", 12, 4, SX_ID),
    SX_FIELD("type_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("pixel_width", "uint32", 20, 4, SX_NONE),
    SX_FIELD("pixel_height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("pixel_depth", "uint32", 28, 4, SX_NONE),
    SX_FIELD("layer_count", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("face_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("level_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("supercompression_scheme", "uint32", 44, 4, SX_ID),
    SX_FIELD("dfd_offset", "uint32", 48, 4, SX_OFFSET),
    SX_FIELD("dfd_length", "uint32", 52, 4, SX_SIZE),
    SX_FIELD("kvd_offset", "uint32", 56, 4, SX_OFFSET),
    SX_FIELD("kvd_length", "uint32", 60, 4, SX_SIZE),
    SX_FIELD("sgd_offset", "uint64", 64, 8, SX_OFFSET),
    SX_FIELD("sgd_length", "uint64", 72, 8, SX_SIZE),
};
const sx_layout sxm_ktx2_header = {UINT32_C(0x60060016), "ktx2_header", sxm_ktx2_header_fields, SX_COUNT(sxm_ktx2_header_fields), SX_LE};
static const xx_data_struct_field_desc sxm_ktx2_level_fields[] = {
    SX_FIELD("byte_offset", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("byte_length", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("uncompressed_byte_length", "uint64", 16, 8, SX_SIZE),
};
const sx_layout sxm_ktx2_level = {UINT32_C(0x60060017), "ktx2_level", sxm_ktx2_level_fields, SX_COUNT(sxm_ktx2_level_fields), SX_LE};
static bool sxm_ktx2(sx_context *c,const uint8_t *h)
{
    uint32_t levels=xx_data_get_u32(h,80,40,false);uint64_t at;
    if(xx_rt_memcmp(h,"\xabKTX 20\xbb\r\n\x1a\n",12)||levels>32)return false;
    if(!levels)levels=1;
    if(!sx_add(c,&sxm_ktx2_header,0,80)||!sx_table(c,&sxm_ktx2_level,80,24,levels))return false;
    at=80+(uint64_t)levels*24;
    for(uint32_t i=0;i<levels;i++){uint64_t off,n;if(!sx_u64(c,80+(int64_t)i*24,false,&off)||!sx_u64(c,88+(int64_t)i*24,false,&n)||!sxm_span(c,off,n))return false;}
    for(unsigned i=48;i<=56;i+=8){uint32_t off=xx_data_get_u32(h,80,i,false),n=xx_data_get_u32(h,80,i+4,false);if(n&&!sxm_span(c,off,n))return false;}
    if(!sxm_span(c,xx_data_get_u64(h,80,64,false),xx_data_get_u64(h,80,72,false)))return false;
    return sxm_tail(c,at);
}
bool sx_ktx2_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=80&&sxm_ktx2(c,h);
}
