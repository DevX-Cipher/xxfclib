/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IDTECH_ROQ data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_roq_header_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("size_marker", "uint32", 2, 4, SX_SIGNATURE),
    SX_FIELD("frames_per_second", "uint16", 6, 2, SX_NONE),
};
const sx_layout sx_st_roq_header = {0x6008002BU, "roq_header", sx_st_roq_header_fields, SX_COUNT(sx_st_roq_header_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_roq_chunk_fields[] = {
    SX_FIELD("type", "uint16", 0, 2, SX_ID),
    SX_FIELD("payload_size", "uint32", 2, 4, SX_SIZE),
    SX_FIELD("argument", "uint16", 6, 2, SX_NONE),
};
const sx_layout sx_st_roq_chunk = {0x6008002CU, "roq_chunk", sx_st_roq_chunk_fields, SX_COUNT(sx_st_roq_chunk_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_roq_info_fields[] = {
    SX_FIELD("width", "uint16", 0, 2, SX_NONE),
    SX_FIELD("height", "uint16", 2, 2, SX_NONE),
    SX_FIELD("maximum_block_size", "uint16", 4, 2, SX_NONE),
    SX_FIELD("minimum_block_size", "uint16", 6, 2, SX_NONE),
};
const sx_layout sx_st_roq_info = {0x6008002DU, "roq_info", sx_st_roq_info_fields, SX_COUNT(sx_st_roq_info_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_roq_codebook_cell_fields[] = {
    SX_FIELD("y0", "uint8", 0, 1, SX_NONE),
    SX_FIELD("y1", "uint8", 1, 1, SX_NONE),
    SX_FIELD("y2", "uint8", 2, 1, SX_NONE),
    SX_FIELD("y3", "uint8", 3, 1, SX_NONE),
    SX_FIELD("u", "uint8", 4, 1, SX_NONE),
    SX_FIELD("v", "uint8", 5, 1, SX_NONE),
};
const sx_layout sx_st_roq_codebook_cell = {0x6008002EU, "roq_codebook_cell", sx_st_roq_codebook_cell_fields, SX_COUNT(sx_st_roq_codebook_cell_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_roq_codebook_quad_fields[] = {
    SX_FIELD("cell0", "uint8", 0, 1, SX_ID),
    SX_FIELD("cell1", "uint8", 1, 1, SX_ID),
    SX_FIELD("cell2", "uint8", 2, 1, SX_ID),
    SX_FIELD("cell3", "uint8", 3, 1, SX_ID),
};
const sx_layout sx_st_roq_codebook_quad = {0x6008002FU, "roq_codebook_quad", sx_st_roq_codebook_quad_fields, SX_COUNT(sx_st_roq_codebook_quad_fields), SX_LE};
static bool sx_st_roq(sx_context *c)
{
    uint64_t at=8;if(!sx_add(c,&sx_st_roq_header,0,8))return false;
    while(at<(uint64_t)c->size) {
        uint8_t h[8];uint16_t type,arg;uint32_t n;
        if(!sx_read(c,(int64_t)at,h,8)||!sx_add(c,&sx_st_roq_chunk,(int64_t)at,8))return false;
        type=xx_data_get_u16(h,8,0,false);n=xx_data_get_u32(h,8,2,false);arg=xx_data_get_u16(h,8,6,false);at+=8;
        if(!sx_st_fits(c,at,n))return false;
        if(type==0x1001){if(n!=8||!sx_add(c,&sx_st_roq_info,(int64_t)at,8))return false;}
        else if(type==0x1002) {
            unsigned cells=arg>>8,quads=arg&255;if(!cells)cells=256;if(!quads&&n>cells*6)quads=256;
            if(n!=cells*6+quads*4||!sx_table(c,&sx_st_roq_codebook_cell,(int64_t)at,6,cells)||!sx_table(c,&sx_st_roq_codebook_quad,(int64_t)at+cells*6,4,quads))return false;
        }
        at+=n;
    }
    return true;
}
bool sx_idtech_roq_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_roq(c);
    return ok&&sx_st_finish(c);
}
