/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Tero 'kometbomb' Lindeman's Klystrack effects (.KF?) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_kometbomb_klystrack_fx_build(sxmw_view*v)
{
 return sxmw_kly(v,2);
}
