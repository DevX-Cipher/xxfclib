/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical disk-container metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_systemlater_scope.txt. */

static const xx_data_struct_field_desc sxsl_lofi_header_fields[] = {
    SX_FIELD("algorithm","char[36]",0,36,SX_NONE),
    SX_FIELD("segment_size","uint32",36,4,SX_SIZE),
    SX_FIELD("index_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("last_segment_size","uint32",44,4,SX_SIZE),
};
static const sx_layout sxsl_lofi_header = {0x60330001U,"lofi_header",sxsl_lofi_header_fields,SX_COUNT(sxsl_lofi_header_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_lofi_index_fields[] = {
    SX_FIELD("segment_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxsl_lofi_index = {0x60330002U,"lofi_index",sxsl_lofi_index_fields,SX_COUNT(sxsl_lofi_index_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_lofi_segment_fields[] = {
    SX_FIELD("compressed","uint8",0,1,SX_ID),
};
static const sx_layout sxsl_lofi_segment = {0x60330003U,"lofi_segment",sxsl_lofi_segment_fields,SX_COUNT(sxsl_lofi_segment_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_lofi_lzma_header_fields[] = {
    SX_FIELD("properties","uint8",0,1,SX_ID),
    SX_FIELD("dictionary_size","uint32",1,4,SX_SIZE),
    SX_FIELD("uncompressed_size","uint64",5,8,SX_SIZE),
};
static const sx_layout sxsl_lofi_lzma_header = {0x60330004U,"lofi_lzma_header",sxsl_lofi_lzma_header_fields,SX_COUNT(sxsl_lofi_lzma_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_savedskf_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("media_descriptor","uint16",2,2,SX_ID),
    SX_FIELD("sector_size","uint16",4,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster_minus_one","uint8",6,1,SX_NONE),
    SX_FIELD("cluster_shift","uint8",7,1,SX_NONE),
    SX_FIELD("reserved_sectors","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("first_data_sector","uint16",13,2,SX_NONE),
    SX_FIELD("highest_cluster","uint16",15,2,SX_NONE),
    SX_FIELD("sectors_per_fat","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("root_directory_sector","uint16",18,2,SX_NONE),
    SX_FIELD("checksum","uint32",20,4,SX_CHECKSUM),
    SX_FIELD("cylinder_count","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",28,2,SX_COUNT_PROP),
    SX_FIELD("unknown_1e","byte[4]",30,4,SX_NONE),
    SX_FIELD("stored_sector_count","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("comment_offset","uint16",36,2,SX_OFFSET),
    SX_FIELD("data_offset","uint16",38,2,SX_OFFSET),
};
static const sx_layout sxsl_savedskf_header = {0x60330005U,"savedskf_header",sxsl_savedskf_header_fields,SX_COUNT(sxsl_savedskf_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_diskdupe_header_fields[] = {
    SX_FIELD("signature","char[21]",0,21,SX_SIGNATURE),
    SX_FIELD("unknown_15","byte[46]",21,46,SX_NONE),
    SX_FIELD("track_count","uint8",67,1,SX_COUNT_PROP),
    SX_FIELD("block_size","uint16",68,2,SX_SIZE),
    SX_FIELD("unknown_46","byte[2]",70,2,SX_NONE),
};
static const sx_layout sxsl_diskdupe_header = {0x60330006U,"diskdupe_header",sxsl_diskdupe_header_fields,SX_COUNT(sxsl_diskdupe_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_diskdupe_track_fields[] = {
    SX_FIELD("block_offset","uint24",0,3,SX_NONE),
    SX_FIELD("status","uint8",3,1,SX_ID),
    SX_FIELD("unknown","uint8",4,1,SX_NONE),
};
static const sx_layout sxsl_diskdupe_track = {0x60330007U,"diskdupe_track",sxsl_diskdupe_track_fields,SX_COUNT(sxsl_diskdupe_track_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_pmdiskcopy_header_fields[] = {
    SX_FIELD("signature","char[11]",0,11,SX_SIGNATURE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("opaque_tail","byte[11]",36,11,SX_NONE),
};
static const sx_layout sxsl_pmdiskcopy_header = {0x60330008U,"pmdiskcopy_header",sxsl_pmdiskcopy_header_fields,SX_COUNT(sxsl_pmdiskcopy_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_qrst_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","float32",4,4,SX_NONE),
    SX_FIELD("set_id","uint32",8,4,SX_ID),
    SX_FIELD("disk_type","uint8",12,1,SX_ID),
    SX_FIELD("disk_number","uint8",13,1,SX_NONE),
    SX_FIELD("disk_count","uint8",14,1,SX_COUNT_PROP),
    SX_FIELD("description_and_banner","char[781]",15,781,SX_NONE),
};
static const sx_layout sxsl_qrst_header = {0x60330009U,"qrst_header",sxsl_qrst_header_fields,SX_COUNT(sxsl_qrst_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_qrst_track_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("method","uint8",2,1,SX_ID),
};
static const sx_layout sxsl_qrst_track = {0x6033000aU,"qrst_track",sxsl_qrst_track_fields,SX_COUNT(sxsl_qrst_track_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_qrst_fill_fields[] = {
    SX_FIELD("fill_value","uint8",0,1,SX_ID),
};
static const sx_layout sxsl_qrst_fill = {0x6033000bU,"qrst_fill",sxsl_qrst_fill_fields,SX_COUNT(sxsl_qrst_fill_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_qrst_encoded_size_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxsl_qrst_encoded_size = {0x6033000cU,"qrst_encoded_size",sxsl_qrst_encoded_size_fields,SX_COUNT(sxsl_qrst_encoded_size_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_hdcopy_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("label_size","uint8",2,1,SX_SIZE),
    SX_FIELD("label","char[11]",3,11,SX_NONE),
    SX_FIELD("last_cylinder","uint8",14,1,SX_NONE),
    SX_FIELD("sectors_per_track","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("track_usage_map","uint8[168]",16,168,SX_FLAGS),
};
static const sx_layout sxsl_hdcopy_header = {0x6033000dU,"hdcopy_header",sxsl_hdcopy_header_fields,SX_COUNT(sxsl_hdcopy_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_hdcopy_block_fields[] = {
    SX_FIELD("block_size","uint16",0,2,SX_SIZE),
    SX_FIELD("escape","uint8",2,1,SX_ID),
};
static const sx_layout sxsl_hdcopy_block = {0x6033000eU,"hdcopy_block",sxsl_hdcopy_block_fields,SX_COUNT(sxsl_hdcopy_block_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_apridisk_header_fields[] = {
    SX_FIELD("signature","char[24]",0,24,SX_SIGNATURE),
    SX_FIELD("reserved","byte[104]",24,104,SX_RESERVED),
};
static const sx_layout sxsl_apridisk_header = {0x6033000fU,"apridisk_header",sxsl_apridisk_header_fields,SX_COUNT(sxsl_apridisk_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_apridisk_record_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("compression","uint16",4,2,SX_ID),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
    SX_FIELD("head","uint8",12,1,SX_NONE),
    SX_FIELD("sector","uint8",13,1,SX_NONE),
    SX_FIELD("cylinder","uint16",14,2,SX_NONE),
};
static const sx_layout sxsl_apridisk_record = {0x60330010U,"apridisk_record",sxsl_apridisk_record_fields,SX_COUNT(sxsl_apridisk_record_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_diskcopy42_header_fields[] = {
    SX_FIELD("name_size","uint8",0,1,SX_SIZE),
    SX_FIELD("disk_name","char[63]",1,63,SX_NONE),
    SX_FIELD("data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("tag_size","uint32",68,4,SX_SIZE),
    SX_FIELD("data_checksum","uint32",72,4,SX_CHECKSUM),
    SX_FIELD("tag_checksum","uint32",76,4,SX_CHECKSUM),
    SX_FIELD("disk_format","uint8",80,1,SX_ID),
    SX_FIELD("format_byte","uint8",81,1,SX_ID),
    SX_FIELD("private_word","uint16",82,2,SX_ID),
};
static const sx_layout sxsl_diskcopy42_header = {0x60330011U,"diskcopy42_header",sxsl_diskcopy42_header_fields,SX_COUNT(sxsl_diskcopy42_header_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_isz_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint8",4,1,SX_SIZE),
    SX_FIELD("version","uint8",5,1,SX_NONE),
    SX_FIELD("volume_serial","uint32",6,4,SX_ID),
    SX_FIELD("sector_size","uint16",10,2,SX_SIZE),
    SX_FIELD("sector_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("encryption","uint8",16,1,SX_ID),
    SX_FIELD("volume_size","uint64",17,8,SX_SIZE),
    SX_FIELD("chunk_count","uint32",25,4,SX_COUNT_PROP),
    SX_FIELD("chunk_size","uint32",29,4,SX_SIZE),
    SX_FIELD("pointer_size","uint8",33,1,SX_SIZE),
    SX_FIELD("volume_number","uint8",34,1,SX_NONE),
    SX_FIELD("pointer_table_offset","uint32",35,4,SX_OFFSET),
    SX_FIELD("segment_table_offset","uint32",39,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",43,4,SX_OFFSET),
    SX_FIELD("reserved","uint8",47,1,SX_RESERVED),
};
static const sx_layout sxsl_isz_header = {0x60330012U,"isz_header",sxsl_isz_header_fields,SX_COUNT(sxsl_isz_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_isz_checksum_tail_fields[] = {
    SX_FIELD("checksum1","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("unknown","uint32",8,4,SX_NONE),
    SX_FIELD("checksum2","uint32",12,4,SX_CHECKSUM),
};
static const sx_layout sxsl_isz_checksum_tail = {0x60330013U,"isz_checksum_tail",sxsl_isz_checksum_tail_fields,SX_COUNT(sxsl_isz_checksum_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_isz_encoded_pointer1_fields[] = {
    SX_FIELD("encoded_size_and_type","byte[1]",0,1,SX_NONE),
};
static const sx_layout sxsl_isz_encoded_pointer1 = {0x60330014U,"isz_encoded_pointer1",sxsl_isz_encoded_pointer1_fields,SX_COUNT(sxsl_isz_encoded_pointer1_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_isz_encoded_pointer2_fields[] = {
    SX_FIELD("encoded_size_and_type","byte[2]",0,2,SX_NONE),
};
static const sx_layout sxsl_isz_encoded_pointer2 = {0x60330015U,"isz_encoded_pointer2",sxsl_isz_encoded_pointer2_fields,SX_COUNT(sxsl_isz_encoded_pointer2_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_isz_encoded_pointer3_fields[] = {
    SX_FIELD("encoded_size_and_type","byte[3]",0,3,SX_NONE),
};
static const sx_layout sxsl_isz_encoded_pointer3 = {0x60330016U,"isz_encoded_pointer3",sxsl_isz_encoded_pointer3_fields,SX_COUNT(sxsl_isz_encoded_pointer3_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_isz_encoded_pointer4_fields[] = {
    SX_FIELD("encoded_size_and_type","byte[4]",0,4,SX_NONE),
};
static const sx_layout sxsl_isz_encoded_pointer4 = {0x60330017U,"isz_encoded_pointer4",sxsl_isz_encoded_pointer4_fields,SX_COUNT(sxsl_isz_encoded_pointer4_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_isz_encoded_segment_fields[] = {
    SX_FIELD("encoded_volume_size","byte[8]",0,8,SX_NONE),
    SX_FIELD("encoded_chunk_count","byte[4]",8,4,SX_NONE),
    SX_FIELD("encoded_first_chunk","byte[4]",12,4,SX_NONE),
    SX_FIELD("encoded_data_offset","byte[4]",16,4,SX_NONE),
    SX_FIELD("encoded_last_chunk_continuation","byte[4]",20,4,SX_NONE),
};
static const sx_layout sxsl_isz_encoded_segment = {0x60330018U,"isz_encoded_segment",sxsl_isz_encoded_segment_fields,SX_COUNT(sxsl_isz_encoded_segment_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_mfi_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("cylinders_and_resolution","uint32",16,4,SX_FLAGS),
    SX_FIELD("head_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("form_factor","uint32",24,4,SX_ID),
    SX_FIELD("variant","uint32",28,4,SX_ID),
};
static const sx_layout sxsl_mfi_header = {0x60330019U,"mfi_header",sxsl_mfi_header_fields,SX_COUNT(sxsl_mfi_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_mfi_track_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
    SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("write_splice","uint32",12,4,SX_NONE),
};
static const sx_layout sxsl_mfi_track = {0x6033001aU,"mfi_track",sxsl_mfi_track_fields,SX_COUNT(sxsl_mfi_track_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sdi_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("type","uint64",8,8,SX_ID),
    SX_FIELD("boot_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("boot_size","uint64",24,8,SX_SIZE),
    SX_FIELD("vendor_id","uint64",32,8,SX_ID),
    SX_FIELD("device_id","uint64",40,8,SX_ID),
    SX_FIELD("device_model","byte[16]",48,16,SX_NONE),
    SX_FIELD("device_role","uint64",64,8,SX_ID),
    SX_FIELD("reserved1","uint64",72,8,SX_RESERVED),
    SX_FIELD("runtime_guid","byte[16]",80,16,SX_NONE),
    SX_FIELD("runtime_oem_revision","uint64",96,8,SX_NONE),
    SX_FIELD("reserved2","uint64",104,8,SX_RESERVED),
    SX_FIELD("page_alignment","int64",112,8,SX_NONE),
    SX_FIELD("reserved3","byte[384]",120,384,SX_RESERVED),
    SX_FIELD("checksum","uint64",504,8,SX_CHECKSUM),
};
static const sx_layout sxsl_sdi_header = {0x6033001bU,"sdi_header",sxsl_sdi_header_fields,SX_COUNT(sxsl_sdi_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sdi_section_fields[] = {
    SX_FIELD("section_type","char[8]",0,8,SX_ID),
    SX_FIELD("attributes","uint64",8,8,SX_FLAGS),
    SX_FIELD("data_offset","int64",16,8,SX_OFFSET),
    SX_FIELD("data_size","int64",24,8,SX_SIZE),
    SX_FIELD("partition_type","uint64",32,8,SX_ID),
    SX_FIELD("reserved","byte[24]",40,24,SX_RESERVED),
};
static const sx_layout sxsl_sdi_section = {0x6033001cU,"sdi_section",sxsl_sdi_section_fields,SX_COUNT(sxsl_sdi_section_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_nhd_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("comment","char[256]",16,256,SX_NONE),
    SX_FIELD("header_size","uint32",272,4,SX_SIZE),
    SX_FIELD("cylinder_count","uint32",276,4,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",280,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",282,2,SX_COUNT_PROP),
    SX_FIELD("sector_size","uint16",284,2,SX_SIZE),
    SX_FIELD("reserved","byte[226]",286,226,SX_RESERVED),
};
static const sx_layout sxsl_nhd_header = {0x6033001dU,"nhd_header",sxsl_nhd_header_fields,SX_COUNT(sxsl_nhd_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_virtual98_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("comment","char[128]",8,128,SX_NONE),
    SX_FIELD("padding","uint32",136,4,SX_RESERVED),
    SX_FIELD("megabyte_size","uint16",140,2,SX_NONE),
    SX_FIELD("sector_size","uint16",142,2,SX_SIZE),
    SX_FIELD("sectors_per_track","uint8",144,1,SX_COUNT_PROP),
    SX_FIELD("head_count","uint8",145,1,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint16",146,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("padding2","byte[68]",152,68,SX_RESERVED),
};
static const sx_layout sxsl_virtual98_header = {0x6033001eU,"virtual98_header",sxsl_virtual98_header_fields,SX_COUNT(sxsl_virtual98_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_anex86_header_fields[] = {
    SX_FIELD("unknown1","uint32",0,4,SX_NONE),
    SX_FIELD("unknown2","uint32",4,4,SX_NONE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("disk_size","uint32",12,4,SX_SIZE),
    SX_FIELD("sector_size","uint32",16,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("head_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxsl_anex86_header = {0x6033001fU,"anex86_header",sxsl_anex86_header_fields,SX_COUNT(sxsl_anex86_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sap_header_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_ID),
    SX_FIELD("signature","char[65]",1,65,SX_SIGNATURE),
};
static const sx_layout sxsl_sap_header = {0x60330020U,"sap_header",sxsl_sap_header_fields,SX_COUNT(sxsl_sap_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sap_sector_fields[] = {
    SX_FIELD("format","uint8",0,1,SX_ID),
    SX_FIELD("protection","uint8",1,1,SX_FLAGS),
    SX_FIELD("cylinder","uint8",2,1,SX_NONE),
    SX_FIELD("sector","uint8",3,1,SX_NONE),
};
static const sx_layout sxsl_sap_sector = {0x60330021U,"sap_sector",sxsl_sap_sector_fields,SX_COUNT(sxsl_sap_sector_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sap_checksum_fields[] = {
    SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxsl_sap_checksum = {0x60330022U,"sap_checksum",sxsl_sap_checksum_fields,SX_COUNT(sxsl_sap_checksum_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_dmk_header_fields[] = {
    SX_FIELD("write_protected","uint8",0,1,SX_FLAGS),
    SX_FIELD("cylinder_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("track_size","uint16",2,2,SX_SIZE),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("reserved","byte[7]",5,7,SX_RESERVED),
    SX_FIELD("real_disk_flags","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxsl_dmk_header = {0x60330023U,"dmk_header",sxsl_dmk_header_fields,SX_COUNT(sxsl_dmk_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_dmk_idam_pointer_fields[] = {
    SX_FIELD("offset_and_density","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxsl_dmk_idam_pointer = {0x60330024U,"dmk_idam_pointer",sxsl_dmk_idam_pointer_fields,SX_COUNT(sxsl_dmk_idam_pointer_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_dmk_idam_fields[] = {
    SX_FIELD("id_address_mark","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("cylinder","uint8",1,1,SX_NONE),
    SX_FIELD("head","uint8",2,1,SX_NONE),
    SX_FIELD("sector","uint8",3,1,SX_NONE),
    SX_FIELD("size_code","uint8",4,1,SX_NONE),
    SX_FIELD("crc16","uint16be",5,2,SX_CHECKSUM),
};
static const sx_layout sxsl_dmk_idam = {0x60330025U,"dmk_idam",sxsl_dmk_idam_fields,SX_COUNT(sxsl_dmk_idam_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_extadf_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",8,2,SX_RESERVED),
    SX_FIELD("track_count","uint16",10,2,SX_COUNT_PROP),
};
static const sx_layout sxsl_extadf_header = {0x60330026U,"extadf_header",sxsl_extadf_header_fields,SX_COUNT(sxsl_extadf_header_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_extadf_track_fields[] = {
    SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
    SX_FIELD("revolution_count_minus_one","uint8",2,1,SX_NONE),
    SX_FIELD("track_type","uint8",3,1,SX_ID),
    SX_FIELD("allocated_size","uint32",4,4,SX_SIZE),
    SX_FIELD("bit_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxsl_extadf_track = {0x60330027U,"extadf_track",sxsl_extadf_track_fields,SX_COUNT(sxsl_extadf_track_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_oldextadf_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxsl_oldextadf_header = {0x60330028U,"oldextadf_header",sxsl_oldextadf_header_fields,SX_COUNT(sxsl_oldextadf_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_oldextadf_track_fields[] = {
    SX_FIELD("sync_word","uint16",0,2,SX_ID),
    SX_FIELD("data_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxsl_oldextadf_track = {0x60330029U,"oldextadf_track",sxsl_oldextadf_track_fields,SX_COUNT(sxsl_oldextadf_track_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_udi_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("size_without_crc","uint32",4,4,SX_SIZE),
    SX_FIELD("version","uint8",8,1,SX_NONE),
    SX_FIELD("last_cylinder","uint8",9,1,SX_NONE),
    SX_FIELD("last_head","uint8",10,1,SX_NONE),
    SX_FIELD("reserved","uint8",11,1,SX_RESERVED),
    SX_FIELD("extended_header_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxsl_udi_header = {0x6033002aU,"udi_header",sxsl_udi_header_fields,SX_COUNT(sxsl_udi_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_udi_track_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("track_size","uint16",1,2,SX_SIZE),
};
static const sx_layout sxsl_udi_track = {0x6033002bU,"udi_track",sxsl_udi_track_fields,SX_COUNT(sxsl_udi_track_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_udi_compressed_track_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("compressed_size_minus_one","uint16",1,2,SX_NONE),
    SX_FIELD("original_type","uint8",3,1,SX_ID),
    SX_FIELD("track_size","uint16",4,2,SX_SIZE),
};
static const sx_layout sxsl_udi_compressed_track = {0x6033002cU,"udi_compressed_track",sxsl_udi_compressed_track_fields,SX_COUNT(sxsl_udi_compressed_track_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_udi_checksum_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxsl_udi_checksum = {0x6033002dU,"udi_checksum",sxsl_udi_checksum_fields,SX_COUNT(sxsl_udi_checksum_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_moof_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("binary_marker","byte[4]",4,4,SX_SIGNATURE),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
};
static const sx_layout sxsl_moof_header = {0x6033002eU,"moof_header",sxsl_moof_header_fields,SX_COUNT(sxsl_moof_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_moof_chunk_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxsl_moof_chunk = {0x6033002fU,"moof_chunk",sxsl_moof_chunk_fields,SX_COUNT(sxsl_moof_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_moof_info_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("write_protected","uint8",2,1,SX_FLAGS),
    SX_FIELD("synchronized","uint8",3,1,SX_FLAGS),
    SX_FIELD("optimal_bit_timing","uint8",4,1,SX_NONE),
    SX_FIELD("creator","char[32]",5,32,SX_NONE),
    SX_FIELD("reserved","uint8",37,1,SX_RESERVED),
    SX_FIELD("largest_track_blocks","uint16",38,2,SX_COUNT_PROP),
    SX_FIELD("flux_block","uint16",40,2,SX_NONE),
    SX_FIELD("largest_flux_track_blocks","uint16",42,2,SX_COUNT_PROP),
};
static const sx_layout sxsl_moof_info = {0x60330030U,"moof_info",sxsl_moof_info_fields,SX_COUNT(sxsl_moof_info_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_moof_track_map_fields[] = {
    SX_FIELD("track_index","uint8",0,1,SX_NONE),
};
static const sx_layout sxsl_moof_track_map = {0x60330031U,"moof_track_map",sxsl_moof_track_map_fields,SX_COUNT(sxsl_moof_track_map_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_moof_track_fields[] = {
    SX_FIELD("starting_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("bit_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsl_moof_track = {0x60330032U,"moof_track",sxsl_moof_track_fields,SX_COUNT(sxsl_moof_track_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_bochs_growing_v1_fields[] = {
    SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
    SX_FIELD("type","char[16]",32,16,SX_ID),
    SX_FIELD("subtype","char[16]",48,16,SX_ID),
    SX_FIELD("version","uint32",64,4,SX_NONE),
    SX_FIELD("header_size","uint32",68,4,SX_SIZE),
    SX_FIELD("catalog_count","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_size","uint32",76,4,SX_SIZE),
    SX_FIELD("extent_size","uint32",80,4,SX_SIZE),
    SX_FIELD("disk_size","uint64",84,8,SX_SIZE),
    SX_FIELD("reserved","byte[420]",92,420,SX_RESERVED),
};
static const sx_layout sxsl_bochs_growing_v1 = {0x60330033U,"bochs_growing_v1",sxsl_bochs_growing_v1_fields,SX_COUNT(sxsl_bochs_growing_v1_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_bochs_growing_v2_fields[] = {
    SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
    SX_FIELD("type","char[16]",32,16,SX_ID),
    SX_FIELD("subtype","char[16]",48,16,SX_ID),
    SX_FIELD("version","uint32",64,4,SX_NONE),
    SX_FIELD("header_size","uint32",68,4,SX_SIZE),
    SX_FIELD("catalog_count","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_size","uint32",76,4,SX_SIZE),
    SX_FIELD("extent_size","uint32",80,4,SX_SIZE),
    SX_FIELD("reserved_timestamp","uint32",84,4,SX_NONE),
    SX_FIELD("disk_size","uint64",88,8,SX_SIZE),
    SX_FIELD("reserved","byte[416]",96,416,SX_RESERVED),
};
static const sx_layout sxsl_bochs_growing_v2 = {0x60330034U,"bochs_growing_v2",sxsl_bochs_growing_v2_fields,SX_COUNT(sxsl_bochs_growing_v2_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_bochs_catalog_entry_fields[] = {
    SX_FIELD("extent_index","uint32",0,4,SX_NONE),
};
static const sx_layout sxsl_bochs_catalog_entry = {0x60330035U,"bochs_catalog_entry",sxsl_bochs_catalog_entry_fields,SX_COUNT(sxsl_bochs_catalog_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_bochs_bitmap_byte_fields[] = {
    SX_FIELD("allocated_sector_bits","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxsl_bochs_bitmap_byte = {0x60330036U,"bochs_bitmap_byte",sxsl_bochs_bitmap_byte_fields,SX_COUNT(sxsl_bochs_bitmap_byte_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_partclone_header_le_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("creator_version","char[14]",16,14,SX_NONE),
    SX_FIELD("image_version","char[4]",30,4,SX_NONE),
    SX_FIELD("byte_order_marker","uint16",34,2,SX_ID),
    SX_FIELD("filesystem","char[16]",36,16,SX_NONE),
    SX_FIELD("device_size","uint64",52,8,SX_SIZE),
    SX_FIELD("total_blocks","uint64",60,8,SX_COUNT_PROP),
    SX_FIELD("superblock_used_blocks","uint64",68,8,SX_COUNT_PROP),
    SX_FIELD("bitmap_used_blocks","uint64",76,8,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",84,4,SX_SIZE),
    SX_FIELD("feature_size","uint32",88,4,SX_SIZE),
    SX_FIELD("options_image_version","uint16",92,2,SX_NONE),
    SX_FIELD("cpu_bits","uint16",94,2,SX_NONE),
    SX_FIELD("checksum_mode","uint16",96,2,SX_ID),
    SX_FIELD("checksum_size","uint16",98,2,SX_SIZE),
    SX_FIELD("blocks_per_checksum","uint32",100,4,SX_COUNT_PROP),
    SX_FIELD("reseed_checksum","uint8",104,1,SX_FLAGS),
    SX_FIELD("bitmap_mode","uint8",105,1,SX_ID),
    SX_FIELD("header_crc","uint32",106,4,SX_CHECKSUM),
};
static const sx_layout sxsl_partclone_header_le = {0x60330037U,"partclone_header_le",sxsl_partclone_header_le_fields,SX_COUNT(sxsl_partclone_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_partclone_bitmap_crc_le_fields[] = {
    SX_FIELD("bitmap_crc","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxsl_partclone_bitmap_crc_le = {0x60330038U,"partclone_bitmap_crc_le",sxsl_partclone_bitmap_crc_le_fields,SX_COUNT(sxsl_partclone_bitmap_crc_le_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_partclone_header_be_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("creator_version","char[14]",16,14,SX_NONE),
    SX_FIELD("image_version","char[4]",30,4,SX_NONE),
    SX_FIELD("byte_order_marker","uint16",34,2,SX_ID),
    SX_FIELD("filesystem","char[16]",36,16,SX_NONE),
    SX_FIELD("device_size","uint64",52,8,SX_SIZE),
    SX_FIELD("total_blocks","uint64",60,8,SX_COUNT_PROP),
    SX_FIELD("superblock_used_blocks","uint64",68,8,SX_COUNT_PROP),
    SX_FIELD("bitmap_used_blocks","uint64",76,8,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",84,4,SX_SIZE),
    SX_FIELD("feature_size","uint32",88,4,SX_SIZE),
    SX_FIELD("options_image_version","uint16",92,2,SX_NONE),
    SX_FIELD("cpu_bits","uint16",94,2,SX_NONE),
    SX_FIELD("checksum_mode","uint16",96,2,SX_ID),
    SX_FIELD("checksum_size","uint16",98,2,SX_SIZE),
    SX_FIELD("blocks_per_checksum","uint32",100,4,SX_COUNT_PROP),
    SX_FIELD("reseed_checksum","uint8",104,1,SX_FLAGS),
    SX_FIELD("bitmap_mode","uint8",105,1,SX_ID),
    SX_FIELD("header_crc","uint32",106,4,SX_CHECKSUM),
};
static const sx_layout sxsl_partclone_header_be = {0x60330039U,"partclone_header_be",sxsl_partclone_header_be_fields,SX_COUNT(sxsl_partclone_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_partclone_bitmap_crc_be_fields[] = {
    SX_FIELD("bitmap_crc","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxsl_partclone_bitmap_crc_be = {0x6033003aU,"partclone_bitmap_crc_be",sxsl_partclone_bitmap_crc_be_fields,SX_COUNT(sxsl_partclone_bitmap_crc_be_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_dms_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unknown_04","byte[6]",4,6,SX_NONE),
    SX_FIELD("general_info","uint16",10,2,SX_FLAGS),
    SX_FIELD("creation_time","uint32",12,4,SX_TIME),
    SX_FIELD("first_track","uint16",16,2,SX_NONE),
    SX_FIELD("last_track","uint16",18,2,SX_NONE),
    SX_FIELD("packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("unknown_1c","byte[18]",28,18,SX_NONE),
    SX_FIELD("creator_version","uint16",46,2,SX_NONE),
    SX_FIELD("unknown_30","byte[2]",48,2,SX_NONE),
    SX_FIELD("disk_type","uint16",50,2,SX_ID),
    SX_FIELD("compression_mode","uint16",52,2,SX_ID),
    SX_FIELD("header_crc","uint16",54,2,SX_CHECKSUM),
};
static const sx_layout sxsl_dms_header = {0x6033003bU,"dms_header",sxsl_dms_header_fields,SX_COUNT(sxsl_dms_header_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_dms_track_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("track_number","uint16",2,2,SX_NONE),
    SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
    SX_FIELD("packed_size","uint16",6,2,SX_SIZE),
    SX_FIELD("intermediate_size","uint16",8,2,SX_SIZE),
    SX_FIELD("unpacked_size","uint16",10,2,SX_SIZE),
    SX_FIELD("flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("compression_mode","uint8",13,1,SX_ID),
    SX_FIELD("unpacked_checksum","uint16",14,2,SX_CHECKSUM),
    SX_FIELD("packed_crc","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("header_crc","uint16",18,2,SX_CHECKSUM),
};
static const sx_layout sxsl_dms_track = {0x6033003cU,"dms_track",sxsl_dms_track_fields,SX_COUNT(sxsl_dms_track_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_footer32_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("chunk_list_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxsl_nrg_footer32 = {0x6033003dU,"nrg_footer32",sxsl_nrg_footer32_fields,SX_COUNT(sxsl_nrg_footer32_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_dao_track32_fields[] = {
    SX_FIELD("isrc","char[12]",0,12,SX_NONE),
    SX_FIELD("sector_size","uint16",12,2,SX_SIZE),
    SX_FIELD("mode","uint8",14,1,SX_ID),
    SX_FIELD("unknown","byte[3]",15,3,SX_NONE),
    SX_FIELD("pregap_offset","uint32",18,4,SX_OFFSET),
    SX_FIELD("track_offset","uint32",22,4,SX_OFFSET),
    SX_FIELD("end_offset","uint32",26,4,SX_OFFSET),
};
static const sx_layout sxsl_nrg_dao_track32 = {0x6033003eU,"nrg_dao_track32",sxsl_nrg_dao_track32_fields,SX_COUNT(sxsl_nrg_dao_track32_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_etn_track32_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("unknown1","byte[3]",8,3,SX_NONE),
    SX_FIELD("mode","uint8",11,1,SX_ID),
    SX_FIELD("start_lba","int32",12,4,SX_NONE),
    SX_FIELD("unknown2","byte[4]",16,4,SX_NONE),
};
static const sx_layout sxsl_nrg_etn_track32 = {0x6033003fU,"nrg_etn_track32",sxsl_nrg_etn_track32_fields,SX_COUNT(sxsl_nrg_etn_track32_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_footer64_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("chunk_list_offset","uint64",4,8,SX_OFFSET),
};
static const sx_layout sxsl_nrg_footer64 = {0x60330040U,"nrg_footer64",sxsl_nrg_footer64_fields,SX_COUNT(sxsl_nrg_footer64_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_dao_track64_fields[] = {
    SX_FIELD("isrc","char[12]",0,12,SX_NONE),
    SX_FIELD("sector_size","uint16",12,2,SX_SIZE),
    SX_FIELD("mode","uint8",14,1,SX_ID),
    SX_FIELD("unknown","byte[3]",15,3,SX_NONE),
    SX_FIELD("pregap_offset","uint64",18,8,SX_OFFSET),
    SX_FIELD("track_offset","uint64",26,8,SX_OFFSET),
    SX_FIELD("end_offset","uint64",34,8,SX_OFFSET),
};
static const sx_layout sxsl_nrg_dao_track64 = {0x60330041U,"nrg_dao_track64",sxsl_nrg_dao_track64_fields,SX_COUNT(sxsl_nrg_dao_track64_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_etn_track64_fields[] = {
    SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("data_size","uint64",8,8,SX_SIZE),
    SX_FIELD("unknown1","byte[3]",16,3,SX_NONE),
    SX_FIELD("mode","uint8",19,1,SX_ID),
    SX_FIELD("start_lba","int32",20,4,SX_NONE),
    SX_FIELD("unknown2","byte[8]",24,8,SX_NONE),
};
static const sx_layout sxsl_nrg_etn_track64 = {0x60330042U,"nrg_etn_track64",sxsl_nrg_etn_track64_fields,SX_COUNT(sxsl_nrg_etn_track64_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_chunk_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxsl_nrg_chunk = {0x60330043U,"nrg_chunk",sxsl_nrg_chunk_fields,SX_COUNT(sxsl_nrg_chunk_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_dao_header_fields[] = {
    SX_FIELD("size_word","byte[4]",0,4,SX_NONE),
    SX_FIELD("media_catalog_number","char[13]",4,13,SX_NONE),
    SX_FIELD("unknown1","uint8",17,1,SX_NONE),
    SX_FIELD("session_type","uint8",18,1,SX_ID),
    SX_FIELD("unknown2","uint8",19,1,SX_NONE),
    SX_FIELD("first_track","uint8",20,1,SX_NONE),
    SX_FIELD("last_track","uint8",21,1,SX_NONE),
};
static const sx_layout sxsl_nrg_dao_header = {0x60330044U,"nrg_dao_header",sxsl_nrg_dao_header_fields,SX_COUNT(sxsl_nrg_dao_header_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_cuex_fields[] = {
    SX_FIELD("adr_control","uint8",0,1,SX_FLAGS),
    SX_FIELD("track_bcd","uint8",1,1,SX_NONE),
    SX_FIELD("index_bcd","uint8",2,1,SX_NONE),
    SX_FIELD("unknown","uint8",3,1,SX_NONE),
    SX_FIELD("start_lba","int32",4,4,SX_NONE),
};
static const sx_layout sxsl_nrg_cuex = {0x60330045U,"nrg_cuex",sxsl_nrg_cuex_fields,SX_COUNT(sxsl_nrg_cuex_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_cues_fields[] = {
    SX_FIELD("adr_control","uint8",0,1,SX_FLAGS),
    SX_FIELD("track_bcd","uint8",1,1,SX_NONE),
    SX_FIELD("index_bcd","uint8",2,1,SX_NONE),
    SX_FIELD("unknown","uint8",3,1,SX_NONE),
    SX_FIELD("hour","uint8",4,1,SX_NONE),
    SX_FIELD("minute","uint8",5,1,SX_NONE),
    SX_FIELD("second","uint8",6,1,SX_NONE),
    SX_FIELD("frame","uint8",7,1,SX_NONE),
};
static const sx_layout sxsl_nrg_cues = {0x60330046U,"nrg_cues",sxsl_nrg_cues_fields,SX_COUNT(sxsl_nrg_cues_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_session_fields[] = {
    SX_FIELD("track_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsl_nrg_session = {0x60330047U,"nrg_session",sxsl_nrg_session_fields,SX_COUNT(sxsl_nrg_session_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_nrg_media_fields[] = {
    SX_FIELD("media_type","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxsl_nrg_media = {0x60330048U,"nrg_media",sxsl_nrg_media_fields,SX_COUNT(sxsl_nrg_media_fields),SX_BE};

static const xx_data_struct_field_desc sxsl_cowd_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("capacity_sectors","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("grain_sectors","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("directory_sector","uint32",20,4,SX_NONE),
    SX_FIELD("directory_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("next_free_sector","uint32",28,4,SX_NONE),
};
static const sx_layout sxsl_cowd_header = {0x60330049U,"cowd_header",sxsl_cowd_header_fields,SX_COUNT(sxsl_cowd_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_cowd_root_fields[] = {
    SX_FIELD("cylinder_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("head_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[1016]",12,1016,SX_RESERVED),
};
static const sx_layout sxsl_cowd_root = {0x6033004aU,"cowd_root",sxsl_cowd_root_fields,SX_COUNT(sxsl_cowd_root_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_cowd_child_fields[] = {
    SX_FIELD("parent_filename","char[1024]",0,1024,SX_NONE),
    SX_FIELD("parent_generation","uint32",1024,4,SX_NONE),
};
static const sx_layout sxsl_cowd_child = {0x6033004bU,"cowd_child",sxsl_cowd_child_fields,SX_COUNT(sxsl_cowd_child_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_cowd_tail_fields[] = {
    SX_FIELD("generation","uint32",0,4,SX_NONE),
    SX_FIELD("name","char[60]",4,60,SX_NONE),
    SX_FIELD("description","char[512]",64,512,SX_NONE),
    SX_FIELD("saved_generation","uint32",576,4,SX_NONE),
    SX_FIELD("reserved1","byte[8]",580,8,SX_RESERVED),
    SX_FIELD("dirty","uint32",588,4,SX_FLAGS),
    SX_FIELD("reserved2","byte[396]",592,396,SX_RESERVED),
};
static const sx_layout sxsl_cowd_tail = {0x6033004cU,"cowd_tail",sxsl_cowd_tail_fields,SX_COUNT(sxsl_cowd_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_cowd_directory_fields[] = {
    SX_FIELD("table_sector","uint32",0,4,SX_NONE),
};
static const sx_layout sxsl_cowd_directory = {0x6033004dU,"cowd_directory",sxsl_cowd_directory_fields,SX_COUNT(sxsl_cowd_directory_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_cowd_grain_fields[] = {
    SX_FIELD("grain_sector","uint32",0,4,SX_NONE),
};
static const sx_layout sxsl_cowd_grain = {0x6033004eU,"cowd_grain",sxsl_cowd_grain_fields,SX_COUNT(sxsl_cowd_grain_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sesparse_header_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint64",8,8,SX_NONE),
    SX_FIELD("capacity_sectors","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("grain_sectors","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("table_sectors","uint64",32,8,SX_COUNT_PROP),
    SX_FIELD("flags","uint64",40,8,SX_FLAGS),
    SX_FIELD("reserved1","uint64[4]",48,32,SX_RESERVED),
    SX_FIELD("volatile_header_sector","uint64",80,8,SX_NONE),
    SX_FIELD("volatile_header_sectors","uint64",88,8,SX_COUNT_PROP),
    SX_FIELD("journal_header_sector","uint64",96,8,SX_NONE),
    SX_FIELD("journal_header_sectors","uint64",104,8,SX_COUNT_PROP),
    SX_FIELD("journal_sector","uint64",112,8,SX_NONE),
    SX_FIELD("journal_sectors","uint64",120,8,SX_COUNT_PROP),
    SX_FIELD("grain_directory_sector","uint64",128,8,SX_NONE),
    SX_FIELD("grain_directory_sectors","uint64",136,8,SX_COUNT_PROP),
    SX_FIELD("grain_tables_sector","uint64",144,8,SX_NONE),
    SX_FIELD("grain_tables_sectors","uint64",152,8,SX_COUNT_PROP),
    SX_FIELD("free_bitmap_sector","uint64",160,8,SX_NONE),
    SX_FIELD("free_bitmap_sectors","uint64",168,8,SX_COUNT_PROP),
    SX_FIELD("back_map_sector","uint64",176,8,SX_NONE),
    SX_FIELD("back_map_sectors","uint64",184,8,SX_COUNT_PROP),
    SX_FIELD("grains_sector","uint64",192,8,SX_NONE),
    SX_FIELD("grains_sectors","uint64",200,8,SX_COUNT_PROP),
    SX_FIELD("reserved2","byte[304]",208,304,SX_RESERVED),
};
static const sx_layout sxsl_sesparse_header = {0x6033004fU,"sesparse_header",sxsl_sesparse_header_fields,SX_COUNT(sxsl_sesparse_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sesparse_volatile_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("free_table_number","uint64",8,8,SX_NONE),
    SX_FIELD("next_transaction_number","uint64",16,8,SX_NONE),
    SX_FIELD("replay_journal","uint64",24,8,SX_FLAGS),
    SX_FIELD("reserved","byte[480]",32,480,SX_RESERVED),
};
static const sx_layout sxsl_sesparse_volatile = {0x60330050U,"sesparse_volatile",sxsl_sesparse_volatile_fields,SX_COUNT(sxsl_sesparse_volatile_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sesparse_directory_fields[] = {
    SX_FIELD("table_index_and_flags","uint64",0,8,SX_FLAGS),
};
static const sx_layout sxsl_sesparse_directory = {0x60330051U,"sesparse_directory",sxsl_sesparse_directory_fields,SX_COUNT(sxsl_sesparse_directory_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_sesparse_grain_fields[] = {
    SX_FIELD("grain_index_and_type","uint64",0,8,SX_FLAGS),
};
static const sx_layout sxsl_sesparse_grain = {0x60330052U,"sesparse_grain",sxsl_sesparse_grain_fields,SX_COUNT(sxsl_sesparse_grain_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_dmk_idam_doubled_fields[] = {
    SX_FIELD("id_address_mark","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("id_address_mark_copy","uint8",1,1,SX_NONE),
    SX_FIELD("cylinder","uint8",2,1,SX_NONE),
    SX_FIELD("cylinder_copy","uint8",3,1,SX_NONE),
    SX_FIELD("head","uint8",4,1,SX_NONE),
    SX_FIELD("head_copy","uint8",5,1,SX_NONE),
    SX_FIELD("sector","uint8",6,1,SX_NONE),
    SX_FIELD("sector_copy","uint8",7,1,SX_NONE),
    SX_FIELD("size_code","uint8",8,1,SX_NONE),
    SX_FIELD("size_code_copy","uint8",9,1,SX_NONE),
    SX_FIELD("crc_high","uint8",10,1,SX_CHECKSUM),
    SX_FIELD("crc_high_copy","uint8",11,1,SX_CHECKSUM),
    SX_FIELD("crc_low","uint8",12,1,SX_CHECKSUM),
    SX_FIELD("crc_low_copy","uint8",13,1,SX_CHECKSUM),
};
static const sx_layout sxsl_dmk_idam_doubled = {0x60330053U,"dmk_idam_doubled",sxsl_dmk_idam_doubled_fields,SX_COUNT(sxsl_dmk_idam_doubled_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_partclone_bitmap_byte_fields[] = {
    SX_FIELD("allocated_bits","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxsl_partclone_bitmap_byte = {0x60330054U,"partclone_bitmap_byte",sxsl_partclone_bitmap_byte_fields,SX_COUNT(sxsl_partclone_bitmap_byte_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_partclone_data_checksum4_fields[] = {
    SX_FIELD("checksum","byte[4]",0,4,SX_CHECKSUM),
};
static const sx_layout sxsl_partclone_data_checksum4 = {0x60330055U,"partclone_data_checksum4",sxsl_partclone_data_checksum4_fields,SX_COUNT(sxsl_partclone_data_checksum4_fields),SX_LE};

static const xx_data_struct_field_desc sxsl_partclone_data_checksum16_fields[] = {
    SX_FIELD("checksum","byte[16]",0,16,SX_CHECKSUM),
};
static const sx_layout sxsl_partclone_data_checksum16 = {0x60330056U,"partclone_data_checksum16",sxsl_partclone_data_checksum16_fields,SX_COUNT(sxsl_partclone_data_checksum16_fields),SX_LE};

static const sx_layout *const sx_systemlater_layouts[] = {
    &sxsl_lofi_header,
    &sxsl_lofi_index,
    &sxsl_lofi_segment,
    &sxsl_lofi_lzma_header,
    &sxsl_savedskf_header,
    &sxsl_diskdupe_header,
    &sxsl_diskdupe_track,
    &sxsl_pmdiskcopy_header,
    &sxsl_qrst_header,
    &sxsl_qrst_track,
    &sxsl_qrst_fill,
    &sxsl_qrst_encoded_size,
    &sxsl_hdcopy_header,
    &sxsl_hdcopy_block,
    &sxsl_apridisk_header,
    &sxsl_apridisk_record,
    &sxsl_diskcopy42_header,
    &sxsl_isz_header,
    &sxsl_isz_checksum_tail,
    &sxsl_isz_encoded_pointer1,
    &sxsl_isz_encoded_pointer2,
    &sxsl_isz_encoded_pointer3,
    &sxsl_isz_encoded_pointer4,
    &sxsl_isz_encoded_segment,
    &sxsl_mfi_header,
    &sxsl_mfi_track,
    &sxsl_sdi_header,
    &sxsl_sdi_section,
    &sxsl_nhd_header,
    &sxsl_virtual98_header,
    &sxsl_anex86_header,
    &sxsl_sap_header,
    &sxsl_sap_sector,
    &sxsl_sap_checksum,
    &sxsl_dmk_header,
    &sxsl_dmk_idam_pointer,
    &sxsl_dmk_idam,
    &sxsl_extadf_header,
    &sxsl_extadf_track,
    &sxsl_oldextadf_header,
    &sxsl_oldextadf_track,
    &sxsl_udi_header,
    &sxsl_udi_track,
    &sxsl_udi_compressed_track,
    &sxsl_udi_checksum,
    &sxsl_moof_header,
    &sxsl_moof_chunk,
    &sxsl_moof_info,
    &sxsl_moof_track_map,
    &sxsl_moof_track,
    &sxsl_bochs_growing_v1,
    &sxsl_bochs_growing_v2,
    &sxsl_bochs_catalog_entry,
    &sxsl_bochs_bitmap_byte,
    &sxsl_partclone_header_le,
    &sxsl_partclone_bitmap_crc_le,
    &sxsl_partclone_header_be,
    &sxsl_partclone_bitmap_crc_be,
    &sxsl_dms_header,
    &sxsl_dms_track,
    &sxsl_nrg_footer32,
    &sxsl_nrg_dao_track32,
    &sxsl_nrg_etn_track32,
    &sxsl_nrg_footer64,
    &sxsl_nrg_dao_track64,
    &sxsl_nrg_etn_track64,
    &sxsl_nrg_chunk,
    &sxsl_nrg_dao_header,
    &sxsl_nrg_cuex,
    &sxsl_nrg_cues,
    &sxsl_nrg_session,
    &sxsl_nrg_media,
    &sxsl_cowd_header,
    &sxsl_cowd_root,
    &sxsl_cowd_child,
    &sxsl_cowd_tail,
    &sxsl_cowd_directory,
    &sxsl_cowd_grain,
    &sxsl_sesparse_header,
    &sxsl_sesparse_volatile,
    &sxsl_sesparse_directory,
    &sxsl_sesparse_grain,
    &sxsl_dmk_idam_doubled,
    &sxsl_partclone_bitmap_byte,
    &sxsl_partclone_data_checksum4,
    &sxsl_partclone_data_checksum16,
};

static bool sx_systemlater_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60330000U||id>=0x60340000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;
    if(id==0x60330005U&&!xx_rt_wcscmp(r->name,L"signature")&&integer){switch(value){
    case 22698U:return xx_data_struct_record_set_comment(r,L"SAVEDSKF_OLD");
    case 22954U:return xx_data_struct_record_set_comment(r,L"SAVEDSKF_NEW");
    case 23210U:return xx_data_struct_record_set_comment(r,L"SAVEDSKF_COMPRESSED_LZW");
    default:break;}}
    if(id==0x60330009U&&!xx_rt_wcscmp(r->name,L"disk_type")&&integer){switch(value){
    case 3U:return xx_data_struct_record_set_comment(r,L"720 KiB double-density disk");
    case 4U:return xx_data_struct_record_set_comment(r,L"1.44 MiB high-density disk");
    default:break;}}
    if(id==0x6033000aU&&!xx_rt_wcscmp(r->name,L"method")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored track");
    case 1U:return xx_data_struct_record_set_comment(r,L"Repeated fill byte");
    case 2U:return xx_data_struct_record_set_comment(r,L"Run-length encoded track");
    default:break;}}
    if(id==0x60330010U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 3810328576U:return xx_data_struct_record_set_comment(r,L"Deleted record");
    case 3810328577U:return xx_data_struct_record_set_comment(r,L"Sector record");
    case 3810328578U:return xx_data_struct_record_set_comment(r,L"Comment record");
    case 3810328579U:return xx_data_struct_record_set_comment(r,L"Creator record");
    default:break;}}
    if(id==0x60330010U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 40592U:return xx_data_struct_record_set_comment(r,L"APRIDISK_STORED");
    case 15962U:return xx_data_struct_record_set_comment(r,L"APRIDISK_RLE");
    default:break;}}
    if(id==0x60330011U&&!xx_rt_wcscmp(r->name,L"disk_format")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"400 KiB GCR");
    case 1U:return xx_data_struct_record_set_comment(r,L"800 KiB GCR");
    case 2U:return xx_data_struct_record_set_comment(r,L"720 KiB MFM");
    case 3U:return xx_data_struct_record_set_comment(r,L"1.44 MiB MFM");
    default:break;}}
    if(id==0x60330012U&&!xx_rt_wcscmp(r->name,L"encryption")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unencrypted");
    case 1U:return xx_data_struct_record_set_comment(r,L"Password-protected");
    case 2U:return xx_data_struct_record_set_comment(r,L"AES-128");
    case 3U:return xx_data_struct_record_set_comment(r,L"AES-192");
    case 4U:return xx_data_struct_record_set_comment(r,L"AES-256");
    default:break;}}
    if(id==0x60330027U&&!xx_rt_wcscmp(r->name,L"track_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Sector data");
    case 1U:return xx_data_struct_record_set_comment(r,L"Raw MFM track");
    default:break;}}
    if(id==0x60330033U&&!xx_rt_wcscmp(r->name,L"version")&&integer){switch(value){
    case 65536U:return xx_data_struct_record_set_comment(r,L"Bochs redolog version 1");
    default:break;}}
    if(id==0x60330034U&&!xx_rt_wcscmp(r->name,L"version")&&integer){switch(value){
    case 131072U:return xx_data_struct_record_set_comment(r,L"Bochs redolog version 2");
    default:break;}}
    switch(id){
    case 0x60330002U:
        if(!xx_rt_wcscmp(r->name,L"segment_offset"))s=L"Relative to the end of the index; final entry marks the end of segment data.";
        break;
    case 0x60330003U:
        if(!xx_rt_wcscmp(r->name,L"compressed"))s=L"0 stored; 1 compressed using the header algorithm.";
        break;
    case 0x60330004U:
        if(!xx_rt_wcscmp(r->name,L"properties"))s=L"Encoded LZMA lc/lp/pb properties.";
        break;
    case 0x60330005U:
        if(!xx_rt_wcscmp(r->name,L"media_descriptor"))s=L"Low byte is the FAT media descriptor; upper byte normally zero.";
        else if(!xx_rt_wcscmp(r->name,L"cluster_shift"))s=L"Base-2 logarithm of sectors per cluster.";
        else if(!xx_rt_wcscmp(r->name,L"first_data_sector"))s=L"Logical sector number within the restored disk.";
        else if(!xx_rt_wcscmp(r->name,L"root_directory_sector"))s=L"Logical sector number within the restored disk.";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Stored zero denotes a 512-byte data offset.";
        break;
    case 0x60330007U:
        if(!xx_rt_wcscmp(r->name,L"block_offset"))s=L"Block index relative to the inferred track data area; multiply by block_size for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"status"))s=L"Native reader accepts values 1 and 2; repeated block offsets denote unwritten tracks.";
        break;
    case 0x60330009U:
        if(!xx_rt_wcscmp(r->name,L"disk_type"))s=L"3 is 720 KiB; 4 is 1.44 MiB.";
        else if(!xx_rt_wcscmp(r->name,L"disk_number"))s=L"One-based index in the diskette set.";
        else if(!xx_rt_wcscmp(r->name,L"description_and_banner"))s=L"Physical NUL-padded text area; individual string boundaries are not fixed.";
        break;
    case 0x6033000aU:
        if(!xx_rt_wcscmp(r->name,L"method"))s=L"0 stored track; 1 repeated fill byte; 2 run-length encoded track.";
        break;
    case 0x6033000dU:
        if(!xx_rt_wcscmp(r->name,L"last_cylinder"))s=L"Last zero-based cylinder index, not a count.";
        else if(!xx_rt_wcscmp(r->name,L"track_usage_map"))s=L"One byte per physical track; zero means unwritten and restored as 0xF6.";
        break;
    case 0x6033000eU:
        if(!xx_rt_wcscmp(r->name,L"block_size"))s=L"Encoded bytes after the length, including the escape byte.";
        break;
    case 0x60330010U:
        if(!xx_rt_wcscmp(r->name,L"compression"))s=L"0x9E90 stored; 0x3E5A run-length encoded.";
        break;
    case 0x60330011U:
        if(!xx_rt_wcscmp(r->name,L"private_word"))s=L"DiskCopy private marker 0x0100.";
        break;
    case 0x60330014U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size_and_type"))s=L"XOR-obfuscated packed size/type word; retained exactly as stored.";
        break;
    case 0x60330015U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size_and_type"))s=L"XOR-obfuscated packed size/type word; retained exactly as stored.";
        break;
    case 0x60330016U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size_and_type"))s=L"XOR-obfuscated packed size/type word; retained exactly as stored.";
        break;
    case 0x60330017U:
        if(!xx_rt_wcscmp(r->name,L"encoded_size_and_type"))s=L"XOR-obfuscated packed size/type word; retained exactly as stored.";
        break;
    case 0x60330018U:
        if(!xx_rt_wcscmp(r->name,L"encoded_volume_size"))s=L"XOR-obfuscated u64 volume byte size.";
        else if(!xx_rt_wcscmp(r->name,L"encoded_data_offset"))s=L"XOR-obfuscated file-relative chunk data offset.";
        else if(!xx_rt_wcscmp(r->name,L"encoded_last_chunk_continuation"))s=L"XOR-obfuscated byte count continuing in the next volume.";
        break;
    case 0x60330019U:
        if(!xx_rt_wcscmp(r->name,L"cylinders_and_resolution"))s=L"Low 30 bits: cylinder count; top 2 bits: whole/half/quarter-track resolution.";
        break;
    case 0x6033001aU:
        if(!xx_rt_wcscmp(r->name,L"write_splice"))s=L"Position in MAME angular time units; not a file offset.";
        break;
    case 0x6033001bU:
        if(!xx_rt_wcscmp(r->name,L"device_model"))s=L"GUID in Windows on-disk byte order.";
        else if(!xx_rt_wcscmp(r->name,L"runtime_guid"))s=L"GUID in Windows on-disk byte order.";
        else if(!xx_rt_wcscmp(r->name,L"page_alignment"))s=L"Page size in 512-byte sectors; table begins at one page.";
        break;
    case 0x6033001eU:
        if(!xx_rt_wcscmp(r->name,L"megabyte_size"))s=L"Capacity expressed in megabytes, not bytes.";
        break;
    case 0x60330020U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"1: 256-byte sectors; 2: 128-byte sectors.";
        break;
    case 0x60330023U:
        if(!xx_rt_wcscmp(r->name,L"write_protected"))s=L"0 writable; 0xFF write protected.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit4 single sided; bit6 single-density track bytes are not doubled.";
        else if(!xx_rt_wcscmp(r->name,L"real_disk_flags"))s=L"Native reader supports zero only.";
        break;
    case 0x60330024U:
        if(!xx_rt_wcscmp(r->name,L"offset_and_density"))s=L"Low14 bits are track-relative byte offset; bit15 marks MFM; remaining flag bit retained.";
        break;
    case 0x60330025U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector byte size is 128 shifted left by this code.";
        break;
    case 0x60330027U:
        if(!xx_rt_wcscmp(r->name,L"revolution_count_minus_one"))s=L"Number of captured revolutions minus one for raw MFM tracks.";
        else if(!xx_rt_wcscmp(r->name,L"track_type"))s=L"0 sector data; 1 raw MFM data.";
        else if(!xx_rt_wcscmp(r->name,L"bit_count"))s=L"Number of meaningful bits, not bytes.";
        break;
    case 0x60330029U:
        if(!xx_rt_wcscmp(r->name,L"sync_word"))s=L"Zero selects stored sectors; nonzero is the omitted leading MFM sync word.";
        break;
    case 0x6033002bU:
        if(!xx_rt_wcscmp(r->name,L"track_size"))s=L"Raw track byte count, followed by one to three clock/weak bitmaps.";
        break;
    case 0x6033002cU:
        if(!xx_rt_wcscmp(r->name,L"compressed_size_minus_one"))s=L"Stored compressed byte length minus one.";
        else if(!xx_rt_wcscmp(r->name,L"track_size"))s=L"Uncompressed raw track byte count, excluding bitmaps.";
        break;
    case 0x6033002dU:
        if(!xx_rt_wcscmp(r->name,L"crc32"))s=L"UDI signed-shift CRC32 variant.";
        break;
    case 0x60330030U:
        if(!xx_rt_wcscmp(r->name,L"optimal_bit_timing"))s=L"Multiples of 125 nanoseconds.";
        else if(!xx_rt_wcscmp(r->name,L"creator"))s=L"UTF-8, padded with spaces.";
        else if(!xx_rt_wcscmp(r->name,L"largest_track_blocks"))s=L"Number of 512-byte allocation blocks.";
        else if(!xx_rt_wcscmp(r->name,L"flux_block"))s=L"File-relative block index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"largest_flux_track_blocks"))s=L"Number of 512-byte allocation blocks.";
        break;
    case 0x60330031U:
        if(!xx_rt_wcscmp(r->name,L"track_index"))s=L"0xFF means an unrecorded track.";
        break;
    case 0x60330032U:
        if(!xx_rt_wcscmp(r->name,L"starting_block"))s=L"File-relative 512-byte block index.";
        else if(!xx_rt_wcscmp(r->name,L"bit_count"))s=L"Number of bits for bitstream tracks, or bytes for flux tracks.";
        break;
    case 0x60330034U:
        if(!xx_rt_wcscmp(r->name,L"reserved_timestamp"))s=L"Reserved in Growing images; Undoable mode uses packed FAT date/time, not a Unix timestamp.";
        break;
    case 0x60330035U:
        if(!xx_rt_wcscmp(r->name,L"extent_index"))s=L"0xFFFFFFFF means unallocated; other values select physical extent slots.";
        break;
    case 0x60330036U:
        if(!xx_rt_wcscmp(r->name,L"allocated_sector_bits"))s=L"Low bit is the first 512-byte sector in this group.";
        break;
    case 0x6033003bU:
        if(!xx_rt_wcscmp(r->name,L"general_info"))s=L"Bit1 obfuscated; bit4 high density; bit5 MS-DOS; bit8 FILE_ID.DIZ.";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Unix epoch seconds.";
        else if(!xx_rt_wcscmp(r->name,L"first_track"))s=L"Inclusive track number; header range may be stale in appended archives.";
        else if(!xx_rt_wcscmp(r->name,L"packed_size"))s=L"Header hint; actual track records can differ after appending.";
        else if(!xx_rt_wcscmp(r->name,L"unpacked_size"))s=L"Header hint; actual track records can differ after appending.";
        else if(!xx_rt_wcscmp(r->name,L"creator_version"))s=L"Decimal major*100 plus minor.";
        break;
    case 0x6033003cU:
        if(!xx_rt_wcscmp(r->name,L"track_number"))s=L"80 and values at least 0x8000 are informational tracks.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit0 retains decoder context; bit1 refreshes tables; bit2 selects the final RLE stage in Heavy modes.";
        break;
    case 0x6033003fU:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Logical sector address, not a file byte offset.";
        break;
    case 0x60330042U:
        if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Logical sector address, not a file byte offset.";
        break;
    case 0x60330044U:
        if(!xx_rt_wcscmp(r->name,L"size_word"))s=L"Producer-specific header word retained as bytes; not used by the native extent parser.";
        else if(!xx_rt_wcscmp(r->name,L"session_type"))s=L"0 CD-DA/CD-ROM; 0x10 CD-I; 0x20 CD-ROM XA.";
        break;
    case 0x60330045U:
        if(!xx_rt_wcscmp(r->name,L"track_bcd"))s=L"Packed binary-coded decimal track number.";
        else if(!xx_rt_wcscmp(r->name,L"index_bcd"))s=L"Packed binary-coded decimal index number.";
        else if(!xx_rt_wcscmp(r->name,L"start_lba"))s=L"Signed logical sector address; pregap entries may be negative.";
        break;
    case 0x60330049U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit0 identifies a root extent; clear selects child/parent-name metadata.";
        else if(!xx_rt_wcscmp(r->name,L"capacity_sectors"))s=L"Logical sectors of 512 bytes each.";
        else if(!xx_rt_wcscmp(r->name,L"directory_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"next_free_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        break;
    case 0x6033004dU:
        if(!xx_rt_wcscmp(r->name,L"table_sector"))s=L"File-relative sector index; multiply by 512 for bytes. Zero means unallocated.";
        break;
    case 0x6033004eU:
        if(!xx_rt_wcscmp(r->name,L"grain_sector"))s=L"File-relative sector index; multiply by 512 for bytes. Zero means unallocated or supplied by a parent.";
        break;
    case 0x6033004fU:
        if(!xx_rt_wcscmp(r->name,L"volatile_header_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"volatile_header_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"journal_header_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"journal_header_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"journal_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"journal_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"grain_directory_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"grain_directory_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"grain_tables_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"grain_tables_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"free_bitmap_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"free_bitmap_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"back_map_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"back_map_sectors"))s=L"Number of 512-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"grains_sector"))s=L"File-relative sector index; multiply by 512 for bytes.";
        else if(!xx_rt_wcscmp(r->name,L"grains_sectors"))s=L"Number of 512-byte sectors.";
        break;
    case 0x60330051U:
        if(!xx_rt_wcscmp(r->name,L"table_index_and_flags"))s=L"Zero is unallocated; 0x10000000 in the high word identifies a low32-bit table index.";
        break;
    case 0x60330052U:
        if(!xx_rt_wcscmp(r->name,L"grain_index_and_type"))s=L"High nibble: 0 unallocated, 1 unmapped, 2 zero, 3 allocated; allocated index uses bits48..59 as low12 and bits0..47 as upper bits.";
        break;
    case 0x60330053U:
        if(!xx_rt_wcscmp(r->name,L"id_address_mark_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"head_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"sector_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"size_code_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_copy"))s=L"Duplicated single-density byte, preserved at its physical offset.";
        break;
    case 0x60330054U:
        if(!xx_rt_wcscmp(r->name,L"allocated_bits"))s=L"Physical bitmap byte; big-endian images reverse byte positions within cpu_bits-sized bitmap words.";
        break;
    case 0x60330055U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Stored checksum of a used-block group; exact wire bytes retained.";
        break;
    case 0x60330056U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Stored checksum of a used-block group; exact wire bytes retained.";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Bounded wire metadata only. Optional damaged extents and display-budget
 * remainder stay raw. No native subclass casts or factory dependencies. */
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
static bool sxsl_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxsl_read(sx_context*c,uint64_t p,void*b,size_t n){return sxsl_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxsl_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint16_t sxsl16(const uint8_t*b){return (uint16_t)sxsl_uint(b,2,false);}
static uint32_t sxsl32(const uint8_t*b){return (uint32_t)sxsl_uint(b,4,false);}
static bool sxsl_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(n>8||!sxsl_read(c,p,b,n))return false;*v=sxsl_uint(b,n,be);return true;}
/* Keep metadata sorted as it is collected. Monotonic sector tables take
 * O(log n) overlap checks; out-of-order optional pointers insert in place. */
static bool sxsl_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 const xx_data_struct_field_desc*f=l->fields+l->field_count-1;
 uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!n)return true;
 if(n>SXSL_ROWS||n>(uint64_t)INT64_MAX/z||!sxsl_span(c,p,n*z))return false;
 if(xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXSL_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&c->items[lo-1].offset-c->f->base_address+c->items[lo-1].total_size>(int64_t)p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}
 return true;
}
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_lofi(sx_context*c){uint8_t h[48];if(!sxsl_read(c,0,h,48)||!SXSL_ADD(c,lofi_header,0))return false;uint64_t n=sxsl_uint(h+40,4,true),base=48+n*8;if(n<2||n>SXSL_ROWS||!SXSL_TABLE(c,lofi_index,48,n))return true;bool lzma=!xx_rt_memcmp(h,"lzma",4);for(uint64_t i=0;i+1<n&&c->count<SXSL_LIMIT;i++){uint64_t a,b;uint8_t flag;if(!sxsl_word(c,48+i*8,8,true,&a)||!sxsl_word(c,56+i*8,8,true,&b)||a>b||b>(uint64_t)c->size-base||!sxsl_read(c,base+a,&flag,1)||!SXSL_ADD(c,lofi_segment,base+a))break;if(flag==1&&lzma&&b-a>=14&&!SXSL_ADD(c,lofi_lzma_header,base+a+1))return false;}return true;}
static bool sxsl_dms(sx_context*c){uint8_t b[88];uint64_t p=0;if(!sxsl_read(c,0,b,56))return false;if(xx_rt_memcmp(b,"DMS!",4)){if(!sxsl_read(c,0,b,88)||sxsl_uint(b,4,true)!=0x3f3)return false;uint64_t kind=sxsl_uint(b+20,4,true);p=kind==0x1605?0x58c4:kind==0x2462?0x45d0:kind==0x2466?0x45e0:kind==0x3269?0x537c:0;if(!p||!sxsl_read(c,p,b,56)||xx_rt_memcmp(b,"DMS!",4))return false;}if(!SXSL_ADD(c,dms_header,p))return false;p+=56;for(unsigned i=0;i<SXSL_LIMIT&&c->count<SXSL_LIMIT;i++){if(!sxsl_read(c,p,b,20)||xx_rt_memcmp(b,"TR",2))break;uint64_t z=sxsl_uint(b+6,2,true);if(!sxsl_span(c,p+20,z)||!SXSL_ADD(c,dms_track,p))break;p+=20+z;}return true;}
static bool sxsl_diskdupe(sx_context*c){uint8_t b[72];return sxsl_read(c,0,b,72)&&SXSL_ADD(c,diskdupe_header,0)&&SXSL_TABLE(c,diskdupe_track,72,b[67]);}
static bool sxsl_qrst(sx_context*c){uint64_t p=0;uint8_t h[15],b[5];for(unsigned image=0;image<128&&c->count<SXSL_LIMIT;image++){if(!sxsl_read(c,p,h,15)||xx_rt_memcmp(h,"QRST",4)||!sxsl_span(c,p,796))break;if(!SXSL_ADD(c,qrst_header,p))return false;if(sxsl32(h+4)!=0x3f800000||(h[12]!=3&&h[12]!=4))break;uint64_t track=h[12]==3?4608:9216;p+=796;bool ok=true;for(unsigned i=0;i<160;i++){if(!sxsl_read(c,p,b,3)){ok=false;break;}uint64_t data=b[2]==0?track:b[2]==1?1:0;if(b[2]==2){if(!sxsl_read(c,p,b,5)){ok=false;break;}data=2+sxsl16(b+3);}else if(b[2]>1){ok=false;break;}if(!sxsl_span(c,p+3,data)){ok=false;break;}if(!SXSL_ADD(c,qrst_track,p)||(b[2]==1&&!SXSL_ADD(c,qrst_fill,p+3))||(b[2]==2&&!SXSL_ADD(c,qrst_encoded_size,p+3)))return false;p+=3+data;}if(!ok)break;}return c->count>0;}
static bool sxsl_hdcopy(sx_context*c){uint8_t b[184];if(!sxsl_read(c,0,b,184)||!SXSL_ADD(c,hdcopy_header,0))return false;uint64_t p=184;unsigned n=((unsigned)b[14]+1)*2;if(n>168)return true;for(unsigned i=0;i<n&&c->count<SXSL_LIMIT;i++)if(b[16+i]){uint64_t z;if(!sxsl_word(c,p,2,false,&z)||z<1||!sxsl_span(c,p+2,z)||!SXSL_ADD(c,hdcopy_block,p))break;p+=2+z;}return true;}
static bool sxsl_apridisk(sx_context*c){if(!SXSL_ADD(c,apridisk_header,0))return false;uint64_t p=128;uint8_t b[16];for(unsigned i=0;i<SXSL_LIMIT&&c->count<SXSL_LIMIT;i++){if(!sxsl_read(c,p,b,16))break;uint64_t h=sxsl16(b+6),z=sxsl32(b+8);if(h<16||!sxsl_span(c,p,h+z)||!SXSL_ADD(c,apridisk_record,p))break;p+=h+z;}return true;}
static bool sxsl_nrg(sx_context*c){uint8_t b[12];uint64_t end=(uint64_t)c->size,p;if(end>=12&&sxsl_read(c,end-12,b,12)&&!xx_rt_memcmp(b,"NER5",4)){p=sxsl_uint(b+4,8,true);if(!SXSL_ADD(c,nrg_footer64,end-12))return false;end-=12;}else if(end>=8&&sxsl_read(c,end-8,b,8)&&!xx_rt_memcmp(b,"NERO",4)){p=sxsl_uint(b+4,4,true);if(!SXSL_ADD(c,nrg_footer32,end-8))return false;end-=8;}else return false;for(unsigned i=0;i<SXSL_LIMIT&&p<end&&c->count<SXSL_LIMIT;i++){if(end-p<8||!sxsl_read(c,p,b,8))break;uint64_t n=sxsl_uint(b+4,4,true),q=p+8;if(n>end-q||!SXSL_ADD(c,nrg_chunk,p))break;const sx_layout*l=NULL;uint64_t z=0,skip=0;if(!xx_rt_memcmp(b,"DAOX",4)||!xx_rt_memcmp(b,"DAOI",4)){z=b[3]=='X'?42:30;skip=22;l=b[3]=='X'?&sxsl_nrg_dao_track64:&sxsl_nrg_dao_track32;if(n>=22&&!SXSL_ADD(c,nrg_dao_header,q))return false;}else if(!xx_rt_memcmp(b,"ETN2",4)||!xx_rt_memcmp(b,"ETNF",4)){z=b[3]=='2'?32:20;l=b[3]=='2'?&sxsl_nrg_etn_track64:&sxsl_nrg_etn_track32;}else if(!xx_rt_memcmp(b,"CUEX",4)||!xx_rt_memcmp(b,"CUES",4)){z=8;l=b[3]=='X'?&sxsl_nrg_cuex:&sxsl_nrg_cues;}else if(!xx_rt_memcmp(b,"SINF",4)&&n==4){z=4;l=&sxsl_nrg_session;}else if(!xx_rt_memcmp(b,"MTYP",4)&&n==4){z=4;l=&sxsl_nrg_media;}if(l&&n>=skip&&(n-skip)%z==0&&(n-skip)/z<=SXSL_ROWS&&!sxsl_put(c,l,q+skip,(n-skip)/z))return false;p=q+n;if(!xx_rt_memcmp(b,"END!",4))break;}return true;}
static bool sxsl_isz(sx_context*c){uint8_t h[48],b[24];if(!sxsl_read(c,0,h,48)||!SXSL_ADD(c,isz_header,0))return false;if(h[4]>=64&&sxsl_span(c,48,16)&&!SXSL_ADD(c,isz_checksum_tail,48))return false;uint64_t p=sxsl32(h+35),n=sxsl32(h+25);unsigned w=h[33];const sx_layout*ls[]={&sxsl_isz_encoded_pointer1,&sxsl_isz_encoded_pointer2,&sxsl_isz_encoded_pointer3,&sxsl_isz_encoded_pointer4};if(p>=h[4]&&w>=1&&w<=4&&n<=SXSL_ROWS&&sxsl_span(c,p,n*w)&&!sxsl_put(c,ls[w-1],p,n))return false;p=sxsl32(h+39);if(p>=h[4])for(unsigned i=0;i<1024&&c->count<SXSL_LIMIT;i++){if(!sxsl_read(c,p,b,24))break;if(!SXSL_ADD(c,isz_encoded_segment,p))return false;for(unsigned j=0;j<24;j++)b[j]^=(uint8_t)~"IsZ!"[j%4];if(!sxsl_uint(b,8,false))break;p+=24;}return true;}
static bool sxsl_mfi(sx_context*c){uint8_t b[32];if(!sxsl_read(c,0,b,32)||!SXSL_ADD(c,mfi_header,0))return false;uint64_t n=(sxsl32(b+16)&0x3fffffffU),heads=sxsl32(b+20);unsigned shift=sxsl32(b+16)>>30;if(shift>2||heads>2||n>256)return true;n*=heads*(1U<<shift);return !sxsl_span(c,32,n*16)||SXSL_TABLE(c,mfi_track,32,n);}
static bool sxsl_sdi(sx_context*c){uint64_t page;uint8_t b[8];if(!SXSL_ADD(c,sdi_header,0)||!sxsl_word(c,112,8,false,&page))return false;if(!page||page>2048)return true;page*=512;for(uint64_t p=page;p+64<=2*page&&c->count<SXSL_LIMIT;p+=64){if(!sxsl_read(c,p,b,8))break;uint64_t tag=sxsl_uint(b,8,false);if(!tag)break;if(!SXSL_ADD(c,sdi_section,p))return false;}return true;}
static bool sxsl_sap(sx_context*c){uint8_t version;if(!sxsl_read(c,0,&version,1)||!SXSL_ADD(c,sap_header,0))return false;uint64_t z=version==1?256:version==2?128:0,n=version==1?1280:640;if(!z)return true;for(uint64_t i=0;i<n&&c->count<SXSL_LIMIT;i++){uint64_t p=66+i*(z+6);if(!sxsl_span(c,p,z+6))break;if(!SXSL_ADD(c,sap_sector,p)||!SXSL_ADD(c,sap_checksum,p+4+z))return false;}return true;}
static bool sxsl_dmk(sx_context*c){uint8_t h[16];if(!sxsl_read(c,0,h,16)||!SXSL_ADD(c,dmk_header,0))return false;uint64_t z=sxsl16(h+2),n=(uint64_t)h[1]*((h[4]&16)?1:2);if(z<=128||z>=16384)return true;for(uint64_t i=0;i<n&&c->count<SXSL_LIMIT;i++){uint64_t p=16+i*z;if(!sxsl_span(c,p,z))break;if(!SXSL_TABLE(c,dmk_idam_pointer,p,64))return false;for(unsigned j=0;j<64&&c->count<SXSL_LIMIT;j++){uint64_t w;if(!sxsl_word(c,p+2*j,2,false,&w)||!w)break;uint64_t q=w&0x3fff,step=(w&0x8000)||(h[4]&64)?1:2;if(q<128||q+7*step>z)continue;if(!sxsl_put(c,step==1?&sxsl_dmk_idam:&sxsl_dmk_idam_doubled,p+q,1))return false;}}return true;}
static bool sxsl_extadf(sx_context*c,bool old){uint64_t n;if(old)return SXSL_ADD(c,oldextadf_header,0)&&SXSL_TABLE(c,oldextadf_track,8,160);if(!SXSL_ADD(c,extadf_header,0)||!sxsl_word(c,10,2,true,&n))return false;return n<=340&&SXSL_TABLE(c,extadf_track,12,n);}
static bool sxsl_udi(sx_context*c){uint8_t h[16],b[6];if(!sxsl_read(c,0,h,16)||!SXSL_ADD(c,udi_header,0))return false;uint64_t end=sxsl32(h+4),p=16+(uint64_t)sxsl32(h+12),n=((uint64_t)h[9]+1)*(h[10]+1);if(end>=(uint64_t)c->size||!sxsl_span(c,end,4)||p>end||n>512)return true;if(!SXSL_ADD(c,udi_checksum,end))return false;for(uint64_t i=0;i<n&&c->count<SXSL_LIMIT;i++){if(p>end||end-p<3||!sxsl_read(c,p,b,3))break;uint64_t z;if(b[0]==0xf0){if(end-p<6||!sxsl_read(c,p,b,6))break;z=6+(uint64_t)sxsl16(b+1)+1;if(z>end-p||!SXSL_ADD(c,udi_compressed_track,p))break;}else{unsigned maps=b[0]<=1?1:b[0]==2||b[0]==0x80||b[0]==0x81?2:b[0]==0x82?3:0;uint64_t raw=sxsl16(b+1);if(!maps)break;z=3+raw+(raw+7)/8*maps;if(z>end-p||!SXSL_ADD(c,udi_track,p))break;}p+=z;}return true;}
static bool sxsl_moof(sx_context*c){uint8_t b[8];uint64_t p=12;if(!SXSL_ADD(c,moof_header,0))return false;for(unsigned i=0;i<4096&&c->count<SXSL_LIMIT;i++){if(!sxsl_read(c,p,b,8)||!sxsl32(b))break;uint64_t z=sxsl32(b+4),q=p+8;if(!sxsl_span(c,q,z)||!SXSL_ADD(c,moof_chunk,p))break;if(!xx_rt_memcmp(b,"INFO",4)&&z>=44){if(!SXSL_ADD(c,moof_info,q))return false;}else if((!xx_rt_memcmp(b,"TMAP",4)||!xx_rt_memcmp(b,"FLUX",4))&&z>=160){if(!SXSL_TABLE(c,moof_track_map,q,160))return false;}else if(!xx_rt_memcmp(b,"TRKS",4)&&z>=1280){if(!SXSL_TABLE(c,moof_track,q,160))return false;}p=q+z;}return true;}
static bool sxsl_bochs(sx_context*c){uint8_t h[96];if(!sxsl_read(c,0,h,96))return false;uint32_t v=sxsl32(h+64);if(v!=0x10000&&v!=0x20000)return false;if(!sxsl_put(c,v==0x10000?&sxsl_bochs_growing_v1:&sxsl_bochs_growing_v2,0,1))return false;uint64_t n=sxsl32(h+72),bitmap=sxsl32(h+76),extent=sxsl32(h+80);if(n>SXSL_ROWS||!bitmap||bitmap>4096||extent!=bitmap*4096||!sxsl_span(c,512,n*4)||!SXSL_TABLE(c,bochs_catalog_entry,512,n))return true;uint64_t base=512+n*4,slot=((bitmap+511)/512)*512+extent;for(uint64_t i=0;i<n&&c->count<SXSL_LIMIT;i++){uint64_t index;if(!sxsl_word(c,512+4*i,4,false,&index))return false;if(index==UINT32_MAX)continue;if(index>((uint64_t)c->size-base)/slot)continue;uint64_t p=base+index*slot;if(sxsl_span(c,p,bitmap)&&!SXSL_TABLE(c,bochs_bitmap_byte,p,bitmap))return false;}return true;}
static bool sxsl_cowd(sx_context*c){uint8_t h[32];if(!sxsl_read(c,0,h,32)||!SXSL_ADD(c,cowd_header,0))return false;uint64_t gd=(uint64_t)sxsl32(h+20)*512,n=sxsl32(h+24),capacity=sxsl32(h+12),grain=sxsl32(h+16);if(gd>=2048&&sxsl_span(c,32,2016)){if(!sxsl_put(c,(sxsl32(h+8)&1)?&sxsl_cowd_root:&sxsl_cowd_child,32,1)||!SXSL_ADD(c,cowd_tail,1060))return false;}if(!grain||!capacity)return true;uint64_t needed=(capacity+grain*4096-1)/(grain*4096);if(n<needed||needed>SXSL_ROWS||gd<32||!sxsl_span(c,gd,needed*4)||!SXSL_TABLE(c,cowd_directory,gd,needed))return true;for(uint64_t i=0;i<needed&&c->count<SXSL_LIMIT;i++){uint64_t p;if(!sxsl_word(c,gd+i*4,4,false,&p))return false;p*=512;if(p>=32&&sxsl_span(c,p,16384)&&!SXSL_TABLE(c,cowd_grain,p,4096))return false;}return true;}
static bool sxsl_sesparse(sx_context*c){uint8_t h[208];if(!sxsl_read(c,0,h,208)||!SXSL_ADD(c,sesparse_header,0))return false;uint64_t v=sxsl_uint(h+80,8,false),gd=sxsl_uint(h+128,8,false),gs=sxsl_uint(h+136,8,false),tables=sxsl_uint(h+144,8,false),table_size=sxsl_uint(h+152,8,false),cap=sxsl_uint(h+16,8,false),grain=sxsl_uint(h+24,8,false);if(v<=(uint64_t)c->size/512&&sxsl_span(c,v*512,512)&&!SXSL_ADD(c,sesparse_volatile,v*512))return false;if(!grain||grain>UINT64_MAX/4096)return true;uint64_t cover=grain*4096,needed=cap/cover+(cap%cover!=0);if(needed>SXSL_ROWS||gd>(uint64_t)c->size/512||gs>UINT64_MAX/512||needed>gs*64||!sxsl_span(c,gd*512,needed*8)||!SXSL_TABLE(c,sesparse_directory,gd*512,needed))return true;for(uint64_t i=0;i<needed&&c->count<SXSL_LIMIT;i++){uint64_t word;if(!sxsl_word(c,gd*512+8*i,8,false,&word))return false;if((word>>32)!=0x10000000)continue;uint64_t index=(uint32_t)word;if(index>=table_size/64||tables>UINT64_MAX-index*64)continue;uint64_t p=tables+index*64;if(p<=(uint64_t)c->size/512&&sxsl_span(c,p*512,32768)&&!SXSL_TABLE(c,sesparse_grain,p*512,4096))return false;}return true;}
static bool sxsl_partclone(sx_context*c){uint8_t h[110];if(!sxsl_read(c,0,h,110))return false;bool be=h[34]==0xc0&&h[35]==0xde;if(!sxsl_put(c,be?&sxsl_partclone_header_be:&sxsl_partclone_header_le,0,1))return false;uint64_t total=sxsl_uint(h+60,8,be),used=sxsl_uint(h+76,8,be),block=sxsl_uint(h+84,4,be),per=sxsl_uint(h+100,4,be),cs=sxsl_uint(h+98,2,be),map=total/8+(total%8!=0);if(!sxsl_span(c,110,map)||!sxsl_span(c,110+map,4))return true;if(map<=SXSL_ROWS&&!SXSL_TABLE(c,partclone_bitmap_byte,110,map))return false;if(!sxsl_put(c,be?&sxsl_partclone_bitmap_crc_be:&sxsl_partclone_bitmap_crc_le,110+map,1))return false;if(!per||!block||(cs!=4&&cs!=16))return true;uint64_t p=114+map;for(unsigned i=0;used&&i<SXSL_LIMIT&&c->count<SXSL_LIMIT;i++){uint64_t n=used<per?used:per;if(n>UINT64_MAX/block||!sxsl_span(c,p,n*block)||!sxsl_span(c,p+n*block,cs))break;p+=n*block;if(!sxsl_put(c,cs==4?&sxsl_partclone_data_checksum4:&sxsl_partclone_data_checksum16,p,1))return false;p+=cs;used-=n;}return true;}
static int sxsl_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxsl_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsl_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsl_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_systemlater_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_LOFI:
case XX_FILE_TYPE_DMS:
case XX_FILE_TYPE_SAVEDSKF:
case XX_FILE_TYPE_DISKDUPE:
case XX_FILE_TYPE_PMDISKCOPY:
case XX_FILE_TYPE_QRST:
case XX_FILE_TYPE_HDCOPY:
case XX_FILE_TYPE_APRIDISK:
case XX_FILE_TYPE_DISKCOPY42:
case XX_FILE_TYPE_NRG:
case XX_FILE_TYPE_ISZ:
case XX_FILE_TYPE_MAME_FLOPPY_IMAGE_MFI:
case XX_FILE_TYPE_SDI:
case XX_FILE_TYPE_NHD:
case XX_FILE_TYPE_VIRTUAL98:
case XX_FILE_TYPE_ANEX86_HDI:
case XX_FILE_TYPE_THOMSON_SAP:
case XX_FILE_TYPE_DMK:
case XX_FILE_TYPE_AMIGA_EXT_ADF:
case XX_FILE_TYPE_AMIGA_OLD_EXT_ADF:
case XX_FILE_TYPE_SPECTRUM_UDI:
case XX_FILE_TYPE_MOOF:
case XX_FILE_TYPE_BOCHS_GROWING:
case XX_FILE_TYPE_VMDK_COWD_SPARSE:
case XX_FILE_TYPE_VMDK_SESPARSE:
case XX_FILE_TYPE_PARTCLONE_IMAGE:
return true;default:return false;}}
static bool sx_systemlater_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_LOFI:ok=sxsl_lofi(c);break;
case XX_FILE_TYPE_DMS:ok=sxsl_dms(c);break;
case XX_FILE_TYPE_SAVEDSKF:ok=SXSL_ADD(c,savedskf_header,0);break;
case XX_FILE_TYPE_DISKDUPE:ok=sxsl_diskdupe(c);break;
case XX_FILE_TYPE_PMDISKCOPY:ok=SXSL_ADD(c,pmdiskcopy_header,0);break;
case XX_FILE_TYPE_QRST:ok=sxsl_qrst(c);break;
case XX_FILE_TYPE_HDCOPY:ok=sxsl_hdcopy(c);break;
case XX_FILE_TYPE_APRIDISK:ok=sxsl_apridisk(c);break;
case XX_FILE_TYPE_DISKCOPY42:ok=SXSL_ADD(c,diskcopy42_header,0);break;
case XX_FILE_TYPE_NRG:ok=sxsl_nrg(c);break;
case XX_FILE_TYPE_ISZ:ok=sxsl_isz(c);break;
case XX_FILE_TYPE_MAME_FLOPPY_IMAGE_MFI:ok=sxsl_mfi(c);break;
case XX_FILE_TYPE_SDI:ok=sxsl_sdi(c);break;
case XX_FILE_TYPE_NHD:ok=SXSL_ADD(c,nhd_header,0);break;
case XX_FILE_TYPE_VIRTUAL98:ok=SXSL_ADD(c,virtual98_header,0);break;
case XX_FILE_TYPE_ANEX86_HDI:ok=SXSL_ADD(c,anex86_header,0);break;
case XX_FILE_TYPE_THOMSON_SAP:ok=sxsl_sap(c);break;
case XX_FILE_TYPE_DMK:ok=sxsl_dmk(c);break;
case XX_FILE_TYPE_AMIGA_EXT_ADF:ok=sxsl_extadf(c,false);break;
case XX_FILE_TYPE_AMIGA_OLD_EXT_ADF:ok=sxsl_extadf(c,true);break;
case XX_FILE_TYPE_SPECTRUM_UDI:ok=sxsl_udi(c);break;
case XX_FILE_TYPE_MOOF:ok=sxsl_moof(c);break;
case XX_FILE_TYPE_BOCHS_GROWING:ok=sxsl_bochs(c);break;
case XX_FILE_TYPE_VMDK_COWD_SPARSE:ok=sxsl_cowd(c);break;
case XX_FILE_TYPE_VMDK_SESPARSE:ok=sxsl_sesparse(c);break;
case XX_FILE_TYPE_PARTCLONE_IMAGE:ok=sxsl_partclone(c);break;
default:break;}return ok&&sxsl_finish(c);}
