/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * larian_lspk data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_lspk_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("file_list_size","uint32",12,4,SX_SIZE),
 SX_FIELD("part_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("flags","uint8",18,1,SX_FLAGS),
 SX_FIELD("priority","uint8",19,1,SX_NONE),
 SX_FIELD("file_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxgp_lspk_header={UINT32_C(0x60360063),"lspk_header",sxgp_lspk_header_fields,SX_COUNT(sxgp_lspk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lspk_file_fields[]={
 SX_FIELD("name","char[256]",0,256,SX_STRING),
 SX_FIELD("data_offset","uint32",256,4,SX_OFFSET),
 SX_FIELD("size_on_disk","uint32",260,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",264,4,SX_SIZE),
 SX_FIELD("archive_part","uint32",268,4,SX_ID),
 SX_FIELD("compression_flags","uint32",272,4,SX_FLAGS),
 SX_FIELD("crc32","uint32",276,4,SX_CHECKSUM),
};
const sx_layout sxgp_lspk_file={UINT32_C(0x60360064),"lspk_file",sxgp_lspk_file_fields,SX_COUNT(sxgp_lspk_file_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_lspk(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,n;return SG_ROW(lspk_header,0,end)&&sxgp_word(v,20,4,false,&n,end)&&n<=4096&&sxgp_table(v,&sxgp_lspk_file,24,n,end);}
bool sx_larian_lspk_build(sxgp_view*v)
{
 return sxgp_lspk(v);
}
#undef SG_ROW
