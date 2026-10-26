/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VIRTUAL98 data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_virtual98_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("comment","char[128]",8,128,SX_NONE),
    SX_FIELD("padding","uint32",136,4,SX_RESERVED),
    SX_FIELD("megabyte_size","uint16",140,2,SX_NONE),
    SX_FIELD("sector_size","uint16",142,2,SX_SIZE),
    SX_FIELD("sectors_per_track","uint8",144,1,SX_COUNT_PROP),
    SX_FIELD("head_count","uint8",145,1,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint16",146,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("padding2","byte[68]",152,68,SX_RESERVED),
};
const sx_layout sxsl_virtual98_header = {0x6033001eU,"virtual98_header",sxsl_virtual98_header_fields,SX_COUNT(sxsl_virtual98_header_fields),SX_LE};
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
bool sx_virtual98_build(sx_context*c)
{
bool ok=false;
ok=SXSL_ADD(c,virtual98_header,0);
return ok&&sxsl_finish(c);
}
