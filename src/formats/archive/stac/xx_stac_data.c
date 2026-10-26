/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Stac LZS (sTaC header) data structures, moved out of the archivewire schema family. */
#include "../../xx_format_schema_archivewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_stac_build(sx_context*c)
{
 return sxarwire_lzs(c,4);
}
