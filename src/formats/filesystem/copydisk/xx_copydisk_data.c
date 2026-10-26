/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CopyDisk data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_copydisk_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("bytes_per_sector","uint16",8,2,SX_SIZE),
    SX_FIELD("geometry_hints","byte[22]",10,22,SX_NONE),
};
const sx_layout sxst_copydisk_header = {0x6037000dU,"copydisk_header",sxst_copydisk_header_fields,SX_COUNT(sxst_copydisk_header_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
bool sx_copydisk_build(sx_context*c)
{
 return SXST_ADD(c,copydisk_header,0);
}
#undef SXST_ADD
