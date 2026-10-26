/* SPDX-License-Identifier: MIT. Physical game metadata. Scope: docs/data_struct_gamemeta_scope.txt. */
static const xx_data_struct_field_desc sxgm_ines_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("prg_rom_units","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("chr_rom_units","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("flags6","uint8",6,1,SX_FLAGS),
 SX_FIELD("flags7","uint8",7,1,SX_FLAGS),
 SX_FIELD("prg_ram_units","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("tv_system","uint8",9,1,SX_FLAGS),
 SX_FIELD("flags10","uint8",10,1,SX_FLAGS),
 SX_FIELD("unused11","uint8",11,1,SX_NONE),
 SX_FIELD("reserved","uint8[4]",12,4,SX_RESERVED),
};
static const sx_layout sxgm_ines_header = {UINT32_C(0x60270001),"ines_header",sxgm_ines_header_fields,SX_COUNT(sxgm_ines_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_nes2_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("prg_rom_units_low","uint8",4,1,SX_NONE),
 SX_FIELD("chr_rom_units_low","uint8",5,1,SX_NONE),
 SX_FIELD("flags6","uint8",6,1,SX_FLAGS),
 SX_FIELD("flags7","uint8",7,1,SX_FLAGS),
 SX_FIELD("mapper_submapper","uint8",8,1,SX_FLAGS),
 SX_FIELD("rom_size_high","uint8",9,1,SX_NONE),
 SX_FIELD("prg_ram_shifts","uint8",10,1,SX_NONE),
 SX_FIELD("chr_ram_shifts","uint8",11,1,SX_NONE),
 SX_FIELD("timing","uint8",12,1,SX_ID),
 SX_FIELD("console_type","uint8",13,1,SX_ID),
 SX_FIELD("misc_rom_count","uint8",14,1,SX_NONE),
 SX_FIELD("expansion_device","uint8",15,1,SX_ID),
};
static const sx_layout sxgm_nes2_header = {UINT32_C(0x60270002),"nes2_header",sxgm_nes2_header_fields,SX_COUNT(sxgm_nes2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_lynx_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("bank0_page_size","uint16",4,2,SX_SIZE),
 SX_FIELD("bank1_page_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_ID),
 SX_FIELD("cartridge_name","char[32]",10,32,SX_STRING),
 SX_FIELD("manufacturer","char[16]",42,16,SX_STRING),
 SX_FIELD("rotation","uint8",58,1,SX_ID),
 SX_FIELD("audin","uint8",59,1,SX_FLAGS),
 SX_FIELD("eeprom","uint8",60,1,SX_FLAGS),
 SX_FIELD("reserved","uint8[3]",61,3,SX_RESERVED),
};
static const sx_layout sxgm_lynx_header = {UINT32_C(0x60270003),"lynx_header",sxgm_lynx_header_fields,SX_COUNT(sxgm_lynx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_crt_header_fields[] = {
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",16,4,SX_SIZE),
 SX_FIELD("version","uint16",20,2,SX_ID),
 SX_FIELD("hardware_type","uint16",22,2,SX_ID),
 SX_FIELD("exrom","uint8",24,1,SX_FLAGS),
 SX_FIELD("game","uint8",25,1,SX_FLAGS),
 SX_FIELD("hardware_subtype","uint8",26,1,SX_ID),
 SX_FIELD("reserved","uint8[5]",27,5,SX_RESERVED),
 SX_FIELD("name","char[32]",32,32,SX_STRING),
};
static const sx_layout sxgm_crt_header = {UINT32_C(0x60270004),"crt_header",sxgm_crt_header_fields,SX_COUNT(sxgm_crt_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_crt_chip_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("packet_size","uint32",4,4,SX_SIZE),
 SX_FIELD("chip_type","uint16",8,2,SX_ID),
 SX_FIELD("bank","uint16",10,2,SX_ID),
 SX_FIELD("load_address","uint16",12,2,SX_ADDRESS),
 SX_FIELD("image_size","uint16",14,2,SX_SIZE),
};
static const sx_layout sxgm_crt_chip = {UINT32_C(0x60270005),"crt_chip",sxgm_crt_chip_fields,SX_COUNT(sxgm_crt_chip_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_godot_pck_v1_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("pack_version","uint32",4,4,SX_ID),
 SX_FIELD("engine_major","uint32",8,4,SX_ID),
 SX_FIELD("engine_minor","uint32",12,4,SX_ID),
 SX_FIELD("engine_patch","uint32",16,4,SX_ID),
 SX_FIELD("reserved","uint32[16]",20,64,SX_RESERVED),
};
static const sx_layout sxgm_godot_pck_v1 = {UINT32_C(0x60270006),"godot_pck_v1",sxgm_godot_pck_v1_fields,SX_COUNT(sxgm_godot_pck_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_pck_v2_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("pack_version","uint32",4,4,SX_ID),
 SX_FIELD("engine_major","uint32",8,4,SX_ID),
 SX_FIELD("engine_minor","uint32",12,4,SX_ID),
 SX_FIELD("engine_patch","uint32",16,4,SX_ID),
 SX_FIELD("flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("file_base","uint64",24,8,SX_OFFSET),
 SX_FIELD("reserved","uint32[16]",32,64,SX_RESERVED),
};
static const sx_layout sxgm_godot_pck_v2 = {UINT32_C(0x60270007),"godot_pck_v2",sxgm_godot_pck_v2_fields,SX_COUNT(sxgm_godot_pck_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_pck_v3_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("pack_version","uint32",4,4,SX_ID),
 SX_FIELD("engine_major","uint32",8,4,SX_ID),
 SX_FIELD("engine_minor","uint32",12,4,SX_ID),
 SX_FIELD("engine_patch","uint32",16,4,SX_ID),
 SX_FIELD("flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("file_base","uint64",24,8,SX_OFFSET),
 SX_FIELD("directory_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("reserved","uint32[16]",40,64,SX_RESERVED),
};
static const sx_layout sxgm_godot_pck_v3 = {UINT32_C(0x60270008),"godot_pck_v3",sxgm_godot_pck_v3_fields,SX_COUNT(sxgm_godot_pck_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_pck_v4_salted_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("pack_version","uint32",4,4,SX_ID),
 SX_FIELD("engine_major","uint32",8,4,SX_ID),
 SX_FIELD("engine_minor","uint32",12,4,SX_ID),
 SX_FIELD("engine_patch","uint32",16,4,SX_ID),
 SX_FIELD("flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("file_base","uint64",24,8,SX_OFFSET),
 SX_FIELD("directory_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("salt","uint8[32]",40,32,SX_NONE),
 SX_FIELD("reserved","uint8[32]",72,32,SX_RESERVED),
};
static const sx_layout sxgm_godot_pck_v4_salted = {UINT32_C(0x60270009),"godot_pck_v4_salted",sxgm_godot_pck_v4_salted_fields,SX_COUNT(sxgm_godot_pck_v4_salted_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_file_count_fields[] = {
 SX_FIELD("file_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxgm_godot_file_count = {UINT32_C(0x6027000a),"godot_file_count",sxgm_godot_file_count_fields,SX_COUNT(sxgm_godot_file_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_path_length_fields[] = {
 SX_FIELD("path_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgm_godot_path_length = {UINT32_C(0x6027000b),"godot_path_length",sxgm_godot_path_length_fields,SX_COUNT(sxgm_godot_path_length_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_entry_v1_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("data_size","uint64",8,8,SX_SIZE),
 SX_FIELD("md5","uint8[16]",16,16,SX_CHECKSUM),
};
static const sx_layout sxgm_godot_entry_v1 = {UINT32_C(0x6027000c),"godot_entry_v1",sxgm_godot_entry_v1_fields,SX_COUNT(sxgm_godot_entry_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_entry_v2_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("data_size","uint64",8,8,SX_SIZE),
 SX_FIELD("md5","uint8[16]",16,16,SX_CHECKSUM),
 SX_FIELD("flags","uint32",32,4,SX_FLAGS),
};
static const sx_layout sxgm_godot_entry_v2 = {UINT32_C(0x6027000d),"godot_entry_v2",sxgm_godot_entry_v2_fields,SX_COUNT(sxgm_godot_entry_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_encrypted_block_fields[] = {
 SX_FIELD("md5","uint8[16]",0,16,SX_CHECKSUM),
 SX_FIELD("plain_size","uint64",16,8,SX_SIZE),
 SX_FIELD("iv","uint8[16]",24,16,SX_NONE),
};
static const sx_layout sxgm_godot_encrypted_block = {UINT32_C(0x6027000e),"godot_encrypted_block",sxgm_godot_encrypted_block_fields,SX_COUNT(sxgm_godot_encrypted_block_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_godot_trailer_fields[] = {
 SX_FIELD("pack_size","uint64",0,8,SX_SIZE),
 SX_FIELD("signature","char[4]",8,4,SX_SIGNATURE),
};
static const sx_layout sxgm_godot_trailer = {UINT32_C(0x6027000f),"godot_trailer",sxgm_godot_trailer_fields,SX_COUNT(sxgm_godot_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("tree_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxgm_vpk_header = {UINT32_C(0x60270010),"vpk_header",sxgm_vpk_header_fields,SX_COUNT(sxgm_vpk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_v2_sections_fields[] = {
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("archive_md5_size","uint32",4,4,SX_SIZE),
 SX_FIELD("other_md5_size","uint32",8,4,SX_SIZE),
 SX_FIELD("signature_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxgm_vpk_v2_sections = {UINT32_C(0x60270011),"vpk_v2_sections",sxgm_vpk_v2_sections_fields,SX_COUNT(sxgm_vpk_v2_sections_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_entry_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("preload_size","uint16",4,2,SX_SIZE),
 SX_FIELD("archive_index","uint16",6,2,SX_ID),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("terminator","uint16",16,2,SX_SIGNATURE),
};
static const sx_layout sxgm_vpk_entry = {UINT32_C(0x60270012),"vpk_entry",sxgm_vpk_entry_fields,SX_COUNT(sxgm_vpk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_archive_md5_fields[] = {
 SX_FIELD("archive_index","uint32",0,4,SX_ID),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("md5","uint8[16]",12,16,SX_CHECKSUM),
};
static const sx_layout sxgm_vpk_archive_md5 = {UINT32_C(0x60270013),"vpk_archive_md5",sxgm_vpk_archive_md5_fields,SX_COUNT(sxgm_vpk_archive_md5_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_other_md5_fields[] = {
 SX_FIELD("tree_md5","uint8[16]",0,16,SX_CHECKSUM),
 SX_FIELD("archive_md5_section_md5","uint8[16]",16,16,SX_CHECKSUM),
 SX_FIELD("file_md5","uint8[16]",32,16,SX_CHECKSUM),
};
static const sx_layout sxgm_vpk_other_md5 = {UINT32_C(0x60270014),"vpk_other_md5",sxgm_vpk_other_md5_fields,SX_COUNT(sxgm_vpk_other_md5_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_public_key_length_fields[] = {
 SX_FIELD("public_key_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgm_vpk_public_key_length = {UINT32_C(0x60270015),"vpk_public_key_length",sxgm_vpk_public_key_length_fields,SX_COUNT(sxgm_vpk_public_key_length_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_vpk_signature_length_fields[] = {
 SX_FIELD("signature_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgm_vpk_signature_length = {UINT32_C(0x60270016),"vpk_signature_length",sxgm_vpk_signature_length_fields,SX_COUNT(sxgm_vpk_signature_length_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_header_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",16,4,SX_SIZE),
 SX_FIELD("mram_data_size","uint32",20,4,SX_SIZE),
 SX_FIELD("aram_data_size","uint32",24,4,SX_SIZE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
 SX_FIELD("node_count","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("nodes_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("entries_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("strings_size","uint32",48,4,SX_SIZE),
 SX_FIELD("strings_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("next_file_id","uint16",56,2,SX_ID),
 SX_FIELD("sync_file_ids","uint8",58,1,SX_FLAGS),
 SX_FIELD("reserved59","uint8[5]",59,5,SX_RESERVED),
};
static const sx_layout sxgm_rarc_header_le = {UINT32_C(0x60270017),"rarc_header_le",sxgm_rarc_header_le_fields,SX_COUNT(sxgm_rarc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_header_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",16,4,SX_SIZE),
 SX_FIELD("mram_data_size","uint32",20,4,SX_SIZE),
 SX_FIELD("aram_data_size","uint32",24,4,SX_SIZE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
 SX_FIELD("node_count","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("nodes_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("entries_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("strings_size","uint32",48,4,SX_SIZE),
 SX_FIELD("strings_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("next_file_id","uint16",56,2,SX_ID),
 SX_FIELD("sync_file_ids","uint8",58,1,SX_FLAGS),
 SX_FIELD("reserved59","uint8[5]",59,5,SX_RESERVED),
};
static const sx_layout sxgm_rarc_header_be = {UINT32_C(0x60270018),"rarc_header_be",sxgm_rarc_header_be_fields,SX_COUNT(sxgm_rarc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_rarc_node_le_fields[] = {
 SX_FIELD("type","char[4]",0,4,SX_ID),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("name_hash","uint16",8,2,SX_CHECKSUM),
 SX_FIELD("entry_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("first_entry_index","uint32",12,4,SX_ID),
};
static const sx_layout sxgm_rarc_node_le = {UINT32_C(0x60270019),"rarc_node_le",sxgm_rarc_node_le_fields,SX_COUNT(sxgm_rarc_node_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_node_be_fields[] = {
 SX_FIELD("type","char[4]",0,4,SX_ID),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("name_hash","uint16",8,2,SX_CHECKSUM),
 SX_FIELD("entry_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("first_entry_index","uint32",12,4,SX_ID),
};
static const sx_layout sxgm_rarc_node_be = {UINT32_C(0x6027001a),"rarc_node_be",sxgm_rarc_node_be_fields,SX_COUNT(sxgm_rarc_node_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_rarc_file_le_fields[] = {
 SX_FIELD("file_id","uint16",0,2,SX_ID),
 SX_FIELD("name_hash","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("name_offset","uint24",4,3,SX_OFFSET),
 SX_FIELD("attributes","uint8",7,1,SX_FLAGS),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
static const sx_layout sxgm_rarc_file_le = {UINT32_C(0x6027001b),"rarc_file_le",sxgm_rarc_file_le_fields,SX_COUNT(sxgm_rarc_file_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_directory_le_fields[] = {
 SX_FIELD("file_id","uint16",0,2,SX_ID),
 SX_FIELD("name_hash","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("name_offset","uint24",4,3,SX_OFFSET),
 SX_FIELD("attributes","uint8",7,1,SX_FLAGS),
 SX_FIELD("node_index","uint32",8,4,SX_ID),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
static const sx_layout sxgm_rarc_directory_le = {UINT32_C(0x6027001c),"rarc_directory_le",sxgm_rarc_directory_le_fields,SX_COUNT(sxgm_rarc_directory_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_file_be_fields[] = {
 SX_FIELD("file_id","uint16",0,2,SX_ID),
 SX_FIELD("name_hash","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("attributes","uint8",4,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",5,3,SX_OFFSET),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
static const sx_layout sxgm_rarc_file_be = {UINT32_C(0x6027001d),"rarc_file_be",sxgm_rarc_file_be_fields,SX_COUNT(sxgm_rarc_file_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_rarc_directory_be_fields[] = {
 SX_FIELD("file_id","uint16",0,2,SX_ID),
 SX_FIELD("name_hash","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("attributes","uint8",4,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",5,3,SX_OFFSET),
 SX_FIELD("node_index","uint32",8,4,SX_ID),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
static const sx_layout sxgm_rarc_directory_be = {UINT32_C(0x6027001e),"rarc_directory_be",sxgm_rarc_directory_be_fields,SX_COUNT(sxgm_rarc_directory_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_narc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order_mark","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("header_size","uint16",12,2,SX_SIZE),
 SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxgm_narc_header = {UINT32_C(0x6027001f),"narc_header",sxgm_narc_header_fields,SX_COUNT(sxgm_narc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_narc_fat_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxgm_narc_fat = {UINT32_C(0x60270020),"narc_fat",sxgm_narc_fat_fields,SX_COUNT(sxgm_narc_fat_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_narc_entry_fields[] = {
 SX_FIELD("start_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxgm_narc_entry = {UINT32_C(0x60270021),"narc_entry",sxgm_narc_entry_fields,SX_COUNT(sxgm_narc_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_narc_block_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_ID),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxgm_narc_block = {UINT32_C(0x60270022),"narc_block",sxgm_narc_block_fields,SX_COUNT(sxgm_narc_block_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_header_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("byte_order_mark","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("version","uint16",16,2,SX_ID),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
};
static const sx_layout sxgm_sarc_header_le = {UINT32_C(0x60270023),"sarc_header_le",sxgm_sarc_header_le_fields,SX_COUNT(sxgm_sarc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_header_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("byte_order_mark","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("version","uint16",16,2,SX_ID),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
};
static const sx_layout sxgm_sarc_header_be = {UINT32_C(0x60270024),"sarc_header_be",sxgm_sarc_header_be_fields,SX_COUNT(sxgm_sarc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_sarc_fat_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("hash_multiplier","uint32",8,4,SX_NONE),
};
static const sx_layout sxgm_sarc_fat_le = {UINT32_C(0x60270025),"sarc_fat_le",sxgm_sarc_fat_le_fields,SX_COUNT(sxgm_sarc_fat_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_fat_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("hash_multiplier","uint32",8,4,SX_NONE),
};
static const sx_layout sxgm_sarc_fat_be = {UINT32_C(0x60270026),"sarc_fat_be",sxgm_sarc_fat_be_fields,SX_COUNT(sxgm_sarc_fat_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_sarc_entry_le_fields[] = {
 SX_FIELD("name_hash","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("name_attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("start_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxgm_sarc_entry_le = {UINT32_C(0x60270027),"sarc_entry_le",sxgm_sarc_entry_le_fields,SX_COUNT(sxgm_sarc_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_entry_be_fields[] = {
 SX_FIELD("name_hash","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("name_attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("start_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxgm_sarc_entry_be = {UINT32_C(0x60270028),"sarc_entry_be",sxgm_sarc_entry_be_fields,SX_COUNT(sxgm_sarc_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_sarc_names_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
};
static const sx_layout sxgm_sarc_names_le = {UINT32_C(0x60270029),"sarc_names_le",sxgm_sarc_names_le_fields,SX_COUNT(sxgm_sarc_names_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_names_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
};
static const sx_layout sxgm_sarc_names_be = {UINT32_C(0x6027002a),"sarc_names_be",sxgm_sarc_names_be_fields,SX_COUNT(sxgm_sarc_names_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_pfs_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("strings_size","uint32",8,4,SX_SIZE),
 SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxgm_pfs_header = {UINT32_C(0x6027002b),"pfs_header",sxgm_pfs_header_fields,SX_COUNT(sxgm_pfs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_pfs_entry_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("data_size","uint64",8,8,SX_SIZE),
 SX_FIELD("name_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("reserved","uint32",20,4,SX_RESERVED),
};
static const sx_layout sxgm_pfs_entry = {UINT32_C(0x6027002c),"pfs_entry",sxgm_pfs_entry_fields,SX_COUNT(sxgm_pfs_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_hfs_entry_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("data_size","uint64",8,8,SX_SIZE),
 SX_FIELD("name_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("hashed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("reserved","uint64",24,8,SX_RESERVED),
 SX_FIELD("sha256","uint8[32]",32,32,SX_CHECKSUM),
};
static const sx_layout sxgm_hfs_entry = {UINT32_C(0x6027002d),"hfs_entry",sxgm_hfs_entry_fields,SX_COUNT(sxgm_hfs_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_psarc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("compression","char[4]",8,4,SX_ID),
 SX_FIELD("toc_size","uint32",12,4,SX_SIZE),
 SX_FIELD("entry_size","uint32",16,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("block_size","uint32",24,4,SX_SIZE),
 SX_FIELD("flags","uint32",28,4,SX_FLAGS),
};
static const sx_layout sxgm_psarc_header = {UINT32_C(0x6027002e),"psarc_header",sxgm_psarc_header_fields,SX_COUNT(sxgm_psarc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_psarc_entry_fields[] = {
 SX_FIELD("name_md5","uint8[16]",0,16,SX_CHECKSUM),
 SX_FIELD("first_block_index","uint32",16,4,SX_ID),
 SX_FIELD("unpacked_size","uint40",20,5,SX_SIZE),
 SX_FIELD("data_offset","uint40",25,5,SX_OFFSET),
};
static const sx_layout sxgm_psarc_entry = {UINT32_C(0x6027002f),"psarc_entry",sxgm_psarc_entry_fields,SX_COUNT(sxgm_psarc_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_psarc_block_length_fields[] = {
 SX_FIELD("stored_length","uint16",0,2,SX_NONE),
};
static const sx_layout sxgm_psarc_block_length = {UINT32_C(0x60270030),"psarc_block_length",sxgm_psarc_block_length_fields,SX_COUNT(sxgm_psarc_block_length_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_biff_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[4]",4,4,SX_ID),
 SX_FIELD("variable_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("fixed_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("table_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxgm_biff_header = {UINT32_C(0x60270031),"biff_header",sxgm_biff_header_fields,SX_COUNT(sxgm_biff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_biff_entry_v1_fields[] = {
 SX_FIELD("resource_id","uint32",0,4,SX_ID),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("resource_type","uint32",12,4,SX_ID),
};
static const sx_layout sxgm_biff_entry_v1 = {UINT32_C(0x60270032),"biff_entry_v1",sxgm_biff_entry_v1_fields,SX_COUNT(sxgm_biff_entry_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_biff_entry_v2_fields[] = {
 SX_FIELD("resource_id","uint64",0,8,SX_ID),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("resource_type","uint32",16,4,SX_ID),
};
static const sx_layout sxgm_biff_entry_v2 = {UINT32_C(0x60270033),"biff_entry_v2",sxgm_biff_entry_v2_fields,SX_COUNT(sxgm_biff_entry_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[4]",4,4,SX_ID),
 SX_FIELD("language_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("localized_size","uint32",12,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("localized_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("keys_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("resources_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("build_year","uint32",32,4,SX_NONE),
 SX_FIELD("build_day","uint32",36,4,SX_NONE),
 SX_FIELD("description_strref","uint32",40,4,SX_ID),
 SX_FIELD("reserved","uint8[116]",44,116,SX_RESERVED),
};
static const sx_layout sxgm_erf_header = {UINT32_C(0x60270034),"erf_header",sxgm_erf_header_fields,SX_COUNT(sxgm_erf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_key16_fields[] = {
 SX_FIELD("resref","char[16]",0,16,SX_STRING),
 SX_FIELD("resource_id","uint32",16,4,SX_ID),
 SX_FIELD("resource_type","uint16",20,2,SX_ID),
 SX_FIELD("reserved","uint16",22,2,SX_RESERVED),
};
static const sx_layout sxgm_erf_key16 = {UINT32_C(0x60270035),"erf_key16",sxgm_erf_key16_fields,SX_COUNT(sxgm_erf_key16_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_key32_fields[] = {
 SX_FIELD("resref","char[32]",0,32,SX_STRING),
 SX_FIELD("resource_id","uint32",32,4,SX_ID),
 SX_FIELD("resource_type","uint16",36,2,SX_ID),
 SX_FIELD("reserved","uint16",38,2,SX_RESERVED),
};
static const sx_layout sxgm_erf_key32 = {UINT32_C(0x60270036),"erf_key32",sxgm_erf_key32_fields,SX_COUNT(sxgm_erf_key32_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_resource_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxgm_erf_resource = {UINT32_C(0x60270037),"erf_resource",sxgm_erf_resource_fields,SX_COUNT(sxgm_erf_resource_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_erf_localized_fields[] = {
 SX_FIELD("language_id","uint32",0,4,SX_ID),
 SX_FIELD("text_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxgm_erf_localized = {UINT32_C(0x60270038),"erf_localized",sxgm_erf_localized_fields,SX_COUNT(sxgm_erf_localized_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rim_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[4]",4,4,SX_ID),
 SX_FIELD("unknown8","uint32",8,4,SX_NONE),
 SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("table_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("reserved","uint8[100]",20,100,SX_RESERVED),
};
static const sx_layout sxgm_rim_header = {UINT32_C(0x60270039),"rim_header",sxgm_rim_header_fields,SX_COUNT(sxgm_rim_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rim_entry_fields[] = {
 SX_FIELD("resref","char[16]",0,16,SX_STRING),
 SX_FIELD("resource_type","uint32",16,4,SX_ID),
 SX_FIELD("resource_id","uint32",20,4,SX_ID),
 SX_FIELD("data_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxgm_rim_entry = {UINT32_C(0x6027003a),"rim_entry",sxgm_rim_entry_fields,SX_COUNT(sxgm_rim_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_bsa_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("folders_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("archive_flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("folder_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("file_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("folder_names_size","uint32",24,4,SX_SIZE),
 SX_FIELD("file_names_size","uint32",28,4,SX_SIZE),
 SX_FIELD("file_flags","uint32",32,4,SX_FLAGS),
};
static const sx_layout sxgm_bsa_header = {UINT32_C(0x6027003b),"bsa_header",sxgm_bsa_header_fields,SX_COUNT(sxgm_bsa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_bsa_folder_fields[] = {
 SX_FIELD("name_hash","uint64",0,8,SX_CHECKSUM),
 SX_FIELD("file_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("block_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxgm_bsa_folder = {UINT32_C(0x6027003c),"bsa_folder",sxgm_bsa_folder_fields,SX_COUNT(sxgm_bsa_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_bsa_folder105_fields[] = {
 SX_FIELD("name_hash","uint64",0,8,SX_CHECKSUM),
 SX_FIELD("file_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("unknown12","uint32",12,4,SX_NONE),
 SX_FIELD("block_offset","uint64",16,8,SX_OFFSET),
};
static const sx_layout sxgm_bsa_folder105 = {UINT32_C(0x6027003d),"bsa_folder105",sxgm_bsa_folder105_fields,SX_COUNT(sxgm_bsa_folder105_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_bsa_file_fields[] = {
 SX_FIELD("name_hash","uint64",0,8,SX_CHECKSUM),
 SX_FIELD("size_flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxgm_bsa_file = {UINT32_C(0x6027003e),"bsa_file",sxgm_bsa_file_fields,SX_COUNT(sxgm_bsa_file_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_game_name_length8_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxgm_game_name_length8 = {UINT32_C(0x6027003f),"game_name_length8",sxgm_game_name_length8_fields,SX_COUNT(sxgm_game_name_length8_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_game_name_length16_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxgm_game_name_length16 = {UINT32_C(0x60270040),"game_name_length16",sxgm_game_name_length16_fields,SX_COUNT(sxgm_game_name_length16_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_ba2_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("archive_type","char[4]",8,4,SX_ID),
 SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("names_offset","uint64",16,8,SX_OFFSET),
};
static const sx_layout sxgm_ba2_header = {UINT32_C(0x60270041),"ba2_header",sxgm_ba2_header_fields,SX_COUNT(sxgm_ba2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_ba2_v2_extension_fields[] = {
 SX_FIELD("unknown","uint64",0,8,SX_NONE),
};
static const sx_layout sxgm_ba2_v2_extension = {UINT32_C(0x60270042),"ba2_v2_extension",sxgm_ba2_v2_extension_fields,SX_COUNT(sxgm_ba2_v2_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_ba2_v3_compression_fields[] = {
 SX_FIELD("compression","uint32",0,4,SX_ID),
};
static const sx_layout sxgm_ba2_v3_compression = {UINT32_C(0x60270043),"ba2_v3_compression",sxgm_ba2_v3_compression_fields,SX_COUNT(sxgm_ba2_v3_compression_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_ba2_general_entry_fields[] = {
 SX_FIELD("name_hash","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("extension","char[4]",4,4,SX_STRING),
 SX_FIELD("directory_hash","uint32",8,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("data_offset","uint64",16,8,SX_OFFSET),
 SX_FIELD("packed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",28,4,SX_SIZE),
 SX_FIELD("alignment","uint32",32,4,SX_SIGNATURE),
};
static const sx_layout sxgm_ba2_general_entry = {UINT32_C(0x60270044),"ba2_general_entry",sxgm_ba2_general_entry_fields,SX_COUNT(sxgm_ba2_general_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_idtech_bsp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
};
static const sx_layout sxgm_idtech_bsp_header = {UINT32_C(0x60270045),"idtech_bsp_header",sxgm_idtech_bsp_header_fields,SX_COUNT(sxgm_idtech_bsp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_idtech_bsp_lump_fields[] = {
 SX_FIELD("file_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("file_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxgm_idtech_bsp_lump = {UINT32_C(0x60270046),"idtech_bsp_lump",sxgm_idtech_bsp_lump_fields,SX_COUNT(sxgm_idtech_bsp_lump_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_valve_bsp_lump_fields[] = {
 SX_FIELD("file_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("file_size","int32",4,4,SX_SIZE),
 SX_FIELD("version","int32",8,4,SX_ID),
 SX_FIELD("fourcc","char[4]",12,4,SX_ID),
};
static const sx_layout sxgm_valve_bsp_lump = {UINT32_C(0x60270047),"valve_bsp_lump",sxgm_valve_bsp_lump_fields,SX_COUNT(sxgm_valve_bsp_lump_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_valve_bsp_revision_fields[] = {
 SX_FIELD("revision","int32",0,4,SX_NONE),
};
static const sx_layout sxgm_valve_bsp_revision = {UINT32_C(0x60270048),"valve_bsp_revision",sxgm_valve_bsp_revision_fields,SX_COUNT(sxgm_valve_bsp_revision_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("skin_width","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("skin_height","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("frame_size","int32",16,4,SX_SIZE),
 SX_FIELD("skin_count","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("vertex_count","int32",24,4,SX_COUNT_PROP),
 SX_FIELD("texcoord_count","int32",28,4,SX_COUNT_PROP),
 SX_FIELD("triangle_count","int32",32,4,SX_COUNT_PROP),
 SX_FIELD("gl_command_words","int32",36,4,SX_COUNT_PROP),
 SX_FIELD("frame_count","int32",40,4,SX_COUNT_PROP),
 SX_FIELD("skins_offset","int32",44,4,SX_OFFSET),
 SX_FIELD("texcoords_offset","int32",48,4,SX_OFFSET),
 SX_FIELD("triangles_offset","int32",52,4,SX_OFFSET),
 SX_FIELD("frames_offset","int32",56,4,SX_OFFSET),
 SX_FIELD("gl_commands_offset","int32",60,4,SX_OFFSET),
 SX_FIELD("end_offset","int32",64,4,SX_OFFSET),
};
static const sx_layout sxgm_md2_header = {UINT32_C(0x60270049),"md2_header",sxgm_md2_header_fields,SX_COUNT(sxgm_md2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_game_skin_name_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_STRING),
};
static const sx_layout sxgm_game_skin_name = {UINT32_C(0x6027004a),"game_skin_name",sxgm_game_skin_name_fields,SX_COUNT(sxgm_game_skin_name_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_texcoord_fields[] = {
 SX_FIELD("s","int16",0,2,SX_NONE),
 SX_FIELD("t","int16",2,2,SX_NONE),
};
static const sx_layout sxgm_md2_texcoord = {UINT32_C(0x6027004b),"md2_texcoord",sxgm_md2_texcoord_fields,SX_COUNT(sxgm_md2_texcoord_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_triangle_fields[] = {
 SX_FIELD("vertex0","int16",0,2,SX_ID),
 SX_FIELD("vertex1","int16",2,2,SX_ID),
 SX_FIELD("vertex2","int16",4,2,SX_ID),
 SX_FIELD("texcoord0","int16",6,2,SX_ID),
 SX_FIELD("texcoord1","int16",8,2,SX_ID),
 SX_FIELD("texcoord2","int16",10,2,SX_ID),
};
static const sx_layout sxgm_md2_triangle = {UINT32_C(0x6027004c),"md2_triangle",sxgm_md2_triangle_fields,SX_COUNT(sxgm_md2_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_frame_fields[] = {
 SX_FIELD("scale_0","float32",0,4,SX_NONE),
 SX_FIELD("scale_1","float32",4,4,SX_NONE),
 SX_FIELD("scale_2","float32",8,4,SX_NONE),
 SX_FIELD("translate_0","float32",12,4,SX_NONE),
 SX_FIELD("translate_1","float32",16,4,SX_NONE),
 SX_FIELD("translate_2","float32",20,4,SX_NONE),
 SX_FIELD("name","char[16]",24,16,SX_STRING),
};
static const sx_layout sxgm_md2_frame = {UINT32_C(0x6027004d),"md2_frame",sxgm_md2_frame_fields,SX_COUNT(sxgm_md2_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_vertex_fields[] = {
 SX_FIELD("x","uint8",0,1,SX_NONE),
 SX_FIELD("y","uint8",1,1,SX_NONE),
 SX_FIELD("z","uint8",2,1,SX_NONE),
 SX_FIELD("normal_index","uint8",3,1,SX_ID),
};
static const sx_layout sxgm_quake_vertex = {UINT32_C(0x6027004e),"quake_vertex",sxgm_quake_vertex_fields,SX_COUNT(sxgm_quake_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_gl_command_fields[] = {
 SX_FIELD("vertex_count_signed","int32",0,4,SX_NONE),
};
static const sx_layout sxgm_md2_gl_command = {UINT32_C(0x6027004f),"md2_gl_command",sxgm_md2_gl_command_fields,SX_COUNT(sxgm_md2_gl_command_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md2_gl_vertex_fields[] = {
 SX_FIELD("s","float32",0,4,SX_NONE),
 SX_FIELD("t","float32",4,4,SX_NONE),
 SX_FIELD("vertex_index","int32",8,4,SX_ID),
};
static const sx_layout sxgm_md2_gl_vertex = {UINT32_C(0x60270050),"md2_gl_vertex",sxgm_md2_gl_vertex_fields,SX_COUNT(sxgm_md2_gl_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("name","char[64]",8,64,SX_STRING),
 SX_FIELD("flags","int32",72,4,SX_FLAGS),
 SX_FIELD("frame_count","int32",76,4,SX_COUNT_PROP),
 SX_FIELD("tag_count","int32",80,4,SX_COUNT_PROP),
 SX_FIELD("surface_count","int32",84,4,SX_COUNT_PROP),
 SX_FIELD("skin_count","int32",88,4,SX_COUNT_PROP),
 SX_FIELD("frames_offset","int32",92,4,SX_OFFSET),
 SX_FIELD("tags_offset","int32",96,4,SX_OFFSET),
 SX_FIELD("surfaces_offset","int32",100,4,SX_OFFSET),
 SX_FIELD("end_offset","int32",104,4,SX_OFFSET),
};
static const sx_layout sxgm_md3_header = {UINT32_C(0x60270051),"md3_header",sxgm_md3_header_fields,SX_COUNT(sxgm_md3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_frame_fields[] = {
 SX_FIELD("bounds_min_0","float32",0,4,SX_NONE),
 SX_FIELD("bounds_min_1","float32",4,4,SX_NONE),
 SX_FIELD("bounds_min_2","float32",8,4,SX_NONE),
 SX_FIELD("bounds_max_0","float32",12,4,SX_NONE),
 SX_FIELD("bounds_max_1","float32",16,4,SX_NONE),
 SX_FIELD("bounds_max_2","float32",20,4,SX_NONE),
 SX_FIELD("origin_0","float32",24,4,SX_NONE),
 SX_FIELD("origin_1","float32",28,4,SX_NONE),
 SX_FIELD("origin_2","float32",32,4,SX_NONE),
 SX_FIELD("radius","float32",36,4,SX_NONE),
 SX_FIELD("name","char[16]",40,16,SX_STRING),
};
static const sx_layout sxgm_md3_frame = {UINT32_C(0x60270052),"md3_frame",sxgm_md3_frame_fields,SX_COUNT(sxgm_md3_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_tag_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("origin_0","float32",64,4,SX_NONE),
 SX_FIELD("origin_1","float32",68,4,SX_NONE),
 SX_FIELD("origin_2","float32",72,4,SX_NONE),
 SX_FIELD("axis_0","float32",76,4,SX_NONE),
 SX_FIELD("axis_1","float32",80,4,SX_NONE),
 SX_FIELD("axis_2","float32",84,4,SX_NONE),
 SX_FIELD("axis_3","float32",88,4,SX_NONE),
 SX_FIELD("axis_4","float32",92,4,SX_NONE),
 SX_FIELD("axis_5","float32",96,4,SX_NONE),
 SX_FIELD("axis_6","float32",100,4,SX_NONE),
 SX_FIELD("axis_7","float32",104,4,SX_NONE),
 SX_FIELD("axis_8","float32",108,4,SX_NONE),
};
static const sx_layout sxgm_md3_tag = {UINT32_C(0x60270053),"md3_tag",sxgm_md3_tag_fields,SX_COUNT(sxgm_md3_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_surface_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[64]",4,64,SX_STRING),
 SX_FIELD("flags","int32",68,4,SX_FLAGS),
 SX_FIELD("frame_count","int32",72,4,SX_COUNT_PROP),
 SX_FIELD("shader_count","int32",76,4,SX_COUNT_PROP),
 SX_FIELD("vertex_count","int32",80,4,SX_COUNT_PROP),
 SX_FIELD("triangle_count","int32",84,4,SX_COUNT_PROP),
 SX_FIELD("triangles_offset","int32",88,4,SX_OFFSET),
 SX_FIELD("shaders_offset","int32",92,4,SX_OFFSET),
 SX_FIELD("texcoords_offset","int32",96,4,SX_OFFSET),
 SX_FIELD("vertices_offset","int32",100,4,SX_OFFSET),
 SX_FIELD("end_offset","int32",104,4,SX_OFFSET),
};
static const sx_layout sxgm_md3_surface = {UINT32_C(0x60270054),"md3_surface",sxgm_md3_surface_fields,SX_COUNT(sxgm_md3_surface_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_triangle_fields[] = {
 SX_FIELD("vertex0","int32",0,4,SX_ID),
 SX_FIELD("vertex1","int32",4,4,SX_ID),
 SX_FIELD("vertex2","int32",8,4,SX_ID),
};
static const sx_layout sxgm_md3_triangle = {UINT32_C(0x60270055),"md3_triangle",sxgm_md3_triangle_fields,SX_COUNT(sxgm_md3_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_shader_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("shader_index","int32",64,4,SX_ID),
};
static const sx_layout sxgm_md3_shader = {UINT32_C(0x60270056),"md3_shader",sxgm_md3_shader_fields,SX_COUNT(sxgm_md3_shader_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_texcoord_fields[] = {
 SX_FIELD("s","float32",0,4,SX_NONE),
 SX_FIELD("t","float32",4,4,SX_NONE),
};
static const sx_layout sxgm_md3_texcoord = {UINT32_C(0x60270057),"md3_texcoord",sxgm_md3_texcoord_fields,SX_COUNT(sxgm_md3_texcoord_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_vertex_fields[] = {
 SX_FIELD("x","int16",0,2,SX_NONE),
 SX_FIELD("y","int16",2,2,SX_NONE),
 SX_FIELD("z","int16",4,2,SX_NONE),
 SX_FIELD("normal","int16",6,2,SX_NONE),
};
static const sx_layout sxgm_md3_vertex = {UINT32_C(0x60270058),"md3_vertex",sxgm_md3_vertex_fields,SX_COUNT(sxgm_md3_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_qvm_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("instruction_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("code_offset","int32",8,4,SX_OFFSET),
 SX_FIELD("code_size","int32",12,4,SX_SIZE),
 SX_FIELD("data_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("data_size","int32",20,4,SX_SIZE),
 SX_FIELD("literals_size","int32",24,4,SX_SIZE),
 SX_FIELD("bss_size","int32",28,4,SX_SIZE),
};
static const sx_layout sxgm_qvm_header = {UINT32_C(0x60270059),"qvm_header",sxgm_qvm_header_fields,SX_COUNT(sxgm_qvm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_sprite_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("sprite_type","int32",8,4,SX_ID),
 SX_FIELD("bounding_radius","float32",12,4,SX_NONE),
 SX_FIELD("width","int32",16,4,SX_COUNT_PROP),
 SX_FIELD("height","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("frame_count","int32",24,4,SX_COUNT_PROP),
 SX_FIELD("beam_length","float32",28,4,SX_NONE),
 SX_FIELD("sync_type","int32",32,4,SX_ID),
};
static const sx_layout sxgm_quake_sprite_header = {UINT32_C(0x6027005a),"quake_sprite_header",sxgm_quake_sprite_header_fields,SX_COUNT(sxgm_quake_sprite_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_frame_type_fields[] = {
 SX_FIELD("frame_type","int32",0,4,SX_ID),
};
static const sx_layout sxgm_quake_frame_type = {UINT32_C(0x6027005b),"quake_frame_type",sxgm_quake_frame_type_fields,SX_COUNT(sxgm_quake_frame_type_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_group_count_fields[] = {
 SX_FIELD("frame_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxgm_quake_group_count = {UINT32_C(0x6027005c),"quake_group_count",sxgm_quake_group_count_fields,SX_COUNT(sxgm_quake_group_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_interval_fields[] = {
 SX_FIELD("interval","float32",0,4,SX_NONE),
};
static const sx_layout sxgm_quake_interval = {UINT32_C(0x6027005d),"quake_interval",sxgm_quake_interval_fields,SX_COUNT(sxgm_quake_interval_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_sprite_frame_fields[] = {
 SX_FIELD("origin_x","int32",0,4,SX_NONE),
 SX_FIELD("origin_y","int32",4,4,SX_NONE),
 SX_FIELD("width","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("height","int32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxgm_quake_sprite_frame = {UINT32_C(0x6027005e),"quake_sprite_frame",sxgm_quake_sprite_frame_fields,SX_COUNT(sxgm_quake_sprite_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_mdl_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("scale_0","float32",8,4,SX_NONE),
 SX_FIELD("scale_1","float32",12,4,SX_NONE),
 SX_FIELD("scale_2","float32",16,4,SX_NONE),
 SX_FIELD("origin_0","float32",20,4,SX_NONE),
 SX_FIELD("origin_1","float32",24,4,SX_NONE),
 SX_FIELD("origin_2","float32",28,4,SX_NONE),
 SX_FIELD("bounding_radius","float32",32,4,SX_NONE),
 SX_FIELD("eye_position_0","float32",36,4,SX_NONE),
 SX_FIELD("eye_position_1","float32",40,4,SX_NONE),
 SX_FIELD("eye_position_2","float32",44,4,SX_NONE),
 SX_FIELD("skin_count","int32",48,4,SX_COUNT_PROP),
 SX_FIELD("skin_width","int32",52,4,SX_COUNT_PROP),
 SX_FIELD("skin_height","int32",56,4,SX_COUNT_PROP),
 SX_FIELD("vertex_count","int32",60,4,SX_COUNT_PROP),
 SX_FIELD("triangle_count","int32",64,4,SX_COUNT_PROP),
 SX_FIELD("frame_count","int32",68,4,SX_COUNT_PROP),
 SX_FIELD("sync_type","int32",72,4,SX_ID),
 SX_FIELD("flags","int32",76,4,SX_FLAGS),
 SX_FIELD("model_size","float32",80,4,SX_NONE),
};
static const sx_layout sxgm_quake_mdl_header = {UINT32_C(0x6027005f),"quake_mdl_header",sxgm_quake_mdl_header_fields,SX_COUNT(sxgm_quake_mdl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_skin_type_fields[] = {
 SX_FIELD("skin_type","int32",0,4,SX_ID),
};
static const sx_layout sxgm_quake_skin_type = {UINT32_C(0x60270060),"quake_skin_type",sxgm_quake_skin_type_fields,SX_COUNT(sxgm_quake_skin_type_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_stvert_fields[] = {
 SX_FIELD("on_seam","int32",0,4,SX_FLAGS),
 SX_FIELD("s","int32",4,4,SX_NONE),
 SX_FIELD("t","int32",8,4,SX_NONE),
};
static const sx_layout sxgm_quake_stvert = {UINT32_C(0x60270061),"quake_stvert",sxgm_quake_stvert_fields,SX_COUNT(sxgm_quake_stvert_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_triangle_fields[] = {
 SX_FIELD("faces_front","int32",0,4,SX_FLAGS),
 SX_FIELD("vertex0","int32",4,4,SX_ID),
 SX_FIELD("vertex1","int32",8,4,SX_ID),
 SX_FIELD("vertex2","int32",12,4,SX_ID),
};
static const sx_layout sxgm_quake_triangle = {UINT32_C(0x60270062),"quake_triangle",sxgm_quake_triangle_fields,SX_COUNT(sxgm_quake_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_mdl_frame_fields[] = {
 SX_FIELD("bbox_min_x","uint8",0,1,SX_NONE),
 SX_FIELD("bbox_min_y","uint8",1,1,SX_NONE),
 SX_FIELD("bbox_min_z","uint8",2,1,SX_NONE),
 SX_FIELD("bbox_min_normal","uint8",3,1,SX_ID),
 SX_FIELD("bbox_max_x","uint8",4,1,SX_NONE),
 SX_FIELD("bbox_max_y","uint8",5,1,SX_NONE),
 SX_FIELD("bbox_max_z","uint8",6,1,SX_NONE),
 SX_FIELD("bbox_max_normal","uint8",7,1,SX_ID),
 SX_FIELD("name","char[16]",8,16,SX_STRING),
};
static const sx_layout sxgm_quake_mdl_frame = {UINT32_C(0x60270063),"quake_mdl_frame",sxgm_quake_mdl_frame_fields,SX_COUNT(sxgm_quake_mdl_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_studio_v10_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("name","char[64]",8,64,SX_STRING),
 SX_FIELD("file_size","int32",72,4,SX_SIZE),
 SX_FIELD("eye_position_0","float32",76,4,SX_NONE),
 SX_FIELD("eye_position_1","float32",80,4,SX_NONE),
 SX_FIELD("eye_position_2","float32",84,4,SX_NONE),
 SX_FIELD("hull_min_0","float32",88,4,SX_NONE),
 SX_FIELD("hull_min_1","float32",92,4,SX_NONE),
 SX_FIELD("hull_min_2","float32",96,4,SX_NONE),
 SX_FIELD("hull_max_0","float32",100,4,SX_NONE),
 SX_FIELD("hull_max_1","float32",104,4,SX_NONE),
 SX_FIELD("hull_max_2","float32",108,4,SX_NONE),
 SX_FIELD("bbox_min_0","float32",112,4,SX_NONE),
 SX_FIELD("bbox_min_1","float32",116,4,SX_NONE),
 SX_FIELD("bbox_min_2","float32",120,4,SX_NONE),
 SX_FIELD("bbox_max_0","float32",124,4,SX_NONE),
 SX_FIELD("bbox_max_1","float32",128,4,SX_NONE),
 SX_FIELD("bbox_max_2","float32",132,4,SX_NONE),
 SX_FIELD("flags","int32",136,4,SX_FLAGS),
 SX_FIELD("bone_count","int32",140,4,SX_COUNT_PROP),
 SX_FIELD("bones_offset","int32",144,4,SX_OFFSET),
 SX_FIELD("bone_controller_count","int32",148,4,SX_COUNT_PROP),
 SX_FIELD("bone_controllers_offset","int32",152,4,SX_OFFSET),
 SX_FIELD("hitbox_count","int32",156,4,SX_COUNT_PROP),
 SX_FIELD("hitboxs_offset","int32",160,4,SX_OFFSET),
 SX_FIELD("sequence_count","int32",164,4,SX_COUNT_PROP),
 SX_FIELD("sequences_offset","int32",168,4,SX_OFFSET),
 SX_FIELD("sequence_group_count","int32",172,4,SX_COUNT_PROP),
 SX_FIELD("sequence_groups_offset","int32",176,4,SX_OFFSET),
 SX_FIELD("texture_count","int32",180,4,SX_COUNT_PROP),
 SX_FIELD("textures_offset","int32",184,4,SX_OFFSET),
 SX_FIELD("texture_data_offset","int32",188,4,SX_OFFSET),
 SX_FIELD("skinref_count","int32",192,4,SX_COUNT_PROP),
 SX_FIELD("skin_family_count","int32",196,4,SX_COUNT_PROP),
 SX_FIELD("skins_offset","int32",200,4,SX_OFFSET),
 SX_FIELD("bodypart_count","int32",204,4,SX_COUNT_PROP),
 SX_FIELD("bodyparts_offset","int32",208,4,SX_OFFSET),
 SX_FIELD("attachment_count","int32",212,4,SX_COUNT_PROP),
 SX_FIELD("attachments_offset","int32",216,4,SX_OFFSET),
 SX_FIELD("sound_table","int32",220,4,SX_NONE),
 SX_FIELD("sound_index","int32",224,4,SX_NONE),
 SX_FIELD("sound_groups","int32",228,4,SX_NONE),
 SX_FIELD("sound_group_index","int32",232,4,SX_NONE),
 SX_FIELD("transition_count","int32",236,4,SX_COUNT_PROP),
 SX_FIELD("transitions_offset","int32",240,4,SX_OFFSET),
};
static const sx_layout sxgm_studio_v10_header = {UINT32_C(0x60270064),"studio_v10_header",sxgm_studio_v10_header_fields,SX_COUNT(sxgm_studio_v10_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_studio_texture_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("flags","int32",64,4,SX_FLAGS),
 SX_FIELD("width","int32",68,4,SX_COUNT_PROP),
 SX_FIELD("height","int32",72,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","int32",76,4,SX_OFFSET),
};
static const sx_layout sxgm_studio_texture = {UINT32_C(0x60270065),"studio_texture",sxgm_studio_texture_fields,SX_COUNT(sxgm_studio_texture_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_studio_skinref_fields[] = {
 SX_FIELD("texture_index","int16",0,2,SX_ID),
};
static const sx_layout sxgm_studio_skinref = {UINT32_C(0x60270066),"studio_skinref",sxgm_studio_skinref_fields,SX_COUNT(sxgm_studio_skinref_fields),SX_LE};
static const sx_layout *const sx_gamemeta_layouts[] = {
 &sxgm_ines_header,
 &sxgm_nes2_header,
 &sxgm_lynx_header,
 &sxgm_crt_header,
 &sxgm_crt_chip,
 &sxgm_godot_pck_v1,
 &sxgm_godot_pck_v2,
 &sxgm_godot_pck_v3,
 &sxgm_godot_pck_v4_salted,
 &sxgm_godot_file_count,
 &sxgm_godot_path_length,
 &sxgm_godot_entry_v1,
 &sxgm_godot_entry_v2,
 &sxgm_godot_encrypted_block,
 &sxgm_godot_trailer,
 &sxgm_vpk_header,
 &sxgm_vpk_v2_sections,
 &sxgm_vpk_entry,
 &sxgm_vpk_archive_md5,
 &sxgm_vpk_other_md5,
 &sxgm_vpk_public_key_length,
 &sxgm_vpk_signature_length,
 &sxgm_rarc_header_le,
 &sxgm_rarc_header_be,
 &sxgm_rarc_node_le,
 &sxgm_rarc_node_be,
 &sxgm_rarc_file_le,
 &sxgm_rarc_directory_le,
 &sxgm_rarc_file_be,
 &sxgm_rarc_directory_be,
 &sxgm_narc_header,
 &sxgm_narc_fat,
 &sxgm_narc_entry,
 &sxgm_narc_block,
 &sxgm_sarc_header_le,
 &sxgm_sarc_header_be,
 &sxgm_sarc_fat_le,
 &sxgm_sarc_fat_be,
 &sxgm_sarc_entry_le,
 &sxgm_sarc_entry_be,
 &sxgm_sarc_names_le,
 &sxgm_sarc_names_be,
 &sxgm_pfs_header,
 &sxgm_pfs_entry,
 &sxgm_hfs_entry,
 &sxgm_psarc_header,
 &sxgm_psarc_entry,
 &sxgm_psarc_block_length,
 &sxgm_biff_header,
 &sxgm_biff_entry_v1,
 &sxgm_biff_entry_v2,
 &sxgm_erf_header,
 &sxgm_erf_key16,
 &sxgm_erf_key32,
 &sxgm_erf_resource,
 &sxgm_erf_localized,
 &sxgm_rim_header,
 &sxgm_rim_entry,
 &sxgm_bsa_header,
 &sxgm_bsa_folder,
 &sxgm_bsa_folder105,
 &sxgm_bsa_file,
 &sxgm_game_name_length8,
 &sxgm_game_name_length16,
 &sxgm_ba2_header,
 &sxgm_ba2_v2_extension,
 &sxgm_ba2_v3_compression,
 &sxgm_ba2_general_entry,
 &sxgm_idtech_bsp_header,
 &sxgm_idtech_bsp_lump,
 &sxgm_valve_bsp_lump,
 &sxgm_valve_bsp_revision,
 &sxgm_md2_header,
 &sxgm_game_skin_name,
 &sxgm_md2_texcoord,
 &sxgm_md2_triangle,
 &sxgm_md2_frame,
 &sxgm_quake_vertex,
 &sxgm_md2_gl_command,
 &sxgm_md2_gl_vertex,
 &sxgm_md3_header,
 &sxgm_md3_frame,
 &sxgm_md3_tag,
 &sxgm_md3_surface,
 &sxgm_md3_triangle,
 &sxgm_md3_shader,
 &sxgm_md3_texcoord,
 &sxgm_md3_vertex,
 &sxgm_qvm_header,
 &sxgm_quake_sprite_header,
 &sxgm_quake_frame_type,
 &sxgm_quake_group_count,
 &sxgm_quake_interval,
 &sxgm_quake_sprite_frame,
 &sxgm_quake_mdl_header,
 &sxgm_quake_skin_type,
 &sxgm_quake_stvert,
 &sxgm_quake_triangle,
 &sxgm_quake_mdl_frame,
 &sxgm_studio_v10_header,
 &sxgm_studio_texture,
 &sxgm_studio_skinref,
};
static bool sx_gamemeta_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x60270000U||id>=0x60280000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x60270001U:
 if(!xx_rt_wcscmp(r->name,L"prg_rom_units"))text=L"Number of 16 KiB PRG ROM units.";
 if(!xx_rt_wcscmp(r->name,L"chr_rom_units"))text=L"Number of 8 KiB CHR ROM units; zero uses CHR RAM.";
 if(!xx_rt_wcscmp(r->name,L"flags6"))text=L"Low bits: mirroring, battery, trainer, four-screen; high nibble: mapper low bits.";
 if(!xx_rt_wcscmp(r->name,L"flags7"))text=L"High nibble: mapper high bits; low bits: console and header format.";
 if(!xx_rt_wcscmp(r->name,L"prg_ram_units"))text=L"Number of 8 KiB PRG RAM units; zero conventionally means one unit.";
 break;
 case 0x60270002U:
 if(!xx_rt_wcscmp(r->name,L"prg_rom_units_low"))text=L"Low eight bits of the linear 16 KiB PRG ROM unit count; extended by rom_size_high.";
 if(!xx_rt_wcscmp(r->name,L"chr_rom_units_low"))text=L"Low eight bits of the linear 8 KiB CHR ROM unit count; extended by rom_size_high.";
 if(!xx_rt_wcscmp(r->name,L"rom_size_high"))text=L"Low/high nibbles extend PRG/CHR counts; value 15 selects exponent encoding, outside the native reader scope.";
 if(!xx_rt_wcscmp(r->name,L"prg_ram_shifts"))text=L"Low/high nibbles encode volatile/nonvolatile RAM: zero means absent, otherwise 64 << nibble bytes.";
 if(!xx_rt_wcscmp(r->name,L"chr_ram_shifts"))text=L"Low/high nibbles encode volatile/nonvolatile CHR RAM: zero means absent, otherwise 64 << nibble bytes.";
 if(!xx_rt_wcscmp(r->name,L"misc_rom_count"))text=L"Low two bits are the miscellaneous ROM count; these variants are excluded by the native reader.";
 break;
 case 0x60270003U:
 if(!xx_rt_wcscmp(r->name,L"bank0_page_size"))text=L"Bank 0 consists of 256 pages of this byte size.";
 if(!xx_rt_wcscmp(r->name,L"bank1_page_size"))text=L"Bank 1 consists of 256 pages; zero means absent.";
 if(!xx_rt_wcscmp(r->name,L"rotation"))text=L"0=none, 1=left, 2=right.";
 if(!xx_rt_wcscmp(r->name,L"audin"))text=L"Bit 0 enables additional AUDIN-addressed banks; excluded by the native reader.";
 if(!xx_rt_wcscmp(r->name,L"eeprom"))text=L"Low bits select 93C46/56/66/76/86; bit 6=SD support, bit 7=eight-bit EEPROM mode.";
 break;
 case 0x60270005U:
 if(!xx_rt_wcscmp(r->name,L"packet_size"))text=L"Includes this 16-byte CHIP header and any packet padding; RAM chips may omit image bytes.";
 if(!xx_rt_wcscmp(r->name,L"chip_type"))text=L"0=ROM, 1=RAM, 2=flash ROM, 3=EEPROM (broader CRT reader).";
 break;
 case 0x60270007U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=encrypted directory; bit 1=file_base relative to pack header.";
 if(!xx_rt_wcscmp(r->name,L"file_base"))text=L"Payload offset origin; pack-relative when flag 1 is set, otherwise relative to the enclosing file.";
 break;
 case 0x60270008U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=encrypted directory; bit 1=relative base; bit 2=sparse bundle.";
 if(!xx_rt_wcscmp(r->name,L"file_base"))text=L"Payload origin relative to this pack header.";
 if(!xx_rt_wcscmp(r->name,L"directory_offset"))text=L"Directory count word offset relative to this pack header.";
 break;
 case 0x60270009U:
 if(!xx_rt_wcscmp(r->name,L"file_base"))text=L"Payload origin relative to this pack header.";
 if(!xx_rt_wcscmp(r->name,L"directory_offset"))text=L"Directory count word offset relative to this pack header.";
 if(!xx_rt_wcscmp(r->name,L"salt"))text=L"Version 4 encrypted sparse-bundle key derivation salt.";
 break;
 case 0x6027000bU:
 if(!xx_rt_wcscmp(r->name,L"path_size"))text=L"Padded UTF-8 path byte count, including its terminating NUL.";
 break;
 case 0x6027000cU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Payload byte offset relative to the pack version-specific file_base.";
 break;
 case 0x6027000dU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Payload byte offset relative to the pack version-specific file_base.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=encrypted, bit 1=removal, bit 2=delta.";
 break;
 case 0x6027000eU:
 if(!xx_rt_wcscmp(r->name,L"plain_size"))text=L"Decoded plaintext length; ciphertext occupies the length rounded up to 16 bytes.";
 break;
 case 0x6027000fU:
 if(!xx_rt_wcscmp(r->name,L"pack_size"))text=L"Pack bytes preceding this 12-byte embedded-pack trailer.";
 break;
 case 0x60270012U:
 if(!xx_rt_wcscmp(r->name,L"archive_index"))text=L"0x7FFF means the directory file data section; other values name an external numbered archive.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset in the selected archive data section, not necessarily this file.";
 break;
 case 0x60270013U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Offset in the selected external archive.";
 break;
 case 0x60270017U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"nodes_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"entries_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"strings_offset"))text=L"Relative to byte 0x20 in this archive.";
 break;
 case 0x60270018U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"nodes_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"entries_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"strings_offset"))text=L"Relative to byte 0x20 in this archive.";
 break;
 case 0x60270019U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string pool.";
 break;
 case 0x6027001aU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string pool.";
 break;
 case 0x6027001bU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"Bit 0=file, bit 1=directory, bit 2=compressed, bit 7=Yaz0.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to the archive data section.";
 break;
 case 0x6027001cU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"Bit 0=file, bit 1=directory, bit 2=compressed, bit 7=Yaz0.";
 if(!xx_rt_wcscmp(r->name,L"node_index"))text=L"Directory node index; 0xFFFFFFFF is the root parent sentinel.";
 break;
 case 0x6027001dU:
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"Bit 0=file, bit 1=directory, bit 2=compressed, bit 7=Yaz0.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to the archive data section.";
 break;
 case 0x6027001eU:
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"Bit 0=file, bit 1=directory, bit 2=compressed, bit 7=Yaz0.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"node_index"))text=L"Directory node index; 0xFFFFFFFF is the root parent sentinel.";
 break;
 case 0x60270021U:
 if(!xx_rt_wcscmp(r->name,L"start_offset"))text=L"Relative to the GMIF image payload.";
 if(!xx_rt_wcscmp(r->name,L"end_offset"))text=L"Exclusive endpoint relative to the GMIF image payload.";
 break;
 case 0x60270027U:
 if(!xx_rt_wcscmp(r->name,L"name_attributes"))text=L"High byte=has name; low 24 bits=string-pool offset in four-byte units.";
 if(!xx_rt_wcscmp(r->name,L"start_offset"))text=L"Relative to the data section.";
 if(!xx_rt_wcscmp(r->name,L"end_offset"))text=L"Exclusive endpoint relative to the data section.";
 break;
 case 0x60270028U:
 if(!xx_rt_wcscmp(r->name,L"name_attributes"))text=L"High byte=has name; low 24 bits=string-pool offset in four-byte units.";
 if(!xx_rt_wcscmp(r->name,L"start_offset"))text=L"Relative to the data section.";
 if(!xx_rt_wcscmp(r->name,L"end_offset"))text=L"Exclusive endpoint relative to the data section.";
 break;
 case 0x6027002cU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the payload area after the directory and string pool.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string pool.";
 break;
 case 0x6027002dU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the payload area after the directory and string pool.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"hashed_size"))text=L"Length of the initial member region covered by sha256.";
 break;
 case 0x60270030U:
 if(!xx_rt_wcscmp(r->name,L"stored_length"))text=L"Zero encodes a full 65536-byte stored block; nonzero is the physical block byte length.";
 break;
 case 0x60270034U:
 if(!xx_rt_wcscmp(r->name,L"build_year"))text=L"Years since 1900.";
 if(!xx_rt_wcscmp(r->name,L"build_day"))text=L"Zero-based day of the year.";
 if(!xx_rt_wcscmp(r->name,L"description_strref"))text=L"String-reference index; 0xFFFFFFFF means absent.";
 break;
 case 0x6027003bU:
 if(!xx_rt_wcscmp(r->name,L"archive_flags"))text=L"Bit 0=folder names, bit 1=file names, bit 2=default compression; bit 8=embedded file names for v104/105.";
 break;
 case 0x6027003cU:
 if(!xx_rt_wcscmp(r->name,L"block_offset"))text=L"Encoded folder block offset includes the file-name-pool byte length.";
 break;
 case 0x6027003dU:
 if(!xx_rt_wcscmp(r->name,L"block_offset"))text=L"Encoded folder block offset includes the file-name-pool byte length.";
 break;
 case 0x6027003eU:
 if(!xx_rt_wcscmp(r->name,L"size_flags"))text=L"Low 30 bits=stored byte length; bit 30 toggles archive default compression; bit 31 is reserved.";
 break;
 case 0x60270043U:
 if(!xx_rt_wcscmp(r->name,L"compression"))text=L"0=zlib, 3=LZ4.";
 break;
 case 0x60270044U:
 if(!xx_rt_wcscmp(r->name,L"packed_size"))text=L"Zero denotes a stored member of unpacked_size bytes.";
 if(!xx_rt_wcscmp(r->name,L"alignment"))text=L"Native general-file record marker 0xBAADF00D.";
 break;
 case 0x60270047U:
 if(!xx_rt_wcscmp(r->name,L"fourcc"))text=L"Compression identifier/uncompressed-length slot; the native reader supports zero, uncompressed records.";
 break;
 case 0x60270049U:
 if(!xx_rt_wcscmp(r->name,L"gl_command_words"))text=L"Number of four-byte command-stream words; not the number of commands.";
 break;
 case 0x6027004eU:
 if(!xx_rt_wcscmp(r->name,L"x"))text=L"Compressed coordinate; multiply by frame/model scale and add translation.";
 if(!xx_rt_wcscmp(r->name,L"y"))text=L"Compressed coordinate; multiply by frame/model scale and add translation.";
 if(!xx_rt_wcscmp(r->name,L"z"))text=L"Compressed coordinate; multiply by frame/model scale and add translation.";
 break;
 case 0x6027004fU:
 if(!xx_rt_wcscmp(r->name,L"vertex_count_signed"))text=L"Positive=triangle strip, negative=triangle fan, zero=terminator; absolute value is vertex count.";
 break;
 case 0x60270054U:
 if(!xx_rt_wcscmp(r->name,L"triangles_offset"))text=L"Byte offset relative to this surface header.";
 if(!xx_rt_wcscmp(r->name,L"shaders_offset"))text=L"Byte offset relative to this surface header.";
 if(!xx_rt_wcscmp(r->name,L"texcoords_offset"))text=L"Byte offset relative to this surface header.";
 if(!xx_rt_wcscmp(r->name,L"vertices_offset"))text=L"Byte offset relative to this surface header.";
 if(!xx_rt_wcscmp(r->name,L"end_offset"))text=L"Byte offset relative to this surface header.";
 break;
 case 0x60270058U:
 if(!xx_rt_wcscmp(r->name,L"x"))text=L"Signed fixed point coordinate, scale 1/64.";
 if(!xx_rt_wcscmp(r->name,L"y"))text=L"Signed fixed point coordinate, scale 1/64.";
 if(!xx_rt_wcscmp(r->name,L"z"))text=L"Signed fixed point coordinate, scale 1/64.";
 if(!xx_rt_wcscmp(r->name,L"normal"))text=L"Two encoded eight-bit spherical angles retained as their physical signed short word.";
 break;
 case 0x6027005bU:
 if(!xx_rt_wcscmp(r->name,L"frame_type"))text=L"0=single frame, 1=frame group.";
 break;
 case 0x6027005dU:
 if(!xx_rt_wcscmp(r->name,L"interval"))text=L"Cumulative group frame interval in seconds.";
 break;
 case 0x60270064U:
 if(!xx_rt_wcscmp(r->name,L"sound_table"))text=L"Unused legacy sound-table slot; retained as encoded integer.";
 if(!xx_rt_wcscmp(r->name,L"sound_index"))text=L"Unused legacy sound-index slot.";
 if(!xx_rt_wcscmp(r->name,L"sound_groups"))text=L"Unused legacy sound-group slot.";
 if(!xx_rt_wcscmp(r->name,L"sound_group_index"))text=L"Unused legacy sound-group-index slot.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXGM_LIMIT 20000U
static bool sxgm_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxgm_read(sx_context *c,uint64_t p,void *b,size_t n){return sxgm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxgm_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint16_t sxgm16(const uint8_t *b,bool be){return (uint16_t)sxgm_uint(b,2,be);}
static uint32_t sxgm32(const uint8_t *b,bool be){return (uint32_t)sxgm_uint(b,4,be);}
/* Native readers can authenticate aliases and damaged optional records. Keep
 * earlier bounded physical metadata, and leave conflicting later interpretations
 * opaque instead of discarding the entire useful header view. */
static bool sxgm_free(sx_context *c,uint64_t p,uint64_t n){for(size_t i=0;i<c->count;i++){uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<at+z&&at<p+n)return false;}return true;}
static bool sxgm_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(!sxgm_span(c,p,n))return false;if(!sxgm_free(c,p,n))return true;return c->count>=SXGM_LIMIT||sx_add(c,l,(int64_t)p,(int64_t)n);}
static bool sxgm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n||n>SXGM_LIMIT||!sxgm_span(c,p,n*z))return true;if(!sxgm_free(c,p,n*z))return true;return c->count>=SXGM_LIMIT||sx_table(c,l,(int64_t)p,(int64_t)z,n);}
static bool sxgm_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v){uint8_t b[8];if(n>8||!sxgm_read(c,p,b,n))return false;*v=sxgm_uint(b,n,be);return true;}
static bool sxgm_crt(sx_context *c){uint8_t b[64];if(!sxgm_read(c,0,b,64)||!sxgm_add(c,&sxgm_crt_header,0))return false;uint64_t p=sxgm32(b+16,true);if(p<64)p=64;for(unsigned i=0;i<SXGM_LIMIT&&p<(uint64_t)c->size;i++){if(!sxgm_read(c,p,b,16)||xx_rt_memcmp(b,"CHIP",4))break;uint64_t n=sxgm32(b+4,true);if(n<16||!sxgm_span(c,p,n))break;if(!sxgm_add(c,&sxgm_crt_chip,p))return false;p+=n;}return true;}
static bool sxgm_godot_locate(sx_context *c,uint64_t *pack,uint64_t *end){uint8_t b[64];*pack=0;*end=(uint64_t)c->size;if(!sxgm_read(c,0,b,4))return false;if(!xx_rt_memcmp(b,"GDPC",4))return true;
 if(*end>=100&&sxgm_read(c,*end-12,b,12)&&!xx_rt_memcmp(b+8,"GDPC",4)){uint64_t n=sxgm_uint(b,8,false);if(n>=88&&n<=*end-12&&sxgm_read(c,*end-12-n,b,4)&&!xx_rt_memcmp(b,"GDPC",4)){*pack=*end-12-n;*end-=12;return sxgm_add(c,&sxgm_godot_trailer,*end);}}
 if(!sxgm_read(c,0,b,64)||xx_rt_memcmp(b,"MZ",2))return false;uint64_t pe=sxgm32(b+60,false);if(pe>0x10000000||!sxgm_read(c,pe,b,24)||xx_rt_memcmp(b,"PE\0\0",4))return false;unsigned n=sxgm16(b+6,false);uint64_t p=pe+24+sxgm16(b+20,false);if(!n||n>96||!sxgm_span(c,p,(uint64_t)n*40))return false;
 for(unsigned i=0;i<n;i++){if(!sxgm_read(c,p+i*40,b,40))return false;if(xx_rt_memcmp(b,"pck\0\0\0\0\0",8))continue;uint64_t at=sxgm32(b+20,false),z=sxgm32(b+16,false);if(at>*end)continue;uint64_t limit=z>*end-at?*end:at+z;for(unsigned slack=0;slack<8&&limit-at>=88+slack;slack++){if(sxgm_read(c,at+slack,b,4)&&!xx_rt_memcmp(b,"GDPC",4)){*pack=at+slack;*end=limit;return true;}}}return false;}
static bool sxgm_godot(sx_context *c){uint8_t b[104];uint64_t pack,end;if(!sxgm_godot_locate(c,&pack,&end)||end-pack<20||!sxgm_read(c,pack,b,20))return false;uint32_t v=sxgm32(b+4,false),flags=0;unsigned h=v<=1?84:v==2?96:104;if(v>4||end-pack<h||!sxgm_read(c,pack,b,h))return false;if(v>=2)flags=sxgm32(b+20,false);const sx_layout *l=v<=1?&sxgm_godot_pck_v1:v==2?&sxgm_godot_pck_v2:v==4&&(flags&5)==5?&sxgm_godot_pck_v4_salted:&sxgm_godot_pck_v3;if(!sxgm_add(c,l,pack))return false;
 uint64_t rel=v>=3?sxgm_uint(b+32,8,false):h;if(rel>end-pack||end-pack-rel<4)return true;uint64_t p=pack+rel,n;if(!sxgm_word(c,p,4,false,&n)||!sxgm_add(c,&sxgm_godot_file_count,p))return false;p+=4;if(flags&1){if(end-p>=40&&!sxgm_add(c,&sxgm_godot_encrypted_block,p))return false;return true;}unsigned tail=v>=2?36:32;
 for(uint64_t i=0;i<n&&i<SXGM_LIMIT&&c->count<SXGM_LIMIT;i++){uint64_t z;if(end-p<4||!sxgm_word(c,p,4,false,&z)||!z||z>end-p-4||end-p-4-z<tail)break;if(!sxgm_add(c,&sxgm_godot_path_length,p)||!sxgm_add(c,v>=2?&sxgm_godot_entry_v2:&sxgm_godot_entry_v1,p+4+z))return false;p+=4+z+tail;}return true;}
static bool sxgm_cstr(sx_context *c,uint64_t *p,uint64_t end,bool *empty){uint8_t b;uint64_t start=*p;for(unsigned i=0;i<4096&&*p<end;i++,(*p)++){if(!sxgm_read(c,*p,&b,1))return false;if(!b){*empty=*p==start;(*p)++;return true;}}return false;}
static bool sxgm_vpk(sx_context *c){uint8_t b[28];if(!sxgm_read(c,0,b,12)||!sxgm_add(c,&sxgm_vpk_header,0))return false;unsigned v=sxgm32(b+4,false),h=v==1?12:28;uint64_t tree=sxgm32(b+8,false);if(v!=1&&v!=2)return true;if(!sxgm_read(c,0,b,h)||!sxgm_span(c,h,tree))return true;if(v==2&&!sxgm_add(c,&sxgm_vpk_v2_sections,12))return false;uint64_t p=h,end=h+tree;bool empty=false;unsigned steps=0;
 while(p<end&&steps++<SXGM_LIMIT){if(!sxgm_cstr(c,&p,end,&empty)||empty)break;for(;;){if(++steps>SXGM_LIMIT||!sxgm_cstr(c,&p,end,&empty))goto sections;if(empty)break;for(;;){if(++steps>SXGM_LIMIT||!sxgm_cstr(c,&p,end,&empty))goto sections;if(empty)break;uint8_t e[18];if(end-p<18||!sxgm_read(c,p,e,18)||sxgm16(e+16,false)!=0xffff)goto sections;uint64_t z=sxgm16(e+4,false);if(z>end-p-18)goto sections;if(!sxgm_add(c,&sxgm_vpk_entry,p))return false;p+=18+z;}}}
sections:if(v==2){p=end+sxgm32(b+12,false);uint64_t a=sxgm32(b+16,false),o=sxgm32(b+20,false),sig=sxgm32(b+24,false);if(!sxgm_span(c,p,a)||a%28)return true;if(!sxgm_table(c,&sxgm_vpk_archive_md5,p,a/28))return false;p+=a;if(!sxgm_span(c,p,o))return true;if(o==48&&!sxgm_add(c,&sxgm_vpk_other_md5,p))return false;p+=o;if(sig>=8&&sxgm_span(c,p,sig)){uint64_t z;if(sxgm_word(c,p,4,false,&z)&&z<=sig-8){uint64_t sn;if(sxgm_word(c,p+4+z,4,false,&sn)&&sn==sig-8-z){if(!sxgm_add(c,&sxgm_vpk_public_key_length,p)||!sxgm_add(c,&sxgm_vpk_signature_length,p+4+z))return false;}}}}return true;}
static bool sxgm_rarc(sx_context *c){uint8_t b[64];if(!sxgm_read(c,0,b,64))return false;bool be=!xx_rt_memcmp(b,"RARC",4);if(!be&&xx_rt_memcmp(b,"CRAR",4))return false;if(!sxgm_add(c,be?&sxgm_rarc_header_be:&sxgm_rarc_header_le,0))return false;uint64_t n=sxgm32(b+32,be),p=(uint64_t)sxgm32(b+36,be)+32,k=sxgm32(b+40,be),q=(uint64_t)sxgm32(b+44,be)+32;if(!sxgm_table(c,be?&sxgm_rarc_node_be:&sxgm_rarc_node_le,p,n))return false;if(k>SXGM_LIMIT||!sxgm_span(c,q,k*20))return true;for(uint64_t i=0;i<k&&c->count<SXGM_LIMIT;i++){uint8_t e[20];if(!sxgm_read(c,q+i*20,e,20))break;bool dir=(sxgm32(e+4,be)>>24)&2;const sx_layout *l=dir?(be?&sxgm_rarc_directory_be:&sxgm_rarc_directory_le):(be?&sxgm_rarc_file_be:&sxgm_rarc_file_le);if(!sxgm_add(c,l,q+i*20))return false;}return true;}
static bool sxgm_narc(sx_context *c){uint8_t b[12];if(!sxgm_add(c,&sxgm_narc_header,0)||!sxgm_read(c,16,b,12)||!sxgm_add(c,&sxgm_narc_fat,16))return false;uint64_t fat=sxgm32(b+4,false),n=sxgm32(b+8,false);if(fat<12||!sxgm_span(c,16,fat)||!sxgm_table(c,&sxgm_narc_entry,28,n))return true;uint64_t p=16+fat;if(!sxgm_read(c,p,b,8))return true;uint64_t z=sxgm32(b+4,false);if(z<8||!sxgm_span(c,p,z))return true;if(!sxgm_add(c,&sxgm_narc_block,p))return false;p+=z;if(sxgm_span(c,p,8)&&!sxgm_add(c,&sxgm_narc_block,p))return false;return true;}
static bool sxgm_sarc(sx_context *c){uint8_t b[32];if(!sxgm_read(c,0,b,32))return false;bool be=b[6]==0xfe&&b[7]==0xff;uint64_t n=sxgm16(b+26,be);return sxgm_add(c,be?&sxgm_sarc_header_be:&sxgm_sarc_header_le,0)&&sxgm_add(c,be?&sxgm_sarc_fat_be:&sxgm_sarc_fat_le,20)&&sxgm_table(c,be?&sxgm_sarc_entry_be:&sxgm_sarc_entry_le,32,n)&&(sxgm_span(c,32+n*16,8)?sxgm_add(c,be?&sxgm_sarc_names_be:&sxgm_sarc_names_le,32+n*16):true);}
static bool sxgm_fixed(sx_context *c,const sx_layout *h,const sx_layout *e,unsigned off,unsigned size,unsigned noff,unsigned nwidth,unsigned poff,unsigned pwidth,bool be){uint8_t b[160];if(size>sizeof(b)||!sxgm_read(c,off,b,size)||!sxgm_add(c,h,off))return false;uint64_t n=sxgm_uint(b+noff,nwidth,be),p=pwidth?sxgm_uint(b+poff,pwidth,be):off+size;return sxgm_table(c,e,p,n);}
static bool sxgm_psarc(sx_context *c){uint8_t b[32];if(!sxgm_read(c,0,b,32)||!sxgm_add(c,&sxgm_psarc_header,0))return false;uint64_t toc=sxgm32(b+12,true),stride=sxgm32(b+16,true),n=sxgm32(b+20,true);if(stride!=30||n>SXGM_LIMIT||toc<32+n*30||!sxgm_span(c,0,toc))return true;return sxgm_table(c,&sxgm_psarc_entry,32,n)&&sxgm_table(c,&sxgm_psarc_block_length,32+n*30,(toc-32-n*30)/2);}
static bool sxgm_biff(sx_context *c){uint8_t b[20];if(!sxgm_read(c,0,b,20)||!sxgm_add(c,&sxgm_biff_header,0))return false;return sxgm_table(c,b[7]=='1'?&sxgm_biff_entry_v2:&sxgm_biff_entry_v1,sxgm32(b+16,false),sxgm32(b+8,false));}
static bool sxgm_erf(sx_context *c){uint8_t b[160];if(!sxgm_read(c,0,b,160)||!sxgm_add(c,&sxgm_erf_header,0))return false;uint64_t n=sxgm32(b+16,false),p=sxgm32(b+20,false),z=sxgm32(b+12,false),langs=sxgm32(b+8,false);if(!sxgm_table(c,b[7]=='1'?&sxgm_erf_key32:&sxgm_erf_key16,sxgm32(b+24,false),n)||!sxgm_table(c,&sxgm_erf_resource,sxgm32(b+28,false),n))return false;if(!sxgm_span(c,p,z))return true;uint64_t end=p+z;for(uint64_t i=0;i<langs&&i<SXGM_LIMIT&&end-p>=8;i++){uint64_t text;if(!sxgm_word(c,p+4,4,false,&text)||text>end-p-8)break;if(!sxgm_add(c,&sxgm_erf_localized,p))return false;p+=8+text;}return true;}
static bool sxgm_bsa(sx_context *c){uint8_t b[36];if(!sxgm_read(c,0,b,36)||!sxgm_add(c,&sxgm_bsa_header,0))return false;unsigned v=sxgm32(b+4,false),stride=v==105?24:16;uint64_t table=sxgm32(b+8,false),flags=sxgm32(b+12,false),n=sxgm32(b+16,false);if((v<103||v>105)||n>SXGM_LIMIT||!sxgm_span(c,table,n*stride))return true;if(!sxgm_table(c,v==105?&sxgm_bsa_folder105:&sxgm_bsa_folder,table,n))return false;uint64_t p=table+n*stride;
 for(uint64_t i=0;i<n&&c->count<SXGM_LIMIT;i++){uint64_t files;if(!sxgm_word(c,table+i*stride+8,4,false,&files)||files>SXGM_LIMIT)break;if(flags&1){uint64_t z;if(!sxgm_word(c,p,1,false,&z)||!sxgm_span(c,p+1,z))break;if(!sxgm_add(c,&sxgm_game_name_length8,p))return false;p+=1+z;}if(!sxgm_span(c,p,files*16))break;if(!sxgm_table(c,&sxgm_bsa_file,p,files))return false;
 if(v>=104&&(flags&0x100)){for(uint64_t j=0;j<files&&c->count<SXGM_LIMIT;j++){uint8_t e[16];if(!sxgm_read(c,p+j*16,e,16))break;uint64_t at=sxgm32(e+12,false),sz=sxgm32(e+8,false)&0x3fffffffU,z;if(sz&&sxgm_word(c,at,1,false,&z)&&z<sz&&sxgm_span(c,at,sz)&&!sxgm_add(c,&sxgm_game_name_length8,at))return false;}}p+=files*16;}return true;}
static bool sxgm_ba2(sx_context *c){uint8_t b[36];if(!sxgm_read(c,0,b,24)||!sxgm_add(c,&sxgm_ba2_header,0))return false;unsigned v=sxgm32(b+4,false);uint64_t n=sxgm32(b+12,false),p=sxgm_uint(b+16,8,false);unsigned h=v==2?32:v==3?36:24;if(v==2||v==3){if(!sxgm_span(c,24,h-24))return true;if(!sxgm_add(c,&sxgm_ba2_v2_extension,24))return false;if(v==3&&!sxgm_add(c,&sxgm_ba2_v3_compression,32))return false;}if(xx_rt_memcmp(b+8,"GNRL",4))return true;if(!sxgm_table(c,&sxgm_ba2_general_entry,h,n))return false;for(uint64_t i=0;i<n&&i<SXGM_LIMIT&&c->count<SXGM_LIMIT;i++){uint64_t z;if(!sxgm_word(c,p,2,false,&z)||!sxgm_span(c,p+2,z))break;if(!sxgm_add(c,&sxgm_game_name_length16,p))return false;p+=2+z;}return true;}
static bool sxgm_md2(sx_context *c){uint8_t b[68];if(!sxgm_read(c,0,b,68)||!sxgm_add(c,&sxgm_md2_header,0))return false;uint64_t skins=sxgm32(b+20,false),verts=sxgm32(b+24,false),st=sxgm32(b+28,false),tris=sxgm32(b+32,false),words=sxgm32(b+36,false),frames=sxgm32(b+40,false),fs=sxgm32(b+16,false),p=sxgm32(b+56,false);if(!sxgm_table(c,&sxgm_game_skin_name,sxgm32(b+44,false),skins)||!sxgm_table(c,&sxgm_md2_texcoord,sxgm32(b+48,false),st)||!sxgm_table(c,&sxgm_md2_triangle,sxgm32(b+52,false),tris))return false;
 if(verts<=2048&&frames<=512&&fs==40+verts*4&&sxgm_span(c,p,frames*fs))for(uint64_t i=0;i<frames&&c->count<SXGM_LIMIT;i++){if(!sxgm_add(c,&sxgm_md2_frame,p+i*fs)||!sxgm_table(c,&sxgm_quake_vertex,p+i*fs+40,verts))return false;}
 p=sxgm32(b+60,false);if(words>0x1000000||!sxgm_span(c,p,words*4))return true;uint64_t end=p+words*4;for(unsigned i=0;i<SXGM_LIMIT&&end-p>=4&&c->count<SXGM_LIMIT;i++){uint64_t encoded;if(!sxgm_word(c,p,4,false,&encoded))break;int64_t signedn=(int32_t)(uint32_t)encoded;uint64_t n=(uint64_t)(signedn<0?-signedn:signedn);if(n>SXGM_LIMIT||n>(end-p-4)/12)break;if(!sxgm_add(c,&sxgm_md2_gl_command,p))return false;p+=4;if(!n)break;if(!sxgm_table(c,&sxgm_md2_gl_vertex,p,n))return false;p+=n*12;}return true;}
static bool sxgm_md3(sx_context *c){uint8_t b[108];if(!sxgm_read(c,0,b,108)||!sxgm_add(c,&sxgm_md3_header,0))return false;uint64_t frames=sxgm32(b+76,false),tags=sxgm32(b+80,false),surfaces=sxgm32(b+84,false),p=sxgm32(b+100,false);if(frames>1024||tags>16||surfaces>32)return true;if(!sxgm_table(c,&sxgm_md3_frame,sxgm32(b+92,false),frames)||!sxgm_table(c,&sxgm_md3_tag,sxgm32(b+96,false),frames*tags))return false;
 for(uint64_t i=0;i<surfaces&&c->count<SXGM_LIMIT;i++){if(!sxgm_read(c,p,b,108)||xx_rt_memcmp(b,"IDP3",4))break;uint64_t sf=sxgm32(b+72,false),sh=sxgm32(b+76,false),v=sxgm32(b+80,false),t=sxgm32(b+84,false),z=sxgm32(b+104,false);if(z<108||!sxgm_span(c,p,z))break;if(!sxgm_add(c,&sxgm_md3_surface,p))return false;const sx_layout *ls[]={&sxgm_md3_triangle,&sxgm_md3_shader,&sxgm_md3_texcoord,&sxgm_md3_vertex};uint64_t counts[]={t,sh,v,sf<=1024&&v<=4096?sf*v:UINT64_MAX};unsigned widths[]={12,68,8,8};for(unsigned j=0;j<4;j++){uint64_t at=sxgm32(b+88+j*4,false),n=counts[j];if(n<=SXGM_LIMIT&&at<=z&&n<=(z-at)/widths[j]&&!sxgm_table(c,ls[j],p+at,n))return false;}p+=z;}return true;}
static bool sxgm_sprite(sx_context *c){uint8_t b[36];if(!sxgm_read(c,0,b,36)||!sxgm_add(c,&sxgm_quake_sprite_header,0))return false;uint64_t n=sxgm32(b+24,false),p=36;if(n>SXGM_LIMIT)return true;for(uint64_t i=0;i<n&&c->count<SXGM_LIMIT;i++){uint64_t kind,frames=1;if(!sxgm_word(c,p,4,false,&kind)||kind>1)break;if(!sxgm_add(c,&sxgm_quake_frame_type,p))return false;p+=4;if(kind){if(!sxgm_word(c,p,4,false,&frames)||!frames||frames>SXGM_LIMIT||!sxgm_span(c,p+4,frames*4))break;if(!sxgm_add(c,&sxgm_quake_group_count,p)||!sxgm_table(c,&sxgm_quake_interval,p+4,frames))return false;p+=4+frames*4;}
 for(uint64_t j=0;j<frames;j++){if(!sxgm_read(c,p,b,16))return true;uint64_t w=sxgm32(b+8,false),h=sxgm32(b+12,false);if(!w||!h||w>16384||h>16384||!sxgm_span(c,p+16,w*h))return true;if(!sxgm_add(c,&sxgm_quake_sprite_frame,p))return false;p+=16+w*h;}}return true;}
static bool sxgm_mdl(sx_context *c){uint8_t b[84];if(!sxgm_read(c,0,b,84)||!sxgm_add(c,&sxgm_quake_mdl_header,0))return false;uint64_t skins=sxgm32(b+48,false),w=sxgm32(b+52,false),h=sxgm32(b+56,false),v=sxgm32(b+60,false),t=sxgm32(b+64,false),frames=sxgm32(b+68,false),p=84;if(skins>64||w>16384||h>16384||v>4096||t>65536||frames>1024)return true;for(uint64_t i=0;i<skins;i++){uint64_t kind;if(!sxgm_word(c,p,4,false,&kind)||kind||!sxgm_span(c,p+4,w*h))return true;if(!sxgm_add(c,&sxgm_quake_skin_type,p))return false;p+=4+w*h;}if(!sxgm_span(c,p,v*12+t*16))return true;if(!sxgm_table(c,&sxgm_quake_stvert,p,v)||!sxgm_table(c,&sxgm_quake_triangle,p+v*12,t))return false;p+=v*12+t*16;for(uint64_t i=0;i<frames&&c->count<SXGM_LIMIT;i++){uint64_t kind;if(!sxgm_word(c,p,4,false,&kind)||kind||!sxgm_span(c,p+4,24+v*4))break;if(!sxgm_add(c,&sxgm_quake_frame_type,p)||!sxgm_add(c,&sxgm_quake_mdl_frame,p+4)||!sxgm_table(c,&sxgm_quake_vertex,p+28,v))return false;p+=28+v*4;}return true;}
static bool sxgm_studio(sx_context *c){uint8_t b[244];if(!sxgm_read(c,0,b,244)||!sxgm_add(c,&sxgm_studio_v10_header,0))return false;uint64_t n=sxgm32(b+180,false),p=sxgm32(b+184,false),refs=sxgm32(b+192,false),families=sxgm32(b+196,false),skins=sxgm32(b+200,false);if(!sxgm_table(c,&sxgm_studio_texture,p,n))return false;if(refs<=SXGM_LIMIT&&families<=SXGM_LIMIT)return sxgm_table(c,&sxgm_studio_skinref,skins,refs*families);return true;}
static int sxgm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxgm_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxgm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxgm_order);return !c->failed;}
static bool sx_gamemeta_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_NES_ROM:case XX_FILE_TYPE_LYNX_LNX:case XX_FILE_TYPE_CRT:case XX_FILE_TYPE_COMMODORE_CRT:case XX_FILE_TYPE_GODOT_ENGINE_PCK:case XX_FILE_TYPE_VALVE_VPK:case XX_FILE_TYPE_NINTENDO_RARC:case XX_FILE_TYPE_NINTENDO_NARC:case XX_FILE_TYPE_NINTENDO_SARC:case XX_FILE_TYPE_NINTENDO_PFS0:case XX_FILE_TYPE_NINTENDO_HFS0:case XX_FILE_TYPE_SONY_PSARC:case XX_FILE_TYPE_BIOWARE_BIFF:case XX_FILE_TYPE_BIOWARE_ERF:case XX_FILE_TYPE_BIOWARE_RIM:case XX_FILE_TYPE_BETHESDA_BSA:case XX_FILE_TYPE_BETHESDA_BA2:case XX_FILE_TYPE_IDTECH_BSP:case XX_FILE_TYPE_VALVE_BSP:case XX_FILE_TYPE_IDTECH_MD2:case XX_FILE_TYPE_IDTECH_MD3:case XX_FILE_TYPE_IDTECH_QVM:case XX_FILE_TYPE_QUAKE_SPRITE:case XX_FILE_TYPE_IDTECH_MDL:case XX_FILE_TYPE_VALVE_STUDIO_MDL:return true;default:return false;}}
static bool sx_gamemeta_build(sx_context *c){if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;uint8_t b[16];switch(c->f->file_type){
 case XX_FILE_TYPE_NES_ROM:ok=sxgm_read(c,0,b,16)&&sxgm_add(c,(b[7]&12)==8?&sxgm_nes2_header:&sxgm_ines_header,0);break;
 case XX_FILE_TYPE_LYNX_LNX:ok=sxgm_add(c,&sxgm_lynx_header,0);break;
 case XX_FILE_TYPE_CRT:case XX_FILE_TYPE_COMMODORE_CRT:ok=sxgm_crt(c);break;
 case XX_FILE_TYPE_GODOT_ENGINE_PCK:ok=sxgm_godot(c);break;
 case XX_FILE_TYPE_VALVE_VPK:ok=sxgm_vpk(c);break;
 case XX_FILE_TYPE_NINTENDO_RARC:ok=sxgm_rarc(c);break;
 case XX_FILE_TYPE_NINTENDO_NARC:ok=sxgm_narc(c);break;
 case XX_FILE_TYPE_NINTENDO_SARC:ok=sxgm_sarc(c);break;
 case XX_FILE_TYPE_NINTENDO_PFS0:case XX_FILE_TYPE_NINTENDO_HFS0:ok=sxgm_fixed(c,&sxgm_pfs_header,c->f->file_type==XX_FILE_TYPE_NINTENDO_PFS0?&sxgm_pfs_entry:&sxgm_hfs_entry,0,16,4,4,0,0,false);break;
 case XX_FILE_TYPE_SONY_PSARC:ok=sxgm_psarc(c);break;
 case XX_FILE_TYPE_BIOWARE_BIFF:ok=sxgm_biff(c);break;
 case XX_FILE_TYPE_BIOWARE_ERF:ok=sxgm_erf(c);break;
 case XX_FILE_TYPE_BIOWARE_RIM:ok=sxgm_fixed(c,&sxgm_rim_header,&sxgm_rim_entry,0,120,12,4,16,4,false);break;
 case XX_FILE_TYPE_BETHESDA_BSA:ok=sxgm_bsa(c);break;
 case XX_FILE_TYPE_BETHESDA_BA2:ok=sxgm_ba2(c);break;
 case XX_FILE_TYPE_IDTECH_BSP:ok=sxgm_read(c,0,b,8)&&sxgm_add(c,&sxgm_idtech_bsp_header,0)&&sxgm_table(c,&sxgm_idtech_bsp_lump,8,sxgm32(b+4,false)==38?19:17);break;
 case XX_FILE_TYPE_VALVE_BSP:ok=sxgm_add(c,&sxgm_idtech_bsp_header,0)&&sxgm_table(c,&sxgm_valve_bsp_lump,8,64)&&sxgm_add(c,&sxgm_valve_bsp_revision,1032);break;
 case XX_FILE_TYPE_IDTECH_MD2:ok=sxgm_md2(c);break;
 case XX_FILE_TYPE_IDTECH_MD3:ok=sxgm_md3(c);break;
 case XX_FILE_TYPE_IDTECH_QVM:ok=sxgm_add(c,&sxgm_qvm_header,0);break;
 case XX_FILE_TYPE_QUAKE_SPRITE:ok=sxgm_sprite(c);break;
 case XX_FILE_TYPE_IDTECH_MDL:ok=sxgm_mdl(c);break;
 case XX_FILE_TYPE_VALVE_STUDIO_MDL:ok=sxgm_studio(c);break;
 default:break;}return ok&&sxgm_finish(c);}
