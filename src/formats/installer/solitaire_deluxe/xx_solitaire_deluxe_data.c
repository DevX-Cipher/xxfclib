/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Solitaire Deluxe data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_solitaire_header_fields[] = {
 SX_FIELD("banner","char[100]",0,100,SX_SIGNATURE),
 SX_FIELD("eof_marker","uint8",100,1,SX_SIGNATURE),
 SX_FIELD("marker","uint32",101,4,SX_SIGNATURE),
 SX_FIELD("producer","char[2]",105,2,SX_SIGNATURE),
 SX_FIELD("unknown","uint8[8]",107,8,SX_NONE),
 SX_FIELD("category_count","uint16",115,2,SX_COUNT_PROP),
 SX_FIELD("member_count","uint16",117,2,SX_COUNT_PROP),
};
const sx_layout sxap_solitaire_header = {UINT32_C(0x6072002c),"solitaire_header",sxap_solitaire_header_fields,SX_COUNT(sxap_solitaire_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_solitaire_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",13,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",17,4,SX_SIZE),
 SX_FIELD("attributes","uint16",21,2,SX_FLAGS),
 SX_FIELD("value","uint16",23,2,SX_NONE),
};
const sx_layout sxap_solitaire_member = {UINT32_C(0x6072002d),"solitaire_member",sxap_solitaire_member_fields,SX_COUNT(sxap_solitaire_member_fields),SX_LE};
static bool sxap_solitaire(sx_context*c){uint64_t files,categories,p;if(!sxap_word(c,115,2,false,&categories)||!sxap_word(c,117,2,false,&files)||!sxap_add(c,&sxap_solitaire_header,0)||!sxap_table(c,&sxap_solitaire_member,119,25,files))return false;p=119+25*files+22*categories;for(uint64_t i=0;i<files;i++){uint64_t z;if(!sxap_word(c,119+25*i+17,4,false,&z))return false;if(!sxap_span(c,p,z))return true;if(!sxap_dcl(c,p,z))return false;p+=z;}return true;}
bool sx_solitaire_deluxe_build(sx_context*c)
{
 return sxap_solitaire(c);
}
