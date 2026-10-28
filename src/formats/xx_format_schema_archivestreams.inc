/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivestreams_scope.txt. */
static const xx_data_struct_field_desc sxas_sqze_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("compressed_crc32","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxas_sqze_header = {UINT32_C(0x60430001),"sqze_header",sxas_sqze_header_fields,SX_COUNT(sxas_sqze_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_csq_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("member_count","uint8",8,1,SX_COUNT_PROP),
};
static const sx_layout sxas_csq_header = {UINT32_C(0x60430002),"csq_header",sxas_csq_header_fields,SX_COUNT(sxas_csq_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_csq_entry_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("method","uint8",12,1,SX_NONE),
 SX_FIELD("name_size","uint8",13,1,SX_SIZE),
 SX_FIELD("name","char[12]",14,12,SX_NONE),
};
static const sx_layout sxas_csq_entry = {UINT32_C(0x60430003),"csq_entry",sxas_csq_entry_fields,SX_COUNT(sxas_csq_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxas_zoot1_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_NONE),
 SX_FIELD("directory_count","uint16",10,2,SX_COUNT_PROP),
};
static const sx_layout sxas_zoot1_header = {UINT32_C(0x60430004),"zoot1_header",sxas_zoot1_header_fields,SX_COUNT(sxas_zoot1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_zoot1_entry137_fields[] = {
 SX_FIELD("name","char[60]",0,60,SX_NONE),
 SX_FIELD("opaque0","uint8[33]",60,33,SX_NONE),
 SX_FIELD("payload_offset","uint32",93,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",97,4,SX_SIZE),
 SX_FIELD("opaque1","uint8[2]",101,2,SX_NONE),
 SX_FIELD("status","uint16",103,2,SX_NONE),
 SX_FIELD("class_word","uint16",105,2,SX_NONE),
 SX_FIELD("opaque_tail","uint8[30]",107,30,SX_NONE),
};
static const sx_layout sxas_zoot1_entry137 = {UINT32_C(0x60430005),"zoot1_entry137",sxas_zoot1_entry137_fields,SX_COUNT(sxas_zoot1_entry137_fields),SX_LE};
static const xx_data_struct_field_desc sxas_zoot1_entry235_fields[] = {
 SX_FIELD("name","char[60]",0,60,SX_NONE),
 SX_FIELD("opaque0","uint8[33]",60,33,SX_NONE),
 SX_FIELD("payload_offset","uint32",93,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",97,4,SX_SIZE),
 SX_FIELD("opaque1","uint8[2]",101,2,SX_NONE),
 SX_FIELD("status","uint16",103,2,SX_NONE),
 SX_FIELD("class_word","uint16",105,2,SX_NONE),
 SX_FIELD("opaque_tail","uint8[128]",107,128,SX_NONE),
};
static const sx_layout sxas_zoot1_entry235 = {UINT32_C(0x60430006),"zoot1_entry235",sxas_zoot1_entry235_fields,SX_COUNT(sxas_zoot1_entry235_fields),SX_LE};
static const xx_data_struct_field_desc sxas_rdfz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("method","char[4]",8,4,SX_NONE),
 SX_FIELD("packed_index_size","uint32",12,4,SX_SIZE),
 SX_FIELD("unpacked_index_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxas_rdfz_header = {UINT32_C(0x60430007),"rdfz_header",sxas_rdfz_header_fields,SX_COUNT(sxas_rdfz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_rdfz_count_fields[] = {
 SX_FIELD("member_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxas_rdfz_count = {UINT32_C(0x60430008),"rdfz_count",sxas_rdfz_count_fields,SX_COUNT(sxas_rdfz_count_fields),SX_LE};
static const xx_data_struct_field_desc sxas_rdfz_entry_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
 SX_FIELD("extension_index","uint32",8,4,SX_NONE),
 SX_FIELD("name_index","uint32",12,4,SX_NONE),
 SX_FIELD("method","uint32",16,4,SX_NONE),
};
static const sx_layout sxas_rdfz_entry = {UINT32_C(0x60430009),"rdfz_entry",sxas_rdfz_entry_fields,SX_COUNT(sxas_rdfz_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxas_rdfz_member_size_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxas_rdfz_member_size = {UINT32_C(0x6043000a),"rdfz_member_size",sxas_rdfz_member_size_fields,SX_COUNT(sxas_rdfz_member_size_fields),SX_LE};
static const xx_data_struct_field_desc sxas_asd_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxas_asd_header = {UINT32_C(0x6043000b),"asd_header",sxas_asd_header_fields,SX_COUNT(sxas_asd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_asd_name_length_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxas_asd_name_length = {UINT32_C(0x6043000c),"asd_name_length",sxas_asd_name_length_fields,SX_COUNT(sxas_asd_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxas_asd_entry_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("opaque_tail","uint8[6]",8,6,SX_NONE),
};
static const sx_layout sxas_asd_entry = {UINT32_C(0x6043000d),"asd_entry",sxas_asd_entry_fields,SX_COUNT(sxas_asd_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxas_fox_sqz_header_fields[] = {
 SX_FIELD("signature","char[24]",0,24,SX_SIGNATURE),
 SX_FIELD("base_key_size","uint8",24,1,SX_SIZE),
 SX_FIELD("encoded_key","uint8[4]",25,4,SX_NONE),
 SX_FIELD("opaque0","uint8[3]",29,3,SX_NONE),
 SX_FIELD("method","uint16",32,2,SX_NONE),
 SX_FIELD("opaque1","uint8[2]",34,2,SX_NONE),
 SX_FIELD("extra_key_size","uint16",36,2,SX_SIZE),
 SX_FIELD("opaque_tail","uint8[8]",38,8,SX_NONE),
};
static const sx_layout sxas_fox_sqz_header = {UINT32_C(0x6043000e),"fox_sqz_header",sxas_fox_sqz_header_fields,SX_COUNT(sxas_fox_sqz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_fox_sqz_member_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("opaque0","uint8",2,1,SX_NONE),
 SX_FIELD("compressed_size","uint32",3,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("checksum","uint16",11,2,SX_CHECKSUM),
 SX_FIELD("opaque1","uint8[8]",13,8,SX_NONE),
 SX_FIELD("name_size","uint16",21,2,SX_SIZE),
};
static const sx_layout sxas_fox_sqz_member = {UINT32_C(0x6043000f),"fox_sqz_member",sxas_fox_sqz_member_fields,SX_COUNT(sxas_fox_sqz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxas_fox_sqz_end_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxas_fox_sqz_end = {UINT32_C(0x60430010),"fox_sqz_end",sxas_fox_sqz_end_fields,SX_COUNT(sxas_fox_sqz_end_fields),SX_LE};
static const xx_data_struct_field_desc sxas_lds_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint64",6,8,SX_OFFSET),
};
static const sx_layout sxas_lds_header = {UINT32_C(0x60430011),"lds_header",sxas_lds_header_fields,SX_COUNT(sxas_lds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_lds_count_fields[] = {
 SX_FIELD("member_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxas_lds_count = {UINT32_C(0x60430012),"lds_count",sxas_lds_count_fields,SX_COUNT(sxas_lds_count_fields),SX_LE};
static const xx_data_struct_field_desc sxas_lds_entry_fields[] = {
 SX_FIELD("payload_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("payload_size","uint64",8,8,SX_SIZE),
 SX_FIELD("name_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxas_lds_entry = {UINT32_C(0x60430013),"lds_entry",sxas_lds_entry_fields,SX_COUNT(sxas_lds_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxas_webexe_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("version","char[1]",5,1,SX_NONE),
 SX_FIELD("format_marker","char[1]",6,1,SX_NONE),
 SX_FIELD("zip_end_offset","ascii_decimal[10]",7,10,SX_OFFSET),
 SX_FIELD("file_size","ascii_decimal[10]",17,10,SX_SIZE),
};
static const sx_layout sxas_webexe_header = {UINT32_C(0x60430014),"webexe_header",sxas_webexe_header_fields,SX_COUNT(sxas_webexe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_webexe_zip_local_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version_needed","uint16",4,2,SX_NONE),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("method","uint16",8,2,SX_NONE),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("name_size","uint16",26,2,SX_SIZE),
 SX_FIELD("extra_size","uint16",28,2,SX_SIZE),
};
static const sx_layout sxas_webexe_zip_local = {UINT32_C(0x60430015),"webexe_zip_local",sxas_webexe_zip_local_fields,SX_COUNT(sxas_webexe_zip_local_fields),SX_LE};
static const xx_data_struct_field_desc sxas_webexe_zip_central_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version_made","uint16",4,2,SX_NONE),
 SX_FIELD("version_needed","uint16",6,2,SX_NONE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
 SX_FIELD("method","uint16",10,2,SX_NONE),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
 SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("name_size","uint16",28,2,SX_SIZE),
 SX_FIELD("extra_size","uint16",30,2,SX_SIZE),
 SX_FIELD("comment_size","uint16",32,2,SX_SIZE),
 SX_FIELD("starting_disk","uint16",34,2,SX_NONE),
 SX_FIELD("internal_attributes","uint16",36,2,SX_FLAGS),
 SX_FIELD("external_attributes","uint32",38,4,SX_FLAGS),
 SX_FIELD("local_header_offset","uint32",42,4,SX_OFFSET),
};
static const sx_layout sxas_webexe_zip_central = {UINT32_C(0x60430016),"webexe_zip_central",sxas_webexe_zip_central_fields,SX_COUNT(sxas_webexe_zip_central_fields),SX_LE};
static const xx_data_struct_field_desc sxas_webexe_zip_end_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("disk_number","uint16",4,2,SX_NONE),
 SX_FIELD("directory_disk","uint16",6,2,SX_NONE),
 SX_FIELD("disk_entries","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("total_entries","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("directory_size","uint32",12,4,SX_SIZE),
 SX_FIELD("directory_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("comment_size","uint16",20,2,SX_SIZE),
};
static const sx_layout sxas_webexe_zip_end = {UINT32_C(0x60430017),"webexe_zip_end",sxas_webexe_zip_end_fields,SX_COUNT(sxas_webexe_zip_end_fields),SX_LE};
static const xx_data_struct_field_desc sxas_pma_header_fields[] = {
 SX_FIELD("header_payload_size","uint8",0,1,SX_SIZE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_NONE),
 SX_FIELD("compressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
 SX_FIELD("header_level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
static const sx_layout sxas_pma_header = {UINT32_C(0x60430018),"pma_header",sxas_pma_header_fields,SX_COUNT(sxas_pma_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_pma_crc16_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxas_pma_crc16 = {UINT32_C(0x60430019),"pma_crc16",sxas_pma_crc16_fields,SX_COUNT(sxas_pma_crc16_fields),SX_LE};
static const xx_data_struct_field_desc sxas_lhf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxas_lhf_header = {UINT32_C(0x6043001a),"lhf_header",sxas_lhf_header_fields,SX_COUNT(sxas_lhf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxas_lhf_entry_fields[] = {
 SX_FIELD("opaque_word","uint16",0,2,SX_NONE),
 SX_FIELD("name_size","uint16",2,2,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("opaque_tail","uint32",12,4,SX_NONE),
};
static const sx_layout sxas_lhf_entry = {UINT32_C(0x6043001b),"lhf_entry",sxas_lhf_entry_fields,SX_COUNT(sxas_lhf_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxas_ecmpacked_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("opaque_word0","uint32",6,4,SX_NONE),
 SX_FIELD("opaque_word1","uint16",10,2,SX_NONE),
 SX_FIELD("opaque_word2","uint32",12,4,SX_NONE),
 SX_FIELD("reserved","uint8[20]",16,20,SX_NONE),
 SX_FIELD("opaque_word3","uint16",36,2,SX_NONE),
};
static const sx_layout sxas_ecmpacked_header = {UINT32_C(0x6043001c),"ecmpacked_header",sxas_ecmpacked_header_fields,SX_COUNT(sxas_ecmpacked_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_chieflz_prefix_fields[] = {
 SX_FIELD("signature_size","uint8",0,1,SX_SIZE),
 SX_FIELD("signature","char[8]",1,8,SX_SIGNATURE),
 SX_FIELD("opaque0","uint8[2]",9,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",11,4,SX_SIZE),
 SX_FIELD("opaque1","uint8[4]",15,4,SX_NONE),
 SX_FIELD("dos_date","uint16",19,2,SX_NONE),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",23,4,SX_NONE),
 SX_FIELD("crc32","uint32",27,4,SX_CHECKSUM),
};
static const sx_layout sxas_chieflz_prefix = {UINT32_C(0x6043001d),"chieflz_prefix",sxas_chieflz_prefix_fields,SX_COUNT(sxas_chieflz_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxas_chieflz_name_size_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxas_chieflz_name_size = {UINT32_C(0x6043001e),"chieflz_name_size",sxas_chieflz_name_size_fields,SX_COUNT(sxas_chieflz_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxas_chieflz_method_fields[] = {
 SX_FIELD("method","uint8",0,1,SX_NONE),
};
static const sx_layout sxas_chieflz_method = {UINT32_C(0x6043001f),"chieflz_method",sxas_chieflz_method_fields,SX_COUNT(sxas_chieflz_method_fields),SX_LE};
static const xx_data_struct_field_desc sxas_ibmpack_prefix_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("dialect","uint16",2,2,SX_NONE),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("dos_time","uint16",6,2,SX_NONE),
 SX_FIELD("attributes","uint8",8,1,SX_FLAGS),
};
static const sx_layout sxas_ibmpack_prefix = {UINT32_C(0x60430020),"ibmpack_prefix",sxas_ibmpack_prefix_fields,SX_COUNT(sxas_ibmpack_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxas_ibmpack_chain_fields[] = {
 SX_FIELD("opaque_padding","uint8[3]",0,3,SX_NONE),
 SX_FIELD("extended_attributes_offset","uint32",3,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("next_header_offset","uint32",11,4,SX_OFFSET),
 SX_FIELD("name_field_size","uint16",15,2,SX_SIZE),
};
static const sx_layout sxas_ibmpack_chain = {UINT32_C(0x60430021),"ibmpack_chain",sxas_ibmpack_chain_fields,SX_COUNT(sxas_ibmpack_chain_fields),SX_LE};
static const xx_data_struct_field_desc sxas_cazip_header_fields[] = {
 SX_FIELD("lead_in","uint8[3]",0,3,SX_SIGNATURE),
 SX_FIELD("signature","char[5]",3,5,SX_SIGNATURE),
 SX_FIELD("version","char[2]",8,2,SX_NONE),
 SX_FIELD("fixed_word","uint16",10,2,SX_NONE),
 SX_FIELD("volume_flag","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("reserved","uint8[2]",18,2,SX_NONE),
};
static const sx_layout sxas_cazip_header = {UINT32_C(0x60430022),"cazip_header",sxas_cazip_header_fields,SX_COUNT(sxas_cazip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_cazip_dcl_prefix_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxas_cazip_dcl_prefix = {UINT32_C(0x60430023),"cazip_dcl_prefix",sxas_cazip_dcl_prefix_fields,SX_COUNT(sxas_cazip_dcl_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxas_tpwm_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxas_tpwm_header = {UINT32_C(0x60430024),"tpwm_header",sxas_tpwm_header_fields,SX_COUNT(sxas_tpwm_header_fields),SX_BE};
static const xx_data_struct_field_desc sxas_mrnz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("checkword","uint8[4]",4,4,SX_SIGNATURE),
 SX_FIELD("xor_prefix_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxas_mrnz_header = {UINT32_C(0x60430025),"mrnz_header",sxas_mrnz_header_fields,SX_COUNT(sxas_mrnz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_edc_header_fields[] = {
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("name","char[12]",12,12,SX_NONE),
 SX_FIELD("eof_marker","uint8",24,1,SX_SIGNATURE),
 SX_FIELD("version","uint8",25,1,SX_NONE),
 SX_FIELD("method","uint8",26,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",27,4,SX_SIZE),
 SX_FIELD("member_size","uint32",31,4,SX_SIZE),
 SX_FIELD("reserved","uint16",35,2,SX_NONE),
 SX_FIELD("dos_time","uint16",37,2,SX_NONE),
 SX_FIELD("dos_date","uint16",39,2,SX_NONE),
};
static const sx_layout sxas_edc_header = {UINT32_C(0x60430026),"edc_header",sxas_edc_header_fields,SX_COUNT(sxas_edc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_winlink_header_fields[] = {
 SX_FIELD("format_constant","uint16",0,2,SX_NONE),
 SX_FIELD("reserved","uint8",2,1,SX_NONE),
 SX_FIELD("dos_time","uint16",3,2,SX_NONE),
 SX_FIELD("dos_date","uint16",5,2,SX_NONE),
 SX_FIELD("name","char[13]",7,13,SX_NONE),
 SX_FIELD("sentinel","uint32",20,4,SX_SIGNATURE),
};
static const sx_layout sxas_winlink_header = {UINT32_C(0x60430027),"winlink_header",sxas_winlink_header_fields,SX_COUNT(sxas_winlink_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_ftcomp_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("dialect","uint16",2,2,SX_NONE),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("dos_time","uint16",6,2,SX_NONE),
 SX_FIELD("attributes","uint8",8,1,SX_FLAGS),
 SX_FIELD("opaque_padding","uint8[3]",9,3,SX_NONE),
 SX_FIELD("extended_attributes_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("next_header_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("signature2","char[7]",24,7,SX_SIGNATURE),
 SX_FIELD("opaque_word","uint16",31,2,SX_NONE),
 SX_FIELD("selector","uint16",33,2,SX_NONE),
 SX_FIELD("opaque_dword","uint32",35,4,SX_NONE),
 SX_FIELD("name_field_size","uint16",39,2,SX_SIZE),
};
static const sx_layout sxas_ftcomp_header = {UINT32_C(0x60430028),"ftcomp_header",sxas_ftcomp_header_fields,SX_COUNT(sxas_ftcomp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_crunch_magic_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxas_crunch_magic = {UINT32_C(0x60430029),"crunch_magic",sxas_crunch_magic_fields,SX_COUNT(sxas_crunch_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxas_crunch_parameters_fields[] = {
 SX_FIELD("encoder_version","uint8",0,1,SX_NONE),
 SX_FIELD("decoder_version","uint8",1,1,SX_NONE),
 SX_FIELD("checksum_flag","uint8",2,1,SX_NONE),
 SX_FIELD("reserved","uint8",3,1,SX_NONE),
};
static const sx_layout sxas_crunch_parameters = {UINT32_C(0x6043002a),"crunch_parameters",sxas_crunch_parameters_fields,SX_COUNT(sxas_crunch_parameters_fields),SX_LE};
static const xx_data_struct_field_desc sxas_ibmpack_fixed_name_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
};
static const sx_layout sxas_ibmpack_fixed_name = {UINT32_C(0x6043002b),"ibmpack_fixed_name",sxas_ibmpack_fixed_name_fields,SX_COUNT(sxas_ibmpack_fixed_name_fields),SX_LE};
static const sx_layout *const sx_archivestreams_layouts[] = {
 &sxas_sqze_header,
 &sxas_csq_header,
 &sxas_csq_entry,
 &sxas_zoot1_header,
 &sxas_zoot1_entry137,
 &sxas_zoot1_entry235,
 &sxas_rdfz_header,
 &sxas_rdfz_count,
 &sxas_rdfz_entry,
 &sxas_rdfz_member_size,
 &sxas_asd_header,
 &sxas_asd_name_length,
 &sxas_asd_entry,
 &sxas_fox_sqz_header,
 &sxas_fox_sqz_member,
 &sxas_fox_sqz_end,
 &sxas_lds_header,
 &sxas_lds_count,
 &sxas_lds_entry,
 &sxas_webexe_header,
 &sxas_webexe_zip_local,
 &sxas_webexe_zip_central,
 &sxas_webexe_zip_end,
 &sxas_pma_header,
 &sxas_pma_crc16,
 &sxas_lhf_header,
 &sxas_lhf_entry,
 &sxas_ecmpacked_header,
 &sxas_chieflz_prefix,
 &sxas_chieflz_name_size,
 &sxas_chieflz_method,
 &sxas_ibmpack_prefix,
 &sxas_ibmpack_chain,
 &sxas_cazip_header,
 &sxas_cazip_dcl_prefix,
 &sxas_tpwm_header,
 &sxas_mrnz_header,
 &sxas_edc_header,
 &sxas_winlink_header,
 &sxas_ftcomp_header,
 &sxas_crunch_magic,
 &sxas_crunch_parameters,
 &sxas_ibmpack_fixed_name,
};
static bool sx_archivestreams_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60430000U||id>=0x60440000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60430003U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 LZSS; both payload forms have a position-dependent byte XOR.";
 break;
 case 0x60430004U:
 if(!xx_rt_wcscmp(r->name,L"directory_size"))text=L"Complete directory bytes after 12-byte header.";
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"0x272e,0x2738 or0x2739.";
 break;
 case 0x60430005U:
 if(!xx_rt_wcscmp(r->name,L"payload_offset"))text=L"Physical file position is directory_size+this value+11.";
 if(!xx_rt_wcscmp(r->name,L"status"))text=L"0xfffe marks an unused entry.";
 if(!xx_rt_wcscmp(r->name,L"class_word"))text=L"Native skips values>=20 in versions 0x2738/0x2739.";
 break;
 case 0x60430006U:
 if(!xx_rt_wcscmp(r->name,L"payload_offset"))text=L"Physical file position is directory_size+this value+11.";
 if(!xx_rt_wcscmp(r->name,L"status"))text=L"0xfffe marks an unused entry.";
 if(!xx_rt_wcscmp(r->name,L"class_word"))text=L"Native skips values>=20 in versions 0x2738/0x2739.";
 break;
 case 0x60430007U:
 if(!xx_rt_wcscmp(r->name,L"packed_index_size"))text=L"Includes 4 bytes beyond the zlib stream occupied by the member count.";
 break;
 case 0x60430009U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored; 1 four-byte uncompressed size then zlib.";
 break;
 case 0x6043000eU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 LZSS or 4 DCL when payload is compressed.";
 break;
 case 0x6043000fU:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0x00eb file;0x00fe terminator.";
 break;
 case 0x60430010U:
 if(!xx_rt_wcscmp(r->name,L"tag"))text=L"0x00fe; remaining 21 bytes of end record have no established member semantics.";
 break;
 case 0x60430016U:
 if(!xx_rt_wcscmp(r->name,L"local_header_offset"))text=L"Stored ZIP-relative offset; not rewritten for the carrier.";
 break;
 case 0x60430017U:
 if(!xx_rt_wcscmp(r->name,L"directory_offset"))text=L"Stored ZIP-relative offset.";
 break;
 case 0x60430018U:
 if(!xx_rt_wcscmp(r->name,L"header_payload_size"))text=L"Complete header byte size minus 2.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"-pm0- stored,-pm1- and-pm2- compressed.";
 break;
 case 0x6043001bU:
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"0 means stored;0xffffffff directory-only sentinel.";
 break;
 case 0x6043001fU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"4 ChiefLZ adaptive Huffman/LZ.";
 break;
 case 0x60430020U:
 if(!xx_rt_wcscmp(r->name,L"dialect"))text=L"0x0a14/0x1400 PACK1;0xffff plain;0xfffe chained.";
 break;
 case 0x60430021U:
 if(!xx_rt_wcscmp(r->name,L"extended_attributes_offset"))text=L"File-relative only when it falls inside the member; small values can be unknown metadata.";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"0 or 1 means length not recorded.";
 if(!xx_rt_wcscmp(r->name,L"next_header_offset"))text=L"File-relative;0 means last member.";
 break;
 case 0x60430022U:
 if(!xx_rt_wcscmp(r->name,L"volume_flag"))text=L"1 complete stream;2 may require following volumes.";
 break;
 case 0x60430023U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 uncoded literals;1 coded literals.";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"Dictionary exponent 4, 5 or 6.";
 break;
 case 0x60430025U:
 if(!xx_rt_wcscmp(r->name,L"xor_prefix_size"))text=L"Only this many payload bytes are XORed with0xae; no compression by this layer.";
 break;
 case 0x60430026U:
 if(!xx_rt_wcscmp(r->name,L"member_size"))text=L"Includes 41-byte header.";
 break;
 case 0x6043002aU:
 if(!xx_rt_wcscmp(r->name,L"decoder_version"))text=L"High nibble 1 selects older coding, 2 newer.";
 if(!xx_rt_wcscmp(r->name,L"checksum_flag"))text=L"0 has additive 16-bit checksum; 1 omits it.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAS_LIMIT 20000U
static bool sxas_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxas_read(sx_context*c,uint64_t p,void*b,size_t n){return sxas_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxas_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxas_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxas_read(c,p,b,n))return false;*v=sxas_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
static bool sxas_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXAS_LIMIT||!sxas_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxas_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxas_read(c,(*p)++,&b,1))return false;if(!b)return true;}return false;}
static bool sxas_csq(sx_context*c){uint64_t n;if(!sxas_word(c,8,1,false,&n)||!sxas_add(c,&sxas_csq_header,0)||!sxas_span(c,9,n*26))return false;for(uint64_t i=0;i<n;i++)if(!sxas_add(c,&sxas_csq_entry,9+i*26))return false;return true;}
static bool sxas_zoot(sx_context*c){uint64_t size,version,dirs;if(!sxas_word(c,4,4,false,&size)||!sxas_word(c,8,2,false,&version)||!sxas_word(c,10,2,false,&dirs)||!sxas_span(c,12,size)||!sxas_add(c,&sxas_zoot1_header,0))return false;unsigned ds=version==0x272e?116:76,es=version==0x2739?235:137;if(version!=0x272e&&version!=0x2738&&version!=0x2739)return false;if(dirs>size/ds)return false;uint64_t p=12+dirs*ds,count=(size-dirs*ds)/es;for(uint64_t i=0;i<count;i++)if(!sxas_add(c,es==235?&sxas_zoot1_entry235:&sxas_zoot1_entry137,p+i*es))return false;return true;}
static bool sxas_rdfz(sx_context*c){uint64_t packed,n;if(!sxas_word(c,12,4,false,&packed)||packed<4||!sxas_span(c,20,packed)||!sxas_add(c,&sxas_rdfz_header,0)||!sxas_word(c,16+packed,4,false,&n)||!sxas_add(c,&sxas_rdfz_count,16+packed)||!sxas_span(c,20+packed,n*20))return false;uint64_t table=20+packed;for(uint64_t i=0;i<n;i++)if(!sxas_add(c,&sxas_rdfz_entry,table+20*i))return false;for(uint64_t i=0;i<n;i++){uint8_t b[20];if(!sxas_read(c,table+20*i,b,20))return false;uint64_t p=sxas_uint(b,4,false),z=sxas_uint(b+4,4,false);if(sxas_uint(b+16,4,false)==1&&z>=4&&p>=table+20*n&&sxas_span(c,p,z)&&!sxas_add(c,&sxas_rdfz_member_size,p))return false;}return true;}
static bool sxas_asd(sx_context*c){uint64_t n,p=8;if(!sxas_word(c,6,2,false,&n)||!sxas_add(c,&sxas_asd_header,0))return false;for(uint64_t i=0;i<n;i++){uint64_t z;if(!sxas_word(c,p,1,false,&z)||!sxas_span(c,p+1,z+14)||!sxas_add(c,&sxas_asd_name_length,p)||!sxas_add(c,&sxas_asd_entry,p+1+z))return false;p+=15+z;}return true;}
static bool sxas_fox(sx_context*c){uint8_t b[46];if(!sxas_read(c,0,b,46)||!sxas_add(c,&sxas_fox_sqz_header,0))return false;if(b[24])return true;uint64_t p=46;while(sxas_span(c,p,23)){if(!sxas_read(c,p,b,23))return false;uint64_t tag=sxas_uint(b,2,false);if(tag==0xfe)return sxas_add(c,&sxas_fox_sqz_end,p);if(tag!=0xeb)return false;uint64_t packed=sxas_uint(b+3,4,false),names=sxas_uint(b+21,2,false);if(!sxas_span(c,p+23,names)||!sxas_span(c,p+23+names,packed)||!sxas_add(c,&sxas_fox_sqz_member,p))return false;p+=23+names+packed;}return false;}
static bool sxas_lds(sx_context*c){uint64_t p,n;if(!sxas_word(c,6,8,false,&p)||p<14||!sxas_word(c,p,4,false,&n)||!sxas_add(c,&sxas_lds_header,0)||!sxas_add(c,&sxas_lds_count,p))return false;p+=4;for(uint64_t i=0;i<n;i++){uint64_t z;if(!sxas_word(c,p+16,4,false,&z)||!sxas_span(c,p+20,z)||!sxas_add(c,&sxas_lds_entry,p))return false;p+=20+z;}return true;}
static bool sxas_pma(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint8_t b[22];if(!sxas_read(c,p,b,1))return false;if(!b[0])return true;if(!sxas_read(c,p,b,22))return false;uint64_t hs=b[0]+2,n=b[21],packed=sxas_uint(b+7,4,false);if(hs<24+n||!sxas_span(c,p,hs)||!sxas_span(c,p+hs,packed)||!sxas_add(c,&sxas_pma_header,p)||!sxas_add(c,&sxas_pma_crc16,p+22+n))return false;p+=hs+packed;}return true;}
static bool sxas_lhf(sx_context*c){uint64_t p=8,end;if(!sxas_word(c,4,4,true,&end)||end<8||!sxas_span(c,0,end)||!sxas_add(c,&sxas_lhf_header,0))return false;while(p<end){uint8_t b[16];if(end-p<16||!sxas_read(c,p,b,16))return false;uint64_t name=sxas_uint(b+2,2,true),packed=sxas_uint(b+4,4,true),plain=sxas_uint(b+8,4,true);if(name>end-p-16||!sxas_add(c,&sxas_lhf_entry,p))return false;p+=16+name;if(plain!=UINT32_MAX){if(packed>end-p)return false;p+=packed;}}return true;}
static bool sxas_ibm(sx_context*c,bool ft){uint64_t p=0;for(unsigned i=0;i<SXAS_LIMIT;i++){uint64_t variant,next=0,n=0;if(!sxas_word(c,p+2,2,false,&variant))return false;if(ft){if(variant!=0xfffd||!sxas_word(c,p+20,4,false,&next)||!sxas_word(c,p+39,2,false,&n)||!sxas_span(c,p+41,n)||!sxas_add(c,&sxas_ftcomp_header,p))return false;}else{if(!sxas_add(c,&sxas_ibmpack_prefix,p))return false;if(variant==0xfffe){if(!sxas_word(c,p+20,4,false,&next)||!sxas_word(c,p+24,2,false,&n)||!sxas_span(c,p+26,n)||!sxas_add(c,&sxas_ibmpack_chain,p+9))return false;}else if(variant==0x0a14||variant==0x1400){if(!sxas_add(c,&sxas_ibmpack_fixed_name,p+10))return false;}else if(variant!=0xffff)return false;}if(!next)return true;if(next<=p||next>(uint64_t)c->size)return false;p=next;}return false;}
static bool sxas_edc(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint64_t n;if(!sxas_word(c,p+31,4,false,&n)||n<41||!sxas_span(c,p,n)||!sxas_add(c,&sxas_edc_header,p))return false;p+=n;}return true;}
static bool sxas_chief(sx_context*c){return sxas_span(c,0,257)&&sxas_add(c,&sxas_chieflz_prefix,0)&&sxas_add(c,&sxas_chieflz_name_size,40)&&sxas_add(c,&sxas_chieflz_method,173);}
static bool sxas_crunch(sx_context*c){uint64_t p=2;return sxas_add(c,&sxas_crunch_magic,0)&&sxas_zstr(c,&p,(uint64_t)c->size,96)&&sxas_add(c,&sxas_crunch_parameters,p);}
static int64_t sxas_webexe_overlay(sx_context *c)
{
    uint8_t h[64], p[24], section[40];
    uint32_t pe;
    unsigned count, opt, i;
    uint64_t end, n = (uint64_t)c->size;
    if (n < 2 || !sxas_read(c, 0, h, 2)) return -1;
    if (h[0] != 'M' || h[1] != 'Z') return 0;
    if (n < 64 || !sxas_read(c, 0, h, 64)) return -1;
    pe = sxas_uint(h+60,4,false);
    if (!sxas_span(c,pe,24) || !sxas_read(c, pe, p, 24) || xx_rt_memcmp(p, "PE\0\0", 4)) return -1;
    count = xx_data_get_u16(p + 6, 2, 0, false);
    opt = xx_data_get_u16(p + 20, 2, 0, false);
    if (!count || count > 96 || opt < 64 || opt > 4096 || !sxas_span(c,(uint64_t)pe+24,opt+(uint64_t)count*40) || !sxas_read(c, (int64_t)pe + 84, h, 4))
        return -1;
    end = sxas_uint(h,4,false);
    for (i = 0; i < count; ++i) {
        uint64_t finish;
        if (!sxas_read(c, (int64_t)pe + 24 + opt + (int64_t)i * 40, section, 40)) return -1;
        finish = (uint64_t)sxas_uint(section+16,4,false) + sxas_uint(section+20,4,false);
        if (finish > n) return -1;
        if (finish > end) end = finish;
    }
    /* Some signed launchers append their archive after WIN_CERTIFICATE. */
    if (!sxas_read(c, (int64_t)pe + 24, h, 2)) return -1;
    {
        unsigned dd = xx_data_get_u16(h, 2, 0, false) == 0x10b ? 128 : xx_data_get_u16(h, 2, 0, false) == 0x20b ? 144 : 0;
        if (dd && opt >= dd + 8 && sxas_read(c, (int64_t)pe + 24 + dd, h, 8)) {
            uint64_t cert = sxas_uint(h,4,false), bytes = sxas_uint(h+4,4,false);
            if (bytes >= 8 && sxas_span(c,cert,bytes) && (cert == end || (sxas_span(c,end,bytes) && cert + bytes == n))) {
                uint64_t at = cert;
                bool prefix = cert != end;
                if (prefix) {
                    uint8_t first[8], last[8];
                    if (!sxas_read(c, (int64_t)end, first, 8) || !sxas_read(c, (int64_t)cert, last, 8) || xx_rt_memcmp(first, last, 8)) return (int64_t)end;
                    /* A re-signed launcher retains its older certificate
                     * before the appended archive. Their signatures differ. */
                }
                while (at < cert + bytes) {
                    uint32_t size;
                    if (!sxas_read(c, (int64_t)at, h, 8)) return -1;
                    size = sxas_uint(h,4,false);
                    if (size < 8 || !(at<=cert+bytes && size<=cert+bytes-at) || xx_data_get_u16(h + 4, 2, 0, false) != 0x200 || xx_data_get_u16(h + 6, 2, 0, false) != 2)
                        return -1;
                    at = (at + size + 7) & ~UINT64_C(7);
                }
                if (at != cert + bytes) return -1;
                end = prefix ? end + bytes : at;
            }
        }
    }
    return end <= n ? (int64_t)end : -1;
}
static bool sxas_webexe(sx_context*c){int64_t at=sxas_webexe_overlay(c);uint8_t b[1024];uint64_t end=0,physical=0;if(at<0||!sxas_read(c,(uint64_t)at,b,27)||xx_rt_memcmp(b,"*M2E*",5)||b[5]<'1'||b[5]>'9'||b[6]!='A')return false;for(unsigned i=0;i<10;i++){if(b[7+i]<'0'||b[7+i]>'9'||b[17+i]<'0'||b[17+i]>'9')return false;end=end*10+b[7+i]-'0';physical=physical*10+b[17+i]-'0';}if(physical!=(uint64_t)c->size||end>(uint64_t)c->size||end<=(uint64_t)at+27||!sxas_add(c,&sxas_webexe_header,(uint64_t)at))return false;uint64_t p=(uint64_t)at+27,n=end-p;if(n>sizeof(b))n=sizeof(b);if(!sxas_read(c,p,b,(size_t)n))return false;bool found=false;for(uint64_t i=0;i+4<=n;i++)if(!xx_rt_memcmp(b+i,"PK\3\4",4)){p+=i;found=true;break;}if(!found)return false;while(p<end){if(end-p<4||!sxas_read(c,p,b,4))return false;uint64_t sig=sxas_uint(b,4,false),hs,names,packed=0;const sx_layout*l;if(sig==0x04034b50){hs=30;l=&sxas_webexe_zip_local;if(end-p<hs||!sxas_read(c,p,b,(size_t)hs))return false;packed=sxas_uint(b+18,4,false);names=sxas_uint(b+26,2,false)+sxas_uint(b+28,2,false);}else if(sig==0x02014b50){hs=46;l=&sxas_webexe_zip_central;if(end-p<hs||!sxas_read(c,p,b,(size_t)hs))return false;names=sxas_uint(b+28,2,false)+sxas_uint(b+30,2,false)+sxas_uint(b+32,2,false);}else if(sig==0x06054b50){hs=22;l=&sxas_webexe_zip_end;if(end-p<hs||!sxas_read(c,p,b,(size_t)hs))return false;names=sxas_uint(b+20,2,false);}else return false;if(names>end-p-hs||packed>end-p-hs-names||!sxas_add(c,l,p))return false;p+=hs+names+packed;}return true;}
static int sxas_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxas_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxas_order);return !c->failed;}
static bool sx_archivestreams_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_SQZE:case XX_FILE_TYPE_CSQ:case XX_FILE_TYPE_ZOOT1:case XX_FILE_TYPE_RDFZ:case XX_FILE_TYPE_ASD:case XX_FILE_TYPE_FOX_SQZ:case XX_FILE_TYPE_LDS:case XX_FILE_TYPE_WEBEXE:case XX_FILE_TYPE_PMA:case XX_FILE_TYPE_LHF:case XX_FILE_TYPE_ECMPACKED:case XX_FILE_TYPE_CHIEFLZ:case XX_FILE_TYPE_IBMPACK:case XX_FILE_TYPE_CAZIP:case XX_FILE_TYPE_TPWM:case XX_FILE_TYPE_MRNZ:case XX_FILE_TYPE_EDC:case XX_FILE_TYPE_WINLINK:case XX_FILE_TYPE_FTCOMP:case XX_FILE_TYPE_CPM_CRUNCH:return true;default:return false;}}
static bool sx_archivestreams_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_SQZE:ok=sxas_add(c,&sxas_sqze_header,0);break;case XX_FILE_TYPE_CSQ:ok=sxas_csq(c);break;case XX_FILE_TYPE_ZOOT1:ok=sxas_zoot(c);break;case XX_FILE_TYPE_RDFZ:ok=sxas_rdfz(c);break;case XX_FILE_TYPE_ASD:ok=sxas_asd(c);break;case XX_FILE_TYPE_FOX_SQZ:ok=sxas_fox(c);break;case XX_FILE_TYPE_LDS:ok=sxas_lds(c);break;case XX_FILE_TYPE_WEBEXE:ok=sxas_webexe(c);break;case XX_FILE_TYPE_PMA:ok=sxas_pma(c);break;case XX_FILE_TYPE_LHF:ok=sxas_lhf(c);break;case XX_FILE_TYPE_ECMPACKED:ok=sxas_add(c,&sxas_ecmpacked_header,0);break;case XX_FILE_TYPE_CHIEFLZ:ok=sxas_chief(c);break;case XX_FILE_TYPE_IBMPACK:ok=sxas_ibm(c,false);break;case XX_FILE_TYPE_CAZIP:{uint8_t b[8];if(sxas_read(c,0,b,8)&&!xx_rt_memcmp(b,"\r\n\032CAZIP",8))ok=sxas_add(c,&sxas_cazip_header,0)&&sxas_add(c,&sxas_cazip_dcl_prefix,20);break;}case XX_FILE_TYPE_TPWM:ok=sxas_add(c,&sxas_tpwm_header,0);break;case XX_FILE_TYPE_MRNZ:ok=sxas_add(c,&sxas_mrnz_header,0);break;case XX_FILE_TYPE_EDC:ok=sxas_edc(c);break;case XX_FILE_TYPE_WINLINK:ok=sxas_add(c,&sxas_winlink_header,0);break;case XX_FILE_TYPE_FTCOMP:ok=sxas_ibm(c,true);break;case XX_FILE_TYPE_CPM_CRUNCH:ok=sxas_crunch(c);break;default:break;}(void)ok;return c->count&&sxas_finish(c);}
