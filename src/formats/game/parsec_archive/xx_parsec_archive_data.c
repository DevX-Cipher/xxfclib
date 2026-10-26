/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PARSEC_ARCHIVE data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_parsec_archive_build(sx_context*c)
{
bool ok=false;
ok=sxan_parsec(c);
(void)ok;return c->count&&sxan_finish(c);
}
