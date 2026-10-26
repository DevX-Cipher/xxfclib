/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Tecplot PLT data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_tecplot_prefix_le_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("byte_order","int32",8,4,SX_ID),
    SX_FIELD("file_type","int32",12,4,SX_ID),
};
const sx_layout sxsw_tecplot_prefix_le = {UINT32_C(0x602d0070),"tecplot_prefix_le",sxsw_tecplot_prefix_le_fields,SX_COUNT(sxsw_tecplot_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_codepoint_le_fields[] = {
    SX_FIELD("character","int32",0,4,SX_NONE),
};
const sx_layout sxsw_tecplot_codepoint_le = {UINT32_C(0x602d0071),"tecplot_codepoint_le",sxsw_tecplot_codepoint_le_fields,SX_COUNT(sxsw_tecplot_codepoint_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_variable_count_le_fields[] = {
    SX_FIELD("variable_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsw_tecplot_variable_count_le = {UINT32_C(0x602d0072),"tecplot_variable_count_le",sxsw_tecplot_variable_count_le_fields,SX_COUNT(sxsw_tecplot_variable_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_marker_le_fields[] = {
    SX_FIELD("marker","float32",0,4,SX_NONE),
};
const sx_layout sxsw_tecplot_marker_le = {UINT32_C(0x602d0073),"tecplot_marker_le",sxsw_tecplot_marker_le_fields,SX_COUNT(sxsw_tecplot_marker_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_ordered_zone_le_fields[] = {
    SX_FIELD("parent_zone","int32",0,4,SX_ID),
    SX_FIELD("strand_id","int32",4,4,SX_ID),
    SX_FIELD("solution_time","float64",8,8,SX_NONE),
    SX_FIELD("zone_color","int32",16,4,SX_ID),
    SX_FIELD("zone_type","int32",20,4,SX_ID),
    SX_FIELD("specify_variable_location","int32",24,4,SX_FLAGS),
    SX_FIELD("raw_local_face_neighbors","int32",28,4,SX_FLAGS),
    SX_FIELD("miscellaneous_face_neighbor_count","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("dimension_i","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("dimension_j","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("dimension_k","int32",44,4,SX_COUNT_PROP),
};
const sx_layout sxsw_tecplot_ordered_zone_le = {UINT32_C(0x602d0074),"tecplot_ordered_zone_le",sxsw_tecplot_ordered_zone_le_fields,SX_COUNT(sxsw_tecplot_ordered_zone_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_auxiliary_flag_le_fields[] = {
    SX_FIELD("auxiliary_data","int32",0,4,SX_FLAGS),
};
const sx_layout sxsw_tecplot_auxiliary_flag_le = {UINT32_C(0x602d0075),"tecplot_auxiliary_flag_le",sxsw_tecplot_auxiliary_flag_le_fields,SX_COUNT(sxsw_tecplot_auxiliary_flag_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_data_flags_le_fields[] = {
    SX_FIELD("passive_variables","int32",0,4,SX_FLAGS),
    SX_FIELD("variable_sharing","int32",4,4,SX_FLAGS),
    SX_FIELD("connectivity_sharing","int32",8,4,SX_ID),
};
const sx_layout sxsw_tecplot_data_flags_le = {UINT32_C(0x602d0077),"tecplot_data_flags_le",sxsw_tecplot_data_flags_le_fields,SX_COUNT(sxsw_tecplot_data_flags_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_range_le_fields[] = {
    SX_FIELD("minimum","float64",0,8,SX_NONE),
    SX_FIELD("maximum","float64",8,8,SX_NONE),
};
const sx_layout sxsw_tecplot_range_le = {UINT32_C(0x602d0078),"tecplot_range_le",sxsw_tecplot_range_le_fields,SX_COUNT(sxsw_tecplot_range_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_tecplot_prefix_be_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("byte_order","int32",8,4,SX_ID),
    SX_FIELD("file_type","int32",12,4,SX_ID),
};
const sx_layout sxsw_tecplot_prefix_be = {UINT32_C(0x602d0079),"tecplot_prefix_be",sxsw_tecplot_prefix_be_fields,SX_COUNT(sxsw_tecplot_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_codepoint_be_fields[] = {
    SX_FIELD("character","int32",0,4,SX_NONE),
};
const sx_layout sxsw_tecplot_codepoint_be = {UINT32_C(0x602d007a),"tecplot_codepoint_be",sxsw_tecplot_codepoint_be_fields,SX_COUNT(sxsw_tecplot_codepoint_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_variable_count_be_fields[] = {
    SX_FIELD("variable_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsw_tecplot_variable_count_be = {UINT32_C(0x602d007b),"tecplot_variable_count_be",sxsw_tecplot_variable_count_be_fields,SX_COUNT(sxsw_tecplot_variable_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_marker_be_fields[] = {
    SX_FIELD("marker","float32",0,4,SX_NONE),
};
const sx_layout sxsw_tecplot_marker_be = {UINT32_C(0x602d007c),"tecplot_marker_be",sxsw_tecplot_marker_be_fields,SX_COUNT(sxsw_tecplot_marker_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_ordered_zone_be_fields[] = {
    SX_FIELD("parent_zone","int32",0,4,SX_ID),
    SX_FIELD("strand_id","int32",4,4,SX_ID),
    SX_FIELD("solution_time","float64",8,8,SX_NONE),
    SX_FIELD("zone_color","int32",16,4,SX_ID),
    SX_FIELD("zone_type","int32",20,4,SX_ID),
    SX_FIELD("specify_variable_location","int32",24,4,SX_FLAGS),
    SX_FIELD("raw_local_face_neighbors","int32",28,4,SX_FLAGS),
    SX_FIELD("miscellaneous_face_neighbor_count","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("dimension_i","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("dimension_j","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("dimension_k","int32",44,4,SX_COUNT_PROP),
};
const sx_layout sxsw_tecplot_ordered_zone_be = {UINT32_C(0x602d007d),"tecplot_ordered_zone_be",sxsw_tecplot_ordered_zone_be_fields,SX_COUNT(sxsw_tecplot_ordered_zone_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_auxiliary_flag_be_fields[] = {
    SX_FIELD("auxiliary_data","int32",0,4,SX_FLAGS),
};
const sx_layout sxsw_tecplot_auxiliary_flag_be = {UINT32_C(0x602d007e),"tecplot_auxiliary_flag_be",sxsw_tecplot_auxiliary_flag_be_fields,SX_COUNT(sxsw_tecplot_auxiliary_flag_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_data_flags_be_fields[] = {
    SX_FIELD("passive_variables","int32",0,4,SX_FLAGS),
    SX_FIELD("variable_sharing","int32",4,4,SX_FLAGS),
    SX_FIELD("connectivity_sharing","int32",8,4,SX_ID),
};
const sx_layout sxsw_tecplot_data_flags_be = {UINT32_C(0x602d0080),"tecplot_data_flags_be",sxsw_tecplot_data_flags_be_fields,SX_COUNT(sxsw_tecplot_data_flags_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_tecplot_range_be_fields[] = {
    SX_FIELD("minimum","float64",0,8,SX_NONE),
    SX_FIELD("maximum","float64",8,8,SX_NONE),
};
const sx_layout sxsw_tecplot_range_be = {UINT32_C(0x602d0081),"tecplot_range_be",sxsw_tecplot_range_be_fields,SX_COUNT(sxsw_tecplot_range_be_fields),SX_BE};
static bool sxsw_tec_string(sx_context *c,int64_t *at,bool be)
{
 uint32_t n;int64_t begin=*at;for(unsigned i=0;i<4096;i++){if(!sx_u32(c,*at,be,&n)||n>127)return false;*at+=4;if(!n)return sxsw_table(c,be?&sxsw_tecplot_codepoint_be:&sxsw_tecplot_codepoint_le,begin,4,i+1);}return false;
}
static bool sxsw_tecplot(sx_context *c)
{
 uint32_t x,vars;uint64_t points[32];unsigned zones=0;int64_t at=16;
 if(!sx_u32(c,8,false,&x))return false;bool be=x!=1;
 if(!sxsw_add(c,be?&sxsw_tecplot_prefix_be:&sxsw_tecplot_prefix_le,0,16)||!sxsw_tec_string(c,&at,be)||!sx_u32(c,at,be,&vars)||!vars||vars>64||!sxsw_add(c,be?&sxsw_tecplot_variable_count_be:&sxsw_tecplot_variable_count_le,at,4))return false;at+=4;
 for(uint32_t i=0;i<vars;i++)if(!sxsw_tec_string(c,&at,be))return false;
 while(true){if(!sx_u32(c,at,be,&x)||!sxsw_add(c,be?&sxsw_tecplot_marker_be:&sxsw_tecplot_marker_le,at,4))return false;at+=4;if(x==0x43b28000U)break;
  uint8_t b[48];if(x!=0x43958000U||zones>=32||!sxsw_tec_string(c,&at,be)||!sx_read(c,at,b,48)||!sxsw_add(c,be?&sxsw_tecplot_ordered_zone_be:&sxsw_tecplot_ordered_zone_le,at,48))return false;
  uint64_t count=1;for(unsigned i=0;i<3;i++){uint32_t dim=sxsw32(b+36+i*4,be);if(!dim||count>1048576/dim)return false;count*=dim;}points[zones++]=count;at+=48;
  if(!sxsw_add(c,be?&sxsw_tecplot_auxiliary_flag_be:&sxsw_tecplot_auxiliary_flag_le,at,4))return false;at+=4;
 }
 for(unsigned z=0;z<zones;z++){
  uint32_t types[64];if(!sxsw_add(c,be?&sxsw_tecplot_marker_be:&sxsw_tecplot_marker_le,at,4)||!sxsw_table(c,be?&sxsw_tecplot_variable_type_be:&sxsw_tecplot_variable_type_le,at+4,4,vars))return false;at+=4;
  for(uint32_t i=0;i<vars;i++){if(!sx_u32(c,at,be,&types[i])||types[i]<1||types[i]>5)return false;at+=4;}
  if(!sxsw_add(c,be?&sxsw_tecplot_data_flags_be:&sxsw_tecplot_data_flags_le,at,12)||!sxsw_table(c,be?&sxsw_tecplot_range_be:&sxsw_tecplot_range_le,at+12,16,vars))return false;at+=12+vars*16;
  for(uint32_t i=0;i<vars;i++){unsigned width=types[i]==2?8:types[i]<=3?4:types[i]==4?2:1;uint64_t bytes=points[z]*width;if(!sxsw_span(c,at,bytes))return false;at+=(int64_t)bytes;}
 }return at==c->size;
}
bool sx_tecplot_plt_build(sx_context*c)
{
 return sxsw_tecplot(c);
}
