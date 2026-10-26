/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RSVK data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_rsvk_container_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxao_rsvk_container = {UINT32_C(0x6070001a),"rsvk_container",sxao_rsvk_container_fields,SX_COUNT(sxao_rsvk_container_fields),SX_LE};
static const xx_data_struct_field_desc sxao_rsvk_block_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("primary_index","int32",12,4,SX_NONE),
 SX_FIELD("hole_index","int32",16,4,SX_NONE),
};
const sx_layout sxao_rsvk_block = {UINT32_C(0x6070001b),"rsvk_block",sxao_rsvk_block_fields,SX_COUNT(sxao_rsvk_block_fields),SX_LE};
static const xx_data_struct_field_desc sxao_rsvk_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("compressed_size_hint","int32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",8,4,SX_SIZE),
 SX_FIELD("block_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("first_block_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("dos_time","uint16",20,2,SX_NONE),
 SX_FIELD("dos_date","uint16",22,2,SX_NONE),
 SX_FIELD("attributes","uint32",24,4,SX_FLAGS),
};
const sx_layout sxao_rsvk_member = {UINT32_C(0x6070001c),"rsvk_member",sxao_rsvk_member_fields,SX_COUNT(sxao_rsvk_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_rsvk_trailer_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unused","uint32",4,4,SX_NONE),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxao_rsvk_trailer = {UINT32_C(0x6070001d),"rsvk_trailer",sxao_rsvk_trailer_fields,SX_COUNT(sxao_rsvk_trailer_fields),SX_LE};
#define SXAO_LIMIT 20000U
static bool sxao_rsvk(sx_context*c){uint64_t n=(uint64_t)c->size,dir;if(n<16||!sxao_add(c,&sxao_rsvk_container,0)||!sxao_add(c,&sxao_rsvk_trailer,n-12)||!sxao_word(c,n-4,4,false,&dir)||dir<24||dir>n-12)return false;uint64_t p=dir;for(size_t work=0;p<n-12&&work<SXAO_LIMIT;work++){uint8_t h[28];uint64_t name;if(n-12-p<28||!sxao_read(c,p,h,28)||!sxao_zlen(c,p+28,n-12,&name)||!sxao_add(c,&sxao_rsvk_member,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+28,name,false))return false;uint64_t count=sxao_uint(h+12,4,false),q=sxao_uint(h+16,4,false);if(count>INT32_MAX||q>INT32_MAX)return false;for(uint64_t j=0;j<count&&c->count<SXAO_LIMIT;j++){uint64_t z;if(q>dir||dir-q<20||!sxao_word(c,q+8,4,false,&z)||z>dir-q-20||!sxao_add(c,&sxao_rsvk_block,q))break;q+=20+z;}p+=28+name;}return true;}
bool sx_rsvk_build(sx_context*c)
{
 return sxao_rsvk(c);
}
