/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Mark Cooksey's module (.MC) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
static bool sxamip_find_word(sxamip_view*v,uint64_t*p,uint16_t wanted,uint64_t end)
{for(;*p+2<=end;*p+=2){uint64_t x;if(!sxamip_be(v,*p,2,&x,end))return false;if(x==wanted)return true;}return false;}
static bool sxamip_cooksey(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,lim=e<1048576?e:1048576,p,sub,subend,info,samples;
 if(!sxamip_eq(v,0,"\xd0\x40\xd0\x40\x4e\xfb",6,e))return false;
 for(unsigned i=8;i<=20;i+=4)if(!sxamip_eq(v,i,"\x60\0",2,e))return false;
 p=sxamip_eq(v,40,"\x43\xfa",2,e)?40:150;
 if(!sxamip_eq(v,p,"\x43\xfa",2,e))return false;p+=2;
 if(!sxamip_signed16_target(v,p,p,&sub,e)||!AP_ROW(cooksey_displacement,p,e))return false;
 uint64_t scan=p;if(!sxamip_find_word(v,&scan,0x43fa,lim))return false;scan+=2;
 if(!sxamip_signed16_target(v,scan,scan,&subend,e)||subend<sub||(subend-sub)%16||!AP_ROW(cooksey_displacement,scan,e)||!sxamip_span(v,sub,subend-sub,e))return false;
 p=scan;
 for(;;){if(!sxamip_span(v,p,6,lim))return false;if(sxamip_eq(v,p,"\0\0\x41\xfa",4,lim))break;p+=2;}
 p+=4;if(!sxamip_signed16_target(v,p,p,&info,e)||!AP_ROW(cooksey_displacement,p,e))return false;
 scan=p;if(!sxamip_find_word(v,&scan,0x43fa,lim))return false;scan+=2;
 if(!sxamip_signed16_target(v,scan,scan,&samples,e)||!AP_ROW(cooksey_displacement,scan,e))return false;
 uint64_t first;if(!sxamip_be(v,info,2,&first,e)||(first&1)||!first||first>=32768||first/2>4096||!sxamip_span(v,info,first,e))return false;
 for(uint64_t i=0;i<first/2;i++){
  uint64_t at=info+i*2,row,x,z;if(!sxamip_signed16_target(v,at,at,&row,e)||!AP_ROW(cooksey_sample_offset,at,e))return false;
  if(!sxamip_be(v,row,4,&x,e))return false;
  if(x){if(!sxamip_be(v,row+16,2,&z,e)||!AP_ROW(cooksey_sample,row,e))return false;}
  else{if(!sxamip_be(v,row+4,4,&x,e)||!sxamip_be(v,row+18,2,&z,e)||!AP_ROW(cooksey_shifted_sample,row,e))return false;}
  if(x>e-samples||!sxamip_span(v,samples+x,z*2,e))return false;
 }
 return true;
}
bool sx_mark_cooksey_build(sxamip_view*v)
{
 return sxamip_cooksey(v);
}
#undef AP_ROW
