/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * David 'Talin' Joiner & Joe Pearce's MaxTrax/Music-X module (MXTX.+SMPL.) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamip_count32_fields[]={
 SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxamip_count32={UINT32_C(0x60900003),"count32",sxamip_count32_fields,SX_COUNT(sxamip_count32_fields),SX_BE};
#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
#define AP_TAKE(l,p,n,end) sxamip_take(v,&sxamip_##l,(p),(n),(end))
static bool sxamip_mxtx(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=8,flags,n,z,samples;
 if(!sxamip_eq(v,0,"MXTX",4,e)||!AP_ROW(mxtx_header,0,e)||!sxamip_be(v,6,2,&flags,e))return false;
 /* The retained microtonal loader's read and skip byte counts disagree.
    Preserve only the known prefix instead of inventing its table extent. */
 if(flags&0x8000)return true;
 if(!sxamip_be(v,p,2,&n,e)||!AP_TAKE(count16,&p,1,e))return false;
 for(uint64_t i=0;i<n;i++){if(!sxamip_be(v,p,4,&z,e)||!AP_TAKE(count32,&p,1,e)||!AP_TAKE(mxtx_event,&p,z,e))return false;}
 if(!sxamip_be(v,p,2,&samples,e)||!AP_TAKE(count16,&p,1,e))return false;
 for(uint64_t i=0;i<samples;i++){
  uint64_t oct,a,b,na,nr;
  if(!sxamip_span(v,p,20,e)||!sxamip_be(v,p+6,2,&oct,e)||!sxamip_be(v,p+8,4,&a,e)||!sxamip_be(v,p+12,4,&b,e)||!sxamip_be(v,p+16,2,&na,e)||!sxamip_be(v,p+18,2,&nr,e)||!AP_TAKE(mxtx_sample,&p,1,e)||!AP_TAKE(mxtx_envelope,&p,na+nr,e))return false;
  z=a+b;if(oct>64&&z)return false;
  for(uint64_t k=0;k<oct&&z;k++){if(!sxamip_skip(v,&p,z,e))return false;if(k+1<oct){if(z>UINT64_MAX/2)return false;z*=2;}}
 }
 return true;
}
bool sx_talin_maxtrax_musicx_build(sxamip_view*v)
{
 return sxamip_mxtx(v);
}
#undef AP_ROW
#undef AP_TAKE
