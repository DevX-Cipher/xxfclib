/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SOUNDFONT2 data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_soundfont2_build(sx_context*c)
{
    return sx_c_riff(c);
}
