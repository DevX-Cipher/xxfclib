/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lucas bun data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_bun_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxmx_bun_header={UINT32_C(0x602E0003),"bun_header",sxmx_bun_header_fields,SX_COUNT(sxmx_bun_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bun_lb83_entry_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("extension","char[4]",8,4,SX_STRING),
 SX_FIELD("file_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxmx_bun_lb83_entry={UINT32_C(0x602E0004),"bun_lb83_entry",sxmx_bun_lb83_entry_fields,SX_COUNT(sxmx_bun_lb83_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bun_lb23_entry_fields[]={
 SX_FIELD("name","char[24]",0,24,SX_STRING),
 SX_FIELD("file_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
const sx_layout sxmx_bun_lb23_entry={UINT32_C(0x602E0005),"bun_lb23_entry",sxmx_bun_lb23_entry_fields,SX_COUNT(sxmx_bun_lb23_entry_fields),SX_BE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_bun(sxmx_view*v)
{if(!SM_ROW(bun_header,0,v->n))return false;return sxmx_table(v,!xx_rt_memcmp(v->p,"LB83",4)?&sxmx_bun_lb83_entry:&sxmx_bun_lb23_entry,sxmx_u32(v->p+4,true),sxmx_u32(v->p+8,true),v->n);}
bool sx_lucas_bun_build(sxmx_view*v)
{
 return sxmx_bun(v);
}
#undef SM_ROW
