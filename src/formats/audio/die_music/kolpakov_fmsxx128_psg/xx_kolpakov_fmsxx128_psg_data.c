/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Kirill Kolpakov's fMSX/x128 PSG chiptune (.PSG) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_kolpakov_fmsxx128_psg_build(sxmr_view*v)
{
 return sxmr_psg(v,false);
}
