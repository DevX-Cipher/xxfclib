/* SPDX-License-Identifier: MIT. Physical binary-container metadata. Scope: docs/data_struct_binaryextra_scope.txt. */
static const xx_data_struct_field_desc sxbx_clp_header_fields[] = {
 SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("record_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_clp_header = {UINT32_C(0x60300001),"clp_header",sxbx_clp_header_fields,SX_COUNT(sxbx_clp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_clp_record_fields[] = {
 SX_FIELD("format","uint16",0,2,SX_ID),
 SX_FIELD("data_size","int32",2,4,SX_SIZE),
 SX_FIELD("data_offset","int32",6,4,SX_OFFSET),
 SX_FIELD("format_name_or_reserved","uint8[79]",10,79,SX_NONE),
};
static const sx_layout sxbx_clp_record = {UINT32_C(0x60300002),"clp_record",sxbx_clp_record_fields,SX_COUNT(sxbx_clp_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_header_fields[] = {
 SX_FIELD("signature_length","uint8",0,1,SX_SIZE),
 SX_FIELD("signature","char[8]",1,8,SX_SIGNATURE),
 SX_FIELD("record_count","uint32",9,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_lmd_header = {UINT32_C(0x60300003),"lmd_header",sxbx_lmd_header_fields,SX_COUNT(sxbx_lmd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_record_offset_fields[] = {
 SX_FIELD("record_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxbx_lmd_record_offset = {UINT32_C(0x60300004),"lmd_record_offset",sxbx_lmd_record_offset_fields,SX_COUNT(sxbx_lmd_record_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_flags_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxbx_lmd_flags = {UINT32_C(0x60300005),"lmd_flags",sxbx_lmd_flags_fields,SX_COUNT(sxbx_lmd_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_name_length_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxbx_lmd_name_length = {UINT32_C(0x60300006),"lmd_name_length",sxbx_lmd_name_length_fields,SX_COUNT(sxbx_lmd_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_optional_value_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxbx_lmd_optional_value = {UINT32_C(0x60300007),"lmd_optional_value",sxbx_lmd_optional_value_fields,SX_COUNT(sxbx_lmd_optional_value_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_bitmap_size_fields[] = {
 SX_FIELD("bitmap_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbx_lmd_bitmap_size = {UINT32_C(0x60300008),"lmd_bitmap_size",sxbx_lmd_bitmap_size_fields,SX_COUNT(sxbx_lmd_bitmap_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_block_header_fields[] = {
 SX_FIELD("block_size","uint32",0,4,SX_SIZE),
 SX_FIELD("method","uint8",4,1,SX_ID),
};
static const sx_layout sxbx_lmd_block_header = {UINT32_C(0x60300009),"lmd_block_header",sxbx_lmd_block_header_fields,SX_COUNT(sxbx_lmd_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_vice_snapshot_header_fields[] = {
 SX_FIELD("signature","char[19]",0,19,SX_SIGNATURE),
 SX_FIELD("major","uint8",19,1,SX_NONE),
 SX_FIELD("minor","uint8",20,1,SX_NONE),
 SX_FIELD("machine","char[16]",21,16,SX_NONE),
};
static const sx_layout sxbx_vice_snapshot_header = {UINT32_C(0x6030000a),"vice_snapshot_header",sxbx_vice_snapshot_header_fields,SX_COUNT(sxbx_vice_snapshot_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_vice_version_header_fields[] = {
 SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
 SX_FIELD("major","uint8",13,1,SX_NONE),
 SX_FIELD("minor","uint8",14,1,SX_NONE),
 SX_FIELD("build","uint8",15,1,SX_NONE),
 SX_FIELD("revision","uint8",16,1,SX_NONE),
 SX_FIELD("svn_revision","uint32",17,4,SX_NONE),
};
static const sx_layout sxbx_vice_version_header = {UINT32_C(0x6030000b),"vice_version_header",sxbx_vice_version_header_fields,SX_COUNT(sxbx_vice_version_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_vice_module_header_fields[] = {
 SX_FIELD("name","char[16]",0,16,SX_NONE),
 SX_FIELD("major","uint8",16,1,SX_NONE),
 SX_FIELD("minor","uint8",17,1,SX_NONE),
 SX_FIELD("module_size","uint32",18,4,SX_SIZE),
};
static const sx_layout sxbx_vice_module_header = {UINT32_C(0x6030000c),"vice_module_header",sxbx_vice_module_header_fields,SX_COUNT(sxbx_vice_module_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_magic_fields[] = {
 SX_FIELD("magic","uint8[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxbx_mcap_magic = {UINT32_C(0x6030000d),"mcap_magic",sxbx_mcap_magic_fields,SX_COUNT(sxbx_mcap_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_record_header_fields[] = {
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("payload_size","uint64",1,8,SX_SIZE),
};
static const sx_layout sxbx_mcap_record_header = {UINT32_C(0x6030000e),"mcap_record_header",sxbx_mcap_record_header_fields,SX_COUNT(sxbx_mcap_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_schema_id_fields[] = {
 SX_FIELD("schema_id","uint16",0,2,SX_ID),
};
static const sx_layout sxbx_mcap_schema_id = {UINT32_C(0x6030000f),"mcap_schema_id",sxbx_mcap_schema_id_fields,SX_COUNT(sxbx_mcap_schema_id_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_channel_ids_fields[] = {
 SX_FIELD("channel_id","uint16",0,2,SX_ID),
 SX_FIELD("schema_id","uint16",2,2,SX_ID),
};
static const sx_layout sxbx_mcap_channel_ids = {UINT32_C(0x60300010),"mcap_channel_ids",sxbx_mcap_channel_ids_fields,SX_COUNT(sxbx_mcap_channel_ids_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_message_fields[] = {
 SX_FIELD("channel_id","uint16",0,2,SX_ID),
 SX_FIELD("sequence","uint32",2,4,SX_NONE),
 SX_FIELD("log_time","uint64",6,8,SX_NONE),
 SX_FIELD("publish_time","uint64",14,8,SX_NONE),
};
static const sx_layout sxbx_mcap_message = {UINT32_C(0x60300011),"mcap_message",sxbx_mcap_message_fields,SX_COUNT(sxbx_mcap_message_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_attachment_times_fields[] = {
 SX_FIELD("log_time","uint64",0,8,SX_NONE),
 SX_FIELD("create_time","uint64",8,8,SX_NONE),
};
static const sx_layout sxbx_mcap_attachment_times = {UINT32_C(0x60300012),"mcap_attachment_times",sxbx_mcap_attachment_times_fields,SX_COUNT(sxbx_mcap_attachment_times_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_footer_fields[] = {
 SX_FIELD("summary_start","uint64",0,8,SX_OFFSET),
 SX_FIELD("summary_offset_start","uint64",8,8,SX_OFFSET),
 SX_FIELD("summary_crc","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxbx_mcap_footer = {UINT32_C(0x60300013),"mcap_footer",sxbx_mcap_footer_fields,SX_COUNT(sxbx_mcap_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_crc_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxbx_mcap_crc = {UINT32_C(0x60300014),"mcap_crc",sxbx_mcap_crc_fields,SX_COUNT(sxbx_mcap_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_map_size_fields[] = {
 SX_FIELD("map_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbx_mcap_map_size = {UINT32_C(0x60300015),"mcap_map_size",sxbx_mcap_map_size_fields,SX_COUNT(sxbx_mcap_map_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_string_size_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbx_mcap_string_size = {UINT32_C(0x60300016),"mcap_string_size",sxbx_mcap_string_size_fields,SX_COUNT(sxbx_mcap_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_data_size_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbx_mcap_data_size = {UINT32_C(0x60300017),"mcap_data_size",sxbx_mcap_data_size_fields,SX_COUNT(sxbx_mcap_data_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_mcap_attachment_size_fields[] = {
 SX_FIELD("byte_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxbx_mcap_attachment_size = {UINT32_C(0x60300018),"mcap_attachment_size",sxbx_mcap_attachment_size_fields,SX_COUNT(sxbx_mcap_attachment_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("primary_sequence","uint32",4,4,SX_NONE),
 SX_FIELD("secondary_sequence","uint32",8,4,SX_NONE),
 SX_FIELD("last_written","uint64",12,8,SX_NONE),
 SX_FIELD("major","uint32",20,4,SX_NONE),
 SX_FIELD("minor","uint32",24,4,SX_NONE),
 SX_FIELD("file_type","uint32",28,4,SX_ID),
 SX_FIELD("file_format","uint32",32,4,SX_ID),
 SX_FIELD("root_cell_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("hive_bins_size","uint32",40,4,SX_SIZE),
 SX_FIELD("clustering_factor","uint32",44,4,SX_NONE),
 SX_FIELD("filename","uint8[64]",48,64,SX_NONE),
};
static const sx_layout sxbx_regf_header = {UINT32_C(0x60300019),"regf_header",sxbx_regf_header_fields,SX_COUNT(sxbx_regf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_checksum_fields[] = {
 SX_FIELD("xor32","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxbx_regf_checksum = {UINT32_C(0x6030001a),"regf_checksum",sxbx_regf_checksum_fields,SX_COUNT(sxbx_regf_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_hbin_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("bin_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("bin_size","uint32",8,4,SX_SIZE),
 SX_FIELD("reserved1","uint32",12,4,SX_NONE),
 SX_FIELD("reserved2","uint32",16,4,SX_NONE),
 SX_FIELD("timestamp","uint64",20,8,SX_NONE),
 SX_FIELD("spare","uint32",28,4,SX_NONE),
};
static const sx_layout sxbx_regf_hbin = {UINT32_C(0x6030001b),"regf_hbin",sxbx_regf_hbin_fields,SX_COUNT(sxbx_regf_hbin_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_cell_fields[] = {
 SX_FIELD("signed_cell_size","int32",0,4,SX_NONE),
};
static const sx_layout sxbx_regf_cell = {UINT32_C(0x6030001c),"regf_cell",sxbx_regf_cell_fields,SX_COUNT(sxbx_regf_cell_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_nk_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("last_written","uint64",4,8,SX_NONE),
 SX_FIELD("access_bits","uint32",12,4,SX_NONE),
 SX_FIELD("parent_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("subkey_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("volatile_subkey_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("subkey_list_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("volatile_list_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("value_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("values_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("security_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("class_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("max_subkey_name_size","uint32",52,4,SX_SIZE),
 SX_FIELD("max_subkey_class_size","uint32",56,4,SX_SIZE),
 SX_FIELD("max_value_name_size","uint32",60,4,SX_SIZE),
 SX_FIELD("max_value_data_size","uint32",64,4,SX_SIZE),
 SX_FIELD("work_variable","uint32",68,4,SX_NONE),
 SX_FIELD("name_size","uint16",72,2,SX_SIZE),
 SX_FIELD("class_size","uint16",74,2,SX_SIZE),
};
static const sx_layout sxbx_regf_nk = {UINT32_C(0x6030001d),"regf_nk",sxbx_regf_nk_fields,SX_COUNT(sxbx_regf_nk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_sk_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("reserved","uint16",2,2,SX_NONE),
 SX_FIELD("previous_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("next_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("reference_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("descriptor_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxbx_regf_sk = {UINT32_C(0x6030001e),"regf_sk",sxbx_regf_sk_fields,SX_COUNT(sxbx_regf_sk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_list_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_regf_list = {UINT32_C(0x6030001f),"regf_list",sxbx_regf_list_fields,SX_COUNT(sxbx_regf_list_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_list_offset_fields[] = {
 SX_FIELD("cell_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxbx_regf_list_offset = {UINT32_C(0x60300020),"regf_list_offset",sxbx_regf_list_offset_fields,SX_COUNT(sxbx_regf_list_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_list_hash_fields[] = {
 SX_FIELD("cell_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name_hash_or_hint","uint32",4,4,SX_NONE),
};
static const sx_layout sxbx_regf_list_hash = {UINT32_C(0x60300021),"regf_list_hash",sxbx_regf_list_hash_fields,SX_COUNT(sxbx_regf_list_hash_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_vk_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("name_size","uint16",2,2,SX_SIZE),
 SX_FIELD("data_size_flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("data_offset_or_inline","uint32",8,4,SX_NONE),
 SX_FIELD("value_type","uint32",12,4,SX_ID),
 SX_FIELD("flags","uint16",16,2,SX_FLAGS),
 SX_FIELD("spare","uint16",18,2,SX_NONE),
};
static const sx_layout sxbx_regf_vk = {UINT32_C(0x60300022),"regf_vk",sxbx_regf_vk_fields,SX_COUNT(sxbx_regf_vk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_db_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("segment_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("segment_list_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxbx_regf_db = {UINT32_C(0x60300023),"regf_db",sxbx_regf_db_fields,SX_COUNT(sxbx_regf_db_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_chunk","uint64",8,8,SX_NONE),
 SX_FIELD("last_chunk","uint64",16,8,SX_NONE),
 SX_FIELD("next_record_id","uint64",24,8,SX_ID),
 SX_FIELD("header_size","uint32",32,4,SX_SIZE),
 SX_FIELD("minor","uint16",36,2,SX_NONE),
 SX_FIELD("major","uint16",38,2,SX_NONE),
 SX_FIELD("header_block_size","uint16",40,2,SX_SIZE),
 SX_FIELD("chunk_count","uint32",42,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[74]",46,74,SX_NONE),
 SX_FIELD("flags","uint32",120,4,SX_FLAGS),
 SX_FIELD("checksum","uint32",124,4,SX_CHECKSUM),
};
static const sx_layout sxbx_evtx_header = {UINT32_C(0x60300024),"evtx_header",sxbx_evtx_header_fields,SX_COUNT(sxbx_evtx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_chunk_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_record_number","uint64",8,8,SX_NONE),
 SX_FIELD("last_record_number","uint64",16,8,SX_NONE),
 SX_FIELD("first_record_id","uint64",24,8,SX_ID),
 SX_FIELD("last_record_id","uint64",32,8,SX_ID),
 SX_FIELD("header_size","uint32",40,4,SX_SIZE),
 SX_FIELD("last_record_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("free_space_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("records_checksum","uint32",52,4,SX_CHECKSUM),
 SX_FIELD("reserved","uint8[64]",56,64,SX_NONE),
 SX_FIELD("flags_or_unknown","uint32",120,4,SX_NONE),
 SX_FIELD("header_checksum","uint32",124,4,SX_CHECKSUM),
};
static const sx_layout sxbx_evtx_chunk = {UINT32_C(0x60300025),"evtx_chunk",sxbx_evtx_chunk_fields,SX_COUNT(sxbx_evtx_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_string_offset_fields[] = {
 SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxbx_evtx_string_offset = {UINT32_C(0x60300026),"evtx_string_offset",sxbx_evtx_string_offset_fields,SX_COUNT(sxbx_evtx_string_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_template_offset_fields[] = {
 SX_FIELD("template_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxbx_evtx_template_offset = {UINT32_C(0x60300027),"evtx_template_offset",sxbx_evtx_template_offset_fields,SX_COUNT(sxbx_evtx_template_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_record_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("record_size","uint32",4,4,SX_SIZE),
 SX_FIELD("record_id","uint64",8,8,SX_ID),
 SX_FIELD("timestamp","uint64",16,8,SX_NONE),
};
static const sx_layout sxbx_evtx_record = {UINT32_C(0x60300028),"evtx_record",sxbx_evtx_record_fields,SX_COUNT(sxbx_evtx_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_record_trailer_fields[] = {
 SX_FIELD("record_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbx_evtx_record_trailer = {UINT32_C(0x60300029),"evtx_record_trailer",sxbx_evtx_record_trailer_fields,SX_COUNT(sxbx_evtx_record_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_batch_fields[] = {
 SX_FIELD("base_offset","int64",0,8,SX_NONE),
 SX_FIELD("batch_length","int32",8,4,SX_SIZE),
 SX_FIELD("partition_leader_epoch","int32",12,4,SX_NONE),
 SX_FIELD("magic","int8",16,1,SX_SIGNATURE),
 SX_FIELD("crc32c","uint32",17,4,SX_CHECKSUM),
 SX_FIELD("attributes","int16",21,2,SX_FLAGS),
 SX_FIELD("last_offset_delta","int32",23,4,SX_NONE),
 SX_FIELD("base_timestamp","int64",27,8,SX_NONE),
 SX_FIELD("max_timestamp","int64",35,8,SX_NONE),
 SX_FIELD("producer_id","int64",43,8,SX_ID),
 SX_FIELD("producer_epoch","int16",51,2,SX_NONE),
 SX_FIELD("base_sequence","int32",53,4,SX_NONE),
 SX_FIELD("record_count","int32",57,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_batch = {UINT32_C(0x6030002a),"kafka_batch",sxbx_kafka_batch_fields,SX_COUNT(sxbx_kafka_batch_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_kafka_attributes_fields[] = {
 SX_FIELD("attributes","int8",0,1,SX_FLAGS),
};
static const sx_layout sxbx_kafka_attributes = {UINT32_C(0x6030002b),"kafka_attributes",sxbx_kafka_attributes_fields,SX_COUNT(sxbx_kafka_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size1_fields[] = {
 SX_FIELD("record_size","zigzag32",0,1,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size1 = {UINT32_C(0x6030002c),"kafka_record_size1",sxbx_kafka_record_size1_fields,SX_COUNT(sxbx_kafka_record_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size2_fields[] = {
 SX_FIELD("record_size","zigzag32",0,2,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size2 = {UINT32_C(0x6030002d),"kafka_record_size2",sxbx_kafka_record_size2_fields,SX_COUNT(sxbx_kafka_record_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size3_fields[] = {
 SX_FIELD("record_size","zigzag32",0,3,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size3 = {UINT32_C(0x6030002e),"kafka_record_size3",sxbx_kafka_record_size3_fields,SX_COUNT(sxbx_kafka_record_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size4_fields[] = {
 SX_FIELD("record_size","zigzag32",0,4,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size4 = {UINT32_C(0x6030002f),"kafka_record_size4",sxbx_kafka_record_size4_fields,SX_COUNT(sxbx_kafka_record_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size5_fields[] = {
 SX_FIELD("record_size","zigzag32",0,5,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size5 = {UINT32_C(0x60300030),"kafka_record_size5",sxbx_kafka_record_size5_fields,SX_COUNT(sxbx_kafka_record_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size6_fields[] = {
 SX_FIELD("record_size","zigzag32",0,6,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size6 = {UINT32_C(0x60300031),"kafka_record_size6",sxbx_kafka_record_size6_fields,SX_COUNT(sxbx_kafka_record_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size7_fields[] = {
 SX_FIELD("record_size","zigzag32",0,7,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size7 = {UINT32_C(0x60300032),"kafka_record_size7",sxbx_kafka_record_size7_fields,SX_COUNT(sxbx_kafka_record_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size8_fields[] = {
 SX_FIELD("record_size","zigzag32",0,8,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size8 = {UINT32_C(0x60300033),"kafka_record_size8",sxbx_kafka_record_size8_fields,SX_COUNT(sxbx_kafka_record_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size9_fields[] = {
 SX_FIELD("record_size","zigzag32",0,9,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size9 = {UINT32_C(0x60300034),"kafka_record_size9",sxbx_kafka_record_size9_fields,SX_COUNT(sxbx_kafka_record_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_record_size10_fields[] = {
 SX_FIELD("record_size","zigzag32",0,10,SX_SIZE),
};
static const sx_layout sxbx_kafka_record_size10 = {UINT32_C(0x60300035),"kafka_record_size10",sxbx_kafka_record_size10_fields,SX_COUNT(sxbx_kafka_record_size10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta1_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,1,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta1 = {UINT32_C(0x60300036),"kafka_timestamp_delta1",sxbx_kafka_timestamp_delta1_fields,SX_COUNT(sxbx_kafka_timestamp_delta1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta2_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,2,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta2 = {UINT32_C(0x60300037),"kafka_timestamp_delta2",sxbx_kafka_timestamp_delta2_fields,SX_COUNT(sxbx_kafka_timestamp_delta2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta3_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,3,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta3 = {UINT32_C(0x60300038),"kafka_timestamp_delta3",sxbx_kafka_timestamp_delta3_fields,SX_COUNT(sxbx_kafka_timestamp_delta3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta4_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,4,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta4 = {UINT32_C(0x60300039),"kafka_timestamp_delta4",sxbx_kafka_timestamp_delta4_fields,SX_COUNT(sxbx_kafka_timestamp_delta4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta5_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,5,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta5 = {UINT32_C(0x6030003a),"kafka_timestamp_delta5",sxbx_kafka_timestamp_delta5_fields,SX_COUNT(sxbx_kafka_timestamp_delta5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta6_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,6,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta6 = {UINT32_C(0x6030003b),"kafka_timestamp_delta6",sxbx_kafka_timestamp_delta6_fields,SX_COUNT(sxbx_kafka_timestamp_delta6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta7_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,7,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta7 = {UINT32_C(0x6030003c),"kafka_timestamp_delta7",sxbx_kafka_timestamp_delta7_fields,SX_COUNT(sxbx_kafka_timestamp_delta7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta8_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,8,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta8 = {UINT32_C(0x6030003d),"kafka_timestamp_delta8",sxbx_kafka_timestamp_delta8_fields,SX_COUNT(sxbx_kafka_timestamp_delta8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta9_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,9,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta9 = {UINT32_C(0x6030003e),"kafka_timestamp_delta9",sxbx_kafka_timestamp_delta9_fields,SX_COUNT(sxbx_kafka_timestamp_delta9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_timestamp_delta10_fields[] = {
 SX_FIELD("timestamp_delta","zigzag64",0,10,SX_NONE),
};
static const sx_layout sxbx_kafka_timestamp_delta10 = {UINT32_C(0x6030003f),"kafka_timestamp_delta10",sxbx_kafka_timestamp_delta10_fields,SX_COUNT(sxbx_kafka_timestamp_delta10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta1_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,1,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta1 = {UINT32_C(0x60300040),"kafka_offset_delta1",sxbx_kafka_offset_delta1_fields,SX_COUNT(sxbx_kafka_offset_delta1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta2_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,2,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta2 = {UINT32_C(0x60300041),"kafka_offset_delta2",sxbx_kafka_offset_delta2_fields,SX_COUNT(sxbx_kafka_offset_delta2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta3_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,3,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta3 = {UINT32_C(0x60300042),"kafka_offset_delta3",sxbx_kafka_offset_delta3_fields,SX_COUNT(sxbx_kafka_offset_delta3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta4_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,4,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta4 = {UINT32_C(0x60300043),"kafka_offset_delta4",sxbx_kafka_offset_delta4_fields,SX_COUNT(sxbx_kafka_offset_delta4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta5_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,5,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta5 = {UINT32_C(0x60300044),"kafka_offset_delta5",sxbx_kafka_offset_delta5_fields,SX_COUNT(sxbx_kafka_offset_delta5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta6_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,6,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta6 = {UINT32_C(0x60300045),"kafka_offset_delta6",sxbx_kafka_offset_delta6_fields,SX_COUNT(sxbx_kafka_offset_delta6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta7_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,7,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta7 = {UINT32_C(0x60300046),"kafka_offset_delta7",sxbx_kafka_offset_delta7_fields,SX_COUNT(sxbx_kafka_offset_delta7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta8_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,8,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta8 = {UINT32_C(0x60300047),"kafka_offset_delta8",sxbx_kafka_offset_delta8_fields,SX_COUNT(sxbx_kafka_offset_delta8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta9_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,9,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta9 = {UINT32_C(0x60300048),"kafka_offset_delta9",sxbx_kafka_offset_delta9_fields,SX_COUNT(sxbx_kafka_offset_delta9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_offset_delta10_fields[] = {
 SX_FIELD("offset_delta","zigzag32",0,10,SX_NONE),
};
static const sx_layout sxbx_kafka_offset_delta10 = {UINT32_C(0x60300049),"kafka_offset_delta10",sxbx_kafka_offset_delta10_fields,SX_COUNT(sxbx_kafka_offset_delta10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size1_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,1,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size1 = {UINT32_C(0x6030004a),"kafka_nullable_size1",sxbx_kafka_nullable_size1_fields,SX_COUNT(sxbx_kafka_nullable_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size2_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,2,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size2 = {UINT32_C(0x6030004b),"kafka_nullable_size2",sxbx_kafka_nullable_size2_fields,SX_COUNT(sxbx_kafka_nullable_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size3_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,3,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size3 = {UINT32_C(0x6030004c),"kafka_nullable_size3",sxbx_kafka_nullable_size3_fields,SX_COUNT(sxbx_kafka_nullable_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size4_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,4,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size4 = {UINT32_C(0x6030004d),"kafka_nullable_size4",sxbx_kafka_nullable_size4_fields,SX_COUNT(sxbx_kafka_nullable_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size5_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,5,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size5 = {UINT32_C(0x6030004e),"kafka_nullable_size5",sxbx_kafka_nullable_size5_fields,SX_COUNT(sxbx_kafka_nullable_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size6_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,6,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size6 = {UINT32_C(0x6030004f),"kafka_nullable_size6",sxbx_kafka_nullable_size6_fields,SX_COUNT(sxbx_kafka_nullable_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size7_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,7,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size7 = {UINT32_C(0x60300050),"kafka_nullable_size7",sxbx_kafka_nullable_size7_fields,SX_COUNT(sxbx_kafka_nullable_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size8_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,8,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size8 = {UINT32_C(0x60300051),"kafka_nullable_size8",sxbx_kafka_nullable_size8_fields,SX_COUNT(sxbx_kafka_nullable_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size9_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,9,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size9 = {UINT32_C(0x60300052),"kafka_nullable_size9",sxbx_kafka_nullable_size9_fields,SX_COUNT(sxbx_kafka_nullable_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_nullable_size10_fields[] = {
 SX_FIELD("nullable_size","zigzag32",0,10,SX_NONE),
};
static const sx_layout sxbx_kafka_nullable_size10 = {UINT32_C(0x60300053),"kafka_nullable_size10",sxbx_kafka_nullable_size10_fields,SX_COUNT(sxbx_kafka_nullable_size10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count1_fields[] = {
 SX_FIELD("header_count","zigzag32",0,1,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count1 = {UINT32_C(0x60300054),"kafka_header_count1",sxbx_kafka_header_count1_fields,SX_COUNT(sxbx_kafka_header_count1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count2_fields[] = {
 SX_FIELD("header_count","zigzag32",0,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count2 = {UINT32_C(0x60300055),"kafka_header_count2",sxbx_kafka_header_count2_fields,SX_COUNT(sxbx_kafka_header_count2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count3_fields[] = {
 SX_FIELD("header_count","zigzag32",0,3,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count3 = {UINT32_C(0x60300056),"kafka_header_count3",sxbx_kafka_header_count3_fields,SX_COUNT(sxbx_kafka_header_count3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count4_fields[] = {
 SX_FIELD("header_count","zigzag32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count4 = {UINT32_C(0x60300057),"kafka_header_count4",sxbx_kafka_header_count4_fields,SX_COUNT(sxbx_kafka_header_count4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count5_fields[] = {
 SX_FIELD("header_count","zigzag32",0,5,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count5 = {UINT32_C(0x60300058),"kafka_header_count5",sxbx_kafka_header_count5_fields,SX_COUNT(sxbx_kafka_header_count5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count6_fields[] = {
 SX_FIELD("header_count","zigzag32",0,6,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count6 = {UINT32_C(0x60300059),"kafka_header_count6",sxbx_kafka_header_count6_fields,SX_COUNT(sxbx_kafka_header_count6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count7_fields[] = {
 SX_FIELD("header_count","zigzag32",0,7,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count7 = {UINT32_C(0x6030005a),"kafka_header_count7",sxbx_kafka_header_count7_fields,SX_COUNT(sxbx_kafka_header_count7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count8_fields[] = {
 SX_FIELD("header_count","zigzag32",0,8,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count8 = {UINT32_C(0x6030005b),"kafka_header_count8",sxbx_kafka_header_count8_fields,SX_COUNT(sxbx_kafka_header_count8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count9_fields[] = {
 SX_FIELD("header_count","zigzag32",0,9,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count9 = {UINT32_C(0x6030005c),"kafka_header_count9",sxbx_kafka_header_count9_fields,SX_COUNT(sxbx_kafka_header_count9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_count10_fields[] = {
 SX_FIELD("header_count","zigzag32",0,10,SX_COUNT_PROP),
};
static const sx_layout sxbx_kafka_header_count10 = {UINT32_C(0x6030005d),"kafka_header_count10",sxbx_kafka_header_count10_fields,SX_COUNT(sxbx_kafka_header_count10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size1_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,1,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size1 = {UINT32_C(0x6030005e),"kafka_header_key_size1",sxbx_kafka_header_key_size1_fields,SX_COUNT(sxbx_kafka_header_key_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size2_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,2,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size2 = {UINT32_C(0x6030005f),"kafka_header_key_size2",sxbx_kafka_header_key_size2_fields,SX_COUNT(sxbx_kafka_header_key_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size3_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,3,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size3 = {UINT32_C(0x60300060),"kafka_header_key_size3",sxbx_kafka_header_key_size3_fields,SX_COUNT(sxbx_kafka_header_key_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size4_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,4,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size4 = {UINT32_C(0x60300061),"kafka_header_key_size4",sxbx_kafka_header_key_size4_fields,SX_COUNT(sxbx_kafka_header_key_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size5_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,5,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size5 = {UINT32_C(0x60300062),"kafka_header_key_size5",sxbx_kafka_header_key_size5_fields,SX_COUNT(sxbx_kafka_header_key_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size6_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,6,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size6 = {UINT32_C(0x60300063),"kafka_header_key_size6",sxbx_kafka_header_key_size6_fields,SX_COUNT(sxbx_kafka_header_key_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size7_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,7,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size7 = {UINT32_C(0x60300064),"kafka_header_key_size7",sxbx_kafka_header_key_size7_fields,SX_COUNT(sxbx_kafka_header_key_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size8_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,8,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size8 = {UINT32_C(0x60300065),"kafka_header_key_size8",sxbx_kafka_header_key_size8_fields,SX_COUNT(sxbx_kafka_header_key_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size9_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,9,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size9 = {UINT32_C(0x60300066),"kafka_header_key_size9",sxbx_kafka_header_key_size9_fields,SX_COUNT(sxbx_kafka_header_key_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_kafka_header_key_size10_fields[] = {
 SX_FIELD("header_key_size","zigzag32",0,10,SX_SIZE),
};
static const sx_layout sxbx_kafka_header_key_size10 = {UINT32_C(0x60300067),"kafka_header_key_size10",sxbx_kafka_header_key_size10_fields,SX_COUNT(sxbx_kafka_header_key_size10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_segment_table_fields[] = {
 SX_FIELD("segment_count_minus_one","uint32",0,4,SX_NONE),
 SX_FIELD("segment_words","uint32",4,4,SX_NONE),
};
static const sx_layout sxbx_capnp_segment_table = {UINT32_C(0x60300068),"capnp_segment_table",sxbx_capnp_segment_table_fields,SX_COUNT(sxbx_capnp_segment_table_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_struct_pointer_fields[] = {
 SX_FIELD("offset_and_kind","uint32",0,4,SX_FLAGS),
 SX_FIELD("data_word_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("pointer_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_capnp_struct_pointer = {UINT32_C(0x60300069),"capnp_struct_pointer",sxbx_capnp_struct_pointer_fields,SX_COUNT(sxbx_capnp_struct_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_list_pointer_fields[] = {
 SX_FIELD("offset_and_kind","uint32",0,4,SX_FLAGS),
 SX_FIELD("count_and_element_size","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxbx_capnp_list_pointer = {UINT32_C(0x6030006a),"capnp_list_pointer",sxbx_capnp_list_pointer_fields,SX_COUNT(sxbx_capnp_list_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_composite_tag_fields[] = {
 SX_FIELD("element_count_and_kind","uint32",0,4,SX_FLAGS),
 SX_FIELD("data_word_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("pointer_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_capnp_composite_tag = {UINT32_C(0x6030006b),"capnp_composite_tag",sxbx_capnp_composite_tag_fields,SX_COUNT(sxbx_capnp_composite_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_null_pointer_fields[] = {
 SX_FIELD("null_pointer","uint64",0,8,SX_NONE),
};
static const sx_layout sxbx_capnp_null_pointer = {UINT32_C(0x6030006c),"capnp_null_pointer",sxbx_capnp_null_pointer_fields,SX_COUNT(sxbx_capnp_null_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_acb_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("book_id","uint16",6,2,SX_ID),
};
static const sx_layout sxbx_acb_header = {UINT32_C(0x6030006d),"acb_header",sxbx_acb_header_fields,SX_COUNT(sxbx_acb_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_acb_string_length_fields[] = {
 SX_FIELD("utf16_unit_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_acb_string_length = {UINT32_C(0x6030006e),"acb_string_length",sxbx_acb_string_length_fields,SX_COUNT(sxbx_acb_string_length_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_acb_palette_fields[] = {
 SX_FIELD("color_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("colors_per_page","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("page_offset","uint16",4,2,SX_NONE),
 SX_FIELD("color_space","uint16",6,2,SX_ID),
};
static const sx_layout sxbx_acb_palette = {UINT32_C(0x6030006f),"acb_palette",sxbx_acb_palette_fields,SX_COUNT(sxbx_acb_palette_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_acb_color_rgb_fields[] = {
 SX_FIELD("code","char[6]",0,6,SX_NONE),
 SX_FIELD("component_0","uint8",6,1,SX_NONE),
 SX_FIELD("component_1","uint8",7,1,SX_NONE),
 SX_FIELD("component_2","uint8",8,1,SX_NONE),
};
static const sx_layout sxbx_acb_color_rgb = {UINT32_C(0x60300070),"acb_color_rgb",sxbx_acb_color_rgb_fields,SX_COUNT(sxbx_acb_color_rgb_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_acb_color_cmyk_fields[] = {
 SX_FIELD("code","char[6]",0,6,SX_NONE),
 SX_FIELD("component_0","uint8",6,1,SX_NONE),
 SX_FIELD("component_1","uint8",7,1,SX_NONE),
 SX_FIELD("component_2","uint8",8,1,SX_NONE),
 SX_FIELD("component_3","uint8",9,1,SX_NONE),
};
static const sx_layout sxbx_acb_color_cmyk = {UINT32_C(0x60300071),"acb_color_cmyk",sxbx_acb_color_cmyk_fields,SX_COUNT(sxbx_acb_color_cmyk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_acb_color_lab_fields[] = {
 SX_FIELD("code","char[6]",0,6,SX_NONE),
 SX_FIELD("component_0","uint8",6,1,SX_NONE),
 SX_FIELD("component_1","uint8",7,1,SX_NONE),
 SX_FIELD("component_2","uint8",8,1,SX_NONE),
};
static const sx_layout sxbx_acb_color_lab = {UINT32_C(0x60300072),"acb_color_lab",sxbx_acb_color_lab_fields,SX_COUNT(sxbx_acb_color_lab_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_acb_trailer_fields[] = {
 SX_FIELD("mode","char[8]",0,8,SX_ID),
};
static const sx_layout sxbx_acb_trailer = {UINT32_C(0x60300073),"acb_trailer",sxbx_acb_trailer_fields,SX_COUNT(sxbx_acb_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_keytab_header_fields[] = {
 SX_FIELD("major","uint8",0,1,SX_NONE),
 SX_FIELD("minor","uint8",1,1,SX_NONE),
};
static const sx_layout sxbx_keytab_header = {UINT32_C(0x60300074),"keytab_header",sxbx_keytab_header_fields,SX_COUNT(sxbx_keytab_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_entry_length_fields[] = {
 SX_FIELD("signed_entry_size","int32",0,4,SX_NONE),
};
static const sx_layout sxbx_keytab_entry_length = {UINT32_C(0x60300075),"keytab_entry_length",sxbx_keytab_entry_length_fields,SX_COUNT(sxbx_keytab_entry_length_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_component_count_fields[] = {
 SX_FIELD("component_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_keytab_component_count = {UINT32_C(0x60300076),"keytab_component_count",sxbx_keytab_component_count_fields,SX_COUNT(sxbx_keytab_component_count_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_string_length_fields[] = {
 SX_FIELD("byte_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxbx_keytab_string_length = {UINT32_C(0x60300077),"keytab_string_length",sxbx_keytab_string_length_fields,SX_COUNT(sxbx_keytab_string_length_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_kerberos_name_type_fields[] = {
 SX_FIELD("name_type","uint32",0,4,SX_ID),
};
static const sx_layout sxbx_kerberos_name_type = {UINT32_C(0x60300078),"kerberos_name_type",sxbx_kerberos_name_type_fields,SX_COUNT(sxbx_kerberos_name_type_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_key_fields[] = {
 SX_FIELD("timestamp","uint32",0,4,SX_NONE),
 SX_FIELD("kvno","uint8",4,1,SX_NONE),
 SX_FIELD("enctype","uint16",5,2,SX_ID),
 SX_FIELD("key_size","uint16",7,2,SX_SIZE),
};
static const sx_layout sxbx_keytab_key = {UINT32_C(0x60300079),"keytab_key",sxbx_keytab_key_fields,SX_COUNT(sxbx_keytab_key_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_keytab_extended_kvno_fields[] = {
 SX_FIELD("kvno","uint32",0,4,SX_NONE),
};
static const sx_layout sxbx_keytab_extended_kvno = {UINT32_C(0x6030007a),"keytab_extended_kvno",sxbx_keytab_extended_kvno_fields,SX_COUNT(sxbx_keytab_extended_kvno_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_header_fields[] = {
 SX_FIELD("major","uint8",0,1,SX_NONE),
 SX_FIELD("minor","uint8",1,1,SX_NONE),
 SX_FIELD("header_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxbx_ccache_header = {UINT32_C(0x6030007b),"ccache_header",sxbx_ccache_header_fields,SX_COUNT(sxbx_ccache_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_tag_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_ID),
 SX_FIELD("tag_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxbx_ccache_tag = {UINT32_C(0x6030007c),"ccache_tag",sxbx_ccache_tag_fields,SX_COUNT(sxbx_ccache_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_time_offset_fields[] = {
 SX_FIELD("seconds","int32",0,4,SX_NONE),
 SX_FIELD("microseconds","int32",4,4,SX_NONE),
};
static const sx_layout sxbx_ccache_time_offset = {UINT32_C(0x6030007d),"ccache_time_offset",sxbx_ccache_time_offset_fields,SX_COUNT(sxbx_ccache_time_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_principal_fields[] = {
 SX_FIELD("name_type","uint32",0,4,SX_ID),
 SX_FIELD("component_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_ccache_principal = {UINT32_C(0x6030007e),"ccache_principal",sxbx_ccache_principal_fields,SX_COUNT(sxbx_ccache_principal_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_blob_size_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbx_ccache_blob_size = {UINT32_C(0x6030007f),"ccache_blob_size",sxbx_ccache_blob_size_fields,SX_COUNT(sxbx_ccache_blob_size_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_key_fields[] = {
 SX_FIELD("enctype","uint16",0,2,SX_ID),
 SX_FIELD("key_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxbx_ccache_key = {UINT32_C(0x60300080),"ccache_key",sxbx_ccache_key_fields,SX_COUNT(sxbx_ccache_key_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_times_flags_fields[] = {
 SX_FIELD("auth_time","uint32",0,4,SX_NONE),
 SX_FIELD("start_time","uint32",4,4,SX_NONE),
 SX_FIELD("end_time","uint32",8,4,SX_NONE),
 SX_FIELD("renew_until","uint32",12,4,SX_NONE),
 SX_FIELD("is_skey","uint8",16,1,SX_NONE),
 SX_FIELD("ticket_flags","uint32",17,4,SX_FLAGS),
};
static const sx_layout sxbx_ccache_times_flags = {UINT32_C(0x60300081),"ccache_times_flags",sxbx_ccache_times_flags_fields,SX_COUNT(sxbx_ccache_times_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_list_count_fields[] = {
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_ccache_list_count = {UINT32_C(0x60300082),"ccache_list_count",sxbx_ccache_list_count_fields,SX_COUNT(sxbx_ccache_list_count_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_typed_blob_fields[] = {
 SX_FIELD("type","uint16",0,2,SX_ID),
 SX_FIELD("byte_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxbx_ccache_typed_blob = {UINT32_C(0x60300083),"ccache_typed_blob",sxbx_ccache_typed_blob_fields,SX_COUNT(sxbx_ccache_typed_blob_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_header_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_jks_header = {UINT32_C(0x60300084),"jks_header",sxbx_jks_header_fields,SX_COUNT(sxbx_jks_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_entry_tag_fields[] = {
 SX_FIELD("tag","uint32",0,4,SX_ID),
};
static const sx_layout sxbx_jks_entry_tag = {UINT32_C(0x60300085),"jks_entry_tag",sxbx_jks_entry_tag_fields,SX_COUNT(sxbx_jks_entry_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_string_size_fields[] = {
 SX_FIELD("modified_utf8_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxbx_jks_string_size = {UINT32_C(0x60300086),"jks_string_size",sxbx_jks_string_size_fields,SX_COUNT(sxbx_jks_string_size_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_timestamp_fields[] = {
 SX_FIELD("timestamp","int64",0,8,SX_NONE),
};
static const sx_layout sxbx_jks_timestamp = {UINT32_C(0x60300087),"jks_timestamp",sxbx_jks_timestamp_fields,SX_COUNT(sxbx_jks_timestamp_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_blob_size_fields[] = {
 SX_FIELD("byte_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxbx_jks_blob_size = {UINT32_C(0x60300088),"jks_blob_size",sxbx_jks_blob_size_fields,SX_COUNT(sxbx_jks_blob_size_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_certificate_count_fields[] = {
 SX_FIELD("certificate_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_jks_certificate_count = {UINT32_C(0x60300089),"jks_certificate_count",sxbx_jks_certificate_count_fields,SX_COUNT(sxbx_jks_certificate_count_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_digest_fields[] = {
 SX_FIELD("sha1","uint8[20]",0,20,SX_CHECKSUM),
};
static const sx_layout sxbx_jks_digest = {UINT32_C(0x6030008a),"jks_digest",sxbx_jks_digest_fields,SX_COUNT(sxbx_jks_digest_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_header_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("tensor_count","uint64",8,8,SX_COUNT_PROP),
 SX_FIELD("metadata_count","uint64",16,8,SX_COUNT_PROP),
};
static const sx_layout sxbx_gguf_header = {UINT32_C(0x6030008b),"gguf_header",sxbx_gguf_header_fields,SX_COUNT(sxbx_gguf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_string_size_fields[] = {
 SX_FIELD("utf8_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxbx_gguf_string_size = {UINT32_C(0x6030008c),"gguf_string_size",sxbx_gguf_string_size_fields,SX_COUNT(sxbx_gguf_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value_type_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
};
static const sx_layout sxbx_gguf_value_type = {UINT32_C(0x6030008d),"gguf_value_type",sxbx_gguf_value_type_fields,SX_COUNT(sxbx_gguf_value_type_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_array_fields[] = {
 SX_FIELD("element_type","uint32",0,4,SX_ID),
 SX_FIELD("element_count","uint64",4,8,SX_COUNT_PROP),
};
static const sx_layout sxbx_gguf_array = {UINT32_C(0x6030008e),"gguf_array",sxbx_gguf_array_fields,SX_COUNT(sxbx_gguf_array_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value0_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxbx_gguf_value0 = {UINT32_C(0x6030008f),"gguf_value0",sxbx_gguf_value0_fields,SX_COUNT(sxbx_gguf_value0_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value1_fields[] = {
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxbx_gguf_value1 = {UINT32_C(0x60300090),"gguf_value1",sxbx_gguf_value1_fields,SX_COUNT(sxbx_gguf_value1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value2_fields[] = {
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxbx_gguf_value2 = {UINT32_C(0x60300091),"gguf_value2",sxbx_gguf_value2_fields,SX_COUNT(sxbx_gguf_value2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value3_fields[] = {
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxbx_gguf_value3 = {UINT32_C(0x60300092),"gguf_value3",sxbx_gguf_value3_fields,SX_COUNT(sxbx_gguf_value3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value4_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxbx_gguf_value4 = {UINT32_C(0x60300093),"gguf_value4",sxbx_gguf_value4_fields,SX_COUNT(sxbx_gguf_value4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value5_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxbx_gguf_value5 = {UINT32_C(0x60300094),"gguf_value5",sxbx_gguf_value5_fields,SX_COUNT(sxbx_gguf_value5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value6_fields[] = {
 SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxbx_gguf_value6 = {UINT32_C(0x60300095),"gguf_value6",sxbx_gguf_value6_fields,SX_COUNT(sxbx_gguf_value6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value7_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxbx_gguf_value7 = {UINT32_C(0x60300096),"gguf_value7",sxbx_gguf_value7_fields,SX_COUNT(sxbx_gguf_value7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value10_fields[] = {
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
static const sx_layout sxbx_gguf_value10 = {UINT32_C(0x60300097),"gguf_value10",sxbx_gguf_value10_fields,SX_COUNT(sxbx_gguf_value10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value11_fields[] = {
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxbx_gguf_value11 = {UINT32_C(0x60300098),"gguf_value11",sxbx_gguf_value11_fields,SX_COUNT(sxbx_gguf_value11_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value12_fields[] = {
 SX_FIELD("value","float64",0,8,SX_NONE),
};
static const sx_layout sxbx_gguf_value12 = {UINT32_C(0x60300099),"gguf_value12",sxbx_gguf_value12_fields,SX_COUNT(sxbx_gguf_value12_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_dimensions_fields[] = {
 SX_FIELD("dimension_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_gguf_dimensions = {UINT32_C(0x6030009a),"gguf_dimensions",sxbx_gguf_dimensions_fields,SX_COUNT(sxbx_gguf_dimensions_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_dimension_fields[] = {
 SX_FIELD("dimension","uint64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxbx_gguf_dimension = {UINT32_C(0x6030009b),"gguf_dimension",sxbx_gguf_dimension_fields,SX_COUNT(sxbx_gguf_dimension_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_tensor_storage_fields[] = {
 SX_FIELD("tensor_type","uint32",0,4,SX_ID),
 SX_FIELD("data_offset","uint64",4,8,SX_OFFSET),
};
static const sx_layout sxbx_gguf_tensor_storage = {UINT32_C(0x6030009c),"gguf_tensor_storage",sxbx_gguf_tensor_storage_fields,SX_COUNT(sxbx_gguf_tensor_storage_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxbx_nvp_header = {UINT32_C(0x6030009d),"nvp_header",sxbx_nvp_header_fields,SX_COUNT(sxbx_nvp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_directory_fields[] = {
 SX_FIELD("unknown","uint8[3]",0,3,SX_NONE),
 SX_FIELD("record_count","uint16",3,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_nvp_directory = {UINT32_C(0x6030009e),"nvp_directory",sxbx_nvp_directory_fields,SX_COUNT(sxbx_nvp_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_record_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("size_and_flags","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxbx_nvp_record = {UINT32_C(0x6030009f),"nvp_record",sxbx_nvp_record_fields,SX_COUNT(sxbx_nvp_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_jpeg_size_fields[] = {
 SX_FIELD("jpeg_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbx_nvp_jpeg_size = {UINT32_C(0x603000a0),"nvp_jpeg_size",sxbx_nvp_jpeg_size_fields,SX_COUNT(sxbx_nvp_jpeg_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_string_list_fields[] = {
 SX_FIELD("string_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxbx_nvp_string_list = {UINT32_C(0x603000a1),"nvp_string_list",sxbx_nvp_string_list_fields,SX_COUNT(sxbx_nvp_string_list_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lbrcobol_title_fields[] = {
 SX_FIELD("title","char[34]",0,34,SX_SIGNATURE),
 SX_FIELD("creation_stamp","char[21]",34,21,SX_NONE),
};
static const sx_layout sxbx_lbrcobol_title = {UINT32_C(0x603000a2),"lbrcobol_title",sxbx_lbrcobol_title_fields,SX_COUNT(sxbx_lbrcobol_title_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lbrcobol_directory_header_fields[] = {
 SX_FIELD("block_size","uint16",0,2,SX_NONE),
 SX_FIELD("record_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_lbrcobol_directory_header = {UINT32_C(0x603000a3),"lbrcobol_directory_header",sxbx_lbrcobol_directory_header_fields,SX_COUNT(sxbx_lbrcobol_directory_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_lbrcobol_header_constants_fields[] = {
 SX_FIELD("constant1","uint32",0,4,SX_NONE),
 SX_FIELD("constant2","uint32",4,4,SX_NONE),
};
static const sx_layout sxbx_lbrcobol_header_constants = {UINT32_C(0x603000a4),"lbrcobol_header_constants",sxbx_lbrcobol_header_constants_fields,SX_COUNT(sxbx_lbrcobol_header_constants_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lbrcobol_member_fields[] = {
 SX_FIELD("next_record_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("payload_block","uint32",4,4,SX_NONE),
 SX_FIELD("payload_size","uint32",8,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
};
static const sx_layout sxbx_lbrcobol_member = {UINT32_C(0x603000a5),"lbrcobol_member",sxbx_lbrcobol_member_fields,SX_COUNT(sxbx_lbrcobol_member_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_lbrcobol_member_tail_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("name_size","uint8",2,1,SX_SIZE),
};
static const sx_layout sxbx_lbrcobol_member_tail = {UINT32_C(0x603000a6),"lbrcobol_member_tail",sxbx_lbrcobol_member_tail_fields,SX_COUNT(sxbx_lbrcobol_member_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_header_le_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("python_magic","uint8[4]",4,4,SX_SIGNATURE),
 SX_FIELD("toc_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxbx_pyz_header_le = {UINT32_C(0x603000a7),"pyz_header_le",sxbx_pyz_header_le_fields,SX_COUNT(sxbx_pyz_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_header_be_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("python_magic","uint8[4]",4,4,SX_SIGNATURE),
 SX_FIELD("toc_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxbx_pyz_header_be = {UINT32_C(0x603000a8),"pyz_header_be",sxbx_pyz_header_be_fields,SX_COUNT(sxbx_pyz_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_tag_fields[] = {
 SX_FIELD("type_and_reference","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxbx_pyz_marshal_tag = {UINT32_C(0x603000a9),"pyz_marshal_tag",sxbx_pyz_marshal_tag_fields,SX_COUNT(sxbx_pyz_marshal_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_int32_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxbx_pyz_marshal_int32 = {UINT32_C(0x603000aa),"pyz_marshal_int32",sxbx_pyz_marshal_int32_fields,SX_COUNT(sxbx_pyz_marshal_int32_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_int64_fields[] = {
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxbx_pyz_marshal_int64 = {UINT32_C(0x603000ab),"pyz_marshal_int64",sxbx_pyz_marshal_int64_fields,SX_COUNT(sxbx_pyz_marshal_int64_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_length_fields[] = {
 SX_FIELD("value","int32",0,4,SX_SIZE),
};
static const sx_layout sxbx_pyz_marshal_length = {UINT32_C(0x603000ac),"pyz_marshal_length",sxbx_pyz_marshal_length_fields,SX_COUNT(sxbx_pyz_marshal_length_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_count_fields[] = {
 SX_FIELD("value","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_pyz_marshal_count = {UINT32_C(0x603000ad),"pyz_marshal_count",sxbx_pyz_marshal_count_fields,SX_COUNT(sxbx_pyz_marshal_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_short_count_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxbx_pyz_marshal_short_count = {UINT32_C(0x603000ae),"pyz_marshal_short_count",sxbx_pyz_marshal_short_count_fields,SX_COUNT(sxbx_pyz_marshal_short_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_short_length_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_SIZE),
};
static const sx_layout sxbx_pyz_marshal_short_length = {UINT32_C(0x603000af),"pyz_marshal_short_length",sxbx_pyz_marshal_short_length_fields,SX_COUNT(sxbx_pyz_marshal_short_length_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_reference_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxbx_pyz_marshal_reference = {UINT32_C(0x603000b0),"pyz_marshal_reference",sxbx_pyz_marshal_reference_fields,SX_COUNT(sxbx_pyz_marshal_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_long_digits_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxbx_pyz_marshal_long_digits = {UINT32_C(0x603000b1),"pyz_marshal_long_digits",sxbx_pyz_marshal_long_digits_fields,SX_COUNT(sxbx_pyz_marshal_long_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_digit_fields[] = {
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxbx_pyz_marshal_digit = {UINT32_C(0x603000b2),"pyz_marshal_digit",sxbx_pyz_marshal_digit_fields,SX_COUNT(sxbx_pyz_marshal_digit_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyinstaller_cookie24_fields[] = {
 SX_FIELD("magic","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("package_size","uint32",8,4,SX_SIZE),
 SX_FIELD("toc_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("toc_size","uint32",16,4,SX_SIZE),
 SX_FIELD("python_version","int32",20,4,SX_NONE),
};
static const sx_layout sxbx_pyinstaller_cookie24 = {UINT32_C(0x603000b3),"pyinstaller_cookie24",sxbx_pyinstaller_cookie24_fields,SX_COUNT(sxbx_pyinstaller_cookie24_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_pyinstaller_library_fields[] = {
 SX_FIELD("python_library","char[64]",0,64,SX_NONE),
};
static const sx_layout sxbx_pyinstaller_library = {UINT32_C(0x603000b4),"pyinstaller_library",sxbx_pyinstaller_library_fields,SX_COUNT(sxbx_pyinstaller_library_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyinstaller_toc_fields[] = {
 SX_FIELD("entry_size","int32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("compressed","uint8",16,1,SX_NONE),
 SX_FIELD("type","char",17,1,SX_ID),
};
static const sx_layout sxbx_pyinstaller_toc = {UINT32_C(0x603000b5),"pyinstaller_toc",sxbx_pyinstaller_toc_fields,SX_COUNT(sxbx_pyinstaller_toc_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_starkit_header_fields[] = {
 SX_FIELD("magic","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxbx_starkit_header = {UINT32_C(0x603000b6),"starkit_header",sxbx_starkit_header_fields,SX_COUNT(sxbx_starkit_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_starkit_commit_fields[] = {
 SX_FIELD("commit_tag","uint32",0,4,SX_FLAGS),
 SX_FIELD("footer_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("root_size_and_tag","uint32",8,4,SX_FLAGS),
 SX_FIELD("root_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxbx_starkit_commit = {UINT32_C(0x603000b7),"starkit_commit",sxbx_starkit_commit_fields,SX_COUNT(sxbx_starkit_commit_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_starkit_root_prefix_fields[] = {
 SX_FIELD("root_tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("schema_size_and_tag","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxbx_starkit_root_prefix = {UINT32_C(0x603000b8),"starkit_root_prefix",sxbx_starkit_root_prefix_fields,SX_COUNT(sxbx_starkit_root_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count1_fields[] = {
 SX_FIELD("row_count","metakit_msb128[1]",0,1,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count1 = {UINT32_C(0x603000b9),"starkit_row_count1",sxbx_starkit_row_count1_fields,SX_COUNT(sxbx_starkit_row_count1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count2_fields[] = {
 SX_FIELD("row_count","metakit_msb128[2]",0,2,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count2 = {UINT32_C(0x603000ba),"starkit_row_count2",sxbx_starkit_row_count2_fields,SX_COUNT(sxbx_starkit_row_count2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count3_fields[] = {
 SX_FIELD("row_count","metakit_msb128[3]",0,3,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count3 = {UINT32_C(0x603000bb),"starkit_row_count3",sxbx_starkit_row_count3_fields,SX_COUNT(sxbx_starkit_row_count3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count4_fields[] = {
 SX_FIELD("row_count","metakit_msb128[4]",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count4 = {UINT32_C(0x603000bc),"starkit_row_count4",sxbx_starkit_row_count4_fields,SX_COUNT(sxbx_starkit_row_count4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count5_fields[] = {
 SX_FIELD("row_count","metakit_msb128[5]",0,5,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count5 = {UINT32_C(0x603000bd),"starkit_row_count5",sxbx_starkit_row_count5_fields,SX_COUNT(sxbx_starkit_row_count5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count6_fields[] = {
 SX_FIELD("row_count","metakit_msb128[6]",0,6,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count6 = {UINT32_C(0x603000be),"starkit_row_count6",sxbx_starkit_row_count6_fields,SX_COUNT(sxbx_starkit_row_count6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count7_fields[] = {
 SX_FIELD("row_count","metakit_msb128[7]",0,7,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count7 = {UINT32_C(0x603000bf),"starkit_row_count7",sxbx_starkit_row_count7_fields,SX_COUNT(sxbx_starkit_row_count7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count8_fields[] = {
 SX_FIELD("row_count","metakit_msb128[8]",0,8,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count8 = {UINT32_C(0x603000c0),"starkit_row_count8",sxbx_starkit_row_count8_fields,SX_COUNT(sxbx_starkit_row_count8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count9_fields[] = {
 SX_FIELD("row_count","metakit_msb128[9]",0,9,SX_COUNT_PROP),
};
static const sx_layout sxbx_starkit_row_count9 = {UINT32_C(0x603000c1),"starkit_row_count9",sxbx_starkit_row_count9_fields,SX_COUNT(sxbx_starkit_row_count9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size1_fields[] = {
 SX_FIELD("column_size","metakit_msb128[1]",0,1,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size1 = {UINT32_C(0x603000c2),"starkit_column_size1",sxbx_starkit_column_size1_fields,SX_COUNT(sxbx_starkit_column_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size2_fields[] = {
 SX_FIELD("column_size","metakit_msb128[2]",0,2,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size2 = {UINT32_C(0x603000c3),"starkit_column_size2",sxbx_starkit_column_size2_fields,SX_COUNT(sxbx_starkit_column_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size3_fields[] = {
 SX_FIELD("column_size","metakit_msb128[3]",0,3,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size3 = {UINT32_C(0x603000c4),"starkit_column_size3",sxbx_starkit_column_size3_fields,SX_COUNT(sxbx_starkit_column_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size4_fields[] = {
 SX_FIELD("column_size","metakit_msb128[4]",0,4,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size4 = {UINT32_C(0x603000c5),"starkit_column_size4",sxbx_starkit_column_size4_fields,SX_COUNT(sxbx_starkit_column_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size5_fields[] = {
 SX_FIELD("column_size","metakit_msb128[5]",0,5,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size5 = {UINT32_C(0x603000c6),"starkit_column_size5",sxbx_starkit_column_size5_fields,SX_COUNT(sxbx_starkit_column_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size6_fields[] = {
 SX_FIELD("column_size","metakit_msb128[6]",0,6,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size6 = {UINT32_C(0x603000c7),"starkit_column_size6",sxbx_starkit_column_size6_fields,SX_COUNT(sxbx_starkit_column_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size7_fields[] = {
 SX_FIELD("column_size","metakit_msb128[7]",0,7,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size7 = {UINT32_C(0x603000c8),"starkit_column_size7",sxbx_starkit_column_size7_fields,SX_COUNT(sxbx_starkit_column_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size8_fields[] = {
 SX_FIELD("column_size","metakit_msb128[8]",0,8,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size8 = {UINT32_C(0x603000c9),"starkit_column_size8",sxbx_starkit_column_size8_fields,SX_COUNT(sxbx_starkit_column_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size9_fields[] = {
 SX_FIELD("column_size","metakit_msb128[9]",0,9,SX_SIZE),
};
static const sx_layout sxbx_starkit_column_size9 = {UINT32_C(0x603000ca),"starkit_column_size9",sxbx_starkit_column_size9_fields,SX_COUNT(sxbx_starkit_column_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset1_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[1]",0,1,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset1 = {UINT32_C(0x603000cb),"starkit_column_offset1",sxbx_starkit_column_offset1_fields,SX_COUNT(sxbx_starkit_column_offset1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset2_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[2]",0,2,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset2 = {UINT32_C(0x603000cc),"starkit_column_offset2",sxbx_starkit_column_offset2_fields,SX_COUNT(sxbx_starkit_column_offset2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset3_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[3]",0,3,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset3 = {UINT32_C(0x603000cd),"starkit_column_offset3",sxbx_starkit_column_offset3_fields,SX_COUNT(sxbx_starkit_column_offset3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset4_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[4]",0,4,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset4 = {UINT32_C(0x603000ce),"starkit_column_offset4",sxbx_starkit_column_offset4_fields,SX_COUNT(sxbx_starkit_column_offset4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset5_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[5]",0,5,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset5 = {UINT32_C(0x603000cf),"starkit_column_offset5",sxbx_starkit_column_offset5_fields,SX_COUNT(sxbx_starkit_column_offset5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset6_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[6]",0,6,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset6 = {UINT32_C(0x603000d0),"starkit_column_offset6",sxbx_starkit_column_offset6_fields,SX_COUNT(sxbx_starkit_column_offset6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset7_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[7]",0,7,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset7 = {UINT32_C(0x603000d1),"starkit_column_offset7",sxbx_starkit_column_offset7_fields,SX_COUNT(sxbx_starkit_column_offset7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset8_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[8]",0,8,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset8 = {UINT32_C(0x603000d2),"starkit_column_offset8",sxbx_starkit_column_offset8_fields,SX_COUNT(sxbx_starkit_column_offset8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset9_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[9]",0,9,SX_OFFSET),
};
static const sx_layout sxbx_starkit_column_offset9 = {UINT32_C(0x603000d3),"starkit_column_offset9",sxbx_starkit_column_offset9_fields,SX_COUNT(sxbx_starkit_column_offset9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta1_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[1]",0,1,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta1 = {UINT32_C(0x603000d4),"starkit_memo_row_delta1",sxbx_starkit_memo_row_delta1_fields,SX_COUNT(sxbx_starkit_memo_row_delta1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta2_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[2]",0,2,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta2 = {UINT32_C(0x603000d5),"starkit_memo_row_delta2",sxbx_starkit_memo_row_delta2_fields,SX_COUNT(sxbx_starkit_memo_row_delta2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta3_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[3]",0,3,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta3 = {UINT32_C(0x603000d6),"starkit_memo_row_delta3",sxbx_starkit_memo_row_delta3_fields,SX_COUNT(sxbx_starkit_memo_row_delta3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta4_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[4]",0,4,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta4 = {UINT32_C(0x603000d7),"starkit_memo_row_delta4",sxbx_starkit_memo_row_delta4_fields,SX_COUNT(sxbx_starkit_memo_row_delta4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta5_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[5]",0,5,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta5 = {UINT32_C(0x603000d8),"starkit_memo_row_delta5",sxbx_starkit_memo_row_delta5_fields,SX_COUNT(sxbx_starkit_memo_row_delta5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta6_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[6]",0,6,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta6 = {UINT32_C(0x603000d9),"starkit_memo_row_delta6",sxbx_starkit_memo_row_delta6_fields,SX_COUNT(sxbx_starkit_memo_row_delta6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta7_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[7]",0,7,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta7 = {UINT32_C(0x603000da),"starkit_memo_row_delta7",sxbx_starkit_memo_row_delta7_fields,SX_COUNT(sxbx_starkit_memo_row_delta7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta8_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[8]",0,8,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta8 = {UINT32_C(0x603000db),"starkit_memo_row_delta8",sxbx_starkit_memo_row_delta8_fields,SX_COUNT(sxbx_starkit_memo_row_delta8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta9_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[9]",0,9,SX_NONE),
};
static const sx_layout sxbx_starkit_memo_row_delta9 = {UINT32_C(0x603000dc),"starkit_memo_row_delta9",sxbx_starkit_memo_row_delta9_fields,SX_COUNT(sxbx_starkit_memo_row_delta9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag1_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[1]",0,1,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag1 = {UINT32_C(0x603000dd),"starkit_view_tag1",sxbx_starkit_view_tag1_fields,SX_COUNT(sxbx_starkit_view_tag1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag2_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[2]",0,2,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag2 = {UINT32_C(0x603000de),"starkit_view_tag2",sxbx_starkit_view_tag2_fields,SX_COUNT(sxbx_starkit_view_tag2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag3_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[3]",0,3,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag3 = {UINT32_C(0x603000df),"starkit_view_tag3",sxbx_starkit_view_tag3_fields,SX_COUNT(sxbx_starkit_view_tag3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag4_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[4]",0,4,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag4 = {UINT32_C(0x603000e0),"starkit_view_tag4",sxbx_starkit_view_tag4_fields,SX_COUNT(sxbx_starkit_view_tag4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag5_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[5]",0,5,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag5 = {UINT32_C(0x603000e1),"starkit_view_tag5",sxbx_starkit_view_tag5_fields,SX_COUNT(sxbx_starkit_view_tag5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag6_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[6]",0,6,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag6 = {UINT32_C(0x603000e2),"starkit_view_tag6",sxbx_starkit_view_tag6_fields,SX_COUNT(sxbx_starkit_view_tag6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag7_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[7]",0,7,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag7 = {UINT32_C(0x603000e3),"starkit_view_tag7",sxbx_starkit_view_tag7_fields,SX_COUNT(sxbx_starkit_view_tag7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag8_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[8]",0,8,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag8 = {UINT32_C(0x603000e4),"starkit_view_tag8",sxbx_starkit_view_tag8_fields,SX_COUNT(sxbx_starkit_view_tag8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag9_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[9]",0,9,SX_NONE),
};
static const sx_layout sxbx_starkit_view_tag9 = {UINT32_C(0x603000e5),"starkit_view_tag9",sxbx_starkit_view_tag9_fields,SX_COUNT(sxbx_starkit_view_tag9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxbx_evb_header = {UINT32_C(0x603000e6),"evb_header",sxbx_evb_header_fields,SX_COUNT(sxbx_evb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_table_prefix_fields[] = {
 SX_FIELD("node_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown1","uint32",4,4,SX_NONE),
 SX_FIELD("unknown2","uint32",8,4,SX_NONE),
 SX_FIELD("root_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_evb_table_prefix = {UINT32_C(0x603000e7),"evb_table_prefix",sxbx_evb_table_prefix_fields,SX_COUNT(sxbx_evb_table_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_node_fields[] = {
 SX_FIELD("node_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown1","uint32",4,4,SX_NONE),
 SX_FIELD("unknown2","uint32",8,4,SX_NONE),
 SX_FIELD("child_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_evb_node = {UINT32_C(0x603000e8),"evb_node",sxbx_evb_node_fields,SX_COUNT(sxbx_evb_node_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_node_type_fields[] = {
 SX_FIELD("type","uint8",0,1,SX_ID),
};
static const sx_layout sxbx_evb_node_type = {UINT32_C(0x603000e9),"evb_node_type",sxbx_evb_node_type_fields,SX_COUNT(sxbx_evb_node_type_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_file_stored_size_fields[] = {
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbx_evb_file_stored_size = {UINT32_C(0x603000ea),"evb_file_stored_size",sxbx_evb_file_stored_size_fields,SX_COUNT(sxbx_evb_file_stored_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gta_img_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_gta_img_header = {UINT32_C(0x603000eb),"gta_img_header",sxbx_gta_img_header_fields,SX_COUNT(sxbx_gta_img_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gta_img_entry_fields[] = {
 SX_FIELD("sector_offset","uint32",0,4,SX_NONE),
 SX_FIELD("sector_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",6,2,SX_NONE),
 SX_FIELD("filename","char[24]",8,24,SX_NONE),
};
static const sx_layout sxbx_gta_img_entry = {UINT32_C(0x603000ec),"gta_img_entry",sxbx_gta_img_entry_fields,SX_COUNT(sxbx_gta_img_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pam_pak_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("entry_count","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("unknown1","uint16",10,2,SX_NONE),
 SX_FIELD("string_table_size","uint32",12,4,SX_SIZE),
 SX_FIELD("unknown2","uint8[20]",16,20,SX_NONE),
};
static const sx_layout sxbx_pam_pak_header = {UINT32_C(0x603000ed),"pam_pak_header",sxbx_pam_pak_header_fields,SX_COUNT(sxbx_pam_pak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pam_pak_data_fields[] = {
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxbx_pam_pak_data = {UINT32_C(0x603000ee),"pam_pak_data",sxbx_pam_pak_data_fields,SX_COUNT(sxbx_pam_pak_data_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pam_pak_directory_marker_fields[] = {
 SX_FIELD("size_marker","uint32",0,4,SX_FLAGS),
 SX_FIELD("offset_marker","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxbx_pam_pak_directory_marker = {UINT32_C(0x603000ef),"pam_pak_directory_marker",sxbx_pam_pak_directory_marker_fields,SX_COUNT(sxbx_pam_pak_directory_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pam_pak_index_fields[] = {
 SX_FIELD("entry_id","uint32",0,4,SX_ID),
 SX_FIELD("data_index","uint16",4,2,SX_NONE),
 SX_FIELD("unknown1","uint16",6,2,SX_NONE),
 SX_FIELD("name_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("unknown2","uint32",12,4,SX_NONE),
 SX_FIELD("parent_id","uint32",16,4,SX_ID),
 SX_FIELD("unknown3","uint32",20,4,SX_NONE),
};
static const sx_layout sxbx_pam_pak_index = {UINT32_C(0x603000f0),"pam_pak_index",sxbx_pam_pak_index_fields,SX_COUNT(sxbx_pam_pak_index_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pfpk_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxbx_pfpk_header = {UINT32_C(0x603000f1),"pfpk_header",sxbx_pfpk_header_fields,SX_COUNT(sxbx_pfpk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pfpk_name_size_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxbx_pfpk_name_size = {UINT32_C(0x603000f2),"pfpk_name_size",sxbx_pfpk_name_size_fields,SX_COUNT(sxbx_pfpk_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pfpk_member_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxbx_pfpk_member = {UINT32_C(0x603000f3),"pfpk_member",sxbx_pfpk_member_fields,SX_COUNT(sxbx_pfpk_member_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_offset32_fields[] = {
 SX_FIELD("file_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxbx_pyz_marshal_offset32 = {UINT32_C(0x603000f4),"pyz_marshal_offset32",sxbx_pyz_marshal_offset32_fields,SX_COUNT(sxbx_pyz_marshal_offset32_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_size32_fields[] = {
 SX_FIELD("packed_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxbx_pyz_marshal_size32 = {UINT32_C(0x603000f5),"pyz_marshal_size32",sxbx_pyz_marshal_size32_fields,SX_COUNT(sxbx_pyz_marshal_size32_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_offset64_fields[] = {
 SX_FIELD("file_offset","int64",0,8,SX_OFFSET),
};
static const sx_layout sxbx_pyz_marshal_offset64 = {UINT32_C(0x603000f6),"pyz_marshal_offset64",sxbx_pyz_marshal_offset64_fields,SX_COUNT(sxbx_pyz_marshal_offset64_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_size64_fields[] = {
 SX_FIELD("packed_size","int64",0,8,SX_SIZE),
};
static const sx_layout sxbx_pyz_marshal_size64 = {UINT32_C(0x603000f7),"pyz_marshal_size64",sxbx_pyz_marshal_size64_fields,SX_COUNT(sxbx_pyz_marshal_size64_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_file_modern_fields[] = {
 SX_FIELD("reserved0","uint16",0,2,SX_NONE),
 SX_FIELD("unpacked_size","uint32",2,4,SX_SIZE),
 SX_FIELD("unknown","uint32",6,4,SX_NONE),
 SX_FIELD("filetime1","uint64",10,8,SX_NONE),
 SX_FIELD("filetime2","uint64",18,8,SX_NONE),
 SX_FIELD("filetime3","uint64",26,8,SX_NONE),
 SX_FIELD("reserved1","uint8[15]",34,15,SX_NONE),
 SX_FIELD("packed_size","uint32",49,4,SX_SIZE),
};
static const sx_layout sxbx_evb_file_modern = {UINT32_C(0x603000f8),"evb_file_modern",sxbx_evb_file_modern_fields,SX_COUNT(sxbx_evb_file_modern_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_file_legacy_fields[] = {
 SX_FIELD("reserved0","uint16",0,2,SX_NONE),
 SX_FIELD("unpacked_size","uint32",2,4,SX_SIZE),
 SX_FIELD("unknown","uint32",6,4,SX_NONE),
 SX_FIELD("filetime1","uint64",10,8,SX_NONE),
 SX_FIELD("filetime2","uint64",18,8,SX_NONE),
 SX_FIELD("filetime3","uint64",26,8,SX_NONE),
 SX_FIELD("reserved1","uint8[7]",34,7,SX_NONE),
 SX_FIELD("packed_size","uint32",41,4,SX_SIZE),
 SX_FIELD("reserved2","uint32",45,4,SX_NONE),
};
static const sx_layout sxbx_evb_file_legacy = {UINT32_C(0x603000f9),"evb_file_legacy",sxbx_evb_file_legacy_fields,SX_COUNT(sxbx_evb_file_legacy_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_chunk_header_fields[] = {
 SX_FIELD("table_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
};
static const sx_layout sxbx_evb_chunk_header = {UINT32_C(0x603000fa),"evb_chunk_header",sxbx_evb_chunk_header_fields,SX_COUNT(sxbx_evb_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_chunk_entry_fields[] = {
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("total_size","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint32",8,4,SX_NONE),
};
static const sx_layout sxbx_evb_chunk_entry = {UINT32_C(0x603000fb),"evb_chunk_entry",sxbx_evb_chunk_entry_fields,SX_COUNT(sxbx_evb_chunk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evb_ap32_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",4,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("unpacked_size","uint32",16,4,SX_SIZE),
 SX_FIELD("unpacked_crc32","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxbx_evb_ap32 = {UINT32_C(0x603000fc),"evb_ap32",sxbx_evb_ap32_fields,SX_COUNT(sxbx_evb_ap32_fields),SX_LE};
static bool sxbx_metakit_comment(xx_data_struct_record*r){size_t n=0;const uint8_t*b=xx_var_get_bytes(&r->value,&n);if(!b||!n||n>9)return true;uint64_t v=0;for(size_t i=0;i<n;i++){if(((b[i]&128)!=0)!=(i+1==n))return xx_data_struct_record_set_comment(r,L"Invalid Metakit varint framing; encoded bytes preserved");v=(v<<7)|(b[i]&127);}bool hex=!xx_rt_wcscmp(r->name,L"column_offset");char a[40];wchar_t out[40];int z=xx_rt_snprintf(a,sizeof(a),hex?"0x%llX":"%llu",(unsigned long long)v);if(z<0||z>=40)return false;for(int i=0;i<=z;i++)out[i]=(unsigned char)a[i];xx_var_set_u64(&r->value,v);return xx_data_struct_record_set_display_value(r,out)&&xx_data_struct_record_set_comment(r,hex?L"Decoded Metakit varint; byte offset relative to the embedded Metakit datafile.":L"Decoded Metakit MSB-first seven-bit groups; high bit marks the final physical byte.");}

static const sx_layout *const sx_binaryextra_layouts[] = {
 &sxbx_clp_header,
 &sxbx_clp_record,
 &sxbx_lmd_header,
 &sxbx_lmd_record_offset,
 &sxbx_lmd_flags,
 &sxbx_lmd_name_length,
 &sxbx_lmd_optional_value,
 &sxbx_lmd_bitmap_size,
 &sxbx_lmd_block_header,
 &sxbx_vice_snapshot_header,
 &sxbx_vice_version_header,
 &sxbx_vice_module_header,
 &sxbx_mcap_magic,
 &sxbx_mcap_record_header,
 &sxbx_mcap_schema_id,
 &sxbx_mcap_channel_ids,
 &sxbx_mcap_message,
 &sxbx_mcap_attachment_times,
 &sxbx_mcap_footer,
 &sxbx_mcap_crc,
 &sxbx_mcap_map_size,
 &sxbx_mcap_string_size,
 &sxbx_mcap_data_size,
 &sxbx_mcap_attachment_size,
 &sxbx_regf_header,
 &sxbx_regf_checksum,
 &sxbx_regf_hbin,
 &sxbx_regf_cell,
 &sxbx_regf_nk,
 &sxbx_regf_sk,
 &sxbx_regf_list,
 &sxbx_regf_list_offset,
 &sxbx_regf_list_hash,
 &sxbx_regf_vk,
 &sxbx_regf_db,
 &sxbx_evtx_header,
 &sxbx_evtx_chunk,
 &sxbx_evtx_string_offset,
 &sxbx_evtx_template_offset,
 &sxbx_evtx_record,
 &sxbx_evtx_record_trailer,
 &sxbx_kafka_batch,
 &sxbx_kafka_attributes,
 &sxbx_kafka_record_size1,
 &sxbx_kafka_record_size2,
 &sxbx_kafka_record_size3,
 &sxbx_kafka_record_size4,
 &sxbx_kafka_record_size5,
 &sxbx_kafka_record_size6,
 &sxbx_kafka_record_size7,
 &sxbx_kafka_record_size8,
 &sxbx_kafka_record_size9,
 &sxbx_kafka_record_size10,
 &sxbx_kafka_timestamp_delta1,
 &sxbx_kafka_timestamp_delta2,
 &sxbx_kafka_timestamp_delta3,
 &sxbx_kafka_timestamp_delta4,
 &sxbx_kafka_timestamp_delta5,
 &sxbx_kafka_timestamp_delta6,
 &sxbx_kafka_timestamp_delta7,
 &sxbx_kafka_timestamp_delta8,
 &sxbx_kafka_timestamp_delta9,
 &sxbx_kafka_timestamp_delta10,
 &sxbx_kafka_offset_delta1,
 &sxbx_kafka_offset_delta2,
 &sxbx_kafka_offset_delta3,
 &sxbx_kafka_offset_delta4,
 &sxbx_kafka_offset_delta5,
 &sxbx_kafka_offset_delta6,
 &sxbx_kafka_offset_delta7,
 &sxbx_kafka_offset_delta8,
 &sxbx_kafka_offset_delta9,
 &sxbx_kafka_offset_delta10,
 &sxbx_kafka_nullable_size1,
 &sxbx_kafka_nullable_size2,
 &sxbx_kafka_nullable_size3,
 &sxbx_kafka_nullable_size4,
 &sxbx_kafka_nullable_size5,
 &sxbx_kafka_nullable_size6,
 &sxbx_kafka_nullable_size7,
 &sxbx_kafka_nullable_size8,
 &sxbx_kafka_nullable_size9,
 &sxbx_kafka_nullable_size10,
 &sxbx_kafka_header_count1,
 &sxbx_kafka_header_count2,
 &sxbx_kafka_header_count3,
 &sxbx_kafka_header_count4,
 &sxbx_kafka_header_count5,
 &sxbx_kafka_header_count6,
 &sxbx_kafka_header_count7,
 &sxbx_kafka_header_count8,
 &sxbx_kafka_header_count9,
 &sxbx_kafka_header_count10,
 &sxbx_kafka_header_key_size1,
 &sxbx_kafka_header_key_size2,
 &sxbx_kafka_header_key_size3,
 &sxbx_kafka_header_key_size4,
 &sxbx_kafka_header_key_size5,
 &sxbx_kafka_header_key_size6,
 &sxbx_kafka_header_key_size7,
 &sxbx_kafka_header_key_size8,
 &sxbx_kafka_header_key_size9,
 &sxbx_kafka_header_key_size10,
 &sxbx_capnp_segment_table,
 &sxbx_capnp_struct_pointer,
 &sxbx_capnp_list_pointer,
 &sxbx_capnp_composite_tag,
 &sxbx_capnp_null_pointer,
 &sxbx_acb_header,
 &sxbx_acb_string_length,
 &sxbx_acb_palette,
 &sxbx_acb_color_rgb,
 &sxbx_acb_color_cmyk,
 &sxbx_acb_color_lab,
 &sxbx_acb_trailer,
 &sxbx_keytab_header,
 &sxbx_keytab_entry_length,
 &sxbx_keytab_component_count,
 &sxbx_keytab_string_length,
 &sxbx_kerberos_name_type,
 &sxbx_keytab_key,
 &sxbx_keytab_extended_kvno,
 &sxbx_ccache_header,
 &sxbx_ccache_tag,
 &sxbx_ccache_time_offset,
 &sxbx_ccache_principal,
 &sxbx_ccache_blob_size,
 &sxbx_ccache_key,
 &sxbx_ccache_times_flags,
 &sxbx_ccache_list_count,
 &sxbx_ccache_typed_blob,
 &sxbx_jks_header,
 &sxbx_jks_entry_tag,
 &sxbx_jks_string_size,
 &sxbx_jks_timestamp,
 &sxbx_jks_blob_size,
 &sxbx_jks_certificate_count,
 &sxbx_jks_digest,
 &sxbx_gguf_header,
 &sxbx_gguf_string_size,
 &sxbx_gguf_value_type,
 &sxbx_gguf_array,
 &sxbx_gguf_value0,
 &sxbx_gguf_value1,
 &sxbx_gguf_value2,
 &sxbx_gguf_value3,
 &sxbx_gguf_value4,
 &sxbx_gguf_value5,
 &sxbx_gguf_value6,
 &sxbx_gguf_value7,
 &sxbx_gguf_value10,
 &sxbx_gguf_value11,
 &sxbx_gguf_value12,
 &sxbx_gguf_dimensions,
 &sxbx_gguf_dimension,
 &sxbx_gguf_tensor_storage,
 &sxbx_nvp_header,
 &sxbx_nvp_directory,
 &sxbx_nvp_record,
 &sxbx_nvp_jpeg_size,
 &sxbx_nvp_string_list,
 &sxbx_lbrcobol_title,
 &sxbx_lbrcobol_directory_header,
 &sxbx_lbrcobol_header_constants,
 &sxbx_lbrcobol_member,
 &sxbx_lbrcobol_member_tail,
 &sxbx_pyz_header_le,
 &sxbx_pyz_header_be,
 &sxbx_pyz_marshal_tag,
 &sxbx_pyz_marshal_int32,
 &sxbx_pyz_marshal_int64,
 &sxbx_pyz_marshal_length,
 &sxbx_pyz_marshal_count,
 &sxbx_pyz_marshal_short_count,
 &sxbx_pyz_marshal_short_length,
 &sxbx_pyz_marshal_reference,
 &sxbx_pyz_marshal_long_digits,
 &sxbx_pyz_marshal_digit,
 &sxbx_pyinstaller_cookie24,
 &sxbx_pyinstaller_library,
 &sxbx_pyinstaller_toc,
 &sxbx_starkit_header,
 &sxbx_starkit_commit,
 &sxbx_starkit_root_prefix,
 &sxbx_starkit_row_count1,
 &sxbx_starkit_row_count2,
 &sxbx_starkit_row_count3,
 &sxbx_starkit_row_count4,
 &sxbx_starkit_row_count5,
 &sxbx_starkit_row_count6,
 &sxbx_starkit_row_count7,
 &sxbx_starkit_row_count8,
 &sxbx_starkit_row_count9,
 &sxbx_starkit_column_size1,
 &sxbx_starkit_column_size2,
 &sxbx_starkit_column_size3,
 &sxbx_starkit_column_size4,
 &sxbx_starkit_column_size5,
 &sxbx_starkit_column_size6,
 &sxbx_starkit_column_size7,
 &sxbx_starkit_column_size8,
 &sxbx_starkit_column_size9,
 &sxbx_starkit_column_offset1,
 &sxbx_starkit_column_offset2,
 &sxbx_starkit_column_offset3,
 &sxbx_starkit_column_offset4,
 &sxbx_starkit_column_offset5,
 &sxbx_starkit_column_offset6,
 &sxbx_starkit_column_offset7,
 &sxbx_starkit_column_offset8,
 &sxbx_starkit_column_offset9,
 &sxbx_starkit_memo_row_delta1,
 &sxbx_starkit_memo_row_delta2,
 &sxbx_starkit_memo_row_delta3,
 &sxbx_starkit_memo_row_delta4,
 &sxbx_starkit_memo_row_delta5,
 &sxbx_starkit_memo_row_delta6,
 &sxbx_starkit_memo_row_delta7,
 &sxbx_starkit_memo_row_delta8,
 &sxbx_starkit_memo_row_delta9,
 &sxbx_starkit_view_tag1,
 &sxbx_starkit_view_tag2,
 &sxbx_starkit_view_tag3,
 &sxbx_starkit_view_tag4,
 &sxbx_starkit_view_tag5,
 &sxbx_starkit_view_tag6,
 &sxbx_starkit_view_tag7,
 &sxbx_starkit_view_tag8,
 &sxbx_starkit_view_tag9,
 &sxbx_evb_header,
 &sxbx_evb_table_prefix,
 &sxbx_evb_node,
 &sxbx_evb_node_type,
 &sxbx_evb_file_stored_size,
 &sxbx_gta_img_header,
 &sxbx_gta_img_entry,
 &sxbx_pam_pak_header,
 &sxbx_pam_pak_data,
 &sxbx_pam_pak_directory_marker,
 &sxbx_pam_pak_index,
 &sxbx_pfpk_header,
 &sxbx_pfpk_name_size,
 &sxbx_pfpk_member,
 &sxbx_pyz_marshal_offset32,
 &sxbx_pyz_marshal_size32,
 &sxbx_pyz_marshal_offset64,
 &sxbx_pyz_marshal_size64,
 &sxbx_evb_file_modern,
 &sxbx_evb_file_legacy,
 &sxbx_evb_chunk_header,
 &sxbx_evb_chunk_entry,
 &sxbx_evb_ap32,
};
static bool sx_binaryextra_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x60300000U||id>=0x60310000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x603000b9U: return sxbx_metakit_comment(r);
 case 0x603000baU: return sxbx_metakit_comment(r);
 case 0x603000bbU: return sxbx_metakit_comment(r);
 case 0x603000bcU: return sxbx_metakit_comment(r);
 case 0x603000bdU: return sxbx_metakit_comment(r);
 case 0x603000beU: return sxbx_metakit_comment(r);
 case 0x603000bfU: return sxbx_metakit_comment(r);
 case 0x603000c0U: return sxbx_metakit_comment(r);
 case 0x603000c1U: return sxbx_metakit_comment(r);
 case 0x603000c2U: return sxbx_metakit_comment(r);
 case 0x603000c3U: return sxbx_metakit_comment(r);
 case 0x603000c4U: return sxbx_metakit_comment(r);
 case 0x603000c5U: return sxbx_metakit_comment(r);
 case 0x603000c6U: return sxbx_metakit_comment(r);
 case 0x603000c7U: return sxbx_metakit_comment(r);
 case 0x603000c8U: return sxbx_metakit_comment(r);
 case 0x603000c9U: return sxbx_metakit_comment(r);
 case 0x603000caU: return sxbx_metakit_comment(r);
 case 0x603000cbU: return sxbx_metakit_comment(r);
 case 0x603000ccU: return sxbx_metakit_comment(r);
 case 0x603000cdU: return sxbx_metakit_comment(r);
 case 0x603000ceU: return sxbx_metakit_comment(r);
 case 0x603000cfU: return sxbx_metakit_comment(r);
 case 0x603000d0U: return sxbx_metakit_comment(r);
 case 0x603000d1U: return sxbx_metakit_comment(r);
 case 0x603000d2U: return sxbx_metakit_comment(r);
 case 0x603000d3U: return sxbx_metakit_comment(r);
 case 0x603000d4U: return sxbx_metakit_comment(r);
 case 0x603000d5U: return sxbx_metakit_comment(r);
 case 0x603000d6U: return sxbx_metakit_comment(r);
 case 0x603000d7U: return sxbx_metakit_comment(r);
 case 0x603000d8U: return sxbx_metakit_comment(r);
 case 0x603000d9U: return sxbx_metakit_comment(r);
 case 0x603000daU: return sxbx_metakit_comment(r);
 case 0x603000dbU: return sxbx_metakit_comment(r);
 case 0x603000dcU: return sxbx_metakit_comment(r);
 case 0x603000ddU: return sxbx_metakit_comment(r);
 case 0x603000deU: return sxbx_metakit_comment(r);
 case 0x603000dfU: return sxbx_metakit_comment(r);
 case 0x603000e0U: return sxbx_metakit_comment(r);
 case 0x603000e1U: return sxbx_metakit_comment(r);
 case 0x603000e2U: return sxbx_metakit_comment(r);
 case 0x603000e3U: return sxbx_metakit_comment(r);
 case 0x603000e4U: return sxbx_metakit_comment(r);
 case 0x603000e5U: return sxbx_metakit_comment(r);
 case 0x60300002U:
 if(!xx_rt_wcscmp(r->name,L"format_name_or_reserved"))text=L"Physical 79-byte record tail; encoding and meaning vary by clipboard writer.";
 break;
 case 0x60300005U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0 compressed bitmap; bit1 name present; bit2 optional value present; bit3 bitmap record.";
 break;
 case 0x60300009U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Byte count after this four-byte length, including the method byte.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0x80 stored bytes; 0x40 encoded LMD bitmap block.";
 break;
 case 0x6030000cU:
 if(!xx_rt_wcscmp(r->name,L"module_size"))text=L"Includes the 22-byte module header.";
 break;
 case 0x60300011U:
 if(!xx_rt_wcscmp(r->name,L"log_time"))text=L"Nanoseconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"publish_time"))text=L"Nanoseconds since Unix epoch.";
 break;
 case 0x60300012U:
 if(!xx_rt_wcscmp(r->name,L"log_time"))text=L"Nanoseconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"create_time"))text=L"Nanoseconds since Unix epoch.";
 break;
 case 0x60300019U:
 if(!xx_rt_wcscmp(r->name,L"last_written"))text=L"Windows FILETIME, 100-nanosecond intervals since 1601 UTC.";
 if(!xx_rt_wcscmp(r->name,L"root_cell_offset"))text=L"Relative to the hive-bin data area at file offset 0x1000.";
 if(!xx_rt_wcscmp(r->name,L"clustering_factor"))text=L"Underlying logical sector size divided by 512.";
 if(!xx_rt_wcscmp(r->name,L"filename"))text=L"Physical UTF-16LE filename fragment; not necessarily terminated.";
 break;
 case 0x6030001bU:
 if(!xx_rt_wcscmp(r->name,L"bin_offset"))text=L"Relative to the hive-bin data area at file offset 0x1000.";
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Optional FILETIME in the first bin; later bins may contain stale data.";
 break;
 case 0x6030001cU:
 if(!xx_rt_wcscmp(r->name,L"signed_cell_size"))text=L"Absolute magnitude is the total cell byte count; negative means allocated and positive means free.";
 break;
 case 0x6030001dU:
 if(!xx_rt_wcscmp(r->name,L"parent_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"subkey_list_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"volatile_list_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"values_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"security_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 if(!xx_rt_wcscmp(r->name,L"class_offset"))text=L"Cell offset relative to the hive-bin area; 0xFFFFFFFF is an absent-reference sentinel.";
 break;
 case 0x60300020U:
 if(!xx_rt_wcscmp(r->name,L"cell_offset"))text=L"Relative to the hive-bin data area.";
 break;
 case 0x60300021U:
 if(!xx_rt_wcscmp(r->name,L"cell_offset"))text=L"Relative to the hive-bin data area.";
 if(!xx_rt_wcscmp(r->name,L"name_hash_or_hint"))text=L"lh: name hash; lf: first four compressed-name bytes.";
 break;
 case 0x60300022U:
 if(!xx_rt_wcscmp(r->name,L"data_size_flags"))text=L"High bit selects inline data; low 31 bits are the encoded byte count.";
 if(!xx_rt_wcscmp(r->name,L"data_offset_or_inline"))text=L"Hive-bin-relative cell offset, or up to four inline data bytes when data_size_flags has bit31 set.";
 break;
 case 0x60300025U:
 if(!xx_rt_wcscmp(r->name,L"last_record_offset"))text=L"Relative to this chunk.";
 if(!xx_rt_wcscmp(r->name,L"free_space_offset"))text=L"Relative to this chunk.";
 break;
 case 0x60300026U:
 if(!xx_rt_wcscmp(r->name,L"string_offset"))text=L"Relative to this chunk; zero means unused.";
 break;
 case 0x60300027U:
 if(!xx_rt_wcscmp(r->name,L"template_offset"))text=L"Relative to this chunk; zero means unused.";
 break;
 case 0x60300028U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Windows FILETIME, 100-nanosecond intervals since 1601 UTC.";
 break;
 case 0x6030002aU:
 if(!xx_rt_wcscmp(r->name,L"base_offset"))text=L"Logical Kafka log offset, not a physical byte offset.";
 if(!xx_rt_wcscmp(r->name,L"batch_length"))text=L"Bytes after the first 12 bytes of this batch.";
 if(!xx_rt_wcscmp(r->name,L"last_offset_delta"))text=L"Logical record-offset delta, not a byte offset.";
 if(!xx_rt_wcscmp(r->name,L"base_timestamp"))text=L"Milliseconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"max_timestamp"))text=L"Milliseconds since Unix epoch.";
 break;
 case 0x6030002cU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x6030002dU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x6030002eU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x6030002fU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300030U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300031U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300032U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300033U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300034U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300035U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Record bytes after this encoded length.";
 break;
 case 0x60300036U:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x60300037U:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x60300038U:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x60300039U:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003aU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003bU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003cU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003dU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003eU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x6030003fU:
 if(!xx_rt_wcscmp(r->name,L"timestamp_delta"))text=L"Signed delta from the batch base timestamp.";
 break;
 case 0x60300040U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300041U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300042U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300043U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300044U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300045U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300046U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300047U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300048U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x60300049U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Logical log-offset delta, not a byte offset.";
 break;
 case 0x6030004aU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004bU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004cU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004dU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004eU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x6030004fU:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300050U:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300051U:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300052U:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300053U:
 if(!xx_rt_wcscmp(r->name,L"nullable_size"))text=L"Byte count; -1 denotes a null value.";
 break;
 case 0x60300054U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300055U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300056U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300057U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300058U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x60300059U:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005aU:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005bU:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005cU:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005dU:
 if(!xx_rt_wcscmp(r->name,L"header_count"))text=L"Number of record headers.";
 break;
 case 0x6030005eU:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x6030005fU:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300060U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300061U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300062U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300063U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300064U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300065U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300066U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300067U:
 if(!xx_rt_wcscmp(r->name,L"header_key_size"))text=L"Header-key byte count.";
 break;
 case 0x60300068U:
 if(!xx_rt_wcscmp(r->name,L"segment_count_minus_one"))text=L"Stored segment count minus one. Native reader supports one unpacked segment.";
 if(!xx_rt_wcscmp(r->name,L"segment_words"))text=L"Number of 64-bit words in the segment.";
 break;
 case 0x60300069U:
 if(!xx_rt_wcscmp(r->name,L"offset_and_kind"))text=L"Low2bits=0; upper30bits are a signed word displacement from the word after this pointer.";
 if(!xx_rt_wcscmp(r->name,L"data_word_count"))text=L"Number of 64-bit words in the struct data section.";
 break;
 case 0x6030006aU:
 if(!xx_rt_wcscmp(r->name,L"offset_and_kind"))text=L"Low2bits=1; upper30bits are a signed word displacement.";
 if(!xx_rt_wcscmp(r->name,L"count_and_element_size"))text=L"Low3bits are element-size code; upper29bits are element count, or word count for inline-composite lists.";
 break;
 case 0x6030006bU:
 if(!xx_rt_wcscmp(r->name,L"element_count_and_kind"))text=L"Low2bits=0; upper30bits are the element count.";
 break;
 case 0x6030006fU:
 if(!xx_rt_wcscmp(r->name,L"color_space"))text=L"0 RGB; 2 CMYK; 7 Lab.";
 break;
 case 0x60300070U:
 if(!xx_rt_wcscmp(r->name,L"component_0"))text=L"Physical encoded color channel; Lab channels use the ACB byte encoding.";
 break;
 case 0x60300071U:
 if(!xx_rt_wcscmp(r->name,L"component_0"))text=L"Physical encoded color channel; Lab channels use the ACB byte encoding.";
 break;
 case 0x60300072U:
 if(!xx_rt_wcscmp(r->name,L"component_0"))text=L"Physical encoded color channel; Lab channels use the ACB byte encoding.";
 break;
 case 0x60300075U:
 if(!xx_rt_wcscmp(r->name,L"signed_entry_size"))text=L"Positive: entry byte count after this word; negative: deleted slot of the absolute byte count; zero: end marker.";
 break;
 case 0x60300079U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Seconds since Unix epoch.";
 break;
 case 0x60300081U:
 if(!xx_rt_wcscmp(r->name,L"auth_time"))text=L"Seconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"start_time"))text=L"Seconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"end_time"))text=L"Seconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"renew_until"))text=L"Seconds since Unix epoch.";
 break;
 case 0x60300085U:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"1 private key with certificate chain; 2 trusted certificate.";
 break;
 case 0x60300087U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Signed Java long: milliseconds since Unix epoch.";
 break;
 case 0x6030009cU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the aligned tensor-data area, not the start of the file.";
 break;
 case 0x6030009fU:
 if(!xx_rt_wcscmp(r->name,L"size_and_flags"))text=L"Low31bits are record payload byte count; top bit is preserved as an encoded flag.";
 break;
 case 0x603000a3U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Encoded block size; native payload coordinates use 128-byte blocks.";
 break;
 case 0x603000a5U:
 if(!xx_rt_wcscmp(r->name,L"payload_block"))text=L"Multiply by 128 for the file-relative byte offset.";
 if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time.";
 if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date.";
 break;
 case 0x603000a9U:
 if(!xx_rt_wcscmp(r->name,L"type_and_reference"))text=L"Low7bits are the Python marshal type code; highbit reserves a reference slot.";
 break;
 case 0x603000b3U:
 if(!xx_rt_wcscmp(r->name,L"toc_offset"))text=L"Relative to the package start, derived from the cookie end minus package_size.";
 break;
 case 0x603000b5U:
 if(!xx_rt_wcscmp(r->name,L"entry_size"))text=L"Includes this fixed18-byte prefix and padded NUL-terminated name.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the CArchive package start.";
 break;
 case 0x603000b7U:
 if(!xx_rt_wcscmp(r->name,L"footer_offset"))text=L"Relative to the embedded Metakit container.";
 if(!xx_rt_wcscmp(r->name,L"root_size_and_tag"))text=L"Highbit is the commit tag; low31bits are the root descriptor byte count.";
 if(!xx_rt_wcscmp(r->name,L"root_offset"))text=L"Relative to the embedded Metakit container.";
 break;
 case 0x603000b8U:
 if(!xx_rt_wcscmp(r->name,L"schema_size_and_tag"))text=L"Highbit terminates this encoded length; low7bits are schema string size.";
 break;
 case 0x603000e9U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"2 file; 3 directory.";
 break;
 case 0x603000ecU:
 if(!xx_rt_wcscmp(r->name,L"sector_offset"))text=L"Multiply by 2048 for the file-relative byte offset.";
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Number of 2048-byte sectors.";
 break;
 case 0x603000efU:
 if(!xx_rt_wcscmp(r->name,L"size_marker"))text=L"0xC0000000 marks a directory; not a byte size.";
 if(!xx_rt_wcscmp(r->name,L"offset_marker"))text=L"0xFFFFFFFF marks a directory; not a file offset.";
 break;
 case 0x603000f0U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string table after both entry arrays.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXBX_LIMIT 20000U
static bool sxbx_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxbx_read(sx_context *c,uint64_t p,void *b,size_t n){return sxbx_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxbx_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint16_t sxbx16(const uint8_t *b,bool be){return (uint16_t)sxbx_uint(b,2,be);}
static uint32_t sxbx32(const uint8_t *b,bool be){return (uint32_t)sxbx_uint(b,4,be);}
/* Native readers can authenticate aliases and damaged optional records. Keep
 * earlier bounded physical metadata, and leave conflicting later interpretations
 * opaque instead of discarding the entire useful header view. */
static bool sxbx_free(sx_context *c,uint64_t p,uint64_t n){for(size_t i=0;i<c->count;i++){uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<at+z&&at<p+n)return false;}return true;}
static bool sxbx_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(!sxbx_span(c,p,n))return false;if(!sxbx_free(c,p,n))return true;return c->count>=SXBX_LIMIT||sx_add(c,l,(int64_t)p,(int64_t)n);}
static bool sxbx_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n||n>SXBX_LIMIT||!sxbx_span(c,p,n*z))return true;if(!sxbx_free(c,p,n*z))return true;return c->count>=SXBX_LIMIT||sx_table(c,l,(int64_t)p,(int64_t)z,n);}
static bool sxbx_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v){uint8_t b[8];if(n>8||!sxbx_read(c,p,b,n))return false;*v=sxbx_uint(b,n,be);return true;}
static bool sxbx_counted(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l,unsigned width,bool be,unsigned multiplier){uint64_t z;if(*p>end||width>end-*p||!sxbx_word(c,*p,width,be,&z)||z>(end-*p-width)/multiplier||!sxbx_add(c,l,*p))return false;*p+=width+z*multiplier;return true;}
static bool sxbx_zero_string(sx_context*c,uint64_t*p,uint64_t end,unsigned width){for(unsigned i=0;i<4096;i++){uint64_t v;if(*p>end||width>end-*p||!sxbx_word(c,*p,width,false,&v))return false;*p+=width;if(!v)return true;}return false;}
static bool sxbx_lmd(sx_context*c){uint64_t n;if(!sxbx_add(c,&sxbx_lmd_header,0)||!sxbx_word(c,9,4,false,&n)||n>4096||!sxbx_span(c,13,n*4)||!sxbx_table(c,&sxbx_lmd_record_offset,13,n))return false;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint64_t p,end=(uint64_t)c->size,flags,z;if(!sxbx_word(c,13+i*4,4,false,&p)||(i+1<n&&!sxbx_word(c,17+i*4,4,false,&end))||p<13+n*4||end<=p||end>(uint64_t)c->size||!sxbx_word(c,p,1,false,&flags)||!sxbx_add(c,&sxbx_lmd_flags,p))continue;p++;if(flags&2){if(!sxbx_counted(c,&p,end,&sxbx_lmd_name_length,1,false,1))continue;}if(flags&4){if(end-p<4||!sxbx_add(c,&sxbx_lmd_optional_value,p))continue;p+=4;}if(flags&8){if(end-p<4||!sxbx_word(c,p,4,false,&z)||z!=end-p-4||!sxbx_add(c,&sxbx_lmd_bitmap_size,p))continue;p+=4;if(flags&1)while(p<end&&c->count<SXBX_LIMIT){if(end-p<5||!sxbx_word(c,p,4,false,&z)||z<1||z>end-p-4)break;if(!sxbx_add(c,&sxbx_lmd_block_header,p))return false;p+=4+z;}}}return true;}
static bool sxbx_vice(sx_context*c){uint8_t b[22];uint64_t p=37;if(!sxbx_add(c,&sxbx_vice_snapshot_header,0))return false;if(sxbx_read(c,p,b,21)&&!xx_rt_memcmp(b,"VICE Version\x1a",13)){if(!sxbx_add(c,&sxbx_vice_version_header,p))return false;p+=21;}for(unsigned i=0;i<4096&&c->count<SXBX_LIMIT;i++){if(!sxbx_read(c,p,b,22))break;uint64_t z=sxbx32(b+18,false);if(z<=22||!sxbx_span(c,p,z))break;if(!sxbx_add(c,&sxbx_vice_module_header,p))return false;p+=z;}return true;}
static bool sxbx_mcap_map(sx_context*c,uint64_t*p,uint64_t end){uint64_t z;if(*p>end||end-*p<4||!sxbx_word(c,*p,4,false,&z)||z>end-*p-4||!sxbx_add(c,&sxbx_mcap_map_size,*p))return false;*p+=4;uint64_t stop=*p+z;for(unsigned i=0;*p<stop&&i<128;i++)if(!sxbx_counted(c,p,stop,&sxbx_mcap_string_size,4,false,1)||!sxbx_counted(c,p,stop,&sxbx_mcap_string_size,4,false,1))return false;return *p==stop;}
static bool sxbx_mcap(sx_context*c){uint8_t b[9];uint64_t p=8;if(!sxbx_add(c,&sxbx_mcap_magic,0))return false;while(c->count<SXBX_LIMIT&&p<(uint64_t)c->size){if(sxbx_read(c,p,b,8)&&!xx_rt_memcmp(b,"\x89MCAP0\r\n",8)){return sxbx_add(c,&sxbx_mcap_magic,p);}if(!sxbx_read(c,p,b,9))break;uint64_t z=sxbx_uint(b+1,8,false);if(!sxbx_span(c,p+9,z))break;if(!sxbx_add(c,&sxbx_mcap_record_header,p))return false;uint64_t q=p+9,end=q+z;size_t keep=c->count;bool ok=true;
 switch(b[0]){case 1:ok=sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1);break;
 case 2:ok=z==20&&sxbx_add(c,&sxbx_mcap_footer,q);break;
 case 3:ok=z>=2&&sxbx_add(c,&sxbx_mcap_schema_id,q);q+=2;ok=ok&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_data_size,4,false,1);break;
 case 4:ok=z>=4&&sxbx_add(c,&sxbx_mcap_channel_ids,q);q+=4;ok=ok&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_mcap_map(c,&q,end);break;
 case 5:ok=z>=22&&sxbx_add(c,&sxbx_mcap_message,q);break;
 case 9:ok=z>=16&&sxbx_add(c,&sxbx_mcap_attachment_times,q);q+=16;ok=ok&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_counted(c,&q,end,&sxbx_mcap_attachment_size,8,false,1)&&end-q==4&&sxbx_add(c,&sxbx_mcap_crc,q);break;
 case 12:ok=sxbx_counted(c,&q,end,&sxbx_mcap_string_size,4,false,1)&&sxbx_mcap_map(c,&q,end);break;
 case 15:ok=z==4&&sxbx_add(c,&sxbx_mcap_crc,q);break;default:break;}if(!ok)c->count=keep;p=end;}return true;}
static bool sxbx_regf(sx_context*c){uint8_t b[80];if(!sxbx_add(c,&sxbx_regf_header,0)||!sxbx_add(c,&sxbx_regf_checksum,508))return false;uint64_t p=4096;for(unsigned bins=0;bins<SXBX_LIMIT&&c->count<SXBX_LIMIT;bins++){if(!sxbx_read(c,p,b,32)||xx_rt_memcmp(b,"hbin",4))break;uint64_t size=sxbx32(b+8,false);if(size<4096||size%4096||!sxbx_span(c,p,size))break;if(!sxbx_add(c,&sxbx_regf_hbin,p))return false;uint64_t q=p+32,end=p+size;while(q<end&&c->count<SXBX_LIMIT){if(!sxbx_read(c,q,b,4))break;int64_t signedsize=(int32_t)sxbx32(b,false);uint64_t z=signedsize<0?(uint64_t)-signedsize:(uint64_t)signedsize;if(z<8||z%8||z>end-q)break;if(!sxbx_add(c,&sxbx_regf_cell,q))return false;if(signedsize<0&&sxbx_read(c,q+4,b,(size_t)(z-4<76?z-4:76))){const sx_layout*l=NULL;uint64_t n=0;if(!xx_rt_memcmp(b,"nk",2)&&z>=80&&sxbx16(b+72,false)<=z-80)l=&sxbx_regf_nk;else if(!xx_rt_memcmp(b,"sk",2)&&z>=24&&sxbx32(b+16,false)<=z-24)l=&sxbx_regf_sk;else if(!xx_rt_memcmp(b,"vk",2)&&z>=24&&sxbx16(b+2,false)<=z-24)l=&sxbx_regf_vk;else if(!xx_rt_memcmp(b,"db",2)&&z>=12)l=&sxbx_regf_db;else if((!xx_rt_memcmp(b,"lf",2)||!xx_rt_memcmp(b,"lh",2)||!xx_rt_memcmp(b,"li",2)||!xx_rt_memcmp(b,"ri",2))&&z>=8){n=sxbx16(b+2,false);unsigned stride=(b[1]=='f'||b[1]=='h')?8:4;if(n<=(z-8)/stride){l=&sxbx_regf_list;if(!sxbx_table(c,stride==8?&sxbx_regf_list_hash:&sxbx_regf_list_offset,q+8,n))return false;}}if(l&&!sxbx_add(c,l,q+4))return false;}q+=z;}p=end;}return true;}
static bool sxbx_evtx(sx_context*c){uint64_t n;if(!sxbx_add(c,&sxbx_evtx_header,0)||!sxbx_word(c,42,4,false,&n))return false;if(n>1024)return true;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint64_t p=4096+i*65536,end;if(!sxbx_span(c,p,65536)||!sxbx_word(c,p+48,4,false,&end)||end<512||end>65536)break;if(!sxbx_add(c,&sxbx_evtx_chunk,p)||!sxbx_table(c,&sxbx_evtx_string_offset,p+128,64)||!sxbx_table(c,&sxbx_evtx_template_offset,p+384,32))return false;end+=p;uint64_t q=p+512;while(q<end&&c->count<SXBX_LIMIT){uint64_t magic,z;if(!sxbx_word(c,q,4,false,&magic)||magic!=0x2a2a||!sxbx_word(c,q+4,4,false,&z)||z<28||z%8||z>end-q)break;if(!sxbx_add(c,&sxbx_evtx_record,q)||!sxbx_add(c,&sxbx_evtx_record_trailer,q+z-4))return false;q+=z;}}return true;}
static const sx_layout *const sxbx_kafka_record_size[] = {&sxbx_kafka_record_size1,&sxbx_kafka_record_size2,&sxbx_kafka_record_size3,&sxbx_kafka_record_size4,&sxbx_kafka_record_size5,&sxbx_kafka_record_size6,&sxbx_kafka_record_size7,&sxbx_kafka_record_size8,&sxbx_kafka_record_size9,&sxbx_kafka_record_size10};
static const sx_layout *const sxbx_kafka_timestamp_delta[] = {&sxbx_kafka_timestamp_delta1,&sxbx_kafka_timestamp_delta2,&sxbx_kafka_timestamp_delta3,&sxbx_kafka_timestamp_delta4,&sxbx_kafka_timestamp_delta5,&sxbx_kafka_timestamp_delta6,&sxbx_kafka_timestamp_delta7,&sxbx_kafka_timestamp_delta8,&sxbx_kafka_timestamp_delta9,&sxbx_kafka_timestamp_delta10};
static const sx_layout *const sxbx_kafka_offset_delta[] = {&sxbx_kafka_offset_delta1,&sxbx_kafka_offset_delta2,&sxbx_kafka_offset_delta3,&sxbx_kafka_offset_delta4,&sxbx_kafka_offset_delta5,&sxbx_kafka_offset_delta6,&sxbx_kafka_offset_delta7,&sxbx_kafka_offset_delta8,&sxbx_kafka_offset_delta9,&sxbx_kafka_offset_delta10};
static const sx_layout *const sxbx_kafka_nullable_size[] = {&sxbx_kafka_nullable_size1,&sxbx_kafka_nullable_size2,&sxbx_kafka_nullable_size3,&sxbx_kafka_nullable_size4,&sxbx_kafka_nullable_size5,&sxbx_kafka_nullable_size6,&sxbx_kafka_nullable_size7,&sxbx_kafka_nullable_size8,&sxbx_kafka_nullable_size9,&sxbx_kafka_nullable_size10};
static const sx_layout *const sxbx_kafka_header_count[] = {&sxbx_kafka_header_count1,&sxbx_kafka_header_count2,&sxbx_kafka_header_count3,&sxbx_kafka_header_count4,&sxbx_kafka_header_count5,&sxbx_kafka_header_count6,&sxbx_kafka_header_count7,&sxbx_kafka_header_count8,&sxbx_kafka_header_count9,&sxbx_kafka_header_count10};
static const sx_layout *const sxbx_kafka_header_key_size[] = {&sxbx_kafka_header_key_size1,&sxbx_kafka_header_key_size2,&sxbx_kafka_header_key_size3,&sxbx_kafka_header_key_size4,&sxbx_kafka_header_key_size5,&sxbx_kafka_header_key_size6,&sxbx_kafka_header_key_size7,&sxbx_kafka_header_key_size8,&sxbx_kafka_header_key_size9,&sxbx_kafka_header_key_size10};
static bool sxbx_zig(sx_context*c,uint64_t*p,uint64_t end,const sx_layout *const*ls,int64_t*out){uint64_t u=0,start=*p;for(unsigned i=0;i<10;i++){uint64_t v;if(*p>=end||!sxbx_word(c,(*p)++,1,false,&v)||(i==9&&(v&254)))return false;u|=(v&127)<<(i*7);if(!(v&128)){*out=(int64_t)(u>>1)^-(int64_t)(u&1);return sxbx_add(c,ls[i],start);}}return false;}
static bool sxbx_kafka_blob(sx_context*c,uint64_t*p,uint64_t end,bool key){int64_t z;if(!sxbx_zig(c,p,end,key?sxbx_kafka_header_key_size:sxbx_kafka_nullable_size,&z)||z<(key?0:-1)||z>INT32_MAX)return false;if(z<0)return true;if((uint64_t)z>end-*p)return false;*p+=(uint64_t)z;return true;}
static bool sxbx_kafka(sx_context*c){uint64_t p=0;uint8_t b[61];for(unsigned batch=0;batch<SXBX_LIMIT&&c->count<SXBX_LIMIT;batch++){if(!sxbx_read(c,p,b,61)||b[16]!=2)break;int64_t length=(int32_t)sxbx32(b+8,true),count=(int32_t)sxbx32(b+57,true);if(length<49||count<0||count>2048||!sxbx_span(c,p,(uint64_t)length+12))break;if(!sxbx_add(c,&sxbx_kafka_batch,p))return false;uint64_t q=p+61,end=p+12+(uint64_t)length;for(int64_t i=0;i<count&&q<end&&c->count<SXBX_LIMIT;i++){size_t old=c->count;int64_t z,delta,headers;uint64_t rec=q;if(!sxbx_zig(c,&q,end,sxbx_kafka_record_size,&z)||z<6||z>INT32_MAX||(uint64_t)z>end-q){c->count=old;break;}uint64_t stop=q+(uint64_t)z;if(!sxbx_add(c,&sxbx_kafka_attributes,q++ )||!sxbx_zig(c,&q,stop,sxbx_kafka_timestamp_delta,&delta)||!sxbx_zig(c,&q,stop,sxbx_kafka_offset_delta,&delta)||delta<0||delta>INT32_MAX||!sxbx_kafka_blob(c,&q,stop,false)||!sxbx_kafka_blob(c,&q,stop,false)||!sxbx_zig(c,&q,stop,sxbx_kafka_header_count,&headers)||headers<0||headers>256){c->count=old;break;}bool ok=true;for(int64_t j=0;j<headers;j++)if(!sxbx_kafka_blob(c,&q,stop,true)||!sxbx_kafka_blob(c,&q,stop,false)){ok=false;break;}if(!ok||q!=stop||q<=rec){c->count=old;break;}}p=end;}return c->count>0;}
static bool sxbx_cap_pointer(sx_context*c,uint64_t word,uint64_t words,unsigned depth,unsigned*work){if(depth>32||++*work>65536||c->count>=SXBX_LIMIT||word>=words)return true;uint64_t p=8+word*8,v;if(!sxbx_word(c,p,8,false,&v))return false;if(!sxbx_free(c,p,8))return true;if(!v)return sxbx_add(c,&sxbx_capnp_null_pointer,p);unsigned type=(unsigned)v&3;if(type>1)return true;if(!sxbx_add(c,type?&sxbx_capnp_list_pointer:&sxbx_capnp_struct_pointer,p))return false;int64_t disp=(int32_t)(uint32_t)v/4;/* arithmetic shift for negative 30-bit word offsets, without implementation-defined shifts */if((uint32_t)v&0x80000000U)disp=((int64_t)(int32_t)(uint32_t)v-3)/4;int64_t target=(int64_t)word+1+disp;if(target<0||(uint64_t)target>words)return true;uint64_t at=(uint64_t)target;if(!type){uint64_t data=(v>>32)&65535,ptrs=v>>48;if(data+ptrs>words-at)return true;for(uint64_t i=0;i<ptrs&&c->count<SXBX_LIMIT;i++)if(!sxbx_cap_pointer(c,at+data+i,words,depth+1,work))return false;}else{unsigned size=(unsigned)(v>>32)&7;uint64_t n=v>>35;if(size==6){if(n>words-at)return true;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++)if(!sxbx_cap_pointer(c,at+i,words,depth+1,work))return false;}else if(size==7){uint64_t tag;if(at>=words||n>words-at-1||!sxbx_word(c,8+at*8,8,false,&tag)||(tag&3))return true;uint64_t elems=(uint32_t)tag>>2,data=(tag>>32)&65535,ptrs=tag>>48;if(elems>1048576||elems*(data+ptrs)!=n)return true;if(!sxbx_add(c,&sxbx_capnp_composite_tag,8+at*8))return false;for(uint64_t i=0;i<elems&&c->count<SXBX_LIMIT;i++)for(uint64_t j=0;j<ptrs&&c->count<SXBX_LIMIT;j++)if(!sxbx_cap_pointer(c,at+1+i*(data+ptrs)+data+j,words,depth+1,work))return false;}}return true;}
static bool sxbx_capnp(sx_context*c){uint64_t n;if(!sxbx_add(c,&sxbx_capnp_segment_table,0)||!sxbx_word(c,4,4,false,&n)||n>1048576||!sxbx_span(c,8,n*8))return false;unsigned work=0;return sxbx_cap_pointer(c,0,n,0,&work);}
static bool sxbx_acb(sx_context*c){uint64_t p=8,end=(uint64_t)c->size,n,space;if(!sxbx_add(c,&sxbx_acb_header,0))return false;for(unsigned i=0;i<4;i++)if(!sxbx_counted(c,&p,end,&sxbx_acb_string_length,4,true,2))return true;if(!sxbx_word(c,p,2,true,&n)||!sxbx_word(c,p+6,2,true,&space)||!sxbx_add(c,&sxbx_acb_palette,p)||n>4094||(space!=0&&space!=2&&space!=7))return true;p+=8;unsigned width=space==2?10:9;const sx_layout*l=space==2?&sxbx_acb_color_cmyk:space==7?&sxbx_acb_color_lab:&sxbx_acb_color_rgb;for(uint64_t i=0;i<n;i++){if(!sxbx_counted(c,&p,end,&sxbx_acb_string_length,4,true,2)||p>end||width>end-p||!sxbx_add(c,l,p))return true;p+=width;}if(end-p==8&&!sxbx_add(c,&sxbx_acb_trailer,p))return false;return true;}
static bool sxbx_keytab(sx_context*c){uint64_t p=2,end=(uint64_t)c->size;if(!sxbx_add(c,&sxbx_keytab_header,0))return false;for(unsigned entries=0;p<end&&entries<2048&&c->count<SXBX_LIMIT;entries++){uint64_t raw;if(!sxbx_word(c,p,4,true,&raw))break;int64_t z=(int32_t)(uint32_t)raw;uint64_t n=z<0?(uint64_t)-z:(uint64_t)z;if(n>end-p-4||!sxbx_add(c,&sxbx_keytab_entry_length,p))break;p+=4;if(!z)break;if(z<0){p+=n;continue;}uint64_t q=p,stop=p+n,count;if(!sxbx_word(c,q,2,true,&count)||count>32||!count||!sxbx_add(c,&sxbx_keytab_component_count,q))break;q+=2;bool ok=true;for(uint64_t i=0;i<=count;i++)if(!sxbx_counted(c,&q,stop,&sxbx_keytab_string_length,2,true,1)){ok=false;break;}if(ok&&stop-q>=13&&sxbx_add(c,&sxbx_kerberos_name_type,q)&&sxbx_add(c,&sxbx_keytab_key,q+4)&&sxbx_word(c,q+11,2,true,&count)&&count<=stop-q-13){q+=13+count;if(stop-q>=4&&!sxbx_add(c,&sxbx_keytab_extended_kvno,q))return false;}p=stop;}return true;}
static bool sxbx_cc_principal(sx_context*c,uint64_t*p,uint64_t end){uint64_t n;if(*p>end||end-*p<8||!sxbx_word(c,*p+4,4,true,&n)||!n||n>32||!sxbx_add(c,&sxbx_ccache_principal,*p))return false;*p+=8;for(uint64_t i=0;i<=n;i++)if(!sxbx_counted(c,p,end,&sxbx_ccache_blob_size,4,true,1))return false;return true;}
static bool sxbx_ccache(sx_context*c){uint64_t p=4,end=(uint64_t)c->size,z;if(!sxbx_add(c,&sxbx_ccache_header,0)||!sxbx_word(c,2,2,true,&z)||z>end-4)return false;uint64_t stop=p+z;while(p<stop&&c->count<SXBX_LIMIT){uint64_t tag;if(stop-p<4||!sxbx_word(c,p,2,true,&tag)||!sxbx_word(c,p+2,2,true,&z)||z>stop-p-4||!sxbx_add(c,&sxbx_ccache_tag,p))break;p+=4;if(tag==1&&z==8&&!sxbx_add(c,&sxbx_ccache_time_offset,p))return false;p+=z;}p=stop;if(!sxbx_cc_principal(c,&p,end))return true;for(unsigned entries=0;p<end&&entries<512&&c->count<SXBX_LIMIT;entries++){size_t keep=c->count;if(!sxbx_cc_principal(c,&p,end)||!sxbx_cc_principal(c,&p,end)||end-p<6||!sxbx_word(c,p+2,4,true,&z)||z>end-p-6||!sxbx_add(c,&sxbx_ccache_key,p)){c->count=keep;break;}p+=6+z;if(end-p<21||!sxbx_add(c,&sxbx_ccache_times_flags,p)){c->count=keep;break;}p+=21;bool ok=true;for(unsigned l=0;l<2&&ok;l++){uint64_t count;if(end-p<4||!sxbx_word(c,p,4,true,&count)||count>128||!sxbx_add(c,&sxbx_ccache_list_count,p)){ok=false;break;}p+=4;for(uint64_t i=0;i<count;i++){if(end-p<6||!sxbx_word(c,p+2,4,true,&z)||z>end-p-6||!sxbx_add(c,&sxbx_ccache_typed_blob,p)){ok=false;break;}p+=6+z;}}if(!ok||!sxbx_counted(c,&p,end,&sxbx_ccache_blob_size,4,true,1)||!sxbx_counted(c,&p,end,&sxbx_ccache_blob_size,4,true,1)){c->count=keep;break;}}return true;}
static bool sxbx_jks(sx_context*c){uint64_t p=12,end=(uint64_t)c->size,n;if(end<32||!sxbx_add(c,&sxbx_jks_header,0)||!sxbx_add(c,&sxbx_jks_digest,end-20)||!sxbx_word(c,8,4,true,&n))return false;end-=20;if(n>256)return true;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint64_t tag,certs=1;size_t keep=c->count;if(end-p<4||!sxbx_word(c,p,4,true,&tag)||!sxbx_add(c,&sxbx_jks_entry_tag,p)){c->count=keep;break;}p+=4;if(!sxbx_counted(c,&p,end,&sxbx_jks_string_size,2,true,1)||end-p<8||!sxbx_add(c,&sxbx_jks_timestamp,p)){c->count=keep;break;}p+=8;if(tag==1){if(!sxbx_counted(c,&p,end,&sxbx_jks_blob_size,4,true,1)||end-p<4||!sxbx_word(c,p,4,true,&certs)||certs>16||!sxbx_add(c,&sxbx_jks_certificate_count,p)){c->count=keep;break;}p+=4;}else if(tag!=2){c->count=keep;break;}bool ok=true;for(uint64_t j=0;j<certs;j++)if(!sxbx_counted(c,&p,end,&sxbx_jks_string_size,2,true,1)||!sxbx_counted(c,&p,end,&sxbx_jks_blob_size,4,true,1)){ok=false;break;}if(!ok){c->count=keep;break;}}return true;}
static bool sxbx_gg_value(sx_context*c,uint64_t*p,uint64_t end,unsigned type,unsigned depth){static const sx_layout*const ls[]={&sxbx_gguf_value0,&sxbx_gguf_value1,&sxbx_gguf_value2,&sxbx_gguf_value3,&sxbx_gguf_value4,&sxbx_gguf_value5,&sxbx_gguf_value6,&sxbx_gguf_value7,NULL,NULL,&sxbx_gguf_value10,&sxbx_gguf_value11,&sxbx_gguf_value12};static const unsigned widths[]={1,1,2,2,4,4,4,1,0,0,8,8,8};if(type>12||depth>1||c->count>=SXBX_LIMIT)return false;if(type==8)return sxbx_counted(c,p,end,&sxbx_gguf_string_size,8,false,1);if(type==9){uint64_t item,n;if(*p>end||end-*p<12||!sxbx_word(c,*p,4,false,&item)||item>12||item==9||!sxbx_word(c,*p+4,8,false,&n)||n>4096||!sxbx_add(c,&sxbx_gguf_array,*p))return false;*p+=12;for(uint64_t i=0;i<n;i++)if(!sxbx_gg_value(c,p,end,(unsigned)item,depth+1))return false;return true;}if(*p>end||widths[type]>end-*p||!sxbx_add(c,ls[type],*p))return false;*p+=widths[type];return true;}
static bool sxbx_gguf(sx_context*c){uint64_t nt,nk,p=24,end=(uint64_t)c->size;if(!sxbx_add(c,&sxbx_gguf_header,0)||!sxbx_word(c,8,8,false,&nt)||!sxbx_word(c,16,8,false,&nk)||nt>1024||nk>1024)return false;for(uint64_t i=0;i<nk&&c->count<SXBX_LIMIT;i++){uint64_t t;if(!sxbx_counted(c,&p,end,&sxbx_gguf_string_size,8,false,1)||end-p<4||!sxbx_word(c,p,4,false,&t)||!sxbx_add(c,&sxbx_gguf_value_type,p))return true;p+=4;if(!sxbx_gg_value(c,&p,end,(unsigned)t,0))return true;}for(uint64_t i=0;i<nt&&c->count<SXBX_LIMIT;i++){uint64_t n;if(!sxbx_counted(c,&p,end,&sxbx_gguf_string_size,8,false,1)||end-p<4||!sxbx_word(c,p,4,false,&n)||n<1||n>4||!sxbx_add(c,&sxbx_gguf_dimensions,p))break;p+=4;if(n>(end-p)/8||!sxbx_table(c,&sxbx_gguf_dimension,p,n))break;p+=n*8;if(end-p<12||!sxbx_add(c,&sxbx_gguf_tensor_storage,p))break;p+=12;}return true;}
static bool sxbx_nvp_lists(sx_context*c,uint64_t*p,uint64_t end){uint64_t n;if(*p>=end||!sxbx_word(c,*p,1,false,&n)||!sxbx_add(c,&sxbx_nvp_string_list,(*p)++))return false;for(uint64_t i=0;i<n;i++)if(!sxbx_zero_string(c,p,end,1))return false;return true;}
static bool sxbx_nvp(sx_context*c){uint64_t p=4,end=(uint64_t)c->size,n;if(!sxbx_add(c,&sxbx_nvp_header,0)||!sxbx_zero_string(c,&p,end,1)||!sxbx_word(c,p+3,2,false,&n)||!sxbx_add(c,&sxbx_nvp_directory,p))return false;p+=5;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint8_t b[8];if(!sxbx_read(c,p,b,8))break;uint64_t z=sxbx32(b+4,false)&0x7fffffffU;unsigned type=sxbx32(b,false);if(!sxbx_span(c,p+8,z)||!sxbx_add(c,&sxbx_nvp_record,p))break;uint64_t q=p+8,stop=q+z;if(type==4005||type==2203){if(z>=4&&!sxbx_add(c,&sxbx_nvp_jpeg_size,q))return false;}else if(type==1500||type==1502){unsigned skip=type==1500?17:13;if(z>=skip+4&&!sxbx_add(c,&sxbx_nvp_jpeg_size,q+skip))return false;}else if(type==1503){size_t keep=c->count;bool ok=sxbx_nvp_lists(c,&q,stop)&&sxbx_nvp_lists(c,&q,stop)&&stop-q>=3;q+=ok?3:0;ok=ok&&sxbx_nvp_lists(c,&q,stop)&&sxbx_nvp_lists(c,&q,stop)&&stop-q>=6;if(ok){q+=2;ok=sxbx_add(c,&sxbx_nvp_jpeg_size,q);}if(!ok)c->count=keep;}p=stop;}return true;}
static bool sxbx_lbr(sx_context*c){uint64_t n,p=256;if(!sxbx_add(c,&sxbx_lbrcobol_title,0)||!sxbx_add(c,&sxbx_lbrcobol_directory_header,144)||!sxbx_add(c,&sxbx_lbrcobol_header_constants,148)||!sxbx_word(c,146,2,true,&n))return false;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint8_t b[19];if(!sxbx_read(c,p,b,19)||!sxbx_span(c,p+19,b[18])||!sxbx_free(c,p,19))break;if(!sxbx_add(c,&sxbx_lbrcobol_member,p)||!sxbx_add(c,&sxbx_lbrcobol_member_tail,p+16))return false;p=sxbx32(b,true);}return true;}
static bool sxbx_marshal(sx_context*c,uint64_t*p,uint64_t end,unsigned depth,unsigned*work,unsigned role){if(depth>32||++*work>SXBX_LIMIT||c->count>=SXBX_LIMIT||*p>=end)return false;uint64_t code,n;if(!sxbx_word(c,*p,1,false,&code)||!sxbx_add(c,&sxbx_pyz_marshal_tag,(*p)++))return false;code&=127;const sx_layout*l=NULL;unsigned width=0;if(code=='i'){l=role==1?&sxbx_pyz_marshal_offset32:role==2?&sxbx_pyz_marshal_size32:&sxbx_pyz_marshal_int32;width=4;}else if(code=='I'){l=role==1?&sxbx_pyz_marshal_offset64:role==2?&sxbx_pyz_marshal_size64:&sxbx_pyz_marshal_int64;width=8;}else if(code=='r'){l=&sxbx_pyz_marshal_reference;width=4;}else if(code=='N'||code=='0'||code=='F'||code=='T')return true;
 if(l){if(width>end-*p||!sxbx_add(c,l,*p))return false;*p+=width;return true;}if(code=='s'||code=='t'||code=='u'||code=='a'||code=='A')return sxbx_counted(c,p,end,&sxbx_pyz_marshal_length,4,false,1);if(code=='z'||code=='Z')return sxbx_counted(c,p,end,&sxbx_pyz_marshal_short_length,1,false,1);
 if(code=='l'){if(end-*p<4||!sxbx_word(c,*p,4,false,&n)||!sxbx_add(c,&sxbx_pyz_marshal_long_digits,*p))return false;*p+=4;int64_t z=(int32_t)(uint32_t)n;n=z<0?(uint64_t)-z:(uint64_t)z;if(n>5||n>(end-*p)/2||!sxbx_table(c,&sxbx_pyz_marshal_digit,*p,n))return false;*p+=n*2;return true;}
 if(code=='['||code=='('||code==')'){width=code==')'?1:4;if(width>end-*p||!sxbx_word(c,*p,width,false,&n)||n>SXBX_LIMIT||!sxbx_add(c,width==1?&sxbx_pyz_marshal_short_count:&sxbx_pyz_marshal_count,*p))return false;*p+=width;for(uint64_t i=0;i<n;i++)if(!sxbx_marshal(c,p,end,depth+1,work,(code!='['&&n==3&&i)?(unsigned)i:0))return false;return true;}if(code=='{'){for(unsigned i=0;i<SXBX_LIMIT;i++){if(*p>=end||!sxbx_word(c,*p,1,false,&n))return false;if((n&127)=='0')return sxbx_marshal(c,p,end,depth+1,work,0);if(!sxbx_marshal(c,p,end,depth+1,work,0)||!sxbx_marshal(c,p,end,depth+1,work,0))return false;}return false;}return false;}
static bool sxbx_pyz(sx_context*c){uint8_t b[12];if(!sxbx_read(c,0,b,12))return false;uint64_t p=sxbx32(b+8,true),end=(uint64_t)c->size;bool be=true;if(p<12||p>=end){p=sxbx32(b+8,false);be=false;}if(p<12||p>=end||!sxbx_add(c,be?&sxbx_pyz_header_be:&sxbx_pyz_header_le,0))return false;size_t keep=c->count;unsigned work=0;if(!sxbx_marshal(c,&p,end,0,&work,0)||p!=end)c->count=keep;return true;}
static bool sxbx_pyi_candidate(sx_context*c,uint64_t p,uint64_t limit,uint64_t*outtable,uint64_t*outsize,uint64_t*outcookie){uint8_t b[88];if(limit<p||limit-p<24||!sxbx_read(c,p,b,24)||xx_rt_memcmp(b,"MEI\x0c\x0b\x0a\x0b\x0e",8))return false;uint64_t pkg=sxbx32(b+8,true),off=sxbx32(b+12,true),size=sxbx32(b+16,true);if(off+size>pkg)return false;uint64_t cookie=pkg-off-size;if((cookie!=24&&cookie!=88)||cookie>limit-p||pkg>p+cookie||size<19||size>16777216||!sxbx_read(c,p,b,(size_t)cookie))return false;uint64_t table=p+cookie-pkg+off,q=table,end=table+size;if(end!=p)return false;unsigned count=0;while(q<end){if(++count>SXBX_LIMIT||end-q<19||!sxbx_read(c,q,b,18))return false;uint64_t z=sxbx32(b,true),data=sxbx32(b+4,true),packed=sxbx32(b+8,true);if(z<19||z>end-q||data>off||packed>off-data||b[16]>1)return false;q+=z;}*outtable=table;*outsize=size;*outcookie=cookie;return true;}
static bool sxbx_pyi(sx_context*c){uint64_t limits[2]={(uint64_t)c->size,0},pe;uint8_t b[8];if(sxbx_read(c,0,b,2)&&b[0]=='M'&&b[1]=='Z'&&sxbx_word(c,60,4,false,&pe)&&sxbx_read(c,pe,b,4)&&!xx_rt_memcmp(b,"PE\0\0",4)){uint64_t magic,off;if(sxbx_word(c,pe+24,2,false,&magic)&&(magic==267||magic==523)&&sxbx_word(c,pe+24+(magic==267?128:144),4,false,&off)&&off<limits[0])limits[1]=off;}for(unsigned window=0;window<2;window++){uint64_t limit=limits[window],low=limit>(window?512:4096)?limit-(window?512:4096):0;if(limit<24)continue;for(uint64_t p=limit-24;;p--){uint64_t table,size,cookie;if(sxbx_pyi_candidate(c,p,limit,&table,&size,&cookie)){if(!sxbx_add(c,&sxbx_pyinstaller_cookie24,p)||(cookie==88&&!sxbx_add(c,&sxbx_pyinstaller_library,p+24)))return false;uint64_t q=table;while(q<table+size&&c->count<SXBX_LIMIT){uint64_t z;if(!sxbx_word(c,q,4,true,&z)||!sxbx_add(c,&sxbx_pyinstaller_toc,q))return false;q+=z;}return true;}if(p==low)break;}}return false;}
static const sx_layout *const sxbx_starkit_row_count[] = {&sxbx_starkit_row_count1,&sxbx_starkit_row_count2,&sxbx_starkit_row_count3,&sxbx_starkit_row_count4,&sxbx_starkit_row_count5,&sxbx_starkit_row_count6,&sxbx_starkit_row_count7,&sxbx_starkit_row_count8,&sxbx_starkit_row_count9};
static const sx_layout *const sxbx_starkit_column_size[] = {&sxbx_starkit_column_size1,&sxbx_starkit_column_size2,&sxbx_starkit_column_size3,&sxbx_starkit_column_size4,&sxbx_starkit_column_size5,&sxbx_starkit_column_size6,&sxbx_starkit_column_size7,&sxbx_starkit_column_size8,&sxbx_starkit_column_size9};
static const sx_layout *const sxbx_starkit_column_offset[] = {&sxbx_starkit_column_offset1,&sxbx_starkit_column_offset2,&sxbx_starkit_column_offset3,&sxbx_starkit_column_offset4,&sxbx_starkit_column_offset5,&sxbx_starkit_column_offset6,&sxbx_starkit_column_offset7,&sxbx_starkit_column_offset8,&sxbx_starkit_column_offset9};
static const sx_layout *const sxbx_starkit_memo_row_delta[] = {&sxbx_starkit_memo_row_delta1,&sxbx_starkit_memo_row_delta2,&sxbx_starkit_memo_row_delta3,&sxbx_starkit_memo_row_delta4,&sxbx_starkit_memo_row_delta5,&sxbx_starkit_memo_row_delta6,&sxbx_starkit_memo_row_delta7,&sxbx_starkit_memo_row_delta8,&sxbx_starkit_memo_row_delta9};
static const sx_layout *const sxbx_starkit_view_tag[] = {&sxbx_starkit_view_tag1,&sxbx_starkit_view_tag2,&sxbx_starkit_view_tag3,&sxbx_starkit_view_tag4,&sxbx_starkit_view_tag5,&sxbx_starkit_view_tag6,&sxbx_starkit_view_tag7,&sxbx_starkit_view_tag8,&sxbx_starkit_view_tag9};
static bool sxbx_mkvar(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*const*ls,uint64_t*v){uint64_t start=*p;*v=0;for(unsigned i=0;i<9;i++){uint64_t b;if(*p>=end||!sxbx_word(c,(*p)++,1,false,&b))return false;*v=(*v<<7)|(b&127);if(b&128)return sxbx_add(c,ls[i],start);}return false;}
typedef struct sxbx_col {uint64_t size,offset;}sxbx_col;
static bool sxbx_mkcol(sx_context*c,uint64_t base,uint64_t*p,uint64_t end,sxbx_col*out){out->offset=0;if(!sxbx_mkvar(c,p,end,sxbx_starkit_column_size,&out->size))return false;if(out->size&&(!sxbx_mkvar(c,p,end,sxbx_starkit_column_offset,&out->offset)||out->offset>UINT64_MAX-base||!sxbx_span(c,base+out->offset,out->size)))return false;out->offset+=base;return true;}
static bool sxbx_mkprop(sx_context*c,uint64_t base,uint64_t*p,uint64_t end,sxbx_col out[3]){xx_mem_zero(out,3*sizeof(*out));return sxbx_mkcol(c,base,p,end,out)&&(!out[0].size||sxbx_mkcol(c,base,p,end,out+1))&&sxbx_mkcol(c,base,p,end,out+2);}
static bool sxbx_starkit(sx_context*c){uint64_t base=0,end=(uint64_t)c->size,size,root,footer;uint8_t b[8];if(end<24||!sxbx_read(c,0,b,8))return false;if(xx_rt_memcmp(b,"JL\x1a\0",4)){if(b[0]!='M'||b[1]!='Z'||!sxbx_word(c,end-12,4,true,&footer)||footer+16>end)return false;base=end-footer-16;if(!sxbx_read(c,base,b,8)||xx_rt_memcmp(b,"JL\x1a\0",4))return false;}if(!sxbx_add(c,&sxbx_starkit_header,base)||!sxbx_add(c,&sxbx_starkit_commit,end-16)||!sxbx_word(c,end-8,4,true,&size)||!sxbx_word(c,end-4,4,true,&root))return false;size&=0x7fffffff;root+=base;if(size<3||size>4096||!sxbx_span(c,root,size)||!sxbx_read(c,root,b,2)||b[0]!=128||!(b[1]&128)||!sxbx_add(c,&sxbx_starkit_root_prefix,root))return true;uint64_t p=root+2+(b[1]&127),stop=root+size,rows;sxbx_col dirs;if(!sxbx_mkvar(c,&p,stop,sxbx_starkit_row_count,&rows)||!sxbx_mkcol(c,base,&p,stop,&dirs)||!dirs.size)return true;p=dirs.offset;stop=p+dirs.size;sxbx_col name[3],parents,views;if(!sxbx_mkvar(c,&p,stop,sxbx_starkit_view_tag,&rows)||!sxbx_mkvar(c,&p,stop,sxbx_starkit_row_count,&rows)||!rows||rows>SXBX_LIMIT||!sxbx_mkprop(c,base,&p,stop,name)||!sxbx_mkcol(c,base,&p,stop,&parents)||!sxbx_mkcol(c,base,&p,stop,&views))return true;p=views.offset;stop=p+views.size;for(uint64_t i=0;i<rows&&c->count<SXBX_LIMIT;i++){uint64_t n;size_t keep=c->count;sxbx_col filename[3],bytes,date,contents[3];if(!sxbx_mkvar(c,&p,stop,sxbx_starkit_view_tag,&n)||!sxbx_mkvar(c,&p,stop,sxbx_starkit_row_count,&n)){c->count=keep;break;}if(!n)continue;if(n>SXBX_LIMIT||!sxbx_mkprop(c,base,&p,stop,filename)||!sxbx_mkcol(c,base,&p,stop,&bytes)||!sxbx_mkcol(c,base,&p,stop,&date)||!sxbx_mkprop(c,base,&p,stop,contents)){c->count=keep;break;}uint64_t q=contents[2].offset,mend=q+contents[2].size;for(unsigned memo=0;q<mend&&memo<SXBX_LIMIT&&c->count<SXBX_LIMIT;memo++){uint64_t v;if(!sxbx_mkvar(c,&q,mend,sxbx_starkit_memo_row_delta,&v)||!sxbx_mkvar(c,&q,mend,sxbx_starkit_column_size,&v)||!sxbx_mkvar(c,&q,mend,sxbx_starkit_column_offset,&v))break;}}return true;}
static bool sxbx_evb_compressed(sx_context*c,uint64_t p,uint64_t z){uint64_t table;if(z<12||!sxbx_word(c,p,4,false,&table)||table<12||table>=z||(table-12)%12||table>1048576)return true;if(!sxbx_add(c,&sxbx_evb_chunk_header,p))return false;uint64_t count=(table-12)/12+1,data=p+table;for(uint64_t i=0;i<count&&c->count<SXBX_LIMIT;i++){uint64_t n,q=p+8+i*12;if(!sxbx_word(c,q,4,false,&n)||n>p+z-data)break;if(!sxbx_add(c,i+1==count?&sxbx_evb_file_stored_size:&sxbx_evb_chunk_entry,q))return false;uint8_t magic[4];if(n>=24&&sxbx_read(c,data,magic,4)&&!xx_rt_memcmp(magic,"AP32",4)&&!sxbx_add(c,&sxbx_evb_ap32,data))return false;data+=n;}return true;}
static bool sxbx_evb_nodes(sx_context*c,uint64_t*p,uint64_t*payload,uint64_t table_end,uint64_t count,bool legacy,unsigned depth,unsigned*work){if(depth>64||count>SXBX_LIMIT)return false;for(uint64_t i=0;i<count;i++){if(++*work>SXBX_LIMIT||c->count>=SXBX_LIMIT)return false;uint64_t start=*p,size,children,type;if(!sxbx_word(c,start,4,false,&size)||!sxbx_word(c,start+12,4,false,&children)||!sxbx_span(c,start,16))return false;/* First modern child shares one byte with the main-node count, as specified by the external-package layout. */if(!sx_add(c,&sxbx_evb_node,(int64_t)start,16))return false;*p+=16;if(!sxbx_zero_string(c,p,table_end,2)||!sxbx_word(c,*p,1,false,&type)||!sxbx_add(c,&sxbx_evb_node_type,(*p)++))return false;if(type==3){if(legacy){if(size<16||!sxbx_span(c,start,size+4)||start+size+4<*p)return false;*p=start+size+4;}else{if(*p>table_end||table_end-*p<25)return false;*p+=25;}if(!sxbx_evb_nodes(c,p,payload,table_end,children,legacy,depth+1,work))return false;}else if(type==2){uint64_t info,original,packed,data;if(children)return false;if(legacy){if(size<45||!sxbx_span(c,start,size+4)||start+size+4<49||start+size+4-49<*p)return false;info=start+size+4-49;data=start+size+4;}else{info=*p;if(info>table_end||table_end-info<53)return false;data=*payload;}if(!sxbx_word(c,info+2,4,false,&original)||!sxbx_word(c,info+(legacy?41:49),4,false,&packed)||!sxbx_span(c,data,packed)||!sxbx_add(c,legacy?&sxbx_evb_file_legacy:&sxbx_evb_file_modern,info))return false;if(original!=packed&&!sxbx_evb_compressed(c,data,packed))return false;if(legacy)*p=data+packed;else{*p=info+53;*payload+=packed;}}else return false;}return true;}
static bool sxbx_evb(sx_context*c)
{
 uint8_t b[80];uint64_t limit=(uint64_t)c->size;if(limit>67108864)limit=67108864;
 uint8_t*window=xx_mem_alloc(65539);if(!window)return false;unsigned candidates=0;bool result=false;
 for(uint64_t chunk=0;chunk<limit;chunk+=65536){size_t take=(size_t)(limit-chunk>65539?65539:limit-chunk);if(!sxbx_read(c,chunk,window,take))break;
  for(size_t i=0;i+4<=take&&i<65536;i++){
   if(xx_rt_memcmp(window+i,"EVB\0",4))continue;if(++candidates>64)goto done;uint64_t p=chunk+i;
   if(!sxbx_read(c,p,b,80)||sxbx32(b+4,false)!=64)continue;uint64_t size=sxbx32(b+64,false),count=sxbx32(b+76,false);
   if(!count||count>65536||size<15||!sxbx_span(c,p+64,size+4))continue;
   for(unsigned mode=0;mode<2;mode++){size_t keep=c->count;bool legacy=mode!=0;uint64_t q=legacy?p+68+size:p+79,payload=p+68+size,table_end=legacy?(uint64_t)c->size:payload;unsigned work=0;
    if(sxbx_add(c,&sxbx_evb_header,p)&&sxbx_add(c,&sxbx_evb_table_prefix,p+64)&&sxbx_evb_nodes(c,&q,&payload,table_end,count,legacy,0,&work)){result=true;goto done;}c->count=keep;
   }
  }
 }
 done:xx_mem_free(window);return result;
}
static bool sxbx_pam(sx_context*c){uint64_t n;if(!sxbx_add(c,&sxbx_pam_pak_header,0)||!sxbx_word(c,8,2,false,&n)||n>SXBX_LIMIT||!sxbx_span(c,36,n*32))return false;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint64_t z,off;if(!sxbx_word(c,36+i*8,4,false,&z)||!sxbx_word(c,40+i*8,4,false,&off)||!sxbx_add(c,z==0xc0000000U&&off==UINT32_MAX?&sxbx_pam_pak_directory_marker:&sxbx_pam_pak_data,36+i*8))return false;}return sxbx_table(c,&sxbx_pam_pak_index,36+n*8,n);}
static bool sxbx_pfpk(sx_context*c){uint64_t n,p=8,end=(uint64_t)c->size;if(!sxbx_add(c,&sxbx_pfpk_header,0)||!sxbx_word(c,4,4,false,&n)||n>SXBX_LIMIT)return false;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){if(!sxbx_counted(c,&p,end,&sxbx_pfpk_name_size,1,false,1)||end-p<8||!sxbx_add(c,&sxbx_pfpk_member,p))break;p+=8;}return true;}
static int sxbx_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxbx_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxbx_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxbx_order);return !c->failed;}
static bool sx_binaryextra_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_CLP:case XX_FILE_TYPE_LMD_CONTAINER:case XX_FILE_TYPE_VICE_SNAPSHOT:case XX_FILE_TYPE_MCAP:case XX_FILE_TYPE_WINDOWS_REGISTRY_HIVE:case XX_FILE_TYPE_WINDOWS_EVTX:case XX_FILE_TYPE_KAFKA_RECORD_BATCH:case XX_FILE_TYPE_CAPNPROTO_MESSAGE:case XX_FILE_TYPE_ADOBE_ACB:case XX_FILE_TYPE_KERBEROS_KEYTAB:case XX_FILE_TYPE_KERBEROS_CCACHE:case XX_FILE_TYPE_JKS_KEYSTORE:case XX_FILE_TYPE_GGUF:case XX_FILE_TYPE_NVP:case XX_FILE_TYPE_LBRCOBOL:case XX_FILE_TYPE_PYZ:case XX_FILE_TYPE_PYINSTALLER_ONE_EXECUTABLE:case XX_FILE_TYPE_STARKIT:case XX_FILE_TYPE_ENIGMA_VIRTUAL_BOX:case XX_FILE_TYPE_GTA_IMG:case XX_FILE_TYPE_PAM_PAK:case XX_FILE_TYPE_PFPK:return true;default:return false;}}
static bool sx_binaryextra_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;uint64_t n;switch(c->f->file_type){
case XX_FILE_TYPE_CLP:ok=sxbx_word(c,2,2,false,&n)&&sxbx_add(c,&sxbx_clp_header,0)&&sxbx_table(c,&sxbx_clp_record,4,n);break;
case XX_FILE_TYPE_LMD_CONTAINER:ok=sxbx_lmd(c);break;
case XX_FILE_TYPE_VICE_SNAPSHOT:ok=sxbx_vice(c);break;
case XX_FILE_TYPE_MCAP:ok=sxbx_mcap(c);break;
case XX_FILE_TYPE_WINDOWS_REGISTRY_HIVE:ok=sxbx_regf(c);break;
case XX_FILE_TYPE_WINDOWS_EVTX:ok=sxbx_evtx(c);break;
case XX_FILE_TYPE_KAFKA_RECORD_BATCH:ok=sxbx_kafka(c);break;
case XX_FILE_TYPE_CAPNPROTO_MESSAGE:ok=sxbx_capnp(c);break;
case XX_FILE_TYPE_ADOBE_ACB:ok=sxbx_acb(c);break;
case XX_FILE_TYPE_KERBEROS_KEYTAB:ok=sxbx_keytab(c);break;
case XX_FILE_TYPE_KERBEROS_CCACHE:ok=sxbx_ccache(c);break;
case XX_FILE_TYPE_JKS_KEYSTORE:ok=sxbx_jks(c);break;
case XX_FILE_TYPE_GGUF:ok=sxbx_gguf(c);break;
case XX_FILE_TYPE_NVP:ok=sxbx_nvp(c);break;
case XX_FILE_TYPE_LBRCOBOL:ok=sxbx_lbr(c);break;
case XX_FILE_TYPE_PYZ:ok=sxbx_pyz(c);break;
case XX_FILE_TYPE_PYINSTALLER_ONE_EXECUTABLE:ok=sxbx_pyi(c);break;
case XX_FILE_TYPE_STARKIT:ok=sxbx_starkit(c);break;
case XX_FILE_TYPE_ENIGMA_VIRTUAL_BOX:ok=sxbx_evb(c);break;
case XX_FILE_TYPE_GTA_IMG:ok=sxbx_word(c,4,4,false,&n)&&sxbx_add(c,&sxbx_gta_img_header,0)&&sxbx_table(c,&sxbx_gta_img_entry,8,n);break;
case XX_FILE_TYPE_PAM_PAK:ok=sxbx_pam(c);break;
case XX_FILE_TYPE_PFPK:ok=sxbx_pfpk(c);break;
default:break;}return ok&&sxbx_finish(c);}
