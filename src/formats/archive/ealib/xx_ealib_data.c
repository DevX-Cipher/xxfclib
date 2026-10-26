/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * EALIB archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_ealib_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("entry_count","uint16",5,2,SX_COUNT_PROP),
};
const sx_layout sxag_ealib_header = {UINT32_C(0x60250038),"ealib_header",sxag_ealib_header_fields,SX_COUNT(sxag_ealib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ealib_entry_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_STRING),
 SX_FIELD("method","uint8",13,1,SX_ID),
 SX_FIELD("data_offset","int32",14,4,SX_OFFSET),
};
const sx_layout sxag_ealib_entry = {UINT32_C(0x60250039),"ealib_entry",sxag_ealib_entry_fields,SX_COUNT(sxag_ealib_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ealib_packed_size_fields[] = {
 SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxag_ealib_packed_size = {UINT32_C(0x6025003a),"ealib_packed_size",sxag_ealib_packed_size_fields,SX_COUNT(sxag_ealib_packed_size_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_ealib(sx_context *c){uint8_t b[18];if(!sxag_read(c,0,b,7)||!sxag_add(c,&sxag_ealib_header,0))return false;uint64_t n=sxag16(b+5,false);if(!n||n>=SXAG_LIMIT||!sxag_span(c,7,(n+1)*18))return true;if(!sxag_table(c,&sxag_ealib_entry,7,n+1))return false;uint64_t directory_end=7+(n+1)*18;for(uint64_t i=0;i<n;i++){if(!sxag_read(c,7+i*18,b,18))break;uint64_t p=sxag32(b+14,false);if(p<directory_end||p>INT32_MAX||(b[13]!=1&&b[13]!=4))continue;unsigned method=b[13];if(!sxag_read(c,7+(i+1)*18,b,18))break;uint64_t end=sxag32(b+14,false);if(end<p||end-p<4||!sxag_span(c,p,end-p))continue;if(!sxag_add(c,&sxag_ealib_packed_size,p))return false;if(method==4&&end-p>=6&&!sxag_add(c,&sxag_archivelegacy_dcl,p+4))return false;}return true;}
bool sx_ealib_build(sx_context*c)
{
 return sxag_ealib(c);
}
