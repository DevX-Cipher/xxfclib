/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Atari Atr data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_atr_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("paragraph_count_low","uint16",2,2,SX_NONE),
    SX_FIELD("sector_size","uint16",4,2,SX_SIZE),
    SX_FIELD("paragraph_count_high","uint16",6,2,SX_NONE),
    SX_FIELD("unused_header_bytes","byte[7]",8,7,SX_NONE),
    SX_FIELD("write_protected","uint8",15,1,SX_FLAGS),
};
const sx_layout sxse_atr_header = {0x602f0050U,"atr_header",sxse_atr_header_fields,SX_COUNT(sxse_atr_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
bool sx_atari_atr_build(sx_context*c)
{
 return SXSE_ADD(c,atr_header,0,16);
}
#undef SXSE_ADD
