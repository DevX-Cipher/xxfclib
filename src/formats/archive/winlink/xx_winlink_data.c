/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WinLink data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_winlink_header_fields[] = {
 SX_FIELD("format_constant","uint16",0,2,SX_NONE),
 SX_FIELD("reserved","uint8",2,1,SX_NONE),
 SX_FIELD("dos_time","uint16",3,2,SX_NONE),
 SX_FIELD("dos_date","uint16",5,2,SX_NONE),
 SX_FIELD("name","char[13]",7,13,SX_NONE),
 SX_FIELD("sentinel","uint32",20,4,SX_SIGNATURE),
};
const sx_layout sxas_winlink_header = {UINT32_C(0x60430027),"winlink_header",sxas_winlink_header_fields,SX_COUNT(sxas_winlink_header_fields),SX_LE};
bool sx_winlink_build(sx_context*c)
{
 return sxas_add(c,&sxas_winlink_header,0);
}
