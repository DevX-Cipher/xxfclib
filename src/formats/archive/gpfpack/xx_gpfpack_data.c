/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GPF pack data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_gpfpack_header_fields[] = {
 SX_FIELD("constant","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("signature","char[8]",4,8,SX_SIGNATURE),
 SX_FIELD("version","uint16",12,2,SX_NONE),
 SX_FIELD("name","char[14]",14,14,SX_NONE),
};
const sx_layout sxat_gpfpack_header = {UINT32_C(0x60640012),"gpfpack_header",sxat_gpfpack_header_fields,SX_COUNT(sxat_gpfpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_gpfpack_block_fields[] = {
 SX_FIELD("bit_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxat_gpfpack_block = {UINT32_C(0x60640013),"gpfpack_block",sxat_gpfpack_block_fields,SX_COUNT(sxat_gpfpack_block_fields),SX_LE};
static bool sxat_gpf(sx_context*c){uint64_t p=28;if(!sxat_add(c,&sxat_gpfpack_header,0))return false;while(p<(uint64_t)c->size){uint64_t bits;if(!sxat_word(c,p,4,false,&bits)||!bits||bits>INT32_MAX||!sxat_add(c,&sxat_gpfpack_block,p))return false;p+=4;uint64_t z=(bits+7)/8;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
bool sx_gpfpack_build(sx_context*c)
{
 return sxat_gpf(c);
}
