/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * iges model data structures, moved out of the vectortext schema family. */
#include "../../xx_format_schema_vectortext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvtx_entity_type_fields[]={
 SX_FIELD("entity_type","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_entity_type={0x60620034U,"vectortext_entity_type",sxvtx_entity_type_fields,SX_COUNT(sxvtx_entity_type_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_directory_reference_fields[]={
 SX_FIELD("directory_reference","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_directory_reference={0x60620035U,"vectortext_directory_reference",sxvtx_directory_reference_fields,SX_COUNT(sxvtx_directory_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_parameter_reference_fields[]={
 SX_FIELD("parameter_reference","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_parameter_reference={0x60620036U,"vectortext_parameter_reference",sxvtx_parameter_reference_fields,SX_COUNT(sxvtx_parameter_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_level_fields[]={
 SX_FIELD("level","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_level={0x60620037U,"vectortext_level",sxvtx_level_fields,SX_COUNT(sxvtx_level_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_line_font_pattern_fields[]={
 SX_FIELD("line_font_pattern","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_line_font_pattern={0x60620038U,"vectortext_line_font_pattern",sxvtx_line_font_pattern_fields,SX_COUNT(sxvtx_line_font_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_line_weight_fields[]={
 SX_FIELD("line_weight","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_line_weight={0x60620039U,"vectortext_line_weight",sxvtx_line_weight_fields,SX_COUNT(sxvtx_line_weight_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_color_number_fields[]={
 SX_FIELD("color_number","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_color_number={0x6062003aU,"vectortext_color_number",sxvtx_color_number_fields,SX_COUNT(sxvtx_color_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_form_number_fields[]={
 SX_FIELD("form_number","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_form_number={0x6062003bU,"vectortext_form_number",sxvtx_form_number_fields,SX_COUNT(sxvtx_form_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_structure_reference_fields[]={
 SX_FIELD("structure_reference","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_structure_reference={0x60620088U,"vectortext_structure_reference",sxvtx_structure_reference_fields,SX_COUNT(sxvtx_structure_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_view_reference_fields[]={
 SX_FIELD("view_reference","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_view_reference={0x60620089U,"vectortext_view_reference",sxvtx_view_reference_fields,SX_COUNT(sxvtx_view_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_transform_reference_fields[]={
 SX_FIELD("transform_reference","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_transform_reference={0x6062008aU,"vectortext_transform_reference",sxvtx_transform_reference_fields,SX_COUNT(sxvtx_transform_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_label_display_reference_fields[]={
 SX_FIELD("label_display_reference","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_label_display_reference={0x6062008bU,"vectortext_label_display_reference",sxvtx_label_display_reference_fields,SX_COUNT(sxvtx_label_display_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_parameter_line_count_fields[]={
 SX_FIELD("parameter_line_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxvtx_parameter_line_count={0x6062008cU,"vectortext_parameter_line_count",sxvtx_parameter_line_count_fields,SX_COUNT(sxvtx_parameter_line_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_entity_subscript_fields[]={
 SX_FIELD("entity_subscript","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_entity_subscript={0x6062008dU,"vectortext_entity_subscript",sxvtx_entity_subscript_fields,SX_COUNT(sxvtx_entity_subscript_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_section_record_count_fields[]={
 SX_FIELD("section_record_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxvtx_section_record_count={0x6062008eU,"vectortext_section_record_count",sxvtx_section_record_count_fields,SX_COUNT(sxvtx_section_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_iges_status_fields[]={
 SX_FIELD("iges_status","char",0,0,SX_STRING),
};
const sx_layout sxvtx_iges_status={0x6062009dU,"vectortext_iges_status",sxvtx_iges_status_fields,SX_COUNT(sxvtx_iges_status_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_iges_record_label_fields[]={
 SX_FIELD("section","char[1]",0,1,SX_STRING),
 SX_FIELD("sequence_number","ascii_signed[7]",1,7,SX_NONE),
};
const sx_layout sxvtx_iges_record_label={0x606200a5U,"vectortext_iges_record_label",sxvtx_iges_record_label_fields,SX_COUNT(sxvtx_iges_record_label_fields),SX_LE};
#define VT_EMIT(n,a,z) do{if(!sxvtx_emit(q,&sxvtx_##n,(a),(z)))return false;}while(0)
static bool sxvtx_iges(sxvtx_cursor*q)
{
 int64_t p=0;unsigned directory=0;
 while(p<q->n){
  if(q->c->count>=32000)return true;if(q->n-p<81)return false;unsigned section=q->b[p+72];VT_EMIT(iges_record_label,p+72,8);
  if(section=='D'){
   const sx_layout*first[]={&sxvtx_entity_type,&sxvtx_parameter_reference,&sxvtx_structure_reference,&sxvtx_line_font_pattern,&sxvtx_level,&sxvtx_view_reference,&sxvtx_transform_reference,&sxvtx_label_display_reference,&sxvtx_iges_status};
   const sx_layout*second[]={&sxvtx_entity_type,&sxvtx_line_weight,&sxvtx_color_number,&sxvtx_parameter_line_count,&sxvtx_form_number};
   if(!(directory++&1)){for(unsigned i=0;i<9;i++)if(sxvtx_nonblank(q,p+i*8,8)&&!sxvtx_emit(q,first[i],p+i*8,8))return false;}
   else {for(unsigned i=0;i<5;i++)if(sxvtx_nonblank(q,p+i*8,8)&&!sxvtx_emit(q,second[i],p+i*8,8))return false;if(sxvtx_nonblank(q,p+56,8))VT_EMIT(name,p+56,8);if(sxvtx_nonblank(q,p+64,8))VT_EMIT(entity_subscript,p+64,8);}
  }else if(section=='T'){
   for(unsigned i=0;i<4;i++){VT_EMIT(keyword,p+i*8,1);VT_EMIT(section_record_count,p+i*8+1,7);}
  }else if(section=='P'){
   VT_EMIT(record_text,p,64);if(sxvtx_nonblank(q,p+64,8))VT_EMIT(directory_reference,p+64,8);
  }else if(section=='S'||section=='G'){VT_EMIT(record_text,p,72);}else return false;
  p+=80;if(p<q->n&&q->b[p]=='\r')p++;if(p>=q->n||q->b[p++]!='\n')return false;
 }
 return true;
}
bool sx_iges_model_build(sxvtx_cursor*q)
{
 return sxvtx_iges(q);
}
#undef VT_EMIT
