/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NewWave LZWD packed files data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_lzwd_header_fields[] = {
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("signature","uint32",4,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",8,2,SX_NONE),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
};
const sx_layout sxafr_lzwd_header = {UINT32_C(0x60540003),"lzwd_header",sxafr_lzwd_header_fields,SX_COUNT(sxafr_lzwd_header_fields),SX_LE};
bool sx_lzwd_build(sx_context*c)
{
 return sxafr_add(c,&sxafr_lzwd_header,0);
}
