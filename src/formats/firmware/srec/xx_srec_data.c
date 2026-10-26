/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * srec data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_srec_build(sxtw_cursor*q)
{
 return sxtw_hex_records(q,false);
}
