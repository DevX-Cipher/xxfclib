/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * majiro data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_majiro(sxga_view*v)
{uint64_t end=v->c->size,version,n,at,data;if(!GA_ROW(majiro_header,0,end)||!sxga_word(v,10,1,false,&version,end)||!sxga_word(v,16,4,false,&n,end)||!sxga_word(v,20,4,false,&at,end)||!sxga_word(v,24,4,false,&data,end)||data>end)return false;const sx_layout*l=version=='1'?&sxga_majiro_entry1:version=='2'?&sxga_majiro_entry2:&sxga_majiro_entry3;if(!sxga_table(v,l,28,n+(version=='1'),end))return false;for(uint64_t i=0;i<n;i++){uint64_t start=at;if(!sxga_cstring(v,&at,data,4097)||!sxga_named(v,start,at-start,data,false))return false;}return true;}
bool sx_majiro_build(sxga_view*v)
{
 return sxga_majiro(v);
}
#undef GA_ROW
