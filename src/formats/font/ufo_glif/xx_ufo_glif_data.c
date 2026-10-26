/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ufo glif data structures, moved out of the vectortext schema family. */
#include "../../xx_format_schema_vectortext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_ufo_glif_build(sxvtx_cursor*q)
{
 return sxvtx_xml(q,2);
}
