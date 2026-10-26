/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * genomics_sff data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_sff_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("index_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("index_length", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("read_count", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("header_length", "uint16", 24, 2, SX_SIZE),
    SX_FIELD("key_length", "uint16", 26, 2, SX_COUNT_PROP),
    SX_FIELD("flows_per_read", "uint16", 28, 2, SX_COUNT_PROP),
    SX_FIELD("flowgram_format_code", "uint8", 30, 1, SX_ID),
};
const sx_layout sxm_sff_header = {UINT32_C(0x60060038), "sff_header", sxm_sff_header_fields, SX_COUNT(sxm_sff_header_fields), SX_BE};
static const xx_data_struct_field_desc sxm_sff_read_header_fields[] = {
    SX_FIELD("header_length", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("name_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("base_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("clip_quality_left", "uint16", 8, 2, SX_NONE),
    SX_FIELD("clip_quality_right", "uint16", 10, 2, SX_NONE),
    SX_FIELD("clip_adapter_left", "uint16", 12, 2, SX_NONE),
    SX_FIELD("clip_adapter_right", "uint16", 14, 2, SX_NONE),
};
const sx_layout sxm_sff_read_header = {UINT32_C(0x60060039), "sff_read_header", sxm_sff_read_header_fields, SX_COUNT(sxm_sff_read_header_fields), SX_BE};
static bool sxm_sff(sx_context *c,const uint8_t *h)
{
    uint64_t index=xx_data_get_u64(h,31,8,true),index_size=xx_data_get_u32(h,31,16,true),at=xx_data_get_u16(h,31,24,true);uint32_t count=xx_data_get_u32(h,31,20,true),flows=xx_data_get_u16(h,31,28,true);
    if(xx_rt_memcmp(h,".sff",4)||!count||count>512||at<31||!sxm_span(c,index,index_size)||!sx_add(c,&sxm_sff_header,0,31)||!sxm_raw(c,31,at-31))return false;
    for(uint32_t i=0;i<count;i++){
        uint8_t b[16];uint32_t header,n;uint64_t data;
        if(index&&at==index){uint64_t padded=(index_size+7)&~UINT64_C(7);if(!sxm_raw(c,at,padded))return false;at+=padded;}
        if(!sx_read(c,(int64_t)at,b,16))return false;header=xx_data_get_u16(b,16,0,true);n=xx_data_get_u32(b,16,4,true);
        if(header<16||!sx_add(c,&sxm_sff_read_header,(int64_t)at,16)||!sxm_raw(c,at+16,header-16))return false;at+=header;
        data=((uint64_t)flows*2+(uint64_t)n*3+7)&~UINT64_C(7);
        if(!sxm_raw(c,at,data))return false;at+=data;
    }
    return sxm_tail(c,at);
}
bool sx_genomics_sff_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=31&&sxm_sff(c,h);
}
