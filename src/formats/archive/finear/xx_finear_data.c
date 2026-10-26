/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FINEAR data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_finear_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("marker","uint8[3]",6,3,SX_NONE),
 SX_FIELD("crc16_word","uint32",9,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",13,4,SX_SIZE),
};
const sx_layout sxat_finear_header = {UINT32_C(0x60640010),"finear_header",sxat_finear_header_fields,SX_COUNT(sxat_finear_header_fields),SX_LE};
bool sx_finear_build(sx_context*c)
{
 return sxat_add(c,&sxat_finear_header,0);
}
