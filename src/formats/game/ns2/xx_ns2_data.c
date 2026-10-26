/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ns2 data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_ns2_size_fields[]={
 SX_FIELD("data_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxga_ns2_size={UINT32_C(0x603B002C),"ns2_size",sxga_ns2_size_fields,SX_COUNT(sxga_ns2_size_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ns2_quote_fields[]={
 SX_FIELD("quote","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxga_ns2_quote={UINT32_C(0x603B002D),"ns2_quote",sxga_ns2_quote_fields,SX_COUNT(sxga_ns2_quote_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ns2_end_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxga_ns2_end={UINT32_C(0x603B002E),"ns2_end",sxga_ns2_end_fields,SX_COUNT(sxga_ns2_end_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_ns2(sxga_view*v)
{uint64_t end=v->c->size,base,at=4,b;if(!GA_ROW(ns2_header,0,end)||!sxga_word(v,0,4,false,&base,end)||base>end)return false;while(at<base){if(!sxga_word(v,at,1,false,&b,base))return false;if(b=='e')return GA_ROW(ns2_end,at,base);if(b!='"'||!GA_ROW(ns2_quote,at,base))return false;uint64_t start=++at;while(at<base){if(!sxga_word(v,at,1,false,&b,base))return false;if(b=='"')break;at++;if(++v->work>4000000)return false;}if(!sxga_named(v,start,at-start,base,false)||!GA_ROW(ns2_quote,at,base)||!GA_ROW(ns2_size,at+1,base))return false;at+=5;}return false;}
bool sx_ns2_build(sxga_view*v)
{
 return sxga_ns2(v);
}
#undef GA_ROW
