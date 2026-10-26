/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Sega Genesis/Mega Drive YM2612 chiptune (.GYM) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_gensmd_ym2612_gym_build(sxmn_view*v)
{
 return sxmn_gym(v,true);
}
