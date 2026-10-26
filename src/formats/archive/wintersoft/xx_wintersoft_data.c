/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Wintersoft "**++" archives data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_wintersoft_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("method_tag","char[4]",4,4,SX_NONE),
};
const sx_layout sxafr_wintersoft_header = {UINT32_C(0x60540025),"wintersoft_header",sxafr_wintersoft_header_fields,SX_COUNT(sxafr_wintersoft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_wintersoft_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxafr_wintersoft_member = {UINT32_C(0x60540026),"wintersoft_member",sxafr_wintersoft_member_fields,SX_COUNT(sxafr_wintersoft_member_fields),SX_LE};
static bool sxafr_winter(sx_context*c){uint64_t p=8;if(!sxafr_add(c,&sxafr_wintersoft_header,0))return false;while(p<(uint64_t)c->size){uint64_t z;if(!sxafr_word(c,p+4,4,false,&z)||!sxafr_span(c,p+8,z)||!sxafr_add(c,&sxafr_wintersoft_member,p))return false;p+=8+z;}return true;}
bool sx_wintersoft_build(sx_context*c)
{
 return sxafr_winter(c);
}
