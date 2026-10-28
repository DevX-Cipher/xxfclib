/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical firmware container metadata. Unimplemented payloads remain raw. */

static const xx_data_struct_field_desc sx_fm_rompaq_header_fields[] = {
    SX_FIELD("image_size","int32",0,4,SX_SIZE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("rom_id","uint16",8,2,SX_ID),
    SX_FIELD("version","uint16",10,2,SX_ID),
    SX_FIELD("image_name","char[7]",12,7,SX_NONE),
    SX_FIELD("name_terminator","uint8",19,1,SX_RESERVED),
    SX_FIELD("date","char[39]",20,39,SX_NONE),
    SX_FIELD("date_terminator","uint8",59,1,SX_RESERVED),
    SX_FIELD("method","uint8",60,1,SX_ID),
    SX_FIELD("part_count","uint16",61,2,SX_COUNT_PROP),
    SX_FIELD("packed_part_size","int32",63,4,SX_SIZE),
    SX_FIELD("reserved","uint32",67,4,SX_RESERVED),
    SX_FIELD("reserved2","uint8",71,1,SX_RESERVED),
};
static const sx_layout sx_fm_rompaq_header = {0x60220001U,"rompaq_header",sx_fm_rompaq_header_fields,SX_COUNT(sx_fm_rompaq_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_dms_swapped_header_fields[] = {
    SX_FIELD("tag","byte[2]",0,2,SX_SIGNATURE),
    SX_FIELD("unknown16","uint16",2,2,SX_NONE),
    SX_FIELD("magic","uint32_halfword_be",4,4,SX_SIGNATURE),
    SX_FIELD("unknown32","uint32_halfword_be",8,4,SX_NONE),
    SX_FIELD("image_size","uint32_halfword_be",12,4,SX_SIZE),
};
static const sx_layout sx_fm_dms_swapped_header = {0x60220002U,"dms_swapped_header",sx_fm_dms_swapped_header_fields,SX_COUNT(sx_fm_dms_swapped_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_fm_dkbs_header_fields[] = {
    SX_FIELD("board_id","char[32]",0,32,SX_NONE),
    SX_FIELD("unknown1","byte[8]",32,8,SX_NONE),
    SX_FIELD("firmware_version","char[32]",40,32,SX_NONE),
    SX_FIELD("unknown2","byte[32]",72,32,SX_NONE),
    SX_FIELD("payload_size","uint32",104,4,SX_SIZE),
    SX_FIELD("unknown3","byte[4]",108,4,SX_NONE),
    SX_FIELD("boot_device","char[32]",112,32,SX_NONE),
    SX_FIELD("unknown4","byte[16]",144,16,SX_NONE),
};
static const sx_layout sx_fm_dkbs_header = {0x60220003U,"dkbs_header",sx_fm_dkbs_header_fields,SX_COUNT(sx_fm_dkbs_header_fields),SX_FILE};

static const xx_data_struct_field_desc sx_fm_shrs_header_prefix_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unknown","uint32",4,4,SX_NONE),
    SX_FIELD("encrypted_size","uint32",8,4,SX_SIZE),
    SX_FIELD("iv","byte[16]",12,16,SX_NONE),
};
static const sx_layout sx_fm_shrs_header_prefix = {0x60220004U,"shrs_header_prefix",sx_fm_shrs_header_prefix_fields,SX_COUNT(sx_fm_shrs_header_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sx_fm_mh01_signature_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("signature_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("signature_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unknown","uint32",12,4,SX_NONE),
};
static const sx_layout sx_fm_mh01_signature_header = {0x60220005U,"mh01_signature_header",sx_fm_mh01_signature_header_fields,SX_COUNT(sx_fm_mh01_signature_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_mh01_payload_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("iv_text_size","uint32",4,4,SX_SIZE),
    SX_FIELD("encrypted_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unknown","uint32",12,4,SX_NONE),
};
static const sx_layout sx_fm_mh01_payload_header = {0x60220006U,"mh01_payload_header",sx_fm_mh01_payload_header_fields,SX_COUNT(sx_fm_mh01_payload_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_autel_header_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("copyright","char[16]",16,16,SX_NONE),
};
static const sx_layout sx_fm_autel_header = {0x60220007U,"autel_header",sx_fm_autel_header_fields,SX_COUNT(sx_fm_autel_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_dlke_arm_header_fields[] = {
    SX_FIELD("rom_id","char[12]",0,12,SX_NONE),
    SX_FIELD("drange","uint16",12,2,SX_NONE),
    SX_FIELD("image_checksum","uint16",14,2,SX_CHECKSUM),
    SX_FIELD("block_size","uint32",16,4,SX_SIZE),
    SX_FIELD("reserved2","uint32",20,4,SX_RESERVED),
    SX_FIELD("reserved3","uint16",24,2,SX_RESERVED),
    SX_FIELD("lpvs","uint8",26,1,SX_ID),
    SX_FIELD("mbz","uint8",27,1,SX_RESERVED),
    SX_FIELD("timestamp_ticks","uint32",28,4,SX_NONE),
    SX_FIELD("erase_start","uint32",32,4,SX_ADDRESS),
    SX_FIELD("erase_size","uint32",36,4,SX_SIZE),
    SX_FIELD("data_start","uint32",40,4,SX_ADDRESS),
    SX_FIELD("data_size","uint32",44,4,SX_SIZE),
    SX_FIELD("reserved4","uint32",48,4,SX_RESERVED),
    SX_FIELD("reserved5","uint32",52,4,SX_RESERVED),
    SX_FIELD("reserved6","uint32",56,4,SX_RESERVED),
    SX_FIELD("reserved7","uint32",60,4,SX_RESERVED),
    SX_FIELD("header_id","uint16",64,2,SX_SIGNATURE),
    SX_FIELD("header_version","uint16",66,2,SX_ID),
    SX_FIELD("reserved8","uint16",68,2,SX_RESERVED),
    SX_FIELD("section_id","uint8",70,1,SX_ID),
    SX_FIELD("image_info_type","uint8",71,1,SX_ID),
    SX_FIELD("image_info_offset","uint32",72,4,SX_OFFSET),
    SX_FIELD("family","uint16",76,2,SX_ID),
    SX_FIELD("header_checksum","uint16",78,2,SX_CHECKSUM),
};
static const sx_layout sx_fm_dlke_arm_header = {0x60220008U,"dlke_arm_header",sx_fm_dlke_arm_header_fields,SX_COUNT(sx_fm_dlke_arm_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_encrpted_img_header_fields[] = {
    SX_FIELD("magic","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("unknown","byte[4]",12,4,SX_NONE),
};
static const sx_layout sx_fm_encrpted_img_header = {0x60220009U,"encrpted_img_header",sx_fm_encrpted_img_header_fields,SX_COUNT(sx_fm_encrpted_img_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_alpha_encimg_header_prefix_fields[] = {
    SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
    SX_FIELD("magic1","uint32",32,4,SX_SIGNATURE),
    SX_FIELD("magic2","uint32",36,4,SX_SIGNATURE),
    SX_FIELD("version","char[16]",40,16,SX_NONE),
    SX_FIELD("model","char[16]",56,16,SX_NONE),
    SX_FIELD("flags0","uint32",72,4,SX_FLAGS),
    SX_FIELD("flags1","uint32",76,4,SX_FLAGS),
    SX_FIELD("reserve0","uint32",80,4,SX_RESERVED),
    SX_FIELD("reserve1","uint32",84,4,SX_RESERVED),
    SX_FIELD("build_number","char[16]",88,16,SX_NONE),
};
static const sx_layout sx_fm_alpha_encimg_header_prefix = {0x6022000aU,"alpha_encimg_header_prefix",sx_fm_alpha_encimg_header_prefix_fields,SX_COUNT(sx_fm_alpha_encimg_header_prefix_fields),SX_FILE};

static const xx_data_struct_field_desc sx_fm_alpha_encimg_payload_le_fields[] = {
    SX_FIELD("encrypted_size","uint32",0,4,SX_SIZE),
    SX_FIELD("offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sx_fm_alpha_encimg_payload_le = {0x6022000bU,"alpha_encimg_payload_le",sx_fm_alpha_encimg_payload_le_fields,SX_COUNT(sx_fm_alpha_encimg_payload_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_alpha_encimg_payload_be_fields[] = {
    SX_FIELD("encrypted_size","uint32",0,4,SX_SIZE),
    SX_FIELD("offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sx_fm_alpha_encimg_payload_be = {0x6022000cU,"alpha_encimg_payload_be",sx_fm_alpha_encimg_payload_be_fields,SX_COUNT(sx_fm_alpha_encimg_payload_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_fm_alpha_encimg_header_suffix_fields[] = {
    SX_FIELD("device_name","char[32]",0,32,SX_NONE),
    SX_FIELD("digest","byte[16]",32,16,SX_CHECKSUM),
};
static const sx_layout sx_fm_alpha_encimg_header_suffix = {0x6022000dU,"alpha_encimg_header_suffix",sx_fm_alpha_encimg_header_suffix_fields,SX_COUNT(sx_fm_alpha_encimg_header_suffix_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_dlink_package_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unknown","uint32",4,4,SX_NONE),
    SX_FIELD("first_entry_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sx_fm_dlink_package_header = {0x6022000eU,"dlink_package_header",sx_fm_dlink_package_header_fields,SX_COUNT(sx_fm_dlink_package_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_fm_dlink_fpkg_extra_fields[] = {
    SX_FIELD("unknown","uint32",0,4,SX_NONE),
    SX_FIELD("model_name_length","uint32",4,4,SX_SIZE),
};
static const sx_layout sx_fm_dlink_fpkg_extra = {0x6022000fU,"dlink_fpkg_extra",sx_fm_dlink_fpkg_extra_fields,SX_COUNT(sx_fm_dlink_fpkg_extra_fields),SX_BE};

static const xx_data_struct_field_desc sx_fm_dlink_package_entry_fields[] = {
    SX_FIELD("header_length","uint32",0,4,SX_SIZE),
    SX_FIELD("type","uint16",4,2,SX_ID),
    SX_FIELD("unknown","uint16",6,2,SX_NONE),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("name","char[16]",12,16,SX_NONE),
};
static const sx_layout sx_fm_dlink_package_entry = {0x60220010U,"dlink_package_entry",sx_fm_dlink_package_entry_fields,SX_COUNT(sx_fm_dlink_package_entry_fields),SX_BE};

static const xx_data_struct_field_desc sx_fm_htc_nbh_header_fields[] = {
    SX_FIELD("magic","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("initial_signature","byte[16]",7,16,SX_NONE),
};
static const sx_layout sx_fm_htc_nbh_header = {0x60220011U,"htc_nbh_header",sx_fm_htc_nbh_header_fields,SX_COUNT(sx_fm_htc_nbh_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_htc_nbh_block_header_fields[] = {
    SX_FIELD("data_length","uint32",0,4,SX_SIZE),
    SX_FIELD("signature_length","uint32",4,4,SX_SIZE),
    SX_FIELD("flag","uint8",8,1,SX_FLAGS),
};
static const sx_layout sx_fm_htc_nbh_block_header = {0x60220012U,"htc_nbh_block_header",sx_fm_htc_nbh_block_header_fields,SX_COUNT(sx_fm_htc_nbh_block_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_htc_dbh_prefix_fields[] = {
    SX_FIELD("magic","uint32[8]",0,32,SX_SIGNATURE),
    SX_FIELD("device_name","char[32]",32,32,SX_NONE),
};
static const sx_layout sx_fm_htc_dbh_prefix = {0x60220013U,"htc_dbh_prefix",sx_fm_htc_dbh_prefix_fields,SX_COUNT(sx_fm_htc_dbh_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_htc_dbh_section_type_fields[] = {
    SX_FIELD("section_type","uint32",0,4,SX_ID),
};
static const sx_layout sx_fm_htc_dbh_section_type = {0x60220014U,"htc_dbh_section_type",sx_fm_htc_dbh_section_type_fields,SX_COUNT(sx_fm_htc_dbh_section_type_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_htc_dbh_section_offset_fields[] = {
    SX_FIELD("section_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sx_fm_htc_dbh_section_offset = {0x60220015U,"htc_dbh_section_offset",sx_fm_htc_dbh_section_offset_fields,SX_COUNT(sx_fm_htc_dbh_section_offset_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_htc_dbh_section_size_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sx_fm_htc_dbh_section_size = {0x60220016U,"htc_dbh_section_size",sx_fm_htc_dbh_section_size_fields,SX_COUNT(sx_fm_htc_dbh_section_size_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_htc_dbh_identity_fields[] = {
    SX_FIELD("cid","char[32]",0,32,SX_NONE),
    SX_FIELD("version","char[16]",32,16,SX_NONE),
    SX_FIELD("language","char[16]",48,16,SX_NONE),
};
static const sx_layout sx_fm_htc_dbh_identity = {0x60220017U,"htc_dbh_identity",sx_fm_htc_dbh_identity_fields,SX_COUNT(sx_fm_htc_dbh_identity_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_xiaomi_hdr1_prefix_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("signature_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("unused","uint16",12,2,SX_RESERVED),
    SX_FIELD("device_id","uint16",14,2,SX_ID),
};
static const sx_layout sx_fm_xiaomi_hdr1_prefix = {0x60220018U,"xiaomi_hdr1_prefix",sx_fm_xiaomi_hdr1_prefix_fields,SX_COUNT(sx_fm_xiaomi_hdr1_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_xiaomi_hdr2_prefix_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("signature_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("unused","uint32",12,4,SX_RESERVED),
    SX_FIELD("device_id","char[8]",16,8,SX_NONE),
    SX_FIELD("region","char[8]",24,8,SX_NONE),
    SX_FIELD("unused2","uint64[2]",32,16,SX_RESERVED),
};
static const sx_layout sx_fm_xiaomi_hdr2_prefix = {0x60220019U,"xiaomi_hdr2_prefix",sx_fm_xiaomi_hdr2_prefix_fields,SX_COUNT(sx_fm_xiaomi_hdr2_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_xiaomi_blob_offset_fields[] = {
    SX_FIELD("blob_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sx_fm_xiaomi_blob_offset = {0x6022001aU,"xiaomi_blob_offset",sx_fm_xiaomi_blob_offset_fields,SX_COUNT(sx_fm_xiaomi_blob_offset_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_xiaomi_blob_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("flash_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
    SX_FIELD("type","uint16",12,2,SX_ID),
    SX_FIELD("unused","uint16",14,2,SX_RESERVED),
    SX_FIELD("name","char[32]",16,32,SX_NONE),
};
static const sx_layout sx_fm_xiaomi_blob_header = {0x6022001bU,"xiaomi_blob_header",sx_fm_xiaomi_blob_header_fields,SX_COUNT(sx_fm_xiaomi_blob_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_xiaomi_signature_fields[] = {
    SX_FIELD("signature_size","uint32",0,4,SX_SIZE),
    SX_FIELD("padding","uint32[3]",4,12,SX_RESERVED),
    SX_FIELD("signature","byte[256]",16,256,SX_NONE),
};
static const sx_layout sx_fm_xiaomi_signature = {0x6022001cU,"xiaomi_signature",sx_fm_xiaomi_signature_fields,SX_COUNT(sx_fm_xiaomi_signature_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_bios_far_reset_jump_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("target_offset","uint16",1,2,SX_OFFSET),
    SX_FIELD("target_segment","uint16",3,2,SX_ADDRESS),
};
static const sx_layout sx_fm_bios_far_reset_jump = {0x6022001dU,"bios_far_reset_jump",sx_fm_bios_far_reset_jump_fields,SX_COUNT(sx_fm_bios_far_reset_jump_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_bios_near_reset_jump_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("displacement","int16",1,2,SX_OFFSET),
};
static const sx_layout sx_fm_bios_near_reset_jump = {0x6022001eU,"bios_near_reset_jump",sx_fm_bios_near_reset_jump_fields,SX_COUNT(sx_fm_bios_near_reset_jump_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_gns1_ftab_header_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sx_fm_gns1_ftab_header = {0x6022001fU,"gns1_ftab_header",sx_fm_gns1_ftab_header_fields,SX_COUNT(sx_fm_gns1_ftab_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_gns1_ftab_entry_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("size","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sx_fm_gns1_ftab_entry = {0x60220020U,"gns1_ftab_entry",sx_fm_gns1_ftab_entry_fields,SX_COUNT(sx_fm_gns1_ftab_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_gns1_segment_fields[] = {
    SX_FIELD("size","uint32",0,4,SX_SIZE),
    SX_FIELD("physical_address","uint32",4,4,SX_ADDRESS),
    SX_FIELD("image_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sx_fm_gns1_segment = {0x60220021U,"gns1_segment",sx_fm_gns1_segment_fields,SX_COUNT(sx_fm_gns1_segment_fields),SX_LE};

static const xx_data_struct_field_desc sx_fm_gns1_terminator_fields[] = {
    SX_FIELD("size_sentinel","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("address_sentinel","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("offset_sentinel","uint32",8,4,SX_SIGNATURE),
};
static const sx_layout sx_fm_gns1_terminator = {0x60220022U,"gns1_terminator",sx_fm_gns1_terminator_fields,SX_COUNT(sx_fm_gns1_terminator_fields),SX_LE};

static const sx_layout *const sx_firmwaremore_layouts[] = {
    &sx_fm_rompaq_header,
    &sx_fm_dms_swapped_header,
    &sx_fm_dkbs_header,
    &sx_fm_shrs_header_prefix,
    &sx_fm_mh01_signature_header,
    &sx_fm_mh01_payload_header,
    &sx_fm_autel_header,
    &sx_fm_dlke_arm_header,
    &sx_fm_encrpted_img_header,
    &sx_fm_alpha_encimg_header_prefix,
    &sx_fm_alpha_encimg_payload_le,
    &sx_fm_alpha_encimg_payload_be,
    &sx_fm_alpha_encimg_header_suffix,
    &sx_fm_dlink_package_header,
    &sx_fm_dlink_fpkg_extra,
    &sx_fm_dlink_package_entry,
    &sx_fm_htc_nbh_header,
    &sx_fm_htc_nbh_block_header,
    &sx_fm_htc_dbh_prefix,
    &sx_fm_htc_dbh_section_type,
    &sx_fm_htc_dbh_section_offset,
    &sx_fm_htc_dbh_section_size,
    &sx_fm_htc_dbh_identity,
    &sx_fm_xiaomi_hdr1_prefix,
    &sx_fm_xiaomi_hdr2_prefix,
    &sx_fm_xiaomi_blob_offset,
    &sx_fm_xiaomi_blob_header,
    &sx_fm_xiaomi_signature,
    &sx_fm_bios_far_reset_jump,
    &sx_fm_bios_near_reset_jump,
    &sx_fm_gns1_ftab_header,
    &sx_fm_gns1_ftab_entry,
    &sx_fm_gns1_segment,
    &sx_fm_gns1_terminator,
};

/* Optional metadata ranges are bounded before shared helpers are called. */
static bool sx_fm_span(sx_context*c,int64_t p,uint64_t n){return p>=0&&p<=c->size&&n<=(uint64_t)(c->size-p);}
static bool sx_fm_read(sx_context*c,int64_t p,void*b,size_t n){return sx_fm_span(c,p,n)&&sx_read(c,p,b,n);}
static bool sx_fm_u32(sx_context*c,int64_t p,bool be,uint32_t*v){uint8_t b[4];if(!sx_fm_read(c,p,b,4))return false;*v=xx_data_get_u32(b,4,0,be);return true;}
/* Keep the first physical interpretation of ambiguous overlapping ranges. */
static bool sx_fm_table(sx_context*c,const sx_layout*l,int64_t p,int64_t z,uint64_t n){if(!n)return true;if(z<=0||n>1000000||(uint64_t)z>INT64_MAX/n||!sx_fm_span(c,p,(uint64_t)z*n))return false;if(c->count>=32000)return true;for(size_t i=0;i<c->count;i++){int64_t a=c->items[i].offset-c->f->base_address,b=a+c->items[i].total_size;if(p<b&&a<p+z*(int64_t)n)return true;}return sx_table(c,l,p,z,n);}
static bool sx_fm_add(sx_context*c,const sx_layout*l,int64_t p,int64_t z){return sx_fm_table(c,l,p,z,1);}
static bool sx_firmwaremore_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_ROMPAQ:case XX_FILE_TYPE_DMSFW:case XX_FILE_TYPE_DKBS:case XX_FILE_TYPE_SHRS:case XX_FILE_TYPE_MH01:case XX_FILE_TYPE_AUTEL:case XX_FILE_TYPE_DLKE:case XX_FILE_TYPE_ENCRPTED_IMG:case XX_FILE_TYPE_D_LINK_ALPHA_ENCIMG_V2:case XX_FILE_TYPE_D_LINK_FPKG_CPKG:case XX_FILE_TYPE_HTC_NBH_ROM_IMAGE:case XX_FILE_TYPE_XIAOMI_HDR1:case XX_FILE_TYPE_XIAOMI_HDR2:case XX_FILE_TYPE_BIOS_FIRMWARE:case XX_FILE_TYPE_GNS1:return true;default:return false;}
}
static bool sx_fm_dlke(sx_context *c)
{
    uint32_t n;if(!sx_fm_u32(c,44,false,&n))return false;
    /* data_size is the signature span in the first JBOOT ARM header. */
    if(!sx_fm_add(c,&sx_fm_dlke_arm_header,0,80))return false;return !sx_fm_span(c,80+(int64_t)n,80)||sx_fm_add(c,&sx_fm_dlke_arm_header,80+(int64_t)n,80);
}
static bool sx_fm_alpha(sx_context *c)
{
    uint32_t le,be;if(!sx_fm_u32(c,104,false,&le)||!sx_fm_u32(c,104,true,&be))return false;
    return sx_fm_add(c,&sx_fm_alpha_encimg_header_prefix,0,104)&&sx_fm_add(c,le<=be?&sx_fm_alpha_encimg_payload_le:&sx_fm_alpha_encimg_payload_be,104,8)&&sx_fm_add(c,&sx_fm_alpha_encimg_header_suffix,112,48);
}
static bool sx_fm_dlink(sx_context *c)
{
    uint8_t magic[4];uint32_t off;if(!sx_fm_read(c,0,magic,4)||!sx_fm_u32(c,8,true,&off)||!sx_fm_add(c,&sx_fm_dlink_package_header,0,12))return false;
    if(!xx_rt_memcmp(magic,"FPKG",4)&&off>=20){uint32_t name;if(sx_fm_u32(c,16,true,&name)&&name&&name<=256&&name<=off-20&&!sx_fm_add(c,&sx_fm_dlink_fpkg_extra,12,8))return false;}
    uint64_t at=off;unsigned count=0;
    while(at+28<=(uint64_t)c->size&&count<65530){
        uint8_t h[28];if(!sx_fm_read(c,(int64_t)at,h,28))return false;
        uint32_t n=xx_data_get_u32(h,28,8,true);uint16_t t=xx_data_get_u16(h,28,4,true);
        if(xx_data_get_u32(h,28,0,true)!=28||t<0x100||t>0x103||!sx_fm_span(c,(int64_t)at+28,n))break;
        bool printable=true;for(unsigned i=12;i<28&&h[i];i++)if(h[i]<32||h[i]>126)printable=false;
        if(!printable)break;if(!sx_fm_add(c,&sx_fm_dlink_package_entry,(int64_t)at,28))return false;at+=28+(uint64_t)n;count++;
    }
    return !c->failed;
}
static bool sx_fm_dbh(sx_context *c,int64_t at)
{
    return sx_fm_add(c,&sx_fm_htc_dbh_prefix,at,64)&&sx_fm_table(c,&sx_fm_htc_dbh_section_type,at+64,4,32)&&sx_fm_table(c,&sx_fm_htc_dbh_section_offset,at+192,4,32)&&sx_fm_table(c,&sx_fm_htc_dbh_section_size,at+320,4,32)&&sx_fm_add(c,&sx_fm_htc_dbh_identity,at+448,64);
}
static bool sx_fm_nbh(sx_context *c)
{
    if(!sx_fm_add(c,&sx_fm_htc_nbh_header,0,23))return false;uint64_t at=23,logical=0;unsigned count=0;
    while(at+9<=(uint64_t)c->size&&count<65500){
        uint8_t h[9];if(!sx_fm_read(c,(int64_t)at,h,9))return false;
        uint32_t data=xx_data_get_u32(h,9,0,false),sig=xx_data_get_u32(h,9,4,false);
        if(h[8]>2||sig>65536)break;if(!sx_fm_add(c,&sx_fm_htc_nbh_block_header,(int64_t)at,9))return false;
        if(logical==0&&data>=512&&sx_fm_span(c,(int64_t)at+9,512)){uint8_t m[32];bool valid=sx_fm_read(c,(int64_t)at+9,m,32);for(unsigned i=0;i<8&&valid;i++)if(xx_data_get_u32(m,32,i*4,false)!=(uint8_t)"HTCIMAGE"[i])valid=false;if(valid&&!sx_fm_dbh(c,(int64_t)at+9))return false;}
        uint64_t next=at+9+(uint64_t)data+sig;count++;if(next>(uint64_t)c->size||h[8]==2)break;
        logical+=data;at=next;
    }
    return !c->failed;
}
static bool sx_fm_xiaomi(sx_context *c,bool hdr2)
{
    uint32_t signature;int64_t prefix=hdr2?48:16;if(!sx_fm_u32(c,4,false,&signature)||!sx_fm_add(c,hdr2?&sx_fm_xiaomi_hdr2_prefix:&sx_fm_xiaomi_hdr1_prefix,0,prefix)||!sx_fm_table(c,&sx_fm_xiaomi_blob_offset,prefix,4,8)||!sx_fm_add(c,&sx_fm_xiaomi_signature,signature,272))return false;
    for(unsigned i=0;i<8;i++){uint32_t off;if(!sx_fm_u32(c,prefix+4*i,false,&off))return false;if(!off)break;if(!sx_fm_add(c,&sx_fm_xiaomi_blob_header,off,48))return false;}
    return true;
}
/* Native reader tests a complete raw segment table before considering FTAB. */
static bool sx_fm_gns_segments(sx_context*c,uint64_t base,uint64_t size)
{
 if(base>INT64_MAX||size>INT64_MAX||size<64||!sx_fm_span(c,(int64_t)base,size))return false;
 uint8_t h[256];if(!sx_fm_read(c,(int64_t)base,h,12))return false;uint32_t first=xx_data_get_u32(h,12,8,false),address=xx_data_get_u32(h,12,4,false);
 if(first<100||first>size||(address&0x00ffffff)||address<0x12000000||address>=0x16000000)return false;
 uint64_t off=0;unsigned n=0,records=0;bool terminal=false;
 while(off+12<=first&&n<=1000){if(!sx_fm_read(c,(int64_t)(base+off),h,12))return false;uint32_t length=xx_data_get_u32(h,12,0,false),addr=xx_data_get_u32(h,12,4,false),at=xx_data_get_u32(h,12,8,false);off+=12;records++;
  if((length==UINT32_MAX&&addr==UINT32_MAX&&at==UINT32_MAX)||(!length&&!addr&&!at)){terminal=true;break;}
  if(!length||addr<0x12000000||addr>=0x16000000||at<first||at>size||length>size-at||++n>1000)return false;
 }
 if(!terminal&&first>off&&first-off<12)terminal=true;if(!terminal||!n)return false;
 while(off<first){size_t z=first-off>sizeof(h)?sizeof(h):(size_t)(first-off);if(!sx_fm_read(c,(int64_t)(base+off),h,z))return false;for(size_t i=0;i<z;i++)if(h[i])return false;off+=z;}
 return sx_fm_table(c,&sx_fm_gns1_segment,(int64_t)base,12,n)&&(records==n||sx_fm_add(c,&sx_fm_gns1_terminator,(int64_t)(base+(uint64_t)n*12),12));
}
static bool sx_fm_gns(sx_context*c)
{
 if(sx_fm_gns_segments(c,0,(uint64_t)c->size))return true;if(c->failed)return false;
 uint8_t magic[8];if(!sx_fm_read(c,32,magic,8)||xx_rt_memcmp(magic,"rkosftab",8))return false;
 uint32_t n,reserved;if(!sx_fm_u32(c,40,false,&n)||!sx_fm_u32(c,44,false,&reserved)||reserved||!n||n>4096||!sx_fm_span(c,48,(uint64_t)n*16))return false;
 if(!sx_fm_add(c,&sx_fm_gns1_ftab_header,32,16)||!sx_fm_table(c,&sx_fm_gns1_ftab_entry,48,16,n))return false;
 uint32_t base=0,size=0;bool found=false;for(uint32_t i=0;i<n;i++){uint8_t e[16];if(!sx_fm_read(c,48+(int64_t)i*16,e,16))return false;if(!xx_rt_memcmp(e,"GNS1",4)){base=xx_data_get_u32(e,16,4,false);size=xx_data_get_u32(e,16,8,false);found=true;}}
 if(found&&!sx_fm_gns_segments(c,base,size))return !c->failed;return !c->failed;
}
static int sx_fm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sx_fm_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sx_fm_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end||(at>end&&!sx_raw(c,end,at-end)))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sx_fm_order);return !c->failed;
}
static bool sx_firmwaremore_build(sx_context *c)
{
    if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_ROMPAQ:ok=sx_fm_add(c,&sx_fm_rompaq_header,0,72);break;
    case XX_FILE_TYPE_DMSFW:ok=sx_fm_add(c,&sx_fm_dms_swapped_header,0,16);break;
    case XX_FILE_TYPE_DKBS:ok=sx_fm_add(c,&sx_fm_dkbs_header,0,160);break;
    case XX_FILE_TYPE_SHRS:ok=sx_fm_add(c,&sx_fm_shrs_header_prefix,0,28);break;
    case XX_FILE_TYPE_MH01:ok=sx_fm_add(c,&sx_fm_mh01_signature_header,0,16)&&sx_fm_add(c,&sx_fm_mh01_payload_header,16,16);break;
    case XX_FILE_TYPE_AUTEL:ok=sx_fm_add(c,&sx_fm_autel_header,0,32);break;
    case XX_FILE_TYPE_DLKE:ok=sx_fm_dlke(c);break;
    case XX_FILE_TYPE_ENCRPTED_IMG:ok=sx_fm_add(c,&sx_fm_encrpted_img_header,0,16);break;
    case XX_FILE_TYPE_D_LINK_ALPHA_ENCIMG_V2:ok=sx_fm_alpha(c);break;
    case XX_FILE_TYPE_D_LINK_FPKG_CPKG:ok=sx_fm_dlink(c);break;
    case XX_FILE_TYPE_HTC_NBH_ROM_IMAGE:ok=sx_fm_nbh(c);break;
    case XX_FILE_TYPE_XIAOMI_HDR1:ok=sx_fm_xiaomi(c,false);break;
    case XX_FILE_TYPE_XIAOMI_HDR2:ok=sx_fm_xiaomi(c,true);break;
    case XX_FILE_TYPE_BIOS_FIRMWARE:{uint8_t op;if(c->size<16||!sx_fm_read(c,c->size-16,&op,1))return false;ok=op==0xea?sx_fm_add(c,&sx_fm_bios_far_reset_jump,c->size-16,5):op==0xe9?sx_fm_add(c,&sx_fm_bios_near_reset_jump,c->size-16,3):false;break;}
    case XX_FILE_TYPE_GNS1:ok=sx_fm_gns(c);break;
    default:break;}return ok&&sx_fm_finish(c);
}
static bool sx_firmwaremore_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60220001U||id>=0x60220001U+SX_COUNT(sx_firmwaremore_layouts))return true;
    uint64_t v=xx_var_get_u64(&r->value);const wchar_t *s=NULL;
    if(id==sx_fm_dlink_package_header.id&&!xx_rt_wcscmp(r->name,L"unknown"))s=L"Stored constant 0x01000000; its meaning is not established";
    else if(id==sx_fm_dms_swapped_header.id&&(!xx_rt_wcscmp(r->name,L"magic")||!xx_rt_wcscmp(r->name,L"unknown32")||!xx_rt_wcscmp(r->name,L"image_size")))s=L"Physical bytes ABCD decode as big-endian CDAB after swapping the two 16-bit halves";
    else if(id==sx_fm_rompaq_header.id&&!xx_rt_wcscmp(r->name,L"method"))s=v==1?L"Stored":v==2?L"PKWARE DCL implode":NULL;
    else if(id==sx_fm_mh01_signature_header.id&&!xx_rt_wcscmp(r->name,L"signature_offset"))s=L"Byte offset relative to the second MH01 header at file offset 0x10";
    else if(id==sx_fm_dlke_arm_header.id&&!xx_rt_wcscmp(r->name,L"timestamp_ticks"))s=L"4-second ticks since 1998-03-07 16:00:00 UTC; stored value retained";
    else if((id==sx_fm_alpha_encimg_payload_le.id||id==sx_fm_alpha_encimg_payload_be.id))s=L"Native payload byte order chooses the smaller size interpretation, independently of the header magic byte order";
    else if(id==sx_fm_dlink_package_entry.id&&!xx_rt_wcscmp(r->name,L"type"))s=v==0x100?L"FILE":v==0x101?L"UNKNOWN_TYPE_0x101":v==0x102?L"CHECKSUM":v==0x103?L"SIGNATURE":NULL;
    else if(id==sx_fm_htc_nbh_block_header.id&&!xx_rt_wcscmp(r->name,L"flag"))s=v==1?L"MORE_BLOCKS":v==2?L"LAST_BLOCK":v==0?L"Legacy zero flag":NULL;
    else if(id==sx_fm_htc_dbh_section_type.id){switch(v){case 0:s=L"Unused section";break;case 0x100:s=L"IPL";break;case 0x101:s=L"G3IPL";break;case 0x102:s=L"G4IPL";break;case 0x200:s=L"SPL";break;case 0x201:s=L"G3SPL";break;case 0x202:s=L"G4SPL";break;case 0x300:s=L"GSM";break;case 0x400:s=L"OS";break;case 0x600:s=L"MainSplash";break;case 0x601:s=L"SubSplash";break;case 0x700:case 0x900:s=L"ExtROM";break;}}
    else if(id==sx_fm_htc_dbh_section_offset.id)s=L"Byte offset in the logical reassembled DBH image, not in the signed NBH wrapper";
    else if(id==sx_fm_xiaomi_blob_header.id&&!xx_rt_wcscmp(r->name,L"flash_offset"))s=L"Flash destination coordinate; not an offset in the container file";
    else if((id==sx_fm_xiaomi_hdr1_prefix.id||id==sx_fm_xiaomi_hdr2_prefix.id)&&!xx_rt_wcscmp(r->name,L"crc32"))s=L"CRC-32/JAMCRC from file offset 0x0C through the fixed signature block";
    else if(id==sx_fm_bios_far_reset_jump.id&&!xx_rt_wcscmp(r->name,L"target_segment"))s=L"Real-mode segment; physical target is segment * 16 + target_offset";
    else if(id==sx_fm_bios_near_reset_jump.id&&!xx_rt_wcscmp(r->name,L"displacement"))s=L"Signed 16-bit relative displacement from the end of the three-byte reset jump";
    else if(id==sx_fm_gns1_terminator.id)s=L"Physical table terminator: all three words are zero or all are 0xFFFFFFFF; not a segment size, address or offset";
    else if(id==sx_fm_gns1_segment.id&&!xx_rt_wcscmp(r->name,L"image_offset"))s=L"Byte offset relative to the GNS1 image, which can be embedded inside FTAB";
    return !s||xx_data_struct_record_set_comment(r,s);
}
