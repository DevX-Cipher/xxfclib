/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * subz3ro's AdLib Tracker II module (.A2T) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_subz3ro_adlibtracker2_tiny_build(sxmn_view*v)
{
 return sxmn_a2(v,true);
}
