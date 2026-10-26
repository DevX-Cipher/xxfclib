/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ASD compressed stream data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_asd_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sxas_asd_header = {UINT32_C(0x6043000b),"asd_header",sxas_asd_header_fields,SX_COUNT(sxas_asd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_asd_name_length_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxas_asd_name_length = {UINT32_C(0x6043000c),"asd_name_length",sxas_asd_name_length_fields,SX_COUNT(sxas_asd_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxas_asd_entry_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("opaque_tail","uint8[6]",8,6,SX_NONE),
};
const sx_layout sxas_asd_entry = {UINT32_C(0x6043000d),"asd_entry",sxas_asd_entry_fields,SX_COUNT(sxas_asd_entry_fields),SX_LE};
static bool sxas_asd(sx_context*c){uint64_t n,p=8;if(!sxas_word(c,6,2,false,&n)||!sxas_add(c,&sxas_asd_header,0))return false;for(uint64_t i=0;i<n;i++){uint64_t z;if(!sxas_word(c,p,1,false,&z)||!sxas_span(c,p+1,z+14)||!sxas_add(c,&sxas_asd_name_length,p)||!sxas_add(c,&sxas_asd_entry,p+1+z))return false;p+=15+z;}return true;}
bool sx_asd_build(sx_context*c)
{
 return sxas_asd(c);
}
