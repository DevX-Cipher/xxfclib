/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BIOMEDICAL_BDF data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_biomedical_bdf_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_edf(c);
 return ok&&sxsh_finish(c);
}
