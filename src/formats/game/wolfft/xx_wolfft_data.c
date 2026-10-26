/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * wolfft data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_length16_fields[]={
 SX_FIELD("data_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxga_length16={UINT32_C(0x603B0008),"length16",sxga_length16_fields,SX_COUNT(sxga_length16_fields),SX_LE};
static const xx_data_struct_field_desc sxga_wolf_header_fields[]={
 SX_FIELD("chunks","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("first_sprite","uint16",2,2,SX_ID),
 SX_FIELD("first_sound","uint16",4,2,SX_ID),
};
const sx_layout sxga_wolf_header={UINT32_C(0x603B0011),"wolf_header",sxga_wolf_header_fields,SX_COUNT(sxga_wolf_header_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_wolf(sxga_view*v)
{uint64_t end=v->c->size,n;return GA_ROW(wolf_header,0,end)&&sxga_word(v,0,2,false,&n,end)&&sxga_table(v,&sxga_offset32,6,n,end)&&sxga_table(v,&sxga_length16,6+n*4,n,end);}
bool sx_wolfft_build(sxga_view*v)
{
 return sxga_wolf(v);
}
#undef GA_ROW
