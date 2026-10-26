/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * xfig data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_fig_orientation_fields[]={
 SX_FIELD("fig_orientation","char",0,0,SX_STRING),
};
const sx_layout sxmt_fig_orientation={0x60520080U,"modeltext_fig_orientation",sxmt_fig_orientation_fields,SX_COUNT(sxmt_fig_orientation_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_justification_fields[]={
 SX_FIELD("fig_justification","char",0,0,SX_STRING),
};
const sx_layout sxmt_fig_justification={0x60520081U,"modeltext_fig_justification",sxmt_fig_justification_fields,SX_COUNT(sxmt_fig_justification_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_units_fields[]={
 SX_FIELD("fig_units","char",0,0,SX_STRING),
};
const sx_layout sxmt_fig_units={0x60520082U,"modeltext_fig_units",sxmt_fig_units_fields,SX_COUNT(sxmt_fig_units_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_paper_size_fields[]={
 SX_FIELD("fig_paper_size","char",0,0,SX_STRING),
};
const sx_layout sxmt_fig_paper_size={0x60520083U,"modeltext_fig_paper_size",sxmt_fig_paper_size_fields,SX_COUNT(sxmt_fig_paper_size_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_page_mode_fields[]={
 SX_FIELD("fig_page_mode","char",0,0,SX_STRING),
};
const sx_layout sxmt_fig_page_mode={0x60520084U,"modeltext_fig_page_mode",sxmt_fig_page_mode_fields,SX_COUNT(sxmt_fig_page_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_object_code_fields[]={
 SX_FIELD("fig_object_code","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_object_code={0x60520085U,"modeltext_fig_object_code",sxmt_fig_object_code_fields,SX_COUNT(sxmt_fig_object_code_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_subtype_fields[]={
 SX_FIELD("fig_subtype","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_subtype={0x60520086U,"modeltext_fig_subtype",sxmt_fig_subtype_fields,SX_COUNT(sxmt_fig_subtype_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_line_style_fields[]={
 SX_FIELD("fig_line_style","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_line_style={0x60520087U,"modeltext_fig_line_style",sxmt_fig_line_style_fields,SX_COUNT(sxmt_fig_line_style_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_thickness_fields[]={
 SX_FIELD("fig_thickness","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_thickness={0x60520088U,"modeltext_fig_thickness",sxmt_fig_thickness_fields,SX_COUNT(sxmt_fig_thickness_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_pen_color_fields[]={
 SX_FIELD("fig_pen_color","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_pen_color={0x60520089U,"modeltext_fig_pen_color",sxmt_fig_pen_color_fields,SX_COUNT(sxmt_fig_pen_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_fill_color_fields[]={
 SX_FIELD("fig_fill_color","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_fill_color={0x6052008aU,"modeltext_fig_fill_color",sxmt_fig_fill_color_fields,SX_COUNT(sxmt_fig_fill_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_depth_fields[]={
 SX_FIELD("fig_depth","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_depth={0x6052008bU,"modeltext_fig_depth",sxmt_fig_depth_fields,SX_COUNT(sxmt_fig_depth_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_pen_style_fields[]={
 SX_FIELD("fig_pen_style","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_pen_style={0x6052008cU,"modeltext_fig_pen_style",sxmt_fig_pen_style_fields,SX_COUNT(sxmt_fig_pen_style_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_area_fill_fields[]={
 SX_FIELD("fig_area_fill","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_area_fill={0x6052008dU,"modeltext_fig_area_fill",sxmt_fig_area_fill_fields,SX_COUNT(sxmt_fig_area_fill_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_direction_fields[]={
 SX_FIELD("fig_direction","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_direction={0x6052008eU,"modeltext_fig_direction",sxmt_fig_direction_fields,SX_COUNT(sxmt_fig_direction_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_center_x_fields[]={
 SX_FIELD("fig_center_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_center_x={0x6052008fU,"modeltext_fig_center_x",sxmt_fig_center_x_fields,SX_COUNT(sxmt_fig_center_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_center_y_fields[]={
 SX_FIELD("fig_center_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_center_y={0x60520090U,"modeltext_fig_center_y",sxmt_fig_center_y_fields,SX_COUNT(sxmt_fig_center_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_radius_x_fields[]={
 SX_FIELD("fig_radius_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_radius_x={0x60520091U,"modeltext_fig_radius_x",sxmt_fig_radius_x_fields,SX_COUNT(sxmt_fig_radius_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_radius_y_fields[]={
 SX_FIELD("fig_radius_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_radius_y={0x60520092U,"modeltext_fig_radius_y",sxmt_fig_radius_y_fields,SX_COUNT(sxmt_fig_radius_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_start_x_fields[]={
 SX_FIELD("fig_start_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_start_x={0x60520093U,"modeltext_fig_start_x",sxmt_fig_start_x_fields,SX_COUNT(sxmt_fig_start_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_start_y_fields[]={
 SX_FIELD("fig_start_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_start_y={0x60520094U,"modeltext_fig_start_y",sxmt_fig_start_y_fields,SX_COUNT(sxmt_fig_start_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_end_x_fields[]={
 SX_FIELD("fig_end_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_end_x={0x60520095U,"modeltext_fig_end_x",sxmt_fig_end_x_fields,SX_COUNT(sxmt_fig_end_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_end_y_fields[]={
 SX_FIELD("fig_end_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_end_y={0x60520096U,"modeltext_fig_end_y",sxmt_fig_end_y_fields,SX_COUNT(sxmt_fig_end_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_join_style_fields[]={
 SX_FIELD("fig_join_style","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_join_style={0x60520097U,"modeltext_fig_join_style",sxmt_fig_join_style_fields,SX_COUNT(sxmt_fig_join_style_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_cap_style_fields[]={
 SX_FIELD("fig_cap_style","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_cap_style={0x60520098U,"modeltext_fig_cap_style",sxmt_fig_cap_style_fields,SX_COUNT(sxmt_fig_cap_style_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_radius_fields[]={
 SX_FIELD("fig_radius","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_radius={0x60520099U,"modeltext_fig_radius",sxmt_fig_radius_fields,SX_COUNT(sxmt_fig_radius_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_forward_arrow_fields[]={
 SX_FIELD("fig_forward_arrow","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_forward_arrow={0x6052009aU,"modeltext_fig_forward_arrow",sxmt_fig_forward_arrow_fields,SX_COUNT(sxmt_fig_forward_arrow_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_backward_arrow_fields[]={
 SX_FIELD("fig_backward_arrow","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_backward_arrow={0x6052009bU,"modeltext_fig_backward_arrow",sxmt_fig_backward_arrow_fields,SX_COUNT(sxmt_fig_backward_arrow_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_point_count_fields[]={
 SX_FIELD("fig_point_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_fig_point_count={0x6052009cU,"modeltext_fig_point_count",sxmt_fig_point_count_fields,SX_COUNT(sxmt_fig_point_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_color_index_fields[]={
 SX_FIELD("fig_color_index","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_color_index={0x6052009dU,"modeltext_fig_color_index",sxmt_fig_color_index_fields,SX_COUNT(sxmt_fig_color_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_transparent_color_fields[]={
 SX_FIELD("fig_transparent_color","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_transparent_color={0x6052009eU,"modeltext_fig_transparent_color",sxmt_fig_transparent_color_fields,SX_COUNT(sxmt_fig_transparent_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_resolution_fields[]={
 SX_FIELD("fig_resolution","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_resolution={0x6052009fU,"modeltext_fig_resolution",sxmt_fig_resolution_fields,SX_COUNT(sxmt_fig_resolution_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_coordinate_system_fields[]={
 SX_FIELD("fig_coordinate_system","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_fig_coordinate_system={0x605200a0U,"modeltext_fig_coordinate_system",sxmt_fig_coordinate_system_fields,SX_COUNT(sxmt_fig_coordinate_system_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_magnification_fields[]={
 SX_FIELD("fig_magnification","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_fig_magnification={0x605200a1U,"modeltext_fig_magnification",sxmt_fig_magnification_fields,SX_COUNT(sxmt_fig_magnification_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_style_value_fields[]={
 SX_FIELD("fig_style_value","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_fig_style_value={0x605200a2U,"modeltext_fig_style_value",sxmt_fig_style_value_fields,SX_COUNT(sxmt_fig_style_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_angle_fields[]={
 SX_FIELD("fig_angle","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_fig_angle={0x605200a3U,"modeltext_fig_angle",sxmt_fig_angle_fields,SX_COUNT(sxmt_fig_angle_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_rgb_fields[]={
 SX_FIELD("fig_rgb","ascii_hex",0,0,SX_FLAGS),
};
const sx_layout sxmt_fig_rgb={0x605200a4U,"modeltext_fig_rgb",sxmt_fig_rgb_fields,SX_COUNT(sxmt_fig_rgb_fields),SX_LE};
#define MT_VALUE(n,e,v) do{if(!sxmt_value(q,&sxmt_##n,(e),(v)))return false;}while(0)
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
static bool sxmt_fig(sxmt_cursor*q){int64_t a,e;unsigned stage=0;const sx_layout*header[]={&sxmt_signature,&sxmt_fig_orientation,&sxmt_fig_justification,&sxmt_fig_units,&sxmt_fig_paper_size,&sxmt_fig_magnification,&sxmt_fig_page_mode,&sxmt_fig_transparent_color};
 while(stage<9&&sxmt_line(q,&a,&e,false)){if(stage&&q->b[a]=='#')continue;if(stage<8){if(!sxmt_emit(q,header[stage],a,e-a))return false;}else{int64_t next=q->p;q->p=a;MT_VALUE(fig_resolution,e,NULL);MT_VALUE(fig_coordinate_system,e,NULL);q->p=next;}stage++;}if(stage!=9)return false;
 const sx_layout*common[]={&sxmt_fig_object_code,&sxmt_fig_subtype,&sxmt_fig_line_style,&sxmt_fig_thickness,&sxmt_fig_pen_color,&sxmt_fig_fill_color,&sxmt_fig_depth,&sxmt_fig_pen_style,&sxmt_fig_area_fill,&sxmt_fig_style_value};
 const sx_layout*ellipse[]={&sxmt_fig_direction,&sxmt_fig_angle,&sxmt_fig_center_x,&sxmt_fig_center_y,&sxmt_fig_radius_x,&sxmt_fig_radius_y,&sxmt_fig_start_x,&sxmt_fig_start_y,&sxmt_fig_end_x,&sxmt_fig_end_y};
 const sx_layout*poly[]={&sxmt_fig_join_style,&sxmt_fig_cap_style,&sxmt_fig_radius,&sxmt_fig_forward_arrow,&sxmt_fig_backward_arrow,&sxmt_fig_point_count};
 while(sxmt_line(q,&a,&e,false)){if(q->b[a]=='#')continue;if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;uint64_t kind;MT_VALUE(fig_object_code,e,&kind);
 if(kind==0){MT_VALUE(fig_color_index,e,NULL);int64_t z;if(!sxmt_token(q,e,&a,&z,false)||z!=7||q->b[a]!='#')return false;MT_EMIT(fig_rgb,a+1,6);q->p=next;continue;}
 if(kind!=1&&kind!=2)return false;for(unsigned i=1;i<10;i++)if(!sxmt_value(q,common[i],e,NULL))return false;uint64_t points=0;unsigned n=kind==1?10:6;for(unsigned i=0;i<n;i++)if(!sxmt_value(q,kind==1?ellipse[i]:poly[i],e,kind==2&&i==5?&points:NULL))return false;q->p=next;
 if(points>65536)return false;for(uint64_t i=0;i<points;i++){if(q->c->count>=32000)return true;MT_VALUE(x,q->n,NULL);MT_VALUE(y,q->n,NULL);}
 }return true;}
bool sx_xfig_build(sxmt_cursor*q)
{
 return sxmt_fig(q);
}
#undef MT_VALUE
#undef MT_EMIT
