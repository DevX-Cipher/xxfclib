/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Kirill Kolpakov's PSG2 chiptune (.PSG2) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_psg2_magic_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
};
const sx_layout sxmr_psg2_magic={UINT32_C(0x607D0053),"psg2_magic",sxmr_psg2_magic_fields,SX_COUNT(sxmr_psg2_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg2_value_fields[]={
 SX_FIELD("register_value","uint8",0,1,SX_NONE),
};
const sx_layout sxmr_psg2_value={UINT32_C(0x607D0056),"psg2_value",sxmr_psg2_value_fields,SX_COUNT(sxmr_psg2_value_fields),SX_LE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_psg2(sxmr_view*v)
{uint64_t end=v->c->size,p=4,n;uint8_t b[2];if(!sxmr_eq(v,0,"PSG2",4,end)||!MR_ROW(psg2_magic,0,end))return false;
 while(p<end){if(!sxmr_read(v,p,b,2,end)||!MR_ROW(psg2_map,p,end))return false;p+=2;if(b[0]==255&&b[1]==255)return true;
  if(!sxmr_u(v,p,1,&n,end)||!MR_ROW(psg2_reuse,p,end))return false;p++;if(!n)return true;unsigned bits=0;for(unsigned j=0;j<2;j++)for(unsigned k=0;k<8;k++)bits+=(b[j]>>k)&1U;
  if(!sxmr_table(v,&sxmr_psg2_value,p,n*bits,end))return false;p+=n*bits;
 }return true;}
bool sx_kolpakov_psg2_build(sxmr_view*v)
{
 return sxmr_psg2(v);
}
#undef MR_ROW
