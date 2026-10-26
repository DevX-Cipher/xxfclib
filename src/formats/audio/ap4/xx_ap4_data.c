/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AP4 audio packages data structures, moved out of the audiolater schema family. */
#include "../../xx_format_schema_audiolater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaul_ap4_table_fields[] = {
    SX_FIELD("marker0","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("marker1","uint8",1,1,SX_SIGNATURE),
    SX_FIELD("count_copy","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("marker3","uint8",3,1,SX_SIGNATURE),
    SX_FIELD("records","uint8",4,1,SX_COUNT_PROP),
};
const sx_layout sxaul_ap4_table = {UINT32_C(0x60380096),"ap4_table",sxaul_ap4_table_fields,SX_COUNT(sxaul_ap4_table_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_ap4_entry_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_bytes","uint32",4,4,SX_SIZE),
    SX_FIELD("flags","uint8",8,1,SX_FLAGS),
};
const sx_layout sxaul_ap4_entry = {UINT32_C(0x60380097),"ap4_entry",sxaul_ap4_entry_fields,SX_COUNT(sxaul_ap4_entry_fields),SX_BE};
#define AL(n,k) do{if(!sxaul_take(c,&sxaul_##n,&at,end,(k)))return false;}while(0)
#define N(p,w) sxaul_num(c,(p),(w),false)
#define B(p,w) sxaul_num(c,(p),(w),true)
static bool sxaul_ap4(sx_context*c)
{
 /* Match the native bounded table search, leaving non-table prefix bytes raw. */
 int64_t at=0,end=c->size,first=-1,limit=end;uint8_t block[4100];
 while(at+5<=limit&&c->count<31000&&!xx_pd_is_stopped(c->pd)){
  int64_t search=first<0?65536:first+67108864;if(search>limit)search=limit;
  bool found=false;
  while(at+5<=search){
   if(xx_pd_is_stopped(c->pd))return false;
   size_t n=(size_t)(search-at>4100?4100:search-at);if(!sx_read(c,at,block,n))return false;
   size_t i=0;for(;i+5<=n;i++)if(!block[i]&&block[i+1]==1&&block[i+3]==1&&block[i+2]==block[i+4]){at+=(int64_t)i;found=true;break;}
   if(found)break;at+=(int64_t)(n-4);
  }
  if(!found)break;uint32_t count=N(at+4,1);int64_t start=at;
  if((uint64_t)count*9+5>(uint64_t)(limit-at))break;
  AL(ap4_table,1);
  for(uint32_t i=0;i<count;i++){
   uint32_t off=B(at+9*i,4),size=B(at+9*i+4,4);
   if(size&&off&&(uint64_t)off+size<=(uint64_t)end&&off<limit)limit=off;
  }
  AL(ap4_entry,count);if(count&&first<0)first=start;
 }return !c->failed&&c->count>0;
}
bool sx_ap4_build(sx_context*c)
{
 return sxaul_ap4(c)&&sxaul_finish(c);
}
#undef AL
#undef N
#undef B
