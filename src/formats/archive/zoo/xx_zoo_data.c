/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZOO data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_zoo_header_fields[] = {
    SX_FIELD("banner", "char[20]", 0, 20, SX_STRING),
    SX_FIELD("magic", "uint32", 20, 4, SX_SIGNATURE),
    SX_FIELD("first_directory", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("negative_first_directory", "uint32", 28, 4, SX_NONE),
    SX_FIELD("version_major", "uint8", 32, 1, SX_NONE),
    SX_FIELD("version_minor", "uint8", 33, 1, SX_NONE),
};
const sx_layout sx_p_zoo_header = { UINT32_C(0x60070018), "zoo_header", sx_p_zoo_header_fields, SX_COUNT(sx_p_zoo_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_zoo_variable_fields[] = {
    SX_FIELD("variable_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("timezone", "int8", 2, 1, SX_NONE),
    SX_FIELD("header_crc16", "uint16", 3, 2, SX_CHECKSUM),
    SX_FIELD("name_size", "uint8", 5, 1, SX_SIZE),
    SX_FIELD("directory_size", "uint8", 6, 1, SX_SIZE),
};
const sx_layout sx_p_zoo_variable = { UINT32_C(0x6007001A), "zoo_variable", sx_p_zoo_variable_fields, SX_COUNT(sx_p_zoo_variable_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_zoo_attributes_fields[] = {
    SX_FIELD("system_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("attributes", "uint24", 2, 3, SX_FLAGS),
};
const sx_layout sx_p_zoo_attributes = { UINT32_C(0x6007004F), "zoo_attributes", sx_p_zoo_attributes_fields, SX_COUNT(sx_p_zoo_attributes_fields), SX_LE };
static bool sx_p_zoo(sx_context *c)
{
    uint32_t magic,first;if(!sx_u32(c,20,false,&magic)||magic!=0xfdc4a7dc||!sx_u32(c,24,false,&first)||!sx_add(c,&sx_p_zoo_header,0,34))return false;int64_t off=first;
    for(unsigned steps=0;off&&steps<100000;steps++) {uint8_t type;uint32_t next,data,packed,comment;uint16_t comment_size;
        if(!sx_u32(c,off,false,&magic)||magic!=0xfdc4a7dc||!sx_p_byte(c,off+4,&type)||!sx_u32(c,off+6,false,&next)||!sx_u32(c,off+10,false,&data)||!sx_u32(c,off+24,false,&packed)||!sx_u32(c,off+32,false,&comment)||!sx_u16(c,off+36,false,&comment_size)||!sx_add(c,&sx_p_zoo_directory,off,51)||!sx_p_span(c,data,packed)||!sx_p_span(c,comment,comment_size))return false;
        if(type==2){uint16_t n;uint8_t name,dir;if(!sx_u16(c,off+51,false,&n)||!sx_p_span(c,off+53,n))return false;
            if(n>=5){if(!sx_read(c,off+56,&name,1)||!sx_read(c,off+57,&dir,1)||(unsigned)name+dir>n-5||!sx_add(c,&sx_p_zoo_variable,off+51,7))return false;if(n>=10+name+dir&&!sx_add(c,&sx_p_zoo_attributes,off+58+name+dir,5))return false;}
            else if(!sx_add(c,&sx_p_length16,off+51,2))return false;
        }else if(type!=1)return false;
        if(!next)return true;if(next<=off)return false;off=next;
    }return off==0;
}
bool sx_zoo_build(sx_context*c)
{
    return sx_p_zoo(c);
}
