/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Compaq LZH data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_compaqlzh_header_fields[] = {
 SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("name","char[13]",7,13,SX_NONE),
 SX_FIELD("attributes","uint8",20,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("dos_date","uint16",23,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",25,4,SX_SIZE),
};
const sx_layout sxat_compaqlzh_header = {UINT32_C(0x6064001c),"compaqlzh_header",sxat_compaqlzh_header_fields,SX_COUNT(sxat_compaqlzh_header_fields),SX_LE};
bool sx_compaqlzh_build(sx_context*c)
{
 return sxat_add(c,&sxat_compaqlzh_header,0);
}
