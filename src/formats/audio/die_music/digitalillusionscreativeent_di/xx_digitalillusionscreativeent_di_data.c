/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * digitalillusionscreativeent_di data structures, moved out of the modvariants schema family. */
#include "../../../xx_format_schema_modvariants.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmodv_di_header_fields[]={
 SX_FIELD("sample_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("order_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("pattern_data_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("sample_data_offset","uint32",10,4,SX_OFFSET),
};
const sx_layout sxmodv_di_header={UINT32_C(0x609B0001),"di_header",sxmodv_di_header_fields,SX_COUNT(sxmodv_di_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_di_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmodv_di_pattern_offset={UINT32_C(0x609B0003),"di_pattern_offset",sxmodv_di_pattern_offset_fields,SX_COUNT(sxmodv_di_pattern_offset_fields),SX_BE};
#define SMV_ROW(n,p) sxmodv_row(v,&sxmodv_##n,p)
static bool sxmodv_di_pattern(sxmodv_view*v,uint64_t p,uint64_t limit){
 if(p>=limit||limit>v->end)return false;
 for(unsigned row=0;row<64;row++){bool stop=false;for(unsigned ch=0;ch<4;ch++){
  uint64_t a,b;unsigned n;if(!sxmodv_word(v,p,1,&a))return false;
  if(a==255){if(p>=limit||!SMV_ROW(di_blank,p))return false;p++;continue;}
  n=a<128?2:3;if(p>limit||n>limit-p||!sxmodv_word(v,p+1,1,&b))return false;
  if((b&15)==11||(b&15)==13)stop=true;
  if(!sxmodv_row(v,n==2?&sxmodv_di_event:&sxmodv_di_event_value,p))return false;p+=n;
 }if(stop)break;}return true;
}
static bool sxmodv_di(sxmodv_view*v){
 uint64_t ns,orders,patterns,samples,x,np=0,norder=0,table,ends;
 if(!SMV_ROW(di_header,0)||!sxmodv_word(v,0,2,&ns)||ns>31||!sxmodv_word(v,2,4,&orders)||!sxmodv_word(v,6,4,&patterns)||!sxmodv_word(v,10,4,&samples))return false;
 table=14+ns*8;if(orders<table||patterns<=orders||samples<=patterns||samples>v->end||patterns-orders>129||!sxmodv_span(v,14,ns*8))return false;
 for(uint64_t i=0;i<ns;i++)if(!SMV_ROW(mod_compact_sample,14+i*8))return false;
 ends=orders;for(;ends<patterns&&norder<128;ends++,norder++){if(!sxmodv_word(v,ends,1,&x))return false;if(x==255)break;if(x>=128)return false;if(np<x+1)np=x+1;if(!SMV_ROW(mod_order,ends))return false;}
 if(!sxmodv_word(v,ends,1,&x)||x!=255||ends+1!=patterns||!SMV_ROW(di_orders_end,ends)||!np||np*2>orders-table)return false;
 uint64_t pointers[128];for(uint64_t i=0;i<np;i++){if(!sxmodv_word(v,table+i*2,2,&pointers[i])||!SMV_ROW(di_pattern_offset,table+i*2))return false;}
 for(uint64_t i=0;i<np;i++){
  uint64_t p=pointers[i],end=samples;bool duplicate=false;for(uint64_t j=0;j<i;j++)if(pointers[j]==p)duplicate=true;if(duplicate||p<patterns||p>=samples)continue;
  for(uint64_t j=0;j<np;j++)if(pointers[j]>p&&pointers[j]<end)end=pointers[j];
  (void)sxmodv_di_pattern(v,p,end);
 }return true;
}
bool sx_digitalillusionscreativeent_di_build(sxmodv_view*v)
{
 return sxmodv_di(v);
}
#undef SMV_ROW
