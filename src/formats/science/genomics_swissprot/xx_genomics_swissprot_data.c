/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * genomics_swissprot data structures, moved out of the sciencesequence schema family. */
#include "../../xx_format_schema_sciencesequence.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_genomics_swissprot_build(sxseq_cursor*q)
{
 return sxseq_embl_swiss(q,true);
}
