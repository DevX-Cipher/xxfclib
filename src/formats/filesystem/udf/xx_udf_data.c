/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * UDF (ECMA-167) data structures, moved out of the opticalfs schema family. */
#include "../../xx_format_schema_opticalfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxo_udf_volume_recognition_descriptor_fields[] = {
    SX_FIELD("structure_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("structure_version", "uint8", 6, 1, SX_ID),
};
const sx_layout sxo_udf_volume_recognition_descriptor = {UINT32_C(0x6013000A),"udf_volume_recognition_descriptor",sxo_udf_volume_recognition_descriptor_fields,SX_COUNT(sxo_udf_volume_recognition_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_descriptor_tag_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
};
const sx_layout sxo_udf_descriptor_tag = {UINT32_C(0x6013000B),"udf_descriptor_tag",sxo_udf_descriptor_tag_fields,SX_COUNT(sxo_udf_descriptor_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_anchor_volume_descriptor_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("main_extent_length", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("main_extent_location", "uint32", 20, 4, SX_NONE),
    SX_FIELD("reserve_extent_length", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("reserve_extent_location", "uint32", 28, 4, SX_NONE),
    SX_FIELD("reserved", "bytes", 32, 480, SX_RESERVED),
};
const sx_layout sxo_udf_anchor_volume_descriptor = {UINT32_C(0x6013000C),"udf_anchor_volume_descriptor",sxo_udf_anchor_volume_descriptor_fields,SX_COUNT(sxo_udf_anchor_volume_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_primary_volume_descriptor_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("sequence_number", "uint32", 16, 4, SX_NONE),
    SX_FIELD("descriptor_number", "uint32", 20, 4, SX_NONE),
    SX_FIELD("volume_identifier", "uint8[32]", 24, 32, SX_NONE),
    SX_FIELD("volume_sequence", "uint16", 56, 2, SX_NONE),
    SX_FIELD("maximum_volume_sequence", "uint16", 58, 2, SX_NONE),
    SX_FIELD("interchange_level", "uint16", 60, 2, SX_NONE),
    SX_FIELD("maximum_interchange_level", "uint16", 62, 2, SX_NONE),
    SX_FIELD("character_set_list", "uint32", 64, 4, SX_FLAGS),
    SX_FIELD("maximum_character_set_list", "uint32", 68, 4, SX_FLAGS),
    SX_FIELD("volume_set_identifier", "uint8[128]", 72, 128, SX_NONE),
    SX_FIELD("descriptor_character_set_type", "uint8", 200, 1, SX_ID),
    SX_FIELD("descriptor_character_set_information", "uint8[63]", 201, 63, SX_NONE),
    SX_FIELD("explanatory_character_set_type", "uint8", 264, 1, SX_ID),
    SX_FIELD("explanatory_character_set_information", "uint8[63]", 265, 63, SX_NONE),
    SX_FIELD("volume_abstract_extent_length", "uint32", 328, 4, SX_SIZE),
    SX_FIELD("volume_abstract_extent_location", "uint32", 332, 4, SX_NONE),
    SX_FIELD("volume_copyright_extent_length", "uint32", 336, 4, SX_SIZE),
    SX_FIELD("volume_copyright_extent_location", "uint32", 340, 4, SX_NONE),
    SX_FIELD("application_flags", "uint8", 344, 1, SX_FLAGS),
    SX_FIELD("application_identifier", "char[23]", 345, 23, SX_STRING),
    SX_FIELD("application_suffix", "uint8[8]", 368, 8, SX_NONE),
    SX_FIELD("recorded_type_timezone", "uint16", 376, 2, SX_FLAGS),
    SX_FIELD("recorded_year", "uint16", 378, 2, SX_NONE),
    SX_FIELD("recorded_month", "uint8", 380, 1, SX_NONE),
    SX_FIELD("recorded_day", "uint8", 381, 1, SX_NONE),
    SX_FIELD("recorded_hour", "uint8", 382, 1, SX_NONE),
    SX_FIELD("recorded_minute", "uint8", 383, 1, SX_NONE),
    SX_FIELD("recorded_second", "uint8", 384, 1, SX_NONE),
    SX_FIELD("recorded_centiseconds", "uint8", 385, 1, SX_NONE),
    SX_FIELD("recorded_hundreds_microseconds", "uint8", 386, 1, SX_NONE),
    SX_FIELD("recorded_microseconds", "uint8", 387, 1, SX_NONE),
    SX_FIELD("implementation_flags", "uint8", 388, 1, SX_FLAGS),
    SX_FIELD("implementation_identifier", "char[23]", 389, 23, SX_STRING),
    SX_FIELD("implementation_suffix", "uint8[8]", 412, 8, SX_NONE),
    SX_FIELD("implementation_use", "uint8[64]", 420, 64, SX_NONE),
    SX_FIELD("predecessor_volume_sequence_location", "uint32", 484, 4, SX_NONE),
    SX_FIELD("flags", "uint16", 488, 2, SX_FLAGS),
    SX_FIELD("reserved", "bytes", 490, 22, SX_RESERVED),
};
const sx_layout sxo_udf_primary_volume_descriptor = {UINT32_C(0x6013000D),"udf_primary_volume_descriptor",sxo_udf_primary_volume_descriptor_fields,SX_COUNT(sxo_udf_primary_volume_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_partition_descriptor_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("sequence_number", "uint32", 16, 4, SX_NONE),
    SX_FIELD("partition_flags", "uint16", 20, 2, SX_FLAGS),
    SX_FIELD("partition_number", "uint16", 22, 2, SX_NONE),
    SX_FIELD("contents_flags", "uint8", 24, 1, SX_FLAGS),
    SX_FIELD("contents_identifier", "char[23]", 25, 23, SX_STRING),
    SX_FIELD("contents_suffix", "uint8[8]", 48, 8, SX_NONE),
    SX_FIELD("contents_use", "uint8[128]", 56, 128, SX_NONE),
    SX_FIELD("access_type", "uint32", 184, 4, SX_ID),
    SX_FIELD("starting_location", "uint32", 188, 4, SX_NONE),
    SX_FIELD("length_blocks", "uint32", 192, 4, SX_COUNT_PROP),
    SX_FIELD("implementation_flags", "uint8", 196, 1, SX_FLAGS),
    SX_FIELD("implementation_identifier", "char[23]", 197, 23, SX_STRING),
    SX_FIELD("implementation_suffix", "uint8[8]", 220, 8, SX_NONE),
    SX_FIELD("implementation_use", "uint8[128]", 228, 128, SX_NONE),
    SX_FIELD("reserved", "bytes", 356, 156, SX_RESERVED),
};
const sx_layout sxo_udf_partition_descriptor = {UINT32_C(0x6013000E),"udf_partition_descriptor",sxo_udf_partition_descriptor_fields,SX_COUNT(sxo_udf_partition_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_logical_volume_descriptor_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("sequence_number", "uint32", 16, 4, SX_NONE),
    SX_FIELD("descriptor_character_set_type", "uint8", 20, 1, SX_ID),
    SX_FIELD("descriptor_character_set_information", "uint8[63]", 21, 63, SX_NONE),
    SX_FIELD("logical_volume_identifier", "uint8[128]", 84, 128, SX_NONE),
    SX_FIELD("logical_block_size", "uint32", 212, 4, SX_SIZE),
    SX_FIELD("domain_flags", "uint8", 216, 1, SX_FLAGS),
    SX_FIELD("domain_identifier", "char[23]", 217, 23, SX_STRING),
    SX_FIELD("domain_suffix", "uint8[8]", 240, 8, SX_NONE),
    SX_FIELD("fileset_extent_length_flags", "uint32", 248, 4, SX_FLAGS),
    SX_FIELD("fileset_logical_block", "uint32", 252, 4, SX_NONE),
    SX_FIELD("fileset_partition_reference", "uint16", 256, 2, SX_NONE),
    SX_FIELD("fileset_implementation_use", "uint8[6]", 258, 6, SX_NONE),
    SX_FIELD("map_table_length", "uint32", 264, 4, SX_SIZE),
    SX_FIELD("partition_map_count", "uint32", 268, 4, SX_COUNT_PROP),
    SX_FIELD("implementation_flags", "uint8", 272, 1, SX_FLAGS),
    SX_FIELD("implementation_identifier", "char[23]", 273, 23, SX_STRING),
    SX_FIELD("implementation_suffix", "uint8[8]", 296, 8, SX_NONE),
    SX_FIELD("implementation_use", "uint8[128]", 304, 128, SX_NONE),
    SX_FIELD("integrity_sequence_extent_length", "uint32", 432, 4, SX_SIZE),
    SX_FIELD("integrity_sequence_extent_location", "uint32", 436, 4, SX_NONE),
};
const sx_layout sxo_udf_logical_volume_descriptor = {UINT32_C(0x6013000F),"udf_logical_volume_descriptor",sxo_udf_logical_volume_descriptor_fields,SX_COUNT(sxo_udf_logical_volume_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_partition_map_type1_fields[] = {
    SX_FIELD("map_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("map_length", "uint8", 1, 1, SX_SIZE),
    SX_FIELD("volume_sequence", "uint16", 2, 2, SX_NONE),
    SX_FIELD("partition_number", "uint16", 4, 2, SX_NONE),
};
const sx_layout sxo_udf_partition_map_type1 = {UINT32_C(0x60130010),"udf_partition_map_type1",sxo_udf_partition_map_type1_fields,SX_COUNT(sxo_udf_partition_map_type1_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_partition_map_header_fields[] = {
    SX_FIELD("map_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("map_length", "uint8", 1, 1, SX_SIZE),
};
const sx_layout sxo_udf_partition_map_header = {UINT32_C(0x60130011),"udf_partition_map_header",sxo_udf_partition_map_header_fields,SX_COUNT(sxo_udf_partition_map_header_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_terminating_descriptor_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("reserved", "bytes", 16, 496, SX_RESERVED),
};
const sx_layout sxo_udf_terminating_descriptor = {UINT32_C(0x60130012),"udf_terminating_descriptor",sxo_udf_terminating_descriptor_fields,SX_COUNT(sxo_udf_terminating_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_file_set_descriptor_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("recorded_type_timezone", "uint16", 16, 2, SX_FLAGS),
    SX_FIELD("recorded_year", "uint16", 18, 2, SX_NONE),
    SX_FIELD("recorded_month", "uint8", 20, 1, SX_NONE),
    SX_FIELD("recorded_day", "uint8", 21, 1, SX_NONE),
    SX_FIELD("recorded_hour", "uint8", 22, 1, SX_NONE),
    SX_FIELD("recorded_minute", "uint8", 23, 1, SX_NONE),
    SX_FIELD("recorded_second", "uint8", 24, 1, SX_NONE),
    SX_FIELD("recorded_centiseconds", "uint8", 25, 1, SX_NONE),
    SX_FIELD("recorded_hundreds_microseconds", "uint8", 26, 1, SX_NONE),
    SX_FIELD("recorded_microseconds", "uint8", 27, 1, SX_NONE),
    SX_FIELD("interchange_level", "uint16", 28, 2, SX_NONE),
    SX_FIELD("maximum_interchange_level", "uint16", 30, 2, SX_NONE),
    SX_FIELD("character_set_list", "uint32", 32, 4, SX_FLAGS),
    SX_FIELD("maximum_character_set_list", "uint32", 36, 4, SX_FLAGS),
    SX_FIELD("file_set_number", "uint32", 40, 4, SX_NONE),
    SX_FIELD("descriptor_number", "uint32", 44, 4, SX_NONE),
    SX_FIELD("logical_volume_identifier_character_set_type", "uint8", 48, 1, SX_ID),
    SX_FIELD("logical_volume_identifier_character_set_information", "uint8[63]", 49, 63, SX_NONE),
    SX_FIELD("logical_volume_identifier", "uint8[128]", 112, 128, SX_NONE),
    SX_FIELD("fileset_character_set_type", "uint8", 240, 1, SX_ID),
    SX_FIELD("fileset_character_set_information", "uint8[63]", 241, 63, SX_NONE),
    SX_FIELD("file_set_identifier", "uint8[32]", 304, 32, SX_NONE),
    SX_FIELD("copyright_identifier", "uint8[32]", 336, 32, SX_NONE),
    SX_FIELD("abstract_identifier", "uint8[32]", 368, 32, SX_NONE),
    SX_FIELD("root_directory_extent_length_flags", "uint32", 400, 4, SX_FLAGS),
    SX_FIELD("root_directory_logical_block", "uint32", 404, 4, SX_NONE),
    SX_FIELD("root_directory_partition_reference", "uint16", 408, 2, SX_NONE),
    SX_FIELD("root_directory_implementation_use", "uint8[6]", 410, 6, SX_NONE),
    SX_FIELD("domain_flags", "uint8", 416, 1, SX_FLAGS),
    SX_FIELD("domain_identifier", "char[23]", 417, 23, SX_STRING),
    SX_FIELD("domain_suffix", "uint8[8]", 440, 8, SX_NONE),
    SX_FIELD("next_extent_length_flags", "uint32", 448, 4, SX_FLAGS),
    SX_FIELD("next_logical_block", "uint32", 452, 4, SX_NONE),
    SX_FIELD("next_partition_reference", "uint16", 456, 2, SX_NONE),
    SX_FIELD("next_implementation_use", "uint8[6]", 458, 6, SX_NONE),
    SX_FIELD("system_stream_directory_extent_length_flags", "uint32", 464, 4, SX_FLAGS),
    SX_FIELD("system_stream_directory_logical_block", "uint32", 468, 4, SX_NONE),
    SX_FIELD("system_stream_directory_partition_reference", "uint16", 472, 2, SX_NONE),
    SX_FIELD("system_stream_directory_implementation_use", "uint8[6]", 474, 6, SX_NONE),
    SX_FIELD("reserved", "bytes", 480, 32, SX_RESERVED),
};
const sx_layout sxo_udf_file_set_descriptor = {UINT32_C(0x60130013),"udf_file_set_descriptor",sxo_udf_file_set_descriptor_fields,SX_COUNT(sxo_udf_file_set_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_file_entry_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("prior_recorded_direct_entries", "uint32", 16, 4, SX_NONE),
    SX_FIELD("strategy_type", "uint16", 20, 2, SX_ID),
    SX_FIELD("strategy_parameter", "uint16", 22, 2, SX_NONE),
    SX_FIELD("maximum_entries", "uint16", 24, 2, SX_COUNT_PROP),
    SX_FIELD("reserved_icb", "uint8", 26, 1, SX_RESERVED),
    SX_FIELD("file_type", "uint8", 27, 1, SX_ID),
    SX_FIELD("parent_icb_block", "uint32", 28, 4, SX_NONE),
    SX_FIELD("parent_icb_partition", "uint16", 32, 2, SX_NONE),
    SX_FIELD("icb_flags", "uint16", 34, 2, SX_FLAGS),
    SX_FIELD("uid", "uint32", 36, 4, SX_NONE),
    SX_FIELD("gid", "uint32", 40, 4, SX_NONE),
    SX_FIELD("permissions", "uint32", 44, 4, SX_FLAGS),
    SX_FIELD("link_count", "uint16", 48, 2, SX_COUNT_PROP),
    SX_FIELD("record_format", "uint8", 50, 1, SX_ID),
    SX_FIELD("record_display_attributes", "uint8", 51, 1, SX_FLAGS),
    SX_FIELD("record_length", "uint32", 52, 4, SX_SIZE),
    SX_FIELD("information_length", "uint64", 56, 8, SX_SIZE),
    SX_FIELD("logical_blocks_recorded", "uint64", 64, 8, SX_COUNT_PROP),
    SX_FIELD("access_type_timezone", "uint16", 72, 2, SX_FLAGS),
    SX_FIELD("access_year", "uint16", 74, 2, SX_NONE),
    SX_FIELD("access_month", "uint8", 76, 1, SX_NONE),
    SX_FIELD("access_day", "uint8", 77, 1, SX_NONE),
    SX_FIELD("access_hour", "uint8", 78, 1, SX_NONE),
    SX_FIELD("access_minute", "uint8", 79, 1, SX_NONE),
    SX_FIELD("access_second", "uint8", 80, 1, SX_NONE),
    SX_FIELD("access_centiseconds", "uint8", 81, 1, SX_NONE),
    SX_FIELD("access_hundreds_microseconds", "uint8", 82, 1, SX_NONE),
    SX_FIELD("access_microseconds", "uint8", 83, 1, SX_NONE),
    SX_FIELD("modification_type_timezone", "uint16", 84, 2, SX_FLAGS),
    SX_FIELD("modification_year", "uint16", 86, 2, SX_NONE),
    SX_FIELD("modification_month", "uint8", 88, 1, SX_NONE),
    SX_FIELD("modification_day", "uint8", 89, 1, SX_NONE),
    SX_FIELD("modification_hour", "uint8", 90, 1, SX_NONE),
    SX_FIELD("modification_minute", "uint8", 91, 1, SX_NONE),
    SX_FIELD("modification_second", "uint8", 92, 1, SX_NONE),
    SX_FIELD("modification_centiseconds", "uint8", 93, 1, SX_NONE),
    SX_FIELD("modification_hundreds_microseconds", "uint8", 94, 1, SX_NONE),
    SX_FIELD("modification_microseconds", "uint8", 95, 1, SX_NONE),
    SX_FIELD("attribute_type_timezone", "uint16", 96, 2, SX_FLAGS),
    SX_FIELD("attribute_year", "uint16", 98, 2, SX_NONE),
    SX_FIELD("attribute_month", "uint8", 100, 1, SX_NONE),
    SX_FIELD("attribute_day", "uint8", 101, 1, SX_NONE),
    SX_FIELD("attribute_hour", "uint8", 102, 1, SX_NONE),
    SX_FIELD("attribute_minute", "uint8", 103, 1, SX_NONE),
    SX_FIELD("attribute_second", "uint8", 104, 1, SX_NONE),
    SX_FIELD("attribute_centiseconds", "uint8", 105, 1, SX_NONE),
    SX_FIELD("attribute_hundreds_microseconds", "uint8", 106, 1, SX_NONE),
    SX_FIELD("attribute_microseconds", "uint8", 107, 1, SX_NONE),
    SX_FIELD("checkpoint", "uint32", 108, 4, SX_NONE),
    SX_FIELD("extended_attributes_extent_length_flags", "uint32", 112, 4, SX_FLAGS),
    SX_FIELD("extended_attributes_logical_block", "uint32", 116, 4, SX_NONE),
    SX_FIELD("extended_attributes_partition_reference", "uint16", 120, 2, SX_NONE),
    SX_FIELD("extended_attributes_implementation_use", "uint8[6]", 122, 6, SX_NONE),
    SX_FIELD("implementation_flags", "uint8", 128, 1, SX_FLAGS),
    SX_FIELD("implementation_identifier", "char[23]", 129, 23, SX_STRING),
    SX_FIELD("implementation_suffix", "uint8[8]", 152, 8, SX_NONE),
    SX_FIELD("unique_id", "uint64", 160, 8, SX_ID),
    SX_FIELD("extended_attributes_length", "uint32", 168, 4, SX_SIZE),
    SX_FIELD("allocation_descriptors_length", "uint32", 172, 4, SX_SIZE),
};
const sx_layout sxo_udf_file_entry = {UINT32_C(0x60130014),"udf_file_entry",sxo_udf_file_entry_fields,SX_COUNT(sxo_udf_file_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_extended_file_entry_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("prior_recorded_direct_entries", "uint32", 16, 4, SX_NONE),
    SX_FIELD("strategy_type", "uint16", 20, 2, SX_ID),
    SX_FIELD("strategy_parameter", "uint16", 22, 2, SX_NONE),
    SX_FIELD("maximum_entries", "uint16", 24, 2, SX_COUNT_PROP),
    SX_FIELD("reserved_icb", "uint8", 26, 1, SX_RESERVED),
    SX_FIELD("file_type", "uint8", 27, 1, SX_ID),
    SX_FIELD("parent_icb_block", "uint32", 28, 4, SX_NONE),
    SX_FIELD("parent_icb_partition", "uint16", 32, 2, SX_NONE),
    SX_FIELD("icb_flags", "uint16", 34, 2, SX_FLAGS),
    SX_FIELD("uid", "uint32", 36, 4, SX_NONE),
    SX_FIELD("gid", "uint32", 40, 4, SX_NONE),
    SX_FIELD("permissions", "uint32", 44, 4, SX_FLAGS),
    SX_FIELD("link_count", "uint16", 48, 2, SX_COUNT_PROP),
    SX_FIELD("record_format", "uint8", 50, 1, SX_ID),
    SX_FIELD("record_display_attributes", "uint8", 51, 1, SX_FLAGS),
    SX_FIELD("record_length", "uint32", 52, 4, SX_SIZE),
    SX_FIELD("information_length", "uint64", 56, 8, SX_SIZE),
    SX_FIELD("object_size", "uint64", 64, 8, SX_SIZE),
    SX_FIELD("logical_blocks_recorded", "uint64", 72, 8, SX_COUNT_PROP),
    SX_FIELD("access_type_timezone", "uint16", 80, 2, SX_FLAGS),
    SX_FIELD("access_year", "uint16", 82, 2, SX_NONE),
    SX_FIELD("access_month", "uint8", 84, 1, SX_NONE),
    SX_FIELD("access_day", "uint8", 85, 1, SX_NONE),
    SX_FIELD("access_hour", "uint8", 86, 1, SX_NONE),
    SX_FIELD("access_minute", "uint8", 87, 1, SX_NONE),
    SX_FIELD("access_second", "uint8", 88, 1, SX_NONE),
    SX_FIELD("access_centiseconds", "uint8", 89, 1, SX_NONE),
    SX_FIELD("access_hundreds_microseconds", "uint8", 90, 1, SX_NONE),
    SX_FIELD("access_microseconds", "uint8", 91, 1, SX_NONE),
    SX_FIELD("modification_type_timezone", "uint16", 92, 2, SX_FLAGS),
    SX_FIELD("modification_year", "uint16", 94, 2, SX_NONE),
    SX_FIELD("modification_month", "uint8", 96, 1, SX_NONE),
    SX_FIELD("modification_day", "uint8", 97, 1, SX_NONE),
    SX_FIELD("modification_hour", "uint8", 98, 1, SX_NONE),
    SX_FIELD("modification_minute", "uint8", 99, 1, SX_NONE),
    SX_FIELD("modification_second", "uint8", 100, 1, SX_NONE),
    SX_FIELD("modification_centiseconds", "uint8", 101, 1, SX_NONE),
    SX_FIELD("modification_hundreds_microseconds", "uint8", 102, 1, SX_NONE),
    SX_FIELD("modification_microseconds", "uint8", 103, 1, SX_NONE),
    SX_FIELD("creation_type_timezone", "uint16", 104, 2, SX_FLAGS),
    SX_FIELD("creation_year", "uint16", 106, 2, SX_NONE),
    SX_FIELD("creation_month", "uint8", 108, 1, SX_NONE),
    SX_FIELD("creation_day", "uint8", 109, 1, SX_NONE),
    SX_FIELD("creation_hour", "uint8", 110, 1, SX_NONE),
    SX_FIELD("creation_minute", "uint8", 111, 1, SX_NONE),
    SX_FIELD("creation_second", "uint8", 112, 1, SX_NONE),
    SX_FIELD("creation_centiseconds", "uint8", 113, 1, SX_NONE),
    SX_FIELD("creation_hundreds_microseconds", "uint8", 114, 1, SX_NONE),
    SX_FIELD("creation_microseconds", "uint8", 115, 1, SX_NONE),
    SX_FIELD("attribute_type_timezone", "uint16", 116, 2, SX_FLAGS),
    SX_FIELD("attribute_year", "uint16", 118, 2, SX_NONE),
    SX_FIELD("attribute_month", "uint8", 120, 1, SX_NONE),
    SX_FIELD("attribute_day", "uint8", 121, 1, SX_NONE),
    SX_FIELD("attribute_hour", "uint8", 122, 1, SX_NONE),
    SX_FIELD("attribute_minute", "uint8", 123, 1, SX_NONE),
    SX_FIELD("attribute_second", "uint8", 124, 1, SX_NONE),
    SX_FIELD("attribute_centiseconds", "uint8", 125, 1, SX_NONE),
    SX_FIELD("attribute_hundreds_microseconds", "uint8", 126, 1, SX_NONE),
    SX_FIELD("attribute_microseconds", "uint8", 127, 1, SX_NONE),
    SX_FIELD("checkpoint", "uint32", 128, 4, SX_NONE),
    SX_FIELD("reserved", "uint32", 132, 4, SX_RESERVED),
    SX_FIELD("extended_attributes_extent_length_flags", "uint32", 136, 4, SX_FLAGS),
    SX_FIELD("extended_attributes_logical_block", "uint32", 140, 4, SX_NONE),
    SX_FIELD("extended_attributes_partition_reference", "uint16", 144, 2, SX_NONE),
    SX_FIELD("extended_attributes_implementation_use", "uint8[6]", 146, 6, SX_NONE),
    SX_FIELD("stream_directory_extent_length_flags", "uint32", 152, 4, SX_FLAGS),
    SX_FIELD("stream_directory_logical_block", "uint32", 156, 4, SX_NONE),
    SX_FIELD("stream_directory_partition_reference", "uint16", 160, 2, SX_NONE),
    SX_FIELD("stream_directory_implementation_use", "uint8[6]", 162, 6, SX_NONE),
    SX_FIELD("implementation_flags", "uint8", 168, 1, SX_FLAGS),
    SX_FIELD("implementation_identifier", "char[23]", 169, 23, SX_STRING),
    SX_FIELD("implementation_suffix", "uint8[8]", 192, 8, SX_NONE),
    SX_FIELD("unique_id", "uint64", 200, 8, SX_ID),
    SX_FIELD("extended_attributes_length", "uint32", 208, 4, SX_SIZE),
    SX_FIELD("allocation_descriptors_length", "uint32", 212, 4, SX_SIZE),
};
const sx_layout sxo_udf_extended_file_entry = {UINT32_C(0x60130015),"udf_extended_file_entry",sxo_udf_extended_file_entry_fields,SX_COUNT(sxo_udf_extended_file_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_file_identifier_descriptor_fields[] = {
    SX_FIELD("tag_identifier", "uint16", 0, 2, SX_ID),
    SX_FIELD("descriptor_version", "uint16", 2, 2, SX_ID),
    SX_FIELD("tag_checksum", "uint8", 4, 1, SX_CHECKSUM),
    SX_FIELD("reserved_tag", "uint8", 5, 1, SX_RESERVED),
    SX_FIELD("tag_serial", "uint16", 6, 2, SX_NONE),
    SX_FIELD("descriptor_crc", "uint16", 8, 2, SX_CHECKSUM),
    SX_FIELD("descriptor_crc_length", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("tag_location", "uint32", 12, 4, SX_NONE),
    SX_FIELD("file_version", "uint16", 16, 2, SX_NONE),
    SX_FIELD("file_characteristics", "uint8", 18, 1, SX_FLAGS),
    SX_FIELD("identifier_length", "uint8", 19, 1, SX_SIZE),
    SX_FIELD("icb_extent_length_flags", "uint32", 20, 4, SX_FLAGS),
    SX_FIELD("icb_logical_block", "uint32", 24, 4, SX_NONE),
    SX_FIELD("icb_partition_reference", "uint16", 28, 2, SX_NONE),
    SX_FIELD("icb_implementation_use", "uint8[6]", 30, 6, SX_NONE),
    SX_FIELD("implementation_use_length", "uint16", 36, 2, SX_SIZE),
};
const sx_layout sxo_udf_file_identifier_descriptor = {UINT32_C(0x60130016),"udf_file_identifier_descriptor",sxo_udf_file_identifier_descriptor_fields,SX_COUNT(sxo_udf_file_identifier_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_short_allocation_descriptor_fields[] = {
    SX_FIELD("extent_length_flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("logical_block", "uint32", 4, 4, SX_NONE),
};
const sx_layout sxo_udf_short_allocation_descriptor = {UINT32_C(0x60130017),"udf_short_allocation_descriptor",sxo_udf_short_allocation_descriptor_fields,SX_COUNT(sxo_udf_short_allocation_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_long_allocation_descriptor_fields[] = {
    SX_FIELD("extent_length_flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("logical_block", "uint32", 4, 4, SX_NONE),
    SX_FIELD("partition_reference", "uint16", 8, 2, SX_NONE),
    SX_FIELD("implementation_use", "uint8[6]", 10, 6, SX_NONE),
};
const sx_layout sxo_udf_long_allocation_descriptor = {UINT32_C(0x60130018),"udf_long_allocation_descriptor",sxo_udf_long_allocation_descriptor_fields,SX_COUNT(sxo_udf_long_allocation_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxo_udf_extended_allocation_descriptor_fields[] = {
    SX_FIELD("extent_length_flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("recorded_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("information_length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("logical_block", "uint32", 12, 4, SX_NONE),
    SX_FIELD("partition_reference", "uint16", 16, 2, SX_NONE),
    SX_FIELD("reserved", "uint16", 18, 2, SX_RESERVED),
};
const sx_layout sxo_udf_extended_allocation_descriptor = {UINT32_C(0x60130019),"udf_extended_allocation_descriptor",sxo_udf_extended_allocation_descriptor_fields,SX_COUNT(sxo_udf_extended_allocation_descriptor_fields),SX_LE};
/* Verify the actual tag checksum and optional ECMA-167 descriptor CRC before
 * classifying any UDF object. Invalid alternate copies remain raw bytes. */
static bool sxo_udf_tag(sx_context *c,int64_t at,uint16_t expected,uint8_t out[2048])
{
    if(!sxo_can(c,at,16)||!sx_read(c,at,out,16))return false;
    uint16_t id=sxo_u16(out),version=sxo_u16(out+2),n=sxo_u16(out+10),crc=0;unsigned sum=0;
    if((expected&&id!=expected)||(version!=2&&version!=3)||out[5]||n>2032||!sxo_can(c,at,16U+n))return false;
    for(unsigned i=0;i<16;i++)if(i!=4)sum+=out[i];if((uint8_t)sum!=out[4])return false;
    if(n){if(!sx_read(c,at+16,out+16,n))return false;for(unsigned i=0;i<n;i++){crc^=(uint16_t)out[16+i]<<8;for(unsigned k=0;k<8;k++)crc=(uint16_t)((crc<<1)^((crc&0x8000)?0x1021:0));}if(crc!=sxo_u16(out+8))return false;}
    return true;
}
typedef struct sxo_udf_partition {uint16_t number;uint32_t start,length;} sxo_udf_partition;
typedef struct sxo_udf_state {sxo_udf_partition part[16];size_t part_count;uint16_t maps[16];bool map_valid[16];size_t map_count;uint32_t fsd_block;uint16_t fsd_partition;bool lvd;} sxo_udf_state;
static bool sxo_udf_lba(sx_context *c,sxo_udf_state *u,uint16_t ref,uint32_t lba,int64_t *at)
{
    uint16_t number;if(!u->part_count)return false;
    if(!u->map_count){if(u->part_count!=1)return false;number=u->part[0].number;}else{if(ref>=u->map_count||!u->map_valid[ref])return false;number=u->maps[ref];}
    for(size_t i=0;i<u->part_count;i++)if(u->part[i].number==number&&lba<u->part[i].length){uint64_t off=((uint64_t)u->part[i].start+lba)*2048;if(off>INT64_MAX||!sxo_can(c,(int64_t)off,2048))return false;*at=(int64_t)off;return true;}return false;
}
static bool sxo_udf_vds(sx_context *c,int64_t start,uint32_t size,sxo_udf_state *u)
{
    uint8_t b[2048];uint32_t count=size/2048;if(count>256)count=256;
    for(uint32_t i=0;i<count;i++){
        int64_t at=start+(int64_t)i*2048;const sx_layout *l=&sxo_udf_descriptor_tag;int n=16;
        if(!sxo_can(c,at,2048)||!sxo_udf_tag(c,at,0,b))break;if(!sx_read(c,at,b,2048))return false;uint16_t id=sxo_u16(b);
        if(id==1){l=&sxo_udf_primary_volume_descriptor;n=512;}
        else if(id==5){l=&sxo_udf_partition_descriptor;n=512;if(u&&u->part_count<16&&sxo_u32(b+192)){bool seen=false;for(size_t j=0;j<u->part_count;j++)if(u->part[j].number==sxo_u16(b+22))seen=true;if(!seen)u->part[u->part_count++]=(sxo_udf_partition){sxo_u16(b+22),sxo_u32(b+188),sxo_u32(b+192)};}}
        else if(id==6){
            l=&sxo_udf_logical_volume_descriptor;n=440;uint32_t bytes=sxo_u32(b+264),maps=sxo_u32(b+268),pos=440;
            if(bytes>1608)return false;if(maps>16)maps=16;
            for(uint32_t j=0;j<maps&&pos+2<=440+bytes;j++){
                uint8_t type=b[pos],len=b[pos+1];if(len<2||len>440+bytes-pos)break;
                if(!sxo_add(c,type==1&&len>=6?&sxo_udf_partition_map_type1:&sxo_udf_partition_map_header,at+pos,type==1&&len>=6?6:2))return false;
                if(u&&!u->lvd){u->map_valid[j]=type==1&&len>=6;if(u->map_valid[j])u->maps[j]=sxo_u16(b+pos+4);u->map_count=j+1;}pos+=len;
            }
            if(u&&!u->lvd&&sxo_u32(b+212)==2048&&sxo_u32(b+248)){u->fsd_block=sxo_u32(b+252);u->fsd_partition=sxo_u16(b+256);u->lvd=true;}
        }else if(id==8){l=&sxo_udf_terminating_descriptor;n=512;}
        if(!sxo_add(c,l,at,n))return false;if(id==8)break;
    }return true;
}
typedef struct sxo_udf_work {int64_t offset;uint16_t partition;unsigned depth;} sxo_udf_work;
static bool sxo_udf_files(sx_context *c,sxo_udf_state *u,int64_t root,uint16_t home)
{
    uint8_t b[2048],fid[2048];sxo_udf_work *work=xx_mem_alloc(8192*sizeof(*work));size_t count=1;bool ok=false;if(!work)return false;work[0]=(sxo_udf_work){root,home,0};
    for(size_t q=0;q<count;q++){
        int64_t at=work[q].offset,data=-1,expected=-1;uint64_t available=0,info;unsigned fixed,mode;uint32_t ea,ad;uint16_t id;
        if(work[q].depth>64||xx_pd_is_stopped(c->pd))goto done;
        if(!sxo_can(c,at,2048)||!sxo_udf_tag(c,at,0,b))continue;id=sxo_u16(b);if(id!=261&&id!=266)continue;if(!sx_read(c,at,b,2048))goto done;
        fixed=id==261?176:216;ea=sxo_u32(b+fixed-8);ad=sxo_u32(b+fixed-4);if((uint64_t)ea+ad>2048-fixed)continue;
        if(!sxo_add(c,id==261?&sxo_udf_file_entry:&sxo_udf_extended_file_entry,at,fixed))goto done;
        mode=sxo_u16(b+34)&7;info=xx_data_get_u64(b+56,8,0,false);
        if(mode<3){unsigned width=mode==0?8:mode==1?16:20;const sx_layout *l=mode==0?&sxo_udf_short_allocation_descriptor:mode==1?&sxo_udf_long_allocation_descriptor:&sxo_udf_extended_allocation_descriptor;
            if(ad%width)continue;bool resolved=mode!=2;
            for(uint32_t j=0;j<ad;j+=width){const uint8_t *p=b+fixed+ea+j;uint32_t length=sxo_u32(p);int64_t pos;
                if(!sxo_add(c,l,at+fixed+ea+j,width))goto done;
                if(mode==2||length>>30||!sxo_udf_lba(c,u,mode==0?work[q].partition:sxo_u16(p+8),sxo_u32(p+4),&pos)||!sxo_can(c,pos,length&0x3fffffff))resolved=false;
                else{if(data<0)data=pos;else if(expected!=pos)resolved=false;expected=pos+(length&0x3fffffff);available+=length&0x3fffffff;}
            }
            if(!resolved)data=-1;
        }else if(mode==3){data=at+fixed+ea;available=ad;}
        if(b[27]!=4||data<0||info>available||info>67108864)continue;
        int64_t pos=data,end=data+(int64_t)info;
        while(end-pos>=38){
            if(!sxo_udf_tag(c,pos,257,fid)||!sx_read(c,pos,fid,38))break;
            uint32_t n=38U+sxo_u16(fid+36)+fid[19],padded=(n+3)&~3U;if(padded>(uint64_t)(end-pos))break;
            if(!sxo_add(c,&sxo_udf_file_identifier_descriptor,pos,38))goto done;
            if(!(fid[18]&12)&&fid[19]&&sxo_u32(fid+20)){
                int64_t child;uint16_t ref=sxo_u16(fid+28);if(sxo_udf_lba(c,u,ref,sxo_u32(fid+24),&child)){
                    bool seen=false;for(size_t j=0;j<count;j++)if(work[j].offset==child)seen=true;
                    if(!seen){if(count>=8192)goto done;work[count++]=(sxo_udf_work){child,ref,work[q].depth+1};}
                }
            }pos+=padded;
        }
    }ok=true;
done:xx_mem_free(work);return ok;
}
static bool sxo_udf_build(sx_context *c)
{
    uint8_t b[2048];int64_t last=c->size/2048-1,candidates[4]={256,last,last-256,512},selected=-1;uint32_t vds_size=0;int64_t vds_at=0;bool vrs=false,extended_area=false;sxo_udf_state u;xx_rt_memset(&u,0,sizeof(u));
    for(unsigned i=0;i<64;i++){int64_t at=(int64_t)(16+i)*2048;if(!sxo_can(c,at,2048)||!sx_read(c,at,b,7))break;
        bool bea=!xx_rt_memcmp(b+1,"BEA01",5),nsr=!xx_rt_memcmp(b+1,"NSR02",5)||!xx_rt_memcmp(b+1,"NSR03",5),tea=!xx_rt_memcmp(b+1,"TEA01",5),iso=!xx_rt_memcmp(b+1,"CD001",5);
        bool known=bea||nsr||tea||iso||!xx_rt_memcmp(b+1,"CDW02",5)||!xx_rt_memcmp(b+1,"BOOT2",5);if(!known)break;
        if(!sxo_add(c,iso?&sxo_iso_volume_descriptor_header:&sxo_udf_volume_recognition_descriptor,at,7))return false;
        if(bea)extended_area=true;if(nsr&&extended_area)vrs=true;if(tea)break;
    }
    for(unsigned pass=0;pass<2&&selected<0;pass++){
        if(pass&&!vrs)break;
        for(unsigned i=0;i<4;i++){if(candidates[i]<0)continue;int64_t at=candidates[i]*2048;
            if(!sxo_can(c,at,2048)||!sxo_udf_tag(c,at,2,b)||!sx_read(c,at,b,512))continue;
            uint32_t size=sxo_u32(b+16),block=sxo_u32(b+20);if(!size||size%2048||!block||!sxo_can(c,(int64_t)block*2048,2048)||(!pass&&sxo_u32(b+12)!=(uint64_t)candidates[i]))continue;
            selected=at;vds_size=size;vds_at=(int64_t)block*2048;break;
        }
    }
    if(selected<0)return false;
    if(!sxo_udf_vds(c,vds_at,vds_size,&u)||!u.lvd||!u.part_count)return false;
    for(unsigned i=0;i<4;i++){if(candidates[i]<0)continue;int64_t at=candidates[i]*2048;
        if(!sxo_can(c,at,2048)||!sxo_udf_tag(c,at,2,b)||!sx_read(c,at,b,512))continue;
        if(at!=selected&&sxo_u32(b+12)!=(uint64_t)candidates[i])continue;
        if(!sxo_add(c,&sxo_udf_anchor_volume_descriptor,at,512))return false;
        /* Reserve sequence descriptors are physical metadata, never a source
         * of partition mappings when the native reader selected the main set. */
        for(unsigned j=0;j<2;j++){uint32_t size=sxo_u32(b+16+j*8),block=sxo_u32(b+20+j*8);if(size&&!(size%2048)&&size<=256*2048&&block&&sxo_can(c,(int64_t)block*2048,size)){
                size_t saved=c->count;if(!sxo_udf_vds(c,(int64_t)block*2048,size,NULL)){if(c->failed||xx_pd_is_stopped(c->pd))return false;c->count=saved;}
            }}
    }
    int64_t fsd,root;if(!sxo_udf_lba(c,&u,u.fsd_partition,u.fsd_block,&fsd)||!sxo_udf_tag(c,fsd,256,b)||!sx_read(c,fsd,b,512)||!sxo_add(c,&sxo_udf_file_set_descriptor,fsd,512)||!sxo_u32(b+400)||!sxo_udf_lba(c,&u,sxo_u16(b+408),sxo_u32(b+404),&root))return false;
    return sxo_udf_files(c,&u,root,sxo_u16(b+408));
}
bool sx_udf_build(sx_context*c)
{
 return sxo_udf_build(c);
}
