/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ppd data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_name_length32_fields[]={
 SX_FIELD("name_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxga_name_length32={UINT32_C(0x603B0004),"name_length32",sxga_name_length32_fields,SX_COUNT(sxga_name_length32_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_ppd(sxga_view*v)
{uint64_t end=v->c->size,at=4,n,z;if(!GA_ROW(count32,0,end)||!sxga_word(v,0,4,false,&n,end)||n>4096)return false;for(uint64_t i=0;i<n;i++){if(!GA_ROW(name_length32,at,end)||!sxga_word(v,at,4,false,&z,end))return false;at+=4;if(!sxga_named(v,at,z,end,false))return false;at+=z;if(!GA_ROW(ppd_entry,at,end))return false;at+=12;}return true;}
bool sx_ppd_build(sxga_view*v)
{
 return sxga_ppd(v);
}
#undef GA_ROW
