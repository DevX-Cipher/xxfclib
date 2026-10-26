/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * terminalreality pod data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_pod2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("comment","char[80]",8,80,SX_STRING),
 SX_FIELD("entry_count","uint32",88,4,SX_COUNT_PROP),
 SX_FIELD("audit_count","uint32",92,4,SX_COUNT_PROP),
};
const sx_layout sxmx_pod2_header={UINT32_C(0x602E000E),"pod2_header",sxmx_pod2_header_fields,SX_COUNT(sxmx_pod2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_pod2_entry_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("file_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("timestamp","int32",12,4,SX_TIME),
 SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
};
const sx_layout sxmx_pod2_entry={UINT32_C(0x602E000F),"pod2_entry",sxmx_pod2_entry_fields,SX_COUNT(sxmx_pod2_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_pod2_audit_fields[]={
 SX_FIELD("user","char[32]",0,32,SX_STRING),
 SX_FIELD("timestamp","int32",32,4,SX_TIME),
 SX_FIELD("action","uint32",36,4,SX_ID),
 SX_FIELD("name","char[256]",40,256,SX_STRING),
 SX_FIELD("old_timestamp","int32",296,4,SX_TIME),
 SX_FIELD("old_size","uint32",300,4,SX_SIZE),
 SX_FIELD("new_timestamp","int32",304,4,SX_TIME),
 SX_FIELD("new_size","uint32",308,4,SX_SIZE),
};
const sx_layout sxmx_pod2_audit={UINT32_C(0x602E0010),"pod2_audit",sxmx_pod2_audit_fields,SX_COUNT(sxmx_pod2_audit_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_pod(sxmx_view*v)
{if(!SM_ROW(pod2_header,0,v->n))return false;uint32_t n=sxmx_u32(v->p+88,false),a=sxmx_u32(v->p+92,false);uint64_t bytes=(uint64_t)a*312;if(bytes>v->n)return false;return sxmx_table(v,&sxmx_pod2_entry,96,n,v->n)&&sxmx_table(v,&sxmx_pod2_audit,v->n-(size_t)bytes,a,v->n);}
bool sx_terminalreality_pod_build(sxmx_view*v)
{
 return sxmx_pod(v);
}
#undef SM_ROW
