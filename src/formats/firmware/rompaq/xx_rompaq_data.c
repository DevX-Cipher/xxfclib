/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ROMPAQ data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_rompaq_build(sx_context*c)
{
    return sx_fm_add(c,&sx_fm_rompaq_header,0,72);
}
