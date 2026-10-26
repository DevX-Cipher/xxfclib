/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bgi data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxgco_bgi(sxgco_view*v){return sxgco_bgi_common(v,false);}
bool sx_bgi_build(sxgco_view*v)
{
 return sxgco_bgi(v);
}
