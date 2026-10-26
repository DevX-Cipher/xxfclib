/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARJ data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_arj_prefix_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
};
const sx_layout sx_p_arj_prefix = { UINT32_C(0x60070001), "arj_prefix", sx_p_arj_prefix_fields, SX_COUNT(sx_p_arj_prefix_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_arj_main_fields[] = {
    SX_FIELD("first_header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("archiver_version", "uint8", 1, 1, SX_NONE),
    SX_FIELD("minimum_version", "uint8", 2, 1, SX_NONE),
    SX_FIELD("host_os", "uint8", 3, 1, SX_ID),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("method", "uint8", 5, 1, SX_ID),
    SX_FIELD("file_type", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 7, 1, SX_RESERVED),
    SX_FIELD("created", "uint32", 8, 4, SX_TIME),
    SX_FIELD("modified", "uint32", 12, 4, SX_TIME),
    SX_FIELD("archive_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("security_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("filespec_position", "uint16", 24, 2, SX_OFFSET),
    SX_FIELD("security_size", "uint16", 26, 2, SX_SIZE),
    SX_FIELD("encryption_version", "uint8", 28, 1, SX_NONE),
    SX_FIELD("last_chapter", "uint8", 29, 1, SX_NONE),
};
const sx_layout sx_p_arj_main = { UINT32_C(0x60070002), "arj_main", sx_p_arj_main_fields, SX_COUNT(sx_p_arj_main_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_arj_file_fields[] = {
    SX_FIELD("first_header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("archiver_version", "uint8", 1, 1, SX_NONE),
    SX_FIELD("minimum_version", "uint8", 2, 1, SX_NONE),
    SX_FIELD("host_os", "uint8", 3, 1, SX_ID),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("method", "uint8", 5, 1, SX_ID),
    SX_FIELD("file_type", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 7, 1, SX_RESERVED),
    SX_FIELD("modified", "uint32", 8, 4, SX_TIME),
    SX_FIELD("packed_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("crc32", "uint32", 20, 4, SX_CHECKSUM),
    SX_FIELD("filespec_position", "uint16", 24, 2, SX_OFFSET),
    SX_FIELD("access_mode", "uint16", 26, 2, SX_FLAGS),
    SX_FIELD("first_chapter", "uint8", 28, 1, SX_NONE),
    SX_FIELD("last_chapter", "uint8", 29, 1, SX_NONE),
};
const sx_layout sx_p_arj_file = { UINT32_C(0x60070003), "arj_file", sx_p_arj_file_fields, SX_COUNT(sx_p_arj_file_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_crc32_fields[] = {
    SX_FIELD("crc32", "uint32", 0, 4, SX_CHECKSUM),
};
const sx_layout sx_p_crc32 = { UINT32_C(0x60070004), "crc32", sx_p_crc32_fields, SX_COUNT(sx_p_crc32_fields), SX_LE };
static bool sx_p_arj(sx_context *c)
{
    int64_t off=0;bool main=true;
    while(off<c->size){uint16_t n;uint64_t packed=0;uint8_t first;
        if(!sx_p_sig(c,off,"\x60\xea",2)||!sx_u16(c,off+2,false,&n)||!sx_add(c,&sx_p_arj_prefix,off,4))return false;
        if(!n)return off+4==c->size;
        if(n<30||n>2600||!sx_p_span(c,off+4,(uint64_t)n+4)||!sx_p_byte(c,off+4,&first)||first<30||first>=n)return false;
        if(!sx_add(c,main?&sx_p_arj_main:&sx_p_arj_file,off+4,30)||!sx_add(c,&sx_p_crc32,off+4+n,4))return false;
        if(!main&&!sx_p_uint(c,off+16,4,&packed))return false;
        int64_t str=off+4+first;if(!sx_p_zstring(c,&str,off+4+n))return false;
        off+=8+n;
        for(;;){uint16_t ext;if(!sx_u16(c,off,false,&ext)||!sx_add(c,&sx_p_length16,off,2))return false;off+=2;if(!ext)break;if(!sx_p_span(c,off,(uint64_t)ext+4)||!sx_add(c,&sx_p_crc32,off+ext,4))return false;off+=ext+4;}
        if(!sx_p_span(c,off,packed))return false;off+=(int64_t)packed;main=false;
    }
    return !main;
}
bool sx_arj_build(sx_context*c)
{
    return sx_p_arj(c);
}
