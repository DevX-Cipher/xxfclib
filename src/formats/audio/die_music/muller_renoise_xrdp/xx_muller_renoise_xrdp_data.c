/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * muller_renoise_xrdp data structures, moved out of the musicprojects schema family. */
#include "../../../xx_format_schema_musicprojects.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_muller_renoise_xrdp_build(sxmp_view*v)
{
 return sxmp_xml(v);
}
