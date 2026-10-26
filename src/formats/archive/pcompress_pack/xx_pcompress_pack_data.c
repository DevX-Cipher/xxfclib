/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCOMPRESS_PACK data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_pcompress_magic_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxaf_pcompress_magic = {UINT32_C(0x603c0025),"pcompress_magic",sxaf_pcompress_magic_fields,SX_COUNT(sxaf_pcompress_magic_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_pcompress_member_size_fields[] = {
 SX_FIELD("name_terminator","uint8",0,1,SX_NONE),
 SX_FIELD("member_block_size","uint32",1,4,SX_SIZE),
};
const sx_layout sxaf_pcompress_member_size = {UINT32_C(0x603c0026),"pcompress_member_size",sxaf_pcompress_member_size_fields,SX_COUNT(sxaf_pcompress_member_size_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_pcompress_lh_block_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",2,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("raw_crc32","uint32",10,4,SX_CHECKSUM),
};
const sx_layout sxaf_pcompress_lh_block = {UINT32_C(0x603c0027),"pcompress_lh_block",sxaf_pcompress_lh_block_fields,SX_COUNT(sxaf_pcompress_lh_block_fields),SX_BE};
static bool sxaf_pcompress(sx_context*c){uint64_t p=4;if(!sxaf_add(c,&sxaf_pcompress_magic,0))return false;while(p<(uint64_t)c->size){if(!sxaf_zstr(c,&p,(uint64_t)c->size,91,'\n'))return false;p--;uint64_t n;if(!sxaf_word(c,p+1,4,true,&n)||!sxaf_span(c,p+5,n)||!sxaf_add(c,&sxaf_pcompress_member_size,p))return false;p+=5;uint8_t b[14];if(n>14&&sxaf_read(c,p,b,14)&&b[0]=='L'&&b[1]=='H'&&!b[2]&&!b[6]&&!sxaf_add(c,&sxaf_pcompress_lh_block,p))return false;p+=n;}return true;}
bool sx_pcompress_pack_build(sx_context*c)
{
 return sxaf_pcompress(c);
}
