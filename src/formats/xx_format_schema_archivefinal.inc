/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivefinal_scope.txt. */
static const xx_data_struct_field_desc sxaf_nar_string_length_fields[] = {
 SX_FIELD("byte_length","uint64",0,8,SX_SIZE),
};
static const sx_layout sxaf_nar_string_length = {UINT32_C(0x603c0001),"nar_string_length",sxaf_nar_string_length_fields,SX_COUNT(sxaf_nar_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_manifest_prefix_fields[] = {
 SX_FIELD("manifest_size","uint32",0,4,SX_SIZE),
 SX_FIELD("file_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxaf_phar_manifest_prefix = {UINT32_C(0x603c0002),"phar_manifest_prefix",sxaf_phar_manifest_prefix_fields,SX_COUNT(sxaf_phar_manifest_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_api_version_fields[] = {
 SX_FIELD("api_version","uint16",0,2,SX_NONE),
};
static const sx_layout sxaf_phar_api_version = {UINT32_C(0x603c0003),"phar_api_version",sxaf_phar_api_version_fields,SX_COUNT(sxaf_phar_api_version_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_phar_manifest_flags_fields[] = {
 SX_FIELD("global_flags","uint32",0,4,SX_NONE),
 SX_FIELD("alias_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxaf_phar_manifest_flags = {UINT32_C(0x603c0004),"phar_manifest_flags",sxaf_phar_manifest_flags_fields,SX_COUNT(sxaf_phar_manifest_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_metadata_length_fields[] = {
 SX_FIELD("metadata_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxaf_phar_metadata_length = {UINT32_C(0x603c0005),"phar_metadata_length",sxaf_phar_metadata_length_fields,SX_COUNT(sxaf_phar_metadata_length_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_name_length_fields[] = {
 SX_FIELD("name_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxaf_phar_name_length = {UINT32_C(0x603c0006),"phar_name_length",sxaf_phar_name_length_fields,SX_COUNT(sxaf_phar_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_file_entry_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unix_timestamp","uint32",4,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",16,4,SX_NONE),
 SX_FIELD("metadata_size","uint32",20,4,SX_SIZE),
};
static const sx_layout sxaf_phar_file_entry = {UINT32_C(0x603c0007),"phar_file_entry",sxaf_phar_file_entry_fields,SX_COUNT(sxaf_phar_file_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_phar_signature_footer_fields[] = {
 SX_FIELD("signature_type","uint32",0,4,SX_NONE),
 SX_FIELD("magic","char[4]",4,4,SX_SIGNATURE),
};
static const sx_layout sxaf_phar_signature_footer = {UINT32_C(0x603c0008),"phar_signature_footer",sxaf_phar_signature_footer_fields,SX_COUNT(sxaf_phar_signature_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_stuffit_split_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("part_number","uint16",2,2,SX_NONE),
 SX_FIELD("name_size","uint8",4,1,SX_SIZE),
 SX_FIELD("file_name","char[63]",5,63,SX_NONE),
 SX_FIELD("file_type","char[4]",68,4,SX_NONE),
 SX_FIELD("creator","char[4]",72,4,SX_NONE),
 SX_FIELD("finder_flags","uint16",76,2,SX_NONE),
 SX_FIELD("creation_time","uint32",78,4,SX_NONE),
 SX_FIELD("modification_time","uint32",82,4,SX_NONE),
 SX_FIELD("resource_fork_size","uint32",86,4,SX_SIZE),
 SX_FIELD("data_fork_size","uint32",90,4,SX_SIZE),
 SX_FIELD("segment_bookkeeping","uint8[6]",94,6,SX_NONE),
};
static const sx_layout sxaf_stuffit_split_header = {UINT32_C(0x603c0009),"stuffit_split_header",sxaf_stuffit_split_header_fields,SX_COUNT(sxaf_stuffit_split_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_squeeze1_header_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
};
static const sx_layout sxaf_squeeze1_header = {UINT32_C(0x603c000a),"squeeze1_header",sxaf_squeeze1_header_fields,SX_COUNT(sxaf_squeeze1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_squeeze2_magic_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxaf_squeeze2_magic = {UINT32_C(0x603c000b),"squeeze2_magic",sxaf_squeeze2_magic_fields,SX_COUNT(sxaf_squeeze2_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_squeeze2_header_fields[] = {
 SX_FIELD("empty_field","uint8",0,1,SX_NONE),
 SX_FIELD("end_of_text","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("dos_time","uint16",6,2,SX_NONE),
 SX_FIELD("node_count","uint16",8,2,SX_COUNT_PROP),
};
static const sx_layout sxaf_squeeze2_header = {UINT32_C(0x603c000c),"squeeze2_header",sxaf_squeeze2_header_fields,SX_COUNT(sxaf_squeeze2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_squeeze_node_count_fields[] = {
 SX_FIELD("node_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxaf_squeeze_node_count = {UINT32_C(0x603c000d),"squeeze_node_count",sxaf_squeeze_node_count_fields,SX_COUNT(sxaf_squeeze_node_count_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_squeeze_tree_node_fields[] = {
 SX_FIELD("left_child","int16",0,2,SX_NONE),
 SX_FIELD("right_child","int16",2,2,SX_NONE),
};
static const sx_layout sxaf_squeeze_tree_node = {UINT32_C(0x603c000e),"squeeze_tree_node",sxaf_squeeze_tree_node_fields,SX_COUNT(sxaf_squeeze_tree_node_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_sq_magic_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxaf_sq_magic = {UINT32_C(0x603c000f),"sq_magic",sxaf_sq_magic_fields,SX_COUNT(sxaf_sq_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_sq_calendar_fields[] = {
 SX_FIELD("month","uint8",0,1,SX_NONE),
 SX_FIELD("day","uint8",1,1,SX_NONE),
 SX_FIELD("year_since_1980","uint8",2,1,SX_NONE),
 SX_FIELD("hour","uint8",3,1,SX_NONE),
 SX_FIELD("minute","uint8",4,1,SX_NONE),
 SX_FIELD("two_second_count","uint8",5,1,SX_NONE),
};
static const sx_layout sxaf_sq_calendar = {UINT32_C(0x603c0010),"sq_calendar",sxaf_sq_calendar_fields,SX_COUNT(sxaf_sq_calendar_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_lspack10_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("flags","uint16",6,2,SX_NONE),
 SX_FIELD("method","uint16",8,2,SX_NONE),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","int32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",22,4,SX_SIZE),
 SX_FIELD("reserved0","uint16",26,2,SX_NONE),
 SX_FIELD("reserved1","uint16",28,2,SX_NONE),
 SX_FIELD("reserved2","uint16",30,2,SX_NONE),
 SX_FIELD("reserved3","uint32",32,4,SX_NONE),
 SX_FIELD("name_size","uint16",36,2,SX_SIZE),
 SX_FIELD("path_size","uint16",38,2,SX_SIZE),
};
static const sx_layout sxaf_lspack10_member = {UINT32_C(0x603c0011),"lspack10_member",sxaf_lspack10_member_fields,SX_COUNT(sxaf_lspack10_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_rnca_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("first_member_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("directory_checkword","uint16",6,2,SX_SIGNATURE),
 SX_FIELD("first_member_offset_copy","uint16",8,2,SX_OFFSET),
 SX_FIELD("reserved","uint8",10,1,SX_NONE),
};
static const sx_layout sxaf_rnca_header = {UINT32_C(0x603c0012),"rnca_header",sxaf_rnca_header_fields,SX_COUNT(sxaf_rnca_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_rnca_directory_offset_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxaf_rnca_directory_offset = {UINT32_C(0x603c0013),"rnca_directory_offset",sxaf_rnca_directory_offset_fields,SX_COUNT(sxaf_rnca_directory_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_rnca_stored_member_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("method","uint8",3,1,SX_NONE),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxaf_rnca_stored_member = {UINT32_C(0x603c0014),"rnca_stored_member",sxaf_rnca_stored_member_fields,SX_COUNT(sxaf_rnca_stored_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_rnca_compressed_member_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("method","uint8",3,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_crc16","uint16",12,2,SX_CHECKSUM),
 SX_FIELD("compressed_crc16","uint16",14,2,SX_CHECKSUM),
 SX_FIELD("leeway","uint8",16,1,SX_NONE),
 SX_FIELD("chunk_count","uint8",17,1,SX_COUNT_PROP),
};
static const sx_layout sxaf_rnca_compressed_member = {UINT32_C(0x603c0015),"rnca_compressed_member",sxaf_rnca_compressed_member_fields,SX_COUNT(sxaf_rnca_compressed_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_bagf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("positive_word","int32",8,4,SX_NONE),
 SX_FIELD("opaque_words","uint8[20]",12,20,SX_NONE),
 SX_FIELD("class_word0","uint32",32,4,SX_NONE),
 SX_FIELD("class_word1","uint32",36,4,SX_NONE),
 SX_FIELD("payload_size","uint32",40,4,SX_SIZE),
 SX_FIELD("name_size","uint8",44,1,SX_SIZE),
 SX_FIELD("name","char[15]",45,15,SX_NONE),
 SX_FIELD("description_size","uint8",60,1,SX_SIZE),
 SX_FIELD("description","char[51]",61,51,SX_NONE),
};
static const sx_layout sxaf_bagf_header = {UINT32_C(0x603c0016),"bagf_header",sxaf_bagf_header_fields,SX_COUNT(sxaf_bagf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_ixa_header_fields[] = {
 SX_FIELD("signature","char[9]",0,9,SX_SIGNATURE),
 SX_FIELD("title","char[31]",9,31,SX_NONE),
 SX_FIELD("fixed_word","uint32",40,4,SX_NONE),
 SX_FIELD("version","uint32",44,4,SX_NONE),
 SX_FIELD("slot_count_plus_one","uint32",48,4,SX_NONE),
 SX_FIELD("table_end_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("auxiliary_block_size","uint32",56,4,SX_SIZE),
 SX_FIELD("unknown_word","uint32",60,4,SX_NONE),
};
static const sx_layout sxaf_ixa_header = {UINT32_C(0x603c0017),"ixa_header",sxaf_ixa_header_fields,SX_COUNT(sxaf_ixa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_ixa_entry_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxaf_ixa_entry = {UINT32_C(0x603c0018),"ixa_entry",sxaf_ixa_entry_fields,SX_COUNT(sxaf_ixa_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_bga_member_fields[] = {
 SX_FIELD("header_checksum","int32",0,4,SX_CHECKSUM),
 SX_FIELD("method","char[4]",4,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",16,2,SX_NONE),
 SX_FIELD("dos_time","uint16",18,2,SX_NONE),
 SX_FIELD("attributes","uint8",20,1,SX_NONE),
 SX_FIELD("header_type","uint8",21,1,SX_NONE),
 SX_FIELD("archive_type","uint16",22,2,SX_NONE),
 SX_FIELD("directory_name_size","uint16",24,2,SX_SIZE),
 SX_FIELD("file_name_size","uint16",26,2,SX_SIZE),
};
static const sx_layout sxaf_bga_member = {UINT32_C(0x603c0019),"bga_member",sxaf_bga_member_fields,SX_COUNT(sxaf_bga_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_dfc_header_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("version","uint16",2,2,SX_NONE),
};
static const sx_layout sxaf_dfc_header = {UINT32_C(0x603c001a),"dfc_header",sxaf_dfc_header_fields,SX_COUNT(sxaf_dfc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_dfc_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("payload_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",17,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",21,4,SX_SIZE),
 SX_FIELD("complemented_crc32","uint32",25,4,SX_CHECKSUM),
 SX_FIELD("opaque_word","uint16",29,2,SX_NONE),
 SX_FIELD("method","uint8",31,1,SX_NONE),
 SX_FIELD("opaque_tail","uint8[3]",32,3,SX_NONE),
};
static const sx_layout sxaf_dfc_entry = {UINT32_C(0x603c001b),"dfc_entry",sxaf_dfc_entry_fields,SX_COUNT(sxaf_dfc_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_ka_header_fields[] = {
 SX_FIELD("signature","char[11]",0,11,SX_SIGNATURE),
 SX_FIELD("reserved","uint8[9]",11,9,SX_NONE),
 SX_FIELD("member_count","uint16",20,2,SX_COUNT_PROP),
};
static const sx_layout sxaf_ka_header = {UINT32_C(0x603c001c),"ka_header",sxaf_ka_header_fields,SX_COUNT(sxaf_ka_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_ka_entry_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("payload_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",17,4,SX_SIZE),
};
static const sx_layout sxaf_ka_entry = {UINT32_C(0x603c001d),"ka_entry",sxaf_ka_entry_fields,SX_COUNT(sxaf_ka_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_cdaf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("form_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",8,4,SX_SIGNATURE),
 SX_FIELD("name_chunk","char[4]",12,4,SX_SIGNATURE),
 SX_FIELD("name_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name","char[6]",20,6,SX_NONE),
};
static const sx_layout sxaf_cdaf_header = {UINT32_C(0x603c001e),"cdaf_header",sxaf_cdaf_header_fields,SX_COUNT(sxaf_cdaf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_cdaf_member_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("opaque0","uint8",8,1,SX_NONE),
 SX_FIELD("method","uint8",9,1,SX_NONE),
 SX_FIELD("opaque1","uint8[4]",10,4,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",14,4,SX_SIZE),
 SX_FIELD("opaque2","uint8[6]",18,6,SX_NONE),
 SX_FIELD("crc16","uint16",24,2,SX_CHECKSUM),
 SX_FIELD("opaque3","uint8[2]",26,2,SX_NONE),
};
static const sx_layout sxaf_cdaf_member = {UINT32_C(0x603c001f),"cdaf_member",sxaf_cdaf_member_fields,SX_COUNT(sxaf_cdaf_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_cdaf_chunk_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxaf_cdaf_chunk = {UINT32_C(0x603c0020),"cdaf_chunk",sxaf_cdaf_chunk_fields,SX_COUNT(sxaf_cdaf_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_spack_magic_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxaf_spack_magic = {UINT32_C(0x603c0021),"spack_magic",sxaf_spack_magic_fields,SX_COUNT(sxaf_spack_magic_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_spack_stored_member_fields[] = {
 SX_FIELD("tag","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("id_and_flags","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxaf_spack_stored_member = {UINT32_C(0x603c0022),"spack_stored_member",sxaf_spack_stored_member_fields,SX_COUNT(sxaf_spack_stored_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_spack_compressed_member_fields[] = {
 SX_FIELD("tag","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("id_and_flags","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc16","uint16",12,2,SX_CHECKSUM),
};
static const sx_layout sxaf_spack_compressed_member = {UINT32_C(0x603c0023),"spack_compressed_member",sxaf_spack_compressed_member_fields,SX_COUNT(sxaf_spack_compressed_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_spack_footer_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("index_record_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxaf_spack_footer = {UINT32_C(0x603c0024),"spack_footer",sxaf_spack_footer_fields,SX_COUNT(sxaf_spack_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_pcompress_magic_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxaf_pcompress_magic = {UINT32_C(0x603c0025),"pcompress_magic",sxaf_pcompress_magic_fields,SX_COUNT(sxaf_pcompress_magic_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_pcompress_member_size_fields[] = {
 SX_FIELD("name_terminator","uint8",0,1,SX_NONE),
 SX_FIELD("member_block_size","uint32",1,4,SX_SIZE),
};
static const sx_layout sxaf_pcompress_member_size = {UINT32_C(0x603c0026),"pcompress_member_size",sxaf_pcompress_member_size_fields,SX_COUNT(sxaf_pcompress_member_size_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_pcompress_lh_block_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",2,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("raw_crc32","uint32",10,4,SX_CHECKSUM),
};
static const sx_layout sxaf_pcompress_lh_block = {UINT32_C(0x603c0027),"pcompress_lh_block",sxaf_pcompress_lh_block_fields,SX_COUNT(sxaf_pcompress_lh_block_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_mxm_simplearc_member_fields[] = {
 SX_FIELD("next_record_delta","uint32",0,4,SX_OFFSET),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
 SX_FIELD("name","char[16]",8,16,SX_NONE),
};
static const sx_layout sxaf_mxm_simplearc_member = {UINT32_C(0x603c0028),"mxm_simplearc_member",sxaf_mxm_simplearc_member_fields,SX_COUNT(sxaf_mxm_simplearc_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_lif_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_NONE),
 SX_FIELD("positive_word","uint16",4,2,SX_NONE),
 SX_FIELD("name","char[15]",6,15,SX_NONE),
 SX_FIELD("file_size","uint32",21,4,SX_SIZE),
 SX_FIELD("method","uint32",25,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",29,4,SX_SIZE),
 SX_FIELD("reserved","uint32",33,4,SX_NONE),
 SX_FIELD("dos_date","uint16",37,2,SX_NONE),
 SX_FIELD("dos_time","uint16",39,2,SX_NONE),
};
static const sx_layout sxaf_lif_header = {UINT32_C(0x603c0029),"lif_header",sxaf_lif_header_fields,SX_COUNT(sxaf_lif_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_dn_data_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque_prefix","uint8[14]",4,14,SX_NONE),
 SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("opaque_word","uint16",26,2,SX_NONE),
 SX_FIELD("name_size","uint16",28,2,SX_SIZE),
};
static const sx_layout sxaf_dn_data_header = {UINT32_C(0x603c002a),"dn_data_header",sxaf_dn_data_header_fields,SX_COUNT(sxaf_dn_data_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_dn_directory_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque_prefix","uint8[26]",4,26,SX_NONE),
 SX_FIELD("name_size","uint16",30,2,SX_SIZE),
 SX_FIELD("opaque_tail","uint8[10]",32,10,SX_NONE),
 SX_FIELD("data_header_offset","uint32",42,4,SX_OFFSET),
};
static const sx_layout sxaf_dn_directory_header = {UINT32_C(0x603c002b),"dn_directory_header",sxaf_dn_directory_header_fields,SX_COUNT(sxaf_dn_directory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_dn_end_marker_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxaf_dn_end_marker = {UINT32_C(0x603c002c),"dn_end_marker",sxaf_dn_end_marker_fields,SX_COUNT(sxaf_dn_end_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_insa_version_fields[] = {
 SX_FIELD("version","uint16",0,2,SX_NONE),
};
static const sx_layout sxaf_insa_version = {UINT32_C(0x603c002d),"insa_version",sxaf_insa_version_fields,SX_COUNT(sxaf_insa_version_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_insa_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxaf_insa_member = {UINT32_C(0x603c002e),"insa_member",sxaf_insa_member_fields,SX_COUNT(sxaf_insa_member_fields),SX_LE};
static const sx_layout *const sx_archivefinal_layouts[] = {
 &sxaf_nar_string_length,
 &sxaf_phar_manifest_prefix,
 &sxaf_phar_api_version,
 &sxaf_phar_manifest_flags,
 &sxaf_phar_metadata_length,
 &sxaf_phar_name_length,
 &sxaf_phar_file_entry,
 &sxaf_phar_signature_footer,
 &sxaf_stuffit_split_header,
 &sxaf_squeeze1_header,
 &sxaf_squeeze2_magic,
 &sxaf_squeeze2_header,
 &sxaf_squeeze_node_count,
 &sxaf_squeeze_tree_node,
 &sxaf_sq_magic,
 &sxaf_sq_calendar,
 &sxaf_lspack10_member,
 &sxaf_rnca_header,
 &sxaf_rnca_directory_offset,
 &sxaf_rnca_stored_member,
 &sxaf_rnca_compressed_member,
 &sxaf_bagf_header,
 &sxaf_ixa_header,
 &sxaf_ixa_entry,
 &sxaf_bga_member,
 &sxaf_dfc_header,
 &sxaf_dfc_entry,
 &sxaf_ka_header,
 &sxaf_ka_entry,
 &sxaf_cdaf_header,
 &sxaf_cdaf_member,
 &sxaf_cdaf_chunk,
 &sxaf_spack_magic,
 &sxaf_spack_stored_member,
 &sxaf_spack_compressed_member,
 &sxaf_spack_footer,
 &sxaf_pcompress_magic,
 &sxaf_pcompress_member_size,
 &sxaf_pcompress_lh_block,
 &sxaf_mxm_simplearc_member,
 &sxaf_lif_header,
 &sxaf_dn_data_header,
 &sxaf_dn_directory_header,
 &sxaf_dn_end_marker,
 &sxaf_insa_version,
 &sxaf_insa_member,
};
static bool sx_archivefinal_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x603c0000U||id>=0x603d0000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x603c0001U:
 if(!xx_rt_wcscmp(r->name,L"byte_length"))text=L"NAR string byte length; following bytes are padded to an8-byte boundary.";
 break;
 case 0x603c0003U:
 if(!xx_rt_wcscmp(r->name,L"api_version"))text=L"Three big-endian version nibbles: major/minor/patch, followed by zero nibble.";
 break;
 case 0x603c0004U:
 if(!xx_rt_wcscmp(r->name,L"global_flags"))text=L"0x10000 signature present; other unused bits reserved.";
 break;
 case 0x603c0007U:
 if(!xx_rt_wcscmp(r->name,L"unix_timestamp"))text=L"Seconds since1970-01-01.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Low9bits permissions;0x1000 DEFLATE;0x2000 BZIP2.";
 break;
 case 0x603c0008U:
 if(!xx_rt_wcscmp(r->name,L"signature_type"))text=L"1 MD5,2 SHA1,3 SHA256,4 SHA512,16 OpenSSL.";
 break;
 case 0x603c0009U:
 if(!xx_rt_wcscmp(r->name,L"part_number"))text=L"One-based segment number.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01.";
 if(!xx_rt_wcscmp(r->name,L"resource_fork_size"))text=L"Whole original resource fork, not this segment.";
 if(!xx_rt_wcscmp(r->name,L"data_fork_size"))text=L"Whole original data fork, not this segment.";
 if(!xx_rt_wcscmp(r->name,L"segment_bookkeeping"))text=L"Stored bookkeeping bytes; semantics not established.";
 break;
 case 0x603c000aU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of decoded bytes modulo65536.";
 break;
 case 0x603c000cU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of decoded bytes modulo65536.";
 if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date: year since1980/month/day.";
 if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time: hour/minute/2-second count.";
 break;
 case 0x603c000eU:
 if(!xx_rt_wcscmp(r->name,L"left_child"))text=L"Nonnegative node index; negative value encodes symbol=-(value+1),256=end.";
 if(!xx_rt_wcscmp(r->name,L"right_child"))text=L"Nonnegative node index; negative value encodes symbol=-(value+1),256=end.";
 break;
 case 0x603c0011U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored;2 raw DEFLATE.";
 if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time.";
 if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date.";
 break;
 case 0x603c0012U:
 if(!xx_rt_wcscmp(r->name,L"directory_checkword"))text=L"Stored checkword; native reader does not validate its algorithm.";
 break;
 case 0x603c0015U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"RNC method1 or2.";
 break;
 case 0x603c0016U:
 if(!xx_rt_wcscmp(r->name,L"positive_word"))text=L"Native reader requires positive; meaning is unknown.";
 if(!xx_rt_wcscmp(r->name,L"class_word0"))text=L"Observed selector; semantics unknown.";
 if(!xx_rt_wcscmp(r->name,L"class_word1"))text=L"Observed selector; semantics unknown.";
 break;
 case 0x603c0017U:
 if(!xx_rt_wcscmp(r->name,L"fixed_word"))text=L"Native requires0x30; further semantics are not established.";
 if(!xx_rt_wcscmp(r->name,L"slot_count_plus_one"))text=L"Directory row count is this value minus one.";
 break;
 case 0x603c0019U:
 if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"Sum of signed header/name bytes starting at offset4.";
 if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date.";
 if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time.";
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"0x10 directory.";
 if(!xx_rt_wcscmp(r->name,L"archive_type"))text=L"1 compressed,2 stored,0 autodetect based on length and suffix.";
 break;
 case 0x603c001bU:
 if(!xx_rt_wcscmp(r->name,L"complemented_crc32"))text=L"Bitwise complement of the plaintext standard CRC32.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 PKWARE DCL;1 stored.";
 break;
 case 0x603c001eU:
 if(!xx_rt_wcscmp(r->name,L"form_size"))text=L"Complete file size minus8.";
 break;
 case 0x603c001fU:
 if(!xx_rt_wcscmp(r->name,L"header_payload_size"))text=L"Name length plus20; excludes8-byte chunk prefix.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored;1..7 Shrink arithmetic/LZ.";
 break;
 case 0x603c0022U:
 if(!xx_rt_wcscmp(r->name,L"id_and_flags"))text=L"0x8000 stored;low15bits member ID.";
 break;
 case 0x603c0026U:
 if(!xx_rt_wcscmp(r->name,L"name_terminator"))text=L"Newline delimiter.";
 break;
 case 0x603c0027U:
 if(!xx_rt_wcscmp(r->name,L"raw_crc32"))text=L"CRC32 of packed bytes with initial state zero, no complement.";
 break;
 case 0x603c0028U:
 if(!xx_rt_wcscmp(r->name,L"next_record_delta"))text=L"Relative to current header;zero means final member.";
 break;
 case 0x603c0029U:
 if(!xx_rt_wcscmp(r->name,L"positive_word"))text=L"Native requires nonzero; semantics unknown.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"6 Zoo LZD.";
 break;
 case 0x603c002aU:
 if(!xx_rt_wcscmp(r->name,L"opaque_prefix"))text=L"Uninterpreted physical header bytes.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAF_LIMIT 20000U
static bool sxaf_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxaf_read(sx_context*c,uint64_t p,void*b,size_t n){return sxaf_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxaf_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxaf_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxaf_read(c,p,b,n))return false;*v=sxaf_uint(b,n,be);return true;}
static bool sxaf_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];int64_t n=f->rel_offset+f->size;return c->count<SXAF_LIMIT&&sxaf_span(c,p,(uint64_t)n)&&sx_add(c,l,(int64_t)p,n);}
static bool sxaf_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap,uint8_t stop){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxaf_read(c,(*p)++,&b,1))return false;if(b==stop)return true;}return false;}
static bool sxaf_nar(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint64_t n;if(!sxaf_word(c,p,8,false,&n)||!sxaf_span(c,p+8,n)||!sxaf_add(c,&sxaf_nar_string_length,p))return false;p+=8+n;uint64_t pad=(8-(n&7))&7;if(!sxaf_span(c,p,pad))return false;p+=pad;}return true;}
static bool sxaf_phar(sx_context*c){uint64_t p=0,limit=(uint64_t)c->size<8388608?(uint64_t)c->size:8388608;uint8_t b[4113];bool found=false;
 for(uint64_t block=0;block<limit&&!found;block+=4096){size_t nr=(size_t)(limit-block);if(nr>sizeof(b))nr=sizeof(b);if(!sxaf_read(c,block,b,nr))return false;for(size_t i=0;i+18<=nr&&i<4096;i++){if(!xx_rt_memcmp(b+i,"__HALT_COMPILER();",18)){p=block+i+18;found=true;break;}}}if(!found)return false;uint8_t tail[8];size_t n=(uint64_t)c->size-p<8?(size_t)((uint64_t)c->size-p):8;if(!sxaf_read(c,p,tail,n))return false;size_t skip=0;while(skip<n&&(tail[skip]==' '||tail[skip]=='\t'))skip++;if(skip+2<=n&&tail[skip]=='?'&&tail[skip+1]=='>')skip+=2;if(skip+2<=n&&tail[skip]=='\r'&&tail[skip+1]=='\n')skip+=2;else if(skip<n&&tail[skip]=='\n')skip++;p+=skip;
 uint64_t size,count,alias,meta,flags;if(!sxaf_word(c,p,4,false,&size)||!sxaf_span(c,p+4,size)||!sxaf_word(c,p+4,4,false,&count)||!sxaf_word(c,p+14,4,false,&alias)||!sxaf_word(c,p+10,4,false,&flags)||!sxaf_add(c,&sxaf_phar_manifest_prefix,p)||!sxaf_add(c,&sxaf_phar_api_version,p+8)||!sxaf_add(c,&sxaf_phar_manifest_flags,p+10))return false;uint64_t end=p+4+size,q=p+18,data=end;if(q>end||alias>end-q)return false;q+=alias;if(end-q<4||!sxaf_word(c,q,4,false,&meta)||!sxaf_add(c,&sxaf_phar_metadata_length,q))return false;q+=4;if(meta>end-q)return false;q+=meta;
 for(uint64_t i=0;i<count;i++){uint64_t name,packed;if(end-q<4||!sxaf_word(c,q,4,false,&name)||!sxaf_add(c,&sxaf_phar_name_length,q))return false;q+=4;if(name>end-q)return false;q+=name;if(end-q<24||!sxaf_word(c,q+20,4,false,&meta)||!sxaf_word(c,q+8,4,false,&packed)||!sxaf_add(c,&sxaf_phar_file_entry,q))return false;q+=24;if(!sxaf_span(c,data,packed))return false;data+=packed;if(meta>end-q)return false;q+=meta;}
 if((flags&0x10000)&&c->size>=8&&data<=(uint64_t)c->size-8&&sxaf_read(c,(uint64_t)c->size-4,b,4)&&!xx_rt_memcmp(b,"GBMB",4)){uint64_t kind;if(!sxaf_word(c,(uint64_t)c->size-8,4,false,&kind))return false;uint64_t signature_size=kind==1?16:kind==2?20:kind==3?32:kind==4?64:0;if(signature_size&&(uint64_t)c->size-8-data==signature_size)return sxaf_add(c,&sxaf_phar_signature_footer,(uint64_t)c->size-8);}return true;}
static bool sxaf_squeeze(sx_context*c,bool second){uint64_t p=second?2:4,n;if(!sxaf_add(c,second?&sxaf_squeeze2_magic:&sxaf_squeeze1_header,0)||!sxaf_zstr(c,&p,(uint64_t)c->size,256,0))return false;if(second){if(!sxaf_zstr(c,&p,(uint64_t)c->size,256,0)||!sxaf_word(c,p+8,2,false,&n)||!sxaf_add(c,&sxaf_squeeze2_header,p))return false;p+=10;}else{if(!sxaf_word(c,p,2,false,&n)||!sxaf_add(c,&sxaf_squeeze_node_count,p))return false;p+=2;}if(n>256||!sxaf_span(c,p,4*n))return false;for(uint64_t i=0;i<n;i++)if(!sxaf_add(c,&sxaf_squeeze_tree_node,p+4*i))return false;return true;}
static bool sxaf_sq(sx_context*c){uint64_t p=4;return sxaf_add(c,&sxaf_sq_magic,0)&&sxaf_zstr(c,&p,(uint64_t)c->size,256,0)&&sxaf_add(c,&sxaf_sq_calendar,p);}
static bool sxaf_lspack(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint8_t b[40];if(!sxaf_read(c,p,b,40)||xx_rt_memcmp(b,"FL\3\4",4)||!sxaf_add(c,&sxaf_lspack10_member,p))return false;uint64_t n=sxaf_uint(b+18,4,false),names=sxaf_uint(b+36,2,false)+sxaf_uint(b+38,2,false);p+=40;if(!sxaf_span(c,p,names)||!sxaf_span(c,p+names,n))return false;p+=names+n;}return true;}
static bool sxaf_rnca(sx_context*c){uint64_t end,p=11;if(!sxaf_word(c,4,2,true,&end)||end<12||!sxaf_span(c,0,end)||!sxaf_add(c,&sxaf_rnca_header,0))return false;while(p<end){uint8_t b;if(!sxaf_read(c,p,&b,1))return false;if(!b)break;if(!sxaf_zstr(c,&p,end,256,0)||end-p<4)return false;uint64_t off;if(!sxaf_word(c,p,4,true,&off)||!sxaf_add(c,&sxaf_rnca_directory_offset,p))return false;p+=4;uint8_t h[4];if(sxaf_read(c,off,h,4)&&!xx_rt_memcmp(h,"RNC",3)){const sx_layout*l=h[3]?&sxaf_rnca_compressed_member:&sxaf_rnca_stored_member;if(!sxaf_add(c,l,off))return false;}}return true;}
static bool sxaf_ixa(sx_context*c){uint64_t count,end;if(!sxaf_word(c,48,4,false,&count)||!count||!sxaf_word(c,52,4,false,&end)||end<64||count-1>(end-64)/12||!sxaf_span(c,0,end)||!sxaf_add(c,&sxaf_ixa_header,0))return false;for(uint64_t i=0;i<count-1;i++)if(!sxaf_add(c,&sxaf_ixa_entry,64+i*12))return false;return true;}
static bool sxaf_bga(sx_context*c){uint64_t p=0;while(sxaf_span(c,p,28)){uint8_t b[28];if(!sxaf_read(c,p,b,28))return false;uint64_t n=sxaf_uint(b+8,4,false),names=sxaf_uint(b+24,2,false)+sxaf_uint(b+26,2,false);if(!names||names>1024||!sxaf_span(c,p+28,names)||((xx_rt_memcmp(b+4,"GZIP",4))&&(xx_rt_memcmp(b+4,"BZ2\0",4))))return false;uint8_t name[1024];if(!sxaf_read(c,p+28,name,(size_t)names))return false;int32_t sum=0;for(unsigned i=4;i<28;i++)sum+=(b[i]&128)?(int32_t)b[i]-256:b[i];for(uint64_t i=0;i<names;i++)sum+=(name[i]&128)?(int32_t)name[i]-256:name[i];if((uint32_t)sum!=(uint32_t)sxaf_uint(b,4,false)||!sxaf_add(c,&sxaf_bga_member,p))return false;p+=28+names;if(!sxaf_span(c,p,n))return false;p+=n;}return true;}
static bool sxaf_table(sx_context*c,const sx_layout*h,const sx_layout*entry,uint64_t off,unsigned width,uint64_t p,uint64_t stride){uint64_t count;if(!sxaf_word(c,off,width,false,&count)||!sxaf_span(c,p,count*stride)||!sxaf_add(c,h,0))return false;for(uint64_t i=0;i<count;i++)if(!sxaf_add(c,entry,p+i*stride))return false;return true;}
static bool sxaf_cdaf(sx_context*c){uint64_t p=26;if(!sxaf_add(c,&sxaf_cdaf_header,0))return false;while(p<(uint64_t)c->size){uint64_t hs,n;uint8_t b[4];if(!sxaf_word(c,p+4,4,true,&hs)||hs<20||hs>65535||!sxaf_add(c,&sxaf_cdaf_member,p))return false;hs-=20;p+=28;if(!sxaf_span(c,p,hs+(hs&1)))return false;p+=hs+(hs&1);if(!sxaf_read(c,p,b,4))return false;if(!xx_rt_memcmp(b,"NOTE",4)){if(!sxaf_word(c,p+4,4,true,&n)||!sxaf_span(c,p+8,n+(n&1))||!sxaf_add(c,&sxaf_cdaf_chunk,p))return false;p+=8+n+(n&1);}if(!sxaf_read(c,p,b,4)||xx_rt_memcmp(b,"BODY",4)||!sxaf_word(c,p+4,4,true,&n)||!sxaf_span(c,p+8,n+(n&1))||!sxaf_add(c,&sxaf_cdaf_chunk,p))return false;p+=8+n+(n&1);}return true;}
static bool sxaf_spack(sx_context*c){uint64_t start=0,footer,n,index;uint8_t b[14];if(!sxaf_read(c,0,b,4))return false;if(sxaf_uint(b,4,true)==0x3f3){uint8_t x;if(!sxaf_read(c,47,&x,1))return false;start=x==0xf4?6624:6616;}if(c->size<12||!sxaf_read(c,(uint64_t)c->size-12,b,4))return false;footer=(uint64_t)c->size-12;if(xx_rt_memcmp(b,"INDX",4)){footer=(uint64_t)c->size-8;if(!sxaf_read(c,footer,b,4)||xx_rt_memcmp(b,"INDX",4))return false;}if(!sxaf_word(c,footer+4,4,true,&n)||n<14||n>footer||footer-n<start+4||!sxaf_add(c,&sxaf_spack_magic,start)||!sxaf_add(c,&sxaf_spack_footer,footer))return false;index=footer-n;if(!sxaf_add(c,&sxaf_spack_compressed_member,index))return false;for(uint64_t p=start+4;p<index;){if(index-p<8||!sxaf_read(c,p,b,8))return false;uint64_t flag=sxaf_uint(b+2,2,true),size=sxaf_uint(b+4,4,true),hs=8;const sx_layout*l=&sxaf_spack_stored_member;if(!(flag&0x8000)){hs=14;l=&sxaf_spack_compressed_member;if(index-p<14||!sxaf_word(c,p+8,4,true,&size))return false;}if(size>index-p-hs||!sxaf_add(c,l,p))return false;p+=hs+size;}return true;}
static bool sxaf_pcompress(sx_context*c){uint64_t p=4;if(!sxaf_add(c,&sxaf_pcompress_magic,0))return false;while(p<(uint64_t)c->size){if(!sxaf_zstr(c,&p,(uint64_t)c->size,91,'\n'))return false;p--;uint64_t n;if(!sxaf_word(c,p+1,4,true,&n)||!sxaf_span(c,p+5,n)||!sxaf_add(c,&sxaf_pcompress_member_size,p))return false;p+=5;uint8_t b[14];if(n>14&&sxaf_read(c,p,b,14)&&b[0]=='L'&&b[1]=='H'&&!b[2]&&!b[6]&&!sxaf_add(c,&sxaf_pcompress_lh_block,p))return false;p+=n;}return true;}
static bool sxaf_mxm(sx_context*c){uint64_t p=0x264;while(sxaf_span(c,p,24)){uint8_t b[24];if(!sxaf_read(c,p,b,24)||!sxaf_add(c,&sxaf_mxm_simplearc_member,p))return false;uint64_t next=sxaf_uint(b,4,true),n=sxaf_uint(b+4,4,true);if(!b[8]||!next)return true;if(next<24||n>next-24||!sxaf_span(c,p,next))return false;p+=next;}return false;}
static bool sxaf_dn(sx_context*c){uint64_t p=0;while(sxaf_span(c,p,4)){uint8_t b[46];if(!sxaf_read(c,p,b,4)||b[0]!=0x84||b[1]!=0x8d)return false;uint64_t hs,n=0,names;if(b[2]==1&&b[3]==2){hs=30;if(!sxaf_read(c,p,b,30))return false;n=sxaf_uint(b+18,4,false);names=sxaf_uint(b+28,2,false);if(!sxaf_add(c,&sxaf_dn_data_header,p))return false;}else if(b[2]==3&&b[3]==4){hs=46;if(!sxaf_read(c,p,b,46))return false;names=sxaf_uint(b+30,2,false);if(!sxaf_add(c,&sxaf_dn_directory_header,p))return false;}else if(b[2]==5&&b[3]==6)return sxaf_add(c,&sxaf_dn_end_marker,p);else return false;p+=hs;if(!sxaf_span(c,p,names)||!sxaf_span(c,p+names,n))return false;p+=names+n;}return true;}
static bool sxaf_insa(sx_context*c){if(!sxaf_add(c,&sxaf_insa_version,0))return false;if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;for(unsigned i=0;i<1024;i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>=c->f->base_address&&r->header_size==4&&r->data_offset==r->header_offset+4&&r->compressed_size>=0){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);if(!sxaf_span(c,p+4,(uint64_t)r->compressed_size)||!sxaf_add(c,&sxaf_insa_member,p)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static int sxaf_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxaf_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxaf_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxaf_order);return !c->failed;}
static bool sx_archivefinal_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_NIX_NAR:case XX_FILE_TYPE_PHAR:case XX_FILE_TYPE_STUFFIT_SPLIT_FILE:case XX_FILE_TYPE_SQUEEZE1:case XX_FILE_TYPE_SQUEEZE2:case XX_FILE_TYPE_SQ:case XX_FILE_TYPE_LSPACK10:case XX_FILE_TYPE_RNCA:case XX_FILE_TYPE_BAGF:case XX_FILE_TYPE_IXA:case XX_FILE_TYPE_BGA:case XX_FILE_TYPE_DFC:case XX_FILE_TYPE_KA:case XX_FILE_TYPE_SHRINK_CDAF:case XX_FILE_TYPE_SPACK:case XX_FILE_TYPE_PCOMPRESS_PACK:case XX_FILE_TYPE_MXM_SIMPLEARC:case XX_FILE_TYPE_LIF:case XX_FILE_TYPE_DN:case XX_FILE_TYPE_INSA:return true;default:return false;}}
static bool sx_archivefinal_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_NIX_NAR:ok=sxaf_nar(c);break;case XX_FILE_TYPE_PHAR:ok=sxaf_phar(c);break;case XX_FILE_TYPE_STUFFIT_SPLIT_FILE:ok=sxaf_add(c,&sxaf_stuffit_split_header,0);break;case XX_FILE_TYPE_SQUEEZE1:ok=sxaf_squeeze(c,false);break;case XX_FILE_TYPE_SQUEEZE2:ok=sxaf_squeeze(c,true);break;case XX_FILE_TYPE_SQ:ok=sxaf_sq(c);break;case XX_FILE_TYPE_LSPACK10:ok=sxaf_lspack(c);break;case XX_FILE_TYPE_RNCA:ok=sxaf_rnca(c);break;case XX_FILE_TYPE_BAGF:ok=sxaf_add(c,&sxaf_bagf_header,0);break;case XX_FILE_TYPE_IXA:ok=sxaf_ixa(c);break;case XX_FILE_TYPE_BGA:ok=sxaf_bga(c);break;case XX_FILE_TYPE_DFC:ok=sxaf_table(c,&sxaf_dfc_header,&sxaf_dfc_entry,0,2,4,35);break;case XX_FILE_TYPE_KA:ok=sxaf_table(c,&sxaf_ka_header,&sxaf_ka_entry,20,2,22,21);break;case XX_FILE_TYPE_SHRINK_CDAF:ok=sxaf_cdaf(c);break;case XX_FILE_TYPE_SPACK:ok=sxaf_spack(c);break;case XX_FILE_TYPE_PCOMPRESS_PACK:ok=sxaf_pcompress(c);break;case XX_FILE_TYPE_MXM_SIMPLEARC:ok=sxaf_mxm(c);break;case XX_FILE_TYPE_LIF:ok=sxaf_add(c,&sxaf_lif_header,0);break;case XX_FILE_TYPE_DN:ok=sxaf_dn(c);break;case XX_FILE_TYPE_INSA:ok=sxaf_insa(c);break;default:break;}(void)ok;return c->count&&sxaf_finish(c);}
