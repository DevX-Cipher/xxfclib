/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * atari_7800_a78 data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_a78_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("signature","bytes",1,16,SX_SIGNATURE),
 SX_FIELD("title","char[32]",17,32,SX_STRING),
 SX_FIELD("rom_size","uint32",49,4,SX_SIZE),
 SX_FIELD("cartridge_type","uint16",53,2,SX_FLAGS),
 SX_FIELD("controller1","uint8",55,1,SX_ID),
 SX_FIELD("controller2","uint8",56,1,SX_ID),
 SX_FIELD("television","uint8",57,1,SX_FLAGS),
 SX_FIELD("save_device","uint8",58,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",59,4,SX_RESERVED),
 SX_FIELD("passthrough","uint8",63,1,SX_FLAGS),
 SX_FIELD("reserved_tail","bytes",64,36,SX_RESERVED),
 SX_FIELD("trailer","bytes",100,28,SX_SIGNATURE),
};
const sx_layout sxgp_a78_header={UINT32_C(0x6036000E),"a78_header",sxgp_a78_header_fields,SX_COUNT(sxgp_a78_header_fields),SX_BE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_a78(sxgp_view*v){return SG_ROW(a78_header,0,(uint64_t)v->c->size);}
bool sx_atari_7800_a78_build(sxgp_view*v)
{
 return sxgp_a78(v);
}
#undef SG_ROW
