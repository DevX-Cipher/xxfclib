/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical database metadata. Native readers validate supported grammars. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_databases.h"
static const xx_data_struct_field_desc sxd_sequence_options_fields[] = {
    SX_FIELD("compression", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("block_compression", "uint8", 1, 1, SX_FLAGS),
    SX_FIELD("metadata_entries", "int32", 2, 4, SX_COUNT_PROP),
};
const sx_layout sxd_sequence_options = {UINT32_C(0x601A0002),"sequence_options",sxd_sequence_options_fields,SX_COUNT(sxd_sequence_options_fields),SX_BE};
static const xx_data_struct_field_desc sxd_postgres_header_fields[] = {
    SX_FIELD("magic", "char[5]", 0, 5, SX_SIGNATURE),
    SX_FIELD("version_major", "uint8", 5, 1, SX_ID),
    SX_FIELD("version_minor", "uint8", 6, 1, SX_ID),
    SX_FIELD("version_revision", "uint8", 7, 1, SX_ID),
    SX_FIELD("integer_size", "uint8", 8, 1, SX_SIZE),
    SX_FIELD("offset_size", "uint8", 9, 1, SX_SIZE),
    SX_FIELD("format", "uint8", 10, 1, SX_ID),
};
const sx_layout sxd_postgres_header = {UINT32_C(0x601A000F),"postgres_header",sxd_postgres_header_fields,SX_COUNT(sxd_postgres_header_fields),SX_LE};
static const xx_data_struct_field_desc sxd_postgres_compression_v15_fields[] = {
    SX_FIELD("compression_algorithm", "uint8", 0, 1, SX_ID),
};
const sx_layout sxd_postgres_compression_v15 = {UINT32_C(0x601A0010),"postgres_compression_v15",sxd_postgres_compression_v15_fields,SX_COUNT(sxd_postgres_compression_v15_fields),SX_LE};
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
const sx_layout sxd_postgres_time = {UINT32_C(0x601A0012),"postgres_time",sxd_postgres_time_fields,SX_COUNT(sxd_postgres_time_fields),SX_LE};
static const xx_data_struct_field_desc sxd_postgres_string_length_fields[] = {
    SX_FIELD("length_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("length_magnitude", "uint32", 1, 4, SX_NONE),
};
const sx_layout sxd_postgres_string_length = {UINT32_C(0x601A0013),"postgres_string_length",sxd_postgres_string_length_fields,SX_COUNT(sxd_postgres_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxd_postgres_section_fields[] = {
    SX_FIELD("section_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("section_magnitude", "uint32", 1, 4, SX_ID),
};
const sx_layout sxd_postgres_section = {UINT32_C(0x601A0016),"postgres_section",sxd_postgres_section_fields,SX_COUNT(sxd_postgres_section_fields),SX_LE};
static const xx_data_struct_field_desc sxd_postgres_data_offset_fields[] = {
    SX_FIELD("offset_state", "uint8", 0, 1, SX_ID),
    SX_FIELD("data_offset", "uint64", 1, 8, SX_OFFSET),
};
const sx_layout sxd_postgres_data_offset = {UINT32_C(0x601A0017),"postgres_data_offset",sxd_postgres_data_offset_fields,SX_COUNT(sxd_postgres_data_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxd_postgres_block_header_fields[] = {
    SX_FIELD("block_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("dump_id_sign", "uint8", 1, 1, SX_NONE),
    SX_FIELD("dump_id_magnitude", "uint32", 2, 4, SX_ID),
};
const sx_layout sxd_postgres_block_header = {UINT32_C(0x601A0018),"postgres_block_header",sxd_postgres_block_header_fields,SX_COUNT(sxd_postgres_block_header_fields),SX_LE};
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
const sx_layout sxd_lmdb_meta_prefix = {UINT32_C(0x601A001A),"lmdb_meta_prefix",sxd_lmdb_meta_prefix_fields,SX_COUNT(sxd_lmdb_meta_prefix_fields),SX_LE};
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
const sx_layout sxd_lmdb_database = {UINT32_C(0x601A001B),"lmdb_database",sxd_lmdb_database_fields,SX_COUNT(sxd_lmdb_database_fields),SX_LE};
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
const sx_layout sxd_lmdb_free_database = {UINT32_C(0x601A001C),"lmdb_free_database",sxd_lmdb_free_database_fields,SX_COUNT(sxd_lmdb_free_database_fields),SX_LE};
static const xx_data_struct_field_desc sxd_lmdb_page_header_fields[] = {
    SX_FIELD("page_number", "uint64", 0, 8, SX_NONE),
    SX_FIELD("pad", "uint16", 8, 2, SX_RESERVED),
    SX_FIELD("flags", "uint16", 10, 2, SX_FLAGS),
    SX_FIELD("lower_offset", "uint16", 12, 2, SX_OFFSET),
    SX_FIELD("upper_offset", "uint16", 14, 2, SX_OFFSET),
};
const sx_layout sxd_lmdb_page_header = {UINT32_C(0x601A001E),"lmdb_page_header",sxd_lmdb_page_header_fields,SX_COUNT(sxd_lmdb_page_header_fields),SX_LE};
static const xx_data_struct_field_desc sxd_lmdb_leaf_node_fields[] = {
    SX_FIELD("data_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("flags", "uint16", 4, 2, SX_FLAGS),
    SX_FIELD("key_size", "uint16", 6, 2, SX_SIZE),
};
const sx_layout sxd_lmdb_leaf_node = {UINT32_C(0x601A0020),"lmdb_leaf_node",sxd_lmdb_leaf_node_fields,SX_COUNT(sxd_lmdb_leaf_node_fields),SX_LE};
static const xx_data_struct_field_desc sxd_lmdb_overflow_page_fields[] = {
    SX_FIELD("page_number", "uint64", 0, 8, SX_NONE),
    SX_FIELD("pad", "uint16", 8, 2, SX_RESERVED),
    SX_FIELD("flags", "uint16", 10, 2, SX_FLAGS),
    SX_FIELD("page_count", "uint32", 12, 4, SX_COUNT_PROP),
};
const sx_layout sxd_lmdb_overflow_page = {UINT32_C(0x601A0023),"lmdb_overflow_page",sxd_lmdb_overflow_page_fields,SX_COUNT(sxd_lmdb_overflow_page_fields),SX_LE};
static const xx_data_struct_field_desc sxd_leveldb_block_trailer_fields[] = {
    SX_FIELD("compression_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("masked_crc32c", "uint32", 1, 4, SX_CHECKSUM),
};
const sx_layout sxd_leveldb_block_trailer = {UINT32_C(0x601A0024),"leveldb_block_trailer",sxd_leveldb_block_trailer_fields,SX_COUNT(sxd_leveldb_block_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_opcode_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
};
const sx_layout sxd_redis_opcode = {UINT32_C(0x601A0029),"redis_opcode",sxd_redis_opcode_fields,SX_COUNT(sxd_redis_opcode_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_trailer_fields[] = {
    SX_FIELD("end_opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("crc64", "uint64", 1, 8, SX_CHECKSUM),
};
const sx_layout sxd_redis_trailer = {UINT32_C(0x601A002A),"redis_trailer",sxd_redis_trailer_fields,SX_COUNT(sxd_redis_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_frequency_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("frequency", "uint8", 1, 1, SX_NONE),
};
const sx_layout sxd_redis_frequency = {UINT32_C(0x601A002D),"redis_frequency",sxd_redis_frequency_fields,SX_COUNT(sxd_redis_frequency_fields),SX_LE};
static const xx_data_struct_field_desc sxd_tps_entry_fields[] = {
    SX_FIELD("entry_tag", "uint8", 0, 1, SX_ID),
    SX_FIELD("name_length", "uint8", 1, 1, SX_SIZE),
    SX_FIELD("name", "char[12]", 2, 12, SX_STRING),
    SX_FIELD("coded_length_plus_four", "int32", 14, 4, SX_NONE),
    SX_FIELD("encoded_uncompressed_length", "uint32", 18, 4, SX_NONE),
};
const sx_layout sxd_tps_entry = {UINT32_C(0x601A0039),"tps_entry",sxd_tps_entry_fields,SX_COUNT(sxd_tps_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxd_dbz_index_record_fields[] = {
    SX_FIELD("name", "char[14]", 0, 14, SX_STRING),
    SX_FIELD("decimal_payload_offset", "ascii_decimal[9]", 14, 9, SX_OFFSET),
    SX_FIELD("decimal_payload_size", "ascii_decimal[9]", 23, 9, SX_SIZE),
};
const sx_layout sxd_dbz_index_record = {UINT32_C(0x601A003C),"dbz_index_record",sxd_dbz_index_record_fields,SX_COUNT(sxd_dbz_index_record_fields),SX_LE};
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
const sx_layout *const sxd_database_varuint_offset_rows[] = {&sxd_database_varuint_offset_1,&sxd_database_varuint_offset_2,&sxd_database_varuint_offset_3,&sxd_database_varuint_offset_4,&sxd_database_varuint_offset_5,&sxd_database_varuint_offset_6,&sxd_database_varuint_offset_7,&sxd_database_varuint_offset_8,&sxd_database_varuint_offset_9,&sxd_database_varuint_offset_10};
const sx_layout *const sxd_database_varuint_size_rows[] = {&sxd_database_varuint_size_1,&sxd_database_varuint_size_2,&sxd_database_varuint_size_3,&sxd_database_varuint_size_4,&sxd_database_varuint_size_5,&sxd_database_varuint_size_6,&sxd_database_varuint_size_7,&sxd_database_varuint_size_8,&sxd_database_varuint_size_9,&sxd_database_varuint_size_10};
static bool sx_databases_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_HADOOP_SEQUENCEFILE:case XX_FILE_TYPE_POSTGRES_CUSTOM:case XX_FILE_TYPE_LMDB_DATA:case XX_FILE_TYPE_LEVELDB_SSTABLE:case XX_FILE_TYPE_REDIS_RDB:case XX_FILE_TYPE_TPS:case XX_FILE_TYPE_DBZ:case XX_FILE_TYPE_APACHE_ORC:return true;default:return false;}
}
uint32_t sxd_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
uint32_t sxd_be32(const uint8_t *p){return xx_data_get_u32(p,4,0,true);}
bool sxd_can(sx_context *c,uint64_t at,uint64_t n){return at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at&&!xx_pd_is_stopped(c->pd);}
bool sxd_add(sx_context *c,const sx_layout *l,uint64_t at,uint64_t n){return sxd_can(c,at,n)&&n<=INT64_MAX&&sx_add(c,l,(int64_t)at,(int64_t)n);}
bool sxd_table(sx_context *c,const sx_layout *l,uint64_t at,unsigned width,uint64_t count){return width&&count<=INT64_MAX/width&&sxd_can(c,at,count*width)&&sx_table(c,l,(int64_t)at,width,count);}
static int sxd_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxd_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxd_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+bytes;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxd_order);return !c->failed;
}
/* Native primary-layout blob readers cap inputs at 64 MiB; metadata walks use
 * the same cap. Every dereference below is preceded by a checked source span. */
bool sxd_var(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t end,uint64_t *v,const sx_layout *const *rows)
{
    uint64_t start=*at;*v=0;for(unsigned i=0;i<10;i++){if(*at>=end||!sxd_can(c,*at,1))return false;uint8_t x=b[(*at)++];if(i==9&&(x&254))return false;*v|=(uint64_t)(x&127)<<(7*i);if(!(x&128))return !rows||sxd_add(c,rows[i],start,i+1);}return false;
}
static bool sx_databases_build(sx_context *c)
{
    if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>67108864||xx_pd_is_stopped(c->pd))return false;
    uint8_t *b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=false;
    for(int64_t at=0;at<c->size;){size_t n=c->size-at>65536?65536:(size_t)(c->size-at);if(!sx_read(c,at,b+at,n))goto done;at+=(int64_t)n;}
    switch(c->f->file_type){case XX_FILE_TYPE_HADOOP_SEQUENCEFILE:ok=sx_hadoop_sequencefile_build(c,b);break;case XX_FILE_TYPE_POSTGRES_CUSTOM:ok=sx_postgres_custom_build(c,b);break;case XX_FILE_TYPE_LMDB_DATA:ok=sx_lmdb_data_build(c,b);break;case XX_FILE_TYPE_LEVELDB_SSTABLE:ok=sx_leveldb_sstable_build(c,b);break;case XX_FILE_TYPE_REDIS_RDB:ok=sx_redis_rdb_build(c,b);break;case XX_FILE_TYPE_TPS:ok=sx_tps_build(c,b);break;case XX_FILE_TYPE_DBZ:ok=sx_dbz_build(c,b);break;case XX_FILE_TYPE_APACHE_ORC:ok=sx_apache_orc_build(c,b);break;default:break;}
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
const sx_family sx_databases_family={sx_databases_supports,sx_databases_build,sx_databases_layouts,SX_COUNT(sx_databases_layouts),sx_databases_comment};
