/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pjl data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdw_pjl_command_fields[]={
 SX_FIELD("pjl_command","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_pjl_command={0x60740021U,"documentwire_pjl_command",sxdw_pjl_command_fields,SX_COUNT(sxdw_pjl_command_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_parameter_fields[]={
 SX_FIELD("pjl_parameter","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_pjl_parameter={0x60740022U,"documentwire_pjl_parameter",sxdw_pjl_parameter_fields,SX_COUNT(sxdw_pjl_parameter_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_value_fields[]={
 SX_FIELD("pjl_value","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_pjl_value={0x60740023U,"documentwire_pjl_value",sxdw_pjl_value_fields,SX_COUNT(sxdw_pjl_value_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_text_fields[]={
 SX_FIELD("pjl_text","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_pjl_text={0x60740024U,"documentwire_pjl_text",sxdw_pjl_text_fields,SX_COUNT(sxdw_pjl_text_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_pjl_uel_fields[]={
 SX_FIELD("universal_exit_language","uint8[9]",0,9,SX_SIGNATURE),
};
const sx_layout sxdw_pjl_uel={0x6074002eU,"documentwire_pjl_uel",sxdw_pjl_uel_fields,SX_COUNT(sxdw_pjl_uel_fields),SX_LE};
#define DW_VALUE(name,a,n) sxdw_value(q,&sxdw_##name,a,n)
static bool sxdw_pjl(sxdw_cursor*q)
{
 int64_t end=9;while(end<q->n&&q->b[end])end++;int64_t total=q->n;q->n=end;q->p=0;
 while(q->p<q->n&&q->c->count<32000){if(sxdw_prefix(q,q->p,q->n,"\033%-12345X")){if(!sxdw_emit(q,&sxdw_pjl_uel,q->p,9))return false;q->p+=9;continue;}
  int64_t a,e;if(!sxdw_line(q,&a,&e))break;if(sxdw_prefix(q,a,e,"@PJL")){int64_t p=a+4;while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;int64_t b=p;while(p<e&&q->b[p]!=' '&&q->b[p]!='\t')p++;if(!DW_VALUE(pjl_command,b,p-b))return false;
   while(p<e){while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;b=p;while(p<e&&q->b[p]!='='&&q->b[p]!=' '&&q->b[p]!='\t')p++;if(!DW_VALUE(pjl_parameter,b,p-b))return false;while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;if(p<e&&q->b[p]=='='){p++;while(p<e&&(q->b[p]==' '||q->b[p]=='\t'))p++;b=p;if(p<e&&q->b[p]=='"'){p++;while(p<e&&q->b[p]!='"')p++;if(p<e)p++;}else while(p<e&&q->b[p]!=' '&&q->b[p]!='\t')p++;if(!DW_VALUE(pjl_value,b,p-b))return false;}if(p==b&&p<e)p++;}
  }else if(!DW_VALUE(pjl_text,a,e-a))return false;
 }q->n=total;return !xx_pd_is_stopped(q->c->pd);
}
bool sx_pjl_build(sxdw_cursor*q)
{
 return sxdw_pjl(q);
}
#undef DW_VALUE
