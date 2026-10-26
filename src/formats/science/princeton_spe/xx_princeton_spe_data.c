/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PRINCETON_SPE data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_princeton_spe_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_add(c,&sxsh_spe_header,0,4100);
 return ok&&sxsh_finish(c);
}
