/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * putty_ppk data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_algorithm_fields[]={
 SX_FIELD("algorithm","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_algorithm={0x6071000fU,"textwire_algorithm",sxtw_algorithm_fields,SX_COUNT(sxtw_algorithm_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_mac_text_fields[]={
 SX_FIELD("mac_text","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_mac_text={0x60710014U,"textwire_mac_text",sxtw_mac_text_fields,SX_COUNT(sxtw_mac_text_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_line_count_fields[]={
 SX_FIELD("line_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxtw_line_count={0x6071002bU,"textwire_line_count",sxtw_line_count_fields,SX_COUNT(sxtw_line_count_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_ppk(sxtw_cursor*q)
{
 int64_t a,end;uint64_t encoded=0;
 while(sxtw_line(q,&a,&end)){
  if(q->c->count>=32000)return true;
  if(encoded){TW_EMIT(base64_text,a,end-a);encoded--;continue;}
  if(end-a>21&&sxtw_eq(q,a,20,"PuTTY-User-Key-File-")){TW_EMIT(signature,a,20);TW_EMIT(version,a+20,1);int64_t p=a+21;while(p<end&&(q->b[p]==':'||q->b[p]==' '))p++;TW_EMIT(algorithm,p,end-p);continue;}
  int64_t c=a;while(c<end&&q->b[c]!=':')c++;if(c==end)return false;TW_EMIT(field_name,a,c-a);int64_t v=c+1;sxtw_trim(q,&v,&end);
  if(sxtw_eq(q,a,c-a,"Public-Lines")||sxtw_eq(q,a,c-a,"Private-Lines")){if(!sxtw_number(q,v,end-v,10,&encoded)||encoded>1024)return false;TW_EMIT(line_count,v,end-v);}
  else if(sxtw_eq(q,a,c-a,"Private-MAC")){TW_EMIT(mac_text,v,end-v);}
  else if(sxtw_eq(q,a,c-a,"Encryption")){TW_EMIT(encryption,v,end-v);}
  else{TW_EMIT(field_value,v,end-v);}
 }return encoded==0;
}
bool sx_putty_ppk_build(sxtw_cursor*q)
{
 return sxtw_ppk(q);
}
#undef TW_EMIT
