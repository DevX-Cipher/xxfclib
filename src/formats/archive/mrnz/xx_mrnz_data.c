/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MRNZ data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_mrnz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("checkword","uint8[4]",4,4,SX_SIGNATURE),
 SX_FIELD("xor_prefix_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxas_mrnz_header = {UINT32_C(0x60430025),"mrnz_header",sxas_mrnz_header_fields,SX_COUNT(sxas_mrnz_header_fields),SX_LE};
bool sx_mrnz_build(sx_context*c)
{
 return sxas_add(c,&sxas_mrnz_header,0);
}
