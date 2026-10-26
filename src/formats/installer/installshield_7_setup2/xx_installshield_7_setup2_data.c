/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * InstallShield 7 setup.boot data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_installshield_7_setup2_build(sx_context*c,sxil_records records)
{
 return sxil_is_strings(c,&records,false,true);
}
