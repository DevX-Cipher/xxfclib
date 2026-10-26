/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Compact Pro (.cpt) archives data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_compactpro_header_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_ID),
    SX_FIELD("volume_number","uint8",1,1,SX_ID),
    SX_FIELD("volume_set","uint16",2,2,SX_ID),
    SX_FIELD("catalogue_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxar_compactpro_header = {UINT32_C(0x601c001c),"compactpro_header",sxar_compactpro_header_fields,SX_COUNT(sxar_compactpro_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_compactpro_catalogue_fields[] = {
    SX_FIELD("crc32_register","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("record_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("comment_size","uint8",6,1,SX_SIZE),
};
const sx_layout sxar_compactpro_catalogue = {UINT32_C(0x601c001d),"compactpro_catalogue",sxar_compactpro_catalogue_fields,SX_COUNT(sxar_compactpro_catalogue_fields),SX_BE};
static const xx_data_struct_field_desc sxar_compactpro_name_size_fields[] = {
    SX_FIELD("name_size_and_folder","uint8",0,1,SX_FLAGS),
};
const sx_layout sxar_compactpro_name_size = {UINT32_C(0x601c001e),"compactpro_name_size",sxar_compactpro_name_size_fields,SX_COUNT(sxar_compactpro_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxar_compactpro_directory_fields[] = {
    SX_FIELD("descendant_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxar_compactpro_directory = {UINT32_C(0x601c001f),"compactpro_directory",sxar_compactpro_directory_fields,SX_COUNT(sxar_compactpro_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxar_compactpro_file_fields[] = {
    SX_FIELD("volume_number","uint8",0,1,SX_ID),
    SX_FIELD("data_offset","uint32",1,4,SX_OFFSET),
    SX_FIELD("file_type","char[4]",5,4,SX_ID),
    SX_FIELD("creator","char[4]",9,4,SX_ID),
    SX_FIELD("created","uint32",13,4,SX_NONE),
    SX_FIELD("modified","uint32",17,4,SX_NONE),
    SX_FIELD("finder_flags","uint16",21,2,SX_FLAGS),
    SX_FIELD("crc32_register","uint32",23,4,SX_CHECKSUM),
    SX_FIELD("flags","uint16",27,2,SX_FLAGS),
    SX_FIELD("resource_unpacked_size","uint32",29,4,SX_SIZE),
    SX_FIELD("data_unpacked_size","uint32",33,4,SX_SIZE),
    SX_FIELD("resource_packed_size","uint32",37,4,SX_SIZE),
    SX_FIELD("data_packed_size","uint32",41,4,SX_SIZE),
};
const sx_layout sxar_compactpro_file = {UINT32_C(0x601c0020),"compactpro_file",sxar_compactpro_file_fields,SX_COUNT(sxar_compactpro_file_fields),SX_BE};
#define SXAR_LIMIT 20000U
static bool sxar_compactpro(sx_context *c){uint8_t b[8];if(!sxar_read(c,0,b,8)||!sxar_add(c,&sxar_compactpro_header,0))return false;uint64_t p=sxar32(b+4,true);if(p<8||!sxar_read(c,p,b,7))return true;uint32_t n=sxar16(b+4,true);if(n>SXAR_LIMIT||!sxar_add(c,&sxar_compactpro_catalogue,p))return false;p+=7+b[6];
 for(uint32_t i=0;i<n;i++){if(!sxar_read(c,p,b,1))break;uint8_t q=b[0];if(!sxar_span(c,p+1,(q&127)+(q&128?2:45)))break;if(!sxar_add(c,&sxar_compactpro_name_size,p))return false;p+=1+(q&127);if(!sxar_add(c,q&128?&sxar_compactpro_directory:&sxar_compactpro_file,p))return false;p+=q&128?2:45;}
 return true;}
bool sx_compactpro_build(sx_context*c)
{
 return sxar_compactpro(c);
}
