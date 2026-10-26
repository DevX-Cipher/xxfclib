/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo bcfnt data structures, moved out of the fontbinary schema family. */
#include "../../xx_format_schema_fontbinary.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_nintendo_bcfnt_build(sx_context*c)
{
 return sxfb_nintendo(c,false);
}
