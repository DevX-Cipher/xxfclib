/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARTIPACK data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_artipack_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 8, 2, SX_NONE),
    SX_FIELD("member_count", "uint16", 10, 2, SX_COUNT_PROP),
    SX_FIELD("directory_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("unknown", "bytes", 16, 16, SX_NONE),
};
const sx_layout sxl_artipack_header = { UINT32_C(0x600A0032), "artipack_header", sxl_artipack_header_fields, SX_COUNT(sxl_artipack_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_artipack_directory_fields[] = {
    SX_FIELD("filename", "char[13]", 0, 13, SX_STRING),
    SX_FIELD("unknown", "uint8", 13, 1, SX_NONE),
    SX_FIELD("data_offset", "uint32", 14, 4, SX_OFFSET),
    SX_FIELD("original_size", "uint32", 18, 4, SX_SIZE),
    SX_FIELD("packed_size", "uint32", 22, 4, SX_SIZE),
    SX_FIELD("dos_date", "uint16", 26, 2, SX_NONE),
    SX_FIELD("dos_time", "uint16", 28, 2, SX_NONE),
    SX_FIELD("unknown_tail", "bytes", 30, 4, SX_NONE),
};
const sx_layout sxl_artipack_directory = { UINT32_C(0x600A0033), "artipack_directory", sxl_artipack_directory_fields, SX_COUNT(sxl_artipack_directory_fields), SX_LE };
static const xx_data_struct_field_desc sxl_artipack_size_fields[] = {
    SX_FIELD("original_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sxl_artipack_size = { UINT32_C(0x600A0034), "artipack_size", sxl_artipack_size_fields, SX_COUNT(sxl_artipack_size_fields), SX_LE };
static bool sxl_artipack(sx_context *c)
{
    uint16_t version,count;uint32_t dir;uint64_t end=32;
    if(!sxl_sig(c,0,"ARTIPACK",8)||!sx_u16(c,8,false,&version)||version!=0x100||!sx_u16(c,10,false,&count)||!count||!sx_u32(c,12,false,&dir)||dir<32||!sxl_span(c,dir,(uint64_t)count*34)||(uint64_t)dir+(uint64_t)count*34!=(uint64_t)c->size||!sx_add(c,&sxl_artipack_header,0,32)||!sx_table(c,&sxl_artipack_directory,dir,34,count))return false;
    for(uint16_t i=0;i<count;i++){uint32_t off,size,n,inner;int64_t at=dir+(int64_t)i*34;if(!sx_u32(c,at+14,false,&off)||off!=end||!sx_u32(c,at+18,false,&n)||!sx_u32(c,at+22,false,&size)||size<4||size>dir-end||!sx_u32(c,off,false,&inner)||inner!=n||!sx_add(c,&sxl_artipack_size,off,4))return false;end+=size;}return end==dir;
}
bool sx_artipack_build(sx_context*c)
{
    return sxl_artipack(c);
}
