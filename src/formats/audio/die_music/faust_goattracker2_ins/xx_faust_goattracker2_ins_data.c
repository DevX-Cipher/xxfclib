/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Lasse 'Faust' Oorni's GoatTracker 2 Instrument (.INS) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_faust_goattracker2_ins_build(sxmn_view*v)
{
 return sxmn_goat(v,true);
}
