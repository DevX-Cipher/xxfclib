/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * settlersft data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_settlers_header_fields[]={
 SX_FIELD("file_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("slots","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxga_settlers_header={UINT32_C(0x603B000F),"settlers_header",sxga_settlers_header_fields,SX_COUNT(sxga_settlers_header_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_settlers(sxga_view*v)
{uint64_t end=v->c->size,n;return GA_ROW(settlers_header,0,end)&&sxga_word(v,4,4,false,&n,end)&&sxga_table(v,&sxga_settlers_slot,8,n,end);}
bool sx_settlersft_build(sxga_view*v)
{
 return sxga_settlers(v);
}
#undef GA_ROW
