/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * agis data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_agis(sxga_view*v)
{uint64_t end=v->c->size,at=0,n;while(at<end){if(!GA_ROW(agis_entry,at,end)||!sxga_word(v,at+14,4,false,&n,end)||n<31||!sxga_span(v,at,n,end))return false;at+=n;}return true;}
bool sx_agis_build(sxga_view*v)
{
 return sxga_agis(v);
}
#undef GA_ROW
