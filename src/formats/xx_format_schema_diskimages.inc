/* SPDX-License-Identifier: MIT
 * Physical disk-image metadata. See docs/data_struct_diskimages_scope.txt. */
static const xx_data_struct_field_desc sxdi_anadisk_sector_header_fields[] = {
    SX_FIELD("physical_cylinder","uint8",0,1,SX_ID),
    SX_FIELD("physical_head","uint8",1,1,SX_ID),
    SX_FIELD("logical_cylinder","uint8",2,1,SX_ID),
    SX_FIELD("logical_head","uint8",3,1,SX_ID),
    SX_FIELD("sector_id","uint8",4,1,SX_ID),
    SX_FIELD("size_code","uint8",5,1,SX_NONE),
    SX_FIELD("stored_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxdi_anadisk_sector_header = {UINT32_C(0x60150001),"anadisk_sector_header",sxdi_anadisk_sector_header_fields,SX_COUNT(sxdi_anadisk_sector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_transcopy_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("comment1","char[32]",2,32,SX_STRING),
    SX_FIELD("comment2","char[32]",34,32,SX_STRING),
};
static const sx_layout sxdi_transcopy_header = {UINT32_C(0x60150002),"transcopy_header",sxdi_transcopy_header_fields,SX_COUNT(sxdi_transcopy_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_transcopy_geometry_fields[] = {
    SX_FIELD("last_cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head_count","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxdi_transcopy_geometry = {UINT32_C(0x60150003),"transcopy_geometry",sxdi_transcopy_geometry_fields,SX_COUNT(sxdi_transcopy_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_transcopy_track_offset_fields[] = {
    SX_FIELD("offset_in_256_byte_units","uint16",0,2,SX_NONE),
};
static const sx_layout sxdi_transcopy_track_offset = {UINT32_C(0x60150004),"transcopy_track_offset",sxdi_transcopy_track_offset_fields,SX_COUNT(sxdi_transcopy_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_transcopy_track_length_fields[] = {
    SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxdi_transcopy_track_length = {UINT32_C(0x60150005),"transcopy_track_length",sxdi_transcopy_track_length_fields,SX_COUNT(sxdi_transcopy_track_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_copyqm_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("format_marker","uint8",2,1,SX_ID),
    SX_FIELD("sector_size","uint16",3,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("root_entries","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors16","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("media_type","uint8",13,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors32","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("description","char[60]",28,60,SX_STRING),
    SX_FIELD("blind_mode","uint8",88,1,SX_ID),
    SX_FIELD("density","uint8",89,1,SX_ID),
    SX_FIELD("used_cylinders","uint8",90,1,SX_COUNT_PROP),
    SX_FIELD("total_cylinders","uint8",91,1,SX_COUNT_PROP),
    SX_FIELD("decoded_data_crc","uint32",92,4,SX_CHECKSUM),
    SX_FIELD("volume_label","char[11]",96,11,SX_STRING),
    SX_FIELD("dos_time","uint16",107,2,SX_NONE),
    SX_FIELD("dos_date","uint16",109,2,SX_NONE),
    SX_FIELD("comment_size","uint16",111,2,SX_SIZE),
    SX_FIELD("first_sector_minus_one","uint8",113,1,SX_NONE),
    SX_FIELD("unknown_72","uint8[2]",114,2,SX_NONE),
    SX_FIELD("interleave","uint8",116,1,SX_NONE),
    SX_FIELD("skew","int8",117,1,SX_NONE),
    SX_FIELD("source_drive_type","uint8",118,1,SX_ID),
    SX_FIELD("unknown_77","uint8[13]",119,13,SX_NONE),
    SX_FIELD("header_checksum","uint8",132,1,SX_CHECKSUM),
};
static const sx_layout sxdi_copyqm_header = {UINT32_C(0x60150006),"copyqm_header",sxdi_copyqm_header_fields,SX_COUNT(sxdi_copyqm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_copyqm_rle_token_fields[] = {
    SX_FIELD("signed_run_length","int16",0,2,SX_NONE),
};
static const sx_layout sxdi_copyqm_rle_token = {UINT32_C(0x60150007),"copyqm_rle_token",sxdi_copyqm_rle_token_fields,SX_COUNT(sxdi_copyqm_rle_token_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_disk_fill_byte_fields[] = {
    SX_FIELD("fill_value","uint8",0,1,SX_ID),
};
static const sx_layout sxdi_disk_fill_byte = {UINT32_C(0x60150008),"disk_fill_byte",sxdi_disk_fill_byte_fields,SX_COUNT(sxdi_disk_fill_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_track_header_fields[] = {
    SX_FIELD("mode","uint8",0,1,SX_ID),
    SX_FIELD("cylinder","uint8",1,1,SX_ID),
    SX_FIELD("head_and_maps","uint8",2,1,SX_FLAGS),
    SX_FIELD("sector_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_code","uint8",4,1,SX_NONE),
};
static const sx_layout sxdi_imd_track_header = {UINT32_C(0x60150009),"imd_track_header",sxdi_imd_track_header_fields,SX_COUNT(sxdi_imd_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_sector_id_fields[] = {
    SX_FIELD("sector_id","uint8",0,1,SX_ID),
};
static const sx_layout sxdi_imd_sector_id = {UINT32_C(0x6015000a),"imd_sector_id",sxdi_imd_sector_id_fields,SX_COUNT(sxdi_imd_sector_id_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_cylinder_map_fields[] = {
    SX_FIELD("cylinder_id","uint8",0,1,SX_ID),
};
static const sx_layout sxdi_imd_cylinder_map = {UINT32_C(0x6015000b),"imd_cylinder_map",sxdi_imd_cylinder_map_fields,SX_COUNT(sxdi_imd_cylinder_map_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_head_map_fields[] = {
    SX_FIELD("head_id","uint8",0,1,SX_ID),
};
static const sx_layout sxdi_imd_head_map = {UINT32_C(0x6015000c),"imd_head_map",sxdi_imd_head_map_fields,SX_COUNT(sxdi_imd_head_map_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_size_map_fields[] = {
    SX_FIELD("sector_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxdi_imd_size_map = {UINT32_C(0x6015000d),"imd_size_map",sxdi_imd_size_map_fields,SX_COUNT(sxdi_imd_size_map_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_sector_status_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
};
static const sx_layout sxdi_imd_sector_status = {UINT32_C(0x6015000e),"imd_sector_status",sxdi_imd_sector_status_fields,SX_COUNT(sxdi_imd_sector_status_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_fdi_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("write_protected","uint8",3,1,SX_FLAGS),
    SX_FIELD("cylinders","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("text_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("data_offset","uint16",10,2,SX_OFFSET),
    SX_FIELD("extra_header_size","uint16",12,2,SX_SIZE),
};
static const sx_layout sxdi_fdi_header = {UINT32_C(0x6015000f),"fdi_header",sxdi_fdi_header_fields,SX_COUNT(sxdi_fdi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_fdi_track_header_fields[] = {
    SX_FIELD("track_data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
    SX_FIELD("sector_count","uint8",6,1,SX_COUNT_PROP),
};
static const sx_layout sxdi_fdi_track_header = {UINT32_C(0x60150010),"fdi_track_header",sxdi_fdi_track_header_fields,SX_COUNT(sxdi_fdi_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_fdi_sector_header_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("data_offset","uint16",5,2,SX_OFFSET),
};
static const sx_layout sxdi_fdi_sector_header = {UINT32_C(0x60150011),"fdi_sector_header",sxdi_fdi_sector_header_fields,SX_COUNT(sxdi_fdi_sector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_nec_pc98_fdi_header_fields[] = {
    SX_FIELD("reserved","uint32",0,4,SX_RESERVED),
    SX_FIELD("floppy_type","uint32",4,4,SX_ID),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("data_size","uint32",12,4,SX_SIZE),
    SX_FIELD("sector_size","uint32",16,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("head_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxdi_nec_pc98_fdi_header = {UINT32_C(0x60150012),"nec_pc98_fdi_header",sxdi_nec_pc98_fdi_header_fields,SX_COUNT(sxdi_nec_pc98_fdi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("volume_sequence","uint8",2,1,SX_ID),
    SX_FIELD("volume_id","uint8",3,1,SX_ID),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("rate_and_fm","uint8",5,1,SX_FLAGS),
    SX_FIELD("drive_type","uint8",6,1,SX_ID),
    SX_FIELD("stepping_and_comment","uint8",7,1,SX_FLAGS),
    SX_FIELD("dos_allocation_mode","uint8",8,1,SX_FLAGS),
    SX_FIELD("head_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("header_crc","uint16",10,2,SX_CHECKSUM),
};
static const sx_layout sxdi_teledisk_header = {UINT32_C(0x60150013),"teledisk_header",sxdi_teledisk_header_fields,SX_COUNT(sxdi_teledisk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_comment_fields[] = {
    SX_FIELD("crc","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("text_size","uint16",2,2,SX_SIZE),
    SX_FIELD("year_since_1900","uint8",4,1,SX_NONE),
    SX_FIELD("month_zero_based","uint8",5,1,SX_NONE),
    SX_FIELD("day","uint8",6,1,SX_NONE),
    SX_FIELD("hour","uint8",7,1,SX_NONE),
    SX_FIELD("minute","uint8",8,1,SX_NONE),
    SX_FIELD("second","uint8",9,1,SX_NONE),
};
static const sx_layout sxdi_teledisk_comment = {UINT32_C(0x60150014),"teledisk_comment",sxdi_teledisk_comment_fields,SX_COUNT(sxdi_teledisk_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_track_fields[] = {
    SX_FIELD("sector_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("cylinder","uint8",1,1,SX_ID),
    SX_FIELD("head_and_fm","uint8",2,1,SX_FLAGS),
    SX_FIELD("header_crc_low","uint8",3,1,SX_CHECKSUM),
};
static const sx_layout sxdi_teledisk_track = {UINT32_C(0x60150015),"teledisk_track",sxdi_teledisk_track_fields,SX_COUNT(sxdi_teledisk_track_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_end_fields[] = {
    SX_FIELD("end_marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxdi_teledisk_end = {UINT32_C(0x60150016),"teledisk_end",sxdi_teledisk_end_fields,SX_COUNT(sxdi_teledisk_end_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_sector_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("crc_low","uint8",5,1,SX_CHECKSUM),
};
static const sx_layout sxdi_teledisk_sector = {UINT32_C(0x60150017),"teledisk_sector",sxdi_teledisk_sector_fields,SX_COUNT(sxdi_teledisk_sector_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_data_block_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
    SX_FIELD("method","uint8",2,1,SX_ID),
};
static const sx_layout sxdi_teledisk_data_block = {UINT32_C(0x60150018),"teledisk_data_block",sxdi_teledisk_data_block_fields,SX_COUNT(sxdi_teledisk_data_block_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_d88_disk_header_fields[] = {
    SX_FIELD("disk_name","char[17]",0,17,SX_STRING),
    SX_FIELD("reserved","uint8[9]",17,9,SX_RESERVED),
    SX_FIELD("write_protect","uint8",26,1,SX_FLAGS),
    SX_FIELD("media_type","uint8",27,1,SX_ID),
    SX_FIELD("disk_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxdi_d88_disk_header = {UINT32_C(0x60150019),"d88_disk_header",sxdi_d88_disk_header_fields,SX_COUNT(sxdi_d88_disk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_d88_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdi_d88_track_offset = {UINT32_C(0x6015001a),"d88_track_offset",sxdi_d88_track_offset_fields,SX_COUNT(sxdi_d88_track_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_d88_sector_header_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("sector_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("density","uint8",6,1,SX_ID),
    SX_FIELD("deleted_mark","uint8",7,1,SX_FLAGS),
    SX_FIELD("status","uint8",8,1,SX_ID),
    SX_FIELD("reserved","uint8[5]",9,5,SX_RESERVED),
    SX_FIELD("stored_size","uint16",14,2,SX_SIZE),
};
static const sx_layout sxdi_d88_sector_header = {UINT32_C(0x6015001b),"d88_sector_header",sxdi_d88_sector_header_fields,SX_COUNT(sxdi_d88_sector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_ipf_chunk_header_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
static const sx_layout sxdi_ipf_chunk_header = {UINT32_C(0x6015001c),"ipf_chunk_header",sxdi_ipf_chunk_header_fields,SX_COUNT(sxdi_ipf_chunk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_info_fields[] = {
    SX_FIELD("image_type","uint32",0,4,SX_ID),
    SX_FIELD("encoder","uint32",4,4,SX_ID),
    SX_FIELD("encoder_revision","uint32",8,4,SX_ID),
    SX_FIELD("release","uint32",12,4,SX_ID),
    SX_FIELD("revision","uint32",16,4,SX_ID),
    SX_FIELD("origin","uint32",20,4,SX_ID),
    SX_FIELD("min_cylinder","uint32",24,4,SX_ID),
    SX_FIELD("max_cylinder","uint32",28,4,SX_ID),
    SX_FIELD("min_head","uint32",32,4,SX_ID),
    SX_FIELD("max_head","uint32",36,4,SX_ID),
    SX_FIELD("creation_date","uint32",40,4,SX_NONE),
    SX_FIELD("creation_time","uint32",44,4,SX_NONE),
    SX_FIELD("platforms","uint32[4]",48,16,SX_ID),
    SX_FIELD("disk_number","uint32",64,4,SX_ID),
    SX_FIELD("user_id","uint32",68,4,SX_ID),
    SX_FIELD("reserved","uint32[3]",72,12,SX_RESERVED),
};
static const sx_layout sxdi_ipf_info = {UINT32_C(0x6015001d),"ipf_info",sxdi_ipf_info_fields,SX_COUNT(sxdi_ipf_info_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_image_fields[] = {
    SX_FIELD("cylinder","uint32",0,4,SX_ID),
    SX_FIELD("head","uint32",4,4,SX_ID),
    SX_FIELD("density_type","uint32",8,4,SX_ID),
    SX_FIELD("signal_type","uint32",12,4,SX_ID),
    SX_FIELD("track_size_rounded","uint32",16,4,SX_NONE),
    SX_FIELD("start_position_rounded","uint32",20,4,SX_NONE),
    SX_FIELD("start_bit","uint32",24,4,SX_NONE),
    SX_FIELD("data_bits","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("gap_bits","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("track_bits","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("process","uint32",44,4,SX_ID),
    SX_FIELD("flags","uint32",48,4,SX_FLAGS),
    SX_FIELD("data_key","uint32",52,4,SX_ID),
    SX_FIELD("reserved","uint32[3]",56,12,SX_RESERVED),
};
static const sx_layout sxdi_ipf_image = {UINT32_C(0x6015001e),"ipf_image",sxdi_ipf_image_fields,SX_COUNT(sxdi_ipf_image_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_data_fields[] = {
    SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
    SX_FIELD("payload_bits","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("payload_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("data_key","uint32",12,4,SX_ID),
};
static const sx_layout sxdi_ipf_data = {UINT32_C(0x6015001f),"ipf_data",sxdi_ipf_data_fields,SX_COUNT(sxdi_ipf_data_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_block_encoder1_fields[] = {
    SX_FIELD("data_bits","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("gap_bits","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("decoded_block_size_rounded","uint32",8,4,SX_NONE),
    SX_FIELD("decoded_gap_size_rounded","uint32",12,4,SX_NONE),
    SX_FIELD("encoding_type","uint32",16,4,SX_ID),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("gap_value","uint32",24,4,SX_ID),
    SX_FIELD("data_offset","uint32",28,4,SX_OFFSET),
};
static const sx_layout sxdi_ipf_block_encoder1 = {UINT32_C(0x60150020),"ipf_block_encoder1",sxdi_ipf_block_encoder1_fields,SX_COUNT(sxdi_ipf_block_encoder1_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_block_encoder2_fields[] = {
    SX_FIELD("data_bits","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("gap_bits","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("gap_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("cell_type","uint32",12,4,SX_ID),
    SX_FIELD("encoding_type","uint32",16,4,SX_ID),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("gap_value","uint32",24,4,SX_ID),
    SX_FIELD("data_offset","uint32",28,4,SX_OFFSET),
};
static const sx_layout sxdi_ipf_block_encoder2 = {UINT32_C(0x60150021),"ipf_block_encoder2",sxdi_ipf_block_encoder2_fields,SX_COUNT(sxdi_ipf_block_encoder2_fields),SX_BE};
static const sx_layout *const sx_diskimages_layouts[] = {
    &sxdi_anadisk_sector_header,
    &sxdi_transcopy_header,
    &sxdi_transcopy_geometry,
    &sxdi_transcopy_track_offset,
    &sxdi_transcopy_track_length,
    &sxdi_copyqm_header,
    &sxdi_copyqm_rle_token,
    &sxdi_disk_fill_byte,
    &sxdi_imd_track_header,
    &sxdi_imd_sector_id,
    &sxdi_imd_cylinder_map,
    &sxdi_imd_head_map,
    &sxdi_imd_size_map,
    &sxdi_imd_sector_status,
    &sxdi_fdi_header,
    &sxdi_fdi_track_header,
    &sxdi_fdi_sector_header,
    &sxdi_nec_pc98_fdi_header,
    &sxdi_teledisk_header,
    &sxdi_teledisk_comment,
    &sxdi_teledisk_track,
    &sxdi_teledisk_end,
    &sxdi_teledisk_sector,
    &sxdi_teledisk_data_block,
    &sxdi_d88_disk_header,
    &sxdi_d88_track_offset,
    &sxdi_d88_sector_header,
    &sxdi_ipf_chunk_header,
    &sxdi_ipf_info,
    &sxdi_ipf_image,
    &sxdi_ipf_data,
    &sxdi_ipf_block_encoder1,
    &sxdi_ipf_block_encoder2,
};
static bool sx_diskimages_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60150000U||id>=0x60160000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60150001U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))text=L"Encoded nominal sector size: 128 << value; stored payload length is independent.";
        break;
    case 0x60150003U:
        if(!xx_rt_wcscmp(r->name,L"last_cylinder"))text=L"Zero-based last cylinder, not a cylinder count.";
        break;
    case 0x60150004U:
        if(!xx_rt_wcscmp(r->name,L"offset_in_256_byte_units"))text=L"File byte offset = value << 8; zero marks an absent track.";
        break;
    case 0x60150005U:
        if(!xx_rt_wcscmp(r->name,L"byte_length"))text=L"Absent tracks may retain the original 0x3333 filler; offset zero takes precedence.";
        break;
    case 0x60150006U:
        if(!xx_rt_wcscmp(r->name,L"blind_mode"))text=L"0=DOS, 1=blind copy, 2=HFS.";
        if(!xx_rt_wcscmp(r->name,L"density"))text=L"0=double, 1=high, 2=extended.";
        if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time: hours bits11..15, minutes bits5..10, two-second units bits0..4.";
        if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date: year since1980 bits9..15, month bits5..8, day bits0..4.";
        if(!xx_rt_wcscmp(r->name,L"first_sector_minus_one"))text=L"First sector ID is this encoded value plus one.";
        if(!xx_rt_wcscmp(r->name,L"skew"))text=L"Signed track skew; negative values select alternating sides.";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"Sum of all 133 header bytes modulo256 is zero.";
        break;
    case 0x60150007U:
        if(!xx_rt_wcscmp(r->name,L"signed_run_length"))text=L"Positive: literal byte count; negative: repeat next byte -value times; zero: end marker.";
        break;
    case 0x60150008U:
        if(!xx_rt_wcscmp(r->name,L"fill_value"))text=L"Repeated byte stored physically once; expanded bytes have no file offsets.";
        break;
    case 0x60150009U:
        if(!xx_rt_wcscmp(r->name,L"mode"))text=L"ImageDisk data-rate and recording-mode code.";
        if(!xx_rt_wcscmp(r->name,L"head_and_maps"))text=L"Bit0=head, bit6=head map present, bit7=cylinder map present.";
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))text=L"0..6: 128 << value bytes; 255: per-sector uint16 size map follows.";
        break;
    case 0x6015000eU:
        if(!xx_rt_wcscmp(r->name,L"status"))text=L"0=unavailable; 1/3/5/7=stored; 2/4/6/8=fill; variants encode deleted-data and error status.";
        break;
    case 0x6015000fU:
        if(!xx_rt_wcscmp(r->name,L"write_protected"))text=L"0=write enabled, 1=write protected.";
        break;
    case 0x60150010U:
        if(!xx_rt_wcscmp(r->name,L"track_data_offset"))text=L"Byte offset relative to the file header data_offset, not absolute.";
        break;
    case 0x60150011U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))text=L"Nominal sector size is 128 << value bytes.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit7=deleted data; bits0..5 record valid CRC for 128 through4096-byte reads; bit6 reserved.";
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to this track data area.";
        break;
    case 0x60150013U:
        if(!xx_rt_wcscmp(r->name,L"signature"))text=L"TD=uncompressed physical records; td=whole-body compressed.";
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"Decimal version multiplied by10.";
        if(!xx_rt_wcscmp(r->name,L"rate_and_fm"))text=L"Low7 bits: 0=250,1=300,2=500 kbit/s; bit7=FM.";
        if(!xx_rt_wcscmp(r->name,L"stepping_and_comment"))text=L"Low bits describe drive/media stepping; bit7 marks an optional comment.";
        break;
    case 0x60150014U:
        if(!xx_rt_wcscmp(r->name,L"year_since_1900"))text=L"Calendar component; not a Unix timestamp.";
        break;
    case 0x60150015U:
        if(!xx_rt_wcscmp(r->name,L"head_and_fm"))text=L"Low bits identify head; bit7 is FM.";
        break;
    case 0x60150017U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))text=L"Nominal sector size is 128 << value bytes.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bits4/5 omit data; other bits preserve duplicate, CRC, deleted and skipped-sector status.";
        break;
    case 0x60150018U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size"))text=L"Number of bytes beginning with the method byte, including that method.";
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=literal, 1=two-byte pattern, 2=RLE fragments.";
        break;
    case 0x6015001aU:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))text=L"Byte offset from the start of the containing disk image; zero means no track.";
        break;
    case 0x6015001bU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))text=L"Encoded nominal size: 128 << value; actual stored size is separate.";
        break;
    case 0x6015001cU:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Includes the12-byte chunk header; DATA payload follows outside this size.";
        if(!xx_rt_wcscmp(r->name,L"header_crc"))text=L"CRC calculated with this field zero.";
        break;
    case 0x6015001dU:
        if(!xx_rt_wcscmp(r->name,L"creation_date"))text=L"Decimal packed calendar date YYYYMMDD; not Unix seconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Decimal packed time HHMMSSTTT; final3 digits are milliseconds.";
        break;
    case 0x6015001eU:
        if(!xx_rt_wcscmp(r->name,L"track_size_rounded"))text=L"Rounded decoded track-size quantity as stored by the encoder.";
        if(!xx_rt_wcscmp(r->name,L"start_position_rounded"))text=L"Rounded decoded start position; not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"start_bit"))text=L"Position in decoded track bits; not a file byte offset.";
        break;
    case 0x60150020U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to DATA payload.";
        break;
    case 0x60150021U:
        if(!xx_rt_wcscmp(r->name,L"gap_offset"))text=L"Byte offset relative to DATA payload.";
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to DATA payload.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}

static bool sxdi_span(sx_context *c,uint64_t at,uint64_t n){return c->size>=0&&at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
static bool sxdi_read(sx_context *c,uint64_t at,void *p,size_t n){return sxdi_span(c,at,n)&&sx_read(c,(int64_t)at,p,n);}
static uint16_t sxdi_le16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
static uint32_t sxdi_le32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
static uint32_t sxdi_be32(const uint8_t *p){return xx_data_get_u32(p,4,0,true);}
static bool sxdi_ana(sx_context *c)
{
    uint64_t at=0;unsigned count=0;
    while(at<(uint64_t)c->size&&count<65536){uint8_t h[8];if(!sxdi_read(c,at,h,8))return count!=0;uint32_t n=sxdi_le16(h+6);
        if(!sxdi_span(c,at+8,n))return count!=0;if(!sx_add(c,&sxdi_anadisk_sector_header,(int64_t)at,8))return false;count++;at+=8+n;
    }return count!=0;
}
static bool sxdi_tc(sx_context *c)
{
    uint8_t h[4];if(c->size<16384||!sxdi_read(c,0,h,2)||h[0]!=0x5a||h[1]!=0xa5||!sxdi_read(c,258,h,2)||h[0]>=99||!h[1]||h[1]>2)return false;
    return sx_add(c,&sxdi_transcopy_header,0,66)&&sx_add(c,&sxdi_transcopy_geometry,258,2)&&sx_table(c,&sxdi_transcopy_track_offset,0x305,2,256)&&sx_table(c,&sxdi_transcopy_track_length,0x505,2,256);
}
static bool sxdi_cqm(sx_context *c)
{
    uint8_t h[133];if(!sxdi_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"CQ\024",3)||!sx_add(c,&sxdi_copyqm_header,0,133))return false;
    uint64_t at=133U+sxdi_le16(h+111);if(at>(uint64_t)c->size)return true;
    for(unsigned i=0;i<8192&&at<(uint64_t)c->size;i++){uint8_t b[2];if(!sxdi_read(c,at,b,2))break;
        int32_t n=(int16_t)sxdi_le16(b);if(!sx_add(c,&sxdi_copyqm_rle_token,(int64_t)at,2))return false;at+=2;if(!n)break;
        if(n<0){if(!sxdi_span(c,at,1))break;if(!sx_add(c,&sxdi_disk_fill_byte,(int64_t)at,1))return false;at++;}
        else {if(!sxdi_span(c,at,(unsigned)n))break;at+=(unsigned)n;}
    }return true;
}
static bool sxdi_imd(sx_context *c)
{
    uint8_t b[1024];size_t n=c->size<1024?(size_t)c->size:1024;uint64_t at=0;unsigned tracks=0,sectors=0;
    if(n<4||!sxdi_read(c,0,b,n)||xx_rt_memcmp(b,"IMD ",4))return false;
    while(at<n&&b[at]!=0x1a)at++;if(at==n)return false;at++;
    while(at<(uint64_t)c->size&&tracks<4096&&sectors<32768){uint8_t h[5];uint64_t sizes=0;uint32_t fixed=0;
        if(!sxdi_read(c,at,h,5)||(h[0]>6&&h[0]!=9)||!h[3]||(h[2]&0x3e)||(h[4]>6&&h[4]!=255))return tracks!=0;
        uint64_t prefix=5+(uint64_t)h[3]*(1+((h[2]&128)!=0)+((h[2]&64)!=0)+(h[4]==255?2:0));
        if(!sxdi_span(c,at,prefix))return tracks!=0;
        if(!sx_add(c,&sxdi_imd_track_header,(int64_t)at,5))return false;tracks++;at+=5;
        if(!sx_table(c,&sxdi_imd_sector_id,(int64_t)at,1,h[3]))return false;at+=h[3];
        if(h[2]&128){if(!sx_table(c,&sxdi_imd_cylinder_map,(int64_t)at,1,h[3]))return false;at+=h[3];}
        if(h[2]&64){if(!sx_table(c,&sxdi_imd_head_map,(int64_t)at,1,h[3]))return false;at+=h[3];}
        if(h[4]==255){sizes=at;if(!sx_table(c,&sxdi_imd_size_map,(int64_t)at,2,h[3]))return false;at+=(uint64_t)h[3]*2;}else fixed=128U<<h[4];
        for(unsigned j=0;j<h[3]&&sectors<32768;j++){uint8_t status;uint16_t z=0;uint32_t len=fixed;
            if(sizes){if(!sx_u16(c,(int64_t)(sizes+j*2),false,&z))return false;len=z;}
            if(!len||len>8192||!sxdi_read(c,at,&status,1)||status>8)return true;
            if(!sx_add(c,&sxdi_imd_sector_status,(int64_t)at,1))return false;at++;sectors++;
            if(!status)continue;
            if(!(status&1)){if(!sxdi_span(c,at,1))return true;if(!sx_add(c,&sxdi_disk_fill_byte,(int64_t)at,1))return false;at++;}
            else {if(!sxdi_span(c,at,len))return true;at+=len;}
        }
    }return tracks!=0;
}
static bool sxdi_fdi(sx_context *c)
{
    uint8_t h[14];if(!sxdi_read(c,0,h,14)||xx_rt_memcmp(h,"FDI",3)||!sx_add(c,&sxdi_fdi_header,0,14))return false;
    uint32_t cyl=sxdi_le16(h+4),heads=sxdi_le16(h+6);uint64_t at=14U+sxdi_le16(h+12),limit=sxdi_le16(h+10),text=sxdi_le16(h+8);
    if(!cyl||cyl>256||!heads||heads>2||at>limit||limit>(uint64_t)c->size)return true;if(text>=at&&text<limit)limit=text;
    for(uint32_t i=0;i<cyl*heads;i++){uint8_t t[7];if(at>limit||limit-at<7||!sxdi_read(c,at,t,7))break;uint64_t bytes=7U+(uint64_t)t[6]*7;
        if(bytes>limit-at)break;if(!sx_add(c,&sxdi_fdi_track_header,(int64_t)at,7))return false;
        if(t[6]&&!sx_table(c,&sxdi_fdi_sector_header,(int64_t)at+7,7,t[6]))return false;at+=bytes;
    }return true;
}
static bool sxdi_necfdi(sx_context *c)
{
    uint8_t h[32];if(!sxdi_read(c,0,h,32)||sxdi_le32(h)||sxdi_le32(h+8)<32)return false;
    return sx_add(c,&sxdi_nec_pc98_fdi_header,0,32);
}
static bool sxdi_td(sx_context *c)
{
    uint8_t h[12];if(!sxdi_read(c,0,h,12)||(xx_rt_memcmp(h,"TD",2)&&xx_rt_memcmp(h,"td",2))||!sx_add(c,&sxdi_teledisk_header,0,12))return false;
    if(h[0]=='t')return true;uint64_t at=12;unsigned sectors=0;
    if(h[7]&128){uint8_t m[10];if(!sxdi_read(c,at,m,10))return true;if(!sx_add(c,&sxdi_teledisk_comment,(int64_t)at,10))return false;at+=10+sxdi_le16(m+2);if(at>(uint64_t)c->size)return true;}
    for(unsigned i=0;i<4096&&sectors<32768&&at<(uint64_t)c->size;i++){uint8_t t[4];if(!sxdi_read(c,at,t,4))break;
        if(t[0]==255)return sx_add(c,&sxdi_teledisk_end,(int64_t)at,1);
        if(!sx_add(c,&sxdi_teledisk_track,(int64_t)at,4))return false;at+=4;
        for(unsigned j=0;j<t[0]&&sectors<32768;j++){uint8_t s[6];if(!sxdi_read(c,at,s,6)||s[3]>7)return true;
            if(!sx_add(c,&sxdi_teledisk_sector,(int64_t)at,6))return false;at+=6;sectors++;
            if(!(s[4]&0x30)){uint8_t d[3];if(!sxdi_read(c,at,d,3))return true;uint32_t n=sxdi_le16(d);if(!n||!sxdi_span(c,at,2U+n))return true;
                if(!sx_add(c,&sxdi_teledisk_data_block,(int64_t)at,3))return false;at+=2U+n;
            }
        }
    }return true;
}
static bool sxdi_d88(sx_context *c)
{
    uint64_t base=0;unsigned disks=0,sectors=0;
    while(base<(uint64_t)c->size&&disks<256&&sectors<32768){uint8_t h[32];uint32_t offsets[164],first=0;unsigned count=160;
        if(!sxdi_read(c,base,h,32))return disks!=0;uint32_t size=sxdi_le32(h+28);
        if(size<672||!sxdi_span(c,base,size))return disks!=0;
        for(unsigned i=0;i<160;i++){if(!sx_u32(c,(int64_t)(base+32+i*4),false,&offsets[i]))return false;if(offsets[i]&&!first)first=offsets[i];}
        if(first==688)count=164;else if(first!=672)return disks!=0;
        if(size<first)return disks!=0;for(unsigned i=160;i<count;i++)if(!sx_u32(c,(int64_t)(base+32+i*4),false,&offsets[i]))return false;
        uint32_t prev=0;for(unsigned i=0;i<count;i++)if(offsets[i]){if(offsets[i]<first||offsets[i]>size||(prev&&offsets[i]<prev))return disks!=0;prev=offsets[i];}
        if(!sx_add(c,&sxdi_d88_disk_header,(int64_t)base,32)||!sx_table(c,&sxdi_d88_track_offset,(int64_t)base+32,4,count))return false;disks++;
        for(unsigned i=0;i<count&&sectors<32768;i++){uint64_t at=offsets[i],end=size;if(!at||at==size)continue;
            for(unsigned j=i+1;j<count;j++)if(offsets[j]){end=offsets[j];break;}if(at>=end)continue;
            uint8_t s[16];if(end-at<16||!sxdi_read(c,base+at,s,16))continue;unsigned n=sxdi_le16(s+4);if(!n||n>128)continue;
            for(unsigned j=0;j<n&&sectors<32768;j++){if(end-at<16||!sxdi_read(c,base+at,s,16))break;uint32_t z=sxdi_le16(s+14);if(z>end-at-16)break;
                if(!sx_add(c,&sxdi_d88_sector_header,(int64_t)(base+at),16))return false;at+=16+z;sectors++;
            }
        }base+=size;
    }return disks!=0;
}
static bool sxdi_ipf(sx_context *c)
{
    uint64_t at=0;uint32_t encoder=0,keys[170],counts[170];size_t tracks=0;
    while(at<(uint64_t)c->size&&c->count+3<=32768){uint8_t h[12];if(!sxdi_read(c,at,h,12))return at!=0;uint32_t n=sxdi_be32(h+4);if(n<12||!sxdi_span(c,at,n)||(!at&&xx_rt_memcmp(h,"CAPS",4)))return at!=0;
        if(!sx_add(c,&sxdi_ipf_chunk_header,(int64_t)at,12))return false;uint64_t q=at+12,end=at+n;
        if(!xx_rt_memcmp(h,"INFO",4)&&n>=96){if(!sx_add(c,&sxdi_ipf_info,(int64_t)q,84)||!sx_u32(c,(int64_t)q+4,true,&encoder))return false;}
        else if(!xx_rt_memcmp(h,"IMGE",4)&&n>=80){if(!sx_add(c,&sxdi_ipf_image,(int64_t)q,68))return false;
            if(tracks<170){if(!sx_u32(c,(int64_t)q+52,true,&keys[tracks])||!sx_u32(c,(int64_t)q+40,true,&counts[tracks]))return false;tracks++;}
        }else if(!xx_rt_memcmp(h,"DATA",4)&&n>=28){uint8_t d[16];if(!sxdi_read(c,q,d,16)||!sx_add(c,&sxdi_ipf_data,(int64_t)q,16))return false;uint32_t bytes=sxdi_be32(d),key=sxdi_be32(d+12);if(!sxdi_span(c,end,bytes))return true;
            if(encoder==1||encoder==2)for(size_t j=0;j<tracks;j++)if(keys[j]==key){uint32_t blocks=counts[j];if(blocks&&blocks<=256&&(uint64_t)blocks*32<=bytes&&!sx_table(c,encoder==1?&sxdi_ipf_block_encoder1:&sxdi_ipf_block_encoder2,(int64_t)end,32,blocks))return false;break;}
            end+=bytes;
        }
        at=end;if(c->count>=32768)break;
    }return at!=0;
}
static int sxdi_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxdi_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxdi_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdi_order);return !c->failed;
}
static bool sx_diskimages_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_PCE_ANADISK:case XX_FILE_TYPE_PCE_TC:case XX_FILE_TYPE_COPYQM:case XX_FILE_TYPE_IMD:case XX_FILE_TYPE_FDI:case XX_FILE_TYPE_NEC_PC_98_FDI:case XX_FILE_TYPE_TELEDISK:case XX_FILE_TYPE_PC98_D88:case XX_FILE_TYPE_AMIGA_IPF:return true;default:return false;}
}
static bool sx_diskimages_build(sx_context *c)
{
    bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_PCE_ANADISK:ok=sxdi_ana(c);break;case XX_FILE_TYPE_PCE_TC:ok=sxdi_tc(c);break;case XX_FILE_TYPE_COPYQM:ok=sxdi_cqm(c);break;case XX_FILE_TYPE_IMD:ok=sxdi_imd(c);break;case XX_FILE_TYPE_FDI:ok=sxdi_fdi(c);break;case XX_FILE_TYPE_NEC_PC_98_FDI:ok=sxdi_necfdi(c);break;case XX_FILE_TYPE_TELEDISK:ok=sxdi_td(c);break;case XX_FILE_TYPE_PC98_D88:ok=sxdi_d88(c);break;case XX_FILE_TYPE_AMIGA_IPF:ok=sxdi_ipf(c);break;default:break;}return ok&&sxdi_finish(c);
}
