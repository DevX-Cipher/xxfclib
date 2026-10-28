/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical installer and self-extractor metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_installerlast_scope.txt. */

static const xx_data_struct_field_desc sxil_installerlast_name_fields[] = {
    SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxil_installerlast_name = {0x60850001U,"installerlast_name",sxil_installerlast_name_fields,SX_COUNT(sxil_installerlast_name_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installerlast_utf16_name_fields[] = {
    SX_FIELD("name","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installerlast_utf16_name = {0x60850002U,"installerlast_utf16_name",sxil_installerlast_utf16_name_fields,SX_COUNT(sxil_installerlast_utf16_name_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installerlast_encoded_bytes_fields[] = {
    SX_FIELD("encoded_bytes","uint8",0,0,SX_NONE),
};
static const sx_layout sxil_installerlast_encoded_bytes = {0x60850003U,"installerlast_encoded_bytes",sxil_installerlast_encoded_bytes_fields,SX_COUNT(sxil_installerlast_encoded_bytes_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installerlast_decimal_size_fields[] = {
    SX_FIELD("file_size","ascii_decimal",0,0,SX_SIZE),
};
static const sx_layout sxil_installerlast_decimal_size = {0x60850004U,"installerlast_decimal_size",sxil_installerlast_decimal_size_fields,SX_COUNT(sxil_installerlast_decimal_size_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installerlast_utf16_size_fields[] = {
    SX_FIELD("file_size_text","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installerlast_utf16_size = {0x60850005U,"installerlast_utf16_size",sxil_installerlast_utf16_size_fields,SX_COUNT(sxil_installerlast_utf16_size_fields),SX_LE};

static const xx_data_struct_field_desc sxil_advanced_installer_footer_fields[] = {
    SX_FIELD("mode","uint32",0,4,SX_ID),
    SX_FIELD("external_name_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("file_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("version","uint32",12,4,SX_ID),
    SX_FIELD("metadata_end","uint32",16,4,SX_OFFSET),
    SX_FIELD("info_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("guid_hex","char[32]",28,32,SX_NONE),
    SX_FIELD("unknown","uint32",60,4,SX_NONE),
    SX_FIELD("marker","char[10]",64,10,SX_SIGNATURE),
};
static const sx_layout sxil_advanced_installer_footer = {0x60850006U,"advanced_installer_footer",sxil_advanced_installer_footer_fields,SX_COUNT(sxil_advanced_installer_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxil_advanced_installer_record_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("index","uint32",4,4,SX_NONE),
    SX_FIELD("xor_flag","uint32",8,4,SX_FLAGS),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("file_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("name_length","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxil_advanced_installer_record = {0x60850007U,"advanced_installer_record",sxil_advanced_installer_record_fields,SX_COUNT(sxil_advanced_installer_record_fields),SX_LE};

static const xx_data_struct_field_desc sxil_advanced_installer_external_fields[] = {
    SX_FIELD("reserved","uint32",0,4,SX_RESERVED),
    SX_FIELD("name_length","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxil_advanced_installer_external = {0x60850008U,"advanced_installer_external",sxil_advanced_installer_external_fields,SX_COUNT(sxil_advanced_installer_external_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ardi_trailer_fields[] = {
    SX_FIELD("copyright","char[25]",0,25,SX_NONE),
    SX_FIELD("builder_check","uint32",25,4,SX_NONE),
    SX_FIELD("builder_counter","uint16",29,2,SX_NONE),
    SX_FIELD("copyright_suffix","char[14]",31,14,SX_NONE),
    SX_FIELD("year","char[4]",45,4,SX_NONE),
    SX_FIELD("terminator","char[1]",49,1,SX_NONE),
};
static const sx_layout sxil_ardi_trailer = {0x60850009U,"ardi_trailer",sxil_ardi_trailer_fields,SX_COUNT(sxil_ardi_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ardi_block_tag_fields[] = {
    SX_FIELD("tag","uint32",0,4,SX_ID),
};
static const sx_layout sxil_ardi_block_tag = {0x6085000aU,"ardi_block_tag",sxil_ardi_block_tag_fields,SX_COUNT(sxil_ardi_block_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ardi_block_length_fields[] = {
    SX_FIELD("block_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxil_ardi_block_length = {0x6085000bU,"ardi_block_length",sxil_ardi_block_length_fields,SX_COUNT(sxil_ardi_block_length_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ardi_member_time_fields[] = {
    SX_FIELD("modification_time","uint32",0,4,SX_TIME),
};
static const sx_layout sxil_ardi_member_time = {0x6085000cU,"ardi_member_time",sxil_ardi_member_time_fields,SX_COUNT(sxil_ardi_member_time_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ardi_chain_start_fields[] = {
    SX_FIELD("sentinel","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxil_ardi_chain_start = {0x6085000dU,"ardi_chain_start",sxil_ardi_chain_start_fields,SX_COUNT(sxil_ardi_chain_start_fields),SX_LE};

static const xx_data_struct_field_desc sxil_arni_member_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxil_arni_member = {0x6085000eU,"arni_member",sxil_arni_member_fields,SX_COUNT(sxil_arni_member_fields),SX_LE};

static const xx_data_struct_field_desc sxil_arni_end_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("terminator","byte[2]",8,2,SX_NONE),
};
static const sx_layout sxil_arni_end = {0x6085000fU,"arni_end",sxil_arni_end_fields,SX_COUNT(sxil_arni_end_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ej_technologies_header_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("variable_count","int32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxil_ej_technologies_header = {0x60850010U,"ej_technologies_header",sxil_ej_technologies_header_fields,SX_COUNT(sxil_ej_technologies_header_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ej_technologies_variable_fields[] = {
    SX_FIELD("key","int32",0,4,SX_ID),
    SX_FIELD("value_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxil_ej_technologies_variable = {0x60850011U,"ej_technologies_variable",sxil_ej_technologies_variable_fields,SX_COUNT(sxil_ej_technologies_variable_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ej_technologies_extra_count_fields[] = {
    SX_FIELD("extra_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxil_ej_technologies_extra_count = {0x60850012U,"ej_technologies_extra_count",sxil_ej_technologies_extra_count_fields,SX_COUNT(sxil_ej_technologies_extra_count_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ej_technologies_member_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxil_ej_technologies_member = {0x60850013U,"ej_technologies_member",sxil_ej_technologies_member_fields,SX_COUNT(sxil_ej_technologies_member_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ej_technologies_member_later_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
static const sx_layout sxil_ej_technologies_member_later = {0x60850014U,"ej_technologies_member_later",sxil_ej_technologies_member_later_fields,SX_COUNT(sxil_ej_technologies_member_later_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ej_technologies_trailer_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("member_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxil_ej_technologies_trailer = {0x60850015U,"ej_technologies_trailer",sxil_ej_technologies_trailer_fields,SX_COUNT(sxil_ej_technologies_trailer_fields),SX_BE};

static const xx_data_struct_field_desc sxil_ej_technologies_trailer_name_fields[] = {
    SX_FIELD("name_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxil_ej_technologies_trailer_name = {0x60850016U,"ej_technologies_trailer_name",sxil_ej_technologies_trailer_name_fields,SX_COUNT(sxil_ej_technologies_trailer_name_fields),SX_BE};

static const xx_data_struct_field_desc sxil_ej_technologies_trailer_size_fields[] = {
    SX_FIELD("file_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxil_ej_technologies_trailer_size = {0x60850017U,"ej_technologies_trailer_size",sxil_ej_technologies_trailer_size_fields,SX_COUNT(sxil_ej_technologies_trailer_size_fields),SX_BE};

static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_header_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("version","uint16",6,2,SX_ID),
};
static const sx_layout sxil_ibm_zpak_sfx_header = {0x60850018U,"ibm_zpak_sfx_header",sxil_ibm_zpak_sfx_header_fields,SX_COUNT(sxil_ibm_zpak_sfx_header_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_v1_directory_fields[] = {
    SX_FIELD("name","char[102]",0,102,SX_NONE),
    SX_FIELD("packed_size","int32",102,4,SX_SIZE),
    SX_FIELD("reserved","uint32",106,4,SX_RESERVED),
    SX_FIELD("dos_date","uint16",110,2,SX_NONE),
    SX_FIELD("dos_time","uint16",112,2,SX_NONE),
};
static const sx_layout sxil_ibm_zpak_sfx_v1_directory = {0x60850019U,"ibm_zpak_sfx_v1_directory",sxil_ibm_zpak_sfx_v1_directory_fields,SX_COUNT(sxil_ibm_zpak_sfx_v1_directory_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_v2_record_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("unused","uint8",1,1,SX_NONE),
    SX_FIELD("packed_size","int32",2,4,SX_SIZE),
    SX_FIELD("writer_scratch","byte[4]",6,4,SX_NONE),
    SX_FIELD("dos_date","uint16",10,2,SX_NONE),
    SX_FIELD("dos_time","uint16",12,2,SX_NONE),
    SX_FIELD("name_size","int16",14,2,SX_SIZE),
};
static const sx_layout sxil_ibm_zpak_sfx_v2_record = {0x6085001aU,"ibm_zpak_sfx_v2_record",sxil_ibm_zpak_sfx_v2_record_fields,SX_COUNT(sxil_ibm_zpak_sfx_v2_record_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_v1_trailer_fields[] = {
    SX_FIELD("file_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("header_offset","uint32",2,4,SX_OFFSET),
    SX_FIELD("declared_file_size","uint32",6,4,SX_SIZE),
    SX_FIELD("product_tag","char[12]",10,12,SX_NONE),
};
static const sx_layout sxil_ibm_zpak_sfx_v1_trailer = {0x6085001bU,"ibm_zpak_sfx_v1_trailer",sxil_ibm_zpak_sfx_v1_trailer_fields,SX_COUNT(sxil_ibm_zpak_sfx_v1_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ibm_zpak_sfx_v2_trailer_fields[] = {
    SX_FIELD("file_count","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("header_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("adjusted_file_size","uint32",8,4,SX_NONE),
    SX_FIELD("product_tag","char[26]",12,26,SX_NONE),
};
static const sx_layout sxil_ibm_zpak_sfx_v2_trailer = {0x6085001cU,"ibm_zpak_sfx_v2_trailer",sxil_ibm_zpak_sfx_v2_trailer_fields,SX_COUNT(sxil_ibm_zpak_sfx_v2_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installerlast_dcl_prelude_fields[] = {
    SX_FIELD("literal_mode","uint8",0,1,SX_ID),
    SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxil_installerlast_dcl_prelude = {0x6085001dU,"installerlast_dcl_prelude",sxil_installerlast_dcl_prelude_fields,SX_COUNT(sxil_installerlast_dcl_prelude_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield12_count_fields[] = {
    SX_FIELD("file_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxil_installshield12_count = {0x6085001eU,"installshield12_count",sxil_installshield12_count_fields,SX_COUNT(sxil_installshield12_count_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_ansi_base_name_fields[] = {
    SX_FIELD("base_name","char",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_ansi_base_name = {0x6085001fU,"installshield_ansi_base_name",sxil_installshield_ansi_base_name_fields,SX_COUNT(sxil_installshield_ansi_base_name_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_utf16_base_name_fields[] = {
    SX_FIELD("base_name","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_utf16_base_name = {0x60850020U,"installshield_utf16_base_name",sxil_installshield_utf16_base_name_fields,SX_COUNT(sxil_installshield_utf16_base_name_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_ansi_relative_path_fields[] = {
    SX_FIELD("relative_path","char",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_ansi_relative_path = {0x60850021U,"installshield_ansi_relative_path",sxil_installshield_ansi_relative_path_fields,SX_COUNT(sxil_installshield_ansi_relative_path_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_utf16_relative_path_fields[] = {
    SX_FIELD("relative_path","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_utf16_relative_path = {0x60850022U,"installshield_utf16_relative_path",sxil_installshield_utf16_relative_path_fields,SX_COUNT(sxil_installshield_utf16_relative_path_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_ansi_version_fields[] = {
    SX_FIELD("version","char",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_ansi_version = {0x60850023U,"installshield_ansi_version",sxil_installshield_ansi_version_fields,SX_COUNT(sxil_installshield_ansi_version_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_utf16_version_fields[] = {
    SX_FIELD("version","uint16",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_utf16_version = {0x60850024U,"installshield_utf16_version",sxil_installshield_utf16_version_fields,SX_COUNT(sxil_installshield_utf16_version_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield3_descriptor_fields[] = {
    SX_FIELD("descriptor_size","uint32",0,4,SX_SIZE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("file_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("end_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("unknown","uint32",20,4,SX_NONE),
    SX_FIELD("reserved","uint32",24,4,SX_RESERVED),
    SX_FIELD("encoded_unused_string","byte[40]",28,40,SX_NONE),
    SX_FIELD("encoded_command","byte[128]",68,128,SX_NONE),
    SX_FIELD("encoded_product_title","byte[80]",196,80,SX_NONE),
    SX_FIELD("encoded_source_directory","byte[128]",276,128,SX_NONE),
};
static const sx_layout sxil_installshield3_descriptor = {0x60850025U,"installshield3_descriptor",sxil_installshield3_descriptor_fields,SX_COUNT(sxil_installshield3_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield3_name_size_fields[] = {
    SX_FIELD("name_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxil_installshield3_name_size = {0x60850026U,"installshield3_name_size",sxil_installshield3_name_size_fields,SX_COUNT(sxil_installshield3_name_size_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield3_member_fields[] = {
    SX_FIELD("dos_date","uint16",0,2,SX_NONE),
    SX_FIELD("dos_time","uint16",2,2,SX_NONE),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxil_installshield3_member = {0x60850027U,"installshield3_member",sxil_installshield3_member_fields,SX_COUNT(sxil_installshield3_member_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield7_szdd_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("method","uint8",8,1,SX_ID),
    SX_FIELD("missing_name_character","uint8",9,1,SX_NONE),
    SX_FIELD("unpacked_size","uint32",10,4,SX_SIZE),
};
static const sx_layout sxil_installshield7_szdd = {0x60850028U,"installshield7_szdd",sxil_installshield7_szdd_fields,SX_COUNT(sxil_installshield7_szdd_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_developer_header_fields[] = {
    SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
    SX_FIELD("file_count","uint32",14,4,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[28]",18,28,SX_RESERVED),
};
static const sx_layout sxil_installshield_developer_header = {0x60850029U,"installshield_developer_header",sxil_installshield_developer_header_fields,SX_COUNT(sxil_installshield_developer_header_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_developer_record_fields[] = {
    SX_FIELD("name_storage","char[268]",0,268,SX_NONE),
    SX_FIELD("file_size","uint32",268,4,SX_SIZE),
    SX_FIELD("reserved","byte[40]",272,40,SX_RESERVED),
};
static const sx_layout sxil_installshield_developer_record = {0x6085002aU,"installshield_developer_record",sxil_installshield_developer_record_fields,SX_COUNT(sxil_installshield_developer_record_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_multiplatform_footer_fields[] = {
    SX_FIELD("index_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("signature","uint32",4,4,SX_SIGNATURE),
};
static const sx_layout sxil_installshield_multiplatform_footer = {0x6085002bU,"installshield_multiplatform_footer",sxil_installshield_multiplatform_footer_fields,SX_COUNT(sxil_installshield_multiplatform_footer_fields),SX_BE};

static const xx_data_struct_field_desc sxil_installshield_multiplatform_count_fields[] = {
    SX_FIELD("resource_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxil_installshield_multiplatform_count = {0x6085002cU,"installshield_multiplatform_count",sxil_installshield_multiplatform_count_fields,SX_COUNT(sxil_installshield_multiplatform_count_fields),SX_BE};

static const xx_data_struct_field_desc sxil_installshield_multiplatform_record_fields[] = {
    SX_FIELD("resource_type","uint8",0,1,SX_ID),
    SX_FIELD("resource_id","uint32",1,4,SX_ID),
    SX_FIELD("file_size","uint32",5,4,SX_SIZE),
    SX_FIELD("file_offset","uint32",9,4,SX_OFFSET),
    SX_FIELD("name_size","uint16",13,2,SX_SIZE),
};
static const sx_layout sxil_installshield_multiplatform_record = {0x6085002dU,"installshield_multiplatform_record",sxil_installshield_multiplatform_record_fields,SX_COUNT(sxil_installshield_multiplatform_record_fields),SX_BE};

static const xx_data_struct_field_desc sxil_installshield_multiplatform_optional_fields[] = {
    SX_FIELD("has_u64","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxil_installshield_multiplatform_optional = {0x6085002eU,"installshield_multiplatform_optional",sxil_installshield_multiplatform_optional_fields,SX_COUNT(sxil_installshield_multiplatform_optional_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_multiplatform_u64_fields[] = {
    SX_FIELD("bundled_jvm_value","uint64",0,8,SX_NONE),
};
static const sx_layout sxil_installshield_multiplatform_u64 = {0x6085002fU,"installshield_multiplatform_u64",sxil_installshield_multiplatform_u64_fields,SX_COUNT(sxil_installshield_multiplatform_u64_fields),SX_BE};

static const xx_data_struct_field_desc sxil_installshield_skin_encoded_name_fields[] = {
    SX_FIELD("encoded_name","uint8",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_skin_encoded_name = {0x60850030U,"installshield_skin_encoded_name",sxil_installshield_skin_encoded_name_fields,SX_COUNT(sxil_installshield_skin_encoded_name_fields),SX_LE};

static const xx_data_struct_field_desc sxil_installshield_skin_encoded_size_fields[] = {
    SX_FIELD("encoded_size","uint8",0,0,SX_NONE),
};
static const sx_layout sxil_installshield_skin_encoded_size = {0x60850031U,"installshield_skin_encoded_size",sxil_installshield_skin_encoded_size_fields,SX_COUNT(sxil_installshield_skin_encoded_size_fields),SX_LE};

static const xx_data_struct_field_desc sxil_qsetup_length_fields[] = {
    SX_FIELD("string_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxil_qsetup_length = {0x60850032U,"qsetup_length",sxil_qsetup_length_fields,SX_COUNT(sxil_qsetup_length_fields),SX_LE};

static const xx_data_struct_field_desc sxil_qsetup_record_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxil_qsetup_record = {0x60850033U,"qsetup_record",sxil_qsetup_record_fields,SX_COUNT(sxil_qsetup_record_fields),SX_LE};

static const xx_data_struct_field_desc sxil_qsetup_trailer_fields[] = {
    SX_FIELD("unknown1","byte[4]",0,4,SX_NONE),
    SX_FIELD("container_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("record_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("signature","uint32",12,4,SX_SIGNATURE),
    SX_FIELD("unknown2","byte[54]",16,54,SX_NONE),
    SX_FIELD("trailer_size","uint32",70,4,SX_SIZE),
};
static const sx_layout sxil_qsetup_trailer = {0x60850034U,"qsetup_trailer",sxil_qsetup_trailer_fields,SX_COUNT(sxil_qsetup_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxil_tarma_section_fields[] = {
    SX_FIELD("unknown","byte[16]",0,16,SX_NONE),
    SX_FIELD("signature","char[4]",16,4,SX_SIGNATURE),
    SX_FIELD("minor_version","uint16",20,2,SX_ID),
    SX_FIELD("major_version","uint16",22,2,SX_ID),
    SX_FIELD("reserved","uint64",24,8,SX_RESERVED),
    SX_FIELD("section_size","uint64",32,8,SX_SIZE),
    SX_FIELD("reserved2","byte[8]",40,8,SX_RESERVED),
    SX_FIELD("database_identifier","byte[16]",48,16,SX_NONE),
    SX_FIELD("check_word_a","uint32",64,4,SX_NONE),
    SX_FIELD("check_word_b","uint32",68,4,SX_NONE),
};
static const sx_layout sxil_tarma_section = {0x60850035U,"tarma_section",sxil_tarma_section_fields,SX_COUNT(sxil_tarma_section_fields),SX_LE};

static const xx_data_struct_field_desc sxil_tarma_lzma_properties_fields[] = {
    SX_FIELD("properties","uint8",0,1,SX_NONE),
    SX_FIELD("dictionary_size","uint32",1,4,SX_SIZE),
};
static const sx_layout sxil_tarma_lzma_properties = {0x60850036U,"tarma_lzma_properties",sxil_tarma_lzma_properties_fields,SX_COUNT(sxil_tarma_lzma_properties_fields),SX_LE};

static const xx_data_struct_field_desc sxil_tarma_separator_fields[] = {
    SX_FIELD("value","uint32",0,4,SX_NONE),
    SX_FIELD("complemented_value","uint32",4,4,SX_NONE),
    SX_FIELD("reserved","uint64",8,8,SX_RESERVED),
};
static const sx_layout sxil_tarma_separator = {0x60850037U,"tarma_separator",sxil_tarma_separator_fields,SX_COUNT(sxil_tarma_separator_fields),SX_LE};

static const xx_data_struct_field_desc sxil_gentee_locator_fields[] = {
    SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("first_block_size","uint32",4,4,SX_SIZE),
    SX_FIELD("first_unpacked_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxil_gentee_locator = {0x60850038U,"gentee_locator",sxil_gentee_locator_fields,SX_COUNT(sxil_gentee_locator_fields),SX_LE};

static const xx_data_struct_field_desc sxil_gentee_block_size_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxil_gentee_block_size = {0x60850039U,"gentee_block_size",sxil_gentee_block_size_fields,SX_COUNT(sxil_gentee_block_size_fields),SX_LE};

static const xx_data_struct_field_desc sxil_createinstall_record_fields[] = {
    SX_FIELD("record_type","uint8",0,1,SX_ID),
    SX_FIELD("flag","uint8",1,1,SX_FLAGS),
    SX_FIELD("attributes","uint32",2,4,SX_FLAGS),
    SX_FIELD("filetime","uint64",6,8,SX_TIME),
    SX_FIELD("method","uint8",14,1,SX_ID),
    SX_FIELD("name_length","int16",15,2,SX_SIZE),
};
static const sx_layout sxil_createinstall_record = {0x6085003aU,"createinstall_record",sxil_createinstall_record_fields,SX_COUNT(sxil_createinstall_record_fields),SX_LE};

static const xx_data_struct_field_desc sxil_createinstall_file_size_fields[] = {
    SX_FIELD("file_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxil_createinstall_file_size = {0x6085003bU,"createinstall_file_size",sxil_createinstall_file_size_fields,SX_COUNT(sxil_createinstall_file_size_fields),SX_LE};

static const xx_data_struct_field_desc sxil_createinstall_prelude_fields[] = {
    SX_FIELD("carrier_size","uint32",0,4,SX_SIZE),
    SX_FIELD("unknown","uint32",4,4,SX_NONE),
    SX_FIELD("script_size","int32",8,4,SX_SIZE),
    SX_FIELD("unknown_tail","byte[6]",12,6,SX_NONE),
};
static const sx_layout sxil_createinstall_prelude = {0x6085003cU,"createinstall_prelude",sxil_createinstall_prelude_fields,SX_COUNT(sxil_createinstall_prelude_fields),SX_LE};

static const xx_data_struct_field_desc sxil_clickteam_creator_tag_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
};
static const sx_layout sxil_clickteam_creator_tag = {0x6085003dU,"clickteam_creator_tag",sxil_clickteam_creator_tag_fields,SX_COUNT(sxil_clickteam_creator_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxil_clickteam_creator_chunk_fields[] = {
    SX_FIELD("chunk_id","uint16",0,2,SX_ID),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxil_clickteam_creator_chunk = {0x6085003eU,"clickteam_creator_chunk",sxil_clickteam_creator_chunk_fields,SX_COUNT(sxil_clickteam_creator_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxil_clickteam_creator_data_chunk_fields[] = {
    SX_FIELD("chunk_id","uint16",0,2,SX_ID),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("repeated_data_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxil_clickteam_creator_data_chunk = {0x6085003fU,"clickteam_creator_data_chunk",sxil_clickteam_creator_data_chunk_fields,SX_COUNT(sxil_clickteam_creator_data_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxil_clickteam_creator_compression1_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxil_clickteam_creator_compression1 = {0x60850040U,"clickteam_creator_compression1",sxil_clickteam_creator_compression1_fields,SX_COUNT(sxil_clickteam_creator_compression1_fields),SX_LE};

static const xx_data_struct_field_desc sxil_clickteam_creator_compression2_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
    SX_FIELD("method","uint8",4,1,SX_ID),
};
static const sx_layout sxil_clickteam_creator_compression2 = {0x60850041U,"clickteam_creator_compression2",sxil_clickteam_creator_compression2_fields,SX_COUNT(sxil_clickteam_creator_compression2_fields),SX_LE};

static const xx_data_struct_field_desc sxil_clickteam_creator_method_fields[] = {
    SX_FIELD("method","uint8",0,1,SX_ID),
};
static const sx_layout sxil_clickteam_creator_method = {0x60850042U,"clickteam_creator_method",sxil_clickteam_creator_method_fields,SX_COUNT(sxil_clickteam_creator_method_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("build_time","uint32",4,4,SX_TIME),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("variant","uint32",12,4,SX_ID),
};
static const sx_layout sxil_vise_header = {0x60850043U,"vise_header",sxil_vise_header_fields,SX_COUNT(sxil_vise_header_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_footer_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxil_vise_footer = {0x60850044U,"vise_footer",sxil_vise_footer_fields,SX_COUNT(sxil_vise_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_wrapper_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("container_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxil_vise_wrapper = {0x60850045U,"vise_wrapper",sxil_vise_wrapper_fields,SX_COUNT(sxil_vise_wrapper_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_string8_fields[] = {
    SX_FIELD("string_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxil_vise_string8 = {0x60850046U,"vise_string8",sxil_vise_string8_fields,SX_COUNT(sxil_vise_string8_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_string16_fields[] = {
    SX_FIELD("string_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxil_vise_string16 = {0x60850047U,"vise_string16",sxil_vise_string16_fields,SX_COUNT(sxil_vise_string16_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_masked_length_fields[] = {
    SX_FIELD("length_and_flags","uint8",0,1,SX_NONE),
};
static const sx_layout sxil_vise_masked_length = {0x60850048U,"vise_masked_length",sxil_vise_masked_length_fields,SX_COUNT(sxil_vise_masked_length_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_setup_count_fields[] = {
    SX_FIELD("file_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxil_vise_setup_count = {0x60850049U,"vise_setup_count",sxil_vise_setup_count_fields,SX_COUNT(sxil_vise_setup_count_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_setup_fields_fields[] = {
    SX_FIELD("dos_date","uint16",0,2,SX_NONE),
    SX_FIELD("dos_time","uint16",2,2,SX_NONE),
    SX_FIELD("unknown","byte[8]",4,8,SX_NONE),
    SX_FIELD("packed_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxil_vise_setup_fields = {0x6085004aU,"vise_setup_fields",sxil_vise_setup_fields_fields,SX_COUNT(sxil_vise_setup_fields_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_packed_size_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxil_vise_packed_size = {0x6085004bU,"vise_packed_size",sxil_vise_packed_size_fields,SX_COUNT(sxil_vise_packed_size_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_object4_fields[] = {
    SX_FIELD("reserved","byte[4]",0,4,SX_RESERVED),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
    SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxil_vise_object4 = {0x6085004cU,"vise_object4",sxil_vise_object4_fields,SX_COUNT(sxil_vise_object4_fields),SX_LE};

static const xx_data_struct_field_desc sxil_vise_object6_fields[] = {
    SX_FIELD("reserved","byte[6]",0,6,SX_RESERVED),
    SX_FIELD("unpacked_size","uint32",6,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",10,4,SX_SIZE),
    SX_FIELD("flags","uint32",14,4,SX_FLAGS),
    SX_FIELD("data_offset","uint32",18,4,SX_OFFSET),
};
static const sx_layout sxil_vise_object6 = {0x6085004dU,"vise_object6",sxil_vise_object6_fields,SX_COUNT(sxil_vise_object6_fields),SX_LE};

static const xx_data_struct_field_desc sxil_wise_member_crc32_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxil_wise_member_crc32 = {0x6085004eU,"wise_member_crc32",sxil_wise_member_crc32_fields,SX_COUNT(sxil_wise_member_crc32_fields),SX_LE};

static const xx_data_struct_field_desc sxil_wise_zip_local_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version_needed","uint16",4,2,SX_ID),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
    SX_FIELD("method","uint16",8,2,SX_ID),
    SX_FIELD("dos_time","uint16",10,2,SX_NONE),
    SX_FIELD("dos_date","uint16",12,2,SX_NONE),
    SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",18,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",22,4,SX_SIZE),
    SX_FIELD("name_size","uint16",26,2,SX_SIZE),
    SX_FIELD("extra_size","uint16",28,2,SX_SIZE),
};
static const sx_layout sxil_wise_zip_local = {0x6085004fU,"wise_zip_local",sxil_wise_zip_local_fields,SX_COUNT(sxil_wise_zip_local_fields),SX_LE};

static const xx_data_struct_field_desc sxil_wise_zip_central_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version_made_by","uint16",4,2,SX_ID),
    SX_FIELD("version_needed","uint16",6,2,SX_ID),
    SX_FIELD("flags","uint16",8,2,SX_FLAGS),
    SX_FIELD("method","uint16",10,2,SX_ID),
    SX_FIELD("dos_time","uint16",12,2,SX_NONE),
    SX_FIELD("dos_date","uint16",14,2,SX_NONE),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("name_size","uint16",28,2,SX_SIZE),
    SX_FIELD("extra_size","uint16",30,2,SX_SIZE),
    SX_FIELD("comment_size","uint16",32,2,SX_SIZE),
    SX_FIELD("disk_start","uint16",34,2,SX_NONE),
    SX_FIELD("internal_attributes","uint16",36,2,SX_FLAGS),
    SX_FIELD("external_attributes","uint32",38,4,SX_FLAGS),
    SX_FIELD("local_header_offset","uint32",42,4,SX_OFFSET),
};
static const sx_layout sxil_wise_zip_central = {0x60850050U,"wise_zip_central",sxil_wise_zip_central_fields,SX_COUNT(sxil_wise_zip_central_fields),SX_LE};

static const xx_data_struct_field_desc sxil_wise_zip_end_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("disk_number","uint16",4,2,SX_NONE),
    SX_FIELD("directory_disk","uint16",6,2,SX_NONE),
    SX_FIELD("entries_on_disk","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("total_entries","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("directory_size","uint32",12,4,SX_SIZE),
    SX_FIELD("directory_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("comment_size","uint16",20,2,SX_SIZE),
};
static const sx_layout sxil_wise_zip_end = {0x60850051U,"wise_zip_end",sxil_wise_zip_end_fields,SX_COUNT(sxil_wise_zip_end_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ghost_encoded_cab_header_fields[] = {
    SX_FIELD("encoded_signature","byte[4]",0,4,SX_NONE),
    SX_FIELD("encoded_reserved1","byte[4]",4,4,SX_NONE),
    SX_FIELD("encoded_cabinet_size","byte[4]",8,4,SX_NONE),
    SX_FIELD("encoded_reserved2","byte[4]",12,4,SX_NONE),
    SX_FIELD("encoded_files_offset","byte[4]",16,4,SX_NONE),
    SX_FIELD("encoded_reserved3","byte[4]",20,4,SX_NONE),
    SX_FIELD("encoded_version_minor","byte[1]",24,1,SX_NONE),
    SX_FIELD("encoded_version_major","byte[1]",25,1,SX_NONE),
    SX_FIELD("encoded_folder_count","byte[2]",26,2,SX_NONE),
    SX_FIELD("encoded_file_count","byte[2]",28,2,SX_NONE),
    SX_FIELD("encoded_flags","byte[2]",30,2,SX_NONE),
    SX_FIELD("encoded_set_id","byte[2]",32,2,SX_NONE),
    SX_FIELD("encoded_cabinet_index","byte[2]",34,2,SX_NONE),
};
static const sx_layout sxil_ghost_encoded_cab_header = {0x60850052U,"ghost_encoded_cab_header",sxil_ghost_encoded_cab_header_fields,SX_COUNT(sxil_ghost_encoded_cab_header_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ghost_encoded_cab_reserve_fields[] = {
    SX_FIELD("encoded_header_reserve_size","byte[2]",0,2,SX_NONE),
    SX_FIELD("encoded_folder_reserve_size","byte[1]",2,1,SX_NONE),
    SX_FIELD("encoded_data_reserve_size","byte[1]",3,1,SX_NONE),
};
static const sx_layout sxil_ghost_encoded_cab_reserve = {0x60850053U,"ghost_encoded_cab_reserve",sxil_ghost_encoded_cab_reserve_fields,SX_COUNT(sxil_ghost_encoded_cab_reserve_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ghost_encoded_cab_folder_fields[] = {
    SX_FIELD("encoded_data_offset","byte[4]",0,4,SX_NONE),
    SX_FIELD("encoded_data_count","byte[2]",4,2,SX_NONE),
    SX_FIELD("encoded_compression_type","byte[2]",6,2,SX_NONE),
};
static const sx_layout sxil_ghost_encoded_cab_folder = {0x60850054U,"ghost_encoded_cab_folder",sxil_ghost_encoded_cab_folder_fields,SX_COUNT(sxil_ghost_encoded_cab_folder_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ghost_encoded_cab_file_fields[] = {
    SX_FIELD("encoded_unpacked_size","byte[4]",0,4,SX_NONE),
    SX_FIELD("encoded_folder_offset","byte[4]",4,4,SX_NONE),
    SX_FIELD("encoded_folder_index","byte[2]",8,2,SX_NONE),
    SX_FIELD("encoded_dos_date","byte[2]",10,2,SX_NONE),
    SX_FIELD("encoded_dos_time","byte[2]",12,2,SX_NONE),
    SX_FIELD("encoded_attributes","byte[2]",14,2,SX_NONE),
};
static const sx_layout sxil_ghost_encoded_cab_file = {0x60850055U,"ghost_encoded_cab_file",sxil_ghost_encoded_cab_file_fields,SX_COUNT(sxil_ghost_encoded_cab_file_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ghost_encoded_cab_data_fields[] = {
    SX_FIELD("encoded_checksum","byte[4]",0,4,SX_NONE),
    SX_FIELD("encoded_packed_size","byte[2]",4,2,SX_NONE),
    SX_FIELD("encoded_unpacked_size","byte[2]",6,2,SX_NONE),
};
static const sx_layout sxil_ghost_encoded_cab_data = {0x60850056U,"ghost_encoded_cab_data",sxil_ghost_encoded_cab_data_fields,SX_COUNT(sxil_ghost_encoded_cab_data_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ghost_trailer26_fields[] = {
    SX_FIELD("metadata","byte[20]",0,20,SX_NONE),
    SX_FIELD("marker","char[6]",20,6,SX_SIGNATURE),
};
static const sx_layout sxil_ghost_trailer26 = {0x60850057U,"ghost_trailer26",sxil_ghost_trailer26_fields,SX_COUNT(sxil_ghost_trailer26_fields),SX_LE};

static const xx_data_struct_field_desc sxil_ghost_trailer34_fields[] = {
    SX_FIELD("metadata","byte[28]",0,28,SX_NONE),
    SX_FIELD("marker","char[6]",28,6,SX_SIGNATURE),
};
static const sx_layout sxil_ghost_trailer34 = {0x60850058U,"ghost_trailer34",sxil_ghost_trailer34_fields,SX_COUNT(sxil_ghost_trailer34_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_loader_pointer_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("table_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("complemented_table_offset","uint32",8,4,SX_NONE),
};
static const sx_layout sxil_inno_loader_pointer = {0x60850059U,"inno_loader_pointer",sxil_inno_loader_pointer_fields,SX_COUNT(sxil_inno_loader_pointer_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_loader2_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("legacy_word","uint32",32,4,SX_NONE),
    SX_FIELD("setup_header_offset","uint32",36,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",40,4,SX_OFFSET),
};
static const sx_layout sxil_inno_loader2 = {0x6085005aU,"inno_loader2",sxil_inno_loader2_fields,SX_COUNT(sxil_inno_loader2_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_loader4_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",36,4,SX_OFFSET),
};
static const sx_layout sxil_inno_loader4 = {0x6085005bU,"inno_loader4",sxil_inno_loader4_fields,SX_COUNT(sxil_inno_loader4_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_loader5_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",36,4,SX_OFFSET),
};
static const sx_layout sxil_inno_loader5 = {0x6085005cU,"inno_loader5",sxil_inno_loader5_fields,SX_COUNT(sxil_inno_loader5_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_loader6_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",36,4,SX_OFFSET),
    SX_FIELD("table_crc32","uint32",40,4,SX_CHECKSUM),
};
static const sx_layout sxil_inno_loader6 = {0x6085005dU,"inno_loader6",sxil_inno_loader6_fields,SX_COUNT(sxil_inno_loader6_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_loader7_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_unpacked_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",24,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("table_crc32","uint32",36,4,SX_CHECKSUM),
};
static const sx_layout sxil_inno_loader7 = {0x6085005eU,"inno_loader7",sxil_inno_loader7_fields,SX_COUNT(sxil_inno_loader7_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_loader_revision1_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("revision","uint32",12,4,SX_ID),
    SX_FIELD("total_size","uint32",16,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",36,4,SX_OFFSET),
    SX_FIELD("table_crc32","uint32",40,4,SX_CHECKSUM),
};
static const sx_layout sxil_inno_loader_revision1 = {0x6085005fU,"inno_loader_revision1",sxil_inno_loader_revision1_fields,SX_COUNT(sxil_inno_loader_revision1_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_loader_revision2_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("revision","uint32",12,4,SX_ID),
    SX_FIELD("total_size","uint64",16,8,SX_SIZE),
    SX_FIELD("exe_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("exe_unpacked_size","uint32",32,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",36,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("data_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("reserved","uint32",56,4,SX_RESERVED),
    SX_FIELD("table_crc32","uint32",60,4,SX_CHECKSUM),
};
static const sx_layout sxil_inno_loader_revision2 = {0x60850060U,"inno_loader_revision2",sxil_inno_loader_revision2_fields,SX_COUNT(sxil_inno_loader_revision2_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_setup_version_fields[] = {
    SX_FIELD("version","char[64]",0,64,SX_NONE),
};
static const sx_layout sxil_inno_setup_version = {0x60850061U,"inno_setup_version",sxil_inno_setup_version_fields,SX_COUNT(sxil_inno_setup_version_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_encryption_envelope_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("encryption_kind","uint8",4,1,SX_ID),
    SX_FIELD("encryption_parameters","byte[48]",5,48,SX_NONE),
};
static const sx_layout sxil_inno_encryption_envelope = {0x60850062U,"inno_encryption_envelope",sxil_inno_encryption_envelope_fields,SX_COUNT(sxil_inno_encryption_envelope_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_block_legacy_fields[] = {
    SX_FIELD("header_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("compressed_size","int32",4,4,SX_NONE),
    SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxil_inno_block_legacy = {0x60850063U,"inno_block_legacy",sxil_inno_block_legacy_fields,SX_COUNT(sxil_inno_block_legacy_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_block32_fields[] = {
    SX_FIELD("header_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("stored_extent","uint32",4,4,SX_SIZE),
    SX_FIELD("compressed","uint8",8,1,SX_FLAGS),
};
static const sx_layout sxil_inno_block32 = {0x60850064U,"inno_block32",sxil_inno_block32_fields,SX_COUNT(sxil_inno_block32_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_block64_fields[] = {
    SX_FIELD("header_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("stored_extent","uint64",4,8,SX_SIZE),
    SX_FIELD("compressed","uint8",12,1,SX_FLAGS),
};
static const sx_layout sxil_inno_block64 = {0x60850065U,"inno_block64",sxil_inno_block64_fields,SX_COUNT(sxil_inno_block64_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_block_crc32_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxil_inno_block_crc32 = {0x60850066U,"inno_block_crc32",sxil_inno_block_crc32_fields,SX_COUNT(sxil_inno_block_crc32_fields),SX_LE};

static const xx_data_struct_field_desc sxil_inno_data_marker_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxil_inno_data_marker = {0x60850067U,"inno_data_marker",sxil_inno_data_marker_fields,SX_COUNT(sxil_inno_data_marker_fields),SX_LE};

static const sx_layout *const sx_installerlast_layouts[] = {
    &sxil_installerlast_name,
    &sxil_installerlast_utf16_name,
    &sxil_installerlast_encoded_bytes,
    &sxil_installerlast_decimal_size,
    &sxil_installerlast_utf16_size,
    &sxil_advanced_installer_footer,
    &sxil_advanced_installer_record,
    &sxil_advanced_installer_external,
    &sxil_ardi_trailer,
    &sxil_ardi_block_tag,
    &sxil_ardi_block_length,
    &sxil_ardi_member_time,
    &sxil_ardi_chain_start,
    &sxil_arni_member,
    &sxil_arni_end,
    &sxil_ej_technologies_header,
    &sxil_ej_technologies_variable,
    &sxil_ej_technologies_extra_count,
    &sxil_ej_technologies_member,
    &sxil_ej_technologies_member_later,
    &sxil_ej_technologies_trailer,
    &sxil_ej_technologies_trailer_name,
    &sxil_ej_technologies_trailer_size,
    &sxil_ibm_zpak_sfx_header,
    &sxil_ibm_zpak_sfx_v1_directory,
    &sxil_ibm_zpak_sfx_v2_record,
    &sxil_ibm_zpak_sfx_v1_trailer,
    &sxil_ibm_zpak_sfx_v2_trailer,
    &sxil_installerlast_dcl_prelude,
    &sxil_installshield12_count,
    &sxil_installshield_ansi_base_name,
    &sxil_installshield_utf16_base_name,
    &sxil_installshield_ansi_relative_path,
    &sxil_installshield_utf16_relative_path,
    &sxil_installshield_ansi_version,
    &sxil_installshield_utf16_version,
    &sxil_installshield3_descriptor,
    &sxil_installshield3_name_size,
    &sxil_installshield3_member,
    &sxil_installshield7_szdd,
    &sxil_installshield_developer_header,
    &sxil_installshield_developer_record,
    &sxil_installshield_multiplatform_footer,
    &sxil_installshield_multiplatform_count,
    &sxil_installshield_multiplatform_record,
    &sxil_installshield_multiplatform_optional,
    &sxil_installshield_multiplatform_u64,
    &sxil_installshield_skin_encoded_name,
    &sxil_installshield_skin_encoded_size,
    &sxil_qsetup_length,
    &sxil_qsetup_record,
    &sxil_qsetup_trailer,
    &sxil_tarma_section,
    &sxil_tarma_lzma_properties,
    &sxil_tarma_separator,
    &sxil_gentee_locator,
    &sxil_gentee_block_size,
    &sxil_createinstall_record,
    &sxil_createinstall_file_size,
    &sxil_createinstall_prelude,
    &sxil_clickteam_creator_tag,
    &sxil_clickteam_creator_chunk,
    &sxil_clickteam_creator_data_chunk,
    &sxil_clickteam_creator_compression1,
    &sxil_clickteam_creator_compression2,
    &sxil_clickteam_creator_method,
    &sxil_vise_header,
    &sxil_vise_footer,
    &sxil_vise_wrapper,
    &sxil_vise_string8,
    &sxil_vise_string16,
    &sxil_vise_masked_length,
    &sxil_vise_setup_count,
    &sxil_vise_setup_fields,
    &sxil_vise_packed_size,
    &sxil_vise_object4,
    &sxil_vise_object6,
    &sxil_wise_member_crc32,
    &sxil_wise_zip_local,
    &sxil_wise_zip_central,
    &sxil_wise_zip_end,
    &sxil_ghost_encoded_cab_header,
    &sxil_ghost_encoded_cab_reserve,
    &sxil_ghost_encoded_cab_folder,
    &sxil_ghost_encoded_cab_file,
    &sxil_ghost_encoded_cab_data,
    &sxil_ghost_trailer26,
    &sxil_ghost_trailer34,
    &sxil_inno_loader_pointer,
    &sxil_inno_loader2,
    &sxil_inno_loader4,
    &sxil_inno_loader5,
    &sxil_inno_loader6,
    &sxil_inno_loader7,
    &sxil_inno_loader_revision1,
    &sxil_inno_loader_revision2,
    &sxil_inno_setup_version,
    &sxil_inno_encryption_envelope,
    &sxil_inno_block_legacy,
    &sxil_inno_block32,
    &sxil_inno_block64,
    &sxil_inno_block_crc32,
    &sxil_inno_data_marker,
};

static bool sx_installerlast_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60850000U||id>=0x60860000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    switch(id){
    case 0x60850001U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Stored byte string including terminator when present; producer codepage varies";
        break;
    case 0x60850002U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Stored UTF-16LE code units";
        break;
    case 0x60850003U:
        if(!xx_rt_wcscmp(r->name,L"encoded_bytes"))s=L"Encoded physical bytes; values are not substituted with plaintext";
        break;
    case 0x60850004U:
        if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Stored ASCII decimal byte count";
        break;
    case 0x60850005U:
        if(!xx_rt_wcscmp(r->name,L"file_size_text"))s=L"Stored UTF-16LE decimal byte count; code units are retained";
        break;
    case 0x60850006U:
        if(!xx_rt_wcscmp(r->name,L"mode"))s=L"0 internal payload; 1 external MSI";
        else if(!xx_rt_wcscmp(r->name,L"external_name_offset"))s=L"Executable-relative external-name block offset in mode 1; footer offset in mode 0";
        else if(!xx_rt_wcscmp(r->name,L"metadata_end"))s=L"Executable-relative footer offset";
        else if(!xx_rt_wcscmp(r->name,L"info_offset"))s=L"Executable-relative file table offset";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative first stored payload";
        break;
    case 0x60850007U:
        if(!xx_rt_wcscmp(r->name,L"index"))s=L"Stored member ordinal";
        else if(!xx_rt_wcscmp(r->name,L"xor_flag"))s=L"2 XORs the first min(file_size,512) bytes with 0xFF; 0 is plain";
        else if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"Executable-relative payload offset";
        else if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Number of following UTF-16LE code units";
        break;
    case 0x60850008U:
        if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Number of following UTF-16LE code units";
        break;
    case 0x60850009U:
        if(!xx_rt_wcscmp(r->name,L"builder_check"))s=L"Builder check word; algorithm not established";
        break;
    case 0x6085000bU:
        if(!xx_rt_wcscmp(r->name,L"block_size"))s=L"Total block bytes including the tag and this trailing size word";
        break;
    case 0x6085000cU:
        if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Unix seconds";
        break;
    case 0x60850013U:
        if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Size of the following XOR-0x88 payload";
        break;
    case 0x60850014U:
        if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Size of the following XOR-0x88 payload";
        break;
    case 0x60850019U:
        if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x6085001aU:
        if(!xx_rt_wcscmp(r->name,L"writer_scratch"))s=L"Not reserved; nonzero producer-specific values occur";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        else if(!xx_rt_wcscmp(r->name,L"name_size"))s=L"Byte size including terminating NUL";
        break;
    case 0x6085001bU:
        if(!xx_rt_wcscmp(r->name,L"header_offset"))s=L"Executable-relative archive header";
        break;
    case 0x6085001cU:
        if(!xx_rt_wcscmp(r->name,L"header_offset"))s=L"Executable-relative archive header";
        else if(!xx_rt_wcscmp(r->name,L"adjusted_file_size"))s=L"Stored file size plus 16 times the member count";
        break;
    case 0x6085001dU:
        if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))s=L"Dictionary parameter 4..6; not a byte size";
        break;
    case 0x6085001fU:
        if(!xx_rt_wcscmp(r->name,L"base_name"))s=L"Stored NUL-terminated ANSI string";
        break;
    case 0x60850020U:
        if(!xx_rt_wcscmp(r->name,L"base_name"))s=L"Stored NUL-terminated UTF-16LE string";
        break;
    case 0x60850021U:
        if(!xx_rt_wcscmp(r->name,L"relative_path"))s=L"Stored NUL-terminated ANSI string";
        break;
    case 0x60850022U:
        if(!xx_rt_wcscmp(r->name,L"relative_path"))s=L"Stored NUL-terminated UTF-16LE string";
        break;
    case 0x60850023U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"Stored NUL-terminated ANSI string";
        break;
    case 0x60850024U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"Stored NUL-terminated UTF-16LE string";
        break;
    case 0x60850025U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative first record";
        else if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Executable-relative end of the last record";
        else if(!xx_rt_wcscmp(r->name,L"encoded_unused_string"))s=L"Rotate/XOR-obfuscated fixed string allocation";
        else if(!xx_rt_wcscmp(r->name,L"encoded_command"))s=L"Rotate/XOR-obfuscated command";
        else if(!xx_rt_wcscmp(r->name,L"encoded_product_title"))s=L"Rotate/XOR-obfuscated product title";
        else if(!xx_rt_wcscmp(r->name,L"encoded_source_directory"))s=L"Rotate/XOR-obfuscated source directory";
        break;
    case 0x60850027U:
        if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x6085002aU:
        if(!xx_rt_wcscmp(r->name,L"name_storage"))s=L"ANSI name and zero padding; later encoding-flag variants are not accepted by the native reader";
        break;
    case 0x6085002bU:
        if(!xx_rt_wcscmp(r->name,L"index_offset"))s=L"File-relative resource index";
        break;
    case 0x6085002dU:
        if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"File-relative stored resource";
        else if(!xx_rt_wcscmp(r->name,L"name_size"))s=L"Byte length of Java modified UTF-8 name";
        break;
    case 0x6085002eU:
        if(!xx_rt_wcscmp(r->name,L"has_u64"))s=L"0 or 1; whether the following 64-bit word is present";
        break;
    case 0x6085002fU:
        if(!xx_rt_wcscmp(r->name,L"bundled_jvm_value"))s=L"Opaque producer value; present only when selected by preceding flag";
        break;
    case 0x60850030U:
        if(!xx_rt_wcscmp(r->name,L"encoded_name"))s=L"Physical nibble-swapped and XOR-obfuscated name including encoded terminator";
        break;
    case 0x60850031U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size"))s=L"Physical nibble-swapped and XOR-obfuscated decimal byte count including encoded terminator";
        break;
    case 0x60850033U:
        if(!xx_rt_wcscmp(r->name,L"packed_size"))s=L"Byte size of the following complete zlib stream";
        break;
    case 0x60850034U:
        if(!xx_rt_wcscmp(r->name,L"container_offset"))s=L"Executable-relative overlay start";
        break;
    case 0x60850035U:
        if(!xx_rt_wcscmp(r->name,L"section_size"))s=L"Includes this 72-byte header";
        else if(!xx_rt_wcscmp(r->name,L"check_word_a"))s=L"XOR with check_word_b equals 0x35BC6F82";
        else if(!xx_rt_wcscmp(r->name,L"check_word_b"))s=L"XOR with check_word_a equals 0x35BC6F82";
        break;
    case 0x60850036U:
        if(!xx_rt_wcscmp(r->name,L"properties"))s=L"Encoded LZMA lc/lp/pb parameters";
        break;
    case 0x60850037U:
        if(!xx_rt_wcscmp(r->name,L"complemented_value"))s=L"Bitwise complement of preceding value";
        break;
    case 0x60850038U:
        if(!xx_rt_wcscmp(r->name,L"payload_offset"))s=L"Executable-relative first block";
        else if(!xx_rt_wcscmp(r->name,L"first_block_size"))s=L"Producer locator size; native parser authenticates the payload pointer independently";
        break;
    case 0x60850039U:
        if(!xx_rt_wcscmp(r->name,L"unpacked_size"))s=L"Physical prefix of a solid adaptive-Huffman block; compressed extent is determined by native decoding";
        break;
    case 0x6085003aU:
        if(!xx_rt_wcscmp(r->name,L"record_type"))s=L"1 file; 2 enter directory; 3 leave directory; 4 end";
        else if(!xx_rt_wcscmp(r->name,L"filetime"))s=L"Windows FILETIME ticks";
        else if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 packed; 1 stored";
        break;
    case 0x60850041U:
        if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 stored; 1 zlib; 2 bzip2";
        break;
    case 0x60850042U:
        if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 stored; 1 zlib; 2 bzip2";
        break;
    case 0x60850043U:
        if(!xx_rt_wcscmp(r->name,L"build_time"))s=L"Stored build timestamp";
        break;
    case 0x60850044U:
        if(!xx_rt_wcscmp(r->name,L"header_offset"))s=L"Executable-relative ESIV header or SIVM wrapper";
        break;
    case 0x60850045U:
        if(!xx_rt_wcscmp(r->name,L"container_size"))s=L"Bytes from SIVM wrapper up to, but excluding, the eight-byte footer";
        break;
    case 0x60850047U:
        if(!xx_rt_wcscmp(r->name,L"string_size"))s=L"Byte count, not UTF-16 code units";
        break;
    case 0x60850048U:
        if(!xx_rt_wcscmp(r->name,L"length_and_flags"))s=L"Low six bits give the following byte count; upper bits are not interpreted";
        break;
    case 0x6085004aU:
        if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x6085004cU:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to ESIV header";
        break;
    case 0x6085004dU:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to ESIV header";
        break;
    case 0x6085004eU:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"CRC32 of the decoded raw-DEFLATE member";
        break;
    case 0x6085004fU:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Wise PK mode commonly sets bit 15";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        break;
    case 0x60850050U:
        if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"local_header_offset"))s=L"Absolute from executable start in native Wise PK mode";
        break;
    case 0x60850051U:
        if(!xx_rt_wcscmp(r->name,L"directory_offset"))s=L"Absolute from executable start in native Wise PK mode";
        break;
    case 0x60850052U:
        if(!xx_rt_wcscmp(r->name,L"encoded_signature"))s=L"Physical XOR-0x8D encoded signature";
        else if(!xx_rt_wcscmp(r->name,L"encoded_reserved1"))s=L"Physical XOR-0x8D encoded reserved1";
        else if(!xx_rt_wcscmp(r->name,L"encoded_cabinet_size"))s=L"Physical XOR-0x8D encoded cabinet_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_reserved2"))s=L"Physical XOR-0x8D encoded reserved2";
        else if(!xx_rt_wcscmp(r->name,L"encoded_files_offset"))s=L"Physical XOR-0x8D encoded files_offset";
        else if(!xx_rt_wcscmp(r->name,L"encoded_reserved3"))s=L"Physical XOR-0x8D encoded reserved3";
        else if(!xx_rt_wcscmp(r->name,L"encoded_version_minor"))s=L"Physical XOR-0x8D encoded version_minor";
        else if(!xx_rt_wcscmp(r->name,L"encoded_version_major"))s=L"Physical XOR-0x8D encoded version_major";
        else if(!xx_rt_wcscmp(r->name,L"encoded_folder_count"))s=L"Physical XOR-0x8D encoded folder_count";
        else if(!xx_rt_wcscmp(r->name,L"encoded_file_count"))s=L"Physical XOR-0x8D encoded file_count";
        else if(!xx_rt_wcscmp(r->name,L"encoded_flags"))s=L"Physical XOR-0x8D encoded flags";
        else if(!xx_rt_wcscmp(r->name,L"encoded_set_id"))s=L"Physical XOR-0x8D encoded set_id";
        else if(!xx_rt_wcscmp(r->name,L"encoded_cabinet_index"))s=L"Physical XOR-0x8D encoded cabinet_index";
        break;
    case 0x60850053U:
        if(!xx_rt_wcscmp(r->name,L"encoded_header_reserve_size"))s=L"Physical XOR-0x8D encoded header_reserve_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_folder_reserve_size"))s=L"Physical XOR-0x8D encoded folder_reserve_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_data_reserve_size"))s=L"Physical XOR-0x8D encoded data_reserve_size";
        break;
    case 0x60850054U:
        if(!xx_rt_wcscmp(r->name,L"encoded_data_offset"))s=L"Physical XOR-0x8D encoded data_offset";
        else if(!xx_rt_wcscmp(r->name,L"encoded_data_count"))s=L"Physical XOR-0x8D encoded data_count";
        else if(!xx_rt_wcscmp(r->name,L"encoded_compression_type"))s=L"Physical XOR-0x8D encoded compression_type";
        break;
    case 0x60850055U:
        if(!xx_rt_wcscmp(r->name,L"encoded_unpacked_size"))s=L"Physical XOR-0x8D encoded unpacked_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_folder_offset"))s=L"Physical XOR-0x8D encoded folder_offset";
        else if(!xx_rt_wcscmp(r->name,L"encoded_folder_index"))s=L"Physical XOR-0x8D encoded folder_index";
        else if(!xx_rt_wcscmp(r->name,L"encoded_dos_date"))s=L"Physical XOR-0x8D encoded dos_date";
        else if(!xx_rt_wcscmp(r->name,L"encoded_dos_time"))s=L"Physical XOR-0x8D encoded dos_time";
        else if(!xx_rt_wcscmp(r->name,L"encoded_attributes"))s=L"Physical XOR-0x8D encoded attributes";
        break;
    case 0x60850056U:
        if(!xx_rt_wcscmp(r->name,L"encoded_checksum"))s=L"Physical XOR-0x8D encoded checksum";
        else if(!xx_rt_wcscmp(r->name,L"encoded_packed_size"))s=L"Physical XOR-0x8D encoded packed_size";
        else if(!xx_rt_wcscmp(r->name,L"encoded_unpacked_size"))s=L"Physical XOR-0x8D encoded unpacked_size";
        break;
    case 0x60850057U:
        if(!xx_rt_wcscmp(r->name,L"metadata"))s=L"Clear producer-specific trailer words; exact meanings vary";
        break;
    case 0x60850058U:
        if(!xx_rt_wcscmp(r->name,L"metadata"))s=L"Clear producer-specific trailer words; exact meanings vary";
        break;
    case 0x60850059U:
        if(!xx_rt_wcscmp(r->name,L"table_offset"))s=L"Executable-relative loader table";
        else if(!xx_rt_wcscmp(r->name,L"complemented_table_offset"))s=L"Bitwise complement of table_offset";
        break;
    case 0x6085005aU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005bU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005cU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005dU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005eU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded setup loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x6085005fU:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x60850060U:
        if(!xx_rt_wcscmp(r->name,L"exe_offset"))s=L"Executable-relative embedded loader";
        else if(!xx_rt_wcscmp(r->name,L"setup_header_offset"))s=L"Executable-relative setup version record";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Executable-relative data area; zero denotes external slices";
        break;
    case 0x60850061U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"Stored setup format version text with NUL padding";
        break;
    case 0x60850062U:
        if(!xx_rt_wcscmp(r->name,L"encryption_parameters"))s=L"Physical encryption envelope; no plaintext substitution";
        break;
    case 0x60850063U:
        if(!xx_rt_wcscmp(r->name,L"compressed_size"))s=L"-1 means stored; otherwise compressed byte size excluding CRC prefixes";
        break;
    case 0x60850064U:
        if(!xx_rt_wcscmp(r->name,L"stored_extent"))s=L"Includes four-byte CRC prefixes for each up-to-4096-byte payload piece";
        break;
    case 0x60850065U:
        if(!xx_rt_wcscmp(r->name,L"stored_extent"))s=L"Includes four-byte CRC prefixes for each up-to-4096-byte payload piece";
        break;
    case 0x60850066U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"CRC32 of the following up-to-4096 physical payload bytes";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
#define SXIL_LIMIT 24000U
static bool sxil_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
static bool sxil_read(sx_context*c,uint64_t p,void*b,size_t n){return sxil_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxil16(const uint8_t*b,bool be){return be?((uint16_t)b[0]<<8)|b[1]:(uint16_t)b[0]|((uint16_t)b[1]<<8);}
static uint32_t sxil32(const uint8_t*b,bool be){return be?((uint32_t)b[0]<<24)|((uint32_t)b[1]<<16)|((uint32_t)b[2]<<8)|b[3]:(uint32_t)b[0]|((uint32_t)b[1]<<8)|((uint32_t)b[2]<<16)|((uint32_t)b[3]<<24);}
static bool sxil_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>UINT64_MAX/z||!sxil_span(c,p,count*z))return false;if(!count||c->count>=SXIL_LIMIT)return true;return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);}
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!sxil_span(c,p,n))return false;if(!n||n>4096||c->count>=SXIL_LIMIT)return true;return sx_add(c,l,(int64_t)p,(int64_t)n);}
static int sxil_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;if(x->offset!=y->offset)return x->offset<y->offset?-1:1;if(x->total_size!=y->total_size)return x->total_size<y->total_size?-1:1;return x->id<y->id?-1:x->id>y->id;}
static bool sxil_finish(sx_context*c){size_t n=c->count,kept=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxil_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end)continue;c->items[kept++]=c->items[i];end=p+z;}c->count=kept;n=kept;end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxil_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
typedef struct sxil_member { uint64_t header,header_size,data,packed,crc; } sxil_member;
typedef struct sxil_records { sxil_member *items; size_t count; } sxil_records;
/* Borrow the authenticated native iterator, copy only physical coordinates,
 * and release it before inspecting bytes. No subclass assumptions or ownership transfer. */
static bool sxil_collect(sx_context*c,sxil_records*out){
 Abstractformat*f=c->f;out->items=NULL;out->count=0;
 if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return true;
 xx_archive_record_state*state=(f->create_archive_records_reading)(f,NULL,c->pd);if(!state)return true;
 sxil_member*v=xx_mem_alloc(SXIL_LIMIT*sizeof(*v));if(!v){(f->free_archive_records_reading)(f,state);return false;}
 for(size_t i=0;i<SXIL_LIMIT&&!xx_pd_is_stopped(c->pd);i++){
  const xx_archive_record*r=(f->get_current_archive_record)(f,state);if(!r)break;
  if((r->header_offset>=f->base_address||(f->file_type==XX_FILE_TYPE_CLICKTEAM_INSTALL_CREATOR&&r->header_offset==-1))&&r->header_size>=0&&r->data_offset>=f->base_address&&r->compressed_size>=0){
   uint64_t p=r->header_offset<0?UINT64_MAX:(uint64_t)(r->header_offset-f->base_address),d=(uint64_t)(r->data_offset-f->base_address),h=(uint64_t)r->header_size,z=(uint64_t)r->compressed_size;
   if((p==UINT64_MAX||sxil_span(c,p,h))&&sxil_span(c,d,z))v[out->count++]=(sxil_member){p,h,d,z,xx_archive_record_get_meta_u64(r,XX_META_ID_CRC32,UINT64_MAX)};
  }
  if(!(f->archive_record_move_to_next)(f,state,c->pd))break;
 }
 (f->free_archive_records_reading)(f,state);out->items=v;return !xx_pd_is_stopped(c->pd);
}
static bool sxil_u32(sx_context*c,uint64_t p,uint32_t*v){uint8_t b[4];if(!sxil_read(c,p,b,4))return false;*v=sxil32(b,false);return true;}
static bool sxil_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxil_read(c,p,b,2))return false;*v=sxil16(b,false);return true;}
static bool sxil_eq(sx_context*c,uint64_t p,const void*s,size_t n){uint8_t b[32];return n<=sizeof(b)&&sxil_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static bool sxil_name(sx_context*c,uint64_t p,uint64_t n){return sxil_text(c,&sxil_installerlast_name,p,n);}
static bool sxil_encoded(sx_context*c,uint64_t p,uint64_t n){return sxil_text(c,&sxil_installerlast_encoded_bytes,p,n);}
/* This carrier walk locates an installer overlay only. It emits no PE fields. */
static bool sxil_pe(sx_context*c,uint64_t*out){
 uint8_t d[64],h[24],o[64],s[40];if(!sxil_read(c,0,d,64)||d[0]!='M'||d[1]!='Z')return false;
 uint64_t at=sxil32(d+60,false);if(!sxil_read(c,at,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;
 uint16_t count=sxil16(h+6,false),opt=sxil16(h+20,false);if(!count||count>96||opt<64||!sxil_read(c,at+24,o,64))return false;
 uint64_t end=sxil32(o+60,false),tab=at+24+opt;if(!sxil_span(c,0,end)||!sxil_span(c,tab,(uint64_t)count*40))return false;
 for(unsigned i=0;i<count;i++){if(!sxil_read(c,tab+40U*i,s,40))return false;uint64_t p=sxil32(s+20,false),n=sxil32(s+16,false);if(!sxil_span(c,p,n))return false;if(n&&p+n>end)end=p+n;}
 *out=end;return true;
}
static bool sxil_take(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l,unsigned width,bool decimal){
 uint64_t start=*p;uint8_t b[2];if(end>(uint64_t)c->size||!width||width>2)return false;
 for(unsigned i=0;i<4096&&*p<=end&&width<=end-*p;i++,*p+=width){if(!sxil_read(c,*p,b,width))return false;uint16_t v=width==1?b[0]:sxil16(b,false);if(!v){uint64_t n=*p-start;*p+=width;return sxil_text(c,l,start,decimal?n:n+width);}if(decimal&&(v<'0'||v>'9'))return false;}
 return false;
}
/* A bounded byte-pattern search for native-confirmed roots. Matches are always
 * checked against their count, geometry or authenticated member coordinates. */
static bool sxil_find(sx_context*c,const uint8_t*needle,size_t n,uint64_t start,uint64_t end,uint64_t*out){
 uint8_t b[4096+64];if(!n||n>64||start>end||end>(uint64_t)c->size)return false;
 while(start<end){size_t z=(size_t)((end-start)>sizeof(b)?sizeof(b):end-start);if(z<n||!sxil_read(c,start,b,z))return false;for(size_t k=0;k+n<=z;k++)if(!xx_rt_memcmp(b+k,needle,n)){*out=start+k;return true;}start+=z-n+1;}return false;
}
static bool sxil_u32be(sx_context*c,uint64_t p,uint32_t*v){uint8_t b[4];if(!sxil_read(c,p,b,4))return false;*v=sxil32(b,true);return true;}
static bool sxil_rva(sx_context*c,uint32_t rva,uint32_t bytes,uint64_t*out){uint32_t nt;uint8_t h[24];if(!sxil_u32(c,60,&nt)||!sxil_read(c,nt,h,24))return false;unsigned n=sxil16(h+6,false),opt=sxil16(h+20,false);if(!n||n>96)return false;uint64_t table=(uint64_t)nt+24+opt;for(unsigned i=0;i<n;i++){uint8_t s[40];if(!sxil_read(c,table+40U*i,s,40))return false;uint32_t va=sxil32(s+12,false),raw=sxil32(s+16,false),off=sxil32(s+20,false);if(rva>=va&&(uint64_t)rva-va<=raw&&bytes<=raw-(rva-va)&&sxil_span(c,(uint64_t)off+rva-va,bytes)){*out=(uint64_t)off+rva-va;return true;}}return false;}
static bool sxil_resource_name(sx_context*c,uint64_t root,uint32_t size,uint32_t field,const char*name){if(!(field&0x80000000U)||!name)return false;uint32_t at=field&0x7fffffffU;uint16_t n;if(at>size||size-at<2||!sxil_u16(c,root+at,&n)||n>64||2U*n>size-at-2)return false;for(unsigned i=0;i<n;i++){uint16_t ch;if(!name[i]||!sxil_u16(c,root+at+2+2U*i,&ch)||ch!=(uint8_t)name[i])return false;}return name[n]==0;}
static bool sxil_resource_tree(sx_context*c,uint64_t root,uint32_t span,uint32_t dir,unsigned depth,uint32_t type,uint32_t id,const char*name,unsigned*work,uint64_t*out,uint32_t*length){
 uint8_t h[16];if(depth>2||dir>span||16>span-dir||!sxil_read(c,root+dir,h,16))return false;unsigned n=(unsigned)sxil16(h+12,false)+sxil16(h+14,false);if(n>4096||(uint64_t)n*8>span-dir-16)return false;
 for(unsigned i=0;i<n&&*work<12000;i++,(*work)++){uint8_t e[8];if(!sxil_read(c,root+dir+16+8U*i,e,8))return false;uint32_t key=sxil32(e,false),next=sxil32(e+4,false);if(depth==0&&(key!=type))continue;if(depth==1&&(name?!sxil_resource_name(c,root,span,key,name):key!=id))continue;
  if(depth<2){if(!(next&0x80000000U))continue;if(sxil_resource_tree(c,root,span,next&0x7fffffffU,depth+1,type,id,name,work,out,length))return true;}
  else if(!(next&0x80000000U)&&next<=span&&16<=span-next&&sxil_read(c,root+next,h,16)){uint32_t rva=sxil32(h,false),z=sxil32(h+4,false);if(sxil_rva(c,rva,z,out)){*length=z;return true;}}
 }return false;
}
static bool sxil_resource(sx_context*c,uint32_t type,uint32_t id,const char*name,uint64_t*out,uint32_t*length){uint32_t nt;uint8_t h[24],d[8];uint16_t magic;if(!sxil_u32(c,60,&nt)||!sxil_read(c,nt,h,24)||xx_rt_memcmp(h,"PE\0\0",4)||!sxil_u16(c,(uint64_t)nt+24,&magic))return false;unsigned opt=sxil16(h+20,false),dd=magic==0x10b?96:magic==0x20b?112:0;if(!dd||opt<dd+24||!sxil_read(c,(uint64_t)nt+24+dd+16,d,8))return false;uint32_t rva=sxil32(d,false),span=sxil32(d+4,false);uint64_t root;unsigned work=0;if(!rva||!span||!sxil_rva(c,rva,span,&root))return false;return sxil_resource_tree(c,root,span,0,0,type,id,name,&work,out,length);}

static bool sxil_advanced(sx_context*c,sxil_records*r){
 uint64_t start=0,p=0;uint8_t b[74];size_t attempts=0;
 while(attempts++<100000&&sxil_find(c,(const uint8_t*)"ADVINSTSFX",10,start,(uint64_t)c->size,&p)){
  start=p+10;if(p<64||!sxil_read(c,p-64,b,74))continue;
  uint32_t mode=sxil32(b,false),ext=sxil32(b+4,false),count=sxil32(b+8,false),info=sxil32(b+20,false);
  if(mode>1||sxil32(b+12,false)!=100||sxil32(b+16,false)!=p-64||!count||count>4096||info>=p-64)continue;
  if(r->count&&r->items[0].header!=info)continue;
  if(!SXIL_ADD(c,advanced_installer_footer,p-64))return false;
  uint64_t q=info,limit=mode?ext:p-64;
  for(uint32_t i=0;i<count&&q<=limit&&24<=limit-q;i++){
   uint8_t h[24];if(!sxil_read(c,q,h,24))return true;uint64_t n=sxil32(h+20,false);if(!n||n>2048||n*2>limit-q-24)return true;
   if(!SXIL_ADD(c,advanced_installer_record,q)||!sxil_text(c,&sxil_installerlast_utf16_name,q+24,n*2))return false;q+=24+n*2;
  }
  if(mode&&ext<=p-64&&8<=p-64-ext){uint32_t n;if(sxil_u32(c,ext+4,&n)&&n<=(p-64-ext-8)/2){if(!SXIL_ADD(c,advanced_installer_external,ext)||!sxil_text(c,&sxil_installerlast_utf16_name,ext+8,(uint64_t)n*2))return false;}}
  return true;
 }
 return true;
}
static bool sxil_ardi(sx_context*c){
 if(c->size<54)return true;uint64_t end=(uint64_t)c->size-50;if(!SXIL_ADD(c,ardi_trailer,end))return false;
 for(size_t k=0;k<100000&&end>=4;k++){
  uint32_t n;if(!sxil_u32(c,end-4,&n))return true;if(n==0x98765432U)return SXIL_ADD(c,ardi_chain_start,end-4);
  if(n<8||n>end)return true;uint64_t p=end-n;uint32_t tag;if(!sxil_u32(c,p,&tag))return true;
  if(!SXIL_ADD(c,ardi_block_tag,p)||!SXIL_ADD(c,ardi_block_length,end-4))return false;
  if(tag==0x12345677U&&n>=14){if(!SXIL_ADD(c,ardi_member_time,p+4)||!sxil_name(c,p+8,n-12))return false;}
  else if(tag==0x11221122U||tag==0x97979797U||tag==0x12121212U||tag==0x13131313U){if(!sxil_name(c,p+4,n-8))return false;}
  end=p;
 }return true;
}
static bool sxil_arni(sx_context*c,sxil_records*r){
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header_size!=8||!sxil_eq(c,m->header,"ARNI",4))continue;if(!SXIL_ADD(c,arni_member,m->header))return false;uint64_t e=m->data+m->packed;if(sxil_eq(c,e,"ARNIARNI\r\n",10)&&!SXIL_ADD(c,arni_end,e))return false;}return true;
}
static bool sxil_ej(sx_context*c,sxil_records*r){
 uint64_t p;if(!sxil_pe(c,&p)||!sxil_eq(c,p,"\xd5\x13\xe4\xe8",4))return true;uint32_t n;if(!sxil_u32(c,p+4,&n)||!n||n>=1024)return true;
 if(!SXIL_ADD(c,ej_technologies_header,p))return false;p+=8;
 for(unsigned pass=0;pass<2;pass++){
  if(pass){if(!sxil_u32(c,p,&n)||n>=1024)return true;if(!SXIL_ADD(c,ej_technologies_extra_count,p))return false;p+=4;}
  for(uint32_t i=0;i<n;i++){uint32_t z;if(!sxil_u32(c,p+4,&z)||z>INT32_MAX||!sxil_span(c,p+8,z))return true;if(!SXIL_ADD(c,ej_technologies_variable,p)||!sxil_name(c,p+8,z))return false;p+=8+(uint64_t)z;}
 }
 for(size_t i=0;i<r->count;i++){
  sxil_member*m=r->items+i;if(m->header_size==4){if(!SXIL_ADD(c,ej_technologies_member,m->header))return false;}
  else if(m->header_size==8){if(!SXIL_ADD(c,ej_technologies_member_later,m->header))return false;}
  else if(m->header_size>=10){uint8_t b[2];if(!sxil_read(c,m->header,b,2))continue;uint64_t z=sxil16(b,true);if(z+10==m->header_size&&(!SXIL_ADD(c,ej_technologies_trailer_name,m->header)||!sxil_name(c,m->header+2,z)||!SXIL_ADD(c,ej_technologies_trailer_size,m->header+2+z)))return false;}
  uint64_t e=m->data+m->packed;if(sxil_eq(c,e,"\xe8\xe4\x13\xd5",4)&&!SXIL_ADD(c,ej_technologies_trailer,e))return false;
 }
 if(sxil_eq(c,p,"\xe8\xe4\x13\xd5",4)&&!SXIL_ADD(c,ej_technologies_trailer,p))return false;return true;
}
static bool sxil_zpak(sx_context*c){
 uint64_t total=(uint64_t)c->size;uint8_t b[38];uint32_t count,p;unsigned version=0;uint64_t tr=0;
 if(total>=38&&sxil_read(c,total-38,b,38)){count=sxil32(b,false);p=sxil32(b+4,false);if(count&&count<=65535&&sxil_eq(c,p,"-ZPAK\0\2\0",8)){version=2;tr=total-38;}}
 if(!version&&total>=22&&sxil_read(c,total-22,b,22)){count=sxil16(b,false);p=sxil32(b+2,false);if(count&&sxil_eq(c,p,"-ZPAK\0\1\0",8)){version=1;tr=total-22;}}
 if(!version||!SXIL_ADD(c,ibm_zpak_sfx_header,p))return !version;
 if(version==1){if(!SXIL_ADD(c,ibm_zpak_sfx_v1_trailer,tr))return false;if(count>tr/114)return true;uint64_t dir=tr-(uint64_t)count*114,q=(uint64_t)p+8;if(dir<q)return true;
  if(!sxil_put(c,&sxil_ibm_zpak_sfx_v1_directory,dir,count))return false;for(uint32_t i=0;i<count;i++){uint32_t z;if(!sxil_u32(c,dir+(uint64_t)i*114+102,&z)||z<3||z>dir-q)return true;if(!SXIL_ADD(c,installerlast_dcl_prelude,q))return false;q+=z;}}
 else{if(!SXIL_ADD(c,ibm_zpak_sfx_v2_trailer,tr))return false;uint64_t q=(uint64_t)p+8;for(uint32_t i=0;i<count&&q<=tr&&16<=tr-q;i++){uint8_t h[16];if(!sxil_read(c,q,h,16))return true;uint64_t z=sxil32(h+2,false),n=sxil16(h+14,false);if(h[0]!=10||!n||n>1024||n>tr-q-16||z<3||z>tr-q-16-n)return true;if(!SXIL_ADD(c,ibm_zpak_sfx_v2_record,q)||!sxil_name(c,q+16,n)||!SXIL_ADD(c,installerlast_dcl_prelude,q+16+n))return false;q+=16+n+z;}}
 return true;
}
static bool sxil_is_strings(sx_context*c,sxil_records*r,bool wide,bool boot){
 if(wide){uint64_t p;if(sxil_pe(c,&p)&&!SXIL_ADD(c,installshield12_count,p))return false;}
 const sx_layout*str[4]={wide?&sxil_installshield_utf16_base_name:&sxil_installshield_ansi_base_name,wide?&sxil_installshield_utf16_relative_path:&sxil_installshield_ansi_relative_path,wide?&sxil_installshield_utf16_version:&sxil_installshield_ansi_version,wide?&sxil_installerlast_utf16_size:&sxil_installerlast_decimal_size};
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;uint64_t p=m->header,end=p+m->header_size;for(unsigned k=0;k<4;k++)if(!sxil_take(c,&p,end,str[k],wide?2:1,k==3))break;if(boot&&m->packed>=14&&sxil_eq(c,m->data,"SZDD\x88\xf0\x27\x33",8)&&!SXIL_ADD(c,installshield7_szdd,m->data))return false;}return !c->failed;
}
static bool sxil_is3(sx_context*c,sxil_records*r){
 if(!r->count)return true;uint64_t p=0,start=0;uint8_t b[28];static const uint8_t magic[]={0x94,1,0,0,6,0,0,0};
 uint32_t resource_size; if(sxil_resource(c,1024,0,"MYRESOURCE",&p,&resource_size)&&resource_size>=404){if(!SXIL_ADD(c,installshield3_descriptor,p))return false;}
 while(sxil_find(c,magic,8,start,r->items[0].header,&p)){start=p+8;if(!sxil_read(c,p,b,28))break;if(sxil32(b+8,false)==r->items[0].header&&sxil32(b+12,false)>=r->count){if(!SXIL_ADD(c,installshield3_descriptor,p))return false;break;}}
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;uint32_t n;if(!sxil_u32(c,m->header,&n)||!n||n>1024||(uint64_t)n+12!=m->header_size)continue;if(!SXIL_ADD(c,installshield3_name_size,m->header)||!sxil_encoded(c,m->header+4,n)||!SXIL_ADD(c,installshield3_member,m->header+4+n))return false;}return true;
}
static bool sxil_isd(sx_context*c){uint64_t p;uint32_t n;if(!sxil_pe(c,&p)||!sxil_eq(c,p,"InstallShield\0",14)||!sxil_u32(c,p+14,&n)||!n||n>65535)return true;if(!SXIL_ADD(c,installshield_developer_header,p))return false;p+=46;for(uint32_t i=0;i<n;i++){uint32_t z;if(!sxil_u32(c,p+268,&z)||!sxil_span(c,p,312)||!sxil_span(c,p+312,z))return true;if(!SXIL_ADD(c,installshield_developer_record,p))return false;p+=312+(uint64_t)z;}return true;}
static bool sxil_ismp(sx_context*c){if(c->size<12)return true;uint64_t tr=(uint64_t)c->size-8;uint32_t p,n;if(!sxil_eq(c,tr+4,"\xca\x82\xca\x82",4)||!sxil_u32be(c,tr,&p)||p>tr||tr-p<4)return true;
 if(!SXIL_ADD(c,installshield_multiplatform_footer,tr)||!sxil_u32be(c,p,&n)||!SXIL_ADD(c,installshield_multiplatform_count,p))return false;
 uint64_t q=(uint64_t)p+4;for(uint32_t i=0;i<n&&i<100000&&q<=tr&&15<=tr-q;i++){uint8_t b[15],flag;if(!sxil_read(c,q,b,15))return true;uint64_t z=sxil16(b+13,true);if(z>tr-q-15)return true;if(!SXIL_ADD(c,installshield_multiplatform_record,q)||!sxil_name(c,q+15,z))return false;q+=15+z;if(!sxil_read(c,q,&flag,1)||flag>1)return true;if(!SXIL_ADD(c,installshield_multiplatform_optional,q))return false;q++;if(flag){if(q>tr||8>tr-q)return true;if(!SXIL_ADD(c,installshield_multiplatform_u64,q))return false;q+=8;}}return true;}
static bool sxil_skin(sx_context*c,sxil_records*r){static const uint8_t key[8]={0xa2,0x85,0x59,0xbc,0xa3,0x9f,0x3b,0xac};for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header_size>281)continue;uint8_t b[281];if(!sxil_read(c,m->header,b,(size_t)m->header_size))continue;for(uint64_t k=0;k<m->header_size;k++)b[k]=(uint8_t)((b[k]>>4)|(b[k]<<4))^key[(m->header+k)&7];uint64_t n=0;while(n<m->header_size&&b[n])n++;if(n>=m->header_size)continue;n++;if(!sxil_text(c,&sxil_installshield_skin_encoded_name,m->header,n)||!sxil_text(c,&sxil_installshield_skin_encoded_size,m->header+n,m->header_size-n))return false;}return true;}
static bool sxil_qsetup(sx_context*c){uint64_t p;if(!sxil_pe(c,&p))return true;for(unsigned k=0;k<2;k++){uint32_t n;if(!sxil_u32(c,p,&n)||n>4096||!sxil_span(c,p+4,n))return true;if(!SXIL_ADD(c,qsetup_length,p)||!sxil_name(c,p+4,n))return false;p+=4+(uint64_t)n;}
 for(size_t k=0;k<100000&&sxil_span(c,p,4);k++){uint32_t n;if(sxil_span(c,p,74)&&sxil_eq(c,p+12,"\x1d\x2c\x3b\x4a",4))return SXIL_ADD(c,qsetup_trailer,p);if(!sxil_u32(c,p,&n)||!n||!sxil_span(c,p+4,n))return true;if(!SXIL_ADD(c,qsetup_record,p))return false;p+=4+(uint64_t)n;}return true;}
static bool sxil_tarma(sx_context*c){uint64_t p;if(!sxil_pe(c,&p))return true;for(size_t k=0;k<100000&&sxil_span(c,p,72);k++){uint8_t b[72];if(!sxil_read(c,p,b,72))return true;
 if(xx_rt_memcmp(b+16,"tiz3",4)){if(sxil32(b,false)==~sxil32(b+4,false)&&!sxil32(b+8,false)&&!sxil32(b+12,false)){if(!SXIL_ADD(c,tarma_separator,p))return false;p+=16;continue;}return true;}
 if(!SXIL_ADD(c,tarma_section,p))return false;uint64_t z=(uint64_t)sxil32(b+32,false)|((uint64_t)sxil32(b+36,false)<<32);if(z<77||!sxil_span(c,p,77))return true;if(!SXIL_ADD(c,tarma_lzma_properties,p+72))return false;if(!sxil_span(c,p,z))return true;p+=z;}return true;}

/* Gentee uses the largest nonempty section end, without SizeOfHeaders. */
static bool sxil_gentee_overlay(sx_context*c,uint64_t*out){uint8_t d[64],h[24],row[40];if(!sxil_span(c,0,0x3fc)||!sxil_read(c,0,d,64)||d[0]!='M'||d[1]!='Z')return false;uint64_t lf=sxil32(d+60,false);if(lf<64||lf>0x10000||!sxil_read(c,lf,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;unsigned n=sxil16(h+6,false),opt=sxil16(h+20,false);uint64_t tab=lf+24+opt,end=0;if(!n||n>96||!sxil_span(c,tab,40U*n))return false;for(unsigned i=0;i<n;i++){if(!sxil_read(c,tab+40U*i,row,40))return false;uint64_t z=sxil32(row+16,false),p=sxil32(row+20,false);if(z&&p+z>end)end=p+z;}if(!end||!sxil_span(c,end,12))return false;*out=end;return true;}
static bool sxil_gentee_header(sx_context*c,uint64_t p){uint32_t z;return sxil_u32(c,p,&z)&&z>0&&z<0x100000&&sxil_eq(c,p+4,"\xab\x67\xa7\x36\xff\x4d\xfb\x6f",8);}
static bool sxil_gentee(sx_context*c,sxil_records*r){uint64_t overlay,p;uint32_t off;if(!sxil_gentee_overlay(c,&overlay))return true;p=overlay;
 if(sxil_u32(c,0x3f0,&off)&&off>=overlay&&sxil_gentee_header(c,off)){p=off;if(!SXIL_ADD(c,gentee_locator,0x3f0))return false;}
 else if(!sxil_gentee_header(c,p))return true;
 if(!SXIL_ADD(c,gentee_block_size,p))return false;
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header_size>=4&&m->header!=p&&!SXIL_ADD(c,gentee_block_size,m->header))return false;}return true;}
static bool sxil_createinstall(sx_context*c,sxil_records*r){
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header_size<21)continue;uint8_t b[17];if(!sxil_read(c,m->header,b,17))continue;uint64_t n=sxil16(b+15,false);if(b[0]!=1||b[14]>1||n>INT16_MAX||17+n+4!=m->header_size)continue;
  if(!SXIL_ADD(c,createinstall_record,m->header)||!sxil_name(c,m->header+17,n)||!SXIL_ADD(c,createinstall_file_size,m->header+17+n))return false;
 }
 /* Native runtime extent authenticates the beginning of the raw prelude.
  * Match the stored carrier size and a real first record; never scan codec output. */
 if(r->count>1&&r->items[0].header_size==0){uint64_t start=r->items[0].data+r->items[0].packed,end=r->items[1].header,p;uint8_t needle[4];for(unsigned i=0;i<4;i++)needle[i]=(uint8_t)((uint64_t)c->size>>(8*i));
  if(end>=start&&end-start<=0x10000&&sxil_find(c,needle,4,start,end,&p)){uint32_t z;if(sxil_u32(c,p+8,&z)&&(p+77+(uint64_t)z==end||p+79+(uint64_t)z==end)&&!SXIL_ADD(c,createinstall_prelude,p))return false;}}
 return true;
}
static bool sxil_clickteam(sx_context*c,sxil_records*r){uint64_t p;if(!sxil_pe(c,&p))return true;bool v2=sxil_eq(c,p,"wwgT)H",6);if(v2){if(!SXIL_ADD(c,clickteam_creator_tag,p))return false;p+=6;}
 for(size_t k=0;k<4096&&sxil_span(c,p,8);k++){uint8_t b[8];if(!sxil_read(c,p,b,8))return true;uint16_t id=sxil16(b,false),flags=sxil16(b+2,false);uint64_t n=sxil32(b+4,false);
  if(id==0x7f7f){if(sxil_span(c,p,12)&&!SXIL_ADD(c,clickteam_creator_data_chunk,p))return false;break;}
  if(!sxil_span(c,p+8,n))return true;if(!SXIL_ADD(c,clickteam_creator_chunk,p))return false;
  if(flags&&n>=(v2?5:4)){if(!sxil_put(c,v2?&sxil_clickteam_creator_compression2:&sxil_clickteam_creator_compression1,p+8,1))return false;}p+=8+n;
 }
 if(v2)for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;/* A native v2 record includes the method byte in its physical payload. */if(m->packed&&sxil_span(c,m->data,1)&&!SXIL_ADD(c,clickteam_creator_method,m->data))return false;}
 return true;
}
static bool sxil_vise_string(sx_context*c,uint64_t*p,uint64_t end,bool wide,bool masked){uint8_t b[2];unsigned w=wide?2:1;if(*p>end||w>end-*p||!sxil_read(c,*p,b,w))return false;uint64_t n=wide?sxil16(b,false):b[0];if(masked)n&=63;if(n>end-*p-w)return false;if(!sxil_put(c,wide?&sxil_vise_string16:masked?&sxil_vise_masked_length:&sxil_vise_string8,*p,1)||!sxil_name(c,*p+w,n))return false;*p+=w+n;return true;}
/* Match the native locator's ordered physical anchors. An ESIV byte pattern
 * inside executable code is not a container root. All coordinates are relative
 * to the current reader base; no subclass storage or ownership is borrowed. */
typedef struct sxil_vise_root {uint64_t head,wrapper,wrapper_size,footer,end,cert;} sxil_vise_root;
static bool sxil_vise_follow(sx_context*c,uint64_t pointer,uint64_t footer,sxil_vise_root*r){
 uint8_t h[12];if(pointer<64||pointer>footer||16>footer-pointer||!sxil_read(c,pointer,h,12))return false;
 if(!xx_rt_memcmp(h,"ESIV",4)){r->head=pointer;r->wrapper=UINT64_MAX;r->wrapper_size=0;return true;}
 if(!xx_rt_memcmp(h,"SIVM",4)&&!xx_rt_memcmp(h+8,"ESIV",4)&&24<=footer-pointer){r->head=pointer+8;r->wrapper=pointer;r->wrapper_size=sxil32(h+4,false);return true;}return false;
}
static bool sxil_vise_footer_is(sx_context*c,uint64_t p,uint64_t anchor){uint8_t h[8];return anchor<=UINT32_MAX&&sxil_read(c,p,h,8)&&!xx_rt_memcmp(h,"ESIV",4)&&sxil32(h+4,false)==anchor;}
static bool sxil_vise_locate(sx_context*c,sxil_vise_root*r){
 uint8_t dos[64],nt[24],sec[40],head[16];uint64_t total=(uint64_t)c->size;
 r->head=r->wrapper=r->footer=r->cert=UINT64_MAX;r->wrapper_size=0;r->end=total;
 if(total<256||!sxil_read(c,0,dos,64)||dos[0]!='M'||dos[1]!='Z')return false;
 uint64_t lf=sxil32(dos+60,false);if(lf<4||lf>0x10000000||!sxil_read(c,lf,nt,24))return false;
 if(nt[0]=='N'&&nt[1]=='E'){
  uint8_t f[8];uint64_t at=total-8;if(!sxil_read(c,at,f,8)||xx_rt_memcmp(f,"ESIV",4)||!sxil_vise_follow(c,sxil32(f+4,false),at,r))return false;r->footer=at;r->end=at;
 }else{
  if(xx_rt_memcmp(nt,"PE\0\0",4))return false;unsigned count=sxil16(nt+6,false),opt=sxil16(nt+20,false);uint64_t tab=lf+24+opt,overlay=0;
  if(!count||count>96||opt>4096||!sxil_span(c,tab,40U*count))return false;
  uint16_t magic;unsigned dd=0;if(opt>=2&&sxil_u16(c,lf+24,&magic))dd=magic==0x10b?96:magic==0x20b?112:0;
  if(dd&&opt>=dd+40){uint32_t countdir,off,size;if(sxil_u32(c,lf+24+dd-4,&countdir)&&countdir>=5&&sxil_u32(c,lf+24+dd+32,&off)&&sxil_u32(c,lf+24+dd+36,&size)&&size>=8&&off>=64&&sxil_span(c,off,size))r->cert=off;}
  for(unsigned i=0;i<count;i++){if(!sxil_read(c,tab+40U*i,sec,40))return false;uint64_t size=sxil32(sec+16,false),off=sxil32(sec+20,false);if(size&&off+size>overlay)overlay=off+size;}
  if(overlay>=64&&sxil_span(c,overlay,16)&&sxil_eq(c,overlay,"ESIV",4))r->head=overlay;
  for(unsigned i=0;r->head==UINT64_MAX&&i<count;i++){
   uint8_t w[12];if(!sxil_read(c,tab+40U*i,sec,40))return false;uint64_t size=sxil32(sec+16,false),off=sxil32(sec+20,false);
   if(size<32||off<64||!sxil_read(c,off,w,12)||xx_rt_memcmp(w,"SIVM",4)||xx_rt_memcmp(w+8,"ESIV",4))continue;
   uint64_t z=sxil32(w+4,false);if(z<24||!sxil_span(c,off,z+8))continue;r->head=off+8;r->wrapper=off;r->wrapper_size=z;
  }
  if(r->head==UINT64_MAX){
   uint64_t end=r->cert!=UINT64_MAX&&r->cert>=overlay?r->cert:total,low=end>64?end-64:0;
   if(end>=8)for(uint64_t p=end-8;;p--){uint8_t f[8];if(p<low)break;if(!sxil_read(c,p,f,8))return false;if(!xx_rt_memcmp(f,"ESIV",4)&&sxil_vise_follow(c,sxil32(f+4,false),p,r)){r->footer=p;break;}if(!p)break;}
  }
  if(r->wrapper!=UINT64_MAX&&sxil_span(c,r->wrapper,r->wrapper_size+8))r->end=r->wrapper+r->wrapper_size;
 }
 if(r->head==UINT64_MAX||!sxil_span(c,r->head,19)||!sxil_read(c,r->head,head,16)||xx_rt_memcmp(head,"ESIV",4)||sxil32(head+8,false)!=1)return false;
 if(r->footer==UINT64_MAX){
  uint64_t anchor=r->wrapper!=UINT64_MAX?r->wrapper:r->head;
  if(r->wrapper!=UINT64_MAX){uint64_t p=r->wrapper+r->wrapper_size;if(sxil_vise_footer_is(c,p,anchor))r->footer=p;}
  else{
   if(total>=r->head+24&&sxil_vise_footer_is(c,total-8,anchor))r->footer=total-8;
   if(r->footer==UINT64_MAX&&r->cert!=UINT64_MAX&&r->cert>=r->head+24){uint64_t low=r->cert>64?r->cert-64:0;for(uint64_t p=r->cert-8;p>=r->head+16&&p>=low;p--)if(sxil_vise_footer_is(c,p,anchor)){r->footer=p;break;}}
   if(r->footer==UINT64_MAX&&anchor<=UINT32_MAX){uint8_t needle[8]={'E','S','I','V',0,0,0,0};for(unsigned i=0;i<4;i++)needle[4+i]=(uint8_t)(anchor>>(8*i));uint64_t start=r->head+16,end=total;if(end-start>(UINT64_C(256)<<20))end=start+(UINT64_C(256)<<20);uint64_t p;if(sxil_find(c,needle,8,start,end,&p))r->footer=p;}
  }
 }
 if(r->footer!=UINT64_MAX)r->end=r->footer;return true;
}
static bool sxil_vise(sx_context*c,sxil_records*r){sxil_vise_root root;if(!sxil_vise_locate(c,&root))return true;uint64_t p=root.head,head=p;
 if(!SXIL_ADD(c,vise_header,p))return false;
 if(root.wrapper!=UINT64_MAX&&!SXIL_ADD(c,vise_wrapper,root.wrapper))return false;
 p+=16;for(unsigned k=0;k<3;k++)if(!sxil_vise_string(c,&p,root.end,false,k==1))return true;
 uint16_t n;if(!sxil_u16(c,p,&n)||!n)return true;if(!SXIL_ADD(c,vise_setup_count,p))return false;p+=2;
 for(unsigned i=0;i<n;i++){if(!sxil_vise_string(c,&p,root.end,false,false))return true;uint32_t z;if(!sxil_u32(c,p+12,&z)||!sxil_span(c,p+16,z))return true;if(!SXIL_ADD(c,vise_setup_fields,p))return false;p+=16+(uint64_t)z;}
 /* Authenticated member callbacks also describe second-table setup files,
  * settings frames and variant install objects. They contain physical spans. */
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header>=head&&m->header<p)continue;
  if(m->header_size==4){if(!SXIL_ADD(c,vise_packed_size,m->header))return false;continue;}
  uint8_t h[2];if(!sxil_read(c,m->header,h,2))continue;uint64_t z=h[0];if(z+17==m->header_size){if(!SXIL_ADD(c,vise_string8,m->header)||!sxil_name(c,m->header+1,z)||!SXIL_ADD(c,vise_setup_fields,m->header+1+z))return false;continue;}
  z=sxil16(h,false);for(unsigned extra=4;extra<=6;extra+=2){uint64_t at=m->header+2+z;if(m->header_size==2+z+extra+16&&sxil_span(c,at,extra+16)){uint32_t off;if(sxil_u32(c,at+extra+12,&off)&&head+(uint64_t)off==m->data){if(!SXIL_ADD(c,vise_string16,m->header)||!sxil_name(c,m->header+2,z)||!sxil_put(c,extra==4?&sxil_vise_object4:&sxil_vise_object6,at,1))return false;break;}}}
 }
 if(root.footer!=UINT64_MAX&&!SXIL_ADD(c,vise_footer,root.footer))return false;return true;
}
static bool sxil_wise(sx_context*c,sxil_records*r){uint64_t end=0;bool zip=false;for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;
 if(m->header_size>=30&&sxil_eq(c,m->header,"PK\3\4",4)){uint8_t b[30];if(!sxil_read(c,m->header,b,30))continue;uint64_t ns=sxil16(b+26,false),es=sxil16(b+28,false);if(30+ns+es!=m->header_size)continue;zip=true;if(!SXIL_ADD(c,wise_zip_local,m->header)||!sxil_name(c,m->header+30,ns))return false;end=m->data+m->packed;}
 else if(!m->header_size&&m->crc<=UINT32_MAX){uint64_t p=m->data+m->packed;for(unsigned pad=0;pad<=3;pad++){uint32_t v;if(sxil_u32(c,p+pad,&v)&&v==(uint32_t)m->crc){if(!SXIL_ADD(c,wise_member_crc32,p+pad))return false;break;}uint8_t z;if(!sxil_read(c,p+pad,&z,1)||z)break;}}
 }
 if(zip){uint64_t p=end;for(size_t k=0;k<100000;k++){if(sxil_eq(c,p,"PK\1\2",4)){uint8_t b[46];if(!sxil_read(c,p,b,46))return true;uint64_t n=sxil16(b+28,false),e=sxil16(b+30,false),z=sxil16(b+32,false);if(!sxil_span(c,p,46+n+e+z))return true;if(!SXIL_ADD(c,wise_zip_central,p)||!sxil_name(c,p+46,n)||!sxil_name(c,p+46+n+e,z))return false;p+=46+n+e+z;}
 else{if(sxil_eq(c,p,"PK\5\6",4)&&sxil_span(c,p,22)&&!SXIL_ADD(c,wise_zip_end,p))return false;break;}}}return true;}
static bool sxil_ghost_read(sx_context*c,uint64_t p,uint8_t*b,size_t n){if(!sxil_read(c,p,b,n))return false;for(size_t i=0;i<n;i++)b[i]^=0x8d;return true;}
static bool sxil_ghost_zstr(sx_context*c,uint64_t*p,uint64_t end){uint64_t first=*p;uint8_t x;for(unsigned k=0;k<4096&&*p<end;k++,(*p)++){if(!sxil_ghost_read(c,*p,&x,1))return false;if(!x){(*p)++;return sxil_encoded(c,first,*p-first);}}return false;}
static bool sxil_ghost_magic(sx_context*c,uint64_t p){return sxil_span(c,p,71)&&sxil_eq(c,p,"\xc0\xde\xce\xcb\x8d\x8d\x8d\x8d",8);}
static bool sxil_ghost_start(sx_context*c,uint64_t*out){
 if(sxil_ghost_magic(c,0)){*out=0;return true;}
 uint8_t d[64],h[24],row[40];if(!sxil_read(c,0,d,64)||d[0]!='M'||d[1]!='Z')return false;uint64_t lf=sxil32(d+60,false);
 if(lf<4||lf>0x10000||!sxil_read(c,lf,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;
 unsigned count=sxil16(h+6,false),opt=sxil16(h+20,false);if(!count||count>96)return false;uint64_t end=0,tab=lf+24+opt;
 if(opt>=64){uint32_t z;if(!sxil_u32(c,lf+24+60,&z))return false;end=z;}
 if(!sxil_span(c,tab,40U*count))return false;
 for(unsigned i=0;i<count;i++){if(!sxil_read(c,tab+40U*i,row,40))return false;uint64_t n=sxil32(row+16,false),p=sxil32(row+20,false);if(n&&p&&p+n>end)end=p+n;}
 if(!end||end>(uint64_t)c->size)return false;if(sxil_ghost_magic(c,end)){*out=end;return true;}
 if((uint64_t)c->size-end>=105){uint64_t at=(uint64_t)c->size-34;uint32_t p;if(sxil_eq(c,at+28,"GIPEND",6)&&sxil_u32(c,at,&p)&&p>=end&&sxil_ghost_magic(c,p)){*out=p;return true;}}
 return false;
}
static bool sxil_ghost(sx_context*c){uint64_t start;if(!sxil_ghost_start(c,&start))return true;
 for(unsigned seg=0;seg<64;seg++){uint8_t h[36];if(!sxil_ghost_read(c,start,h,36)||xx_rt_memcmp(h,"MSCF",4))return true;uint64_t size=sxil32(h+8,false),files=sxil32(h+16,false);unsigned nf=sxil16(h+26,false),nm=sxil16(h+28,false),flags=sxil16(h+30,false);if(size<36||!sxil_span(c,start,size)||files>size)return true;
  if(!SXIL_ADD(c,ghost_encoded_cab_header,start))return false;uint64_t p=start+36,finish=start+size;unsigned fr=0,dr=0;
  if(flags&4){uint8_t r[4];if(!sxil_ghost_read(c,p,r,4))return true;if(!SXIL_ADD(c,ghost_encoded_cab_reserve,p))return false;uint64_t n=sxil16(r,false);fr=r[2];dr=r[3];p+=4;if(p>finish||n>finish-p)return true;p+=n;}
  for(unsigned bit=1;bit<=2;bit*=2)if(flags&bit){if(!sxil_ghost_zstr(c,&p,finish)||!sxil_ghost_zstr(c,&p,finish))return true;}
  if(p>finish||(uint64_t)nf>(finish-p)/(8+fr))return true;
  for(unsigned i=0;i<nf;i++){uint8_t f[8];if(!sxil_ghost_read(c,p,f,8))return true;if(!SXIL_ADD(c,ghost_encoded_cab_folder,p))return false;uint64_t q=start+sxil32(f,false);unsigned n=sxil16(f+4,false);for(unsigned j=0;j<n;j++){uint8_t d[8];if(q>finish||8+dr>finish-q||!sxil_ghost_read(c,q,d,8))break;uint64_t z=sxil16(d+4,false);if(z>finish-q-8-dr)break;if(!SXIL_ADD(c,ghost_encoded_cab_data,q))return false;q+=8+dr+z;}p+=8+fr;}
  p=start+files;for(unsigned i=0;i<nm&&p<=finish&&16<=finish-p;i++){if(!SXIL_ADD(c,ghost_encoded_cab_file,p))return false;p+=16;if(!sxil_ghost_zstr(c,&p,finish))return true;}
  p=finish;if(sxil_eq(c,p+28,"GIPEND",6)){if(!SXIL_ADD(c,ghost_trailer34,p))return false;start=p+34;}else if(sxil_eq(c,p+20,"GIPEND",6)){if(!SXIL_ADD(c,ghost_trailer26,p))return false;start=p+26;}else return true;
 }return true;}

static uint64_t sxil64(const uint8_t*p){return (uint64_t)sxil32(p,false)|((uint64_t)sxil32(p+4,false)<<32);}
static bool sxil_inno(sx_context*c){uint8_t b[64];uint64_t table=0,header=0,data=0;unsigned generation=0;uint32_t resource_size=0;const sx_layout*row=NULL;
 if(sxil_eq(c,48,"Inno",4)){uint32_t p,np;if(!sxil_u32(c,52,&p)||!sxil_u32(c,56,&np)||p!=~np||!sxil_read(c,p,b,12))return true;table=p;if(!SXIL_ADD(c,inno_loader_pointer,48))return false;
  if(xx_rt_memcmp(b,"rDlPtS",6)||b[6]!='0'||b[7]<'2'||b[7]>'7'||xx_rt_memcmp(b+8,"\x87\x65\x56\x78",4))return true;generation=b[7]-'0';unsigned n=generation==2||generation==6?44:40;if(!sxil_read(c,table,b,n))return true;
  switch(generation){case 2:row=&sxil_inno_loader2;break;case 4:row=&sxil_inno_loader4;break;case 5:row=&sxil_inno_loader5;break;case 6:row=&sxil_inno_loader6;break;case 7:row=&sxil_inno_loader7;break;default:return true;}
  header=sxil32(b+(generation==2?36:generation==7?28:32),false);data=sxil32(b+(generation==2?40:generation==7?32:36),false);
 }else if(sxil_resource(c,10,11111,NULL,&table,&resource_size)&&resource_size>=44&&sxil_read(c,table,b,44)){
  if(xx_rt_memcmp(b,"rDlPtS\xcd\xe6\xd7\x7b\x0b\x2a",12))return true;generation=sxil32(b+12,false);
  if(generation==1){row=&sxil_inno_loader_revision1;header=sxil32(b+32,false);data=sxil32(b+36,false);}
  else if(generation==2&&resource_size>=64&&sxil_read(c,table,b,64)){row=&sxil_inno_loader_revision2;header=sxil64(b+40);data=sxil64(b+48);}else return true;
  generation+=100;
 }else return true;
 if(!sxil_put(c,row,table,1))return false;if(!sxil_read(c,header,b,64))return true;
 unsigned version[3]={0};size_t pos=0;while(pos<64&&b[pos]!='(')pos++;if(pos==64)return true;pos++;
 for(unsigned k=0;k<3;k++){unsigned digits=0;while(pos<64&&b[pos]>='0'&&b[pos]<='9'&&digits<3){version[k]=version[k]*10+b[pos++]-'0';digits++;}if(!digits)return true;if(k<2){if(pos>=64||b[pos++]!='.')return true;}}
 if(!SXIL_ADD(c,inno_setup_version,header))return false;uint64_t p=header+64;bool legacy=version[0]<4||(version[0]==4&&version[1]==0&&version[2]<9),wide=version[0]>6||(version[0]==6&&version[1]>=7);
 if(generation==102){if(!SXIL_ADD(c,inno_encryption_envelope,p))return false;p+=53;}
 for(unsigned block=0;block<2;block++){uint64_t extent;unsigned hs=legacy?12:wide?13:9;if(!sxil_read(c,p,b,hs))return true;
  if(legacy){int32_t packed=(int32_t)sxil32(b+4,false);uint64_t n=packed==-1?sxil32(b+8,false):packed<0?0:(uint32_t)packed;extent=n+4*((n+4095)/4096);}
  else extent=wide?sxil64(b+4):sxil32(b+4,false);
  if(!sxil_put(c,legacy?&sxil_inno_block_legacy:wide?&sxil_inno_block64:&sxil_inno_block32,p,1))return false;p+=hs;if(!sxil_span(c,p,extent))return true;uint64_t end=p+extent;
  for(size_t k=0;k<20000&&p<end;k++){if(end-p<4)return true;if(!SXIL_ADD(c,inno_block_crc32,p))return false;p+=4;uint64_t n=end-p<4096?end-p:4096;p+=n;}
  p=end;
 }
 if(data&&sxil_eq(c,data,"zlb\x1a",4)&&!SXIL_ADD(c,inno_data_marker,data))return false;return true;
}

static bool sx_installerlast_supports(xx_file_type_t type){switch(type){
case XX_FILE_TYPE_WISE_INSTALLATION_SYSTEM:case XX_FILE_TYPE_GENTEE_INSTALLER:case XX_FILE_TYPE_CLICKTEAM_INSTALL_CREATOR:case XX_FILE_TYPE_CREATEINSTALL_INSTCRIN_EXTRACTOR:case XX_FILE_TYPE_ADVANCED_INSTALLER_BOOTSTRAPPER:case XX_FILE_TYPE_ARDI_INSTALLER:case XX_FILE_TYPE_ARNI_INSTALLER_CONTAINER:case XX_FILE_TYPE_EJ_TECHNOLOGIES_INSTALL:case XX_FILE_TYPE_GHOST_INSTALLER:case XX_FILE_TYPE_IBM_ZPAK_INSTALLER:case XX_FILE_TYPE_INNO_SETUP:case XX_FILE_TYPE_INSTALLER_VISE_WINDOWS:case XX_FILE_TYPE_INSTALLSHIELD_12_SETUP:case XX_FILE_TYPE_INSTALLSHIELD_3:case XX_FILE_TYPE_INSTALLSHIELD_7_SETUP:case XX_FILE_TYPE_INSTALLSHIELD_7_SETUP2:case XX_FILE_TYPE_INSTALLSHIELD_DEVELOPER:case XX_FILE_TYPE_INSTALLSHIELD_MULTIPLATFORM:case XX_FILE_TYPE_INSTALLSHIELD_SKIN:case XX_FILE_TYPE_QSETUP_INSTALLATION_SUITE:case XX_FILE_TYPE_TARMA_INSTALLER:return true;default:return false;}}
static bool sx_installerlast_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;sxil_records records;if(!sxil_collect(c,&records)){if(records.items)xx_mem_free(records.items);return false;}bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_WISE_INSTALLATION_SYSTEM:ok=sxil_wise(c,&records);break;
case XX_FILE_TYPE_GENTEE_INSTALLER:ok=sxil_gentee(c,&records);break;
case XX_FILE_TYPE_CLICKTEAM_INSTALL_CREATOR:ok=sxil_clickteam(c,&records);break;
case XX_FILE_TYPE_CREATEINSTALL_INSTCRIN_EXTRACTOR:ok=sxil_createinstall(c,&records);break;
case XX_FILE_TYPE_ADVANCED_INSTALLER_BOOTSTRAPPER:ok=sxil_advanced(c,&records);break;
case XX_FILE_TYPE_ARDI_INSTALLER:ok=sxil_ardi(c);break;
case XX_FILE_TYPE_ARNI_INSTALLER_CONTAINER:ok=sxil_arni(c,&records);break;
case XX_FILE_TYPE_EJ_TECHNOLOGIES_INSTALL:ok=sxil_ej(c,&records);break;
case XX_FILE_TYPE_GHOST_INSTALLER:ok=sxil_ghost(c);break;
case XX_FILE_TYPE_IBM_ZPAK_INSTALLER:ok=sxil_zpak(c);break;
case XX_FILE_TYPE_INNO_SETUP:ok=sxil_inno(c);break;
case XX_FILE_TYPE_INSTALLER_VISE_WINDOWS:ok=sxil_vise(c,&records);break;
case XX_FILE_TYPE_INSTALLSHIELD_12_SETUP:ok=sxil_is_strings(c,&records,true,false);break;
case XX_FILE_TYPE_INSTALLSHIELD_3:ok=sxil_is3(c,&records);break;
case XX_FILE_TYPE_INSTALLSHIELD_7_SETUP:ok=sxil_is_strings(c,&records,false,false);break;
case XX_FILE_TYPE_INSTALLSHIELD_7_SETUP2:ok=sxil_is_strings(c,&records,false,true);break;
case XX_FILE_TYPE_INSTALLSHIELD_DEVELOPER:ok=sxil_isd(c);break;
case XX_FILE_TYPE_INSTALLSHIELD_MULTIPLATFORM:ok=sxil_ismp(c);break;
case XX_FILE_TYPE_INSTALLSHIELD_SKIN:ok=sxil_skin(c,&records);break;
case XX_FILE_TYPE_QSETUP_INSTALLATION_SUITE:ok=sxil_qsetup(c);break;
case XX_FILE_TYPE_TARMA_INSTALLER:ok=sxil_tarma(c);break;
default:break;}if(records.items)xx_mem_free(records.items);(void)ok;return c->count&&sxil_finish(c);}
#undef SXIL_ADD
#undef SXIL_LIMIT

