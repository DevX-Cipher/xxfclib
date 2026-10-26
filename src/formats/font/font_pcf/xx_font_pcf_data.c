/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * font_pcf data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_pcf_header_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("table_count", "uint32", 4, 4, SX_COUNT_PROP),
};
const sx_layout sxm_pcf_header = {UINT32_C(0x60060024), "pcf_header", sxm_pcf_header_fields, SX_COUNT(sxm_pcf_header_fields), SX_LE};
static const xx_data_struct_field_desc sxm_pcf_directory_fields[] = {
    SX_FIELD("type", "uint32", 0, 4, SX_ID),
    SX_FIELD("format", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("offset", "uint32", 12, 4, SX_OFFSET),
};
const sx_layout sxm_pcf_directory = {UINT32_C(0x60060025), "pcf_directory", sxm_pcf_directory_fields, SX_COUNT(sxm_pcf_directory_fields), SX_LE};
static bool sxm_pcf(sx_context *c,const uint8_t *h)
{
    uint32_t count=xx_data_get_u32(h,8,4,false);uint64_t first=8+(uint64_t)count*16;
    if(xx_rt_memcmp(h,"\1fcp",4)||!count||count>9||!sx_add(c,&sxm_pcf_header,0,8)||!sx_table(c,&sxm_pcf_directory,8,16,count))return false;
    for(uint32_t i=0;i<count;i++){
        uint8_t e[16];uint64_t at,n;uint32_t type,fmt;
        if(!sx_read(c,8+(int64_t)i*16,e,16))return false;
        type=xx_data_get_u32(e,16,0,false);fmt=xx_data_get_u32(e,16,4,false);n=xx_data_get_u32(e,16,8,false);at=xx_data_get_u32(e,16,12,false);
        /* Historic bdftopcf declares 100 bytes but writes a 72-byte EOF accelerator. */
        if(at<=(uint64_t)c->size&&n>(uint64_t)c->size-at&&i+1==count&&(type==2||type==256)&&(fmt&256)&&n==100&&(uint64_t)c->size-at==72)n=72;
        if(at<first||!sxm_span(c,at,n))return false;
    }
    return sxm_tail(c,first);
}
bool sx_font_pcf_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=8&&sxm_pcf(c,h);
}
