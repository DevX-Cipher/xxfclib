/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Jochen 'Mad Max' Hippel's module (.HIPC) data structures, moved out of the classicmusic schema family. */
#include "../../../xx_format_schema_classicmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_hippel_co_build(sx_context*c)
{
 return sxcmus_hippel(c,1);
}
