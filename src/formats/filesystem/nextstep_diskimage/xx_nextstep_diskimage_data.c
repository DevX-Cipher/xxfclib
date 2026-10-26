/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Nextstep Diskimage data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_nextstep_container_header_fields[] = {
    SX_FIELD("format_word","uint32",0,4,SX_ID),
    SX_FIELD("sector_size","uint16",4,2,SX_SIZE),
    SX_FIELD("geometry_factor_0","uint32",6,4,SX_COUNT_PROP),
    SX_FIELD("geometry_factor_1","uint32",10,4,SX_COUNT_PROP),
    SX_FIELD("unknown0","byte[8]",14,8,SX_NONE),
    SX_FIELD("image_size","uint32",22,4,SX_SIZE),
    SX_FIELD("constant_one","uint32",26,4,SX_ID),
    SX_FIELD("sector_size_copy32","uint32",30,4,SX_SIZE),
    SX_FIELD("sector_size_copy16","uint16",34,2,SX_SIZE),
    SX_FIELD("geometry_factor_2","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("unknown1","byte[2]",40,2,SX_NONE),
    SX_FIELD("total_sectors","uint32",42,4,SX_COUNT_PROP),
};
const sx_layout sxvi_nextstep_container_header = {0x60530046U,"nextstep_container_header",sxvi_nextstep_container_header_fields,SX_COUNT(sxvi_nextstep_container_header_fields),SX_BE};
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
static bool sxvi_next(sx_context*c){uint8_t b[46];if(!sxvi_read(c,0,b,46)||!sxvi32(b,1)||sxvi32(b,1)>16||sxvi16(b+4,1)!=512||sxvi16(b+34,1)!=512||sxvi32(b+30,1)!=512||sxvi32(b+26,1)!=1)return false;uint64_t a=sxvi32(b+6,1),d=sxvi32(b+10,1),e=sxvi32(b+36,1);if(!a||a>65535||!d||d>255||!e||e>255||a*d*e!=sxvi32(b+42,1)||a*d*e*512!=sxvi32(b+22,1)||!sxvi_span(c,46,a*d*e*512))return false;return SXVI_ADD(c,nextstep_container_header,0);}
bool sx_nextstep_diskimage_build(sx_context*c)
{
 return sxvi_next(c);
}
#undef SXVI_ADD
