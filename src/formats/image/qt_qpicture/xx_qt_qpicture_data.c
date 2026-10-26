/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QT QPICTURE data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_qpic_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("major_version","uint16",6,2,SX_ID),
 SX_FIELD("minor_version","uint16",8,2,SX_ID),
 SX_FIELD("begin_opcode","uint8",10,1,SX_ID),
 SX_FIELD("begin_length","uint8",11,1,SX_SIZE),
 SX_FIELD("left","int32",12,4,SX_NONE),
 SX_FIELD("top","int32",16,4,SX_NONE),
 SX_FIELD("width","int32",20,4,SX_NONE),
 SX_FIELD("height","int32",24,4,SX_NONE),
 SX_FIELD("record_count","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxnx_qpic_header={UINT32_C(0x60320043),"qpic_header",sxnx_qpic_header_fields,SX_COUNT(sxnx_qpic_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_record_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("data_size","uint8",1,1,SX_SIZE),
};
const sx_layout sxnx_qpic_record={UINT32_C(0x60320044),"qpic_record",sxnx_qpic_record_fields,SX_COUNT(sxnx_qpic_record_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_qpic_record_long_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("size_marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxnx_qpic_record_long={UINT32_C(0x60320045),"qpic_record_long",sxnx_qpic_record_long_fields,SX_COUNT(sxnx_qpic_record_long_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_point_fields[]={
 SX_FIELD("x","double",0,8,SX_NONE),
 SX_FIELD("y","double",8,8,SX_NONE),
};
const sx_layout sxnx_qpic_point={UINT32_C(0x60320046),"qpic_point",sxnx_qpic_point_fields,SX_COUNT(sxnx_qpic_point_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_rectangle_fields[]={
 SX_FIELD("x","double",0,8,SX_NONE),
 SX_FIELD("y","double",8,8,SX_NONE),
 SX_FIELD("width","double",16,8,SX_NONE),
 SX_FIELD("height","double",24,8,SX_NONE),
};
const sx_layout sxnx_qpic_rectangle={UINT32_C(0x60320047),"qpic_rectangle",sxnx_qpic_rectangle_fields,SX_COUNT(sxnx_qpic_rectangle_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_line_fields[]={
 SX_FIELD("x1","double",0,8,SX_NONE),
 SX_FIELD("y1","double",8,8,SX_NONE),
 SX_FIELD("x2","double",16,8,SX_NONE),
 SX_FIELD("y2","double",24,8,SX_NONE),
};
const sx_layout sxnx_qpic_line={UINT32_C(0x60320048),"qpic_line",sxnx_qpic_line_fields,SX_COUNT(sxnx_qpic_line_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_rounding_fields[]={
 SX_FIELD("x_rounding","int16",0,2,SX_NONE),
 SX_FIELD("y_rounding","int16",2,2,SX_NONE),
};
const sx_layout sxnx_qpic_rounding={UINT32_C(0x60320049),"qpic_rounding",sxnx_qpic_rounding_fields,SX_COUNT(sxnx_qpic_rounding_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_angles_fields[]={
 SX_FIELD("start_angle","int16",0,2,SX_NONE),
 SX_FIELD("span_angle","int16",2,2,SX_NONE),
};
const sx_layout sxnx_qpic_angles={UINT32_C(0x6032004A),"qpic_angles",sxnx_qpic_angles_fields,SX_COUNT(sxnx_qpic_angles_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_point_count_fields[]={
 SX_FIELD("point_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxnx_qpic_point_count={UINT32_C(0x6032004B),"qpic_point_count",sxnx_qpic_point_count_fields,SX_COUNT(sxnx_qpic_point_count_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_fill_rule_fields[]={
 SX_FIELD("fill_rule","uint8",0,1,SX_ID),
};
const sx_layout sxnx_qpic_fill_rule={UINT32_C(0x6032004C),"qpic_fill_rule",sxnx_qpic_fill_rule_fields,SX_COUNT(sxnx_qpic_fill_rule_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_qpic_mode_fields[]={
 SX_FIELD("mode","int32",0,4,SX_ID),
};
const sx_layout sxnx_qpic_mode={UINT32_C(0x6032004D),"qpic_mode",sxnx_qpic_mode_fields,SX_COUNT(sxnx_qpic_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_flags_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxnx_qpic_flags={UINT32_C(0x6032004E),"qpic_flags",sxnx_qpic_flags_fields,SX_COUNT(sxnx_qpic_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_raster_operation_fields[]={
 SX_FIELD("raster_operation","int32",0,4,SX_ID),
};
const sx_layout sxnx_qpic_raster_operation={UINT32_C(0x6032004F),"qpic_raster_operation",sxnx_qpic_raster_operation_fields,SX_COUNT(sxnx_qpic_raster_operation_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_boolean_fields[]={
 SX_FIELD("enabled","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnx_qpic_boolean={UINT32_C(0x60320050),"qpic_boolean",sxnx_qpic_boolean_fields,SX_COUNT(sxnx_qpic_boolean_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_qpic_opacity_fields[]={
 SX_FIELD("opacity","double",0,8,SX_NONE),
};
const sx_layout sxnx_qpic_opacity={UINT32_C(0x60320051),"qpic_opacity",sxnx_qpic_opacity_fields,SX_COUNT(sxnx_qpic_opacity_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_qpic(sxnx_view*v)
{if(!SN_ROW(qpic_header,0,v->n))return false;unsigned count=sxnx_u32(v->p+28,true);if(count>4095)return false;size_t p=32;for(unsigned i=0;i<count;i++){if(!sxnx_need(v,p,2,v->n))return false;unsigned op=v->p[p],n=v->p[p+1];if(n==255){if(!SN_ROW(qpic_record_long,p,v->n))return false;n=sxnx_u32(v->p+p+2,true);p+=6;}else{if(!SN_ROW(qpic_record,p,v->n))return false;p+=2;}if(!sxnx_need(v,p,n,v->n))return false;size_t end=p+n;const sx_layout*l=NULL;
 if(op==1)l=&sxnx_qpic_point;else if(op==4)l=&sxnx_qpic_line;else if(op==5||op==7)l=&sxnx_qpic_rectangle;else if(op==6||(op>=8&&op<=10)){if(!SN_ROW(qpic_rectangle,p,end)||!sxnx_row(v,op==6?&sxnx_qpic_rounding:&sxnx_qpic_angles,p+32,end))return false;}else if(op==12||op==13){if(!SN_ROW(qpic_point_count,p,end))return false;unsigned num=sxnx_u32(v->p+p,true);if(!sxnx_table(v,&sxnx_qpic_point,p+4,num,end))return false;if(op==13&&!SN_ROW(qpic_fill_rule,p+4+(size_t)num*16,end))return false;}else if(op==41||op==64)l=&sxnx_qpic_mode;else if(op==42)l=&sxnx_qpic_raster_operation;else if(op==63)l=&sxnx_qpic_flags;else if(op==65)l=&sxnx_qpic_boolean;else if(op==66)l=&sxnx_qpic_opacity;if(l&&!sxnx_row(v,l,p,end))return false;p=end;}return p==v->n;}
bool sx_qt_qpicture_build(sxnx_view*v)
{
 return sxnx_qpic(v);
}
#undef SN_ROW
