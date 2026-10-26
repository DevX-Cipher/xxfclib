/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * stunts data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_stunts_escape_fields[]={
 SX_FIELD("escape","uint8",0,1,SX_ID),
};
const sx_layout sxga_stunts_escape={UINT32_C(0x603B0021),"stunts_escape",sxga_stunts_escape_fields,SX_COUNT(sxga_stunts_escape_fields),SX_LE};
static const xx_data_struct_field_desc sxga_stunts_level_fields[]={
 SX_FIELD("symbols","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxga_stunts_level={UINT32_C(0x603B0022),"stunts_level",sxga_stunts_level_fields,SX_COUNT(sxga_stunts_level_fields),SX_LE};
static const xx_data_struct_field_desc sxga_stunts_symbol_fields[]={
 SX_FIELD("symbol","uint8",0,1,SX_ID),
};
const sx_layout sxga_stunts_symbol={UINT32_C(0x603B0023),"stunts_symbol",sxga_stunts_symbol_fields,SX_COUNT(sxga_stunts_symbol_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_stunts(sxga_view*v)
{uint64_t end=v->c->size,b,at=0,n;if(!sxga_word(v,0,1,false,&b,end))return false;if(b&128){if(!GA_ROW(stunts_header,0,end))return false;at=4;}if(!GA_ROW(stunts_pass,at,end)||!sxga_word(v,at,1,false,&b,end))return false;at+=4;if(b==1){if(!GA_ROW(stunts_rle,at,end)||!sxga_word(v,at+4,1,false,&n,end))return false;return sxga_table(v,&sxga_stunts_escape,at+5,n&127,end);}if(b==2){if(!GA_ROW(stunts_vle,at,end)||!sxga_word(v,at,1,false,&n,end))return false;at++;n&=127;uint64_t total=0;for(uint64_t i=0;i<n;i++){uint64_t z;if(!GA_ROW(stunts_level,at+i,end)||!sxga_word(v,at+i,1,false,&z,end))return false;total+=z;}return sxga_table(v,&sxga_stunts_symbol,at+n,total,end);}return false;}
bool sx_stunts_build(sxga_view*v)
{
 return sxga_stunts(v);
}
#undef GA_ROW
