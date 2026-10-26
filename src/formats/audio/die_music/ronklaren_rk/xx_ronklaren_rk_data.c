/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ronklaren_rk data structures, moved out of the amigamore schema family. */
#include "../../../xx_format_schema_amigamore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamore_rk_selector_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("subsong","uint16",2,2,SX_ID),
 SX_FIELD("branch_code","bytes",4,4,SX_NONE),
};
const sx_layout sxamore_rk_selector={UINT32_C(0x6095001D),"rk_selector",sxamore_rk_selector_fields,SX_COUNT(sxamore_rk_selector_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_position_end_fields[]={
 SX_FIELD("end_marker","int32",0,4,SX_ID),
};
const sx_layout sxamore_rk_position_end={UINT32_C(0x60950020),"rk_position_end",sxamore_rk_position_end_fields,SX_COUNT(sxamore_rk_position_end_fields),SX_BE};
#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
#define AM_TAKE(l,p,n,end) sxamore_take(v,&sxamore_##l,(p),(n),(end))
static bool sxamore_rk(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,x,words,alloc,p=64,jumps=0,songs=0,irq=0,init=0,targets[2]={0,0};
 if(!sxamore_be(v,0,4,&x,e)||x!=1011||!sxamore_be(v,4,4,&x,e)||x||!sxamore_be(v,8,4,&x,e)||x!=1||!sxamore_be(v,12,4,&x,e)||x||!sxamore_be(v,16,4,&x,e)||x||!sxamore_be(v,20,4,&alloc,e)||!sxamore_be(v,24,4,&x,e)||(x&0x3fffffff)!=1001||!sxamore_be(v,28,4,&words,e)||words<656||words>(alloc&0x3fffffff)||!sxamore_span(v,32,words*4,e)||!sxamore_eq(v,40,"RON_KLAREN_SOUNDMODULE!\0",23,e))return false;
 uint64_t end=32+words*4,scan_end=end<2656?end:2656;
 while(jumps<128&&sxamore_be(v,p,2,&x,scan_end)&&x==0x4ef9){uint64_t off;if(!sxamore_be(v,p+2,4,&off,scan_end)||off>=words*4)return false;if(jumps<2)targets[jumps]=32+off;jumps++;p+=6;}
 if(jumps<2)return false;uint64_t selectors=p;
 while(songs<128&&sxamore_be(v,p,2,&x,scan_end)&&x==0x303c){if(!sxamore_span(v,p,8,scan_end))return false;songs++;p+=8;}
 if(!songs)return false;
 for(unsigned i=0;i<2;i++){if(!sxamore_be(v,targets[i],2,&x,scan_end))return false;if(x==0x6100||x==0x33fc){init=targets[i];break;}}
 uint64_t writes_at[128];unsigned writes_kind[128],nwrites=0;uint64_t cia_lo=0,cia_hi=0;
 if(init){
  p=init;for(unsigned i=0;i<1024;i++,p+=2){if(!sxamore_be(v,p,2,&x,scan_end))return false;if(x==0x4e75)break;
   if(x==0x13fc){uint64_t value,reg;if(!sxamore_be(v,p+2,2,&value,scan_end)||!sxamore_be(v,p+4,4,&reg,scan_end))return false;if(reg==0xbfd400)cia_lo=value&255;if(reg==0xbfd500)cia_hi=value&255;if(nwrites<128){writes_at[nwrites]=p;writes_kind[nwrites++]=0;}p+=6;
   }else if(x==0x23fc){uint64_t off,reg;if(!sxamore_be(v,p+2,4,&off,scan_end)||!sxamore_be(v,p+6,4,&reg,scan_end))return false;if(reg==0x78){if(off>=words*4)return false;irq=32+off;if(nwrites<128){writes_at[nwrites]=p;writes_kind[nwrites++]=1;}}p+=8;}
  }
  if(!irq||!(cia_lo|cia_hi))return false;
 }else{irq=targets[1];if(!sxamore_be(v,irq,2,&x,scan_end)||x!=0x41fa)return false;}
 p=irq;if(!sxamore_find(v,&p,scan_end,0x41fa,2,2))return false;uint64_t global,global_op=p+2;if(!sxamore_signed16(v,p+2,p+2,&global,end))return false;p+=4;
 uint64_t index_op=0;
 for(unsigned i=0;i<1024;i++,p+=2){if(!sxamore_be(v,p,2,&x,scan_end))return false;if(x==0x4e73||x==0x4e75)return false;if(sxamore_eq(v,p,"\x02\x40\x00\x0f\x53\x40\xe9\x48\x47\xf0",10,scan_end)){index_op=p+10;break;}}
 /* This loader's published variant uses D0.w and a nonnegative brief
    displacement. Other index-register/full-extension forms stay raw. */
 if(!index_op||!sxamore_be(v,index_op,2,&x,scan_end)||x>127||global>end||x>end-global)return false;uint64_t table=global+x;
 if(!sxamore_span(v,table,songs*16,end)||!AM_ROW(rk_hunk_header,0,e)||!sxamore_table(v,&sxamore_rk_jump,64,jumps,scan_end)||!sxamore_table(v,&sxamore_rk_selector,selectors,songs,scan_end)||!AM_ROW(signed_displacement,global_op,scan_end)||!AM_ROW(rk_index_extension,index_op,scan_end)||!sxamore_table(v,&sxamore_rk_subsong,table,songs,end))return false;
 for(unsigned i=0;i<nwrites;i++)if(!sxamore_row(v,writes_kind[i]?&sxamore_rk_vector_write:&sxamore_rk_cia_write,writes_at[i],scan_end))return false;
 for(uint64_t i=0;i<songs*4;i++){
  uint64_t off;if(!sxamore_be(v,table+i*4,4,&off,end)||off>words*4)return false;p=32+off;
  for(unsigned j=0;j<4096;j++){
   if(!sxamore_be(v,p,4,&x,end))return false;if(x&UINT64_C(0x80000000)){if(!AM_ROW(rk_position_end,p,end))return false;break;}
   if(x>=words*4||!AM_TAKE(rk_position,&p,1,end))return false;if(j==4095)return false;
  }
 }
 return true;
}
bool sx_ronklaren_rk_build(sxamore_view*v)
{
 return sxamore_rk(v);
}
#undef AM_ROW
#undef AM_TAKE
