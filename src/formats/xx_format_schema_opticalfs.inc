/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ISO9660 ECMA-119 and UDF ECMA-167 physical metadata.
 * Logical block numbers retain their physical units. */
static const xx_data_struct_field_desc sxo_iso_directory_record_fields[] = {
    SX_FIELD("record_length", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("extended_attribute_blocks", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("extent_lba_le", "uint32", 2, 4, SX_NONE),
    SX_FIELD("extent_lba_be", "uint32be", 6, 4, SX_NONE),
    SX_FIELD("data_length_le", "uint32", 10, 4, SX_SIZE),
    SX_FIELD("data_length_be", "uint32be", 14, 4, SX_SIZE),
    SX_FIELD("recorded_year_since_1900", "uint8", 18, 1, SX_NONE),
    SX_FIELD("recorded_month", "uint8", 19, 1, SX_NONE),
    SX_FIELD("recorded_day", "uint8", 20, 1, SX_NONE),
    SX_FIELD("recorded_hour", "uint8", 21, 1, SX_NONE),
    SX_FIELD("recorded_minute", "uint8", 22, 1, SX_NONE),
    SX_FIELD("recorded_second", "uint8", 23, 1, SX_NONE),
    SX_FIELD("recorded_timezone_quarters", "int8", 24, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 25, 1, SX_FLAGS),
    SX_FIELD("file_unit_blocks", "uint8", 26, 1, SX_COUNT_PROP),
    SX_FIELD("interleave_gap_blocks", "uint8", 27, 1, SX_COUNT_PROP),
    SX_FIELD("volume_sequence_le", "uint16", 28, 2, SX_NONE),
    SX_FIELD("volume_sequence_be", "uint16be", 30, 2, SX_NONE),
    SX_FIELD("identifier_length", "uint8", 32, 1, SX_SIZE),
};
static const sx_layout sxo_iso_directory_record = {UINT32_C(0x60130001),"iso_directory_record",sxo_iso_directory_record_fields,SX_COUNT(sxo_iso_directory_record_fields),SX_LE};

static const xx_data_struct_field_desc sxo_iso_path_table_l_fields[] = {
    SX_FIELD("identifier_length", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("extended_attribute_blocks", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("extent_lba", "uint32", 2, 4, SX_NONE),
    SX_FIELD("parent_directory_number", "uint16", 6, 2, SX_NONE),
};
static const sx_layout sxo_iso_path_table_l = {UINT32_C(0x60130002),"iso_path_table_l",sxo_iso_path_table_l_fields,SX_COUNT(sxo_iso_path_table_l_fields),SX_LE};

static const xx_data_struct_field_desc sxo_iso_path_table_m_fields[] = {
    SX_FIELD("identifier_length", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("extended_attribute_blocks", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("extent_lba", "uint32", 2, 4, SX_NONE),
    SX_FIELD("parent_directory_number", "uint16", 6, 2, SX_NONE),
};
static const sx_layout sxo_iso_path_table_m = {UINT32_C(0x60130003),"iso_path_table_m",sxo_iso_path_table_m_fields,SX_COUNT(sxo_iso_path_table_m_fields),SX_BE};

static const xx_data_struct_field_desc sxo_iso_primary_volume_descriptor_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved_flags", "uint8", 7, 1, SX_RESERVED),
    SX_FIELD("system_identifier", "char[32]", 8, 32, SX_STRING),
    SX_FIELD("volume_identifier", "char[32]", 40, 32, SX_STRING),
    SX_FIELD("reserved0", "bytes", 72, 8, SX_RESERVED),
    SX_FIELD("volume_blocks_le", "uint32", 80, 4, SX_COUNT_PROP),
    SX_FIELD("volume_blocks_be", "uint32be", 84, 4, SX_COUNT_PROP),
    SX_FIELD("reserved_escape_sequences", "bytes", 88, 32, SX_RESERVED),
    SX_FIELD("volume_set_size_le", "uint16", 120, 2, SX_COUNT_PROP),
    SX_FIELD("volume_set_size_be", "uint16be", 122, 2, SX_COUNT_PROP),
    SX_FIELD("volume_sequence_le", "uint16", 124, 2, SX_NONE),
    SX_FIELD("volume_sequence_be", "uint16be", 126, 2, SX_NONE),
    SX_FIELD("logical_block_size_le", "uint16", 128, 2, SX_SIZE),
    SX_FIELD("logical_block_size_be", "uint16be", 130, 2, SX_SIZE),
    SX_FIELD("path_table_size_le", "uint32", 132, 4, SX_SIZE),
    SX_FIELD("path_table_size_be", "uint32be", 136, 4, SX_SIZE),
    SX_FIELD("l_path_table_lba", "uint32", 140, 4, SX_NONE),
    SX_FIELD("l_optional_path_table_lba", "uint32", 144, 4, SX_NONE),
    SX_FIELD("m_path_table_lba", "uint32be", 148, 4, SX_NONE),
    SX_FIELD("m_optional_path_table_lba", "uint32be", 152, 4, SX_NONE),
    SX_FIELD("root_record_length", "uint8", 156, 1, SX_SIZE),
    SX_FIELD("root_extended_attribute_blocks", "uint8", 157, 1, SX_COUNT_PROP),
    SX_FIELD("root_extent_lba_le", "uint32", 158, 4, SX_NONE),
    SX_FIELD("root_extent_lba_be", "uint32be", 162, 4, SX_NONE),
    SX_FIELD("root_data_length_le", "uint32", 166, 4, SX_SIZE),
    SX_FIELD("root_data_length_be", "uint32be", 170, 4, SX_SIZE),
    SX_FIELD("root_recorded_year_since_1900", "uint8", 174, 1, SX_NONE),
    SX_FIELD("root_recorded_month", "uint8", 175, 1, SX_NONE),
    SX_FIELD("root_recorded_day", "uint8", 176, 1, SX_NONE),
    SX_FIELD("root_recorded_hour", "uint8", 177, 1, SX_NONE),
    SX_FIELD("root_recorded_minute", "uint8", 178, 1, SX_NONE),
    SX_FIELD("root_recorded_second", "uint8", 179, 1, SX_NONE),
    SX_FIELD("root_recorded_timezone_quarters", "int8", 180, 1, SX_NONE),
    SX_FIELD("root_flags", "uint8", 181, 1, SX_FLAGS),
    SX_FIELD("root_file_unit_blocks", "uint8", 182, 1, SX_COUNT_PROP),
    SX_FIELD("root_interleave_gap_blocks", "uint8", 183, 1, SX_COUNT_PROP),
    SX_FIELD("root_volume_sequence_le", "uint16", 184, 2, SX_NONE),
    SX_FIELD("root_volume_sequence_be", "uint16be", 186, 2, SX_NONE),
    SX_FIELD("root_identifier_length", "uint8", 188, 1, SX_SIZE),
    SX_FIELD("root_identifier", "uint8", 189, 1, SX_NONE),
    SX_FIELD("volume_set_identifier", "char[128]", 190, 128, SX_STRING),
    SX_FIELD("publisher_identifier", "char[128]", 318, 128, SX_STRING),
    SX_FIELD("data_preparer_identifier", "char[128]", 446, 128, SX_STRING),
    SX_FIELD("application_identifier", "char[128]", 574, 128, SX_STRING),
    SX_FIELD("copyright_file_identifier", "char[37]", 702, 37, SX_STRING),
    SX_FIELD("abstract_file_identifier", "char[37]", 739, 37, SX_STRING),
    SX_FIELD("bibliographic_file_identifier", "char[37]", 776, 37, SX_STRING),
    SX_FIELD("creation_datetime_digits", "char[16]", 813, 16, SX_NONE),
    SX_FIELD("creation_timezone_quarters", "int8", 829, 1, SX_NONE),
    SX_FIELD("modification_datetime_digits", "char[16]", 830, 16, SX_NONE),
    SX_FIELD("modification_timezone_quarters", "int8", 846, 1, SX_NONE),
    SX_FIELD("expiration_datetime_digits", "char[16]", 847, 16, SX_NONE),
    SX_FIELD("expiration_timezone_quarters", "int8", 863, 1, SX_NONE),
    SX_FIELD("effective_datetime_digits", "char[16]", 864, 16, SX_NONE),
    SX_FIELD("effective_timezone_quarters", "int8", 880, 1, SX_NONE),
    SX_FIELD("file_structure_version", "uint8", 881, 1, SX_ID),
    SX_FIELD("reserved1", "uint8", 882, 1, SX_RESERVED),
    SX_FIELD("application_use", "bytes", 883, 512, SX_NONE),
    SX_FIELD("reserved2", "bytes", 1395, 653, SX_RESERVED),
};
static const sx_layout sxo_iso_primary_volume_descriptor = {UINT32_C(0x60130004),"iso_primary_volume_descriptor",sxo_iso_primary_volume_descriptor_fields,SX_COUNT(sxo_iso_primary_volume_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxo_iso_supplementary_volume_descriptor_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("volume_flags", "uint8", 7, 1, SX_FLAGS),
    SX_FIELD("system_identifier", "uint8[32]", 8, 32, SX_NONE),
    SX_FIELD("volume_identifier", "uint8[32]", 40, 32, SX_NONE),
    SX_FIELD("reserved0", "bytes", 72, 8, SX_RESERVED),
    SX_FIELD("volume_blocks_le", "uint32", 80, 4, SX_COUNT_PROP),
    SX_FIELD("volume_blocks_be", "uint32be", 84, 4, SX_COUNT_PROP),
    SX_FIELD("escape_sequences", "bytes", 88, 32, SX_NONE),
    SX_FIELD("volume_set_size_le", "uint16", 120, 2, SX_COUNT_PROP),
    SX_FIELD("volume_set_size_be", "uint16be", 122, 2, SX_COUNT_PROP),
    SX_FIELD("volume_sequence_le", "uint16", 124, 2, SX_NONE),
    SX_FIELD("volume_sequence_be", "uint16be", 126, 2, SX_NONE),
    SX_FIELD("logical_block_size_le", "uint16", 128, 2, SX_SIZE),
    SX_FIELD("logical_block_size_be", "uint16be", 130, 2, SX_SIZE),
    SX_FIELD("path_table_size_le", "uint32", 132, 4, SX_SIZE),
    SX_FIELD("path_table_size_be", "uint32be", 136, 4, SX_SIZE),
    SX_FIELD("l_path_table_lba", "uint32", 140, 4, SX_NONE),
    SX_FIELD("l_optional_path_table_lba", "uint32", 144, 4, SX_NONE),
    SX_FIELD("m_path_table_lba", "uint32be", 148, 4, SX_NONE),
    SX_FIELD("m_optional_path_table_lba", "uint32be", 152, 4, SX_NONE),
    SX_FIELD("root_record_length", "uint8", 156, 1, SX_SIZE),
    SX_FIELD("root_extended_attribute_blocks", "uint8", 157, 1, SX_COUNT_PROP),
    SX_FIELD("root_extent_lba_le", "uint32", 158, 4, SX_NONE),
    SX_FIELD("root_extent_lba_be", "uint32be", 162, 4, SX_NONE),
    SX_FIELD("root_data_length_le", "uint32", 166, 4, SX_SIZE),
    SX_FIELD("root_data_length_be", "uint32be", 170, 4, SX_SIZE),
    SX_FIELD("root_recorded_year_since_1900", "uint8", 174, 1, SX_NONE),
    SX_FIELD("root_recorded_month", "uint8", 175, 1, SX_NONE),
    SX_FIELD("root_recorded_day", "uint8", 176, 1, SX_NONE),
    SX_FIELD("root_recorded_hour", "uint8", 177, 1, SX_NONE),
    SX_FIELD("root_recorded_minute", "uint8", 178, 1, SX_NONE),
    SX_FIELD("root_recorded_second", "uint8", 179, 1, SX_NONE),
    SX_FIELD("root_recorded_timezone_quarters", "int8", 180, 1, SX_NONE),
    SX_FIELD("root_flags", "uint8", 181, 1, SX_FLAGS),
    SX_FIELD("root_file_unit_blocks", "uint8", 182, 1, SX_COUNT_PROP),
    SX_FIELD("root_interleave_gap_blocks", "uint8", 183, 1, SX_COUNT_PROP),
    SX_FIELD("root_volume_sequence_le", "uint16", 184, 2, SX_NONE),
    SX_FIELD("root_volume_sequence_be", "uint16be", 186, 2, SX_NONE),
    SX_FIELD("root_identifier_length", "uint8", 188, 1, SX_SIZE),
    SX_FIELD("root_identifier", "uint8", 189, 1, SX_NONE),
    SX_FIELD("volume_set_identifier", "uint8[128]", 190, 128, SX_NONE),
    SX_FIELD("publisher_identifier", "uint8[128]", 318, 128, SX_NONE),
    SX_FIELD("data_preparer_identifier", "uint8[128]", 446, 128, SX_NONE),
    SX_FIELD("application_identifier", "uint8[128]", 574, 128, SX_NONE),
    SX_FIELD("copyright_file_identifier", "uint8[37]", 702, 37, SX_NONE),
    SX_FIELD("abstract_file_identifier", "uint8[37]", 739, 37, SX_NONE),
    SX_FIELD("bibliographic_file_identifier", "uint8[37]", 776, 37, SX_NONE),
    SX_FIELD("creation_datetime_digits", "char[16]", 813, 16, SX_NONE),
    SX_FIELD("creation_timezone_quarters", "int8", 829, 1, SX_NONE),
    SX_FIELD("modification_datetime_digits", "char[16]", 830, 16, SX_NONE),
    SX_FIELD("modification_timezone_quarters", "int8", 846, 1, SX_NONE),
    SX_FIELD("expiration_datetime_digits", "char[16]", 847, 16, SX_NONE),
    SX_FIELD("expiration_timezone_quarters", "int8", 863, 1, SX_NONE),
    SX_FIELD("effective_datetime_digits", "char[16]", 864, 16, SX_NONE),
    SX_FIELD("effective_timezone_quarters", "int8", 880, 1, SX_NONE),
    SX_FIELD("file_structure_version", "uint8", 881, 1, SX_ID),
    SX_FIELD("reserved1", "uint8", 882, 1, SX_RESERVED),
    SX_FIELD("application_use", "bytes", 883, 512, SX_NONE),
    SX_FIELD("reserved2", "bytes", 1395, 653, SX_RESERVED),
};
static const sx_layout sxo_iso_supplementary_volume_descriptor = {UINT32_C(0x60130005),"iso_supplementary_volume_descriptor",sxo_iso_supplementary_volume_descriptor_fields,SX_COUNT(sxo_iso_supplementary_volume_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxo_iso_boot_record_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("boot_system_identifier", "char[32]", 7, 32, SX_STRING),
    SX_FIELD("boot_identifier", "char[32]", 39, 32, SX_STRING),
    SX_FIELD("boot_system_use", "bytes", 71, 1977, SX_NONE),
};
static const sx_layout sxo_iso_boot_record = {UINT32_C(0x60130006),"iso_boot_record",sxo_iso_boot_record_fields,SX_COUNT(sxo_iso_boot_record_fields),SX_LE};

static const xx_data_struct_field_desc sxo_iso_volume_partition_descriptor_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 7, 1, SX_RESERVED),
    SX_FIELD("system_identifier", "char[32]", 8, 32, SX_STRING),
    SX_FIELD("partition_identifier", "char[32]", 40, 32, SX_STRING),
    SX_FIELD("partition_location_le", "uint32", 72, 4, SX_NONE),
    SX_FIELD("partition_location_be", "uint32be", 76, 4, SX_NONE),
    SX_FIELD("partition_blocks_le", "uint32", 80, 4, SX_COUNT_PROP),
    SX_FIELD("partition_blocks_be", "uint32be", 84, 4, SX_COUNT_PROP),
    SX_FIELD("system_use", "bytes", 88, 1960, SX_NONE),
};
static const sx_layout sxo_iso_volume_partition_descriptor = {UINT32_C(0x60130007),"iso_volume_partition_descriptor",sxo_iso_volume_partition_descriptor_fields,SX_COUNT(sxo_iso_volume_partition_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxo_iso_volume_descriptor_terminator_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved", "bytes", 7, 2041, SX_RESERVED),
};
static const sx_layout sxo_iso_volume_descriptor_terminator = {UINT32_C(0x60130008),"iso_volume_descriptor_terminator",sxo_iso_volume_descriptor_terminator_fields,SX_COUNT(sxo_iso_volume_descriptor_terminator_fields),SX_LE};

static const xx_data_struct_field_desc sxo_iso_volume_descriptor_header_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
};
static const sx_layout sxo_iso_volume_descriptor_header = {UINT32_C(0x60130009),"iso_volume_descriptor_header",sxo_iso_volume_descriptor_header_fields,SX_COUNT(sxo_iso_volume_descriptor_header_fields),SX_LE};

static const xx_data_struct_field_desc sxo_udf_volume_recognition_descriptor_fields[] = {
    SX_FIELD("structure_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("structure_version", "uint8", 6, 1, SX_ID),
};
static const sx_layout sxo_udf_volume_recognition_descriptor = {UINT32_C(0x6013000A),"udf_volume_recognition_descriptor",sxo_udf_volume_recognition_descriptor_fields,SX_COUNT(sxo_udf_volume_recognition_descriptor_fields),SX_LE};

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
static const sx_layout sxo_udf_descriptor_tag = {UINT32_C(0x6013000B),"udf_descriptor_tag",sxo_udf_descriptor_tag_fields,SX_COUNT(sxo_udf_descriptor_tag_fields),SX_LE};

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
static const sx_layout sxo_udf_anchor_volume_descriptor = {UINT32_C(0x6013000C),"udf_anchor_volume_descriptor",sxo_udf_anchor_volume_descriptor_fields,SX_COUNT(sxo_udf_anchor_volume_descriptor_fields),SX_LE};

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
static const sx_layout sxo_udf_primary_volume_descriptor = {UINT32_C(0x6013000D),"udf_primary_volume_descriptor",sxo_udf_primary_volume_descriptor_fields,SX_COUNT(sxo_udf_primary_volume_descriptor_fields),SX_LE};

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
static const sx_layout sxo_udf_partition_descriptor = {UINT32_C(0x6013000E),"udf_partition_descriptor",sxo_udf_partition_descriptor_fields,SX_COUNT(sxo_udf_partition_descriptor_fields),SX_LE};

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
static const sx_layout sxo_udf_logical_volume_descriptor = {UINT32_C(0x6013000F),"udf_logical_volume_descriptor",sxo_udf_logical_volume_descriptor_fields,SX_COUNT(sxo_udf_logical_volume_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxo_udf_partition_map_type1_fields[] = {
    SX_FIELD("map_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("map_length", "uint8", 1, 1, SX_SIZE),
    SX_FIELD("volume_sequence", "uint16", 2, 2, SX_NONE),
    SX_FIELD("partition_number", "uint16", 4, 2, SX_NONE),
};
static const sx_layout sxo_udf_partition_map_type1 = {UINT32_C(0x60130010),"udf_partition_map_type1",sxo_udf_partition_map_type1_fields,SX_COUNT(sxo_udf_partition_map_type1_fields),SX_LE};

static const xx_data_struct_field_desc sxo_udf_partition_map_header_fields[] = {
    SX_FIELD("map_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("map_length", "uint8", 1, 1, SX_SIZE),
};
static const sx_layout sxo_udf_partition_map_header = {UINT32_C(0x60130011),"udf_partition_map_header",sxo_udf_partition_map_header_fields,SX_COUNT(sxo_udf_partition_map_header_fields),SX_LE};

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
static const sx_layout sxo_udf_terminating_descriptor = {UINT32_C(0x60130012),"udf_terminating_descriptor",sxo_udf_terminating_descriptor_fields,SX_COUNT(sxo_udf_terminating_descriptor_fields),SX_LE};

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
static const sx_layout sxo_udf_file_set_descriptor = {UINT32_C(0x60130013),"udf_file_set_descriptor",sxo_udf_file_set_descriptor_fields,SX_COUNT(sxo_udf_file_set_descriptor_fields),SX_LE};

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
static const sx_layout sxo_udf_file_entry = {UINT32_C(0x60130014),"udf_file_entry",sxo_udf_file_entry_fields,SX_COUNT(sxo_udf_file_entry_fields),SX_LE};

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
static const sx_layout sxo_udf_extended_file_entry = {UINT32_C(0x60130015),"udf_extended_file_entry",sxo_udf_extended_file_entry_fields,SX_COUNT(sxo_udf_extended_file_entry_fields),SX_LE};

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
static const sx_layout sxo_udf_file_identifier_descriptor = {UINT32_C(0x60130016),"udf_file_identifier_descriptor",sxo_udf_file_identifier_descriptor_fields,SX_COUNT(sxo_udf_file_identifier_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxo_udf_short_allocation_descriptor_fields[] = {
    SX_FIELD("extent_length_flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("logical_block", "uint32", 4, 4, SX_NONE),
};
static const sx_layout sxo_udf_short_allocation_descriptor = {UINT32_C(0x60130017),"udf_short_allocation_descriptor",sxo_udf_short_allocation_descriptor_fields,SX_COUNT(sxo_udf_short_allocation_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxo_udf_long_allocation_descriptor_fields[] = {
    SX_FIELD("extent_length_flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("logical_block", "uint32", 4, 4, SX_NONE),
    SX_FIELD("partition_reference", "uint16", 8, 2, SX_NONE),
    SX_FIELD("implementation_use", "uint8[6]", 10, 6, SX_NONE),
};
static const sx_layout sxo_udf_long_allocation_descriptor = {UINT32_C(0x60130018),"udf_long_allocation_descriptor",sxo_udf_long_allocation_descriptor_fields,SX_COUNT(sxo_udf_long_allocation_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxo_udf_extended_allocation_descriptor_fields[] = {
    SX_FIELD("extent_length_flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("recorded_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("information_length", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("logical_block", "uint32", 12, 4, SX_NONE),
    SX_FIELD("partition_reference", "uint16", 16, 2, SX_NONE),
    SX_FIELD("reserved", "uint16", 18, 2, SX_RESERVED),
};
static const sx_layout sxo_udf_extended_allocation_descriptor = {UINT32_C(0x60130019),"udf_extended_allocation_descriptor",sxo_udf_extended_allocation_descriptor_fields,SX_COUNT(sxo_udf_extended_allocation_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxo_hfsplus_volume_header_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 2, 2, SX_ID),
    SX_FIELD("attributes", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("last_mounted_version", "uint32", 8, 4, SX_ID),
    SX_FIELD("journal_info_block", "uint32", 12, 4, SX_NONE),
    SX_FIELD("create_date", "uint32", 16, 4, SX_TIME),
    SX_FIELD("modify_date", "uint32", 20, 4, SX_TIME),
    SX_FIELD("backup_date", "uint32", 24, 4, SX_TIME),
    SX_FIELD("checked_date", "uint32", 28, 4, SX_TIME),
    SX_FIELD("file_count", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("folder_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("block_size", "uint32", 40, 4, SX_SIZE),
    SX_FIELD("total_blocks", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("free_blocks", "uint32", 48, 4, SX_COUNT_PROP),
    SX_FIELD("next_allocation_block", "uint32", 52, 4, SX_NONE),
    SX_FIELD("resource_clump_size", "uint32", 56, 4, SX_SIZE),
    SX_FIELD("data_clump_size", "uint32", 60, 4, SX_SIZE),
    SX_FIELD("next_catalog_id", "uint32", 64, 4, SX_ID),
    SX_FIELD("write_count", "uint32", 68, 4, SX_COUNT_PROP),
    SX_FIELD("encodings_bitmap", "uint64", 72, 8, SX_FLAGS),
    SX_FIELD("finder_info0", "uint32", 80, 4, SX_NONE),
    SX_FIELD("finder_info1", "uint32", 84, 4, SX_NONE),
    SX_FIELD("finder_info2", "uint32", 88, 4, SX_NONE),
    SX_FIELD("finder_info3", "uint32", 92, 4, SX_NONE),
    SX_FIELD("finder_info4", "uint32", 96, 4, SX_NONE),
    SX_FIELD("finder_info5", "uint32", 100, 4, SX_NONE),
    SX_FIELD("finder_info6", "uint32", 104, 4, SX_NONE),
    SX_FIELD("finder_info7", "uint32", 108, 4, SX_NONE),
    SX_FIELD("allocation_logical_size", "uint64", 112, 8, SX_SIZE),
    SX_FIELD("allocation_clump_size", "uint32", 120, 4, SX_SIZE),
    SX_FIELD("allocation_total_blocks", "uint32", 124, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent0_start_block", "uint32", 128, 4, SX_NONE),
    SX_FIELD("allocation_extent0_block_count", "uint32", 132, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent1_start_block", "uint32", 136, 4, SX_NONE),
    SX_FIELD("allocation_extent1_block_count", "uint32", 140, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent2_start_block", "uint32", 144, 4, SX_NONE),
    SX_FIELD("allocation_extent2_block_count", "uint32", 148, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent3_start_block", "uint32", 152, 4, SX_NONE),
    SX_FIELD("allocation_extent3_block_count", "uint32", 156, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent4_start_block", "uint32", 160, 4, SX_NONE),
    SX_FIELD("allocation_extent4_block_count", "uint32", 164, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent5_start_block", "uint32", 168, 4, SX_NONE),
    SX_FIELD("allocation_extent5_block_count", "uint32", 172, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent6_start_block", "uint32", 176, 4, SX_NONE),
    SX_FIELD("allocation_extent6_block_count", "uint32", 180, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent7_start_block", "uint32", 184, 4, SX_NONE),
    SX_FIELD("allocation_extent7_block_count", "uint32", 188, 4, SX_COUNT_PROP),
    SX_FIELD("extents_logical_size", "uint64", 192, 8, SX_SIZE),
    SX_FIELD("extents_clump_size", "uint32", 200, 4, SX_SIZE),
    SX_FIELD("extents_total_blocks", "uint32", 204, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent0_start_block", "uint32", 208, 4, SX_NONE),
    SX_FIELD("extents_extent0_block_count", "uint32", 212, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent1_start_block", "uint32", 216, 4, SX_NONE),
    SX_FIELD("extents_extent1_block_count", "uint32", 220, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent2_start_block", "uint32", 224, 4, SX_NONE),
    SX_FIELD("extents_extent2_block_count", "uint32", 228, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent3_start_block", "uint32", 232, 4, SX_NONE),
    SX_FIELD("extents_extent3_block_count", "uint32", 236, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent4_start_block", "uint32", 240, 4, SX_NONE),
    SX_FIELD("extents_extent4_block_count", "uint32", 244, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent5_start_block", "uint32", 248, 4, SX_NONE),
    SX_FIELD("extents_extent5_block_count", "uint32", 252, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent6_start_block", "uint32", 256, 4, SX_NONE),
    SX_FIELD("extents_extent6_block_count", "uint32", 260, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent7_start_block", "uint32", 264, 4, SX_NONE),
    SX_FIELD("extents_extent7_block_count", "uint32", 268, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_logical_size", "uint64", 272, 8, SX_SIZE),
    SX_FIELD("catalog_clump_size", "uint32", 280, 4, SX_SIZE),
    SX_FIELD("catalog_total_blocks", "uint32", 284, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent0_start_block", "uint32", 288, 4, SX_NONE),
    SX_FIELD("catalog_extent0_block_count", "uint32", 292, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent1_start_block", "uint32", 296, 4, SX_NONE),
    SX_FIELD("catalog_extent1_block_count", "uint32", 300, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent2_start_block", "uint32", 304, 4, SX_NONE),
    SX_FIELD("catalog_extent2_block_count", "uint32", 308, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent3_start_block", "uint32", 312, 4, SX_NONE),
    SX_FIELD("catalog_extent3_block_count", "uint32", 316, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent4_start_block", "uint32", 320, 4, SX_NONE),
    SX_FIELD("catalog_extent4_block_count", "uint32", 324, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent5_start_block", "uint32", 328, 4, SX_NONE),
    SX_FIELD("catalog_extent5_block_count", "uint32", 332, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent6_start_block", "uint32", 336, 4, SX_NONE),
    SX_FIELD("catalog_extent6_block_count", "uint32", 340, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent7_start_block", "uint32", 344, 4, SX_NONE),
    SX_FIELD("catalog_extent7_block_count", "uint32", 348, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_logical_size", "uint64", 352, 8, SX_SIZE),
    SX_FIELD("attributes_clump_size", "uint32", 360, 4, SX_SIZE),
    SX_FIELD("attributes_total_blocks", "uint32", 364, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent0_start_block", "uint32", 368, 4, SX_NONE),
    SX_FIELD("attributes_extent0_block_count", "uint32", 372, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent1_start_block", "uint32", 376, 4, SX_NONE),
    SX_FIELD("attributes_extent1_block_count", "uint32", 380, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent2_start_block", "uint32", 384, 4, SX_NONE),
    SX_FIELD("attributes_extent2_block_count", "uint32", 388, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent3_start_block", "uint32", 392, 4, SX_NONE),
    SX_FIELD("attributes_extent3_block_count", "uint32", 396, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent4_start_block", "uint32", 400, 4, SX_NONE),
    SX_FIELD("attributes_extent4_block_count", "uint32", 404, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent5_start_block", "uint32", 408, 4, SX_NONE),
    SX_FIELD("attributes_extent5_block_count", "uint32", 412, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent6_start_block", "uint32", 416, 4, SX_NONE),
    SX_FIELD("attributes_extent6_block_count", "uint32", 420, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent7_start_block", "uint32", 424, 4, SX_NONE),
    SX_FIELD("attributes_extent7_block_count", "uint32", 428, 4, SX_COUNT_PROP),
    SX_FIELD("startup_logical_size", "uint64", 432, 8, SX_SIZE),
    SX_FIELD("startup_clump_size", "uint32", 440, 4, SX_SIZE),
    SX_FIELD("startup_total_blocks", "uint32", 444, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent0_start_block", "uint32", 448, 4, SX_NONE),
    SX_FIELD("startup_extent0_block_count", "uint32", 452, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent1_start_block", "uint32", 456, 4, SX_NONE),
    SX_FIELD("startup_extent1_block_count", "uint32", 460, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent2_start_block", "uint32", 464, 4, SX_NONE),
    SX_FIELD("startup_extent2_block_count", "uint32", 468, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent3_start_block", "uint32", 472, 4, SX_NONE),
    SX_FIELD("startup_extent3_block_count", "uint32", 476, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent4_start_block", "uint32", 480, 4, SX_NONE),
    SX_FIELD("startup_extent4_block_count", "uint32", 484, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent5_start_block", "uint32", 488, 4, SX_NONE),
    SX_FIELD("startup_extent5_block_count", "uint32", 492, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent6_start_block", "uint32", 496, 4, SX_NONE),
    SX_FIELD("startup_extent6_block_count", "uint32", 500, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent7_start_block", "uint32", 504, 4, SX_NONE),
    SX_FIELD("startup_extent7_block_count", "uint32", 508, 4, SX_COUNT_PROP),
};
static const sx_layout sxo_hfsplus_volume_header = {UINT32_C(0x6013001A),"hfsplus_volume_header",sxo_hfsplus_volume_header_fields,SX_COUNT(sxo_hfsplus_volume_header_fields),SX_BE};

static const xx_data_struct_field_desc sxo_hfsplus_btree_node_descriptor_fields[] = {
    SX_FIELD("forward_link", "uint32", 0, 4, SX_NONE),
    SX_FIELD("backward_link", "uint32", 4, 4, SX_NONE),
    SX_FIELD("kind", "int8", 8, 1, SX_ID),
    SX_FIELD("height", "uint8", 9, 1, SX_NONE),
    SX_FIELD("record_count", "uint16", 10, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint16", 12, 2, SX_RESERVED),
};
static const sx_layout sxo_hfsplus_btree_node_descriptor = {UINT32_C(0x6013001B),"hfsplus_btree_node_descriptor",sxo_hfsplus_btree_node_descriptor_fields,SX_COUNT(sxo_hfsplus_btree_node_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sxo_hfsplus_btree_header_fields[] = {
    SX_FIELD("tree_depth", "uint16", 0, 2, SX_NONE),
    SX_FIELD("root_node", "uint32", 2, 4, SX_NONE),
    SX_FIELD("leaf_record_count", "uint32", 6, 4, SX_COUNT_PROP),
    SX_FIELD("first_leaf_node", "uint32", 10, 4, SX_NONE),
    SX_FIELD("last_leaf_node", "uint32", 14, 4, SX_NONE),
    SX_FIELD("node_size", "uint16", 18, 2, SX_SIZE),
    SX_FIELD("maximum_key_length", "uint16", 20, 2, SX_SIZE),
    SX_FIELD("total_nodes", "uint32", 22, 4, SX_COUNT_PROP),
    SX_FIELD("free_nodes", "uint32", 26, 4, SX_COUNT_PROP),
    SX_FIELD("reserved0", "uint16", 30, 2, SX_RESERVED),
    SX_FIELD("clump_size", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("tree_type", "uint8", 36, 1, SX_ID),
    SX_FIELD("key_compare_type", "uint8", 37, 1, SX_ID),
    SX_FIELD("attributes", "uint32", 38, 4, SX_FLAGS),
    SX_FIELD("reserved1", "uint8[64]", 42, 64, SX_RESERVED),
};
static const sx_layout sxo_hfsplus_btree_header = {UINT32_C(0x6013001C),"hfsplus_btree_header",sxo_hfsplus_btree_header_fields,SX_COUNT(sxo_hfsplus_btree_header_fields),SX_BE};

static const xx_data_struct_field_desc sxo_hfsplus_btree_record_offset_fields[] = {
    SX_FIELD("record_offset", "uint16", 0, 2, SX_OFFSET),
};
static const sx_layout sxo_hfsplus_btree_record_offset = {UINT32_C(0x6013001D),"hfsplus_btree_record_offset",sxo_hfsplus_btree_record_offset_fields,SX_COUNT(sxo_hfsplus_btree_record_offset_fields),SX_BE};

static const xx_data_struct_field_desc sxo_hfsplus_catalog_key_fields[] = {
    SX_FIELD("key_length", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("parent_id", "uint32", 2, 4, SX_ID),
    SX_FIELD("name_code_units", "uint16", 6, 2, SX_COUNT_PROP),
};
static const sx_layout sxo_hfsplus_catalog_key = {UINT32_C(0x6013001E),"hfsplus_catalog_key",sxo_hfsplus_catalog_key_fields,SX_COUNT(sxo_hfsplus_catalog_key_fields),SX_BE};

static const xx_data_struct_field_desc sxo_hfsplus_catalog_folder_fields[] = {
    SX_FIELD("record_type", "int16", 0, 2, SX_ID),
    SX_FIELD("flags", "uint16", 2, 2, SX_FLAGS),
    SX_FIELD("valence", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("object_id", "uint32", 8, 4, SX_ID),
    SX_FIELD("create_date", "uint32", 12, 4, SX_TIME),
    SX_FIELD("content_modification_date", "uint32", 16, 4, SX_TIME),
    SX_FIELD("attribute_modification_date", "uint32", 20, 4, SX_TIME),
    SX_FIELD("access_date", "uint32", 24, 4, SX_TIME),
    SX_FIELD("backup_date", "uint32", 28, 4, SX_TIME),
    SX_FIELD("owner_id", "uint32", 32, 4, SX_NONE),
    SX_FIELD("group_id", "uint32", 36, 4, SX_NONE),
    SX_FIELD("admin_flags", "uint8", 40, 1, SX_FLAGS),
    SX_FIELD("owner_flags", "uint8", 41, 1, SX_FLAGS),
    SX_FIELD("file_mode", "uint16", 42, 2, SX_FLAGS),
    SX_FIELD("special", "uint32", 44, 4, SX_NONE),
    SX_FIELD("window_top", "int16", 48, 2, SX_NONE),
    SX_FIELD("window_left", "int16", 50, 2, SX_NONE),
    SX_FIELD("window_bottom", "int16", 52, 2, SX_NONE),
    SX_FIELD("window_right", "int16", 54, 2, SX_NONE),
    SX_FIELD("finder_flags", "uint16", 56, 2, SX_FLAGS),
    SX_FIELD("location_vertical", "int16", 58, 2, SX_NONE),
    SX_FIELD("location_horizontal", "int16", 60, 2, SX_NONE),
    SX_FIELD("finder_opaque", "int16", 62, 2, SX_NONE),
    SX_FIELD("extended_finder_info", "uint8[16]", 64, 16, SX_NONE),
    SX_FIELD("text_encoding", "uint32", 80, 4, SX_ID),
    SX_FIELD("folder_count", "uint32", 84, 4, SX_COUNT_PROP),
};
static const sx_layout sxo_hfsplus_catalog_folder = {UINT32_C(0x6013001F),"hfsplus_catalog_folder",sxo_hfsplus_catalog_folder_fields,SX_COUNT(sxo_hfsplus_catalog_folder_fields),SX_BE};

static const xx_data_struct_field_desc sxo_hfsplus_catalog_file_fields[] = {
    SX_FIELD("record_type", "int16", 0, 2, SX_ID),
    SX_FIELD("flags", "uint16", 2, 2, SX_FLAGS),
    SX_FIELD("reserved0", "uint32", 4, 4, SX_RESERVED),
    SX_FIELD("object_id", "uint32", 8, 4, SX_ID),
    SX_FIELD("create_date", "uint32", 12, 4, SX_TIME),
    SX_FIELD("content_modification_date", "uint32", 16, 4, SX_TIME),
    SX_FIELD("attribute_modification_date", "uint32", 20, 4, SX_TIME),
    SX_FIELD("access_date", "uint32", 24, 4, SX_TIME),
    SX_FIELD("backup_date", "uint32", 28, 4, SX_TIME),
    SX_FIELD("owner_id", "uint32", 32, 4, SX_NONE),
    SX_FIELD("group_id", "uint32", 36, 4, SX_NONE),
    SX_FIELD("admin_flags", "uint8", 40, 1, SX_FLAGS),
    SX_FIELD("owner_flags", "uint8", 41, 1, SX_FLAGS),
    SX_FIELD("file_mode", "uint16", 42, 2, SX_FLAGS),
    SX_FIELD("special", "uint32", 44, 4, SX_NONE),
    SX_FIELD("file_type", "uint32", 48, 4, SX_ID),
    SX_FIELD("file_creator", "uint32", 52, 4, SX_ID),
    SX_FIELD("finder_flags", "uint16", 56, 2, SX_FLAGS),
    SX_FIELD("location_vertical", "int16", 58, 2, SX_NONE),
    SX_FIELD("location_horizontal", "int16", 60, 2, SX_NONE),
    SX_FIELD("finder_opaque", "int16", 62, 2, SX_NONE),
    SX_FIELD("extended_finder_info", "uint8[16]", 64, 16, SX_NONE),
    SX_FIELD("text_encoding", "uint32", 80, 4, SX_ID),
    SX_FIELD("reserved2", "uint32", 84, 4, SX_RESERVED),
    SX_FIELD("data_logical_size", "uint64", 88, 8, SX_SIZE),
    SX_FIELD("data_clump_size", "uint32", 96, 4, SX_SIZE),
    SX_FIELD("data_total_blocks", "uint32", 100, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent0_start_block", "uint32", 104, 4, SX_NONE),
    SX_FIELD("data_extent0_block_count", "uint32", 108, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent1_start_block", "uint32", 112, 4, SX_NONE),
    SX_FIELD("data_extent1_block_count", "uint32", 116, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent2_start_block", "uint32", 120, 4, SX_NONE),
    SX_FIELD("data_extent2_block_count", "uint32", 124, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent3_start_block", "uint32", 128, 4, SX_NONE),
    SX_FIELD("data_extent3_block_count", "uint32", 132, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent4_start_block", "uint32", 136, 4, SX_NONE),
    SX_FIELD("data_extent4_block_count", "uint32", 140, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent5_start_block", "uint32", 144, 4, SX_NONE),
    SX_FIELD("data_extent5_block_count", "uint32", 148, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent6_start_block", "uint32", 152, 4, SX_NONE),
    SX_FIELD("data_extent6_block_count", "uint32", 156, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent7_start_block", "uint32", 160, 4, SX_NONE),
    SX_FIELD("data_extent7_block_count", "uint32", 164, 4, SX_COUNT_PROP),
    SX_FIELD("resource_logical_size", "uint64", 168, 8, SX_SIZE),
    SX_FIELD("resource_clump_size", "uint32", 176, 4, SX_SIZE),
    SX_FIELD("resource_total_blocks", "uint32", 180, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent0_start_block", "uint32", 184, 4, SX_NONE),
    SX_FIELD("resource_extent0_block_count", "uint32", 188, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent1_start_block", "uint32", 192, 4, SX_NONE),
    SX_FIELD("resource_extent1_block_count", "uint32", 196, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent2_start_block", "uint32", 200, 4, SX_NONE),
    SX_FIELD("resource_extent2_block_count", "uint32", 204, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent3_start_block", "uint32", 208, 4, SX_NONE),
    SX_FIELD("resource_extent3_block_count", "uint32", 212, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent4_start_block", "uint32", 216, 4, SX_NONE),
    SX_FIELD("resource_extent4_block_count", "uint32", 220, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent5_start_block", "uint32", 224, 4, SX_NONE),
    SX_FIELD("resource_extent5_block_count", "uint32", 228, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent6_start_block", "uint32", 232, 4, SX_NONE),
    SX_FIELD("resource_extent6_block_count", "uint32", 236, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent7_start_block", "uint32", 240, 4, SX_NONE),
    SX_FIELD("resource_extent7_block_count", "uint32", 244, 4, SX_COUNT_PROP),
};
static const sx_layout sxo_hfsplus_catalog_file = {UINT32_C(0x60130020),"hfsplus_catalog_file",sxo_hfsplus_catalog_file_fields,SX_COUNT(sxo_hfsplus_catalog_file_fields),SX_BE};

static const xx_data_struct_field_desc sxo_hfsplus_catalog_thread_fields[] = {
    SX_FIELD("record_type", "int16", 0, 2, SX_ID),
    SX_FIELD("reserved", "int16", 2, 2, SX_RESERVED),
    SX_FIELD("parent_id", "uint32", 4, 4, SX_ID),
    SX_FIELD("name_code_units", "uint16", 8, 2, SX_COUNT_PROP),
};
static const sx_layout sxo_hfsplus_catalog_thread = {UINT32_C(0x60130021),"hfsplus_catalog_thread",sxo_hfsplus_catalog_thread_fields,SX_COUNT(sxo_hfsplus_catalog_thread_fields),SX_BE};

static const sx_layout *const sx_opticalfs_layouts[] = {
    &sxo_iso_directory_record,
    &sxo_iso_path_table_l,
    &sxo_iso_path_table_m,
    &sxo_iso_primary_volume_descriptor,
    &sxo_iso_supplementary_volume_descriptor,
    &sxo_iso_boot_record,
    &sxo_iso_volume_partition_descriptor,
    &sxo_iso_volume_descriptor_terminator,
    &sxo_iso_volume_descriptor_header,
    &sxo_udf_volume_recognition_descriptor,
    &sxo_udf_descriptor_tag,
    &sxo_udf_anchor_volume_descriptor,
    &sxo_udf_primary_volume_descriptor,
    &sxo_udf_partition_descriptor,
    &sxo_udf_logical_volume_descriptor,
    &sxo_udf_partition_map_type1,
    &sxo_udf_partition_map_header,
    &sxo_udf_terminating_descriptor,
    &sxo_udf_file_set_descriptor,
    &sxo_udf_file_entry,
    &sxo_udf_extended_file_entry,
    &sxo_udf_file_identifier_descriptor,
    &sxo_udf_short_allocation_descriptor,
    &sxo_udf_long_allocation_descriptor,
    &sxo_udf_extended_allocation_descriptor,
    &sxo_hfsplus_volume_header,
    &sxo_hfsplus_btree_node_descriptor,
    &sxo_hfsplus_btree_header,
    &sxo_hfsplus_btree_record_offset,
    &sxo_hfsplus_catalog_key,
    &sxo_hfsplus_catalog_folder,
    &sxo_hfsplus_catalog_file,
    &sxo_hfsplus_catalog_thread,
};

static bool sx_opticalfs_supports(xx_file_type_t t){return t==XX_FILE_TYPE_ISO9660||t==XX_FILE_TYPE_UDF||t==XX_FILE_TYPE_HFSPLUS;}
static uint32_t sxo_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
static uint16_t sxo_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
static bool sxo_can(sx_context *c,int64_t at,uint64_t n){return at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at)&&!xx_pd_is_stopped(c->pd);}
static bool sxo_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n)
{
    if(n<=0||!sxo_can(c,at,(uint64_t)n)||at>INT64_MAX-c->f->base_address)return false;
    for(size_t i=0;i<c->count;i++)if(c->items[i].offset==c->f->base_address+at&&c->items[i].id==l->id&&c->items[i].total_size==n)return true;
    return sx_add(c,l,at,n);
}
static bool sxo_finish(sx_context *c)
{
    size_t count=c->count;int64_t end=0;
    for(size_t i=1;i<count;i++){xx_data_struct d=c->items[i];size_t j=i;while(j&&c->items[j-1].offset>d.offset){c->items[j]=c->items[j-1];j--;}c->items[j]=d;}
    for(size_t i=0;i<count;i++){int64_t at=c->items[i].offset-c->f->base_address,n=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+n;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    for(size_t i=1;i<c->count;i++){xx_data_struct d=c->items[i];size_t j=i;while(j&&c->items[j-1].offset>d.offset){c->items[j]=c->items[j-1];j--;}c->items[j]=d;}
    return !c->failed;
}
typedef struct sxo_iso_directory {uint32_t lba,size;unsigned depth;} sxo_iso_directory;
static bool sxo_iso_paths(sx_context *c,uint32_t block,uint32_t bytes,bool be)
{
    int64_t at=(int64_t)block*2048,end=at+bytes;unsigned entries=0;uint8_t b[8];
    if(!block||!bytes)return true;if(!sxo_can(c,at,bytes))return false;
    while(at<end){if(++entries>65535||end-at<8||!sx_read(c,at,b,8)||!b[0])return false;uint32_t n=8+b[0]+(b[0]&1);if(n>(uint64_t)(end-at))return false;
        if(!sxo_add(c,be?&sxo_iso_path_table_m:&sxo_iso_path_table_l,at,8))return false;at+=n;
    }return true;
}
static bool sxo_iso_build(sx_context *c)
{
    uint8_t b[2048],pvd[2048];bool primary=false,terminated=false,ok=false;size_t count=1;
    sxo_iso_directory *queue=xx_mem_alloc(8192*sizeof(*queue));if(!queue)return false;
    for(unsigned i=0;i<64;i++){
        int64_t at=(int64_t)(16+i)*2048;const sx_layout *l=&sxo_iso_volume_descriptor_header;int n=7;
        if(!sx_read(c,at,b,2048)||xx_rt_memcmp(b+1,"CD001",5)||b[6]!=1)goto done;
        switch(b[0]){case 0:l=&sxo_iso_boot_record;n=2048;break;case 1:l=&sxo_iso_primary_volume_descriptor;n=2048;if(!primary){xx_rt_memcpy(pvd,b,2048);primary=true;}break;case 2:l=&sxo_iso_supplementary_volume_descriptor;n=2048;break;case 3:l=&sxo_iso_volume_partition_descriptor;n=2048;break;case 255:l=&sxo_iso_volume_descriptor_terminator;n=2048;terminated=true;break;}
        if(!sxo_add(c,l,at,n))goto done;if(terminated)break;
    }
    if(!primary||!terminated||sxo_u32(pvd+80)!=xx_data_get_u32(pvd+84,4,0,true)||sxo_u16(pvd+128)!=2048||xx_data_get_u16(pvd+130,2,0,true)!=2048)goto done;
    if(sxo_u32(pvd+132)!=xx_data_get_u32(pvd+136,4,0,true))goto done;
    for(unsigned i=0;i<4;i++)if(!sxo_iso_paths(c,xx_data_get_u32(pvd+140+i*4,4,0,i>=2),sxo_u32(pvd+132),i>=2))goto done;
    queue[0]=(sxo_iso_directory){sxo_u32(pvd+158),sxo_u32(pvd+166),0};
    for(size_t q=0;q<count;q++){
        int64_t at=(int64_t)queue[q].lba*2048,end=at+queue[q].size,start=at;
        if(queue[q].depth>64||!queue[q].size||!sxo_can(c,at,queue[q].size))goto done;
        while(at<end){
            if(!sx_read(c,at,b,1))goto done;unsigned n=b[0];if(!n){at+=2048-(at-start)%2048;continue;}
            if(n<34||n>(uint64_t)(end-at)||n>2048-(at-start)%2048||!sx_read(c,at,b,n)||33U+b[32]>n)goto done;
            if(!sxo_add(c,&sxo_iso_directory_record,at,33))goto done;
            if((b[25]&2)&&!(b[32]==1&&(b[33]==0||b[33]==1))){
                uint32_t lba=sxo_u32(b+2),bytes=sxo_u32(b+10);bool seen=false;
                for(size_t j=0;j<count;j++)if(queue[j].lba==lba&&queue[j].size==bytes){seen=true;break;}
                if(!seen){if(count>=8192)goto done;queue[count++]=(sxo_iso_directory){lba,bytes,queue[q].depth+1};}
            }
            at+=n;
        }
    }
    ok=true;
done:xx_mem_free(queue);return ok;
}
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
/* Only a physically contiguous node reached through the volume-header fork's
 * eight inline extents receives structures. Overflow-resolved or fragmented
 * node payloads remain raw; no fictitious contiguous file offset is emitted. */
static bool sxo_hfs_address(sx_context *c,const uint8_t fork[80],uint32_t unit,uint64_t logical,uint64_t size,int64_t *out)
{
    uint64_t start=0;
    if(logical>xx_data_get_u64(fork,8,0,true)||size>xx_data_get_u64(fork,8,0,true)-logical)return false;
    for(unsigned i=0;i<8;i++){
        uint32_t block=xx_data_get_u32(fork+16+i*8,4,0,true),count=xx_data_get_u32(fork+20+i*8,4,0,true);uint64_t bytes=(uint64_t)count*unit;
        if(logical>=start&&logical-start<bytes){uint64_t at=(uint64_t)block*unit+logical-start;if(size>bytes-(logical-start)||at>INT64_MAX||!sxo_can(c,(int64_t)at,size))return false;*out=(int64_t)at;return true;}start+=bytes;
    }return false;
}
static bool sxo_hfs_tree(sx_context *c,const uint8_t fork[80],uint32_t unit,bool catalog)
{
    uint8_t probe[120],*b=NULL;int64_t at;uint32_t node_size,nodes,first,count=1;bool ok=false;
    if(!xx_data_get_u64(fork,8,0,true))return true;
    if(!sxo_hfs_address(c,fork,unit,0,120,&at))return true;if(!sx_read(c,at,probe,120))return false;
    node_size=xx_data_get_u16(probe+32,2,0,true);nodes=xx_data_get_u32(probe+36,4,0,true);first=xx_data_get_u32(probe+24,4,0,true);
    if(node_size<512||node_size>32768||(node_size&(node_size-1))||!nodes||nodes>131072)return false;
    b=xx_mem_alloc(node_size);uint32_t *queue=xx_mem_alloc((size_t)nodes*sizeof(*queue));uint8_t *seen=xx_mem_alloc(nodes);if(!b||!queue||!seen)goto done;xx_rt_memset(seen,0,nodes);queue[0]=0;seen[0]=1;
    if(first){if(first>=nodes)goto done;queue[count++]=first;seen[first]=1;}
    for(uint32_t q=0;q<count;q++){
        if(xx_pd_is_stopped(c->pd))goto done;if(!sxo_hfs_address(c,fork,unit,(uint64_t)queue[q]*node_size,node_size,&at))continue;if(!sx_read(c,at,b,node_size))goto done;
        uint16_t n=xx_data_get_u16(b+10,2,0,true);if(n>(node_size-16)/4)goto done;
        if(!sxo_add(c,&sxo_hfsplus_btree_node_descriptor,at,14)||!sx_table(c,&sxo_hfsplus_btree_record_offset,at+node_size-2*(n+1),2,n+1))goto done;
        for(uint16_t i=0;i<n;i++){
            uint16_t begin=xx_data_get_u16(b+node_size-2-2*i,2,0,true),end=xx_data_get_u16(b+node_size-4-2*i,2,0,true);
            if(begin<14||end<=begin||end>node_size-2*(n+1))goto done;
            if(queue[q]==0&&i==0){if(end-begin<106||!sxo_add(c,&sxo_hfsplus_btree_header,at+begin,106))goto done;}
            else if(catalog&&b[8]==255){
                uint16_t key=xx_data_get_u16(b+begin,2,0,true);uint32_t payload=begin+2+key;if(key<6||payload>end||end-payload<2)goto done;
                if(!sxo_add(c,&sxo_hfsplus_catalog_key,at+begin,8))goto done;
                uint16_t type=xx_data_get_u16(b+payload,2,0,true);const sx_layout *l=type==1?&sxo_hfsplus_catalog_folder:type==2?&sxo_hfsplus_catalog_file:(type==3||type==4)?&sxo_hfsplus_catalog_thread:NULL;
                unsigned length=type==1?88:type==2?248:10;if(l&&(length>(uint32_t)(end-payload)||!sxo_add(c,l,at+payload,length)))goto done;
            }
        }
        uint32_t next=xx_data_get_u32(b,4,0,true);if(next){if(next>=nodes)goto done;if(!seen[next]){if(count>=nodes)goto done;seen[next]=1;queue[count++]=next;}}
    }ok=true;
done:xx_mem_free(b);xx_mem_free(queue);xx_mem_free(seen);return ok;
}
static bool sxo_hfs_build(sx_context *c)
{
    uint8_t h[512],alt[512];if(!sx_read(c,1024,h,512)||!sxo_add(c,&sxo_hfsplus_volume_header,1024,512))return false;
    uint32_t unit=xx_data_get_u32(h+40,4,0,true),blocks=xx_data_get_u32(h+44,4,0,true);uint64_t size=(uint64_t)unit*blocks;
    if(size<4096||size>(uint64_t)c->size)return false;
    if(sxo_can(c,(int64_t)size-1024,512)&&sx_read(c,(int64_t)size-1024,alt,512)&&!xx_rt_memcmp(h,alt,4)&&xx_data_get_u32(alt+40,4,0,true)==unit&&xx_data_get_u32(alt+44,4,0,true)==blocks)
        if(!sxo_add(c,&sxo_hfsplus_volume_header,(int64_t)size-1024,512))return false;
    return sxo_hfs_tree(c,h+192,unit,false)&&sxo_hfs_tree(c,h+272,unit,true)&&sxo_hfs_tree(c,h+352,unit,false);
}

static bool sx_opticalfs_build(sx_context *c)
{
    if(!c->f->handle_base_info||!xx_format_handle_base_info(c->f,c->pd)||!c->f->is_valid)return false;
    bool ok=c->f->file_type==XX_FILE_TYPE_ISO9660?sxo_iso_build(c):c->f->file_type==XX_FILE_TYPE_UDF?sxo_udf_build(c):c->f->file_type==XX_FILE_TYPE_HFSPLUS?sxo_hfs_build(c):false;
    return ok&&c->count&&sxo_finish(c);
}
static bool sxo_has(const wchar_t *s,const wchar_t *p){size_t n=xx_rt_wcslen(p);for(;*s;s++)if(!xx_rt_wcsncmp(s,p,n))return true;return false;}
static bool sx_opticalfs_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60130000)||id>=UINT32_C(0x60140000))return true;
    const wchar_t *n=r->name,*text=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(sxo_has(n,L"_lba")||sxo_has(n,L"_location")||sxo_has(n,L"logical_block")||!xx_rt_wcscmp(n,L"starting_location"))text=L"Logical block number; byte position depends on the volume or partition origin and logical block size";
    if(sxo_has(n,L"_blocks")||sxo_has(n,L"logical_blocks_recorded"))text=L"Logical blocks, not bytes; multiply by the logical block size";
    if(sxo_has(n,L"timezone_quarters"))text=L"Signed offset from UTC in 15-minute units";
    if(sxo_has(n,L"type_timezone"))text=L"High 4 bits: timestamp type; low 12 bits: signed UTC offset in minutes (0x801 means unspecified)";
    if(sxo_has(n,L"extent_length_flags"))text=L"Bits 0..29: extent length in bytes; bits 30..31: recorded, allocated/unrecorded, unallocated, or continuation";
    if(!xx_rt_wcscmp(n,L"descriptor_type"))text=v==0?L"BOOT_RECORD":v==1?L"PRIMARY_VOLUME_DESCRIPTOR":v==2?L"SUPPLEMENTARY_VOLUME_DESCRIPTOR":v==3?L"VOLUME_PARTITION_DESCRIPTOR":v==255?L"VOLUME_DESCRIPTOR_SET_TERMINATOR":NULL;
    if(!xx_rt_wcscmp(n,L"tag_identifier"))text=v==1?L"PRIMARY_VOLUME_DESCRIPTOR":v==2?L"ANCHOR_VOLUME_DESCRIPTOR_POINTER":v==5?L"PARTITION_DESCRIPTOR":v==6?L"LOGICAL_VOLUME_DESCRIPTOR":v==8?L"TERMINATING_DESCRIPTOR":v==256?L"FILE_SET_DESCRIPTOR":v==257?L"FILE_IDENTIFIER_DESCRIPTOR":v==261?L"FILE_ENTRY":v==266?L"EXTENDED_FILE_ENTRY":NULL;
    if(!xx_rt_wcscmp(n,L"icb_flags"))text=L"Bits 0..2: short/long/extended/embedded allocation descriptors; bit 3 sorted, bit 4 non-relocatable, bit 9 contiguous, bit 12 multiple versions";
    if(!xx_rt_wcscmp(n,L"file_characteristics"))text=L"Bits: 0 hidden, 1 directory, 2 deleted, 3 parent, 4 metadata";
    if((id==sxo_iso_directory_record.id&&!xx_rt_wcscmp(n,L"flags"))||sxo_has(n,L"root_flags"))text=L"Bits: 0 hidden, 1 directory, 2 associated, 3 record, 4 protection, 7 multiple extents";
    if(id<sxo_hfsplus_volume_header.id&&!xx_rt_wcscmp(n,L"file_type"))text=v==4?L"DIRECTORY":v==5?L"REGULAR_FILE":v==12?L"SYMBOLIC_LINK":NULL;
    if(id>=sxo_hfsplus_volume_header.id&&id<=sxo_hfsplus_catalog_thread.id){
        if(sxo_has(n,L"_block")||sxo_has(n,L"_blocks"))text=L"Allocation block units; byte position or length = value * volume block size";
        if(sxo_has(n,L"_node")||!xx_rt_wcscmp(n,L"forward_link")||!xx_rt_wcscmp(n,L"backward_link"))text=L"B-tree node number; byte position within the special file = value * node size";
        if(!xx_rt_wcscmp(n,L"total_nodes")||!xx_rt_wcscmp(n,L"free_nodes"))text=L"Count of B-tree nodes";
        if(!xx_rt_wcscmp(n,L"file_type")||!xx_rt_wcscmp(n,L"file_creator")||!xx_rt_wcscmp(n,L"last_mounted_version"))text=L"Four-character code stored as a big-endian 32-bit integer";
        if(id==sxo_hfsplus_volume_header.id&&!xx_rt_wcscmp(n,L"signature"))text=v==0x482b?L"HFS_PLUS_SIGNATURE":v==0x4858?L"HFSX_SIGNATURE":NULL;
        if(sxo_has(n,L"_date"))text=L"Seconds since 1904-01-01 (HFS epoch)";
        if(!xx_rt_wcscmp(n,L"record_type"))text=v==1?L"HFS_PLUS_FOLDER_RECORD":v==2?L"HFS_PLUS_FILE_RECORD":v==3?L"HFS_PLUS_FOLDER_THREAD_RECORD":v==4?L"HFS_PLUS_FILE_THREAD_RECORD":NULL;
        if(id==sxo_hfsplus_btree_node_descriptor.id&&!xx_rt_wcscmp(n,L"kind"))text=xx_var_get_i64(&r->value)==-1?L"LEAF_NODE":v==0?L"INDEX_NODE":v==1?L"HEADER_NODE":v==2?L"MAP_NODE":NULL;
        if(id==sxo_hfsplus_volume_header.id&&!xx_rt_wcscmp(n,L"attributes"))text=L"Bit 8: unmounted cleanly; bit 9: spared blocks; bit 11: inconsistent; bit 13: journaled; bit 15: software locked";
    }
    return !text||xx_data_struct_record_set_comment(r,text);
}
