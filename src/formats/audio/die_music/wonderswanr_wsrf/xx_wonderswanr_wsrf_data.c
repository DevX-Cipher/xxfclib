/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WonderSwan R programmatic chiptune (.WSR) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_wsr(sxmr_view*v)
{uint64_t end=v->c->size;if(end<32||!sxmr_eq(v,end-32,"WSRF",4,end)||!sxmr_eq(v,end-16,"\xea",1,end))return false;return MR_ROW(wsr_footer,end-32,end);}
bool sx_wonderswanr_wsrf_build(sxmr_view*v)
{
 return sxmr_wsr(v);
}
#undef MR_ROW
