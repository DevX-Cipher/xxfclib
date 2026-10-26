/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * hpgl plot data structures, moved out of the vectortext schema family. */
#include "../../xx_format_schema_vectortext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvtx_line_width_fields[]={
 SX_FIELD("line_width","ascii_real",0,0,SX_NONE),
};
const sx_layout sxvtx_line_width={0x6062004eU,"vectortext_line_width",sxvtx_line_width_fields,SX_COUNT(sxvtx_line_width_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_radius_fields[]={
 SX_FIELD("radius","ascii_real",0,0,SX_NONE),
};
const sx_layout sxvtx_radius={0x60620075U,"vectortext_radius",sxvtx_radius_fields,SX_COUNT(sxvtx_radius_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_pen_number_fields[]={
 SX_FIELD("pen_number","ascii_real",0,0,SX_NONE),
};
const sx_layout sxvtx_pen_number={0x60620077U,"vectortext_pen_number",sxvtx_pen_number_fields,SX_COUNT(sxvtx_pen_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_label_terminator_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_NONE),
};
const sx_layout sxvtx_label_terminator={0x60620079U,"vectortext_label_terminator",sxvtx_label_terminator_fields,SX_COUNT(sxvtx_label_terminator_fields),SX_LE};
#define VT_EMIT(n,a,z) do{if(!sxvtx_emit(q,&sxvtx_##n,(a),(z)))return false;}while(0)
static bool sxvtx_hpgl(sxvtx_cursor*q)
{
 int64_t p=0;unsigned terminator=3;
 while(p<q->n){if(q->c->count>=32000)return true;while(p<q->n&&sxvtx_space(q->b[p]))p++;if(p==q->n)break;if(q->n-p<2)return false;int64_t key=p;VT_EMIT(keyword,key,2);p+=2;
  if(sxvtx_eq(q,key,2,"LB")){int64_t a=p;while(p<q->n&&q->b[p]!=terminator)p++;if(p==q->n)return false;VT_EMIT(string_value,a,p-a);p++;if(p<q->n&&q->b[p]==';')p++;continue;}
  int64_t end=p;while(end<q->n&&q->b[end]!=';')end++;if(end==q->n)return false;
  if(sxvtx_eq(q,key,2,"DT")){if(end-p>1)return false;if(end>p){terminator=q->b[p];VT_EMIT(label_terminator,p,1);}else terminator=3;}
  else {unsigned i=0;while(p<end){while(p<end&&(sxvtx_space(q->b[p])||q->b[p]==','))p++;int64_t a=p;while(p<end&&q->b[p]!=',')p++;int64_t stop=p;while(stop>a&&sxvtx_space(q->b[stop-1]))stop--;const sx_layout*l=&sxvtx_real_value;
    if(sxvtx_eq(q,key,2,"PA")||sxvtx_eq(q,key,2,"PR")||sxvtx_eq(q,key,2,"PU")||sxvtx_eq(q,key,2,"PD"))l=i%2?&sxvtx_y:&sxvtx_x;
    else if(sxvtx_eq(q,key,2,"SP"))l=&sxvtx_pen_number;
    else if(sxvtx_eq(q,key,2,"CI")&&i==0)l=&sxvtx_radius;
    else if(sxvtx_eq(q,key,2,"PW")&&i==0)l=&sxvtx_line_width;
    if(!sxvtx_emit(q,l,a,stop-a))return false;i++;}}
  p=end+1;
 }
 return true;
}
bool sx_hpgl_plot_build(sxvtx_cursor*q)
{
 return sxvtx_hpgl(q);
}
#undef VT_EMIT
