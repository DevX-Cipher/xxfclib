/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Marcin 'Jaskier' Lewandowski's Theta Music Composer module (.TMC,.TM4,.TM8) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_jaskier_thetamusiccomposer_tmc_build(sx_context*c)
{
 return sxchip_tmc(c,false);
}
