/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Jazz Jackrabbit 2/Galaxy Sound System module (.J2B) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_jazzjr2_gss_unp_build(sxmta_view*v)
{
 return sxmta_galaxy(v,false);
}
