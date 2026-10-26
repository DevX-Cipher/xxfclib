/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WBMP IMAGE data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_wbmp_header_fields[]={
 SX_FIELD("type","uint8",0,1,SX_ID),
 SX_FIELD("fixed_header","uint8",1,1,SX_FLAGS),
};
const sx_layout sxnx_wbmp_header={UINT32_C(0x6032001B),"wbmp_header",sxnx_wbmp_header_fields,SX_COUNT(sxnx_wbmp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_width_1_fields[]={
 SX_FIELD("width","uintbase128",0,1,SX_COUNT_PROP),
};
const sx_layout sxnx_wbmp_width_1={UINT32_C(0x6032001C),"wbmp_width_1",sxnx_wbmp_width_1_fields,SX_COUNT(sxnx_wbmp_width_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_height_1_fields[]={
 SX_FIELD("height","uintbase128",0,1,SX_COUNT_PROP),
};
const sx_layout sxnx_wbmp_height_1={UINT32_C(0x6032001D),"wbmp_height_1",sxnx_wbmp_height_1_fields,SX_COUNT(sxnx_wbmp_height_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_width_2_fields[]={
 SX_FIELD("width","uintbase128",0,2,SX_COUNT_PROP),
};
const sx_layout sxnx_wbmp_width_2={UINT32_C(0x6032001E),"wbmp_width_2",sxnx_wbmp_width_2_fields,SX_COUNT(sxnx_wbmp_width_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_height_2_fields[]={
 SX_FIELD("height","uintbase128",0,2,SX_COUNT_PROP),
};
const sx_layout sxnx_wbmp_height_2={UINT32_C(0x6032001F),"wbmp_height_2",sxnx_wbmp_height_2_fields,SX_COUNT(sxnx_wbmp_height_2_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_wbmp(sxnx_view*v)
{if(!SN_ROW(wbmp_header,0,v->n))return false;size_t p=2;for(unsigned i=0;i<2;i++){size_t start=p;uint32_t n;unsigned width;if(!sxnx_varuint(v,&p,v->n,&n,&width)||width>2)return false;const sx_layout*l=i?(width==1?&sxnx_wbmp_height_1:&sxnx_wbmp_height_2):(width==1?&sxnx_wbmp_width_1:&sxnx_wbmp_width_2);if(!sxnx_row(v,l,start,p))return false;}return true;}
bool sx_wbmp_image_build(sxnx_view*v)
{
 return sxnx_wbmp(v);
}
#undef SN_ROW
