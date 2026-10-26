/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dxa data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_dxa(sxgco_view*v)
{unsigned version=(unsigned char)v->c->f->version[0]-'0';if(version>=1&&version<=3)return GC_ROW(dxa_header1,0,v->c->size);if(version==4)return GC_ROW(dxa_header4,0,v->c->size);if(version==6)return GC_ROW(dxa_header6,0,v->c->size);return false;}
bool sx_dxa_build(sxgco_view*v)
{
 return sxgco_dxa(v);
}
#undef GC_ROW
