/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archiveframes_scope.txt. */
static const xx_data_struct_field_desc sxafr_lzhcxp_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
};
static const sx_layout sxafr_lzhcxp_header = {UINT32_C(0x60540001),"lzhcxp_header",sxafr_lzhcxp_header_fields,SX_COUNT(sxafr_lzhcxp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_lzhcxp_block_size_fields[] = {
 SX_FIELD("compressed_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxafr_lzhcxp_block_size = {UINT32_C(0x60540002),"lzhcxp_block_size",sxafr_lzhcxp_block_size_fields,SX_COUNT(sxafr_lzhcxp_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_lzwd_header_fields[] = {
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("signature","uint32",4,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",8,2,SX_NONE),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
};
static const sx_layout sxafr_lzwd_header = {UINT32_C(0x60540003),"lzwd_header",sxafr_lzwd_header_fields,SX_COUNT(sxafr_lzwd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_mi10_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxafr_mi10_member = {UINT32_C(0x60540004),"mi10_member",sxafr_mi10_member_fields,SX_COUNT(sxafr_mi10_member_fields),SX_BE};
static const xx_data_struct_field_desc sxafr_mi10_prefix_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("escape","uint8",1,1,SX_NONE),
};
static const sx_layout sxafr_mi10_prefix = {UINT32_C(0x60540005),"mi10_prefix",sxafr_mi10_prefix_fields,SX_COUNT(sxafr_mi10_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_pakleo_header_fields[] = {
 SX_FIELD("banner","char[37]",0,37,SX_SIGNATURE),
};
static const sx_layout sxafr_pakleo_header = {UINT32_C(0x60540006),"pakleo_header",sxafr_pakleo_header_fields,SX_COUNT(sxafr_pakleo_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_pakleo_member_fields[] = {
 SX_FIELD("unused1","uint8[2]",0,2,SX_NONE),
 SX_FIELD("method_tag","char[5]",2,5,SX_NONE),
 SX_FIELD("compressed_size","int32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",11,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",15,2,SX_NONE),
 SX_FIELD("dos_date","uint16",17,2,SX_NONE),
 SX_FIELD("unused2","uint8[2]",19,2,SX_NONE),
 SX_FIELD("crc32","uint32",21,4,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",25,1,SX_SIZE),
};
static const sx_layout sxafr_pakleo_member = {UINT32_C(0x60540007),"pakleo_member",sxafr_pakleo_member_fields,SX_COUNT(sxafr_pakleo_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_zcmp_header_fields[] = {
 SX_FIELD("reserved","uint32",0,4,SX_NONE),
 SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
 SX_FIELD("version1","uint64",8,8,SX_NONE),
 SX_FIELD("version2","uint64",16,8,SX_NONE),
 SX_FIELD("uncompressed_size","uint64",24,8,SX_SIZE),
 SX_FIELD("block_size","uint64",32,8,SX_SIZE),
};
static const sx_layout sxafr_zcmp_header = {UINT32_C(0x60540008),"zcmp_header",sxafr_zcmp_header_fields,SX_COUNT(sxafr_zcmp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxafr_zcmp_seek_word_fields[] = {
 SX_FIELD("seek_index_word","uint64",0,8,SX_NONE),
};
static const sx_layout sxafr_zcmp_seek_word = {UINT32_C(0x60540009),"zcmp_seek_word",sxafr_zcmp_seek_word_fields,SX_COUNT(sxafr_zcmp_seek_word_fields),SX_BE};
static const xx_data_struct_field_desc sxafr_ztc_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("opaque","uint8[4]",4,4,SX_NONE),
 SX_FIELD("volume_number","uint16",8,2,SX_NONE),
};
static const sx_layout sxafr_ztc_header = {UINT32_C(0x6054000a),"ztc_header",sxafr_ztc_header_fields,SX_COUNT(sxafr_ztc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_ztc_member_fields[] = {
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("stamp","int32",4,4,SX_NONE),
 SX_FIELD("total_size","int32",8,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("name_size","uint16",16,2,SX_SIZE),
};
static const sx_layout sxafr_ztc_member = {UINT32_C(0x6054000b),"ztc_member",sxafr_ztc_member_fields,SX_COUNT(sxafr_ztc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_ztc_check_fields[] = {
 SX_FIELD("header_check","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxafr_ztc_check = {UINT32_C(0x6054000c),"ztc_check",sxafr_ztc_check_fields,SX_COUNT(sxafr_ztc_check_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_ztc_page_sum_fields[] = {
 SX_FIELD("page_sum","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxafr_ztc_page_sum = {UINT32_C(0x6054000d),"ztc_page_sum",sxafr_ztc_page_sum_fields,SX_COUNT(sxafr_ztc_page_sum_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_header_fields[] = {
 SX_FIELD("file_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxafr_gtu_header = {UINT32_C(0x6054000e),"gtu_header",sxafr_gtu_header_fields,SX_COUNT(sxafr_gtu_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_record_fields[] = {
 SX_FIELD("block_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("tag","uint16",4,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",6,2,SX_NONE),
 SX_FIELD("reserved","uint16",8,2,SX_NONE),
 SX_FIELD("name_size","uint16",10,2,SX_SIZE),
};
static const sx_layout sxafr_gtu_record = {UINT32_C(0x6054000f),"gtu_record",sxafr_gtu_record_fields,SX_COUNT(sxafr_gtu_record_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_terminator_fields[] = {
 SX_FIELD("self_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unused","uint8[8]",4,8,SX_NONE),
};
static const sx_layout sxafr_gtu_terminator = {UINT32_C(0x60540010),"gtu_terminator",sxafr_gtu_terminator_fields,SX_COUNT(sxafr_gtu_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_info_fields[] = {
 SX_FIELD("dos_date","uint16",0,2,SX_NONE),
 SX_FIELD("dos_time","uint16",2,2,SX_NONE),
 SX_FIELD("opaque","uint8[8]",4,8,SX_NONE),
 SX_FIELD("uncompressed_size","int32",12,4,SX_SIZE),
 SX_FIELD("allocated_size","int32",16,4,SX_SIZE),
 SX_FIELD("attributes","uint32",20,4,SX_FLAGS),
 SX_FIELD("skip_size","int32",24,4,SX_SIZE),
};
static const sx_layout sxafr_gtu_info = {UINT32_C(0x60540011),"gtu_info",sxafr_gtu_info_fields,SX_COUNT(sxafr_gtu_info_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_frame_fields[] = {
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxafr_gtu_frame = {UINT32_C(0x60540012),"gtu_frame",sxafr_gtu_frame_fields,SX_COUNT(sxafr_gtu_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_jbf_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",17,4,SX_SIZE),
 SX_FIELD("payload_offset","int32",21,4,SX_OFFSET),
 SX_FIELD("checksum","uint16",25,2,SX_CHECKSUM),
 SX_FIELD("dos_time","uint16",27,2,SX_NONE),
 SX_FIELD("dos_date","uint16",29,2,SX_NONE),
};
static const sx_layout sxafr_jbf_member = {UINT32_C(0x60540013),"jbf_member",sxafr_jbf_member_fields,SX_COUNT(sxafr_jbf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_jbf_count_fields[] = {
 SX_FIELD("member_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxafr_jbf_count = {UINT32_C(0x60540014),"jbf_count",sxafr_jbf_count_fields,SX_COUNT(sxafr_jbf_count_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_imp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("opaque","uint8[26]",12,26,SX_NONE),
 SX_FIELD("flags","uint16",38,2,SX_FLAGS),
 SX_FIELD("header_crc16","uint16",40,2,SX_CHECKSUM),
};
static const sx_layout sxafr_imp_header = {UINT32_C(0x60540015),"imp_header",sxafr_imp_header_fields,SX_COUNT(sxafr_imp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_imp_directory_block_fields[] = {
 SX_FIELD("signature","uint8[6]",0,6,SX_SIGNATURE),
 SX_FIELD("method_and_lengths","uint48",6,6,SX_FLAGS),
};
static const sx_layout sxafr_imp_directory_block = {UINT32_C(0x60540016),"imp_directory_block",sxafr_imp_directory_block_fields,SX_COUNT(sxafr_imp_directory_block_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_irwinpac_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",8,2,SX_SIZE),
 SX_FIELD("opaque","uint8[10]",10,10,SX_NONE),
};
static const sx_layout sxafr_irwinpac_header = {UINT32_C(0x60540017),"irwinpac_header",sxafr_irwinpac_header_fields,SX_COUNT(sxafr_irwinpac_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_irwinpac_block_fields[] = {
 SX_FIELD("compressed","uint16",0,2,SX_NONE),
 SX_FIELD("total_size","uint16",2,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("uninitialized","uint8[4]",6,4,SX_NONE),
};
static const sx_layout sxafr_irwinpac_block = {UINT32_C(0x60540018),"irwinpac_block",sxafr_irwinpac_block_fields,SX_COUNT(sxafr_irwinpac_block_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_kpack_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint32",8,4,SX_FLAGS),
};
static const sx_layout sxafr_kpack_header = {UINT32_C(0x60540019),"kpack_header",sxafr_kpack_header_fields,SX_COUNT(sxafr_kpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_kpack_filter_fields[] = {
 SX_FIELD("conversion_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("marker","uint8",4,1,SX_NONE),
};
static const sx_layout sxafr_kpack_filter = {UINT32_C(0x6054001a),"kpack_filter",sxafr_kpack_filter_fields,SX_COUNT(sxafr_kpack_filter_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_lim_header_fields[] = {
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("reserved","uint8",4,1,SX_NONE),
 SX_FIELD("unused","uint8",5,1,SX_NONE),
 SX_FIELD("marker","uint16",6,2,SX_SIGNATURE),
};
static const sx_layout sxafr_lim_header = {UINT32_C(0x6054001b),"lim_header",sxafr_lim_header_fields,SX_COUNT(sxafr_lim_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_lim_chunk_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_NONE),
 SX_FIELD("chunk_size","int16",2,2,SX_SIZE),
};
static const sx_layout sxafr_lim_chunk = {UINT32_C(0x6054001c),"lim_chunk",sxafr_lim_chunk_fields,SX_COUNT(sxafr_lim_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_lim_member_fields[] = {
 SX_FIELD("unused1","uint8[2]",0,2,SX_NONE),
 SX_FIELD("dos_time","uint16",2,2,SX_NONE),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("attributes","uint8",6,1,SX_FLAGS),
 SX_FIELD("unused2","uint8",7,1,SX_NONE),
 SX_FIELD("method","uint8",8,1,SX_NONE),
 SX_FIELD("uncompressed_size","int32",9,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("crc32","uint32",17,4,SX_CHECKSUM),
};
static const sx_layout sxafr_lim_member = {UINT32_C(0x6054001d),"lim_member",sxafr_lim_member_fields,SX_COUNT(sxafr_lim_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_qda_header_fields[] = {
 SX_FIELD("packed","uint32",0,4,SX_NONE),
 SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint32",12,4,SX_NONE),
 SX_FIELD("unused","uint8[240]",16,240,SX_NONE),
};
static const sx_layout sxafr_qda_header = {UINT32_C(0x6054001e),"qda_header",sxafr_qda_header_fields,SX_COUNT(sxafr_qda_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_qda_member_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("name","char[256]",12,256,SX_NONE),
};
static const sx_layout sxafr_qda_member = {UINT32_C(0x6054001f),"qda_member",sxafr_qda_member_fields,SX_COUNT(sxafr_qda_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_rid_member_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_NONE),
 SX_FIELD("reserved","uint8[19]",2,19,SX_NONE),
 SX_FIELD("attributes","uint8",21,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",22,2,SX_NONE),
 SX_FIELD("dos_date","uint16",24,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",26,4,SX_SIZE),
 SX_FIELD("name","char[13]",30,13,SX_NONE),
};
static const sx_layout sxafr_rid_member = {UINT32_C(0x60540020),"rid_member",sxafr_rid_member_fields,SX_COUNT(sxafr_rid_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_rid_block_fields[] = {
 SX_FIELD("compressed_size","uint16",0,2,SX_SIZE),
 SX_FIELD("type","uint8",2,1,SX_NONE),
};
static const sx_layout sxafr_rid_block = {UINT32_C(0x60540021),"rid_block",sxafr_rid_block_fields,SX_COUNT(sxafr_rid_block_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_tivoli_header_fields[] = {
 SX_FIELD("header_line","char[79]",0,79,SX_NONE),
};
static const sx_layout sxafr_tivoli_header = {UINT32_C(0x60540022),"tivoli_header",sxafr_tivoli_header_fields,SX_COUNT(sxafr_tivoli_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_tivoli_block_fields[] = {
 SX_FIELD("flags_and_size","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxafr_tivoli_block = {UINT32_C(0x60540023),"tivoli_block",sxafr_tivoli_block_fields,SX_COUNT(sxafr_tivoli_block_fields),SX_BE};
static const xx_data_struct_field_desc sxafr_tivoli_digest_fields[] = {
 SX_FIELD("running_md5_prefix","uint8[8]",0,8,SX_CHECKSUM),
};
static const sx_layout sxafr_tivoli_digest = {UINT32_C(0x60540024),"tivoli_digest",sxafr_tivoli_digest_fields,SX_COUNT(sxafr_tivoli_digest_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_wintersoft_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("method_tag","char[4]",4,4,SX_NONE),
};
static const sx_layout sxafr_wintersoft_header = {UINT32_C(0x60540025),"wintersoft_header",sxafr_wintersoft_header_fields,SX_COUNT(sxafr_wintersoft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_wintersoft_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxafr_wintersoft_member = {UINT32_C(0x60540026),"wintersoft_member",sxafr_wintersoft_member_fields,SX_COUNT(sxafr_wintersoft_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_wpk_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("directory_size","uint16",6,2,SX_SIZE),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxafr_wpk_header = {UINT32_C(0x60540027),"wpk_header",sxafr_wpk_header_fields,SX_COUNT(sxafr_wpk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_wpk_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("payload_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("timestamp","uint32",8,4,SX_NONE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("method_and_name_size","uint8",16,1,SX_FLAGS),
};
static const sx_layout sxafr_wpk_member = {UINT32_C(0x60540028),"wpk_member",sxafr_wpk_member_fields,SX_COUNT(sxafr_wpk_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_xeditpack_header_fields[] = {
 SX_FIELD("signature","uint8[2]",0,2,SX_SIGNATURE),
 SX_FIELD("ebcdic_blank","uint8",2,1,SX_SIGNATURE),
 SX_FIELD("record_format","uint8",3,1,SX_NONE),
 SX_FIELD("opaque","uint8[4]",4,4,SX_NONE),
};
static const sx_layout sxafr_xeditpack_header = {UINT32_C(0x60540029),"xeditpack_header",sxafr_xeditpack_header_fields,SX_COUNT(sxafr_xeditpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_zie_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("obfuscated_key","uint8[16]",4,16,SX_NONE),
 SX_FIELD("name","char[13]",20,13,SX_NONE),
 SX_FIELD("unused","uint8[3]",33,3,SX_NONE),
 SX_FIELD("reserved","uint8[244]",36,244,SX_NONE),
};
static const sx_layout sxafr_zie_header = {UINT32_C(0x6054002a),"zie_header",sxafr_zie_header_fields,SX_COUNT(sxafr_zie_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_clay_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("dos_time","uint16",14,2,SX_NONE),
 SX_FIELD("name_size","uint16",16,2,SX_SIZE),
 SX_FIELD("unused","uint16",18,2,SX_NONE),
};
static const sx_layout sxafr_clay_member = {UINT32_C(0x6054002b),"clay_member",sxafr_clay_member_fields,SX_COUNT(sxafr_clay_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_archiveframes_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxafr_archiveframes_dcl = {UINT32_C(0x6054002c),"archiveframes_dcl",sxafr_archiveframes_dcl_fields,SX_COUNT(sxafr_archiveframes_dcl_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_clay_prefix_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("window_exponent","uint8",1,1,SX_NONE),
};
static const sx_layout sxafr_clay_prefix = {UINT32_C(0x6054002d),"clay_prefix",sxafr_clay_prefix_fields,SX_COUNT(sxafr_clay_prefix_fields),SX_LE};
static const sx_layout *const sx_archiveframes_layouts[] = {
 &sxafr_lzhcxp_header,
 &sxafr_lzhcxp_block_size,
 &sxafr_lzwd_header,
 &sxafr_mi10_member,
 &sxafr_mi10_prefix,
 &sxafr_pakleo_header,
 &sxafr_pakleo_member,
 &sxafr_zcmp_header,
 &sxafr_zcmp_seek_word,
 &sxafr_ztc_header,
 &sxafr_ztc_member,
 &sxafr_ztc_check,
 &sxafr_ztc_page_sum,
 &sxafr_gtu_header,
 &sxafr_gtu_record,
 &sxafr_gtu_terminator,
 &sxafr_gtu_info,
 &sxafr_gtu_frame,
 &sxafr_jbf_member,
 &sxafr_jbf_count,
 &sxafr_imp_header,
 &sxafr_imp_directory_block,
 &sxafr_irwinpac_header,
 &sxafr_irwinpac_block,
 &sxafr_kpack_header,
 &sxafr_kpack_filter,
 &sxafr_lim_header,
 &sxafr_lim_chunk,
 &sxafr_lim_member,
 &sxafr_qda_header,
 &sxafr_qda_member,
 &sxafr_rid_member,
 &sxafr_rid_block,
 &sxafr_tivoli_header,
 &sxafr_tivoli_block,
 &sxafr_tivoli_digest,
 &sxafr_wintersoft_header,
 &sxafr_wintersoft_member,
 &sxafr_wpk_header,
 &sxafr_wpk_member,
 &sxafr_xeditpack_header,
 &sxafr_zie_header,
 &sxafr_clay_member,
 &sxafr_archiveframes_dcl,
 &sxafr_clay_prefix,
};
static bool sx_archiveframes_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60540000U||id>=0x60550000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60540002U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Zero ends the length-prefixed LZW block chain";
 break;
 case 0x60540004U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of uncompressed bytes";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Excludes the following two-byte stream prefix";
 break;
 case 0x60540005U:
 if(!xx_rt_wcscmp(r->name,L"escape"))text=L"Escape value for the backwards token stream";
 break;
 case 0x60540007U:
 if(!xx_rt_wcscmp(r->name,L"method_tag"))text=L"-ll0- stored, -ll1- LEOLZW";
 break;
 case 0x60540008U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Maximum uncompressed bytes per block";
 break;
 case 0x60540009U:
 if(!xx_rt_wcscmp(r->name,L"seek_index_word"))text=L"Stored seek-index word; native validation derives block boundaries by inflation instead of trusting this index";
 break;
 case 0x6054000bU:
 if(!xx_rt_wcscmp(r->name,L"stamp"))text=L"First record has 0x3BC4";
 if(!xx_rt_wcscmp(r->name,L"total_size"))text=L"Includes record, name, check word and compressed payload";
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored time, epoch unspecified";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Includes a NUL inside the stored field";
 break;
 case 0x6054000cU:
 if(!xx_rt_wcscmp(r->name,L"header_check"))text=L"Low byte of uncompressed size plus low byte of timestamp plus every stored name byte";
 break;
 case 0x6054000dU:
 if(!xx_rt_wcscmp(r->name,L"page_sum"))text=L"Sum of the physical compressed bytes in the preceding page, at most 4096 bytes";
 break;
 case 0x60540010U:
 if(!xx_rt_wcscmp(r->name,L"self_offset"))text=L"Offset of this physical record";
 if(!xx_rt_wcscmp(r->name,L"unused"))text=L"Remaining terminator bytes are not interpreted by the native reader";
 break;
 case 0x60540011U:
 if(!xx_rt_wcscmp(r->name,L"skip_size"))text=L"Uncompressed bytes belonging to a previous volume";
 break;
 case 0x60540013U:
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Zero selects stored data";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Checksum algorithm unidentified";
 break;
 case 0x60540015U:
 if(!xx_rt_wcscmp(r->name,L"header_crc16"))text=L"Low 16 bits of CRC-32 with this word treated as zero";
 break;
 case 0x60540016U:
 if(!xx_rt_wcscmp(r->name,L"method_and_lengths"))text=L"LSB-first: bits0..4 method/flags, bits5..24 uncompressed length, bits25..44 stored chunk advance excluding six-byte signature; upper3 bits are padding";
 break;
 case 0x60540018U:
 if(!xx_rt_wcscmp(r->name,L"compressed"))text=L"0 stored, 1 compressed";
 if(!xx_rt_wcscmp(r->name,L"total_size"))text=L"Includes this ten-byte header";
 if(!xx_rt_wcscmp(r->name,L"uninitialized"))text=L"Uninitialized encoder scratch, not a checksum";
 break;
 case 0x60540019U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"0x01 LZMA, 0x40 call-trick1, 0x80 call-trick2; filters are mutually exclusive";
 break;
 case 0x6054001aU:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Call-trick filter marker byte";
 break;
 case 0x6054001cU:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0xD180 directory, 0xF123 file";
 if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Stored chunk field; cursor advancement follows the body grammar";
 break;
 case 0x6054001dU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 LIM";
 break;
 case 0x6054001eU:
 if(!xx_rt_wcscmp(r->name,L"packed"))text=L"0 stored, 1 byte-pair encoding";
 break;
 case 0x6054001fU:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Ignored when the archive packed flag is zero";
 break;
 case 0x60540021U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"0 stored, 1 DCL, 0xFF ends the member with zero length";
 break;
 case 0x60540022U:
 if(!xx_rt_wcscmp(r->name,L"header_line"))text=L"Physical 79-byte Filepack declaration, including LF; variable text is preserved";
 break;
 case 0x60540023U:
 if(!xx_rt_wcscmp(r->name,L"flags_and_size"))text=L"Zero terminates; bit15 selects stored, bits0..14 count physical block bytes including its eight-byte running-MD5 tail";
 break;
 case 0x60540024U:
 if(!xx_rt_wcscmp(r->name,L"running_md5_prefix"))text=L"First eight MD5 bytes of all uncompressed output emitted so far";
 break;
 case 0x60540025U:
 if(!xx_rt_wcscmp(r->name,L"method_tag"))text=L"LZW or HUFF applies to every member";
 break;
 case 0x60540028U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored timestamp, epoch unspecified";
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC-32 of consumed compressed prefix, not plaintext or the entire upper-bound run";
 if(!xx_rt_wcscmp(r->name,L"method_and_name_size"))text=L"Bit7 selects method B instead of A; low7 bits are physical name length";
 break;
 case 0x60540029U:
 if(!xx_rt_wcscmp(r->name,L"record_format"))text=L"0xC6 F fixed, 0xE5 V variable";
 break;
 case 0x6054002cU:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 binary or 1 coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4, 5 or 6; PKWARE DCL dictionary parameter";
 break;
 case 0x6054002dU:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 direct or 1 coded literals";
 if(!xx_rt_wcscmp(r->name,L"window_exponent"))text=L"4, 5 or 6; encoded history-window parameter";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAFR_LIMIT 20000U
static bool sxafr_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxafr_read(sx_context*c,uint64_t p,void*b,size_t n){return sxafr_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxafr_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxafr_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxafr_read(c,p,b,n))return false;*v=sxafr_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
static bool sxafr_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXAFR_LIMIT||!sxafr_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxafr_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxafr_read(c,(*p)++,&b,1))return false;if(!b)return true;}return false;}
static bool sxafr_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t h[2];return n<2||!sxafr_read(c,p,h,2)||h[0]>1||h[1]<4||h[1]>6?true:sxafr_add(c,&sxafr_archiveframes_dcl,p);}
static int sxafr_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxafr_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxafr_order);return !c->failed;}
static bool sxafr_lzhcxp(sx_context*c){uint64_t p=2,z;if(!sxafr_add(c,&sxafr_lzhcxp_header,0))return false;while(p<(uint64_t)c->size){if(!sxafr_word(c,p,1,false,&z)||!sxafr_add(c,&sxafr_lzhcxp_block_size,p++))return false;if(!z)return true;if(!sxafr_span(c,p,z))return false;p+=z;}return true;}
static bool sxafr_mi10(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint8_t h[16];if((p&1)||!sxafr_read(c,p,h,16)||xx_rt_memcmp(h,"MI10",4))return false;uint64_t z=sxafr_uint(h+12,4,true);if(!z||!sxafr_span(c,p+16,z+2)||!sxafr_add(c,&sxafr_mi10_member,p)||!sxafr_add(c,&sxafr_mi10_prefix,p+16))return false;p+=18+z;for(unsigned i=0;i<2&&p<(uint64_t)c->size;i++){uint8_t b;if(!sxafr_read(c,p,&b,1))return false;if(b!=0x6b)break;p++;}}return true;}
static bool sxafr_pakleo(sx_context*c){uint64_t p=37;if(!sxafr_add(c,&sxafr_pakleo_header,0))return false;while(p<(uint64_t)c->size){uint8_t h[26];if(!sxafr_read(c,p,h,26)||h[2]!='-'||h[3]!='l'||h[4]!='l'||h[5]<'0'||h[5]>'9'||h[6]!='-')return false;uint64_t z=sxafr_uint(h+7,4,false),n=h[25];if(z>INT32_MAX||!sxafr_span(c,p+26,n)||!sxafr_add(c,&sxafr_pakleo_member,p))return false;p+=26+n;if(!sxafr_span(c,p,z))return false;p+=z;}return true;}
static bool sxafr_zcmp(sx_context*c){uint64_t n,block;if(!sxafr_word(c,24,8,true,&n)||!sxafr_word(c,32,8,true,&block)||!block||!sxafr_add(c,&sxafr_zcmp_header,0))return false;uint64_t count=n/block+(n%block!=0);if(count==UINT64_MAX||count+1>((uint64_t)c->size-40)/8)return false;for(uint64_t i=0;i<=count;i++)if(!sxafr_add(c,&sxafr_zcmp_seek_word,40+i*8))return false;return true;}
static bool sxafr_ztc(sx_context*c){uint64_t p=10;if(!sxafr_add(c,&sxafr_ztc_header,0))return false;while(p<(uint64_t)c->size){if((uint64_t)c->size-p==2)return true;uint8_t h[18];if(!sxafr_read(c,p,h,18))return false;uint64_t total=sxafr_uint(h+8,4,false),names=sxafr_uint(h+16,2,false);if(total>INT32_MAX||!names||total<22+names||!sxafr_span(c,p+18,names+4)||!sxafr_add(c,&sxafr_ztc_member,p)||!sxafr_add(c,&sxafr_ztc_check,p+18+names))return false;uint64_t q=p+22+names,z=total-22-names;/* Declared geometry locates sums; a truncated page cannot move its checksum earlier. */while(z>=4){uint64_t page=z-4;if(page>4096)page=4096;if(!sxafr_span(c,q,page+4))return true;if(!sxafr_add(c,&sxafr_ztc_page_sum,q+page))return false;q+=page+4;z-=page+4;}if(total>(uint64_t)c->size-p)return true;p+=total;}return true;}
static bool sxafr_gtu(sx_context*c){uint64_t p=4;if(!sxafr_add(c,&sxafr_gtu_header,0))return false;for(unsigned i=0;i<SXAFR_LIMIT;i++){uint8_t h[12];if(!sxafr_read(c,p,h,12))return false;uint64_t off=sxafr_uint(h,4,false),names=sxafr_uint(h+10,2,false);if(off==p)return sxafr_add(c,&sxafr_gtu_terminator,p);if(!names||names>4096||!sxafr_span(c,p+12,names)||!sxafr_span(c,off,12+names+28)||!sxafr_add(c,&sxafr_gtu_record,p)||!sxafr_add(c,&sxafr_gtu_record,off))return false;uint64_t q=off+12+names;uint8_t info[28];if(!sxafr_read(c,q,info,28)||!sxafr_add(c,&sxafr_gtu_info,q))return false;q+=28;uint64_t totals[2]={sxafr_uint(info+24,4,false),sxafr_uint(info+12,4,false)};for(unsigned phase=0;phase<2;phase++){uint64_t remaining=totals[phase];if(remaining>INT32_MAX)return false;while(remaining){uint8_t frame[8];if(!sxafr_read(c,q,frame,8))return false;uint64_t raw=sxafr_uint(frame,4,false),z=sxafr_uint(frame+4,4,false);if(!raw||raw>65536||raw>remaining||z>INT32_MAX||!sxafr_span(c,q+8,z)||!sxafr_add(c,&sxafr_gtu_frame,q))return false;remaining-=raw;q+=8+z;}}p+=12+names;}return true;}
static bool sxafr_jbf(sx_context*c){uint64_t n;if(c->size<1||!sxafr_word(c,(uint64_t)c->size-1,1,false,&n)||!n||n>((uint64_t)c->size-1)/31)return false;uint64_t p=(uint64_t)c->size-1-n*31;for(uint64_t i=0;i<n;i++)if(!sxafr_add(c,&sxafr_jbf_member,p+i*31))return false;return sxafr_add(c,&sxafr_jbf_count,(uint64_t)c->size-1);}
static bool sxafr_imp(sx_context*c){uint64_t p,n;if(!sxafr_word(c,4,4,false,&p)||!sxafr_word(c,8,4,false,&n)||!sxafr_add(c,&sxafr_imp_header,0))return false;uint64_t decoded=0;for(unsigned i=0;n&&i<SXAFR_LIMIT;i++){uint8_t h[12];if(!sxafr_read(c,p,h,12)||xx_rt_memcmp(h,"IMPDE\0",6))return false;uint64_t bits=sxafr_uint(h+6,6,false),plain=(bits>>5)&0xfffff,z=(bits>>25)&0xfffff;if((bits&15)>1||plain>8192||!sxafr_add(c,&sxafr_imp_directory_block,p))return false;decoded+=plain;if(!z||decoded>=n*38)return true;if(z<6||!sxafr_span(c,p+6,z))return false;p+=6+z;}return true;}
static bool sxafr_irwin(sx_context*c){uint64_t p=20;if(!sxafr_add(c,&sxafr_irwinpac_header,0))return false;while(p<(uint64_t)c->size){uint64_t z;if(!sxafr_word(c,p+2,2,false,&z)||z<10||!sxafr_span(c,p,z)||!sxafr_add(c,&sxafr_irwinpac_block,p))return false;p+=z;}return true;}
static bool sxafr_kpack(sx_context*c){uint64_t flags;if(!sxafr_word(c,8,4,false,&flags)||!sxafr_add(c,&sxafr_kpack_header,0))return false;return !(flags&0xc0)||(c->size>=17&&sxafr_add(c,&sxafr_kpack_filter,(uint64_t)c->size-5));}
static bool sxafr_lim(sx_context*c){uint64_t p=8;if(!sxafr_add(c,&sxafr_lim_header,0))return false;while(p<(uint64_t)c->size){uint64_t tag,sz;if(!sxafr_word(c,p,2,false,&tag)||!sxafr_word(c,p+2,2,false,&sz)||sz<4||sz>INT16_MAX||(tag!=0xd180&&tag!=0xf123)||!sxafr_add(c,&sxafr_lim_chunk,p))return false;p+=4;uint64_t z=0;if(tag==0xf123){if(!sxafr_word(c,p+13,4,false,&z)||z>INT32_MAX||!sxafr_add(c,&sxafr_lim_member,p))return false;p+=21;}if(!sxafr_zstr(c,&p,(uint64_t)c->size,4096)||!sxafr_span(c,p,z))return false;p+=z;}return true;}
static bool sxafr_qda(sx_context*c){uint64_t n;if(!sxafr_word(c,8,4,false,&n)||!sxafr_add(c,&sxafr_qda_header,0)||n>((uint64_t)c->size-256)/268)return false;for(uint64_t i=0;i<n;i++)if(!sxafr_add(c,&sxafr_qda_member,256+i*268))return false;return true;}
static bool sxafr_rid(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){if(!sxafr_add(c,&sxafr_rid_member,p))return false;p+=43;for(;;){uint8_t h[3];if(!sxafr_read(c,p,h,3))return false;uint64_t z=sxafr_uint(h,2,false);if((h[2]!=0&&h[2]!=1&&h[2]!=255)||!sxafr_span(c,p+3,z)||!sxafr_add(c,&sxafr_rid_block,p))return false;p+=3;if(h[2]==255){if(z)return false;break;}if(h[2]==1&&!sxafr_dcl(c,p,z))return false;p+=z;}}return true;}
static bool sxafr_tivoli(sx_context*c){uint64_t p=79;if(!sxafr_add(c,&sxafr_tivoli_header,0))return false;while(p<(uint64_t)c->size){uint64_t h;if(!sxafr_word(c,p,2,true,&h)||!sxafr_add(c,&sxafr_tivoli_block,p))return false;p+=2;if(!h)return true;uint64_t z=h&0x7fff;if(z<8||!sxafr_span(c,p,z)||!sxafr_add(c,&sxafr_tivoli_digest,p+z-8))return false;p+=z;}return true;}
static bool sxafr_winter(sx_context*c){uint64_t p=8;if(!sxafr_add(c,&sxafr_wintersoft_header,0))return false;while(p<(uint64_t)c->size){uint64_t z;if(!sxafr_word(c,p+4,4,false,&z)||!sxafr_span(c,p+8,z)||!sxafr_add(c,&sxafr_wintersoft_member,p))return false;p+=8+z;}return true;}
static bool sxafr_wpk(sx_context*c){uint64_t p,n,z;if(!sxafr_word(c,4,2,false,&n)||!sxafr_word(c,6,2,false,&z)||!sxafr_word(c,8,4,false,&p)||!sxafr_span(c,p,z)||!sxafr_add(c,&sxafr_wpk_header,0))return false;uint64_t end=p+z;for(uint64_t i=0;i<n;i++){uint64_t flags;if(p>end||end-p<17||!sxafr_word(c,p+16,1,false,&flags)||((flags&127)>end-p-17)||!sxafr_add(c,&sxafr_wpk_member,p))return false;p+=17+(flags&127);}return true;}
static bool sxafr_clay(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint8_t h[20];if(!sxafr_read(c,p,h,20)||xx_rt_memcmp(h,"Clay",4))return false;uint64_t z=sxafr_uint(h+4,4,false),names=sxafr_uint(h+16,2,false);if(!names||names>4096||!sxafr_span(c,p+20,names)||!sxafr_add(c,&sxafr_clay_member,p))return false;p+=20+names;if(z>=2&&sxafr_span(c,p,2)&&!sxafr_add(c,&sxafr_clay_prefix,p))return false;if(!sxafr_span(c,p,z))return true;p+=z;}return true;}
static bool sx_archiveframes_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_LZHCXP:case XX_FILE_TYPE_LZWD:case XX_FILE_TYPE_MI10:case XX_FILE_TYPE_PAKLEO:case XX_FILE_TYPE_ZCMP:case XX_FILE_TYPE_ZTC:case XX_FILE_TYPE_GTU:case XX_FILE_TYPE_JBF:case XX_FILE_TYPE_IMP:case XX_FILE_TYPE_IRWINPAC:case XX_FILE_TYPE_KOLIBRIKPACK:case XX_FILE_TYPE_LIM:case XX_FILE_TYPE_QDA:case XX_FILE_TYPE_RID:case XX_FILE_TYPE_TIVOLI:case XX_FILE_TYPE_WINTERSOFT:case XX_FILE_TYPE_WPK:case XX_FILE_TYPE_XEDITPACK:case XX_FILE_TYPE_ZIE:case XX_FILE_TYPE_CLAYLZ:return true;default:return false;}}
static bool sx_archiveframes_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_LZHCXP:ok=sxafr_lzhcxp(c);break;case XX_FILE_TYPE_LZWD:ok=sxafr_add(c,&sxafr_lzwd_header,0);break;case XX_FILE_TYPE_MI10:ok=sxafr_mi10(c);break;case XX_FILE_TYPE_PAKLEO:ok=sxafr_pakleo(c);break;case XX_FILE_TYPE_ZCMP:ok=sxafr_zcmp(c);break;case XX_FILE_TYPE_ZTC:ok=sxafr_ztc(c);break;case XX_FILE_TYPE_GTU:ok=sxafr_gtu(c);break;case XX_FILE_TYPE_JBF:ok=sxafr_jbf(c);break;case XX_FILE_TYPE_IMP:ok=sxafr_imp(c);break;case XX_FILE_TYPE_IRWINPAC:ok=sxafr_irwin(c);break;case XX_FILE_TYPE_KOLIBRIKPACK:ok=sxafr_kpack(c);break;case XX_FILE_TYPE_LIM:ok=sxafr_lim(c);break;case XX_FILE_TYPE_QDA:ok=sxafr_qda(c);break;case XX_FILE_TYPE_RID:ok=sxafr_rid(c);break;case XX_FILE_TYPE_TIVOLI:ok=sxafr_tivoli(c);break;case XX_FILE_TYPE_WINTERSOFT:ok=sxafr_winter(c);break;case XX_FILE_TYPE_WPK:ok=sxafr_wpk(c);break;case XX_FILE_TYPE_XEDITPACK:ok=sxafr_add(c,&sxafr_xeditpack_header,0);break;case XX_FILE_TYPE_ZIE:ok=sxafr_add(c,&sxafr_zie_header,0);break;case XX_FILE_TYPE_CLAYLZ:ok=sxafr_clay(c);break;default:break;}(void)ok;return c->count&&sxafr_finish(c);}
