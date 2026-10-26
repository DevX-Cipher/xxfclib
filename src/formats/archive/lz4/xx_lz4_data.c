/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZ4 frame data structures, moved out of the archive schema family. */
#include "../../xx_format_schema_archive.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_a_lz4_frame_header_00_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("FLG", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("BD", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("header_checksum", "uint8", 6, 1, SX_CHECKSUM),
};
const sx_layout sx_a_lz4_frame_header_00 = { UINT32_C(0x6004000F), "lz4_frame_header_00", sx_a_lz4_frame_header_00_fields, SX_COUNT(sx_a_lz4_frame_header_00_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_lz4_frame_header_01_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("FLG", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("BD", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
    SX_FIELD("header_checksum", "uint8", 10, 1, SX_CHECKSUM),
};
const sx_layout sx_a_lz4_frame_header_01 = { UINT32_C(0x60040010), "lz4_frame_header_01", sx_a_lz4_frame_header_01_fields, SX_COUNT(sx_a_lz4_frame_header_01_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_lz4_frame_header_10_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("FLG", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("BD", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("content_size", "uint64", 6, 8, SX_SIZE),
    SX_FIELD("header_checksum", "uint8", 14, 1, SX_CHECKSUM),
};
const sx_layout sx_a_lz4_frame_header_10 = { UINT32_C(0x60040011), "lz4_frame_header_10", sx_a_lz4_frame_header_10_fields, SX_COUNT(sx_a_lz4_frame_header_10_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_lz4_frame_header_11_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("FLG", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("BD", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("content_size", "uint64", 6, 8, SX_SIZE),
    SX_FIELD("dictionary_id", "uint32", 14, 4, SX_ID),
    SX_FIELD("header_checksum", "uint8", 18, 1, SX_CHECKSUM),
};
const sx_layout sx_a_lz4_frame_header_11 = { UINT32_C(0x60040012), "lz4_frame_header_11", sx_a_lz4_frame_header_11_fields, SX_COUNT(sx_a_lz4_frame_header_11_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_lz4_legacy_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
};
const sx_layout sx_a_lz4_legacy_header = { UINT32_C(0x60040016), "lz4_legacy_header", sx_a_lz4_legacy_header_fields, SX_COUNT(sx_a_lz4_legacy_header_fields), SX_LE };
static bool sx_a_lz4(sx_context *c)
{
    int64_t at=0;
    while(at<c->size){
        uint32_t magic;uint8_t h[6];
        if(!sx_u32(c,at,false,&magic))return false;
        if((magic&0xfffffff0U)==0x184d2a50U){if(!sx_a_skippable(c,&at))return false;continue;}
        bool legacy=magic==0x184c2102U;uint8_t flags=0;
        if(legacy){if(!sx_add(c,&sx_a_lz4_legacy_header,at,4))return false;at+=4;}
        else{
            const sx_layout *l;
            if(magic!=0x184d2204U||!sx_read(c,at,h,6)||(h[4]>>6)!=1||(h[4]&2)||(h[5]&0x8f)||((h[5]>>4)&7)<4)return false;
            flags=h[4];bool content=(flags&8)!=0,dictionary=(flags&1)!=0;
            l=content?(dictionary?&sx_a_lz4_frame_header_11:&sx_a_lz4_frame_header_10):(dictionary?&sx_a_lz4_frame_header_01:&sx_a_lz4_frame_header_00);
            int64_t size=7+(content?8:0)+(dictionary?4:0);
            if(!sx_add(c,l,at,size))return false;at+=size;
        }
        for(;;){
            uint32_t block;
            if(legacy&&at==c->size)return true;
            if(!sx_u32(c,at,false,&block)||!sx_add(c,&sx_a_lz4_block_header,at,4))return false;
            at+=4;if(!block)break;
            uint32_t size=legacy?block:block&0x7fffffffU;
            if(!size||size>8U*1024U*1024U||!sx_a_raw_advance(c,&at,size))return false;
            if(flags&16){if(!sx_add(c,&sx_a_checksum_le,at,4))return false;at+=4;}
        }
        if(flags&4){if(!sx_add(c,&sx_a_checksum_le,at,4))return false;at+=4;}
    }
    return true;
}
bool sx_lz4_build(sx_context*c)
{
    return sx_a_lz4(c);
}
