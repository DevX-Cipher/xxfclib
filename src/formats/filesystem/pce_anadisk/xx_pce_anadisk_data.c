/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AnaDisk sector disk image data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_anadisk_sector_header_fields[] = {
    SX_FIELD("physical_cylinder","uint8",0,1,SX_ID),
    SX_FIELD("physical_head","uint8",1,1,SX_ID),
    SX_FIELD("logical_cylinder","uint8",2,1,SX_ID),
    SX_FIELD("logical_head","uint8",3,1,SX_ID),
    SX_FIELD("sector_id","uint8",4,1,SX_ID),
    SX_FIELD("size_code","uint8",5,1,SX_NONE),
    SX_FIELD("stored_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxdi_anadisk_sector_header = {UINT32_C(0x60150001),"anadisk_sector_header",sxdi_anadisk_sector_header_fields,SX_COUNT(sxdi_anadisk_sector_header_fields),SX_LE};
static bool sxdi_ana(sx_context *c)
{
    uint64_t at=0;unsigned count=0;
    while(at<(uint64_t)c->size&&count<65536){uint8_t h[8];if(!sxdi_read(c,at,h,8))return count!=0;uint32_t n=sxdi_le16(h+6);
        if(!sxdi_span(c,at+8,n))return count!=0;if(!sx_add(c,&sxdi_anadisk_sector_header,(int64_t)at,8))return false;count++;at+=8+n;
    }return count!=0;
}
bool sx_pce_anadisk_build(sx_context*c)
{
    return sxdi_ana(c);
}
