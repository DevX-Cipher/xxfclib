/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * msx_rom data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_msx_rom_header_fields[]={
 SX_FIELD("signature","bytes",0,2,SX_SIGNATURE),
 SX_FIELD("init_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("runtime_address","uint16",4,2,SX_ADDRESS),
 SX_FIELD("device_address","uint16",6,2,SX_ADDRESS),
 SX_FIELD("text_address","uint16",8,2,SX_ADDRESS),
 SX_FIELD("reserved","bytes",10,6,SX_RESERVED),
};
const sx_layout sxgp_msx_rom_header={UINT32_C(0x60360001),"msx_rom_header",sxgp_msx_rom_header_fields,SX_COUNT(sxgp_msx_rom_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_msx_binary_header_fields[]={
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("start_address","uint16",1,2,SX_ADDRESS),
 SX_FIELD("end_address","uint16",3,2,SX_ADDRESS),
 SX_FIELD("init_address","uint16",5,2,SX_ADDRESS),
};
const sx_layout sxgp_msx_binary_header={UINT32_C(0x60360002),"msx_binary_header",sxgp_msx_binary_header_fields,SX_COUNT(sxgp_msx_binary_header_fields),SX_LE};
static bool sxgp_msx(sxgp_view*v){uint64_t magic,end=(uint64_t)v->c->size;return sxgp_word(v,0,1,false,&magic,end)&&sxgp_row(v,magic==254?&sxgp_msx_binary_header:&sxgp_msx_rom_header,0,end);}
bool sx_msx_rom_build(sxgp_view*v)
{
 return sxgp_msx(v);
}
