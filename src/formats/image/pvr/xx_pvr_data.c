/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pvr data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_pvr_header_le_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("flags", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("pixel_format", "uint64", 8, 8, SX_ID),
    SX_FIELD("color_space", "uint32", 16, 4, SX_ID),
    SX_FIELD("channel_type", "uint32", 20, 4, SX_ID),
    SX_FIELD("height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("width", "uint32", 28, 4, SX_NONE),
    SX_FIELD("depth", "uint32", 32, 4, SX_NONE),
    SX_FIELD("surface_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("face_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("mipmap_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("metadata_size", "uint32", 48, 4, SX_SIZE),
};
const sx_layout sxm_pvr_header_le = {UINT32_C(0x60060018), "pvr_header_le", sxm_pvr_header_le_fields, SX_COUNT(sxm_pvr_header_le_fields), SX_LE};
static const xx_data_struct_field_desc sxm_pvr_metadata_le_fields[] = {
    SX_FIELD("fourcc", "uint32", 0, 4, SX_ID),
    SX_FIELD("key", "uint32", 4, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 8, 4, SX_SIZE),
};
const sx_layout sxm_pvr_metadata_le = {UINT32_C(0x60060019), "pvr_metadata_le", sxm_pvr_metadata_le_fields, SX_COUNT(sxm_pvr_metadata_le_fields), SX_LE};
static const xx_data_struct_field_desc sxm_pvr_header_be_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("flags", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("pixel_format", "uint64", 8, 8, SX_ID),
    SX_FIELD("color_space", "uint32", 16, 4, SX_ID),
    SX_FIELD("channel_type", "uint32", 20, 4, SX_ID),
    SX_FIELD("height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("width", "uint32", 28, 4, SX_NONE),
    SX_FIELD("depth", "uint32", 32, 4, SX_NONE),
    SX_FIELD("surface_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("face_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("mipmap_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("metadata_size", "uint32", 48, 4, SX_SIZE),
};
const sx_layout sxm_pvr_header_be = {UINT32_C(0x6006001A), "pvr_header_be", sxm_pvr_header_be_fields, SX_COUNT(sxm_pvr_header_be_fields), SX_BE};
static const xx_data_struct_field_desc sxm_pvr_metadata_be_fields[] = {
    SX_FIELD("fourcc", "uint32", 0, 4, SX_ID),
    SX_FIELD("key", "uint32", 4, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 8, 4, SX_SIZE),
};
const sx_layout sxm_pvr_metadata_be = {UINT32_C(0x6006001B), "pvr_metadata_be", sxm_pvr_metadata_be_fields, SX_COUNT(sxm_pvr_metadata_be_fields), SX_BE};
static bool sxm_pvr(sx_context *c,const uint8_t *h)
{
    bool be=xx_data_get_u32(h,52,0,true)==UINT32_C(0x03525650);uint64_t at=52,end;uint32_t meta;
    if(!be&&xx_data_get_u32(h,52,0,false)!=UINT32_C(0x03525650))return false;
    meta=xx_data_get_u32(h,52,48,be);if(!sxm_span(c,52,meta)||!sx_add(c,be?&sxm_pvr_header_be:&sxm_pvr_header_le,0,52))return false;end=52+(uint64_t)meta;
    while(at<end){uint32_t n;if(end-at<12||!sx_u32(c,(int64_t)at+8,be,&n)||n>end-at-12||!sx_add(c,be?&sxm_pvr_metadata_be:&sxm_pvr_metadata_le,(int64_t)at,12)||!sxm_raw(c,at+12,n))return false;at+=12+(uint64_t)n;}
    return sxm_tail(c,at);
}
bool sx_pvr_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=52&&sxm_pvr(c,h);
}
