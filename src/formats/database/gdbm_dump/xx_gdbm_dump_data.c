/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gdbm_dump data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_record_count_fields[]={
 SX_FIELD("record_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxtw_record_count={0x6071003dU,"textwire_record_count",sxtw_record_count_fields,SX_COUNT(sxtw_record_count_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_gdbm(sxtw_cursor*q)
{
 int64_t a,end;while(sxtw_line(q,&a,&end)){
  if(q->c->count>=32000)return true;
  if(end-a>6&&sxtw_eq(q,a,6,"#:len=")){TW_EMIT(byte_length,a+6,end-a-6);continue;}
  if(end-a>8&&sxtw_eq(q,a,8,"#:count=")){TW_EMIT(record_count,a+8,end-a-8);continue;}
  if(end-a>2&&sxtw_eq(q,a,2,"#:")){int64_t p=a+2;while(p<end){int64_t k=p;while(p<end&&q->b[p]!='=')p++;if(p==end)break;int64_t kn=p-k,v=++p;while(p<end&&q->b[p]!=',')p++;TW_EMIT(field_name,k,kn);const sx_layout*l=sxtw_eq(q,k,kn,"uid")?&sxtw_uid:sxtw_eq(q,k,kn,"gid")?&sxtw_gid:sxtw_eq(q,k,kn,"mode")?&sxtw_octal_mode:sxtw_eq(q,k,kn,"version")?&sxtw_version:sxtw_eq(q,k,kn,"file")?&sxtw_path:&sxtw_field_value;if(!sxtw_emit(q,l,v,p-v))return false;if(p<end)p++;}continue;}
  if(a<end&&q->b[a]=='#'){TW_EMIT(text,a,end-a);}else{TW_EMIT(base64_text,a,end-a);}
 }return true;
}
bool sx_gdbm_dump_build(sxtw_cursor*q)
{
 return sxtw_gdbm(q);
}
#undef TW_EMIT
