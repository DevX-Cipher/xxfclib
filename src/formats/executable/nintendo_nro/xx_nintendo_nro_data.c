/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NINTENDO_NRO data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_nro_start_fields[] = {
 SX_FIELD("version_or_instruction","uint32",0,4,SX_NONE),
 SX_FIELD("module_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("version_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sxexm_nro_start = {UINT32_C(0x602b001a),"nro_start",sxexm_nro_start_fields,SX_COUNT(sxexm_nro_start_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_nro_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("image_size","uint32",8,4,SX_SIZE),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("text_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("text_size","uint32",20,4,SX_SIZE),
 SX_FIELD("ro_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("ro_size","uint32",28,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",36,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",40,4,SX_SIZE),
 SX_FIELD("additional_header_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("build_id","uint8[32]",48,32,SX_ID),
 SX_FIELD("dso_handle_offset","uint32",80,4,SX_OFFSET),
 SX_FIELD("reserved100","uint32",84,4,SX_RESERVED),
 SX_FIELD("embedded_offset","uint32",88,4,SX_OFFSET),
 SX_FIELD("embedded_size","uint32",92,4,SX_SIZE),
 SX_FIELD("dynstr_offset","uint32",96,4,SX_OFFSET),
 SX_FIELD("dynstr_size","uint32",100,4,SX_SIZE),
 SX_FIELD("dynsym_offset","uint32",104,4,SX_OFFSET),
 SX_FIELD("dynsym_size","uint32",108,4,SX_SIZE),
};
const sx_layout sxexm_nro_header = {UINT32_C(0x602b001b),"nro_header",sxexm_nro_header_fields,SX_COUNT(sxexm_nro_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_nro_asset_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("icon_offset","uint64",8,8,SX_OFFSET),
 SX_FIELD("icon_size","uint64",16,8,SX_SIZE),
 SX_FIELD("nacp_offset","uint64",24,8,SX_OFFSET),
 SX_FIELD("nacp_size","uint64",32,8,SX_SIZE),
 SX_FIELD("romfs_offset","uint64",40,8,SX_OFFSET),
 SX_FIELD("romfs_size","uint64",48,8,SX_SIZE),
};
const sx_layout sxexm_nro_asset_header = {UINT32_C(0x602b001c),"nro_asset_header",sxexm_nro_asset_header_fields,SX_COUNT(sxexm_nro_asset_header_fields),SX_LE};
static bool sxexm_nro(sx_context*c){uint8_t h[128],asset[4];if(!sxexm_read(c,0,h,128)||!sxexm_add(c,&sxexm_nro_start,0)||!sxexm_add(c,&sxexm_nro_header,16))return false;uint64_t p=sxexm32(h+24,false);if(sxexm_span(c,p,56)&&sxexm_read(c,p,asset,4)&&!xx_rt_memcmp(asset,"ASET",4)&&!sxexm_add(c,&sxexm_nro_asset_header,p))return false;return true;}
bool sx_nintendo_nro_build(sx_context*c)
{
bool ok=false;
ok=sxexm_nro(c);
return ok&&sxexm_finish(c);
}
