/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XLAS data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_xlas_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxat_xlas_header = {UINT32_C(0x60640020),"xlas_header",sxat_xlas_header_fields,SX_COUNT(sxat_xlas_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_xlas_member_fields[] = {
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("payload_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("method","uint16",24,2,SX_NONE),
};
const sx_layout sxat_xlas_member = {UINT32_C(0x60640021),"xlas_member",sxat_xlas_member_fields,SX_COUNT(sxat_xlas_member_fields),SX_LE};
static bool sxat_xlas(sx_context*c){uint64_t p,n;return sxat_word(c,4,4,false,&p)&&sxat_word(c,8,4,false,&n)&&sxat_add(c,&sxat_xlas_header,0)&&sxat_table(c,&sxat_xlas_member,p,26,n);}
bool sx_xlas_build(sx_context*c)
{
 return sxat_xlas(c);
}
