/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * wallybeben data structures, moved out of the amigamore schema family. */
#include "../../../xx_format_schema_amigamore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
static bool sxamore_wb(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=0,after,address,origin,n,table,operands[3];
 if(!sxamore_eq(v,0,"\x60\x00",2,e)||!sxamore_eq(v,4,"\x48\xe7\xff\xfe\x61\x00\x00",7,e)||!sxamore_eq(v,12,"\x4c\xdf\x7f\xff\x4e\x75",6,e)||!sxamore_find(v,&p,e,0x4e75,2,2))return false;after=p+2;
 if(!sxamore_find(v,&p,e,0x1039,2,2))return false;p+=2;operands[0]=p;if(!sxamore_be(v,p,4,&address,e)||address<after)return false;origin=address-after;
 p+=4;if(!sxamore_find(v,&p,e,0x223c,2,2))return false;p+=2;operands[1]=p;if(!sxamore_be(v,p,4,&n,e)||n<2||n>4097)return false;n--;
 p+=4;if(!sxamore_find(v,&p,e,0x41f9,2,2))return false;p+=2;operands[2]=p;if(!sxamore_be(v,p,4,&address,e)||!sxamore_map(address,origin,e,&table)||!sxamore_span(v,table,n*16,e))return false;
 uint64_t minimum=e;for(uint64_t j=0;j<n*4;j++){uint64_t target;if(!sxamore_be(v,table+j*4,4,&address,e)||!sxamore_map(address,origin,e,&target))return false;if(target<minimum)minimum=target;}
 uint64_t end=table+n*16;if(minimum<end||(minimum-end)%4)return false;
 if(!AM_ROW(original_address,operands[0],e)||!AM_ROW(wb_count,operands[1],e)||!AM_ROW(original_address,operands[2],e)||!sxamore_table(v,&sxamore_wb_subsong,table,n,e)||!sxamore_table(v,&sxamore_original_address,end,(minimum-end)/4,e))return false;
 return true;
}
bool sx_wallybeben_build(sxamore_view*v)
{
 return sxamore_wb(v);
}
#undef AM_ROW
