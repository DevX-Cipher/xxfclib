/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical database metadata. Native readers validate supported grammars. */
static const xx_data_struct_field_desc sxd_sequence_header_fields[] = {
    SX_FIELD("magic", "char[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_ID),
};
static const sx_layout sxd_sequence_header = {UINT32_C(0x601A0001),"sequence_header",sxd_sequence_header_fields,SX_COUNT(sxd_sequence_header_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_options_fields[] = {
    SX_FIELD("compression", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("block_compression", "uint8", 1, 1, SX_FLAGS),
    SX_FIELD("metadata_entries", "int32", 2, 4, SX_COUNT_PROP),
};
static const sx_layout sxd_sequence_options = {UINT32_C(0x601A0002),"sequence_options",sxd_sequence_options_fields,SX_COUNT(sxd_sequence_options_fields),SX_BE};

static const xx_data_struct_field_desc sxd_sequence_sync_fields[] = {
    SX_FIELD("sync_marker", "uint8[16]", 0, 16, SX_SIGNATURE),
};
static const sx_layout sxd_sequence_sync = {UINT32_C(0x601A0003),"sequence_sync",sxd_sequence_sync_fields,SX_COUNT(sxd_sequence_sync_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_sync_record_fields[] = {
    SX_FIELD("sync_escape", "int32", 0, 4, SX_SIGNATURE),
    SX_FIELD("sync_marker", "uint8[16]", 4, 16, SX_SIGNATURE),
};
static const sx_layout sxd_sequence_sync_record = {UINT32_C(0x601A0004),"sequence_sync_record",sxd_sequence_sync_record_fields,SX_COUNT(sxd_sequence_sync_record_fields),SX_BE};

static const xx_data_struct_field_desc sxd_sequence_record_fields[] = {
    SX_FIELD("record_length", "int32", 0, 4, SX_SIZE),
    SX_FIELD("key_length", "int32", 4, 4, SX_SIZE),
};
static const sx_layout sxd_sequence_record = {UINT32_C(0x601A0005),"sequence_record",sxd_sequence_record_fields,SX_COUNT(sxd_sequence_record_fields),SX_BE};

static const xx_data_struct_field_desc sxd_sequence_text_length_0_fields[] = {
    SX_FIELD("length", "uint8", 0, 1, SX_SIZE),
};
static const sx_layout sxd_sequence_text_length_0 = {UINT32_C(0x601A0006),"sequence_text_length_0",sxd_sequence_text_length_0_fields,SX_COUNT(sxd_sequence_text_length_0_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_text_length_1_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint8be", 1, 1, SX_NONE),
};
static const sx_layout sxd_sequence_text_length_1 = {UINT32_C(0x601A0007),"sequence_text_length_1",sxd_sequence_text_length_1_fields,SX_COUNT(sxd_sequence_text_length_1_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_text_length_2_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint16be", 1, 2, SX_NONE),
};
static const sx_layout sxd_sequence_text_length_2 = {UINT32_C(0x601A0008),"sequence_text_length_2",sxd_sequence_text_length_2_fields,SX_COUNT(sxd_sequence_text_length_2_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_text_length_3_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint24be", 1, 3, SX_NONE),
};
static const sx_layout sxd_sequence_text_length_3 = {UINT32_C(0x601A0009),"sequence_text_length_3",sxd_sequence_text_length_3_fields,SX_COUNT(sxd_sequence_text_length_3_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_text_length_4_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint32be", 1, 4, SX_NONE),
};
static const sx_layout sxd_sequence_text_length_4 = {UINT32_C(0x601A000A),"sequence_text_length_4",sxd_sequence_text_length_4_fields,SX_COUNT(sxd_sequence_text_length_4_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_text_length_5_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint40be", 1, 5, SX_NONE),
};
static const sx_layout sxd_sequence_text_length_5 = {UINT32_C(0x601A000B),"sequence_text_length_5",sxd_sequence_text_length_5_fields,SX_COUNT(sxd_sequence_text_length_5_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_text_length_6_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint48be", 1, 6, SX_NONE),
};
static const sx_layout sxd_sequence_text_length_6 = {UINT32_C(0x601A000C),"sequence_text_length_6",sxd_sequence_text_length_6_fields,SX_COUNT(sxd_sequence_text_length_6_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_text_length_7_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint56be", 1, 7, SX_NONE),
};
static const sx_layout sxd_sequence_text_length_7 = {UINT32_C(0x601A000D),"sequence_text_length_7",sxd_sequence_text_length_7_fields,SX_COUNT(sxd_sequence_text_length_7_fields),SX_LE};

static const xx_data_struct_field_desc sxd_sequence_text_length_8_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint64be", 1, 8, SX_NONE),
};
static const sx_layout sxd_sequence_text_length_8 = {UINT32_C(0x601A000E),"sequence_text_length_8",sxd_sequence_text_length_8_fields,SX_COUNT(sxd_sequence_text_length_8_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_header_fields[] = {
    SX_FIELD("magic", "char[5]", 0, 5, SX_SIGNATURE),
    SX_FIELD("version_major", "uint8", 5, 1, SX_ID),
    SX_FIELD("version_minor", "uint8", 6, 1, SX_ID),
    SX_FIELD("version_revision", "uint8", 7, 1, SX_ID),
    SX_FIELD("integer_size", "uint8", 8, 1, SX_SIZE),
    SX_FIELD("offset_size", "uint8", 9, 1, SX_SIZE),
    SX_FIELD("format", "uint8", 10, 1, SX_ID),
};
static const sx_layout sxd_postgres_header = {UINT32_C(0x601A000F),"postgres_header",sxd_postgres_header_fields,SX_COUNT(sxd_postgres_header_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_compression_v15_fields[] = {
    SX_FIELD("compression_algorithm", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxd_postgres_compression_v15 = {UINT32_C(0x601A0010),"postgres_compression_v15",sxd_postgres_compression_v15_fields,SX_COUNT(sxd_postgres_compression_v15_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_compression_legacy_fields[] = {
    SX_FIELD("compression_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("compression_magnitude", "uint32", 1, 4, SX_NONE),
};
static const sx_layout sxd_postgres_compression_legacy = {UINT32_C(0x601A0011),"postgres_compression_legacy",sxd_postgres_compression_legacy_fields,SX_COUNT(sxd_postgres_compression_legacy_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_time_fields[] = {
    SX_FIELD("second_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("second_magnitude", "uint32", 1, 4, SX_NONE),
    SX_FIELD("minute_sign", "uint8", 5, 1, SX_NONE),
    SX_FIELD("minute_magnitude", "uint32", 6, 4, SX_NONE),
    SX_FIELD("hour_sign", "uint8", 10, 1, SX_NONE),
    SX_FIELD("hour_magnitude", "uint32", 11, 4, SX_NONE),
    SX_FIELD("day_sign", "uint8", 15, 1, SX_NONE),
    SX_FIELD("day_magnitude", "uint32", 16, 4, SX_NONE),
    SX_FIELD("month_sign", "uint8", 20, 1, SX_NONE),
    SX_FIELD("month_magnitude", "uint32", 21, 4, SX_NONE),
    SX_FIELD("year_sign", "uint8", 25, 1, SX_NONE),
    SX_FIELD("year_magnitude", "uint32", 26, 4, SX_NONE),
    SX_FIELD("is_dst_sign", "uint8", 30, 1, SX_NONE),
    SX_FIELD("is_dst_magnitude", "uint32", 31, 4, SX_NONE),
};
static const sx_layout sxd_postgres_time = {UINT32_C(0x601A0012),"postgres_time",sxd_postgres_time_fields,SX_COUNT(sxd_postgres_time_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_string_length_fields[] = {
    SX_FIELD("length_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("length_magnitude", "uint32", 1, 4, SX_NONE),
};
static const sx_layout sxd_postgres_string_length = {UINT32_C(0x601A0013),"postgres_string_length",sxd_postgres_string_length_fields,SX_COUNT(sxd_postgres_string_length_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_toc_count_fields[] = {
    SX_FIELD("count_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("count_magnitude", "uint32", 1, 4, SX_COUNT_PROP),
};
static const sx_layout sxd_postgres_toc_count = {UINT32_C(0x601A0014),"postgres_toc_count",sxd_postgres_toc_count_fields,SX_COUNT(sxd_postgres_toc_count_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_toc_prefix_fields[] = {
    SX_FIELD("dump_id_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("dump_id_magnitude", "uint32", 1, 4, SX_ID),
    SX_FIELD("has_dumper_sign", "uint8", 5, 1, SX_NONE),
    SX_FIELD("has_dumper_magnitude", "uint32", 6, 4, SX_FLAGS),
};
static const sx_layout sxd_postgres_toc_prefix = {UINT32_C(0x601A0015),"postgres_toc_prefix",sxd_postgres_toc_prefix_fields,SX_COUNT(sxd_postgres_toc_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_section_fields[] = {
    SX_FIELD("section_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("section_magnitude", "uint32", 1, 4, SX_ID),
};
static const sx_layout sxd_postgres_section = {UINT32_C(0x601A0016),"postgres_section",sxd_postgres_section_fields,SX_COUNT(sxd_postgres_section_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_data_offset_fields[] = {
    SX_FIELD("offset_state", "uint8", 0, 1, SX_ID),
    SX_FIELD("data_offset", "uint64", 1, 8, SX_OFFSET),
};
static const sx_layout sxd_postgres_data_offset = {UINT32_C(0x601A0017),"postgres_data_offset",sxd_postgres_data_offset_fields,SX_COUNT(sxd_postgres_data_offset_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_block_header_fields[] = {
    SX_FIELD("block_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("dump_id_sign", "uint8", 1, 1, SX_NONE),
    SX_FIELD("dump_id_magnitude", "uint32", 2, 4, SX_ID),
};
static const sx_layout sxd_postgres_block_header = {UINT32_C(0x601A0018),"postgres_block_header",sxd_postgres_block_header_fields,SX_COUNT(sxd_postgres_block_header_fields),SX_LE};

static const xx_data_struct_field_desc sxd_postgres_chunk_length_fields[] = {
    SX_FIELD("length_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("length_magnitude", "uint32", 1, 4, SX_SIZE),
};
static const sx_layout sxd_postgres_chunk_length = {UINT32_C(0x601A0019),"postgres_chunk_length",sxd_postgres_chunk_length_fields,SX_COUNT(sxd_postgres_chunk_length_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_meta_prefix_fields[] = {
    SX_FIELD("page_number", "uint64", 0, 8, SX_NONE),
    SX_FIELD("page_pad", "uint16", 8, 2, SX_RESERVED),
    SX_FIELD("page_flags", "uint16", 10, 2, SX_FLAGS),
    SX_FIELD("lower_upper_unused", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("magic", "uint32", 16, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 20, 4, SX_ID),
    SX_FIELD("fixed_address", "uint64", 24, 8, SX_ADDRESS),
    SX_FIELD("map_size", "uint64", 32, 8, SX_SIZE),
};
static const sx_layout sxd_lmdb_meta_prefix = {UINT32_C(0x601A001A),"lmdb_meta_prefix",sxd_lmdb_meta_prefix_fields,SX_COUNT(sxd_lmdb_meta_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_database_fields[] = {
    SX_FIELD("pad", "uint32", 0, 4, SX_NONE),
    SX_FIELD("flags", "uint16", 4, 2, SX_FLAGS),
    SX_FIELD("depth", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("branch_pages", "uint64", 8, 8, SX_COUNT_PROP),
    SX_FIELD("leaf_pages", "uint64", 16, 8, SX_COUNT_PROP),
    SX_FIELD("overflow_pages", "uint64", 24, 8, SX_COUNT_PROP),
    SX_FIELD("entry_count", "uint64", 32, 8, SX_COUNT_PROP),
    SX_FIELD("root_page", "uint64", 40, 8, SX_NONE),
};
static const sx_layout sxd_lmdb_database = {UINT32_C(0x601A001B),"lmdb_database",sxd_lmdb_database_fields,SX_COUNT(sxd_lmdb_database_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_free_database_fields[] = {
    SX_FIELD("page_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("flags", "uint16", 4, 2, SX_FLAGS),
    SX_FIELD("depth", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("branch_pages", "uint64", 8, 8, SX_COUNT_PROP),
    SX_FIELD("leaf_pages", "uint64", 16, 8, SX_COUNT_PROP),
    SX_FIELD("overflow_pages", "uint64", 24, 8, SX_COUNT_PROP),
    SX_FIELD("entry_count", "uint64", 32, 8, SX_COUNT_PROP),
    SX_FIELD("root_page", "uint64", 40, 8, SX_NONE),
};
static const sx_layout sxd_lmdb_free_database = {UINT32_C(0x601A001C),"lmdb_free_database",sxd_lmdb_free_database_fields,SX_COUNT(sxd_lmdb_free_database_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_meta_tail_fields[] = {
    SX_FIELD("last_page", "uint64", 0, 8, SX_NONE),
    SX_FIELD("transaction_id", "uint64", 8, 8, SX_ID),
};
static const sx_layout sxd_lmdb_meta_tail = {UINT32_C(0x601A001D),"lmdb_meta_tail",sxd_lmdb_meta_tail_fields,SX_COUNT(sxd_lmdb_meta_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_page_header_fields[] = {
    SX_FIELD("page_number", "uint64", 0, 8, SX_NONE),
    SX_FIELD("pad", "uint16", 8, 2, SX_RESERVED),
    SX_FIELD("flags", "uint16", 10, 2, SX_FLAGS),
    SX_FIELD("lower_offset", "uint16", 12, 2, SX_OFFSET),
    SX_FIELD("upper_offset", "uint16", 14, 2, SX_OFFSET),
};
static const sx_layout sxd_lmdb_page_header = {UINT32_C(0x601A001E),"lmdb_page_header",sxd_lmdb_page_header_fields,SX_COUNT(sxd_lmdb_page_header_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_node_offset_fields[] = {
    SX_FIELD("node_offset", "uint16", 0, 2, SX_OFFSET),
};
static const sx_layout sxd_lmdb_node_offset = {UINT32_C(0x601A001F),"lmdb_node_offset",sxd_lmdb_node_offset_fields,SX_COUNT(sxd_lmdb_node_offset_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_leaf_node_fields[] = {
    SX_FIELD("data_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("flags", "uint16", 4, 2, SX_FLAGS),
    SX_FIELD("key_size", "uint16", 6, 2, SX_SIZE),
};
static const sx_layout sxd_lmdb_leaf_node = {UINT32_C(0x601A0020),"lmdb_leaf_node",sxd_lmdb_leaf_node_fields,SX_COUNT(sxd_lmdb_leaf_node_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_branch_node_fields[] = {
    SX_FIELD("child_page_low", "uint32", 0, 4, SX_NONE),
    SX_FIELD("child_page_high", "uint16", 4, 2, SX_NONE),
    SX_FIELD("key_size", "uint16", 6, 2, SX_SIZE),
};
static const sx_layout sxd_lmdb_branch_node = {UINT32_C(0x601A0021),"lmdb_branch_node",sxd_lmdb_branch_node_fields,SX_COUNT(sxd_lmdb_branch_node_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_overflow_reference_fields[] = {
    SX_FIELD("overflow_page", "uint64", 0, 8, SX_NONE),
};
static const sx_layout sxd_lmdb_overflow_reference = {UINT32_C(0x601A0022),"lmdb_overflow_reference",sxd_lmdb_overflow_reference_fields,SX_COUNT(sxd_lmdb_overflow_reference_fields),SX_LE};

static const xx_data_struct_field_desc sxd_lmdb_overflow_page_fields[] = {
    SX_FIELD("page_number", "uint64", 0, 8, SX_NONE),
    SX_FIELD("pad", "uint16", 8, 2, SX_RESERVED),
    SX_FIELD("flags", "uint16", 10, 2, SX_FLAGS),
    SX_FIELD("page_count", "uint32", 12, 4, SX_COUNT_PROP),
};
static const sx_layout sxd_lmdb_overflow_page = {UINT32_C(0x601A0023),"lmdb_overflow_page",sxd_lmdb_overflow_page_fields,SX_COUNT(sxd_lmdb_overflow_page_fields),SX_LE};

static const xx_data_struct_field_desc sxd_leveldb_block_trailer_fields[] = {
    SX_FIELD("compression_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("masked_crc32c", "uint32", 1, 4, SX_CHECKSUM),
};
static const sx_layout sxd_leveldb_block_trailer = {UINT32_C(0x601A0024),"leveldb_block_trailer",sxd_leveldb_block_trailer_fields,SX_COUNT(sxd_leveldb_block_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxd_leveldb_restart_offset_fields[] = {
    SX_FIELD("restart_offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sxd_leveldb_restart_offset = {UINT32_C(0x601A0025),"leveldb_restart_offset",sxd_leveldb_restart_offset_fields,SX_COUNT(sxd_leveldb_restart_offset_fields),SX_LE};

static const xx_data_struct_field_desc sxd_leveldb_restart_count_fields[] = {
    SX_FIELD("restart_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sxd_leveldb_restart_count = {UINT32_C(0x601A0026),"leveldb_restart_count",sxd_leveldb_restart_count_fields,SX_COUNT(sxd_leveldb_restart_count_fields),SX_LE};

static const xx_data_struct_field_desc sxd_leveldb_footer_magic_fields[] = {
    SX_FIELD("magic", "uint64", 0, 8, SX_SIGNATURE),
};
static const sx_layout sxd_leveldb_footer_magic = {UINT32_C(0x601A0027),"leveldb_footer_magic",sxd_leveldb_footer_magic_fields,SX_COUNT(sxd_leveldb_footer_magic_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_header_fields[] = {
    SX_FIELD("magic", "char[5]", 0, 5, SX_SIGNATURE),
    SX_FIELD("version", "char[4]", 5, 4, SX_ID),
};
static const sx_layout sxd_redis_header = {UINT32_C(0x601A0028),"redis_header",sxd_redis_header_fields,SX_COUNT(sxd_redis_header_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_opcode_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxd_redis_opcode = {UINT32_C(0x601A0029),"redis_opcode",sxd_redis_opcode_fields,SX_COUNT(sxd_redis_opcode_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_trailer_fields[] = {
    SX_FIELD("end_opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("crc64", "uint64", 1, 8, SX_CHECKSUM),
};
static const sx_layout sxd_redis_trailer = {UINT32_C(0x601A002A),"redis_trailer",sxd_redis_trailer_fields,SX_COUNT(sxd_redis_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_expire_milliseconds_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("expire_time_ms", "int64", 1, 8, SX_TIME),
};
static const sx_layout sxd_redis_expire_milliseconds = {UINT32_C(0x601A002B),"redis_expire_milliseconds",sxd_redis_expire_milliseconds_fields,SX_COUNT(sxd_redis_expire_milliseconds_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_expire_seconds_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("expire_time_seconds", "int32", 1, 4, SX_TIME),
};
static const sx_layout sxd_redis_expire_seconds = {UINT32_C(0x601A002C),"redis_expire_seconds",sxd_redis_expire_seconds_fields,SX_COUNT(sxd_redis_expire_seconds_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_frequency_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("frequency", "uint8", 1, 1, SX_NONE),
};
static const sx_layout sxd_redis_frequency = {UINT32_C(0x601A002D),"redis_frequency",sxd_redis_frequency_fields,SX_COUNT(sxd_redis_frequency_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_length_6_fields[] = {
    SX_FIELD("encoding_and_length", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sxd_redis_length_6 = {UINT32_C(0x601A002E),"redis_length_6",sxd_redis_length_6_fields,SX_COUNT(sxd_redis_length_6_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_length_14_fields[] = {
    SX_FIELD("encoding_and_length_high", "uint8", 0, 1, SX_NONE),
    SX_FIELD("length_low", "uint8", 1, 1, SX_NONE),
};
static const sx_layout sxd_redis_length_14 = {UINT32_C(0x601A002F),"redis_length_14",sxd_redis_length_14_fields,SX_COUNT(sxd_redis_length_14_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_length_32_fields[] = {
    SX_FIELD("encoding", "uint8", 0, 1, SX_NONE),
    SX_FIELD("encoded_length", "uint32", 1, 4, SX_NONE),
};
static const sx_layout sxd_redis_length_32 = {UINT32_C(0x601A0030),"redis_length_32",sxd_redis_length_32_fields,SX_COUNT(sxd_redis_length_32_fields),SX_BE};

static const xx_data_struct_field_desc sxd_redis_length_64_fields[] = {
    SX_FIELD("encoding", "uint8", 0, 1, SX_NONE),
    SX_FIELD("encoded_length", "uint64", 1, 8, SX_NONE),
};
static const sx_layout sxd_redis_length_64 = {UINT32_C(0x601A0031),"redis_length_64",sxd_redis_length_64_fields,SX_COUNT(sxd_redis_length_64_fields),SX_BE};

static const xx_data_struct_field_desc sxd_redis_encoded_string_fields[] = {
    SX_FIELD("encoding_and_integer_type", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxd_redis_encoded_string = {UINT32_C(0x601A0032),"redis_encoded_string",sxd_redis_encoded_string_fields,SX_COUNT(sxd_redis_encoded_string_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_integer_1_fields[] = {
    SX_FIELD("signed_integer", "int8", 0, 1, SX_NONE),
};
static const sx_layout sxd_redis_integer_1 = {UINT32_C(0x601A0033),"redis_integer_1",sxd_redis_integer_1_fields,SX_COUNT(sxd_redis_integer_1_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_integer_2_fields[] = {
    SX_FIELD("signed_integer", "int16", 0, 2, SX_NONE),
};
static const sx_layout sxd_redis_integer_2 = {UINT32_C(0x601A0034),"redis_integer_2",sxd_redis_integer_2_fields,SX_COUNT(sxd_redis_integer_2_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_integer_4_fields[] = {
    SX_FIELD("signed_integer", "int32", 0, 4, SX_NONE),
};
static const sx_layout sxd_redis_integer_4 = {UINT32_C(0x601A0035),"redis_integer_4",sxd_redis_integer_4_fields,SX_COUNT(sxd_redis_integer_4_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_score_length_fields[] = {
    SX_FIELD("score_length_or_infinity", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sxd_redis_score_length = {UINT32_C(0x601A0036),"redis_score_length",sxd_redis_score_length_fields,SX_COUNT(sxd_redis_score_length_fields),SX_LE};

static const xx_data_struct_field_desc sxd_redis_score_binary_fields[] = {
    SX_FIELD("ieee754_binary64_bits", "uint64", 0, 8, SX_NONE),
};
static const sx_layout sxd_redis_score_binary = {UINT32_C(0x601A0037),"redis_score_binary",sxd_redis_score_binary_fields,SX_COUNT(sxd_redis_score_binary_fields),SX_LE};

static const xx_data_struct_field_desc sxd_tps_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
};
static const sx_layout sxd_tps_header = {UINT32_C(0x601A0038),"tps_header",sxd_tps_header_fields,SX_COUNT(sxd_tps_header_fields),SX_LE};

static const xx_data_struct_field_desc sxd_tps_entry_fields[] = {
    SX_FIELD("entry_tag", "uint8", 0, 1, SX_ID),
    SX_FIELD("name_length", "uint8", 1, 1, SX_SIZE),
    SX_FIELD("name", "char[12]", 2, 12, SX_STRING),
    SX_FIELD("coded_length_plus_four", "int32", 14, 4, SX_NONE),
    SX_FIELD("encoded_uncompressed_length", "uint32", 18, 4, SX_NONE),
};
static const sx_layout sxd_tps_entry = {UINT32_C(0x601A0039),"tps_entry",sxd_tps_entry_fields,SX_COUNT(sxd_tps_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxd_tps_terminator_fields[] = {
    SX_FIELD("end_tag", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxd_tps_terminator = {UINT32_C(0x601A003A),"tps_terminator",sxd_tps_terminator_fields,SX_COUNT(sxd_tps_terminator_fields),SX_LE};

static const xx_data_struct_field_desc sxd_dbz_header_fields[] = {
    SX_FIELD("magic", "char[27]", 0, 27, SX_SIGNATURE),
};
static const sx_layout sxd_dbz_header = {UINT32_C(0x601A003B),"dbz_header",sxd_dbz_header_fields,SX_COUNT(sxd_dbz_header_fields),SX_LE};

static const xx_data_struct_field_desc sxd_dbz_index_record_fields[] = {
    SX_FIELD("name", "char[14]", 0, 14, SX_STRING),
    SX_FIELD("decimal_payload_offset", "ascii_decimal[9]", 14, 9, SX_OFFSET),
    SX_FIELD("decimal_payload_size", "ascii_decimal[9]", 23, 9, SX_SIZE),
};
static const sx_layout sxd_dbz_index_record = {UINT32_C(0x601A003C),"dbz_index_record",sxd_dbz_index_record_fields,SX_COUNT(sxd_dbz_index_record_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_header_fields[] = {
    SX_FIELD("magic", "char[3]", 0, 3, SX_SIGNATURE),
};
static const sx_layout sxd_orc_header = {UINT32_C(0x601A003D),"orc_header",sxd_orc_header_fields,SX_COUNT(sxd_orc_header_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_postscript_length_fields[] = {
    SX_FIELD("postscript_length", "uint8", 0, 1, SX_SIZE),
};
static const sx_layout sxd_orc_postscript_length = {UINT32_C(0x601A003E),"orc_postscript_length",sxd_orc_postscript_length_fields,SX_COUNT(sxd_orc_postscript_length_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_fixed32_fields[] = {
    SX_FIELD("value", "uint32", 0, 4, SX_NONE),
};
static const sx_layout sxd_orc_fixed32 = {UINT32_C(0x601A003F),"orc_fixed32",sxd_orc_fixed32_fields,SX_COUNT(sxd_orc_fixed32_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_fixed64_fields[] = {
    SX_FIELD("value", "uint64", 0, 8, SX_NONE),
};
static const sx_layout sxd_orc_fixed64 = {UINT32_C(0x601A0040),"orc_fixed64",sxd_orc_fixed64_fields,SX_COUNT(sxd_orc_fixed64_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_1_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 1, SX_NONE),
};
static const sx_layout sxd_database_varuint_1 = {UINT32_C(0x601A0041),"database_varuint_1",sxd_database_varuint_1_fields,SX_COUNT(sxd_database_varuint_1_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_2_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 2, SX_NONE),
};
static const sx_layout sxd_database_varuint_2 = {UINT32_C(0x601A0042),"database_varuint_2",sxd_database_varuint_2_fields,SX_COUNT(sxd_database_varuint_2_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_3_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 3, SX_NONE),
};
static const sx_layout sxd_database_varuint_3 = {UINT32_C(0x601A0043),"database_varuint_3",sxd_database_varuint_3_fields,SX_COUNT(sxd_database_varuint_3_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_4_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 4, SX_NONE),
};
static const sx_layout sxd_database_varuint_4 = {UINT32_C(0x601A0044),"database_varuint_4",sxd_database_varuint_4_fields,SX_COUNT(sxd_database_varuint_4_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_5_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 5, SX_NONE),
};
static const sx_layout sxd_database_varuint_5 = {UINT32_C(0x601A0045),"database_varuint_5",sxd_database_varuint_5_fields,SX_COUNT(sxd_database_varuint_5_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_6_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 6, SX_NONE),
};
static const sx_layout sxd_database_varuint_6 = {UINT32_C(0x601A0046),"database_varuint_6",sxd_database_varuint_6_fields,SX_COUNT(sxd_database_varuint_6_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_7_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 7, SX_NONE),
};
static const sx_layout sxd_database_varuint_7 = {UINT32_C(0x601A0047),"database_varuint_7",sxd_database_varuint_7_fields,SX_COUNT(sxd_database_varuint_7_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_8_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 8, SX_NONE),
};
static const sx_layout sxd_database_varuint_8 = {UINT32_C(0x601A0048),"database_varuint_8",sxd_database_varuint_8_fields,SX_COUNT(sxd_database_varuint_8_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_9_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 9, SX_NONE),
};
static const sx_layout sxd_database_varuint_9 = {UINT32_C(0x601A0049),"database_varuint_9",sxd_database_varuint_9_fields,SX_COUNT(sxd_database_varuint_9_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_10_fields[] = {
    SX_FIELD("value", "uleb128_64", 0, 10, SX_NONE),
};
static const sx_layout sxd_database_varuint_10 = {UINT32_C(0x601A004A),"database_varuint_10",sxd_database_varuint_10_fields,SX_COUNT(sxd_database_varuint_10_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_1_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 1, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_1 = {UINT32_C(0x601A004B),"database_varuint_offset_1",sxd_database_varuint_offset_1_fields,SX_COUNT(sxd_database_varuint_offset_1_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_2_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 2, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_2 = {UINT32_C(0x601A004C),"database_varuint_offset_2",sxd_database_varuint_offset_2_fields,SX_COUNT(sxd_database_varuint_offset_2_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_3_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 3, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_3 = {UINT32_C(0x601A004D),"database_varuint_offset_3",sxd_database_varuint_offset_3_fields,SX_COUNT(sxd_database_varuint_offset_3_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_4_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 4, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_4 = {UINT32_C(0x601A004E),"database_varuint_offset_4",sxd_database_varuint_offset_4_fields,SX_COUNT(sxd_database_varuint_offset_4_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_5_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 5, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_5 = {UINT32_C(0x601A004F),"database_varuint_offset_5",sxd_database_varuint_offset_5_fields,SX_COUNT(sxd_database_varuint_offset_5_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_6_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 6, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_6 = {UINT32_C(0x601A0050),"database_varuint_offset_6",sxd_database_varuint_offset_6_fields,SX_COUNT(sxd_database_varuint_offset_6_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_7_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 7, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_7 = {UINT32_C(0x601A0051),"database_varuint_offset_7",sxd_database_varuint_offset_7_fields,SX_COUNT(sxd_database_varuint_offset_7_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_8_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 8, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_8 = {UINT32_C(0x601A0052),"database_varuint_offset_8",sxd_database_varuint_offset_8_fields,SX_COUNT(sxd_database_varuint_offset_8_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_9_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 9, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_9 = {UINT32_C(0x601A0053),"database_varuint_offset_9",sxd_database_varuint_offset_9_fields,SX_COUNT(sxd_database_varuint_offset_9_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_offset_10_fields[] = {
    SX_FIELD("data_offset", "uleb128_64", 0, 10, SX_OFFSET),
};
static const sx_layout sxd_database_varuint_offset_10 = {UINT32_C(0x601A0054),"database_varuint_offset_10",sxd_database_varuint_offset_10_fields,SX_COUNT(sxd_database_varuint_offset_10_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_1_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 1, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_1 = {UINT32_C(0x601A0055),"database_varuint_size_1",sxd_database_varuint_size_1_fields,SX_COUNT(sxd_database_varuint_size_1_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_2_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 2, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_2 = {UINT32_C(0x601A0056),"database_varuint_size_2",sxd_database_varuint_size_2_fields,SX_COUNT(sxd_database_varuint_size_2_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_3_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 3, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_3 = {UINT32_C(0x601A0057),"database_varuint_size_3",sxd_database_varuint_size_3_fields,SX_COUNT(sxd_database_varuint_size_3_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_4_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 4, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_4 = {UINT32_C(0x601A0058),"database_varuint_size_4",sxd_database_varuint_size_4_fields,SX_COUNT(sxd_database_varuint_size_4_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_5_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 5, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_5 = {UINT32_C(0x601A0059),"database_varuint_size_5",sxd_database_varuint_size_5_fields,SX_COUNT(sxd_database_varuint_size_5_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_6_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 6, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_6 = {UINT32_C(0x601A005A),"database_varuint_size_6",sxd_database_varuint_size_6_fields,SX_COUNT(sxd_database_varuint_size_6_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_7_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 7, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_7 = {UINT32_C(0x601A005B),"database_varuint_size_7",sxd_database_varuint_size_7_fields,SX_COUNT(sxd_database_varuint_size_7_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_8_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 8, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_8 = {UINT32_C(0x601A005C),"database_varuint_size_8",sxd_database_varuint_size_8_fields,SX_COUNT(sxd_database_varuint_size_8_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_9_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 9, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_9 = {UINT32_C(0x601A005D),"database_varuint_size_9",sxd_database_varuint_size_9_fields,SX_COUNT(sxd_database_varuint_size_9_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_size_10_fields[] = {
    SX_FIELD("data_size", "uleb128_64", 0, 10, SX_SIZE),
};
static const sx_layout sxd_database_varuint_size_10 = {UINT32_C(0x601A005E),"database_varuint_size_10",sxd_database_varuint_size_10_fields,SX_COUNT(sxd_database_varuint_size_10_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_1_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 1, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_1 = {UINT32_C(0x601A005F),"database_varuint_count_1",sxd_database_varuint_count_1_fields,SX_COUNT(sxd_database_varuint_count_1_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_2_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_2 = {UINT32_C(0x601A0060),"database_varuint_count_2",sxd_database_varuint_count_2_fields,SX_COUNT(sxd_database_varuint_count_2_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_3_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 3, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_3 = {UINT32_C(0x601A0061),"database_varuint_count_3",sxd_database_varuint_count_3_fields,SX_COUNT(sxd_database_varuint_count_3_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_4_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_4 = {UINT32_C(0x601A0062),"database_varuint_count_4",sxd_database_varuint_count_4_fields,SX_COUNT(sxd_database_varuint_count_4_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_5_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 5, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_5 = {UINT32_C(0x601A0063),"database_varuint_count_5",sxd_database_varuint_count_5_fields,SX_COUNT(sxd_database_varuint_count_5_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_6_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 6, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_6 = {UINT32_C(0x601A0064),"database_varuint_count_6",sxd_database_varuint_count_6_fields,SX_COUNT(sxd_database_varuint_count_6_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_7_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 7, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_7 = {UINT32_C(0x601A0065),"database_varuint_count_7",sxd_database_varuint_count_7_fields,SX_COUNT(sxd_database_varuint_count_7_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_8_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 8, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_8 = {UINT32_C(0x601A0066),"database_varuint_count_8",sxd_database_varuint_count_8_fields,SX_COUNT(sxd_database_varuint_count_8_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_9_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 9, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_9 = {UINT32_C(0x601A0067),"database_varuint_count_9",sxd_database_varuint_count_9_fields,SX_COUNT(sxd_database_varuint_count_9_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_count_10_fields[] = {
    SX_FIELD("item_count", "uleb128_64", 0, 10, SX_COUNT_PROP),
};
static const sx_layout sxd_database_varuint_count_10 = {UINT32_C(0x601A0068),"database_varuint_count_10",sxd_database_varuint_count_10_fields,SX_COUNT(sxd_database_varuint_count_10_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_1_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 1, SX_ID),
};
static const sx_layout sxd_database_varuint_id_1 = {UINT32_C(0x601A0069),"database_varuint_id_1",sxd_database_varuint_id_1_fields,SX_COUNT(sxd_database_varuint_id_1_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_2_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 2, SX_ID),
};
static const sx_layout sxd_database_varuint_id_2 = {UINT32_C(0x601A006A),"database_varuint_id_2",sxd_database_varuint_id_2_fields,SX_COUNT(sxd_database_varuint_id_2_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_3_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 3, SX_ID),
};
static const sx_layout sxd_database_varuint_id_3 = {UINT32_C(0x601A006B),"database_varuint_id_3",sxd_database_varuint_id_3_fields,SX_COUNT(sxd_database_varuint_id_3_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_4_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 4, SX_ID),
};
static const sx_layout sxd_database_varuint_id_4 = {UINT32_C(0x601A006C),"database_varuint_id_4",sxd_database_varuint_id_4_fields,SX_COUNT(sxd_database_varuint_id_4_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_5_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 5, SX_ID),
};
static const sx_layout sxd_database_varuint_id_5 = {UINT32_C(0x601A006D),"database_varuint_id_5",sxd_database_varuint_id_5_fields,SX_COUNT(sxd_database_varuint_id_5_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_6_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 6, SX_ID),
};
static const sx_layout sxd_database_varuint_id_6 = {UINT32_C(0x601A006E),"database_varuint_id_6",sxd_database_varuint_id_6_fields,SX_COUNT(sxd_database_varuint_id_6_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_7_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 7, SX_ID),
};
static const sx_layout sxd_database_varuint_id_7 = {UINT32_C(0x601A006F),"database_varuint_id_7",sxd_database_varuint_id_7_fields,SX_COUNT(sxd_database_varuint_id_7_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_8_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 8, SX_ID),
};
static const sx_layout sxd_database_varuint_id_8 = {UINT32_C(0x601A0070),"database_varuint_id_8",sxd_database_varuint_id_8_fields,SX_COUNT(sxd_database_varuint_id_8_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_9_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 9, SX_ID),
};
static const sx_layout sxd_database_varuint_id_9 = {UINT32_C(0x601A0071),"database_varuint_id_9",sxd_database_varuint_id_9_fields,SX_COUNT(sxd_database_varuint_id_9_fields),SX_LE};

static const xx_data_struct_field_desc sxd_database_varuint_id_10_fields[] = {
    SX_FIELD("identifier", "uleb128_64", 0, 10, SX_ID),
};
static const sx_layout sxd_database_varuint_id_10 = {UINT32_C(0x601A0072),"database_varuint_id_10",sxd_database_varuint_id_10_fields,SX_COUNT(sxd_database_varuint_id_10_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_1_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 1, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_1 = {UINT32_C(0x601A0073),"orc_protobuf_key_1",sxd_orc_protobuf_key_1_fields,SX_COUNT(sxd_orc_protobuf_key_1_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_2_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 2, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_2 = {UINT32_C(0x601A0074),"orc_protobuf_key_2",sxd_orc_protobuf_key_2_fields,SX_COUNT(sxd_orc_protobuf_key_2_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_3_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 3, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_3 = {UINT32_C(0x601A0075),"orc_protobuf_key_3",sxd_orc_protobuf_key_3_fields,SX_COUNT(sxd_orc_protobuf_key_3_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_4_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 4, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_4 = {UINT32_C(0x601A0076),"orc_protobuf_key_4",sxd_orc_protobuf_key_4_fields,SX_COUNT(sxd_orc_protobuf_key_4_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_5_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 5, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_5 = {UINT32_C(0x601A0077),"orc_protobuf_key_5",sxd_orc_protobuf_key_5_fields,SX_COUNT(sxd_orc_protobuf_key_5_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_6_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 6, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_6 = {UINT32_C(0x601A0078),"orc_protobuf_key_6",sxd_orc_protobuf_key_6_fields,SX_COUNT(sxd_orc_protobuf_key_6_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_7_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 7, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_7 = {UINT32_C(0x601A0079),"orc_protobuf_key_7",sxd_orc_protobuf_key_7_fields,SX_COUNT(sxd_orc_protobuf_key_7_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_8_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 8, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_8 = {UINT32_C(0x601A007A),"orc_protobuf_key_8",sxd_orc_protobuf_key_8_fields,SX_COUNT(sxd_orc_protobuf_key_8_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_9_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 9, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_9 = {UINT32_C(0x601A007B),"orc_protobuf_key_9",sxd_orc_protobuf_key_9_fields,SX_COUNT(sxd_orc_protobuf_key_9_fields),SX_LE};

static const xx_data_struct_field_desc sxd_orc_protobuf_key_10_fields[] = {
    SX_FIELD("field_number_and_wire_type", "uleb128_64", 0, 10, SX_ID),
};
static const sx_layout sxd_orc_protobuf_key_10 = {UINT32_C(0x601A007C),"orc_protobuf_key_10",sxd_orc_protobuf_key_10_fields,SX_COUNT(sxd_orc_protobuf_key_10_fields),SX_LE};

static const sx_layout *const sx_databases_layouts[] = {
    &sxd_sequence_header,
    &sxd_sequence_options,
    &sxd_sequence_sync,
    &sxd_sequence_sync_record,
    &sxd_sequence_record,
    &sxd_sequence_text_length_0,
    &sxd_sequence_text_length_1,
    &sxd_sequence_text_length_2,
    &sxd_sequence_text_length_3,
    &sxd_sequence_text_length_4,
    &sxd_sequence_text_length_5,
    &sxd_sequence_text_length_6,
    &sxd_sequence_text_length_7,
    &sxd_sequence_text_length_8,
    &sxd_postgres_header,
    &sxd_postgres_compression_v15,
    &sxd_postgres_compression_legacy,
    &sxd_postgres_time,
    &sxd_postgres_string_length,
    &sxd_postgres_toc_count,
    &sxd_postgres_toc_prefix,
    &sxd_postgres_section,
    &sxd_postgres_data_offset,
    &sxd_postgres_block_header,
    &sxd_postgres_chunk_length,
    &sxd_lmdb_meta_prefix,
    &sxd_lmdb_database,
    &sxd_lmdb_free_database,
    &sxd_lmdb_meta_tail,
    &sxd_lmdb_page_header,
    &sxd_lmdb_node_offset,
    &sxd_lmdb_leaf_node,
    &sxd_lmdb_branch_node,
    &sxd_lmdb_overflow_reference,
    &sxd_lmdb_overflow_page,
    &sxd_leveldb_block_trailer,
    &sxd_leveldb_restart_offset,
    &sxd_leveldb_restart_count,
    &sxd_leveldb_footer_magic,
    &sxd_redis_header,
    &sxd_redis_opcode,
    &sxd_redis_trailer,
    &sxd_redis_expire_milliseconds,
    &sxd_redis_expire_seconds,
    &sxd_redis_frequency,
    &sxd_redis_length_6,
    &sxd_redis_length_14,
    &sxd_redis_length_32,
    &sxd_redis_length_64,
    &sxd_redis_encoded_string,
    &sxd_redis_integer_1,
    &sxd_redis_integer_2,
    &sxd_redis_integer_4,
    &sxd_redis_score_length,
    &sxd_redis_score_binary,
    &sxd_tps_header,
    &sxd_tps_entry,
    &sxd_tps_terminator,
    &sxd_dbz_header,
    &sxd_dbz_index_record,
    &sxd_orc_header,
    &sxd_orc_postscript_length,
    &sxd_orc_fixed32,
    &sxd_orc_fixed64,
    &sxd_database_varuint_1,
    &sxd_database_varuint_2,
    &sxd_database_varuint_3,
    &sxd_database_varuint_4,
    &sxd_database_varuint_5,
    &sxd_database_varuint_6,
    &sxd_database_varuint_7,
    &sxd_database_varuint_8,
    &sxd_database_varuint_9,
    &sxd_database_varuint_10,
    &sxd_database_varuint_offset_1,
    &sxd_database_varuint_offset_2,
    &sxd_database_varuint_offset_3,
    &sxd_database_varuint_offset_4,
    &sxd_database_varuint_offset_5,
    &sxd_database_varuint_offset_6,
    &sxd_database_varuint_offset_7,
    &sxd_database_varuint_offset_8,
    &sxd_database_varuint_offset_9,
    &sxd_database_varuint_offset_10,
    &sxd_database_varuint_size_1,
    &sxd_database_varuint_size_2,
    &sxd_database_varuint_size_3,
    &sxd_database_varuint_size_4,
    &sxd_database_varuint_size_5,
    &sxd_database_varuint_size_6,
    &sxd_database_varuint_size_7,
    &sxd_database_varuint_size_8,
    &sxd_database_varuint_size_9,
    &sxd_database_varuint_size_10,
    &sxd_database_varuint_count_1,
    &sxd_database_varuint_count_2,
    &sxd_database_varuint_count_3,
    &sxd_database_varuint_count_4,
    &sxd_database_varuint_count_5,
    &sxd_database_varuint_count_6,
    &sxd_database_varuint_count_7,
    &sxd_database_varuint_count_8,
    &sxd_database_varuint_count_9,
    &sxd_database_varuint_count_10,
    &sxd_database_varuint_id_1,
    &sxd_database_varuint_id_2,
    &sxd_database_varuint_id_3,
    &sxd_database_varuint_id_4,
    &sxd_database_varuint_id_5,
    &sxd_database_varuint_id_6,
    &sxd_database_varuint_id_7,
    &sxd_database_varuint_id_8,
    &sxd_database_varuint_id_9,
    &sxd_database_varuint_id_10,
    &sxd_orc_protobuf_key_1,
    &sxd_orc_protobuf_key_2,
    &sxd_orc_protobuf_key_3,
    &sxd_orc_protobuf_key_4,
    &sxd_orc_protobuf_key_5,
    &sxd_orc_protobuf_key_6,
    &sxd_orc_protobuf_key_7,
    &sxd_orc_protobuf_key_8,
    &sxd_orc_protobuf_key_9,
    &sxd_orc_protobuf_key_10,
};

static const sx_layout *const sxd_sequence_text_length_rows[] = {&sxd_sequence_text_length_0,&sxd_sequence_text_length_1,&sxd_sequence_text_length_2,&sxd_sequence_text_length_3,&sxd_sequence_text_length_4,&sxd_sequence_text_length_5,&sxd_sequence_text_length_6,&sxd_sequence_text_length_7,&sxd_sequence_text_length_8};
static const sx_layout *const sxd_database_varuint_rows[] = {&sxd_database_varuint_1,&sxd_database_varuint_2,&sxd_database_varuint_3,&sxd_database_varuint_4,&sxd_database_varuint_5,&sxd_database_varuint_6,&sxd_database_varuint_7,&sxd_database_varuint_8,&sxd_database_varuint_9,&sxd_database_varuint_10};
static const sx_layout *const sxd_database_varuint_offset_rows[] = {&sxd_database_varuint_offset_1,&sxd_database_varuint_offset_2,&sxd_database_varuint_offset_3,&sxd_database_varuint_offset_4,&sxd_database_varuint_offset_5,&sxd_database_varuint_offset_6,&sxd_database_varuint_offset_7,&sxd_database_varuint_offset_8,&sxd_database_varuint_offset_9,&sxd_database_varuint_offset_10};
static const sx_layout *const sxd_database_varuint_size_rows[] = {&sxd_database_varuint_size_1,&sxd_database_varuint_size_2,&sxd_database_varuint_size_3,&sxd_database_varuint_size_4,&sxd_database_varuint_size_5,&sxd_database_varuint_size_6,&sxd_database_varuint_size_7,&sxd_database_varuint_size_8,&sxd_database_varuint_size_9,&sxd_database_varuint_size_10};
static const sx_layout *const sxd_database_varuint_count_rows[] = {&sxd_database_varuint_count_1,&sxd_database_varuint_count_2,&sxd_database_varuint_count_3,&sxd_database_varuint_count_4,&sxd_database_varuint_count_5,&sxd_database_varuint_count_6,&sxd_database_varuint_count_7,&sxd_database_varuint_count_8,&sxd_database_varuint_count_9,&sxd_database_varuint_count_10};
static const sx_layout *const sxd_database_varuint_id_rows[] = {&sxd_database_varuint_id_1,&sxd_database_varuint_id_2,&sxd_database_varuint_id_3,&sxd_database_varuint_id_4,&sxd_database_varuint_id_5,&sxd_database_varuint_id_6,&sxd_database_varuint_id_7,&sxd_database_varuint_id_8,&sxd_database_varuint_id_9,&sxd_database_varuint_id_10};
static const sx_layout *const sxd_orc_protobuf_key_rows[] = {&sxd_orc_protobuf_key_1,&sxd_orc_protobuf_key_2,&sxd_orc_protobuf_key_3,&sxd_orc_protobuf_key_4,&sxd_orc_protobuf_key_5,&sxd_orc_protobuf_key_6,&sxd_orc_protobuf_key_7,&sxd_orc_protobuf_key_8,&sxd_orc_protobuf_key_9,&sxd_orc_protobuf_key_10};
static bool sx_databases_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_HADOOP_SEQUENCEFILE:case XX_FILE_TYPE_POSTGRES_CUSTOM:case XX_FILE_TYPE_LMDB_DATA:case XX_FILE_TYPE_LEVELDB_SSTABLE:case XX_FILE_TYPE_REDIS_RDB:case XX_FILE_TYPE_TPS:case XX_FILE_TYPE_DBZ:case XX_FILE_TYPE_APACHE_ORC:return true;default:return false;}
}
static uint16_t sxd_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
static uint32_t sxd_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
static uint64_t sxd_u64(const uint8_t *p){return xx_data_get_u64(p,8,0,false);}
static uint32_t sxd_be32(const uint8_t *p){return xx_data_get_u32(p,4,0,true);}
static bool sxd_can(sx_context *c,uint64_t at,uint64_t n){return at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at&&!xx_pd_is_stopped(c->pd);}
static bool sxd_add(sx_context *c,const sx_layout *l,uint64_t at,uint64_t n){return sxd_can(c,at,n)&&n<=INT64_MAX&&sx_add(c,l,(int64_t)at,(int64_t)n);}
static bool sxd_table(sx_context *c,const sx_layout *l,uint64_t at,unsigned width,uint64_t count){return width&&count<=INT64_MAX/width&&sxd_can(c,at,count*width)&&sx_table(c,l,(int64_t)at,width,count);}
static int sxd_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxd_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxd_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+bytes;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxd_order);return !c->failed;
}
/* Native primary-layout blob readers cap inputs at 64 MiB; metadata walks use
 * the same cap. Every dereference below is preceded by a checked source span. */
static bool sxd_var(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t end,uint64_t *v,const sx_layout *const *rows)
{
    uint64_t start=*at;*v=0;for(unsigned i=0;i<10;i++){if(*at>=end||!sxd_can(c,*at,1))return false;uint8_t x=b[(*at)++];if(i==9&&(x&254))return false;*v|=(uint64_t)(x&127)<<(7*i);if(!(x&128))return !rows||sxd_add(c,rows[i],start,i+1);}return false;
}
static bool sxd_sequence_text(sx_context *c,const uint8_t *b,uint64_t *at)
{
    if(!sxd_can(c,*at,1))return false;uint64_t start=*at,n=0;int marker=(int)(int8_t)b[(*at)++];unsigned width=marker>=-112?0:(unsigned)(marker<-120?-120-marker:-112-marker);
    if(width>8||!sxd_can(c,*at,width))return false;
    if(!width){if(marker<0)return false;n=(unsigned)marker;}else{for(unsigned i=0;i<width;i++)n=(n<<8)|b[(*at)++];if(marker<-120)n=~n;}
    if(n>65536||!sxd_can(c,*at,n)||!sxd_add(c,sxd_sequence_text_length_rows[width],start,width+1))return false;*at+=n;return true;
}
static bool sxd_sequence(sx_context *c,const uint8_t *b)
{
    uint64_t at=4;if(!sxd_add(c,&sxd_sequence_header,0,4)||!sxd_sequence_text(c,b,&at)||!sxd_sequence_text(c,b,&at)||!sxd_can(c,at,6))return false;
    uint32_t n=sxd_be32(b+at+2);if(n>4094||b[at]||b[at+1]||!sxd_add(c,&sxd_sequence_options,at,6))return false;at+=6;
    for(uint32_t i=0;i<n;i++)if(!sxd_sequence_text(c,b,&at)||!sxd_sequence_text(c,b,&at))return false;
    if(!sxd_add(c,&sxd_sequence_sync,at,16))return false;at+=16;
    while(at<(uint64_t)c->size){if(!sxd_can(c,at,4))return false;if(sxd_be32(b+at)==UINT32_MAX){if(!sxd_add(c,&sxd_sequence_sync_record,at,20))return false;at+=20;if(at==(uint64_t)c->size)break;}
        if(!sxd_can(c,at,8))return false;uint32_t n=sxd_be32(b+at),k=sxd_be32(b+at+4);if(k>n||!sxd_add(c,&sxd_sequence_record,at,8)||!sxd_can(c,at+8,n))return false;at+=8+n;
    }return true;
}
static bool sxd_pg_int(sx_context *c,const uint8_t *b,uint64_t *at,int64_t *v,const sx_layout *l)
{
    if(!sxd_can(c,*at,5)||b[*at]>1||sxd_u32(b+*at+1)>INT32_MAX)return false;*v=sxd_u32(b+*at+1);if(b[*at])*v=-*v;if(l&&!sxd_add(c,l,*at,5))return false;*at+=5;return true;
}
static bool sxd_pg_string(sx_context *c,const uint8_t *b,uint64_t *at,bool *null)
{
    int64_t n;if(!sxd_pg_int(c,b,at,&n,&sxd_postgres_string_length)||n< -1||n>65536)return false;*null=n==-1;if(!*null){if(!sxd_can(c,*at,(uint64_t)n))return false;*at+=(uint64_t)n;}return true;
}
static bool sxd_postgres(sx_context *c,const uint8_t *b)
{
    uint64_t at=11;int64_t n,v;bool null;if(!sxd_add(c,&sxd_postgres_header,0,11))return false;
    if(b[6]>=15){if(!sxd_add(c,&sxd_postgres_compression_v15,at++,1))return false;}else if(!sxd_pg_int(c,b,&at,&v,&sxd_postgres_compression_legacy))return false;
    if(!sxd_add(c,&sxd_postgres_time,at,35))return false;at+=35;for(unsigned i=0;i<3;i++)if(!sxd_pg_string(c,b,&at,&null))return false;
    if(!sxd_pg_int(c,b,&at,&n,&sxd_postgres_toc_count)||n<=0||n>1024)return false;
    for(int64_t i=0;i<n;i++){
        if(!sxd_add(c,&sxd_postgres_toc_prefix,at,10))return false;at+=10;for(unsigned j=0;j<4;j++)if(!sxd_pg_string(c,b,&at,&null))return false;
        if(!sxd_pg_int(c,b,&at,&v,&sxd_postgres_section))return false;
        for(unsigned j=0;j<(b[6]>=14?8U:7U);j++)if(!sxd_pg_string(c,b,&at,&null))return false;
        unsigned deps=0;do{if(++deps>1024||!sxd_pg_string(c,b,&at,&null))return false;}while(!null);
        if(!sxd_add(c,&sxd_postgres_data_offset,at,9))return false;at+=9;
    }
    while(at<(uint64_t)c->size){if(!sxd_add(c,&sxd_postgres_block_header,at,6))return false;at+=6;do{if(!sxd_pg_int(c,b,&at,&n,&sxd_postgres_chunk_length)||n<0||!sxd_can(c,at,(uint64_t)n))return false;at+=(uint64_t)n;}while(n);}
    return true;
}
static bool sxd_lmdb(sx_context *c,const uint8_t *b)
{
    if(!sxd_can(c,0,152))return false;uint32_t unit=sxd_u32(b+40);if(unit<512||unit>32768||(unit&(unit-1))||!sxd_can(c,unit,152))return false;
    for(unsigned i=0;i<2;i++){uint64_t at=(uint64_t)i*unit;if(!sxd_add(c,&sxd_lmdb_meta_prefix,at,40)||!sxd_add(c,&sxd_lmdb_free_database,at+40,48)||!sxd_add(c,&sxd_lmdb_database,at+88,48)||!sxd_add(c,&sxd_lmdb_meta_tail,at+136,16))return false;}
    const uint8_t *meta=sxd_u64(b+144)>sxd_u64(b+unit+144)?b:b+unit;uint64_t last=sxd_u64(meta+136);if(last>16383||last>=(uint64_t)c->size/unit)return false;
    for(uint64_t p=2;p<=last;p++){
        uint64_t at=p*unit;if(!sxd_can(c,at,unit))return false;const uint8_t *h=b+at;uint16_t flags=sxd_u16(h+10);
        if(flags==4){uint32_t pages=sxd_u32(h+12);if(!pages||pages>last-p+1||!sxd_add(c,&sxd_lmdb_overflow_page,at,16))return false;p+=pages-1;continue;}
        if(flags!=1&&flags!=2)return false;uint16_t lower=sxd_u16(h+12),upper=sxd_u16(h+14);if(lower<16||lower>upper||upper>unit||(lower&1)||(upper&1))return false;uint32_t n=(lower-16)/2;
        if(!sxd_add(c,&sxd_lmdb_page_header,at,16)||!sxd_table(c,&sxd_lmdb_node_offset,at+16,2,n))return false;
        for(uint32_t i=0;i<n;i++){
            uint16_t off=sxd_u16(h+16+2*i);if(off<upper||off>unit-8)return false;const uint8_t *node=h+off;uint32_t k=sxd_u16(node+6),bytes=sxd_u32(node);
            if(k>unit-off-8||!sxd_add(c,flags==1?&sxd_lmdb_branch_node:&sxd_lmdb_leaf_node,at+off,8))return false;
            if(flags==2){uint16_t nf=sxd_u16(node+4);if(nf==1){if(!sxd_add(c,&sxd_lmdb_overflow_reference,at+off+8+k,8))return false;}else if(nf||bytes>unit-off-8-k)return false;}
        }
    }return true;
}
typedef struct sxd_handle{uint64_t at,size;}sxd_handle;
static bool sxd_level_block(sx_context *c,const uint8_t *b,sxd_handle h,unsigned mode,sxd_handle *handles,size_t *count)
{
    if(h.size<8||h.size>INT64_MAX-5||!sxd_can(c,h.at,h.size+5))return false;uint32_t n=sxd_u32(b+h.at+h.size-4);if(!n||n>4096||(uint64_t)n*4>h.size-4)return false;
    uint64_t end=h.at+h.size-4-(uint64_t)n*4,at=h.at;
    while(at<end){uint64_t shared,key,value;if(!sxd_var(c,b,&at,end,&shared,sxd_database_varuint_size_rows)||!sxd_var(c,b,&at,end,&key,sxd_database_varuint_size_rows)||!sxd_var(c,b,&at,end,&value,sxd_database_varuint_size_rows)||key>end-at||value>end-at-key)return false;at+=key;
        if(mode==1){uint64_t ve=at+value,x,y;if(!sxd_var(c,b,&at,ve,&x,sxd_database_varuint_offset_rows)||!sxd_var(c,b,&at,ve,&y,sxd_database_varuint_size_rows)||at!=ve||*count>=1024)return false;handles[(*count)++]=(sxd_handle){x,y};}else at+=value;
    }
    return sxd_table(c,&sxd_leveldb_restart_offset,end,4,n)&&sxd_add(c,&sxd_leveldb_restart_count,h.at+h.size-4,4)&&sxd_add(c,&sxd_leveldb_block_trailer,h.at+h.size,5);
}
static bool sxd_leveldb(sx_context *c,const uint8_t *b)
{
    if(c->size<48)return false;uint64_t footer=(uint64_t)c->size-48,at=footer;uint64_t v[4];for(unsigned i=0;i<4;i++)if(!sxd_var(c,b,&at,footer+40,&v[i],i%2?sxd_database_varuint_size_rows:sxd_database_varuint_offset_rows))return false;
    if(!sxd_add(c,&sxd_leveldb_footer_magic,footer+40,8))return false;sxd_handle handles[1024];size_t count=0;
    if(!sxd_level_block(c,b,(sxd_handle){v[0],v[1]},2,NULL,NULL)||!sxd_level_block(c,b,(sxd_handle){v[2],v[3]},1,handles,&count))return false;
    for(size_t i=0;i<count;i++)if(!sxd_level_block(c,b,handles[i],0,NULL,NULL))return false;return true;
}
static bool sxd_redis_len(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t *v,bool *encoded)
{
    if(!sxd_can(c,*at,1))return false;uint64_t start=*at;uint8_t x=b[(*at)++];*encoded=x>=192;*v=x&63;
    if(*encoded)return *v<=3&&sxd_add(c,&sxd_redis_encoded_string,start,1);
    if(x<64)return sxd_add(c,&sxd_redis_length_6,start,1);
    if(x<128){if(!sxd_can(c,*at,1))return false;*v=(*v<<8)|b[(*at)++];return sxd_add(c,&sxd_redis_length_14,start,2);}
    unsigned n=x==128?4:x==129?8:0;if(!n||!sxd_can(c,*at,n))return false;*v=n==4?sxd_be32(b+*at):xx_data_get_u64(b+*at,8,0,true);*at+=n;return sxd_add(c,n==4?&sxd_redis_length_32:&sxd_redis_length_64,start,n+1);
}
static bool sxd_redis_plain(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t *v){bool encoded;return sxd_redis_len(c,b,at,v,&encoded)&&!encoded;}
static bool sxd_redis_string(sx_context *c,const uint8_t *b,uint64_t *at)
{
    uint64_t n,m;bool enc;if(!sxd_redis_len(c,b,at,&n,&enc))return false;
    if(enc&&n<3){unsigned width=1U<<(unsigned)n;if(!sxd_add(c,n==0?&sxd_redis_integer_1:n==1?&sxd_redis_integer_2:&sxd_redis_integer_4,*at,width))return false;*at+=width;return true;}
    if(enc){if(!sxd_redis_plain(c,b,at,&n)||!sxd_redis_plain(c,b,at,&m))return false;}
    if(!sxd_can(c,*at,n))return false;*at+=n;return true;
}
static bool sxd_redis(sx_context *c,const uint8_t *b)
{
    uint64_t at=9;if(!sxd_add(c,&sxd_redis_header,0,9))return false;
    while(at<(uint64_t)c->size-8){uint64_t start=at,n;uint8_t type=b[at++];if(type==255)return sxd_add(c,&sxd_redis_trailer,start,9)&&at+8==(uint64_t)c->size;
        if(type==252||type==253||type==249){unsigned width=type==252?8:type==253?4:1;if(!sxd_add(c,type==252?&sxd_redis_expire_milliseconds:type==253?&sxd_redis_expire_seconds:&sxd_redis_frequency,start,width+1))return false;at+=width;continue;}
        if(!sxd_add(c,&sxd_redis_opcode,start,1))return false;
        if(type==250){if(!sxd_redis_string(c,b,&at)||!sxd_redis_string(c,b,&at))return false;continue;}
        if(type==254||type==251||type==248){if(!sxd_redis_plain(c,b,&at,&n)||(type==251&&!sxd_redis_plain(c,b,&at,&n)))return false;continue;}
        if(type>5||!sxd_redis_string(c,b,&at))return false;
        if(!type){if(!sxd_redis_string(c,b,&at))return false;continue;}
        if(!sxd_redis_plain(c,b,&at,&n)||n>65536)return false;
        for(uint64_t i=0;i<n;i++){if(!sxd_redis_string(c,b,&at))return false;if(type==4){if(!sxd_redis_string(c,b,&at))return false;}else if(type==5){if(!sxd_add(c,&sxd_redis_score_binary,at,8))return false;at+=8;}else if(type==3){if(!sxd_can(c,at,1)||!sxd_add(c,&sxd_redis_score_length,at,1))return false;uint8_t len=b[at++];if(len<253){if(!sxd_can(c,at,len))return false;at+=len;}}}
    }return false;
}
static bool sxd_tps(sx_context *c,const uint8_t *b)
{
    uint64_t at=4;if(!sxd_add(c,&sxd_tps_header,0,4))return false;
    while(at<(uint64_t)c->size){if((uint64_t)c->size-at==1){if(b[at]==4&&!sxd_add(c,&sxd_tps_terminator,at,1))return false;break;}if(!sxd_can(c,at,22)||b[at]!=2)break;
        int64_t coded=(int32_t)sxd_u32(b+at+14);if(coded<0)coded=-coded;coded-=4;if(coded<0||coded>0x10000000)return false;uint64_t stored=(uint64_t)coded+((uint64_t)coded+4+16383)/16384+1;
        if(!sxd_can(c,at+22,stored)||!sxd_add(c,&sxd_tps_entry,at,22))return false;at+=22+stored;
    }return true;
}
static bool sxd_decimal(const uint8_t *p,unsigned n,uint64_t *v)
{
    unsigned i=0;*v=0;while(i<n&&p[i]==' ')i++;if(i==n)return false;for(;i<n;i++){if(p[i]<'0'||p[i]>'9'||*v>(UINT64_MAX-(p[i]-'0'))/10)return false;*v=*v*10+(p[i]-'0');}return true;
}
static bool sxd_dbz(sx_context *c,const uint8_t *b)
{
    uint64_t first;if(!sxd_can(c,0,59)||!sxd_decimal(b+27+14,9,&first)||first<59||(first-27)%32||first>(uint64_t)c->size)return false;
    if(!sxd_add(c,&sxd_dbz_header,0,27))return false;for(uint64_t at=27;at<first;at+=32){uint64_t offset,size;if(sxd_decimal(b+at+14,9,&offset)&&sxd_decimal(b+at+23,9,&size)&&!sxd_add(c,&sxd_dbz_index_record,at,32))return false;}return true;
}
typedef struct sxd_proto {uint64_t tag,wire,value,at,size;}sxd_proto;
static bool sxd_proto_next(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t end,sxd_proto *f,bool emit,unsigned kind)
{
    uint64_t key;if(!sxd_var(c,b,at,end,&key,emit?sxd_orc_protobuf_key_rows:NULL)||!(key>>3)||(key>>3)>0x1fffffff)return false;
    f->tag=key>>3;f->wire=key&7;f->at=*at;f->size=0;f->value=0;
    if(!f->wire){
        const sx_layout *const *rows=sxd_database_varuint_rows;
        if((kind==1&&(f->tag==1||f->tag==3||f->tag==5||f->tag==7))||(kind==2&&(f->tag==1||f->tag==2))||(kind==3&&f->tag>=2&&f->tag<=4)||(kind==6&&f->tag==3)||(kind==9&&f->tag==11))rows=sxd_database_varuint_size_rows;
        if((kind==2&&(f->tag==6||f->tag==8))||(kind==3&&f->tag==5)||(kind==4&&f->tag==4)||(kind==7&&f->tag==2)||(kind==9&&f->tag==1))rows=sxd_database_varuint_count_rows;
        if(kind==3&&f->tag==1)rows=sxd_database_varuint_offset_rows;
        if((kind==1&&(f->tag==2||f->tag==6))||(kind==2&&(f->tag==9||f->tag==11))||(kind==4&&f->tag==1)||(kind==6&&(f->tag==1||f->tag==2))||(kind==7&&(f->tag==1||f->tag==3)))rows=sxd_database_varuint_id_rows;
        return sxd_var(c,b,at,end,&f->value,emit?rows:NULL);
    }
    if(f->wire==2){if(!sxd_var(c,b,at,end,&f->size,emit?sxd_database_varuint_size_rows:NULL))return false;f->at=*at;}
    else if(f->wire==1)f->size=8;else if(f->wire==5)f->size=4;else return false;
    if(*at>end||f->size>end-*at||!sxd_can(c,*at,f->size))return false;
    if(emit&&(f->wire==1||f->wire==5)&&!sxd_add(c,f->wire==1?&sxd_orc_fixed64:&sxd_orc_fixed32,*at,f->size))return false;*at+=f->size;return true;
}
/* Interpret only the protocol-message relationships defined by ORC. String,
 * packed numeric and column-data bytes are never guessed to be submessages. */
static bool sxd_orc_proto(sx_context *c,const uint8_t *b,uint64_t at,uint64_t end,unsigned kind,unsigned depth)
{
    if(depth>16||end>(uint64_t)c->size||at>end)return false;unsigned work=0;
    while(at<end){sxd_proto f;if(++work>100000||!sxd_proto_next(c,b,&at,end,&f,true,kind))return false;if(f.wire!=2)continue;
        unsigned child=0;bool packed=false;
        if(kind==1&&f.tag==4)packed=true;
        if(kind==2){if(f.tag==3)child=3;else if(f.tag==4)child=4;else if(f.tag==5)child=8;else if(f.tag==7)child=9;}
        if(kind==4){if(f.tag==2)packed=true;else if(f.tag==7)child=8;}
        if(kind==5){if(f.tag==1)child=6;else if(f.tag==2)child=7;}
        if(kind==10&&f.tag==1)child=11;
        if(kind==11&&f.tag==1)child=9;
        if(child&&!sxd_orc_proto(c,b,f.at,f.at+f.size,child,depth+1))return false;
        if(packed){uint64_t p=f.at,v;while(p<f.at+f.size)if(!sxd_var(c,b,&p,f.at+f.size,&v,sxd_database_varuint_rows))return false;}
    }return at==end;
}
static bool sxd_orc(sx_context *c,const uint8_t *b)
{
    if(c->size<4)return false;uint64_t n=(uint64_t)c->size,ps=b[n-1];if(!ps||ps>n-4)return false;uint64_t p=n-1-ps,end=n-1,fl=0,ml=0;
    while(p<end){sxd_proto f;if(!sxd_proto_next(c,b,&p,end,&f,false,0))return false;if(f.tag==1)fl=f.value;else if(f.tag==5)ml=f.value;}
    if(fl>n-ps-4||ml>n-ps-4-fl)return false;uint64_t footer=n-1-ps-fl,meta=footer-ml;
    if(!sxd_add(c,&sxd_orc_header,0,3)||!sxd_add(c,&sxd_orc_postscript_length,n-1,1)||!sxd_orc_proto(c,b,n-1-ps,n-1,1,0)||!sxd_orc_proto(c,b,footer,footer+fl,2,0)||!sxd_orc_proto(c,b,meta,footer,10,0))return false;
    p=footer;while(p<footer+fl){sxd_proto f;if(!sxd_proto_next(c,b,&p,footer+fl,&f,false,0))return false;if(f.tag==3&&f.wire==2){uint64_t q=f.at,v[5]={0,0,0,0,0};while(q<f.at+f.size){sxd_proto x;if(!sxd_proto_next(c,b,&q,f.at+f.size,&x,false,0)||x.wire||x.tag<1||x.tag>5)return false;v[x.tag-1]=x.value;}
        if(v[0]>meta||v[1]>meta-v[0]||v[2]>meta-v[0]-v[1]||v[3]>meta-v[0]-v[1]-v[2])return false;uint64_t sf=v[0]+v[1]+v[2];if(!sxd_orc_proto(c,b,sf,sf+v[3],5,0))return false;
    }}return true;
}
static bool sx_databases_build(sx_context *c)
{
    if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>67108864||xx_pd_is_stopped(c->pd))return false;
    uint8_t *b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=false;
    for(int64_t at=0;at<c->size;){size_t n=c->size-at>65536?65536:(size_t)(c->size-at);if(!sx_read(c,at,b+at,n))goto done;at+=(int64_t)n;}
    switch(c->f->file_type){case XX_FILE_TYPE_HADOOP_SEQUENCEFILE:ok=sxd_sequence(c,b);break;case XX_FILE_TYPE_POSTGRES_CUSTOM:ok=sxd_postgres(c,b);break;case XX_FILE_TYPE_LMDB_DATA:ok=sxd_lmdb(c,b);break;case XX_FILE_TYPE_LEVELDB_SSTABLE:ok=sxd_leveldb(c,b);break;case XX_FILE_TYPE_REDIS_RDB:ok=sxd_redis(c,b);break;case XX_FILE_TYPE_TPS:ok=sxd_tps(c,b);break;case XX_FILE_TYPE_DBZ:ok=sxd_dbz(c,b);break;case XX_FILE_TYPE_APACHE_ORC:ok=sxd_orc(c,b);break;default:break;}
    if(ok)ok=sxd_finish(c);
done:xx_mem_free(b);return ok;
}
static bool sx_databases_comment(xx_data_struct_record *r,uint32_t id)
{
    if(id<UINT32_C(0x601A0000)||id>=UINT32_C(0x601B0000)||!r||!r->name||!r->type)return true;
    const wchar_t *comment=NULL;uint64_t v=0;
    /* Text and raw arrays must not be coerced into integers before selection. */
    if(id==sxd_dbz_index_record.id&&xx_var_get_type(&r->value)==XX_VAR_TYPE_UINT64&&(!xx_rt_wcscmp(r->name,L"decimal_payload_offset")||!xx_rt_wcscmp(r->name,L"decimal_payload_size")))comment=L"Right-aligned decimal ASCII on disk; raw bytes retained";
    if(!xx_rt_wcscmp(r->type,L"uleb128_64")){
        if(!xx_rt_wcscmp(r->name,L"field_number_and_wire_type")){v=xx_var_get_u64(&r->value);char a[96];wchar_t w[96];int n=xx_rt_snprintf(a,sizeof(a),"Protobuf field %llu; wire type %u",(unsigned long long)(v>>3),(unsigned)(v&7));if(n<0||n>=(int)sizeof(a))return false;for(int i=0;i<=n;i++)w[i]=(unsigned char)a[i];return xx_data_struct_record_set_comment(r,w);}
        if(!(r->property&SX_SIZE))comment=L"Unsigned LEB128; physical encoding retained";
    }
    if(!xx_rt_wcscmp(r->name,L"page_number")||!xx_rt_wcscmp(r->name,L"root_page")||!xx_rt_wcscmp(r->name,L"last_page")||!xx_rt_wcscmp(r->name,L"overflow_page"))comment=L"Page index; multiply by the LMDB page size for a byte offset; UINT64_MAX denotes no root";
    if(!xx_rt_wcscmp(r->name,L"branch_pages")||!xx_rt_wcscmp(r->name,L"leaf_pages")||!xx_rt_wcscmp(r->name,L"overflow_pages")||!xx_rt_wcscmp(r->name,L"page_count"))comment=L"Count of LMDB allocation pages, not bytes";
    if(!xx_rt_wcscmp(r->name,L"node_offset")||!xx_rt_wcscmp(r->name,L"lower_offset")||!xx_rt_wcscmp(r->name,L"upper_offset"))comment=L"Byte offset relative to this LMDB page";
    if(!xx_rt_wcscmp(r->name,L"child_page_low")||!xx_rt_wcscmp(r->name,L"child_page_high"))comment=L"Child page = low32 | (high16 << 32); page index, not byte offset";
    if(!xx_rt_wcscmp(r->name,L"restart_offset"))comment=L"Byte offset relative to the uncompressed LevelDB block";
    if(id==sxd_leveldb_block_trailer.id&&!xx_rt_wcscmp(r->name,L"compression_type"))comment=L"0 = no compression; native reader supported scope";
    if(!xx_rt_wcscmp(r->name,L"masked_crc32c"))comment=L"Masked CRC32C of block bytes and compression byte";
    if(id==sxd_tps_entry.id&&!xx_rt_wcscmp(r->name,L"coded_length_plus_four"))comment=L"Coded payload bytes = abs(stored signed value) - 4; framing bytes are separate";
    if(id==sxd_tps_entry.id&&!xx_rt_wcscmp(r->name,L"encoded_uncompressed_length"))comment=L"Uncompressed bytes = stored value XOR 0x80808080";
    if(!xx_rt_wcscmp(r->name,L"marker")||!xx_rt_wcscmp(r->name,L"encoded_magnitude"))comment=L"Hadoop VInt: prefix encodes byte count/sign; big-endian magnitude is complemented for negative encoding";
    if(!xx_rt_wcscmp(r->name,L"compression_sign")||!xx_rt_wcscmp(r->name,L"length_sign")||!xx_rt_wcscmp(r->name,L"dump_id_sign")||!xx_rt_wcscmp(r->name,L"section_sign"))comment=L"PostgreSQL signed magnitude: 0 = nonnegative, 1 = negative";
    if(id==sxd_postgres_string_length.id&&!xx_rt_wcscmp(r->name,L"length_magnitude"))comment=L"Signed-magnitude string length; sign 1 and magnitude 1 denotes NULL";
    if(id==sxd_postgres_time.id)comment=L"PostgreSQL signed-magnitude struct tm component; month is zero-based and year is since 1900";
    if(id==sxd_postgres_data_offset.id&&!xx_rt_wcscmp(r->name,L"offset_state"))comment=L"1 = offset not set; 2 = offset set; 3 = no data";
    if(!xx_rt_wcscmp(r->name,L"encoding_and_length"))comment=L"Redis 6-bit literal length or count";
    if(!xx_rt_wcscmp(r->name,L"encoding_and_length_high")||!xx_rt_wcscmp(r->name,L"length_low"))comment=L"Redis 14-bit length/count = ((first byte & 0x3F) << 8) | second byte";
    if(!xx_rt_wcscmp(r->name,L"encoded_length"))comment=L"Redis literal length or count, in big-endian order";
    if(!xx_rt_wcscmp(r->name,L"encoding_and_integer_type"))comment=L"0xC0 = int8; 0xC1 = int16; 0xC2 = int32; 0xC3 = LZF string";
    if(id==sxd_redis_opcode.id||id==sxd_redis_trailer.id){if(!xx_rt_wcscmp(r->name,L"opcode")||!xx_rt_wcscmp(r->name,L"end_opcode")){v=xx_var_get_u64(&r->value);switch(v){case 0:comment=L"RDB_TYPE_STRING";break;case 1:comment=L"RDB_TYPE_LIST";break;case 2:comment=L"RDB_TYPE_SET";break;case 3:comment=L"RDB_TYPE_ZSET";break;case 4:comment=L"RDB_TYPE_HASH";break;case 5:comment=L"RDB_TYPE_ZSET_2";break;case 248:comment=L"RDB_OPCODE_IDLE";break;case 250:comment=L"RDB_OPCODE_AUX";break;case 251:comment=L"RDB_OPCODE_RESIZEDB";break;case 254:comment=L"RDB_OPCODE_SELECTDB";break;case 255:comment=L"RDB_OPCODE_EOF";break;default:break;}}}
    if((id==sxd_lmdb_meta_prefix.id&&!xx_rt_wcscmp(r->name,L"page_flags"))||((id==sxd_lmdb_page_header.id||id==sxd_lmdb_overflow_page.id)&&!xx_rt_wcscmp(r->name,L"flags"))){v=xx_var_get_u64(&r->value);comment=v==1?L"P_BRANCH":v==2?L"P_LEAF":v==4?L"P_OVERFLOW":v==8?L"P_META":L"LMDB page flags";}
    if((id==sxd_lmdb_database.id||id==sxd_lmdb_free_database.id)&&!xx_rt_wcscmp(r->name,L"flags")){v=xx_var_get_u64(&r->value);comment=v==8?L"MDB_INTEGERKEY":v==0?L"No persistent database flags":L"LMDB persistent database flags";}
    if(id==sxd_lmdb_leaf_node.id&&!xx_rt_wcscmp(r->name,L"flags")){v=xx_var_get_u64(&r->value);comment=v==1?L"F_BIGDATA: value is an overflow-page reference":L"Inline leaf value";}
    if(id==sxd_postgres_header.id&&!xx_rt_wcscmp(r->name,L"format"))comment=L"archCustom = 1";
    if(id==sxd_postgres_compression_v15.id)comment=L"PG_COMPRESSION_NONE = 0; native uncompressed scope";
    if(id==sxd_postgres_section.id&&!xx_rt_wcscmp(r->name,L"section_magnitude")){v=xx_var_get_u64(&r->value);comment=v==0?L"SECTION_NONE":v==1?L"SECTION_PRE_DATA":v==2?L"SECTION_DATA":v==3?L"SECTION_POST_DATA":NULL;}
    if(id==sxd_postgres_block_header.id&&!xx_rt_wcscmp(r->name,L"block_type"))comment=L"BLK_DATA = 1";
    if(id==sxd_sequence_options.id&&(!xx_rt_wcscmp(r->name,L"compression")||!xx_rt_wcscmp(r->name,L"block_compression")))comment=L"0 = false; native uncompressed SequenceFile scope";
    if(id==sxd_redis_frequency.id&&!xx_rt_wcscmp(r->name,L"frequency"))comment=L"Encoded logarithmic LFU frequency counter; not a literal access count";
    if(!xx_rt_wcscmp(r->name,L"crc64"))comment=L"Redis CRC64; zero disables checksum verification";
    if(!xx_rt_wcscmp(r->name,L"ieee754_binary64_bits"))comment=L"Little-endian IEEE-754 binary64 score bits";
    return !comment||xx_data_struct_record_set_comment(r,comment);
}
