/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * usgs dem data structures, moved out of the vectortext schema family. */
#include "../../xx_format_schema_vectortext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvtx_profile_count_fields[]={
 SX_FIELD("profile_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxvtx_profile_count={0x6062003cU,"vectortext_profile_count",sxvtx_profile_count_fields,SX_COUNT(sxvtx_profile_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_row_count_fields[]={
 SX_FIELD("row_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxvtx_row_count={0x6062003dU,"vectortext_row_count",sxvtx_row_count_fields,SX_COUNT(sxvtx_row_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_column_number_fields[]={
 SX_FIELD("column_number","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_column_number={0x6062003eU,"vectortext_column_number",sxvtx_column_number_fields,SX_COUNT(sxvtx_column_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_elevation_sample_fields[]={
 SX_FIELD("elevation_sample","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_elevation_sample={0x6062003fU,"vectortext_elevation_sample",sxvtx_elevation_sample_fields,SX_COUNT(sxvtx_elevation_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_level_fields[]={
 SX_FIELD("dem_level","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_level={0x60620040U,"vectortext_dem_level",sxvtx_dem_level_fields,SX_COUNT(sxvtx_dem_level_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_elevation_pattern_fields[]={
 SX_FIELD("elevation_pattern","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_elevation_pattern={0x60620041U,"vectortext_elevation_pattern",sxvtx_elevation_pattern_fields,SX_COUNT(sxvtx_elevation_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_reference_system_fields[]={
 SX_FIELD("reference_system","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_reference_system={0x60620042U,"vectortext_reference_system",sxvtx_reference_system_fields,SX_COUNT(sxvtx_reference_system_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_zone_fields[]={
 SX_FIELD("zone","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_zone={0x60620043U,"vectortext_zone",sxvtx_zone_fields,SX_COUNT(sxvtx_zone_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_ground_unit_fields[]={
 SX_FIELD("ground_unit","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_ground_unit={0x60620044U,"vectortext_ground_unit",sxvtx_ground_unit_fields,SX_COUNT(sxvtx_ground_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_elevation_unit_fields[]={
 SX_FIELD("elevation_unit","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_elevation_unit={0x60620045U,"vectortext_elevation_unit",sxvtx_elevation_unit_fields,SX_COUNT(sxvtx_elevation_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_polygon_side_count_fields[]={
 SX_FIELD("polygon_side_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxvtx_polygon_side_count={0x60620046U,"vectortext_polygon_side_count",sxvtx_polygon_side_count_fields,SX_COUNT(sxvtx_polygon_side_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_accuracy_code_fields[]={
 SX_FIELD("accuracy_code","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_accuracy_code={0x60620047U,"vectortext_accuracy_code",sxvtx_accuracy_code_fields,SX_COUNT(sxvtx_accuracy_code_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_row_number_fields[]={
 SX_FIELD("row_number","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_row_number={0x60620086U,"vectortext_row_number",sxvtx_row_number_fields,SX_COUNT(sxvtx_row_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_x_fields[]={
 SX_FIELD("dem_x","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_x={0x60620092U,"vectortext_dem_x",sxvtx_dem_x_fields,SX_COUNT(sxvtx_dem_x_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_y_fields[]={
 SX_FIELD("dem_y","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_y={0x60620093U,"vectortext_dem_y",sxvtx_dem_y_fields,SX_COUNT(sxvtx_dem_y_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_coordinate_value_fields[]={
 SX_FIELD("dem_coordinate_value","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_coordinate_value={0x60620094U,"vectortext_dem_coordinate_value",sxvtx_dem_coordinate_value_fields,SX_COUNT(sxvtx_dem_coordinate_value_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_minimum_elevation_fields[]={
 SX_FIELD("dem_minimum_elevation","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_minimum_elevation={0x60620095U,"vectortext_dem_minimum_elevation",sxvtx_dem_minimum_elevation_fields,SX_COUNT(sxvtx_dem_minimum_elevation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_maximum_elevation_fields[]={
 SX_FIELD("dem_maximum_elevation","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_maximum_elevation={0x60620096U,"vectortext_dem_maximum_elevation",sxvtx_dem_maximum_elevation_fields,SX_COUNT(sxvtx_dem_maximum_elevation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_rotation_fields[]={
 SX_FIELD("dem_rotation","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_rotation={0x60620097U,"vectortext_dem_rotation",sxvtx_dem_rotation_fields,SX_COUNT(sxvtx_dem_rotation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_x_resolution_fields[]={
 SX_FIELD("dem_x_resolution","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_x_resolution={0x60620098U,"vectortext_dem_x_resolution",sxvtx_dem_x_resolution_fields,SX_COUNT(sxvtx_dem_x_resolution_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_y_resolution_fields[]={
 SX_FIELD("dem_y_resolution","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_y_resolution={0x60620099U,"vectortext_dem_y_resolution",sxvtx_dem_y_resolution_fields,SX_COUNT(sxvtx_dem_y_resolution_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_z_resolution_fields[]={
 SX_FIELD("dem_z_resolution","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_z_resolution={0x6062009aU,"vectortext_dem_z_resolution",sxvtx_dem_z_resolution_fields,SX_COUNT(sxvtx_dem_z_resolution_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_elevation_datum_fields[]={
 SX_FIELD("dem_elevation_datum","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_elevation_datum={0x6062009bU,"vectortext_dem_elevation_datum",sxvtx_dem_elevation_datum_fields,SX_COUNT(sxvtx_dem_elevation_datum_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_projection_parameter_fields[]={
 SX_FIELD("dem_projection_parameter","ascii_fortran_real",0,0,SX_NONE),
};
const sx_layout sxvtx_dem_projection_parameter={0x6062009cU,"vectortext_dem_projection_parameter",sxvtx_dem_projection_parameter_fields,SX_COUNT(sxvtx_dem_projection_parameter_fields),SX_LE};
#define VT_EMIT(n,a,z) do{if(!sxvtx_emit(q,&sxvtx_##n,(a),(z)))return false;}while(0)
static bool sxvtx_dem(sxvtx_cursor*q)
{
 if(q->n<2048)return false;int64_t stride=q->b[1024]=='\n'?1025:q->b[1024]=='\r'&&q->b[1025]=='\n'?1026:1024;if(q->n%stride)return false;
 VT_EMIT(record_text,0,144);
 const sx_layout*head[]={&sxvtx_dem_level,&sxvtx_elevation_pattern,&sxvtx_reference_system,&sxvtx_zone};for(unsigned i=0;i<4;i++)if(!sxvtx_emit(q,head[i],144+6*i,6))return false;
 for(unsigned i=0;i<15;i++)if(sxvtx_nonblank(q,168+24*i,24)&&!sxvtx_emit(q,&sxvtx_dem_projection_parameter,168+24*i,24))return false;
 VT_EMIT(ground_unit,528,6);VT_EMIT(elevation_unit,534,6);VT_EMIT(polygon_side_count,540,6);
 for(unsigned i=0;i<8;i++)VT_EMIT(dem_coordinate_value,546+24*i,24);
 VT_EMIT(dem_minimum_elevation,738,24);VT_EMIT(dem_maximum_elevation,762,24);VT_EMIT(dem_rotation,786,24);VT_EMIT(accuracy_code,810,6);
 VT_EMIT(dem_x_resolution,816,12);VT_EMIT(dem_y_resolution,828,12);VT_EMIT(dem_z_resolution,840,12);VT_EMIT(row_count,852,6);VT_EMIT(profile_count,858,6);
 uint64_t count=0;if(!sxvtx_uint_at(q,858,6,&count)||count>4000)return false;int64_t logical=1024,available=q->n/stride*1024;
 for(uint64_t i=0;i<count;i++){
  if(q->c->count>=32000)return true;int64_t a=logical/1024*stride;if(logical>available-144)return false;
  uint64_t rows=0;if(!sxvtx_uint_at(q,a+12,6,&rows)||rows>1000000)return false;
  VT_EMIT(row_number,a,6);VT_EMIT(column_number,a+6,6);VT_EMIT(row_count,a+12,6);VT_EMIT(column_count,a+18,6);
  VT_EMIT(dem_x,a+24,24);VT_EMIT(dem_y,a+48,24);VT_EMIT(dem_elevation_datum,a+72,24);VT_EMIT(dem_minimum_elevation,a+96,24);VT_EMIT(dem_maximum_elevation,a+120,24);logical+=144;
  for(uint64_t j=0;j<rows;j++){
   if(q->c->count>=32000)return true;if(logical%1024>1018)logical=(logical+1023)/1024*1024;if(logical>available-6)return false;
   VT_EMIT(elevation_sample,logical/1024*stride+logical%1024,6);logical+=6;
  }
  logical=(logical+1023)/1024*1024;
 }
 return logical==available;
}
bool sx_usgs_dem_build(sxvtx_cursor*q)
{
 return sxvtx_dem(q);
}
#undef VT_EMIT
