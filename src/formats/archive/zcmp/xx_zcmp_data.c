/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Zcmp compressed files (the Solaris "compressed file" wrapper) data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_zcmp_header_fields[] = {
 SX_FIELD("reserved","uint32",0,4,SX_NONE),
 SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
 SX_FIELD("version1","uint64",8,8,SX_NONE),
 SX_FIELD("version2","uint64",16,8,SX_NONE),
 SX_FIELD("uncompressed_size","uint64",24,8,SX_SIZE),
 SX_FIELD("block_size","uint64",32,8,SX_SIZE),
};
const sx_layout sxafr_zcmp_header = {UINT32_C(0x60540008),"zcmp_header",sxafr_zcmp_header_fields,SX_COUNT(sxafr_zcmp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxafr_zcmp_seek_word_fields[] = {
 SX_FIELD("seek_index_word","uint64",0,8,SX_NONE),
};
const sx_layout sxafr_zcmp_seek_word = {UINT32_C(0x60540009),"zcmp_seek_word",sxafr_zcmp_seek_word_fields,SX_COUNT(sxafr_zcmp_seek_word_fields),SX_BE};
static bool sxafr_zcmp(sx_context*c){uint64_t n,block;if(!sxafr_word(c,24,8,true,&n)||!sxafr_word(c,32,8,true,&block)||!block||!sxafr_add(c,&sxafr_zcmp_header,0))return false;uint64_t count=n/block+(n%block!=0);if(count==UINT64_MAX||count+1>((uint64_t)c->size-40)/8)return false;for(uint64_t i=0;i<=count;i++)if(!sxafr_add(c,&sxafr_zcmp_seek_word,40+i*8))return false;return true;}
bool sx_zcmp_build(sx_context*c)
{
 return sxafr_zcmp(c);
}
