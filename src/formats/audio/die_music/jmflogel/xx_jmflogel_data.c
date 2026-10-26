/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Janko Mrsic-Flogel's module (.JMF) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_jmflogel_build(sxamip_view*v)
{
 return sxamip_hunk_metadata(v,2);
}
