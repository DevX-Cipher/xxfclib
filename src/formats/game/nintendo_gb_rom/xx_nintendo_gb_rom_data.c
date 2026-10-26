/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_gb_rom data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_gb_common_fields[]={
 SX_FIELD("entry_instructions","bytes",0,4,SX_NONE),
 SX_FIELD("logo","bytes",4,48,SX_SIGNATURE),
};
const sx_layout sxgp_gb_common={UINT32_C(0x60360005),"gb_common",sxgp_gb_common_fields,SX_COUNT(sxgp_gb_common_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gb_title_fields[]={
 SX_FIELD("title","char[16]",0,16,SX_STRING),
};
const sx_layout sxgp_gb_title={UINT32_C(0x60360006),"gb_title",sxgp_gb_title_fields,SX_COUNT(sxgp_gb_title_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cgb_title_fields[]={
 SX_FIELD("title","char[11]",0,11,SX_STRING),
 SX_FIELD("manufacturer_or_title_tail","char[4]",11,4,SX_STRING),
 SX_FIELD("cgb_flag","uint8",15,1,SX_FLAGS),
};
const sx_layout sxgp_cgb_title={UINT32_C(0x60360007),"cgb_title",sxgp_cgb_title_fields,SX_COUNT(sxgp_cgb_title_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gb_cartridge_fields[]={
 SX_FIELD("new_licensee","char[2]",0,2,SX_ID),
 SX_FIELD("sgb_flag","uint8",2,1,SX_FLAGS),
 SX_FIELD("cartridge_type","uint8",3,1,SX_ID),
 SX_FIELD("rom_size_code","uint8",4,1,SX_ID),
 SX_FIELD("ram_size_code","uint8",5,1,SX_ID),
 SX_FIELD("destination_code","uint8",6,1,SX_ID),
 SX_FIELD("old_licensee","uint8",7,1,SX_ID),
 SX_FIELD("version","uint8",8,1,SX_ID),
 SX_FIELD("header_checksum","uint8",9,1,SX_CHECKSUM),
 SX_FIELD("global_checksum","uint16be",10,2,SX_CHECKSUM),
};
const sx_layout sxgp_gb_cartridge={UINT32_C(0x60360008),"gb_cartridge",sxgp_gb_cartridge_fields,SX_COUNT(sxgp_gb_cartridge_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_gb(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,flag;if(!SG_ROW(gb_common,0x100,end)||!sxgp_word(v,0x143,1,false,&flag,end))return false;return sxgp_row(v,flag&128?&sxgp_cgb_title:&sxgp_gb_title,0x134,end)&&SG_ROW(gb_cartridge,0x144,end);}
bool sx_nintendo_gb_rom_build(sxgp_view*v)
{
 return sxgp_gb(v);
}
#undef SG_ROW
