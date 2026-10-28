/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy archive, codec, executable and catalog metadata.
 * Encoded payloads, bit trees and unparsed extensions remain RAW_DATA.
 */
static const xx_data_struct_field_desc sxl_szdd_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("method", "uint8", 8, 1, SX_ID),
    SX_FIELD("missing_filename_character", "char[1]", 9, 1, SX_STRING),
    SX_FIELD("original_size", "uint32", 10, 4, SX_SIZE),
};
static const sx_layout sxl_szdd_header = { UINT32_C(0x600A0001), "szdd_header", sxl_szdd_header_fields, SX_COUNT(sxl_szdd_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_sz_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 7, SX_SIGNATURE),
    SX_FIELD("volume_marker", "uint8", 7, 1, SX_ID),
    SX_FIELD("original_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sxl_sz_header = { UINT32_C(0x600A0002), "sz_header", sxl_sz_header_fields, SX_COUNT(sxl_sz_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_imd5_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("content_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("reserved", "bytes", 8, 8, SX_RESERVED),
    SX_FIELD("md5", "bytes", 16, 16, SX_CHECKSUM),
};
static const sx_layout sxl_imd5_header = { UINT32_C(0x600A0003), "imd5_header", sxl_imd5_header_fields, SX_COUNT(sxl_imd5_header_fields), SX_BE };

static const xx_data_struct_field_desc sxl_wii_lz77_tag_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
};
static const sx_layout sxl_wii_lz77_tag = { UINT32_C(0x600A0004), "wii_lz77_tag", sxl_wii_lz77_tag_fields, SX_COUNT(sxl_wii_lz77_tag_fields), SX_LE };

static const xx_data_struct_field_desc sxl_wii_lz77_header_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("original_size", "uint24", 1, 3, SX_SIZE),
};
static const sx_layout sxl_wii_lz77_header = { UINT32_C(0x600A0005), "wii_lz77_header", sxl_wii_lz77_header_fields, SX_COUNT(sxl_wii_lz77_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_wii_lz77_extended_size_fields[] = {
    SX_FIELD("original_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sxl_wii_lz77_extended_size = { UINT32_C(0x600A0006), "wii_lz77_extended_size", sxl_wii_lz77_extended_size_fields, SX_COUNT(sxl_wii_lz77_extended_size_fields), SX_LE };

static const xx_data_struct_field_desc sxl_ash0_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("size_word_top_byte", "uint8", 4, 1, SX_NONE),
    SX_FIELD("original_size", "uint24", 5, 3, SX_SIZE),
    SX_FIELD("distance_stream_offset", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sxl_ash0_header = { UINT32_C(0x600A0007), "ash0_header", sxl_ash0_header_fields, SX_COUNT(sxl_ash0_header_fields), SX_BE };

static const xx_data_struct_field_desc sxl_lzv1_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("format_marker", "bytes", 4, 6, SX_SIGNATURE),
    SX_FIELD("maximum_codes", "uint16", 10, 2, SX_COUNT_PROP),
};
static const sx_layout sxl_lzv1_header = { UINT32_C(0x600A0008), "lzv1_header", sxl_lzv1_header_fields, SX_COUNT(sxl_lzv1_header_fields), SX_BE };

static const xx_data_struct_field_desc sxl_oracle_squeeze_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("original_size", "uint32", 2, 4, SX_SIZE),
    SX_FIELD("checksum", "uint16", 6, 2, SX_CHECKSUM),
};
static const sx_layout sxl_oracle_squeeze_header = { UINT32_C(0x600A0009), "oracle_squeeze_header", sxl_oracle_squeeze_header_fields, SX_COUNT(sxl_oracle_squeeze_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_squeeze_tree_header_fields[] = {
    SX_FIELD("node_count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sxl_squeeze_tree_header = { UINT32_C(0x600A000A), "squeeze_tree_header", sxl_squeeze_tree_header_fields, SX_COUNT(sxl_squeeze_tree_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_squeeze_tree_node_fields[] = {
    SX_FIELD("zero_child", "int16", 0, 2, SX_NONE),
    SX_FIELD("one_child", "int16", 2, 2, SX_NONE),
};
static const sx_layout sxl_squeeze_tree_node = { UINT32_C(0x600A000B), "squeeze_tree_node", sxl_squeeze_tree_node_fields, SX_COUNT(sxl_squeeze_tree_node_fields), SX_LE };

static const xx_data_struct_field_desc sxl_filename_byte_fields[] = {
    SX_FIELD("character", "char[1]", 0, 1, SX_STRING),
};
static const sx_layout sxl_filename_byte = { UINT32_C(0x600A000C), "filename_byte", sxl_filename_byte_fields, SX_COUNT(sxl_filename_byte_fields), SX_LE };

static const xx_data_struct_field_desc sxl_softronics_header_fields[] = {
    SX_FIELD("header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("signature", "bytes", 2, 40, SX_SIGNATURE),
    SX_FIELD("packed_size", "uint32", 42, 4, SX_SIZE),
};
static const sx_layout sxl_softronics_header = { UINT32_C(0x600A000D), "softronics_header", sxl_softronics_header_fields, SX_COUNT(sxl_softronics_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_softronics_metadata_fields[] = {
    SX_FIELD("original_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("dos_time", "uint16", 4, 2, SX_NONE),
    SX_FIELD("dos_date", "uint16", 6, 2, SX_NONE),
};
static const sx_layout sxl_softronics_metadata = { UINT32_C(0x600A000E), "softronics_metadata", sxl_softronics_metadata_fields, SX_COUNT(sxl_softronics_metadata_fields), SX_LE };

static const xx_data_struct_field_desc sxl_logitech_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 2, SX_SIGNATURE),
    SX_FIELD("missing_filename_character", "char[1]", 2, 1, SX_STRING),
    SX_FIELD("unknown", "uint8", 3, 1, SX_NONE),
    SX_FIELD("original_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxl_logitech_header = { UINT32_C(0x600A000F), "logitech_header", sxl_logitech_header_fields, SX_COUNT(sxl_logitech_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_dma_packed_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("filename", "char[14]", 4, 14, SX_STRING),
    SX_FIELD("original_size", "uint32", 18, 4, SX_SIZE),
    SX_FIELD("dos_date", "uint16", 22, 2, SX_NONE),
    SX_FIELD("dos_time", "uint16", 24, 2, SX_NONE),
    SX_FIELD("pack_tag", "bytes", 26, 6, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 32, 2, SX_NONE),
};
static const sx_layout sxl_dma_packed_header = { UINT32_C(0x600A0010), "dma_packed_header", sxl_dma_packed_header_fields, SX_COUNT(sxl_dma_packed_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_dcl_header_fields[] = {
    SX_FIELD("literal_coding", "uint8", 0, 1, SX_ID),
    SX_FIELD("dictionary_bits", "uint8", 1, 1, SX_NONE),
};
static const sx_layout sxl_dcl_header = { UINT32_C(0x600A0011), "dcl_header", sxl_dcl_header_fields, SX_COUNT(sxl_dcl_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_gas_huff_header_fields[] = {
    SX_FIELD("original_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("node_count_minus_one", "uint16", 4, 2, SX_NONE),
    SX_FIELD("root_index", "uint16", 6, 2, SX_ID),
};
static const sx_layout sxl_gas_huff_header = { UINT32_C(0x600A0012), "gas_huff_header", sxl_gas_huff_header_fields, SX_COUNT(sxl_gas_huff_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_huf_header_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("member_count", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("symbol_count", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("directory_offset", "uint32", 6, 4, SX_OFFSET),
};
static const sx_layout sxl_huf_header = { UINT32_C(0x600A0013), "huf_header", sxl_huf_header_fields, SX_COUNT(sxl_huf_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_huf_symbol_fields[] = {
    SX_FIELD("symbol", "uint8", 0, 1, SX_NONE),
};
static const sx_layout sxl_huf_symbol = { UINT32_C(0x600A0014), "huf_symbol", sxl_huf_symbol_fields, SX_COUNT(sxl_huf_symbol_fields), SX_LE };

static const xx_data_struct_field_desc sxl_huf_directory_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("original_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("data_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("flags", "uint8", 12, 1, SX_FLAGS),
};
static const sx_layout sxl_huf_directory = { UINT32_C(0x600A0015), "huf_directory", sxl_huf_directory_fields, SX_COUNT(sxl_huf_directory_fields), SX_LE };

static const xx_data_struct_field_desc sxl_lzdiet_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 6, SX_SIGNATURE),
    SX_FIELD("original_size", "uint32", 6, 4, SX_SIZE),
};
static const sx_layout sxl_lzdiet_header = { UINT32_C(0x600A0016), "lzdiet_header", sxl_lzdiet_header_fields, SX_COUNT(sxl_lzdiet_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_lzdiet_chunk_fields[] = {
    SX_FIELD("data_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("packed_size", "uint16", 4, 2, SX_SIZE),
};
static const sx_layout sxl_lzdiet_chunk = { UINT32_C(0x600A0017), "lzdiet_chunk", sxl_lzdiet_chunk_fields, SX_COUNT(sxl_lzdiet_chunk_fields), SX_LE };

static const xx_data_struct_field_desc sxl_lzdiet_table_end_fields[] = {
    SX_FIELD("end_marker", "uint32", 0, 4, SX_SIGNATURE),
};
static const sx_layout sxl_lzdiet_table_end = { UINT32_C(0x600A0018), "lzdiet_table_end", sxl_lzdiet_table_end_fields, SX_COUNT(sxl_lzdiet_table_end_fields), SX_LE };

static const xx_data_struct_field_desc sxl_lzpis2_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 6, SX_SIGNATURE),
};
static const sx_layout sxl_lzpis2_header = { UINT32_C(0x600A0019), "lzpis2_header", sxl_lzpis2_header_fields, SX_COUNT(sxl_lzpis2_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_lzpis2_chunk_fields[] = {
    SX_FIELD("original_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("packed_size", "uint16", 2, 2, SX_SIZE),
};
static const sx_layout sxl_lzpis2_chunk = { UINT32_C(0x600A001A), "lzpis2_chunk", sxl_lzpis2_chunk_fields, SX_COUNT(sxl_lzpis2_chunk_fields), SX_LE };

static const xx_data_struct_field_desc sxl_legacy_frame_header_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("block_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("content_size", "uint64", 6, 8, SX_SIZE),
    SX_FIELD("header_checksum", "uint8", 14, 1, SX_CHECKSUM),
};
static const sx_layout sxl_legacy_frame_header = { UINT32_C(0x600A001B), "legacy_frame_header", sxl_legacy_frame_header_fields, SX_COUNT(sxl_legacy_frame_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_legacy_frame_block_fields[] = {
    SX_FIELD("size_and_flags", "uint32", 0, 4, SX_FLAGS),
};
static const sx_layout sxl_legacy_frame_block = { UINT32_C(0x600A001C), "legacy_frame_block", sxl_legacy_frame_block_fields, SX_COUNT(sxl_legacy_frame_block_fields), SX_LE };

static const xx_data_struct_field_desc sxl_legacy_frame_skip_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("content_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sxl_legacy_frame_skip = { UINT32_C(0x600A001D), "legacy_frame_skip", sxl_legacy_frame_skip_fields, SX_COUNT(sxl_legacy_frame_skip_fields), SX_LE };

static const xx_data_struct_field_desc sxl_legacy_frame_checksum_fields[] = {
    SX_FIELD("xxhash32", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sxl_legacy_frame_checksum = { UINT32_C(0x600A001E), "legacy_frame_checksum", sxl_legacy_frame_checksum_fields, SX_COUNT(sxl_legacy_frame_checksum_fields), SX_LE };

static const xx_data_struct_field_desc sxl_bullfrog_tag_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
};
static const sx_layout sxl_bullfrog_tag = { UINT32_C(0x600A001F), "bullfrog_tag", sxl_bullfrog_tag_fields, SX_COUNT(sxl_bullfrog_tag_fields), SX_BE };

static const xx_data_struct_field_desc sxl_rnc_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 3, SX_SIGNATURE),
    SX_FIELD("method", "uint8", 3, 1, SX_ID),
    SX_FIELD("original_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("packed_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("original_crc16", "uint16", 12, 2, SX_CHECKSUM),
    SX_FIELD("packed_crc16", "uint16", 14, 2, SX_CHECKSUM),
    SX_FIELD("leeway", "uint8", 16, 1, SX_SIZE),
    SX_FIELD("chunk_count", "uint8", 17, 1, SX_COUNT_PROP),
};
static const sx_layout sxl_rnc_header = { UINT32_C(0x600A0020), "rnc_header", sxl_rnc_header_fields, SX_COUNT(sxl_rnc_header_fields), SX_BE };

static const xx_data_struct_field_desc sxl_mo_header_le_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("revision", "uint32", 4, 4, SX_NONE),
    SX_FIELD("string_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("originals_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("translations_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("hash_count", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("hash_offset", "uint32", 24, 4, SX_OFFSET),
};
static const sx_layout sxl_mo_header_le = { UINT32_C(0x600A0021), "mo_header_le", sxl_mo_header_le_fields, SX_COUNT(sxl_mo_header_le_fields), SX_LE };

static const xx_data_struct_field_desc sxl_mo_string_le_fields[] = {
    SX_FIELD("string_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("string_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sxl_mo_string_le = { UINT32_C(0x600A0022), "mo_string_le", sxl_mo_string_le_fields, SX_COUNT(sxl_mo_string_le_fields), SX_LE };

static const xx_data_struct_field_desc sxl_mo_hash_le_fields[] = {
    SX_FIELD("string_index", "uint32", 0, 4, SX_ID),
};
static const sx_layout sxl_mo_hash_le = { UINT32_C(0x600A0023), "mo_hash_le", sxl_mo_hash_le_fields, SX_COUNT(sxl_mo_hash_le_fields), SX_LE };

static const xx_data_struct_field_desc sxl_mo_header_be_fields[] = {
    SX_FIELD("signature", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("revision", "uint32", 4, 4, SX_NONE),
    SX_FIELD("string_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("originals_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("translations_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("hash_count", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("hash_offset", "uint32", 24, 4, SX_OFFSET),
};
static const sx_layout sxl_mo_header_be = { UINT32_C(0x600A0024), "mo_header_be", sxl_mo_header_be_fields, SX_COUNT(sxl_mo_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sxl_mo_string_be_fields[] = {
    SX_FIELD("string_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("string_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sxl_mo_string_be = { UINT32_C(0x600A0025), "mo_string_be", sxl_mo_string_be_fields, SX_COUNT(sxl_mo_string_be_fields), SX_BE };

static const xx_data_struct_field_desc sxl_mo_hash_be_fields[] = {
    SX_FIELD("string_index", "uint32", 0, 4, SX_ID),
};
static const sx_layout sxl_mo_hash_be = { UINT32_C(0x600A0026), "mo_hash_be", sxl_mo_hash_be_fields, SX_COUNT(sxl_mo_hash_be_fields), SX_BE };

static const xx_data_struct_field_desc sxl_qm_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 16, SX_SIGNATURE),
};
static const sx_layout sxl_qm_header = { UINT32_C(0x600A0027), "qm_header", sxl_qm_header_fields, SX_COUNT(sxl_qm_header_fields), SX_BE };

static const xx_data_struct_field_desc sxl_qm_block_fields[] = {
    SX_FIELD("tag", "uint8", 0, 1, SX_ID),
    SX_FIELD("content_size", "uint32", 1, 4, SX_SIZE),
};
static const sx_layout sxl_qm_block = { UINT32_C(0x600A0028), "qm_block", sxl_qm_block_fields, SX_COUNT(sxl_qm_block_fields), SX_BE };

static const xx_data_struct_field_desc sxl_qm_hash_fields[] = {
    SX_FIELD("hash", "uint32", 0, 4, SX_ID),
    SX_FIELD("message_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sxl_qm_hash = { UINT32_C(0x600A0029), "qm_hash", sxl_qm_hash_fields, SX_COUNT(sxl_qm_hash_fields), SX_BE };

static const xx_data_struct_field_desc sxl_qm_message_field_fields[] = {
    SX_FIELD("tag", "uint8", 0, 1, SX_ID),
    SX_FIELD("content_size", "uint32", 1, 4, SX_SIZE),
};
static const sx_layout sxl_qm_message_field = { UINT32_C(0x600A002A), "qm_message_field", sxl_qm_message_field_fields, SX_COUNT(sxl_qm_message_field_fields), SX_BE };

static const xx_data_struct_field_desc sxl_qm_message_end_fields[] = {
    SX_FIELD("tag", "uint8", 0, 1, SX_ID),
};
static const sx_layout sxl_qm_message_end = { UINT32_C(0x600A002B), "qm_message_end", sxl_qm_message_end_fields, SX_COUNT(sxl_qm_message_end_fields), SX_BE };

static const xx_data_struct_field_desc sxl_qm_message_obsolete_fields[] = {
    SX_FIELD("tag", "uint8", 0, 1, SX_ID),
    SX_FIELD("obsolete_value", "uint32", 1, 4, SX_NONE),
};
static const sx_layout sxl_qm_message_obsolete = { UINT32_C(0x600A002C), "qm_message_obsolete", sxl_qm_message_obsolete_fields, SX_COUNT(sxl_qm_message_obsolete_fields), SX_BE };

static const xx_data_struct_field_desc sxl_atarist_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("text_size", "uint32", 2, 4, SX_SIZE),
    SX_FIELD("data_size", "uint32", 6, 4, SX_SIZE),
    SX_FIELD("bss_size", "uint32", 10, 4, SX_SIZE),
    SX_FIELD("symbol_size", "uint32", 14, 4, SX_SIZE),
    SX_FIELD("reserved", "uint32", 18, 4, SX_RESERVED),
    SX_FIELD("flags", "uint32", 22, 4, SX_FLAGS),
    SX_FIELD("absolute_flag", "uint16", 26, 2, SX_FLAGS),
};
static const sx_layout sxl_atarist_header = { UINT32_C(0x600A002D), "atarist_header", sxl_atarist_header_fields, SX_COUNT(sxl_atarist_header_fields), SX_BE };

static const xx_data_struct_field_desc sxl_atarist_symbol_fields[] = {
    SX_FIELD("name", "char[8]", 0, 8, SX_STRING),
    SX_FIELD("type", "uint16", 8, 2, SX_FLAGS),
    SX_FIELD("value", "uint32", 10, 4, SX_NONE),
};
static const sx_layout sxl_atarist_symbol = { UINT32_C(0x600A002E), "atarist_symbol", sxl_atarist_symbol_fields, SX_COUNT(sxl_atarist_symbol_fields), SX_BE };

static const xx_data_struct_field_desc sxl_pef_header_fields[] = {
    SX_FIELD("tag1", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("tag2", "bytes", 4, 4, SX_SIGNATURE),
    SX_FIELD("architecture", "char[4]", 8, 4, SX_ID),
    SX_FIELD("format_version", "uint32", 12, 4, SX_NONE),
    SX_FIELD("created_mac_epoch", "uint32", 16, 4, SX_NONE),
    SX_FIELD("old_definition_version", "uint32", 20, 4, SX_NONE),
    SX_FIELD("old_implementation_version", "uint32", 24, 4, SX_NONE),
    SX_FIELD("current_version", "uint32", 28, 4, SX_NONE),
    SX_FIELD("section_count", "uint16", 32, 2, SX_COUNT_PROP),
    SX_FIELD("instantiated_count", "uint16", 34, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint32", 36, 4, SX_RESERVED),
};
static const sx_layout sxl_pef_header = { UINT32_C(0x600A002F), "pef_header", sxl_pef_header_fields, SX_COUNT(sxl_pef_header_fields), SX_BE };

static const xx_data_struct_field_desc sxl_pef_section_fields[] = {
    SX_FIELD("name_offset", "int32", 0, 4, SX_OFFSET),
    SX_FIELD("default_address", "uint32", 4, 4, SX_ADDRESS),
    SX_FIELD("total_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("unpacked_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("packed_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("container_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("section_kind", "uint8", 24, 1, SX_ID),
    SX_FIELD("share_kind", "uint8", 25, 1, SX_ID),
    SX_FIELD("alignment", "uint8", 26, 1, SX_NONE),
    SX_FIELD("reserved", "uint8", 27, 1, SX_RESERVED),
};
static const sx_layout sxl_pef_section = { UINT32_C(0x600A0030), "pef_section", sxl_pef_section_fields, SX_COUNT(sxl_pef_section_fields), SX_BE };

static const xx_data_struct_field_desc sxl_pef_loader_fields[] = {
    SX_FIELD("main_section", "int32", 0, 4, SX_ID),
    SX_FIELD("main_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("init_section", "int32", 8, 4, SX_ID),
    SX_FIELD("init_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("term_section", "int32", 16, 4, SX_ID),
    SX_FIELD("term_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("imported_library_count", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("imported_symbol_count", "uint32", 28, 4, SX_COUNT_PROP),
    SX_FIELD("relocation_section_count", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("relocation_offset", "uint32", 36, 4, SX_OFFSET),
    SX_FIELD("strings_offset", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("export_hash_offset", "uint32", 44, 4, SX_OFFSET),
    SX_FIELD("export_hash_power", "uint32", 48, 4, SX_NONE),
    SX_FIELD("exported_symbol_count", "uint32", 52, 4, SX_COUNT_PROP),
};
static const sx_layout sxl_pef_loader = { UINT32_C(0x600A0031), "pef_loader", sxl_pef_loader_fields, SX_COUNT(sxl_pef_loader_fields), SX_BE };

static const xx_data_struct_field_desc sxl_artipack_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 8, 2, SX_NONE),
    SX_FIELD("member_count", "uint16", 10, 2, SX_COUNT_PROP),
    SX_FIELD("directory_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("unknown", "bytes", 16, 16, SX_NONE),
};
static const sx_layout sxl_artipack_header = { UINT32_C(0x600A0032), "artipack_header", sxl_artipack_header_fields, SX_COUNT(sxl_artipack_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_artipack_directory_fields[] = {
    SX_FIELD("filename", "char[13]", 0, 13, SX_STRING),
    SX_FIELD("unknown", "uint8", 13, 1, SX_NONE),
    SX_FIELD("data_offset", "uint32", 14, 4, SX_OFFSET),
    SX_FIELD("original_size", "uint32", 18, 4, SX_SIZE),
    SX_FIELD("packed_size", "uint32", 22, 4, SX_SIZE),
    SX_FIELD("dos_date", "uint16", 26, 2, SX_NONE),
    SX_FIELD("dos_time", "uint16", 28, 2, SX_NONE),
    SX_FIELD("unknown_tail", "bytes", 30, 4, SX_NONE),
};
static const sx_layout sxl_artipack_directory = { UINT32_C(0x600A0033), "artipack_directory", sxl_artipack_directory_fields, SX_COUNT(sxl_artipack_directory_fields), SX_LE };

static const xx_data_struct_field_desc sxl_artipack_size_fields[] = {
    SX_FIELD("original_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sxl_artipack_size = { UINT32_C(0x600A0034), "artipack_size", sxl_artipack_size_fields, SX_COUNT(sxl_artipack_size_fields), SX_LE };

static const xx_data_struct_field_desc sxl_arcfs_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("directory_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("data_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("minimum_read_version", "uint32", 16, 4, SX_NONE),
    SX_FIELD("minimum_write_version", "uint32", 20, 4, SX_NONE),
    SX_FIELD("unknown_24", "uint32", 24, 4, SX_NONE),
    SX_FIELD("reserved", "bytes", 28, 68, SX_RESERVED),
};
static const sx_layout sxl_arcfs_header = { UINT32_C(0x600A0035), "arcfs_header", sxl_arcfs_header_fields, SX_COUNT(sxl_arcfs_header_fields), SX_LE };

static const xx_data_struct_field_desc sxl_arcfs_directory_fields[] = {
    SX_FIELD("method", "uint8", 0, 1, SX_ID),
    SX_FIELD("filename", "char[11]", 1, 11, SX_STRING),
    SX_FIELD("original_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("load_address", "uint32", 16, 4, SX_NONE),
    SX_FIELD("execution_address", "uint32", 20, 4, SX_NONE),
    SX_FIELD("attributes", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("packed_size", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("offset_and_flags", "uint32", 32, 4, SX_FLAGS),
};
static const sx_layout sxl_arcfs_directory = { UINT32_C(0x600A0036), "arcfs_directory", sxl_arcfs_directory_fields, SX_COUNT(sxl_arcfs_directory_fields), SX_LE };

static const sx_layout *const sx_legacy_layouts[] = {
    &sxl_szdd_header,
    &sxl_sz_header,
    &sxl_imd5_header,
    &sxl_wii_lz77_tag,
    &sxl_wii_lz77_header,
    &sxl_wii_lz77_extended_size,
    &sxl_ash0_header,
    &sxl_lzv1_header,
    &sxl_oracle_squeeze_header,
    &sxl_squeeze_tree_header,
    &sxl_squeeze_tree_node,
    &sxl_filename_byte,
    &sxl_softronics_header,
    &sxl_softronics_metadata,
    &sxl_logitech_header,
    &sxl_dma_packed_header,
    &sxl_dcl_header,
    &sxl_gas_huff_header,
    &sxl_huf_header,
    &sxl_huf_symbol,
    &sxl_huf_directory,
    &sxl_lzdiet_header,
    &sxl_lzdiet_chunk,
    &sxl_lzdiet_table_end,
    &sxl_lzpis2_header,
    &sxl_lzpis2_chunk,
    &sxl_legacy_frame_header,
    &sxl_legacy_frame_block,
    &sxl_legacy_frame_skip,
    &sxl_legacy_frame_checksum,
    &sxl_bullfrog_tag,
    &sxl_rnc_header,
    &sxl_mo_header_le,
    &sxl_mo_string_le,
    &sxl_mo_hash_le,
    &sxl_mo_header_be,
    &sxl_mo_string_be,
    &sxl_mo_hash_be,
    &sxl_qm_header,
    &sxl_qm_block,
    &sxl_qm_hash,
    &sxl_qm_message_field,
    &sxl_qm_message_end,
    &sxl_qm_message_obsolete,
    &sxl_atarist_header,
    &sxl_atarist_symbol,
    &sxl_pef_header,
    &sxl_pef_section,
    &sxl_pef_loader,
    &sxl_artipack_header,
    &sxl_artipack_directory,
    &sxl_artipack_size,
    &sxl_arcfs_header,
    &sxl_arcfs_directory,
};
/* All positions are relative to the selected format. Members which encode
 * bits, indexes or logarithms retain those units rather than byte-size roles. */
static bool sxl_span(sx_context *c,uint64_t o,uint64_t n){return o<=(uint64_t)c->size&&n<=(uint64_t)c->size-o;}
static bool sxl_sig(sx_context *c,int64_t o,const char *s,size_t n){uint8_t b[64];return n<=sizeof(b)&&sx_read(c,o,b,n)&&!xx_rt_memcmp(b,s,n);}
static bool sxl_byte(sx_context *c,int64_t o,uint8_t *v){return sx_read(c,o,v,1);}
static bool sxl_name(sx_context *c,int64_t off,int64_t limit,int64_t *next){int64_t at=off;uint8_t b;while(at<limit){if(!sxl_byte(c,at++,&b))return false;if(!b){*next=at;return sx_table(c,&sxl_filename_byte,off,1,(uint64_t)(at-off));}}return false;}
static bool sxl_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;
    for(size_t gap=n/2;gap;gap/=2)for(size_t i=gap;i<n;i++){xx_data_struct item=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=item;}
    for(size_t i=0;i<n;i++){int64_t off=c->items[i].offset-c->f->base_address,total=c->items[i].total_size;if(off<end||!sxl_span(c,(uint64_t)off,(uint64_t)total)||!sx_raw(c,end,off-end))return false;end=off+total;}
    if(!sx_raw(c,end,c->size-end))return false;
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){xx_data_struct item=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=item;}
    return true;
}
static bool sxl_wii(sx_context *c)
{
    int64_t at=0;uint8_t h[4];uint32_t n;
    if(!sx_read(c,0,h,4))return false;
    if(!xx_rt_memcmp(h,"IMD5",4)){if(!sx_add(c,&sxl_imd5_header,0,32))return false;at=32;if(!sxl_sig(c,at,"LZ77",4))return false;}
    if(!sx_read(c,at,h,4))return false;
    if(!xx_rt_memcmp(h,"LZ77",4)){if(!sx_add(c,&sxl_wii_lz77_tag,at,4))return false;at+=4;if(!sx_read(c,at,h,4))return false;}
    if((h[0]!=0x10&&h[0]!=0x11)||!sx_add(c,&sxl_wii_lz77_header,at,4))return false;
    at+=4;n=(uint32_t)h[1]|((uint32_t)h[2]<<8)|((uint32_t)h[3]<<16);
    if(!n){if(!sx_u32(c,at,false,&n)||!sx_add(c,&sxl_wii_lz77_extended_size,at,4))return false;at+=4;}
    return n>0&&sxl_span(c,(uint64_t)at,2);
}
static bool sxl_squeeze(sx_context *c)
{
    int64_t at;uint16_t nodes;uint32_t n;
    if(!sxl_sig(c,0,"\x76\xff",2)||!sx_u32(c,2,false,&n)||!n||!sx_add(c,&sxl_oracle_squeeze_header,0,8)||!sxl_name(c,8,c->size<264?c->size:264,&at)||!sx_u16(c,at,false,&nodes)||!nodes||nodes>256)return false;
    if(!sx_add(c,&sxl_squeeze_tree_header,at,2)||!sx_table(c,&sxl_squeeze_tree_node,at+2,4,nodes)||!sxl_span(c,at+2+(uint64_t)nodes*4,1))return false;
    for(uint16_t i=0;i<nodes*2;i++){uint16_t v;if(!sx_u16(c,at+2+(int64_t)i*2,false,&v))return false;int32_t x=(v&0x8000)?(int32_t)v-65536:(int32_t)v;if(x>=nodes||x < -257)return false;}
    return true;
}
static bool sxl_softronics(sx_context *c)
{
    int64_t at;uint8_t size;uint32_t packed,n;
    if(!sxl_byte(c,0,&size)||!sxl_sig(c,1,"\0",1)||!sxl_sig(c,2,"Softronics Compressed File\0Version 2.00\0",40)||!sx_u32(c,42,false,&packed)||!packed||!sx_add(c,&sxl_softronics_header,0,46)||!sxl_name(c,46,c->size<59?c->size:59,&at)||at+8!=size||!sx_u32(c,at,false,&n)||!n||!sx_add(c,&sxl_softronics_metadata,at,8))return false;
    return sxl_span(c,size,packed)&&(uint64_t)size+packed==(uint64_t)c->size;
}
static bool sxl_dcl(sx_context *c,bool dma)
{
    int64_t at=dma?34:8;uint8_t h[2];uint32_t n;
    if(dma){if(!sxl_sig(c,0,"dm\x10\x11",4)||!sxl_sig(c,26,"PAKPAK\0\x2a",8)||!sx_u32(c,18,false,&n)||!sx_add(c,&sxl_dma_packed_header,0,34))return false;}
    else if(!sxl_sig(c,0,"\xda\xfa",2)||!sx_u32(c,4,false,&n)||!sx_add(c,&sxl_logitech_header,0,8))return false;
    return n&&sx_read(c,at,h,2)&&h[0]<=1&&h[1]>=4&&h[1]<=6&&sx_add(c,&sxl_dcl_header,at,2)&&sxl_span(c,at+2,1);
}
static bool sxl_huf(sx_context *c)
{
    uint16_t count,symbols;uint32_t dir;
    if(!sxl_sig(c,0,"\xbd\x01",2)||!sx_u16(c,2,false,&count)||!count||!sx_u16(c,4,false,&symbols)||!symbols||symbols>256||!sx_u32(c,6,false,&dir)||dir<=10U+symbols||!sx_add(c,&sxl_huf_header,0,10)||!sx_table(c,&sxl_huf_symbol,10,1,symbols)||!sx_table(c,&sxl_huf_directory,dir,13,count))return false;
    for(uint16_t i=0;i<count;i++){uint32_t name,data;int64_t at=dir+(int64_t)i*13;if(!sx_u32(c,at,false,&name)||!sx_u32(c,at+8,false,&data)||name<dir+(uint64_t)count*13||data<dir+(uint64_t)count*13||!sxl_span(c,name,1)||!sxl_span(c,data,1))return false;}
    return true;
}
static bool sxl_diet(sx_context *c)
{
    uint32_t n;uint64_t previous=0x5fc;bool any=false;
    if(!sxl_sig(c,0,"lZdIeT",6)||!sxl_span(c,0,0x5fc)||!sx_u32(c,6,false,&n)||!n||n>0x40000000U||!sx_add(c,&sxl_lzdiet_header,0,10))return false;
    for(unsigned i=0;i<250;i++){uint32_t off;uint16_t size;int64_t at=32+(int64_t)i*6;if(!sx_u32(c,at,false,&off)||!sx_u16(c,at+4,false,&size))return false;
        if(off==UINT32_MAX)return any&&sx_add(c,&sxl_lzdiet_table_end,at,4);
        if(off<previous||size<6||!sxl_span(c,off,size)||!sx_add(c,&sxl_lzdiet_chunk,at,6))return false;
        previous=(uint64_t)off+size;any=true;
    }return any;
}
static bool sxl_pis(sx_context *c)
{
    int64_t at=6;uint64_t total=0;
    if(!sxl_sig(c,0,"LZPIS2",6)||!sx_add(c,&sxl_lzpis2_header,0,6)||at==c->size)return false;
    while(at<c->size){uint16_t n,z;if(!sx_u16(c,at,false,&n)||!sx_u16(c,at+2,false,&z)||!n||n>4096||!z||!sxl_span(c,at+4,z)||!sx_add(c,&sxl_lzpis2_chunk,at,4))return false;total+=n;if(total>UINT64_C(0x40000000))return false;at+=4+z;}return true;
}
static bool sxl_frame(sx_context *c,uint32_t expected)
{
    int64_t at=0;bool any=false;
    while(at<c->size){uint32_t magic,n;uint8_t h[2];uint64_t maximum;
        if(!sx_u32(c,at,false,&magic))return false;
        if((magic&0xfffffff0U)==0x184d2a50U){if(!sx_u32(c,at+4,false,&n)||!sxl_span(c,at+8,n)||!sx_add(c,&sxl_legacy_frame_skip,at,8))return false;at+=8+(int64_t)n;continue;}
        if(magic!=expected||!sx_read(c,at+4,h,2)||(h[0]>>6)!=1||(h[0]&3)||!(h[0]&8)||(h[1]&0x8f)||(h[1]>>4)<4||(h[1]>>4)>7||!sx_add(c,&sxl_legacy_frame_header,at,15))return false;
        maximum=UINT64_C(1)<<(8+2*(h[1]>>4));at+=15;any=true;
        for(;;){if(!sx_u32(c,at,false,&n)||!sx_add(c,&sxl_legacy_frame_block,at,4))return false;at+=4;if(!n)break;uint32_t size=n&0x7fffffffU;if(!size||size>maximum||!sxl_span(c,at,size))return false;at+=size;if(h[0]&16){if(!sx_add(c,&sxl_legacy_frame_checksum,at,4))return false;at+=4;}}
        if(h[0]&4){if(!sx_add(c,&sxl_legacy_frame_checksum,at,4))return false;at+=4;}
    }return any;
}
static bool sxl_rnc(sx_context *c)
{
    int64_t at=0;uint8_t h[4];uint32_t packed,n;
    if(!sx_read(c,0,h,4))return false;if(!xx_rt_memcmp(h,"BULL",4)){if(!sxl_sig(c,0,"BULLFROG",8)||!sx_add(c,&sxl_bullfrog_tag,0,8))return false;at=8;}
    return sx_read(c,at,h,4)&&!xx_rt_memcmp(h,"RNC",3)&&(h[3]==1||h[3]==2)&&sx_u32(c,at+4,true,&n)&&n&&sx_u32(c,at+8,true,&packed)&&packed&&sxl_span(c,at+18,packed)&&sx_add(c,&sxl_rnc_header,at,18);
}
static bool sxl_mo(sx_context *c)
{
    uint32_t magic,rev,count,a,b,hc,ho;bool be;
    if(!sx_u32(c,0,false,&magic)||(magic!=0x950412deU&&magic!=0xde120495U))return false;be=magic==0xde120495U;
    if(!sx_u32(c,4,be,&rev)||(rev>>16)||!sx_u32(c,8,be,&count)||count>1000000||!sx_u32(c,12,be,&a)||!sx_u32(c,16,be,&b)||!sx_u32(c,20,be,&hc)||!sx_u32(c,24,be,&ho)||!sxl_span(c,a,(uint64_t)count*8)||!sxl_span(c,b,(uint64_t)count*8)||(hc&&!sxl_span(c,ho,(uint64_t)hc*4)))return false;
    if(!sx_add(c,be?&sxl_mo_header_be:&sxl_mo_header_le,0,28)||!sx_table(c,be?&sxl_mo_string_be:&sxl_mo_string_le,a,8,count)||!sx_table(c,be?&sxl_mo_string_be:&sxl_mo_string_le,b,8,count)||!sx_table(c,be?&sxl_mo_hash_be:&sxl_mo_hash_le,ho,4,hc))return false;
    for(unsigned table=0;table<2;table++)for(uint32_t i=0;i<count;i++){uint32_t size,off;uint8_t z;int64_t at=(table?b:a)+(int64_t)i*8;if(!sx_u32(c,at,be,&size)||!sx_u32(c,at+4,be,&off)||!sxl_span(c,off,(uint64_t)size+1)||!sxl_byte(c,(int64_t)off+size,&z)||z)return false;}
    for(uint32_t i=0;i<hc;i++){uint32_t v;if(!sx_u32(c,(int64_t)ho+(int64_t)i*4,be,&v)||v>count)return false;}return true;
}
static bool sxl_qm(sx_context *c)
{
    int64_t at=16,hash_at=-1,message_at=-1;uint32_t hash_size=0,message_size=0;
    if(!sxl_sig(c,0,"\x3c\xb8\x64\x18\xca\xef\x9c\x95\xcd\x21\x1c\xbf\x60\xa1\xbd\xdd",16)||!sx_add(c,&sxl_qm_header,0,16))return false;
    while(at<c->size){uint8_t tag;uint32_t size;if(!sxl_byte(c,at,&tag)||!tag||!sx_u32(c,at+1,true,&size)||!sxl_span(c,at+5,size)||!sx_add(c,&sxl_qm_block,at,5))return false;at+=5;
        if(tag==0x42){if(hash_at>=0||size%8||!sx_table(c,&sxl_qm_hash,at,8,size/8))return false;hash_at=at;hash_size=size;}
        else if(tag==0x69){if(message_at>=0)return false;message_at=at;message_size=size;int64_t p=at,end=at+size;
            while(p<end){uint8_t field;uint32_t length;if(!sxl_byte(c,p,&field))return false;if(field==1){if(!sx_add(c,&sxl_qm_message_end,p++,1))return false;continue;}
                if(end-p<5||!sx_u32(c,p+1,true,&length)||!sx_add(c,field==5?&sxl_qm_message_obsolete:&sxl_qm_message_field,p,5))return false;p+=5;if(field==5)continue;if(length==UINT32_MAX)length=0;if(length>(uint64_t)(end-p))return false;p+=length;
            }
        }at+=size;
    }
    if(hash_size&&message_at<0)return false;
    for(uint32_t i=0;i<hash_size/8;i++){uint32_t off;if(!sx_u32(c,hash_at+(int64_t)i*8+4,true,&off)||off>=message_size)return false;}
    return true;
}
static bool sxl_atari(sx_context *c)
{
    uint32_t text,data,symbols;uint64_t off;
    if(!sxl_sig(c,0,"\x60\x1a",2)||!sx_u32(c,2,true,&text)||!sx_u32(c,6,true,&data)||!sx_u32(c,14,true,&symbols)||!sx_add(c,&sxl_atarist_header,0,28))return false;
    off=28+(uint64_t)text+data;if(!sxl_span(c,28,(uint64_t)text+data)||!sxl_span(c,off,symbols))return false;
    /* Basic DRI flags occupy the upper type byte. Other symbol encodings
     * and extended-name records remain raw rather than being misframed. */
    if(symbols%14)return true;
    for(uint32_t i=0;i<symbols/14;i++){uint16_t type;if(!sx_u16(c,(int64_t)off+(int64_t)i*14+8,true,&type))return false;if(type&0xff)return true;}
    return sx_table(c,&sxl_atarist_symbol,(int64_t)off,14,symbols/14);
}
static bool sxl_pef(sx_context *c)
{
    uint16_t count,inst;uint32_t arch,version;unsigned loaders=0;
    if(!sxl_sig(c,0,"Joy!peff",8)||!sx_u32(c,8,true,&arch)||(arch!=0x70777063&&arch!=0x6d36386b)||!sx_u32(c,12,true,&version)||version>1||!sx_u16(c,32,true,&count)||!count||count>4096||!sx_u16(c,34,true,&inst)||inst>count||!sx_add(c,&sxl_pef_header,0,40)||!sx_table(c,&sxl_pef_section,40,28,count))return false;
    for(uint16_t i=0;i<count;i++){int64_t at=40+(int64_t)i*28;uint32_t packed,off;uint8_t kind,align,reserved;if(!sx_u32(c,at+16,true,&packed)||!sx_u32(c,at+20,true,&off)||!sxl_byte(c,at+24,&kind)||kind>8||!sxl_byte(c,at+26,&align)||align>31||!sxl_byte(c,at+27,&reserved)||reserved||(packed&&(off<40+(uint64_t)count*28||!sxl_span(c,off,packed))))return false;
        if(kind==4){if(++loaders>1||packed<56||!sx_add(c,&sxl_pef_loader,off,56))return false;}
    }return loaders==1;
}
static bool sxl_artipack(sx_context *c)
{
    uint16_t version,count;uint32_t dir;uint64_t end=32;
    if(!sxl_sig(c,0,"ARTIPACK",8)||!sx_u16(c,8,false,&version)||version!=0x100||!sx_u16(c,10,false,&count)||!count||!sx_u32(c,12,false,&dir)||dir<32||!sxl_span(c,dir,(uint64_t)count*34)||(uint64_t)dir+(uint64_t)count*34!=(uint64_t)c->size||!sx_add(c,&sxl_artipack_header,0,32)||!sx_table(c,&sxl_artipack_directory,dir,34,count))return false;
    for(uint16_t i=0;i<count;i++){uint32_t off,size,n,inner;int64_t at=dir+(int64_t)i*34;if(!sx_u32(c,at+14,false,&off)||off!=end||!sx_u32(c,at+18,false,&n)||!sx_u32(c,at+22,false,&size)||size<4||size>dir-end||!sx_u32(c,off,false,&inner)||inner!=n||!sx_add(c,&sxl_artipack_size,off,4))return false;end+=size;}return end==dir;
}
static bool sxl_arcfs(sx_context *c)
{
    uint32_t dir,data;
    if(!sxl_sig(c,0,"Archive\0",8)||!sx_u32(c,8,false,&dir)||!dir||dir%36||!sx_u32(c,12,false,&data)||data<96+(uint64_t)dir||data>(uint64_t)c->size||!sx_add(c,&sxl_arcfs_header,0,96)||!sx_table(c,&sxl_arcfs_directory,96,36,dir/36))return false;
    for(uint32_t i=0;i<dir/36;i++){uint8_t status;uint32_t off,size;int64_t at=96+(int64_t)i*36;if(!sxl_byte(c,at,&status)||!sx_u32(c,at+28,false,&size)||!sx_u32(c,at+32,false,&off))return false;if(status>1&&!(off&0x80000000U)&&!sxl_span(c,(uint64_t)data+off,size))return false;}return true;
}
static bool sx_legacy_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_MS_COMPRESS:case XX_FILE_TYPE_ASH0:case XX_FILE_TYPE_WII_LZ77:case XX_FILE_TYPE_LZV1:case XX_FILE_TYPE_ORACLE_SQUEEZE:case XX_FILE_TYPE_SOFTRONICS:case XX_FILE_TYPE_LOGITECH_COMPRESS:case XX_FILE_TYPE_DMA_PACKED:case XX_FILE_TYPE_GAS_HUFF:case XX_FILE_TYPE_HUF:case XX_FILE_TYPE_LZDIET:case XX_FILE_TYPE_LZPIS2:case XX_FILE_TYPE_LZ5:case XX_FILE_TYPE_LIZARD:case XX_FILE_TYPE_RNC:case XX_FILE_TYPE_GNU_GETTEXT_MO:case XX_FILE_TYPE_QT_QM:case XX_FILE_TYPE_ATARIST:case XX_FILE_TYPE_PEF:case XX_FILE_TYPE_ARTIPACK:case XX_FILE_TYPE_ARCFS:return true;default:return false;}
}
static bool sx_legacy_build(sx_context *c)
{
    bool ok=false;uint8_t h[12];uint32_t v;uint16_t n,root;
    switch(c->f->file_type){
    case XX_FILE_TYPE_MS_COMPRESS:
        if(sxl_sig(c,0,"SZDD\x88\xf0\x27\x33",8)){ok=sxl_sig(c,8,"A",1)&&sxl_span(c,14,0)&&sx_add(c,&sxl_szdd_header,0,14);}
        else ok=sxl_sig(c,0,"SZ \x88\xf0\x27\x33\xd1",8)&&sx_add(c,&sxl_sz_header,0,12);break;
    case XX_FILE_TYPE_WII_LZ77:ok=sxl_wii(c);break;
    case XX_FILE_TYPE_ASH0:ok=sxl_sig(c,0,"ASH0",4)&&sx_read(c,4,h,4)&&(h[1]||h[2]||h[3])&&sx_u32(c,8,true,&v)&&v>=16&&sxl_span(c,v,4)&&sx_add(c,&sxl_ash0_header,0,12);break;
    case XX_FILE_TYPE_LZV1:ok=sxl_sig(c,0,"LZV1\x5d\x19\x01\xad\0\0",10)&&sx_u16(c,10,true,&n)&&n>256&&n<16384&&sxl_span(c,12,1)&&sx_add(c,&sxl_lzv1_header,0,12);break;
    case XX_FILE_TYPE_ORACLE_SQUEEZE:ok=sxl_squeeze(c);break;
    case XX_FILE_TYPE_SOFTRONICS:ok=sxl_softronics(c);break;
    case XX_FILE_TYPE_LOGITECH_COMPRESS:case XX_FILE_TYPE_DMA_PACKED:ok=sxl_dcl(c,c->f->file_type==XX_FILE_TYPE_DMA_PACKED);break;
    case XX_FILE_TYPE_GAS_HUFF:ok=sx_u32(c,0,false,&v)&&v&&sx_u16(c,4,false,&n)&&n>=3&&n<=511&&sx_u16(c,6,false,&root)&&root<=n&&sxl_span(c,8,3)&&sx_add(c,&sxl_gas_huff_header,0,8);break;
    case XX_FILE_TYPE_HUF:ok=sxl_huf(c);break;
    case XX_FILE_TYPE_LZDIET:ok=sxl_diet(c);break;
    case XX_FILE_TYPE_LZPIS2:ok=sxl_pis(c);break;
    case XX_FILE_TYPE_LZ5:case XX_FILE_TYPE_LIZARD:ok=sxl_frame(c,c->f->file_type==XX_FILE_TYPE_LZ5?0x184d2205U:0x184d2206U);break;
    case XX_FILE_TYPE_RNC:ok=sxl_rnc(c);break;
    case XX_FILE_TYPE_GNU_GETTEXT_MO:ok=sxl_mo(c);break;
    case XX_FILE_TYPE_QT_QM:ok=sxl_qm(c);break;
    case XX_FILE_TYPE_ATARIST:ok=sxl_atari(c);break;
    case XX_FILE_TYPE_PEF:ok=sxl_pef(c);break;
    case XX_FILE_TYPE_ARTIPACK:ok=sxl_artipack(c);break;
    case XX_FILE_TYPE_ARCFS:ok=sxl_arcfs(c);break;
    default:break;
    }return ok&&sxl_finish(c);
}
static bool sx_legacy_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x600A0000)||id>=UINT32_C(0x600B0000))return true;
    const wchar_t *n=r->name,*s=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(!xx_rt_wcscmp(n,L"dos_date"))s=L"Packed MS-DOS date: year since 1980, month, day";
    else if(!xx_rt_wcscmp(n,L"dos_time"))s=L"Packed MS-DOS time: hours, minutes, two-second units";
    else if(id==sxl_dcl_header.id){if(!xx_rt_wcscmp(n,L"literal_coding"))s=v?L"Huffman literals":L"Raw literals";else s=L"Dictionary size is 64 times 2 to this power, in bytes";}
    else if(id==sxl_wii_lz77_header.id&&!xx_rt_wcscmp(n,L"method"))s=v==16?L"Nintendo LZ10":v==17?L"Nintendo LZ11":NULL;
    else if(id==sxl_squeeze_tree_node.id)s=L"Nonnegative: node index; negative: -symbol-1; -257 is end of stream";
    else if(id==sxl_gas_huff_header.id&&!xx_rt_wcscmp(n,L"node_count_minus_one"))s=L"Physical tree record count is this value plus one";
    else if(id==sxl_legacy_frame_block.id)s=!v?L"End mark":(v&0x80000000U)?L"Uncompressed block; low 31 bits are byte size":L"Compressed block byte size";
    else if(id==sxl_legacy_frame_header.id&&!xx_rt_wcscmp(n,L"block_descriptor"))s=L"Bits 4..6 select maximum block size; remaining bits reserved";
    else if(id==sxl_qm_block.id&&!xx_rt_wcscmp(n,L"tag"))s=v==0x42?L"Hashes":v==0x69?L"Messages":v==0xa7?L"Language":v==0x2f?L"Contexts":v==0x88?L"Numerus rules":v==0x96?L"Dependencies":NULL;
    else if((id==sxl_qm_message_field.id||id==sxl_qm_message_end.id||id==sxl_qm_message_obsolete.id)&&!xx_rt_wcscmp(n,L"tag"))s=v==1?L"End":v==2?L"SourceText16":v==3?L"Translation":v==4?L"Context16":v==5?L"Obsolete1":v==6?L"SourceText":v==7?L"Context":v==8?L"Comment":v==9?L"Obsolete2":NULL;
    else if(id==sxl_qm_message_field.id&&!xx_rt_wcscmp(n,L"content_size")&&v==UINT32_MAX)s=L"Null byte array; no payload bytes";
    else if(id==sxl_pef_section.id&&!xx_rt_wcscmp(n,L"alignment"))s=L"log2(alignment in bytes)";
    else if(id==sxl_pef_section.id&&!xx_rt_wcscmp(n,L"name_offset")&&xx_var_get_i64(&r->value)==-1)s=L"No section name";
    else if(id==sxl_pef_header.id&&!xx_rt_wcscmp(n,L"created_mac_epoch"))s=L"Seconds since 1904-01-01";
    else if(id==sxl_pef_loader.id&&!xx_rt_wcscmp(n,L"export_hash_power"))s=L"log2(number of export hash slots)";
    else if(id==sxl_arcfs_directory.id&&!xx_rt_wcscmp(n,L"offset_and_flags"))s=L"Bit 31: directory; low 31 bits: data-relative byte offset or directory-header offset";
    else if(id==sxl_arcfs_directory.id&&(!xx_rt_wcscmp(n,L"load_address")||!xx_rt_wcscmp(n,L"execution_address")))s=L"RISC OS load/exec address, or packed filetype and centisecond timestamp";
    return !s||xx_data_struct_record_set_comment(r,s);
}
