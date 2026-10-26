/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MAXI_DISK data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_maxidisk_header_fields[] = {
    SX_FIELD("unknown_00","uint8",0,1,SX_NONE),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("heads","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_code","uint8",4,1,SX_NONE),
    SX_FIELD("sectors_per_track","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("unknown_06","byte[2]",6,2,SX_NONE),
};
const sx_layout sxst_maxidisk_header = {0x6037002dU,"maxidisk_header",sxst_maxidisk_header_fields,SX_COUNT(sxst_maxidisk_header_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
bool sx_maxi_disk_build(sx_context*c)
{
 return SXST_ADD(c,maxidisk_header,0);
}
#undef SXST_ADD
