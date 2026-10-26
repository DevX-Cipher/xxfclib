/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * esri_ascii_grid data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_esri_ascii_grid_build(sxsa_cursor*q)
{
 return sxsa_grid(q,false);
}
