/* SPDX-License-Identifier: MIT. Original physical model/font tokens and binary properties. */
static const xx_data_struct_field_desc sxmt_signature_fields[]={
 SX_FIELD("signature","char",0,0,SX_SIGNATURE),
};
static const sx_layout sxmt_signature={0x60520001U,"modeltext_signature",sxmt_signature_fields,SX_COUNT(sxmt_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_version_fields[]={
 SX_FIELD("version","char",0,0,SX_STRING),
};
static const sx_layout sxmt_version={0x60520002U,"modeltext_version",sxmt_version_fields,SX_COUNT(sxmt_version_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_encoding_fields[]={
 SX_FIELD("encoding","char",0,0,SX_STRING),
};
static const sx_layout sxmt_encoding={0x60520003U,"modeltext_encoding",sxmt_encoding_fields,SX_COUNT(sxmt_encoding_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_element_name_fields[]={
 SX_FIELD("element_name","char",0,0,SX_STRING),
};
static const sx_layout sxmt_element_name={0x60520004U,"modeltext_element_name",sxmt_element_name_fields,SX_COUNT(sxmt_element_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_property_name_fields[]={
 SX_FIELD("property_name","char",0,0,SX_STRING),
};
static const sx_layout sxmt_property_name={0x60520005U,"modeltext_property_name",sxmt_property_name_fields,SX_COUNT(sxmt_property_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_property_type_fields[]={
 SX_FIELD("property_type","char",0,0,SX_STRING),
};
static const sx_layout sxmt_property_type={0x60520006U,"modeltext_property_type",sxmt_property_type_fields,SX_COUNT(sxmt_property_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_count_type_fields[]={
 SX_FIELD("count_type","char",0,0,SX_STRING),
};
static const sx_layout sxmt_count_type={0x60520007U,"modeltext_count_type",sxmt_count_type_fields,SX_COUNT(sxmt_count_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_field_type_fields[]={
 SX_FIELD("field_type","char",0,0,SX_STRING),
};
static const sx_layout sxmt_field_type={0x60520008U,"modeltext_field_type",sxmt_field_type_fields,SX_COUNT(sxmt_field_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_object_type_fields[]={
 SX_FIELD("object_type","char",0,0,SX_STRING),
};
static const sx_layout sxmt_object_type={0x60520009U,"modeltext_object_type",sxmt_object_type_fields,SX_COUNT(sxmt_object_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_keyword_fields[]={
 SX_FIELD("keyword","char",0,0,SX_STRING),
};
static const sx_layout sxmt_keyword={0x6052000aU,"modeltext_keyword",sxmt_keyword_fields,SX_COUNT(sxmt_keyword_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_group_name_fields[]={
 SX_FIELD("group_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmt_group_name={0x6052000bU,"modeltext_group_name",sxmt_group_name_fields,SX_COUNT(sxmt_group_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_material_name_fields[]={
 SX_FIELD("material_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmt_material_name={0x6052000cU,"modeltext_material_name",sxmt_material_name_fields,SX_COUNT(sxmt_material_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_font_name_fields[]={
 SX_FIELD("font_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmt_font_name={0x6052000dU,"modeltext_font_name",sxmt_font_name_fields,SX_COUNT(sxmt_font_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_glyph_name_fields[]={
 SX_FIELD("glyph_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmt_glyph_name={0x6052000eU,"modeltext_glyph_name",sxmt_glyph_name_fields,SX_COUNT(sxmt_glyph_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_channel_name_fields[]={
 SX_FIELD("channel_name","char",0,0,SX_STRING),
};
static const sx_layout sxmt_channel_name={0x6052000fU,"modeltext_channel_name",sxmt_channel_name_fields,SX_COUNT(sxmt_channel_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_name_fields[]={
 SX_FIELD("name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmt_name={0x60520010U,"modeltext_name",sxmt_name_fields,SX_COUNT(sxmt_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_string_value_fields[]={
 SX_FIELD("string_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxmt_string_value={0x60520011U,"modeltext_string_value",sxmt_string_value_fields,SX_COUNT(sxmt_string_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_record_text_fields[]={
 SX_FIELD("record_text","utf8",0,0,SX_STRING),
};
static const sx_layout sxmt_record_text={0x60520012U,"modeltext_record_text",sxmt_record_text_fields,SX_COUNT(sxmt_record_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_vertex_count_fields[]={
 SX_FIELD("vertex_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_vertex_count={0x60520013U,"modeltext_vertex_count",sxmt_vertex_count_fields,SX_COUNT(sxmt_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_face_count_fields[]={
 SX_FIELD("face_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_face_count={0x60520014U,"modeltext_face_count",sxmt_face_count_fields,SX_COUNT(sxmt_face_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_edge_count_fields[]={
 SX_FIELD("edge_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_edge_count={0x60520015U,"modeltext_edge_count",sxmt_edge_count_fields,SX_COUNT(sxmt_edge_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_list_count_fields[]={
 SX_FIELD("list_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_list_count={0x60520016U,"modeltext_list_count",sxmt_list_count_fields,SX_COUNT(sxmt_list_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_element_count_fields[]={
 SX_FIELD("element_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_element_count={0x60520017U,"modeltext_element_count",sxmt_element_count_fields,SX_COUNT(sxmt_element_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_point_count_fields[]={
 SX_FIELD("point_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_point_count={0x60520018U,"modeltext_point_count",sxmt_point_count_fields,SX_COUNT(sxmt_point_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_width_fields[]={
 SX_FIELD("width","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_width={0x60520019U,"modeltext_width",sxmt_width_fields,SX_COUNT(sxmt_width_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_height_fields[]={
 SX_FIELD("height","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_height={0x6052001aU,"modeltext_height",sxmt_height_fields,SX_COUNT(sxmt_height_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_sample_count_fields[]={
 SX_FIELD("sample_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_sample_count={0x6052001bU,"modeltext_sample_count",sxmt_sample_count_fields,SX_COUNT(sxmt_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_vertex_index_fields[]={
 SX_FIELD("vertex_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_vertex_index={0x6052001cU,"modeltext_vertex_index",sxmt_vertex_index_fields,SX_COUNT(sxmt_vertex_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_texture_index_fields[]={
 SX_FIELD("texture_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_texture_index={0x6052001dU,"modeltext_texture_index",sxmt_texture_index_fields,SX_COUNT(sxmt_texture_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_normal_index_fields[]={
 SX_FIELD("normal_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_normal_index={0x6052001eU,"modeltext_normal_index",sxmt_normal_index_fields,SX_COUNT(sxmt_normal_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_edge_index_fields[]={
 SX_FIELD("edge_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_edge_index={0x6052001fU,"modeltext_edge_index",sxmt_edge_index_fields,SX_COUNT(sxmt_edge_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_material_index_fields[]={
 SX_FIELD("material_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_material_index={0x60520020U,"modeltext_material_index",sxmt_material_index_fields,SX_COUNT(sxmt_material_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_smoothing_group_fields[]={
 SX_FIELD("smoothing_group","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_smoothing_group={0x60520021U,"modeltext_smoothing_group",sxmt_smoothing_group_fields,SX_COUNT(sxmt_smoothing_group_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_child_count_fields[]={
 SX_FIELD("child_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_child_count={0x60520022U,"modeltext_child_count",sxmt_child_count_fields,SX_COUNT(sxmt_child_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_data_bytes_fields[]={
 SX_FIELD("data_bytes","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxmt_data_bytes={0x60520023U,"modeltext_data_bytes",sxmt_data_bytes_fields,SX_COUNT(sxmt_data_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_surface_count_fields[]={
 SX_FIELD("surface_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_surface_count={0x60520024U,"modeltext_surface_count",sxmt_surface_count_fields,SX_COUNT(sxmt_surface_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_reference_count_fields[]={
 SX_FIELD("reference_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_reference_count={0x60520025U,"modeltext_reference_count",sxmt_reference_count_fields,SX_COUNT(sxmt_reference_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_glyph_count_fields[]={
 SX_FIELD("glyph_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_glyph_count={0x60520026U,"modeltext_glyph_count",sxmt_glyph_count_fields,SX_COUNT(sxmt_glyph_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_property_total_fields[]={
 SX_FIELD("property_total","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_property_total={0x60520027U,"modeltext_property_total",sxmt_property_total_fields,SX_COUNT(sxmt_property_total_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_codepoint_fields[]={
 SX_FIELD("codepoint","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_codepoint={0x60520028U,"modeltext_codepoint",sxmt_codepoint_fields,SX_COUNT(sxmt_codepoint_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_glyph_index_fields[]={
 SX_FIELD("glyph_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_glyph_index={0x60520029U,"modeltext_glyph_index",sxmt_glyph_index_fields,SX_COUNT(sxmt_glyph_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_font_size_fields[]={
 SX_FIELD("font_size","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_font_size={0x6052002aU,"modeltext_font_size",sxmt_font_size_fields,SX_COUNT(sxmt_font_size_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_resolution_x_fields[]={
 SX_FIELD("resolution_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_resolution_x={0x6052002bU,"modeltext_resolution_x",sxmt_resolution_x_fields,SX_COUNT(sxmt_resolution_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_resolution_y_fields[]={
 SX_FIELD("resolution_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_resolution_y={0x6052002cU,"modeltext_resolution_y",sxmt_resolution_y_fields,SX_COUNT(sxmt_resolution_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bbox_width_fields[]={
 SX_FIELD("bbox_width","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_bbox_width={0x6052002dU,"modeltext_bbox_width",sxmt_bbox_width_fields,SX_COUNT(sxmt_bbox_width_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bbox_height_fields[]={
 SX_FIELD("bbox_height","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_bbox_height={0x6052002eU,"modeltext_bbox_height",sxmt_bbox_height_fields,SX_COUNT(sxmt_bbox_height_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bbox_x_fields[]={
 SX_FIELD("bbox_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_bbox_x={0x6052002fU,"modeltext_bbox_x",sxmt_bbox_x_fields,SX_COUNT(sxmt_bbox_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bbox_y_fields[]={
 SX_FIELD("bbox_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_bbox_y={0x60520030U,"modeltext_bbox_y",sxmt_bbox_y_fields,SX_COUNT(sxmt_bbox_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_swidth_x_fields[]={
 SX_FIELD("swidth_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_swidth_x={0x60520031U,"modeltext_swidth_x",sxmt_swidth_x_fields,SX_COUNT(sxmt_swidth_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_swidth_y_fields[]={
 SX_FIELD("swidth_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_swidth_y={0x60520032U,"modeltext_swidth_y",sxmt_swidth_y_fields,SX_COUNT(sxmt_swidth_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dwidth_x_fields[]={
 SX_FIELD("dwidth_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_dwidth_x={0x60520033U,"modeltext_dwidth_x",sxmt_dwidth_x_fields,SX_COUNT(sxmt_dwidth_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dwidth_y_fields[]={
 SX_FIELD("dwidth_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_dwidth_y={0x60520034U,"modeltext_dwidth_y",sxmt_dwidth_y_fields,SX_COUNT(sxmt_dwidth_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_integer_value_fields[]={
 SX_FIELD("integer_value","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_integer_value={0x60520035U,"modeltext_integer_value",sxmt_integer_value_fields,SX_COUNT(sxmt_integer_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_frame_count_fields[]={
 SX_FIELD("frame_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_frame_count={0x60520036U,"modeltext_frame_count",sxmt_frame_count_fields,SX_COUNT(sxmt_frame_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_channel_count_fields[]={
 SX_FIELD("channel_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_channel_count={0x60520037U,"modeltext_channel_count",sxmt_channel_count_fields,SX_COUNT(sxmt_channel_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_curve_flags_fields[]={
 SX_FIELD("curve_flags","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_curve_flags={0x60520038U,"modeltext_curve_flags",sxmt_curve_flags_fields,SX_COUNT(sxmt_curve_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_x_fields[]={
 SX_FIELD("x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_x={0x60520039U,"modeltext_x",sxmt_x_fields,SX_COUNT(sxmt_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_y_fields[]={
 SX_FIELD("y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_y={0x6052003aU,"modeltext_y",sxmt_y_fields,SX_COUNT(sxmt_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_z_fields[]={
 SX_FIELD("z","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_z={0x6052003bU,"modeltext_z",sxmt_z_fields,SX_COUNT(sxmt_z_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_w_fields[]={
 SX_FIELD("w","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_w={0x6052003cU,"modeltext_w",sxmt_w_fields,SX_COUNT(sxmt_w_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_u_fields[]={
 SX_FIELD("u","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_u={0x6052003dU,"modeltext_u",sxmt_u_fields,SX_COUNT(sxmt_u_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_v_fields[]={
 SX_FIELD("v","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_v={0x6052003eU,"modeltext_v",sxmt_v_fields,SX_COUNT(sxmt_v_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_normal_x_fields[]={
 SX_FIELD("normal_x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_normal_x={0x6052003fU,"modeltext_normal_x",sxmt_normal_x_fields,SX_COUNT(sxmt_normal_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_normal_y_fields[]={
 SX_FIELD("normal_y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_normal_y={0x60520040U,"modeltext_normal_y",sxmt_normal_y_fields,SX_COUNT(sxmt_normal_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_normal_z_fields[]={
 SX_FIELD("normal_z","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_normal_z={0x60520041U,"modeltext_normal_z",sxmt_normal_z_fields,SX_COUNT(sxmt_normal_z_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_red_fields[]={
 SX_FIELD("red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_red={0x60520042U,"modeltext_red",sxmt_red_fields,SX_COUNT(sxmt_red_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_green_fields[]={
 SX_FIELD("green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_green={0x60520043U,"modeltext_green",sxmt_green_fields,SX_COUNT(sxmt_green_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_blue_fields[]={
 SX_FIELD("blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_blue={0x60520044U,"modeltext_blue",sxmt_blue_fields,SX_COUNT(sxmt_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_alpha_fields[]={
 SX_FIELD("alpha","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_alpha={0x60520045U,"modeltext_alpha",sxmt_alpha_fields,SX_COUNT(sxmt_alpha_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_translate_x_fields[]={
 SX_FIELD("translate_x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_translate_x={0x60520046U,"modeltext_translate_x",sxmt_translate_x_fields,SX_COUNT(sxmt_translate_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_translate_y_fields[]={
 SX_FIELD("translate_y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_translate_y={0x60520047U,"modeltext_translate_y",sxmt_translate_y_fields,SX_COUNT(sxmt_translate_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_translate_z_fields[]={
 SX_FIELD("translate_z","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_translate_z={0x60520048U,"modeltext_translate_z",sxmt_translate_z_fields,SX_COUNT(sxmt_translate_z_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_quaternion_w_fields[]={
 SX_FIELD("quaternion_w","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_quaternion_w={0x60520049U,"modeltext_quaternion_w",sxmt_quaternion_w_fields,SX_COUNT(sxmt_quaternion_w_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_quaternion_x_fields[]={
 SX_FIELD("quaternion_x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_quaternion_x={0x6052004aU,"modeltext_quaternion_x",sxmt_quaternion_x_fields,SX_COUNT(sxmt_quaternion_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_quaternion_y_fields[]={
 SX_FIELD("quaternion_y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_quaternion_y={0x6052004bU,"modeltext_quaternion_y",sxmt_quaternion_y_fields,SX_COUNT(sxmt_quaternion_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_quaternion_z_fields[]={
 SX_FIELD("quaternion_z","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_quaternion_z={0x6052004cU,"modeltext_quaternion_z",sxmt_quaternion_z_fields,SX_COUNT(sxmt_quaternion_z_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_real_value_fields[]={
 SX_FIELD("real_value","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_real_value={0x6052004dU,"modeltext_real_value",sxmt_real_value_fields,SX_COUNT(sxmt_real_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_frame_time_fields[]={
 SX_FIELD("frame_time","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_frame_time={0x6052004eU,"modeltext_frame_time",sxmt_frame_time_fields,SX_COUNT(sxmt_frame_time_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_rotation_value_fields[]={
 SX_FIELD("rotation_value","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_rotation_value={0x6052004fU,"modeltext_rotation_value",sxmt_rotation_value_fields,SX_COUNT(sxmt_rotation_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_transparency_fields[]={
 SX_FIELD("transparency","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_transparency={0x60520050U,"modeltext_transparency",sxmt_transparency_fields,SX_COUNT(sxmt_transparency_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_shininess_fields[]={
 SX_FIELD("shininess","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_shininess={0x60520051U,"modeltext_shininess",sxmt_shininess_fields,SX_COUNT(sxmt_shininess_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_ambient_red_fields[]={
 SX_FIELD("ambient_red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_ambient_red={0x60520052U,"modeltext_ambient_red",sxmt_ambient_red_fields,SX_COUNT(sxmt_ambient_red_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_ambient_green_fields[]={
 SX_FIELD("ambient_green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_ambient_green={0x60520053U,"modeltext_ambient_green",sxmt_ambient_green_fields,SX_COUNT(sxmt_ambient_green_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_ambient_blue_fields[]={
 SX_FIELD("ambient_blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_ambient_blue={0x60520054U,"modeltext_ambient_blue",sxmt_ambient_blue_fields,SX_COUNT(sxmt_ambient_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_emission_red_fields[]={
 SX_FIELD("emission_red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_emission_red={0x60520055U,"modeltext_emission_red",sxmt_emission_red_fields,SX_COUNT(sxmt_emission_red_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_emission_green_fields[]={
 SX_FIELD("emission_green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_emission_green={0x60520056U,"modeltext_emission_green",sxmt_emission_green_fields,SX_COUNT(sxmt_emission_green_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_emission_blue_fields[]={
 SX_FIELD("emission_blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_emission_blue={0x60520057U,"modeltext_emission_blue",sxmt_emission_blue_fields,SX_COUNT(sxmt_emission_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_specular_red_fields[]={
 SX_FIELD("specular_red","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_specular_red={0x60520058U,"modeltext_specular_red",sxmt_specular_red_fields,SX_COUNT(sxmt_specular_red_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_specular_green_fields[]={
 SX_FIELD("specular_green","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_specular_green={0x60520059U,"modeltext_specular_green",sxmt_specular_green_fields,SX_COUNT(sxmt_specular_green_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_specular_blue_fields[]={
 SX_FIELD("specular_blue","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_specular_blue={0x6052005aU,"modeltext_specular_blue",sxmt_specular_blue_fields,SX_COUNT(sxmt_specular_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_font_metric_fields[]={
 SX_FIELD("font_metric","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_font_metric={0x6052005bU,"modeltext_font_metric",sxmt_font_metric_fields,SX_COUNT(sxmt_font_metric_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_motion_value_fields[]={
 SX_FIELD("motion_value","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_motion_value={0x6052005cU,"modeltext_motion_value",sxmt_motion_value_fields,SX_COUNT(sxmt_motion_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_surface_flags_fields[]={
 SX_FIELD("surface_flags","ascii_hex",0,0,SX_FLAGS),
};
static const sx_layout sxmt_surface_flags={0x6052005dU,"modeltext_surface_flags",sxmt_surface_flags_fields,SX_COUNT(sxmt_surface_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_glyph_attributes_fields[]={
 SX_FIELD("glyph_attributes","ascii_hex",0,0,SX_FLAGS),
};
static const sx_layout sxmt_glyph_attributes={0x6052005eU,"modeltext_glyph_attributes",sxmt_glyph_attributes_fields,SX_COUNT(sxmt_glyph_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bitmap_byte_fields[]={
 SX_FIELD("bitmap_byte","ascii_hex",0,0,SX_FLAGS),
};
static const sx_layout sxmt_bitmap_byte={0x6052005fU,"modeltext_bitmap_byte",sxmt_bitmap_byte_fields,SX_COUNT(sxmt_bitmap_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_character_code_hex_fields[]={
 SX_FIELD("character_code_hex","ascii_hex",0,0,SX_ID),
};
static const sx_layout sxmt_character_code_hex={0x60520060U,"modeltext_character_code_hex",sxmt_character_code_hex_fields,SX_COUNT(sxmt_character_code_hex_fields),SX_LE};
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
static const xx_data_struct_field_desc sxmt_list_uint8_le_fields[]={
 SX_FIELD("list_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmt_list_uint8_le={0x60520069U,"modeltext_list_uint8_le",sxmt_list_uint8_le_fields,SX_COUNT(sxmt_list_uint8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_list_uint16_le_fields[]={
 SX_FIELD("list_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmt_list_uint16_le={0x6052006aU,"modeltext_list_uint16_le",sxmt_list_uint16_le_fields,SX_COUNT(sxmt_list_uint16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_list_uint32_le_fields[]={
 SX_FIELD("list_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmt_list_uint32_le={0x6052006bU,"modeltext_list_uint32_le",sxmt_list_uint32_le_fields,SX_COUNT(sxmt_list_uint32_le_fields),SX_LE};
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
static const xx_data_struct_field_desc sxmt_list_uint8_be_fields[]={
 SX_FIELD("list_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmt_list_uint8_be={0x60520074U,"modeltext_list_uint8_be",sxmt_list_uint8_be_fields,SX_COUNT(sxmt_list_uint8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_list_uint16_be_fields[]={
 SX_FIELD("list_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmt_list_uint16_be={0x60520075U,"modeltext_list_uint16_be",sxmt_list_uint16_be_fields,SX_COUNT(sxmt_list_uint16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_list_uint32_be_fields[]={
 SX_FIELD("list_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmt_list_uint32_be={0x60520076U,"modeltext_list_uint32_be",sxmt_list_uint32_be_fields,SX_COUNT(sxmt_list_uint32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_dxf_signature_fields[]={
 SX_FIELD("signature","char[22]",0,22,SX_SIGNATURE),
};
static const sx_layout sxmt_dxf_signature={0x60520077U,"modeltext_dxf_signature",sxmt_dxf_signature_fields,SX_COUNT(sxmt_dxf_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_group_code_fields[]={
 SX_FIELD("group_code","uint16",0,2,SX_ID),
};
static const sx_layout sxmt_dxf_group_code={0x60520078U,"modeltext_dxf_group_code",sxmt_dxf_group_code_fields,SX_COUNT(sxmt_dxf_group_code_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_int8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxmt_dxf_int8={0x60520079U,"modeltext_dxf_int8",sxmt_dxf_int8_fields,SX_COUNT(sxmt_dxf_int8_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_int16_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxmt_dxf_int16={0x6052007aU,"modeltext_dxf_int16",sxmt_dxf_int16_fields,SX_COUNT(sxmt_dxf_int16_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_int32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxmt_dxf_int32={0x6052007bU,"modeltext_dxf_int32",sxmt_dxf_int32_fields,SX_COUNT(sxmt_dxf_int32_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_int64_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxmt_dxf_int64={0x6052007cU,"modeltext_dxf_int64",sxmt_dxf_int64_fields,SX_COUNT(sxmt_dxf_int64_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_double_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
static const sx_layout sxmt_dxf_double={0x6052007dU,"modeltext_dxf_double",sxmt_dxf_double_fields,SX_COUNT(sxmt_dxf_double_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_chunk_length_fields[]={
 SX_FIELD("binary_chunk_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxmt_dxf_chunk_length={0x6052007eU,"modeltext_dxf_chunk_length",sxmt_dxf_chunk_length_fields,SX_COUNT(sxmt_dxf_chunk_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_xfile_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("major_version","char[2]",4,2,SX_NONE),
 SX_FIELD("minor_version","char[2]",6,2,SX_NONE),
 SX_FIELD("encoding","char[4]",8,4,SX_STRING),
 SX_FIELD("float_width","char[4]",12,4,SX_NONE),
};
static const sx_layout sxmt_xfile_header={0x6052007fU,"modeltext_xfile_header",sxmt_xfile_header_fields,SX_COUNT(sxmt_xfile_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_orientation_fields[]={
 SX_FIELD("fig_orientation","char",0,0,SX_STRING),
};
static const sx_layout sxmt_fig_orientation={0x60520080U,"modeltext_fig_orientation",sxmt_fig_orientation_fields,SX_COUNT(sxmt_fig_orientation_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_justification_fields[]={
 SX_FIELD("fig_justification","char",0,0,SX_STRING),
};
static const sx_layout sxmt_fig_justification={0x60520081U,"modeltext_fig_justification",sxmt_fig_justification_fields,SX_COUNT(sxmt_fig_justification_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_units_fields[]={
 SX_FIELD("fig_units","char",0,0,SX_STRING),
};
static const sx_layout sxmt_fig_units={0x60520082U,"modeltext_fig_units",sxmt_fig_units_fields,SX_COUNT(sxmt_fig_units_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_paper_size_fields[]={
 SX_FIELD("fig_paper_size","char",0,0,SX_STRING),
};
static const sx_layout sxmt_fig_paper_size={0x60520083U,"modeltext_fig_paper_size",sxmt_fig_paper_size_fields,SX_COUNT(sxmt_fig_paper_size_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_page_mode_fields[]={
 SX_FIELD("fig_page_mode","char",0,0,SX_STRING),
};
static const sx_layout sxmt_fig_page_mode={0x60520084U,"modeltext_fig_page_mode",sxmt_fig_page_mode_fields,SX_COUNT(sxmt_fig_page_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_object_code_fields[]={
 SX_FIELD("fig_object_code","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_object_code={0x60520085U,"modeltext_fig_object_code",sxmt_fig_object_code_fields,SX_COUNT(sxmt_fig_object_code_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_subtype_fields[]={
 SX_FIELD("fig_subtype","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_subtype={0x60520086U,"modeltext_fig_subtype",sxmt_fig_subtype_fields,SX_COUNT(sxmt_fig_subtype_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_line_style_fields[]={
 SX_FIELD("fig_line_style","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_line_style={0x60520087U,"modeltext_fig_line_style",sxmt_fig_line_style_fields,SX_COUNT(sxmt_fig_line_style_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_thickness_fields[]={
 SX_FIELD("fig_thickness","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_thickness={0x60520088U,"modeltext_fig_thickness",sxmt_fig_thickness_fields,SX_COUNT(sxmt_fig_thickness_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_pen_color_fields[]={
 SX_FIELD("fig_pen_color","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_pen_color={0x60520089U,"modeltext_fig_pen_color",sxmt_fig_pen_color_fields,SX_COUNT(sxmt_fig_pen_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_fill_color_fields[]={
 SX_FIELD("fig_fill_color","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_fill_color={0x6052008aU,"modeltext_fig_fill_color",sxmt_fig_fill_color_fields,SX_COUNT(sxmt_fig_fill_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_depth_fields[]={
 SX_FIELD("fig_depth","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_depth={0x6052008bU,"modeltext_fig_depth",sxmt_fig_depth_fields,SX_COUNT(sxmt_fig_depth_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_pen_style_fields[]={
 SX_FIELD("fig_pen_style","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_pen_style={0x6052008cU,"modeltext_fig_pen_style",sxmt_fig_pen_style_fields,SX_COUNT(sxmt_fig_pen_style_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_area_fill_fields[]={
 SX_FIELD("fig_area_fill","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_area_fill={0x6052008dU,"modeltext_fig_area_fill",sxmt_fig_area_fill_fields,SX_COUNT(sxmt_fig_area_fill_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_direction_fields[]={
 SX_FIELD("fig_direction","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_direction={0x6052008eU,"modeltext_fig_direction",sxmt_fig_direction_fields,SX_COUNT(sxmt_fig_direction_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_center_x_fields[]={
 SX_FIELD("fig_center_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_center_x={0x6052008fU,"modeltext_fig_center_x",sxmt_fig_center_x_fields,SX_COUNT(sxmt_fig_center_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_center_y_fields[]={
 SX_FIELD("fig_center_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_center_y={0x60520090U,"modeltext_fig_center_y",sxmt_fig_center_y_fields,SX_COUNT(sxmt_fig_center_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_radius_x_fields[]={
 SX_FIELD("fig_radius_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_radius_x={0x60520091U,"modeltext_fig_radius_x",sxmt_fig_radius_x_fields,SX_COUNT(sxmt_fig_radius_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_radius_y_fields[]={
 SX_FIELD("fig_radius_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_radius_y={0x60520092U,"modeltext_fig_radius_y",sxmt_fig_radius_y_fields,SX_COUNT(sxmt_fig_radius_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_start_x_fields[]={
 SX_FIELD("fig_start_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_start_x={0x60520093U,"modeltext_fig_start_x",sxmt_fig_start_x_fields,SX_COUNT(sxmt_fig_start_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_start_y_fields[]={
 SX_FIELD("fig_start_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_start_y={0x60520094U,"modeltext_fig_start_y",sxmt_fig_start_y_fields,SX_COUNT(sxmt_fig_start_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_end_x_fields[]={
 SX_FIELD("fig_end_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_end_x={0x60520095U,"modeltext_fig_end_x",sxmt_fig_end_x_fields,SX_COUNT(sxmt_fig_end_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_end_y_fields[]={
 SX_FIELD("fig_end_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_end_y={0x60520096U,"modeltext_fig_end_y",sxmt_fig_end_y_fields,SX_COUNT(sxmt_fig_end_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_join_style_fields[]={
 SX_FIELD("fig_join_style","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_join_style={0x60520097U,"modeltext_fig_join_style",sxmt_fig_join_style_fields,SX_COUNT(sxmt_fig_join_style_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_cap_style_fields[]={
 SX_FIELD("fig_cap_style","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_cap_style={0x60520098U,"modeltext_fig_cap_style",sxmt_fig_cap_style_fields,SX_COUNT(sxmt_fig_cap_style_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_radius_fields[]={
 SX_FIELD("fig_radius","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_radius={0x60520099U,"modeltext_fig_radius",sxmt_fig_radius_fields,SX_COUNT(sxmt_fig_radius_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_forward_arrow_fields[]={
 SX_FIELD("fig_forward_arrow","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_forward_arrow={0x6052009aU,"modeltext_fig_forward_arrow",sxmt_fig_forward_arrow_fields,SX_COUNT(sxmt_fig_forward_arrow_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_backward_arrow_fields[]={
 SX_FIELD("fig_backward_arrow","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_backward_arrow={0x6052009bU,"modeltext_fig_backward_arrow",sxmt_fig_backward_arrow_fields,SX_COUNT(sxmt_fig_backward_arrow_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_point_count_fields[]={
 SX_FIELD("fig_point_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmt_fig_point_count={0x6052009cU,"modeltext_fig_point_count",sxmt_fig_point_count_fields,SX_COUNT(sxmt_fig_point_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_color_index_fields[]={
 SX_FIELD("fig_color_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_color_index={0x6052009dU,"modeltext_fig_color_index",sxmt_fig_color_index_fields,SX_COUNT(sxmt_fig_color_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_transparent_color_fields[]={
 SX_FIELD("fig_transparent_color","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_transparent_color={0x6052009eU,"modeltext_fig_transparent_color",sxmt_fig_transparent_color_fields,SX_COUNT(sxmt_fig_transparent_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_resolution_fields[]={
 SX_FIELD("fig_resolution","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_resolution={0x6052009fU,"modeltext_fig_resolution",sxmt_fig_resolution_fields,SX_COUNT(sxmt_fig_resolution_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_coordinate_system_fields[]={
 SX_FIELD("fig_coordinate_system","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_coordinate_system={0x605200a0U,"modeltext_fig_coordinate_system",sxmt_fig_coordinate_system_fields,SX_COUNT(sxmt_fig_coordinate_system_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_magnification_fields[]={
 SX_FIELD("fig_magnification","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_magnification={0x605200a1U,"modeltext_fig_magnification",sxmt_fig_magnification_fields,SX_COUNT(sxmt_fig_magnification_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_style_value_fields[]={
 SX_FIELD("fig_style_value","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_style_value={0x605200a2U,"modeltext_fig_style_value",sxmt_fig_style_value_fields,SX_COUNT(sxmt_fig_style_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_angle_fields[]={
 SX_FIELD("fig_angle","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxmt_fig_angle={0x605200a3U,"modeltext_fig_angle",sxmt_fig_angle_fields,SX_COUNT(sxmt_fig_angle_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_fig_rgb_fields[]={
 SX_FIELD("fig_rgb","ascii_hex",0,0,SX_FLAGS),
};
static const sx_layout sxmt_fig_rgb={0x605200a4U,"modeltext_fig_rgb",sxmt_fig_rgb_fields,SX_COUNT(sxmt_fig_rgb_fields),SX_LE};
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

/* Bounded physical tokens. Whitespace and unparsed bodies retain raw spans. */
typedef struct sxmt_cursor {sx_context*c;uint8_t*b;int64_t n,p;} sxmt_cursor;
static bool sxmt_space(uint8_t x){return x==' '||(x>=9&&x<=13);}
static bool sxmt_emit(sxmt_cursor*q,const sx_layout*l,int64_t a,int64_t z){if(a<0||z<0||a>q->n||z>q->n-a)return false;if(!z||q->c->count>=32000)return !xx_pd_is_stopped(q->c->pd);int64_t limit=l->fields[0].size?INT64_MAX:sx_variable_field_limit(l->fields[0].type);if(z>limit)return true;if(!l->fields[0].size&&!xx_rt_wcscmp(l->fields[0].type,L"ascii_hex")){uint64_t value=0;for(int64_t i=0;i<z;i++){unsigned ch=q->b[a+i],digit=ch>='0'&&ch<='9'?ch-'0':ch>='a'&&ch<='f'?ch-'a'+10:ch>='A'&&ch<='F'?ch-'A'+10:16;if(digit>=16||value>(UINT64_MAX-digit)/16)return false;value=value*16+digit;}}return sx_add(q->c,l,a,z);}
static bool sxmt_token(sxmt_cursor*q,int64_t end,int64_t*a,int64_t*z,bool comments){if(q->p<0||end>q->n||q->p>end)return false;for(;;){while(q->p<end&&sxmt_space(q->b[q->p]))q->p++;if(!comments||q->p==end||q->b[q->p]!='#')break;while(q->p<end&&q->b[q->p]!='\n')q->p++;}if(q->p==end)return false;*a=q->p;while(q->p<end&&!sxmt_space(q->b[q->p])&&(!comments||q->b[q->p]!='#'))q->p++;*z=q->p-*a;return *z>0&&!xx_pd_is_stopped(q->c->pd);}
static bool sxmt_value(sxmt_cursor*q,const sx_layout*l,int64_t end,uint64_t*out){int64_t a,z;if(!sxmt_token(q,end,&a,&z,true)||!sxmt_emit(q,l,a,z))return false;if(out){uint64_t v=0;int64_t i=0;if(q->b[a]=='+')i++;if(i==z)return false;for(;i<z;i++){unsigned d=q->b[a+i]-'0';if(d>9||v>(UINT64_MAX-d)/10)return false;v=v*10+d;}*out=v;}return true;}
static bool sxmt_line(sxmt_cursor*q,int64_t*a,int64_t*end,bool comments){while(q->p<q->n){int64_t start=q->p,stop;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;stop=q->p;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;if(comments){bool quoted=false;for(int64_t i=start;i<stop;i++){if(q->b[i]=='\\'&&quoted&&i+1<stop){i++;continue;}if(q->b[i]=='"')quoted=!quoted;if(q->b[i]=='#'&&!quoted){stop=i;break;}}}while(start<stop&&sxmt_space(q->b[start]))start++;while(stop>start&&sxmt_space(q->b[stop-1]))stop--;if(start<stop){*a=start;*end=stop;return !xx_pd_is_stopped(q->c->pd);}}return false;}
static bool sxmt_eq(sxmt_cursor*q,int64_t a,int64_t z,const char*s){size_t n=xx_rt_strlen(s);return a>=0&&z==(int64_t)n&&a<=q->n&&z<=q->n-a&&!xx_rt_memcmp(q->b+a,s,n);}
static bool sxmt_values(sxmt_cursor*q,int64_t a,int64_t end,const sx_layout*const*layouts,unsigned count){int64_t save=q->p;q->p=a;bool ok=true;for(unsigned i=0;i<count;i++)if(!sxmt_value(q,layouts[i],end,NULL)){ok=false;break;}q->p=save;return ok;}
static bool sxmt_table(sxmt_cursor*q,const sx_layout*l,int64_t at,int64_t width,uint64_t count){if(at<0||at>q->n||width<=0||count>(uint64_t)(q->n-at)/(uint64_t)width)return false;if(!count||q->c->count>=32000)return true;return sx_table(q->c,l,at,width,count>65536?65536:count);}
#define MT_VALUE(n,e,v) do{if(!sxmt_value(q,&sxmt_##n,(e),(v)))return false;}while(0)
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)

/* Native parsers establish the accepted grammar; this walk retains byte positions. */
static bool sxmt_many(sxmt_cursor*q,const sx_layout*l,int64_t end){while(q->p<end){int64_t a,z;if(!sxmt_token(q,end,&a,&z,true))break;if(!sxmt_emit(q,l,a,z))return false;}return true;}
static bool sxmt_uint_token(sxmt_cursor*q,int64_t a,int64_t z,uint64_t*v){uint64_t n=0;if(z<=0)return false;for(int64_t i=0;i<z;i++){unsigned d=q->b[a+i]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*v=n;return true;}
static bool sxmt_obj(sxmt_cursor*q){int64_t a,end;while(sxmt_line(q,&a,&end,true)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;int64_t k,z;if(!sxmt_token(q,end,&k,&z,false))return false;MT_EMIT(keyword,k,z);
 if(sxmt_eq(q,k,z,"v")||sxmt_eq(q,k,z,"vt")||sxmt_eq(q,k,z,"vn")){bool tex=sxmt_eq(q,k,z,"vt"),normal=sxmt_eq(q,k,z,"vn");const sx_layout*ls[]={tex?&sxmt_u:normal?&sxmt_normal_x:&sxmt_x,tex?&sxmt_v:normal?&sxmt_normal_y:&sxmt_y,tex?&sxmt_w:normal?&sxmt_normal_z:&sxmt_z,&sxmt_w};unsigned i=0;while(sxmt_token(q,end,&a,&z,true)){if(i>=4||!sxmt_emit(q,ls[i++],a,z))return false;}}
 else if(sxmt_eq(q,k,z,"f")){while(sxmt_token(q,end,&a,&z,true)){int64_t start=a,stop=a+z;unsigned i=0;const sx_layout*ls[]={&sxmt_vertex_index,&sxmt_texture_index,&sxmt_normal_index};for(int64_t p=a;p<=stop;p++)if(p==stop||q->b[p]=='/'){if(i>=3)return false;if(p>start&&!sxmt_emit(q,ls[i],start,p-start))return false;start=p+1;i++;}}}
 else {while(q->p<end&&sxmt_space(q->b[q->p]))q->p++;const sx_layout*l=sxmt_eq(q,k,z,"s")?(sxmt_eq(q,q->p,end-q->p,"off")?&sxmt_string_value:&sxmt_smoothing_group):(sxmt_eq(q,k,z,"usemtl")||sxmt_eq(q,k,z,"mtllib"))?&sxmt_material_name:&sxmt_group_name;if(!sxmt_emit(q,l,q->p,end-q->p))return false;}q->p=next;}return q->c->count>0;}
static bool sxmt_off(sxmt_cursor*q){int64_t a,e;if(!sxmt_line(q,&a,&e,true))return false;MT_EMIT(signature,a,e-a);if(!sxmt_line(q,&a,&e,true))return false;int64_t next=q->p;q->p=a;uint64_t nv,nf,ne;MT_VALUE(vertex_count,e,&nv);MT_VALUE(face_count,e,&nf);MT_VALUE(edge_count,e,&ne);q->p=next;if(nv>1000000||nf>1000000)return false;
 const sx_layout*xyz[]={&sxmt_x,&sxmt_y,&sxmt_z};for(uint64_t i=0;i<nv;i++){if(q->c->count>=32000)return true;if(!sxmt_line(q,&a,&e,true)||!sxmt_values(q,a,e,xyz,3))return false;}
 for(uint64_t i=0;i<nf;i++){if(q->c->count>=32000)return true;if(!sxmt_line(q,&a,&e,true))return false;next=q->p;q->p=a;uint64_t n;MT_VALUE(list_count,e,&n);if(n>1000000)return false;for(uint64_t j=0;j<n;j++){if(q->c->count>=32000)return true;MT_VALUE(vertex_index,e,NULL);}const sx_layout*colors[]={&sxmt_red,&sxmt_green,&sxmt_blue,&sxmt_alpha};unsigned j=0;int64_t z;while(sxmt_token(q,e,&a,&z,true)){if(j>=4||!sxmt_emit(q,colors[j++],a,z))return false;}q->p=next;}return true;}
/* The native GTS grammar is token-based, not line-based. Its enabled
 * comments are # and !; a CR alone terminates either comment. */
static bool sxmt_gts_token(sxmt_cursor*q,int64_t*a,int64_t*z){
 for(;;){while(q->p<q->n&&sxmt_space(q->b[q->p]))q->p++;if(q->p==q->n)return false;
  if(q->b[q->p]!='#'&&q->b[q->p]!='!')break;
  while(q->p<q->n&&q->b[q->p]!='\r'&&q->b[q->p]!='\n')q->p++;
 }
 *a=q->p;while(q->p<q->n&&!sxmt_space(q->b[q->p])&&q->b[q->p]!='#'&&q->b[q->p]!='!')q->p++;
 *z=q->p-*a;return *z>0&&!xx_pd_is_stopped(q->c->pd);
}
static bool sxmt_gts_value(sxmt_cursor*q,const sx_layout*l,uint64_t*out){
 int64_t a,z;if(!sxmt_gts_token(q,&a,&z)||!sxmt_emit(q,l,a,z))return false;
 if(out){if(q->b[a]=='+'){a++;z--;}if(!sxmt_uint_token(q,a,z,out))return false;}return true;
}
static bool sxmt_gts(sxmt_cursor*q){uint64_t nv,ne,nf;
 if(!sxmt_gts_value(q,&sxmt_vertex_count,&nv)||!sxmt_gts_value(q,&sxmt_edge_count,&ne)||!sxmt_gts_value(q,&sxmt_face_count,&nf)||nv>1000000||ne>1000000||nf>1000000)return false;
 int64_t save=q->p,a,z;
 if(!sxmt_gts_token(q,&a,&z))return false;
 if(sxmt_eq(q,a,z,"GtsSurface")){
  static const char*classes[]={"GtsSurface","GtsFace","GtsEdge","GtsVertex"};
  for(unsigned i=0;i<4;i++){if(i&&!sxmt_gts_token(q,&a,&z))return false;if(!sxmt_eq(q,a,z,classes[i])||!sxmt_emit(q,&sxmt_object_type,a,z))return false;}
 }else q->p=save;
 const sx_layout*xyz[]={&sxmt_x,&sxmt_y,&sxmt_z};for(uint64_t i=0;i<nv;i++)for(unsigned j=0;j<3;j++){if(q->c->count>=32000)return true;if(!sxmt_gts_value(q,xyz[j],NULL))return false;}
 for(uint64_t i=0;i<ne;i++)for(unsigned j=0;j<2;j++){if(q->c->count>=32000)return true;if(!sxmt_gts_value(q,&sxmt_vertex_index,NULL))return false;}
 for(uint64_t i=0;i<nf;i++)for(unsigned j=0;j<3;j++){if(q->c->count>=32000)return true;if(!sxmt_gts_value(q,&sxmt_edge_index,NULL))return false;}return true;}
static const sx_layout*sxmt_binary_type(unsigned kind,unsigned width,bool be){
#define MT_BINARY(k,w,t) if(kind==(k)&&width==(w))return be?&sxmt_binary_##t##_be:&sxmt_binary_##t##_le
 MT_BINARY('I',1,int8);MT_BINARY('U',1,uint8);MT_BINARY('I',2,int16);MT_BINARY('U',2,uint16);MT_BINARY('I',4,int32);MT_BINARY('U',4,uint32);MT_BINARY('F',4,float32);MT_BINARY('F',8,double);
#undef MT_BINARY
 return NULL;}
static bool sxmt_dxf(sxmt_cursor*q){if(q->n<22)return false;MT_EMIT(dxf_signature,0,22);q->p=22;while(q->p<q->n){if(q->c->count>=32000)return true;if(q->n-q->p<2)return false;unsigned code=xx_data_get_u16(q->b+q->p,2,0,false),kind=255;MT_EMIT(dxf_group_code,q->p,2);q->p+=2;
 if((code>=10&&code<=59)||(code>=110&&code<=149)||(code>=210&&code<=239)||(code>=460&&code<=469)||(code>=1010&&code<=1059))kind=8;
 else if((code>=60&&code<=79)||(code>=170&&code<=179)||(code>=270&&code<=289)||(code>=370&&code<=389)||(code>=400&&code<=409)||code==1060||code==1070)kind=2;
 else if((code>=90&&code<=99)||(code>=420&&code<=429)||(code>=440&&code<=459)||code==1071)kind=4;
 else if(code>=160&&code<=169)kind=9;else if(code>=290&&code<=299)kind=1;else if((code>=310&&code<=319)||code==1004)kind=3;
 else if(code<=9||(code>=100&&code<=102)||code==105||(code>=300&&code<=309)||(code>=320&&code<=369)||(code>=390&&code<=399)||(code>=410&&code<=419)||(code>=430&&code<=439)||(code>=470&&code<=481)||code==999||(code>=1000&&code<=1009))kind=0;
 if(kind==255)return false;if(!kind){int64_t a=q->p;while(q->p<q->n&&q->b[q->p])q->p++;if(q->p==q->n)return false;MT_EMIT(string_value,a,q->p-a);q->p++;}
 else if(kind==3){if(q->p==q->n)return false;unsigned n=q->b[q->p];MT_EMIT(dxf_chunk_length,q->p,1);q->p++;if(n>(uint64_t)(q->n-q->p))return false;q->p+=n;}
 else {const sx_layout*l=kind==1?&sxmt_dxf_int8:kind==2?&sxmt_dxf_int16:kind==4?&sxmt_dxf_int32:kind==9?&sxmt_dxf_int64:&sxmt_dxf_double;unsigned w=kind==9?8:kind;if(!sxmt_emit(q,l,q->p,w))return false;q->p+=w;}}
 return true;}

typedef struct sxmt_property {unsigned kind,width,list_width;} sxmt_property;
typedef struct sxmt_element {uint64_t count;unsigned fields;sxmt_property props[64];} sxmt_element;
static bool sxmt_ply_type(sxmt_cursor*q,int64_t a,int64_t z,sxmt_property*p){
 static const char*names[]={"char","int8","uchar","uint8","short","int16","ushort","uint16","int","int32","uint","uint32","float","float32","double","float64"};
 for(unsigned i=0;i<SX_COUNT(names);i++)if(sxmt_eq(q,a,z,names[i])){p->kind=i<4?(i<2?'I':'U'):i<8?(i<6?'I':'U'):i<12?(i<10?'I':'U'):'F';p->width=i<4?1:i<8?2:i<14?4:8;return true;}return false;}
static bool sxmt_ply(sxmt_cursor*q){sxmt_element*es=xx_mem_alloc(sizeof(*es)*32);if(!es)return false;xx_rt_memset(es,0,sizeof(*es)*32);bool ok=false,be=false,ended=false;unsigned ne=0;int64_t a,e,z,k;
 if(!sxmt_line(q,&a,&e,false)||!sxmt_emit(q,&sxmt_signature,a,e-a)||!sxmt_line(q,&a,&e,false))goto done;int64_t next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false)||!sxmt_value(q,&sxmt_encoding,e,NULL)||!sxmt_value(q,&sxmt_version,e,NULL))goto done;be=e-a>=24&&!xx_rt_memcmp(q->b+a,"format binary_big_endian",23);q->p=next;
 while(sxmt_line(q,&a,&e,false)){if(q->p>65536)goto done;next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false))goto done;
  if(sxmt_eq(q,k,z,"end_header")){q->p=next;ended=true;break;}
  if(sxmt_eq(q,k,z,"comment")||sxmt_eq(q,k,z,"obj_info")){q->p=next;continue;}
  if(sxmt_eq(q,k,z,"element")){if(ne==32||!sxmt_value(q,&sxmt_element_name,e,NULL)||!sxmt_value(q,&sxmt_element_count,e,&es[ne].count)||es[ne].count>1000000)goto done;ne++;}
  else if(sxmt_eq(q,k,z,"property")){if(!ne||es[ne-1].fields==64||!sxmt_token(q,e,&a,&z,false))goto done;sxmt_property*prop=&es[ne-1].props[es[ne-1].fields++];if(sxmt_eq(q,a,z,"list")){sxmt_property cp={0};if(!sxmt_token(q,e,&a,&z,false)||!sxmt_ply_type(q,a,z,&cp)||cp.kind!='U'||!sxmt_emit(q,&sxmt_count_type,a,z))goto done;prop->list_width=cp.width;if(!sxmt_token(q,e,&a,&z,false))goto done;}if(!sxmt_ply_type(q,a,z,prop)||!sxmt_emit(q,&sxmt_property_type,a,z)||!sxmt_value(q,&sxmt_property_name,e,NULL))goto done;}
  else goto done;q->p=next;
 }if(!ended||!ne)goto done;
 for(unsigned el=0;el<ne;el++)for(uint64_t row=0;row<es[el].count;row++)for(unsigned f=0;f<es[el].fields;f++){if(q->c->count>=32000){ok=true;goto done;}sxmt_property*p=&es[el].props[f];uint64_t count=1;const sx_layout*l=sxmt_binary_type(p->kind,p->width,be);if(!l)goto done;
  if(p->list_width){unsigned w=p->list_width;if(w>(uint64_t)(q->n-q->p))goto done;count=w==1?q->b[q->p]:w==2?xx_data_get_u16(q->b+q->p,2,0,be):xx_data_get_u32(q->b+q->p,4,0,be);if(count>65536)goto done;const sx_layout*cl=w==1?(be?&sxmt_list_uint8_be:&sxmt_list_uint8_le):w==2?(be?&sxmt_list_uint16_be:&sxmt_list_uint16_le):(be?&sxmt_list_uint32_be:&sxmt_list_uint32_le);if(!sxmt_emit(q,cl,q->p,w))goto done;q->p+=w;}
  if(!sxmt_table(q,l,q->p,p->width,count))goto done;q->p+=(int64_t)(count*p->width);
 }ok=true;
done:xx_mem_free(es);return ok;}
static bool sxmt_pcd(sxmt_cursor*q){uint64_t sizes[64]={0},counts[64],points=0;unsigned kinds[64]={0},nf=0;int64_t a,e,z,k;bool ended=false;for(unsigned i=0;i<64;i++)counts[i]=1;
 while(sxmt_line(q,&a,&e,true)){if(q->p>65536)return false;int64_t next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false))return false;
  const sx_layout*l=NULL;uint64_t*out=NULL;
  if(sxmt_eq(q,k,z,"VERSION"))l=&sxmt_version;
  else if(sxmt_eq(q,k,z,"WIDTH"))l=&sxmt_width;
  else if(sxmt_eq(q,k,z,"HEIGHT"))l=&sxmt_height;
  else if(sxmt_eq(q,k,z,"POINTS")){l=&sxmt_point_count;out=&points;}
  else if(sxmt_eq(q,k,z,"DATA")){if(!sxmt_value(q,&sxmt_encoding,e,NULL))return false;q->p=next;ended=true;break;}
  else if(sxmt_eq(q,k,z,"VIEWPOINT")){const sx_layout*ls[]={&sxmt_translate_x,&sxmt_translate_y,&sxmt_translate_z,&sxmt_quaternion_w,&sxmt_quaternion_x,&sxmt_quaternion_y,&sxmt_quaternion_z};for(unsigned i=0;i<7;i++)if(!sxmt_value(q,ls[i],e,NULL))return false;}
  else {unsigned index=0;bool fields=sxmt_eq(q,k,z,"FIELDS"),sz=sxmt_eq(q,k,z,"SIZE"),ty=sxmt_eq(q,k,z,"TYPE"),co=sxmt_eq(q,k,z,"COUNT");if(!fields&&!sz&&!ty&&!co)return false;
   while(sxmt_token(q,e,&a,&z,true)){if(index>=64)return false;if(fields){if(!sxmt_emit(q,&sxmt_property_name,a,z))return false;nf++;}else if(ty){if(z!=1||!sxmt_emit(q,&sxmt_field_type,a,z))return false;kinds[index]=q->b[a];}else {uint64_t n;if(!sxmt_uint_token(q,a,z,&n)||!sxmt_emit(q,sz?&sxmt_data_bytes:&sxmt_sample_count,a,z))return false;if(sz)sizes[index]=n;else counts[index]=n;}index++;}if(!fields&&index!=nf)return false;
  }if(l&&!sxmt_value(q,l,e,out))return false;q->p=next;
 }if(!ended||!nf||!points||points>1000000)return false;
 for(uint64_t i=0;i<points;i++)for(unsigned j=0;j<nf;j++){if(q->c->count>=32000)return true;if(sizes[j]>8||!counts[j]||counts[j]>65536)return false;const sx_layout*l=sxmt_binary_type(kinds[j],(unsigned)sizes[j],false);if(!l||!sxmt_table(q,l,q->p,(int64_t)sizes[j],counts[j]))return false;q->p+=(int64_t)(sizes[j]*counts[j]);}return true;}

static bool sxmt_remainder(sxmt_cursor*q,const sx_layout*l,int64_t end){while(q->p<end&&sxmt_space(q->b[q->p]))q->p++;return sxmt_emit(q,l,q->p,end-q->p);}
static bool sxmt_bdf(sxmt_cursor*q){int64_t a,e,k,z;bool bitmap=false,properties=false;while(sxmt_line(q,&a,&e,false)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false))return false;
 if(sxmt_eq(q,k,z,"COMMENT")){q->p=next;continue;}
 if(bitmap&&!sxmt_eq(q,k,z,"ENDCHAR")){if((e-a)%2)return false;for(int64_t i=a;i<e;i+=2)MT_EMIT(bitmap_byte,i,2);q->p=next;continue;}
 MT_EMIT(keyword,k,z);
 if(sxmt_eq(q,k,z,"ENDCHAR"))bitmap=false;else if(sxmt_eq(q,k,z,"BITMAP"))bitmap=true;else if(sxmt_eq(q,k,z,"ENDPROPERTIES"))properties=false;
 else if(sxmt_eq(q,k,z,"STARTFONT")){MT_VALUE(version,e,NULL);}
 else if(sxmt_eq(q,k,z,"FONT")){if(!sxmt_remainder(q,&sxmt_font_name,e))return false;}
 else if(sxmt_eq(q,k,z,"STARTCHAR")){if(!sxmt_remainder(q,&sxmt_glyph_name,e))return false;}
 else if(sxmt_eq(q,k,z,"SIZE")){MT_VALUE(font_size,e,NULL);MT_VALUE(resolution_x,e,NULL);MT_VALUE(resolution_y,e,NULL);}
 else if(sxmt_eq(q,k,z,"FONTBOUNDINGBOX")||sxmt_eq(q,k,z,"BBX")){MT_VALUE(bbox_width,e,NULL);MT_VALUE(bbox_height,e,NULL);MT_VALUE(bbox_x,e,NULL);MT_VALUE(bbox_y,e,NULL);}
 else if(sxmt_eq(q,k,z,"SWIDTH")){MT_VALUE(swidth_x,e,NULL);MT_VALUE(swidth_y,e,NULL);}
 else if(sxmt_eq(q,k,z,"DWIDTH")){MT_VALUE(dwidth_x,e,NULL);MT_VALUE(dwidth_y,e,NULL);}
 else if(sxmt_eq(q,k,z,"STARTPROPERTIES")){MT_VALUE(property_total,e,NULL);properties=true;}
 else if(sxmt_eq(q,k,z,"CHARS")){MT_VALUE(glyph_count,e,NULL);}
 else if(sxmt_eq(q,k,z,"ENCODING")){MT_VALUE(codepoint,e,NULL);}
 else if(sxmt_eq(q,k,z,"ATTRIBUTES")){MT_VALUE(glyph_attributes,e,NULL);}
 else if(properties){while(q->p<e&&sxmt_space(q->b[q->p]))q->p++;if(!sxmt_remainder(q,q->p<e&&q->b[q->p]=='"'?&sxmt_string_value:&sxmt_integer_value,e))return false;}
 q->p=next;}return !bitmap;}
static bool sxmt_sfd(sxmt_cursor*q){int64_t a,e,k,z;bool glyph=false,curve=false;while(sxmt_line(q,&a,&e,false)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false))return false;bool numeric=(q->b[k]>='0'&&q->b[k]<='9')||q->b[k]=='-'||q->b[k]=='+'||q->b[k]=='.';
 if(curve&&numeric){q->p=a;unsigned i=0;while(sxmt_token(q,e,&a,&z,false)){bool command=z==1&&(q->b[a]=='m'||q->b[a]=='l'||q->b[a]=='c');if(command){MT_EMIT(keyword,a,z);MT_VALUE(curve_flags,e,NULL);break;}if(i++>=6||!sxmt_emit(q,(i%2)?&sxmt_x:&sxmt_y,a,z))return false;}}
 else{MT_EMIT(keyword,k,z);
#define MT_SFDKEY(s) (sxmt_eq(q,k,z,s ":"))
 if(MT_SFDKEY("StartChar")){glyph=true;if(!sxmt_remainder(q,&sxmt_glyph_name,e))return false;}
 else if(sxmt_eq(q,k,z,"EndChar")){glyph=false;curve=false;}else if(sxmt_eq(q,k,z,"Fore"))curve=true;else if(sxmt_eq(q,k,z,"EndSplineSet"))curve=false;
 else if(MT_SFDKEY("BeginChars")){MT_VALUE(property_total,e,NULL);MT_VALUE(glyph_count,e,NULL);}
 else if(glyph&&MT_SFDKEY("Encoding")){MT_VALUE(glyph_index,e,NULL);MT_VALUE(codepoint,e,NULL);}
 else if(MT_SFDKEY("SplineFontDB")){MT_VALUE(version,e,NULL);}
 else if(MT_SFDKEY("Ascent")||MT_SFDKEY("Descent")||MT_SFDKEY("DisplaySize")||MT_SFDKEY("Width")||MT_SFDKEY("VWidth")||MT_SFDKEY("NeedsXUIDChange")||MT_SFDKEY("AntiAlias")){MT_VALUE(integer_value,e,NULL);}
 else if(MT_SFDKEY("ItalicAngle")||MT_SFDKEY("UnderlinePosition")||MT_SFDKEY("UnderlineWidth")){MT_VALUE(font_metric,e,NULL);}
 else if(!sxmt_remainder(q,&sxmt_string_value,e))return false;
#undef MT_SFDKEY
 }q->p=next;}return true;}
static bool sxmt_afm(sxmt_cursor*q){int64_t a,e;while(sxmt_line(q,&a,&e,false)){if(q->c->count>=32000)return true;int64_t next=q->p;for(int64_t start=a;start<e;){int64_t stop=start;while(stop<e&&q->b[stop]!=';')stop++;q->p=start;int64_t k,z;if(!sxmt_token(q,stop,&k,&z,false)){start=stop+1;continue;}MT_EMIT(keyword,k,z);const sx_layout*l=&sxmt_string_value;
 if(sxmt_eq(q,k,z,"Comment")){/* comments can contain semicolons */if(!sxmt_remainder(q,l,e))return false;break;}
 if(sxmt_eq(q,k,z,"StartFontMetrics"))l=&sxmt_version;
 else if(sxmt_eq(q,k,z,"C"))l=&sxmt_codepoint;
 else if(sxmt_eq(q,k,z,"CH")){while(q->p<stop&&sxmt_space(q->b[q->p]))q->p++;if(q->p<stop&&q->b[q->p]=='<'){int64_t n=++q->p;while(q->p<stop&&q->b[q->p]!='>')q->p++;MT_EMIT(character_code_hex,n,q->p-n);}start=stop+1;continue;}
 else if(sxmt_eq(q,k,z,"N"))l=&sxmt_glyph_name;
 else if(sxmt_eq(q,k,z,"StartCharMetrics")||sxmt_eq(q,k,z,"StartKernPairs")||sxmt_eq(q,k,z,"StartKernPairs0")||sxmt_eq(q,k,z,"StartKernPairs1")||sxmt_eq(q,k,z,"StartTrackKern")||sxmt_eq(q,k,z,"StartComposites")||sxmt_eq(q,k,z,"StartDirection"))l=&sxmt_integer_value;
 else if(sxmt_eq(q,k,z,"WX")||sxmt_eq(q,k,z,"WY")||sxmt_eq(q,k,z,"W0X")||sxmt_eq(q,k,z,"W0Y")||sxmt_eq(q,k,z,"W1X")||sxmt_eq(q,k,z,"W1Y")||sxmt_eq(q,k,z,"W")||sxmt_eq(q,k,z,"W0")||sxmt_eq(q,k,z,"W1")||sxmt_eq(q,k,z,"B")||sxmt_eq(q,k,z,"VV")||sxmt_eq(q,k,z,"FontBBox")||sxmt_eq(q,k,z,"UnderlinePosition")||sxmt_eq(q,k,z,"UnderlineThickness")||sxmt_eq(q,k,z,"ItalicAngle")||sxmt_eq(q,k,z,"CapHeight")||sxmt_eq(q,k,z,"XHeight")||sxmt_eq(q,k,z,"Ascender")||sxmt_eq(q,k,z,"Descender")||sxmt_eq(q,k,z,"StdHW")||sxmt_eq(q,k,z,"StdVW")||sxmt_eq(q,k,z,"CharWidth"))l=&sxmt_font_metric;
 else if(sxmt_eq(q,k,z,"KPX")||sxmt_eq(q,k,z,"KPY")||sxmt_eq(q,k,z,"KP")){MT_VALUE(glyph_name,stop,NULL);MT_VALUE(glyph_name,stop,NULL);l=&sxmt_font_metric;}
 else if(sxmt_eq(q,k,z,"TrackKern")){MT_VALUE(integer_value,stop,NULL);l=&sxmt_font_metric;}
 else if(sxmt_eq(q,k,z,"CC")){MT_VALUE(glyph_name,stop,NULL);l=&sxmt_property_total;}
 else if(sxmt_eq(q,k,z,"PCC")){MT_VALUE(glyph_name,stop,NULL);l=&sxmt_font_metric;}
 if(l==&sxmt_string_value){if(!sxmt_remainder(q,l,stop))return false;}else if(!sxmt_many(q,l,stop))return false;start=stop+1;}q->p=next;}return true;}

static bool sxmt_quoted(sxmt_cursor*q,const sx_layout*l,int64_t end){while(q->p<end&&sxmt_space(q->b[q->p]))q->p++;if(q->p==end||q->b[q->p]!='"')return false;int64_t start=++q->p;while(q->p<end&&q->b[q->p]!='"'){if(q->b[q->p]=='\\'&&q->p+1<end)q->p++;q->p++;}if(q->p==end)return false;bool ok=sxmt_emit(q,l,start,q->p-start);q->p++;return ok;}
static bool sxmt_ac(sxmt_cursor*q){int64_t a,e;uint64_t vertices=0,refs=0;while(sxmt_line(q,&a,&e,true)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;
 if(vertices){MT_VALUE(x,e,NULL);MT_VALUE(y,e,NULL);MT_VALUE(z,e,NULL);vertices--;}
 else if(refs){MT_VALUE(vertex_index,e,NULL);MT_VALUE(u,e,NULL);MT_VALUE(v,e,NULL);refs--;}
 else {int64_t k,z;if(!sxmt_token(q,e,&k,&z,false))return false;MT_EMIT(keyword,k,z);
 if(sxmt_eq(q,k,z,"AC3Db")){}
 else if(sxmt_eq(q,k,z,"OBJECT")){MT_VALUE(object_type,e,NULL);}
 else if(sxmt_eq(q,k,z,"name")||sxmt_eq(q,k,z,"texture")||sxmt_eq(q,k,z,"url")){if(!sxmt_quoted(q,&sxmt_name,e))return false;}
 else if(sxmt_eq(q,k,z,"numvert")){MT_VALUE(vertex_count,e,&vertices);if(vertices>1000000)return false;}
 else if(sxmt_eq(q,k,z,"refs")){MT_VALUE(reference_count,e,&refs);if(refs>256)return false;}
 else if(sxmt_eq(q,k,z,"numsurf")){MT_VALUE(surface_count,e,NULL);}
 else if(sxmt_eq(q,k,z,"kids")){MT_VALUE(child_count,e,NULL);}
 else if(sxmt_eq(q,k,z,"mat")){MT_VALUE(material_index,e,NULL);}
 else if(sxmt_eq(q,k,z,"SURF")){if(!sxmt_token(q,e,&a,&z,false)||z<3||q->b[a]!='0'||q->b[a+1]!='x')return false;MT_EMIT(surface_flags,a+2,z-2);}
 else if(sxmt_eq(q,k,z,"loc")){MT_VALUE(translate_x,e,NULL);MT_VALUE(translate_y,e,NULL);MT_VALUE(translate_z,e,NULL);}
 else if(sxmt_eq(q,k,z,"rot")){if(!sxmt_many(q,&sxmt_rotation_value,e))return false;}
 else if(sxmt_eq(q,k,z,"texrep")||sxmt_eq(q,k,z,"texoff")){MT_VALUE(u,e,NULL);MT_VALUE(v,e,NULL);}
 else if(sxmt_eq(q,k,z,"MATERIAL")){if(!sxmt_quoted(q,&sxmt_material_name,e))return false;const sx_layout*ls[]={&sxmt_red,&sxmt_green,&sxmt_blue,&sxmt_ambient_red,&sxmt_ambient_green,&sxmt_ambient_blue,&sxmt_emission_red,&sxmt_emission_green,&sxmt_emission_blue,&sxmt_specular_red,&sxmt_specular_green,&sxmt_specular_blue};for(unsigned i=0;i<4;i++){MT_VALUE(keyword,e,NULL);for(unsigned j=0;j<3;j++)if(!sxmt_value(q,ls[i*3+j],e,NULL))return false;}MT_VALUE(keyword,e,NULL);MT_VALUE(shininess,e,NULL);MT_VALUE(keyword,e,NULL);MT_VALUE(transparency,e,NULL);}
 else return false;}
 q->p=next;}return true;}
/* Used only for native-validated lexical scene grammars. Values remain physical
 * tokens. Integer/real describes spelling, not a reconstructed object field. */
static bool sxmt_lex(sxmt_cursor*q,xx_file_type_t type){bool motion=false;unsigned expect=0;const sx_layout*requested=NULL;bool bang=type==XX_FILE_TYPE_BVH_MOTION||type==XX_FILE_TYPE_DIRECTX_X;
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
 if(ok)switch(type){case XX_FILE_TYPE_POLYGON_PLY:ok=sxmt_ply(q);break;case XX_FILE_TYPE_POINTCLOUD_PCD:ok=sxmt_pcd(q);break;case XX_FILE_TYPE_WAVEFRONT_OBJ:ok=sxmt_obj(q);break;case XX_FILE_TYPE_OFF_MESH:ok=sxmt_off(q);break;case XX_FILE_TYPE_AC3D_MODEL:ok=sxmt_ac(q);break;case XX_FILE_TYPE_XFIG:ok=sxmt_fig(q);break;case XX_FILE_TYPE_AUTOCAD_DXF:ok=sxmt_dxf(q);break;case XX_FILE_TYPE_FONT_BDF:ok=sxmt_bdf(q);break;case XX_FILE_TYPE_FONT_AFM:ok=sxmt_afm(q);break;case XX_FILE_TYPE_FONTFORGE_SFD:ok=sxmt_sfd(q);break;case XX_FILE_TYPE_GTS_SURFACE:ok=sxmt_gts(q);break;case XX_FILE_TYPE_BVH_MOTION:ok=sxmt_lex(q,type);break;case XX_FILE_TYPE_DIRECTX_X:ok=sxmt_lex(q,type);break;case XX_FILE_TYPE_LIGHTWAVE_SCENE:ok=sxmt_lex(q,type);break;case XX_FILE_TYPE_METASEQUOIA_MQO:ok=sxmt_lex(q,type);break;case XX_FILE_TYPE_AUTODESK_ASE:ok=sxmt_lex(q,type);break;default:ok=false;break;}
 xx_mem_free(b);return ok&&sxmt_finish(c);}
#undef MT_VALUE
#undef MT_EMIT
