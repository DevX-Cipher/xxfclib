/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IS11 data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_is11_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("format_version","uint32",4,4,SX_NONE),
 SX_FIELD("variant","uint8",8,1,SX_NONE),
 SX_FIELD("reserved","uint32",9,4,SX_NONE),
};
const sx_layout sxan_is11_header = {UINT32_C(0x6077000c),"is11_header",sxan_is11_header_fields,SX_COUNT(sxan_is11_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is11_member_v1_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("compressed_size","int32",1,4,SX_SIZE),
 SX_FIELD("next_offset","int32",5,4,SX_OFFSET),
 SX_FIELD("reserved","uint16",9,2,SX_NONE),
 SX_FIELD("name_size","uint8",11,1,SX_SIZE),
};
const sx_layout sxan_is11_member_v1 = {UINT32_C(0x6077000d),"is11_member_v1",sxan_is11_member_v1_fields,SX_COUNT(sxan_is11_member_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is11_member_v3_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("compressed_size","int32",1,4,SX_SIZE),
 SX_FIELD("next_offset","int32",5,4,SX_OFFSET),
 SX_FIELD("dos_date","uint16",9,2,SX_NONE),
 SX_FIELD("dos_time","uint16",11,2,SX_NONE),
 SX_FIELD("reserved","uint16",13,2,SX_NONE),
 SX_FIELD("name_size","uint8",15,1,SX_SIZE),
};
const sx_layout sxan_is11_member_v3 = {UINT32_C(0x6077000e),"is11_member_v3",sxan_is11_member_v3_fields,SX_COUNT(sxan_is11_member_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_separator_fields[] = {
 SX_FIELD("separator","uint8",0,1,SX_NONE),
};
const sx_layout sxan_archivenext_separator = {UINT32_C(0x60770048),"archivenext_separator",sxan_archivenext_separator_fields,SX_COUNT(sxan_archivenext_separator_fields),SX_LE};
static bool sxan_is11(sx_context*c){uint64_t version,p=13,z,len;if(!sxan_word(c,4,4,false,&version)||!sxan_add(c,&sxan_is11_header,0))return false;unsigned fixed=version==0x00030108?16:12;while(sxan_span(c,p,fixed)){if(!sxan_word(c,p+1,4,false,&z)||z>INT32_MAX||!sxan_word(c,p+fixed-1,1,false,&len)||!sxan_add(c,fixed==16?&sxan_is11_member_v3:&sxan_is11_member_v1,p)||!sxan_named(c,p+fixed,len)||!sxan_add(c,&sxan_archivenext_separator,p+fixed+len))return false;p+=fixed+len+1;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
bool sx_is11_build(sx_context*c)
{
bool ok=false;
ok=sxan_is11(c);
(void)ok;return c->count&&sxan_finish(c);
}
