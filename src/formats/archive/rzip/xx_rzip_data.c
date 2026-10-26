/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RZIP data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_rzip_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("major","uint8",4,1,SX_ID),
 SX_FIELD("minor","uint8",5,1,SX_ID),
 SX_FIELD("unpacked_size_low","uint32",6,4,SX_NONE),
 SX_FIELD("unpacked_size_high","uint32",10,4,SX_NONE),
 SX_FIELD("reserved","uint8[10]",14,10,SX_RESERVED),
};
const sx_layout sxal_rzip_header = {UINT32_C(0x60200046),"rzip_header",sxal_rzip_header_fields,SX_COUNT(sxal_rzip_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_rzip_block_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint32",1,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",5,4,SX_SIZE),
 SX_FIELD("next_block_offset","uint32",9,4,SX_OFFSET),
};
const sx_layout sxal_rzip_block = {UINT32_C(0x60200047),"rzip_block",sxal_rzip_block_fields,SX_COUNT(sxal_rzip_block_fields),SX_LE};
static bool sxal_rzip(sx_context *c){uint8_t b[13];if(!sxal_add(c,&sxal_rzip_header,0))return false;uint64_t p=24;for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,13)||(b[0]!=3&&b[0]!=4))break;uint64_t n=sxal32(b+1,false);if(!sxal_span(c,p+13,n))break;if(!sxal_add(c,&sxal_rzip_block,p))return false;p+=13+n;}return true;}
bool sx_rzip_build(sx_context*c)
{
 return sxal_rzip(c);
}
