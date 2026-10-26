/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lut_cinespace_csp data structures, moved out of the textimages schema family. */
#include "../../xx_format_schema_textimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_lut_cinespace_csp_build(sxti_cursor*q,xx_file_type_t type)
{
 return sxti_lut(q,type);
}
