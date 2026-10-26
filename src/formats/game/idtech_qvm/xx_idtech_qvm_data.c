/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * idtech_qvm data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_qvm_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("instruction_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("code_offset","int32",8,4,SX_OFFSET),
 SX_FIELD("code_size","int32",12,4,SX_SIZE),
 SX_FIELD("data_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("data_size","int32",20,4,SX_SIZE),
 SX_FIELD("literals_size","int32",24,4,SX_SIZE),
 SX_FIELD("bss_size","int32",28,4,SX_SIZE),
};
const sx_layout sxgm_qvm_header = {UINT32_C(0x60270059),"qvm_header",sxgm_qvm_header_fields,SX_COUNT(sxgm_qvm_header_fields),SX_LE};
bool sx_idtech_qvm_build(sx_context*c)
{
 return sxgm_add(c,&sxgm_qvm_header,0);
}
