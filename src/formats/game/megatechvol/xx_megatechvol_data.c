/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * megatechvol data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxgco_megavol(sxgco_view*v)
{uint64_t n,e=v->c->size;return sxgco_word(v,0,4,false,&n,e)&&n>=8&&!(n&3)&&sxgco_table(v,&sxgco_offset32,0,n/4,e);}
bool sx_megatechvol_build(sxgco_view*v)
{
 return sxgco_megavol(v);
}
