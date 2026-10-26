/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * UEFI TE executable data structures, moved out of the executable schema family. */
#include "../../xx_format_schema_executable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_te_executable_build(sx_context*c)
{
    return sx_coff_build(c,true);
}
