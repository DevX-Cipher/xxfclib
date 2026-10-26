/* SPDX-License-Identifier: MIT. Original physical model/font tokens and binary properties. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_modeltext.h"
static const xx_data_struct_field_desc sxmt_signature_fields[]={
 SX_FIELD("signature","char",0,0,SX_SIGNATURE),
};
const sx_layout sxmt_signature={0x60520001U,"modeltext_signature",sxmt_signature_fields,SX_COUNT(sxmt_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_version_fields[]={
 SX_FIELD("version","char",0,0,SX_STRING),
};
const sx_layout sxmt_version={0x60520002U,"modeltext_version",sxmt_version_fields,SX_COUNT(sxmt_version_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_encoding_fields[]={
 SX_FIELD("encoding","char",0,0,SX_STRING),
};
const sx_layout sxmt_encoding={0x60520003U,"modeltext_encoding",sxmt_encoding_fields,SX_COUNT(sxmt_encoding_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_property_name_fields[]={
 SX_FIELD("property_name","char",0,0,SX_STRING),
};
const sx_layout sxmt_property_name={0x60520005U,"modeltext_property_name",sxmt_property_name_fields,SX_COUNT(sxmt_property_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_object_type_fields[]={
 SX_FIELD("object_type","char",0,0,SX_STRING),
};
const sx_layout sxmt_object_type={0x60520009U,"modeltext_object_type",sxmt_object_type_fields,SX_COUNT(sxmt_object_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_keyword_fields[]={
 SX_FIELD("keyword","char",0,0,SX_STRING),
};
const sx_layout sxmt_keyword={0x6052000aU,"modeltext_keyword",sxmt_keyword_fields,SX_COUNT(sxmt_keyword_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_material_name_fields[]={
 SX_FIELD("material_name","utf8",0,0,SX_STRING),
};
const sx_layout sxmt_material_name={0x6052000cU,"modeltext_material_name",sxmt_material_name_fields,SX_COUNT(sxmt_material_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_glyph_name_fields[]={
 SX_FIELD("glyph_name","utf8",0,0,SX_STRING),
};
const sx_layout sxmt_glyph_name={0x6052000eU,"modeltext_glyph_name",sxmt_glyph_name_fields,SX_COUNT(sxmt_glyph_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_channel_name_fields[]={
 SX_FIELD("channel_name","char",0,0,SX_STRING),
};
static const sx_layout sxmt_channel_name={0x6052000fU,"modeltext_channel_name",sxmt_channel_name_fields,SX_COUNT(sxmt_channel_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_name_fields[]={
 SX_FIELD("name","utf8",0,0,SX_STRING),
};
const sx_layout sxmt_name={0x60520010U,"modeltext_name",sxmt_name_fields,SX_COUNT(sxmt_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_string_value_fields[]={
 SX_FIELD("string_value","utf8",0,0,SX_STRING),
};
const sx_layout sxmt_string_value={0x60520011U,"modeltext_string_value",sxmt_string_value_fields,SX_COUNT(sxmt_string_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_record_text_fields[]={
 SX_FIELD("record_text","utf8",0,0,SX_STRING),
};
static const sx_layout sxmt_record_text={0x60520012U,"modeltext_record_text",sxmt_record_text_fields,SX_COUNT(sxmt_record_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_vertex_count_fields[]={
 SX_FIELD("vertex_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_vertex_count={0x60520013U,"modeltext_vertex_count",sxmt_vertex_count_fields,SX_COUNT(sxmt_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_face_count_fields[]={
 SX_FIELD("face_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_face_count={0x60520014U,"modeltext_face_count",sxmt_face_count_fields,SX_COUNT(sxmt_face_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_edge_count_fields[]={
 SX_FIELD("edge_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_edge_count={0x60520015U,"modeltext_edge_count",sxmt_edge_count_fields,SX_COUNT(sxmt_edge_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_vertex_index_fields[]={
 SX_FIELD("vertex_index","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_vertex_index={0x6052001cU,"modeltext_vertex_index",sxmt_vertex_index_fields,SX_COUNT(sxmt_vertex_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_glyph_count_fields[]={
 SX_FIELD("glyph_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_glyph_count={0x60520026U,"modeltext_glyph_count",sxmt_glyph_count_fields,SX_COUNT(sxmt_glyph_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_property_total_fields[]={
 SX_FIELD("property_total","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_property_total={0x60520027U,"modeltext_property_total",sxmt_property_total_fields,SX_COUNT(sxmt_property_total_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_codepoint_fields[]={
 SX_FIELD("codepoint","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_codepoint={0x60520028U,"modeltext_codepoint",sxmt_codepoint_fields,SX_COUNT(sxmt_codepoint_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_integer_value_fields[]={
 SX_FIELD("integer_value","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_integer_value={0x60520035U,"modeltext_integer_value",sxmt_integer_value_fields,SX_COUNT(sxmt_integer_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_frame_count_fields[]={
 SX_FIELD("frame_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_frame_count={0x60520036U,"modeltext_frame_count",sxmt_frame_count_fields,SX_COUNT(sxmt_frame_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_channel_count_fields[]={
 SX_FIELD("channel_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_channel_count={0x60520037U,"modeltext_channel_count",sxmt_channel_count_fields,SX_COUNT(sxmt_channel_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_x_fields[]={
 SX_FIELD("x","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_x={0x60520039U,"modeltext_x",sxmt_x_fields,SX_COUNT(sxmt_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_y_fields[]={
 SX_FIELD("y","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_y={0x6052003aU,"modeltext_y",sxmt_y_fields,SX_COUNT(sxmt_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_z_fields[]={
 SX_FIELD("z","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_z={0x6052003bU,"modeltext_z",sxmt_z_fields,SX_COUNT(sxmt_z_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_u_fields[]={
 SX_FIELD("u","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_u={0x6052003dU,"modeltext_u",sxmt_u_fields,SX_COUNT(sxmt_u_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_v_fields[]={
 SX_FIELD("v","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_v={0x6052003eU,"modeltext_v",sxmt_v_fields,SX_COUNT(sxmt_v_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_red_fields[]={
 SX_FIELD("red","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_red={0x60520042U,"modeltext_red",sxmt_red_fields,SX_COUNT(sxmt_red_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_green_fields[]={
 SX_FIELD("green","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_green={0x60520043U,"modeltext_green",sxmt_green_fields,SX_COUNT(sxmt_green_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_blue_fields[]={
 SX_FIELD("blue","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_blue={0x60520044U,"modeltext_blue",sxmt_blue_fields,SX_COUNT(sxmt_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_translate_x_fields[]={
 SX_FIELD("translate_x","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_translate_x={0x60520046U,"modeltext_translate_x",sxmt_translate_x_fields,SX_COUNT(sxmt_translate_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_translate_y_fields[]={
 SX_FIELD("translate_y","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_translate_y={0x60520047U,"modeltext_translate_y",sxmt_translate_y_fields,SX_COUNT(sxmt_translate_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_translate_z_fields[]={
 SX_FIELD("translate_z","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_translate_z={0x60520048U,"modeltext_translate_z",sxmt_translate_z_fields,SX_COUNT(sxmt_translate_z_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_real_value_fields[]={
 SX_FIELD("real_value","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_real_value={0x6052004dU,"modeltext_real_value",sxmt_real_value_fields,SX_COUNT(sxmt_real_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_frame_time_fields[]={
 SX_FIELD("frame_time","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_frame_time={0x6052004eU,"modeltext_frame_time",sxmt_frame_time_fields,SX_COUNT(sxmt_frame_time_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_font_metric_fields[]={
 SX_FIELD("font_metric","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_font_metric={0x6052005bU,"modeltext_font_metric",sxmt_font_metric_fields,SX_COUNT(sxmt_font_metric_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_motion_value_fields[]={
 SX_FIELD("motion_value","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_motion_value={0x6052005cU,"modeltext_motion_value",sxmt_motion_value_fields,SX_COUNT(sxmt_motion_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_int8_le_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxmt_binary_int8_le={0x60520061U,"modeltext_binary_int8_le",sxmt_binary_int8_le_fields,SX_COUNT(sxmt_binary_int8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_uint8_le_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxmt_binary_uint8_le={0x60520062U,"modeltext_binary_uint8_le",sxmt_binary_uint8_le_fields,SX_COUNT(sxmt_binary_uint8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_int16_le_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxmt_binary_int16_le={0x60520063U,"modeltext_binary_int16_le",sxmt_binary_int16_le_fields,SX_COUNT(sxmt_binary_int16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_uint16_le_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxmt_binary_uint16_le={0x60520064U,"modeltext_binary_uint16_le",sxmt_binary_uint16_le_fields,SX_COUNT(sxmt_binary_uint16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_int32_le_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxmt_binary_int32_le={0x60520065U,"modeltext_binary_int32_le",sxmt_binary_int32_le_fields,SX_COUNT(sxmt_binary_int32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_uint32_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxmt_binary_uint32_le={0x60520066U,"modeltext_binary_uint32_le",sxmt_binary_uint32_le_fields,SX_COUNT(sxmt_binary_uint32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_float32_le_fields[]={
 SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxmt_binary_float32_le={0x60520067U,"modeltext_binary_float32_le",sxmt_binary_float32_le_fields,SX_COUNT(sxmt_binary_float32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_double_le_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
static const sx_layout sxmt_binary_double_le={0x60520068U,"modeltext_binary_double_le",sxmt_binary_double_le_fields,SX_COUNT(sxmt_binary_double_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_binary_int8_be_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxmt_binary_int8_be={0x6052006cU,"modeltext_binary_int8_be",sxmt_binary_int8_be_fields,SX_COUNT(sxmt_binary_int8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_binary_uint8_be_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxmt_binary_uint8_be={0x6052006dU,"modeltext_binary_uint8_be",sxmt_binary_uint8_be_fields,SX_COUNT(sxmt_binary_uint8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_binary_int16_be_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxmt_binary_int16_be={0x6052006eU,"modeltext_binary_int16_be",sxmt_binary_int16_be_fields,SX_COUNT(sxmt_binary_int16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_binary_uint16_be_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxmt_binary_uint16_be={0x6052006fU,"modeltext_binary_uint16_be",sxmt_binary_uint16_be_fields,SX_COUNT(sxmt_binary_uint16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_binary_int32_be_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxmt_binary_int32_be={0x60520070U,"modeltext_binary_int32_be",sxmt_binary_int32_be_fields,SX_COUNT(sxmt_binary_int32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_binary_uint32_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxmt_binary_uint32_be={0x60520071U,"modeltext_binary_uint32_be",sxmt_binary_uint32_be_fields,SX_COUNT(sxmt_binary_uint32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_binary_float32_be_fields[]={
 SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxmt_binary_float32_be={0x60520072U,"modeltext_binary_float32_be",sxmt_binary_float32_be_fields,SX_COUNT(sxmt_binary_float32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_binary_double_be_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
static const sx_layout sxmt_binary_double_be={0x60520073U,"modeltext_binary_double_be",sxmt_binary_double_be_fields,SX_COUNT(sxmt_binary_double_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_xfile_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("major_version","char[2]",4,2,SX_NONE),
 SX_FIELD("minor_version","char[2]",6,2,SX_NONE),
 SX_FIELD("encoding","char[4]",8,4,SX_STRING),
 SX_FIELD("float_width","char[4]",12,4,SX_NONE),
};
static const sx_layout sxmt_xfile_header={0x6052007fU,"modeltext_xfile_header",sxmt_xfile_header_fields,SX_COUNT(sxmt_xfile_header_fields),SX_LE};
static const sx_layout *const sx_modeltext_layouts[]={&sxmt_signature,&sxmt_version,&sxmt_encoding,&sxmt_element_name,&sxmt_property_name,&sxmt_property_type,&sxmt_count_type,&sxmt_field_type,&sxmt_object_type,&sxmt_keyword,&sxmt_group_name,&sxmt_material_name,&sxmt_font_name,&sxmt_glyph_name,&sxmt_channel_name,&sxmt_name,&sxmt_string_value,&sxmt_record_text,&sxmt_vertex_count,&sxmt_face_count,&sxmt_edge_count,&sxmt_list_count,&sxmt_element_count,&sxmt_point_count,&sxmt_width,&sxmt_height,&sxmt_sample_count,&sxmt_vertex_index,&sxmt_texture_index,&sxmt_normal_index,&sxmt_edge_index,&sxmt_material_index,&sxmt_smoothing_group,&sxmt_child_count,&sxmt_data_bytes,&sxmt_surface_count,&sxmt_reference_count,&sxmt_glyph_count,&sxmt_property_total,&sxmt_codepoint,&sxmt_glyph_index,&sxmt_font_size,&sxmt_resolution_x,&sxmt_resolution_y,&sxmt_bbox_width,&sxmt_bbox_height,&sxmt_bbox_x,&sxmt_bbox_y,&sxmt_swidth_x,&sxmt_swidth_y,&sxmt_dwidth_x,&sxmt_dwidth_y,&sxmt_integer_value,&sxmt_frame_count,&sxmt_channel_count,&sxmt_curve_flags,&sxmt_x,&sxmt_y,&sxmt_z,&sxmt_w,&sxmt_u,&sxmt_v,&sxmt_normal_x,&sxmt_normal_y,&sxmt_normal_z,&sxmt_red,&sxmt_green,&sxmt_blue,&sxmt_alpha,&sxmt_translate_x,&sxmt_translate_y,&sxmt_translate_z,&sxmt_quaternion_w,&sxmt_quaternion_x,&sxmt_quaternion_y,&sxmt_quaternion_z,&sxmt_real_value,&sxmt_frame_time,&sxmt_rotation_value,&sxmt_transparency,&sxmt_shininess,&sxmt_ambient_red,&sxmt_ambient_green,&sxmt_ambient_blue,&sxmt_emission_red,&sxmt_emission_green,&sxmt_emission_blue,&sxmt_specular_red,&sxmt_specular_green,&sxmt_specular_blue,&sxmt_font_metric,&sxmt_motion_value,&sxmt_surface_flags,&sxmt_glyph_attributes,&sxmt_bitmap_byte,&sxmt_character_code_hex,&sxmt_binary_int8_le,&sxmt_binary_uint8_le,&sxmt_binary_int16_le,&sxmt_binary_uint16_le,&sxmt_binary_int32_le,&sxmt_binary_uint32_le,&sxmt_binary_float32_le,&sxmt_binary_double_le,&sxmt_list_uint8_le,&sxmt_list_uint16_le,&sxmt_list_uint32_le,&sxmt_binary_int8_be,&sxmt_binary_uint8_be,&sxmt_binary_int16_be,&sxmt_binary_uint16_be,&sxmt_binary_int32_be,&sxmt_binary_uint32_be,&sxmt_binary_float32_be,&sxmt_binary_double_be,&sxmt_list_uint8_be,&sxmt_list_uint16_be,&sxmt_list_uint32_be,&sxmt_dxf_signature,&sxmt_dxf_group_code,&sxmt_dxf_int8,&sxmt_dxf_int16,&sxmt_dxf_int32,&sxmt_dxf_int64,&sxmt_dxf_double,&sxmt_dxf_chunk_length,&sxmt_xfile_header,&sxmt_fig_orientation,&sxmt_fig_justification,&sxmt_fig_units,&sxmt_fig_paper_size,&sxmt_fig_page_mode,&sxmt_fig_object_code,&sxmt_fig_subtype,&sxmt_fig_line_style,&sxmt_fig_thickness,&sxmt_fig_pen_color,&sxmt_fig_fill_color,&sxmt_fig_depth,&sxmt_fig_pen_style,&sxmt_fig_area_fill,&sxmt_fig_direction,&sxmt_fig_center_x,&sxmt_fig_center_y,&sxmt_fig_radius_x,&sxmt_fig_radius_y,&sxmt_fig_start_x,&sxmt_fig_start_y,&sxmt_fig_end_x,&sxmt_fig_end_y,&sxmt_fig_join_style,&sxmt_fig_cap_style,&sxmt_fig_radius,&sxmt_fig_forward_arrow,&sxmt_fig_backward_arrow,&sxmt_fig_point_count,&sxmt_fig_color_index,&sxmt_fig_transparent_color,&sxmt_fig_resolution,&sxmt_fig_coordinate_system,&sxmt_fig_magnification,&sxmt_fig_style_value,&sxmt_fig_angle,&sxmt_fig_rgb};
static bool sx_modeltext_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;switch(id){
case 0x6052005dU:return xx_data_struct_record_set_comment(r,L"Physical hexadecimal source value; original bytes are retained.");
case 0x6052005eU:return xx_data_struct_record_set_comment(r,L"Physical hexadecimal source value; original bytes are retained.");
case 0x6052005fU:return xx_data_struct_record_set_comment(r,L"Physical hexadecimal source value; original bytes are retained.");
case 0x60520060U:return xx_data_struct_record_set_comment(r,L"Physical hexadecimal source value; original bytes are retained.");
case 0x60520061U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520062U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520063U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520064U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520065U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520066U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520067U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520068U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x6052006cU:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x6052006dU:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x6052006eU:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x6052006fU:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520070U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520071U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520072U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520073U:return xx_data_struct_record_set_comment(r,L"Binary property value in declaration order; its name and type are stored in the preceding header.");
case 0x60520078U:return xx_data_struct_record_set_comment(r,L"DXF group code selects the type and semantic role of the following value.");
case 0x605200a4U:return xx_data_struct_record_set_comment(r,L"Original #RRGGBB color value.");
default:return true;}}
bool sxmt_space(uint8_t x){return x==' '||(x>=9&&x<=13);}
bool sxmt_emit(sxmt_cursor*q,const sx_layout*l,int64_t a,int64_t z){if(a<0||z<0||a>q->n||z>q->n-a)return false;if(!z||q->c->count>=32000)return !xx_pd_is_stopped(q->c->pd);int64_t limit=l->fields[0].size?INT64_MAX:sx_variable_field_limit(l->fields[0].type);if(z>limit)return true;if(!l->fields[0].size&&!xx_rt_wcscmp(l->fields[0].type,L"ascii_hex")){uint64_t value=0;for(int64_t i=0;i<z;i++){unsigned ch=q->b[a+i],digit=ch>='0'&&ch<='9'?ch-'0':ch>='a'&&ch<='f'?ch-'a'+10:ch>='A'&&ch<='F'?ch-'A'+10:16;if(digit>=16||value>(UINT64_MAX-digit)/16)return false;value=value*16+digit;}}return sx_add(q->c,l,a,z);}
bool sxmt_token(sxmt_cursor*q,int64_t end,int64_t*a,int64_t*z,bool comments){if(q->p<0||end>q->n||q->p>end)return false;for(;;){while(q->p<end&&sxmt_space(q->b[q->p]))q->p++;if(!comments||q->p==end||q->b[q->p]!='#')break;while(q->p<end&&q->b[q->p]!='\n')q->p++;}if(q->p==end)return false;*a=q->p;while(q->p<end&&!sxmt_space(q->b[q->p])&&(!comments||q->b[q->p]!='#'))q->p++;*z=q->p-*a;return *z>0&&!xx_pd_is_stopped(q->c->pd);}
bool sxmt_value(sxmt_cursor*q,const sx_layout*l,int64_t end,uint64_t*out){int64_t a,z;if(!sxmt_token(q,end,&a,&z,true)||!sxmt_emit(q,l,a,z))return false;if(out){uint64_t v=0;int64_t i=0;if(q->b[a]=='+')i++;if(i==z)return false;for(;i<z;i++){unsigned d=q->b[a+i]-'0';if(d>9||v>(UINT64_MAX-d)/10)return false;v=v*10+d;}*out=v;}return true;}
bool sxmt_line(sxmt_cursor*q,int64_t*a,int64_t*end,bool comments){while(q->p<q->n){int64_t start=q->p,stop;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;stop=q->p;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;if(comments){bool quoted=false;for(int64_t i=start;i<stop;i++){if(q->b[i]=='\\'&&quoted&&i+1<stop){i++;continue;}if(q->b[i]=='"')quoted=!quoted;if(q->b[i]=='#'&&!quoted){stop=i;break;}}}while(start<stop&&sxmt_space(q->b[start]))start++;while(stop>start&&sxmt_space(q->b[stop-1]))stop--;if(start<stop){*a=start;*end=stop;return !xx_pd_is_stopped(q->c->pd);}}return false;}
bool sxmt_eq(sxmt_cursor*q,int64_t a,int64_t z,const char*s){size_t n=xx_rt_strlen(s);return a>=0&&z==(int64_t)n&&a<=q->n&&z<=q->n-a&&!xx_rt_memcmp(q->b+a,s,n);}
bool sxmt_table(sxmt_cursor*q,const sx_layout*l,int64_t at,int64_t width,uint64_t count){if(at<0||at>q->n||width<=0||count>(uint64_t)(q->n-at)/(uint64_t)width)return false;if(!count||q->c->count>=32000)return true;return sx_table(q->c,l,at,width,count>65536?65536:count);}
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
/* Native parsers establish the accepted grammar; this walk retains byte positions. */
bool sxmt_many(sxmt_cursor*q,const sx_layout*l,int64_t end){while(q->p<end){int64_t a,z;if(!sxmt_token(q,end,&a,&z,true))break;if(!sxmt_emit(q,l,a,z))return false;}return true;}
bool sxmt_uint_token(sxmt_cursor*q,int64_t a,int64_t z,uint64_t*v){uint64_t n=0;if(z<=0)return false;for(int64_t i=0;i<z;i++){unsigned d=q->b[a+i]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*v=n;return true;}
const sx_layout*sxmt_binary_type(unsigned kind,unsigned width,bool be){
#define MT_BINARY(k,w,t) if(kind==(k)&&width==(w))return be?&sxmt_binary_##t##_be:&sxmt_binary_##t##_le
 MT_BINARY('I',1,int8);MT_BINARY('U',1,uint8);MT_BINARY('I',2,int16);MT_BINARY('U',2,uint16);MT_BINARY('I',4,int32);MT_BINARY('U',4,uint32);MT_BINARY('F',4,float32);MT_BINARY('F',8,double);
#undef MT_BINARY
 return NULL;}
bool sxmt_remainder(sxmt_cursor*q,const sx_layout*l,int64_t end){while(q->p<end&&sxmt_space(q->b[q->p]))q->p++;return sxmt_emit(q,l,q->p,end-q->p);}
bool sxmt_quoted(sxmt_cursor*q,const sx_layout*l,int64_t end){while(q->p<end&&sxmt_space(q->b[q->p]))q->p++;if(q->p==end||q->b[q->p]!='"')return false;int64_t start=++q->p;while(q->p<end&&q->b[q->p]!='"'){if(q->b[q->p]=='\\'&&q->p+1<end)q->p++;q->p++;}if(q->p==end)return false;bool ok=sxmt_emit(q,l,start,q->p-start);q->p++;return ok;}
/* Used only for native-validated lexical scene grammars. Values remain physical
 * tokens. Integer/real describes spelling, not a reconstructed object field. */
bool sxmt_lex(sxmt_cursor*q,xx_file_type_t type){bool motion=false;unsigned expect=0;const sx_layout*requested=NULL;bool bang=type==XX_FILE_TYPE_BVH_MOTION||type==XX_FILE_TYPE_DIRECTX_X;
 if(type==XX_FILE_TYPE_DIRECTX_X){MT_EMIT(xfile_header,0,16);q->p=16;}
 while(q->p<q->n){if(q->c->count>=32000)return true;uint8_t c=q->b[q->p];if(sxmt_space(c)){q->p++;continue;}
 if(c=='#'||(bang&&c=='!')||(c=='/'&&q->p+1<q->n&&q->b[q->p+1]=='/')){while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;continue;}
 if(c=='/'&&q->p+1<q->n&&q->b[q->p+1]=='*'){q->p+=2;while(q->p+1<q->n&&(q->b[q->p]!='*'||q->b[q->p+1]!='/'))q->p++;if(q->p+1==q->n)return false;q->p+=2;continue;}
 if(c=='"'){if(!sxmt_quoted(q,&sxmt_name,q->n))return false;continue;}
 if(c=='{'||c=='}'||c=='('||c==')'||c==';'||c==','||c==':'||c=='['||c==']'){q->p++;continue;}
 int64_t a=q->p;bool number=(c>='0'&&c<='9')||c=='+'||c=='-'||c=='.',real=false;
 while(q->p<q->n){c=q->b[q->p];if(type==XX_FILE_TYPE_DIRECTX_X&&c=='/'&&q->p+1<q->n&&(q->b[q->p+1]=='/'||q->b[q->p+1]=='*'))break;if(sxmt_space(c)||c=='{'||c=='}'||c=='('||c==')'||c==';'||c==','||c==':'||c=='['||c==']'||c=='"')break;if(number&&(c=='.'||c=='e'||c=='E'))real=true;q->p++;}int64_t z=q->p-a;if(!z)return false;
 if(type==XX_FILE_TYPE_BVH_MOTION){if(sxmt_eq(q,a,z,"OFFSET")){expect=3;requested=&sxmt_real_value;}else if(sxmt_eq(q,a,z,"CHANNELS")){expect=1;requested=&sxmt_channel_count;}else if(sxmt_eq(q,a,z,"Frames")){expect=1;requested=&sxmt_frame_count;}else if(sxmt_eq(q,a,z,"Time")){expect=1;requested=&sxmt_frame_time;motion=true;}}
 const sx_layout*l=number?(expect?requested:motion?&sxmt_motion_value:real?&sxmt_real_value:&sxmt_integer_value):&sxmt_keyword;
 /* GUID and hex syntax are retained text, not mislabelled decimal values. */
 if(number){int64_t t=0;unsigned digits=0;if(t<z&&(q->b[a+t]=='+'||q->b[a+t]=='-'))t++;while(t<z&&q->b[a+t]>='0'&&q->b[a+t]<='9'){t++;digits++;}if(t<z&&q->b[a+t]=='.'){t++;while(t<z&&q->b[a+t]>='0'&&q->b[a+t]<='9'){t++;digits++;}}bool valid=digits>0;if(t<z&&(q->b[a+t]=='e'||q->b[a+t]=='E')){t++;if(t<z&&(q->b[a+t]=='+'||q->b[a+t]=='-'))t++;int64_t first=t;while(t<z&&q->b[a+t]>='0'&&q->b[a+t]<='9')t++;if(t==first)valid=false;}if(!valid||t!=z)l=&sxmt_record_text;}
 if(type==XX_FILE_TYPE_BVH_MOTION&&!number&&((z>=8&&sxmt_eq(q,a+z-8,8,"position"))||(z>=8&&sxmt_eq(q,a+z-8,8,"rotation"))))l=&sxmt_channel_name;
 if(!sxmt_emit(q,l,a,z))return false;if(number&&expect)expect--;
 }return true;}
static int sxmt_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxmt_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmt_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmt_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_modeltext_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_POLYGON_PLY:case XX_FILE_TYPE_POINTCLOUD_PCD:case XX_FILE_TYPE_WAVEFRONT_OBJ:case XX_FILE_TYPE_OFF_MESH:case XX_FILE_TYPE_AC3D_MODEL:case XX_FILE_TYPE_XFIG:case XX_FILE_TYPE_AUTOCAD_DXF:case XX_FILE_TYPE_FONT_BDF:case XX_FILE_TYPE_FONT_AFM:case XX_FILE_TYPE_FONTFORGE_SFD:case XX_FILE_TYPE_GTS_SURFACE:case XX_FILE_TYPE_BVH_MOTION:case XX_FILE_TYPE_DIRECTX_X:case XX_FILE_TYPE_LIGHTWAVE_SCENE:case XX_FILE_TYPE_METASEQUOIA_MQO:case XX_FILE_TYPE_AUTODESK_ASE:return true;default:return false;}}
static bool sx_modeltext_build(sx_context*c){
 if(!c||!c->f||c->size<1||c->size>67108864||xx_pd_is_stopped(c->pd))return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxmt_cursor cursor={c,b,c->size,0},*q=&cursor;xx_file_type_t type=c->f->file_type;
 if(ok)switch(type){case XX_FILE_TYPE_POLYGON_PLY:ok=sx_polygon_ply_build(q);break;case XX_FILE_TYPE_POINTCLOUD_PCD:ok=sx_pointcloud_pcd_build(q);break;case XX_FILE_TYPE_WAVEFRONT_OBJ:ok=sx_wavefront_obj_build(q);break;case XX_FILE_TYPE_OFF_MESH:ok=sx_off_mesh_build(q);break;case XX_FILE_TYPE_AC3D_MODEL:ok=sx_ac3d_model_build(q);break;case XX_FILE_TYPE_XFIG:ok=sx_xfig_build(q);break;case XX_FILE_TYPE_AUTOCAD_DXF:ok=sx_autocad_dxf_build(q);break;case XX_FILE_TYPE_FONT_BDF:ok=sx_font_bdf_build(q);break;case XX_FILE_TYPE_FONT_AFM:ok=sx_font_afm_build(q);break;case XX_FILE_TYPE_FONTFORGE_SFD:ok=sx_fontforge_sfd_build(q);break;case XX_FILE_TYPE_GTS_SURFACE:ok=sx_gts_surface_build(q);break;case XX_FILE_TYPE_BVH_MOTION:ok=sx_bvh_motion_build(q,type);break;case XX_FILE_TYPE_DIRECTX_X:ok=sx_directx_x_build(q,type);break;case XX_FILE_TYPE_LIGHTWAVE_SCENE:ok=sx_lightwave_scene_build(q,type);break;case XX_FILE_TYPE_METASEQUOIA_MQO:ok=sx_metasequoia_mqo_build(q,type);break;case XX_FILE_TYPE_AUTODESK_ASE:ok=sx_autodesk_ase_build(q,type);break;default:ok=false;break;}
 xx_mem_free(b);return ok&&sxmt_finish(c);}
#undef MT_EMIT
const sx_family sx_modeltext_family={sx_modeltext_supports,sx_modeltext_build,sx_modeltext_layouts,SX_COUNT(sx_modeltext_layouts),sx_modeltext_comment};
