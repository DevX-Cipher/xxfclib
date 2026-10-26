/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NEC PC-98 FDI data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_nec_pc98_fdi_header_fields[] = {
    SX_FIELD("reserved","uint32",0,4,SX_RESERVED),
    SX_FIELD("floppy_type","uint32",4,4,SX_ID),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("data_size","uint32",12,4,SX_SIZE),
    SX_FIELD("sector_size","uint32",16,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("head_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxdi_nec_pc98_fdi_header = {UINT32_C(0x60150012),"nec_pc98_fdi_header",sxdi_nec_pc98_fdi_header_fields,SX_COUNT(sxdi_nec_pc98_fdi_header_fields),SX_LE};
static bool sxdi_necfdi(sx_context *c)
{
    uint8_t h[32];if(!sxdi_read(c,0,h,32)||sxdi_le32(h)||sxdi_le32(h+8)<32)return false;
    return sx_add(c,&sxdi_nec_pc98_fdi_header,0,32);
}
bool sx_nec_pc_98_fdi_build(sx_context*c)
{
    return sxdi_necfdi(c);
}
