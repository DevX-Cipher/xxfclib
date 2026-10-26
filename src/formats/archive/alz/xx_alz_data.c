/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ALZ data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_alz_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("reserved", "uint32", 4, 4, SX_RESERVED),
};
const sx_layout sx_p_alz_header = { UINT32_C(0x6007000B), "alz_header", sx_p_alz_header_fields, SX_COUNT(sx_p_alz_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_sizes1_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint8", 6, 1, SX_SIZE),
    SX_FIELD("original_size", "uint8", 7, 1, SX_SIZE),
};
const sx_layout sx_p_alz_sizes1 = { UINT32_C(0x6007000D), "alz_sizes1", sx_p_alz_sizes1_fields, SX_COUNT(sx_p_alz_sizes1_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_sizes2_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("original_size", "uint16", 8, 2, SX_SIZE),
};
const sx_layout sx_p_alz_sizes2 = { UINT32_C(0x6007000E), "alz_sizes2", sx_p_alz_sizes2_fields, SX_COUNT(sx_p_alz_sizes2_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_sizes3_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint24", 6, 3, SX_SIZE),
    SX_FIELD("original_size", "uint24", 9, 3, SX_SIZE),
};
const sx_layout sx_p_alz_sizes3 = { UINT32_C(0x6007000F), "alz_sizes3", sx_p_alz_sizes3_fields, SX_COUNT(sx_p_alz_sizes3_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_sizes4_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint32", 6, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 10, 4, SX_SIZE),
};
const sx_layout sx_p_alz_sizes4 = { UINT32_C(0x60070010), "alz_sizes4", sx_p_alz_sizes4_fields, SX_COUNT(sx_p_alz_sizes4_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_sizes5_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint40", 6, 5, SX_SIZE),
    SX_FIELD("original_size", "uint40", 11, 5, SX_SIZE),
};
const sx_layout sx_p_alz_sizes5 = { UINT32_C(0x60070011), "alz_sizes5", sx_p_alz_sizes5_fields, SX_COUNT(sx_p_alz_sizes5_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_sizes6_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint48", 6, 6, SX_SIZE),
    SX_FIELD("original_size", "uint48", 12, 6, SX_SIZE),
};
const sx_layout sx_p_alz_sizes6 = { UINT32_C(0x60070012), "alz_sizes6", sx_p_alz_sizes6_fields, SX_COUNT(sx_p_alz_sizes6_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_sizes7_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint56", 6, 7, SX_SIZE),
    SX_FIELD("original_size", "uint56", 13, 7, SX_SIZE),
};
const sx_layout sx_p_alz_sizes7 = { UINT32_C(0x60070013), "alz_sizes7", sx_p_alz_sizes7_fields, SX_COUNT(sx_p_alz_sizes7_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_alz_sizes8_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint64", 6, 8, SX_SIZE),
    SX_FIELD("original_size", "uint64", 14, 8, SX_SIZE),
};
const sx_layout sx_p_alz_sizes8 = { UINT32_C(0x60070014), "alz_sizes8", sx_p_alz_sizes8_fields, SX_COUNT(sx_p_alz_sizes8_fields), SX_LE };
static bool sx_p_alz(sx_context *c)
{
    if(!sx_p_sig(c,0,"ALZ\1",4)||!sx_add(c,&sx_p_alz_header,0,8))return false;
    int64_t off=8;while(off<c->size){uint32_t magic;if(!sx_u32(c,off,false,&magic))return false;
        if(magic==0x015a4c43){if(!sx_p_span(c,off,12))return false;off+=12;continue;}if(magic==0x025a4c43){off+=4;continue;}if(magic!=0x015a4c42)return false;
        uint16_t name;uint8_t descriptor;uint64_t packed=0;
        if(!sx_u16(c,off+4,false,&name)||!sx_p_byte(c,off+11,&descriptor)||!sx_add(c,&sx_p_alz_file,off,13))return false;off+=13;
        unsigned width=descriptor>>4;if(width>8)return false;
        if(width){const sx_layout *rows[]={&sx_p_alz_sizes1,&sx_p_alz_sizes2,&sx_p_alz_sizes3,&sx_p_alz_sizes4,&sx_p_alz_sizes5,&sx_p_alz_sizes6,&sx_p_alz_sizes7,&sx_p_alz_sizes8};if(!sx_add(c,rows[width-1],off,6+2*width)||!sx_p_uint(c,off+6,width,&packed))return false;off+=6+2*width;}
        if(!sx_p_span(c,off,name))return false;off+=name;if(!sx_p_span(c,off,packed))return false;off+=(int64_t)packed;
    }return true;
}
bool sx_alz_build(sx_context*c)
{
    return sx_p_alz(c);
}
