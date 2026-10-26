/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CPIO data structures, moved out of the archive schema family. */
#include "../../xx_format_schema_archive.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_a_cpio_newc_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("ino", "ascii_hex[8]", 6, 8, SX_ID),
    SX_FIELD("mode", "ascii_hex[8]", 14, 8, SX_FLAGS),
    SX_FIELD("uid", "ascii_hex[8]", 22, 8, SX_ID),
    SX_FIELD("gid", "ascii_hex[8]", 30, 8, SX_ID),
    SX_FIELD("nlink", "ascii_hex[8]", 38, 8, SX_COUNT_PROP),
    SX_FIELD("mtime", "ascii_hex[8]", 46, 8, SX_TIME),
    SX_FIELD("filesize", "ascii_hex[8]", 54, 8, SX_SIZE),
    SX_FIELD("devmajor", "ascii_hex[8]", 62, 8, SX_ID),
    SX_FIELD("devminor", "ascii_hex[8]", 70, 8, SX_ID),
    SX_FIELD("rdevmajor", "ascii_hex[8]", 78, 8, SX_ID),
    SX_FIELD("rdevminor", "ascii_hex[8]", 86, 8, SX_ID),
    SX_FIELD("namesize", "ascii_hex[8]", 94, 8, SX_SIZE),
    SX_FIELD("check", "ascii_hex[8]", 102, 8, SX_SIGNATURE),
};
const sx_layout sx_a_cpio_newc_header = { UINT32_C(0x60040001), "cpio_newc_header", sx_a_cpio_newc_header_fields, SX_COUNT(sx_a_cpio_newc_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cpio_odc_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("dev", "ascii_octal[6]", 6, 6, SX_ID),
    SX_FIELD("ino", "ascii_octal[6]", 12, 6, SX_ID),
    SX_FIELD("mode", "ascii_octal[6]", 18, 6, SX_FLAGS),
    SX_FIELD("uid", "ascii_octal[6]", 24, 6, SX_ID),
    SX_FIELD("gid", "ascii_octal[6]", 30, 6, SX_ID),
    SX_FIELD("nlink", "ascii_octal[6]", 36, 6, SX_COUNT_PROP),
    SX_FIELD("rdev", "ascii_octal[6]", 42, 6, SX_ID),
    SX_FIELD("mtime", "ascii_octal[11]", 48, 11, SX_TIME),
    SX_FIELD("namesize", "ascii_octal[6]", 59, 6, SX_SIZE),
    SX_FIELD("filesize", "ascii_octal[11]", 65, 11, SX_SIZE),
};
const sx_layout sx_a_cpio_odc_header = { UINT32_C(0x60040002), "cpio_odc_header", sx_a_cpio_odc_header_fields, SX_COUNT(sx_a_cpio_odc_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cpio_afio_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("dev", "ascii_hex[8]", 6, 8, SX_ID),
    SX_FIELD("ino", "ascii_hex[16]", 14, 16, SX_ID),
    SX_FIELD("mode_marker", "char[1]", 30, 1, SX_SIGNATURE),
    SX_FIELD("mode", "ascii_octal[6]", 31, 6, SX_FLAGS),
    SX_FIELD("uid", "ascii_hex[8]", 37, 8, SX_ID),
    SX_FIELD("gid", "ascii_hex[8]", 45, 8, SX_ID),
    SX_FIELD("nlink", "ascii_hex[8]", 53, 8, SX_COUNT_PROP),
    SX_FIELD("rdev", "ascii_hex[8]", 61, 8, SX_ID),
    SX_FIELD("mtime", "ascii_hex[16]", 69, 16, SX_TIME),
    SX_FIELD("name_marker", "char[1]", 85, 1, SX_SIGNATURE),
    SX_FIELD("namesize", "ascii_hex[4]", 86, 4, SX_SIZE),
    SX_FIELD("flags", "ascii_hex[4]", 90, 4, SX_FLAGS),
    SX_FIELD("extended_header_size", "ascii_hex[4]", 94, 4, SX_SIZE),
    SX_FIELD("size_marker", "char[1]", 98, 1, SX_SIGNATURE),
    SX_FIELD("filesize", "ascii_hex[16]", 99, 16, SX_SIZE),
    SX_FIELD("header_end", "char[1]", 115, 1, SX_SIGNATURE),
};
const sx_layout sx_a_cpio_afio_header = { UINT32_C(0x60040003), "cpio_afio_header", sx_a_cpio_afio_header_fields, SX_COUNT(sx_a_cpio_afio_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cpio_solaris_tl_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("payload_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sx_a_cpio_solaris_tl = { UINT32_C(0x60040006), "cpio_solaris_tl", sx_a_cpio_solaris_tl_fields, SX_COUNT(sx_a_cpio_solaris_tl_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cpio_solaris_tg_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("block_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("block_size", "uint32", 8, 4, SX_SIZE),
};
const sx_layout sx_a_cpio_solaris_tg = { UINT32_C(0x60040007), "cpio_solaris_tg", sx_a_cpio_solaris_tg_fields, SX_COUNT(sx_a_cpio_solaris_tg_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cpio_solaris_block_fields[] = {
    SX_FIELD("uncompressed_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("compressed_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("offset", "uint32", 8, 4, SX_OFFSET),
};
const sx_layout sx_a_cpio_solaris_block = { UINT32_C(0x60040008), "cpio_solaris_block", sx_a_cpio_solaris_block_fields, SX_COUNT(sx_a_cpio_solaris_block_fields), SX_LE };
static bool sx_a_ascii_number(const uint8_t *s,size_t n,unsigned base,uint64_t *out)
{
    uint64_t v=0;
    for(size_t i=0;i<n;i++){
        unsigned d=s[i]>='0'&&s[i]<='9'?s[i]-'0':s[i]>='a'&&s[i]<='f'?s[i]-'a'+10:s[i]>='A'&&s[i]<='F'?s[i]-'A'+10:UINT_MAX;
        if(d>=base||v>(UINT64_MAX-d)/base)return false;
        v=v*base+d;
    }
    *out=v;return true;
}
static bool sx_a_cpio_solaris(sx_context *c)
{
    int64_t at=0;
    while(at<c->size){
        uint8_t h[12];uint32_t payload,blocks;
        if(!sx_read(c,at,h,8)||xx_rt_memcmp(h,"\x19\x9eTL",4))return false;
        payload=xx_data_get_u32(h,8,4,false);
        if(!sx_add(c,&sx_a_cpio_solaris_tl,at,8))return false;
        at+=8;if(!sx_a_raw_advance(c,&at,504))return false;
        int64_t tg=at;
        if(payload<12||payload>(uint64_t)(c->size-at)||!sx_read(c,at,h,12)||xx_rt_memcmp(h,"\x19\x9eTG",4))return false;
        blocks=xx_data_get_u32(h,12,4,false);
        if(blocks>(payload-12U)/12U||!sx_add(c,&sx_a_cpio_solaris_tg,at,12)||!sx_table(c,&sx_a_cpio_solaris_block,at+12,12,blocks))return false;
        for(uint32_t i=0;i<blocks;i++){
            uint32_t packed,offset;
            if(!sx_u32(c,tg+12+(int64_t)i*12+4,false,&packed)||!sx_u32(c,tg+12+(int64_t)i*12+8,false,&offset)||offset>payload||packed>payload-offset||!sx_raw(c,tg+offset,packed))return false;
        }
        at=tg+payload;
        uint64_t padding=(512U-(uint64_t)at%512U)%512U;
        if(!sx_a_raw_advance(c,&at,padding))return false;
        if(at<c->size){uint8_t b;if(!sx_read(c,at,&b,1))return false;if(!b)return sx_raw(c,at,c->size-at);}
    }
    return true;
}
static bool sx_a_cpio(sx_context *c)
{
    int64_t at=0;uint8_t h[116];
    if(!sx_read(c,0,h,6))return false;
    if(!xx_rt_memcmp(h,"\x19\x9eTL",4))return sx_a_cpio_solaris(c);
    while(at<c->size){
        const sx_layout *l;int64_t hs;uint64_t namesize,size,extra=0;unsigned alignment=1;
        if(!sx_read(c,at,h,6))return false;
        if(!xx_rt_memcmp(h,"070701",6)||!xx_rt_memcmp(h,"070702",6)){
            l=&sx_a_cpio_newc_header;hs=110;alignment=4;
            if(!sx_read(c,at,h,(size_t)hs)||!sx_a_ascii_number(h+94,8,16,&namesize)||!sx_a_ascii_number(h+54,8,16,&size))return false;
        }else if(!xx_rt_memcmp(h,"070707",6)){
            l=&sx_a_cpio_odc_header;hs=76;
            if(!sx_read(c,at,h,(size_t)hs)||!sx_a_ascii_number(h+59,6,8,&namesize)||!sx_a_ascii_number(h+65,11,8,&size))return false;
        }else if(!xx_rt_memcmp(h,"070727",6)){
            l=&sx_a_cpio_afio_header;hs=116;
            if(!sx_read(c,at,h,(size_t)hs)||h[30]!='m'||h[85]!='n'||h[98]!='s'||h[115]!=':'||!sx_a_ascii_number(h+86,4,16,&namesize)||!sx_a_ascii_number(h+94,4,16,&extra)||!sx_a_ascii_number(h+99,16,16,&size))return false;
        }else{
            bool be=h[0]==0x71&&h[1]==0xc7;
            if(!be&&!(h[0]==0xc7&&h[1]==0x71))return false;
            l=be?&sx_a_cpio_binary_be_header:&sx_a_cpio_binary_le_header;hs=26;alignment=2;
            if(!sx_read(c,at,h,(size_t)hs))return false;
            namesize=xx_data_get_u16(h,26,20,be);
            size=((uint64_t)xx_data_get_u16(h,26,22,be)<<16)|xx_data_get_u16(h,26,24,be);
        }
        if(!namesize||namesize>65536||!sx_add(c,l,at,hs))return false;
        at+=hs;int64_t name_at=at;uint8_t last;
        if(!sx_a_raw_advance(c,&at,namesize)||!sx_read(c,at-1,&last,1)||last!=0)return false;
        if(!sx_a_raw_advance(c,&at,(alignment-(uint64_t)at%alignment)%alignment))return false;
        bool trailer=false;
        if(namesize==11){uint8_t name[11];if(!sx_read(c,name_at,name,11))return false;trailer=!xx_rt_memcmp(name,"TRAILER!!!",11);}
        if(!sx_a_raw_advance(c,&at,extra)||!sx_a_raw_advance(c,&at,size)||!sx_a_raw_advance(c,&at,(alignment-(uint64_t)at%alignment)%alignment))return false;
        if(trailer)return sx_raw(c,at,c->size-at);
    }
    return false;
}
bool sx_cpio_build(sx_context*c)
{
    return sx_a_cpio(c);
}
