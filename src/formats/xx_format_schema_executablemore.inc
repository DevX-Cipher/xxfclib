/* SPDX-License-Identifier: MIT. Physical executable metadata. Scope: docs/data_struct_executablemore_scope.txt. */
static const xx_data_struct_field_desc sxexm_vz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[17]",4,17,SX_STRING),
 SX_FIELD("file_type","uint8",21,1,SX_ID),
 SX_FIELD("load_address","uint16",22,2,SX_ADDRESS),
};
static const sx_layout sxexm_vz_header = {UINT32_C(0x602b0001),"vz_header",sxexm_vz_header_fields,SX_COUNT(sxexm_vz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xalz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("descriptor_index","uint32",4,4,SX_ID),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxexm_xalz_header = {UINT32_C(0x602b0002),"xalz_header",sxexm_xalz_header_fields,SX_COUNT(sxexm_xalz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pyc_header8_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("newline","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("timestamp","uint32",4,4,SX_TIME),
};
static const sx_layout sxexm_pyc_header8 = {UINT32_C(0x602b0003),"pyc_header8",sxexm_pyc_header8_fields,SX_COUNT(sxexm_pyc_header8_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pyc_header12_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("newline","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("timestamp","uint32",4,4,SX_TIME),
 SX_FIELD("source_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxexm_pyc_header12 = {UINT32_C(0x602b0004),"pyc_header12",sxexm_pyc_header12_fields,SX_COUNT(sxexm_pyc_header12_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pyc_header16_timestamp_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("newline","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("timestamp","uint32",8,4,SX_TIME),
 SX_FIELD("source_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxexm_pyc_header16_timestamp = {UINT32_C(0x602b0005),"pyc_header16_timestamp",sxexm_pyc_header16_timestamp_fields,SX_COUNT(sxexm_pyc_header16_timestamp_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pyc_header16_hash_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("newline","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("source_hash","uint8[8]",8,8,SX_CHECKSUM),
};
static const sx_layout sxexm_pyc_header16_hash = {UINT32_C(0x602b0006),"pyc_header16_hash",sxexm_pyc_header16_hash_fields,SX_COUNT(sxexm_pyc_header16_hash_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_superblock_fields[] = {
 SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
 SX_FIELD("block_size","uint32",32,4,SX_SIZE),
 SX_FIELD("free_block_map_block","uint32",36,4,SX_ID),
 SX_FIELD("block_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("directory_size","uint32",44,4,SX_SIZE),
 SX_FIELD("reserved","uint32",48,4,SX_RESERVED),
 SX_FIELD("block_map_block","uint32",52,4,SX_ID),
};
static const sx_layout sxexm_msf7_superblock = {UINT32_C(0x602b0007),"msf7_superblock",sxexm_msf7_superblock_fields,SX_COUNT(sxexm_msf7_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_directory_block_fields[] = {
 SX_FIELD("directory_block_index","uint32",0,4,SX_ID),
};
static const sx_layout sxexm_msf7_directory_block = {UINT32_C(0x602b0008),"msf7_directory_block",sxexm_msf7_directory_block_fields,SX_COUNT(sxexm_msf7_directory_block_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_stream_count_fields[] = {
 SX_FIELD("stream_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxexm_msf7_stream_count = {UINT32_C(0x602b0009),"msf7_stream_count",sxexm_msf7_stream_count_fields,SX_COUNT(sxexm_msf7_stream_count_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_stream_size_fields[] = {
 SX_FIELD("stream_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxexm_msf7_stream_size = {UINT32_C(0x602b000a),"msf7_stream_size",sxexm_msf7_stream_size_fields,SX_COUNT(sxexm_msf7_stream_size_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_msf7_stream_block_fields[] = {
 SX_FIELD("stream_block_index","uint32",0,4,SX_ID),
};
static const sx_layout sxexm_msf7_stream_block = {UINT32_C(0x602b000b),"msf7_stream_block",sxexm_msf7_stream_block_fields,SX_COUNT(sxexm_msf7_stream_block_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_mub_header_le_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("slice_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxexm_mub_header_le = {UINT32_C(0x602b000c),"mub_header_le",sxexm_mub_header_le_fields,SX_COUNT(sxexm_mub_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_mub_arch32_le_fields[] = {
 SX_FIELD("cpu_type","int32",0,4,SX_ID),
 SX_FIELD("cpu_subtype","int32",4,4,SX_ID),
 SX_FIELD("slice_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("slice_size","uint32",12,4,SX_SIZE),
 SX_FIELD("alignment_shift","uint32",16,4,SX_NONE),
};
static const sx_layout sxexm_mub_arch32_le = {UINT32_C(0x602b000d),"mub_arch32_le",sxexm_mub_arch32_le_fields,SX_COUNT(sxexm_mub_arch32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_mub_header_be_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("slice_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxexm_mub_header_be = {UINT32_C(0x602b000e),"mub_header_be",sxexm_mub_header_be_fields,SX_COUNT(sxexm_mub_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_mub_arch32_be_fields[] = {
 SX_FIELD("cpu_type","int32",0,4,SX_ID),
 SX_FIELD("cpu_subtype","int32",4,4,SX_ID),
 SX_FIELD("slice_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("slice_size","uint32",12,4,SX_SIZE),
 SX_FIELD("alignment_shift","uint32",16,4,SX_NONE),
};
static const sx_layout sxexm_mub_arch32_be = {UINT32_C(0x602b000f),"mub_arch32_be",sxexm_mub_arch32_be_fields,SX_COUNT(sxexm_mub_arch32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_mub_arch64_be_fields[] = {
 SX_FIELD("cpu_type","int32",0,4,SX_ID),
 SX_FIELD("cpu_subtype","int32",4,4,SX_ID),
 SX_FIELD("slice_offset","uint64",8,8,SX_OFFSET),
 SX_FIELD("slice_size","uint64",16,8,SX_SIZE),
 SX_FIELD("alignment_shift","uint32",24,4,SX_NONE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxexm_mub_arch64_be = {UINT32_C(0x602b0010),"mub_arch64_be",sxexm_mub_arch64_be_fields,SX_COUNT(sxexm_mub_arch64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_fork_header_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("map_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("map_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxexm_resource_fork_header = {UINT32_C(0x602b0011),"resource_fork_header",sxexm_resource_fork_header_fields,SX_COUNT(sxexm_resource_fork_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_map_header_fields[] = {
 SX_FIELD("data_offset_copy","uint32",0,4,SX_OFFSET),
 SX_FIELD("map_offset_copy","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size_copy","uint32",8,4,SX_SIZE),
 SX_FIELD("map_size_copy","uint32",12,4,SX_SIZE),
 SX_FIELD("next_map_handle","uint32",16,4,SX_POINTER),
 SX_FIELD("file_reference","int16",20,2,SX_ID),
 SX_FIELD("attributes","uint16",22,2,SX_FLAGS),
 SX_FIELD("type_list_offset","uint16",24,2,SX_OFFSET),
 SX_FIELD("name_list_offset","uint16",26,2,SX_OFFSET),
};
static const sx_layout sxexm_resource_map_header = {UINT32_C(0x602b0012),"resource_map_header",sxexm_resource_map_header_fields,SX_COUNT(sxexm_resource_map_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_type_count_fields[] = {
 SX_FIELD("type_count_minus_one","uint16",0,2,SX_NONE),
};
static const sx_layout sxexm_resource_type_count = {UINT32_C(0x602b0013),"resource_type_count",sxexm_resource_type_count_fields,SX_COUNT(sxexm_resource_type_count_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_type_entry_fields[] = {
 SX_FIELD("resource_type","char[4]",0,4,SX_ID),
 SX_FIELD("resource_count_minus_one","uint16",4,2,SX_NONE),
 SX_FIELD("references_offset","uint16",6,2,SX_OFFSET),
};
static const sx_layout sxexm_resource_type_entry = {UINT32_C(0x602b0014),"resource_type_entry",sxexm_resource_type_entry_fields,SX_COUNT(sxexm_resource_type_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_reference_fields[] = {
 SX_FIELD("resource_id","int16",0,2,SX_ID),
 SX_FIELD("name_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("attributes","uint8",4,1,SX_FLAGS),
 SX_FIELD("data_offset","uint24",5,3,SX_OFFSET),
 SX_FIELD("handle","uint32",8,4,SX_POINTER),
};
static const sx_layout sxexm_resource_reference = {UINT32_C(0x602b0015),"resource_reference",sxexm_resource_reference_fields,SX_COUNT(sxexm_resource_reference_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_data_length_fields[] = {
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxexm_resource_data_length = {UINT32_C(0x602b0016),"resource_data_length",sxexm_resource_data_length_fields,SX_COUNT(sxexm_resource_data_length_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_name_length_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxexm_resource_name_length = {UINT32_C(0x602b0017),"resource_name_length",sxexm_resource_name_length_fields,SX_COUNT(sxexm_resource_name_length_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_pebble_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("structure_major","uint8",8,1,SX_ID),
 SX_FIELD("structure_minor","uint8",9,1,SX_ID),
 SX_FIELD("sdk_major","uint8",10,1,SX_ID),
 SX_FIELD("sdk_minor","uint8",11,1,SX_ID),
 SX_FIELD("application_major","uint8",12,1,SX_ID),
 SX_FIELD("application_minor","uint8",13,1,SX_ID),
 SX_FIELD("image_size","uint16",14,2,SX_SIZE),
 SX_FIELD("entry_point","uint32",16,4,SX_OFFSET),
 SX_FIELD("image_crc32","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("application_name","char[32]",24,32,SX_STRING),
 SX_FIELD("company_name","char[32]",56,32,SX_STRING),
 SX_FIELD("icon_resource_id","uint32",88,4,SX_ID),
 SX_FIELD("symbol_table_address","uint32",92,4,SX_ADDRESS),
 SX_FIELD("flags","uint32",96,4,SX_FLAGS),
 SX_FIELD("relocation_count","uint32",100,4,SX_COUNT_PROP),
 SX_FIELD("uuid","uint8[16]",104,16,SX_ID),
 SX_FIELD("header_crc32","uint32",120,4,SX_CHECKSUM),
};
static const sx_layout sxexm_pebble_header = {UINT32_C(0x602b0018),"pebble_header",sxexm_pebble_header_fields,SX_COUNT(sxexm_pebble_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pebble_relocation_fields[] = {
 SX_FIELD("relocation_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxexm_pebble_relocation = {UINT32_C(0x602b0019),"pebble_relocation",sxexm_pebble_relocation_fields,SX_COUNT(sxexm_pebble_relocation_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_nro_start_fields[] = {
 SX_FIELD("version_or_instruction","uint32",0,4,SX_NONE),
 SX_FIELD("module_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("version_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxexm_nro_start = {UINT32_C(0x602b001a),"nro_start",sxexm_nro_start_fields,SX_COUNT(sxexm_nro_start_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_nro_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("image_size","uint32",8,4,SX_SIZE),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("text_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("text_size","uint32",20,4,SX_SIZE),
 SX_FIELD("ro_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("ro_size","uint32",28,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",36,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",40,4,SX_SIZE),
 SX_FIELD("additional_header_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("build_id","uint8[32]",48,32,SX_ID),
 SX_FIELD("dso_handle_offset","uint32",80,4,SX_OFFSET),
 SX_FIELD("reserved100","uint32",84,4,SX_RESERVED),
 SX_FIELD("embedded_offset","uint32",88,4,SX_OFFSET),
 SX_FIELD("embedded_size","uint32",92,4,SX_SIZE),
 SX_FIELD("dynstr_offset","uint32",96,4,SX_OFFSET),
 SX_FIELD("dynstr_size","uint32",100,4,SX_SIZE),
 SX_FIELD("dynsym_offset","uint32",104,4,SX_OFFSET),
 SX_FIELD("dynsym_size","uint32",108,4,SX_SIZE),
};
static const sx_layout sxexm_nro_header = {UINT32_C(0x602b001b),"nro_header",sxexm_nro_header_fields,SX_COUNT(sxexm_nro_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_nro_asset_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("icon_offset","uint64",8,8,SX_OFFSET),
 SX_FIELD("icon_size","uint64",16,8,SX_SIZE),
 SX_FIELD("nacp_offset","uint64",24,8,SX_OFFSET),
 SX_FIELD("nacp_size","uint64",32,8,SX_SIZE),
 SX_FIELD("romfs_offset","uint64",40,8,SX_OFFSET),
 SX_FIELD("romfs_size","uint64",48,8,SX_SIZE),
};
static const sx_layout sxexm_nro_asset_header = {UINT32_C(0x602b001c),"nro_asset_header",sxexm_nro_asset_header_fields,SX_COUNT(sxexm_nro_asset_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_nso_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("text_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("text_address","uint32",20,4,SX_ADDRESS),
 SX_FIELD("text_size","uint32",24,4,SX_SIZE),
 SX_FIELD("module_name_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("ro_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("ro_address","uint32",36,4,SX_ADDRESS),
 SX_FIELD("ro_size","uint32",40,4,SX_SIZE),
 SX_FIELD("module_name_size","uint32",44,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("data_address","uint32",52,4,SX_ADDRESS),
 SX_FIELD("data_size","uint32",56,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",60,4,SX_SIZE),
 SX_FIELD("build_id","uint8[32]",64,32,SX_ID),
 SX_FIELD("text_compressed_size","uint32",96,4,SX_SIZE),
 SX_FIELD("ro_compressed_size","uint32",100,4,SX_SIZE),
 SX_FIELD("data_compressed_size","uint32",104,4,SX_SIZE),
 SX_FIELD("reserved108","uint8[28]",108,28,SX_RESERVED),
 SX_FIELD("embedded_offset","uint32",136,4,SX_OFFSET),
 SX_FIELD("embedded_size","uint32",140,4,SX_SIZE),
 SX_FIELD("dynstr_offset","uint32",144,4,SX_OFFSET),
 SX_FIELD("dynstr_size","uint32",148,4,SX_SIZE),
 SX_FIELD("dynsym_offset","uint32",152,4,SX_OFFSET),
 SX_FIELD("dynsym_size","uint32",156,4,SX_SIZE),
 SX_FIELD("text_sha256","uint8[32]",160,32,SX_CHECKSUM),
 SX_FIELD("ro_sha256","uint8[32]",192,32,SX_CHECKSUM),
 SX_FIELD("data_sha256","uint8[32]",224,32,SX_CHECKSUM),
};
static const sx_layout sxexm_nso_header = {UINT32_C(0x602b001d),"nso_header",sxexm_nso_header_fields,SX_COUNT(sxexm_nso_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xbe_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("digital_signature","uint8[256]",4,256,SX_SIGNATURE),
 SX_FIELD("base_address","uint32",260,4,SX_ADDRESS),
 SX_FIELD("headers_size","uint32",264,4,SX_SIZE),
 SX_FIELD("image_size","uint32",268,4,SX_SIZE),
 SX_FIELD("image_header_size","uint32",272,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",276,4,SX_TIME),
 SX_FIELD("certificate_address","uint32",280,4,SX_ADDRESS),
 SX_FIELD("section_count","uint32",284,4,SX_COUNT_PROP),
 SX_FIELD("section_headers_address","uint32",288,4,SX_ADDRESS),
 SX_FIELD("initialization_flags","uint32",292,4,SX_FLAGS),
 SX_FIELD("encoded_entry_point","uint32",296,4,SX_FLAGS),
 SX_FIELD("tls_address","uint32",300,4,SX_ADDRESS),
 SX_FIELD("stack_commit","uint32",304,4,SX_SIZE),
 SX_FIELD("heap_reserve","uint32",308,4,SX_SIZE),
 SX_FIELD("heap_commit","uint32",312,4,SX_SIZE),
 SX_FIELD("original_base_address","uint32",316,4,SX_ADDRESS),
 SX_FIELD("original_image_size","uint32",320,4,SX_SIZE),
 SX_FIELD("original_checksum","uint32",324,4,SX_CHECKSUM),
 SX_FIELD("original_timestamp","uint32",328,4,SX_TIME),
 SX_FIELD("debug_path_address","uint32",332,4,SX_ADDRESS),
 SX_FIELD("debug_filename_address","uint32",336,4,SX_ADDRESS),
 SX_FIELD("debug_unicode_filename_address","uint32",340,4,SX_ADDRESS),
 SX_FIELD("encoded_kernel_thunk_address","uint32",344,4,SX_FLAGS),
 SX_FIELD("nonkernel_import_address","uint32",348,4,SX_ADDRESS),
 SX_FIELD("library_version_count","uint32",352,4,SX_COUNT_PROP),
 SX_FIELD("library_versions_address","uint32",356,4,SX_ADDRESS),
 SX_FIELD("kernel_library_version_address","uint32",360,4,SX_ADDRESS),
 SX_FIELD("xapi_library_version_address","uint32",364,4,SX_ADDRESS),
 SX_FIELD("logo_address","uint32",368,4,SX_ADDRESS),
 SX_FIELD("logo_size","uint32",372,4,SX_SIZE),
};
static const sx_layout sxexm_xbe_header = {UINT32_C(0x602b001e),"xbe_header",sxexm_xbe_header_fields,SX_COUNT(sxexm_xbe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xbe_section_fields[] = {
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("virtual_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("virtual_size","uint32",8,4,SX_SIZE),
 SX_FIELD("raw_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("raw_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name_address","uint32",20,4,SX_ADDRESS),
 SX_FIELD("reference_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("head_shared_reference_address","uint32",28,4,SX_ADDRESS),
 SX_FIELD("tail_shared_reference_address","uint32",32,4,SX_ADDRESS),
 SX_FIELD("sha1","uint8[20]",36,20,SX_CHECKSUM),
};
static const sx_layout sxexm_xbe_section = {UINT32_C(0x602b001f),"xbe_section",sxexm_xbe_section_fields,SX_COUNT(sxexm_xbe_section_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xbe_certificate_fields[] = {
 SX_FIELD("certificate_size","uint32",0,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",4,4,SX_TIME),
 SX_FIELD("title_id","uint32",8,4,SX_ID),
 SX_FIELD("title_name","uint16[40]",12,80,SX_STRING),
 SX_FIELD("alternate_title_ids","uint32[16]",92,64,SX_ID),
 SX_FIELD("allowed_media","uint32",156,4,SX_FLAGS),
 SX_FIELD("game_region","uint32",160,4,SX_FLAGS),
 SX_FIELD("game_ratings","uint32",164,4,SX_FLAGS),
 SX_FIELD("disc_number","uint32",168,4,SX_ID),
 SX_FIELD("version","uint32",172,4,SX_ID),
 SX_FIELD("lan_key","uint8[16]",176,16,SX_NONE),
 SX_FIELD("signature_key","uint8[16]",192,16,SX_NONE),
 SX_FIELD("alternate_signature_keys","uint8[256]",208,256,SX_NONE),
};
static const sx_layout sxexm_xbe_certificate = {UINT32_C(0x602b0020),"xbe_certificate",sxexm_xbe_certificate_fields,SX_COUNT(sxexm_xbe_certificate_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_prefix_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("valid_dump","char[4]",4,4,SX_SIGNATURE),
 SX_FIELD("major_version","uint32",8,4,SX_ID),
 SX_FIELD("minor_version","uint32",12,4,SX_ID),
 SX_FIELD("directory_table_base","uint64",16,8,SX_ADDRESS),
 SX_FIELD("pfn_database","uint64",24,8,SX_ADDRESS),
 SX_FIELD("loaded_module_list","uint64",32,8,SX_ADDRESS),
 SX_FIELD("active_process_head","uint64",40,8,SX_ADDRESS),
 SX_FIELD("machine_type","uint32",48,4,SX_ID),
 SX_FIELD("processor_count","uint32",52,4,SX_COUNT_PROP),
 SX_FIELD("bugcheck_code","uint32",56,4,SX_ID),
 SX_FIELD("padding","uint32",60,4,SX_RESERVED),
 SX_FIELD("bugcheck_parameters","uint64[4]",64,32,SX_NONE),
 SX_FIELD("version_user","char[32]",96,32,SX_STRING),
 SX_FIELD("debugger_data_block","uint64",128,8,SX_ADDRESS),
};
static const sx_layout sxexm_dmp64_prefix = {UINT32_C(0x602b0021),"dmp64_prefix",sxexm_dmp64_prefix_fields,SX_COUNT(sxexm_dmp64_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_type_fields[] = {
 SX_FIELD("dump_type","uint32",0,4,SX_ID),
};
static const sx_layout sxexm_dmp64_type = {UINT32_C(0x602b0022),"dmp64_type",sxexm_dmp64_type_fields,SX_COUNT(sxexm_dmp64_type_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_required_space_fields[] = {
 SX_FIELD("required_space","uint64",0,8,SX_SIZE),
};
static const sx_layout sxexm_dmp64_required_space = {UINT32_C(0x602b0023),"dmp64_required_space",sxexm_dmp64_required_space_fields,SX_COUNT(sxexm_dmp64_required_space_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_product_fields[] = {
 SX_FIELD("secondary_state","uint32",0,4,SX_FLAGS),
 SX_FIELD("product_type","uint32",4,4,SX_ID),
 SX_FIELD("suite_mask","uint32",8,4,SX_FLAGS),
};
static const sx_layout sxexm_dmp64_product = {UINT32_C(0x602b0024),"dmp64_product",sxexm_dmp64_product_fields,SX_COUNT(sxexm_dmp64_product_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dmp64_bitmap_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("unknown","uint8[24]",8,24,SX_NONE),
 SX_FIELD("first_page_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("present_page_count","uint64",40,8,SX_COUNT_PROP),
 SX_FIELD("addressable_page_count","uint64",48,8,SX_COUNT_PROP),
};
static const sx_layout sxexm_dmp64_bitmap_header = {UINT32_C(0x602b0025),"dmp64_bitmap_header",sxexm_dmp64_bitmap_header_fields,SX_COUNT(sxexm_dmp64_bitmap_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_cgc_header_le_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("elf_class","uint8",4,1,SX_ID),
 SX_FIELD("endian","uint8",5,1,SX_ID),
 SX_FIELD("elf_version","uint8",6,1,SX_ID),
 SX_FIELD("osabi","uint8",7,1,SX_ID),
 SX_FIELD("abi_version","uint8",8,1,SX_ID),
 SX_FIELD("padding","uint8[7]",9,7,SX_RESERVED),
 SX_FIELD("file_type","uint16",16,2,SX_ID),
 SX_FIELD("machine","uint16",18,2,SX_ID),
 SX_FIELD("version","uint32",20,4,SX_ID),
 SX_FIELD("entry_point","uint32",24,4,SX_ADDRESS),
 SX_FIELD("program_headers_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("section_headers_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("flags","uint32",36,4,SX_FLAGS),
 SX_FIELD("header_size","uint16",40,2,SX_SIZE),
 SX_FIELD("program_header_size","uint16",42,2,SX_SIZE),
 SX_FIELD("program_header_count","uint16",44,2,SX_COUNT_PROP),
 SX_FIELD("section_header_size","uint16",46,2,SX_SIZE),
 SX_FIELD("section_header_count","uint16",48,2,SX_COUNT_PROP),
 SX_FIELD("section_names_index","uint16",50,2,SX_ID),
};
static const sx_layout sxexm_cgc_header_le = {UINT32_C(0x602b0026),"cgc_header_le",sxexm_cgc_header_le_fields,SX_COUNT(sxexm_cgc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_cgc_header_be_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("elf_class","uint8",4,1,SX_ID),
 SX_FIELD("endian","uint8",5,1,SX_ID),
 SX_FIELD("elf_version","uint8",6,1,SX_ID),
 SX_FIELD("osabi","uint8",7,1,SX_ID),
 SX_FIELD("abi_version","uint8",8,1,SX_ID),
 SX_FIELD("padding","uint8[7]",9,7,SX_RESERVED),
 SX_FIELD("file_type","uint16",16,2,SX_ID),
 SX_FIELD("machine","uint16",18,2,SX_ID),
 SX_FIELD("version","uint32",20,4,SX_ID),
 SX_FIELD("entry_point","uint32",24,4,SX_ADDRESS),
 SX_FIELD("program_headers_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("section_headers_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("flags","uint32",36,4,SX_FLAGS),
 SX_FIELD("header_size","uint16",40,2,SX_SIZE),
 SX_FIELD("program_header_size","uint16",42,2,SX_SIZE),
 SX_FIELD("program_header_count","uint16",44,2,SX_COUNT_PROP),
 SX_FIELD("section_header_size","uint16",46,2,SX_SIZE),
 SX_FIELD("section_header_count","uint16",48,2,SX_COUNT_PROP),
 SX_FIELD("section_names_index","uint16",50,2,SX_ID),
};
static const sx_layout sxexm_cgc_header_be = {UINT32_C(0x602b0027),"cgc_header_be",sxexm_cgc_header_be_fields,SX_COUNT(sxexm_cgc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_cgc_program_header_le_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("file_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("virtual_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("physical_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("file_size","uint32",16,4,SX_SIZE),
 SX_FIELD("memory_size","uint32",20,4,SX_SIZE),
 SX_FIELD("flags","uint32",24,4,SX_FLAGS),
 SX_FIELD("alignment","uint32",28,4,SX_SIZE),
};
static const sx_layout sxexm_cgc_program_header_le = {UINT32_C(0x602b0028),"cgc_program_header_le",sxexm_cgc_program_header_le_fields,SX_COUNT(sxexm_cgc_program_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_cgc_program_header_be_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("file_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("virtual_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("physical_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("file_size","uint32",16,4,SX_SIZE),
 SX_FIELD("memory_size","uint32",20,4,SX_SIZE),
 SX_FIELD("flags","uint32",24,4,SX_FLAGS),
 SX_FIELD("alignment","uint32",28,4,SX_SIZE),
};
static const sx_layout sxexm_cgc_program_header_be = {UINT32_C(0x602b0029),"cgc_program_header_be",sxexm_cgc_program_header_be_fields,SX_COUNT(sxexm_cgc_program_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_cgc_section_header_le_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("type","uint32",4,4,SX_ID),
 SX_FIELD("flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("file_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",20,4,SX_SIZE),
 SX_FIELD("link","uint32",24,4,SX_ID),
 SX_FIELD("info","uint32",28,4,SX_NONE),
 SX_FIELD("alignment","uint32",32,4,SX_SIZE),
 SX_FIELD("entry_size","uint32",36,4,SX_SIZE),
};
static const sx_layout sxexm_cgc_section_header_le = {UINT32_C(0x602b002a),"cgc_section_header_le",sxexm_cgc_section_header_le_fields,SX_COUNT(sxexm_cgc_section_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_cgc_section_header_be_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("type","uint32",4,4,SX_ID),
 SX_FIELD("flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("file_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",20,4,SX_SIZE),
 SX_FIELD("link","uint32",24,4,SX_ID),
 SX_FIELD("info","uint32",28,4,SX_NONE),
 SX_FIELD("alignment","uint32",32,4,SX_SIZE),
 SX_FIELD("entry_size","uint32",36,4,SX_SIZE),
};
static const sx_layout sxexm_cgc_section_header_be = {UINT32_C(0x602b002b),"cgc_section_header_be",sxexm_cgc_section_header_be_fields,SX_COUNT(sxexm_cgc_section_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_header_fields[] = {
 SX_FIELD("module_id","uint32",0,4,SX_ID),
 SX_FIELD("next_module_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("previous_module_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("section_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("section_table_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("module_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("module_name_size","uint32",24,4,SX_SIZE),
 SX_FIELD("version","uint32",28,4,SX_ID),
 SX_FIELD("bss_size","uint32",32,4,SX_SIZE),
 SX_FIELD("relocation_table_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("import_table_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("import_table_size","uint32",44,4,SX_SIZE),
 SX_FIELD("prolog_section","uint8",48,1,SX_ID),
 SX_FIELD("epilog_section","uint8",49,1,SX_ID),
 SX_FIELD("unresolved_section","uint8",50,1,SX_ID),
 SX_FIELD("bss_section","uint8",51,1,SX_ID),
 SX_FIELD("prolog_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("epilog_offset","uint32",56,4,SX_OFFSET),
 SX_FIELD("unresolved_offset","uint32",60,4,SX_OFFSET),
};
static const sx_layout sxexm_rel_header = {UINT32_C(0x602b002c),"rel_header",sxexm_rel_header_fields,SX_COUNT(sxexm_rel_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_v2_extension_fields[] = {
 SX_FIELD("section_alignment","uint32",0,4,SX_SIZE),
 SX_FIELD("bss_alignment","uint32",4,4,SX_SIZE),
};
static const sx_layout sxexm_rel_v2_extension = {UINT32_C(0x602b002d),"rel_v2_extension",sxexm_rel_v2_extension_fields,SX_COUNT(sxexm_rel_v2_extension_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_v3_extension_fields[] = {
 SX_FIELD("section_alignment","uint32",0,4,SX_SIZE),
 SX_FIELD("bss_alignment","uint32",4,4,SX_SIZE),
 SX_FIELD("fix_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxexm_rel_v3_extension = {UINT32_C(0x602b002e),"rel_v3_extension",sxexm_rel_v3_extension_fields,SX_COUNT(sxexm_rel_v3_extension_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_section_fields[] = {
 SX_FIELD("offset_and_executable","uint32",0,4,SX_FLAGS),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxexm_rel_section = {UINT32_C(0x602b002f),"rel_section",sxexm_rel_section_fields,SX_COUNT(sxexm_rel_section_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_import_fields[] = {
 SX_FIELD("module_id","uint32",0,4,SX_ID),
 SX_FIELD("relocations_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxexm_rel_import = {UINT32_C(0x602b0030),"rel_import",sxexm_rel_import_fields,SX_COUNT(sxexm_rel_import_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_rel_relocation_fields[] = {
 SX_FIELD("offset_delta","uint16",0,2,SX_OFFSET),
 SX_FIELD("relocation_type","uint8",2,1,SX_ID),
 SX_FIELD("section","uint8",3,1,SX_ID),
 SX_FIELD("addend","uint32",4,4,SX_NONE),
};
static const sx_layout sxexm_rel_relocation = {UINT32_C(0x602b0031),"rel_relocation",sxexm_rel_relocation_fields,SX_COUNT(sxexm_rel_relocation_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xtac_header_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("is_updated","uint32",8,4,SX_FLAGS),
 SX_FIELD("address_pairs_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("address_pair_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("module_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("module_name_size","uint32",24,4,SX_SIZE),
 SX_FIELD("nt_path_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("nt_path_size","uint32",32,4,SX_SIZE),
 SX_FIELD("head_block_stub_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("tail_block_stub_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("block_stub_code_size","uint32",44,4,SX_SIZE),
 SX_FIELD("linked_list_head_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("linked_list_tail_offset","uint32",52,4,SX_OFFSET),
};
static const sx_layout sxexm_xtac_header = {UINT32_C(0x602b0032),"xtac_header",sxexm_xtac_header_fields,SX_COUNT(sxexm_xtac_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_address_pair_fields[] = {
 SX_FIELD("x86_rva","uint32",0,4,SX_ADDRESS),
 SX_FIELD("arm64_rva","uint32",4,4,SX_ADDRESS),
};
static const sx_layout sxexm_xtac_address_pair = {UINT32_C(0x602b0033),"xtac_address_pair",sxexm_xtac_address_pair_fields,SX_COUNT(sxexm_xtac_address_pair_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_block_stub_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("offset_to_next_entry","uint32",4,4,SX_OFFSET),
 SX_FIELD("next_entry_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("padding","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxexm_xtac_block_stub = {UINT32_C(0x602b0034),"xtac_block_stub",sxexm_xtac_block_stub_fields,SX_COUNT(sxexm_xtac_block_stub_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_linked_entry0_fields[] = {
 SX_FIELD("metadata_and_step","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxexm_xtac_linked_entry0 = {UINT32_C(0x602b0035),"xtac_linked_entry0",sxexm_xtac_linked_entry0_fields,SX_COUNT(sxexm_xtac_linked_entry0_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_linked_entry1_fields[] = {
 SX_FIELD("metadata_and_step","uint32",0,4,SX_FLAGS),
 SX_FIELD("forward_edge_address","uint32",4,4,SX_ADDRESS),
};
static const sx_layout sxexm_xtac_linked_entry1 = {UINT32_C(0x602b0036),"xtac_linked_entry1",sxexm_xtac_linked_entry1_fields,SX_COUNT(sxexm_xtac_linked_entry1_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_linked_entry2_fields[] = {
 SX_FIELD("metadata_and_step","uint32",0,4,SX_FLAGS),
 SX_FIELD("backward_edge_address","uint32",4,4,SX_ADDRESS),
};
static const sx_layout sxexm_xtac_linked_entry2 = {UINT32_C(0x602b0037),"xtac_linked_entry2",sxexm_xtac_linked_entry2_fields,SX_COUNT(sxexm_xtac_linked_entry2_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_xtac_linked_entry3_fields[] = {
 SX_FIELD("metadata_and_step","uint32",0,4,SX_FLAGS),
 SX_FIELD("forward_edge_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("backward_edge_address","uint32",8,4,SX_ADDRESS),
};
static const sx_layout sxexm_xtac_linked_entry3 = {UINT32_C(0x602b0038),"xtac_linked_entry3",sxexm_xtac_linked_entry3_fields,SX_COUNT(sxexm_xtac_linked_entry3_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_record_header_fields[] = {
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("reserved1","uint8",1,1,SX_RESERVED),
 SX_FIELD("data_size","uint16",2,2,SX_SIZE),
 SX_FIELD("reserved2","uint16",4,2,SX_RESERVED),
};
static const sx_layout sxexm_qnx_record_header = {UINT32_C(0x602b0039),"qnx_record_header",sxexm_qnx_record_header_fields,SX_COUNT(sxexm_qnx_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_module_header_fields[] = {
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("cpu","uint16",4,2,SX_ID),
 SX_FIELD("fpu","uint16",6,2,SX_ID),
 SX_FIELD("code_index","uint16",8,2,SX_ID),
 SX_FIELD("stack_index","uint16",10,2,SX_ID),
 SX_FIELD("heap_index","uint16",12,2,SX_ID),
 SX_FIELD("argv_index","uint16",14,2,SX_ID),
 SX_FIELD("spare2","uint16[4]",16,8,SX_RESERVED),
 SX_FIELD("code_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("stack_size","uint32",28,4,SX_SIZE),
 SX_FIELD("heap_size","uint32",32,4,SX_SIZE),
 SX_FIELD("image_base","uint32",36,4,SX_ADDRESS),
 SX_FIELD("spare3","uint32[2]",40,8,SX_RESERVED),
};
static const sx_layout sxexm_qnx_module_header = {UINT32_C(0x602b003a),"qnx_module_header",sxexm_qnx_module_header_fields,SX_COUNT(sxexm_qnx_module_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_segment_fields[] = {
 SX_FIELD("size_and_flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxexm_qnx_segment = {UINT32_C(0x602b003b),"qnx_segment",sxexm_qnx_segment_fields,SX_COUNT(sxexm_qnx_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_load_header_fields[] = {
 SX_FIELD("segment_index","uint16",0,2,SX_ID),
 SX_FIELD("segment_offset","uint32",2,4,SX_OFFSET),
};
static const sx_layout sxexm_qnx_load_header = {UINT32_C(0x602b003c),"qnx_load_header",sxexm_qnx_load_header_fields,SX_COUNT(sxexm_qnx_load_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_resource_header_fields[] = {
 SX_FIELD("resource_type","uint16",0,2,SX_ID),
 SX_FIELD("spare","uint16[3]",2,6,SX_RESERVED),
};
static const sx_layout sxexm_qnx_resource_header = {UINT32_C(0x602b003d),"qnx_resource_header",sxexm_qnx_resource_header_fields,SX_COUNT(sxexm_qnx_resource_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_read_write_end_fields[] = {
 SX_FIELD("verification","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("signature","uint32",2,4,SX_SIGNATURE),
};
static const sx_layout sxexm_qnx_read_write_end = {UINT32_C(0x602b003e),"qnx_read_write_end",sxexm_qnx_read_write_end_fields,SX_COUNT(sxexm_qnx_read_write_end_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_qnx_image_end_fields[] = {
 SX_FIELD("spare","uint16[3]",0,6,SX_RESERVED),
};
static const sx_layout sxexm_qnx_image_end = {UINT32_C(0x602b003f),"qnx_image_end",sxexm_qnx_image_end_fields,SX_COUNT(sxexm_qnx_image_end_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_omf_record_header_fields[] = {
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("record_size","uint16",1,2,SX_SIZE),
};
static const sx_layout sxexm_omf_record_header = {UINT32_C(0x602b0040),"omf_record_header",sxexm_omf_record_header_fields,SX_COUNT(sxexm_omf_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_omf_checksum_fields[] = {
 SX_FIELD("checksum","uint8",0,1,SX_CHECKSUM),
};
static const sx_layout sxexm_omf_checksum = {UINT32_C(0x602b0041),"omf_checksum",sxexm_omf_checksum_fields,SX_COUNT(sxexm_omf_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_omf_name_length_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxexm_omf_name_length = {UINT32_C(0x602b0042),"omf_name_length",sxexm_omf_name_length_fields,SX_COUNT(sxexm_omf_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dos_extender_mz_fields[] = {
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("last_page_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("pages_in_file","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("relocation_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("header_paragraphs","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("min_alloc_paragraphs","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("max_alloc_paragraphs","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("initial_ss","uint16",14,2,SX_NONE),
 SX_FIELD("initial_sp","uint16",16,2,SX_ADDRESS),
 SX_FIELD("checksum","uint16",18,2,SX_CHECKSUM),
 SX_FIELD("initial_ip","uint16",20,2,SX_ADDRESS),
 SX_FIELD("initial_cs","uint16",22,2,SX_NONE),
 SX_FIELD("relocations_offset","uint16",24,2,SX_OFFSET),
 SX_FIELD("overlay_number","uint16",26,2,SX_ID),
 SX_FIELD("reserved","uint16[4]",28,8,SX_RESERVED),
 SX_FIELD("oem_id","uint16",36,2,SX_ID),
 SX_FIELD("oem_info","uint16",38,2,SX_NONE),
 SX_FIELD("reserved2","uint16[10]",40,20,SX_RESERVED),
 SX_FIELD("new_header_offset","uint32",60,4,SX_OFFSET),
};
static const sx_layout sxexm_dos_extender_mz = {UINT32_C(0x602b0043),"dos_extender_mz",sxexm_dos_extender_mz_fields,SX_COUNT(sxexm_dos_extender_mz_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dos16m_bw_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("last_page_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("pages_in_file","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("reserved1","uint16",6,2,SX_RESERVED),
 SX_FIELD("reserved2","uint16",8,2,SX_RESERVED),
 SX_FIELD("min_alloc_kib","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("max_alloc_kib","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("stack_selector","uint16",14,2,SX_ID),
 SX_FIELD("stack_pointer","uint16",16,2,SX_ADDRESS),
 SX_FIELD("first_relocation_selector","uint16",18,2,SX_ID),
 SX_FIELD("initial_ip","uint16",20,2,SX_ADDRESS),
 SX_FIELD("code_selector","uint16",22,2,SX_ID),
 SX_FIELD("runtime_gdt_size","uint16",24,2,SX_SIZE),
 SX_FIELD("makepm_version","uint16",26,2,SX_NONE),
 SX_FIELD("next_header_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("codeview_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("last_selector","uint16",36,2,SX_ID),
 SX_FIELD("physical_alloc_kib","uint16",38,2,SX_COUNT_PROP),
 SX_FIELD("allocation_increment_kib","uint16",40,2,SX_COUNT_PROP),
 SX_FIELD("unknown42","uint8[6]",42,6,SX_NONE),
 SX_FIELD("options","uint16",48,2,SX_FLAGS),
 SX_FIELD("transition_stack_selector","uint16",50,2,SX_ID),
 SX_FIELD("flags","uint16",52,2,SX_FLAGS),
 SX_FIELD("program_paragraphs","uint16",54,2,SX_COUNT_PROP),
 SX_FIELD("gdt_image_size","uint16",56,2,SX_SIZE),
 SX_FIELD("first_selector","uint16",58,2,SX_ID),
 SX_FIELD("default_memory_strategy","uint8",60,1,SX_ID),
 SX_FIELD("unknown61","uint8",61,1,SX_NONE),
 SX_FIELD("transfer_buffer_size","uint16",62,2,SX_SIZE),
 SX_FIELD("unknown64","uint8[48]",64,48,SX_NONE),
 SX_FIELD("exp_path","char[64]",112,64,SX_STRING),
};
static const sx_layout sxexm_dos16m_bw_header = {UINT32_C(0x602b0044),"dos16m_bw_header",sxexm_dos16m_bw_header_fields,SX_COUNT(sxexm_dos16m_bw_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_dos16m_mf_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("block_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxexm_dos16m_mf_header = {UINT32_C(0x602b0045),"dos16m_mf_header",sxexm_dos16m_mf_header_fields,SX_COUNT(sxexm_dos16m_mf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_amiga_hunk_tag_fields[] = {
 SX_FIELD("type_and_memory_flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxexm_amiga_hunk_tag = {UINT32_C(0x602b0046),"amiga_hunk_tag",sxexm_amiga_hunk_tag_fields,SX_COUNT(sxexm_amiga_hunk_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_hunk_length_fields[] = {
 SX_FIELD("longword_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxexm_amiga_hunk_length = {UINT32_C(0x602b0047),"amiga_hunk_length",sxexm_amiga_hunk_length_fields,SX_COUNT(sxexm_amiga_hunk_length_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_hunk_table_fields[] = {
 SX_FIELD("table_size","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_hunk","uint32",4,4,SX_ID),
 SX_FIELD("last_hunk","uint32",8,4,SX_ID),
};
static const sx_layout sxexm_amiga_hunk_table = {UINT32_C(0x602b0048),"amiga_hunk_table",sxexm_amiga_hunk_table_fields,SX_COUNT(sxexm_amiga_hunk_table_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_hunk_allocation_fields[] = {
 SX_FIELD("size_and_memory_flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxexm_amiga_hunk_allocation = {UINT32_C(0x602b0049),"amiga_hunk_allocation",sxexm_amiga_hunk_allocation_fields,SX_COUNT(sxexm_amiga_hunk_allocation_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_memory_flags_fields[] = {
 SX_FIELD("memory_flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxexm_amiga_memory_flags = {UINT32_C(0x602b004a),"amiga_memory_flags",sxexm_amiga_memory_flags_fields,SX_COUNT(sxexm_amiga_memory_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_count16_fields[] = {
 SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxexm_amiga_relocation_count16 = {UINT32_C(0x602b004b),"amiga_relocation_count16",sxexm_amiga_relocation_count16_fields,SX_COUNT(sxexm_amiga_relocation_count16_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_target16_fields[] = {
 SX_FIELD("hunk_index","uint16",0,2,SX_ID),
};
static const sx_layout sxexm_amiga_relocation_target16 = {UINT32_C(0x602b004c),"amiga_relocation_target16",sxexm_amiga_relocation_target16_fields,SX_COUNT(sxexm_amiga_relocation_target16_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_offset16_fields[] = {
 SX_FIELD("offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxexm_amiga_relocation_offset16 = {UINT32_C(0x602b004d),"amiga_relocation_offset16",sxexm_amiga_relocation_offset16_fields,SX_COUNT(sxexm_amiga_relocation_offset16_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_count32_fields[] = {
 SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxexm_amiga_relocation_count32 = {UINT32_C(0x602b004e),"amiga_relocation_count32",sxexm_amiga_relocation_count32_fields,SX_COUNT(sxexm_amiga_relocation_count32_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_target32_fields[] = {
 SX_FIELD("hunk_index","uint32",0,4,SX_ID),
};
static const sx_layout sxexm_amiga_relocation_target32 = {UINT32_C(0x602b004f),"amiga_relocation_target32",sxexm_amiga_relocation_target32_fields,SX_COUNT(sxexm_amiga_relocation_target32_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_relocation_offset32_fields[] = {
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxexm_amiga_relocation_offset32 = {UINT32_C(0x602b0050),"amiga_relocation_offset32",sxexm_amiga_relocation_offset32_fields,SX_COUNT(sxexm_amiga_relocation_offset32_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_symbol_value_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxexm_amiga_symbol_value = {UINT32_C(0x602b0051),"amiga_symbol_value",sxexm_amiga_symbol_value_fields,SX_COUNT(sxexm_amiga_symbol_value_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_ext_name_fields[] = {
 SX_FIELD("type","uint8",0,1,SX_ID),
 SX_FIELD("name_longwords","uint24",1,3,SX_COUNT_PROP),
};
static const sx_layout sxexm_amiga_ext_name = {UINT32_C(0x602b0052),"amiga_ext_name",sxexm_amiga_ext_name_fields,SX_COUNT(sxexm_amiga_ext_name_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_amiga_common_size_fields[] = {
 SX_FIELD("common_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxexm_amiga_common_size = {UINT32_C(0x602b0053),"amiga_common_size",sxexm_amiga_common_size_fields,SX_COUNT(sxexm_amiga_common_size_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_header_fields[] = {
 SX_FIELD("system_id","uint16",0,2,SX_ID),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("version_id","uint32",4,4,SX_ID),
 SX_FIELD("file_time_seconds","uint32",8,4,SX_TIME),
 SX_FIELD("file_time_nanoseconds","uint32",12,4,SX_NONE),
 SX_FIELD("entry_space","uint32",16,4,SX_ID),
 SX_FIELD("entry_subspace","uint32",20,4,SX_ID),
 SX_FIELD("entry_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("auxiliary_header_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("auxiliary_header_size","uint32",32,4,SX_SIZE),
 SX_FIELD("som_size","uint32",36,4,SX_SIZE),
 SX_FIELD("presumed_dp","uint32",40,4,SX_ADDRESS),
 SX_FIELD("space_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("space_count","uint32",48,4,SX_COUNT_PROP),
 SX_FIELD("subspace_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("subspace_count","uint32",56,4,SX_COUNT_PROP),
 SX_FIELD("loader_fixup_offset","uint32",60,4,SX_OFFSET),
 SX_FIELD("loader_fixup_count","uint32",64,4,SX_COUNT_PROP),
 SX_FIELD("space_strings_offset","uint32",68,4,SX_OFFSET),
 SX_FIELD("space_strings_size","uint32",72,4,SX_SIZE),
 SX_FIELD("initialization_array_offset","uint32",76,4,SX_OFFSET),
 SX_FIELD("initialization_array_count","uint32",80,4,SX_COUNT_PROP),
 SX_FIELD("compiler_offset","uint32",84,4,SX_OFFSET),
 SX_FIELD("compiler_count","uint32",88,4,SX_COUNT_PROP),
 SX_FIELD("symbol_offset","uint32",92,4,SX_OFFSET),
 SX_FIELD("symbol_count","uint32",96,4,SX_COUNT_PROP),
 SX_FIELD("fixup_request_offset","uint32",100,4,SX_OFFSET),
 SX_FIELD("fixup_request_count","uint32",104,4,SX_COUNT_PROP),
 SX_FIELD("symbol_strings_offset","uint32",108,4,SX_OFFSET),
 SX_FIELD("symbol_strings_size","uint32",112,4,SX_SIZE),
 SX_FIELD("unloadable_space_offset","uint32",116,4,SX_OFFSET),
 SX_FIELD("unloadable_space_size","uint32",120,4,SX_SIZE),
 SX_FIELD("checksum","uint32",124,4,SX_CHECKSUM),
};
static const sx_layout sxexm_som_header = {UINT32_C(0x602b0054),"som_header",sxexm_som_header_fields,SX_COUNT(sxexm_som_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_space_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("space_number","int32",8,4,SX_ID),
 SX_FIELD("subspace_index","int32",12,4,SX_ID),
 SX_FIELD("subspace_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("loader_fixup_index","int32",20,4,SX_ID),
 SX_FIELD("loader_fixup_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("initialization_pointer_index","int32",28,4,SX_ID),
 SX_FIELD("initialization_pointer_count","uint32",32,4,SX_COUNT_PROP),
};
static const sx_layout sxexm_som_space = {UINT32_C(0x602b0055),"som_space",sxexm_som_space_fields,SX_COUNT(sxexm_som_space_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_subspace_initialized_fields[] = {
 SX_FIELD("space_index","int32",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("file_offset","int32",8,4,SX_OFFSET),
 SX_FIELD("initialization_size","uint32",12,4,SX_SIZE),
 SX_FIELD("subspace_start","uint32",16,4,SX_ADDRESS),
 SX_FIELD("virtual_size","uint32",20,4,SX_SIZE),
 SX_FIELD("alignment_and_reserved","uint32",24,4,SX_FLAGS),
 SX_FIELD("name_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("fixup_request_index","int32",32,4,SX_ID),
 SX_FIELD("fixup_request_count","uint32",36,4,SX_COUNT_PROP),
};
static const sx_layout sxexm_som_subspace_initialized = {UINT32_C(0x602b0056),"som_subspace_initialized",sxexm_som_subspace_initialized_fields,SX_COUNT(sxexm_som_subspace_initialized_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_subspace_pattern_fields[] = {
 SX_FIELD("space_index","int32",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("initialization_pattern","int32",8,4,SX_NONE),
 SX_FIELD("initialization_size","uint32",12,4,SX_SIZE),
 SX_FIELD("subspace_start","uint32",16,4,SX_ADDRESS),
 SX_FIELD("virtual_size","uint32",20,4,SX_SIZE),
 SX_FIELD("alignment_and_reserved","uint32",24,4,SX_FLAGS),
 SX_FIELD("name_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("fixup_request_index","int32",32,4,SX_ID),
 SX_FIELD("fixup_request_count","uint32",36,4,SX_COUNT_PROP),
};
static const sx_layout sxexm_som_subspace_pattern = {UINT32_C(0x602b0057),"som_subspace_pattern",sxexm_som_subspace_pattern_fields,SX_COUNT(sxexm_som_subspace_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_som_symbol_fields[] = {
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("qualifier_name_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("info","uint32",12,4,SX_NONE),
 SX_FIELD("value","uint32",16,4,SX_NONE),
};
static const sx_layout sxexm_som_symbol = {UINT32_C(0x602b0058),"som_symbol",sxexm_som_symbol_fields,SX_COUNT(sxexm_som_symbol_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_file_header_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("section_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("timestamp","int32",4,4,SX_TIME),
 SX_FIELD("symbol_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("symbol_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("optional_header_size","uint16",16,2,SX_SIZE),
 SX_FIELD("flags","uint16",18,2,SX_FLAGS),
};
static const sx_layout sxexm_xcoff32_file_header = {UINT32_C(0x602b0059),"xcoff32_file_header",sxexm_xcoff32_file_header_fields,SX_COUNT(sxexm_xcoff32_file_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_optional_header_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("version_stamp","uint16",2,2,SX_ID),
 SX_FIELD("text_size","uint32",4,4,SX_SIZE),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",12,4,SX_SIZE),
 SX_FIELD("entry_descriptor","uint32",16,4,SX_ADDRESS),
 SX_FIELD("text_start","uint32",20,4,SX_ADDRESS),
 SX_FIELD("data_start","uint32",24,4,SX_ADDRESS),
 SX_FIELD("toc","uint32",28,4,SX_ADDRESS),
 SX_FIELD("entry_section","uint16",32,2,SX_ID),
 SX_FIELD("text_section","uint16",34,2,SX_ID),
 SX_FIELD("data_section","uint16",36,2,SX_ID),
 SX_FIELD("toc_section","uint16",38,2,SX_ID),
 SX_FIELD("loader_section","uint16",40,2,SX_ID),
 SX_FIELD("bss_section","uint16",42,2,SX_ID),
 SX_FIELD("text_alignment_shift","uint16",44,2,SX_NONE),
 SX_FIELD("data_alignment_shift","uint16",46,2,SX_NONE),
 SX_FIELD("module_type","uint16",48,2,SX_ID),
 SX_FIELD("cpu_flags","uint8",50,1,SX_FLAGS),
 SX_FIELD("cpu_type","uint8",51,1,SX_ID),
 SX_FIELD("max_stack_size","uint32",52,4,SX_SIZE),
 SX_FIELD("max_data_size","uint32",56,4,SX_SIZE),
 SX_FIELD("debugger","uint32",60,4,SX_NONE),
 SX_FIELD("text_page_size","uint8",64,1,SX_NONE),
 SX_FIELD("data_page_size","uint8",65,1,SX_NONE),
 SX_FIELD("stack_page_size","uint8",66,1,SX_NONE),
 SX_FIELD("flags","uint8",67,1,SX_FLAGS),
 SX_FIELD("tls_data_section","uint16",68,2,SX_ID),
 SX_FIELD("tls_bss_section","uint16",70,2,SX_ID),
};
static const sx_layout sxexm_xcoff32_optional_header = {UINT32_C(0x602b005a),"xcoff32_optional_header",sxexm_xcoff32_optional_header_fields,SX_COUNT(sxexm_xcoff32_optional_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_section_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("physical_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("virtual_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("size","uint32",16,4,SX_SIZE),
 SX_FIELD("file_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("relocation_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("line_number_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("relocation_count","uint16",32,2,SX_COUNT_PROP),
 SX_FIELD("line_number_count","uint16",34,2,SX_COUNT_PROP),
 SX_FIELD("flags","int32",36,4,SX_FLAGS),
};
static const sx_layout sxexm_xcoff32_section = {UINT32_C(0x602b005b),"xcoff32_section",sxexm_xcoff32_section_fields,SX_COUNT(sxexm_xcoff32_section_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_loader_fields[] = {
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("symbol_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("relocation_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("import_strings_size","uint32",12,4,SX_SIZE),
 SX_FIELD("import_file_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("import_files_offset","int32",20,4,SX_OFFSET),
 SX_FIELD("strings_size","uint32",24,4,SX_SIZE),
 SX_FIELD("strings_offset","int32",28,4,SX_OFFSET),
};
static const sx_layout sxexm_xcoff32_loader = {UINT32_C(0x602b005c),"xcoff32_loader",sxexm_xcoff32_loader_fields,SX_COUNT(sxexm_xcoff32_loader_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_loader_symbol_inline_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("value","uint32",8,4,SX_ADDRESS),
 SX_FIELD("section_number","int16",12,2,SX_ID),
 SX_FIELD("type_flags","uint8",14,1,SX_FLAGS),
 SX_FIELD("storage_class","uint8",15,1,SX_ID),
 SX_FIELD("import_file_index","uint32",16,4,SX_ID),
 SX_FIELD("parameter_type_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxexm_xcoff32_loader_symbol_inline = {UINT32_C(0x602b005d),"xcoff32_loader_symbol_inline",sxexm_xcoff32_loader_symbol_inline_fields,SX_COUNT(sxexm_xcoff32_loader_symbol_inline_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_xcoff32_loader_symbol_external_fields[] = {
 SX_FIELD("zero","uint32",0,4,SX_RESERVED),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("value","uint32",8,4,SX_ADDRESS),
 SX_FIELD("section_number","int16",12,2,SX_ID),
 SX_FIELD("type_flags","uint8",14,1,SX_FLAGS),
 SX_FIELD("storage_class","uint8",15,1,SX_ID),
 SX_FIELD("import_file_index","uint32",16,4,SX_ID),
 SX_FIELD("parameter_type_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxexm_xcoff32_loader_symbol_external = {UINT32_C(0x602b005e),"xcoff32_loader_symbol_external",sxexm_xcoff32_loader_symbol_external_fields,SX_COUNT(sxexm_xcoff32_loader_symbol_external_fields),SX_BE};
static const sx_layout *const sx_executablemore_layouts[] = {
 &sxexm_vz_header,
 &sxexm_xalz_header,
 &sxexm_pyc_header8,
 &sxexm_pyc_header12,
 &sxexm_pyc_header16_timestamp,
 &sxexm_pyc_header16_hash,
 &sxexm_msf7_superblock,
 &sxexm_msf7_directory_block,
 &sxexm_msf7_stream_count,
 &sxexm_msf7_stream_size,
 &sxexm_msf7_stream_block,
 &sxexm_mub_header_le,
 &sxexm_mub_arch32_le,
 &sxexm_mub_header_be,
 &sxexm_mub_arch32_be,
 &sxexm_mub_arch64_be,
 &sxexm_resource_fork_header,
 &sxexm_resource_map_header,
 &sxexm_resource_type_count,
 &sxexm_resource_type_entry,
 &sxexm_resource_reference,
 &sxexm_resource_data_length,
 &sxexm_resource_name_length,
 &sxexm_pebble_header,
 &sxexm_pebble_relocation,
 &sxexm_nro_start,
 &sxexm_nro_header,
 &sxexm_nro_asset_header,
 &sxexm_nso_header,
 &sxexm_xbe_header,
 &sxexm_xbe_section,
 &sxexm_xbe_certificate,
 &sxexm_dmp64_prefix,
 &sxexm_dmp64_type,
 &sxexm_dmp64_required_space,
 &sxexm_dmp64_product,
 &sxexm_dmp64_bitmap_header,
 &sxexm_cgc_header_le,
 &sxexm_cgc_header_be,
 &sxexm_cgc_program_header_le,
 &sxexm_cgc_program_header_be,
 &sxexm_cgc_section_header_le,
 &sxexm_cgc_section_header_be,
 &sxexm_rel_header,
 &sxexm_rel_v2_extension,
 &sxexm_rel_v3_extension,
 &sxexm_rel_section,
 &sxexm_rel_import,
 &sxexm_rel_relocation,
 &sxexm_xtac_header,
 &sxexm_xtac_address_pair,
 &sxexm_xtac_block_stub,
 &sxexm_xtac_linked_entry0,
 &sxexm_xtac_linked_entry1,
 &sxexm_xtac_linked_entry2,
 &sxexm_xtac_linked_entry3,
 &sxexm_qnx_record_header,
 &sxexm_qnx_module_header,
 &sxexm_qnx_segment,
 &sxexm_qnx_load_header,
 &sxexm_qnx_resource_header,
 &sxexm_qnx_read_write_end,
 &sxexm_qnx_image_end,
 &sxexm_omf_record_header,
 &sxexm_omf_checksum,
 &sxexm_omf_name_length,
 &sxexm_dos_extender_mz,
 &sxexm_dos16m_bw_header,
 &sxexm_dos16m_mf_header,
 &sxexm_amiga_hunk_tag,
 &sxexm_amiga_hunk_length,
 &sxexm_amiga_hunk_table,
 &sxexm_amiga_hunk_allocation,
 &sxexm_amiga_memory_flags,
 &sxexm_amiga_relocation_count16,
 &sxexm_amiga_relocation_target16,
 &sxexm_amiga_relocation_offset16,
 &sxexm_amiga_relocation_count32,
 &sxexm_amiga_relocation_target32,
 &sxexm_amiga_relocation_offset32,
 &sxexm_amiga_symbol_value,
 &sxexm_amiga_ext_name,
 &sxexm_amiga_common_size,
 &sxexm_som_header,
 &sxexm_som_space,
 &sxexm_som_subspace_initialized,
 &sxexm_som_subspace_pattern,
 &sxexm_som_symbol,
 &sxexm_xcoff32_file_header,
 &sxexm_xcoff32_optional_header,
 &sxexm_xcoff32_section,
 &sxexm_xcoff32_loader,
 &sxexm_xcoff32_loader_symbol_inline,
 &sxexm_xcoff32_loader_symbol_external,
};
static bool sx_executablemore_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x602b0000U||id>=0x602c0000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x602b0001U:
 if(!xx_rt_wcscmp(r->name,L"file_type"))text=L"0xF0=BASIC, 0xF1=machine code.";
 break;
 case 0x602b0005U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"PEP 552: bit 0 selects hash-based header; bit 1 requests source checking.";
 break;
 case 0x602b0006U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"PEP 552: bit 0 selects hash-based header; bit 1 requests source checking.";
 break;
 case 0x602b0007U:
 if(!xx_rt_wcscmp(r->name,L"free_block_map_block"))text=L"File block index, in block_size-byte units.";
 if(!xx_rt_wcscmp(r->name,L"block_map_block"))text=L"File block index of the directory-block index array.";
 break;
 case 0x602b0008U:
 if(!xx_rt_wcscmp(r->name,L"directory_block_index"))text=L"Physical file block index containing one page of the logical stream directory.";
 break;
 case 0x602b000aU:
 if(!xx_rt_wcscmp(r->name,L"stream_size"))text=L"0xFFFFFFFF denotes an absent stream; other values are byte sizes.";
 break;
 case 0x602b000bU:
 if(!xx_rt_wcscmp(r->name,L"stream_block_index"))text=L"Physical file block index in block_size-byte units.";
 break;
 case 0x602b000dU:
 if(!xx_rt_wcscmp(r->name,L"alignment_shift"))text=L"Slice alignment is 1 << alignment_shift bytes.";
 break;
 case 0x602b000fU:
 if(!xx_rt_wcscmp(r->name,L"alignment_shift"))text=L"Slice alignment is 1 << alignment_shift bytes.";
 break;
 case 0x602b0010U:
 if(!xx_rt_wcscmp(r->name,L"alignment_shift"))text=L"Slice alignment is 1 << alignment_shift bytes.";
 break;
 case 0x602b0012U:
 if(!xx_rt_wcscmp(r->name,L"type_list_offset"))text=L"Relative to the resource map start.";
 if(!xx_rt_wcscmp(r->name,L"name_list_offset"))text=L"Relative to the resource map start.";
 break;
 case 0x602b0013U:
 if(!xx_rt_wcscmp(r->name,L"type_count_minus_one"))text=L"Encoded count minus one; 0xFFFF denotes no types.";
 break;
 case 0x602b0014U:
 if(!xx_rt_wcscmp(r->name,L"resource_count_minus_one"))text=L"Number of references minus one.";
 if(!xx_rt_wcscmp(r->name,L"references_offset"))text=L"Relative to the beginning of the type list, including its count word.";
 break;
 case 0x602b0015U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the name list; 0xFFFF means unnamed.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the data area; points to the resource length word.";
 break;
 case 0x602b0018U:
 if(!xx_rt_wcscmp(r->name,L"entry_point"))text=L"Byte offset in the loaded application image.";
 if(!xx_rt_wcscmp(r->name,L"symbol_table_address"))text=L"Application-image address retained as stored; zero means absent.";
 break;
 case 0x602b0019U:
 if(!xx_rt_wcscmp(r->name,L"relocation_offset"))text=L"Byte offset of the location to relocate in the application image.";
 break;
 case 0x602b001aU:
 if(!xx_rt_wcscmp(r->name,L"version_or_instruction"))text=L"Module-header-location version on firmware 17 or later; padding or an entry instruction in older/homebrew images.";
 if(!xx_rt_wcscmp(r->name,L"version_offset"))text=L"Module-version byte offset on firmware 17 or later; reserved on older NRO images.";
 break;
 case 0x602b001bU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 requests aligned header; bit 1 marks compression on firmware 23 or later.";
 if(!xx_rt_wcscmp(r->name,L"additional_header_offset"))text=L"Additional NRA0 header offset on firmware 23 or later; reserved in older images.";
 if(!xx_rt_wcscmp(r->name,L"dso_handle_offset"))text=L"Image-relative DSO handle offset.";
 if(!xx_rt_wcscmp(r->name,L"embedded_offset"))text=L"Image-relative embedded metadata offset; older tooling names this API-info offset.";
 break;
 case 0x602b001cU:
 if(!xx_rt_wcscmp(r->name,L"icon_offset"))text=L"Relative to this ASET header.";
 if(!xx_rt_wcscmp(r->name,L"nacp_offset"))text=L"Relative to this ASET header.";
 if(!xx_rt_wcscmp(r->name,L"romfs_offset"))text=L"Relative to this ASET header.";
 break;
 case 0x602b001dU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bits 0..2 select section compression; bits 3..5 select decompressed-section SHA-256 checks. Bit 6 selects execute-only memory; bit 7 selects Zstandard instead of LZ4 on newer runtimes.";
 if(!xx_rt_wcscmp(r->name,L"text_address"))text=L"Image-relative virtual address.";
 if(!xx_rt_wcscmp(r->name,L"ro_address"))text=L"Image-relative virtual address.";
 if(!xx_rt_wcscmp(r->name,L"data_address"))text=L"Image-relative virtual address.";
 if(!xx_rt_wcscmp(r->name,L"embedded_offset"))text=L"Offset within decompressed rodata; older tooling names this API-info offset.";
 if(!xx_rt_wcscmp(r->name,L"dynstr_offset"))text=L"Offset within decompressed rodata.";
 if(!xx_rt_wcscmp(r->name,L"dynsym_offset"))text=L"Offset within decompressed rodata.";
 break;
 case 0x602b001eU:
 if(!xx_rt_wcscmp(r->name,L"encoded_entry_point"))text=L"XOR-encoded entry-point word; encoding key depends on retail/debug variant.";
 if(!xx_rt_wcscmp(r->name,L"encoded_kernel_thunk_address"))text=L"XOR-encoded kernel-thunk address word; not a direct virtual address.";
 break;
 case 0x602b0025U:
 if(!xx_rt_wcscmp(r->name,L"present_page_count"))text=L"Number of stored 4096-byte physical memory pages.";
 if(!xx_rt_wcscmp(r->name,L"addressable_page_count"))text=L"Number of bits in the page-presence bitmap.";
 break;
 case 0x602b002aU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the section-name string table.";
 break;
 case 0x602b002bU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the section-name string table.";
 break;
 case 0x602b002cU:
 if(!xx_rt_wcscmp(r->name,L"module_name_offset"))text=L"Offset in the external module-name string table, not a byte offset in this REL image.";
 if(!xx_rt_wcscmp(r->name,L"prolog_offset"))text=L"Byte offset within the corresponding section.";
 if(!xx_rt_wcscmp(r->name,L"epilog_offset"))text=L"Byte offset within the corresponding section.";
 if(!xx_rt_wcscmp(r->name,L"unresolved_offset"))text=L"Byte offset within the corresponding section.";
 break;
 case 0x602b002fU:
 if(!xx_rt_wcscmp(r->name,L"offset_and_executable"))text=L"Low bit marks executable; bits 2..31 are the aligned file byte offset (bit 1 is excluded). Zero offset with nonzero size is BSS.";
 break;
 case 0x602b0031U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Byte delta from the preceding patch position in the current section.";
 if(!xx_rt_wcscmp(r->name,L"relocation_type"))text=L"201=NOP, 202=section selection, 203=end of table; other values are PowerPC relocations.";
 break;
 case 0x602b0033U:
 if(!xx_rt_wcscmp(r->name,L"x86_rva"))text=L"Relative virtual address in the original x86 image.";
 if(!xx_rt_wcscmp(r->name,L"arm64_rva"))text=L"Relative virtual address in the translated ARM64 image.";
 break;
 case 0x602b0034U:
 if(!xx_rt_wcscmp(r->name,L"offset_to_next_entry"))text=L"Byte extent of the code regions following this 16-byte stub.";
 if(!xx_rt_wcscmp(r->name,L"next_entry_offset"))text=L"File-relative byte offset of the next BLCK stub; zero terminates.";
 break;
 case 0x602b0035U:
 if(!xx_rt_wcscmp(r->name,L"metadata_and_step"))text=L"High nibble selects edge fields; low 28 bits encode forward distance in four-byte words, 0x0FFFFFFF terminates.";
 break;
 case 0x602b0036U:
 if(!xx_rt_wcscmp(r->name,L"metadata_and_step"))text=L"High nibble selects edge fields; low 28 bits encode forward distance in four-byte words, 0x0FFFFFFF terminates.";
 break;
 case 0x602b0037U:
 if(!xx_rt_wcscmp(r->name,L"metadata_and_step"))text=L"High nibble selects edge fields; low 28 bits encode forward distance in four-byte words, 0x0FFFFFFF terminates.";
 break;
 case 0x602b0038U:
 if(!xx_rt_wcscmp(r->name,L"metadata_and_step"))text=L"High nibble selects edge fields; low 28 bits encode forward distance in four-byte words, 0x0FFFFFFF terminates.";
 break;
 case 0x602b0039U:
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"0=module header, 1=comment, 2=load, 3=fixup, 4=8087 fixup, 5=image end, 6=resource, 7=read/write end, 8=linear fixup.";
 break;
 case 0x602b003bU:
 if(!xx_rt_wcscmp(r->name,L"size_and_flags"))text=L"Low 28 bits encode segment byte size; high nibble carries segment attributes.";
 break;
 case 0x602b003cU:
 if(!xx_rt_wcscmp(r->name,L"segment_offset"))text=L"Offset within the selected load segment.";
 break;
 case 0x602b0040U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Payload bytes plus the trailing one-byte checksum; excludes this three-byte record header.";
 break;
 case 0x602b0041U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Byte sum of the complete record is zero; zero also denotes an omitted checksum in legacy tools.";
 break;
 case 0x602b0043U:
 if(!xx_rt_wcscmp(r->name,L"pages_in_file"))text=L"Number of 512-byte pages; extender chain location follows the native reader convention.";
 if(!xx_rt_wcscmp(r->name,L"header_paragraphs"))text=L"Number of 16-byte paragraphs in the MZ header.";
 if(!xx_rt_wcscmp(r->name,L"min_alloc_paragraphs"))text=L"Allocation count in 16-byte paragraphs.";
 if(!xx_rt_wcscmp(r->name,L"max_alloc_paragraphs"))text=L"Allocation count in 16-byte paragraphs.";
 break;
 case 0x602b0044U:
 if(!xx_rt_wcscmp(r->name,L"makepm_version"))text=L"Encoded version multiplied by 100.";
 if(!xx_rt_wcscmp(r->name,L"next_header_offset"))text=L"Byte offset relative to the containing DOS executable.";
 if(!xx_rt_wcscmp(r->name,L"program_paragraphs"))text=L"Number of 16-byte paragraphs in the program.";
 if(!xx_rt_wcscmp(r->name,L"transfer_buffer_size"))text=L"Byte size; zero encodes the default 8192-byte buffer.";
 break;
 case 0x602b0046U:
 if(!xx_rt_wcscmp(r->name,L"type_and_memory_flags"))text=L"Low 30 bits are the HUNK type; top two bits encode memory attributes.";
 break;
 case 0x602b0047U:
 if(!xx_rt_wcscmp(r->name,L"longword_count"))text=L"Count in four-byte longwords.";
 break;
 case 0x602b0049U:
 if(!xx_rt_wcscmp(r->name,L"size_and_memory_flags"))text=L"Low 30 bits encode allocation size in longwords; top bits are memory flags. Both top bits set add an explicit memory-attribute word.";
 break;
 case 0x602b004dU:
 if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Byte offset of the relocation in its source hunk.";
 break;
 case 0x602b0050U:
 if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Byte offset of the relocation in its source hunk.";
 break;
 case 0x602b0052U:
 if(!xx_rt_wcscmp(r->name,L"name_longwords"))text=L"Name length in four-byte longwords.";
 break;
 case 0x602b0054U:
 if(!xx_rt_wcscmp(r->name,L"entry_offset"))text=L"Byte offset within the entry subspace.";
 break;
 case 0x602b0055U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset in the space string table.";
 break;
 case 0x602b0056U:
 if(!xx_rt_wcscmp(r->name,L"space_index"))text=L"Signed space index; negative values retain their sentinel meaning.";
 if(!xx_rt_wcscmp(r->name,L"file_offset"))text=L"SOM-relative byte offset of the initialization image; used only when initialization_size is nonzero.";
 if(!xx_rt_wcscmp(r->name,L"subspace_start"))text=L"Virtual byte address relative to the start of the owning space.";
 if(!xx_rt_wcscmp(r->name,L"alignment_and_reserved"))text=L"Packed alignment/reserved word retained without splitting: HP structure diagram specifies 5/27 bits while descriptive text gives 16/16.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset in the space string table.";
 if(!xx_rt_wcscmp(r->name,L"fixup_request_index"))text=L"Signed index of the first fixup; negative values denote no index.";
 break;
 case 0x602b0057U:
 if(!xx_rt_wcscmp(r->name,L"space_index"))text=L"Signed space index; negative values retain their sentinel meaning.";
 if(!xx_rt_wcscmp(r->name,L"initialization_pattern"))text=L"Repeated 32-bit initialization bit pattern for the subspace; not a file offset.";
 if(!xx_rt_wcscmp(r->name,L"subspace_start"))text=L"Virtual byte address relative to the start of the owning space.";
 if(!xx_rt_wcscmp(r->name,L"alignment_and_reserved"))text=L"Packed alignment/reserved word retained without splitting: HP structure diagram specifies 5/27 bits while descriptive text gives 16/16.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset in the space string table.";
 if(!xx_rt_wcscmp(r->name,L"fixup_request_index"))text=L"Signed index of the first fixup; negative values denote no index.";
 break;
 case 0x602b0058U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset in the symbol string table.";
 if(!xx_rt_wcscmp(r->name,L"qualifier_name_offset"))text=L"Byte offset in the symbol string table.";
 break;
 case 0x602b005aU:
 if(!xx_rt_wcscmp(r->name,L"text_alignment_shift"))text=L"Power-of-two alignment exponent.";
 if(!xx_rt_wcscmp(r->name,L"data_alignment_shift"))text=L"Power-of-two alignment exponent.";
 if(!xx_rt_wcscmp(r->name,L"text_page_size"))text=L"Encoded page-size request; preserved without conversion.";
 if(!xx_rt_wcscmp(r->name,L"data_page_size"))text=L"Encoded page-size request; preserved without conversion.";
 if(!xx_rt_wcscmp(r->name,L"stack_page_size"))text=L"Encoded page-size request; preserved without conversion.";
 break;
 case 0x602b005cU:
 if(!xx_rt_wcscmp(r->name,L"import_files_offset"))text=L"Relative to the loader section.";
 if(!xx_rt_wcscmp(r->name,L"strings_offset"))text=L"Relative to the loader section.";
 break;
 case 0x602b005dU:
 case 0x602b005eU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the loader string table.";
 if(!xx_rt_wcscmp(r->name,L"parameter_type_offset"))text=L"Byte offset from the loader string table to the parameter type-check string (after its length field); zero means absent.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXEXM_LIMIT 20000U
static bool sxexm_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxexm_read(sx_context *c,uint64_t p,void *b,size_t n){return sxexm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxexm_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint16_t sxexm16(const uint8_t *b,bool be){return (uint16_t)sxexm_uint(b,2,be);}
static uint32_t sxexm32(const uint8_t *b,bool be){return (uint32_t)sxexm_uint(b,4,be);}
/* Native readers can authenticate aliases and damaged optional records. Keep
 * earlier bounded physical metadata, and leave conflicting later interpretations
 * opaque instead of discarding the entire useful header view. */
static bool sxexm_free(sx_context *c,uint64_t p,uint64_t n){for(size_t i=0;i<c->count;i++){uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<at+z&&at<p+n)return false;}return true;}
static bool sxexm_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(!sxexm_span(c,p,n))return false;if(!sxexm_free(c,p,n))return true;return c->count>=SXEXM_LIMIT||sx_add(c,l,(int64_t)p,(int64_t)n);}
static bool sxexm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n||n>SXEXM_LIMIT||!sxexm_span(c,p,n*z))return true;if(!sxexm_free(c,p,n*z))return true;return c->count>=SXEXM_LIMIT||sx_table(c,l,(int64_t)p,(int64_t)z,n);}
static bool sxexm_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v){uint8_t b[8];if(n>8||!sxexm_read(c,p,b,n))return false;*v=sxexm_uint(b,n,be);return true;}
static bool sxexm_msf_word(sx_context *c,uint64_t map,uint64_t bs,uint64_t bytes,uint64_t logical,const sx_layout *l,uint64_t *value){uint64_t id;if(logical>bytes||bytes-logical<4||logical%4||!sxexm_word(c,map+(logical/bs)*4,4,false,&id)||id>(uint64_t)c->size/bs)return false;uint64_t p=id*bs+logical%bs;return sxexm_word(c,p,4,false,value)&&sxexm_add(c,l,p);}
static bool sxexm_msf(sx_context *c){uint8_t b[56];if(!sxexm_read(c,0,b,56)||!sxexm_add(c,&sxexm_msf7_superblock,0))return false;uint64_t bs=sxexm32(b+32,false),dn=sxexm32(b+44,false),map=sxexm32(b+52,false);if((bs!=512&&bs!=1024&&bs!=2048&&bs!=4096)||dn<4||dn>4194304||map>(uint64_t)c->size/bs)return true;map*=bs;uint64_t pages=(dn+bs-1)/bs;if(pages*4>bs||!sxexm_span(c,map,pages*4)||!sxexm_table(c,&sxexm_msf7_directory_block,map,pages))return true;uint64_t count;if(!sxexm_msf_word(c,map,bs,dn,0,&sxexm_msf7_stream_count,&count)||count>4093||count*4+4>dn)return true;uint64_t at=4+count*4;
 for(uint64_t i=0;i<count&&c->count<SXEXM_LIMIT;i++){uint64_t z;if(!sxexm_msf_word(c,map,bs,dn,4+i*4,&sxexm_msf7_stream_size,&z))break;if(z==UINT32_MAX)continue;uint64_t n=(z+bs-1)/bs;if(n>(dn-at)/4)break;for(uint64_t j=0;j<n&&c->count<SXEXM_LIMIT;j++){uint64_t id;if(!sxexm_msf_word(c,map,bs,dn,at,&sxexm_msf7_stream_block,&id))return true;at+=4;}if(c->count>=SXEXM_LIMIT)break;}return true;}
static bool sxexm_resource(sx_context *c){uint8_t h[28];if(!sxexm_read(c,0,h,16)||!sxexm_add(c,&sxexm_resource_fork_header,0))return false;uint64_t data=sxexm32(h,true),map=sxexm32(h+4,true),ds=sxexm32(h+8,true),ms=sxexm32(h+12,true);if(ms<28||!sxexm_span(c,map,ms)||!sxexm_span(c,data,ds)||!sxexm_read(c,map,h,28))return true;if(!sxexm_add(c,&sxexm_resource_map_header,map))return false;uint64_t t=sxexm16(h+24,true),names=sxexm16(h+26,true),count;if(t>ms||ms-t<2||!sxexm_word(c,map+t,2,true,&count))return true;if(!sxexm_add(c,&sxexm_resource_type_count,map+t))return false;count=count==65535?0:count+1;if(count>SXEXM_LIMIT||count>(ms-t-2)/8)return true;if(!sxexm_table(c,&sxexm_resource_type_entry,map+t+2,count))return false;
 for(uint64_t i=0;i<count&&c->count<SXEXM_LIMIT;i++){if(!sxexm_read(c,map+t+2+i*8,h,8))break;uint64_t n=(uint64_t)sxexm16(h+4,true)+1,p=t+sxexm16(h+6,true);if(n>SXEXM_LIMIT||p>ms||n>(ms-p)/12)continue;if(!sxexm_table(c,&sxexm_resource_reference,map+p,n))return false;for(uint64_t j=0;j<n&&c->count<SXEXM_LIMIT;j++){if(!sxexm_read(c,map+p+j*12,h,12))break;uint64_t off=sxexm_uint(h+5,3,true),name=sxexm16(h+2,true),z;if(off<=ds&&ds-off>=4&&sxexm_word(c,data+off,4,true,&z)&&z<=ds-off-4&&!sxexm_add(c,&sxexm_resource_data_length,data+off))return false;if(name!=65535&&names<=ms&&name<ms-names&&sxexm_word(c,map+names+name,1,true,&z)&&z<ms-names-name&&!sxexm_add(c,&sxexm_resource_name_length,map+names+name))return false;}}return true;}
static bool sxexm_xbe(sx_context*c){uint8_t b[376];if(!sxexm_read(c,0,b,sizeof(b))||!sxexm_add(c,&sxexm_xbe_header,0))return false;uint64_t base=sxexm32(b+260,false),heads=sxexm32(b+264,false),cert=sxexm32(b+280,false),n=sxexm32(b+284,false),table=sxexm32(b+288,false);if(table>=base&&table-base<=heads&&n<=SXEXM_LIMIT&&n<=(heads-(table-base))/56&&!sxexm_table(c,&sxexm_xbe_section,table-base,n))return false;if(cert>=base&&cert-base<=heads&&heads-(cert-base)>=464){uint64_t z;if(sxexm_word(c,cert-base,4,false,&z)&&z>=464&&z<=heads-(cert-base)&&!sxexm_add(c,&sxexm_xbe_certificate,cert-base))return false;}return true;}
static bool sxexm_pyc(sx_context*c){uint8_t h[8];if(!sxexm_read(c,0,h,8))return false;uint64_t magic=sxexm16(h,false);/* Historical Python 1/2 magics are above 5000; modern Python3 magics are 3000..4999. */unsigned size=magic>=3000&&magic<5000?(magic>=3392?16:magic>=3210?12:8):8;const sx_layout*l=size==8?&sxexm_pyc_header8:size==12?&sxexm_pyc_header12:(sxexm32(h+4,false)&1)?&sxexm_pyc_header16_hash:&sxexm_pyc_header16_timestamp;return sxexm_add(c,l,0);}
static bool sxexm_mub(sx_context*c){uint8_t h[8];if(!sxexm_read(c,0,h,8))return false;uint32_t magic=sxexm32(h,true);bool be=magic!=0xb9faf10eU,fat64=magic==0xcafebabfU;if(magic!=0xcafebabeU&&magic!=0xcafebabfU&&magic!=0xb9faf10eU)return false;uint64_t n=sxexm32(h+4,be);return sxexm_add(c,be?&sxexm_mub_header_be:&sxexm_mub_header_le,0)&&sxexm_table(c,fat64?&sxexm_mub_arch64_be:be?&sxexm_mub_arch32_be:&sxexm_mub_arch32_le,8,n);}
static bool sxexm_nro(sx_context*c){uint8_t h[128],asset[4];if(!sxexm_read(c,0,h,128)||!sxexm_add(c,&sxexm_nro_start,0)||!sxexm_add(c,&sxexm_nro_header,16))return false;uint64_t p=sxexm32(h+24,false);if(sxexm_span(c,p,56)&&sxexm_read(c,p,asset,4)&&!xx_rt_memcmp(asset,"ASET",4)&&!sxexm_add(c,&sxexm_nro_asset_header,p))return false;return true;}
static bool sxexm_cgc(sx_context*c){uint8_t h[52];if(!sxexm_read(c,0,h,52))return false;bool be=h[5]==2;if(!sxexm_add(c,be?&sxexm_cgc_header_be:&sxexm_cgc_header_le,0))return false;for(unsigned t=0;t<2;t++){uint64_t p=sxexm32(h+(t?32:28),be),stride=sxexm16(h+(t?46:42),be),n=sxexm16(h+(t?48:44),be),minimum=t?40:32;if(n>SXEXM_LIMIT||stride<minimum||!sxexm_span(c,p,n*stride))continue;const sx_layout*l=t?(be?&sxexm_cgc_section_header_be:&sxexm_cgc_section_header_le):(be?&sxexm_cgc_program_header_be:&sxexm_cgc_program_header_le);for(uint64_t i=0;i<n&&c->count<SXEXM_LIMIT;i++)if(!sxexm_add(c,l,p+i*stride))return false;}return true;}
static bool sxexm_rel(sx_context*c){uint8_t h[64];if(!sxexm_read(c,0,h,64)||!sxexm_add(c,&sxexm_rel_header,0))return false;uint64_t v=sxexm32(h+28,true),p=sxexm32(h+40,true),n=sxexm32(h+44,true)/8;if(!sxexm_table(c,&sxexm_rel_section,sxexm32(h+16,true),sxexm32(h+12,true))||!sxexm_table(c,&sxexm_rel_import,p,n))return false;if((v==2||v==3)&&sxexm_span(c,64,v==2?8:12)&&!sxexm_add(c,v==2?&sxexm_rel_v2_extension:&sxexm_rel_v3_extension,64))return false;if(n>SXEXM_LIMIT||!sxexm_span(c,p,n*8))return true;for(uint64_t i=0;i<n&&c->count<SXEXM_LIMIT;i++){uint64_t q;if(!sxexm_word(c,p+i*8+4,4,true,&q)||!q)continue;for(unsigned j=0;j<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;j++,q+=8){uint8_t r[8];if(!sxexm_read(c,q,r,8)||!sxexm_free(c,q,8))break;if(!sxexm_add(c,&sxexm_rel_relocation,q))return false;if(r[2]==203)break;}}return true;}
static bool sxexm_xtac(sx_context*c){uint8_t h[56],b[16];if(!sxexm_read(c,0,h,56)||!sxexm_add(c,&sxexm_xtac_header,0)||!sxexm_table(c,&sxexm_xtac_address_pair,sxexm32(h+12,false),sxexm32(h+16,false)))return false;uint64_t p=sxexm32(h+36,false);for(unsigned i=0;p&&i<20;i++){if(!sxexm_read(c,p,b,16)||xx_rt_memcmp(b,"BLCK",4)||!sxexm_free(c,p,16))break;if(!sxexm_add(c,&sxexm_xtac_block_stub,p))return false;p=sxexm32(b+8,false);}p=sxexm32(h+48,false);for(unsigned i=0;p&&i<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;i++){uint64_t v;if(!sxexm_word(c,p,4,false,&v))break;unsigned k=(unsigned)(v>>28)&3,z=4+((k&1)?4:0)+((k&2)?4:0);const sx_layout*ls[]={&sxexm_xtac_linked_entry0,&sxexm_xtac_linked_entry1,&sxexm_xtac_linked_entry2,&sxexm_xtac_linked_entry3};if(!sxexm_span(c,p,z)||!sxexm_free(c,p,z))break;if(!sxexm_add(c,ls[k],p))return false;uint64_t step=v&0x0fffffff;if(!step||step==0x0fffffff)break;p+=step*4;}return true;}
static bool sxexm_qnx(sx_context*c){uint64_t p=0;uint8_t h[6];for(unsigned i=0;i<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;i++){if(!sxexm_read(c,p,h,6))break;uint64_t z=sxexm16(h+2,false);unsigned type=h[0];if(type>8||!sxexm_span(c,p+6,z))break;if(!sxexm_add(c,&sxexm_qnx_record_header,p))return false;const sx_layout*l=NULL;if(type==0&&z>=48){l=&sxexm_qnx_module_header;if(!sxexm_table(c,&sxexm_qnx_segment,p+54,(z-48)/4))return false;}else if(type==2||type==3||type==4||type==8){if(z>=6)l=&sxexm_qnx_load_header;}else if(type==6&&z>=8)l=&sxexm_qnx_resource_header;else if(type==7&&z>=6)l=&sxexm_qnx_read_write_end;else if(type==5&&z>=6)l=&sxexm_qnx_image_end;if(l&&!sxexm_add(c,l,p+6))return false;p+=6+z;if(type==5)break;}return c->count!=0;}
static bool sxexm_omf(sx_context*c){uint8_t h[3];uint64_t p=0;for(unsigned i=0;i<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;i++){if(!sxexm_read(c,p,h,3))break;uint64_t z=sxexm16(h+1,false);if(!z||!sxexm_span(c,p+3,z))break;if(!sxexm_add(c,&sxexm_omf_record_header,p)||!sxexm_add(c,&sxexm_omf_checksum,p+2+z))return false;if(h[0]==0x80||h[0]==0x82||h[0]==0x96){uint64_t q=p+3,end=p+2+z;while(q<end&&c->count<SXEXM_LIMIT){uint64_t n;if(!sxexm_word(c,q,1,false,&n)||n>=end-q)break;if(!sxexm_add(c,&sxexm_omf_name_length,q))return false;q+=1+n;if(h[0]!=0x96)break;}}p+=3+z;}return c->count!=0;}
static bool sxexm_dos(sx_context*c){uint8_t h[64];if(!sxexm_read(c,0,h,64)||!sxexm_add(c,&sxexm_dos_extender_mz,0))return false;uint64_t pages=sxexm16(h+4,false);if(!pages)return true;uint64_t p=(pages-1)*512+sxexm16(h+2,false);for(unsigned i=0;i<SXEXM_LIMIT&&c->count<SXEXM_LIMIT;i++){if(!sxexm_read(c,p,h,2))break;if(!xx_rt_memcmp(h,"BW",2)){uint64_t next;if(!sxexm_span(c,p,176)||!sxexm_word(c,p+28,4,false,&next))break;if(!sxexm_add(c,&sxexm_dos16m_bw_header,p))return false;if(next<=p)break;p=next;}else if(!xx_rt_memcmp(h,"MF",2)){uint64_t z;if(!sxexm_word(c,p+2,4,false,&z)||z<6||!sxexm_span(c,p,z))break;if(!sxexm_add(c,&sxexm_dos16m_mf_header,p))return false;p+=z;}else if(!xx_rt_memcmp(h,"MZ",2)){if(sxexm_span(c,p,64)&&!sxexm_add(c,&sxexm_dos_extender_mz,p))return false;break;}else break;}return true;}
static bool sxexm_hunk_counted(sx_context*c,uint64_t*p,const sx_layout*l,bool skip){uint64_t n;if(!sxexm_word(c,*p,4,true,&n)||!sxexm_add(c,l,*p))return false;*p+=4;if(skip){if(n>UINT32_MAX/4||!sxexm_span(c,*p,n*4))return false;*p+=n*4;}return true;}
static bool sxexm_hunk(sx_context*c){uint64_t p=0;unsigned budget=0;while(sxexm_span(c,p,4)&&budget++<SXEXM_LIMIT&&c->count<SXEXM_LIMIT){uint64_t start=p,v;if(!sxexm_word(c,p,4,true,&v))break;unsigned id=(unsigned)v&0x3fffffff;size_t old=c->count;if(!sxexm_add(c,&sxexm_amiga_hunk_tag,p))return false;p+=4;bool ok=true;
 if(id==0x3f3){for(;;){uint64_t n;if(++budget>SXEXM_LIMIT||!sxexm_word(c,p,4,true,&n)){ok=false;break;}if(!sxexm_hunk_counted(c,&p,&sxexm_amiga_hunk_length,true)){ok=false;break;}if(!n)break;}uint8_t b[12];if(!ok||!sxexm_read(c,p,b,12)){ok=false;}else{uint64_t first=sxexm32(b+4,true),last=sxexm32(b+8,true);if(last<first||last-first>=SXEXM_LIMIT)ok=false;else{ok=sxexm_add(c,&sxexm_amiga_hunk_table,p);p+=12;for(uint64_t i=first;ok&&i<=last;i++){if(++budget>=SXEXM_LIMIT){ok=false;break;}uint64_t n;if(!sxexm_word(c,p,4,true,&n)||!sxexm_add(c,&sxexm_amiga_hunk_allocation,p)){ok=false;break;}p+=4;if((n>>30)==3){ok=sxexm_add(c,&sxexm_amiga_memory_flags,p);p+=4;}}}}}
 else if(id==0x3e7||id==0x3e8||id==0x3e9||id==0x3ea||id==0x3f1||id==0x4e9)ok=sxexm_hunk_counted(c,&p,&sxexm_amiga_hunk_length,true);
 else if(id==0x3eb)ok=sxexm_hunk_counted(c,&p,&sxexm_amiga_hunk_length,false);
 else if(id==0x3ec||id==0x3ed||id==0x3ee||id==0x3f7||id==0x3f8||id==0x3f9||id==0x3fc||id==0x3ff){unsigned width=(id==0x3fc||id==0x3ff)?2:4;const sx_layout*count=width==2?&sxexm_amiga_relocation_count16:&sxexm_amiga_relocation_count32,*target=width==2?&sxexm_amiga_relocation_target16:&sxexm_amiga_relocation_target32,*offset=width==2?&sxexm_amiga_relocation_offset16:&sxexm_amiga_relocation_offset32;for(;;){uint64_t n;if(++budget>SXEXM_LIMIT||!sxexm_word(c,p,width,true,&n)||!sxexm_add(c,count,p)){ok=false;break;}p+=width;if(!n){if(width==2)p=start+((p-start+3)&~UINT64_C(3));break;}if(n>SXEXM_LIMIT||!sxexm_span(c,p,(n+1)*width)||!sxexm_add(c,target,p)||!sxexm_table(c,offset,p+width,n)){ok=false;break;}p+=(n+1)*width;}}
 else if(id==0x3f0||id==0x3ef){for(;;){uint64_t n;if(++budget>SXEXM_LIMIT||!sxexm_word(c,p,4,true,&n)){ok=false;break;}if(!sxexm_add(c,id==0x3ef?&sxexm_amiga_ext_name:&sxexm_amiga_hunk_length,p)){ok=false;break;}p+=4;if(!n)break;unsigned type=id==0x3ef?(unsigned)(n>>24):0;n=id==0x3ef?n&0xffffff:n;if(n>UINT32_MAX/4||!sxexm_span(c,p,n*4)){ok=false;break;}p+=n*4;if(type<=3){ok=sxexm_add(c,&sxexm_amiga_symbol_value,p);p+=4;}else if(type>=128){if(type==130){ok=sxexm_add(c,&sxexm_amiga_common_size,p);p+=4;}uint64_t refs;if(!ok||!sxexm_word(c,p,4,true,&refs)||refs>SXEXM_LIMIT||!sxexm_span(c,p+4,refs*4)){ok=false;break;}ok=sxexm_add(c,&sxexm_amiga_relocation_count32,p)&&sxexm_table(c,&sxexm_amiga_relocation_offset32,p+4,refs);p+=4+refs*4;}else ok=false;if(!ok)break;}}
 else if(id!=0x3f2)ok=false;if(!ok||p>(uint64_t)c->size){c->count=old;break;}if(p<=start)break;}return c->count!=0;}
static bool sxexm_som(sx_context*c){uint8_t b[128];if(!sxexm_read(c,0,b,128)||!sxexm_add(c,&sxexm_som_header,0))return false;if(!sxexm_table(c,&sxexm_som_space,sxexm32(b+44,true),sxexm32(b+48,true))||!sxexm_table(c,&sxexm_som_symbol,sxexm32(b+92,true),sxexm32(b+96,true)))return false;uint64_t p=sxexm32(b+52,true),n=sxexm32(b+56,true);if(n>SXEXM_LIMIT||!sxexm_span(c,p,n*40))return true;for(uint64_t i=0;i<n&&c->count<SXEXM_LIMIT;i++){uint64_t z;if(!sxexm_word(c,p+i*40+12,4,true,&z))break;if(!sxexm_add(c,z?&sxexm_som_subspace_initialized:&sxexm_som_subspace_pattern,p+i*40))return false;}return true;}
static bool sxexm_xcoff(sx_context*c){uint8_t h[92],s[40],b[32];if(!sxexm_read(c,0,h,92)||!sxexm_add(c,&sxexm_xcoff32_file_header,0)||!sxexm_add(c,&sxexm_xcoff32_optional_header,20))return false;uint64_t n=sxexm16(h+2,true),loader=sxexm16(h+60,true);if(!sxexm_table(c,&sxexm_xcoff32_section,92,n))return false;if(!loader||loader>n||!sxexm_read(c,92+(loader-1)*40,s,40))return true;uint64_t p=sxexm32(s+20,true),z=sxexm32(s+16,true);if(z<32||!sxexm_span(c,p,z)||!sxexm_read(c,p,b,32)||!sxexm_add(c,&sxexm_xcoff32_loader,p))return true;uint64_t count=sxexm32(b+4,true);if(count>SXEXM_LIMIT||count>(z-32)/24)return true;for(uint64_t i=0;i<count&&c->count<SXEXM_LIMIT;i++){uint64_t name;if(!sxexm_word(c,p+32+i*24,4,true,&name))break;if(!sxexm_add(c,name?&sxexm_xcoff32_loader_symbol_inline:&sxexm_xcoff32_loader_symbol_external,p+32+i*24))return false;}return true;}
static int sxexm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxexm_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxexm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxexm_order);return !c->failed;}
static bool sx_executablemore_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_AMIGAHUNK:case XX_FILE_TYPE_DOS16M:case XX_FILE_TYPE_DOS4G:case XX_FILE_TYPE_RESOURCEFORK:case XX_FILE_TYPE_XBOX_XBE:case XX_FILE_TYPE_MICROSOFT_MSF:case XX_FILE_TYPE_PYC:case XX_FILE_TYPE_VTECH_VZ:case XX_FILE_TYPE_XAMARIN_COMPRESSED_ASSEMBLY:case XX_FILE_TYPE_MUB:case XX_FILE_TYPE_CGC:case XX_FILE_TYPE_NINTENDO_NRO:case XX_FILE_TYPE_NINTENDO_NSO:case XX_FILE_TYPE_WINDOWS_DMP64:case XX_FILE_TYPE_OMF:case XX_FILE_TYPE_XTAC:case XX_FILE_TYPE_PEBBLE:case XX_FILE_TYPE_HP_SOM:case XX_FILE_TYPE_QNX_LMF:case XX_FILE_TYPE_NINTENDO_REL:case XX_FILE_TYPE_XCOFF:return true;default:return false;}}
static bool sx_executablemore_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;uint64_t p,n;switch(c->f->file_type){
case XX_FILE_TYPE_AMIGAHUNK:ok=sxexm_hunk(c);break;
case XX_FILE_TYPE_DOS16M:ok=sxexm_dos(c);break;
case XX_FILE_TYPE_DOS4G:ok=sxexm_dos(c);break;
case XX_FILE_TYPE_RESOURCEFORK:ok=sxexm_resource(c);break;
case XX_FILE_TYPE_XBOX_XBE:ok=sxexm_xbe(c);break;
case XX_FILE_TYPE_MICROSOFT_MSF:ok=sxexm_msf(c);break;
case XX_FILE_TYPE_PYC:ok=sxexm_pyc(c);break;
case XX_FILE_TYPE_VTECH_VZ:ok=sxexm_add(c,&sxexm_vz_header,0);break;
case XX_FILE_TYPE_XAMARIN_COMPRESSED_ASSEMBLY:ok=sxexm_add(c,&sxexm_xalz_header,0);break;
case XX_FILE_TYPE_MUB:ok=sxexm_mub(c);break;
case XX_FILE_TYPE_CGC:ok=sxexm_cgc(c);break;
case XX_FILE_TYPE_NINTENDO_NRO:ok=sxexm_nro(c);break;
case XX_FILE_TYPE_NINTENDO_NSO:ok=sxexm_add(c,&sxexm_nso_header,0);break;
case XX_FILE_TYPE_WINDOWS_DMP64:ok=sxexm_add(c,&sxexm_dmp64_prefix,0)&&sxexm_add(c,&sxexm_dmp64_type,0xf98)&&sxexm_add(c,&sxexm_dmp64_required_space,0xfa0)&&sxexm_add(c,&sxexm_dmp64_product,0x103c)&&sxexm_add(c,&sxexm_dmp64_bitmap_header,8192);break;
case XX_FILE_TYPE_OMF:ok=sxexm_omf(c);break;
case XX_FILE_TYPE_XTAC:ok=sxexm_xtac(c);break;
case XX_FILE_TYPE_PEBBLE:ok=sxexm_add(c,&sxexm_pebble_header,0)&&sxexm_word(c,14,2,false,&p)&&sxexm_word(c,100,4,false,&n)&&sxexm_table(c,&sxexm_pebble_relocation,p,n);break;
case XX_FILE_TYPE_HP_SOM:ok=sxexm_som(c);break;
case XX_FILE_TYPE_QNX_LMF:ok=sxexm_qnx(c);break;
case XX_FILE_TYPE_NINTENDO_REL:ok=sxexm_rel(c);break;
case XX_FILE_TYPE_XCOFF:ok=sxexm_xcoff(c);break;
default:break;}return ok&&sxexm_finish(c);}
