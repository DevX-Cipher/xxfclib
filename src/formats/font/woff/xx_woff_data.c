/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WOFF data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_woff_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("flavor", "uint32", 4, 4, SX_ID),
    SX_FIELD("length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("number_of_tables", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint16", 14, 2, SX_RESERVED),
    SX_FIELD("total_sfnt_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("major_version", "uint16", 20, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 22, 2, SX_NONE),
    SX_FIELD("metadata_offset", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("metadata_length", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("metadata_original_length", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("private_offset", "uint32", 36, 4, SX_OFFSET),
    SX_FIELD("private_length", "uint32", 40, 4, SX_SIZE),
};
const sx_layout sx_c_woff_header = { UINT32_C(0x6002002A), "woff_header", sx_c_woff_header_fields, SX_COUNT(sx_c_woff_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_woff_table_record_fields[] = {
    SX_FIELD("tag", "char[4]", 0, 4, SX_ID),
    SX_FIELD("offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("compressed_length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("original_length", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("original_checksum", "uint32", 16, 4, SX_CHECKSUM),
};
const sx_layout sx_c_woff_table_record = { UINT32_C(0x6002002B), "woff_table_record", sx_c_woff_table_record_fields, SX_COUNT(sx_c_woff_table_record_fields), SX_BE };
static bool sx_c_woff(sx_context *c)
{
    uint8_t h[44];uint32_t total;uint16_t count;
    if(!sx_read(c,0,h,44)||xx_rt_memcmp(h,"wOFF",4))return false;
    count=xx_data_get_u16(h+12,2,0,true);total=xx_data_get_u32(h+8,4,0,true);
    if(!count||total>c->size||total<44U+20U*count||xx_data_get_u16(h+14,2,0,true)||!sx_add(c,&sx_c_woff_header,0,44)||
       !sx_table(c,&sx_c_woff_table_record,44,20,count))return false;
    for(uint32_t i=0;i<count;++i){
        uint8_t d[20];uint32_t off,n,orig;
        if(!sx_read(c,44+20*(int64_t)i,d,20))return false;
        off=xx_data_get_u32(d+4,4,0,true);n=xx_data_get_u32(d+8,4,0,true);orig=xx_data_get_u32(d+12,4,0,true);
        if(off<44U+20U*count||off>total||n>total-off||n>orig)return false;
        if(n==orig){if(!sx_c_font_table(c,d,off,n))return false;}
        else if(!sx_raw(c,off,n))return false;
    }
    for(unsigned i=0;i<2;++i){
        uint32_t off=xx_data_get_u32(h+(i?36:24),4,0,true),n=xx_data_get_u32(h+(i?40:28),4,0,true);
        if((!off)!=(!n)||off>total||n>total-off||!sx_raw(c,off,n))return false;
    }
    return sx_raw(c,total,c->size-total);
}
bool sx_woff_build(sx_context*c)
{
    return sx_c_woff(c);
}
