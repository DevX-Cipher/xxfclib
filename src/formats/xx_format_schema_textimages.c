/* SPDX-License-Identifier: MIT
 * Physical text tokens and fixed binary fields. Variable final fields have size0. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_textimages.h"
static const xx_data_struct_field_desc sxti_magic_fields[]={
 SX_FIELD("magic","char",0,0,SX_SIGNATURE),
};
const sx_layout sxti_magic={0x60410001U,"textimage_magic",sxti_magic_fields,SX_COUNT(sxti_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxti_version_fields[]={
 SX_FIELD("version","char",0,0,SX_STRING),
};
static const sx_layout sxti_version={0x60410002U,"textimage_version",sxti_version_fields,SX_COUNT(sxti_version_fields),SX_LE};
static const xx_data_struct_field_desc sxti_byte_order_fields[]={
 SX_FIELD("byte_order","char",0,0,SX_STRING),
};
static const sx_layout sxti_byte_order={0x60410004U,"textimage_byte_order",sxti_byte_order_fields,SX_COUNT(sxti_byte_order_fields),SX_LE};
static const xx_data_struct_field_desc sxti_sample_sign_fields[]={
 SX_FIELD("sample_sign","char",0,0,SX_STRING),
};
static const sx_layout sxti_sample_sign={0x60410005U,"textimage_sample_sign",sxti_sample_sign_fields,SX_COUNT(sxti_sample_sign_fields),SX_LE};
static const xx_data_struct_field_desc sxti_lut_dimension_fields[]={
 SX_FIELD("lut_dimension","char",0,0,SX_STRING),
};
static const sx_layout sxti_lut_dimension={0x60410008U,"textimage_lut_dimension",sxti_lut_dimension_fields,SX_COUNT(sxti_lut_dimension_fields),SX_LE};
static const xx_data_struct_field_desc sxti_define_name_fields[]={
 SX_FIELD("define_name","char",0,0,SX_STRING),
};
const sx_layout sxti_define_name={0x6041000eU,"textimage_define_name",sxti_define_name_fields,SX_COUNT(sxti_define_name_fields),SX_LE};
static const xx_data_struct_field_desc sxti_name_fields[]={
 SX_FIELD("name","utf8",0,0,SX_STRING),
};
const sx_layout sxti_name={0x6041000fU,"textimage_name",sxti_name_fields,SX_COUNT(sxti_name_fields),SX_LE};
static const xx_data_struct_field_desc sxti_title_fields[]={
 SX_FIELD("title","utf8",0,0,SX_STRING),
};
static const sx_layout sxti_title={0x60410010U,"textimage_title",sxti_title_fields,SX_COUNT(sxti_title_fields),SX_LE};
static const xx_data_struct_field_desc sxti_color_name_fields[]={
 SX_FIELD("color_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxti_color_name={0x60410011U,"textimage_color_name",sxti_color_name_fields,SX_COUNT(sxti_color_name_fields),SX_LE};
static const xx_data_struct_field_desc sxti_metadata_text_fields[]={
 SX_FIELD("metadata_text","utf8",0,0,SX_STRING),
};
const sx_layout sxti_metadata_text={0x60410012U,"textimage_metadata_text",sxti_metadata_text_fields,SX_COUNT(sxti_metadata_text_fields),SX_LE};
static const xx_data_struct_field_desc sxti_width_fields[]={
 SX_FIELD("width","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_width={0x60410014U,"textimage_width",sxti_width_fields,SX_COUNT(sxti_width_fields),SX_LE};
static const xx_data_struct_field_desc sxti_height_fields[]={
 SX_FIELD("height","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_height={0x60410015U,"textimage_height",sxti_height_fields,SX_COUNT(sxti_height_fields),SX_LE};
static const xx_data_struct_field_desc sxti_precision_fields[]={
 SX_FIELD("precision","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_precision={0x60410018U,"textimage_precision",sxti_precision_fields,SX_COUNT(sxti_precision_fields),SX_LE};
static const xx_data_struct_field_desc sxti_columns_fields[]={
 SX_FIELD("columns","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_columns={0x60410019U,"textimage_columns",sxti_columns_fields,SX_COUNT(sxti_columns_fields),SX_LE};
static const xx_data_struct_field_desc sxti_color_count_fields[]={
 SX_FIELD("color_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxti_color_count={0x6041001aU,"textimage_color_count",sxti_color_count_fields,SX_COUNT(sxti_color_count_fields),SX_LE};
static const xx_data_struct_field_desc sxti_segment_count_fields[]={
 SX_FIELD("segment_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxti_segment_count={0x6041001bU,"textimage_segment_count",sxti_segment_count_fields,SX_COUNT(sxti_segment_count_fields),SX_LE};
static const xx_data_struct_field_desc sxti_hotspot_x_fields[]={
 SX_FIELD("hotspot_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_hotspot_x={0x60410026U,"textimage_hotspot_x",sxti_hotspot_x_fields,SX_COUNT(sxti_hotspot_x_fields),SX_LE};
static const xx_data_struct_field_desc sxti_hotspot_y_fields[]={
 SX_FIELD("hotspot_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_hotspot_y={0x60410027U,"textimage_hotspot_y",sxti_hotspot_y_fields,SX_COUNT(sxti_hotspot_y_fields),SX_LE};
static const xx_data_struct_field_desc sxti_lut_length_fields[]={
 SX_FIELD("lut_length","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxti_lut_length={0x60410028U,"textimage_lut_length",sxti_lut_length_fields,SX_COUNT(sxti_lut_length_fields),SX_LE};
static const xx_data_struct_field_desc sxti_components_fields[]={
 SX_FIELD("components","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxti_components={0x60410029U,"textimage_components",sxti_components_fields,SX_COUNT(sxti_components_fields),SX_LE};
static const xx_data_struct_field_desc sxti_input_components_fields[]={
 SX_FIELD("input_components","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_input_components={0x6041002aU,"textimage_input_components",sxti_input_components_fields,SX_COUNT(sxti_input_components_fields),SX_LE};
static const xx_data_struct_field_desc sxti_output_components_fields[]={
 SX_FIELD("output_components","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_output_components={0x6041002bU,"textimage_output_components",sxti_output_components_fields,SX_COUNT(sxti_output_components_fields),SX_LE};
static const xx_data_struct_field_desc sxti_red_size_fields[]={
 SX_FIELD("red_size","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_red_size={0x6041002cU,"textimage_red_size",sxti_red_size_fields,SX_COUNT(sxti_red_size_fields),SX_LE};
static const xx_data_struct_field_desc sxti_green_size_fields[]={
 SX_FIELD("green_size","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_green_size={0x6041002dU,"textimage_green_size",sxti_green_size_fields,SX_COUNT(sxti_green_size_fields),SX_LE};
static const xx_data_struct_field_desc sxti_blue_size_fields[]={
 SX_FIELD("blue_size","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_blue_size={0x6041002eU,"textimage_blue_size",sxti_blue_size_fields,SX_COUNT(sxti_blue_size_fields),SX_LE};
static const xx_data_struct_field_desc sxti_prelut_count_fields[]={
 SX_FIELD("prelut_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxti_prelut_count={0x6041002fU,"textimage_prelut_count",sxti_prelut_count_fields,SX_COUNT(sxti_prelut_count_fields),SX_LE};
static const xx_data_struct_field_desc sxti_red_index_fields[]={
 SX_FIELD("red_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_red_index={0x60410030U,"textimage_red_index",sxti_red_index_fields,SX_COUNT(sxti_red_index_fields),SX_LE};
static const xx_data_struct_field_desc sxti_green_index_fields[]={
 SX_FIELD("green_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_green_index={0x60410031U,"textimage_green_index",sxti_green_index_fields,SX_COUNT(sxti_green_index_fields),SX_LE};
static const xx_data_struct_field_desc sxti_blue_index_fields[]={
 SX_FIELD("blue_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_blue_index={0x60410032U,"textimage_blue_index",sxti_blue_index_fields,SX_COUNT(sxti_blue_index_fields),SX_LE};
static const xx_data_struct_field_desc sxti_red_fields[]={
 SX_FIELD("red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_red={0x60410034U,"textimage_red",sxti_red_fields,SX_COUNT(sxti_red_fields),SX_LE};
static const xx_data_struct_field_desc sxti_green_fields[]={
 SX_FIELD("green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_green={0x60410035U,"textimage_green",sxti_green_fields,SX_COUNT(sxti_green_fields),SX_LE};
static const xx_data_struct_field_desc sxti_blue_fields[]={
 SX_FIELD("blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_blue={0x60410036U,"textimage_blue",sxti_blue_fields,SX_COUNT(sxti_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxti_scale_fields[]={
 SX_FIELD("scale","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_scale={0x60410037U,"textimage_scale",sxti_scale_fields,SX_COUNT(sxti_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxti_domain_min_red_fields[]={
 SX_FIELD("domain_min_red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_domain_min_red={0x60410038U,"textimage_domain_min_red",sxti_domain_min_red_fields,SX_COUNT(sxti_domain_min_red_fields),SX_LE};
static const xx_data_struct_field_desc sxti_domain_min_green_fields[]={
 SX_FIELD("domain_min_green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_domain_min_green={0x60410039U,"textimage_domain_min_green",sxti_domain_min_green_fields,SX_COUNT(sxti_domain_min_green_fields),SX_LE};
static const xx_data_struct_field_desc sxti_domain_min_blue_fields[]={
 SX_FIELD("domain_min_blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_domain_min_blue={0x6041003aU,"textimage_domain_min_blue",sxti_domain_min_blue_fields,SX_COUNT(sxti_domain_min_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxti_domain_max_red_fields[]={
 SX_FIELD("domain_max_red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_domain_max_red={0x6041003bU,"textimage_domain_max_red",sxti_domain_max_red_fields,SX_COUNT(sxti_domain_max_red_fields),SX_LE};
static const xx_data_struct_field_desc sxti_domain_max_green_fields[]={
 SX_FIELD("domain_max_green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_domain_max_green={0x6041003cU,"textimage_domain_max_green",sxti_domain_max_green_fields,SX_COUNT(sxti_domain_max_green_fields),SX_LE};
static const xx_data_struct_field_desc sxti_domain_max_blue_fields[]={
 SX_FIELD("domain_max_blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_domain_max_blue={0x6041003dU,"textimage_domain_max_blue",sxti_domain_max_blue_fields,SX_COUNT(sxti_domain_max_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxti_from_min_fields[]={
 SX_FIELD("from_min","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_from_min={0x6041003eU,"textimage_from_min",sxti_from_min_fields,SX_COUNT(sxti_from_min_fields),SX_LE};
static const xx_data_struct_field_desc sxti_from_max_fields[]={
 SX_FIELD("from_max","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_from_max={0x6041003fU,"textimage_from_max",sxti_from_max_fields,SX_COUNT(sxti_from_max_fields),SX_LE};
static const xx_data_struct_field_desc sxti_prelut_input_fields[]={
 SX_FIELD("prelut_input","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_prelut_input={0x60410040U,"textimage_prelut_input",sxti_prelut_input_fields,SX_COUNT(sxti_prelut_input_fields),SX_LE};
static const xx_data_struct_field_desc sxti_prelut_output_fields[]={
 SX_FIELD("prelut_output","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_prelut_output={0x60410041U,"textimage_prelut_output",sxti_prelut_output_fields,SX_COUNT(sxti_prelut_output_fields),SX_LE};
static const xx_data_struct_field_desc sxti_left_fields[]={
 SX_FIELD("left","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_left={0x60410042U,"textimage_left",sxti_left_fields,SX_COUNT(sxti_left_fields),SX_LE};
static const xx_data_struct_field_desc sxti_middle_fields[]={
 SX_FIELD("middle","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_middle={0x60410043U,"textimage_middle",sxti_middle_fields,SX_COUNT(sxti_middle_fields),SX_LE};
static const xx_data_struct_field_desc sxti_right_fields[]={
 SX_FIELD("right","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_right={0x60410044U,"textimage_right",sxti_right_fields,SX_COUNT(sxti_right_fields),SX_LE};
static const xx_data_struct_field_desc sxti_left_red_fields[]={
 SX_FIELD("left_red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_left_red={0x60410045U,"textimage_left_red",sxti_left_red_fields,SX_COUNT(sxti_left_red_fields),SX_LE};
static const xx_data_struct_field_desc sxti_left_green_fields[]={
 SX_FIELD("left_green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_left_green={0x60410046U,"textimage_left_green",sxti_left_green_fields,SX_COUNT(sxti_left_green_fields),SX_LE};
static const xx_data_struct_field_desc sxti_left_blue_fields[]={
 SX_FIELD("left_blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_left_blue={0x60410047U,"textimage_left_blue",sxti_left_blue_fields,SX_COUNT(sxti_left_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxti_left_alpha_fields[]={
 SX_FIELD("left_alpha","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_left_alpha={0x60410048U,"textimage_left_alpha",sxti_left_alpha_fields,SX_COUNT(sxti_left_alpha_fields),SX_LE};
static const xx_data_struct_field_desc sxti_right_red_fields[]={
 SX_FIELD("right_red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_right_red={0x60410049U,"textimage_right_red",sxti_right_red_fields,SX_COUNT(sxti_right_red_fields),SX_LE};
static const xx_data_struct_field_desc sxti_right_green_fields[]={
 SX_FIELD("right_green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_right_green={0x6041004aU,"textimage_right_green",sxti_right_green_fields,SX_COUNT(sxti_right_green_fields),SX_LE};
static const xx_data_struct_field_desc sxti_right_blue_fields[]={
 SX_FIELD("right_blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_right_blue={0x6041004bU,"textimage_right_blue",sxti_right_blue_fields,SX_COUNT(sxti_right_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxti_right_alpha_fields[]={
 SX_FIELD("right_alpha","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxti_right_alpha={0x6041004cU,"textimage_right_alpha",sxti_right_alpha_fields,SX_COUNT(sxti_right_alpha_fields),SX_LE};
static const xx_data_struct_field_desc sxti_rgb8_red_fields[]={
 SX_FIELD("rgb8_red","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_rgb8_red={0x6041004dU,"textimage_rgb8_red",sxti_rgb8_red_fields,SX_COUNT(sxti_rgb8_red_fields),SX_LE};
static const xx_data_struct_field_desc sxti_rgb8_green_fields[]={
 SX_FIELD("rgb8_green","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_rgb8_green={0x6041004eU,"textimage_rgb8_green",sxti_rgb8_green_fields,SX_COUNT(sxti_rgb8_green_fields),SX_LE};
static const xx_data_struct_field_desc sxti_rgb8_blue_fields[]={
 SX_FIELD("rgb8_blue","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxti_rgb8_blue={0x6041004fU,"textimage_rgb8_blue",sxti_rgb8_blue_fields,SX_COUNT(sxti_rgb8_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxti_blending_fields[]={
 SX_FIELD("blending","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxti_blending={0x60410051U,"textimage_blending",sxti_blending_fields,SX_COUNT(sxti_blending_fields),SX_LE};
static const xx_data_struct_field_desc sxti_coloring_fields[]={
 SX_FIELD("coloring","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxti_coloring={0x60410052U,"textimage_coloring",sxti_coloring_fields,SX_COUNT(sxti_coloring_fields),SX_LE};
static const xx_data_struct_field_desc sxti_left_color_type_fields[]={
 SX_FIELD("left_color_type","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxti_left_color_type={0x60410053U,"textimage_left_color_type",sxti_left_color_type_fields,SX_COUNT(sxti_left_color_type_fields),SX_LE};
static const xx_data_struct_field_desc sxti_right_color_type_fields[]={
 SX_FIELD("right_color_type","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxti_right_color_type={0x60410054U,"textimage_right_color_type",sxti_right_color_type_fields,SX_COUNT(sxti_right_color_type_fields),SX_LE};
static const xx_data_struct_field_desc sxti_bitmap_byte_fields[]={
 SX_FIELD("bitmap_byte","ascii_hex",0,0,SX_FLAGS),
};
const sx_layout sxti_bitmap_byte={0x60410056U,"textimage_bitmap_byte",sxti_bitmap_byte_fields,SX_COUNT(sxti_bitmap_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxti_sample_u8_fields[]={
 SX_FIELD("sample","uint8",0,1,SX_NONE),
};
const sx_layout sxti_sample_u8={0x60410057U,"textimage_sample_u8",sxti_sample_u8_fields,SX_COUNT(sxti_sample_u8_fields),SX_LE};
static const xx_data_struct_field_desc sxti_sample_u16_be_fields[]={
 SX_FIELD("sample","uint16",0,2,SX_NONE),
};
const sx_layout sxti_sample_u16_be={0x60410058U,"textimage_sample_u16_be",sxti_sample_u16_be_fields,SX_COUNT(sxti_sample_u16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxti_sample_u16_le_fields[]={
 SX_FIELD("sample","uint16",0,2,SX_NONE),
};
static const sx_layout sxti_sample_u16_le={0x60410059U,"textimage_sample_u16_le",sxti_sample_u16_le_fields,SX_COUNT(sxti_sample_u16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxti_sample_i8_fields[]={
 SX_FIELD("sample","int8",0,1,SX_NONE),
};
static const sx_layout sxti_sample_i8={0x6041005aU,"textimage_sample_i8",sxti_sample_i8_fields,SX_COUNT(sxti_sample_i8_fields),SX_LE};
static const xx_data_struct_field_desc sxti_sample_i16_be_fields[]={
 SX_FIELD("sample","int16",0,2,SX_NONE),
};
static const sx_layout sxti_sample_i16_be={0x6041005bU,"textimage_sample_i16_be",sxti_sample_i16_be_fields,SX_COUNT(sxti_sample_i16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxti_sample_i16_le_fields[]={
 SX_FIELD("sample","int16",0,2,SX_NONE),
};
static const sx_layout sxti_sample_i16_le={0x6041005cU,"textimage_sample_i16_le",sxti_sample_i16_le_fields,SX_COUNT(sxti_sample_i16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxti_sample_float_be_fields[]={
 SX_FIELD("sample","float32",0,4,SX_NONE),
};
static const sx_layout sxti_sample_float_be={0x6041005dU,"textimage_sample_float_be",sxti_sample_float_be_fields,SX_COUNT(sxti_sample_float_be_fields),SX_BE};
static const xx_data_struct_field_desc sxti_sample_float_le_fields[]={
 SX_FIELD("sample","float32",0,4,SX_NONE),
};
static const sx_layout sxti_sample_float_le={0x6041005eU,"textimage_sample_float_le",sxti_sample_float_le_fields,SX_COUNT(sxti_sample_float_le_fields),SX_LE};
static const sx_layout *const sx_textimages_layouts[]={&sxti_magic,&sxti_version,&sxti_tuple_type,&sxti_byte_order,&sxti_sample_sign,&sxti_axis_y,&sxti_axis_x,&sxti_lut_dimension,&sxti_placement,&sxti_selection,&sxti_color_key,&sxti_color_specification,&sxti_declaration_name,&sxti_define_name,&sxti_name,&sxti_title,&sxti_color_name,&sxti_metadata_text,&sxti_brush_name,&sxti_width,&sxti_height,&sxti_depth,&sxti_maxval,&sxti_precision,&sxti_columns,&sxti_color_count,&sxti_segment_count,&sxti_brush_count,&sxti_ncells,&sxti_cellwidth,&sxti_cellheight,&sxti_step,&sxti_dim,&sxti_cols,&sxti_rows,&sxti_rank0,&sxti_characters_per_pixel,&sxti_hotspot_x,&sxti_hotspot_y,&sxti_lut_length,&sxti_components,&sxti_input_components,&sxti_output_components,&sxti_red_size,&sxti_green_size,&sxti_blue_size,&sxti_prelut_count,&sxti_red_index,&sxti_green_index,&sxti_blue_index,&sxti_declared_bytes,&sxti_red,&sxti_green,&sxti_blue,&sxti_scale,&sxti_domain_min_red,&sxti_domain_min_green,&sxti_domain_min_blue,&sxti_domain_max_red,&sxti_domain_max_green,&sxti_domain_max_blue,&sxti_from_min,&sxti_from_max,&sxti_prelut_input,&sxti_prelut_output,&sxti_left,&sxti_middle,&sxti_right,&sxti_left_red,&sxti_left_green,&sxti_left_blue,&sxti_left_alpha,&sxti_right_red,&sxti_right_green,&sxti_right_blue,&sxti_right_alpha,&sxti_rgb8_red,&sxti_rgb8_green,&sxti_rgb8_blue,&sxti_sample,&sxti_blending,&sxti_coloring,&sxti_left_color_type,&sxti_right_color_type,&sxti_unicode_codepoint,&sxti_bitmap_byte,&sxti_sample_u8,&sxti_sample_u16_be,&sxti_sample_u16_le,&sxti_sample_i8,&sxti_sample_i16_be,&sxti_sample_i16_le,&sxti_sample_float_be,&sxti_sample_float_le,&sxti_gih_brush_header,&sxti_radiance_scanline_header,&sxti_radiance_run,&sxti_radiance_literal};
static bool sx_textimages_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;switch(id){
case 0x60410037U:return xx_data_struct_record_set_comment(r,L"PFM scale: negative selects little endian; positive selects big endian. Magnitude is the sample scale.");
case 0x60410055U:return xx_data_struct_record_set_comment(r,L"Unicode scalar value; hexadecimal source text is preserved.");
case 0x60410056U:return xx_data_struct_record_set_comment(r,L"Original physical ASCII hexadecimal bitmap byte; bit order is defined by the parent format.");
case 0x60410061U:return xx_data_struct_record_set_comment(r,L"run_code minus128 is the repeated sample count.");
case 0x60410062U:return xx_data_struct_record_set_comment(r,L"The following sample_count bytes are literal channel values.");
case 0x60410051U:{static const wchar_t*names[]={L"LINEAR",L"CURVED",L"SINE",L"SPHERE_INCREASING",L"SPHERE_DECREASING",L"STEP"};if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;int64_t v=xx_var_get_i64(&r->value);return v>=0&&(uint64_t)v<SX_COUNT(names)?xx_data_struct_record_set_comment(r,names[v]):true;}
case 0x60410052U:{static const wchar_t*names[]={L"RGB",L"HSV_COUNTERCLOCKWISE",L"HSV_CLOCKWISE"};if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;int64_t v=xx_var_get_i64(&r->value);return v>=0&&(uint64_t)v<SX_COUNT(names)?xx_data_struct_record_set_comment(r,names[v]):true;}
case 0x60410053U:{static const wchar_t*names[]={L"FIXED",L"FOREGROUND",L"FOREGROUND_TRANSPARENT",L"BACKGROUND",L"BACKGROUND_TRANSPARENT"};if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;int64_t v=xx_var_get_i64(&r->value);return v>=0&&(uint64_t)v<SX_COUNT(names)?xx_data_struct_record_set_comment(r,names[v]):true;}
case 0x60410054U:{static const wchar_t*names[]={L"FIXED",L"FOREGROUND",L"FOREGROUND_TRANSPARENT",L"BACKGROUND",L"BACKGROUND_TRANSPARENT"};if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;int64_t v=xx_var_get_i64(&r->value);return v>=0&&(uint64_t)v<SX_COUNT(names)?xx_data_struct_record_set_comment(r,names[v]):true;}
default:return true;}}
bool sxti_space(uint8_t x){return x==' '||(x>=9&&x<=13);}
bool sxti_emit(sxti_cursor*q,const sx_layout*l,int64_t a,int64_t z){if(a<0||z<0||a>q->n||z>q->n-a)return false;if(!z||q->c->count>=32000)return !xx_pd_is_stopped(q->c->pd);int64_t limit=l->fields[0].size?INT64_MAX:sx_variable_field_limit(l->fields[0].type);if(z>limit)return true;if(!l->fields[0].size&&!xx_rt_wcscmp(l->fields[0].type,L"ascii_hex")){uint64_t value=0;for(int64_t i=0;i<z;i++){unsigned ch=q->b[a+i],digit=ch>='0'&&ch<='9'?ch-'0':ch>='a'&&ch<='f'?ch-'a'+10:ch>='A'&&ch<='F'?ch-'A'+10:16;if(digit>=16||value>(UINT64_MAX-digit)/16)return false;value=value*16+digit;}}return sx_add(q->c,l,a,z);}
bool sxti_token(sxti_cursor*q,int64_t end,int64_t*a,int64_t*z,bool comments){if(q->p<0||end>q->n||q->p>end)return false;for(;;){while(q->p<end&&sxti_space(q->b[q->p]))q->p++;if(!comments||q->p==end||q->b[q->p]!='#')break;while(q->p<end&&q->b[q->p]!='\n')q->p++;}if(q->p==end)return false;*a=q->p;while(q->p<end&&!sxti_space(q->b[q->p])&&(!comments||q->b[q->p]!='#'))q->p++;*z=q->p-*a;return *z>0&&!xx_pd_is_stopped(q->c->pd);}
bool sxti_value(sxti_cursor*q,const sx_layout*l,int64_t end,uint64_t*out){int64_t a,z;if(!sxti_token(q,end,&a,&z,true)||!sxti_emit(q,l,a,z))return false;if(out){uint64_t v=0;int64_t i=0;if(q->b[a]=='+')i++;if(i==z)return false;for(;i<z;i++){unsigned d=q->b[a+i]-'0';if(d>9||v>(UINT64_MAX-d)/10)return false;v=v*10+d;}*out=v;}return true;}
bool sxti_line(sxti_cursor*q,int64_t*a,int64_t*end,bool comments){while(q->p<q->n){int64_t start=q->p,stop;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;stop=q->p;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;if(comments){bool quoted=false;for(int64_t i=start;i<stop;i++){if(q->b[i]=='\\'&&quoted&&i+1<stop){i++;continue;}if(q->b[i]=='"')quoted=!quoted;if(q->b[i]=='#'&&!quoted){stop=i;break;}}}while(start<stop&&sxti_space(q->b[start]))start++;while(stop>start&&sxti_space(q->b[stop-1]))stop--;if(start<stop){*a=start;*end=stop;return !xx_pd_is_stopped(q->c->pd);}}return false;}
bool sxti_eq(sxti_cursor*q,int64_t a,int64_t z,const char*s){size_t n=xx_rt_strlen(s);return a>=0&&z==(int64_t)n&&a<=q->n&&z<=q->n-a&&!xx_rt_memcmp(q->b+a,s,n);}
static bool sxti_values(sxti_cursor*q,int64_t a,int64_t end,const sx_layout*const*layouts,unsigned count){int64_t save=q->p;q->p=a;bool ok=true;for(unsigned i=0;i<count;i++)if(!sxti_value(q,layouts[i],end,NULL)){ok=false;break;}q->p=save;return ok;}
bool sxti_table(sxti_cursor*q,const sx_layout*l,int64_t at,int64_t width,uint64_t count){if(at<0||at>q->n||width<=0||count>(uint64_t)(q->n-at)/(uint64_t)width)return false;if(!count||q->c->count>=32000)return true;return sx_table(q->c,l,at,width,count>65536?65536:count);}
#define TI_VALUE(n,e,v) do{if(!sxti_value(q,&sxti_##n,(e),(v)))return false;}while(0)
#define TI_EMIT(n,a,z) do{if(!sxti_emit(q,&sxti_##n,(a),(z)))return false;}while(0)
bool sxti_simple_image(sxti_cursor*q,xx_file_type_t type)
{
 int64_t a,end;uint64_t w,h,prec=8;bool be=false,sign=false;unsigned channels=1;
 if(type==XX_FILE_TYPE_NETPBM_PFM){if(q->n<3)return false;TI_EMIT(magic,0,2);channels=q->b[1]=='F'?3:1;q->p=3;if(!sxti_line(q,&a,&end,false))return false;int64_t next=q->p;q->p=a;TI_VALUE(width,end,&w);TI_VALUE(height,end,&h);q->p=next;if(!sxti_line(q,&a,&end,false))return false;TI_EMIT(scale,a,end-a);be=q->b[a]!='-';if(!w||!h||w>16777216/channels||h>16777216/channels/w)return false;return sxti_table(q,be?&sxti_sample_float_be:&sxti_sample_float_le,q->p,4,w*h*channels);}
 if(!sxti_line(q,&a,&end,false))return false;int64_t next=q->p;q->p=a;
 if(type==XX_FILE_TYPE_JPEG2000_PGX){TI_VALUE(magic,end,NULL);int64_t start,z;if(!sxti_token(q,end,&start,&z,false))return false;TI_EMIT(byte_order,start,z);be=sxti_eq(q,start,z,"ML");while(q->p<end&&sxti_space(q->b[q->p]))q->p++;if(q->p==end)return false;sign=q->b[q->p]=='-';TI_EMIT(sample_sign,q->p,1);q->p++;TI_VALUE(precision,end,&prec);}
 else channels=3;
 TI_VALUE(width,end,&w);TI_VALUE(height,end,&h);q->p=next;if(!w||!h||w>16777216/channels||h>16777216/channels/w||!prec||prec>16)return false;unsigned width=prec>8?2:1;const sx_layout*l=width==1?(sign?&sxti_sample_i8:&sxti_sample_u8):sign?(be?&sxti_sample_i16_be:&sxti_sample_i16_le):(be?&sxti_sample_u16_be:&sxti_sample_u16_le);return sxti_table(q,l,q->p,width,w*h*channels);
}
bool sxti_palette(sxti_cursor*q,xx_file_type_t type)
{
 int64_t a,end;bool gradient=type==XX_FILE_TYPE_GIMP_GGR,jasc=type==XX_FILE_TYPE_JASC_PALETTE;unsigned header=0;
 const sx_layout*rgb[]={&sxti_rgb8_red,&sxti_rgb8_green,&sxti_rgb8_blue};
 const sx_layout*segment[]={&sxti_left,&sxti_middle,&sxti_right,&sxti_left_red,&sxti_left_green,&sxti_left_blue,&sxti_left_alpha,&sxti_right_red,&sxti_right_green,&sxti_right_blue,&sxti_right_alpha,&sxti_blending,&sxti_coloring,&sxti_left_color_type,&sxti_right_color_type};
 while(sxti_line(q,&a,&end,false)){if(q->b[a]=='#')continue;if(q->c->count>=32000)return true;if(!header){TI_EMIT(magic,a,end-a);header++;continue;}if(end-a>=5&&sxti_eq(q,a,5,"Name:")){a+=5;while(a<end&&sxti_space(q->b[a]))a++;TI_EMIT(name,a,end-a);continue;}if(!gradient&&!jasc&&end-a>=8&&sxti_eq(q,a,8,"Columns:")){a+=8;while(a<end&&sxti_space(q->b[a]))a++;TI_EMIT(columns,a,end-a);continue;}
  if(jasc&&header==1){TI_EMIT(version,a,end-a);header++;continue;}if((gradient&&header==1)||(jasc&&header==2)){TI_EMIT(segment_count,a,gradient?end-a:0);if(jasc)TI_EMIT(color_count,a,end-a);header++;continue;}
  int64_t next=q->p;q->p=a;unsigned n=gradient?13:3;for(unsigned i=0;i<n;i++)if(!sxti_value(q,gradient?segment[i]:rgb[i],end,NULL))return false;while(q->p<end&&sxti_space(q->b[q->p]))q->p++;
  if(gradient){if(q->p<end&&q->b[q->p]!='#'){for(unsigned i=13;i<15;i++)if(!sxti_value(q,segment[i],end,NULL))return false;}}
  else if(!jasc&&q->p<end)TI_EMIT(color_name,q->p,end-q->p);q->p=next;
 }return header>0;
}
bool sxti_lut(sxti_cursor*q,xx_file_type_t type)
{
 const sx_layout*rgb[]={&sxti_red,&sxti_green,&sxti_blue};const sx_layout*domains[]={&sxti_domain_min_red,&sxti_domain_min_green,&sxti_domain_min_blue,&sxti_domain_max_red,&sxti_domain_max_green,&sxti_domain_max_blue};
 const sx_layout*sizes[]={&sxti_red_size,&sxti_green_size,&sxti_blue_size};const sx_layout*spirow[]={&sxti_red_index,&sxti_green_index,&sxti_blue_index,&sxti_red,&sxti_green,&sxti_blue};
 int64_t a,end;unsigned line=0,components=3;bool data=false,metadata=false;unsigned csp_phase=0;
 while(sxti_line(q,&a,&end,!metadata)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;int64_t key,z;if(!sxti_token(q,end,&key,&z,false))return false;
  if(type==XX_FILE_TYPE_IRIDAS_CUBE_LUT){
   if(!data&&sxti_eq(q,key,z,"TITLE")){while(q->p<end&&sxti_space(q->b[q->p]))q->p++;if(end-q->p<2||q->b[q->p]!='"'||q->b[end-1]!='"')return false;TI_EMIT(title,q->p+1,end-q->p-2);}
   else if(!data&&(sxti_eq(q,key,z,"DOMAIN_MIN")||sxti_eq(q,key,z,"DOMAIN_MAX"))){unsigned first=sxti_eq(q,key,z,"DOMAIN_MIN")?0:3;for(unsigned i=0;i<3;i++)if(!sxti_value(q,domains[first+i],end,NULL))return false;}
   else if(!data&&(sxti_eq(q,key,z,"LUT_1D_SIZE")||sxti_eq(q,key,z,"LUT_3D_SIZE"))){TI_EMIT(lut_dimension,key+4,2);TI_VALUE(lut_length,end,NULL);}
   else{data=true;if(!sxti_values(q,a,end,rgb,3))return false;}
  }else if(type==XX_FILE_TYPE_LUT_SPI1D){
   if(!data&&sxti_eq(q,key,z,"Version")){TI_VALUE(version,end,NULL);}
   else if(!data&&sxti_eq(q,key,z,"From")){TI_VALUE(from_min,end,NULL);TI_VALUE(from_max,end,NULL);}
   else if(!data&&sxti_eq(q,key,z,"Length")){TI_VALUE(lut_length,end,NULL);}
   else if(!data&&sxti_eq(q,key,z,"Components")){uint64_t n;TI_VALUE(components,end,&n);if(!n||n>3)return false;components=(unsigned)n;}
   else if(sxti_eq(q,key,z,"{")){data=true;}
   else if(!sxti_eq(q,key,z,"}")){if(!data||!sxti_values(q,a,end,rgb,components))return false;}
  }else if(type==XX_FILE_TYPE_LUT_SPI3D){
   if(line==0){TI_EMIT(magic,key,z);TI_VALUE(version,end,NULL);}
   else if(line==1){q->p=a;TI_VALUE(input_components,end,NULL);TI_VALUE(output_components,end,NULL);}
   else if(line==2){if(!sxti_values(q,a,end,sizes,3))return false;}
   else if(!sxti_values(q,a,end,spirow,6))return false;
  }else{
   if(line==0){TI_EMIT(magic,key,z);}
   else if(line==1){TI_EMIT(lut_dimension,key,z);components=sxti_eq(q,key,z,"3D")?3:1;}
   else if(metadata){if(sxti_eq(q,a,end-a,"END METADATA"))metadata=false;else TI_EMIT(metadata_text,a,end-a);}
   else if(csp_phase==0&&sxti_eq(q,a,end-a,"BEGIN METADATA")){metadata=true;}
   else if(csp_phase<9){q->p=a;if(csp_phase%3==0){TI_VALUE(prelut_count,end,NULL);}else while(q->p<end){int64_t at,len;if(!sxti_token(q,end,&at,&len,true))break;if(!sxti_emit(q,csp_phase%3==1?&sxti_prelut_input:&sxti_prelut_output,at,len))return false;}csp_phase++;}
   else if(csp_phase==9){if(components==3){if(!sxti_values(q,a,end,sizes,3))return false;}else{q->p=a;TI_VALUE(lut_length,end,NULL);}csp_phase++;}
   else if(!sxti_values(q,a,end,rgb,3))return false;
  }q->p=next;line++;
 }return line>0&&!metadata;
}
bool sxti_cskip(sxti_cursor*q)
{
 while(q->p<q->n){if(xx_pd_is_stopped(q->c->pd))return false;if(sxti_space(q->b[q->p])){q->p++;continue;}if(q->n-q->p>=2&&q->b[q->p]=='/'&&q->b[q->p+1]=='*'){q->p+=2;while(q->n-q->p>=2&&(q->b[q->p]!='*'||q->b[q->p+1]!='/'))q->p++;if(q->n-q->p<2)return false;q->p+=2;continue;}if(q->n-q->p>=2&&q->b[q->p]=='/'&&q->b[q->p+1]=='/'){q->p+=2;while(q->p<q->n&&q->b[q->p]!='\n')q->p++;continue;}break;}return true;
}
static int sxti_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxti_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxti_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxti_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_textimages_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_PNM:case XX_FILE_TYPE_RADIANCE_HDR:case XX_FILE_TYPE_NETPBM_PFM:case XX_FILE_TYPE_JPEG2000_PGX:case XX_FILE_TYPE_MTV_IMAGE:case XX_FILE_TYPE_GIMP_GIH:case XX_FILE_TYPE_GIMP_GPL:case XX_FILE_TYPE_GIMP_GGR:case XX_FILE_TYPE_JASC_PALETTE:case XX_FILE_TYPE_IRIDAS_CUBE_LUT:case XX_FILE_TYPE_LUT_SPI1D:case XX_FILE_TYPE_LUT_SPI3D:case XX_FILE_TYPE_LUT_CINESPACE_CSP:case XX_FILE_TYPE_UNIFONT_HEX:case XX_FILE_TYPE_XPM:case XX_FILE_TYPE_X11_XBM:return true;default:return false;}}
static bool sx_textimages_build(sx_context*c){
 if(!c||!c->f||c->size<1||c->size>67108864||xx_pd_is_stopped(c->pd))return false;
 /* Metadata interpretation uses the same complete native validation as the
  * application. Cached native acceptance never bypasses local span checks. */
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 uint8_t*bytes=xx_mem_alloc((size_t)c->size);if(!bytes)return false;
 bool ok=sx_read(c,0,bytes,(size_t)c->size);sxti_cursor cursor={c,bytes,c->size,0},*q=&cursor;xx_file_type_t type=c->f->file_type;
 if(ok)switch(type){
case XX_FILE_TYPE_PNM:ok=sx_pnm_build(q);break;
case XX_FILE_TYPE_RADIANCE_HDR:ok=sx_radiance_hdr_build(q);break;
case XX_FILE_TYPE_NETPBM_PFM:ok=sx_netpbm_pfm_build(q,type);break;
case XX_FILE_TYPE_JPEG2000_PGX:ok=sx_jpeg2000_pgx_build(q,type);break;
case XX_FILE_TYPE_MTV_IMAGE:ok=sx_mtv_image_build(q,type);break;
case XX_FILE_TYPE_GIMP_GIH:ok=sx_gimp_gih_build(q);break;
case XX_FILE_TYPE_GIMP_GPL:ok=sx_gimp_gpl_build(q,type);break;
case XX_FILE_TYPE_GIMP_GGR:ok=sx_gimp_ggr_build(q,type);break;
case XX_FILE_TYPE_JASC_PALETTE:ok=sx_jasc_palette_build(q,type);break;
case XX_FILE_TYPE_IRIDAS_CUBE_LUT:ok=sx_iridas_cube_lut_build(q,type);break;
case XX_FILE_TYPE_LUT_SPI1D:ok=sx_lut_spi1d_build(q,type);break;
case XX_FILE_TYPE_LUT_SPI3D:ok=sx_lut_spi3d_build(q,type);break;
case XX_FILE_TYPE_LUT_CINESPACE_CSP:ok=sx_lut_cinespace_csp_build(q,type);break;
case XX_FILE_TYPE_UNIFONT_HEX:ok=sx_unifont_hex_build(q);break;
case XX_FILE_TYPE_XPM:ok=sx_xpm_build(q);break;
case XX_FILE_TYPE_X11_XBM:ok=sx_x11_xbm_build(q);break;
default:ok=false;break;}
 xx_mem_free(bytes);return ok&&sxti_finish(c);
 }
#undef TI_EMIT
#undef TI_VALUE
const sx_family sx_textimages_family={sx_textimages_supports,sx_textimages_build,sx_textimages_layouts,SX_COUNT(sx_textimages_layouts),sx_textimages_comment};
