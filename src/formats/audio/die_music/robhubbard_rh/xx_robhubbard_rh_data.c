/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * robhubbard_rh data structures, moved out of the amigamore schema family. */
#include "../../../xx_format_schema_amigamore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamore_end_word_fields[]={
 SX_FIELD("end_marker","uint16",0,2,SX_ID),
};
const sx_layout sxamore_end_word={UINT32_C(0x60950005),"end_word",sxamore_end_word_fields,SX_COUNT(sxamore_end_word_fields),SX_BE};
#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
static bool sxamore_skip(sxamore_view*v,uint64_t*p,uint64_t n,uint64_t end)
{if(!sxamore_span(v,*p,n,end))return false;*p+=n;return true;}
#define AM_TAKE(l,p,n,end) sxamore_take(v,&sxamore_##l,(p),(n),(end))
/* The anchors below are the original loaders' operand sequences. Search caps
   bound corrupted cached-valid readers; no code is executed or relocated. */
static bool sxamore_rh(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=64,n,operand=54,samples,sub=130,x;
 for(unsigned i=0;i<5;i++)if(!sxamore_be(v,i*4,2,&x,e)||x!=0x6000)return false;
 if(!sxamore_eq(v,20,"\x41\xfa",2,e)||!sxamore_eq(v,28,"\x4e\x75\x41\xfa",4,e)||!sxamore_find(v,&p,e<80?e:80,0x2418,2,2)||!sxamore_be(v,p-1,1,&n,e)||!sxamore_find(v,&operand,e<64?e:64,0x41fa,2,2))return false;
 operand+=2;if(!sxamore_signed16(v,operand,operand,&samples,e)||!sxamore_be(v,operand+2,2,&x,e))return false;if(x==0xd1fc){if(!sxamore_span(v,samples,64,e))return false;samples+=64;}
 if(!sxamore_find(v,&sub,e<150?e:150,0x41eb,2,2))return false;sub+=2;
 uint64_t song;if(!sxamore_signed16(v,sub,0,&song,e)||!sxamore_span(v,song,18,e)||!AM_ROW(rh_sample_count,p-1,e)||!AM_ROW(signed_displacement,operand,e)||!AM_ROW(signed_displacement,sub,e))return false;
 p=samples;for(uint64_t i=0;i<=n;i++){uint64_t bytes;if(!sxamore_be(v,p,4,&bytes,e)||bytes>65536||!AM_TAKE(rh_sample,&p,1,e)||!sxamore_skip(v,&p,bytes,e))return false;}
 if(!sxamore_be(v,p,2,&x,e)||x!=0x4e71||!AM_ROW(end_word,p,e))return false;
 for(unsigned i=0;i<4096;i++,song+=18){if(!AM_ROW(rh_subsong,song,e)||!sxamore_be(v,song+18,2,&x,e))return false;if(!x)return AM_ROW(end_word,song+18,e);}
 return false;
}
bool sx_robhubbard_rh_build(sxamore_view*v)
{
 return sxamore_rh(v);
}
#undef AM_ROW
#undef AM_TAKE
