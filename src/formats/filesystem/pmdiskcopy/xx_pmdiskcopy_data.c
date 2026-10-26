/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PMDISKCOPY data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_pmdiskcopy_header_fields[] = {
    SX_FIELD("signature","char[11]",0,11,SX_SIGNATURE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("opaque_tail","byte[11]",36,11,SX_NONE),
};
const sx_layout sxsl_pmdiskcopy_header = {0x60330008U,"pmdiskcopy_header",sxsl_pmdiskcopy_header_fields,SX_COUNT(sxsl_pmdiskcopy_header_fields),SX_LE};
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
bool sx_pmdiskcopy_build(sx_context*c)
{
bool ok=false;
ok=SXSL_ADD(c,pmdiskcopy_header,0);
return ok&&sxsl_finish(c);
}
