/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * smtp_transcript data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_smtp(sxtw_cursor*q)
{
 bool body=false;int64_t a,end;while(sxtw_line(q,&a,&end)){
  if(q->c->count>=32000)return true;
  if(body){if(sxtw_eq(q,a,end-a,".")){TW_EMIT(command,a,1);body=false;}continue;}
  int64_t split=a;while(split<end&&q->b[split]!=' '&&q->b[split]!=':')split++;TW_EMIT(command,a,split-a);if(split<end){TW_EMIT(field_value,split+1,end-split-1);}if(sxtw_ci(q,a,end-a,"DATA"))body=true;
 }return !body;
}
bool sx_smtp_transcript_build(sxtw_cursor*q)
{
 return sxtw_smtp(q);
}
#undef TW_EMIT
