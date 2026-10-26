/* SPDX-License-Identifier: MIT
 * Native-supported scientific mesh/measurement metadata. Unsupported bytes remain raw. */
static const xx_data_struct_field_desc sxsm_signature_fields[]={SX_FIELD("signature","char",0,0,SX_STRING)};
static const sx_layout sxsm_signature={0x60630001U,"mesh_signature",sxsm_signature_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_keyword_fields[]={SX_FIELD("keyword","char",0,0,SX_STRING)};
static const sx_layout sxsm_keyword={0x60630002U,"mesh_keyword",sxsm_keyword_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_section_fields[]={SX_FIELD("section","char",0,0,SX_STRING)};
static const sx_layout sxsm_section={0x60630003U,"mesh_section",sxsm_section_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_key_fields[]={SX_FIELD("key","char",0,0,SX_STRING)};
static const sx_layout sxsm_key={0x60630004U,"mesh_key",sxsm_key_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_option_value_fields[]={SX_FIELD("option_value","char",0,0,SX_STRING)};
static const sx_layout sxsm_option_value={0x60630005U,"mesh_option_value",sxsm_option_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_title_fields[]={SX_FIELD("title","utf8",0,0,SX_STRING)};
static const sx_layout sxsm_title={0x60630006U,"mesh_title",sxsm_title_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_comment_fields[]={SX_FIELD("comment","utf8",0,0,SX_STRING)};
static const sx_layout sxsm_comment={0x60630007U,"mesh_comment",sxsm_comment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_name_fields[]={SX_FIELD("name","utf8",0,0,SX_STRING)};
static const sx_layout sxsm_name={0x60630008U,"mesh_name",sxsm_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_text_value_fields[]={SX_FIELD("text_value","utf8",0,0,SX_STRING)};
static const sx_layout sxsm_text_value={0x60630009U,"mesh_text_value",sxsm_text_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_type_name_fields[]={SX_FIELD("type_name","char",0,0,SX_STRING)};
static const sx_layout sxsm_type_name={0x6063000aU,"mesh_type_name",sxsm_type_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_encoding_fields[]={SX_FIELD("encoding","char",0,0,SX_STRING)};
static const sx_layout sxsm_encoding={0x6063000bU,"mesh_encoding",sxsm_encoding_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_endian_fields[]={SX_FIELD("endian","char",0,0,SX_STRING)};
static const sx_layout sxsm_endian={0x6063000cU,"mesh_endian",sxsm_endian_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_units_fields[]={SX_FIELD("units","char",0,0,SX_STRING)};
static const sx_layout sxsm_units={0x6063000dU,"mesh_units",sxsm_units_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_filename_fields[]={SX_FIELD("filename","char",0,0,SX_STRING)};
static const sx_layout sxsm_filename={0x6063000eU,"mesh_filename",sxsm_filename_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_format_string_fields[]={SX_FIELD("format_string","char",0,0,SX_STRING)};
static const sx_layout sxsm_format_string={0x6063000fU,"mesh_format_string",sxsm_format_string_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_boolean_text_fields[]={SX_FIELD("boolean_text","char",0,0,SX_STRING)};
static const sx_layout sxsm_boolean_text={0x60630010U,"mesh_boolean_text",sxsm_boolean_text_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_dimension_fields[]={SX_FIELD("dimension","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_dimension={0x60630011U,"mesh_dimension",sxsm_dimension_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_axis_count_fields[]={SX_FIELD("axis_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_axis_count={0x60630012U,"mesh_axis_count",sxsm_axis_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_node_count_fields[]={SX_FIELD("node_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_node_count={0x60630013U,"mesh_node_count",sxsm_node_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_element_count_fields[]={SX_FIELD("element_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_element_count={0x60630014U,"mesh_element_count",sxsm_element_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_value_count_fields[]={SX_FIELD("value_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_value_count={0x60630015U,"mesh_value_count",sxsm_value_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_component_count_fields[]={SX_FIELD("component_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_component_count={0x60630016U,"mesh_component_count",sxsm_component_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_tag_count_fields[]={SX_FIELD("tag_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_tag_count={0x60630017U,"mesh_tag_count",sxsm_tag_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_attribute_count_fields[]={SX_FIELD("attribute_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_attribute_count={0x60630018U,"mesh_attribute_count",sxsm_attribute_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_node_id_fields[]={SX_FIELD("node_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_node_id={0x60630019U,"mesh_node_id",sxsm_node_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_element_id_fields[]={SX_FIELD("element_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_element_id={0x6063001aU,"mesh_element_id",sxsm_element_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_node_index_fields[]={SX_FIELD("node_index","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_node_index={0x6063001bU,"mesh_node_index",sxsm_node_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_property_id_fields[]={SX_FIELD("property_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_property_id={0x6063001cU,"mesh_property_id",sxsm_property_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_region_id_fields[]={SX_FIELD("region_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_region_id={0x6063001dU,"mesh_region_id",sxsm_region_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_entity_id_fields[]={SX_FIELD("entity_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_entity_id={0x6063001eU,"mesh_entity_id",sxsm_entity_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_label_id_fields[]={SX_FIELD("label_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_label_id={0x6063001fU,"mesh_label_id",sxsm_label_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_integer_value_fields[]={SX_FIELD("integer_value","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_integer_value={0x60630020U,"mesh_integer_value",sxsm_integer_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_real_value_fields[]={SX_FIELD("real_value","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_real_value={0x60630021U,"mesh_real_value",sxsm_real_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_coordinate_x_fields[]={SX_FIELD("coordinate_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_coordinate_x={0x60630022U,"mesh_coordinate_x",sxsm_coordinate_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_coordinate_y_fields[]={SX_FIELD("coordinate_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_coordinate_y={0x60630023U,"mesh_coordinate_y",sxsm_coordinate_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_coordinate_z_fields[]={SX_FIELD("coordinate_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_coordinate_z={0x60630024U,"mesh_coordinate_z",sxsm_coordinate_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_origin_x_fields[]={SX_FIELD("origin_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_origin_x={0x60630025U,"mesh_origin_x",sxsm_origin_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_origin_y_fields[]={SX_FIELD("origin_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_origin_y={0x60630026U,"mesh_origin_y",sxsm_origin_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_origin_z_fields[]={SX_FIELD("origin_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_origin_z={0x60630027U,"mesh_origin_z",sxsm_origin_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spacing_x_fields[]={SX_FIELD("spacing_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_spacing_x={0x60630028U,"mesh_spacing_x",sxsm_spacing_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spacing_y_fields[]={SX_FIELD("spacing_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_spacing_y={0x60630029U,"mesh_spacing_y",sxsm_spacing_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spacing_z_fields[]={SX_FIELD("spacing_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_spacing_z={0x6063002aU,"mesh_spacing_z",sxsm_spacing_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_delta_x_fields[]={SX_FIELD("delta_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_delta_x={0x6063002bU,"mesh_delta_x",sxsm_delta_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_delta_y_fields[]={SX_FIELD("delta_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_delta_y={0x6063002cU,"mesh_delta_y",sxsm_delta_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_delta_z_fields[]={SX_FIELD("delta_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_delta_z={0x6063002dU,"mesh_delta_z",sxsm_delta_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_min_x_fields[]={SX_FIELD("box_min_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_box_min_x={0x6063002eU,"mesh_box_min_x",sxsm_box_min_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_min_y_fields[]={SX_FIELD("box_min_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_box_min_y={0x6063002fU,"mesh_box_min_y",sxsm_box_min_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_min_z_fields[]={SX_FIELD("box_min_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_box_min_z={0x60630030U,"mesh_box_min_z",sxsm_box_min_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_max_x_fields[]={SX_FIELD("box_max_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_box_max_x={0x60630031U,"mesh_box_max_x",sxsm_box_max_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_max_y_fields[]={SX_FIELD("box_max_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_box_max_y={0x60630032U,"mesh_box_max_y",sxsm_box_max_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_max_z_fields[]={SX_FIELD("box_max_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_box_max_z={0x60630033U,"mesh_box_max_z",sxsm_box_max_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_scalar_min_fields[]={SX_FIELD("scalar_min","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_scalar_min={0x60630034U,"mesh_scalar_min",sxsm_scalar_min_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_scalar_max_fields[]={SX_FIELD("scalar_max","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_scalar_max={0x60630035U,"mesh_scalar_max",sxsm_scalar_max_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_scalar_value_fields[]={SX_FIELD("scalar_value","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_scalar_value={0x60630036U,"mesh_scalar_value",sxsm_scalar_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_attribute_value_fields[]={SX_FIELD("attribute_value","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_attribute_value={0x60630037U,"mesh_attribute_value",sxsm_attribute_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_sample_bytes_fields[]={SX_FIELD("sample_bytes","ascii_signed",0,0,SX_SIZE)};
static const sx_layout sxsm_sample_bytes={0x60630038U,"mesh_sample_bytes",sxsm_sample_bytes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_header_bytes_fields[]={SX_FIELD("header_bytes","ascii_signed",0,0,SX_SIZE)};
static const sx_layout sxsm_header_bytes={0x60630039U,"mesh_header_bytes",sxsm_header_bytes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_sample_bits_fields[]={SX_FIELD("sample_bits","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_sample_bits={0x6063003aU,"mesh_sample_bits",sxsm_sample_bits_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_significant_bits_fields[]={SX_FIELD("significant_bits","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_significant_bits={0x6063003bU,"mesh_significant_bits",sxsm_significant_bits_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_ics_parameter_count_fields[]={SX_FIELD("ics_parameter_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_ics_parameter_count={0x6063003cU,"mesh_ics_parameter_count",sxsm_ics_parameter_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_byte_order_index_fields[]={SX_FIELD("byte_order_index","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_byte_order_index={0x6063003dU,"mesh_byte_order_index",sxsm_byte_order_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_parameter_origin_fields[]={SX_FIELD("parameter_origin","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_parameter_origin={0x6063003eU,"mesh_parameter_origin",sxsm_parameter_origin_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_parameter_scale_fields[]={SX_FIELD("parameter_scale","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_parameter_scale={0x6063003fU,"mesh_parameter_scale",sxsm_parameter_scale_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_x_increment_fields[]={SX_FIELD("x_increment","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_x_increment={0x60630040U,"mesh_x_increment",sxsm_x_increment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_x_zero_fields[]={SX_FIELD("x_zero","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_x_zero={0x60630041U,"mesh_x_zero",sxsm_x_zero_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_point_offset_fields[]={SX_FIELD("point_offset","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_point_offset={0x60630042U,"mesh_point_offset",sxsm_point_offset_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_y_multiplier_fields[]={SX_FIELD("y_multiplier","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_y_multiplier={0x60630043U,"mesh_y_multiplier",sxsm_y_multiplier_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_y_zero_fields[]={SX_FIELD("y_zero","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_y_zero={0x60630044U,"mesh_y_zero",sxsm_y_zero_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_y_offset_fields[]={SX_FIELD("y_offset","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_y_offset={0x60630045U,"mesh_y_offset",sxsm_y_offset_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_length_digits_fields[]={SX_FIELD("length_digits","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_length_digits={0x60630046U,"mesh_length_digits",sxsm_length_digits_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_payload_bytes_fields[]={SX_FIELD("payload_bytes","ascii_signed",0,0,SX_SIZE)};
static const sx_layout sxsm_payload_bytes={0x60630047U,"mesh_payload_bytes",sxsm_payload_bytes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_node_label_fields[]={SX_FIELD("node_label","utf8",0,0,SX_STRING)};
static const sx_layout sxsm_node_label={0x60630048U,"mesh_node_label",sxsm_node_label_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_tree_name_fields[]={SX_FIELD("tree_name","char",0,0,SX_STRING)};
static const sx_layout sxsm_tree_name={0x60630049U,"mesh_tree_name",sxsm_tree_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_taxon_count_fields[]={SX_FIELD("taxon_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_taxon_count={0x6063004aU,"mesh_taxon_count",sxsm_taxon_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_branch_length_fields[]={SX_FIELD("branch_length","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_branch_length={0x6063004bU,"mesh_branch_length",sxsm_branch_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_jcamp_version_fields[]={SX_FIELD("jcamp_version","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_jcamp_version={0x6063004cU,"mesh_jcamp_version",sxsm_jcamp_version_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_first_x_fields[]={SX_FIELD("first_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_first_x={0x6063004dU,"mesh_first_x",sxsm_first_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_last_x_fields[]={SX_FIELD("last_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_last_x={0x6063004eU,"mesh_last_x",sxsm_last_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_x_factor_fields[]={SX_FIELD("x_factor","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_x_factor={0x6063004fU,"mesh_x_factor",sxsm_x_factor_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_y_factor_fields[]={SX_FIELD("y_factor","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_y_factor={0x60630050U,"mesh_y_factor",sxsm_y_factor_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spectral_x_fields[]={SX_FIELD("spectral_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_spectral_x={0x60630051U,"mesh_spectral_x",sxsm_spectral_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spectral_y_fields[]={SX_FIELD("spectral_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_spectral_y={0x60630052U,"mesh_spectral_y",sxsm_spectral_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_total_lines_fields[]={SX_FIELD("hb_total_lines","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_hb_total_lines={0x60630053U,"mesh_hb_total_lines",sxsm_hb_total_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_pointer_lines_fields[]={SX_FIELD("hb_pointer_lines","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_hb_pointer_lines={0x60630054U,"mesh_hb_pointer_lines",sxsm_hb_pointer_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_index_lines_fields[]={SX_FIELD("hb_index_lines","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_hb_index_lines={0x60630055U,"mesh_hb_index_lines",sxsm_hb_index_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_value_lines_fields[]={SX_FIELD("hb_value_lines","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_hb_value_lines={0x60630056U,"mesh_hb_value_lines",sxsm_hb_value_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_hb_rhs_lines_fields[]={SX_FIELD("hb_rhs_lines","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_hb_rhs_lines={0x60630057U,"mesh_hb_rhs_lines",sxsm_hb_rhs_lines_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_matrix_rows_fields[]={SX_FIELD("matrix_rows","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_matrix_rows={0x60630058U,"mesh_matrix_rows",sxsm_matrix_rows_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_matrix_columns_fields[]={SX_FIELD("matrix_columns","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_matrix_columns={0x60630059U,"mesh_matrix_columns",sxsm_matrix_columns_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_nonzero_count_fields[]={SX_FIELD("nonzero_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_nonzero_count={0x6063005aU,"mesh_nonzero_count",sxsm_nonzero_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_elemental_values_fields[]={SX_FIELD("elemental_values","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_elemental_values={0x6063005bU,"mesh_elemental_values",sxsm_elemental_values_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_column_pointer_fields[]={SX_FIELD("column_pointer","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_column_pointer={0x6063005cU,"mesh_column_pointer",sxsm_column_pointer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_row_index_fields[]={SX_FIELD("row_index","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_row_index={0x6063005dU,"mesh_row_index",sxsm_row_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_matrix_key_fields[]={SX_FIELD("matrix_key","char",0,0,SX_STRING)};
static const sx_layout sxsm_matrix_key={0x6063005eU,"mesh_matrix_key",sxsm_matrix_key_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_matrix_type_fields[]={SX_FIELD("matrix_type","char",0,0,SX_STRING)};
static const sx_layout sxsm_matrix_type={0x6063005fU,"mesh_matrix_type",sxsm_matrix_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_mesh_version_fields[]={SX_FIELD("mesh_version","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_mesh_version={0x60630060U,"mesh_mesh_version",sxsm_mesh_version_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_element_type_fields[]={SX_FIELD("element_type","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_element_type={0x60630061U,"mesh_element_type",sxsm_element_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_tag_value_fields[]={SX_FIELD("tag_value","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_tag_value={0x60630062U,"mesh_tag_value",sxsm_tag_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_step_index_fields[]={SX_FIELD("step_index","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_step_index={0x60630063U,"mesh_step_index",sxsm_step_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_simulation_time_fields[]={SX_FIELD("simulation_time","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_simulation_time={0x60630064U,"mesh_simulation_time",sxsm_simulation_time_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_boundary_marker_fields[]={SX_FIELD("boundary_marker","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_boundary_marker={0x60630065U,"mesh_boundary_marker",sxsm_boundary_marker_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_surface_id_fields[]={SX_FIELD("surface_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_surface_id={0x60630066U,"mesh_surface_id",sxsm_surface_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_boundary_id_fields[]={SX_FIELD("boundary_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_boundary_id={0x60630067U,"mesh_boundary_id",sxsm_boundary_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_inside_domain_fields[]={SX_FIELD("inside_domain","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_inside_domain={0x60630068U,"mesh_inside_domain",sxsm_inside_domain_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_outside_domain_fields[]={SX_FIELD("outside_domain","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_outside_domain={0x60630069U,"mesh_outside_domain",sxsm_outside_domain_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_region_fields[]={SX_FIELD("edge_region","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_edge_region={0x6063006aU,"mesh_edge_region",sxsm_edge_region_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_triangle_fields[]={SX_FIELD("edge_triangle","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_edge_triangle={0x6063006bU,"mesh_edge_triangle",sxsm_edge_triangle_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_surface_fields[]={SX_FIELD("edge_surface","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_edge_surface={0x6063006cU,"mesh_edge_surface",sxsm_edge_surface_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_id_fields[]={SX_FIELD("edge_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_edge_id={0x6063006dU,"mesh_edge_id",sxsm_edge_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_distance_fields[]={SX_FIELD("edge_distance","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_edge_distance={0x6063006eU,"mesh_edge_distance",sxsm_edge_distance_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_geometry_type_fields[]={SX_FIELD("geometry_type","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_geometry_type={0x6063006fU,"mesh_geometry_type",sxsm_geometry_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_red_fields[]={SX_FIELD("red","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_red={0x60630070U,"mesh_red",sxsm_red_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_green_fields[]={SX_FIELD("green","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_green={0x60630071U,"mesh_green",sxsm_green_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_blue_fields[]={SX_FIELD("blue","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_blue={0x60630072U,"mesh_blue",sxsm_blue_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_alpha_fields[]={SX_FIELD("alpha","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_alpha={0x60630073U,"mesh_alpha",sxsm_alpha_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_axis_name_fields[]={SX_FIELD("axis_name","char",0,0,SX_STRING)};
static const sx_layout sxsm_axis_name={0x60630074U,"mesh_axis_name",sxsm_axis_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_axis_unit_fields[]={SX_FIELD("axis_unit","char",0,0,SX_STRING)};
static const sx_layout sxsm_axis_unit={0x60630075U,"mesh_axis_unit",sxsm_axis_unit_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_z_direction_fields[]={SX_FIELD("z_direction","char",0,0,SX_STRING)};
static const sx_layout sxsm_z_direction={0x60630076U,"mesh_z_direction",sxsm_z_direction_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_topology_name_fields[]={SX_FIELD("topology_name","char",0,0,SX_STRING)};
static const sx_layout sxsm_topology_name={0x60630077U,"mesh_topology_name",sxsm_topology_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_variable_name_fields[]={SX_FIELD("variable_name","char",0,0,SX_STRING)};
static const sx_layout sxsm_variable_name={0x60630078U,"mesh_variable_name",sxsm_variable_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_material_name_fields[]={SX_FIELD("material_name","char",0,0,SX_STRING)};
static const sx_layout sxsm_material_name={0x60630079U,"mesh_material_name",sxsm_material_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_surface_face_fields[]={SX_FIELD("surface_face","char",0,0,SX_STRING)};
static const sx_layout sxsm_surface_face={0x6063007aU,"mesh_surface_face",sxsm_surface_face_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_material_id_fields[]={SX_FIELD("material_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_material_id={0x6063007bU,"mesh_material_id",sxsm_material_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_coordinate_system_fields[]={SX_FIELD("coordinate_system","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_coordinate_system={0x6063007cU,"mesh_coordinate_system",sxsm_coordinate_system_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_displacement_coordinate_system_fields[]={SX_FIELD("displacement_coordinate_system","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_displacement_coordinate_system={0x6063007dU,"mesh_displacement_coordinate_system",sxsm_displacement_coordinate_system_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_permanent_constraints_fields[]={SX_FIELD("permanent_constraints","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsm_permanent_constraints={0x6063007eU,"mesh_permanent_constraints",sxsm_permanent_constraints_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_superelement_id_fields[]={SX_FIELD("superelement_id","ascii_signed",0,0,SX_ID)};
static const sx_layout sxsm_superelement_id={0x6063007fU,"mesh_superelement_id",sxsm_superelement_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_nastran_x_fields[]={SX_FIELD("nastran_x","ascii_nastran_real",0,0,SX_NONE)};
static const sx_layout sxsm_nastran_x={0x60630080U,"mesh_nastran_x",sxsm_nastran_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_nastran_y_fields[]={SX_FIELD("nastran_y","ascii_nastran_real",0,0,SX_NONE)};
static const sx_layout sxsm_nastran_y={0x60630081U,"mesh_nastran_y",sxsm_nastran_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_nastran_z_fields[]={SX_FIELD("nastran_z","ascii_nastran_real",0,0,SX_NONE)};
static const sx_layout sxsm_nastran_z={0x60630082U,"mesh_nastran_z",sxsm_nastran_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_bar_orientation_x_fields[]={SX_FIELD("bar_orientation_x","ascii_nastran_real",0,0,SX_NONE)};
static const sx_layout sxsm_bar_orientation_x={0x60630083U,"mesh_bar_orientation_x",sxsm_bar_orientation_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_bar_orientation_y_fields[]={SX_FIELD("bar_orientation_y","ascii_nastran_real",0,0,SX_NONE)};
static const sx_layout sxsm_bar_orientation_y={0x60630084U,"mesh_bar_orientation_y",sxsm_bar_orientation_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_bar_orientation_z_fields[]={SX_FIELD("bar_orientation_z","ascii_nastran_real",0,0,SX_NONE)};
static const sx_layout sxsm_bar_orientation_z={0x60630085U,"mesh_bar_orientation_z",sxsm_bar_orientation_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_count_fields[]={SX_FIELD("binary_count","int32",0,4,SX_COUNT_PROP)};
static const sx_layout sxsm_binary_count={0x60630086U,"mesh_binary_count",sxsm_binary_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_arity_fields[]={SX_FIELD("binary_arity","int32",0,4,SX_COUNT_PROP)};
static const sx_layout sxsm_binary_arity={0x60630087U,"mesh_binary_arity",sxsm_binary_arity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_node_index_fields[]={SX_FIELD("binary_node_index","int32",0,4,SX_ID)};
static const sx_layout sxsm_binary_node_index={0x60630088U,"mesh_binary_node_index",sxsm_binary_node_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_material_id_fields[]={SX_FIELD("binary_material_id","int32",0,4,SX_ID)};
static const sx_layout sxsm_binary_material_id={0x60630089U,"mesh_binary_material_id",sxsm_binary_material_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_flag_value_fields[]={SX_FIELD("binary_flag_value","int32",0,4,SX_ID)};
static const sx_layout sxsm_binary_flag_value={0x6063008aU,"mesh_binary_flag_value",sxsm_binary_flag_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_cycle_fields[]={SX_FIELD("binary_cycle","int32",0,4,SX_ID)};
static const sx_layout sxsm_binary_cycle={0x6063008bU,"mesh_binary_cycle",sxsm_binary_cycle_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_location_fields[]={SX_FIELD("binary_location","int32",0,4,SX_NONE)};
static const sx_layout sxsm_binary_location={0x6063008cU,"mesh_binary_location",sxsm_binary_location_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_scalar_fields[]={SX_FIELD("binary_scalar","float",0,4,SX_NONE)};
static const sx_layout sxsm_binary_scalar={0x6063008dU,"mesh_binary_scalar",sxsm_binary_scalar_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_coordinate_fields[]={SX_FIELD("binary_coordinate","float",0,4,SX_NONE)};
static const sx_layout sxsm_binary_coordinate={0x6063008eU,"mesh_binary_coordinate",sxsm_binary_coordinate_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_velocity_fields[]={SX_FIELD("binary_velocity","float",0,4,SX_NONE)};
static const sx_layout sxsm_binary_velocity={0x6063008fU,"mesh_binary_velocity",sxsm_binary_velocity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_time_fields[]={SX_FIELD("binary_time","float",0,4,SX_NONE)};
static const sx_layout sxsm_binary_time={0x60630090U,"mesh_binary_time",sxsm_binary_time_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_name_fields[]={SX_FIELD("binary_name","char[8]",0,8,SX_STRING)};
static const sx_layout sxsm_binary_name={0x60630091U,"mesh_binary_name",sxsm_binary_name_fields,1,SX_LE};
static const sx_layout*const sx_sciencemesh_layouts[]={&sxsm_signature,&sxsm_keyword,&sxsm_section,&sxsm_key,&sxsm_option_value,&sxsm_title,&sxsm_comment,&sxsm_name,&sxsm_text_value,&sxsm_type_name,&sxsm_encoding,&sxsm_endian,&sxsm_units,&sxsm_filename,&sxsm_format_string,&sxsm_boolean_text,&sxsm_dimension,&sxsm_axis_count,&sxsm_node_count,&sxsm_element_count,&sxsm_value_count,&sxsm_component_count,&sxsm_tag_count,&sxsm_attribute_count,&sxsm_node_id,&sxsm_element_id,&sxsm_node_index,&sxsm_property_id,&sxsm_region_id,&sxsm_entity_id,&sxsm_label_id,&sxsm_integer_value,&sxsm_real_value,&sxsm_coordinate_x,&sxsm_coordinate_y,&sxsm_coordinate_z,&sxsm_origin_x,&sxsm_origin_y,&sxsm_origin_z,&sxsm_spacing_x,&sxsm_spacing_y,&sxsm_spacing_z,&sxsm_delta_x,&sxsm_delta_y,&sxsm_delta_z,&sxsm_box_min_x,&sxsm_box_min_y,&sxsm_box_min_z,&sxsm_box_max_x,&sxsm_box_max_y,&sxsm_box_max_z,&sxsm_scalar_min,&sxsm_scalar_max,&sxsm_scalar_value,&sxsm_attribute_value,&sxsm_sample_bytes,&sxsm_header_bytes,&sxsm_sample_bits,&sxsm_significant_bits,&sxsm_ics_parameter_count,&sxsm_byte_order_index,&sxsm_parameter_origin,&sxsm_parameter_scale,&sxsm_x_increment,&sxsm_x_zero,&sxsm_point_offset,&sxsm_y_multiplier,&sxsm_y_zero,&sxsm_y_offset,&sxsm_length_digits,&sxsm_payload_bytes,&sxsm_node_label,&sxsm_tree_name,&sxsm_taxon_count,&sxsm_branch_length,&sxsm_jcamp_version,&sxsm_first_x,&sxsm_last_x,&sxsm_x_factor,&sxsm_y_factor,&sxsm_spectral_x,&sxsm_spectral_y,&sxsm_hb_total_lines,&sxsm_hb_pointer_lines,&sxsm_hb_index_lines,&sxsm_hb_value_lines,&sxsm_hb_rhs_lines,&sxsm_matrix_rows,&sxsm_matrix_columns,&sxsm_nonzero_count,&sxsm_elemental_values,&sxsm_column_pointer,&sxsm_row_index,&sxsm_matrix_key,&sxsm_matrix_type,&sxsm_mesh_version,&sxsm_element_type,&sxsm_tag_value,&sxsm_step_index,&sxsm_simulation_time,&sxsm_boundary_marker,&sxsm_surface_id,&sxsm_boundary_id,&sxsm_inside_domain,&sxsm_outside_domain,&sxsm_edge_region,&sxsm_edge_triangle,&sxsm_edge_surface,&sxsm_edge_id,&sxsm_edge_distance,&sxsm_geometry_type,&sxsm_red,&sxsm_green,&sxsm_blue,&sxsm_alpha,&sxsm_axis_name,&sxsm_axis_unit,&sxsm_z_direction,&sxsm_topology_name,&sxsm_variable_name,&sxsm_material_name,&sxsm_surface_face,&sxsm_material_id,&sxsm_coordinate_system,&sxsm_displacement_coordinate_system,&sxsm_permanent_constraints,&sxsm_superelement_id,&sxsm_nastran_x,&sxsm_nastran_y,&sxsm_nastran_z,&sxsm_bar_orientation_x,&sxsm_bar_orientation_y,&sxsm_bar_orientation_z,&sxsm_binary_count,&sxsm_binary_arity,&sxsm_binary_node_index,&sxsm_binary_material_id,&sxsm_binary_flag_value,&sxsm_binary_cycle,&sxsm_binary_location,&sxsm_binary_scalar,&sxsm_binary_coordinate,&sxsm_binary_velocity,&sxsm_binary_time,&sxsm_binary_name};
static bool sx_sciencemesh_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;if(id<0x60630001U||id>=0x60630001U+SX_COUNT(sx_sciencemesh_layouts))return true;if(!r->name||xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;switch(id){
case 0x60630011U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630012U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630013U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630014U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630015U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630016U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630017U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630018U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630019U:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001aU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001bU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001cU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001dU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001eU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001fU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x60630020U:return xx_data_struct_record_set_comment(r,L"Format-defined physical integer; interpretation follows the preceding key.");
case 0x60630021U:return xx_data_struct_record_set_comment(r,L"Format-defined physical real; values remain stored without transformation.");
case 0x60630022U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630023U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630024U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630025U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630026U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630027U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630028U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630029U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002aU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002bU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002cU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002dU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002eU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002fU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630030U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630031U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630032U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630033U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630034U:return xx_data_struct_record_set_comment(r,L"Stored scalar value in the dataset-defined units.");
case 0x60630035U:return xx_data_struct_record_set_comment(r,L"Stored scalar value in the dataset-defined units.");
case 0x60630036U:return xx_data_struct_record_set_comment(r,L"Stored scalar value in the dataset-defined units.");
case 0x60630037U:return xx_data_struct_record_set_comment(r,L"Stored scalar value in the dataset-defined units.");
case 0x60630038U:return xx_data_struct_record_set_comment(r,L"Stored length in bytes.");
case 0x60630039U:return xx_data_struct_record_set_comment(r,L"Stored length in bytes.");
case 0x6063003aU:return xx_data_struct_record_set_comment(r,L"Number of bits per sample; not a byte size.");
case 0x6063003bU:return xx_data_struct_record_set_comment(r,L"Number of bits per sample; not a byte size.");
case 0x6063003cU:return xx_data_struct_record_set_comment(r,L"ICS layout parameters including the initial bits axis.");
case 0x6063003dU:return xx_data_struct_record_set_comment(r,L"One-based byte position defining the stored byte permutation.");
case 0x6063003eU:return xx_data_struct_record_set_comment(r,L"ICS per-axis origin or scale in its corresponding parameter units.");
case 0x6063003fU:return xx_data_struct_record_set_comment(r,L"ICS per-axis origin or scale in its corresponding parameter units.");
case 0x60630040U:return xx_data_struct_record_set_comment(r,L"ISF horizontal scale/origin in declared X units.");
case 0x60630041U:return xx_data_struct_record_set_comment(r,L"ISF horizontal scale/origin in declared X units.");
case 0x60630042U:return xx_data_struct_record_set_comment(r,L"ISF sample-position offset, not a file byte offset.");
case 0x60630043U:return xx_data_struct_record_set_comment(r,L"ISF vertical calibration in declared Y units.");
case 0x60630044U:return xx_data_struct_record_set_comment(r,L"ISF vertical calibration in declared Y units.");
case 0x60630045U:return xx_data_struct_record_set_comment(r,L"ISF stored sample-value offset, not a file byte offset.");
case 0x60630046U:return xx_data_struct_record_set_comment(r,L"Number of decimal digits in the following IEEE488.2 byte count.");
case 0x60630047U:return xx_data_struct_record_set_comment(r,L"Physical following binary payload length in bytes.");
case 0x60630048U:return xx_data_struct_record_set_comment(r,L"Original Newick label, with quote/escape spelling retained.");
case 0x60630049U:return xx_data_struct_record_set_comment(r,L"Original Nexus tree identifier; no label decoding or renaming.");
case 0x6063004aU:return xx_data_struct_record_set_comment(r,L"Declared number of taxa.");
case 0x6063004bU:return xx_data_struct_record_set_comment(r,L"Stored phylogenetic branch length; units belong to the dataset.");
case 0x6063004cU:return xx_data_struct_record_set_comment(r,L"JCAMP-DX numeric format version.");
case 0x6063004dU:return xx_data_struct_record_set_comment(r,L"Spectral endpoint after applying XFACTOR, in XUNITS.");
case 0x6063004eU:return xx_data_struct_record_set_comment(r,L"Spectral endpoint after applying XFACTOR, in XUNITS.");
case 0x6063004fU:return xx_data_struct_record_set_comment(r,L"JCAMP multiplicative factor; original data values are not rescaled.");
case 0x60630050U:return xx_data_struct_record_set_comment(r,L"JCAMP multiplicative factor; original data values are not rescaled.");
case 0x60630051U:return xx_data_struct_record_set_comment(r,L"Stored abscissa; multiply by XFACTOR for XUNITS.");
case 0x60630052U:return xx_data_struct_record_set_comment(r,L"Stored ordinate; multiply by YFACTOR for YUNITS.");
case 0x60630053U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630054U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630055U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630056U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630057U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630058U:return xx_data_struct_record_set_comment(r,L"Matrix dimension/value count.");
case 0x60630059U:return xx_data_struct_record_set_comment(r,L"Matrix dimension/value count.");
case 0x6063005aU:return xx_data_struct_record_set_comment(r,L"Matrix dimension/value count.");
case 0x6063005bU:return xx_data_struct_record_set_comment(r,L"Matrix dimension/value count.");
case 0x6063005cU:return xx_data_struct_record_set_comment(r,L"One-based index into the matrix index/value arrays; not a file offset.");
case 0x6063005dU:return xx_data_struct_record_set_comment(r,L"One-based matrix row index; not a file offset.");
case 0x60630060U:return xx_data_struct_record_set_comment(r,L"Mesh format version number.");
case 0x60630061U:{static const wchar_t*names[]={L"Gmsh unknown",L"Gmsh line2",L"Gmsh triangle3",L"Gmsh quadrangle4",L"Gmsh tetrahedron4",L"Gmsh hexahedron8",L"Gmsh prism6",L"Gmsh pyramid5",L"Gmsh line3",L"Gmsh triangle6",L"Gmsh quadrangle9",L"Gmsh tetrahedron10",L"Gmsh hexahedron27",L"Gmsh prism18",L"Gmsh pyramid14",L"Gmsh point1",L"Gmsh quadrangle8",L"Gmsh hexahedron20",L"Gmsh prism15",L"Gmsh pyramid13",L"Gmsh triangle9 incomplete",L"Gmsh triangle10",L"Gmsh triangle12 incomplete",L"Gmsh triangle15",L"Gmsh triangle15 incomplete",L"Gmsh triangle21",L"Gmsh line4",L"Gmsh line5",L"Gmsh line6",L"Gmsh tetrahedron20",L"Gmsh tetrahedron35",L"Gmsh tetrahedron56"};if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;int64_t v=xx_var_get_i64(&r->value);return v>0&&(uint64_t)v<SX_COUNT(names)?xx_data_struct_record_set_comment(r,names[v]):true;}
case 0x60630062U:return xx_data_struct_record_set_comment(r,L"Gmsh integer tag; meaning depends on tag position.");
case 0x60630063U:return xx_data_struct_record_set_comment(r,L"Simulation step index; not a wall-clock timestamp.");
case 0x60630064U:return xx_data_struct_record_set_comment(r,L"Stored simulation time in model-defined units, not a wall-clock timestamp.");
case 0x60630065U:return xx_data_struct_record_set_comment(r,L"TetGen boundary marker or mesh boundary/reference label.");
case 0x60630066U:return xx_data_struct_record_set_comment(r,L"Netgen physical surface/domain identifier.");
case 0x60630067U:return xx_data_struct_record_set_comment(r,L"Netgen physical surface/domain identifier.");
case 0x60630068U:return xx_data_struct_record_set_comment(r,L"Netgen physical surface/domain identifier.");
case 0x60630069U:return xx_data_struct_record_set_comment(r,L"Netgen physical surface/domain identifier.");
case 0x6063006aU:return xx_data_struct_record_set_comment(r,L"Netgen stored edge-region, geometry triangle, surface or edge identifier.");
case 0x6063006bU:return xx_data_struct_record_set_comment(r,L"Netgen stored edge-region, geometry triangle, surface or edge identifier.");
case 0x6063006cU:return xx_data_struct_record_set_comment(r,L"Netgen stored edge-region, geometry triangle, surface or edge identifier.");
case 0x6063006dU:return xx_data_struct_record_set_comment(r,L"Netgen stored edge-region, geometry triangle, surface or edge identifier.");
case 0x6063006eU:return xx_data_struct_record_set_comment(r,L"Netgen stored geometric edge parameter/distance; not a file offset or necessarily Euclidean length.");
case 0x6063006fU:return xx_data_struct_record_set_comment(r,L"Netgen geometry implementation code.");
case 0x60630070U:return xx_data_struct_record_set_comment(r,L"Normalized color component in0..1.");
case 0x60630071U:return xx_data_struct_record_set_comment(r,L"Normalized color component in0..1.");
case 0x60630072U:return xx_data_struct_record_set_comment(r,L"Normalized color component in0..1.");
case 0x60630073U:return xx_data_struct_record_set_comment(r,L"Normalized color component in0..1.");
case 0x6063007bU:return xx_data_struct_record_set_comment(r,L"Integer material/flag assignment, not a file offset.");
case 0x6063007cU:return xx_data_struct_record_set_comment(r,L"NASTRAN coordinate system identifier; native subset requires0.");
case 0x6063007dU:return xx_data_struct_record_set_comment(r,L"NASTRAN GRID CD displacement coordinate-system identifier; native subset requires0.");
case 0x6063007eU:return xx_data_struct_record_set_comment(r,L"NASTRAN GRID PS permanent constraint component digits; native subset requires0.");
case 0x6063007fU:return xx_data_struct_record_set_comment(r,L"NASTRAN GRID SEID superelement identifier; native subset requires0.");
case 0x60630080U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630081U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630082U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630083U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630084U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630085U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630086U:return xx_data_struct_record_set_comment(r,L"Native GMV signed32 entry count.");
case 0x60630087U:return xx_data_struct_record_set_comment(r,L"Native GMV signed32 entry count.");
case 0x60630088U:return xx_data_struct_record_set_comment(r,L"Native GMV physical integer/index; not a file offset.");
case 0x60630089U:return xx_data_struct_record_set_comment(r,L"Native GMV physical integer/index; not a file offset.");
case 0x6063008aU:return xx_data_struct_record_set_comment(r,L"Native GMV physical integer/index; not a file offset.");
case 0x6063008bU:return xx_data_struct_record_set_comment(r,L"Native GMV physical integer/index; not a file offset.");
case 0x6063008cU:return xx_data_struct_record_set_comment(r,L"GMV association selector: 0=cell-centered, 1=node-centered.");
case 0x6063008dU:return xx_data_struct_record_set_comment(r,L"Native GMV stored IEEE754 binary32; model-defined units.");
case 0x6063008eU:return xx_data_struct_record_set_comment(r,L"Native GMV stored IEEE754 binary32; model-defined units.");
case 0x6063008fU:return xx_data_struct_record_set_comment(r,L"Native GMV stored IEEE754 binary32; model-defined units.");
case 0x60630090U:return xx_data_struct_record_set_comment(r,L"Native GMV stored IEEE754 binary32; model-defined units.");
case 0x60630091U:return xx_data_struct_record_set_comment(r,L"Fixed GMV eight-byte keyword/name, padding retained.");
default:return true;}}
/* Native validation gates interpretation; every emitted span is checked again. */
typedef struct sxsm_cursor{sx_context*c;uint8_t*b;int64_t n,p;uint64_t work;}sxsm_cursor;
typedef struct sxsm_token{int64_t a,z;}sxsm_token;
static bool sxsm_space(uint8_t c){return c==' '||c=='\t'||c=='\r'||c=='\n';}
static bool sxsm_eq(sxsm_cursor*q,sxsm_token t,const char*s){size_t n=xx_rt_strlen(s);return t.a>=0&&t.z==(int64_t)n&&t.a<=q->n&&t.z<=q->n-t.a&&!xx_rt_memcmp(q->b+t.a,s,n);}
static bool sxsm_ci(sxsm_cursor*q,sxsm_token t,const char*s){size_t n=xx_rt_strlen(s);if(t.a<0||t.z!=(int64_t)n||t.a>q->n||t.z>q->n-t.a)return false;for(size_t i=0;i<n;i++){unsigned ch=q->b[t.a+i];if(ch>='A'&&ch<='Z')ch+=32;if(ch!=(unsigned char)s[i])return false;}return true;}
static sxsm_token sxsm_trim(sxsm_cursor*q,sxsm_token t){while(t.z&&sxsm_space(q->b[t.a])){t.a++;t.z--;}while(t.z&&sxsm_space(q->b[t.a+t.z-1]))t.z--;return t;}
static bool sxsm_line(sxsm_cursor*q,sxsm_token*t){if(q->p>=q->n||++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;t->a=q->p;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;t->z=q->p-t->a;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;return true;}
static unsigned sxsm_split(sxsm_cursor*q,sxsm_token line,sxsm_token*t,unsigned cap,bool tabs){unsigned n=0;int64_t p=line.a,end=p+line.z;while(p<end){if(tabs){int64_t a=p;while(p<end&&q->b[p]!='\t')p++;if(n==cap)return cap+1;t[n++]=(sxsm_token){a,p-a};if(p<end)p++;}else{while(p<end&&sxsm_space(q->b[p]))p++;if(p==end)break;int64_t a=p;while(p<end&&!sxsm_space(q->b[p]))p++;if(n==cap)return cap+1;t[n++]=(sxsm_token){a,p-a};}}return n;}
static bool sxsm_emit(sxsm_cursor*q,const sx_layout*l,sxsm_token t){if(t.a<0||t.z<0||t.a>q->n||t.z>q->n-t.a||xx_pd_is_stopped(q->c->pd))return false;if(!t.z||q->c->count>=24000)return true;if(!l->fields[0].size&&t.z>sx_variable_field_limit(l->fields[0].type))return true;return sx_add(q->c,l,t.a,t.z);}
static bool sxsm_number(sxsm_cursor*q,sxsm_token t,uint64_t*v){t=sxsm_trim(q,t);uint64_t n=0;int64_t i=0;if(t.z&&q->b[t.a]=='+')i++;if(i==t.z)return false;for(;i<t.z;i++){unsigned d=q->b[t.a+i]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*v=n;return true;}
static bool sxsm_fields(sxsm_cursor*q,sxsm_token*t,unsigned n,const sx_layout*const*l,unsigned max){if(n>max)return false;for(unsigned i=0;i<n;i++)if(l[i]&&!sxsm_emit(q,l[i],t[i]))return false;return true;}
static bool sxsm_column(sxsm_cursor*q,const sx_layout*l,sxsm_token line,unsigned at,unsigned width){if(at>(uint64_t)line.z||width>(uint64_t)line.z-at)return false;sxsm_token t={line.a+at,width};/* Blank optional numeric columns remain raw. */if(!sxsm_trim(q,t).z)return true;return sxsm_emit(q,l,t);}
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
#define SM_COL(n,o,z) do{if(!sxsm_column(q,&sxsm_##n,line,(o),(z)))return false;}while(0)
static bool sxsm_next(sxsm_cursor*q,sxsm_token*line,sxsm_token*t,unsigned cap,unsigned*n,const char*comments){while(sxsm_line(q,line)){int64_t i=0;uint8_t quote=0;for(;i<line->z;i++){uint8_t ch=q->b[line->a+i];if(quote){if(ch==quote)quote=0;else if(ch==92&&i+1<line->z)i++;continue;}if(ch==34||ch==39){quote=ch;continue;}if(xx_rt_strchr(comments,ch)){SM_EMIT(comment,((sxsm_token){line->a+i,line->z-i}));line->z=i;break;}}*line=sxsm_trim(q,*line);if(line->z){*n=sxsm_split(q,*line,t,cap,false);return *n<=cap;}}return false;}
static bool sxsm_each(sxsm_cursor*q,sxsm_token*t,unsigned n,const sx_layout*l){for(unsigned i=0;i<n;i++)if(!sxsm_emit(q,l,t[i]))return false;return true;}
static bool sxsm_xyz(sxsm_cursor*q,sxsm_token*t,unsigned kind){const sx_layout*const rows[][3]={{&sxsm_coordinate_x,&sxsm_coordinate_y,&sxsm_coordinate_z},{&sxsm_origin_x,&sxsm_origin_y,&sxsm_origin_z},{&sxsm_spacing_x,&sxsm_spacing_y,&sxsm_spacing_z},{&sxsm_delta_x,&sxsm_delta_y,&sxsm_delta_z}};return kind<SX_COUNT(rows)&&sxsm_fields(q,t,3,rows[kind],3);}
static unsigned sxsm_csv(sxsm_cursor*q,sxsm_token line,sxsm_token*t,unsigned cap){unsigned n=0;int64_t p=line.a,end=p+line.z;do{int64_t a=p;while(p<end&&q->b[p]!=',')p++;if(n==cap)return cap+1;t[n++]=sxsm_trim(q,(sxsm_token){a,p-a});if(p==end)break;p++;}while(p<=end);return n;}
static bool sxsm_keyvalue(sxsm_cursor*q,sxsm_token line,uint8_t delim,sxsm_token*key,sxsm_token*value){int64_t i=0;while(i<line.z&&q->b[line.a+i]!=delim)i++;if(i==line.z)return false;*key=sxsm_trim(q,(sxsm_token){line.a,i});*value=sxsm_trim(q,(sxsm_token){line.a+i+1,line.z-i-1});return key->z!=0;}
static bool sxsm_nrrd_meta(sxsm_cursor*q,bool meta){sxsm_token line,key,value,t[32];unsigned n;if(!meta){if(!sxsm_line(q,&line))return false;SM_EMIT(signature,line);}while(sxsm_line(q,&line)){if(q->c->count>=24000)return true;line=sxsm_trim(q,line);if(!line.z){if(!meta)return true;continue;}if(q->b[line.a]=='#'){SM_EMIT(comment,line);continue;}if(!sxsm_keyvalue(q,line,meta?'=':':',&key,&value))return false;SM_EMIT(key,key);const sx_layout*l=&sxsm_option_value;
 if(sxsm_ci(q,key,meta?"ndims":"dimension"))l=&sxsm_dimension;
 else if(sxsm_ci(q,key,meta?"elementtype":"type"))l=&sxsm_type_name;
 else if(sxsm_ci(q,key,"encoding"))l=&sxsm_encoding;
 else if(sxsm_ci(q,key,"endian"))l=&sxsm_endian;
 else if(meta&&(sxsm_ci(q,key,"binarydata")||sxsm_ci(q,key,"compresseddata")||sxsm_ci(q,key,"binarydatabyteordermsb")||sxsm_ci(q,key,"elementbyteordermsb")))l=&sxsm_boolean_text;
 else if(meta&&sxsm_ci(q,key,"elementnumberofchannels"))l=&sxsm_component_count;
 else if(meta&&sxsm_ci(q,key,"headersize"))l=&sxsm_header_bytes;
 else if(sxsm_ci(q,key,meta?"dimsize":"sizes")){n=sxsm_split(q,value,t,32,false);if(n>32||!sxsm_each(q,t,n,&sxsm_axis_count))return false;continue;}
 if(!sxsm_emit(q,l,value))return false;if(meta&&sxsm_ci(q,key,"elementdatafile"))return true;
 }return false;}
static bool sxsm_vtk(sxsm_cursor*q){sxsm_token line,t[16];unsigned n;if(!sxsm_line(q,&line))return false;SM_EMIT(signature,line);if(!sxsm_line(q,&line))return false;SM_EMIT(title,line);while(sxsm_next(q,&line,t,16,&n,"")){if(q->c->count>=24000)return true;SM_EMIT(keyword,t[0]);if(sxsm_eq(q,t[0],"BINARY"))continue;if(sxsm_eq(q,t[0],"DATASET")){if(n!=2)return false;SM_EMIT(type_name,t[1]);}else if(sxsm_eq(q,t[0],"DIMENSIONS")){if(n!=4||!sxsm_each(q,t+1,3,&sxsm_axis_count))return false;}else if(sxsm_eq(q,t[0],"ORIGIN")||sxsm_eq(q,t[0],"SPACING")){if(n!=4||!sxsm_xyz(q,t+1,sxsm_eq(q,t[0],"ORIGIN")?1:2))return false;}else if(sxsm_eq(q,t[0],"POINT_DATA")||sxsm_eq(q,t[0],"CELL_DATA")){if(n!=2)return false;SM_EMIT(value_count,t[1]);}else if(sxsm_eq(q,t[0],"SCALARS")){if(n!=3&&n!=4)return false;SM_EMIT(name,t[1]);SM_EMIT(type_name,t[2]);if(n==4)SM_EMIT(component_count,t[3]);}else if(sxsm_eq(q,t[0],"LOOKUP_TABLE")){if(n!=2)return false;SM_EMIT(name,t[1]);return true;}else return false;}return false;}
static bool sxsm_ics(sxsm_cursor*q){sxsm_token line,t[32];unsigned n;if(!sxsm_line(q,&line))return false;/* First physical line declares separators; preserve tab as raw. */while(sxsm_next(q,&line,t,32,&n,"")){if(q->c->count>=24000)return true;SM_EMIT(key,t[0]);if(sxsm_eq(q,t[0],"end"))return true;if(n<2)return false;if(sxsm_eq(q,t[0],"ics_version")){SM_EMIT(option_value,t[1]);continue;}if(sxsm_eq(q,t[0],"filename")){SM_EMIT(filename,t[1]);continue;}if(sxsm_eq(q,t[0],"history")){SM_EMIT(text_value,((sxsm_token){t[1].a,line.a+line.z-t[1].a}));continue;}SM_EMIT(key,t[1]);if(n<3)return false;const sx_layout*l=&sxsm_option_value;
 if(sxsm_eq(q,t[0],"layout")){if(sxsm_eq(q,t[1],"parameters"))l=&sxsm_ics_parameter_count;else if(sxsm_eq(q,t[1],"sizes")){SM_EMIT(sample_bits,t[2]);if(!sxsm_each(q,t+3,n-3,&sxsm_axis_count))return false;continue;}else if(sxsm_eq(q,t[1],"significant_bits"))l=&sxsm_significant_bits;else if(sxsm_eq(q,t[1],"order"))l=&sxsm_axis_name;}
 else if(sxsm_eq(q,t[0],"representation")){if(sxsm_eq(q,t[1],"byte_order"))l=&sxsm_byte_order_index;else if(sxsm_eq(q,t[1],"format"))l=&sxsm_type_name;else if(sxsm_eq(q,t[1],"compression"))l=&sxsm_encoding;}
 else if(sxsm_eq(q,t[0],"parameter")){if(sxsm_eq(q,t[1],"origin"))l=&sxsm_parameter_origin;else if(sxsm_eq(q,t[1],"scale"))l=&sxsm_parameter_scale;else if(sxsm_eq(q,t[1],"units"))l=&sxsm_axis_unit;else if(sxsm_eq(q,t[1],"labels"))l=&sxsm_axis_name;}
 if(!sxsm_each(q,t+2,n-2,l))return false;}return false;}
static bool sxsm_isf(sxsm_cursor*q){if(q->n<8)return false;SM_EMIT(signature,((sxsm_token){0,8}));int64_t p=8;while(p<q->n&&p<32768){if(q->c->count>=24000)return true;if(q->n-p>=6&&!xx_rt_memcmp(q->b+p,":CURVE",6)){SM_EMIT(keyword,((sxsm_token){p,6}));p+=6;while(p<q->n&&q->b[p]==' ')p++;if(q->n-p<2||q->b[p]!='#')return false;p++;unsigned digits=q->b[p]-'0';if(digits<1||digits>9||q->n-p-1<digits)return false;SM_EMIT(length_digits,((sxsm_token){p,1}));SM_EMIT(payload_bytes,((sxsm_token){p+1,digits}));return true;}
 int64_t a=p;bool quote=false;while(p<q->n){uint8_t c=q->b[p];if(c=='"')quote=!quote;if(!quote&&c==';')break;p++;}if(p==q->n||quote)return false;sxsm_token line=sxsm_trim(q,(sxsm_token){a,p-a}),key,value;int64_t i=0;while(i<line.z&&!sxsm_space(q->b[line.a+i]))i++;key=(sxsm_token){line.a,i};value=sxsm_trim(q,(sxsm_token){line.a+i,line.z-i});SM_EMIT(key,key);const sx_layout*l=sxsm_eq(q,key,"BYT_NR")?&sxsm_sample_bytes:sxsm_eq(q,key,"BIT_NR")?&sxsm_sample_bits:sxsm_eq(q,key,"NR_PT")?&sxsm_value_count:sxsm_eq(q,key,"XINCR")?&sxsm_x_increment:sxsm_eq(q,key,"XZERO")?&sxsm_x_zero:sxsm_eq(q,key,"PT_OFF")?&sxsm_point_offset:sxsm_eq(q,key,"YMULT")?&sxsm_y_multiplier:sxsm_eq(q,key,"YZERO")?&sxsm_y_zero:sxsm_eq(q,key,"YOFF")?&sxsm_y_offset:sxsm_eq(q,key,"XUNIT")||sxsm_eq(q,key,"YUNIT")?&sxsm_units:sxsm_eq(q,key,"BYT_OR")?&sxsm_endian:sxsm_eq(q,key,"ENCDG")?&sxsm_encoding:&sxsm_option_value;if(!sxsm_emit(q,l,value))return false;p++;}return false;}
static bool sxsm_phylo(sxsm_cursor*q,bool nexus){bool length=false,count=false,tree=false,treeeq=false,topology=!nexus,taxa=false;while(q->p<q->n){if(q->c->count>=24000)return true;if(++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;uint8_t ch=q->b[q->p];if(sxsm_space(ch)){q->p++;continue;}int64_t a=q->p;if(ch=='['){unsigned depth=1;q->p++;while(q->p<q->n&&depth){ch=q->b[q->p++];if(ch=='['&&++depth>64)return false;if(ch==']')depth--;}if(depth)return false;SM_EMIT(comment,((sxsm_token){a,q->p-a}));continue;}if(xx_rt_strchr("(),:;=*",ch)){if(ch==':'&&topology)length=true;if(ch=='='&&treeeq){topology=true;treeeq=false;}if(ch==';'&&nexus){topology=false;taxa=false;}q->p++;continue;}if(ch=='\''){q->p++;bool closed=false;while(q->p<q->n){if(q->b[q->p++]=='\''){if(q->p<q->n&&q->b[q->p]=='\''){q->p++;continue;}closed=true;break;}}if(!closed)return false;}else{while(q->p<q->n&&!sxsm_space(q->b[q->p])&&!xx_rt_strchr("(),:;=[]",q->b[q->p]))q->p++;}if(q->p==a)return false;sxsm_token t={a,q->p-a};const sx_layout*l=&sxsm_node_label;
 if(length){l=&sxsm_branch_length;length=false;}else if(count){l=&sxsm_taxon_count;count=false;}else if(tree){l=&sxsm_tree_name;tree=false;treeeq=true;}else if(nexus&&!topology&&!taxa&&(sxsm_ci(q,t,"#nexus")||sxsm_ci(q,t,"begin")||sxsm_ci(q,t,"taxa")||sxsm_ci(q,t,"dimensions")||sxsm_ci(q,t,"ntax")||sxsm_ci(q,t,"taxlabels")||sxsm_ci(q,t,"trees")||sxsm_ci(q,t,"tree")||sxsm_ci(q,t,"utree")||sxsm_ci(q,t,"end")||sxsm_ci(q,t,"endblock"))){l=&sxsm_keyword;taxa=sxsm_ci(q,t,"taxlabels");count=sxsm_ci(q,t,"ntax");tree=sxsm_ci(q,t,"tree")||sxsm_ci(q,t,"utree");}
 if(!sxsm_emit(q,l,t))return false;}return true;}
static bool sxsm_surfer(sxsm_cursor*q){sxsm_token line,t[512];unsigned n;if(!sxsm_next(q,&line,t,512,&n,"#")||n!=1)return false;SM_EMIT(signature,t[0]);if(!sxsm_next(q,&line,t,512,&n,"#")||n!=2||!sxsm_each(q,t,2,&sxsm_axis_count))return false;const sx_layout*lo[]={&sxsm_box_min_x,&sxsm_box_min_y,&sxsm_scalar_min},*hi[]={&sxsm_box_max_x,&sxsm_box_max_y,&sxsm_scalar_max};for(unsigned i=0;i<3;i++){if(!sxsm_next(q,&line,t,512,&n,"#")||n!=2||!sxsm_emit(q,lo[i],t[0])||!sxsm_emit(q,hi[i],t[1]))return false;}while(sxsm_next(q,&line,t,512,&n,"#")){if(q->c->count>=24000)return true;if(!sxsm_each(q,t,n,&sxsm_scalar_value))return false;}return true;}
static bool sxsm_dx(sxsm_cursor*q){sxsm_token line,t[512];unsigned n;uint64_t left=0;bool data=false;while(sxsm_next(q,&line,t,512,&n,"#")){if(q->c->count>=24000)return true;if(data&&left){if(n>left||!sxsm_each(q,t,n,&sxsm_scalar_value))return false;left-=n;continue;}SM_EMIT(keyword,t[0]);if(sxsm_eq(q,t[0],"origin")||sxsm_eq(q,t[0],"delta")){if(n!=4||!sxsm_xyz(q,t+1,sxsm_eq(q,t[0],"origin")?1:3))return false;}else if(sxsm_eq(q,t[0],"object")&&n==8){SM_EMIT(entity_id,t[1]);if(!sxsm_each(q,t+2,3,&sxsm_keyword)||!sxsm_each(q,t+5,3,&sxsm_axis_count))return false;}else if(sxsm_eq(q,t[0],"object")&&n==12){SM_EMIT(entity_id,t[1]);for(unsigned i=2;i<n;i++){if(i==5)SM_EMIT(type_name,t[i]);else if(i==7)SM_EMIT(dimension,t[i]);else if(i==9){SM_EMIT(value_count,t[i]);if(!sxsm_number(q,t[i],&left))return false;}else SM_EMIT(keyword,t[i]);}data=true;}else if(sxsm_eq(q,t[0],"object")&&n>=4){int64_t stop=t[n-2].a;SM_EMIT(name,sxsm_trim(q,(sxsm_token){t[1].a,stop-t[1].a}));if(!sxsm_each(q,t+n-2,2,&sxsm_keyword))return false;}else if(sxsm_eq(q,t[0],"component")&&n==4){SM_EMIT(name,t[1]);SM_EMIT(keyword,t[2]);SM_EMIT(entity_id,t[3]);}else if(!sxsm_each(q,t+1,n-1,&sxsm_option_value))return false;}return true;}
static bool sxsm_jcamp(sxsm_cursor*q){sxsm_token line,t[128],key,value;unsigned n;bool data=false,pairs=false;while(sxsm_line(q,&line)){if(q->c->count>=24000)return true;if(!line.z)continue;if(line.z>=2&&q->b[line.a]=='#'&&q->b[line.a+1]=='#'){if(!sxsm_keyvalue(q,(sxsm_token){line.a+2,line.z-2},'=',&key,&value))return false;SM_EMIT(key,key);char k[64];unsigned used=0;for(int64_t i=0;i<key.z;i++){uint8_t ch=q->b[key.a+i];if(ch==' '||ch=='-'||ch=='/'||ch=='_')continue;if(ch>='a'&&ch<='z')ch-=32;if(used==63)return false;k[used++]=(char)ch;}k[used]=0;
 const sx_layout*l=!xx_rt_strcmp(k,"TITLE")?&sxsm_title:!xx_rt_strcmp(k,"JCAMPDX")?&sxsm_jcamp_version:!xx_rt_strcmp(k,"FIRSTX")?&sxsm_first_x:!xx_rt_strcmp(k,"LASTX")?&sxsm_last_x:!xx_rt_strcmp(k,"XFACTOR")?&sxsm_x_factor:!xx_rt_strcmp(k,"YFACTOR")?&sxsm_y_factor:!xx_rt_strcmp(k,"NPOINTS")?&sxsm_value_count:!xx_rt_strcmp(k,"XUNITS")||!xx_rt_strcmp(k,"YUNITS")?&sxsm_units:&sxsm_option_value;if(!sxsm_emit(q,l,value))return false;if(!xx_rt_strcmp(k,"END"))return true;if(!xx_rt_strcmp(k,"XYDATA")||!xx_rt_strcmp(k,"XYPOINTS")){data=true;pairs=!xx_rt_strcmp(k,"XYPOINTS");}}
 else if(data){n=sxsm_split(q,line,t,128,false);if(n>128)return false;for(unsigned i=0;i<n;i++)if(!sxsm_emit(q,(pairs?!(i&1):i==0)?&sxsm_spectral_x:&sxsm_spectral_y,t[i]))return false;}else return false;}return false;}
static bool sxsm_hb_format(sxsm_cursor*q,sxsm_token t,unsigned*repeat,unsigned*width){t=sxsm_trim(q,t);if(t.z<5||q->b[t.a]!='(')return false;int64_t p=1,a=p;while(p<t.z&&q->b[t.a+p]>='0'&&q->b[t.a+p]<='9')p++;uint64_t v;if(!sxsm_number(q,(sxsm_token){t.a+a,p-a},&v)||v>1000||!v)return false;*repeat=(unsigned)v;if(p==t.z)return false;p++;a=p;while(p<t.z&&q->b[t.a+p]>='0'&&q->b[t.a+p]<='9')p++;if(!sxsm_number(q,(sxsm_token){t.a+a,p-a},&v)||!v||v>96)return false;*width=(unsigned)v;return true;}
static bool sxsm_hb(sxsm_cursor*q){sxsm_token line;unsigned repeats[3],widths[3];uint64_t cols,nnz;if(!sxsm_line(q,&line)||line.z!=80)return false;SM_COL(title,0,72);SM_COL(matrix_key,72,8);if(!sxsm_line(q,&line)||(line.z!=56&&line.z!=70))return false;const sx_layout*counts[]={&sxsm_hb_total_lines,&sxsm_hb_pointer_lines,&sxsm_hb_index_lines,&sxsm_hb_value_lines,&sxsm_hb_rhs_lines};for(unsigned i=0;i<(unsigned)line.z/14;i++)if(!sxsm_column(q,counts[i],line,i*14,14))return false;
 if(!sxsm_line(q,&line)||line.z!=70)return false;SM_COL(matrix_type,0,3);SM_COL(matrix_rows,14,14);SM_COL(matrix_columns,28,14);SM_COL(nonzero_count,42,14);SM_COL(elemental_values,56,14);if(!sxsm_number(q,(sxsm_token){line.a+28,14},&cols)||!sxsm_number(q,(sxsm_token){line.a+42,14},&nnz)||cols>1000000||nnz>1000000)return false;
 if(!sxsm_line(q,&line)||(line.z!=52&&line.z!=72))return false;for(unsigned i=0;i<3;i++){unsigned at=i*16,width=i==2?20:16;if(!sxsm_column(q,&sxsm_format_string,line,at,width)||!sxsm_hb_format(q,(sxsm_token){line.a+at,width},repeats+i,widths+i))return false;}
 const sx_layout*values[]={&sxsm_column_pointer,&sxsm_row_index,&sxsm_scalar_value};uint64_t totals[]={cols+1,nnz,nnz};for(unsigned k=0;k<3;k++){uint64_t done=0;bool first=true;while(done<totals[k]){if(q->c->count>=24000)return true;unsigned n=(unsigned)(totals[k]-done<repeats[k]?totals[k]-done:repeats[k]);if(!sxsm_line(q,&line))return false;if(k==2&&first&&widths[k]>1&&(uint64_t)line.z==(uint64_t)n*(widths[k]-1))widths[k]--;first=false;if((uint64_t)line.z!=(uint64_t)n*widths[k])return false;for(unsigned i=0;i<n;i++)if(!sxsm_column(q,values[k],line,i*widths[k],widths[k]))return false;done+=n;}}return true;}
static bool sxsm_tetgen(sxsm_cursor*q){sxsm_token line,t[128];unsigned n;uint64_t count,dim,attrs,marker=0;if(!sxsm_next(q,&line,t,128,&n,"#")||(n!=3&&n!=4)||!sxsm_number(q,t[0],&count)||!sxsm_number(q,t[1],&dim)||!sxsm_number(q,t[2],&attrs)||attrs>64||dim>10)return false;bool node=n==4;if(!sxsm_emit(q,node?&sxsm_node_count:&sxsm_element_count,t[0]))return false;if(node)SM_EMIT(dimension,t[1]);else SM_EMIT(component_count,t[1]);SM_EMIT(attribute_count,t[2]);if(node){if(!sxsm_number(q,t[3],&marker)||marker>1)return false;SM_EMIT(boundary_marker,t[3]);}for(uint64_t i=0;i<count;i++){if(q->c->count>=24000)return true;if(!sxsm_next(q,&line,t,128,&n,"#")||n!=1+dim+attrs+marker)return false;if(node){SM_EMIT(node_id,t[0]);for(unsigned j=0;j<dim;j++){const sx_layout*l=j==0?&sxsm_coordinate_x:j==1?&sxsm_coordinate_y:&sxsm_coordinate_z;if(!sxsm_emit(q,l,t[1+j]))return false;}}else{SM_EMIT(element_id,t[0]);if(!sxsm_each(q,t+1,(unsigned)dim,&sxsm_node_index))return false;}if(!sxsm_each(q,t+1+dim,(unsigned)attrs,&sxsm_attribute_value))return false;if(marker)SM_EMIT(boundary_marker,t[n-1]);}return true;}
static bool sxsm_gmsh_data(sxsm_cursor*q){sxsm_token line,t[32];unsigned n;uint64_t count,components=0,entries=0;for(unsigned kind=0;kind<3;kind++){if(!sxsm_next(q,&line,t,32,&n,"#")||n!=1||!sxsm_number(q,t[0],&count)||count>16)return false;SM_EMIT(tag_count,t[0]);for(uint64_t i=0;i<count;i++){if(!sxsm_line(q,&line))return false;line=sxsm_trim(q,line);const sx_layout*l=kind==0?&sxsm_name:kind==1?(i==0?&sxsm_simulation_time:&sxsm_real_value):i==0?&sxsm_step_index:i==1?&sxsm_component_count:i==2?&sxsm_value_count:&sxsm_integer_value;if(!sxsm_emit(q,l,line))return false;if(kind==2&&i==1&&!sxsm_number(q,line,&components))return false;if(kind==2&&i==2&&!sxsm_number(q,line,&entries))return false;}}
 if(!components||components>16||entries>1000000)return false;for(uint64_t i=0;i<entries;i++){if(q->c->count>=24000)return true;if(!sxsm_next(q,&line,t,32,&n,"#")||n!=1+components)return false;SM_EMIT(entity_id,t[0]);if(!sxsm_each(q,t+1,n-1,&sxsm_scalar_value))return false;}return true;}
static bool sxsm_gmsh(sxsm_cursor*q){sxsm_token line,t[128];unsigned n;while(sxsm_next(q,&line,t,128,&n,"#")){if(q->c->count>=24000)return true;SM_EMIT(section,t[0]);if(sxsm_eq(q,t[0],"$MeshFormat")){if(!sxsm_next(q,&line,t,128,&n,"#")||n!=3)return false;SM_EMIT(real_value,t[0]);SM_EMIT(integer_value,t[1]);SM_EMIT(sample_bytes,t[2]);continue;}
 if(sxsm_eq(q,t[0],"$NodeData")||sxsm_eq(q,t[0],"$ElementData")){if(!sxsm_gmsh_data(q))return false;continue;}
 unsigned mode=sxsm_eq(q,t[0],"$Nodes")?1:sxsm_eq(q,t[0],"$Elements")?2:sxsm_eq(q,t[0],"$PhysicalNames")?3:0;if(!mode)continue;uint64_t count;if(!sxsm_next(q,&line,t,128,&n,"#")||n!=1||!sxsm_number(q,t[0],&count)||count>1000000)return false;if(!sxsm_emit(q,mode==1?&sxsm_node_count:mode==2?&sxsm_element_count:&sxsm_value_count,t[0]))return false;
 for(uint64_t i=0;i<count;i++){if(q->c->count>=24000)return true;if(!sxsm_next(q,&line,t,128,&n,"#"))return false;if(mode==1){if(n!=4)return false;SM_EMIT(node_id,t[0]);if(!sxsm_xyz(q,t+1,0))return false;}else if(mode==2){uint64_t tags;if(n<4||!sxsm_number(q,t[2],&tags)||tags>16||tags>n-3)return false;SM_EMIT(element_id,t[0]);SM_EMIT(element_type,t[1]);SM_EMIT(tag_count,t[2]);if(!sxsm_each(q,t+3,(unsigned)tags,&sxsm_tag_value)||!sxsm_each(q,t+3+tags,n-3-(unsigned)tags,&sxsm_node_index))return false;}else{if(n<3)return false;SM_EMIT(dimension,t[0]);SM_EMIT(property_id,t[1]);SM_EMIT(name,((sxsm_token){t[2].a,line.a+line.z-t[2].a}));}}}return true;}
static bool sxsm_netgen(sxsm_cursor*q){sxsm_token line,t[40];unsigned n;if(!sxsm_next(q,&line,t,40,&n,"#"))return false;SM_EMIT(signature,t[0]);while(sxsm_next(q,&line,t,40,&n,"#")){if(q->c->count>=24000)return true;SM_EMIT(section,t[0]);if(sxsm_eq(q,t[0],"endmesh"))return true;unsigned mode=sxsm_eq(q,t[0],"dimension")?1:sxsm_eq(q,t[0],"geomtype")?2:sxsm_eq(q,t[0],"points")?3:sxsm_eq(q,t[0],"surfaceelements")?4:sxsm_eq(q,t[0],"volumeelements")?5:sxsm_eq(q,t[0],"edgesegments")?6:sxsm_eq(q,t[0],"edgesegmentsgi2")?7:sxsm_eq(q,t[0],"face_colours")?8:0;uint64_t count;if(!mode||!sxsm_next(q,&line,t,40,&n,"#")||n!=1||!sxsm_number(q,t[0],&count)||count>1000000)return false;if(!sxsm_emit(q,mode==1?&sxsm_dimension:mode==2?&sxsm_geometry_type:mode==3?&sxsm_node_count:mode==8?&sxsm_value_count:&sxsm_element_count,t[0]))return false;if(mode<=2)continue;
 for(uint64_t i=0;i<count;i++){if(q->c->count>=24000)return true;if(!sxsm_next(q,&line,t,40,&n,"#"))return false;if(mode==3){if(n!=3||!sxsm_xyz(q,t,0))return false;}else if(mode==4){if(n<6)return false;const sx_layout*cols[]={&sxsm_surface_id,&sxsm_boundary_id,&sxsm_inside_domain,&sxsm_outside_domain,&sxsm_component_count};if(!sxsm_fields(q,t,5,cols,5)||!sxsm_each(q,t+5,n-5,&sxsm_node_index))return false;}else if(mode==5){if(n<3)return false;SM_EMIT(region_id,t[0]);SM_EMIT(component_count,t[1]);if(!sxsm_each(q,t+2,n-2,&sxsm_node_index))return false;}else if(mode==8){if(n!=4)return false;SM_EMIT(surface_id,t[0]);const sx_layout*cols[]={&sxsm_red,&sxsm_green,&sxsm_blue};if(!sxsm_fields(q,t+1,3,cols,3))return false;}else{if(n!=(mode==6?4U:12U))return false;for(unsigned j=0;j<n;j++)if(!sxsm_emit(q,j==0?&sxsm_edge_region:j==1?&sxsm_integer_value:j==2||j==3?&sxsm_node_index:j==4||j==5?&sxsm_edge_triangle:j==6||j==7?&sxsm_edge_surface:j==9||j==11?&sxsm_edge_distance:&sxsm_edge_id,t[j]))return false;}}}return true;}
static bool sxsm_nastran(sxsm_cursor*q){sxsm_token line,t[24];unsigned n;while(sxsm_line(q,&line)){if(q->c->count>=24000)return true;int64_t p=0;bool comma=false;while(p<line.z&&q->b[line.a+p]!='$'){if(q->b[line.a+p]==',')comma=true;p++;}if(p<line.z){SM_EMIT(comment,((sxsm_token){line.a+p,line.z-p}));line.z=p;}sxsm_token trimmed=sxsm_trim(q,line);if(!trimmed.z)continue;if(trimmed.z>=5&&!xx_rt_memcmp(q->b+trimmed.a,"BEGIN",5)){SM_EMIT(keyword,line);continue;}if(sxsm_eq(q,trimmed,"ENDDATA")){SM_EMIT(keyword,line);continue;}
 if(comma)n=sxsm_csv(q,line,t,24);else{n=0;for(int64_t at=0;at<line.z;at+=8){if(n==24)return false;t[n++]=sxsm_trim(q,(sxsm_token){line.a+at,line.z-at<8?line.z-at:8});}}while(n&&!t[n-1].z)n--;if(n<2||n>24)return false;SM_EMIT(keyword,t[0]);bool grid=sxsm_eq(q,t[0],"GRID"),bar=sxsm_eq(q,t[0],"CBAR");if(grid){if(n<6)return false;SM_EMIT(node_id,t[1]);SM_EMIT(coordinate_system,t[2]);SM_EMIT(nastran_x,t[3]);SM_EMIT(nastran_y,t[4]);SM_EMIT(nastran_z,t[5]);const sx_layout*extra[]={&sxsm_displacement_coordinate_system,&sxsm_permanent_constraints,&sxsm_superelement_id};if(!sxsm_fields(q,t+6,n-6,extra,3))return false;}else{if(n<5||(bar&&n!=8))return false;SM_EMIT(element_id,t[1]);SM_EMIT(property_id,t[2]);if(!sxsm_each(q,t+3,n-3-(bar?3:0),&sxsm_node_index))return false;if(bar){if(n!=8)return false;SM_EMIT(bar_orientation_x,t[5]);SM_EMIT(bar_orientation_y,t[6]);SM_EMIT(bar_orientation_z,t[7]);}}}return true;}
static bool sxsm_abaqus(sxsm_cursor*q){sxsm_token line,t[32];unsigned n,mode=0;while(sxsm_line(q,&line)){if(q->c->count>=24000)return true;line=sxsm_trim(q,line);if(!line.z)continue;if(line.z>=2&&q->b[line.a]=='*'&&q->b[line.a+1]=='*'){SM_EMIT(comment,line);continue;}n=sxsm_csv(q,line,t,32);if(!n||n>32)return false;if(q->b[line.a]=='*'){SM_EMIT(section,t[0]);mode=sxsm_ci(q,t[0],"*heading")?1:sxsm_ci(q,t[0],"*node")?2:sxsm_ci(q,t[0],"*element")?3:sxsm_ci(q,t[0],"*nset")?4:sxsm_ci(q,t[0],"*elset")?5:sxsm_ci(q,t[0],"*surface")?6:0;for(unsigned i=1;i<n;i++){sxsm_token key,value;if(!sxsm_keyvalue(q,t[i],'=',&key,&value))return false;SM_EMIT(key,key);SM_EMIT(option_value,value);}continue;}
 if(mode==1){SM_EMIT(title,line);continue;}while(n&&!t[n-1].z)n--;if(!n)return false;if(mode==2){if(n!=4)return false;SM_EMIT(node_id,t[0]);if(!sxsm_xyz(q,t+1,0))return false;}else if(mode==3){SM_EMIT(element_id,t[0]);if(!sxsm_each(q,t+1,n-1,&sxsm_node_index))return false;}else if(mode==4||mode==5){if(!sxsm_each(q,t,n,mode==4?&sxsm_node_index:&sxsm_element_id))return false;}else if(mode==6){if(n!=2)return false;SM_EMIT(element_id,t[0]);SM_EMIT(surface_face,t[1]);}else return false;}return true;}
static bool sxsm_gocad(sxsm_cursor*q){sxsm_token line,t[128];unsigned n;while(sxsm_next(q,&line,t,128,&n,"#")){if(q->c->count>=24000)return true;SM_EMIT(keyword,t[0]);if(sxsm_eq(q,t[0],"VRTX")||sxsm_eq(q,t[0],"PVRTX")){if(n<5)return false;SM_EMIT(node_id,t[1]);if(!sxsm_xyz(q,t+2,0)||!sxsm_each(q,t+5,n-5,&sxsm_attribute_value))return false;}else if(sxsm_eq(q,t[0],"ATOM")){if(n!=3)return false;SM_EMIT(node_id,t[1]);SM_EMIT(node_index,t[2]);}else if(sxsm_eq(q,t[0],"TRGL")||sxsm_eq(q,t[0],"BSTONE")){if(!sxsm_each(q,t+1,n-1,&sxsm_node_index))return false;}else if(sxsm_eq(q,t[0],"BORDER")){if(n!=4)return false;SM_EMIT(boundary_id,t[1]);if(!sxsm_each(q,t+2,2,&sxsm_node_index))return false;}else if(sxsm_eq(q,t[0],"*solid*color:")){if(n!=5)return false;const sx_layout*cols[]={&sxsm_red,&sxsm_green,&sxsm_blue,&sxsm_alpha};if(!sxsm_fields(q,t+1,4,cols,4))return false;}else if(sxsm_eq(q,t[0],"ESIZES")){if(!sxsm_each(q,t+1,n-1,&sxsm_component_count))return false;}else if(sxsm_eq(q,t[0],"ZPOSITIVE")){if(n!=2)return false;SM_EMIT(z_direction,t[1]);}else if(n>1){SM_EMIT(text_value,((sxsm_token){t[1].a,line.a+line.z-t[1].a}));}}return true;}
/* Bounded physical token cursor for native lexer-based mesh grammars. */
static bool sxsm_lex(sxsm_cursor*q,sxsm_token*t,bool hash){while(q->p<q->n){if(++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;uint8_t ch=q->b[q->p];if(sxsm_space(ch)){q->p++;continue;}int64_t a=q->p;if((hash&&(ch=='#'||ch=='!'))||(ch=='/'&&q->n-q->p>=2&&q->b[q->p+1]=='/')){while(q->p<q->n&&q->b[q->p]!='\r'&&q->b[q->p]!='\n')q->p++;SM_EMIT(comment,((sxsm_token){a,q->p-a}));continue;}if(ch=='/'&&q->n-q->p>=2&&q->b[q->p+1]=='*'){q->p+=2;while(q->n-q->p>=2&&(q->b[q->p]!='*'||q->b[q->p+1]!='/'))q->p++;if(q->n-q->p<2)return false;q->p+=2;SM_EMIT(comment,((sxsm_token){a,q->p-a}));continue;}
 if(xx_rt_strchr("{}()[],;@",ch)){q->p++;*t=(sxsm_token){a,1};return true;}if(ch=='"'){q->p++;bool closed=false;while(q->p<q->n){ch=q->b[q->p++];if(ch=='"'){closed=true;break;}if(ch=='\\'&&q->p<q->n)q->p++;}if(!closed)return false;}else{while(q->p<q->n&&!sxsm_space(q->b[q->p])&&!xx_rt_strchr("{}()[],;@",q->b[q->p]))q->p++;}if(q->p==a)return false;*t=(sxsm_token){a,q->p-a};return true;}return false;}
static bool sxsm_expect(sxsm_cursor*q,const char*s,bool hash){sxsm_token t;return sxsm_lex(q,&t,hash)&&sxsm_eq(q,t,s);}
static bool sxsm_one(sxsm_cursor*q,const sx_layout*l,bool hash){sxsm_token t;return sxsm_lex(q,&t,hash)&&sxsm_emit(q,l,t);}
static bool sxsm_many(sxsm_cursor*q,const sx_layout*l,uint64_t count,bool hash){if(count>1000000)return false;for(uint64_t i=0;i<count;i++){if(q->c->count>=24000)return true;if(!sxsm_one(q,l,hash))return false;}return true;}
static bool sxsm_count(sxsm_cursor*q,const sx_layout*l,uint64_t*v,bool hash){sxsm_token t;return sxsm_lex(q,&t,hash)&&sxsm_number(q,t,v)&&*v<=1000000&&sxsm_emit(q,l,t);}
static bool sxsm_foam(sxsm_cursor*q){sxsm_token t,key,value;if(!sxsm_lex(q,&t,false))return false;SM_EMIT(signature,t);if(!sxsm_expect(q,"{",false))return false;while(sxsm_lex(q,&key,false)){if(sxsm_eq(q,key,"}"))break;SM_EMIT(key,key);if(!sxsm_lex(q,&value,false)||!sxsm_emit(q,sxsm_eq(q,key,"version")?&sxsm_real_value:&sxsm_option_value,value)||!sxsm_expect(q,";",false))return false;}
 uint64_t n;if(!sxsm_count(q,&sxsm_node_count,&n,false)||!sxsm_expect(q,"(",false))return false;for(uint64_t i=0;i<n;i++){if(q->c->count>=24000)return true;if(!sxsm_expect(q,"(",false)||!sxsm_one(q,&sxsm_coordinate_x,false)||!sxsm_one(q,&sxsm_coordinate_y,false)||!sxsm_one(q,&sxsm_coordinate_z,false)||!sxsm_expect(q,")",false))return false;}return sxsm_expect(q,")",false);}
static bool sxsm_medit(sxsm_cursor*q){sxsm_token t;uint64_t dim;if(!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);if(!sxsm_one(q,&sxsm_mesh_version,true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);if(!sxsm_count(q,&sxsm_dimension,&dim,true)||(dim!=2&&dim!=3))return false;while(sxsm_lex(q,&t,true)){if(q->c->count>=24000)return true;SM_EMIT(section,t);if(sxsm_eq(q,t,"End"))return true;bool vertices=sxsm_eq(q,t,"Vertices"),ref=sxsm_eq(q,t,"Corners")||sxsm_eq(q,t,"RequiredVertices");unsigned arity=vertices?(unsigned)dim:ref?1:sxsm_eq(q,t,"Edges")?2:sxsm_eq(q,t,"Triangles")?3:sxsm_eq(q,t,"Quadrilaterals")||sxsm_eq(q,t,"Tetrahedra")?4:sxsm_eq(q,t,"Hexahedra")?8:0;uint64_t n;if(!arity||!sxsm_count(q,vertices?&sxsm_node_count:&sxsm_element_count,&n,true))return false;for(uint64_t i=0;i<n;i++){if(q->c->count>=24000)return true;if(vertices){if(!sxsm_one(q,&sxsm_coordinate_x,true)||!sxsm_one(q,&sxsm_coordinate_y,true)||(dim==3&&!sxsm_one(q,&sxsm_coordinate_z,true)))return false;}else if(!sxsm_many(q,&sxsm_node_index,arity,true))return false;if(!ref&&!sxsm_one(q,&sxsm_label_id,true))return false;}}return true;}
static bool sxsm_amira(sxsm_cursor*q){sxsm_token line,t;if(!sxsm_line(q,&line))return false;SM_EMIT(signature,line);for(unsigned i=0;i<2;i++){if(!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);}if(!sxsm_many(q,&sxsm_axis_count,3,true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);if(!sxsm_expect(q,"{",true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(key,t);const sx_layout*cols[]={&sxsm_box_min_x,&sxsm_box_max_x,&sxsm_box_min_y,&sxsm_box_max_y,&sxsm_box_min_z,&sxsm_box_max_z};for(unsigned i=0;i<6;i++){if(!sxsm_one(q,cols[i],true))return false;}
 if(!sxsm_lex(q,&t,true))return false;if(sxsm_eq(q,t,",")){if(!sxsm_lex(q,&t,true))return false;}SM_EMIT(key,t);if(!sxsm_one(q,&sxsm_option_value,true)||!sxsm_expect(q,"}",true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);if(!sxsm_expect(q,"{",true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(type_name,t);if(!sxsm_lex(q,&t,true))return false;if(sxsm_eq(q,t,"[")){if(!sxsm_one(q,&sxsm_component_count,true)||!sxsm_expect(q,"]",true)||!sxsm_lex(q,&t,true))return false;}SM_EMIT(name,t);if(!sxsm_expect(q,"}",true))return false;for(unsigned i=0;i<2;i++){if(!sxsm_expect(q,"@",true)||!sxsm_one(q,&sxsm_entity_id,true))return false;}return true;}
static unsigned sxsm_gmv_arity(sxsm_cursor*q,sxsm_token t){return sxsm_eq(q,t,"line")?2:sxsm_eq(q,t,"tri")?3:sxsm_eq(q,t,"quad")||sxsm_eq(q,t,"tet")?4:sxsm_eq(q,t,"pyramid")?5:sxsm_eq(q,t,"prism")?6:sxsm_eq(q,t,"hex")?8:0;}
static bool sxsm_gmv_ascii(sxsm_cursor*q){sxsm_token t;uint64_t nodes=0,cells=0,n,location;if(!sxsm_lex(q,&t,true))return false;SM_EMIT(signature,t);if(!sxsm_one(q,&sxsm_encoding,true))return false;while(sxsm_lex(q,&t,true)){if(q->c->count>=24000)return true;SM_EMIT(section,t);if(sxsm_eq(q,t,"nodes")){if(!sxsm_count(q,&sxsm_node_count,&nodes,true))return false;const sx_layout*cols[]={&sxsm_coordinate_x,&sxsm_coordinate_y,&sxsm_coordinate_z};for(unsigned k=0;k<3;k++)if(!sxsm_many(q,cols[k],nodes,true))return false;}
 else if(sxsm_eq(q,t,"cells")){if(!sxsm_count(q,&sxsm_element_count,&cells,true))return false;for(uint64_t i=0;i<cells;i++){if(q->c->count>=24000)return true;if(!sxsm_lex(q,&t,true))return false;SM_EMIT(topology_name,t);unsigned arity=sxsm_gmv_arity(q,t);if(!arity||!sxsm_count(q,&sxsm_component_count,&n,true)||n!=arity||!sxsm_many(q,&sxsm_node_index,n,true))return false;}}
 else if(sxsm_eq(q,t,"material")){if(!sxsm_count(q,&sxsm_value_count,&n,true)||!sxsm_count(q,&sxsm_integer_value,&location,true)||location>1)return false;if(!sxsm_many(q,&sxsm_material_name,n,true)||!sxsm_many(q,&sxsm_material_id,location?nodes:cells,true))return false;}
 else if(sxsm_eq(q,t,"variable")){while(sxsm_lex(q,&t,true)){if(q->c->count>=24000)return true;if(sxsm_eq(q,t,"endvars")){SM_EMIT(keyword,t);break;}SM_EMIT(variable_name,t);if(!sxsm_count(q,&sxsm_integer_value,&location,true)||location>1||!sxsm_many(q,&sxsm_scalar_value,location?nodes:cells,true))return false;}}
 else if(sxsm_eq(q,t,"cycleno")){if(!sxsm_one(q,&sxsm_step_index,true))return false;}else if(sxsm_eq(q,t,"probtime")){if(!sxsm_one(q,&sxsm_simulation_time,true))return false;}else if(sxsm_eq(q,t,"endgmv"))return true;else return false;}return false;}
static bool sxsm_btake(sxsm_cursor*q,const sx_layout*l,uint64_t count){uint64_t z=(uint64_t)l->fields[0].size;if(!z||count>1000000||count>(uint64_t)(q->n-q->p)/z||xx_pd_is_stopped(q->c->pd))return false;for(uint64_t i=0;i<count;i++){if(q->c->count>=24000){q->p+=(int64_t)((count-i)*z);return true;}if(!sxsm_emit(q,l,(sxsm_token){q->p,(int64_t)z}))return false;q->p+=(int64_t)z;}return true;}
static bool sxsm_bcount(sxsm_cursor*q,const sx_layout*l,uint64_t*v){if(q->n-q->p<4)return false;*v=xx_data_get_u32(q->b+q->p,4,0,false);return *v<=1000000&&sxsm_btake(q,l,1);}
static bool sxsm_bname(sxsm_cursor*q,sxsm_token*t){if(q->n-q->p<8)return false;*t=sxsm_trim(q,(sxsm_token){q->p,8});return sxsm_btake(q,&sxsm_binary_name,1);}
static bool sxsm_gmv_binary(sxsm_cursor*q){uint64_t nodes=0,cells=0,n,loc,types; sxsm_token t;if(!sxsm_btake(q,&sxsm_binary_name,2))return false;while(q->p<q->n){if(q->c->count>=24000)return true;if(++q->work>2000000||!sxsm_bname(q,&t))return false;
 if(sxsm_eq(q,t,"nodes")){if(!sxsm_bcount(q,&sxsm_binary_count,&nodes))return false;for(unsigned k=0;k<3;k++)if(!sxsm_btake(q,&sxsm_binary_coordinate,nodes))return false;}
 else if(sxsm_eq(q,t,"cells")){if(!sxsm_bcount(q,&sxsm_binary_count,&cells))return false;for(uint64_t i=0;i<cells;i++){if(q->c->count>=24000)return true;if(!sxsm_bname(q,&t))return false;unsigned arity=sxsm_gmv_arity(q,t);if(!arity||!sxsm_bcount(q,&sxsm_binary_arity,&n)||n!=arity||!sxsm_btake(q,&sxsm_binary_node_index,n))return false;}}
 else if(sxsm_eq(q,t,"material")){if(!sxsm_bcount(q,&sxsm_binary_count,&n)||!sxsm_bcount(q,&sxsm_binary_location,&loc)||loc>1||!sxsm_btake(q,&sxsm_binary_name,n)||!sxsm_btake(q,&sxsm_binary_material_id,loc?nodes:cells))return false;}
 else if(sxsm_eq(q,t,"variable")){for(unsigned i=0;i<4096;i++){if(q->c->count>=24000)return true;if(!sxsm_bname(q,&t))return false;if(sxsm_eq(q,t,"endvars"))break;if(!sxsm_bcount(q,&sxsm_binary_location,&loc)||loc>1||!sxsm_btake(q,&sxsm_binary_scalar,loc?nodes:cells))return false;}}
 else if(sxsm_eq(q,t,"velocity")){if(!sxsm_bcount(q,&sxsm_binary_location,&loc)||loc>1)return false;for(unsigned k=0;k<3;k++)if(!sxsm_btake(q,&sxsm_binary_velocity,loc?nodes:cells))return false;}
 else if(sxsm_eq(q,t,"flags")){for(unsigned i=0;i<4096;i++){if(q->c->count>=24000)return true;if(!sxsm_bname(q,&t))return false;if(sxsm_eq(q,t,"endflag"))break;if(!sxsm_bcount(q,&sxsm_binary_count,&types)||!sxsm_bcount(q,&sxsm_binary_location,&loc)||loc>1||!sxsm_btake(q,&sxsm_binary_name,types)||!sxsm_btake(q,&sxsm_binary_flag_value,loc?nodes:cells))return false;}}
 else if(sxsm_eq(q,t,"polygons")){for(unsigned i=0;i<1000000;i++){if(q->c->count>=24000)return true;if(q->n-q->p<8)return false;t=sxsm_trim(q,(sxsm_token){q->p,8});if(sxsm_eq(q,t,"endpoly")){if(!sxsm_btake(q,&sxsm_binary_name,1))return false;break;}if(!sxsm_bcount(q,&sxsm_binary_material_id,&n)||!sxsm_bcount(q,&sxsm_binary_count,&n)||n>64)return false;for(unsigned k=0;k<3;k++)if(!sxsm_btake(q,&sxsm_binary_coordinate,n))return false;}}
 else if(sxsm_eq(q,t,"cycleno")){if(!sxsm_btake(q,&sxsm_binary_cycle,1))return false;}else if(sxsm_eq(q,t,"probtime")){if(!sxsm_btake(q,&sxsm_binary_time,1))return false;}else if(sxsm_eq(q,t,"endgmv"))return true;else return false;}return false;}
static bool sxsm_gmv(sxsm_cursor*q){return q->n>=16&&!xx_rt_memcmp(q->b+8,"ieee    ",8)?sxsm_gmv_binary(q):sxsm_gmv_ascii(q);}
static int sxsm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxsm_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsm_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}

static bool sx_sciencemesh_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_NRRD:case XX_FILE_TYPE_METAIMAGE:case XX_FILE_TYPE_VTK_LEGACY:case XX_FILE_TYPE_MICROSCOPY_ICS:case XX_FILE_TYPE_TEKTRONIX_ISF:case XX_FILE_TYPE_PHYLO_NEXUS:case XX_FILE_TYPE_PHYLO_NEWICK:case XX_FILE_TYPE_OPENDX_FIELD:case XX_FILE_TYPE_GMSH_MSH:case XX_FILE_TYPE_NETGEN_VOL:case XX_FILE_TYPE_JCAMP_DX:case XX_FILE_TYPE_SURFER_GRID:case XX_FILE_TYPE_HARWELL_BOEING:case XX_FILE_TYPE_OPENFOAM_POINTS:case XX_FILE_TYPE_MEDIT_MESH:case XX_FILE_TYPE_GOCAD_MODEL:case XX_FILE_TYPE_NASTRAN_BULK:case XX_FILE_TYPE_ABAQUS_INPUT:case XX_FILE_TYPE_GMV_MESH:case XX_FILE_TYPE_AMIRA_MESH:case XX_FILE_TYPE_TETGEN_MESH:return true;default:return false;}}
static bool sx_sciencemesh_build(sx_context*c){if(!c||!c->f||c->size<1||c->size>67108864||xx_pd_is_stopped(c->pd))return false;if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxsm_cursor cursor={c,b,c->size,0,0},*q=&cursor;xx_file_type_t type=c->f->file_type;if(ok)switch(type){
case XX_FILE_TYPE_NRRD:ok=sxsm_nrrd_meta(q,false);break;
case XX_FILE_TYPE_METAIMAGE:ok=sxsm_nrrd_meta(q,true);break;
case XX_FILE_TYPE_VTK_LEGACY:ok=sxsm_vtk(q);break;
case XX_FILE_TYPE_MICROSCOPY_ICS:ok=sxsm_ics(q);break;
case XX_FILE_TYPE_TEKTRONIX_ISF:ok=sxsm_isf(q);break;
case XX_FILE_TYPE_PHYLO_NEXUS:ok=sxsm_phylo(q,true);break;
case XX_FILE_TYPE_PHYLO_NEWICK:ok=sxsm_phylo(q,false);break;
case XX_FILE_TYPE_OPENDX_FIELD:ok=sxsm_dx(q);break;
case XX_FILE_TYPE_GMSH_MSH:ok=sxsm_gmsh(q);break;
case XX_FILE_TYPE_NETGEN_VOL:ok=sxsm_netgen(q);break;
case XX_FILE_TYPE_JCAMP_DX:ok=sxsm_jcamp(q);break;
case XX_FILE_TYPE_SURFER_GRID:ok=sxsm_surfer(q);break;
case XX_FILE_TYPE_HARWELL_BOEING:ok=sxsm_hb(q);break;
case XX_FILE_TYPE_OPENFOAM_POINTS:ok=sxsm_foam(q);break;
case XX_FILE_TYPE_MEDIT_MESH:ok=sxsm_medit(q);break;
case XX_FILE_TYPE_GOCAD_MODEL:ok=sxsm_gocad(q);break;
case XX_FILE_TYPE_NASTRAN_BULK:ok=sxsm_nastran(q);break;
case XX_FILE_TYPE_ABAQUS_INPUT:ok=sxsm_abaqus(q);break;
case XX_FILE_TYPE_GMV_MESH:ok=sxsm_gmv(q);break;
case XX_FILE_TYPE_AMIRA_MESH:ok=sxsm_amira(q);break;
case XX_FILE_TYPE_TETGEN_MESH:ok=sxsm_tetgen(q);break;
default:ok=false;break;}xx_mem_free(b);return ok&&sxsm_finish(c);}
#undef SM_EMIT
#undef SM_COL
