/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ea_exa data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_ea_block_le_fields[]={
 SX_FIELD("block_id","char[4]",0,4,SX_ID),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxau_ea_block_le={UINT32_C(0x602C0065),"ea_block_le",sxau_ea_block_le_fields,SX_COUNT(sxau_ea_block_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ea_block_be_fields[]={
 SX_FIELD("block_id","char[4]",0,4,SX_ID),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxau_ea_block_be={UINT32_C(0x602C006A),"ea_block_be",sxau_ea_block_be_fields,SX_COUNT(sxau_ea_block_be_fields),SX_BE};
static bool sxau_ea_check(sxau_view*v,bool be)
{size_t at=0;unsigned i=0;while(at<v->n){if(++i>4096||!sxau_need(v,at,8,v->n))return false;uint32_t z=sxau_u32(v->p+at+4,be);if(z<8||!sxau_need(v,at,z,v->n))return false;at+=z;}return true;}
static bool sxau_ea(sxau_view*v)
{bool be=false;if(!sxau_ea_check(v,false)){be=true;if(!sxau_ea_check(v,true))return false;}size_t at=0;while(at<v->n){if(!sxau_row(v,be?&sxau_ea_block_be:&sxau_ea_block_le,at,v->n))return false;at+=sxau_u32(v->p+at+4,be);}return true;}
bool sx_ea_exa_build(sxau_view*v)
{
 return sxau_ea(v);
}
