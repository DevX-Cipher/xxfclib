/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CSIDOS data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_csidos_root_block_fields[] = {
    SX_FIELD("catalogue_block","uint16",0,2,SX_NONE),
    SX_FIELD("volume_blocks","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("signature1","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("signature2","uint16",6,2,SX_SIGNATURE),
    SX_FIELD("low_signature_or_state","uint8",8,1,SX_NONE),
    SX_FIELD("signature_high","uint8",9,1,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",10,2,SX_RESERVED),
};
const sx_layout sxst_csidos_root_block = {0x6037000aU,"csidos_root_block",sxst_csidos_root_block_fields,SX_COUNT(sxst_csidos_root_block_fields),SX_LE};
static const xx_data_struct_field_desc sxst_csidos_catalogue_block_fields[] = {
    SX_FIELD("catalogue_block","uint16",0,2,SX_NONE),
    SX_FIELD("opaque_header","byte[10]",2,10,SX_NONE),
};
const sx_layout sxst_csidos_catalogue_block = {0x6037000bU,"csidos_catalogue_block",sxst_csidos_catalogue_block_fields,SX_COUNT(sxst_csidos_catalogue_block_fields),SX_LE};
static const xx_data_struct_field_desc sxst_csidos_entry_fields[] = {
    SX_FIELD("parent_directory","uint16",0,2,SX_ID),
    SX_FIELD("name","char[8]",2,8,SX_NONE),
    SX_FIELD("extension","char[3]",10,3,SX_NONE),
    SX_FIELD("attributes_or_directory_id","uint8",13,1,SX_FLAGS),
    SX_FIELD("first_block","uint16",14,2,SX_NONE),
    SX_FIELD("load_address","uint16",16,2,SX_ADDRESS),
    SX_FIELD("byte_length","uint16",18,2,SX_SIZE),
};
const sx_layout sxst_csidos_entry = {0x6037000cU,"csidos_entry",sxst_csidos_entry_fields,SX_COUNT(sxst_csidos_entry_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_csidos(sx_context*c){uint8_t b[12];if(!SXST_ADD(c,csidos_root_block,1024))return false;for(unsigned i=2;i<10;i++){uint64_t p=i*512;if(!sxst_read(c,p,b,12)||sxst16(b)!=i||!sxst_span(c,p,512))break;if(i!=2&&!SXST_ADD(c,csidos_catalogue_block,p))return false;if(!SXST_TABLE(c,csidos_entry,p+12,25))return false;}return true;}
bool sx_csidos_build(sx_context*c)
{
 return sxst_csidos(c);
}
#undef SXST_ADD
#undef SXST_TABLE
