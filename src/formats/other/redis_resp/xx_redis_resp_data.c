/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * redis_resp data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_array_count_fields[]={
 SX_FIELD("array_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxtw_array_count={0x60710027U,"textwire_array_count",sxtw_array_count_fields,SX_COUNT(sxtw_array_count_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_resp(sxtw_cursor*q)
{
 while(q->p<q->n){if(q->c->count>=32000)return true;int64_t a,end;uint64_t count;
  if(!sxtw_line(q,&a,&end)||a==end||q->b[a]!='*'||!sxtw_number(q,a+1,end-a-1,10,&count)||count>1024)return false;TW_EMIT(control,a,1);TW_EMIT(array_count,a+1,end-a-1);
  for(uint64_t i=0;i<count;i++){uint64_t n;if(!sxtw_line(q,&a,&end)||a==end||q->b[a]!='$'||!sxtw_number(q,a+1,end-a-1,10,&n))return false;TW_EMIT(control,a,1);TW_EMIT(byte_length,a+1,end-a-1);if(n>(uint64_t)(q->n-q->p)||q->n-q->p-(int64_t)n<2)return false;if(!i){TW_EMIT(command,q->p,(int64_t)n);}q->p+=(int64_t)n;if(q->b[q->p]!='\r'||q->b[q->p+1]!='\n')return false;q->p+=2;if(q->c->count>=32000)return true;}
 }return true;
}
bool sx_redis_resp_build(sxtw_cursor*q)
{
 return sxtw_resp(q);
}
#undef TW_EMIT
