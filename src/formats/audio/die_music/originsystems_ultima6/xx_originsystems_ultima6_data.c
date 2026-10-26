/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Originsystems Ultima6 data structures, moved out of the musiclate schema family. */
#include "../../../xx_format_schema_musiclate.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxlate_ultima6(sx_context*c)
{
    uint8_t h[6];uint64_t end=(uint64_t)c->size;
    if(!sxlate_read(c,0,h,6,end)||h[2]||h[3]||h[4]||!(h[5]&1))return false;
    return sxlate_row(c,&sxlate_ultima6_header,0,4,end);
}
bool sx_originsystems_ultima6_build(sx_context*c)
{
    return sxlate_ultima6(c);
}
