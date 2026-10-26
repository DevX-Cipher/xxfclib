/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_n64_rom data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_n64_header_fields[]={
 SX_FIELD("pi_boot_config","uint32",0,4,SX_FLAGS),
 SX_FIELD("clock_rate","uint32",4,4,SX_NONE),
 SX_FIELD("entry_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("release","uint32",12,4,SX_ID),
 SX_FIELD("crc1","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("crc2","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("reserved","bytes",24,8,SX_RESERVED),
 SX_FIELD("name","char[20]",32,20,SX_STRING),
 SX_FIELD("reserved2","bytes",52,4,SX_RESERVED),
 SX_FIELD("manufacturer","uint32",56,4,SX_ID),
 SX_FIELD("cartridge_id","char[2]",60,2,SX_ID),
 SX_FIELD("country","uint8",62,1,SX_ID),
 SX_FIELD("version","uint8",63,1,SX_ID),
};
const sx_layout sxgp_n64_header={UINT32_C(0x6036000D),"n64_header",sxgp_n64_header_fields,SX_COUNT(sxgp_n64_header_fields),SX_BE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_n64(sxgp_view*v){return SG_ROW(n64_header,0,(uint64_t)v->c->size);}
bool sx_nintendo_n64_rom_build(sxgp_view*v)
{
 return sxgp_n64(v);
}
#undef SG_ROW
