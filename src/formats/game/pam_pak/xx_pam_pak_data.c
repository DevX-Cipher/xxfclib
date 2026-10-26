/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PAM PAK archive data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_pam_pak_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("entry_count","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("unknown1","uint16",10,2,SX_NONE),
 SX_FIELD("string_table_size","uint32",12,4,SX_SIZE),
 SX_FIELD("unknown2","uint8[20]",16,20,SX_NONE),
};
const sx_layout sxbx_pam_pak_header = {UINT32_C(0x603000ed),"pam_pak_header",sxbx_pam_pak_header_fields,SX_COUNT(sxbx_pam_pak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pam_pak_data_fields[] = {
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxbx_pam_pak_data = {UINT32_C(0x603000ee),"pam_pak_data",sxbx_pam_pak_data_fields,SX_COUNT(sxbx_pam_pak_data_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pam_pak_directory_marker_fields[] = {
 SX_FIELD("size_marker","uint32",0,4,SX_FLAGS),
 SX_FIELD("offset_marker","uint32",4,4,SX_FLAGS),
};
const sx_layout sxbx_pam_pak_directory_marker = {UINT32_C(0x603000ef),"pam_pak_directory_marker",sxbx_pam_pak_directory_marker_fields,SX_COUNT(sxbx_pam_pak_directory_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pam_pak_index_fields[] = {
 SX_FIELD("entry_id","uint32",0,4,SX_ID),
 SX_FIELD("data_index","uint16",4,2,SX_NONE),
 SX_FIELD("unknown1","uint16",6,2,SX_NONE),
 SX_FIELD("name_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("unknown2","uint32",12,4,SX_NONE),
 SX_FIELD("parent_id","uint32",16,4,SX_ID),
 SX_FIELD("unknown3","uint32",20,4,SX_NONE),
};
const sx_layout sxbx_pam_pak_index = {UINT32_C(0x603000f0),"pam_pak_index",sxbx_pam_pak_index_fields,SX_COUNT(sxbx_pam_pak_index_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_pam(sx_context*c){uint64_t n;if(!sxbx_add(c,&sxbx_pam_pak_header,0)||!sxbx_word(c,8,2,false,&n)||n>SXBX_LIMIT||!sxbx_span(c,36,n*32))return false;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint64_t z,off;if(!sxbx_word(c,36+i*8,4,false,&z)||!sxbx_word(c,40+i*8,4,false,&off)||!sxbx_add(c,z==0xc0000000U&&off==UINT32_MAX?&sxbx_pam_pak_directory_marker:&sxbx_pam_pak_data,36+i*8))return false;}return sxbx_table(c,&sxbx_pam_pak_index,36+n*8,n);}
bool sx_pam_pak_build(sx_context*c)
{
 return sxbx_pam(c);
}
