/* SPDX-License-Identifier: MIT
 * Physical archive metadata. See docs/data_struct_archivemore_scope.txt. */
static const xx_data_struct_field_desc sxar_rtpatch_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("generation","uint16",2,2,SX_ID),
    SX_FIELD("builder_metadata","uint8[22]",4,22,SX_NONE),
};
static const sx_layout sxar_rtpatch_header = {UINT32_C(0x601c0001),"rtpatch_header",sxar_rtpatch_header_fields,SX_COUNT(sxar_rtpatch_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_rtpatch_destination_count_fields[] = {
    SX_FIELD("destination_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxar_rtpatch_destination_count = {UINT32_C(0x601c0002),"rtpatch_destination_count",sxar_rtpatch_destination_count_fields,SX_COUNT(sxar_rtpatch_destination_count_fields),SX_LE};
static const xx_data_struct_field_desc sxar_rtpatch_stream_sizes_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxar_rtpatch_stream_sizes = {UINT32_C(0x601c0003),"rtpatch_stream_sizes",sxar_rtpatch_stream_sizes_fields,SX_COUNT(sxar_rtpatch_stream_sizes_fields),SX_LE};
static const xx_data_struct_field_desc sxar_rtpatch_destination_fields[] = {
    SX_FIELD("name","char[14]",0,14,SX_STRING),
    SX_FIELD("attributes","uint16",14,2,SX_FLAGS),
    SX_FIELD("unpacked_size","uint32",16,4,SX_SIZE),
    SX_FIELD("date","uint16",20,2,SX_NONE),
    SX_FIELD("time","uint16",22,2,SX_NONE),
    SX_FIELD("builder_metadata","uint8[10]",24,10,SX_NONE),
};
static const sx_layout sxar_rtpatch_destination = {UINT32_C(0x601c0004),"rtpatch_destination",sxar_rtpatch_destination_fields,SX_COUNT(sxar_rtpatch_destination_fields),SX_LE};
static const xx_data_struct_field_desc sxar_rtpatch_codec_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("raw_literal_flag","uint8",2,1,SX_FLAGS),
    SX_FIELD("marker","uint8",3,1,SX_SIGNATURE),
    SX_FIELD("rescale_periods","uint24",4,3,SX_NONE),
    SX_FIELD("window_and_first_bits","uint8",7,1,SX_NONE),
};
static const sx_layout sxar_rtpatch_codec_header = {UINT32_C(0x601c0005),"rtpatch_codec_header",sxar_rtpatch_codec_header_fields,SX_COUNT(sxar_rtpatch_codec_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_rtpatch_name_size_fields[] = {
    SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxar_rtpatch_name_size = {UINT32_C(0x601c0006),"rtpatch_name_size",sxar_rtpatch_name_size_fields,SX_COUNT(sxar_rtpatch_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_header_v0_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("archive_size_32","uint32",8,4,SX_SIZE),
    SX_FIELD("format_version","uint16",12,2,SX_ID),
    SX_FIELD("sector_shift","uint16",14,2,SX_NONE),
    SX_FIELD("hash_table_offset_low","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_table_offset_low","uint32",20,4,SX_OFFSET),
    SX_FIELD("hash_entry_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("block_entry_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxar_mpq_header_v0 = {UINT32_C(0x601c0007),"mpq_header_v0",sxar_mpq_header_v0_fields,SX_COUNT(sxar_mpq_header_v0_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_header_v1_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("archive_size_32","uint32",8,4,SX_SIZE),
    SX_FIELD("format_version","uint16",12,2,SX_ID),
    SX_FIELD("sector_shift","uint16",14,2,SX_NONE),
    SX_FIELD("hash_table_offset_low","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_table_offset_low","uint32",20,4,SX_OFFSET),
    SX_FIELD("hash_entry_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("block_entry_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("high_block_table_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("hash_table_offset_high","uint16",40,2,SX_NONE),
    SX_FIELD("block_table_offset_high","uint16",42,2,SX_NONE),
};
static const sx_layout sxar_mpq_header_v1 = {UINT32_C(0x601c0008),"mpq_header_v1",sxar_mpq_header_v1_fields,SX_COUNT(sxar_mpq_header_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_header_v2_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("archive_size_32","uint32",8,4,SX_SIZE),
    SX_FIELD("format_version","uint16",12,2,SX_ID),
    SX_FIELD("sector_shift","uint16",14,2,SX_NONE),
    SX_FIELD("hash_table_offset_low","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_table_offset_low","uint32",20,4,SX_OFFSET),
    SX_FIELD("hash_entry_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("block_entry_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("high_block_table_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("hash_table_offset_high","uint16",40,2,SX_NONE),
    SX_FIELD("block_table_offset_high","uint16",42,2,SX_NONE),
    SX_FIELD("archive_size_64","uint64",44,8,SX_SIZE),
    SX_FIELD("bet_table_offset","uint64",52,8,SX_OFFSET),
    SX_FIELD("het_table_offset","uint64",60,8,SX_OFFSET),
};
static const sx_layout sxar_mpq_header_v2 = {UINT32_C(0x601c0009),"mpq_header_v2",sxar_mpq_header_v2_fields,SX_COUNT(sxar_mpq_header_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_header_v3_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("archive_size_32","uint32",8,4,SX_SIZE),
    SX_FIELD("format_version","uint16",12,2,SX_ID),
    SX_FIELD("sector_shift","uint16",14,2,SX_NONE),
    SX_FIELD("hash_table_offset_low","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_table_offset_low","uint32",20,4,SX_OFFSET),
    SX_FIELD("hash_entry_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("block_entry_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("high_block_table_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("hash_table_offset_high","uint16",40,2,SX_NONE),
    SX_FIELD("block_table_offset_high","uint16",42,2,SX_NONE),
    SX_FIELD("archive_size_64","uint64",44,8,SX_SIZE),
    SX_FIELD("bet_table_offset","uint64",52,8,SX_OFFSET),
    SX_FIELD("het_table_offset","uint64",60,8,SX_OFFSET),
    SX_FIELD("hash_table_size","uint64",68,8,SX_SIZE),
    SX_FIELD("block_table_size","uint64",76,8,SX_SIZE),
    SX_FIELD("high_block_table_size","uint64",84,8,SX_SIZE),
    SX_FIELD("het_table_size","uint64",92,8,SX_SIZE),
    SX_FIELD("bet_table_size","uint64",100,8,SX_SIZE),
    SX_FIELD("raw_chunk_size","uint32",108,4,SX_SIZE),
    SX_FIELD("block_table_md5","uint8[16]",112,16,SX_CHECKSUM),
    SX_FIELD("hash_table_md5","uint8[16]",128,16,SX_CHECKSUM),
    SX_FIELD("high_block_table_md5","uint8[16]",144,16,SX_CHECKSUM),
    SX_FIELD("bet_table_md5","uint8[16]",160,16,SX_CHECKSUM),
    SX_FIELD("het_table_md5","uint8[16]",176,16,SX_CHECKSUM),
    SX_FIELD("header_md5","uint8[16]",192,16,SX_CHECKSUM),
};
static const sx_layout sxar_mpq_header_v3 = {UINT32_C(0x601c000a),"mpq_header_v3",sxar_mpq_header_v3_fields,SX_COUNT(sxar_mpq_header_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_high_block_entry_fields[] = {
    SX_FIELD("file_offset_high","uint16",0,2,SX_NONE),
};
static const sx_layout sxar_mpq_high_block_entry = {UINT32_C(0x601c000b),"mpq_high_block_entry",sxar_mpq_high_block_entry_fields,SX_COUNT(sxar_mpq_high_block_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxar_applesingle_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("home_filesystem_or_filler","char[16]",8,16,SX_NONE),
    SX_FIELD("entry_count","uint16",24,2,SX_COUNT_PROP),
};
static const sx_layout sxar_applesingle_header = {UINT32_C(0x601c000c),"applesingle_header",sxar_applesingle_header_fields,SX_COUNT(sxar_applesingle_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_applesingle_entry_fields[] = {
    SX_FIELD("entry_id","uint32",0,4,SX_ID),
    SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxar_applesingle_entry = {UINT32_C(0x601c000d),"applesingle_entry",sxar_applesingle_entry_fields,SX_COUNT(sxar_applesingle_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxar_macbinary1_header_fields[] = {
    SX_FIELD("old_version","uint8",0,1,SX_ID),
    SX_FIELD("name_size","uint8",1,1,SX_SIZE),
    SX_FIELD("name","char[63]",2,63,SX_STRING),
    SX_FIELD("file_type","char[4]",65,4,SX_ID),
    SX_FIELD("creator","char[4]",69,4,SX_ID),
    SX_FIELD("finder_flags_high","uint8",73,1,SX_FLAGS),
    SX_FIELD("zero74","uint8",74,1,SX_RESERVED),
    SX_FIELD("window_vertical","int16",75,2,SX_NONE),
    SX_FIELD("window_horizontal","int16",77,2,SX_NONE),
    SX_FIELD("folder_id","uint16",79,2,SX_ID),
    SX_FIELD("protected_flag","uint8",81,1,SX_FLAGS),
    SX_FIELD("zero82","uint8",82,1,SX_RESERVED),
    SX_FIELD("data_fork_size","uint32",83,4,SX_SIZE),
    SX_FIELD("resource_fork_size","uint32",87,4,SX_SIZE),
    SX_FIELD("created","uint32",91,4,SX_NONE),
    SX_FIELD("modified","uint32",95,4,SX_NONE),
    SX_FIELD("unused_tail","uint8[29]",99,29,SX_NONE),
};
static const sx_layout sxar_macbinary1_header = {UINT32_C(0x601c000e),"macbinary1_header",sxar_macbinary1_header_fields,SX_COUNT(sxar_macbinary1_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_macbinary2_header_fields[] = {
    SX_FIELD("old_version","uint8",0,1,SX_ID),
    SX_FIELD("name_size","uint8",1,1,SX_SIZE),
    SX_FIELD("name","char[63]",2,63,SX_STRING),
    SX_FIELD("file_type","char[4]",65,4,SX_ID),
    SX_FIELD("creator","char[4]",69,4,SX_ID),
    SX_FIELD("finder_flags_high","uint8",73,1,SX_FLAGS),
    SX_FIELD("zero74","uint8",74,1,SX_RESERVED),
    SX_FIELD("window_vertical","int16",75,2,SX_NONE),
    SX_FIELD("window_horizontal","int16",77,2,SX_NONE),
    SX_FIELD("folder_id","uint16",79,2,SX_ID),
    SX_FIELD("protected_flag","uint8",81,1,SX_FLAGS),
    SX_FIELD("zero82","uint8",82,1,SX_RESERVED),
    SX_FIELD("data_fork_size","uint32",83,4,SX_SIZE),
    SX_FIELD("resource_fork_size","uint32",87,4,SX_SIZE),
    SX_FIELD("created","uint32",91,4,SX_NONE),
    SX_FIELD("modified","uint32",95,4,SX_NONE),
    SX_FIELD("comment_size","uint16",99,2,SX_SIZE),
    SX_FIELD("finder_flags_low","uint8",101,1,SX_FLAGS),
    SX_FIELD("unused_signature_area","uint8[14]",102,14,SX_NONE),
    SX_FIELD("total_unpacked_size","uint32",116,4,SX_SIZE),
    SX_FIELD("secondary_header_size","uint16",120,2,SX_SIZE),
    SX_FIELD("writer_version","uint8",122,1,SX_ID),
    SX_FIELD("minimum_version","uint8",123,1,SX_ID),
    SX_FIELD("header_crc16","uint16",124,2,SX_CHECKSUM),
    SX_FIELD("reserved_tail","uint16",126,2,SX_RESERVED),
};
static const sx_layout sxar_macbinary2_header = {UINT32_C(0x601c000f),"macbinary2_header",sxar_macbinary2_header_fields,SX_COUNT(sxar_macbinary2_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_macbinary3_header_fields[] = {
    SX_FIELD("old_version","uint8",0,1,SX_ID),
    SX_FIELD("name_size","uint8",1,1,SX_SIZE),
    SX_FIELD("name","char[63]",2,63,SX_STRING),
    SX_FIELD("file_type","char[4]",65,4,SX_ID),
    SX_FIELD("creator","char[4]",69,4,SX_ID),
    SX_FIELD("finder_flags_high","uint8",73,1,SX_FLAGS),
    SX_FIELD("zero74","uint8",74,1,SX_RESERVED),
    SX_FIELD("window_vertical","int16",75,2,SX_NONE),
    SX_FIELD("window_horizontal","int16",77,2,SX_NONE),
    SX_FIELD("folder_id","uint16",79,2,SX_ID),
    SX_FIELD("protected_flag","uint8",81,1,SX_FLAGS),
    SX_FIELD("zero82","uint8",82,1,SX_RESERVED),
    SX_FIELD("data_fork_size","uint32",83,4,SX_SIZE),
    SX_FIELD("resource_fork_size","uint32",87,4,SX_SIZE),
    SX_FIELD("created","uint32",91,4,SX_NONE),
    SX_FIELD("modified","uint32",95,4,SX_NONE),
    SX_FIELD("comment_size","uint16",99,2,SX_SIZE),
    SX_FIELD("finder_flags_low","uint8",101,1,SX_FLAGS),
    SX_FIELD("signature","char[4]",102,4,SX_SIGNATURE),
    SX_FIELD("script","uint8",106,1,SX_ID),
    SX_FIELD("extended_finder_flags","uint8",107,1,SX_FLAGS),
    SX_FIELD("reserved","uint8[8]",108,8,SX_RESERVED),
    SX_FIELD("total_unpacked_size","uint32",116,4,SX_SIZE),
    SX_FIELD("secondary_header_size","uint16",120,2,SX_SIZE),
    SX_FIELD("writer_version","uint8",122,1,SX_ID),
    SX_FIELD("minimum_version","uint8",123,1,SX_ID),
    SX_FIELD("header_crc16","uint16",124,2,SX_CHECKSUM),
    SX_FIELD("reserved_tail","uint16",126,2,SX_RESERVED),
};
static const sx_layout sxar_macbinary3_header = {UINT32_C(0x601c0010),"macbinary3_header",sxar_macbinary3_header_fields,SX_COUNT(sxar_macbinary3_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_binaryii_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("access_low","uint8",3,1,SX_FLAGS),
    SX_FIELD("file_type_low","uint8",4,1,SX_NONE),
    SX_FIELD("auxiliary_type_low","uint16",5,2,SX_NONE),
    SX_FIELD("storage_type_low","uint8",7,1,SX_NONE),
    SX_FIELD("block_count_low","uint16",8,2,SX_NONE),
    SX_FIELD("modified_date","uint16",10,2,SX_NONE),
    SX_FIELD("modified_time","uint16",12,2,SX_NONE),
    SX_FIELD("created_date","uint16",14,2,SX_NONE),
    SX_FIELD("created_time","uint16",16,2,SX_NONE),
    SX_FIELD("identity","uint8",18,1,SX_SIGNATURE),
    SX_FIELD("reserved19","uint8",19,1,SX_RESERVED),
    SX_FIELD("eof_low","uint24",20,3,SX_NONE),
    SX_FIELD("name_size","uint8",23,1,SX_SIZE),
    SX_FIELD("name","char[64]",24,64,SX_STRING),
    SX_FIELD("unused88","uint8[21]",88,21,SX_NONE),
    SX_FIELD("auxiliary_type_high","uint16",109,2,SX_NONE),
    SX_FIELD("access_high","uint8",111,1,SX_FLAGS),
    SX_FIELD("file_type_high","uint8",112,1,SX_NONE),
    SX_FIELD("storage_type_high","uint8",113,1,SX_NONE),
    SX_FIELD("block_count_high","uint16",114,2,SX_NONE),
    SX_FIELD("eof_high","uint8",116,1,SX_NONE),
    SX_FIELD("unused117","uint8[4]",117,4,SX_NONE),
    SX_FIELD("operating_system","uint8",121,1,SX_ID),
    SX_FIELD("native_file_type","uint16",122,2,SX_ID),
    SX_FIELD("reserved124","uint8",124,1,SX_RESERVED),
    SX_FIELD("data_flags","uint8",125,1,SX_FLAGS),
    SX_FIELD("version","uint8",126,1,SX_ID),
    SX_FIELD("files_to_follow","uint8",127,1,SX_COUNT_PROP),
};
static const sx_layout sxar_binaryii_header = {UINT32_C(0x601c0011),"binaryii_header",sxar_binaryii_header_fields,SX_COUNT(sxar_binaryii_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_master_fields[] = {
    SX_FIELD("magic","uint8[6]",0,6,SX_SIGNATURE),
    SX_FIELD("master_crc16","uint16",6,2,SX_CHECKSUM),
    SX_FIELD("record_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("created_second","uint8",12,1,SX_NONE),
    SX_FIELD("created_minute","uint8",13,1,SX_NONE),
    SX_FIELD("created_hour","uint8",14,1,SX_NONE),
    SX_FIELD("created_year_since_1900","uint8",15,1,SX_NONE),
    SX_FIELD("created_day_zero_based","uint8",16,1,SX_NONE),
    SX_FIELD("created_month_zero_based","uint8",17,1,SX_NONE),
    SX_FIELD("created_reserved","uint8",18,1,SX_RESERVED),
    SX_FIELD("created_weekday","uint8",19,1,SX_ID),
    SX_FIELD("modified_second","uint8",20,1,SX_NONE),
    SX_FIELD("modified_minute","uint8",21,1,SX_NONE),
    SX_FIELD("modified_hour","uint8",22,1,SX_NONE),
    SX_FIELD("modified_year_since_1900","uint8",23,1,SX_NONE),
    SX_FIELD("modified_day_zero_based","uint8",24,1,SX_NONE),
    SX_FIELD("modified_month_zero_based","uint8",25,1,SX_NONE),
    SX_FIELD("modified_reserved","uint8",26,1,SX_RESERVED),
    SX_FIELD("modified_weekday","uint8",27,1,SX_ID),
    SX_FIELD("version","uint16",28,2,SX_ID),
    SX_FIELD("reserved30","uint8[8]",30,8,SX_RESERVED),
    SX_FIELD("archive_size","uint32",38,4,SX_SIZE),
    SX_FIELD("reserved42","uint8[6]",42,6,SX_RESERVED),
};
static const sx_layout sxar_nufx_master = {UINT32_C(0x601c0012),"nufx_master",sxar_nufx_master_fields,SX_COUNT(sxar_nufx_master_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_record_fields[] = {
    SX_FIELD("magic","uint8[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_crc16","uint16",4,2,SX_CHECKSUM),
    SX_FIELD("attribute_size","uint16",6,2,SX_SIZE),
    SX_FIELD("version","uint16",8,2,SX_ID),
    SX_FIELD("thread_count","uint32",10,4,SX_COUNT_PROP),
    SX_FIELD("filesystem_id","uint16",14,2,SX_ID),
    SX_FIELD("filesystem_info","uint16",16,2,SX_NONE),
    SX_FIELD("access","uint32",18,4,SX_FLAGS),
    SX_FIELD("file_type","uint32",22,4,SX_ID),
    SX_FIELD("auxiliary_type_or_block_count","uint32",26,4,SX_NONE),
    SX_FIELD("storage_type_or_block_size","uint16",30,2,SX_NONE),
    SX_FIELD("created_second","uint8",32,1,SX_NONE),
    SX_FIELD("created_minute","uint8",33,1,SX_NONE),
    SX_FIELD("created_hour","uint8",34,1,SX_NONE),
    SX_FIELD("created_year_since_1900","uint8",35,1,SX_NONE),
    SX_FIELD("created_day_zero_based","uint8",36,1,SX_NONE),
    SX_FIELD("created_month_zero_based","uint8",37,1,SX_NONE),
    SX_FIELD("created_reserved","uint8",38,1,SX_RESERVED),
    SX_FIELD("created_weekday","uint8",39,1,SX_ID),
    SX_FIELD("modified_second","uint8",40,1,SX_NONE),
    SX_FIELD("modified_minute","uint8",41,1,SX_NONE),
    SX_FIELD("modified_hour","uint8",42,1,SX_NONE),
    SX_FIELD("modified_year_since_1900","uint8",43,1,SX_NONE),
    SX_FIELD("modified_day_zero_based","uint8",44,1,SX_NONE),
    SX_FIELD("modified_month_zero_based","uint8",45,1,SX_NONE),
    SX_FIELD("modified_reserved","uint8",46,1,SX_RESERVED),
    SX_FIELD("modified_weekday","uint8",47,1,SX_ID),
    SX_FIELD("archived_second","uint8",48,1,SX_NONE),
    SX_FIELD("archived_minute","uint8",49,1,SX_NONE),
    SX_FIELD("archived_hour","uint8",50,1,SX_NONE),
    SX_FIELD("archived_year_since_1900","uint8",51,1,SX_NONE),
    SX_FIELD("archived_day_zero_based","uint8",52,1,SX_NONE),
    SX_FIELD("archived_month_zero_based","uint8",53,1,SX_NONE),
    SX_FIELD("archived_reserved","uint8",54,1,SX_RESERVED),
    SX_FIELD("archived_weekday","uint8",55,1,SX_ID),
};
static const sx_layout sxar_nufx_record = {UINT32_C(0x601c0013),"nufx_record",sxar_nufx_record_fields,SX_COUNT(sxar_nufx_record_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_option_size_fields[] = {
    SX_FIELD("option_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxar_nufx_option_size = {UINT32_C(0x601c0014),"nufx_option_size",sxar_nufx_option_size_fields,SX_COUNT(sxar_nufx_option_size_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_name_size_fields[] = {
    SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxar_nufx_name_size = {UINT32_C(0x601c0015),"nufx_name_size",sxar_nufx_name_size_fields,SX_COUNT(sxar_nufx_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxar_nufx_thread_fields[] = {
    SX_FIELD("thread_class","uint16",0,2,SX_ID),
    SX_FIELD("method","uint16",2,2,SX_ID),
    SX_FIELD("thread_kind","uint16",4,2,SX_ID),
    SX_FIELD("thread_crc16","uint16",6,2,SX_CHECKSUM),
    SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxar_nufx_thread = {UINT32_C(0x601c0016),"nufx_thread",sxar_nufx_thread_fields,SX_COUNT(sxar_nufx_thread_fields),SX_LE};
static const xx_data_struct_field_desc sxar_packit_marker_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxar_packit_marker = {UINT32_C(0x601c0017),"packit_marker",sxar_packit_marker_fields,SX_COUNT(sxar_packit_marker_fields),SX_BE};
static const xx_data_struct_field_desc sxar_packit_stored_header_fields[] = {
    SX_FIELD("name_size","uint8",0,1,SX_SIZE),
    SX_FIELD("name","char[63]",1,63,SX_STRING),
    SX_FIELD("file_type","char[4]",64,4,SX_ID),
    SX_FIELD("creator","char[4]",68,4,SX_ID),
    SX_FIELD("finder_flags","uint16",72,2,SX_FLAGS),
    SX_FIELD("locked","uint16",74,2,SX_FLAGS),
    SX_FIELD("data_fork_size","uint32",76,4,SX_SIZE),
    SX_FIELD("resource_fork_size","uint32",80,4,SX_SIZE),
    SX_FIELD("created","uint32",84,4,SX_NONE),
    SX_FIELD("modified","uint32",88,4,SX_NONE),
    SX_FIELD("header_crc16","uint16",92,2,SX_CHECKSUM),
};
static const sx_layout sxar_packit_stored_header = {UINT32_C(0x601c0018),"packit_stored_header",sxar_packit_stored_header_fields,SX_COUNT(sxar_packit_stored_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_packit_forks_crc_fields[] = {
    SX_FIELD("forks_crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxar_packit_forks_crc = {UINT32_C(0x601c0019),"packit_forks_crc",sxar_packit_forks_crc_fields,SX_COUNT(sxar_packit_forks_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxar_stuffit_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("top_level_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("archive_size","uint32",6,4,SX_SIZE),
    SX_FIELD("signature","char[4]",10,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",14,1,SX_ID),
    SX_FIELD("reserved","uint8[7]",15,7,SX_RESERVED),
};
static const sx_layout sxar_stuffit_header = {UINT32_C(0x601c001a),"stuffit_header",sxar_stuffit_header_fields,SX_COUNT(sxar_stuffit_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_stuffit_member_fields[] = {
    SX_FIELD("resource_method","uint8",0,1,SX_ID),
    SX_FIELD("data_method","uint8",1,1,SX_ID),
    SX_FIELD("name_size","uint8",2,1,SX_SIZE),
    SX_FIELD("name","char[63]",3,63,SX_STRING),
    SX_FIELD("file_type","char[4]",66,4,SX_ID),
    SX_FIELD("creator","char[4]",70,4,SX_ID),
    SX_FIELD("finder_flags","uint16",74,2,SX_FLAGS),
    SX_FIELD("created","uint32",76,4,SX_NONE),
    SX_FIELD("modified","uint32",80,4,SX_NONE),
    SX_FIELD("resource_unpacked_size","uint32",84,4,SX_SIZE),
    SX_FIELD("data_unpacked_size","uint32",88,4,SX_SIZE),
    SX_FIELD("resource_packed_size","uint32",92,4,SX_SIZE),
    SX_FIELD("data_packed_size","uint32",96,4,SX_SIZE),
    SX_FIELD("resource_crc16","uint16",100,2,SX_CHECKSUM),
    SX_FIELD("data_crc16","uint16",102,2,SX_CHECKSUM),
    SX_FIELD("reserved","uint8[6]",104,6,SX_RESERVED),
    SX_FIELD("header_crc16","uint16",110,2,SX_CHECKSUM),
};
static const sx_layout sxar_stuffit_member = {UINT32_C(0x601c001b),"stuffit_member",sxar_stuffit_member_fields,SX_COUNT(sxar_stuffit_member_fields),SX_BE};
static const xx_data_struct_field_desc sxar_compactpro_header_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_ID),
    SX_FIELD("volume_number","uint8",1,1,SX_ID),
    SX_FIELD("volume_set","uint16",2,2,SX_ID),
    SX_FIELD("catalogue_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxar_compactpro_header = {UINT32_C(0x601c001c),"compactpro_header",sxar_compactpro_header_fields,SX_COUNT(sxar_compactpro_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_compactpro_catalogue_fields[] = {
    SX_FIELD("crc32_register","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("record_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("comment_size","uint8",6,1,SX_SIZE),
};
static const sx_layout sxar_compactpro_catalogue = {UINT32_C(0x601c001d),"compactpro_catalogue",sxar_compactpro_catalogue_fields,SX_COUNT(sxar_compactpro_catalogue_fields),SX_BE};
static const xx_data_struct_field_desc sxar_compactpro_name_size_fields[] = {
    SX_FIELD("name_size_and_folder","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxar_compactpro_name_size = {UINT32_C(0x601c001e),"compactpro_name_size",sxar_compactpro_name_size_fields,SX_COUNT(sxar_compactpro_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxar_compactpro_directory_fields[] = {
    SX_FIELD("descendant_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxar_compactpro_directory = {UINT32_C(0x601c001f),"compactpro_directory",sxar_compactpro_directory_fields,SX_COUNT(sxar_compactpro_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxar_compactpro_file_fields[] = {
    SX_FIELD("volume_number","uint8",0,1,SX_ID),
    SX_FIELD("data_offset","uint32",1,4,SX_OFFSET),
    SX_FIELD("file_type","char[4]",5,4,SX_ID),
    SX_FIELD("creator","char[4]",9,4,SX_ID),
    SX_FIELD("created","uint32",13,4,SX_NONE),
    SX_FIELD("modified","uint32",17,4,SX_NONE),
    SX_FIELD("finder_flags","uint16",21,2,SX_FLAGS),
    SX_FIELD("crc32_register","uint32",23,4,SX_CHECKSUM),
    SX_FIELD("flags","uint16",27,2,SX_FLAGS),
    SX_FIELD("resource_unpacked_size","uint32",29,4,SX_SIZE),
    SX_FIELD("data_unpacked_size","uint32",33,4,SX_SIZE),
    SX_FIELD("resource_packed_size","uint32",37,4,SX_SIZE),
    SX_FIELD("data_packed_size","uint32",41,4,SX_SIZE),
};
static const sx_layout sxar_compactpro_file = {UINT32_C(0x601c0020),"compactpro_file",sxar_compactpro_file_fields,SX_COUNT(sxar_compactpro_file_fields),SX_BE};
static const xx_data_struct_field_desc sxar_egg_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("header_id","uint32",6,4,SX_ID),
    SX_FIELD("reserved","uint32",10,4,SX_RESERVED),
    SX_FIELD("terminator","uint32",14,4,SX_SIGNATURE),
};
static const sx_layout sxar_egg_header = {UINT32_C(0x601c0021),"egg_header",sxar_egg_header_fields,SX_COUNT(sxar_egg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_egg_file_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("file_id","uint32",4,4,SX_ID),
    SX_FIELD("unpacked_size","uint64",8,8,SX_SIZE),
};
static const sx_layout sxar_egg_file = {UINT32_C(0x601c0022),"egg_file",sxar_egg_file_fields,SX_COUNT(sxar_egg_file_fields),SX_LE};
static const xx_data_struct_field_desc sxar_egg_extra_fields[] = {
    SX_FIELD("tag","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("data_size","uint16",5,2,SX_SIZE),
};
static const sx_layout sxar_egg_extra = {UINT32_C(0x601c0023),"egg_extra",sxar_egg_extra_fields,SX_COUNT(sxar_egg_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxar_egg_block_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("method","uint8",4,1,SX_ID),
    SX_FIELD("encryption","uint8",5,1,SX_ID),
    SX_FIELD("unpacked_size","uint32",6,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",10,4,SX_SIZE),
    SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
    SX_FIELD("terminator","uint32",18,4,SX_SIGNATURE),
};
static const sx_layout sxar_egg_block = {UINT32_C(0x601c0024),"egg_block",sxar_egg_block_fields,SX_COUNT(sxar_egg_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_egg_end_fields[] = {
    SX_FIELD("terminator","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxar_egg_end = {UINT32_C(0x601c0025),"egg_end",sxar_egg_end_fields,SX_COUNT(sxar_egg_end_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_raw_block_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxar_lzfse_raw_block = {UINT32_C(0x601c0026),"lzfse_raw_block",sxar_lzfse_raw_block_fields,SX_COUNT(sxar_lzfse_raw_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_lzvn_block_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxar_lzfse_lzvn_block = {UINT32_C(0x601c0027),"lzfse_lzvn_block",sxar_lzfse_lzvn_block_fields,SX_COUNT(sxar_lzfse_lzvn_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_v1_block_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("literal_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("match_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("literal_payload_size","uint32",20,4,SX_SIZE),
    SX_FIELD("lmd_payload_size","uint32",24,4,SX_SIZE),
    SX_FIELD("literal_bits","int32",28,4,SX_NONE),
    SX_FIELD("literal_states","uint16[4]",32,8,SX_NONE),
    SX_FIELD("lmd_bits","int32",40,4,SX_NONE),
    SX_FIELD("l_state","uint16",44,2,SX_NONE),
    SX_FIELD("m_state","uint16",46,2,SX_NONE),
    SX_FIELD("d_state","uint16",48,2,SX_NONE),
    SX_FIELD("l_frequencies","uint16[20]",50,40,SX_NONE),
    SX_FIELD("m_frequencies","uint16[20]",90,40,SX_NONE),
    SX_FIELD("d_frequencies","uint16[64]",130,128,SX_NONE),
    SX_FIELD("literal_frequencies","uint16[256]",258,512,SX_NONE),
    SX_FIELD("alignment_padding","uint16",770,2,SX_RESERVED),
};
static const sx_layout sxar_lzfse_v1_block = {UINT32_C(0x601c0028),"lzfse_v1_block",sxar_lzfse_v1_block_fields,SX_COUNT(sxar_lzfse_v1_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_v2_block_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_fields0","uint64",8,8,SX_NONE),
    SX_FIELD("packed_fields1","uint64",16,8,SX_NONE),
    SX_FIELD("packed_fields2","uint64",24,8,SX_NONE),
};
static const sx_layout sxar_lzfse_v2_block = {UINT32_C(0x601c0029),"lzfse_v2_block",sxar_lzfse_v2_block_fields,SX_COUNT(sxar_lzfse_v2_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_end_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxar_lzfse_end = {UINT32_C(0x601c002a),"lzfse_end",sxar_lzfse_end_fields,SX_COUNT(sxar_lzfse_end_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzf_stored_block_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("kind","uint8",2,1,SX_ID),
    SX_FIELD("packed_size","uint16",3,2,SX_SIZE),
};
static const sx_layout sxar_lzf_stored_block = {UINT32_C(0x601c002b),"lzf_stored_block",sxar_lzf_stored_block_fields,SX_COUNT(sxar_lzf_stored_block_fields),SX_BE};
static const xx_data_struct_field_desc sxar_lzf_compressed_block_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("kind","uint8",2,1,SX_ID),
    SX_FIELD("packed_size","uint16",3,2,SX_SIZE),
    SX_FIELD("unpacked_size","uint16",5,2,SX_SIZE),
};
static const sx_layout sxar_lzf_compressed_block = {UINT32_C(0x601c002c),"lzf_compressed_block",sxar_lzf_compressed_block_fields,SX_COUNT(sxar_lzf_compressed_block_fields),SX_BE};
static const xx_data_struct_field_desc sxar_lzf_end_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxar_lzf_end = {UINT32_C(0x601c002d),"lzf_end",sxar_lzf_end_fields,SX_COUNT(sxar_lzf_end_fields),SX_LE};
static const xx_data_struct_field_desc sxar_sixpack_header_fields[] = {
    SX_FIELD("magic","uint8[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxar_sixpack_header = {UINT32_C(0x601c002e),"sixpack_header",sxar_sixpack_header_fields,SX_COUNT(sxar_sixpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_sixpack_chunk_fields[] = {
    SX_FIELD("kind","uint16",0,2,SX_ID),
    SX_FIELD("method","uint16",2,2,SX_ID),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
    SX_FIELD("adler32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxar_sixpack_chunk = {UINT32_C(0x601c002f),"sixpack_chunk",sxar_sixpack_chunk_fields,SX_COUNT(sxar_sixpack_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxar_sixpack_file_fields[] = {
    SX_FIELD("file_size","uint64",0,8,SX_SIZE),
    SX_FIELD("name_size","uint16",8,2,SX_SIZE),
};
static const sx_layout sxar_sixpack_file = {UINT32_C(0x601c0030),"sixpack_file",sxar_sixpack_file_fields,SX_COUNT(sxar_sixpack_file_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lbr_directory_entry_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
    SX_FIELD("name","char[8]",1,8,SX_STRING),
    SX_FIELD("extension","char[3]",9,3,SX_STRING),
    SX_FIELD("first_sector","uint16",12,2,SX_NONE),
    SX_FIELD("sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("crc16","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("created_date","uint16",18,2,SX_NONE),
    SX_FIELD("modified_date","uint16",20,2,SX_NONE),
    SX_FIELD("created_time","uint16",22,2,SX_NONE),
    SX_FIELD("modified_time","uint16",24,2,SX_NONE),
    SX_FIELD("pad_size","uint8",26,1,SX_SIZE),
    SX_FIELD("reserved","uint8[5]",27,5,SX_RESERVED),
};
static const sx_layout sxar_lbr_directory_entry = {UINT32_C(0x601c0031),"lbr_directory_entry",sxar_lbr_directory_entry_fields,SX_COUNT(sxar_lbr_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxar_pdp11ar_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxar_pdp11ar_header = {UINT32_C(0x601c0032),"pdp11ar_header",sxar_pdp11ar_header_fields,SX_COUNT(sxar_pdp11ar_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_pdp11ar_member_fields[] = {
    SX_FIELD("name","char[14]",0,14,SX_STRING),
    SX_FIELD("modified","uint32_pdp",14,4,SX_TIME),
    SX_FIELD("uid","uint8",18,1,SX_ID),
    SX_FIELD("gid","uint8",19,1,SX_ID),
    SX_FIELD("mode","uint16",20,2,SX_FLAGS),
    SX_FIELD("data_size","uint32_pdp",22,4,SX_SIZE),
};
static const sx_layout sxar_pdp11ar_member = {UINT32_C(0x601c0033),"pdp11ar_member",sxar_pdp11ar_member_fields,SX_COUNT(sxar_pdp11ar_member_fields),SX_LE};
static const xx_data_struct_field_desc sxar_bigaf_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("member_table_offset","ascii_decimal[20]",8,20,SX_OFFSET),
    SX_FIELD("symbol_table_offset","ascii_decimal[20]",28,20,SX_OFFSET),
    SX_FIELD("symbol_table64_offset","ascii_decimal[20]",48,20,SX_OFFSET),
    SX_FIELD("first_member_offset","ascii_decimal[20]",68,20,SX_OFFSET),
    SX_FIELD("last_member_offset","ascii_decimal[20]",88,20,SX_OFFSET),
    SX_FIELD("free_list_offset","ascii_decimal[20]",108,20,SX_OFFSET),
};
static const sx_layout sxar_bigaf_header = {UINT32_C(0x601c0034),"bigaf_header",sxar_bigaf_header_fields,SX_COUNT(sxar_bigaf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_bigaf_member_fields[] = {
    SX_FIELD("data_size","ascii_decimal[20]",0,20,SX_SIZE),
    SX_FIELD("next_member_offset","ascii_decimal[20]",20,20,SX_OFFSET),
    SX_FIELD("previous_member_offset","ascii_decimal[20]",40,20,SX_OFFSET),
    SX_FIELD("modified","ascii_decimal[12]",60,12,SX_TIME),
    SX_FIELD("uid","ascii_decimal[12]",72,12,SX_ID),
    SX_FIELD("gid","ascii_decimal[12]",84,12,SX_ID),
    SX_FIELD("mode","ascii_octal_padded[12]",96,12,SX_FLAGS),
    SX_FIELD("name_size","ascii_decimal[4]",108,4,SX_SIZE),
};
static const sx_layout sxar_bigaf_member = {UINT32_C(0x601c0035),"bigaf_member",sxar_bigaf_member_fields,SX_COUNT(sxar_bigaf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxar_bigaf_name_end_fields[] = {
    SX_FIELD("terminator","char[2]",0,2,SX_SIGNATURE),
};
static const sx_layout sxar_bigaf_name_end = {UINT32_C(0x601c0036),"bigaf_name_end",sxar_bigaf_name_end_fields,SX_COUNT(sxar_bigaf_name_end_fields),SX_LE};
static const sx_layout *const sx_archivemore_layouts[] = {
    &sxar_rtpatch_header,
    &sxar_rtpatch_destination_count,
    &sxar_rtpatch_stream_sizes,
    &sxar_rtpatch_destination,
    &sxar_rtpatch_codec_header,
    &sxar_rtpatch_name_size,
    &sxar_mpq_header_v0,
    &sxar_mpq_header_v1,
    &sxar_mpq_header_v2,
    &sxar_mpq_header_v3,
    &sxar_mpq_high_block_entry,
    &sxar_applesingle_header,
    &sxar_applesingle_entry,
    &sxar_macbinary1_header,
    &sxar_macbinary2_header,
    &sxar_macbinary3_header,
    &sxar_binaryii_header,
    &sxar_nufx_master,
    &sxar_nufx_record,
    &sxar_nufx_option_size,
    &sxar_nufx_name_size,
    &sxar_nufx_thread,
    &sxar_packit_marker,
    &sxar_packit_stored_header,
    &sxar_packit_forks_crc,
    &sxar_stuffit_header,
    &sxar_stuffit_member,
    &sxar_compactpro_header,
    &sxar_compactpro_catalogue,
    &sxar_compactpro_name_size,
    &sxar_compactpro_directory,
    &sxar_compactpro_file,
    &sxar_egg_header,
    &sxar_egg_file,
    &sxar_egg_extra,
    &sxar_egg_block,
    &sxar_egg_end,
    &sxar_lzfse_raw_block,
    &sxar_lzfse_lzvn_block,
    &sxar_lzfse_v1_block,
    &sxar_lzfse_v2_block,
    &sxar_lzfse_end,
    &sxar_lzf_stored_block,
    &sxar_lzf_compressed_block,
    &sxar_lzf_end,
    &sxar_sixpack_header,
    &sxar_sixpack_chunk,
    &sxar_sixpack_file,
    &sxar_lbr_directory_entry,
    &sxar_pdp11ar_header,
    &sxar_pdp11ar_member,
    &sxar_bigaf_header,
    &sxar_bigaf_member,
    &sxar_bigaf_name_end,
};
static bool sx_archivemore_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x601c0000U||id>=0x601d0000U)return true;
    if(r->type&&!xx_rt_wcsncmp(r->type,L"ascii_",6)&&xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x601c0004U:
        if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time bits.";
        if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time bits.";
        break;
    case 0x601c0005U:
        if(!xx_rt_wcscmp(r->name,L"rescale_periods"))text=L"Two packed 12-bit rescale periods; first in the high 12 bits.";
        if(!xx_rt_wcscmp(r->name,L"window_and_first_bits"))text=L"High nibble is the window selector; low nibble starts the compressed payload.";
        break;
    case 0x601c0007U:
        if(!xx_rt_wcscmp(r->name,L"sector_shift"))text=L"File sectors contain 512 multiplied by 2 raised to sector_shift bytes.";
        break;
    case 0x601c0008U:
        if(!xx_rt_wcscmp(r->name,L"sector_shift"))text=L"File sectors contain 512 multiplied by 2 raised to sector_shift bytes.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_low"))text=L"Low 32 bits of the byte offset; combine hash_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_low"))text=L"Low 32 bits of the byte offset; combine block_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        break;
    case 0x601c0009U:
        if(!xx_rt_wcscmp(r->name,L"sector_shift"))text=L"File sectors contain 512 multiplied by 2 raised to sector_shift bytes.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_low"))text=L"Low 32 bits of the byte offset; combine hash_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_low"))text=L"Low 32 bits of the byte offset; combine block_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        break;
    case 0x601c000aU:
        if(!xx_rt_wcscmp(r->name,L"sector_shift"))text=L"File sectors contain 512 multiplied by 2 raised to sector_shift bytes.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_low"))text=L"Low 32 bits of the byte offset; combine hash_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_low"))text=L"Low 32 bits of the byte offset; combine block_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        break;
    case 0x601c000bU:
        if(!xx_rt_wcscmp(r->name,L"file_offset_high"))text=L"Upper 16 bits of a file offset; encrypted block-table entry contains the low word.";
        break;
    case 0x601c000eU:
        if(!xx_rt_wcscmp(r->name,L"window_vertical"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"window_horizontal"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        break;
    case 0x601c000fU:
        if(!xx_rt_wcscmp(r->name,L"window_vertical"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"window_horizontal"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"total_unpacked_size"))text=L"Reserved for compressed MacBinary files; not used by the plain native reader.";
        break;
    case 0x601c0010U:
        if(!xx_rt_wcscmp(r->name,L"window_vertical"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"window_horizontal"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"total_unpacked_size"))text=L"Reserved for compressed MacBinary files; not used by the plain native reader.";
        break;
    case 0x601c0011U:
        if(!xx_rt_wcscmp(r->name,L"block_count_low"))text=L"Low 16 bits of the ProDOS block count, not a byte size.";
        if(!xx_rt_wcscmp(r->name,L"modified_date"))text=L"Packed ProDOS date.";
        if(!xx_rt_wcscmp(r->name,L"modified_time"))text=L"Packed ProDOS time.";
        if(!xx_rt_wcscmp(r->name,L"created_date"))text=L"Packed ProDOS date.";
        if(!xx_rt_wcscmp(r->name,L"created_time"))text=L"Packed ProDOS time.";
        if(!xx_rt_wcscmp(r->name,L"eof_low"))text=L"Low 24 bits of the declared byte size; combine eof_high. Directories store no payload.";
        if(!xx_rt_wcscmp(r->name,L"block_count_high"))text=L"High 16 bits of the ProDOS block count.";
        if(!xx_rt_wcscmp(r->name,L"eof_high"))text=L"High 8 bits of the declared byte size.";
        break;
    case 0x601c0013U:
        if(!xx_rt_wcscmp(r->name,L"filesystem_info"))text=L"Low byte is the native pathname separator; high byte is reserved.";
        if(!xx_rt_wcscmp(r->name,L"auxiliary_type_or_block_count"))text=L"File auxiliary type, or disk block count for disk-image threads.";
        if(!xx_rt_wcscmp(r->name,L"storage_type_or_block_size"))text=L"File storage type, or disk block size in bytes for disk-image threads.";
        break;
    case 0x601c0016U:
        if(!xx_rt_wcscmp(r->name,L"thread_crc16"))text=L"Version 2 checks compressed bytes; version 3 checks uncompressed bytes, seeded 0xFFFF.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size"))text=L"Disk-image threads may instead derive their byte size from the record block count.";
        break;
    case 0x601c0018U:
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        break;
    case 0x601c001bU:
        if(!xx_rt_wcscmp(r->name,L"resource_method"))text=L"Method bits plus folder/encryption markers; 32 starts a folder and 33 ends one.";
        if(!xx_rt_wcscmp(r->name,L"data_method"))text=L"Fork compression method and password flag; 0 is stored.";
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        break;
    case 0x601c001eU:
        if(!xx_rt_wcscmp(r->name,L"name_size_and_folder"))text=L"Low 7 bits are name length; bit 7 marks a directory.";
        break;
    case 0x601c0020U:
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"crc32_register"))text=L"Uncomplemented CRC32 over resource then data fork.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 encrypted; bit 1 resource LZH; bit 2 data LZH.";
        break;
    case 0x601c0029U:
        if(!xx_rt_wcscmp(r->name,L"packed_fields0"))text=L"Bits 0..19 literals; 20..39 literal bytes; 40..59 matches; 60..62 literal bit accumulator.";
        if(!xx_rt_wcscmp(r->name,L"packed_fields1"))text=L"Four 10-bit literal states; bits 40..59 LMD payload bytes; 60..62 LMD bit accumulator.";
        if(!xx_rt_wcscmp(r->name,L"packed_fields2"))text=L"Bits 0..31 header byte size; 32..41 L state; 42..51 M state; 52..61 D state.";
        break;
    case 0x601c0031U:
        if(!xx_rt_wcscmp(r->name,L"status"))text=L"0 active, 0xFE deleted, 0xFF unused; stale fields in inactive entries are not live references.";
        if(!xx_rt_wcscmp(r->name,L"first_sector"))text=L"File-relative sector number; multiply by 128 for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Count of 128-byte sectors.";
        if(!xx_rt_wcscmp(r->name,L"created_date"))text=L"Days since 1977-12-31; zero means unset.";
        if(!xx_rt_wcscmp(r->name,L"modified_date"))text=L"Days since 1977-12-31; zero means unset.";
        if(!xx_rt_wcscmp(r->name,L"created_time"))text=L"Packed DOS date/time bits.";
        if(!xx_rt_wcscmp(r->name,L"modified_time"))text=L"Packed DOS date/time bits.";
        break;
    case 0x601c0035U:
        if(!xx_rt_wcscmp(r->name,L"mode"))text=L"Octal permission bits stored as a blank-padded digit string.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}

/* Every offset is relative to the selected reader's original physical base. */
#define SXAR_LIMIT 20000U
static bool sxar_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxar_read(sx_context *c,uint64_t p,void *b,size_t n){return sxar_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxar16(const uint8_t *b,bool be){return xx_data_get_u16(b,2,0,be);}
static uint32_t sxar32(const uint8_t *b,bool be){return xx_data_get_u32(b,4,0,be);}
static uint64_t sxar64(const uint8_t *b){return xx_data_get_u64(b,8,0,false);}
static bool sxar_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return c->count<SXAR_LIMIT&&p<=INT64_MAX&&sx_add(c,l,(int64_t)p,f->rel_offset+f->size);}
static bool sxar_applesingle(sx_context *c){uint8_t b[26];if(!sxar_read(c,0,b,26)||!sxar_add(c,&sxar_applesingle_header,0))return false;uint32_t n=sxar16(b+24,true);return sxar_span(c,26,(uint64_t)n*12)&&sx_table(c,&sxar_applesingle_entry,26,12,n);}
static bool sxar_macbinary(sx_context *c){uint8_t b[128];if(!sxar_read(c,0,b,128))return false;const sx_layout *l=b[122]==130&&!xx_rt_memcmp(b+102,"mBIN",4)?&sxar_macbinary3_header:b[122]>=129?&sxar_macbinary2_header:&sxar_macbinary1_header;return sxar_add(c,l,0);}
static bool sxar_binaryii(sx_context *c){uint64_t p=0;for(unsigned i=0;i<SXAR_LIMIT;i++){uint8_t b[128];if(!sxar_read(c,p,b,128)||xx_rt_memcmp(b,"\x0aGL",3))break;if(!sxar_add(c,&sxar_binaryii_header,p))return false;uint64_t n=b[7]==13?0:(uint64_t)sxar16(b+20,false)|((uint64_t)b[22]<<16)|((uint64_t)b[116]<<24);if(!b[127]||!sxar_span(c,p+128,n))break;p=(p+128+n+127)&~UINT64_C(127);}return c->count!=0;}
static bool sxar_nufx(sx_context *c){uint8_t b[58];if(!sxar_read(c,0,b,48)||!sxar_add(c,&sxar_nufx_master,0))return false;uint32_t n=sxar32(b+8,false);uint64_t p=48;if(n>SXAR_LIMIT)return true;
 for(uint32_t i=0;i<n;i++){if(!sxar_read(c,p,b,56))break;uint16_t size=sxar16(b+6,false),v=sxar16(b+8,false),name;uint32_t threads=sxar32(b+10,false);if(size<(v?60:58)||size>4096||threads>SXAR_LIMIT||!sxar_span(c,p,size))break;
  if(!sx_u16(c,(int64_t)p+size-2,false,&name)||!sxar_span(c,p+size,name+(uint64_t)threads*16))break;
  if(!sxar_add(c,&sxar_nufx_record,p)||(v&&!sxar_add(c,&sxar_nufx_option_size,p+56))||!sxar_add(c,&sxar_nufx_name_size,p+size-2))return false;
  uint64_t table=p+size+name;if(threads&&!sx_table(c,&sxar_nufx_thread,(int64_t)table,16,threads))return false;p=table+(uint64_t)threads*16;
  for(uint32_t j=0;j<threads;j++){uint32_t z;if(!sx_u32(c,(int64_t)(table+(uint64_t)j*16+12),false,&z)||!sxar_span(c,p,z))return true;p+=z;}
 }return true;}
static bool sxar_stuffit(sx_context *c){uint8_t b[112];if(!sxar_read(c,0,b,22)||!sxar_add(c,&sxar_stuffit_header,0))return false;uint64_t p=22;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){if(!sxar_read(c,p,b,112))break;if(!sxar_add(c,&sxar_stuffit_member,p))return false;uint8_t rm=(uint8_t)(b[0]&~0x90U),dm=(uint8_t)(b[1]&~0x90U);uint64_t n=(rm==32||rm==33||dm==32||dm==33)?0:(uint64_t)sxar32(b+92,true)+sxar32(b+96,true);if(!sxar_span(c,p+112,n))break;p+=112+n;}return true;}
static bool sxar_compactpro(sx_context *c){uint8_t b[8];if(!sxar_read(c,0,b,8)||!sxar_add(c,&sxar_compactpro_header,0))return false;uint64_t p=sxar32(b+4,true);if(p<8||!sxar_read(c,p,b,7))return true;uint32_t n=sxar16(b+4,true);if(n>SXAR_LIMIT||!sxar_add(c,&sxar_compactpro_catalogue,p))return false;p+=7+b[6];
 for(uint32_t i=0;i<n;i++){if(!sxar_read(c,p,b,1))break;uint8_t q=b[0];if(!sxar_span(c,p+1,(q&127)+(q&128?2:45)))break;if(!sxar_add(c,&sxar_compactpro_name_size,p))return false;p+=1+(q&127);if(!sxar_add(c,q&128?&sxar_compactpro_directory:&sxar_compactpro_file,p))return false;p+=q&128?2:45;}
 return true;}
static bool sxar_egg(sx_context *c){uint8_t b[22];if(!sxar_read(c,0,b,18)||!sxar_add(c,&sxar_egg_header,0))return false;uint64_t p=18;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){if(!sxar_read(c,p,b,4))break;uint32_t tag=sxar32(b,false);uint64_t n=0;const sx_layout *l=NULL;
 if(tag==0x08e28222){l=&sxar_egg_end;n=4;}else if(tag==0x0a8590e3){l=&sxar_egg_file;n=16;}else if(tag==0x0a8591ac||tag==0x04c63672){if(!sxar_read(c,p,b,7))break;l=&sxar_egg_extra;n=7+(uint64_t)sxar16(b+5,false);}else if(tag==0x02b50c13){if(!sxar_read(c,p,b,22))break;l=&sxar_egg_block;n=22+(uint64_t)sxar32(b+10,false);}else break;
 if(!sxar_span(c,p,n))break;if(!sxar_add(c,l,p))return false;p+=n;}return true;}
static bool sxar_lzfse(sx_context *c){uint64_t p=0;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){uint8_t b[32];if(!sxar_read(c,p,b,4))break;const sx_layout *l=NULL;uint64_t head=0,payload=0;
 if(!xx_rt_memcmp(b,"bvx$",4)){if(!sxar_add(c,&sxar_lzfse_end,p))return false;break;}
 if(!xx_rt_memcmp(b,"bvx-",4)){head=8;if(!sxar_read(c,p,b,8))break;payload=sxar32(b+4,false);l=&sxar_lzfse_raw_block;}
 else if(!xx_rt_memcmp(b,"bvxn",4)){head=12;if(!sxar_read(c,p,b,12))break;payload=sxar32(b+8,false);l=&sxar_lzfse_lzvn_block;}
 else if(!xx_rt_memcmp(b,"bvx1",4)){head=772;if(!sxar_read(c,p,b,28))break;payload=(uint64_t)sxar32(b+20,false)+sxar32(b+24,false);l=&sxar_lzfse_v1_block;}
 else if(!xx_rt_memcmp(b,"bvx2",4)){if(!sxar_read(c,p,b,32))break;head=sxar32(b+24,false);if(head<32||head>752)break;payload=((sxar64(b+8)>>20)&0xfffff)+((sxar64(b+16)>>40)&0xfffff);l=&sxar_lzfse_v2_block;}else break;
 if(!sxar_span(c,p,head+payload))break;if(!sxar_add(c,l,p))return false;p+=head+payload;}return c->count!=0;}
static bool sxar_lzf(sx_context *c){uint64_t p=0;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){uint8_t b[7];if(!sxar_read(c,p,b,1))break;if(!b[0]&&p+1==(uint64_t)c->size){if(!sxar_add(c,&sxar_lzf_end,p))return false;break;}if(!sxar_read(c,p,b,5)||b[0]!='Z'||b[1]!='V'||b[2]>1)break;uint64_t head=b[2]?7:5,n=sxar16(b+3,true);if(!sxar_span(c,p,head+n))break;if(!sxar_add(c,b[2]?&sxar_lzf_compressed_block:&sxar_lzf_stored_block,p))return false;p+=head+n;}return c->count!=0;}
static bool sxar_sixpack(sx_context *c){uint8_t b[16];if(!sxar_span(c,0,8)||!sxar_add(c,&sxar_sixpack_header,0))return false;uint64_t p=8;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){if(!sxar_read(c,p,b,16))break;uint64_t n=sxar32(b+4,false);if(!sxar_span(c,p+16,n))break;if(!sxar_add(c,&sxar_sixpack_chunk,p))return false;if(sxar16(b,false)==1&&n>=10&&!sxar_add(c,&sxar_sixpack_file,p+16))return false;p+=16+n;}return true;}
static bool sxar_lbr(sx_context *c){uint8_t b[32];if(!sxar_read(c,0,b,32))return false;uint64_t n=(uint64_t)sxar16(b+14,false)*4;if(!n||n>SXAR_LIMIT||!sxar_span(c,0,n*32))return false;return sx_table(c,&sxar_lbr_directory_entry,0,32,n);}
static bool sxar_pdp11ar(sx_context *c){if(!sxar_span(c,0,2)||!sxar_add(c,&sxar_pdp11ar_header,0))return false;uint64_t p=2;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){uint8_t b[26];if(!sxar_read(c,p,b,26)||!b[0])break;uint64_t n=((uint32_t)sxar16(b+22,false)<<16)|sxar16(b+24,false);if(!sxar_span(c,p+26,n))break;if(!sxar_add(c,&sxar_pdp11ar_member,p))return false;p=(p+26+n+1)&~UINT64_C(1);}return true;}
static bool sxar_decimal(const uint8_t *b,size_t n,uint64_t *v){size_t a=0;*v=0;while(a<n&&(b[a]==' '||b[a]=='\t'))a++;while(n>a&&(b[n-1]==' '||b[n-1]=='\t'||b[n-1]=='\n'||b[n-1]=='\r'))n--;for(;a<n;a++){unsigned d=b[a]-'0';if(d>9||*v>(UINT64_MAX-d)/10)return false;*v=*v*10+d;}return true;}
static bool sxar_bigaf(sx_context *c){uint8_t b[128];if(!sxar_read(c,0,b,128)||!sxar_add(c,&sxar_bigaf_header,0))return false;uint64_t p,last;if(!sxar_decimal(b+68,20,&p)||!sxar_decimal(b+88,20,&last))return true;
 for(unsigned i=0;i<SXAR_LIMIT&&p>=128;i++){uint64_t next,n,name;if(!sxar_read(c,p,b,112)||!sxar_decimal(b,20,&n)||!sxar_decimal(b+20,20,&next)||!sxar_decimal(b+108,4,&name)||!name||name>4096||!sxar_span(c,p+112,name))break;
  uint64_t term=(p+112+name+1)&~UINT64_C(1);if(!sxar_span(c,term,2)||!sxar_span(c,term+2,n))break;if(!sxar_add(c,&sxar_bigaf_member,p)||!sxar_add(c,&sxar_bigaf_name_end,term))return false;if(p==last||next<=p||next<term+2+n)break;p=next;}
 return true;}
/* Reuse validated native archive-record boundaries for formats whose compressed
 * stream must be decoded merely to find the next physical record. No constructors. */
static bool sxar_native_records(sx_context *c,bool pit){uint8_t b[128];uint16_t generation=0;uint64_t end=0;bool ok=true;
 if(!pit){if(!sxar_read(c,0,b,26)||!sxar_add(c,&sxar_rtpatch_header,0))return false;generation=sxar16(b+2,false);}
 if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return c->count!=0;
 xx_archive_record_state *state=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!state)return c->count!=0;
 for(unsigned i=0;i<SXAR_LIMIT;i++){const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,state);if(!r)break;
  int64_t absolute=r->header_offset;
  if(pit&&absolute<c->f->base_address&&(r->header_size==4||r->header_size==98)&&r->data_offset>=c->f->base_address+r->header_size)absolute=r->data_offset-r->header_size;
  if(absolute>=c->f->base_address){uint64_t p=(uint64_t)(absolute-c->f->base_address),data=r->data_offset>=c->f->base_address?(uint64_t)(r->data_offset-c->f->base_address):UINT64_MAX;
   if(pit){if(p>=end&&sxar_read(c,p,b,4)&&!xx_rt_memcmp(b,"PMa",3)){if(!sxar_add(c,&sxar_packit_marker,p)){ok=false;break;}
    if(b[3]=='g'&&sxar_read(c,p+4,b,94)){uint64_t z=(uint64_t)sxar32(b+76,true)+sxar32(b+80,true);if(sxar_span(c,p+98,z+2)){if(!sxar_add(c,&sxar_packit_stored_header,p+4)||!sxar_add(c,&sxar_packit_forks_crc,p+98+z)){ok=false;break;}end=p+100+z;}}
    else if(data<=INT64_MAX&&r->compressed_size>=0&&sxar_span(c,data,(uint64_t)r->compressed_size))end=data+(uint64_t)r->compressed_size;
   }}else if(p>=26&&p>=end&&r->header_size>=42&&data==p+(uint64_t)r->header_size&&sxar_read(c,p,b,42)){
    /* Fixed and augmented whole-file forms start with the two size words.
     * Delta/inline forms remain raw unless this independent shape agrees. */
    uint32_t n=sxar32(b,false);bool whole=p>0&&sxar_read(c,p-1,b+42,1)&&b[42]==1&&n==sxar32(b+24,false)&&r->compressed_size>=0&&sxar32(b+4,false)==(uint64_t)r->compressed_size;
    if(whole&&((generation<=320&&r->header_size==42)||(generation>=400&&r->header_size>=53))){
     uint64_t name=p+50;bool valid=true;if(generation>=400){uint8_t z;valid=sxar_read(c,name,&z,1)&&z>=2&&name+1+z==data;}
     if(valid){if(!sxar_add(c,&sxar_rtpatch_destination_count,p-1)||!sxar_add(c,&sxar_rtpatch_stream_sizes,p)||!sxar_add(c,&sxar_rtpatch_destination,p+8)||(generation>=400&&!sxar_add(c,&sxar_rtpatch_name_size,name))){ok=false;break;}if(sxar_read(c,data,b,8)&&b[0]==0xb5&&b[1]==0x9c&&!sxar_add(c,&sxar_rtpatch_codec_header,data)){ok=false;break;}end=data+(uint64_t)r->compressed_size;}
    }
   }
  }
  if(!(c->f->archive_record_move_to_next)(c->f,state,c->pd))break;
 }
 (c->f->free_archive_records_reading)(c->f,state);
 if(pit&&end&&sxar_read(c,end,b,4)&&!xx_rt_memcmp(b,"PEnd",4)&&!sxar_add(c,&sxar_packit_marker,end))ok=false;
 return ok&&c->count!=0;}
static bool sxar_mpq(sx_context *c){uint8_t b[208];if(!sxar_read(c,0,b,32))return false;unsigned v=sxar16(b+12,false);const sx_layout *a[]={&sxar_mpq_header_v0,&sxar_mpq_header_v1,&sxar_mpq_header_v2,&sxar_mpq_header_v3};unsigned widths[]={32,44,68,208};if(v>3||!sxar_read(c,0,b,widths[v])||!sxar_add(c,a[v],0))return false;
 if(v==1){uint64_t p=sxar64(b+32),n=sxar32(b+28,false);if(p>=sxar32(b+4,false)&&p&&n<=SXAR_LIMIT&&sxar_span(c,p,n*2)&&!sx_table(c,&sxar_mpq_high_block_entry,(int64_t)p,2,n))return false;}return true;}
static int sxar_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxar_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxar_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxar_order);return !c->failed;}
static bool sx_archivemore_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_RTPATCH:case XX_FILE_TYPE_MPQ:case XX_FILE_TYPE_APPLESINGLE:case XX_FILE_TYPE_MACBINARY:case XX_FILE_TYPE_BINARYII:case XX_FILE_TYPE_NUFX:case XX_FILE_TYPE_PACKIT_MAC:case XX_FILE_TYPE_STUFFIT:case XX_FILE_TYPE_COMPACTPRO:case XX_FILE_TYPE_EGG:case XX_FILE_TYPE_LZFSE:case XX_FILE_TYPE_LZF_STREAM:case XX_FILE_TYPE_FASTLZ_SIXPACK:case XX_FILE_TYPE_LBR:case XX_FILE_TYPE_PDP11AR:case XX_FILE_TYPE_BIGAF:return true;default:return false;}}
static bool sx_archivemore_build(sx_context *c){if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_RTPATCH:ok=sxar_native_records(c,false);break;case XX_FILE_TYPE_MPQ:ok=sxar_mpq(c);break;case XX_FILE_TYPE_APPLESINGLE:ok=sxar_applesingle(c);break;case XX_FILE_TYPE_MACBINARY:ok=sxar_macbinary(c);break;case XX_FILE_TYPE_BINARYII:ok=sxar_binaryii(c);break;case XX_FILE_TYPE_NUFX:ok=sxar_nufx(c);break;case XX_FILE_TYPE_PACKIT_MAC:ok=sxar_native_records(c,true);break;case XX_FILE_TYPE_STUFFIT:ok=sxar_stuffit(c);break;case XX_FILE_TYPE_COMPACTPRO:ok=sxar_compactpro(c);break;case XX_FILE_TYPE_EGG:ok=sxar_egg(c);break;case XX_FILE_TYPE_LZFSE:ok=sxar_lzfse(c);break;case XX_FILE_TYPE_LZF_STREAM:ok=sxar_lzf(c);break;case XX_FILE_TYPE_FASTLZ_SIXPACK:ok=sxar_sixpack(c);break;case XX_FILE_TYPE_LBR:ok=sxar_lbr(c);break;case XX_FILE_TYPE_PDP11AR:ok=sxar_pdp11ar(c);break;case XX_FILE_TYPE_BIGAF:ok=sxar_bigaf(c);break;default:break;}return ok&&sxar_finish(c);}
