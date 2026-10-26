/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * wux data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_wux(sxga_view*v)
{uint64_t end=v->c->size,z,n;if(!GA_ROW(wux_header,0,end)||!sxga_word(v,8,4,false,&z,end)||!z||!sxga_word(v,16,8,false,&n,end))return false;return sxga_table(v,&sxga_wux_block,32,n/z+(n%z!=0),end);}
bool sx_wux_build(sxga_view*v)
{
 return sxga_wux(v);
}
#undef GA_ROW
