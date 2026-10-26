/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JGPAK data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_jgpak_header_fields[] = {
 SX_FIELD("signature","uint8[7]",0,7,SX_SIGNATURE),
 SX_FIELD("description_size","int32",7,4,SX_SIZE),
};
const sx_layout sxacl_jgpak_header = {UINT32_C(0x60500006),"jgpak_header",sxacl_jgpak_header_fields,SX_COUNT(sxacl_jgpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_version_size_fields[] = {
 SX_FIELD("version_size","int32",0,4,SX_SIZE),
};
const sx_layout sxacl_jgpak_version_size = {UINT32_C(0x60500007),"jgpak_version_size",sxacl_jgpak_version_size_fields,SX_COUNT(sxacl_jgpak_version_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_count_fields[] = {
 SX_FIELD("flag","uint8",0,1,SX_NONE),
 SX_FIELD("member_count","int32",1,4,SX_COUNT_PROP),
};
const sx_layout sxacl_jgpak_count = {UINT32_C(0x60500008),"jgpak_count",sxacl_jgpak_count_fields,SX_COUNT(sxacl_jgpak_count_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_name_size_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxacl_jgpak_name_size = {UINT32_C(0x60500009),"jgpak_name_size",sxacl_jgpak_name_size_fields,SX_COUNT(sxacl_jgpak_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_member_fields[] = {
 SX_FIELD("dos_time","uint16",0,2,SX_NONE),
 SX_FIELD("dos_date","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("payload_offset","int32",8,4,SX_OFFSET),
 SX_FIELD("compressed_size","int32",12,4,SX_SIZE),
 SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("unused","uint8[4]",20,4,SX_NONE),
};
const sx_layout sxacl_jgpak_member = {UINT32_C(0x6050000a),"jgpak_member",sxacl_jgpak_member_fields,SX_COUNT(sxacl_jgpak_member_fields),SX_LE};
static bool sxacl_jg(sx_context*c){uint64_t z,p,n;if(!sxacl_word(c,7,4,false,&z)||z>INT32_MAX||!sxacl_span(c,11,z)||!sxacl_add(c,&sxacl_jgpak_header,0))return false;p=11+z;if(!sxacl_word(c,p,4,false,&z)||z>INT32_MAX||!sxacl_span(c,p+4,z)||!sxacl_add(c,&sxacl_jgpak_version_size,p))return false;p+=4+z;if(!sxacl_word(c,p+1,4,false,&n)||n>INT32_MAX||!sxacl_add(c,&sxacl_jgpak_count,p))return false;p+=5;for(uint64_t i=0;i<n;i++){if(!sxacl_word(c,p,1,false,&z)||!z||!sxacl_span(c,p+1,z+24)||!sxacl_add(c,&sxacl_jgpak_name_size,p)||!sxacl_add(c,&sxacl_jgpak_member,p+1+z))return false;p+=25+z;}return true;}
bool sx_jgpak_build(sx_context*c)
{
 return sxacl_jg(c);
}
