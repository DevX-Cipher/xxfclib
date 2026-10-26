/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * APPLE DOS33 32 data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_apple_dos33_32_build(sx_context*c)
{
 return sxrfs_apple_dos(c);
}
