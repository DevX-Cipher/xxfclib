/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bounded physical container, audio, font, capture and database schemas.
 * Specification links are retained by the corresponding native readers.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_container.h"
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
const sx_layout sx_c_ogg_page_header = { UINT32_C(0x6002001C), "ogg_page_header", sx_c_ogg_page_header_fields, SX_COUNT(sx_c_ogg_page_header_fields), SX_LE };
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
const sx_layout sx_c_sqlite3_database_header = { UINT32_C(0x60020022), "sqlite3_database_header", sx_c_sqlite3_database_header_fields, SX_COUNT(sx_c_sqlite3_database_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_sqlite_btree_leaf_page_header_fields[] = {
    SX_FIELD("page_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("first_freeblock_offset", "uint16", 1, 2, SX_OFFSET),
    SX_FIELD("cell_count", "uint16", 3, 2, SX_COUNT_PROP),
    SX_FIELD("cell_content_offset", "uint16", 5, 2, SX_OFFSET),
    SX_FIELD("fragmented_free_bytes", "uint8", 7, 1, SX_SIZE),
};
const sx_layout sx_c_sqlite_btree_leaf_page_header = { UINT32_C(0x60020023), "sqlite_btree_leaf_page_header", sx_c_sqlite_btree_leaf_page_header_fields, SX_COUNT(sx_c_sqlite_btree_leaf_page_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_sqlite_btree_interior_page_header_fields[] = {
    SX_FIELD("page_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("first_freeblock_offset", "uint16", 1, 2, SX_OFFSET),
    SX_FIELD("cell_count", "uint16", 3, 2, SX_COUNT_PROP),
    SX_FIELD("cell_content_offset", "uint16", 5, 2, SX_OFFSET),
    SX_FIELD("fragmented_free_bytes", "uint8", 7, 1, SX_SIZE),
    SX_FIELD("rightmost_child_page", "uint32", 8, 4, SX_NONE),
};
const sx_layout sx_c_sqlite_btree_interior_page_header = { UINT32_C(0x60020024), "sqlite_btree_interior_page_header", sx_c_sqlite_btree_interior_page_header_fields, SX_COUNT(sx_c_sqlite_btree_interior_page_header_fields), SX_BE };
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
static const xx_data_struct_field_desc sx_c_flac_metadata_block_header_fields[] = {
    SX_FIELD("last_block_and_type", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("length", "uint24", 1, 3, SX_SIZE),
};
const sx_layout sx_c_flac_metadata_block_header = { UINT32_C(0x6002003D), "flac_metadata_block_header", sx_c_flac_metadata_block_header_fields, SX_COUNT(sx_c_flac_metadata_block_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_flac_streaminfo_fields[] = {
    SX_FIELD("minimum_block_size", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("maximum_block_size", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("minimum_frame_size", "uint24", 4, 3, SX_SIZE),
    SX_FIELD("maximum_frame_size", "uint24", 7, 3, SX_SIZE),
    SX_FIELD("sample_rate_channels_bits_total_samples", "uint64", 10, 8, SX_FLAGS),
    SX_FIELD("md5_signature", "bytes", 18, 16, SX_CHECKSUM),
};
const sx_layout sx_c_flac_streaminfo = { UINT32_C(0x6002003E), "flac_streaminfo", sx_c_flac_streaminfo_fields, SX_COUNT(sx_c_flac_streaminfo_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_au_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("data_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("encoding", "uint32", 12, 4, SX_ID),
    SX_FIELD("sample_rate", "uint32", 16, 4, SX_NONE),
    SX_FIELD("channels", "uint32", 20, 4, SX_COUNT_PROP),
};
const sx_layout sx_c_au_header = { UINT32_C(0x60020047), "au_header", sx_c_au_header_fields, SX_COUNT(sx_c_au_header_fields), SX_BE };
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
bool sx_c_bounds(sx_context *c, int64_t off, uint64_t n)
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
bool sx_c_riff(sx_context *c)
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
bool sx_c_font_table(sx_context *c,const uint8_t tag[4],int64_t off,uint32_t n)
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
    if(c->f->file_type==XX_FILE_TYPE_RIFF)return sx_riff_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_RIFX_WAVE)return sx_audio_rifx_wave_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_RIFF_IMA)return sx_audio_riff_ima_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_WWISE_WEM)return sx_audio_wwise_wem_build(c);
    if(c->f->file_type==XX_FILE_TYPE_SOUNDFONT2)return sx_soundfont2_build(c);
    if(c->f->file_type==XX_FILE_TYPE_OGG)return sx_ogg_build(c);
    if(c->f->file_type==XX_FILE_TYPE_PCAP)return sx_pcap_build(c);
    if(c->f->file_type==XX_FILE_TYPE_SQLITE3)return sx_sqlite3_build(c);
    if(c->f->file_type==XX_FILE_TYPE_SQLITE_WAL)return sx_sqlite_wal_build(c);
    if(c->f->file_type==XX_FILE_TYPE_SFNT)return sx_sfnt_build(c);
    if(c->f->file_type==XX_FILE_TYPE_WOFF)return sx_woff_build(c);
    if(c->f->file_type==XX_FILE_TYPE_WOFF2)return sx_woff2_build(c);
    if(c->f->file_type==XX_FILE_TYPE_FLAC)return sx_flac_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AIFF)return sx_aiff_build(c);
    if(c->f->file_type==XX_FILE_TYPE_AUDIO_AU)return sx_audio_au_build(c);
    return false;
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
const sx_family sx_container_family={sx_container_supports,sx_container_build,sx_container_layouts,SX_COUNT(sx_container_layouts),sx_container_comment};
