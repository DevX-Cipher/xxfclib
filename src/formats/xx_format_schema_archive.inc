/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical archive and compressed stream schemas; payload bytes stay raw.
 */
static const xx_data_struct_field_desc sx_a_cpio_newc_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("ino", "ascii_hex[8]", 6, 8, SX_ID),
    SX_FIELD("mode", "ascii_hex[8]", 14, 8, SX_FLAGS),
    SX_FIELD("uid", "ascii_hex[8]", 22, 8, SX_ID),
    SX_FIELD("gid", "ascii_hex[8]", 30, 8, SX_ID),
    SX_FIELD("nlink", "ascii_hex[8]", 38, 8, SX_COUNT_PROP),
    SX_FIELD("mtime", "ascii_hex[8]", 46, 8, SX_TIME),
    SX_FIELD("filesize", "ascii_hex[8]", 54, 8, SX_SIZE),
    SX_FIELD("devmajor", "ascii_hex[8]", 62, 8, SX_ID),
    SX_FIELD("devminor", "ascii_hex[8]", 70, 8, SX_ID),
    SX_FIELD("rdevmajor", "ascii_hex[8]", 78, 8, SX_ID),
    SX_FIELD("rdevminor", "ascii_hex[8]", 86, 8, SX_ID),
    SX_FIELD("namesize", "ascii_hex[8]", 94, 8, SX_SIZE),
    SX_FIELD("check", "ascii_hex[8]", 102, 8, SX_SIGNATURE),
};
static const sx_layout sx_a_cpio_newc_header = { UINT32_C(0x60040001), "cpio_newc_header", sx_a_cpio_newc_header_fields, SX_COUNT(sx_a_cpio_newc_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cpio_odc_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("dev", "ascii_octal[6]", 6, 6, SX_ID),
    SX_FIELD("ino", "ascii_octal[6]", 12, 6, SX_ID),
    SX_FIELD("mode", "ascii_octal[6]", 18, 6, SX_FLAGS),
    SX_FIELD("uid", "ascii_octal[6]", 24, 6, SX_ID),
    SX_FIELD("gid", "ascii_octal[6]", 30, 6, SX_ID),
    SX_FIELD("nlink", "ascii_octal[6]", 36, 6, SX_COUNT_PROP),
    SX_FIELD("rdev", "ascii_octal[6]", 42, 6, SX_ID),
    SX_FIELD("mtime", "ascii_octal[11]", 48, 11, SX_TIME),
    SX_FIELD("namesize", "ascii_octal[6]", 59, 6, SX_SIZE),
    SX_FIELD("filesize", "ascii_octal[11]", 65, 11, SX_SIZE),
};
static const sx_layout sx_a_cpio_odc_header = { UINT32_C(0x60040002), "cpio_odc_header", sx_a_cpio_odc_header_fields, SX_COUNT(sx_a_cpio_odc_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cpio_afio_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("dev", "ascii_hex[8]", 6, 8, SX_ID),
    SX_FIELD("ino", "ascii_hex[16]", 14, 16, SX_ID),
    SX_FIELD("mode_marker", "char[1]", 30, 1, SX_SIGNATURE),
    SX_FIELD("mode", "ascii_octal[6]", 31, 6, SX_FLAGS),
    SX_FIELD("uid", "ascii_hex[8]", 37, 8, SX_ID),
    SX_FIELD("gid", "ascii_hex[8]", 45, 8, SX_ID),
    SX_FIELD("nlink", "ascii_hex[8]", 53, 8, SX_COUNT_PROP),
    SX_FIELD("rdev", "ascii_hex[8]", 61, 8, SX_ID),
    SX_FIELD("mtime", "ascii_hex[16]", 69, 16, SX_TIME),
    SX_FIELD("name_marker", "char[1]", 85, 1, SX_SIGNATURE),
    SX_FIELD("namesize", "ascii_hex[4]", 86, 4, SX_SIZE),
    SX_FIELD("flags", "ascii_hex[4]", 90, 4, SX_FLAGS),
    SX_FIELD("extended_header_size", "ascii_hex[4]", 94, 4, SX_SIZE),
    SX_FIELD("size_marker", "char[1]", 98, 1, SX_SIGNATURE),
    SX_FIELD("filesize", "ascii_hex[16]", 99, 16, SX_SIZE),
    SX_FIELD("header_end", "char[1]", 115, 1, SX_SIGNATURE),
};
static const sx_layout sx_a_cpio_afio_header = { UINT32_C(0x60040003), "cpio_afio_header", sx_a_cpio_afio_header_fields, SX_COUNT(sx_a_cpio_afio_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cpio_binary_le_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("dev", "uint16", 2, 2, SX_ID),
    SX_FIELD("ino", "uint16", 4, 2, SX_ID),
    SX_FIELD("mode", "uint16", 6, 2, SX_FLAGS),
    SX_FIELD("uid", "uint16", 8, 2, SX_ID),
    SX_FIELD("gid", "uint16", 10, 2, SX_ID),
    SX_FIELD("nlink", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("rdev", "uint16", 14, 2, SX_ID),
    SX_FIELD("mtime_high", "uint16", 16, 2, SX_NONE),
    SX_FIELD("mtime_low", "uint16", 18, 2, SX_NONE),
    SX_FIELD("namesize", "uint16", 20, 2, SX_SIZE),
    SX_FIELD("filesize_high", "uint16", 22, 2, SX_NONE),
    SX_FIELD("filesize_low", "uint16", 24, 2, SX_NONE),
};
static const sx_layout sx_a_cpio_binary_le_header = { UINT32_C(0x60040004), "cpio_binary_le_header", sx_a_cpio_binary_le_header_fields, SX_COUNT(sx_a_cpio_binary_le_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cpio_binary_be_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("dev", "uint16", 2, 2, SX_ID),
    SX_FIELD("ino", "uint16", 4, 2, SX_ID),
    SX_FIELD("mode", "uint16", 6, 2, SX_FLAGS),
    SX_FIELD("uid", "uint16", 8, 2, SX_ID),
    SX_FIELD("gid", "uint16", 10, 2, SX_ID),
    SX_FIELD("nlink", "uint16", 12, 2, SX_COUNT_PROP),
    SX_FIELD("rdev", "uint16", 14, 2, SX_ID),
    SX_FIELD("mtime_high", "uint16", 16, 2, SX_NONE),
    SX_FIELD("mtime_low", "uint16", 18, 2, SX_NONE),
    SX_FIELD("namesize", "uint16", 20, 2, SX_SIZE),
    SX_FIELD("filesize_high", "uint16", 22, 2, SX_NONE),
    SX_FIELD("filesize_low", "uint16", 24, 2, SX_NONE),
};
static const sx_layout sx_a_cpio_binary_be_header = { UINT32_C(0x60040005), "cpio_binary_be_header", sx_a_cpio_binary_be_header_fields, SX_COUNT(sx_a_cpio_binary_be_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_a_cpio_solaris_tl_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("payload_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_a_cpio_solaris_tl = { UINT32_C(0x60040006), "cpio_solaris_tl", sx_a_cpio_solaris_tl_fields, SX_COUNT(sx_a_cpio_solaris_tl_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cpio_solaris_tg_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("block_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("block_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_a_cpio_solaris_tg = { UINT32_C(0x60040007), "cpio_solaris_tg", sx_a_cpio_solaris_tg_fields, SX_COUNT(sx_a_cpio_solaris_tg_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cpio_solaris_block_fields[] = {
    SX_FIELD("uncompressed_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("compressed_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("offset", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sx_a_cpio_solaris_block = { UINT32_C(0x60040008), "cpio_solaris_block", sx_a_cpio_solaris_block_fields, SX_COUNT(sx_a_cpio_solaris_block_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cab_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("reserved1", "uint32", 4, 4, SX_RESERVED),
    SX_FIELD("cbCabinet", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("reserved2", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("coffFiles", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("reserved3", "uint32", 20, 4, SX_RESERVED),
    SX_FIELD("versionMinor", "uint8", 24, 1, SX_NONE),
    SX_FIELD("versionMajor", "uint8", 25, 1, SX_NONE),
    SX_FIELD("cFolders", "uint16", 26, 2, SX_COUNT_PROP),
    SX_FIELD("cFiles", "uint16", 28, 2, SX_COUNT_PROP),
    SX_FIELD("flags", "uint16", 30, 2, SX_FLAGS),
    SX_FIELD("setID", "uint16", 32, 2, SX_ID),
    SX_FIELD("iCabinet", "uint16", 34, 2, SX_ID),
};
static const sx_layout sx_a_cab_header = { UINT32_C(0x60040009), "cab_header", sx_a_cab_header_fields, SX_COUNT(sx_a_cab_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cab_reserve_sizes_fields[] = {
    SX_FIELD("cbCFHeader", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("cbCFFolder", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("cbCFData", "uint8", 3, 1, SX_SIZE),
};
static const sx_layout sx_a_cab_reserve_sizes = { UINT32_C(0x6004000A), "cab_reserve_sizes", sx_a_cab_reserve_sizes_fields, SX_COUNT(sx_a_cab_reserve_sizes_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cab_folder_fields[] = {
    SX_FIELD("coffCabStart", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("cCFData", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("typeCompress", "uint16", 6, 2, SX_FLAGS),
};
static const sx_layout sx_a_cab_folder = { UINT32_C(0x6004000B), "cab_folder", sx_a_cab_folder_fields, SX_COUNT(sx_a_cab_folder_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cab_file_fields[] = {
    SX_FIELD("cbFile", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("uoffFolderStart", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("iFolder", "uint16", 8, 2, SX_ID),
    SX_FIELD("date", "uint16", 10, 2, SX_TIME),
    SX_FIELD("time", "uint16", 12, 2, SX_TIME),
    SX_FIELD("attribs", "uint16", 14, 2, SX_FLAGS),
};
static const sx_layout sx_a_cab_file = { UINT32_C(0x6004000C), "cab_file", sx_a_cab_file_fields, SX_COUNT(sx_a_cab_file_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_cab_data_fields[] = {
    SX_FIELD("csum", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("cbData", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("cbUncomp", "uint16", 6, 2, SX_SIZE),
};
static const sx_layout sx_a_cab_data = { UINT32_C(0x6004000D), "cab_data", sx_a_cab_data_fields, SX_COUNT(sx_a_cab_data_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_skippable_frame_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_a_skippable_frame = { UINT32_C(0x6004000E), "skippable_frame", sx_a_skippable_frame_fields, SX_COUNT(sx_a_skippable_frame_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_lz4_frame_header_00_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("FLG", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("BD", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("header_checksum", "uint8", 6, 1, SX_CHECKSUM),
};
static const sx_layout sx_a_lz4_frame_header_00 = { UINT32_C(0x6004000F), "lz4_frame_header_00", sx_a_lz4_frame_header_00_fields, SX_COUNT(sx_a_lz4_frame_header_00_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_lz4_frame_header_01_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("FLG", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("BD", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
    SX_FIELD("header_checksum", "uint8", 10, 1, SX_CHECKSUM),
};
static const sx_layout sx_a_lz4_frame_header_01 = { UINT32_C(0x60040010), "lz4_frame_header_01", sx_a_lz4_frame_header_01_fields, SX_COUNT(sx_a_lz4_frame_header_01_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_lz4_frame_header_10_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("FLG", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("BD", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("content_size", "uint64", 6, 8, SX_SIZE),
    SX_FIELD("header_checksum", "uint8", 14, 1, SX_CHECKSUM),
};
static const sx_layout sx_a_lz4_frame_header_10 = { UINT32_C(0x60040011), "lz4_frame_header_10", sx_a_lz4_frame_header_10_fields, SX_COUNT(sx_a_lz4_frame_header_10_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_lz4_frame_header_11_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("FLG", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("BD", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("content_size", "uint64", 6, 8, SX_SIZE),
    SX_FIELD("dictionary_id", "uint32", 14, 4, SX_ID),
    SX_FIELD("header_checksum", "uint8", 18, 1, SX_CHECKSUM),
};
static const sx_layout sx_a_lz4_frame_header_11 = { UINT32_C(0x60040012), "lz4_frame_header_11", sx_a_lz4_frame_header_11_fields, SX_COUNT(sx_a_lz4_frame_header_11_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_lz4_block_header_fields[] = {
    SX_FIELD("size_and_uncompressed_flag", "uint32", 0, 4, SX_FLAGS),
};
static const sx_layout sx_a_lz4_block_header = { UINT32_C(0x60040013), "lz4_block_header", sx_a_lz4_block_header_fields, SX_COUNT(sx_a_lz4_block_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_checksum_le_fields[] = {
    SX_FIELD("checksum", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_a_checksum_le = { UINT32_C(0x60040014), "checksum_le", sx_a_checksum_le_fields, SX_COUNT(sx_a_checksum_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_checksum_be_fields[] = {
    SX_FIELD("checksum", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_a_checksum_be = { UINT32_C(0x60040015), "checksum_be", sx_a_checksum_be_fields, SX_COUNT(sx_a_checksum_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_a_lz4_legacy_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
};
static const sx_layout sx_a_lz4_legacy_header = { UINT32_C(0x60040016), "lz4_legacy_header", sx_a_lz4_legacy_header_fields, SX_COUNT(sx_a_lz4_legacy_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_000_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
};
static const sx_layout sx_a_zstd_frame_header_000 = { UINT32_C(0x60040017), "zstd_frame_header_000", sx_a_zstd_frame_header_000_fields, SX_COUNT(sx_a_zstd_frame_header_000_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_001_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("frame_content_size_encoded", "uint16", 6, 2, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_001 = { UINT32_C(0x60040018), "zstd_frame_header_001", sx_a_zstd_frame_header_001_fields, SX_COUNT(sx_a_zstd_frame_header_001_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_002_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint32", 6, 4, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_002 = { UINT32_C(0x60040019), "zstd_frame_header_002", sx_a_zstd_frame_header_002_fields, SX_COUNT(sx_a_zstd_frame_header_002_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_003_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint64", 6, 8, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_003 = { UINT32_C(0x6004001A), "zstd_frame_header_003", sx_a_zstd_frame_header_003_fields, SX_COUNT(sx_a_zstd_frame_header_003_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_010_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 6, 1, SX_ID),
};
static const sx_layout sx_a_zstd_frame_header_010 = { UINT32_C(0x6004001B), "zstd_frame_header_010", sx_a_zstd_frame_header_010_fields, SX_COUNT(sx_a_zstd_frame_header_010_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_011_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 6, 1, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 7, 2, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_011 = { UINT32_C(0x6004001C), "zstd_frame_header_011", sx_a_zstd_frame_header_011_fields, SX_COUNT(sx_a_zstd_frame_header_011_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_012_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 6, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 7, 4, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_012 = { UINT32_C(0x6004001D), "zstd_frame_header_012", sx_a_zstd_frame_header_012_fields, SX_COUNT(sx_a_zstd_frame_header_012_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_013_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 6, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 7, 8, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_013 = { UINT32_C(0x6004001E), "zstd_frame_header_013", sx_a_zstd_frame_header_013_fields, SX_COUNT(sx_a_zstd_frame_header_013_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_020_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 6, 2, SX_ID),
};
static const sx_layout sx_a_zstd_frame_header_020 = { UINT32_C(0x6004001F), "zstd_frame_header_020", sx_a_zstd_frame_header_020_fields, SX_COUNT(sx_a_zstd_frame_header_020_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_021_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 6, 2, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 8, 2, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_021 = { UINT32_C(0x60040020), "zstd_frame_header_021", sx_a_zstd_frame_header_021_fields, SX_COUNT(sx_a_zstd_frame_header_021_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_022_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 6, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_022 = { UINT32_C(0x60040021), "zstd_frame_header_022", sx_a_zstd_frame_header_022_fields, SX_COUNT(sx_a_zstd_frame_header_022_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_023_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 6, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 8, 8, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_023 = { UINT32_C(0x60040022), "zstd_frame_header_023", sx_a_zstd_frame_header_023_fields, SX_COUNT(sx_a_zstd_frame_header_023_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_030_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
};
static const sx_layout sx_a_zstd_frame_header_030 = { UINT32_C(0x60040023), "zstd_frame_header_030", sx_a_zstd_frame_header_030_fields, SX_COUNT(sx_a_zstd_frame_header_030_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_031_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 10, 2, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_031 = { UINT32_C(0x60040024), "zstd_frame_header_031", sx_a_zstd_frame_header_031_fields, SX_COUNT(sx_a_zstd_frame_header_031_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_032_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 10, 4, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_032 = { UINT32_C(0x60040025), "zstd_frame_header_032", sx_a_zstd_frame_header_032_fields, SX_COUNT(sx_a_zstd_frame_header_032_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_033_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 10, 8, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_033 = { UINT32_C(0x60040026), "zstd_frame_header_033", sx_a_zstd_frame_header_033_fields, SX_COUNT(sx_a_zstd_frame_header_033_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_100_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint8", 5, 1, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_100 = { UINT32_C(0x60040027), "zstd_frame_header_100", sx_a_zstd_frame_header_100_fields, SX_COUNT(sx_a_zstd_frame_header_100_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_101_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("frame_content_size_encoded", "uint16", 5, 2, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_101 = { UINT32_C(0x60040028), "zstd_frame_header_101", sx_a_zstd_frame_header_101_fields, SX_COUNT(sx_a_zstd_frame_header_101_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_102_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint32", 5, 4, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_102 = { UINT32_C(0x60040029), "zstd_frame_header_102", sx_a_zstd_frame_header_102_fields, SX_COUNT(sx_a_zstd_frame_header_102_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_103_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint64", 5, 8, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_103 = { UINT32_C(0x6004002A), "zstd_frame_header_103", sx_a_zstd_frame_header_103_fields, SX_COUNT(sx_a_zstd_frame_header_103_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_110_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 5, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint8", 6, 1, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_110 = { UINT32_C(0x6004002B), "zstd_frame_header_110", sx_a_zstd_frame_header_110_fields, SX_COUNT(sx_a_zstd_frame_header_110_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_111_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 5, 1, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 6, 2, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_111 = { UINT32_C(0x6004002C), "zstd_frame_header_111", sx_a_zstd_frame_header_111_fields, SX_COUNT(sx_a_zstd_frame_header_111_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_112_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 5, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 6, 4, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_112 = { UINT32_C(0x6004002D), "zstd_frame_header_112", sx_a_zstd_frame_header_112_fields, SX_COUNT(sx_a_zstd_frame_header_112_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_113_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 5, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 6, 8, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_113 = { UINT32_C(0x6004002E), "zstd_frame_header_113", sx_a_zstd_frame_header_113_fields, SX_COUNT(sx_a_zstd_frame_header_113_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_120_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 5, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint8", 7, 1, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_120 = { UINT32_C(0x6004002F), "zstd_frame_header_120", sx_a_zstd_frame_header_120_fields, SX_COUNT(sx_a_zstd_frame_header_120_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_121_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 5, 2, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 7, 2, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_121 = { UINT32_C(0x60040030), "zstd_frame_header_121", sx_a_zstd_frame_header_121_fields, SX_COUNT(sx_a_zstd_frame_header_121_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_122_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 5, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 7, 4, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_122 = { UINT32_C(0x60040031), "zstd_frame_header_122", sx_a_zstd_frame_header_122_fields, SX_COUNT(sx_a_zstd_frame_header_122_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_123_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 5, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 7, 8, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_123 = { UINT32_C(0x60040032), "zstd_frame_header_123", sx_a_zstd_frame_header_123_fields, SX_COUNT(sx_a_zstd_frame_header_123_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_130_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 5, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint8", 9, 1, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_130 = { UINT32_C(0x60040033), "zstd_frame_header_130", sx_a_zstd_frame_header_130_fields, SX_COUNT(sx_a_zstd_frame_header_130_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_131_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 5, 4, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 9, 2, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_131 = { UINT32_C(0x60040034), "zstd_frame_header_131", sx_a_zstd_frame_header_131_fields, SX_COUNT(sx_a_zstd_frame_header_131_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_132_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 5, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 9, 4, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_132 = { UINT32_C(0x60040035), "zstd_frame_header_132", sx_a_zstd_frame_header_132_fields, SX_COUNT(sx_a_zstd_frame_header_132_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_frame_header_133_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 5, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 9, 8, SX_SIZE),
};
static const sx_layout sx_a_zstd_frame_header_133 = { UINT32_C(0x60040036), "zstd_frame_header_133", sx_a_zstd_frame_header_133_fields, SX_COUNT(sx_a_zstd_frame_header_133_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_zstd_block_header_fields[] = {
    SX_FIELD("last_type_size", "uint24", 0, 3, SX_FLAGS),
};
static const sx_layout sx_a_zstd_block_header = { UINT32_C(0x60040037), "zstd_block_header", sx_a_zstd_block_header_fields, SX_COUNT(sx_a_zstd_block_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_lzip_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 4, 1, SX_NONE),
    SX_FIELD("dictionary_size_code", "uint8", 5, 1, SX_ID),
};
static const sx_layout sx_a_lzip_header = { UINT32_C(0x60040038), "lzip_header", sx_a_lzip_header_fields, SX_COUNT(sx_a_lzip_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_lzip_trailer_fields[] = {
    SX_FIELD("crc32", "uint32", 0, 4, SX_CHECKSUM),
    SX_FIELD("data_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("member_size", "uint64", 12, 8, SX_SIZE),
};
static const sx_layout sx_a_lzip_trailer = { UINT32_C(0x60040039), "lzip_trailer", sx_a_lzip_trailer_fields, SX_COUNT(sx_a_lzip_trailer_fields), SX_LE };

static const xx_data_struct_field_desc sx_a_lzop_header_00_fields[] = {
    SX_FIELD("magic", "bytes", 0, 9, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 9, 2, SX_NONE),
    SX_FIELD("library_version", "uint16", 11, 2, SX_NONE),
    SX_FIELD("method", "uint8", 13, 1, SX_ID),
    SX_FIELD("flags", "uint32", 14, 4, SX_FLAGS),
    SX_FIELD("mode", "uint32", 18, 4, SX_FLAGS),
    SX_FIELD("mtime_low", "uint32", 22, 4, SX_TIME),
    SX_FIELD("filename_length", "uint8", 26, 1, SX_SIZE),
};
static const sx_layout sx_a_lzop_header_00 = { UINT32_C(0x6004003A), "lzop_header_00", sx_a_lzop_header_00_fields, SX_COUNT(sx_a_lzop_header_00_fields), SX_BE };

static const xx_data_struct_field_desc sx_a_lzop_header_01_fields[] = {
    SX_FIELD("magic", "bytes", 0, 9, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 9, 2, SX_NONE),
    SX_FIELD("library_version", "uint16", 11, 2, SX_NONE),
    SX_FIELD("method", "uint8", 13, 1, SX_ID),
    SX_FIELD("flags", "uint32", 14, 4, SX_FLAGS),
    SX_FIELD("filter", "uint32", 18, 4, SX_ID),
    SX_FIELD("mode", "uint32", 22, 4, SX_FLAGS),
    SX_FIELD("mtime_low", "uint32", 26, 4, SX_TIME),
    SX_FIELD("filename_length", "uint8", 30, 1, SX_SIZE),
};
static const sx_layout sx_a_lzop_header_01 = { UINT32_C(0x6004003B), "lzop_header_01", sx_a_lzop_header_01_fields, SX_COUNT(sx_a_lzop_header_01_fields), SX_BE };

static const xx_data_struct_field_desc sx_a_lzop_header_10_fields[] = {
    SX_FIELD("magic", "bytes", 0, 9, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 9, 2, SX_NONE),
    SX_FIELD("library_version", "uint16", 11, 2, SX_NONE),
    SX_FIELD("version_needed", "uint16", 13, 2, SX_NONE),
    SX_FIELD("method", "uint8", 15, 1, SX_ID),
    SX_FIELD("level", "uint8", 16, 1, SX_NONE),
    SX_FIELD("flags", "uint32", 17, 4, SX_FLAGS),
    SX_FIELD("mode", "uint32", 21, 4, SX_FLAGS),
    SX_FIELD("mtime_low", "uint32", 25, 4, SX_NONE),
    SX_FIELD("mtime_high", "uint32", 29, 4, SX_NONE),
    SX_FIELD("filename_length", "uint8", 33, 1, SX_SIZE),
};
static const sx_layout sx_a_lzop_header_10 = { UINT32_C(0x6004003C), "lzop_header_10", sx_a_lzop_header_10_fields, SX_COUNT(sx_a_lzop_header_10_fields), SX_BE };

static const xx_data_struct_field_desc sx_a_lzop_header_11_fields[] = {
    SX_FIELD("magic", "bytes", 0, 9, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 9, 2, SX_NONE),
    SX_FIELD("library_version", "uint16", 11, 2, SX_NONE),
    SX_FIELD("version_needed", "uint16", 13, 2, SX_NONE),
    SX_FIELD("method", "uint8", 15, 1, SX_ID),
    SX_FIELD("level", "uint8", 16, 1, SX_NONE),
    SX_FIELD("flags", "uint32", 17, 4, SX_FLAGS),
    SX_FIELD("filter", "uint32", 21, 4, SX_ID),
    SX_FIELD("mode", "uint32", 25, 4, SX_FLAGS),
    SX_FIELD("mtime_low", "uint32", 29, 4, SX_NONE),
    SX_FIELD("mtime_high", "uint32", 33, 4, SX_NONE),
    SX_FIELD("filename_length", "uint8", 37, 1, SX_SIZE),
};
static const sx_layout sx_a_lzop_header_11 = { UINT32_C(0x6004003D), "lzop_header_11", sx_a_lzop_header_11_fields, SX_COUNT(sx_a_lzop_header_11_fields), SX_BE };

static const xx_data_struct_field_desc sx_a_lzop_block_sizes_fields[] = {
    SX_FIELD("uncompressed_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("compressed_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_a_lzop_block_sizes = { UINT32_C(0x6004003E), "lzop_block_sizes", sx_a_lzop_block_sizes_fields, SX_COUNT(sx_a_lzop_block_sizes_fields), SX_BE };

static const xx_data_struct_field_desc sx_a_lzop_end_fields[] = {
    SX_FIELD("uncompressed_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_a_lzop_end = { UINT32_C(0x6004003F), "lzop_end", sx_a_lzop_end_fields, SX_COUNT(sx_a_lzop_end_fields), SX_BE };

static const xx_data_struct_field_desc sx_a_lzop_extra_size_fields[] = {
    SX_FIELD("extra_field_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_a_lzop_extra_size = { UINT32_C(0x60040040), "lzop_extra_size", sx_a_lzop_extra_size_fields, SX_COUNT(sx_a_lzop_extra_size_fields), SX_BE };

static const sx_layout *const sx_archive_layouts[] = {
    &sx_a_cpio_newc_header,
    &sx_a_cpio_odc_header,
    &sx_a_cpio_afio_header,
    &sx_a_cpio_binary_le_header,
    &sx_a_cpio_binary_be_header,
    &sx_a_cpio_solaris_tl,
    &sx_a_cpio_solaris_tg,
    &sx_a_cpio_solaris_block,
    &sx_a_cab_header,
    &sx_a_cab_reserve_sizes,
    &sx_a_cab_folder,
    &sx_a_cab_file,
    &sx_a_cab_data,
    &sx_a_skippable_frame,
    &sx_a_lz4_frame_header_00,
    &sx_a_lz4_frame_header_01,
    &sx_a_lz4_frame_header_10,
    &sx_a_lz4_frame_header_11,
    &sx_a_lz4_block_header,
    &sx_a_checksum_le,
    &sx_a_checksum_be,
    &sx_a_lz4_legacy_header,
    &sx_a_zstd_frame_header_000,
    &sx_a_zstd_frame_header_001,
    &sx_a_zstd_frame_header_002,
    &sx_a_zstd_frame_header_003,
    &sx_a_zstd_frame_header_010,
    &sx_a_zstd_frame_header_011,
    &sx_a_zstd_frame_header_012,
    &sx_a_zstd_frame_header_013,
    &sx_a_zstd_frame_header_020,
    &sx_a_zstd_frame_header_021,
    &sx_a_zstd_frame_header_022,
    &sx_a_zstd_frame_header_023,
    &sx_a_zstd_frame_header_030,
    &sx_a_zstd_frame_header_031,
    &sx_a_zstd_frame_header_032,
    &sx_a_zstd_frame_header_033,
    &sx_a_zstd_frame_header_100,
    &sx_a_zstd_frame_header_101,
    &sx_a_zstd_frame_header_102,
    &sx_a_zstd_frame_header_103,
    &sx_a_zstd_frame_header_110,
    &sx_a_zstd_frame_header_111,
    &sx_a_zstd_frame_header_112,
    &sx_a_zstd_frame_header_113,
    &sx_a_zstd_frame_header_120,
    &sx_a_zstd_frame_header_121,
    &sx_a_zstd_frame_header_122,
    &sx_a_zstd_frame_header_123,
    &sx_a_zstd_frame_header_130,
    &sx_a_zstd_frame_header_131,
    &sx_a_zstd_frame_header_132,
    &sx_a_zstd_frame_header_133,
    &sx_a_zstd_block_header,
    &sx_a_lzip_header,
    &sx_a_lzip_trailer,
    &sx_a_lzop_header_00,
    &sx_a_lzop_header_01,
    &sx_a_lzop_header_10,
    &sx_a_lzop_header_11,
    &sx_a_lzop_block_sizes,
    &sx_a_lzop_end,
    &sx_a_lzop_extra_size,
};

static bool sx_a_ascii_number(const uint8_t *s,size_t n,unsigned base,uint64_t *out)
{
    uint64_t v=0;
    for(size_t i=0;i<n;i++){
        unsigned d=s[i]>='0'&&s[i]<='9'?s[i]-'0':s[i]>='a'&&s[i]<='f'?s[i]-'a'+10:s[i]>='A'&&s[i]<='F'?s[i]-'A'+10:UINT_MAX;
        if(d>=base||v>(UINT64_MAX-d)/base)return false;
        v=v*base+d;
    }
    *out=v;return true;
}
static bool sx_a_raw_advance(sx_context *c,int64_t *at,uint64_t size)
{
    if(*at<0||*at>c->size||size>(uint64_t)(c->size-*at))return false;
    if(!sx_raw(c,*at,(int64_t)size))return false;
    *at+=(int64_t)size;return true;
}
static bool sx_a_cstring(sx_context *c,int64_t *at,int64_t end)
{
    int64_t start=*at;uint8_t b;
    if(start<0||end>c->size)return false;
    while(*at<end){if(!sx_read(c,*at,&b,1))return false;(*at)++;if(!b)return sx_raw(c,start,*at-start);}
    return false;
}
static bool sx_a_cpio_solaris(sx_context *c)
{
    int64_t at=0;
    while(at<c->size){
        uint8_t h[12];uint32_t payload,blocks;
        if(!sx_read(c,at,h,8)||xx_rt_memcmp(h,"\x19\x9eTL",4))return false;
        payload=xx_data_get_u32(h,8,4,false);
        if(!sx_add(c,&sx_a_cpio_solaris_tl,at,8))return false;
        at+=8;if(!sx_a_raw_advance(c,&at,504))return false;
        int64_t tg=at;
        if(payload<12||payload>(uint64_t)(c->size-at)||!sx_read(c,at,h,12)||xx_rt_memcmp(h,"\x19\x9eTG",4))return false;
        blocks=xx_data_get_u32(h,12,4,false);
        if(blocks>(payload-12U)/12U||!sx_add(c,&sx_a_cpio_solaris_tg,at,12)||!sx_table(c,&sx_a_cpio_solaris_block,at+12,12,blocks))return false;
        for(uint32_t i=0;i<blocks;i++){
            uint32_t packed,offset;
            if(!sx_u32(c,tg+12+(int64_t)i*12+4,false,&packed)||!sx_u32(c,tg+12+(int64_t)i*12+8,false,&offset)||offset>payload||packed>payload-offset||!sx_raw(c,tg+offset,packed))return false;
        }
        at=tg+payload;
        uint64_t padding=(512U-(uint64_t)at%512U)%512U;
        if(!sx_a_raw_advance(c,&at,padding))return false;
        if(at<c->size){uint8_t b;if(!sx_read(c,at,&b,1))return false;if(!b)return sx_raw(c,at,c->size-at);}
    }
    return true;
}
static bool sx_a_cpio(sx_context *c)
{
    int64_t at=0;uint8_t h[116];
    if(!sx_read(c,0,h,6))return false;
    if(!xx_rt_memcmp(h,"\x19\x9eTL",4))return sx_a_cpio_solaris(c);
    while(at<c->size){
        const sx_layout *l;int64_t hs;uint64_t namesize,size,extra=0;unsigned alignment=1;
        if(!sx_read(c,at,h,6))return false;
        if(!xx_rt_memcmp(h,"070701",6)||!xx_rt_memcmp(h,"070702",6)){
            l=&sx_a_cpio_newc_header;hs=110;alignment=4;
            if(!sx_read(c,at,h,(size_t)hs)||!sx_a_ascii_number(h+94,8,16,&namesize)||!sx_a_ascii_number(h+54,8,16,&size))return false;
        }else if(!xx_rt_memcmp(h,"070707",6)){
            l=&sx_a_cpio_odc_header;hs=76;
            if(!sx_read(c,at,h,(size_t)hs)||!sx_a_ascii_number(h+59,6,8,&namesize)||!sx_a_ascii_number(h+65,11,8,&size))return false;
        }else if(!xx_rt_memcmp(h,"070727",6)){
            l=&sx_a_cpio_afio_header;hs=116;
            if(!sx_read(c,at,h,(size_t)hs)||h[30]!='m'||h[85]!='n'||h[98]!='s'||h[115]!=':'||!sx_a_ascii_number(h+86,4,16,&namesize)||!sx_a_ascii_number(h+94,4,16,&extra)||!sx_a_ascii_number(h+99,16,16,&size))return false;
        }else{
            bool be=h[0]==0x71&&h[1]==0xc7;
            if(!be&&!(h[0]==0xc7&&h[1]==0x71))return false;
            l=be?&sx_a_cpio_binary_be_header:&sx_a_cpio_binary_le_header;hs=26;alignment=2;
            if(!sx_read(c,at,h,(size_t)hs))return false;
            namesize=xx_data_get_u16(h,26,20,be);
            size=((uint64_t)xx_data_get_u16(h,26,22,be)<<16)|xx_data_get_u16(h,26,24,be);
        }
        if(!namesize||namesize>65536||!sx_add(c,l,at,hs))return false;
        at+=hs;int64_t name_at=at;uint8_t last;
        if(!sx_a_raw_advance(c,&at,namesize)||!sx_read(c,at-1,&last,1)||last!=0)return false;
        if(!sx_a_raw_advance(c,&at,(alignment-(uint64_t)at%alignment)%alignment))return false;
        bool trailer=false;
        if(namesize==11){uint8_t name[11];if(!sx_read(c,name_at,name,11))return false;trailer=!xx_rt_memcmp(name,"TRAILER!!!",11);}
        if(!sx_a_raw_advance(c,&at,extra)||!sx_a_raw_advance(c,&at,size)||!sx_a_raw_advance(c,&at,(alignment-(uint64_t)at%alignment)%alignment))return false;
        if(trailer)return sx_raw(c,at,c->size-at);
    }
    return false;
}
static bool sx_a_cab(sx_context *c)
{
    uint8_t h[36],r[4]={0};uint32_t end,files;uint16_t flags,folders,count;int64_t at=36,folder_at;
    if(!sx_read(c,0,h,36)||xx_rt_memcmp(h,"MSCF",4))return false;
    end=xx_data_get_u32(h,36,8,false);files=xx_data_get_u32(h,36,16,false);
    folders=xx_data_get_u16(h,36,26,false);count=xx_data_get_u16(h,36,28,false);flags=xx_data_get_u16(h,36,30,false);
    if(end<36||end>(uint64_t)c->size||files>end||(flags&~7U)||!sx_add(c,&sx_a_cab_header,0,36))return false;
    if(flags&4){if(!sx_read(c,at,r,4)||!sx_add(c,&sx_a_cab_reserve_sizes,at,4))return false;at+=4;if(!sx_a_raw_advance(c,&at,xx_data_get_u16(r,4,0,false)))return false;}
    if(flags&1)if(!sx_a_cstring(c,&at,end)||!sx_a_cstring(c,&at,end))return false;
    if(flags&2)if(!sx_a_cstring(c,&at,end)||!sx_a_cstring(c,&at,end))return false;
    folder_at=at;
    for(uint16_t i=0;i<folders;i++){
        if(at>end||8U+r[2]>(uint64_t)(end-at)||!sx_add(c,&sx_a_cab_folder,at,8))return false;
        at+=8;if(!sx_a_raw_advance(c,&at,r[2]))return false;
    }
    at=files;
    for(uint16_t i=0;i<count;i++){
        if(at>end||end-at<16||!sx_add(c,&sx_a_cab_file,at,16))return false;
        at+=16;if(!sx_a_cstring(c,&at,end))return false;
    }
    for(uint16_t i=0;i<folders;i++){
        uint32_t data;uint16_t blocks;
        int64_t fo=folder_at+(int64_t)i*(8+r[2]);
        if(!sx_u32(c,fo,false,&data)||!sx_u16(c,fo+4,false,&blocks))return false;
        at=data;
        for(uint16_t j=0;j<blocks;j++){
            uint16_t packed;
            if(at>end||8U+r[3]>(uint64_t)(end-at)||!sx_u16(c,at+4,false,&packed)||!sx_add(c,&sx_a_cab_data,at,8))return false;
            at+=8;if(!sx_a_raw_advance(c,&at,r[3])||packed>(uint64_t)(end-at)||!sx_a_raw_advance(c,&at,packed))return false;
        }
    }
    return sx_raw(c,end,c->size-end);
}
static bool sx_a_skippable(sx_context *c,int64_t *at)
{
    uint32_t size;
    if(!sx_u32(c,*at+4,false,&size)||!sx_add(c,&sx_a_skippable_frame,*at,8))return false;
    *at+=8;return sx_a_raw_advance(c,at,size);
}
static bool sx_a_lz4(sx_context *c)
{
    int64_t at=0;
    while(at<c->size){
        uint32_t magic;uint8_t h[6];
        if(!sx_u32(c,at,false,&magic))return false;
        if((magic&0xfffffff0U)==0x184d2a50U){if(!sx_a_skippable(c,&at))return false;continue;}
        bool legacy=magic==0x184c2102U;uint8_t flags=0;
        if(legacy){if(!sx_add(c,&sx_a_lz4_legacy_header,at,4))return false;at+=4;}
        else{
            const sx_layout *l;
            if(magic!=0x184d2204U||!sx_read(c,at,h,6)||(h[4]>>6)!=1||(h[4]&2)||(h[5]&0x8f)||((h[5]>>4)&7)<4)return false;
            flags=h[4];bool content=(flags&8)!=0,dictionary=(flags&1)!=0;
            l=content?(dictionary?&sx_a_lz4_frame_header_11:&sx_a_lz4_frame_header_10):(dictionary?&sx_a_lz4_frame_header_01:&sx_a_lz4_frame_header_00);
            int64_t size=7+(content?8:0)+(dictionary?4:0);
            if(!sx_add(c,l,at,size))return false;at+=size;
        }
        for(;;){
            uint32_t block;
            if(legacy&&at==c->size)return true;
            if(!sx_u32(c,at,false,&block)||!sx_add(c,&sx_a_lz4_block_header,at,4))return false;
            at+=4;if(!block)break;
            uint32_t size=legacy?block:block&0x7fffffffU;
            if(!size||size>8U*1024U*1024U||!sx_a_raw_advance(c,&at,size))return false;
            if(flags&16){if(!sx_add(c,&sx_a_checksum_le,at,4))return false;at+=4;}
        }
        if(flags&4){if(!sx_add(c,&sx_a_checksum_le,at,4))return false;at+=4;}
    }
    return true;
}
static bool sx_a_zstd(sx_context *c)
{
    static const sx_layout *const variants[2][4][4]={
        {
            {&sx_a_zstd_frame_header_000,&sx_a_zstd_frame_header_001,&sx_a_zstd_frame_header_002,&sx_a_zstd_frame_header_003},
            {&sx_a_zstd_frame_header_010,&sx_a_zstd_frame_header_011,&sx_a_zstd_frame_header_012,&sx_a_zstd_frame_header_013},
            {&sx_a_zstd_frame_header_020,&sx_a_zstd_frame_header_021,&sx_a_zstd_frame_header_022,&sx_a_zstd_frame_header_023},
            {&sx_a_zstd_frame_header_030,&sx_a_zstd_frame_header_031,&sx_a_zstd_frame_header_032,&sx_a_zstd_frame_header_033},
        },
        {
            {&sx_a_zstd_frame_header_100,&sx_a_zstd_frame_header_101,&sx_a_zstd_frame_header_102,&sx_a_zstd_frame_header_103},
            {&sx_a_zstd_frame_header_110,&sx_a_zstd_frame_header_111,&sx_a_zstd_frame_header_112,&sx_a_zstd_frame_header_113},
            {&sx_a_zstd_frame_header_120,&sx_a_zstd_frame_header_121,&sx_a_zstd_frame_header_122,&sx_a_zstd_frame_header_123},
            {&sx_a_zstd_frame_header_130,&sx_a_zstd_frame_header_131,&sx_a_zstd_frame_header_132,&sx_a_zstd_frame_header_133},
        },
    };
    int64_t at=0;
    while(at<c->size){
        uint32_t magic;uint8_t d;
        if(!sx_u32(c,at,false,&magic))return false;
        if((magic&0xfffffff0U)==0x184d2a50U){if(!sx_a_skippable(c,&at))return false;continue;}
        if(magic!=0xfd2fb528U||!sx_read(c,at+4,&d,1)||(d&0x18))return false;
        unsigned single=(d>>5)&1,dict=d&3,content=d>>6;
        static const unsigned dictsize[]={0,1,2,4};
        unsigned cs=content==0?single:content==1?2:content==2?4:8;
        int64_t size=5+!single+dictsize[dict]+cs;
        if(!sx_add(c,variants[single][dict][content],at,size))return false;at+=size;
        for(;;){
            uint8_t h[3];uint32_t block,kind,packed;
            if(!sx_read(c,at,h,3)||!sx_add(c,&sx_a_zstd_block_header,at,3))return false;
            block=xx_data_get_u24(h,3,0,false);kind=(block>>1)&3;packed=kind==1?1:block>>3;
            if(kind==3||(block>>3)>131072)return false;
            at+=3;if(!sx_a_raw_advance(c,&at,packed))return false;
            if(block&1)break;
        }
        if(d&4){if(!sx_add(c,&sx_a_checksum_le,at,4))return false;at+=4;}
    }
    return true;
}
static bool sx_a_lzip(sx_context *c)
{
    uint8_t h[6];int64_t end=c->size;
    if(!sx_read(c,0,h,6)||xx_rt_memcmp(h,"LZIP",4)||h[4]>1)return false;
    /* v0 has no encoded member size; expose its known header only. */
    if(h[4]==0)return sx_add(c,&sx_a_lzip_header,0,6)&&sx_raw(c,6,c->size-6);
    if(c->f->format_size>0&&c->f->format_size<c->size)end=c->f->format_size;
    if(!sx_raw(c,end,c->size-end))return false;
    while(end>0){
        uint64_t member;
        if(end<26||!sx_u64(c,end-8,false,&member)||member<26||member>(uint64_t)end)return false;
        int64_t start=end-(int64_t)member;
        if(!sx_read(c,start,h,6)||xx_rt_memcmp(h,"LZIP",4)||h[4]!=1||!sx_add(c,&sx_a_lzip_header,start,6)||
           !sx_raw(c,start+6,end-20-start-6)||!sx_add(c,&sx_a_lzip_trailer,end-20,20))return false;
        end=start;
    }
    return true;
}
static bool sx_a_lzop(sx_context *c)
{
    static const uint8_t magic[9]={0x89,'L','Z','O',0,13,10,26,10};
    int64_t at=0;
    while(at<c->size){
        uint8_t h[17],namelen;uint16_t version;uint32_t flags;const sx_layout *l;
        if(!sx_read(c,at,h,13)||xx_rt_memcmp(h,magic,9))return false;
        version=xx_data_get_u16(h,13,9,true);bool longheader=version>=0x0940;
        int64_t flag_at=at+(longheader?17:14);
        if(version<0x0900||!sx_u32(c,flag_at,true,&flags)||(flags&~0xfff03fffU))return false;
        bool filter=(flags&0x800)!=0;
        l=longheader?(filter?&sx_a_lzop_header_11:&sx_a_lzop_header_10):(filter?&sx_a_lzop_header_01:&sx_a_lzop_header_00);
        int64_t header_size=(longheader?34:27)+(filter?4:0);
        if(!sx_add(c,l,at,header_size)||!sx_read(c,at+header_size-1,&namelen,1))return false;
        at+=header_size;
        if(!sx_a_raw_advance(c,&at,namelen)||!sx_add(c,&sx_a_checksum_be,at,4))return false;at+=4;
        if(flags&0x40){
            uint32_t extra;if(!sx_u32(c,at,true,&extra)||!sx_add(c,&sx_a_lzop_extra_size,at,4))return false;at+=4;
            if(!sx_a_raw_advance(c,&at,extra)||!sx_add(c,&sx_a_checksum_be,at,4))return false;at+=4;
        }
        for(;;){
            uint32_t plain,packed;
            if(!sx_u32(c,at,true,&plain))return false;
            if(!plain){if(!sx_add(c,&sx_a_lzop_end,at,4))return false;at+=4;break;}
            if(!sx_u32(c,at+4,true,&packed)||!packed||packed>plain||!sx_add(c,&sx_a_lzop_block_sizes,at,8))return false;at+=8;
            unsigned sums=((flags&1)!=0)+((flags&0x100)!=0)+(packed<plain?((flags&2)!=0)+((flags&0x200)!=0):0);
            for(unsigned i=0;i<sums;i++){if(!sx_add(c,&sx_a_checksum_be,at,4))return false;at+=4;}
            if(!sx_a_raw_advance(c,&at,packed))return false;
        }
    }
    return true;
}
static bool sx_archive_supports(xx_file_type_t t)
{
    return t==XX_FILE_TYPE_CPIO||t==XX_FILE_TYPE_CAB||t==XX_FILE_TYPE_LZ4||t==XX_FILE_TYPE_ZSTD||t==XX_FILE_TYPE_LZIP||t==XX_FILE_TYPE_LZOP;
}
static bool sx_archive_build(sx_context *c)
{
    switch(c->f->file_type){
        case XX_FILE_TYPE_CPIO:return sx_a_cpio(c);
        case XX_FILE_TYPE_CAB:return sx_a_cab(c);
        case XX_FILE_TYPE_LZ4:return sx_a_lz4(c);
        case XX_FILE_TYPE_ZSTD:return sx_a_zstd(c);
        case XX_FILE_TYPE_LZIP:return sx_a_lzip(c);
        case XX_FILE_TYPE_LZOP:return sx_a_lzop(c);
        default:return false;
    }
}
static bool sx_archive_comment(xx_data_struct_record *r,uint32_t id)
{
    const wchar_t *s=NULL;uint64_t v;
    if(!r||!r->name||id<UINT32_C(0x60040001)||id>UINT32_C(0x6004ffff))return true;
    v=xx_var_get_u64(&r->value);
    if(id==sx_a_cpio_binary_le_header.id||id==sx_a_cpio_binary_be_header.id){
        if(!xx_rt_wcscmp(r->name,L"filesize_high"))s=L"High 16 bits of the 32-bit file size";
        else if(!xx_rt_wcscmp(r->name,L"filesize_low"))s=L"Low 16 bits of the 32-bit file size";
        else if(!xx_rt_wcscmp(r->name,L"mtime_high"))s=L"High 16 bits of the 32-bit modification time";
        else if(!xx_rt_wcscmp(r->name,L"mtime_low"))s=L"Low 16 bits of the 32-bit modification time";
    }else if(id==sx_a_cab_folder.id&&!xx_rt_wcscmp(r->name,L"typeCompress")){
        switch(v&15){case 0:s=L"CAB_COMP_NONE";break;case 1:s=L"CAB_COMP_MSZIP";break;case 2:s=L"CAB_COMP_QUANTUM";break;case 3:s=L"CAB_COMP_LZX";break;}
    }else if(id==sx_a_cab_header.id&&!xx_rt_wcscmp(r->name,L"flags")){
        static const wchar_t *const names[]={L"0",L"CAB_FLAG_PREV",L"CAB_FLAG_NEXT",L"CAB_FLAG_PREV|CAB_FLAG_NEXT",L"CAB_FLAG_RESERVE",L"CAB_FLAG_PREV|CAB_FLAG_RESERVE",L"CAB_FLAG_NEXT|CAB_FLAG_RESERVE",L"CAB_FLAG_PREV|CAB_FLAG_NEXT|CAB_FLAG_RESERVE"};
        if(v<8)s=names[v];
    }else if(!xx_rt_wcscmp(r->name,L"frame_content_size_encoded"))s=L"Decoded content size is this value + 256";
    else if(id==sx_a_zstd_block_header.id){
        static const wchar_t *const names[]={L"Raw block",L"RLE block",L"Compressed block",L"Reserved"};s=names[(v>>1)&3];
    }else if(id==sx_a_lz4_block_header.id)s=v==0?L"End mark":(v&0x80000000U)?L"Uncompressed block; low 31 bits are size":L"Compressed block size";
    else if((id==sx_a_lzop_header_10.id||id==sx_a_lzop_header_11.id)&&!xx_rt_wcscmp(r->name,L"mtime_low"))s=L"Low 32 bits of the 64-bit modification time";
    else if((id==sx_a_lzop_header_10.id||id==sx_a_lzop_header_11.id)&&!xx_rt_wcscmp(r->name,L"mtime_high"))s=L"High 32 bits of the 64-bit modification time";
    else if(!xx_rt_wcscmp(r->name,L"method")&&(id==sx_a_lzop_header_00.id||id==sx_a_lzop_header_01.id||id==sx_a_lzop_header_10.id||id==sx_a_lzop_header_11.id))s=v==1?L"LZO1X-1":v==2?L"LZO1X-1(15)":v==3?L"LZO1X-999":NULL;
    return !s||xx_data_struct_record_set_comment(r,s);
}
