/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IFAH_INSTALLER data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_ifah_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("declared_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown1","uint32",8,4,SX_NONE),
 SX_FIELD("unknown2","uint8",12,1,SX_NONE),
 SX_FIELD("member_count","uint32",13,4,SX_COUNT_PROP),
};
const sx_layout sxan_ifah_header = {UINT32_C(0x60770017),"ifah_header",sxan_ifah_header_fields,SX_COUNT(sxan_ifah_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ifah_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("dos_time","uint16",16,2,SX_NONE),
 SX_FIELD("dos_date","uint16",18,2,SX_NONE),
 SX_FIELD("version_high","uint32",20,4,SX_NONE),
 SX_FIELD("version_low","uint32",24,4,SX_NONE),
 SX_FIELD("name_size","uint8",28,1,SX_SIZE),
};
const sx_layout sxan_ifah_member = {UINT32_C(0x60770018),"ifah_member",sxan_ifah_member_fields,SX_COUNT(sxan_ifah_member_fields),SX_LE};
static bool sxan_ifah(sx_context*c){uint8_t h[4];uint64_t p=0,n,z,len;if(!sxan_read(c,0,h,4))return false;if(xx_rt_memcmp(h,"IFAH",4)&&!sxan_pe_overlay(c,&p))return false;if(!sxan_add(c,&sxan_ifah_header,p)||!sxan_word(c,p+13,4,false,&n))return false;p+=17;for(uint64_t i=0;i<n;i++){if(!sxan_add(c,&sxan_ifah_member,p)||!sxan_word(c,p+8,4,false,&z)||!sxan_word(c,p+28,1,false,&len)||!sxan_named(c,p+29,len))return false;p+=29+len;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
bool sx_ifah_installer_build(sx_context*c)
{
bool ok=false;
ok=sxan_ifah(c);
(void)ok;return c->count&&sxan_finish(c);
}
