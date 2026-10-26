/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * clermonte_frededitor_final data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_fred_final(sxnextm_view*v)
{uint64_t e=(uint64_t)v->c->size,init,p,module=0,base=0,word,inst,track,n,at;bool found=false;
 if(e<0xb0e)return false;for(unsigned i=0;i<4;i++)if(!sxnextm_eq(v,i*4,"\x4e\xfa",2,e))return false;
 if(!sxnextm_rel(v,2,2,2,&init,e)||!sxnextm_span(v,init,128,e))return false;
 for(unsigned i=0;i<4;i++){p=init+i*2;if(sxnextm_eq(v,p,"\x12\x3a",2,e)&&sxnextm_eq(v,p+4,"\xb0\x01",2,e)){if(!sxnextm_rel(v,p+2,2,p+1,&module,e))return false;found=true;break;}}
 if(!found)return false;found=false;for(;p<init+120;p+=2)if(sxnextm_eq(v,p,"\x47\xfa",2,e)&&sxnextm_eq(v,p+4,"\xd7\xfa",2,e)){if(!sxnextm_rel(v,p+2,2,p+2,&base,e))return false;found=true;break;}
 if(!found||!NX_ROW(fred_final_header,module,e)||!sxnextm_u(v,module+1,1,&n,e)||n>=10)return false;n++;
 if(!sxnextm_be(v,module+14,4,&word,e)||word>e-base)return false;inst=base+word;if(!sxnextm_be(v,module+18,4,&word,e)||word>e-base)return false;track=base+word;
 at=module+22;if(!sxnextm_skip(v,&at,612,e)||!NX_TAKE(fred_final_subsong,&at,n,e))return false;uint64_t end=inst<track?inst:track;
 if(at>end||(end-at)%2)return false;while(at<end){if(!sxnextm_be(v,at,2,&word,end)||!sxnextm_take(v,word&0x8000?&sxnextm_fred_final_control:&sxnextm_fred_final_position,&at,1,end))return false;}
 /* The source locates the end of the instrument array by its sample pointers
    and a documented legacy sentinel; incomplete/ambiguous tail stays raw. */
 uint64_t sample_begin=e;for(p=inst;p<sample_begin;){uint64_t off,type,test;if(!sxnextm_span(v,p,64,sample_begin))break;if(!sxnextm_be(v,p,4,&off,e)||!sxnextm_be(v,p+4,2,&test,e)||!sxnextm_u(v,p+39,1,&type,e))return false;
  if(type!=255){if(!off){if(test==0xfcf5)break;if(test!=65535&&type!=0)break;}else{if(off>e-base)break;uint64_t dest=base+off;if(dest<p+64)break;if(dest<sample_begin)sample_begin=dest;}}
  if(!NX_TAKE(fred_final_instrument,&p,1,sample_begin))return false;}
 return true;}
bool sx_clermonte_frededitor_final_build(sxnextm_view*v)
{
 return sxnextm_fred_final(v);
}
#undef NX_ROW
#undef NX_TAKE
