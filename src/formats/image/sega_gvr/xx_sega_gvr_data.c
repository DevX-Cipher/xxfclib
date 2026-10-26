/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sega gvr data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_gvr_prefix_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("reserved","uint16",8,2,SX_RESERVED),
    SX_FIELD("palette_format_and_flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("texture_format","uint8",11,1,SX_ID),
};
const sx_layout sxrm_gvr_prefix = {UINT32_C(0x601d0021),"gvr_prefix",sxrm_gvr_prefix_fields,SX_COUNT(sxrm_gvr_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_gvr_dimensions_fields[] = {
    SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxrm_gvr_dimensions = {UINT32_C(0x601d0022),"gvr_dimensions",sxrm_gvr_dimensions_fields,SX_COUNT(sxrm_gvr_dimensions_fields),SX_BE};
bool sx_sega_gvr_build(sx_context*c)
{
 return sxrm_add(c,&sxrm_gvr_prefix,0)&&sxrm_add(c,&sxrm_gvr_dimensions,12);
}
