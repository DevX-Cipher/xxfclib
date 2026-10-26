/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy disk image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_disklegacy_scope.txt. */

static const xx_data_struct_field_desc sxdleg_shrinkwrap_header_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("disk_name","char[63]",1,63,SX_NONE),
    SX_FIELD("data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("tag_size","uint32",68,4,SX_SIZE),
    SX_FIELD("data_checksum","uint32",72,4,SX_CHECKSUM),
    SX_FIELD("tag_checksum","uint32",76,4,SX_CHECKSUM),
    SX_FIELD("disk_format","uint8",80,1,SX_ID),
    SX_FIELD("format_byte","uint8",81,1,SX_ID),
    SX_FIELD("private_word","uint16",82,2,SX_ID),
};
static const sx_layout sxdleg_shrinkwrap_header = {0x60750001U,"shrinkwrap_header",sxdleg_shrinkwrap_header_fields,SX_COUNT(sxdleg_shrinkwrap_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_jv3_sector_descriptor_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("sector_id","uint8",1,1,SX_ID),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxdleg_jv3_sector_descriptor = {0x60750002U,"jv3_sector_descriptor",sxdleg_jv3_sector_descriptor_fields,SX_COUNT(sxdleg_jv3_sector_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_jv3_write_protection_fields[] = {
    SX_FIELD("write_protection","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxdleg_jv3_write_protection = {0x60750003U,"jv3_write_protection",sxdleg_jv3_write_protection_fields,SX_COUNT(sxdleg_jv3_write_protection_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_x68000_dim_header_fields[] = {
    SX_FIELD("media_type","uint8",0,1,SX_ID),
    SX_FIELD("track_present","uint8[170]",1,170,SX_NONE),
    SX_FIELD("signature","char[11]",171,11,SX_SIGNATURE),
    SX_FIELD("producer_metadata","byte[73]",182,73,SX_NONE),
    SX_FIELD("overtrack_flag","uint8",255,1,SX_FLAGS),
};
static const sx_layout sxdleg_x68000_dim_header = {0x60750004U,"x68000_dim_header",sxdleg_x68000_dim_header_fields,SX_COUNT(sxdleg_x68000_dim_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_dart_header_fields[] = {
    SX_FIELD("compression","uint8",0,1,SX_ID),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("disk_size_kib","uint16",2,2,SX_NONE),
};
static const sx_layout sxdleg_dart_header = {0x60750005U,"dart_header",sxdleg_dart_header_fields,SX_COUNT(sxdleg_dart_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_dart_block_length_fields[] = {
    SX_FIELD("encoded_length","uint16",0,2,SX_NONE),
};
static const sx_layout sxdleg_dart_block_length = {0x60750006U,"dart_block_length",sxdleg_dart_block_length_fields,SX_COUNT(sxdleg_dart_block_length_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_mds2_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version_major","uint8",16,1,SX_ID),
    SX_FIELD("version_minor","uint8",17,1,SX_ID),
    SX_FIELD("copyright","char[26]",18,26,SX_NONE),
    SX_FIELD("key_header_offset","uint32",44,4,SX_OFFSET),
};
static const sx_layout sxdleg_mds2_header = {0x60750007U,"mds2_header",sxdleg_mds2_header_fields,SX_COUNT(sxdleg_mds2_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_mdx_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version_major","uint8",16,1,SX_ID),
    SX_FIELD("version_minor","uint8",17,1,SX_ID),
    SX_FIELD("copyright","char[26]",18,26,SX_NONE),
    SX_FIELD("mdx_marker","uint32",44,4,SX_ID),
    SX_FIELD("descriptor_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("descriptor_span","uint64",56,8,SX_SIZE),
};
static const sx_layout sxdleg_mdx_header = {0x60750008U,"mdx_header",sxdleg_mdx_header_fields,SX_COUNT(sxdleg_mdx_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_mdx_key_salt_fields[] = {
    SX_FIELD("salt","byte[64]",0,64,SX_NONE),
};
static const sx_layout sxdleg_mdx_key_salt = {0x60750009U,"mdx_key_salt",sxdleg_mdx_key_salt_fields,SX_COUNT(sxdleg_mdx_key_salt_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("subtype","byte[4]",4,4,SX_SIGNATURE),
    SX_FIELD("used_head_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("free_head_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("track_directory_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxdleg_ldbs_header = {0x6075000aU,"ldbs_header",sxdleg_ldbs_header_fields,SX_COUNT(sxdleg_ldbs_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_block_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("block_type","byte[4]",4,4,SX_ID),
    SX_FIELD("allocated_size","uint32",8,4,SX_SIZE),
    SX_FIELD("used_size","uint32",12,4,SX_SIZE),
    SX_FIELD("next_block_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxdleg_ldbs_block_header = {0x6075000bU,"ldbs_block_header",sxdleg_ldbs_block_header_fields,SX_COUNT(sxdleg_ldbs_block_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_directory_header_fields[] = {
    SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxdleg_ldbs_directory_header = {0x6075000cU,"ldbs_directory_header",sxdleg_ldbs_directory_header_fields,SX_COUNT(sxdleg_ldbs_directory_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_directory_entry_fields[] = {
    SX_FIELD("block_type","byte[4]",0,4,SX_ID),
    SX_FIELD("block_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxdleg_ldbs_directory_entry = {0x6075000dU,"ldbs_directory_entry",sxdleg_ldbs_directory_entry_fields,SX_COUNT(sxdleg_ldbs_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_track_header_fields[] = {
    SX_FIELD("fixed_header_size","uint16",0,2,SX_SIZE),
    SX_FIELD("sector_descriptor_size","uint16",2,2,SX_SIZE),
    SX_FIELD("sector_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("data_rate","uint8",6,1,SX_ID),
    SX_FIELD("recording_mode","uint8",7,1,SX_ID),
    SX_FIELD("gap3_length","uint8",8,1,SX_SIZE),
    SX_FIELD("filler","uint8",9,1,SX_ID),
    SX_FIELD("track_length","uint16",10,2,SX_SIZE),
};
static const sx_layout sxdleg_ldbs_track_header = {0x6075000eU,"ldbs_track_header",sxdleg_ldbs_track_header_fields,SX_COUNT(sxdleg_ldbs_track_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_sector16_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("status1","uint8",4,1,SX_FLAGS),
    SX_FIELD("status2","uint8",5,1,SX_FLAGS),
    SX_FIELD("copies","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("filler","uint8",7,1,SX_ID),
    SX_FIELD("data_block_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("trailing_size","uint16",12,2,SX_SIZE),
    SX_FIELD("track_offset","uint16",14,2,SX_OFFSET),
};
static const sx_layout sxdleg_ldbs_sector16 = {0x6075000fU,"ldbs_sector16",sxdleg_ldbs_sector16_fields,SX_COUNT(sxdleg_ldbs_sector16_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_sector18_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("status1","uint8",4,1,SX_FLAGS),
    SX_FIELD("status2","uint8",5,1,SX_FLAGS),
    SX_FIELD("copies","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("filler","uint8",7,1,SX_ID),
    SX_FIELD("data_block_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("trailing_size","uint16",12,2,SX_SIZE),
    SX_FIELD("track_offset","uint16",14,2,SX_OFFSET),
    SX_FIELD("data_size","uint16",16,2,SX_SIZE),
};
static const sx_layout sxdleg_ldbs_sector18 = {0x60750010U,"ldbs_sector18",sxdleg_ldbs_sector18_fields,SX_COUNT(sxdleg_ldbs_sector18_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_geometry_fields[] = {
    SX_FIELD("sidedness","uint8",0,1,SX_ID),
    SX_FIELD("cylinder_count","uint16",1,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("first_sector_id","uint8",5,1,SX_ID),
    SX_FIELD("sector_size","uint16",6,2,SX_SIZE),
    SX_FIELD("data_rate","uint8",8,1,SX_ID),
    SX_FIELD("read_write_gap","uint8",9,1,SX_SIZE),
    SX_FIELD("format_gap","uint8",10,1,SX_SIZE),
    SX_FIELD("recording_mode","uint8",11,1,SX_ID),
    SX_FIELD("complement_flag","uint8",12,1,SX_FLAGS),
    SX_FIELD("no_multitrack","uint8",13,1,SX_FLAGS),
    SX_FIELD("no_skip_deleted","uint8",14,1,SX_FLAGS),
};
static const sx_layout sxdleg_ldbs_geometry = {0x60750011U,"ldbs_geometry",sxdleg_ldbs_geometry_fields,SX_COUNT(sxdleg_ldbs_geometry_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_atari_dim_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved0","uint8",2,1,SX_RESERVED),
    SX_FIELD("used_sectors_only","uint8",3,1,SX_FLAGS),
    SX_FIELD("reserved1","uint16",4,2,SX_RESERVED),
    SX_FIELD("sides_minus_one","uint8",6,1,SX_NONE),
    SX_FIELD("reserved2","uint8",7,1,SX_RESERVED),
    SX_FIELD("sectors_per_track","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("reserved3","uint8",9,1,SX_RESERVED),
    SX_FIELD("first_track","uint8",10,1,SX_NONE),
    SX_FIELD("reserved4","uint8",11,1,SX_RESERVED),
    SX_FIELD("last_track","uint8",12,1,SX_NONE),
    SX_FIELD("density","uint8",13,1,SX_ID),
    SX_FIELD("sector_size","uint16",14,2,SX_SIZE),
    SX_FIELD("opaque_extension","byte[16]",16,16,SX_NONE),
};
static const sx_layout sxdleg_atari_dim_header = {0x60750012U,"atari_dim_header",sxdleg_atari_dim_header_fields,SX_COUNT(sxdleg_atari_dim_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_stt_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
    SX_FIELD("all_track_flags","uint16",8,2,SX_FLAGS),
    SX_FIELD("track_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("side_count","uint16",12,2,SX_COUNT_PROP),
};
static const sx_layout sxdleg_stt_header = {0x60750013U,"stt_header",sxdleg_stt_header_fields,SX_COUNT(sxdleg_stt_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_stt_track_entry_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("track_size","uint16",4,2,SX_SIZE),
};
static const sx_layout sxdleg_stt_track_entry = {0x60750014U,"stt_track_entry",sxdleg_stt_track_entry_fields,SX_COUNT(sxdleg_stt_track_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_stt_track_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_flags","uint16",4,2,SX_FLAGS),
};
static const sx_layout sxdleg_stt_track_header = {0x60750015U,"stt_track_header",sxdleg_stt_track_header_fields,SX_COUNT(sxdleg_stt_track_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_stt_sector_section_fields[] = {
    SX_FIELD("end_offset","uint16",0,2,SX_OFFSET),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("sector_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxdleg_stt_sector_section = {0x60750016U,"stt_sector_section",sxdleg_stt_sector_section_fields,SX_COUNT(sxdleg_stt_sector_section_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_stt_sector_descriptor_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("side","uint8",1,1,SX_NONE),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("address_crc","byte[2]",4,2,SX_CHECKSUM),
    SX_FIELD("data_offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("data_size","uint16",8,2,SX_SIZE),
};
static const sx_layout sxdleg_stt_sector_descriptor = {0x60750017U,"stt_sector_descriptor",sxdleg_stt_sector_descriptor_fields,SX_COUNT(sxdleg_stt_sector_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_stt_raw_section_fields[] = {
    SX_FIELD("end_offset","uint16",0,2,SX_OFFSET),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("data_offset","uint16",4,2,SX_OFFSET),
    SX_FIELD("data_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxdleg_stt_raw_section = {0x60750018U,"stt_raw_section",sxdleg_stt_raw_section_fields,SX_COUNT(sxdleg_stt_raw_section_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_stt_unknown_section_fields[] = {
    SX_FIELD("end_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxdleg_stt_unknown_section = {0x60750019U,"stt_unknown_section",sxdleg_stt_unknown_section_fields,SX_COUNT(sxdleg_stt_unknown_section_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_stw_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("side_count","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("track_count","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("mfm_word_count","uint16",8,2,SX_COUNT_PROP),
};
static const sx_layout sxdleg_stw_header = {0x6075001aU,"stw_header",sxdleg_stw_header_fields,SX_COUNT(sxdleg_stw_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_stw_track_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("side","uint8",3,1,SX_NONE),
    SX_FIELD("cylinder","uint8",4,1,SX_NONE),
};
static const sx_layout sxdleg_stw_track_header = {0x6075001bU,"stw_track_header",sxdleg_stw_track_header_fields,SX_COUNT(sxdleg_stw_track_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_discferret_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxdleg_discferret_header = {0x6075001cU,"discferret_header",sxdleg_discferret_header_fields,SX_COUNT(sxdleg_discferret_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_discferret_capture_fields[] = {
    SX_FIELD("cylinder","uint16",0,2,SX_NONE),
    SX_FIELD("head","uint16",2,2,SX_NONE),
    SX_FIELD("sector","uint16",4,2,SX_NONE),
    SX_FIELD("stored_size","uint32",6,4,SX_SIZE),
};
static const sx_layout sxdleg_discferret_capture = {0x6075001dU,"discferret_capture",sxdleg_discferret_capture_fields,SX_COUNT(sxdleg_discferret_capture_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_afi_header_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version_major","uint8",16,1,SX_ID),
    SX_FIELD("version_minor","uint8",17,1,SX_ID),
    SX_FIELD("header_size","uint32",18,4,SX_SIZE),
    SX_FIELD("info_offset","uint32",22,4,SX_OFFSET),
    SX_FIELD("track_list_offset","uint32",26,4,SX_OFFSET),
    SX_FIELD("header_crc","uint16be",30,2,SX_CHECKSUM),
};
static const sx_layout sxdleg_afi_header = {0x6075001eU,"afi_header",sxdleg_afi_header_fields,SX_COUNT(sxdleg_afi_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_afi_info_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("info_size","uint32",16,4,SX_SIZE),
    SX_FIELD("media_type","uint32",20,4,SX_ID),
    SX_FIELD("platform_type","uint32",24,4,SX_ID),
    SX_FIELD("total_track_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("first_track","uint32",32,4,SX_NONE),
    SX_FIELD("last_track","uint32",36,4,SX_NONE),
    SX_FIELD("first_side","uint32",40,4,SX_NONE),
    SX_FIELD("last_side","uint32",44,4,SX_NONE),
    SX_FIELD("string_count","uint32",48,4,SX_COUNT_PROP),
};
static const sx_layout sxdleg_afi_info = {0x6075001fU,"afi_info",sxdleg_afi_info_fields,SX_COUNT(sxdleg_afi_info_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_afi_string_offset_fields[] = {
    SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdleg_afi_string_offset = {0x60750020U,"afi_string_offset",sxdleg_afi_string_offset_fields,SX_COUNT(sxdleg_afi_string_offset_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_afi_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdleg_afi_track_offset = {0x60750021U,"afi_track_offset",sxdleg_afi_track_offset_fields,SX_COUNT(sxdleg_afi_track_offset_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_afi_data_offset_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdleg_afi_data_offset = {0x60750022U,"afi_data_offset",sxdleg_afi_data_offset_fields,SX_COUNT(sxdleg_afi_data_offset_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_afi_crc_fields[] = {
    SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxdleg_afi_crc = {0x60750023U,"afi_crc",sxdleg_afi_crc_fields,SX_COUNT(sxdleg_afi_crc_fields),SX_BE};

static const xx_data_struct_field_desc sxdleg_afi_string_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("string_type","char[16]",16,16,SX_ID),
    SX_FIELD("string_size","uint32",32,4,SX_SIZE),
};
static const sx_layout sxdleg_afi_string = {0x60750024U,"afi_string",sxdleg_afi_string_fields,SX_COUNT(sxdleg_afi_string_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_afi_track_list_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("track_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxdleg_afi_track_list = {0x60750025U,"afi_track_list",sxdleg_afi_track_list_fields,SX_COUNT(sxdleg_afi_track_list_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_afi_track_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("track_number","uint32",16,4,SX_NONE),
    SX_FIELD("side_number","uint32",20,4,SX_NONE),
    SX_FIELD("encoding_mode","uint32",24,4,SX_ID),
    SX_FIELD("element_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("chunk_count","uint32",32,4,SX_COUNT_PROP),
};
static const sx_layout sxdleg_afi_track = {0x60750026U,"afi_track",sxdleg_afi_track_fields,SX_COUNT(sxdleg_afi_track_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_afi_data_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("type_id","uint32",16,4,SX_ID),
    SX_FIELD("type_tag","char[16]",20,16,SX_ID),
    SX_FIELD("bits_per_element","uint32",36,4,SX_NONE),
    SX_FIELD("packed_size","uint32",40,4,SX_SIZE),
    SX_FIELD("packer","uint32",44,4,SX_ID),
    SX_FIELD("unpacked_size","uint32",48,4,SX_SIZE),
};
static const sx_layout sxdleg_afi_data = {0x60750027U,"afi_data",sxdleg_afi_data_fields,SX_COUNT(sxdleg_afi_data_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_hxc_qd_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("revision","uint32",8,4,SX_ID),
    SX_FIELD("track_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("side_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("encoding","uint32",20,4,SX_ID),
    SX_FIELD("write_protected","uint32",24,4,SX_FLAGS),
    SX_FIELD("cell_rate","uint32",28,4,SX_NONE),
    SX_FIELD("flags","uint32",32,4,SX_FLAGS),
    SX_FIELD("track_table_offset","uint32",36,4,SX_OFFSET),
};
static const sx_layout sxdleg_hxc_qd_header = {0x60750028U,"hxc_qd_header",sxdleg_hxc_qd_header_fields,SX_COUNT(sxdleg_hxc_qd_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_hxc_qd_track_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("start_switch_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("stop_switch_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxdleg_hxc_qd_track = {0x60750029U,"hxc_qd_track",sxdleg_hxc_qd_track_fields,SX_COUNT(sxdleg_hxc_qd_track_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_hxc_stream_chunk_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packet_number","uint32",8,4,SX_NONE),
};
static const sx_layout sxdleg_hxc_stream_chunk = {0x6075002aU,"hxc_stream_chunk",sxdleg_hxc_stream_chunk_fields,SX_COUNT(sxdleg_hxc_stream_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_hxc_stream_metadata_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxdleg_hxc_stream_metadata = {0x6075002bU,"hxc_stream_metadata",sxdleg_hxc_stream_metadata_fields,SX_COUNT(sxdleg_hxc_stream_metadata_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_hxc_stream_io_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxdleg_hxc_stream_io = {0x6075002cU,"hxc_stream_io",sxdleg_hxc_stream_io_fields,SX_COUNT(sxdleg_hxc_stream_io_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_hxc_stream_flux_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
    SX_FIELD("pulse_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxdleg_hxc_stream_flux = {0x6075002dU,"hxc_stream_flux",sxdleg_hxc_stream_flux_fields,SX_COUNT(sxdleg_hxc_stream_flux_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_hxc_stream_crc_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxdleg_hxc_stream_crc = {0x6075002eU,"hxc_stream_crc",sxdleg_hxc_stream_crc_fields,SX_COUNT(sxdleg_hxc_stream_crc_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_oric_sector_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("side_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("opaque_header","byte[236]",20,236,SX_NONE),
};
static const sx_layout sxdleg_oric_sector_header = {0x6075002fU,"oric_sector_header",sxdleg_oric_sector_header_fields,SX_COUNT(sxdleg_oric_sector_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_oric_mfm_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("side_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("geometry_order","uint32",16,4,SX_ID),
    SX_FIELD("opaque_header","byte[236]",20,236,SX_NONE),
};
static const sx_layout sxdleg_oric_mfm_header = {0x60750030U,"oric_mfm_header",sxdleg_oric_mfm_header_fields,SX_COUNT(sxdleg_oric_mfm_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_gkh_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("number_type","uint8",4,1,SX_ID),
    SX_FIELD("version","uint8",5,1,SX_ID),
    SX_FIELD("tag_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxdleg_gkh_header = {0x60750031U,"gkh_header",sxdleg_gkh_header_fields,SX_COUNT(sxdleg_gkh_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_gkh_format_tag_fields[] = {
    SX_FIELD("tag_type","uint8",0,1,SX_ID),
    SX_FIELD("data_type","uint8",1,1,SX_ID),
    SX_FIELD("disk_format","uint32",2,4,SX_ID),
    SX_FIELD("dump_type","uint32",6,4,SX_ID),
};
static const sx_layout sxdleg_gkh_format_tag = {0x60750032U,"gkh_format_tag",sxdleg_gkh_format_tag_fields,SX_COUNT(sxdleg_gkh_format_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_gkh_geometry_tag_fields[] = {
    SX_FIELD("tag_type","uint8",0,1,SX_ID),
    SX_FIELD("data_type","uint8",1,1,SX_ID),
    SX_FIELD("track_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("sector_size","uint16",8,2,SX_SIZE),
};
static const sx_layout sxdleg_gkh_geometry_tag = {0x60750033U,"gkh_geometry_tag",sxdleg_gkh_geometry_tag_fields,SX_COUNT(sxdleg_gkh_geometry_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_gkh_location_tag_fields[] = {
    SX_FIELD("tag_type","uint8",0,1,SX_ID),
    SX_FIELD("data_type","uint8",1,1,SX_ID),
    SX_FIELD("data_size","uint32",2,4,SX_SIZE),
    SX_FIELD("data_offset","uint32",6,4,SX_OFFSET),
};
static const sx_layout sxdleg_gkh_location_tag = {0x60750034U,"gkh_location_tag",sxdleg_gkh_location_tag_fields,SX_COUNT(sxdleg_gkh_location_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ede_text_header_fields[] = {
    SX_FIELD("line_start","byte[2]",0,2,SX_SIGNATURE),
    SX_FIELD("description","char[76]",2,76,SX_NONE),
    SX_FIELD("line_end","byte[2]",78,2,SX_SIGNATURE),
};
static const sx_layout sxdleg_ede_text_header = {0x60750035U,"ede_text_header",sxdleg_ede_text_header_fields,SX_COUNT(sxdleg_ede_text_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ede_bitmap_marker_fields[] = {
    SX_FIELD("text_end","byte[3]",0,3,SX_SIGNATURE),
};
static const sx_layout sxdleg_ede_bitmap_marker = {0x60750036U,"ede_bitmap_marker",sxdleg_ede_bitmap_marker_fields,SX_COUNT(sxdleg_ede_bitmap_marker_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ede_bitmap_byte_fields[] = {
    SX_FIELD("sector_bitmap","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxdleg_ede_bitmap_byte = {0x60750037U,"ede_bitmap_byte",sxdleg_ede_bitmap_byte_fields,SX_COUNT(sxdleg_ede_bitmap_byte_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ede_format_fields[] = {
    SX_FIELD("computer_format","uint8",0,1,SX_FLAGS),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
};
static const sx_layout sxdleg_ede_format = {0x60750038U,"ede_format",sxdleg_ede_format_fields,SX_COUNT(sxdleg_ede_format_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_sad_header_fields[] = {
    SX_FIELD("magic","char[18]",0,18,SX_SIGNATURE),
    SX_FIELD("side_count","uint8",18,1,SX_COUNT_PROP),
    SX_FIELD("track_count","uint8",19,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",20,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_div64","uint8",21,1,SX_NONE),
};
static const sx_layout sxdleg_sad_header = {0x60750039U,"sad_header",sxdleg_sad_header_fields,SX_COUNT(sxdleg_sad_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_trackstar_track_header_fields[] = {
    SX_FIELD("description","char[46]",0,46,SX_NONE),
    SX_FIELD("reserved","byte[82]",46,82,SX_RESERVED),
    SX_FIELD("halftrack_image","uint8",128,1,SX_FLAGS),
};
static const sx_layout sxdleg_trackstar_track_header = {0x6075003aU,"trackstar_track_header",sxdleg_trackstar_track_header_fields,SX_COUNT(sxdleg_trackstar_track_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_trackstar_track_size_fields[] = {
    SX_FIELD("stored_track_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxdleg_trackstar_track_size = {0x6075003bU,"trackstar_track_size",sxdleg_trackstar_track_size_fields,SX_COUNT(sxdleg_trackstar_track_size_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_fatx_superblock_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("volume_id","uint32",4,4,SX_ID),
    SX_FIELD("sectors_per_cluster","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("root_directory_cluster","uint32",12,4,SX_NONE),
    SX_FIELD("partition_name","uint16[32]",16,64,SX_NONE),
};
static const sx_layout sxdleg_fatx_superblock = {0x6075003cU,"fatx_superblock",sxdleg_fatx_superblock_fields,SX_COUNT(sxdleg_fatx_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_fatx_fat16_entry_fields[] = {
    SX_FIELD("next_cluster","uint16",0,2,SX_NONE),
};
static const sx_layout sxdleg_fatx_fat16_entry = {0x6075003dU,"fatx_fat16_entry",sxdleg_fatx_fat16_entry_fields,SX_COUNT(sxdleg_fatx_fat16_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_fatx_fat32_entry_fields[] = {
    SX_FIELD("next_cluster","uint32",0,4,SX_NONE),
};
static const sx_layout sxdleg_fatx_fat32_entry = {0x6075003eU,"fatx_fat32_entry",sxdleg_fatx_fat32_entry_fields,SX_COUNT(sxdleg_fatx_fat32_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_fatx_directory_entry_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("attributes","uint8",1,1,SX_FLAGS),
    SX_FIELD("name","char[42]",2,42,SX_NONE),
    SX_FIELD("first_cluster","uint32",44,4,SX_NONE),
    SX_FIELD("file_size","uint32",48,4,SX_SIZE),
    SX_FIELD("modification_time","uint16",52,2,SX_NONE),
    SX_FIELD("modification_date","uint16",54,2,SX_NONE),
    SX_FIELD("creation_time","uint16",56,2,SX_NONE),
    SX_FIELD("creation_date","uint16",58,2,SX_NONE),
    SX_FIELD("access_time","uint16",60,2,SX_NONE),
    SX_FIELD("access_date","uint16",62,2,SX_NONE),
};
static const sx_layout sxdleg_fatx_directory_entry = {0x6075003fU,"fatx_directory_entry",sxdleg_fatx_directory_entry_fields,SX_COUNT(sxdleg_fatx_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_xdvdfs_volume_descriptor_fields[] = {
    SX_FIELD("signature","char[20]",0,20,SX_SIGNATURE),
    SX_FIELD("root_directory_sector","uint32",20,4,SX_NONE),
    SX_FIELD("root_directory_size","uint32",24,4,SX_SIZE),
    SX_FIELD("creation_filetime","uint64",28,8,SX_NONE),
    SX_FIELD("reserved","byte[1992]",36,1992,SX_RESERVED),
    SX_FIELD("ending_signature","char[20]",2028,20,SX_SIGNATURE),
};
static const sx_layout sxdleg_xdvdfs_volume_descriptor = {0x60750040U,"xdvdfs_volume_descriptor",sxdleg_xdvdfs_volume_descriptor_fields,SX_COUNT(sxdleg_xdvdfs_volume_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_xdvdfs_directory_entry_fields[] = {
    SX_FIELD("left_child_words","uint16",0,2,SX_NONE),
    SX_FIELD("right_child_words","uint16",2,2,SX_NONE),
    SX_FIELD("first_sector","uint32",4,4,SX_NONE),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("attributes","uint8",12,1,SX_FLAGS),
    SX_FIELD("name_length","uint8",13,1,SX_COUNT_PROP),
};
static const sx_layout sxdleg_xdvdfs_directory_entry = {0x60750041U,"xdvdfs_directory_entry",sxdleg_xdvdfs_directory_entry_fields,SX_COUNT(sxdleg_xdvdfs_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_focusdrive_header_fields[] = {
    SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
    SX_FIELD("opaque_byte","uint8",14,1,SX_NONE),
    SX_FIELD("partition_count","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("opaque_identifier","byte[16]",16,16,SX_NONE),
};
static const sx_layout sxdleg_focusdrive_header = {0x60750042U,"focusdrive_header",sxdleg_focusdrive_header_fields,SX_COUNT(sxdleg_focusdrive_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_focusdrive_partition_fields[] = {
    SX_FIELD("start_lba","uint32",0,4,SX_NONE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("opaque_metadata","byte[8]",8,8,SX_NONE),
};
static const sx_layout sxdleg_focusdrive_partition = {0x60750043U,"focusdrive_partition",sxdleg_focusdrive_partition_fields,SX_COUNT(sxdleg_focusdrive_partition_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_focusdrive_name_header_fields[] = {
    SX_FIELD("opaque_prefix","byte[4]",0,4,SX_NONE),
    SX_FIELD("unpartitioned_blocks","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("opaque_metadata","byte[24]",8,24,SX_NONE),
};
static const sx_layout sxdleg_focusdrive_name_header = {0x60750044U,"focusdrive_name_header",sxdleg_focusdrive_name_header_fields,SX_COUNT(sxdleg_focusdrive_name_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_focusdrive_partition_name_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_NONE),
};
static const sx_layout sxdleg_focusdrive_partition_name = {0x60750045U,"focusdrive_partition_name",sxdleg_focusdrive_partition_name_fields,SX_COUNT(sxdleg_focusdrive_partition_name_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_microdrive_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("cylinder_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("reserved0","uint16",4,2,SX_RESERVED),
    SX_FIELD("heads_per_cylinder","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("reserved1","uint16",10,2,SX_RESERVED),
    SX_FIELD("first_partition_count","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("second_partition_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved2","byte[10]",14,10,SX_RESERVED),
    SX_FIELD("iigs_rom_version","uint16",24,2,SX_ID),
    SX_FIELD("reserved3","byte[6]",26,6,SX_RESERVED),
};
static const sx_layout sxdleg_microdrive_header = {0x60750046U,"microdrive_header",sxdleg_microdrive_header_fields,SX_COUNT(sxdleg_microdrive_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_microdrive_start_fields[] = {
    SX_FIELD("start_lba","uint32",0,4,SX_NONE),
};
static const sx_layout sxdleg_microdrive_start = {0x60750047U,"microdrive_start",sxdleg_microdrive_start_fields,SX_COUNT(sxdleg_microdrive_start_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_microdrive_size_fields[] = {
    SX_FIELD("block_count","uint24",0,3,SX_COUNT_PROP),
    SX_FIELD("drive_switch","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxdleg_microdrive_size = {0x60750048U,"microdrive_size",sxdleg_microdrive_size_fields,SX_COUNT(sxdleg_microdrive_size_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_track_directory_entry_fields[] = {
    SX_FIELD("block_kind","uint8",0,1,SX_ID),
    SX_FIELD("cylinder","uint16",1,2,SX_NONE),
    SX_FIELD("head","uint8",3,1,SX_NONE),
    SX_FIELD("block_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxdleg_ldbs_track_directory_entry = {0x60750049U,"ldbs_track_directory_entry",sxdleg_ldbs_track_directory_entry_fields,SX_COUNT(sxdleg_ldbs_track_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_track_block_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("block_kind","uint8",4,1,SX_ID),
    SX_FIELD("cylinder","uint16",5,2,SX_NONE),
    SX_FIELD("head","uint8",7,1,SX_NONE),
    SX_FIELD("allocated_size","uint32",8,4,SX_SIZE),
    SX_FIELD("used_size","uint32",12,4,SX_SIZE),
    SX_FIELD("next_block_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxdleg_ldbs_track_block_header = {0x6075004aU,"ldbs_track_block_header",sxdleg_ldbs_track_block_header_fields,SX_COUNT(sxdleg_ldbs_track_block_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdleg_ldbs_sector_block_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("block_kind","uint8",4,1,SX_ID),
    SX_FIELD("cylinder","uint8",5,1,SX_NONE),
    SX_FIELD("head","uint8",6,1,SX_NONE),
    SX_FIELD("sector_id","uint8",7,1,SX_ID),
    SX_FIELD("allocated_size","uint32",8,4,SX_SIZE),
    SX_FIELD("used_size","uint32",12,4,SX_SIZE),
    SX_FIELD("next_block_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxdleg_ldbs_sector_block_header = {0x6075004bU,"ldbs_sector_block_header",sxdleg_ldbs_sector_block_header_fields,SX_COUNT(sxdleg_ldbs_sector_block_header_fields),SX_LE};

static const sx_layout *const sx_disklegacy_layouts[] = {
    &sxdleg_shrinkwrap_header,
    &sxdleg_jv3_sector_descriptor,
    &sxdleg_jv3_write_protection,
    &sxdleg_x68000_dim_header,
    &sxdleg_dart_header,
    &sxdleg_dart_block_length,
    &sxdleg_mds2_header,
    &sxdleg_mdx_header,
    &sxdleg_mdx_key_salt,
    &sxdleg_ldbs_header,
    &sxdleg_ldbs_block_header,
    &sxdleg_ldbs_directory_header,
    &sxdleg_ldbs_directory_entry,
    &sxdleg_ldbs_track_header,
    &sxdleg_ldbs_sector16,
    &sxdleg_ldbs_sector18,
    &sxdleg_ldbs_geometry,
    &sxdleg_atari_dim_header,
    &sxdleg_stt_header,
    &sxdleg_stt_track_entry,
    &sxdleg_stt_track_header,
    &sxdleg_stt_sector_section,
    &sxdleg_stt_sector_descriptor,
    &sxdleg_stt_raw_section,
    &sxdleg_stt_unknown_section,
    &sxdleg_stw_header,
    &sxdleg_stw_track_header,
    &sxdleg_discferret_header,
    &sxdleg_discferret_capture,
    &sxdleg_afi_header,
    &sxdleg_afi_info,
    &sxdleg_afi_string_offset,
    &sxdleg_afi_track_offset,
    &sxdleg_afi_data_offset,
    &sxdleg_afi_crc,
    &sxdleg_afi_string,
    &sxdleg_afi_track_list,
    &sxdleg_afi_track,
    &sxdleg_afi_data,
    &sxdleg_hxc_qd_header,
    &sxdleg_hxc_qd_track,
    &sxdleg_hxc_stream_chunk,
    &sxdleg_hxc_stream_metadata,
    &sxdleg_hxc_stream_io,
    &sxdleg_hxc_stream_flux,
    &sxdleg_hxc_stream_crc,
    &sxdleg_oric_sector_header,
    &sxdleg_oric_mfm_header,
    &sxdleg_gkh_header,
    &sxdleg_gkh_format_tag,
    &sxdleg_gkh_geometry_tag,
    &sxdleg_gkh_location_tag,
    &sxdleg_ede_text_header,
    &sxdleg_ede_bitmap_marker,
    &sxdleg_ede_bitmap_byte,
    &sxdleg_ede_format,
    &sxdleg_sad_header,
    &sxdleg_trackstar_track_header,
    &sxdleg_trackstar_track_size,
    &sxdleg_fatx_superblock,
    &sxdleg_fatx_fat16_entry,
    &sxdleg_fatx_fat32_entry,
    &sxdleg_fatx_directory_entry,
    &sxdleg_xdvdfs_volume_descriptor,
    &sxdleg_xdvdfs_directory_entry,
    &sxdleg_focusdrive_header,
    &sxdleg_focusdrive_partition,
    &sxdleg_focusdrive_name_header,
    &sxdleg_focusdrive_partition_name,
    &sxdleg_microdrive_header,
    &sxdleg_microdrive_start,
    &sxdleg_microdrive_size,
    &sxdleg_ldbs_track_directory_entry,
    &sxdleg_ldbs_track_block_header,
    &sxdleg_ldbs_sector_block_header,
};

typedef struct sxdleg_flag {uint64_t mask;const wchar_t*name;} sxdleg_flag;
static bool sxdleg_flags(xx_data_struct_record*r,uint64_t value,const sxdleg_flag*bits,size_t n){
 wchar_t out[1024];size_t used=0;uint64_t known=0;
 for(size_t i=0;i<n;i++){known|=bits[i].mask;if(!(value&bits[i].mask))continue;const wchar_t*p=bits[i].name;size_t z=xx_rt_wcslen(p);if(z+used+24>=SX_COUNT(out))return false;if(used)out[used++]=L'|';while(*p)out[used++]=*p++;}
 uint64_t unknown=value&~known;if(unknown){if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';bool start=false;for(int shift=60;shift>=0;shift-=4){unsigned d=(unsigned)((unknown>>shift)&15);if(d||start||!shift){out[used++]=L"0123456789ABCDEF"[d];start=true;}}}
 if(!used)out[used++]=L'0';out[used]=0;return xx_data_struct_record_set_comment(r,out);
}

static bool sx_disklegacy_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60750000U||id>=0x60760000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    if(id==0x60750015U&&!xx_rt_wcscmp(r->name,L"data_flags")&&integer){static const sxdleg_flag bits[]={{1U,L"Sectors and ID fields"},{2U,L"Raw track data"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60750013U&&!xx_rt_wcscmp(r->name,L"all_track_flags")&&integer){static const sxdleg_flag bits[]={{1U,L"Sectors and ID fields"},{2U,L"Raw track data"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6075000fU&&!xx_rt_wcscmp(r->name,L"status1")&&integer){static const sxdleg_flag bits[]={{1U,L"Missing address mark"},{4U,L"No data"},{32U,L"Data error"},{128U,L"End of cylinder"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60750010U&&!xx_rt_wcscmp(r->name,L"status1")&&integer){static const sxdleg_flag bits[]={{1U,L"Missing address mark"},{4U,L"No data"},{32U,L"Data error"},{128U,L"End of cylinder"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6075000fU&&!xx_rt_wcscmp(r->name,L"status2")&&integer){static const sxdleg_flag bits[]={{1U,L"Missing data address mark"},{32U,L"Data error"},{64U,L"Deleted data mark"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60750010U&&!xx_rt_wcscmp(r->name,L"status2")&&integer){static const sxdleg_flag bits[]={{1U,L"Missing data address mark"},{32U,L"Data error"},{64U,L"Deleted data mark"}};return sxdleg_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60750005U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Word RLE");
    case 1U:return xx_data_struct_record_set_comment(r,L"LZHUF");
    case 2U:return xx_data_struct_record_set_comment(r,L"Stored");
    default:break;}}
    if(id==0x60750005U&&!xx_rt_wcscmp(r->name,L"disk_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Macintosh");
    case 2U:return xx_data_struct_record_set_comment(r,L"Lisa");
    case 3U:return xx_data_struct_record_set_comment(r,L"Apple II");
    case 16U:return xx_data_struct_record_set_comment(r,L"Macintosh HD");
    case 17U:return xx_data_struct_record_set_comment(r,L"DOS 720K");
    case 18U:return xx_data_struct_record_set_comment(r,L"DOS 1440K");
    default:break;}}
    if(id==0x60750001U&&!xx_rt_wcscmp(r->name,L"disk_format")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"400 KiB GCR");
    case 1U:return xx_data_struct_record_set_comment(r,L"800 KiB GCR");
    case 2U:return xx_data_struct_record_set_comment(r,L"720 KiB MFM");
    case 3U:return xx_data_struct_record_set_comment(r,L"1440 KiB MFM");
    default:break;}}
    if(id==0x60750004U&&!xx_rt_wcscmp(r->name,L"media_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"2HD (1024 x 8)");
    case 1U:return xx_data_struct_record_set_comment(r,L"2HS (1024 x 9)");
    case 2U:return xx_data_struct_record_set_comment(r,L"2HC (512 x 15)");
    case 3U:return xx_data_struct_record_set_comment(r,L"2HDE (1024 x 9)");
    case 9U:return xx_data_struct_record_set_comment(r,L"2HQ (512 x 18)");
    case 17U:return xx_data_struct_record_set_comment(r,L"N88-BASIC (256 x 26)");
    default:break;}}
    if(id==0x60750003U&&!xx_rt_wcscmp(r->name,L"write_protection")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Write-protected");
    case 255U:return xx_data_struct_record_set_comment(r,L"Writable; padding in subsequent headers");
    default:break;}}
    if(id==0x6075001fU&&!xx_rt_wcscmp(r->name,L"media_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"3.5-inch DD");
    case 2U:return xx_data_struct_record_set_comment(r,L"3.5-inch HD");
    case 3U:return xx_data_struct_record_set_comment(r,L"3.5-inch ED");
    case 4U:return xx_data_struct_record_set_comment(r,L"5.25-inch");
    case 5U:return xx_data_struct_record_set_comment(r,L"3-inch");
    default:break;}}
    if(id==0x6075001fU&&!xx_rt_wcscmp(r->name,L"platform_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"Atari ST");
    case 2U:return xx_data_struct_record_set_comment(r,L"Amiga");
    case 3U:return xx_data_struct_record_set_comment(r,L"PC");
    case 4U:return xx_data_struct_record_set_comment(r,L"CPC");
    case 5U:return xx_data_struct_record_set_comment(r,L"MSX2");
    default:break;}}
    if(id==0x60750026U&&!xx_rt_wcscmp(r->name,L"encoding_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    case 1U:return xx_data_struct_record_set_comment(r,L"MFM");
    case 2U:return xx_data_struct_record_set_comment(r,L"PDC");
    case 3U:return xx_data_struct_record_set_comment(r,L"Cell array");
    default:break;}}
    if(id==0x60750027U&&!xx_rt_wcscmp(r->name,L"type_id")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    case 1U:return xx_data_struct_record_set_comment(r,L"MFM_DATA");
    case 2U:return xx_data_struct_record_set_comment(r,L"INDEX_DATA");
    case 3U:return xx_data_struct_record_set_comment(r,L"BITRATE_DATA");
    case 4U:return xx_data_struct_record_set_comment(r,L"PDC_DATA");
    case 5U:return xx_data_struct_record_set_comment(r,L"WEAKBITS_DATA");
    case 6U:return xx_data_struct_record_set_comment(r,L"CELL_DATA");
    default:break;}}
    if(id==0x60750027U&&!xx_rt_wcscmp(r->name,L"packer")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 1U:return xx_data_struct_record_set_comment(r,L"zlib (historically called GZIP)");
    case 2U:return xx_data_struct_record_set_comment(r,L"Reserved RLE; opaque");
    case 3U:return xx_data_struct_record_set_comment(r,L"Reserved LZW; opaque");
    default:break;}}
    if(id==0x60750032U&&!xx_rt_wcscmp(r->name,L"disk_format")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"EPS Disk");
    default:break;}}
    if(id==0x60750032U&&!xx_rt_wcscmp(r->name,L"dump_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Uncompressed dump");
    default:break;}}
    if(id==0x60750034U&&!xx_rt_wcscmp(r->name,L"tag_type")&&integer){switch(value){
    case 11U:return xx_data_struct_record_set_comment(r,L"Image");
    case 20U:return xx_data_struct_record_set_comment(r,L"Author");
    case 21U:return xx_data_struct_record_set_comment(r,L"Subject");
    default:break;}}
    if(id==0x60750030U&&!xx_rt_wcscmp(r->name,L"geometry_order")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Side-major");
    case 2U:return xx_data_struct_record_set_comment(r,L"Cylinder-major");
    default:break;}}
    if(id==0x60750038U&&!xx_rt_wcscmp(r->name,L"disk_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"DD geometry (code 0)");
    case 1U:return xx_data_struct_record_set_comment(r,L"Single-sided mixed-size geometry");
    case 2U:return xx_data_struct_record_set_comment(r,L"Double-sided mixed-size geometry");
    case 3U:return xx_data_struct_record_set_comment(r,L"EPS DD");
    case 4U:return xx_data_struct_record_set_comment(r,L"DD geometry (code 4)");
    case 7U:return xx_data_struct_record_set_comment(r,L"TS DD");
    case 203U:return xx_data_struct_record_set_comment(r,L"ASR HD");
    case 204U:return xx_data_struct_record_set_comment(r,L"TS HD");
    default:break;}}
    if(id==0x6075000eU&&!xx_rt_wcscmp(r->name,L"data_rate")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"Single/double density");
    case 2U:return xx_data_struct_record_set_comment(r,L"High density");
    case 3U:return xx_data_struct_record_set_comment(r,L"Extended density");
    default:break;}}
    if(id==0x6075000eU&&!xx_rt_wcscmp(r->name,L"recording_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"FM");
    case 2U:return xx_data_struct_record_set_comment(r,L"MFM");
    default:break;}}
    if(id==0x60750011U&&!xx_rt_wcscmp(r->name,L"recording_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"MFM");
    case 1U:return xx_data_struct_record_set_comment(r,L"FM");
    default:break;}}
    if(id==0x60750011U&&!xx_rt_wcscmp(r->name,L"data_rate")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"500 kbit/s");
    case 1U:return xx_data_struct_record_set_comment(r,L"300 kbit/s");
    case 2U:return xx_data_struct_record_set_comment(r,L"250 kbit/s");
    case 3U:return xx_data_struct_record_set_comment(r,L"1 Mbit/s");
    default:break;}}
    if(id==0x60750011U&&!xx_rt_wcscmp(r->name,L"sidedness")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Alternating sides");
    case 1U:return xx_data_struct_record_set_comment(r,L"Out and back");
    case 2U:return xx_data_struct_record_set_comment(r,L"Out and out");
    case 3U:return xx_data_struct_record_set_comment(r,L"Extended surface");
    default:break;}}
    if(id==0x6075002bU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Metadata text");
    default:break;}}
    if(id==0x6075002cU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"LZ4 packed 16-bit IO");
    default:break;}}
    if(id==0x6075002dU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 2U:return xx_data_struct_record_set_comment(r,L"LZ4 packed flux stream");
    default:break;}}
    switch(id){
    case 0x60750001U:
        if(!xx_rt_wcscmp(r->name,L"data_checksum"))s=L"Disk Copy rolling checksum of data words";
        else if(!xx_rt_wcscmp(r->name,L"tag_checksum"))s=L"Disk Copy rolling checksum, excluding the first 12 tag bytes";
        else if(!xx_rt_wcscmp(r->name,L"disk_format"))s=L"0=400 KiB, 1=800 KiB, 2=720 KiB, 3=1440 KiB";
        else if(!xx_rt_wcscmp(r->name,L"format_byte"))s=L"GCR/MFM format byte";
        else if(!xx_rt_wcscmp(r->name,L"private_word"))s=L"Private Disk Copy marker, normally 0x0100";
        break;
    case 0x60750002U:
        if(!xx_rt_wcscmp(r->name,L"cylinder"))s=L"0xFF with sector_id 0xFF denotes a free descriptor";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Density, DAM, side, error and size-code bits; free descriptors use a different size-code mapping";
        break;
    case 0x60750003U:
        if(!xx_rt_wcscmp(r->name,L"write_protection"))s=L"First header: 0x00 protected, 0xFF writable; later headers carry padding";
        break;
    case 0x60750004U:
        if(!xx_rt_wcscmp(r->name,L"track_present"))s=L"One byte per physical track; nonzero denotes stored track data";
        else if(!xx_rt_wcscmp(r->name,L"producer_metadata"))s=L"Unspecified producer date, time and comment area; preserved without invented subfields";
        break;
    case 0x60750005U:
        if(!xx_rt_wcscmp(r->name,L"compression"))s=L"0=word RLE, 1=LZHUF, 2=stored";
        else if(!xx_rt_wcscmp(r->name,L"disk_size_kib"))s=L"Logical disk capacity in 1024-byte units";
        break;
    case 0x60750006U:
        if(!xx_rt_wcscmp(r->name,L"encoded_length"))s=L"0=unused; 0xFFFF=stored 20960-byte block; otherwise words for RLE and bytes for LZHUF";
        break;
    case 0x60750007U:
        if(!xx_rt_wcscmp(r->name,L"key_header_offset"))s=L"File-relative offset of the encrypted 512-byte key header";
        break;
    case 0x60750008U:
        if(!xx_rt_wcscmp(r->name,L"mdx_marker"))s=L"0xFFFFFFFF selects the MDX physical envelope";
        else if(!xx_rt_wcscmp(r->name,L"descriptor_span"))s=L"Physical descriptor extent, including its 64-byte salt; encrypted payload remains raw";
        break;
    case 0x60750009U:
        if(!xx_rt_wcscmp(r->name,L"salt"))s=L"Physical key-derivation salt; subsequent key material is encrypted";
        break;
    case 0x6075000eU:
        if(!xx_rt_wcscmp(r->name,L"data_rate"))s=L"0=unknown, 1=SD/DD, 2=HD, 3=ED; unlike GEOM rate codes";
        else if(!xx_rt_wcscmp(r->name,L"recording_mode"))s=L"0=unknown, 1=FM, 2=MFM; native reader excludes GCR variants";
        else if(!xx_rt_wcscmp(r->name,L"gap3_length"))s=L"Controller format-gap byte count";
        else if(!xx_rt_wcscmp(r->name,L"track_length"))s=L"Approximate controller track byte length; zero if unavailable";
        break;
    case 0x6075000fU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Nominal sector bytes = 128 shifted left by this value";
        else if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Approximate controller-track byte offset, not a file offset";
        break;
    case 0x60750010U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Nominal sector bytes = 128 shifted left by this value";
        else if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Approximate controller-track byte offset, not a file offset";
        else if(!xx_rt_wcscmp(r->name,L"data_size"))s=L"Zero selects the nominal 128<<size_code length";
        break;
    case 0x60750011U:
        if(!xx_rt_wcscmp(r->name,L"data_rate"))s=L"0=500 kbit/s, 1=300 kbit/s, 2=250 kbit/s, 3=1 Mbit/s";
        else if(!xx_rt_wcscmp(r->name,L"read_write_gap"))s=L"Controller gap byte count";
        else if(!xx_rt_wcscmp(r->name,L"format_gap"))s=L"Controller gap byte count";
        else if(!xx_rt_wcscmp(r->name,L"recording_mode"))s=L"0=MFM, 1=FM; unlike track-header mode codes";
        break;
    case 0x60750012U:
        if(!xx_rt_wcscmp(r->name,L"sector_size"))s=L"Zero selects the legacy 512-byte sector size";
        break;
    case 0x60750015U:
        if(!xx_rt_wcscmp(r->name,L"data_flags"))s=L"Bit0=sector descriptors and data, bit1=raw track data";
        break;
    case 0x60750016U:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Relative to the start of this track";
        break;
    case 0x60750017U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Nominal sector bytes = 128 shifted left by this value";
        else if(!xx_rt_wcscmp(r->name,L"address_crc"))s=L"Address-field CRC bytes in recorded order";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to the start of this track";
        break;
    case 0x60750018U:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Relative to the start of this track";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to the start of this track";
        break;
    case 0x60750019U:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Relative to the start of this track; unsupported section body remains raw";
        break;
    case 0x6075001aU:
        if(!xx_rt_wcscmp(r->name,L"mfm_word_count"))s=L"Number of encoded 16-bit MFM words per track";
        break;
    case 0x6075001cU:
        if(!xx_rt_wcscmp(r->name,L"magic"))s=L"DFER=version1, DFE2=version2";
        break;
    case 0x6075001eU:
        if(!xx_rt_wcscmp(r->name,L"header_crc"))s=L"CRC16-CCITT stored big endian, unlike the surrounding header";
        break;
    case 0x60750020U:
        if(!xx_rt_wcscmp(r->name,L"string_offset"))s=L"Relative to the AFI_INFO block";
        break;
    case 0x60750021U:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Relative to the TRACKLIST block";
        break;
    case 0x60750022U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Relative to the TRACK block";
        break;
    case 0x60750023U:
        if(!xx_rt_wcscmp(r->name,L"crc16"))s=L"CRC16-CCITT stored big endian";
        break;
    case 0x60750027U:
        if(!xx_rt_wcscmp(r->name,L"bits_per_element"))s=L"Encoded bit width, not bytes";
        else if(!xx_rt_wcscmp(r->name,L"packer"))s=L"0=stored, 1=zlib; reserved packers remain opaque";
        break;
    case 0x60750028U:
        if(!xx_rt_wcscmp(r->name,L"cell_rate"))s=L"Bit-cell rate in hertz";
        break;
    case 0x60750029U:
        if(!xx_rt_wcscmp(r->name,L"start_switch_offset"))s=L"Byte offset within this track data";
        else if(!xx_rt_wcscmp(r->name,L"stop_switch_offset"))s=L"Byte offset within this track data";
        break;
    case 0x6075002aU:
        if(!xx_rt_wcscmp(r->name,L"total_size"))s=L"Includes chunk header, block records and trailing CRC32";
        break;
    case 0x6075002bU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Does not include the 8-byte common block header";
        break;
    case 0x6075002cU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Does not include the 8-byte common block header";
        break;
    case 0x6075002dU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Does not include the 8-byte common block header";
        break;
    case 0x6075002eU:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"Pauline stream CRC32";
        break;
    case 0x60750030U:
        if(!xx_rt_wcscmp(r->name,L"geometry_order"))s=L"1=side-major, 2=cylinder-major";
        break;
    case 0x60750031U:
        if(!xx_rt_wcscmp(r->name,L"number_type"))s=L"ASCII I selects Intel little-endian numbers";
        break;
    case 0x60750032U:
        if(!xx_rt_wcscmp(r->name,L"disk_format"))s=L"1=Ensoniq EPS disk";
        else if(!xx_rt_wcscmp(r->name,L"dump_type"))s=L"1=uncompressed data dump";
        break;
    case 0x60750034U:
        if(!xx_rt_wcscmp(r->name,L"tag_type"))s=L"11=image, 20=author text, 21=subject text";
        break;
    case 0x60750036U:
        if(!xx_rt_wcscmp(r->name,L"text_end"))s=L"CR LF and DOS end-of-text marker";
        break;
    case 0x60750037U:
        if(!xx_rt_wcscmp(r->name,L"sector_bitmap"))s=L"MSB-first: 0=stored sector, 1=implicit fill sector";
        break;
    case 0x60750038U:
        if(!xx_rt_wcscmp(r->name,L"computer_format"))s=L"Native reader supports zero only";
        break;
    case 0x60750039U:
        if(!xx_rt_wcscmp(r->name,L"sector_size_div64"))s=L"Physical sector byte size divided by 64";
        break;
    case 0x6075003aU:
        if(!xx_rt_wcscmp(r->name,L"halftrack_image"))s=L"Zero for 40-track, one for 80-half-track images";
        break;
    case 0x6075003bU:
        if(!xx_rt_wcscmp(r->name,L"stored_track_size"))s=L"Zero denotes failed analysis; data is stored in reverse byte order";
        break;
    case 0x6075003cU:
        if(!xx_rt_wcscmp(r->name,L"sectors_per_cluster"))s=L"Number of 512-byte sectors in a cluster";
        else if(!xx_rt_wcscmp(r->name,L"root_directory_cluster"))s=L"Cluster index, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_name"))s=L"UTF-16LE code units, zero-padded; ignored by the native volume reader";
        break;
    case 0x6075003dU:
        if(!xx_rt_wcscmp(r->name,L"next_cluster"))s=L"0=free; 0xFFFF=end of chain";
        break;
    case 0x6075003eU:
        if(!xx_rt_wcscmp(r->name,L"next_cluster"))s=L"0=free; 0xFFFFFFFF=end of chain";
        break;
    case 0x6075003fU:
        if(!xx_rt_wcscmp(r->name,L"first_cluster"))s=L"Cluster index, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Packed FATX clock: hour/minute/two-second fields";
        else if(!xx_rt_wcscmp(r->name,L"modification_date"))s=L"Packed FATX calendar date; year field is relative to 2000";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Packed FATX clock: hour/minute/two-second fields";
        else if(!xx_rt_wcscmp(r->name,L"creation_date"))s=L"Packed FATX calendar date; year field is relative to 2000";
        else if(!xx_rt_wcscmp(r->name,L"access_time"))s=L"Packed FATX clock: hour/minute/two-second fields";
        else if(!xx_rt_wcscmp(r->name,L"access_date"))s=L"Packed FATX calendar date; year field is relative to 2000";
        break;
    case 0x60750040U:
        if(!xx_rt_wcscmp(r->name,L"root_directory_sector"))s=L"Logical sector index in 2048-byte units";
        else if(!xx_rt_wcscmp(r->name,L"creation_filetime"))s=L"Windows FILETIME: 100-nanosecond ticks since 1601-01-01 UTC";
        break;
    case 0x60750041U:
        if(!xx_rt_wcscmp(r->name,L"left_child_words"))s=L"Directory-relative byte offset divided by four; 0/0xFFFF means absent";
        else if(!xx_rt_wcscmp(r->name,L"right_child_words"))s=L"Directory-relative byte offset divided by four; 0/0xFFFF means absent";
        else if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"Logical sector index in 2048-byte units";
        break;
    case 0x60750042U:
        if(!xx_rt_wcscmp(r->name,L"opaque_identifier"))s=L"Unknown producer metadata, possibly a serial number";
        break;
    case 0x60750043U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Starting logical block in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"block_count"))s=L"Partition length in 512-byte blocks";
        else if(!xx_rt_wcscmp(r->name,L"opaque_metadata"))s=L"Native reader requires zero";
        break;
    case 0x60750044U:
        if(!xx_rt_wcscmp(r->name,L"unpartitioned_blocks"))s=L"Number of 512-byte blocks outside the partition map";
        break;
    case 0x60750047U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Starting logical block in 512-byte units";
        break;
    case 0x60750048U:
        if(!xx_rt_wcscmp(r->name,L"block_count"))s=L"Partition length in 512-byte blocks";
        else if(!xx_rt_wcscmp(r->name,L"drive_switch"))s=L"Drive-switch metadata for a two-drive configuration";
        break;
    case 0x60750049U:
        if(!xx_rt_wcscmp(r->name,L"block_kind"))s=L"ASCII T denotes a track descriptor";
        break;
    case 0x6075004aU:
        if(!xx_rt_wcscmp(r->name,L"block_kind"))s=L"ASCII T denotes a track descriptor";
        break;
    case 0x6075004bU:
        if(!xx_rt_wcscmp(r->name,L"block_kind"))s=L"ASCII S denotes sector bytes";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed image base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXDLEG_LIMIT 24000U
static bool sxdleg_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxdleg_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxdleg_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxdleg16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
static uint32_t sxdleg32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxdleg16(b,0)<<16|sxdleg16(b+2,0);return o==1?(uint32_t)sxdleg16(b,1)<<16|sxdleg16(b+2,1):(uint32_t)sxdleg16(b+2,0)<<16|sxdleg16(b,0);}
static bool sxdleg_pow(uint64_t v){return v&&!(v&(v-1));}
static bool sxdleg_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxdleg_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXDLEG_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static uint64_t sxdleg64(const uint8_t*b){return (uint64_t)sxdleg32(b+4,0)<<32|sxdleg32(b,0);}
static bool sxdleg_shrinkwrap(sx_context*c){uint8_t h[84];if(!sxdleg_read(c,0,h,84)||h[0]>63||sxdleg16(h+82,1)!=256)return false;return SXDLEG_ADD(c,shrinkwrap_header,0);}
static bool sxdleg_jv3(sx_context*c){uint8_t h[8704];uint64_t p=0;for(unsigned block=0;block<4&&c->count<SXDLEG_LIMIT;block++){
 if(!sxdleg_read(c,p,h,sizeof(h)))break;if(!SXDLEG_TABLE(c,jv3_sector_descriptor,p,2901)||!SXDLEG_ADD(c,jv3_write_protection,p+8703))return false;uint64_t next=p+8704;
 for(unsigned i=0;i<2901;i++){const uint8_t*e=h+3*i;bool free=e[0]==255&&e[1]==255;unsigned code=e[2]&3;static const unsigned used[4]={256,128,1024,512},unused[4]={512,1024,128,256};unsigned n=free?unused[code]:used[code];if(!sxdleg_span(c,next,n))return true;next+=n;}
 if(next<=p)return false;p=next;if(p==(uint64_t)c->size)break;}return c->count!=0;}
static bool sxdleg_xdim(sx_context*c){uint8_t h[256];return sxdleg_read(c,0,h,256)&&!xx_rt_memcmp(h+171,"DIFC HEADER",11)&&SXDLEG_ADD(c,x68000_dim_header,0);}
static bool sxdleg_dart(sx_context*c){uint8_t h[4];if(!sxdleg_read(c,0,h,4)||h[0]>2)return false;unsigned kib=sxdleg16(h+2,1),n=kib<=800?40:72;if(!kib||!sxdleg_span(c,4,n*2))return false;return SXDLEG_ADD(c,dart_header,0)&&SXDLEG_TABLE(c,dart_block_length,4,n);}
static bool sxdleg_mdx(sx_context*c){uint8_t h[64];if(!sxdleg_read(c,0,h,48)||xx_rt_memcmp(h,"MEDIA DESCRIPTOR",16)||h[16]!=2)return false;uint64_t key=sxdleg32(h+44,0);if(key==UINT32_MAX){if(!sxdleg_read(c,48,h+48,16)||!SXDLEG_ADD(c,mdx_header,0))return false;uint64_t p=sxdleg64(h+48),n=sxdleg64(h+56);if(p<64||n<=64||n>16777280||!sxdleg_span(c,p,n)||!sxdleg_span(c,p+n-64,512))return true;key=p+n-64;
 }else if(!SXDLEG_ADD(c,mds2_header,0))return false;if(key>=48&&sxdleg_span(c,key,512))return SXDLEG_ADD(c,mdx_key_salt,key);return true;}
static bool sxdleg_ldbs(sx_context*c){uint8_t h[20],b[18];if(!sxdleg_read(c,0,h,20)||xx_rt_memcmp(h,"LBS\1DSK\2",8)||!SXDLEG_ADD(c,ldbs_header,0))return false;
 for(uint64_t p=20,walk=0;walk<32768&&p<(uint64_t)c->size&&c->count<SXDLEG_LIMIT;walk++){if(!sxdleg_read(c,p,h,20)||xx_rt_memcmp(h,"LDB\1",4))break;uint32_t alloc=sxdleg32(h+8,0),used=sxdleg32(h+12,0);if(used>alloc||!sxdleg_span(c,p+20,alloc))break;if(!sxdleg_put(c,h[4]=='T'?&sxdleg_ldbs_track_block_header:h[4]=='S'?&sxdleg_ldbs_sector_block_header:&sxdleg_ldbs_block_header,p,1))return false;uint64_t q=p+20;
 if(!xx_rt_memcmp(h+4,"DIR\1",4)&&used>=2&&sxdleg_read(c,q,b,2)){unsigned n=sxdleg16(b,0);if(n<=(used-2)/8){if(!SXDLEG_ADD(c,ldbs_directory_header,q))return false;for(unsigned j=0;j<n;j++){uint8_t tag;if(!sxdleg_read(c,q+2+(uint64_t)j*8,&tag,1))return false;if(!sxdleg_put(c,tag=='T'?&sxdleg_ldbs_track_directory_entry:&sxdleg_ldbs_directory_entry,q+2+(uint64_t)j*8,1))return false;}}}
 else if(h[4]=='T'&&used>=12&&sxdleg_read(c,q,b,12)){unsigned z=sxdleg16(b,0),step=sxdleg16(b+2,0),n=sxdleg16(b+4,0);if(z>=12&&z<=used&&step>=16&&n<=64&&n<=(used-z)/step){if(!SXDLEG_ADD(c,ldbs_track_header,q))return false;for(unsigned i=0;i<n;i++)if(!sxdleg_put(c,step>=18?&sxdleg_ldbs_sector18:&sxdleg_ldbs_sector16,q+z+(uint64_t)i*step,1))return false;}}
 else if(!xx_rt_memcmp(h+4,"GEOM",4)&&used>=15&&!SXDLEG_ADD(c,ldbs_geometry,q))return false;p=q+alloc;
 }return true;}
static bool sxdleg_dim(sx_context*c){uint8_t h[32];return sxdleg_read(c,0,h,32)&&sxdleg16(h,1)==0x4242&&SXDLEG_ADD(c,atari_dim_header,0);}
static bool sxdleg_stt(sx_context*c){uint8_t h[14],e[10];if(!sxdleg_read(c,0,h,14)||xx_rt_memcmp(h,"STEM",4))return false;unsigned tracks=sxdleg16(h+10,0),sides=sxdleg16(h+12,0);if(!tracks||tracks>86||!sides||sides>2||!sxdleg_span(c,14,tracks*sides*6)||!SXDLEG_ADD(c,stt_header,0)||!SXDLEG_TABLE(c,stt_track_entry,14,tracks*sides))return false;
 for(unsigned i=0;i<tracks*sides;i++){if(!sxdleg_read(c,14+i*6,e,6))return false;uint64_t p=sxdleg32(e,0),z=sxdleg16(e+4,0);if(z<6||!sxdleg_span(c,p,z)||!sxdleg_read(c,p,e,6)||xx_rt_memcmp(e,"TRCK",4))continue;if(!SXDLEG_ADD(c,stt_track_header,p))return false;unsigned flags=sxdleg16(e+4,0);uint64_t q=6;
 for(unsigned bit=0;bit<16;bit++){if(!(flags&(1U<<bit)))continue;unsigned head=bit==0?6:bit==1?8:2;if(head>z-q||!sxdleg_read(c,p+q,e,head))break;unsigned end=sxdleg16(e,0);if(end<q+head||end>z)break;const sx_layout*l=bit==0?&sxdleg_stt_sector_section:bit==1?&sxdleg_stt_raw_section:&sxdleg_stt_unknown_section;if(!sxdleg_put(c,l,p+q,1))return false;if(bit==0){unsigned n=sxdleg16(e+4,0);if(n>256||n>(end-q-6)/10)break;if(!SXDLEG_TABLE(c,stt_sector_descriptor,p+q+6,n))return false;}q=end;}
 }return true;}
static bool sxdleg_stw(sx_context*c){uint8_t h[10];if(!sxdleg_read(c,0,h,10)||xx_rt_memcmp(h,"STW\0",4))return false;unsigned sides=h[6],tracks=h[7],words=sxdleg16(h+8,1);if(!sides||sides>2||!tracks||tracks>170||words<128||words>32768||!SXDLEG_ADD(c,stw_header,0))return false;uint64_t step=5+(uint64_t)words*2;for(unsigned i=0;i<sides*tracks;i++){uint64_t p=10+i*step;if(!sxdleg_span(c,p,step))break;if(!SXDLEG_ADD(c,stw_track_header,p))return false;}return true;}
static bool sxdleg_dfi(sx_context*c){uint8_t h[10];if(!sxdleg_read(c,0,h,4)||(xx_rt_memcmp(h,"DFER",4)&&xx_rt_memcmp(h,"DFE2",4))||!SXDLEG_ADD(c,discferret_header,0))return false;uint64_t p=4;for(unsigned i=0;i<1024&&p<(uint64_t)c->size;i++){if(!sxdleg_read(c,p,h,10))break;uint64_t n=sxdleg32(h+6,1);if(!sxdleg_span(c,p+10,n))break;if(!SXDLEG_ADD(c,discferret_capture,p))return false;p+=10+n;}return true;}
static bool sxdleg_tag(sx_context*c,uint64_t p,const char*s,size_t size){uint8_t b[16];return size<=16&&sxdleg_read(c,p,b,size)&&!xx_rt_memcmp(b,s,size);}
static bool sxdleg_afi(sx_context*c){uint8_t h[54],e[4];if(!sxdleg_read(c,0,h,32)||xx_rt_memcmp(h,"AFI_FLOPPY_IMG",13)||!SXDLEG_ADD(c,afi_header,0))return false;uint64_t info=sxdleg32(h+22,0),list=sxdleg32(h+26,0);if(info<32||!sxdleg_read(c,info,h,54)||xx_rt_memcmp(h,"AFI_INFO",8))return true;uint32_t n=sxdleg32(h+48,0);if(n>256||!sxdleg_span(c,info,54+(uint64_t)n*4))return true;if(!SXDLEG_ADD(c,afi_info,info)||!SXDLEG_TABLE(c,afi_string_offset,info+52,n)||!SXDLEG_ADD(c,afi_crc,info+52+(uint64_t)n*4))return false;
 for(unsigned i=0;i<n;i++){if(!sxdleg_read(c,info+52+i*4,e,4))return false;uint64_t p=info+sxdleg32(e,0);if(!sxdleg_read(c,p,h,36)||xx_rt_memcmp(h,"STRING",6))continue;uint64_t z=sxdleg32(h+32,0);if(z>1048576||!sxdleg_span(c,p,38+z))continue;if(!SXDLEG_ADD(c,afi_string,p)||!SXDLEG_ADD(c,afi_crc,p+36+z))return false;}
 if(list<32||!sxdleg_read(c,list,h,20)||xx_rt_memcmp(h,"TRACKLIST",9))return true;n=sxdleg32(h+16,0);if(n>340||!sxdleg_span(c,list,22+(uint64_t)n*4))return true;if(!SXDLEG_ADD(c,afi_track_list,list)||!SXDLEG_TABLE(c,afi_track_offset,list+20,n)||!SXDLEG_ADD(c,afi_crc,list+20+(uint64_t)n*4))return false;
 for(unsigned i=0;i<n;i++){if(!sxdleg_read(c,list+20+i*4,e,4))return false;uint64_t p=list+sxdleg32(e,0);if(!sxdleg_read(c,p,h,36)||xx_rt_memcmp(h,"TRACK",5))continue;unsigned chunks=sxdleg32(h+32,0);if(chunks>16||!sxdleg_span(c,p,38+(uint64_t)chunks*4))continue;if(!SXDLEG_ADD(c,afi_track,p)||!SXDLEG_TABLE(c,afi_data_offset,p+36,chunks)||!SXDLEG_ADD(c,afi_crc,p+36+(uint64_t)chunks*4))return false;
 for(unsigned j=0;j<chunks;j++){if(!sxdleg_read(c,p+36+j*4,e,4))return false;uint64_t d=p+sxdleg32(e,0);if(!sxdleg_read(c,d,h,52)||xx_rt_memcmp(h,"TRACKDATA",9))continue;uint64_t z=sxdleg32(h+40,0);if(!sxdleg_span(c,d,54+z))continue;if(!SXDLEG_ADD(c,afi_data,d)||!SXDLEG_ADD(c,afi_crc,d+52+z))return false;}}
 return true;}
static bool sxdleg_qd(sx_context*c){uint8_t h[40];if(!sxdleg_read(c,0,h,40)||xx_rt_memcmp(h,"HXCQDDRV",8)||!SXDLEG_ADD(c,hxc_qd_header,0))return false;uint64_t tracks=sxdleg32(h+12,0),sides=sxdleg32(h+16,0),p=sxdleg32(h+36,0);if(!tracks||tracks>170||!sides||sides>2||p<40||!sxdleg_span(c,p,tracks*sides*16))return true;return SXDLEG_TABLE(c,hxc_qd_track,p,tracks*sides);}
static bool sxdleg_stream(sx_context*c){uint8_t h[20];uint64_t p=0;for(unsigned i=0;i<1024&&p<(uint64_t)c->size&&c->count<SXDLEG_LIMIT;i++){if(!sxdleg_read(c,p,h,12)||xx_rt_memcmp(h,"CHKH",4))break;uint64_t z=sxdleg32(h+4,0);if(z<24||z%4||!sxdleg_span(c,p,z))break;if(!SXDLEG_ADD(c,hxc_stream_chunk,p)||!SXDLEG_ADD(c,hxc_stream_crc,p+z-4))return false;uint64_t q=p+12,end=p+z-4;for(unsigned j=0;j<64&&q<end;j++){if(end-q<8||!sxdleg_read(c,q,h,8))break;uint64_t n=sxdleg32(h+4,0);unsigned type=sxdleg32(h,0),head=type==0?8:type==1?16:type==2?20:0;if(!head||n>end-q-8||head>8+n)break;const sx_layout*l=type==0?&sxdleg_hxc_stream_metadata:type==1?&sxdleg_hxc_stream_io:&sxdleg_hxc_stream_flux;if(!sxdleg_put(c,l,q,1))return false;q+=8+n;}p+=z;}return c->count!=0;}
static bool sxdleg_oric(sx_context*c){uint8_t h[8];if(!sxdleg_read(c,0,h,8))return false;const sx_layout*l=!xx_rt_memcmp(h,"ORICDISK",8)?&sxdleg_oric_sector_header:!xx_rt_memcmp(h,"MFM_DISK",8)?&sxdleg_oric_mfm_header:NULL;return l&&sxdleg_put(c,l,0,1);}
static bool sxdleg_gkh(sx_context*c){uint8_t h[10];if(!sxdleg_read(c,0,h,8)||xx_rt_memcmp(h,"TDDFI\1",6))return false;unsigned n=sxdleg16(h+6,0);if(n<3||n>5||!sxdleg_span(c,8,n*10)||!SXDLEG_ADD(c,gkh_header,0))return false;for(unsigned i=0;i<n;i++){uint64_t p=8+i*10;if(!sxdleg_read(c,p,h,10))return false;const sx_layout*l=h[0]==1?&sxdleg_gkh_format_tag:h[0]==10?&sxdleg_gkh_geometry_tag:(h[0]==11||h[0]==20||h[0]==21)?&sxdleg_gkh_location_tag:NULL;if(l&&!sxdleg_put(c,l,p,1))return false;}return true;}
static bool sxdleg_ede(sx_context*c){uint8_t h[512];if(!sxdleg_read(c,0,h,512)||h[0]!=13||h[1]!=10||h[78]!=13||h[79]!=10)return false;unsigned t=h[511],heads=t==1?1:2,sectors=t==1||t==2?6:t==203||t==204?20:10,bitmap=t==203||t==204?96:160,n=(80*heads*sectors+7)/8;if(bitmap+n>510)return false;return SXDLEG_ADD(c,ede_text_header,0)&&SXDLEG_ADD(c,ede_bitmap_marker,bitmap-3)&&SXDLEG_TABLE(c,ede_bitmap_byte,bitmap,n)&&SXDLEG_ADD(c,ede_format,510);}
static bool sxdleg_sad(sx_context*c){return sxdleg_tag(c,0,"Aley's disk back",15)&&SXDLEG_ADD(c,sad_header,0);}
static bool sxdleg_trackstar(sx_context*c){if(c->size!=266240&&c->size!=532480)return false;unsigned n=(unsigned)(c->size/6656);for(unsigned i=0;i<n;i++)if(!SXDLEG_ADD(c,trackstar_track_header,(uint64_t)i*6656)||!SXDLEG_ADD(c,trackstar_track_size,(uint64_t)i*6656+6654))return false;return true;}
/* Archive callbacks authenticate physical directory entry coordinates without
 * assuming that an Abstractformat is a specific native-reader allocation. */
static bool sxdleg_archive_entries(sx_context*c,const sx_layout*l,uint64_t width){if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;for(unsigned i=0;i<65536&&c->count<SXDLEG_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>=c->f->base_address&&r->header_size==(int64_t)width){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);if(sxdleg_span(c,p,width)&&!sxdleg_put(c,l,p,1)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static bool sxdleg_fatx(sx_context*c){uint8_t h[16];if(!sxdleg_read(c,0,h,16)||xx_rt_memcmp(h,"FATX",4)||c->size<8704||!SXDLEG_ADD(c,fatx_superblock,0))return false;uint64_t sectors=sxdleg32(h+8,0);if(!sectors||sectors>1024||!sxdleg_pow(sectors))return true;uint64_t cb=sectors*512,nominal=(uint64_t)c->size/cb+1,width=nominal<0xfff0?2:4;if(nominal>UINT64_MAX/width)return true;uint64_t fat=(nominal*width+4095)&~UINT64_C(4095),data=4096+fat;if(data>=(uint64_t)c->size)return true;uint64_t n=((uint64_t)c->size-data)/cb+1;if(n>8000001||n>fat/width)return true;if(n>1048576)n=1048576;if(!sxdleg_put(c,width==2?&sxdleg_fatx_fat16_entry:&sxdleg_fatx_fat32_entry,4096,n))return false;return sxdleg_archive_entries(c,&sxdleg_fatx_directory_entry,64);}
static bool sxdleg_xdvdfs(sx_context*c){uint8_t h[32],e[14];if(!sxdleg_read(c,65536,h,32)||xx_rt_memcmp(h,"MICROSOFT*XBOX*MEDIA",20)||!SXDLEG_ADD(c,xdvdfs_volume_descriptor,65536))return false;uint64_t base=(uint64_t)sxdleg32(h+20,0)*2048,size=sxdleg32(h+24,0);if(size<14||!sxdleg_span(c,base,size))return true;uint32_t todo[1024]={0};unsigned count=1;for(unsigned i=0;i<count;i++){uint64_t p=todo[i];if(p>size||size-p<14||!sxdleg_read(c,base+p,e,14)||e[13]>size-p-14)continue;if(!SXDLEG_ADD(c,xdvdfs_directory_entry,base+p))return false;for(unsigned j=0;j<2;j++){uint32_t child=sxdleg16(e+j*2,0);if(!child||child==65535)continue;child*=4;bool seen=false;for(unsigned k=0;k<count;k++)if(todo[k]==child)seen=true;if(!seen&&count<1024)todo[count++]=child;}}return true;}
static bool sxdleg_focus(sx_context*c){uint8_t h[32];if(!sxdleg_read(c,0,h,32)||xx_rt_memcmp(h,"Parsons Engin.",14)||!h[15]||h[15]>30)return false;return SXDLEG_ADD(c,focusdrive_header,0)&&SXDLEG_TABLE(c,focusdrive_partition,32,h[15])&&SXDLEG_ADD(c,focusdrive_name_header,512)&&SXDLEG_TABLE(c,focusdrive_partition_name,544,h[15]);}
static bool sxdleg_micro(sx_context*c){uint8_t h[32];if(!sxdleg_read(c,0,h,32)||sxdleg16(h,0)!=0xccca||h[12]>8||h[13]>8||(!h[12]&&!h[13])||!SXDLEG_ADD(c,microdrive_header,0))return false;return SXDLEG_TABLE(c,microdrive_start,32,h[12])&&SXDLEG_TABLE(c,microdrive_size,64,h[12])&&SXDLEG_TABLE(c,microdrive_start,128,h[13])&&SXDLEG_TABLE(c,microdrive_size,160,h[13]);}

static int sxdleg_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxdleg_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdleg_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_disklegacy_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_SHRINKWRAP:
case XX_FILE_TYPE_TRS_80_JV3:
case XX_FILE_TYPE_X68000_DIM:
case XX_FILE_TYPE_DART:
case XX_FILE_TYPE_DAEMON_TOOLS_MDX:
case XX_FILE_TYPE_LDBS:
case XX_FILE_TYPE_ATARI_DIM:
case XX_FILE_TYPE_ATARI_STT:
case XX_FILE_TYPE_ATARI_STW:
case XX_FILE_TYPE_DISCFERRET_DFI:
case XX_FILE_TYPE_HXC_AFI:
case XX_FILE_TYPE_HXC_QD:
case XX_FILE_TYPE_HXC_STREAM:
case XX_FILE_TYPE_ORIC_DSK:
case XX_FILE_TYPE_ENSONIQ_GKH:
case XX_FILE_TYPE_ENSONIQ_EDE:
case XX_FILE_TYPE_SAMCOUPE_SAD:
case XX_FILE_TYPE_TRACKSTAR:
case XX_FILE_TYPE_FATX:
case XX_FILE_TYPE_XBOX_XDVDFS:
case XX_FILE_TYPE_FOCUSDRIVE:
case XX_FILE_TYPE_MICRODRIVE:
return true;default:return false;}}
static bool sx_disklegacy_build(sx_context*c){bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_SHRINKWRAP:ok=sxdleg_shrinkwrap(c);break;
case XX_FILE_TYPE_TRS_80_JV3:ok=sxdleg_jv3(c);break;
case XX_FILE_TYPE_X68000_DIM:ok=sxdleg_xdim(c);break;
case XX_FILE_TYPE_DART:ok=sxdleg_dart(c);break;
case XX_FILE_TYPE_DAEMON_TOOLS_MDX:ok=sxdleg_mdx(c);break;
case XX_FILE_TYPE_LDBS:ok=sxdleg_ldbs(c);break;
case XX_FILE_TYPE_ATARI_DIM:ok=sxdleg_dim(c);break;
case XX_FILE_TYPE_ATARI_STT:ok=sxdleg_stt(c);break;
case XX_FILE_TYPE_ATARI_STW:ok=sxdleg_stw(c);break;
case XX_FILE_TYPE_DISCFERRET_DFI:ok=sxdleg_dfi(c);break;
case XX_FILE_TYPE_HXC_AFI:ok=sxdleg_afi(c);break;
case XX_FILE_TYPE_HXC_QD:ok=sxdleg_qd(c);break;
case XX_FILE_TYPE_HXC_STREAM:ok=sxdleg_stream(c);break;
case XX_FILE_TYPE_ORIC_DSK:ok=sxdleg_oric(c);break;
case XX_FILE_TYPE_ENSONIQ_GKH:ok=sxdleg_gkh(c);break;
case XX_FILE_TYPE_ENSONIQ_EDE:ok=sxdleg_ede(c);break;
case XX_FILE_TYPE_SAMCOUPE_SAD:ok=sxdleg_sad(c);break;
case XX_FILE_TYPE_TRACKSTAR:ok=sxdleg_trackstar(c);break;
case XX_FILE_TYPE_FATX:ok=sxdleg_fatx(c);break;
case XX_FILE_TYPE_XBOX_XDVDFS:ok=sxdleg_xdvdfs(c);break;
case XX_FILE_TYPE_FOCUSDRIVE:ok=sxdleg_focus(c);break;
case XX_FILE_TYPE_MICRODRIVE:ok=sxdleg_micro(c);break;
default:return false;}return (ok||c->count)&&c->count&&!c->failed&&!xx_pd_is_stopped(c->pd)&&sxdleg_finish(c);}
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
#undef SXDLEG_LIMIT
