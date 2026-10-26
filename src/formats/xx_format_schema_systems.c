/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical systems metadata. Scope: docs/data_struct_systems_scope.txt.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_s_wince_image_header_fields[] = {
    SX_FIELD("signature", "char[7]", 0, 7, SX_SIGNATURE),
    SX_FIELD("image_start", "uint32", 7, 4, SX_ADDRESS),
    SX_FIELD("image_length", "uint32", 11, 4, SX_SIZE),
};
static const sx_layout sx_s_wince_image_header = { UINT32_C(0x600C0001), "wince_image_header", sx_s_wince_image_header_fields, SX_COUNT(sx_s_wince_image_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_wince_record_header_fields[] = {
    SX_FIELD("load_address", "uint32", 0, 4, SX_ADDRESS),
    SX_FIELD("data_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("checksum", "uint32", 8, 4, SX_CHECKSUM),
};
static const sx_layout sx_s_wince_record_header = { UINT32_C(0x600C0002), "wince_record_header", sx_s_wince_record_header_fields, SX_COUNT(sx_s_wince_record_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_wince_terminator_fields[] = {
    SX_FIELD("terminator", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("entry_point", "uint32", 4, 4, SX_ADDRESS),
    SX_FIELD("checksum", "uint32", 8, 4, SX_CHECKSUM),
};
static const sx_layout sx_s_wince_terminator = { UINT32_C(0x600C0003), "wince_terminator", sx_s_wince_terminator_fields, SX_COUNT(sx_s_wince_terminator_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_binhdr_header_fields[] = {
    SX_FIELD("board_id", "char[4]", 0, 4, SX_ID),
    SX_FIELD("reserved1", "uint32", 4, 4, SX_RESERVED),
    SX_FIELD("build_date_encoded", "uint32", 8, 4, SX_NONE),
    SX_FIELD("version_major", "uint8", 12, 1, SX_NONE),
    SX_FIELD("version_minor", "uint8", 13, 1, SX_NONE),
    SX_FIELD("magic", "char[4]", 14, 4, SX_SIGNATURE),
    SX_FIELD("hardware_id", "uint8", 18, 1, SX_ID),
    SX_FIELD("reserved2", "uint24", 19, 3, SX_RESERVED),
    SX_FIELD("reserved3", "uint64", 22, 8, SX_RESERVED),
};
static const sx_layout sx_s_binhdr_header = { UINT32_C(0x600C0004), "binhdr_header", sx_s_binhdr_header_fields, SX_COUNT(sx_s_binhdr_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_rtk_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("image_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("checksum", "uint32", 8, 4, SX_CHECKSUM),
    SX_FIELD("unknown0", "uint32", 12, 4, SX_NONE),
    SX_FIELD("header_size_excluding_magic", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("unknown1", "uint32", 20, 4, SX_NONE),
    SX_FIELD("unknown2", "uint32", 24, 4, SX_NONE),
    SX_FIELD("identifier", "uint32", 28, 4, SX_ID),
};
static const sx_layout sx_s_rtk_header = { UINT32_C(0x600C0005), "rtk_header", sx_s_rtk_header_fields, SX_COUNT(sx_s_rtk_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_packimg_header_fields[] = {
    SX_FIELD("tag", "char[12]", 0, 12, SX_SIGNATURE),
    SX_FIELD("unknown", "uint32", 12, 4, SX_NONE),
    SX_FIELD("data_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("unknown_tail", "bytes", 20, 12, SX_NONE),
};
static const sx_layout sx_s_packimg_header = { UINT32_C(0x600C0006), "packimg_header", sx_s_packimg_header_fields, SX_COUNT(sx_s_packimg_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dlob_entity_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("reserved", "uint16", 4, 2, SX_RESERVED),
    SX_FIELD("metadata_size", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("image_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_s_dlob_entity_header = { UINT32_C(0x600C0007), "dlob_entity_header", sx_s_dlob_entity_header_fields, SX_COUNT(sx_s_dlob_entity_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_dlob_digest_fields[] = {
    SX_FIELD("md5", "bytes", 0, 16, SX_CHECKSUM),
};
static const sx_layout sx_s_dlob_digest = { UINT32_C(0x600C0008), "dlob_digest", sx_s_dlob_digest_fields, SX_COUNT(sx_s_dlob_digest_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_chk_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("header_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("reserved", "bytes", 8, 8, SX_RESERVED),
    SX_FIELD("kernel_checksum", "uint32", 16, 4, SX_CHECKSUM),
    SX_FIELD("rootfs_checksum", "uint32", 20, 4, SX_CHECKSUM),
    SX_FIELD("kernel_size", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("rootfs_size", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("image_checksum", "uint32", 32, 4, SX_CHECKSUM),
    SX_FIELD("header_checksum", "uint32", 36, 4, SX_CHECKSUM),
};
static const sx_layout sx_s_chk_header = { UINT32_C(0x600C0009), "chk_header", sx_s_chk_header_fields, SX_COUNT(sx_s_chk_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_csman_header_le_fields[] = {
    SX_FIELD("magic", "char[2]", 0, 2, SX_SIGNATURE),
    SX_FIELD("unknown0", "uint16", 2, 2, SX_NONE),
    SX_FIELD("compressed_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("unknown1", "uint32", 8, 4, SX_NONE),
    SX_FIELD("decompressed_size", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_s_csman_header_le = { UINT32_C(0x600C000A), "csman_header_le", sx_s_csman_header_le_fields, SX_COUNT(sx_s_csman_header_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_csman_entry_le_fields[] = {
    SX_FIELD("key", "uint32", 0, 4, SX_ID),
    SX_FIELD("value_size", "uint16", 4, 2, SX_SIZE),
};
static const sx_layout sx_s_csman_entry_le = { UINT32_C(0x600C000B), "csman_entry_le", sx_s_csman_entry_le_fields, SX_COUNT(sx_s_csman_entry_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_csman_terminator_le_fields[] = {
    SX_FIELD("zero_key", "uint32", 0, 4, SX_SIGNATURE),
};
static const sx_layout sx_s_csman_terminator_le = { UINT32_C(0x600C000C), "csman_terminator_le", sx_s_csman_terminator_le_fields, SX_COUNT(sx_s_csman_terminator_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_csman_header_be_fields[] = {
    SX_FIELD("magic", "char[2]", 0, 2, SX_SIGNATURE),
    SX_FIELD("unknown0", "uint16", 2, 2, SX_NONE),
    SX_FIELD("compressed_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("unknown1", "uint32", 8, 4, SX_NONE),
    SX_FIELD("decompressed_size", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_s_csman_header_be = { UINT32_C(0x600C000D), "csman_header_be", sx_s_csman_header_be_fields, SX_COUNT(sx_s_csman_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_csman_entry_be_fields[] = {
    SX_FIELD("key", "uint32", 0, 4, SX_ID),
    SX_FIELD("value_size", "uint16", 4, 2, SX_SIZE),
};
static const sx_layout sx_s_csman_entry_be = { UINT32_C(0x600C000E), "csman_entry_be", sx_s_csman_entry_be_fields, SX_COUNT(sx_s_csman_entry_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_csman_terminator_be_fields[] = {
    SX_FIELD("zero_key", "uint32", 0, 4, SX_SIGNATURE),
};
static const sx_layout sx_s_csman_terminator_be = { UINT32_C(0x600C000F), "csman_terminator_be", sx_s_csman_terminator_be_fields, SX_COUNT(sx_s_csman_terminator_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_matter_ota_preamble_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("total_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("tlv_header_size", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_s_matter_ota_preamble = { UINT32_C(0x600C0010), "matter_ota_preamble", sx_s_matter_ota_preamble_fields, SX_COUNT(sx_s_matter_ota_preamble_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_twoimg_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("creator", "char[4]", 4, 4, SX_ID),
    SX_FIELD("header_size", "uint16", 8, 2, SX_SIZE),
    SX_FIELD("version", "uint16", 10, 2, SX_NONE),
    SX_FIELD("image_format", "uint32", 12, 4, SX_ID),
    SX_FIELD("flags", "uint32", 16, 4, SX_FLAGS),
    SX_FIELD("block_count", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("data_offset", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("data_length", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("comment_offset", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("comment_length", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("creator_data_offset", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("creator_data_length", "uint32", 44, 4, SX_SIZE),
    SX_FIELD("reserved", "bytes", 48, 16, SX_RESERVED),
};
static const sx_layout sx_s_twoimg_header = { UINT32_C(0x600C0011), "twoimg_header", sx_s_twoimg_header_fields, SX_COUNT(sx_s_twoimg_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_t64_header_fields[] = {
    SX_FIELD("signature", "char[32]", 0, 32, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 32, 2, SX_NONE),
    SX_FIELD("directory_slots", "uint16", 34, 2, SX_COUNT_PROP),
    SX_FIELD("used_slots", "uint16", 36, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint16", 38, 2, SX_RESERVED),
    SX_FIELD("tape_name", "char[24]", 40, 24, SX_STRING),
};
static const sx_layout sx_s_t64_header = { UINT32_C(0x600C0012), "t64_header", sx_s_t64_header_fields, SX_COUNT(sx_s_t64_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_t64_directory_entry_fields[] = {
    SX_FIELD("entry_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("file_type", "uint8", 1, 1, SX_ID),
    SX_FIELD("start_address", "uint16", 2, 2, SX_ADDRESS),
    SX_FIELD("end_address", "uint16", 4, 2, SX_ADDRESS),
    SX_FIELD("reserved0", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("data_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("reserved1", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("file_name", "char[16]", 16, 16, SX_STRING),
};
static const sx_layout sx_s_t64_directory_entry = { UINT32_C(0x600C0013), "t64_directory_entry", sx_s_t64_directory_entry_fields, SX_COUNT(sx_s_t64_directory_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_scl_header_fields[] = {
    SX_FIELD("magic", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("file_count", "uint8", 8, 1, SX_COUNT_PROP),
};
static const sx_layout sx_s_scl_header = { UINT32_C(0x600C0014), "scl_header", sx_s_scl_header_fields, SX_COUNT(sx_s_scl_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_scl_catalogue_entry_fields[] = {
    SX_FIELD("name", "char[8]", 0, 8, SX_STRING),
    SX_FIELD("file_type", "char", 8, 1, SX_ID),
    SX_FIELD("start_address_or_basic_length", "uint16", 9, 2, SX_NONE),
    SX_FIELD("file_length", "uint16", 11, 2, SX_SIZE),
    SX_FIELD("sector_count", "uint8", 13, 1, SX_COUNT_PROP),
};
static const sx_layout sx_s_scl_catalogue_entry = { UINT32_C(0x600C0015), "scl_catalogue_entry", sx_s_scl_catalogue_entry_fields, SX_COUNT(sx_s_scl_catalogue_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_ciso_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("header_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("uncompressed_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("block_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("version", "uint8", 20, 1, SX_NONE),
    SX_FIELD("alignment_shift", "uint8", 21, 1, SX_NONE),
    SX_FIELD("reserved", "uint16", 22, 2, SX_RESERVED),
};
static const sx_layout sx_s_ciso_header = { UINT32_C(0x600C0016), "ciso_header", sx_s_ciso_header_fields, SX_COUNT(sx_s_ciso_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_ciso_index_entry_fields[] = {
    SX_FIELD("encoded_block_offset", "uint32", 0, 4, SX_FLAGS),
};
static const sx_layout sx_s_ciso_index_entry = { UINT32_C(0x600C0017), "ciso_index_entry", sx_s_ciso_index_entry_fields, SX_COUNT(sx_s_ciso_index_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dax_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("uncompressed_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("version", "uint32", 8, 4, SX_NONE),
    SX_FIELD("uncompressed_area_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("reserved", "bytes", 16, 16, SX_RESERVED),
};
static const sx_layout sx_s_dax_header = { UINT32_C(0x600C0018), "dax_header", sx_s_dax_header_fields, SX_COUNT(sx_s_dax_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dax_frame_offset_fields[] = {
    SX_FIELD("frame_offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sx_s_dax_frame_offset = { UINT32_C(0x600C0019), "dax_frame_offset", sx_s_dax_frame_offset_fields, SX_COUNT(sx_s_dax_frame_offset_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dax_frame_size_fields[] = {
    SX_FIELD("compressed_size", "uint16", 0, 2, SX_SIZE),
};
static const sx_layout sx_s_dax_frame_size = { UINT32_C(0x600C001A), "dax_frame_size", sx_s_dax_frame_size_fields, SX_COUNT(sx_s_dax_frame_size_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dax_uncompressed_area_fields[] = {
    SX_FIELD("first_frame", "uint32", 0, 4, SX_NONE),
    SX_FIELD("frame_count", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sx_s_dax_uncompressed_area = { UINT32_C(0x600C001B), "dax_uncompressed_area", sx_s_dax_uncompressed_area_fields, SX_COUNT(sx_s_dax_uncompressed_area_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_palm_database_header_fields[] = {
    SX_FIELD("name", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("attributes", "uint16", 32, 2, SX_FLAGS),
    SX_FIELD("version", "uint16", 34, 2, SX_NONE),
    SX_FIELD("creation_time", "uint32", 36, 4, SX_TIME),
    SX_FIELD("modification_time", "uint32", 40, 4, SX_TIME),
    SX_FIELD("backup_time", "uint32", 44, 4, SX_TIME),
    SX_FIELD("modification_number", "uint32", 48, 4, SX_NONE),
    SX_FIELD("app_info_offset", "uint32", 52, 4, SX_OFFSET),
    SX_FIELD("sort_info_offset", "uint32", 56, 4, SX_OFFSET),
    SX_FIELD("database_type", "char[4]", 60, 4, SX_ID),
    SX_FIELD("creator", "char[4]", 64, 4, SX_ID),
    SX_FIELD("unique_id_seed", "uint32", 68, 4, SX_NONE),
    SX_FIELD("next_record_list_offset", "uint32", 72, 4, SX_OFFSET),
    SX_FIELD("record_count", "uint16", 76, 2, SX_COUNT_PROP),
};
static const sx_layout sx_s_palm_database_header = { UINT32_C(0x600C001C), "palm_database_header", sx_s_palm_database_header_fields, SX_COUNT(sx_s_palm_database_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_palm_record_entry_fields[] = {
    SX_FIELD("data_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("attributes", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("unique_id", "uint24", 5, 3, SX_ID),
};
static const sx_layout sx_s_palm_record_entry = { UINT32_C(0x600C001D), "palm_record_entry", sx_s_palm_record_entry_fields, SX_COUNT(sx_s_palm_record_entry_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_palm_resource_entry_fields[] = {
    SX_FIELD("type", "char[4]", 0, 4, SX_ID),
    SX_FIELD("id", "uint16", 4, 2, SX_ID),
    SX_FIELD("data_offset", "uint32", 6, 4, SX_OFFSET),
};
static const sx_layout sx_s_palm_resource_entry = { UINT32_C(0x600C001E), "palm_resource_entry", sx_s_palm_resource_entry_fields, SX_COUNT(sx_s_palm_resource_entry_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_dbase3_header_fields[] = {
    SX_FIELD("version", "uint8", 0, 1, SX_NONE),
    SX_FIELD("year_since_1900", "uint8", 1, 1, SX_NONE),
    SX_FIELD("month", "uint8", 2, 1, SX_NONE),
    SX_FIELD("day", "uint8", 3, 1, SX_NONE),
    SX_FIELD("record_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("header_size", "uint16", 8, 2, SX_SIZE),
    SX_FIELD("record_size", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("reserved0", "bytes", 12, 2, SX_RESERVED),
    SX_FIELD("transaction_flag", "uint8", 14, 1, SX_FLAGS),
    SX_FIELD("encryption_flag", "uint8", 15, 1, SX_FLAGS),
    SX_FIELD("reserved1", "bytes", 16, 12, SX_RESERVED),
    SX_FIELD("mdx_flag", "uint8", 28, 1, SX_FLAGS),
    SX_FIELD("language_driver_id", "uint8", 29, 1, SX_ID),
    SX_FIELD("reserved2", "uint16", 30, 2, SX_RESERVED),
};
static const sx_layout sx_s_dbase3_header = { UINT32_C(0x600C001F), "dbase3_header", sx_s_dbase3_header_fields, SX_COUNT(sx_s_dbase3_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dbase3_field_descriptor_fields[] = {
    SX_FIELD("name", "char[11]", 0, 11, SX_STRING),
    SX_FIELD("field_type", "char", 11, 1, SX_ID),
    SX_FIELD("memory_address", "uint32", 12, 4, SX_ADDRESS),
    SX_FIELD("field_length", "uint8", 16, 1, SX_SIZE),
    SX_FIELD("decimal_count", "uint8", 17, 1, SX_COUNT_PROP),
    SX_FIELD("reserved", "bytes", 18, 14, SX_RESERVED),
};
static const sx_layout sx_s_dbase3_field_descriptor = { UINT32_C(0x600C0020), "dbase3_field_descriptor", sx_s_dbase3_field_descriptor_fields, SX_COUNT(sx_s_dbase3_field_descriptor_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dbase3_record_marker_fields[] = {
    SX_FIELD("deletion_marker", "char", 0, 1, SX_FLAGS),
};
static const sx_layout sx_s_dbase3_record_marker = { UINT32_C(0x600C0021), "dbase3_record_marker", sx_s_dbase3_record_marker_fields, SX_COUNT(sx_s_dbase3_record_marker_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dbase3_header_terminator_fields[] = {
    SX_FIELD("terminator", "uint8", 0, 1, SX_SIGNATURE),
};
static const sx_layout sx_s_dbase3_header_terminator = { UINT32_C(0x600C0022), "dbase3_header_terminator", sx_s_dbase3_header_terminator_fields, SX_COUNT(sx_s_dbase3_header_terminator_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dns_header_fields[] = {
    SX_FIELD("transaction_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("flags", "uint16", 2, 2, SX_FLAGS),
    SX_FIELD("question_count", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("answer_count", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("authority_count", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("additional_count", "uint16", 10, 2, SX_COUNT_PROP),
};
static const sx_layout sx_s_dns_header = { UINT32_C(0x600C0023), "dns_header", sx_s_dns_header_fields, SX_COUNT(sx_s_dns_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_dns_question_fields[] = {
    SX_FIELD("type", "uint16", 0, 2, SX_ID),
    SX_FIELD("class", "uint16", 2, 2, SX_ID),
};
static const sx_layout sx_s_dns_question = { UINT32_C(0x600C0024), "dns_question", sx_s_dns_question_fields, SX_COUNT(sx_s_dns_question_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_dns_resource_header_fields[] = {
    SX_FIELD("type", "uint16", 0, 2, SX_ID),
    SX_FIELD("class", "uint16", 2, 2, SX_ID),
    SX_FIELD("ttl_seconds", "uint32", 4, 4, SX_NONE),
    SX_FIELD("rdata_length", "uint16", 8, 2, SX_SIZE),
};
static const sx_layout sx_s_dns_resource_header = { UINT32_C(0x600C0025), "dns_resource_header", sx_s_dns_resource_header_fields, SX_COUNT(sx_s_dns_resource_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_modbus_mbap_header_fields[] = {
    SX_FIELD("transaction_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("protocol_id", "uint16", 2, 2, SX_ID),
    SX_FIELD("length", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("unit_id", "uint8", 6, 1, SX_ID),
};
static const sx_layout sx_s_modbus_mbap_header = { UINT32_C(0x600C0026), "modbus_mbap_header", sx_s_modbus_mbap_header_fields, SX_COUNT(sx_s_modbus_mbap_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_modbus_read_request_fields[] = {
    SX_FIELD("function", "uint8", 0, 1, SX_ID),
    SX_FIELD("starting_register", "uint16", 1, 2, SX_ID),
    SX_FIELD("register_count", "uint16", 3, 2, SX_COUNT_PROP),
};
static const sx_layout sx_s_modbus_read_request = { UINT32_C(0x600C0027), "modbus_read_request", sx_s_modbus_read_request_fields, SX_COUNT(sx_s_modbus_read_request_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_modbus_write_multiple_response_fields[] = {
    SX_FIELD("function", "uint8", 0, 1, SX_ID),
    SX_FIELD("starting_register", "uint16", 1, 2, SX_ID),
    SX_FIELD("register_count", "uint16", 3, 2, SX_COUNT_PROP),
};
static const sx_layout sx_s_modbus_write_multiple_response = { UINT32_C(0x600C0028), "modbus_write_multiple_response", sx_s_modbus_write_multiple_response_fields, SX_COUNT(sx_s_modbus_write_multiple_response_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_modbus_write_single_fields[] = {
    SX_FIELD("function", "uint8", 0, 1, SX_ID),
    SX_FIELD("register_address", "uint16", 1, 2, SX_ID),
    SX_FIELD("value", "uint16", 3, 2, SX_NONE),
};
static const sx_layout sx_s_modbus_write_single = { UINT32_C(0x600C0029), "modbus_write_single", sx_s_modbus_write_single_fields, SX_COUNT(sx_s_modbus_write_single_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_modbus_read_response_fields[] = {
    SX_FIELD("function", "uint8", 0, 1, SX_ID),
    SX_FIELD("byte_count", "uint8", 1, 1, SX_SIZE),
};
static const sx_layout sx_s_modbus_read_response = { UINT32_C(0x600C002A), "modbus_read_response", sx_s_modbus_read_response_fields, SX_COUNT(sx_s_modbus_read_response_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_modbus_write_multiple_fields[] = {
    SX_FIELD("function", "uint8", 0, 1, SX_ID),
    SX_FIELD("starting_register", "uint16", 1, 2, SX_ID),
    SX_FIELD("register_count", "uint16", 3, 2, SX_COUNT_PROP),
    SX_FIELD("byte_count", "uint8", 5, 1, SX_SIZE),
};
static const sx_layout sx_s_modbus_write_multiple = { UINT32_C(0x600C002B), "modbus_write_multiple", sx_s_modbus_write_multiple_fields, SX_COUNT(sx_s_modbus_write_multiple_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_modbus_exception_fields[] = {
    SX_FIELD("function", "uint8", 0, 1, SX_ID),
    SX_FIELD("exception_code", "uint8", 1, 1, SX_ID),
};
static const sx_layout sx_s_modbus_exception = { UINT32_C(0x600C002C), "modbus_exception", sx_s_modbus_exception_fields, SX_COUNT(sx_s_modbus_exception_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_modbus_register_value_fields[] = {
    SX_FIELD("value", "uint16", 0, 2, SX_NONE),
};
static const sx_layout sx_s_modbus_register_value = { UINT32_C(0x600C002D), "modbus_register_value", sx_s_modbus_register_value_fields, SX_COUNT(sx_s_modbus_register_value_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_someip_header_fields[] = {
    SX_FIELD("service_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("method_id", "uint16", 2, 2, SX_ID),
    SX_FIELD("length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("client_id", "uint16", 8, 2, SX_ID),
    SX_FIELD("session_id", "uint16", 10, 2, SX_ID),
    SX_FIELD("protocol_version", "uint8", 12, 1, SX_NONE),
    SX_FIELD("interface_version", "uint8", 13, 1, SX_NONE),
    SX_FIELD("message_type", "uint8", 14, 1, SX_ID),
    SX_FIELD("return_code", "uint8", 15, 1, SX_ID),
};
static const sx_layout sx_s_someip_header = { UINT32_C(0x600C002E), "someip_header", sx_s_someip_header_fields, SX_COUNT(sx_s_someip_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_coap_header_fields[] = {
    SX_FIELD("version_type_token_length", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("code", "uint8", 1, 1, SX_ID),
    SX_FIELD("message_id", "uint16", 2, 2, SX_ID),
};
static const sx_layout sx_s_coap_header = { UINT32_C(0x600C002F), "coap_header", sx_s_coap_header_fields, SX_COUNT(sx_s_coap_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_coap_option_header_fields[] = {
    SX_FIELD("delta_length_nibbles", "uint8", 0, 1, SX_FLAGS),
};
static const sx_layout sx_s_coap_option_header = { UINT32_C(0x600C0030), "coap_option_header", sx_s_coap_option_header_fields, SX_COUNT(sx_s_coap_option_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_coap_delta_extension8_fields[] = {
    SX_FIELD("encoded_delta_extension", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sx_s_coap_delta_extension8 = { UINT32_C(0x600C0031), "coap_delta_extension8", sx_s_coap_delta_extension8_fields, SX_COUNT(sx_s_coap_delta_extension8_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_coap_delta_extension16_fields[] = {
    SX_FIELD("encoded_delta_extension", "uint16", 0, 2, SX_NONE),
};
static const sx_layout sx_s_coap_delta_extension16 = { UINT32_C(0x600C0032), "coap_delta_extension16", sx_s_coap_delta_extension16_fields, SX_COUNT(sx_s_coap_delta_extension16_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_coap_length_extension8_fields[] = {
    SX_FIELD("encoded_length_extension", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sx_s_coap_length_extension8 = { UINT32_C(0x600C0033), "coap_length_extension8", sx_s_coap_length_extension8_fields, SX_COUNT(sx_s_coap_length_extension8_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_coap_length_extension16_fields[] = {
    SX_FIELD("encoded_length_extension", "uint16", 0, 2, SX_NONE),
};
static const sx_layout sx_s_coap_length_extension16 = { UINT32_C(0x600C0034), "coap_length_extension16", sx_s_coap_length_extension16_fields, SX_COUNT(sx_s_coap_length_extension16_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_stun_header_fields[] = {
    SX_FIELD("message_type", "uint16", 0, 2, SX_ID),
    SX_FIELD("message_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("magic_cookie", "uint32", 4, 4, SX_SIGNATURE),
    SX_FIELD("transaction_id", "bytes", 8, 12, SX_ID),
};
static const sx_layout sx_s_stun_header = { UINT32_C(0x600C0035), "stun_header", sx_s_stun_header_fields, SX_COUNT(sx_s_stun_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_stun_attribute_header_fields[] = {
    SX_FIELD("type", "uint16", 0, 2, SX_ID),
    SX_FIELD("length", "uint16", 2, 2, SX_SIZE),
};
static const sx_layout sx_s_stun_attribute_header = { UINT32_C(0x600C0036), "stun_attribute_header", sx_s_stun_attribute_header_fields, SX_COUNT(sx_s_stun_attribute_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_dhcp_header_fields[] = {
    SX_FIELD("operation", "uint8", 0, 1, SX_ID),
    SX_FIELD("hardware_type", "uint8", 1, 1, SX_ID),
    SX_FIELD("hardware_address_length", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("hops", "uint8", 3, 1, SX_COUNT_PROP),
    SX_FIELD("transaction_id", "uint32", 4, 4, SX_ID),
    SX_FIELD("seconds_elapsed", "uint16", 8, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 10, 2, SX_FLAGS),
    SX_FIELD("client_ipv4", "bytes", 12, 4, SX_NONE),
    SX_FIELD("your_ipv4", "bytes", 16, 4, SX_NONE),
    SX_FIELD("server_ipv4", "bytes", 20, 4, SX_NONE),
    SX_FIELD("gateway_ipv4", "bytes", 24, 4, SX_NONE),
    SX_FIELD("client_hardware_address", "bytes", 28, 16, SX_NONE),
    SX_FIELD("server_host_name", "char[64]", 44, 64, SX_STRING),
    SX_FIELD("boot_file_name", "char[128]", 108, 128, SX_STRING),
    SX_FIELD("magic_cookie", "uint32", 236, 4, SX_SIGNATURE),
};
static const sx_layout sx_s_dhcp_header = { UINT32_C(0x600C0037), "dhcp_header", sx_s_dhcp_header_fields, SX_COUNT(sx_s_dhcp_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_dhcp_option_fields[] = {
    SX_FIELD("code", "uint8", 0, 1, SX_ID),
    SX_FIELD("length", "uint8", 1, 1, SX_SIZE),
};
static const sx_layout sx_s_dhcp_option = { UINT32_C(0x600C0038), "dhcp_option", sx_s_dhcp_option_fields, SX_COUNT(sx_s_dhcp_option_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_dhcp_option_marker_fields[] = {
    SX_FIELD("code", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_s_dhcp_option_marker = { UINT32_C(0x600C0039), "dhcp_option_marker", sx_s_dhcp_option_marker_fields, SX_COUNT(sx_s_dhcp_option_marker_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_radius_header_fields[] = {
    SX_FIELD("code", "uint8", 0, 1, SX_ID),
    SX_FIELD("identifier", "uint8", 1, 1, SX_ID),
    SX_FIELD("length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("authenticator", "bytes", 4, 16, SX_SIGNATURE),
};
static const sx_layout sx_s_radius_header = { UINT32_C(0x600C003A), "radius_header", sx_s_radius_header_fields, SX_COUNT(sx_s_radius_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_radius_attribute_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("length_including_header", "uint8", 1, 1, SX_SIZE),
};
static const sx_layout sx_s_radius_attribute = { UINT32_C(0x600C003B), "radius_attribute", sx_s_radius_attribute_fields, SX_COUNT(sx_s_radius_attribute_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_ntp_header_fields[] = {
    SX_FIELD("leap_version_mode", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("stratum", "uint8", 1, 1, SX_NONE),
    SX_FIELD("poll_exponent", "int8", 2, 1, SX_NONE),
    SX_FIELD("precision_exponent", "int8", 3, 1, SX_NONE),
    SX_FIELD("root_delay_16_16", "int32", 4, 4, SX_NONE),
    SX_FIELD("root_dispersion_16_16", "uint32", 8, 4, SX_NONE),
    SX_FIELD("reference_id", "bytes", 12, 4, SX_ID),
    SX_FIELD("reference_timestamp_32_32", "uint64", 16, 8, SX_NONE),
    SX_FIELD("origin_timestamp_32_32", "uint64", 24, 8, SX_NONE),
    SX_FIELD("receive_timestamp_32_32", "uint64", 32, 8, SX_NONE),
    SX_FIELD("transmit_timestamp_32_32", "uint64", 40, 8, SX_NONE),
};
static const sx_layout sx_s_ntp_header = { UINT32_C(0x600C003C), "ntp_header", sx_s_ntp_header_fields, SX_COUNT(sx_s_ntp_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_rip_header_fields[] = {
    SX_FIELD("command", "uint8", 0, 1, SX_ID),
    SX_FIELD("version", "uint8", 1, 1, SX_NONE),
    SX_FIELD("reserved", "uint16", 2, 2, SX_RESERVED),
};
static const sx_layout sx_s_rip_header = { UINT32_C(0x600C003D), "rip_header", sx_s_rip_header_fields, SX_COUNT(sx_s_rip_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_rip_route_fields[] = {
    SX_FIELD("address_family", "uint16", 0, 2, SX_ID),
    SX_FIELD("route_tag", "uint16", 2, 2, SX_ID),
    SX_FIELD("ipv4_address", "bytes", 4, 4, SX_NONE),
    SX_FIELD("subnet_mask", "bytes", 8, 4, SX_NONE),
    SX_FIELD("next_hop", "bytes", 12, 4, SX_NONE),
    SX_FIELD("metric", "uint32", 16, 4, SX_NONE),
};
static const sx_layout sx_s_rip_route = { UINT32_C(0x600C003E), "rip_route", sx_s_rip_route_fields, SX_COUNT(sx_s_rip_route_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_vrrp2_header_fields[] = {
    SX_FIELD("version_type", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("virtual_router_id", "uint8", 1, 1, SX_ID),
    SX_FIELD("priority", "uint8", 2, 1, SX_NONE),
    SX_FIELD("address_count", "uint8", 3, 1, SX_COUNT_PROP),
    SX_FIELD("authentication_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("advertisement_interval_seconds", "uint8", 5, 1, SX_NONE),
    SX_FIELD("checksum", "uint16", 6, 2, SX_CHECKSUM),
};
static const sx_layout sx_s_vrrp2_header = { UINT32_C(0x600C003F), "vrrp2_header", sx_s_vrrp2_header_fields, SX_COUNT(sx_s_vrrp2_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_vrrp2_ipv4_fields[] = {
    SX_FIELD("virtual_ipv4", "bytes", 0, 4, SX_NONE),
};
static const sx_layout sx_s_vrrp2_ipv4 = { UINT32_C(0x600C0040), "vrrp2_ipv4", sx_s_vrrp2_ipv4_fields, SX_COUNT(sx_s_vrrp2_ipv4_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_vrrp2_authentication_fields[] = {
    SX_FIELD("authentication_data", "bytes", 0, 8, SX_NONE),
};
static const sx_layout sx_s_vrrp2_authentication = { UINT32_C(0x600C0041), "vrrp2_authentication", sx_s_vrrp2_authentication_fields, SX_COUNT(sx_s_vrrp2_authentication_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_igmp3_report_header_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("reserved0", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("checksum", "uint16", 2, 2, SX_CHECKSUM),
    SX_FIELD("reserved1", "uint16", 4, 2, SX_RESERVED),
    SX_FIELD("record_count", "uint16", 6, 2, SX_COUNT_PROP),
};
static const sx_layout sx_s_igmp3_report_header = { UINT32_C(0x600C0042), "igmp3_report_header", sx_s_igmp3_report_header_fields, SX_COUNT(sx_s_igmp3_report_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_igmp3_group_record_fields[] = {
    SX_FIELD("record_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("auxiliary_word_count", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("source_count", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("multicast_ipv4", "bytes", 4, 4, SX_NONE),
};
static const sx_layout sx_s_igmp3_group_record = { UINT32_C(0x600C0043), "igmp3_group_record", sx_s_igmp3_group_record_fields, SX_COUNT(sx_s_igmp3_group_record_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_igmp3_source_ipv4_fields[] = {
    SX_FIELD("source_ipv4", "bytes", 0, 4, SX_NONE),
};
static const sx_layout sx_s_igmp3_source_ipv4 = { UINT32_C(0x600C0044), "igmp3_source_ipv4", sx_s_igmp3_source_ipv4_fields, SX_COUNT(sx_s_igmp3_source_ipv4_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_lldp_tlv_header_fields[] = {
    SX_FIELD("type_length_bits", "uint16", 0, 2, SX_FLAGS),
};
static const sx_layout sx_s_lldp_tlv_header = { UINT32_C(0x600C0045), "lldp_tlv_header", sx_s_lldp_tlv_header_fields, SX_COUNT(sx_s_lldp_tlv_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_lldp_identifier_subtype_fields[] = {
    SX_FIELD("subtype", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_s_lldp_identifier_subtype = { UINT32_C(0x600C0046), "lldp_identifier_subtype", sx_s_lldp_identifier_subtype_fields, SX_COUNT(sx_s_lldp_identifier_subtype_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_lldp_ttl_fields[] = {
    SX_FIELD("ttl_seconds", "uint16", 0, 2, SX_NONE),
};
static const sx_layout sx_s_lldp_ttl = { UINT32_C(0x600C0047), "lldp_ttl", sx_s_lldp_ttl_fields, SX_COUNT(sx_s_lldp_ttl_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_lldp_capabilities_fields[] = {
    SX_FIELD("supported", "uint16", 0, 2, SX_FLAGS),
    SX_FIELD("enabled", "uint16", 2, 2, SX_FLAGS),
};
static const sx_layout sx_s_lldp_capabilities = { UINT32_C(0x600C0048), "lldp_capabilities", sx_s_lldp_capabilities_fields, SX_COUNT(sx_s_lldp_capabilities_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_arp_ethernet_ipv4_fields[] = {
    SX_FIELD("hardware_type", "uint16", 0, 2, SX_ID),
    SX_FIELD("protocol_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("hardware_length", "uint8", 4, 1, SX_SIZE),
    SX_FIELD("protocol_length", "uint8", 5, 1, SX_SIZE),
    SX_FIELD("operation", "uint16", 6, 2, SX_ID),
    SX_FIELD("sender_mac", "bytes", 8, 6, SX_NONE),
    SX_FIELD("sender_ipv4", "bytes", 14, 4, SX_NONE),
    SX_FIELD("target_mac", "bytes", 18, 6, SX_NONE),
    SX_FIELD("target_ipv4", "bytes", 24, 4, SX_NONE),
};
static const sx_layout sx_s_arp_ethernet_ipv4 = { UINT32_C(0x600C0049), "arp_ethernet_ipv4", sx_s_arp_ethernet_ipv4_fields, SX_COUNT(sx_s_arp_ethernet_ipv4_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_mongodb_opmsg_header_fields[] = {
    SX_FIELD("message_length", "int32", 0, 4, SX_SIZE),
    SX_FIELD("request_id", "int32", 4, 4, SX_ID),
    SX_FIELD("response_to", "int32", 8, 4, SX_ID),
    SX_FIELD("opcode", "int32", 12, 4, SX_ID),
    SX_FIELD("flags", "uint32", 16, 4, SX_FLAGS),
};
static const sx_layout sx_s_mongodb_opmsg_header = { UINT32_C(0x600C004A), "mongodb_opmsg_header", sx_s_mongodb_opmsg_header_fields, SX_COUNT(sx_s_mongodb_opmsg_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_mongodb_section_kind_fields[] = {
    SX_FIELD("kind", "uint8", 0, 1, SX_ID),
};
static const sx_layout sx_s_mongodb_section_kind = { UINT32_C(0x600C004B), "mongodb_section_kind", sx_s_mongodb_section_kind_fields, SX_COUNT(sx_s_mongodb_section_kind_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_mongodb_sequence_size_fields[] = {
    SX_FIELD("size_including_self", "int32", 0, 4, SX_SIZE),
};
static const sx_layout sx_s_mongodb_sequence_size = { UINT32_C(0x600C004C), "mongodb_sequence_size", sx_s_mongodb_sequence_size_fields, SX_COUNT(sx_s_mongodb_sequence_size_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_mongodb_document_size_fields[] = {
    SX_FIELD("document_size", "int32", 0, 4, SX_SIZE),
};
static const sx_layout sx_s_mongodb_document_size = { UINT32_C(0x600C004D), "mongodb_document_size", sx_s_mongodb_document_size_fields, SX_COUNT(sx_s_mongodb_document_size_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_mongodb_checksum_fields[] = {
    SX_FIELD("crc32c", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_s_mongodb_checksum = { UINT32_C(0x600C004E), "mongodb_checksum", sx_s_mongodb_checksum_fields, SX_COUNT(sx_s_mongodb_checksum_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dbus_header_le_fields[] = {
    SX_FIELD("byte_order", "char", 0, 1, SX_ID),
    SX_FIELD("message_type", "uint8", 1, 1, SX_ID),
    SX_FIELD("flags", "uint8", 2, 1, SX_FLAGS),
    SX_FIELD("protocol_version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("body_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("serial", "uint32", 8, 4, SX_ID),
    SX_FIELD("header_fields_length", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_s_dbus_header_le = { UINT32_C(0x600C004F), "dbus_header_le", sx_s_dbus_header_le_fields, SX_COUNT(sx_s_dbus_header_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_dbus_header_be_fields[] = {
    SX_FIELD("byte_order", "char", 0, 1, SX_ID),
    SX_FIELD("message_type", "uint8", 1, 1, SX_ID),
    SX_FIELD("flags", "uint8", 2, 1, SX_FLAGS),
    SX_FIELD("protocol_version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("body_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("serial", "uint32", 8, 4, SX_ID),
    SX_FIELD("header_fields_length", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_s_dbus_header_be = { UINT32_C(0x600C0050), "dbus_header_be", sx_s_dbus_header_be_fields, SX_COUNT(sx_s_dbus_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_shell_link_header_fields[] = {
    SX_FIELD("header_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("class_id", "bytes", 4, 16, SX_ID),
    SX_FIELD("link_flags", "uint32", 20, 4, SX_FLAGS),
    SX_FIELD("file_attributes", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("creation_time", "uint64", 28, 8, SX_TIME),
    SX_FIELD("access_time", "uint64", 36, 8, SX_TIME),
    SX_FIELD("write_time", "uint64", 44, 8, SX_TIME),
    SX_FIELD("file_size", "uint32", 52, 4, SX_SIZE),
    SX_FIELD("icon_index", "int32", 56, 4, SX_NONE),
    SX_FIELD("show_command", "uint32", 60, 4, SX_ID),
    SX_FIELD("hot_key", "uint16", 64, 2, SX_FLAGS),
    SX_FIELD("reserved0", "uint16", 66, 2, SX_RESERVED),
    SX_FIELD("reserved1", "uint32", 68, 4, SX_RESERVED),
    SX_FIELD("reserved2", "uint32", 72, 4, SX_RESERVED),
};
static const sx_layout sx_s_shell_link_header = { UINT32_C(0x600C0051), "shell_link_header", sx_s_shell_link_header_fields, SX_COUNT(sx_s_shell_link_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_shell_link_idlist_size_fields[] = {
    SX_FIELD("idlist_size", "uint16", 0, 2, SX_SIZE),
};
static const sx_layout sx_s_shell_link_idlist_size = { UINT32_C(0x600C0052), "shell_link_idlist_size", sx_s_shell_link_idlist_size_fields, SX_COUNT(sx_s_shell_link_idlist_size_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_shell_link_item_id_fields[] = {
    SX_FIELD("item_size", "uint16", 0, 2, SX_SIZE),
};
static const sx_layout sx_s_shell_link_item_id = { UINT32_C(0x600C0053), "shell_link_item_id", sx_s_shell_link_item_id_fields, SX_COUNT(sx_s_shell_link_item_id_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_shell_link_info_fields[] = {
    SX_FIELD("link_info_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("header_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("volume_id_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("local_base_path_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("network_relative_link_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("common_path_suffix_offset", "uint32", 24, 4, SX_OFFSET),
};
static const sx_layout sx_s_shell_link_info = { UINT32_C(0x600C0054), "shell_link_info", sx_s_shell_link_info_fields, SX_COUNT(sx_s_shell_link_info_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_shell_link_info_unicode_offsets_fields[] = {
    SX_FIELD("local_base_path_unicode_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("common_path_suffix_unicode_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sx_s_shell_link_info_unicode_offsets = { UINT32_C(0x600C0055), "shell_link_info_unicode_offsets", sx_s_shell_link_info_unicode_offsets_fields, SX_COUNT(sx_s_shell_link_info_unicode_offsets_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_shell_link_string_count_fields[] = {
    SX_FIELD("character_count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sx_s_shell_link_string_count = { UINT32_C(0x600C0056), "shell_link_string_count", sx_s_shell_link_string_count_fields, SX_COUNT(sx_s_shell_link_string_count_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_shell_link_extra_header_fields[] = {
    SX_FIELD("block_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("signature", "uint32", 4, 4, SX_ID),
};
static const sx_layout sx_s_shell_link_extra_header = { UINT32_C(0x600C0057), "shell_link_extra_header", sx_s_shell_link_extra_header_fields, SX_COUNT(sx_s_shell_link_extra_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_shell_link_terminal_fields[] = {
    SX_FIELD("zero_size", "uint32", 0, 4, SX_SIGNATURE),
};
static const sx_layout sx_s_shell_link_terminal = { UINT32_C(0x600C0058), "shell_link_terminal", sx_s_shell_link_terminal_fields, SX_COUNT(sx_s_shell_link_terminal_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_icc_profile_header_fields[] = {
    SX_FIELD("profile_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("preferred_cmm", "char[4]", 4, 4, SX_ID),
    SX_FIELD("version", "uint32", 8, 4, SX_NONE),
    SX_FIELD("device_class", "char[4]", 12, 4, SX_ID),
    SX_FIELD("color_space", "char[4]", 16, 4, SX_ID),
    SX_FIELD("profile_connection_space", "char[4]", 20, 4, SX_ID),
    SX_FIELD("year", "uint16", 24, 2, SX_NONE),
    SX_FIELD("month", "uint16", 26, 2, SX_NONE),
    SX_FIELD("day", "uint16", 28, 2, SX_NONE),
    SX_FIELD("hour", "uint16", 30, 2, SX_NONE),
    SX_FIELD("minute", "uint16", 32, 2, SX_NONE),
    SX_FIELD("second", "uint16", 34, 2, SX_NONE),
    SX_FIELD("signature", "char[4]", 36, 4, SX_SIGNATURE),
    SX_FIELD("platform", "char[4]", 40, 4, SX_ID),
    SX_FIELD("flags", "uint32", 44, 4, SX_FLAGS),
    SX_FIELD("manufacturer", "char[4]", 48, 4, SX_ID),
    SX_FIELD("device_model", "char[4]", 52, 4, SX_ID),
    SX_FIELD("attributes", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("rendering_intent", "uint32", 64, 4, SX_ID),
    SX_FIELD("illuminant_x_16_16", "int32", 68, 4, SX_NONE),
    SX_FIELD("illuminant_y_16_16", "int32", 72, 4, SX_NONE),
    SX_FIELD("illuminant_z_16_16", "int32", 76, 4, SX_NONE),
    SX_FIELD("creator", "char[4]", 80, 4, SX_ID),
    SX_FIELD("profile_id", "bytes", 84, 16, SX_SIGNATURE),
    SX_FIELD("reserved", "bytes", 100, 28, SX_RESERVED),
};
static const sx_layout sx_s_icc_profile_header = { UINT32_C(0x600C0059), "icc_profile_header", sx_s_icc_profile_header_fields, SX_COUNT(sx_s_icc_profile_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_icc_tag_count_fields[] = {
    SX_FIELD("tag_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sx_s_icc_tag_count = { UINT32_C(0x600C005A), "icc_tag_count", sx_s_icc_tag_count_fields, SX_COUNT(sx_s_icc_tag_count_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_icc_tag_entry_fields[] = {
    SX_FIELD("tag_signature", "char[4]", 0, 4, SX_ID),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("data_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_s_icc_tag_entry = { UINT32_C(0x600C005B), "icc_tag_entry", sx_s_icc_tag_entry_fields, SX_COUNT(sx_s_icc_tag_entry_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_icc_tag_type_fields[] = {
    SX_FIELD("type_signature", "char[4]", 0, 4, SX_ID),
    SX_FIELD("reserved", "uint32", 4, 4, SX_RESERVED),
};
static const sx_layout sx_s_icc_tag_type = { UINT32_C(0x600C005C), "icc_tag_type", sx_s_icc_tag_type_fields, SX_COUNT(sx_s_icc_tag_type_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_pcapng_block_header_le_fields[] = {
    SX_FIELD("block_type", "uint32", 0, 4, SX_ID),
    SX_FIELD("block_length", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_block_header_le = { UINT32_C(0x600C005D), "pcapng_block_header_le", sx_s_pcapng_block_header_le_fields, SX_COUNT(sx_s_pcapng_block_header_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_pcapng_block_trailer_le_fields[] = {
    SX_FIELD("block_length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_block_trailer_le = { UINT32_C(0x600C005E), "pcapng_block_trailer_le", sx_s_pcapng_block_trailer_le_fields, SX_COUNT(sx_s_pcapng_block_trailer_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_pcapng_section_body_le_fields[] = {
    SX_FIELD("byte_order_magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("major_version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("section_length", "int64", 8, 8, SX_SIZE),
};
static const sx_layout sx_s_pcapng_section_body_le = { UINT32_C(0x600C005F), "pcapng_section_body_le", sx_s_pcapng_section_body_le_fields, SX_COUNT(sx_s_pcapng_section_body_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_pcapng_interface_body_le_fields[] = {
    SX_FIELD("link_type", "uint16", 0, 2, SX_ID),
    SX_FIELD("reserved", "uint16", 2, 2, SX_RESERVED),
    SX_FIELD("snap_length", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_interface_body_le = { UINT32_C(0x600C0060), "pcapng_interface_body_le", sx_s_pcapng_interface_body_le_fields, SX_COUNT(sx_s_pcapng_interface_body_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_pcapng_enhanced_packet_body_le_fields[] = {
    SX_FIELD("interface_id", "uint32", 0, 4, SX_ID),
    SX_FIELD("timestamp_high", "uint32", 4, 4, SX_NONE),
    SX_FIELD("timestamp_low", "uint32", 8, 4, SX_NONE),
    SX_FIELD("captured_length", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("original_length", "uint32", 16, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_enhanced_packet_body_le = { UINT32_C(0x600C0061), "pcapng_enhanced_packet_body_le", sx_s_pcapng_enhanced_packet_body_le_fields, SX_COUNT(sx_s_pcapng_enhanced_packet_body_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_pcapng_simple_packet_body_le_fields[] = {
    SX_FIELD("original_length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_simple_packet_body_le = { UINT32_C(0x600C0062), "pcapng_simple_packet_body_le", sx_s_pcapng_simple_packet_body_le_fields, SX_COUNT(sx_s_pcapng_simple_packet_body_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_pcapng_obsolete_packet_body_le_fields[] = {
    SX_FIELD("interface_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("dropped_packets", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("timestamp_high", "uint32", 4, 4, SX_NONE),
    SX_FIELD("timestamp_low", "uint32", 8, 4, SX_NONE),
    SX_FIELD("captured_length", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("original_length", "uint32", 16, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_obsolete_packet_body_le = { UINT32_C(0x600C0063), "pcapng_obsolete_packet_body_le", sx_s_pcapng_obsolete_packet_body_le_fields, SX_COUNT(sx_s_pcapng_obsolete_packet_body_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_pcapng_option_le_fields[] = {
    SX_FIELD("code", "uint16", 0, 2, SX_ID),
    SX_FIELD("length", "uint16", 2, 2, SX_SIZE),
};
static const sx_layout sx_s_pcapng_option_le = { UINT32_C(0x600C0064), "pcapng_option_le", sx_s_pcapng_option_le_fields, SX_COUNT(sx_s_pcapng_option_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_icu_data_header_le_fields[] = {
    SX_FIELD("header_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("magic", "bytes", 2, 2, SX_SIGNATURE),
    SX_FIELD("info_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("reserved_word", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("big_endian", "uint8", 8, 1, SX_FLAGS),
    SX_FIELD("charset_family", "uint8", 9, 1, SX_ID),
    SX_FIELD("uchar_size", "uint8", 10, 1, SX_SIZE),
    SX_FIELD("reserved_byte", "uint8", 11, 1, SX_RESERVED),
    SX_FIELD("data_format", "char[4]", 12, 4, SX_ID),
    SX_FIELD("format_version", "bytes", 16, 4, SX_NONE),
    SX_FIELD("data_version", "bytes", 20, 4, SX_NONE),
};
static const sx_layout sx_s_icu_data_header_le = { UINT32_C(0x600C0065), "icu_data_header_le", sx_s_icu_data_header_le_fields, SX_COUNT(sx_s_icu_data_header_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_icu_toc_count_le_fields[] = {
    SX_FIELD("file_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sx_s_icu_toc_count_le = { UINT32_C(0x600C0066), "icu_toc_count_le", sx_s_icu_toc_count_le_fields, SX_COUNT(sx_s_icu_toc_count_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_icu_toc_entry_le_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sx_s_icu_toc_entry_le = { UINT32_C(0x600C0067), "icu_toc_entry_le", sx_s_icu_toc_entry_le_fields, SX_COUNT(sx_s_icu_toc_entry_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_s_pcapng_block_header_be_fields[] = {
    SX_FIELD("block_type", "uint32", 0, 4, SX_ID),
    SX_FIELD("block_length", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_block_header_be = { UINT32_C(0x600C0068), "pcapng_block_header_be", sx_s_pcapng_block_header_be_fields, SX_COUNT(sx_s_pcapng_block_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_pcapng_block_trailer_be_fields[] = {
    SX_FIELD("block_length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_block_trailer_be = { UINT32_C(0x600C0069), "pcapng_block_trailer_be", sx_s_pcapng_block_trailer_be_fields, SX_COUNT(sx_s_pcapng_block_trailer_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_pcapng_section_body_be_fields[] = {
    SX_FIELD("byte_order_magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("major_version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("section_length", "int64", 8, 8, SX_SIZE),
};
static const sx_layout sx_s_pcapng_section_body_be = { UINT32_C(0x600C006A), "pcapng_section_body_be", sx_s_pcapng_section_body_be_fields, SX_COUNT(sx_s_pcapng_section_body_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_pcapng_interface_body_be_fields[] = {
    SX_FIELD("link_type", "uint16", 0, 2, SX_ID),
    SX_FIELD("reserved", "uint16", 2, 2, SX_RESERVED),
    SX_FIELD("snap_length", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_interface_body_be = { UINT32_C(0x600C006B), "pcapng_interface_body_be", sx_s_pcapng_interface_body_be_fields, SX_COUNT(sx_s_pcapng_interface_body_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_pcapng_enhanced_packet_body_be_fields[] = {
    SX_FIELD("interface_id", "uint32", 0, 4, SX_ID),
    SX_FIELD("timestamp_high", "uint32", 4, 4, SX_NONE),
    SX_FIELD("timestamp_low", "uint32", 8, 4, SX_NONE),
    SX_FIELD("captured_length", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("original_length", "uint32", 16, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_enhanced_packet_body_be = { UINT32_C(0x600C006C), "pcapng_enhanced_packet_body_be", sx_s_pcapng_enhanced_packet_body_be_fields, SX_COUNT(sx_s_pcapng_enhanced_packet_body_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_pcapng_simple_packet_body_be_fields[] = {
    SX_FIELD("original_length", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_simple_packet_body_be = { UINT32_C(0x600C006D), "pcapng_simple_packet_body_be", sx_s_pcapng_simple_packet_body_be_fields, SX_COUNT(sx_s_pcapng_simple_packet_body_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_pcapng_obsolete_packet_body_be_fields[] = {
    SX_FIELD("interface_id", "uint16", 0, 2, SX_ID),
    SX_FIELD("dropped_packets", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("timestamp_high", "uint32", 4, 4, SX_NONE),
    SX_FIELD("timestamp_low", "uint32", 8, 4, SX_NONE),
    SX_FIELD("captured_length", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("original_length", "uint32", 16, 4, SX_SIZE),
};
static const sx_layout sx_s_pcapng_obsolete_packet_body_be = { UINT32_C(0x600C006E), "pcapng_obsolete_packet_body_be", sx_s_pcapng_obsolete_packet_body_be_fields, SX_COUNT(sx_s_pcapng_obsolete_packet_body_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_pcapng_option_be_fields[] = {
    SX_FIELD("code", "uint16", 0, 2, SX_ID),
    SX_FIELD("length", "uint16", 2, 2, SX_SIZE),
};
static const sx_layout sx_s_pcapng_option_be = { UINT32_C(0x600C006F), "pcapng_option_be", sx_s_pcapng_option_be_fields, SX_COUNT(sx_s_pcapng_option_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_icu_data_header_be_fields[] = {
    SX_FIELD("header_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("magic", "bytes", 2, 2, SX_SIGNATURE),
    SX_FIELD("info_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("reserved_word", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("big_endian", "uint8", 8, 1, SX_FLAGS),
    SX_FIELD("charset_family", "uint8", 9, 1, SX_ID),
    SX_FIELD("uchar_size", "uint8", 10, 1, SX_SIZE),
    SX_FIELD("reserved_byte", "uint8", 11, 1, SX_RESERVED),
    SX_FIELD("data_format", "char[4]", 12, 4, SX_ID),
    SX_FIELD("format_version", "bytes", 16, 4, SX_NONE),
    SX_FIELD("data_version", "bytes", 20, 4, SX_NONE),
};
static const sx_layout sx_s_icu_data_header_be = { UINT32_C(0x600C0070), "icu_data_header_be", sx_s_icu_data_header_be_fields, SX_COUNT(sx_s_icu_data_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_icu_toc_count_be_fields[] = {
    SX_FIELD("file_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sx_s_icu_toc_count_be = { UINT32_C(0x600C0071), "icu_toc_count_be", sx_s_icu_toc_count_be_fields, SX_COUNT(sx_s_icu_toc_count_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_s_icu_toc_entry_be_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sx_s_icu_toc_entry_be = { UINT32_C(0x600C0072), "icu_toc_entry_be", sx_s_icu_toc_entry_be_fields, SX_COUNT(sx_s_icu_toc_entry_be_fields), SX_BE };

static const sx_layout *const sx_systems_layouts[] = {
    &sx_s_wince_image_header,
    &sx_s_wince_record_header,
    &sx_s_wince_terminator,
    &sx_s_binhdr_header,
    &sx_s_rtk_header,
    &sx_s_packimg_header,
    &sx_s_dlob_entity_header,
    &sx_s_dlob_digest,
    &sx_s_chk_header,
    &sx_s_csman_header_le,
    &sx_s_csman_entry_le,
    &sx_s_csman_terminator_le,
    &sx_s_csman_header_be,
    &sx_s_csman_entry_be,
    &sx_s_csman_terminator_be,
    &sx_s_matter_ota_preamble,
    &sx_s_twoimg_header,
    &sx_s_t64_header,
    &sx_s_t64_directory_entry,
    &sx_s_scl_header,
    &sx_s_scl_catalogue_entry,
    &sx_s_ciso_header,
    &sx_s_ciso_index_entry,
    &sx_s_dax_header,
    &sx_s_dax_frame_offset,
    &sx_s_dax_frame_size,
    &sx_s_dax_uncompressed_area,
    &sx_s_palm_database_header,
    &sx_s_palm_record_entry,
    &sx_s_palm_resource_entry,
    &sx_s_dbase3_header,
    &sx_s_dbase3_field_descriptor,
    &sx_s_dbase3_record_marker,
    &sx_s_dbase3_header_terminator,
    &sx_s_dns_header,
    &sx_s_dns_question,
    &sx_s_dns_resource_header,
    &sx_s_modbus_mbap_header,
    &sx_s_modbus_read_request,
    &sx_s_modbus_write_multiple_response,
    &sx_s_modbus_write_single,
    &sx_s_modbus_read_response,
    &sx_s_modbus_write_multiple,
    &sx_s_modbus_exception,
    &sx_s_modbus_register_value,
    &sx_s_someip_header,
    &sx_s_coap_header,
    &sx_s_coap_option_header,
    &sx_s_coap_delta_extension8,
    &sx_s_coap_delta_extension16,
    &sx_s_coap_length_extension8,
    &sx_s_coap_length_extension16,
    &sx_s_stun_header,
    &sx_s_stun_attribute_header,
    &sx_s_dhcp_header,
    &sx_s_dhcp_option,
    &sx_s_dhcp_option_marker,
    &sx_s_radius_header,
    &sx_s_radius_attribute,
    &sx_s_ntp_header,
    &sx_s_rip_header,
    &sx_s_rip_route,
    &sx_s_vrrp2_header,
    &sx_s_vrrp2_ipv4,
    &sx_s_vrrp2_authentication,
    &sx_s_igmp3_report_header,
    &sx_s_igmp3_group_record,
    &sx_s_igmp3_source_ipv4,
    &sx_s_lldp_tlv_header,
    &sx_s_lldp_identifier_subtype,
    &sx_s_lldp_ttl,
    &sx_s_lldp_capabilities,
    &sx_s_arp_ethernet_ipv4,
    &sx_s_mongodb_opmsg_header,
    &sx_s_mongodb_section_kind,
    &sx_s_mongodb_sequence_size,
    &sx_s_mongodb_document_size,
    &sx_s_mongodb_checksum,
    &sx_s_dbus_header_le,
    &sx_s_dbus_header_be,
    &sx_s_shell_link_header,
    &sx_s_shell_link_idlist_size,
    &sx_s_shell_link_item_id,
    &sx_s_shell_link_info,
    &sx_s_shell_link_info_unicode_offsets,
    &sx_s_shell_link_string_count,
    &sx_s_shell_link_extra_header,
    &sx_s_shell_link_terminal,
    &sx_s_icc_profile_header,
    &sx_s_icc_tag_count,
    &sx_s_icc_tag_entry,
    &sx_s_icc_tag_type,
    &sx_s_pcapng_block_header_le,
    &sx_s_pcapng_block_trailer_le,
    &sx_s_pcapng_section_body_le,
    &sx_s_pcapng_interface_body_le,
    &sx_s_pcapng_enhanced_packet_body_le,
    &sx_s_pcapng_simple_packet_body_le,
    &sx_s_pcapng_obsolete_packet_body_le,
    &sx_s_pcapng_option_le,
    &sx_s_icu_data_header_le,
    &sx_s_icu_toc_count_le,
    &sx_s_icu_toc_entry_le,
    &sx_s_pcapng_block_header_be,
    &sx_s_pcapng_block_trailer_be,
    &sx_s_pcapng_section_body_be,
    &sx_s_pcapng_interface_body_be,
    &sx_s_pcapng_enhanced_packet_body_be,
    &sx_s_pcapng_simple_packet_body_be,
    &sx_s_pcapng_obsolete_packet_body_be,
    &sx_s_pcapng_option_be,
    &sx_s_icu_data_header_be,
    &sx_s_icu_toc_count_be,
    &sx_s_icu_toc_entry_be,
};

static bool sx_systems_supports(xx_file_type_t type) {
    switch(type) {
    case XX_FILE_TYPE_WINCE:
    case XX_FILE_TYPE_BINHDR:
    case XX_FILE_TYPE_RTK:
    case XX_FILE_TYPE_PACKIMG:
    case XX_FILE_TYPE_DLOB:
    case XX_FILE_TYPE_CHK:
    case XX_FILE_TYPE_CSMAN:
    case XX_FILE_TYPE_MATTER_OTA:
    case XX_FILE_TYPE_TWOIMG:
    case XX_FILE_TYPE_T64:
    case XX_FILE_TYPE_SCL:
    case XX_FILE_TYPE_CISO:
    case XX_FILE_TYPE_CISO2:
    case XX_FILE_TYPE_ZISO:
    case XX_FILE_TYPE_DAX:
    case XX_FILE_TYPE_PDB:
    case XX_FILE_TYPE_DBASE_DBF:
    case XX_FILE_TYPE_DNS_MESSAGE:
    case XX_FILE_TYPE_MODBUS_TCP:
    case XX_FILE_TYPE_SOMEIP_MESSAGE:
    case XX_FILE_TYPE_COAP_MESSAGE:
    case XX_FILE_TYPE_STUN_MESSAGE:
    case XX_FILE_TYPE_DHCP_MESSAGE:
    case XX_FILE_TYPE_RADIUS_PACKET:
    case XX_FILE_TYPE_NTP_MESSAGE:
    case XX_FILE_TYPE_RIP_MESSAGE:
    case XX_FILE_TYPE_VRRP_MESSAGE:
    case XX_FILE_TYPE_IGMP_MESSAGE:
    case XX_FILE_TYPE_LLDP_MESSAGE:
    case XX_FILE_TYPE_ARP_PACKET:
    case XX_FILE_TYPE_MONGODB_WIRE:
    case XX_FILE_TYPE_DBUS_MESSAGE:
    case XX_FILE_TYPE_WINDOWS_SHELL_LINK:
    case XX_FILE_TYPE_ICC:
    case XX_FILE_TYPE_PCAPNG:
    case XX_FILE_TYPE_ICU_DATA_PACKAGE:
        return true;
    default:return false;
    }
}

/* Native readers establish validity; this layer exposes bounded physical
 * metadata only. Unknown payloads, opcode operands, and extensions stay raw. */
static uint32_t sx_s_u32(sx_context *c,uint64_t o,bool be) {uint32_t v=0;if(o>INT64_MAX||!sx_u32(c,(int64_t)o,be,&v))c->failed=true;return v;}
static uint64_t sx_s_u64(sx_context *c,uint64_t o,bool be) {uint64_t v=0;if(o>INT64_MAX||!sx_u64(c,(int64_t)o,be,&v))c->failed=true;return v;}
static uint16_t sx_s_u16(sx_context *c,uint64_t o,bool be) {uint16_t v=0;if(o>INT64_MAX||!sx_u16(c,(int64_t)o,be,&v))c->failed=true;return v;}
static uint8_t sx_s_u8(sx_context *c,uint64_t o) {uint8_t v=0;if(o>INT64_MAX||!sx_read(c,(int64_t)o,&v,1))c->failed=true;return v;}
static bool sx_s_range(sx_context *c,uint64_t o,uint64_t n) {return o<=INT64_MAX&&sx_range(c,(int64_t)o,n);}
static int64_t sx_s_extent(const sx_layout *l) {int64_t n=0;for(size_t i=0;i<l->field_count;i++){int64_t e=l->fields[i].rel_offset+l->fields[i].size;if(e>n)n=e;}return n;}
static bool sx_s_record(sx_context *c,const sx_layout *l,uint64_t o) {return o<=INT64_MAX&&sx_add(c,l,(int64_t)o,sx_s_extent(l));}
static bool sx_s_table(sx_context *c,const sx_layout *l,uint64_t o,uint64_t n) {return n<=100000&&o<=INT64_MAX&&sx_table(c,l,(int64_t)o,sx_s_extent(l),n);}
/* Heap sorting keeps pathological reverse-order directory pointers O(n log n). */
static void sx_s_sift(xx_data_struct *a,size_t n,size_t root) {
    while(root<n/2){size_t child=root*2+1;if(child+1<n&&a[child].offset<a[child+1].offset)child++;if(a[root].offset>=a[child].offset)break;xx_data_struct t=a[root];a[root]=a[child];a[child]=t;root=child;}
}
static void sx_s_sort(xx_data_struct *a,size_t n) {
    for(size_t i=n/2;i>0;i--)sx_s_sift(a,n,i-1);
    for(size_t i=n;i>1;i--){xx_data_struct t=a[0];a[0]=a[i-1];a[i-1]=t;sx_s_sift(a,i-1,0);}
}
static bool sx_s_finish(sx_context *c) {
    size_t n=c->count;uint64_t end=0;sx_s_sort(c->items,n);
    for(size_t i=0;i<n;i++) {xx_data_struct d=c->items[i];uint64_t at=(uint64_t)(d.offset-c->f->base_address);
        if(at<end)return false;
        if(at>end&&!sx_raw(c,(int64_t)end,(int64_t)(at-end)))return false;
        end=at+(uint64_t)d.total_size;
    }
    if(end>(uint64_t)c->size||!sx_raw(c,(int64_t)end,c->size-(int64_t)end))return false;
    sx_s_sort(c->items,c->count);return !c->failed;
}
static bool sx_s_dns_name(sx_context *c,uint64_t *at,uint64_t end) {
    for(unsigned labels=0;labels<128;labels++) {if(*at>=end)return false;unsigned n=sx_s_u8(c,(*at)++);if(!n)return true;
        if((n&192)==192){if(*at>=end)return false;(*at)++;return !c->failed;}
        if(n>63||n>end-*at)return false;*at+=n;
    }return false;
}
static bool sx_s_options(sx_context *c,uint64_t at,uint64_t end,bool be) {
    /* Option framing is optional to the native capture reader. Preserve a
     * valid block header when the option tail is malformed, leaving it raw. */
    uint64_t cursor=at;unsigned count=0;
    while(cursor<end) {if(++count>65536||end-cursor<4)return true;uint64_t n=sx_s_u16(c,cursor+2,be);unsigned code=sx_s_u16(c,cursor,be);
        if(n>end-cursor-4)return true;cursor+=4+((n+3)&~UINT64_C(3));if(cursor>end)return true;if(!code){if(n)return true;break;}}
    while(at<cursor){uint64_t n=sx_s_u16(c,at+2,be);if(!sx_s_record(c,be?&sx_s_pcapng_option_be:&sx_s_pcapng_option_le,at))return false;at+=4+((n+3)&~UINT64_C(3));}
    return !c->failed;
}
static bool sx_s_pcapng(sx_context *c) {
    uint64_t at=0,limit=(uint64_t)c->size;bool be=false;unsigned blocks=0;
    while(at<limit) {
        if(limit-at<12)break;uint32_t type=sx_s_u32(c,at,false);
        if(type==UINT32_C(0x0a0d0d0a)){if(limit-at<28)break;uint32_t magic=sx_s_u32(c,at+8,false);if(magic!=UINT32_C(0x1a2b3c4d)&&magic!=UINT32_C(0x4d3c2b1a))break;be=magic==UINT32_C(0x4d3c2b1a);}
        type=sx_s_u32(c,at,be);uint64_t n=sx_s_u32(c,at+4,be),head=8,payload=0;
        /* Native carving tolerates short malformed trailing blocks. Keep those
         * bytes raw; they cannot contain distinct header and trailer records. */
        if(n<12||(n&3)||n>limit-at||sx_s_u32(c,at+n-4,be)!=n)break;
        if(++blocks>65536||!sx_s_record(c,be?&sx_s_pcapng_block_header_be:&sx_s_pcapng_block_header_le,at)||!sx_s_record(c,be?&sx_s_pcapng_block_trailer_be:&sx_s_pcapng_block_trailer_le,at+n-4))return false;
        const sx_layout *body=NULL;
        if(type==UINT32_C(0x0a0d0d0a)&&n>=28){body=be?&sx_s_pcapng_section_body_be:&sx_s_pcapng_section_body_le;head=24;}
        else if(type==1&&n>=20){body=be?&sx_s_pcapng_interface_body_be:&sx_s_pcapng_interface_body_le;head=16;}
        else if((type==6||type==2)&&n>=32){uint64_t cap=sx_s_u32(c,at+20,be);if(cap<=n-32){body=type==6?(be?&sx_s_pcapng_enhanced_packet_body_be:&sx_s_pcapng_enhanced_packet_body_le):(be?&sx_s_pcapng_obsolete_packet_body_be:&sx_s_pcapng_obsolete_packet_body_le);head=28;payload=(cap+3)&~UINT64_C(3);}}
        else if(type==3&&n>=16){body=be?&sx_s_pcapng_simple_packet_body_be:&sx_s_pcapng_simple_packet_body_le;head=n-4;}
        if(body&&!sx_s_record(c,body,at+8))return false;
        if(body&&type!=3&&head+payload<=n-4&&!sx_s_options(c,at+head+payload,at+n-4,be))return false;
        at+=n;
    }return blocks>0&&!c->failed;
}
static bool sx_systems_walk(sx_context *c) {
    uint64_t at=0,n=0,off=0,size=0,end=(uint64_t)c->size;uint32_t v=0;bool be=false;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_WINCE:
        if(!sx_s_record(c,&sx_s_wince_image_header,0))return false;at=15;
        for(unsigned i=0;i<65536;i++){v=sx_s_u32(c,at,false);n=sx_s_u32(c,at+4,false);if(!sx_s_record(c,v?&sx_s_wince_record_header:&sx_s_wince_terminator,at))return false;at+=12;if(!v)return true;if(!sx_s_range(c,at,n))return false;at+=n;}return false;
    case XX_FILE_TYPE_BINHDR:return sx_s_record(c,&sx_s_binhdr_header,0);
    case XX_FILE_TYPE_RTK:
        off=4+(uint64_t)sx_s_u32(c,16,false);size=sx_s_u32(c,4,false);return off>=32&&sx_s_range(c,off,size)&&sx_s_record(c,&sx_s_rtk_header,0);
    case XX_FILE_TYPE_PACKIMG:return sx_s_range(c,32,sx_s_u32(c,16,false))&&sx_s_record(c,&sx_s_packimg_header,0);
    case XX_FILE_TYPE_DLOB:
        if(!sx_s_record(c,&sx_s_dlob_entity_header,0))return false;at=12+(uint64_t)sx_s_u16(c,6,true);
        if(!sx_s_record(c,&sx_s_dlob_entity_header,at)||!sx_s_record(c,&sx_s_dlob_digest,at+12))return false;return sx_s_range(c,at+28+(uint64_t)sx_s_u16(c,at+6,true),sx_s_u32(c,at+8,true));
    case XX_FILE_TYPE_CHK:
        off=sx_s_u32(c,4,true);n=sx_s_u32(c,24,true);size=sx_s_u32(c,28,true);return off>=40&&sx_s_range(c,off,n+size)&&sx_s_record(c,&sx_s_chk_header,0);
    case XX_FILE_TYPE_CSMAN:
        be=sx_s_u8(c,0)=='S';n=sx_s_u32(c,4,be);size=sx_s_u32(c,12,be);if(!sx_s_range(c,16,n)||!sx_s_record(c,be?&sx_s_csman_header_be:&sx_s_csman_header_le,0))return false;
        if(n!=size)return true;at=16;end=16+n;
        while(at<end){if(end-at<4)return false;v=sx_s_u32(c,at,be);if(!v)return sx_s_record(c,be?&sx_s_csman_terminator_be:&sx_s_csman_terminator_le,at);if(end-at<6)return false;n=sx_s_u16(c,at+4,be);if(n>end-at-6||!sx_s_record(c,be?&sx_s_csman_entry_be:&sx_s_csman_entry_le,at))return false;at+=6+n;}return false;
    case XX_FILE_TYPE_MATTER_OTA:
        n=sx_s_u64(c,4,false);size=sx_s_u32(c,12,false);return n>=16&&size<=n-16&&sx_s_range(c,0,n)&&sx_s_record(c,&sx_s_matter_ota_preamble,0);
    case XX_FILE_TYPE_TWOIMG:return sx_s_record(c,&sx_s_twoimg_header,0);
    case XX_FILE_TYPE_T64:
        if(!sx_s_record(c,&sx_s_t64_header,0))return false;n=sx_s_u16(c,34,false);at=64;
        for(uint64_t i=0;i<n&&at<=end&&end-at>=32;i++,at+=32){v=sx_s_u8(c,at);off=sx_s_u32(c,at+8,false);if(!sx_s_record(c,&sx_s_t64_directory_entry,at))return false;if(v>0&&v<=4&&off>=at+32&&off<end)end=off;}break;
    case XX_FILE_TYPE_SCL:return sx_s_record(c,&sx_s_scl_header,0)&&sx_s_table(c,&sx_s_scl_catalogue_entry,9,sx_s_u8(c,8));
    case XX_FILE_TYPE_CISO:case XX_FILE_TYPE_CISO2:case XX_FILE_TYPE_ZISO:case XX_FILE_TYPE_DAX:
        if(sx_s_u32(c,0,false)==UINT32_C(0x00584144)){n=((uint64_t)sx_s_u32(c,4,false)+8191)/8192;size=sx_s_u32(c,12,false);return sx_s_record(c,&sx_s_dax_header,0)&&sx_s_table(c,&sx_s_dax_frame_offset,32,n)&&sx_s_table(c,&sx_s_dax_frame_size,32+4*n,n)&&sx_s_table(c,&sx_s_dax_uncompressed_area,32+6*n,size);}
        size=sx_s_u32(c,16,false);n=sx_s_u64(c,8,false);return size&&n%size==0&&n/size<100000&&sx_s_record(c,&sx_s_ciso_header,0)&&sx_s_table(c,&sx_s_ciso_index_entry,24,n/size+1);
    case XX_FILE_TYPE_PDB:
        v=sx_s_u16(c,32,true);n=sx_s_u16(c,76,true);return sx_s_record(c,&sx_s_palm_database_header,0)&&sx_s_table(c,(v&1)?&sx_s_palm_resource_entry:&sx_s_palm_record_entry,78,n);
    case XX_FILE_TYPE_DBASE_DBF:
        off=sx_s_u16(c,8,false);size=sx_s_u16(c,10,false);n=sx_s_u32(c,4,false);
        if(off<33||(off-33)%32||!size||n>100000||!sx_s_record(c,&sx_s_dbase3_header,0)||!sx_s_table(c,&sx_s_dbase3_field_descriptor,32,(off-33)/32)||!sx_s_record(c,&sx_s_dbase3_header_terminator,off-1)||n>UINT64_MAX/size||!sx_s_range(c,off,n*size))return false;
        for(uint64_t i=0;i<n;i++)if(!sx_s_record(c,&sx_s_dbase3_record_marker,off+i*size))return false;break;
    case XX_FILE_TYPE_DNS_MESSAGE:
        if(!sx_s_record(c,&sx_s_dns_header,0))return false;n=sx_s_u16(c,4,true);at=12;
        for(uint64_t i=0;i<n;i++){if(!sx_s_dns_name(c,&at,end)||!sx_s_record(c,&sx_s_dns_question,at))return false;at+=4;}
        n=(uint64_t)sx_s_u16(c,6,true)+sx_s_u16(c,8,true)+sx_s_u16(c,10,true);if(n>100000)return false;
        for(uint64_t i=0;i<n;i++){if(!sx_s_dns_name(c,&at,end)||!sx_s_record(c,&sx_s_dns_resource_header,at))return false;size=sx_s_u16(c,at+8,true);at+=10;if(!sx_s_range(c,at,size))return false;at+=size;}break;
    case XX_FILE_TYPE_MODBUS_TCP:
        while(at<end){n=sx_s_u16(c,at+4,true);if(n<2||!sx_s_range(c,at,6+n)||!sx_s_record(c,&sx_s_modbus_mbap_header,at))return false;off=at+7;size=n-1;v=sx_s_u8(c,off);const sx_layout *l=NULL;
            if(v&128)l=&sx_s_modbus_exception;else if(v==3)l=size==5?&sx_s_modbus_read_request:&sx_s_modbus_read_response;else if(v==5||v==6)l=&sx_s_modbus_write_single;else if(v==16)l=size==5?&sx_s_modbus_write_multiple_response:&sx_s_modbus_write_multiple;else return false;
            if((uint64_t)sx_s_extent(l)>size||!sx_s_record(c,l,off))return false;
            if(v==3&&size!=5){uint64_t bytes=sx_s_u8(c,off+1);if(bytes!=size-2||(bytes&1)||!sx_s_table(c,&sx_s_modbus_register_value,off+2,bytes/2))return false;}
            if(v==16&&size!=5){uint64_t bytes=sx_s_u8(c,off+5);if(bytes!=size-6||(bytes&1)||!sx_s_table(c,&sx_s_modbus_register_value,off+6,bytes/2))return false;}
            at+=6+n;}break;
    case XX_FILE_TYPE_SOMEIP_MESSAGE:
        while(at<end){n=sx_s_u32(c,at+4,true);if(n<8||!sx_s_range(c,at,8+n)||!sx_s_record(c,&sx_s_someip_header,at))return false;at+=8+n;}break;
    case XX_FILE_TYPE_COAP_MESSAGE:
        if(!sx_s_record(c,&sx_s_coap_header,0))return false;at=4+(sx_s_u8(c,0)&15);if(at>end)return false;
        while(at<end){v=sx_s_u8(c,at);if(v==255)break;if(!sx_s_record(c,&sx_s_coap_option_header,at++))return false;n=0;
            for(unsigned part=0;part<2;part++){unsigned nib=part?(v&15):(v>>4);uint64_t val=nib;const sx_layout *l=NULL;if(nib==15)return false;
                if(nib==13){l=part?&sx_s_coap_length_extension8:&sx_s_coap_delta_extension8;val=13+sx_s_u8(c,at);}
                if(nib==14){l=part?&sx_s_coap_length_extension16:&sx_s_coap_delta_extension16;val=269+sx_s_u16(c,at,true);}
                if(l){if(!sx_s_record(c,l,at))return false;at+=(uint64_t)sx_s_extent(l);}if(part)n=val;}
            if(!sx_s_range(c,at,n))return false;at+=n;}break;
    case XX_FILE_TYPE_STUN_MESSAGE:
        if(!sx_s_record(c,&sx_s_stun_header,0))return false;at=20;end=20+(uint64_t)sx_s_u16(c,2,true);if(!sx_s_range(c,0,end))return false;
        while(at<end){if(end-at<4)return false;n=sx_s_u16(c,at+2,true);n=(n+3)&~UINT64_C(3);if(n>end-at-4||!sx_s_record(c,&sx_s_stun_attribute_header,at))return false;at+=4+n;}break;
    case XX_FILE_TYPE_DHCP_MESSAGE:
        if(!sx_s_record(c,&sx_s_dhcp_header,0))return false;at=240;
        while(at<end){v=sx_s_u8(c,at);if(v==0||v==255){if(!sx_s_record(c,&sx_s_dhcp_option_marker,at++))return false;if(v==255)break;continue;}n=sx_s_u8(c,at+1);if(!sx_s_range(c,at,2+n)||!sx_s_record(c,&sx_s_dhcp_option,at))return false;at+=2+n;}break;
    case XX_FILE_TYPE_RADIUS_PACKET:
        if(!sx_s_record(c,&sx_s_radius_header,0))return false;at=20;end=sx_s_u16(c,2,true);if(end<20||!sx_s_range(c,0,end))return false;
        while(at<end){n=sx_s_u8(c,at+1);if(n<2||n>end-at||!sx_s_record(c,&sx_s_radius_attribute,at))return false;at+=n;}break;
    case XX_FILE_TYPE_NTP_MESSAGE:return sx_s_record(c,&sx_s_ntp_header,0);
    case XX_FILE_TYPE_RIP_MESSAGE:return end>=4&&(end-4)%20==0&&sx_s_record(c,&sx_s_rip_header,0)&&sx_s_table(c,&sx_s_rip_route,4,(end-4)/20);
    case XX_FILE_TYPE_VRRP_MESSAGE:
        n=sx_s_u8(c,3);return sx_s_record(c,&sx_s_vrrp2_header,0)&&sx_s_table(c,&sx_s_vrrp2_ipv4,8,n)&&sx_s_record(c,&sx_s_vrrp2_authentication,8+n*4);
    case XX_FILE_TYPE_IGMP_MESSAGE:
        if(!sx_s_record(c,&sx_s_igmp3_report_header,0))return false;n=sx_s_u16(c,6,true);at=8;
        for(uint64_t i=0;i<n;i++){v=sx_s_u8(c,at+1);size=sx_s_u16(c,at+2,true);if(!sx_s_record(c,&sx_s_igmp3_group_record,at)||!sx_s_table(c,&sx_s_igmp3_source_ipv4,at+8,size))return false;at+=8+size*4;if(!sx_s_range(c,at,v*4))return false;at+=v*4;}break;
    case XX_FILE_TYPE_LLDP_MESSAGE:
        while(at<end){v=sx_s_u16(c,at,true);n=v&511;v>>=9;if(!sx_s_range(c,at,2+n)||!sx_s_record(c,&sx_s_lldp_tlv_header,at))return false;at+=2;
            if(v==1||v==2){if(!n||!sx_s_record(c,&sx_s_lldp_identifier_subtype,at))return false;}
            else if(v==3){if(n!=2||!sx_s_record(c,&sx_s_lldp_ttl,at))return false;}
            else if(v==7){if(n!=4||!sx_s_record(c,&sx_s_lldp_capabilities,at))return false;}
            at+=n;if(!v)break;}break;
    case XX_FILE_TYPE_ARP_PACKET:return sx_s_record(c,&sx_s_arp_ethernet_ipv4,0);
    case XX_FILE_TYPE_MONGODB_WIRE:
        while(at<end){size=sx_s_u32(c,at,false);v=sx_s_u32(c,at+16,false);if(size<20||!sx_s_range(c,at,size)||!sx_s_record(c,&sx_s_mongodb_opmsg_header,at))return false;uint64_t next=at+size,stop=next;
            if(v&1){if(size<24||!sx_s_record(c,&sx_s_mongodb_checksum,next-4))return false;stop-=4;}at+=20;
            while(at<stop){v=sx_s_u8(c,at);if(!sx_s_record(c,&sx_s_mongodb_section_kind,at++))return false;
                if(!v){n=sx_s_u32(c,at,false);if(n<5||n>stop-at||!sx_s_record(c,&sx_s_mongodb_document_size,at))return false;at+=n;}
                else if(v==1){n=sx_s_u32(c,at,false);if(n<5||n>stop-at||!sx_s_record(c,&sx_s_mongodb_sequence_size,at))return false;uint64_t seqend=at+n;at+=4;bool nul=false;while(at<seqend){if(!sx_s_u8(c,at++)){nul=true;break;}}if(!nul)return false;
                    while(at<seqend){n=sx_s_u32(c,at,false);if(n<5||n>seqend-at||!sx_s_record(c,&sx_s_mongodb_document_size,at))return false;at+=n;}}
                else return false;
            }at=next;}break;
    case XX_FILE_TYPE_DBUS_MESSAGE:be=sx_s_u8(c,0)=='B';return sx_s_record(c,be?&sx_s_dbus_header_be:&sx_s_dbus_header_le,0);
    case XX_FILE_TYPE_WINDOWS_SHELL_LINK:
        if(!sx_s_record(c,&sx_s_shell_link_header,0))return false;v=sx_s_u32(c,20,false);at=76;
        if(v&1){n=sx_s_u16(c,at,false);if(!sx_s_record(c,&sx_s_shell_link_idlist_size,at)||!sx_s_range(c,at+2,n))return false;at+=2;uint64_t stop=at+n;
            while(at<stop){size=sx_s_u16(c,at,false);if(stop-at<2||!sx_s_record(c,&sx_s_shell_link_item_id,at))return false;if(!size){at+=2;break;}if(size<2||size>stop-at)return false;at+=size;}if(at!=stop)return false;}
        if(v&2){n=sx_s_u32(c,at,false);size=sx_s_u32(c,at+4,false);if(n<28||size<28||size>n||!sx_s_range(c,at,n)||!sx_s_record(c,&sx_s_shell_link_info,at))return false;if(size>=36&&!sx_s_record(c,&sx_s_shell_link_info_unicode_offsets,at+28))return false;at+=n;}
        for(unsigned bit=2;bit<=6;bit++)if(v&(1U<<bit)){n=sx_s_u16(c,at,false);if(!sx_s_range(c,at,2+n*((v&128)?2:1))||!sx_s_record(c,&sx_s_shell_link_string_count,at))return false;at+=2+n*((v&128)?2:1);}
        while(at<end){n=sx_s_u32(c,at,false);if(!n)return sx_s_record(c,&sx_s_shell_link_terminal,at);if(n<8||!sx_s_range(c,at,n)||!sx_s_record(c,&sx_s_shell_link_extra_header,at))return false;at+=n;}return false;
    case XX_FILE_TYPE_ICC:
        if(!sx_s_record(c,&sx_s_icc_profile_header,0)||!sx_s_record(c,&sx_s_icc_tag_count,128))return false;n=sx_s_u32(c,128,true);if(n>1024||!sx_s_table(c,&sx_s_icc_tag_entry,132,n))return false;
        for(uint64_t i=0;i<n;i++){off=sx_s_u32(c,132+12*i+4,true);size=sx_s_u32(c,132+12*i+8,true);bool duplicate=false;
            for(uint64_t j=0;j<i;j++)if(sx_s_u32(c,132+12*j+4,true)==off){duplicate=true;break;}
            if(size<8||!sx_s_range(c,off,size)||(!duplicate&&!sx_s_record(c,&sx_s_icc_tag_type,off)))return false;}break;
    case XX_FILE_TYPE_PCAPNG:return sx_s_pcapng(c);
    case XX_FILE_TYPE_ICU_DATA_PACKAGE:
        be=sx_s_u8(c,8)!=0;off=sx_s_u16(c,0,be);n=sx_s_u32(c,off,be);
        if(!sx_s_record(c,be?&sx_s_icu_data_header_be:&sx_s_icu_data_header_le,0)||!sx_s_record(c,be?&sx_s_icu_toc_count_be:&sx_s_icu_toc_count_le,off)||!sx_s_table(c,be?&sx_s_icu_toc_entry_be:&sx_s_icu_toc_entry_le,off+4,n))return false;
        for(uint64_t i=0;i<n;i++){at=off+(uint64_t)sx_s_u32(c,off+4+8*i+4,be);if(!sx_s_record(c,be?&sx_s_icu_data_header_be:&sx_s_icu_data_header_le,at))return false;}break;
    default:return false;
    }return !c->failed;
}
static bool sx_systems_build(sx_context *c) {
    if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    return sx_systems_walk(c)&&c->count>0&&sx_s_finish(c);
}
static bool sx_s_contains(const wchar_t *text,const wchar_t *part) {
    size_t n=xx_rt_wcslen(part);for(;*text;text++)if(!xx_rt_wcsncmp(text,part,n))return true;return false;
}
static bool sx_systems_comment(xx_data_struct_record *r,uint32_t id) {
    if(!r||!r->name||id<UINT32_C(0x600c0000)||id>UINT32_C(0x600cffff))return true;
    const wchar_t *comment=NULL;
    if(!xx_rt_wcscmp(r->name,L"register_address")||!xx_rt_wcscmp(r->name,L"starting_register"))comment=L"Zero-based Modbus register address";
    else if(id==sx_s_ciso_index_entry.id)comment=L"Low 31 bits: block offset shifted left by alignment_shift; high bit: version-dependent storage flag";
    else if(!xx_rt_wcscmp(r->name,L"alignment_shift"))comment=L"Base-2 shift applied to encoded block offsets";
    else if(!xx_rt_wcscmp(r->name,L"header_size_excluding_magic"))comment=L"Byte length excluding the first four magic bytes";
    else if(!xx_rt_wcscmp(r->name,L"build_date_encoded"))comment=L"Raw vendor build-date encoding";
    else if(id==sx_s_palm_database_header.id&&(r->property&SX_TIME))comment=L"Seconds in the Palm database epoch (1904-01-01)";
    else if(id==sx_s_ntp_header.id){if(sx_s_contains(r->name,L"timestamp_32_32"))comment=L"NTP fixed point: seconds since 1900 in upper 32 bits; fractional seconds in lower 32 bits";else if(sx_s_contains(r->name,L"16_16"))comment=L"Fixed point seconds with 16 fractional bits";else if(sx_s_contains(r->name,L"exponent"))comment=L"Signed base-2 exponent in seconds";else if(!xx_rt_wcscmp(r->name,L"leap_version_mode"))comment=L"Leap indicator bits 6..7; version bits 3..5; mode bits 0..2";}
    else if(!xx_rt_wcscmp(r->name,L"timestamp_high")||!xx_rt_wcscmp(r->name,L"timestamp_low"))comment=L"One 32-bit half of the packet timestamp; units are selected by interface options";
    else if(!xx_rt_wcscmp(r->name,L"section_length"))comment=L"Bytes following this Section Header Block; -1 means unspecified";
    else if(!xx_rt_wcscmp(r->name,L"auxiliary_word_count"))comment=L"Number of 32-bit auxiliary-data words";
    else if(id==sx_s_lldp_tlv_header.id)comment=L"TLV type in upper 7 bits; value byte length in lower 9 bits";
    else if(id==sx_s_coap_header.id&&!xx_rt_wcscmp(r->name,L"version_type_token_length"))comment=L"Version bits 6..7; type bits 4..5; token byte length bits 0..3";
    else if(id==sx_s_coap_option_header.id)comment=L"High nibble: option-number delta; low nibble: value length; 13/14 select extended encodings";
    else if(sx_s_contains(r->name,L"encoded_")&&sx_s_contains(r->name,L"_extension"))comment=L"Encoded extension: add 13 for an 8-bit extension, or 269 for a 16-bit extension";
    else if(id==sx_s_shell_link_header.id&&(r->property&SX_TIME))comment=L"FILETIME: 100-nanosecond intervals since 1601-01-01 UTC";
    else if(!xx_rt_wcscmp(r->name,L"start_address_or_basic_length"))comment=L"TR-DOS start address, or BASIC program length according to file type";
    else if(id==sx_s_scl_catalogue_entry.id&&!xx_rt_wcscmp(r->name,L"sector_count"))comment=L"Number of 256-byte sectors";
    else if(id==sx_s_icc_profile_header.id&&sx_s_contains(r->name,L"16_16"))comment=L"Signed 16.16 fixed point tristimulus value";
    return !comment||xx_data_struct_record_set_comment(r,comment);
}

const sx_family sx_systems_family={sx_systems_supports,sx_systems_build,sx_systems_layouts,SX_COUNT(sx_systems_layouts),sx_systems_comment};
