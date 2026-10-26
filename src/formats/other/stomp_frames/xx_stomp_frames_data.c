/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * stomp_frames data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_stomp(sxtw_cursor*q)
{
 while(q->p<q->n){if(q->c->count>=32000)return true;int64_t a,end;if(!sxtw_line(q,&a,&end))return false;TW_EMIT(command,a,end-a);uint64_t bytes=0;bool length=false;
  while(sxtw_line(q,&a,&end)&&a!=end){int64_t c=a;while(c<end&&q->b[c]!=':')c++;if(c==end)return false;TW_EMIT(field_name,a,c-a);
   if(sxtw_eq(q,a,c-a,"content-length")){uint64_t v;if(!sxtw_number(q,c+1,end-c-1,10,&v))return false;if(!length){bytes=v;length=true;}TW_EMIT(content_length,c+1,end-c-1);}
   else{TW_EMIT(field_value,c+1,end-c-1);}if(q->c->count>=32000)return true;
  }
  if(length){if(bytes>(uint64_t)(q->n-q->p))return false;q->p+=(int64_t)bytes;}else while(q->p<q->n&&q->b[q->p])q->p++;
  if(q->p==q->n||q->b[q->p])return false;TW_EMIT(control,q->p,1);q->p++;while(q->p<q->n&&(q->b[q->p]=='\r'||q->b[q->p]=='\n'))q->p++;
 }return true;
}
bool sx_stomp_frames_build(sxtw_cursor*q)
{
 return sxtw_stomp(q);
}
#undef TW_EMIT
