/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DCS data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_dcs_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxan_dcs_header = {UINT32_C(0x6077003e),"dcs_header",sxan_dcs_header_fields,SX_COUNT(sxan_dcs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_dcs_block_fields[] = {
 SX_FIELD("stored_size","uint32",0,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxan_dcs_block = {UINT32_C(0x6077003f),"dcs_block",sxan_dcs_block_fields,SX_COUNT(sxan_dcs_block_fields),SX_LE};
static bool sxan_dcs(sx_context*c){uint64_t n,p=12,z;if(!sxan_add(c,&sxan_dcs_header,0)||!sxan_word(c,4,4,false,&n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,p,4,false,&z)||z<4||!sxan_add(c,&sxan_dcs_block,p))return false;p+=8;if(!sxan_span(c,p,z-4))return true;p+=z-4;}return true;}
bool sx_dcs_build(sx_context*c)
{
bool ok=false;
ok=sxan_dcs(c);
(void)ok;return c->count&&sxan_finish(c);
}
