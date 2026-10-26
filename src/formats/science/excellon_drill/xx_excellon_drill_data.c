/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * excellon drill data structures, moved out of the vectortext schema family. */
#include "../../xx_format_schema_vectortext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvtx_tool_number_fields[]={
 SX_FIELD("tool_number","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_tool_number={0x60620048U,"vectortext_tool_number",sxvtx_tool_number_fields,SX_COUNT(sxvtx_tool_number_fields),SX_LE};
static bool sxvtx_line(sxvtx_cursor*q,int64_t*a,int64_t*end,bool comments){while(q->p<q->n){int64_t start=q->p,stop;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;stop=q->p;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;if(comments){bool quoted=false;for(int64_t i=start;i<stop;i++){if(q->b[i]=='\\'&&quoted&&i+1<stop){i++;continue;}if(q->b[i]=='"')quoted=!quoted;if(q->b[i]=='#'&&!quoted){stop=i;break;}}}while(start<stop&&sxvtx_space(q->b[start]))start++;while(stop>start&&sxvtx_space(q->b[stop-1]))stop--;if(start<stop){*a=start;*end=stop;return !xx_pd_is_stopped(q->c->pd);}}return false;}
#define VT_EMIT(n,a,z) do{if(!sxvtx_emit(q,&sxvtx_##n,(a),(z)))return false;}while(0)
/* Gerber/Excellon coordinates are encoded decimal integers. Suppression and
 * scale are recorded separately: emitted digits are never silently rescaled. */
static bool sxvtx_drill(sxvtx_cursor*q)
{
 int64_t a,end;while(sxvtx_line(q,&a,&end,false)){if(q->c->count>=32000)return true;if(q->b[a]==';')continue;
  if(sxvtx_eq(q,a,end-a,"INCH,LZ")||sxvtx_eq(q,a,end-a,"INCH,TZ")||sxvtx_eq(q,a,end-a,"METRIC,LZ")||sxvtx_eq(q,a,end-a,"METRIC,TZ")){int64_t n=q->b[a]=='I'?4:6;VT_EMIT(units,a,n);VT_EMIT(zero_suppression,a+n+1,2);continue;}
  if(q->b[a]=='%'){VT_EMIT(keyword,a,1);continue;}
  while(a<end){while(a<end&&sxvtx_space(q->b[a]))a++;if(a==end)break;unsigned key=q->b[a];VT_EMIT(keyword,a,1);int64_t value=++a;while(value<end&&sxvtx_space(q->b[value]))value++;a=value;if(a<end&&(q->b[a]=='+'||q->b[a]=='-'))a++;
   while(a<end&&((q->b[a]>='0'&&q->b[a]<='9')||q->b[a]=='.'||q->b[a]=='e'||q->b[a]=='E'||((q->b[a]=='+'||q->b[a]=='-')&&a>value&&(q->b[a-1]=='e'||q->b[a-1]=='E'))))a++;
   const sx_layout*l=key=='T'?&sxvtx_tool_number:key=='C'?&sxvtx_diameter:key=='X'?&sxvtx_encoded_x:key=='Y'?&sxvtx_encoded_y:&sxvtx_command_code;if(!sxvtx_emit(q,l,value,a-value))return false;
  }
 }
 return true;
}
bool sx_excellon_drill_build(sxvtx_cursor*q)
{
 return sxvtx_drill(q);
}
#undef VT_EMIT
