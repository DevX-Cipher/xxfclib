/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pink_pretracker_prt data structures, moved out of the amigamore schema family. */
#include "../../../xx_format_schema_amigamore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamore_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
const sx_layout sxamore_text={UINT32_C(0x60950001),"text",sxamore_text_fields,SX_COUNT(sxamore_text_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_nul_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_ID),
};
const sx_layout sxamore_nul={UINT32_C(0x60950002),"nul",sxamore_nul_fields,SX_COUNT(sxamore_nul_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_subsong_count_fields[]={
 SX_FIELD("subsong_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxamore_prt_subsong_count={UINT32_C(0x60950009),"prt_subsong_count",sxamore_prt_subsong_count_fields,SX_COUNT(sxamore_prt_subsong_count_fields),SX_LE};
#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
static bool sxamore_text_emit(sxamore_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxamore_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxamore_text,(int64_t)p,(int64_t)n);}
#define AM_TAKE(l,p,n,end) sxamore_take(v,&sxamore_##l,(p),(n),(end))
/* The format's 23-byte field is a bounded byte string, not assumed UTF-8. */
static bool sxamore_name(sxamore_view*v,uint64_t*p,uint64_t end)
{uint64_t start=*p,x;for(unsigned i=0;i<23;i++){if(!sxamore_be(v,*p,1,&x,end))return false;if(!x){if(!sxamore_text_emit(v,start,*p-start,end)||!AM_TAKE(nul,p,1,end))return false;return true;}++*p;}return sxamore_text_emit(v,start,23,end);}
static bool sxamore_prt(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,version,pos,pat,inst,wave,nins,nwave;
 if(!sxamore_eq(v,0,"PRT",3,e)||!sxamore_be(v,3,1,&version,e)||(version!=25&&version!=27&&version!=30)||!sxamore_be(v,4,4,&pos,e)||!sxamore_be(v,8,4,&pat,e)||!sxamore_be(v,12,4,&inst,e)||!sxamore_be(v,16,4,&wave,e)||!sxamore_be(v,64,1,&nins,e)||!nins||nins>64||!sxamore_be(v,65,1,&nwave,e)||nwave>24 )return false;
 if(!sxamore_row(v,version==30?&sxamore_prt_header30:&sxamore_prt_header,0,e))return false;
 if(version>=27&&!AM_ROW(prt_generation_order,66,e))return false;
 if(pos<66||pat<66||inst<66||wave<66||pos>e||pat>e||inst>e||wave>e)return false;
 if(version==30){
  uint64_t songs;if(!sxamore_be(v,90,1,&songs,e)||!songs||!AM_ROW(prt_subsong_count,90,e))return false;
  for(uint64_t i=0;i<songs;i++){
   uint64_t patterns,rows,positions,rel;
   if(!sxamore_be(v,pos+1,1,&patterns,e)||!sxamore_be(v,pos+2,1,&rows,e)||!sxamore_be(v,pos+3,1,&positions,e)||!sxamore_be(v,pos+4,4,&rel,e)||!patterns||!rows||!positions||rel>e-pat||!AM_TAKE(prt_subsong,&pos,1,e)||!AM_TAKE(prt_position,&pos,positions*4,e)||!sxamore_table(v,&sxamore_prt_pattern,pat+rel,patterns*rows,e))return false;
  }
 }else{
  uint64_t patterns,rows,positions;if(!sxamore_be(v,61,1,&patterns,e)||!patterns||!sxamore_be(v,62,1,&positions,e)||!positions||!sxamore_be(v,63,1,&rows,e)||!rows||!sxamore_table(v,&sxamore_prt_position,pos,positions*4,e)||!sxamore_table(v,&sxamore_prt_pattern,pat,patterns*rows,e))return false;
 }
 uint64_t p=inst;for(unsigned i=0;i<(version==30?64U:32U);i++)if(!sxamore_name(v,&p,e))return false;
 uint64_t info=p;if(!AM_TAKE(prt_instrument,&p,nins,e))return false;
 for(uint64_t i=0;i<nins;i++){uint64_t steps;if(!sxamore_be(v,info+i*8+7,1,&steps,e)||!AM_TAKE(prt_instrument_pattern,&p,steps,e))return false;}
 p=wave;for(unsigned i=0;i<24;i++)if(!sxamore_name(v,&p,e))return false;
 if(p&1){if(p==e)return false;p++;}return AM_TAKE(prt_wave,&p,nwave,e);
}
bool sx_pink_pretracker_prt_build(sxamore_view*v)
{
 return sxamore_prt(v);
}
#undef AM_ROW
#undef AM_TAKE
