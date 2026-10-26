/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LHF data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_lhf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxas_lhf_header = {UINT32_C(0x6043001a),"lhf_header",sxas_lhf_header_fields,SX_COUNT(sxas_lhf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxas_lhf_entry_fields[] = {
 SX_FIELD("opaque_word","uint16",0,2,SX_NONE),
 SX_FIELD("name_size","uint16",2,2,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("opaque_tail","uint32",12,4,SX_NONE),
};
const sx_layout sxas_lhf_entry = {UINT32_C(0x6043001b),"lhf_entry",sxas_lhf_entry_fields,SX_COUNT(sxas_lhf_entry_fields),SX_BE};
static bool sxas_lhf(sx_context*c){uint64_t p=8,end;if(!sxas_word(c,4,4,true,&end)||end<8||!sxas_span(c,0,end)||!sxas_add(c,&sxas_lhf_header,0))return false;while(p<end){uint8_t b[16];if(end-p<16||!sxas_read(c,p,b,16))return false;uint64_t name=sxas_uint(b+2,2,true),packed=sxas_uint(b+4,4,true),plain=sxas_uint(b+8,4,true);if(name>end-p-16||!sxas_add(c,&sxas_lhf_entry,p))return false;p+=16+name;if(plain!=UINT32_MAX){if(packed>end-p)return false;p+=packed;}}return true;}
bool sx_lhf_build(sx_context*c)
{
 return sxas_lhf(c);
}
