/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pbo data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_pbo(sxga_view*v)
{uint64_t end=v->c->size,at=0,method;while(at<end){uint64_t start=at;if(!sxga_cstring(v,&at,end,4097)||!sxga_named(v,start,at-start,end,false)||!GA_ROW(pbo_entry,at,end)||!sxga_word(v,at,4,false,&method,end))return false;bool empty=at==start+1;at+=20;if(empty&&method==0x56657273){for(;;){start=at;if(!sxga_cstring(v,&at,end,4097)||!sxga_named(v,start,at-start,end,false))return false;if(at==start+1)break;start=at;if(!sxga_cstring(v,&at,end,4097)||!sxga_named(v,start,at-start,end,false))return false;}continue;}if(empty)return true;}return false;}
bool sx_pbo_build(sxga_view*v)
{
 return sxga_pbo(v);
}
#undef GA_ROW
