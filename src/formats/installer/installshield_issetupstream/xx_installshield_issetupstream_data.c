/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * INSTALLSHIELD_ISSETUPSTREAM data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_issetup_header_fields[] = {
 SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("version","uint8",16,1,SX_NONE),
 SX_FIELD("reserved","uint8[29]",17,29,SX_NONE),
};
const sx_layout sxan_issetup_header = {UINT32_C(0x60770023),"issetup_header",sxan_issetup_header_fields,SX_COUNT(sxan_issetup_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_issetup_member_fields[] = {
 SX_FIELD("name_size","uint32",0,4,SX_SIZE),
 SX_FIELD("cipher_selector","uint32",4,4,SX_NONE),
 SX_FIELD("reserved1","uint16",8,2,SX_NONE),
 SX_FIELD("stream_size","uint32",10,4,SX_SIZE),
 SX_FIELD("reserved2","uint64",14,8,SX_NONE),
 SX_FIELD("storage","uint16",22,2,SX_NONE),
};
const sx_layout sxan_issetup_member = {UINT32_C(0x60770024),"issetup_member",sxan_issetup_member_fields,SX_COUNT(sxan_issetup_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_utf16le_fields[] = {
 SX_FIELD("name_units","uint16",0,0,SX_NONE),
};
const sx_layout sxan_archivenext_utf16le = {UINT32_C(0x60770044),"archivenext_utf16le",sxan_archivenext_utf16le_fields,SX_COUNT(sxan_archivenext_utf16le_fields),SX_LE};
static bool sxan_issetup(sx_context*c){uint8_t h[14];uint64_t p=0,n,z,len;if(!sxan_read(c,0,h,14))return false;if(xx_rt_memcmp(h,"ISSetupStream\0",14)&&!sxan_pe_overlay(c,&p))return false;if(!sxan_add(c,&sxan_issetup_header,p)||!sxan_word(c,p+14,2,false,&n))return false;p+=46;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,p,4,false,&len)||!sxan_word(c,p+10,4,false,&z)||!sxan_add(c,&sxan_issetup_member,p)||!sxan_span(c,p+24,len))return true;if(!(len&1)&&!sxan_text(c,&sxan_archivenext_utf16le,p+24,len,false))return false;p+=24+len;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
bool sx_installshield_issetupstream_build(sx_context*c)
{
bool ok=false;
ok=sxan_issetup(c);
(void)ok;return c->count&&sxan_finish(c);
}
