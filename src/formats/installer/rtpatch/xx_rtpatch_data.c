/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Pocket Soft RTPatch (.rtp) patch packages data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_rtpatch_build(sx_context*c)
{
 return sxar_native_records(c,false);
}
