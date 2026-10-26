/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Mozilla MAR data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_mar_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("index_offset", "uint32", 4, 4, SX_OFFSET),
};
const sx_layout sx_p_mar_header = { UINT32_C(0x60070041), "mar_header", sx_p_mar_header_fields, SX_COUNT(sx_p_mar_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_mar_index_fields[] = {
    SX_FIELD("index_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_p_mar_index = { UINT32_C(0x60070042), "mar_index", sx_p_mar_index_fields, SX_COUNT(sx_p_mar_index_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_mar_entry_fields[] = {
    SX_FIELD("data_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("data_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
};
const sx_layout sx_p_mar_entry = { UINT32_C(0x60070043), "mar_entry", sx_p_mar_entry_fields, SX_COUNT(sx_p_mar_entry_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_mar_signed_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("index_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("file_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("signature_count", "uint32", 16, 4, SX_COUNT_PROP),
};
const sx_layout sx_p_mar_signed_header = { UINT32_C(0x60070054), "mar_signed_header", sx_p_mar_signed_header_fields, SX_COUNT(sx_p_mar_signed_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_mar_signature_fields[] = {
    SX_FIELD("algorithm", "uint32", 0, 4, SX_ID),
    SX_FIELD("signature_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sx_p_mar_signature = { UINT32_C(0x60070055), "mar_signature", sx_p_mar_signature_fields, SX_COUNT(sx_p_mar_signature_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_mar_sections_fields[] = {
    SX_FIELD("section_count", "uint32", 0, 4, SX_COUNT_PROP),
};
const sx_layout sx_p_mar_sections = { UINT32_C(0x60070056), "mar_sections", sx_p_mar_sections_fields, SX_COUNT(sx_p_mar_sections_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_mar_section_fields[] = {
    SX_FIELD("section_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("section_id", "uint32", 4, 4, SX_ID),
};
const sx_layout sx_p_mar_section = { UINT32_C(0x60070057), "mar_section", sx_p_mar_section_fields, SX_COUNT(sx_p_mar_section_fields), SX_BE };
static bool sx_p_mar(sx_context *c)
{
    uint32_t index,size;uint64_t declared=0;int64_t data_start=8;
    if(!sx_p_sig(c,0,"MAR1",4)||!sx_u32(c,4,true,&index)||index<8||!sx_u32(c,index,true,&size)||!sx_p_span(c,(uint64_t)index+4,size))return false;
    uint64_t archive_size=(uint64_t)index+4+size;
    if(index>=24&&!sx_u64(c,8,true,&declared))return false;
    if(declared==archive_size){uint32_t signatures,sections;
        if(!sx_u32(c,16,true,&signatures)||signatures>8||!sx_add(c,&sx_p_mar_signed_header,0,20))return false;data_start=20;
        for(uint32_t i=0;i<signatures;i++){uint32_t n;if(data_start>index-8||!sx_u32(c,data_start+4,true,&n)||n>2048||n>index-data_start-8||!sx_add(c,&sx_p_mar_signature,data_start,8))return false;data_start+=8+n;}
        if(data_start>index-4||!sx_u32(c,data_start,true,&sections)||sections>1024||!sx_add(c,&sx_p_mar_sections,data_start,4))return false;data_start+=4;
        for(uint32_t i=0;i<sections;i++){uint32_t n;if(data_start>index-8||!sx_u32(c,data_start,true,&n)||n<8||n>index-data_start||!sx_add(c,&sx_p_mar_section,data_start,8))return false;data_start+=n;}
    }else if(!sx_add(c,&sx_p_mar_header,0,8))return false;
    if(!sx_add(c,&sx_p_mar_index,index,4))return false;int64_t off=(int64_t)index+4,end=off+size;
    while(off<end){uint32_t data,n;if(end-off<13||!sx_u32(c,off,true,&data)||!sx_u32(c,off+4,true,&n)||data>index||n>index-data||(n&&data<(uint64_t)data_start)||!sx_add(c,&sx_p_mar_entry,off,12))return false;off+=12;if(!sx_p_zstring(c,&off,end))return false;}return off==end;
}
bool sx_mozilla_mar_build(sx_context*c)
{
    return sx_p_mar(c);
}
