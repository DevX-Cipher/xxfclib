/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RDFZ compressed image data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_rdfz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("method","char[4]",8,4,SX_NONE),
 SX_FIELD("packed_index_size","uint32",12,4,SX_SIZE),
 SX_FIELD("unpacked_index_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxas_rdfz_header = {UINT32_C(0x60430007),"rdfz_header",sxas_rdfz_header_fields,SX_COUNT(sxas_rdfz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_rdfz_count_fields[] = {
 SX_FIELD("member_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxas_rdfz_count = {UINT32_C(0x60430008),"rdfz_count",sxas_rdfz_count_fields,SX_COUNT(sxas_rdfz_count_fields),SX_LE};
static const xx_data_struct_field_desc sxas_rdfz_entry_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
 SX_FIELD("extension_index","uint32",8,4,SX_NONE),
 SX_FIELD("name_index","uint32",12,4,SX_NONE),
 SX_FIELD("method","uint32",16,4,SX_NONE),
};
const sx_layout sxas_rdfz_entry = {UINT32_C(0x60430009),"rdfz_entry",sxas_rdfz_entry_fields,SX_COUNT(sxas_rdfz_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxas_rdfz_member_size_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxas_rdfz_member_size = {UINT32_C(0x6043000a),"rdfz_member_size",sxas_rdfz_member_size_fields,SX_COUNT(sxas_rdfz_member_size_fields),SX_LE};
static bool sxas_rdfz(sx_context*c){uint64_t packed,n;if(!sxas_word(c,12,4,false,&packed)||packed<4||!sxas_span(c,20,packed)||!sxas_add(c,&sxas_rdfz_header,0)||!sxas_word(c,16+packed,4,false,&n)||!sxas_add(c,&sxas_rdfz_count,16+packed)||!sxas_span(c,20+packed,n*20))return false;uint64_t table=20+packed;for(uint64_t i=0;i<n;i++)if(!sxas_add(c,&sxas_rdfz_entry,table+20*i))return false;for(uint64_t i=0;i<n;i++){uint8_t b[20];if(!sxas_read(c,table+20*i,b,20))return false;uint64_t p=sxas_uint(b,4,false),z=sxas_uint(b+4,4,false);if(sxas_uint(b+16,4,false)==1&&z>=4&&p>=table+20*n&&sxas_span(c,p,z)&&!sxas_add(c,&sxas_rdfz_member_size,p))return false;}return true;}
bool sx_rdfz_build(sx_context*c)
{
 return sxas_rdfz(c);
}
