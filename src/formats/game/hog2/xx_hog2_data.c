/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * hog2 data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_hog(sxga_view*v)
{uint64_t end=v->c->size,n;if(!GA_ROW(hog2_header,0,end)||!sxga_word(v,4,4,false,&n,end))return false;return sxga_table(v,&sxga_hog2_entry,68,n,end);}
bool sx_hog2_build(sxga_view*v)
{
 return sxga_hog(v);
}
#undef GA_ROW
