/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RECOGNITA data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_recognita_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("uncompressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",17,2,SX_NONE),
 SX_FIELD("dos_date","uint16",19,2,SX_NONE),
 SX_FIELD("next_header_offset","uint32",21,4,SX_OFFSET),
};
const sx_layout sxao_recognita_member = {UINT32_C(0x60700026),"recognita_member",sxao_recognita_member_fields,SX_COUNT(sxao_recognita_member_fields),SX_LE};
static bool sxao_recognita(sx_context*c){uint64_t p=0;while(sxao_span(c,p,25)){uint64_t next;if(!sxao_word(c,p+21,4,false,&next)||!sxao_add(c,&sxao_recognita_member,p)||next<=p+25||next>(uint64_t)c->size)return false;if(!sxao_dcl(c,p+25,next-p-25))return false;p=next;}return true;}
bool sx_recognita_build(sx_context*c)
{
 return sxao_recognita(c);
}
