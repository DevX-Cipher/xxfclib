/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * STEREOLITHOGRAPHY_STL data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_stl_binary_header_fields[] = {
    SX_FIELD("header","uint8[80]",0,80,SX_NONE),
    SX_FIELD("facet_count","uint32",80,4,SX_COUNT_PROP),
};
const sx_layout sxmo_stl_binary_header = {UINT32_C(0x60210060),"stl_binary_header",sxmo_stl_binary_header_fields,SX_COUNT(sxmo_stl_binary_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_stl_binary_facet_fields[] = {
    SX_FIELD("normal","float32[3]",0,12,SX_NONE),
    SX_FIELD("vertex0","float32[3]",12,12,SX_NONE),
    SX_FIELD("vertex1","float32[3]",24,12,SX_NONE),
    SX_FIELD("vertex2","float32[3]",36,12,SX_NONE),
    SX_FIELD("attribute_byte_count","uint16",48,2,SX_SIZE),
};
const sx_layout sxmo_stl_binary_facet = {UINT32_C(0x60210061),"stl_binary_facet",sxmo_stl_binary_facet_fields,SX_COUNT(sxmo_stl_binary_facet_fields),SX_LE};
static bool sxmo_stl(sx_context*c){uint8_t h[84];if(!sxmo_read(c,0,h,84)||!sxmo_add(c,&sxmo_stl_binary_header,0))return false;uint64_t n=sxmo32(h+80,false);if(n<=1000000&&sxmo_span(c,84,n*50)&&!sxmo_table(c,&sxmo_stl_binary_facet,84,n))return false;return true;}
bool sx_stereolithography_stl_build(sx_context*c)
{
bool ok=false;
ok=sxmo_stl(c);
return ok&&c->count>0&&sxmo_finish(c);
}
