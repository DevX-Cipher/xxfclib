/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NRRD data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_nrrd_build(sxsm_cursor*q)
{
 return sxsm_nrrd_meta(q,false);
}
