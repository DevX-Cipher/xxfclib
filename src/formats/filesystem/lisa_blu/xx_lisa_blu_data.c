/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LISA_BLU data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_lisa_blu_header_fields[] = {
    SX_FIELD("device_name","char[13]",0,13,SX_NONE),
    SX_FIELD("device_type","uint24",13,3,SX_ID),
    SX_FIELD("unknown_10","byte[2]",16,2,SX_NONE),
    SX_FIELD("block_count","uint24",18,3,SX_COUNT_PROP),
    SX_FIELD("bytes_per_block","uint16",21,2,SX_SIZE),
};
const sx_layout sxst_lisa_blu_header = {0x60370020U,"lisa_blu_header",sxst_lisa_blu_header_fields,SX_COUNT(sxst_lisa_blu_header_fields),SX_BE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
bool sx_lisa_blu_build(sx_context*c)
{
 return SXST_ADD(c,lisa_blu_header,0);
}
#undef SXST_ADD
