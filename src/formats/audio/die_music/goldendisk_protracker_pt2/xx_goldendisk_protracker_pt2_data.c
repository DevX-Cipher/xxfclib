/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Goldendisk Protracker Pt2 data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_goldendisk_protracker_pt2_build(sx_context*c)
{
 return sxzxm_pt(c,2);
}
