/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Hxc Hfe Extended data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_hxc_hfe_extended_build(sx_context*c)
{
 return sxse_hfe(c,false);
}
