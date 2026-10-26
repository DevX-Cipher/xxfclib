/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MS DOS BACKUP data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_dos_backup_header_fields[] = {
 SX_FIELD("last_fragment","uint8",0,1,SX_FLAGS),
 SX_FIELD("sequence","uint16",1,2,SX_ID),
 SX_FIELD("zero","uint16",3,2,SX_RESERVED),
 SX_FIELD("original_path","char[78]",5,78,SX_STRING),
 SX_FIELD("path_size","uint8",83,1,SX_SIZE),
 SX_FIELD("reserved","uint8[44]",84,44,SX_RESERVED),
};
const sx_layout sxal_dos_backup_header = {UINT32_C(0x60200048),"dos_backup_header",sxal_dos_backup_header_fields,SX_COUNT(sxal_dos_backup_header_fields),SX_LE};
bool sx_ms_dos_backup_build(sx_context*c)
{
 return sxal_add(c,&sxal_dos_backup_header,0);
}
