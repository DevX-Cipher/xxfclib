/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TRCPAK archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_trcpak_header_fields[] = {
 SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("padding","uint8",7,1,SX_RESERVED),
 SX_FIELD("version","float32",8,4,SX_NONE),
 SX_FIELD("entry_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[12]",16,12,SX_RESERVED),
};
const sx_layout sxag_trcpak_header = {UINT32_C(0x60250019),"trcpak_header",sxag_trcpak_header_fields,SX_COUNT(sxag_trcpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_trcpak_entry_fields[] = {
 SX_FIELD("name","char[260]",0,260,SX_STRING),
 SX_FIELD("data_size","int32",260,4,SX_SIZE),
 SX_FIELD("data_offset","int32",264,4,SX_OFFSET),
};
const sx_layout sxag_trcpak_entry = {UINT32_C(0x6025001a),"trcpak_entry",sxag_trcpak_entry_fields,SX_COUNT(sxag_trcpak_entry_fields),SX_LE};
bool sx_trcpak_build(sx_context*c)
{
 return sxag_fixed(c,&sxag_trcpak_header,&sxag_trcpak_entry,28,12,4,false,28,0);
}
