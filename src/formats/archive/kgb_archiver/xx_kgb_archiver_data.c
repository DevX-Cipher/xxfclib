/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * kgb_archiver data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_kgb2_header_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("encrypted","uint8",8,1,SX_FLAGS),
 SX_FIELD("algorithm","uint8",9,1,SX_NONE),
 SX_FIELD("compression_mode","uint8",10,1,SX_NONE),
 SX_FIELD("member_count","uint32",11,4,SX_COUNT_PROP),
};
const sx_layout sxap_kgb2_header = {UINT32_C(0x6072002f),"kgb2_header",sxap_kgb2_header_fields,SX_COUNT(sxap_kgb2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_kgb2_member_fields[] = {
 SX_FIELD("record_size","uint32",0,4,SX_SIZE),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("padding","uint32",8,4,SX_NONE),
 SX_FIELD("creation_time","int64",12,8,SX_TIME),
 SX_FIELD("access_time","int64",20,8,SX_TIME),
 SX_FIELD("modification_time","int64",28,8,SX_TIME),
 SX_FIELD("uncompressed_size","int64",36,8,SX_SIZE),
 SX_FIELD("name","uint16[260]",44,520,SX_NONE),
 SX_FIELD("byte_sum","uint64",564,8,SX_CHECKSUM),
};
const sx_layout sxap_kgb2_member = {UINT32_C(0x60720030),"kgb2_member",sxap_kgb2_member_fields,SX_COUNT(sxap_kgb2_member_fields),SX_LE};
static const xx_data_struct_field_desc sxap_kgb2_encryption_fields[] = {
 SX_FIELD("encrypted_check","uint64",0,8,SX_NONE),
};
const sx_layout sxap_kgb2_encryption = {UINT32_C(0x60720031),"kgb2_encryption",sxap_kgb2_encryption_fields,SX_COUNT(sxap_kgb2_encryption_fields),SX_LE};
static bool sxap_kgb(sx_context*c){uint64_t n,encrypted;if(!sxap_word(c,11,4,false,&n)||!sxap_word(c,8,1,false,&encrypted)||!sxap_add(c,&sxap_kgb2_header,0)||!sxap_table(c,&sxap_kgb2_member,15,572,n))return false;return !encrypted||sxap_add(c,&sxap_kgb2_encryption,15+572*n);}
bool sx_kgb_archiver_build(sx_context*c)
{
 return sxap_kgb(c);
}
