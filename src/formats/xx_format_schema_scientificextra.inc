/* SPDX-License-Identifier: MIT
 * Scientific file metadata. Scope: docs/data_struct_scientificextra_scope.txt. */
static const xx_data_struct_field_desc sxscx_aedat2_event_fields[] = {
    SX_FIELD("event_address","int32",0,4,SX_FLAGS),
    SX_FIELD("timestamp","int32",4,4,SX_NONE),
};
static const sx_layout sxscx_aedat2_event = {UINT32_C(0x60310001),"aedat2_event",sxscx_aedat2_event_fields,SX_COUNT(sxscx_aedat2_event_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_axona_timestamp_fields[] = {
    SX_FIELD("timestamp","int32",0,4,SX_NONE),
};
static const sx_layout sxscx_axona_timestamp = {UINT32_C(0x60310002),"axona_timestamp",sxscx_axona_timestamp_fields,SX_COUNT(sxscx_axona_timestamp_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_axona_end_fields[] = {
    SX_FIELD("marker","char[12]",0,12,SX_SIGNATURE),
};
static const sx_layout sxscx_axona_end = {UINT32_C(0x60310003),"axona_end",sxscx_axona_end_fields,SX_COUNT(sxscx_axona_end_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_iplab_header_le_fields[] = {
    SX_FIELD("byte_order","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_size","uint32",4,4,SX_SIZE),
    SX_FIELD("version","char[4]",8,4,SX_ID),
    SX_FIELD("data_tag","char[4]",12,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",16,4,SX_SIZE),
    SX_FIELD("width","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("channels","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("z_planes","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("time_points","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("sample_type","uint32",40,4,SX_ID),
};
static const sx_layout sxscx_iplab_header_le = {UINT32_C(0x60310004),"iplab_header_le",sxscx_iplab_header_le_fields,SX_COUNT(sxscx_iplab_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_iplab_terminator_le_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxscx_iplab_terminator_le = {UINT32_C(0x60310005),"iplab_terminator_le",sxscx_iplab_terminator_le_fields,SX_COUNT(sxscx_iplab_terminator_le_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_dsn6_header_le_fields[] = {
    SX_FIELD("origin_x","int16",0,2,SX_NONE),
    SX_FIELD("origin_y","int16",2,2,SX_NONE),
    SX_FIELD("origin_z","int16",4,2,SX_NONE),
    SX_FIELD("extent_x","int16",6,2,SX_COUNT_PROP),
    SX_FIELD("extent_y","int16",8,2,SX_COUNT_PROP),
    SX_FIELD("extent_z","int16",10,2,SX_COUNT_PROP),
    SX_FIELD("grid_x","int16",12,2,SX_COUNT_PROP),
    SX_FIELD("grid_y","int16",14,2,SX_COUNT_PROP),
    SX_FIELD("grid_z","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("cell_a","int16",18,2,SX_NONE),
    SX_FIELD("cell_b","int16",20,2,SX_NONE),
    SX_FIELD("cell_c","int16",22,2,SX_NONE),
    SX_FIELD("cell_alpha","int16",24,2,SX_NONE),
    SX_FIELD("cell_beta","int16",26,2,SX_NONE),
    SX_FIELD("cell_gamma","int16",28,2,SX_NONE),
    SX_FIELD("density_multiplier","int16",30,2,SX_NONE),
    SX_FIELD("density_bias","int16",32,2,SX_NONE),
    SX_FIELD("cell_multiplier","int16",34,2,SX_NONE),
    SX_FIELD("byte_order_marker","int16",36,2,SX_ID),
    SX_FIELD("reserved","uint8[474]",38,474,SX_RESERVED),
};
static const sx_layout sxscx_dsn6_header_le = {UINT32_C(0x60310006),"dsn6_header_le",sxscx_dsn6_header_le_fields,SX_COUNT(sxscx_dsn6_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_iplab_header_be_fields[] = {
    SX_FIELD("byte_order","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_size","uint32",4,4,SX_SIZE),
    SX_FIELD("version","char[4]",8,4,SX_ID),
    SX_FIELD("data_tag","char[4]",12,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",16,4,SX_SIZE),
    SX_FIELD("width","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("channels","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("z_planes","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("time_points","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("sample_type","uint32",40,4,SX_ID),
};
static const sx_layout sxscx_iplab_header_be = {UINT32_C(0x60310007),"iplab_header_be",sxscx_iplab_header_be_fields,SX_COUNT(sxscx_iplab_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_iplab_terminator_be_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxscx_iplab_terminator_be = {UINT32_C(0x60310008),"iplab_terminator_be",sxscx_iplab_terminator_be_fields,SX_COUNT(sxscx_iplab_terminator_be_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dsn6_header_be_fields[] = {
    SX_FIELD("origin_x","int16",0,2,SX_NONE),
    SX_FIELD("origin_y","int16",2,2,SX_NONE),
    SX_FIELD("origin_z","int16",4,2,SX_NONE),
    SX_FIELD("extent_x","int16",6,2,SX_COUNT_PROP),
    SX_FIELD("extent_y","int16",8,2,SX_COUNT_PROP),
    SX_FIELD("extent_z","int16",10,2,SX_COUNT_PROP),
    SX_FIELD("grid_x","int16",12,2,SX_COUNT_PROP),
    SX_FIELD("grid_y","int16",14,2,SX_COUNT_PROP),
    SX_FIELD("grid_z","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("cell_a","int16",18,2,SX_NONE),
    SX_FIELD("cell_b","int16",20,2,SX_NONE),
    SX_FIELD("cell_c","int16",22,2,SX_NONE),
    SX_FIELD("cell_alpha","int16",24,2,SX_NONE),
    SX_FIELD("cell_beta","int16",26,2,SX_NONE),
    SX_FIELD("cell_gamma","int16",28,2,SX_NONE),
    SX_FIELD("density_multiplier","int16",30,2,SX_NONE),
    SX_FIELD("density_bias","int16",32,2,SX_NONE),
    SX_FIELD("cell_multiplier","int16",34,2,SX_NONE),
    SX_FIELD("byte_order_marker","int16",36,2,SX_ID),
    SX_FIELD("reserved","uint8[474]",38,474,SX_RESERVED),
};
static const sx_layout sxscx_dsn6_header_be = {UINT32_C(0x60310009),"dsn6_header_be",sxscx_dsn6_header_be_fields,SX_COUNT(sxscx_dsn6_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_brix_header_fields[] = {
    SX_FIELD("descriptor_text","char[512]",0,512,SX_STRING),
};
static const sx_layout sxscx_brix_header = {UINT32_C(0x6031000a),"brix_header",sxscx_brix_header_fields,SX_COUNT(sxscx_brix_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_mtz_prefix_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_word_index","uint32",4,4,SX_NONE),
    SX_FIELD("machine_stamp","uint8[4]",8,4,SX_ID),
    SX_FIELD("reserved","uint8[68]",12,68,SX_RESERVED),
};
static const sx_layout sxscx_mtz_prefix = {UINT32_C(0x6031000b),"mtz_prefix",sxscx_mtz_prefix_fields,SX_COUNT(sxscx_mtz_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_mtz_header_record_fields[] = {
    SX_FIELD("record_text","char[80]",0,80,SX_STRING),
};
static const sx_layout sxscx_mtz_header_record = {UINT32_C(0x6031000c),"mtz_header_record",sxscx_mtz_header_record_fields,SX_COUNT(sxscx_mtz_header_record_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_header_fields[] = {
    SX_FIELD("encoding","char[80]",0,80,SX_SIGNATURE),
    SX_FIELD("description1","char[80]",80,80,SX_STRING),
    SX_FIELD("description2","char[80]",160,80,SX_STRING),
    SX_FIELD("node_id_mode","char[80]",240,80,SX_ID),
    SX_FIELD("element_id_mode","char[80]",320,80,SX_ID),
};
static const sx_layout sxscx_ensight_header = {UINT32_C(0x6031000d),"ensight_header",sxscx_ensight_header_fields,SX_COUNT(sxscx_ensight_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_part_fields[] = {
    SX_FIELD("part_marker","char[80]",0,80,SX_SIGNATURE),
    SX_FIELD("part_id","int32",80,4,SX_ID),
    SX_FIELD("description","char[80]",84,80,SX_STRING),
    SX_FIELD("coordinates_marker","char[80]",164,80,SX_SIGNATURE),
    SX_FIELD("node_count","int32",244,4,SX_COUNT_PROP),
};
static const sx_layout sxscx_ensight_part = {UINT32_C(0x6031000e),"ensight_part",sxscx_ensight_part_fields,SX_COUNT(sxscx_ensight_part_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_elements_fields[] = {
    SX_FIELD("element_type","char[80]",0,80,SX_ID),
    SX_FIELD("element_count","int32",80,4,SX_COUNT_PROP),
};
static const sx_layout sxscx_ensight_elements = {UINT32_C(0x6031000f),"ensight_elements",sxscx_ensight_elements_fields,SX_COUNT(sxscx_ensight_elements_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_given_id_fields[] = {
    SX_FIELD("identifier","int32",0,4,SX_ID),
};
static const sx_layout sxscx_ensight_given_id = {UINT32_C(0x60310010),"ensight_given_id",sxscx_ensight_given_id_fields,SX_COUNT(sxscx_ensight_given_id_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_coordinate_fields[] = {
    SX_FIELD("coordinate","float32",0,4,SX_NONE),
};
static const sx_layout sxscx_ensight_coordinate = {UINT32_C(0x60310011),"ensight_coordinate",sxscx_ensight_coordinate_fields,SX_COUNT(sxscx_ensight_coordinate_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_connectivity_fields[] = {
    SX_FIELD("local_node_index","int32",0,4,SX_NONE),
};
static const sx_layout sxscx_ensight_connectivity = {UINT32_C(0x60310012),"ensight_connectivity",sxscx_ensight_connectivity_fields,SX_COUNT(sxscx_ensight_connectivity_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_dted_uhl_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("version","char[1]",3,1,SX_ID),
    SX_FIELD("longitude_origin","char[8]",4,8,SX_STRING),
    SX_FIELD("latitude_origin","char[8]",12,8,SX_STRING),
    SX_FIELD("longitude_interval","ascii_decimal[4]",20,4,SX_NONE),
    SX_FIELD("latitude_interval","ascii_decimal[4]",24,4,SX_NONE),
    SX_FIELD("absolute_vertical_accuracy","char[4]",28,4,SX_STRING),
    SX_FIELD("security_code","char[3]",32,3,SX_STRING),
    SX_FIELD("unique_reference","char[12]",35,12,SX_STRING),
    SX_FIELD("longitude_lines","ascii_decimal[4]",47,4,SX_COUNT_PROP),
    SX_FIELD("latitude_points","ascii_decimal[4]",51,4,SX_COUNT_PROP),
    SX_FIELD("multiple_accuracy","char[1]",55,1,SX_ID),
    SX_FIELD("reserved","char[24]",56,24,SX_RESERVED),
};
static const sx_layout sxscx_dted_uhl = {UINT32_C(0x60310013),"dted_uhl",sxscx_dted_uhl_fields,SX_COUNT(sxscx_dted_uhl_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dted_dsi_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("security_code","char[1]",3,1,SX_STRING),
    SX_FIELD("security_control","char[2]",4,2,SX_STRING),
    SX_FIELD("security_handling","char[27]",6,27,SX_STRING),
    SX_FIELD("opaque_21","uint8[26]",33,26,SX_NONE),
    SX_FIELD("series_designator","char[5]",59,5,SX_STRING),
    SX_FIELD("unique_reference","char[15]",64,15,SX_STRING),
    SX_FIELD("opaque_4f","uint8[8]",79,8,SX_NONE),
    SX_FIELD("data_edition","char[2]",87,2,SX_STRING),
    SX_FIELD("merge_version","char[1]",89,1,SX_STRING),
    SX_FIELD("maintenance_date","char[4]",90,4,SX_STRING),
    SX_FIELD("merge_date","char[4]",94,4,SX_STRING),
    SX_FIELD("maintenance_description","char[4]",98,4,SX_STRING),
    SX_FIELD("producer","char[8]",102,8,SX_STRING),
    SX_FIELD("opaque_6e","uint8[16]",110,16,SX_NONE),
    SX_FIELD("product_specification","char[9]",126,9,SX_STRING),
    SX_FIELD("specification_amendment","char[2]",135,2,SX_STRING),
    SX_FIELD("specification_date","char[4]",137,4,SX_STRING),
    SX_FIELD("vertical_datum","char[3]",141,3,SX_STRING),
    SX_FIELD("horizontal_datum","char[5]",144,5,SX_STRING),
    SX_FIELD("digitizing_system","char[10]",149,10,SX_STRING),
    SX_FIELD("compilation_date","char[4]",159,4,SX_STRING),
    SX_FIELD("opaque_a3","uint8[22]",163,22,SX_NONE),
    SX_FIELD("origin_latitude","char[9]",185,9,SX_STRING),
    SX_FIELD("origin_longitude","char[10]",194,10,SX_STRING),
    SX_FIELD("southwest_latitude","char[7]",204,7,SX_STRING),
    SX_FIELD("southwest_longitude","char[8]",211,8,SX_STRING),
    SX_FIELD("northwest_latitude","char[7]",219,7,SX_STRING),
    SX_FIELD("northwest_longitude","char[8]",226,8,SX_STRING),
    SX_FIELD("northeast_latitude","char[7]",234,7,SX_STRING),
    SX_FIELD("northeast_longitude","char[8]",241,8,SX_STRING),
    SX_FIELD("southeast_latitude","char[7]",249,7,SX_STRING),
    SX_FIELD("southeast_longitude","char[8]",256,8,SX_STRING),
    SX_FIELD("orientation","char[9]",264,9,SX_STRING),
    SX_FIELD("latitude_interval","char[4]",273,4,SX_STRING),
    SX_FIELD("longitude_interval","char[4]",277,4,SX_STRING),
    SX_FIELD("latitude_points","char[4]",281,4,SX_STRING),
    SX_FIELD("longitude_lines","char[4]",285,4,SX_STRING),
    SX_FIELD("partial_cell","char[2]",289,2,SX_STRING),
    SX_FIELD("opaque_123","uint8[357]",291,357,SX_NONE),
};
static const sx_layout sxscx_dted_dsi = {UINT32_C(0x60310014),"dted_dsi",sxscx_dted_dsi_fields,SX_COUNT(sxscx_dted_dsi_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dted_acc_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("absolute_horizontal_accuracy","char[4]",3,4,SX_STRING),
    SX_FIELD("absolute_vertical_accuracy","char[4]",7,4,SX_STRING),
    SX_FIELD("relative_horizontal_accuracy","char[4]",11,4,SX_STRING),
    SX_FIELD("relative_vertical_accuracy","char[4]",15,4,SX_STRING),
    SX_FIELD("opaque_13","uint8[36]",19,36,SX_NONE),
    SX_FIELD("accuracy_subregions","char[2]",55,2,SX_STRING),
    SX_FIELD("opaque_39","uint8[2643]",57,2643,SX_NONE),
};
static const sx_layout sxscx_dted_acc = {UINT32_C(0x60310015),"dted_acc",sxscx_dted_acc_fields,SX_COUNT(sxscx_dted_acc_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dted_column_header_fields[] = {
    SX_FIELD("sentinel","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("block_count","uint24",1,3,SX_COUNT_PROP),
    SX_FIELD("longitude_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("latitude_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxscx_dted_column_header = {UINT32_C(0x60310016),"dted_column_header",sxscx_dted_column_header_fields,SX_COUNT(sxscx_dted_column_header_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dted_column_checksum_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxscx_dted_column_checksum = {UINT32_C(0x60310017),"dted_column_checksum",sxscx_dted_column_checksum_fields,SX_COUNT(sxscx_dted_column_checksum_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_fgb_prefix_fields[] = {
    SX_FIELD("magic","uint8[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxscx_fgb_prefix = {UINT32_C(0x60310018),"fgb_prefix",sxscx_fgb_prefix_fields,SX_COUNT(sxscx_fgb_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_root_fields[] = {
    SX_FIELD("root_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_root = {UINT32_C(0x60310019),"fgb_root",sxscx_fgb_root_fields,SX_COUNT(sxscx_fgb_root_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_feature_size_fields[] = {
    SX_FIELD("feature_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxscx_fgb_feature_size = {UINT32_C(0x6031001a),"fgb_feature_size",sxscx_fgb_feature_size_fields,SX_COUNT(sxscx_fgb_feature_size_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_table_header_fields[] = {
    SX_FIELD("vtable_displacement","int32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_table_header = {UINT32_C(0x6031001b),"fgb_table_header",sxscx_fgb_table_header_fields,SX_COUNT(sxscx_fgb_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_vtable_header_fields[] = {
    SX_FIELD("vtable_size","uint16",0,2,SX_SIZE),
    SX_FIELD("object_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxscx_fgb_vtable_header = {UINT32_C(0x6031001c),"fgb_vtable_header",sxscx_fgb_vtable_header_fields,SX_COUNT(sxscx_fgb_vtable_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_vtable_entry_fields[] = {
    SX_FIELD("member_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxscx_fgb_vtable_entry = {UINT32_C(0x6031001d),"fgb_vtable_entry",sxscx_fgb_vtable_entry_fields,SX_COUNT(sxscx_fgb_vtable_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_vector_header_fields[] = {
    SX_FIELD("element_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxscx_fgb_vector_header = {UINT32_C(0x6031001e),"fgb_vector_header",sxscx_fgb_vector_header_fields,SX_COUNT(sxscx_fgb_vector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_string_header_fields[] = {
    SX_FIELD("utf8_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxscx_fgb_string_header = {UINT32_C(0x6031001f),"fgb_string_header",sxscx_fgb_string_header_fields,SX_COUNT(sxscx_fgb_string_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_vector_reference_fields[] = {
    SX_FIELD("relative_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_vector_reference = {UINT32_C(0x60310020),"fgb_vector_reference",sxscx_fgb_vector_reference_fields,SX_COUNT(sxscx_fgb_vector_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_end_fields[] = {
    SX_FIELD("point_end_index","uint32",0,4,SX_NONE),
};
static const sx_layout sxscx_fgb_geometry_end = {UINT32_C(0x60310021),"fgb_geometry_end",sxscx_fgb_geometry_end_fields,SX_COUNT(sxscx_fgb_geometry_end_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_coordinate_fields[] = {
    SX_FIELD("coordinate","float64",0,8,SX_NONE),
};
static const sx_layout sxscx_fgb_coordinate = {UINT32_C(0x60310022),"fgb_coordinate",sxscx_fgb_coordinate_fields,SX_COUNT(sxscx_fgb_coordinate_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_time_fields[] = {
    SX_FIELD("time_nanoseconds","uint64",0,8,SX_NONE),
};
static const sx_layout sxscx_fgb_geometry_time = {UINT32_C(0x60310023),"fgb_geometry_time",sxscx_fgb_geometry_time_fields,SX_COUNT(sxscx_fgb_geometry_time_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_index_internal_fields[] = {
    SX_FIELD("min_x","float64",0,8,SX_NONE),
    SX_FIELD("min_y","float64",8,8,SX_NONE),
    SX_FIELD("max_x","float64",16,8,SX_NONE),
    SX_FIELD("max_y","float64",24,8,SX_NONE),
    SX_FIELD("child_node_index","uint64",32,8,SX_NONE),
};
static const sx_layout sxscx_fgb_index_internal = {UINT32_C(0x60310024),"fgb_index_internal",sxscx_fgb_index_internal_fields,SX_COUNT(sxscx_fgb_index_internal_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_index_leaf_fields[] = {
    SX_FIELD("min_x","float64",0,8,SX_NONE),
    SX_FIELD("min_y","float64",8,8,SX_NONE),
    SX_FIELD("max_x","float64",16,8,SX_NONE),
    SX_FIELD("max_y","float64",24,8,SX_NONE),
    SX_FIELD("feature_offset","uint64",32,8,SX_OFFSET),
};
static const sx_layout sxscx_fgb_index_leaf = {UINT32_C(0x60310025),"fgb_index_leaf",sxscx_fgb_index_leaf_fields,SX_COUNT(sxscx_fgb_index_leaf_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_name_fields[] = {
    SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_header_name = {UINT32_C(0x60310026),"fgb_header_name",sxscx_fgb_header_name_fields,SX_COUNT(sxscx_fgb_header_name_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_envelope_fields[] = {
    SX_FIELD("envelope_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_header_envelope = {UINT32_C(0x60310027),"fgb_header_envelope",sxscx_fgb_header_envelope_fields,SX_COUNT(sxscx_fgb_header_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_geometry_type_fields[] = {
    SX_FIELD("geometry_type","uint8",0,1,SX_ID),
};
static const sx_layout sxscx_fgb_header_geometry_type = {UINT32_C(0x60310028),"fgb_header_geometry_type",sxscx_fgb_header_geometry_type_fields,SX_COUNT(sxscx_fgb_header_geometry_type_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_has_z_fields[] = {
    SX_FIELD("has_z","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxscx_fgb_header_has_z = {UINT32_C(0x60310029),"fgb_header_has_z",sxscx_fgb_header_has_z_fields,SX_COUNT(sxscx_fgb_header_has_z_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_has_m_fields[] = {
    SX_FIELD("has_m","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxscx_fgb_header_has_m = {UINT32_C(0x6031002a),"fgb_header_has_m",sxscx_fgb_header_has_m_fields,SX_COUNT(sxscx_fgb_header_has_m_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_has_t_fields[] = {
    SX_FIELD("has_t","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxscx_fgb_header_has_t = {UINT32_C(0x6031002b),"fgb_header_has_t",sxscx_fgb_header_has_t_fields,SX_COUNT(sxscx_fgb_header_has_t_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_has_tm_fields[] = {
    SX_FIELD("has_tm","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxscx_fgb_header_has_tm = {UINT32_C(0x6031002c),"fgb_header_has_tm",sxscx_fgb_header_has_tm_fields,SX_COUNT(sxscx_fgb_header_has_tm_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_columns_fields[] = {
    SX_FIELD("columns_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_header_columns = {UINT32_C(0x6031002d),"fgb_header_columns",sxscx_fgb_header_columns_fields,SX_COUNT(sxscx_fgb_header_columns_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_features_count_fields[] = {
    SX_FIELD("features_count","uint64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxscx_fgb_header_features_count = {UINT32_C(0x6031002e),"fgb_header_features_count",sxscx_fgb_header_features_count_fields,SX_COUNT(sxscx_fgb_header_features_count_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_index_node_size_fields[] = {
    SX_FIELD("index_node_size","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxscx_fgb_header_index_node_size = {UINT32_C(0x6031002f),"fgb_header_index_node_size",sxscx_fgb_header_index_node_size_fields,SX_COUNT(sxscx_fgb_header_index_node_size_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_crs_fields[] = {
    SX_FIELD("crs_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_header_crs = {UINT32_C(0x60310030),"fgb_header_crs",sxscx_fgb_header_crs_fields,SX_COUNT(sxscx_fgb_header_crs_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_title_fields[] = {
    SX_FIELD("title_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_header_title = {UINT32_C(0x60310031),"fgb_header_title",sxscx_fgb_header_title_fields,SX_COUNT(sxscx_fgb_header_title_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_description_fields[] = {
    SX_FIELD("description_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_header_description = {UINT32_C(0x60310032),"fgb_header_description",sxscx_fgb_header_description_fields,SX_COUNT(sxscx_fgb_header_description_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_metadata_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_header_metadata = {UINT32_C(0x60310033),"fgb_header_metadata",sxscx_fgb_header_metadata_fields,SX_COUNT(sxscx_fgb_header_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_name_fields[] = {
    SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_column_name = {UINT32_C(0x60310034),"fgb_column_name",sxscx_fgb_column_name_fields,SX_COUNT(sxscx_fgb_column_name_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_type_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
};
static const sx_layout sxscx_fgb_column_type = {UINT32_C(0x60310035),"fgb_column_type",sxscx_fgb_column_type_fields,SX_COUNT(sxscx_fgb_column_type_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_title_fields[] = {
    SX_FIELD("title_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_column_title = {UINT32_C(0x60310036),"fgb_column_title",sxscx_fgb_column_title_fields,SX_COUNT(sxscx_fgb_column_title_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_description_fields[] = {
    SX_FIELD("description_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_column_description = {UINT32_C(0x60310037),"fgb_column_description",sxscx_fgb_column_description_fields,SX_COUNT(sxscx_fgb_column_description_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_width_fields[] = {
    SX_FIELD("width","int32",0,4,SX_NONE),
};
static const sx_layout sxscx_fgb_column_width = {UINT32_C(0x60310038),"fgb_column_width",sxscx_fgb_column_width_fields,SX_COUNT(sxscx_fgb_column_width_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_precision_fields[] = {
    SX_FIELD("precision","int32",0,4,SX_NONE),
};
static const sx_layout sxscx_fgb_column_precision = {UINT32_C(0x60310039),"fgb_column_precision",sxscx_fgb_column_precision_fields,SX_COUNT(sxscx_fgb_column_precision_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_scale_fields[] = {
    SX_FIELD("scale","int32",0,4,SX_NONE),
};
static const sx_layout sxscx_fgb_column_scale = {UINT32_C(0x6031003a),"fgb_column_scale",sxscx_fgb_column_scale_fields,SX_COUNT(sxscx_fgb_column_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_nullable_fields[] = {
    SX_FIELD("nullable","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxscx_fgb_column_nullable = {UINT32_C(0x6031003b),"fgb_column_nullable",sxscx_fgb_column_nullable_fields,SX_COUNT(sxscx_fgb_column_nullable_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_unique_fields[] = {
    SX_FIELD("unique","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxscx_fgb_column_unique = {UINT32_C(0x6031003c),"fgb_column_unique",sxscx_fgb_column_unique_fields,SX_COUNT(sxscx_fgb_column_unique_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_primary_key_fields[] = {
    SX_FIELD("primary_key","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxscx_fgb_column_primary_key = {UINT32_C(0x6031003d),"fgb_column_primary_key",sxscx_fgb_column_primary_key_fields,SX_COUNT(sxscx_fgb_column_primary_key_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_metadata_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_column_metadata = {UINT32_C(0x6031003e),"fgb_column_metadata",sxscx_fgb_column_metadata_fields,SX_COUNT(sxscx_fgb_column_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_org_fields[] = {
    SX_FIELD("org_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_crs_org = {UINT32_C(0x6031003f),"fgb_crs_org",sxscx_fgb_crs_org_fields,SX_COUNT(sxscx_fgb_crs_org_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_code_fields[] = {
    SX_FIELD("code","int32",0,4,SX_ID),
};
static const sx_layout sxscx_fgb_crs_code = {UINT32_C(0x60310040),"fgb_crs_code",sxscx_fgb_crs_code_fields,SX_COUNT(sxscx_fgb_crs_code_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_name_fields[] = {
    SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_crs_name = {UINT32_C(0x60310041),"fgb_crs_name",sxscx_fgb_crs_name_fields,SX_COUNT(sxscx_fgb_crs_name_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_description_fields[] = {
    SX_FIELD("description_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_crs_description = {UINT32_C(0x60310042),"fgb_crs_description",sxscx_fgb_crs_description_fields,SX_COUNT(sxscx_fgb_crs_description_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_wkt_fields[] = {
    SX_FIELD("wkt_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_crs_wkt = {UINT32_C(0x60310043),"fgb_crs_wkt",sxscx_fgb_crs_wkt_fields,SX_COUNT(sxscx_fgb_crs_wkt_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_code_string_fields[] = {
    SX_FIELD("code_string_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_crs_code_string = {UINT32_C(0x60310044),"fgb_crs_code_string",sxscx_fgb_crs_code_string_fields,SX_COUNT(sxscx_fgb_crs_code_string_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_ends_fields[] = {
    SX_FIELD("ends_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_geometry_ends = {UINT32_C(0x60310045),"fgb_geometry_ends",sxscx_fgb_geometry_ends_fields,SX_COUNT(sxscx_fgb_geometry_ends_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_xy_fields[] = {
    SX_FIELD("xy_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_geometry_xy = {UINT32_C(0x60310046),"fgb_geometry_xy",sxscx_fgb_geometry_xy_fields,SX_COUNT(sxscx_fgb_geometry_xy_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_z_fields[] = {
    SX_FIELD("z_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_geometry_z = {UINT32_C(0x60310047),"fgb_geometry_z",sxscx_fgb_geometry_z_fields,SX_COUNT(sxscx_fgb_geometry_z_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_m_fields[] = {
    SX_FIELD("m_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_geometry_m = {UINT32_C(0x60310048),"fgb_geometry_m",sxscx_fgb_geometry_m_fields,SX_COUNT(sxscx_fgb_geometry_m_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_t_fields[] = {
    SX_FIELD("t_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_geometry_t = {UINT32_C(0x60310049),"fgb_geometry_t",sxscx_fgb_geometry_t_fields,SX_COUNT(sxscx_fgb_geometry_t_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_tm_fields[] = {
    SX_FIELD("tm_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_geometry_tm = {UINT32_C(0x6031004a),"fgb_geometry_tm",sxscx_fgb_geometry_tm_fields,SX_COUNT(sxscx_fgb_geometry_tm_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_type_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
};
static const sx_layout sxscx_fgb_geometry_type = {UINT32_C(0x6031004b),"fgb_geometry_type",sxscx_fgb_geometry_type_fields,SX_COUNT(sxscx_fgb_geometry_type_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_parts_fields[] = {
    SX_FIELD("parts_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_geometry_parts = {UINT32_C(0x6031004c),"fgb_geometry_parts",sxscx_fgb_geometry_parts_fields,SX_COUNT(sxscx_fgb_geometry_parts_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_feature_geometry_fields[] = {
    SX_FIELD("geometry_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_feature_geometry = {UINT32_C(0x6031004d),"fgb_feature_geometry",sxscx_fgb_feature_geometry_fields,SX_COUNT(sxscx_fgb_feature_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_feature_properties_fields[] = {
    SX_FIELD("properties_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxscx_fgb_feature_properties = {UINT32_C(0x6031004e),"fgb_feature_properties",sxscx_fgb_feature_properties_fields,SX_COUNT(sxscx_fgb_feature_properties_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_0_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","int8",2,1,SX_NONE),
};
static const sx_layout sxscx_fgb_property_0 = {UINT32_C(0x6031004f),"fgb_property_0",sxscx_fgb_property_0_fields,SX_COUNT(sxscx_fgb_property_0_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_1_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint8",2,1,SX_NONE),
};
static const sx_layout sxscx_fgb_property_1 = {UINT32_C(0x60310050),"fgb_property_1",sxscx_fgb_property_1_fields,SX_COUNT(sxscx_fgb_property_1_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_2_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint8",2,1,SX_NONE),
};
static const sx_layout sxscx_fgb_property_2 = {UINT32_C(0x60310051),"fgb_property_2",sxscx_fgb_property_2_fields,SX_COUNT(sxscx_fgb_property_2_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_3_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","int16",2,2,SX_NONE),
};
static const sx_layout sxscx_fgb_property_3 = {UINT32_C(0x60310052),"fgb_property_3",sxscx_fgb_property_3_fields,SX_COUNT(sxscx_fgb_property_3_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_4_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint16",2,2,SX_NONE),
};
static const sx_layout sxscx_fgb_property_4 = {UINT32_C(0x60310053),"fgb_property_4",sxscx_fgb_property_4_fields,SX_COUNT(sxscx_fgb_property_4_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_5_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","int32",2,4,SX_NONE),
};
static const sx_layout sxscx_fgb_property_5 = {UINT32_C(0x60310054),"fgb_property_5",sxscx_fgb_property_5_fields,SX_COUNT(sxscx_fgb_property_5_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_6_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint32",2,4,SX_NONE),
};
static const sx_layout sxscx_fgb_property_6 = {UINT32_C(0x60310055),"fgb_property_6",sxscx_fgb_property_6_fields,SX_COUNT(sxscx_fgb_property_6_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_7_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","int64",2,8,SX_NONE),
};
static const sx_layout sxscx_fgb_property_7 = {UINT32_C(0x60310056),"fgb_property_7",sxscx_fgb_property_7_fields,SX_COUNT(sxscx_fgb_property_7_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_8_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint64",2,8,SX_NONE),
};
static const sx_layout sxscx_fgb_property_8 = {UINT32_C(0x60310057),"fgb_property_8",sxscx_fgb_property_8_fields,SX_COUNT(sxscx_fgb_property_8_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_9_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","float32",2,4,SX_NONE),
};
static const sx_layout sxscx_fgb_property_9 = {UINT32_C(0x60310058),"fgb_property_9",sxscx_fgb_property_9_fields,SX_COUNT(sxscx_fgb_property_9_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_10_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","float64",2,8,SX_NONE),
};
static const sx_layout sxscx_fgb_property_10 = {UINT32_C(0x60310059),"fgb_property_10",sxscx_fgb_property_10_fields,SX_COUNT(sxscx_fgb_property_10_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_11_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("byte_length","uint32",2,4,SX_SIZE),
};
static const sx_layout sxscx_fgb_property_11 = {UINT32_C(0x6031005a),"fgb_property_11",sxscx_fgb_property_11_fields,SX_COUNT(sxscx_fgb_property_11_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_12_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("byte_length","uint32",2,4,SX_SIZE),
};
static const sx_layout sxscx_fgb_property_12 = {UINT32_C(0x6031005b),"fgb_property_12",sxscx_fgb_property_12_fields,SX_COUNT(sxscx_fgb_property_12_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_13_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("byte_length","uint32",2,4,SX_SIZE),
};
static const sx_layout sxscx_fgb_property_13 = {UINT32_C(0x6031005c),"fgb_property_13",sxscx_fgb_property_13_fields,SX_COUNT(sxscx_fgb_property_13_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_14_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("byte_length","uint32",2,4,SX_SIZE),
};
static const sx_layout sxscx_fgb_property_14 = {UINT32_C(0x6031005d),"fgb_property_14",sxscx_fgb_property_14_fields,SX_COUNT(sxscx_fgb_property_14_fields),SX_LE};
static const sx_layout *const sx_scientificextra_layouts[] = {
    &sxscx_aedat2_event,
    &sxscx_axona_timestamp,
    &sxscx_axona_end,
    &sxscx_iplab_header_le,
    &sxscx_iplab_terminator_le,
    &sxscx_dsn6_header_le,
    &sxscx_iplab_header_be,
    &sxscx_iplab_terminator_be,
    &sxscx_dsn6_header_be,
    &sxscx_brix_header,
    &sxscx_mtz_prefix,
    &sxscx_mtz_header_record,
    &sxscx_ensight_header,
    &sxscx_ensight_part,
    &sxscx_ensight_elements,
    &sxscx_ensight_given_id,
    &sxscx_ensight_coordinate,
    &sxscx_ensight_connectivity,
    &sxscx_dted_uhl,
    &sxscx_dted_dsi,
    &sxscx_dted_acc,
    &sxscx_dted_column_header,
    &sxscx_dted_column_checksum,
    &sxscx_fgb_prefix,
    &sxscx_fgb_root,
    &sxscx_fgb_feature_size,
    &sxscx_fgb_table_header,
    &sxscx_fgb_vtable_header,
    &sxscx_fgb_vtable_entry,
    &sxscx_fgb_vector_header,
    &sxscx_fgb_string_header,
    &sxscx_fgb_vector_reference,
    &sxscx_fgb_geometry_end,
    &sxscx_fgb_coordinate,
    &sxscx_fgb_geometry_time,
    &sxscx_fgb_index_internal,
    &sxscx_fgb_index_leaf,
    &sxscx_fgb_header_name,
    &sxscx_fgb_header_envelope,
    &sxscx_fgb_header_geometry_type,
    &sxscx_fgb_header_has_z,
    &sxscx_fgb_header_has_m,
    &sxscx_fgb_header_has_t,
    &sxscx_fgb_header_has_tm,
    &sxscx_fgb_header_columns,
    &sxscx_fgb_header_features_count,
    &sxscx_fgb_header_index_node_size,
    &sxscx_fgb_header_crs,
    &sxscx_fgb_header_title,
    &sxscx_fgb_header_description,
    &sxscx_fgb_header_metadata,
    &sxscx_fgb_column_name,
    &sxscx_fgb_column_type,
    &sxscx_fgb_column_title,
    &sxscx_fgb_column_description,
    &sxscx_fgb_column_width,
    &sxscx_fgb_column_precision,
    &sxscx_fgb_column_scale,
    &sxscx_fgb_column_nullable,
    &sxscx_fgb_column_unique,
    &sxscx_fgb_column_primary_key,
    &sxscx_fgb_column_metadata,
    &sxscx_fgb_crs_org,
    &sxscx_fgb_crs_code,
    &sxscx_fgb_crs_name,
    &sxscx_fgb_crs_description,
    &sxscx_fgb_crs_wkt,
    &sxscx_fgb_crs_code_string,
    &sxscx_fgb_geometry_ends,
    &sxscx_fgb_geometry_xy,
    &sxscx_fgb_geometry_z,
    &sxscx_fgb_geometry_m,
    &sxscx_fgb_geometry_t,
    &sxscx_fgb_geometry_tm,
    &sxscx_fgb_geometry_type,
    &sxscx_fgb_geometry_parts,
    &sxscx_fgb_feature_geometry,
    &sxscx_fgb_feature_properties,
    &sxscx_fgb_property_0,
    &sxscx_fgb_property_1,
    &sxscx_fgb_property_2,
    &sxscx_fgb_property_3,
    &sxscx_fgb_property_4,
    &sxscx_fgb_property_5,
    &sxscx_fgb_property_6,
    &sxscx_fgb_property_7,
    &sxscx_fgb_property_8,
    &sxscx_fgb_property_9,
    &sxscx_fgb_property_10,
    &sxscx_fgb_property_11,
    &sxscx_fgb_property_12,
    &sxscx_fgb_property_13,
    &sxscx_fgb_property_14,
};
static bool sx_scientificextra_static_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60310000U||id>=0x60320000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60310001U:
        if(!xx_rt_wcscmp(r->name,L"event_address"))text=L"Signed packed sensor address; its bits depend on the AEChip. This is not a memory address.";
        if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Microseconds; native reader supports nonnegative monotonic timestamps.";
        break;
    case 0x60310002U:
        if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Signed sample-clock count; divide by the text header timebase to obtain seconds.";
        break;
    case 0x60310004U:
        if(!xx_rt_wcscmp(r->name,L"data_size"))text=L"Size of the data block after its tag, including its size word and the six dimension/type words.";
        break;
    case 0x60310006U:
        if(!xx_rt_wcscmp(r->name,L"origin_x"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"origin_y"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"origin_z"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"cell_a"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_b"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_c"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_alpha"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_beta"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_gamma"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"density_multiplier"))text=L"Stored density scale multiplied by100.";
        break;
    case 0x60310007U:
        if(!xx_rt_wcscmp(r->name,L"data_size"))text=L"Size of the data block after its tag, including its size word and the six dimension/type words.";
        break;
    case 0x60310009U:
        if(!xx_rt_wcscmp(r->name,L"origin_x"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"origin_y"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"origin_z"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"cell_a"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_b"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_c"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_alpha"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_beta"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_gamma"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"density_multiplier"))text=L"Stored density scale multiplied by100.";
        break;
    case 0x6031000aU:
        if(!xx_rt_wcscmp(r->name,L"descriptor_text"))text=L"BRIX ASCII descriptor: origin, extent, grid, cell, prod, plus and sigma. Numeric text is preserved as stored.";
        break;
    case 0x6031000bU:
        if(!xx_rt_wcscmp(r->name,L"header_word_index"))text=L"One-based four-byte word index; byte position is four times(value-1).";
        break;
    case 0x6031000cU:
        if(!xx_rt_wcscmp(r->name,L"record_text"))text=L"Fixed80-byte metadata record. Space-delimited numeric/text fields are preserved verbatim.";
        break;
    case 0x60310010U:
        if(!xx_rt_wcscmp(r->name,L"identifier"))text=L"Stored node or element identifier; not a file offset.";
        break;
    case 0x60310011U:
        if(!xx_rt_wcscmp(r->name,L"coordinate"))text=L"Cartesian coordinate; not a file offset.";
        break;
    case 0x60310012U:
        if(!xx_rt_wcscmp(r->name,L"local_node_index"))text=L"One-based local node index, independent of given node IDs.";
        break;
    case 0x60310013U:
        if(!xx_rt_wcscmp(r->name,L"longitude_interval"))text=L"Tenths of arc-seconds.";
        if(!xx_rt_wcscmp(r->name,L"latitude_interval"))text=L"Tenths of arc-seconds.";
        if(!xx_rt_wcscmp(r->name,L"absolute_vertical_accuracy"))text=L"Metres or NA.";
        break;
    case 0x60310017U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Unsigned sum of all bytes in this elevation column, excluding this four-byte checksum.";
        break;
    case 0x60310019U:
        if(!xx_rt_wcscmp(r->name,L"root_offset"))text=L"Forward displacement from this four-byte word to the root table.";
        break;
    case 0x6031001bU:
        if(!xx_rt_wcscmp(r->name,L"vtable_displacement"))text=L"Subtract this signed displacement from the table address to locate its vtable.";
        break;
    case 0x6031001dU:
        if(!xx_rt_wcscmp(r->name,L"member_offset"))text=L"Displacement from the containing table; zero means absent.";
        break;
    case 0x60310020U:
        if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Forward displacement from this word to a table.";
        break;
    case 0x60310021U:
        if(!xx_rt_wcscmp(r->name,L"point_end_index"))text=L"End index in the coordinate array, not a byte offset.";
        break;
    case 0x60310022U:
        if(!xx_rt_wcscmp(r->name,L"coordinate"))text=L"Geometry/envelope floating point value, not a memory address.";
        break;
    case 0x60310024U:
        if(!xx_rt_wcscmp(r->name,L"child_node_index"))text=L"Index of first child node; not a file byte offset.";
        break;
    case 0x60310025U:
        if(!xx_rt_wcscmp(r->name,L"feature_offset"))text=L"Byte displacement from the start of the feature section.";
        break;
    case 0x60310026U:
        if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310027U:
        if(!xx_rt_wcscmp(r->name,L"envelope_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031002dU:
        if(!xx_rt_wcscmp(r->name,L"columns_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310030U:
        if(!xx_rt_wcscmp(r->name,L"crs_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310031U:
        if(!xx_rt_wcscmp(r->name,L"title_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310032U:
        if(!xx_rt_wcscmp(r->name,L"description_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310033U:
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310034U:
        if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310036U:
        if(!xx_rt_wcscmp(r->name,L"title_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310037U:
        if(!xx_rt_wcscmp(r->name,L"description_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031003eU:
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031003fU:
        if(!xx_rt_wcscmp(r->name,L"org_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310041U:
        if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310042U:
        if(!xx_rt_wcscmp(r->name,L"description_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310043U:
        if(!xx_rt_wcscmp(r->name,L"wkt_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310044U:
        if(!xx_rt_wcscmp(r->name,L"code_string_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310045U:
        if(!xx_rt_wcscmp(r->name,L"ends_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310046U:
        if(!xx_rt_wcscmp(r->name,L"xy_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310047U:
        if(!xx_rt_wcscmp(r->name,L"z_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310048U:
        if(!xx_rt_wcscmp(r->name,L"m_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310049U:
        if(!xx_rt_wcscmp(r->name,L"t_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031004aU:
        if(!xx_rt_wcscmp(r->name,L"tm_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031004cU:
        if(!xx_rt_wcscmp(r->name,L"parts_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031004dU:
        if(!xx_rt_wcscmp(r->name,L"geometry_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031004eU:
        if(!xx_rt_wcscmp(r->name,L"properties_offset"))text=L"Forward displacement from this physical word.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
static const sx_layout *const sxscx_fgb_header_rows[]={&sxscx_fgb_header_name,&sxscx_fgb_header_envelope,&sxscx_fgb_header_geometry_type,&sxscx_fgb_header_has_z,&sxscx_fgb_header_has_m,&sxscx_fgb_header_has_t,&sxscx_fgb_header_has_tm,&sxscx_fgb_header_columns,&sxscx_fgb_header_features_count,&sxscx_fgb_header_index_node_size,&sxscx_fgb_header_crs,&sxscx_fgb_header_title,&sxscx_fgb_header_description,&sxscx_fgb_header_metadata};
static const sx_layout *const sxscx_fgb_column_rows[]={&sxscx_fgb_column_name,&sxscx_fgb_column_type,&sxscx_fgb_column_title,&sxscx_fgb_column_description,&sxscx_fgb_column_width,&sxscx_fgb_column_precision,&sxscx_fgb_column_scale,&sxscx_fgb_column_nullable,&sxscx_fgb_column_unique,&sxscx_fgb_column_primary_key,&sxscx_fgb_column_metadata};
static const sx_layout *const sxscx_fgb_crs_rows[]={&sxscx_fgb_crs_org,&sxscx_fgb_crs_code,&sxscx_fgb_crs_name,&sxscx_fgb_crs_description,&sxscx_fgb_crs_wkt,&sxscx_fgb_crs_code_string};
static const sx_layout *const sxscx_fgb_geometry_rows[]={&sxscx_fgb_geometry_ends,&sxscx_fgb_geometry_xy,&sxscx_fgb_geometry_z,&sxscx_fgb_geometry_m,&sxscx_fgb_geometry_t,&sxscx_fgb_geometry_tm,&sxscx_fgb_geometry_type,&sxscx_fgb_geometry_parts};
static const sx_layout *const sxscx_fgb_feature_rows[]={&sxscx_fgb_feature_geometry,&sxscx_fgb_feature_properties,NULL};
static const sx_layout *const sxscx_fgb_property_rows[]={&sxscx_fgb_property_0,&sxscx_fgb_property_1,&sxscx_fgb_property_2,&sxscx_fgb_property_3,&sxscx_fgb_property_4,&sxscx_fgb_property_5,&sxscx_fgb_property_6,&sxscx_fgb_property_7,&sxscx_fgb_property_8,&sxscx_fgb_property_9,&sxscx_fgb_property_10,&sxscx_fgb_property_11,&sxscx_fgb_property_12,&sxscx_fgb_property_13,&sxscx_fgb_property_14};

static bool sx_scientificextra_comment(xx_data_struct_record *r,uint32_t id)
{
 if(!sx_scientificextra_static_comment(r,id))return false;
 if(!r||!r->name||id<0x60310000U||id>=0x60320000U)return true;
 xx_var_type_t type=xx_var_get_type(&r->value);
 if(type==XX_VAR_TYPE_FLOAT||type==XX_VAR_TYPE_DOUBLE||type==XX_VAR_TYPE_STRING||type==XX_VAR_TYPE_BYTES)return true;
 uint64_t v=xx_var_get_u64(&r->value);const wchar_t *text=NULL;
 if((id==sxscx_iplab_header_le.id||id==sxscx_iplab_header_be.id)&&!xx_rt_wcscmp(r->name,L"sample_type")){
  switch(v){case 0:text=L"Unsigned8-bit intensity";break;case 1:text=L"Signed16-bit intensity";break;case 2:text=L"Unsigned16-bit intensity";break;case 3:text=L"Signed32-bit intensity";break;case 4:text=L"IEEE754 float32";break;case 5:text=L"Unsigned8-bit data";break;case 6:text=L"Unsigned16-bit data";break;case 10:text=L"IEEE754 float64";break;default:break;}
 }
 if(id==sxscx_fgb_header_geometry_type.id||id==sxscx_fgb_geometry_type.id){
  static const wchar_t *const names[]={L"Unknown",L"Point",L"LineString",L"Polygon",L"MultiPoint",L"MultiLineString",L"MultiPolygon",L"GeometryCollection",L"CircularString",L"CompoundCurve",L"CurvePolygon",L"MultiCurve",L"MultiSurface",L"Curve",L"Surface",L"PolyhedralSurface",L"TIN",L"Triangle"};if(v<SX_COUNT(names))text=names[v];
 }
 if(id==sxscx_fgb_column_type.id){
  static const wchar_t *const names[]={L"Byte",L"UByte",L"Bool",L"Short",L"UShort",L"Int",L"UInt",L"Long",L"ULong",L"Float",L"Double",L"String",L"Json",L"DateTime",L"Binary"};if(v<SX_COUNT(names))text=names[v];
 }
 return !text||xx_data_struct_record_set_comment(r,text);
}

/* Physical coordinates only; bounded output leaves unexpanded data raw. */
static bool sxscx_span(sx_context *c,uint64_t at,uint64_t n){return c&&!xx_pd_is_stopped(c->pd)&&c->size>=0&&at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
static uint16_t sxscx16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
static uint32_t sxscx32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
static uint64_t sxscx64(const uint8_t *p,bool be){return xx_data_get_u64(p,8,0,be);}
static uint64_t sxscx_extent(const sx_layout *l){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return (uint64_t)(f->rel_offset+f->size);}
static bool sxscx_add(sx_context *c,const sx_layout *l,uint64_t at){uint64_t n=sxscx_extent(l);return sxscx_span(c,at,n)&&(c->count>=32000||sx_add(c,l,(int64_t)at,(int64_t)n));}
static bool sxscx_table(sx_context *c,const sx_layout *l,uint64_t at,uint64_t count){uint64_t n=sxscx_extent(l);return !count||(count<=INT64_MAX/n&&sxscx_span(c,at,n*count)&&(c->count>=32000||sx_table(c,l,(int64_t)at,(int64_t)n,count)));}
static int sxscx_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxscx_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxscx_order);
 /* FlatBuffers can share vtables/vectors. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxscx_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sxscx_decimal(const uint8_t *p,size_t n,uint64_t *value)
{
 uint64_t v=0;size_t i=0;while(i<n&&(p[i]==' '||p[i]=='\t'))i++;bool digit=false;
 for(;i<n&&p[i]>='0'&&p[i]<='9';i++){if(v>(UINT64_MAX-(p[i]-'0'))/10)return false;v=v*10+p[i]-'0';digit=true;}
 while(i<n&&(p[i]==' '||p[i]=='\t'||p[i]=='\r'))i++;*value=v;return digit&&i==n;
}
static bool sxscx_axona(sx_context *c,const uint8_t *b,size_t n)
{
 uint64_t at=0,head=0,samples=0,count=0,channels=0;
 while(at<n&&at<65536){if(n-at>=10&&!xx_rt_memcmp(b+at,"data_start",10)){head=at+10;break;}
  uint64_t end=at;while(end<n&&b[end]!='\n')end++;if(end==n)return false;
  const char *keys[]={"num_spikes ","num_chans ","samples_per_spike "};uint64_t *out[]={&count,&channels,&samples};
  for(unsigned i=0;i<3;i++){size_t z=xx_rt_strlen(keys[i]);if(end-at>=z&&!xx_rt_memcmp(b+at,keys[i],z)&&!sxscx_decimal(b+at+z,(size_t)(end-at-z),out[i]))return false;}at=end+1;
 }
 if(!head||!count||count>261760||channels!=4||!samples||samples>1024)return false;
 uint64_t width=4+samples,bytes=count*4*width;if(!sxscx_span(c,head,bytes+12)||head+bytes+12!=n)return false;
 for(uint64_t i=0;i<count*4&&c->count<32000;i++)if(!sxscx_add(c,&sxscx_axona_timestamp,head+i*width))return false;
 return sxscx_add(c,&sxscx_axona_end,head+bytes);
}
static bool sxscx_aedat(sx_context *c,const uint8_t *b,size_t n)
{
 uint64_t at=0;while(at<n&&b[at]=='#'){while(at<n&&b[at]!='\n')at++;if(at==n)return false;at++;}
 return at>=13&&at<n&&(n-at)%8==0&&sxscx_table(c,&sxscx_aedat2_event,at,(n-at)/8);
}
static bool sxscx_iplab(sx_context *c,const uint8_t *b,size_t n){if(n<52)return false;bool be=b[0]=='m';return sxscx_add(c,be?&sxscx_iplab_header_be:&sxscx_iplab_header_le,0)&&sxscx_add(c,be?&sxscx_iplab_terminator_be:&sxscx_iplab_terminator_le,n-8);}
static bool sxscx_dsn6(sx_context *c,const uint8_t *b,size_t n){if(n<512)return false;return sxscx_add(c,!xx_rt_memcmp(b,":-)",3)?&sxscx_brix_header:sxscx16(b+36,true)==100?&sxscx_dsn6_header_be:&sxscx_dsn6_header_le,0);}
static bool sxscx_mtz(sx_context *c,const uint8_t *b,size_t n){if(n<80)return false;uint64_t word=sxscx32(b+4,false);if(word<21)return false;uint64_t at=(word-1)*4;return at<=n&&(n-at)%80==0&&sxscx_add(c,&sxscx_mtz_prefix,0)&&sxscx_table(c,&sxscx_mtz_header_record,at,(n-at)/80);}
static bool sxscx_dted(sx_context *c,const uint8_t *b,size_t n)
{
 uint64_t nx,ny,at=3428;if(n<3428||!sxscx_decimal(b+47,4,&nx)||!sxscx_decimal(b+51,4,&ny)||!nx||!ny||nx>3601||ny>3601)return false;
 if(!sxscx_add(c,&sxscx_dted_uhl,0)||!sxscx_add(c,&sxscx_dted_dsi,80)||!sxscx_add(c,&sxscx_dted_acc,728))return false;
 uint64_t size=12+ny*2;for(uint64_t i=0;i<nx;i++,at+=size)if(!sxscx_span(c,at,size)||!sxscx_add(c,&sxscx_dted_column_header,at)||!sxscx_add(c,&sxscx_dted_column_checksum,at+size-4))return false;
 return at==n;
}
static bool sxscx_ensight(sx_context *c,const uint8_t *b,size_t n)
{
 if(n<400||!sxscx_add(c,&sxscx_ensight_header,0))return false;bool nodeids=!xx_rt_memcmp(b+240,"node id given",13),elementids=!xx_rt_memcmp(b+320,"element id given",16);uint64_t at=400;
 for(unsigned part=0;at<n&&part<1000;part++){
  if(!sxscx_span(c,at,248)||!sxscx_add(c,&sxscx_ensight_part,at))return false;uint32_t nodes=sxscx32(b+at+244,false);at+=248;if(!nodes||nodes>1000000)return false;
  if(nodeids){if(!sxscx_table(c,&sxscx_ensight_given_id,at,nodes))return false;at+=(uint64_t)nodes*4;}
  if(!sxscx_table(c,&sxscx_ensight_coordinate,at,(uint64_t)nodes*3))return false;at+=(uint64_t)nodes*12;
  while(at<n){
   if(!sxscx_span(c,at,80))return false;if(!xx_rt_memcmp(b+at,"part",4))break;
   static const char *const names[]={"point","bar2","tria3","quad4","tetra4","pyramid5","penta6","hexa8"};static const unsigned widths[]={1,2,3,4,4,5,6,8};unsigned arity=0;
   for(unsigned i=0;i<8;i++)if(!xx_rt_memcmp(b+at,names[i],xx_rt_strlen(names[i]))){arity=widths[i];break;}
   if(!arity||!sxscx_span(c,at,84)||!sxscx_add(c,&sxscx_ensight_elements,at))return false;uint32_t count=sxscx32(b+at+80,false);if(!count||count>1000000)return false;at+=84;
   if(elementids){if(!sxscx_table(c,&sxscx_ensight_given_id,at,count))return false;at+=(uint64_t)count*4;}
   if(!sxscx_table(c,&sxscx_ensight_connectivity,at,(uint64_t)count*arity))return false;at+=(uint64_t)count*arity*4;
  }
 }return at==n;
}


typedef struct sxscx_fb {sx_context *c;const uint8_t *b;uint64_t base,n;uint8_t types[256];unsigned columns,work;} sxscx_fb;
static bool sxscx_fb_span(sxscx_fb *w,uint64_t at,uint64_t n){return !xx_pd_is_stopped(w->c->pd)&&at<=w->n&&n<=w->n-at;}
static bool sxscx_fb_add(sxscx_fb *w,const sx_layout *l,uint64_t at){return sxscx_fb_span(w,at,sxscx_extent(l))&&sxscx_add(w->c,l,w->base+at);}
static bool sxscx_fb_table(sxscx_fb *w,const sx_layout *l,uint64_t at,uint64_t count){uint64_t z=sxscx_extent(l);return !count||(count<=UINT64_MAX/z&&sxscx_fb_span(w,at,count*z)&&sxscx_table(w->c,l,w->base+at,count));}
static bool sxscx_fb_field(sxscx_fb *w,uint64_t table,unsigned id,unsigned width,uint64_t *out)
{
 if(!sxscx_fb_span(w,table,4))return false;int64_t delta=(int32_t)sxscx32(w->b+table,false),v=(int64_t)table-delta;
 if(v<0||!sxscx_fb_span(w,(uint64_t)v,4))return false;uint16_t vn=sxscx16(w->b+v,false),on=sxscx16(w->b+v+2,false);
 if(vn<4||(vn&1)||on<4||!sxscx_fb_span(w,(uint64_t)v,vn)||!sxscx_fb_span(w,table,on))return false;
 *out=0;if(4+id*2>=vn)return true;unsigned off=sxscx16(w->b+v+4+id*2,false);if(!off)return true;if(off<4||off>on||width>on-off)return false;*out=table+off;return true;
}
static bool sxscx_fb_ref(sxscx_fb *w,uint64_t field,uint64_t *out){*out=0;if(!field)return true;if(!sxscx_fb_span(w,field,4))return false;uint32_t off=sxscx32(w->b+field,false);if(!off||!sxscx_fb_span(w,field+off,4))return false;*out=field+off;return true;}
static bool sxscx_fb_string(sxscx_fb *w,uint64_t field){uint64_t at;if(!sxscx_fb_ref(w,field,&at))return false;if(!at)return true;uint32_t n=sxscx32(w->b+at,false);return n<=65536&&sxscx_fb_span(w,at+4,(uint64_t)n+1)&&w->b[at+4+n]==0&&sxscx_fb_add(w,&sxscx_fgb_string_header,at);}
static bool sxscx_fb_vector(sxscx_fb *w,uint64_t field,unsigned width,uint64_t *at,uint64_t *count)
{
 uint64_t v;*at=*count=0;if(!sxscx_fb_ref(w,field,&v))return false;if(!v)return true;
 *count=sxscx32(w->b+v,false);*at=v+4;return width&&*count<=UINT64_MAX/width&&sxscx_fb_span(w,*at,*count*width)&&sxscx_fb_add(w,&sxscx_fgb_vector_header,v);
}
static bool sxscx_fb_parse(sxscx_fb *w,uint64_t table,unsigned kind,unsigned depth);
static bool sxscx_fb_children(sxscx_fb *w,uint64_t field,unsigned kind,unsigned depth)
{
 uint64_t at,count;if(!sxscx_fb_vector(w,field,4,&at,&count)||count>1024)return false;
 if(!sxscx_fb_table(w,&sxscx_fgb_vector_reference,at,count))return false;
 for(uint64_t i=0;i<count;i++){uint64_t target;if(!sxscx_fb_ref(w,at+i*4,&target)||!target||!sxscx_fb_parse(w,target,kind,depth+1))return false;}return true;
}
static bool sxscx_fb_properties(sxscx_fb *w,uint64_t field)
{
 uint64_t at,count;if(!sxscx_fb_vector(w,field,1,&at,&count))return false;uint64_t end=at+count;
 while(at<end){if(end-at==1&&!w->b[at])return true;if(end-at<2)return false;unsigned col=sxscx16(w->b+at,false);if(col>=w->columns)return false;unsigned type=w->types[col];if(type>14)return false;
  const sx_layout *l=sxscx_fgb_property_rows[type];uint64_t z=sxscx_extent(l);if(z>end-at||!sxscx_fb_add(w,l,at))return false;
  uint64_t len=type>=11?sxscx32(w->b+at+2,false):0;if(len>end-at-z)return false;at+=z+len;
 }return at==end;
}
static bool sxscx_fb_parse(sxscx_fb *w,uint64_t table,unsigned kind,unsigned depth)
{
 static const sx_layout *const *const sets[]={sxscx_fgb_header_rows,sxscx_fgb_column_rows,sxscx_fgb_crs_rows,sxscx_fgb_geometry_rows,sxscx_fgb_feature_rows};
 static const unsigned counts[]={14,11,6,8,3};
 if(kind>=5||depth>19||!sxscx_fb_span(w,table,4))return false;
 /* Native validation has already checked the grammar. A bounded physical
  * metadata prefix is enough when shared graph expansion would be excessive. */
 if(++w->work>32768||w->c->count>=32000)return true;
 int64_t vt=(int64_t)table-(int32_t)sxscx32(w->b+table,false);if(vt<0||!sxscx_fb_span(w,(uint64_t)vt,4))return false;unsigned vn=sxscx16(w->b+vt,false);uint64_t fields[14]={0};
 if(vn<4||(vn&1)||vn>4+2*counts[kind]||!sxscx_fb_span(w,(uint64_t)vt,vn)||!sxscx_fb_add(w,&sxscx_fgb_table_header,table)||!sxscx_fb_add(w,&sxscx_fgb_vtable_header,(uint64_t)vt)||!sxscx_fb_table(w,&sxscx_fgb_vtable_entry,(uint64_t)vt+4,(vn-4)/2))return false;
 for(unsigned i=0;i<counts[kind];i++){
  const sx_layout *l=sets[kind][i];if(!sxscx_fb_field(w,table,i,l?(unsigned)sxscx_extent(l):4,&fields[i]))return false;
  if(fields[i]&&l&&!sxscx_fb_add(w,l,fields[i]))return false;
 }
 uint64_t at,count,target;
 if(kind==0){
  const unsigned strings[]={0,11,12,13};for(unsigned i=0;i<4;i++)if(!sxscx_fb_string(w,fields[strings[i]]))return false;
  if(!sxscx_fb_vector(w,fields[1],8,&at,&count)||!sxscx_fb_table(w,&sxscx_fgb_coordinate,at,count))return false;
  if(!sxscx_fb_children(w,fields[7],1,depth)||!sxscx_fb_ref(w,fields[10],&target))return false;
  return !target||sxscx_fb_parse(w,target,2,depth+1);
 }
 if(kind==1){const unsigned strings[]={0,2,3,10};for(unsigned i=0;i<4;i++)if(!sxscx_fb_string(w,fields[strings[i]]))return false;return true;}
 if(kind==2){for(unsigned i=0;i<6;i++)if(i!=1&&!sxscx_fb_string(w,fields[i]))return false;return true;}
 if(kind==3){
  if(!sxscx_fb_vector(w,fields[0],4,&at,&count)||!sxscx_fb_table(w,&sxscx_fgb_geometry_end,at,count))return false;
  for(unsigned i=1;i<=5;i++)if(!sxscx_fb_vector(w,fields[i],8,&at,&count)||!sxscx_fb_table(w,i==5?&sxscx_fgb_geometry_time:&sxscx_fgb_coordinate,at,count))return false;
  return sxscx_fb_children(w,fields[7],3,depth);
 }
 if(!sxscx_fb_ref(w,fields[0],&target)||!target||!sxscx_fb_parse(w,target,3,depth+1)||!sxscx_fb_properties(w,fields[1]))return false;
 return !fields[2];
}
static bool sxscx_flatgeobuf(sx_context *c,const uint8_t *b,size_t n)
{
 if(n<16||!sxscx_add(c,&sxscx_fgb_prefix,0))return false;uint32_t header=sxscx32(b+8,false);if(header<8||!sxscx_span(c,12,header))return false;
 sxscx_fb w={c,b+12,12,header,{0},0,0};uint64_t root=sxscx32(w.b,false),f,at,count,features,index_size=16;
 if(!sxscx_fb_add(&w,&sxscx_fgb_root,0)||!sxscx_fb_parse(&w,root,0,0)||!sxscx_fb_field(&w,root,8,8,&f)||!f)return false;features=sxscx64(w.b+f,false);if(!features||features>1024)return false;
 if(!sxscx_fb_field(&w,root,9,2,&f))return false;if(f)index_size=sxscx16(w.b+f,false);if(index_size==1)return false;
 if(!sxscx_fb_field(&w,root,7,4,&f)||!sxscx_fb_vector(&w,f,4,&at,&count)||count>256)return false;w.columns=(unsigned)count;
 for(unsigned i=0;i<w.columns;i++){
  uint64_t target,t;if(!sxscx_fb_ref(&w,at+i*4,&target)||!target||!sxscx_fb_field(&w,target,1,1,&t))return false;w.types[i]=t?w.b[t]:0;if(w.types[i]>14)return false;
 }
 at=12+(uint64_t)header;
 if(index_size){uint64_t nodes=features,level=features;unsigned depth=0;do{if(++depth>16)return false;level=(level+index_size-1)/index_size;nodes+=level;}while(level!=1);
  if(!sxscx_table(c,&sxscx_fgb_index_internal,at,nodes-features)||!sxscx_table(c,&sxscx_fgb_index_leaf,at+(nodes-features)*40,features))return false;at+=nodes*40;
 }
 for(uint64_t i=0;i<features;i++){
  if(!sxscx_span(c,at,8))return false;uint32_t z=sxscx32(b+at,false);if(z<8||z>8388608||!sxscx_span(c,at+4,z)||!sxscx_add(c,&sxscx_fgb_feature_size,at))return false;
  w.b=b+at+4;w.base=at+4;w.n=z;w.work=0;root=sxscx32(w.b,false);
  if(!sxscx_fb_add(&w,&sxscx_fgb_root,0)||!sxscx_fb_parse(&w,root,4,0))return false;at+=4+(uint64_t)z;
 }return at==n;
}
static bool sx_scientificextra_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_FLATGEOBUF:case XX_FILE_TYPE_AXONA_TETRODE:case XX_FILE_TYPE_INIVATION_AEDAT:case XX_FILE_TYPE_ENSIGHT_GOLD_GEOMETRY:case XX_FILE_TYPE_DTED_ELEVATION:case XX_FILE_TYPE_SCANALYTICS_IPLAB:case XX_FILE_TYPE_DSN6_DENSITY:case XX_FILE_TYPE_CRYSTALLOGRAPHY_MTZ:return true;default:return false;}}
static bool sx_scientificextra_build(sx_context *c)
{
 if(!c||c->size<=0||c->size>134217728||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 uint8_t *b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);
 if(ok)switch(c->f->file_type){case XX_FILE_TYPE_FLATGEOBUF:ok=sxscx_flatgeobuf(c,b,(size_t)c->size);break;case XX_FILE_TYPE_AXONA_TETRODE:ok=sxscx_axona(c,b,(size_t)c->size);break;case XX_FILE_TYPE_INIVATION_AEDAT:ok=sxscx_aedat(c,b,(size_t)c->size);break;case XX_FILE_TYPE_ENSIGHT_GOLD_GEOMETRY:ok=sxscx_ensight(c,b,(size_t)c->size);break;case XX_FILE_TYPE_DTED_ELEVATION:ok=sxscx_dted(c,b,(size_t)c->size);break;case XX_FILE_TYPE_SCANALYTICS_IPLAB:ok=sxscx_iplab(c,b,(size_t)c->size);break;case XX_FILE_TYPE_DSN6_DENSITY:ok=sxscx_dsn6(c,b,(size_t)c->size);break;case XX_FILE_TYPE_CRYSTALLOGRAPHY_MTZ:ok=sxscx_mtz(c,b,(size_t)c->size);break;default:ok=false;break;}
 xx_mem_free(b);return ok&&sxscx_finish(c);
}
