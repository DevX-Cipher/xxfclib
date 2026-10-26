/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Amaya 'Pixel' Daisuke's pxtone tune (.PTTUNE) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_pixel_pxtone_pttune_build(sxmn_view*v)
{
 return sxmn_pxt(v);
}
