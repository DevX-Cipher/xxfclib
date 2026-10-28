/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical package/document metadata. Compressed streams, XML, opcode streams
 * and unparsed variable extensions remain RAW_DATA.
 */
static const xx_data_struct_field_desc sx_p_arj_prefix_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
};
static const sx_layout sx_p_arj_prefix = { UINT32_C(0x60070001), "arj_prefix", sx_p_arj_prefix_fields, SX_COUNT(sx_p_arj_prefix_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_arj_main_fields[] = {
    SX_FIELD("first_header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("archiver_version", "uint8", 1, 1, SX_NONE),
    SX_FIELD("minimum_version", "uint8", 2, 1, SX_NONE),
    SX_FIELD("host_os", "uint8", 3, 1, SX_ID),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("method", "uint8", 5, 1, SX_ID),
    SX_FIELD("file_type", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 7, 1, SX_RESERVED),
    SX_FIELD("created", "uint32", 8, 4, SX_TIME),
    SX_FIELD("modified", "uint32", 12, 4, SX_TIME),
    SX_FIELD("archive_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("security_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("filespec_position", "uint16", 24, 2, SX_OFFSET),
    SX_FIELD("security_size", "uint16", 26, 2, SX_SIZE),
    SX_FIELD("encryption_version", "uint8", 28, 1, SX_NONE),
    SX_FIELD("last_chapter", "uint8", 29, 1, SX_NONE),
};
static const sx_layout sx_p_arj_main = { UINT32_C(0x60070002), "arj_main", sx_p_arj_main_fields, SX_COUNT(sx_p_arj_main_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_arj_file_fields[] = {
    SX_FIELD("first_header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("archiver_version", "uint8", 1, 1, SX_NONE),
    SX_FIELD("minimum_version", "uint8", 2, 1, SX_NONE),
    SX_FIELD("host_os", "uint8", 3, 1, SX_ID),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("method", "uint8", 5, 1, SX_ID),
    SX_FIELD("file_type", "uint8", 6, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 7, 1, SX_RESERVED),
    SX_FIELD("modified", "uint32", 8, 4, SX_TIME),
    SX_FIELD("packed_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("crc32", "uint32", 20, 4, SX_CHECKSUM),
    SX_FIELD("filespec_position", "uint16", 24, 2, SX_OFFSET),
    SX_FIELD("access_mode", "uint16", 26, 2, SX_FLAGS),
    SX_FIELD("first_chapter", "uint8", 28, 1, SX_NONE),
    SX_FIELD("last_chapter", "uint8", 29, 1, SX_NONE),
};
static const sx_layout sx_p_arj_file = { UINT32_C(0x60070003), "arj_file", sx_p_arj_file_fields, SX_COUNT(sx_p_arj_file_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_crc32_fields[] = {
    SX_FIELD("crc32", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_p_crc32 = { UINT32_C(0x60070004), "crc32", sx_p_crc32_fields, SX_COUNT(sx_p_crc32_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_crc16_fields[] = {
    SX_FIELD("crc16", "uint16", 0, 2, SX_CHECKSUM),
};
static const sx_layout sx_p_crc16 = { UINT32_C(0x60070005), "crc16", sx_p_crc16_fields, SX_COUNT(sx_p_crc16_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_length16_fields[] = {
    SX_FIELD("data_size", "uint16", 0, 2, SX_SIZE),
};
static const sx_layout sx_p_length16 = { UINT32_C(0x60070006), "length16", sx_p_length16_fields, SX_COUNT(sx_p_length16_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_ace_main_fields[] = {
    SX_FIELD("header_crc", "uint16", 0, 2, SX_CHECKSUM),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("header_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("flags", "uint16", 5, 2, SX_FLAGS),
    SX_FIELD("signature", "char[7]", 7, 7, SX_SIGNATURE),
    SX_FIELD("extract_version", "uint8", 14, 1, SX_NONE),
    SX_FIELD("create_version", "uint8", 15, 1, SX_NONE),
    SX_FIELD("host_os", "uint8", 16, 1, SX_ID),
    SX_FIELD("volume", "uint8", 17, 1, SX_NONE),
    SX_FIELD("created", "uint32", 18, 4, SX_TIME),
    SX_FIELD("reserved", "bytes", 22, 8, SX_RESERVED),
    SX_FIELD("advert_size", "uint8", 30, 1, SX_SIZE),
};
static const sx_layout sx_p_ace_main = { UINT32_C(0x60070007), "ace_main", sx_p_ace_main_fields, SX_COUNT(sx_p_ace_main_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_ace_generic_fields[] = {
    SX_FIELD("header_crc", "uint16", 0, 2, SX_CHECKSUM),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("header_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("flags", "uint16", 5, 2, SX_FLAGS),
};
static const sx_layout sx_p_ace_generic = { UINT32_C(0x60070008), "ace_generic", sx_p_ace_generic_fields, SX_COUNT(sx_p_ace_generic_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_ace_file32_fields[] = {
    SX_FIELD("header_crc", "uint16", 0, 2, SX_CHECKSUM),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("header_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("flags", "uint16", 5, 2, SX_FLAGS),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint32", 19, 4, SX_FLAGS),
    SX_FIELD("crc32", "uint32", 23, 4, SX_CHECKSUM),
    SX_FIELD("method", "uint8", 27, 1, SX_ID),
    SX_FIELD("quality", "uint8", 28, 1, SX_NONE),
    SX_FIELD("parameter", "uint16", 29, 2, SX_NONE),
    SX_FIELD("reserved", "uint16", 31, 2, SX_RESERVED),
    SX_FIELD("name_size", "uint16", 33, 2, SX_SIZE),
};
static const sx_layout sx_p_ace_file32 = { UINT32_C(0x60070009), "ace_file32", sx_p_ace_file32_fields, SX_COUNT(sx_p_ace_file32_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_ace_file64_fields[] = {
    SX_FIELD("header_crc", "uint16", 0, 2, SX_CHECKSUM),
    SX_FIELD("header_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("header_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("flags", "uint16", 5, 2, SX_FLAGS),
    SX_FIELD("packed_size", "uint64", 7, 8, SX_SIZE),
    SX_FIELD("original_size", "uint64", 15, 8, SX_SIZE),
    SX_FIELD("modified", "uint32", 23, 4, SX_TIME),
    SX_FIELD("attributes", "uint32", 27, 4, SX_FLAGS),
    SX_FIELD("crc32", "uint32", 31, 4, SX_CHECKSUM),
    SX_FIELD("method", "uint8", 35, 1, SX_ID),
    SX_FIELD("quality", "uint8", 36, 1, SX_NONE),
    SX_FIELD("parameter", "uint16", 37, 2, SX_NONE),
    SX_FIELD("reserved", "uint16", 39, 2, SX_RESERVED),
    SX_FIELD("name_size", "uint16", 41, 2, SX_SIZE),
};
static const sx_layout sx_p_ace_file64 = { UINT32_C(0x6007000A), "ace_file64", sx_p_ace_file64_fields, SX_COUNT(sx_p_ace_file64_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("reserved", "uint32", 4, 4, SX_RESERVED),
};
static const sx_layout sx_p_alz_header = { UINT32_C(0x6007000B), "alz_header", sx_p_alz_header_fields, SX_COUNT(sx_p_alz_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_file_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("name_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("attributes", "uint8", 6, 1, SX_FLAGS),
    SX_FIELD("modified", "uint32", 7, 4, SX_TIME),
    SX_FIELD("descriptor", "uint8", 11, 1, SX_FLAGS),
    SX_FIELD("reserved", "uint8", 12, 1, SX_RESERVED),
};
static const sx_layout sx_p_alz_file = { UINT32_C(0x6007000C), "alz_file", sx_p_alz_file_fields, SX_COUNT(sx_p_alz_file_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_sizes1_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint8", 6, 1, SX_SIZE),
    SX_FIELD("original_size", "uint8", 7, 1, SX_SIZE),
};
static const sx_layout sx_p_alz_sizes1 = { UINT32_C(0x6007000D), "alz_sizes1", sx_p_alz_sizes1_fields, SX_COUNT(sx_p_alz_sizes1_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_sizes2_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("original_size", "uint16", 8, 2, SX_SIZE),
};
static const sx_layout sx_p_alz_sizes2 = { UINT32_C(0x6007000E), "alz_sizes2", sx_p_alz_sizes2_fields, SX_COUNT(sx_p_alz_sizes2_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_sizes3_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint24", 6, 3, SX_SIZE),
    SX_FIELD("original_size", "uint24", 9, 3, SX_SIZE),
};
static const sx_layout sx_p_alz_sizes3 = { UINT32_C(0x6007000F), "alz_sizes3", sx_p_alz_sizes3_fields, SX_COUNT(sx_p_alz_sizes3_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_sizes4_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint32", 6, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 10, 4, SX_SIZE),
};
static const sx_layout sx_p_alz_sizes4 = { UINT32_C(0x60070010), "alz_sizes4", sx_p_alz_sizes4_fields, SX_COUNT(sx_p_alz_sizes4_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_sizes5_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint40", 6, 5, SX_SIZE),
    SX_FIELD("original_size", "uint40", 11, 5, SX_SIZE),
};
static const sx_layout sx_p_alz_sizes5 = { UINT32_C(0x60070011), "alz_sizes5", sx_p_alz_sizes5_fields, SX_COUNT(sx_p_alz_sizes5_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_sizes6_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint48", 6, 6, SX_SIZE),
    SX_FIELD("original_size", "uint48", 12, 6, SX_SIZE),
};
static const sx_layout sx_p_alz_sizes6 = { UINT32_C(0x60070012), "alz_sizes6", sx_p_alz_sizes6_fields, SX_COUNT(sx_p_alz_sizes6_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_sizes7_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint56", 6, 7, SX_SIZE),
    SX_FIELD("original_size", "uint56", 13, 7, SX_SIZE),
};
static const sx_layout sx_p_alz_sizes7 = { UINT32_C(0x60070013), "alz_sizes7", sx_p_alz_sizes7_fields, SX_COUNT(sx_p_alz_sizes7_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_alz_sizes8_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("crc32", "uint32", 2, 4, SX_CHECKSUM),
    SX_FIELD("packed_size", "uint64", 6, 8, SX_SIZE),
    SX_FIELD("original_size", "uint64", 14, 8, SX_SIZE),
};
static const sx_layout sx_p_alz_sizes8 = { UINT32_C(0x60070014), "alz_sizes8", sx_p_alz_sizes8_fields, SX_COUNT(sx_p_alz_sizes8_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_ha_header_fields[] = {
    SX_FIELD("signature", "char[2]", 0, 2, SX_SIGNATURE),
    SX_FIELD("member_count", "uint16", 2, 2, SX_COUNT_PROP),
};
static const sx_layout sx_p_ha_header = { UINT32_C(0x60070015), "ha_header", sx_p_ha_header_fields, SX_COUNT(sx_p_ha_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_ha_file_fields[] = {
    SX_FIELD("version_method", "uint8", 0, 1, SX_ID),
    SX_FIELD("packed_size", "uint32", 1, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 5, 4, SX_SIZE),
    SX_FIELD("crc32", "uint32", 9, 4, SX_CHECKSUM),
    SX_FIELD("modified", "uint32", 13, 4, SX_TIME),
};
static const sx_layout sx_p_ha_file = { UINT32_C(0x60070016), "ha_file", sx_p_ha_file_fields, SX_COUNT(sx_p_ha_file_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_ha_machine_fields[] = {
    SX_FIELD("machine_data_size", "uint8", 0, 1, SX_SIZE),
};
static const sx_layout sx_p_ha_machine = { UINT32_C(0x60070017), "ha_machine", sx_p_ha_machine_fields, SX_COUNT(sx_p_ha_machine_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_zoo_header_fields[] = {
    SX_FIELD("banner", "char[20]", 0, 20, SX_STRING),
    SX_FIELD("magic", "uint32", 20, 4, SX_SIGNATURE),
    SX_FIELD("first_directory", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("negative_first_directory", "uint32", 28, 4, SX_NONE),
    SX_FIELD("version_major", "uint8", 32, 1, SX_NONE),
    SX_FIELD("version_minor", "uint8", 33, 1, SX_NONE),
};
static const sx_layout sx_p_zoo_header = { UINT32_C(0x60070018), "zoo_header", sx_p_zoo_header_fields, SX_COUNT(sx_p_zoo_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_zoo_directory_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("type", "uint8", 4, 1, SX_ID),
    SX_FIELD("method", "uint8", 5, 1, SX_ID),
    SX_FIELD("next_directory", "uint32", 6, 4, SX_OFFSET),
    SX_FIELD("data_offset", "uint32", 10, 4, SX_OFFSET),
    SX_FIELD("date", "uint16", 14, 2, SX_NONE),
    SX_FIELD("time", "uint16", 16, 2, SX_NONE),
    SX_FIELD("crc16", "uint16", 18, 2, SX_CHECKSUM),
    SX_FIELD("original_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("packed_size", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("version_major", "uint8", 28, 1, SX_NONE),
    SX_FIELD("version_minor", "uint8", 29, 1, SX_NONE),
    SX_FIELD("deleted", "uint8", 30, 1, SX_FLAGS),
    SX_FIELD("file_structure", "uint8", 31, 1, SX_ID),
    SX_FIELD("comment_offset", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("comment_size", "uint16", 36, 2, SX_SIZE),
    SX_FIELD("short_name", "char[13]", 38, 13, SX_STRING),
};
static const sx_layout sx_p_zoo_directory = { UINT32_C(0x60070019), "zoo_directory", sx_p_zoo_directory_fields, SX_COUNT(sx_p_zoo_directory_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_zoo_variable_fields[] = {
    SX_FIELD("variable_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("timezone", "int8", 2, 1, SX_NONE),
    SX_FIELD("header_crc16", "uint16", 3, 2, SX_CHECKSUM),
    SX_FIELD("name_size", "uint8", 5, 1, SX_SIZE),
    SX_FIELD("directory_size", "uint8", 6, 1, SX_SIZE),
};
static const sx_layout sx_p_zoo_variable = { UINT32_C(0x6007001A), "zoo_variable", sx_p_zoo_variable_fields, SX_COUNT(sx_p_zoo_variable_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_level0_fields[] = {
    SX_FIELD("header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("header_checksum", "uint8", 1, 1, SX_CHECKSUM),
    SX_FIELD("method", "char[5]", 2, 5, SX_ID),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint8", 19, 1, SX_FLAGS),
    SX_FIELD("level", "uint8", 20, 1, SX_ID),
    SX_FIELD("name_size", "uint8", 21, 1, SX_SIZE),
};
static const sx_layout sx_p_lha_level0 = { UINT32_C(0x6007001B), "lha_level0", sx_p_lha_level0_fields, SX_COUNT(sx_p_lha_level0_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_level1_fields[] = {
    SX_FIELD("header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("header_checksum", "uint8", 1, 1, SX_CHECKSUM),
    SX_FIELD("method", "char[5]", 2, 5, SX_ID),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint8", 19, 1, SX_FLAGS),
    SX_FIELD("level", "uint8", 20, 1, SX_ID),
    SX_FIELD("name_size", "uint8", 21, 1, SX_SIZE),
};
static const sx_layout sx_p_lha_level1 = { UINT32_C(0x6007001C), "lha_level1", sx_p_lha_level1_fields, SX_COUNT(sx_p_lha_level1_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_level2_fields[] = {
    SX_FIELD("header_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("method", "char[5]", 2, 5, SX_ID),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint8", 19, 1, SX_FLAGS),
    SX_FIELD("level", "uint8", 20, 1, SX_ID),
    SX_FIELD("crc16", "uint16", 21, 2, SX_CHECKSUM),
    SX_FIELD("host_os", "uint8", 23, 1, SX_ID),
};
static const sx_layout sx_p_lha_level2 = { UINT32_C(0x6007001D), "lha_level2", sx_p_lha_level2_fields, SX_COUNT(sx_p_lha_level2_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_level3_fields[] = {
    SX_FIELD("word_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("method", "char[5]", 2, 5, SX_ID),
    SX_FIELD("packed_size", "uint32", 7, 4, SX_SIZE),
    SX_FIELD("original_size", "uint32", 11, 4, SX_SIZE),
    SX_FIELD("modified", "uint32", 15, 4, SX_TIME),
    SX_FIELD("attributes", "uint8", 19, 1, SX_FLAGS),
    SX_FIELD("level", "uint8", 20, 1, SX_ID),
    SX_FIELD("crc16", "uint16", 21, 2, SX_CHECKSUM),
    SX_FIELD("host_os", "uint8", 23, 1, SX_ID),
    SX_FIELD("total_header_size", "uint32", 24, 4, SX_SIZE),
};
static const sx_layout sx_p_lha_level3 = { UINT32_C(0x6007001E), "lha_level3", sx_p_lha_level3_fields, SX_COUNT(sx_p_lha_level3_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_extension2_fields[] = {
    SX_FIELD("next_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("type", "uint8", 2, 1, SX_ID),
};
static const sx_layout sx_p_lha_extension2 = { UINT32_C(0x6007001F), "lha_extension2", sx_p_lha_extension2_fields, SX_COUNT(sx_p_lha_extension2_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_extension4_fields[] = {
    SX_FIELD("next_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("type", "uint8", 4, 1, SX_ID),
};
static const sx_layout sx_p_lha_extension4 = { UINT32_C(0x60070020), "lha_extension4", sx_p_lha_extension4_fields, SX_COUNT(sx_p_lha_extension4_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_os_fields[] = {
    SX_FIELD("host_os", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_p_lha_os = { UINT32_C(0x60070021), "lha_os", sx_p_lha_os_fields, SX_COUNT(sx_p_lha_os_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_length32_fields[] = {
    SX_FIELD("data_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_p_length32 = { UINT32_C(0x60070022), "length32", sx_p_length32_fields, SX_COUNT(sx_p_length32_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_zlib_header_fields[] = {
    SX_FIELD("compression_method_flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("flags", "uint8", 1, 1, SX_FLAGS),
};
static const sx_layout sx_p_zlib_header = { UINT32_C(0x60070023), "zlib_header", sx_p_zlib_header_fields, SX_COUNT(sx_p_zlib_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_zlib_dictionary_fields[] = {
    SX_FIELD("dictionary_adler32", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_p_zlib_dictionary = { UINT32_C(0x60070024), "zlib_dictionary", sx_p_zlib_dictionary_fields, SX_COUNT(sx_p_zlib_dictionary_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_zlib_trailer_fields[] = {
    SX_FIELD("adler32", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_p_zlib_trailer = { UINT32_C(0x60070025), "zlib_trailer", sx_p_zlib_trailer_fields, SX_COUNT(sx_p_zlib_trailer_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_lzma_header_fields[] = {
    SX_FIELD("properties", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("dictionary_size", "uint32", 1, 4, SX_SIZE),
    SX_FIELD("original_size", "uint64", 5, 8, SX_SIZE),
};
static const sx_layout sx_p_lzma_header = { UINT32_C(0x60070026), "lzma_header", sx_p_lzma_header_fields, SX_COUNT(sx_p_lzma_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lzma86_filter_fields[] = {
    SX_FIELD("filter", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_p_lzma86_filter = { UINT32_C(0x60070027), "lzma86_filter", sx_p_lzma86_filter_fields, SX_COUNT(sx_p_lzma86_filter_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_xar_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("header_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("toc_packed_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("toc_original_size", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("checksum_algorithm", "uint32", 24, 4, SX_ID),
};
static const sx_layout sx_p_xar_header = { UINT32_C(0x60070028), "xar_header", sx_p_xar_header_fields, SX_COUNT(sx_p_xar_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_rpm_lead_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("major", "uint8", 4, 1, SX_NONE),
    SX_FIELD("minor", "uint8", 5, 1, SX_NONE),
    SX_FIELD("package_type", "uint16", 6, 2, SX_ID),
    SX_FIELD("architecture", "uint16", 8, 2, SX_ID),
    SX_FIELD("name", "char[66]", 10, 66, SX_STRING),
    SX_FIELD("operating_system", "uint16", 76, 2, SX_ID),
    SX_FIELD("signature_type", "uint16", 78, 2, SX_ID),
    SX_FIELD("reserved", "bytes", 80, 16, SX_RESERVED),
};
static const sx_layout sx_p_rpm_lead = { UINT32_C(0x60070029), "rpm_lead", sx_p_rpm_lead_fields, SX_COUNT(sx_p_rpm_lead_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_rpm_header_fields[] = {
    SX_FIELD("magic", "bytes", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("reserved", "uint32", 4, 4, SX_RESERVED),
    SX_FIELD("index_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("data_size", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_p_rpm_header = { UINT32_C(0x6007002A), "rpm_header", sx_p_rpm_header_fields, SX_COUNT(sx_p_rpm_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_rpm_index_fields[] = {
    SX_FIELD("tag", "uint32", 0, 4, SX_ID),
    SX_FIELD("type", "uint32", 4, 4, SX_ID),
    SX_FIELD("data_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("count", "uint32", 12, 4, SX_COUNT_PROP),
};
static const sx_layout sx_p_rpm_index = { UINT32_C(0x6007002B), "rpm_index", sx_p_rpm_index_fields, SX_COUNT(sx_p_rpm_index_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_cfbf_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("clsid", "bytes", 8, 16, SX_ID),
    SX_FIELD("minor_version", "uint16", 24, 2, SX_NONE),
    SX_FIELD("major_version", "uint16", 26, 2, SX_NONE),
    SX_FIELD("byte_order", "uint16", 28, 2, SX_ID),
    SX_FIELD("sector_shift", "uint16", 30, 2, SX_NONE),
    SX_FIELD("mini_sector_shift", "uint16", 32, 2, SX_NONE),
    SX_FIELD("reserved", "bytes", 34, 6, SX_RESERVED),
    SX_FIELD("directory_sector_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("fat_sector_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("first_directory_sector", "uint32", 48, 4, SX_ID),
    SX_FIELD("transaction_signature", "uint32", 52, 4, SX_SIGNATURE),
    SX_FIELD("mini_stream_cutoff", "uint32", 56, 4, SX_SIZE),
    SX_FIELD("first_mini_fat_sector", "uint32", 60, 4, SX_ID),
    SX_FIELD("mini_fat_sector_count", "uint32", 64, 4, SX_COUNT_PROP),
    SX_FIELD("first_difat_sector", "uint32", 68, 4, SX_ID),
    SX_FIELD("difat_sector_count", "uint32", 72, 4, SX_COUNT_PROP),
};
static const sx_layout sx_p_cfbf_header = { UINT32_C(0x6007002C), "cfbf_header", sx_p_cfbf_header_fields, SX_COUNT(sx_p_cfbf_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_cfbf_sector_id_fields[] = {
    SX_FIELD("sector_id", "uint32", 0, 4, SX_ID),
};
static const sx_layout sx_p_cfbf_sector_id = { UINT32_C(0x6007002D), "cfbf_sector_id", sx_p_cfbf_sector_id_fields, SX_COUNT(sx_p_cfbf_sector_id_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_cfbf_directory_fields[] = {
    SX_FIELD("name_utf16", "bytes", 0, 64, SX_STRING),
    SX_FIELD("name_size", "uint16", 64, 2, SX_SIZE),
    SX_FIELD("object_type", "uint8", 66, 1, SX_ID),
    SX_FIELD("color", "uint8", 67, 1, SX_ID),
    SX_FIELD("left_sibling", "uint32", 68, 4, SX_ID),
    SX_FIELD("right_sibling", "uint32", 72, 4, SX_ID),
    SX_FIELD("child", "uint32", 76, 4, SX_ID),
    SX_FIELD("clsid", "bytes", 80, 16, SX_ID),
    SX_FIELD("state_bits", "uint32", 96, 4, SX_FLAGS),
    SX_FIELD("created", "uint64", 100, 8, SX_TIME),
    SX_FIELD("modified", "uint64", 108, 8, SX_TIME),
    SX_FIELD("first_sector", "uint32", 116, 4, SX_ID),
    SX_FIELD("stream_size", "uint64", 120, 8, SX_SIZE),
};
static const sx_layout sx_p_cfbf_directory = { UINT32_C(0x6007002E), "cfbf_directory", sx_p_cfbf_directory_fields, SX_COUNT(sx_p_cfbf_directory_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_chm_itsf2_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("unknown", "uint32", 12, 4, SX_NONE),
    SX_FIELD("timestamp", "uint32", 16, 4, SX_NONE),
    SX_FIELD("language_id", "uint32", 20, 4, SX_ID),
    SX_FIELD("directory_guid", "bytes", 24, 16, SX_ID),
    SX_FIELD("stream_guid", "bytes", 40, 16, SX_ID),
    SX_FIELD("section0_offset", "uint64", 56, 8, SX_OFFSET),
    SX_FIELD("section0_size", "uint64", 64, 8, SX_SIZE),
    SX_FIELD("directory_offset", "uint64", 72, 8, SX_OFFSET),
    SX_FIELD("directory_size", "uint64", 80, 8, SX_SIZE),
};
static const sx_layout sx_p_chm_itsf2 = { UINT32_C(0x6007002F), "chm_itsf2", sx_p_chm_itsf2_fields, SX_COUNT(sx_p_chm_itsf2_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_chm_itsf3_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("unknown", "uint32", 12, 4, SX_NONE),
    SX_FIELD("timestamp", "uint32", 16, 4, SX_NONE),
    SX_FIELD("language_id", "uint32", 20, 4, SX_ID),
    SX_FIELD("directory_guid", "bytes", 24, 16, SX_ID),
    SX_FIELD("stream_guid", "bytes", 40, 16, SX_ID),
    SX_FIELD("section0_offset", "uint64", 56, 8, SX_OFFSET),
    SX_FIELD("section0_size", "uint64", 64, 8, SX_SIZE),
    SX_FIELD("directory_offset", "uint64", 72, 8, SX_OFFSET),
    SX_FIELD("directory_size", "uint64", 80, 8, SX_SIZE),
    SX_FIELD("data_offset", "uint64", 88, 8, SX_OFFSET),
};
static const sx_layout sx_p_chm_itsf3 = { UINT32_C(0x60070030), "chm_itsf3", sx_p_chm_itsf3_fields, SX_COUNT(sx_p_chm_itsf3_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_chm_itsp_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("unknown_0", "uint32", 12, 4, SX_NONE),
    SX_FIELD("chunk_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("density", "uint32", 20, 4, SX_NONE),
    SX_FIELD("tree_depth", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("root_index", "int32", 28, 4, SX_ID),
    SX_FIELD("first_pmgl", "int32", 32, 4, SX_ID),
    SX_FIELD("last_pmgl", "int32", 36, 4, SX_ID),
    SX_FIELD("unknown_1", "int32", 40, 4, SX_NONE),
    SX_FIELD("chunk_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("language_id", "uint32", 48, 4, SX_ID),
    SX_FIELD("guid", "bytes", 52, 16, SX_ID),
    SX_FIELD("header_size_again", "uint32", 68, 4, SX_SIZE),
    SX_FIELD("unknown_2", "bytes", 72, 12, SX_NONE),
};
static const sx_layout sx_p_chm_itsp = { UINT32_C(0x60070031), "chm_itsp", sx_p_chm_itsp_fields, SX_COUNT(sx_p_chm_itsp_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_chm_pmgl_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("free_space", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("unknown", "uint32", 8, 4, SX_NONE),
    SX_FIELD("previous", "int32", 12, 4, SX_ID),
    SX_FIELD("next", "int32", 16, 4, SX_ID),
};
static const sx_layout sx_p_chm_pmgl = { UINT32_C(0x60070032), "chm_pmgl", sx_p_chm_pmgl_fields, SX_COUNT(sx_p_chm_pmgl_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_chm_pmgi_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("free_space", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_p_chm_pmgi = { UINT32_C(0x60070033), "chm_pmgi", sx_p_chm_pmgi_fields, SX_COUNT(sx_p_chm_pmgi_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_chm_section0_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("unknown", "uint32", 4, 4, SX_NONE),
    SX_FIELD("file_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("unknown_tail", "bytes", 16, 8, SX_NONE),
};
static const sx_layout sx_p_chm_section0 = { UINT32_C(0x60070034), "chm_section0", sx_p_chm_section0_fields, SX_COUNT(sx_p_chm_section0_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_tnef_header_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("key", "uint16", 4, 2, SX_ID),
};
static const sx_layout sx_p_tnef_header = { UINT32_C(0x60070035), "tnef_header", sx_p_tnef_header_fields, SX_COUNT(sx_p_tnef_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_tnef_attribute_fields[] = {
    SX_FIELD("level", "uint8", 0, 1, SX_ID),
    SX_FIELD("attribute_id", "uint32", 1, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 5, 4, SX_SIZE),
};
static const sx_layout sx_p_tnef_attribute = { UINT32_C(0x60070036), "tnef_attribute", sx_p_tnef_attribute_fields, SX_COUNT(sx_p_tnef_attribute_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_tnef_checksum_fields[] = {
    SX_FIELD("checksum", "uint16", 0, 2, SX_CHECKSUM),
};
static const sx_layout sx_p_tnef_checksum = { UINT32_C(0x60070037), "tnef_checksum", sx_p_tnef_checksum_fields, SX_COUNT(sx_p_tnef_checksum_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_wim_header_fields[] = {
    SX_FIELD("signature", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("version", "uint32", 12, 4, SX_NONE),
    SX_FIELD("flags", "uint32", 16, 4, SX_FLAGS),
    SX_FIELD("chunk_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("guid", "bytes", 24, 16, SX_ID),
    SX_FIELD("part_number", "uint16", 40, 2, SX_NONE),
    SX_FIELD("total_parts", "uint16", 42, 2, SX_COUNT_PROP),
    SX_FIELD("image_count", "uint32", 44, 4, SX_COUNT_PROP),
};
static const sx_layout sx_p_wim_header = { UINT32_C(0x60070038), "wim_header", sx_p_wim_header_fields, SX_COUNT(sx_p_wim_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_wim_resource_fields[] = {
    SX_FIELD("size_and_flags", "uint64", 0, 8, SX_FLAGS),
    SX_FIELD("offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("original_size", "uint64", 16, 8, SX_SIZE),
};
static const sx_layout sx_p_wim_resource = { UINT32_C(0x60070039), "wim_resource", sx_p_wim_resource_fields, SX_COUNT(sx_p_wim_resource_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_wim_boot_fields[] = {
    SX_FIELD("boot_index", "uint32", 0, 4, SX_ID),
};
static const sx_layout sx_p_wim_boot = { UINT32_C(0x6007003A), "wim_boot", sx_p_wim_boot_fields, SX_COUNT(sx_p_wim_boot_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_wim_blob_fields[] = {
    SX_FIELD("size_and_flags", "uint64", 0, 8, SX_FLAGS),
    SX_FIELD("offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("original_size", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("part_number", "uint16", 24, 2, SX_NONE),
    SX_FIELD("reference_count", "uint32", 26, 4, SX_COUNT_PROP),
    SX_FIELD("sha1", "bytes", 30, 20, SX_CHECKSUM),
};
static const sx_layout sx_p_wim_blob = { UINT32_C(0x6007003B), "wim_blob", sx_p_wim_blob_fields, SX_COUNT(sx_p_wim_blob_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_unix_compress_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("flags", "uint8", 2, 1, SX_FLAGS),
};
static const sx_layout sx_p_unix_compress_header = { UINT32_C(0x6007003C), "unix_compress_header", sx_p_unix_compress_header_fields, SX_COUNT(sx_p_unix_compress_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_unix_pack_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("original_size", "uint32", 2, 4, SX_SIZE),
};
static const sx_layout sx_p_unix_pack_header = { UINT32_C(0x6007003D), "unix_pack_header", sx_p_unix_pack_header_fields, SX_COUNT(sx_p_unix_pack_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_unix_pack_old_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("original_size_high", "uint16", 2, 2, SX_NONE),
    SX_FIELD("original_size_low", "uint16", 4, 2, SX_NONE),
};
static const sx_layout sx_p_unix_pack_old_header = { UINT32_C(0x6007003E), "unix_pack_old_header", sx_p_unix_pack_old_header_fields, SX_COUNT(sx_p_unix_pack_old_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_snappy_chunk_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("data_size", "uint24", 1, 3, SX_SIZE),
};
static const sx_layout sx_p_snappy_chunk = { UINT32_C(0x6007003F), "snappy_chunk", sx_p_snappy_chunk_fields, SX_COUNT(sx_p_snappy_chunk_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_snappy_crc_fields[] = {
    SX_FIELD("masked_crc32c", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_p_snappy_crc = { UINT32_C(0x60070040), "snappy_crc", sx_p_snappy_crc_fields, SX_COUNT(sx_p_snappy_crc_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_mar_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("index_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sx_p_mar_header = { UINT32_C(0x60070041), "mar_header", sx_p_mar_header_fields, SX_COUNT(sx_p_mar_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_mar_index_fields[] = {
    SX_FIELD("index_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_p_mar_index = { UINT32_C(0x60070042), "mar_index", sx_p_mar_index_fields, SX_COUNT(sx_p_mar_index_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_mar_entry_fields[] = {
    SX_FIELD("data_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("data_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
};
static const sx_layout sx_p_mar_entry = { UINT32_C(0x60070043), "mar_entry", sx_p_mar_entry_fields, SX_COUNT(sx_p_mar_entry_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_pak_header4_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_NONE),
    SX_FIELD("resource_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("encoding", "uint8", 8, 1, SX_ID),
};
static const sx_layout sx_p_pak_header4 = { UINT32_C(0x60070044), "pak_header4", sx_p_pak_header4_fields, SX_COUNT(sx_p_pak_header4_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_pak_header5_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_NONE),
    SX_FIELD("encoding", "uint8", 4, 1, SX_ID),
    SX_FIELD("reserved", "bytes", 5, 3, SX_RESERVED),
    SX_FIELD("resource_count", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("alias_count", "uint16", 10, 2, SX_COUNT_PROP),
};
static const sx_layout sx_p_pak_header5 = { UINT32_C(0x60070045), "pak_header5", sx_p_pak_header5_fields, SX_COUNT(sx_p_pak_header5_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_pak_resource_fields[] = {
    SX_FIELD("resource_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("data_offset", "uint32", 2, 4, SX_OFFSET),
};
static const sx_layout sx_p_pak_resource = { UINT32_C(0x60070046), "pak_resource", sx_p_pak_resource_fields, SX_COUNT(sx_p_pak_resource_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_pak_alias_fields[] = {
    SX_FIELD("resource_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("resource_index", "uint16", 2, 2, SX_ID),
};
static const sx_layout sx_p_pak_alias = { UINT32_C(0x60070047), "pak_alias", sx_p_pak_alias_fields, SX_COUNT(sx_p_pak_alias_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_xpak_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("archive_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("name", "char[13]", 8, 13, SX_STRING),
    SX_FIELD("original_size", "uint32", 21, 4, SX_SIZE),
};
static const sx_layout sx_p_xpak_header = { UINT32_C(0x60070048), "xpak_header", sx_p_xpak_header_fields, SX_COUNT(sx_p_xpak_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_xpak_codec_fields[] = {
    SX_FIELD("hash_size_parameter", "uint8", 0, 1, SX_NONE),
    SX_FIELD("magic", "uint16", 1, 2, SX_SIGNATURE),
    SX_FIELD("window_size", "uint16", 3, 2, SX_SIZE),
    SX_FIELD("max_match", "uint16", 5, 2, SX_SIZE),
    SX_FIELD("model_rescale_limit", "uint16", 7, 2, SX_NONE),
};
static const sx_layout sx_p_xpak_codec = { UINT32_C(0x60070049), "xpak_codec", sx_p_xpak_codec_fields, SX_COUNT(sx_p_xpak_codec_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_pp20_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("efficiency", "bytes", 4, 4, SX_NONE),
};
static const sx_layout sx_p_pp20_header = { UINT32_C(0x6007004A), "pp20_header", sx_p_pp20_header_fields, SX_COUNT(sx_p_pp20_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_pp20_trailer_fields[] = {
    SX_FIELD("original_size", "uint24", 0, 3, SX_SIZE),
    SX_FIELD("skip_bits", "uint8", 3, 1, SX_COUNT_PROP),
};
static const sx_layout sx_p_pp20_trailer = { UINT32_C(0x6007004B), "pp20_trailer", sx_p_pp20_trailer_fields, SX_COUNT(sx_p_pp20_trailer_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_dvi_preamble_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("version", "uint8", 1, 1, SX_ID),
    SX_FIELD("numerator", "uint32", 2, 4, SX_NONE),
    SX_FIELD("denominator", "uint32", 6, 4, SX_NONE),
    SX_FIELD("magnification", "uint32", 10, 4, SX_NONE),
    SX_FIELD("comment_size", "uint8", 14, 1, SX_SIZE),
};
static const sx_layout sx_p_dvi_preamble = { UINT32_C(0x6007004C), "dvi_preamble", sx_p_dvi_preamble_fields, SX_COUNT(sx_p_dvi_preamble_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_dvi_postamble_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("last_page", "int32", 1, 4, SX_OFFSET),
    SX_FIELD("numerator", "uint32", 5, 4, SX_NONE),
    SX_FIELD("denominator", "uint32", 9, 4, SX_NONE),
    SX_FIELD("magnification", "uint32", 13, 4, SX_NONE),
    SX_FIELD("max_height", "uint32", 17, 4, SX_NONE),
    SX_FIELD("max_width", "uint32", 21, 4, SX_NONE),
    SX_FIELD("max_stack_depth", "uint16", 25, 2, SX_COUNT_PROP),
    SX_FIELD("page_count", "uint16", 27, 2, SX_COUNT_PROP),
};
static const sx_layout sx_p_dvi_postamble = { UINT32_C(0x6007004D), "dvi_postamble", sx_p_dvi_postamble_fields, SX_COUNT(sx_p_dvi_postamble_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_dvi_post_post_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("postamble_offset", "uint32", 1, 4, SX_OFFSET),
    SX_FIELD("version", "uint8", 5, 1, SX_ID),
};
static const sx_layout sx_p_dvi_post_post = { UINT32_C(0x6007004E), "dvi_post_post", sx_p_dvi_post_post_fields, SX_COUNT(sx_p_dvi_post_post_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_zoo_attributes_fields[] = {
    SX_FIELD("system_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("attributes", "uint24", 2, 3, SX_FLAGS),
};
static const sx_layout sx_p_zoo_attributes = { UINT32_C(0x6007004F), "zoo_attributes", sx_p_zoo_attributes_fields, SX_COUNT(sx_p_zoo_attributes_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_unix_mode_fields[] = {
    SX_FIELD("mode", "uint16", 0, 2, SX_FLAGS),
};
static const sx_layout sx_p_lha_unix_mode = { UINT32_C(0x60070050), "lha_unix_mode", sx_p_lha_unix_mode_fields, SX_COUNT(sx_p_lha_unix_mode_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_lha_sizes64_fields[] = {
    SX_FIELD("packed_size", "uint64", 0, 8, SX_SIZE),
    SX_FIELD("original_size", "uint64", 8, 8, SX_SIZE),
};
static const sx_layout sx_p_lha_sizes64 = { UINT32_C(0x60070051), "lha_sizes64", sx_p_lha_sizes64_fields, SX_COUNT(sx_p_lha_sizes64_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_pp20_library_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("hunk_original_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("efficiency", "bytes", 8, 4, SX_NONE),
};
static const sx_layout sx_p_pp20_library_header = { UINT32_C(0x60070052), "pp20_library_header", sx_p_pp20_library_header_fields, SX_COUNT(sx_p_pp20_library_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_pp20_encrypted_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("password_checksum", "uint16", 4, 2, SX_CHECKSUM),
    SX_FIELD("efficiency", "bytes", 6, 4, SX_NONE),
};
static const sx_layout sx_p_pp20_encrypted_header = { UINT32_C(0x60070053), "pp20_encrypted_header", sx_p_pp20_encrypted_header_fields, SX_COUNT(sx_p_pp20_encrypted_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_mar_signed_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("index_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("file_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("signature_count", "uint32", 16, 4, SX_COUNT_PROP),
};
static const sx_layout sx_p_mar_signed_header = { UINT32_C(0x60070054), "mar_signed_header", sx_p_mar_signed_header_fields, SX_COUNT(sx_p_mar_signed_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_mar_signature_fields[] = {
    SX_FIELD("algorithm", "uint32", 0, 4, SX_ID),
    SX_FIELD("signature_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_p_mar_signature = { UINT32_C(0x60070055), "mar_signature", sx_p_mar_signature_fields, SX_COUNT(sx_p_mar_signature_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_mar_sections_fields[] = {
    SX_FIELD("section_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sx_p_mar_sections = { UINT32_C(0x60070056), "mar_sections", sx_p_mar_sections_fields, SX_COUNT(sx_p_mar_sections_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_mar_section_fields[] = {
    SX_FIELD("section_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("section_id", "uint32", 4, 4, SX_ID),
};
static const sx_layout sx_p_mar_section = { UINT32_C(0x60070057), "mar_section", sx_p_mar_section_fields, SX_COUNT(sx_p_mar_section_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_pack_tree_fields[] = {
    SX_FIELD("maximum_code_length", "uint8", 0, 1, SX_COUNT_PROP),
};
static const sx_layout sx_p_pack_tree = { UINT32_C(0x60070058), "pack_tree", sx_p_pack_tree_fields, SX_COUNT(sx_p_pack_tree_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_pack_level_fields[] = {
    SX_FIELD("stored_code_count", "uint8", 0, 1, SX_COUNT_PROP),
};
static const sx_layout sx_p_pack_level = { UINT32_C(0x60070059), "pack_level", sx_p_pack_level_fields, SX_COUNT(sx_p_pack_level_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_pack_literal_fields[] = {
    SX_FIELD("literal", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_p_pack_literal = { UINT32_C(0x6007005A), "pack_literal", sx_p_pack_literal_fields, SX_COUNT(sx_p_pack_literal_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_dvi_page_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("count0", "int32", 1, 4, SX_NONE),
    SX_FIELD("count1", "int32", 5, 4, SX_NONE),
    SX_FIELD("count2", "int32", 9, 4, SX_NONE),
    SX_FIELD("count3", "int32", 13, 4, SX_NONE),
    SX_FIELD("count4", "int32", 17, 4, SX_NONE),
    SX_FIELD("count5", "int32", 21, 4, SX_NONE),
    SX_FIELD("count6", "int32", 25, 4, SX_NONE),
    SX_FIELD("count7", "int32", 29, 4, SX_NONE),
    SX_FIELD("count8", "int32", 33, 4, SX_NONE),
    SX_FIELD("count9", "int32", 37, 4, SX_NONE),
    SX_FIELD("previous_page", "int32", 41, 4, SX_OFFSET),
};
static const sx_layout sx_p_dvi_page = { UINT32_C(0x6007005B), "dvi_page", sx_p_dvi_page_fields, SX_COUNT(sx_p_dvi_page_fields), SX_BE };

static const xx_data_struct_field_desc sx_p_pack_old_tree_fields[] = {
    SX_FIELD("entry_count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sx_p_pack_old_tree = { UINT32_C(0x6007005C), "pack_old_tree", sx_p_pack_old_tree_fields, SX_COUNT(sx_p_pack_old_tree_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_pack_old_node_fields[] = {
    SX_FIELD("value", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sx_p_pack_old_node = { UINT32_C(0x6007005D), "pack_old_node", sx_p_pack_old_node_fields, SX_COUNT(sx_p_pack_old_node_fields), SX_LE };

static const xx_data_struct_field_desc sx_p_pack_old_wide_node_fields[] = {
    SX_FIELD("marker", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("value", "uint16", 1, 2, SX_NONE),
};
static const sx_layout sx_p_pack_old_wide_node = { UINT32_C(0x6007005E), "pack_old_wide_node", sx_p_pack_old_wide_node_fields, SX_COUNT(sx_p_pack_old_wide_node_fields), SX_LE };

static const sx_layout *const sx_package_layouts[] = {
    &sx_p_arj_prefix,
    &sx_p_arj_main,
    &sx_p_arj_file,
    &sx_p_crc32,
    &sx_p_crc16,
    &sx_p_length16,
    &sx_p_ace_main,
    &sx_p_ace_generic,
    &sx_p_ace_file32,
    &sx_p_ace_file64,
    &sx_p_alz_header,
    &sx_p_alz_file,
    &sx_p_alz_sizes1,
    &sx_p_alz_sizes2,
    &sx_p_alz_sizes3,
    &sx_p_alz_sizes4,
    &sx_p_alz_sizes5,
    &sx_p_alz_sizes6,
    &sx_p_alz_sizes7,
    &sx_p_alz_sizes8,
    &sx_p_ha_header,
    &sx_p_ha_file,
    &sx_p_ha_machine,
    &sx_p_zoo_header,
    &sx_p_zoo_directory,
    &sx_p_zoo_variable,
    &sx_p_lha_level0,
    &sx_p_lha_level1,
    &sx_p_lha_level2,
    &sx_p_lha_level3,
    &sx_p_lha_extension2,
    &sx_p_lha_extension4,
    &sx_p_lha_os,
    &sx_p_length32,
    &sx_p_zlib_header,
    &sx_p_zlib_dictionary,
    &sx_p_zlib_trailer,
    &sx_p_lzma_header,
    &sx_p_lzma86_filter,
    &sx_p_xar_header,
    &sx_p_rpm_lead,
    &sx_p_rpm_header,
    &sx_p_rpm_index,
    &sx_p_cfbf_header,
    &sx_p_cfbf_sector_id,
    &sx_p_cfbf_directory,
    &sx_p_chm_itsf2,
    &sx_p_chm_itsf3,
    &sx_p_chm_itsp,
    &sx_p_chm_pmgl,
    &sx_p_chm_pmgi,
    &sx_p_chm_section0,
    &sx_p_tnef_header,
    &sx_p_tnef_attribute,
    &sx_p_tnef_checksum,
    &sx_p_wim_header,
    &sx_p_wim_resource,
    &sx_p_wim_boot,
    &sx_p_wim_blob,
    &sx_p_unix_compress_header,
    &sx_p_unix_pack_header,
    &sx_p_unix_pack_old_header,
    &sx_p_snappy_chunk,
    &sx_p_snappy_crc,
    &sx_p_mar_header,
    &sx_p_mar_index,
    &sx_p_mar_entry,
    &sx_p_pak_header4,
    &sx_p_pak_header5,
    &sx_p_pak_resource,
    &sx_p_pak_alias,
    &sx_p_xpak_header,
    &sx_p_xpak_codec,
    &sx_p_pp20_header,
    &sx_p_pp20_trailer,
    &sx_p_dvi_preamble,
    &sx_p_dvi_postamble,
    &sx_p_dvi_post_post,
    &sx_p_zoo_attributes,
    &sx_p_lha_unix_mode,
    &sx_p_lha_sizes64,
    &sx_p_pp20_library_header,
    &sx_p_pp20_encrypted_header,
    &sx_p_mar_signed_header,
    &sx_p_mar_signature,
    &sx_p_mar_sections,
    &sx_p_mar_section,
    &sx_p_pack_tree,
    &sx_p_pack_level,
    &sx_p_pack_literal,
    &sx_p_dvi_page,
    &sx_p_pack_old_tree,
    &sx_p_pack_old_node,
    &sx_p_pack_old_wide_node,
};
/* Arithmetic is relative to the selected format base. Sector IDs, bit counts
 * and packed flags are deliberately not labelled byte offsets or byte sizes. */
static bool sx_p_span(sx_context *c,uint64_t off,uint64_t size) { return off<=(uint64_t)c->size&&size<=(uint64_t)c->size-off; }
static bool sx_p_sig(sx_context *c,int64_t off,const char *sig,size_t n) { uint8_t b[16];return n<=sizeof(b)&&sx_read(c,off,b,n)&&!xx_rt_memcmp(b,sig,n); }
static bool sx_p_byte(sx_context *c,int64_t off,uint8_t *v) {return sx_read(c,off,v,1);}
static bool sx_p_uint(sx_context *c,int64_t off,unsigned n,uint64_t *v) {uint8_t b[8];if(!n||n>8||!sx_read(c,off,b,n))return false;*v=0;for(unsigned i=0;i<n;i++)*v|=(uint64_t)b[i]<<(8*i);return true;}
static bool sx_p_zstring(sx_context *c,int64_t *off,int64_t end) {uint8_t b;while(*off<end){if(!sx_p_byte(c,(*off)++,&b))return false;if(!b)return true;}return false;}
/* Sort non-overlapping metadata and fill every other physical byte as raw.
 * Linked metadata may arrive out of order; overlaps are malformed, not views. */
static bool sx_p_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;
    for(size_t gap=n/2;gap;gap/=2)for(size_t i=gap;i<n;i++){xx_data_struct item=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=item;}
    for(size_t i=0;i<n;i++){int64_t off=c->items[i].offset-c->f->base_address,total=c->items[i].total_size;if(off<end||!sx_p_span(c,(uint64_t)off,(uint64_t)total)||!sx_raw(c,end,off-end))return false;end=off+total;}
    if(!sx_raw(c,end,c->size-end))return false;
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){xx_data_struct item=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=item;}
    return true;
}
static bool sx_p_arj(sx_context *c)
{
    int64_t off=0;bool main=true;
    while(off<c->size){uint16_t n;uint64_t packed=0;uint8_t first;
        if(!sx_p_sig(c,off,"\x60\xea",2)||!sx_u16(c,off+2,false,&n)||!sx_add(c,&sx_p_arj_prefix,off,4))return false;
        if(!n)return off+4==c->size;
        if(n<30||n>2600||!sx_p_span(c,off+4,(uint64_t)n+4)||!sx_p_byte(c,off+4,&first)||first<30||first>=n)return false;
        if(!sx_add(c,main?&sx_p_arj_main:&sx_p_arj_file,off+4,30)||!sx_add(c,&sx_p_crc32,off+4+n,4))return false;
        if(!main&&!sx_p_uint(c,off+16,4,&packed))return false;
        int64_t str=off+4+first;if(!sx_p_zstring(c,&str,off+4+n))return false;
        off+=8+n;
        for(;;){uint16_t ext;if(!sx_u16(c,off,false,&ext)||!sx_add(c,&sx_p_length16,off,2))return false;off+=2;if(!ext)break;if(!sx_p_span(c,off,(uint64_t)ext+4)||!sx_add(c,&sx_p_crc32,off+ext,4))return false;off+=ext+4;}
        if(!sx_p_span(c,off,packed))return false;off+=(int64_t)packed;main=false;
    }
    return !main;
}
static bool sx_p_ace(sx_context *c)
{
    int64_t off=0;bool first=true;
    while(off<c->size){uint16_t n,flags;uint8_t type;uint64_t packed=0;
        if(!sx_u16(c,off+2,false,&n)||n<3||!sx_u16(c,off+5,false,&flags)||!sx_p_byte(c,off+4,&type)||!sx_p_span(c,off,(uint64_t)n+4))return false;
        const sx_layout *l=&sx_p_ace_generic;int size=7;
        if(first){if(type||n<27||!sx_p_sig(c,off+7,"**ACE**",7))return false;l=&sx_p_ace_main;size=31;}
        else if(type==1||type==3){bool wide=(flags&4)!=0;uint16_t names;size=wide?43:35;l=wide?&sx_p_ace_file64:&sx_p_ace_file32;if(!(flags&1)||(type==1&&wide)||(type==3&&!wide)||n+4<size||!sx_u16(c,off+size-2,false,&names)||names>n+4-size||!sx_p_uint(c,off+7,wide?8:4,&packed))return false;}
        else if(flags&1){if(n<3+((flags&4)?8:4)||!sx_p_uint(c,off+7,(flags&4)?8:4,&packed))return false;}
        if(!sx_add(c,l,off,size))return false;off+=n+4;if(!sx_p_span(c,off,packed))return false;off+=(int64_t)packed;first=false;
    }return !first;
}
static bool sx_p_alz(sx_context *c)
{
    if(!sx_p_sig(c,0,"ALZ\1",4)||!sx_add(c,&sx_p_alz_header,0,8))return false;
    int64_t off=8;while(off<c->size){uint32_t magic;if(!sx_u32(c,off,false,&magic))return false;
        if(magic==0x015a4c43){if(!sx_p_span(c,off,12))return false;off+=12;continue;}if(magic==0x025a4c43){off+=4;continue;}if(magic!=0x015a4c42)return false;
        uint16_t name;uint8_t descriptor;uint64_t packed=0;
        if(!sx_u16(c,off+4,false,&name)||!sx_p_byte(c,off+11,&descriptor)||!sx_add(c,&sx_p_alz_file,off,13))return false;off+=13;
        unsigned width=descriptor>>4;if(width>8)return false;
        if(width){const sx_layout *rows[]={&sx_p_alz_sizes1,&sx_p_alz_sizes2,&sx_p_alz_sizes3,&sx_p_alz_sizes4,&sx_p_alz_sizes5,&sx_p_alz_sizes6,&sx_p_alz_sizes7,&sx_p_alz_sizes8};if(!sx_add(c,rows[width-1],off,6+2*width)||!sx_p_uint(c,off+6,width,&packed))return false;off+=6+2*width;}
        if(!sx_p_span(c,off,name))return false;off+=name;if(!sx_p_span(c,off,packed))return false;off+=(int64_t)packed;
    }return true;
}
static bool sx_p_ha(sx_context *c)
{
    uint16_t count;if(!sx_p_sig(c,0,"HA",2)||!sx_u16(c,2,false,&count)||!sx_add(c,&sx_p_ha_header,0,4))return false;int64_t off=4;
    for(unsigned i=0;i<count;i++){uint32_t packed;uint8_t machine;if(!sx_u32(c,off+1,false,&packed)||!sx_add(c,&sx_p_ha_file,off,17))return false;off+=17;if(!sx_p_zstring(c,&off,c->size)||!sx_p_zstring(c,&off,c->size)||!sx_p_byte(c,off,&machine)||!sx_add(c,&sx_p_ha_machine,off,1))return false;off++;if(!sx_p_span(c,off,(uint64_t)machine+packed))return false;off+=(int64_t)machine+packed;}
    return off==c->size;
}
static bool sx_p_zoo(sx_context *c)
{
    uint32_t magic,first;if(!sx_u32(c,20,false,&magic)||magic!=0xfdc4a7dc||!sx_u32(c,24,false,&first)||!sx_add(c,&sx_p_zoo_header,0,34))return false;int64_t off=first;
    for(unsigned steps=0;off&&steps<100000;steps++) {uint8_t type;uint32_t next,data,packed,comment;uint16_t comment_size;
        if(!sx_u32(c,off,false,&magic)||magic!=0xfdc4a7dc||!sx_p_byte(c,off+4,&type)||!sx_u32(c,off+6,false,&next)||!sx_u32(c,off+10,false,&data)||!sx_u32(c,off+24,false,&packed)||!sx_u32(c,off+32,false,&comment)||!sx_u16(c,off+36,false,&comment_size)||!sx_add(c,&sx_p_zoo_directory,off,51)||!sx_p_span(c,data,packed)||!sx_p_span(c,comment,comment_size))return false;
        if(type==2){uint16_t n;uint8_t name,dir;if(!sx_u16(c,off+51,false,&n)||!sx_p_span(c,off+53,n))return false;
            if(n>=5){if(!sx_read(c,off+56,&name,1)||!sx_read(c,off+57,&dir,1)||(unsigned)name+dir>n-5||!sx_add(c,&sx_p_zoo_variable,off+51,7))return false;if(n>=10+name+dir&&!sx_add(c,&sx_p_zoo_attributes,off+58+name+dir,5))return false;}
            else if(!sx_add(c,&sx_p_length16,off+51,2))return false;
        }else if(type!=1)return false;
        if(!next)return true;if(next<=off)return false;off=next;
    }return off==0;
}
static bool sx_p_lha(sx_context *c)
{
    int64_t off=0;while(off<c->size){uint8_t h[28],first;if(!sx_p_byte(c,off,&first))return false;if(!first&&c->size-off<22)return true;if(!sx_read(c,off,h,22)||h[2]!='-'||h[6]!='-')return false;
        unsigned level=h[20],word=2;uint32_t packed=xx_data_get_u32(h,22,7,false);int64_t base,chain=-1,end;
        const sx_layout *l;int fixed;
        if(level<2){base=h[0]+2;fixed=22;l=level?&sx_p_lha_level1:&sx_p_lha_level0;if(base<24+h[21]+(level?3:0)||!sx_p_span(c,off,base)||!sx_add(c,&sx_p_crc16,off+22+h[21],2))return false;if(level){if(!sx_add(c,&sx_p_lha_os,off+24+h[21],1))return false;chain=base-2;}}
        else {if(!sx_read(c,off,h,level==3?28:24))return false;fixed=level==2?24:28;l=level==2?&sx_p_lha_level2:&sx_p_lha_level3;if(level==2){base=xx_data_get_u16(h,28,0,false)+(h[23]=='K'?2:0);chain=24;}else if(level==3&&xx_data_get_u16(h,28,0,false)==4){base=xx_data_get_u32(h,28,24,false);chain=28;word=4;}else return false;if(base<fixed+word||!sx_p_span(c,off,base))return false;}
        if(!sx_add(c,l,off,fixed))return false;end=base;
        if(chain>=0)for(;;){uint64_t n;if(!sx_p_uint(c,off+chain,word,&n))return false;if(!n){if(!sx_add(c,word==2?&sx_p_length16:&sx_p_length32,off+chain,word))return false;break;}if(n<word+1||n>INT32_MAX)return false;if(level==1){if(n>packed||!sx_p_span(c,off+end,n))return false;packed-=(uint32_t)n;end+=(int64_t)n;}else if(n>(uint64_t)(base-chain-word))return false;if(!sx_add(c,word==2?&sx_p_lha_extension2:&sx_p_lha_extension4,off+chain,word+1))return false;
        uint8_t type;if(!sx_p_byte(c,off+chain+word,&type))return false;int64_t data=off+chain+word+1;uint64_t amount=n-word-1;
        if(type==0&&amount>=2){if(!sx_add(c,&sx_p_crc16,data,2))return false;}else if(type==0x50&&amount>=2){if(!sx_add(c,&sx_p_lha_unix_mode,data,2))return false;}else if(type==0x42&&amount>=16){if(!sx_add(c,&sx_p_lha_sizes64,data,16))return false;}
        chain+=(int64_t)n;}
        if(!sx_p_span(c,off+end,packed))return false;off+=end+packed;
    }return true;
}
static bool sx_p_rpm_header_at(sx_context *c,int64_t *off)
{
    uint32_t count,size;if(!sx_p_sig(c,*off,"\x8e\xad\xe8\1",4)||!sx_u32(c,*off+8,true,&count)||!count||count>65535||!sx_u32(c,*off+12,true,&size)||!sx_add(c,&sx_p_rpm_header,*off,16))return false;*off+=16;
    if(!sx_table(c,&sx_p_rpm_index,*off,16,count))return false;int64_t store=*off+(int64_t)count*16;if(!sx_p_span(c,store,size))return false;
    for(uint32_t i=0;i<count;i++){uint32_t type,at,n;if(!sx_u32(c,*off+16*i+4,true,&type)||type>9||!sx_u32(c,*off+16*i+8,true,&at)||!sx_u32(c,*off+16*i+12,true,&n)||at>size)return false;unsigned unit=type==3?2:type==4?4:type==5?8:1;if(type!=0&&type!=6&&type!=8&&type!=9&&(uint64_t)n*unit>size-at)return false;}
    *off=store+size;return true;
}
static bool sx_p_rpm(sx_context *c)
{
    uint16_t sig;if(!sx_p_sig(c,0,"\xed\xab\xee\xdb",4)||!sx_u16(c,78,true,&sig)||!sx_add(c,&sx_p_rpm_lead,0,96))return false;int64_t off=96;
    if(sig==5){if(!sx_p_rpm_header_at(c,&off))return false;off=(off+7)&~INT64_C(7);}else if(sig==1)off+=256;else if(sig)return false;
    return sx_p_rpm_header_at(c,&off);
}
static bool sx_p_cfbf(sx_context *c)
{
    uint16_t major,shift;uint32_t dir,fats;
    if(!sx_p_sig(c,0,"\xd0\xcf\x11\xe0\xa1\xb1\x1a\xe1",8)||!sx_u16(c,26,false,&major)||!sx_p_sig(c,28,"\xfe\xff",2)||!sx_u16(c,30,false,&shift)||!((major==3&&shift==9)||(major==4&&shift==12))||!sx_u32(c,44,false,&fats)||!sx_u32(c,48,false,&dir)||!sx_add(c,&sx_p_cfbf_header,0,76)||!sx_table(c,&sx_p_cfbf_sector_id,76,4,109))return false;
    uint64_t sector=UINT64_C(1)<<shift;if(!sx_p_span(c,0,sector))return false;
    /* Inline DIFAT permits bounded FAT lookup. Extended DIFAT chains remain
     * raw in this revision instead of claiming a complete storage walk. */
    if(fats>109)return true;
    for(uint32_t i=0;i<fats;i++){uint32_t id;if(!sx_u32(c,76+4*i,false,&id)||id>=0xfffffffa||!sx_table(c,&sx_p_cfbf_sector_id,(int64_t)((uint64_t)(id+1)*sector),4,sector/4))return false;}
    uint64_t max=(uint64_t)c->size/sector;
    for(uint64_t seen=0;dir<0xfffffffa&&seen<max;seen++){uint64_t loc=(uint64_t)(dir+1)*sector;if(!sx_table(c,&sx_p_cfbf_directory,(int64_t)loc,128,sector/128))return false;uint64_t fi=dir/(sector/4);uint32_t fat,next;if(fi>=fats||!sx_u32(c,76+(int64_t)fi*4,false,&fat)||!sx_u32(c,(int64_t)((uint64_t)(fat+1)*sector+(dir%(sector/4))*4),false,&next))return false;if(next==0xfffffffe)return true;if(next==dir)return false;dir=next;}
    return dir==0xfffffffe;
}
static bool sx_p_chm(sx_context *c)
{
    uint32_t v,hs,chunk,count;uint64_t section,section_size,dir,dir_size;
    if(!sx_p_sig(c,0,"ITSF",4)||!sx_u32(c,4,false,&v)||(v!=2&&v!=3)||!sx_u32(c,8,false,&hs)||hs!=(v==3?96:88)||!sx_add(c,v==3?&sx_p_chm_itsf3:&sx_p_chm_itsf2,0,hs)||!sx_u64(c,56,false,&section)||!sx_u64(c,64,false,&section_size)||section_size<24||!sx_p_span(c,section,section_size)||!sx_add(c,&sx_p_chm_section0,(int64_t)section,24)||!sx_u64(c,72,false,&dir)||!sx_u64(c,80,false,&dir_size)||dir_size<84||!sx_p_span(c,dir,dir_size)||!sx_p_sig(c,dir,"ITSP",4)||!sx_u32(c,dir+16,false,&chunk)||chunk<20||!sx_u32(c,dir+44,false,&count)||(uint64_t)count*chunk>dir_size-84||!sx_add(c,&sx_p_chm_itsp,dir,84))return false;
    int64_t off=(int64_t)dir+84;for(uint32_t i=0;i<count;i++,off+=chunk){uint32_t free;if(!sx_u32(c,off+4,false,&free)||free>chunk)return false;if(sx_p_sig(c,off,"PMGL",4)){if(free>chunk-20||!sx_add(c,&sx_p_chm_pmgl,off,20))return false;}else if(sx_p_sig(c,off,"PMGI",4)){if(free>chunk-8||!sx_add(c,&sx_p_chm_pmgi,off,8))return false;}else return false;}return true;
}
static bool sx_p_tnef(sx_context *c)
{
    if(!sx_p_sig(c,0,"\x78\x9f\x3e\x22",4)||!sx_add(c,&sx_p_tnef_header,0,6))return false;int64_t off=6;
    while(off<c->size){uint8_t level;uint32_t n;if(!sx_p_byte(c,off,&level)||(level!=1&&level!=2)||!sx_u32(c,off+5,false,&n)||!sx_add(c,&sx_p_tnef_attribute,off,9))return false;off+=9;if(!sx_p_span(c,off,(uint64_t)n+2)||!sx_add(c,&sx_p_tnef_checksum,off+n,2))return false;off+=n+2;}return true;
}
static bool sx_p_wim(sx_context *c)
{
    uint32_t size;if(!sx_p_sig(c,0,"MSWIM\0\0\0",8)||!sx_u32(c,8,false,&size)||size<116||size>208||!sx_p_span(c,0,size)||!sx_add(c,&sx_p_wim_header,0,48))return false;
    int offs[]={48,72,96,124};for(unsigned i=0;i<4;i++)if(size>=(unsigned)offs[i]+24){uint64_t sf,off;if(!sx_add(c,&sx_p_wim_resource,offs[i],24)||!sx_u64(c,offs[i],false,&sf)||!sx_u64(c,offs[i]+8,false,&off))return false;uint64_t packed=sf&UINT64_C(0x00ffffffffffffff);if(i<2&&!sx_p_span(c,off,packed))return false;if(i==0&&packed&&!(sf>>56&4)){if(packed%50||!sx_table(c,&sx_p_wim_blob,(int64_t)off,50,packed/50))return false;}}
    return size<124||sx_add(c,&sx_p_wim_boot,120,4);
}
static bool sx_p_snappy(sx_context *c)
{
    int64_t off=0;bool first=true;while(off<c->size){uint8_t type,b[3];if(!sx_p_byte(c,off,&type)||!sx_read(c,off+1,b,3))return false;uint32_t n=b[0]|(uint32_t)b[1]<<8|(uint32_t)b[2]<<16;if(!sx_add(c,&sx_p_snappy_chunk,off,4)||!sx_p_span(c,off+4,n)||(first&&type!=255))return false;off+=4;if(type==255){if(n!=6||!sx_p_sig(c,off,"sNaPpY",6))return false;}else if(type<=1){if(n<4||!sx_add(c,&sx_p_snappy_crc,off,4))return false;}else if(type<128)return false;off+=n;first=false;}return !first;
}
static bool sx_p_mar(sx_context *c)
{
    uint32_t index,size;uint64_t declared=0;int64_t data_start=8;
    if(!sx_p_sig(c,0,"MAR1",4)||!sx_u32(c,4,true,&index)||index<8||!sx_u32(c,index,true,&size)||!sx_p_span(c,(uint64_t)index+4,size))return false;
    uint64_t archive_size=(uint64_t)index+4+size;
    if(index>=24&&!sx_u64(c,8,true,&declared))return false;
    if(declared==archive_size){uint32_t signatures,sections;
        if(!sx_u32(c,16,true,&signatures)||signatures>8||!sx_add(c,&sx_p_mar_signed_header,0,20))return false;data_start=20;
        for(uint32_t i=0;i<signatures;i++){uint32_t n;if(data_start>index-8||!sx_u32(c,data_start+4,true,&n)||n>2048||n>index-data_start-8||!sx_add(c,&sx_p_mar_signature,data_start,8))return false;data_start+=8+n;}
        if(data_start>index-4||!sx_u32(c,data_start,true,&sections)||sections>1024||!sx_add(c,&sx_p_mar_sections,data_start,4))return false;data_start+=4;
        for(uint32_t i=0;i<sections;i++){uint32_t n;if(data_start>index-8||!sx_u32(c,data_start,true,&n)||n<8||n>index-data_start||!sx_add(c,&sx_p_mar_section,data_start,8))return false;data_start+=n;}
    }else if(!sx_add(c,&sx_p_mar_header,0,8))return false;
    if(!sx_add(c,&sx_p_mar_index,index,4))return false;int64_t off=(int64_t)index+4,end=off+size;
    while(off<end){uint32_t data,n;if(end-off<13||!sx_u32(c,off,true,&data)||!sx_u32(c,off+4,true,&n)||data>index||n>index-data||(n&&data<(uint64_t)data_start)||!sx_add(c,&sx_p_mar_entry,off,12))return false;off+=12;if(!sx_p_zstring(c,&off,end))return false;}return off==end;
}
static bool sx_p_pak(sx_context *c)
{
    uint32_t v,count,previous=0;uint16_t n,aliases=0;uint8_t enc;int64_t header;
    if(!sx_u32(c,0,false,&v))return false;
    if(v==4){header=9;if(!sx_u32(c,4,false,&count)||!sx_p_byte(c,8,&enc)||!sx_add(c,&sx_p_pak_header4,0,9))return false;}else if(v==5){header=12;if(!sx_u16(c,8,false,&n)||!sx_u16(c,10,false,&aliases)||!sx_p_byte(c,4,&enc)||!sx_add(c,&sx_p_pak_header5,0,12))return false;count=n;}else return false;
    if(count>65535||enc>2||!sx_table(c,&sx_p_pak_resource,header,6,(uint64_t)count+1)||!sx_table(c,&sx_p_pak_alias,header+6*((int64_t)count+1),4,aliases))return false;
    uint64_t payload=header+6*((uint64_t)count+1)+4*aliases;for(uint32_t i=0;i<=count;i++){uint32_t off;if(!sx_u32(c,header+6*i+2,false,&off)||off<payload||off<previous||off>(uint64_t)c->size)return false;previous=off;}if(previous!=(uint64_t)c->size)return false;
    for(unsigned i=0;i<aliases;i++){uint16_t which;if(!sx_u16(c,header+6*((int64_t)count+1)+4*i+2,false,&which)||which>=count)return false;}return true;
}
static bool sx_p_dvi(sx_context *c)
{
    uint8_t n,b;if(!sx_p_sig(c,0,"\xf7\2",2)||!sx_p_byte(c,14,&n)||!sx_p_span(c,15,n)||!sx_add(c,&sx_p_dvi_preamble,0,15)||c->size<10)return false;
    int64_t end=c->size;unsigned padding=0;while(end>0){if(!sx_p_byte(c,end-1,&b))return false;if(b!=223)break;end--;padding++;}if(padding<4||end<6)return false;
    uint32_t post;if(!sx_p_byte(c,end-6,&b)||b!=249||!sx_u32(c,end-5,true,&post)||!sx_p_byte(c,end-1,&b)||b!=2||post>=end-6||!sx_p_byte(c,post,&b)||b!=248||!sx_add(c,&sx_p_dvi_postamble,post,29)||!sx_add(c,&sx_p_dvi_post_post,end-6,6))return false;
    uint32_t page,previous;uint16_t pages;if(!sx_u32(c,(int64_t)post+1,true,&page)||!sx_u16(c,(int64_t)post+27,true,&pages))return false;unsigned seen=0;
    while(page!=UINT32_MAX){if(page>=post||!sx_p_byte(c,page,&b)||b!=139||!sx_add(c,&sx_p_dvi_page,page,45)||!sx_u32(c,(int64_t)page+41,true,&previous)||(++seen)>pages||(previous!=UINT32_MAX&&previous>=page))return false;page=previous;}
    return seen==pages;
}
static bool sx_package_supports(xx_file_type_t type)
{
    switch(type){case XX_FILE_TYPE_ARJ:case XX_FILE_TYPE_ACE:case XX_FILE_TYPE_ALZ:case XX_FILE_TYPE_HA:case XX_FILE_TYPE_ZOO:case XX_FILE_TYPE_LHA:case XX_FILE_TYPE_ZLIB:case XX_FILE_TYPE_LZMA:case XX_FILE_TYPE_LZMA86:case XX_FILE_TYPE_XAR:case XX_FILE_TYPE_RPM:case XX_FILE_TYPE_CFBF:case XX_FILE_TYPE_BINDER:case XX_FILE_TYPE_CHM:case XX_FILE_TYPE_TNEF:case XX_FILE_TYPE_WIM:case XX_FILE_TYPE_UNIX_COMPRESS:case XX_FILE_TYPE_UNIX_PACK:case XX_FILE_TYPE_SNAPPY_FRAMED:case XX_FILE_TYPE_MOZILLA_MAR:case XX_FILE_TYPE_CHROMIUM_PAK:case XX_FILE_TYPE_XPAK:case XX_FILE_TYPE_PP20:case XX_FILE_TYPE_TEX_DVI:return true;default:return false;}
}
static bool sx_package_build(sx_context *c)
{
    bool ok=false;uint8_t b[16];uint32_t n;uint64_t length;
    switch(c->f->file_type){
    case XX_FILE_TYPE_ARJ:ok=sx_p_arj(c);break;case XX_FILE_TYPE_ACE:ok=sx_p_ace(c);break;case XX_FILE_TYPE_ALZ:ok=sx_p_alz(c);break;case XX_FILE_TYPE_HA:ok=sx_p_ha(c);break;case XX_FILE_TYPE_ZOO:ok=sx_p_zoo(c);break;case XX_FILE_TYPE_LHA:ok=sx_p_lha(c);break;
    case XX_FILE_TYPE_ZLIB:if(sx_read(c,0,b,2)&&(b[0]&15)==8&&(b[0]>>4)<=7&&(((unsigned)b[0]<<8)|b[1])%31==0&&c->size>=6+(b[1]&32?4:0)){ok=sx_add(c,&sx_p_zlib_header,0,2)&&(!(b[1]&32)||sx_add(c,&sx_p_zlib_dictionary,2,4))&&sx_add(c,&sx_p_zlib_trailer,c->size-4,4);}break;
    case XX_FILE_TYPE_LZMA:case XX_FILE_TYPE_LZMA86:{int off=c->f->file_type==XX_FILE_TYPE_LZMA86?1:0;if(off&&(!sx_p_byte(c,0,b)||*b>1||!sx_add(c,&sx_p_lzma86_filter,0,1)))break;ok=sx_p_byte(c,off,b)&&*b<225&&sx_add(c,&sx_p_lzma_header,off,13);break;}
    case XX_FILE_TYPE_XAR:{uint16_t hs,v;ok=sx_p_sig(c,0,"xar!",4)&&sx_u16(c,4,true,&hs)&&hs>=28&&sx_u16(c,6,true,&v)&&v<=1&&hs<=1024&&sx_u64(c,8,true,&length)&&sx_p_span(c,hs,length)&&sx_add(c,&sx_p_xar_header,0,28);break;}
    case XX_FILE_TYPE_RPM:ok=sx_p_rpm(c);break;case XX_FILE_TYPE_CFBF:case XX_FILE_TYPE_BINDER:ok=sx_p_cfbf(c);break;case XX_FILE_TYPE_CHM:ok=sx_p_chm(c);break;case XX_FILE_TYPE_TNEF:ok=sx_p_tnef(c);break;case XX_FILE_TYPE_WIM:ok=sx_p_wim(c);break;
    case XX_FILE_TYPE_UNIX_COMPRESS:ok=sx_read(c,0,b,3)&&b[0]==0x1f&&b[1]==0x9d&&(b[2]&31)>=9&&(b[2]&31)<=16&&!(b[2]&0x60)&&sx_add(c,&sx_p_unix_compress_header,0,3);break;
    case XX_FILE_TYPE_UNIX_PACK:
        ok=sx_read(c,0,b,6)&&b[0]==0x1f&&(b[1]==0x1e||b[1]==0x1f)&&sx_add(c,b[1]==0x1e?&sx_p_unix_pack_header:&sx_p_unix_pack_old_header,0,6);
        if(ok&&b[1]==0x1e){uint8_t depth,counts[24];ok=sx_p_byte(c,6,&depth)&&depth>0&&depth<=24&&sx_read(c,7,counts,depth)&&counts[depth-1]<=253&&sx_add(c,&sx_p_pack_tree,6,1)&&sx_table(c,&sx_p_pack_level,7,1,depth);unsigned literals=1;if(ok){for(unsigned i=0;i<depth;i++)literals+=counts[i];ok=literals<=256&&sx_table(c,&sx_p_pack_literal,7+depth,1,literals);}}
        else if(ok){uint16_t count;ok=sx_u16(c,6,false,&count)&&count>=2&&count<1024&&sx_add(c,&sx_p_pack_old_tree,6,2);int64_t off=8;for(unsigned i=0;ok&&i<count;i++){uint8_t marker;ok=sx_p_byte(c,off,&marker);if(ok){unsigned size=marker==255?3:1;ok=sx_add(c,marker==255?&sx_p_pack_old_wide_node:&sx_p_pack_old_node,off,size);off+=size;}}}
        break;
    case XX_FILE_TYPE_SNAPPY_FRAMED:ok=sx_p_snappy(c);break;case XX_FILE_TYPE_MOZILLA_MAR:ok=sx_p_mar(c);break;case XX_FILE_TYPE_CHROMIUM_PAK:ok=sx_p_pak(c);break;
    case XX_FILE_TYPE_XPAK:ok=sx_p_sig(c,0,"XPAK",4)&&sx_u32(c,4,false,&n)&&n>=35&&n<=(uint64_t)c->size&&sx_p_sig(c,26,"\xff\xfe",2)&&sx_add(c,&sx_p_xpak_header,0,25)&&sx_add(c,&sx_p_xpak_codec,25,9);break;
    case XX_FILE_TYPE_PP20:{
        int header=8;const sx_layout *layout=&sx_p_pp20_header;
        if(!sx_read(c,0,b,4))break;
        if(!xx_rt_memcmp(b,"PPLS",4)){header=12;layout=&sx_p_pp20_library_header;}else if(!xx_rt_memcmp(b,"PX20",4)){header=10;layout=&sx_p_pp20_encrypted_header;}else if(xx_rt_memcmp(b,"PP20",4)&&xx_rt_memcmp(b,"PP11",4)&&xx_rt_memcmp(b,"PPBK",4))break;
        if(c->size<header+5||(c->size&3)||!sx_read(c,header-4,b,4))break;
        bool widths=true;for(unsigned i=0;i<4;i++)if(b[i]<9||b[i]>16||(i&&b[i]<b[i-1]))widths=false;
        ok=widths&&sx_add(c,layout,0,header)&&sx_p_byte(c,c->size-1,b)&&*b<=31&&sx_add(c,&sx_p_pp20_trailer,c->size-4,4);break;}

    case XX_FILE_TYPE_TEX_DVI:ok=sx_p_dvi(c);break;default:return false;}
    return ok&&sx_p_finish(c);
}
static const wchar_t *sx_p_comment(uint32_t id,const wchar_t *name,uint64_t value)
{
    if((id==sx_p_chm_itsf2.id||id==sx_p_chm_itsf3.id)&&!xx_rt_wcscmp(name,L"timestamp"))return L"Encoded low 32 bits of FILETIME plus 42, modulo 2^32";
    if(id==sx_p_zoo_directory.id){if(!xx_rt_wcscmp(name,L"date"))return L"Packed MS-DOS date: year since 1980 (bits 9..15), month (5..8), day (0..4)";if(!xx_rt_wcscmp(name,L"time"))return L"Packed MS-DOS time: hour (bits 11..15), minute (5..10), two-second units (0..4)";}
    if((id==sx_p_cfbf_header.id)&&(!xx_rt_wcscmp(name,L"sector_shift")||!xx_rt_wcscmp(name,L"mini_sector_shift")))return L"log2(sector size in bytes)";
    if(id==sx_p_wim_resource.id||id==sx_p_wim_blob.id)if(!xx_rt_wcscmp(name,L"size_and_flags"))return L"Low 56 bits: packed byte size; high 8 bits: resource flags";
    if(id==sx_p_lzma_header.id){if(!xx_rt_wcscmp(name,L"properties"))return L"(pb * 5 + lp) * 9 + lc";if(!xx_rt_wcscmp(name,L"original_size")&&value==UINT64_MAX)return L"Unknown size; end marker terminates stream";}
    if(id==sx_p_lzma86_filter.id)return value==0?L"No filter":value==1?L"x86 BCJ":NULL;
    if(id==sx_p_xar_header.id&&!xx_rt_wcscmp(name,L"checksum_algorithm"))return value==0?L"NONE":value==1?L"SHA1":value==2?L"MD5":value==3?L"SHA256":value==4?L"SHA512":NULL;
    if(id==sx_p_rpm_index.id&&!xx_rt_wcscmp(name,L"type")){static const wchar_t *const names[]={L"NULL",L"CHAR",L"INT8",L"INT16",L"INT32",L"INT64",L"STRING",L"BIN",L"STRING_ARRAY",L"I18NSTRING"};return value<SX_COUNT(names)?names[value]:NULL;}
    if(id==sx_p_snappy_chunk.id&&!xx_rt_wcscmp(name,L"type"))return value==0?L"Compressed data":value==1?L"Uncompressed data":value==255?L"Stream identifier":value>=128?L"Skippable chunk":L"Reserved unskippable chunk";
    if(id==sx_p_tnef_attribute.id&&!xx_rt_wcscmp(name,L"level"))return value==1?L"Message":value==2?L"Attachment":NULL;
    if(id==sx_p_unix_compress_header.id&&!xx_rt_wcscmp(name,L"flags"))return L"Low 5 bits: maximum code width; bit 7: block mode";
    if(id==sx_p_zlib_header.id){if(!xx_rt_wcscmp(name,L"compression_method_flags"))return L"CM in bits 0..3 (8 = DEFLATE); CINFO in bits 4..7 (window log2 minus 8)";return L"FCHECK in bits 0..4; FDICT bit 5; compression level bits 6..7";}
    if(id==sx_p_alz_file.id&&!xx_rt_wcscmp(name,L"descriptor"))return L"High nibble: size-field byte width; bit 0: encrypted";
    if(id==sx_p_ha_file.id&&!xx_rt_wcscmp(name,L"version_method"))return L"High nibble: version; low nibble: method (0 stored, 1 ASC, 2 HSC)";
    if(id==sx_p_unix_pack_old_header.id&&(!xx_rt_wcscmp(name,L"original_size_high")||!xx_rt_wcscmp(name,L"original_size_low")))return L"Original size = (high << 16) | low; words are little endian";
    if(id==sx_p_pack_level.id)return L"Codewords at this depth; deepest level stores the count minus 2";
    return NULL;
}

static bool sx_package_comment(xx_data_struct_record *record,uint32_t id)
{
    if(!record||!record->name||id<UINT32_C(0x60070000)||id>=UINT32_C(0x60080000))return true;
    const wchar_t *comment=sx_p_comment(id,record->name,xx_var_get_u64(&record->value));
    return !comment||xx_data_struct_record_set_comment(record,comment);
}
