/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Gameboy Ripped Format chiptune (.GBR) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_gbr(sxmr_view*v)
{uint64_t n,end=v->c->size;if(!sxmr_eq(v,0,"GBRF",4,end)||!sxmr_u(v,4,1,&n,end)||!n||!MR_ROW(gbr_header,0,end))return false;return sxmr_span(v,32,n*16384,end);}
bool sx_gameboy_rippedformat_build(sxmr_view*v)
{
 return sxmr_gbr(v);
}
#undef MR_ROW
