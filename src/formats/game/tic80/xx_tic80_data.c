/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tic80 data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_tic_chunk_fields[]={
 SX_FIELD("bank_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("data_size","uint16",1,2,SX_SIZE),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
};
const sx_layout sxgp_tic_chunk={UINT32_C(0x60360004),"tic_chunk",sxgp_tic_chunk_fields,SX_COUNT(sxgp_tic_chunk_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_tic(sxgp_view*v){uint64_t p=0,end=(uint64_t)v->c->size,z;while(p<end){if(!SG_ROW(tic_chunk,p,end)||!sxgp_word(v,p+1,2,false,&z,end)||!sxgp_span(v,p+4,z,end))return false;p+=4+z;}return p==end;}
bool sx_tic80_build(sxgp_view*v)
{
 return sxgp_tic(v);
}
#undef SG_ROW
