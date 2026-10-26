/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * visionaire_studio_vis data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_vis_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxgco_vis_header_le={UINT32_C(0x6040001A),"vis_header_le",sxgco_vis_header_le_fields,SX_COUNT(sxgco_vis_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_vis_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxgco_vis_header_be={UINT32_C(0x6040001B),"vis_header_be",sxgco_vis_header_be_fields,SX_COUNT(sxgco_vis_header_be_fields),SX_BE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_vis(sxgco_view*v)
{uint64_t n,b,e=v->c->size;if(!sxgco_word(v,4,4,false,&n,e)||!sxgco_word(v,4,4,true,&b,e))return false;bool be=b<n;if(be)n=b;return sxgco_row(v,be?&sxgco_vis_header_be:&sxgco_vis_header_le,0,e)&&GC_ROW(vis_index_marker,8,e)&&sxgco_table(v,&sxgco_vis_entry,11,n,e)&&n<=(UINT64_MAX-11)/16&&GC_ROW(vis_index_marker,11+16*n,e);}
bool sx_visionaire_studio_vis_build(sxgco_view*v)
{
 return sxgco_vis(v);
}
#undef GC_ROW
