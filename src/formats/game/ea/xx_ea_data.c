/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ea data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_ea(sxga_view*v)
{uint64_t end=v->c->size,at=0,n;while(at<end){if(!GA_ROW(ea_entry,at,end)||!sxga_word(v,at+25,4,false,&n,end)||!sxga_span(v,at+48,n,end))return false;at+=48+n;}return true;}
bool sx_ea_build(sxga_view*v)
{
 return sxga_ea(v);
}
#undef GA_ROW
