/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Tivoli Filepack Block (.PKT) containers data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_tivoli_header_fields[] = {
 SX_FIELD("header_line","char[79]",0,79,SX_NONE),
};
const sx_layout sxafr_tivoli_header = {UINT32_C(0x60540022),"tivoli_header",sxafr_tivoli_header_fields,SX_COUNT(sxafr_tivoli_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_tivoli_block_fields[] = {
 SX_FIELD("flags_and_size","uint16",0,2,SX_FLAGS),
};
const sx_layout sxafr_tivoli_block = {UINT32_C(0x60540023),"tivoli_block",sxafr_tivoli_block_fields,SX_COUNT(sxafr_tivoli_block_fields),SX_BE};
static const xx_data_struct_field_desc sxafr_tivoli_digest_fields[] = {
 SX_FIELD("running_md5_prefix","uint8[8]",0,8,SX_CHECKSUM),
};
const sx_layout sxafr_tivoli_digest = {UINT32_C(0x60540024),"tivoli_digest",sxafr_tivoli_digest_fields,SX_COUNT(sxafr_tivoli_digest_fields),SX_LE};
static bool sxafr_tivoli(sx_context*c){uint64_t p=79;if(!sxafr_add(c,&sxafr_tivoli_header,0))return false;while(p<(uint64_t)c->size){uint64_t h;if(!sxafr_word(c,p,2,true,&h)||!sxafr_add(c,&sxafr_tivoli_block,p))return false;p+=2;if(!h)return true;uint64_t z=h&0x7fff;if(z<8||!sxafr_span(c,p,z)||!sxafr_add(c,&sxafr_tivoli_digest,p+z-8))return false;p+=z;}return true;}
bool sx_tivoli_build(sx_context*c)
{
 return sxafr_tivoli(c);
}
