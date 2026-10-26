/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BND data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_bnd_header_fields[] = {
 SX_FIELD("volume_prefix","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxao_bnd_header = {UINT32_C(0x60700029),"bnd_header",sxao_bnd_header_fields,SX_COUNT(sxao_bnd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_record_fields[] = {
 SX_FIELD("next_record_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("unknown","uint8[8]",8,8,SX_NONE),
 SX_FIELD("stored_member_size","uint32",16,4,SX_SIZE),
 SX_FIELD("path","char[256]",20,256,SX_NONE),
};
const sx_layout sxao_bnd_record = {UINT32_C(0x6070002a),"bnd_record",sxao_bnd_record_fields,SX_COUNT(sxao_bnd_record_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_prologue_fields[] = {
 SX_FIELD("link_name","char[14]",0,14,SX_NONE),
 SX_FIELD("constant1","uint16",14,2,SX_NONE),
 SX_FIELD("constant2","uint16",16,2,SX_NONE),
 SX_FIELD("record_type","uint16",18,2,SX_NONE),
 SX_FIELD("constant3","uint16",20,2,SX_NONE),
 SX_FIELD("zero","uint8[36]",22,36,SX_NONE),
};
const sx_layout sxao_bnd_prologue = {UINT32_C(0x6070002b),"bnd_prologue",sxao_bnd_prologue_fields,SX_COUNT(sxao_bnd_prologue_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_member_tail_fields[] = {
 SX_FIELD("name","char[128]",0,128,SX_NONE),
 SX_FIELD("attributes","uint32",128,4,SX_FLAGS),
 SX_FIELD("zero","uint32",132,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",136,4,SX_SIZE),
 SX_FIELD("dos_date_word","uint32",140,4,SX_NONE),
 SX_FIELD("dos_time_word","uint32",144,4,SX_NONE),
 SX_FIELD("unknown","uint8[20]",148,20,SX_NONE),
};
const sx_layout sxao_bnd_member_tail = {UINT32_C(0x6070002c),"bnd_member_tail",sxao_bnd_member_tail_fields,SX_COUNT(sxao_bnd_member_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_trailer_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_record_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("last_record_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxao_bnd_trailer = {UINT32_C(0x6070002d),"bnd_trailer",sxao_bnd_trailer_fields,SX_COUNT(sxao_bnd_trailer_fields),SX_LE};
#define SXAO_LIMIT 20000U
static bool sxao_bnd(sx_context*c){uint64_t n=(uint64_t)c->size,p,last;if(n<16||!sxao_add(c,&sxao_bnd_header,0)||!sxao_add(c,&sxao_bnd_trailer,n-16)||!sxao_word(c,n-8,4,false,&p)||!sxao_word(c,n-4,4,false,&last))return false;for(size_t work=0;work<SXAO_LIMIT;work++){uint64_t next,z,kind;if(!sxao_word(c,p,4,false,&next)||!sxao_word(c,p+16,4,false,&z)||!sxao_add(c,&sxao_bnd_record,p))return false;uint64_t q=p+276;if(!sxao_span(c,q,z)||z<58||!sxao_word(c,q+18,2,false,&kind)||!sxao_add(c,&sxao_bnd_prologue,q))return false;if(kind==0x74&&z>=226){if(!sxao_add(c,&sxao_bnd_member_tail,q+58)||!sxao_dcl(c,q+226,z-226))return false;}if(p==last||!next)return true;if(next<=p)return false;p=next;}return true;}
bool sx_bnd_build(sx_context*c)
{
 return sxao_bnd(c);
}
