/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SLS data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_sls_header_fields[] = {
 SX_FIELD("signature","uint8[9]",0,9,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","int32",9,4,SX_SIZE),
};
const sx_layout sxat_sls_header = {UINT32_C(0x60640007),"sls_header",sxat_sls_header_fields,SX_COUNT(sxat_sls_header_fields),SX_LE};
bool sx_sls_build(sx_context*c)
{
 return sxat_add(c,&sxat_sls_header,0);
}
