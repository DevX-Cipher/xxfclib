/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HZL data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_hzl_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("separator","char[1]",8,1,SX_SIGNATURE),
 SX_FIELD("extension","char[3]",9,3,SX_NONE),
};
const sx_layout sxacl_hzl_header = {UINT32_C(0x60500032),"hzl_header",sxacl_hzl_header_fields,SX_COUNT(sxacl_hzl_header_fields),SX_LE};
bool sx_hzl_build(sx_context*c)
{
 return sxacl_add(c,&sxacl_hzl_header,0);
}
