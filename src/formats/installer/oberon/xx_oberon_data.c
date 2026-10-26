/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Oberon data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_oberon_member_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_NONE),
 SX_FIELD("unknown","uint8[64]",64,64,SX_NONE),
 SX_FIELD("compressed_size","uint32",128,4,SX_SIZE),
 SX_FIELD("flags","uint32",132,4,SX_FLAGS),
};
const sx_layout sxap_oberon_member = {UINT32_C(0x6072002a),"oberon_member",sxap_oberon_member_fields,SX_COUNT(sxap_oberon_member_fields),SX_LE};
static const xx_data_struct_field_desc sxap_oberon_szdd_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("mode","uint8",8,1,SX_NONE),
 SX_FIELD("missing_filename_byte","uint8",9,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",10,4,SX_SIZE),
};
const sx_layout sxap_oberon_szdd = {UINT32_C(0x6072002b),"oberon_szdd",sxap_oberon_szdd_fields,SX_COUNT(sxap_oberon_szdd_fields),SX_LE};
static bool sxap_oberon(sx_context*c){uint64_t p=0;while(sxap_span(c,p,136)){uint64_t n;if(!sxap_word(c,p+128,4,false,&n)||!sxap_add(c,&sxap_oberon_member,p))return false;p+=136;if(!sxap_span(c,p,n))return true;if(n>=14&&!sxap_add(c,&sxap_oberon_szdd,p))return false;p+=n;}return true;}
bool sx_oberon_build(sx_context*c)
{
 return sxap_oberon(c);
}
