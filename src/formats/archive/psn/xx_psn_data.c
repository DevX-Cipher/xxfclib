/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PSN data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_psn_header_fields[] = {
 SX_FIELD("banner","char[53]",0,53,SX_SIGNATURE),
 SX_FIELD("version","char[4]",53,4,SX_NONE),
 SX_FIELD("uncompressed_size","ascii_hex[8]",57,8,SX_SIZE),
};
const sx_layout sxat_psn_header = {UINT32_C(0x6064001e),"psn_header",sxat_psn_header_fields,SX_COUNT(sxat_psn_header_fields),SX_LE};
bool sx_psn_build(sx_context*c)
{
 bool ok=false;uint64_t size;ok=sxat_hex(c,57,8,&size)&&sxat_add(c,&sxat_psn_header,0)&&sxat_dcl(c,65,c->size>=65?(uint64_t)c->size-65:0);return ok;
}
