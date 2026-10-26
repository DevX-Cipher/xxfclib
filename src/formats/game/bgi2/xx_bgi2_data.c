/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bgi2 data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxgco_bgi2(sxgco_view*v){return sxgco_bgi_common(v,true);}
bool sx_bgi2_build(sxgco_view*v)
{
 return sxgco_bgi2(v);
}
