/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IVF data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_ivf_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("header_size", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("codec", "char[4]", 8, 4, SX_STRING),
    SX_FIELD("width", "uint16", 12, 2, SX_NONE),
    SX_FIELD("height", "uint16", 14, 2, SX_NONE),
    SX_FIELD("frame_rate_numerator", "uint32", 16, 4, SX_NONE),
    SX_FIELD("frame_rate_denominator", "uint32", 20, 4, SX_NONE),
    SX_FIELD("declared_frame_count", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("unused", "uint32", 28, 4, SX_RESERVED),
};
const sx_layout sx_st_ivf_header = {0x60080029U, "ivf_header", sx_st_ivf_header_fields, SX_COUNT(sx_st_ivf_header_fields), SX_LE};
static bool sx_st_ivf(sx_context *c)
{
    uint64_t at=32;if(!sx_add(c,&sx_st_ivf_header,0,32))return false;
    while(at<(uint64_t)c->size) {
        uint32_t n;if(!sx_add(c,&sx_st_ivf_frame,(int64_t)at,12)||!sx_u32(c,(int64_t)at,false,&n)||!sx_st_fits(c,at+12,n))return false;
        at+=12+(uint64_t)n;if(c->count>=20000)break;
    }
    return true;
}
bool sx_ivf_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_ivf(c);
    return ok&&sx_st_finish(c);
}
