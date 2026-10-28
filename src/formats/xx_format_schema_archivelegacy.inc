/* SPDX-License-Identifier: MIT. Physical archive metadata. Scope: docs/data_struct_archivelegacy_scope.txt. */
static const xx_data_struct_field_desc sxag_amplus_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("form_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxag_amplus_header = {UINT32_C(0x60250001),"amplus_header",sxag_amplus_header_fields,SX_COUNT(sxag_amplus_header_fields),SX_BE};
static const xx_data_struct_field_desc sxag_amplus_chunk_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxag_amplus_chunk = {UINT32_C(0x60250002),"amplus_chunk",sxag_amplus_chunk_fields,SX_COUNT(sxag_amplus_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxag_amplus_data_fields[] = {
 SX_FIELD("compression","uint16",0,2,SX_ID),
 SX_FIELD("packed_size_hint","uint32",2,4,SX_SIZE),
 SX_FIELD("checksum","uint32",6,4,SX_CHECKSUM),
};
static const sx_layout sxag_amplus_data = {UINT32_C(0x60250003),"amplus_data",sxag_amplus_data_fields,SX_COUNT(sxag_amplus_data_fields),SX_BE};
static const xx_data_struct_field_desc sxag_amplus_file_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
 SX_FIELD("days","int32",12,4,SX_NONE),
 SX_FIELD("minutes","int32",16,4,SX_NONE),
 SX_FIELD("ticks","int32",20,4,SX_NONE),
 SX_FIELD("protection","uint32",24,4,SX_FLAGS),
};
static const sx_layout sxag_amplus_file = {UINT32_C(0x60250004),"amplus_file",sxag_amplus_file_fields,SX_COUNT(sxag_amplus_file_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_header_fields[] = {
 SX_FIELD("signature","uint8[2]",0,2,SX_SIGNATURE),
 SX_FIELD("unknown2","uint8[6]",2,6,SX_NONE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("unknown12","uint8[12]",12,12,SX_NONE),
};
static const sx_layout sxag_nowcompress_header = {UINT32_C(0x60250005),"nowcompress_header",sxag_nowcompress_header_fields,SX_COUNT(sxag_nowcompress_header_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[31]",1,31,SX_STRING),
 SX_FIELD("unknown32","uint8[4]",32,4,SX_NONE),
 SX_FIELD("flags","uint16",36,2,SX_FLAGS),
 SX_FIELD("finder_info","uint8[16]",38,16,SX_NONE),
 SX_FIELD("created","uint32",54,4,SX_NONE),
 SX_FIELD("modified","uint32",58,4,SX_NONE),
 SX_FIELD("accessed","uint32",62,4,SX_NONE),
 SX_FIELD("unknown66","uint8[16]",66,16,SX_NONE),
 SX_FIELD("child_count","uint16",82,2,SX_COUNT_PROP),
 SX_FIELD("unknown84","uint16",84,2,SX_NONE),
 SX_FIELD("data_size","uint32",86,4,SX_SIZE),
 SX_FIELD("resource_size","uint32",90,4,SX_SIZE),
 SX_FIELD("unknown94","uint32",94,4,SX_NONE),
 SX_FIELD("stream_start","uint32",98,4,SX_OFFSET),
 SX_FIELD("stream_end","uint32",102,4,SX_OFFSET),
 SX_FIELD("checksum","uint32",106,4,SX_CHECKSUM),
};
static const sx_layout sxag_nowcompress_entry = {UINT32_C(0x60250006),"nowcompress_entry",sxag_nowcompress_entry_fields,SX_COUNT(sxag_nowcompress_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_stream_fields[] = {
 SX_FIELD("first_data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxag_nowcompress_stream = {UINT32_C(0x60250007),"nowcompress_stream",sxag_nowcompress_stream_fields,SX_COUNT(sxag_nowcompress_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_block_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("padding_size","uint16",2,2,SX_SIZE),
 SX_FIELD("next_data_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxag_nowcompress_block = {UINT32_C(0x60250008),"nowcompress_block",sxag_nowcompress_block_fields,SX_COUNT(sxag_nowcompress_block_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_stream_end_fields[] = {
 SX_FIELD("unknown","uint32",0,4,SX_NONE),
 SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
};
static const sx_layout sxag_nowcompress_stream_end = {UINT32_C(0x60250009),"nowcompress_stream_end",sxag_nowcompress_stream_end_fields,SX_COUNT(sxag_nowcompress_stream_end_fields),SX_BE};
static const xx_data_struct_field_desc sxag_applelink_header_fields[] = {
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("source_filesystem","uint16",2,2,SX_ID),
 SX_FIELD("signature","char[5]",4,5,SX_SIGNATURE),
 SX_FIELD("version","uint8",9,1,SX_ID),
 SX_FIELD("member_header_size","uint16",10,2,SX_SIZE),
 SX_FIELD("reserved","uint8[7]",12,7,SX_RESERVED),
 SX_FIELD("producer","uint8",19,1,SX_NONE),
};
static const sx_layout sxag_applelink_header = {UINT32_C(0x6025000a),"applelink_header",sxag_applelink_header_fields,SX_COUNT(sxag_applelink_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_applelink_member_fields[] = {
 SX_FIELD("resource_method","uint8",0,1,SX_ID),
 SX_FIELD("data_method","uint8",1,1,SX_ID),
 SX_FIELD("resource_crc16","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("data_crc16","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("resource_storage_blocks","uint32",6,4,SX_COUNT_PROP),
 SX_FIELD("data_storage_blocks","uint32",10,4,SX_COUNT_PROP),
 SX_FIELD("resource_packed_size","uint32",14,4,SX_SIZE),
 SX_FIELD("data_packed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("access","uint16",22,2,SX_FLAGS),
 SX_FIELD("file_type","uint16",24,2,SX_ID),
 SX_FIELD("aux_type","uint32",26,4,SX_ID),
 SX_FIELD("reserved","uint16",30,2,SX_RESERVED),
 SX_FIELD("storage_type","uint16",32,2,SX_ID),
 SX_FIELD("resource_unpacked_size","uint32",34,4,SX_SIZE),
 SX_FIELD("data_unpacked_size","uint32",38,4,SX_SIZE),
 SX_FIELD("created_date","uint16",42,2,SX_NONE),
 SX_FIELD("created_time","uint16",44,2,SX_NONE),
 SX_FIELD("modified_date","uint16",46,2,SX_NONE),
 SX_FIELD("modified_time","uint16",48,2,SX_NONE),
 SX_FIELD("name_size","uint16",50,2,SX_SIZE),
 SX_FIELD("header_crc16","uint16",52,2,SX_CHECKSUM),
};
static const sx_layout sxag_applelink_member = {UINT32_C(0x6025000b),"applelink_member",sxag_applelink_member_fields,SX_COUNT(sxag_applelink_member_fields),SX_LE};
static const xx_data_struct_field_desc sxag_arc_cbm_member_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("method","uint8",1,1,SX_ID),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("unpacked_size","uint24",4,3,SX_SIZE),
 SX_FIELD("block_count","uint16",7,2,SX_COUNT_PROP),
 SX_FIELD("file_type","char[1]",9,1,SX_ID),
 SX_FIELD("name_size","uint8",10,1,SX_SIZE),
};
static const sx_layout sxag_arc_cbm_member = {UINT32_C(0x6025000c),"arc_cbm_member",sxag_arc_cbm_member_fields,SX_COUNT(sxag_arc_cbm_member_fields),SX_LE};
static const xx_data_struct_field_desc sxag_arc_cbm_v2_fields[] = {
 SX_FIELD("record_length","uint8",0,1,SX_SIZE),
 SX_FIELD("date","uint16",1,2,SX_NONE),
};
static const sx_layout sxag_arc_cbm_v2 = {UINT32_C(0x6025000d),"arc_cbm_v2",sxag_arc_cbm_v2_fields,SX_COUNT(sxag_arc_cbm_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxag_vmarc_member_fields[] = {
 SX_FIELD("signature","uint8[9]",0,9,SX_SIGNATURE),
 SX_FIELD("unknown9","uint8",9,1,SX_NONE),
 SX_FIELD("name_ebcdic","uint8[8]",10,8,SX_STRING),
 SX_FIELD("type_ebcdic","uint8[8]",18,8,SX_STRING),
 SX_FIELD("unknown26","uint16",26,2,SX_NONE),
 SX_FIELD("logical_record_size","uint16",28,2,SX_SIZE),
 SX_FIELD("unknown30","uint8[6]",30,6,SX_NONE),
 SX_FIELD("record_format","uint8",36,1,SX_ID),
 SX_FIELD("flags","uint8",37,1,SX_FLAGS),
};
static const sx_layout sxag_vmarc_member = {UINT32_C(0x6025000e),"vmarc_member",sxag_vmarc_member_fields,SX_COUNT(sxag_vmarc_member_fields),SX_BE};
static const xx_data_struct_field_desc sxag_vmarc_record_fields[] = {
 SX_FIELD("record_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxag_vmarc_record = {UINT32_C(0x6025000f),"vmarc_record",sxag_vmarc_record_fields,SX_COUNT(sxag_vmarc_record_fields),SX_BE};
static const xx_data_struct_field_desc sxag_ti99_tifiles_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("sector_count","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("records_per_sector","uint8",11,1,SX_COUNT_PROP),
 SX_FIELD("final_sector_bytes","uint8",12,1,SX_NONE),
 SX_FIELD("record_size","uint8",13,1,SX_SIZE),
};
static const sx_layout sxag_ti99_tifiles = {UINT32_C(0x60250010),"ti99_tifiles",sxag_ti99_tifiles_fields,SX_COUNT(sxag_ti99_tifiles_fields),SX_BE};
static const xx_data_struct_field_desc sxag_ti99_fiad_fields[] = {
 SX_FIELD("name","char[10]",0,10,SX_STRING),
 SX_FIELD("reserved","uint16",10,2,SX_RESERVED),
 SX_FIELD("flags","uint8",12,1,SX_FLAGS),
 SX_FIELD("records_per_sector","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("sector_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("final_sector_bytes","uint8",16,1,SX_NONE),
 SX_FIELD("record_size","uint8",17,1,SX_SIZE),
};
static const sx_layout sxag_ti99_fiad = {UINT32_C(0x60250011),"ti99_fiad",sxag_ti99_fiad_fields,SX_COUNT(sxag_ti99_fiad_fields),SX_BE};
static const xx_data_struct_field_desc sxag_ti99_record_count_fields[] = {
 SX_FIELD("record_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxag_ti99_record_count = {UINT32_C(0x60250012),"ti99_record_count",sxag_ti99_record_count_fields,SX_COUNT(sxag_ti99_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ti99_fiad_times_fields[] = {
 SX_FIELD("created","uint8[4]",0,4,SX_NONE),
 SX_FIELD("modified","uint8[4]",4,4,SX_NONE),
 SX_FIELD("reserved","uint8[100]",8,100,SX_RESERVED),
};
static const sx_layout sxag_ti99_fiad_times = {UINT32_C(0x60250013),"ti99_fiad_times",sxag_ti99_fiad_times_fields,SX_COUNT(sxag_ti99_fiad_times_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ti99_entry_fields[] = {
 SX_FIELD("name","char[10]",0,10,SX_STRING),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("records_per_sector","uint8",11,1,SX_COUNT_PROP),
 SX_FIELD("sector_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("final_sector_bytes","uint8",14,1,SX_NONE),
 SX_FIELD("record_size","uint8",15,1,SX_SIZE),
};
static const sx_layout sxag_ti99_entry = {UINT32_C(0x60250014),"ti99_entry",sxag_ti99_entry_fields,SX_COUNT(sxag_ti99_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxag_ti99_catalog_end_fields[] = {
 SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxag_ti99_catalog_end = {UINT32_C(0x60250015),"ti99_catalog_end",sxag_ti99_catalog_end_fields,SX_COUNT(sxag_ti99_catalog_end_fields),SX_LE};
static const xx_data_struct_field_desc sxag_zfsf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("constant8","uint32",8,4,SX_NONE),
 SX_FIELD("group_capacity","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("entry_count","int32",16,4,SX_COUNT_PROP),
 SX_FIELD("unknown20","uint32",20,4,SX_NONE),
 SX_FIELD("first_group_offset","uint32",24,4,SX_OFFSET),
};
static const sx_layout sxag_zfsf_header = {UINT32_C(0x60250016),"zfsf_header",sxag_zfsf_header_fields,SX_COUNT(sxag_zfsf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_zfsf_group_fields[] = {
 SX_FIELD("next_group_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxag_zfsf_group = {UINT32_C(0x60250017),"zfsf_group",sxag_zfsf_group_fields,SX_COUNT(sxag_zfsf_group_fields),SX_LE};
static const xx_data_struct_field_desc sxag_zfsf_entry_fields[] = {
 SX_FIELD("name","char[16]",0,16,SX_STRING),
 SX_FIELD("data_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("unknown20","uint32",20,4,SX_NONE),
 SX_FIELD("data_size","int32",24,4,SX_SIZE),
 SX_FIELD("unknown28","uint8[8]",28,8,SX_NONE),
};
static const sx_layout sxag_zfsf_entry = {UINT32_C(0x60250018),"zfsf_entry",sxag_zfsf_entry_fields,SX_COUNT(sxag_zfsf_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_trcpak_header_fields[] = {
 SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("padding","uint8",7,1,SX_RESERVED),
 SX_FIELD("version","float32",8,4,SX_NONE),
 SX_FIELD("entry_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[12]",16,12,SX_RESERVED),
};
static const sx_layout sxag_trcpak_header = {UINT32_C(0x60250019),"trcpak_header",sxag_trcpak_header_fields,SX_COUNT(sxag_trcpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_trcpak_entry_fields[] = {
 SX_FIELD("name","char[260]",0,260,SX_STRING),
 SX_FIELD("data_size","int32",260,4,SX_SIZE),
 SX_FIELD("data_offset","int32",264,4,SX_OFFSET),
};
static const sx_layout sxag_trcpak_entry = {UINT32_C(0x6025001a),"trcpak_entry",sxag_trcpak_entry_fields,SX_COUNT(sxag_trcpak_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_chieflz_header_fields[] = {
 SX_FIELD("signature","uint8[13]",0,13,SX_SIGNATURE),
 SX_FIELD("unknown13","uint8[6]",13,6,SX_NONE),
 SX_FIELD("unused19","uint32",19,4,SX_NONE),
 SX_FIELD("entry_count","uint32",23,4,SX_COUNT_PROP),
 SX_FIELD("unused27","uint32",27,4,SX_NONE),
 SX_FIELD("unused31","uint32",31,4,SX_NONE),
 SX_FIELD("names_size","uint32",35,4,SX_SIZE),
 SX_FIELD("unknown39","uint8[4]",39,4,SX_NONE),
};
static const sx_layout sxag_chieflz_header = {UINT32_C(0x6025001b),"chieflz_header",sxag_chieflz_header_fields,SX_COUNT(sxag_chieflz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_chieflz_entry_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("directory_parent","uint16",1,2,SX_ID),
 SX_FIELD("file_parent","uint16",3,2,SX_ID),
 SX_FIELD("unknown5","uint8[10]",5,10,SX_NONE),
 SX_FIELD("packed_size","uint32",15,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",19,4,SX_SIZE),
 SX_FIELD("time","uint16",23,2,SX_NONE),
 SX_FIELD("date","uint16",25,2,SX_NONE),
 SX_FIELD("attributes","uint32",27,4,SX_FLAGS),
 SX_FIELD("complemented_crc32","uint32",31,4,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",35,1,SX_SIZE),
 SX_FIELD("unknown36","uint8[4]",36,4,SX_NONE),
 SX_FIELD("method","uint8",40,1,SX_ID),
};
static const sx_layout sxag_chieflz_entry = {UINT32_C(0x6025001c),"chieflz_entry",sxag_chieflz_entry_fields,SX_COUNT(sxag_chieflz_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ibmzpak_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("reserved","uint8",5,1,SX_RESERVED),
 SX_FIELD("version","uint16",6,2,SX_ID),
};
static const sx_layout sxag_ibmzpak_header = {UINT32_C(0x6025001d),"ibmzpak_header",sxag_ibmzpak_header_fields,SX_COUNT(sxag_ibmzpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ibmzpak_entry_fields[] = {
 SX_FIELD("name","char[80]",0,80,SX_STRING),
 SX_FIELD("packed_size","uint32",80,4,SX_SIZE),
 SX_FIELD("date","uint16",84,2,SX_NONE),
 SX_FIELD("time","uint16",86,2,SX_NONE),
};
static const sx_layout sxag_ibmzpak_entry = {UINT32_C(0x6025001e),"ibmzpak_entry",sxag_ibmzpak_entry_fields,SX_COUNT(sxag_ibmzpak_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ibmzpak_count_fields[] = {
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxag_ibmzpak_count = {UINT32_C(0x6025001f),"ibmzpak_count",sxag_ibmzpak_count_fields,SX_COUNT(sxag_ibmzpak_count_fields),SX_LE};
static const xx_data_struct_field_desc sxag_archivelegacy_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_ID),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxag_archivelegacy_dcl = {UINT32_C(0x60250020),"archivelegacy_dcl",sxag_archivelegacy_dcl_fields,SX_COUNT(sxag_archivelegacy_dcl_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ascend_header_fields[] = {
 SX_FIELD("year","uint16",0,2,SX_NONE),
 SX_FIELD("month","uint16",2,2,SX_NONE),
 SX_FIELD("day","uint16",4,2,SX_NONE),
 SX_FIELD("hour","uint16",6,2,SX_NONE),
 SX_FIELD("minute","uint16",8,2,SX_NONE),
 SX_FIELD("second","uint16",10,2,SX_NONE),
};
static const sx_layout sxag_ascend_header = {UINT32_C(0x60250021),"ascend_header",sxag_ascend_header_fields,SX_COUNT(sxag_ascend_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("directory_unpacked_size","int32",8,4,SX_SIZE),
};
static const sx_layout sxag_cfl_header = {UINT32_C(0x60250022),"cfl_header",sxag_cfl_header_fields,SX_COUNT(sxag_cfl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_directory_block_fields[] = {
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("packed_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxag_cfl_directory_block = {UINT32_C(0x60250023),"cfl_directory_block",sxag_cfl_directory_block_fields,SX_COUNT(sxag_cfl_directory_block_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_directory_size_fields[] = {
 SX_FIELD("unpacked_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxag_cfl_directory_size = {UINT32_C(0x60250024),"cfl_directory_size",sxag_cfl_directory_size_fields,SX_COUNT(sxag_cfl_directory_size_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_entry_fields[] = {
 SX_FIELD("unpacked_size","int32",0,4,SX_SIZE),
 SX_FIELD("data_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("method","uint16",8,2,SX_ID),
 SX_FIELD("unused","uint16",10,2,SX_NONE),
 SX_FIELD("name_size","uint16",12,2,SX_SIZE),
};
static const sx_layout sxag_cfl_entry = {UINT32_C(0x60250025),"cfl_entry",sxag_cfl_entry_fields,SX_COUNT(sxag_cfl_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_cfl_member_block_fields[] = {
 SX_FIELD("block_size","int32",0,4,SX_SIZE),
 SX_FIELD("unpacked_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxag_cfl_member_block = {UINT32_C(0x60250026),"cfl_member_block",sxag_cfl_member_block_fields,SX_COUNT(sxag_cfl_member_block_fields),SX_LE};
static const xx_data_struct_field_desc sxag_dpk_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("archive_size","int32",4,4,SX_SIZE),
 SX_FIELD("directory_size","int32",8,4,SX_SIZE),
 SX_FIELD("entry_count","int32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxag_dpk_header = {UINT32_C(0x60250027),"dpk_header",sxag_dpk_header_fields,SX_COUNT(sxag_dpk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_dpk_entry_fields[] = {
 SX_FIELD("record_size","int32",0,4,SX_SIZE),
 SX_FIELD("unpacked_size","int32",4,4,SX_SIZE),
 SX_FIELD("packed_size","int32",8,4,SX_SIZE),
 SX_FIELD("data_offset","int32",12,4,SX_OFFSET),
};
static const sx_layout sxag_dpk_entry = {UINT32_C(0x60250028),"dpk_entry",sxag_dpk_entry_fields,SX_COUNT(sxag_dpk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_swagpacket_header_fields[] = {
 SX_FIELD("banner","char[48]",0,48,SX_SIGNATURE),
 SX_FIELD("separator","char[1]",48,1,SX_RESERVED),
 SX_FIELD("entry_count","ascii_decimal[5]",49,5,SX_COUNT_PROP),
 SX_FIELD("padding","char[9]",54,9,SX_RESERVED),
 SX_FIELD("title","char[65]",63,65,SX_STRING),
};
static const sx_layout sxag_swagpacket_header = {UINT32_C(0x60250029),"swagpacket_header",sxag_swagpacket_header_fields,SX_COUNT(sxag_swagpacket_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_swagpacket_entry_fields[] = {
 SX_FIELD("entry_index","ascii_decimal[8]",0,8,SX_ID),
 SX_FIELD("date","char[8]",8,8,SX_NONE),
 SX_FIELD("time","char[5]",16,5,SX_NONE),
 SX_FIELD("author","char[25]",21,25,SX_STRING),
 SX_FIELD("contributor","char[25]",46,25,SX_STRING),
 SX_FIELD("subject","char[25]",71,25,SX_STRING),
 SX_FIELD("keywords","char[20]",96,20,SX_STRING),
 SX_FIELD("block_count","ascii_decimal[7]",116,7,SX_COUNT_PROP),
 SX_FIELD("unknown123","uint8[4]",123,4,SX_NONE),
 SX_FIELD("separator","char[1]",127,1,SX_RESERVED),
};
static const sx_layout sxag_swagpacket_entry = {UINT32_C(0x6025002a),"swagpacket_entry",sxag_swagpacket_entry_fields,SX_COUNT(sxag_swagpacket_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_marc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("entry_count","int32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxag_marc_header = {UINT32_C(0x6025002b),"marc_header",sxag_marc_header_fields,SX_COUNT(sxag_marc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_marc_entry_fields[] = {
 SX_FIELD("name","char[56]",0,56,SX_STRING),
 SX_FIELD("data_size","int32",56,4,SX_SIZE),
 SX_FIELD("unknown60","uint32",60,4,SX_NONE),
 SX_FIELD("data_offset","int32",64,4,SX_OFFSET),
};
static const sx_layout sxag_marc_entry = {UINT32_C(0x6025002c),"marc_entry",sxag_marc_entry_fields,SX_COUNT(sxag_marc_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_hlb_header_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxag_hlb_header = {UINT32_C(0x6025002d),"hlb_header",sxag_hlb_header_fields,SX_COUNT(sxag_hlb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_hlb_entry_fields[] = {
 SX_FIELD("data_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("name","char[14]",4,14,SX_STRING),
};
static const sx_layout sxag_hlb_entry = {UINT32_C(0x6025002e),"hlb_entry",sxag_hlb_entry_fields,SX_COUNT(sxag_hlb_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_hlb_footer_fields[] = {
 SX_FIELD("directory_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxag_hlb_footer = {UINT32_C(0x6025002f),"hlb_footer",sxag_hlb_footer_fields,SX_COUNT(sxag_hlb_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_header_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
};
static const sx_layout sxag_jam_header = {UINT32_C(0x60250030),"jam_header",sxag_jam_header_fields,SX_COUNT(sxag_jam_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_file_count_fields[] = {
 SX_FIELD("file_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxag_jam_file_count = {UINT32_C(0x60250031),"jam_file_count",sxag_jam_file_count_fields,SX_COUNT(sxag_jam_file_count_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_directory_count_fields[] = {
 SX_FIELD("directory_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxag_jam_directory_count = {UINT32_C(0x60250032),"jam_directory_count",sxag_jam_directory_count_fields,SX_COUNT(sxag_jam_directory_count_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_file_fields[] = {
 SX_FIELD("name","char[15]",0,15,SX_STRING),
 SX_FIELD("data_offset","int32",15,4,SX_OFFSET),
 SX_FIELD("data_size","int32",19,4,SX_SIZE),
};
static const sx_layout sxag_jam_file = {UINT32_C(0x60250033),"jam_file",sxag_jam_file_fields,SX_COUNT(sxag_jam_file_fields),SX_LE};
static const xx_data_struct_field_desc sxag_jam_directory_fields[] = {
 SX_FIELD("name","char[15]",0,15,SX_STRING),
 SX_FIELD("node_offset","int32",15,4,SX_OFFSET),
};
static const sx_layout sxag_jam_directory = {UINT32_C(0x60250034),"jam_directory",sxag_jam_directory_fields,SX_COUNT(sxag_jam_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxag_tws_header_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_STRING),
 SX_FIELD("constant13","uint16",13,2,SX_NONE),
 SX_FIELD("zero15","uint16",15,2,SX_RESERVED),
 SX_FIELD("entry_count_minus1","int32",17,4,SX_NONE),
 SX_FIELD("payload_size","int32",21,4,SX_SIZE),
};
static const sx_layout sxag_tws_header = {UINT32_C(0x60250035),"tws_header",sxag_tws_header_fields,SX_COUNT(sxag_tws_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_tws_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_STRING),
 SX_FIELD("time","uint16",13,2,SX_NONE),
 SX_FIELD("date","uint16",15,2,SX_NONE),
 SX_FIELD("data_offset","int32",17,4,SX_OFFSET),
 SX_FIELD("data_size","int32",21,4,SX_SIZE),
};
static const sx_layout sxag_tws_entry = {UINT32_C(0x60250036),"tws_entry",sxag_tws_entry_fields,SX_COUNT(sxag_tws_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_fiz_member_fields[] = {
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("method","uint8",4,1,SX_ID),
 SX_FIELD("name_size","uint8",5,1,SX_SIZE),
 SX_FIELD("crc16","uint16",6,2,SX_CHECKSUM),
 SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("time","uint16",16,2,SX_NONE),
 SX_FIELD("date","uint16",18,2,SX_NONE),
};
static const sx_layout sxag_fiz_member = {UINT32_C(0x60250037),"fiz_member",sxag_fiz_member_fields,SX_COUNT(sxag_fiz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ealib_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("entry_count","uint16",5,2,SX_COUNT_PROP),
};
static const sx_layout sxag_ealib_header = {UINT32_C(0x60250038),"ealib_header",sxag_ealib_header_fields,SX_COUNT(sxag_ealib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ealib_entry_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_STRING),
 SX_FIELD("method","uint8",13,1,SX_ID),
 SX_FIELD("data_offset","int32",14,4,SX_OFFSET),
};
static const sx_layout sxag_ealib_entry = {UINT32_C(0x60250039),"ealib_entry",sxag_ealib_entry_fields,SX_COUNT(sxag_ealib_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ealib_packed_size_fields[] = {
 SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxag_ealib_packed_size = {UINT32_C(0x6025003a),"ealib_packed_size",sxag_ealib_packed_size_fields,SX_COUNT(sxag_ealib_packed_size_fields),SX_LE};
static const sx_layout *const sx_archivelegacy_layouts[] = {
 &sxag_amplus_header,
 &sxag_amplus_chunk,
 &sxag_amplus_data,
 &sxag_amplus_file,
 &sxag_nowcompress_header,
 &sxag_nowcompress_entry,
 &sxag_nowcompress_stream,
 &sxag_nowcompress_block,
 &sxag_nowcompress_stream_end,
 &sxag_applelink_header,
 &sxag_applelink_member,
 &sxag_arc_cbm_member,
 &sxag_arc_cbm_v2,
 &sxag_vmarc_member,
 &sxag_vmarc_record,
 &sxag_ti99_tifiles,
 &sxag_ti99_fiad,
 &sxag_ti99_record_count,
 &sxag_ti99_fiad_times,
 &sxag_ti99_entry,
 &sxag_ti99_catalog_end,
 &sxag_zfsf_header,
 &sxag_zfsf_group,
 &sxag_zfsf_entry,
 &sxag_trcpak_header,
 &sxag_trcpak_entry,
 &sxag_chieflz_header,
 &sxag_chieflz_entry,
 &sxag_ibmzpak_header,
 &sxag_ibmzpak_entry,
 &sxag_ibmzpak_count,
 &sxag_archivelegacy_dcl,
 &sxag_ascend_header,
 &sxag_cfl_header,
 &sxag_cfl_directory_block,
 &sxag_cfl_directory_size,
 &sxag_cfl_entry,
 &sxag_cfl_member_block,
 &sxag_dpk_header,
 &sxag_dpk_entry,
 &sxag_swagpacket_header,
 &sxag_swagpacket_entry,
 &sxag_marc_header,
 &sxag_marc_entry,
 &sxag_hlb_header,
 &sxag_hlb_entry,
 &sxag_hlb_footer,
 &sxag_jam_header,
 &sxag_jam_file_count,
 &sxag_jam_directory_count,
 &sxag_jam_file,
 &sxag_jam_directory,
 &sxag_tws_header,
 &sxag_tws_entry,
 &sxag_fiz_member,
 &sxag_ealib_header,
 &sxag_ealib_entry,
 &sxag_ealib_packed_size,
};
static bool sx_archivelegacy_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x60250000U||id>=0x60260000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x60250001U:
 if(!xx_rt_wcscmp(r->name,L"form_size"))text=L"Byte count following this field, including the APUP form type.";
 break;
 case 0x60250003U:
 if(!xx_rt_wcscmp(r->name,L"compression"))text=L"PACK: 0=AMPK codec, other values denote unsupported XPK variants. DATA is stored.";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of decoded bytes packed into big-endian 32-bit words, with zero tail padding.";
 break;
 case 0x60250004U:
 if(!xx_rt_wcscmp(r->name,L"body_size"))text=L"FILE chunk body byte count includes its nested NAME chunk.";
 if(!xx_rt_wcscmp(r->name,L"days"))text=L"Amiga DateStamp days since 1978-01-01.";
 if(!xx_rt_wcscmp(r->name,L"minutes"))text=L"Amiga DateStamp minutes since midnight.";
 if(!xx_rt_wcscmp(r->name,L"ticks"))text=L"Amiga DateStamp ticks within the minute, 50 ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"protection"))text=L"Complete Amiga protection flag bit word.";
 break;
 case 0x60250006U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 4 marks a directory.";
 if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"accessed"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of the first 106 entry bytes.";
 break;
 case 0x60250008U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 5=Huffman, low 5 bits=old LZ, bit 6=new LZ; zero means stored. Equal consecutive offsets reset history.";
 if(!xx_rt_wcscmp(r->name,L"padding_size"))text=L"Padding after the block and its four-byte opaque trailer.";
 break;
 case 0x60250009U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of the stream-table bytes preceding this checksum.";
 break;
 case 0x6025000bU:
 if(!xx_rt_wcscmp(r->name,L"resource_method"))text=L"0=stored, 3=Squeeze.";
 if(!xx_rt_wcscmp(r->name,L"data_method"))text=L"0=stored, 3=Squeeze.";
 if(!xx_rt_wcscmp(r->name,L"resource_storage_blocks"))text=L"ProDOS storage allocation in 512-byte blocks; not a byte length.";
 if(!xx_rt_wcscmp(r->name,L"data_storage_blocks"))text=L"ProDOS storage allocation in 512-byte blocks; not a byte length.";
 if(!xx_rt_wcscmp(r->name,L"storage_type"))text=L"13=directory.";
 if(!xx_rt_wcscmp(r->name,L"created_date"))text=L"Packed ProDOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"created_time"))text=L"Packed ProDOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"modified_date"))text=L"Packed ProDOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"modified_time"))text=L"Packed ProDOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"header_crc16"))text=L"CRC16/XMODEM over the first 52 fixed-header bytes and the variable name.";
 break;
 case 0x6025000cU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Version 1: byte sum. Version 2: sum of each byte XOR its one-based byte index modulo 256.";
 if(!xx_rt_wcscmp(r->name,L"block_count"))text=L"Physical member span in 254-byte Commodore blocks.";
 break;
 case 0x6025000dU:
 if(!xx_rt_wcscmp(r->name,L"record_length"))text=L"Record byte length for Commodore relative files.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x6025000eU:
 if(!xx_rt_wcscmp(r->name,L"name_ebcdic"))text=L"Blank-padded EBCDIC CP037 filename; original encoded bytes are retained.";
 if(!xx_rt_wcscmp(r->name,L"type_ebcdic"))text=L"Blank-padded EBCDIC CP037 CMS file type.";
 if(!xx_rt_wcscmp(r->name,L"record_format"))text=L"EBCDIC F (0xC6)=fixed, V (0xE5)=variable.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=12-byte extension; bit 6=stored; bit 7=other codec when not stored.";
 break;
 case 0x6025000fU:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Stored-record byte count; zero terminates the member.";
 break;
 case 0x60250010U:
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Number of 256-byte sectors.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Native ARK wrapper: bit 1 selects LZW-compressed archive data.";
 if(!xx_rt_wcscmp(r->name,L"final_sector_bytes"))text=L"Bytes used in the final sector; zero denotes a full sector.";
 break;
 case 0x60250011U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Native ARK wrapper: bit 1 selects LZW-compressed archive data.";
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Number of 256-byte sectors.";
 if(!xx_rt_wcscmp(r->name,L"final_sector_bytes"))text=L"Bytes used in the final sector; zero denotes a full sector.";
 break;
 case 0x60250013U:
 if(!xx_rt_wcscmp(r->name,L"created"))text=L"Encoded TI file date/time, retained in physical byte order.";
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Encoded TI file date/time, retained in physical byte order.";
 break;
 case 0x60250014U:
 if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Number of 256-byte payload sectors.";
 if(!xx_rt_wcscmp(r->name,L"final_sector_bytes"))text=L"Bytes used in the final sector; zero denotes a full sector.";
 break;
 case 0x60250015U:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"END! marks the last catalog sector; zero continues the catalog.";
 break;
 case 0x6025001cU:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=directory; other values use file_parent.";
 if(!xx_rt_wcscmp(r->name,L"directory_parent"))text=L"One-based parent entry index for directories, zero denotes root.";
 if(!xx_rt_wcscmp(r->name,L"file_parent"))text=L"One-based parent entry index for files, zero denotes root.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"complemented_crc32"))text=L"Bitwise complement of the uncompressed-data CRC32.";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Encoded name bytes in the following name pool: byte i is stored as character+i+4.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"2=stored, 3=unsupported method, 4=ChiefLZ.";
 break;
 case 0x6025001eU:
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60250020U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0=literal bytes, 1=Huffman-coded literals.";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"Extra distance bits: 4, 5, or 6; dictionary size is 1 << (6+this value) bytes.";
 break;
 case 0x60250023U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored directory, 1=zlib directory without Adler32 trailer.";
 break;
 case 0x60250025U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored, 1=zlib stream in a physical member block.";
 break;
 case 0x60250026U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Byte count following this field, including the uncompressed-size word.";
 break;
 case 0x60250028U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Complete directory record size, including variable NUL-padded name.";
 break;
 case 0x6025002aU:
 if(!xx_rt_wcscmp(r->name,L"entry_index"))text=L"One-based member ordinal.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"ASCII MM-DD-YY.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"ASCII HH:MM.";
 if(!xx_rt_wcscmp(r->name,L"block_count"))text=L"Total 128-byte member blocks, including this header block.";
 break;
 case 0x60250035U:
 if(!xx_rt_wcscmp(r->name,L"entry_count_minus1"))text=L"Member count is this encoded value plus one.";
 break;
 case 0x60250036U:
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60250037U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored, 1=LH5.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60250039U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 or 3=stored, 1=LZSS, 4=PKWARE DCL; the last directory entry is the end sentinel.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to this EALIB container; the sentinel bounds its payload.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAG_LIMIT 20000U
static bool sxag_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxag_read(sx_context *c,uint64_t p,void *b,size_t n){return sxag_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxag_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint16_t sxag16(const uint8_t *b,bool be){return (uint16_t)sxag_uint(b,2,be);}
static uint32_t sxag32(const uint8_t *b,bool be){return (uint32_t)sxag_uint(b,4,be);}
/* Native readers can authenticate aliases and damaged optional records. Keep
 * earlier bounded physical metadata, and leave conflicting later interpretations
 * opaque instead of discarding the entire useful header view. */
static bool sxag_free(sx_context *c,uint64_t p,uint64_t n){for(size_t i=0;i<c->count;i++){uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<at+z&&at<p+n)return false;}return true;}
static bool sxag_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(!sxag_span(c,p,n))return false;if(!sxag_free(c,p,n))return true;return c->count>=SXAG_LIMIT||sx_add(c,l,(int64_t)p,(int64_t)n);}
static bool sxag_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n||n>SXAG_LIMIT||!sxag_span(c,p,n*z))return false;if(!sxag_free(c,p,n*z))return true;return c->count>=SXAG_LIMIT||sx_table(c,l,(int64_t)p,(int64_t)z,n);}
static bool sxag_amplus(sx_context *c){uint8_t b[36];if(!sxag_read(c,0,b,12)||!sxag_add(c,&sxag_amplus_header,0))return false;uint64_t p=12;for(unsigned i=0;i<SXAG_LIMIT&&p<(uint64_t)c->size;i++){if(!sxag_read(c,p,b,8))break;uint64_t n=sxag32(b+4,true),end=p+8+n,at=p+8;if(!sxag_span(c,at,n))break;if(!sxag_add(c,&sxag_amplus_chunk,p))return false;
 bool help=!xx_rt_memcmp(b,"HELP",4),data=!xx_rt_memcmp(b,"DATA",4)||!xx_rt_memcmp(b,"PACK",4);if(help||data){if(data){if(end-at<10||!sxag_add(c,&sxag_amplus_data,at))break;at+=10;}if(end-at<36||!sxag_read(c,at,b,36)||xx_rt_memcmp(b,"FILE",4)||xx_rt_memcmp(b+28,"NAME",4))break;if(!sxag_add(c,&sxag_amplus_file,at)||!sxag_add(c,&sxag_amplus_chunk,at+28))return false;uint64_t names=sxag32(b+32,true);at+=36;if(names>end-at)break;at+=names;if(end-at<8||!sxag_read(c,at,b,8)||sxag32(b+4,true)>end-at-8)break;if(!sxag_add(c,&sxag_amplus_chunk,at))return false;}p=end+(n&1);}
 return true;}
static bool sxag_now(sx_context *c){uint8_t b[110];if(!sxag_read(c,0,b,24)||!sxag_add(c,&sxag_nowcompress_header,0))return false;uint64_t n=sxag32(b+8,true);if(!n||n>SXAG_LIMIT||!sxag_span(c,24,n*110))return true;if(!sxag_table(c,&sxag_nowcompress_entry,24,n))return false;uint64_t directory_end=24+n*110;
 for(uint64_t i=0;i<n&&c->count<SXAG_LIMIT;i++){if(!sxag_read(c,24+i*110,b,110))break;if((sxag16(b+36,true)&16)||(!sxag32(b+86,true)&&!sxag32(b+90,true)))continue;uint64_t start=sxag32(b+98,true),end=sxag32(b+102,true);if(start<directory_end||end<=start||!sxag_span(c,start,end-start)||!sxag_read(c,start,b,4))continue;uint64_t first=sxag32(b,true);if(first<start+20||first>end||(first-start-4)%8)continue;uint64_t blocks=(first-start-4)/8-1;if(!blocks||blocks>8191||!sxag_free(c,start,first-start))continue;if(!sxag_add(c,&sxag_nowcompress_stream,start)||!sxag_table(c,&sxag_nowcompress_block,start+4,blocks)||!sxag_add(c,&sxag_nowcompress_stream_end,first-8))return false;}
 return true;}
static bool sxag_applelink(sx_context *c){uint8_t b[54];if(!sxag_read(c,0,b,20)||!sxag_add(c,&sxag_applelink_header,0))return false;unsigned count=sxag16(b,false);uint64_t p=20;for(unsigned i=0;i<count&&i<SXAG_LIMIT;i++){if(!sxag_read(c,p,b,54))break;uint64_t name=sxag16(b+50,false),data=(uint64_t)sxag32(b+14,false)+sxag32(b+18,false);if(!sxag_span(c,p+54,name))break;if(!sxag_add(c,&sxag_applelink_member,p))return false;p+=54+name;if(!sxag_span(c,p,data))break;p+=data;}return true;}
static bool sxag_cbm(sx_context *c){uint8_t b[20];uint64_t p=0;if(!sxag_read(c,0,b,11))return false;if((uint64_t)c->size>265&&b[6]==0x9e&&b[7]=='('){unsigned line=sxag16(b+4,false);if(line<7||line>4096)return false;p=(uint64_t)(line-6)*254;if(line==15&&b[8]=='7')p--;}
 for(unsigned i=0;i<SXAG_LIMIT&&p<(uint64_t)c->size;i++){if(!sxag_read(c,p,b,11)||(b[0]!=1&&b[0]!=2))break;unsigned version=b[0],name=b[10];uint64_t n=(uint64_t)sxag16(b+7,false)*254,h=11+name+(version==2?3:0);if(!name||name>16||n<h||!sxag_span(c,p,n))break;if(!sxag_add(c,&sxag_arc_cbm_member,p))return false;if(version==2&&!sxag_add(c,&sxag_arc_cbm_v2,p+11+name))return false;p+=n;}
 return c->count!=0;}
static bool sxag_vmarc_stored(sx_context *c,uint64_t p,uint64_t end){uint8_t b[2];for(unsigned i=0;i<SXAG_LIMIT&&p+2<=end;i++){if(!sxag_read(c,p,b,2))break;unsigned n=sxag16(b,true);if(n>end-p-2)break;if(!sxag_add(c,&sxag_vmarc_record,p))return false;p+=2+n;if(!n)break;}return true;}
static bool sxag_vmarc(sx_context *c){if(!sxag_add(c,&sxag_vmarc_member,0))return false;if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;xx_archive_record_state *s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;
 for(unsigned i=0;i<1024;i++){const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>=c->f->base_address&&r->data_offset>=r->header_offset&&r->compressed_size>=0){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address),data=(uint64_t)(r->data_offset-c->f->base_address),n=(uint64_t)r->compressed_size;uint8_t b[38];if(sxag_read(c,p,b,38)&&sxag_span(c,data,n)){if(!sxag_add(c,&sxag_vmarc_member,p)||((b[37]&64)&&!sxag_vmarc_stored(c,data,data+n))){ok=false;break;}}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static bool sxag_ti99(sx_context *c){uint8_t b[128];uint64_t p=0;bool compressed=false;if(!sxag_read(c,0,b,128))return false;
 if(!xx_rt_memcmp(b,"\7TIFILES",8)){if(!sxag_add(c,&sxag_ti99_tifiles,0)||!sxag_add(c,&sxag_ti99_record_count,14))return false;compressed=(b[10]&2)!=0;p=128;}
 else{bool fiad=b[10]==0&&b[11]==0&&sxag16(b+14,true)!=0;for(unsigned i=28;i<128&&fiad;i++)if(b[i])fiad=false;uint64_t size=(uint64_t)sxag16(b+14,true)*256+128;if(fiad&&size==(uint64_t)c->size){if(!sxag_add(c,&sxag_ti99_fiad,0)||!sxag_add(c,&sxag_ti99_record_count,18)||!sxag_add(c,&sxag_ti99_fiad_times,20))return false;compressed=(b[12]&2)!=0;p=128;}}
 if(compressed)return true;for(unsigned sector=0;sector<1024&&sxag_span(c,p,256);sector++,p+=256){for(unsigned i=0;i<14;i++){uint8_t e[18];uint64_t at=p+i*18;if(!sxag_read(c,at,e,18))return false;bool empty=true;for(unsigned j=0;j<18;j++)if(e[j])empty=false;if(empty)continue;if(!sxag_add(c,&sxag_ti99_entry,at)||!sxag_add(c,&sxag_ti99_record_count,at+16))return false;}if(!sxag_read(c,p+252,b,4)||!sxag_add(c,&sxag_ti99_catalog_end,p+252))return false;if(!xx_rt_memcmp(b,"END!",4))break;if(sxag32(b,false))break;}return c->count!=0;}
static bool sxag_zfsf(sx_context *c){uint8_t b[28];if(!sxag_read(c,0,b,28)||!sxag_add(c,&sxag_zfsf_header,0))return false;uint64_t cap=sxag32(b+12,false),left=sxag32(b+16,false),p=sxag32(b+24,false);if(!cap||cap>INT32_MAX||left>INT32_MAX)return true;
 for(unsigned i=0;left&&i<1024;i++){uint64_t n=left<cap?left:cap;if(p<28||n>SXAG_LIMIT||!sxag_span(c,p,4+n*36)||!sxag_free(c,p,4+n*36)||!sxag_read(c,p,b,4))break;uint64_t next=sxag32(b,false);if(!sxag_add(c,&sxag_zfsf_group,p)||!sxag_table(c,&sxag_zfsf_entry,p+4,n))return false;left-=n;p=next;}return true;}
static bool sxag_fixed(sx_context *c,const sx_layout *header,const sx_layout *entry,unsigned h,unsigned field,unsigned width,bool be,uint64_t p,int extra){uint8_t b[32];if(h>sizeof(b)||!sxag_read(c,0,b,h)||!sxag_add(c,header,0))return false;uint64_t n=sxag_uint(b+field,width,be);if(n>INT32_MAX||n>SXAG_LIMIT)return true;n+=(unsigned)extra;if(!n||n>SXAG_LIMIT)return true;uint64_t z=(uint64_t)(entry->fields[entry->field_count-1].rel_offset+entry->fields[entry->field_count-1].size);if(!sxag_span(c,p,n*z))return true;return sxag_table(c,entry,p,n);}
static bool sxag_chief(sx_context *c){uint8_t b[43];if(!sxag_read(c,0,b,43)||!sxag_add(c,&sxag_chieflz_header,0))return false;uint64_t n=sxag32(b+23,false);if(!n||n>SXAG_LIMIT||!sxag_span(c,126,n*41))return true;return sxag_table(c,&sxag_chieflz_entry,126,n);}
static bool sxag_ibm(sx_context *c){uint8_t b[88];if(!sxag_add(c,&sxag_ibmzpak_header,0)||(uint64_t)c->size<10||!sxag_read(c,(uint64_t)c->size-2,b,2))return false;uint64_t n=sxag16(b,false);if(!n||n>SXAG_LIMIT||n*88>(uint64_t)c->size-10)return true;uint64_t table=(uint64_t)c->size-2-n*88,p=8;if(!sxag_table(c,&sxag_ibmzpak_entry,table,n)||!sxag_add(c,&sxag_ibmzpak_count,(uint64_t)c->size-2))return false;for(uint64_t i=0;i<n;i++){if(!sxag_read(c,table+i*88,b,88))break;uint64_t z=sxag32(b+80,false);if(z<2||p>table||z>table-p)break;if(!sxag_add(c,&sxag_archivelegacy_dcl,p))return false;p+=z;}return true;}
static bool sxag_cfl_member_blocks(sx_context *c){if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;xx_archive_record_state *s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;
 for(unsigned i=0;i<1024;i++){const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(xx_archive_record_get_meta_u64(r,XX_META_ID_COMPRESSION_METHOD,UINT64_MAX)==1&&r->data_offset>=c->f->base_address&&r->data_offset-c->f->base_address>=10){uint64_t p=(uint64_t)(r->data_offset-c->f->base_address)-10;uint8_t b[8];if(sxag_read(c,p,b,8)&&!sxag_add(c,&sxag_cfl_member_block,p)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static bool sxag_cfl(sx_context *c){uint8_t b[14];if(!sxag_read(c,0,b,12)||!sxag_add(c,&sxag_cfl_header,0))return false;uint64_t p=sxag32(b+4,false);if(p<12||!sxag_read(c,p,b,8))return true;uint64_t method=sxag32(b,false),n=sxag32(b+4,false);if(method>1||n>INT32_MAX||!sxag_span(c,p+8,n))return true;if(!sxag_add(c,&sxag_cfl_directory_block,p))return false;p+=8;
 if(method){if(n>=4&&!sxag_add(c,&sxag_cfl_directory_size,p))return false;return sxag_cfl_member_blocks(c);}uint64_t end=p+n;for(unsigned i=0;i<SXAG_LIMIT&&end-p>=14;i++){if(!sxag_read(c,p,b,14))break;uint64_t z=sxag16(b+12,false),data=sxag32(b+4,false),plain=sxag32(b,false);if(!z||z>end-p-14||data<12||data>INT32_MAX||plain>INT32_MAX)break;if(!sxag_add(c,&sxag_cfl_entry,p))return false;p+=14+z;}return sxag_cfl_member_blocks(c);}
static bool sxag_dpk(sx_context *c){uint8_t b[16];if(!sxag_read(c,0,b,16)||!sxag_add(c,&sxag_dpk_header,0))return false;uint64_t n=sxag32(b+12,false),z=sxag32(b+8,false),p=16;if(n>SXAG_LIMIT||!sxag_span(c,p,z))return true;uint64_t end=p+z;for(uint64_t i=0;i<n&&end-p>=16;i++){if(!sxag_read(c,p,b,16))break;uint64_t h=sxag32(b,false);if(h<17||h>end-p)break;if(!sxag_add(c,&sxag_dpk_entry,p))return false;p+=h;}return true;}
static bool sxag_decimal(const uint8_t *b,unsigned n,uint64_t *v){uint64_t a=0;bool seen=false,tail=false;for(unsigned i=0;i<n;i++){if(b[i]==' '){if(seen)tail=true;continue;}if(tail||b[i]<'0'||b[i]>'9'||a>(UINT64_MAX-(b[i]-'0'))/10)return false;a=a*10+b[i]-'0';seen=true;}*v=a;return seen;}
static bool sxag_swag(sx_context *c){uint8_t b[128];if(!sxag_read(c,0,b,128)||!sxag_add(c,&sxag_swagpacket_header,0))return false;uint64_t n=0,p=128;if(!sxag_decimal(b+49,5,&n)||n>SXAG_LIMIT)return true;for(uint64_t i=0;i<n;i++){uint64_t blocks;if(!sxag_read(c,p,b,128)||!sxag_decimal(b+116,7,&blocks)||blocks<2||blocks>UINT64_MAX/128||!sxag_span(c,p,blocks*128))break;if(!sxag_add(c,&sxag_swagpacket_entry,p))return false;p+=blocks*128;}return true;}
static bool sxag_hlb(sx_context *c){uint8_t b[8];if(!sxag_read(c,0,b,8)||!sxag_add(c,&sxag_hlb_header,0))return false;uint64_t n=sxag16(b+2,false),p=sxag32(b+4,false);if(!n||n>SXAG_LIMIT||p<8||!sxag_span(c,p,n*18+4))return true;return sxag_table(c,&sxag_hlb_entry,p,n)&&sxag_add(c,&sxag_hlb_footer,p+n*18);}
static bool sxag_jam(sx_context *c){uint8_t b[23];if(!sxag_add(c,&sxag_jam_header,0))return false;uint64_t *queue=xx_mem_alloc(4096*sizeof(*queue));if(!queue)return false;size_t head=0,tail=1;queue[0]=3;bool ok=true;
 while(head<tail&&c->count<SXAG_LIMIT){uint64_t p=queue[head++];if(!sxag_read(c,p,b,4)||!sxag_free(c,p,4))continue;uint64_t n=sxag32(b,false);if(n>SXAG_LIMIT||!sxag_span(c,p+4,n*23+4))continue;if(!sxag_add(c,&sxag_jam_file_count,p)||(n&&!sxag_table(c,&sxag_jam_file,p+4,n))){ok=false;break;}p+=4+n*23;if(!sxag_read(c,p,b,4))continue;n=sxag32(b,false);if(n>4096||!sxag_span(c,p+4,n*19))continue;if(!sxag_add(c,&sxag_jam_directory_count,p)||(n&&!sxag_table(c,&sxag_jam_directory,p+4,n))){ok=false;break;}p+=4;for(uint64_t i=0;i<n;i++){if(!sxag_read(c,p+i*19,b,19))break;uint64_t child=sxag32(b+15,false);if(child<3||child>INT32_MAX)continue;bool seen=false;for(size_t j=0;j<tail;j++)if(queue[j]==child)seen=true;if(!seen&&tail<4096)queue[tail++]=child;}}
 xx_mem_free(queue);return ok;}
static bool sxag_fiz(sx_context *c){uint8_t b[20];uint64_t p=0;for(unsigned i=0;i<SXAG_LIMIT&&p<(uint64_t)c->size;i++){if(!sxag_read(c,p,b,20)||xx_rt_memcmp(b,"FIZ\32",4))break;uint64_t n=sxag32(b+12,false),name=b[5];if(!name||name>12||!sxag_span(c,p+20,name+n))break;if(!sxag_add(c,&sxag_fiz_member,p))return false;p+=20+name+n;}return c->count!=0;}
static bool sxag_ealib(sx_context *c){uint8_t b[18];if(!sxag_read(c,0,b,7)||!sxag_add(c,&sxag_ealib_header,0))return false;uint64_t n=sxag16(b+5,false);if(!n||n>=SXAG_LIMIT||!sxag_span(c,7,(n+1)*18))return true;if(!sxag_table(c,&sxag_ealib_entry,7,n+1))return false;uint64_t directory_end=7+(n+1)*18;for(uint64_t i=0;i<n;i++){if(!sxag_read(c,7+i*18,b,18))break;uint64_t p=sxag32(b+14,false);if(p<directory_end||p>INT32_MAX||(b[13]!=1&&b[13]!=4))continue;unsigned method=b[13];if(!sxag_read(c,7+(i+1)*18,b,18))break;uint64_t end=sxag32(b+14,false);if(end<p||end-p<4||!sxag_span(c,p,end-p))continue;if(!sxag_add(c,&sxag_ealib_packed_size,p))return false;if(method==4&&end-p>=6&&!sxag_add(c,&sxag_archivelegacy_dcl,p+4))return false;}return true;}
static int sxag_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxag_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxag_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxag_order);return !c->failed;}
static bool sx_archivelegacy_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_AMPLUS:case XX_FILE_TYPE_NOWCOMPRESS:case XX_FILE_TYPE_APPLELINK_PE:case XX_FILE_TYPE_ARC_CBM:case XX_FILE_TYPE_VMARC:case XX_FILE_TYPE_TI99ARC:case XX_FILE_TYPE_ZFSF:case XX_FILE_TYPE_TRCPAK:case XX_FILE_TYPE_CHIEFLZMULTI:case XX_FILE_TYPE_IBMZPAK:case XX_FILE_TYPE_ASCEND:case XX_FILE_TYPE_CFL:case XX_FILE_TYPE_DPK:case XX_FILE_TYPE_SWAGPACKET:case XX_FILE_TYPE_MARC:case XX_FILE_TYPE_HLB:case XX_FILE_TYPE_JAM:case XX_FILE_TYPE_TWS:case XX_FILE_TYPE_FIZ:case XX_FILE_TYPE_EALIB:return true;default:return false;}}
static bool sx_archivelegacy_build(sx_context *c){if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_AMPLUS:ok=sxag_amplus(c);break;case XX_FILE_TYPE_NOWCOMPRESS:ok=sxag_now(c);break;case XX_FILE_TYPE_APPLELINK_PE:ok=sxag_applelink(c);break;case XX_FILE_TYPE_ARC_CBM:ok=sxag_cbm(c);break;case XX_FILE_TYPE_VMARC:ok=sxag_vmarc(c);break;case XX_FILE_TYPE_TI99ARC:ok=sxag_ti99(c);break;case XX_FILE_TYPE_ZFSF:ok=sxag_zfsf(c);break;case XX_FILE_TYPE_TRCPAK:ok=sxag_fixed(c,&sxag_trcpak_header,&sxag_trcpak_entry,28,12,4,false,28,0);break;case XX_FILE_TYPE_CHIEFLZMULTI:ok=sxag_chief(c);break;case XX_FILE_TYPE_IBMZPAK:ok=sxag_ibm(c);break;case XX_FILE_TYPE_ASCEND:ok=sxag_add(c,&sxag_ascend_header,0)&&sxag_add(c,&sxag_archivelegacy_dcl,12);break;case XX_FILE_TYPE_CFL:ok=sxag_cfl(c);break;case XX_FILE_TYPE_DPK:ok=sxag_dpk(c);break;case XX_FILE_TYPE_SWAGPACKET:ok=sxag_swag(c);break;case XX_FILE_TYPE_MARC:ok=sxag_fixed(c,&sxag_marc_header,&sxag_marc_entry,12,8,4,false,12,0);break;case XX_FILE_TYPE_HLB:ok=sxag_hlb(c);break;case XX_FILE_TYPE_JAM:ok=sxag_jam(c);break;case XX_FILE_TYPE_TWS:ok=sxag_fixed(c,&sxag_tws_header,&sxag_tws_entry,25,17,4,false,25,1);break;case XX_FILE_TYPE_FIZ:ok=sxag_fiz(c);break;case XX_FILE_TYPE_EALIB:ok=sxag_ealib(c);break;default:break;}return ok&&sxag_finish(c);}
