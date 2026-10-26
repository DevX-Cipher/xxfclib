/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivepackages_scope.txt. */
static const xx_data_struct_field_desc sxap_kpck_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("method_flags","uint32",8,4,SX_FLAGS),
};
static const sx_layout sxap_kpck_header = {UINT32_C(0x60720001),"kpck_header",sxap_kpck_header_fields,SX_COUNT(sxap_kpck_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_kpck_filter_fields[] = {
 SX_FIELD("call_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("marker","uint8",4,1,SX_NONE),
};
static const sx_layout sxap_kpck_filter = {UINT32_C(0x60720002),"kpck_filter",sxap_kpck_filter_fields,SX_COUNT(sxap_kpck_filter_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_header_fields[] = {
 SX_FIELD("signature","char[9]",0,9,SX_SIGNATURE),
 SX_FIELD("version","char[1]",9,1,SX_NONE),
 SX_FIELD("marker","uint8[6]",10,6,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",16,2,SX_COUNT_PROP),
};
static const sx_layout sxap_lingvo_header = {UINT32_C(0x60720003),"lingvo_header",sxap_lingvo_header_fields,SX_COUNT(sxap_lingvo_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_index_v1_fields[] = {
 SX_FIELD("name","char[46]",0,46,SX_NONE),
 SX_FIELD("descriptor_offset","uint32",46,4,SX_OFFSET),
 SX_FIELD("unknown","uint8[4]",50,4,SX_NONE),
};
static const sx_layout sxap_lingvo_index_v1 = {UINT32_C(0x60720004),"lingvo_index_v1",sxap_lingvo_index_v1_fields,SX_COUNT(sxap_lingvo_index_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_member_v1_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("payload_size","uint32",13,4,SX_SIZE),
 SX_FIELD("dos_datetime","uint32",17,4,SX_NONE),
 SX_FIELD("fragment_method","uint16",21,2,SX_NONE),
};
static const sx_layout sxap_lingvo_member_v1 = {UINT32_C(0x60720005),"lingvo_member_v1",sxap_lingvo_member_v1_fields,SX_COUNT(sxap_lingvo_member_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_index_v2_fields[] = {
 SX_FIELD("name","char[101]",0,101,SX_NONE),
 SX_FIELD("descriptor_offset","uint32",101,4,SX_OFFSET),
 SX_FIELD("unknown","uint8[4]",105,4,SX_NONE),
};
static const sx_layout sxap_lingvo_index_v2 = {UINT32_C(0x60720006),"lingvo_index_v2",sxap_lingvo_index_v2_fields,SX_COUNT(sxap_lingvo_index_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_member_v2_fields[] = {
 SX_FIELD("name","char[61]",0,61,SX_NONE),
 SX_FIELD("payload_size","uint32",61,4,SX_SIZE),
 SX_FIELD("dos_datetime","uint32",65,4,SX_NONE),
 SX_FIELD("fragment_method","uint16",69,2,SX_NONE),
};
static const sx_layout sxap_lingvo_member_v2 = {UINT32_C(0x60720007),"lingvo_member_v2",sxap_lingvo_member_v2_fields,SX_COUNT(sxap_lingvo_member_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxap_finear_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("marker","uint8[3]",6,3,SX_SIGNATURE),
 SX_FIELD("crc16_word","uint32",9,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",13,4,SX_SIZE),
};
static const sx_layout sxap_finear_header = {UINT32_C(0x60720008),"finear_header",sxap_finear_header_fields,SX_COUNT(sxap_finear_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_stream_header_fields[] = {
 SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
 SX_FIELD("parameters","uint8[16]",10,16,SX_NONE),
};
static const sx_layout sxap_lingvo_stream_header = {UINT32_C(0x60720009),"lingvo_stream_header",sxap_lingvo_stream_header_fields,SX_COUNT(sxap_lingvo_stream_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_code_length_fields[] = {
 SX_FIELD("code_bits","uint8",0,1,SX_NONE),
};
static const sx_layout sxap_lingvo_code_length = {UINT32_C(0x6072000a),"lingvo_code_length",sxap_lingvo_code_length_fields,SX_COUNT(sxap_lingvo_code_length_fields),SX_LE};
static const xx_data_struct_field_desc sxap_legacy_lz4_magic_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxap_legacy_lz4_magic = {UINT32_C(0x6072000b),"legacy_lz4_magic",sxap_legacy_lz4_magic_fields,SX_COUNT(sxap_legacy_lz4_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxap_legacy_lz4_block_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxap_legacy_lz4_block = {UINT32_C(0x6072000c),"legacy_lz4_block",sxap_legacy_lz4_block_fields,SX_COUNT(sxap_legacy_lz4_block_fields),SX_LE};
static const xx_data_struct_field_desc sxap_legacy_lz4_skip_fields[] = {
 SX_FIELD("skip_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxap_legacy_lz4_skip = {UINT32_C(0x6072000d),"legacy_lz4_skip",sxap_legacy_lz4_skip_fields,SX_COUNT(sxap_legacy_lz4_skip_fields),SX_LE};
static const xx_data_struct_field_desc sxap_ssm_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[12]",4,12,SX_NONE),
 SX_FIELD("dos_date","uint16",16,2,SX_NONE),
 SX_FIELD("dos_time","uint16",18,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("window_size","uint32",24,4,SX_SIZE),
 SX_FIELD("unused","uint32",28,4,SX_NONE),
 SX_FIELD("method","uint32",32,4,SX_NONE),
};
static const sx_layout sxap_ssm_header = {UINT32_C(0x6072000e),"ssm_header",sxap_ssm_header_fields,SX_COUNT(sxap_ssm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_spark_prefix_fields[] = {
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("method","uint8",1,1,SX_NONE),
 SX_FIELD("name","char[13]",2,13,SX_NONE),
 SX_FIELD("compressed_size","uint32",15,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",19,2,SX_NONE),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("crc16","uint16",23,2,SX_CHECKSUM),
};
static const sx_layout sxap_spark_prefix = {UINT32_C(0x6072000f),"spark_prefix",sxap_spark_prefix_fields,SX_COUNT(sxap_spark_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxap_spark_original_size_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxap_spark_original_size = {UINT32_C(0x60720010),"spark_original_size",sxap_spark_original_size_fields,SX_COUNT(sxap_spark_original_size_fields),SX_LE};
static const xx_data_struct_field_desc sxap_spark_riscos_fields[] = {
 SX_FIELD("load_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("exec_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("attributes","uint32",8,4,SX_FLAGS),
};
static const sx_layout sxap_spark_riscos = {UINT32_C(0x60720011),"spark_riscos",sxap_spark_riscos_fields,SX_COUNT(sxap_spark_riscos_fields),SX_LE};
static const xx_data_struct_field_desc sxap_spark_end_fields[] = {
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("method","uint8",1,1,SX_NONE),
};
static const sx_layout sxap_spark_end = {UINT32_C(0x60720012),"spark_end",sxap_spark_end_fields,SX_COUNT(sxap_spark_end_fields),SX_LE};
static const xx_data_struct_field_desc sxap_wrzl_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxap_wrzl_header = {UINT32_C(0x60720013),"wrzl_header",sxap_wrzl_header_fields,SX_COUNT(sxap_wrzl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_wrzl_block_size_fields[] = {
 SX_FIELD("compressed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxap_wrzl_block_size = {UINT32_C(0x60720014),"wrzl_block_size",sxap_wrzl_block_size_fields,SX_COUNT(sxap_wrzl_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxap_wrzl_mode_fields[] = {
 SX_FIELD("mode","uint8",0,1,SX_NONE),
};
static const sx_layout sxap_wrzl_mode = {UINT32_C(0x60720015),"wrzl_mode",sxap_wrzl_mode_fields,SX_COUNT(sxap_wrzl_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxap_wrzl_control_fields[] = {
 SX_FIELD("control_bits","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxap_wrzl_control = {UINT32_C(0x60720016),"wrzl_control",sxap_wrzl_control_fields,SX_COUNT(sxap_wrzl_control_fields),SX_BE};
static const xx_data_struct_field_desc sxap_qip_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("index_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_NONE),
 SX_FIELD("reserved","uint32",12,4,SX_NONE),
};
static const sx_layout sxap_qip_header = {UINT32_C(0x60720017),"qip_header",sxap_qip_header_fields,SX_COUNT(sxap_qip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_qip_index_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name","char[12]",4,12,SX_NONE),
};
static const sx_layout sxap_qip_index = {UINT32_C(0x60720018),"qip_index",sxap_qip_index_fields,SX_COUNT(sxap_qip_index_fields),SX_LE};
static const xx_data_struct_field_desc sxap_qip_member_v1_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sequence_number","uint16",8,2,SX_NONE),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",11,2,SX_NONE),
 SX_FIELD("dos_date","uint16",13,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",15,4,SX_SIZE),
 SX_FIELD("name","char[13]",19,13,SX_NONE),
};
static const sx_layout sxap_qip_member_v1 = {UINT32_C(0x60720019),"qip_member_v1",sxap_qip_member_v1_fields,SX_COUNT(sxap_qip_member_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxap_qip_member_v2_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sequence_number","uint16",8,2,SX_NONE),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",11,2,SX_NONE),
 SX_FIELD("dos_date","uint16",13,2,SX_NONE),
 SX_FIELD("unknown","uint32",15,4,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",19,4,SX_SIZE),
 SX_FIELD("name","char[13]",23,13,SX_NONE),
};
static const sx_layout sxap_qip_member_v2 = {UINT32_C(0x6072001a),"qip_member_v2",sxap_qip_member_v2_fields,SX_COUNT(sxap_qip_member_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxap_twrx_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("reserved","uint16",6,2,SX_NONE),
 SX_FIELD("method","uint16",8,2,SX_NONE),
 SX_FIELD("stamp_low","uint32",10,4,SX_NONE),
 SX_FIELD("packed_crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("name_size","uint32",26,4,SX_SIZE),
};
static const sx_layout sxap_twrx_header = {UINT32_C(0x6072001b),"twrx_header",sxap_twrx_header_fields,SX_COUNT(sxap_twrx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_twrx_deflate_fields[] = {
 SX_FIELD("method","uint16",0,2,SX_NONE),
 SX_FIELD("stream_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxap_twrx_deflate = {UINT32_C(0x6072001c),"twrx_deflate",sxap_twrx_deflate_fields,SX_COUNT(sxap_twrx_deflate_fields),SX_LE};
static const xx_data_struct_field_desc sxap_beospkg_header_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxap_beospkg_header = {UINT32_C(0x6072001d),"beospkg_header",sxap_beospkg_header_fields,SX_COUNT(sxap_beospkg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_beospkg_tag_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("reserved","uint8",4,1,SX_NONE),
 SX_FIELD("payload_type","uint16",5,2,SX_NONE),
};
static const sx_layout sxap_beospkg_tag = {UINT32_C(0x6072001e),"beospkg_tag",sxap_beospkg_tag_fields,SX_COUNT(sxap_beospkg_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxap_beospkg_value32_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxap_beospkg_value32 = {UINT32_C(0x6072001f),"beospkg_value32",sxap_beospkg_value32_fields,SX_COUNT(sxap_beospkg_value32_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_value64_fields[] = {
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
static const sx_layout sxap_beospkg_value64 = {UINT32_C(0x60720020),"beospkg_value64",sxap_beospkg_value64_fields,SX_COUNT(sxap_beospkg_value64_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_offset64_fields[] = {
 SX_FIELD("file_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxap_beospkg_offset64 = {UINT32_C(0x60720021),"beospkg_offset64",sxap_beospkg_offset64_fields,SX_COUNT(sxap_beospkg_offset64_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_size64_fields[] = {
 SX_FIELD("uncompressed_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxap_beospkg_size64 = {UINT32_C(0x60720022),"beospkg_size64",sxap_beospkg_size64_fields,SX_COUNT(sxap_beospkg_size64_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_length_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxap_beospkg_length = {UINT32_C(0x60720023),"beospkg_length",sxap_beospkg_length_fields,SX_COUNT(sxap_beospkg_length_fields),SX_BE};
static const xx_data_struct_field_desc sxap_beospkg_chunk_fields[] = {
 SX_FIELD("compressed_size","uint64",0,8,SX_SIZE),
 SX_FIELD("uncompressed_size","uint64",8,8,SX_SIZE),
 SX_FIELD("method","uint32",16,4,SX_NONE),
};
static const sx_layout sxap_beospkg_chunk = {UINT32_C(0x60720024),"beospkg_chunk",sxap_beospkg_chunk_fields,SX_COUNT(sxap_beospkg_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxap_cpoint_setup_fields[] = {
 SX_FIELD("tag","uint32",0,4,SX_NONE),
 SX_FIELD("reserved","uint8",4,1,SX_NONE),
 SX_FIELD("payload_size","uint32",5,4,SX_SIZE),
 SX_FIELD("reserved2","uint32",9,4,SX_NONE),
};
static const sx_layout sxap_cpoint_setup = {UINT32_C(0x60720025),"cpoint_setup",sxap_cpoint_setup_fields,SX_COUNT(sxap_cpoint_setup_fields),SX_LE};
static const xx_data_struct_field_desc sxap_cpoint_file_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_NONE),
 SX_FIELD("payload_size","uint32",1,4,SX_SIZE),
 SX_FIELD("name_size","uint32",5,4,SX_SIZE),
 SX_FIELD("metadata","uint32",9,4,SX_NONE),
};
static const sx_layout sxap_cpoint_file = {UINT32_C(0x60720026),"cpoint_file",sxap_cpoint_file_fields,SX_COUNT(sxap_cpoint_file_fields),SX_LE};
static const xx_data_struct_field_desc sxap_cpoint_footer_fields[] = {
 SX_FIELD("footer","uint32",0,4,SX_NONE),
};
static const sx_layout sxap_cpoint_footer = {UINT32_C(0x60720027),"cpoint_footer",sxap_cpoint_footer_fields,SX_COUNT(sxap_cpoint_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxap_mlbft_header_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("version","uint16",2,2,SX_NONE),
};
static const sx_layout sxap_mlbft_header = {UINT32_C(0x60720028),"mlbft_header",sxap_mlbft_header_fields,SX_COUNT(sxap_mlbft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_mlbft_member_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("name","char[13]",8,13,SX_NONE),
};
static const sx_layout sxap_mlbft_member = {UINT32_C(0x60720029),"mlbft_member",sxap_mlbft_member_fields,SX_COUNT(sxap_mlbft_member_fields),SX_LE};
static const xx_data_struct_field_desc sxap_oberon_member_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_NONE),
 SX_FIELD("unknown","uint8[64]",64,64,SX_NONE),
 SX_FIELD("compressed_size","uint32",128,4,SX_SIZE),
 SX_FIELD("flags","uint32",132,4,SX_FLAGS),
};
static const sx_layout sxap_oberon_member = {UINT32_C(0x6072002a),"oberon_member",sxap_oberon_member_fields,SX_COUNT(sxap_oberon_member_fields),SX_LE};
static const xx_data_struct_field_desc sxap_oberon_szdd_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("mode","uint8",8,1,SX_NONE),
 SX_FIELD("missing_filename_byte","uint8",9,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",10,4,SX_SIZE),
};
static const sx_layout sxap_oberon_szdd = {UINT32_C(0x6072002b),"oberon_szdd",sxap_oberon_szdd_fields,SX_COUNT(sxap_oberon_szdd_fields),SX_LE};
static const xx_data_struct_field_desc sxap_solitaire_header_fields[] = {
 SX_FIELD("banner","char[100]",0,100,SX_SIGNATURE),
 SX_FIELD("eof_marker","uint8",100,1,SX_SIGNATURE),
 SX_FIELD("marker","uint32",101,4,SX_SIGNATURE),
 SX_FIELD("producer","char[2]",105,2,SX_SIGNATURE),
 SX_FIELD("unknown","uint8[8]",107,8,SX_NONE),
 SX_FIELD("category_count","uint16",115,2,SX_COUNT_PROP),
 SX_FIELD("member_count","uint16",117,2,SX_COUNT_PROP),
};
static const sx_layout sxap_solitaire_header = {UINT32_C(0x6072002c),"solitaire_header",sxap_solitaire_header_fields,SX_COUNT(sxap_solitaire_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_solitaire_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",13,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",17,4,SX_SIZE),
 SX_FIELD("attributes","uint16",21,2,SX_FLAGS),
 SX_FIELD("value","uint16",23,2,SX_NONE),
};
static const sx_layout sxap_solitaire_member = {UINT32_C(0x6072002d),"solitaire_member",sxap_solitaire_member_fields,SX_COUNT(sxap_solitaire_member_fields),SX_LE};
static const xx_data_struct_field_desc sxap_rdc_block_fields[] = {
 SX_FIELD("size_or_stored_length","int16",0,2,SX_NONE),
};
static const sx_layout sxap_rdc_block = {UINT32_C(0x6072002e),"rdc_block",sxap_rdc_block_fields,SX_COUNT(sxap_rdc_block_fields),SX_LE};
static const xx_data_struct_field_desc sxap_kgb2_header_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("encrypted","uint8",8,1,SX_FLAGS),
 SX_FIELD("algorithm","uint8",9,1,SX_NONE),
 SX_FIELD("compression_mode","uint8",10,1,SX_NONE),
 SX_FIELD("member_count","uint32",11,4,SX_COUNT_PROP),
};
static const sx_layout sxap_kgb2_header = {UINT32_C(0x6072002f),"kgb2_header",sxap_kgb2_header_fields,SX_COUNT(sxap_kgb2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_kgb2_member_fields[] = {
 SX_FIELD("record_size","uint32",0,4,SX_SIZE),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("padding","uint32",8,4,SX_NONE),
 SX_FIELD("creation_time","int64",12,8,SX_TIME),
 SX_FIELD("access_time","int64",20,8,SX_TIME),
 SX_FIELD("modification_time","int64",28,8,SX_TIME),
 SX_FIELD("uncompressed_size","int64",36,8,SX_SIZE),
 SX_FIELD("name","uint16[260]",44,520,SX_NONE),
 SX_FIELD("byte_sum","uint64",564,8,SX_CHECKSUM),
};
static const sx_layout sxap_kgb2_member = {UINT32_C(0x60720030),"kgb2_member",sxap_kgb2_member_fields,SX_COUNT(sxap_kgb2_member_fields),SX_LE};
static const xx_data_struct_field_desc sxap_kgb2_encryption_fields[] = {
 SX_FIELD("encrypted_check","uint64",0,8,SX_NONE),
};
static const sx_layout sxap_kgb2_encryption = {UINT32_C(0x60720031),"kgb2_encryption",sxap_kgb2_encryption_fields,SX_COUNT(sxap_kgb2_encryption_fields),SX_LE};
static const xx_data_struct_field_desc sxap_tar_nextstep_header_fields[] = {
 SX_FIELD("name","char[225]",0,225,SX_NONE),
 SX_FIELD("mode","ascii_octal_padded[8]",225,8,SX_FLAGS),
 SX_FIELD("uid","ascii_octal_padded[8]",233,8,SX_NONE),
 SX_FIELD("gid","ascii_octal_padded[8]",241,8,SX_NONE),
 SX_FIELD("payload_size","ascii_octal_padded[12]",249,12,SX_SIZE),
 SX_FIELD("modification_time","ascii_octal_padded[12]",261,12,SX_TIME),
 SX_FIELD("checksum","ascii_octal_padded[8]",273,8,SX_CHECKSUM),
 SX_FIELD("typeflag","char[1]",281,1,SX_NONE),
 SX_FIELD("unknown_tail","uint8[230]",282,230,SX_NONE),
};
static const sx_layout sxap_tar_nextstep_header = {UINT32_C(0x60720032),"tar_nextstep_header",sxap_tar_nextstep_header_fields,SX_COUNT(sxap_tar_nextstep_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_volume_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("volume_number","uint16",6,2,SX_NONE),
 SX_FIELD("backup_time","int32",8,4,SX_TIME),
 SX_FIELD("since_time","int32",12,4,SX_TIME),
 SX_FIELD("volume_words","int32",16,4,SX_NONE),
 SX_FIELD("disk","char[16]",20,16,SX_NONE),
 SX_FIELD("filesystem","char[16]",36,16,SX_NONE),
 SX_FIELD("user","char[16]",52,16,SX_NONE),
 SX_FIELD("dump_level","int16",68,2,SX_NONE),
 SX_FIELD("padding","uint8[2]",70,2,SX_NONE),
};
static const sx_layout sxap_bff_volume = {UINT32_C(0x60720033),"bff_volume",sxap_bff_volume_fields,SX_COUNT(sxap_bff_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_legacy_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("inode","uint16",6,2,SX_NONE),
 SX_FIELD("mode","uint16",8,2,SX_FLAGS),
 SX_FIELD("link_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("uid","uint16",12,2,SX_NONE),
 SX_FIELD("gid","uint16",14,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",16,4,SX_SIZE),
 SX_FIELD("access_time","int32",20,4,SX_TIME),
 SX_FIELD("modification_time","int32",24,4,SX_TIME),
 SX_FIELD("change_time","int32",28,4,SX_TIME),
 SX_FIELD("device_major","uint16",32,2,SX_NONE),
 SX_FIELD("device_minor","uint16",34,2,SX_NONE),
 SX_FIELD("rdevice_major","uint16",36,2,SX_NONE),
 SX_FIELD("rdevice_minor","uint16",38,2,SX_NONE),
 SX_FIELD("compressed_size","int32",40,4,SX_SIZE),
 SX_FIELD("padding","int32",44,4,SX_NONE),
};
static const sx_layout sxap_bff_legacy = {UINT32_C(0x60720034),"bff_legacy",sxap_bff_legacy_fields,SX_COUNT(sxap_bff_legacy_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_member_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("link_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("inode","uint32",8,4,SX_NONE),
 SX_FIELD("mode","uint32",12,4,SX_FLAGS),
 SX_FIELD("uid","uint32",16,4,SX_NONE),
 SX_FIELD("gid","uint32",20,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",24,4,SX_SIZE),
 SX_FIELD("access_time","int32",28,4,SX_TIME),
 SX_FIELD("modification_time","int32",32,4,SX_TIME),
 SX_FIELD("change_time","int32",36,4,SX_TIME),
 SX_FIELD("device_major","uint32",40,4,SX_NONE),
 SX_FIELD("device_minor","uint32",44,4,SX_NONE),
 SX_FIELD("rdevice_major","uint32",48,4,SX_NONE),
 SX_FIELD("rdevice_minor","uint32",52,4,SX_NONE),
 SX_FIELD("compressed_size","int32",56,4,SX_SIZE),
 SX_FIELD("padding","int32",60,4,SX_NONE),
};
static const sx_layout sxap_bff_member = {UINT32_C(0x60720035),"bff_member",sxap_bff_member_fields,SX_COUNT(sxap_bff_member_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_compact_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("link_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("inode","uint32",8,4,SX_NONE),
 SX_FIELD("mode","uint32",12,4,SX_FLAGS),
 SX_FIELD("uid","uint32",16,4,SX_NONE),
 SX_FIELD("gid","uint32",20,4,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("access_time","uint32",28,4,SX_TIME),
 SX_FIELD("modification_time","uint32",32,4,SX_TIME),
 SX_FIELD("change_time","uint32",36,4,SX_TIME),
 SX_FIELD("unknown","uint8[8]",40,8,SX_NONE),
 SX_FIELD("compressed_size","uint32",48,4,SX_SIZE),
 SX_FIELD("unknown_tail","uint8[20]",52,20,SX_NONE),
};
static const sx_layout sxap_bff_compact = {UINT32_C(0x60720036),"bff_compact",sxap_bff_compact_fields,SX_COUNT(sxap_bff_compact_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_security_sizes_fields[] = {
 SX_FIELD("acl_words","uint32",0,4,SX_NONE),
 SX_FIELD("pcl_words","uint32",4,4,SX_NONE),
};
static const sx_layout sxap_bff_security_sizes = {UINT32_C(0x60720037),"bff_security_sizes",sxap_bff_security_sizes_fields,SX_COUNT(sxap_bff_security_sizes_fields),SX_LE};
static const xx_data_struct_field_desc sxap_bff_terminator_fields[] = {
 SX_FIELD("record_length_words","uint8",0,1,SX_NONE),
 SX_FIELD("record_type","uint8",1,1,SX_NONE),
 SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
};
static const sx_layout sxap_bff_terminator = {UINT32_C(0x60720038),"bff_terminator",sxap_bff_terminator_fields,SX_COUNT(sxap_bff_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxap_archivepackages_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxap_archivepackages_dcl = {UINT32_C(0x60720039),"archivepackages_dcl",sxap_archivepackages_dcl_fields,SX_COUNT(sxap_archivepackages_dcl_fields),SX_LE};
static const xx_data_struct_field_desc sxap_archivepackages_name_fields[] = {
 SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxap_archivepackages_name = {UINT32_C(0x6072003a),"archivepackages_name",sxap_archivepackages_name_fields,SX_COUNT(sxap_archivepackages_name_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_block_fields[] = {
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("operating_system","uint16",2,2,SX_NONE),
 SX_FIELD("subsystem","uint16",4,2,SX_NONE),
 SX_FIELD("application","uint16",6,2,SX_NONE),
 SX_FIELD("block_number","uint32",8,4,SX_NONE),
 SX_FIELD("spare1","uint8[20]",12,20,SX_NONE),
 SX_FIELD("structure_level","uint16",32,2,SX_NONE),
 SX_FIELD("volume_number","uint16",34,2,SX_NONE),
 SX_FIELD("crc32","uint32",36,4,SX_CHECKSUM),
 SX_FIELD("block_size","int32",40,4,SX_SIZE),
 SX_FIELD("flags","uint32",44,4,SX_FLAGS),
 SX_FIELD("saveset_name","char[32]",48,32,SX_NONE),
 SX_FIELD("file_id","uint16[3]",80,6,SX_NONE),
 SX_FIELD("directory_id","uint16[3]",86,6,SX_NONE),
 SX_FIELD("filename","char[128]",92,128,SX_NONE),
 SX_FIELD("record_format","uint8",220,1,SX_NONE),
 SX_FIELD("record_attributes","uint8",221,1,SX_FLAGS),
 SX_FIELD("record_size","uint16",222,2,SX_SIZE),
 SX_FIELD("bucket_size","uint8",224,1,SX_NONE),
 SX_FIELD("fixed_control_size","uint8",225,1,SX_SIZE),
 SX_FIELD("maximum_record","uint16",226,2,SX_SIZE),
 SX_FIELD("file_size","uint32",228,4,SX_NONE),
 SX_FIELD("spare2","uint8[22]",232,22,SX_NONE),
 SX_FIELD("checksum","uint16",254,2,SX_CHECKSUM),
};
static const sx_layout sxap_vms_backup_block = {UINT32_C(0x6072003b),"vms_backup_block",sxap_vms_backup_block_fields,SX_COUNT(sxap_vms_backup_block_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_record_fields[] = {
 SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
 SX_FIELD("record_type","uint16",2,2,SX_NONE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("spare","uint32",12,4,SX_NONE),
};
static const sx_layout sxap_vms_backup_record = {UINT32_C(0x6072003c),"vms_backup_record",sxap_vms_backup_record_fields,SX_COUNT(sxap_vms_backup_record_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_file_version_fields[] = {
 SX_FIELD("structure_level","uint16",0,2,SX_NONE),
};
static const sx_layout sxap_vms_backup_file_version = {UINT32_C(0x6072003d),"vms_backup_file_version",sxap_vms_backup_file_version_fields,SX_COUNT(sxap_vms_backup_file_version_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_attribute_fields[] = {
 SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
 SX_FIELD("tag","uint16",2,2,SX_NONE),
};
static const sx_layout sxap_vms_backup_attribute = {UINT32_C(0x6072003e),"vms_backup_attribute",sxap_vms_backup_attribute_fields,SX_COUNT(sxap_vms_backup_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_fid_fields[] = {
 SX_FIELD("number","uint16",0,2,SX_NONE),
 SX_FIELD("sequence","uint16",2,2,SX_NONE),
 SX_FIELD("relative_volume_and_extension","uint16",4,2,SX_NONE),
};
static const sx_layout sxap_vms_backup_fid = {UINT32_C(0x6072003f),"vms_backup_fid",sxap_vms_backup_fid_fields,SX_COUNT(sxap_vms_backup_fid_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_characteristics_fields[] = {
 SX_FIELD("characteristics","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxap_vms_backup_characteristics = {UINT32_C(0x60720040),"vms_backup_characteristics",sxap_vms_backup_characteristics_fields,SX_COUNT(sxap_vms_backup_characteristics_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_date_fields[] = {
 SX_FIELD("vms_time","uint64",0,8,SX_NONE),
};
static const sx_layout sxap_vms_backup_date = {UINT32_C(0x60720041),"vms_backup_date",sxap_vms_backup_date_fields,SX_COUNT(sxap_vms_backup_date_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vms_backup_fat_fields[] = {
 SX_FIELD("record_type","uint8",0,1,SX_NONE),
 SX_FIELD("record_attributes","uint8",1,1,SX_FLAGS),
 SX_FIELD("record_size","uint16",2,2,SX_SIZE),
 SX_FIELD("high_block","uint32_pdp",4,4,SX_NONE),
 SX_FIELD("eof_block","uint32_pdp",8,4,SX_NONE),
 SX_FIELD("first_free_byte","uint16",12,2,SX_NONE),
 SX_FIELD("bucket_size","uint8",14,1,SX_NONE),
 SX_FIELD("fixed_control_size","uint8",15,1,SX_SIZE),
 SX_FIELD("maximum_record","uint16",16,2,SX_SIZE),
 SX_FIELD("default_extend","uint16",18,2,SX_NONE),
 SX_FIELD("global_buffers","uint16",20,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[8]",22,8,SX_NONE),
 SX_FIELD("version_limit","uint16",30,2,SX_NONE),
};
static const sx_layout sxap_vms_backup_fat = {UINT32_C(0x60720042),"vms_backup_fat",sxap_vms_backup_fat_fields,SX_COUNT(sxap_vms_backup_fat_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_header_fields[] = {
 SX_FIELD("banner","char[32]",0,32,SX_SIGNATURE),
 SX_FIELD("unknown1","uint8[24]",32,24,SX_NONE),
 SX_FIELD("table_size","uint32",56,4,SX_SIZE),
 SX_FIELD("unknown2","uint8[4]",60,4,SX_NONE),
 SX_FIELD("record_count","uint32",64,4,SX_COUNT_PROP),
 SX_FIELD("unknown3","uint8[12]",68,12,SX_NONE),
};
static const sx_layout sxap_vmspcsi_header = {UINT32_C(0x60720043),"vmspcsi_header",sxap_vmspcsi_header_fields,SX_COUNT(sxap_vmspcsi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_table_fields[] = {
 SX_FIELD("table_size","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved1","uint32",4,4,SX_NONE),
 SX_FIELD("magic","uint32",8,4,SX_SIGNATURE),
 SX_FIELD("reserved2","uint32",12,4,SX_NONE),
 SX_FIELD("context_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("header_size","uint16",18,2,SX_SIZE),
};
static const sx_layout sxap_vmspcsi_table = {UINT32_C(0x60720044),"vmspcsi_table",sxap_vmspcsi_table_fields,SX_COUNT(sxap_vmspcsi_table_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_context_fields[] = {
 SX_FIELD("block_size","uint16",0,2,SX_SIZE),
 SX_FIELD("first_symbol","uint8",2,1,SX_NONE),
 SX_FIELD("last_symbol","uint8",3,1,SX_NONE),
 SX_FIELD("reserved","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("node_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("map_offset","uint16",10,2,SX_OFFSET),
};
static const sx_layout sxap_vmspcsi_context = {UINT32_C(0x60720045),"vmspcsi_context",sxap_vmspcsi_context_fields,SX_COUNT(sxap_vmspcsi_context_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_bitmap_fields[] = {
 SX_FIELD("leaf_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxap_vmspcsi_bitmap = {UINT32_C(0x60720046),"vmspcsi_bitmap",sxap_vmspcsi_bitmap_fields,SX_COUNT(sxap_vmspcsi_bitmap_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_node_fields[] = {
 SX_FIELD("symbol_or_child","uint8",0,1,SX_NONE),
};
static const sx_layout sxap_vmspcsi_node = {UINT32_C(0x60720047),"vmspcsi_node",sxap_vmspcsi_node_fields,SX_COUNT(sxap_vmspcsi_node_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_context_map_fields[] = {
 SX_FIELD("next_context","uint16",0,2,SX_NONE),
};
static const sx_layout sxap_vmspcsi_context_map = {UINT32_C(0x60720048),"vmspcsi_context_map",sxap_vmspcsi_context_map_fields,SX_COUNT(sxap_vmspcsi_context_map_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_record_fields[] = {
 SX_FIELD("unknown_record_word","uint16",0,2,SX_NONE),
};
static const sx_layout sxap_vmspcsi_record = {UINT32_C(0x60720049),"vmspcsi_record",sxap_vmspcsi_record_fields,SX_COUNT(sxap_vmspcsi_record_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_prefix_fields[] = {
 SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxap_vmsdb_prefix = {UINT32_C(0x6072004a),"vmsdb_prefix",sxap_vmsdb_prefix_fields,SX_COUNT(sxap_vmsdb_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_short_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_NONE),
 SX_FIELD("length","uint8",1,1,SX_SIZE),
};
static const sx_layout sxap_vmsdb_short = {UINT32_C(0x6072004b),"vmsdb_short",sxap_vmsdb_short_fields,SX_COUNT(sxap_vmsdb_short_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_indefinite_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_NONE),
 SX_FIELD("length_form","uint8",1,1,SX_NONE),
};
static const sx_layout sxap_vmsdb_indefinite = {UINT32_C(0x6072004c),"vmsdb_indefinite",sxap_vmsdb_indefinite_fields,SX_COUNT(sxap_vmsdb_indefinite_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_long1_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_NONE),
 SX_FIELD("length_form","uint8",1,1,SX_NONE),
 SX_FIELD("length","uint8",2,1,SX_SIZE),
};
static const sx_layout sxap_vmsdb_long1 = {UINT32_C(0x6072004d),"vmsdb_long1",sxap_vmsdb_long1_fields,SX_COUNT(sxap_vmsdb_long1_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmsdb_long2_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_NONE),
 SX_FIELD("length_form","uint8",1,1,SX_NONE),
 SX_FIELD("length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxap_vmsdb_long2 = {UINT32_C(0x6072004e),"vmsdb_long2",sxap_vmsdb_long2_fields,SX_COUNT(sxap_vmsdb_long2_fields),SX_BE};
static const xx_data_struct_field_desc sxap_vmsdb_attributes_fields[] = {
 SX_FIELD("unknown1","uint8[19]",0,19,SX_NONE),
 SX_FIELD("allocated_blocks","int32",19,4,SX_NONE),
 SX_FIELD("unknown2","uint8[8]",23,8,SX_NONE),
 SX_FIELD("last_block_bytes","uint16",31,2,SX_NONE),
 SX_FIELD("unknown_tail","uint8[138]",33,138,SX_NONE),
};
static const sx_layout sxap_vmsdb_attributes = {UINT32_C(0x6072004f),"vmsdb_attributes",sxap_vmsdb_attributes_fields,SX_COUNT(sxap_vmsdb_attributes_fields),SX_LE};
static const sx_layout *const sx_archivepackages_layouts[] = {
 &sxap_kpck_header,
 &sxap_kpck_filter,
 &sxap_lingvo_header,
 &sxap_lingvo_index_v1,
 &sxap_lingvo_member_v1,
 &sxap_lingvo_index_v2,
 &sxap_lingvo_member_v2,
 &sxap_finear_header,
 &sxap_lingvo_stream_header,
 &sxap_lingvo_code_length,
 &sxap_legacy_lz4_magic,
 &sxap_legacy_lz4_block,
 &sxap_legacy_lz4_skip,
 &sxap_ssm_header,
 &sxap_spark_prefix,
 &sxap_spark_original_size,
 &sxap_spark_riscos,
 &sxap_spark_end,
 &sxap_wrzl_header,
 &sxap_wrzl_block_size,
 &sxap_wrzl_mode,
 &sxap_wrzl_control,
 &sxap_qip_header,
 &sxap_qip_index,
 &sxap_qip_member_v1,
 &sxap_qip_member_v2,
 &sxap_twrx_header,
 &sxap_twrx_deflate,
 &sxap_beospkg_header,
 &sxap_beospkg_tag,
 &sxap_beospkg_value32,
 &sxap_beospkg_value64,
 &sxap_beospkg_offset64,
 &sxap_beospkg_size64,
 &sxap_beospkg_length,
 &sxap_beospkg_chunk,
 &sxap_cpoint_setup,
 &sxap_cpoint_file,
 &sxap_cpoint_footer,
 &sxap_mlbft_header,
 &sxap_mlbft_member,
 &sxap_oberon_member,
 &sxap_oberon_szdd,
 &sxap_solitaire_header,
 &sxap_solitaire_member,
 &sxap_rdc_block,
 &sxap_kgb2_header,
 &sxap_kgb2_member,
 &sxap_kgb2_encryption,
 &sxap_tar_nextstep_header,
 &sxap_bff_volume,
 &sxap_bff_legacy,
 &sxap_bff_member,
 &sxap_bff_compact,
 &sxap_bff_security_sizes,
 &sxap_bff_terminator,
 &sxap_archivepackages_dcl,
 &sxap_archivepackages_name,
 &sxap_vms_backup_block,
 &sxap_vms_backup_record,
 &sxap_vms_backup_file_version,
 &sxap_vms_backup_attribute,
 &sxap_vms_backup_fid,
 &sxap_vms_backup_characteristics,
 &sxap_vms_backup_date,
 &sxap_vms_backup_fat,
 &sxap_vmspcsi_header,
 &sxap_vmspcsi_table,
 &sxap_vmspcsi_context,
 &sxap_vmspcsi_bitmap,
 &sxap_vmspcsi_node,
 &sxap_vmspcsi_context_map,
 &sxap_vmspcsi_record,
 &sxap_vmsdb_prefix,
 &sxap_vmsdb_short,
 &sxap_vmsdb_indefinite,
 &sxap_vmsdb_long1,
 &sxap_vmsdb_long2,
 &sxap_vmsdb_attributes,
};
static bool sx_archivepackages_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60720000U||id>=0x60730000U)return true;
 if(r->type&&(!xx_rt_wcsncmp(r->type,L"ascii_decimal[",14)||!xx_rt_wcsncmp(r->type,L"ascii_octal_padded[",19))&&r->value.type!=XX_VAR_TYPE_UINT64&&r->value.type!=XX_VAR_TYPE_INT64)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60720001U:
 if(!xx_rt_wcscmp(r->name,L"method_flags"))text=L"1=LZMA; 0x40=x86 filter1; 0x80=x86 filter2, mutually exclusive";
 break;
 case 0x60720002U:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"x86 call-trick marker; parameters occupy the final five physical bytes";
 break;
 case 0x60720005U:
 if(!xx_rt_wcscmp(r->name,L"dos_datetime"))text=L"Packed DOS date/time";
 if(!xx_rt_wcscmp(r->name,L"fragment_method"))text=L"0=complete FINEAR, 6=first fragment, 2=continuation from previous volume";
 break;
 case 0x60720007U:
 if(!xx_rt_wcscmp(r->name,L"dos_datetime"))text=L"Packed DOS date/time";
 if(!xx_rt_wcscmp(r->name,L"fragment_method"))text=L"0=complete FINEAR, 6=first fragment, 2=continuation from previous volume";
 break;
 case 0x60720008U:
 if(!xx_rt_wcscmp(r->name,L"crc16_word"))text=L"CRC16/ARC stored in a 32-bit word";
 break;
 case 0x60720009U:
 if(!xx_rt_wcscmp(r->name,L"parameters"))text=L"Fixed native-supported stream parameters; individual meanings not established";
 break;
 case 0x6072000aU:
 if(!xx_rt_wcscmp(r->name,L"code_bits"))text=L"Canonical Huffman symbol code length in bits; 321 symbols including end marker256";
 break;
 case 0x6072000bU:
 if(!xx_rt_wcscmp(r->name,L"magic"))text=L"0x184C2102 legacy frame; 0x184D2A50..0x184D2A5F skippable frames";
 break;
 case 0x6072000eU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"3 or5 PICTools opcode stream; synthesized MZ prologue is not stored metadata";
 break;
 case 0x6072000fU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"High bit indicates RISC OS extension; masked0 ends archive";
 break;
 case 0x60720011U:
 if(!xx_rt_wcscmp(r->name,L"load_address"))text=L"Filetyped RISC OS words may encode type/date rather than address";
 if(!xx_rt_wcscmp(r->name,L"exec_address"))text=L"For filetyped load word, this contains timestamp low bits";
 break;
 case 0x60720012U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"Masked method0 terminates the containing member chain";
 break;
 case 0x60720014U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Includes mode byte and any control words";
 break;
 case 0x60720015U:
 if(!xx_rt_wcscmp(r->name,L"mode"))text=L"0x80 copied; 0x40 LZRW1/KH coded";
 break;
 case 0x60720016U:
 if(!xx_rt_wcscmp(r->name,L"control_bits"))text=L"Sixteen token flags, most significant bit first; subsequent codec tokens remain raw";
 break;
 case 0x60720019U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=file,1=install path";
 if(!xx_rt_wcscmp(r->name,L"sequence_number"))text=L"One-based sequence number";
 break;
 case 0x6072001aU:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=file,1=install path";
 if(!xx_rt_wcscmp(r->name,L"sequence_number"))text=L"One-based sequence number";
 break;
 case 0x6072001bU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored,6=DCL,8=Deflate with six-byte prefix";
 if(!xx_rt_wcscmp(r->name,L"stamp_low"))text=L"Unidentified low stamp word";
 if(!xx_rt_wcscmp(r->name,L"packed_crc32"))text=L"Reflected CRC32 seed0/no final complement; zero disables verification";
 break;
 case 0x6072001eU:
 if(!xx_rt_wcscmp(r->name,L"payload_type"))text=L"0x101=u32BE,0x102=u64BE,0x200=string,0x300=chunk,0x400=group,0x500=blob; zero tag/type=end group";
 break;
 case 0x60720024U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"2=zlib";
 break;
 case 0x60720025U:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"First setup tags124,125,126";
 break;
 case 0x60720026U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"3=stored file";
 break;
 case 0x60720028U:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"Native-supported version6";
 break;
 case 0x6072002aU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Native accepts0 or1";
 break;
 case 0x6072002dU:
 if(!xx_rt_wcscmp(r->name,L"value"))text=L"Native metadata word; category interpretation not established";
 break;
 case 0x6072002eU:
 if(!xx_rt_wcscmp(r->name,L"size_or_stored_length"))text=L"Negative=stored byte count after negation; positive=compressed byte count; zero=stream end";
 break;
 case 0x6072002fU:
 if(!xx_rt_wcscmp(r->name,L"algorithm"))text=L"0=stored;1..7=PAQ-family solid models";
 break;
 case 0x60720030U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Size of _wfinddata64_t record, excluding this word and final byte sum";
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"UTF16LE NUL-terminated; unused suffix may contain stale bytes";
 if(!xx_rt_wcscmp(r->name,L"byte_sum"))text=L"Sum of plaintext bytes";
 break;
 case 0x60720031U:
 if(!xx_rt_wcscmp(r->name,L"encrypted_check"))text=L"Encrypted payload prefix; no plaintext interpretation";
 break;
 case 0x60720032U:
 if(!xx_rt_wcscmp(r->name,L"typeflag"))text=L"0/ASCII0=regular,1/2=link no payload,5=directory";
 if(!xx_rt_wcscmp(r->name,L"unknown_tail"))text=L"Native reader does not define the remaining shifted TAR dialect fields";
 break;
 case 0x60720033U:
 if(!xx_rt_wcscmp(r->name,L"record_length_words"))text=L"Header length in eight-byte units";
 if(!xx_rt_wcscmp(r->name,L"volume_words"))text=L"Number of eight-byte words";
 break;
 case 0x60720034U:
 if(!xx_rt_wcscmp(r->name,L"record_length_words"))text=L"Name area length in eight-byte units";
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"9=legacy FS_NAME,11=FS_NAME_X,12=compact,7=end";
 break;
 case 0x60720035U:
 if(!xx_rt_wcscmp(r->name,L"record_length_words"))text=L"Name area length in eight-byte units";
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"9=legacy FS_NAME,11=FS_NAME_X,12=compact,7=end";
 break;
 case 0x60720036U:
 if(!xx_rt_wcscmp(r->name,L"record_length_words"))text=L"Name area length in eight-byte units";
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"9=legacy FS_NAME,11=FS_NAME_X,12=compact,7=end";
 break;
 case 0x60720037U:
 if(!xx_rt_wcscmp(r->name,L"acl_words"))text=L"ACL length in eight-byte words";
 if(!xx_rt_wcscmp(r->name,L"pcl_words"))text=L"PCL length in eight-byte words";
 break;
 case 0x60720039U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0=raw literals,1=coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"Dictionary selector4..6";
 break;
 case 0x6072003bU:
 if(!xx_rt_wcscmp(r->name,L"application"))text=L"1=BACKUP data,2=filler";
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Filler block zero inherits first block size";
 if(!xx_rt_wcscmp(r->name,L"bucket_size"))text=L"Bucket size in512-byte blocks";
 if(!xx_rt_wcscmp(r->name,L"file_size"))text=L"BBH file size word; native does not consume units";
 break;
 case 0x6072003cU:
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"0=null,1=summary,3=file,4=VBN data";
 if(!xx_rt_wcscmp(r->name,L"address"))text=L"Record logical address; not physical file offset";
 break;
 case 0x6072003eU:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0x2a=name,0x2c=FID,0x33=characteristics,0x34=FAT,0x36/37=dates";
 break;
 case 0x60720040U:
 if(!xx_rt_wcscmp(r->name,L"characteristics"))text=L"0x2000=directory; stored Files-11 characteristics";
 break;
 case 0x60720041U:
 if(!xx_rt_wcscmp(r->name,L"vms_time"))text=L"VMS100-nanosecond ticks since1858-11-17; not Unix seconds";
 break;
 case 0x60720042U:
 if(!xx_rt_wcscmp(r->name,L"high_block"))text=L"Allocated512-byte block count, PDP word order";
 if(!xx_rt_wcscmp(r->name,L"eof_block"))text=L"One-based EOF block; byte size=(eof_block-1)*512+first_free_byte";
 if(!xx_rt_wcscmp(r->name,L"first_free_byte"))text=L"Offset within the EOF block";
 if(!xx_rt_wcscmp(r->name,L"bucket_size"))text=L"In512-byte blocks";
 if(!xx_rt_wcscmp(r->name,L"default_extend"))text=L"Allocation extension in512-byte blocks";
 break;
 case 0x60720045U:
 if(!xx_rt_wcscmp(r->name,L"node_offset"))text=L"Relative to this context block";
 if(!xx_rt_wcscmp(r->name,L"map_offset"))text=L"Relative to this context block; zero means implicit context0";
 break;
 case 0x60720046U:
 if(!xx_rt_wcscmp(r->name,L"leaf_flags"))text=L"One bit per node; one=leaf symbol, zero=child index";
 break;
 case 0x60720047U:
 if(!xx_rt_wcscmp(r->name,L"symbol_or_child"))text=L"Leaf bitmap selects symbol vs child/2; child0 ends record";
 break;
 case 0x60720048U:
 if(!xx_rt_wcscmp(r->name,L"next_context"))text=L"Context index selected after decoding the corresponding symbol";
 break;
 case 0x60720049U:
 if(!xx_rt_wcscmp(r->name,L"unknown_record_word"))text=L"Physical two-byte prefix discarded by native codec; later record starts are codec-defined";
 break;
 case 0x6072004aU:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"0xffff introduces the BER-like PCSI database";
 break;
 case 0x6072004cU:
 if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"0x80: constructed value terminated by tag0";
 break;
 case 0x6072004dU:
 if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"0x81";
 break;
 case 0x6072004eU:
 if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"0x82";
 break;
 case 0x6072004fU:
 if(!xx_rt_wcscmp(r->name,L"allocated_blocks"))text=L"Signed512-byte block count; effective size=max(0,(blocks-1)*512+last_block_bytes)";
 if(!xx_rt_wcscmp(r->name,L"last_block_bytes"))text=L"Bytes used in last512-byte block";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAP_LIMIT 20000U
static bool sxap_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxap_read(sx_context*c,uint64_t p,void*b,size_t n){return sxap_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxap_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxap_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxap_read(c,p,b,n))return false;*v=sxap_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxap_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXAP_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxap_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxap_add(sx_context*c,const sx_layout*l,uint64_t p){return sxap_put(c,l,p,0,false);}
static bool sxap_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){return !n||n>4096?true:sxap_put(c,l,p,n,aliases);}
static bool sxap_zlen(sx_context*c,uint64_t p,uint64_t end,uint64_t*n){uint8_t b;*n=0;while(p<end&&*n<4096){if(!sxap_read(c,p++,&b,1))return false;(*n)++;if(!b)return true;}return false;}
static int sxap_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxap_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxap_order);return !c->failed;}
static bool sxap_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxap_add(c,l,p+i*width))return false;return true;}
static bool sxap_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t b[2];return n<2||!sxap_read(c,p,b,2)||b[0]>1||b[1]<4||b[1]>6?true:sxap_add(c,&sxap_archivepackages_dcl,p);}
static bool sxap_kpck(sx_context*c){uint64_t flags;if(!sxap_add(c,&sxap_kpck_header,0)||!sxap_word(c,8,4,false,&flags))return false;return !(flags&0xc0U)||c->size<17||sxap_add(c,&sxap_kpck_filter,(uint64_t)c->size-5);}
static bool sxap_lingvo(sx_context*c){uint8_t h[26];if(!sxap_read(c,0,h,18))return false;if(!xx_rt_memcmp(h,"LingvoArch",10))return sxap_add(c,&sxap_lingvo_stream_header,0)&&sxap_table(c,&sxap_lingvo_code_length,26,1,321);uint64_t count=sxap_uint(h+16,2,false),is2=h[9]=='2',width=is2?109:54,names=is2?101:46,desc=is2?71:23,p=18;if(!sxap_add(c,&sxap_lingvo_header,0)||!sxap_table(c,is2?&sxap_lingvo_index_v2:&sxap_lingvo_index_v1,p,width,count))return false;for(uint64_t i=0;i<count;i++){uint64_t q,z,method;if(!sxap_word(c,p+i*width+names,4,false,&q)||!sxap_add(c,is2?&sxap_lingvo_member_v2:&sxap_lingvo_member_v1,q)||!sxap_word(c,q+desc-10,4,false,&z)||!sxap_word(c,q+desc-2,2,false,&method))return false;q+=desc;if((method==0||method==6)&&z>=17&&sxap_span(c,q,z)&&sxap_read(c,q,h,9)&&!xx_rt_memcmp(h,"FINEAR\xdd\x88\xdd",9)&&!sxap_add(c,&sxap_finear_header,q))return false;}return true;}
static bool sxap_lz4(sx_context*c){uint64_t p=0;while(sxap_span(c,p,4)){uint64_t n;if(!sxap_word(c,p,4,false,&n))return false;if(n==0x184c2102U||(n&0xfffffff0U)==0x184d2a50U){if(!sxap_add(c,&sxap_legacy_lz4_magic,p))return false;p+=4;if(n==0x184c2102U)continue;if(!sxap_word(c,p,4,false,&n)||!sxap_add(c,&sxap_legacy_lz4_skip,p))return false;}else if(!sxap_add(c,&sxap_legacy_lz4_block,p))return false;p+=4;if(!sxap_span(c,p,n))return true;p+=n;}return true;}
static bool sxap_spark(sx_context*c,uint64_t p,uint64_t end,unsigned depth){if(depth>32||end>(uint64_t)c->size)return false;while(p<end){uint8_t h[41];if(end-p<2||!sxap_read(c,p,h,2)||h[0]!=0x1a)return false;unsigned method=h[1]&127;if(!method)return sxap_add(c,&sxap_spark_end,p);if(end-p<25||!sxap_read(c,p,h,25)||!sxap_add(c,&sxap_spark_prefix,p))return false;uint64_t packed=sxap_uint(h+15,4,false),q=p+25,load=0;{if(end-q<4||!sxap_add(c,&sxap_spark_original_size,q))return false;q+=4;}if(h[1]&128){if(end-q<12||!sxap_word(c,q,4,false,&load)||!sxap_add(c,&sxap_spark_riscos,q))return false;q+=12;}if(packed>end-q)return true;if(method==2&&(load&0xffffff00U)==0xfffddc00U&&!sxap_spark(c,q,q+packed,depth+1))return false;p=q+packed;}return true;}
static bool sxap_wrzl(sx_context*c){uint64_t p=8;if(!sxap_add(c,&sxap_wrzl_header,0))return false;while(sxap_span(c,p,3)){uint64_t n,mode;if(!sxap_word(c,p,2,false,&n)||!n||!sxap_word(c,p+2,1,false,&mode)||!sxap_add(c,&sxap_wrzl_block_size,p)||!sxap_add(c,&sxap_wrzl_mode,p+2))return false;p+=2;if(!sxap_span(c,p,n))return true;if(mode==0x40&&n>=3&&!sxap_add(c,&sxap_wrzl_control,p+1))return false;p+=n;}return true;}
static bool sxap_qip(sx_context*c){uint64_t n,ver;if(!sxap_word(c,2,2,false,&n)||!sxap_word(c,8,4,false,&ver)||!sxap_add(c,&sxap_qip_header,0)||!sxap_table(c,&sxap_qip_index,16,16,n))return false;uint64_t width=ver==1?32:36;for(uint64_t i=0;i<n;i++){uint64_t p,z;if(!sxap_word(c,16+i*16,4,false,&p)||!sxap_word(c,p+4,4,false,&z)||!sxap_add(c,ver==1?&sxap_qip_member_v1:&sxap_qip_member_v2,p)||!sxap_span(c,p+width,z)||!sxap_dcl(c,p+width,z))return false;}return true;}
static bool sxap_twrx(sx_context*c){uint64_t p=0;while(sxap_span(c,p,30)){uint64_t method,z,n;if(!sxap_word(c,p+8,2,false,&method)||!sxap_word(c,p+18,4,false,&z)||!sxap_word(c,p+26,4,false,&n)||!sxap_add(c,&sxap_twrx_header,p)||!sxap_span(c,p+30,n)||!sxap_text(c,&sxap_archivepackages_name,p+30,n,false))return false;p+=30+n;if(!sxap_span(c,p,z))return true;if(method==6&&!sxap_dcl(c,p,z))return false;if(method==8&&z>=6&&!sxap_add(c,&sxap_twrx_deflate,p))return false;p+=z;}return true;}
static bool sxap_beos_payload(sx_context*c,uint64_t p){uint8_t h[14];uint64_t z;if(!sxap_read(c,p,h,14)||xx_rt_memcmp(h,"FiDa",4)||xx_rt_memcmp(h+7,"FiMF",4)||sxap_uint(h+12,2,false)!=0x300||!sxap_word(c,p+14,8,true,&z)||!sxap_span(c,p+34,z))return false;return sxap_add(c,&sxap_beospkg_tag,p)&&sxap_add(c,&sxap_beospkg_tag,p+7)&&sxap_add(c,&sxap_beospkg_chunk,p+14);}
static bool sxap_beos_element(sx_context*c,uint64_t*p,unsigned depth,uint64_t*tree){uint8_t h[7];if(depth>64||!sxap_read(c,*p,h,7)||h[4]||!sxap_add(c,&sxap_beospkg_tag,*p))return false;*p+=7;unsigned type=(unsigned)sxap_uint(h+5,2,false);uint64_t n;if(!type&&!sxap_uint(h,4,false))return true;if(type==0x101){if(!sxap_add(c,&sxap_beospkg_value32,*p))return false;*p+=4;}else if(type==0x102){const sx_layout*l=(!xx_rt_memcmp(h,"COff",4)||!xx_rt_memcmp(h,"OffT",4))?&sxap_beospkg_offset64:!xx_rt_memcmp(h,"OrgS",4)?&sxap_beospkg_size64:&sxap_beospkg_value64;if(!sxap_word(c,*p,8,true,&n)||!sxap_add(c,l,*p))return false;if(tree&&!xx_rt_memcmp(h,"COff",4))*tree=n;if(!xx_rt_memcmp(h,"OffT",4)&&!sxap_beos_payload(c,n))return false;*p+=8;}else if(type==0x200||type==0x500){if(!sxap_word(c,*p,4,true,&n)||!sxap_add(c,&sxap_beospkg_length,*p)||!sxap_span(c,*p+4,n))return false;*p+=4;if(type==0x200&&!sxap_text(c,&sxap_archivepackages_name,*p,n,false))return false;*p+=n;}else if(type==0x300){if(!sxap_word(c,*p,8,true,&n)||!sxap_add(c,&sxap_beospkg_chunk,*p)||!sxap_span(c,*p+20,n))return false;*p+=20+n;}else if(type==0x400){for(size_t work=0;work<SXAP_LIMIT;work++){if(!sxap_read(c,*p,h,7))return false;bool end=!sxap_uint(h,4,false)&&!sxap_uint(h+5,2,false);if(!sxap_beos_element(c,p,depth+1,tree))return false;if(end||(tree&&*tree))break;}}else return false;return true;}
static bool sxap_beos(sx_context*c){uint64_t p=8,tree=0;if(!sxap_add(c,&sxap_beospkg_header,0)||!sxap_beos_element(c,&p,0,&tree)||!tree)return false;p=tree;return sxap_beos_element(c,&p,0,NULL);}
static bool sxap_cpoint(sx_context*c){uint64_t p=0;for(size_t work=0;work<SXAP_LIMIT&&sxap_span(c,p,13);work++){uint64_t kind,z,n;if(!sxap_word(c,p,1,false,&kind))return false;if(kind==3){if(!sxap_word(c,p+1,4,false,&z)||!sxap_word(c,p+5,4,false,&n)||!sxap_add(c,&sxap_cpoint_file,p)||!sxap_span(c,p+13,n)||!sxap_text(c,&sxap_archivepackages_name,p+13,n,false))return false;p+=13+n;if(!sxap_span(c,p,z+4)||!sxap_add(c,&sxap_cpoint_footer,p+z))return true;p+=z+4;}else{if(!sxap_word(c,p+5,4,false,&z)||!sxap_add(c,&sxap_cpoint_setup,p))return false;p+=13;if(!sxap_span(c,p,z))return true;p+=z;}}return true;}
static bool sxap_mlb(sx_context*c){uint64_t n;return sxap_word(c,0,2,false,&n)&&sxap_add(c,&sxap_mlbft_header,0)&&sxap_table(c,&sxap_mlbft_member,4,21,n);}
static bool sxap_oberon(sx_context*c){uint64_t p=0;while(sxap_span(c,p,136)){uint64_t n;if(!sxap_word(c,p+128,4,false,&n)||!sxap_add(c,&sxap_oberon_member,p))return false;p+=136;if(!sxap_span(c,p,n))return true;if(n>=14&&!sxap_add(c,&sxap_oberon_szdd,p))return false;p+=n;}return true;}
static bool sxap_solitaire(sx_context*c){uint64_t files,categories,p;if(!sxap_word(c,115,2,false,&categories)||!sxap_word(c,117,2,false,&files)||!sxap_add(c,&sxap_solitaire_header,0)||!sxap_table(c,&sxap_solitaire_member,119,25,files))return false;p=119+25*files+22*categories;for(uint64_t i=0;i<files;i++){uint64_t z;if(!sxap_word(c,119+25*i+17,4,false,&z))return false;if(!sxap_span(c,p,z))return true;if(!sxap_dcl(c,p,z))return false;p+=z;}return true;}
static bool sxap_rdc(sx_context*c){uint64_t p=0;while(sxap_span(c,p,2)){uint64_t word;if(!sxap_word(c,p,2,false,&word)||!sxap_add(c,&sxap_rdc_block,p))return false;p+=2;if(!word)break;uint64_t n=(word&0x8000)?0x10000-word:word;if(!sxap_span(c,p,n))return true;p+=n;}return true;}
static bool sxap_kgb(sx_context*c){uint64_t n,encrypted;if(!sxap_word(c,11,4,false,&n)||!sxap_word(c,8,1,false,&encrypted)||!sxap_add(c,&sxap_kgb2_header,0)||!sxap_table(c,&sxap_kgb2_member,15,572,n))return false;return !encrypted||sxap_add(c,&sxap_kgb2_encryption,15+572*n);}
static bool sxap_octal(const uint8_t*b,size_t n,uint64_t*v){*v=0;size_t i=0;while(i<n&&(b[i]==' '||!b[i]))i++;bool digit=false;for(;i<n;i++){if(b[i]==' '||!b[i]){for(;i<n;i++)if(b[i]!=' '&&b[i])return false;break;}if(b[i]<'0'||b[i]>'7'||*v>(UINT64_MAX-(b[i]-'0'))/8)return false;*v=*v*8+b[i]-'0';digit=true;}return digit;}
static bool sxap_tar(sx_context*c){uint64_t p=0;uint8_t h[512];while(sxap_read(c,p,h,512)){bool zero=true;for(unsigned i=0;i<512;i++)if(h[i])zero=false;if(zero)break;uint64_t stored,z,checksum=8*32;if(!sxap_octal(h+0x111,8,&stored))return true;for(unsigned i=0;i<512;i++)if(i<0x111||i>=0x119)checksum+=h[i];if(stored!=checksum||!sxap_add(c,&sxap_tar_nextstep_header,p)||!sxap_octal(h+0xf9,12,&z))return true;if(h[0x119]=='1'||h[0x119]=='2')z=0;if(z>UINT64_MAX-511)return false;z=(z+511)&~UINT64_C(511);p+=512;if(!sxap_span(c,p,z))return true;p+=z;}return true;}
static bool sxap_bff(sx_context*c){uint64_t p=72;if(!sxap_add(c,&sxap_bff_volume,0))return false;while(sxap_span(c,p,4)){uint8_t h[72];if(!sxap_read(c,p,h,4))return false;uint64_t words=h[0],type=h[1],fixed=type==9?48:type==12?72:64;if(type==7)return sxap_add(c,&sxap_bff_terminator,p);if((type!=9&&type!=11&&type!=12)||words*8<fixed||!sxap_read(c,p,h,(size_t)fixed)||!sxap_span(c,p,words*8))return false;uint64_t mode=sxap_uint(h+(type==9?8:12),type==9?2:4,false),name,z=sxap_uint(h+(type==9?40:type==11?56:48),4,false),plain=sxap_uint(h+(type==9?16:24),4,false),q=p+words*8;if(!sxap_add(c,type==9?&sxap_bff_legacy:type==11?&sxap_bff_member:&sxap_bff_compact,p)||!sxap_zlen(c,p+fixed,q,&name)||!sxap_text(c,&sxap_archivepackages_name,p+fixed,name,false))return false;if(type==11&&(mode&0xf000)!=0xa000){if(!sxap_span(c,q,40)||!sxap_add(c,&sxap_bff_security_sizes,q))return false;q+=40;}if((mode&0xf000)==0x4000)z=0;else if((mode&0xf000)==0xa000&&sxap_uint(h+2,2,false)==0xea6b)z=plain;if(!sxap_span(c,q,z))return true;p=(q+z+7)&~UINT64_C(7);}return true;}
static bool sxap_saveset(sx_context*c){uint64_t p=0,first=0;while(sxap_span(c,p,256)){uint64_t z,app;if(!sxap_word(c,p+40,4,false,&z)||!sxap_word(c,p+6,2,false,&app)||!sxap_add(c,&sxap_vms_backup_block,p))return false;if(!first)first=z;if(app==2&&!z)z=first;if(z<=256||z>INT32_MAX)return true;uint64_t end=p+z,q=p+256;if(!sxap_span(c,p,z))end=(uint64_t)c->size;if(app!=2)while(q<=end&&end-q>=16){uint64_t len,type;if(!sxap_word(c,q,2,false,&len)||!sxap_word(c,q+2,2,false,&type)||!sxap_add(c,&sxap_vms_backup_record,q))return false;q+=16;if(len>end-q)return true;if(type==3&&len>=2){if(!sxap_add(c,&sxap_vms_backup_file_version,q))return false;uint64_t a=q+2,stop=q+len;while(a<=stop&&stop-a>=4){uint64_t n,tag;if(!sxap_word(c,a,2,false,&n)||!sxap_word(c,a+2,2,false,&tag)||!sxap_add(c,&sxap_vms_backup_attribute,a))return false;a+=4;if(n>stop-a)return true;if(tag==0x2a){if(!sxap_text(c,&sxap_archivepackages_name,a,n,false))return false;}else if(tag==0x2c&&n==6){if(!sxap_add(c,&sxap_vms_backup_fid,a))return false;}else if(tag==0x33&&n==4){if(!sxap_add(c,&sxap_vms_backup_characteristics,a))return false;}else if(tag==0x34&&n==32){if(!sxap_add(c,&sxap_vms_backup_fat,a))return false;}else if((tag==0x36||tag==0x37)&&n==8){if(!sxap_add(c,&sxap_vms_backup_date,a))return false;}a+=n;}}q+=len;}p+=z;}return true;}
static bool sxap_pcsi(sx_context*c){uint64_t n,p=532;if(!sxap_add(c,&sxap_vmspcsi_header,0)||!sxap_add(c,&sxap_vmspcsi_table,512)||!sxap_word(c,528,2,false,&n))return false;for(uint64_t i=0;i<n;i++){uint8_t h[12];if(!sxap_read(c,p,h,12)||!sxap_add(c,&sxap_vmspcsi_context,p))return false;uint64_t z=sxap_uint(h,2,false),nodes=sxap_uint(h+8,2,false),map=sxap_uint(h+10,2,false),node_end=map?map:z;if(z<12||nodes<=12||node_end<nodes||node_end>z||!sxap_span(c,p,z))return true;if(!sxap_table(c,&sxap_vmspcsi_bitmap,p+12,1,nodes-12)||!sxap_table(c,&sxap_vmspcsi_node,p+nodes,1,node_end-nodes))return false;if(map&&(z-map)%2==0&&!sxap_table(c,&sxap_vmspcsi_context_map,p+map,2,(z-map)/2))return false;p+=z;}p=(p+511)&~UINT64_C(511);return !sxap_span(c,p,2)||sxap_add(c,&sxap_vmspcsi_record,p);}
static bool sxap_vms_element(sx_context*c,uint64_t*p,unsigned depth,unsigned parent,unsigned grand){uint8_t b[4];if(depth>64||!sxap_read(c,*p,b,2))return false;unsigned tag=b[0],form=b[1];uint64_t n=0;const sx_layout*l=&sxap_vmsdb_short;unsigned width=2;if(form==128)l=&sxap_vmsdb_indefinite;else if(form==129){width=3;l=&sxap_vmsdb_long1;if(!sxap_read(c,*p,b,3))return false;n=b[2];}else if(form==130){width=4;l=&sxap_vmsdb_long2;if(!sxap_read(c,*p,b,4))return false;n=sxap_uint(b+2,2,true);}else if(form<128)n=form;else return false;if(!sxap_add(c,l,*p))return false;*p+=width;if(form==128&&tag){for(size_t work=0;work<SXAP_LIMIT;work++){if(!sxap_read(c,*p,b,2))return false;bool end=!b[0];if(!sxap_vms_element(c,p,depth+1,tag,parent))return false;if(end)return true;}return false;}if(!sxap_span(c,*p,n))return true;if(tag==4&&n==171&&parent==0xa2&&grand==0x30){if(!sxap_add(c,&sxap_vmsdb_attributes,*p))return false;}else if(tag==0x81&&parent==0x30&&!sxap_text(c,&sxap_archivepackages_name,*p,n,false))return false;*p+=n;return true;}
static bool sx_archivepackages_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_KPCK:case XX_FILE_TYPE_LINGVOARC:case XX_FILE_TYPE_LZ4DEMO:case XX_FILE_TYPE_VMSSAVESET:case XX_FILE_TYPE_SSM:case XX_FILE_TYPE_SPK:case XX_FILE_TYPE_WRZL:case XX_FILE_TYPE_QIP2:case XX_FILE_TYPE_TWRX:case XX_FILE_TYPE_BEOSPKG:case XX_FILE_TYPE_VMSPCSI:case XX_FILE_TYPE_VMSDB:case XX_FILE_TYPE_MLB_FT:case XX_FILE_TYPE_OBERON:case XX_FILE_TYPE_SOLITAIRE_DELUXE:case XX_FILE_TYPE_CPOINT:case XX_FILE_TYPE_RDC:case XX_FILE_TYPE_KGB_ARCHIVER:case XX_FILE_TYPE_TAR_NEXTSTEP:case XX_FILE_TYPE_AIXBFF:return true;default:return false;}}
static bool sx_archivepackages_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_KPCK:ok=sxap_kpck(c);break;case XX_FILE_TYPE_LINGVOARC:ok=sxap_lingvo(c);break;case XX_FILE_TYPE_LZ4DEMO:ok=sxap_lz4(c);break;case XX_FILE_TYPE_VMSSAVESET:ok=sxap_saveset(c);break;case XX_FILE_TYPE_SSM:ok=sxap_add(c,&sxap_ssm_header,0);break;case XX_FILE_TYPE_SPK:ok=sxap_spark(c,0,(uint64_t)c->size,0);break;case XX_FILE_TYPE_WRZL:ok=sxap_wrzl(c);break;case XX_FILE_TYPE_QIP2:ok=sxap_qip(c);break;case XX_FILE_TYPE_TWRX:ok=sxap_twrx(c);break;case XX_FILE_TYPE_BEOSPKG:ok=sxap_beos(c);break;case XX_FILE_TYPE_VMSPCSI:ok=sxap_pcsi(c);break;case XX_FILE_TYPE_VMSDB:{uint64_t p=2;ok=sxap_add(c,&sxap_vmsdb_prefix,0)&&sxap_vms_element(c,&p,0,0,0);break;}case XX_FILE_TYPE_MLB_FT:ok=sxap_mlb(c);break;case XX_FILE_TYPE_OBERON:ok=sxap_oberon(c);break;case XX_FILE_TYPE_SOLITAIRE_DELUXE:ok=sxap_solitaire(c);break;case XX_FILE_TYPE_CPOINT:ok=sxap_cpoint(c);break;case XX_FILE_TYPE_RDC:ok=sxap_rdc(c);break;case XX_FILE_TYPE_KGB_ARCHIVER:ok=sxap_kgb(c);break;case XX_FILE_TYPE_TAR_NEXTSTEP:ok=sxap_tar(c);break;case XX_FILE_TYPE_AIXBFF:ok=sxap_bff(c);break;default:break;}(void)ok;return c->count&&sxap_finish(c);}
