/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZZ data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_zz_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint64",8,8,SX_NONE),
};
const sx_layout sxacl_zz_header = {UINT32_C(0x60500004),"zz_header",sxacl_zz_header_fields,SX_COUNT(sxacl_zz_header_fields),SX_LE};
bool sx_zz_build(sx_context*c)
{
 return sxacl_add(c,&sxacl_zz_header,0);
}
