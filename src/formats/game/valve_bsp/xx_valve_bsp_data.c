/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * valve_bsp data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_valve_bsp_lump_fields[] = {
 SX_FIELD("file_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("file_size","int32",4,4,SX_SIZE),
 SX_FIELD("version","int32",8,4,SX_ID),
 SX_FIELD("fourcc","char[4]",12,4,SX_ID),
};
const sx_layout sxgm_valve_bsp_lump = {UINT32_C(0x60270047),"valve_bsp_lump",sxgm_valve_bsp_lump_fields,SX_COUNT(sxgm_valve_bsp_lump_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_valve_bsp_revision_fields[] = {
 SX_FIELD("revision","int32",0,4,SX_NONE),
};
const sx_layout sxgm_valve_bsp_revision = {UINT32_C(0x60270048),"valve_bsp_revision",sxgm_valve_bsp_revision_fields,SX_COUNT(sxgm_valve_bsp_revision_fields),SX_LE};
bool sx_valve_bsp_build(sx_context*c)
{
 return sxgm_add(c,&sxgm_idtech_bsp_header,0)&&sxgm_table(c,&sxgm_valve_bsp_lump,8,64)&&sxgm_add(c,&sxgm_valve_bsp_revision,1032);
}
