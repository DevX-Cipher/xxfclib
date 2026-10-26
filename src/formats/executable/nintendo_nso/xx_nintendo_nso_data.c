/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NINTENDO_NSO data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_nso_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("text_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("text_address","uint32",20,4,SX_ADDRESS),
 SX_FIELD("text_size","uint32",24,4,SX_SIZE),
 SX_FIELD("module_name_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("ro_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("ro_address","uint32",36,4,SX_ADDRESS),
 SX_FIELD("ro_size","uint32",40,4,SX_SIZE),
 SX_FIELD("module_name_size","uint32",44,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("data_address","uint32",52,4,SX_ADDRESS),
 SX_FIELD("data_size","uint32",56,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",60,4,SX_SIZE),
 SX_FIELD("build_id","uint8[32]",64,32,SX_ID),
 SX_FIELD("text_compressed_size","uint32",96,4,SX_SIZE),
 SX_FIELD("ro_compressed_size","uint32",100,4,SX_SIZE),
 SX_FIELD("data_compressed_size","uint32",104,4,SX_SIZE),
 SX_FIELD("reserved108","uint8[28]",108,28,SX_RESERVED),
 SX_FIELD("embedded_offset","uint32",136,4,SX_OFFSET),
 SX_FIELD("embedded_size","uint32",140,4,SX_SIZE),
 SX_FIELD("dynstr_offset","uint32",144,4,SX_OFFSET),
 SX_FIELD("dynstr_size","uint32",148,4,SX_SIZE),
 SX_FIELD("dynsym_offset","uint32",152,4,SX_OFFSET),
 SX_FIELD("dynsym_size","uint32",156,4,SX_SIZE),
 SX_FIELD("text_sha256","uint8[32]",160,32,SX_CHECKSUM),
 SX_FIELD("ro_sha256","uint8[32]",192,32,SX_CHECKSUM),
 SX_FIELD("data_sha256","uint8[32]",224,32,SX_CHECKSUM),
};
const sx_layout sxexm_nso_header = {UINT32_C(0x602b001d),"nso_header",sxexm_nso_header_fields,SX_COUNT(sxexm_nso_header_fields),SX_LE};
bool sx_nintendo_nso_build(sx_context*c)
{
bool ok=false;
ok=sxexm_add(c,&sxexm_nso_header,0);
return ok&&sxexm_finish(c);
}
