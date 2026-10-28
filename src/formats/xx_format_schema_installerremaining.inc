/* SPDX-License-Identifier: MIT
 * Bounded physical installer records; compressed and encoded metadata stay raw. */
static const xx_data_struct_field_desc sxir_nsis_firstheader_fields[]={
 SX_FIELD("flags","int32le",0,4,SX_FLAGS),
 SX_FIELD("signature","uint32le",4,4,SX_SIGNATURE),
 SX_FIELD("nsinst","uint32le[3]",8,12,SX_SIGNATURE),
 SX_FIELD("length_of_header","int32le",20,4,SX_SIZE),
 SX_FIELD("length_of_all_following_data","int32le",24,4,SX_SIZE),
};
static const sx_layout sxir_nsis_firstheader={0x60800001U,"nsis_firstheader",sxir_nsis_firstheader_fields,SX_COUNT(sxir_nsis_firstheader_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_common_flags_fields[]={
 SX_FIELD("flags","int32le",0,4,SX_FLAGS),
};
static const sx_layout sxir_nsis_common_flags={0x60800002U,"nsis_common_flags",sxir_nsis_common_flags_fields,SX_COUNT(sxir_nsis_common_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_block32_fields[]={
 SX_FIELD("header_relative_offset","uint32le",0,4,SX_OFFSET),
 SX_FIELD("item_count","int32le",4,4,SX_COUNT_PROP),
};
static const sx_layout sxir_nsis_block32={0x60800003U,"nsis_block32",sxir_nsis_block32_fields,SX_COUNT(sxir_nsis_block32_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_block64_fields[]={
 SX_FIELD("header_relative_offset","uint64le",0,8,SX_OFFSET),
 SX_FIELD("item_count","int32le",8,4,SX_COUNT_PROP),
};
static const sx_layout sxir_nsis_block64={0x60800004U,"nsis_block64",sxir_nsis_block64_fields,SX_COUNT(sxir_nsis_block64_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_instruction_fields[]={
 SX_FIELD("opcode","int32le",0,4,SX_ID),
 SX_FIELD("parameters","int32le[6]",4,24,SX_NONE),
};
static const sx_layout sxir_nsis_instruction={0x60800005U,"nsis_instruction",sxir_nsis_instruction_fields,SX_COUNT(sxir_nsis_instruction_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_block_length_fields[]={
 SX_FIELD("encoded_block_size","uint32le",0,4,SX_FLAGS),
};
static const sx_layout sxir_nsis_block_length={0x60800006U,"nsis_block_length",sxir_nsis_block_length_fields,SX_COUNT(sxir_nsis_block_length_fields),SX_LE};
static const xx_data_struct_field_desc sxir_installer_crc32_fields[]={
 SX_FIELD("crc32","uint32le",0,4,SX_CHECKSUM),
};
static const sx_layout sxir_installer_crc32={0x60800007U,"installer_crc32",sxir_installer_crc32_fields,SX_COUNT(sxir_installer_crc32_fields),SX_LE};
static const xx_data_struct_field_desc sxir_installer_name_fields[]={
 SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxir_installer_name={0x60800008U,"installer_name",sxir_installer_name_fields,SX_COUNT(sxir_installer_name_fields),SX_LE};
static const xx_data_struct_field_desc sxir_installer_utf8_fields[]={
 SX_FIELD("text","utf8",0,0,SX_NONE),
};
static const sx_layout sxir_installer_utf8={0x60800009U,"installer_utf8",sxir_installer_utf8_fields,SX_COUNT(sxir_installer_utf8_fields),SX_LE};
static const xx_data_struct_field_desc sxir_installer_terminator_fields[]={
 SX_FIELD("nul","uint8",0,1,SX_RESERVED),
};
static const sx_layout sxir_installer_terminator={0x6080000aU,"installer_terminator",sxir_installer_terminator_fields,SX_COUNT(sxir_installer_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxir_installer_size_fields[]={
 SX_FIELD("size","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxir_installer_size={0x6080000bU,"installer_size",sxir_installer_size_fields,SX_COUNT(sxir_installer_size_fields),SX_LE};
static const xx_data_struct_field_desc sxir_cookfs_footer_fields[]={
 SX_FIELD("stored_index_size","uint32be",0,4,SX_SIZE),
 SX_FIELD("page_count","uint32be",4,4,SX_COUNT_PROP),
 SX_FIELD("default_compression_method","uint8",8,1,SX_ID),
 SX_FIELD("signature","char[7]",9,7,SX_SIGNATURE),
};
static const sx_layout sxir_cookfs_footer={0x6080000cU,"cookfs_footer",sxir_cookfs_footer_fields,SX_COUNT(sxir_cookfs_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_page_digest_fields[]={
 SX_FIELD("digest","uint8[16]",0,16,SX_CHECKSUM),
};
static const sx_layout sxir_cookfs_page_digest={0x6080000dU,"cookfs_page_digest",sxir_cookfs_page_digest_fields,SX_COUNT(sxir_cookfs_page_digest_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_page_size_fields[]={
 SX_FIELD("stored_size","uint32be",0,4,SX_SIZE),
};
static const sx_layout sxir_cookfs_page_size={0x6080000eU,"cookfs_page_size",sxir_cookfs_page_size_fields,SX_COUNT(sxir_cookfs_page_size_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_blob_fields[]={
 SX_FIELD("compression_method","uint8",0,1,SX_ID),
};
static const sx_layout sxir_cookfs_blob={0x6080000fU,"cookfs_blob",sxir_cookfs_blob_fields,SX_COUNT(sxir_cookfs_blob_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_index_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxir_cookfs_index={0x60800010U,"cookfs_index",sxir_cookfs_index_fields,SX_COUNT(sxir_cookfs_index_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_directory_fields[]={
 SX_FIELD("entry_count","uint32be",0,4,SX_COUNT_PROP),
};
static const sx_layout sxir_cookfs_directory={0x60800011U,"cookfs_directory",sxir_cookfs_directory_fields,SX_COUNT(sxir_cookfs_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_name_length_fields[]={
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxir_cookfs_name_length={0x60800012U,"cookfs_name_length",sxir_cookfs_name_length_fields,SX_COUNT(sxir_cookfs_name_length_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_entry_fields[]={
 SX_FIELD("mtime","uint64be",0,8,SX_TIME),
 SX_FIELD("block_count","int32be",8,4,SX_COUNT_PROP),
};
static const sx_layout sxir_cookfs_entry={0x60800013U,"cookfs_entry",sxir_cookfs_entry_fields,SX_COUNT(sxir_cookfs_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxir_cookfs_block_fields[]={
 SX_FIELD("page_index","uint32be",0,4,SX_ID),
 SX_FIELD("page_relative_offset","uint32be",4,4,SX_OFFSET),
 SX_FIELD("size","uint32be",8,4,SX_SIZE),
};
static const sx_layout sxir_cookfs_block={0x60800014U,"cookfs_block",sxir_cookfs_block_fields,SX_COUNT(sxir_cookfs_block_fields),SX_BE};
static const xx_data_struct_field_desc sxir_sim_footer_fields[]={
 SX_FIELD("strings_offset","uint64le",0,8,SX_OFFSET),
 SX_FIELD("runtime_size","uint64le",8,8,SX_SIZE),
 SX_FIELD("runtime_offset","uint64le",16,8,SX_OFFSET),
 SX_FIELD("content_offset","uint64le",24,8,SX_OFFSET),
 SX_FIELD("compressed_runtime","uint8",32,1,SX_FLAGS),
 SX_FIELD("runtime_count","uint8",33,1,SX_COUNT_PROP),
 SX_FIELD("header_string_count","uint8",34,1,SX_COUNT_PROP),
 SX_FIELD("signature","uint8",35,1,SX_SIGNATURE),
};
static const sx_layout sxir_sim_footer={0x60800015U,"sim_footer",sxir_sim_footer_fields,SX_COUNT(sxir_sim_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_sim_stored_file_fields[]={
 SX_FIELD("unknown_00","uint8[4]",0,4,SX_NONE),
 SX_FIELD("size","uint32le",4,4,SX_SIZE),
 SX_FIELD("unknown_08","uint8[16]",8,16,SX_NONE),
};
static const sx_layout sxir_sim_stored_file={0x60800016U,"sim_stored_file",sxir_sim_stored_file_fields,SX_COUNT(sxir_sim_stored_file_fields),SX_LE};
static const xx_data_struct_field_desc sxir_excelsior_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("unknown_0c","uint8[4]",12,4,SX_NONE),
 SX_FIELD("index_offset","uint64le",16,8,SX_OFFSET),
 SX_FIELD("decoded_index_size","uint32le",24,4,SX_SIZE),
 SX_FIELD("decoded_prefix_size","uint32le",28,4,SX_SIZE),
 SX_FIELD("data_stream_offset","uint64le",32,8,SX_OFFSET),
};
static const sx_layout sxir_excelsior_header={0x60800017U,"excelsior_header",sxir_excelsior_header_fields,SX_COUNT(sxir_excelsior_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_excelsior_lzma_stream_fields[]={
 SX_FIELD("decoded_size","uint64le",0,8,SX_SIZE),
 SX_FIELD("lzma_properties","uint8",8,1,SX_NONE),
 SX_FIELD("dictionary_size","uint32le",9,4,SX_SIZE),
};
static const sx_layout sxir_excelsior_lzma_stream={0x60800018U,"excelsior_lzma_stream",sxir_excelsior_lzma_stream_fields,SX_COUNT(sxir_excelsior_lzma_stream_fields),SX_LE};
static const xx_data_struct_field_desc sxir_fead_outer_prefix_fields[]={
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("version","uint8",6,1,SX_NONE),
};
static const sx_layout sxir_fead_outer_prefix={0x60800019U,"fead_outer_prefix",sxir_fead_outer_prefix_fields,SX_COUNT(sxir_fead_outer_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxir_fead_encoded_header_fields[]={
 SX_FIELD("encoded_signature","uint8[6]",0,6,SX_SIGNATURE),
 SX_FIELD("encoded_unknown_06","uint8[4]",6,4,SX_NONE),
 SX_FIELD("encoded_payload_size","uint8[4]",10,4,SX_NONE),
 SX_FIELD("encoded_unknown_0e","uint8[4]",14,4,SX_NONE),
};
static const sx_layout sxir_fead_encoded_header={0x6080001aU,"fead_encoded_header",sxir_fead_encoded_header_fields,SX_COUNT(sxir_fead_encoded_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_group_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
};
static const sx_layout sxir_superdat_group={0x6080001bU,"superdat_group",sxir_superdat_group_fields,SX_COUNT(sxir_superdat_group_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_member_fields[]={
 SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
 SX_FIELD("name","char[260]",14,260,SX_NONE),
 SX_FIELD("uncompressed_size","uint32le",274,4,SX_SIZE),
 SX_FIELD("packed_size","uint32le",278,4,SX_SIZE),
 SX_FIELD("hour","uint8",282,1,SX_NONE),
 SX_FIELD("minute","uint8",283,1,SX_NONE),
 SX_FIELD("second","uint8",284,1,SX_NONE),
 SX_FIELD("year_since_1900","uint8",285,1,SX_NONE),
 SX_FIELD("month","uint8",286,1,SX_NONE),
 SX_FIELD("day","uint8",287,1,SX_NONE),
};
static const sx_layout sxir_superdat_member={0x6080001cU,"superdat_member",sxir_superdat_member_fields,SX_COUNT(sxir_superdat_member_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_lh1_stream_fields[]={
 SX_FIELD("uncompressed_size","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxir_superdat_lh1_stream={0x6080001dU,"superdat_lh1_stream",sxir_superdat_lh1_stream_fields,SX_COUNT(sxir_superdat_lh1_stream_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_group_trailer_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("unknown_08","uint8[3]",8,3,SX_NONE),
 SX_FIELD("unknown_checksum_bytes","uint8[4]",11,4,SX_NONE),
 SX_FIELD("trailer_size","uint16le",15,2,SX_SIZE),
};
static const sx_layout sxir_superdat_group_trailer={0x6080001eU,"superdat_group_trailer",sxir_superdat_group_trailer_fields,SX_COUNT(sxir_superdat_group_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_original_footer_fields[]={
 SX_FIELD("group_size","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxir_superdat_original_footer={0x6080001fU,"superdat_original_footer",sxir_superdat_original_footer_fields,SX_COUNT(sxir_superdat_original_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_footer_v0_fields[]={
 SX_FIELD("signature","char[17]",0,17,SX_SIGNATURE),
 SX_FIELD("group_size","uint32le",17,4,SX_SIZE),
 SX_FIELD("group_offset","uint32le",21,4,SX_OFFSET),
 SX_FIELD("member_count","uint32le",25,4,SX_COUNT_PROP),
 SX_FIELD("unknown_tail","uint8[4]",29,4,SX_NONE),
};
static const sx_layout sxir_superdat_footer_v0={0x60800020U,"superdat_footer_v0",sxir_superdat_footer_v0_fields,SX_COUNT(sxir_superdat_footer_v0_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_footer_v1_fields[]={
 SX_FIELD("signature","char[17]",0,17,SX_SIGNATURE),
 SX_FIELD("group_size","uint32le",17,4,SX_SIZE),
 SX_FIELD("group_offset","uint32le",21,4,SX_OFFSET),
 SX_FIELD("zero_count","uint32le",25,4,SX_RESERVED),
 SX_FIELD("member_count","uint32le",29,4,SX_COUNT_PROP),
 SX_FIELD("unknown_tail","uint8[4]",33,4,SX_NONE),
};
static const sx_layout sxir_superdat_footer_v1={0x60800021U,"superdat_footer_v1",sxir_superdat_footer_v1_fields,SX_COUNT(sxir_superdat_footer_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_footer_v12_fields[]={
 SX_FIELD("signature","char[17]",0,17,SX_SIGNATURE),
 SX_FIELD("signing_bytes","uint8[268]",17,268,SX_NONE),
 SX_FIELD("group_size","uint32le",285,4,SX_SIZE),
 SX_FIELD("group_offset","uint32le",289,4,SX_OFFSET),
 SX_FIELD("member_count","uint32le",293,4,SX_COUNT_PROP),
};
static const sx_layout sxir_superdat_footer_v12={0x60800022U,"superdat_footer_v12",sxir_superdat_footer_v12_fields,SX_COUNT(sxir_superdat_footer_v12_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_manifest_170_fields[]={
 SX_FIELD("name","char[144]",0,144,SX_NONE),
 SX_FIELD("checksum","uint32le",144,4,SX_CHECKSUM),
 SX_FIELD("unknown_94","uint8[12]",148,12,SX_NONE),
 SX_FIELD("uncompressed_size","uint32le",160,4,SX_SIZE),
 SX_FIELD("unknown_a4","uint8[6]",164,6,SX_NONE),
};
static const sx_layout sxir_superdat_manifest_170={0x60800023U,"superdat_manifest_170",sxir_superdat_manifest_170_fields,SX_COUNT(sxir_superdat_manifest_170_fields),SX_LE};
static const xx_data_struct_field_desc sxir_superdat_manifest_178_fields[]={
 SX_FIELD("name","char[144]",0,144,SX_NONE),
 SX_FIELD("checksum","uint32le",144,4,SX_CHECKSUM),
 SX_FIELD("unknown_94","uint8[12]",148,12,SX_NONE),
 SX_FIELD("uncompressed_size","uint32le",160,4,SX_SIZE),
 SX_FIELD("unknown_a4","uint8[6]",164,6,SX_NONE),
 SX_FIELD("classification","uint32le",170,4,SX_ID),
 SX_FIELD("unknown_ae","uint8[4]",174,4,SX_NONE),
};
static const sx_layout sxir_superdat_manifest_178={0x60800024U,"superdat_manifest_178",sxir_superdat_manifest_178_fields,SX_COUNT(sxir_superdat_manifest_178_fields),SX_LE};
static const xx_data_struct_field_desc sxir_solaris_zip_signature_fields[]={
 SX_FIELD("signature","char[25]",0,25,SX_SIGNATURE),
};
static const sx_layout sxir_solaris_zip_signature={0x60800025U,"solaris_zip_signature",sxir_solaris_zip_signature_fields,SX_COUNT(sxir_solaris_zip_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxir_solaris_zip_object_fields[]={
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("stored_object_size","uint32le",4,4,SX_SIZE),
 SX_FIELD("unknown_08","uint8[4]",8,4,SX_NONE),
};
static const sx_layout sxir_solaris_zip_object={0x60800026U,"solaris_zip_object",sxir_solaris_zip_object_fields,SX_COUNT(sxir_solaris_zip_object_fields),SX_LE};
static const xx_data_struct_field_desc sxir_solaris_zip_group_fields[]={
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("block_count","uint32le",4,4,SX_COUNT_PROP),
 SX_FIELD("maximum_block_size","uint32le",8,4,SX_SIZE),
};
static const sx_layout sxir_solaris_zip_group={0x60800027U,"solaris_zip_group",sxir_solaris_zip_group_fields,SX_COUNT(sxir_solaris_zip_group_fields),SX_LE};
static const xx_data_struct_field_desc sxir_solaris_zip_block_fields[]={
 SX_FIELD("uncompressed_size","uint32le",0,4,SX_SIZE),
 SX_FIELD("stored_size","uint32le",4,4,SX_SIZE),
 SX_FIELD("group_relative_offset","uint32le",8,4,SX_OFFSET),
};
static const sx_layout sxir_solaris_zip_block={0x60800028U,"solaris_zip_block",sxir_solaris_zip_block_fields,SX_COUNT(sxir_solaris_zip_block_fields),SX_LE};
static const xx_data_struct_field_desc sxir_desksoft_header_fields[]={
 SX_FIELD("signature","char[19]",0,19,SX_SIGNATURE),
};
static const sx_layout sxir_desksoft_header={0x60800029U,"desksoft_header",sxir_desksoft_header_fields,SX_COUNT(sxir_desksoft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_desksoft_end_fields[]={
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
};
static const sx_layout sxir_desksoft_end={0x6080002aU,"desksoft_end",sxir_desksoft_end_fields,SX_COUNT(sxir_desksoft_end_fields),SX_LE};
static const xx_data_struct_field_desc sxir_metaproducts_header_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
};
static const sx_layout sxir_metaproducts_header={0x6080002bU,"metaproducts_header",sxir_metaproducts_header_fields,SX_COUNT(sxir_metaproducts_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_metaproducts_member_fields[]={
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[103]",1,103,SX_NONE),
 SX_FIELD("packed_size","uint32le",104,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32le",108,4,SX_SIZE),
};
static const sx_layout sxir_metaproducts_member={0x6080002cU,"metaproducts_member",sxir_metaproducts_member_fields,SX_COUNT(sxir_metaproducts_member_fields),SX_LE};
static const xx_data_struct_field_desc sxir_metaproducts_footer_fields[]={
 SX_FIELD("footer_value","uint32le",0,4,SX_NONE),
 SX_FIELD("signature","uint32le",4,4,SX_SIGNATURE),
};
static const sx_layout sxir_metaproducts_footer={0x6080002dU,"metaproducts_footer",sxir_metaproducts_footer_fields,SX_COUNT(sxir_metaproducts_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_visualware_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("block_kind","char[4]",12,4,SX_ID),
 SX_FIELD("unknown_10","uint8[8]",16,8,SX_NONE),
 SX_FIELD("stored_size","uint32le",24,4,SX_SIZE),
};
static const sx_layout sxir_visualware_header={0x6080002eU,"visualware_header",sxir_visualware_header_fields,SX_COUNT(sxir_visualware_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_visualware_legacy_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("block_kind","char[4]",12,4,SX_ID),
 SX_FIELD("stored_size","uint32le",16,4,SX_SIZE),
};
static const sx_layout sxir_visualware_legacy_header={0x6080002fU,"visualware_legacy_header",sxir_visualware_legacy_header_fields,SX_COUNT(sxir_visualware_legacy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_visualware_legacy_data_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("block_kind","char[4]",12,4,SX_ID),
 SX_FIELD("stored_size_with_length","uint32le",16,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32le",20,4,SX_SIZE),
};
static const sx_layout sxir_visualware_legacy_data_header={0x60800030U,"visualware_legacy_data_header",sxir_visualware_legacy_data_header_fields,SX_COUNT(sxir_visualware_legacy_data_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_footer_fields[]={
 SX_FIELD("member_count","uint32le",0,4,SX_COUNT_PROP),
 SX_FIELD("signature","char[14]",4,14,SX_SIGNATURE),
};
static const sx_layout sxir_lyme_footer={0x60800031U,"lyme_footer",sxir_lyme_footer_fields,SX_COUNT(sxir_lyme_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_member_fields[]={
 SX_FIELD("file_offset","uint32le",0,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32le",4,4,SX_SIZE),
 SX_FIELD("stored_size","uint32le",8,4,SX_SIZE),
};
static const sx_layout sxir_lyme_member={0x60800032U,"lyme_member",sxir_lyme_member_fields,SX_COUNT(sxir_lyme_member_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_name_length_fields[]={
 SX_FIELD("name_size","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxir_lyme_name_length={0x60800033U,"lyme_name_length",sxir_lyme_name_length_fields,SX_COUNT(sxir_lyme_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_label_fields[]={
 SX_FIELD("label_size","uint32le",0,4,SX_SIZE),
 SX_FIELD("label_kind","uint32le",4,4,SX_ID),
};
static const sx_layout sxir_lyme_label={0x60800034U,"lyme_label",sxir_lyme_label_fields,SX_COUNT(sxir_lyme_label_fields),SX_LE};
static const xx_data_struct_field_desc sxir_instalit_dcl_header_fields[]={
 SX_FIELD("literal_mode","uint8",0,1,SX_ID),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxir_instalit_dcl_header={0x60800035U,"instalit_dcl_header",sxir_instalit_dcl_header_fields,SX_COUNT(sxir_instalit_dcl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_softpaq4_descriptor_0_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint32le",4,4,SX_FLAGS),
 SX_FIELD("record_0_size","uint32le",8,4,SX_SIZE),
 SX_FIELD("record_0_offset","uint32le",12,4,SX_OFFSET),
 SX_FIELD("record_1_size","uint32le",16,4,SX_SIZE),
 SX_FIELD("record_1_offset","uint32le",20,4,SX_OFFSET),
 SX_FIELD("record_2_size","uint32le",24,4,SX_SIZE),
 SX_FIELD("record_2_offset","uint32le",28,4,SX_OFFSET),
 SX_FIELD("record_3_size","uint32le",32,4,SX_SIZE),
 SX_FIELD("record_3_offset","uint32le",36,4,SX_OFFSET),
 SX_FIELD("unknown_tail","uint8[24]",40,24,SX_NONE),
};
static const sx_layout sxir_softpaq4_descriptor_0={0x60800036U,"softpaq4_descriptor_0",sxir_softpaq4_descriptor_0_fields,SX_COUNT(sxir_softpaq4_descriptor_0_fields),SX_LE};
static const xx_data_struct_field_desc sxir_softpaq4_descriptor_8_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint32le",4,4,SX_FLAGS),
 SX_FIELD("unknown_08","uint8[4]",8,4,SX_NONE),
 SX_FIELD("record_0_size","uint32le",12,4,SX_SIZE),
 SX_FIELD("record_0_offset","uint32le",16,4,SX_OFFSET),
 SX_FIELD("record_1_size","uint32le",20,4,SX_SIZE),
 SX_FIELD("record_1_offset","uint32le",24,4,SX_OFFSET),
 SX_FIELD("record_2_size","uint32le",28,4,SX_SIZE),
 SX_FIELD("record_2_offset","uint32le",32,4,SX_OFFSET),
 SX_FIELD("record_3_size","uint32le",36,4,SX_SIZE),
 SX_FIELD("record_3_offset","uint32le",40,4,SX_OFFSET),
 SX_FIELD("record_4_size","uint32le",44,4,SX_SIZE),
 SX_FIELD("record_4_offset","uint32le",48,4,SX_OFFSET),
 SX_FIELD("unknown_tail","uint8[12]",52,12,SX_NONE),
};
static const sx_layout sxir_softpaq4_descriptor_8={0x60800037U,"softpaq4_descriptor_8",sxir_softpaq4_descriptor_8_fields,SX_COUNT(sxir_softpaq4_descriptor_8_fields),SX_LE};
static const xx_data_struct_field_desc sxir_softpaq4_name_length_fields[]={
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxir_softpaq4_name_length={0x60800038U,"softpaq4_name_length",sxir_softpaq4_name_length_fields,SX_COUNT(sxir_softpaq4_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxir_softpaq4_footer_fields[]={
 SX_FIELD("unknown_00","uint8[4]",0,4,SX_NONE),
 SX_FIELD("signature","uint32le",4,4,SX_SIGNATURE),
};
static const sx_layout sxir_softpaq4_footer={0x60800039U,"softpaq4_footer",sxir_softpaq4_footer_fields,SX_COUNT(sxir_softpaq4_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxir_inftool_header_22_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_NONE),
 SX_FIELD("string_04_size","uint8",4,1,SX_SIZE),
 SX_FIELD("inf_name_size","uint8",5,1,SX_SIZE),
 SX_FIELD("flag_06","uint8",6,1,SX_FLAGS),
 SX_FIELD("string_07_size","uint8",7,1,SX_SIZE),
 SX_FIELD("field_08_size","uint32le",8,4,SX_SIZE),
 SX_FIELD("field_0c_size","uint32le",12,4,SX_SIZE),
 SX_FIELD("flag_10","uint8",16,1,SX_FLAGS),
 SX_FIELD("zero_11","uint8",17,1,SX_RESERVED),
 SX_FIELD("file_size","uint32le",18,4,SX_SIZE),
};
static const sx_layout sxir_inftool_header_22={0x6080003aU,"inftool_header_22",sxir_inftool_header_22_fields,SX_COUNT(sxir_inftool_header_22_fields),SX_LE};
static const xx_data_struct_field_desc sxir_inftool_header_24_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_NONE),
 SX_FIELD("string_04_size","uint8",4,1,SX_SIZE),
 SX_FIELD("inf_name_size","uint8",5,1,SX_SIZE),
 SX_FIELD("flag_06","uint8",6,1,SX_FLAGS),
 SX_FIELD("string_07_size","uint8",7,1,SX_SIZE),
 SX_FIELD("field_08_size","uint32le",8,4,SX_SIZE),
 SX_FIELD("field_0c_size","uint32le",12,4,SX_SIZE),
 SX_FIELD("flag_10","uint8",16,1,SX_FLAGS),
 SX_FIELD("zero_11","uint8",17,1,SX_RESERVED),
 SX_FIELD("flag_12","uint8",18,1,SX_FLAGS),
 SX_FIELD("obfuscated_cabinet","uint8",19,1,SX_FLAGS),
 SX_FIELD("file_size","uint32le",20,4,SX_SIZE),
};
static const sx_layout sxir_inftool_header_24={0x6080003bU,"inftool_header_24",sxir_inftool_header_24_fields,SX_COUNT(sxir_inftool_header_24_fields),SX_LE};
static const xx_data_struct_field_desc sxir_active_delivery_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown_04","uint8[4]",4,4,SX_NONE),
 SX_FIELD("zip_size","uint32le",8,4,SX_SIZE),
};
static const sx_layout sxir_active_delivery_header={0x6080003cU,"active_delivery_header",sxir_active_delivery_header_fields,SX_COUNT(sxir_active_delivery_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_lyme_zero_sentinel_fields[]={
 SX_FIELD("zero","uint32le",0,4,SX_RESERVED),
};
static const sx_layout sxir_lyme_zero_sentinel={0x6080003dU,"lyme_zero_sentinel",sxir_lyme_zero_sentinel_fields,SX_COUNT(sxir_lyme_zero_sentinel_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_string_pool_fields[]={
 SX_FIELD("strings","uint8",0,0,SX_NONE),
};
static const sx_layout sxir_nsis_string_pool={0x6080003eU,"nsis_string_pool",sxir_nsis_string_pool_fields,SX_COUNT(sxir_nsis_string_pool_fields),SX_LE};
static const sx_layout*const sx_installerremaining_layouts[]={&sxir_nsis_firstheader,&sxir_nsis_common_flags,&sxir_nsis_block32,&sxir_nsis_block64,&sxir_nsis_instruction,&sxir_nsis_block_length,&sxir_installer_crc32,&sxir_installer_name,&sxir_installer_utf8,&sxir_installer_terminator,&sxir_installer_size,&sxir_cookfs_footer,&sxir_cookfs_page_digest,&sxir_cookfs_page_size,&sxir_cookfs_blob,&sxir_cookfs_index,&sxir_cookfs_directory,&sxir_cookfs_name_length,&sxir_cookfs_entry,&sxir_cookfs_block,&sxir_sim_footer,&sxir_sim_stored_file,&sxir_excelsior_header,&sxir_excelsior_lzma_stream,&sxir_fead_outer_prefix,&sxir_fead_encoded_header,&sxir_superdat_group,&sxir_superdat_member,&sxir_superdat_lh1_stream,&sxir_superdat_group_trailer,&sxir_superdat_original_footer,&sxir_superdat_footer_v0,&sxir_superdat_footer_v1,&sxir_superdat_footer_v12,&sxir_superdat_manifest_170,&sxir_superdat_manifest_178,&sxir_solaris_zip_signature,&sxir_solaris_zip_object,&sxir_solaris_zip_group,&sxir_solaris_zip_block,&sxir_desksoft_header,&sxir_desksoft_end,&sxir_metaproducts_header,&sxir_metaproducts_member,&sxir_metaproducts_footer,&sxir_visualware_header,&sxir_visualware_legacy_header,&sxir_visualware_legacy_data_header,&sxir_lyme_footer,&sxir_lyme_member,&sxir_lyme_name_length,&sxir_lyme_label,&sxir_instalit_dcl_header,&sxir_softpaq4_descriptor_0,&sxir_softpaq4_descriptor_8,&sxir_softpaq4_name_length,&sxir_softpaq4_footer,&sxir_inftool_header_22,&sxir_inftool_header_24,&sxir_active_delivery_header,&sxir_lyme_zero_sentinel,&sxir_nsis_string_pool};
static bool sx_installerremaining_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<0x60800000U||id>=0x60810000U)return true;
 if(id==sxir_nsis_string_pool.id)return xx_data_struct_record_set_comment(r,L"Stored NSIS string pool, ANSI or UTF-16LE depending on the installer; bytes preserve every terminator and string-control opcode.");
 if(!xx_rt_wcscmp(r->name,L"header_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the beginning of the decoded NSIS common header; this view exposes only stored headers.");
 if(!xx_rt_wcscmp(r->name,L"page_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset in the decoded CookFS page identified by page_index.");
 if(!xx_rt_wcscmp(r->name,L"group_relative_offset"))return xx_data_struct_record_set_comment(r,L"Physical byte offset from the beginning of this TG block group.");
 if(!xx_rt_wcscmp(r->name,L"encoded_payload_size"))return xx_data_struct_record_set_comment(r,L"Masked bytes of the FEAD payload length; these bytes are displayed without decoding the header.");
 if(!xx_rt_wcscmp(r->name,L"digest"))return xx_data_struct_record_set_comment(r,L"MD5 digest of the decoded CookFS page; displaying the digest does not validate it.");
 if(!xx_rt_wcscmp(r->name,L"checksum"))return xx_data_struct_record_set_comment(r,L"SuperDAT member checksum; classification 2 uses the vendor DAT checksum, other types use reflected CRC with zero initialization and final XOR.");
 if(!xx_rt_wcscmp(r->name,L"encoded_block_size"))return xx_data_struct_record_set_comment(r,L"Bit 31 marks a compressed block; bits 0..30 give the number of stored payload bytes.");
 if(!xx_rt_wcscmp(r->name,L"year_since_1900"))return xx_data_struct_record_set_comment(r,L"Calendar year minus 1900.");
 if(id==sxir_sim_footer.id&&(r->property&SX_OFFSET))return xx_data_struct_record_set_comment(r,L"Stored file offset; launchers may relocate all three offsets by the common delta to the version string. The stored value is preserved.");
 if(r->property&SX_OFFSET)return xx_data_struct_record_set_comment(r,L"Physical byte offset relative to the beginning of this installer file.");
 if(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 uint64_t n=xx_var_get_u64(&r->value);
 if(id==sxir_cookfs_entry.id&&!xx_rt_wcscmp(r->name,L"block_count"))return xx_data_struct_record_set_comment(r,xx_var_get_i64(&r->value)==-1?L"DIRECTORY (-1); a recursive directory follows":L"Number of page-slice triples following this file entry");
 if(id==sxir_cookfs_entry.id&&!xx_rt_wcscmp(r->name,L"mtime"))return xx_data_struct_record_set_comment(r,L"CookFS modification timestamp.");
 if(id==sxir_nsis_firstheader.id&&!xx_rt_wcscmp(r->name,L"flags"))return xx_data_struct_record_set_comment(r,L"UNINSTALL=0x1 | SILENT=0x2 | NO_CRC=0x4 | FORCE_CRC=0x8; unknown bits are preserved.");
 if((id==sxir_cookfs_blob.id&&!xx_rt_wcscmp(r->name,L"compression_method"))||(id==sxir_cookfs_footer.id&&!xx_rt_wcscmp(r->name,L"default_compression_method")))return xx_data_struct_record_set_comment(r,n==0?L"STORED":n==1?L"DEFLATE":n==2?L"BZIP2":n==255?L"CUSTOM (LZMA-Alone in supported BitRock files)":L"Other CookFS compression method");
 if(id==sxir_instalit_dcl_header.id&&!xx_rt_wcscmp(r->name,L"literal_mode"))return xx_data_struct_record_set_comment(r,n==0?L"BINARY_LITERALS":n==1?L"HUFFMAN_LITERALS":L"Unknown literal mode");
 if(id==sxir_instalit_dcl_header.id&&!xx_rt_wcscmp(r->name,L"dictionary_bits"))return xx_data_struct_record_set_comment(r,n==4?L"1024-byte dictionary":n==5?L"2048-byte dictionary":n==6?L"4096-byte dictionary":L"Unsupported dictionary size");
 if(id==sxir_lyme_label.id&&!xx_rt_wcscmp(r->name,L"label_kind"))return xx_data_struct_record_set_comment(r,n==1?L"APPLICATION_LABEL":n==3?L"DIRECTORY_LABEL":L"Unknown label kind");
 return true;}

/* Reads use physical file coordinates, never decoded-buffer offsets. */
typedef struct sxir_view {sx_context*c;uint64_t work;} sxir_view;
static bool sxir_span(sxir_view*v,uint64_t at,uint64_t z,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&end<=(uint64_t)v->c->size&&at<=end&&z<=end-at;}
static bool sxir_read(sxir_view*v,uint64_t at,void*b,size_t z,uint64_t end)
{return ++v->work<=4000000&&sxir_span(v,at,z,end)&&sx_read(v->c,(int64_t)at,b,z);}
static bool sxir_u(sxir_view*v,uint64_t at,unsigned z,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!z||z>8||!sxir_read(v,at,b,z,end))return false;*out=0;for(unsigned i=0;i<z;i++)*out|=(uint64_t)b[i]<<((be?z-1-i:i)*8);return true;}
static bool sxir_eq(sxir_view*v,uint64_t at,const char*s,size_t z,uint64_t end)
{uint8_t b[64];return z<=sizeof(b)&&sxir_read(v,at,b,z,end)&&!xx_rt_memcmp(b,s,z);}
static bool sxir_emit(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t z,uint64_t end)
{if(!sxir_span(v,at,z,end))return false;if(!z||v->c->count>=24000)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;if(z<(uint64_t)f->rel_offset)return false;if(!f->size&&z-(uint64_t)f->rel_offset>(uint64_t)sx_variable_field_limit(f->type))return true;return sx_add(v->c,l,(int64_t)at,(int64_t)z);}
static bool sxir_row(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return sxir_emit(v,l,at,(uint64_t)(f->rel_offset+f->size),end);}
static bool sxir_table(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t n,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||n>4000000||n>UINT64_MAX/z||!sxir_span(v,at,n*z,end))return false;for(uint64_t i=0;i<n&&v->c->count<24000;i++,at+=z)if(!sxir_row(v,l,at,end))return false;return true;}
static bool sxir_zstr(sxir_view*v,uint64_t*at,uint64_t end,uint64_t*length)
{uint64_t p=*at;uint8_t b;while(*at<end&&*at-p<=1048576){if(!sxir_read(v,(*at)++,&b,1,end))return false;if(!b){*length=*at-p-1;return sxir_emit(v,&sxir_installer_name,p,*length,end)&&sxir_row(v,&sxir_installer_terminator,*at-1,end);}}return false;}
static bool sxir_find(sxir_view*v,uint64_t begin,uint64_t end,const char*sig,size_t z,bool last,uint64_t*out)
{uint8_t b[4096];bool found=false;if(!z||z>64||begin>end)return false;while(end-begin>=z){size_t n=end-begin>sizeof(b)?sizeof(b):(size_t)(end-begin);if(!sxir_read(v,begin,b,n,end))return false;for(size_t i=0;i+z<=n;i++)if(!xx_rt_memcmp(b+i,sig,z)){*out=begin+i;found=true;if(!last)return true;}if(n==end-begin)break;begin+=n-z+1;}return found;}
static bool sxir_pe(sxir_view*v,uint64_t start,uint64_t end,uint64_t*out,uint64_t*certificate)
{uint64_t pe,sections,opt,headers,at;*certificate=end;if(!sxir_eq(v,start,"MZ",2,end)){*out=start;return true;}if(!sxir_u(v,start+60,4,false,&pe,end)||pe>16777216||pe>end-start||!sxir_eq(v,start+pe,"PE\0\0",4,end)||!sxir_u(v,start+pe+6,2,false,&sections,end)||!sections||sections>96||!sxir_u(v,start+pe+20,2,false,&opt,end)||opt<64||opt>4096||!sxir_u(v,start+pe+84,4,false,&headers,end))return false;at=start+pe+24+opt;if(!sxir_span(v,at,sections*40,end)||headers<pe+24+opt+sections*40||headers>end-start)return false;*out=start+headers;
 for(uint64_t i=0;i<sections;i++){uint64_t size,offset;if(!sxir_u(v,at+i*40+16,4,false,&size,end)||!sxir_u(v,at+i*40+20,4,false,&offset,end)||offset>end-start||!sxir_span(v,start+offset,size,end))return false;if(size&&start+offset+size>*out)*out=start+offset+size;}
 uint64_t magic;if(!sxir_u(v,start+pe+24,2,false,&magic,end))return false;uint64_t dd=magic==0x10b?128:magic==0x20b?144:0;
 if(dd&&opt>=dd+8){uint64_t off,size;if(!sxir_u(v,start+pe+24+dd,4,false,&off,end)||!sxir_u(v,start+pe+24+dd+4,4,false,&size,end))return false;if(size>=8&&off&&off<=end-start&&sxir_span(v,start+off,size,end)){uint64_t a=start+off,finish=a+size;bool valid=true;while(a<finish){uint64_t z,revision,type;if(!sxir_u(v,a,4,false,&z,finish)||z<8||!sxir_span(v,a,z,finish)||!sxir_u(v,a+4,2,false,&revision,finish)||revision!=0x200||!sxir_u(v,a+6,2,false,&type,finish)||type!=2){valid=false;break;}uint64_t pad=(8-(z&7))&7;if(z+pad>finish-a){valid=false;break;}a+=z+pad;}if(valid&&a==finish){if(finish==end)*certificate=start+off;if(start+off==*out)*out=finish;}}}
 return true;}
static int sxir_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxir_finish(sx_context*c)
{size_t n=c->count,k=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxir_order);for(size_t i=0;i<n;i++){int64_t a=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(a<end)continue;c->items[k++]=c->items[i];end=a+z;}c->count=k;n=k;end=0;for(size_t i=0;i<n;i++){int64_t a=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(a>end&&!sx_raw(c,end,a-end))return false;end=a+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxir_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))

static bool sxir_ns_lzma(sxir_view*v,uint64_t at,uint64_t end)
{uint8_t b[7];return sxir_read(v,at,b,7,end)&&b[0]==0x5d&&!b[1]&&!b[2]&&!b[5]&&!(b[6]&128);}
static bool sxir_nsis(sxir_view*v)
{uint64_t end=v->c->size,at=0,flags,header_size,size,packed;bool found=false;
 if(sxir_eq(v,0,"MZ",2,end)){for(at=512;at<=end&&end-at>=28;at+=512){if(sxir_eq(v,at+4,"\xef\xbe\xad\xdeNullsoftInst",16,end)){found=true;break;}}if(!found)return false;}
 if(!sxir_eq(v,at+4,"\xef\xbe\xad\xdeNullsoftInst",16,end)||!IR_U(at,4,flags,end)||flags&~15U||!IR_U(at+20,4,header_size,end)||!header_size||header_size>16777216||!IR_U(at+24,4,size,end)||size<32||!sxir_span(v,at,size,end)||!IR_ROW(nsis_firstheader,at,end))return false;
 uint64_t finish=at+size;if((flags&8)||!(flags&4)){if(!IR_ROW(installer_crc32,finish-4,finish))return false;finish-=4;}
 uint64_t data=at+28;if(!IR_U(data,4,packed,finish))return false;bool solid=packed!=header_size&&(!(packed&0x80000000U)||sxir_ns_lzma(v,data,finish)||sxir_ns_lzma(v,data+1,finish));if(solid)return true;
 if(!IR_ROW(nsis_block_length,data,finish))return false;uint64_t bytes=packed&0x7fffffffU;if(!sxir_span(v,data+4,bytes,finish))return false;if(packed&0x80000000U)return true;if(bytes!=header_size||bytes<68)return false;
 uint64_t h=data+4,he=h+bytes,stride=8;if(bytes>=100){bool wide=true;for(unsigned i=0;i<8;i++){uint64_t upper;if(!IR_U(h+8+i*12,4,upper,he))return false;if(upper)wide=false;}if(wide)stride=12;}
 if(!IR_ROW(nsis_common_flags,h,he)||!sxir_table(v,stride==12?&sxir_nsis_block64:&sxir_nsis_block32,h+4,8,he))return false;
 uint64_t entries,count,strings,lang;if(!IR_U(h+4+stride*2,4,entries,he)||!IR_U(h+stride*3,4,count,he)||!IR_U(h+4+stride*3,4,strings,he)||!IR_U(h+4+stride*4,4,lang,he)||entries>bytes||count>(bytes-entries)/28||strings>=lang||lang>bytes)return false;
 if(!sxir_table(v,&sxir_nsis_instruction,h+entries,count,he)||!sxir_emit(v,&sxir_nsis_string_pool,h+strings,lang-strings,he))return false;
 for(uint64_t i=0;i<count;i++){uint64_t command=h+entries+28*i,op,off,n;if(!IR_U(command,4,op,he))return false;if(op!=20)continue;if(!IR_U(command+12,4,off,he)||off>finish-he||!IR_U(he+off,4,n,finish)||!sxir_span(v,he+off+4,n&0x7fffffffU,finish)||!IR_ROW(nsis_block_length,he+off,finish))return false;}
 return true;}
static bool sxir_cook_dir(sxir_view*v,uint64_t*at,uint64_t end,unsigned depth)
{uint64_t count;if(depth>64||!sxir_u(v,*at,4,true,&count,end)||count>65535||!IR_ROW(cookfs_directory,*at,end))return false;*at+=4;
 for(uint64_t i=0;i<count;i++){uint64_t n,blocks;uint8_t zero;if(!IR_U(*at,1,n,end)||!n||!IR_ROW(cookfs_name_length,*at,end))return false;(*at)++;if(!sxir_span(v,*at,n+1,end)||!sxir_emit(v,&sxir_installer_utf8,*at,n,end)||!sxir_read(v,*at+n,&zero,1,end)||zero||!IR_ROW(installer_terminator,*at+n,end))return false;*at+=n+1;if(!sxir_u(v,*at+8,4,true,&blocks,end)||!IR_ROW(cookfs_entry,*at,end))return false;*at+=12;
  if(blocks==UINT32_MAX){if(!sxir_cook_dir(v,at,end,depth+1))return false;}else{if(blocks>1000000||!sxir_table(v,&sxir_cookfs_block,*at,blocks,end))return false;*at+=blocks*12;}}
 return true;}
static bool sxir_cookfs(sxir_view*v)
{uint64_t end=v->c->size,sig,index_size,count;if(v->c->f->format_size>0&&(uint64_t)v->c->f->format_size<end)end=(uint64_t)v->c->f->format_size;if(end<16||!sxir_find(v,end>16777216?end-16777216:0,end,"CFS0002",7,true,&sig)||sig<9)return false;uint64_t footer=sig-9,finish=sig+7;
 if(!sxir_u(v,footer,4,true,&index_size,finish)||!index_size||index_size>67108864||!sxir_u(v,footer+4,4,true,&count,finish)||count>65535||index_size>footer||count*20>footer-index_size||!IR_ROW(cookfs_footer,footer,finish))return false;
 uint64_t table=footer-index_size-count*20,total=0;for(uint64_t i=0;i<count;i++){uint64_t z;if(!sxir_u(v,table+count*16+4*i,4,true,&z,footer)||z>67108864||z>table-total)return false;total+=z;}
 if(!sxir_table(v,&sxir_cookfs_page_digest,table,count,footer)||!sxir_table(v,&sxir_cookfs_page_size,table+16*count,count,footer))return false;
 uint64_t p=table-total;for(uint64_t i=0;i<count;i++){uint64_t z;if(!sxir_u(v,table+count*16+4*i,4,true,&z,footer))return false;if(z&&!IR_ROW(cookfs_blob,p,p+z))return false;p+=z;}
 p=footer-index_size;uint64_t method;if(!IR_U(p,1,method,footer)||!IR_ROW(cookfs_blob,p,footer))return false;if(method)return true;p++;if(!sxir_eq(v,p,"CFS2.200",8,footer)||!IR_ROW(cookfs_index,p,footer))return false;p+=8;return sxir_cook_dir(v,&p,footer,0);}
static bool sxir_sim(sxir_view*v)
{uint64_t end=v->c->size;if(end<4132)return false;uint64_t footer=end-36,so,ro,rl,co,n,compressed,runtime;
 if(!IR_U(footer,8,so,end)||!IR_U(footer+8,8,rl,end)||!IR_U(footer+16,8,ro,end)||!IR_U(footer+24,8,co,end)||!IR_U(footer+32,1,compressed,end)||!IR_U(footer+33,1,runtime,end)||!IR_U(footer+34,1,n,end)||n<119||compressed>1||!sxir_eq(v,footer+35,"\xf1",1,end)||so<4096||so>=ro||ro>co||co>footer||rl!=co-ro||!IR_ROW(sim_footer,footer,end))return false;
 if(!sxir_eq(v,so,"Smart Install Maker v.",21,ro)){uint64_t found;if(!sxir_find(v,4096,footer,"Smart Install Maker v.",21,true,&found))return false;if(found>=so){uint64_t delta=found-so;if(delta>footer-co)return false;ro+=delta;co+=delta;}else{uint64_t delta=so-found;if(delta>ro||delta>co)return false;ro-=delta;co-=delta;}so=found;if(so>=ro||ro>co||co>footer||rl!=co-ro)return false;}
 uint64_t at=so,chunks=0,rest=0;for(uint64_t i=0;at<ro;i++){uint64_t start=at,len;if(!sxir_zstr(v,&at,ro,&len))return false;if(i==117||i==118){uint64_t value=0;if(!len||len>10)return false;for(uint64_t k=0;k<len;k++){uint64_t b;if(!IR_U(start+k,1,b,ro)||b<'0'||b>'9'||value>(UINT32_MAX-(b-'0'))/10)return false;value=value*10+b-'0';}if(i==117)chunks=value;else rest=value;}}
 if(!compressed){at=ro;for(uint64_t i=0;i<runtime;i++){uint64_t len,start,size=0;if(!sxir_zstr(v,&at,co,&len))return false;start=at;if(!sxir_zstr(v,&at,co,&len)||!len||len>10)return false;for(uint64_t k=0;k<len;k++){uint64_t b;if(!IR_U(start+k,1,b,co)||b<'0'||b>'9'||size>(UINT32_MAX-(b-'0'))/10)return false;size=size*10+b-'0';}if(!sxir_span(v,at,size,co))return false;at+=size;}if(at!=co)return false;}
 if(!chunks&&!rest){at=co;while(at<footer){uint64_t size;if(!IR_U(at+4,4,size,footer)||!IR_ROW(sim_stored_file,at,footer)||!sxir_span(v,at+24,size,footer))return false;at+=24+size;}}
 return true;}
static bool sxir_excelsior(sxir_view*v)
{uint64_t end=v->c->size,at,cert,index,data;if(!sxir_pe(v,0,end,&at,&cert)||!sxir_eq(v,at,"ExcelsiorII1",12,end)||!IR_ROW(excelsior_header,at,end)||!IR_U(at+16,8,index,end)||!IR_U(at+32,8,data,end)||data<at+40||index<=data||!IR_ROW(excelsior_lzma_stream,data,index)||!IR_ROW(excelsior_lzma_stream,index,end))return false;return true;}
static bool sxir_fead(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert))return false;if(sxir_eq(v,at,"NOS_PO",6,end)){if(!IR_ROW(fead_outer_prefix,at,end))return false;at+=7;}return IR_ROW(fead_encoded_header,at,end);}
static bool sxir_desksoft(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert)||!sxir_eq(v,at,"<Setup Data Header>",19,end)||!IR_ROW(desksoft_header,at,end))return false;at+=19;
 while(at<end){if(sxir_eq(v,at,"<Setup Data End>",16,end))return at+16==end&&IR_ROW(desksoft_end,at,end);uint64_t len,n;if(!sxir_zstr(v,&at,end,&len)||!len||!IR_U(at,4,n,end)||!IR_ROW(installer_size,at,end)||!sxir_span(v,at+4,n,end))return false;at+=4+n;}return false;}
static bool sxir_metaproducts(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert)||!sxir_eq(v,at,"\x73\x19\xba\xab",4,end)||!IR_ROW(metaproducts_header,at,end))return false;at+=4;end=cert;
 while(at<end){if(sxir_eq(v,at+4,"\x73\x19\xc0\xab",4,end))return at+8==end&&IR_ROW(metaproducts_footer,at,end);uint64_t n;if(!IR_U(at+104,4,n,end)||!n||!IR_ROW(metaproducts_member,at,end)||!sxir_span(v,at+112,n,end))return false;at+=112+n;}return false;}
static bool sxir_visualware(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert))return false;bool legacy=false;for(unsigned i=0;i<3;i++){const char*tag=i==0?"\\]_B":i==1?"\\]_V":"\\]_Z";if(!sxir_eq(v,at,"JKMNPQSTVWYZ",12,end)||!sxir_eq(v,at+12,tag,4,end))return false;if(!i)legacy=sxir_eq(v,at+20,"\xca\xfe\xba\xbe",4,end);uint64_t n,z=legacy?(i==2?24:20):28;if(!IR_U(at+(legacy?16:24),4,n,end))return false;if(legacy&&i==2){if(n<4)return false;n-=4;}if(!sxir_row(v,legacy?(i==2?&sxir_visualware_legacy_data_header:&sxir_visualware_legacy_header):&sxir_visualware_header,at,end)||!n||!sxir_span(v,at+z,n,end))return false;at+=z+n;if(i<2){uint64_t pad=(16-(at&15))&15;if(!sxir_span(v,at,pad,end))return false;at+=pad;}}return true;}
static bool sxir_lyme(sxir_view*v)
{uint64_t end=v->c->size;if(end<18)return false;uint64_t at=end-18,count;if(!sxir_eq(v,at+4,"1.10!LYME_SFX!",14,end)||!IR_U(at,4,count,end)||!count||count>65536||!IR_ROW(lyme_footer,at,end))return false;
 if(at>=12){uint64_t n,kind,zero;if(!IR_U(at-8,4,n,end)||!IR_U(at-4,4,kind,end))return false;if((kind==1||kind==3)&&n<=4096&&n<=at-12&&IR_U(at-12-n,4,zero,end)&&!zero){if(!IR_ROW(lyme_zero_sentinel,at-12-n,end)||!sxir_emit(v,&sxir_installer_name,at-8-n,n,end)||!IR_ROW(lyme_label,at-8,end))return false;at-=12+n;}}
 for(uint64_t i=0;i<count;i++){uint64_t n,offset,size;if(at<4||!IR_U(at-4,4,n,end)||!n||n>4096||n>at-4||at-4-n<12||!IR_ROW(lyme_name_length,at-4,end))return false;at-=4+n;if(!sxir_emit(v,&sxir_installer_name,at,n,end))return false;at-=12;if(!IR_ROW(lyme_member,at,end)||!IR_U(at,4,offset,end)||!IR_U(at+8,4,size,end)||!sxir_span(v,offset,size,at))return false;}return true;}
static bool sxir_solaris_zip(sxir_view*v)
{uint64_t end=v->c->size;if(!sxir_eq(v,0,"# PaCkAgE DaTaStReAm:zip\n",25,end)||!IR_ROW(solaris_zip_signature,0,end))return false;
 for(uint64_t at=512;at<=end&&end-at>=512;){if(!sxir_eq(v,at,"\x19\x9eTL",4,end)){at+=512;continue;}uint64_t n,count,body=at+512;if(!IR_U(at+4,4,n,end)||n<12||!sxir_span(v,body,n,end)||!IR_ROW(solaris_zip_object,at,end)||!sxir_eq(v,body,"\x19\x9eTG",4,body+n)||!IR_U(body+4,4,count,body+n)||!count||count>262144||!IR_ROW(solaris_zip_group,body,body+n)||!sxir_table(v,&sxir_solaris_zip_block,body+12,count,body+n))return false;uint64_t pad=(512-(n&511))&511;if(!sxir_span(v,body+n,pad,end))return false;at=body+n+pad;}return true;}
static bool sxir_superdat(sxir_view*v)
{uint64_t end=v->c->size,pe,cert,footer=0,at=0,count=0,declared=0;unsigned kind=3;bool found=false;if(!sxir_pe(v,0,end,&pe,&cert))return false;end=cert;
 if(end>=33){uint64_t begin=end>131072?end-131072:0,scan=begin,candidate;while(end-scan>=33&&sxir_find(v,scan,end,"_SUPERDAT_HEADER\0",17,false,&candidate)){uint64_t z,start,n;if(!IR_U(candidate+17,4,z,end)||!IR_U(candidate+21,4,start,end)||!IR_U(candidate+25,4,n,end))return false;unsigned k=n?0:1;if(!n&&!IR_U(candidate+29,4,n,end))return false;if(z&&n&&n<=65536&&start<=candidate&&sxir_span(v,candidate,k?37:33,end)){footer=candidate;declared=z;at=start;count=n;kind=k;found=true;}scan=candidate+1;}}
 if(!found&&end>=297&&sxir_eq(v,end-297,"_SUPERDAT_HEADER\0",17,end)){uint64_t zero;if(!IR_U(end-280,4,zero,end)||!IR_U(end-12,4,declared,end)||!IR_U(end-8,4,at,end)||!IR_U(end-4,4,count,end))return false;if(!zero&&declared&&count&&count<65536&&at<end-297){footer=end-297;kind=2;found=true;}}
 if(!found){if(end<8||!IR_U(end-4,4,declared,end)||declared<=17||declared>end-8)return false;footer=end-4;at=end-8-declared;kind=3;}
 if(!sxir_row(v,kind==0?&sxir_superdat_footer_v0:kind==1?&sxir_superdat_footer_v1:kind==2?&sxir_superdat_footer_v12:&sxir_superdat_original_footer,footer,end))return false;
 uint64_t last_group=0,members=0;for(unsigned groups=0;;groups++){if(groups>=8||!sxir_eq(v,at,"\xef\xbe\xad\xde",4,footer)||!IR_ROW(superdat_group,at,footer))return false;last_group=at;members=0;at+=4;
  while(!sxir_eq(v,at,"NAISIGN\0",8,footer)){uint64_t z,plain,actual;if(++members>65536||!sxir_eq(v,at,"__NAILZHUFLIB\0",14,footer)||!IR_U(at+274,4,plain,footer)||!IR_U(at+278,4,z,footer)||z<4||!IR_U(at+288,4,actual,footer)||plain!=actual||!IR_ROW(superdat_member,at,footer)||!IR_ROW(superdat_lh1_stream,at+288,footer)||!sxir_span(v,at+288,z,footer))return false;at+=288+z;}
  if(!members||!IR_ROW(superdat_group_trailer,at,footer))return false;at+=17;if(!sxir_eq(v,at,"\xef\xbe\xad\xde",4,end))break;}
 if(at-last_group-4!=declared)return false;if(kind==3)return at==footer;uint64_t stride=kind==2?170:178,bootstrap=kind==2?1:2;if(members!=count+bootstrap||at>footer||footer-at!=count*stride+(kind==1?12:0))return false;return sxir_table(v,kind==2?&sxir_superdat_manifest_170:&sxir_superdat_manifest_178,at,count,footer);}
static bool sxir_instalit(sxir_view*v)
{Abstractformat*f=v->c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->free_archive_records_reading)return false;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,v->c->pd);if(!s)return false;bool ok=true;uint64_t previous=0,count=0;
 while(s->has_record){const xx_archive_record*r=xx_format_get_current_archive_record(f,s);if(!r||r->data_offset<f->base_address||r->compressed_size<4){ok=false;break;}uint64_t at=(uint64_t)(r->data_offset-f->base_address),z=(uint64_t)r->compressed_size;uint64_t mode,bits;if(at<previous||++count>65536||!sxir_span(v,at,z,v->c->size)||!IR_U(at,1,mode,v->c->size)||mode>1||!IR_U(at+1,1,bits,v->c->size)||bits<4||bits>6||!IR_ROW(instalit_dcl_header,at,at+z)){ok=false;break;}previous=at+z;if(!xx_format_archive_record_move_to_next(f,s,v->c->pd))break;}
 xx_format_free_archive_records_reading(f,s);return ok&&count&&!xx_pd_is_stopped(v->c->pd);}
static bool sxir_softpaq4(sxir_view*v)
{uint64_t end=v->c->size,pages,last,image,at,flags;if(!sxir_eq(v,0,"MZ",2,end)||!IR_U(4,2,pages,end)||!pages||!IR_U(2,2,last,end)||last>511)return false;image=(pages-1)*512+(last?last:512);if(image>=end||!sxir_find(v,image,end<16777216?end:16777216,"!3PS",4,false,&at)||!IR_U(at+4,4,flags,end)||(flags!=0&&flags!=8)||!sxir_row(v,flags?&sxir_softpaq4_descriptor_8:&sxir_softpaq4_descriptor_0,at,end))return false;
 uint64_t first=flags?12:8,count=flags?5:4,previous=at+64;for(uint64_t i=0;i<count;i++){uint64_t z,off;if(!IR_U(at+first+8*i,4,z,end)||!IR_U(at+first+8*i+4,4,off,end)||off!=previous||!sxir_span(v,off,z,end))return false;previous=off+z;if(i==0||i>=count-2){uint64_t n;if(!z||!IR_U(off,1,n,end)||!n||n+1>=z||!IR_ROW(softpaq4_name_length,off,previous)||!sxir_emit(v,&sxir_installer_name,off+1,n,previous))return false;}else if(z&&!sxir_emit(v,&sxir_installer_name,off,z,previous))return false;}
 if(previous==end)return true;return end-previous==8&&sxir_eq(v,previous+4,"\x12\xef\xcd\xab",4,end)&&IR_ROW(softpaq4_footer,previous,end);}
static bool sxir_inftool(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert))return false;bool legacy=sxir_eq(v,at,"MRI",3,end);if(!legacy){uint64_t dll;if(!sxir_eq(v,at,"MZ",2,end)||!sxir_pe(v,at,end,&dll,&cert)||dll<=at)return false;at=dll;}uint64_t z=legacy?22:24,declared;if(!sxir_eq(v,at,"MRI\1",4,end)||!IR_U(at+(legacy?18:20),4,declared,end)||declared!=end||!sxir_row(v,legacy?&sxir_inftool_header_22:&sxir_inftool_header_24,at,end))return false;
 uint64_t p=at+z;const unsigned offsets[]={4,5,7,8,12};for(unsigned i=0;i<5;i++){uint64_t n;if(!IR_U(at+offsets[i],i<3?1:4,n,end)||!sxir_span(v,p,n,end))return false;if(i<3&&n&&!sxir_emit(v,&sxir_installer_name,p,n,end))return false;p+=n;}return sxir_span(v,p,36,end);}
static bool sxir_ad01(sxir_view*v)
{uint64_t end=v->c->size,extent,cert,pe,sections,opt;if(!sxir_eq(v,0,"MZ",2,end)||!sxir_pe(v,0,end,&extent,&cert)||!IR_U(60,4,pe,end)||!IR_U(pe+6,2,sections,end)||!IR_U(pe+20,2,opt,end))return false;
 for(uint64_t i=0;i<sections;i++){uint64_t s=pe+24+opt+40*i;if(!sxir_eq(v,s,"actdlvry",8,end))continue;uint64_t size,at,z;if(!IR_U(s+16,4,size,end)||!IR_U(s+20,4,at,end)||!sxir_span(v,at,size,end)||size<34||!sxir_eq(v,at,"AD01",4,at+size)||!IR_U(at+8,4,z,at+size)||z>size-12||!IR_ROW(active_delivery_header,at,at+size))return false;return true;}return false;}

static bool sx_installerremaining_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_NSIS:case XX_FILE_TYPE_BITROCK:case XX_FILE_TYPE_SMART_INSTALL_MAKER:case XX_FILE_TYPE_EXCELSIOR_INSTALLER:case XX_FILE_TYPE_NETOPSYSTEMS_FEAD:case XX_FILE_TYPE_SUPERDAT:case XX_FILE_TYPE_SOLARISPKG_ZIP:case XX_FILE_TYPE_DESKSOFT:case XX_FILE_TYPE_METAPRODUCTS:case XX_FILE_TYPE_VISUALWARE:case XX_FILE_TYPE_LYME_SFX:case XX_FILE_TYPE_INSTALIT_DATA:case XX_FILE_TYPE_SFX_AD01:case XX_FILE_TYPE_SFX_SOFTPAQ4:case XX_FILE_TYPE_SFX_INFTOOL:return true;default:return false;}}
static bool sx_installerremaining_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxir_view view={c,0},*v=&view;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_NSIS:ok=sxir_nsis(v);break;case XX_FILE_TYPE_BITROCK:ok=sxir_cookfs(v);break;case XX_FILE_TYPE_SMART_INSTALL_MAKER:ok=sxir_sim(v);break;case XX_FILE_TYPE_EXCELSIOR_INSTALLER:ok=sxir_excelsior(v);break;case XX_FILE_TYPE_NETOPSYSTEMS_FEAD:ok=sxir_fead(v);break;case XX_FILE_TYPE_SUPERDAT:ok=sxir_superdat(v);break;case XX_FILE_TYPE_SOLARISPKG_ZIP:ok=sxir_solaris_zip(v);break;case XX_FILE_TYPE_DESKSOFT:ok=sxir_desksoft(v);break;case XX_FILE_TYPE_METAPRODUCTS:ok=sxir_metaproducts(v);break;case XX_FILE_TYPE_VISUALWARE:ok=sxir_visualware(v);break;case XX_FILE_TYPE_LYME_SFX:ok=sxir_lyme(v);break;case XX_FILE_TYPE_INSTALIT_DATA:ok=sxir_instalit(v);break;case XX_FILE_TYPE_SFX_AD01:ok=sxir_ad01(v);break;case XX_FILE_TYPE_SFX_SOFTPAQ4:ok=sxir_softpaq4(v);break;case XX_FILE_TYPE_SFX_INFTOOL:ok=sxir_inftool(v);break;default:break;}return ok&&sxir_finish(c);}
#undef IR_ROW
#undef IR_U
