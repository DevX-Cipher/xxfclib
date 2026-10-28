/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical Arrow IPC/FlatBuffers and Parquet Compact Thrift metadata. */
static const xx_data_struct_field_desc sxq_arrow_file_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("padding", "bytes", 6, 2, SX_RESERVED),
};
static const sx_layout sxq_arrow_file_header = {UINT32_C(0x601F0001),"arrow_file_header",sxq_arrow_file_header_fields,SX_COUNT(sxq_arrow_file_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_file_trailer_fields[] = {
    SX_FIELD("footer_length", "int32", 0, 4, SX_SIZE),
    SX_FIELD("magic", "char[6]", 4, 6, SX_SIGNATURE),
};
static const sx_layout sxq_arrow_file_trailer = {UINT32_C(0x601F0002),"arrow_file_trailer",sxq_arrow_file_trailer_fields,SX_COUNT(sxq_arrow_file_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_message_prefix_fields[] = {
    SX_FIELD("metadata_length", "int32", 0, 4, SX_SIZE),
};
static const sx_layout sxq_arrow_message_prefix = {UINT32_C(0x601F0003),"arrow_message_prefix",sxq_arrow_message_prefix_fields,SX_COUNT(sxq_arrow_message_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_continuation_prefix_fields[] = {
    SX_FIELD("continuation", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("metadata_length", "int32", 4, 4, SX_SIZE),
};
static const sx_layout sxq_arrow_continuation_prefix = {UINT32_C(0x601F0004),"arrow_continuation_prefix",sxq_arrow_continuation_prefix_fields,SX_COUNT(sxq_arrow_continuation_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_flatbuffer_root_fields[] = {
    SX_FIELD("root_offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_flatbuffer_root = {UINT32_C(0x601F0005),"arrow_flatbuffer_root",sxq_arrow_flatbuffer_root_fields,SX_COUNT(sxq_arrow_flatbuffer_root_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_table_header_fields[] = {
    SX_FIELD("vtable_displacement", "int32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_table_header = {UINT32_C(0x601F0006),"arrow_table_header",sxq_arrow_table_header_fields,SX_COUNT(sxq_arrow_table_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_vtable_header_fields[] = {
    SX_FIELD("vtable_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("object_size", "uint16", 2, 2, SX_SIZE),
};
static const sx_layout sxq_arrow_vtable_header = {UINT32_C(0x601F0007),"arrow_vtable_header",sxq_arrow_vtable_header_fields,SX_COUNT(sxq_arrow_vtable_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_vtable_entry_fields[] = {
    SX_FIELD("field_offset", "uint16", 0, 2, SX_OFFSET),
};
static const sx_layout sxq_arrow_vtable_entry = {UINT32_C(0x601F0008),"arrow_vtable_entry",sxq_arrow_vtable_entry_fields,SX_COUNT(sxq_arrow_vtable_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_vector_header_fields[] = {
    SX_FIELD("element_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sxq_arrow_vector_header = {UINT32_C(0x601F0009),"arrow_vector_header",sxq_arrow_vector_header_fields,SX_COUNT(sxq_arrow_vector_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_vector_reference_fields[] = {
    SX_FIELD("object_offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_vector_reference = {UINT32_C(0x601F000A),"arrow_vector_reference",sxq_arrow_vector_reference_fields,SX_COUNT(sxq_arrow_vector_reference_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_string_header_fields[] = {
    SX_FIELD("byte_length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sxq_arrow_string_header = {UINT32_C(0x601F000B),"arrow_string_header",sxq_arrow_string_header_fields,SX_COUNT(sxq_arrow_string_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_block_fields[] = {
    SX_FIELD("message_offset", "int64", 0, 8, SX_OFFSET),
    SX_FIELD("metadata_length", "int32", 8, 4, SX_SIZE),
    SX_FIELD("alignment_padding", "bytes", 12, 4, SX_RESERVED),
    SX_FIELD("body_length", "int64", 16, 8, SX_SIZE),
};
static const sx_layout sxq_arrow_block = {UINT32_C(0x601F000C),"arrow_block",sxq_arrow_block_fields,SX_COUNT(sxq_arrow_block_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_field_node_fields[] = {
    SX_FIELD("length", "int64", 0, 8, SX_COUNT_PROP),
    SX_FIELD("null_count", "int64", 8, 8, SX_COUNT_PROP),
};
static const sx_layout sxq_arrow_field_node = {UINT32_C(0x601F000D),"arrow_field_node",sxq_arrow_field_node_fields,SX_COUNT(sxq_arrow_field_node_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_buffer_fields[] = {
    SX_FIELD("body_offset", "int64", 0, 8, SX_OFFSET),
    SX_FIELD("byte_length", "int64", 8, 8, SX_SIZE),
};
static const sx_layout sxq_arrow_buffer = {UINT32_C(0x601F000E),"arrow_buffer",sxq_arrow_buffer_fields,SX_COUNT(sxq_arrow_buffer_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_footer_version_fields[] = {
    SX_FIELD("version", "int16", 0, 2, SX_ID),
};
static const sx_layout sxq_arrow_footer_version = {UINT32_C(0x601F000F),"arrow_footer_version",sxq_arrow_footer_version_fields,SX_COUNT(sxq_arrow_footer_version_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_footer_schema_fields[] = {
    SX_FIELD("schema", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_footer_schema = {UINT32_C(0x601F0010),"arrow_footer_schema",sxq_arrow_footer_schema_fields,SX_COUNT(sxq_arrow_footer_schema_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_footer_dictionaries_fields[] = {
    SX_FIELD("dictionaries", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_footer_dictionaries = {UINT32_C(0x601F0011),"arrow_footer_dictionaries",sxq_arrow_footer_dictionaries_fields,SX_COUNT(sxq_arrow_footer_dictionaries_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_footer_record_batches_fields[] = {
    SX_FIELD("record_batches", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_footer_record_batches = {UINT32_C(0x601F0012),"arrow_footer_record_batches",sxq_arrow_footer_record_batches_fields,SX_COUNT(sxq_arrow_footer_record_batches_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_footer_custom_metadata_fields[] = {
    SX_FIELD("custom_metadata", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_footer_custom_metadata = {UINT32_C(0x601F0013),"arrow_footer_custom_metadata",sxq_arrow_footer_custom_metadata_fields,SX_COUNT(sxq_arrow_footer_custom_metadata_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_schema_endianness_fields[] = {
    SX_FIELD("endianness", "int16", 0, 2, SX_ID),
};
static const sx_layout sxq_arrow_schema_endianness = {UINT32_C(0x601F0014),"arrow_schema_endianness",sxq_arrow_schema_endianness_fields,SX_COUNT(sxq_arrow_schema_endianness_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_schema_fields_fields[] = {
    SX_FIELD("fields", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_schema_fields = {UINT32_C(0x601F0015),"arrow_schema_fields",sxq_arrow_schema_fields_fields,SX_COUNT(sxq_arrow_schema_fields_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_schema_custom_metadata_fields[] = {
    SX_FIELD("custom_metadata", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_schema_custom_metadata = {UINT32_C(0x601F0016),"arrow_schema_custom_metadata",sxq_arrow_schema_custom_metadata_fields,SX_COUNT(sxq_arrow_schema_custom_metadata_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_schema_features_fields[] = {
    SX_FIELD("features", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_schema_features = {UINT32_C(0x601F0017),"arrow_schema_features",sxq_arrow_schema_features_fields,SX_COUNT(sxq_arrow_schema_features_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_field_name_fields[] = {
    SX_FIELD("name", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_field_name = {UINT32_C(0x601F0018),"arrow_field_name",sxq_arrow_field_name_fields,SX_COUNT(sxq_arrow_field_name_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_field_nullable_fields[] = {
    SX_FIELD("nullable", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sxq_arrow_field_nullable = {UINT32_C(0x601F0019),"arrow_field_nullable",sxq_arrow_field_nullable_fields,SX_COUNT(sxq_arrow_field_nullable_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_field_type_tag_fields[] = {
    SX_FIELD("type_tag", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxq_arrow_field_type_tag = {UINT32_C(0x601F001A),"arrow_field_type_tag",sxq_arrow_field_type_tag_fields,SX_COUNT(sxq_arrow_field_type_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_field_type_fields[] = {
    SX_FIELD("type", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_field_type = {UINT32_C(0x601F001B),"arrow_field_type",sxq_arrow_field_type_fields,SX_COUNT(sxq_arrow_field_type_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_field_children_fields[] = {
    SX_FIELD("children", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_field_children = {UINT32_C(0x601F001C),"arrow_field_children",sxq_arrow_field_children_fields,SX_COUNT(sxq_arrow_field_children_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_field_custom_metadata_fields[] = {
    SX_FIELD("custom_metadata", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_field_custom_metadata = {UINT32_C(0x601F001D),"arrow_field_custom_metadata",sxq_arrow_field_custom_metadata_fields,SX_COUNT(sxq_arrow_field_custom_metadata_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_int_type_bit_width_fields[] = {
    SX_FIELD("bit_width", "int32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sxq_arrow_int_type_bit_width = {UINT32_C(0x601F001E),"arrow_int_type_bit_width",sxq_arrow_int_type_bit_width_fields,SX_COUNT(sxq_arrow_int_type_bit_width_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_int_type_is_signed_fields[] = {
    SX_FIELD("is_signed", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sxq_arrow_int_type_is_signed = {UINT32_C(0x601F001F),"arrow_int_type_is_signed",sxq_arrow_int_type_is_signed_fields,SX_COUNT(sxq_arrow_int_type_is_signed_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_message_version_fields[] = {
    SX_FIELD("version", "int16", 0, 2, SX_ID),
};
static const sx_layout sxq_arrow_message_version = {UINT32_C(0x601F0020),"arrow_message_version",sxq_arrow_message_version_fields,SX_COUNT(sxq_arrow_message_version_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_message_header_tag_fields[] = {
    SX_FIELD("header_tag", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxq_arrow_message_header_tag = {UINT32_C(0x601F0021),"arrow_message_header_tag",sxq_arrow_message_header_tag_fields,SX_COUNT(sxq_arrow_message_header_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_message_header_fields[] = {
    SX_FIELD("header", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_message_header = {UINT32_C(0x601F0022),"arrow_message_header",sxq_arrow_message_header_fields,SX_COUNT(sxq_arrow_message_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_message_body_length_fields[] = {
    SX_FIELD("body_length", "int64", 0, 8, SX_SIZE),
};
static const sx_layout sxq_arrow_message_body_length = {UINT32_C(0x601F0023),"arrow_message_body_length",sxq_arrow_message_body_length_fields,SX_COUNT(sxq_arrow_message_body_length_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_message_custom_metadata_fields[] = {
    SX_FIELD("custom_metadata", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_message_custom_metadata = {UINT32_C(0x601F0024),"arrow_message_custom_metadata",sxq_arrow_message_custom_metadata_fields,SX_COUNT(sxq_arrow_message_custom_metadata_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_record_batch_length_fields[] = {
    SX_FIELD("length", "int64", 0, 8, SX_COUNT_PROP),
};
static const sx_layout sxq_arrow_record_batch_length = {UINT32_C(0x601F0025),"arrow_record_batch_length",sxq_arrow_record_batch_length_fields,SX_COUNT(sxq_arrow_record_batch_length_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_record_batch_nodes_fields[] = {
    SX_FIELD("nodes", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_record_batch_nodes = {UINT32_C(0x601F0026),"arrow_record_batch_nodes",sxq_arrow_record_batch_nodes_fields,SX_COUNT(sxq_arrow_record_batch_nodes_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_record_batch_buffers_fields[] = {
    SX_FIELD("buffers", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_record_batch_buffers = {UINT32_C(0x601F0027),"arrow_record_batch_buffers",sxq_arrow_record_batch_buffers_fields,SX_COUNT(sxq_arrow_record_batch_buffers_fields),SX_LE};

static const xx_data_struct_field_desc sxq_arrow_record_batch_variadic_buffer_counts_fields[] = {
    SX_FIELD("variadic_buffer_counts", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_arrow_record_batch_variadic_buffer_counts = {UINT32_C(0x601F0028),"arrow_record_batch_variadic_buffer_counts",sxq_arrow_record_batch_variadic_buffer_counts_fields,SX_COUNT(sxq_arrow_record_batch_variadic_buffer_counts_fields),SX_LE};

static const xx_data_struct_field_desc sxq_parquet_file_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
};
static const sx_layout sxq_parquet_file_header = {UINT32_C(0x601F0029),"parquet_file_header",sxq_parquet_file_header_fields,SX_COUNT(sxq_parquet_file_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_parquet_file_trailer_fields[] = {
    SX_FIELD("metadata_length", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("magic", "char[4]", 4, 4, SX_SIGNATURE),
};
static const sx_layout sxq_parquet_file_trailer = {UINT32_C(0x601F002A),"parquet_file_trailer",sxq_parquet_file_trailer_fields,SX_COUNT(sxq_parquet_file_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_field_header_fields[] = {
    SX_FIELD("field_delta_and_type", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxq_thrift_field_header = {UINT32_C(0x601F002B),"thrift_field_header",sxq_thrift_field_header_fields,SX_COUNT(sxq_thrift_field_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_list_header_fields[] = {
    SX_FIELD("count_and_element_type", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sxq_thrift_list_header = {UINT32_C(0x601F002C),"thrift_list_header",sxq_thrift_list_header_fields,SX_COUNT(sxq_thrift_list_header_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_map_types_fields[] = {
    SX_FIELD("key_and_value_type", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxq_thrift_map_types = {UINT32_C(0x601F002D),"thrift_map_types",sxq_thrift_map_types_fields,SX_COUNT(sxq_thrift_map_types_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_boolean_value_fields[] = {
    SX_FIELD("boolean_type", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sxq_thrift_boolean_value = {UINT32_C(0x601F002E),"thrift_boolean_value",sxq_thrift_boolean_value_fields,SX_COUNT(sxq_thrift_boolean_value_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_byte_value_fields[] = {
    SX_FIELD("value", "int8", 0, 1, SX_NONE),
};
static const sx_layout sxq_thrift_byte_value = {UINT32_C(0x601F002F),"thrift_byte_value",sxq_thrift_byte_value_fields,SX_COUNT(sxq_thrift_byte_value_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_double_bits_fields[] = {
    SX_FIELD("ieee754_binary64_bits", "uint64", 0, 8, SX_NONE),
};
static const sx_layout sxq_thrift_double_bits = {UINT32_C(0x601F0030),"thrift_double_bits",sxq_thrift_double_bits_fields,SX_COUNT(sxq_thrift_double_bits_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_1_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 1, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_1 = {UINT32_C(0x601F0031),"columnar_varuint_size_1",sxq_columnar_varuint_size_1_fields,SX_COUNT(sxq_columnar_varuint_size_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_2_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 2, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_2 = {UINT32_C(0x601F0032),"columnar_varuint_size_2",sxq_columnar_varuint_size_2_fields,SX_COUNT(sxq_columnar_varuint_size_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_3_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 3, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_3 = {UINT32_C(0x601F0033),"columnar_varuint_size_3",sxq_columnar_varuint_size_3_fields,SX_COUNT(sxq_columnar_varuint_size_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_4_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 4, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_4 = {UINT32_C(0x601F0034),"columnar_varuint_size_4",sxq_columnar_varuint_size_4_fields,SX_COUNT(sxq_columnar_varuint_size_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_5_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 5, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_5 = {UINT32_C(0x601F0035),"columnar_varuint_size_5",sxq_columnar_varuint_size_5_fields,SX_COUNT(sxq_columnar_varuint_size_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_6_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 6, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_6 = {UINT32_C(0x601F0036),"columnar_varuint_size_6",sxq_columnar_varuint_size_6_fields,SX_COUNT(sxq_columnar_varuint_size_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_7_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 7, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_7 = {UINT32_C(0x601F0037),"columnar_varuint_size_7",sxq_columnar_varuint_size_7_fields,SX_COUNT(sxq_columnar_varuint_size_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_8_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 8, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_8 = {UINT32_C(0x601F0038),"columnar_varuint_size_8",sxq_columnar_varuint_size_8_fields,SX_COUNT(sxq_columnar_varuint_size_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_9_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 9, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_9 = {UINT32_C(0x601F0039),"columnar_varuint_size_9",sxq_columnar_varuint_size_9_fields,SX_COUNT(sxq_columnar_varuint_size_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_size_10_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 10, SX_SIZE),
};
static const sx_layout sxq_columnar_varuint_size_10 = {UINT32_C(0x601F003A),"columnar_varuint_size_10",sxq_columnar_varuint_size_10_fields,SX_COUNT(sxq_columnar_varuint_size_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_1_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 1, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_1 = {UINT32_C(0x601F003B),"columnar_varuint_count_1",sxq_columnar_varuint_count_1_fields,SX_COUNT(sxq_columnar_varuint_count_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_2_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_2 = {UINT32_C(0x601F003C),"columnar_varuint_count_2",sxq_columnar_varuint_count_2_fields,SX_COUNT(sxq_columnar_varuint_count_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_3_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 3, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_3 = {UINT32_C(0x601F003D),"columnar_varuint_count_3",sxq_columnar_varuint_count_3_fields,SX_COUNT(sxq_columnar_varuint_count_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_4_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_4 = {UINT32_C(0x601F003E),"columnar_varuint_count_4",sxq_columnar_varuint_count_4_fields,SX_COUNT(sxq_columnar_varuint_count_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_5_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 5, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_5 = {UINT32_C(0x601F003F),"columnar_varuint_count_5",sxq_columnar_varuint_count_5_fields,SX_COUNT(sxq_columnar_varuint_count_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_6_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 6, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_6 = {UINT32_C(0x601F0040),"columnar_varuint_count_6",sxq_columnar_varuint_count_6_fields,SX_COUNT(sxq_columnar_varuint_count_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_7_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 7, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_7 = {UINT32_C(0x601F0041),"columnar_varuint_count_7",sxq_columnar_varuint_count_7_fields,SX_COUNT(sxq_columnar_varuint_count_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_8_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 8, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_8 = {UINT32_C(0x601F0042),"columnar_varuint_count_8",sxq_columnar_varuint_count_8_fields,SX_COUNT(sxq_columnar_varuint_count_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_9_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 9, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_9 = {UINT32_C(0x601F0043),"columnar_varuint_count_9",sxq_columnar_varuint_count_9_fields,SX_COUNT(sxq_columnar_varuint_count_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_columnar_varuint_count_10_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 10, SX_COUNT_PROP),
};
static const sx_layout sxq_columnar_varuint_count_10 = {UINT32_C(0x601F0044),"columnar_varuint_count_10",sxq_columnar_varuint_count_10_fields,SX_COUNT(sxq_columnar_varuint_count_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_1_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 1, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_1 = {UINT32_C(0x601F0045),"thrift_i16_id_1",sxq_thrift_i16_id_1_fields,SX_COUNT(sxq_thrift_i16_id_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_2_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 2, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_2 = {UINT32_C(0x601F0046),"thrift_i16_id_2",sxq_thrift_i16_id_2_fields,SX_COUNT(sxq_thrift_i16_id_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_3_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 3, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_3 = {UINT32_C(0x601F0047),"thrift_i16_id_3",sxq_thrift_i16_id_3_fields,SX_COUNT(sxq_thrift_i16_id_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_4_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 4, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_4 = {UINT32_C(0x601F0048),"thrift_i16_id_4",sxq_thrift_i16_id_4_fields,SX_COUNT(sxq_thrift_i16_id_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_5_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 5, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_5 = {UINT32_C(0x601F0049),"thrift_i16_id_5",sxq_thrift_i16_id_5_fields,SX_COUNT(sxq_thrift_i16_id_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_6_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 6, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_6 = {UINT32_C(0x601F004A),"thrift_i16_id_6",sxq_thrift_i16_id_6_fields,SX_COUNT(sxq_thrift_i16_id_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_7_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 7, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_7 = {UINT32_C(0x601F004B),"thrift_i16_id_7",sxq_thrift_i16_id_7_fields,SX_COUNT(sxq_thrift_i16_id_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_8_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 8, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_8 = {UINT32_C(0x601F004C),"thrift_i16_id_8",sxq_thrift_i16_id_8_fields,SX_COUNT(sxq_thrift_i16_id_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_9_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 9, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_9 = {UINT32_C(0x601F004D),"thrift_i16_id_9",sxq_thrift_i16_id_9_fields,SX_COUNT(sxq_thrift_i16_id_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_id_10_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 10, SX_ID),
};
static const sx_layout sxq_thrift_i16_id_10 = {UINT32_C(0x601F004E),"thrift_i16_id_10",sxq_thrift_i16_id_10_fields,SX_COUNT(sxq_thrift_i16_id_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_1_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 1, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_1 = {UINT32_C(0x601F004F),"thrift_i16_value_1",sxq_thrift_i16_value_1_fields,SX_COUNT(sxq_thrift_i16_value_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_2_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 2, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_2 = {UINT32_C(0x601F0050),"thrift_i16_value_2",sxq_thrift_i16_value_2_fields,SX_COUNT(sxq_thrift_i16_value_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_3_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 3, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_3 = {UINT32_C(0x601F0051),"thrift_i16_value_3",sxq_thrift_i16_value_3_fields,SX_COUNT(sxq_thrift_i16_value_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_4_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 4, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_4 = {UINT32_C(0x601F0052),"thrift_i16_value_4",sxq_thrift_i16_value_4_fields,SX_COUNT(sxq_thrift_i16_value_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_5_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 5, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_5 = {UINT32_C(0x601F0053),"thrift_i16_value_5",sxq_thrift_i16_value_5_fields,SX_COUNT(sxq_thrift_i16_value_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_6_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 6, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_6 = {UINT32_C(0x601F0054),"thrift_i16_value_6",sxq_thrift_i16_value_6_fields,SX_COUNT(sxq_thrift_i16_value_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_7_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 7, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_7 = {UINT32_C(0x601F0055),"thrift_i16_value_7",sxq_thrift_i16_value_7_fields,SX_COUNT(sxq_thrift_i16_value_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_8_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 8, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_8 = {UINT32_C(0x601F0056),"thrift_i16_value_8",sxq_thrift_i16_value_8_fields,SX_COUNT(sxq_thrift_i16_value_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_9_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 9, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_9 = {UINT32_C(0x601F0057),"thrift_i16_value_9",sxq_thrift_i16_value_9_fields,SX_COUNT(sxq_thrift_i16_value_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i16_value_10_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 10, SX_NONE),
};
static const sx_layout sxq_thrift_i16_value_10 = {UINT32_C(0x601F0058),"thrift_i16_value_10",sxq_thrift_i16_value_10_fields,SX_COUNT(sxq_thrift_i16_value_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_1_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 1, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_1 = {UINT32_C(0x601F0059),"thrift_i32_id_1",sxq_thrift_i32_id_1_fields,SX_COUNT(sxq_thrift_i32_id_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_2_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 2, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_2 = {UINT32_C(0x601F005A),"thrift_i32_id_2",sxq_thrift_i32_id_2_fields,SX_COUNT(sxq_thrift_i32_id_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_3_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 3, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_3 = {UINT32_C(0x601F005B),"thrift_i32_id_3",sxq_thrift_i32_id_3_fields,SX_COUNT(sxq_thrift_i32_id_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_4_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 4, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_4 = {UINT32_C(0x601F005C),"thrift_i32_id_4",sxq_thrift_i32_id_4_fields,SX_COUNT(sxq_thrift_i32_id_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_5_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 5, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_5 = {UINT32_C(0x601F005D),"thrift_i32_id_5",sxq_thrift_i32_id_5_fields,SX_COUNT(sxq_thrift_i32_id_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_6_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 6, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_6 = {UINT32_C(0x601F005E),"thrift_i32_id_6",sxq_thrift_i32_id_6_fields,SX_COUNT(sxq_thrift_i32_id_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_7_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 7, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_7 = {UINT32_C(0x601F005F),"thrift_i32_id_7",sxq_thrift_i32_id_7_fields,SX_COUNT(sxq_thrift_i32_id_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_8_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 8, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_8 = {UINT32_C(0x601F0060),"thrift_i32_id_8",sxq_thrift_i32_id_8_fields,SX_COUNT(sxq_thrift_i32_id_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_9_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 9, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_9 = {UINT32_C(0x601F0061),"thrift_i32_id_9",sxq_thrift_i32_id_9_fields,SX_COUNT(sxq_thrift_i32_id_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_id_10_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 10, SX_ID),
};
static const sx_layout sxq_thrift_i32_id_10 = {UINT32_C(0x601F0062),"thrift_i32_id_10",sxq_thrift_i32_id_10_fields,SX_COUNT(sxq_thrift_i32_id_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_1_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 1, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_1 = {UINT32_C(0x601F0063),"thrift_i32_value_1",sxq_thrift_i32_value_1_fields,SX_COUNT(sxq_thrift_i32_value_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_2_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 2, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_2 = {UINT32_C(0x601F0064),"thrift_i32_value_2",sxq_thrift_i32_value_2_fields,SX_COUNT(sxq_thrift_i32_value_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_3_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 3, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_3 = {UINT32_C(0x601F0065),"thrift_i32_value_3",sxq_thrift_i32_value_3_fields,SX_COUNT(sxq_thrift_i32_value_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_4_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 4, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_4 = {UINT32_C(0x601F0066),"thrift_i32_value_4",sxq_thrift_i32_value_4_fields,SX_COUNT(sxq_thrift_i32_value_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_5_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 5, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_5 = {UINT32_C(0x601F0067),"thrift_i32_value_5",sxq_thrift_i32_value_5_fields,SX_COUNT(sxq_thrift_i32_value_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_6_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 6, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_6 = {UINT32_C(0x601F0068),"thrift_i32_value_6",sxq_thrift_i32_value_6_fields,SX_COUNT(sxq_thrift_i32_value_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_7_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 7, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_7 = {UINT32_C(0x601F0069),"thrift_i32_value_7",sxq_thrift_i32_value_7_fields,SX_COUNT(sxq_thrift_i32_value_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_8_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 8, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_8 = {UINT32_C(0x601F006A),"thrift_i32_value_8",sxq_thrift_i32_value_8_fields,SX_COUNT(sxq_thrift_i32_value_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_9_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 9, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_9 = {UINT32_C(0x601F006B),"thrift_i32_value_9",sxq_thrift_i32_value_9_fields,SX_COUNT(sxq_thrift_i32_value_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_value_10_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 10, SX_NONE),
};
static const sx_layout sxq_thrift_i32_value_10 = {UINT32_C(0x601F006C),"thrift_i32_value_10",sxq_thrift_i32_value_10_fields,SX_COUNT(sxq_thrift_i32_value_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_1_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 1, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_1 = {UINT32_C(0x601F006D),"thrift_i32_size_1",sxq_thrift_i32_size_1_fields,SX_COUNT(sxq_thrift_i32_size_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_2_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 2, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_2 = {UINT32_C(0x601F006E),"thrift_i32_size_2",sxq_thrift_i32_size_2_fields,SX_COUNT(sxq_thrift_i32_size_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_3_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 3, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_3 = {UINT32_C(0x601F006F),"thrift_i32_size_3",sxq_thrift_i32_size_3_fields,SX_COUNT(sxq_thrift_i32_size_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_4_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 4, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_4 = {UINT32_C(0x601F0070),"thrift_i32_size_4",sxq_thrift_i32_size_4_fields,SX_COUNT(sxq_thrift_i32_size_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_5_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 5, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_5 = {UINT32_C(0x601F0071),"thrift_i32_size_5",sxq_thrift_i32_size_5_fields,SX_COUNT(sxq_thrift_i32_size_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_6_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 6, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_6 = {UINT32_C(0x601F0072),"thrift_i32_size_6",sxq_thrift_i32_size_6_fields,SX_COUNT(sxq_thrift_i32_size_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_7_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 7, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_7 = {UINT32_C(0x601F0073),"thrift_i32_size_7",sxq_thrift_i32_size_7_fields,SX_COUNT(sxq_thrift_i32_size_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_8_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 8, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_8 = {UINT32_C(0x601F0074),"thrift_i32_size_8",sxq_thrift_i32_size_8_fields,SX_COUNT(sxq_thrift_i32_size_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_9_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 9, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_9 = {UINT32_C(0x601F0075),"thrift_i32_size_9",sxq_thrift_i32_size_9_fields,SX_COUNT(sxq_thrift_i32_size_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_size_10_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 10, SX_SIZE),
};
static const sx_layout sxq_thrift_i32_size_10 = {UINT32_C(0x601F0076),"thrift_i32_size_10",sxq_thrift_i32_size_10_fields,SX_COUNT(sxq_thrift_i32_size_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_1_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 1, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_1 = {UINT32_C(0x601F0077),"thrift_i32_count_1",sxq_thrift_i32_count_1_fields,SX_COUNT(sxq_thrift_i32_count_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_2_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_2 = {UINT32_C(0x601F0078),"thrift_i32_count_2",sxq_thrift_i32_count_2_fields,SX_COUNT(sxq_thrift_i32_count_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_3_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 3, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_3 = {UINT32_C(0x601F0079),"thrift_i32_count_3",sxq_thrift_i32_count_3_fields,SX_COUNT(sxq_thrift_i32_count_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_4_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_4 = {UINT32_C(0x601F007A),"thrift_i32_count_4",sxq_thrift_i32_count_4_fields,SX_COUNT(sxq_thrift_i32_count_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_5_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 5, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_5 = {UINT32_C(0x601F007B),"thrift_i32_count_5",sxq_thrift_i32_count_5_fields,SX_COUNT(sxq_thrift_i32_count_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_6_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 6, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_6 = {UINT32_C(0x601F007C),"thrift_i32_count_6",sxq_thrift_i32_count_6_fields,SX_COUNT(sxq_thrift_i32_count_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_7_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 7, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_7 = {UINT32_C(0x601F007D),"thrift_i32_count_7",sxq_thrift_i32_count_7_fields,SX_COUNT(sxq_thrift_i32_count_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_8_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 8, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_8 = {UINT32_C(0x601F007E),"thrift_i32_count_8",sxq_thrift_i32_count_8_fields,SX_COUNT(sxq_thrift_i32_count_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_9_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 9, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_9 = {UINT32_C(0x601F007F),"thrift_i32_count_9",sxq_thrift_i32_count_9_fields,SX_COUNT(sxq_thrift_i32_count_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i32_count_10_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 10, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i32_count_10 = {UINT32_C(0x601F0080),"thrift_i32_count_10",sxq_thrift_i32_count_10_fields,SX_COUNT(sxq_thrift_i32_count_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_1_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 1, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_1 = {UINT32_C(0x601F0081),"thrift_i64_value_1",sxq_thrift_i64_value_1_fields,SX_COUNT(sxq_thrift_i64_value_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_2_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 2, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_2 = {UINT32_C(0x601F0082),"thrift_i64_value_2",sxq_thrift_i64_value_2_fields,SX_COUNT(sxq_thrift_i64_value_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_3_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 3, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_3 = {UINT32_C(0x601F0083),"thrift_i64_value_3",sxq_thrift_i64_value_3_fields,SX_COUNT(sxq_thrift_i64_value_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_4_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 4, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_4 = {UINT32_C(0x601F0084),"thrift_i64_value_4",sxq_thrift_i64_value_4_fields,SX_COUNT(sxq_thrift_i64_value_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_5_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 5, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_5 = {UINT32_C(0x601F0085),"thrift_i64_value_5",sxq_thrift_i64_value_5_fields,SX_COUNT(sxq_thrift_i64_value_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_6_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 6, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_6 = {UINT32_C(0x601F0086),"thrift_i64_value_6",sxq_thrift_i64_value_6_fields,SX_COUNT(sxq_thrift_i64_value_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_7_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 7, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_7 = {UINT32_C(0x601F0087),"thrift_i64_value_7",sxq_thrift_i64_value_7_fields,SX_COUNT(sxq_thrift_i64_value_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_8_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 8, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_8 = {UINT32_C(0x601F0088),"thrift_i64_value_8",sxq_thrift_i64_value_8_fields,SX_COUNT(sxq_thrift_i64_value_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_9_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 9, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_9 = {UINT32_C(0x601F0089),"thrift_i64_value_9",sxq_thrift_i64_value_9_fields,SX_COUNT(sxq_thrift_i64_value_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_value_10_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 10, SX_NONE),
};
static const sx_layout sxq_thrift_i64_value_10 = {UINT32_C(0x601F008A),"thrift_i64_value_10",sxq_thrift_i64_value_10_fields,SX_COUNT(sxq_thrift_i64_value_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_1_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 1, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_1 = {UINT32_C(0x601F008B),"thrift_i64_offset_1",sxq_thrift_i64_offset_1_fields,SX_COUNT(sxq_thrift_i64_offset_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_2_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 2, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_2 = {UINT32_C(0x601F008C),"thrift_i64_offset_2",sxq_thrift_i64_offset_2_fields,SX_COUNT(sxq_thrift_i64_offset_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_3_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 3, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_3 = {UINT32_C(0x601F008D),"thrift_i64_offset_3",sxq_thrift_i64_offset_3_fields,SX_COUNT(sxq_thrift_i64_offset_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_4_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 4, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_4 = {UINT32_C(0x601F008E),"thrift_i64_offset_4",sxq_thrift_i64_offset_4_fields,SX_COUNT(sxq_thrift_i64_offset_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_5_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 5, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_5 = {UINT32_C(0x601F008F),"thrift_i64_offset_5",sxq_thrift_i64_offset_5_fields,SX_COUNT(sxq_thrift_i64_offset_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_6_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 6, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_6 = {UINT32_C(0x601F0090),"thrift_i64_offset_6",sxq_thrift_i64_offset_6_fields,SX_COUNT(sxq_thrift_i64_offset_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_7_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 7, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_7 = {UINT32_C(0x601F0091),"thrift_i64_offset_7",sxq_thrift_i64_offset_7_fields,SX_COUNT(sxq_thrift_i64_offset_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_8_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 8, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_8 = {UINT32_C(0x601F0092),"thrift_i64_offset_8",sxq_thrift_i64_offset_8_fields,SX_COUNT(sxq_thrift_i64_offset_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_9_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 9, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_9 = {UINT32_C(0x601F0093),"thrift_i64_offset_9",sxq_thrift_i64_offset_9_fields,SX_COUNT(sxq_thrift_i64_offset_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_offset_10_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 10, SX_OFFSET),
};
static const sx_layout sxq_thrift_i64_offset_10 = {UINT32_C(0x601F0094),"thrift_i64_offset_10",sxq_thrift_i64_offset_10_fields,SX_COUNT(sxq_thrift_i64_offset_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_1_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 1, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_1 = {UINT32_C(0x601F0095),"thrift_i64_size_1",sxq_thrift_i64_size_1_fields,SX_COUNT(sxq_thrift_i64_size_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_2_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 2, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_2 = {UINT32_C(0x601F0096),"thrift_i64_size_2",sxq_thrift_i64_size_2_fields,SX_COUNT(sxq_thrift_i64_size_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_3_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 3, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_3 = {UINT32_C(0x601F0097),"thrift_i64_size_3",sxq_thrift_i64_size_3_fields,SX_COUNT(sxq_thrift_i64_size_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_4_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 4, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_4 = {UINT32_C(0x601F0098),"thrift_i64_size_4",sxq_thrift_i64_size_4_fields,SX_COUNT(sxq_thrift_i64_size_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_5_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 5, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_5 = {UINT32_C(0x601F0099),"thrift_i64_size_5",sxq_thrift_i64_size_5_fields,SX_COUNT(sxq_thrift_i64_size_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_6_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 6, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_6 = {UINT32_C(0x601F009A),"thrift_i64_size_6",sxq_thrift_i64_size_6_fields,SX_COUNT(sxq_thrift_i64_size_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_7_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 7, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_7 = {UINT32_C(0x601F009B),"thrift_i64_size_7",sxq_thrift_i64_size_7_fields,SX_COUNT(sxq_thrift_i64_size_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_8_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 8, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_8 = {UINT32_C(0x601F009C),"thrift_i64_size_8",sxq_thrift_i64_size_8_fields,SX_COUNT(sxq_thrift_i64_size_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_9_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 9, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_9 = {UINT32_C(0x601F009D),"thrift_i64_size_9",sxq_thrift_i64_size_9_fields,SX_COUNT(sxq_thrift_i64_size_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_size_10_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 10, SX_SIZE),
};
static const sx_layout sxq_thrift_i64_size_10 = {UINT32_C(0x601F009E),"thrift_i64_size_10",sxq_thrift_i64_size_10_fields,SX_COUNT(sxq_thrift_i64_size_10_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_1_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 1, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_1 = {UINT32_C(0x601F009F),"thrift_i64_count_1",sxq_thrift_i64_count_1_fields,SX_COUNT(sxq_thrift_i64_count_1_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_2_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_2 = {UINT32_C(0x601F00A0),"thrift_i64_count_2",sxq_thrift_i64_count_2_fields,SX_COUNT(sxq_thrift_i64_count_2_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_3_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 3, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_3 = {UINT32_C(0x601F00A1),"thrift_i64_count_3",sxq_thrift_i64_count_3_fields,SX_COUNT(sxq_thrift_i64_count_3_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_4_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_4 = {UINT32_C(0x601F00A2),"thrift_i64_count_4",sxq_thrift_i64_count_4_fields,SX_COUNT(sxq_thrift_i64_count_4_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_5_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 5, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_5 = {UINT32_C(0x601F00A3),"thrift_i64_count_5",sxq_thrift_i64_count_5_fields,SX_COUNT(sxq_thrift_i64_count_5_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_6_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 6, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_6 = {UINT32_C(0x601F00A4),"thrift_i64_count_6",sxq_thrift_i64_count_6_fields,SX_COUNT(sxq_thrift_i64_count_6_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_7_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 7, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_7 = {UINT32_C(0x601F00A5),"thrift_i64_count_7",sxq_thrift_i64_count_7_fields,SX_COUNT(sxq_thrift_i64_count_7_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_8_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 8, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_8 = {UINT32_C(0x601F00A6),"thrift_i64_count_8",sxq_thrift_i64_count_8_fields,SX_COUNT(sxq_thrift_i64_count_8_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_9_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 9, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_9 = {UINT32_C(0x601F00A7),"thrift_i64_count_9",sxq_thrift_i64_count_9_fields,SX_COUNT(sxq_thrift_i64_count_9_fields),SX_LE};

static const xx_data_struct_field_desc sxq_thrift_i64_count_10_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 10, SX_COUNT_PROP),
};
static const sx_layout sxq_thrift_i64_count_10 = {UINT32_C(0x601F00A8),"thrift_i64_count_10",sxq_thrift_i64_count_10_fields,SX_COUNT(sxq_thrift_i64_count_10_fields),SX_LE};

static const sx_layout *const sx_columnar_layouts[] = {
    &sxq_arrow_file_header,
    &sxq_arrow_file_trailer,
    &sxq_arrow_message_prefix,
    &sxq_arrow_continuation_prefix,
    &sxq_arrow_flatbuffer_root,
    &sxq_arrow_table_header,
    &sxq_arrow_vtable_header,
    &sxq_arrow_vtable_entry,
    &sxq_arrow_vector_header,
    &sxq_arrow_vector_reference,
    &sxq_arrow_string_header,
    &sxq_arrow_block,
    &sxq_arrow_field_node,
    &sxq_arrow_buffer,
    &sxq_arrow_footer_version,
    &sxq_arrow_footer_schema,
    &sxq_arrow_footer_dictionaries,
    &sxq_arrow_footer_record_batches,
    &sxq_arrow_footer_custom_metadata,
    &sxq_arrow_schema_endianness,
    &sxq_arrow_schema_fields,
    &sxq_arrow_schema_custom_metadata,
    &sxq_arrow_schema_features,
    &sxq_arrow_field_name,
    &sxq_arrow_field_nullable,
    &sxq_arrow_field_type_tag,
    &sxq_arrow_field_type,
    &sxq_arrow_field_children,
    &sxq_arrow_field_custom_metadata,
    &sxq_arrow_int_type_bit_width,
    &sxq_arrow_int_type_is_signed,
    &sxq_arrow_message_version,
    &sxq_arrow_message_header_tag,
    &sxq_arrow_message_header,
    &sxq_arrow_message_body_length,
    &sxq_arrow_message_custom_metadata,
    &sxq_arrow_record_batch_length,
    &sxq_arrow_record_batch_nodes,
    &sxq_arrow_record_batch_buffers,
    &sxq_arrow_record_batch_variadic_buffer_counts,
    &sxq_parquet_file_header,
    &sxq_parquet_file_trailer,
    &sxq_thrift_field_header,
    &sxq_thrift_list_header,
    &sxq_thrift_map_types,
    &sxq_thrift_boolean_value,
    &sxq_thrift_byte_value,
    &sxq_thrift_double_bits,
    &sxq_columnar_varuint_size_1,
    &sxq_columnar_varuint_size_2,
    &sxq_columnar_varuint_size_3,
    &sxq_columnar_varuint_size_4,
    &sxq_columnar_varuint_size_5,
    &sxq_columnar_varuint_size_6,
    &sxq_columnar_varuint_size_7,
    &sxq_columnar_varuint_size_8,
    &sxq_columnar_varuint_size_9,
    &sxq_columnar_varuint_size_10,
    &sxq_columnar_varuint_count_1,
    &sxq_columnar_varuint_count_2,
    &sxq_columnar_varuint_count_3,
    &sxq_columnar_varuint_count_4,
    &sxq_columnar_varuint_count_5,
    &sxq_columnar_varuint_count_6,
    &sxq_columnar_varuint_count_7,
    &sxq_columnar_varuint_count_8,
    &sxq_columnar_varuint_count_9,
    &sxq_columnar_varuint_count_10,
    &sxq_thrift_i16_id_1,
    &sxq_thrift_i16_id_2,
    &sxq_thrift_i16_id_3,
    &sxq_thrift_i16_id_4,
    &sxq_thrift_i16_id_5,
    &sxq_thrift_i16_id_6,
    &sxq_thrift_i16_id_7,
    &sxq_thrift_i16_id_8,
    &sxq_thrift_i16_id_9,
    &sxq_thrift_i16_id_10,
    &sxq_thrift_i16_value_1,
    &sxq_thrift_i16_value_2,
    &sxq_thrift_i16_value_3,
    &sxq_thrift_i16_value_4,
    &sxq_thrift_i16_value_5,
    &sxq_thrift_i16_value_6,
    &sxq_thrift_i16_value_7,
    &sxq_thrift_i16_value_8,
    &sxq_thrift_i16_value_9,
    &sxq_thrift_i16_value_10,
    &sxq_thrift_i32_id_1,
    &sxq_thrift_i32_id_2,
    &sxq_thrift_i32_id_3,
    &sxq_thrift_i32_id_4,
    &sxq_thrift_i32_id_5,
    &sxq_thrift_i32_id_6,
    &sxq_thrift_i32_id_7,
    &sxq_thrift_i32_id_8,
    &sxq_thrift_i32_id_9,
    &sxq_thrift_i32_id_10,
    &sxq_thrift_i32_value_1,
    &sxq_thrift_i32_value_2,
    &sxq_thrift_i32_value_3,
    &sxq_thrift_i32_value_4,
    &sxq_thrift_i32_value_5,
    &sxq_thrift_i32_value_6,
    &sxq_thrift_i32_value_7,
    &sxq_thrift_i32_value_8,
    &sxq_thrift_i32_value_9,
    &sxq_thrift_i32_value_10,
    &sxq_thrift_i32_size_1,
    &sxq_thrift_i32_size_2,
    &sxq_thrift_i32_size_3,
    &sxq_thrift_i32_size_4,
    &sxq_thrift_i32_size_5,
    &sxq_thrift_i32_size_6,
    &sxq_thrift_i32_size_7,
    &sxq_thrift_i32_size_8,
    &sxq_thrift_i32_size_9,
    &sxq_thrift_i32_size_10,
    &sxq_thrift_i32_count_1,
    &sxq_thrift_i32_count_2,
    &sxq_thrift_i32_count_3,
    &sxq_thrift_i32_count_4,
    &sxq_thrift_i32_count_5,
    &sxq_thrift_i32_count_6,
    &sxq_thrift_i32_count_7,
    &sxq_thrift_i32_count_8,
    &sxq_thrift_i32_count_9,
    &sxq_thrift_i32_count_10,
    &sxq_thrift_i64_value_1,
    &sxq_thrift_i64_value_2,
    &sxq_thrift_i64_value_3,
    &sxq_thrift_i64_value_4,
    &sxq_thrift_i64_value_5,
    &sxq_thrift_i64_value_6,
    &sxq_thrift_i64_value_7,
    &sxq_thrift_i64_value_8,
    &sxq_thrift_i64_value_9,
    &sxq_thrift_i64_value_10,
    &sxq_thrift_i64_offset_1,
    &sxq_thrift_i64_offset_2,
    &sxq_thrift_i64_offset_3,
    &sxq_thrift_i64_offset_4,
    &sxq_thrift_i64_offset_5,
    &sxq_thrift_i64_offset_6,
    &sxq_thrift_i64_offset_7,
    &sxq_thrift_i64_offset_8,
    &sxq_thrift_i64_offset_9,
    &sxq_thrift_i64_offset_10,
    &sxq_thrift_i64_size_1,
    &sxq_thrift_i64_size_2,
    &sxq_thrift_i64_size_3,
    &sxq_thrift_i64_size_4,
    &sxq_thrift_i64_size_5,
    &sxq_thrift_i64_size_6,
    &sxq_thrift_i64_size_7,
    &sxq_thrift_i64_size_8,
    &sxq_thrift_i64_size_9,
    &sxq_thrift_i64_size_10,
    &sxq_thrift_i64_count_1,
    &sxq_thrift_i64_count_2,
    &sxq_thrift_i64_count_3,
    &sxq_thrift_i64_count_4,
    &sxq_thrift_i64_count_5,
    &sxq_thrift_i64_count_6,
    &sxq_thrift_i64_count_7,
    &sxq_thrift_i64_count_8,
    &sxq_thrift_i64_count_9,
    &sxq_thrift_i64_count_10,
};

static const sx_layout *const sxq_arrow_footer_rows[]={&sxq_arrow_footer_version,&sxq_arrow_footer_schema,&sxq_arrow_footer_dictionaries,&sxq_arrow_footer_record_batches,&sxq_arrow_footer_custom_metadata};
static const sx_layout *const sxq_arrow_schema_rows[]={&sxq_arrow_schema_endianness,&sxq_arrow_schema_fields,&sxq_arrow_schema_custom_metadata,&sxq_arrow_schema_features};
static const sx_layout *const sxq_arrow_field_rows[]={&sxq_arrow_field_name,&sxq_arrow_field_nullable,&sxq_arrow_field_type_tag,&sxq_arrow_field_type,NULL,&sxq_arrow_field_children,&sxq_arrow_field_custom_metadata};
static const sx_layout *const sxq_arrow_int_type_rows[]={&sxq_arrow_int_type_bit_width,&sxq_arrow_int_type_is_signed};
static const sx_layout *const sxq_arrow_message_rows[]={&sxq_arrow_message_version,&sxq_arrow_message_header_tag,&sxq_arrow_message_header,&sxq_arrow_message_body_length,&sxq_arrow_message_custom_metadata};
static const sx_layout *const sxq_arrow_record_batch_rows[]={&sxq_arrow_record_batch_length,&sxq_arrow_record_batch_nodes,&sxq_arrow_record_batch_buffers,NULL,&sxq_arrow_record_batch_variadic_buffer_counts};
static const sx_layout *const sxq_columnar_varuint_size_rows[]={&sxq_columnar_varuint_size_1,&sxq_columnar_varuint_size_2,&sxq_columnar_varuint_size_3,&sxq_columnar_varuint_size_4,&sxq_columnar_varuint_size_5,&sxq_columnar_varuint_size_6,&sxq_columnar_varuint_size_7,&sxq_columnar_varuint_size_8,&sxq_columnar_varuint_size_9,&sxq_columnar_varuint_size_10};
static const sx_layout *const sxq_columnar_varuint_count_rows[]={&sxq_columnar_varuint_count_1,&sxq_columnar_varuint_count_2,&sxq_columnar_varuint_count_3,&sxq_columnar_varuint_count_4,&sxq_columnar_varuint_count_5,&sxq_columnar_varuint_count_6,&sxq_columnar_varuint_count_7,&sxq_columnar_varuint_count_8,&sxq_columnar_varuint_count_9,&sxq_columnar_varuint_count_10};
static const sx_layout *const sxq_thrift_i16_id_rows[]={&sxq_thrift_i16_id_1,&sxq_thrift_i16_id_2,&sxq_thrift_i16_id_3,&sxq_thrift_i16_id_4,&sxq_thrift_i16_id_5,&sxq_thrift_i16_id_6,&sxq_thrift_i16_id_7,&sxq_thrift_i16_id_8,&sxq_thrift_i16_id_9,&sxq_thrift_i16_id_10};
static const sx_layout *const sxq_thrift_i16_value_rows[]={&sxq_thrift_i16_value_1,&sxq_thrift_i16_value_2,&sxq_thrift_i16_value_3,&sxq_thrift_i16_value_4,&sxq_thrift_i16_value_5,&sxq_thrift_i16_value_6,&sxq_thrift_i16_value_7,&sxq_thrift_i16_value_8,&sxq_thrift_i16_value_9,&sxq_thrift_i16_value_10};
static const sx_layout *const sxq_thrift_i32_id_rows[]={&sxq_thrift_i32_id_1,&sxq_thrift_i32_id_2,&sxq_thrift_i32_id_3,&sxq_thrift_i32_id_4,&sxq_thrift_i32_id_5,&sxq_thrift_i32_id_6,&sxq_thrift_i32_id_7,&sxq_thrift_i32_id_8,&sxq_thrift_i32_id_9,&sxq_thrift_i32_id_10};
static const sx_layout *const sxq_thrift_i32_value_rows[]={&sxq_thrift_i32_value_1,&sxq_thrift_i32_value_2,&sxq_thrift_i32_value_3,&sxq_thrift_i32_value_4,&sxq_thrift_i32_value_5,&sxq_thrift_i32_value_6,&sxq_thrift_i32_value_7,&sxq_thrift_i32_value_8,&sxq_thrift_i32_value_9,&sxq_thrift_i32_value_10};
static const sx_layout *const sxq_thrift_i32_size_rows[]={&sxq_thrift_i32_size_1,&sxq_thrift_i32_size_2,&sxq_thrift_i32_size_3,&sxq_thrift_i32_size_4,&sxq_thrift_i32_size_5,&sxq_thrift_i32_size_6,&sxq_thrift_i32_size_7,&sxq_thrift_i32_size_8,&sxq_thrift_i32_size_9,&sxq_thrift_i32_size_10};
static const sx_layout *const sxq_thrift_i32_count_rows[]={&sxq_thrift_i32_count_1,&sxq_thrift_i32_count_2,&sxq_thrift_i32_count_3,&sxq_thrift_i32_count_4,&sxq_thrift_i32_count_5,&sxq_thrift_i32_count_6,&sxq_thrift_i32_count_7,&sxq_thrift_i32_count_8,&sxq_thrift_i32_count_9,&sxq_thrift_i32_count_10};
static const sx_layout *const sxq_thrift_i64_value_rows[]={&sxq_thrift_i64_value_1,&sxq_thrift_i64_value_2,&sxq_thrift_i64_value_3,&sxq_thrift_i64_value_4,&sxq_thrift_i64_value_5,&sxq_thrift_i64_value_6,&sxq_thrift_i64_value_7,&sxq_thrift_i64_value_8,&sxq_thrift_i64_value_9,&sxq_thrift_i64_value_10};
static const sx_layout *const sxq_thrift_i64_offset_rows[]={&sxq_thrift_i64_offset_1,&sxq_thrift_i64_offset_2,&sxq_thrift_i64_offset_3,&sxq_thrift_i64_offset_4,&sxq_thrift_i64_offset_5,&sxq_thrift_i64_offset_6,&sxq_thrift_i64_offset_7,&sxq_thrift_i64_offset_8,&sxq_thrift_i64_offset_9,&sxq_thrift_i64_offset_10};
static const sx_layout *const sxq_thrift_i64_size_rows[]={&sxq_thrift_i64_size_1,&sxq_thrift_i64_size_2,&sxq_thrift_i64_size_3,&sxq_thrift_i64_size_4,&sxq_thrift_i64_size_5,&sxq_thrift_i64_size_6,&sxq_thrift_i64_size_7,&sxq_thrift_i64_size_8,&sxq_thrift_i64_size_9,&sxq_thrift_i64_size_10};
static const sx_layout *const sxq_thrift_i64_count_rows[]={&sxq_thrift_i64_count_1,&sxq_thrift_i64_count_2,&sxq_thrift_i64_count_3,&sxq_thrift_i64_count_4,&sxq_thrift_i64_count_5,&sxq_thrift_i64_count_6,&sxq_thrift_i64_count_7,&sxq_thrift_i64_count_8,&sxq_thrift_i64_count_9,&sxq_thrift_i64_count_10};
/* Read only metadata windows. Column payload bytes remain on the original device. */
#define SXQ_RECORD_LIMIT 100000U
#define SXQ_META_LIMIT (16U*1024U*1024U)
typedef struct sxq_window { sx_context *c;uint8_t *b;size_t n;uint64_t base;unsigned work; } sxq_window;
static bool sxq_span(const sxq_window *w,uint64_t p,uint64_t n){return p<=w->n&&n<=w->n-p;}
static bool sxq_file_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static uint16_t sxq16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
static uint32_t sxq32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
static uint64_t sxq64(const uint8_t *p){return xx_data_get_u64(p,8,0,false);}
static bool sxq_window_open(sxq_window *w,sx_context *c,uint64_t base,uint64_t n){
 xx_mem_zero(w,sizeof(*w));if(n<4||n>SXQ_META_LIMIT||!sxq_file_span(c,base,n))return false;
 w->c=c;w->n=(size_t)n;w->base=base;w->b=xx_mem_alloc(w->n);if(!w->b)return false;
 if(!sx_read(c,(int64_t)base,w->b,w->n)){xx_mem_free(w->b);w->b=NULL;return false;}return true;
}
static bool sxq_add(sx_context *c,const sx_layout *l,uint64_t p){
 const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)f->rel_offset+(uint64_t)f->size;
 return c->count<SXQ_RECORD_LIMIT&&sxq_file_span(c,p,n)&&sx_add(c,l,(int64_t)p,(int64_t)n);
}
static bool sxq_wadd(sxq_window *w,const sx_layout *l,uint64_t p){
 const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return sxq_span(w,p,(uint64_t)f->rel_offset+(uint64_t)f->size)&&sxq_add(w->c,l,w->base+p);
}
static bool sxq_table(sxq_window *w,const sx_layout *l,uint64_t p,uint64_t n,uint64_t count){
 return !count||(count<=SXQ_RECORD_LIMIT&&n&&count<=UINT64_MAX/n&&sxq_span(w,p,n*count)&&sx_table(w->c,l,(int64_t)(w->base+p),(int64_t)n,count));
}
/* FlatBuffers offsets are relative to their own physical words; vtable displacement
 * is signed and is subtracted from the table address. */
static bool sxq_a_field(sxq_window *w,uint64_t t,unsigned id,unsigned width,uint64_t *out){
 if(!sxq_span(w,t,4))return false;int64_t delta=(int32_t)sxq32(w->b+t);int64_t vt=(int64_t)t-delta;
 if(vt<0||!sxq_span(w,(uint64_t)vt,4))return false;uint16_t vn=sxq16(w->b+vt),on=sxq16(w->b+vt+2);
 if(vn<4||(vn&1)||on<4||!sxq_span(w,(uint64_t)vt,vn)||!sxq_span(w,t,on))return false;
 *out=0;if((uint64_t)id*2+6>vn)return true;uint16_t off=sxq16(w->b+vt+4+id*2);
 if(!off)return true;if(off<4||off>on||width>on-off)return false;*out=t+off;return true;
}
static bool sxq_a_ref(sxq_window *w,uint64_t field,uint64_t *out){
 if(!field){*out=0;return true;}if(!sxq_span(w,field,4))return false;uint32_t d=sxq32(w->b+field);if(d<4||!sxq_span(w,field+d,4))return false;*out=field+d;return true;
}
static bool sxq_a_parse(sxq_window *w,uint64_t t,unsigned kind,unsigned depth);
static bool sxq_a_vector(sxq_window *w,uint64_t field,unsigned width,const sx_layout *l,int child,unsigned depth){
 uint64_t v;if(!sxq_a_ref(w,field,&v))return false;if(!v)return true;uint32_t n=sxq32(w->b+v);
 if(n>SXQ_RECORD_LIMIT||!sxq_span(w,v+4,(uint64_t)n*width)||!sxq_wadd(w,&sxq_arrow_vector_header,v))return false;
 if(l&&!sxq_table(w,l,v+4,width,n))return false;
 if(child>=0)for(uint32_t i=0;i<n;i++){uint64_t at=v+4+(uint64_t)i*4,p;if(!sxq_wadd(w,&sxq_arrow_vector_reference,at)||!sxq_a_ref(w,at,&p)||!sxq_a_parse(w,p,(unsigned)child,depth+1))return false;}
 return true;
}
static bool sxq_a_parse(sxq_window *w,uint64_t t,unsigned kind,unsigned depth){
 static const sx_layout *const *const sets[]={sxq_arrow_footer_rows,sxq_arrow_schema_rows,sxq_arrow_field_rows,sxq_arrow_int_type_rows,sxq_arrow_message_rows,sxq_arrow_record_batch_rows};
 static const unsigned counts[]={5,4,7,2,5,5};
 if(kind>=6||depth>24||++w->work>SXQ_RECORD_LIMIT||!sxq_span(w,t,4))return false;
 int64_t vt=(int64_t)t-(int32_t)sxq32(w->b+t);if(vt<0||!sxq_span(w,(uint64_t)vt,4))return false;
 uint16_t vn=sxq16(w->b+vt);uint64_t fields[7]={0};
 if(!sxq_wadd(w,&sxq_arrow_table_header,t)||!sxq_wadd(w,&sxq_arrow_vtable_header,(uint64_t)vt)||vn<4||(vn&1)||!sxq_table(w,&sxq_arrow_vtable_entry,(uint64_t)vt+4,2,(vn-4)/2))return false;
 for(unsigned i=0;i<counts[kind];i++){
  const sx_layout *l=sets[kind][i];unsigned z=l?(unsigned)l->fields[0].size:4;
  if(!sxq_a_field(w,t,i,z,&fields[i]))return false;
  if(fields[i]&&l&&!sxq_wadd(w,l,fields[i]))return false;
 }
 uint64_t target=0;
 if(kind==0){
  if(!sxq_a_ref(w,fields[1],&target)||!target||!sxq_a_parse(w,target,1,depth+1))return false;
  return sxq_a_vector(w,fields[2],24,&sxq_arrow_block,-1,depth)&&sxq_a_vector(w,fields[3],24,&sxq_arrow_block,-1,depth)&&sxq_a_vector(w,fields[4],4,NULL,-1,depth);
 }
 if(kind==1)return sxq_a_vector(w,fields[1],4,NULL,2,depth)&&sxq_a_vector(w,fields[2],4,NULL,-1,depth)&&sxq_a_vector(w,fields[3],8,NULL,-1,depth);
 if(kind==2){
  if(!sxq_a_ref(w,fields[0],&target)||!target)return false;uint32_t n=sxq32(w->b+target);
  if(!sxq_span(w,target+4,(uint64_t)n+1)||!sxq_wadd(w,&sxq_arrow_string_header,target)||!sxq_a_ref(w,fields[3],&target)||!target||!sxq_a_parse(w,target,3,depth+1))return false;
  return !fields[4]&&sxq_a_vector(w,fields[5],4,NULL,-1,depth)&&sxq_a_vector(w,fields[6],4,NULL,-1,depth);
 }
 if(kind==4){
  if(!fields[1]||!sxq_a_ref(w,fields[2],&target)||!target)return false;unsigned tag=w->b[fields[1]];if(tag!=1&&tag!=3)return false;
  return sxq_a_parse(w,target,tag==1?1:5,depth+1)&&sxq_a_vector(w,fields[4],4,NULL,-1,depth);
 }
 if(kind==5)return !fields[3]&&sxq_a_vector(w,fields[1],16,&sxq_arrow_field_node,-1,depth)&&sxq_a_vector(w,fields[2],16,&sxq_arrow_buffer,-1,depth)&&sxq_a_vector(w,fields[4],8,NULL,-1,depth);
 return true;
}
static bool sxq_a_message(sx_context *c,uint64_t p,uint64_t expected,uint64_t *after){
 uint8_t b[8];if(!sxq_file_span(c,p,8)||!sx_read(c,(int64_t)p,b,8))return false;
 unsigned prefix=sxq32(b)==UINT32_MAX?8:4;uint32_t n=sxq32(b+prefix-4);
 if(n<4||n>SXQ_META_LIMIT||(expected&&n+prefix!=expected)||!sxq_add(c,prefix==8?&sxq_arrow_continuation_prefix:&sxq_arrow_message_prefix,p))return false;
 sxq_window w;if(!sxq_window_open(&w,c,p+prefix,n))return false;uint64_t root=sxq32(w.b),field=0;bool ok=sxq_wadd(&w,&sxq_arrow_flatbuffer_root,0)&&sxq_a_parse(&w,root,4,0)&&sxq_a_field(&w,root,3,8,&field);
 uint64_t body=field?sxq64(w.b+field):0;if(ok)ok=body<=INT64_MAX&&sxq_file_span(c,p,n+prefix+body);
 if(ok)*after=p+n+prefix+body;xx_mem_free(w.b);return ok;
}
static bool sxq_arrow(sx_context *c){
 uint8_t tail[10];if(c->size<18||!sx_read(c,c->size-10,tail,10))return false;uint32_t n=sxq32(tail);
 if(n<4||n>SXQ_META_LIMIT||n>(uint64_t)c->size-18||!sxq_add(c,&sxq_arrow_file_header,0)||!sxq_add(c,&sxq_arrow_file_trailer,(uint64_t)c->size-10))return false;
 uint64_t footer=(uint64_t)c->size-10-n;sxq_window w;if(!sxq_window_open(&w,c,footer,n))return false;
 uint64_t root=sxq32(w.b),field=0,v=0,after=0;bool ok=sxq_wadd(&w,&sxq_arrow_flatbuffer_root,0)&&sxq_a_parse(&w,root,0,0)&&sxq_a_field(&w,root,3,4,&field)&&sxq_a_ref(&w,field,&v)&&v;
 uint32_t count=ok?sxq32(w.b+v):0;if(ok)ok=sxq_span(&w,v+4,(uint64_t)count*24)&&sxq_a_message(c,8,0,&after);
 for(uint32_t i=0;ok&&i<count;i++){
  const uint8_t *b=w.b+v+4+(size_t)i*24;uint64_t at=sxq64(b),body=sxq64(b+16);uint32_t meta=sxq32(b+8);
  ok=at==after&&meta<=SXQ_META_LIMIT&&sxq_a_message(c,at,meta,&after)&&after<=footer&&body==after-at-meta;
 }
 if(ok&&after!=footer){uint8_t eos[8];ok=footer-after==8&&sx_read(c,(int64_t)after,eos,8)&&sxq32(eos)==UINT32_MAX&&!sxq32(eos+4)&&sxq_add(c,&sxq_arrow_continuation_prefix,after);}
 xx_mem_free(w.b);return ok;
}
/* Compact Thrift records only their wire fields. Logical strings and arrays
 * use explicit length/count framing; payload bytes are left raw. */
static bool sxq_var(sxq_window *w,uint64_t *p,uint64_t *value,unsigned *width){
 uint64_t start=*p,u=0;for(unsigned i=0;i<10;i++){
  if(!sxq_span(w,*p,1))return false;uint8_t b=w->b[(*p)++];if(i==9&&(b&254))return false;u|=(uint64_t)(b&127)<<(7*i);
  if(!(b&128)){*value=u;*width=(unsigned)(*p-start);return true;}
 }return false;
}
static bool sxq_urow(sxq_window *w,uint64_t *p,bool count,uint64_t *out){
 uint64_t at=*p;unsigned width;if(!sxq_var(w,p,out,&width))return false;
 return sxq_wadd(w,count?sxq_columnar_varuint_count_rows[width-1]:sxq_columnar_varuint_size_rows[width-1],at);
}
static bool sxq_zrow(sxq_window *w,uint64_t *p,unsigned type,unsigned role,int64_t *out){
 uint64_t at=*p,u;unsigned width;if(!sxq_var(w,p,&u,&width))return false;int64_t v=(int64_t)(u>>1)^-(int64_t)(u&1);
 const sx_layout *const *rows;
 if(type==4){rows=role==1?sxq_thrift_i16_id_rows:sxq_thrift_i16_value_rows;}
 else if(type==5){rows=role==1?sxq_thrift_i32_id_rows:role==2?sxq_thrift_i32_size_rows:role==3?sxq_thrift_i32_count_rows:sxq_thrift_i32_value_rows;}
 else rows=role==2?sxq_thrift_i64_size_rows:role==3?sxq_thrift_i64_count_rows:role==4?sxq_thrift_i64_offset_rows:sxq_thrift_i64_value_rows;
 *out=v;return sxq_wadd(w,rows[width-1],at);
}
/* Contexts: 0 unknown, 1 FileMetaData, 2 SchemaElement, 3 RowGroup,
 * 4 ColumnChunk, 5 ColumnMetaData, 6 PageHeader, 7 DataPageHeader,
 * 8 DictionaryPageHeader, 9 DataPageHeaderV2. */
static unsigned sxq_child(unsigned kind,unsigned id){
 if(kind==1)return id==2?2:id==4?3:0;
 if(kind==3&&id==1)return 4;if(kind==4&&id==3)return 5;
 if(kind==6)return id==5?7:id==7?8:id==8?9:0;return 0;
}
static unsigned sxq_role(unsigned kind,unsigned id){
 if(kind==1)return id==1?1:id==3?3:0;
 if(kind==2)return id==1||id==3||id==6||id==9?1:id==2?2:id==5?3:0;
 if(kind==3)return id==2||id==6?2:id==3?3:id==5?4:id==7?1:0;
 if(kind==4)return id==2||id==4||id==6?4:id==5||id==7?2:0;
 if(kind==5)return id==1||id==2||id==4?1:id==5?3:id==6||id==7||id==15?2:id==9||id==10||id==11||id==14?4:0;
 if(kind==6)return id==1?1:id==2||id==3?2:0;
 if(kind==7)return id==1?3:id>=2&&id<=4?1:0;
 if(kind==8)return id==1?3:id==2?1:0;
 if(kind==9)return id>=1&&id<=3?3:id==4?1:id==5||id==6?2:0;return 0;
}
static bool sxq_t_struct(sxq_window *w,uint64_t *p,unsigned kind,unsigned depth,int64_t *packed);
static bool sxq_t_value(sxq_window *w,uint64_t *p,unsigned type,unsigned child,unsigned role,unsigned depth,bool in_collection,int64_t *number){
 if(depth>32||++w->work>2000000U)return false;
 if(type==1||type==2){if(!in_collection)return true;if(!sxq_span(w,*p,1)||(w->b[*p]!=1&&w->b[*p]!=2)||!sxq_wadd(w,&sxq_thrift_boolean_value,*p))return false;(*p)++;return true;}
 if(type==3){if(!sxq_wadd(w,&sxq_thrift_byte_value,*p))return false;(*p)++;return true;}
 if(type>=4&&type<=6)return sxq_zrow(w,p,type,role,number);
 if(type==7){if(!sxq_wadd(w,&sxq_thrift_double_bits,*p))return false;*p+=8;return true;}
 if(type==8){uint64_t n;if(!sxq_urow(w,p,false,&n)||!sxq_span(w,*p,n))return false;*p+=n;return true;}
 if(type==9||type==10){
  if(!sxq_span(w,*p,1)||!sxq_wadd(w,&sxq_thrift_list_header,*p))return false;uint8_t b=w->b[(*p)++];uint64_t n=b>>4;if(n==15&&!sxq_urow(w,p,true,&n))return false;
  if(n>65536)return false;for(uint64_t i=0;i<n;i++)if(!sxq_t_value(w,p,b&15,child,role,depth+1,true,number))return false;return true;
 }
 if(type==11){
  uint64_t n;if(!sxq_urow(w,p,true,&n)||n>65536)return false;if(!n)return true;
  if(!sxq_span(w,*p,1)||!sxq_wadd(w,&sxq_thrift_map_types,*p))return false;uint8_t b=w->b[(*p)++];
  for(uint64_t i=0;i<n;i++)if(!sxq_t_value(w,p,b>>4,0,0,depth+1,true,number)||!sxq_t_value(w,p,b&15,0,0,depth+1,true,number))return false;return true;
 }
 if(type==12)return sxq_t_struct(w,p,child,depth+1,NULL);return false;
}
static bool sxq_t_struct(sxq_window *w,uint64_t *p,unsigned kind,unsigned depth,int64_t *packed){
 unsigned last=0;if(depth>32)return false;for(unsigned i=0;i<SXQ_RECORD_LIMIT;i++){
  if(!sxq_span(w,*p,1)||!sxq_wadd(w,&sxq_thrift_field_header,*p))return false;uint8_t b=w->b[(*p)++];if(!b)return true;
  unsigned id=last+(b>>4);if(!(b>>4)){int64_t x;if(!sxq_zrow(w,p,4,1,&x)||x<=0||x>INT16_MAX)return false;id=(unsigned)x;}
  if(id>INT16_MAX)return false;last=id;int64_t number=0;
  if(!sxq_t_value(w,p,b&15,sxq_child(kind,id),sxq_role(kind,id),depth+1,false,&number))return false;
  if(kind==6&&id==3&&packed){if((b&15)!=5||number<0)return false;*packed=number;}
 }return false;
}
static bool sxq_p_pages(sx_context *c,uint64_t at,uint64_t size){
 uint64_t end=at+size;for(unsigned i=0;i<65536&&at<end;i++){
  uint64_t n=end-at;if(n>65536)n=65536;sxq_window w;if(!sxq_window_open(&w,c,at,n))return false;
  uint64_t used=0;int64_t packed=-1;bool ok=sxq_t_struct(&w,&used,6,0,&packed)&&packed>=0&&(uint64_t)packed<=end-at-used;
  xx_mem_free(w.b);if(!ok)return false;at+=used+(uint64_t)packed;
 }return at==end;
}
static bool sxq_parquet(sx_context *c){
 uint8_t b[8];if(c->size<12||!sx_read(c,c->size-8,b,8))return false;uint32_t n=sxq32(b);
 if(!n||n>8U*1024U*1024U||n>(uint64_t)c->size-12||!sxq_add(c,&sxq_parquet_file_header,0)||!sxq_add(c,&sxq_parquet_file_trailer,(uint64_t)c->size-8))return false;
 uint64_t footer=(uint64_t)c->size-8-n;sxq_window w;if(!sxq_window_open(&w,c,footer,n))return false;uint64_t p=0;
 bool ok=sxq_t_struct(&w,&p,1,0,NULL)&&p==n;xx_mem_free(w.b);if(!ok)return false;
 if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return false;
 xx_archive_record_state *state=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!state)return false;
 unsigned count=0;for(;count<65536;count++){
  const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,state);if(!r)break;
  if(r->data_offset<c->f->base_address||r->compressed_size<0){ok=false;break;}
  uint64_t at=(uint64_t)(r->data_offset-c->f->base_address),size=(uint64_t)r->compressed_size;
  if(at==footer&&size==n){}else if(at<4||at>footer||size>footer-at||!sxq_p_pages(c,at,size)){ok=false;break;}
  if(!(c->f->archive_record_move_to_next)(c->f,state,c->pd))break;
 }
 (c->f->free_archive_records_reading)(c->f,state);return ok&&count<65536;
}
static int sxq_order(const void *a,const void *b){
 const xx_data_struct *x=a,*y=b;if(x->offset!=y->offset)return x->offset<y->offset?-1:1;
 if(x->id!=y->id)return x->id<y->id?-1:1;if(x->total_size!=y->total_size)return x->total_size<y->total_size?-1:1;return 0;
}
static bool sxq_finish(sx_context *c){
 xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxq_order);size_t kept=0;
 for(size_t i=0;i<c->count;i++){
  if(kept&&c->items[kept-1].offset==c->items[i].offset&&c->items[kept-1].id==c->items[i].id&&c->items[kept-1].total_size==c->items[i].total_size&&c->items[kept-1].entry_size==c->items[i].entry_size&&c->items[kept-1].count==c->items[i].count){continue;}
  if(kept!=i){c->items[kept]=c->items[i];xx_mem_zero(&c->items[i],sizeof(c->items[i]));}kept++;
 }
 c->count=kept;int64_t end=0;for(size_t i=0;i<kept;i++){
  int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;
 }
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxq_order);return !c->failed;
}
static bool sx_columnar_supports(xx_file_type_t t){return t==XX_FILE_TYPE_APACHE_ARROW_FILE||t==XX_FILE_TYPE_APACHE_PARQUET;}
static bool sx_columnar_build(sx_context *c){
 if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 return (c->f->file_type==XX_FILE_TYPE_APACHE_ARROW_FILE?sxq_arrow(c):c->f->file_type==XX_FILE_TYPE_APACHE_PARQUET?sxq_parquet(c):false)&&sxq_finish(c);
}
static bool sx_columnar_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x601f0000U||id>=0x60200000U)return true;const wchar_t *t=NULL;
 if(xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;
 if(!xx_rt_wcscmp(r->name,L"version")&&(id==sxq_arrow_footer_version.id||id==sxq_arrow_message_version.id)){
  uint64_t v=xx_var_get_u64(&r->value);static const wchar_t *const names[]={L"MetadataVersion_V1",L"MetadataVersion_V2",L"MetadataVersion_V3",L"MetadataVersion_V4",L"MetadataVersion_V5"};if(v<SX_COUNT(names))t=names[v];
 }else if(!xx_rt_wcscmp(r->name,L"endianness")){uint64_t v=xx_var_get_u64(&r->value);t=v==0?L"Endianness_Little":v==1?L"Endianness_Big":L"Unknown Arrow endianness";}
 else if(!xx_rt_wcscmp(r->name,L"type_tag")){if(xx_var_get_u64(&r->value)==2)t=L"Type_Int";}
 else if(!xx_rt_wcscmp(r->name,L"header_tag")){uint64_t v=xx_var_get_u64(&r->value);t=v==1?L"MessageHeader_Schema":v==2?L"MessageHeader_DictionaryBatch":v==3?L"MessageHeader_RecordBatch":L"Unknown IPC message header tag";}
 else if(!xx_rt_wcscmp(r->name,L"nullable")||!xx_rt_wcscmp(r->name,L"is_signed")){uint64_t v=xx_var_get_u64(&r->value);t=v==0?L"false":v==1?L"true":L"Invalid Boolean";}
 if(t)return xx_data_struct_record_set_comment(r,t);

 if(!xx_rt_wcscmp(r->name,L"field_delta_and_type")||!xx_rt_wcscmp(r->name,L"count_and_element_type")||!xx_rt_wcscmp(r->name,L"key_and_value_type")){
  static const char *const names[]={"STOP","BOOLEAN_TRUE","BOOLEAN_FALSE","BYTE","I16","I32","I64","DOUBLE","BINARY","LIST","SET","MAP","STRUCT","UNKNOWN","UNKNOWN","UNKNOWN"};
  unsigned v=(unsigned)xx_var_get_u64(&r->value);char b[192];wchar_t out[192];int n;
  if(!xx_rt_wcscmp(r->name,L"field_delta_and_type"))n=xx_rt_snprintf(b,sizeof(b),"Compact Thrift %s; field-ID delta %u%s",names[v&15],v>>4,!v?"; end of structure":!(v>>4)?"; explicit ZigZag field ID follows":"");
  else if(!xx_rt_wcscmp(r->name,L"count_and_element_type"))n=xx_rt_snprintf(b,sizeof(b),"Compact Thrift %s elements; %s %u",names[v&15],(v>>4)==15?"ULEB count follows; marker":"inline count",v>>4);
  else n=xx_rt_snprintf(b,sizeof(b),"Compact Thrift map: %s keys, %s values",names[(v>>4)&15],names[v&15]);
  if(n<0||n>=(int)sizeof(b))return false;for(int i=0;i<=n;i++)out[i]=(unsigned char)b[i];return xx_data_struct_record_set_comment(r,out);
 }
 if(!xx_rt_wcscmp(r->name,L"vtable_displacement"))t=L"Signed displacement subtracted from the table offset to locate its vtable.";
 else if(!xx_rt_wcscmp(r->name,L"field_offset"))t=L"Byte offset from the FlatBuffers table start; zero means the field is absent.";
 else if(!xx_rt_wcscmp(r->name,L"root_offset")||!xx_rt_wcscmp(r->name,L"object_offset"))t=L"Unsigned forward byte offset from this physical word.";
 else if(!xx_rt_wcscmp(r->name,L"body_offset"))t=L"Byte offset relative to the IPC record-batch body.";
 else if(!xx_rt_wcscmp(r->name,L"bit_width"))t=L"Number of bits in each integer value; not bytes.";
 else if(!xx_rt_wcscmp(r->name,L"field_delta_and_type"))t=L"High nibble is the field-ID delta; low nibble is Compact Thrift type. Zero ends the structure.";
 else if(!xx_rt_wcscmp(r->name,L"count_and_element_type"))t=L"High nibble is the element count (15 means a following ULEB count); low nibble is the element type.";
 else if(!xx_rt_wcscmp(r->name,L"key_and_value_type"))t=L"High nibble is the map key type; low nibble is its value type.";
 else if(!xx_rt_wcscmp(r->name,L"boolean_type"))t=L"Compact Thrift collection Boolean: 1 true; 2 false.";
 else if(!xx_rt_wcscmp(r->name,L"ieee754_binary64_bits"))t=L"Little-endian IEEE 754 binary64 wire representation.";
 return !t||xx_data_struct_record_set_comment(r,t);
}
