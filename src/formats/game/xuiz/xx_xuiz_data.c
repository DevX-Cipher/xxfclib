/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XUIZ data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_xuiz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("archive_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
 SX_FIELD("directory_size","uint32",16,4,SX_SIZE),
 SX_FIELD("member_count","uint16",20,2,SX_COUNT_PROP),
};
const sx_layout sxan_xuiz_header = {UINT32_C(0x6077003b),"xuiz_header",sxan_xuiz_header_fields,SX_COUNT(sxan_xuiz_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_xuiz_member_0_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("name_units","uint8",8,1,SX_COUNT_PROP),
};
const sx_layout sxan_xuiz_member_0 = {UINT32_C(0x6077003c),"xuiz_member_0",sxan_xuiz_member_0_fields,SX_COUNT(sxan_xuiz_member_0_fields),SX_BE};
static const xx_data_struct_field_desc sxan_xuiz_member_10_fields[] = {
 SX_FIELD("unknown","uint8[10]",0,10,SX_NONE),
 SX_FIELD("payload_size","uint32",10,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",14,4,SX_OFFSET),
 SX_FIELD("name_units","uint8",18,1,SX_COUNT_PROP),
};
const sx_layout sxan_xuiz_member_10 = {UINT32_C(0x6077003d),"xuiz_member_10",sxan_xuiz_member_10_fields,SX_COUNT(sxan_xuiz_member_10_fields),SX_BE};
static const xx_data_struct_field_desc sxan_archivenext_utf16be_fields[] = {
 SX_FIELD("name_units","uint16",0,0,SX_NONE),
};
const sx_layout sxan_archivenext_utf16be = {UINT32_C(0x60770045),"archivenext_utf16be",sxan_archivenext_utf16be_fields,SX_COUNT(sxan_archivenext_utf16be_fields),SX_BE};
static bool sxan_xuiz_walk(sx_context*c,uint64_t n,uint64_t end,unsigned extra,bool emit){uint64_t p=22,len;for(uint64_t i=0;i<n;i++){if(p>end||end-p<9+extra||!sxan_word(c,p+8+extra,1,false,&len)||!len||2*len>end-p-9-extra)return false;if(emit&&(!sxan_add(c,extra?&sxan_xuiz_member_10:&sxan_xuiz_member_0,p)||!sxan_text(c,&sxan_archivenext_utf16be,p+9+extra,len*2,false)))return false;p+=9+extra+len*2;}return p==end;}
static bool sxan_xuiz(sx_context*c){uint64_t n,z;if(!sxan_add(c,&sxan_xuiz_header,0)||!sxan_word(c,16,4,true,&z)||!sxan_word(c,20,2,true,&n)||!sxan_span(c,22,z))return false;bool short_ok=sxan_xuiz_walk(c,n,22+z,0,false),long_ok=sxan_xuiz_walk(c,n,22+z,10,false);if(short_ok==long_ok)return true;return sxan_xuiz_walk(c,n,22+z,long_ok?10:0,true);}
bool sx_xuiz_build(sx_context*c)
{
bool ok=false;
ok=sxan_xuiz(c);
(void)ok;return c->count&&sxan_finish(c);
}
