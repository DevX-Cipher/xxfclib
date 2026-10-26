/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NoteTab data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdw_notetab_option_fields[]={
 SX_FIELD("notetab_option","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_notetab_option={0x6074001eU,"documentwire_notetab_option",sxdw_notetab_option_fields,SX_COUNT(sxdw_notetab_option_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_notetab_heading_fields[]={
 SX_FIELD("notetab_heading","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_notetab_heading={0x6074001fU,"documentwire_notetab_heading",sxdw_notetab_heading_fields,SX_COUNT(sxdw_notetab_heading_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_notetab_body_line_fields[]={
 SX_FIELD("notetab_body_line","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_notetab_body_line={0x60740020U,"documentwire_notetab_body_line",sxdw_notetab_body_line_fields,SX_COUNT(sxdw_notetab_body_line_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_notetab_declaration_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","ascii_signed[1]",3,1,SX_NONE),
};
const sx_layout sxdw_notetab_declaration={0x6074002dU,"documentwire_notetab_declaration",sxdw_notetab_declaration_fields,SX_COUNT(sxdw_notetab_declaration_fields),SX_LE};
#define DW_VALUE(name,a,n) sxdw_value(q,&sxdw_##name,a,n)
static bool sxdw_notetab(sxdw_cursor*q)
{
 int64_t a,e;if(!sxdw_line(q,&a,&e)||e<5||!sxdw_emit(q,&sxdw_notetab_declaration,0,4)||!DW_VALUE(notetab_option,5,e-5)||!sxdw_line(q,&a,&e))return false;
 int64_t body=q->p;bool quoted=false;while(sxdw_line(q,&a,&e))if(sxdw_prefix(q,a,e,"H=\"")){quoted=true;break;}q->p=body;bool heading=false;
 while(q->c->count<32000&&sxdw_line(q,&a,&e)){int64_t tag=quoted?3:2;if(sxdw_prefix(q,a,e,quoted?"H=\"":"H=")){int64_t end=e;if(quoted&&end>a+tag&&q->b[end-1]=='"')end--;if(!DW_VALUE(notetab_heading,a+tag,end-a-tag))return false;heading=true;}
  else if(heading&&!DW_VALUE(notetab_body_line,a,e-a))return false;}return !xx_pd_is_stopped(q->c->pd);
}
bool sx_notetab_build(sxdw_cursor*q)
{
 return sxdw_notetab(q);
}
#undef DW_VALUE
