/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMIGA_OLD_EXT_ADF data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_amiga_old_ext_adf_build(sx_context*c)
{
bool ok=false;
ok=sxsl_extadf(c,true);
return ok&&sxsl_finish(c);
}
