/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LDS compressed stream data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_lds_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint64",6,8,SX_OFFSET),
};
const sx_layout sxas_lds_header = {UINT32_C(0x60430011),"lds_header",sxas_lds_header_fields,SX_COUNT(sxas_lds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_lds_count_fields[] = {
 SX_FIELD("member_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxas_lds_count = {UINT32_C(0x60430012),"lds_count",sxas_lds_count_fields,SX_COUNT(sxas_lds_count_fields),SX_LE};
static const xx_data_struct_field_desc sxas_lds_entry_fields[] = {
 SX_FIELD("payload_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("payload_size","uint64",8,8,SX_SIZE),
 SX_FIELD("name_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxas_lds_entry = {UINT32_C(0x60430013),"lds_entry",sxas_lds_entry_fields,SX_COUNT(sxas_lds_entry_fields),SX_LE};
static bool sxas_lds(sx_context*c){uint64_t p,n;if(!sxas_word(c,6,8,false,&p)||p<14||!sxas_word(c,p,4,false,&n)||!sxas_add(c,&sxas_lds_header,0)||!sxas_add(c,&sxas_lds_count,p))return false;p+=4;for(uint64_t i=0;i<n;i++){uint64_t z;if(!sxas_word(c,p+16,4,false,&z)||!sxas_span(c,p+20,z)||!sxas_add(c,&sxas_lds_entry,p))return false;p+=20+z;}return true;}
bool sx_lds_build(sx_context*c)
{
 return sxas_lds(c);
}
