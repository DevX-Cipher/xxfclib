/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ACE data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_ace_main_fields[] = {
    SX_FIELD("header_crc", "uint16", 0, 2, SX_CHECKSUM),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("header_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("flags", "uint16", 5, 2, SX_FLAGS),
    SX_FIELD("signature", "char[7]", 7, 7, SX_SIGNATURE),
    SX_FIELD("extract_version", "uint8", 14, 1, SX_NONE),
    SX_FIELD("create_version", "uint8", 15, 1, SX_NONE),
    SX_FIELD("host_os", "uint8", 16, 1, SX_ID),
    SX_FIELD("volume", "uint8", 17, 1, SX_NONE),
    SX_FIELD("created", "uint32", 18, 4, SX_TIME),
    SX_FIELD("reserved", "bytes", 22, 8, SX_RESERVED),
    SX_FIELD("advert_size", "uint8", 30, 1, SX_SIZE),
};
const sx_layout sx_p_ace_main = { UINT32_C(0x60070007), "ace_main", sx_p_ace_main_fields, SX_COUNT(sx_p_ace_main_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_ace_generic_fields[] = {
    SX_FIELD("header_crc", "uint16", 0, 2, SX_CHECKSUM),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("header_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("flags", "uint16", 5, 2, SX_FLAGS),
};
const sx_layout sx_p_ace_generic = { UINT32_C(0x60070008), "ace_generic", sx_p_ace_generic_fields, SX_COUNT(sx_p_ace_generic_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_ace_file32_fields[] = {
    SX_FIELD("header_crc", "uint16", 0, 2, SX_CHECKSUM),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("header_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("flags", "uint16", 5, 2, SX_FLAGS),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint32", 19, 4, SX_FLAGS),
    SX_FIELD("crc32", "uint32", 23, 4, SX_CHECKSUM),
    SX_FIELD("method", "uint8", 27, 1, SX_ID),
    SX_FIELD("quality", "uint8", 28, 1, SX_NONE),
    SX_FIELD("parameter", "uint16", 29, 2, SX_NONE),
    SX_FIELD("reserved", "uint16", 31, 2, SX_RESERVED),
    SX_FIELD("name_size", "uint16", 33, 2, SX_SIZE),
};
const sx_layout sx_p_ace_file32 = { UINT32_C(0x60070009), "ace_file32", sx_p_ace_file32_fields, SX_COUNT(sx_p_ace_file32_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_ace_file64_fields[] = {
    SX_FIELD("header_crc", "uint16", 0, 2, SX_CHECKSUM),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("header_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("flags", "uint16", 5, 2, SX_FLAGS),
    SX_FIELD("packed_size", "uint64", 7, 8, SX_SIZE),
    SX_FIELD("original_size", "uint64", 15, 8, SX_SIZE),
    SX_FIELD("modified", "uint32", 23, 4, SX_TIME),
    SX_FIELD("attributes", "uint32", 27, 4, SX_FLAGS),
    SX_FIELD("crc32", "uint32", 31, 4, SX_CHECKSUM),
    SX_FIELD("method", "uint8", 35, 1, SX_ID),
    SX_FIELD("quality", "uint8", 36, 1, SX_NONE),
    SX_FIELD("parameter", "uint16", 37, 2, SX_NONE),
    SX_FIELD("reserved", "uint16", 39, 2, SX_RESERVED),
    SX_FIELD("name_size", "uint16", 41, 2, SX_SIZE),
};
const sx_layout sx_p_ace_file64 = { UINT32_C(0x6007000A), "ace_file64", sx_p_ace_file64_fields, SX_COUNT(sx_p_ace_file64_fields), SX_LE };
static bool sx_p_ace(sx_context *c)
{
    int64_t off=0;bool first=true;
    while(off<c->size){uint16_t n,flags;uint8_t type;uint64_t packed=0;
        if(!sx_u16(c,off+2,false,&n)||n<3||!sx_u16(c,off+5,false,&flags)||!sx_p_byte(c,off+4,&type)||!sx_p_span(c,off,(uint64_t)n+4))return false;
        const sx_layout *l=&sx_p_ace_generic;int size=7;
        if(first){if(type||n<27||!sx_p_sig(c,off+7,"**ACE**",7))return false;l=&sx_p_ace_main;size=31;}
        else if(type==1||type==3){bool wide=(flags&4)!=0;uint16_t names;size=wide?43:35;l=wide?&sx_p_ace_file64:&sx_p_ace_file32;if(!(flags&1)||(type==1&&wide)||(type==3&&!wide)||n+4<size||!sx_u16(c,off+size-2,false,&names)||names>n+4-size||!sx_p_uint(c,off+7,wide?8:4,&packed))return false;}
        else if(flags&1){if(n<3+((flags&4)?8:4)||!sx_p_uint(c,off+7,(flags&4)?8:4,&packed))return false;}
        if(!sx_add(c,l,off,size))return false;off+=n+4;if(!sx_p_span(c,off,packed))return false;off+=(int64_t)packed;first=false;
    }return !first;
}
bool sx_ace_build(sx_context*c)
{
    return sx_p_ace(c);
}
