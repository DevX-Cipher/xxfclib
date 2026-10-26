/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SAC seismic data data structures, moved out of the sciencemeta schema family. */
#include "../../xx_format_schema_sciencemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_seismic_sac_build(sx_context*c)
{
 uint32_t v;if(!sx_u32(c,304,false,&v))return false;bool be=v!=6;if(be&&!sx_u32(c,304,true,&v))return false;return v==6&&sxsc_add(c,be?&sxsc_sac_header_be:&sxsc_sac_header_le,0,632);
}
