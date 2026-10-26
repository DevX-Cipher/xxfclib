/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nitroplus_npk2 data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_npk2(sxgco_view*v)
{return GC_ROW(npk2_header,0,(uint64_t)v->c->size);}
bool sx_nitroplus_npk2_build(sxgco_view*v)
{
 return sxgco_npk2(v);
}
#undef GC_ROW
