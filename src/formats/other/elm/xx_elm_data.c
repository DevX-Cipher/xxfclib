/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ELM data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_elm_build(sxdw_cursor*q)
{
 return sxdw_theme(q,true);
}
