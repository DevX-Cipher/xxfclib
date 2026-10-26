/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * oric dsk data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_oric_sector_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("side_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("opaque_header","byte[236]",20,236,SX_NONE),
};
const sx_layout sxdleg_oric_sector_header = {0x6075002fU,"oric_sector_header",sxdleg_oric_sector_header_fields,SX_COUNT(sxdleg_oric_sector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_oric_mfm_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("side_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("geometry_order","uint32",16,4,SX_ID),
    SX_FIELD("opaque_header","byte[236]",20,236,SX_NONE),
};
const sx_layout sxdleg_oric_mfm_header = {0x60750030U,"oric_mfm_header",sxdleg_oric_mfm_header_fields,SX_COUNT(sxdleg_oric_mfm_header_fields),SX_LE};
static bool sxdleg_oric(sx_context*c){uint8_t h[8];if(!sxdleg_read(c,0,h,8))return false;const sx_layout*l=!xx_rt_memcmp(h,"ORICDISK",8)?&sxdleg_oric_sector_header:!xx_rt_memcmp(h,"MFM_DISK",8)?&sxdleg_oric_mfm_header:NULL;return l&&sxdleg_put(c,l,0,1);}
bool sx_oric_dsk_build(sx_context*c)
{
 return sxdleg_oric(c);
}
