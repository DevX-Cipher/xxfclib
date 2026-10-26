/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * photoshop_psd data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_psd_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 4, 2, SX_ID),
    SX_FIELD("reserved", "bytes", 6, 6, SX_RESERVED),
    SX_FIELD("channels", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("height", "uint32", 14, 4, SX_NONE),
    SX_FIELD("width", "uint32", 18, 4, SX_NONE),
    SX_FIELD("depth_bits", "uint16", 22, 2, SX_NONE),
    SX_FIELD("color_mode", "uint16", 24, 2, SX_ID),
};
const sx_layout sxm_psd_header = {UINT32_C(0x60060006), "psd_header", sxm_psd_header_fields, SX_COUNT(sxm_psd_header_fields), SX_BE};
static const xx_data_struct_field_desc sxm_be_length64_fields[] = {
    SX_FIELD("length", "uint64", 0, 8, SX_SIZE),
};
const sx_layout sxm_be_length64 = {UINT32_C(0x60060008), "be_length64", sxm_be_length64_fields, SX_COUNT(sxm_be_length64_fields), SX_BE};
static bool sxm_psd(sx_context *c,const uint8_t *h)
{
    uint64_t at=26,n;uint16_t version=xx_data_get_u16(h,26,4,true);
    if(xx_rt_memcmp(h,"8BPS",4)||(version!=1&&version!=2)||!sx_add(c,&sxm_psd_header,0,26))return false;
    for(unsigned i=0;i<3;i++){
        bool wide=i==2&&version==2;uint32_t small=0;
        if(wide){if(!sx_u64(c,(int64_t)at,true,&n))return false;}
        else{if(!sx_u32(c,(int64_t)at,true,&small))return false;n=small;}
        if(!sx_add(c,wide?&sxm_be_length64:&sxm_be_length32,(int64_t)at,wide?8:4))return false;
        at+=wide?8:4;if(!sxm_raw(c,at,n))return false;at+=n;
    }
    return sx_add(c,&sxm_psd_compression,(int64_t)at,2)&&sxm_tail(c,at+2);
}
bool sx_photoshop_psd_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=26&&sxm_psd(c,h);
}
