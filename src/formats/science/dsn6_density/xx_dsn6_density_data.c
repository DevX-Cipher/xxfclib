/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dsn6_density data structures, moved out of the scientificextra schema family. */
#include "../../xx_format_schema_scientificextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxscx_dsn6_header_le_fields[] = {
    SX_FIELD("origin_x","int16",0,2,SX_NONE),
    SX_FIELD("origin_y","int16",2,2,SX_NONE),
    SX_FIELD("origin_z","int16",4,2,SX_NONE),
    SX_FIELD("extent_x","int16",6,2,SX_COUNT_PROP),
    SX_FIELD("extent_y","int16",8,2,SX_COUNT_PROP),
    SX_FIELD("extent_z","int16",10,2,SX_COUNT_PROP),
    SX_FIELD("grid_x","int16",12,2,SX_COUNT_PROP),
    SX_FIELD("grid_y","int16",14,2,SX_COUNT_PROP),
    SX_FIELD("grid_z","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("cell_a","int16",18,2,SX_NONE),
    SX_FIELD("cell_b","int16",20,2,SX_NONE),
    SX_FIELD("cell_c","int16",22,2,SX_NONE),
    SX_FIELD("cell_alpha","int16",24,2,SX_NONE),
    SX_FIELD("cell_beta","int16",26,2,SX_NONE),
    SX_FIELD("cell_gamma","int16",28,2,SX_NONE),
    SX_FIELD("density_multiplier","int16",30,2,SX_NONE),
    SX_FIELD("density_bias","int16",32,2,SX_NONE),
    SX_FIELD("cell_multiplier","int16",34,2,SX_NONE),
    SX_FIELD("byte_order_marker","int16",36,2,SX_ID),
    SX_FIELD("reserved","uint8[474]",38,474,SX_RESERVED),
};
const sx_layout sxscx_dsn6_header_le = {UINT32_C(0x60310006),"dsn6_header_le",sxscx_dsn6_header_le_fields,SX_COUNT(sxscx_dsn6_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_dsn6_header_be_fields[] = {
    SX_FIELD("origin_x","int16",0,2,SX_NONE),
    SX_FIELD("origin_y","int16",2,2,SX_NONE),
    SX_FIELD("origin_z","int16",4,2,SX_NONE),
    SX_FIELD("extent_x","int16",6,2,SX_COUNT_PROP),
    SX_FIELD("extent_y","int16",8,2,SX_COUNT_PROP),
    SX_FIELD("extent_z","int16",10,2,SX_COUNT_PROP),
    SX_FIELD("grid_x","int16",12,2,SX_COUNT_PROP),
    SX_FIELD("grid_y","int16",14,2,SX_COUNT_PROP),
    SX_FIELD("grid_z","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("cell_a","int16",18,2,SX_NONE),
    SX_FIELD("cell_b","int16",20,2,SX_NONE),
    SX_FIELD("cell_c","int16",22,2,SX_NONE),
    SX_FIELD("cell_alpha","int16",24,2,SX_NONE),
    SX_FIELD("cell_beta","int16",26,2,SX_NONE),
    SX_FIELD("cell_gamma","int16",28,2,SX_NONE),
    SX_FIELD("density_multiplier","int16",30,2,SX_NONE),
    SX_FIELD("density_bias","int16",32,2,SX_NONE),
    SX_FIELD("cell_multiplier","int16",34,2,SX_NONE),
    SX_FIELD("byte_order_marker","int16",36,2,SX_ID),
    SX_FIELD("reserved","uint8[474]",38,474,SX_RESERVED),
};
const sx_layout sxscx_dsn6_header_be = {UINT32_C(0x60310009),"dsn6_header_be",sxscx_dsn6_header_be_fields,SX_COUNT(sxscx_dsn6_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_brix_header_fields[] = {
    SX_FIELD("descriptor_text","char[512]",0,512,SX_STRING),
};
const sx_layout sxscx_brix_header = {UINT32_C(0x6031000a),"brix_header",sxscx_brix_header_fields,SX_COUNT(sxscx_brix_header_fields),SX_LE};
static bool sxscx_dsn6(sx_context *c,const uint8_t *b,size_t n){if(n<512)return false;return sxscx_add(c,!xx_rt_memcmp(b,":-)",3)?&sxscx_brix_header:sxscx16(b+36,true)==100?&sxscx_dsn6_header_be:&sxscx_dsn6_header_le,0);}
bool sx_dsn6_density_build(sx_context *c,uint8_t *b)
{
 return sxscx_dsn6(c,b,(size_t)c->size);
}
