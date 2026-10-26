/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC CYBERBRAIN CYBERTRACKER data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_cyberbrain_cybertracker_build(sx_context*c)
{
 return sxpcm_cyber(c,false);
}
