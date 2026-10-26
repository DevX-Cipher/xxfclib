/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * rsc data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxgco_rsc(sxgco_view*v){return sxgco_counted(v,&sxgco_rsc_entry);}
bool sx_rsc_build(sxgco_view*v)
{
 return sxgco_rsc(v);
}
