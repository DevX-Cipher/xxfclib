/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NHD data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_nhd_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("comment","char[256]",16,256,SX_NONE),
    SX_FIELD("header_size","uint32",272,4,SX_SIZE),
    SX_FIELD("cylinder_count","uint32",276,4,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",280,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",282,2,SX_COUNT_PROP),
    SX_FIELD("sector_size","uint16",284,2,SX_SIZE),
    SX_FIELD("reserved","byte[226]",286,226,SX_RESERVED),
};
const sx_layout sxsl_nhd_header = {0x6033001dU,"nhd_header",sxsl_nhd_header_fields,SX_COUNT(sxsl_nhd_header_fields),SX_LE};
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
bool sx_nhd_build(sx_context*c)
{
bool ok=false;
ok=SXSL_ADD(c,nhd_header,0);
return ok&&sxsl_finish(c);
}
