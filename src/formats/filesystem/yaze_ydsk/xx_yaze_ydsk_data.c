/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Yaze Ydsk data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_ydsk_header_fields[] = {
    SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
    SX_FIELD("reserved1","byte[6]",10,6,SX_RESERVED),
    SX_FIELD("flags","uint8",16,1,SX_FLAGS),
    SX_FIELD("reserved2","byte[15]",17,15,SX_RESERVED),
    SX_FIELD("logical_sectors_per_track","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("block_shift","uint8",34,1,SX_NONE),
    SX_FIELD("block_mask","uint8",35,1,SX_NONE),
    SX_FIELD("extent_mask","uint8",36,1,SX_NONE),
    SX_FIELD("maximum_block_number","uint16",37,2,SX_NONE),
    SX_FIELD("maximum_directory_entry","uint16",39,2,SX_NONE),
    SX_FIELD("allocation_bitmap_high","uint8",41,1,SX_FLAGS),
    SX_FIELD("allocation_bitmap_low","uint8",42,1,SX_FLAGS),
    SX_FIELD("check_vector_size","uint16",43,2,SX_NONE),
    SX_FIELD("reserved_track_count","uint16",45,2,SX_COUNT_PROP),
    SX_FIELD("sector_shift","uint8",47,1,SX_NONE),
    SX_FIELD("sector_mask","uint8",48,1,SX_NONE),
    SX_FIELD("reserved3","byte[79]",49,79,SX_RESERVED),
};
const sx_layout sxse_ydsk_header = {0x602f0056U,"ydsk_header",sxse_ydsk_header_fields,SX_COUNT(sxse_ydsk_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
bool sx_yaze_ydsk_build(sx_context*c)
{
 return SXSE_ADD(c,ydsk_header,0,128);
}
#undef SXSE_ADD
