/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivetails_scope.txt. */
static const xx_data_struct_field_desc sxat_zxzip_header_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("signature","char[3]",8,3,SX_SIGNATURE),
 SX_FIELD("chain_size","uint16",11,2,SX_SIZE),
 SX_FIELD("reserved","uint8",13,1,SX_NONE),
 SX_FIELD("size_high_guard","uint8",14,1,SX_NONE),
 SX_FIELD("header_checksum","uint16",15,2,SX_CHECKSUM),
};
static const sx_layout sxat_zxzip_header = {UINT32_C(0x60640001),"zxzip_header",sxat_zxzip_header_fields,SX_COUNT(sxat_zxzip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_zxzip_member_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("trdos_type","char[1]",8,1,SX_NONE),
 SX_FIELD("start_or_basic_size","uint16",9,2,SX_NONE),
 SX_FIELD("length","uint16",11,2,SX_SIZE),
 SX_FIELD("sector_count","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("compressed_size","uint16",14,2,SX_SIZE),
 SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("method","uint8",20,1,SX_NONE),
 SX_FIELD("submethod","uint8",21,1,SX_NONE),
};
static const sx_layout sxat_zxzip_member = {UINT32_C(0x60640002),"zxzip_member",sxat_zxzip_member_fields,SX_COUNT(sxat_zxzip_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_saf_banner29_fields[] = {
 SX_FIELD("banner","char[29]",0,29,SX_SIGNATURE),
};
static const sx_layout sxat_saf_banner29 = {UINT32_C(0x60640003),"saf_banner29",sxat_saf_banner29_fields,SX_COUNT(sxat_saf_banner29_fields),SX_LE};
static const xx_data_struct_field_desc sxat_saf_banner47_fields[] = {
 SX_FIELD("banner","char[47]",0,47,SX_SIGNATURE),
};
static const sx_layout sxat_saf_banner47 = {UINT32_C(0x60640004),"saf_banner47",sxat_saf_banner47_fields,SX_COUNT(sxat_saf_banner47_fields),SX_LE};
static const xx_data_struct_field_desc sxat_saf_member_fields[] = {
 SX_FIELD("name","char[14]",0,14,SX_NONE),
 SX_FIELD("uncompressed_size","int32",14,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",18,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",22,2,SX_NONE),
 SX_FIELD("dos_time","uint16",24,2,SX_NONE),
 SX_FIELD("unknown","uint8",26,1,SX_NONE),
 SX_FIELD("method","uint8",27,1,SX_NONE),
 SX_FIELD("opaque","uint8[7]",28,7,SX_NONE),
};
static const sx_layout sxat_saf_member = {UINT32_C(0x60640005),"saf_member",sxat_saf_member_fields,SX_COUNT(sxat_saf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_saf_chunk_fields[] = {
 SX_FIELD("compressed_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxat_saf_chunk = {UINT32_C(0x60640006),"saf_chunk",sxat_saf_chunk_fields,SX_COUNT(sxat_saf_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxat_sls_header_fields[] = {
 SX_FIELD("signature","uint8[9]",0,9,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","int32",9,4,SX_SIZE),
};
static const sx_layout sxat_sls_header = {UINT32_C(0x60640007),"sls_header",sxat_sls_header_fields,SX_COUNT(sxat_sls_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_nid_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_NONE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("member_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[112]",8,112,SX_NONE),
};
static const sx_layout sxat_nid_header = {UINT32_C(0x60640008),"nid_header",sxat_nid_header_fields,SX_COUNT(sxat_nid_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_nid_member_fields[] = {
 SX_FIELD("method","uint8",0,1,SX_NONE),
 SX_FIELD("payload_offset1","int32",1,4,SX_OFFSET),
 SX_FIELD("folder_key","uint32",5,4,SX_NONE),
 SX_FIELD("name","char[11]",9,11,SX_NONE),
 SX_FIELD("attributes","uint8",20,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("dos_date","uint16",23,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",25,4,SX_SIZE),
};
static const sx_layout sxat_nid_member = {UINT32_C(0x60640009),"nid_member",sxat_nid_member_fields,SX_COUNT(sxat_nid_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_nid_block_fields[] = {
 SX_FIELD("opaque","uint8",0,1,SX_NONE),
 SX_FIELD("flags","uint16",1,2,SX_FLAGS),
 SX_FIELD("compressed_size","uint16",3,2,SX_SIZE),
};
static const sx_layout sxat_nid_block = {UINT32_C(0x6064000a),"nid_block",sxat_nid_block_fields,SX_COUNT(sxat_nid_block_fields),SX_LE};
static const xx_data_struct_field_desc sxat_gamos_header_fields[] = {
 SX_FIELD("signature","uint8[18]",0,18,SX_SIGNATURE),
 SX_FIELD("zero","uint8",18,1,SX_NONE),
 SX_FIELD("marker1","uint8",19,1,SX_NONE),
 SX_FIELD("reserved","uint16",20,2,SX_NONE),
 SX_FIELD("marker2","uint8",22,1,SX_NONE),
 SX_FIELD("member_count","uint16",23,2,SX_COUNT_PROP),
 SX_FIELD("unused","uint8[8]",25,8,SX_NONE),
};
static const sx_layout sxat_gamos_header = {UINT32_C(0x6064000b),"gamos_header",sxat_gamos_header_fields,SX_COUNT(sxat_gamos_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_gamos_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("method","uint8",13,1,SX_NONE),
 SX_FIELD("payload_offset","int32",14,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint16",18,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",20,2,SX_SIZE),
};
static const sx_layout sxat_gamos_member = {UINT32_C(0x6064000c),"gamos_member",sxat_gamos_member_fields,SX_COUNT(sxat_gamos_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_fpak_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("set_compressed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("set_uncompressed_size","uint32",10,4,SX_SIZE),
 SX_FIELD("description_size","uint16",14,2,SX_SIZE),
};
static const sx_layout sxat_fpak_header = {UINT32_C(0x6064000d),"fpak_header",sxat_fpak_header_fields,SX_COUNT(sxat_fpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_fpac_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxat_fpac_header = {UINT32_C(0x6064000e),"fpac_header",sxat_fpac_header_fields,SX_COUNT(sxat_fpac_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_fpak_segment_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint16",4,2,SX_FLAGS),
 SX_FIELD("method","uint16",6,2,SX_NONE),
 SX_FIELD("dos_time","uint16",8,2,SX_NONE),
 SX_FIELD("dos_date","uint16",10,2,SX_NONE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("segment_size","uint32",24,4,SX_SIZE),
 SX_FIELD("name_size","uint16",28,2,SX_SIZE),
};
static const sx_layout sxat_fpak_segment = {UINT32_C(0x6064000f),"fpak_segment",sxat_fpak_segment_fields,SX_COUNT(sxat_fpak_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxat_finear_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("marker","uint8[3]",6,3,SX_NONE),
 SX_FIELD("crc16_word","uint32",9,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",13,4,SX_SIZE),
};
static const sx_layout sxat_finear_header = {UINT32_C(0x60640010),"finear_header",sxat_finear_header_fields,SX_COUNT(sxat_finear_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_gst_member_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("stamp","uint32",2,4,SX_NONE),
 SX_FIELD("flags","uint8",6,1,SX_FLAGS),
 SX_FIELD("method","uint8",7,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("name","char[12]",16,12,SX_NONE),
 SX_FIELD("crc32","uint32",28,4,SX_CHECKSUM),
};
static const sx_layout sxat_gst_member = {UINT32_C(0x60640011),"gst_member",sxat_gst_member_fields,SX_COUNT(sxat_gst_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_gpfpack_header_fields[] = {
 SX_FIELD("constant","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("signature","char[8]",4,8,SX_SIGNATURE),
 SX_FIELD("version","uint16",12,2,SX_NONE),
 SX_FIELD("name","char[14]",14,14,SX_NONE),
};
static const sx_layout sxat_gpfpack_header = {UINT32_C(0x60640012),"gpfpack_header",sxat_gpfpack_header_fields,SX_COUNT(sxat_gpfpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_gpfpack_block_fields[] = {
 SX_FIELD("bit_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxat_gpfpack_block = {UINT32_C(0x60640013),"gpfpack_block",sxat_gpfpack_block_fields,SX_COUNT(sxat_gpfpack_block_fields),SX_LE};
static const xx_data_struct_field_desc sxat_psdc_header_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("reserved","uint8[63]",13,63,SX_NONE),
 SX_FIELD("total_size","uint32",76,4,SX_SIZE),
};
static const sx_layout sxat_psdc_header = {UINT32_C(0x60640014),"psdc_header",sxat_psdc_header_fields,SX_COUNT(sxat_psdc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_edi_header_fields[] = {
 SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("version","char[1]",7,1,SX_NONE),
};
static const sx_layout sxat_edi_header = {UINT32_C(0x60640015),"edi_header",sxat_edi_header_fields,SX_COUNT(sxat_edi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_edi_name_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
};
static const sx_layout sxat_edi_name = {UINT32_C(0x60640016),"edi_name",sxat_edi_name_fields,SX_COUNT(sxat_edi_name_fields),SX_LE};
static const xx_data_struct_field_desc sxat_edi_size_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxat_edi_size = {UINT32_C(0x60640017),"edi_size",sxat_edi_size_fields,SX_COUNT(sxat_edi_size_fields),SX_LE};
static const xx_data_struct_field_desc sxat_archivetails_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxat_archivetails_dcl = {UINT32_C(0x60640018),"archivetails_dcl",sxat_archivetails_dcl_fields,SX_COUNT(sxat_archivetails_dcl_fields),SX_LE};
static const xx_data_struct_field_desc sxat_lzk_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("reserved","uint8[4]",5,4,SX_NONE),
};
static const sx_layout sxat_lzk_header = {UINT32_C(0x60640019),"lzk_header",sxat_lzk_header_fields,SX_COUNT(sxat_lzk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_lzk_literal_fields[] = {
 SX_FIELD("literal_code","uint8",0,1,SX_NONE),
};
static const sx_layout sxat_lzk_literal = {UINT32_C(0x6064001a),"lzk_literal",sxat_lzk_literal_fields,SX_COUNT(sxat_lzk_literal_fields),SX_LE};
static const xx_data_struct_field_desc sxat_lzk_match_fields[] = {
 SX_FIELD("match_code","uint16",0,2,SX_NONE),
};
static const sx_layout sxat_lzk_match = {UINT32_C(0x6064001b),"lzk_match",sxat_lzk_match_fields,SX_COUNT(sxat_lzk_match_fields),SX_LE};
static const xx_data_struct_field_desc sxat_compaqlzh_header_fields[] = {
 SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("name","char[13]",7,13,SX_NONE),
 SX_FIELD("attributes","uint8",20,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("dos_date","uint16",23,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",25,4,SX_SIZE),
};
static const sx_layout sxat_compaqlzh_header = {UINT32_C(0x6064001c),"compaqlzh_header",sxat_compaqlzh_header_fields,SX_COUNT(sxat_compaqlzh_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_lifkd_member_fields[] = {
 SX_FIELD("dos_datetime","ascii_hex[8]",0,8,SX_NONE),
 SX_FIELD("compressed_size","ascii_hex[8]",8,8,SX_SIZE),
 SX_FIELD("uncompressed_size","ascii_hex[8]",16,8,SX_SIZE),
 SX_FIELD("packed_crc16","ascii_hex[4]",24,4,SX_CHECKSUM),
 SX_FIELD("plain_crc16","ascii_hex[4]",28,4,SX_CHECKSUM),
 SX_FIELD("method","ascii_hex[2]",32,2,SX_NONE),
 SX_FIELD("name","char[20]",34,20,SX_NONE),
};
static const sx_layout sxat_lifkd_member = {UINT32_C(0x6064001d),"lifkd_member",sxat_lifkd_member_fields,SX_COUNT(sxat_lifkd_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_psn_header_fields[] = {
 SX_FIELD("banner","char[53]",0,53,SX_SIGNATURE),
 SX_FIELD("version","char[4]",53,4,SX_NONE),
 SX_FIELD("uncompressed_size","ascii_hex[8]",57,8,SX_SIZE),
};
static const sx_layout sxat_psn_header = {UINT32_C(0x6064001e),"psn_header",sxat_psn_header_fields,SX_COUNT(sxat_psn_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_mcc_member_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("method","uint8",3,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("xor_key","uint8",12,1,SX_NONE),
 SX_FIELD("attributes","uint8",13,1,SX_FLAGS),
 SX_FIELD("reserved","uint8",14,1,SX_NONE),
 SX_FIELD("dos_datetime","uint32",15,4,SX_NONE),
 SX_FIELD("crc16","uint16",19,2,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
 SX_FIELD("name","char[12]",22,12,SX_NONE),
};
static const sx_layout sxat_mcc_member = {UINT32_C(0x6064001f),"mcc_member",sxat_mcc_member_fields,SX_COUNT(sxat_mcc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_xlas_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxat_xlas_header = {UINT32_C(0x60640020),"xlas_header",sxat_xlas_header_fields,SX_COUNT(sxat_xlas_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_xlas_member_fields[] = {
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("payload_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("method","uint16",24,2,SX_NONE),
};
static const sx_layout sxat_xlas_member = {UINT32_C(0x60640021),"xlas_member",sxat_xlas_member_fields,SX_COUNT(sxat_xlas_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_mdcd_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("header_type","uint8",5,1,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unused","uint8[16]",8,16,SX_NONE),
 SX_FIELD("method","uint8",24,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",25,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",29,4,SX_SIZE),
 SX_FIELD("attributes","uint16",33,2,SX_FLAGS),
 SX_FIELD("dos_time","uint16",35,2,SX_NONE),
 SX_FIELD("dos_date","uint16",37,2,SX_NONE),
 SX_FIELD("crc16","uint16",39,2,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",41,1,SX_SIZE),
 SX_FIELD("name","char[12]",42,12,SX_NONE),
};
static const sx_layout sxat_mdcd_member = {UINT32_C(0x60640022),"mdcd_member",sxat_mdcd_member_fields,SX_COUNT(sxat_mdcd_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_mdcd_path_fields[] = {
 SX_FIELD("path_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxat_mdcd_path = {UINT32_C(0x60640023),"mdcd_path",sxat_mdcd_path_fields,SX_COUNT(sxat_mdcd_path_fields),SX_LE};
static const xx_data_struct_field_desc sxat_bvrp_header_fields[] = {
 SX_FIELD("banner","char[76]",0,76,SX_SIGNATURE),
 SX_FIELD("terminator","uint8[4]",76,4,SX_SIGNATURE),
 SX_FIELD("signature","uint16",80,2,SX_SIGNATURE),
 SX_FIELD("writer_version","uint16",82,2,SX_NONE),
 SX_FIELD("opaque","uint8[8]",84,8,SX_NONE),
 SX_FIELD("first_member_offset","uint32",92,4,SX_OFFSET),
 SX_FIELD("member_count","uint16",96,2,SX_COUNT_PROP),
};
static const sx_layout sxat_bvrp_header = {UINT32_C(0x60640024),"bvrp_header",sxat_bvrp_header_fields,SX_COUNT(sxat_bvrp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_bvrp_member_fields[] = {
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("attributes","uint16",12,2,SX_FLAGS),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
 SX_FIELD("dos_time","uint16",16,2,SX_NONE),
 SX_FIELD("method","uint8",18,1,SX_NONE),
 SX_FIELD("next_header_offset","uint32",19,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",23,4,SX_SIZE),
 SX_FIELD("crc16","uint16",27,2,SX_CHECKSUM),
 SX_FIELD("name_tail_size","uint16",29,2,SX_SIZE),
 SX_FIELD("padding","uint8",31,1,SX_NONE),
};
static const sx_layout sxat_bvrp_member = {UINT32_C(0x60640025),"bvrp_member",sxat_bvrp_member_fields,SX_COUNT(sxat_bvrp_member_fields),SX_LE};
static const sx_layout *const sx_archivetails_layouts[] = {
 &sxat_zxzip_header,
 &sxat_zxzip_member,
 &sxat_saf_banner29,
 &sxat_saf_banner47,
 &sxat_saf_member,
 &sxat_saf_chunk,
 &sxat_sls_header,
 &sxat_nid_header,
 &sxat_nid_member,
 &sxat_nid_block,
 &sxat_gamos_header,
 &sxat_gamos_member,
 &sxat_fpak_header,
 &sxat_fpac_header,
 &sxat_fpak_segment,
 &sxat_finear_header,
 &sxat_gst_member,
 &sxat_gpfpack_header,
 &sxat_gpfpack_block,
 &sxat_psdc_header,
 &sxat_edi_header,
 &sxat_edi_name,
 &sxat_edi_size,
 &sxat_archivetails_dcl,
 &sxat_lzk_header,
 &sxat_lzk_literal,
 &sxat_lzk_match,
 &sxat_compaqlzh_header,
 &sxat_lifkd_member,
 &sxat_psn_header,
 &sxat_mcc_member,
 &sxat_xlas_header,
 &sxat_xlas_member,
 &sxat_mdcd_member,
 &sxat_mdcd_path,
 &sxat_bvrp_header,
 &sxat_bvrp_member,
};
static bool sx_archivetails_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60640000U||id>=0x60650000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60640001U:
 if(!xx_rt_wcscmp(r->name,L"size_high_guard"))text=L"Upper bound for the high byte of chain_size";
 if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"Hobeta sum: sum(first15bytes)*0x101+0x69, low16 bits";
 break;
 case 0x60640002U:
 if(!xx_rt_wcscmp(r->name,L"start_or_basic_size"))text=L"B/b: BASIC program byte length; other types: stored TR-DOS start word";
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"256-byte output sectors";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Opaque decompressed checksum, not verified by the native reader";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 unsupported, 2 Shrink, 3 ZXZIP LZH";
 break;
 case 0x60640005U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"3 single bitstream, others use length-prefixed chunks";
 break;
 case 0x60640008U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Stored checksum, algorithm not verified";
 break;
 case 0x60640009U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 local member, 2 following-volume continuation";
 if(!xx_rt_wcscmp(r->name,L"payload_offset1"))text=L"One-based offset relative to the container: subtract1 for the physical byte position";
 if(!xx_rt_wcscmp(r->name,L"folder_key"))text=L"Opaque folder grouping key";
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"Space-padded FCB 8+3 name";
 break;
 case 0x6064000aU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"0x0800 compressed, 0x0100 last block";
 break;
 case 0x6064000cU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 Gamos LZSS, 2 stored";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Stored method2 uses compressed_size and ignores this zero field";
 break;
 case 0x6064000dU:
 if(!xx_rt_wcscmp(r->name,L"set_compressed_size"))text=L"Whole distribution set, not this volume";
 if(!xx_rt_wcscmp(r->name,L"set_uncompressed_size"))text=L"Whole distribution set";
 break;
 case 0x6064000fU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"PKZIP general-purpose flags";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 6 imploded";
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Whole member plaintext";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Whole member across segments";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Whole member across segments";
 if(!xx_rt_wcscmp(r->name,L"segment_size"))text=L"Physical payload bytes in this segment";
 break;
 case 0x60640010U:
 if(!xx_rt_wcscmp(r->name,L"crc16_word"))text=L"CRC16/ARC of plaintext, zero-extended to32 bits";
 break;
 case 0x60640011U:
 if(!xx_rt_wcscmp(r->name,L"signature"))text=L"0xC8E9 or alternate0xC9EA";
 if(!xx_rt_wcscmp(r->name,L"stamp"))text=L"Opaque stored stamp";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 PKWARE DCL";
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of plaintext";
 break;
 case 0x60640013U:
 if(!xx_rt_wcscmp(r->name,L"bit_count"))text=L"Stored compressed bit budget; physical byte length is ceil(bit_count/8)";
 break;
 case 0x60640014U:
 if(!xx_rt_wcscmp(r->name,L"total_size"))text=L"Includes this80-byte header";
 break;
 case 0x60640018U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 direct or1 Huffman-coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4=1KiB,5=2KiB,6=4KiB dictionary; encoded selector, not byte size";
 break;
 case 0x6064001aU:
 if(!xx_rt_wcscmp(r->name,L"literal_code"))text=L"Bit0 is0; bits1..7 store literal byte count";
 break;
 case 0x6064001bU:
 if(!xx_rt_wcscmp(r->name,L"match_code"))text=L"Bit0 is1; bits1..11 store backwards distance, bits12..15 store length minus3";
 break;
 case 0x6064001dU:
 if(!xx_rt_wcscmp(r->name,L"dos_datetime"))text=L"DOS date in high16 bits, time in low16";
 if(!xx_rt_wcscmp(r->name,L"packed_crc16"))text=L"CRC16/CCITT-FALSE of physical packed bytes";
 if(!xx_rt_wcscmp(r->name,L"plain_crc16"))text=L"CRC16/CCITT-FALSE of plaintext";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 stored,2 LZD";
 break;
 case 0x6064001eU:
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"FFFFFFFF means the uncompressed size was not recorded";
 break;
 case 0x6064001fU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,1 XOR-filtered LZW";
 if(!xx_rt_wcscmp(r->name,L"dos_datetime"))text=L"DOS date in high16 bits, time in low16";
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/BUYPASS of plaintext";
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"Space-padded";
 break;
 case 0x60640021U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,1 Okumura LZSS";
 break;
 case 0x60640022U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,1 LZD";
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/XMODEM of plaintext; zero tolerated for stored members";
 break;
 case 0x60640024U:
 if(!xx_rt_wcscmp(r->name,L"writer_version"))text=L"Major in high byte, minor in low byte";
 break;
 case 0x60640025U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,1 LZHUF";
 if(!xx_rt_wcscmp(r->name,L"next_header_offset"))text=L"Container-relative physical end of this member, or next header";
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/ARC of plaintext";
 if(!xx_rt_wcscmp(r->name,L"name_tail_size"))text=L"Optional repeated NUL-terminated name after compressed payload; zero may use native name matching";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAT_LIMIT 20000U
static bool sxat_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxat_read(sx_context*c,uint64_t p,void*b,size_t n){return sxat_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxat_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxat_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxat_read(c,p,b,n))return false;*v=sxat_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
static bool sxat_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXAT_LIMIT||!sxat_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxat_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t h[2];return n<2||!sxat_read(c,p,h,2)||h[0]>1||h[1]<4||h[1]>6?true:sxat_add(c,&sxat_archivetails_dcl,p);}
static int sxat_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxat_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxat_order);return !c->failed;}
static bool sxat_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxat_add(c,l,p+i*width))return false;return true;}
static bool sxat_zxzip(sx_context*c){uint64_t p=17,remain;if(!sxat_word(c,11,2,false,&remain)||!sxat_add(c,&sxat_zxzip_header,0))return false;while(remain>=22){uint64_t z;if(!sxat_word(c,p+14,2,false,&z)||!sxat_add(c,&sxat_zxzip_member,p))return false;p+=22;remain-=22;if(z>remain||!sxat_span(c,p,z))return true;p+=z;remain-=z;}return true;}
static bool sxat_saf(sx_context*c){uint8_t b[47];if(!sxat_read(c,0,b,47))return false;uint64_t p=b[27]==0x1a&&b[28]==0?29:47;if(!sxat_add(c,p==29?&sxat_saf_banner29:&sxat_saf_banner47,0))return false;while(sxat_span(c,p,35)){uint8_t h[35];if(!sxat_read(c,p,h,35))return false;uint64_t z=sxat_uint(h+18,4,false);if(z>INT32_MAX||!sxat_add(c,&sxat_saf_member,p))return false;p+=35;if(!sxat_span(c,p,z))return true;if(h[27]!=3){uint64_t q=p,end=p+z;while(q<end){uint64_t n;if(end-q<4||!sxat_word(c,q,4,false,&n)||n>INT32_MAX||!sxat_add(c,&sxat_saf_chunk,q))break;q+=4;if(n>end-q)break;q+=n;}}p+=z;}return true;}
static bool sxat_nid(sx_context*c){uint64_t n,work=0;if(!sxat_word(c,6,2,false,&n)||!sxat_add(c,&sxat_nid_header,0)||!sxat_table(c,&sxat_nid_member,120,29,n))return false;for(uint64_t i=0;i<n&&c->count<SXAT_LIMIT;i++){uint8_t h[29];if(!sxat_read(c,120+29*i,h,29))return false;if(h[0]!=1)continue;uint64_t p=sxat_uint(h+1,4,false);if(!p||p>INT32_MAX)continue;p--;while(sxat_span(c,p,5)){if(++work>100000)return true;uint8_t b[5];if(!sxat_read(c,p,b,5)||!sxat_add(c,&sxat_nid_block,p))break;uint64_t z=sxat_uint(b+3,2,false);p+=5;if(!sxat_span(c,p,z))break;p+=z;if(sxat_uint(b+1,2,false)&0x100)break;}}return true;}
static bool sxat_gamos(sx_context*c){uint64_t n;return sxat_word(c,23,2,false,&n)&&sxat_add(c,&sxat_gamos_header,0)&&sxat_table(c,&sxat_gamos_member,33,22,n);}
static bool sxat_fpak(sx_context*c){uint8_t magic[4];uint64_t p,n;if(!sxat_read(c,0,magic,4))return false;if(!xx_rt_memcmp(magic,"FPAK",4)){if(!sxat_word(c,14,2,false,&n)||!sxat_add(c,&sxat_fpak_header,0)||!sxat_span(c,16,n))return false;p=16+n;}else if(!xx_rt_memcmp(magic,"FPAC",4)){if(!sxat_add(c,&sxat_fpac_header,0))return false;p=4;}else return false;while(sxat_span(c,p,30)){uint8_t h[30];if(!sxat_read(c,p,h,30)||xx_rt_memcmp(h,"FPPF",4))return true;uint64_t z=sxat_uint(h+24,4,false),name=sxat_uint(h+28,2,false);if(!sxat_add(c,&sxat_fpak_segment,p)||!sxat_span(c,p+30,name))return false;p+=30+name;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
static bool sxat_gst(sx_context*c){uint64_t p=0;while(sxat_span(c,p,32)){uint8_t h[32];if(!sxat_read(c,p,h,32))return false;uint64_t z=sxat_uint(h+12,4,false);if(!sxat_add(c,&sxat_gst_member,p))return false;p+=32;if(!sxat_span(c,p,z))return true;if(h[7]==1&&!sxat_dcl(c,p,z))return false;p+=z;}return true;}
static bool sxat_gpf(sx_context*c){uint64_t p=28;if(!sxat_add(c,&sxat_gpfpack_header,0))return false;while(p<(uint64_t)c->size){uint64_t bits;if(!sxat_word(c,p,4,false,&bits)||!bits||bits>INT32_MAX||!sxat_add(c,&sxat_gpfpack_block,p))return false;p+=4;uint64_t z=(bits+7)/8;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
static bool sxat_edi(sx_context*c){uint8_t h[21];if(!sxat_add(c,&sxat_edi_header,0))return false;bool named=false;if(sxat_read(c,0,h,21)){for(unsigned i=8;i<21;i++){if(!h[i]){named=i!=8;break;}if(h[i]<32||h[i]>=127)break;}}if(named&&!sxat_add(c,&sxat_edi_name,8))return false;uint64_t version;if(!sxat_word(c,7,1,false,&version))return false;return version!='2'||(named&&sxat_add(c,&sxat_edi_size,21));}
static bool sxat_lzk(sx_context*c){uint64_t p=9;if(!sxat_add(c,&sxat_lzk_header,0))return false;while(p<(uint64_t)c->size){uint64_t b;if(!sxat_word(c,p,1,false,&b))return false;if(b&1){if(!sxat_add(c,&sxat_lzk_match,p))return false;p+=2;}else{uint64_t z=b>>1;if(!z||!sxat_add(c,&sxat_lzk_literal,p++))return false;if(!sxat_span(c,p,z))return true;p+=z;}}return true;}
static bool sxat_hex(sx_context*c,uint64_t p,unsigned n,uint64_t*v){uint8_t b[16];*v=0;if(!n||n>16||!sxat_read(c,p,b,n))return false;for(unsigned i=0;i<n;i++){unsigned d;if(b[i]>='0'&&b[i]<='9')d=b[i]-'0';else if(b[i]>='A'&&b[i]<='F')d=b[i]-'A'+10;else if(b[i]>='a'&&b[i]<='f')d=b[i]-'a'+10;else return false;*v=(*v<<4)|d;}return true;}
static bool sxat_lifkd(sx_context*c){uint64_t p=0;while(sxat_span(c,p,54)){uint64_t z,v;if(!sxat_hex(c,p,8,&v)||!sxat_hex(c,p+8,8,&z)||!sxat_hex(c,p+16,8,&v)||!sxat_hex(c,p+24,4,&v)||!sxat_hex(c,p+28,4,&v)||!sxat_hex(c,p+32,2,&v)||!sxat_add(c,&sxat_lifkd_member,p))return false;p+=54;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
static bool sxat_mcc(sx_context*c){uint64_t p=0;while(sxat_span(c,p,34)){uint8_t h[34];if(!sxat_read(c,p,h,34)||xx_rt_memcmp(h,"MCC",3))return true;uint64_t z=sxat_uint(h+8,4,false);if(!sxat_add(c,&sxat_mcc_member,p))return false;p+=34;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
static bool sxat_xlas(sx_context*c){uint64_t p,n;return sxat_word(c,4,4,false,&p)&&sxat_word(c,8,4,false,&n)&&sxat_add(c,&sxat_xlas_header,0)&&sxat_table(c,&sxat_xlas_member,p,26,n);}
static bool sxat_mdcd(sx_context*c){uint64_t p=0;while(sxat_span(c,p,54)){uint8_t h[54];if(!sxat_read(c,p,h,54)||xx_rt_memcmp(h,"MDmd",4))return true;uint64_t hs=sxat_uint(h+6,2,false),z=sxat_uint(h+29,4,false);if(hs<54||!sxat_span(c,p,hs)||!sxat_add(c,&sxat_mdcd_member,p))return false;if(hs>=55&&!sxat_add(c,&sxat_mdcd_path,p+54))return false;p+=hs;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
static bool sxat_bvrp(sx_context*c){uint64_t p,n;if(!sxat_word(c,92,4,false,&p)||!sxat_word(c,96,2,false,&n)||!sxat_add(c,&sxat_bvrp_header,0))return false;for(uint64_t i=0;i<n;i++){uint64_t next;if(!sxat_word(c,p+19,4,false,&next)||!sxat_span(c,p,32)||next<p+32||next>(uint64_t)c->size||!sxat_add(c,&sxat_bvrp_member,p))return false;p=next;}return true;}
static bool sx_archivetails_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_ZXZIP:case XX_FILE_TYPE_SAF:case XX_FILE_TYPE_SLS:case XX_FILE_TYPE_NID:case XX_FILE_TYPE_GAMOS:case XX_FILE_TYPE_FPAK:case XX_FILE_TYPE_FINEAR:case XX_FILE_TYPE_GST:case XX_FILE_TYPE_GPFPACK:case XX_FILE_TYPE_PSDC:case XX_FILE_TYPE_EDILZSS:case XX_FILE_TYPE_DCLFT:case XX_FILE_TYPE_LZK00:case XX_FILE_TYPE_COMPAQLZH:case XX_FILE_TYPE_LIFKD:case XX_FILE_TYPE_PSN:case XX_FILE_TYPE_MCC:case XX_FILE_TYPE_XLAS:case XX_FILE_TYPE_MDCD:case XX_FILE_TYPE_BVRP:return true;default:return false;}}
static bool sx_archivetails_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_ZXZIP:ok=sxat_zxzip(c);break;case XX_FILE_TYPE_SAF:ok=sxat_saf(c);break;case XX_FILE_TYPE_SLS:ok=sxat_add(c,&sxat_sls_header,0);break;case XX_FILE_TYPE_NID:ok=sxat_nid(c);break;case XX_FILE_TYPE_GAMOS:ok=sxat_gamos(c);break;case XX_FILE_TYPE_FPAK:ok=sxat_fpak(c);break;case XX_FILE_TYPE_FINEAR:ok=sxat_add(c,&sxat_finear_header,0);break;case XX_FILE_TYPE_GST:ok=sxat_gst(c);break;case XX_FILE_TYPE_GPFPACK:ok=sxat_gpf(c);break;case XX_FILE_TYPE_PSDC:ok=sxat_add(c,&sxat_psdc_header,0)&&sxat_dcl(c,80,c->size>=80?(uint64_t)c->size-80:0);break;case XX_FILE_TYPE_EDILZSS:ok=sxat_edi(c);break;case XX_FILE_TYPE_DCLFT:ok=sxat_dcl(c,0,(uint64_t)c->size);break;case XX_FILE_TYPE_LZK00:ok=sxat_lzk(c);break;case XX_FILE_TYPE_COMPAQLZH:ok=sxat_add(c,&sxat_compaqlzh_header,0);break;case XX_FILE_TYPE_LIFKD:ok=sxat_lifkd(c);break;case XX_FILE_TYPE_PSN:{uint64_t size;ok=sxat_hex(c,57,8,&size)&&sxat_add(c,&sxat_psn_header,0)&&sxat_dcl(c,65,c->size>=65?(uint64_t)c->size-65:0);break;}case XX_FILE_TYPE_MCC:ok=sxat_mcc(c);break;case XX_FILE_TYPE_XLAS:ok=sxat_xlas(c);break;case XX_FILE_TYPE_MDCD:ok=sxat_mdcd(c);break;case XX_FILE_TYPE_BVRP:ok=sxat_bvrp(c);break;default:break;}(void)ok;return c->count&&sxat_finish(c);}
