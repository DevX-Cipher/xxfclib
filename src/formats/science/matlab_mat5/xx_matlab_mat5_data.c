/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * matlab_mat5 data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_mat5_header_le_fields[] = {
    SX_FIELD("description", "char[116]", 0, 116, SX_STRING),
    SX_FIELD("subsystem_data_offset", "uint64", 116, 8, SX_OFFSET),
    SX_FIELD("version", "uint16", 124, 2, SX_ID),
    SX_FIELD("endian_indicator", "char[2]", 126, 2, SX_ID),
};
const sx_layout sxm_mat5_header_le = {UINT32_C(0x6006003B), "mat5_header_le", sxm_mat5_header_le_fields, SX_COUNT(sxm_mat5_header_le_fields), SX_LE};
static const xx_data_struct_field_desc sxm_mat5_tag_le_fields[] = {
    SX_FIELD("data_type", "uint32", 0, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sxm_mat5_tag_le = {UINT32_C(0x6006003C), "mat5_tag_le", sxm_mat5_tag_le_fields, SX_COUNT(sxm_mat5_tag_le_fields), SX_LE};
static const xx_data_struct_field_desc sxm_mat5_header_be_fields[] = {
    SX_FIELD("description", "char[116]", 0, 116, SX_STRING),
    SX_FIELD("subsystem_data_offset", "uint64", 116, 8, SX_OFFSET),
    SX_FIELD("version", "uint16", 124, 2, SX_ID),
    SX_FIELD("endian_indicator", "char[2]", 126, 2, SX_ID),
};
const sx_layout sxm_mat5_header_be = {UINT32_C(0x6006003F), "mat5_header_be", sxm_mat5_header_be_fields, SX_COUNT(sxm_mat5_header_be_fields), SX_BE};
static const xx_data_struct_field_desc sxm_mat5_tag_be_fields[] = {
    SX_FIELD("data_type", "uint32", 0, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sxm_mat5_tag_be = {UINT32_C(0x60060040), "mat5_tag_be", sxm_mat5_tag_be_fields, SX_COUNT(sxm_mat5_tag_be_fields), SX_BE};
static bool sxm_mat5_tags(sx_context *c,uint64_t at,uint64_t end,bool be,unsigned depth)
{
    if(depth>8)return false;
    while(at<end){uint32_t type,n;uint64_t data,next;
        if(end-at<8||!sx_u32(c,(int64_t)at,be,&type))return false;
        /* miCOMPRESSED has no 8-byte padding and is outside native reader scope. */
        if((type&UINT32_C(0xffff))==15)return false;
        if(type>>16){n=type>>16;if(n>4||!sx_add(c,be?&sxm_mat5_small_tag_be:&sxm_mat5_small_tag_le,(int64_t)at,8))return false;next=at+8;}
        else{if(!sx_u32(c,(int64_t)at+4,be,&n))return false;data=at+8;next=data+(((uint64_t)n+7)&~UINT64_C(7));if(next>end||!sx_add(c,be?&sxm_mat5_tag_be:&sxm_mat5_tag_le,(int64_t)at,8))return false;
            if(type==14){if(!sxm_mat5_tags(c,data,data+n,be,depth+1)||!sxm_raw(c,data+n,next-data-n))return false;}
            else if(!sxm_raw(c,data,next-data))return false;
        }
        at=next;
    }
    return at==end;
}
bool sx_matlab_mat5_build(sx_context*c,uint8_t*h,size_t n)
{
 bool be;if(n<128||xx_rt_memcmp(h,"MATLAB 5.0 MAT-file",19))return false;be=!xx_rt_memcmp(h+126,"MI",2);if(!be&&xx_rt_memcmp(h+126,"IM",2))return false;return sx_add(c,be?&sxm_mat5_header_be:&sxm_mat5_header_le,0,128)&&sxm_mat5_tags(c,128,(uint64_t)c->size,be,0);
}
