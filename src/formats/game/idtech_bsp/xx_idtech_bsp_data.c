/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * idtech_bsp data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_idtech_bsp_lump_fields[] = {
 SX_FIELD("file_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("file_size","int32",4,4,SX_SIZE),
};
const sx_layout sxgm_idtech_bsp_lump = {UINT32_C(0x60270046),"idtech_bsp_lump",sxgm_idtech_bsp_lump_fields,SX_COUNT(sxgm_idtech_bsp_lump_fields),SX_LE};
bool sx_idtech_bsp_build(sx_context*c,uint8_t*b)
{
 return sxgm_read(c,0,b,8)&&sxgm_add(c,&sxgm_idtech_bsp_header,0)&&sxgm_table(c,&sxgm_idtech_bsp_lump,8,sxgm32(b+4,false)==38?19:17);
}
