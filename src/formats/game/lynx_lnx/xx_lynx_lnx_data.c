/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lynx_lnx data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_lynx_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("bank0_page_size","uint16",4,2,SX_SIZE),
 SX_FIELD("bank1_page_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_ID),
 SX_FIELD("cartridge_name","char[32]",10,32,SX_STRING),
 SX_FIELD("manufacturer","char[16]",42,16,SX_STRING),
 SX_FIELD("rotation","uint8",58,1,SX_ID),
 SX_FIELD("audin","uint8",59,1,SX_FLAGS),
 SX_FIELD("eeprom","uint8",60,1,SX_FLAGS),
 SX_FIELD("reserved","uint8[3]",61,3,SX_RESERVED),
};
const sx_layout sxgm_lynx_header = {UINT32_C(0x60270003),"lynx_header",sxgm_lynx_header_fields,SX_COUNT(sxgm_lynx_header_fields),SX_LE};
bool sx_lynx_lnx_build(sx_context*c)
{
 return sxgm_add(c,&sxgm_lynx_header,0);
}
