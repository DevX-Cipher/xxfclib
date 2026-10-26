/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARCV data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_arcv_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown","uint8[4]",8,4,SX_NONE),
 SX_FIELD("name_size","uint8",12,1,SX_SIZE),
};
const sx_layout sxao_arcv_header = {UINT32_C(0x6070001e),"arcv_header",sxao_arcv_header_fields,SX_COUNT(sxao_arcv_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_arcv_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown1","uint8[16]",8,16,SX_NONE),
 SX_FIELD("jamcrc","uint32",24,4,SX_CHECKSUM),
 SX_FIELD("unknown2","uint8[6]",28,6,SX_NONE),
};
const sx_layout sxao_arcv_member = {UINT32_C(0x6070001f),"arcv_member",sxao_arcv_member_fields,SX_COUNT(sxao_arcv_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_arcv_chunk_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown1","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown2","uint32",8,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxao_arcv_chunk = {UINT32_C(0x60700020),"arcv_chunk",sxao_arcv_chunk_fields,SX_COUNT(sxao_arcv_chunk_fields),SX_LE};
static bool sxao_arcv(sx_context*c){uint8_t b[13];if(!sxao_read(c,0,b,13)||!sxao_add(c,&sxao_arcv_header,0))return false;uint64_t hs=sxao_uint(b+6,2,false),name=b[12];return sxao_text(c,&sxao_archiveobsolete_name,13,name,false)&&sxao_add(c,&sxao_arcv_member,13+name)&&sxao_add(c,&sxao_arcv_chunk,hs);}
bool sx_arcv_build(sx_context*c)
{
 return sxao_arcv(c);
}
