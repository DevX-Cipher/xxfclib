/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Lzip data structures, moved out of the archive schema family. */
#include "../../xx_format_schema_archive.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_a_lzip_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 4, 1, SX_NONE),
    SX_FIELD("dictionary_size_code", "uint8", 5, 1, SX_ID),
};
const sx_layout sx_a_lzip_header = { UINT32_C(0x60040038), "lzip_header", sx_a_lzip_header_fields, SX_COUNT(sx_a_lzip_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_lzip_trailer_fields[] = {
    SX_FIELD("crc32", "uint32", 0, 4, SX_CHECKSUM),
    SX_FIELD("data_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("member_size", "uint64", 12, 8, SX_SIZE),
};
const sx_layout sx_a_lzip_trailer = { UINT32_C(0x60040039), "lzip_trailer", sx_a_lzip_trailer_fields, SX_COUNT(sx_a_lzip_trailer_fields), SX_LE };
static bool sx_a_lzip(sx_context *c)
{
    uint8_t h[6];int64_t end=c->size;
    if(!sx_read(c,0,h,6)||xx_rt_memcmp(h,"LZIP",4)||h[4]>1)return false;
    /* v0 has no encoded member size; expose its known header only. */
    if(h[4]==0)return sx_add(c,&sx_a_lzip_header,0,6)&&sx_raw(c,6,c->size-6);
    if(c->f->format_size>0&&c->f->format_size<c->size)end=c->f->format_size;
    if(!sx_raw(c,end,c->size-end))return false;
    while(end>0){
        uint64_t member;
        if(end<26||!sx_u64(c,end-8,false,&member)||member<26||member>(uint64_t)end)return false;
        int64_t start=end-(int64_t)member;
        if(!sx_read(c,start,h,6)||xx_rt_memcmp(h,"LZIP",4)||h[4]!=1||!sx_add(c,&sx_a_lzip_header,start,6)||
           !sx_raw(c,start+6,end-20-start-6)||!sx_add(c,&sx_a_lzip_trailer,end-20,20))return false;
        end=start;
    }
    return true;
}
bool sx_lzip_build(sx_context*c)
{
    return sx_a_lzip(c);
}
