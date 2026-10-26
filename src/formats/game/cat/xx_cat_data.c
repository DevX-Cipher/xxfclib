/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cat data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_cat_build(sxga_view*v)
{
 return sxga_counted(v,&sxga_cat_entry);
}
