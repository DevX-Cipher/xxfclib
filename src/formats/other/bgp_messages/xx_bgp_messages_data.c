/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BGP MESSAGES data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_bgp(sxnm_view *v)
{
 size_t at=0;
 for(unsigned msg=0;at<v->n;msg++){
  if(msg>=128||!SN_ROW(bgp_message_header,at,v->n))return false;size_t n=sxnm_u16(v->p+at+16);if(n<19||!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;
  if(v->p[at+18]==1){if(!SN_ROW(bgp_open,at+19,end))return false;size_t p=at+29;if(v->p[at+28]!=end-p)return false;
   while(p<end){if(!SN_ROW(bgp_optional_parameter,p,end))return false;size_t pe=p+2+v->p[p+1];if(pe>end)return false;unsigned type=v->p[p];p+=2;if(type==2)while(p<pe){if(!SN_ROW(bgp_capability_header,p,pe))return false;size_t ncap=v->p[p+1];p+=2;if(!sxnm_need(v,p,ncap,pe))return false;p+=ncap;}p=pe;}
  }at=end;
 }return at==v->n;
}
bool sx_bgp_messages_build(sxnm_view*v)
{
 return sxnm_bgp(v);
}
#undef SN_ROW
