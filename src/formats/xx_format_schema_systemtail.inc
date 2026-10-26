/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical disk-container metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_systemtail_scope.txt. */

static const xx_data_struct_field_desc sxst_irixsa_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("reserved","byte[24]",8,24,SX_RESERVED),
};
static const sx_layout sxst_irixsa_header = {0x60370001U,"irixsa_header",sxst_irixsa_header_fields,SX_COUNT(sxst_irixsa_header_fields),SX_BE};

static const xx_data_struct_field_desc sxst_irixsa_directory_entry_fields[] = {
    SX_FIELD("name","char[16]",0,16,SX_NONE),
    SX_FIELD("first_block","uint32",16,4,SX_NONE),
    SX_FIELD("byte_size","uint32",20,4,SX_SIZE),
};
static const sx_layout sxst_irixsa_directory_entry = {0x60370002U,"irixsa_directory_entry",sxst_irixsa_directory_entry_fields,SX_COUNT(sxst_irixsa_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxst_sos_boot_prefix_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("filesystem_flags","uint8",3,1,SX_FLAGS),
    SX_FIELD("boot_checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("root_block","uint32",8,4,SX_NONE),
    SX_FIELD("loader_code","byte[4]",12,4,SX_NONE),
    SX_FIELD("loader_signature","char[4]",16,4,SX_SIGNATURE),
};
static const sx_layout sxst_sos_boot_prefix = {0x60370003U,"sos_boot_prefix",sxst_sos_boot_prefix_fields,SX_COUNT(sxst_sos_boot_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sxst_sos_directory_entry_fields[] = {
    SX_FIELD("data_offset","int32",0,4,SX_OFFSET),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("name","char[24]",8,24,SX_NONE),
};
static const sx_layout sxst_sos_directory_entry = {0x60370004U,"sos_directory_entry",sxst_sos_directory_entry_fields,SX_COUNT(sxst_sos_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxst_zoom_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("first_cylinder","uint8",4,1,SX_NONE),
    SX_FIELD("last_cylinder","uint8",5,1,SX_NONE),
    SX_FIELD("version","uint8",6,1,SX_ID),
    SX_FIELD("unknown_07","byte[21]",7,21,SX_NONE),
    SX_FIELD("note_size","uint32",28,4,SX_SIZE),
    SX_FIELD("unknown_20","byte[4]",32,4,SX_NONE),
    SX_FIELD("password_protected","uint8",36,1,SX_FLAGS),
    SX_FIELD("unknown_25","byte[35]",37,35,SX_NONE),
    SX_FIELD("header_checksum","uint32",72,4,SX_CHECKSUM),
};
static const sx_layout sxst_zoom_header = {0x60370005U,"zoom_header",sxst_zoom_header_fields,SX_COUNT(sxst_zoom_header_fields),SX_BE};

static const xx_data_struct_field_desc sxst_zoom_note_checksum_fields[] = {
    SX_FIELD("note_checksum","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxst_zoom_note_checksum = {0x60370006U,"zoom_note_checksum",sxst_zoom_note_checksum_fields,SX_COUNT(sxst_zoom_note_checksum_fields),SX_BE};

static const xx_data_struct_field_desc sxst_zoom_chunk_fields[] = {
    SX_FIELD("cylinders","uint8[5]",0,5,SX_NONE),
    SX_FIELD("unknown_05","uint8",5,1,SX_NONE),
    SX_FIELD("sector_masks","uint32[5]",6,20,SX_FLAGS),
    SX_FIELD("packed_size","uint16",26,2,SX_SIZE),
    SX_FIELD("middle_size","uint16",28,2,SX_SIZE),
    SX_FIELD("final_size","uint16",30,2,SX_SIZE),
    SX_FIELD("lzhuf_flag","uint16",32,2,SX_FLAGS),
    SX_FIELD("unknown_22","byte[8]",34,8,SX_NONE),
};
static const sx_layout sxst_zoom_chunk = {0x60370007U,"zoom_chunk",sxst_zoom_chunk_fields,SX_COUNT(sxst_zoom_chunk_fields),SX_BE};

static const xx_data_struct_field_desc sxst_trdos_entry_fields[] = {
    SX_FIELD("name","char[8]",0,8,SX_NONE),
    SX_FIELD("extension","char[1]",8,1,SX_ID),
    SX_FIELD("start_address","uint16",9,2,SX_ADDRESS),
    SX_FIELD("byte_length","uint16",11,2,SX_SIZE),
    SX_FIELD("sector_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("first_sector","uint8",14,1,SX_NONE),
    SX_FIELD("first_track","uint8",15,1,SX_NONE),
};
static const sx_layout sxst_trdos_entry = {0x60370008U,"trdos_entry",sxst_trdos_entry_fields,SX_COUNT(sxst_trdos_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxst_trdos_disk_descriptor_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
    SX_FIELD("first_free_sector","uint8",1,1,SX_NONE),
    SX_FIELD("first_free_track","uint8",2,1,SX_NONE),
    SX_FIELD("disk_type","uint8",3,1,SX_ID),
    SX_FIELD("file_count","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("free_sector_count","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("identifier","uint8",7,1,SX_SIGNATURE),
};
static const sx_layout sxst_trdos_disk_descriptor = {0x60370009U,"trdos_disk_descriptor",sxst_trdos_disk_descriptor_fields,SX_COUNT(sxst_trdos_disk_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxst_csidos_root_block_fields[] = {
    SX_FIELD("catalogue_block","uint16",0,2,SX_NONE),
    SX_FIELD("volume_blocks","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("signature1","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("signature2","uint16",6,2,SX_SIGNATURE),
    SX_FIELD("low_signature_or_state","uint8",8,1,SX_NONE),
    SX_FIELD("signature_high","uint8",9,1,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",10,2,SX_RESERVED),
};
static const sx_layout sxst_csidos_root_block = {0x6037000aU,"csidos_root_block",sxst_csidos_root_block_fields,SX_COUNT(sxst_csidos_root_block_fields),SX_LE};

static const xx_data_struct_field_desc sxst_csidos_catalogue_block_fields[] = {
    SX_FIELD("catalogue_block","uint16",0,2,SX_NONE),
    SX_FIELD("opaque_header","byte[10]",2,10,SX_NONE),
};
static const sx_layout sxst_csidos_catalogue_block = {0x6037000bU,"csidos_catalogue_block",sxst_csidos_catalogue_block_fields,SX_COUNT(sxst_csidos_catalogue_block_fields),SX_LE};

static const xx_data_struct_field_desc sxst_csidos_entry_fields[] = {
    SX_FIELD("parent_directory","uint16",0,2,SX_ID),
    SX_FIELD("name","char[8]",2,8,SX_NONE),
    SX_FIELD("extension","char[3]",10,3,SX_NONE),
    SX_FIELD("attributes_or_directory_id","uint8",13,1,SX_FLAGS),
    SX_FIELD("first_block","uint16",14,2,SX_NONE),
    SX_FIELD("load_address","uint16",16,2,SX_ADDRESS),
    SX_FIELD("byte_length","uint16",18,2,SX_SIZE),
};
static const sx_layout sxst_csidos_entry = {0x6037000cU,"csidos_entry",sxst_csidos_entry_fields,SX_COUNT(sxst_csidos_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxst_copydisk_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("bytes_per_sector","uint16",8,2,SX_SIZE),
    SX_FIELD("geometry_hints","byte[22]",10,22,SX_NONE),
};
static const sx_layout sxst_copydisk_header = {0x6037000dU,"copydisk_header",sxst_copydisk_header_fields,SX_COUNT(sxst_copydisk_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_apricot_image_header_fields[] = {
    SX_FIELD("signature","char[22]",0,22,SX_SIGNATURE),
    SX_FIELD("opaque_preamble","byte[106]",22,106,SX_NONE),
};
static const sx_layout sxst_apricot_image_header = {0x6037000eU,"apricot_image_header",sxst_apricot_image_header_fields,SX_COUNT(sxst_apricot_image_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_apricot_chunk_fields[] = {
    SX_FIELD("kind","uint16",0,2,SX_ID),
    SX_FIELD("tag","uint16",2,2,SX_SIGNATURE),
    SX_FIELD("subtype","uint16",4,2,SX_ID),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("data_size","int32",8,4,SX_SIZE),
    SX_FIELD("unknown_0c","byte[4]",12,4,SX_NONE),
};
static const sx_layout sxst_apricot_chunk = {0x6037000fU,"apricot_chunk",sxst_apricot_chunk_fields,SX_COUNT(sxst_apricot_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxst_apricot_run_fields[] = {
    SX_FIELD("repeat_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("value","uint8",2,1,SX_ID),
};
static const sx_layout sxst_apricot_run = {0x60370010U,"apricot_run",sxst_apricot_run_fields,SX_COUNT(sxst_apricot_run_fields),SX_LE};

static const xx_data_struct_field_desc sxst_sabdu_header_fields[] = {
    SX_FIELD("signature","char[21]",0,21,SX_SIGNATURE),
    SX_FIELD("version","char[4]",21,4,SX_NONE),
    SX_FIELD("terminator","uint8",25,1,SX_RESERVED),
    SX_FIELD("flags","uint16",26,2,SX_FLAGS),
    SX_FIELD("disk_type","uint16",28,2,SX_ID),
    SX_FIELD("cylinders","uint16",30,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("current_cylinder","uint16",36,2,SX_NONE),
    SX_FIELD("current_head","uint16",38,2,SX_NONE),
    SX_FIELD("current_sector","uint16",40,2,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",42,2,SX_SIZE),
    SX_FIELD("bytes_per_track","uint16",44,2,SX_SIZE),
};
static const sx_layout sxst_sabdu_header = {0x60370011U,"sabdu_header",sxst_sabdu_header_fields,SX_COUNT(sxst_sabdu_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_adam_volume_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
    SX_FIELD("directory_blocks_and_protection","uint8",12,1,SX_FLAGS),
    SX_FIELD("directory_check","uint32",13,4,SX_SIGNATURE),
    SX_FIELD("volume_blocks","uint32",17,4,SX_COUNT_PROP),
    SX_FIELD("unknown_15","byte[2]",21,2,SX_NONE),
    SX_FIELD("year_bcd","uint8",23,1,SX_NONE),
    SX_FIELD("month_bcd","uint8",24,1,SX_NONE),
    SX_FIELD("day_bcd","uint8",25,1,SX_NONE),
};
static const sx_layout sxst_adam_volume = {0x60370012U,"adam_volume",sxst_adam_volume_fields,SX_COUNT(sxst_adam_volume_fields),SX_LE};

static const xx_data_struct_field_desc sxst_adam_entry_fields[] = {
    SX_FIELD("name_and_type","char[12]",0,12,SX_NONE),
    SX_FIELD("attributes","uint8",12,1,SX_FLAGS),
    SX_FIELD("first_block","uint32",13,4,SX_NONE),
    SX_FIELD("allocated_blocks","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("used_blocks","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("last_block_used_bytes","uint16",21,2,SX_SIZE),
    SX_FIELD("year_bcd","uint8",23,1,SX_NONE),
    SX_FIELD("month_bcd","uint8",24,1,SX_NONE),
    SX_FIELD("day_bcd","uint8",25,1,SX_NONE),
};
static const sx_layout sxst_adam_entry = {0x60370013U,"adam_entry",sxst_adam_entry_fields,SX_COUNT(sxst_adam_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxst_adam_entry_split_prefix_fields[] = {
    SX_FIELD("name_and_type","char[12]",0,12,SX_NONE),
    SX_FIELD("attributes","uint8",12,1,SX_FLAGS),
    SX_FIELD("first_block","uint32",13,4,SX_NONE),
    SX_FIELD("allocated_blocks_low","uint8",17,1,SX_NONE),
};
static const sx_layout sxst_adam_entry_split_prefix = {0x60370014U,"adam_entry_split_prefix",sxst_adam_entry_split_prefix_fields,SX_COUNT(sxst_adam_entry_split_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxst_adam_entry_split_tail_fields[] = {
    SX_FIELD("allocated_blocks_high","uint8",0,1,SX_NONE),
    SX_FIELD("used_blocks","uint16",1,2,SX_COUNT_PROP),
    SX_FIELD("last_block_used_bytes","uint16",3,2,SX_SIZE),
    SX_FIELD("year_bcd","uint8",5,1,SX_NONE),
    SX_FIELD("month_bcd","uint8",6,1,SX_NONE),
    SX_FIELD("day_bcd","uint8",7,1,SX_NONE),
};
static const sx_layout sxst_adam_entry_split_tail = {0x60370015U,"adam_entry_split_tail",sxst_adam_entry_split_tail_fields,SX_COUNT(sxst_adam_entry_split_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxst_pcmag_flp_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",3,2,SX_RESERVED),
    SX_FIELD("heads","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("tracks_per_side","uint16",7,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
};
static const sx_layout sxst_pcmag_flp_header = {0x60370016U,"pcmag_flp_header",sxst_pcmag_flp_header_fields,SX_COUNT(sxst_pcmag_flp_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_warp_track_fields[] = {
    SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
    SX_FIELD("cylinder","uint16",10,2,SX_NONE),
    SX_FIELD("side","char[4]",12,4,SX_ID),
    SX_FIELD("version","uint16",16,2,SX_ID),
    SX_FIELD("compression","uint16",18,2,SX_ID),
    SX_FIELD("data_crc","uint16",20,2,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",22,4,SX_SIZE),
};
static const sx_layout sxst_warp_track = {0x60370017U,"warp_track",sxst_warp_track_fields,SX_COUNT(sxst_warp_track_fields),SX_BE};

static const xx_data_struct_field_desc sxst_lhwarp_header0_fields[] = {
    SX_FIELD("major_version","uint8",0,1,SX_ID),
    SX_FIELD("revision","uint8",1,1,SX_ID),
    SX_FIELD("minor_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("first_cylinder","uint16",4,2,SX_NONE),
    SX_FIELD("last_cylinder","uint16",6,2,SX_NONE),
    SX_FIELD("comment_size","uint32",8,4,SX_SIZE),
    SX_FIELD("packed_comment_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxst_lhwarp_header0 = {0x60370018U,"lhwarp_header0",sxst_lhwarp_header0_fields,SX_COUNT(sxst_lhwarp_header0_fields),SX_BE};

static const xx_data_struct_field_desc sxst_lhwarp_header3_fields[] = {
    SX_FIELD("major_version","uint8",0,1,SX_ID),
    SX_FIELD("revision","uint8",1,1,SX_ID),
    SX_FIELD("minor_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("first_cylinder","uint16",4,2,SX_NONE),
    SX_FIELD("last_cylinder","uint16",6,2,SX_NONE),
    SX_FIELD("comment_size","uint32",8,4,SX_SIZE),
    SX_FIELD("packed_comment_size","uint32",12,4,SX_SIZE),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxst_lhwarp_header3 = {0x60370019U,"lhwarp_header3",sxst_lhwarp_header3_fields,SX_COUNT(sxst_lhwarp_header3_fields),SX_BE};

static const xx_data_struct_field_desc sxst_lhwarp_cylinder0_fields[] = {
    SX_FIELD("unknown_00","byte[2]",0,2,SX_NONE),
    SX_FIELD("cylinder","uint8",2,1,SX_NONE),
    SX_FIELD("unknown_03","uint8",3,1,SX_NONE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("byte_sum","uint32",12,4,SX_SIGNATURE),
};
static const sx_layout sxst_lhwarp_cylinder0 = {0x6037001aU,"lhwarp_cylinder0",sxst_lhwarp_cylinder0_fields,SX_COUNT(sxst_lhwarp_cylinder0_fields),SX_BE};

static const xx_data_struct_field_desc sxst_lhwarp_cylinder_fields[] = {
    SX_FIELD("compression","uint8",0,1,SX_ID),
    SX_FIELD("flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("cylinder","uint8",2,1,SX_NONE),
    SX_FIELD("unknown_03","uint8",3,1,SX_NONE),
    SX_FIELD("presence_bitmap","uint24le",4,3,SX_FLAGS),
    SX_FIELD("old_mode","uint8",7,1,SX_NONE),
    SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",12,4,SX_SIZE),
    SX_FIELD("data_crc","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxst_lhwarp_cylinder = {0x6037001bU,"lhwarp_cylinder",sxst_lhwarp_cylinder_fields,SX_COUNT(sxst_lhwarp_cylinder_fields),SX_BE};

static const xx_data_struct_field_desc sxst_compdisk_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("reserved1","uint32",8,4,SX_RESERVED),
    SX_FIELD("reserved2","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxst_compdisk_header = {0x6037001cU,"compdisk_header",sxst_compdisk_header_fields,SX_COUNT(sxst_compdisk_header_fields),SX_BE};

static const xx_data_struct_field_desc sxst_compdisk_cylinder_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
    SX_FIELD("olaf_checksum","uint16",4,2,SX_CHECKSUM),
};
static const sx_layout sxst_compdisk_cylinder = {0x6037001dU,"compdisk_cylinder",sxst_compdisk_cylinder_fields,SX_COUNT(sxst_compdisk_cylinder_fields),SX_BE};

static const xx_data_struct_field_desc sxst_crunchdisk_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("bytes_per_sector","uint32",4,4,SX_SIZE),
    SX_FIELD("sectors_per_track","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("first_cylinder","uint32",16,4,SX_NONE),
    SX_FIELD("last_cylinder","uint32",20,4,SX_NONE),
    SX_FIELD("encrypted","uint8",24,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",25,1,SX_RESERVED),
    SX_FIELD("unknown_1a","byte[2]",26,2,SX_NONE),
    SX_FIELD("efficiency","uint16",28,2,SX_ID),
    SX_FIELD("compression","uint16",30,2,SX_ID),
};
static const sx_layout sxst_crunchdisk_header = {0x6037001eU,"crunchdisk_header",sxst_crunchdisk_header_fields,SX_COUNT(sxst_crunchdisk_header_fields),SX_BE};

static const xx_data_struct_field_desc sxst_crunchdisk_cylinder_fields[] = {
    SX_FIELD("type","char[4]",0,4,SX_ID),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxst_crunchdisk_cylinder = {0x6037001fU,"crunchdisk_cylinder",sxst_crunchdisk_cylinder_fields,SX_COUNT(sxst_crunchdisk_cylinder_fields),SX_BE};

static const xx_data_struct_field_desc sxst_lisa_blu_header_fields[] = {
    SX_FIELD("device_name","char[13]",0,13,SX_NONE),
    SX_FIELD("device_type","uint24",13,3,SX_ID),
    SX_FIELD("unknown_10","byte[2]",16,2,SX_NONE),
    SX_FIELD("block_count","uint24",18,3,SX_COUNT_PROP),
    SX_FIELD("bytes_per_block","uint16",21,2,SX_SIZE),
};
static const sx_layout sxst_lisa_blu_header = {0x60370020U,"lisa_blu_header",sxst_lisa_blu_header_fields,SX_COUNT(sxst_lisa_blu_header_fields),SX_BE};

static const xx_data_struct_field_desc sxst_ciscopy_header_fields[] = {
    SX_FIELD("disk_type","uint8",0,1,SX_ID),
};
static const sx_layout sxst_ciscopy_header = {0x60370021U,"ciscopy_header",sxst_ciscopy_header_fields,SX_COUNT(sxst_ciscopy_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_ciscopy_track_state_fields[] = {
    SX_FIELD("state","uint8",0,1,SX_ID),
};
static const sx_layout sxst_ciscopy_track_state = {0x60370022U,"ciscopy_track_state",sxst_ciscopy_track_state_fields,SX_COUNT(sxst_ciscopy_track_state_fields),SX_LE};

static const xx_data_struct_field_desc sxst_ciscopy_compression_fields[] = {
    SX_FIELD("compression","uint8",0,1,SX_ID),
};
static const sx_layout sxst_ciscopy_compression = {0x60370023U,"ciscopy_compression",sxst_ciscopy_compression_fields,SX_COUNT(sxst_ciscopy_compression_fields),SX_LE};

static const xx_data_struct_field_desc sxst_copytape_block_fields[] = {
    SX_FIELD("marker","char[9]",0,9,SX_SIGNATURE),
    SX_FIELD("block_length","ascii_decimal[6]",9,6,SX_SIZE),
    SX_FIELD("line_feed","uint8",15,1,SX_ID),
};
static const sx_layout sxst_copytape_block = {0x60370024U,"copytape_block",sxst_copytape_block_fields,SX_COUNT(sxst_copytape_block_fields),SX_LE};

static const xx_data_struct_field_desc sxst_copytape_mark_fields[] = {
    SX_FIELD("prefix","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("kind","char[3]",5,3,SX_ID),
    SX_FIELD("line_feed","uint8",8,1,SX_ID),
};
static const sx_layout sxst_copytape_mark = {0x60370025U,"copytape_mark",sxst_copytape_mark_fields,SX_COUNT(sxst_copytape_mark_fields),SX_LE};

static const xx_data_struct_field_desc sxst_copytape_separator_fields[] = {
    SX_FIELD("line_feed","uint8",0,1,SX_ID),
};
static const sx_layout sxst_copytape_separator = {0x60370026U,"copytape_separator",sxst_copytape_separator_fields,SX_COUNT(sxst_copytape_separator_fields),SX_LE};

static const xx_data_struct_field_desc sxst_wcdisk_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint8",16,1,SX_ID),
    SX_FIELD("heads","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",18,1,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint8",19,1,SX_COUNT_PROP),
    SX_FIELD("extra_tracks","uint8[4]",20,4,SX_FLAGS),
    SX_FIELD("extra_flags","uint8",24,1,SX_FLAGS),
    SX_FIELD("reserved","byte[7]",25,7,SX_RESERVED),
};
static const sx_layout sxst_wcdisk_header = {0x60370027U,"wcdisk_header",sxst_wcdisk_header_fields,SX_COUNT(sxst_wcdisk_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_wcdisk_sector_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector","uint8",2,1,SX_NONE),
    SX_FIELD("cylinder","uint8",3,1,SX_NONE),
    SX_FIELD("data_crc","uint16",4,2,SX_CHECKSUM),
};
static const sx_layout sxst_wcdisk_sector = {0x60370028U,"wcdisk_sector",sxst_wcdisk_sector_fields,SX_COUNT(sxst_wcdisk_sector_fields),SX_LE};

static const xx_data_struct_field_desc sxst_wcdisk_fill_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector","uint8",2,1,SX_NONE),
    SX_FIELD("cylinder","uint8",3,1,SX_NONE),
    SX_FIELD("fill_value","uint8",4,1,SX_ID),
    SX_FIELD("unused","uint8",5,1,SX_NONE),
};
static const sx_layout sxst_wcdisk_fill = {0x60370029U,"wcdisk_fill",sxst_wcdisk_fill_fields,SX_COUNT(sxst_wcdisk_fill_fields),SX_LE};

static const xx_data_struct_field_desc sxst_wcdisk_extra_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector","uint8",2,1,SX_NONE),
    SX_FIELD("cylinder","uint8",3,1,SX_NONE),
    SX_FIELD("text_size","uint16",4,2,SX_SIZE),
};
static const sx_layout sxst_wcdisk_extra = {0x6037002aU,"wcdisk_extra",sxst_wcdisk_extra_fields,SX_COUNT(sxst_wcdisk_extra_fields),SX_LE};

static const xx_data_struct_field_desc sxst_dri_signature_fields[] = {
    SX_FIELD("signature","char[51]",0,51,SX_SIGNATURE),
};
static const sx_layout sxst_dri_signature = {0x6037002bU,"dri_signature",sxst_dri_signature_fields,SX_COUNT(sxst_dri_signature_fields),SX_LE};

static const xx_data_struct_field_desc sxst_dri_diskcopy_bpb_fields[] = {
    SX_FIELD("expected_five","uint8",0,1,SX_ID),
    SX_FIELD("drive_code","uint8",1,1,SX_ID),
    SX_FIELD("unknown_02","uint16",2,2,SX_NONE),
    SX_FIELD("cylinders","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("unknown_06","uint8",6,1,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",7,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("root_entries","uint16",13,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors","uint16",15,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",17,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",20,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sectors","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("drive_number","uint8",28,1,SX_ID),
    SX_FIELD("unknown_1d","byte[8]",29,8,SX_NONE),
    SX_FIELD("unknown_25","uint8",37,1,SX_NONE),
    SX_FIELD("sectors_per_track_copy","uint16",38,2,SX_COUNT_PROP),
    SX_FIELD("unknown_28","byte[144]",40,144,SX_NONE),
};
static const sx_layout sxst_dri_diskcopy_bpb = {0x6037002cU,"dri_diskcopy_bpb",sxst_dri_diskcopy_bpb_fields,SX_COUNT(sxst_dri_diskcopy_bpb_fields),SX_LE};

static const xx_data_struct_field_desc sxst_maxidisk_header_fields[] = {
    SX_FIELD("unknown_00","uint8",0,1,SX_NONE),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("heads","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_code","uint8",4,1,SX_NONE),
    SX_FIELD("sectors_per_track","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("unknown_06","byte[2]",6,2,SX_NONE),
};
static const sx_layout sxst_maxidisk_header = {0x6037002dU,"maxidisk_header",sxst_maxidisk_header_fields,SX_COUNT(sxst_maxidisk_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_raydim_header_indices_fields[] = {
    SX_FIELD("signature","char[80]",0,80,SX_SIGNATURE),
    SX_FIELD("disk_type","uint8",80,1,SX_ID),
    SX_FIELD("cylinders_indices","uint8",81,1,SX_NONE),
    SX_FIELD("sectors_per_track","uint8",82,1,SX_COUNT_PROP),
    SX_FIELD("heads_indices","uint8",83,1,SX_NONE),
};
static const sx_layout sxst_raydim_header_indices = {0x6037002eU,"raydim_header_indices",sxst_raydim_header_indices_fields,SX_COUNT(sxst_raydim_header_indices_fields),SX_LE};

static const xx_data_struct_field_desc sxst_raydim_header_counts_fields[] = {
    SX_FIELD("signature","char[80]",0,80,SX_SIGNATURE),
    SX_FIELD("disk_type","uint8",80,1,SX_ID),
    SX_FIELD("cylinders_counts","uint8",81,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",82,1,SX_COUNT_PROP),
    SX_FIELD("heads_counts","uint8",83,1,SX_COUNT_PROP),
};
static const sx_layout sxst_raydim_header_counts = {0x6037002fU,"raydim_header_counts",sxst_raydim_header_counts_fields,SX_COUNT(sxst_raydim_header_counts_fields),SX_LE};

static const xx_data_struct_field_desc sxst_raydim_sector_status_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxst_raydim_sector_status = {0x60370030U,"raydim_sector_status",sxst_raydim_sector_status_fields,SX_COUNT(sxst_raydim_sector_status_fields),SX_LE};

static const xx_data_struct_field_desc sxst_rside_header_fields[] = {
    SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("revision","uint8",7,1,SX_ID),
    SX_FIELD("flags","uint8",8,1,SX_FLAGS),
    SX_FIELD("data_offset","uint16",9,2,SX_OFFSET),
    SX_FIELD("reserved","byte[11]",11,11,SX_RESERVED),
};
static const sx_layout sxst_rside_header = {0x60370031U,"rside_header",sxst_rside_header_fields,SX_COUNT(sxst_rside_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_rside_identify_fields[] = {
    SX_FIELD("general_configuration","uint16",0,2,SX_FLAGS),
    SX_FIELD("cylinders","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("specific_configuration","uint16",4,2,SX_FLAGS),
    SX_FIELD("heads","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("obsolete_bytes_per_track","uint16",8,2,SX_SIZE),
    SX_FIELD("obsolete_bytes_per_sector","uint16",10,2,SX_SIZE),
    SX_FIELD("sectors_per_track","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("obsolete_vendor","byte[6]",14,6,SX_NONE),
    SX_FIELD("serial_number_words","byte[20]",20,20,SX_NONE),
    SX_FIELD("obsolete_buffer_type","uint16",40,2,SX_ID),
    SX_FIELD("obsolete_buffer_size","uint16",42,2,SX_NONE),
    SX_FIELD("obsolete_ecc_bytes","uint16",44,2,SX_SIZE),
    SX_FIELD("firmware_revision_words","byte[8]",46,8,SX_NONE),
    SX_FIELD("model_number_words","byte[40]",54,40,SX_NONE),
    SX_FIELD("multiple_sector_setting","uint16",94,2,SX_FLAGS),
    SX_FIELD("trusted_computing","uint16",96,2,SX_FLAGS),
    SX_FIELD("capabilities1","uint16",98,2,SX_FLAGS),
    SX_FIELD("capabilities2","uint16",100,2,SX_FLAGS),
    SX_FIELD("pio_timing_word","uint16",102,2,SX_FLAGS),
    SX_FIELD("dma_timing_word","uint16",104,2,SX_FLAGS),
};
static const sx_layout sxst_rside_identify = {0x60370032U,"rside_identify",sxst_rside_identify_fields,SX_COUNT(sxst_rside_identify_fields),SX_LE};

static const xx_data_struct_field_desc sxst_t98_header_fields[] = {
    SX_FIELD("cylinders","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[252]",4,252,SX_RESERVED),
};
static const sx_layout sxst_t98_header = {0x60370033U,"t98_header",sxst_t98_header_fields,SX_COUNT(sxst_t98_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_pc86f_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("minor_version","uint8",4,1,SX_ID),
    SX_FIELD("major_version","uint8",5,1,SX_ID),
    SX_FIELD("disk_flags","uint16",6,2,SX_FLAGS),
};
static const sx_layout sxst_pc86f_header = {0x60370034U,"pc86f_header",sxst_pc86f_header_fields,SX_COUNT(sxst_pc86f_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_pc86f_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxst_pc86f_track_offset = {0x60370035U,"pc86f_track_offset",sxst_pc86f_track_offset_fields,SX_COUNT(sxst_pc86f_track_offset_fields),SX_LE};

static const xx_data_struct_field_desc sxst_pc86f_track_fields[] = {
    SX_FIELD("track_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("index_bit_position","uint32",2,4,SX_NONE),
};
static const sx_layout sxst_pc86f_track = {0x60370036U,"pc86f_track",sxst_pc86f_track_fields,SX_COUNT(sxst_pc86f_track_fields),SX_LE};

static const xx_data_struct_field_desc sxst_pc86f_track_extra_fields[] = {
    SX_FIELD("track_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("extra_bit_cells","int32",2,4,SX_NONE),
    SX_FIELD("index_bit_position","uint32",6,4,SX_NONE),
};
static const sx_layout sxst_pc86f_track_extra = {0x60370037U,"pc86f_track_extra",sxst_pc86f_track_extra_fields,SX_COUNT(sxst_pc86f_track_extra_fields),SX_LE};

static const xx_data_struct_field_desc sxst_fdx68_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("revision","uint8",3,1,SX_ID),
    SX_FIELD("name","char[60]",4,60,SX_NONE),
    SX_FIELD("padding","byte[4]",64,4,SX_RESERVED),
    SX_FIELD("type","int32",68,4,SX_ID),
    SX_FIELD("cylinders","int32",72,4,SX_COUNT_PROP),
    SX_FIELD("heads","int32",76,4,SX_COUNT_PROP),
    SX_FIELD("transfer_rate","int32",80,4,SX_NONE),
    SX_FIELD("rpm","int32",84,4,SX_NONE),
    SX_FIELD("write_protected","int32",88,4,SX_FLAGS),
    SX_FIELD("options","uint32",92,4,SX_FLAGS),
    SX_FIELD("unused","uint32",96,4,SX_RESERVED),
    SX_FIELD("track_block_size","int32",100,4,SX_SIZE),
    SX_FIELD("reserved","byte[152]",104,152,SX_RESERVED),
};
static const sx_layout sxst_fdx68_header = {0x60370038U,"fdx68_header",sxst_fdx68_header_fields,SX_COUNT(sxst_fdx68_header_fields),SX_LE};

static const xx_data_struct_field_desc sxst_fdx68_track_fields[] = {
    SX_FIELD("cylinder","int32",0,4,SX_NONE),
    SX_FIELD("head","int32",4,4,SX_NONE),
    SX_FIELD("index_bit_position","int32",8,4,SX_NONE),
    SX_FIELD("bit_count","int32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxst_fdx68_track = {0x60370039U,"fdx68_track",sxst_fdx68_track_fields,SX_COUNT(sxst_fdx68_track_fields),SX_LE};

static const xx_data_struct_field_desc sxst_h17_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","char[3]",4,3,SX_NONE),
    SX_FIELD("eight_bit_check","uint8",7,1,SX_SIGNATURE),
};
static const sx_layout sxst_h17_header = {0x6037003aU,"h17_header",sxst_h17_header_fields,SX_COUNT(sxst_h17_header_fields),SX_BE};

static const xx_data_struct_field_desc sxst_h17_chunk_fields[] = {
    SX_FIELD("type","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxst_h17_chunk = {0x6037003bU,"h17_chunk",sxst_h17_chunk_fields,SX_COUNT(sxst_h17_chunk_fields),SX_BE};

static const xx_data_struct_field_desc sxst_h17_disk_format2_fields[] = {
    SX_FIELD("sides","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("tracks_per_side","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxst_h17_disk_format2 = {0x6037003cU,"h17_disk_format2",sxst_h17_disk_format2_fields,SX_COUNT(sxst_h17_disk_format2_fields),SX_BE};

static const xx_data_struct_field_desc sxst_h17_disk_format3_fields[] = {
    SX_FIELD("sides","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("tracks_per_side","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("read_only","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxst_h17_disk_format3 = {0x6037003dU,"h17_disk_format3",sxst_h17_disk_format3_fields,SX_COUNT(sxst_h17_disk_format3_fields),SX_BE};

static const xx_data_struct_field_desc sxst_h17_parameters1_fields[] = {
    SX_FIELD("distribution_disk","uint8",0,1,SX_ID),
};
static const sx_layout sxst_h17_parameters1 = {0x6037003eU,"h17_parameters1",sxst_h17_parameters1_fields,SX_COUNT(sxst_h17_parameters1_fields),SX_BE};

static const xx_data_struct_field_desc sxst_h17_parameters2_fields[] = {
    SX_FIELD("distribution_disk","uint8",0,1,SX_ID),
    SX_FIELD("header_data_source","uint8",1,1,SX_ID),
};
static const sx_layout sxst_h17_parameters2 = {0x6037003fU,"h17_parameters2",sxst_h17_parameters2_fields,SX_COUNT(sxst_h17_parameters2_fields),SX_BE};

static const xx_data_struct_field_desc sxst_h17_sector_metadata_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("status","uint8",4,1,SX_FLAGS),
    SX_FIELD("header_sync","uint8",5,1,SX_SIGNATURE),
    SX_FIELD("volume_number","uint8",6,1,SX_NONE),
    SX_FIELD("track","uint8",7,1,SX_NONE),
    SX_FIELD("sector","uint8",8,1,SX_NONE),
    SX_FIELD("header_checksum","uint8",9,1,SX_CHECKSUM),
    SX_FIELD("data_sync","uint8",10,1,SX_SIGNATURE),
    SX_FIELD("data_checksum","uint8",11,1,SX_CHECKSUM),
    SX_FIELD("valid_bytes","uint16",12,2,SX_SIZE),
    SX_FIELD("reserved","byte[2]",14,2,SX_RESERVED),
};
static const sx_layout sxst_h17_sector_metadata = {0x60370040U,"h17_sector_metadata",sxst_h17_sector_metadata_fields,SX_COUNT(sxst_h17_sector_metadata_fields),SX_BE};

static const sx_layout *const sx_systemtail_layouts[] = {
    &sxst_irixsa_header,
    &sxst_irixsa_directory_entry,
    &sxst_sos_boot_prefix,
    &sxst_sos_directory_entry,
    &sxst_zoom_header,
    &sxst_zoom_note_checksum,
    &sxst_zoom_chunk,
    &sxst_trdos_entry,
    &sxst_trdos_disk_descriptor,
    &sxst_csidos_root_block,
    &sxst_csidos_catalogue_block,
    &sxst_csidos_entry,
    &sxst_copydisk_header,
    &sxst_apricot_image_header,
    &sxst_apricot_chunk,
    &sxst_apricot_run,
    &sxst_sabdu_header,
    &sxst_adam_volume,
    &sxst_adam_entry,
    &sxst_adam_entry_split_prefix,
    &sxst_adam_entry_split_tail,
    &sxst_pcmag_flp_header,
    &sxst_warp_track,
    &sxst_lhwarp_header0,
    &sxst_lhwarp_header3,
    &sxst_lhwarp_cylinder0,
    &sxst_lhwarp_cylinder,
    &sxst_compdisk_header,
    &sxst_compdisk_cylinder,
    &sxst_crunchdisk_header,
    &sxst_crunchdisk_cylinder,
    &sxst_lisa_blu_header,
    &sxst_ciscopy_header,
    &sxst_ciscopy_track_state,
    &sxst_ciscopy_compression,
    &sxst_copytape_block,
    &sxst_copytape_mark,
    &sxst_copytape_separator,
    &sxst_wcdisk_header,
    &sxst_wcdisk_sector,
    &sxst_wcdisk_fill,
    &sxst_wcdisk_extra,
    &sxst_dri_signature,
    &sxst_dri_diskcopy_bpb,
    &sxst_maxidisk_header,
    &sxst_raydim_header_indices,
    &sxst_raydim_header_counts,
    &sxst_raydim_sector_status,
    &sxst_rside_header,
    &sxst_rside_identify,
    &sxst_t98_header,
    &sxst_pc86f_header,
    &sxst_pc86f_track_offset,
    &sxst_pc86f_track,
    &sxst_pc86f_track_extra,
    &sxst_fdx68_header,
    &sxst_fdx68_track,
    &sxst_h17_header,
    &sxst_h17_chunk,
    &sxst_h17_disk_format2,
    &sxst_h17_disk_format3,
    &sxst_h17_parameters1,
    &sxst_h17_parameters2,
    &sxst_h17_sector_metadata,
};

static bool sx_systemtail_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60370000U||id>=0x60380000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;
    if(id==0x60370009U&&!xx_rt_wcscmp(r->name,L"disk_type")&&integer){switch(value){
    case 22U:return xx_data_struct_record_set_comment(r,L"80 tracks, double sided");
    case 23U:return xx_data_struct_record_set_comment(r,L"40 tracks, double sided");
    case 24U:return xx_data_struct_record_set_comment(r,L"80 tracks, single sided");
    case 25U:return xx_data_struct_record_set_comment(r,L"40 tracks, single sided");
    default:break;}}
    if(id==0x6037000fU&&!xx_rt_wcscmp(r->name,L"subtype")&&integer){switch(value){
    case 40592U:return xx_data_struct_record_set_comment(r,L"Stored bytes");
    case 15962U:return xx_data_struct_record_set_comment(r,L"Repeated fill byte");
    default:break;}}
    if(id==0x6037000fU&&!xx_rt_wcscmp(r->name,L"kind")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Disk image data");
    default:break;}}
    if(id==0x60370017U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 1U:return xx_data_struct_record_set_comment(r,L"Unix LZW then RLE90");
    case 2U:return xx_data_struct_record_set_comment(r,L"Squeeze then RLE90");
    case 3U:return xx_data_struct_record_set_comment(r,L"RLE90");
    default:break;}}
    if(id==0x6037001bU&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Freeze adaptive Huffman/LZSS");
    case 1U:return xx_data_struct_record_set_comment(r,L"Stored");
    case 7U:return xx_data_struct_record_set_comment(r,L"Vaporize Unix LZW");
    case 10U:return xx_data_struct_record_set_comment(r,L"Squeeze then RLE90");
    default:break;}}
    if(id==0x6037001eU&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored transposed sectors");
    case 1U:return xx_data_struct_record_set_comment(r,L"PowerPacker");
    case 2U:return xx_data_struct_record_set_comment(r,L"XPK; native decoder does not support compressed CYL1 records");
    default:break;}}
    if(id==0x60370022U&&!xx_rt_wcscmp(r->name,L"state")&&integer){switch(value){
    case 76U:return xx_data_struct_record_set_comment(r,L"Stored track");
    case 250U:return xx_data_struct_record_set_comment(r,L"Omitted track; restored with byte0xF6");
    case 254U:return xx_data_struct_record_set_comment(r,L"Omitted track; restored with byte0xF6");
    default:break;}}
    if(id==0x60370028U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Stored sector with CRC16");
    case 1U:return xx_data_struct_record_set_comment(r,L"Unreadable sector; native output is incomplete");
    default:break;}}
    if(id==0x60370029U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 2U:return xx_data_struct_record_set_comment(r,L"Repeated byte sector");
    default:break;}}
    if(id==0x6037002aU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 3U:return xx_data_struct_record_set_comment(r,L"Comment");
    case 4U:return xx_data_struct_record_set_comment(r,L"Directory listing");
    default:break;}}
    if(id==0x6037002cU&&!xx_rt_wcscmp(r->name,L"drive_code")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"5.25 inch 360 KiB");
    case 1U:return xx_data_struct_record_set_comment(r,L"5.25 inch 1.2 MiB");
    case 2U:return xx_data_struct_record_set_comment(r,L"3.5 inch 720 KiB");
    case 7U:return xx_data_struct_record_set_comment(r,L"3.5 inch 1.44 MiB");
    case 9U:return xx_data_struct_record_set_comment(r,L"3.5 inch 2.88 MiB");
    default:break;}}
    if(id==0x60370038U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"2D");
    case 1U:return xx_data_struct_record_set_comment(r,L"2DD");
    case 2U:return xx_data_struct_record_set_comment(r,L"2HD");
    case 9U:return xx_data_struct_record_set_comment(r,L"Sampled raw");
    default:break;}}
    if(id==0x6037003eU&&!xx_rt_wcscmp(r->name,L"distribution_disk")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"Original distribution disk");
    case 2U:return xx_data_struct_record_set_comment(r,L"Not an original distribution disk");
    case 3U:return xx_data_struct_record_set_comment(r,L"Appears to be a copy of a distribution disk");
    default:break;}}
    if(id==0x6037003fU&&!xx_rt_wcscmp(r->name,L"distribution_disk")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"Original distribution disk");
    case 2U:return xx_data_struct_record_set_comment(r,L"Not an original distribution disk");
    case 3U:return xx_data_struct_record_set_comment(r,L"Appears to be a copy of a distribution disk");
    default:break;}}
    if(id==0x6037003fU&&!xx_rt_wcscmp(r->name,L"header_data_source")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"H8D conversion utility");
    case 1U:return xx_data_struct_record_set_comment(r,L"Emulator");
    case 2U:return xx_data_struct_record_set_comment(r,L"Captured on H8/H89");
    case 3U:return xx_data_struct_record_set_comment(r,L"FC5025");
    case 4U:return xx_data_struct_record_set_comment(r,L"AppleSauce");
    default:break;}}
    switch(id){
    case 0x60370001U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Sum of all 128 big-endian header words is zero modulo 2^32.";
        break;
    case 0x60370002U:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Block index in the physical image; block size is 512 bytes.";
        break;
    case 0x60370003U:
        if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"AmigaDOS root block number; zero may denote the default.";
        break;
    case 0x60370005U:
        if(!xx_rt_wcscmp(r->name,L"last_cylinder"))s=L"Inclusive last cylinder index.";
        else if(!xx_rt_wcscmp(r->name,L"header_checksum"))s=L"Stored checksum; the native reader does not authenticate it.";
        break;
    case 0x60370007U:
        if(!xx_rt_wcscmp(r->name,L"cylinders"))s=L"0xFF marks an unused slot.";
        else if(!xx_rt_wcscmp(r->name,L"middle_size"))s=L"Zero means no RLE stage.";
        else if(!xx_rt_wcscmp(r->name,L"final_size"))s=L"Stored value; when middle_size is zero the decoder derives its final length from the sector masks.";
        break;
    case 0x60370008U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Initial 0 ends the catalogue; initial 1 denotes a deleted entry.";
        else if(!xx_rt_wcscmp(r->name,L"start_address"))s=L"Load/start address encoded by TR-DOS; some file types use this word for their own parameters.";
        break;
    case 0x6037000aU:
        if(!xx_rt_wcscmp(r->name,L"low_signature_or_state"))s=L"Native recognition does not constrain this byte.";
        break;
    case 0x6037000cU:
        if(!xx_rt_wcscmp(r->name,L"parent_directory"))s=L"Directory identity occupies the low byte; 0xFF marks an erased entry.";
        else if(!xx_rt_wcscmp(r->name,L"extension"))s=L"All zero denotes a directory.";
        else if(!xx_rt_wcscmp(r->name,L"attributes_or_directory_id"))s=L"File attributes; on a directory this is its identifier.";
        else if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Logical 512-byte block index.";
        break;
    case 0x6037000dU:
        if(!xx_rt_wcscmp(r->name,L"geometry_hints"))s=L"Unresolved geometry bytes are preserved without inferred field meanings.";
        break;
    case 0x60370010U:
        if(!xx_rt_wcscmp(r->name,L"repeat_count"))s=L"Number of decoded bytes emitted for the following value.";
        break;
    case 0x60370012U:
        if(!xx_rt_wcscmp(r->name,L"directory_blocks_and_protection"))s=L"Low 7 bits are a block count; bit7 is write protection.";
        else if(!xx_rt_wcscmp(r->name,L"year_bcd"))s=L"BCD calendar year, not a Unix timestamp.";
        break;
    case 0x60370013U:
        if(!xx_rt_wcscmp(r->name,L"name_and_type"))s=L"Filename followed by type byte and ETX within this physical field.";
        else if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Logical 1024-byte EOS block index; the two sectors are interleaved on disk.";
        else if(!xx_rt_wcscmp(r->name,L"year_bcd"))s=L"BCD calendar year; 00..49 are interpreted as 2000..2049 by the native reader.";
        break;
    case 0x60370014U:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Logical 1024-byte EOS block index.";
        else if(!xx_rt_wcscmp(r->name,L"allocated_blocks_low"))s=L"Low byte of the allocated-block count; high byte resides in the interleaved second sector.";
        break;
    case 0x60370015U:
        if(!xx_rt_wcscmp(r->name,L"allocated_blocks_high"))s=L"High byte of the allocated-block count; low byte resides in the first sector.";
        else if(!xx_rt_wcscmp(r->name,L"year_bcd"))s=L"BCD calendar year.";
        break;
    case 0x60370017U:
        if(!xx_rt_wcscmp(r->name,L"side"))s=L"TOP or BOT with a terminating NUL.";
        else if(!xx_rt_wcscmp(r->name,L"data_crc"))s=L"IBM CRC16 of decoded 5632 sector bytes and 176 label bytes.";
        break;
    case 0x6037001bU:
        if(!xx_rt_wcscmp(r->name,L"presence_bitmap"))s=L"Low 22 bits indicate present sectors; each decoded sector includes 16 label bytes.";
        else if(!xx_rt_wcscmp(r->name,L"old_mode"))s=L"Stored compatibility byte; unused by LhWarp.";
        else if(!xx_rt_wcscmp(r->name,L"data_crc"))s=L"CRC32 over decoded sectors and labels.";
        break;
    case 0x6037001dU:
        if(!xx_rt_wcscmp(r->name,L"packed_size"))s=L"Zero denotes an uncompressed 11264-byte cylinder.";
        break;
    case 0x6037001fU:
        if(!xx_rt_wcscmp(r->name,L"type"))s=L"CYL0 stores a full cylinder; CYL1 uses the header compression/transpose mode.";
        break;
    case 0x60370020U:
        if(!xx_rt_wcscmp(r->name,L"bytes_per_block"))s=L"Includes the 512-byte sector and any stored sector tags.";
        break;
    case 0x60370022U:
        if(!xx_rt_wcscmp(r->name,L"state"))s=L"0x4C stored; 0xFA or 0xFE omitted and restored as 0xF6.";
        break;
    case 0x60370023U:
        if(!xx_rt_wcscmp(r->name,L"compression"))s=L"Native reader supports zero (uncompressed) only.";
        break;
    case 0x60370024U:
        if(!xx_rt_wcscmp(r->name,L"block_length"))s=L"Six ASCII decimal digits giving payload byte length.";
        break;
    case 0x60370025U:
        if(!xx_rt_wcscmp(r->name,L"kind"))s=L"MRK filemark; EOT end of tape.";
        break;
    case 0x60370027U:
        if(!xx_rt_wcscmp(r->name,L"extra_flags"))s=L"Bit0 comment; bit1 directory listing.";
        break;
    case 0x6037002dU:
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"Bytes per sector equal 128 shifted left by this value.";
        break;
    case 0x6037002eU:
        if(!xx_rt_wcscmp(r->name,L"cylinders_indices"))s=L"Inclusive highest cylinder index.";
        else if(!xx_rt_wcscmp(r->name,L"heads_indices"))s=L"Inclusive highest head index.";
        break;
    case 0x60370031U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit0 selects 256-byte sectors instead of 512-byte sectors.";
        break;
    case 0x60370032U:
        if(!xx_rt_wcscmp(r->name,L"serial_number_words"))s=L"ATA string bytes are swapped within each 16-bit word; shown as stored.";
        else if(!xx_rt_wcscmp(r->name,L"obsolete_buffer_size"))s=L"Obsolete buffer capacity in 512-byte units.";
        break;
    case 0x60370035U:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Zero means no track; exact duplicate offsets may share a track.";
        break;
    case 0x60370036U:
        if(!xx_rt_wcscmp(r->name,L"index_bit_position"))s=L"Position in encoded bit cells, not a byte offset.";
        break;
    case 0x60370037U:
        if(!xx_rt_wcscmp(r->name,L"extra_bit_cells"))s=L"Signed adjustment; with disk flags0x1080 and zero speed bits it instead gives total bit-cell count.";
        break;
    case 0x60370038U:
        if(!xx_rt_wcscmp(r->name,L"transfer_rate"))s=L"Clock-inclusive transfer rate, normally 500 or 1000 kilobits per second.";
        else if(!xx_rt_wcscmp(r->name,L"options"))s=L"Currently unused by the published format.";
        break;
    case 0x60370039U:
        if(!xx_rt_wcscmp(r->name,L"bit_count"))s=L"Encoded or sampled bit cells, not bytes.";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Bounded wire metadata only. Optional damaged extents and display-budget
 * remainder stay raw. No native subclass casts or factory dependencies. */
#define SXST_LIMIT 24000U
#define SXST_ROWS 1048576U
static bool sxst_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxst_read(sx_context*c,uint64_t p,void*b,size_t n){return sxst_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxst_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint16_t sxst16(const uint8_t*b){return (uint16_t)sxst_uint(b,2,false);}
static uint32_t sxst32(const uint8_t*b){return (uint32_t)sxst_uint(b,4,false);}
static bool sxst_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(n>8||!sxst_read(c,p,b,n))return false;*v=sxst_uint(b,n,be);return true;}
/* Keep metadata sorted as it is collected. Monotonic sector tables take
 * O(log n) overlap checks; out-of-order optional pointers insert in place. */
static bool sxst_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 const xx_data_struct_field_desc*f=l->fields+l->field_count-1;
 uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!n)return true;
 if(n>SXST_ROWS||n>(uint64_t)INT64_MAX/z||!sxst_span(c,p,n*z))return false;
 if(xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXST_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&c->items[lo-1].offset-c->f->base_address+c->items[lo-1].total_size>(int64_t)p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}
 return true;
}
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_sos(sx_context*c){uint8_t b[32];if(!SXST_ADD(c,sos_boot_prefix,0))return false;uint64_t p=0;for(unsigned i=1;i<=30;i++){if(!sxst_read(c,i*512,b,32))break;if(!xx_rt_memcmp(b+8,"loader",6)&&(b[14]==0)){p=i*512;break;}}if(!p)return true;for(unsigned i=0;i<SXST_LIMIT&&c->count<SXST_LIMIT;i++,p+=32){if(!sxst_read(c,p,b,32))break;if(!SXST_ADD(c,sos_directory_entry,p))return false;if(!sxst_uint(b,4,true)||!b[8])break;}return true;}
static bool sxst_zoom(sx_context*c){uint8_t h[76],b[42];if(!sxst_read(c,0,h,76)||!SXST_ADD(c,zoom_header,0))return false;uint64_t p=76,n=sxst_uint(h+28,4,true);if(n){if(!sxst_span(c,p,n+4))return true;if(!SXST_ADD(c,zoom_note_checksum,p+n))return false;p+=n+4;}if(h[36])return true;for(unsigned i=0;i<SXST_LIMIT&&c->count<SXST_LIMIT;i++){if(!sxst_read(c,p,b,42))break;n=sxst_uint(b+26,2,true);if(!sxst_span(c,p+42,n)||!SXST_ADD(c,zoom_chunk,p))break;p+=42+n;}return true;}
static bool sxst_trdos(sx_context*c){if(!SXST_ADD(c,trdos_disk_descriptor,0x8e0))return false;uint8_t b;uint64_t n=0;for(;n<128;n++){if(!sxst_read(c,16*n,&b,1))break;if(!b){n++;break;}}return n&&SXST_TABLE(c,trdos_entry,0,n);}
static bool sxst_csidos(sx_context*c){uint8_t b[12];if(!SXST_ADD(c,csidos_root_block,1024))return false;for(unsigned i=2;i<10;i++){uint64_t p=i*512;if(!sxst_read(c,p,b,12)||sxst16(b)!=i||!sxst_span(c,p,512))break;if(i!=2&&!SXST_ADD(c,csidos_catalogue_block,p))return false;if(!SXST_TABLE(c,csidos_entry,p+12,25))return false;}return true;}
static bool sxst_apricot(sx_context*c){if(!SXST_ADD(c,apricot_image_header,0))return false;uint64_t p=128;uint8_t b[16];for(unsigned i=0;i<SXST_LIMIT&&c->count<SXST_LIMIT;i++){if(!sxst_read(c,p,b,16))break;uint64_t z=sxst32(b+8),h=sxst16(b+6);if(h<16||z>INT32_MAX||!sxst_span(c,p,h+z)||!SXST_ADD(c,apricot_chunk,p))break;if(sxst16(b)==1&&sxst16(b+4)==0x3e5a&&z==3&&!SXST_ADD(c,apricot_run,p+h))return false;p+=h+z;}return true;}
static bool sxst_adam(sx_context*c){uint8_t b;if(!sxst_read(c,1036,&b,1)||!SXST_ADD(c,adam_volume,1024))return false;unsigned n=b&127;for(unsigned i=1;i<=n;i++){uint64_t p=(uint64_t)i*1024,q=((uint64_t)i*2^5)*512;if(!sxst_span(c,p,512)||!sxst_span(c,q,512))break;if(i==1){if(!SXST_TABLE(c,adam_entry,p+26,18))return false;}else if(!SXST_TABLE(c,adam_entry,p,19))return false;if(!SXST_ADD(c,adam_entry_split_prefix,p+494)||!SXST_ADD(c,adam_entry_split_tail,q)||!SXST_TABLE(c,adam_entry,q+8,19))return false;}return true;}
static bool sxst_warp(sx_context*c){uint64_t p=0;uint8_t b[26];for(unsigned i=0;i<160;i++){if(!sxst_read(c,p,b,26)||xx_rt_memcmp(b,"Warp v1.1",10))break;uint64_t z=sxst_uint(b+22,4,true);if(!sxst_span(c,p+26,z)||!SXST_ADD(c,warp_track,p))break;p+=26+z;}return c->count>0;}
static bool sxst_lhwarp(sx_context*c){uint8_t h[20],b[20];if(!sxst_read(c,0,h,16))return false;unsigned rev=h[1];uint64_t p=rev<3?16:20,low=sxst_uint(h+4,2,true),high=sxst_uint(h+6,2,true),z=sxst_uint(h+12,4,true);if(rev>3||!sxst_put(c,rev<3?&sxst_lhwarp_header0:&sxst_lhwarp_header3,0,1))return false;if(low>high||high>=80||!sxst_span(c,p,z))return true;p+=z;for(uint64_t i=low;i<=high;i++){unsigned hs=rev?20:16;if(!sxst_read(c,p,b,hs))break;z=sxst_uint(b+(rev?12:8),4,true);if(!sxst_span(c,p+hs,z)||!sxst_put(c,rev?&sxst_lhwarp_cylinder:&sxst_lhwarp_cylinder0,p,1))break;p+=hs+z;}return true;}
static bool sxst_compdisk(sx_context*c){if(!SXST_ADD(c,compdisk_header,0))return false;uint64_t p=16,z;for(unsigned i=0;i<80;i++){if(!sxst_word(c,p,4,true,&z))break;if(!z)z=11264;if(!sxst_span(c,p+6,z)||!SXST_ADD(c,compdisk_cylinder,p))break;p+=6+z;}return true;}
static bool sxst_crunchdisk(sx_context*c){uint8_t h[32],b[8];if(!sxst_read(c,0,h,32)||!SXST_ADD(c,crunchdisk_header,0))return false;uint64_t low=sxst_uint(h+16,4,true),high=sxst_uint(h+20,4,true),p=32;if(low>high||high>255||h[24])return true;for(uint64_t i=low;i<=high;i++){if(!sxst_read(c,p,b,8)||(xx_rt_memcmp(b,"CYL0",4)&&xx_rt_memcmp(b,"CYL1",4)))break;uint64_t z=sxst_uint(b+4,4,true);if(!sxst_span(c,p+8,z)||!SXST_ADD(c,crunchdisk_cylinder,p))break;p+=8+z;}return true;}
static bool sxst_ciscopy(sx_context*c){uint8_t type;if(!sxst_read(c,0,&type,1)||!SXST_ADD(c,ciscopy_header,0))return false;uint64_t n=type<=4?80:160;if(type<1||type>7||!sxst_span(c,1,n+1))return true;return SXST_TABLE(c,ciscopy_track_state,1,n)&&SXST_ADD(c,ciscopy_compression,n+1);}
static bool sxst_copytape(sx_context*c){uint64_t p=0;uint8_t b[16];for(unsigned i=0;i<100000&&c->count<SXST_LIMIT;i++){if(!sxst_read(c,p,b,9))break;if(!xx_rt_memcmp(b,"CPTP:MRK\n",9)||!xx_rt_memcmp(b,"CPTP:EOT\n",9)){if(!SXST_ADD(c,copytape_mark,p))return false;p+=9;if(b[5]=='E')break;continue;}if(xx_rt_memcmp(b,"CPTP:BLK ",9)||!sxst_read(c,p,b,16)||b[15]!=10)break;uint64_t z=0;bool valid=true;for(unsigned j=9;j<15;j++){if(b[j]<'0'||b[j]>'9'){valid=false;break;}z=z*10+b[j]-'0';}if(!valid||!z||!sxst_span(c,p,17+z)||!SXST_ADD(c,copytape_block,p)||!SXST_ADD(c,copytape_separator,p+16+z))break;p+=17+z;}return c->count>0;}
static bool sxst_wcdisk(sx_context*c){uint8_t h[32],b[6];if(!sxst_read(c,0,h,32)||!SXST_ADD(c,wcdisk_header,0))return false;if(!h[17]||h[17]>2||!h[18]||h[18]>18||!h[19]||h[19]>80)return true;uint64_t tracks=(uint64_t)h[17]*h[19],p=32;for(unsigned i=20;i<24;i++)tracks+=h[i]!=0;for(uint64_t i=0;i<tracks*h[18];i++){if(!sxst_read(c,p,b,6)||b[0]>2)return true;uint64_t z=b[0]==0?512:0;if(!sxst_span(c,p+6,z)||!sxst_put(c,b[0]==2?&sxst_wcdisk_fill:&sxst_wcdisk_sector,p,1))return true;p+=6+z;}for(unsigned i=0;i<2;i++)if(h[24]&(1U<<i)){if(!sxst_read(c,p,b,6)||b[0]!=3+i)return true;uint64_t z=sxst16(b+4);if(!sxst_span(c,p+6,z)||!SXST_ADD(c,wcdisk_extra,p))return true;p+=6+z;}return true;}
static bool sxst_dri(sx_context*c){if(c->size<419)return false;uint64_t p=(uint64_t)c->size-419;return SXST_ADD(c,dri_signature,p)&&SXST_TABLE(c,dri_diskcopy_bpb,p+51,2);}
static bool sxst_ray(sx_context*c){uint8_t h[84];if(!sxst_read(c,0,h,84))return false;uint64_t n=(uint64_t)c->size,tracks=((uint64_t)h[81]+1)*(h[83]+1),bytes=(uint64_t)h[82]*512;bool original=h[83]<=1&&h[82]&&n==84+tracks*(bytes+h[82]);if(!sxst_put(c,original?&sxst_raydim_header_indices:&sxst_raydim_header_counts,0,1))return false;if(original)for(uint64_t i=0;i<tracks&&c->count<SXST_LIMIT;i++)if(!SXST_TABLE(c,raydim_sector_status,84+i*(bytes+h[82])+bytes,h[82]))return false;return true;}
static bool sxst_pc86f(sx_context*c){uint8_t h[8];if(!sxst_read(c,0,h,8)||!SXST_ADD(c,pc86f_header,0))return false;uint16_t flags=sxst16(h+6);uint64_t n=(flags&8)?512:256;if(!sxst_span(c,8,n*4)||!SXST_TABLE(c,pc86f_track_offset,8,n))return true;for(uint64_t i=0;i<n;i++){uint64_t p;if(!sxst_word(c,8+i*4,4,false,&p))return false;if(!p||p<8+n*4)continue;unsigned hs=(flags&128)?10:6;if(sxst_span(c,p,hs)&&!sxst_put(c,hs==10?&sxst_pc86f_track_extra:&sxst_pc86f_track,p,1))return false;}return true;}
static bool sxst_fdx(sx_context*c){uint8_t h[104];if(!sxst_read(c,0,h,104)||!SXST_ADD(c,fdx68_header,0))return false;uint64_t cyl=sxst32(h+72),heads=sxst32(h+76),block=sxst32(h+100);if(!cyl||cyl>256||!heads||heads>2||block<=16||block>1048576)return true;for(uint64_t i=0;i<cyl*heads;i++){uint64_t p=256+i*block;if(!sxst_span(c,p,block)||!SXST_ADD(c,fdx68_track,p))break;}return true;}
static bool sxst_h17(sx_context*c){uint8_t b[8];uint64_t p=8;if(!SXST_ADD(c,h17_header,0))return false;for(unsigned i=0;i<4096&&c->count<SXST_LIMIT;i++){if(!sxst_read(c,p,b,8))break;uint64_t z=sxst_uint(b+4,4,true),q=p+8;if(!sxst_span(c,q,z)||!SXST_ADD(c,h17_chunk,p))break;if(!xx_rt_memcmp(b,"DskF",4)&&(z==2||z==3)){if(!sxst_put(c,z==2?&sxst_h17_disk_format2:&sxst_h17_disk_format3,q,1))return false;}else if(!xx_rt_memcmp(b,"Parm",4)&&(z==1||z==2)){if(!sxst_put(c,z==1?&sxst_h17_parameters1:&sxst_h17_parameters2,q,1))return false;}else if(!xx_rt_memcmp(b,"SecM",4)&&z%16==0&&z/16<=SXST_ROWS){if(!SXST_TABLE(c,h17_sector_metadata,q,z/16))return false;}p=q+z;}return true;}
static int sxst_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxst_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sxst_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxst_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_systemtail_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_IRIXSA:
case XX_FILE_TYPE_SOS:
case XX_FILE_TYPE_ZOOM:
case XX_FILE_TYPE_TRDOS:
case XX_FILE_TYPE_CSIDOS:
case XX_FILE_TYPE_COPYDISK:
case XX_FILE_TYPE_APRICOT:
case XX_FILE_TYPE_SDU:
case XX_FILE_TYPE_SABDU:
case XX_FILE_TYPE_ADAM:
case XX_FILE_TYPE_PC_MAGAZINE_FLP:
case XX_FILE_TYPE_WARP:
case XX_FILE_TYPE_LHWARP:
case XX_FILE_TYPE_COMPDISK:
case XX_FILE_TYPE_CRUNCHDISK:
case XX_FILE_TYPE_LISA_BLU:
case XX_FILE_TYPE_CISCOPY:
case XX_FILE_TYPE_COPYTAPE:
case XX_FILE_TYPE_WC_DISK_IMAGE:
case XX_FILE_TYPE_DRI_DISKCOPY:
case XX_FILE_TYPE_MAXI_DISK:
case XX_FILE_TYPE_RAY_DIM:
case XX_FILE_TYPE_RS_IDE:
case XX_FILE_TYPE_T98_HDD:
case XX_FILE_TYPE_PC_86F:
case XX_FILE_TYPE_FDX68_FDX:
case XX_FILE_TYPE_HEATHKIT_H17:
return true;default:return false;}}
static bool sx_systemtail_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_IRIXSA:ok=SXST_ADD(c,irixsa_header,0)&&SXST_TABLE(c,irixsa_directory_entry,32,20);break;
case XX_FILE_TYPE_SOS:ok=sxst_sos(c);break;
case XX_FILE_TYPE_ZOOM:ok=sxst_zoom(c);break;
case XX_FILE_TYPE_TRDOS:ok=sxst_trdos(c);break;
case XX_FILE_TYPE_CSIDOS:ok=sxst_csidos(c);break;
case XX_FILE_TYPE_COPYDISK:ok=SXST_ADD(c,copydisk_header,0);break;
case XX_FILE_TYPE_APRICOT:ok=sxst_apricot(c);break;
case XX_FILE_TYPE_SDU:
case XX_FILE_TYPE_SABDU:ok=SXST_ADD(c,sabdu_header,0);break;
case XX_FILE_TYPE_ADAM:ok=sxst_adam(c);break;
case XX_FILE_TYPE_PC_MAGAZINE_FLP:ok=SXST_ADD(c,pcmag_flp_header,0);break;
case XX_FILE_TYPE_WARP:ok=sxst_warp(c);break;
case XX_FILE_TYPE_LHWARP:ok=sxst_lhwarp(c);break;
case XX_FILE_TYPE_COMPDISK:ok=sxst_compdisk(c);break;
case XX_FILE_TYPE_CRUNCHDISK:ok=sxst_crunchdisk(c);break;
case XX_FILE_TYPE_LISA_BLU:ok=SXST_ADD(c,lisa_blu_header,0);break;
case XX_FILE_TYPE_CISCOPY:ok=sxst_ciscopy(c);break;
case XX_FILE_TYPE_COPYTAPE:ok=sxst_copytape(c);break;
case XX_FILE_TYPE_WC_DISK_IMAGE:ok=sxst_wcdisk(c);break;
case XX_FILE_TYPE_DRI_DISKCOPY:ok=sxst_dri(c);break;
case XX_FILE_TYPE_MAXI_DISK:ok=SXST_ADD(c,maxidisk_header,0);break;
case XX_FILE_TYPE_RAY_DIM:ok=sxst_ray(c);break;
case XX_FILE_TYPE_RS_IDE:ok=SXST_ADD(c,rside_header,0)&&SXST_ADD(c,rside_identify,22);break;
case XX_FILE_TYPE_T98_HDD:ok=SXST_ADD(c,t98_header,0);break;
case XX_FILE_TYPE_PC_86F:ok=sxst_pc86f(c);break;
case XX_FILE_TYPE_FDX68_FDX:ok=sxst_fdx(c);break;
case XX_FILE_TYPE_HEATHKIT_H17:ok=sxst_h17(c);break;
default:break;}return ok&&sxst_finish(c);}
#undef SXST_ADD
#undef SXST_TABLE
#undef SXST_LIMIT
#undef SXST_ROWS
