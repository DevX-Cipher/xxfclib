/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ANEX86_HDI data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_anex86_header_fields[] = {
    SX_FIELD("unknown1","uint32",0,4,SX_NONE),
    SX_FIELD("unknown2","uint32",4,4,SX_NONE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("disk_size","uint32",12,4,SX_SIZE),
    SX_FIELD("sector_size","uint32",16,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("head_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxsl_anex86_header = {0x6033001fU,"anex86_header",sxsl_anex86_header_fields,SX_COUNT(sxsl_anex86_header_fields),SX_LE};
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
bool sx_anex86_hdi_build(sx_context*c)
{
bool ok=false;
ok=SXSL_ADD(c,anex86_header,0);
return ok&&sxsl_finish(c);
}
