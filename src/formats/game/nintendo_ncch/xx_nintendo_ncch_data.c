/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_ncch data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxgp_ncch(sxgp_view*v){return sxgp_ncch_at(v,0,(uint64_t)v->c->size,true);}
bool sx_nintendo_ncch_build(sxgp_view*v)
{
 return sxgp_ncch(v);
}
