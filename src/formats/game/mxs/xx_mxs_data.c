/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * mxs data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_mxs(sxgco_view*v)
{uint64_t p=0,e=v->c->size,n;while(p<e){if(!GC_ROW(mxs_entry,p,e)||!sxgco_word(v,p,4,false,&n,e)||n<4||!sxgco_span(v,p+17,n,e))return false;p+=17+n;}return p==e;}
bool sx_mxs_build(sxgco_view*v)
{
 return sxgco_mxs(v);
}
#undef GC_ROW
