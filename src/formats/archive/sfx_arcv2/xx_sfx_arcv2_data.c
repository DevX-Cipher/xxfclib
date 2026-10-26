/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx arcv2 data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

bool sx_sfx_arcv2_build(sx_context*c)
{
 return sxaend_carrier_records(c);
}
