/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Daniel Potter/Digital Infinity's Farandole Composer sample (.FSM) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_potter_farandole_fsm_build(sxmr_view*v)
{
 return sxmr_far(v,true);
}
