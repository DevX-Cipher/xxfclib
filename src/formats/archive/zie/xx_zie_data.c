/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZIE data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_zie_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("obfuscated_key","uint8[16]",4,16,SX_NONE),
 SX_FIELD("name","char[13]",20,13,SX_NONE),
 SX_FIELD("unused","uint8[3]",33,3,SX_NONE),
 SX_FIELD("reserved","uint8[244]",36,244,SX_NONE),
};
const sx_layout sxafr_zie_header = {UINT32_C(0x6054002a),"zie_header",sxafr_zie_header_fields,SX_COUNT(sxafr_zie_header_fields),SX_LE};
bool sx_zie_build(sx_context*c)
{
 return sxafr_add(c,&sxafr_zie_header,0);
}
