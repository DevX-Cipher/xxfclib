/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ULEAD data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_ulead_prefix_fields[] = {
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("reserved1","uint32",12,4,SX_NONE),
 SX_FIELD("constant1","uint16",16,2,SX_NONE),
 SX_FIELD("constant2","uint16",18,2,SX_NONE),
 SX_FIELD("reserved2","uint32",20,4,SX_NONE),
};
const sx_layout sxao_ulead_prefix = {UINT32_C(0x6070000b),"ulead_prefix",sxao_ulead_prefix_fields,SX_COUNT(sxao_ulead_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxao_ulead_name_fields[] = {
 SX_FIELD("name","char[16]",0,16,SX_NONE),
};
const sx_layout sxao_ulead_name = {UINT32_C(0x6070000c),"ulead_name",sxao_ulead_name_fields,SX_COUNT(sxao_ulead_name_fields),SX_LE};
static const xx_data_struct_field_desc sxao_ulead_block_counts_fields[] = {
 SX_FIELD("block_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("last_block_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxao_ulead_block_counts = {UINT32_C(0x6070000d),"ulead_block_counts",sxao_ulead_block_counts_fields,SX_COUNT(sxao_ulead_block_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxao_ulead_block_size_fields[] = {
 SX_FIELD("compressed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxao_ulead_block_size = {UINT32_C(0x6070000e),"ulead_block_size",sxao_ulead_block_size_fields,SX_COUNT(sxao_ulead_block_size_fields),SX_LE};
static bool sxao_ulead(sx_context*c){uint8_t b[44];if(!sxao_read(c,0,b,44)||!sxao_add(c,&sxao_ulead_prefix,0))return false;uint64_t n1=sxao_uint(b+24,2,false),z1=sxao_uint(b+26,2,false),n2=sxao_uint(b+40,2,false),z2=sxao_uint(b+42,2,false);bool a=n1&&z1<=16384&&28+2*n1<(uint64_t)c->size,d=n2&&z2<=16384&&44+2*n2<(uint64_t)c->size;bool short_header=a&&(!d||n1<0x2000);if(!a&&!d)return false;uint64_t p=short_header?24:40,n=short_header?n1:n2;if(!short_header&&!sxao_add(c,&sxao_ulead_name,24))return false;return sxao_add(c,&sxao_ulead_block_counts,p)&&sxao_table(c,&sxao_ulead_block_size,p+4,2,n);}
bool sx_ulead_build(sx_context*c)
{
 return sxao_ulead(c);
}
