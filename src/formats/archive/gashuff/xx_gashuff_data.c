/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GAS HUFF data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_gashuff_build(sx_context*c)
{
    uint32_t v;uint16_t n,root;return sx_u32(c,0,false,&v)&&v&&sx_u16(c,4,false,&n)&&n>=3&&n<=511&&sx_u16(c,6,false,&root)&&root<=n&&sxl_span(c,8,3)&&sx_add(c,&sxl_gas_huff_header,0,8);
}
