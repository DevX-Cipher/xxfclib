/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SBPAK data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_sbpak_header_fields[] = {
 SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
 SX_FIELD("unknown0","uint8[7]",13,7,SX_NONE),
 SX_FIELD("endian_marker","uint32",20,4,SX_SIGNATURE),
 SX_FIELD("marker","uint32",24,4,SX_NONE),
 SX_FIELD("version","uint32",28,4,SX_NONE),
 SX_FIELD("unknown1","uint32",32,4,SX_NONE),
 SX_FIELD("member_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("unknown2","uint32",40,4,SX_NONE),
 SX_FIELD("data_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("archive_size","uint32",48,4,SX_SIZE),
};
const sx_layout sxan_sbpak_header = {UINT32_C(0x60770068),"sbpak_header",sxan_sbpak_header_fields,SX_COUNT(sxan_sbpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_sbpak_encoded_header_fields[] = {
 SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
 SX_FIELD("unknown0","uint8[7]",13,7,SX_NONE),
 SX_FIELD("encoded_endian_marker","uint8[4]",20,4,SX_NONE),
 SX_FIELD("encoded_marker","uint8[4]",24,4,SX_NONE),
 SX_FIELD("xor_key","uint8",28,1,SX_NONE),
 SX_FIELD("encoded_version_tail","uint8[3]",29,3,SX_NONE),
 SX_FIELD("encoded_unknown1","uint8[4]",32,4,SX_NONE),
 SX_FIELD("encoded_member_count","uint8[4]",36,4,SX_NONE),
 SX_FIELD("encoded_unknown2","uint8[4]",40,4,SX_NONE),
 SX_FIELD("encoded_data_offset","uint8[4]",44,4,SX_NONE),
 SX_FIELD("encoded_archive_size","uint8[4]",48,4,SX_NONE),
};
const sx_layout sxan_sbpak_encoded_header = {UINT32_C(0x60770069),"sbpak_encoded_header",sxan_sbpak_encoded_header_fields,SX_COUNT(sxan_sbpak_encoded_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_sbpak_member_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("name_offset_flags","uint32",8,4,SX_NONE),
 SX_FIELD("directory_offset_flags","uint32",12,4,SX_NONE),
};
const sx_layout sxan_sbpak_member = {UINT32_C(0x6077006a),"sbpak_member",sxan_sbpak_member_fields,SX_COUNT(sxan_sbpak_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_sbpak_encoded_member_fields[] = {
 SX_FIELD("encoded_size","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_data_offset","uint8[4]",4,4,SX_NONE),
 SX_FIELD("encoded_name_offset_flags","uint8[4]",8,4,SX_NONE),
 SX_FIELD("encoded_directory_offset_flags","uint8[4]",12,4,SX_NONE),
};
const sx_layout sxan_sbpak_encoded_member = {UINT32_C(0x6077006b),"sbpak_encoded_member",sxan_sbpak_encoded_member_fields,SX_COUNT(sxan_sbpak_encoded_member_fields),SX_LE};
static bool sxan_sbpak(sx_context*c){uint8_t h[52];if(!sxan_read(c,0,h,52))return false;uint8_t key=h[28];for(unsigned i=0;i<52;i++)h[i]^=key;uint64_t n=sxan_uint(h+36,4,false);return sxan_add(c,key?&sxan_sbpak_encoded_header:&sxan_sbpak_header,0)&&sxan_table(c,key?&sxan_sbpak_encoded_member:&sxan_sbpak_member,52,16,n);}
bool sx_sbpak_build(sx_context*c)
{
bool ok=false;
ok=sxan_sbpak(c);
(void)ok;return c->count&&sxan_finish(c);
}
