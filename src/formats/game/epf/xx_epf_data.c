/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * epf data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_epf(sxga_view*v)
{uint64_t end=v->c->size,at,n;return GA_ROW(epf_header,0,end)&&sxga_word(v,4,4,false,&at,end)&&sxga_word(v,9,2,false,&n,end)&&sxga_table(v,&sxga_epf_entry,at,n,end);}
bool sx_epf_build(sxga_view*v)
{
 return sxga_epf(v);
}
#undef GA_ROW
