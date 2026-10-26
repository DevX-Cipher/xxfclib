/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nes_rom data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_ines_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("prg_rom_units","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("chr_rom_units","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("flags6","uint8",6,1,SX_FLAGS),
 SX_FIELD("flags7","uint8",7,1,SX_FLAGS),
 SX_FIELD("prg_ram_units","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("tv_system","uint8",9,1,SX_FLAGS),
 SX_FIELD("flags10","uint8",10,1,SX_FLAGS),
 SX_FIELD("unused11","uint8",11,1,SX_NONE),
 SX_FIELD("reserved","uint8[4]",12,4,SX_RESERVED),
};
const sx_layout sxgm_ines_header = {UINT32_C(0x60270001),"ines_header",sxgm_ines_header_fields,SX_COUNT(sxgm_ines_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_nes2_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("prg_rom_units_low","uint8",4,1,SX_NONE),
 SX_FIELD("chr_rom_units_low","uint8",5,1,SX_NONE),
 SX_FIELD("flags6","uint8",6,1,SX_FLAGS),
 SX_FIELD("flags7","uint8",7,1,SX_FLAGS),
 SX_FIELD("mapper_submapper","uint8",8,1,SX_FLAGS),
 SX_FIELD("rom_size_high","uint8",9,1,SX_NONE),
 SX_FIELD("prg_ram_shifts","uint8",10,1,SX_NONE),
 SX_FIELD("chr_ram_shifts","uint8",11,1,SX_NONE),
 SX_FIELD("timing","uint8",12,1,SX_ID),
 SX_FIELD("console_type","uint8",13,1,SX_ID),
 SX_FIELD("misc_rom_count","uint8",14,1,SX_NONE),
 SX_FIELD("expansion_device","uint8",15,1,SX_ID),
};
const sx_layout sxgm_nes2_header = {UINT32_C(0x60270002),"nes2_header",sxgm_nes2_header_fields,SX_COUNT(sxgm_nes2_header_fields),SX_LE};
bool sx_nes_rom_build(sx_context*c,uint8_t*b)
{
 return sxgm_read(c,0,b,16)&&sxgm_add(c,(b[7]&12)==8?&sxgm_nes2_header:&sxgm_ines_header,0);
}
