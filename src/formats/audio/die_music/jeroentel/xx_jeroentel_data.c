/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jeroentel data structures, moved out of the amigamore schema family. */
#include "../../../xx_format_schema_amigamore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
static bool sxamore_jt(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=0,period_address,period_at,origin,op[5],info_table,subsong,address;
 if(!sxamore_find(v,&p,e,UINT64_C(0x1400e302),4,2)||!sxamore_be(v,p+6,4,&period_address,e))return false;op[0]=p+6;
 if(!sxamore_find(v,&p,e,UINT64_C(0x03580328),4,2)||period_address<p)return false;period_at=p;origin=period_address-period_at;
 p=0;uint64_t a=0,b=0;bool aa=sxamore_find(v,&a,e,UINT64_C(0xb23c00ff),4,2),bb=sxamore_find(v,&b,e,UINT64_C(0x0c0100ff),4,2);if(!aa&&!bb)return false;p=aa&&(!bb||a<b)?a:b;
 if(!sxamore_find(v,&p,e,0x267c,2,2))return false;op[1]=p+2;p+=6;
 if(!sxamore_find(v,&p,e,0x49f9,2,2))return false;op[2]=p+2;if(!sxamore_be(v,p+2,4,&address,e)||!sxamore_map(address,origin,e,&info_table))return false;p+=6;
 if(!sxamore_find(v,&p,e,UINT64_C(0x0026267c),4,2))return false;op[3]=p+4;p+=8;
 if(!sxamore_find(v,&p,e,0x23f4,2,2)||p<4)return false;op[4]=p-4;if(!sxamore_be(v,p-4,4,&address,e)||!sxamore_map(address,origin,e,&subsong))return false;
 uint64_t first;if(!sxamore_be(v,info_table,4,&address,e)||!sxamore_map(address,origin,e,&first)||first<=info_table||(first-info_table)%4||(first-info_table)/4>4096)return false;
 for(unsigned i=0;i<5;i++)if(!AM_ROW(original_address,op[i],e))return false;
 bool seen=false;for(unsigned i=0;i<4096;i++,subsong+=18){uint64_t marker,channels[4];if(!sxamore_be(v,subsong+16,1,&marker,e))return false;if(marker!=12)break;for(unsigned j=0;j<4;j++)if(!sxamore_be(v,subsong+j*4,4,&channels[j],e))return false;if(channels[0]==channels[1]&&channels[0]==channels[2]&&channels[0]==channels[3])break;if(!AM_ROW(jt_subsong,subsong,e))return false;seen=true;}
 if(!seen)return false;
 for(uint64_t row=info_table;row<first;row+=4){uint64_t at,length,data;if(!sxamore_be(v,row,4,&address,e)||!sxamore_map(address,origin,e,&at)||!sxamore_be(v,at+2,2,&length,e)||!sxamore_be(v,at+4,4,&address,e)||!AM_ROW(original_address,row,e)||!AM_ROW(jt_sample,at,e))return false;if(address&&(!sxamore_map(address,origin,e,&data)||!sxamore_span(v,data,length*2,e)))return false;}
 return true;
}
bool sx_jeroentel_build(sxamore_view*v)
{
 return sxamore_jt(v);
}
#undef AM_ROW
