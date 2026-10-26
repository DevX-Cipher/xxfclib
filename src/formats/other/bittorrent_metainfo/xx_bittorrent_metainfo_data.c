/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bittorrent_metainfo data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_key_fields[]={
 SX_FIELD("key","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_key={0x6071000bU,"textwire_key",sxtw_key_fields,SX_COUNT(sxtw_key_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
/* Bencode keys and length/integer spellings have physical contiguous spans.
 * String payloads may be arbitrary bytes; only dictionary keys are text. */
static bool sxtw_bstring(sxtw_cursor*q,int64_t*a,int64_t*z,bool key)
{
 int64_t start=q->p;while(q->p<q->n&&q->b[q->p]>='0'&&q->b[q->p]<='9')q->p++;uint64_t n;if(q->p==q->n||q->b[q->p]!=':'||!sxtw_number(q,start,q->p-start,10,&n))return false;TW_EMIT(byte_length,start,q->p-start);q->p++;if(n>(uint64_t)(q->n-q->p))return false;*a=q->p;*z=(int64_t)n;if(key){TW_EMIT(key,*a,*z);}q->p+=(int64_t)n;return true;
}
static bool sxtw_bvalue(sxtw_cursor*q,unsigned depth,const sx_layout*value)
{
 if(q->c->count>=32000)return true;if(depth>40||q->p>=q->n)return false;unsigned c=q->b[q->p];
 if(c=='i'){TW_EMIT(control,q->p,1);int64_t a=++q->p;while(q->p<q->n&&q->b[q->p]!='e')q->p++;if(q->p==q->n)return false;if(!sxtw_emit(q,value?value:&sxtw_integer_value,a,q->p-a))return false;TW_EMIT(control,q->p,1);q->p++;return true;}
 if(c>='0'&&c<='9'){int64_t a,z;return sxtw_bstring(q,&a,&z,false);}
 if(c!='d'&&c!='l')return false;TW_EMIT(control,q->p,1);q->p++;
 while(q->p<q->n&&q->b[q->p]!='e'){
  const sx_layout*l=NULL;if(c=='d'){int64_t a,z;if(!sxtw_bstring(q,&a,&z,true))return false;if(sxtw_eq(q,a,z,"length")||sxtw_eq(q,a,z,"piece length"))l=&sxtw_declared_size;}
  if(!sxtw_bvalue(q,depth+1,l))return false;if(q->c->count>=32000)return true;
 }
 if(q->p==q->n)return false;TW_EMIT(control,q->p,1);q->p++;return true;
}
bool sx_bittorrent_metainfo_build(sxtw_cursor*q)
{
 return sxtw_bvalue(q,0,NULL);
}
#undef TW_EMIT
