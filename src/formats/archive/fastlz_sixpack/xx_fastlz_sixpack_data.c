/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FastLZ 6pack data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_sixpack_header_fields[] = {
    SX_FIELD("magic","uint8[8]",0,8,SX_SIGNATURE),
};
const sx_layout sxar_sixpack_header = {UINT32_C(0x601c002e),"sixpack_header",sxar_sixpack_header_fields,SX_COUNT(sxar_sixpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_sixpack_chunk_fields[] = {
    SX_FIELD("kind","uint16",0,2,SX_ID),
    SX_FIELD("method","uint16",2,2,SX_ID),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
    SX_FIELD("adler32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxar_sixpack_chunk = {UINT32_C(0x601c002f),"sixpack_chunk",sxar_sixpack_chunk_fields,SX_COUNT(sxar_sixpack_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxar_sixpack_file_fields[] = {
    SX_FIELD("file_size","uint64",0,8,SX_SIZE),
    SX_FIELD("name_size","uint16",8,2,SX_SIZE),
};
const sx_layout sxar_sixpack_file = {UINT32_C(0x601c0030),"sixpack_file",sxar_sixpack_file_fields,SX_COUNT(sxar_sixpack_file_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_sixpack(sx_context *c){uint8_t b[16];if(!sxar_span(c,0,8)||!sxar_add(c,&sxar_sixpack_header,0))return false;uint64_t p=8;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){if(!sxar_read(c,p,b,16))break;uint64_t n=sxar32(b+4,false);if(!sxar_span(c,p+16,n))break;if(!sxar_add(c,&sxar_sixpack_chunk,p))return false;if(sxar16(b,false)==1&&n>=10&&!sxar_add(c,&sxar_sixpack_file,p+16))return false;p+=16+n;}return true;}
bool sx_fastlz_sixpack_build(sx_context*c)
{
 return sxar_sixpack(c);
}
