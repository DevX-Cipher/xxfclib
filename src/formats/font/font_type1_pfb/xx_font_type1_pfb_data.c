/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * font_type1_pfb data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_pfb_segment_fields[] = {
    SX_FIELD("marker", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("type", "uint8", 1, 1, SX_ID),
    SX_FIELD("length", "uint32", 2, 4, SX_SIZE),
};
const sx_layout sxm_pfb_segment = {UINT32_C(0x60060026), "pfb_segment", sxm_pfb_segment_fields, SX_COUNT(sxm_pfb_segment_fields), SX_LE};
static const xx_data_struct_field_desc sxm_pfb_end_fields[] = {
    SX_FIELD("marker", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("type", "uint8", 1, 1, SX_ID),
};
const sx_layout sxm_pfb_end = {UINT32_C(0x60060027), "pfb_end", sxm_pfb_end_fields, SX_COUNT(sxm_pfb_end_fields), SX_LE};
static bool sxm_pfb(sx_context *c)
{
    uint64_t at=0;
    while(at<(uint64_t)c->size){uint8_t h[6];uint32_t n;
        if(!sx_read(c,(int64_t)at,h,2)||h[0]!=128)return false;
        if(h[1]==3)return sx_add(c,&sxm_pfb_end,(int64_t)at,2)&&sxm_tail(c,at+2);
        if((h[1]!=1&&h[1]!=2)||!sx_read(c,(int64_t)at,h,6))return false;n=xx_data_get_u32(h,6,2,false);
        if(!n||!sx_add(c,&sxm_pfb_segment,(int64_t)at,6)||!sxm_raw(c,at+6,n))return false;at+=6+(uint64_t)n;
    }
    return false;
}
bool sx_font_type1_pfb_build(sx_context*c)
{
 return sxm_pfb(c);
}
