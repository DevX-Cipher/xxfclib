/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCHROM data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fw_intel_flash_descriptor_map_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("flmap0","uint32",4,4,SX_FLAGS),
    SX_FIELD("flmap1","uint32",8,4,SX_FLAGS),
    SX_FIELD("flmap2","uint32",12,4,SX_FLAGS),
};
const sx_layout sx_fw_intel_flash_descriptor_map = {0x601e0014U,"intel_flash_descriptor_map",sx_fw_intel_flash_descriptor_map_fields,SX_COUNT(sx_fw_intel_flash_descriptor_map_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_intel_flash_component_fields[] = {
    SX_FIELD("flcomp","uint32",0,4,SX_FLAGS),
    SX_FIELD("flill","uint32",4,4,SX_FLAGS),
    SX_FIELD("flpb","uint32",8,4,SX_NONE),
};
const sx_layout sx_fw_intel_flash_component = {0x601e0015U,"intel_flash_component",sx_fw_intel_flash_component_fields,SX_COUNT(sx_fw_intel_flash_component_fields),SX_LE};
static bool sx_fw_pch(sx_context *c)
{
    uint32_t map1,comp;if(!sx_u32(c,0x18,false,&map1)||!sx_u32(c,0x30,false,&comp))return false;
    uint32_t master=(map1&255)*16,n=((comp>>17)&7)?16:7;
    if(master<0x40||master>0xe00)return false;if(n>(master-0x40)/4)n=(master-0x40)/4;
    return n>=5&&sx_add(c,&sx_fw_intel_flash_descriptor_map,0x10,16)&&sx_add(c,&sx_fw_intel_flash_component,0x30,12)&&sx_table(c,&sx_fw_intel_flash_region,0x40,4,n);
}
bool sx_pchrom_build(sx_context*c)
{
    bool ok=false;
    ok=sx_fw_pch(c);
    return ok&&sx_fw_finish(c);
}
