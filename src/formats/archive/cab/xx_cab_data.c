/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Microsoft Cabinet (CAB) data structures, moved out of the archive schema family. */
#include "../../xx_format_schema_archive.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_a_cab_reserve_sizes_fields[] = {
    SX_FIELD("cbCFHeader", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("cbCFFolder", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("cbCFData", "uint8", 3, 1, SX_SIZE),
};
const sx_layout sx_a_cab_reserve_sizes = { UINT32_C(0x6004000A), "cab_reserve_sizes", sx_a_cab_reserve_sizes_fields, SX_COUNT(sx_a_cab_reserve_sizes_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cab_file_fields[] = {
    SX_FIELD("cbFile", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("uoffFolderStart", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("iFolder", "uint16", 8, 2, SX_ID),
    SX_FIELD("date", "uint16", 10, 2, SX_TIME),
    SX_FIELD("time", "uint16", 12, 2, SX_TIME),
    SX_FIELD("attribs", "uint16", 14, 2, SX_FLAGS),
};
const sx_layout sx_a_cab_file = { UINT32_C(0x6004000C), "cab_file", sx_a_cab_file_fields, SX_COUNT(sx_a_cab_file_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_cab_data_fields[] = {
    SX_FIELD("csum", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("cbData", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("cbUncomp", "uint16", 6, 2, SX_SIZE),
};
const sx_layout sx_a_cab_data = { UINT32_C(0x6004000D), "cab_data", sx_a_cab_data_fields, SX_COUNT(sx_a_cab_data_fields), SX_LE };
static bool sx_a_cstring(sx_context *c,int64_t *at,int64_t end)
{
    int64_t start=*at;uint8_t b;
    if(start<0||end>c->size)return false;
    while(*at<end){if(!sx_read(c,*at,&b,1))return false;(*at)++;if(!b)return sx_raw(c,start,*at-start);}
    return false;
}
static bool sx_a_cab(sx_context *c)
{
    uint8_t h[36],r[4]={0};uint32_t end,files;uint16_t flags,folders,count;int64_t at=36,folder_at;
    if(!sx_read(c,0,h,36)||xx_rt_memcmp(h,"MSCF",4))return false;
    end=xx_data_get_u32(h,36,8,false);files=xx_data_get_u32(h,36,16,false);
    folders=xx_data_get_u16(h,36,26,false);count=xx_data_get_u16(h,36,28,false);flags=xx_data_get_u16(h,36,30,false);
    if(end<36||end>(uint64_t)c->size||files>end||(flags&~7U)||!sx_add(c,&sx_a_cab_header,0,36))return false;
    if(flags&4){if(!sx_read(c,at,r,4)||!sx_add(c,&sx_a_cab_reserve_sizes,at,4))return false;at+=4;if(!sx_a_raw_advance(c,&at,xx_data_get_u16(r,4,0,false)))return false;}
    if(flags&1)if(!sx_a_cstring(c,&at,end)||!sx_a_cstring(c,&at,end))return false;
    if(flags&2)if(!sx_a_cstring(c,&at,end)||!sx_a_cstring(c,&at,end))return false;
    folder_at=at;
    for(uint16_t i=0;i<folders;i++){
        if(at>end||8U+r[2]>(uint64_t)(end-at)||!sx_add(c,&sx_a_cab_folder,at,8))return false;
        at+=8;if(!sx_a_raw_advance(c,&at,r[2]))return false;
    }
    at=files;
    for(uint16_t i=0;i<count;i++){
        if(at>end||end-at<16||!sx_add(c,&sx_a_cab_file,at,16))return false;
        at+=16;if(!sx_a_cstring(c,&at,end))return false;
    }
    for(uint16_t i=0;i<folders;i++){
        uint32_t data;uint16_t blocks;
        int64_t fo=folder_at+(int64_t)i*(8+r[2]);
        if(!sx_u32(c,fo,false,&data)||!sx_u16(c,fo+4,false,&blocks))return false;
        at=data;
        for(uint16_t j=0;j<blocks;j++){
            uint16_t packed;
            if(at>end||8U+r[3]>(uint64_t)(end-at)||!sx_u16(c,at+4,false,&packed)||!sx_add(c,&sx_a_cab_data,at,8))return false;
            at+=8;if(!sx_a_raw_advance(c,&at,r[3])||packed>(uint64_t)(end-at)||!sx_a_raw_advance(c,&at,packed))return false;
        }
    }
    return sx_raw(c,end,c->size-end);
}
bool sx_cab_build(sx_context*c)
{
    return sx_a_cab(c);
}
