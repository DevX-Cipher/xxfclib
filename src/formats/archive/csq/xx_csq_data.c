/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CSQ compressed data data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_csq_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("member_count","uint8",8,1,SX_COUNT_PROP),
};
const sx_layout sxas_csq_header = {UINT32_C(0x60430002),"csq_header",sxas_csq_header_fields,SX_COUNT(sxas_csq_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_csq_entry_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("method","uint8",12,1,SX_NONE),
 SX_FIELD("name_size","uint8",13,1,SX_SIZE),
 SX_FIELD("name","char[12]",14,12,SX_NONE),
};
const sx_layout sxas_csq_entry = {UINT32_C(0x60430003),"csq_entry",sxas_csq_entry_fields,SX_COUNT(sxas_csq_entry_fields),SX_LE};
static bool sxas_csq(sx_context*c){uint64_t n;if(!sxas_word(c,8,1,false,&n)||!sxas_add(c,&sxas_csq_header,0)||!sxas_span(c,9,n*26))return false;for(uint64_t i=0;i<n;i++)if(!sxas_add(c,&sxas_csq_entry,9+i*26))return false;return true;}
bool sx_csq_build(sx_context*c)
{
 return sxas_csq(c);
}
