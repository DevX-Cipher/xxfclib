/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZF stream data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_lzf_stored_block_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("kind","uint8",2,1,SX_ID),
    SX_FIELD("packed_size","uint16",3,2,SX_SIZE),
};
const sx_layout sxar_lzf_stored_block = {UINT32_C(0x601c002b),"lzf_stored_block",sxar_lzf_stored_block_fields,SX_COUNT(sxar_lzf_stored_block_fields),SX_BE};
static const xx_data_struct_field_desc sxar_lzf_compressed_block_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("kind","uint8",2,1,SX_ID),
    SX_FIELD("packed_size","uint16",3,2,SX_SIZE),
    SX_FIELD("unpacked_size","uint16",5,2,SX_SIZE),
};
const sx_layout sxar_lzf_compressed_block = {UINT32_C(0x601c002c),"lzf_compressed_block",sxar_lzf_compressed_block_fields,SX_COUNT(sxar_lzf_compressed_block_fields),SX_BE};
static const xx_data_struct_field_desc sxar_lzf_end_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxar_lzf_end = {UINT32_C(0x601c002d),"lzf_end",sxar_lzf_end_fields,SX_COUNT(sxar_lzf_end_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_lzf(sx_context *c){uint64_t p=0;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){uint8_t b[7];if(!sxar_read(c,p,b,1))break;if(!b[0]&&p+1==(uint64_t)c->size){if(!sxar_add(c,&sxar_lzf_end,p))return false;break;}if(!sxar_read(c,p,b,5)||b[0]!='Z'||b[1]!='V'||b[2]>1)break;uint64_t head=b[2]?7:5,n=sxar16(b+3,true);if(!sxar_span(c,p,head+n))break;if(!sxar_add(c,b[2]?&sxar_lzf_compressed_block:&sxar_lzf_stored_block,p))return false;p+=head+n;}return c->count!=0;}
bool sx_lzf_stream_build(sx_context*c)
{
 return sxar_lzf(c);
}
