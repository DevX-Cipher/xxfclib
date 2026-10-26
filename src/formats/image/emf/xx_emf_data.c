/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * EMF data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_emf_header_fields[]={
 SX_FIELD("record_type","uint32",0,4,SX_ID),
 SX_FIELD("record_size","uint32",4,4,SX_SIZE),
 SX_FIELD("bounds_left","int32",8,4,SX_NONE),
 SX_FIELD("bounds_top","int32",12,4,SX_NONE),
 SX_FIELD("bounds_right","int32",16,4,SX_NONE),
 SX_FIELD("bounds_bottom","int32",20,4,SX_NONE),
 SX_FIELD("frame_left","int32",24,4,SX_NONE),
 SX_FIELD("frame_top","int32",28,4,SX_NONE),
 SX_FIELD("frame_right","int32",32,4,SX_NONE),
 SX_FIELD("frame_bottom","int32",36,4,SX_NONE),
 SX_FIELD("signature","uint32",40,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",44,4,SX_ID),
 SX_FIELD("file_size","uint32",48,4,SX_SIZE),
 SX_FIELD("record_count","uint32",52,4,SX_COUNT_PROP),
 SX_FIELD("handle_count","uint16",56,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",58,2,SX_RESERVED),
 SX_FIELD("description_chars","uint32",60,4,SX_COUNT_PROP),
 SX_FIELD("description_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("palette_entries","uint32",68,4,SX_COUNT_PROP),
 SX_FIELD("device_width","int32",72,4,SX_NONE),
 SX_FIELD("device_height","int32",76,4,SX_NONE),
 SX_FIELD("millimeters_width","int32",80,4,SX_NONE),
 SX_FIELD("millimeters_height","int32",84,4,SX_NONE),
};
const sx_layout sxnx_emf_header={UINT32_C(0x60320001),"emf_header",sxnx_emf_header_fields,SX_COUNT(sxnx_emf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_record_fields[]={
 SX_FIELD("record_type","uint32",0,4,SX_ID),
 SX_FIELD("record_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxnx_emf_record={UINT32_C(0x60320002),"emf_record",sxnx_emf_record_fields,SX_COUNT(sxnx_emf_record_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_rectangle_fields[]={
 SX_FIELD("left","int32",0,4,SX_NONE),
 SX_FIELD("top","int32",4,4,SX_NONE),
 SX_FIELD("right","int32",8,4,SX_NONE),
 SX_FIELD("bottom","int32",12,4,SX_NONE),
};
const sx_layout sxnx_emf_rectangle={UINT32_C(0x60320003),"emf_rectangle",sxnx_emf_rectangle_fields,SX_COUNT(sxnx_emf_rectangle_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_point_fields[]={
 SX_FIELD("x","int32",0,4,SX_NONE),
 SX_FIELD("y","int32",4,4,SX_NONE),
};
const sx_layout sxnx_emf_point={UINT32_C(0x60320004),"emf_point",sxnx_emf_point_fields,SX_COUNT(sxnx_emf_point_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_poly_count_fields[]={
 SX_FIELD("point_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxnx_emf_poly_count={UINT32_C(0x60320005),"emf_poly_count",sxnx_emf_poly_count_fields,SX_COUNT(sxnx_emf_poly_count_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_mode_fields[]={
 SX_FIELD("mode","uint32",0,4,SX_ID),
};
const sx_layout sxnx_emf_mode={UINT32_C(0x60320006),"emf_mode",sxnx_emf_mode_fields,SX_COUNT(sxnx_emf_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_flags_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxnx_emf_flags={UINT32_C(0x60320007),"emf_flags",sxnx_emf_flags_fields,SX_COUNT(sxnx_emf_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_color_fields[]={
 SX_FIELD("color_ref","uint32",0,4,SX_NONE),
};
const sx_layout sxnx_emf_color={UINT32_C(0x60320008),"emf_color",sxnx_emf_color_fields,SX_COUNT(sxnx_emf_color_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_restore_fields[]={
 SX_FIELD("relative_level","int32",0,4,SX_NONE),
};
const sx_layout sxnx_emf_restore={UINT32_C(0x60320009),"emf_restore",sxnx_emf_restore_fields,SX_COUNT(sxnx_emf_restore_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_handle_fields[]={
 SX_FIELD("object_index","uint32",0,4,SX_ID),
};
const sx_layout sxnx_emf_handle={UINT32_C(0x6032000A),"emf_handle",sxnx_emf_handle_fields,SX_COUNT(sxnx_emf_handle_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_pen_fields[]={
 SX_FIELD("object_index","uint32",0,4,SX_ID),
 SX_FIELD("style","uint32",4,4,SX_FLAGS),
 SX_FIELD("width_x","int32",8,4,SX_NONE),
 SX_FIELD("width_y","int32",12,4,SX_NONE),
 SX_FIELD("color_ref","uint32",16,4,SX_NONE),
};
const sx_layout sxnx_emf_pen={UINT32_C(0x6032000B),"emf_pen",sxnx_emf_pen_fields,SX_COUNT(sxnx_emf_pen_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_brush_fields[]={
 SX_FIELD("object_index","uint32",0,4,SX_ID),
 SX_FIELD("style","uint32",4,4,SX_ID),
 SX_FIELD("color_ref","uint32",8,4,SX_NONE),
 SX_FIELD("hatch","uint32",12,4,SX_ID),
};
const sx_layout sxnx_emf_brush={UINT32_C(0x6032000C),"emf_brush",sxnx_emf_brush_fields,SX_COUNT(sxnx_emf_brush_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_eof_fields[]={
 SX_FIELD("palette_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("palette_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("last_record_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxnx_emf_eof={UINT32_C(0x6032000D),"emf_eof",sxnx_emf_eof_fields,SX_COUNT(sxnx_emf_eof_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_emf(sxnx_view*v)
{
 if(!SN_ROW(emf_header,0,v->n))return false;size_t at=sxnx_u32(v->p+4,false);unsigned work=0;
 while(at<v->n){if(++work>4096||!SN_ROW(emf_record,at,v->n))return false;uint32_t kind=sxnx_u32(v->p+at,false),size=sxnx_u32(v->p+at+4,false);if(size<8||!sxnx_need(v,at,size,v->n))return false;size_t p=at+8,end=at+size;const sx_layout*l=NULL;
 if(kind>=2&&kind<=4){if(!SN_ROW(emf_rectangle,p,end)||!SN_ROW(emf_poly_count,p+16,end)||!sxnx_table(v,&sxnx_emf_point,p+20,sxnx_u32(v->p+p+16,false),end))return false;}
 else{if((kind>=9&&kind<=13)||kind==27||kind==54)l=&sxnx_emf_point;else if(kind==15){if(!SN_ROW(emf_point,p,end))return false;l=&sxnx_emf_color;p+=8;}else if(kind==16||kind==22)l=&sxnx_emf_flags;else if(kind>=17&&kind<=21)l=&sxnx_emf_mode;else if(kind==24||kind==25)l=&sxnx_emf_color;else if(kind==34)l=&sxnx_emf_restore;else if(kind==37||kind==40)l=&sxnx_emf_handle;else if(kind==29||kind==30||kind==42||kind==43)l=&sxnx_emf_rectangle;else if(kind==38)l=&sxnx_emf_pen;else if(kind==39)l=&sxnx_emf_brush;else if(kind==14)l=&sxnx_emf_eof;if(l&&!sxnx_row(v,l,p,end))return false;}
 at=end;}return at==v->n;
}
bool sx_emf_build(sxnx_view*v)
{
 return sxnx_emf(v);
}
#undef SN_ROW
