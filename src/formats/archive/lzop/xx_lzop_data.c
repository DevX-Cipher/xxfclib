/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZOP data structures, moved out of the archive schema family. */
#include "../../xx_format_schema_archive.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_a_checksum_be_fields[] = {
    SX_FIELD("checksum", "uint32", 0, 4, SX_CHECKSUM),
};
const sx_layout sx_a_checksum_be = { UINT32_C(0x60040015), "checksum_be", sx_a_checksum_be_fields, SX_COUNT(sx_a_checksum_be_fields), SX_BE };
static const xx_data_struct_field_desc sx_a_lzop_block_sizes_fields[] = {
    SX_FIELD("uncompressed_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("compressed_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sx_a_lzop_block_sizes = { UINT32_C(0x6004003E), "lzop_block_sizes", sx_a_lzop_block_sizes_fields, SX_COUNT(sx_a_lzop_block_sizes_fields), SX_BE };
static const xx_data_struct_field_desc sx_a_lzop_end_fields[] = {
    SX_FIELD("uncompressed_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_a_lzop_end = { UINT32_C(0x6004003F), "lzop_end", sx_a_lzop_end_fields, SX_COUNT(sx_a_lzop_end_fields), SX_BE };
static const xx_data_struct_field_desc sx_a_lzop_extra_size_fields[] = {
    SX_FIELD("extra_field_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_a_lzop_extra_size = { UINT32_C(0x60040040), "lzop_extra_size", sx_a_lzop_extra_size_fields, SX_COUNT(sx_a_lzop_extra_size_fields), SX_BE };
static bool sx_a_lzop(sx_context *c)
{
    static const uint8_t magic[9]={0x89,'L','Z','O',0,13,10,26,10};
    int64_t at=0;
    while(at<c->size){
        uint8_t h[17],namelen;uint16_t version;uint32_t flags;const sx_layout *l;
        if(!sx_read(c,at,h,13)||xx_rt_memcmp(h,magic,9))return false;
        version=xx_data_get_u16(h,13,9,true);bool longheader=version>=0x0940;
        int64_t flag_at=at+(longheader?17:14);
        if(version<0x0900||!sx_u32(c,flag_at,true,&flags)||(flags&~0xfff03fffU))return false;
        bool filter=(flags&0x800)!=0;
        l=longheader?(filter?&sx_a_lzop_header_11:&sx_a_lzop_header_10):(filter?&sx_a_lzop_header_01:&sx_a_lzop_header_00);
        int64_t header_size=(longheader?34:27)+(filter?4:0);
        if(!sx_add(c,l,at,header_size)||!sx_read(c,at+header_size-1,&namelen,1))return false;
        at+=header_size;
        if(!sx_a_raw_advance(c,&at,namelen)||!sx_add(c,&sx_a_checksum_be,at,4))return false;at+=4;
        if(flags&0x40){
            uint32_t extra;if(!sx_u32(c,at,true,&extra)||!sx_add(c,&sx_a_lzop_extra_size,at,4))return false;at+=4;
            if(!sx_a_raw_advance(c,&at,extra)||!sx_add(c,&sx_a_checksum_be,at,4))return false;at+=4;
        }
        for(;;){
            uint32_t plain,packed;
            if(!sx_u32(c,at,true,&plain))return false;
            if(!plain){if(!sx_add(c,&sx_a_lzop_end,at,4))return false;at+=4;break;}
            if(!sx_u32(c,at+4,true,&packed)||!packed||packed>plain||!sx_add(c,&sx_a_lzop_block_sizes,at,8))return false;at+=8;
            unsigned sums=((flags&1)!=0)+((flags&0x100)!=0)+(packed<plain?((flags&2)!=0)+((flags&0x200)!=0):0);
            for(unsigned i=0;i<sums;i++){if(!sx_add(c,&sx_a_checksum_be,at,4))return false;at+=4;}
            if(!sx_a_raw_advance(c,&at,packed))return false;
        }
    }
    return true;
}
bool sx_lzop_build(sx_context*c)
{
    return sx_a_lzop(c);
}
