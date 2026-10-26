/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * T98_HDD data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_t98_header_fields[] = {
    SX_FIELD("cylinders","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[252]",4,252,SX_RESERVED),
};
const sx_layout sxst_t98_header = {0x60370033U,"t98_header",sxst_t98_header_fields,SX_COUNT(sxst_t98_header_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
bool sx_t98_hdd_build(sx_context*c)
{
 return SXST_ADD(c,t98_header,0);
}
#undef SXST_ADD
