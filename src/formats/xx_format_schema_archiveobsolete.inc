/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archiveobsolete_scope.txt. */
static const xx_data_struct_field_desc sxao_sw_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("image_revision","ascii_decimal[3]",6,3,SX_NONE),
 SX_FIELD("product_marker","char[1]",9,1,SX_SIGNATURE),
 SX_FIELD("product_revision","ascii_decimal[2]",10,2,SX_NONE),
 SX_FIELD("terminator","uint8",12,1,SX_NONE),
};
static const sx_layout sxao_sw_header = {UINT32_C(0x60700001),"sw_header",sxao_sw_header_fields,SX_COUNT(sxao_sw_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_sw_path_length_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxao_sw_path_length = {UINT32_C(0x60700002),"sw_path_length",sxao_sw_path_length_fields,SX_COUNT(sxao_sw_path_length_fields),SX_BE};
static const xx_data_struct_field_desc sxao_archiveobsolete_name_fields[] = {
 SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxao_archiveobsolete_name = {UINT32_C(0x60700003),"archiveobsolete_name",sxao_archiveobsolete_name_fields,SX_COUNT(sxao_archiveobsolete_name_fields),SX_LE};
static const xx_data_struct_field_desc sxao_archiveobsolete_path_fields[] = {
 SX_FIELD("path","char",0,0,SX_NONE),
};
static const sx_layout sxao_archiveobsolete_path = {UINT32_C(0x60700004),"archiveobsolete_path",sxao_archiveobsolete_path_fields,SX_COUNT(sxao_archiveobsolete_path_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_header_fields[] = {
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("revision","uint16",16,2,SX_NONE),
 SX_FIELD("member_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("unused","uint32",20,4,SX_NONE),
 SX_FIELD("directory_end","int32",24,4,SX_OFFSET),
};
static const sx_layout sxao_dsl2_header = {UINT32_C(0x60700005),"dsl2_header",sxao_dsl2_header_fields,SX_COUNT(sxao_dsl2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_path_length_fields[] = {
 SX_FIELD("path_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxao_dsl2_path_length = {UINT32_C(0x60700006),"dsl2_path_length",sxao_dsl2_path_length_fields,SX_COUNT(sxao_dsl2_path_length_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_member_fields[] = {
 SX_FIELD("record_size","uint16_bias33_le",0,2,SX_SIZE),
 SX_FIELD("uncompressed_size","int32_bias33_le",2,4,SX_SIZE),
 SX_FIELD("compressed_size","int32_bias33_le",6,4,SX_SIZE),
 SX_FIELD("payload_offset","int32_bias33_le",10,4,SX_OFFSET),
 SX_FIELD("dos_time","uint16_bias33_le",14,2,SX_NONE),
 SX_FIELD("dos_date","uint16_bias33_le",16,2,SX_NONE),
 SX_FIELD("flags","uint16_bias33_le",18,2,SX_FLAGS),
};
static const sx_layout sxao_dsl2_member = {UINT32_C(0x60700007),"dsl2_member",sxao_dsl2_member_fields,SX_COUNT(sxao_dsl2_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_name_length_fields[] = {
 SX_FIELD("name_size","uint16_bias33_le",0,2,SX_SIZE),
};
static const sx_layout sxao_dsl2_name_length = {UINT32_C(0x60700008),"dsl2_name_length",sxao_dsl2_name_length_fields,SX_COUNT(sxao_dsl2_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_name_fields[] = {
 SX_FIELD("name","bias33_char",0,0,SX_NONE),
};
static const sx_layout sxao_dsl2_name = {UINT32_C(0x60700009),"dsl2_name",sxao_dsl2_name_fields,SX_COUNT(sxao_dsl2_name_fields),SX_LE};
static const xx_data_struct_field_desc sxao_topspeed_block_fields[] = {
 SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint16",2,2,SX_SIZE),
 SX_FIELD("compressed_size","uint16",4,2,SX_SIZE),
};
static const sx_layout sxao_topspeed_block = {UINT32_C(0x6070000a),"topspeed_block",sxao_topspeed_block_fields,SX_COUNT(sxao_topspeed_block_fields),SX_LE};
static const xx_data_struct_field_desc sxao_ulead_prefix_fields[] = {
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("reserved1","uint32",12,4,SX_NONE),
 SX_FIELD("constant1","uint16",16,2,SX_NONE),
 SX_FIELD("constant2","uint16",18,2,SX_NONE),
 SX_FIELD("reserved2","uint32",20,4,SX_NONE),
};
static const sx_layout sxao_ulead_prefix = {UINT32_C(0x6070000b),"ulead_prefix",sxao_ulead_prefix_fields,SX_COUNT(sxao_ulead_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxao_ulead_name_fields[] = {
 SX_FIELD("name","char[16]",0,16,SX_NONE),
};
static const sx_layout sxao_ulead_name = {UINT32_C(0x6070000c),"ulead_name",sxao_ulead_name_fields,SX_COUNT(sxao_ulead_name_fields),SX_LE};
static const xx_data_struct_field_desc sxao_ulead_block_counts_fields[] = {
 SX_FIELD("block_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("last_block_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxao_ulead_block_counts = {UINT32_C(0x6070000d),"ulead_block_counts",sxao_ulead_block_counts_fields,SX_COUNT(sxao_ulead_block_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxao_ulead_block_size_fields[] = {
 SX_FIELD("compressed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxao_ulead_block_size = {UINT32_C(0x6070000e),"ulead_block_size",sxao_ulead_block_size_fields,SX_COUNT(sxao_ulead_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxao_quantum_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("zero","uint8",2,1,SX_NONE),
 SX_FIELD("version","uint8",3,1,SX_NONE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("window_bits","uint8",6,1,SX_NONE),
 SX_FIELD("level","uint8",7,1,SX_NONE),
};
static const sx_layout sxao_quantum_header = {UINT32_C(0x6070000f),"quantum_header",sxao_quantum_header_fields,SX_COUNT(sxao_quantum_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_quantum_length1_fields[] = {
 SX_FIELD("string_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxao_quantum_length1 = {UINT32_C(0x60700010),"quantum_length1",sxao_quantum_length1_fields,SX_COUNT(sxao_quantum_length1_fields),SX_LE};
static const xx_data_struct_field_desc sxao_quantum_length2_fields[] = {
 SX_FIELD("length_high","uint8",0,1,SX_NONE),
 SX_FIELD("length_low","uint8",1,1,SX_NONE),
};
static const sx_layout sxao_quantum_length2 = {UINT32_C(0x60700011),"quantum_length2",sxao_quantum_length2_fields,SX_COUNT(sxao_quantum_length2_fields),SX_BE};
static const xx_data_struct_field_desc sxao_quantum_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",4,2,SX_NONE),
 SX_FIELD("dos_date","uint16",6,2,SX_NONE),
};
static const sx_layout sxao_quantum_member = {UINT32_C(0x60700012),"quantum_member",sxao_quantum_member_fields,SX_COUNT(sxao_quantum_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_quantum_crc16_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxao_quantum_crc16 = {UINT32_C(0x60700013),"quantum_crc16",sxao_quantum_crc16_fields,SX_COUNT(sxao_quantum_crc16_fields),SX_LE};
static const xx_data_struct_field_desc sxao_wraptor_signature_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxao_wraptor_signature = {UINT32_C(0x60700014),"wraptor_signature",sxao_wraptor_signature_fields,SX_COUNT(sxao_wraptor_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxao_wraptor_flags_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxao_wraptor_flags = {UINT32_C(0x60700015),"wraptor_flags",sxao_wraptor_flags_fields,SX_COUNT(sxao_wraptor_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxao_wraptor_checksum_fields[] = {
 SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxao_wraptor_checksum = {UINT32_C(0x60700016),"wraptor_checksum",sxao_wraptor_checksum_fields,SX_COUNT(sxao_wraptor_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxao_wraptor_end_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxao_wraptor_end = {UINT32_C(0x60700017),"wraptor_end",sxao_wraptor_end_fields,SX_COUNT(sxao_wraptor_end_fields),SX_LE};
static const xx_data_struct_field_desc sxao_corelltec_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
 SX_FIELD("zero","uint8",8,1,SX_NONE),
};
static const sx_layout sxao_corelltec_header = {UINT32_C(0x60700018),"corelltec_header",sxao_corelltec_header_fields,SX_COUNT(sxao_corelltec_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_corelltec_member_fields[] = {
 SX_FIELD("record_size","uint16",0,2,SX_SIZE),
 SX_FIELD("block_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("decoded_member_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",10,4,SX_SIZE),
};
static const sx_layout sxao_corelltec_member = {UINT32_C(0x60700019),"corelltec_member",sxao_corelltec_member_fields,SX_COUNT(sxao_corelltec_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_rsvk_container_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxao_rsvk_container = {UINT32_C(0x6070001a),"rsvk_container",sxao_rsvk_container_fields,SX_COUNT(sxao_rsvk_container_fields),SX_LE};
static const xx_data_struct_field_desc sxao_rsvk_block_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("primary_index","int32",12,4,SX_NONE),
 SX_FIELD("hole_index","int32",16,4,SX_NONE),
};
static const sx_layout sxao_rsvk_block = {UINT32_C(0x6070001b),"rsvk_block",sxao_rsvk_block_fields,SX_COUNT(sxao_rsvk_block_fields),SX_LE};
static const xx_data_struct_field_desc sxao_rsvk_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("compressed_size_hint","int32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",8,4,SX_SIZE),
 SX_FIELD("block_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("first_block_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("dos_time","uint16",20,2,SX_NONE),
 SX_FIELD("dos_date","uint16",22,2,SX_NONE),
 SX_FIELD("attributes","uint32",24,4,SX_FLAGS),
};
static const sx_layout sxao_rsvk_member = {UINT32_C(0x6070001c),"rsvk_member",sxao_rsvk_member_fields,SX_COUNT(sxao_rsvk_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_rsvk_trailer_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unused","uint32",4,4,SX_NONE),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxao_rsvk_trailer = {UINT32_C(0x6070001d),"rsvk_trailer",sxao_rsvk_trailer_fields,SX_COUNT(sxao_rsvk_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxao_arcv_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown","uint8[4]",8,4,SX_NONE),
 SX_FIELD("name_size","uint8",12,1,SX_SIZE),
};
static const sx_layout sxao_arcv_header = {UINT32_C(0x6070001e),"arcv_header",sxao_arcv_header_fields,SX_COUNT(sxao_arcv_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_arcv_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown1","uint8[16]",8,16,SX_NONE),
 SX_FIELD("jamcrc","uint32",24,4,SX_CHECKSUM),
 SX_FIELD("unknown2","uint8[6]",28,6,SX_NONE),
};
static const sx_layout sxao_arcv_member = {UINT32_C(0x6070001f),"arcv_member",sxao_arcv_member_fields,SX_COUNT(sxao_arcv_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_arcv_chunk_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown1","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown2","uint32",8,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxao_arcv_chunk = {UINT32_C(0x60700020),"arcv_chunk",sxao_arcv_chunk_fields,SX_COUNT(sxao_arcv_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bcw_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxao_bcw_header = {UINT32_C(0x60700021),"bcw_header",sxao_bcw_header_fields,SX_COUNT(sxao_bcw_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bcw_record_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_NONE),
};
static const sx_layout sxao_bcw_record = {UINT32_C(0x60700022),"bcw_record",sxao_bcw_record_fields,SX_COUNT(sxao_bcw_record_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bcw_time_fields[] = {
 SX_FIELD("dos_date","uint16",0,2,SX_NONE),
 SX_FIELD("dos_time","uint16",2,2,SX_NONE),
};
static const sx_layout sxao_bcw_time = {UINT32_C(0x60700023),"bcw_time",sxao_bcw_time_fields,SX_COUNT(sxao_bcw_time_fields),SX_LE};
static const xx_data_struct_field_desc sxao_scf_header_fields[] = {
 SX_FIELD("constant","uint32",0,4,SX_NONE),
};
static const sx_layout sxao_scf_header = {UINT32_C(0x60700024),"scf_header",sxao_scf_header_fields,SX_COUNT(sxao_scf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_scf_member_fields[] = {
 SX_FIELD("name","char[14]",0,14,SX_NONE),
 SX_FIELD("compressed_size","uint32",14,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",22,2,SX_NONE),
 SX_FIELD("dos_time","uint16",24,2,SX_NONE),
};
static const sx_layout sxao_scf_member = {UINT32_C(0x60700025),"scf_member",sxao_scf_member_fields,SX_COUNT(sxao_scf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_recognita_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("uncompressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",17,2,SX_NONE),
 SX_FIELD("dos_date","uint16",19,2,SX_NONE),
 SX_FIELD("next_header_offset","uint32",21,4,SX_OFFSET),
};
static const sx_layout sxao_recognita_member = {UINT32_C(0x60700026),"recognita_member",sxao_recognita_member_fields,SX_COUNT(sxao_recognita_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_jasc_member_fields[] = {
 SX_FIELD("header_size_minus2","uint8",0,1,SX_NONE),
 SX_FIELD("header_check","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",2,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("modification_time","uint32",10,4,SX_TIME),
 SX_FIELD("crc16","uint16",14,2,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",16,1,SX_SIZE),
};
static const sx_layout sxao_jasc_member = {UINT32_C(0x60700027),"jasc_member",sxao_jasc_member_fields,SX_COUNT(sxao_jasc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_jasc_end_fields[] = {
 SX_FIELD("terminator","uint8",0,1,SX_NONE),
};
static const sx_layout sxao_jasc_end = {UINT32_C(0x60700028),"jasc_end",sxao_jasc_end_fields,SX_COUNT(sxao_jasc_end_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_header_fields[] = {
 SX_FIELD("volume_prefix","uint8[16]",0,16,SX_NONE),
};
static const sx_layout sxao_bnd_header = {UINT32_C(0x60700029),"bnd_header",sxao_bnd_header_fields,SX_COUNT(sxao_bnd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_record_fields[] = {
 SX_FIELD("next_record_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("unknown","uint8[8]",8,8,SX_NONE),
 SX_FIELD("stored_member_size","uint32",16,4,SX_SIZE),
 SX_FIELD("path","char[256]",20,256,SX_NONE),
};
static const sx_layout sxao_bnd_record = {UINT32_C(0x6070002a),"bnd_record",sxao_bnd_record_fields,SX_COUNT(sxao_bnd_record_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_prologue_fields[] = {
 SX_FIELD("link_name","char[14]",0,14,SX_NONE),
 SX_FIELD("constant1","uint16",14,2,SX_NONE),
 SX_FIELD("constant2","uint16",16,2,SX_NONE),
 SX_FIELD("record_type","uint16",18,2,SX_NONE),
 SX_FIELD("constant3","uint16",20,2,SX_NONE),
 SX_FIELD("zero","uint8[36]",22,36,SX_NONE),
};
static const sx_layout sxao_bnd_prologue = {UINT32_C(0x6070002b),"bnd_prologue",sxao_bnd_prologue_fields,SX_COUNT(sxao_bnd_prologue_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_member_tail_fields[] = {
 SX_FIELD("name","char[128]",0,128,SX_NONE),
 SX_FIELD("attributes","uint32",128,4,SX_FLAGS),
 SX_FIELD("zero","uint32",132,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",136,4,SX_SIZE),
 SX_FIELD("dos_date_word","uint32",140,4,SX_NONE),
 SX_FIELD("dos_time_word","uint32",144,4,SX_NONE),
 SX_FIELD("unknown","uint8[20]",148,20,SX_NONE),
};
static const sx_layout sxao_bnd_member_tail = {UINT32_C(0x6070002c),"bnd_member_tail",sxao_bnd_member_tail_fields,SX_COUNT(sxao_bnd_member_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxao_bnd_trailer_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_record_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("last_record_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxao_bnd_trailer = {UINT32_C(0x6070002d),"bnd_trailer",sxao_bnd_trailer_fields,SX_COUNT(sxao_bnd_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxao_smsipak_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("stamp","uint16",8,2,SX_NONE),
 SX_FIELD("member_area_end","uint32",10,4,SX_OFFSET),
};
static const sx_layout sxao_smsipak_header = {UINT32_C(0x6070002e),"smsipak_header",sxao_smsipak_header_fields,SX_COUNT(sxao_smsipak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_smsipak_member_fields[] = {
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("terminator","uint8",12,1,SX_NONE),
 SX_FIELD("dos_date","uint16",13,2,SX_NONE),
 SX_FIELD("dos_time","uint16",15,2,SX_NONE),
 SX_FIELD("crc32","uint32",17,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint16",21,2,SX_FLAGS),
 SX_FIELD("method","uint8",23,1,SX_NONE),
 SX_FIELD("uncompressed_size","int32",24,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",28,4,SX_SIZE),
 SX_FIELD("zero","uint16",32,2,SX_NONE),
};
static const sx_layout sxao_smsipak_member = {UINT32_C(0x6070002f),"smsipak_member",sxao_smsipak_member_fields,SX_COUNT(sxao_smsipak_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_smsipak_index_fields[] = {
 SX_FIELD("zero","uint32",0,4,SX_NONE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxao_smsipak_index = {UINT32_C(0x60700030),"smsipak_index",sxao_smsipak_index_fields,SX_COUNT(sxao_smsipak_index_fields),SX_LE};
static const xx_data_struct_field_desc sxao_smsipak_index_entry_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxao_smsipak_index_entry = {UINT32_C(0x60700031),"smsipak_index_entry",sxao_smsipak_index_entry_fields,SX_COUNT(sxao_smsipak_index_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxao_cpx_header_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_NONE),
 SX_FIELD("signature","uint8[3]",1,3,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxao_cpx_header = {UINT32_C(0x60700032),"cpx_header",sxao_cpx_header_fields,SX_COUNT(sxao_cpx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_cpx_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("group","uint8",13,1,SX_NONE),
 SX_FIELD("dos_datetime","uint32",14,4,SX_NONE),
 SX_FIELD("size_and_stored_flag","uint32",18,4,SX_FLAGS),
 SX_FIELD("payload_offset","uint32",22,4,SX_OFFSET),
};
static const sx_layout sxao_cpx_member = {UINT32_C(0x60700033),"cpx_member",sxao_cpx_member_fields,SX_COUNT(sxao_cpx_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_cpx4_header_fields[] = {
 SX_FIELD("version_stamp","uint8",0,1,SX_NONE),
 SX_FIELD("signature","uint8[3]",1,3,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("version","uint16",6,2,SX_NONE),
 SX_FIELD("record_table_size","uint32",8,4,SX_SIZE),
 SX_FIELD("record_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("name_table_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name_table_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("extra_size","uint32",24,4,SX_SIZE),
 SX_FIELD("extra_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("stamp","uint32",32,4,SX_NONE),
};
static const sx_layout sxao_cpx4_header = {UINT32_C(0x60700034),"cpx4_header",sxao_cpx4_header_fields,SX_COUNT(sxao_cpx4_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_cpx4_member_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("flags","uint32",16,4,SX_FLAGS),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("payload_offset","uint32",24,4,SX_OFFSET),
};
static const sx_layout sxao_cpx4_member = {UINT32_C(0x60700035),"cpx4_member",sxao_cpx4_member_fields,SX_COUNT(sxao_cpx4_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_red_member_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint8",2,1,SX_NONE),
 SX_FIELD("header_size","uint8",3,1,SX_SIZE),
 SX_FIELD("dos_time","uint16",4,2,SX_NONE),
 SX_FIELD("dos_date","uint16",6,2,SX_NONE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("crc1","uint16",16,2,SX_CHECKSUM),
 SX_FIELD("crc2","uint16",18,2,SX_CHECKSUM),
 SX_FIELD("fragment_number","uint16",20,2,SX_NONE),
 SX_FIELD("last_fragment","uint16",22,2,SX_NONE),
 SX_FIELD("method","uint16",24,2,SX_NONE),
};
static const sx_layout sxao_red_member = {UINT32_C(0x60700036),"red_member",sxao_red_member_fields,SX_COUNT(sxao_red_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_red_header_crc_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxao_red_header_crc = {UINT32_C(0x60700037),"red_header_crc",sxao_red_header_crc_fields,SX_COUNT(sxao_red_header_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxao_red_segment_crc_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxao_red_segment_crc = {UINT32_C(0x60700038),"red_segment_crc",sxao_red_segment_crc_fields,SX_COUNT(sxao_red_segment_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxao_aiaff_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("member_table_offset","ascii_decimal[12]",8,12,SX_OFFSET),
 SX_FIELD("symbol_table_offset","ascii_decimal[12]",20,12,SX_OFFSET),
 SX_FIELD("first_member_offset","ascii_decimal[12]",32,12,SX_OFFSET),
 SX_FIELD("last_member_offset","ascii_decimal[12]",44,12,SX_OFFSET),
 SX_FIELD("free_list_offset","ascii_decimal[12]",56,12,SX_OFFSET),
};
static const sx_layout sxao_aiaff_header = {UINT32_C(0x60700039),"aiaff_header",sxao_aiaff_header_fields,SX_COUNT(sxao_aiaff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_aiaff_member_fields[] = {
 SX_FIELD("payload_size","ascii_decimal[12]",0,12,SX_SIZE),
 SX_FIELD("next_member_offset","ascii_decimal[12]",12,12,SX_OFFSET),
 SX_FIELD("previous_member_offset","ascii_decimal[12]",24,12,SX_OFFSET),
 SX_FIELD("modification_time","ascii_decimal[12]",36,12,SX_TIME),
 SX_FIELD("user_id","ascii_decimal[12]",48,12,SX_NONE),
 SX_FIELD("group_id","ascii_decimal[12]",60,12,SX_NONE),
 SX_FIELD("mode","ascii_octal_padded[12]",72,12,SX_FLAGS),
 SX_FIELD("name_size","ascii_decimal[4]",84,4,SX_SIZE),
};
static const sx_layout sxao_aiaff_member = {UINT32_C(0x6070003a),"aiaff_member",sxao_aiaff_member_fields,SX_COUNT(sxao_aiaff_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_aiaff_terminator_fields[] = {
 SX_FIELD("terminator","char[2]",0,2,SX_SIGNATURE),
};
static const sx_layout sxao_aiaff_terminator = {UINT32_C(0x6070003b),"aiaff_terminator",sxao_aiaff_terminator_fields,SX_COUNT(sxao_aiaff_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxao_softpaq2_locator_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("unknown1","uint8[8]",8,8,SX_NONE),
 SX_FIELD("self_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("directory_offset","int32",20,4,SX_OFFSET),
 SX_FIELD("split_offset","int32",24,4,SX_OFFSET),
 SX_FIELD("unknown2","uint8[9]",28,9,SX_NONE),
};
static const sx_layout sxao_softpaq2_locator = {UINT32_C(0x6070003c),"softpaq2_locator",sxao_softpaq2_locator_fields,SX_COUNT(sxao_softpaq2_locator_fields),SX_LE};
static const xx_data_struct_field_desc sxao_softpaq2_stored_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("zero1","uint8",8,1,SX_NONE),
 SX_FIELD("extension","char[4]",9,4,SX_NONE),
 SX_FIELD("zero2","uint8",13,1,SX_NONE),
 SX_FIELD("payload_size","int32",14,4,SX_SIZE),
 SX_FIELD("payload_offset","int32",18,4,SX_OFFSET),
 SX_FIELD("published","uint8",22,1,SX_NONE),
};
static const sx_layout sxao_softpaq2_stored = {UINT32_C(0x6070003d),"softpaq2_stored",sxao_softpaq2_stored_fields,SX_COUNT(sxao_softpaq2_stored_fields),SX_LE};
static const xx_data_struct_field_desc sxao_softpaq2_compressed_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("zero1","uint8",8,1,SX_NONE),
 SX_FIELD("extension","char[4]",9,4,SX_NONE),
 SX_FIELD("zero2","uint8",13,1,SX_NONE),
 SX_FIELD("method","uint16",14,2,SX_NONE),
 SX_FIELD("dos_time","uint16",16,2,SX_NONE),
 SX_FIELD("dos_date","uint16",18,2,SX_NONE),
 SX_FIELD("crc32","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","int32",24,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",28,4,SX_SIZE),
 SX_FIELD("attributes","uint16",32,2,SX_FLAGS),
 SX_FIELD("payload_offset","int32",34,4,SX_OFFSET),
};
static const sx_layout sxao_softpaq2_compressed = {UINT32_C(0x6070003e),"softpaq2_compressed",sxao_softpaq2_compressed_fields,SX_COUNT(sxao_softpaq2_compressed_fields),SX_LE};
static const xx_data_struct_field_desc sxao_archiveobsolete_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxao_archiveobsolete_dcl = {UINT32_C(0x6070003f),"archiveobsolete_dcl",sxao_archiveobsolete_dcl_fields,SX_COUNT(sxao_archiveobsolete_dcl_fields),SX_LE};
static const sx_layout *const sx_archiveobsolete_layouts[] = {
 &sxao_sw_header,
 &sxao_sw_path_length,
 &sxao_archiveobsolete_name,
 &sxao_archiveobsolete_path,
 &sxao_dsl2_header,
 &sxao_dsl2_path_length,
 &sxao_dsl2_member,
 &sxao_dsl2_name_length,
 &sxao_dsl2_name,
 &sxao_topspeed_block,
 &sxao_ulead_prefix,
 &sxao_ulead_name,
 &sxao_ulead_block_counts,
 &sxao_ulead_block_size,
 &sxao_quantum_header,
 &sxao_quantum_length1,
 &sxao_quantum_length2,
 &sxao_quantum_member,
 &sxao_quantum_crc16,
 &sxao_wraptor_signature,
 &sxao_wraptor_flags,
 &sxao_wraptor_checksum,
 &sxao_wraptor_end,
 &sxao_corelltec_header,
 &sxao_corelltec_member,
 &sxao_rsvk_container,
 &sxao_rsvk_block,
 &sxao_rsvk_member,
 &sxao_rsvk_trailer,
 &sxao_arcv_header,
 &sxao_arcv_member,
 &sxao_arcv_chunk,
 &sxao_bcw_header,
 &sxao_bcw_record,
 &sxao_bcw_time,
 &sxao_scf_header,
 &sxao_scf_member,
 &sxao_recognita_member,
 &sxao_jasc_member,
 &sxao_jasc_end,
 &sxao_bnd_header,
 &sxao_bnd_record,
 &sxao_bnd_prologue,
 &sxao_bnd_member_tail,
 &sxao_bnd_trailer,
 &sxao_smsipak_header,
 &sxao_smsipak_member,
 &sxao_smsipak_index,
 &sxao_smsipak_index_entry,
 &sxao_cpx_header,
 &sxao_cpx_member,
 &sxao_cpx4_header,
 &sxao_cpx4_member,
 &sxao_red_member,
 &sxao_red_header_crc,
 &sxao_red_segment_crc,
 &sxao_aiaff_header,
 &sxao_aiaff_member,
 &sxao_aiaff_terminator,
 &sxao_softpaq2_locator,
 &sxao_softpaq2_stored,
 &sxao_softpaq2_compressed,
 &sxao_archiveobsolete_dcl,
};
static bool sx_archiveobsolete_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60700000U||id>=0x60710000U)return true;
 if(r->type&&(!xx_rt_wcsncmp(r->type,L"ascii_decimal[",14)||!xx_rt_wcsncmp(r->type,L"ascii_octal_padded[",19))&&r->value.type!=XX_VAR_TYPE_UINT64&&r->value.type!=XX_VAR_TYPE_INT64)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60700007U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Per-byte+0x33 storage bias; decoded bit0x10 selects DCL";
 break;
 case 0x60700008U:
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Decoded length includes the NUL; native name extent is directory-bounded, not record-bounded";
 break;
 case 0x6070000aU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Additive sum of stored payload bytes";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Physical payload uses min(compressed_size,uncompressed_size); compressed_size>=uncompressed_size means stored";
 break;
 case 0x6070000dU:
 if(!xx_rt_wcscmp(r->name,L"last_block_size"))text=L"Earlier blocks decode to16384 bytes each";
 break;
 case 0x6070000eU:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Stored if equal to this block plain size; otherwise independent12-bit LZW";
 break;
 case 0x6070000fU:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"Below0x17 uses directory CRC and old solid coder";
 if(!xx_rt_wcscmp(r->name,L"window_bits"))text=L"Encoded power of two,10..21";
 break;
 case 0x60700011U:
 if(!xx_rt_wcscmp(r->name,L"length_high"))text=L"Bit7 is set; low7 bits are upper length bits";
 if(!xx_rt_wcscmp(r->name,L"length_low"))text=L"Full byte length=((length_high&0x7f)<<8)|length_low";
 break;
 case 0x60700013U:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"Old stream variant plaintext checksum";
 break;
 case 0x60700016U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Stored word; algorithm not verified by native reader";
 break;
 case 0x60700018U:
 if(!xx_rt_wcscmp(r->name,L"unknown"))text=L"Meaning not established";
 break;
 case 0x60700019U:
 if(!xx_rt_wcscmp(r->name,L"block_offset"))text=L"Relative to physical payload area after directory";
 if(!xx_rt_wcscmp(r->name,L"decoded_member_offset"))text=L"Offset in decompressed block, not a physical file coordinate";
 break;
 case 0x6070001bU:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Plaintext checksum";
 if(!xx_rt_wcscmp(r->name,L"primary_index"))text=L"Inverse BWT primary row";
 if(!xx_rt_wcscmp(r->name,L"hole_index"))text=L"Inverse BWT sentinel row";
 break;
 case 0x6070001cU:
 if(!xx_rt_wcscmp(r->name,L"compressed_size_hint"))text=L"Stored hint; actual block chain can have a different length";
 break;
 case 0x6070001eU:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"0x0100 LH1 or0x0110 stop-symbol LZHUF";
 break;
 case 0x6070001fU:
 if(!xx_rt_wcscmp(r->name,L"jamcrc"))text=L"v1.00 plaintext; v1.10 matching packed checksum selects compact coder, otherwise plaintext wide coder";
 break;
 case 0x60700022U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0 terminator,1 file,2 enter directory,3 leave directory";
 break;
 case 0x60700027U:
 if(!xx_rt_wcscmp(r->name,L"header_size_minus2"))text=L"Encoded header length equals name_size+15; actual header is stored value+2";
 if(!xx_rt_wcscmp(r->name,L"header_check"))text=L"Algorithm not established";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Unix seconds since1970-01-01";
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/ARC of plaintext";
 break;
 case 0x60700029U:
 if(!xx_rt_wcscmp(r->name,L"volume_prefix"))text=L"All-zero standalone prefix, or repeated [20/20] tag in executable-overlay variant";
 break;
 case 0x6070002aU:
 if(!xx_rt_wcscmp(r->name,L"stored_member_size"))text=L"Includes the member prologue/header";
 break;
 case 0x6070002bU:
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"0x74 full member,0x75 continuation";
 break;
 case 0x6070002cU:
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"DOS attributes word at member+0xba";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Declared whole member stream, possibly continued in next volume";
 if(!xx_rt_wcscmp(r->name,L"dos_date_word"))text=L"Low16 bits contain DOS date";
 if(!xx_rt_wcscmp(r->name,L"dos_time_word"))text=L"Low16 bits contain DOS time";
 break;
 case 0x6070002fU:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Plaintext checksum";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 DCL,2 stored";
 break;
 case 0x60700033U:
 if(!xx_rt_wcscmp(r->name,L"group"))text=L"Path or volume identifier";
 if(!xx_rt_wcscmp(r->name,L"size_and_stored_flag"))text=L"Bit31 means stored, low31 bits are unreliable for stored members";
 break;
 case 0x60700035U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to name table";
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored timestamp; epoch not established";
 break;
 case 0x60700036U:
 if(!xx_rt_wcscmp(r->name,L"crc1"))text=L"Opaque stored checksum word";
 if(!xx_rt_wcscmp(r->name,L"crc2"))text=L"CRC16/IBM-3740 of plaintext";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 stored,11 LH5 with per-segment CRC words";
 break;
 case 0x60700037U:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/IBM-3740 over header bytes2 through header_size-3";
 break;
 case 0x60700038U:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16/IBM-3740 of up to4094 coded bytes; whole declared segment must be physically present";
 break;
 case 0x6070003aU:
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Unix seconds since epoch";
 if(!xx_rt_wcscmp(r->name,L"mode"))text=L"Octal ASCII file type and permissions";
 break;
 case 0x6070003dU:
 if(!xx_rt_wcscmp(r->name,L"published"))text=L"0 extractor resource,nonzero public archive member";
 break;
 case 0x6070003eU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored,6 DCL";
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Packed stream checksum";
 break;
 case 0x6070003fU:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 direct or1 Huffman literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4=1KiB,5=2KiB,6=4KiB; encoded power,not byte count";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAO_LIMIT 20000U
static bool sxao_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxao_read(sx_context*c,uint64_t p,void*b,size_t n){return sxao_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxao_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxao_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxao_read(c,p,b,n))return false;*v=sxao_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxao_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXAO_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxao_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxao_add(sx_context*c,const sx_layout*l,uint64_t p){return sxao_put(c,l,p,0,false);}
static bool sxao_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){return !n||n>4096?true:sxao_put(c,l,p,n,aliases);}
static bool sxao_zlen(sx_context*c,uint64_t p,uint64_t end,uint64_t*n){uint8_t b;*n=0;while(p<end&&*n<4096){if(!sxao_read(c,p++,&b,1))return false;(*n)++;if(!b)return true;}return false;}
static int sxao_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxao_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxao_order);return !c->failed;}
static bool sxao_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxao_add(c,l,p+i*width))return false;return true;}
static bool sxao_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t b[2];return n<2||!sxao_read(c,p,b,2)||b[0]>1||b[1]<4||b[1]>6?true:sxao_add(c,&sxao_archiveobsolete_dcl,p);}
/* Reuse authenticated physical extents for grammars whose end is codec-defined.
 * Callbacks belong to the supplied native reader; no constructor is linked. */
static bool sxao_native_members(sx_context*c){xx_archive_record_state*s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);if(!s)return false;bool ok=true;uint64_t end=0;for(size_t work=0;work<SXAO_LIMIT;work++){const xx_archive_record*r=xx_format_get_current_archive_record(c->f,s);if(!r)break;if(r->header_offset<c->f->base_address||r->header_size<0||r->data_offset<c->f->base_address||r->compressed_size<0){ok=false;break;}uint64_t p=(uint64_t)(r->header_offset-c->f->base_address),n=(uint64_t)r->header_size,d=(uint64_t)(r->data_offset-c->f->base_address),z=(uint64_t)r->compressed_size;if(!sxao_span(c,p,n)||!sxao_span(c,d,z)){ok=false;break;}
 if(c->f->file_type==XX_FILE_TYPE_SW){if(n<2||!sxao_add(c,&sxao_sw_path_length,p)||!sxao_text(c,&sxao_archiveobsolete_path,p+2,n-2,false)){ok=false;break;}}
 else if(c->f->file_type==XX_FILE_TYPE_C64WRAPTOR){if(n<6||d!=p+n||!sxao_add(c,&sxao_wraptor_signature,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+4,n-5,false)||!sxao_add(c,&sxao_wraptor_flags,d-1)||!sxao_add(c,&sxao_wraptor_checksum,d+z)){ok=false;break;}end=d+z+2;}
 else if(c->f->file_type==XX_FILE_TYPE_CORELLTEC){if(n<15||!sxao_add(c,&sxao_corelltec_member,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+14,n-14,false)){ok=false;break;}}
 if(!xx_format_archive_record_move_to_next(c->f,s,c->pd))break;}
 xx_format_free_archive_records_reading(c->f,s);if(ok&&c->f->file_type==XX_FILE_TYPE_C64WRAPTOR){uint64_t tag;if(sxao_word(c,end,4,false,&tag)&&tag==0x1a1a1a1a)ok=sxao_add(c,&sxao_wraptor_end,end);}return ok;}
static bool sxao_dsl2(sx_context*c){uint64_t p=28,n,end;if(!sxao_add(c,&sxao_dsl2_header,0)||!sxao_word(c,18,2,false,&n)||!sxao_word(c,24,4,false,&end)||end>INT32_MAX||end>(uint64_t)c->size)return false;for(unsigned i=0;i<2;i++){uint64_t z;if(!sxao_word(c,p,2,false,&z)||!sxao_add(c,&sxao_dsl2_path_length,p)||!sxao_span(c,p+2,z)||p+2+z>end)return false;p+=2;if(!sxao_text(c,&sxao_archiveobsolete_path,p,z,false))return false;p+=z;}
 for(uint64_t i=0;i<n;i++){uint8_t b[22];if(p>end||end-p<20||!sxao_read(c,p,b,20))return false;for(unsigned j=0;j<20;j++)b[j]=(uint8_t)(b[j]-0x33U);uint64_t z=sxao_uint(b,2,false);if(z<20||z>end-p||!sxao_put(c,&sxao_dsl2_member,p,20,true))return false;uint64_t payload=sxao_uint(b+10,4,false),packed=sxao_uint(b+6,4,false);if((sxao_uint(b+18,2,false)&16)&&payload<=INT32_MAX&&packed<=INT32_MAX&&sxao_span(c,payload,packed)&&!sxao_dcl(c,payload,packed))return false;if(end-p>=22){if(!sxao_read(c,p+20,b+20,2))return false;b[20]=(uint8_t)(b[20]-0x33U);b[21]=(uint8_t)(b[21]-0x33U);uint64_t name=sxao_uint(b+20,2,false);if(name>end-p-22)name=end-p-22;if(!sxao_put(c,&sxao_dsl2_name_length,p+20,2,true)||!sxao_text(c,&sxao_dsl2_name,p+22,name,true))return false;}p+=z;}return true;}
static bool sxao_topspeed(sx_context*c){uint64_t p=0;while(sxao_span(c,p,6)){uint8_t h[6];if(!sxao_read(c,p,h,6)||!sxao_add(c,&sxao_topspeed_block,p))return false;uint64_t a=sxao_uint(h+2,2,false),b=sxao_uint(h+4,2,false),z=a<b?a:b;p+=6;if(!sxao_span(c,p,z))return true;p+=z;}return true;}
static bool sxao_ulead(sx_context*c){uint8_t b[44];if(!sxao_read(c,0,b,44)||!sxao_add(c,&sxao_ulead_prefix,0))return false;uint64_t n1=sxao_uint(b+24,2,false),z1=sxao_uint(b+26,2,false),n2=sxao_uint(b+40,2,false),z2=sxao_uint(b+42,2,false);bool a=n1&&z1<=16384&&28+2*n1<(uint64_t)c->size,d=n2&&z2<=16384&&44+2*n2<(uint64_t)c->size;bool short_header=a&&(!d||n1<0x2000);if(!a&&!d)return false;uint64_t p=short_header?24:40,n=short_header?n1:n2;if(!short_header&&!sxao_add(c,&sxao_ulead_name,24))return false;return sxao_add(c,&sxao_ulead_block_counts,p)&&sxao_table(c,&sxao_ulead_block_size,p+4,2,n);}
static bool sxao_qlength(sx_context*c,uint64_t*p,uint64_t*z){uint8_t b[2];if(!sxao_read(c,*p,b,1))return false;if(b[0]&128){if(!sxao_read(c,*p,b,2)||!sxao_add(c,&sxao_quantum_length2,*p))return false;*z=((b[0]&127U)<<8)|b[1];*p+=2;}else{if(!sxao_add(c,&sxao_quantum_length1,*p))return false;*z=b[0];(*p)++;}return sxao_span(c,*p,*z);}
static bool sxao_quantum(sx_context*c){uint64_t p=8,n,ver;if(!sxao_word(c,4,2,false,&n)||!sxao_word(c,3,1,false,&ver)||!sxao_add(c,&sxao_quantum_header,0))return false;for(uint64_t i=0;i<n;i++){uint64_t z;if(!sxao_qlength(c,&p,&z)||!sxao_text(c,&sxao_archiveobsolete_name,p,z,false))return false;p+=z;if(!sxao_qlength(c,&p,&z))return false;p+=z;if(!sxao_add(c,&sxao_quantum_member,p))return false;p+=8;if(ver<0x17){if(!sxao_add(c,&sxao_quantum_crc16,p))return false;p+=2;}}return true;}
static bool sxao_rsvk(sx_context*c){uint64_t n=(uint64_t)c->size,dir;if(n<16||!sxao_add(c,&sxao_rsvk_container,0)||!sxao_add(c,&sxao_rsvk_trailer,n-12)||!sxao_word(c,n-4,4,false,&dir)||dir<24||dir>n-12)return false;uint64_t p=dir;for(size_t work=0;p<n-12&&work<SXAO_LIMIT;work++){uint8_t h[28];uint64_t name;if(n-12-p<28||!sxao_read(c,p,h,28)||!sxao_zlen(c,p+28,n-12,&name)||!sxao_add(c,&sxao_rsvk_member,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+28,name,false))return false;uint64_t count=sxao_uint(h+12,4,false),q=sxao_uint(h+16,4,false);if(count>INT32_MAX||q>INT32_MAX)return false;for(uint64_t j=0;j<count&&c->count<SXAO_LIMIT;j++){uint64_t z;if(q>dir||dir-q<20||!sxao_word(c,q+8,4,false,&z)||z>dir-q-20||!sxao_add(c,&sxao_rsvk_block,q))break;q+=20+z;}p+=28+name;}return true;}
static bool sxao_arcv(sx_context*c){uint8_t b[13];if(!sxao_read(c,0,b,13)||!sxao_add(c,&sxao_arcv_header,0))return false;uint64_t hs=sxao_uint(b+6,2,false),name=b[12];return sxao_text(c,&sxao_archiveobsolete_name,13,name,false)&&sxao_add(c,&sxao_arcv_member,13+name)&&sxao_add(c,&sxao_arcv_chunk,hs);}
static bool sxao_bcw(sx_context*c){if(!sxao_add(c,&sxao_bcw_header,0))return false;xx_archive_record_state*s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);if(!s)return false;uint64_t p=4;bool ok=true;while(p<(uint64_t)c->size&&c->count<SXAO_LIMIT){uint64_t kind,name;if(!sxao_word(c,p,1,false,&kind)||kind>3||!sxao_add(c,&sxao_bcw_record,p++)){ok=false;break;}if(!kind)break;if(kind==3)continue;if(!sxao_zlen(c,p,(uint64_t)c->size,&name)||!sxao_text(c,&sxao_archiveobsolete_name,p,name,false)){ok=false;break;}p+=name;if(kind==2)continue;if(!sxao_add(c,&sxao_bcw_time,p)){ok=false;break;}p+=4;const xx_archive_record*r=xx_format_get_current_archive_record(c->f,s);if(!r||r->data_offset<c->f->base_address||r->compressed_size<0||(uint64_t)(r->data_offset-c->f->base_address)!=p||!sxao_span(c,p,(uint64_t)r->compressed_size)){ok=false;break;}p+=(uint64_t)r->compressed_size;(void)xx_format_archive_record_move_to_next(c->f,s,c->pd);}xx_format_free_archive_records_reading(c->f,s);return ok;}
static bool sxao_scf(sx_context*c){uint64_t p=4;if(!sxao_add(c,&sxao_scf_header,0))return false;while(sxao_span(c,p,26)){uint64_t z;if(!sxao_word(c,p+14,4,false,&z)||!sxao_add(c,&sxao_scf_member,p))return false;p+=26;if(!sxao_span(c,p,z)||!sxao_dcl(c,p,z))return true;p+=z;}return true;}
static bool sxao_recognita(sx_context*c){uint64_t p=0;while(sxao_span(c,p,25)){uint64_t next;if(!sxao_word(c,p+21,4,false,&next)||!sxao_add(c,&sxao_recognita_member,p)||next<=p+25||next>(uint64_t)c->size)return false;if(!sxao_dcl(c,p+25,next-p-25))return false;p=next;}return true;}
static bool sxao_jasc(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint64_t hs,n,z;if(!sxao_word(c,p,1,false,&hs))return false;if(!hs)return sxao_add(c,&sxao_jasc_end,p);if(!sxao_word(c,p+16,1,false,&n)||hs!=n+15||!sxao_word(c,p+2,4,false,&z)||!sxao_add(c,&sxao_jasc_member,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+17,n,false))return false;p+=17+n;if(!sxao_span(c,p,z))return true;p+=z;}return true;}
static bool sxao_bnd(sx_context*c){uint64_t n=(uint64_t)c->size,p,last;if(n<16||!sxao_add(c,&sxao_bnd_header,0)||!sxao_add(c,&sxao_bnd_trailer,n-16)||!sxao_word(c,n-8,4,false,&p)||!sxao_word(c,n-4,4,false,&last))return false;for(size_t work=0;work<SXAO_LIMIT;work++){uint64_t next,z,kind;if(!sxao_word(c,p,4,false,&next)||!sxao_word(c,p+16,4,false,&z)||!sxao_add(c,&sxao_bnd_record,p))return false;uint64_t q=p+276;if(!sxao_span(c,q,z)||z<58||!sxao_word(c,q+18,2,false,&kind)||!sxao_add(c,&sxao_bnd_prologue,q))return false;if(kind==0x74&&z>=226){if(!sxao_add(c,&sxao_bnd_member_tail,q+58)||!sxao_dcl(c,q+226,z-226))return false;}if(p==last||!next)return true;if(next<=p)return false;p=next;}return true;}
static bool sxao_smsi(sx_context*c){uint64_t end,p=14;if(!sxao_word(c,10,4,false,&end)||!sxao_add(c,&sxao_smsipak_header,0)||end>(uint64_t)c->size)return false;while(p<end){uint64_t z,method;if(end-p<34||!sxao_word(c,p+28,4,false,&z)||z>INT32_MAX||!sxao_word(c,p+23,1,false,&method)||!sxao_add(c,&sxao_smsipak_member,p))return false;p+=34;if(z>end-p)return true;if(method==1&&!sxao_dcl(c,p,z))return false;p+=z;}if(sxao_span(c,end,6)){uint64_t n;if(!sxao_word(c,end+4,2,false,&n)||!sxao_add(c,&sxao_smsipak_index,end)||!sxao_table(c,&sxao_smsipak_index_entry,end+6,4,n))return false;}return true;}
static bool sxao_cpx(sx_context*c){uint64_t version;if(!sxao_word(c,0,1,false,&version))return false;if(version!=0x2c){uint64_t n;return sxao_word(c,4,2,false,&n)&&sxao_add(c,&sxao_cpx_header,0)&&sxao_table(c,&sxao_cpx_member,6,26,n);}uint64_t size,off,names,nsize;if(!sxao_word(c,8,4,false,&size)||!sxao_word(c,12,4,false,&off)||!sxao_word(c,16,4,false,&nsize)||!sxao_word(c,20,4,false,&names)||!sxao_add(c,&sxao_cpx4_header,0)||size%28||!sxao_table(c,&sxao_cpx4_member,off,28,size/28)||!sxao_span(c,names,nsize))return false;for(uint64_t i=0;i<size/28&&c->count<SXAO_LIMIT;i++){uint64_t rel,n;if(!sxao_word(c,off+i*28,4,false,&rel))return false;if(rel<nsize&&sxao_zlen(c,names+rel,names+nsize,&n)&&!sxao_text(c,&sxao_archiveobsolete_name,names+rel,n,false))return false;}return true;}
static bool sxao_red(sx_context*c){uint64_t p=0;while(sxao_span(c,p,39)){uint8_t h[26];if(!sxao_read(c,p,h,26))return false;uint64_t hs=h[3],z=sxao_uint(h+8,4,false),method=sxao_uint(h+24,2,false);if(hs<39||!sxao_span(c,p,hs)||!sxao_add(c,&sxao_red_member,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+26,12,true)||!sxao_put(c,&sxao_red_header_crc,p+hs-2,2,true))return false;p+=hs;if(!sxao_span(c,p,z))return true;if(method==11){uint64_t q=p,remain=z;while(remain){uint64_t block=remain>4096?4096:remain;if(block>=2&&!sxao_add(c,&sxao_red_segment_crc,q+block-2))return false;q+=block;remain-=block;}}p+=z;}return true;}
static bool sxao_decimal(sx_context*c,uint64_t p,unsigned n,uint64_t*v){uint8_t b[24];if(!n||n>24||!sxao_read(c,p,b,n))return false;*v=0;unsigned first=0,last=n;while(first<last&&(b[first]==' '||b[first]=='\t'))first++;while(last>first&&(b[last-1]==' '||b[last-1]=='\t'||b[last-1]=='\r'||b[last-1]=='\n'))last--;for(unsigned i=first;i<last;i++){if(b[i]<'0'||b[i]>'9'||*v>(UINT64_MAX-(b[i]-'0'))/10)return false;*v=*v*10+(b[i]-'0');}return true;}
static bool sxao_aiaff(sx_context*c){uint64_t p,last;if(!sxao_decimal(c,32,12,&p)||!sxao_decimal(c,44,12,&last)||!sxao_add(c,&sxao_aiaff_header,0))return false;uint64_t anchor=p,power=1,length=0;for(size_t work=0;p&&work<SXAO_LIMIT;work++){uint64_t n,next;if(!sxao_decimal(c,p+84,4,&n)||!sxao_decimal(c,p+12,12,&next)||!sxao_add(c,&sxao_aiaff_member,p)||!sxao_span(c,p+88,n+(n&1)+2)||!sxao_text(c,&sxao_archiveobsolete_name,p+88,n,false)||!sxao_add(c,&sxao_aiaff_terminator,p+88+n+(n&1)))return false;if(p==last||!next)break;if(next==anchor)return false;if(++length==power){anchor=next;length=0;if(power<=SXAO_LIMIT/2)power*=2;}p=next;}return true;}
static bool sxao_softpaq(sx_context*c){uint64_t size=(uint64_t)c->size;uint8_t h[37];uint8_t block[4096];for(uint64_t base=0;size>=37&&base<=size-37;){size_t amount=(size_t)((size-36-base)>sizeof(block)?sizeof(block):(size-36-base));if(xx_pd_is_stopped(c->pd)||!sxao_read(c,base,block,amount))return false;for(size_t i=0;i<amount;i++){uint64_t p=base+i;if(block[i]!='[')continue;if(!sxao_read(c,p,h,37)||xx_rt_memcmp(h,"[FIT]\0\1\0",8))continue;uint64_t self=sxao_uint(h+16,4,false),dir=sxao_uint(h+20,4,false),split=sxao_uint(h+24,4,false);if(self!=p||dir>INT32_MAX||split>INT32_MAX||dir>split||split>size||(split-dir)%23||(size-split)%38)continue;if(!sxao_add(c,&sxao_softpaq2_locator,p)||!sxao_table(c,&sxao_softpaq2_stored,dir,23,(split-dir)/23)||!sxao_table(c,&sxao_softpaq2_compressed,split,38,(size-split)/38))return false;for(uint64_t q=split;q+38<=size&&c->count<SXAO_LIMIT;q+=38){uint64_t method,off,z;if(!sxao_word(c,q+14,2,false,&method)||!sxao_word(c,q+34,4,false,&off)||!sxao_word(c,q+28,4,false,&z))return false;if(method==6&&sxao_span(c,off,z)&&!sxao_dcl(c,off,z))return false;}return true;}base+=amount;}return false;}
static bool sx_archiveobsolete_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_SW:case XX_FILE_TYPE_DSL2:case XX_FILE_TYPE_TOPSPEED:case XX_FILE_TYPE_ULEAD:case XX_FILE_TYPE_QUANTUM:case XX_FILE_TYPE_C64WRAPTOR:case XX_FILE_TYPE_CORELLTEC:case XX_FILE_TYPE_RSVK:case XX_FILE_TYPE_ARCV:case XX_FILE_TYPE_BCW:case XX_FILE_TYPE_SCF:case XX_FILE_TYPE_RECOGNITA:case XX_FILE_TYPE_JASC:case XX_FILE_TYPE_BND:case XX_FILE_TYPE_SMSIPAK:case XX_FILE_TYPE_CPX:case XX_FILE_TYPE_CPX4:case XX_FILE_TYPE_RED:case XX_FILE_TYPE_AIAFF:case XX_FILE_TYPE_SOFTPAQ2:return true;default:return false;}}
static bool sx_archiveobsolete_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_SW:ok=sxao_add(c,&sxao_sw_header,0)&&sxao_native_members(c);break;case XX_FILE_TYPE_DSL2:ok=sxao_dsl2(c);break;case XX_FILE_TYPE_TOPSPEED:ok=sxao_topspeed(c);break;case XX_FILE_TYPE_ULEAD:ok=sxao_ulead(c);break;case XX_FILE_TYPE_QUANTUM:ok=sxao_quantum(c);break;case XX_FILE_TYPE_C64WRAPTOR:ok=sxao_native_members(c);break;case XX_FILE_TYPE_CORELLTEC:ok=sxao_add(c,&sxao_corelltec_header,0)&&sxao_native_members(c);break;case XX_FILE_TYPE_RSVK:ok=sxao_rsvk(c);break;case XX_FILE_TYPE_ARCV:ok=sxao_arcv(c);break;case XX_FILE_TYPE_BCW:ok=sxao_bcw(c);break;case XX_FILE_TYPE_SCF:ok=sxao_scf(c);break;case XX_FILE_TYPE_RECOGNITA:ok=sxao_recognita(c);break;case XX_FILE_TYPE_JASC:ok=sxao_jasc(c);break;case XX_FILE_TYPE_BND:ok=sxao_bnd(c);break;case XX_FILE_TYPE_SMSIPAK:ok=sxao_smsi(c);break;case XX_FILE_TYPE_CPX:case XX_FILE_TYPE_CPX4:ok=sxao_cpx(c);break;case XX_FILE_TYPE_RED:ok=sxao_red(c);break;case XX_FILE_TYPE_AIAFF:ok=sxao_aiaff(c);break;case XX_FILE_TYPE_SOFTPAQ2:ok=sxao_softpaq(c);break;default:break;}(void)ok;return c->count&&sxao_finish(c);}
