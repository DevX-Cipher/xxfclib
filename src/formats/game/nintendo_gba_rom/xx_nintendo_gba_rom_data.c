/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_gba_rom data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_gba_header_fields[]={
 SX_FIELD("entry_instruction","uint32",0,4,SX_FLAGS),
 SX_FIELD("logo","bytes",4,156,SX_SIGNATURE),
 SX_FIELD("title","char[12]",160,12,SX_STRING),
 SX_FIELD("game_code","char[4]",172,4,SX_ID),
 SX_FIELD("maker_code","char[2]",176,2,SX_ID),
 SX_FIELD("fixed","uint8",178,1,SX_SIGNATURE),
 SX_FIELD("unit_code","uint8",179,1,SX_ID),
 SX_FIELD("device_type","uint8",180,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",181,7,SX_RESERVED),
 SX_FIELD("version","uint8",188,1,SX_ID),
 SX_FIELD("complement","uint8",189,1,SX_SIGNATURE),
 SX_FIELD("reserved_tail","uint16",190,2,SX_RESERVED),
};
const sx_layout sxgp_gba_header={UINT32_C(0x60360009),"gba_header",sxgp_gba_header_fields,SX_COUNT(sxgp_gba_header_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_gba(sxgp_view*v){return SG_ROW(gba_header,0,(uint64_t)v->c->size);}
bool sx_nintendo_gba_rom_build(sxgp_view*v)
{
 return sxgp_gba(v);
}
#undef SG_ROW
