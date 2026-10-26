/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bounded physical container, audio, font, capture and database schemas.
 * Specification links are retained by the corresponding native readers.
 */

static const xx_data_struct_field_desc sx_c_riff_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("form_type", "char[4]", 8, 4, SX_ID),
};
static const sx_layout sx_c_riff_header_le = { UINT32_C(0x60020001), "riff_header_le", sx_c_riff_header_fields, SX_COUNT(sx_c_riff_header_fields), SX_LE };
static const sx_layout sx_c_riff_header_be = { UINT32_C(0x60020002), "riff_header_be", sx_c_riff_header_fields, SX_COUNT(sx_c_riff_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_riff_chunk_header_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_ID),
    SX_FIELD("chunk_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_c_riff_chunk_header_le = { UINT32_C(0x60020003), "riff_chunk_header_le", sx_c_riff_chunk_header_fields, SX_COUNT(sx_c_riff_chunk_header_fields), SX_LE };
static const sx_layout sx_c_riff_chunk_header_be = { UINT32_C(0x60020004), "riff_chunk_header_be", sx_c_riff_chunk_header_fields, SX_COUNT(sx_c_riff_chunk_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_riff_list_header_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_ID),
    SX_FIELD("chunk_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("list_type", "char[4]", 8, 4, SX_ID),
};
static const sx_layout sx_c_riff_list_header_le = { UINT32_C(0x60020005), "riff_list_header_le", sx_c_riff_list_header_fields, SX_COUNT(sx_c_riff_list_header_fields), SX_LE };
static const sx_layout sx_c_riff_list_header_be = { UINT32_C(0x60020006), "riff_list_header_be", sx_c_riff_list_header_fields, SX_COUNT(sx_c_riff_list_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_wave_format_fields[] = {
    SX_FIELD("format_tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("channels", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("samples_per_second", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("average_bytes_per_second", "uint32", 8, 4, SX_NONE),
    SX_FIELD("block_alignment", "uint16", 12, 2, SX_SIZE),
    SX_FIELD("bits_per_sample", "uint16", 14, 2, SX_COUNT_PROP),
};
static const sx_layout sx_c_wave_format_le = { UINT32_C(0x60020007), "wave_format_le", sx_c_wave_format_fields, SX_COUNT(sx_c_wave_format_fields), SX_LE };
static const sx_layout sx_c_wave_format_be = { UINT32_C(0x60020008), "wave_format_be", sx_c_wave_format_fields, SX_COUNT(sx_c_wave_format_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_wave_format_extension_size_fields[] = {
    SX_FIELD("extension_size", "uint16", 0, 2, SX_SIZE),
};
static const sx_layout sx_c_wave_format_extension_size_le = { UINT32_C(0x60020009), "wave_format_extension_size_le", sx_c_wave_format_extension_size_fields, SX_COUNT(sx_c_wave_format_extension_size_fields), SX_LE };
static const sx_layout sx_c_wave_format_extension_size_be = { UINT32_C(0x6002000A), "wave_format_extension_size_be", sx_c_wave_format_extension_size_fields, SX_COUNT(sx_c_wave_format_extension_size_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_wave_format_extensible_fields[] = {
    SX_FIELD("valid_bits_per_sample", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("channel_mask", "uint32", 2, 4, SX_FLAGS),
    SX_FIELD("subformat", "bytes", 6, 16, SX_ID),
};
static const sx_layout sx_c_wave_format_extensible_le = { UINT32_C(0x6002000B), "wave_format_extensible_le", sx_c_wave_format_extensible_fields, SX_COUNT(sx_c_wave_format_extensible_fields), SX_LE };
static const sx_layout sx_c_wave_format_extensible_be = { UINT32_C(0x6002000C), "wave_format_extensible_be", sx_c_wave_format_extensible_fields, SX_COUNT(sx_c_wave_format_extensible_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_wave_fact_fields[] = {
    SX_FIELD("sample_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sx_c_wave_fact_le = { UINT32_C(0x6002000D), "wave_fact_le", sx_c_wave_fact_fields, SX_COUNT(sx_c_wave_fact_fields), SX_LE };
static const sx_layout sx_c_wave_fact_be = { UINT32_C(0x6002000E), "wave_fact_be", sx_c_wave_fact_fields, SX_COUNT(sx_c_wave_fact_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_avi_main_header_fields[] = {
    SX_FIELD("microseconds_per_frame", "uint32", 0, 4, SX_NONE),
    SX_FIELD("max_bytes_per_second", "uint32", 4, 4, SX_NONE),
    SX_FIELD("padding_granularity", "uint32", 8, 4, SX_NONE),
    SX_FIELD("flags", "uint32", 12, 4, SX_FLAGS),
    SX_FIELD("total_frames", "uint32", 16, 4, SX_NONE),
    SX_FIELD("initial_frames", "uint32", 20, 4, SX_NONE),
    SX_FIELD("streams", "uint32", 24, 4, SX_NONE),
    SX_FIELD("suggested_buffer_size", "uint32", 28, 4, SX_NONE),
    SX_FIELD("width", "uint32", 32, 4, SX_NONE),
    SX_FIELD("height", "uint32", 36, 4, SX_NONE),
    SX_FIELD("reserved", "bytes", 40, 16, SX_RESERVED),
};
static const sx_layout sx_c_avi_main_header = { UINT32_C(0x6002000F), "avi_main_header", sx_c_avi_main_header_fields, SX_COUNT(sx_c_avi_main_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_avi_stream_header_fields[] = {
    SX_FIELD("type", "char[4]", 0, 4, SX_ID),
    SX_FIELD("handler", "char[4]", 4, 4, SX_ID),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("priority", "uint16", 12, 2, SX_NONE),
    SX_FIELD("language", "uint16", 14, 2, SX_ID),
    SX_FIELD("initial_frames", "uint32", 16, 4, SX_NONE),
    SX_FIELD("scale", "uint32", 20, 4, SX_NONE),
    SX_FIELD("rate", "uint32", 24, 4, SX_NONE),
    SX_FIELD("start", "uint32", 28, 4, SX_NONE),
    SX_FIELD("length", "uint32", 32, 4, SX_NONE),
    SX_FIELD("suggested_buffer_size", "uint32", 36, 4, SX_NONE),
    SX_FIELD("quality", "uint32", 40, 4, SX_NONE),
    SX_FIELD("sample_size", "uint32", 44, 4, SX_NONE),
    SX_FIELD("frame_left", "int16", 48, 2, SX_NONE),
    SX_FIELD("frame_top", "int16", 50, 2, SX_NONE),
    SX_FIELD("frame_right", "int16", 52, 2, SX_NONE),
    SX_FIELD("frame_bottom", "int16", 54, 2, SX_NONE),
};
static const sx_layout sx_c_avi_stream_header = { UINT32_C(0x60020010), "avi_stream_header", sx_c_avi_stream_header_fields, SX_COUNT(sx_c_avi_stream_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_avi_index_entry_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_ID),
    SX_FIELD("flags", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("chunk_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("chunk_length", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_c_avi_index_entry = { UINT32_C(0x60020011), "avi_index_entry", sx_c_avi_index_entry_fields, SX_COUNT(sx_c_avi_index_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_avi_bitmap_info_header_fields[] = {
    SX_FIELD("size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("width", "int32", 4, 4, SX_NONE),
    SX_FIELD("height", "int32", 8, 4, SX_NONE),
    SX_FIELD("planes", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("bit_count", "uint16", 14, 2, SX_COUNT_PROP),
    SX_FIELD("compression", "uint32", 16, 4, SX_ID),
    SX_FIELD("image_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("x_pixels_per_meter", "int32", 24, 4, SX_NONE),
    SX_FIELD("y_pixels_per_meter", "int32", 28, 4, SX_NONE),
    SX_FIELD("colors_used", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("colors_important", "uint32", 36, 4, SX_COUNT_PROP),
};
static const sx_layout sx_c_avi_bitmap_info_header = { UINT32_C(0x60020012), "avi_bitmap_info_header", sx_c_avi_bitmap_info_header_fields, SX_COUNT(sx_c_avi_bitmap_info_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_webp_extended_header_fields[] = {
    SX_FIELD("flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("reserved", "bytes", 1, 3, SX_RESERVED),
    SX_FIELD("canvas_width_minus_one", "uint24", 4, 3, SX_NONE),
    SX_FIELD("canvas_height_minus_one", "uint24", 7, 3, SX_NONE),
};
static const sx_layout sx_c_webp_extended_header = { UINT32_C(0x60020013), "webp_extended_header", sx_c_webp_extended_header_fields, SX_COUNT(sx_c_webp_extended_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_webp_animation_header_fields[] = {
    SX_FIELD("background_color", "uint32", 0, 4, SX_ID),
    SX_FIELD("loop_count", "uint16", 4, 2, SX_COUNT_PROP),
};
static const sx_layout sx_c_webp_animation_header = { UINT32_C(0x60020014), "webp_animation_header", sx_c_webp_animation_header_fields, SX_COUNT(sx_c_webp_animation_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_webp_animation_frame_header_fields[] = {
    SX_FIELD("frame_x_div2", "uint24", 0, 3, SX_NONE),
    SX_FIELD("frame_y_div2", "uint24", 3, 3, SX_NONE),
    SX_FIELD("frame_width_minus_one", "uint24", 6, 3, SX_NONE),
    SX_FIELD("frame_height_minus_one", "uint24", 9, 3, SX_NONE),
    SX_FIELD("duration_ms", "uint24", 12, 3, SX_NONE),
    SX_FIELD("flags", "uint8", 15, 1, SX_FLAGS),
};
static const sx_layout sx_c_webp_animation_frame_header = { UINT32_C(0x60020015), "webp_animation_frame_header", sx_c_webp_animation_frame_header_fields, SX_COUNT(sx_c_webp_animation_frame_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_sf2_preset_header_fields[] = {
    SX_FIELD("preset_name", "char[20]", 0, 20, SX_STRING),
    SX_FIELD("preset", "uint16", 20, 2, SX_ID),
    SX_FIELD("bank", "uint16", 22, 2, SX_ID),
    SX_FIELD("preset_bag_index", "uint16", 24, 2, SX_NONE),
    SX_FIELD("library", "uint32", 26, 4, SX_NONE),
    SX_FIELD("genre", "uint32", 30, 4, SX_NONE),
    SX_FIELD("morphology", "uint32", 34, 4, SX_NONE),
};
static const sx_layout sx_c_sf2_preset_header = { UINT32_C(0x60020016), "sf2_preset_header", sx_c_sf2_preset_header_fields, SX_COUNT(sx_c_sf2_preset_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_sf2_bag_fields[] = {
    SX_FIELD("generator_index", "uint16", 0, 2, SX_NONE),
    SX_FIELD("modulator_index", "uint16", 2, 2, SX_NONE),
};
static const sx_layout sx_c_sf2_bag = { UINT32_C(0x60020017), "sf2_bag", sx_c_sf2_bag_fields, SX_COUNT(sx_c_sf2_bag_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_sf2_modulator_fields[] = {
    SX_FIELD("source_operator", "uint16", 0, 2, SX_FLAGS),
    SX_FIELD("destination_operator", "uint16", 2, 2, SX_ID),
    SX_FIELD("amount", "int16", 4, 2, SX_NONE),
    SX_FIELD("amount_source_operator", "uint16", 6, 2, SX_FLAGS),
    SX_FIELD("transform_operator", "uint16", 8, 2, SX_ID),
};
static const sx_layout sx_c_sf2_modulator = { UINT32_C(0x60020018), "sf2_modulator", sx_c_sf2_modulator_fields, SX_COUNT(sx_c_sf2_modulator_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_sf2_generator_fields[] = {
    SX_FIELD("operator", "uint16", 0, 2, SX_ID),
    SX_FIELD("amount", "uint16", 2, 2, SX_NONE),
};
static const sx_layout sx_c_sf2_generator = { UINT32_C(0x60020019), "sf2_generator", sx_c_sf2_generator_fields, SX_COUNT(sx_c_sf2_generator_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_sf2_instrument_fields[] = {
    SX_FIELD("instrument_name", "char[20]", 0, 20, SX_STRING),
    SX_FIELD("instrument_bag_index", "uint16", 20, 2, SX_NONE),
};
static const sx_layout sx_c_sf2_instrument = { UINT32_C(0x6002001A), "sf2_instrument", sx_c_sf2_instrument_fields, SX_COUNT(sx_c_sf2_instrument_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_sf2_sample_header_fields[] = {
    SX_FIELD("sample_name", "char[20]", 0, 20, SX_STRING),
    SX_FIELD("start", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("end", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("start_loop", "uint32", 28, 4, SX_OFFSET),
    SX_FIELD("end_loop", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("sample_rate", "uint32", 36, 4, SX_NONE),
    SX_FIELD("original_pitch", "uint8", 40, 1, SX_NONE),
    SX_FIELD("pitch_correction", "int8", 41, 1, SX_NONE),
    SX_FIELD("sample_link", "uint16", 42, 2, SX_NONE),
    SX_FIELD("sample_type", "uint16", 44, 2, SX_FLAGS),
};
static const sx_layout sx_c_sf2_sample_header = { UINT32_C(0x6002001B), "sf2_sample_header", sx_c_sf2_sample_header_fields, SX_COUNT(sx_c_sf2_sample_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_ogg_page_header_fields[] = {
    SX_FIELD("capture_pattern", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 4, 1, SX_NONE),
    SX_FIELD("header_type", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("granule_position", "int64", 6, 8, SX_NONE),
    SX_FIELD("bitstream_serial_number", "uint32", 14, 4, SX_ID),
    SX_FIELD("page_sequence_number", "uint32", 18, 4, SX_COUNT_PROP),
    SX_FIELD("checksum", "uint32", 22, 4, SX_CHECKSUM),
    SX_FIELD("page_segments", "uint8", 26, 1, SX_COUNT_PROP),
};
static const sx_layout sx_c_ogg_page_header = { UINT32_C(0x6002001C), "ogg_page_header", sx_c_ogg_page_header_fields, SX_COUNT(sx_c_ogg_page_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_ogg_lacing_value_fields[] = {
    SX_FIELD("segment_size", "uint8", 0, 1, SX_SIZE),
};
static const sx_layout sx_c_ogg_lacing_value = { UINT32_C(0x6002001D), "ogg_lacing_value", sx_c_ogg_lacing_value_fields, SX_COUNT(sx_c_ogg_lacing_value_fields), SX_LE };

static const xx_data_struct_field_desc sx_c_pcap_file_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("major_version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("reserved1", "int32", 8, 4, SX_RESERVED),
    SX_FIELD("reserved2", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("snapshot_length", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("linktype_and_information", "uint32", 20, 4, SX_FLAGS),
};
static const sx_layout sx_c_pcap_file_header_le = { UINT32_C(0x6002001E), "pcap_file_header_le", sx_c_pcap_file_header_fields, SX_COUNT(sx_c_pcap_file_header_fields), SX_LE };
static const sx_layout sx_c_pcap_file_header_be = { UINT32_C(0x6002001F), "pcap_file_header_be", sx_c_pcap_file_header_fields, SX_COUNT(sx_c_pcap_file_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_pcap_packet_header_fields[] = {
    SX_FIELD("timestamp_seconds", "uint32", 0, 4, SX_TIME),
    SX_FIELD("timestamp_fraction", "uint32", 4, 4, SX_NONE),
    SX_FIELD("captured_length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("original_length", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_c_pcap_packet_header_le = { UINT32_C(0x60020020), "pcap_packet_header_le", sx_c_pcap_packet_header_fields, SX_COUNT(sx_c_pcap_packet_header_fields), SX_LE };
static const sx_layout sx_c_pcap_packet_header_be = { UINT32_C(0x60020021), "pcap_packet_header_be", sx_c_pcap_packet_header_fields, SX_COUNT(sx_c_pcap_packet_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_sqlite3_database_header_fields[] = {
    SX_FIELD("magic", "char[16]", 0, 16, SX_SIGNATURE),
    SX_FIELD("page_size", "uint16", 16, 2, SX_SIZE),
    SX_FIELD("write_version", "uint8", 18, 1, SX_ID),
    SX_FIELD("read_version", "uint8", 19, 1, SX_ID),
    SX_FIELD("reserved_bytes_per_page", "uint8", 20, 1, SX_SIZE),
    SX_FIELD("maximum_payload_fraction", "uint8", 21, 1, SX_NONE),
    SX_FIELD("minimum_payload_fraction", "uint8", 22, 1, SX_NONE),
    SX_FIELD("leaf_payload_fraction", "uint8", 23, 1, SX_NONE),
    SX_FIELD("file_change_counter", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("database_size_pages", "uint32", 28, 4, SX_COUNT_PROP),
    SX_FIELD("first_freelist_trunk_page", "uint32", 32, 4, SX_NONE),
    SX_FIELD("freelist_page_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("schema_cookie", "uint32", 40, 4, SX_NONE),
    SX_FIELD("schema_format", "uint32", 44, 4, SX_ID),
    SX_FIELD("default_page_cache_size", "int32", 48, 4, SX_COUNT_PROP),
    SX_FIELD("largest_root_btree_page", "uint32", 52, 4, SX_NONE),
    SX_FIELD("text_encoding", "uint32", 56, 4, SX_ID),
    SX_FIELD("user_version", "uint32", 60, 4, SX_NONE),
    SX_FIELD("incremental_vacuum", "uint32", 64, 4, SX_FLAGS),
    SX_FIELD("application_id", "uint32", 68, 4, SX_ID),
    SX_FIELD("reserved", "bytes", 72, 20, SX_RESERVED),
    SX_FIELD("version_valid_for", "uint32", 92, 4, SX_NONE),
    SX_FIELD("sqlite_version", "uint32", 96, 4, SX_NONE),
};
static const sx_layout sx_c_sqlite3_database_header = { UINT32_C(0x60020022), "sqlite3_database_header", sx_c_sqlite3_database_header_fields, SX_COUNT(sx_c_sqlite3_database_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_sqlite_btree_leaf_page_header_fields[] = {
    SX_FIELD("page_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("first_freeblock_offset", "uint16", 1, 2, SX_OFFSET),
    SX_FIELD("cell_count", "uint16", 3, 2, SX_COUNT_PROP),
    SX_FIELD("cell_content_offset", "uint16", 5, 2, SX_OFFSET),
    SX_FIELD("fragmented_free_bytes", "uint8", 7, 1, SX_SIZE),
};
static const sx_layout sx_c_sqlite_btree_leaf_page_header = { UINT32_C(0x60020023), "sqlite_btree_leaf_page_header", sx_c_sqlite_btree_leaf_page_header_fields, SX_COUNT(sx_c_sqlite_btree_leaf_page_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_sqlite_btree_interior_page_header_fields[] = {
    SX_FIELD("page_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("first_freeblock_offset", "uint16", 1, 2, SX_OFFSET),
    SX_FIELD("cell_count", "uint16", 3, 2, SX_COUNT_PROP),
    SX_FIELD("cell_content_offset", "uint16", 5, 2, SX_OFFSET),
    SX_FIELD("fragmented_free_bytes", "uint8", 7, 1, SX_SIZE),
    SX_FIELD("rightmost_child_page", "uint32", 8, 4, SX_NONE),
};
static const sx_layout sx_c_sqlite_btree_interior_page_header = { UINT32_C(0x60020024), "sqlite_btree_interior_page_header", sx_c_sqlite_btree_interior_page_header_fields, SX_COUNT(sx_c_sqlite_btree_interior_page_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_sqlite_cell_pointer_fields[] = {
    SX_FIELD("cell_offset", "uint16", 0, 2, SX_OFFSET),
};
static const sx_layout sx_c_sqlite_cell_pointer = { UINT32_C(0x60020025), "sqlite_cell_pointer", sx_c_sqlite_cell_pointer_fields, SX_COUNT(sx_c_sqlite_cell_pointer_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_sqlite_wal_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("page_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("checkpoint_sequence", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("salt1", "uint32", 16, 4, SX_ID),
    SX_FIELD("salt2", "uint32", 20, 4, SX_ID),
    SX_FIELD("checksum1", "uint32", 24, 4, SX_CHECKSUM),
    SX_FIELD("checksum2", "uint32", 28, 4, SX_CHECKSUM),
};
static const sx_layout sx_c_sqlite_wal_header = { UINT32_C(0x60020026), "sqlite_wal_header", sx_c_sqlite_wal_header_fields, SX_COUNT(sx_c_sqlite_wal_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_sqlite_wal_frame_header_fields[] = {
    SX_FIELD("page_number", "uint32", 0, 4, SX_NONE),
    SX_FIELD("database_size_pages", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("salt1", "uint32", 8, 4, SX_ID),
    SX_FIELD("salt2", "uint32", 12, 4, SX_ID),
    SX_FIELD("checksum1", "uint32", 16, 4, SX_CHECKSUM),
    SX_FIELD("checksum2", "uint32", 20, 4, SX_CHECKSUM),
};
static const sx_layout sx_c_sqlite_wal_frame_header = { UINT32_C(0x60020027), "sqlite_wal_frame_header", sx_c_sqlite_wal_frame_header_fields, SX_COUNT(sx_c_sqlite_wal_frame_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_sfnt_offset_table_fields[] = {
    SX_FIELD("sfnt_version", "uint32", 0, 4, SX_ID),
    SX_FIELD("number_of_tables", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("search_range", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("entry_selector", "uint16", 8, 2, SX_NONE),
    SX_FIELD("range_shift", "uint16", 10, 2, SX_SIZE),
};
static const sx_layout sx_c_sfnt_offset_table = { UINT32_C(0x60020028), "sfnt_offset_table", sx_c_sfnt_offset_table_fields, SX_COUNT(sx_c_sfnt_offset_table_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_sfnt_table_record_fields[] = {
    SX_FIELD("tag", "char[4]", 0, 4, SX_ID),
    SX_FIELD("checksum", "uint32", 4, 4, SX_CHECKSUM),
    SX_FIELD("offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("length", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_c_sfnt_table_record = { UINT32_C(0x60020029), "sfnt_table_record", sx_c_sfnt_table_record_fields, SX_COUNT(sx_c_sfnt_table_record_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("flavor", "uint32", 4, 4, SX_ID),
    SX_FIELD("length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("number_of_tables", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint16", 14, 2, SX_RESERVED),
    SX_FIELD("total_sfnt_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("major_version", "uint16", 20, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 22, 2, SX_NONE),
    SX_FIELD("metadata_offset", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("metadata_length", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("metadata_original_length", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("private_offset", "uint32", 36, 4, SX_OFFSET),
    SX_FIELD("private_length", "uint32", 40, 4, SX_SIZE),
};
static const sx_layout sx_c_woff_header = { UINT32_C(0x6002002A), "woff_header", sx_c_woff_header_fields, SX_COUNT(sx_c_woff_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff_table_record_fields[] = {
    SX_FIELD("tag", "char[4]", 0, 4, SX_ID),
    SX_FIELD("offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("compressed_length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("original_length", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("original_checksum", "uint32", 16, 4, SX_CHECKSUM),
};
static const sx_layout sx_c_woff_table_record = { UINT32_C(0x6002002B), "woff_table_record", sx_c_woff_table_record_fields, SX_COUNT(sx_c_woff_table_record_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff2_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("flavor", "uint32", 4, 4, SX_ID),
    SX_FIELD("length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("number_of_tables", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint16", 14, 2, SX_RESERVED),
    SX_FIELD("total_sfnt_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("total_compressed_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("major_version", "uint16", 24, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 26, 2, SX_NONE),
    SX_FIELD("metadata_offset", "uint32", 28, 4, SX_OFFSET),
    SX_FIELD("metadata_length", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("metadata_original_length", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("private_offset", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("private_length", "uint32", 44, 4, SX_SIZE),
};
static const sx_layout sx_c_woff2_header = { UINT32_C(0x6002002C), "woff2_header", sx_c_woff2_header_fields, SX_COUNT(sx_c_woff2_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff2_table_flags_fields[] = {
    SX_FIELD("flags", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sx_c_woff2_table_flags = { UINT32_C(0x6002002D), "woff2_table_flags", sx_c_woff2_table_flags_fields, SX_COUNT(sx_c_woff2_table_flags_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff2_table_tag_fields[] = {
    SX_FIELD("tag", "char[4]", 0, 4, SX_ID),
};
static const sx_layout sx_c_woff2_table_tag = { UINT32_C(0x6002002E), "woff2_table_tag", sx_c_woff2_table_tag_fields, SX_COUNT(sx_c_woff2_table_tag_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff2_base128_1_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 1, SX_SIZE),
};
static const sx_layout sx_c_woff2_base128_1 = { UINT32_C(0x6002002F), "woff2_uintbase128_1", sx_c_woff2_base128_1_fields, SX_COUNT(sx_c_woff2_base128_1_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff2_base128_2_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 2, SX_SIZE),
};
static const sx_layout sx_c_woff2_base128_2 = { UINT32_C(0x60020030), "woff2_uintbase128_2", sx_c_woff2_base128_2_fields, SX_COUNT(sx_c_woff2_base128_2_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff2_base128_3_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 3, SX_SIZE),
};
static const sx_layout sx_c_woff2_base128_3 = { UINT32_C(0x60020031), "woff2_uintbase128_3", sx_c_woff2_base128_3_fields, SX_COUNT(sx_c_woff2_base128_3_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff2_base128_4_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 4, SX_SIZE),
};
static const sx_layout sx_c_woff2_base128_4 = { UINT32_C(0x60020032), "woff2_uintbase128_4", sx_c_woff2_base128_4_fields, SX_COUNT(sx_c_woff2_base128_4_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_woff2_base128_5_fields[] = {
    SX_FIELD("length", "uintbase128", 0, 5, SX_SIZE),
};
static const sx_layout sx_c_woff2_base128_5 = { UINT32_C(0x60020033), "woff2_uintbase128_5", sx_c_woff2_base128_5_fields, SX_COUNT(sx_c_woff2_base128_5_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_font_head_table_fields[] = {
    SX_FIELD("major_version", "uint16", 0, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 2, 2, SX_NONE),
    SX_FIELD("font_revision", "uint32", 4, 4, SX_NONE),
    SX_FIELD("checksum_adjustment", "uint32", 8, 4, SX_CHECKSUM),
    SX_FIELD("magic_number", "uint32", 12, 4, SX_SIGNATURE),
    SX_FIELD("flags", "uint16", 16, 2, SX_FLAGS),
    SX_FIELD("units_per_em", "uint16", 18, 2, SX_NONE),
    SX_FIELD("created", "int64", 20, 8, SX_TIME),
    SX_FIELD("modified", "int64", 28, 8, SX_TIME),
    SX_FIELD("x_min", "int16", 36, 2, SX_NONE),
    SX_FIELD("y_min", "int16", 38, 2, SX_NONE),
    SX_FIELD("x_max", "int16", 40, 2, SX_NONE),
    SX_FIELD("y_max", "int16", 42, 2, SX_NONE),
    SX_FIELD("mac_style", "uint16", 44, 2, SX_FLAGS),
    SX_FIELD("lowest_recommended_ppem", "uint16", 46, 2, SX_NONE),
    SX_FIELD("font_direction_hint", "int16", 48, 2, SX_NONE),
    SX_FIELD("index_to_loc_format", "int16", 50, 2, SX_ID),
    SX_FIELD("glyph_data_format", "int16", 52, 2, SX_ID),
};
static const sx_layout sx_c_font_head_table = { UINT32_C(0x60020034), "font_head_table", sx_c_font_head_table_fields, SX_COUNT(sx_c_font_head_table_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_font_horizontal_header_fields[] = {
    SX_FIELD("major_version", "uint16", 0, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 2, 2, SX_NONE),
    SX_FIELD("ascender", "int16", 4, 2, SX_NONE),
    SX_FIELD("descender", "int16", 6, 2, SX_NONE),
    SX_FIELD("line_gap", "int16", 8, 2, SX_NONE),
    SX_FIELD("advance_width_max", "uint16", 10, 2, SX_NONE),
    SX_FIELD("minimum_left_side_bearing", "int16", 12, 2, SX_NONE),
    SX_FIELD("minimum_right_side_bearing", "int16", 14, 2, SX_NONE),
    SX_FIELD("x_max_extent", "int16", 16, 2, SX_NONE),
    SX_FIELD("caret_slope_rise", "int16", 18, 2, SX_NONE),
    SX_FIELD("caret_slope_run", "int16", 20, 2, SX_NONE),
    SX_FIELD("caret_offset", "int16", 22, 2, SX_NONE),
    SX_FIELD("reserved", "bytes", 24, 8, SX_RESERVED),
    SX_FIELD("metric_data_format", "int16", 32, 2, SX_ID),
    SX_FIELD("number_of_h_metrics", "uint16", 34, 2, SX_COUNT_PROP),
};
static const sx_layout sx_c_font_horizontal_header = { UINT32_C(0x60020035), "font_horizontal_header", sx_c_font_horizontal_header_fields, SX_COUNT(sx_c_font_horizontal_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_font_maxp_header_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_ID),
    SX_FIELD("number_of_glyphs", "uint16", 4, 2, SX_COUNT_PROP),
};
static const sx_layout sx_c_font_maxp_header = { UINT32_C(0x60020036), "font_maxp_header", sx_c_font_maxp_header_fields, SX_COUNT(sx_c_font_maxp_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_font_maxp_v1_limits_fields[] = {
    SX_FIELD("max_points", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("max_contours", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("max_composite_points", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("max_composite_contours", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("max_zones", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("max_twilight_points", "uint16", 10, 2, SX_COUNT_PROP),
    SX_FIELD("max_storage", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("max_function_defs", "uint16", 14, 2, SX_COUNT_PROP),
    SX_FIELD("max_instruction_defs", "uint16", 16, 2, SX_COUNT_PROP),
    SX_FIELD("max_stack_elements", "uint16", 18, 2, SX_COUNT_PROP),
    SX_FIELD("max_size_of_instructions", "uint16", 20, 2, SX_COUNT_PROP),
    SX_FIELD("max_component_elements", "uint16", 22, 2, SX_COUNT_PROP),
    SX_FIELD("max_component_depth", "uint16", 24, 2, SX_COUNT_PROP),
};
static const sx_layout sx_c_font_maxp_v1_limits = { UINT32_C(0x60020037), "font_maxp_v1_limits", sx_c_font_maxp_v1_limits_fields, SX_COUNT(sx_c_font_maxp_v1_limits_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_font_name_header_fields[] = {
    SX_FIELD("format", "uint16", 0, 2, SX_ID),
    SX_FIELD("count", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("string_offset", "uint16", 4, 2, SX_OFFSET),
};
static const sx_layout sx_c_font_name_header = { UINT32_C(0x60020038), "font_name_header", sx_c_font_name_header_fields, SX_COUNT(sx_c_font_name_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_font_name_record_fields[] = {
    SX_FIELD("platform_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("encoding_id", "uint16", 2, 2, SX_ID),
    SX_FIELD("language_id", "uint16", 4, 2, SX_ID),
    SX_FIELD("name_id", "uint16", 6, 2, SX_ID),
    SX_FIELD("length", "uint16", 8, 2, SX_SIZE),
    SX_FIELD("offset", "uint16", 10, 2, SX_OFFSET),
};
static const sx_layout sx_c_font_name_record = { UINT32_C(0x60020039), "font_name_record", sx_c_font_name_record_fields, SX_COUNT(sx_c_font_name_record_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_font_cmap_header_fields[] = {
    SX_FIELD("version", "uint16", 0, 2, SX_NONE),
    SX_FIELD("number_of_tables", "uint16", 2, 2, SX_COUNT_PROP),
};
static const sx_layout sx_c_font_cmap_header = { UINT32_C(0x6002003A), "font_cmap_header", sx_c_font_cmap_header_fields, SX_COUNT(sx_c_font_cmap_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_font_cmap_encoding_record_fields[] = {
    SX_FIELD("platform_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("encoding_id", "uint16", 2, 2, SX_ID),
    SX_FIELD("offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sx_c_font_cmap_encoding_record = { UINT32_C(0x6002003B), "font_cmap_encoding_record", sx_c_font_cmap_encoding_record_fields, SX_COUNT(sx_c_font_cmap_encoding_record_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_flac_marker_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
};
static const sx_layout sx_c_flac_marker = { UINT32_C(0x6002003C), "flac_marker", sx_c_flac_marker_fields, SX_COUNT(sx_c_flac_marker_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_flac_metadata_block_header_fields[] = {
    SX_FIELD("last_block_and_type", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("length", "uint24", 1, 3, SX_SIZE),
};
static const sx_layout sx_c_flac_metadata_block_header = { UINT32_C(0x6002003D), "flac_metadata_block_header", sx_c_flac_metadata_block_header_fields, SX_COUNT(sx_c_flac_metadata_block_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_flac_streaminfo_fields[] = {
    SX_FIELD("minimum_block_size", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("maximum_block_size", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("minimum_frame_size", "uint24", 4, 3, SX_SIZE),
    SX_FIELD("maximum_frame_size", "uint24", 7, 3, SX_SIZE),
    SX_FIELD("sample_rate_channels_bits_total_samples", "uint64", 10, 8, SX_FLAGS),
    SX_FIELD("md5_signature", "bytes", 18, 16, SX_CHECKSUM),
};
static const sx_layout sx_c_flac_streaminfo = { UINT32_C(0x6002003E), "flac_streaminfo", sx_c_flac_streaminfo_fields, SX_COUNT(sx_c_flac_streaminfo_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_flac_application_header_fields[] = {
    SX_FIELD("application_id", "char[4]", 0, 4, SX_ID),
};
static const sx_layout sx_c_flac_application_header = { UINT32_C(0x6002003F), "flac_application_header", sx_c_flac_application_header_fields, SX_COUNT(sx_c_flac_application_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_flac_seekpoint_fields[] = {
    SX_FIELD("sample_number", "uint64", 0, 8, SX_NONE),
    SX_FIELD("stream_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("frame_samples", "uint16", 16, 2, SX_COUNT_PROP),
};
static const sx_layout sx_c_flac_seekpoint = { UINT32_C(0x60020040), "flac_seekpoint", sx_c_flac_seekpoint_fields, SX_COUNT(sx_c_flac_seekpoint_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_aiff_form_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("form_type", "char[4]", 8, 4, SX_ID),
};
static const sx_layout sx_c_aiff_form_header = { UINT32_C(0x60020041), "aiff_form_header", sx_c_aiff_form_header_fields, SX_COUNT(sx_c_aiff_form_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_aiff_chunk_header_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_ID),
    SX_FIELD("chunk_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_c_aiff_chunk_header = { UINT32_C(0x60020042), "aiff_chunk_header", sx_c_aiff_chunk_header_fields, SX_COUNT(sx_c_aiff_chunk_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_aiff_common_chunk_fields[] = {
    SX_FIELD("channels", "int16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("sample_frames", "uint32", 2, 4, SX_COUNT_PROP),
    SX_FIELD("sample_size_bits", "int16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("sample_rate_extended80", "bytes", 8, 10, SX_NONE),
};
static const sx_layout sx_c_aiff_common_chunk = { UINT32_C(0x60020043), "aiff_common_chunk", sx_c_aiff_common_chunk_fields, SX_COUNT(sx_c_aiff_common_chunk_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_aifc_compression_type_fields[] = {
    SX_FIELD("compression_type", "char[4]", 0, 4, SX_ID),
};
static const sx_layout sx_c_aifc_compression_type = { UINT32_C(0x60020044), "aifc_compression_type", sx_c_aifc_compression_type_fields, SX_COUNT(sx_c_aifc_compression_type_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_aiff_sound_data_header_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("block_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_c_aiff_sound_data_header = { UINT32_C(0x60020045), "aiff_sound_data_header", sx_c_aiff_sound_data_header_fields, SX_COUNT(sx_c_aiff_sound_data_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_aiff_format_version_fields[] = {
    SX_FIELD("timestamp", "uint32", 0, 4, SX_TIME),
};
static const sx_layout sx_c_aiff_format_version = { UINT32_C(0x60020046), "aiff_format_version", sx_c_aiff_format_version_fields, SX_COUNT(sx_c_aiff_format_version_fields), SX_BE };

static const xx_data_struct_field_desc sx_c_au_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("data_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("encoding", "uint32", 12, 4, SX_ID),
    SX_FIELD("sample_rate", "uint32", 16, 4, SX_NONE),
    SX_FIELD("channels", "uint32", 20, 4, SX_COUNT_PROP),
};
static const sx_layout sx_c_au_header = { UINT32_C(0x60020047), "au_header", sx_c_au_header_fields, SX_COUNT(sx_c_au_header_fields), SX_BE };

static const sx_layout *const sx_container_layouts[] = {
    &sx_c_riff_header_le,
    &sx_c_riff_header_be,
    &sx_c_riff_chunk_header_le,
    &sx_c_riff_chunk_header_be,
    &sx_c_riff_list_header_le,
    &sx_c_riff_list_header_be,
    &sx_c_wave_format_le,
    &sx_c_wave_format_be,
    &sx_c_wave_format_extension_size_le,
    &sx_c_wave_format_extension_size_be,
    &sx_c_wave_format_extensible_le,
    &sx_c_wave_format_extensible_be,
    &sx_c_wave_fact_le,
    &sx_c_wave_fact_be,
    &sx_c_avi_main_header,
    &sx_c_avi_stream_header,
    &sx_c_avi_index_entry,
    &sx_c_avi_bitmap_info_header,
    &sx_c_webp_extended_header,
    &sx_c_webp_animation_header,
    &sx_c_webp_animation_frame_header,
    &sx_c_sf2_preset_header,
    &sx_c_sf2_bag,
    &sx_c_sf2_modulator,
    &sx_c_sf2_generator,
    &sx_c_sf2_instrument,
    &sx_c_sf2_sample_header,
    &sx_c_ogg_page_header,
    &sx_c_ogg_lacing_value,
    &sx_c_pcap_file_header_le,
    &sx_c_pcap_file_header_be,
    &sx_c_pcap_packet_header_le,
    &sx_c_pcap_packet_header_be,
    &sx_c_sqlite3_database_header,
    &sx_c_sqlite_btree_leaf_page_header,
    &sx_c_sqlite_btree_interior_page_header,
    &sx_c_sqlite_cell_pointer,
    &sx_c_sqlite_wal_header,
    &sx_c_sqlite_wal_frame_header,
    &sx_c_sfnt_offset_table,
    &sx_c_sfnt_table_record,
    &sx_c_woff_header,
    &sx_c_woff_table_record,
    &sx_c_woff2_header,
    &sx_c_woff2_table_flags,
    &sx_c_woff2_table_tag,
    &sx_c_woff2_base128_1,
    &sx_c_woff2_base128_2,
    &sx_c_woff2_base128_3,
    &sx_c_woff2_base128_4,
    &sx_c_woff2_base128_5,
    &sx_c_font_head_table,
    &sx_c_font_horizontal_header,
    &sx_c_font_maxp_header,
    &sx_c_font_maxp_v1_limits,
    &sx_c_font_name_header,
    &sx_c_font_name_record,
    &sx_c_font_cmap_header,
    &sx_c_font_cmap_encoding_record,
    &sx_c_flac_marker,
    &sx_c_flac_metadata_block_header,
    &sx_c_flac_streaminfo,
    &sx_c_flac_application_header,
    &sx_c_flac_seekpoint,
    &sx_c_aiff_form_header,
    &sx_c_aiff_chunk_header,
    &sx_c_aiff_common_chunk,
    &sx_c_aifc_compression_type,
    &sx_c_aiff_sound_data_header,
    &sx_c_aiff_format_version,
    &sx_c_au_header,
};
/* All walkers describe physical bytes. Compressed or codec payloads stay raw. */
static bool sx_c_bounds(sx_context *c, int64_t off, uint64_t n)
{
    return off >= 0 && off <= c->size && n <= (uint64_t)(c->size - off);
}
static bool sx_c_riff_chunks(sx_context *c, int64_t at, int64_t end, bool be, unsigned depth, uint32_t form)
{
    uint32_t stream_kind=0;
    bool wave=form==UINT32_C(0x57415645), avi=form==UINT32_C(0x41564920)||form==UINT32_C(0x41564958), webp=form==UINT32_C(0x57454250), sf2=form==UINT32_C(0x7366626b);
    if (depth > 32 || at < 0 || end < at || end > c->size) return false;
    while (at < end) {
        uint8_t id[4]; uint32_t n; int64_t body, next; const sx_layout *l = NULL; uint32_t width = 0;
        if (end - at < 8 || !sx_read(c, at, id, 4) || !sx_u32(c, at+4, be, &n) || n > (uint64_t)(end-at-8)) return false;
        body = at + 8; next = body + n;
        if ((n & 1) && next < end) ++next;
        if (!xx_rt_memcmp(id,"LIST",4) || !xx_rt_memcmp(id,"RIFF",4)) {
            uint32_t nested_form=form;
            if (n < 4 || (!xx_rt_memcmp(id,"RIFF",4) && !sx_u32(c,body,true,&nested_form)) ||
                !sx_add(c, be ? &sx_c_riff_list_header_be : &sx_c_riff_list_header_le, at, 12) ||
                !sx_c_riff_chunks(c,body+4,body+n,be,depth+1,nested_form)) return false;
        } else {
            if (!sx_add(c,be ? &sx_c_riff_chunk_header_be : &sx_c_riff_chunk_header_le,at,8)) return false;
            if ((wave && !xx_rt_memcmp(id,"fmt ",4)) || (avi && stream_kind==UINT32_C(0x61756473) && !xx_rt_memcmp(id,"strf",4))) {
                uint16_t tag, ext = 0;
                if (n < 16 || !sx_add(c,be ? &sx_c_wave_format_be : &sx_c_wave_format_le,body,16) || !sx_u16(c,body,be,&tag)) return false;
                width = 16;
                if (n > 16) {
                    if (n < 18 || !sx_u16(c,body+16,be,&ext) || ext > n-18 ||
                        !sx_add(c,be ? &sx_c_wave_format_extension_size_be : &sx_c_wave_format_extension_size_le,body+16,2)) return false;
                    width = 18;
                    if (tag == 0xfffe) {
                        if (ext < 22 || !sx_add(c,be ? &sx_c_wave_format_extensible_be : &sx_c_wave_format_extensible_le,body+18,22)) return false;
                        width = 40;
                    }
                }
            } else if (wave && !xx_rt_memcmp(id,"fact",4)) { l = be ? &sx_c_wave_fact_be : &sx_c_wave_fact_le; width=4; }
            else if (avi && !be && !xx_rt_memcmp(id,"avih",4)) { l=&sx_c_avi_main_header; width=56; }
            else if (avi && !be && !xx_rt_memcmp(id,"strh",4)) { l=&sx_c_avi_stream_header; width=56; if(n<56||!sx_u32(c,body,true,&stream_kind))return false; }
            else if (avi && !be && !xx_rt_memcmp(id,"idx1",4)) {
                if (n%16 || !sx_table(c,&sx_c_avi_index_entry,body,16,n/16)) return false;
                width=n;
            } else if (avi && !be && stream_kind==UINT32_C(0x76696473) && !xx_rt_memcmp(id,"strf",4) && n>=40) {
                uint32_t z;
                if (!sx_u32(c,body,false,&z)) return false;
                if (z==40 || z==52 || z==56 || z==108 || z==124) { l=&sx_c_avi_bitmap_info_header; width=40; }
            } else if (webp && !be && !xx_rt_memcmp(id,"VP8X",4)) { l=&sx_c_webp_extended_header; width=10; }
            else if (webp && !be && !xx_rt_memcmp(id,"ANIM",4)) { l=&sx_c_webp_animation_header; width=6; }
            else if (webp && !be && !xx_rt_memcmp(id,"ANMF",4)) {
                if (n<16 || !sx_add(c,&sx_c_webp_animation_frame_header,body,16) || !sx_c_riff_chunks(c,body+16,body+n,false,depth+1,form)) return false;
                width=n;
            } else if (sf2 && !be) {
                if (!xx_rt_memcmp(id,"phdr",4)) { l=&sx_c_sf2_preset_header; width=38; }
                else if (!xx_rt_memcmp(id,"pbag",4) || !xx_rt_memcmp(id,"ibag",4)) { l=&sx_c_sf2_bag; width=4; }
                else if (!xx_rt_memcmp(id,"pmod",4) || !xx_rt_memcmp(id,"imod",4)) { l=&sx_c_sf2_modulator; width=10; }
                else if (!xx_rt_memcmp(id,"pgen",4) || !xx_rt_memcmp(id,"igen",4)) { l=&sx_c_sf2_generator; width=4; }
                else if (!xx_rt_memcmp(id,"inst",4)) { l=&sx_c_sf2_instrument; width=22; }
                else if (!xx_rt_memcmp(id,"shdr",4)) { l=&sx_c_sf2_sample_header; width=46; }
                if (l) {
                    if (n%width || !sx_table(c,l,body,width,n/width)) return false;
                    l=NULL; width=n;
                }
            }
            if (width>n || (l && !sx_add(c,l,body,width)) || !sx_raw(c,body+width,n-width)) return false;
        }
        if (next > body+n && !sx_raw(c,body+n,next-body-n)) return false;
        at=next;
    }
    return at==end;
}
static bool sx_c_riff(sx_context *c)
{
    uint8_t h[12]; uint32_t n,form; bool be;
    if (!sx_read(c,0,h,sizeof(h))) return false;
    be=!xx_rt_memcmp(h,"RIFX",4);
    if (!be && xx_rt_memcmp(h,"RIFF",4)) return false;
    n=xx_data_get_u32(h+4,4,0,be); form=xx_data_get_u32(h+8,4,0,true);
    if (n<4 || !sx_c_bounds(c,8,n) || !sx_add(c,be ? &sx_c_riff_header_be : &sx_c_riff_header_le,0,12) ||
        !sx_c_riff_chunks(c,12,8+(int64_t)n,be,0,form)) return false;
    return sx_raw(c,8+(int64_t)n,c->size-8-n);
}
static bool sx_c_ogg(sx_context *c)
{
    int64_t at=0;
    while (at<c->size) {
        uint8_t h[27], lacing[255]; uint32_t n=0;
        if (!sx_read(c,at,h,27) || xx_rt_memcmp(h,"OggS",4) || h[4] || (h[5]&~7U) || !sx_read(c,at+27,lacing,h[26])) return false;
        for (unsigned i=0;i<h[26];++i) n+=lacing[i];
        if (!sx_c_bounds(c,at+27+h[26],n) || !sx_add(c,&sx_c_ogg_page_header,at,27) ||
            !sx_table(c,&sx_c_ogg_lacing_value,at+27,1,h[26]) || !sx_raw(c,at+27+h[26],n)) return false;
        at+=27+h[26]+n;
    }
    return at>0;
}
static bool sx_c_pcap(sx_context *c)
{
    uint8_t h[24]; uint32_t magic,snap; bool be,nano; int64_t at=24;
    if (!sx_read(c,0,h,24)) return false;
    magic=xx_data_get_u32(h,4,0,true);
    be=magic==UINT32_C(0xa1b2c3d4)||magic==UINT32_C(0xa1b23c4d);
    nano=magic==UINT32_C(0xa1b23c4d)||magic==UINT32_C(0x4d3cb2a1);
    if (!be && magic!=UINT32_C(0xd4c3b2a1) && magic!=UINT32_C(0x4d3cb2a1)) return false;
    snap=xx_data_get_u32(h+16,4,0,be);
    if (xx_data_get_u16(h+4,2,0,be)!=2 || xx_data_get_u16(h+6,2,0,be)!=4 || !snap ||
        !sx_add(c,be ? &sx_c_pcap_file_header_be : &sx_c_pcap_file_header_le,0,24)) return false;
    while (at<c->size) {
        uint32_t fraction,cap,original;
        if (!sx_u32(c,at+4,be,&fraction) || !sx_u32(c,at+8,be,&cap) || !sx_u32(c,at+12,be,&original) ||
            fraction>=(nano?1000000000U:1000000U) || cap>snap || cap>original || !sx_c_bounds(c,at+16,cap) ||
            !sx_add(c,be ? &sx_c_pcap_packet_header_be : &sx_c_pcap_packet_header_le,at,16) || !sx_raw(c,at+16,cap)) return false;
        at+=16+(int64_t)cap;
    }
    return true;
}
static bool sx_c_sqlite(sx_context *c)
{
    uint8_t h[100],b[12]; uint32_t page,pages,usable; uint16_t cells,start,freeblock; unsigned header;
    if (!sx_read(c,0,h,100) || xx_rt_memcmp(h,"SQLite format 3\0",16)) return false;
    page=xx_data_get_u16(h+16,2,0,true); if(page==1)page=65536;
    pages=xx_data_get_u32(h+28,4,0,true);
    if (page<512||page>65536||(page&(page-1))||h[20]>page-480||!pages||pages>(uint64_t)c->size/page) return false;
    usable=page-h[20];
    if (!sx_add(c,&sx_c_sqlite3_database_header,0,100)||!sx_read(c,100,b,8))return false;
    /* Page one is always the sqlite_schema B-tree. Other page roles require a
     * full logical B-tree/freelist/overflow traversal, and remain explicit raw
     * pages instead of guessing from their leading byte. */
    if (b[0]!=5 && b[0]!=13) return false;
    header=b[0]==5?12:8; cells=xx_data_get_u16(b+3,2,0,true);start=xx_data_get_u16(b+5,2,0,true);freeblock=xx_data_get_u16(b+1,2,0,true);
    if (100U+header+2U*cells>usable || (start && (start<100U+header+2U*cells || start>usable)) || b[7]>60 ||
        (freeblock && (freeblock<100U+header+2U*cells || freeblock>usable-4))) return false;
    if (!sx_add(c,b[0]==5?&sx_c_sqlite_btree_interior_page_header:&sx_c_sqlite_btree_leaf_page_header,100,header) ||
        !sx_table(c,&sx_c_sqlite_cell_pointer,100+header,2,cells)) return false;
    for (uint32_t i=0;i<cells;++i) {
        uint16_t cell;
        if (!sx_u16(c,100+header+2*i,true,&cell) || cell<100U+header+2U*cells || cell>=usable) return false;
    }
    if (!sx_raw(c,100+header+2*cells,page-(100+header+2*cells))) return false;
    /* Coalesce uninterpreted pages to avoid one allocation per page. */
    return sx_raw(c,page,(int64_t)(pages-1)*page) && sx_raw(c,(int64_t)pages*page,c->size-(int64_t)pages*page);
}
static bool sx_c_sqlite_wal(sx_context *c)
{
    uint8_t h[32]; uint32_t magic,page; int64_t at=32;
    if (!sx_read(c,0,h,32))return false;
    magic=xx_data_get_u32(h,4,0,true);page=xx_data_get_u32(h+8,4,0,true);
    if ((magic!=UINT32_C(0x377f0682)&&magic!=UINT32_C(0x377f0683)) || page<512 || page>65536 || (page&(page-1)) ||
        !sx_add(c,&sx_c_sqlite_wal_header,0,32))return false;
    while(at<c->size) {
        uint32_t page_number,salt1,salt2;
        if(!sx_c_bounds(c,at,24+(uint64_t)page)||!sx_u32(c,at,true,&page_number)||!page_number||
           !sx_u32(c,at+8,true,&salt1)||!sx_u32(c,at+12,true,&salt2)||salt1!=xx_data_get_u32(h+16,4,0,true)||salt2!=xx_data_get_u32(h+20,4,0,true)||
           !sx_add(c,&sx_c_sqlite_wal_frame_header,at,24)||!sx_raw(c,at+24,page))return false;
        at+=24+(int64_t)page;
    }
    return true;
}
static bool sx_c_font_table(sx_context *c,const uint8_t tag[4],int64_t off,uint32_t n)
{
    const sx_layout *layout=NULL; uint32_t width=0;
    if(!sx_c_bounds(c,off,n))return false;
    if(!xx_rt_memcmp(tag,"head",4)){layout=&sx_c_font_head_table;width=54;}
    else if(!xx_rt_memcmp(tag,"hhea",4)){layout=&sx_c_font_horizontal_header;width=36;}
    else if(!xx_rt_memcmp(tag,"maxp",4)) {
        uint32_t v;
        if(n<6||!sx_u32(c,off,true,&v)||!sx_add(c,&sx_c_font_maxp_header,off,6))return false;
        width=6;
        if(v==UINT32_C(0x10000)){
            if(n<32||!sx_add(c,&sx_c_font_maxp_v1_limits,off+6,26))return false;
            width=32;
        }
    } else if(!xx_rt_memcmp(tag,"name",4)) {
        uint16_t count,strings;
        if(n<6||!sx_u16(c,off+2,true,&count)||!sx_u16(c,off+4,true,&strings)||count>(n-6)/12||strings>n||
           !sx_add(c,&sx_c_font_name_header,off,6)||!sx_table(c,&sx_c_font_name_record,off+6,12,count))return false;
        width=6+12U*count;
    } else if(!xx_rt_memcmp(tag,"cmap",4)) {
        uint16_t count;
        if(n<4||!sx_u16(c,off+2,true,&count)||count>(n-4)/8||!sx_add(c,&sx_c_font_cmap_header,off,4)||
           !sx_table(c,&sx_c_font_cmap_encoding_record,off+4,8,count))return false;
        width=4+8U*count;
    }
    if(width>n || (layout&&!sx_add(c,layout,off,width)))return false;
    return sx_raw(c,off+width,n-width);
}
static bool sx_c_sfnt(sx_context *c)
{
    uint8_t h[12];uint32_t version;uint16_t count;
    if(!sx_read(c,0,h,12))return false;
    version=xx_data_get_u32(h,4,0,true);count=xx_data_get_u16(h+4,2,0,true);
    if((version!=UINT32_C(0x10000)&&version!=UINT32_C(0x4f54544f)&&version!=UINT32_C(0x74727565)&&version!=UINT32_C(0x74797031))||
       !count||!sx_c_bounds(c,12,16U*(uint64_t)count)||!sx_add(c,&sx_c_sfnt_offset_table,0,12)||!sx_table(c,&sx_c_sfnt_table_record,12,16,count))return false;
    for(uint32_t i=0;i<count;++i){
        uint8_t d[16];uint32_t off,n;
        if(!sx_read(c,12+16*(int64_t)i,d,16))return false;
        off=xx_data_get_u32(d+8,4,0,true);n=xx_data_get_u32(d+12,4,0,true);
        if(off<12U+16U*count||!sx_c_font_table(c,d,off,n))return false;
    }
    return true;
}
static bool sx_c_woff(sx_context *c)
{
    uint8_t h[44];uint32_t total;uint16_t count;
    if(!sx_read(c,0,h,44)||xx_rt_memcmp(h,"wOFF",4))return false;
    count=xx_data_get_u16(h+12,2,0,true);total=xx_data_get_u32(h+8,4,0,true);
    if(!count||total>c->size||total<44U+20U*count||xx_data_get_u16(h+14,2,0,true)||!sx_add(c,&sx_c_woff_header,0,44)||
       !sx_table(c,&sx_c_woff_table_record,44,20,count))return false;
    for(uint32_t i=0;i<count;++i){
        uint8_t d[20];uint32_t off,n,orig;
        if(!sx_read(c,44+20*(int64_t)i,d,20))return false;
        off=xx_data_get_u32(d+4,4,0,true);n=xx_data_get_u32(d+8,4,0,true);orig=xx_data_get_u32(d+12,4,0,true);
        if(off<44U+20U*count||off>total||n>total-off||n>orig)return false;
        if(n==orig){if(!sx_c_font_table(c,d,off,n))return false;}
        else if(!sx_raw(c,off,n))return false;
    }
    for(unsigned i=0;i<2;++i){
        uint32_t off=xx_data_get_u32(h+(i?36:24),4,0,true),n=xx_data_get_u32(h+(i?40:28),4,0,true);
        if((!off)!=(!n)||off>total||n>total-off||!sx_raw(c,off,n))return false;
    }
    return sx_raw(c,total,c->size-total);
}
static bool sx_c_woff2_base128(sx_context *c,int64_t *at,uint32_t *value)
{
    static const sx_layout *const rows[]={&sx_c_woff2_base128_1,&sx_c_woff2_base128_2,&sx_c_woff2_base128_3,&sx_c_woff2_base128_4,&sx_c_woff2_base128_5};
    uint32_t v=0;int64_t start=*at;
    for(unsigned i=0;i<5;++i){
        uint8_t b;
        if(!sx_read(c,(*at)++,&b,1)||(!i&&b==0x80)||(v&UINT32_C(0xfe000000)))return false;
        v=(v<<7)|(b&127U);
        if(!(b&128U)){*value=v;return sx_add(c,rows[i],start,i+1);}
    }
    return false;
}
static bool sx_c_woff2(sx_context *c)
{
    uint8_t h[48];uint16_t count;uint32_t total,packed;int64_t at=48;
    if(!sx_read(c,0,h,48)||xx_rt_memcmp(h,"wOF2",4))return false;
    count=xx_data_get_u16(h+12,2,0,true);total=xx_data_get_u32(h+8,4,0,true);packed=xx_data_get_u32(h+20,4,0,true);
    if(!count||total>c->size||total<48||!packed||xx_data_get_u16(h+14,2,0,true)||!sx_add(c,&sx_c_woff2_header,0,48))return false;
    /* Font collections require the additional collection directory and are
     * outside the current native WOFF2 reader's supported single-font subset. */
    if(xx_data_get_u32(h+4,4,0,true)==UINT32_C(0x74746366))return false;
    for(uint32_t i=0;i<count;++i){
        uint8_t flags,tag[4]={0};uint32_t len;unsigned index,transform;bool glyf_loca;
        if(!sx_read(c,at,&flags,1)||!sx_add(c,&sx_c_woff2_table_flags,at++,1))return false;
        index=flags&63U;transform=flags>>6;
        if(index==63){if(!sx_read(c,at,tag,4)||!sx_add(c,&sx_c_woff2_table_tag,at,4))return false;at+=4;}
        glyf_loca=index==10||index==11||(index==63&&(!xx_rt_memcmp(tag,"glyf",4)||!xx_rt_memcmp(tag,"loca",4)));
        if(!sx_c_woff2_base128(c,&at,&len))return false;
        if((glyf_loca&&transform!=3)||(!glyf_loca&&transform!=0))if(!sx_c_woff2_base128(c,&at,&len))return false;
    }
    if(at>total||packed>(uint64_t)(total-at)||!sx_raw(c,at,packed))return false;
    at+=packed;
    for(unsigned i=0;i<2;++i){
        uint32_t off=xx_data_get_u32(h+(i?40:28),4,0,true),n=xx_data_get_u32(h+(i?44:32),4,0,true);
        if(!off&&!n)continue;
        if(!off||!n||off<at||off>total||n>total-off||!sx_raw(c,at,off-at)||!sx_raw(c,off,n))return false;
        at=off+(int64_t)n;
    }
    return at<=total&&sx_raw(c,at,c->size-at);
}
static bool sx_c_flac(sx_context *c)
{
    uint8_t h[4];int64_t at=4;bool last=false;unsigned blocks=0;
    if(!sx_read(c,0,h,4)||xx_rt_memcmp(h,"fLaC",4)||!sx_add(c,&sx_c_flac_marker,0,4))return false;
    while(!last){
        uint32_t n;unsigned type;uint32_t width=0;
        if(!sx_read(c,at,h,4))return false;
        type=h[0]&127U;last=(h[0]&128U)!=0;n=((uint32_t)h[1]<<16)|((uint32_t)h[2]<<8)|h[3];
        if(type==127||(!blocks&&type!=0)||!sx_c_bounds(c,at+4,n)||!sx_add(c,&sx_c_flac_metadata_block_header,at,4))return false;
        at+=4;
        if(type==0){if(n!=34||blocks||!sx_add(c,&sx_c_flac_streaminfo,at,34))return false;width=34;}
        else if(type==2){if(n<4||!sx_add(c,&sx_c_flac_application_header,at,4))return false;width=4;}
        else if(type==3){if(n%18||!sx_table(c,&sx_c_flac_seekpoint,at,18,n/18))return false;width=n;}
        if(!sx_raw(c,at+width,n-width))return false;
        at+=n;++blocks;
    }
    return sx_raw(c,at,c->size-at);
}
static bool sx_c_aiff(sx_context *c)
{
    uint8_t h[12];uint32_t n;int64_t at=12,end;bool compressed;
    if(!sx_read(c,0,h,12)||xx_rt_memcmp(h,"FORM",4)||(xx_rt_memcmp(h+8,"AIFF",4)&&xx_rt_memcmp(h+8,"AIFC",4)))return false;
    compressed=!xx_rt_memcmp(h+8,"AIFC",4);n=xx_data_get_u32(h+4,4,0,true);end=8+(int64_t)n;
    if(n<4||end>c->size||!sx_add(c,&sx_c_aiff_form_header,0,12))return false;
    while(at<end){
        uint8_t id[4];uint32_t len,width=0;int64_t body;const sx_layout *l=NULL;
        if(end-at<8||!sx_read(c,at,id,4)||!sx_u32(c,at+4,true,&len)||len>(uint64_t)(end-at-8)||!sx_add(c,&sx_c_aiff_chunk_header,at,8))return false;
        body=at+8;
        if(!xx_rt_memcmp(id,"COMM",4)){
            if(len<18||!sx_add(c,&sx_c_aiff_common_chunk,body,18))return false;width=18;
            if(compressed){if(len<22||!sx_add(c,&sx_c_aifc_compression_type,body+18,4))return false;width=22;}
        }else if(!xx_rt_memcmp(id,"SSND",4)){l=&sx_c_aiff_sound_data_header;width=8;}
        else if(!xx_rt_memcmp(id,"FVER",4)){l=&sx_c_aiff_format_version;width=4;}
        if(width>len||(l&&!sx_add(c,l,body,width))||!sx_raw(c,body+width,len-width))return false;
        at=body+len;if((len&1)&&at<end){if(!sx_raw(c,at,1))return false;++at;}
    }
    return at==end&&sx_raw(c,end,c->size-end);
}
static bool sx_c_au(sx_context *c)
{
    uint8_t h[24];uint32_t off,n;
    if(!sx_read(c,0,h,24)||xx_rt_memcmp(h,".snd",4))return false;
    off=xx_data_get_u32(h+4,4,0,true);n=xx_data_get_u32(h+8,4,0,true);
    if(off<24||off>c->size||(n!=UINT32_MAX&&!sx_c_bounds(c,off,n))||!sx_add(c,&sx_c_au_header,0,24)||!sx_raw(c,24,off-24))return false;
    return sx_raw(c,off,c->size-off);
}
static bool sx_container_supports(xx_file_type_t type)
{
    switch(type){
        case XX_FILE_TYPE_RIFF:case XX_FILE_TYPE_AUDIO_RIFX_WAVE:case XX_FILE_TYPE_AUDIO_RIFF_IMA:
        case XX_FILE_TYPE_AUDIO_WWISE_WEM:case XX_FILE_TYPE_SOUNDFONT2:
        case XX_FILE_TYPE_OGG:case XX_FILE_TYPE_PCAP:case XX_FILE_TYPE_SQLITE3:case XX_FILE_TYPE_SQLITE_WAL:
        case XX_FILE_TYPE_SFNT:case XX_FILE_TYPE_WOFF:case XX_FILE_TYPE_WOFF2:case XX_FILE_TYPE_FLAC:
        case XX_FILE_TYPE_AIFF:case XX_FILE_TYPE_AUDIO_AU:return true;
        default:return false;
    }
}
static bool sx_container_build(sx_context *c)
{
    switch(c->f->file_type){
        case XX_FILE_TYPE_RIFF:case XX_FILE_TYPE_AUDIO_RIFX_WAVE:case XX_FILE_TYPE_AUDIO_RIFF_IMA:
        case XX_FILE_TYPE_AUDIO_WWISE_WEM:case XX_FILE_TYPE_SOUNDFONT2:return sx_c_riff(c);
        case XX_FILE_TYPE_OGG:return sx_c_ogg(c);
        case XX_FILE_TYPE_PCAP:return sx_c_pcap(c);
        case XX_FILE_TYPE_SQLITE3:return sx_c_sqlite(c);
        case XX_FILE_TYPE_SQLITE_WAL:return sx_c_sqlite_wal(c);
        case XX_FILE_TYPE_SFNT:return sx_c_sfnt(c);
        case XX_FILE_TYPE_WOFF:return sx_c_woff(c);
        case XX_FILE_TYPE_WOFF2:return sx_c_woff2(c);
        case XX_FILE_TYPE_FLAC:return sx_c_flac(c);
        case XX_FILE_TYPE_AIFF:return sx_c_aiff(c);
        case XX_FILE_TYPE_AUDIO_AU:return sx_c_au(c);
        default:return false;
    }
}
static bool sx_container_comment(xx_data_struct_record *rec,uint32_t id)
{
    uint64_t v; const wchar_t *s=NULL;
    if(!rec||id<UINT32_C(0x60020001)||id>UINT32_C(0x6002ffff))return true;
    v=xx_var_get_u64(&rec->value);
    if(id==sx_c_sqlite3_database_header.id){
        if(!xx_rt_wcscmp(rec->name,L"text_encoding"))s=v==1?L"UTF-8":v==2?L"UTF-16 little endian":v==3?L"UTF-16 big endian":NULL;
        else if(!xx_rt_wcscmp(rec->name,L"write_version")||!xx_rt_wcscmp(rec->name,L"read_version"))s=v==1?L"Rollback journal":v==2?L"WAL":NULL;
        else if(!xx_rt_wcscmp(rec->name,L"page_size")&&v==1)s=L"65536 bytes (encoded as 1)";
        else if(!xx_rt_wcscmp(rec->name,L"default_page_cache_size"))s=L"Absolute value is the suggested cache size in pages";
    }else if(id==sx_c_sqlite_btree_leaf_page_header.id||id==sx_c_sqlite_btree_interior_page_header.id){
        if(!xx_rt_wcscmp(rec->name,L"page_type"))s=v==2?L"Interior index B-tree":v==5?L"Interior table B-tree":v==10?L"Leaf index B-tree":v==13?L"Leaf table B-tree":NULL;
        else if(!xx_rt_wcscmp(rec->name,L"cell_content_offset")&&v==0)s=L"65536 (encoded as zero)";
    }else if(id==sx_c_wave_format_le.id||id==sx_c_wave_format_be.id){
        if(!xx_rt_wcscmp(rec->name,L"format_tag"))s=v==1?L"WAVE_FORMAT_PCM":v==3?L"WAVE_FORMAT_IEEE_FLOAT":v==6?L"WAVE_FORMAT_ALAW":v==7?L"WAVE_FORMAT_MULAW":v==17?L"WAVE_FORMAT_DVI_ADPCM":v==0xfffe?L"WAVE_FORMAT_EXTENSIBLE":NULL;
        else if(!xx_rt_wcscmp(rec->name,L"average_bytes_per_second"))s=L"Bytes per second";
    }else if(id==sx_c_flac_streaminfo.id){
        if(!xx_rt_wcscmp(rec->name,L"minimum_block_size")||!xx_rt_wcscmp(rec->name,L"maximum_block_size"))s=L"Samples per channel";
    }else if(id==sx_c_au_header.id&&!xx_rt_wcscmp(rec->name,L"encoding")){
        s=v==1?L"8-bit mu-law":v==2?L"8-bit linear PCM":v==3?L"16-bit linear PCM":v==4?L"24-bit linear PCM":v==5?L"32-bit linear PCM":v==6?L"32-bit IEEE float":v==7?L"64-bit IEEE float":v==27?L"8-bit A-law":NULL;
    }else if(id==sx_c_ogg_page_header.id&&!xx_rt_wcscmp(rec->name,L"header_type")){
        static const wchar_t *const names[]={L"0",L"CONTINUED_PACKET",L"BEGINNING_OF_STREAM",L"CONTINUED_PACKET|BEGINNING_OF_STREAM",L"END_OF_STREAM",L"CONTINUED_PACKET|END_OF_STREAM",L"BEGINNING_OF_STREAM|END_OF_STREAM",L"CONTINUED_PACKET|BEGINNING_OF_STREAM|END_OF_STREAM"};
        if(v<8)s=names[v];
    }else if(id==sx_c_flac_metadata_block_header.id&&!xx_rt_wcscmp(rec->name,L"last_block_and_type")){
        static const wchar_t *const names[]={L"STREAMINFO",L"PADDING",L"APPLICATION",L"SEEKTABLE",L"VORBIS_COMMENT",L"CUESHEET",L"PICTURE"};
        static const wchar_t *const last[]={L"LAST_BLOCK|STREAMINFO",L"LAST_BLOCK|PADDING",L"LAST_BLOCK|APPLICATION",L"LAST_BLOCK|SEEKTABLE",L"LAST_BLOCK|VORBIS_COMMENT",L"LAST_BLOCK|CUESHEET",L"LAST_BLOCK|PICTURE"};
        if((v&127U)<7)s=(v&128U)?last[v&127U]:names[v&127U];
    }
    return !s||xx_data_struct_record_set_comment(rec,s);
}
