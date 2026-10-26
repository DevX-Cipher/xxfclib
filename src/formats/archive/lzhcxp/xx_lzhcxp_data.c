/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * "LZ" single-file containers (XLZHCXP) data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_lzhcxp_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
};
const sx_layout sxafr_lzhcxp_header = {UINT32_C(0x60540001),"lzhcxp_header",sxafr_lzhcxp_header_fields,SX_COUNT(sxafr_lzhcxp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_lzhcxp_block_size_fields[] = {
 SX_FIELD("compressed_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxafr_lzhcxp_block_size = {UINT32_C(0x60540002),"lzhcxp_block_size",sxafr_lzhcxp_block_size_fields,SX_COUNT(sxafr_lzhcxp_block_size_fields),SX_LE};
static bool sxafr_lzhcxp(sx_context*c){uint64_t p=2,z;if(!sxafr_add(c,&sxafr_lzhcxp_header,0))return false;while(p<(uint64_t)c->size){if(!sxafr_word(c,p,1,false,&z)||!sxafr_add(c,&sxafr_lzhcxp_block_size,p++))return false;if(!z)return true;if(!sxafr_span(c,p,z))return false;p+=z;}return true;}
bool sx_lzhcxp_build(sx_context*c)
{
 return sxafr_lzhcxp(c);
}
