/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * scanalytics_iplab data structures, moved out of the scientificextra schema family. */
#include "../../xx_format_schema_scientificextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxscx_iplab_terminator_le_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("size","uint32",4,4,SX_SIZE),
};
const sx_layout sxscx_iplab_terminator_le = {UINT32_C(0x60310005),"iplab_terminator_le",sxscx_iplab_terminator_le_fields,SX_COUNT(sxscx_iplab_terminator_le_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_iplab_terminator_be_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("size","uint32",4,4,SX_SIZE),
};
const sx_layout sxscx_iplab_terminator_be = {UINT32_C(0x60310008),"iplab_terminator_be",sxscx_iplab_terminator_be_fields,SX_COUNT(sxscx_iplab_terminator_be_fields),SX_BE};
static bool sxscx_iplab(sx_context *c,const uint8_t *b,size_t n){if(n<52)return false;bool be=b[0]=='m';return sxscx_add(c,be?&sxscx_iplab_header_be:&sxscx_iplab_header_le,0)&&sxscx_add(c,be?&sxscx_iplab_terminator_be:&sxscx_iplab_terminator_le,n-8);}
bool sx_scanalytics_iplab_build(sx_context *c,uint8_t *b)
{
 return sxscx_iplab(c,b,(size_t)c->size);
}
