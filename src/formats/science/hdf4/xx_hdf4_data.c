/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * hdf4 data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_hdf4_dd_block_fields[] = {
    SX_FIELD("descriptor_count", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("next_block_offset", "uint32", 2, 4, SX_OFFSET),
};
const sx_layout sxm_hdf4_dd_block = {UINT32_C(0x60060042), "hdf4_dd_block", sxm_hdf4_dd_block_fields, SX_COUNT(sxm_hdf4_dd_block_fields), SX_BE};
static const xx_data_struct_field_desc sxm_hdf4_descriptor_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("reference", "uint16", 2, 2, SX_ID),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("data_length", "uint32", 8, 4, SX_SIZE),
};
const sx_layout sxm_hdf4_descriptor = {UINT32_C(0x60060043), "hdf4_descriptor", sxm_hdf4_descriptor_fields, SX_COUNT(sxm_hdf4_descriptor_fields), SX_BE};
static const xx_data_struct_field_desc sxm_hdf4_first_block_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("descriptor_count", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("next_block_offset", "uint32", 6, 4, SX_OFFSET),
};
const sx_layout sxm_hdf4_first_block = {UINT32_C(0x60060044), "hdf4_first_block", sxm_hdf4_first_block_fields, SX_COUNT(sxm_hdf4_first_block_fields), SX_BE};
static bool sxm_hdf4(sx_context *c,const uint8_t *h)
{
    uint32_t at=4,seen[1024];unsigned blocks=0;
    if(xx_rt_memcmp(h,"\x0e\x03\x13\x01",4))return false;
    while(at){uint16_t count;uint32_t next;
        if(blocks==1024)return false;
        for(unsigned i=0;i<blocks;i++)if(seen[i]==at)return false;seen[blocks++]=at;
        if(!sx_u16(c,at,true,&count)||!sx_u32(c,(int64_t)at+2,true,&next)||!count||count>4096)return false;
        if(at==4){if(!sx_add(c,&sxm_hdf4_first_block,0,10))return false;}else if(!sx_add(c,&sxm_hdf4_dd_block,at,6))return false;
        if(!sx_table(c,&sxm_hdf4_descriptor,(int64_t)at+6,12,count))return false;
        for(unsigned i=0;i<count;i++){uint8_t e[12];uint32_t off,n;if(!sx_read(c,(int64_t)at+6+(int64_t)i*12,e,12))return false;
            if(xx_data_get_u16(e,12,0,true)==1)continue;off=xx_data_get_u32(e,12,4,true);n=xx_data_get_u32(e,12,8,true);if(!sxm_raw(c,off,n))return false;}
        at=next;
    }
    return true;
}
bool sx_hdf4_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=10&&sxm_hdf4(c,h);
}
