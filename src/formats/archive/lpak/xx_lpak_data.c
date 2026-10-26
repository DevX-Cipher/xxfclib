/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LPAK data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_lpak_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxal_lpak_header = {UINT32_C(0x6020004d),"lpak_header",sxal_lpak_header_fields,SX_COUNT(sxal_lpak_header_fields),SX_BE};
bool sx_lpak_build(sx_context*c)
{
 return sxal_add(c,&sxal_lpak_header,0);
}
