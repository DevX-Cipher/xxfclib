/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SFNT data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_sfnt_offset_table_fields[] = {
    SX_FIELD("sfnt_version", "uint32", 0, 4, SX_ID),
    SX_FIELD("number_of_tables", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("search_range", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("entry_selector", "uint16", 8, 2, SX_NONE),
    SX_FIELD("range_shift", "uint16", 10, 2, SX_SIZE),
};
const sx_layout sx_c_sfnt_offset_table = { UINT32_C(0x60020028), "sfnt_offset_table", sx_c_sfnt_offset_table_fields, SX_COUNT(sx_c_sfnt_offset_table_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_sfnt_table_record_fields[] = {
    SX_FIELD("tag", "char[4]", 0, 4, SX_ID),
    SX_FIELD("checksum", "uint32", 4, 4, SX_CHECKSUM),
    SX_FIELD("offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("length", "uint32", 12, 4, SX_SIZE),
};
const sx_layout sx_c_sfnt_table_record = { UINT32_C(0x60020029), "sfnt_table_record", sx_c_sfnt_table_record_fields, SX_COUNT(sx_c_sfnt_table_record_fields), SX_BE };
static bool sx_c_sfnt(sx_context *c)
{
    uint8_t h[12];uint32_t version;uint16_t count;
    if(!sx_read(c,0,h,12))return false;
    version=xx_data_get_u32(h,4,0,true);count=xx_data_get_u16(h+4,2,0,true);
    if((version!=UINT32_C(0x10000)&&version!=UINT32_C(0x4f54544f)&&version!=UINT32_C(0x74727565)&&version!=UINT32_C(0x74797031))||
       !count||!sx_c_bounds(c,12,16U*(uint64_t)count)||!sx_add(c,&sx_c_sfnt_offset_table,0,12)||!sx_table(c,&sx_c_sfnt_table_record,12,16,count))return false;
    for(uint32_t i=0;i<count;++i){
        uint8_t d[16];uint32_t off,n;
        if(!sx_read(c,12+16*(int64_t)i,d,16))return false;
        off=xx_data_get_u32(d+8,4,0,true);n=xx_data_get_u32(d+12,4,0,true);
        if(off<12U+16U*count||!sx_c_font_table(c,d,off,n))return false;
    }
    return true;
}
bool sx_sfnt_build(sx_context*c)
{
    return sx_c_sfnt(c);
}
