/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HLB libraries data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_hlb_header_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxag_hlb_header = {UINT32_C(0x6025002d),"hlb_header",sxag_hlb_header_fields,SX_COUNT(sxag_hlb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_hlb_entry_fields[] = {
 SX_FIELD("data_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("name","char[14]",4,14,SX_STRING),
};
const sx_layout sxag_hlb_entry = {UINT32_C(0x6025002e),"hlb_entry",sxag_hlb_entry_fields,SX_COUNT(sxag_hlb_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_hlb_footer_fields[] = {
 SX_FIELD("directory_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxag_hlb_footer = {UINT32_C(0x6025002f),"hlb_footer",sxag_hlb_footer_fields,SX_COUNT(sxag_hlb_footer_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_hlb(sx_context *c){uint8_t b[8];if(!sxag_read(c,0,b,8)||!sxag_add(c,&sxag_hlb_header,0))return false;uint64_t n=sxag16(b+2,false),p=sxag32(b+4,false);if(!n||n>SXAG_LIMIT||p<8||!sxag_span(c,p,n*18+4))return true;return sxag_table(c,&sxag_hlb_entry,p,n)&&sxag_add(c,&sxag_hlb_footer,p+n*18);}
bool sx_hlb_build(sx_context*c)
{
 return sxag_hlb(c);
}
