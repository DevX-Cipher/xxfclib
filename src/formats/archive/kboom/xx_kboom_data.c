/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * KBOOM data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_kboom_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",8,2,SX_NONE),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
};
const sx_layout sxacl_kboom_header = {UINT32_C(0x60500033),"kboom_header",sxacl_kboom_header_fields,SX_COUNT(sxacl_kboom_header_fields),SX_LE};
bool sx_kboom_build(sx_context*c)
{
 return sxacl_add(c,&sxacl_kboom_header,0);
}
