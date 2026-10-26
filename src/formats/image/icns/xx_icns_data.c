/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * icns data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_icns_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("file_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sxm_icns_header = {UINT32_C(0x6006001E), "icns_header", sxm_icns_header_fields, SX_COUNT(sxm_icns_header_fields), SX_BE};
static const xx_data_struct_field_desc sxm_icns_element_fields[] = {
    SX_FIELD("type", "char[4]", 0, 4, SX_ID),
    SX_FIELD("element_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sxm_icns_element = {UINT32_C(0x6006001F), "icns_element", sxm_icns_element_fields, SX_COUNT(sxm_icns_element_fields), SX_BE};
static bool sxm_icns(sx_context *c,const uint8_t *h)
{
    uint64_t at=8,end=xx_data_get_u32(h,8,4,true);
    if(xx_rt_memcmp(h,"icns",4)||end<8||!sxm_span(c,0,end)||!sx_add(c,&sxm_icns_header,0,8))return false;
    while(at<end){uint32_t n;if(end-at<8||!sx_u32(c,(int64_t)at+4,true,&n)||n<8||n>end-at||!sx_add(c,&sxm_icns_element,(int64_t)at,8)||!sxm_raw(c,at+8,n-8))return false;at+=n;}
    return sxm_tail(c,end);
}
bool sx_icns_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=8&&sxm_icns(c,h);
}
