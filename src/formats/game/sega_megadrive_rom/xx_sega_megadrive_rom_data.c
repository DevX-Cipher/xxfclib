/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sega_megadrive_rom data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_megadrive_boot_fields[]={
 SX_FIELD("stack_pointer","uint32",0,4,SX_ADDRESS),
 SX_FIELD("reset_address","uint32",4,4,SX_ADDRESS),
};
const sx_layout sxgp_megadrive_boot={UINT32_C(0x6036000A),"megadrive_boot",sxgp_megadrive_boot_fields,SX_COUNT(sxgp_megadrive_boot_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_megadrive_vector_fields[]={
 SX_FIELD("handler_address","uint32",0,4,SX_ADDRESS),
};
const sx_layout sxgp_megadrive_vector={UINT32_C(0x6036000B),"megadrive_vector",sxgp_megadrive_vector_fields,SX_COUNT(sxgp_megadrive_vector_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_megadrive_header_fields[]={
 SX_FIELD("system","char[16]",0,16,SX_ID),
 SX_FIELD("copyright","char[16]",16,16,SX_STRING),
 SX_FIELD("domestic_name","char[48]",32,48,SX_STRING),
 SX_FIELD("overseas_name","char[48]",80,48,SX_STRING),
 SX_FIELD("product_code","char[14]",128,14,SX_ID),
 SX_FIELD("checksum","uint16",142,2,SX_CHECKSUM),
 SX_FIELD("io_support","char[16]",144,16,SX_FLAGS),
 SX_FIELD("rom_start","uint32",160,4,SX_ADDRESS),
 SX_FIELD("rom_end","uint32",164,4,SX_ADDRESS),
 SX_FIELD("ram_start","uint32",168,4,SX_ADDRESS),
 SX_FIELD("ram_end","uint32",172,4,SX_ADDRESS),
 SX_FIELD("sram_marker","bytes",176,2,SX_ID),
 SX_FIELD("sram_type","uint16",178,2,SX_FLAGS),
 SX_FIELD("sram_start","uint32",180,4,SX_ADDRESS),
 SX_FIELD("sram_end","uint32",184,4,SX_ADDRESS),
 SX_FIELD("modem","char[12]",188,12,SX_STRING),
 SX_FIELD("notes","char[40]",200,40,SX_STRING),
 SX_FIELD("regions","char[16]",240,16,SX_FLAGS),
};
const sx_layout sxgp_megadrive_header={UINT32_C(0x6036000C),"megadrive_header",sxgp_megadrive_header_fields,SX_COUNT(sxgp_megadrive_header_fields),SX_BE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_megadrive(sxgp_view*v){uint64_t end=(uint64_t)v->c->size;return SG_ROW(megadrive_boot,0,end)&&sxgp_table(v,&sxgp_megadrive_vector,8,62,end)&&SG_ROW(megadrive_header,256,end);}
bool sx_sega_megadrive_rom_build(sxgp_view*v)
{
 return sxgp_megadrive(v);
}
#undef SG_ROW
