/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jpeg2000_pgx data structures, moved out of the textimages schema family. */
#include "../../xx_format_schema_textimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_jpeg2000_pgx_build(sxti_cursor*q,xx_file_type_t type)
{
 return sxti_simple_image(q,type);
}
