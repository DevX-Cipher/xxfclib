/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JASC data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_jasc_member_fields[] = {
 SX_FIELD("header_size_minus2","uint8",0,1,SX_NONE),
 SX_FIELD("header_check","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",2,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("modification_time","uint32",10,4,SX_TIME),
 SX_FIELD("crc16","uint16",14,2,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",16,1,SX_SIZE),
};
const sx_layout sxao_jasc_member = {UINT32_C(0x60700027),"jasc_member",sxao_jasc_member_fields,SX_COUNT(sxao_jasc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_jasc_end_fields[] = {
 SX_FIELD("terminator","uint8",0,1,SX_NONE),
};
const sx_layout sxao_jasc_end = {UINT32_C(0x60700028),"jasc_end",sxao_jasc_end_fields,SX_COUNT(sxao_jasc_end_fields),SX_LE};
static bool sxao_jasc(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint64_t hs,n,z;if(!sxao_word(c,p,1,false,&hs))return false;if(!hs)return sxao_add(c,&sxao_jasc_end,p);if(!sxao_word(c,p+16,1,false,&n)||hs!=n+15||!sxao_word(c,p+2,4,false,&z)||!sxao_add(c,&sxao_jasc_member,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+17,n,false))return false;p+=17+n;if(!sxao_span(c,p,z))return true;p+=z;}return true;}
bool sx_jasc_build(sx_context*c)
{
 return sxao_jasc(c);
}
