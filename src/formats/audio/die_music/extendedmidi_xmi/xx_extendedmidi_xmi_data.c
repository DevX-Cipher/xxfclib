/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Extended MIDI chiptune (.XMI,.C55,.PCS) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_extendedmidi_xmi_build(sx_context*c,sxmn_view*v)
{
 return sxmn_iff(v,0,(uint64_t)c->size,0,false);
}
