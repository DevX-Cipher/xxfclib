/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * R.Schrijvers & M.Delorme's MoonBlaster for MoonSound FM module (.MFM) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_moonblaster_fm_build(sx_context*c)
{
 return sxchip_moon(c,false);
}
