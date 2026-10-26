/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Riven the Mage's Exotic AdLib module (.XAD) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_riven_exoticadlib_xad_build(sx_context*c,sxmn_view*v)
{
 return sxmn_row(v,&sxmn_xad_header,0,(uint64_t)c->size);
}
