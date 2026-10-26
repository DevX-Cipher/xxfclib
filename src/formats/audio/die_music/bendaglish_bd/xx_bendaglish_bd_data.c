/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bendaglish_bd data structures, moved out of the codeplayers schema family. */
#include "../../../xx_format_schema_codeplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SCP_PUT(n,p,c) sxcodeplayers_put(v,&sxcodeplayers_##n,p,c)
static bool sxcodeplayers_bd(sxcodeplayers_view*v){
 uint64_t init,play,sub,smp,table,tracks;size_t a=SIZE_MAX,b=SIZE_MAX,p;
 if(!sxcodeplayers_eq(v,0,"\x60\0",2)||!sxcodeplayers_eq(v,4,"\x60\0",2)||!sxcodeplayers_eq(v,10,"\x60\0",2)||!sxcodeplayers_ref(v,2,&init)||!sxcodeplayers_ref(v,6,&play)||!sxcodeplayers_eq(v,(size_t)init,"\x3f\0\x61\0",4)||!sxcodeplayers_eq(v,(size_t)init+6,"\x3d\x7c",2)||!sxcodeplayers_eq(v,(size_t)init+12,"\x41\xfa",2))return false;
 for(p=(size_t)init;p+6<=v->code_size;p+=2)if(sxcodeplayers_eq(v,p,"\x41\xfa",2)&&sxcodeplayers_eq(v,p+4,"\x22\x08",2)){a=p;break;}
 if(a==SIZE_MAX||!sxcodeplayers_ref(v,a+2,&sub))return false;
 for(p=a+4;p+6<=v->code_size;p+=2)if(sxcodeplayers_eq(v,p,"\x41\xfa",2)&&sxcodeplayers_eq(v,p+4,"\x23\x48",2)){b=p;break;}
 if(b==SIZE_MAX||!sxcodeplayers_ref(v,b+2,&smp))return false;
 a=SIZE_MAX;for(p=(size_t)play;p+6<=v->code_size;p+=2)if(sxcodeplayers_eq(v,p,"\x47\xfa",2)&&(sxcodeplayers_eq(v,p+4,"\x48\x80",2)||sxcodeplayers_eq(v,p+4,"\xd0\x40",2))){a=p;break;}
 if(a==SIZE_MAX||!sxcodeplayers_ref(v,a+2,&table))return false;
 b=SIZE_MAX;for(p=a+4;p+6<=v->code_size;p+=2)if(sxcodeplayers_eq(v,p,"\x47\xfa",2)&&sxcodeplayers_eq(v,p+4,"\xd6\xc0",2)){b=p;break;}
 if(b==SIZE_MAX||!sxcodeplayers_ref(v,b+2,&tracks))return false;
 uint64_t end=v->end,pos=sub;for(unsigned i=0;i<256&&pos<end;i++,pos+=8){uint8_t row[8];if(!sxcodeplayers_read(v,pos,row,8))break;bool good=true;for(unsigned j=0;j<4;j++){uint64_t off=sxcodeplayers_be16(row+2*j);if(off>v->end-sub||off<8){good=false;break;}if(sub+off<end)end=sub+off;}if(!good||pos>end||8>end-pos)break;if(!SCP_PUT(bd_subsong,pos,1))return false;}
 if(table<sub&&(sub-table)%2==0&&(sub-table)/2<=4096&&!SCP_PUT(bd_track_offset,table,(sub-table)/2))return false;
 uint64_t offsets[256],n=0,first=v->end-smp;
 while(n<256&&n*4<first){uint64_t x;if(!sxcodeplayers_u(v,smp+n*4,4,&x)||x<4||x>v->end-smp)break;if(x<first)first=x;if((n+1)*4>first)break;offsets[n++]=x;}
 if(!n||n*4!=first)return true;if(!SCP_PUT(bd_sample_offset,smp,n))return false;
 for(uint64_t i=0;i<n;i++)if(sxcodeplayers_span(v,smp+offsets[i],28)&&!SCP_PUT(bd_sample,smp+offsets[i],1))return false;
 (void)tracks;return true;
}
bool sx_bendaglish_bd_build(sxcodeplayers_view*v)
{
 return sxcodeplayers_bd(v);
}
#undef SCP_PUT
