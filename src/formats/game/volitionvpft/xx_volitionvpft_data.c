/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * volitionvpft data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_vp(sxga_view*v)
{uint64_t end=v->c->size,n,at;if(!GA_ROW(vp_header,0,end)||!sxga_word(v,8,4,false,&at,end)||!sxga_word(v,12,4,false,&n,end))return false;return sxga_table(v,&sxga_vp_entry,at,n,end);}
bool sx_volitionvpft_build(sxga_view*v)
{
 return sxga_vp(v);
}
#undef GA_ROW
