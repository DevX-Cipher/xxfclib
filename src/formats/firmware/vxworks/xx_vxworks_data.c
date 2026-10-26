/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VxWorks images data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_vxworks_symbol_le_fields[] = {
    SX_FIELD("name_pointer","uint32",0,4,SX_POINTER),
    SX_FIELD("value","uint32",4,4,SX_ADDRESS),
    SX_FIELD("type","uint32",8,4,SX_FLAGS),
    SX_FIELD("group","uint32",12,4,SX_NONE),
};
const sx_layout sxbrs_vxworks_symbol_le = {UINT32_C(0x603e0017),"vxworks_symbol_le",sxbrs_vxworks_symbol_le_fields,SX_COUNT(sxbrs_vxworks_symbol_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_vxworks_symbol_be_fields[] = {
    SX_FIELD("name_pointer","uint32",0,4,SX_POINTER),
    SX_FIELD("value","uint32",4,4,SX_ADDRESS),
    SX_FIELD("type","uint32",8,4,SX_FLAGS),
    SX_FIELD("group","uint32",12,4,SX_NONE),
};
const sx_layout sxbrs_vxworks_symbol_be = {UINT32_C(0x603e0018),"vxworks_symbol_be",sxbrs_vxworks_symbol_be_fields,SX_COUNT(sxbrs_vxworks_symbol_be_fields),SX_BE};
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_vxworks(sx_context*c){bool be=N(9,1)==0;uint64_t count=0;while(count<(uint64_t)c->size/16&&count<4000000){int64_t at=(int64_t)(count*16);uint64_t type=sxbrs_num(c,at+8,4,be);if(!sxbrs_num(c,at,4,be)||!sxbrs_num(c,at+4,4,be)||(type!=0x500&&type!=0x700&&type!=0x900))break;count++;if(xx_pd_is_stopped(c->pd))return false;}if(count<250)return false;int64_t at=0;return sxbrs_take(c,be?&sxbrs_vxworks_symbol_be:&sxbrs_vxworks_symbol_le,&at,c->size,count);}
bool sx_vxworks_build(sx_context*c)
{
 return sxbrs_vxworks(c);
}
#undef N
