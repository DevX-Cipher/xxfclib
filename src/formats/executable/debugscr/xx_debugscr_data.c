/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * debugscr data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_debug(sxtw_cursor*q)
{
 bool count=false;int64_t a,end;while(sxtw_line(q,&a,&end)){
  if(q->c->count>=32000)return true;sxtw_trim(q,&a,&end);if(a==end)continue;
  if(count){uint64_t v;if(!sxtw_number(q,a,end-a,16,&v))break;TW_EMIT(hex_size,a,end-a);count=false;continue;}
  if(sxtw_ci(q,a,end-a,"rcx")||sxtw_ci(q,a,end-a,"r cx")){TW_EMIT(command,a,end-a);count=true;continue;}
  unsigned c=q->b[a]|32;TW_EMIT(command,a,1);int64_t p=a+1;while(p<end&&sxtw_space(q->b[p]))p++;
  if(c=='n'){TW_EMIT(name,p,end-p);}
  else if(c=='e'){int64_t start=p;while(p<end&&!sxtw_space(q->b[p]))p++;uint64_t v;if(!sxtw_number(q,start,p-start,16,&v))return false;TW_EMIT(address_hex,start,p-start);
   while(p<end){while(p<end&&sxtw_space(q->b[p]))p++;if(end-p<2||!sxtw_number(q,p,2,16,&v))break;if(end-p>2&&sxtw_number(q,p+2,1,16,&v))break;TW_EMIT(hex_byte,p,2);p+=2;if(q->c->count>=32000)return true;}
  }
 }return true;
}
bool sx_debugscr_build(sxtw_cursor*q)
{
 return sxtw_debug(q);
}
#undef TW_EMIT
