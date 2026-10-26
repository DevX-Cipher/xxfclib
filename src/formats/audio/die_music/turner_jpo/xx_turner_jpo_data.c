/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Steve Turner's module (.JPO) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
static bool sxamip_turner_target(uint64_t stored,uint64_t origin,uint64_t extra,uint64_t end,uint64_t*out)
{if(stored<origin){uint64_t d=origin-stored;if(d>extra)return false;*out=extra-d;}else{uint64_t d=stored-origin;if(d>end||extra>end-d)return false;*out=d+extra;}return *out<=end;}
static bool sxamip_turner(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,origin,sub,trk,smp,a,p,z,n;
 if(!sxamip_span(v,0,46,e))return false;
 for(unsigned i=0;i<4;i++)if(!sxamip_eq(v,i*8,"\x2b\x7c",2,e)||!AP_ROW(turner_address,2+i*8,e))return false;
 if(!sxamip_eq(v,32,"\x30\x3c\0\xff\x32\0\x4e\xb9",8,e)||!sxamip_eq(v,44,"\x4e\x75",2,e)||!sxamip_be(v,2,4,&origin,e)||origin<46||!sxamip_be(v,10,4,&a,e)||!sxamip_turner_target(a,origin,46,e,&sub)||!sxamip_be(v,18,4,&a,e)||!sxamip_turner_target(a,origin,46,e,&trk)||!sxamip_be(v,26,4,&a,e)||!sxamip_turner_target(a,origin,20,e,&smp))return false;
 p=sub;for(unsigned i=0;i<4096;i++){
  if(!sxamip_be(v,p,2,&a,e))return false;if(a&0xfff0)break;
  if(!AP_ROW(turner_subsong,p,e))return false;
  for(unsigned k=4;k<12;k+=2){uint64_t target;if(!sxamip_be(v,p+k,2,&a,e))return false;if(a&&(!sxamip_signed16_target(v,p+k,sub,&target,e)||!sxamip_span(v,target,1,e)))return false;}
  p+=12;if(i==4095)return false;
 }
 /* The source's sample-information prefix lies26 bytes before its pointer table. */
 if(!sxamip_be(v,smp,4,&n,e)||!n||(n&3)||n/4>4096||!AP_ROW(turner_sample_table,smp,e))return false;
 p=smp+26;if(!sxamip_span(v,p,n,e))return false;
 for(uint64_t i=0;i<n/4;i++){
  if(!sxamip_be(v,p+i*4,4,&a,e)||!AP_ROW(turner_sample_offset,p+i*4,e))return false;
  if(!a)continue;if(a>e-p||!sxamip_be(v,p+a,2,&z,e)||p+a<6||!sxamip_span(v,p+a-6,z+8,e)||!AP_ROW(turner_sample_length,p+a,e))return false;
 }
 /* Track opcodes remain raw: the independent source does not expose a
    version-independent decoded-event table for this stored address. */
 return sxamip_span(v,trk,2,e);
}
bool sx_turner_jpo_build(sxamip_view*v)
{
 return sxamip_turner(v);
}
#undef AP_ROW
