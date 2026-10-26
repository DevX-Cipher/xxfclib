/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical disk-volume and forensic-image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_volumeimages_scope.txt. */

static const xx_data_struct_field_desc sxvi_lvm2_label_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("sector_number","uint64",8,8,SX_NONE),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("pv_header_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("type","char[8]",24,8,SX_STRING),
};
static const sx_layout sxvi_lvm2_label_header = {0x60530001U,"lvm2_label_header",sxvi_lvm2_label_header_fields,SX_COUNT(sxvi_lvm2_label_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_lvm2_pv_header_fields[] = {
    SX_FIELD("pv_uuid","char[32]",0,32,SX_ID),
    SX_FIELD("device_size","uint64",32,8,SX_SIZE),
};
static const sx_layout sxvi_lvm2_pv_header = {0x60530002U,"lvm2_pv_header",sxvi_lvm2_pv_header_fields,SX_COUNT(sxvi_lvm2_pv_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_lvm2_disk_location_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("size","uint64",8,8,SX_SIZE),
};
static const sx_layout sxvi_lvm2_disk_location = {0x60530003U,"lvm2_disk_location",sxvi_lvm2_disk_location_fields,SX_COUNT(sxvi_lvm2_disk_location_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_lvm2_pv_extension_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxvi_lvm2_pv_extension = {0x60530004U,"lvm2_pv_extension",sxvi_lvm2_pv_extension_fields,SX_COUNT(sxvi_lvm2_pv_extension_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_lvm2_mda_header_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("magic","char[16]",4,16,SX_SIGNATURE),
    SX_FIELD("version","uint32",20,4,SX_ID),
    SX_FIELD("start","uint64",24,8,SX_OFFSET),
    SX_FIELD("size","uint64",32,8,SX_SIZE),
};
static const sx_layout sxvi_lvm2_mda_header = {0x60530005U,"lvm2_mda_header",sxvi_lvm2_mda_header_fields,SX_COUNT(sxvi_lvm2_mda_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_lvm2_raw_location_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("size","uint64",8,8,SX_SIZE),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
};
static const sx_layout sxvi_lvm2_raw_location = {0x60530006U,"lvm2_raw_location",sxvi_lvm2_raw_location_fields,SX_COUNT(sxvi_lvm2_raw_location_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_file_header_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("fields_start","uint8",8,1,SX_SIGNATURE),
    SX_FIELD("segment_number","uint16",9,2,SX_ID),
    SX_FIELD("fields_end","uint16",11,2,SX_RESERVED),
};
static const sx_layout sxvi_ewf1_file_header = {0x60530007U,"ewf1_file_header",sxvi_ewf1_file_header_fields,SX_COUNT(sxvi_ewf1_file_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_section_descriptor_fields[] = {
    SX_FIELD("type","char[16]",0,16,SX_STRING),
    SX_FIELD("next_descriptor_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("section_size","uint64",24,8,SX_SIZE),
    SX_FIELD("padding","byte[40]",32,40,SX_RESERVED),
    SX_FIELD("adler32","uint32",72,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_section_descriptor = {0x60530008U,"ewf1_section_descriptor",sxvi_ewf1_section_descriptor_fields,SX_COUNT(sxvi_ewf1_section_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_volume_fields[] = {
    SX_FIELD("media_type","uint8",0,1,SX_ID),
    SX_FIELD("unknown0","byte[3]",1,3,SX_NONE),
    SX_FIELD("chunk_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_chunk","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint32",12,4,SX_SIZE),
    SX_FIELD("sector_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("media_flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("unknown1","byte[3]",37,3,SX_NONE),
    SX_FIELD("palm_start_sector","uint32",40,4,SX_NONE),
    SX_FIELD("unknown2","byte[4]",44,4,SX_NONE),
    SX_FIELD("smart_logs_distance","uint32",48,4,SX_NONE),
    SX_FIELD("compression_level","uint8",52,1,SX_ID),
    SX_FIELD("unknown3","byte[3]",53,3,SX_NONE),
    SX_FIELD("error_granularity","uint32",56,4,SX_NONE),
    SX_FIELD("unknown4","byte[4]",60,4,SX_NONE),
    SX_FIELD("segment_set_identifier","byte[16]",64,16,SX_ID),
    SX_FIELD("unknown5","byte[963]",80,963,SX_NONE),
    SX_FIELD("reserved_signature","byte[5]",1043,5,SX_NONE),
    SX_FIELD("adler32","uint32",1048,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_volume = {0x60530009U,"ewf1_volume",sxvi_ewf1_volume_fields,SX_COUNT(sxvi_ewf1_volume_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_logical_volume_fields[] = {
    SX_FIELD("media_type","uint8",0,1,SX_ID),
    SX_FIELD("unknown0","byte[3]",1,3,SX_NONE),
    SX_FIELD("chunk_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_chunk","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint32",12,4,SX_SIZE),
    SX_FIELD("logical_sector_value","uint64",16,8,SX_NONE),
    SX_FIELD("cylinders","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("media_flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("unknown1","byte[3]",37,3,SX_NONE),
    SX_FIELD("palm_start_sector","uint32",40,4,SX_NONE),
    SX_FIELD("unknown2","byte[4]",44,4,SX_NONE),
    SX_FIELD("smart_logs_distance","uint32",48,4,SX_NONE),
    SX_FIELD("compression_level","uint8",52,1,SX_ID),
    SX_FIELD("unknown3","byte[3]",53,3,SX_NONE),
    SX_FIELD("error_granularity","uint32",56,4,SX_NONE),
    SX_FIELD("unknown4","byte[4]",60,4,SX_NONE),
    SX_FIELD("segment_set_identifier","byte[16]",64,16,SX_ID),
    SX_FIELD("unknown5","byte[963]",80,963,SX_NONE),
    SX_FIELD("reserved_signature","byte[5]",1043,5,SX_NONE),
    SX_FIELD("adler32","uint32",1048,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_logical_volume = {0x6053000aU,"ewf1_logical_volume",sxvi_ewf1_logical_volume_fields,SX_COUNT(sxvi_ewf1_logical_volume_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_smart_volume_fields[] = {
    SX_FIELD("reserved0","uint32",0,4,SX_RESERVED),
    SX_FIELD("chunk_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_chunk","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint32",12,4,SX_SIZE),
    SX_FIELD("sector_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[20]",20,20,SX_RESERVED),
    SX_FIELD("padding","byte[45]",40,45,SX_RESERVED),
    SX_FIELD("signature","char[5]",85,5,SX_SIGNATURE),
    SX_FIELD("adler32","uint32",90,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_smart_volume = {0x6053000bU,"ewf1_smart_volume",sxvi_ewf1_smart_volume_fields,SX_COUNT(sxvi_ewf1_smart_volume_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_table_header_fields[] = {
    SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("padding0","byte[4]",4,4,SX_RESERVED),
    SX_FIELD("base_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("padding1","byte[4]",16,4,SX_RESERVED),
    SX_FIELD("adler32","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_table_header = {0x6053000cU,"ewf1_table_header",sxvi_ewf1_table_header_fields,SX_COUNT(sxvi_ewf1_table_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_chunk_entry_fields[] = {
    SX_FIELD("offset_and_compression","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxvi_ewf1_chunk_entry = {0x6053000dU,"ewf1_chunk_entry",sxvi_ewf1_chunk_entry_fields,SX_COUNT(sxvi_ewf1_chunk_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_image_adler32_fields[] = {
    SX_FIELD("adler32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxvi_image_adler32 = {0x6053000eU,"image_adler32",sxvi_image_adler32_fields,SX_COUNT(sxvi_image_adler32_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_hash_fields[] = {
    SX_FIELD("md5","byte[16]",0,16,SX_CHECKSUM),
    SX_FIELD("unknown","byte[16]",16,16,SX_NONE),
    SX_FIELD("adler32","uint32",32,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_hash = {0x6053000fU,"ewf1_hash",sxvi_ewf1_hash_fields,SX_COUNT(sxvi_ewf1_hash_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_digest_fields[] = {
    SX_FIELD("md5","byte[16]",0,16,SX_CHECKSUM),
    SX_FIELD("sha1","byte[20]",16,20,SX_CHECKSUM),
    SX_FIELD("padding","byte[40]",36,40,SX_RESERVED),
    SX_FIELD("adler32","uint32",76,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf1_digest = {0x60530010U,"ewf1_digest",sxvi_ewf1_digest_fields,SX_COUNT(sxvi_ewf1_digest_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf1_ltree_header_fields[] = {
    SX_FIELD("md5","byte[16]",0,16,SX_CHECKSUM),
    SX_FIELD("data_size","uint64",16,8,SX_SIZE),
    SX_FIELD("adler32","uint32",24,4,SX_CHECKSUM),
    SX_FIELD("unknown","byte[20]",28,20,SX_NONE),
};
static const sx_layout sxvi_ewf1_ltree_header = {0x60530011U,"ewf1_ltree_header",sxvi_ewf1_ltree_header_fields,SX_COUNT(sxvi_ewf1_ltree_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf2_file_header_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("major_version","uint8",8,1,SX_ID),
    SX_FIELD("minor_version","uint8",9,1,SX_ID),
    SX_FIELD("compression_method","uint16",10,2,SX_ID),
    SX_FIELD("segment_number","uint32",12,4,SX_ID),
    SX_FIELD("set_identifier","byte[16]",16,16,SX_ID),
};
static const sx_layout sxvi_ewf2_file_header = {0x60530012U,"ewf2_file_header",sxvi_ewf2_file_header_fields,SX_COUNT(sxvi_ewf2_file_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf2_section_descriptor_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint32",4,4,SX_FLAGS),
    SX_FIELD("previous_descriptor_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("data_size","uint64",16,8,SX_SIZE),
    SX_FIELD("descriptor_size","uint32",24,4,SX_SIZE),
    SX_FIELD("padding_size","uint32",28,4,SX_SIZE),
    SX_FIELD("data_md5","byte[16]",32,16,SX_CHECKSUM),
    SX_FIELD("reserved","byte[12]",48,12,SX_RESERVED),
    SX_FIELD("adler32","uint32",60,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf2_section_descriptor = {0x60530013U,"ewf2_section_descriptor",sxvi_ewf2_section_descriptor_fields,SX_COUNT(sxvi_ewf2_section_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf2_table_header_fields[] = {
    SX_FIELD("first_chunk_number","uint64",0,8,SX_NONE),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved0","uint32",12,4,SX_RESERVED),
    SX_FIELD("adler32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("padding","byte[12]",20,12,SX_RESERVED),
};
static const sx_layout sxvi_ewf2_table_header = {0x60530014U,"ewf2_table_header",sxvi_ewf2_table_header_fields,SX_COUNT(sxvi_ewf2_table_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf2_chunk_entry_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("stored_size","uint32",8,4,SX_SIZE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxvi_ewf2_chunk_entry = {0x60530015U,"ewf2_chunk_entry",sxvi_ewf2_chunk_entry_fields,SX_COUNT(sxvi_ewf2_chunk_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf2_pattern_entry_fields[] = {
    SX_FIELD("fill_pattern","byte[8]",0,8,SX_NONE),
    SX_FIELD("stored_size","uint32",8,4,SX_SIZE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxvi_ewf2_pattern_entry = {0x60530016U,"ewf2_pattern_entry",sxvi_ewf2_pattern_entry_fields,SX_COUNT(sxvi_ewf2_pattern_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf2_md5_fields[] = {
    SX_FIELD("md5","byte[16]",0,16,SX_CHECKSUM),
    SX_FIELD("adler32","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf2_md5 = {0x60530017U,"ewf2_md5",sxvi_ewf2_md5_fields,SX_COUNT(sxvi_ewf2_md5_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ewf2_sha1_fields[] = {
    SX_FIELD("sha1","byte[20]",0,20,SX_CHECKSUM),
    SX_FIELD("adler32","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxvi_ewf2_sha1 = {0x60530018U,"ewf2_sha1",sxvi_ewf2_sha1_fields,SX_COUNT(sxvi_ewf2_sha1_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_uif_trailer_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("trailer_size","uint32",4,4,SX_SIZE),
    SX_FIELD("version","uint16",8,2,SX_ID),
    SX_FIELD("image_type","uint16",10,2,SX_ID),
    SX_FIELD("unknown","uint16",12,2,SX_NONE),
    SX_FIELD("padding","uint16",14,2,SX_RESERVED),
    SX_FIELD("sector_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("sector_size","uint32",20,4,SX_SIZE),
    SX_FIELD("last_sector_bytes","uint32",24,4,SX_SIZE),
    SX_FIELD("block_table_offset","uint64",28,8,SX_OFFSET),
    SX_FIELD("block_table_size","uint32",36,4,SX_SIZE),
    SX_FIELD("hash","byte[16]",40,16,SX_NONE),
    SX_FIELD("fixed_key_index","uint8",56,1,SX_ID),
    SX_FIELD("cipher","uint8",57,1,SX_ID),
    SX_FIELD("cipher_parameters0","byte[2]",58,2,SX_NONE),
    SX_FIELD("cipher_parameters1","uint32",60,4,SX_NONE),
};
static const sx_layout sxvi_uif_trailer = {0x60530019U,"uif_trailer",sxvi_uif_trailer_fields,SX_COUNT(sxvi_uif_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_uif_table_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("compressed","uint32",8,4,SX_FLAGS),
    SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxvi_uif_table_header = {0x6053001aU,"uif_table_header",sxvi_uif_table_header_fields,SX_COUNT(sxvi_uif_table_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_uif_block_entry_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("stored_size","uint32",8,4,SX_SIZE),
    SX_FIELD("first_sector","uint32",12,4,SX_NONE),
    SX_FIELD("sector_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("type","uint32",20,4,SX_ID),
};
static const sx_layout sxvi_uif_block_entry = {0x6053001bU,"uif_block_entry",sxvi_uif_block_entry_fields,SX_COUNT(sxvi_uif_block_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_uif_descriptor_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("compressed","uint32",8,4,SX_FLAGS),
    SX_FIELD("original_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxvi_uif_descriptor_header = {0x6053001cU,"uif_descriptor_header",sxvi_uif_descriptor_header_fields,SX_COUNT(sxvi_uif_descriptor_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_uif_output_format_fields[] = {
    SX_FIELD("output_format","uint32",0,4,SX_ID),
};
static const sx_layout sxvi_uif_output_format = {0x6053001dU,"uif_output_format",sxvi_uif_output_format_fields,SX_COUNT(sxvi_uif_output_format_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_gbi_header100_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("table_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("version","uint32",20,4,SX_ID),
    SX_FIELD("data_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("marker","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("reserved0","uint32",32,4,SX_RESERVED),
    SX_FIELD("chunk_size","uint32",36,4,SX_SIZE),
    SX_FIELD("image_size","uint64",40,8,SX_SIZE),
    SX_FIELD("container_size","uint64",48,8,SX_SIZE),
    SX_FIELD("reserved1","byte[16]",56,16,SX_RESERVED),
    SX_FIELD("crc32","uint32",72,4,SX_CHECKSUM),
};
static const sx_layout sxvi_gbi_header100 = {0x6053001eU,"gbi_header100",sxvi_gbi_header100_fields,SX_COUNT(sxvi_gbi_header100_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_gbi_header110_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("table_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("version","uint32",20,4,SX_ID),
    SX_FIELD("encoded_data_offset","uint32",24,4,SX_FLAGS),
    SX_FIELD("marker","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("reserved0","uint32",32,4,SX_RESERVED),
    SX_FIELD("chunk_size_and_flags","uint32",36,4,SX_FLAGS),
    SX_FIELD("image_size","uint64",40,8,SX_SIZE),
    SX_FIELD("container_size","uint64",48,8,SX_SIZE),
    SX_FIELD("profile","uint8",56,1,SX_ID),
    SX_FIELD("compressed_table_size","uint32",57,4,SX_SIZE),
    SX_FIELD("table_bit_widths","uint8",61,1,SX_FLAGS),
    SX_FIELD("lzma_filter","uint8",62,1,SX_ID),
    SX_FIELD("lzma_properties","byte[5]",63,5,SX_NONE),
    SX_FIELD("reserved1","byte[4]",68,4,SX_RESERVED),
    SX_FIELD("crc32","uint32",72,4,SX_CHECKSUM),
};
static const sx_layout sxvi_gbi_header110 = {0x6053001fU,"gbi_header110",sxvi_gbi_header110_fields,SX_COUNT(sxvi_gbi_header110_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_gbi_descriptor_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxvi_gbi_descriptor = {0x60530020U,"gbi_descriptor",sxvi_gbi_descriptor_fields,SX_COUNT(sxvi_gbi_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_gbi_part_count_fields[] = {
    SX_FIELD("part_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxvi_gbi_part_count = {0x60530021U,"gbi_part_count",sxvi_gbi_part_count_fields,SX_COUNT(sxvi_gbi_part_count_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_zisofs_header_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size_words","uint8",12,1,SX_NONE),
    SX_FIELD("block_size_log2","uint8",13,1,SX_NONE),
    SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
};
static const sx_layout sxvi_zisofs_header = {0x60530022U,"zisofs_header",sxvi_zisofs_header_fields,SX_COUNT(sxvi_zisofs_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_zisofs_block_pointer_fields[] = {
    SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxvi_zisofs_block_pointer = {0x60530023U,"zisofs_block_pointer",sxvi_zisofs_block_pointer_fields,SX_COUNT(sxvi_zisofs_block_pointer_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_header_fields[] = {
    SX_FIELD("magic","char[13]",0,13,SX_SIGNATURE),
    SX_FIELD("version","uint32",13,4,SX_ID),
};
static const sx_layout sxvi_btrfs_send_header = {0x60530024U,"btrfs_send_header",sxvi_btrfs_send_header_fields,SX_COUNT(sxvi_btrfs_send_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_command_fields[] = {
    SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
    SX_FIELD("command","uint16",4,2,SX_ID),
    SX_FIELD("crc32c","uint32",6,4,SX_CHECKSUM),
};
static const sx_layout sxvi_btrfs_send_command = {0x60530025U,"btrfs_send_command",sxvi_btrfs_send_command_fields,SX_COUNT(sxvi_btrfs_send_command_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_attribute_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("value_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxvi_btrfs_send_attribute = {0x60530026U,"btrfs_send_attribute",sxvi_btrfs_send_attribute_fields,SX_COUNT(sxvi_btrfs_send_attribute_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_data_attribute_v2_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
};
static const sx_layout sxvi_btrfs_send_data_attribute_v2 = {0x60530027U,"btrfs_send_data_attribute_v2",sxvi_btrfs_send_data_attribute_v2_fields,SX_COUNT(sxvi_btrfs_send_data_attribute_v2_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_uuid_fields[] = {
    SX_FIELD("uuid","byte[16]",0,16,SX_ID),
};
static const sx_layout sxvi_btrfs_send_uuid = {0x60530028U,"btrfs_send_uuid",sxvi_btrfs_send_uuid_fields,SX_COUNT(sxvi_btrfs_send_uuid_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_id64_fields[] = {
    SX_FIELD("value","uint64",0,8,SX_ID),
};
static const sx_layout sxvi_btrfs_send_id64 = {0x60530029U,"btrfs_send_id64",sxvi_btrfs_send_id64_fields,SX_COUNT(sxvi_btrfs_send_id64_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_size64_fields[] = {
    SX_FIELD("size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxvi_btrfs_send_size64 = {0x6053002aU,"btrfs_send_size64",sxvi_btrfs_send_size64_fields,SX_COUNT(sxvi_btrfs_send_size64_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_offset64_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxvi_btrfs_send_offset64 = {0x6053002bU,"btrfs_send_offset64",sxvi_btrfs_send_offset64_fields,SX_COUNT(sxvi_btrfs_send_offset64_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_flags64_fields[] = {
    SX_FIELD("flags","uint64",0,8,SX_FLAGS),
};
static const sx_layout sxvi_btrfs_send_flags64 = {0x6053002cU,"btrfs_send_flags64",sxvi_btrfs_send_flags64_fields,SX_COUNT(sxvi_btrfs_send_flags64_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_flags32_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxvi_btrfs_send_flags32 = {0x6053002dU,"btrfs_send_flags32",sxvi_btrfs_send_flags32_fields,SX_COUNT(sxvi_btrfs_send_flags32_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_codec32_fields[] = {
    SX_FIELD("codec","uint32",0,4,SX_ID),
};
static const sx_layout sxvi_btrfs_send_codec32 = {0x6053002eU,"btrfs_send_codec32",sxvi_btrfs_send_codec32_fields,SX_COUNT(sxvi_btrfs_send_codec32_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_btrfs_send_timespec_fields[] = {
    SX_FIELD("seconds","int64",0,8,SX_TIME),
    SX_FIELD("nanoseconds","uint32",8,4,SX_NONE),
};
static const sx_layout sxvi_btrfs_send_timespec = {0x6053002fU,"btrfs_send_timespec",sxvi_btrfs_send_timespec_fields,SX_COUNT(sxvi_btrfs_send_timespec_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_aaru2_header_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("application","char[64]",8,64,SX_STRING),
    SX_FIELD("image_major_version","uint8",72,1,SX_ID),
    SX_FIELD("image_minor_version","uint8",73,1,SX_ID),
    SX_FIELD("application_major_version","uint8",74,1,SX_ID),
    SX_FIELD("application_minor_version","uint8",75,1,SX_ID),
    SX_FIELD("media_type","uint32",76,4,SX_ID),
    SX_FIELD("index_offset","uint64",80,8,SX_OFFSET),
    SX_FIELD("creation_time","int64",88,8,SX_TIME),
    SX_FIELD("last_written_time","int64",96,8,SX_TIME),
    SX_FIELD("guid","byte[16]",104,16,SX_ID),
    SX_FIELD("block_alignment_shift","uint8",120,1,SX_NONE),
    SX_FIELD("biggest_sector_size","uint16",121,2,SX_SIZE),
    SX_FIELD("feature_compatible","uint64",123,8,SX_FLAGS),
    SX_FIELD("feature_compatible_readonly","uint64",131,8,SX_FLAGS),
    SX_FIELD("feature_incompatible","uint64",139,8,SX_FLAGS),
};
static const sx_layout sxvi_aaru2_header = {0x60530030U,"aaru2_header",sxvi_aaru2_header_fields,SX_COUNT(sxvi_aaru2_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_aaru2_ddt_header_fields[] = {
    SX_FIELD("identifier","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("data_type","uint16",4,2,SX_ID),
    SX_FIELD("compression","uint16",6,2,SX_ID),
    SX_FIELD("levels","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("table_level","uint8",9,1,SX_NONE),
    SX_FIELD("previous_level_offset","uint64",10,8,SX_OFFSET),
    SX_FIELD("negative_sectors","uint32",18,4,SX_COUNT_PROP),
    SX_FIELD("blocks","uint64",22,8,SX_COUNT_PROP),
    SX_FIELD("overflow_sectors","uint32",30,4,SX_COUNT_PROP),
    SX_FIELD("start","uint64",34,8,SX_NONE),
    SX_FIELD("block_alignment_shift","uint8",42,1,SX_NONE),
    SX_FIELD("data_shift","uint8",43,1,SX_NONE),
    SX_FIELD("table_shift","uint8",44,1,SX_NONE),
    SX_FIELD("entries","uint64",45,8,SX_COUNT_PROP),
    SX_FIELD("compressed_length","uint64",53,8,SX_SIZE),
    SX_FIELD("length","uint64",61,8,SX_SIZE),
    SX_FIELD("compressed_crc64","uint64",69,8,SX_CHECKSUM),
    SX_FIELD("crc64","uint64",77,8,SX_CHECKSUM),
};
static const sx_layout sxvi_aaru2_ddt_header = {0x60530031U,"aaru2_ddt_header",sxvi_aaru2_ddt_header_fields,SX_COUNT(sxvi_aaru2_ddt_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_aaru2_ddt_entry_fields[] = {
    SX_FIELD("encoded_location","uint64",0,8,SX_FLAGS),
};
static const sx_layout sxvi_aaru2_ddt_entry = {0x60530032U,"aaru2_ddt_entry",sxvi_aaru2_ddt_entry_fields,SX_COUNT(sxvi_aaru2_ddt_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_aaru_index3_fields[] = {
    SX_FIELD("identifier","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("entries","uint64",4,8,SX_COUNT_PROP),
    SX_FIELD("crc64","uint64",12,8,SX_CHECKSUM),
    SX_FIELD("previous","uint64",20,8,SX_OFFSET),
};
static const sx_layout sxvi_aaru_index3 = {0x60530033U,"aaru_index3",sxvi_aaru_index3_fields,SX_COUNT(sxvi_aaru_index3_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_aaru_index_entry_fields[] = {
    SX_FIELD("block_type","uint32",0,4,SX_ID),
    SX_FIELD("data_type","uint16",4,2,SX_ID),
    SX_FIELD("offset","uint64",6,8,SX_OFFSET),
};
static const sx_layout sxvi_aaru_index_entry = {0x60530034U,"aaru_index_entry",sxvi_aaru_index_entry_fields,SX_COUNT(sxvi_aaru_index_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_aaru_data_header_fields[] = {
    SX_FIELD("identifier","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("data_type","uint16",4,2,SX_ID),
    SX_FIELD("compression","uint16",6,2,SX_ID),
    SX_FIELD("sector_size","uint32",8,4,SX_SIZE),
    SX_FIELD("compressed_length","uint32",12,4,SX_SIZE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("compressed_crc64","uint64",20,8,SX_CHECKSUM),
    SX_FIELD("crc64","uint64",28,8,SX_CHECKSUM),
};
static const sx_layout sxvi_aaru_data_header = {0x60530035U,"aaru_data_header",sxvi_aaru_data_header_fields,SX_COUNT(sxvi_aaru_data_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_aff_segment_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("name_length","uint32",4,4,SX_SIZE),
    SX_FIELD("data_length","uint32",8,4,SX_SIZE),
    SX_FIELD("argument","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxvi_aff_segment_header = {0x60530036U,"aff_segment_header",sxvi_aff_segment_header_fields,SX_COUNT(sxvi_aff_segment_header_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_aff_segment_footer_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("segment_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxvi_aff_segment_footer = {0x60530037U,"aff_segment_footer",sxvi_aff_segment_footer_fields,SX_COUNT(sxvi_aff_segment_footer_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_aff_quadword_fields[] = {
    SX_FIELD("low","uint32",0,4,SX_NONE),
    SX_FIELD("high","uint32",4,4,SX_NONE),
};
static const sx_layout sxvi_aff_quadword = {0x60530038U,"aff_quadword",sxvi_aff_quadword_fields,SX_COUNT(sxvi_aff_quadword_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_bsd_disklabel_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("drive_type","uint16",4,2,SX_ID),
    SX_FIELD("subtype","uint16",6,2,SX_ID),
    SX_FIELD("type_name","char[16]",8,16,SX_STRING),
    SX_FIELD("pack_name","char[16]",24,16,SX_STRING),
    SX_FIELD("sector_size","uint32",40,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("tracks_per_cylinder","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_unit","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("spare_sectors_per_track","uint16",64,2,SX_COUNT_PROP),
    SX_FIELD("spare_sectors_per_cylinder","uint16",66,2,SX_COUNT_PROP),
    SX_FIELD("alternate_cylinders","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("rpm","uint16",72,2,SX_NONE),
    SX_FIELD("interleave","uint16",74,2,SX_NONE),
    SX_FIELD("track_skew","uint16",76,2,SX_NONE),
    SX_FIELD("cylinder_skew","uint16",78,2,SX_NONE),
    SX_FIELD("head_switch_microseconds","uint32",80,4,SX_NONE),
    SX_FIELD("track_seek_microseconds","uint32",84,4,SX_NONE),
    SX_FIELD("flags","uint32",88,4,SX_FLAGS),
    SX_FIELD("drive_data","uint32[5]",92,20,SX_NONE),
    SX_FIELD("spare","uint32[5]",112,20,SX_RESERVED),
    SX_FIELD("magic2","uint32",132,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint16",136,2,SX_CHECKSUM),
    SX_FIELD("partition_count","uint16",138,2,SX_COUNT_PROP),
    SX_FIELD("boot_area_size","uint32",140,4,SX_SIZE),
    SX_FIELD("maximum_superblock_size","uint32",144,4,SX_SIZE),
};
static const sx_layout sxvi_bsd_disklabel_le = {0x60530039U,"bsd_disklabel_le",sxvi_bsd_disklabel_le_fields,SX_COUNT(sxvi_bsd_disklabel_le_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_bsd_disklabel_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("drive_type","uint16",4,2,SX_ID),
    SX_FIELD("subtype","uint16",6,2,SX_ID),
    SX_FIELD("type_name","char[16]",8,16,SX_STRING),
    SX_FIELD("pack_name","char[16]",24,16,SX_STRING),
    SX_FIELD("sector_size","uint32",40,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("tracks_per_cylinder","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_unit","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("spare_sectors_per_track","uint16",64,2,SX_COUNT_PROP),
    SX_FIELD("spare_sectors_per_cylinder","uint16",66,2,SX_COUNT_PROP),
    SX_FIELD("alternate_cylinders","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("rpm","uint16",72,2,SX_NONE),
    SX_FIELD("interleave","uint16",74,2,SX_NONE),
    SX_FIELD("track_skew","uint16",76,2,SX_NONE),
    SX_FIELD("cylinder_skew","uint16",78,2,SX_NONE),
    SX_FIELD("head_switch_microseconds","uint32",80,4,SX_NONE),
    SX_FIELD("track_seek_microseconds","uint32",84,4,SX_NONE),
    SX_FIELD("flags","uint32",88,4,SX_FLAGS),
    SX_FIELD("drive_data","uint32[5]",92,20,SX_NONE),
    SX_FIELD("spare","uint32[5]",112,20,SX_RESERVED),
    SX_FIELD("magic2","uint32",132,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint16",136,2,SX_CHECKSUM),
    SX_FIELD("partition_count","uint16",138,2,SX_COUNT_PROP),
    SX_FIELD("boot_area_size","uint32",140,4,SX_SIZE),
    SX_FIELD("maximum_superblock_size","uint32",144,4,SX_SIZE),
};
static const sx_layout sxvi_bsd_disklabel_be = {0x6053003aU,"bsd_disklabel_be",sxvi_bsd_disklabel_be_fields,SX_COUNT(sxvi_bsd_disklabel_be_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_bsd_partition_le_fields[] = {
    SX_FIELD("sector_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("start_sector","uint32",4,4,SX_NONE),
    SX_FIELD("fragment_size","uint32",8,4,SX_SIZE),
    SX_FIELD("filesystem_type","uint8",12,1,SX_ID),
    SX_FIELD("fragments_per_block","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxvi_bsd_partition_le = {0x6053003bU,"bsd_partition_le",sxvi_bsd_partition_le_fields,SX_COUNT(sxvi_bsd_partition_le_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_bsd_partition_be_fields[] = {
    SX_FIELD("sector_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("start_sector","uint32",4,4,SX_NONE),
    SX_FIELD("fragment_size","uint32",8,4,SX_SIZE),
    SX_FIELD("filesystem_type","uint8",12,1,SX_ID),
    SX_FIELD("fragments_per_block","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxvi_bsd_partition_be = {0x6053003cU,"bsd_partition_be",sxvi_bsd_partition_be_fields,SX_COUNT(sxvi_bsd_partition_be_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_md1_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint32",4,4,SX_ID),
    SX_FIELD("feature_map","uint32",8,4,SX_FLAGS),
    SX_FIELD("reserved0","uint32",12,4,SX_RESERVED),
    SX_FIELD("set_uuid","byte[16]",16,16,SX_ID),
    SX_FIELD("set_name","char[32]",32,32,SX_STRING),
    SX_FIELD("creation_time_encoded","uint64",64,8,SX_NONE),
    SX_FIELD("level","int32",72,4,SX_ID),
    SX_FIELD("layout","uint32",76,4,SX_ID),
    SX_FIELD("component_sectors","uint64",80,8,SX_COUNT_PROP),
    SX_FIELD("chunk_sectors","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("raid_disks","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_offset","int32",96,4,SX_NONE),
    SX_FIELD("new_level","int32",100,4,SX_ID),
    SX_FIELD("reshape_position","uint64",104,8,SX_NONE),
    SX_FIELD("delta_disks","int32",112,4,SX_NONE),
    SX_FIELD("new_layout","uint32",116,4,SX_ID),
    SX_FIELD("new_chunk_sectors","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("new_data_offset","int32",124,4,SX_NONE),
    SX_FIELD("data_offset","uint64",128,8,SX_NONE),
    SX_FIELD("data_sectors","uint64",136,8,SX_COUNT_PROP),
    SX_FIELD("super_offset","uint64",144,8,SX_NONE),
    SX_FIELD("recovery_or_journal_offset","uint64",152,8,SX_NONE),
    SX_FIELD("device_number","uint32",160,4,SX_ID),
    SX_FIELD("corrected_reads","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("device_uuid","byte[16]",168,16,SX_ID),
    SX_FIELD("device_flags","uint8",184,1,SX_FLAGS),
    SX_FIELD("bad_block_shift","uint8",185,1,SX_NONE),
    SX_FIELD("bad_block_log_sectors","uint16",186,2,SX_COUNT_PROP),
    SX_FIELD("bad_block_log_offset","int32",188,4,SX_NONE),
    SX_FIELD("update_time_encoded","uint64",192,8,SX_NONE),
    SX_FIELD("events","uint64",200,8,SX_COUNT_PROP),
    SX_FIELD("resync_offset","uint64",208,8,SX_NONE),
    SX_FIELD("checksum","uint32",216,4,SX_CHECKSUM),
    SX_FIELD("max_devices","uint32",220,4,SX_COUNT_PROP),
    SX_FIELD("padding","byte[32]",224,32,SX_RESERVED),
};
static const sx_layout sxvi_md1_superblock = {0x6053003dU,"md1_superblock",sxvi_md1_superblock_fields,SX_COUNT(sxvi_md1_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_md1_superblock_ppl_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint32",4,4,SX_ID),
    SX_FIELD("feature_map","uint32",8,4,SX_FLAGS),
    SX_FIELD("reserved0","uint32",12,4,SX_RESERVED),
    SX_FIELD("set_uuid","byte[16]",16,16,SX_ID),
    SX_FIELD("set_name","char[32]",32,32,SX_STRING),
    SX_FIELD("creation_time_encoded","uint64",64,8,SX_NONE),
    SX_FIELD("level","int32",72,4,SX_ID),
    SX_FIELD("layout","uint32",76,4,SX_ID),
    SX_FIELD("component_sectors","uint64",80,8,SX_COUNT_PROP),
    SX_FIELD("chunk_sectors","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("raid_disks","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("ppl_offset","int16",96,2,SX_NONE),
    SX_FIELD("ppl_sectors","uint16",98,2,SX_COUNT_PROP),
    SX_FIELD("new_level","int32",100,4,SX_ID),
    SX_FIELD("reshape_position","uint64",104,8,SX_NONE),
    SX_FIELD("delta_disks","int32",112,4,SX_NONE),
    SX_FIELD("new_layout","uint32",116,4,SX_ID),
    SX_FIELD("new_chunk_sectors","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("new_data_offset","int32",124,4,SX_NONE),
    SX_FIELD("data_offset","uint64",128,8,SX_NONE),
    SX_FIELD("data_sectors","uint64",136,8,SX_COUNT_PROP),
    SX_FIELD("super_offset","uint64",144,8,SX_NONE),
    SX_FIELD("recovery_or_journal_offset","uint64",152,8,SX_NONE),
    SX_FIELD("device_number","uint32",160,4,SX_ID),
    SX_FIELD("corrected_reads","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("device_uuid","byte[16]",168,16,SX_ID),
    SX_FIELD("device_flags","uint8",184,1,SX_FLAGS),
    SX_FIELD("bad_block_shift","uint8",185,1,SX_NONE),
    SX_FIELD("bad_block_log_sectors","uint16",186,2,SX_COUNT_PROP),
    SX_FIELD("bad_block_log_offset","int32",188,4,SX_NONE),
    SX_FIELD("update_time_encoded","uint64",192,8,SX_NONE),
    SX_FIELD("events","uint64",200,8,SX_COUNT_PROP),
    SX_FIELD("resync_offset","uint64",208,8,SX_NONE),
    SX_FIELD("checksum","uint32",216,4,SX_CHECKSUM),
    SX_FIELD("max_devices","uint32",220,4,SX_COUNT_PROP),
    SX_FIELD("padding","byte[32]",224,32,SX_RESERVED),
};
static const sx_layout sxvi_md1_superblock_ppl = {0x6053003eU,"md1_superblock_ppl",sxvi_md1_superblock_ppl_fields,SX_COUNT(sxvi_md1_superblock_ppl_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_md1_device_role_fields[] = {
    SX_FIELD("role","uint16",0,2,SX_ID),
};
static const sx_layout sxvi_md1_device_role = {0x6053003fU,"md1_device_role",sxvi_md1_device_role_fields,SX_COUNT(sxvi_md1_device_role_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_md090_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint32",4,4,SX_ID),
    SX_FIELD("minor_version","uint32",8,4,SX_ID),
    SX_FIELD("patch_version","uint32",12,4,SX_ID),
    SX_FIELD("valid_words","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("uuid0","uint32",20,4,SX_ID),
    SX_FIELD("creation_time","uint32",24,4,SX_TIME),
    SX_FIELD("level","int32",28,4,SX_ID),
    SX_FIELD("component_kib","uint32",32,4,SX_NONE),
    SX_FIELD("total_disks","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("raid_disks","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("preferred_minor","uint32",44,4,SX_ID),
    SX_FIELD("not_persistent","uint32",48,4,SX_FLAGS),
    SX_FIELD("uuid1","uint32",52,4,SX_ID),
    SX_FIELD("uuid2","uint32",56,4,SX_ID),
    SX_FIELD("uuid3","uint32",60,4,SX_ID),
    SX_FIELD("constant_reserved","byte[64]",64,64,SX_RESERVED),
    SX_FIELD("update_time","uint32",128,4,SX_TIME),
    SX_FIELD("state","uint32",132,4,SX_FLAGS),
    SX_FIELD("active_disks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("working_disks","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("failed_disks","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("spare_disks","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("checksum","uint32",152,4,SX_CHECKSUM),
    SX_FIELD("events","uint64",156,8,SX_COUNT_PROP),
    SX_FIELD("checkpoint_events","uint64",164,8,SX_COUNT_PROP),
    SX_FIELD("recovery_checkpoint","uint32",172,4,SX_NONE),
    SX_FIELD("state_reserved","byte[80]",176,80,SX_RESERVED),
    SX_FIELD("layout","uint32",256,4,SX_ID),
    SX_FIELD("chunk_size","uint32",260,4,SX_SIZE),
    SX_FIELD("root_pv","uint32",264,4,SX_ID),
    SX_FIELD("root_block","uint32",268,4,SX_NONE),
    SX_FIELD("personality_reserved","byte[240]",272,240,SX_RESERVED),
};
static const sx_layout sxvi_md090_header_le = {0x60530040U,"md090_header_le",sxvi_md090_header_le_fields,SX_COUNT(sxvi_md090_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_md090_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint32",4,4,SX_ID),
    SX_FIELD("minor_version","uint32",8,4,SX_ID),
    SX_FIELD("patch_version","uint32",12,4,SX_ID),
    SX_FIELD("valid_words","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("uuid0","uint32",20,4,SX_ID),
    SX_FIELD("creation_time","uint32",24,4,SX_TIME),
    SX_FIELD("level","int32",28,4,SX_ID),
    SX_FIELD("component_kib","uint32",32,4,SX_NONE),
    SX_FIELD("total_disks","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("raid_disks","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("preferred_minor","uint32",44,4,SX_ID),
    SX_FIELD("not_persistent","uint32",48,4,SX_FLAGS),
    SX_FIELD("uuid1","uint32",52,4,SX_ID),
    SX_FIELD("uuid2","uint32",56,4,SX_ID),
    SX_FIELD("uuid3","uint32",60,4,SX_ID),
    SX_FIELD("constant_reserved","byte[64]",64,64,SX_RESERVED),
    SX_FIELD("update_time","uint32",128,4,SX_TIME),
    SX_FIELD("state","uint32",132,4,SX_FLAGS),
    SX_FIELD("active_disks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("working_disks","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("failed_disks","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("spare_disks","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("checksum","uint32",152,4,SX_CHECKSUM),
    SX_FIELD("events","uint64",156,8,SX_COUNT_PROP),
    SX_FIELD("checkpoint_events","uint64",164,8,SX_COUNT_PROP),
    SX_FIELD("recovery_checkpoint","uint32",172,4,SX_NONE),
    SX_FIELD("state_reserved","byte[80]",176,80,SX_RESERVED),
    SX_FIELD("layout","uint32",256,4,SX_ID),
    SX_FIELD("chunk_size","uint32",260,4,SX_SIZE),
    SX_FIELD("root_pv","uint32",264,4,SX_ID),
    SX_FIELD("root_block","uint32",268,4,SX_NONE),
    SX_FIELD("personality_reserved","byte[240]",272,240,SX_RESERVED),
};
static const sx_layout sxvi_md090_header_be = {0x60530041U,"md090_header_be",sxvi_md090_header_be_fields,SX_COUNT(sxvi_md090_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_md090_disk_le_fields[] = {
    SX_FIELD("number","uint32",0,4,SX_ID),
    SX_FIELD("major","uint32",4,4,SX_ID),
    SX_FIELD("minor","uint32",8,4,SX_ID),
    SX_FIELD("raid_role","uint32",12,4,SX_ID),
    SX_FIELD("state","uint32",16,4,SX_FLAGS),
    SX_FIELD("reserved","byte[108]",20,108,SX_RESERVED),
};
static const sx_layout sxvi_md090_disk_le = {0x60530042U,"md090_disk_le",sxvi_md090_disk_le_fields,SX_COUNT(sxvi_md090_disk_le_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_md090_disk_be_fields[] = {
    SX_FIELD("number","uint32",0,4,SX_ID),
    SX_FIELD("major","uint32",4,4,SX_ID),
    SX_FIELD("minor","uint32",8,4,SX_ID),
    SX_FIELD("raid_role","uint32",12,4,SX_ID),
    SX_FIELD("state","uint32",16,4,SX_FLAGS),
    SX_FIELD("reserved","byte[108]",20,108,SX_RESERVED),
};
static const sx_layout sxvi_md090_disk_be = {0x60530043U,"md090_disk_be",sxvi_md090_disk_be_fields,SX_COUNT(sxvi_md090_disk_be_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_sun_sparc_label_fields[] = {
    SX_FIELD("ascii_label","char[128]",0,128,SX_STRING),
    SX_FIELD("version","uint32",128,4,SX_ID),
    SX_FIELD("volume_name","char[8]",132,8,SX_STRING),
    SX_FIELD("partition_count","uint16",140,2,SX_COUNT_PROP),
    SX_FIELD("partition_0_tag","uint16",142,2,SX_ID),
    SX_FIELD("partition_0_flags","uint16",144,2,SX_FLAGS),
    SX_FIELD("partition_1_tag","uint16",146,2,SX_ID),
    SX_FIELD("partition_1_flags","uint16",148,2,SX_FLAGS),
    SX_FIELD("partition_2_tag","uint16",150,2,SX_ID),
    SX_FIELD("partition_2_flags","uint16",152,2,SX_FLAGS),
    SX_FIELD("partition_3_tag","uint16",154,2,SX_ID),
    SX_FIELD("partition_3_flags","uint16",156,2,SX_FLAGS),
    SX_FIELD("partition_4_tag","uint16",158,2,SX_ID),
    SX_FIELD("partition_4_flags","uint16",160,2,SX_FLAGS),
    SX_FIELD("partition_5_tag","uint16",162,2,SX_ID),
    SX_FIELD("partition_5_flags","uint16",164,2,SX_FLAGS),
    SX_FIELD("partition_6_tag","uint16",166,2,SX_ID),
    SX_FIELD("partition_6_flags","uint16",168,2,SX_FLAGS),
    SX_FIELD("partition_7_tag","uint16",170,2,SX_ID),
    SX_FIELD("partition_7_flags","uint16",172,2,SX_FLAGS),
    SX_FIELD("alignment_padding","byte[2]",174,2,SX_RESERVED),
    SX_FIELD("boot_info","uint32[3]",176,12,SX_NONE),
    SX_FIELD("sanity","uint32",188,4,SX_SIGNATURE),
    SX_FIELD("reserved0","uint32[10]",192,40,SX_RESERVED),
    SX_FIELD("partition_0_timestamp","int32",232,4,SX_TIME),
    SX_FIELD("partition_1_timestamp","int32",236,4,SX_TIME),
    SX_FIELD("partition_2_timestamp","int32",240,4,SX_TIME),
    SX_FIELD("partition_3_timestamp","int32",244,4,SX_TIME),
    SX_FIELD("partition_4_timestamp","int32",248,4,SX_TIME),
    SX_FIELD("partition_5_timestamp","int32",252,4,SX_TIME),
    SX_FIELD("partition_6_timestamp","int32",256,4,SX_TIME),
    SX_FIELD("partition_7_timestamp","int32",260,4,SX_TIME),
    SX_FIELD("write_reinstruct_sectors","uint16",264,2,SX_COUNT_PROP),
    SX_FIELD("read_reinstruct_sectors","uint16",266,2,SX_COUNT_PROP),
    SX_FIELD("padding","byte[152]",268,152,SX_RESERVED),
    SX_FIELD("rpm","uint16",420,2,SX_NONE),
    SX_FIELD("physical_cylinders","uint16",422,2,SX_COUNT_PROP),
    SX_FIELD("alternates_per_cylinder","uint16",424,2,SX_COUNT_PROP),
    SX_FIELD("obsolete0","uint16",426,2,SX_NONE),
    SX_FIELD("obsolete1","uint16",428,2,SX_NONE),
    SX_FIELD("interleave","uint16",430,2,SX_NONE),
    SX_FIELD("data_cylinders","uint16",432,2,SX_COUNT_PROP),
    SX_FIELD("alternate_cylinders","uint16",434,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",436,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",438,2,SX_COUNT_PROP),
    SX_FIELD("obsolete2","uint16",440,2,SX_NONE),
    SX_FIELD("obsolete3","uint16",442,2,SX_NONE),
    SX_FIELD("partition_0_start_cylinder","uint32",444,4,SX_NONE),
    SX_FIELD("partition_0_sector_count","uint32",448,4,SX_COUNT_PROP),
    SX_FIELD("partition_1_start_cylinder","uint32",452,4,SX_NONE),
    SX_FIELD("partition_1_sector_count","uint32",456,4,SX_COUNT_PROP),
    SX_FIELD("partition_2_start_cylinder","uint32",460,4,SX_NONE),
    SX_FIELD("partition_2_sector_count","uint32",464,4,SX_COUNT_PROP),
    SX_FIELD("partition_3_start_cylinder","uint32",468,4,SX_NONE),
    SX_FIELD("partition_3_sector_count","uint32",472,4,SX_COUNT_PROP),
    SX_FIELD("partition_4_start_cylinder","uint32",476,4,SX_NONE),
    SX_FIELD("partition_4_sector_count","uint32",480,4,SX_COUNT_PROP),
    SX_FIELD("partition_5_start_cylinder","uint32",484,4,SX_NONE),
    SX_FIELD("partition_5_sector_count","uint32",488,4,SX_COUNT_PROP),
    SX_FIELD("partition_6_start_cylinder","uint32",492,4,SX_NONE),
    SX_FIELD("partition_6_sector_count","uint32",496,4,SX_COUNT_PROP),
    SX_FIELD("partition_7_start_cylinder","uint32",500,4,SX_NONE),
    SX_FIELD("partition_7_sector_count","uint32",504,4,SX_COUNT_PROP),
    SX_FIELD("magic","uint16",508,2,SX_SIGNATURE),
    SX_FIELD("checksum","uint16",510,2,SX_CHECKSUM),
};
static const sx_layout sxvi_sun_sparc_label = {0x60530044U,"sun_sparc_label",sxvi_sun_sparc_label_fields,SX_COUNT(sxvi_sun_sparc_label_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_sun_x86_label_fields[] = {
    SX_FIELD("boot_info","uint32[3]",0,12,SX_NONE),
    SX_FIELD("sanity","uint32",12,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",16,4,SX_ID),
    SX_FIELD("volume_name","char[8]",20,8,SX_STRING),
    SX_FIELD("sector_size","uint16",28,2,SX_SIZE),
    SX_FIELD("partition_count","uint16",30,2,SX_COUNT_PROP),
    SX_FIELD("reserved0","uint32[10]",32,40,SX_RESERVED),
    SX_FIELD("partition_0_tag","uint16",72,2,SX_ID),
    SX_FIELD("partition_0_flags","uint16",74,2,SX_FLAGS),
    SX_FIELD("partition_0_start_sector","uint32",76,4,SX_NONE),
    SX_FIELD("partition_0_sector_count","uint32",80,4,SX_COUNT_PROP),
    SX_FIELD("partition_1_tag","uint16",84,2,SX_ID),
    SX_FIELD("partition_1_flags","uint16",86,2,SX_FLAGS),
    SX_FIELD("partition_1_start_sector","uint32",88,4,SX_NONE),
    SX_FIELD("partition_1_sector_count","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("partition_2_tag","uint16",96,2,SX_ID),
    SX_FIELD("partition_2_flags","uint16",98,2,SX_FLAGS),
    SX_FIELD("partition_2_start_sector","uint32",100,4,SX_NONE),
    SX_FIELD("partition_2_sector_count","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("partition_3_tag","uint16",108,2,SX_ID),
    SX_FIELD("partition_3_flags","uint16",110,2,SX_FLAGS),
    SX_FIELD("partition_3_start_sector","uint32",112,4,SX_NONE),
    SX_FIELD("partition_3_sector_count","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("partition_4_tag","uint16",120,2,SX_ID),
    SX_FIELD("partition_4_flags","uint16",122,2,SX_FLAGS),
    SX_FIELD("partition_4_start_sector","uint32",124,4,SX_NONE),
    SX_FIELD("partition_4_sector_count","uint32",128,4,SX_COUNT_PROP),
    SX_FIELD("partition_5_tag","uint16",132,2,SX_ID),
    SX_FIELD("partition_5_flags","uint16",134,2,SX_FLAGS),
    SX_FIELD("partition_5_start_sector","uint32",136,4,SX_NONE),
    SX_FIELD("partition_5_sector_count","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("partition_6_tag","uint16",144,2,SX_ID),
    SX_FIELD("partition_6_flags","uint16",146,2,SX_FLAGS),
    SX_FIELD("partition_6_start_sector","uint32",148,4,SX_NONE),
    SX_FIELD("partition_6_sector_count","uint32",152,4,SX_COUNT_PROP),
    SX_FIELD("partition_7_tag","uint16",156,2,SX_ID),
    SX_FIELD("partition_7_flags","uint16",158,2,SX_FLAGS),
    SX_FIELD("partition_7_start_sector","uint32",160,4,SX_NONE),
    SX_FIELD("partition_7_sector_count","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("partition_8_tag","uint16",168,2,SX_ID),
    SX_FIELD("partition_8_flags","uint16",170,2,SX_FLAGS),
    SX_FIELD("partition_8_start_sector","uint32",172,4,SX_NONE),
    SX_FIELD("partition_8_sector_count","uint32",176,4,SX_COUNT_PROP),
    SX_FIELD("partition_9_tag","uint16",180,2,SX_ID),
    SX_FIELD("partition_9_flags","uint16",182,2,SX_FLAGS),
    SX_FIELD("partition_9_start_sector","uint32",184,4,SX_NONE),
    SX_FIELD("partition_9_sector_count","uint32",188,4,SX_COUNT_PROP),
    SX_FIELD("partition_10_tag","uint16",192,2,SX_ID),
    SX_FIELD("partition_10_flags","uint16",194,2,SX_FLAGS),
    SX_FIELD("partition_10_start_sector","uint32",196,4,SX_NONE),
    SX_FIELD("partition_10_sector_count","uint32",200,4,SX_COUNT_PROP),
    SX_FIELD("partition_11_tag","uint16",204,2,SX_ID),
    SX_FIELD("partition_11_flags","uint16",206,2,SX_FLAGS),
    SX_FIELD("partition_11_start_sector","uint32",208,4,SX_NONE),
    SX_FIELD("partition_11_sector_count","uint32",212,4,SX_COUNT_PROP),
    SX_FIELD("partition_12_tag","uint16",216,2,SX_ID),
    SX_FIELD("partition_12_flags","uint16",218,2,SX_FLAGS),
    SX_FIELD("partition_12_start_sector","uint32",220,4,SX_NONE),
    SX_FIELD("partition_12_sector_count","uint32",224,4,SX_COUNT_PROP),
    SX_FIELD("partition_13_tag","uint16",228,2,SX_ID),
    SX_FIELD("partition_13_flags","uint16",230,2,SX_FLAGS),
    SX_FIELD("partition_13_start_sector","uint32",232,4,SX_NONE),
    SX_FIELD("partition_13_sector_count","uint32",236,4,SX_COUNT_PROP),
    SX_FIELD("partition_14_tag","uint16",240,2,SX_ID),
    SX_FIELD("partition_14_flags","uint16",242,2,SX_FLAGS),
    SX_FIELD("partition_14_start_sector","uint32",244,4,SX_NONE),
    SX_FIELD("partition_14_sector_count","uint32",248,4,SX_COUNT_PROP),
    SX_FIELD("partition_15_tag","uint16",252,2,SX_ID),
    SX_FIELD("partition_15_flags","uint16",254,2,SX_FLAGS),
    SX_FIELD("partition_15_start_sector","uint32",256,4,SX_NONE),
    SX_FIELD("partition_15_sector_count","uint32",260,4,SX_COUNT_PROP),
    SX_FIELD("partition_0_timestamp","int32",264,4,SX_TIME),
    SX_FIELD("partition_1_timestamp","int32",268,4,SX_TIME),
    SX_FIELD("partition_2_timestamp","int32",272,4,SX_TIME),
    SX_FIELD("partition_3_timestamp","int32",276,4,SX_TIME),
    SX_FIELD("partition_4_timestamp","int32",280,4,SX_TIME),
    SX_FIELD("partition_5_timestamp","int32",284,4,SX_TIME),
    SX_FIELD("partition_6_timestamp","int32",288,4,SX_TIME),
    SX_FIELD("partition_7_timestamp","int32",292,4,SX_TIME),
    SX_FIELD("partition_8_timestamp","int32",296,4,SX_TIME),
    SX_FIELD("partition_9_timestamp","int32",300,4,SX_TIME),
    SX_FIELD("partition_10_timestamp","int32",304,4,SX_TIME),
    SX_FIELD("partition_11_timestamp","int32",308,4,SX_TIME),
    SX_FIELD("partition_12_timestamp","int32",312,4,SX_TIME),
    SX_FIELD("partition_13_timestamp","int32",316,4,SX_TIME),
    SX_FIELD("partition_14_timestamp","int32",320,4,SX_TIME),
    SX_FIELD("partition_15_timestamp","int32",324,4,SX_TIME),
    SX_FIELD("ascii_label","char[128]",328,128,SX_STRING),
    SX_FIELD("physical_cylinders","uint32",456,4,SX_COUNT_PROP),
    SX_FIELD("data_cylinders","uint32",460,4,SX_COUNT_PROP),
    SX_FIELD("alternate_cylinders","uint16",464,2,SX_COUNT_PROP),
    SX_FIELD("cylinder_offset","uint16",466,2,SX_NONE),
    SX_FIELD("heads","uint32",468,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",472,4,SX_COUNT_PROP),
    SX_FIELD("interleave","uint16",476,2,SX_NONE),
    SX_FIELD("skew","uint16",478,2,SX_NONE),
    SX_FIELD("alternates_per_cylinder","uint16",480,2,SX_COUNT_PROP),
    SX_FIELD("rpm","uint16",482,2,SX_NONE),
    SX_FIELD("write_reinstruct_sectors","uint16",484,2,SX_COUNT_PROP),
    SX_FIELD("read_reinstruct_sectors","uint16",486,2,SX_COUNT_PROP),
    SX_FIELD("expansion","uint16[4]",488,8,SX_RESERVED),
    SX_FIELD("padding","byte[12]",496,12,SX_RESERVED),
    SX_FIELD("magic","uint16",508,2,SX_SIGNATURE),
    SX_FIELD("checksum","uint16",510,2,SX_CHECKSUM),
};
static const sx_layout sxvi_sun_x86_label = {0x60530045U,"sun_x86_label",sxvi_sun_x86_label_fields,SX_COUNT(sxvi_sun_x86_label_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_nextstep_container_header_fields[] = {
    SX_FIELD("format_word","uint32",0,4,SX_ID),
    SX_FIELD("sector_size","uint16",4,2,SX_SIZE),
    SX_FIELD("geometry_factor_0","uint32",6,4,SX_COUNT_PROP),
    SX_FIELD("geometry_factor_1","uint32",10,4,SX_COUNT_PROP),
    SX_FIELD("unknown0","byte[8]",14,8,SX_NONE),
    SX_FIELD("image_size","uint32",22,4,SX_SIZE),
    SX_FIELD("constant_one","uint32",26,4,SX_ID),
    SX_FIELD("sector_size_copy32","uint32",30,4,SX_SIZE),
    SX_FIELD("sector_size_copy16","uint16",34,2,SX_SIZE),
    SX_FIELD("geometry_factor_2","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("unknown1","byte[2]",40,2,SX_NONE),
    SX_FIELD("total_sectors","uint32",42,4,SX_COUNT_PROP),
};
static const sx_layout sxvi_nextstep_container_header = {0x60530046U,"nextstep_container_header",sxvi_nextstep_container_header_fields,SX_COUNT(sxvi_nextstep_container_header_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_mds_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("major_version","uint8",16,1,SX_ID),
    SX_FIELD("minor_version","uint8",17,1,SX_ID),
    SX_FIELD("media_type","uint16",18,2,SX_ID),
    SX_FIELD("sessions","uint16",20,2,SX_COUNT_PROP),
    SX_FIELD("session_count_copy","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("unknown0","uint16",24,2,SX_NONE),
    SX_FIELD("bca_size","uint16",26,2,SX_SIZE),
    SX_FIELD("unknown1","byte[8]",28,8,SX_NONE),
    SX_FIELD("bca_offset","uint32",36,4,SX_OFFSET),
    SX_FIELD("unknown2","byte[24]",40,24,SX_NONE),
    SX_FIELD("structures_offset","uint32",64,4,SX_OFFSET),
    SX_FIELD("unknown3","byte[12]",68,12,SX_NONE),
    SX_FIELD("sessions_offset","uint32",80,4,SX_OFFSET),
    SX_FIELD("disc_metadata_offset","uint32",84,4,SX_OFFSET),
};
static const sx_layout sxvi_mds_header = {0x60530047U,"mds_header",sxvi_mds_header_fields,SX_COUNT(sxvi_mds_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_mds_session_fields[] = {
    SX_FIELD("start_lba","int32",0,4,SX_NONE),
    SX_FIELD("end_lba","int32",4,4,SX_NONE),
    SX_FIELD("sequence","uint16",8,2,SX_ID),
    SX_FIELD("block_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("non_track_blocks","uint8",11,1,SX_COUNT_PROP),
    SX_FIELD("first_track","uint16",12,2,SX_ID),
    SX_FIELD("last_track","uint16",14,2,SX_ID),
    SX_FIELD("unknown","uint32",16,4,SX_NONE),
    SX_FIELD("tracks_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxvi_mds_session = {0x60530048U,"mds_session",sxvi_mds_session_fields,SX_COUNT(sxvi_mds_session_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_mds_track_fields[] = {
    SX_FIELD("mode","uint8",0,1,SX_ID),
    SX_FIELD("subchannel_mode","uint8",1,1,SX_ID),
    SX_FIELD("adr_control","uint8",2,1,SX_FLAGS),
    SX_FIELD("track_number","uint8",3,1,SX_ID),
    SX_FIELD("point","uint8",4,1,SX_ID),
    SX_FIELD("minute","uint8",5,1,SX_NONE),
    SX_FIELD("second","uint8",6,1,SX_NONE),
    SX_FIELD("frame","uint8",7,1,SX_NONE),
    SX_FIELD("zero","uint8",8,1,SX_RESERVED),
    SX_FIELD("pminute","uint8",9,1,SX_NONE),
    SX_FIELD("psecond","uint8",10,1,SX_NONE),
    SX_FIELD("pframe","uint8",11,1,SX_NONE),
    SX_FIELD("extra_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("sector_size","uint16",16,2,SX_SIZE),
    SX_FIELD("unknown0","byte[18]",18,18,SX_NONE),
    SX_FIELD("start_lba","uint32",36,4,SX_NONE),
    SX_FIELD("mdf_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("file_count","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("footer_offset","uint32",52,4,SX_OFFSET),
    SX_FIELD("unknown1","byte[24]",56,24,SX_NONE),
};
static const sx_layout sxvi_mds_track = {0x60530049U,"mds_track",sxvi_mds_track_fields,SX_COUNT(sxvi_mds_track_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_mds_track_extra_fields[] = {
    SX_FIELD("pregap_sectors","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("sector_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxvi_mds_track_extra = {0x6053004aU,"mds_track_extra",sxvi_mds_track_extra_fields,SX_COUNT(sxvi_mds_track_extra_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_mds_footer_fields[] = {
    SX_FIELD("filename_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("wide_character","uint32",4,4,SX_FLAGS),
    SX_FIELD("unknown0","uint32",8,4,SX_NONE),
    SX_FIELD("unknown1","uint32",12,4,SX_NONE),
};
static const sx_layout sxvi_mds_footer = {0x6053004bU,"mds_footer",sxvi_mds_footer_fields,SX_COUNT(sxvi_mds_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_ldm_private_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("unknown0","byte[4]",8,4,SX_NONE),
    SX_FIELD("major_version","uint16",12,2,SX_ID),
    SX_FIELD("minor_version","uint16",14,2,SX_ID),
    SX_FIELD("unknown1","byte[32]",16,32,SX_NONE),
    SX_FIELD("disk_uuid","char[36]",48,36,SX_ID),
    SX_FIELD("unknown2","byte[199]",84,199,SX_NONE),
    SX_FIELD("logical_disk_start","uint64",283,8,SX_NONE),
    SX_FIELD("logical_disk_sectors","uint64",291,8,SX_COUNT_PROP),
    SX_FIELD("configuration_start","uint64",299,8,SX_NONE),
    SX_FIELD("configuration_sectors","uint64",307,8,SX_COUNT_PROP),
    SX_FIELD("unknown3","byte[197]",315,197,SX_NONE),
};
static const sx_layout sxvi_ldm_private_header = {0x6053004cU,"ldm_private_header",sxvi_ldm_private_header_fields,SX_COUNT(sxvi_ldm_private_header_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_ldm_tocblock_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("unknown0","byte[28]",8,28,SX_NONE),
    SX_FIELD("configuration_name","char[10]",36,10,SX_STRING),
    SX_FIELD("configuration_start","uint64",46,8,SX_NONE),
    SX_FIELD("configuration_sectors","uint64",54,8,SX_COUNT_PROP),
    SX_FIELD("unknown1","byte[8]",62,8,SX_NONE),
    SX_FIELD("log_name","char[10]",70,10,SX_STRING),
    SX_FIELD("log_start","uint64",80,8,SX_NONE),
    SX_FIELD("log_sectors","uint64",88,8,SX_COUNT_PROP),
    SX_FIELD("unknown2","byte[416]",96,416,SX_NONE),
};
static const sx_layout sxvi_ldm_tocblock = {0x6053004dU,"ldm_tocblock",sxvi_ldm_tocblock_fields,SX_COUNT(sxvi_ldm_tocblock_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_ldm_vmdb_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("last_vblk_sequence","uint32",4,4,SX_NONE),
    SX_FIELD("vblk_size","uint32",8,4,SX_SIZE),
    SX_FIELD("vblk_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("update_state","uint16",16,2,SX_ID),
    SX_FIELD("major_version","uint16",18,2,SX_ID),
    SX_FIELD("minor_version","uint16",20,2,SX_ID),
};
static const sx_layout sxvi_ldm_vmdb_header = {0x6053004eU,"ldm_vmdb_header",sxvi_ldm_vmdb_header_fields,SX_COUNT(sxvi_ldm_vmdb_header_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_ldm_vblk_fragment_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("sequence","uint32",4,4,SX_ID),
    SX_FIELD("group","uint32",8,4,SX_ID),
    SX_FIELD("fragment_number","uint16",12,2,SX_NONE),
    SX_FIELD("fragment_count","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxvi_ldm_vblk_fragment = {0x6053004fU,"ldm_vblk_fragment",sxvi_ldm_vblk_fragment_fields,SX_COUNT(sxvi_ldm_vblk_fragment_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_ldm_vblk_record_header_fields[] = {
    SX_FIELD("unknown","byte[2]",0,2,SX_NONE),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("type","uint8",3,1,SX_ID),
    SX_FIELD("declared_length","uint32",4,4,SX_SIZE),
};
static const sx_layout sxvi_ldm_vblk_record_header = {0x60530050U,"ldm_vblk_record_header",sxvi_ldm_vblk_record_header_fields,SX_COUNT(sxvi_ldm_vblk_record_header_fields),SX_BE};

static const xx_data_struct_field_desc sxvi_ldm_variable_length_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxvi_ldm_variable_length = {0x60530051U,"ldm_variable_length",sxvi_ldm_variable_length_fields,SX_COUNT(sxvi_ldm_variable_length_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_hsf_volume_prefix_fields[] = {
    SX_FIELD("descriptor_sector_le","uint32le",0,4,SX_NONE),
    SX_FIELD("descriptor_sector_be","uint32be",4,4,SX_NONE),
    SX_FIELD("type","uint8",8,1,SX_ID),
    SX_FIELD("signature","char[5]",9,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",14,1,SX_ID),
    SX_FIELD("unused0","uint8",15,1,SX_RESERVED),
    SX_FIELD("system_identifier","char[32]",16,32,SX_STRING),
    SX_FIELD("volume_identifier","char[32]",48,32,SX_STRING),
    SX_FIELD("unused1","byte[8]",80,8,SX_RESERVED),
    SX_FIELD("volume_blocks_le","uint32le",88,4,SX_COUNT_PROP),
    SX_FIELD("volume_blocks_be","uint32be",92,4,SX_COUNT_PROP),
    SX_FIELD("unused2","byte[32]",96,32,SX_RESERVED),
    SX_FIELD("volume_set_size_le","uint16le",128,2,SX_COUNT_PROP),
    SX_FIELD("volume_set_size_be","uint16be",130,2,SX_COUNT_PROP),
    SX_FIELD("sequence_number_le","uint16le",132,2,SX_ID),
    SX_FIELD("sequence_number_be","uint16be",134,2,SX_ID),
    SX_FIELD("block_size_le","uint16le",136,2,SX_SIZE),
    SX_FIELD("block_size_be","uint16be",138,2,SX_SIZE),
    SX_FIELD("path_table_size_le","uint32le",140,4,SX_SIZE),
    SX_FIELD("path_table_size_be","uint32be",144,4,SX_SIZE),
    SX_FIELD("path_table_locations","byte[32]",148,32,SX_NONE),
};
static const sx_layout sxvi_hsf_volume_prefix = {0x60530052U,"hsf_volume_prefix",sxvi_hsf_volume_prefix_fields,SX_COUNT(sxvi_hsf_volume_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_hsf_descriptor_header_fields[] = {
    SX_FIELD("descriptor_sector_le","uint32le",0,4,SX_NONE),
    SX_FIELD("descriptor_sector_be","uint32be",4,4,SX_NONE),
    SX_FIELD("type","uint8",8,1,SX_ID),
    SX_FIELD("signature","char[5]",9,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",14,1,SX_ID),
};
static const sx_layout sxvi_hsf_descriptor_header = {0x60530053U,"hsf_descriptor_header",sxvi_hsf_descriptor_header_fields,SX_COUNT(sxvi_hsf_descriptor_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_hsf_directory_record_fields[] = {
    SX_FIELD("record_size","uint8",0,1,SX_SIZE),
    SX_FIELD("extended_attribute_blocks","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("extent_block_le","uint32le",2,4,SX_NONE),
    SX_FIELD("extent_block_be","uint32be",6,4,SX_NONE),
    SX_FIELD("data_size_le","uint32le",10,4,SX_SIZE),
    SX_FIELD("data_size_be","uint32be",14,4,SX_SIZE),
    SX_FIELD("year_since1900","uint8",18,1,SX_NONE),
    SX_FIELD("month","uint8",19,1,SX_NONE),
    SX_FIELD("day","uint8",20,1,SX_NONE),
    SX_FIELD("hour","uint8",21,1,SX_NONE),
    SX_FIELD("minute","uint8",22,1,SX_NONE),
    SX_FIELD("second","uint8",23,1,SX_NONE),
    SX_FIELD("flags","uint8",24,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",25,1,SX_RESERVED),
    SX_FIELD("interleave_unit_blocks","uint8",26,1,SX_COUNT_PROP),
    SX_FIELD("interleave_gap_blocks","uint8",27,1,SX_COUNT_PROP),
    SX_FIELD("volume_sequence_le","uint16le",28,2,SX_ID),
    SX_FIELD("volume_sequence_be","uint16be",30,2,SX_ID),
    SX_FIELD("identifier_size","uint8",32,1,SX_SIZE),
};
static const sx_layout sxvi_hsf_directory_record = {0x60530054U,"hsf_directory_record",sxvi_hsf_directory_record_fields,SX_COUNT(sxvi_hsf_directory_record_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_hsf_volume_identifiers_fields[] = {
    SX_FIELD("volume_set_identifier","char[128]",0,128,SX_STRING),
    SX_FIELD("publisher_identifier","char[128]",128,128,SX_STRING),
    SX_FIELD("preparer_identifier","char[128]",256,128,SX_STRING),
    SX_FIELD("application_identifier","char[128]",384,128,SX_STRING),
    SX_FIELD("copyright_identifier","char[32]",512,32,SX_STRING),
    SX_FIELD("abstract_identifier","char[32]",544,32,SX_STRING),
    SX_FIELD("creation_time","char[16]",576,16,SX_STRING),
    SX_FIELD("modification_time","char[16]",592,16,SX_STRING),
    SX_FIELD("expiration_time","char[16]",608,16,SX_STRING),
    SX_FIELD("effective_time","char[16]",624,16,SX_STRING),
    SX_FIELD("file_structure_version","uint8",640,1,SX_ID),
};
static const sx_layout sxvi_hsf_volume_identifiers = {0x60530055U,"hsf_volume_identifiers",sxvi_hsf_volume_identifiers_fields,SX_COUNT(sxvi_hsf_volume_identifiers_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_cdi_footer_v2_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("descriptor_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxvi_cdi_footer_v2 = {0x60530056U,"cdi_footer_v2",sxvi_cdi_footer_v2_fields,SX_COUNT(sxvi_cdi_footer_v2_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_cdi_footer_v35_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("descriptor_distance","uint32",4,4,SX_SIZE),
};
static const sx_layout sxvi_cdi_footer_v35 = {0x60530057U,"cdi_footer_v35",sxvi_cdi_footer_v35_fields,SX_COUNT(sxvi_cdi_footer_v35_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_cdi_descriptor_header_fields[] = {
    SX_FIELD("session_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxvi_cdi_descriptor_header = {0x60530058U,"cdi_descriptor_header",sxvi_cdi_descriptor_header_fields,SX_COUNT(sxvi_cdi_descriptor_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_cdi_track_prefix_fields[] = {
    SX_FIELD("markers","byte[20]",0,20,SX_SIGNATURE),
    SX_FIELD("unknown","byte[4]",20,4,SX_NONE),
    SX_FIELD("filename_length","uint8",24,1,SX_SIZE),
};
static const sx_layout sxvi_cdi_track_prefix = {0x60530059U,"cdi_track_prefix",sxvi_cdi_track_prefix_fields,SX_COUNT(sxvi_cdi_track_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_cdi_index_count_fields[] = {
    SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxvi_cdi_index_count = {0x6053005aU,"cdi_index_count",sxvi_cdi_index_count_fields,SX_COUNT(sxvi_cdi_index_count_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_cdi_index_fields[] = {
    SX_FIELD("sectors","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxvi_cdi_index = {0x6053005bU,"cdi_index",sxvi_cdi_index_fields,SX_COUNT(sxvi_cdi_index_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_cdi_cdtext_count_fields[] = {
    SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxvi_cdi_cdtext_count = {0x6053005cU,"cdi_cdtext_count",sxvi_cdi_cdtext_count_fields,SX_COUNT(sxvi_cdi_cdtext_count_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_cdi_track_geometry_fields[] = {
    SX_FIELD("unknown0","byte[2]",0,2,SX_NONE),
    SX_FIELD("mode","uint32",2,4,SX_ID),
    SX_FIELD("unknown1","byte[4]",6,4,SX_NONE),
    SX_FIELD("session_index","uint32",10,4,SX_NONE),
    SX_FIELD("track_index","uint32",14,4,SX_NONE),
    SX_FIELD("start_sector","uint32",18,4,SX_NONE),
    SX_FIELD("sector_count","uint32",22,4,SX_COUNT_PROP),
    SX_FIELD("unknown2","byte[16]",26,16,SX_NONE),
    SX_FIELD("read_mode","uint32",42,4,SX_ID),
};
static const sx_layout sxvi_cdi_track_geometry = {0x6053005dU,"cdi_track_geometry",sxvi_cdi_track_geometry_fields,SX_COUNT(sxvi_cdi_track_geometry_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_partimage_volume_header_fields[] = {
    SX_FIELD("magic","char[32]",0,32,SX_SIGNATURE),
    SX_FIELD("version","char[64]",32,64,SX_STRING),
    SX_FIELD("volume_number","uint32",96,4,SX_NONE),
    SX_FIELD("identifier","uint64",100,8,SX_ID),
    SX_FIELD("reserved","byte[404]",108,404,SX_RESERVED),
};
static const sx_layout sxvi_partimage_volume_header = {0x6053005eU,"partimage_volume_header",sxvi_partimage_volume_header_fields,SX_COUNT(sxvi_partimage_volume_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_partimage_main_header_fields[] = {
    SX_FIELD("filesystem","char[512]",0,512,SX_STRING),
    SX_FIELD("description","char[4096]",512,4096,SX_STRING),
    SX_FIELD("original_device","char[512]",4608,512,SX_STRING),
    SX_FIELD("first_image_filepath","char[4095]",5120,4095,SX_STRING),
    SX_FIELD("uname_system","char[65]",9215,65,SX_STRING),
    SX_FIELD("uname_node","char[65]",9280,65,SX_STRING),
    SX_FIELD("uname_release","char[65]",9345,65,SX_STRING),
    SX_FIELD("uname_version","char[65]",9410,65,SX_STRING),
    SX_FIELD("uname_machine","char[65]",9475,65,SX_STRING),
    SX_FIELD("compression","uint32",9540,4,SX_ID),
    SX_FIELD("flags","uint32",9544,4,SX_FLAGS),
    SX_FIELD("second","uint32",9548,4,SX_NONE),
    SX_FIELD("minute","uint32",9552,4,SX_NONE),
    SX_FIELD("hour","uint32",9556,4,SX_NONE),
    SX_FIELD("day","uint32",9560,4,SX_NONE),
    SX_FIELD("month","uint32",9564,4,SX_NONE),
    SX_FIELD("year","uint32",9568,4,SX_NONE),
    SX_FIELD("weekday","uint32",9572,4,SX_NONE),
    SX_FIELD("yearday","uint32",9576,4,SX_NONE),
    SX_FIELD("daylight_saving","uint32",9580,4,SX_NONE),
    SX_FIELD("timezone_offset","uint32",9584,4,SX_NONE),
    SX_FIELD("timezone_word","uint32",9588,4,SX_NONE),
    SX_FIELD("partition_size","uint64",9592,8,SX_SIZE),
    SX_FIELD("hostname","char[128]",9600,128,SX_STRING),
    SX_FIELD("version","char[64]",9728,64,SX_STRING),
    SX_FIELD("mbr_count","uint32",9792,4,SX_COUNT_PROP),
    SX_FIELD("mbr_record_size","uint32",9796,4,SX_SIZE),
    SX_FIELD("encryption_algorithm","uint32",9800,4,SX_ID),
    SX_FIELD("test_key_hash","byte[16]",9804,16,SX_CHECKSUM),
    SX_FIELD("future_extensions","uint32[10]",9820,40,SX_RESERVED),
    SX_FIELD("reserved","byte[6524]",9860,6524,SX_RESERVED),
};
static const sx_layout sxvi_partimage_main_header = {0x6053005fU,"partimage_main_header",sxvi_partimage_main_header_fields,SX_COUNT(sxvi_partimage_main_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_partimage_local_header_fields[] = {
    SX_FIELD("block_size","uint64",0,8,SX_SIZE),
    SX_FIELD("used_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("block_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("bitmap_size","uint64",24,8,SX_SIZE),
    SX_FIELD("bad_blocks","uint64",32,8,SX_COUNT_PROP),
    SX_FIELD("label","char[64]",40,64,SX_STRING),
    SX_FIELD("reserved","byte[16280]",104,16280,SX_RESERVED),
};
static const sx_layout sxvi_partimage_local_header = {0x60530060U,"partimage_local_header",sxvi_partimage_local_header_fields,SX_COUNT(sxvi_partimage_local_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_partimage_header_checksum_fields[] = {
    SX_FIELD("additive_checksum","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxvi_partimage_header_checksum = {0x60530061U,"partimage_header_checksum",sxvi_partimage_header_checksum_fields,SX_COUNT(sxvi_partimage_header_checksum_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_partimage_extension_header_fields[] = {
    SX_FIELD("magic","char[18]",0,18,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",18,4,SX_SIZE),
};
static const sx_layout sxvi_partimage_extension_header = {0x60530062U,"partimage_extension_header",sxvi_partimage_extension_header_fields,SX_COUNT(sxvi_partimage_extension_header_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_partimage_data_check_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("block_position","uint64",8,8,SX_NONE),
};
static const sx_layout sxvi_partimage_data_check = {0x60530063U,"partimage_data_check",sxvi_partimage_data_check_fields,SX_COUNT(sxvi_partimage_data_check_fields),SX_LE};

static const xx_data_struct_field_desc sxvi_partimage_tail_fields[] = {
    SX_FIELD("additive_checksum","uint64",0,8,SX_CHECKSUM),
    SX_FIELD("volume_number","uint32",8,4,SX_NONE),
    SX_FIELD("reserved","byte[16372]",12,16372,SX_RESERVED),
};
static const sx_layout sxvi_partimage_tail = {0x60530064U,"partimage_tail",sxvi_partimage_tail_fields,SX_COUNT(sxvi_partimage_tail_fields),SX_LE};

static const sx_layout *const sx_volumeimages_layouts[] = {
    &sxvi_lvm2_label_header,
    &sxvi_lvm2_pv_header,
    &sxvi_lvm2_disk_location,
    &sxvi_lvm2_pv_extension,
    &sxvi_lvm2_mda_header,
    &sxvi_lvm2_raw_location,
    &sxvi_ewf1_file_header,
    &sxvi_ewf1_section_descriptor,
    &sxvi_ewf1_volume,
    &sxvi_ewf1_logical_volume,
    &sxvi_ewf1_smart_volume,
    &sxvi_ewf1_table_header,
    &sxvi_ewf1_chunk_entry,
    &sxvi_image_adler32,
    &sxvi_ewf1_hash,
    &sxvi_ewf1_digest,
    &sxvi_ewf1_ltree_header,
    &sxvi_ewf2_file_header,
    &sxvi_ewf2_section_descriptor,
    &sxvi_ewf2_table_header,
    &sxvi_ewf2_chunk_entry,
    &sxvi_ewf2_pattern_entry,
    &sxvi_ewf2_md5,
    &sxvi_ewf2_sha1,
    &sxvi_uif_trailer,
    &sxvi_uif_table_header,
    &sxvi_uif_block_entry,
    &sxvi_uif_descriptor_header,
    &sxvi_uif_output_format,
    &sxvi_gbi_header100,
    &sxvi_gbi_header110,
    &sxvi_gbi_descriptor,
    &sxvi_gbi_part_count,
    &sxvi_zisofs_header,
    &sxvi_zisofs_block_pointer,
    &sxvi_btrfs_send_header,
    &sxvi_btrfs_send_command,
    &sxvi_btrfs_send_attribute,
    &sxvi_btrfs_send_data_attribute_v2,
    &sxvi_btrfs_send_uuid,
    &sxvi_btrfs_send_id64,
    &sxvi_btrfs_send_size64,
    &sxvi_btrfs_send_offset64,
    &sxvi_btrfs_send_flags64,
    &sxvi_btrfs_send_flags32,
    &sxvi_btrfs_send_codec32,
    &sxvi_btrfs_send_timespec,
    &sxvi_aaru2_header,
    &sxvi_aaru2_ddt_header,
    &sxvi_aaru2_ddt_entry,
    &sxvi_aaru_index3,
    &sxvi_aaru_index_entry,
    &sxvi_aaru_data_header,
    &sxvi_aff_segment_header,
    &sxvi_aff_segment_footer,
    &sxvi_aff_quadword,
    &sxvi_bsd_disklabel_le,
    &sxvi_bsd_disklabel_be,
    &sxvi_bsd_partition_le,
    &sxvi_bsd_partition_be,
    &sxvi_md1_superblock,
    &sxvi_md1_superblock_ppl,
    &sxvi_md1_device_role,
    &sxvi_md090_header_le,
    &sxvi_md090_header_be,
    &sxvi_md090_disk_le,
    &sxvi_md090_disk_be,
    &sxvi_sun_sparc_label,
    &sxvi_sun_x86_label,
    &sxvi_nextstep_container_header,
    &sxvi_mds_header,
    &sxvi_mds_session,
    &sxvi_mds_track,
    &sxvi_mds_track_extra,
    &sxvi_mds_footer,
    &sxvi_ldm_private_header,
    &sxvi_ldm_tocblock,
    &sxvi_ldm_vmdb_header,
    &sxvi_ldm_vblk_fragment,
    &sxvi_ldm_vblk_record_header,
    &sxvi_ldm_variable_length,
    &sxvi_hsf_volume_prefix,
    &sxvi_hsf_descriptor_header,
    &sxvi_hsf_directory_record,
    &sxvi_hsf_volume_identifiers,
    &sxvi_cdi_footer_v2,
    &sxvi_cdi_footer_v35,
    &sxvi_cdi_descriptor_header,
    &sxvi_cdi_track_prefix,
    &sxvi_cdi_index_count,
    &sxvi_cdi_index,
    &sxvi_cdi_cdtext_count,
    &sxvi_cdi_track_geometry,
    &sxvi_partimage_volume_header,
    &sxvi_partimage_main_header,
    &sxvi_partimage_local_header,
    &sxvi_partimage_header_checksum,
    &sxvi_partimage_extension_header,
    &sxvi_partimage_data_check,
    &sxvi_partimage_tail,
};

typedef struct sxvi_flag {uint64_t mask;const wchar_t*name;} sxvi_flag;
static bool sxvi_flags(xx_data_struct_record*r,uint64_t value,const sxvi_flag*bits,size_t n){
 wchar_t out[1024];size_t used=0;uint64_t known=0;
 for(size_t i=0;i<n;i++){known|=bits[i].mask;if(!(value&bits[i].mask))continue;const wchar_t*p=bits[i].name;size_t z=xx_rt_wcslen(p);if(z+used+24>=SX_COUNT(out))return false;if(used)out[used++]=L'|';while(*p)out[used++]=*p++;}
 uint64_t unknown=value&~known;if(unknown){if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';bool start=false;for(int shift=60;shift>=0;shift-=4){unsigned d=(unsigned)((unknown>>shift)&15);if(d||start||!shift){out[used++]=L"0123456789ABCDEF"[d];start=true;}}}
 if(!used)out[used++]=L'0';out[used]=0;return xx_data_struct_record_set_comment(r,out);
}

static bool sx_volumeimages_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60530000U||id>=0x60540000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    if(id==0x6053003dU&&!xx_rt_wcscmp(r->name,L"feature_map")&&integer){static const sxvi_flag bits[]={{1U,L"MD_FEATURE_BITMAP_OFFSET"},{2U,L"MD_FEATURE_RECOVERY_OFFSET"},{4U,L"MD_FEATURE_RESHAPE_ACTIVE"},{8U,L"MD_FEATURE_BAD_BLOCKS"},{16U,L"MD_FEATURE_REPLACEMENT"},{32U,L"MD_FEATURE_RESHAPE_BACKWARDS"},{64U,L"MD_FEATURE_NEW_OFFSET"},{128U,L"MD_FEATURE_RECOVERY_BITMAP"},{256U,L"MD_FEATURE_CLUSTERED"},{512U,L"MD_FEATURE_JOURNAL"},{1024U,L"MD_FEATURE_PPL"},{2048U,L"MD_FEATURE_MULTIPLE_PPLS"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6053003eU&&!xx_rt_wcscmp(r->name,L"feature_map")&&integer){static const sxvi_flag bits[]={{1U,L"MD_FEATURE_BITMAP_OFFSET"},{2U,L"MD_FEATURE_RECOVERY_OFFSET"},{4U,L"MD_FEATURE_RESHAPE_ACTIVE"},{8U,L"MD_FEATURE_BAD_BLOCKS"},{16U,L"MD_FEATURE_REPLACEMENT"},{32U,L"MD_FEATURE_RESHAPE_BACKWARDS"},{64U,L"MD_FEATURE_NEW_OFFSET"},{128U,L"MD_FEATURE_RECOVERY_BITMAP"},{256U,L"MD_FEATURE_CLUSTERED"},{512U,L"MD_FEATURE_JOURNAL"},{1024U,L"MD_FEATURE_PPL"},{2048U,L"MD_FEATURE_MULTIPLE_PPLS"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530013U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"Has data integrity hash"},{2U,L"Encrypted"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530004U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"PV_EXT_USED"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530006U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"RAW_LOCN_IGNORED"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530015U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"COMPRESSED"},{2U,L"CHECKSUMMED"},{4U,L"PATTERNFILL"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530016U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"COMPRESSED"},{2U,L"CHECKSUMMED"},{4U,L"PATTERNFILL"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_0_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_1_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_2_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_3_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_4_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_5_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_6_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_7_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_0_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_1_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_2_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_3_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_4_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_5_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_6_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_7_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_8_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_9_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_10_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_11_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_12_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_13_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_14_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_15_flags")&&integer){static const sxvi_flag bits[]={{1U,L"V_UNMNT"},{16U,L"V_RONLY"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530042U&&!xx_rt_wcscmp(r->name,L"state")&&integer){static const sxvi_flag bits[]={{1U,L"MD_DISK_FAULTY"},{2U,L"MD_DISK_ACTIVE"},{4U,L"MD_DISK_SYNC"},{8U,L"MD_DISK_REMOVED"},{16U,L"MD_DISK_CLUSTER_ADD"},{32U,L"MD_DISK_CANDIDATE"},{512U,L"MD_DISK_WRITEMOSTLY"},{1024U,L"MD_DISK_FAILFAST"},{262144U,L"MD_DISK_JOURNAL"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530043U&&!xx_rt_wcscmp(r->name,L"state")&&integer){static const sxvi_flag bits[]={{1U,L"MD_DISK_FAULTY"},{2U,L"MD_DISK_ACTIVE"},{4U,L"MD_DISK_SYNC"},{8U,L"MD_DISK_REMOVED"},{16U,L"MD_DISK_CLUSTER_ADD"},{32U,L"MD_DISK_CANDIDATE"},{512U,L"MD_DISK_WRITEMOSTLY"},{1024U,L"MD_DISK_FAILFAST"},{262144U,L"MD_DISK_JOURNAL"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530040U&&!xx_rt_wcscmp(r->name,L"state")&&integer){static const sxvi_flag bits[]={{1U,L"MD_SB_CLEAN"},{2U,L"MD_SB_ERRORS"},{32U,L"MD_SB_CLUSTERED"},{256U,L"MD_SB_BITMAP_PRESENT"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530041U&&!xx_rt_wcscmp(r->name,L"state")&&integer){static const sxvi_flag bits[]={{1U,L"MD_SB_CLEAN"},{2U,L"MD_SB_ERRORS"},{32U,L"MD_SB_CLUSTERED"},{256U,L"MD_SB_BITMAP_PRESENT"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530039U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"D_REMOVABLE"},{2U,L"D_ECC"},{4U,L"D_BADSECT"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6053003aU&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxvi_flag bits[]={{1U,L"D_REMOVABLE"},{2U,L"D_ECC"},{4U,L"D_BADSECT"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530009U&&!xx_rt_wcscmp(r->name,L"media_flags")&&integer){static const sxvi_flag bits[]={{1U,L"IMAGE_FILE"},{2U,L"PHYSICAL_DEVICE"},{4U,L"FASTBLOC_WRITE_BLOCKER"},{8U,L"TABLEAU_WRITE_BLOCKER"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6053000aU&&!xx_rt_wcscmp(r->name,L"media_flags")&&integer){static const sxvi_flag bits[]={{1U,L"IMAGE_FILE"},{2U,L"PHYSICAL_DEVICE"},{4U,L"FASTBLOC_WRITE_BLOCKER"},{8U,L"TABLEAU_WRITE_BLOCKER"}};return sxvi_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60530009U&&!xx_rt_wcscmp(r->name,L"media_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Removable media");
    case 1U:return xx_data_struct_record_set_comment(r,L"Fixed media");
    case 3U:return xx_data_struct_record_set_comment(r,L"Optical media");
    case 14U:return xx_data_struct_record_set_comment(r,L"Logical evidence file");
    case 16U:return xx_data_struct_record_set_comment(r,L"Physical memory (RAM)");
    default:break;}}
    if(id==0x6053000aU&&!xx_rt_wcscmp(r->name,L"media_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Removable media");
    case 1U:return xx_data_struct_record_set_comment(r,L"Fixed media");
    case 3U:return xx_data_struct_record_set_comment(r,L"Optical media");
    case 14U:return xx_data_struct_record_set_comment(r,L"Logical evidence file");
    case 16U:return xx_data_struct_record_set_comment(r,L"Physical memory (RAM)");
    default:break;}}
    if(id==0x60530009U&&!xx_rt_wcscmp(r->name,L"compression_level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No compression");
    case 1U:return xx_data_struct_record_set_comment(r,L"Fast compression");
    case 2U:return xx_data_struct_record_set_comment(r,L"Best compression");
    default:break;}}
    if(id==0x6053000aU&&!xx_rt_wcscmp(r->name,L"compression_level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No compression");
    case 1U:return xx_data_struct_record_set_comment(r,L"Fast compression");
    case 2U:return xx_data_struct_record_set_comment(r,L"Best compression");
    default:break;}}
    if(id==0x60530012U&&!xx_rt_wcscmp(r->name,L"compression_method")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No compression");
    case 1U:return xx_data_struct_record_set_comment(r,L"DEFLATE (zlib)");
    case 2U:return xx_data_struct_record_set_comment(r,L"BZIP2");
    default:break;}}
    if(id==0x60530013U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Device information");
    case 2U:return xx_data_struct_record_set_comment(r,L"Case data");
    case 3U:return xx_data_struct_record_set_comment(r,L"Sector data");
    case 4U:return xx_data_struct_record_set_comment(r,L"Sector table");
    case 5U:return xx_data_struct_record_set_comment(r,L"Error table");
    case 6U:return xx_data_struct_record_set_comment(r,L"Session table");
    case 7U:return xx_data_struct_record_set_comment(r,L"Increment data");
    case 8U:return xx_data_struct_record_set_comment(r,L"MD5 hash");
    case 9U:return xx_data_struct_record_set_comment(r,L"SHA1 hash");
    case 10U:return xx_data_struct_record_set_comment(r,L"Restart data");
    case 11U:return xx_data_struct_record_set_comment(r,L"Encryption keys");
    case 12U:return xx_data_struct_record_set_comment(r,L"Memory extents table");
    case 13U:return xx_data_struct_record_set_comment(r,L"Next segment");
    case 14U:return xx_data_struct_record_set_comment(r,L"Final information");
    case 15U:return xx_data_struct_record_set_comment(r,L"Done");
    case 16U:return xx_data_struct_record_set_comment(r,L"Analytical data");
    case 32U:return xx_data_struct_record_set_comment(r,L"Single files data");
    default:break;}}
    if(id==0x60530013U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"Has data integrity hash");
    case 2U:return xx_data_struct_record_set_comment(r,L"Encrypted");
    default:break;}}
    if(id==0x60530015U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 1U:return xx_data_struct_record_set_comment(r,L"Compressed");
    case 2U:return xx_data_struct_record_set_comment(r,L"Stored with Adler32");
    case 5U:return xx_data_struct_record_set_comment(r,L"Compressed flag with repeated 8-byte fill pattern");
    default:break;}}
    if(id==0x60530016U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 1U:return xx_data_struct_record_set_comment(r,L"Compressed");
    case 2U:return xx_data_struct_record_set_comment(r,L"Stored with Adler32");
    case 5U:return xx_data_struct_record_set_comment(r,L"Compressed flag with repeated 8-byte fill pattern");
    default:break;}}
    if(id==0x60530004U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"PV_EXT_USED");
    default:break;}}
    if(id==0x60530006U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAW_LOCN_IGNORED");
    default:break;}}
    if(id==0x6053001bU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Stored block");
    case 3U:return xx_data_struct_record_set_comment(r,L"Zero block");
    case 5U:return xx_data_struct_record_set_comment(r,L"Compressed block");
    default:break;}}
    if(id==0x6053001dU&&!xx_rt_wcscmp(r->name,L"output_format")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"ISO");
    case 1U:return xx_data_struct_record_set_comment(r,L"BIN/CUE");
    case 2U:return xx_data_struct_record_set_comment(r,L"MDF/MDS");
    case 3U:return xx_data_struct_record_set_comment(r,L"IMG/CCD/SUB");
    case 4U:return xx_data_struct_record_set_comment(r,L"NRG");
    default:break;}}
    if(id==0x60530020U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 2U:return xx_data_struct_record_set_comment(r,L"Split-volume descriptor");
    case 3U:return xx_data_struct_record_set_comment(r,L"Encryption descriptor");
    default:break;}}
    if(id==0x6053001fU&&!xx_rt_wcscmp(r->name,L"lzma_filter")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No filter");
    case 1U:return xx_data_struct_record_set_comment(r,L"x86 BCJ");
    default:break;}}
    if(id==0x60530025U&&!xx_rt_wcscmp(r->name,L"command")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"UNSPEC");
    case 1U:return xx_data_struct_record_set_comment(r,L"SUBVOL");
    case 2U:return xx_data_struct_record_set_comment(r,L"SNAPSHOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"MKFILE");
    case 4U:return xx_data_struct_record_set_comment(r,L"MKDIR");
    case 5U:return xx_data_struct_record_set_comment(r,L"MKNOD");
    case 6U:return xx_data_struct_record_set_comment(r,L"MKFIFO");
    case 7U:return xx_data_struct_record_set_comment(r,L"MKSOCK");
    case 8U:return xx_data_struct_record_set_comment(r,L"SYMLINK");
    case 9U:return xx_data_struct_record_set_comment(r,L"RENAME");
    case 10U:return xx_data_struct_record_set_comment(r,L"LINK");
    case 11U:return xx_data_struct_record_set_comment(r,L"UNLINK");
    case 12U:return xx_data_struct_record_set_comment(r,L"RMDIR");
    case 13U:return xx_data_struct_record_set_comment(r,L"SET_XATTR");
    case 14U:return xx_data_struct_record_set_comment(r,L"REMOVE_XATTR");
    case 15U:return xx_data_struct_record_set_comment(r,L"WRITE");
    case 16U:return xx_data_struct_record_set_comment(r,L"CLONE");
    case 17U:return xx_data_struct_record_set_comment(r,L"TRUNCATE");
    case 18U:return xx_data_struct_record_set_comment(r,L"CHMOD");
    case 19U:return xx_data_struct_record_set_comment(r,L"CHOWN");
    case 20U:return xx_data_struct_record_set_comment(r,L"UTIMES");
    case 21U:return xx_data_struct_record_set_comment(r,L"END");
    case 22U:return xx_data_struct_record_set_comment(r,L"UPDATE_EXTENT");
    case 23U:return xx_data_struct_record_set_comment(r,L"FALLOCATE");
    case 24U:return xx_data_struct_record_set_comment(r,L"FILEATTR");
    case 25U:return xx_data_struct_record_set_comment(r,L"ENCODED_WRITE");
    case 26U:return xx_data_struct_record_set_comment(r,L"ENABLE_VERITY");
    default:break;}}
    if(id==0x60530026U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"UNSPEC");
    case 1U:return xx_data_struct_record_set_comment(r,L"UUID");
    case 2U:return xx_data_struct_record_set_comment(r,L"CTRANSID");
    case 3U:return xx_data_struct_record_set_comment(r,L"INO");
    case 4U:return xx_data_struct_record_set_comment(r,L"SIZE");
    case 5U:return xx_data_struct_record_set_comment(r,L"MODE");
    case 6U:return xx_data_struct_record_set_comment(r,L"UID");
    case 7U:return xx_data_struct_record_set_comment(r,L"GID");
    case 8U:return xx_data_struct_record_set_comment(r,L"RDEV");
    case 9U:return xx_data_struct_record_set_comment(r,L"CTIME");
    case 10U:return xx_data_struct_record_set_comment(r,L"MTIME");
    case 11U:return xx_data_struct_record_set_comment(r,L"ATIME");
    case 12U:return xx_data_struct_record_set_comment(r,L"OTIME");
    case 13U:return xx_data_struct_record_set_comment(r,L"XATTR_NAME");
    case 14U:return xx_data_struct_record_set_comment(r,L"XATTR_DATA");
    case 15U:return xx_data_struct_record_set_comment(r,L"PATH");
    case 16U:return xx_data_struct_record_set_comment(r,L"PATH_TO");
    case 17U:return xx_data_struct_record_set_comment(r,L"PATH_LINK");
    case 18U:return xx_data_struct_record_set_comment(r,L"FILE_OFFSET");
    case 19U:return xx_data_struct_record_set_comment(r,L"DATA");
    case 20U:return xx_data_struct_record_set_comment(r,L"CLONE_UUID");
    case 21U:return xx_data_struct_record_set_comment(r,L"CLONE_CTRANSID");
    case 22U:return xx_data_struct_record_set_comment(r,L"CLONE_PATH");
    case 23U:return xx_data_struct_record_set_comment(r,L"CLONE_OFFSET");
    case 24U:return xx_data_struct_record_set_comment(r,L"CLONE_LEN");
    case 25U:return xx_data_struct_record_set_comment(r,L"FALLOCATE_MODE");
    case 26U:return xx_data_struct_record_set_comment(r,L"FILEATTR");
    case 27U:return xx_data_struct_record_set_comment(r,L"UNENCODED_FILE_LEN");
    case 28U:return xx_data_struct_record_set_comment(r,L"UNENCODED_LEN");
    case 29U:return xx_data_struct_record_set_comment(r,L"UNENCODED_OFFSET");
    case 30U:return xx_data_struct_record_set_comment(r,L"COMPRESSION");
    case 31U:return xx_data_struct_record_set_comment(r,L"ENCRYPTION");
    case 32U:return xx_data_struct_record_set_comment(r,L"VERITY_ALGORITHM");
    case 33U:return xx_data_struct_record_set_comment(r,L"VERITY_BLOCK_SIZE");
    case 34U:return xx_data_struct_record_set_comment(r,L"VERITY_SALT_DATA");
    case 35U:return xx_data_struct_record_set_comment(r,L"VERITY_SIG_DATA");
    default:break;}}
    if(id==0x60530027U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"UNSPEC");
    case 1U:return xx_data_struct_record_set_comment(r,L"UUID");
    case 2U:return xx_data_struct_record_set_comment(r,L"CTRANSID");
    case 3U:return xx_data_struct_record_set_comment(r,L"INO");
    case 4U:return xx_data_struct_record_set_comment(r,L"SIZE");
    case 5U:return xx_data_struct_record_set_comment(r,L"MODE");
    case 6U:return xx_data_struct_record_set_comment(r,L"UID");
    case 7U:return xx_data_struct_record_set_comment(r,L"GID");
    case 8U:return xx_data_struct_record_set_comment(r,L"RDEV");
    case 9U:return xx_data_struct_record_set_comment(r,L"CTIME");
    case 10U:return xx_data_struct_record_set_comment(r,L"MTIME");
    case 11U:return xx_data_struct_record_set_comment(r,L"ATIME");
    case 12U:return xx_data_struct_record_set_comment(r,L"OTIME");
    case 13U:return xx_data_struct_record_set_comment(r,L"XATTR_NAME");
    case 14U:return xx_data_struct_record_set_comment(r,L"XATTR_DATA");
    case 15U:return xx_data_struct_record_set_comment(r,L"PATH");
    case 16U:return xx_data_struct_record_set_comment(r,L"PATH_TO");
    case 17U:return xx_data_struct_record_set_comment(r,L"PATH_LINK");
    case 18U:return xx_data_struct_record_set_comment(r,L"FILE_OFFSET");
    case 19U:return xx_data_struct_record_set_comment(r,L"DATA");
    case 20U:return xx_data_struct_record_set_comment(r,L"CLONE_UUID");
    case 21U:return xx_data_struct_record_set_comment(r,L"CLONE_CTRANSID");
    case 22U:return xx_data_struct_record_set_comment(r,L"CLONE_PATH");
    case 23U:return xx_data_struct_record_set_comment(r,L"CLONE_OFFSET");
    case 24U:return xx_data_struct_record_set_comment(r,L"CLONE_LEN");
    case 25U:return xx_data_struct_record_set_comment(r,L"FALLOCATE_MODE");
    case 26U:return xx_data_struct_record_set_comment(r,L"FILEATTR");
    case 27U:return xx_data_struct_record_set_comment(r,L"UNENCODED_FILE_LEN");
    case 28U:return xx_data_struct_record_set_comment(r,L"UNENCODED_LEN");
    case 29U:return xx_data_struct_record_set_comment(r,L"UNENCODED_OFFSET");
    case 30U:return xx_data_struct_record_set_comment(r,L"COMPRESSION");
    case 31U:return xx_data_struct_record_set_comment(r,L"ENCRYPTION");
    case 32U:return xx_data_struct_record_set_comment(r,L"VERITY_ALGORITHM");
    case 33U:return xx_data_struct_record_set_comment(r,L"VERITY_BLOCK_SIZE");
    case 34U:return xx_data_struct_record_set_comment(r,L"VERITY_SALT_DATA");
    case 35U:return xx_data_struct_record_set_comment(r,L"VERITY_SIG_DATA");
    default:break;}}
    if(id==0x60530034U&&!xx_rt_wcscmp(r->name,L"block_type")&&integer){switch(value){
    case 844383300U:return xx_data_struct_record_set_comment(r,L"DDT2");
    case 1263288900U:return xx_data_struct_record_set_comment(r,L"DBLK");
    default:break;}}
    if(id==0x60530031U&&!xx_rt_wcscmp(r->name,L"data_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"User data");
    default:break;}}
    if(id==0x60530034U&&!xx_rt_wcscmp(r->name,L"data_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"User data");
    default:break;}}
    if(id==0x60530035U&&!xx_rt_wcscmp(r->name,L"data_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"User data");
    default:break;}}
    if(id==0x60530031U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    default:break;}}
    if(id==0x60530035U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    default:break;}}
    if(id==0x6053003bU&&!xx_rt_wcscmp(r->name,L"filesystem_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FS_UNUSED");
    case 1U:return xx_data_struct_record_set_comment(r,L"FS_SWAP");
    case 2U:return xx_data_struct_record_set_comment(r,L"FS_V6");
    case 3U:return xx_data_struct_record_set_comment(r,L"FS_V7");
    case 4U:return xx_data_struct_record_set_comment(r,L"FS_SYSV");
    case 5U:return xx_data_struct_record_set_comment(r,L"FS_V71K");
    case 6U:return xx_data_struct_record_set_comment(r,L"FS_V8");
    case 7U:return xx_data_struct_record_set_comment(r,L"FS_BSDFFS");
    case 8U:return xx_data_struct_record_set_comment(r,L"FS_MSDOS");
    case 9U:return xx_data_struct_record_set_comment(r,L"FS_BSDLFS");
    case 10U:return xx_data_struct_record_set_comment(r,L"FS_OTHER");
    case 11U:return xx_data_struct_record_set_comment(r,L"FS_HPFS");
    case 12U:return xx_data_struct_record_set_comment(r,L"FS_ISO9660");
    case 13U:return xx_data_struct_record_set_comment(r,L"FS_BOOT");
    case 14U:return xx_data_struct_record_set_comment(r,L"FS_VINUM");
    case 15U:return xx_data_struct_record_set_comment(r,L"FS_RAID");
    case 16U:return xx_data_struct_record_set_comment(r,L"FS_FILECORE");
    case 17U:return xx_data_struct_record_set_comment(r,L"FS_EXT2FS");
    case 18U:return xx_data_struct_record_set_comment(r,L"FS_NTFS");
    default:break;}}
    if(id==0x6053003cU&&!xx_rt_wcscmp(r->name,L"filesystem_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FS_UNUSED");
    case 1U:return xx_data_struct_record_set_comment(r,L"FS_SWAP");
    case 2U:return xx_data_struct_record_set_comment(r,L"FS_V6");
    case 3U:return xx_data_struct_record_set_comment(r,L"FS_V7");
    case 4U:return xx_data_struct_record_set_comment(r,L"FS_SYSV");
    case 5U:return xx_data_struct_record_set_comment(r,L"FS_V71K");
    case 6U:return xx_data_struct_record_set_comment(r,L"FS_V8");
    case 7U:return xx_data_struct_record_set_comment(r,L"FS_BSDFFS");
    case 8U:return xx_data_struct_record_set_comment(r,L"FS_MSDOS");
    case 9U:return xx_data_struct_record_set_comment(r,L"FS_BSDLFS");
    case 10U:return xx_data_struct_record_set_comment(r,L"FS_OTHER");
    case 11U:return xx_data_struct_record_set_comment(r,L"FS_HPFS");
    case 12U:return xx_data_struct_record_set_comment(r,L"FS_ISO9660");
    case 13U:return xx_data_struct_record_set_comment(r,L"FS_BOOT");
    case 14U:return xx_data_struct_record_set_comment(r,L"FS_VINUM");
    case 15U:return xx_data_struct_record_set_comment(r,L"FS_RAID");
    case 16U:return xx_data_struct_record_set_comment(r,L"FS_FILECORE");
    case 17U:return xx_data_struct_record_set_comment(r,L"FS_EXT2FS");
    case 18U:return xx_data_struct_record_set_comment(r,L"FS_NTFS");
    default:break;}}
    if(id==0x6053003dU&&!xx_rt_wcscmp(r->name,L"level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"RAID0");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAID1");
    case 4U:return xx_data_struct_record_set_comment(r,L"RAID4");
    case 5U:return xx_data_struct_record_set_comment(r,L"RAID5");
    case 6U:return xx_data_struct_record_set_comment(r,L"RAID6");
    case 10U:return xx_data_struct_record_set_comment(r,L"RAID10");
    case 18446744073709551615U:return xx_data_struct_record_set_comment(r,L"Linear");
    default:break;}}
    if(id==0x6053003eU&&!xx_rt_wcscmp(r->name,L"level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"RAID0");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAID1");
    case 4U:return xx_data_struct_record_set_comment(r,L"RAID4");
    case 5U:return xx_data_struct_record_set_comment(r,L"RAID5");
    case 6U:return xx_data_struct_record_set_comment(r,L"RAID6");
    case 10U:return xx_data_struct_record_set_comment(r,L"RAID10");
    case 18446744073709551615U:return xx_data_struct_record_set_comment(r,L"Linear");
    default:break;}}
    if(id==0x60530040U&&!xx_rt_wcscmp(r->name,L"level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"RAID0");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAID1");
    case 4U:return xx_data_struct_record_set_comment(r,L"RAID4");
    case 5U:return xx_data_struct_record_set_comment(r,L"RAID5");
    case 6U:return xx_data_struct_record_set_comment(r,L"RAID6");
    case 10U:return xx_data_struct_record_set_comment(r,L"RAID10");
    case 18446744073709551615U:return xx_data_struct_record_set_comment(r,L"Linear");
    default:break;}}
    if(id==0x60530041U&&!xx_rt_wcscmp(r->name,L"level")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"RAID0");
    case 1U:return xx_data_struct_record_set_comment(r,L"RAID1");
    case 4U:return xx_data_struct_record_set_comment(r,L"RAID4");
    case 5U:return xx_data_struct_record_set_comment(r,L"RAID5");
    case 6U:return xx_data_struct_record_set_comment(r,L"RAID6");
    case 10U:return xx_data_struct_record_set_comment(r,L"RAID10");
    case 18446744073709551615U:return xx_data_struct_record_set_comment(r,L"Linear");
    default:break;}}
    if(id==0x6053003dU&&!xx_rt_wcscmp(r->name,L"feature_map")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No optional features");
    case 1U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_BITMAP_OFFSET");
    case 2U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RECOVERY_OFFSET");
    case 4U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RESHAPE_ACTIVE");
    case 8U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_BAD_BLOCKS");
    case 16U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_REPLACEMENT");
    case 32U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RESHAPE_BACKWARDS");
    case 64U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_NEW_OFFSET");
    case 128U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RECOVERY_BITMAP");
    case 256U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_CLUSTERED");
    case 512U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_JOURNAL");
    case 1024U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_PPL");
    case 2048U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_MULTIPLE_PPLS");
    default:break;}}
    if(id==0x6053003eU&&!xx_rt_wcscmp(r->name,L"feature_map")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No optional features");
    case 1U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_BITMAP_OFFSET");
    case 2U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RECOVERY_OFFSET");
    case 4U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RESHAPE_ACTIVE");
    case 8U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_BAD_BLOCKS");
    case 16U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_REPLACEMENT");
    case 32U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RESHAPE_BACKWARDS");
    case 64U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_NEW_OFFSET");
    case 128U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_RECOVERY_BITMAP");
    case 256U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_CLUSTERED");
    case 512U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_JOURNAL");
    case 1024U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_PPL");
    case 2048U:return xx_data_struct_record_set_comment(r,L"MD_FEATURE_MULTIPLE_PPLS");
    default:break;}}
    if(id==0x6053003fU&&!xx_rt_wcscmp(r->name,L"role")&&integer){switch(value){
    case 65535U:return xx_data_struct_record_set_comment(r,L"MD_DISK_ROLE_SPARE");
    case 65534U:return xx_data_struct_record_set_comment(r,L"MD_DISK_ROLE_FAULTY");
    case 65533U:return xx_data_struct_record_set_comment(r,L"MD_DISK_ROLE_JOURNAL");
    default:break;}}
    if(id==0x60530050U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 50U:return xx_data_struct_record_set_comment(r,L"Component v3");
    case 51U:return xx_data_struct_record_set_comment(r,L"Partition v3");
    case 52U:return xx_data_struct_record_set_comment(r,L"Disk v3");
    case 53U:return xx_data_struct_record_set_comment(r,L"Disk group v3");
    case 68U:return xx_data_struct_record_set_comment(r,L"Disk v4");
    case 69U:return xx_data_struct_record_set_comment(r,L"Disk group v4");
    case 81U:return xx_data_struct_record_set_comment(r,L"Volume v5");
    default:break;}}
    if(id==0x6053004eU&&!xx_rt_wcscmp(r->name,L"update_state")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Database consistent");
    default:break;}}
    if(id==0x60530049U&&!xx_rt_wcscmp(r->name,L"mode")&&integer){switch(value){
    case 169U:return xx_data_struct_record_set_comment(r,L"Audio");
    case 170U:return xx_data_struct_record_set_comment(r,L"Mode 1");
    case 171U:return xx_data_struct_record_set_comment(r,L"Mode 2");
    case 236U:return xx_data_struct_record_set_comment(r,L"Mode 2 Form 1");
    case 173U:return xx_data_struct_record_set_comment(r,L"Mode 2 Form 2 alternate");
    default:break;}}
    if(id==0x60530049U&&!xx_rt_wcscmp(r->name,L"point")&&integer){switch(value){
    case 160U:return xx_data_struct_record_set_comment(r,L"First track in session");
    case 161U:return xx_data_struct_record_set_comment(r,L"Last track in session");
    case 162U:return xx_data_struct_record_set_comment(r,L"Lead-out start");
    case 176U:return xx_data_struct_record_set_comment(r,L"Next session information");
    case 192U:return xx_data_struct_record_set_comment(r,L"Lead-in information");
    default:break;}}
    if(id==0x6053005dU&&!xx_rt_wcscmp(r->name,L"read_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"2048-byte sectors");
    case 1U:return xx_data_struct_record_set_comment(r,L"2336-byte sectors");
    case 2U:return xx_data_struct_record_set_comment(r,L"2352-byte sectors");
    default:break;}}
    if(id==0x6053005dU&&!xx_rt_wcscmp(r->name,L"mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Audio");
    case 1U:return xx_data_struct_record_set_comment(r,L"Mode 1");
    case 2U:return xx_data_struct_record_set_comment(r,L"Mode 2");
    default:break;}}
    if(id==0x60530052U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Boot record");
    case 1U:return xx_data_struct_record_set_comment(r,L"Standard file structure volume descriptor");
    case 2U:return xx_data_struct_record_set_comment(r,L"Coded file structure volume descriptor");
    case 255U:return xx_data_struct_record_set_comment(r,L"Volume descriptor terminator");
    default:break;}}
    if(id==0x60530053U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Boot record");
    case 1U:return xx_data_struct_record_set_comment(r,L"Standard file structure volume descriptor");
    case 2U:return xx_data_struct_record_set_comment(r,L"Coded file structure volume descriptor");
    case 255U:return xx_data_struct_record_set_comment(r,L"Volume descriptor terminator");
    default:break;}}
    if(id==0x6053005fU&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"None");
    case 1U:return xx_data_struct_record_set_comment(r,L"Gzip");
    case 2U:return xx_data_struct_record_set_comment(r,L"Bzip2");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_0_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_0_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_1_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_1_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_2_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_2_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_3_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_3_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_4_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_4_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_5_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_5_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_6_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_6_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_7_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530044U&&!xx_rt_wcscmp(r->name,L"partition_7_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_0_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_0_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_1_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_1_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_2_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_2_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_3_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_3_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_4_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_4_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_5_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_5_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_6_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_6_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_7_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_7_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_8_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_8_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_9_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_9_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_10_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_10_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_11_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_11_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_12_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_12_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_13_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_13_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_14_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_14_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_15_tag")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"V_UNASSIGNED");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_BOOT");
    case 2U:return xx_data_struct_record_set_comment(r,L"V_ROOT");
    case 3U:return xx_data_struct_record_set_comment(r,L"V_SWAP");
    case 4U:return xx_data_struct_record_set_comment(r,L"V_USR");
    case 5U:return xx_data_struct_record_set_comment(r,L"V_BACKUP");
    case 6U:return xx_data_struct_record_set_comment(r,L"V_STAND");
    case 7U:return xx_data_struct_record_set_comment(r,L"V_VAR");
    case 8U:return xx_data_struct_record_set_comment(r,L"V_HOME");
    case 9U:return xx_data_struct_record_set_comment(r,L"V_ALTSCTR");
    case 10U:return xx_data_struct_record_set_comment(r,L"V_CACHE");
    default:break;}}
    if(id==0x60530045U&&!xx_rt_wcscmp(r->name,L"partition_15_flags")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"No flags");
    case 1U:return xx_data_struct_record_set_comment(r,L"V_UNMNT");
    case 16U:return xx_data_struct_record_set_comment(r,L"V_RONLY");
    case 17U:return xx_data_struct_record_set_comment(r,L"V_UNMNT | V_RONLY");
    default:break;}}
    if(id==0x60530039U&&!xx_rt_wcscmp(r->name,L"drive_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"DTYPE_SMD");
    case 2U:return xx_data_struct_record_set_comment(r,L"DTYPE_MSCP");
    case 3U:return xx_data_struct_record_set_comment(r,L"DTYPE_DEC");
    case 4U:return xx_data_struct_record_set_comment(r,L"DTYPE_SCSI");
    case 5U:return xx_data_struct_record_set_comment(r,L"DTYPE_ESDI");
    case 6U:return xx_data_struct_record_set_comment(r,L"DTYPE_ST506");
    case 7U:return xx_data_struct_record_set_comment(r,L"DTYPE_HPIB");
    case 8U:return xx_data_struct_record_set_comment(r,L"DTYPE_HPFL");
    case 10U:return xx_data_struct_record_set_comment(r,L"DTYPE_FLOPPY");
    case 11U:return xx_data_struct_record_set_comment(r,L"DTYPE_CCD");
    case 12U:return xx_data_struct_record_set_comment(r,L"DTYPE_VINUM");
    case 13U:return xx_data_struct_record_set_comment(r,L"DTYPE_DOC2K");
    case 14U:return xx_data_struct_record_set_comment(r,L"DTYPE_RAID");
    default:break;}}
    if(id==0x6053003aU&&!xx_rt_wcscmp(r->name,L"drive_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"DTYPE_SMD");
    case 2U:return xx_data_struct_record_set_comment(r,L"DTYPE_MSCP");
    case 3U:return xx_data_struct_record_set_comment(r,L"DTYPE_DEC");
    case 4U:return xx_data_struct_record_set_comment(r,L"DTYPE_SCSI");
    case 5U:return xx_data_struct_record_set_comment(r,L"DTYPE_ESDI");
    case 6U:return xx_data_struct_record_set_comment(r,L"DTYPE_ST506");
    case 7U:return xx_data_struct_record_set_comment(r,L"DTYPE_HPIB");
    case 8U:return xx_data_struct_record_set_comment(r,L"DTYPE_HPFL");
    case 10U:return xx_data_struct_record_set_comment(r,L"DTYPE_FLOPPY");
    case 11U:return xx_data_struct_record_set_comment(r,L"DTYPE_CCD");
    case 12U:return xx_data_struct_record_set_comment(r,L"DTYPE_VINUM");
    case 13U:return xx_data_struct_record_set_comment(r,L"DTYPE_DOC2K");
    case 14U:return xx_data_struct_record_set_comment(r,L"DTYPE_RAID");
    default:break;}}
    switch(id){
    case 0x60530001U:
        if(!xx_rt_wcscmp(r->name,L"sector_number"))s=L"Label location in 512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"LVM CRC seed 0xF597A6CF over bytes20..511";
        else if(!xx_rt_wcscmp(r->name,L"pv_header_offset"))s=L"Byte offset from the start of this label sector";
        break;
    case 0x60530003U:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset from the physical-volume image start; all-zero pair terminates a list";
        else if(!xx_rt_wcscmp(r->name,L"size"))s=L"Zero size for a data area can mean all remaining bytes";
        break;
    case 0x60530005U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"LVM CRC seed0xF597A6CF over bytes4..511";
        else if(!xx_rt_wcscmp(r->name,L"start"))s=L"Byte offset from physical-volume image start";
        break;
    case 0x60530006U:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset within this metadata area; text may wrap after its512-byte header";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit0 RAW_LOCN_IGNORED";
        break;
    case 0x60530008U:
        if(!xx_rt_wcscmp(r->name,L"next_descriptor_offset"))s=L"Relative to this segment file; terminal sections point to themselves";
        else if(!xx_rt_wcscmp(r->name,L"section_size"))s=L"Includes76-byte descriptor; terminal sections may store0";
        else if(!xx_rt_wcscmp(r->name,L"adler32"))s=L"Adler32 of first72descriptor bytes";
        break;
    case 0x60530009U:
        if(!xx_rt_wcscmp(r->name,L"palm_start_sector"))s=L"Sector number, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"smart_logs_distance"))s=L"Sector distance backwards from the end of media";
        else if(!xx_rt_wcscmp(r->name,L"error_granularity"))s=L"Error-block size in sectors";
        break;
    case 0x6053000aU:
        if(!xx_rt_wcscmp(r->name,L"chunk_count"))s=L"Commonly0 for logical evidence";
        else if(!xx_rt_wcscmp(r->name,L"logical_sector_value"))s=L"Logical-evidence field does not necessarily describe physical media sectors";
        else if(!xx_rt_wcscmp(r->name,L"palm_start_sector"))s=L"Sector number, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"smart_logs_distance"))s=L"Sector distance backwards from the end of media";
        else if(!xx_rt_wcscmp(r->name,L"error_granularity"))s=L"Error-block size in sectors";
        break;
    case 0x6053000cU:
        if(!xx_rt_wcscmp(r->name,L"base_offset"))s=L"Segment-relative base for encoded chunk offsets; older writers store0";
        break;
    case 0x6053000dU:
        if(!xx_rt_wcscmp(r->name,L"offset_and_compression"))s=L"Bit31 means compressed; low31bits are a byte offset relative to table base";
        break;
    case 0x60530011U:
        if(!xx_rt_wcscmp(r->name,L"adler32"))s=L"Header Adler32 with this field zeroed";
        break;
    case 0x60530013U:
        if(!xx_rt_wcscmp(r->name,L"previous_descriptor_offset"))s=L"Segment-relative descriptor byte offset;0 means first section";
        else if(!xx_rt_wcscmp(r->name,L"data_size"))s=L"Includes alignment padding preceding this descriptor";
        break;
    case 0x60530014U:
        if(!xx_rt_wcscmp(r->name,L"first_chunk_number"))s=L"Logical chunk index, not a byte offset";
        break;
    case 0x60530015U:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset from segment start";
        break;
    case 0x60530016U:
        if(!xx_rt_wcscmp(r->name,L"fill_pattern"))s=L"Physical repeated pattern bytes, not an offset";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Compressed and pattern-fill bits set";
        break;
    case 0x60530019U:
        if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"0means a complete final sector";
        break;
    case 0x6053001aU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"Counts bytes starting at offset8 of this header";
        break;
    case 0x6053001bU:
        if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"Logical sector index";
        break;
    case 0x6053001cU:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"blms counts from header offset8; blss from offset12; uncompressed data uses original_size";
        break;
    case 0x6053001fU:
        if(!xx_rt_wcscmp(r->name,L"encoded_data_offset"))s=L"Low24bits are byte offset; upper bits retain format flags";
        else if(!xx_rt_wcscmp(r->name,L"chunk_size_and_flags"))s=L"Low12bits count16KiB units; remaining bits encode table/codec/permutation flags";
        else if(!xx_rt_wcscmp(r->name,L"table_bit_widths"))s=L"Bits0..2 type width; bits3..7 encoded length width";
        break;
    case 0x60530020U:
        if(!xx_rt_wcscmp(r->name,L"size"))s=L"Includes this8-byte header";
        break;
    case 0x60530022U:
        if(!xx_rt_wcscmp(r->name,L"header_size_words"))s=L"Header length in4-byte words";
        else if(!xx_rt_wcscmp(r->name,L"block_size_log2"))s=L"log2 uncompressed block size in bytes";
        break;
    case 0x60530023U:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset from zisofs compressed-file start";
        break;
    case 0x60530025U:
        if(!xx_rt_wcscmp(r->name,L"crc32c"))s=L"CRC32C seeded0 without final inversion";
        break;
    case 0x60530027U:
        if(!xx_rt_wcscmp(r->name,L"type"))s=L"DATA19 consumes remainder of command without a stored length";
        break;
    case 0x6053002bU:
        if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Logical file-data byte offset, not an offset in the send-stream container";
        break;
    case 0x6053002fU:
        if(!xx_rt_wcscmp(r->name,L"seconds"))s=L"Unix seconds, signed64 representation";
        else if(!xx_rt_wcscmp(r->name,L"nanoseconds"))s=L"Fractional nanoseconds within the second";
        break;
    case 0x60530030U:
        if(!xx_rt_wcscmp(r->name,L"application"))s=L"UTF8 in AaruFormat version2";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Windows FILETIME100ns intervals since1601-01-01UTC";
        else if(!xx_rt_wcscmp(r->name,L"last_written_time"))s=L"Windows FILETIME100ns intervals since1601-01-01UTC";
        else if(!xx_rt_wcscmp(r->name,L"block_alignment_shift"))s=L"Byte alignment is2^shift";
        break;
    case 0x60530031U:
        if(!xx_rt_wcscmp(r->name,L"table_level"))s=L"Zero-based hierarchy level";
        else if(!xx_rt_wcscmp(r->name,L"blocks"))s=L"Logical sector span including negative and overflow sectors";
        else if(!xx_rt_wcscmp(r->name,L"start"))s=L"Logical starting sector index, not a physical byte offset";
        else if(!xx_rt_wcscmp(r->name,L"block_alignment_shift"))s=L"Physical block alignment is2^shift bytes";
        else if(!xx_rt_wcscmp(r->name,L"data_shift"))s=L"Low data_shift bits of a DDT entry contain its sector index within the data block";
        else if(!xx_rt_wcscmp(r->name,L"table_shift"))s=L"Logical sectors per primary entry are2^table_shift";
        break;
    case 0x60530032U:
        if(!xx_rt_wcscmp(r->name,L"encoded_location"))s=L"High4bits are status; lower60bits combine shifted aligned data-block index and within-block sector index";
        break;
    case 0x60530036U:
        if(!xx_rt_wcscmp(r->name,L"argument"))s=L"Segment-specific argument: page codec flags or scalar value";
        break;
    case 0x60530037U:
        if(!xx_rt_wcscmp(r->name,L"segment_size"))s=L"Includes16-byte header, name, payload and8-byte footer";
        break;
    case 0x60530038U:
        if(!xx_rt_wcscmp(r->name,L"low"))s=L"Low32bits of AFF quadword, stored big endian";
        else if(!xx_rt_wcscmp(r->name,L"high"))s=L"High32bits of AFF quadword, stored big endian";
        break;
    case 0x60530039U:
        if(!xx_rt_wcscmp(r->name,L"rpm"))s=L"Revolutions per minute";
        else if(!xx_rt_wcscmp(r->name,L"interleave"))s=L"Physical-sector interleave ratio";
        else if(!xx_rt_wcscmp(r->name,L"track_skew"))s=L"Sector displacement per track";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_skew"))s=L"Sector displacement per cylinder";
        else if(!xx_rt_wcscmp(r->name,L"drive_data"))s=L"Drive-specific stored words";
        else if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"XOR of label and declared partition-table16-bit words";
        break;
    case 0x6053003aU:
        if(!xx_rt_wcscmp(r->name,L"rpm"))s=L"Revolutions per minute";
        else if(!xx_rt_wcscmp(r->name,L"interleave"))s=L"Physical-sector interleave ratio";
        else if(!xx_rt_wcscmp(r->name,L"track_skew"))s=L"Sector displacement per track";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_skew"))s=L"Sector displacement per cylinder";
        else if(!xx_rt_wcscmp(r->name,L"drive_data"))s=L"Drive-specific stored words";
        else if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"XOR of label and declared partition-table16-bit words";
        break;
    case 0x6053003bU:
        if(!xx_rt_wcscmp(r->name,L"start_sector"))s=L"Sector number relative to disk start";
        break;
    case 0x6053003cU:
        if(!xx_rt_wcscmp(r->name,L"start_sector"))s=L"Sector number relative to disk start";
        break;
    case 0x6053003dU:
        if(!xx_rt_wcscmp(r->name,L"creation_time_encoded"))s=L"Low40bits Unix seconds; high24bits microseconds";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_offset"))s=L"Signed512-byte sector displacement from superblock; meaningful when feature bit0 is set";
        else if(!xx_rt_wcscmp(r->name,L"new_level"))s=L"Valid only during reshape";
        else if(!xx_rt_wcscmp(r->name,L"reshape_position"))s=L"Next logical array sector to reshape";
        else if(!xx_rt_wcscmp(r->name,L"new_data_offset"))s=L"Signed sector displacement added to data_offset during reshape";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Physical component start in512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"super_offset"))s=L"Physical superblock start in512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"recovery_or_journal_offset"))s=L"Feature-dependent logical sector position relative to data_offset";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_shift"))s=L"Bad-block unit is512 shifted by this value";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_log_offset"))s=L"Signed sector displacement from this superblock";
        else if(!xx_rt_wcscmp(r->name,L"update_time_encoded"))s=L"Low40bits Unix seconds; high24bits microseconds";
        else if(!xx_rt_wcscmp(r->name,L"resync_offset"))s=L"Synchronized logical sector count orUINT64_MAX sentinel";
        break;
    case 0x6053003eU:
        if(!xx_rt_wcscmp(r->name,L"creation_time_encoded"))s=L"Low40bits Unix seconds; high24bits microseconds";
        else if(!xx_rt_wcscmp(r->name,L"ppl_offset"))s=L"Signed512-byte sector displacement from superblock";
        else if(!xx_rt_wcscmp(r->name,L"new_level"))s=L"Valid only during reshape";
        else if(!xx_rt_wcscmp(r->name,L"reshape_position"))s=L"Next logical array sector to reshape";
        else if(!xx_rt_wcscmp(r->name,L"new_data_offset"))s=L"Signed sector displacement added to data_offset during reshape";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Physical component start in512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"super_offset"))s=L"Physical superblock start in512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"recovery_or_journal_offset"))s=L"Feature-dependent logical sector position relative to data_offset";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_shift"))s=L"Bad-block unit is512 shifted by this value";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_log_offset"))s=L"Signed sector displacement from this superblock";
        else if(!xx_rt_wcscmp(r->name,L"update_time_encoded"))s=L"Low40bits Unix seconds; high24bits microseconds";
        else if(!xx_rt_wcscmp(r->name,L"resync_offset"))s=L"Synchronized logical sector count orUINT64_MAX sentinel";
        break;
    case 0x6053003fU:
        if(!xx_rt_wcscmp(r->name,L"role"))s=L"Array role;0xFFFF spare,0xFFFE faulty,0xFFFD journal";
        break;
    case 0x60530040U:
        if(!xx_rt_wcscmp(r->name,L"valid_words"))s=L"Used32-bit words in constant section";
        else if(!xx_rt_wcscmp(r->name,L"level"))s=L"Signed RAID personality convention";
        else if(!xx_rt_wcscmp(r->name,L"component_kib"))s=L"Apparent member size in1024-byte units";
        else if(!xx_rt_wcscmp(r->name,L"events"))s=L"Stored as32-bit halves: low/high in little endian, high/low in big endian";
        else if(!xx_rt_wcscmp(r->name,L"checkpoint_events"))s=L"Stored as32-bit halves: low/high in little endian, high/low in big endian";
        else if(!xx_rt_wcscmp(r->name,L"recovery_checkpoint"))s=L"Sectors recovered";
        else if(!xx_rt_wcscmp(r->name,L"state_reserved"))s=L"Reshape extension is not defined for native-supported minor90";
        else if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"Logical volume root block number";
        break;
    case 0x60530041U:
        if(!xx_rt_wcscmp(r->name,L"valid_words"))s=L"Used32-bit words in constant section";
        else if(!xx_rt_wcscmp(r->name,L"level"))s=L"Signed RAID personality convention";
        else if(!xx_rt_wcscmp(r->name,L"component_kib"))s=L"Apparent member size in1024-byte units";
        else if(!xx_rt_wcscmp(r->name,L"events"))s=L"Stored as32-bit halves: low/high in little endian, high/low in big endian";
        else if(!xx_rt_wcscmp(r->name,L"checkpoint_events"))s=L"Stored as32-bit halves: low/high in little endian, high/low in big endian";
        else if(!xx_rt_wcscmp(r->name,L"recovery_checkpoint"))s=L"Sectors recovered";
        else if(!xx_rt_wcscmp(r->name,L"state_reserved"))s=L"Reshape extension is not defined for native-supported minor90";
        else if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"Logical volume root block number";
        break;
    case 0x60530044U:
        if(!xx_rt_wcscmp(r->name,L"partition_0_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_1_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_2_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_3_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_4_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_5_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_6_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"partition_7_start_cylinder"))s=L"Starting cylinder, not a byte offset";
        break;
    case 0x60530045U:
        if(!xx_rt_wcscmp(r->name,L"partition_0_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_1_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_2_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_3_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_4_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_5_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_6_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_7_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_8_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_9_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_10_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_11_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_12_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_13_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_14_start_sector"))s=L"Disk-relative512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"partition_15_start_sector"))s=L"Disk-relative512-byte sector number";
        break;
    case 0x60530046U:
        if(!xx_rt_wcscmp(r->name,L"format_word"))s=L"Native accepts1..16; detailed revision meaning is unverified";
        else if(!xx_rt_wcscmp(r->name,L"geometry_factor_0"))s=L"Product of the three geometry factors gives total_sectors; physical axis is unverified";
        else if(!xx_rt_wcscmp(r->name,L"geometry_factor_1"))s=L"Native bounds this factor to1..255; physical axis is unverified";
        else if(!xx_rt_wcscmp(r->name,L"geometry_factor_2"))s=L"Native bounds this factor to1..255; physical axis is unverified";
        break;
    case 0x60530047U:
        if(!xx_rt_wcscmp(r->name,L"session_count_copy"))s=L"Native supported producer duplicates session count here";
        break;
    case 0x60530048U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Signed logical sector position";
        else if(!xx_rt_wcscmp(r->name,L"end_lba"))s=L"Signed logical sector position";
        break;
    case 0x60530049U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Logical sector position in companion MDF image";
        else if(!xx_rt_wcscmp(r->name,L"mdf_offset"))s=L"Byte offset in the companion MDF, not in this MDS descriptor";
        break;
    case 0x6053004cU:
        if(!xx_rt_wcscmp(r->name,L"logical_disk_start"))s=L"512-byte sectors relative to the component image";
        else if(!xx_rt_wcscmp(r->name,L"configuration_start"))s=L"512-byte sectors relative to the component image";
        break;
    case 0x6053004dU:
        if(!xx_rt_wcscmp(r->name,L"configuration_start"))s=L"Sector index relative to configuration area";
        else if(!xx_rt_wcscmp(r->name,L"log_start"))s=L"Sector index relative to configuration area";
        break;
    case 0x6053004eU:
        if(!xx_rt_wcscmp(r->name,L"last_vblk_sequence"))s=L"Exclusive VBLK slot bound; multiplied by record size";
        else if(!xx_rt_wcscmp(r->name,L"vblk_offset"))s=L"Byte offset relative to this VMDB header";
        break;
    case 0x6053004fU:
        if(!xx_rt_wcscmp(r->name,L"fragment_number"))s=L"Zero-based fragment number within group";
        break;
    case 0x60530050U:
        if(!xx_rt_wcscmp(r->name,L"declared_length"))s=L"Type-specific static and variable widths; not an offset from VBLK magic";
        break;
    case 0x60530051U:
        if(!xx_rt_wcscmp(r->name,L"length"))s=L"Byte length of following field";
        break;
    case 0x60530052U:
        if(!xx_rt_wcscmp(r->name,L"descriptor_sector_le"))s=L"2048-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"descriptor_sector_be"))s=L"Big-endian copy of descriptor sector number";
        else if(!xx_rt_wcscmp(r->name,L"path_table_locations"))s=L"Encoded little/big-endian path-table block locations; not followed by this provider";
        break;
    case 0x60530053U:
        if(!xx_rt_wcscmp(r->name,L"descriptor_sector_le"))s=L"2048-byte sector number";
        break;
    case 0x60530054U:
        if(!xx_rt_wcscmp(r->name,L"extent_block_le"))s=L"Logical block index relative to the volume";
        break;
    case 0x60530055U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Decimal YYYYMMDDhhmmsscc; no timezone byte in High Sierra";
        break;
    case 0x60530056U:
        if(!xx_rt_wcscmp(r->name,L"descriptor_offset"))s=L"Offset from beginning of CDI file";
        break;
    case 0x60530057U:
        if(!xx_rt_wcscmp(r->name,L"descriptor_distance"))s=L"Distance backwards from end of CDI file to descriptor";
        break;
    case 0x6053005bU:
        if(!xx_rt_wcscmp(r->name,L"sectors"))s=L"Sector count for this index; first entry is pregap";
        break;
    case 0x6053005dU:
        if(!xx_rt_wcscmp(r->name,L"session_index"))s=L"Zero-based session number";
        else if(!xx_rt_wcscmp(r->name,L"track_index"))s=L"Zero-based track number";
        else if(!xx_rt_wcscmp(r->name,L"start_sector"))s=L"Logical sector position on the disc";
        else if(!xx_rt_wcscmp(r->name,L"read_mode"))s=L"0=2048bytes;1=2336bytes;2=2352bytes per stored sector";
        break;
    case 0x6053005eU:
        if(!xx_rt_wcscmp(r->name,L"volume_number"))s=L"Zero-based split volume number";
        break;
    case 0x6053005fU:
        if(!xx_rt_wcscmp(r->name,L"month"))s=L"Zero-based month as in struct tm";
        else if(!xx_rt_wcscmp(r->name,L"year"))s=L"Years since1900";
        else if(!xx_rt_wcscmp(r->name,L"timezone_offset"))s=L"Legacy portable_tm word; signed offset representation can be encoded in these32bits";
        else if(!xx_rt_wcscmp(r->name,L"timezone_word"))s=L"Legacy stored timezone word; not a portable pointer";
        break;
    case 0x60530061U:
        if(!xx_rt_wcscmp(r->name,L"additive_checksum"))s=L"Sum of signed8-bit header bytes modulo2^32";
        break;
    case 0x60530063U:
        if(!xx_rt_wcscmp(r->name,L"block_position"))s=L"Original partition block index at this checkpoint";
        break;
    case 0x60530064U:
        if(!xx_rt_wcscmp(r->name,L"additive_checksum"))s=L"Unsigned byte sum through MAGIC-BEGIN-TAIL";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed volume base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXVI_LIMIT 24000U
static bool sxvi_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxvi_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxvi_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxvi16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
static uint32_t sxvi32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxvi16(b,0)<<16|sxvi16(b+2,0);return o==1?(uint32_t)sxvi16(b,1)<<16|sxvi16(b+2,1):(uint32_t)sxvi16(b+2,0)<<16|sxvi16(b,0);}
static uint64_t sxvi64(const uint8_t*b,unsigned o){return o==1?(uint64_t)sxvi32(b,1)<<32|sxvi32(b+4,1):(uint64_t)sxvi32(b+4,0)<<32|sxvi32(b,0);}
static bool sxvi_pow(uint64_t v){return v&&!(v&(v-1));}
static bool sxvi_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxvi_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXVI_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
#define SXVI_TABLE(c,l,p,n) sxvi_put(c,&sxvi_##l,p,n)
#define SXVI_ORDER(l,o) ((o)==1?&sxvi_##l##_be:&sxvi_##l##_le)
static uint32_t sxvi_adler(const uint8_t*p,size_t n){uint32_t a=1,b=0;while(n--){a=(a+*p++)%65521U;b=(b+a)%65521U;}return b<<16|a;}
static bool sxvi_magic(sx_context*c,uint64_t p,const char*s,size_t n){uint8_t b[32];return n<=sizeof(b)&&sxvi_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static bool sxvi_aff(sx_context*c){
 if(!sxvi_magic(c,0,"AFF10\r\n\0",8))return false;
 uint64_t p=8;uint8_t h[16],name[128];
 for(unsigned count=0;count<262144&&p<(uint64_t)c->size&&c->count<SXVI_LIMIT;count++){
  if(!sxvi_read(c,p,h,16)||xx_rt_memcmp(h,"AFF\0",4))break;uint64_t n=sxvi32(h+4,1),z=sxvi32(h+8,1);
  if(n>=128||!sxvi_span(c,p+16,n)||z>(uint64_t)c->size-p-16-n||!sxvi_span(c,p+16+n+z,8))break;
  uint64_t tail=p+16+n+z;uint8_t f[8];if(!sxvi_read(c,tail,f,8)||xx_rt_memcmp(f,"ATT\0",4)||sxvi32(f+4,1)!=24+n+z)break;
  if(!SXVI_ADD(c,aff_segment_header,p)||!SXVI_ADD(c,aff_segment_footer,tail))return false;
  if(n&&sxvi_read(c,p+16,name,(size_t)n)&&n==9&&!xx_rt_memcmp(name,"imagesize",9)&&z==8&&sxvi32(h+12,1)==2&&!SXVI_ADD(c,aff_quadword,p+16+n))return false;
  p=tail+8;
 }return c->count!=0;
}
static bool sxvi_bsd(sx_context*c){uint8_t h[148],b[1024];uint64_t limit=(uint64_t)c->size<8192?(uint64_t)c->size:8192;
 for(uint64_t p=0;p+148<=limit;p+=4){if(!sxvi_read(c,p,h,4))return false;unsigned o=sxvi32(h,0)==0x82564557U?0:sxvi32(h,1)==0x82564557U?1:2;if(o==2||!sxvi_read(c,p,h,148)||sxvi32(h+132,o)!=0x82564557U)continue;unsigned n=sxvi16(h+138,o);uint64_t bs=sxvi32(h+40,o),sectors=sxvi32(h+60,o);if(!n||n>64||!sxvi_pow(bs)||bs<128||bs>65536||!sectors||sectors>(uint64_t)c->size/bs||!sxvi_read(c,p+148,b,n*16))continue;uint16_t sum=0;for(unsigned j=0;j<148;j+=2)sum^=sxvi16(h+j,o);for(unsigned j=0;j<n*16;j+=2)sum^=sxvi16(b+j,o);if(sum)continue;
  return sxvi_put(c,SXVI_ORDER(bsd_disklabel,o),p,1)&&sxvi_put(c,SXVI_ORDER(bsd_partition,o),p+148,n);
 }return false;
}
static bool sxvi_sun(sx_context*c){uint8_t b[512];for(unsigned i=0;i<2;i++){uint64_t p=i*512;if(!sxvi_read(c,p,b,512)||sxvi16(b+508,i?0:1)!=0xdabe)continue;uint16_t sum=0;for(unsigned k=0;k<512;k+=2)sum^=sxvi16(b+k,1);if(sum)continue;if(!i){if(!sxvi16(b+436,1)||!sxvi16(b+438,1))continue;return SXVI_ADD(c,sun_sparc_label,p);}if(sxvi32(b+12,0)!=0x600ddeeeU||sxvi32(b+16,0)!=1||sxvi16(b+28,0)!=512||sxvi16(b+30,0)>16)continue;return SXVI_ADD(c,sun_x86_label,p);}return false;}
static bool sxvi_md(sx_context*c){uint8_t b[256];uint64_t sectors=(uint64_t)c->size/512,at[3]={0,4096,UINT64_MAX};if(sectors>=16)at[2]=((sectors-16)&~UINT64_C(7))*512;
 for(unsigned i=0;i<3;i++){if(at[i]==UINT64_MAX||!sxvi_read(c,at[i],b,256)||sxvi32(b,0)!=0xa92b4efcU||sxvi32(b+4,0)!=1)continue;uint64_t n=sxvi32(b+220,0);if(!n||n>3840||sxvi64(b+144,0)!=at[i]/512||!sxvi_span(c,at[i]+256,n*2))continue;return sxvi_put(c,(sxvi32(b+8,0)&1024)?&sxvi_md1_superblock_ppl:&sxvi_md1_superblock,at[i],1)&&SXVI_TABLE(c,md1_device_role,at[i]+256,n);}
 if(c->size<131072)return false;uint64_t p=((uint64_t)c->size&~UINT64_C(65535))-65536;if(!sxvi_read(c,p,b,16)||!sxvi_span(c,p,4096))return false;unsigned o=sxvi32(b,0)==0xa92b4efcU?0:sxvi32(b,1)==0xa92b4efcU?1:2;if(o==2||sxvi32(b+4,o)||sxvi32(b+8,o)!=90)return false;
 return sxvi_put(c,SXVI_ORDER(md090_header,o),p,1)&&sxvi_put(c,SXVI_ORDER(md090_disk,o),p+512,27)&&sxvi_put(c,SXVI_ORDER(md090_disk,o),p+3968,1);
}
static bool sxvi_lvm(sx_context*c){uint8_t h[512],b[512];uint64_t label=UINT64_MAX,pv=0;
 for(unsigned i=0;i<4;i++)if(sxvi_read(c,i*512,h,512)&&!xx_rt_memcmp(h,"LABELONE",8)&&!xx_rt_memcmp(h+24,"LVM2 001",8)&&sxvi64(h+8,0)==i){label=i*512;pv=sxvi32(h+20,0);break;}
 if(label==UINT64_MAX||pv<32||pv>440||!SXVI_ADD(c,lvm2_label_header,label)||!SXVI_ADD(c,lvm2_pv_header,label+pv))return false;
 uint64_t pos=pv+40,metas[28];size_t count=0;for(unsigned list=0;list<2;list++){bool end=false;while(pos+16<=512){uint64_t off=sxvi64(h+pos,0),z=sxvi64(h+pos+8,0);if(!SXVI_ADD(c,lvm2_disk_location,label+pos))return false;pos+=16;if(!off&&!z){end=true;break;}if(list&&count<SX_COUNT(metas)&&z>=512&&sxvi_span(c,off,z))metas[count++]=off;}if(!end)return true;}
 if(pos+8<=512&&sxvi32(h+pos,0)&&sxvi32(h+pos,0)<=2){if(!SXVI_ADD(c,lvm2_pv_extension,label+pos))return false;pos+=8;/* Version1 introduces the bootloader-area list; version2 adds PV_EXT_USED. */while(pos+16<=512){uint64_t off=sxvi64(h+pos,0),z=sxvi64(h+pos+8,0);if(!SXVI_ADD(c,lvm2_disk_location,label+pos))return false;pos+=16;if(!off&&!z)break;}}
 for(size_t i=0;i<count;i++){uint64_t p=metas[i];if(!sxvi_read(c,p,b,512)||xx_rt_memcmp(b+4," LVM2 x[5A%r0N*>",16)||sxvi32(b+20,0)!=1)continue;if(!SXVI_ADD(c,lvm2_mda_header,p))return false;for(unsigned q=40;q+24<=512;q+=24){if(!SXVI_ADD(c,lvm2_raw_location,p+q))return false;if(!sxvi64(b+q,0))break;}}
 return true;
}
static bool sxvi_ldm(sx_context*c){uint8_t h[512],b[32];if(!sxvi_read(c,3072,h,512)||xx_rt_memcmp(h,"PRIVHEAD",8)||sxvi16(h+12,1)!=2||!SXVI_ADD(c,ldm_private_header,3072))return false;uint64_t config=sxvi64(h+299,1),n=sxvi64(h+307,1);if(config>(uint64_t)c->size/512||n<32||n>32768||n>(uint64_t)c->size/512-config)return true;uint64_t base=config*512;
 const unsigned toc[]={1,2,2045,2046},ph[]={1856,2047};for(unsigned i=0;i<SX_COUNT(ph);i++)if(ph[i]<n&&sxvi_magic(c,base+ph[i]*512,"PRIVHEAD",8)&&!SXVI_ADD(c,ldm_private_header,base+ph[i]*512))return false;
 for(unsigned i=0;i<SX_COUNT(toc);i++)if(toc[i]<n&&sxvi_magic(c,base+toc[i]*512,"TOCBLOCK",8)&&!SXVI_ADD(c,ldm_tocblock,base+toc[i]*512))return false;
 uint64_t p=base+17*512;if(!sxvi_read(c,p,b,22)||xx_rt_memcmp(b,"VMDB",4)||!SXVI_ADD(c,ldm_vmdb_header,p))return true;uint64_t last=sxvi32(b+4,1),z=sxvi32(b+8,1),start=sxvi32(b+12,1);if(z<32||z>4096||!sxvi_pow(z)||start<512||start%z||last>(n-17)*512/z||start>last*z)return true;
 for(uint64_t q=start;q<last*z&&c->count<SXVI_LIMIT;q+=z){if(!sxvi_read(c,p+q,b,24)||xx_rt_memcmp(b,"VBLK",4))break;if(!SXVI_ADD(c,ldm_vblk_fragment,p+q))return false;if(sxvi16(b+12,1)==0&&sxvi16(b+14,1)){if(!SXVI_ADD(c,ldm_vblk_record_header,p+q+16))return false;/* Only unfragmented common ID/name length bytes have direct coordinates. */if(sxvi16(b+14,1)==1){uint64_t v=24;for(unsigned k=0;k<2;k++){uint8_t len;if(v>=z||!sxvi_read(c,p+q+v,&len,1)||len>z-v-1)break;if(!SXVI_ADD(c,ldm_variable_length,p+q+v))return false;v+=1+len;}}}}
 return true;
}
static bool sxvi_next(sx_context*c){uint8_t b[46];if(!sxvi_read(c,0,b,46)||!sxvi32(b,1)||sxvi32(b,1)>16||sxvi16(b+4,1)!=512||sxvi16(b+34,1)!=512||sxvi32(b+30,1)!=512||sxvi32(b+26,1)!=1)return false;uint64_t a=sxvi32(b+6,1),d=sxvi32(b+10,1),e=sxvi32(b+36,1);if(!a||a>65535||!d||d>255||!e||e>255||a*d*e!=sxvi32(b+42,1)||a*d*e*512!=sxvi32(b+22,1)||!sxvi_span(c,46,a*d*e*512))return false;return SXVI_ADD(c,nextstep_container_header,0);}
static bool sxvi_zisofs(sx_context*c){uint8_t b[16];static const uint8_t magic[]={0x37,0xe4,0x53,0x96,0xc9,0xdb,0xd6,0x07};if(!sxvi_read(c,0,b,16)||xx_rt_memcmp(b,magic,8)||b[12]<4||b[13]<9||b[13]>30||!SXVI_ADD(c,zisofs_header,0))return false;uint64_t bs=UINT64_C(1)<<b[13],size=sxvi32(b+8,0),n=(size+bs-1)/bs+1,p=(uint64_t)b[12]*4;if(n>1048576||!sxvi_span(c,p,n*4))return true;return SXVI_TABLE(c,zisofs_block_pointer,p,n);}
static bool sxvi_mds(sx_context*c){uint8_t h[88],b[24];if(!sxvi_read(c,0,h,88)||xx_rt_memcmp(h,"MEDIA DESCRIPTOR",16)||h[16]!=1||h[17]!=4||!SXVI_ADD(c,mds_header,0))return false;uint64_t sessions=sxvi16(h+20,0),base=sxvi32(h+80,0),blocks=0;if(!sessions||sessions>32||!sxvi_span(c,base,sessions*24))return true;if(!SXVI_TABLE(c,mds_session,base,sessions))return false;for(uint64_t i=0;i<sessions;i++){if(!sxvi_read(c,base+i*24,b,24))return false;uint64_t p=sxvi32(b+20,0),n=b[10];if(!sxvi_span(c,p,n*80))continue;if(!SXVI_TABLE(c,mds_track,p,n))return false;blocks+=n;for(uint64_t j=0;j<n;j++){uint8_t t[56];if(!sxvi_read(c,p+j*80,t,56))return false;uint64_t footer=sxvi32(t+52,0);if(footer&&sxvi_span(c,footer,16)&&!SXVI_ADD(c,mds_footer,footer))return false;}}
 /* Native-supported producer stores an extra descriptor for every block,
  * including TOC lead-in/out blocks whose pointer is zero. */
 uint64_t extra=base+sessions*24+blocks*80;if(sxvi_span(c,extra,blocks*8)&&!SXVI_TABLE(c,mds_track_extra,extra,blocks))return false;return true;
}
static bool sxvi_aaru(sx_context*c){uint8_t h[147],b[85];if(!sxvi_read(c,0,h,147)||xx_rt_memcmp(h,"AARUFRMT",8)||h[72]!=2||!SXVI_ADD(c,aaru2_header,0))return false;uint64_t p=sxvi64(h+80,0);if(!sxvi_read(c,p,b,28)||sxvi32(b,0)!=0x33584449U)return true;uint64_t n=sxvi64(b+4,0);if(n>1048576||!sxvi_span(c,p+28,n*14))return true;if(!SXVI_ADD(c,aaru_index3,p)||!SXVI_TABLE(c,aaru_index_entry,p+28,n))return false;
 for(uint64_t i=0;i<n&&c->count<SXVI_LIMIT;i++){uint8_t e[14];if(!sxvi_read(c,p+28+i*14,e,14))return false;uint64_t at=sxvi64(e+6,0);uint32_t type=sxvi32(e,0);if(type==0x4b4c4244U){if(sxvi_read(c,at,b,36)&&sxvi32(b,0)==type&&!SXVI_ADD(c,aaru_data_header,at))return false;}else if(type==0x32544444U&&sxvi_read(c,at,b,85)&&sxvi32(b,0)==type){if(!SXVI_ADD(c,aaru2_ddt_header,at))return false;uint64_t count=sxvi64(b+45,0),len=sxvi64(b+61,0);if(!sxvi16(b+6,0)&&count<=1048576&&count*8==len&&sxvi_span(c,at+85,len)&&!SXVI_TABLE(c,aaru2_ddt_entry,at+85,count))return false;}}
 return true;
}
static bool sxvi_ewf1(sx_context*c){uint8_t h[76],b[32];uint64_t base=0,p=13;bool logical=c->f->file_type==XX_FILE_TYPE_EWF_L01;
 if(!sxvi_read(c,0,h,13)||((h[0]!='E'&&h[0]!='L')||h[1]!='V'||h[2]!='F')||h[8]!=1||!SXVI_ADD(c,ewf1_file_header,0))return false;
 for(unsigned visited=0;visited<1048576&&c->count<SXVI_LIMIT;visited++){
  if(!sxvi_read(c,p,h,76)||sxvi_adler(h,72)!=sxvi32(h+72,0))break;uint64_t rel=sxvi64(h+16,0),z=sxvi64(h+24,0);if(!SXVI_ADD(c,ewf1_section_descriptor,p))return false;
  if(!xx_rt_memcmp(h,"done\0",5))break;if(!xx_rt_memcmp(h,"next\0",5)){base=p+76;if(!sxvi_read(c,base,b,13)||b[0]!=(logical?'L':'E')||b[1]!='V'||b[2]!='F')break;/* Signature check below is independent of the overwritten descriptor. */if(b[8]!=1||!SXVI_ADD(c,ewf1_file_header,base))return false;p=base+13;continue;}
  if(rel>(uint64_t)c->size-base)break;uint64_t next=base+rel;if(next<=p||next-p<76)break;if(!z)z=next-p;if(z<76||z>next-p)break;uint64_t data=p+76,bytes=z-76;
  if(!xx_rt_memcmp(h,"volume\0",7)||!xx_rt_memcmp(h,"disk\0",5)||!xx_rt_memcmp(h,"data\0",5)){
   if(bytes>=1052){if(!sxvi_put(c,logical?&sxvi_ewf1_logical_volume:&sxvi_ewf1_volume,data,1))return false;}else if(!logical&&bytes==94&&!SXVI_ADD(c,ewf1_smart_volume,data))return false;
  }else if(!xx_rt_memcmp(h,"table\0",6)||!xx_rt_memcmp(h,"table2\0",7)){
   if(bytes>=24&&sxvi_read(c,data,b,24)){uint64_t n=sxvi32(b,0);if(n<=1048576&&n<=(bytes-24)/4){if(!SXVI_ADD(c,ewf1_table_header,data)||!SXVI_TABLE(c,ewf1_chunk_entry,data+24,n))return false;if(bytes-24-n*4>=4&&!SXVI_ADD(c,image_adler32,data+24+n*4))return false;}}
  }else if(!xx_rt_memcmp(h,"hash\0",5)&&bytes>=36){if(!SXVI_ADD(c,ewf1_hash,data))return false;}
  else if(!xx_rt_memcmp(h,"digest\0",7)&&bytes>=80){if(!SXVI_ADD(c,ewf1_digest,data))return false;}
  else if(!xx_rt_memcmp(h,"ltree\0",6)&&bytes>=48){if(!SXVI_ADD(c,ewf1_ltree_header,data))return false;}
  p=next;
 }return true;
}
static bool sxvi_ewf2_descriptor(sx_context*c,uint64_t p,uint8_t b[64]){if(!sxvi_read(c,p,b,64)||sxvi32(b+24,0)!=64||sxvi_adler(b,60)!=sxvi32(b+60,0))return false;uint64_t prev=sxvi64(b+8,0),n=sxvi64(b+16,0);uint32_t type=sxvi32(b,0);if(!type||type>65535||p<32||prev>=p||(prev&&(prev<32||p-prev<64)))return false;uint64_t start=prev?prev+64:32;return start<=p&&n<=p-start&&sxvi32(b+28,0)<=n;}
static bool sxvi_ewf2_row(sx_context*c,uint64_t p,const uint8_t b[64]){uint64_t prev=sxvi64(b+8,0),data=prev?prev+64:32,n=sxvi64(b+16,0);/* Padding may be internal to table headers: bound physical rows by full data_size. */uint32_t type=sxvi32(b,0);if(!SXVI_ADD(c,ewf2_section_descriptor,p))return false;if(sxvi32(b+4,0)&2)return true;uint8_t h[32];
 if(type==4&&n>=32&&sxvi_read(c,data,h,32)){uint64_t count=sxvi32(h+8,0);if(count>1048576||count>(n-32)/16)return true;if(!SXVI_ADD(c,ewf2_table_header,data))return false;for(uint64_t i=0;i<count&&c->count<SXVI_LIMIT;i++){uint8_t e[16];if(!sxvi_read(c,data+32+i*16,e,16))return false;uint32_t f=sxvi32(e+12,0);if(!sxvi_put(c,(f&5)==5?&sxvi_ewf2_pattern_entry:&sxvi_ewf2_chunk_entry,data+32+i*16,1))return false;}if(n-32-count*16>=4&&!SXVI_ADD(c,image_adler32,data+32+count*16))return false;}
 else if(type==8&&n>=20){if(!SXVI_ADD(c,ewf2_md5,data))return false;}else if(type==9&&n>=24){if(!SXVI_ADD(c,ewf2_sha1,data))return false;}return true;
}
static bool sxvi_ewf2(sx_context*c){uint8_t h[64];if(!sxvi_read(c,0,h,32)||((c->f->file_type==XX_FILE_TYPE_EWF2_LX01)?xx_rt_memcmp(h,"LEF2",4):xx_rt_memcmp(h,"EVF2",4))||!SXVI_ADD(c,ewf2_file_header,0))return false;
 uint64_t end=(uint64_t)c->size;if(end>=96&&sxvi_ewf2_descriptor(c,end-64,h)&&(sxvi32(h,0)==13||sxvi32(h,0)==15)){
  uint64_t p=end-64;for(unsigned i=0;i<1048576&&c->count<SXVI_LIMIT;i++){if(!sxvi_ewf2_row(c,p,h))return false;uint64_t prev=sxvi64(h+8,0);if(!prev)break;p=prev;if(!sxvi_ewf2_descriptor(c,p,h))break;}return true;
 }
 /* Padded/truncated native-valid segments use aligned authenticated descriptors.
  * Search at most64MiB of physical metadata; omitted suffix remains raw. */
 uint64_t prev=0,limit=end<UINT64_C(67108864)?end:UINT64_C(67108864);for(uint64_t p=32;p+64<=limit&&c->count<SXVI_LIMIT;p+=16){if(!sxvi_ewf2_descriptor(c,p,h)||sxvi64(h+8,0)!=prev)continue;if(!sxvi_ewf2_row(c,p,h))return false;prev=p;if(sxvi32(h,0)==13||sxvi32(h,0)==15)break;p+=48;}return true;
}
static bool sxvi_uif(sx_context*c){uint8_t t[64],h[20];if(c->size<80)return false;uint64_t end=(uint64_t)c->size-64;if(!sxvi_read(c,end,t,64)||xx_rt_memcmp(t,"bbis",4)||!SXVI_ADD(c,uif_trailer,end))return false;uint64_t p=sxvi64(t+28,0);if(p>end||end-p<16||!sxvi_read(c,p,h,16))return true;if(xx_rt_memcmp(h,"blhr",4)&&xx_rt_memcmp(h,"bsdr",4))return true;if(!SXVI_ADD(c,uif_table_header,p))return false;
 bool encrypted=!xx_rt_memcmp(h,"bsdr",4)||t[57]==2||(sxvi16(t+8,0)>1&&t[56]&&t[56]<=16);if(encrypted)return true;uint64_t count=sxvi32(h+12,0),stored;if(sxvi32(h+8,0)){if(sxvi32(h+4,0)<8)return true;stored=sxvi32(h+4,0)-8;}else{stored=count*24;if(count<=1048576&&stored<=end-p-16&&!SXVI_TABLE(c,uif_block_entry,p+16,count))return false;}if(stored>end-p-16||sxvi16(t+10,0)!=9)return true;p+=16+stored;
 if(p>end||end-p<16||!sxvi_read(c,p,h,16)||xx_rt_memcmp(h,"blms",4))return true;if(!SXVI_ADD(c,uif_descriptor_header,p))return false;if(sxvi32(h+8,0)){if(sxvi32(h+4,0)<8)return true;stored=sxvi32(h+4,0)-8;}else stored=sxvi32(h+12,0);if(stored>end-p-16)return true;p+=16+stored;
 if(p>end||end-p<20||!sxvi_read(c,p,h,20)||xx_rt_memcmp(h,"blss",4))return true;return SXVI_ADD(c,uif_descriptor_header,p)&&SXVI_ADD(c,uif_output_format,p+16);
}
static bool sxvi_gbi(sx_context*c){uint8_t h[76],b[12];if(!sxvi_read(c,0,h,76)||xx_rt_memcmp(h,"GBI\0",4))return false;uint32_t v=sxvi32(h+20,0);if(v!=0x100&&v!=0x110)return false;if(!sxvi_put(c,v==0x100?&sxvi_gbi_header100:&sxvi_gbi_header110,0,1))return false;uint64_t end=sxvi32(h+16,0);if(end<76||end>(uint64_t)c->size)return true;
 for(uint64_t p=76;p+8<=end&&c->count<SXVI_LIMIT;){if(!sxvi_read(c,p,b,8))return false;uint64_t z=sxvi32(b+4,0);if(z<8||z>end-p)break;if(!SXVI_ADD(c,gbi_descriptor,p))return false;if(sxvi32(b,0)==2&&z>=16&&!SXVI_ADD(c,gbi_part_count,p+8))return false;p+=z;}return true;
}
static bool sxvi_btrfs(sx_context*c){uint8_t h[17],b[10];if(!sxvi_read(c,0,h,17)||xx_rt_memcmp(h,"btrfs-stream\0",13)||sxvi32(h+13,0)<1||sxvi32(h+13,0)>3||!SXVI_ADD(c,btrfs_send_header,0))return false;unsigned version=sxvi32(h+13,0);
 for(uint64_t p=17;p+10<=(uint64_t)c->size&&c->count<SXVI_LIMIT;){if(!sxvi_read(c,p,b,10))return false;uint64_t n=sxvi32(b,0);if(n>1048576||!sxvi_span(c,p+10,n))break;if(!SXVI_ADD(c,btrfs_send_command,p))return false;uint64_t end=p+10+n,q=p+10;
  while(q+2<=end&&c->count<SXVI_LIMIT){uint8_t a[4];if(!sxvi_read(c,q,a,2))return false;unsigned type=sxvi16(a,0);if(version>=2&&type==19){if(!SXVI_ADD(c,btrfs_send_data_attribute_v2,q))return false;break;}if(end-q<4||!sxvi_read(c,q,a,4))break;uint64_t z=sxvi16(a+2,0);if(z>end-q-4)break;if(!SXVI_ADD(c,btrfs_send_attribute,q))return false;q+=4;const sx_layout*l=NULL;
   if((type==1||type==20)&&z==16)l=&sxvi_btrfs_send_uuid;
   else if(type>=9&&type<=12&&z==12)l=&sxvi_btrfs_send_timespec;
   else if(z==8){if(type==4||type==24||type==27||type==28)l=&sxvi_btrfs_send_size64;else if(type==18||type==23||type==29)l=&sxvi_btrfs_send_offset64;else if(type==5||type==26)l=&sxvi_btrfs_send_flags64;else if(type==2||type==3||type==6||type==7||type==8||type==21)l=&sxvi_btrfs_send_id64;}
   else if(z==4){if(type==25)l=&sxvi_btrfs_send_flags32;else if(type==30||type==31)l=&sxvi_btrfs_send_codec32;}
   if(l&&!sxvi_put(c,l,q,1))return false;q+=z;
  }p=end;
 }return true;
}
typedef struct sxvi_directory{uint64_t p,size;unsigned depth;}sxvi_directory;
static bool sxvi_hsf(sx_context*c){uint8_t h[2048];uint64_t bs=0,blocks=0,root=0,rootsize=0;bool found=false;
 for(unsigned i=16;i<80;i++){uint64_t p=(uint64_t)i*2048;if(!sxvi_read(c,p,h,2048)||xx_rt_memcmp(h+9,"CDROM",5)||h[14]!=1||sxvi32(h,0)!=i||sxvi32(h+4,1)!=i)break;
  if(h[8]==1){if(!SXVI_ADD(c,hsf_volume_prefix,p)||!SXVI_ADD(c,hsf_directory_record,p+180)||!SXVI_ADD(c,hsf_volume_identifiers,p+214))return false;if(!found){bs=sxvi16(h+136,0);blocks=sxvi32(h+88,0);root=(uint64_t)sxvi32(h+182,0)+h[181];rootsize=sxvi32(h+190,0);found=true;}}
  else if(!SXVI_ADD(c,hsf_descriptor_header,p))return false;if(h[8]==255)break;
 }
 if(!found)return false;if((bs!=512&&bs!=1024&&bs!=2048)||!blocks||blocks>(uint64_t)c->size/bs||root>=blocks||rootsize>(blocks-root)*bs)return true;
 sxvi_directory*q=xx_rt_calloc(4096,sizeof(*q));if(!q)return false;size_t count=1,index=0;uint64_t walked=0;bool ok=true;q[0]=(sxvi_directory){root*bs,rootsize,0};
 while(ok&&index<count&&c->count<SXVI_LIMIT){sxvi_directory d=q[index++];if(d.depth>32||d.size>UINT64_C(16777216)||walked>UINT64_C(67108864)-d.size||!sxvi_span(c,d.p,d.size))continue;walked+=d.size;
  for(uint64_t pos=0;pos<d.size&&ok&&c->count<SXVI_LIMIT;pos+=bs){uint64_t n=d.size-pos;if(n>bs)n=bs;if(!sxvi_read(c,d.p+pos,h,(size_t)n))break;
   for(uint64_t at=0;at+33<=n;){unsigned z=h[at],len=h[at+32];if(!z)break;if(z<33||z>n-at||!len||len>z-33)break;if(!SXVI_ADD(c,hsf_directory_record,d.p+pos+at)){ok=false;break;}uint64_t block=sxvi32(h+at+2,0),size=sxvi32(h+at+10,0);bool child=(h[at+24]&2)&&!(len==1&&(h[at+33]==0||h[at+33]==1));
    if(child&&count<4096&&block==sxvi32(h+at+6,1)&&size==sxvi32(h+at+14,1)){block+=h[at+1];if(block<blocks&&size<=(blocks-block)*bs){bool seen=false;for(size_t k=0;k<count;k++)if(q[k].p==block*bs)seen=true;if(!seen)q[count++]=(sxvi_directory){block*bs,size,d.depth+1};}}
    at+=z;
   }
  }
 }xx_rt_free(q);return ok;
}
static bool sxvi_cdi(sx_context*c){uint8_t f[8];if(c->size<16||!sxvi_read(c,(uint64_t)c->size-8,f,8))return false;uint32_t version=sxvi32(f,0);uint64_t off=sxvi32(f+4,0),end=(uint64_t)c->size-8;if(version<0x80000004U||version>0x80000006U)return false;uint64_t p=version==0x80000006U?(off<=(uint64_t)c->size?(uint64_t)c->size-off:UINT64_MAX):off;if(p>=end||end-p<2||end-p>UINT64_C(16777216))return false;if(!sxvi_put(c,version==0x80000006U?&sxvi_cdi_footer_v35:&sxvi_cdi_footer_v2,end,1)||!SXVI_ADD(c,cdi_descriptor_header,p))return false;
 size_t n=(size_t)(end-p);uint8_t*h=xx_rt_malloc(n);if(!h)return false;if(!sxvi_read(c,p,h,n)){xx_rt_free(h);return false;}static const uint8_t mark[10]={0,0,1,0,0,0,255,255,255,255};bool ok=true;unsigned sessions=sxvi16(h,0);
 for(uint64_t at=2;at+25<=n&&c->count<SXVI_LIMIT;at++){if(xx_rt_memcmp(h+at,mark,10)||xx_rt_memcmp(h+at+10,mark,10))continue;uint64_t names=h[at+24],ic=at+56+names;if(ic>n||n-ic<2)continue;unsigned indices=sxvi16(h+ic,0);if(indices>64||indices*4U>n-ic-2)continue;uint64_t tc=ic+2+indices*4;if(n-tc<4)continue;uint64_t text=sxvi32(h+tc,0);if(text>4096||text*18>n-tc-4)continue;uint64_t fixed=tc+4+text*18;if(n-fixed<46||h[fixed+2]>2||sxvi32(h+fixed+42,0)>2||sxvi32(h+fixed+10,0)>=sessions||sxvi32(h+fixed+14,0)>999)continue;
  if(!SXVI_ADD(c,cdi_track_prefix,p+at)||!SXVI_ADD(c,cdi_index_count,p+ic)||!SXVI_TABLE(c,cdi_index,p+ic+2,indices)||!SXVI_ADD(c,cdi_cdtext_count,p+tc)||!SXVI_ADD(c,cdi_track_geometry,p+fixed)){ok=false;break;}at+=19;
 }xx_rt_free(h);return ok;
}
static bool sxvi_pi_marker(sx_context*c,uint64_t*p,const char*str){size_t n=xx_rt_strlen(str);if(!sxvi_magic(c,*p,str,n))return false;*p+=n;return true;}
static bool sxvi_partimage(sx_context*c){uint8_t b[40];uint64_t p=512;if(!sxvi_magic(c,0,"PaRtImAgE-VoLuMe\0",16)||!sxvi_magic(c,32,"0.6.1\0",6)||!sxvi_magic(c,512+9728,"0.6.1\0",6)||!SXVI_ADD(c,partimage_volume_header,0)||!SXVI_ADD(c,partimage_main_header,p)||!SXVI_ADD(c,partimage_header_checksum,p+16384))return false;p+=16388;
 if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-MBRBACKUP"))return true;for(unsigned i=0;i<10;i++){char magic[32];xx_rt_snprintf(magic,sizeof(magic),"MAGIC-BEGIN-EXT%03u",i);if(!sxvi_magic(c,p,magic,18)||!sxvi_read(c,p+18,b,4))return true;uint64_t n=sxvi32(b,0);if(!SXVI_ADD(c,partimage_extension_header,p)||!sxvi_span(c,p+22,n))return false;p+=22+n;}
 if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-LOCALHEADER")||!sxvi_read(c,p,b,40))return true;uint64_t bs=sxvi64(b,0),used=sxvi64(b+8,0),blocks=sxvi64(b+16,0),bitmap=sxvi64(b+24,0);if(!SXVI_ADD(c,partimage_local_header,p)||!SXVI_ADD(c,partimage_header_checksum,p+16384))return false;p+=16388;
 if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-BITMAP")||!sxvi_span(c,p,bitmap))return true;p+=bitmap;if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-INFO")||!sxvi_span(c,p,16388))return true;if(!SXVI_ADD(c,partimage_header_checksum,p+16384))return false;p+=16388;if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-DATABLOCKS"))return true;
 if(!bs||bs>65536||used>blocks||used>UINT64_MAX/bs)return true;uint64_t bytes=used*bs,checks=bytes/65536;if(bytes>UINT64_MAX-checks*16||!sxvi_span(c,p,bytes+checks*16))return true;uint64_t end=p+bytes+checks*16;
 for(uint64_t i=0;i<checks&&c->count<SXVI_LIMIT;i++){uint64_t at=p+(i+1)*65536+i*16;if(!sxvi_magic(c,at,"CHK\0",4))break;if(!SXVI_ADD(c,partimage_data_check,at))return false;}
 if(!sxvi_pi_marker(c,&end,"MAGIC-BEGIN-TAIL")||!sxvi_span(c,end,16384))return true;return SXVI_ADD(c,partimage_tail,end);
}
static int sxvi_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxvi_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxvi_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_volumeimages_supports(xx_file_type_t t){switch(t){
 case XX_FILE_TYPE_LVM2:case XX_FILE_TYPE_MD_RAID:case XX_FILE_TYPE_WINDOWS_LDM:case XX_FILE_TYPE_BSD_DISKLABEL:case XX_FILE_TYPE_SUNVTOC:case XX_FILE_TYPE_NEXTSTEP_DISKIMAGE:case XX_FILE_TYPE_AFF:case XX_FILE_TYPE_EWF:case XX_FILE_TYPE_EWF_L01:case XX_FILE_TYPE_EWF2_EX01:case XX_FILE_TYPE_EWF2_LX01:case XX_FILE_TYPE_PARTIMAGE:case XX_FILE_TYPE_BTRFS_STREAM:case XX_FILE_TYPE_DISKJUGGLER:case XX_FILE_TYPE_MDS:case XX_FILE_TYPE_UIF:case XX_FILE_TYPE_GBI:case XX_FILE_TYPE_HSF:case XX_FILE_TYPE_AARUFORMAT:case XX_FILE_TYPE_ZISOFS:return true;default:return false;}}
static bool sx_volumeimages_build(sx_context*c){bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_LVM2:ok=sxvi_lvm(c);break;case XX_FILE_TYPE_MD_RAID:ok=sxvi_md(c);break;case XX_FILE_TYPE_WINDOWS_LDM:ok=sxvi_ldm(c);break;case XX_FILE_TYPE_BSD_DISKLABEL:ok=sxvi_bsd(c);break;case XX_FILE_TYPE_SUNVTOC:ok=sxvi_sun(c);break;case XX_FILE_TYPE_NEXTSTEP_DISKIMAGE:ok=sxvi_next(c);break;case XX_FILE_TYPE_AFF:ok=sxvi_aff(c);break;case XX_FILE_TYPE_EWF:case XX_FILE_TYPE_EWF_L01:ok=sxvi_ewf1(c);break;case XX_FILE_TYPE_EWF2_EX01:case XX_FILE_TYPE_EWF2_LX01:ok=sxvi_ewf2(c);break;case XX_FILE_TYPE_PARTIMAGE:ok=sxvi_partimage(c);break;case XX_FILE_TYPE_BTRFS_STREAM:ok=sxvi_btrfs(c);break;case XX_FILE_TYPE_DISKJUGGLER:ok=sxvi_cdi(c);break;case XX_FILE_TYPE_MDS:ok=sxvi_mds(c);break;case XX_FILE_TYPE_UIF:ok=sxvi_uif(c);break;case XX_FILE_TYPE_GBI:ok=sxvi_gbi(c);break;case XX_FILE_TYPE_HSF:ok=sxvi_hsf(c);break;case XX_FILE_TYPE_AARUFORMAT:ok=sxvi_aaru(c);break;case XX_FILE_TYPE_ZISOFS:ok=sxvi_zisofs(c);break;default:return false;}
 return (ok||c->count)&&c->count&&!c->failed&&!xx_pd_is_stopped(c->pd)&&sxvi_finish(c);
}
#undef SXVI_ADD
#undef SXVI_TABLE
#undef SXVI_ORDER
#undef SXVI_LIMIT
