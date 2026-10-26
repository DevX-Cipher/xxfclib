/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sequencing_abif data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_abif_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 4, 2, SX_ID),
};
const sx_layout sxm_abif_header = {UINT32_C(0x60060035), "abif_header", sxm_abif_header_fields, SX_COUNT(sxm_abif_header_fields), SX_BE};
static const xx_data_struct_field_desc sxm_abif_directory_fields[] = {
    SX_FIELD("tag_name", "char[4]", 0, 4, SX_ID),
    SX_FIELD("tag_number", "uint32", 4, 4, SX_ID),
    SX_FIELD("element_type", "uint16", 8, 2, SX_ID),
    SX_FIELD("element_size", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("element_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("data_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("data_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("data_handle", "uint32", 24, 4, SX_RESERVED),
};
const sx_layout sxm_abif_directory = {UINT32_C(0x60060036), "abif_directory", sxm_abif_directory_fields, SX_COUNT(sxm_abif_directory_fields), SX_BE};
static const xx_data_struct_field_desc sxm_abif_inline_directory_fields[] = {
    SX_FIELD("tag_name", "char[4]", 0, 4, SX_ID),
    SX_FIELD("tag_number", "uint32", 4, 4, SX_ID),
    SX_FIELD("element_type", "uint16", 8, 2, SX_ID),
    SX_FIELD("element_size", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("element_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("data_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("inline_data", "uint8[4]", 20, 4, SX_NONE),
    SX_FIELD("data_handle", "uint32", 24, 4, SX_RESERVED),
};
const sx_layout sxm_abif_inline_directory = {UINT32_C(0x60060037), "abif_inline_directory", sxm_abif_inline_directory_fields, SX_COUNT(sxm_abif_inline_directory_fields), SX_BE};
static bool sxm_abif(sx_context *c,const uint8_t *h)
{
    uint32_t count=xx_data_get_u32(h,34,18,true),bytes=xx_data_get_u32(h,34,22,true),off=xx_data_get_u32(h,34,26,true);uint64_t end;
    if(xx_rt_memcmp(h,"ABIF",4)||xx_rt_memcmp(h+6,"tdir",4)||!count||count>4096||bytes<(uint64_t)count*28||off<34||!sxm_span(c,off,bytes)||!sx_add(c,&sxm_abif_header,0,6)||!sx_add(c,&sxm_abif_directory,6,28)||!sxm_raw(c,34,off-34))return false;
    for(uint32_t i=0;i<count;i++){uint64_t at=off+(uint64_t)i*28;uint32_t n,pos;
        if(!sx_u32(c,(int64_t)at+16,true,&n)||!sx_u32(c,(int64_t)at+20,true,&pos)||!sx_add(c,n<=4?&sxm_abif_inline_directory:&sxm_abif_directory,(int64_t)at,28))return false;
        if(n>4&&!sxm_span(c,pos,n))return false;
    }
    end=off+(uint64_t)count*28;
    return sxm_tail(c,end);
}
bool sx_sequencing_abif_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=34&&sxm_abif(c,h);
}
