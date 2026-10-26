/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Paul van der Valk's Medley Sound Editor module (.MSO) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
static bool sxamip_relative_target32(sxamip_view*v,uint64_t at,uint64_t*out,uint64_t end)
{
 uint64_t x;if(!sxamip_be(v,at,4,&x,end))return false;int64_t d=x&0x80000000U?(int64_t)x-INT64_C(4294967296):(int64_t)x;
 if(d<0){if(at<(uint64_t)(-d))return false;*out=at-(uint64_t)(-d);}else{if((uint64_t)d>end-at)return false;*out=at+(uint64_t)d;}return *out<=end;
}
static bool sxamip_mso(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,table,n,target;
 if(!sxamip_eq(v,0,"MSOB",4,e)||!AP_ROW(mso_header,0,e))return false;
 for(unsigned i=0;i<4;i++)if(!sxamip_relative_target32(v,4+4*i,&target,e))return false;
 if(!sxamip_relative_target32(v,4,&table,e))return false;
 /* Replay compares its byte song index with the low byte of this word. */
 if(table<2||!sxamip_be(v,table-2,2,&n,e)||!AP_ROW(count16,table-2,e)||n>255||!sxamip_span(v,table,4*(n+1),e))return false;
 for(uint64_t i=1;i<=n;i++){
  uint64_t at=table+i*4;if(!sxamip_relative_target32(v,at,&target,e)||!AP_ROW(relative32,at,e))return false;
 }
 return true;
}
bool sx_vdvalk_medleysound_mso_build(sxamip_view*v)
{
 return sxamip_mso(v);
}
#undef AP_ROW
