/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lucas lab data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_lab_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("name_table_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxmx_lab_header={UINT32_C(0x602E0001),"lab_header",sxmx_lab_header_fields,SX_COUNT(sxmx_lab_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_lab_entry_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("file_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
};
const sx_layout sxmx_lab_entry={UINT32_C(0x602E0002),"lab_entry",sxmx_lab_entry_fields,SX_COUNT(sxmx_lab_entry_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_lab(sxmx_view*v)
{return SM_ROW(lab_header,0,v->n)&&sxmx_table(v,&sxmx_lab_entry,16,sxmx_u32(v->p+8,false),v->n);}
bool sx_lucas_lab_build(sxmx_view*v)
{
 return sxmx_lab(v);
}
#undef SM_ROW
