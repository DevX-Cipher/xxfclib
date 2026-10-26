/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DLKE data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sx_fm_dlke(sx_context *c)
{
    uint32_t n;if(!sx_fm_u32(c,44,false,&n))return false;
    /* data_size is the signature span in the first JBOOT ARM header. */
    if(!sx_fm_add(c,&sx_fm_dlke_arm_header,0,80))return false;return !sx_fm_span(c,80+(int64_t)n,80)||sx_fm_add(c,&sx_fm_dlke_arm_header,80+(int64_t)n,80);
}
bool sx_dlke_build(sx_context*c)
{
    return sx_fm_dlke(c);
}
