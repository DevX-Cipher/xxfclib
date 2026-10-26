/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WMF data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_wmf_placeable_fields[]={
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("handle","uint16",4,2,SX_RESERVED),
 SX_FIELD("left","int16",6,2,SX_NONE),
 SX_FIELD("top","int16",8,2,SX_NONE),
 SX_FIELD("right","int16",10,2,SX_NONE),
 SX_FIELD("bottom","int16",12,2,SX_NONE),
 SX_FIELD("units_per_inch","uint16",14,2,SX_NONE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
 SX_FIELD("checksum","uint16",20,2,SX_CHECKSUM),
};
const sx_layout sxnx_wmf_placeable={UINT32_C(0x6032000E),"wmf_placeable",sxnx_wmf_placeable_fields,SX_COUNT(sxnx_wmf_placeable_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_header_fields[]={
 SX_FIELD("file_type","uint16",0,2,SX_ID),
 SX_FIELD("header_words","uint16",2,2,SX_NONE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("file_words","uint32",6,4,SX_NONE),
 SX_FIELD("object_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("maximum_record_words","uint32",12,4,SX_NONE),
 SX_FIELD("parameter_count","uint16",16,2,SX_RESERVED),
};
const sx_layout sxnx_wmf_header={UINT32_C(0x6032000F),"wmf_header",sxnx_wmf_header_fields,SX_COUNT(sxnx_wmf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_record_fields[]={
 SX_FIELD("record_words","uint32",0,4,SX_NONE),
 SX_FIELD("function","uint16",4,2,SX_ID),
};
const sx_layout sxnx_wmf_record={UINT32_C(0x60320010),"wmf_record",sxnx_wmf_record_fields,SX_COUNT(sxnx_wmf_record_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_point_fields[]={
 SX_FIELD("x","int16",0,2,SX_NONE),
 SX_FIELD("y","int16",2,2,SX_NONE),
};
const sx_layout sxnx_wmf_point={UINT32_C(0x60320011),"wmf_point",sxnx_wmf_point_fields,SX_COUNT(sxnx_wmf_point_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_coordinate_pair_fields[]={
 SX_FIELD("y","int16",0,2,SX_NONE),
 SX_FIELD("x","int16",2,2,SX_NONE),
};
const sx_layout sxnx_wmf_coordinate_pair={UINT32_C(0x60320012),"wmf_coordinate_pair",sxnx_wmf_coordinate_pair_fields,SX_COUNT(sxnx_wmf_coordinate_pair_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_rectangle_fields[]={
 SX_FIELD("bottom","int16",0,2,SX_NONE),
 SX_FIELD("right","int16",2,2,SX_NONE),
 SX_FIELD("top","int16",4,2,SX_NONE),
 SX_FIELD("left","int16",6,2,SX_NONE),
};
const sx_layout sxnx_wmf_rectangle={UINT32_C(0x60320013),"wmf_rectangle",sxnx_wmf_rectangle_fields,SX_COUNT(sxnx_wmf_rectangle_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_poly_count_fields[]={
 SX_FIELD("point_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxnx_wmf_poly_count={UINT32_C(0x60320014),"wmf_poly_count",sxnx_wmf_poly_count_fields,SX_COUNT(sxnx_wmf_poly_count_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_mode_fields[]={
 SX_FIELD("mode","uint16",0,2,SX_ID),
};
const sx_layout sxnx_wmf_mode={UINT32_C(0x60320015),"wmf_mode",sxnx_wmf_mode_fields,SX_COUNT(sxnx_wmf_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_restore_fields[]={
 SX_FIELD("relative_level","int16",0,2,SX_NONE),
};
const sx_layout sxnx_wmf_restore={UINT32_C(0x60320016),"wmf_restore",sxnx_wmf_restore_fields,SX_COUNT(sxnx_wmf_restore_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_handle_fields[]={
 SX_FIELD("object_index","uint16",0,2,SX_ID),
};
const sx_layout sxnx_wmf_handle={UINT32_C(0x60320017),"wmf_handle",sxnx_wmf_handle_fields,SX_COUNT(sxnx_wmf_handle_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_color_fields[]={
 SX_FIELD("color_ref","uint32",0,4,SX_NONE),
};
const sx_layout sxnx_wmf_color={UINT32_C(0x60320018),"wmf_color",sxnx_wmf_color_fields,SX_COUNT(sxnx_wmf_color_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_pen_fields[]={
 SX_FIELD("style","uint16",0,2,SX_FLAGS),
 SX_FIELD("width_x","int16",2,2,SX_NONE),
 SX_FIELD("width_y","int16",4,2,SX_NONE),
 SX_FIELD("color_ref","uint32",6,4,SX_NONE),
};
const sx_layout sxnx_wmf_pen={UINT32_C(0x60320019),"wmf_pen",sxnx_wmf_pen_fields,SX_COUNT(sxnx_wmf_pen_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_brush_fields[]={
 SX_FIELD("style","uint16",0,2,SX_ID),
 SX_FIELD("color_ref","uint32",2,4,SX_NONE),
 SX_FIELD("hatch","uint16",6,2,SX_ID),
};
const sx_layout sxnx_wmf_brush={UINT32_C(0x6032001A),"wmf_brush",sxnx_wmf_brush_fields,SX_COUNT(sxnx_wmf_brush_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_wmf(sxnx_view*v)
{
 if(!SN_ROW(wmf_placeable,0,v->n)||!SN_ROW(wmf_header,22,v->n))return false;size_t at=40;unsigned work=0;
 while(at<v->n){if(++work>4096||!SN_ROW(wmf_record,at,v->n))return false;uint64_t size=2*(uint64_t)sxnx_u32(v->p+at,false);uint16_t kind=sxnx_u16(v->p+at+4,false);if(size<6||!sxnx_need(v,at,size,v->n))return false;size_t p=at+6,end=at+(size_t)size;const sx_layout*l=NULL;
 if(kind==0x324||kind==0x325){if(!SN_ROW(wmf_poly_count,p,end)||!sxnx_table(v,&sxnx_wmf_point,p+2,sxnx_u16(v->p+p,false),end))return false;}
 else{if(kind==0x214||kind==0x213||(kind>=0x20b&&kind<=0x20e))l=&sxnx_wmf_coordinate_pair;else if(kind==0x201||kind==0x209)l=&sxnx_wmf_color;else if(kind==0x41b||kind==0x418)l=&sxnx_wmf_rectangle;else if(kind==0x12d||kind==0x1f0)l=&sxnx_wmf_handle;else if(kind==0x127)l=&sxnx_wmf_restore;else if(kind==0x102||kind==0x103||kind==0x104||kind==0x106||kind==0x107||kind==0x108)l=&sxnx_wmf_mode;else if(kind==0x2fa)l=&sxnx_wmf_pen;else if(kind==0x2fc)l=&sxnx_wmf_brush;if(l&&!sxnx_row(v,l,p,end))return false;}
 at=end;}return at==v->n;
}
bool sx_wmf_build(sxnx_view*v)
{
 return sxnx_wmf(v);
}
#undef SN_ROW
