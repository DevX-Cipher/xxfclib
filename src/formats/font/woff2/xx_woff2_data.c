/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WOFF2 data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_woff2_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("flavor", "uint32", 4, 4, SX_ID),
    SX_FIELD("length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("number_of_tables", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint16", 14, 2, SX_RESERVED),
    SX_FIELD("total_sfnt_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("total_compressed_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("major_version", "uint16", 24, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 26, 2, SX_NONE),
    SX_FIELD("metadata_offset", "uint32", 28, 4, SX_OFFSET),
    SX_FIELD("metadata_length", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("metadata_original_length", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("private_offset", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("private_length", "uint32", 44, 4, SX_SIZE),
};
const sx_layout sx_c_woff2_header = { UINT32_C(0x6002002C), "woff2_header", sx_c_woff2_header_fields, SX_COUNT(sx_c_woff2_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_woff2_table_flags_fields[] = {
    SX_FIELD("flags", "uint8", 0, 1, SX_FLAGS),
};
const sx_layout sx_c_woff2_table_flags = { UINT32_C(0x6002002D), "woff2_table_flags", sx_c_woff2_table_flags_fields, SX_COUNT(sx_c_woff2_table_flags_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_woff2_table_tag_fields[] = {
    SX_FIELD("tag", "char[4]", 0, 4, SX_ID),
};
const sx_layout sx_c_woff2_table_tag = { UINT32_C(0x6002002E), "woff2_table_tag", sx_c_woff2_table_tag_fields, SX_COUNT(sx_c_woff2_table_tag_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_woff2_base128_1_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 1, SX_SIZE),
};
const sx_layout sx_c_woff2_base128_1 = { UINT32_C(0x6002002F), "woff2_uintbase128_1", sx_c_woff2_base128_1_fields, SX_COUNT(sx_c_woff2_base128_1_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_woff2_base128_2_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 2, SX_SIZE),
};
const sx_layout sx_c_woff2_base128_2 = { UINT32_C(0x60020030), "woff2_uintbase128_2", sx_c_woff2_base128_2_fields, SX_COUNT(sx_c_woff2_base128_2_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_woff2_base128_3_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 3, SX_SIZE),
};
const sx_layout sx_c_woff2_base128_3 = { UINT32_C(0x60020031), "woff2_uintbase128_3", sx_c_woff2_base128_3_fields, SX_COUNT(sx_c_woff2_base128_3_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_woff2_base128_4_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 4, SX_SIZE),
};
const sx_layout sx_c_woff2_base128_4 = { UINT32_C(0x60020032), "woff2_uintbase128_4", sx_c_woff2_base128_4_fields, SX_COUNT(sx_c_woff2_base128_4_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_woff2_base128_5_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 5, SX_SIZE),
};
const sx_layout sx_c_woff2_base128_5 = { UINT32_C(0x60020033), "woff2_uintbase128_5", sx_c_woff2_base128_5_fields, SX_COUNT(sx_c_woff2_base128_5_fields), SX_BE };
static bool sx_c_woff2_base128(sx_context *c,int64_t *at,uint32_t *value)
{
    static const sx_layout *const rows[]={&sx_c_woff2_base128_1,&sx_c_woff2_base128_2,&sx_c_woff2_base128_3,&sx_c_woff2_base128_4,&sx_c_woff2_base128_5};
    uint32_t v=0;int64_t start=*at;
    for(unsigned i=0;i<5;++i){
        uint8_t b;
        if(!sx_read(c,(*at)++,&b,1)||(!i&&b==0x80)||(v&UINT32_C(0xfe000000)))return false;
        v=(v<<7)|(b&127U);
        if(!(b&128U)){*value=v;return sx_add(c,rows[i],start,i+1);}
    }
    return false;
}
static bool sx_c_woff2(sx_context *c)
{
    uint8_t h[48];uint16_t count;uint32_t total,packed;int64_t at=48;
    if(!sx_read(c,0,h,48)||xx_rt_memcmp(h,"wOF2",4))return false;
    count=xx_data_get_u16(h+12,2,0,true);total=xx_data_get_u32(h+8,4,0,true);packed=xx_data_get_u32(h+20,4,0,true);
    if(!count||total>c->size||total<48||!packed||xx_data_get_u16(h+14,2,0,true)||!sx_add(c,&sx_c_woff2_header,0,48))return false;
    /* Font collections require the additional collection directory and are
     * outside the current native WOFF2 reader's supported single-font subset. */
    if(xx_data_get_u32(h+4,4,0,true)==UINT32_C(0x74746366))return false;
    for(uint32_t i=0;i<count;++i){
        uint8_t flags,tag[4]={0};uint32_t len;unsigned index,transform;bool glyf_loca;
        if(!sx_read(c,at,&flags,1)||!sx_add(c,&sx_c_woff2_table_flags,at++,1))return false;
        index=flags&63U;transform=flags>>6;
        if(index==63){if(!sx_read(c,at,tag,4)||!sx_add(c,&sx_c_woff2_table_tag,at,4))return false;at+=4;}
        glyf_loca=index==10||index==11||(index==63&&(!xx_rt_memcmp(tag,"glyf",4)||!xx_rt_memcmp(tag,"loca",4)));
        if(!sx_c_woff2_base128(c,&at,&len))return false;
        if((glyf_loca&&transform!=3)||(!glyf_loca&&transform!=0))if(!sx_c_woff2_base128(c,&at,&len))return false;
    }
    if(at>total||packed>(uint64_t)(total-at)||!sx_raw(c,at,packed))return false;
    at+=packed;
    for(unsigned i=0;i<2;++i){
        uint32_t off=xx_data_get_u32(h+(i?40:28),4,0,true),n=xx_data_get_u32(h+(i?44:32),4,0,true);
        if(!off&&!n)continue;
        if(!off||!n||off<at||off>total||n>total-off||!sx_raw(c,at,off-at)||!sx_raw(c,off,n))return false;
        at=off+(int64_t)n;
    }
    return at<=total&&sx_raw(c,at,c->size-at);
}
bool sx_woff2_build(sx_context*c)
{
    return sx_c_woff2(c);
}
