/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * silmarilsft data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_silmarils_offset_widths_fields[]={
 SX_FIELD("width0","uint8",0,1,SX_NONE),
 SX_FIELD("width1","uint8",1,1,SX_NONE),
 SX_FIELD("width2","uint8",2,1,SX_NONE),
 SX_FIELD("width3","uint8",3,1,SX_NONE),
 SX_FIELD("width4","uint8",4,1,SX_NONE),
 SX_FIELD("width5","uint8",5,1,SX_NONE),
 SX_FIELD("width6","uint8",6,1,SX_NONE),
 SX_FIELD("width7","uint8",7,1,SX_NONE),
};
const sx_layout sxga_silmarils_offset_widths={UINT32_C(0x603B0026),"silmarils_offset_widths",sxga_silmarils_offset_widths_fields,SX_COUNT(sxga_silmarils_offset_widths_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_silmarils(sxga_view*v)
{uint64_t end=v->c->size,flag,method;if(!sxga_word(v,4,2,false,&flag,end))return false;bool be=flag!=1;if(!sxga_row(v,be?&sxga_silmarils_header_be:&sxga_silmarils_header_le,0,end)||!sxga_word(v,be?0:3,1,false,&method,end))return false;return method!=0xa1||GA_ROW(silmarils_offset_widths,6,end);}
bool sx_silmarilsft_build(sxga_view*v)
{
 return sxga_silmarils(v);
}
#undef GA_ROW
