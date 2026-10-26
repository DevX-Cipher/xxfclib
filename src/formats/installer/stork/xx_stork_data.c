/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * STORK data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_stork_build(sx_context*c)
{
 return sxacl_chain(c,&sxacl_stork_member,0,18,13,true,true);
}
