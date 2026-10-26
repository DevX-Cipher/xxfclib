/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ISAKMP MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_isakmp(sxnm_view *v)
{
 if(!SN_ROW(isakmp_header,0,v->n)||!SN_ROW(isakmp_sa_payload,28,v->n)||sxnm_u32(v->p+24)!=v->n||sxnm_u16(v->p+30)!=v->n-28)return false;size_t p=40;
 while(p<v->n){if(!SN_ROW(isakmp_proposal,p,v->n))return false;size_t n=sxnm_u16(v->p+p+2);if(n<8||!sxnm_need(v,p,n,v->n))return false;size_t end=p+n,t=p+8+v->p[p+6];unsigned count=v->p[p+7];if(t>end)return false;
  for(unsigned j=0;j<count;j++){if(!SN_ROW(isakmp_transform,t,end))return false;size_t z=sxnm_u16(v->p+t+2);if(z<8||!sxnm_need(v,t,z,end))return false;size_t te=t+z,a=t+8;
   while(a<te){if(!sxnm_need(v,a,4,te))return false;bool basic=(v->p[a]&128)!=0;if(!sxnm_row(v,basic?&sxnm_isakmp_basic_attribute:&sxnm_isakmp_variable_attribute,a,te))return false;size_t extra=basic?0:sxnm_u16(v->p+a+2);a+=4;if(!sxnm_need(v,a,extra,te))return false;a+=extra;}t=te;
  }if(t!=end)return false;p=end;
 }return true;
}
bool sx_isakmp_message_build(sxnm_view*v)
{
 return sxnm_isakmp(v);
}
#undef SN_ROW
