/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical installer and self-extractor metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_installerextras_scope.txt. */

static const xx_data_struct_field_desc sxiex_sbx_member_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("record_size","int32",4,4,SX_SIZE),
    SX_FIELD("dos_date","uint16",8,2,SX_NONE),
    SX_FIELD("dos_time","uint16",10,2,SX_NONE),
    SX_FIELD("attributes","uint8",12,1,SX_FLAGS),
    SX_FIELD("name_length","uint8",13,1,SX_SIZE),
};
static const sx_layout sxiex_sbx_member = {0x60820001U,"sbx_member",sxiex_sbx_member_fields,SX_COUNT(sxiex_sbx_member_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sbx_plain_size_fields[] = {
    SX_FIELD("unpacked_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxiex_sbx_plain_size = {0x60820002U,"sbx_plain_size",sxiex_sbx_plain_size_fields,SX_COUNT(sxiex_sbx_plain_size_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_installer_name_fields[] = {
    SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxiex_installer_name = {0x60820003U,"installer_name",sxiex_installer_name_fields,SX_COUNT(sxiex_installer_name_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_installer_utf16_name_fields[] = {
    SX_FIELD("name","uint16",0,0,SX_NONE),
};
static const sx_layout sxiex_installer_utf16_name = {0x60820004U,"installer_utf16_name",sxiex_installer_utf16_name_fields,SX_COUNT(sxiex_installer_utf16_name_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_installer_encoded_bytes_fields[] = {
    SX_FIELD("encoded_bytes","uint8",0,0,SX_NONE),
};
static const sx_layout sxiex_installer_encoded_bytes = {0x60820005U,"installer_encoded_bytes",sxiex_installer_encoded_bytes_fields,SX_COUNT(sxiex_installer_encoded_bytes_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ffs_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("file_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("complemented_file_count","uint32",8,4,SX_NONE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxiex_ffs_header = {0x60820006U,"ffs_header",sxiex_ffs_header_fields,SX_COUNT(sxiex_ffs_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ffs_index_fields[] = {
    SX_FIELD("filename_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("record_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxiex_ffs_index = {0x60820007U,"ffs_index",sxiex_ffs_index_fields,SX_COUNT(sxiex_ffs_index_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ffs_member_fields[] = {
    SX_FIELD("filename_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxiex_ffs_member = {0x60820008U,"ffs_member",sxiex_ffs_member_fields,SX_COUNT(sxiex_ffs_member_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ffs_cmp1_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("encoded_unpacked_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxiex_ffs_cmp1 = {0x60820009U,"ffs_cmp1",sxiex_ffs_cmp1_fields,SX_COUNT(sxiex_ffs_cmp1_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ffs_cmp2_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("encoded_unpacked_size","uint32",4,4,SX_NONE),
};
static const sx_layout sxiex_ffs_cmp2 = {0x6082000aU,"ffs_cmp2",sxiex_ffs_cmp2_fields,SX_COUNT(sxiex_ffs_cmp2_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ffs_footer_fields[] = {
    SX_FIELD("archive_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxiex_ffs_footer = {0x6082000bU,"ffs_footer",sxiex_ffs_footer_fields,SX_COUNT(sxiex_ffs_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_krzip_header_fields[] = {
    SX_FIELD("signature","char[24]",0,24,SX_SIGNATURE),
};
static const sx_layout sxiex_krzip_header = {0x6082000cU,"krzip_header",sxiex_krzip_header_fields,SX_COUNT(sxiex_krzip_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_krzip_encoded_name_length_fields[] = {
    SX_FIELD("encrypted_name_length","byte[2]",0,2,SX_NONE),
};
static const sx_layout sxiex_krzip_encoded_name_length = {0x6082000dU,"krzip_encoded_name_length",sxiex_krzip_encoded_name_length_fields,SX_COUNT(sxiex_krzip_encoded_name_length_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_krzip_encoded_fields_fields[] = {
    SX_FIELD("encrypted_dos_time","byte[2]",0,2,SX_NONE),
    SX_FIELD("encrypted_dos_date","byte[2]",2,2,SX_NONE),
    SX_FIELD("encrypted_unpacked_size","byte[4]",4,4,SX_NONE),
    SX_FIELD("encrypted_attributes","byte[4]",8,4,SX_NONE),
    SX_FIELD("encrypted_packed_size","byte[4]",12,4,SX_NONE),
    SX_FIELD("encrypted_complemented_crc32","byte[4]",16,4,SX_NONE),
};
static const sx_layout sxiex_krzip_encoded_fields = {0x6082000eU,"krzip_encoded_fields",sxiex_krzip_encoded_fields_fields,SX_COUNT(sxiex_krzip_encoded_fields_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_krzip_footer_fields[] = {
    SX_FIELD("complemented_crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxiex_krzip_footer = {0x6082000fU,"krzip_footer",sxiex_krzip_footer_fields,SX_COUNT(sxiex_krzip_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_warpin_header_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("format_revision","uint16",4,2,SX_ID),
    SX_FIELD("description","char[512]",6,512,SX_NONE),
    SX_FIELD("application_revision","uint16",518,2,SX_ID),
    SX_FIELD("operating_system","uint16",520,2,SX_ID),
    SX_FIELD("package_count","uint16",522,2,SX_COUNT_PROP),
    SX_FIELD("script_unpacked_size_low","uint16",524,2,SX_NONE),
    SX_FIELD("script_packed_size","uint16",526,2,SX_SIZE),
    SX_FIELD("optional_blob_size","int32",528,4,SX_SIZE),
};
static const sx_layout sxiex_warpin_header = {0x60820010U,"warpin_header",sxiex_warpin_header_fields,SX_COUNT(sxiex_warpin_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_warpin_extension_fields[] = {
    SX_FIELD("extension_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxiex_warpin_extension = {0x60820011U,"warpin_extension",sxiex_warpin_extension_fields,SX_COUNT(sxiex_warpin_extension_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_warpin_package_fields[] = {
    SX_FIELD("package_id","uint16",0,2,SX_ID),
    SX_FIELD("file_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("data_offset","int32",4,4,SX_OFFSET),
    SX_FIELD("unpacked_size","int32",8,4,SX_SIZE),
    SX_FIELD("packed_size","int32",12,4,SX_SIZE),
    SX_FIELD("description","char[32]",16,32,SX_NONE),
};
static const sx_layout sxiex_warpin_package = {0x60820012U,"warpin_package",sxiex_warpin_package_fields,SX_COUNT(sxiex_warpin_package_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_warpin_member_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("unknown","uint16",2,2,SX_NONE),
    SX_FIELD("method","uint16",4,2,SX_ID),
    SX_FIELD("package_id","uint16",6,2,SX_ID),
    SX_FIELD("unpacked_size","int32",8,4,SX_SIZE),
    SX_FIELD("packed_size","int32",12,4,SX_SIZE),
    SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("name","char[256]",20,256,SX_NONE),
    SX_FIELD("modification_time","uint32",276,4,SX_TIME),
    SX_FIELD("creation_time","uint32",280,4,SX_TIME),
    SX_FIELD("extension","uint8",284,1,SX_ID),
};
static const sx_layout sxiex_warpin_member = {0x60820013U,"warpin_member",sxiex_warpin_member_fields,SX_COUNT(sxiex_warpin_member_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_engine_fields[] = {
    SX_FIELD("unpacked_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxiex_instalit_engine = {0x60820014U,"instalit_engine",sxiex_instalit_engine_fields,SX_COUNT(sxiex_instalit_engine_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_footer_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("serial_number","char[12]",1,12,SX_NONE),
    SX_FIELD("script_offset","uint32",13,4,SX_OFFSET),
    SX_FIELD("catalog_end_offset","uint32",17,4,SX_OFFSET),
    SX_FIELD("packed_data_offset","uint32",21,4,SX_OFFSET),
    SX_FIELD("catalog_offset","uint32",25,4,SX_OFFSET),
};
static const sx_layout sxiex_instalit_footer = {0x60820015U,"instalit_footer",sxiex_instalit_footer_fields,SX_COUNT(sxiex_instalit_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_catalog_prefix_fields[] = {
    SX_FIELD("record_tag","uint8",0,1,SX_ID),
    SX_FIELD("data_offset","uint32",1,4,SX_OFFSET),
    SX_FIELD("method","uint8",5,1,SX_ID),
    SX_FIELD("name","char[13]",6,13,SX_NONE),
    SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
    SX_FIELD("packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("dos_date","uint16",24,2,SX_NONE),
    SX_FIELD("dos_time","uint16",26,2,SX_NONE),
};
static const sx_layout sxiex_instalit_catalog_prefix = {0x60820016U,"instalit_catalog_prefix",sxiex_instalit_catalog_prefix_fields,SX_COUNT(sxiex_instalit_catalog_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_catalog_1c55_fields[] = {
    SX_FIELD("unpacked_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("disk_number","byte[3]",4,3,SX_NONE),
    SX_FIELD("unpacked_size","uint32",7,4,SX_SIZE),
    SX_FIELD("unknown","byte[16]",11,16,SX_NONE),
};
static const sx_layout sxiex_instalit_catalog_1c55 = {0x60820017U,"instalit_catalog_1c55",sxiex_instalit_catalog_1c55_fields,SX_COUNT(sxiex_instalit_catalog_1c55_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_catalog_1c59_fields[] = {
    SX_FIELD("unpacked_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("disk_number","byte[3]",4,3,SX_NONE),
    SX_FIELD("unpacked_size","uint32",7,4,SX_SIZE),
    SX_FIELD("unknown","byte[20]",11,20,SX_NONE),
};
static const sx_layout sxiex_instalit_catalog_1c59 = {0x60820018U,"instalit_catalog_1c59",sxiex_instalit_catalog_1c59_fields,SX_COUNT(sxiex_instalit_catalog_1c59_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_catalog_1a47_fields[] = {
    SX_FIELD("unpacked_crc16","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("disk_number","byte[3]",2,3,SX_NONE),
    SX_FIELD("unpacked_size","uint32",5,4,SX_SIZE),
    SX_FIELD("unknown","byte[10]",9,10,SX_NONE),
};
static const sx_layout sxiex_instalit_catalog_1a47 = {0x60820019U,"instalit_catalog_1a47",sxiex_instalit_catalog_1a47_fields,SX_COUNT(sxiex_instalit_catalog_1a47_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_script_fields[] = {
    SX_FIELD("marker","byte[9]",0,9,SX_SIGNATURE),
};
static const sx_layout sxiex_instalit_script = {0x6082001aU,"instalit_script",sxiex_instalit_script_fields,SX_COUNT(sxiex_instalit_script_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_data_marker_fields[] = {
    SX_FIELD("marker","byte[6]",0,6,SX_SIGNATURE),
};
static const sx_layout sxiex_instalit_data_marker = {0x6082001bU,"instalit_data_marker",sxiex_instalit_data_marker_fields,SX_COUNT(sxiex_instalit_data_marker_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_abbyy_count_fields[] = {
    SX_FIELD("string_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxiex_abbyy_count = {0x6082001cU,"abbyy_count",sxiex_abbyy_count_fields,SX_COUNT(sxiex_abbyy_count_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_abbyy_string_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxiex_abbyy_string = {0x6082001dU,"abbyy_string",sxiex_abbyy_string_fields,SX_COUNT(sxiex_abbyy_string_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_abbyy_stream_size_fields[] = {
    SX_FIELD("stream_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_abbyy_stream_size = {0x6082001eU,"abbyy_stream_size",sxiex_abbyy_stream_size_fields,SX_COUNT(sxiex_abbyy_stream_size_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_abbyy_dates_fields[] = {
    SX_FIELD("first_date","uint32",0,4,SX_TIME),
    SX_FIELD("second_date","uint32",4,4,SX_TIME),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
static const sx_layout sxiex_abbyy_dates = {0x6082001fU,"abbyy_dates",sxiex_abbyy_dates_fields,SX_COUNT(sxiex_abbyy_dates_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_abbyy_finear_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("marker","byte[3]",6,3,SX_SIGNATURE),
    SX_FIELD("crc16_arc","uint32",9,4,SX_CHECKSUM),
    SX_FIELD("unpacked_size","uint32",13,4,SX_SIZE),
};
static const sx_layout sxiex_abbyy_finear = {0x60820020U,"abbyy_finear",sxiex_abbyy_finear_fields,SX_COUNT(sxiex_abbyy_finear_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_abbyy_trailer_fields[] = {
    SX_FIELD("overlay_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("signature","char[15]",4,15,SX_SIGNATURE),
};
static const sx_layout sxiex_abbyy_trailer = {0x60820021U,"abbyy_trailer",sxiex_abbyy_trailer_fields,SX_COUNT(sxiex_abbyy_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_deploymaster_record_fields[] = {
    SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_deploymaster_record = {0x60820022U,"deploymaster_record",sxiex_deploymaster_record_fields,SX_COUNT(sxiex_deploymaster_record_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_deploymaster_separator_fields[] = {
    SX_FIELD("marker","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxiex_deploymaster_separator = {0x60820023U,"deploymaster_separator",sxiex_deploymaster_separator_fields,SX_COUNT(sxiex_deploymaster_separator_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_deploymaster_bzip2_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("block_size_digit","uint8",3,1,SX_ID),
};
static const sx_layout sxiex_deploymaster_bzip2 = {0x60820024U,"deploymaster_bzip2",sxiex_deploymaster_bzip2_fields,SX_COUNT(sxiex_deploymaster_bzip2_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("install_directory_present","uint8",8,1,SX_FLAGS),
};
static const sx_layout sxiex_pimp_header = {0x60820025U,"pimp_header",sxiex_pimp_header_fields,SX_COUNT(sxiex_pimp_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_directory_fields[] = {
    SX_FIELD("default_directory","char[260]",0,260,SX_NONE),
};
static const sx_layout sxiex_pimp_directory = {0x60820026U,"pimp_directory",sxiex_pimp_directory_fields,SX_COUNT(sxiex_pimp_directory_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_text_fields[] = {
    SX_FIELD("title","char[128]",0,128,SX_NONE),
    SX_FIELD("description","char[128]",128,128,SX_NONE),
};
static const sx_layout sxiex_pimp_text = {0x60820027U,"pimp_text",sxiex_pimp_text_fields,SX_COUNT(sxiex_pimp_text_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_v1_count_fields[] = {
    SX_FIELD("file_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxiex_pimp_v1_count = {0x60820028U,"pimp_v1_count",sxiex_pimp_v1_count_fields,SX_COUNT(sxiex_pimp_v1_count_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_v2_count_fields[] = {
    SX_FIELD("unknown","uint32",0,4,SX_NONE),
    SX_FIELD("file_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxiex_pimp_v2_count = {0x60820029U,"pimp_v2_count",sxiex_pimp_v2_count_fields,SX_COUNT(sxiex_pimp_v2_count_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_name_length_fields[] = {
    SX_FIELD("name_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_pimp_name_length = {0x6082002aU,"pimp_name_length",sxiex_pimp_name_length_fields,SX_COUNT(sxiex_pimp_name_length_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_v1_sizes_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_pimp_v1_sizes = {0x6082002bU,"pimp_v1_sizes",sxiex_pimp_v1_sizes_fields,SX_COUNT(sxiex_pimp_v1_sizes_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_v2_sizes_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxiex_pimp_v2_sizes = {0x6082002cU,"pimp_v2_sizes",sxiex_pimp_v2_sizes_fields,SX_COUNT(sxiex_pimp_v2_sizes_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pimp_command_length_fields[] = {
    SX_FIELD("command_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_pimp_command_length = {0x6082002dU,"pimp_command_length",sxiex_pimp_command_length_fields,SX_COUNT(sxiex_pimp_command_length_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_softpaq_fit1_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
    SX_FIELD("reserved","uint8",12,1,SX_RESERVED),
    SX_FIELD("file_size","int32",13,4,SX_SIZE),
    SX_FIELD("file_offset","int32",17,4,SX_OFFSET),
};
static const sx_layout sxiex_softpaq_fit1 = {0x6082002eU,"softpaq_fit1",sxiex_softpaq_fit1_fields,SX_COUNT(sxiex_softpaq_fit1_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_softpaq_fit2_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
    SX_FIELD("reserved","uint8",12,1,SX_RESERVED),
    SX_FIELD("file_size","int32",13,4,SX_SIZE),
    SX_FIELD("file_offset","int32",17,4,SX_OFFSET),
    SX_FIELD("dos_date","uint16",21,2,SX_NONE),
    SX_FIELD("dos_time","uint16",23,2,SX_NONE),
};
static const sx_layout sxiex_softpaq_fit2 = {0x6082002fU,"softpaq_fit2",sxiex_softpaq_fit2_fields,SX_COUNT(sxiex_softpaq_fit2_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_wasp_resource_shift_fields[] = {
    SX_FIELD("alignment_shift","uint16",0,2,SX_NONE),
};
static const sx_layout sxiex_wasp_resource_shift = {0x60820030U,"wasp_resource_shift",sxiex_wasp_resource_shift_fields,SX_COUNT(sxiex_wasp_resource_shift_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_wasp_resource_type_fields[] = {
    SX_FIELD("type_identifier","uint16",0,2,SX_ID),
    SX_FIELD("resource_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
static const sx_layout sxiex_wasp_resource_type = {0x60820031U,"wasp_resource_type",sxiex_wasp_resource_type_fields,SX_COUNT(sxiex_wasp_resource_type_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_wasp_resource_entry_fields[] = {
    SX_FIELD("offset_units","uint16",0,2,SX_NONE),
    SX_FIELD("length_units","uint16",2,2,SX_NONE),
    SX_FIELD("flags","uint16",4,2,SX_FLAGS),
    SX_FIELD("resource_identifier","uint16",6,2,SX_ID),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
static const sx_layout sxiex_wasp_resource_entry = {0x60820032U,"wasp_resource_entry",sxiex_wasp_resource_entry_fields,SX_COUNT(sxiex_wasp_resource_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_wasp_string_length_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxiex_wasp_string_length = {0x60820033U,"wasp_string_length",sxiex_wasp_string_length_fields,SX_COUNT(sxiex_wasp_string_length_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_wasp_payload_size_fields[] = {
    SX_FIELD("payload_size","ascii_decimal",0,0,SX_SIZE),
};
static const sx_layout sxiex_wasp_payload_size = {0x60820034U,"wasp_payload_size",sxiex_wasp_payload_size_fields,SX_COUNT(sxiex_wasp_payload_size_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfxstart_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("payload_size","uint32",8,4,SX_SIZE),
    SX_FIELD("last_file_index","uint32",12,4,SX_NONE),
};
static const sx_layout sxiex_sfxstart_header = {0x60820035U,"sfxstart_header",sxiex_sfxstart_header_fields,SX_COUNT(sxiex_sfxstart_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfxstart_name_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("name_length","uint32",1,4,SX_SIZE),
};
static const sx_layout sxiex_sfxstart_name = {0x60820036U,"sfxstart_name",sxiex_sfxstart_name_fields,SX_COUNT(sxiex_sfxstart_name_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfxstart_size_fields[] = {
    SX_FIELD("marker","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("file_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxiex_sfxstart_size = {0x60820037U,"sfxstart_size",sxiex_sfxstart_size_fields,SX_COUNT(sxiex_sfxstart_size_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfxstart_separator_fields[] = {
    SX_FIELD("marker","byte[3]",0,3,SX_SIGNATURE),
};
static const sx_layout sxiex_sfxstart_separator = {0x60820038U,"sfxstart_separator",sxiex_sfxstart_separator_fields,SX_COUNT(sxiex_sfxstart_separator_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfxstart_command_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("command_length","uint32",1,4,SX_SIZE),
};
static const sx_layout sxiex_sfxstart_command = {0x60820039U,"sfxstart_command",sxiex_sfxstart_command_fields,SX_COUNT(sxiex_sfxstart_command_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfxstart_footer_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("header_offset","uint32",1,4,SX_OFFSET),
};
static const sx_layout sxiex_sfxstart_footer = {0x6082003aU,"sfxstart_footer",sxiex_sfxstart_footer_fields,SX_COUNT(sxiex_sfxstart_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_clickteam_pack_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("secondary_signature","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("pack_size","uint32",12,4,SX_SIZE),
    SX_FIELD("unknown","uint32",16,4,SX_NONE),
    SX_FIELD("reserved1","uint32",20,4,SX_RESERVED),
    SX_FIELD("reserved2","uint32",24,4,SX_RESERVED),
    SX_FIELD("file_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxiex_clickteam_pack = {0x6082003bU,"clickteam_pack",sxiex_clickteam_pack_fields,SX_COUNT(sxiex_clickteam_pack_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_clickteam_name_fields[] = {
    SX_FIELD("name_length","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxiex_clickteam_name = {0x6082003cU,"clickteam_name",sxiex_clickteam_name_fields,SX_COUNT(sxiex_clickteam_name_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_clickteam_size_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_clickteam_size = {0x6082003dU,"clickteam_size",sxiex_clickteam_size_fields,SX_COUNT(sxiex_clickteam_size_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_clickteam_checksum_size_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxiex_clickteam_checksum_size = {0x6082003eU,"clickteam_checksum_size",sxiex_clickteam_checksum_size_fields,SX_COUNT(sxiex_clickteam_checksum_size_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_jugglor_member_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("name_length","uint8",4,1,SX_SIZE),
    SX_FIELD("name_storage","char[255]",5,255,SX_NONE),
    SX_FIELD("directory_length","uint8",260,1,SX_SIZE),
    SX_FIELD("directory_storage","char[255]",261,255,SX_NONE),
    SX_FIELD("unused_string_length","uint8",516,1,SX_SIZE),
    SX_FIELD("unused_string_storage","byte[255]",517,255,SX_NONE),
    SX_FIELD("unpacked_size","uint32",772,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",776,4,SX_SIZE),
    SX_FIELD("local_filetime","uint64",780,8,SX_TIME),
    SX_FIELD("unknown","byte[4]",788,4,SX_NONE),
    SX_FIELD("end_signature","uint32",792,4,SX_SIGNATURE),
};
static const sx_layout sxiex_jugglor_member = {0x6082003fU,"jugglor_member",sxiex_jugglor_member_fields,SX_COUNT(sxiex_jugglor_member_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_exeattachment_member_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("name_length","uint8",4,1,SX_SIZE),
    SX_FIELD("name_storage","char[255]",5,255,SX_NONE),
    SX_FIELD("directory_length","uint8",260,1,SX_SIZE),
    SX_FIELD("directory_storage","char[255]",261,255,SX_NONE),
    SX_FIELD("unpacked_size","uint32",516,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",520,4,SX_SIZE),
    SX_FIELD("local_filetime","uint64",524,8,SX_TIME),
    SX_FIELD("unknown","byte[8]",532,8,SX_NONE),
    SX_FIELD("end_signature","uint32",540,4,SX_SIGNATURE),
};
static const sx_layout sxiex_exeattachment_member = {0x60820040U,"exeattachment_member",sxiex_exeattachment_member_fields,SX_COUNT(sxiex_exeattachment_member_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_jugglor_trailer_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("overlay_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("chain_size","uint32",8,4,SX_SIZE),
    SX_FIELD("file_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("producer_value","uint32",16,4,SX_NONE),
    SX_FIELD("unpacked_size_sum","uint32",20,4,SX_SIZE),
    SX_FIELD("version_length","uint8",24,1,SX_SIZE),
    SX_FIELD("version_storage","char[187]",25,187,SX_NONE),
    SX_FIELD("unknown","uint32",212,4,SX_NONE),
    SX_FIELD("end_signature","uint32",216,4,SX_SIGNATURE),
};
static const sx_layout sxiex_jugglor_trailer = {0x60820041U,"jugglor_trailer",sxiex_jugglor_trailer_fields,SX_COUNT(sxiex_jugglor_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_exeattachment_trailer_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("unknown","byte[270]",4,270,SX_NONE),
    SX_FIELD("end_signature","uint32",274,4,SX_SIGNATURE),
};
static const sx_layout sxiex_exeattachment_trailer = {0x60820042U,"exeattachment_trailer",sxiex_exeattachment_trailer_fields,SX_COUNT(sxiex_exeattachment_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ebook_creator_header_fields[] = {
    SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
    SX_FIELD("list_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("new_class_marker","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("directory_schema","uint16",6,2,SX_ID),
    SX_FIELD("directory_class_name_length","uint16",8,2,SX_SIZE),
    SX_FIELD("directory_class_name","char[10]",10,10,SX_NONE),
    SX_FIELD("list_identifier","uint16",20,2,SX_ID),
    SX_FIELD("file_count","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("new_element_marker","uint16",24,2,SX_SIGNATURE),
    SX_FIELD("element_schema","uint16",26,2,SX_ID),
    SX_FIELD("element_class_name_length","uint16",28,2,SX_SIZE),
    SX_FIELD("element_class_name","char[11]",30,11,SX_NONE),
    SX_FIELD("element_identifier","uint16",41,2,SX_ID),
};
static const sx_layout sxiex_ebook_creator_header = {0x60820043U,"ebook_creator_header",sxiex_ebook_creator_header_fields,SX_COUNT(sxiex_ebook_creator_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ebook_creator_member_fields[] = {
    SX_FIELD("block_size","int32",0,4,SX_SIZE),
    SX_FIELD("unpacked_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxiex_ebook_creator_member = {0x60820044U,"ebook_creator_member",sxiex_ebook_creator_member_fields,SX_COUNT(sxiex_ebook_creator_member_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ebook_creator_ref_fields[] = {
    SX_FIELD("class_reference","uint16",0,2,SX_ID),
    SX_FIELD("element_identifier","uint16",2,2,SX_ID),
};
static const sx_layout sxiex_ebook_creator_ref = {0x60820045U,"ebook_creator_ref",sxiex_ebook_creator_ref_fields,SX_COUNT(sxiex_ebook_creator_ref_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ebook_creator_list_fields[] = {
    SX_FIELD("class_reference","uint16",0,2,SX_ID),
    SX_FIELD("list_identifier","uint16",2,2,SX_ID),
    SX_FIELD("element_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxiex_ebook_creator_list = {0x60820046U,"ebook_creator_list",sxiex_ebook_creator_list_fields,SX_COUNT(sxiex_ebook_creator_list_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ebook_creator_element_fields[] = {
    SX_FIELD("class_reference","uint16",0,2,SX_ID),
    SX_FIELD("element_type","uint16",2,2,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxiex_ebook_creator_element = {0x60820047U,"ebook_creator_element",sxiex_ebook_creator_element_fields,SX_COUNT(sxiex_ebook_creator_element_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ebook_creator_name_fields[] = {
    SX_FIELD("file_index","uint32",0,4,SX_NONE),
    SX_FIELD("flags1","uint32",4,4,SX_FLAGS),
    SX_FIELD("flags2","uint32",8,4,SX_FLAGS),
    SX_FIELD("flags3","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxiex_ebook_creator_name = {0x60820048U,"ebook_creator_name",sxiex_ebook_creator_name_fields,SX_COUNT(sxiex_ebook_creator_name_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_ebook_creator_footer_fields[] = {
    SX_FIELD("overlay_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("signature","char[2]",4,2,SX_SIGNATURE),
};
static const sx_layout sxiex_ebook_creator_footer = {0x60820049U,"ebook_creator_footer",sxiex_ebook_creator_footer_fields,SX_COUNT(sxiex_ebook_creator_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sbook_header_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("signature","char[5]",4,5,SX_SIGNATURE),
    SX_FIELD("unknown","uint32",9,4,SX_NONE),
};
static const sx_layout sxiex_sbook_header = {0x6082004aU,"sbook_header",sxiex_sbook_header_fields,SX_COUNT(sxiex_sbook_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sbook_count_fields[] = {
    SX_FIELD("count_or_zero","uint32",0,4,SX_NONE),
};
static const sx_layout sxiex_sbook_count = {0x6082004bU,"sbook_count",sxiex_sbook_count_fields,SX_COUNT(sxiex_sbook_count_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sbook_name_length_fields[] = {
    SX_FIELD("name_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_sbook_name_length = {0x6082004cU,"sbook_name_length",sxiex_sbook_name_length_fields,SX_COUNT(sxiex_sbook_name_length_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sbook_member_fields[] = {
    SX_FIELD("dos_datetime","uint32",0,4,SX_NONE),
    SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
};
static const sx_layout sxiex_sbook_member = {0x6082004dU,"sbook_member",sxiex_sbook_member_fields,SX_COUNT(sxiex_sbook_member_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sbook_chunk_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_sbook_chunk = {0x6082004eU,"sbook_chunk",sxiex_sbook_chunk_fields,SX_COUNT(sxiex_sbook_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sbook_footer_fields[] = {
    SX_FIELD("zero1","uint32",0,4,SX_RESERVED),
    SX_FIELD("zero2","uint32",4,4,SX_RESERVED),
    SX_FIELD("overlay_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxiex_sbook_footer = {0x6082004fU,"sbook_footer",sxiex_sbook_footer_fields,SX_COUNT(sxiex_sbook_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pftw_settings_size_fields[] = {
    SX_FIELD("settings_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxiex_pftw_settings_size = {0x60820050U,"pftw_settings_size",sxiex_pftw_settings_size_fields,SX_COUNT(sxiex_pftw_settings_size_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pftw_settings_new_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxiex_pftw_settings_new = {0x60820051U,"pftw_settings_new",sxiex_pftw_settings_new_fields,SX_COUNT(sxiex_pftw_settings_new_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pftw_settings_old_fields[] = {
    SX_FIELD("encoded_signature","byte[3]",0,3,SX_NONE),
    SX_FIELD("encoded_version","byte[1]",3,1,SX_NONE),
    SX_FIELD("encoded_cabinet_size","byte[4]",4,4,SX_NONE),
};
static const sx_layout sxiex_pftw_settings_old = {0x60820052U,"pftw_settings_old",sxiex_pftw_settings_old_fields,SX_COUNT(sxiex_pftw_settings_old_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pftw_cab_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("reserved1","uint32",4,4,SX_RESERVED),
    SX_FIELD("cabinet_size","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved2","uint32",12,4,SX_RESERVED),
    SX_FIELD("files_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("reserved3","uint32",20,4,SX_RESERVED),
    SX_FIELD("version_minor","uint8",24,1,SX_ID),
    SX_FIELD("version_major","uint8",25,1,SX_ID),
    SX_FIELD("folder_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("file_count","uint16",28,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",30,2,SX_FLAGS),
    SX_FIELD("set_identifier","uint16",32,2,SX_ID),
    SX_FIELD("cabinet_index","uint16",34,2,SX_NONE),
};
static const sx_layout sxiex_pftw_cab_header = {0x60820053U,"pftw_cab_header",sxiex_pftw_cab_header_fields,SX_COUNT(sxiex_pftw_cab_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pftw_cab_reserve_fields[] = {
    SX_FIELD("header_reserved_size","uint16",0,2,SX_SIZE),
    SX_FIELD("folder_reserved_size","uint8",2,1,SX_SIZE),
    SX_FIELD("data_reserved_size","uint8",3,1,SX_SIZE),
};
static const sx_layout sxiex_pftw_cab_reserve = {0x60820054U,"pftw_cab_reserve",sxiex_pftw_cab_reserve_fields,SX_COUNT(sxiex_pftw_cab_reserve_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pftw_cab_folder_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_block_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("compression_type","uint16",6,2,SX_ID),
};
static const sx_layout sxiex_pftw_cab_folder = {0x60820055U,"pftw_cab_folder",sxiex_pftw_cab_folder_fields,SX_COUNT(sxiex_pftw_cab_folder_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pftw_cab_file_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
    SX_FIELD("folder_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("folder_index","uint16",8,2,SX_NONE),
    SX_FIELD("dos_date","uint16",10,2,SX_NONE),
    SX_FIELD("dos_time","uint16",12,2,SX_NONE),
    SX_FIELD("attributes","uint16",14,2,SX_FLAGS),
};
static const sx_layout sxiex_pftw_cab_file = {0x60820056U,"pftw_cab_file",sxiex_pftw_cab_file_fields,SX_COUNT(sxiex_pftw_cab_file_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_pftw_cab_data_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
    SX_FIELD("unpacked_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxiex_pftw_cab_data = {0x60820057U,"pftw_cab_data",sxiex_pftw_cab_data_fields,SX_COUNT(sxiex_pftw_cab_data_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfx_red_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("version","uint8",2,1,SX_ID),
    SX_FIELD("header_size","uint8",3,1,SX_SIZE),
    SX_FIELD("dos_time","uint16",4,2,SX_NONE),
    SX_FIELD("dos_date","uint16",6,2,SX_NONE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
    SX_FIELD("crc1","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("crc2","uint16",18,2,SX_CHECKSUM),
    SX_FIELD("fragment_index","uint16",20,2,SX_NONE),
    SX_FIELD("last_fragment_index","uint16",22,2,SX_NONE),
    SX_FIELD("method","uint16",24,2,SX_ID),
};
static const sx_layout sxiex_sfx_red_header = {0x60820058U,"sfx_red_header",sxiex_sfx_red_header_fields,SX_COUNT(sxiex_sfx_red_header_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfx_red_name_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
};
static const sx_layout sxiex_sfx_red_name = {0x60820059U,"sfx_red_name",sxiex_sfx_red_name_fields,SX_COUNT(sxiex_sfx_red_name_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfx_red_short_name_fields[] = {
    SX_FIELD("name","char[11]",0,11,SX_NONE),
};
static const sx_layout sxiex_sfx_red_short_name = {0x6082005aU,"sfx_red_short_name",sxiex_sfx_red_short_name_fields,SX_COUNT(sxiex_sfx_red_short_name_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_sfx_red_crc16_fields[] = {
    SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxiex_sfx_red_crc16 = {0x6082005bU,"sfx_red_crc16",sxiex_sfx_red_crc16_fields,SX_COUNT(sxiex_sfx_red_crc16_fields),SX_BE};

static const xx_data_struct_field_desc sxiex_instalit_resource_shift_fields[] = {
    SX_FIELD("alignment_shift","uint16",0,2,SX_NONE),
};
static const sx_layout sxiex_instalit_resource_shift = {0x6082005cU,"instalit_resource_shift",sxiex_instalit_resource_shift_fields,SX_COUNT(sxiex_instalit_resource_shift_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_resource_type_fields[] = {
    SX_FIELD("type_identifier","uint16",0,2,SX_ID),
    SX_FIELD("resource_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
static const sx_layout sxiex_instalit_resource_type = {0x6082005dU,"instalit_resource_type",sxiex_instalit_resource_type_fields,SX_COUNT(sxiex_instalit_resource_type_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_resource_entry_fields[] = {
    SX_FIELD("offset_units","uint16",0,2,SX_NONE),
    SX_FIELD("length_units","uint16",2,2,SX_NONE),
    SX_FIELD("flags","uint16",4,2,SX_FLAGS),
    SX_FIELD("resource_identifier","uint16",6,2,SX_ID),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
static const sx_layout sxiex_instalit_resource_entry = {0x6082005eU,"instalit_resource_entry",sxiex_instalit_resource_entry_fields,SX_COUNT(sxiex_instalit_resource_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_resource_end_fields[] = {
    SX_FIELD("type_terminator","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxiex_instalit_resource_end = {0x6082005fU,"instalit_resource_end",sxiex_instalit_resource_end_fields,SX_COUNT(sxiex_instalit_resource_end_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_instalit_resource_name_length_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxiex_instalit_resource_name_length = {0x60820060U,"instalit_resource_name_length",sxiex_instalit_resource_name_length_fields,SX_COUNT(sxiex_instalit_resource_name_length_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_wasp_name_separator_fields[] = {
    SX_FIELD("separator","char[1]",0,1,SX_NONE),
};
static const sx_layout sxiex_wasp_name_separator = {0x60820061U,"wasp_name_separator",sxiex_wasp_name_separator_fields,SX_COUNT(sxiex_wasp_name_separator_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_wasp_run_marker_fields[] = {
    SX_FIELD("run_after_extract","char[1]",0,1,SX_NONE),
};
static const sx_layout sxiex_wasp_run_marker = {0x60820062U,"wasp_run_marker",sxiex_wasp_run_marker_fields,SX_COUNT(sxiex_wasp_run_marker_fields),SX_LE};

static const xx_data_struct_field_desc sxiex_wasp_resource_end_fields[] = {
    SX_FIELD("type_terminator","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxiex_wasp_resource_end = {0x60820063U,"wasp_resource_end",sxiex_wasp_resource_end_fields,SX_COUNT(sxiex_wasp_resource_end_fields),SX_LE};

static const sx_layout *const sx_installerextras_layouts[] = {
    &sxiex_sbx_member,
    &sxiex_sbx_plain_size,
    &sxiex_installer_name,
    &sxiex_installer_utf16_name,
    &sxiex_installer_encoded_bytes,
    &sxiex_ffs_header,
    &sxiex_ffs_index,
    &sxiex_ffs_member,
    &sxiex_ffs_cmp1,
    &sxiex_ffs_cmp2,
    &sxiex_ffs_footer,
    &sxiex_krzip_header,
    &sxiex_krzip_encoded_name_length,
    &sxiex_krzip_encoded_fields,
    &sxiex_krzip_footer,
    &sxiex_warpin_header,
    &sxiex_warpin_extension,
    &sxiex_warpin_package,
    &sxiex_warpin_member,
    &sxiex_instalit_engine,
    &sxiex_instalit_footer,
    &sxiex_instalit_catalog_prefix,
    &sxiex_instalit_catalog_1c55,
    &sxiex_instalit_catalog_1c59,
    &sxiex_instalit_catalog_1a47,
    &sxiex_instalit_script,
    &sxiex_instalit_data_marker,
    &sxiex_abbyy_count,
    &sxiex_abbyy_string,
    &sxiex_abbyy_stream_size,
    &sxiex_abbyy_dates,
    &sxiex_abbyy_finear,
    &sxiex_abbyy_trailer,
    &sxiex_deploymaster_record,
    &sxiex_deploymaster_separator,
    &sxiex_deploymaster_bzip2,
    &sxiex_pimp_header,
    &sxiex_pimp_directory,
    &sxiex_pimp_text,
    &sxiex_pimp_v1_count,
    &sxiex_pimp_v2_count,
    &sxiex_pimp_name_length,
    &sxiex_pimp_v1_sizes,
    &sxiex_pimp_v2_sizes,
    &sxiex_pimp_command_length,
    &sxiex_softpaq_fit1,
    &sxiex_softpaq_fit2,
    &sxiex_wasp_resource_shift,
    &sxiex_wasp_resource_type,
    &sxiex_wasp_resource_entry,
    &sxiex_wasp_string_length,
    &sxiex_wasp_payload_size,
    &sxiex_sfxstart_header,
    &sxiex_sfxstart_name,
    &sxiex_sfxstart_size,
    &sxiex_sfxstart_separator,
    &sxiex_sfxstart_command,
    &sxiex_sfxstart_footer,
    &sxiex_clickteam_pack,
    &sxiex_clickteam_name,
    &sxiex_clickteam_size,
    &sxiex_clickteam_checksum_size,
    &sxiex_jugglor_member,
    &sxiex_exeattachment_member,
    &sxiex_jugglor_trailer,
    &sxiex_exeattachment_trailer,
    &sxiex_ebook_creator_header,
    &sxiex_ebook_creator_member,
    &sxiex_ebook_creator_ref,
    &sxiex_ebook_creator_list,
    &sxiex_ebook_creator_element,
    &sxiex_ebook_creator_name,
    &sxiex_ebook_creator_footer,
    &sxiex_sbook_header,
    &sxiex_sbook_count,
    &sxiex_sbook_name_length,
    &sxiex_sbook_member,
    &sxiex_sbook_chunk,
    &sxiex_sbook_footer,
    &sxiex_pftw_settings_size,
    &sxiex_pftw_settings_new,
    &sxiex_pftw_settings_old,
    &sxiex_pftw_cab_header,
    &sxiex_pftw_cab_reserve,
    &sxiex_pftw_cab_folder,
    &sxiex_pftw_cab_file,
    &sxiex_pftw_cab_data,
    &sxiex_sfx_red_header,
    &sxiex_sfx_red_name,
    &sxiex_sfx_red_short_name,
    &sxiex_sfx_red_crc16,
    &sxiex_instalit_resource_shift,
    &sxiex_instalit_resource_type,
    &sxiex_instalit_resource_entry,
    &sxiex_instalit_resource_end,
    &sxiex_instalit_resource_name_length,
    &sxiex_wasp_name_separator,
    &sxiex_wasp_run_marker,
    &sxiex_wasp_resource_end,
};

static bool sx_installerextras_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60820000U||id>=0x60830000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    switch(id){
    case 0x60820001U:
        if(!xx_rt_wcscmp(r->name,L"record_size"))s=L"Whole record byte size, including this header, name, size word and compressed body";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x60820003U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Stored legacy byte string; codepage depends on the installer";
        break;
    case 0x60820004U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Stored UTF-16LE code units";
        break;
    case 0x60820005U:
        if(!xx_rt_wcscmp(r->name,L"encoded_bytes"))s=L"Encoded physical bytes; not the decoded member representation";
        break;
    case 0x60820006U:
        if(!xx_rt_wcscmp(r->name,L"complemented_file_count"))s=L"Bitwise complement of the stored file count";
        break;
    case 0x60820007U:
        if(!xx_rt_wcscmp(r->name,L"filename_crc32"))s=L"CRC32 of the upper-case member name";
        else if(!xx_rt_wcscmp(r->name,L"record_offset"))s=L"Offset in original executable; carved FFS images may require an inferred common offset bias";
        break;
    case 0x60820009U:
        if(!xx_rt_wcscmp(r->name,L"encoded_unpacked_size"))s=L"Uncompressed byte size";
        break;
    case 0x6082000aU:
        if(!xx_rt_wcscmp(r->name,L"encoded_unpacked_size"))s=L"Bitwise complement of the uncompressed byte size";
        break;
    case 0x6082000bU:
        if(!xx_rt_wcscmp(r->name,L"archive_offset"))s=L"Offset from the original executable start";
        break;
    case 0x6082000dU:
        if(!xx_rt_wcscmp(r->name,L"encrypted_name_length"))s=L"XOR-obfuscated little-endian name byte length";
        break;
    case 0x6082000eU:
        if(!xx_rt_wcscmp(r->name,L"encrypted_dos_time"))s=L"XOR-obfuscated packed DOS time";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_dos_date"))s=L"XOR-obfuscated packed DOS date";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_unpacked_size"))s=L"XOR-obfuscated little-endian unpacked byte size";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_attributes"))s=L"XOR-obfuscated attribute word";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_packed_size"))s=L"XOR-obfuscated little-endian packed byte size";
        else if(!xx_rt_wcscmp(r->name,L"encrypted_complemented_crc32"))s=L"XOR-obfuscated complemented member CRC32";
        break;
    case 0x6082000fU:
        if(!xx_rt_wcscmp(r->name,L"complemented_crc32"))s=L"Bitwise complement of CRC32 over the deobfuscated record stream";
        break;
    case 0x60820010U:
        if(!xx_rt_wcscmp(r->name,L"script_unpacked_size_low"))s=L"Low 16 bits of the script uncompressed byte size";
        break;
    case 0x60820011U:
        if(!xx_rt_wcscmp(r->name,L"extension_size"))s=L"Includes this size word; remaining extension fields are undocumented";
        break;
    case 0x60820012U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Package data offset; native reader accepts package-relative or original-file-relative values with a common bias";
        break;
    case 0x60820013U:
        if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 stored; 1 bzip2";
        else if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Stored member checksum; native reader does not authenticate this algorithm";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Unix timestamp in seconds";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Unix timestamp in seconds";
        else if(!xx_rt_wcscmp(r->name,L"extension"))s=L"Native reader supports extension zero";
        break;
    case 0x60820015U:
        if(!xx_rt_wcscmp(r->name,L"script_offset"))s=L"Offset within the associated volume; may refer to another file";
        else if(!xx_rt_wcscmp(r->name,L"packed_data_offset"))s=L"Volume-zero PVL marker offset";
        else if(!xx_rt_wcscmp(r->name,L"catalog_offset"))s=L"PVM marker offset";
        break;
    case 0x60820016U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Offset relative to the packed data body of its disk volume";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x60820017U:
        if(!xx_rt_wcscmp(r->name,L"disk_number"))s=L"Stored three-byte disk volume identifier";
        break;
    case 0x60820018U:
        if(!xx_rt_wcscmp(r->name,L"disk_number"))s=L"Stored three-byte disk volume identifier";
        break;
    case 0x60820019U:
        if(!xx_rt_wcscmp(r->name,L"disk_number"))s=L"Stored three-byte disk volume identifier";
        break;
    case 0x6082001dU:
        if(!xx_rt_wcscmp(r->name,L"length"))s=L"Length of the following Windows-1251 byte string";
        break;
    case 0x6082001eU:
        if(!xx_rt_wcscmp(r->name,L"stream_size"))s=L"Complete physical FINEAR stream size";
        break;
    case 0x6082001fU:
        if(!xx_rt_wcscmp(r->name,L"first_date"))s=L"Unix seconds at local midnight, as stored by the producer";
        else if(!xx_rt_wcscmp(r->name,L"second_date"))s=L"Unix seconds at local midnight, as stored by the producer";
        break;
    case 0x60820020U:
        if(!xx_rt_wcscmp(r->name,L"crc16_arc"))s=L"Stored CRC16/ARC in a 32-bit word";
        break;
    case 0x60820022U:
        if(!xx_rt_wcscmp(r->name,L"compressed_size"))s=L"Size of the following physical zlib stream";
        break;
    case 0x60820023U:
        if(!xx_rt_wcscmp(r->name,L"marker"))s=L"0xFFFFFFFF separates bzip2 engine and length-prefixed zlib records";
        break;
    case 0x60820024U:
        if(!xx_rt_wcscmp(r->name,L"block_size_digit"))s=L"ASCII digit 1..9; nominal block size in 100000-byte units";
        break;
    case 0x6082002aU:
        if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Stored name length including the terminating NUL";
        break;
    case 0x6082002dU:
        if(!xx_rt_wcscmp(r->name,L"command_length"))s=L"Stored command length including NUL when present";
        break;
    case 0x6082002eU:
        if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"Offset from the executable beginning";
        break;
    case 0x6082002fU:
        if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"Offset from the executable beginning";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x60820030U:
        if(!xx_rt_wcscmp(r->name,L"alignment_shift"))s=L"Resource physical offsets and allocation lengths are shifted left by this number of bits";
        break;
    case 0x60820031U:
        if(!xx_rt_wcscmp(r->name,L"type_identifier"))s=L"High bit denotes integer ID; otherwise resource-table-relative string offset";
        break;
    case 0x60820032U:
        if(!xx_rt_wcscmp(r->name,L"offset_units"))s=L"Physical byte offset = stored value shifted by the resource alignment shift";
        else if(!xx_rt_wcscmp(r->name,L"length_units"))s=L"Allocated byte length = stored value shifted by the resource alignment shift";
        else if(!xx_rt_wcscmp(r->name,L"resource_identifier"))s=L"High bit denotes integer ID; otherwise resource-table-relative string offset";
        break;
    case 0x60820034U:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Declared payload byte size in the member metadata string";
        break;
    case 0x60820035U:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Byte size after this header, including the command trailer";
        else if(!xx_rt_wcscmp(r->name,L"last_file_index"))s=L"File count minus one";
        break;
    case 0x6082003cU:
        if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Character count; one-byte legacy or UTF-16LE encoding is chosen by the authenticated native variant";
        break;
    case 0x6082003eU:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Rolling rotate-left-one sum of little-endian dwords followed by remaining bytes";
        break;
    case 0x6082003fU:
        if(!xx_rt_wcscmp(r->name,L"local_filetime"))s=L"Windows FILETIME ticks in the producer's local time convention";
        break;
    case 0x60820040U:
        if(!xx_rt_wcscmp(r->name,L"local_filetime"))s=L"Windows FILETIME ticks in the producer's local time convention";
        break;
    case 0x60820041U:
        if(!xx_rt_wcscmp(r->name,L"producer_value"))s=L"Zero in later builds; 797 in the observed Jester Jugglor 1.01 variant";
        break;
    case 0x60820044U:
        if(!xx_rt_wcscmp(r->name,L"block_size"))s=L"Includes the following unpacked-size word, excludes this block-size word";
        break;
    case 0x60820048U:
        if(!xx_rt_wcscmp(r->name,L"file_index"))s=L"One-based file index";
        break;
    case 0x6082004bU:
        if(!xx_rt_wcscmp(r->name,L"count_or_zero"))s=L"File count in the first record; zero separator in subsequent records";
        break;
    case 0x6082004dU:
        if(!xx_rt_wcscmp(r->name,L"dos_datetime"))s=L"Packed DOS date in high half and time in low half";
        break;
    case 0x6082004eU:
        if(!xx_rt_wcscmp(r->name,L"packed_size"))s=L"Size of the following zlib chunk; all nonfinal chunks decode to 16384 bytes";
        break;
    case 0x60820050U:
        if(!xx_rt_wcscmp(r->name,L"settings_size"))s=L"Physical settings byte size; settings may be XOR-obfuscated";
        break;
    case 0x60820052U:
        if(!xx_rt_wcscmp(r->name,L"encoded_signature"))s=L"Alphabetic XOR encoding of SCG";
        else if(!xx_rt_wcscmp(r->name,L"encoded_cabinet_size"))s=L"Alphabetic XOR encoding of little-endian cabinet byte size";
        break;
    case 0x60820053U:
        if(!xx_rt_wcscmp(r->name,L"files_offset"))s=L"Relative to the cabinet start";
        break;
    case 0x60820055U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to cabinet start";
        break;
    case 0x60820056U:
        if(!xx_rt_wcscmp(r->name,L"folder_offset"))s=L"Uncompressed byte offset within the folder stream; not a physical file offset";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        else if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        break;
    case 0x60820058U:
        if(!xx_rt_wcscmp(r->name,L"dos_time"))s=L"Packed DOS clock time";
        else if(!xx_rt_wcscmp(r->name,L"dos_date"))s=L"Packed DOS calendar date";
        break;
    case 0x6082005aU:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"39-byte RED variant shares its twelfth name byte with the header checksum";
        break;
    case 0x6082005cU:
        if(!xx_rt_wcscmp(r->name,L"alignment_shift"))s=L"Resource offsets and allocation lengths use 2^shift byte units";
        break;
    case 0x6082005dU:
        if(!xx_rt_wcscmp(r->name,L"type_identifier"))s=L"High bit denotes integer ID; otherwise offset from resource table start to Pascal type name";
        break;
    case 0x6082005eU:
        if(!xx_rt_wcscmp(r->name,L"offset_units"))s=L"Physical byte offset equals this word shifted by alignment_shift";
        else if(!xx_rt_wcscmp(r->name,L"length_units"))s=L"Allocated byte length equals this word shifted by alignment_shift";
        else if(!xx_rt_wcscmp(r->name,L"resource_identifier"))s=L"High bit denotes integer ID; otherwise offset from resource table start to Pascal resource name";
        break;
    case 0x6082005fU:
        if(!xx_rt_wcscmp(r->name,L"type_terminator"))s=L"Zero terminates resource type rows";
        break;
    case 0x60820060U:
        if(!xx_rt_wcscmp(r->name,L"name_length"))s=L"Byte length of the following resource-table Pascal string";
        break;
    case 0x60820061U:
        if(!xx_rt_wcscmp(r->name,L"separator"))s=L"Comma separating the stored filename from its decimal payload size";
        break;
    case 0x60820062U:
        if(!xx_rt_wcscmp(r->name,L"run_after_extract"))s=L"Asterisk requests execution after extraction; this reader never executes it";
        break;
    case 0x60820063U:
        if(!xx_rt_wcscmp(r->name,L"type_terminator"))s=L"Zero terminates resource type rows";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
#define SXIEX_LIMIT 24000U
static bool sxiex_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
static bool sxiex_read(sx_context*c,uint64_t p,void*b,size_t n){return sxiex_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxiex16(const uint8_t*b,bool be){return be?((uint16_t)b[0]<<8)|b[1]:(uint16_t)b[0]|((uint16_t)b[1]<<8);}
static uint32_t sxiex32(const uint8_t*b,bool be){return be?((uint32_t)b[0]<<24)|((uint32_t)b[1]<<16)|((uint32_t)b[2]<<8)|b[3]:(uint32_t)b[0]|((uint32_t)b[1]<<8)|((uint32_t)b[2]<<16)|((uint32_t)b[3]<<24);}
static bool sxiex_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>UINT64_MAX/z||!sxiex_span(c,p,count*z))return false;if(!count||c->count>=SXIEX_LIMIT)return true;return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);}
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!sxiex_span(c,p,n))return false;if(!n||n>4096||c->count>=SXIEX_LIMIT)return true;return sx_add(c,l,(int64_t)p,(int64_t)n);}
static int sxiex_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;if(x->offset!=y->offset)return x->offset<y->offset?-1:1;if(x->total_size!=y->total_size)return x->total_size<y->total_size?-1:1;return x->id<y->id?-1:x->id>y->id;}
static bool sxiex_finish(sx_context*c){size_t n=c->count,kept=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxiex_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end)continue;c->items[kept++]=c->items[i];end=p+z;}c->count=kept;n=kept;end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxiex_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
typedef struct sxiex_member { uint64_t header,header_size,data,packed; } sxiex_member;
typedef struct sxiex_records { sxiex_member *items; size_t count; } sxiex_records;
/* Borrow the authenticated native iterator, copy only physical coordinates,
 * and release it before inspecting bytes. No subclass assumptions or ownership transfer. */
static bool sxiex_collect(sx_context*c,sxiex_records*out){
 Abstractformat*f=c->f;out->items=NULL;out->count=0;
 if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return true;
 xx_archive_record_state*state=(f->create_archive_records_reading)(f,NULL,c->pd);if(!state)return true;
 sxiex_member*v=xx_mem_alloc(SXIEX_LIMIT*sizeof(*v));if(!v){(f->free_archive_records_reading)(f,state);return false;}
 for(size_t i=0;i<SXIEX_LIMIT&&!xx_pd_is_stopped(c->pd);i++){
  const xx_archive_record*r=(f->get_current_archive_record)(f,state);if(!r)break;
  if(r->header_offset>=f->base_address&&r->header_size>=0&&r->data_offset>=f->base_address&&r->compressed_size>=0){
   uint64_t p=(uint64_t)(r->header_offset-f->base_address),d=(uint64_t)(r->data_offset-f->base_address),h=(uint64_t)r->header_size,z=(uint64_t)r->compressed_size;
   if(sxiex_span(c,p,h)&&sxiex_span(c,d,z))v[out->count++]=(sxiex_member){p,h,d,z};
  }
  if(!(f->archive_record_move_to_next)(f,state,c->pd))break;
 }
 (f->free_archive_records_reading)(f,state);out->items=v;return !xx_pd_is_stopped(c->pd);
}
static bool sxiex_u32(sx_context*c,uint64_t p,uint32_t*v){uint8_t b[4];if(!sxiex_read(c,p,b,4))return false;*v=sxiex32(b,false);return true;}
static bool sxiex_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxiex_read(c,p,b,2))return false;*v=sxiex16(b,false);return true;}
static bool sxiex_eq(sx_context*c,uint64_t p,const void*s,size_t n){uint8_t b[32];return n<=sizeof(b)&&sxiex_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static bool sxiex_name(sx_context*c,uint64_t p,uint64_t n){return sxiex_text(c,&sxiex_installer_name,p,n);}
static bool sxiex_encoded(sx_context*c,uint64_t p,uint64_t n){return sxiex_text(c,&sxiex_installer_encoded_bytes,p,n);}
static bool sxiex_zstr(sx_context*c,uint64_t*p,uint64_t end){uint64_t start=*p;uint8_t x;for(uint64_t k=0;k<4096&&*p<end;k++,(*p)++){if(!sxiex_read(c,*p,&x,1))return false;if(!x){(*p)++;return sxiex_name(c,start,*p-start);}}return false;}
/* This carrier walk locates an installer overlay only. It emits no PE fields. */
static bool sxiex_pe(sx_context*c,uint64_t*out){
 uint8_t d[64],h[24],o[64],s[40];if(!sxiex_read(c,0,d,64)||d[0]!='M'||d[1]!='Z')return false;
 uint64_t at=sxiex32(d+60,false);if(!sxiex_read(c,at,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;
 uint16_t count=sxiex16(h+6,false),opt=sxiex16(h+20,false);if(!count||count>96||opt<64||!sxiex_read(c,at+24,o,64))return false;
 uint64_t end=sxiex32(o+60,false),tab=at+24+opt;if(!sxiex_span(c,0,end)||!sxiex_span(c,tab,(uint64_t)count*40))return false;
 for(unsigned i=0;i<count;i++){if(!sxiex_read(c,tab+40U*i,s,40))return false;uint64_t p=sxiex32(s+20,false),n=sxiex32(s+16,false);if(!sxiex_span(c,p,n))return false;if(n&&p+n>end)end=p+n;}
 *out=end;return true;
}

static bool sxiex_sbx(sx_context*c,const sxiex_records*r){
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint8_t h[14];if(m->header_size<18||!sxiex_read(c,m->header,h,14)||xx_rt_memcmp(h,"SB1\0",4))continue;uint64_t n=h[13];if(m->header_size!=18+n)continue;if(!SXIEX_ADD(c,sbx_member,m->header)||!sxiex_name(c,m->header+14,n)||!SXIEX_ADD(c,sbx_plain_size,m->header+14+n))return false;}return true;
}
static bool sxiex_krzip(sx_context*c,const sxiex_records*r){
 uint64_t p;if(sxiex_pe(c,&p)&&sxiex_eq(c,p,"<KRZIP FILE BEGINS HERE>",24)&&!SXIEX_ADD(c,krzip_header,p))return false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size<23||m->header_size>1046)continue;uint64_t n=m->header_size-22;if(!SXIEX_ADD(c,krzip_encoded_name_length,m->header)||!sxiex_encoded(c,m->header+2,n)||!SXIEX_ADD(c,krzip_encoded_fields,m->header+2+n))return false;}
 return c->size<4||SXIEX_ADD(c,krzip_footer,(uint64_t)c->size-4);
}
static bool sxiex_ffs(sx_context*c,const sxiex_records*r){
 uint64_t p=0;uint8_t h[16];uint32_t tail;
 if(!sxiex_eq(c,0,"FFS!",4)){if(c->size<4||!sxiex_u32(c,(uint64_t)c->size-4,&tail))return true;p=tail;if(!sxiex_eq(c,p,"FFS!",4))return true;if(!SXIEX_ADD(c,ffs_footer,(uint64_t)c->size-4))return false;}
 if(!sxiex_read(c,p,h,16))return true;uint32_t n=sxiex32(h+4,false);if(n!=~sxiex32(h+8,false)||!sxiex_span(c,p+16,(uint64_t)n*8))return true;
 if(!SXIEX_ADD(c,ffs_header,p)||!sxiex_put(c,&sxiex_ffs_index,p+16,n))return false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size==8&&!SXIEX_ADD(c,ffs_member,m->header))return false;if(m->packed>=8){if(sxiex_eq(c,m->data,"FFC!",4)){if(!SXIEX_ADD(c,ffs_cmp1,m->data))return false;}else if(sxiex_eq(c,m->data,"FFC@",4)&&!SXIEX_ADD(c,ffs_cmp2,m->data))return false;}}
 return true;
}
static bool sxiex_warpin(sx_context*c,const sxiex_records*r){
 uint8_t h[532];if(!sxiex_read(c,0,h,sizeof(h))||sxiex32(h,false)!=0xbe020477U)return true;
 if(!SXIEX_ADD(c,warpin_header,0))return false;uint64_t at=532;uint16_t rev=sxiex16(h+4,false),count=sxiex16(h+522,false),packed=sxiex16(h+526,false);uint32_t optional=sxiex32(h+528,false);
 if(rev==4){uint32_t n;if(!sxiex_u32(c,at,&n)||n<40||!sxiex_span(c,at,n))return true;if(!SXIEX_ADD(c,warpin_extension,at))return false;at+=n;}
 if(!sxiex_span(c,at,(uint64_t)packed+optional))return true;at+=packed+optional;
 if(sxiex_span(c,at,(uint64_t)count*48)&&!sxiex_put(c,&sxiex_warpin_package,at,count))return false;
 for(size_t i=0;i<r->count;i++)if(r->items[i].header_size==285&&sxiex_eq(c,r->items[i].header,"\x12\xf0",2)&&!SXIEX_ADD(c,warpin_member,r->items[i].header))return false;
 return true;
}
static bool sxiex_pimp(sx_context*c,const sxiex_records*r){
 uint64_t p,at;uint8_t dir;if(!sxiex_pe(c,&p)||!sxiex_eq(c,p,"PIMPFILE",8)||!sxiex_read(c,p+8,&dir,1))return true;
 if(!SXIEX_ADD(c,pimp_header,p))return false;at=p+9;if(dir){if(!sxiex_span(c,at,260))return true;if(!SXIEX_ADD(c,pimp_directory,at))return false;at+=260;}
 if(!sxiex_span(c,at,256))return true;if(!SXIEX_ADD(c,pimp_text,at))return false;at+=256;
 bool known=false,v2=false;for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header==at+8){known=true;v2=true;break;}if(m->header==at+4){known=true;break;}}
 if(!known)return true;if(!sxiex_put(c,v2?&sxiex_pimp_v2_count:&sxiex_pimp_v1_count,at,1))return false;
 uint64_t end=0;for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint32_t n;if(!sxiex_u32(c,m->header,&n)||m->header_size!=(uint64_t)n+(v2?12:8)||n>1024)continue;
 if(!SXIEX_ADD(c,pimp_name_length,m->header)||!sxiex_name(c,m->header+4,n)||!sxiex_put(c,v2?&sxiex_pimp_v2_sizes:&sxiex_pimp_v1_sizes,m->header+4+n,1))return false;if(m->data+m->packed>end)end=m->data+m->packed;}
 uint32_t n;if(end&&sxiex_u32(c,end,&n)&&n<=65536&&sxiex_span(c,end+4,n)){if(!SXIEX_ADD(c,pimp_command_length,end)||!sxiex_name(c,end+4,n))return false;}
 return true;
}
static bool sxiex_softpaq(sx_context*c,const sxiex_records*r){
 uint64_t first=UINT64_MAX,last=0,stride=0;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size!=21&&m->header_size!=25)continue;if(!sxiex_put(c,m->header_size==21?&sxiex_softpaq_fit1:&sxiex_softpaq_fit2,m->header,1))return false;if(m->header<first)first=m->header;if(m->header+m->header_size>last)last=m->header+m->header_size;stride=m->header_size;}
 if(stride&&first>=stride&&sxiex_eq(c,first-stride,"US_PCU.DOS",10)&&!sxiex_put(c,stride==21?&sxiex_softpaq_fit1:&sxiex_softpaq_fit2,first-stride,1))return false;
 if(stride&&sxiex_span(c,last,stride)&&sxiex_eq(c,last,stride==21?"FIT001":"FIT002",6)&&!sxiex_put(c,stride==21?&sxiex_softpaq_fit1:&sxiex_softpaq_fit2,last,1))return false;
 return true;
}
static bool sxiex_sfxstart(sx_context*c,const sxiex_records*r){
 uint64_t p=0;uint32_t footer;if(!sxiex_pe(c,&p)||!sxiex_eq(c,p,"SFXSTART",8)){if(c->size<4||!sxiex_u32(c,(uint64_t)c->size-4,&footer)||!sxiex_eq(c,footer,"SFXSTART",8))return true;p=footer;}
 if(!sxiex_span(c,p,16)||!SXIEX_ADD(c,sfxstart_header,p))return false;uint64_t end=0;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint8_t h[5];if(!sxiex_read(c,m->header,h,5)||h[0]!='*')continue;uint64_t n=sxiex32(h+1,false);if(!n||n>255||m->header_size!=11+n)continue;
 if(!SXIEX_ADD(c,sfxstart_name,m->header)||!sxiex_name(c,m->header+5,n)||!SXIEX_ADD(c,sfxstart_size,m->header+5+n))return false;
 uint64_t e=m->data+m->packed;if(sxiex_eq(c,e,"->\xf0",3)){if(!SXIEX_ADD(c,sfxstart_separator,e))return false;e+=3;}if(e>end)end=e;}
 uint8_t h[5];if(end&&sxiex_read(c,end,h,5)&&h[0]=='+'){uint64_t n=sxiex32(h+1,false);if(n<=65536&&sxiex_span(c,end+5,n+5)&&sxiex_eq(c,end+5+n,"-",1)){if(!SXIEX_ADD(c,sfxstart_command,end)||!sxiex_name(c,end+5,n)||!SXIEX_ADD(c,sfxstart_footer,end+5+n))return false;}}
 return true;
}
static bool sxiex_jugglor(sx_context*c,const sxiex_records*r){
 uint64_t end=0;bool jugglor=false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size!=796&&m->header_size!=544)continue;jugglor=m->header_size==796;if(!sxiex_put(c,jugglor?&sxiex_jugglor_member:&sxiex_exeattachment_member,m->header,1))return false;
 uint64_t e=m->data+m->packed;if(!jugglor&&sxiex_span(c,e,278)&&sxiex_eq(c,e,"\xa3\x61\x4a\x6a",4)&&!SXIEX_ADD(c,exeattachment_trailer,e))return false;if(e>end)end=e;}
 if(jugglor&&end&&sxiex_span(c,end,220)&&sxiex_eq(c,end,"\xa3\x61\x4a\x6a",4)&&!SXIEX_ADD(c,jugglor_trailer,end))return false;return true;
}
static bool sxiex_deploy(sx_context*c,const sxiex_records*r){
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;
 if(m->header_size==4){uint32_t z;if(sxiex_u32(c,m->header,&z)&&z==m->packed&&!SXIEX_ADD(c,deploymaster_record,m->header))return false;}
 if(m->header_size==0&&m->packed>=4&&sxiex_eq(c,m->data,"BZh",3)){if(!SXIEX_ADD(c,deploymaster_bzip2,m->data))return false;uint64_t end=m->data+m->packed;if(sxiex_eq(c,end,"\xff\xff\xff\xff",4)){if(!SXIEX_ADD(c,deploymaster_separator,end))return false;uint64_t q=end+4;for(unsigned j=0;j<2;j++){uint32_t z;if(!sxiex_u32(c,q,&z)||!sxiex_span(c,q+4,z))break;if(!SXIEX_ADD(c,deploymaster_record,q))return false;q+=4+z;}}}}
 return true;
}

static bool sxiex_cab(sx_context*c,uint64_t p,uint64_t span){
 uint8_t h[36],b[8];if(span<36||!sxiex_read(c,p,h,36)||xx_rt_memcmp(h,"MSCF",4))return true;
 uint64_t total=sxiex32(h+8,false),files=sxiex32(h+16,false),at=p+36;uint16_t folders=sxiex16(h+26,false),count=sxiex16(h+28,false),flags=sxiex16(h+30,false);unsigned fr=0,dr=0;
 if(total>span||total<36)return true;uint64_t end=p+total;if(!SXIEX_ADD(c,pftw_cab_header,p))return false;
 if(flags&4){if(end-at<4||!sxiex_read(c,at,b,4))return true;if(!SXIEX_ADD(c,pftw_cab_reserve,at))return false;fr=b[2];dr=b[3];uint64_t z=sxiex16(b,false);if(z>end-at-4)return true;at+=4+z;}
 if(flags&3)return true;if((uint64_t)folders*(8+fr)>end-at)return true;uint64_t first=end;
 for(unsigned i=0;i<folders;i++){uint64_t q=at+(uint64_t)i*(8+fr);if(!sxiex_read(c,q,b,8)||!SXIEX_ADD(c,pftw_cab_folder,q))return false;uint64_t data=sxiex32(b,false);unsigned n=sxiex16(b+4,false);if(data>total)continue;data+=p;if(data<first)first=data;
  for(unsigned j=0;j<n;j++){if(data>end||end-data<8+dr||!sxiex_read(c,data,b,8))break;uint64_t z=sxiex16(b+4,false);if(z>end-data-8-dr)break;if(!SXIEX_ADD(c,pftw_cab_data,data))return false;data+=8+dr+z;}
 }
 if(files>total)return true;at=p+files;for(unsigned i=0;i<count;i++){if(at>first||first-at<16)break;if(!SXIEX_ADD(c,pftw_cab_file,at))return false;at+=16;if(!sxiex_zstr(c,&at,first))break;}return true;
}
static bool sxiex_pftw(sx_context*c,const sxiex_records*r){
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->packed<36||!sxiex_eq(c,m->data,"MSCF",4))continue;if(!sxiex_cab(c,m->data,m->packed))return false;
  uint64_t candidate[3]={UINT64_MAX,UINT64_MAX,UINT64_MAX};sxiex_pe(c,candidate);uint8_t d[64],h[24],s[40];
  if(sxiex_read(c,0,d,64)){uint64_t nt=sxiex32(d+60,false);if(sxiex_read(c,nt,h,24)){unsigned count=sxiex16(h+6,false),opt=sxiex16(h+20,false);if(count<=96)for(unsigned j=0;j<count;j++)if(sxiex_read(c,nt+24+opt+(uint64_t)j*40,s,40)&&!xx_rt_memcmp(s,"_cabinet",8)){candidate[1]=sxiex32(s+20,false);candidate[2]=candidate[1]+12;}}}
  for(unsigned j=0;j<3;j++){uint64_t p=candidate[j];uint32_t z;if(p==UINT64_MAX||!sxiex_u32(c,p,&z)||z<16||z>1048576||p+4+(uint64_t)z!=m->data)continue;
   if(!SXIEX_ADD(c,pftw_settings_size,p))return false;if(sxiex_eq(c,p+4,"\xdc\xed\xbd\xa9",4)){if(!SXIEX_ADD(c,pftw_settings_new,p+4))return false;}else if(!SXIEX_ADD(c,pftw_settings_old,p+4))return false;break;}
 }
 return true;
}
static bool sxiex_red(sx_context*c,const sxiex_records*r){
 for(size_t i=0;i<r->count;i++){uint64_t p=r->items[i].data,end=p+r->items[i].packed;unsigned rows=0;while(end-p>=39&&rows++<SXIEX_LIMIT){uint8_t h[26];if(!sxiex_read(c,p,h,26)||xx_rt_memcmp(h,"RR\1",3))break;uint64_t hs=h[3],packed=sxiex32(h+8,false);unsigned method=sxiex16(h+24,false);if(hs<39||hs>end-p||packed>end-p-hs)break;
  if(!SXIEX_ADD(c,sfx_red_header,p)||!sxiex_put(c,hs==39?&sxiex_sfx_red_short_name:&sxiex_sfx_red_name,p+26,1)||!SXIEX_ADD(c,sfx_red_crc16,p+hs-2))return false;
  uint64_t data=p+hs;if(method==11){uint64_t q=data,remaining=packed;while(remaining){uint64_t z=remaining>4096?4096:remaining;if(z>=2&&!SXIEX_ADD(c,sfx_red_crc16,q+z-2))return false;q+=z;remaining-=z;}}p=data+packed;
 }}return true;
}

static bool sxiex_abbyy(sx_context*c,const sxiex_records*r){
 uint64_t p=0,at;uint32_t n,z;uint8_t q;
 if(c->size>=19&&sxiex_eq(c,(uint64_t)c->size-15,"ArcUpdateABBYY\0",15)&&sxiex_u32(c,(uint64_t)c->size-19,&z)){p=z;if(!SXIEX_ADD(c,abbyy_trailer,(uint64_t)c->size-19))return false;}else if(!sxiex_pe(c,&p))return true;
 at=p;if(!sxiex_u32(c,at,&n)||n>65535)return true;if(!SXIEX_ADD(c,abbyy_count,at))return false;at+=4;
 for(unsigned group=0;group<3;group++){
  for(uint32_t i=0;i<n;i++){if(!sxiex_read(c,at,&q,1)||!sxiex_span(c,at+1,q))return true;if(!SXIEX_ADD(c,abbyy_string,at)||!sxiex_name(c,at+1,q))return false;at+=1+q;}
  if(group==0){uint32_t count;if(!sxiex_u32(c,at,&count)||count!=n)return true;if(!SXIEX_ADD(c,abbyy_count,at))return false;at+=4;if(!sxiex_span(c,at,(uint64_t)n*4))return true;if(!sxiex_put(c,&sxiex_abbyy_stream_size,at,n))return false;at+=(uint64_t)n*4;if(!sxiex_u32(c,at,&n)||n>65535)return true;if(!SXIEX_ADD(c,abbyy_count,at))return false;at+=4;}
  else if(group==1)n=3;
 }
 if(sxiex_span(c,at,12)&&!SXIEX_ADD(c,abbyy_dates,at))return false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size==17&&sxiex_eq(c,m->header,"FINEAR",6)&&!SXIEX_ADD(c,abbyy_finear,m->header))return false;}
 return true;
}
static bool sxiex_instalit_resources(sx_context*c){
 uint8_t dos[64],ne[40],row[12];if(!sxiex_read(c,0,dos,64)||dos[0]!='M'||dos[1]!='Z')return true;
 uint64_t np=sxiex32(dos+60,false);if(!sxiex_read(c,np,ne,40)||ne[0]!='N'||ne[1]!='E')return true;
 uint64_t start=np+sxiex16(ne+36,false),end=np+sxiex16(ne+38,false);uint16_t shift;
 if(end<=start||end-start<4||!sxiex_span(c,start,end-start)||!sxiex_u16(c,start,&shift)||shift>15)return true;
 if(!SXIEX_ADD(c,instalit_resource_shift,start))return false;uint64_t p=start+2;
 for(unsigned types=0;types<1024&&end-p>=2;types++){
  uint16_t type,n;if(!sxiex_u16(c,p,&type))return false;if(!type){if(!SXIEX_ADD(c,instalit_resource_end,p))return false;break;}
  if(end-p<8||!sxiex_read(c,p,row,8))break;n=sxiex16(row+2,false);if((uint64_t)n*12>end-p-8)break;
  if(!SXIEX_ADD(c,instalit_resource_type,p))return false;p+=8;
  for(unsigned i=0;i<=n;i++){
   uint16_t id=type;if(i<n){if(!sxiex_read(c,p+(uint64_t)i*12,row,12))return false;id=sxiex16(row+6,false);if(!SXIEX_ADD(c,instalit_resource_entry,p+(uint64_t)i*12))return false;}
   if(!(id&0x8000U)&&id<end-start){uint8_t z;uint64_t q=start+id;if(sxiex_read(c,q,&z,1)&&z<=end-q-1){if(!SXIEX_ADD(c,instalit_resource_name_length,q)||!sxiex_name(c,q+1,z))return false;}}
  }
  p+=(uint64_t)n*12;
 }
 return true;
}
static bool sxiex_instalit(sx_context*c,const sxiex_records*r){
 if(!sxiex_instalit_resources(c))return false;
 uint8_t foot[29];if(c->size>=29&&sxiex_read(c,(uint64_t)c->size-29,foot,29)&&foot[0]==12){bool digits=true;for(unsigned i=1;i<13;i++)if(foot[i]<'0'||foot[i]>'9')digits=false;
 if(digits){if(!SXIEX_ADD(c,instalit_footer,(uint64_t)c->size-29))return false;uint64_t p=sxiex32(foot+21,false);if(sxiex_eq(c,p,"\x05[PVL]",6)&&!SXIEX_ADD(c,instalit_data_marker,p))return false;p=sxiex32(foot+25,false);if(sxiex_eq(c,p,"\x05[PVM]",6)&&!SXIEX_ADD(c,instalit_data_marker,p))return false;}}
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint8_t tag;if(!sxiex_read(c,m->header,&tag,1))continue;
 if(m->header_size==8){if(!SXIEX_ADD(c,instalit_engine,m->header))return false;}
 else if(m->header_size==9&&sxiex_eq(c,m->header,"\x08[SCRIPT]",9)){if(!SXIEX_ADD(c,instalit_script,m->header))return false;}
 else if((tag==0x1c&&(m->header_size==55||m->header_size==59))||(tag==0x1a&&m->header_size==47)){
  if(!SXIEX_ADD(c,instalit_catalog_prefix,m->header)||!sxiex_put(c,tag==0x1a?&sxiex_instalit_catalog_1a47:m->header_size==55?&sxiex_instalit_catalog_1c55:&sxiex_instalit_catalog_1c59,m->header+28,1))return false;}
 }
 return true;
}
static bool sxiex_clickteam(sx_context*c,const sxiex_records*r){
 uint64_t p=0;if(!sxiex_pe(c,&p)||!sxiex_eq(c,p,"wwww",4))return true;if(!SXIEX_ADD(c,clickteam_pack,p))return false;
 bool known=false,unicode=false,two=false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint16_t n;if(m->header!=p+32||!sxiex_u16(c,m->header,&n)||!n)continue;unsigned choices=0;
 for(unsigned u=0;u<2;u++)for(unsigned t=0;t<2;t++){uint64_t nb=(uint64_t)n*(u+1);uint32_t z,crc;if(m->header_size!=2+nb+(t?8:4)||!sxiex_u32(c,m->header+2+nb+(t?4:0),&z)||z!=m->packed)continue;if(t&&(!sxiex_u32(c,m->header+2+nb,&crc)||crc))continue;unicode=u!=0;two=t!=0;choices++;}known=choices==1;break;}
 if(!known)return true;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint16_t n;if(!m->header_size||!sxiex_u16(c,m->header,&n))continue;uint64_t nb=(uint64_t)n*(unicode?2:1);if(m->header_size!=2+nb+(two?8:4))continue;
 if(!SXIEX_ADD(c,clickteam_name,m->header)||!sxiex_text(c,unicode?&sxiex_installer_utf16_name:&sxiex_installer_name,m->header+2,nb)||!sxiex_put(c,two?&sxiex_clickteam_checksum_size:&sxiex_clickteam_size,m->header+2+nb,1))return false;}
 return true;
}
static bool sxiex_ebook(sx_context*c,const sxiex_records*r){
 uint64_t p=0;uint32_t v;if(!sxiex_pe(c,&p))return true;
 if(sxiex_eq(c,p,"\0\0\x02\0\xff\xff",6)){
  if(!sxiex_span(c,p,43)||!SXIEX_ADD(c,ebook_creator_header,p))return false;uint64_t end=0;
  for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size!=27&&m->header_size!=12)continue;if(m->header_size==12&&!SXIEX_ADD(c,ebook_creator_ref,m->header))return false;if(!SXIEX_ADD(c,ebook_creator_member,m->data-8))return false;if(m->data+m->packed>end)end=m->data+m->packed;}
  uint8_t h[8];if(end&&sxiex_read(c,end,h,6)&&sxiex16(h,false)==0x8001){uint16_t n=sxiex16(h+4,false);if(!SXIEX_ADD(c,ebook_creator_list,end))return false;uint64_t at=end+6;
   for(unsigned i=0;i<n&&i<24000;i++){if(!sxiex_read(c,at,h,8))break;uint64_t z=sxiex32(h+4,false);if(sxiex16(h,false)!=0x8003||!sxiex_span(c,at+8,z))break;if(!SXIEX_ADD(c,ebook_creator_element,at))return false;
    if(sxiex16(h+2,false)==2){uint64_t q=at+8,e=q+z;while(q<e){if(!sxiex_zstr(c,&q,e)||e-q<16)break;if(!SXIEX_ADD(c,ebook_creator_name,q))return false;q+=16;}}at+=8+z;}
  }
  if(c->size>=6&&sxiex_u32(c,(uint64_t)c->size-6,&v)&&v==p&&!SXIEX_ADD(c,ebook_creator_footer,(uint64_t)c->size-6))return false;
 }else if(sxiex_u32(c,p,&v)&&v==5&&(sxiex_eq(c,p+4,"Sbook",5)||sxiex_eq(c,p+4,"Ebook",5))){
  if(!SXIEX_ADD(c,sbook_header,p))return false;uint64_t end=0;
  for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint32_t n;if(!sxiex_u32(c,m->header+4,&n)||m->header_size!=16U+(uint64_t)n)continue;
   if(!SXIEX_ADD(c,sbook_count,m->header)||!SXIEX_ADD(c,sbook_name_length,m->header+4)||!sxiex_name(c,m->header+8,n)||!SXIEX_ADD(c,sbook_member,m->header+8+n))return false;
   uint64_t q=m->data,e=q+m->packed;while(e-q>=4){uint32_t z;if(!sxiex_u32(c,q,&z)||z>e-q-4)break;if(!SXIEX_ADD(c,sbook_chunk,q))return false;q+=4+z;}if(e>end)end=e;
  }
  if(end&&sxiex_span(c,end,12)&&!SXIEX_ADD(c,sbook_footer,end))return false;
 }
 return true;
}
/* NE resource row offsets are kept in their original shift units. */
static bool sxiex_wasp(sx_context*c,const sxiex_records*r){
 (void)r;uint8_t dos[64],ne[40],b[12];if(!sxiex_read(c,0,dos,64)||dos[0]!='M'||dos[1]!='Z')return true;uint64_t np=sxiex32(dos+60,false);if(!sxiex_read(c,np,ne,40)||ne[0]!='N'||ne[1]!='E')return true;
 uint64_t start=np+sxiex16(ne+36,false),end=np+sxiex16(ne+38,false),p=start;uint16_t shift;if(end<start||!sxiex_span(c,start,end-start)||!sxiex_u16(c,p,&shift)||shift>16)return true;
 if(!SXIEX_ADD(c,wasp_resource_shift,p))return false;p+=2;
 for(unsigned row=0;row<4096&&end-p>=2;row++){
  uint16_t type;if(!sxiex_u16(c,p,&type))break;if(!type){if(!SXIEX_ADD(c,wasp_resource_end,p))return false;break;}if(end-p<8||!sxiex_read(c,p,b,8))break;uint16_t n=sxiex16(b+2,false);if((uint64_t)n*12>end-p-8)break;if(!SXIEX_ADD(c,wasp_resource_type,p))return false;
  if(!(type&0x8000U)&&type<end-start){uint64_t np=start+type;uint8_t len;if(sxiex_read(c,np,&len,1)&&len<=end-np-1){if(!SXIEX_ADD(c,wasp_string_length,np)||!sxiex_name(c,np+1,len))return false;}}p+=8;
  for(unsigned i=0;i<n;i++,p+=12){if(!sxiex_read(c,p,b,12))return false;if(!SXIEX_ADD(c,wasp_resource_entry,p))return false;
   if(type==0x8006){uint64_t q=(uint64_t)sxiex16(b,false)<<shift,z=(uint64_t)sxiex16(b+2,false)<<shift;if(!sxiex_span(c,q,z))continue;uint64_t e=q+z;
    for(unsigned j=0;j<16&&q<e;j++){uint8_t len,text[255];if(!sxiex_read(c,q,&len,1)||len>e-q-1)break;uint64_t s=q+1;q=s+len;if(!len)continue;if(!sxiex_read(c,s,text,len))return false;unsigned comma=len;for(unsigned k=0;k<len;k++)if(text[k]==',')comma=k;unsigned last=len;if(last&&text[last-1]=='*')last--;if(!comma||comma+1>=last)continue;bool number=true;for(unsigned k=comma+1;k<last;k++)if(text[k]<'0'||text[k]>'9')number=false;if(!number||last-comma-1>24)continue;
     if(!SXIEX_ADD(c,wasp_string_length,s-1)||!sxiex_name(c,s,comma)||!SXIEX_ADD(c,wasp_name_separator,s+comma)||!sxiex_text(c,&sxiex_wasp_payload_size,s+comma+1,last-comma-1)||(last<len&&!SXIEX_ADD(c,wasp_run_marker,s+last)))return false;
    }
   }
  }
 }
 return true;
}

static bool sx_installerextras_supports(xx_file_type_t type){switch(type){
case XX_FILE_TYPE_SFX_SBX_EXTRACTOR:case XX_FILE_TYPE_SFX_ANALOGX_EMUCORE_FFS:case XX_FILE_TYPE_SFX_KRZIP:case XX_FILE_TYPE_SFX_WARPIN_PACKAGE:case XX_FILE_TYPE_SFX_HCI_INSTALIT:case XX_FILE_TYPE_SFX_CLICKTEAM_MULTIMEDIA_FUSION:case XX_FILE_TYPE_SFX_ABBYY_FINE_OBJECTS:case XX_FILE_TYPE_SFX_FLASHJESTER_JUGGLOR:case XX_FILE_TYPE_SFX_JGSOFT_DEPLOYMASTER_PACKAGE:case XX_FILE_TYPE_SFX_NULLSOFT_PIMP:case XX_FILE_TYPE_SFX_COMPAQ_SOFTPAQ:case XX_FILE_TYPE_SFX_WASP_WINDOWS_AUTO:case XX_FILE_TYPE_SFXSTART:case XX_FILE_TYPE_SFX_EBOOK_COMPILER_EXECUTABLES:case XX_FILE_TYPE_SFX_PACKAGEFORTHEWEB:case XX_FILE_TYPE_SFX_RED:return true;default:return false;}}
static bool sx_installerextras_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;sxiex_records records;if(!sxiex_collect(c,&records)){if(records.items)xx_mem_free(records.items);return false;}bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_SFX_SBX_EXTRACTOR:ok=sxiex_sbx(c,&records);break;
case XX_FILE_TYPE_SFX_ANALOGX_EMUCORE_FFS:ok=sxiex_ffs(c,&records);break;
case XX_FILE_TYPE_SFX_KRZIP:ok=sxiex_krzip(c,&records);break;
case XX_FILE_TYPE_SFX_WARPIN_PACKAGE:ok=sxiex_warpin(c,&records);break;
case XX_FILE_TYPE_SFX_HCI_INSTALIT:ok=sxiex_instalit(c,&records);break;
case XX_FILE_TYPE_SFX_CLICKTEAM_MULTIMEDIA_FUSION:ok=sxiex_clickteam(c,&records);break;
case XX_FILE_TYPE_SFX_ABBYY_FINE_OBJECTS:ok=sxiex_abbyy(c,&records);break;
case XX_FILE_TYPE_SFX_FLASHJESTER_JUGGLOR:ok=sxiex_jugglor(c,&records);break;
case XX_FILE_TYPE_SFX_JGSOFT_DEPLOYMASTER_PACKAGE:ok=sxiex_deploy(c,&records);break;
case XX_FILE_TYPE_SFX_NULLSOFT_PIMP:ok=sxiex_pimp(c,&records);break;
case XX_FILE_TYPE_SFX_COMPAQ_SOFTPAQ:ok=sxiex_softpaq(c,&records);break;
case XX_FILE_TYPE_SFX_WASP_WINDOWS_AUTO:ok=sxiex_wasp(c,&records);break;
case XX_FILE_TYPE_SFXSTART:ok=sxiex_sfxstart(c,&records);break;
case XX_FILE_TYPE_SFX_EBOOK_COMPILER_EXECUTABLES:ok=sxiex_ebook(c,&records);break;
case XX_FILE_TYPE_SFX_PACKAGEFORTHEWEB:ok=sxiex_pftw(c,&records);break;
case XX_FILE_TYPE_SFX_RED:ok=sxiex_red(c,&records);break;
default:break;}if(records.items)xx_mem_free(records.items);(void)ok;return c->count&&sxiex_finish(c);}
#undef SXIEX_ADD
#undef SXIEX_LIMIT

