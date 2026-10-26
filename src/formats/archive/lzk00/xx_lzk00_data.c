/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZK00 data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_lzk_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("reserved","uint8[4]",5,4,SX_NONE),
};
const sx_layout sxat_lzk_header = {UINT32_C(0x60640019),"lzk_header",sxat_lzk_header_fields,SX_COUNT(sxat_lzk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_lzk_literal_fields[] = {
 SX_FIELD("literal_code","uint8",0,1,SX_NONE),
};
const sx_layout sxat_lzk_literal = {UINT32_C(0x6064001a),"lzk_literal",sxat_lzk_literal_fields,SX_COUNT(sxat_lzk_literal_fields),SX_LE};
static const xx_data_struct_field_desc sxat_lzk_match_fields[] = {
 SX_FIELD("match_code","uint16",0,2,SX_NONE),
};
const sx_layout sxat_lzk_match = {UINT32_C(0x6064001b),"lzk_match",sxat_lzk_match_fields,SX_COUNT(sxat_lzk_match_fields),SX_LE};
static bool sxat_lzk(sx_context*c){uint64_t p=9;if(!sxat_add(c,&sxat_lzk_header,0))return false;while(p<(uint64_t)c->size){uint64_t b;if(!sxat_word(c,p,1,false,&b))return false;if(b&1){if(!sxat_add(c,&sxat_lzk_match,p))return false;p+=2;}else{uint64_t z=b>>1;if(!z||!sxat_add(c,&sxat_lzk_literal,p++))return false;if(!sxat_span(c,p,z))return true;p+=z;}}return true;}
bool sx_lzk00_build(sx_context*c)
{
 return sxat_lzk(c);
}
