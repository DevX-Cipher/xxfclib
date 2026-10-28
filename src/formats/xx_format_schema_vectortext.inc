/* SPDX-License-Identifier: MIT. Original physical vector/XML/fixed-column metadata. */
static const xx_data_struct_field_desc sxvtx_signature_fields[]={
 SX_FIELD("signature","char",0,0,SX_SIGNATURE),
};
static const sx_layout sxvtx_signature={0x60620001U,"vectortext_signature",sxvtx_signature_fields,SX_COUNT(sxvtx_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_version_fields[]={
 SX_FIELD("version","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_version={0x60620002U,"vectortext_version",sxvtx_version_fields,SX_COUNT(sxvtx_version_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_keyword_fields[]={
 SX_FIELD("keyword","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_keyword={0x60620003U,"vectortext_keyword",sxvtx_keyword_fields,SX_COUNT(sxvtx_keyword_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_name_fields[]={
 SX_FIELD("name","utf8",0,0,SX_STRING),
};
static const sx_layout sxvtx_name={0x60620004U,"vectortext_name",sxvtx_name_fields,SX_COUNT(sxvtx_name_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_string_value_fields[]={
 SX_FIELD("string_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxvtx_string_value={0x60620005U,"vectortext_string_value",sxvtx_string_value_fields,SX_COUNT(sxvtx_string_value_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_record_text_fields[]={
 SX_FIELD("record_text","utf8",0,0,SX_STRING),
};
static const sx_layout sxvtx_record_text={0x60620006U,"vectortext_record_text",sxvtx_record_text_fields,SX_COUNT(sxvtx_record_text_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_xml_element_fields[]={
 SX_FIELD("xml_element","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_xml_element={0x60620007U,"vectortext_xml_element",sxvtx_xml_element_fields,SX_COUNT(sxvtx_xml_element_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_xml_attribute_fields[]={
 SX_FIELD("xml_attribute","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_xml_attribute={0x60620008U,"vectortext_xml_attribute",sxvtx_xml_attribute_fields,SX_COUNT(sxvtx_xml_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_encoding_fields[]={
 SX_FIELD("encoding","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_encoding={0x60620009U,"vectortext_encoding",sxvtx_encoding_fields,SX_COUNT(sxvtx_encoding_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_class_name_fields[]={
 SX_FIELD("class_name","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_class_name={0x6062000aU,"vectortext_class_name",sxvtx_class_name_fields,SX_COUNT(sxvtx_class_name_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_units_fields[]={
 SX_FIELD("units","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_units={0x6062000bU,"vectortext_units",sxvtx_units_fields,SX_COUNT(sxvtx_units_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_organization_fields[]={
 SX_FIELD("organization","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_organization={0x6062000cU,"vectortext_organization",sxvtx_organization_fields,SX_COUNT(sxvtx_organization_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_pixel_format_fields[]={
 SX_FIELD("pixel_format","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_pixel_format={0x6062000dU,"vectortext_pixel_format",sxvtx_pixel_format_fields,SX_COUNT(sxvtx_pixel_format_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_pixel_byte_order_fields[]={
 SX_FIELD("pixel_byte_order","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_pixel_byte_order={0x6062000eU,"vectortext_pixel_byte_order",sxvtx_pixel_byte_order_fields,SX_COUNT(sxvtx_pixel_byte_order_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_pixel_real_format_fields[]={
 SX_FIELD("pixel_real_format","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_pixel_real_format={0x6062000fU,"vectortext_pixel_real_format",sxvtx_pixel_real_format_fields,SX_COUNT(sxvtx_pixel_real_format_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_reference_name_fields[]={
 SX_FIELD("reference_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxvtx_reference_name={0x60620010U,"vectortext_reference_name",sxvtx_reference_name_fields,SX_COUNT(sxvtx_reference_name_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_width_fields[]={
 SX_FIELD("width","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_width={0x60620011U,"vectortext_width",sxvtx_width_fields,SX_COUNT(sxvtx_width_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_height_fields[]={
 SX_FIELD("height","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_height={0x60620012U,"vectortext_height",sxvtx_height_fields,SX_COUNT(sxvtx_height_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_depth_fields[]={
 SX_FIELD("depth","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_depth={0x60620013U,"vectortext_depth",sxvtx_depth_fields,SX_COUNT(sxvtx_depth_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_channels_fields[]={
 SX_FIELD("channels","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_channels={0x60620014U,"vectortext_channels",sxvtx_channels_fields,SX_COUNT(sxvtx_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_color_count_fields[]={
 SX_FIELD("color_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_color_count={0x60620015U,"vectortext_color_count",sxvtx_color_count_fields,SX_COUNT(sxvtx_color_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_map_width_fields[]={
 SX_FIELD("map_width","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_map_width={0x60620016U,"vectortext_map_width",sxvtx_map_width_fields,SX_COUNT(sxvtx_map_width_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_map_height_fields[]={
 SX_FIELD("map_height","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_map_height={0x60620017U,"vectortext_map_height",sxvtx_map_height_fields,SX_COUNT(sxvtx_map_height_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_tile_width_fields[]={
 SX_FIELD("tile_width","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_tile_width={0x60620018U,"vectortext_tile_width",sxvtx_tile_width_fields,SX_COUNT(sxvtx_tile_width_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_tile_height_fields[]={
 SX_FIELD("tile_height","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_tile_height={0x60620019U,"vectortext_tile_height",sxvtx_tile_height_fields,SX_COUNT(sxvtx_tile_height_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_tile_count_fields[]={
 SX_FIELD("tile_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_tile_count={0x6062001aU,"vectortext_tile_count",sxvtx_tile_count_fields,SX_COUNT(sxvtx_tile_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_first_gid_fields[]={
 SX_FIELD("first_gid","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_first_gid={0x6062001bU,"vectortext_first_gid",sxvtx_first_gid_fields,SX_COUNT(sxvtx_first_gid_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_global_tile_id_fields[]={
 SX_FIELD("global_tile_id","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_global_tile_id={0x6062001cU,"vectortext_global_tile_id",sxvtx_global_tile_id_fields,SX_COUNT(sxvtx_global_tile_id_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_layer_id_fields[]={
 SX_FIELD("layer_id","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_layer_id={0x6062001dU,"vectortext_layer_id",sxvtx_layer_id_fields,SX_COUNT(sxvtx_layer_id_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_index_value_fields[]={
 SX_FIELD("index_value","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_index_value={0x6062001eU,"vectortext_index_value",sxvtx_index_value_fields,SX_COUNT(sxvtx_index_value_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_input_offset_fields[]={
 SX_FIELD("input_offset","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_input_offset={0x6062001fU,"vectortext_input_offset",sxvtx_input_offset_fields,SX_COUNT(sxvtx_input_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_input_stride_fields[]={
 SX_FIELD("input_stride","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_input_stride={0x60620020U,"vectortext_input_stride",sxvtx_input_stride_fields,SX_COUNT(sxvtx_input_stride_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dimension_fields[]={
 SX_FIELD("dimension","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_dimension={0x60620021U,"vectortext_dimension",sxvtx_dimension_fields,SX_COUNT(sxvtx_dimension_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_line_count_fields[]={
 SX_FIELD("line_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_line_count={0x60620022U,"vectortext_line_count",sxvtx_line_count_fields,SX_COUNT(sxvtx_line_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_sample_count_fields[]={
 SX_FIELD("sample_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_sample_count={0x60620023U,"vectortext_sample_count",sxvtx_sample_count_fields,SX_COUNT(sxvtx_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_band_count_fields[]={
 SX_FIELD("band_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_band_count={0x60620024U,"vectortext_band_count",sxvtx_band_count_fields,SX_COUNT(sxvtx_band_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_n1_fields[]={
 SX_FIELD("n1","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_n1={0x60620025U,"vectortext_n1",sxvtx_n1_fields,SX_COUNT(sxvtx_n1_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_n2_fields[]={
 SX_FIELD("n2","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_n2={0x60620026U,"vectortext_n2",sxvtx_n2_fields,SX_COUNT(sxvtx_n2_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_n3_fields[]={
 SX_FIELD("n3","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_n3={0x60620027U,"vectortext_n3",sxvtx_n3_fields,SX_COUNT(sxvtx_n3_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_n4_fields[]={
 SX_FIELD("n4","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_n4={0x60620028U,"vectortext_n4",sxvtx_n4_fields,SX_COUNT(sxvtx_n4_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_binary_prefix_bytes_fields[]={
 SX_FIELD("binary_prefix_bytes","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxvtx_binary_prefix_bytes={0x60620029U,"vectortext_binary_prefix_bytes",sxvtx_binary_prefix_bytes_fields,SX_COUNT(sxvtx_binary_prefix_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_binary_header_records_fields[]={
 SX_FIELD("binary_header_records","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_binary_header_records={0x6062002aU,"vectortext_binary_header_records",sxvtx_binary_header_records_fields,SX_COUNT(sxvtx_binary_header_records_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_record_bytes_fields[]={
 SX_FIELD("record_bytes","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxvtx_record_bytes={0x6062002bU,"vectortext_record_bytes",sxvtx_record_bytes_fields,SX_COUNT(sxvtx_record_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_label_bytes_fields[]={
 SX_FIELD("label_bytes","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxvtx_label_bytes={0x6062002cU,"vectortext_label_bytes",sxvtx_label_bytes_fields,SX_COUNT(sxvtx_label_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_buffer_bytes_fields[]={
 SX_FIELD("buffer_bytes","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxvtx_buffer_bytes={0x6062002dU,"vectortext_buffer_bytes",sxvtx_buffer_bytes_fields,SX_COUNT(sxvtx_buffer_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_format_version_fields[]={
 SX_FIELD("format_version","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_format_version={0x6062002eU,"vectortext_format_version",sxvtx_format_version_fields,SX_COUNT(sxvtx_format_version_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_fuse_count_fields[]={
 SX_FIELD("fuse_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_fuse_count={0x6062002fU,"vectortext_fuse_count",sxvtx_fuse_count_fields,SX_COUNT(sxvtx_fuse_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_pin_count_fields[]={
 SX_FIELD("pin_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_pin_count={0x60620030U,"vectortext_pin_count",sxvtx_pin_count_fields,SX_COUNT(sxvtx_pin_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_fuse_index_fields[]={
 SX_FIELD("fuse_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_fuse_index={0x60620031U,"vectortext_fuse_index",sxvtx_fuse_index_fields,SX_COUNT(sxvtx_fuse_index_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_default_fuse_fields[]={
 SX_FIELD("default_fuse","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_default_fuse={0x60620032U,"vectortext_default_fuse",sxvtx_default_fuse_fields,SX_COUNT(sxvtx_default_fuse_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_security_fuse_fields[]={
 SX_FIELD("security_fuse","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_security_fuse={0x60620033U,"vectortext_security_fuse",sxvtx_security_fuse_fields,SX_COUNT(sxvtx_security_fuse_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_entity_type_fields[]={
 SX_FIELD("entity_type","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_entity_type={0x60620034U,"vectortext_entity_type",sxvtx_entity_type_fields,SX_COUNT(sxvtx_entity_type_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_directory_reference_fields[]={
 SX_FIELD("directory_reference","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_directory_reference={0x60620035U,"vectortext_directory_reference",sxvtx_directory_reference_fields,SX_COUNT(sxvtx_directory_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_parameter_reference_fields[]={
 SX_FIELD("parameter_reference","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_parameter_reference={0x60620036U,"vectortext_parameter_reference",sxvtx_parameter_reference_fields,SX_COUNT(sxvtx_parameter_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_level_fields[]={
 SX_FIELD("level","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_level={0x60620037U,"vectortext_level",sxvtx_level_fields,SX_COUNT(sxvtx_level_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_line_font_pattern_fields[]={
 SX_FIELD("line_font_pattern","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_line_font_pattern={0x60620038U,"vectortext_line_font_pattern",sxvtx_line_font_pattern_fields,SX_COUNT(sxvtx_line_font_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_line_weight_fields[]={
 SX_FIELD("line_weight","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_line_weight={0x60620039U,"vectortext_line_weight",sxvtx_line_weight_fields,SX_COUNT(sxvtx_line_weight_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_color_number_fields[]={
 SX_FIELD("color_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_color_number={0x6062003aU,"vectortext_color_number",sxvtx_color_number_fields,SX_COUNT(sxvtx_color_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_form_number_fields[]={
 SX_FIELD("form_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_form_number={0x6062003bU,"vectortext_form_number",sxvtx_form_number_fields,SX_COUNT(sxvtx_form_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_profile_count_fields[]={
 SX_FIELD("profile_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_profile_count={0x6062003cU,"vectortext_profile_count",sxvtx_profile_count_fields,SX_COUNT(sxvtx_profile_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_row_count_fields[]={
 SX_FIELD("row_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_row_count={0x6062003dU,"vectortext_row_count",sxvtx_row_count_fields,SX_COUNT(sxvtx_row_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_column_number_fields[]={
 SX_FIELD("column_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_column_number={0x6062003eU,"vectortext_column_number",sxvtx_column_number_fields,SX_COUNT(sxvtx_column_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_elevation_sample_fields[]={
 SX_FIELD("elevation_sample","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_elevation_sample={0x6062003fU,"vectortext_elevation_sample",sxvtx_elevation_sample_fields,SX_COUNT(sxvtx_elevation_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_level_fields[]={
 SX_FIELD("dem_level","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_level={0x60620040U,"vectortext_dem_level",sxvtx_dem_level_fields,SX_COUNT(sxvtx_dem_level_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_elevation_pattern_fields[]={
 SX_FIELD("elevation_pattern","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_elevation_pattern={0x60620041U,"vectortext_elevation_pattern",sxvtx_elevation_pattern_fields,SX_COUNT(sxvtx_elevation_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_reference_system_fields[]={
 SX_FIELD("reference_system","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_reference_system={0x60620042U,"vectortext_reference_system",sxvtx_reference_system_fields,SX_COUNT(sxvtx_reference_system_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_zone_fields[]={
 SX_FIELD("zone","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_zone={0x60620043U,"vectortext_zone",sxvtx_zone_fields,SX_COUNT(sxvtx_zone_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_ground_unit_fields[]={
 SX_FIELD("ground_unit","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_ground_unit={0x60620044U,"vectortext_ground_unit",sxvtx_ground_unit_fields,SX_COUNT(sxvtx_ground_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_elevation_unit_fields[]={
 SX_FIELD("elevation_unit","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_elevation_unit={0x60620045U,"vectortext_elevation_unit",sxvtx_elevation_unit_fields,SX_COUNT(sxvtx_elevation_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_polygon_side_count_fields[]={
 SX_FIELD("polygon_side_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_polygon_side_count={0x60620046U,"vectortext_polygon_side_count",sxvtx_polygon_side_count_fields,SX_COUNT(sxvtx_polygon_side_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_accuracy_code_fields[]={
 SX_FIELD("accuracy_code","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_accuracy_code={0x60620047U,"vectortext_accuracy_code",sxvtx_accuracy_code_fields,SX_COUNT(sxvtx_accuracy_code_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_tool_number_fields[]={
 SX_FIELD("tool_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_tool_number={0x60620048U,"vectortext_tool_number",sxvtx_tool_number_fields,SX_COUNT(sxvtx_tool_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_aperture_number_fields[]={
 SX_FIELD("aperture_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_aperture_number={0x60620049U,"vectortext_aperture_number",sxvtx_aperture_number_fields,SX_COUNT(sxvtx_aperture_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_command_code_fields[]={
 SX_FIELD("command_code","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_command_code={0x6062004aU,"vectortext_command_code",sxvtx_command_code_fields,SX_COUNT(sxvtx_command_code_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_x_fields[]={
 SX_FIELD("x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_x={0x6062004bU,"vectortext_x",sxvtx_x_fields,SX_COUNT(sxvtx_x_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_y_fields[]={
 SX_FIELD("y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_y={0x6062004cU,"vectortext_y",sxvtx_y_fields,SX_COUNT(sxvtx_y_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_rotation_fields[]={
 SX_FIELD("rotation","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_rotation={0x6062004dU,"vectortext_rotation",sxvtx_rotation_fields,SX_COUNT(sxvtx_rotation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_line_width_fields[]={
 SX_FIELD("line_width","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_line_width={0x6062004eU,"vectortext_line_width",sxvtx_line_width_fields,SX_COUNT(sxvtx_line_width_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_real_value_fields[]={
 SX_FIELD("real_value","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_real_value={0x6062004fU,"vectortext_real_value",sxvtx_real_value_fields,SX_COUNT(sxvtx_real_value_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_coordinate_value_fields[]={
 SX_FIELD("coordinate_value","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_coordinate_value={0x60620050U,"vectortext_coordinate_value",sxvtx_coordinate_value_fields,SX_COUNT(sxvtx_coordinate_value_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_alpha_trait_fields[]={
 SX_FIELD("alpha_trait","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_alpha_trait={0x60620051U,"vectortext_alpha_trait",sxvtx_alpha_trait_fields,SX_COUNT(sxvtx_alpha_trait_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_color_space_fields[]={
 SX_FIELD("color_space","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_color_space={0x60620052U,"vectortext_color_space",sxvtx_color_space_fields,SX_COUNT(sxvtx_color_space_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_compression_fields[]={
 SX_FIELD("compression","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_compression={0x60620053U,"vectortext_compression",sxvtx_compression_fields,SX_COUNT(sxvtx_compression_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_page_geometry_fields[]={
 SX_FIELD("page_geometry","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_page_geometry={0x60620054U,"vectortext_page_geometry",sxvtx_page_geometry_fields,SX_COUNT(sxvtx_page_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_rendering_intent_fields[]={
 SX_FIELD("rendering_intent","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_rendering_intent={0x60620055U,"vectortext_rendering_intent",sxvtx_rendering_intent_fields,SX_COUNT(sxvtx_rendering_intent_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_channel_mask_fields[]={
 SX_FIELD("channel_mask","ascii_hex",0,0,SX_FLAGS),
};
static const sx_layout sxvtx_channel_mask={0x60620056U,"vectortext_channel_mask",sxvtx_channel_mask_fields,SX_COUNT(sxvtx_channel_mask_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_gamma_fields[]={
 SX_FIELD("gamma","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_gamma={0x60620057U,"vectortext_gamma",sxvtx_gamma_fields,SX_COUNT(sxvtx_gamma_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_red_primary_x_fields[]={
 SX_FIELD("red_primary_x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_red_primary_x={0x60620058U,"vectortext_red_primary_x",sxvtx_red_primary_x_fields,SX_COUNT(sxvtx_red_primary_x_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_red_primary_y_fields[]={
 SX_FIELD("red_primary_y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_red_primary_y={0x60620059U,"vectortext_red_primary_y",sxvtx_red_primary_y_fields,SX_COUNT(sxvtx_red_primary_y_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_green_primary_x_fields[]={
 SX_FIELD("green_primary_x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_green_primary_x={0x6062005aU,"vectortext_green_primary_x",sxvtx_green_primary_x_fields,SX_COUNT(sxvtx_green_primary_x_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_green_primary_y_fields[]={
 SX_FIELD("green_primary_y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_green_primary_y={0x6062005bU,"vectortext_green_primary_y",sxvtx_green_primary_y_fields,SX_COUNT(sxvtx_green_primary_y_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_blue_primary_x_fields[]={
 SX_FIELD("blue_primary_x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_blue_primary_x={0x6062005cU,"vectortext_blue_primary_x",sxvtx_blue_primary_x_fields,SX_COUNT(sxvtx_blue_primary_x_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_blue_primary_y_fields[]={
 SX_FIELD("blue_primary_y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_blue_primary_y={0x6062005dU,"vectortext_blue_primary_y",sxvtx_blue_primary_y_fields,SX_COUNT(sxvtx_blue_primary_y_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_white_point_x_fields[]={
 SX_FIELD("white_point_x","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_white_point_x={0x6062005eU,"vectortext_white_point_x",sxvtx_white_point_x_fields,SX_COUNT(sxvtx_white_point_x_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_white_point_y_fields[]={
 SX_FIELD("white_point_y","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_white_point_y={0x6062005fU,"vectortext_white_point_y",sxvtx_white_point_y_fields,SX_COUNT(sxvtx_white_point_y_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_element_count_fields[]={
 SX_FIELD("element_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_element_count={0x60620060U,"vectortext_element_count",sxvtx_element_count_fields,SX_COUNT(sxvtx_element_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_set_index_fields[]={
 SX_FIELD("set_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_set_index={0x60620061U,"vectortext_set_index",sxvtx_set_index_fields,SX_COUNT(sxvtx_set_index_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_visible_fields[]={
 SX_FIELD("visible","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_visible={0x60620062U,"vectortext_visible",sxvtx_visible_fields,SX_COUNT(sxvtx_visible_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_next_layer_id_fields[]={
 SX_FIELD("next_layer_id","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_next_layer_id={0x60620063U,"vectortext_next_layer_id",sxvtx_next_layer_id_fields,SX_COUNT(sxvtx_next_layer_id_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_next_object_id_fields[]={
 SX_FIELD("next_object_id","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_next_object_id={0x60620064U,"vectortext_next_object_id",sxvtx_next_object_id_fields,SX_COUNT(sxvtx_next_object_id_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_spacing_fields[]={
 SX_FIELD("spacing","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_spacing={0x60620065U,"vectortext_spacing",sxvtx_spacing_fields,SX_COUNT(sxvtx_spacing_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_margin_fields[]={
 SX_FIELD("margin","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_margin={0x60620066U,"vectortext_margin",sxvtx_margin_fields,SX_COUNT(sxvtx_margin_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_infinite_fields[]={
 SX_FIELD("infinite","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_infinite={0x60620067U,"vectortext_infinite",sxvtx_infinite_fields,SX_COUNT(sxvtx_infinite_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_format_minor_fields[]={
 SX_FIELD("format_minor","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_format_minor={0x60620068U,"vectortext_format_minor",sxvtx_format_minor_fields,SX_COUNT(sxvtx_format_minor_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_unit_meter_fields[]={
 SX_FIELD("unit_meter","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_unit_meter={0x60620069U,"vectortext_unit_meter",sxvtx_unit_meter_fields,SX_COUNT(sxvtx_unit_meter_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_opacity_fields[]={
 SX_FIELD("opacity","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_opacity={0x6062006aU,"vectortext_opacity",sxvtx_opacity_fields,SX_COUNT(sxvtx_opacity_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_advance_width_fields[]={
 SX_FIELD("advance_width","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_advance_width={0x6062006bU,"vectortext_advance_width",sxvtx_advance_width_fields,SX_COUNT(sxvtx_advance_width_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_advance_height_fields[]={
 SX_FIELD("advance_height","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_advance_height={0x6062006cU,"vectortext_advance_height",sxvtx_advance_height_fields,SX_COUNT(sxvtx_advance_height_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_x_scale_fields[]={
 SX_FIELD("x_scale","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_x_scale={0x6062006dU,"vectortext_x_scale",sxvtx_x_scale_fields,SX_COUNT(sxvtx_x_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_y_scale_fields[]={
 SX_FIELD("y_scale","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_y_scale={0x6062006eU,"vectortext_y_scale",sxvtx_y_scale_fields,SX_COUNT(sxvtx_y_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_xy_scale_fields[]={
 SX_FIELD("xy_scale","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_xy_scale={0x6062006fU,"vectortext_xy_scale",sxvtx_xy_scale_fields,SX_COUNT(sxvtx_xy_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_yx_scale_fields[]={
 SX_FIELD("yx_scale","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_yx_scale={0x60620070U,"vectortext_yx_scale",sxvtx_yx_scale_fields,SX_COUNT(sxvtx_yx_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_integer_value_fields[]={
 SX_FIELD("integer_value","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_integer_value={0x60620071U,"vectortext_integer_value",sxvtx_integer_value_fields,SX_COUNT(sxvtx_integer_value_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_entity_reference_fields[]={
 SX_FIELD("entity_reference","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_entity_reference={0x60620072U,"vectortext_entity_reference",sxvtx_entity_reference_fields,SX_COUNT(sxvtx_entity_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_encoded_x_fields[]={
 SX_FIELD("encoded_x","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_encoded_x={0x60620073U,"vectortext_encoded_x",sxvtx_encoded_x_fields,SX_COUNT(sxvtx_encoded_x_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_encoded_y_fields[]={
 SX_FIELD("encoded_y","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_encoded_y={0x60620074U,"vectortext_encoded_y",sxvtx_encoded_y_fields,SX_COUNT(sxvtx_encoded_y_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_radius_fields[]={
 SX_FIELD("radius","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_radius={0x60620075U,"vectortext_radius",sxvtx_radius_fields,SX_COUNT(sxvtx_radius_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_diameter_fields[]={
 SX_FIELD("diameter","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_diameter={0x60620076U,"vectortext_diameter",sxvtx_diameter_fields,SX_COUNT(sxvtx_diameter_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_pen_number_fields[]={
 SX_FIELD("pen_number","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_pen_number={0x60620077U,"vectortext_pen_number",sxvtx_pen_number_fields,SX_COUNT(sxvtx_pen_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_zero_suppression_fields[]={
 SX_FIELD("zero_suppression","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_zero_suppression={0x60620078U,"vectortext_zero_suppression",sxvtx_zero_suppression_fields,SX_COUNT(sxvtx_zero_suppression_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_label_terminator_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_NONE),
};
static const sx_layout sxvtx_label_terminator={0x60620079U,"vectortext_label_terminator",sxvtx_label_terminator_fields,SX_COUNT(sxvtx_label_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_x_integer_digits_fields[]={
 SX_FIELD("x_integer_digits","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_x_integer_digits={0x6062007aU,"vectortext_x_integer_digits",sxvtx_x_integer_digits_fields,SX_COUNT(sxvtx_x_integer_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_x_fraction_digits_fields[]={
 SX_FIELD("x_fraction_digits","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_x_fraction_digits={0x6062007bU,"vectortext_x_fraction_digits",sxvtx_x_fraction_digits_fields,SX_COUNT(sxvtx_x_fraction_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_y_integer_digits_fields[]={
 SX_FIELD("y_integer_digits","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_y_integer_digits={0x6062007cU,"vectortext_y_integer_digits",sxvtx_y_integer_digits_fields,SX_COUNT(sxvtx_y_integer_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_y_fraction_digits_fields[]={
 SX_FIELD("y_fraction_digits","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_y_fraction_digits={0x6062007dU,"vectortext_y_fraction_digits",sxvtx_y_fraction_digits_fields,SX_COUNT(sxvtx_y_fraction_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_vertex_count_fields[]={
 SX_FIELD("vertex_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_vertex_count={0x6062007eU,"vectortext_vertex_count",sxvtx_vertex_count_fields,SX_COUNT(sxvtx_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_d_code_fields[]={
 SX_FIELD("d_code","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_d_code={0x6062007fU,"vectortext_d_code",sxvtx_d_code_fields,SX_COUNT(sxvtx_d_code_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_aperture_width_fields[]={
 SX_FIELD("aperture_width","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_aperture_width={0x60620080U,"vectortext_aperture_width",sxvtx_aperture_width_fields,SX_COUNT(sxvtx_aperture_width_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_aperture_height_fields[]={
 SX_FIELD("aperture_height","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_aperture_height={0x60620081U,"vectortext_aperture_height",sxvtx_aperture_height_fields,SX_COUNT(sxvtx_aperture_height_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_hole_diameter_fields[]={
 SX_FIELD("hole_diameter","ascii_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_hole_diameter={0x60620082U,"vectortext_hole_diameter",sxvtx_hole_diameter_fields,SX_COUNT(sxvtx_hole_diameter_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_coordinate_notation_fields[]={
 SX_FIELD("coordinate_notation","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_coordinate_notation={0x60620083U,"vectortext_coordinate_notation",sxvtx_coordinate_notation_fields,SX_COUNT(sxvtx_coordinate_notation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_polarity_fields[]={
 SX_FIELD("polarity","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_polarity={0x60620084U,"vectortext_polarity",sxvtx_polarity_fields,SX_COUNT(sxvtx_polarity_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_aperture_shape_fields[]={
 SX_FIELD("aperture_shape","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_aperture_shape={0x60620085U,"vectortext_aperture_shape",sxvtx_aperture_shape_fields,SX_COUNT(sxvtx_aperture_shape_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_row_number_fields[]={
 SX_FIELD("row_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_row_number={0x60620086U,"vectortext_row_number",sxvtx_row_number_fields,SX_COUNT(sxvtx_row_number_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_column_count_fields[]={
 SX_FIELD("column_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_column_count={0x60620087U,"vectortext_column_count",sxvtx_column_count_fields,SX_COUNT(sxvtx_column_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_structure_reference_fields[]={
 SX_FIELD("structure_reference","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_structure_reference={0x60620088U,"vectortext_structure_reference",sxvtx_structure_reference_fields,SX_COUNT(sxvtx_structure_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_view_reference_fields[]={
 SX_FIELD("view_reference","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_view_reference={0x60620089U,"vectortext_view_reference",sxvtx_view_reference_fields,SX_COUNT(sxvtx_view_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_transform_reference_fields[]={
 SX_FIELD("transform_reference","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_transform_reference={0x6062008aU,"vectortext_transform_reference",sxvtx_transform_reference_fields,SX_COUNT(sxvtx_transform_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_label_display_reference_fields[]={
 SX_FIELD("label_display_reference","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_label_display_reference={0x6062008bU,"vectortext_label_display_reference",sxvtx_label_display_reference_fields,SX_COUNT(sxvtx_label_display_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_parameter_line_count_fields[]={
 SX_FIELD("parameter_line_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_parameter_line_count={0x6062008cU,"vectortext_parameter_line_count",sxvtx_parameter_line_count_fields,SX_COUNT(sxvtx_parameter_line_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_entity_subscript_fields[]={
 SX_FIELD("entity_subscript","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_entity_subscript={0x6062008dU,"vectortext_entity_subscript",sxvtx_entity_subscript_fields,SX_COUNT(sxvtx_entity_subscript_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_section_record_count_fields[]={
 SX_FIELD("section_record_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_section_record_count={0x6062008eU,"vectortext_section_record_count",sxvtx_section_record_count_fields,SX_COUNT(sxvtx_section_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_eol_label_fields[]={
 SX_FIELD("eol_label","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_eol_label={0x6062008fU,"vectortext_eol_label",sxvtx_eol_label_fields,SX_COUNT(sxvtx_eol_label_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_quality_fields[]={
 SX_FIELD("quality","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxvtx_quality={0x60620090U,"vectortext_quality",sxvtx_quality_fields,SX_COUNT(sxvtx_quality_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_meta_channel_count_fields[]={
 SX_FIELD("meta_channel_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxvtx_meta_channel_count={0x60620091U,"vectortext_meta_channel_count",sxvtx_meta_channel_count_fields,SX_COUNT(sxvtx_meta_channel_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_x_fields[]={
 SX_FIELD("dem_x","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_x={0x60620092U,"vectortext_dem_x",sxvtx_dem_x_fields,SX_COUNT(sxvtx_dem_x_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_y_fields[]={
 SX_FIELD("dem_y","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_y={0x60620093U,"vectortext_dem_y",sxvtx_dem_y_fields,SX_COUNT(sxvtx_dem_y_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_coordinate_value_fields[]={
 SX_FIELD("dem_coordinate_value","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_coordinate_value={0x60620094U,"vectortext_dem_coordinate_value",sxvtx_dem_coordinate_value_fields,SX_COUNT(sxvtx_dem_coordinate_value_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_minimum_elevation_fields[]={
 SX_FIELD("dem_minimum_elevation","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_minimum_elevation={0x60620095U,"vectortext_dem_minimum_elevation",sxvtx_dem_minimum_elevation_fields,SX_COUNT(sxvtx_dem_minimum_elevation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_maximum_elevation_fields[]={
 SX_FIELD("dem_maximum_elevation","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_maximum_elevation={0x60620096U,"vectortext_dem_maximum_elevation",sxvtx_dem_maximum_elevation_fields,SX_COUNT(sxvtx_dem_maximum_elevation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_rotation_fields[]={
 SX_FIELD("dem_rotation","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_rotation={0x60620097U,"vectortext_dem_rotation",sxvtx_dem_rotation_fields,SX_COUNT(sxvtx_dem_rotation_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_x_resolution_fields[]={
 SX_FIELD("dem_x_resolution","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_x_resolution={0x60620098U,"vectortext_dem_x_resolution",sxvtx_dem_x_resolution_fields,SX_COUNT(sxvtx_dem_x_resolution_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_y_resolution_fields[]={
 SX_FIELD("dem_y_resolution","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_y_resolution={0x60620099U,"vectortext_dem_y_resolution",sxvtx_dem_y_resolution_fields,SX_COUNT(sxvtx_dem_y_resolution_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_z_resolution_fields[]={
 SX_FIELD("dem_z_resolution","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_z_resolution={0x6062009aU,"vectortext_dem_z_resolution",sxvtx_dem_z_resolution_fields,SX_COUNT(sxvtx_dem_z_resolution_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_elevation_datum_fields[]={
 SX_FIELD("dem_elevation_datum","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_elevation_datum={0x6062009bU,"vectortext_dem_elevation_datum",sxvtx_dem_elevation_datum_fields,SX_COUNT(sxvtx_dem_elevation_datum_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_dem_projection_parameter_fields[]={
 SX_FIELD("dem_projection_parameter","ascii_fortran_real",0,0,SX_NONE),
};
static const sx_layout sxvtx_dem_projection_parameter={0x6062009cU,"vectortext_dem_projection_parameter",sxvtx_dem_projection_parameter_fields,SX_COUNT(sxvtx_dem_projection_parameter_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_iges_status_fields[]={
 SX_FIELD("iges_status","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_iges_status={0x6062009dU,"vectortext_iges_status",sxvtx_iges_status_fields,SX_COUNT(sxvtx_iges_status_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_checksum_fields[]={
 SX_FIELD("checksum","ascii_hex",0,0,SX_CHECKSUM),
};
static const sx_layout sxvtx_checksum={0x6062009eU,"vectortext_checksum",sxvtx_checksum_fields,SX_COUNT(sxvtx_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_transmission_checksum_fields[]={
 SX_FIELD("transmission_checksum","ascii_hex",0,0,SX_CHECKSUM),
};
static const sx_layout sxvtx_transmission_checksum={0x6062009fU,"vectortext_transmission_checksum",sxvtx_transmission_checksum_fields,SX_COUNT(sxvtx_transmission_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_unicode_hex_fields[]={
 SX_FIELD("unicode_hex","ascii_hex",0,0,SX_ID),
};
static const sx_layout sxvtx_unicode_hex={0x606200a0U,"vectortext_unicode_hex",sxvtx_unicode_hex_fields,SX_COUNT(sxvtx_unicode_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_rgb_hex_fields[]={
 SX_FIELD("rgb_hex","ascii_hex",0,0,SX_ID),
};
static const sx_layout sxvtx_rgb_hex={0x606200a1U,"vectortext_rgb_hex",sxvtx_rgb_hex_fields,SX_COUNT(sxvtx_rgb_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_fuse_bits_fields[]={
 SX_FIELD("fuse_bits","char",0,0,SX_STRING),
};
static const sx_layout sxvtx_fuse_bits={0x606200a2U,"vectortext_fuse_bits",sxvtx_fuse_bits_fields,SX_COUNT(sxvtx_fuse_bits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_jedec_stx_fields[]={
 SX_FIELD("start_of_text","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxvtx_jedec_stx={0x606200a3U,"vectortext_jedec_stx",sxvtx_jedec_stx_fields,SX_COUNT(sxvtx_jedec_stx_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_jedec_etx_fields[]={
 SX_FIELD("end_of_text","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxvtx_jedec_etx={0x606200a4U,"vectortext_jedec_etx",sxvtx_jedec_etx_fields,SX_COUNT(sxvtx_jedec_etx_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_iges_record_label_fields[]={
 SX_FIELD("section","char[1]",0,1,SX_STRING),
 SX_FIELD("sequence_number","ascii_signed[7]",1,7,SX_NONE),
};
static const sx_layout sxvtx_iges_record_label={0x606200a5U,"vectortext_iges_record_label",sxvtx_iges_record_label_fields,SX_COUNT(sxvtx_iges_record_label_fields),SX_LE};
static const sx_layout*const sx_vectortext_layouts[]={&sxvtx_signature,&sxvtx_version,&sxvtx_keyword,&sxvtx_name,&sxvtx_string_value,&sxvtx_record_text,&sxvtx_xml_element,&sxvtx_xml_attribute,&sxvtx_encoding,&sxvtx_class_name,&sxvtx_units,&sxvtx_organization,&sxvtx_pixel_format,&sxvtx_pixel_byte_order,&sxvtx_pixel_real_format,&sxvtx_reference_name,&sxvtx_width,&sxvtx_height,&sxvtx_depth,&sxvtx_channels,&sxvtx_color_count,&sxvtx_map_width,&sxvtx_map_height,&sxvtx_tile_width,&sxvtx_tile_height,&sxvtx_tile_count,&sxvtx_first_gid,&sxvtx_global_tile_id,&sxvtx_layer_id,&sxvtx_index_value,&sxvtx_input_offset,&sxvtx_input_stride,&sxvtx_dimension,&sxvtx_line_count,&sxvtx_sample_count,&sxvtx_band_count,&sxvtx_n1,&sxvtx_n2,&sxvtx_n3,&sxvtx_n4,&sxvtx_binary_prefix_bytes,&sxvtx_binary_header_records,&sxvtx_record_bytes,&sxvtx_label_bytes,&sxvtx_buffer_bytes,&sxvtx_format_version,&sxvtx_fuse_count,&sxvtx_pin_count,&sxvtx_fuse_index,&sxvtx_default_fuse,&sxvtx_security_fuse,&sxvtx_entity_type,&sxvtx_directory_reference,&sxvtx_parameter_reference,&sxvtx_level,&sxvtx_line_font_pattern,&sxvtx_line_weight,&sxvtx_color_number,&sxvtx_form_number,&sxvtx_profile_count,&sxvtx_row_count,&sxvtx_column_number,&sxvtx_elevation_sample,&sxvtx_dem_level,&sxvtx_elevation_pattern,&sxvtx_reference_system,&sxvtx_zone,&sxvtx_ground_unit,&sxvtx_elevation_unit,&sxvtx_polygon_side_count,&sxvtx_accuracy_code,&sxvtx_tool_number,&sxvtx_aperture_number,&sxvtx_command_code,&sxvtx_x,&sxvtx_y,&sxvtx_rotation,&sxvtx_line_width,&sxvtx_real_value,&sxvtx_coordinate_value,&sxvtx_alpha_trait,&sxvtx_color_space,&sxvtx_compression,&sxvtx_page_geometry,&sxvtx_rendering_intent,&sxvtx_channel_mask,&sxvtx_gamma,&sxvtx_red_primary_x,&sxvtx_red_primary_y,&sxvtx_green_primary_x,&sxvtx_green_primary_y,&sxvtx_blue_primary_x,&sxvtx_blue_primary_y,&sxvtx_white_point_x,&sxvtx_white_point_y,&sxvtx_element_count,&sxvtx_set_index,&sxvtx_visible,&sxvtx_next_layer_id,&sxvtx_next_object_id,&sxvtx_spacing,&sxvtx_margin,&sxvtx_infinite,&sxvtx_format_minor,&sxvtx_unit_meter,&sxvtx_opacity,&sxvtx_advance_width,&sxvtx_advance_height,&sxvtx_x_scale,&sxvtx_y_scale,&sxvtx_xy_scale,&sxvtx_yx_scale,&sxvtx_integer_value,&sxvtx_entity_reference,&sxvtx_encoded_x,&sxvtx_encoded_y,&sxvtx_radius,&sxvtx_diameter,&sxvtx_pen_number,&sxvtx_zero_suppression,&sxvtx_label_terminator,&sxvtx_x_integer_digits,&sxvtx_x_fraction_digits,&sxvtx_y_integer_digits,&sxvtx_y_fraction_digits,&sxvtx_vertex_count,&sxvtx_d_code,&sxvtx_aperture_width,&sxvtx_aperture_height,&sxvtx_hole_diameter,&sxvtx_coordinate_notation,&sxvtx_polarity,&sxvtx_aperture_shape,&sxvtx_row_number,&sxvtx_column_count,&sxvtx_structure_reference,&sxvtx_view_reference,&sxvtx_transform_reference,&sxvtx_label_display_reference,&sxvtx_parameter_line_count,&sxvtx_entity_subscript,&sxvtx_section_record_count,&sxvtx_eol_label,&sxvtx_quality,&sxvtx_meta_channel_count,&sxvtx_dem_x,&sxvtx_dem_y,&sxvtx_dem_coordinate_value,&sxvtx_dem_minimum_elevation,&sxvtx_dem_maximum_elevation,&sxvtx_dem_rotation,&sxvtx_dem_x_resolution,&sxvtx_dem_y_resolution,&sxvtx_dem_z_resolution,&sxvtx_dem_elevation_datum,&sxvtx_dem_projection_parameter,&sxvtx_iges_status,&sxvtx_checksum,&sxvtx_transmission_checksum,&sxvtx_unicode_hex,&sxvtx_rgb_hex,&sxvtx_fuse_bits,&sxvtx_jedec_stx,&sxvtx_jedec_etx,&sxvtx_iges_record_label};
static bool sx_vectortext_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;switch(id){
case 0x6062000eU:return xx_data_struct_record_set_comment(r,L"LOW little-endian integer samples; HIGH big-endian integer samples. Pixel payload remains raw.");
case 0x6062000fU:return xx_data_struct_record_set_comment(r,L"IEEE big-endian IEEE samples; RIEEE little-endian IEEE samples. Pixel payload remains raw.");
case 0x6062001fU:return xx_data_struct_record_set_comment(r,L"Tuple/accessor element index, not a physical file offset.");
case 0x60620072U:return xx_data_struct_record_set_comment(r,L"STEP instance identifier; not a physical file offset or memory address.");
case 0x60620073U:return xx_data_struct_record_set_comment(r,L"Stored integer spelling; no coordinate suppression or scaling applied.");
case 0x60620074U:return xx_data_struct_record_set_comment(r,L"Stored integer spelling; no coordinate suppression or scaling applied.");
case 0x60620078U:return xx_data_struct_record_set_comment(r,L"L/LZ omits leading coordinate zeros; T/TZ omits trailing zeros. Stored digits are preserved without rescaling.");
case 0x60620083U:return xx_data_struct_record_set_comment(r,L"A denotes absolute coordinates.");
case 0x60620084U:return xx_data_struct_record_set_comment(r,L"D denotes dark, C clear.");
case 0x60620085U:return xx_data_struct_record_set_comment(r,L"C circle, R rectangle, O obround, P polygon.");
case 0x6062009dU:return xx_data_struct_record_set_comment(r,L"Four two-digit decimal status codes, not a bit mask.");
case 0x606200a2U:return xx_data_struct_record_set_comment(r,L"Stored ASCII fuse assignments, one bit per source digit. Fuse indices are bit positions, not file offsets.");
default:return true;}}

/* Bounded physical tokens. Whitespace and unparsed bodies retain raw spans. */
typedef struct sxvtx_cursor {sx_context*c;uint8_t*b;int64_t n,p;} sxvtx_cursor;
static bool sxvtx_space(uint8_t x){return x==' '||(x>=9&&x<=13);}
static bool sxvtx_emit(sxvtx_cursor*q,const sx_layout*l,int64_t a,int64_t z){if(a<0||z<0||a>q->n||z>q->n-a)return false;if(!z||q->c->count>=32000)return !xx_pd_is_stopped(q->c->pd);int64_t limit=l->fields[0].size?INT64_MAX:sx_variable_field_limit(l->fields[0].type);if(z>limit)return true;if(!l->fields[0].size&&!xx_rt_wcscmp(l->fields[0].type,L"ascii_hex")){uint64_t value=0;for(int64_t i=0;i<z;i++){unsigned ch=q->b[a+i],digit=ch>='0'&&ch<='9'?ch-'0':ch>='a'&&ch<='f'?ch-'a'+10:ch>='A'&&ch<='F'?ch-'A'+10:16;if(digit>=16||value>(UINT64_MAX-digit)/16)return false;value=value*16+digit;}}return sx_add(q->c,l,a,z);}
static bool sxvtx_line(sxvtx_cursor*q,int64_t*a,int64_t*end,bool comments){while(q->p<q->n){int64_t start=q->p,stop;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;stop=q->p;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;if(comments){bool quoted=false;for(int64_t i=start;i<stop;i++){if(q->b[i]=='\\'&&quoted&&i+1<stop){i++;continue;}if(q->b[i]=='"')quoted=!quoted;if(q->b[i]=='#'&&!quoted){stop=i;break;}}}while(start<stop&&sxvtx_space(q->b[start]))start++;while(stop>start&&sxvtx_space(q->b[stop-1]))stop--;if(start<stop){*a=start;*end=stop;return !xx_pd_is_stopped(q->c->pd);}}return false;}
static bool sxvtx_eq(sxvtx_cursor*q,int64_t a,int64_t z,const char*s){size_t n=xx_rt_strlen(s);return a>=0&&z==(int64_t)n&&a<=q->n&&z<=q->n-a&&!xx_rt_memcmp(q->b+a,s,n);}
#define VT_EMIT(n,a,z) do{if(!sxvtx_emit(q,&sxvtx_##n,(a),(z)))return false;}while(0)

/* Fixed-column records retain padding in the member's physical bytes. */
static bool sxvtx_uint_at(sxvtx_cursor*q,int64_t a,int64_t z,uint64_t*out)
{
 if(a<0||z<1||a>q->n||z>q->n-a)return false;int64_t end=a+z;while(a<end&&sxvtx_space(q->b[a]))a++;while(end>a&&sxvtx_space(q->b[end-1]))end--;if(a<end&&q->b[a]=='+')a++;if(a==end)return false;uint64_t n=0;for(;a<end;a++){unsigned d=q->b[a]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*out=n;return true;
}
static bool sxvtx_nonblank(sxvtx_cursor*q,int64_t a,int64_t z)
{if(a<0||z<0||a>q->n||z>q->n-a)return false;for(int64_t i=0;i<z;i++)if(!sxvtx_space(q->b[a+i]))return true;return false;}
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

static const sx_layout*sxvtx_header_type(sxvtx_cursor*q,int64_t a,int64_t z,bool vicar)
{
 struct sxvtx_key {const char*name;const sx_layout*layout;};
 static const struct sxvtx_key miff[]={
  {"id",&sxvtx_signature},{"version",&sxvtx_version},{"class",&sxvtx_class_name},{"colors",&sxvtx_color_count},{"alpha-trait",&sxvtx_alpha_trait},{"number-channels",&sxvtx_channels},{"number-meta-channels",&sxvtx_meta_channel_count},{"channel-mask",&sxvtx_channel_mask},{"columns",&sxvtx_width},{"rows",&sxvtx_height},{"depth",&sxvtx_depth},{"colorspace",&sxvtx_color_space},{"compression",&sxvtx_compression},{"quality",&sxvtx_quality},{"page",&sxvtx_page_geometry},{"rendering-intent",&sxvtx_rendering_intent},{"gamma",&sxvtx_gamma},{"red-primary",&sxvtx_record_text},{"green-primary",&sxvtx_record_text},{"blue-primary",&sxvtx_record_text},{"white-point",&sxvtx_record_text}};
 static const struct sxvtx_key vic[]={
  {"LBLSIZE",&sxvtx_label_bytes},{"FORMAT",&sxvtx_pixel_format},{"TYPE",&sxvtx_class_name},{"BUFSIZE",&sxvtx_buffer_bytes},{"DIM",&sxvtx_dimension},{"EOL",&sxvtx_eol_label},{"RECSIZE",&sxvtx_record_bytes},{"ORG",&sxvtx_organization},{"NL",&sxvtx_line_count},{"NS",&sxvtx_sample_count},{"NB",&sxvtx_band_count},{"N1",&sxvtx_n1},{"N2",&sxvtx_n2},{"N3",&sxvtx_n3},{"N4",&sxvtx_n4},{"NBB",&sxvtx_binary_prefix_bytes},{"NLB",&sxvtx_binary_header_records},{"TASK",&sxvtx_name},{"INTFMT",&sxvtx_pixel_byte_order},{"REALFMT",&sxvtx_pixel_real_format}};
 const struct sxvtx_key*keys=vicar?vic:miff;size_t count=vicar?SX_COUNT(vic):SX_COUNT(miff);for(size_t i=0;i<count;i++)if(sxvtx_eq(q,a,z,keys[i].name))return keys[i].layout;return NULL;
}
static bool sxvtx_image_header(sxvtx_cursor*q,bool vicar)
{
 int64_t p=0,end=vicar?q->n:(q->n<16384?q->n:16384);bool terminated=false;
 while(p<end){
  if(q->c->count>=32000)return true;while(p<end&&sxvtx_space(q->b[p]))p++;if(p==end)break;if(vicar&&!q->b[p]){terminated=true;break;}
  if(!vicar&&end-p>=2&&q->b[p]==':'&&q->b[p+1]==26){VT_EMIT(signature,p,2);terminated=true;break;}
  int64_t key=p;while(p<end&&q->b[p]!='='&&!sxvtx_space(q->b[p]))p++;int64_t keylen=p-key;while(p<end&&sxvtx_space(q->b[p]))p++;if(p==end||q->b[p]!='=')return false;const sx_layout*l=sxvtx_header_type(q,key,keylen,vicar);if(!l)return false;VT_EMIT(keyword,key,keylen);p++;
  while(p<end&&sxvtx_space(q->b[p]))p++;int64_t a=p,z;bool quote=vicar&&p<end&&q->b[p]=='\'';
  if(quote){a=++p;while(p<end&&q->b[p]!='\''){if(q->b[p]=='\\'&&p+1<end)p++;p++;}if(p==end)return false;z=p-a;p++;}
  else {while(p<end&&!sxvtx_space(q->b[p])&&(!vicar||q->b[p]))p++;z=p-a;}
  if(vicar&&key==0){uint64_t n;if(!sxvtx_uint_at(q,a,z,&n)||n<64||n>1048576||n>(uint64_t)q->n)return false;end=(int64_t)n;}
  if(l==&sxvtx_channel_mask){if(z<3||q->b[a]!='0'||q->b[a+1]!='x')return false;a+=2;z-=2;}
  if(!vicar&&l==&sxvtx_record_text){
   const sx_layout*x=&sxvtx_white_point_x,*y=&sxvtx_white_point_y;
   if(sxvtx_eq(q,key,keylen,"red-primary")){x=&sxvtx_red_primary_x;y=&sxvtx_red_primary_y;}
   else if(sxvtx_eq(q,key,keylen,"green-primary")){x=&sxvtx_green_primary_x;y=&sxvtx_green_primary_y;}
   else if(sxvtx_eq(q,key,keylen,"blue-primary")){x=&sxvtx_blue_primary_x;y=&sxvtx_blue_primary_y;}
   int64_t comma=a;while(comma<a+z&&q->b[comma]!=',')comma++;if(comma==a+z||!sxvtx_emit(q,x,a,comma-a)||!sxvtx_emit(q,y,comma+1,a+z-comma-1))return false;
  }else if(!sxvtx_emit(q,l,a,z))return false;
 }
 return vicar?(p==end||terminated):terminated;
}

/* Attribute values refer to original quote contents. Entity-encoded values
 * stay textual; decoded bytes do not have a contiguous physical extent. */
static const sx_layout*sxvtx_xml_attr(sxvtx_cursor*q,int64_t tag,int64_t tn,int64_t key,int64_t kn,int mode)
{
#define XA(k,l) if(sxvtx_eq(q,key,kn,(k)))return &sxvtx_##l
 if(mode==0){
  XA("count",element_count);XA("stride",input_stride);XA("offset",input_offset);XA("set",set_index);XA("meter",unit_meter);
 }else if(mode==1){
  if(sxvtx_eq(q,key,kn,"width"))return sxvtx_eq(q,tag,tn,"map")||sxvtx_eq(q,tag,tn,"layer")?&sxvtx_map_width:&sxvtx_width;
  if(sxvtx_eq(q,key,kn,"height"))return sxvtx_eq(q,tag,tn,"map")||sxvtx_eq(q,tag,tn,"layer")?&sxvtx_map_height:&sxvtx_height;
  XA("tilewidth",tile_width);XA("tileheight",tile_height);XA("tilecount",tile_count);XA("firstgid",first_gid);XA("columns",column_count);XA("id",layer_id);XA("opacity",opacity);XA("visible",visible);XA("offsetx",x);XA("offsety",y);XA("trans",rgb_hex);XA("nextlayerid",next_layer_id);XA("nextobjectid",next_object_id);XA("spacing",spacing);XA("margin",margin);XA("infinite",infinite);
 }else{
  XA("width",advance_width);XA("height",advance_height);XA("format",format_version);XA("formatMinor",format_minor);XA("hex",unicode_hex);XA("x",x);XA("y",y);XA("xScale",x_scale);XA("yScale",y_scale);XA("xyScale",xy_scale);XA("yxScale",yx_scale);XA("xOffset",x);XA("yOffset",y);XA("angle",rotation);
 }
 XA("name",name);XA("id",name);XA("identifier",name);XA("version",version);XA("encoding",encoding);XA("source",reference_name);XA("base",reference_name);XA("url",reference_name);
#undef XA
 return &sxvtx_string_value;
}
static bool sxvtx_xml(sxvtx_cursor*q,int mode)
{
 struct {int64_t tag,length;bool csv;} stack[128];unsigned depth=0;int64_t p=0;
 while(p<q->n){
  if(q->c->count>=32000)return true;if(xx_pd_is_stopped(q->c->pd))return false;
  if(q->b[p]!='<'){
   int64_t a=p;while(p<q->n&&q->b[p]!='<')p++;int64_t end=p;while(a<end&&sxvtx_space(q->b[a]))a++;while(end>a&&sxvtx_space(q->b[end-1]))end--;
   if(a<end){const sx_layout*l=NULL;
    if(depth){int64_t t=stack[depth-1].tag,z=stack[depth-1].length;
     if(mode==0){if(sxvtx_eq(q,t,z,"p"))l=&sxvtx_index_value;else if(sxvtx_eq(q,t,z,"float_array")||sxvtx_eq(q,t,z,"translate")||sxvtx_eq(q,t,z,"rotate")||sxvtx_eq(q,t,z,"scale")||sxvtx_eq(q,t,z,"matrix"))l=&sxvtx_real_value;}
     if(mode==1&&stack[depth-1].csv)l=&sxvtx_global_tile_id;
    }
    if(l){while(a<end){while(a<end&&(sxvtx_space(q->b[a])||q->b[a]==','))a++;int64_t start=a;while(a<end&&!sxvtx_space(q->b[a])&&q->b[a]!=',')a++;bool entity=false;for(int64_t i=start;i<a;i++)entity|=q->b[i]=='&';if(!sxvtx_emit(q,entity?&sxvtx_string_value:l,start,a-start))return false;if(q->c->count>=32000)return true;}}
    else {for(;a<end;){int64_t z=end-a>4096?4096:end-a;VT_EMIT(record_text,a,z);a+=z;}}
   }continue;
  }
  if(q->n-p>=4&&!xx_rt_memcmp(q->b+p,"<!--",4)){p+=4;while(q->n-p>=3&&xx_rt_memcmp(q->b+p,"-->",3))p++;if(q->n-p<3)return false;p+=3;continue;}
  if(q->n-p>=9&&!xx_rt_memcmp(q->b+p,"<![CDATA[",9)){p+=9;while(q->n-p>=3&&xx_rt_memcmp(q->b+p,"]]>",3))p++;if(q->n-p<3)return false;p+=3;continue;}
  if(q->n-p>=2&&q->b[p+1]=='?'){int64_t a=p;p+=2;while(q->n-p>=2&&!(q->b[p]=='?'&&q->b[p+1]=='>'))p++;if(q->n-p<2)return false;p+=2;VT_EMIT(record_text,a,p-a);continue;}
  p++;bool close=p<q->n&&q->b[p]=='/';if(close)p++;int64_t tag=p;while(p<q->n&&!sxvtx_space(q->b[p])&&q->b[p]!='>'&&q->b[p]!='/')p++;int64_t tn=p-tag;if(!tn)return false;VT_EMIT(xml_element,tag,tn);bool self=false,csv=false;
  for(;;){
   while(p<q->n&&sxvtx_space(q->b[p]))p++;if(p==q->n)return false;if(q->b[p]=='>'){p++;break;}if(q->b[p]=='/'&&q->n-p>=2&&q->b[p+1]=='>'){p+=2;self=true;break;}
   if(close)return false;int64_t key=p;while(p<q->n&&!sxvtx_space(q->b[p])&&q->b[p]!='=')p++;int64_t kn=p-key;while(p<q->n&&sxvtx_space(q->b[p]))p++;if(!kn||p==q->n||q->b[p++]!='=')return false;VT_EMIT(xml_attribute,key,kn);while(p<q->n&&sxvtx_space(q->b[p]))p++;if(p==q->n||(q->b[p]!='\''&&q->b[p]!='"'))return false;unsigned quote=q->b[p++];int64_t a=p;bool entity=false;while(p<q->n&&q->b[p]!=quote){entity|=q->b[p]=='&';p++;}if(p==q->n)return false;int64_t z=p++-a;
   const sx_layout*l=entity?&sxvtx_string_value:sxvtx_xml_attr(q,tag,tn,key,kn,mode);if(!sxvtx_emit(q,l,a,z))return false;
   if(mode==1&&sxvtx_eq(q,tag,tn,"data")&&sxvtx_eq(q,key,kn,"encoding")&&sxvtx_eq(q,a,z,"csv"))csv=true;
  }
  if(close){
   if(!depth||stack[depth-1].length!=tn||xx_rt_memcmp(q->b+stack[depth-1].tag,q->b+tag,(size_t)tn))return false;depth--;
  }else if(!self){if(depth==SX_COUNT(stack))return false;stack[depth].tag=tag;stack[depth].length=tn;stack[depth].csv=csv;depth++;}
 }
 return depth==0;
}

/* Native-validated lexical scene records. These token fields describe physical
 * spelling; they do not claim a reconstructed scene graph or units. */
static bool sxvtx_lex(sxvtx_cursor*q,xx_file_type_t type)
{
 bool hash=type==XX_FILE_TYPE_VRML_SCENE||type==XX_FILE_TYPE_RENDERMAN_RIB||type==XX_FILE_TYPE_OPENUSD_USDA;
 bool cpp=type==XX_FILE_TYPE_OPENGEX_MODEL||type==XX_FILE_TYPE_MOTIF_UIL;
 bool block=cpp||type==XX_FILE_TYPE_STEP_PART21;
 bool step=type==XX_FILE_TYPE_STEP_PART21;
 if(type==XX_FILE_TYPE_VRML_SCENE||type==XX_FILE_TYPE_OPENUSD_USDA){int64_t p=0;while(p<q->n&&q->b[p]!='\r'&&q->b[p]!='\n')p++;VT_EMIT(signature,0,p);q->p=p;}
 while(q->p<q->n){
  if(q->c->count>=32000)return true;if(xx_pd_is_stopped(q->c->pd))return false;uint8_t c=q->b[q->p];if(sxvtx_space(c)){q->p++;continue;}
  if((hash&&c=='#')||(cpp&&c=='/'&&q->n-q->p>=2&&q->b[q->p+1]=='/')){while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;continue;}
  if(block&&c=='/'&&q->n-q->p>=2&&q->b[q->p+1]=='*'){q->p+=2;while(q->n-q->p>=2&&(q->b[q->p]!='*'||q->b[q->p+1]!='/'))q->p++;if(q->n-q->p<2)return false;q->p+=2;continue;}
  if(c=='"'||c=='\''){uint8_t quote=c;int64_t a=++q->p;while(q->p<q->n&&q->b[q->p]!=quote){if(q->b[q->p]=='\\'&&q->p+1<q->n)q->p++;q->p++;}if(q->p==q->n)return false;VT_EMIT(string_value,a,q->p-a);q->p++;continue;}
  if(c=='{'||c=='}'||c=='('||c==')'||c==';'||c==','||c==':'||c=='['||c==']'||c=='='){q->p++;continue;}
  if(step&&c=='#'){q->p++;int64_t a=q->p;while(q->p<q->n&&q->b[q->p]>='0'&&q->b[q->p]<='9')q->p++;if(a==q->p)return false;VT_EMIT(entity_reference,a,q->p-a);continue;}
  int64_t a=q->p;while(q->p<q->n){c=q->b[q->p];if(sxvtx_space(c)||c=='{'||c=='}'||c=='('||c==')'||c==';'||c==','||c==':'||c=='['||c==']'||c=='='||c=='"'||c=='\''||(step&&c=='#')||(hash&&c=='#'))break;if(c=='/'&&q->n-q->p>=2&&((cpp&&q->b[q->p+1]=='/')||(block&&q->b[q->p+1]=='*')))break;q->p++;}int64_t z=q->p-a;if(!z)return false;
  int64_t t=0;bool real=false,valid=true;unsigned digits=0;if(t<z&&(q->b[a+t]=='+'||q->b[a+t]=='-'))t++;
  while(t<z&&q->b[a+t]>='0'&&q->b[a+t]<='9'){t++;digits++;}if(t<z&&q->b[a+t]=='.'){real=true;t++;while(t<z&&q->b[a+t]>='0'&&q->b[a+t]<='9'){t++;digits++;}}
  valid=digits>0;if(t<z&&(q->b[a+t]=='e'||q->b[a+t]=='E')){real=true;t++;if(t<z&&(q->b[a+t]=='+'||q->b[a+t]=='-'))t++;int64_t first=t;while(t<z&&q->b[a+t]>='0'&&q->b[a+t]<='9')t++;if(first==t)valid=false;}
  const sx_layout*l=valid&&t==z?(type==XX_FILE_TYPE_OGC_WKT?&sxvtx_coordinate_value:real?&sxvtx_real_value:&sxvtx_integer_value):&sxvtx_keyword;
  if(!sxvtx_emit(q,l,a,z))return false;
 }
 return true;
}
static bool sxvtx_hpgl(sxvtx_cursor*q)
{
 int64_t p=0;unsigned terminator=3;
 while(p<q->n){if(q->c->count>=32000)return true;while(p<q->n&&sxvtx_space(q->b[p]))p++;if(p==q->n)break;if(q->n-p<2)return false;int64_t key=p;VT_EMIT(keyword,key,2);p+=2;
  if(sxvtx_eq(q,key,2,"LB")){int64_t a=p;while(p<q->n&&q->b[p]!=terminator)p++;if(p==q->n)return false;VT_EMIT(string_value,a,p-a);p++;if(p<q->n&&q->b[p]==';')p++;continue;}
  int64_t end=p;while(end<q->n&&q->b[end]!=';')end++;if(end==q->n)return false;
  if(sxvtx_eq(q,key,2,"DT")){if(end-p>1)return false;if(end>p){terminator=q->b[p];VT_EMIT(label_terminator,p,1);}else terminator=3;}
  else {unsigned i=0;while(p<end){while(p<end&&(sxvtx_space(q->b[p])||q->b[p]==','))p++;int64_t a=p;while(p<end&&q->b[p]!=',')p++;int64_t stop=p;while(stop>a&&sxvtx_space(q->b[stop-1]))stop--;const sx_layout*l=&sxvtx_real_value;
    if(sxvtx_eq(q,key,2,"PA")||sxvtx_eq(q,key,2,"PR")||sxvtx_eq(q,key,2,"PU")||sxvtx_eq(q,key,2,"PD"))l=i%2?&sxvtx_y:&sxvtx_x;
    else if(sxvtx_eq(q,key,2,"SP"))l=&sxvtx_pen_number;
    else if(sxvtx_eq(q,key,2,"CI")&&i==0)l=&sxvtx_radius;
    else if(sxvtx_eq(q,key,2,"PW")&&i==0)l=&sxvtx_line_width;
    if(!sxvtx_emit(q,l,a,stop-a))return false;i++;}}
  p=end+1;
 }
 return true;
}
/* Gerber/Excellon coordinates are encoded decimal integers. Suppression and
 * scale are recorded separately: emitted digits are never silently rescaled. */
static bool sxvtx_drill(sxvtx_cursor*q)
{
 int64_t a,end;while(sxvtx_line(q,&a,&end,false)){if(q->c->count>=32000)return true;if(q->b[a]==';')continue;
  if(sxvtx_eq(q,a,end-a,"INCH,LZ")||sxvtx_eq(q,a,end-a,"INCH,TZ")||sxvtx_eq(q,a,end-a,"METRIC,LZ")||sxvtx_eq(q,a,end-a,"METRIC,TZ")){int64_t n=q->b[a]=='I'?4:6;VT_EMIT(units,a,n);VT_EMIT(zero_suppression,a+n+1,2);continue;}
  if(q->b[a]=='%'){VT_EMIT(keyword,a,1);continue;}
  while(a<end){while(a<end&&sxvtx_space(q->b[a]))a++;if(a==end)break;unsigned key=q->b[a];VT_EMIT(keyword,a,1);int64_t value=++a;while(value<end&&sxvtx_space(q->b[value]))value++;a=value;if(a<end&&(q->b[a]=='+'||q->b[a]=='-'))a++;
   while(a<end&&((q->b[a]>='0'&&q->b[a]<='9')||q->b[a]=='.'||q->b[a]=='e'||q->b[a]=='E'||((q->b[a]=='+'||q->b[a]=='-')&&a>value&&(q->b[a-1]=='e'||q->b[a-1]=='E'))))a++;
   const sx_layout*l=key=='T'?&sxvtx_tool_number:key=='C'?&sxvtx_diameter:key=='X'?&sxvtx_encoded_x:key=='Y'?&sxvtx_encoded_y:&sxvtx_command_code;if(!sxvtx_emit(q,l,value,a-value))return false;
  }
 }
 return true;
}

static bool sxvtx_gerber(sxvtx_cursor*q)
{
 int64_t p=0;
 while(p<q->n){if(q->c->count>=32000)return true;while(p<q->n&&sxvtx_space(q->b[p]))p++;if(p==q->n)break;bool extended=q->b[p]=='%';if(extended)p++;int64_t a=p;while(p<q->n&&q->b[p]!='*')p++;if(p==q->n)return false;int64_t end=p++;if(extended&&(p==q->n||q->b[p++]!='%'))return false;
  if(extended){
   while(a<end&&sxvtx_space(q->b[a]))a++;while(end>a&&sxvtx_space(q->b[end-1]))end--;
   if(end-a==10&&q->b[a]=='F'&&q->b[a+1]=='S'){
    VT_EMIT(keyword,a,2);VT_EMIT(zero_suppression,a+2,1);VT_EMIT(coordinate_notation,a+3,1);VT_EMIT(keyword,a+4,1);VT_EMIT(x_integer_digits,a+5,1);VT_EMIT(x_fraction_digits,a+6,1);VT_EMIT(keyword,a+7,1);VT_EMIT(y_integer_digits,a+8,1);VT_EMIT(y_fraction_digits,a+9,1);
   }else if(end-a==4&&q->b[a]=='M'&&q->b[a+1]=='O'){VT_EMIT(keyword,a,2);VT_EMIT(units,a+2,2);}
   else if(end-a==3&&q->b[a]=='L'&&q->b[a+1]=='P'){VT_EMIT(keyword,a,2);VT_EMIT(polarity,a+2,1);}
   else if(end-a>=3&&q->b[a]=='A'){
    /* Native lexer permits whitespace between the three ADD letters. */
    for(unsigned k=0;k<3;k++){while(a<end&&sxvtx_space(q->b[a]))a++;if(a==end)return false;VT_EMIT(keyword,a,1);a++;}
    while(a<end&&sxvtx_space(q->b[a]))a++;int64_t start=a;if(a<end&&(q->b[a]=='+'||q->b[a]=='-'))a++;while(a<end&&q->b[a]>='0'&&q->b[a]<='9')a++;VT_EMIT(aperture_number,start,a-start);if(a==end)return false;unsigned shape=q->b[a];VT_EMIT(aperture_shape,a,1);a++;while(a<end&&sxvtx_space(q->b[a]))a++;if(a==end||q->b[a++]!=',')return false;
    unsigned item=0;while(a<end){while(a<end&&sxvtx_space(q->b[a]))a++;start=a;while(a<end&&q->b[a]!='X')a++;int64_t stop=a;while(stop>start&&sxvtx_space(q->b[stop-1]))stop--;
     const sx_layout*l=&sxvtx_hole_diameter;if(shape=='C')l=item?&sxvtx_hole_diameter:&sxvtx_diameter;else if(shape=='R'||shape=='O')l=item==0?&sxvtx_aperture_width:item==1?&sxvtx_aperture_height:&sxvtx_hole_diameter;else if(shape=='P')l=item==0?&sxvtx_diameter:item==1?&sxvtx_vertex_count:item==2?&sxvtx_rotation:&sxvtx_hole_diameter;
     if(!sxvtx_emit(q,l,start,stop-start))return false;item++;if(a<end)a++;
    }
   }else if(end-a>=2&&q->b[a]=='T'){VT_EMIT(keyword,a,2);if(end-a>2)VT_EMIT(record_text,a+2,end-a-2);}
   else return false;
  }else if(end-a>=3&&!xx_rt_memcmp(q->b+a,"G04",3)){VT_EMIT(keyword,a,3);VT_EMIT(string_value,a+3,end-a-3);}
  else{
   while(a<end){while(a<end&&sxvtx_space(q->b[a]))a++;if(a==end)break;unsigned key=q->b[a];VT_EMIT(keyword,a,1);int64_t start=++a;while(start<end&&sxvtx_space(q->b[start]))start++;a=start;if(a<end&&(q->b[a]=='+'||q->b[a]=='-'))a++;while(a<end&&q->b[a]>='0'&&q->b[a]<='9')a++;if(a==start)return false;
    const sx_layout*l=key=='X'?&sxvtx_encoded_x:key=='Y'?&sxvtx_encoded_y:key=='D'?&sxvtx_d_code:&sxvtx_command_code;if(!sxvtx_emit(q,l,start,a-start))return false;
   }
  }
 }
 return true;
}

/* Physical JEDEC records; decoded fuse arrays never invent file offsets. */
static bool sxvtx_jedec(sxvtx_cursor*q)
{
 if(q->n<2||q->b[0]!=2)return false;VT_EMIT(jedec_stx,0,1);
 int64_t p=1;while(p<q->n&&q->b[p]!='*')p++;if(p==q->n)return false;VT_EMIT(string_value,1,p-1);
 while(p<q->n&&q->b[p]=='*'){
  if(q->c->count>=32000)return true;int64_t a=++p,end=p;while(end<q->n&&q->b[end]!='*'&&q->b[end]!=3)end++;
  while(a<end&&sxvtx_space(q->b[a]))a++;int64_t stop=end;while(stop>a&&sxvtx_space(q->b[stop-1]))stop--;
  if(a<stop){unsigned width=q->b[a]=='Q'?2:1;if(stop-a<(int64_t)width)return false;VT_EMIT(keyword,a,width);uint8_t kind=q->b[a];bool pins=width==2&&q->b[a+1]=='P';a+=width;while(a<stop&&sxvtx_space(q->b[a]))a++;
   if(kind=='L'){
    int64_t first=a;while(a<stop&&!sxvtx_space(q->b[a]))a++;VT_EMIT(fuse_index,first,a-first);
    while(a<stop){while(a<stop&&sxvtx_space(q->b[a]))a++;first=a;while(a<stop&&!sxvtx_space(q->b[a])&&a-first<4096)a++;VT_EMIT(fuse_bits,first,a-first);}
   }else if(kind=='N'){VT_EMIT(string_value,a,stop-a);}
   else if(kind=='Q'){if(!sxvtx_emit(q,pins?&sxvtx_pin_count:&sxvtx_fuse_count,a,stop-a))return false;}
   else if(kind=='F'){VT_EMIT(default_fuse,a,stop-a);}
   else if(kind=='G'){VT_EMIT(security_fuse,a,stop-a);}
   else if(kind=='C'){VT_EMIT(checksum,a,stop-a);}
   else return false;
  }
  p=end;
 }
 if(p>=q->n||q->b[p]!=3)return false;VT_EMIT(jedec_etx,p,1);p++;int64_t a=p;while(p<q->n&&!sxvtx_space(q->b[p]))p++;if(p-a!=4)return false;VT_EMIT(transmission_checksum,a,4);return true;
}

static int sxvtx_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxvtx_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxvtx_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxvtx_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}


static bool sx_vectortext_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_VRML_SCENE:case XX_FILE_TYPE_RENDERMAN_RIB:case XX_FILE_TYPE_OPENGEX_MODEL:case XX_FILE_TYPE_OPENUSD_USDA:case XX_FILE_TYPE_IMAGEMAGICK_MVG:case XX_FILE_TYPE_MOTIF_UIL:case XX_FILE_TYPE_STEP_PART21:case XX_FILE_TYPE_OGC_WKT:case XX_FILE_TYPE_MAPINFO_MIF:case XX_FILE_TYPE_COLLADA_DAE:case XX_FILE_TYPE_TILED_TMX:case XX_FILE_TYPE_UFO_GLIF:case XX_FILE_TYPE_IMAGEMAGICK_MIFF:case XX_FILE_TYPE_NASA_VICAR:case XX_FILE_TYPE_HPGL_PLOT:case XX_FILE_TYPE_IGES_MODEL:case XX_FILE_TYPE_GERBER_RS274X:case XX_FILE_TYPE_EXCELLON_DRILL:case XX_FILE_TYPE_JEDEC_FUSE:case XX_FILE_TYPE_USGS_DEM:return true;default:return false;}}
static bool sx_vectortext_build(sx_context*c){
 if(!c||!c->f||c->size<1||c->size>33554432||xx_pd_is_stopped(c->pd))return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxvtx_cursor cursor={c,b,c->size,0},*q=&cursor;xx_file_type_t type=c->f->file_type;
 if(ok)switch(type){case XX_FILE_TYPE_VRML_SCENE:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_RENDERMAN_RIB:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_OPENGEX_MODEL:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_OPENUSD_USDA:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_IMAGEMAGICK_MVG:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_MOTIF_UIL:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_STEP_PART21:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_OGC_WKT:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_MAPINFO_MIF:ok=sxvtx_lex(q,type);break;case XX_FILE_TYPE_COLLADA_DAE:ok=sxvtx_xml(q,0);break;case XX_FILE_TYPE_TILED_TMX:ok=sxvtx_xml(q,1);break;case XX_FILE_TYPE_UFO_GLIF:ok=sxvtx_xml(q,2);break;case XX_FILE_TYPE_IMAGEMAGICK_MIFF:ok=sxvtx_image_header(q,false);break;case XX_FILE_TYPE_NASA_VICAR:ok=sxvtx_image_header(q,true);break;case XX_FILE_TYPE_HPGL_PLOT:ok=sxvtx_hpgl(q);break;case XX_FILE_TYPE_IGES_MODEL:ok=sxvtx_iges(q);break;case XX_FILE_TYPE_GERBER_RS274X:ok=sxvtx_gerber(q);break;case XX_FILE_TYPE_EXCELLON_DRILL:ok=sxvtx_drill(q);break;case XX_FILE_TYPE_JEDEC_FUSE:ok=sxvtx_jedec(q);break;case XX_FILE_TYPE_USGS_DEM:ok=sxvtx_dem(q);break;default:ok=false;break;}
 xx_mem_free(b);return ok&&sxvtx_finish(c);}
#undef VT_VALUE
#undef VT_EMIT
