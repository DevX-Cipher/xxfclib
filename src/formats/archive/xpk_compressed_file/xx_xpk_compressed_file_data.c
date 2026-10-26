/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * XPK COMPRESSED FILE data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_xpk_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("packed_size_minus8","uint32",4,4,SX_NONE),
 SX_FIELD("subpacker","char[4]",8,4,SX_ID),
 SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("plaintext_prefix","uint8[16]",16,16,SX_NONE),
 SX_FIELD("flags","uint8",32,1,SX_FLAGS),
 SX_FIELD("header_xor8","uint8",33,1,SX_SIGNATURE),
 SX_FIELD("subpacker_version","uint8",34,1,SX_ID),
 SX_FIELD("master_version","uint8",35,1,SX_ID),
};
const sx_layout sxal_xpk_header = {UINT32_C(0x6020002f),"xpk_header",sxal_xpk_header_fields,SX_COUNT(sxal_xpk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_xpk_extension_size_fields[] = {
 SX_FIELD("extension_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxal_xpk_extension_size = {UINT32_C(0x60200030),"xpk_extension_size",sxal_xpk_extension_size_fields,SX_COUNT(sxal_xpk_extension_size_fields),SX_BE};
static const xx_data_struct_field_desc sxal_xpk_chunk2_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("header_xor8","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("data_xor16","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("unpacked_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxal_xpk_chunk2 = {UINT32_C(0x60200031),"xpk_chunk2",sxal_xpk_chunk2_fields,SX_COUNT(sxal_xpk_chunk2_fields),SX_BE};
static const xx_data_struct_field_desc sxal_xpk_chunk4_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("header_xor8","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("data_xor16","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxal_xpk_chunk4 = {UINT32_C(0x60200032),"xpk_chunk4",sxal_xpk_chunk4_fields,SX_COUNT(sxal_xpk_chunk4_fields),SX_BE};
static bool sxal_xpk(sx_context *c){uint8_t b[36];if(!sxal_read(c,0,b,36)||!sxal_add(c,&sxal_xpk_header,0))return false;unsigned flags=b[32],head=flags&1?12:8;uint64_t p=36;if(flags&4){if(!sxal_read(c,p,b,2))return true;uint64_t n=sxal16(b,true);if(!sxal_add(c,&sxal_xpk_extension_size,p))return false;p+=2;if(!sxal_span(c,p,n))return true;p+=n;}p=(p+3)&~UINT64_C(3);
 for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,head)||(b[0]!=0&&b[0]!=1&&b[0]!=15))break;uint64_t n=sxal_uint(b+4,head==12?4:2,true);if(!sxal_span(c,p+head,n))break;if(!sxal_add(c,head==12?&sxal_xpk_chunk4:&sxal_xpk_chunk2,p))return false;if(b[0]==15)break;p=(p+head+n+3)&~UINT64_C(3);}return true;}
bool sx_xpk_compressed_file_build(sx_context*c)
{
 return sxal_xpk(c);
}
