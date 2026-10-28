/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Native-supported physical archive metadata. See docs/data_struct_archiveextras_scope.txt. */
static const xx_data_struct_field_desc sxae_arc_member_old_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("method","uint8",1,1,SX_ID),
    SX_FIELD("name","char[13]",2,13,SX_STRING),
    SX_FIELD("packed_size","uint32",15,4,SX_SIZE),
    SX_FIELD("date","uint16",19,2,SX_NONE),
    SX_FIELD("time","uint16",21,2,SX_NONE),
    SX_FIELD("crc16","uint16",23,2,SX_CHECKSUM),
};
static const sx_layout sxae_arc_member_old = {UINT32_C(0x60170001),"arc_member_old",sxae_arc_member_old_fields,SX_COUNT(sxae_arc_member_old_fields),SX_LE};
static const xx_data_struct_field_desc sxae_arc_member_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("method","uint8",1,1,SX_ID),
    SX_FIELD("name","char[13]",2,13,SX_STRING),
    SX_FIELD("packed_size","uint32",15,4,SX_SIZE),
    SX_FIELD("date","uint16",19,2,SX_NONE),
    SX_FIELD("time","uint16",21,2,SX_NONE),
    SX_FIELD("crc16","uint16",23,2,SX_CHECKSUM),
    SX_FIELD("unpacked_size","uint32",25,4,SX_SIZE),
};
static const sx_layout sxae_arc_member = {UINT32_C(0x60170002),"arc_member",sxae_arc_member_fields,SX_COUNT(sxae_arc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_arc_end_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("method","uint8",1,1,SX_ID),
};
static const sx_layout sxae_arc_end = {UINT32_C(0x60170003),"arc_end",sxae_arc_end_fields,SX_COUNT(sxae_arc_end_fields),SX_LE};
static const xx_data_struct_field_desc sxae_bsn_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
};
static const sx_layout sxae_bsn_header = {UINT32_C(0x60170004),"bsn_header",sxae_bsn_header_fields,SX_COUNT(sxae_bsn_header_fields),SX_BE};
static const xx_data_struct_field_desc sxae_bsn_member_prefix_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("body_size","uint16",4,2,SX_SIZE),
    SX_FIELD("attributes","uint32",6,4,SX_FLAGS),
    SX_FIELD("date_time","uint32",10,4,SX_NONE),
};
static const sx_layout sxae_bsn_member_prefix = {UINT32_C(0x60170005),"bsn_member_prefix",sxae_bsn_member_prefix_fields,SX_COUNT(sxae_bsn_member_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxae_bsn_member_sizes_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("header_crc32","uint32",12,4,SX_CHECKSUM),
};
static const sx_layout sxae_bsn_member_sizes = {UINT32_C(0x60170006),"bsn_member_sizes",sxae_bsn_member_sizes_fields,SX_COUNT(sxae_bsn_member_sizes_fields),SX_BE};
static const xx_data_struct_field_desc sxae_bsn_end_fields[] = {
    SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxae_bsn_end = {UINT32_C(0x60170007),"bsn_end",sxae_bsn_end_fields,SX_COUNT(sxae_bsn_end_fields),SX_BE};
static const xx_data_struct_field_desc sxae_arq_container_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("total_unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
static const sx_layout sxae_arq_container = {UINT32_C(0x60170008),"arq_container",sxae_arq_container_fields,SX_COUNT(sxae_arq_container_fields),SX_LE};
static const xx_data_struct_field_desc sxae_arq_member_prefix_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("signature","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("name_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxae_arq_member_prefix = {UINT32_C(0x60170009),"arq_member_prefix",sxae_arq_member_prefix_fields,SX_COUNT(sxae_arq_member_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxae_arq_member_tail_fields[] = {
    SX_FIELD("modified","uint32",0,4,SX_NONE),
    SX_FIELD("attributes","uint16",4,2,SX_FLAGS),
    SX_FIELD("reserved","uint32",6,4,SX_RESERVED),
    SX_FIELD("packed_size","uint32",10,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",14,4,SX_SIZE),
    SX_FIELD("packed_crc32","uint32",18,4,SX_CHECKSUM),
    SX_FIELD("method","uint16",22,2,SX_ID),
    SX_FIELD("flags","uint8",24,1,SX_FLAGS),
    SX_FIELD("reserved_tail","uint8[8]",25,8,SX_RESERVED),
};
static const sx_layout sxae_arq_member_tail = {UINT32_C(0x6017000a),"arq_member_tail",sxae_arq_member_tail_fields,SX_COUNT(sxae_arq_member_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxae_gxl_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("copyright","char[50]",2,50,SX_STRING),
    SX_FIELD("version","uint16",52,2,SX_NONE),
    SX_FIELD("volume","char[40]",54,40,SX_STRING),
    SX_FIELD("member_count","uint16",94,2,SX_COUNT_PROP),
    SX_FIELD("unused","uint8[32]",96,32,SX_RESERVED),
};
static const sx_layout sxae_gxl_header = {UINT32_C(0x6017000b),"gxl_header",sxae_gxl_header_fields,SX_COUNT(sxae_gxl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_gxl_member_fields[] = {
    SX_FIELD("method","uint8",0,1,SX_ID),
    SX_FIELD("base_name","char[8]",1,8,SX_STRING),
    SX_FIELD("extension","char[4]",9,4,SX_STRING),
    SX_FIELD("unused","uint8",13,1,SX_RESERVED),
    SX_FIELD("data_offset","uint32",14,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",18,4,SX_SIZE),
    SX_FIELD("time","uint16",22,2,SX_NONE),
    SX_FIELD("date","uint16",24,2,SX_NONE),
};
static const sx_layout sxae_gxl_member = {UINT32_C(0x6017000c),"gxl_member",sxae_gxl_member_fields,SX_COUNT(sxae_gxl_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_rta_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxae_rta_header = {UINT32_C(0x6017000d),"rta_header",sxae_rta_header_fields,SX_COUNT(sxae_rta_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_rta_string_size_fields[] = {
    SX_FIELD("string_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxae_rta_string_size = {UINT32_C(0x6017000e),"rta_string_size",sxae_rta_string_size_fields,SX_COUNT(sxae_rta_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxae_rta_member_fields[] = {
    SX_FIELD("attributes","uint8",0,1,SX_FLAGS),
    SX_FIELD("date","uint16",1,2,SX_NONE),
    SX_FIELD("time","uint16",3,2,SX_NONE),
    SX_FIELD("unpacked_size","int32",5,4,SX_SIZE),
    SX_FIELD("packed_size","int32",9,4,SX_SIZE),
};
static const sx_layout sxae_rta_member = {UINT32_C(0x6017000f),"rta_member",sxae_rta_member_fields,SX_COUNT(sxae_rta_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_rta_codec_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("raw_literal_flag","uint8",2,1,SX_FLAGS),
    SX_FIELD("marker","uint8",3,1,SX_SIGNATURE),
};
static const sx_layout sxae_rta_codec_header = {UINT32_C(0x60170010),"rta_codec_header",sxae_rta_codec_header_fields,SX_COUNT(sxae_rta_codec_header_fields),SX_BE};
static const xx_data_struct_field_desc sxae_rta_end_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxae_rta_end = {UINT32_C(0x60170011),"rta_end",sxae_rta_end_fields,SX_COUNT(sxae_rta_end_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_header_fields[] = {
    SX_FIELD("magic","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",5,1,SX_NONE),
    SX_FIELD("unknown","uint8[2]",6,2,SX_NONE),
};
static const sx_layout sxae_sqz_header = {UINT32_C(0x60170012),"sqz_header",sxae_sqz_header_fields,SX_COUNT(sxae_sqz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_member_fields[] = {
    SX_FIELD("header_length","uint8",0,1,SX_NONE),
    SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("packed_size","uint32",3,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",7,4,SX_SIZE),
    SX_FIELD("time","uint16",11,2,SX_NONE),
    SX_FIELD("date","uint16",13,2,SX_NONE),
    SX_FIELD("attributes","uint8",15,1,SX_FLAGS),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxae_sqz_member = {UINT32_C(0x60170013),"sqz_member",sxae_sqz_member_fields,SX_COUNT(sxae_sqz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_block_fields[] = {
    SX_FIELD("kind","uint8",0,1,SX_ID),
    SX_FIELD("extra_size","uint16",1,2,SX_SIZE),
};
static const sx_layout sxae_sqz_block = {UINT32_C(0x60170014),"sqz_block",sxae_sqz_block_fields,SX_COUNT(sxae_sqz_block_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_block4_fields[] = {
    SX_FIELD("kind","uint8",0,1,SX_ID),
    SX_FIELD("extra_size","uint16",1,2,SX_SIZE),
    SX_FIELD("unknown","uint8[2]",3,2,SX_NONE),
};
static const sx_layout sxae_sqz_block4 = {UINT32_C(0x60170015),"sqz_block4",sxae_sqz_block4_fields,SX_COUNT(sxae_sqz_block4_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_comment_fields[] = {
    SX_FIELD("kind","uint8",0,1,SX_ID),
    SX_FIELD("legacy_size","uint16",1,2,SX_NONE),
    SX_FIELD("extra_size","uint16",3,2,SX_SIZE),
    SX_FIELD("unknown","uint8[5]",5,5,SX_NONE),
};
static const sx_layout sxae_sqz_comment = {UINT32_C(0x60170016),"sqz_comment",sxae_sqz_comment_fields,SX_COUNT(sxae_sqz_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqz_end_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxae_sqz_end = {UINT32_C(0x60170017),"sqz_end",sxae_sqz_end_fields,SX_COUNT(sxae_sqz_end_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqx_main_fields[] = {
    SX_FIELD("header_crc16","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("kind","uint8",2,1,SX_ID),
    SX_FIELD("flags","uint16",3,2,SX_FLAGS),
    SX_FIELD("header_size","uint16",5,2,SX_SIZE),
    SX_FIELD("signature","char[5]",7,5,SX_SIGNATURE),
    SX_FIELD("writer_and_reserved","uint8[13]",12,13,SX_NONE),
};
static const sx_layout sxae_sqx_main = {UINT32_C(0x60170018),"sqx_main",sxae_sqx_main_fields,SX_COUNT(sxae_sqx_main_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqx_record_fields[] = {
    SX_FIELD("header_crc16","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("kind","uint8",2,1,SX_ID),
    SX_FIELD("flags","uint16",3,2,SX_FLAGS),
    SX_FIELD("header_size","uint16",5,2,SX_SIZE),
};
static const sx_layout sxae_sqx_record = {UINT32_C(0x60170019),"sqx_record",sxae_sqx_record_fields,SX_COUNT(sxae_sqx_record_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqx_file32_fields[] = {
    SX_FIELD("filter","uint8",0,1,SX_ID),
    SX_FIELD("filter_parameters","uint8[4]",1,4,SX_NONE),
    SX_FIELD("method","uint8",5,1,SX_ID),
    SX_FIELD("crc32","uint32",6,4,SX_CHECKSUM),
    SX_FIELD("attributes","uint32",10,4,SX_FLAGS),
    SX_FIELD("modified","uint32",14,4,SX_NONE),
    SX_FIELD("packed_size_low","uint32",18,4,SX_SIZE),
    SX_FIELD("unpacked_size_low","uint32",22,4,SX_SIZE),
    SX_FIELD("name_size","uint16",26,2,SX_SIZE),
};
static const sx_layout sxae_sqx_file32 = {UINT32_C(0x6017001a),"sqx_file32",sxae_sqx_file32_fields,SX_COUNT(sxae_sqx_file32_fields),SX_LE};
static const xx_data_struct_field_desc sxae_sqx_file64_fields[] = {
    SX_FIELD("filter","uint8",0,1,SX_ID),
    SX_FIELD("filter_parameters","uint8[4]",1,4,SX_NONE),
    SX_FIELD("method","uint8",5,1,SX_ID),
    SX_FIELD("crc32","uint32",6,4,SX_CHECKSUM),
    SX_FIELD("attributes","uint32",10,4,SX_FLAGS),
    SX_FIELD("modified","uint32",14,4,SX_NONE),
    SX_FIELD("packed_size_low","uint32",18,4,SX_NONE),
    SX_FIELD("unpacked_size_low","uint32",22,4,SX_NONE),
    SX_FIELD("packed_size_high","uint32",26,4,SX_NONE),
    SX_FIELD("unpacked_size_high","uint32",30,4,SX_NONE),
    SX_FIELD("name_size","uint16",34,2,SX_SIZE),
};
static const sx_layout sxae_sqx_file64 = {UINT32_C(0x6017001b),"sqx_file64",sxae_sqx_file64_fields,SX_COUNT(sxae_sqx_file64_fields),SX_LE};
static const xx_data_struct_field_desc sxae_hap_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("reserved","uint8[11]",4,11,SX_RESERVED),
};
static const sx_layout sxae_hap_header = {UINT32_C(0x6017001c),"hap_header",sxae_hap_header_fields,SX_COUNT(sxae_hap_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_hap_member_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("packed_size","int32",4,4,SX_SIZE),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("unknown","uint8[4]",12,4,SX_NONE),
    SX_FIELD("flags","uint8",16,1,SX_FLAGS),
    SX_FIELD("unknown17","uint8",17,1,SX_NONE),
    SX_FIELD("time","uint16",18,2,SX_NONE),
    SX_FIELD("date","uint16",20,2,SX_NONE),
    SX_FIELD("unpacked_size","int32",22,4,SX_SIZE),
    SX_FIELD("name","char[13]",26,13,SX_STRING),
    SX_FIELD("method","uint8",39,1,SX_ID),
};
static const sx_layout sxae_hap_member = {UINT32_C(0x6017001d),"hap_member",sxae_hap_member_fields,SX_COUNT(sxae_hap_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("method","uint16",8,2,SX_ID),
    SX_FIELD("data_offset","uint16",10,2,SX_OFFSET),
    SX_FIELD("extension_flags","uint16",12,2,SX_FLAGS),
};
static const sx_layout sxae_kwaj_header = {UINT32_C(0x6017001e),"kwaj_header",sxae_kwaj_header_fields,SX_COUNT(sxae_kwaj_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_unpacked_size_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxae_kwaj_unpacked_size = {UINT32_C(0x6017001f),"kwaj_unpacked_size",sxae_kwaj_unpacked_size_fields,SX_COUNT(sxae_kwaj_unpacked_size_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_unknown_fields[] = {
    SX_FIELD("unknown","uint16",0,2,SX_NONE),
};
static const sx_layout sxae_kwaj_unknown = {UINT32_C(0x60170020),"kwaj_unknown",sxae_kwaj_unknown_fields,SX_COUNT(sxae_kwaj_unknown_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_extension_size_fields[] = {
    SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxae_kwaj_extension_size = {UINT32_C(0x60170021),"kwaj_extension_size",sxae_kwaj_extension_size_fields,SX_COUNT(sxae_kwaj_extension_size_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_mszip_block_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_NONE),
    SX_FIELD("signature","char[2]",2,2,SX_SIGNATURE),
};
static const sx_layout sxae_kwaj_mszip_block = {UINT32_C(0x60170022),"kwaj_mszip_block",sxae_kwaj_mszip_block_fields,SX_COUNT(sxae_kwaj_mszip_block_fields),SX_LE};
static const xx_data_struct_field_desc sxae_kwaj_mszip_end_fields[] = {
    SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxae_kwaj_mszip_end = {UINT32_C(0x60170023),"kwaj_mszip_end",sxae_kwaj_mszip_end_fields,SX_COUNT(sxae_kwaj_mszip_end_fields),SX_LE};
static const xx_data_struct_field_desc sxae_chz_file_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("record_size","uint32",4,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
    SX_FIELD("opaque_metadata","uint8[8]",12,8,SX_NONE),
    SX_FIELD("method","uint8",20,1,SX_ID),
    SX_FIELD("unknown21","uint8",21,1,SX_NONE),
    SX_FIELD("name_size","uint16",22,2,SX_SIZE),
};
static const sx_layout sxae_chz_file = {UINT32_C(0x60170024),"chz_file",sxae_chz_file_fields,SX_COUNT(sxae_chz_file_fields),SX_LE};
static const xx_data_struct_field_desc sxae_chz_directory_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("opaque_metadata","uint8[4]",4,4,SX_NONE),
    SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
    SX_FIELD("name_size","uint8",9,1,SX_SIZE),
};
static const sx_layout sxae_chz_directory = {UINT32_C(0x60170025),"chz_directory",sxae_chz_directory_fields,SX_COUNT(sxae_chz_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxae_chz_directory_end_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxae_chz_directory_end = {UINT32_C(0x60170026),"chz_directory_end",sxae_chz_directory_end_fields,SX_COUNT(sxae_chz_directory_end_fields),SX_LE};
static const xx_data_struct_field_desc sxae_swag_member_fields[] = {
    SX_FIELD("header_length","uint8",0,1,SX_NONE),
    SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
    SX_FIELD("method","char[5]",2,5,SX_ID),
    SX_FIELD("packed_size","int32",7,4,SX_SIZE),
    SX_FIELD("unpacked_size","int32",11,4,SX_SIZE),
    SX_FIELD("time","uint16",15,2,SX_NONE),
    SX_FIELD("date","uint16",17,2,SX_NONE),
    SX_FIELD("attributes","uint16",19,2,SX_FLAGS),
    SX_FIELD("crc32_register","uint32",21,4,SX_CHECKSUM),
    SX_FIELD("archive_name_size","uint8",25,1,SX_SIZE),
    SX_FIELD("archive_name","char[39]",26,39,SX_STRING),
    SX_FIELD("unused","uint8[121]",65,121,SX_RESERVED),
    SX_FIELD("name_size","uint8",186,1,SX_SIZE),
};
static const sx_layout sxae_swag_member = {UINT32_C(0x60170027),"swag_member",sxae_swag_member_fields,SX_COUNT(sxae_swag_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_swag_member_crc_fields[] = {
    SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxae_swag_member_crc = {UINT32_C(0x60170028),"swag_member_crc",sxae_swag_member_crc_fields,SX_COUNT(sxae_swag_member_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxae_swag_footer_fields[] = {
    SX_FIELD("copyright_size","uint8",0,1,SX_SIZE),
    SX_FIELD("copyright","char[60]",1,60,SX_STRING),
    SX_FIELD("collection_size","uint8",61,1,SX_SIZE),
    SX_FIELD("collection","char[65]",62,65,SX_STRING),
    SX_FIELD("member_count","uint16",127,2,SX_COUNT_PROP),
};
static const sx_layout sxae_swag_footer = {UINT32_C(0x60170029),"swag_footer",sxae_swag_footer_fields,SX_COUNT(sxae_swag_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxae_zpak_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxae_zpak_header = {UINT32_C(0x6017002a),"zpak_header",sxae_zpak_header_fields,SX_COUNT(sxae_zpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_zpak_member_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_STRING),
    SX_FIELD("padding","uint8",12,1,SX_RESERVED),
    SX_FIELD("data_offset","int32",13,4,SX_OFFSET),
    SX_FIELD("packed_size","int32",17,4,SX_SIZE),
    SX_FIELD("date","uint16",21,2,SX_NONE),
    SX_FIELD("time","uint16",23,2,SX_NONE),
    SX_FIELD("crc_low","uint16",25,2,SX_CHECKSUM),
    SX_FIELD("crc_high","uint16",27,2,SX_CHECKSUM),
    SX_FIELD("unpacked_size","int32",29,4,SX_SIZE),
};
static const sx_layout sxae_zpak_member = {UINT32_C(0x6017002b),"zpak_member",sxae_zpak_member_fields,SX_COUNT(sxae_zpak_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_zpak_chunk_marker_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxae_zpak_chunk_marker = {UINT32_C(0x6017002c),"zpak_chunk_marker",sxae_zpak_chunk_marker_fields,SX_COUNT(sxae_zpak_chunk_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxae_zpak_chunk_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxae_zpak_chunk = {UINT32_C(0x6017002d),"zpak_chunk",sxae_zpak_chunk_fields,SX_COUNT(sxae_zpak_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxae_asymetrix_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("record_stride","uint32",4,4,SX_SIZE),
    SX_FIELD("set_name","char[9]",8,9,SX_STRING),
    SX_FIELD("opaque_metadata","uint8[23]",17,23,SX_NONE),
    SX_FIELD("volume_number","uint16",40,2,SX_ID),
    SX_FIELD("member_count","uint16",42,2,SX_COUNT_PROP),
};
static const sx_layout sxae_asymetrix_header = {UINT32_C(0x6017002e),"asymetrix_header",sxae_asymetrix_header_fields,SX_COUNT(sxae_asymetrix_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_asymetrix_member_fields[] = {
    SX_FIELD("name","char[13]",0,13,SX_STRING),
    SX_FIELD("writer_bytes","uint8[17]",13,17,SX_NONE),
    SX_FIELD("volume_word","uint32",30,4,SX_NONE),
    SX_FIELD("data_offset","uint32",34,4,SX_OFFSET),
    SX_FIELD("unpacked_size","uint32",38,4,SX_SIZE),
    SX_FIELD("writer_bytes2","uint8[56]",42,56,SX_NONE),
    SX_FIELD("date","uint16",98,2,SX_NONE),
    SX_FIELD("time","uint16",100,2,SX_NONE),
    SX_FIELD("attributes","uint16",102,2,SX_FLAGS),
    SX_FIELD("crc32","uint32",104,4,SX_CHECKSUM),
};
static const sx_layout sxae_asymetrix_member = {UINT32_C(0x6017002f),"asymetrix_member",sxae_asymetrix_member_fields,SX_COUNT(sxae_asymetrix_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_asymetrix_block_fields[] = {
    SX_FIELD("method","uint16",0,2,SX_ID),
    SX_FIELD("packed_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxae_asymetrix_block = {UINT32_C(0x60170030),"asymetrix_block",sxae_asymetrix_block_fields,SX_COUNT(sxae_asymetrix_block_fields),SX_LE};
static const xx_data_struct_field_desc sxae_diskexpress_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("major","uint8",2,1,SX_NONE),
    SX_FIELD("minor","uint8",3,1,SX_NONE),
    SX_FIELD("release","uint8",4,1,SX_NONE),
    SX_FIELD("disk_type","uint8",5,1,SX_ID),
    SX_FIELD("image_crc32","uint32",6,4,SX_CHECKSUM),
    SX_FIELD("method","uint8",10,1,SX_ID),
    SX_FIELD("last_cylinder","uint8",11,1,SX_NONE),
    SX_FIELD("last_head","uint8",12,1,SX_NONE),
    SX_FIELD("unused","uint8",13,1,SX_RESERVED),
    SX_FIELD("flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("reserved","uint8[289]",15,289,SX_RESERVED),
    SX_FIELD("header_crc32","uint32",304,4,SX_CHECKSUM),
    SX_FIELD("description","char[200]",308,200,SX_STRING),
    SX_FIELD("description_crc32","uint32",508,4,SX_CHECKSUM),
};
static const sx_layout sxae_diskexpress_header = {UINT32_C(0x60170031),"diskexpress_header",sxae_diskexpress_header_fields,SX_COUNT(sxae_diskexpress_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_diskexpress_track_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxae_diskexpress_track = {UINT32_C(0x60170032),"diskexpress_track",sxae_diskexpress_track_fields,SX_COUNT(sxae_diskexpress_track_fields),SX_LE};
static const xx_data_struct_field_desc sxae_ain_header_fields[] = {
    SX_FIELD("magic","char[1]",0,1,SX_SIGNATURE),
    SX_FIELD("version_method","uint8",1,1,SX_FLAGS),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("unknown4","uint8[4]",4,4,SX_NONE),
    SX_FIELD("member_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("unknown10","uint8[4]",10,4,SX_NONE),
    SX_FIELD("directory_offset","uint32",14,4,SX_OFFSET),
    SX_FIELD("unknown18","uint8[4]",18,4,SX_NONE),
    SX_FIELD("header_checksum","uint16",22,2,SX_CHECKSUM),
};
static const sx_layout sxae_ain_header = {UINT32_C(0x60170033),"ain_header",sxae_ain_header_fields,SX_COUNT(sxae_ain_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_amigalzx_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("flags_and_info","uint8[7]",3,7,SX_NONE),
};
static const sx_layout sxae_amigalzx_header = {UINT32_C(0x60170034),"amigalzx_header",sxae_amigalzx_header_fields,SX_COUNT(sxae_amigalzx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_amigalzx_member_fields[] = {
    SX_FIELD("attributes","uint8",0,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
    SX_FIELD("unpacked_size","uint32",2,4,SX_SIZE),
    SX_FIELD("group_packed_size","uint32",6,4,SX_SIZE),
    SX_FIELD("machine","uint8",10,1,SX_ID),
    SX_FIELD("method","uint8",11,1,SX_ID),
    SX_FIELD("flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("reserved13","uint8",13,1,SX_RESERVED),
    SX_FIELD("comment_size","uint8",14,1,SX_SIZE),
    SX_FIELD("extract_version","uint8",15,1,SX_NONE),
    SX_FIELD("reserved16","uint16",16,2,SX_RESERVED),
    SX_FIELD("date_time","uint32",18,4,SX_NONE),
    SX_FIELD("crc32","uint32",22,4,SX_CHECKSUM),
    SX_FIELD("header_crc32","uint32",26,4,SX_CHECKSUM),
    SX_FIELD("name_size","uint8",30,1,SX_SIZE),
};
static const sx_layout sxae_amigalzx_member = {UINT32_C(0x60170035),"amigalzx_member",sxae_amigalzx_member_fields,SX_COUNT(sxae_amigalzx_member_fields),SX_LE};
static const sx_layout *const sx_archiveextras_layouts[] = {
    &sxae_arc_member_old,
    &sxae_arc_member,
    &sxae_arc_end,
    &sxae_bsn_header,
    &sxae_bsn_member_prefix,
    &sxae_bsn_member_sizes,
    &sxae_bsn_end,
    &sxae_arq_container,
    &sxae_arq_member_prefix,
    &sxae_arq_member_tail,
    &sxae_gxl_header,
    &sxae_gxl_member,
    &sxae_rta_header,
    &sxae_rta_string_size,
    &sxae_rta_member,
    &sxae_rta_codec_header,
    &sxae_rta_end,
    &sxae_sqz_header,
    &sxae_sqz_member,
    &sxae_sqz_block,
    &sxae_sqz_block4,
    &sxae_sqz_comment,
    &sxae_sqz_end,
    &sxae_sqx_main,
    &sxae_sqx_record,
    &sxae_sqx_file32,
    &sxae_sqx_file64,
    &sxae_hap_header,
    &sxae_hap_member,
    &sxae_kwaj_header,
    &sxae_kwaj_unpacked_size,
    &sxae_kwaj_unknown,
    &sxae_kwaj_extension_size,
    &sxae_kwaj_mszip_block,
    &sxae_kwaj_mszip_end,
    &sxae_chz_file,
    &sxae_chz_directory,
    &sxae_chz_directory_end,
    &sxae_swag_member,
    &sxae_swag_member_crc,
    &sxae_swag_footer,
    &sxae_zpak_header,
    &sxae_zpak_member,
    &sxae_zpak_chunk_marker,
    &sxae_zpak_chunk,
    &sxae_asymetrix_header,
    &sxae_asymetrix_member,
    &sxae_asymetrix_block,
    &sxae_diskexpress_header,
    &sxae_diskexpress_track,
    &sxae_ain_header,
    &sxae_amigalzx_header,
    &sxae_amigalzx_member,
};
static bool sx_archiveextras_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60170000)||id>=UINT32_C(0x60180000))return true;
    const wchar_t *comment=NULL;switch(id){
    case UINT32_C(0x60170001):
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170002):
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170005):
        if(!xx_rt_wcscmp(r->name,L"date_time"))comment=L"Packed DOS date/time words, not a Unix timestamp.";
        break;
    case UINT32_C(0x6017000a):
        if(!xx_rt_wcscmp(r->name,L"modified"))comment=L"Encoded native modification-time word; epoch semantics are not established.";
        if(!xx_rt_wcscmp(r->name,L"packed_crc32"))comment=L"CRC32 of encoded member bytes, not the decoded contents.";
        break;
    case UINT32_C(0x6017000c):
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x6017000f):
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170013):
        if(!xx_rt_wcscmp(r->name,L"header_length"))comment=L"Physical header size is this encoded byte plus 2.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170016):
        if(!xx_rt_wcscmp(r->name,L"legacy_size"))comment=L"Superseded by the following extra_size in type-1 comment blocks.";
        break;
    case UINT32_C(0x6017001a):
        if(!xx_rt_wcscmp(r->name,L"modified"))comment=L"Encoded native modification-time word; epoch semantics are not established.";
        if(!xx_rt_wcscmp(r->name,L"packed_size_low"))comment=L"Byte length; no high word is present in this variant.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size_low"))comment=L"Byte length; no high word is present in this variant.";
        break;
    case UINT32_C(0x6017001b):
        if(!xx_rt_wcscmp(r->name,L"modified"))comment=L"Encoded native modification-time word; epoch semantics are not established.";
        if(!xx_rt_wcscmp(r->name,L"packed_size_low"))comment=L"Low 32 bits of the byte length; combine high word when LARGE flag is set.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size_low"))comment=L"Low 32 bits of the byte length; combine high word when LARGE flag is set.";
        if(!xx_rt_wcscmp(r->name,L"packed_size_high"))comment=L"High 32 bits of the byte length, not a complete size.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size_high"))comment=L"High 32 bits of the byte length, not a complete size.";
        break;
    case UINT32_C(0x6017001d):
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170022):
        if(!xx_rt_wcscmp(r->name,L"encoded_size"))comment=L"MSZIP block encoded length; includes its CK signature as defined by the stream framing.";
        break;
    case UINT32_C(0x60170027):
        if(!xx_rt_wcscmp(r->name,L"header_length"))comment=L"Counted from byte 2; equals member name size plus 0xBB.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size"))comment=L"Zero selects a stored member, whose decoded size is packed_size.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"crc32_register"))comment=L"CRC32 register before final inversion.";
        break;
    case UINT32_C(0x6017002b):
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"crc_low"))comment=L"Low 16 bits of CRC32; combine high word.";
        if(!xx_rt_wcscmp(r->name,L"crc_high"))comment=L"High 16 bits of CRC32; zero disables checksum validation in this reader.";
        break;
    case UINT32_C(0x6017002f):
        if(!xx_rt_wcscmp(r->name,L"writer_bytes"))comment=L"Uninitialized producer bytes; no date/time or other fields are inferred from them.";
        if(!xx_rt_wcscmp(r->name,L"volume_word"))comment=L"High 16 bits identify the volume containing the data offset.";
        if(!xx_rt_wcscmp(r->name,L"date"))comment=L"Packed DOS date bits, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"time"))comment=L"Packed DOS time bits, not a Unix timestamp.";
        break;
    case UINT32_C(0x60170031):
        if(!xx_rt_wcscmp(r->name,L"last_cylinder"))comment=L"Zero-based final cylinder index, not a count.";
        if(!xx_rt_wcscmp(r->name,L"last_head"))comment=L"Zero-based final head index, not a count.";
        break;
    case UINT32_C(0x60170033):
        if(!xx_rt_wcscmp(r->name,L"version_method"))comment=L"High nibble: format generation 1..3. Low nibble: method 1..4.";
        if(!xx_rt_wcscmp(r->name,L"directory_offset"))comment=L"Offset of the compressed directory; decoded directory entries have no physical file offsets.";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))comment=L"Sum of the preceding 22 header bytes XOR 0x5555.";
        break;
    case UINT32_C(0x60170035):
        if(!xx_rt_wcscmp(r->name,L"group_packed_size"))comment=L"Zero for a merged prefix member; nonzero size belongs to the entire terminating group stream.";
        if(!xx_rt_wcscmp(r->name,L"date_time"))comment=L"Packed Amiga date/time, not a Unix timestamp.";
        if(!xx_rt_wcscmp(r->name,L"header_crc32"))comment=L"CRC32 of header, name and comment with this field zeroed.";
        break;
    default:break;}
    if(id==UINT32_C(0x60170002)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 1:comment=L"ARC_STORED_OLD";break;
        case 2:comment=L"ARC_STORED";break;
        case 3:comment=L"ARC_PACKED";break;
        case 4:comment=L"ARC_SQUEEZED";break;
        case 5:comment=L"ARC_CRUNCHED_5";break;
        case 6:comment=L"ARC_CRUNCHED_6";break;
        case 7:comment=L"ARC_CRUNCHED_7";break;
        case 8:comment=L"ARC_CRUNCHED";break;
        case 9:comment=L"ARC_SQUASHED";break;
        case 10:comment=L"ARC_CRUSHED";break;
        case 11:comment=L"ARC_DISTILLED";break;
        case 127:comment=L"ARC_COMPRESS";break;
        default:break;}
    if(id==UINT32_C(0x60170001)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 1:comment=L"ARC_STORED_OLD";break;
        default:break;}
    if(id==UINT32_C(0x60170003)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"ARC_END";break;
        default:break;}
    if(id==UINT32_C(0x6017000a)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 1:comment=L"ARQ_STORED";break;
        case 2:comment=L"ARQ_CRUSHED";break;
        default:break;}
    if(id==UINT32_C(0x6017000c)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"GXL_STORED";break;
        default:break;}
    if(id==UINT32_C(0x6017001e)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"KWAJ_STORED";break;
        case 1:comment=L"KWAJ_XOR_FF";break;
        case 2:comment=L"KWAJ_LZSS";break;
        case 3:comment=L"KWAJ_LZH";break;
        case 4:comment=L"KWAJ_MSZIP";break;
        default:break;}
    if(id==UINT32_C(0x6017001d)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 21:comment=L"HAP_STORED";break;
        case 22:comment=L"HAP_PPM";break;
        default:break;}
    if(id==UINT32_C(0x60170024)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"CHZ_STORED";break;
        case 1:comment=L"CHZ_CHARC";break;
        default:break;}
    if(id==UINT32_C(0x60170030)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"ASYMETRIX_STORED";break;
        case 1:comment=L"ASYMETRIX_DCL";break;
        default:break;}
    if(id==UINT32_C(0x60170035)&&!xx_rt_wcscmp(r->name,L"method"))switch(xx_var_get_u64(&r->value)){
        case 0:comment=L"AMIGA_LZX_STORED";break;
        case 2:comment=L"AMIGA_LZX_COMPRESSED";break;
        default:break;}
    return !comment||xx_data_struct_record_set_comment(r,comment);
}

/* Every cursor is relative to the caller's original file base. */
static uint16_t sxae16(const uint8_t *b){return xx_data_get_u16(b,2,0,false);}
static uint32_t sxae32(const uint8_t *b){return xx_data_get_u32(b,4,0,false);}
static bool sxae_bound(sx_context *c,int64_t o,uint64_t n){return o>=0&&o<=c->size&&n<=(uint64_t)(c->size-o);}
static bool sxae_data(sx_context *c,int64_t o,uint64_t n){return n<=INT64_MAX&&sxae_bound(c,o,n)&&sx_raw(c,o,(int64_t)n);}
static bool sxae_add(sx_context *c,const sx_layout *l,int64_t o){int64_t n=l->fields[l->field_count-1].rel_offset+l->fields[l->field_count-1].size;return sx_add(c,l,o,n);}
static int sxae_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxae_finish(sx_context *c)
{
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxae_order);
    size_t count=c->count;int64_t end=0;
    for(size_t i=0;i<count;i++){int64_t p=c->items[i].offset-c->f->base_address,n=c->items[i].total_size;if(p<end||!sxae_bound(c,p,(uint64_t)n))return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+n;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxae_order);return !c->failed;
}
static bool sxae_arc(sx_context *c)
{
 int64_t p=0;uint8_t b[29];for(unsigned k=0;k<20000;k++){if(!sx_read(c,p,b,2)||b[0]!=0x1a)return false;if(!b[1])return sxae_add(c,&sxae_arc_end,p);
 int n=b[1]==1?25:29;if(!sx_read(c,p,b,n)||!sxae_add(c,n==25?&sxae_arc_member_old:&sxae_arc_member,p))return false;uint32_t z=sxae32(b+15);if(!sxae_data(c,p+n,z))return false;p+=n+z;}return false;
}
static bool sxae_bsn(sx_context *c)
{
 uint8_t b[14];int64_t p=6;if(!sx_read(c,0,b,6)||xx_rt_memcmp(b,"\xff" "BSG",4)||!sxae_add(c,&sxae_bsn_header,0))return false;
 for(unsigned k=0;k<20000;k++){if(!sx_read(c,p,b,2))return false;if(!b[0]&&!b[1])return sxae_add(c,&sxae_bsn_end,p);
 if(!sx_read(c,p,b,14)||xx_rt_memcmp(b,"\xff" "BSA",4))return false;uint16_t z=xx_data_get_u16(b+4,2,0,true);if(z<22||z>281||!sxae_bound(c,p,10+z))return false;
 int64_t tail=p+6+z-12;uint32_t packed;if(!sx_u32(c,tail+4,true,&packed)||!sxae_add(c,&sxae_bsn_member_prefix,p)||!sxae_add(c,&sxae_bsn_member_sizes,tail)||!sxae_data(c,p+10+z,packed))return false;p+=10+z+packed;}return false;
}
static bool sxae_arq(sx_context *c)
{
 int64_t p=0;uint8_t b[12];if(!sx_read(c,0,b,4))return false;if(sxae32(b)==UINT32_C(0x02045767)){if(!sxae_add(c,&sxae_arq_container,0))return false;p=12;}
 for(unsigned k=0;k<20000;k++){if(!sx_read(c,p,b,8)||sxae32(b)!=UINT32_C(0x01045767))return false;uint16_t n=sxae16(b+6);int64_t t=p+8+n;uint32_t z;
 if(!sxae_bound(c,p,41+n)||!sxae_add(c,&sxae_arq_member_prefix,p)||!sxae_add(c,&sxae_arq_member_tail,t))return false;
 if(!n)return true;if(!sx_u32(c,t+10,false,&z)||!sxae_data(c,t+33,z))return false;p=t+33+z;}return false;
}
static bool sxae_gxl(sx_context *c)
{
 uint8_t b[128];if(!sx_read(c,0,b,128)||sxae16(b)!=0xca01)return false;uint16_t n=sxae16(b+94);int64_t e=128+(int64_t)n*26;
 if(!n||n>20000||!sxae_bound(c,0,e)||!sxae_add(c,&sxae_gxl_header,0)||!sx_table(c,&sxae_gxl_member,128,26,n))return false;
 for(unsigned i=0;i<n;i++){uint8_t r[26];if(!sx_read(c,128+(int64_t)i*26,r,26))return false;uint32_t o=sxae32(r+14),z=sxae32(r+18);if(o<e||!sxae_bound(c,o,z))return false;}return true;
}
static bool sxae_rta(sx_context *c)
{
 uint8_t b[13],n;int64_t p=4;if(!sx_read(c,0,b,4)||xx_rt_memcmp(b,"KJd\0",4)||!sxae_add(c,&sxae_rta_header,0))return false;
 for(unsigned i=0;i<20000;i++){if(!sx_read(c,p,&n,1))return false;if(!n)return sxae_add(c,&sxae_rta_end,p);if(!sxae_add(c,&sxae_rta_string_size,p)||!sxae_bound(c,p+1,n))return false;p+=1+n;
 if(!sx_read(c,p,&n,1)||!sxae_add(c,&sxae_rta_string_size,p)||!sxae_bound(c,p+1,n))return false;p+=1+n;
 if(!sx_read(c,p,b,13)||!sxae_add(c,&sxae_rta_member,p))return false;uint32_t z=sxae32(b+9);p+=13;if(z>INT32_MAX||!sxae_bound(c,p,z))return false;
 if(z){uint8_t h[4];if(z<4||!sx_read(c,p,h,4)||h[0]!=0xb5||h[1]!=0x9c||h[2]>1||h[3]!=255||!sxae_add(c,&sxae_rta_codec_header,p)||!sxae_data(c,p+4,z-4))return false;}p+=z;}return false;
}
static bool sxae_sqz(sx_context *c)
{
 uint8_t b[20];int64_t p=8;if(!sx_read(c,0,b,8)||xx_rt_memcmp(b,"HLSQZ",5)||!sxae_add(c,&sxae_sqz_header,0))return false;
 for(unsigned i=0;i<20000;i++){if(!sx_read(c,p,b,1))return false;if(!b[0])return sxae_add(c,&sxae_sqz_end,p);
 if(b[0]<19){int n=b[0]==1?10:b[0]==4?5:3;if(!sx_read(c,p,b,n))return false;uint16_t z=sxae16(b+(b[0]==1?3:1));if(!sxae_add(c,n==10?&sxae_sqz_comment:n==5?&sxae_sqz_block4:&sxae_sqz_block,p)||!sxae_data(c,p+n,z))return false;p+=n+z;}
 else {unsigned n=b[0]+2;if(!sx_read(c,p,b,20)||!sxae_bound(c,p,n)||!sxae_add(c,&sxae_sqz_member,p))return false;uint32_t z=sxae32(b+3);if(!sxae_data(c,p+n,z))return false;p+=n+z;}}return false;
}
static bool sxae_sqx(sx_context *c)
{
 uint8_t b[36];int64_t p=25;if(!sx_read(c,0,b,25)||b[2]!='R'||sxae16(b+5)!=25||xx_rt_memcmp(b+7,"-sqx-",5)||!sxae_add(c,&sxae_sqx_main,0))return false;
 for(unsigned i=0;p<c->size&&i<20000;i++){if(!sxae_bound(c,p,7))return true;if(!sx_read(c,p,b,7))return false;uint8_t kind=b[2];uint16_t fl=sxae16(b+3),z=sxae16(b+5);uint64_t packed=0;
 if(z<7||!sxae_bound(c,p,z))return true;if(!sxae_add(c,&sxae_sqx_record,p))return false;
 if(kind=='A'||kind=='S'||kind=='X')return true;
 if(kind=='D'){unsigned n=fl&0x80?36:28;if(fl&8)return true;if(z<7+n||!sx_read(c,p+7,b,n)||!sxae_add(c,fl&0x80?&sxae_sqx_file64:&sxae_sqx_file32,p+7))return false;
 packed=sxae32(b+18);if(fl&0x80)packed|=(uint64_t)sxae32(b+26)<<32;}
 p+=z;while(fl&0x8000){if(++i>=20000||!sxae_bound(c,p,7))return true;if(!sx_read(c,p,b,7))return false;fl=sxae16(b+3);z=sxae16(b+5);if(z<7||!sxae_bound(c,p,z))return true;if(!sxae_add(c,&sxae_sqx_record,p))return false;p+=z;}
 if(!sxae_data(c,p,packed))return false;p+=(int64_t)packed;}return p==c->size;
}
static bool sxae_hap(sx_context *c)
{
 uint8_t b[40];int64_t p=15;if(!sx_read(c,0,b,15)||sxae32(b)!=UINT32_C(0x46483391)||!sxae_add(c,&sxae_hap_header,0))return false;
 for(unsigned i=0;p<c->size&&i<20000;i++){if(!sx_read(c,p,b,40)||sxae32(b)!=UINT32_C(0x574a688e)||!sxae_add(c,&sxae_hap_member,p))return false;uint32_t n=sxae32(b+4);if(n>INT32_MAX||!sxae_data(c,p+40,n))return false;p+=40+n;}return p==c->size;
}
static bool sxae_kwaj(sx_context *c)
{
 uint8_t b[14];if(!sx_read(c,0,b,14)||xx_rt_memcmp(b,"KWAJ\x88\xf0\x27\xd1",8)||!sxae_add(c,&sxae_kwaj_header,0))return false;
 uint16_t method=sxae16(b+8),end=sxae16(b+10),flags=sxae16(b+12);int64_t p=14;if(end<14||!sxae_bound(c,0,end))return false;
 if(flags&1){if(p+4>end||!sxae_add(c,&sxae_kwaj_unpacked_size,p))return false;p+=4;}
 if(flags&2){if(p+2>end)goto payload;if(!sxae_add(c,&sxae_kwaj_unknown,p))return false;p+=2;}
 if(flags&4){uint16_t n;if(p+2>end)goto payload;if(!sx_u16(c,p,false,&n)||!sxae_add(c,&sxae_kwaj_extension_size,p))return false;p+=2;if(n>end-p)goto payload;p+=n;}
 for(unsigned k=0;k<2;k++)if(flags&(8u<<k)){unsigned max=k?3:8,j;for(j=0;j<=max;j++){uint8_t ch;if(p+j>=end)goto payload;if(!sx_read(c,p+j,&ch,1))return false;if(!ch){p+=j+1;break;}}if(j>max)goto payload;}
 /* Native reader does not interpret bit-5 data. Keep those bytes opaque. */
 payload:p=end;if(method==4){for(unsigned k=0;p<c->size&&k<20000;k++){uint16_t n;if(!sx_u16(c,p,false,&n))return false;if(!n)return sxae_add(c,&sxae_kwaj_mszip_end,p);
 uint8_t sig[2];if(n<=2||!sxae_bound(c,p,2u+n)||!sx_read(c,p+2,sig,2)||xx_rt_memcmp(sig,"CK",2)||!sxae_add(c,&sxae_kwaj_mszip_block,p)||!sxae_data(c,p+4,n-2))return false;p+=2+n;}return p==c->size;}return true;
}
static bool sxae_chz(sx_context *c)
{
 int64_t p=0;uint8_t b[24];unsigned depth=0;for(unsigned i=0;p<c->size&&i<20000;i++){if(!sx_read(c,p,b,4))return false;uint32_t tag=sxae32(b);
 if(tag==UINT32_C(0x46684353)){if(!sx_read(c,p,b,24))return false;uint32_t z=sxae32(b+4);uint16_t n=sxae16(b+22);if(z<24u+n||!sxae_bound(c,p,z)||!sxae_add(c,&sxae_chz_file,p)||!sxae_data(c,p+24+n,z-24-n))return false;p+=z;}
 else if(tag==UINT32_C(0x44684353)){if(depth++>=64||!sx_read(c,p,b,10)||!sxae_bound(c,p,10u+b[9])||!sxae_add(c,&sxae_chz_directory,p))return false;p+=10+b[9];}
 else if(tag==UINT32_C(0x64684353)){if(!depth--||!sxae_add(c,&sxae_chz_directory_end,p))return false;p+=4;}
 else return false;}return p==c->size;
}
static bool sxae_swag(sx_context *c)
{
 uint16_t count;int64_t p=0,foot=c->size-129;if(foot<0||!sx_u16(c,foot+127,false,&count)||!count||!sxae_add(c,&sxae_swag_footer,foot))return false;
 for(unsigned i=0;i<count&&i<20000;i++){uint8_t b[187];if(p>foot-187)break;if(!sx_read(c,p,b,187))return false;uint32_t z=sxae32(b+7);if(b[0]!=187u+b[186]||!b[186]||b[186]>12||xx_rt_memcmp(b+2,"-sw1-",5)||z>INT32_MAX||!sxae_bound(c,p,2u+b[0]+z)||p+2+b[0]+z>foot)break;
 if(!sxae_add(c,&sxae_swag_member,p)||!sxae_add(c,&sxae_swag_member_crc,p+b[0])||!sxae_data(c,p+2+b[0],z))return false;p+=2+b[0]+z;}
 if(foot-p==129||foot-p==130){uint8_t a[129],b[129];if(!sx_read(c,foot-129,a,129)||!sx_read(c,foot,b,129))return false;if(!xx_rt_memcmp(a,b,129)&&!sxae_add(c,&sxae_swag_footer,foot-129))return false;}return true;
}
typedef struct sxae_extent {int64_t start,end;} sxae_extent;
static int sxae_extent_order(const void *a,const void *b){const sxae_extent *x=a,*y=b;return x->start<y->start?-1:x->start>y->start?1:x->end<y->end?-1:x->end>y->end?1:0;}
static bool sxae_zpak_frame(sx_context *c,int64_t p,int64_t end)
{
 if(end-p<2)return false;uint8_t ch;int64_t stop=end-1;
 if(!sx_read(c,p,&ch,1)||ch!=0xca||!sx_read(c,stop,&ch,1)||ch)return false;
 if(!sxae_add(c,&sxae_zpak_chunk_marker,p++)||!sxae_add(c,&sxae_zpak_chunk_marker,stop))return false;
 for(unsigned k=0;p<stop&&k<20000;k++){uint16_t q;if(p+2>stop||!sx_u16(c,p,false,&q)||q>(uint64_t)(stop-p-2)||!sxae_add(c,&sxae_zpak_chunk,p))return false;p+=2;if(!q)return true;if(!sxae_data(c,p,q))return false;p+=q;}
 return p==stop;
}
static bool sxae_zpak(sx_context *c)
{
 uint8_t h[6];if(!sx_read(c,0,h,6)||(xx_rt_memcmp(h,"zpak",4)&&xx_rt_memcmp(h,"zpk2",4)))return false;uint16_t n=sxae16(h+4);int64_t end=6+(int64_t)n*33;
 if(!n||n>20000||!sxae_bound(c,0,end)||!sxae_add(c,&sxae_zpak_header,0)||!sx_table(c,&sxae_zpak_member,6,33,n))return false;
 sxae_extent *spans=xx_mem_alloc((size_t)n*sizeof(*spans));if(!spans)return false;size_t count=0;bool ok=false;
 for(unsigned i=0;i<n;i++){uint8_t b[33];if(!sx_read(c,6+(int64_t)i*33,b,33))goto done;uint32_t p=sxae32(b+13),z=sxae32(b+17);if(p>INT32_MAX||z>INT32_MAX||p<end||!sxae_bound(c,p,z))goto done;if(z)spans[count++]=(sxae_extent){p,(int64_t)p+z};}
 xx_rt_qsort(spans,count,sizeof(*spans),sxae_extent_order);
 /* Distinct overlapping member spans cannot establish unambiguous framing.
  * Exact aliases share one physical stream. Both keep their directory rows. */
 for(size_t i=0;i<count;){size_t j=i+1;int64_t stop=spans[i].end;bool ambiguous=false;
  while(j<count&&spans[j].start<stop){if(spans[j].start!=spans[i].start||spans[j].end!=spans[i].end)ambiguous=true;if(spans[j].end>stop)stop=spans[j].end;j++;}
  if(!ambiguous&&h[3]=='k'){size_t saved=c->count;if(!sxae_zpak_frame(c,spans[i].start,spans[i].end)){if(c->failed)goto done;c->count=saved;}}
  i=j;
 }ok=true;
 done:xx_mem_free(spans);return ok;
}
static bool sxae_asymetrix(sx_context *c)
{
 uint8_t h[44];if(!sx_read(c,0,h,44)||sxae32(h)!=UINT32_C(0x63132260)||sxae32(h+4)!=108||!sxae_add(c,&sxae_asymetrix_header,0))return false;uint16_t vol=sxae16(h+40),n=sxae16(h+42);if(vol!=1)return true;int64_t end=44+(int64_t)n*108;
 if(n>20000||!sxae_bound(c,0,end)||!sx_table(c,&sxae_asymetrix_member,44,108,n))return false;
 for(unsigned i=0;i<n;i++){uint8_t b[108];if(!sx_read(c,44+(int64_t)i*108,b,108))return false;if((sxae32(b+30)>>16)!=1)continue;int64_t p=sxae32(b+34),limit=c->size;uint32_t left=sxae32(b+38);if(p<end||p>c->size)continue;
 /* The native reader bounds each chain by the next current-volume offset. */
 for(unsigned j=i+1;j<n;j++){uint8_t next[12];if(!sx_read(c,44+(int64_t)j*108+30,next,12))return false;if((sxae32(next)>>16)==1){limit=sxae32(next+4);break;}}
 if(limit<p||limit>c->size)continue;size_t saved=c->count;bool complete=true;
 for(unsigned k=0;left&&k<20000;k++){uint8_t q[6];if(limit-p<6){complete=false;break;}if(!sx_read(c,p,q,6))return false;uint16_t method=sxae16(q);uint32_t z=sxae32(q+2),decoded=left>4096?4096:left;
 if(method>1||z>(uint64_t)(limit-p-6)||(method==0&&z!=decoded)){complete=false;break;}
 if(!sxae_add(c,&sxae_asymetrix_block,p)||!sxae_data(c,p+6,z))return false;p+=6+z;left-=decoded;}
 if(left||!complete)c->count=saved;
 }return true;
}
static bool sxae_diskexpress(sx_context *c)
{
 uint8_t b[15];if(!sx_read(c,0,b,15)||xx_rt_memcmp(b,"AS",2)||!sxae_add(c,&sxae_diskexpress_header,0))return false;if(!b[10])return true;unsigned n=(unsigned)b[11]*2+(b[12]>1?1:b[12])+1;int64_t p=512;
 if(n>200)return false;for(unsigned i=0;i<n;i++){uint16_t z;if(!sx_u16(c,p,false,&z)||!z||!sxae_add(c,&sxae_diskexpress_track,p)||!sxae_data(c,p+2,z))return false;p+=2+z;}return p==c->size;
}
static bool sxae_ain(sx_context *c){uint8_t b[24];uint32_t p;if(!sx_read(c,0,b,24)||b[0]!='!'||(p=sxae32(b+14))<24||p>=c->size)return false;return sxae_add(c,&sxae_ain_header,0);}
static bool sxae_amigalzx(sx_context *c)
{
 uint8_t b[31];int64_t p=10;if(!sx_read(c,0,b,10)||xx_rt_memcmp(b,"LZX",3)||!sxae_add(c,&sxae_amigalzx_header,0))return false;
 for(unsigned i=0;p<c->size&&i<20000;i++){if(!sx_read(c,p,b,31)||!b[30]||!sxae_add(c,&sxae_amigalzx_member,p))return false;int64_t n=31+b[14]+b[30];uint32_t z=sxae32(b+6);if(!sxae_bound(c,p,n)||!sxae_data(c,p+n,z))return false;p+=n+z;}return p==c->size;
}
static bool sx_archiveextras_supports(xx_file_type_t type)
{
 switch(type){case XX_FILE_TYPE_SEAARC:case XX_FILE_TYPE_BSN:case XX_FILE_TYPE_ARQ:case XX_FILE_TYPE_GXL:case XX_FILE_TYPE_RTA:case XX_FILE_TYPE_SQZ:case XX_FILE_TYPE_SQX:case XX_FILE_TYPE_HAP:case XX_FILE_TYPE_KWAJ:case XX_FILE_TYPE_CHZ:case XX_FILE_TYPE_SWAG:case XX_FILE_TYPE_ZPAK:case XX_FILE_TYPE_ASYMETRIX:case XX_FILE_TYPE_DISKEXPRESS:case XX_FILE_TYPE_AIN:case XX_FILE_TYPE_AMIGALZX:return true;default:return false;}
}
static bool sx_archiveextras_build(sx_context *c)
{
 bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_SEAARC:ok=sxae_arc(c);break;case XX_FILE_TYPE_BSN:ok=sxae_bsn(c);break;case XX_FILE_TYPE_ARQ:ok=sxae_arq(c);break;case XX_FILE_TYPE_GXL:ok=sxae_gxl(c);break;case XX_FILE_TYPE_RTA:ok=sxae_rta(c);break;case XX_FILE_TYPE_SQZ:ok=sxae_sqz(c);break;case XX_FILE_TYPE_SQX:ok=sxae_sqx(c);break;case XX_FILE_TYPE_HAP:ok=sxae_hap(c);break;case XX_FILE_TYPE_KWAJ:ok=sxae_kwaj(c);break;case XX_FILE_TYPE_CHZ:ok=sxae_chz(c);break;case XX_FILE_TYPE_SWAG:ok=sxae_swag(c);break;case XX_FILE_TYPE_ZPAK:ok=sxae_zpak(c);break;case XX_FILE_TYPE_ASYMETRIX:ok=sxae_asymetrix(c);break;case XX_FILE_TYPE_DISKEXPRESS:ok=sxae_diskexpress(c);break;case XX_FILE_TYPE_AIN:ok=sxae_ain(c);break;case XX_FILE_TYPE_AMIGALZX:ok=sxae_amigalzx(c);break;default:return false;}return ok&&sxae_finish(c);
}
