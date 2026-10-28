/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical game cartridge and resource metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxgp_msx_rom_header_fields[]={
 SX_FIELD("signature","bytes",0,2,SX_SIGNATURE),
 SX_FIELD("init_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("runtime_address","uint16",4,2,SX_ADDRESS),
 SX_FIELD("device_address","uint16",6,2,SX_ADDRESS),
 SX_FIELD("text_address","uint16",8,2,SX_ADDRESS),
 SX_FIELD("reserved","bytes",10,6,SX_RESERVED),
};
static const sx_layout sxgp_msx_rom_header={UINT32_C(0x60360001),"msx_rom_header",sxgp_msx_rom_header_fields,SX_COUNT(sxgp_msx_rom_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_msx_binary_header_fields[]={
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("start_address","uint16",1,2,SX_ADDRESS),
 SX_FIELD("end_address","uint16",3,2,SX_ADDRESS),
 SX_FIELD("init_address","uint16",5,2,SX_ADDRESS),
};
static const sx_layout sxgp_msx_binary_header={UINT32_C(0x60360002),"msx_binary_header",sxgp_msx_binary_header_fields,SX_COUNT(sxgp_msx_binary_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_sms_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("reserved","bytes",8,2,SX_RESERVED),
 SX_FIELD("checksum","uint16",10,2,SX_CHECKSUM),
 SX_FIELD("product_code_low","uint16",12,2,SX_ID),
 SX_FIELD("product_high_version","uint8",14,1,SX_FLAGS),
 SX_FIELD("region_size","uint8",15,1,SX_FLAGS),
};
static const sx_layout sxgp_sms_header={UINT32_C(0x60360003),"sms_header",sxgp_sms_header_fields,SX_COUNT(sxgp_sms_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_tic_chunk_fields[]={
 SX_FIELD("bank_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("data_size","uint16",1,2,SX_SIZE),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
};
static const sx_layout sxgp_tic_chunk={UINT32_C(0x60360004),"tic_chunk",sxgp_tic_chunk_fields,SX_COUNT(sxgp_tic_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gb_common_fields[]={
 SX_FIELD("entry_instructions","bytes",0,4,SX_NONE),
 SX_FIELD("logo","bytes",4,48,SX_SIGNATURE),
};
static const sx_layout sxgp_gb_common={UINT32_C(0x60360005),"gb_common",sxgp_gb_common_fields,SX_COUNT(sxgp_gb_common_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gb_title_fields[]={
 SX_FIELD("title","char[16]",0,16,SX_STRING),
};
static const sx_layout sxgp_gb_title={UINT32_C(0x60360006),"gb_title",sxgp_gb_title_fields,SX_COUNT(sxgp_gb_title_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cgb_title_fields[]={
 SX_FIELD("title","char[11]",0,11,SX_STRING),
 SX_FIELD("manufacturer_or_title_tail","char[4]",11,4,SX_STRING),
 SX_FIELD("cgb_flag","uint8",15,1,SX_FLAGS),
};
static const sx_layout sxgp_cgb_title={UINT32_C(0x60360007),"cgb_title",sxgp_cgb_title_fields,SX_COUNT(sxgp_cgb_title_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gb_cartridge_fields[]={
 SX_FIELD("new_licensee","char[2]",0,2,SX_ID),
 SX_FIELD("sgb_flag","uint8",2,1,SX_FLAGS),
 SX_FIELD("cartridge_type","uint8",3,1,SX_ID),
 SX_FIELD("rom_size_code","uint8",4,1,SX_ID),
 SX_FIELD("ram_size_code","uint8",5,1,SX_ID),
 SX_FIELD("destination_code","uint8",6,1,SX_ID),
 SX_FIELD("old_licensee","uint8",7,1,SX_ID),
 SX_FIELD("version","uint8",8,1,SX_ID),
 SX_FIELD("header_checksum","uint8",9,1,SX_CHECKSUM),
 SX_FIELD("global_checksum","uint16be",10,2,SX_CHECKSUM),
};
static const sx_layout sxgp_gb_cartridge={UINT32_C(0x60360008),"gb_cartridge",sxgp_gb_cartridge_fields,SX_COUNT(sxgp_gb_cartridge_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gba_header_fields[]={
 SX_FIELD("entry_instruction","uint32",0,4,SX_FLAGS),
 SX_FIELD("logo","bytes",4,156,SX_SIGNATURE),
 SX_FIELD("title","char[12]",160,12,SX_STRING),
 SX_FIELD("game_code","char[4]",172,4,SX_ID),
 SX_FIELD("maker_code","char[2]",176,2,SX_ID),
 SX_FIELD("fixed","uint8",178,1,SX_SIGNATURE),
 SX_FIELD("unit_code","uint8",179,1,SX_ID),
 SX_FIELD("device_type","uint8",180,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",181,7,SX_RESERVED),
 SX_FIELD("version","uint8",188,1,SX_ID),
 SX_FIELD("complement","uint8",189,1,SX_SIGNATURE),
 SX_FIELD("reserved_tail","uint16",190,2,SX_RESERVED),
};
static const sx_layout sxgp_gba_header={UINT32_C(0x60360009),"gba_header",sxgp_gba_header_fields,SX_COUNT(sxgp_gba_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_megadrive_boot_fields[]={
 SX_FIELD("stack_pointer","uint32",0,4,SX_ADDRESS),
 SX_FIELD("reset_address","uint32",4,4,SX_ADDRESS),
};
static const sx_layout sxgp_megadrive_boot={UINT32_C(0x6036000A),"megadrive_boot",sxgp_megadrive_boot_fields,SX_COUNT(sxgp_megadrive_boot_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_megadrive_vector_fields[]={
 SX_FIELD("handler_address","uint32",0,4,SX_ADDRESS),
};
static const sx_layout sxgp_megadrive_vector={UINT32_C(0x6036000B),"megadrive_vector",sxgp_megadrive_vector_fields,SX_COUNT(sxgp_megadrive_vector_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_megadrive_header_fields[]={
 SX_FIELD("system","char[16]",0,16,SX_ID),
 SX_FIELD("copyright","char[16]",16,16,SX_STRING),
 SX_FIELD("domestic_name","char[48]",32,48,SX_STRING),
 SX_FIELD("overseas_name","char[48]",80,48,SX_STRING),
 SX_FIELD("product_code","char[14]",128,14,SX_ID),
 SX_FIELD("checksum","uint16",142,2,SX_CHECKSUM),
 SX_FIELD("io_support","char[16]",144,16,SX_FLAGS),
 SX_FIELD("rom_start","uint32",160,4,SX_ADDRESS),
 SX_FIELD("rom_end","uint32",164,4,SX_ADDRESS),
 SX_FIELD("ram_start","uint32",168,4,SX_ADDRESS),
 SX_FIELD("ram_end","uint32",172,4,SX_ADDRESS),
 SX_FIELD("sram_marker","bytes",176,2,SX_ID),
 SX_FIELD("sram_type","uint16",178,2,SX_FLAGS),
 SX_FIELD("sram_start","uint32",180,4,SX_ADDRESS),
 SX_FIELD("sram_end","uint32",184,4,SX_ADDRESS),
 SX_FIELD("modem","char[12]",188,12,SX_STRING),
 SX_FIELD("notes","char[40]",200,40,SX_STRING),
 SX_FIELD("regions","char[16]",240,16,SX_FLAGS),
};
static const sx_layout sxgp_megadrive_header={UINT32_C(0x6036000C),"megadrive_header",sxgp_megadrive_header_fields,SX_COUNT(sxgp_megadrive_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_n64_header_fields[]={
 SX_FIELD("pi_boot_config","uint32",0,4,SX_FLAGS),
 SX_FIELD("clock_rate","uint32",4,4,SX_NONE),
 SX_FIELD("entry_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("release","uint32",12,4,SX_ID),
 SX_FIELD("crc1","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("crc2","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("reserved","bytes",24,8,SX_RESERVED),
 SX_FIELD("name","char[20]",32,20,SX_STRING),
 SX_FIELD("reserved2","bytes",52,4,SX_RESERVED),
 SX_FIELD("manufacturer","uint32",56,4,SX_ID),
 SX_FIELD("cartridge_id","char[2]",60,2,SX_ID),
 SX_FIELD("country","uint8",62,1,SX_ID),
 SX_FIELD("version","uint8",63,1,SX_ID),
};
static const sx_layout sxgp_n64_header={UINT32_C(0x6036000D),"n64_header",sxgp_n64_header_fields,SX_COUNT(sxgp_n64_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_a78_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("signature","bytes",1,16,SX_SIGNATURE),
 SX_FIELD("title","char[32]",17,32,SX_STRING),
 SX_FIELD("rom_size","uint32",49,4,SX_SIZE),
 SX_FIELD("cartridge_type","uint16",53,2,SX_FLAGS),
 SX_FIELD("controller1","uint8",55,1,SX_ID),
 SX_FIELD("controller2","uint8",56,1,SX_ID),
 SX_FIELD("television","uint8",57,1,SX_FLAGS),
 SX_FIELD("save_device","uint8",58,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",59,4,SX_RESERVED),
 SX_FIELD("passthrough","uint8",63,1,SX_FLAGS),
 SX_FIELD("reserved_tail","bytes",64,36,SX_RESERVED),
 SX_FIELD("trailer","bytes",100,28,SX_SIGNATURE),
};
static const sx_layout sxgp_a78_header={UINT32_C(0x6036000E),"a78_header",sxgp_a78_header_fields,SX_COUNT(sxgp_a78_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unif_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("reserved","bytes",8,24,SX_RESERVED),
};
static const sx_layout sxgp_unif_header={UINT32_C(0x6036000F),"unif_header",sxgp_unif_header_fields,SX_COUNT(sxgp_unif_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_unif_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxgp_unif_chunk={UINT32_C(0x60360010),"unif_chunk",sxgp_unif_chunk_fields,SX_COUNT(sxgp_unif_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_unif_crc_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxgp_unif_crc={UINT32_C(0x60360011),"unif_crc",sxgp_unif_crc_fields,SX_COUNT(sxgp_unif_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_unif_mirroring_fields[]={
 SX_FIELD("mirroring","uint8",0,1,SX_ID),
};
static const sx_layout sxgp_unif_mirroring={UINT32_C(0x60360012),"unif_mirroring",sxgp_unif_mirroring_fields,SX_COUNT(sxgp_unif_mirroring_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_fds_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("side_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",5,11,SX_RESERVED),
};
static const sx_layout sxgp_fds_header={UINT32_C(0x60360013),"fds_header",sxgp_fds_header_fields,SX_COUNT(sxgp_fds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_fds_file_count_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
 SX_FIELD("file_count","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxgp_fds_file_count={UINT32_C(0x60360014),"fds_file_count",sxgp_fds_file_count_fields,SX_COUNT(sxgp_fds_file_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_fds_file_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
 SX_FIELD("file_number","uint8",1,1,SX_ID),
 SX_FIELD("file_id","uint8",2,1,SX_ID),
 SX_FIELD("name","char[8]",3,8,SX_STRING),
 SX_FIELD("load_address","uint16",11,2,SX_ADDRESS),
 SX_FIELD("file_size","uint16",13,2,SX_SIZE),
 SX_FIELD("file_type","uint8",15,1,SX_ID),
 SX_FIELD("data_block_type","uint8",16,1,SX_ID),
};
static const sx_layout sxgp_fds_file={UINT32_C(0x60360015),"fds_file",sxgp_fds_file_fields,SX_COUNT(sxgp_fds_file_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_pbp_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("param_sfo_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("icon0_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("icon1_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("pic0_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("pic1_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("snd0_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("data_psp_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("data_psar_offset","uint32",36,4,SX_OFFSET),
};
static const sx_layout sxgp_pbp_header={UINT32_C(0x60360016),"pbp_header",sxgp_pbp_header_fields,SX_COUNT(sxgp_pbp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_sfo_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("key_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_sfo_header={UINT32_C(0x60360017),"sfo_header",sxgp_sfo_header_fields,SX_COUNT(sxgp_sfo_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_sfo_entry_fields[]={
 SX_FIELD("key_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("data_format","uint16",2,2,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("maximum_data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxgp_sfo_entry={UINT32_C(0x60360018),"sfo_entry",sxgp_sfo_entry_fields,SX_COUNT(sxgp_sfo_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_header_fields[]={
 SX_FIELD("signature","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("target_platform","uint8",3,1,SX_ID),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("file_size","uint32",6,4,SX_SIZE),
};
static const sx_layout sxgp_xnb_header={UINT32_C(0x60360019),"xnb_header",sxgp_xnb_header_fields,SX_COUNT(sxgp_xnb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_count_fields[]={
 SX_FIELD("count","uleb128_64",0,1,SX_COUNT_PROP),
};
static const sx_layout sxgp_xnb_count={UINT32_C(0x6036001A),"xnb_count",sxgp_xnb_count_fields,SX_COUNT(sxgp_xnb_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_reader_id_fields[]={
 SX_FIELD("reader_id","uleb128_64",0,1,SX_ID),
};
static const sx_layout sxgp_xnb_reader_id={UINT32_C(0x6036001B),"xnb_reader_id",sxgp_xnb_reader_id_fields,SX_COUNT(sxgp_xnb_reader_id_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_length_1_fields[]={
 SX_FIELD("byte_size","uleb128_64",0,1,SX_SIZE),
};
static const sx_layout sxgp_xnb_length_1={UINT32_C(0x6036001C),"xnb_length_1",sxgp_xnb_length_1_fields,SX_COUNT(sxgp_xnb_length_1_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_length_2_fields[]={
 SX_FIELD("byte_size","uleb128_64",0,2,SX_SIZE),
};
static const sx_layout sxgp_xnb_length_2={UINT32_C(0x6036001D),"xnb_length_2",sxgp_xnb_length_2_fields,SX_COUNT(sxgp_xnb_length_2_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_length_3_fields[]={
 SX_FIELD("byte_size","uleb128_64",0,3,SX_SIZE),
};
static const sx_layout sxgp_xnb_length_3={UINT32_C(0x6036001E),"xnb_length_3",sxgp_xnb_length_3_fields,SX_COUNT(sxgp_xnb_length_3_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_length_4_fields[]={
 SX_FIELD("byte_size","uleb128_64",0,4,SX_SIZE),
};
static const sx_layout sxgp_xnb_length_4={UINT32_C(0x6036001F),"xnb_length_4",sxgp_xnb_length_4_fields,SX_COUNT(sxgp_xnb_length_4_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_reader_version_fields[]={
 SX_FIELD("reader_version","int32",0,4,SX_ID),
};
static const sx_layout sxgp_xnb_reader_version={UINT32_C(0x60360020),"xnb_reader_version",sxgp_xnb_reader_version_fields,SX_COUNT(sxgp_xnb_reader_version_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_texture_fields[]={
 SX_FIELD("surface_format","int32",0,4,SX_ID),
 SX_FIELD("width","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("height","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("mip_count","int32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_xnb_texture={UINT32_C(0x60360021),"xnb_texture",sxgp_xnb_texture_fields,SX_COUNT(sxgp_xnb_texture_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_mip_fields[]={
 SX_FIELD("data_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxgp_xnb_mip={UINT32_C(0x60360022),"xnb_mip",sxgp_xnb_mip_fields,SX_COUNT(sxgp_xnb_mip_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_int32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxgp_xnb_int32={UINT32_C(0x60360023),"xnb_int32",sxgp_xnb_int32_fields,SX_COUNT(sxgp_xnb_int32_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_float32_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
static const sx_layout sxgp_xnb_float32={UINT32_C(0x60360024),"xnb_float32",sxgp_xnb_float32_fields,SX_COUNT(sxgp_xnb_float32_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xnb_byte_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxgp_xnb_byte={UINT32_C(0x60360025),"xnb_byte",sxgp_xnb_byte_fields,SX_COUNT(sxgp_xnb_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_header_fields[]={
 SX_FIELD("signature","bytes",0,256,SX_SIGNATURE),
 SX_FIELD("magic","bytes",256,4,SX_SIGNATURE),
 SX_FIELD("content_media_units","uint32",260,4,SX_NONE),
 SX_FIELD("partition_id","uint64",264,8,SX_ID),
 SX_FIELD("maker_code","char[2]",272,2,SX_ID),
 SX_FIELD("version","uint16",274,2,SX_ID),
 SX_FIELD("seed_hash","uint32",276,4,SX_CHECKSUM),
 SX_FIELD("program_id","uint64",280,8,SX_ID),
 SX_FIELD("reserved","bytes",288,16,SX_RESERVED),
 SX_FIELD("logo_sha256","bytes",304,32,SX_CHECKSUM),
 SX_FIELD("product_code","char[16]",336,16,SX_ID),
 SX_FIELD("extended_header_sha256","bytes",352,32,SX_CHECKSUM),
 SX_FIELD("extended_header_size","uint32",384,4,SX_SIZE),
 SX_FIELD("reserved2","bytes",388,4,SX_RESERVED),
 SX_FIELD("flags","bytes",392,8,SX_FLAGS),
 SX_FIELD("plain_offset_media_units","uint32",400,4,SX_NONE),
 SX_FIELD("plain_size_media_units","uint32",404,4,SX_NONE),
 SX_FIELD("logo_offset_media_units","uint32",408,4,SX_NONE),
 SX_FIELD("logo_size_media_units","uint32",412,4,SX_NONE),
 SX_FIELD("exefs_offset_media_units","uint32",416,4,SX_NONE),
 SX_FIELD("exefs_size_media_units","uint32",420,4,SX_NONE),
 SX_FIELD("exefs_hash_media_units","uint32",424,4,SX_NONE),
 SX_FIELD("reserved3","bytes",428,4,SX_RESERVED),
 SX_FIELD("romfs_offset_media_units","uint32",432,4,SX_NONE),
 SX_FIELD("romfs_size_media_units","uint32",436,4,SX_NONE),
 SX_FIELD("romfs_hash_media_units","uint32",440,4,SX_NONE),
 SX_FIELD("reserved4","bytes",444,4,SX_RESERVED),
 SX_FIELD("exefs_sha256","bytes",448,32,SX_CHECKSUM),
 SX_FIELD("romfs_sha256","bytes",480,32,SX_CHECKSUM),
};
static const sx_layout sxgp_ncch_header={UINT32_C(0x60360026),"ncch_header",sxgp_ncch_header_fields,SX_COUNT(sxgp_ncch_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncsd_header_fields[]={
 SX_FIELD("signature","bytes",0,256,SX_SIGNATURE),
 SX_FIELD("magic","bytes",256,4,SX_SIGNATURE),
 SX_FIELD("content_media_units","uint32",260,4,SX_NONE),
 SX_FIELD("media_id","uint64",264,8,SX_ID),
 SX_FIELD("filesystem_types","bytes",272,8,SX_ID),
 SX_FIELD("crypto_types","bytes",280,8,SX_ID),
};
static const sx_layout sxgp_ncsd_header={UINT32_C(0x60360027),"ncsd_header",sxgp_ncsd_header_fields,SX_COUNT(sxgp_ncsd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncsd_partition_fields[]={
 SX_FIELD("offset_media_units","uint32",0,4,SX_NONE),
 SX_FIELD("size_media_units","uint32",4,4,SX_NONE),
};
static const sx_layout sxgp_ncsd_partition={UINT32_C(0x60360028),"ncsd_partition",sxgp_ncsd_partition_fields,SX_COUNT(sxgp_ncsd_partition_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncsd_tail_fields[]={
 SX_FIELD("extended_header_sha256","bytes",0,32,SX_CHECKSUM),
 SX_FIELD("additional_header_size","uint32",32,4,SX_SIZE),
 SX_FIELD("sector_zero_offset_encoded","uint32",36,4,SX_NONE),
 SX_FIELD("partition_flags","bytes",40,8,SX_FLAGS),
 SX_FIELD("partition_id_0","uint64",48,8,SX_ID),
 SX_FIELD("partition_id_1","uint64",56,8,SX_ID),
 SX_FIELD("partition_id_2","uint64",64,8,SX_ID),
 SX_FIELD("partition_id_3","uint64",72,8,SX_ID),
 SX_FIELD("partition_id_4","uint64",80,8,SX_ID),
 SX_FIELD("partition_id_5","uint64",88,8,SX_ID),
 SX_FIELD("partition_id_6","uint64",96,8,SX_ID),
 SX_FIELD("partition_id_7","uint64",104,8,SX_ID),
 SX_FIELD("reserved","bytes",112,47,SX_RESERVED),
 SX_FIELD("extra_save_key_selector","uint8",159,1,SX_ID),
};
static const sx_layout sxgp_ncsd_tail={UINT32_C(0x60360029),"ncsd_tail",sxgp_ncsd_tail_fields,SX_COUNT(sxgp_ncsd_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_sci_prefix_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("reserved","bytes",8,5,SX_RESERVED),
 SX_FIELD("flags","uint8",13,1,SX_FLAGS),
 SX_FIELD("remaster_version","uint16",14,2,SX_ID),
};
static const sx_layout sxgp_ncch_sci_prefix={UINT32_C(0x6036002A),"ncch_sci_prefix",sxgp_ncch_sci_prefix_fields,SX_COUNT(sxgp_ncch_sci_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_code_segment_fields[]={
 SX_FIELD("address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("page_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("code_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxgp_ncch_code_segment={UINT32_C(0x6036002B),"ncch_code_segment",sxgp_ncch_code_segment_fields,SX_COUNT(sxgp_ncch_code_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_stack_fields[]={
 SX_FIELD("stack_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgp_ncch_stack={UINT32_C(0x6036002C),"ncch_stack",sxgp_ncch_stack_fields,SX_COUNT(sxgp_ncch_stack_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_reserved_word_fields[]={
 SX_FIELD("reserved","uint32",0,4,SX_RESERVED),
};
static const sx_layout sxgp_ncch_reserved_word={UINT32_C(0x6036002D),"ncch_reserved_word",sxgp_ncch_reserved_word_fields,SX_COUNT(sxgp_ncch_reserved_word_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_bss_fields[]={
 SX_FIELD("bss_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgp_ncch_bss={UINT32_C(0x6036002E),"ncch_bss",sxgp_ncch_bss_fields,SX_COUNT(sxgp_ncch_bss_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_dependency_fields[]={
 SX_FIELD("program_id","uint64",0,8,SX_ID),
};
static const sx_layout sxgp_ncch_dependency={UINT32_C(0x6036002F),"ncch_dependency",sxgp_ncch_dependency_fields,SX_COUNT(sxgp_ncch_dependency_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_sci_tail_fields[]={
 SX_FIELD("savedata_size","uint64",0,8,SX_SIZE),
 SX_FIELD("jump_id","uint64",8,8,SX_ID),
 SX_FIELD("reserved","bytes",16,48,SX_RESERVED),
};
static const sx_layout sxgp_ncch_sci_tail={UINT32_C(0x60360030),"ncch_sci_tail",sxgp_ncch_sci_tail_fields,SX_COUNT(sxgp_ncch_sci_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_header_fields[]={
 SX_FIELD("title","char[12]",0,12,SX_STRING),
 SX_FIELD("game_code","char[4]",12,4,SX_ID),
 SX_FIELD("maker_code","char[2]",16,2,SX_ID),
 SX_FIELD("unit_code","uint8",18,1,SX_ID),
 SX_FIELD("device_type","uint8",19,1,SX_ID),
 SX_FIELD("capacity_exponent","uint8",20,1,SX_NONE),
 SX_FIELD("reserved","bytes",21,7,SX_RESERVED),
 SX_FIELD("dsi_flags","uint8",28,1,SX_FLAGS),
 SX_FIELD("region","uint8",29,1,SX_ID),
 SX_FIELD("version","uint8",30,1,SX_ID),
 SX_FIELD("autostart","uint8",31,1,SX_FLAGS),
 SX_FIELD("arm9_rom_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("arm9_entry_address","uint32",36,4,SX_ADDRESS),
 SX_FIELD("arm9_load_address","uint32",40,4,SX_ADDRESS),
 SX_FIELD("arm9_size","uint32",44,4,SX_SIZE),
 SX_FIELD("arm7_rom_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("arm7_entry_address","uint32",52,4,SX_ADDRESS),
 SX_FIELD("arm7_load_address","uint32",56,4,SX_ADDRESS),
 SX_FIELD("arm7_size","uint32",60,4,SX_SIZE),
 SX_FIELD("fnt_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("fnt_size","uint32",68,4,SX_SIZE),
 SX_FIELD("fat_offset","uint32",72,4,SX_OFFSET),
 SX_FIELD("fat_size","uint32",76,4,SX_SIZE),
 SX_FIELD("arm9_overlay_offset","uint32",80,4,SX_OFFSET),
 SX_FIELD("arm9_overlay_size","uint32",84,4,SX_SIZE),
 SX_FIELD("arm7_overlay_offset","uint32",88,4,SX_OFFSET),
 SX_FIELD("arm7_overlay_size","uint32",92,4,SX_SIZE),
 SX_FIELD("rom_control_normal","uint32",96,4,SX_FLAGS),
 SX_FIELD("rom_control_secure","uint32",100,4,SX_FLAGS),
 SX_FIELD("banner_offset","uint32",104,4,SX_OFFSET),
 SX_FIELD("secure_area_crc","uint16",108,2,SX_CHECKSUM),
 SX_FIELD("secure_transfer_timeout","uint16",110,2,SX_NONE),
 SX_FIELD("arm9_autoload_list_address","uint32",112,4,SX_ADDRESS),
 SX_FIELD("arm7_autoload_list_address","uint32",116,4,SX_ADDRESS),
 SX_FIELD("secure_area_disable","bytes",120,8,SX_FLAGS),
 SX_FIELD("rom_size","uint32",128,4,SX_SIZE),
 SX_FIELD("header_size","uint32",132,4,SX_SIZE),
 SX_FIELD("unknown_88","uint32",136,4,SX_NONE),
 SX_FIELD("reserved2","bytes",140,8,SX_RESERVED),
 SX_FIELD("nand_rom_end_units","uint16",148,2,SX_NONE),
 SX_FIELD("nand_rw_start_units","uint16",150,2,SX_NONE),
 SX_FIELD("reserved3a","bytes",152,24,SX_RESERVED),
 SX_FIELD("reserved_or_fastboot","bytes",176,16,SX_NONE),
 SX_FIELD("logo","bytes",192,156,SX_SIGNATURE),
 SX_FIELD("logo_crc","uint16",348,2,SX_CHECKSUM),
 SX_FIELD("header_crc","uint16",350,2,SX_CHECKSUM),
 SX_FIELD("debug_rom_offset","uint32",352,4,SX_OFFSET),
 SX_FIELD("debug_size","uint32",356,4,SX_SIZE),
 SX_FIELD("debug_load_address","uint32",360,4,SX_ADDRESS),
 SX_FIELD("reserved3","bytes",364,20,SX_RESERVED),
};
static const sx_layout sxgp_nds_header={UINT32_C(0x60360031),"nds_header",sxgp_nds_header_fields,SX_COUNT(sxgp_nds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_fat_fields[]={
 SX_FIELD("start_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxgp_nds_fat={UINT32_C(0x60360032),"nds_fat",sxgp_nds_fat_fields,SX_COUNT(sxgp_nds_fat_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_overlay_fields[]={
 SX_FIELD("overlay_id","uint32",0,4,SX_ID),
 SX_FIELD("load_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("ram_size","uint32",8,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",12,4,SX_SIZE),
 SX_FIELD("static_init_start","uint32",16,4,SX_ADDRESS),
 SX_FIELD("static_init_end","uint32",20,4,SX_ADDRESS),
 SX_FIELD("file_id","uint32",24,4,SX_ID),
 SX_FIELD("compressed_size_flags","uint32",28,4,SX_FLAGS),
};
static const sx_layout sxgp_nds_overlay={UINT32_C(0x60360033),"nds_overlay",sxgp_nds_overlay_fields,SX_COUNT(sxgp_nds_overlay_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_directory_fields[]={
 SX_FIELD("subtable_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("first_file_id","uint16",4,2,SX_ID),
 SX_FIELD("parent_id_or_directory_count","uint16",6,2,SX_NONE),
};
static const sx_layout sxgp_nds_directory={UINT32_C(0x60360034),"nds_directory",sxgp_nds_directory_fields,SX_COUNT(sxgp_nds_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_name_fields[]={
 SX_FIELD("directory_flag_name_length","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxgp_nds_name={UINT32_C(0x60360035),"nds_name",sxgp_nds_name_fields,SX_COUNT(sxgp_nds_name_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_subdirectory_fields[]={
 SX_FIELD("directory_id","uint16",0,2,SX_ID),
};
static const sx_layout sxgp_nds_subdirectory={UINT32_C(0x60360036),"nds_subdirectory",sxgp_nds_subdirectory_fields,SX_COUNT(sxgp_nds_subdirectory_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_sfo_int32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxgp_sfo_int32={UINT32_C(0x60360037),"sfo_int32",sxgp_sfo_int32_fields,SX_COUNT(sxgp_sfo_int32_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nds_root_directory_fields[]={
 SX_FIELD("subtable_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("first_file_id","uint16",4,2,SX_ID),
 SX_FIELD("directory_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxgp_nds_root_directory={UINT32_C(0x60360038),"nds_root_directory",sxgp_nds_root_directory_fields,SX_COUNT(sxgp_nds_root_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_unity_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("format_version","uint32",8,4,SX_ID),
};
static const sx_layout sxgp_unity_header={UINT32_C(0x60360039),"unity_header",sxgp_unity_header_fields,SX_COUNT(sxgp_unity_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_sizes_fields[]={
 SX_FIELD("file_size","int64",0,8,SX_SIZE),
 SX_FIELD("compressed_info_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_info_size","uint32",12,4,SX_SIZE),
 SX_FIELD("flags","uint32",16,4,SX_FLAGS),
};
static const sx_layout sxgp_unity_sizes={UINT32_C(0x6036003A),"unity_sizes",sxgp_unity_sizes_fields,SX_COUNT(sxgp_unity_sizes_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_info_fields[]={
 SX_FIELD("data_hash","bytes",0,16,SX_CHECKSUM),
 SX_FIELD("block_count","int32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_unity_info={UINT32_C(0x6036003B),"unity_info",sxgp_unity_info_fields,SX_COUNT(sxgp_unity_info_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_block_fields[]={
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
};
static const sx_layout sxgp_unity_block={UINT32_C(0x6036003C),"unity_block",sxgp_unity_block_fields,SX_COUNT(sxgp_unity_block_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_node_count_fields[]={
 SX_FIELD("node_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_unity_node_count={UINT32_C(0x6036003D),"unity_node_count",sxgp_unity_node_count_fields,SX_COUNT(sxgp_unity_node_count_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_unity_node_fields[]={
 SX_FIELD("data_offset","int64",0,8,SX_OFFSET),
 SX_FIELD("data_size","int64",8,8,SX_SIZE),
 SX_FIELD("flags","uint32",16,4,SX_FLAGS),
};
static const sx_layout sxgp_unity_node={UINT32_C(0x6036003E),"unity_node",sxgp_unity_node_fields,SX_COUNT(sxgp_unity_node_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_hpi_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("directory_end_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("encryption_key","uint32",12,4,SX_FLAGS),
 SX_FIELD("root_directory_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxgp_hpi_header={UINT32_C(0x6036003F),"hpi_header",sxgp_hpi_header_fields,SX_COUNT(sxgp_hpi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_hpi_directory_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("entries_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxgp_hpi_directory={UINT32_C(0x60360040),"hpi_directory",sxgp_hpi_directory_fields,SX_COUNT(sxgp_hpi_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_hpi_entry_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("record_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("is_directory","uint8",8,1,SX_FLAGS),
};
static const sx_layout sxgp_hpi_entry={UINT32_C(0x60360041),"hpi_entry",sxgp_hpi_entry_fields,SX_COUNT(sxgp_hpi_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_hpi_file_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compression","uint8",8,1,SX_ID),
};
static const sx_layout sxgp_hpi_file={UINT32_C(0x60360042),"hpi_file",sxgp_hpi_file_fields,SX_COUNT(sxgp_hpi_file_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_rff_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("reserved_tail","bytes",16,16,SX_RESERVED),
};
static const sx_layout sxgp_rff_header={UINT32_C(0x60360043),"rff_header",sxgp_rff_header_fields,SX_COUNT(sxgp_rff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_rff_entry_fields[]={
 SX_FIELD("runtime_state","bytes",0,16,SX_NONE),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",20,4,SX_SIZE),
 SX_FIELD("unknown_word","uint32",24,4,SX_NONE),
 SX_FIELD("unknown_time_word","uint32",28,4,SX_NONE),
 SX_FIELD("flags","uint8",32,1,SX_FLAGS),
 SX_FIELD("extension","char[3]",33,3,SX_STRING),
 SX_FIELD("name","char[8]",36,8,SX_STRING),
 SX_FIELD("resource_id","uint32",44,4,SX_ID),
};
static const sx_layout sxgp_rff_entry={UINT32_C(0x60360044),"rff_entry",sxgp_rff_entry_fields,SX_COUNT(sxgp_rff_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd3_header_le_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[8]",4,8,SX_STRING),
 SX_FIELD("format_bits","uint8",12,1,SX_FLAGS),
 SX_FIELD("big_endian","uint8",13,1,SX_FLAGS),
 SX_FIELD("bit_big_endian","uint8",14,1,SX_FLAGS),
 SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
 SX_FIELD("file_count","int32",16,4,SX_COUNT_PROP),
 SX_FIELD("headers_end","int32",20,4,SX_OFFSET),
 SX_FIELD("unknown18","uint32",24,4,SX_NONE),
 SX_FIELD("reserved_tail","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxgp_bnd3_header_le={UINT32_C(0x60360045),"bnd3_header_le",sxgp_bnd3_header_le_fields,SX_COUNT(sxgp_bnd3_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd4_header_le_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","uint8",4,1,SX_NONE),
 SX_FIELD("unknown05","uint8",5,1,SX_NONE),
 SX_FIELD("reserved","bytes",6,3,SX_RESERVED),
 SX_FIELD("big_endian","uint8",9,1,SX_FLAGS),
 SX_FIELD("reversed_bit_order","uint8",10,1,SX_FLAGS),
 SX_FIELD("reserved2","uint8",11,1,SX_RESERVED),
 SX_FIELD("file_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("header_size","int64",16,8,SX_SIZE),
 SX_FIELD("version","char[8]",24,8,SX_STRING),
 SX_FIELD("entry_size","int64",32,8,SX_SIZE),
 SX_FIELD("headers_end","int64",40,8,SX_OFFSET),
 SX_FIELD("unicode_names","uint8",48,1,SX_FLAGS),
 SX_FIELD("format_bits","uint8",49,1,SX_FLAGS),
 SX_FIELD("extended","uint8",50,1,SX_FLAGS),
 SX_FIELD("reserved3","uint8",51,1,SX_RESERVED),
 SX_FIELD("reserved4","uint32",52,4,SX_RESERVED),
 SX_FIELD("hash_table_offset","int64",56,8,SX_OFFSET),
};
static const sx_layout sxgp_bnd4_header_le={UINT32_C(0x60360046),"bnd4_header_le",sxgp_bnd4_header_le_fields,SX_COUNT(sxgp_bnd4_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd3_entry_le_fields[]={
 SX_FIELD("file_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxgp_bnd3_entry_le={UINT32_C(0x60360047),"bnd3_entry_le",sxgp_bnd3_entry_le_fields,SX_COUNT(sxgp_bnd3_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd4_entry_le_fields[]={
 SX_FIELD("file_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("sentinel","int32",4,4,SX_NONE),
 SX_FIELD("compressed_size","int64",8,8,SX_SIZE),
};
static const sx_layout sxgp_bnd4_entry_le={UINT32_C(0x60360048),"bnd4_entry_le",sxgp_bnd4_entry_le_fields,SX_COUNT(sxgp_bnd4_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_offset32_le_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxgp_bnd_offset32_le={UINT32_C(0x60360049),"bnd_offset32_le",sxgp_bnd_offset32_le_fields,SX_COUNT(sxgp_bnd_offset32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_offset64_le_fields[]={
 SX_FIELD("data_offset","int64",0,8,SX_OFFSET),
};
static const sx_layout sxgp_bnd_offset64_le={UINT32_C(0x6036004A),"bnd_offset64_le",sxgp_bnd_offset64_le_fields,SX_COUNT(sxgp_bnd_offset64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_id_le_fields[]={
 SX_FIELD("file_id","int32",0,4,SX_ID),
};
static const sx_layout sxgp_bnd_id_le={UINT32_C(0x6036004B),"bnd_id_le",sxgp_bnd_id_le_fields,SX_COUNT(sxgp_bnd_id_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd3_name_le_fields[]={
 SX_FIELD("name_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxgp_bnd3_name_le={UINT32_C(0x6036004C),"bnd3_name_le",sxgp_bnd3_name_le_fields,SX_COUNT(sxgp_bnd3_name_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd4_name_le_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxgp_bnd4_name_le={UINT32_C(0x6036004D),"bnd4_name_le",sxgp_bnd4_name_le_fields,SX_COUNT(sxgp_bnd4_name_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_raw32_le_fields[]={
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxgp_bnd_raw32_le={UINT32_C(0x6036004E),"bnd_raw32_le",sxgp_bnd_raw32_le_fields,SX_COUNT(sxgp_bnd_raw32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_raw64_le_fields[]={
 SX_FIELD("uncompressed_size","int64",0,8,SX_SIZE),
};
static const sx_layout sxgp_bnd_raw64_le={UINT32_C(0x6036004F),"bnd_raw64_le",sxgp_bnd_raw64_le_fields,SX_COUNT(sxgp_bnd_raw64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd4_names_extra_le_fields[]={
 SX_FIELD("unknown_value","int32",0,4,SX_NONE),
 SX_FIELD("reserved","int32",4,4,SX_RESERVED),
};
static const sx_layout sxgp_bnd4_names_extra_le={UINT32_C(0x60360050),"bnd4_names_extra_le",sxgp_bnd4_names_extra_le_fields,SX_COUNT(sxgp_bnd4_names_extra_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd3_header_be_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[8]",4,8,SX_STRING),
 SX_FIELD("format_bits","uint8",12,1,SX_FLAGS),
 SX_FIELD("big_endian","uint8",13,1,SX_FLAGS),
 SX_FIELD("bit_big_endian","uint8",14,1,SX_FLAGS),
 SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
 SX_FIELD("file_count","int32",16,4,SX_COUNT_PROP),
 SX_FIELD("headers_end","int32",20,4,SX_OFFSET),
 SX_FIELD("unknown18","uint32",24,4,SX_NONE),
 SX_FIELD("reserved_tail","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxgp_bnd3_header_be={UINT32_C(0x60360051),"bnd3_header_be",sxgp_bnd3_header_be_fields,SX_COUNT(sxgp_bnd3_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd4_header_be_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","uint8",4,1,SX_NONE),
 SX_FIELD("unknown05","uint8",5,1,SX_NONE),
 SX_FIELD("reserved","bytes",6,3,SX_RESERVED),
 SX_FIELD("big_endian","uint8",9,1,SX_FLAGS),
 SX_FIELD("reversed_bit_order","uint8",10,1,SX_FLAGS),
 SX_FIELD("reserved2","uint8",11,1,SX_RESERVED),
 SX_FIELD("file_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("header_size","int64",16,8,SX_SIZE),
 SX_FIELD("version","char[8]",24,8,SX_STRING),
 SX_FIELD("entry_size","int64",32,8,SX_SIZE),
 SX_FIELD("headers_end","int64",40,8,SX_OFFSET),
 SX_FIELD("unicode_names","uint8",48,1,SX_FLAGS),
 SX_FIELD("format_bits","uint8",49,1,SX_FLAGS),
 SX_FIELD("extended","uint8",50,1,SX_FLAGS),
 SX_FIELD("reserved3","uint8",51,1,SX_RESERVED),
 SX_FIELD("reserved4","uint32",52,4,SX_RESERVED),
 SX_FIELD("hash_table_offset","int64",56,8,SX_OFFSET),
};
static const sx_layout sxgp_bnd4_header_be={UINT32_C(0x60360052),"bnd4_header_be",sxgp_bnd4_header_be_fields,SX_COUNT(sxgp_bnd4_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd3_entry_be_fields[]={
 SX_FIELD("file_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxgp_bnd3_entry_be={UINT32_C(0x60360053),"bnd3_entry_be",sxgp_bnd3_entry_be_fields,SX_COUNT(sxgp_bnd3_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd4_entry_be_fields[]={
 SX_FIELD("file_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("sentinel","int32",4,4,SX_NONE),
 SX_FIELD("compressed_size","int64",8,8,SX_SIZE),
};
static const sx_layout sxgp_bnd4_entry_be={UINT32_C(0x60360054),"bnd4_entry_be",sxgp_bnd4_entry_be_fields,SX_COUNT(sxgp_bnd4_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_offset32_be_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxgp_bnd_offset32_be={UINT32_C(0x60360055),"bnd_offset32_be",sxgp_bnd_offset32_be_fields,SX_COUNT(sxgp_bnd_offset32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_offset64_be_fields[]={
 SX_FIELD("data_offset","int64",0,8,SX_OFFSET),
};
static const sx_layout sxgp_bnd_offset64_be={UINT32_C(0x60360056),"bnd_offset64_be",sxgp_bnd_offset64_be_fields,SX_COUNT(sxgp_bnd_offset64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_id_be_fields[]={
 SX_FIELD("file_id","int32",0,4,SX_ID),
};
static const sx_layout sxgp_bnd_id_be={UINT32_C(0x60360057),"bnd_id_be",sxgp_bnd_id_be_fields,SX_COUNT(sxgp_bnd_id_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd3_name_be_fields[]={
 SX_FIELD("name_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxgp_bnd3_name_be={UINT32_C(0x60360058),"bnd3_name_be",sxgp_bnd3_name_be_fields,SX_COUNT(sxgp_bnd3_name_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd4_name_be_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxgp_bnd4_name_be={UINT32_C(0x60360059),"bnd4_name_be",sxgp_bnd4_name_be_fields,SX_COUNT(sxgp_bnd4_name_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_raw32_be_fields[]={
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxgp_bnd_raw32_be={UINT32_C(0x6036005A),"bnd_raw32_be",sxgp_bnd_raw32_be_fields,SX_COUNT(sxgp_bnd_raw32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_raw64_be_fields[]={
 SX_FIELD("uncompressed_size","int64",0,8,SX_SIZE),
};
static const sx_layout sxgp_bnd_raw64_be={UINT32_C(0x6036005B),"bnd_raw64_be",sxgp_bnd_raw64_be_fields,SX_COUNT(sxgp_bnd_raw64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd4_names_extra_be_fields[]={
 SX_FIELD("unknown_value","int32",0,4,SX_NONE),
 SX_FIELD("reserved","int32",4,4,SX_RESERVED),
};
static const sx_layout sxgp_bnd4_names_extra_be={UINT32_C(0x6036005C),"bnd4_names_extra_be",sxgp_bnd4_names_extra_be_fields,SX_COUNT(sxgp_bnd4_names_extra_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_xp3_header_fields[]={
 SX_FIELD("signature","bytes",0,11,SX_SIGNATURE),
 SX_FIELD("index_offset","uint64",11,8,SX_OFFSET),
};
static const sx_layout sxgp_xp3_header={UINT32_C(0x6036005D),"xp3_header",sxgp_xp3_header_fields,SX_COUNT(sxgp_xp3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_index_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("index_size","uint64",1,8,SX_SIZE),
};
static const sx_layout sxgp_xp3_index={UINT32_C(0x6036005E),"xp3_index",sxgp_xp3_index_fields,SX_COUNT(sxgp_xp3_index_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint64",4,8,SX_SIZE),
};
static const sx_layout sxgp_xp3_chunk={UINT32_C(0x6036005F),"xp3_chunk",sxgp_xp3_chunk_fields,SX_COUNT(sxgp_xp3_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_info_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("original_size","uint64",4,8,SX_SIZE),
 SX_FIELD("archived_size","uint64",12,8,SX_SIZE),
 SX_FIELD("name_utf16_units","uint16",20,2,SX_COUNT_PROP),
};
static const sx_layout sxgp_xp3_info={UINT32_C(0x60360060),"xp3_info",sxgp_xp3_info_fields,SX_COUNT(sxgp_xp3_info_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_segment_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("data_offset","uint64",4,8,SX_OFFSET),
 SX_FIELD("original_size","uint64",12,8,SX_SIZE),
 SX_FIELD("archived_size","uint64",20,8,SX_SIZE),
};
static const sx_layout sxgp_xp3_segment={UINT32_C(0x60360061),"xp3_segment",sxgp_xp3_segment_fields,SX_COUNT(sxgp_xp3_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_checksum_fields[]={
 SX_FIELD("adler32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxgp_xp3_checksum={UINT32_C(0x60360062),"xp3_checksum",sxgp_xp3_checksum_fields,SX_COUNT(sxgp_xp3_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lspk_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("file_list_size","uint32",12,4,SX_SIZE),
 SX_FIELD("part_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("flags","uint8",18,1,SX_FLAGS),
 SX_FIELD("priority","uint8",19,1,SX_NONE),
 SX_FIELD("file_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_lspk_header={UINT32_C(0x60360063),"lspk_header",sxgp_lspk_header_fields,SX_COUNT(sxgp_lspk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lspk_file_fields[]={
 SX_FIELD("name","char[256]",0,256,SX_STRING),
 SX_FIELD("data_offset","uint32",256,4,SX_OFFSET),
 SX_FIELD("size_on_disk","uint32",260,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",264,4,SX_SIZE),
 SX_FIELD("archive_part","uint32",268,4,SX_ID),
 SX_FIELD("compression_flags","uint32",272,4,SX_FLAGS),
 SX_FIELD("crc32","uint32",276,4,SX_CHECKSUM),
};
static const sx_layout sxgp_lspk_file={UINT32_C(0x60360064),"lspk_file",sxgp_lspk_file_fields,SX_COUNT(sxgp_lspk_file_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("engine_version","int32",8,4,SX_ID),
 SX_FIELD("strings_uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("strings_stored_size","uint32",16,4,SX_SIZE),
 SX_FIELD("nodes_uncompressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("nodes_stored_size","uint32",24,4,SX_SIZE),
 SX_FIELD("attributes_uncompressed_size","uint32",28,4,SX_SIZE),
 SX_FIELD("attributes_stored_size","uint32",32,4,SX_SIZE),
 SX_FIELD("values_uncompressed_size","uint32",36,4,SX_SIZE),
 SX_FIELD("values_stored_size","uint32",40,4,SX_SIZE),
 SX_FIELD("compression_flags","uint8",44,1,SX_FLAGS),
 SX_FIELD("unknown2","uint8",45,1,SX_NONE),
 SX_FIELD("unknown3","uint16",46,2,SX_NONE),
 SX_FIELD("metadata_format","uint32",48,4,SX_ID),
};
static const sx_layout sxgp_lsf_header={UINT32_C(0x60360065),"lsf_header",sxgp_lsf_header_fields,SX_COUNT(sxgp_lsf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_string_table_fields[]={
 SX_FIELD("bucket_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_lsf_string_table={UINT32_C(0x60360066),"lsf_string_table",sxgp_lsf_string_table_fields,SX_COUNT(sxgp_lsf_string_table_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_bucket_fields[]={
 SX_FIELD("string_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxgp_lsf_bucket={UINT32_C(0x60360067),"lsf_bucket",sxgp_lsf_bucket_fields,SX_COUNT(sxgp_lsf_bucket_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_string_fields[]={
 SX_FIELD("byte_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxgp_lsf_string={UINT32_C(0x60360068),"lsf_string",sxgp_lsf_string_fields,SX_COUNT(sxgp_lsf_string_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_node_fields[]={
 SX_FIELD("name_reference","uint32",0,4,SX_ID),
 SX_FIELD("first_attribute_index","int32",4,4,SX_ID),
 SX_FIELD("parent_index","int32",8,4,SX_ID),
};
static const sx_layout sxgp_lsf_node={UINT32_C(0x60360069),"lsf_node",sxgp_lsf_node_fields,SX_COUNT(sxgp_lsf_node_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_lsf_attribute_fields[]={
 SX_FIELD("name_reference","uint32",0,4,SX_ID),
 SX_FIELD("type_length","uint32",4,4,SX_FLAGS),
 SX_FIELD("node_index","int32",8,4,SX_ID),
};
static const sx_layout sxgp_lsf_attribute={UINT32_C(0x6036006A),"lsf_attribute",sxgp_lsf_attribute_fields,SX_COUNT(sxgp_lsf_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_rpa_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("index_offset","ascii_hex[16]",8,16,SX_OFFSET),
 SX_FIELD("separator","uint8",24,1,SX_NONE),
 SX_FIELD("xor_key","ascii_hex[8]",25,8,SX_FLAGS),
 SX_FIELD("newline","uint8",33,1,SX_NONE),
};
static const sx_layout sxgp_rpa_header={UINT32_C(0x6036006B),"rpa_header",sxgp_rpa_header_fields,SX_COUNT(sxgp_rpa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_rpa_zlib_fields[]={
 SX_FIELD("compression_method_window","uint8",0,1,SX_FLAGS),
 SX_FIELD("compression_flags","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxgp_rpa_zlib={UINT32_C(0x6036006C),"rpa_zlib",sxgp_rpa_zlib_fields,SX_COUNT(sxgp_rpa_zlib_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_rpa_adler_fields[]={
 SX_FIELD("adler32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxgp_rpa_adler={UINT32_C(0x6036006D),"rpa_adler",sxgp_rpa_adler_fields,SX_COUNT(sxgp_rpa_adler_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_tag_fields[]={
 SX_FIELD("tag_id","uint8",0,1,SX_ID),
};
static const sx_layout sxgp_nbt_tag={UINT32_C(0x6036006E),"nbt_tag",sxgp_nbt_tag_fields,SX_COUNT(sxgp_nbt_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_nbt_string_fields[]={
 SX_FIELD("byte_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxgp_nbt_string={UINT32_C(0x6036006F),"nbt_string",sxgp_nbt_string_fields,SX_COUNT(sxgp_nbt_string_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_array_fields[]={
 SX_FIELD("element_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_nbt_array={UINT32_C(0x60360070),"nbt_array",sxgp_nbt_array_fields,SX_COUNT(sxgp_nbt_array_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_list_fields[]={
 SX_FIELD("element_type","uint8",0,1,SX_ID),
 SX_FIELD("element_count","int32",1,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_nbt_list={UINT32_C(0x60360071),"nbt_list",sxgp_nbt_list_fields,SX_COUNT(sxgp_nbt_list_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_byte_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxgp_nbt_byte={UINT32_C(0x60360072),"nbt_byte",sxgp_nbt_byte_fields,SX_COUNT(sxgp_nbt_byte_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_short_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxgp_nbt_short={UINT32_C(0x60360073),"nbt_short",sxgp_nbt_short_fields,SX_COUNT(sxgp_nbt_short_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_int_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxgp_nbt_int={UINT32_C(0x60360074),"nbt_int",sxgp_nbt_int_fields,SX_COUNT(sxgp_nbt_int_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_long_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxgp_nbt_long={UINT32_C(0x60360075),"nbt_long",sxgp_nbt_long_fields,SX_COUNT(sxgp_nbt_long_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_float_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
static const sx_layout sxgp_nbt_float={UINT32_C(0x60360076),"nbt_float",sxgp_nbt_float_fields,SX_COUNT(sxgp_nbt_float_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_nbt_double_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
static const sx_layout sxgp_nbt_double={UINT32_C(0x60360077),"nbt_double",sxgp_nbt_double_fields,SX_COUNT(sxgp_nbt_double_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_szx_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("major","uint8",4,1,SX_ID),
 SX_FIELD("minor","uint8",5,1,SX_ID),
 SX_FIELD("machine","uint8",6,1,SX_ID),
 SX_FIELD("flags","uint8",7,1,SX_FLAGS),
};
static const sx_layout sxgp_szx_header={UINT32_C(0x60360078),"szx_header",sxgp_szx_header_fields,SX_COUNT(sxgp_szx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxgp_szx_chunk={UINT32_C(0x60360079),"szx_chunk",sxgp_szx_chunk_fields,SX_COUNT(sxgp_szx_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_z80_fields[]={
 SX_FIELD("af","uint16",0,2,SX_FLAGS),
 SX_FIELD("bc","uint16",2,2,SX_NONE),
 SX_FIELD("de","uint16",4,2,SX_NONE),
 SX_FIELD("hl","uint16",6,2,SX_NONE),
 SX_FIELD("af_alt","uint16",8,2,SX_FLAGS),
 SX_FIELD("bc_alt","uint16",10,2,SX_NONE),
 SX_FIELD("de_alt","uint16",12,2,SX_NONE),
 SX_FIELD("hl_alt","uint16",14,2,SX_NONE),
 SX_FIELD("ix","uint16",16,2,SX_NONE),
 SX_FIELD("iy","uint16",18,2,SX_NONE),
 SX_FIELD("sp","uint16",20,2,SX_ADDRESS),
 SX_FIELD("pc","uint16",22,2,SX_ADDRESS),
 SX_FIELD("i","uint8",24,1,SX_NONE),
 SX_FIELD("r","uint8",25,1,SX_NONE),
 SX_FIELD("iff1","uint8",26,1,SX_FLAGS),
 SX_FIELD("iff2","uint8",27,1,SX_FLAGS),
 SX_FIELD("interrupt_mode","uint8",28,1,SX_ID),
 SX_FIELD("tstates","uint32",29,4,SX_NONE),
};
static const sx_layout sxgp_szx_z80={UINT32_C(0x6036007A),"szx_z80",sxgp_szx_z80_fields,SX_COUNT(sxgp_szx_z80_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_z80_v0_tail_fields[]={
 SX_FIELD("reserved","bytes",0,4,SX_RESERVED),
};
static const sx_layout sxgp_szx_z80_v0_tail={UINT32_C(0x6036007B),"szx_z80_v0_tail",sxgp_szx_z80_v0_tail_fields,SX_COUNT(sxgp_szx_z80_v0_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_z80_v1_tail_fields[]={
 SX_FIELD("hold_interrupt_cycles","uint8",0,1,SX_NONE),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("hidden_register","uint8",2,1,SX_NONE),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
};
static const sx_layout sxgp_szx_z80_v1_tail={UINT32_C(0x6036007C),"szx_z80_v1_tail",sxgp_szx_z80_v1_tail_fields,SX_COUNT(sxgp_szx_z80_v1_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_z80_v4_tail_fields[]={
 SX_FIELD("hold_interrupt_cycles","uint8",0,1,SX_NONE),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("memptr","uint16",2,2,SX_ADDRESS),
};
static const sx_layout sxgp_szx_z80_v4_tail={UINT32_C(0x6036007D),"szx_z80_v4_tail",sxgp_szx_z80_v4_tail_fields,SX_COUNT(sxgp_szx_z80_v4_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_spectrum_fields[]={
 SX_FIELD("border","uint8",0,1,SX_ID),
 SX_FIELD("port_7ffd","uint8",1,1,SX_FLAGS),
 SX_FIELD("port_1ffd","uint8",2,1,SX_FLAGS),
 SX_FIELD("port_fe","uint8",3,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",4,4,SX_RESERVED),
};
static const sx_layout sxgp_szx_spectrum={UINT32_C(0x6036007E),"szx_spectrum",sxgp_szx_spectrum_fields,SX_COUNT(sxgp_szx_spectrum_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_ram_fields[]={
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("page_id","uint8",2,1,SX_ID),
};
static const sx_layout sxgp_szx_ram={UINT32_C(0x6036007F),"szx_ram",sxgp_szx_ram_fields,SX_COUNT(sxgp_szx_ram_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_creator_fields[]={
 SX_FIELD("creator","char[32]",0,32,SX_STRING),
 SX_FIELD("major","uint16",32,2,SX_ID),
 SX_FIELD("minor","uint16",34,2,SX_ID),
};
static const sx_layout sxgp_szx_creator={UINT32_C(0x60360080),"szx_creator",sxgp_szx_creator_fields,SX_COUNT(sxgp_szx_creator_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_joystick_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("player1","uint8",4,1,SX_ID),
 SX_FIELD("player2","uint8",5,1,SX_ID),
};
static const sx_layout sxgp_szx_joystick={UINT32_C(0x60360081),"szx_joystick",sxgp_szx_joystick_fields,SX_COUNT(sxgp_szx_joystick_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_keyboard_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxgp_szx_keyboard={UINT32_C(0x60360082),"szx_keyboard",sxgp_szx_keyboard_fields,SX_COUNT(sxgp_szx_keyboard_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_keyboard_joystick_fields[]={
 SX_FIELD("joystick","uint8",0,1,SX_ID),
};
static const sx_layout sxgp_szx_keyboard_joystick={UINT32_C(0x60360083),"szx_keyboard_joystick",sxgp_szx_keyboard_joystick_fields,SX_COUNT(sxgp_szx_keyboard_joystick_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_printer_fields[]={
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxgp_szx_printer={UINT32_C(0x60360084),"szx_printer",sxgp_szx_printer_fields,SX_COUNT(sxgp_szx_printer_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_szx_ay_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("selected_register","uint8",1,1,SX_ID),
 SX_FIELD("register_0","uint8",2,1,SX_FLAGS),
 SX_FIELD("register_1","uint8",3,1,SX_FLAGS),
 SX_FIELD("register_2","uint8",4,1,SX_FLAGS),
 SX_FIELD("register_3","uint8",5,1,SX_FLAGS),
 SX_FIELD("register_4","uint8",6,1,SX_FLAGS),
 SX_FIELD("register_5","uint8",7,1,SX_FLAGS),
 SX_FIELD("register_6","uint8",8,1,SX_FLAGS),
 SX_FIELD("register_7","uint8",9,1,SX_FLAGS),
 SX_FIELD("register_8","uint8",10,1,SX_FLAGS),
 SX_FIELD("register_9","uint8",11,1,SX_FLAGS),
 SX_FIELD("register_10","uint8",12,1,SX_FLAGS),
 SX_FIELD("register_11","uint8",13,1,SX_FLAGS),
 SX_FIELD("register_12","uint8",14,1,SX_FLAGS),
 SX_FIELD("register_13","uint8",15,1,SX_FLAGS),
 SX_FIELD("register_14","uint8",16,1,SX_FLAGS),
 SX_FIELD("register_15","uint8",17,1,SX_FLAGS),
};
static const sx_layout sxgp_szx_ay={UINT32_C(0x60360085),"szx_ay",sxgp_szx_ay_fields,SX_COUNT(sxgp_szx_ay_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cpc_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("reserved","bytes",8,8,SX_RESERVED),
 SX_FIELD("version","uint8",16,1,SX_ID),
 SX_FIELD("f","uint8",17,1,SX_FLAGS),
 SX_FIELD("a","uint8",18,1,SX_NONE),
 SX_FIELD("c","uint8",19,1,SX_NONE),
 SX_FIELD("b","uint8",20,1,SX_NONE),
 SX_FIELD("e","uint8",21,1,SX_NONE),
 SX_FIELD("d","uint8",22,1,SX_NONE),
 SX_FIELD("l","uint8",23,1,SX_NONE),
 SX_FIELD("h","uint8",24,1,SX_NONE),
 SX_FIELD("r","uint8",25,1,SX_NONE),
 SX_FIELD("i","uint8",26,1,SX_NONE),
 SX_FIELD("iff1","uint8",27,1,SX_FLAGS),
 SX_FIELD("iff2","uint8",28,1,SX_FLAGS),
 SX_FIELD("ix","uint16",29,2,SX_NONE),
 SX_FIELD("iy","uint16",31,2,SX_NONE),
 SX_FIELD("sp","uint16",33,2,SX_ADDRESS),
 SX_FIELD("pc","uint16",35,2,SX_ADDRESS),
 SX_FIELD("interrupt_mode","uint8",37,1,SX_ID),
 SX_FIELD("f_alt","uint8",38,1,SX_FLAGS),
 SX_FIELD("a_alt","uint8",39,1,SX_NONE),
 SX_FIELD("c_alt","uint8",40,1,SX_NONE),
 SX_FIELD("b_alt","uint8",41,1,SX_NONE),
 SX_FIELD("e_alt","uint8",42,1,SX_NONE),
 SX_FIELD("d_alt","uint8",43,1,SX_NONE),
 SX_FIELD("l_alt","uint8",44,1,SX_NONE),
 SX_FIELD("h_alt","uint8",45,1,SX_NONE),
 SX_FIELD("selected_pen","uint8",46,1,SX_ID),
 SX_FIELD("pen_0","uint8",47,1,SX_ID),
 SX_FIELD("pen_1","uint8",48,1,SX_ID),
 SX_FIELD("pen_2","uint8",49,1,SX_ID),
 SX_FIELD("pen_3","uint8",50,1,SX_ID),
 SX_FIELD("pen_4","uint8",51,1,SX_ID),
 SX_FIELD("pen_5","uint8",52,1,SX_ID),
 SX_FIELD("pen_6","uint8",53,1,SX_ID),
 SX_FIELD("pen_7","uint8",54,1,SX_ID),
 SX_FIELD("pen_8","uint8",55,1,SX_ID),
 SX_FIELD("pen_9","uint8",56,1,SX_ID),
 SX_FIELD("pen_10","uint8",57,1,SX_ID),
 SX_FIELD("pen_11","uint8",58,1,SX_ID),
 SX_FIELD("pen_12","uint8",59,1,SX_ID),
 SX_FIELD("pen_13","uint8",60,1,SX_ID),
 SX_FIELD("pen_14","uint8",61,1,SX_ID),
 SX_FIELD("pen_15","uint8",62,1,SX_ID),
 SX_FIELD("pen_16","uint8",63,1,SX_ID),
 SX_FIELD("gate_array_config","uint8",64,1,SX_FLAGS),
 SX_FIELD("ram_config","uint8",65,1,SX_FLAGS),
 SX_FIELD("selected_crtc","uint8",66,1,SX_ID),
 SX_FIELD("crtc_0","uint8",67,1,SX_FLAGS),
 SX_FIELD("crtc_1","uint8",68,1,SX_FLAGS),
 SX_FIELD("crtc_2","uint8",69,1,SX_FLAGS),
 SX_FIELD("crtc_3","uint8",70,1,SX_FLAGS),
 SX_FIELD("crtc_4","uint8",71,1,SX_FLAGS),
 SX_FIELD("crtc_5","uint8",72,1,SX_FLAGS),
 SX_FIELD("crtc_6","uint8",73,1,SX_FLAGS),
 SX_FIELD("crtc_7","uint8",74,1,SX_FLAGS),
 SX_FIELD("crtc_8","uint8",75,1,SX_FLAGS),
 SX_FIELD("crtc_9","uint8",76,1,SX_FLAGS),
 SX_FIELD("crtc_10","uint8",77,1,SX_FLAGS),
 SX_FIELD("crtc_11","uint8",78,1,SX_FLAGS),
 SX_FIELD("crtc_12","uint8",79,1,SX_FLAGS),
 SX_FIELD("crtc_13","uint8",80,1,SX_FLAGS),
 SX_FIELD("crtc_14","uint8",81,1,SX_FLAGS),
 SX_FIELD("crtc_15","uint8",82,1,SX_FLAGS),
 SX_FIELD("crtc_16","uint8",83,1,SX_FLAGS),
 SX_FIELD("crtc_17","uint8",84,1,SX_FLAGS),
 SX_FIELD("rom_selection","uint8",85,1,SX_ID),
 SX_FIELD("ppi_a","uint8",86,1,SX_FLAGS),
 SX_FIELD("ppi_b","uint8",87,1,SX_FLAGS),
 SX_FIELD("ppi_c","uint8",88,1,SX_FLAGS),
 SX_FIELD("ppi_control","uint8",89,1,SX_FLAGS),
 SX_FIELD("selected_psg","uint8",90,1,SX_ID),
 SX_FIELD("psg_0","uint8",91,1,SX_FLAGS),
 SX_FIELD("psg_1","uint8",92,1,SX_FLAGS),
 SX_FIELD("psg_2","uint8",93,1,SX_FLAGS),
 SX_FIELD("psg_3","uint8",94,1,SX_FLAGS),
 SX_FIELD("psg_4","uint8",95,1,SX_FLAGS),
 SX_FIELD("psg_5","uint8",96,1,SX_FLAGS),
 SX_FIELD("psg_6","uint8",97,1,SX_FLAGS),
 SX_FIELD("psg_7","uint8",98,1,SX_FLAGS),
 SX_FIELD("psg_8","uint8",99,1,SX_FLAGS),
 SX_FIELD("psg_9","uint8",100,1,SX_FLAGS),
 SX_FIELD("psg_10","uint8",101,1,SX_FLAGS),
 SX_FIELD("psg_11","uint8",102,1,SX_FLAGS),
 SX_FIELD("psg_12","uint8",103,1,SX_FLAGS),
 SX_FIELD("psg_13","uint8",104,1,SX_FLAGS),
 SX_FIELD("psg_14","uint8",105,1,SX_FLAGS),
 SX_FIELD("psg_15","uint8",106,1,SX_FLAGS),
 SX_FIELD("memory_dump_kib","uint16",107,2,SX_NONE),
};
static const sx_layout sxgp_cpc_header={UINT32_C(0x60360086),"cpc_header",sxgp_cpc_header_fields,SX_COUNT(sxgp_cpc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cpc_v1_tail_fields[]={
 SX_FIELD("reserved","bytes",0,147,SX_RESERVED),
};
static const sx_layout sxgp_cpc_v1_tail={UINT32_C(0x60360087),"cpc_v1_tail",sxgp_cpc_v1_tail_fields,SX_COUNT(sxgp_cpc_v1_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cpc_model_fields[]={
 SX_FIELD("machine_type","uint8",0,1,SX_ID),
};
static const sx_layout sxgp_cpc_model={UINT32_C(0x60360088),"cpc_model",sxgp_cpc_model_fields,SX_COUNT(sxgp_cpc_model_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_fds_side_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
 SX_FIELD("disk_verification","bytes",1,14,SX_SIGNATURE),
 SX_FIELD("licensee","uint8",15,1,SX_ID),
 SX_FIELD("game_code","char[3]",16,3,SX_ID),
 SX_FIELD("game_type","uint8",19,1,SX_ID),
 SX_FIELD("game_version","uint8",20,1,SX_ID),
 SX_FIELD("side_number","uint8",21,1,SX_ID),
 SX_FIELD("disk_number","uint8",22,1,SX_ID),
 SX_FIELD("fmc_disk_type","uint8",23,1,SX_ID),
 SX_FIELD("unknown18","uint8",24,1,SX_NONE),
 SX_FIELD("boot_file_id","uint8",25,1,SX_ID),
 SX_FIELD("unknown1a","bytes",26,5,SX_NONE),
 SX_FIELD("manufacture_date_bcd","bytes",31,3,SX_NONE),
 SX_FIELD("country","uint8",34,1,SX_ID),
 SX_FIELD("unknown23","uint8",35,1,SX_NONE),
 SX_FIELD("unknown24","uint8",36,1,SX_NONE),
 SX_FIELD("unknown25","bytes",37,2,SX_NONE),
 SX_FIELD("unknown27","bytes",39,5,SX_NONE),
 SX_FIELD("rewrite_date_bcd","bytes",44,3,SX_NONE),
 SX_FIELD("unknown2f","uint8",47,1,SX_NONE),
 SX_FIELD("unknown30","uint8",48,1,SX_NONE),
 SX_FIELD("disk_writer_serial","uint16",49,2,SX_ID),
 SX_FIELD("unknown33","uint8",51,1,SX_NONE),
 SX_FIELD("rewrite_count_bcd","uint8",52,1,SX_NONE),
 SX_FIELD("actual_side","uint8",53,1,SX_ID),
 SX_FIELD("disk_type","uint8",54,1,SX_ID),
 SX_FIELD("disk_version","uint8",55,1,SX_ID),
};
static const sx_layout sxgp_fds_side={UINT32_C(0x60360089),"fds_side",sxgp_fds_side_fields,SX_COUNT(sxgp_fds_side_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cia_header_fields[]={
 SX_FIELD("header_size","uint32",0,4,SX_SIZE),
 SX_FIELD("type","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("certificates_size","uint32",8,4,SX_SIZE),
 SX_FIELD("ticket_size","uint32",12,4,SX_SIZE),
 SX_FIELD("tmd_size","uint32",16,4,SX_SIZE),
 SX_FIELD("metadata_size","uint32",20,4,SX_SIZE),
 SX_FIELD("content_size","uint64",24,8,SX_SIZE),
 SX_FIELD("content_index_bitmap","bytes",32,8192,SX_FLAGS),
};
static const sx_layout sxgp_cia_header={UINT32_C(0x6036008A),"cia_header",sxgp_cia_header_fields,SX_COUNT(sxgp_cia_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cia_signature_fields[]={
 SX_FIELD("signature_type","uint32",0,4,SX_ID),
 SX_FIELD("signature","bytes",4,256,SX_SIGNATURE),
 SX_FIELD("padding","bytes",260,60,SX_RESERVED),
};
static const sx_layout sxgp_cia_signature={UINT32_C(0x6036008B),"cia_signature",sxgp_cia_signature_fields,SX_COUNT(sxgp_cia_signature_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_cia_tmd_fields[]={
 SX_FIELD("issuer","char[64]",0,64,SX_STRING),
 SX_FIELD("version","uint8",64,1,SX_ID),
 SX_FIELD("ca_crl_version","uint8",65,1,SX_ID),
 SX_FIELD("signer_crl_version","uint8",66,1,SX_ID),
 SX_FIELD("reserved","uint8",67,1,SX_RESERVED),
 SX_FIELD("system_version","uint64",68,8,SX_ID),
 SX_FIELD("title_id","uint64",76,8,SX_ID),
 SX_FIELD("title_type","uint32",84,4,SX_FLAGS),
 SX_FIELD("group_id","uint16",88,2,SX_ID),
 SX_FIELD("save_data_size","uint32le",90,4,SX_SIZE),
 SX_FIELD("private_save_data_size","uint32le",94,4,SX_SIZE),
 SX_FIELD("reserved2","bytes",98,4,SX_RESERVED),
 SX_FIELD("twl_flag","uint8",102,1,SX_FLAGS),
 SX_FIELD("reserved3","bytes",103,49,SX_RESERVED),
 SX_FIELD("access_rights","uint32",152,4,SX_FLAGS),
 SX_FIELD("title_version","uint16",156,2,SX_ID),
 SX_FIELD("content_count","uint16",158,2,SX_COUNT_PROP),
 SX_FIELD("boot_content","uint16",160,2,SX_ID),
 SX_FIELD("reserved4","uint16",162,2,SX_RESERVED),
 SX_FIELD("content_info_sha256","bytes",164,32,SX_CHECKSUM),
};
static const sx_layout sxgp_cia_tmd={UINT32_C(0x6036008C),"cia_tmd",sxgp_cia_tmd_fields,SX_COUNT(sxgp_cia_tmd_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_cia_content_info_fields[]={
 SX_FIELD("index_offset","uint16",0,2,SX_ID),
 SX_FIELD("content_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("sha256","bytes",4,32,SX_CHECKSUM),
};
static const sx_layout sxgp_cia_content_info={UINT32_C(0x6036008D),"cia_content_info",sxgp_cia_content_info_fields,SX_COUNT(sxgp_cia_content_info_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_cia_content_fields[]={
 SX_FIELD("content_id","uint32",0,4,SX_ID),
 SX_FIELD("content_index","uint16",4,2,SX_ID),
 SX_FIELD("type","uint16",6,2,SX_FLAGS),
 SX_FIELD("content_size","uint64",8,8,SX_SIZE),
 SX_FIELD("sha256","bytes",16,32,SX_CHECKSUM),
};
static const sx_layout sxgp_cia_content={UINT32_C(0x6036008E),"cia_content",sxgp_cia_content_fields,SX_COUNT(sxgp_cia_content_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_cia_metadata_fields[]={
 SX_FIELD("dependencies","bytes",0,384,SX_ID),
 SX_FIELD("reserved","bytes",384,384,SX_RESERVED),
 SX_FIELD("core_version","uint32",768,4,SX_ID),
 SX_FIELD("reserved2","bytes",772,252,SX_RESERVED),
};
static const sx_layout sxgp_cia_metadata={UINT32_C(0x6036008F),"cia_metadata",sxgp_cia_metadata_fields,SX_COUNT(sxgp_cia_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gcm_id_fields[]={
 SX_FIELD("game_code","char[4]",0,4,SX_ID),
 SX_FIELD("maker_code","char[2]",4,2,SX_ID),
 SX_FIELD("disc_number","uint8",6,1,SX_ID),
 SX_FIELD("version","uint8",7,1,SX_ID),
 SX_FIELD("audio_streaming","uint8",8,1,SX_FLAGS),
 SX_FIELD("stream_buffer_size","uint8",9,1,SX_NONE),
 SX_FIELD("reserved","bytes",10,14,SX_RESERVED),
 SX_FIELD("wii_magic","uint32",24,4,SX_SIGNATURE),
 SX_FIELD("gamecube_magic","uint32",28,4,SX_SIGNATURE),
};
static const sx_layout sxgp_gcm_id={UINT32_C(0x60360090),"gcm_id",sxgp_gcm_id_fields,SX_COUNT(sxgp_gcm_id_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_title_fields[]={
 SX_FIELD("title","char[992]",0,992,SX_STRING),
};
static const sx_layout sxgp_gcm_title={UINT32_C(0x60360091),"gcm_title",sxgp_gcm_title_fields,SX_COUNT(sxgp_gcm_title_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gcm_debug_fields[]={
 SX_FIELD("debug_monitor_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("debug_monitor_load_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("reserved","bytes",8,24,SX_RESERVED),
};
static const sx_layout sxgp_gcm_debug={UINT32_C(0x60360092),"gcm_debug",sxgp_gcm_debug_fields,SX_COUNT(sxgp_gcm_debug_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_boot_fields[]={
 SX_FIELD("dol_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("fst_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("fst_size","uint32",8,4,SX_SIZE),
 SX_FIELD("fst_maximum_size","uint32",12,4,SX_SIZE),
 SX_FIELD("fst_load_address","uint32",16,4,SX_ADDRESS),
 SX_FIELD("user_data_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("user_data_size","uint32",24,4,SX_SIZE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxgp_gcm_boot={UINT32_C(0x60360093),"gcm_boot",sxgp_gcm_boot_fields,SX_COUNT(sxgp_gcm_boot_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_apploader_fields[]={
 SX_FIELD("date","char[16]",0,16,SX_STRING),
 SX_FIELD("entry_address","uint32",16,4,SX_ADDRESS),
 SX_FIELD("code_size","uint32",20,4,SX_SIZE),
 SX_FIELD("trailer_size","uint32",24,4,SX_SIZE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxgp_gcm_apploader={UINT32_C(0x60360094),"gcm_apploader",sxgp_gcm_apploader_fields,SX_COUNT(sxgp_gcm_apploader_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_fst_file_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",1,3,SX_OFFSET),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxgp_gcm_fst_file={UINT32_C(0x60360095),"gcm_fst_file",sxgp_gcm_fst_file_fields,SX_COUNT(sxgp_gcm_fst_file_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_fst_directory_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",1,3,SX_OFFSET),
 SX_FIELD("parent_index","uint32",4,4,SX_ID),
 SX_FIELD("next_entry_index","uint32",8,4,SX_ID),
};
static const sx_layout sxgp_gcm_fst_directory={UINT32_C(0x60360096),"gcm_fst_directory",sxgp_gcm_fst_directory_fields,SX_COUNT(sxgp_gcm_fst_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_fst_root_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",1,3,SX_OFFSET),
 SX_FIELD("parent_index","uint32",4,4,SX_ID),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxgp_gcm_fst_root={UINT32_C(0x60360097),"gcm_fst_root",sxgp_gcm_fst_root_fields,SX_COUNT(sxgp_gcm_fst_root_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_dol_offset_fields[]={
 SX_FIELD("section_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxgp_gcm_dol_offset={UINT32_C(0x60360098),"gcm_dol_offset",sxgp_gcm_dol_offset_fields,SX_COUNT(sxgp_gcm_dol_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_dol_address_fields[]={
 SX_FIELD("load_address","uint32",0,4,SX_ADDRESS),
};
static const sx_layout sxgp_gcm_dol_address={UINT32_C(0x60360099),"gcm_dol_address",sxgp_gcm_dol_address_fields,SX_COUNT(sxgp_gcm_dol_address_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_dol_size_fields[]={
 SX_FIELD("section_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgp_gcm_dol_size={UINT32_C(0x6036009A),"gcm_dol_size",sxgp_gcm_dol_size_fields,SX_COUNT(sxgp_gcm_dol_size_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_gcm_dol_tail_fields[]={
 SX_FIELD("bss_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("bss_size","uint32",4,4,SX_SIZE),
 SX_FIELD("entry_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("reserved","bytes",12,28,SX_RESERVED),
};
static const sx_layout sxgp_gcm_dol_tail={UINT32_C(0x6036009B),"gcm_dol_tail",sxgp_gcm_dol_tail_fields,SX_COUNT(sxgp_gcm_dol_tail_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_wbfs_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("host_sector_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("host_sector_shift","uint8",8,1,SX_NONE),
 SX_FIELD("wbfs_sector_shift","uint8",9,1,SX_NONE),
 SX_FIELD("reserved","bytes",10,2,SX_RESERVED),
 SX_FIELD("disc_table","bytes",12,500,SX_FLAGS),
};
static const sx_layout sxgp_wbfs_header={UINT32_C(0x6036009C),"wbfs_header",sxgp_wbfs_header_fields,SX_COUNT(sxgp_wbfs_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_wbfs_disc_title_fields[]={
 SX_FIELD("title","char[64]",0,64,SX_STRING),
};
static const sx_layout sxgp_wbfs_disc_title={UINT32_C(0x6036009D),"wbfs_disc_title",sxgp_wbfs_disc_title_fields,SX_COUNT(sxgp_wbfs_disc_title_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_wbfs_block_fields[]={
 SX_FIELD("physical_cluster","uint16",0,2,SX_NONE),
};
static const sx_layout sxgp_wbfs_block={UINT32_C(0x6036009E),"wbfs_block",sxgp_wbfs_block_fields,SX_COUNT(sxgp_wbfs_block_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_wbfs_md5_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("digest","bytes",4,16,SX_CHECKSUM),
};
static const sx_layout sxgp_wbfs_md5={UINT32_C(0x6036009F),"wbfs_md5",sxgp_wbfs_md5_fields,SX_COUNT(sxgp_wbfs_md5_fields),SX_LE};
static const sx_layout *const sx_gameplatforms_layouts[]={
 &sxgp_msx_rom_header,
 &sxgp_msx_binary_header,
 &sxgp_sms_header,
 &sxgp_tic_chunk,
 &sxgp_gb_common,
 &sxgp_gb_title,
 &sxgp_cgb_title,
 &sxgp_gb_cartridge,
 &sxgp_gba_header,
 &sxgp_megadrive_boot,
 &sxgp_megadrive_vector,
 &sxgp_megadrive_header,
 &sxgp_n64_header,
 &sxgp_a78_header,
 &sxgp_unif_header,
 &sxgp_unif_chunk,
 &sxgp_unif_crc,
 &sxgp_unif_mirroring,
 &sxgp_fds_header,
 &sxgp_fds_file_count,
 &sxgp_fds_file,
 &sxgp_pbp_header,
 &sxgp_sfo_header,
 &sxgp_sfo_entry,
 &sxgp_xnb_header,
 &sxgp_xnb_count,
 &sxgp_xnb_reader_id,
 &sxgp_xnb_length_1,
 &sxgp_xnb_length_2,
 &sxgp_xnb_length_3,
 &sxgp_xnb_length_4,
 &sxgp_xnb_reader_version,
 &sxgp_xnb_texture,
 &sxgp_xnb_mip,
 &sxgp_xnb_int32,
 &sxgp_xnb_float32,
 &sxgp_xnb_byte,
 &sxgp_ncch_header,
 &sxgp_ncsd_header,
 &sxgp_ncsd_partition,
 &sxgp_ncsd_tail,
 &sxgp_ncch_sci_prefix,
 &sxgp_ncch_code_segment,
 &sxgp_ncch_stack,
 &sxgp_ncch_reserved_word,
 &sxgp_ncch_bss,
 &sxgp_ncch_dependency,
 &sxgp_ncch_sci_tail,
 &sxgp_nds_header,
 &sxgp_nds_fat,
 &sxgp_nds_overlay,
 &sxgp_nds_directory,
 &sxgp_nds_name,
 &sxgp_nds_subdirectory,
 &sxgp_sfo_int32,
 &sxgp_nds_root_directory,
 &sxgp_unity_header,
 &sxgp_unity_sizes,
 &sxgp_unity_info,
 &sxgp_unity_block,
 &sxgp_unity_node_count,
 &sxgp_unity_node,
 &sxgp_hpi_header,
 &sxgp_hpi_directory,
 &sxgp_hpi_entry,
 &sxgp_hpi_file,
 &sxgp_rff_header,
 &sxgp_rff_entry,
 &sxgp_bnd3_header_le,
 &sxgp_bnd4_header_le,
 &sxgp_bnd3_entry_le,
 &sxgp_bnd4_entry_le,
 &sxgp_bnd_offset32_le,
 &sxgp_bnd_offset64_le,
 &sxgp_bnd_id_le,
 &sxgp_bnd3_name_le,
 &sxgp_bnd4_name_le,
 &sxgp_bnd_raw32_le,
 &sxgp_bnd_raw64_le,
 &sxgp_bnd4_names_extra_le,
 &sxgp_bnd3_header_be,
 &sxgp_bnd4_header_be,
 &sxgp_bnd3_entry_be,
 &sxgp_bnd4_entry_be,
 &sxgp_bnd_offset32_be,
 &sxgp_bnd_offset64_be,
 &sxgp_bnd_id_be,
 &sxgp_bnd3_name_be,
 &sxgp_bnd4_name_be,
 &sxgp_bnd_raw32_be,
 &sxgp_bnd_raw64_be,
 &sxgp_bnd4_names_extra_be,
 &sxgp_xp3_header,
 &sxgp_xp3_index,
 &sxgp_xp3_chunk,
 &sxgp_xp3_info,
 &sxgp_xp3_segment,
 &sxgp_xp3_checksum,
 &sxgp_lspk_header,
 &sxgp_lspk_file,
 &sxgp_lsf_header,
 &sxgp_lsf_string_table,
 &sxgp_lsf_bucket,
 &sxgp_lsf_string,
 &sxgp_lsf_node,
 &sxgp_lsf_attribute,
 &sxgp_rpa_header,
 &sxgp_rpa_zlib,
 &sxgp_rpa_adler,
 &sxgp_nbt_tag,
 &sxgp_nbt_string,
 &sxgp_nbt_array,
 &sxgp_nbt_list,
 &sxgp_nbt_byte,
 &sxgp_nbt_short,
 &sxgp_nbt_int,
 &sxgp_nbt_long,
 &sxgp_nbt_float,
 &sxgp_nbt_double,
 &sxgp_szx_header,
 &sxgp_szx_chunk,
 &sxgp_szx_z80,
 &sxgp_szx_z80_v0_tail,
 &sxgp_szx_z80_v1_tail,
 &sxgp_szx_z80_v4_tail,
 &sxgp_szx_spectrum,
 &sxgp_szx_ram,
 &sxgp_szx_creator,
 &sxgp_szx_joystick,
 &sxgp_szx_keyboard,
 &sxgp_szx_keyboard_joystick,
 &sxgp_szx_printer,
 &sxgp_szx_ay,
 &sxgp_cpc_header,
 &sxgp_cpc_v1_tail,
 &sxgp_cpc_model,
 &sxgp_fds_side,
 &sxgp_cia_header,
 &sxgp_cia_signature,
 &sxgp_cia_tmd,
 &sxgp_cia_content_info,
 &sxgp_cia_content,
 &sxgp_cia_metadata,
 &sxgp_gcm_id,
 &sxgp_gcm_title,
 &sxgp_gcm_debug,
 &sxgp_gcm_boot,
 &sxgp_gcm_apploader,
 &sxgp_gcm_fst_file,
 &sxgp_gcm_fst_directory,
 &sxgp_gcm_fst_root,
 &sxgp_gcm_dol_offset,
 &sxgp_gcm_dol_address,
 &sxgp_gcm_dol_size,
 &sxgp_gcm_dol_tail,
 &sxgp_wbfs_header,
 &sxgp_wbfs_disc_title,
 &sxgp_wbfs_block,
 &sxgp_wbfs_md5,
};
/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxgp_view {sx_context*c;unsigned work;}sxgp_view;
static bool sxgp_span(sxgp_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxgp_read(sxgp_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return sxgp_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxgp_word(sxgp_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxgp_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxgp_row(sxgp_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxgp_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_table(sxgp_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxgp_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxgp_row(v,l,at,end))return false;return true;}
static int sxgp_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxgp_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxgp_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxgp_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxgp_cstring(sxgp_view*v,uint64_t*p,uint64_t end,uint64_t max)
{uint64_t start=*p,c;while(*p<end&&*p-start<max){if(++v->work>4000000||!sxgp_word(v,*p,1,false,&c,end))return false;(*p)++;if(!c)return true;}return false;}
static bool sxgp_msx(sxgp_view*v){uint64_t magic,end=(uint64_t)v->c->size;return sxgp_word(v,0,1,false,&magic,end)&&sxgp_row(v,magic==254?&sxgp_msx_binary_header:&sxgp_msx_rom_header,0,end);}
static bool sxgp_sms(sxgp_view*v){const uint64_t offsets[]={0x1ff0,0x3ff0,0x7ff0,0x8ff0};uint64_t end=(uint64_t)v->c->size;uint8_t tag[8];for(unsigned i=0;i<4;i++)if(sxgp_span(v,offsets[i],16,end)&&sxgp_read(v,offsets[i],tag,8,end)&&!xx_rt_memcmp(tag,"TMR SEGA",8))return SG_ROW(sms_header,offsets[i],end);return false;}
static bool sxgp_tic(sxgp_view*v){uint64_t p=0,end=(uint64_t)v->c->size,z;while(p<end){if(!SG_ROW(tic_chunk,p,end)||!sxgp_word(v,p+1,2,false,&z,end)||!sxgp_span(v,p+4,z,end))return false;p+=4+z;}return p==end;}
static bool sxgp_gb(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,flag;if(!SG_ROW(gb_common,0x100,end)||!sxgp_word(v,0x143,1,false,&flag,end))return false;return sxgp_row(v,flag&128?&sxgp_cgb_title:&sxgp_gb_title,0x134,end)&&SG_ROW(gb_cartridge,0x144,end);}
static bool sxgp_gba(sxgp_view*v){return SG_ROW(gba_header,0,(uint64_t)v->c->size);}
static bool sxgp_megadrive(sxgp_view*v){uint64_t end=(uint64_t)v->c->size;return SG_ROW(megadrive_boot,0,end)&&sxgp_table(v,&sxgp_megadrive_vector,8,62,end)&&SG_ROW(megadrive_header,256,end);}
static bool sxgp_n64(sxgp_view*v){return SG_ROW(n64_header,0,(uint64_t)v->c->size);}
static bool sxgp_a78(sxgp_view*v){return SG_ROW(a78_header,0,(uint64_t)v->c->size);}
static bool sxgp_unif(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,p=32,z;uint8_t tag[4];if(!SG_ROW(unif_header,0,end))return false;while(p<end){if(!SG_ROW(unif_chunk,p,end)||!sxgp_read(v,p,tag,4,end)||!sxgp_word(v,p+4,4,false,&z,end)||!sxgp_span(v,p+8,z,end))return false;p+=8;if((!xx_rt_memcmp(tag,"PCK",3)||!xx_rt_memcmp(tag,"CCK",3))&&z==4){if(!SG_ROW(unif_crc,p,p+z))return false;}else if(!xx_rt_memcmp(tag,"MIRR",4)&&z==1&&!SG_ROW(unif_mirroring,p,p+z))return false;p+=z;}return p==end;}
static bool sxgp_ncch_at(sxgp_view*v,uint64_t at,uint64_t end,bool extended)
{uint64_t ex;if(!SG_ROW(ncch_header,at,end)||!sxgp_word(v,at+0x180,4,false,&ex,end))return false;if(extended&&ex){uint64_t p=at+512;if(!sxgp_span(v,p,0x800,end)||!SG_ROW(ncch_sci_prefix,p,end)||!SG_ROW(ncch_code_segment,p+16,end)||!SG_ROW(ncch_stack,p+28,end)||!SG_ROW(ncch_code_segment,p+32,end)||!SG_ROW(ncch_reserved_word,p+44,end)||!SG_ROW(ncch_code_segment,p+48,end)||!SG_ROW(ncch_bss,p+60,end)||!sxgp_table(v,&sxgp_ncch_dependency,p+64,48,end)||!SG_ROW(ncch_sci_tail,p+448,end))return false;}return true;}
static bool sxgp_ncch(sxgp_view*v){return sxgp_ncch_at(v,0,(uint64_t)v->c->size,true);}
static bool sxgp_ncsd(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size;if(!SG_ROW(ncsd_header,0,end)||!sxgp_table(v,&sxgp_ncsd_partition,0x120,8,end)||!SG_ROW(ncsd_tail,0x160,end))return false;for(unsigned i=0;i<8;i++){uint64_t at,z;if(!sxgp_word(v,0x120+i*8,4,false,&at,end)||!sxgp_word(v,0x124+i*8,4,false,&z,end))return false;if(z){at*=512;z*=512;if(!sxgp_span(v,at,z,end)||!sxgp_ncch_at(v,at,at+z,false))return false;}}return true;}
static bool sxgp_nds(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,fnt,fns,fat,fas,dirs;uint8_t h[384];if(!SG_ROW(nds_header,0,end)||!sxgp_read(v,0,h,sizeof(h),end))return false;
 fnt=xx_data_get_u32(h+64,4,0,false);fns=xx_data_get_u32(h+68,4,0,false);fat=xx_data_get_u32(h+72,4,0,false);fas=xx_data_get_u32(h+76,4,0,false);
 if(fas%8||!sxgp_span(v,fnt,fns,end)||!sxgp_table(v,&sxgp_nds_fat,fat,fas/8,end))return false;
 if(fns){uint64_t stop=fnt+fns;if(!sxgp_word(v,fnt+6,2,false,&dirs,stop)||!dirs||dirs>4096||!SG_ROW(nds_root_directory,fnt,stop)||!sxgp_table(v,&sxgp_nds_directory,fnt+8,dirs-1,stop))return false;
  for(uint64_t i=0;i<dirs;i++){uint64_t p,q;if(!sxgp_word(v,fnt+i*8,4,false,&p,stop)||p>=fns)return false;p+=fnt;
   for(q=0;q<4096;q++){uint64_t ch;if(!SG_ROW(nds_name,p,stop)||!sxgp_word(v,p++,1,false,&ch,stop))return false;if(!ch)break;if(!(ch&127)||!sxgp_span(v,p,(ch&127)+(ch&128?2:0),stop))return false;p+=ch&127;if(ch&128){if(!SG_ROW(nds_subdirectory,p,stop))return false;p+=2;}}
   if(q==4096)return false;
  }
 }
 for(unsigned i=0;i<2;i++){uint64_t at=xx_data_get_u32(h+80+i*8,4,0,false),z=xx_data_get_u32(h+84+i*8,4,0,false);if(z%32||!sxgp_table(v,&sxgp_nds_overlay,at,z/32,end))return false;}
 return true;}
static bool sxgp_pbp(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,sf,stop,count,data;if(!SG_ROW(pbp_header,0,end)||!sxgp_word(v,8,4,false,&sf,end)||!sxgp_word(v,12,4,false,&stop,end)||!sxgp_span(v,sf,20,stop)||!SG_ROW(sfo_header,sf,stop)||!sxgp_word(v,sf+16,4,false,&count,stop)||count>256||!sxgp_table(v,&sxgp_sfo_entry,sf+20,count,stop)||!sxgp_word(v,sf+12,4,false,&data,stop))return false;
 if(data>stop-sf)return false;data+=sf;
 for(uint64_t i=0;i<count;i++){uint64_t type,off,p=sf+20+i*16;if(!sxgp_word(v,p+2,2,false,&type,stop)||!sxgp_word(v,p+12,4,false,&off,stop))return false;if(type==0x404){if(off>stop-data||!SG_ROW(sfo_int32,data+off,stop))return false;}}
 return true;}
static bool sxgp_xnb_var(sxgp_view*v,uint64_t*p,uint64_t end,unsigned kind,uint64_t*out)
{uint64_t a=*p,x=0,ch;unsigned n=0;do{if(n==5||!sxgp_word(v,*p,1,false,&ch,end))return false;(*p)++;if(n==4&&(ch&248))return false;x|=(ch&127)<<(7*n++);}while(ch&128);if(n>1&&!ch)return false;
 const sx_layout*ls[]={&sxgp_xnb_length_1,&sxgp_xnb_length_2,&sxgp_xnb_length_3,&sxgp_xnb_length_4};if((kind&&n!=1)||(!kind&&n>4)||!sxgp_row(v,kind==1?&sxgp_xnb_count:kind==2?&sxgp_xnb_reader_id:ls[n-1],a,end))return false;*out=x;return true;}
static bool sxgp_xnb(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p=10,z,mips;char name[1025];if(!SG_ROW(xnb_header,0,end)||!sxgp_word(v,6,4,false,&end,end)||!sxgp_xnb_var(v,&p,end,1,&z)||z!=1||!sxgp_xnb_var(v,&p,end,0,&z)||z>1024||!sxgp_read(v,p,name,(size_t)z,end))return false;name[z]=0;p+=z;
 if(!SG_ROW(xnb_reader_version,p,end))return false;p+=4;if(!sxgp_xnb_var(v,&p,end,1,&z)||z||!sxgp_xnb_var(v,&p,end,2,&z)||z!=1)return false;
 if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.Texture2DReader",46)){if(!SG_ROW(xnb_texture,p,end)||!sxgp_word(v,p+12,4,false,&mips,end)||mips>16)return false;p+=16;for(uint64_t i=0;i<mips;i++){if(!SG_ROW(xnb_mip,p,end)||!sxgp_word(v,p,4,false,&z,end)||!sxgp_span(v,p+4,z,end))return false;p+=4+z;}}
 else if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.StringReader",43)){if(!sxgp_xnb_var(v,&p,end,0,&z)||!sxgp_span(v,p,z,end))return false;p+=z;}
 else if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.ByteReader",41)){if(!SG_ROW(xnb_byte,p,end))return false;p++;}
 else if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.Int32Reader",42)){if(!SG_ROW(xnb_int32,p,end))return false;p+=4;}
 else if(!xx_rt_strncmp(name,"Microsoft.Xna.Framework.Content.SingleReader",43)){if(!SG_ROW(xnb_float32,p,end))return false;p+=4;}else return false;
 return p==end;}
static bool sxgp_unity(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p=12,ver,size,packed,flags,info,blocks,nodes;if(!SG_ROW(unity_header,0,end)||!sxgp_word(v,8,4,true,&ver,end)||!sxgp_cstring(v,&p,end,256)||!sxgp_cstring(v,&p,end,256)||!SG_ROW(unity_sizes,p,end)||!sxgp_word(v,p,8,true,&size,end)||size>end||!sxgp_word(v,p+8,4,true,&packed,end)||!sxgp_word(v,p+16,4,true,&flags,end))return false;p+=20;if(ver>=7)p=(p+15)&~UINT64_C(15);if(packed>size)return false;info=flags&128?size-packed:p;if(!sxgp_span(v,info,packed,size))return false;end=info+packed;
 if(!SG_ROW(unity_info,info,end)||!sxgp_word(v,info+16,4,true,&blocks,end)||blocks>65536||!sxgp_table(v,&sxgp_unity_block,info+20,blocks,end))return false;p=info+20+10*blocks;
 if(!SG_ROW(unity_node_count,p,end)||!sxgp_word(v,p,4,true,&nodes,end)||nodes>65536)return false;p+=4;
 for(uint64_t i=0;i<nodes;i++){if(!SG_ROW(unity_node,p,end))return false;p+=20;if(!sxgp_cstring(v,&p,end,4096))return false;}return p==end;}
static bool sxgp_hpi(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,de,root,queue[1024];unsigned used=0,count=1;if(!SG_ROW(hpi_header,0,end)||!sxgp_word(v,8,4,false,&de,end)||de>end||!sxgp_word(v,16,4,false,&root,end))return false;queue[0]=root;
 while(used<count){uint64_t at=queue[used++],n,table;if(!SG_ROW(hpi_directory,at,de)||!sxgp_word(v,at,4,false,&n,de)||n>65536||!sxgp_word(v,at+4,4,false,&table,de)||!sxgp_table(v,&sxgp_hpi_entry,table,n,de))return false;
  for(uint64_t i=0;i<n;i++){uint64_t p=table+i*9,rec,kind;if(!sxgp_word(v,p+4,4,false,&rec,de)||!sxgp_word(v,p+8,1,false,&kind,de))return false;if(kind){if(count==1024)return false;for(unsigned j=0;j<count;j++)if(queue[j]==rec)return false;queue[count++]=rec;}else if(!SG_ROW(hpi_file,rec,de))return false;}}
 return true;}
static bool sxgp_rff(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,ver,at,n;if(!SG_ROW(rff_header,0,end)||!sxgp_word(v,4,2,false,&ver,end)||!sxgp_word(v,8,4,false,&at,end)||!sxgp_word(v,12,4,false,&n,end))return false;return ver!=0x200||sxgp_table(v,&sxgp_rff_entry,at,n,end);}
static uint8_t sxgp_reverse(uint8_t b){b=(uint8_t)((b>>4)|(b<<4));b=(uint8_t)(((b&204)>>2)|((b&51)<<2));return(uint8_t)(((b&170)>>1)|((b&85)<<1));}
static bool sxgp_binder(sxgp_view*v)
{uint8_t h[64];uint64_t end=(uint64_t)v->c->size,n,entry,p;bool four,be,bitbe;unsigned fmt;if(!sxgp_read(v,0,h,32,end))return false;four=h[3]=='4';if(four){if(!sxgp_read(v,0,h,64,end))return false;be=h[9]!=0;bitbe=!h[10];fmt=bitbe||((h[49]&1)&&!(h[49]&128))?h[49]:sxgp_reverse(h[49]);n=xx_data_get_u32(h+12,4,0,be);entry=16+((fmt&16)?8:4)+((fmt&32)?8:0)+((fmt&2)?4:0)+((fmt&12)?4:0)+(fmt==4?8:0);p=64;}
 else{bitbe=h[14]!=0;fmt=bitbe||((h[12]&1)&&!(h[12]&128))?h[12]:sxgp_reverse(h[12]);be=h[13]||(fmt&1);n=xx_data_get_u32(h+16,4,0,be);entry=8+((fmt&16)?8:4)+((fmt&2)?4:0)+((fmt&12)?4:0)+((fmt&32)?4:0);p=32;}
 const sx_layout*header=four?(be?&sxgp_bnd4_header_be:&sxgp_bnd4_header_le):(be?&sxgp_bnd3_header_be:&sxgp_bnd3_header_le);
 if(n>65536||!sxgp_row(v,header,0,end)||!sxgp_span(v,p,n*entry,end))return false;
 for(uint64_t i=0;i<n;i++){uint64_t stop=p+entry;const sx_layout*prefix=four?(be?&sxgp_bnd4_entry_be:&sxgp_bnd4_entry_le):(be?&sxgp_bnd3_entry_be:&sxgp_bnd3_entry_le);if(!sxgp_row(v,prefix,p,stop))return false;p+=four?16:8;
  if(four&&(fmt&32)){if(!sxgp_row(v,be?&sxgp_bnd_raw64_be:&sxgp_bnd_raw64_le,p,stop))return false;p+=8;}
  if(!sxgp_row(v,fmt&16?(be?&sxgp_bnd_offset64_be:&sxgp_bnd_offset64_le):(be?&sxgp_bnd_offset32_be:&sxgp_bnd_offset32_le),p,stop))return false;p+=fmt&16?8:4;
  if(fmt&2){if(!sxgp_row(v,be?&sxgp_bnd_id_be:&sxgp_bnd_id_le,p,stop))return false;p+=4;}
  if(fmt&12){if(!sxgp_row(v,four?(be?&sxgp_bnd4_name_be:&sxgp_bnd4_name_le):(be?&sxgp_bnd3_name_be:&sxgp_bnd3_name_le),p,stop))return false;p+=4;}
  if(!four&&(fmt&32)){if(!sxgp_row(v,be?&sxgp_bnd_raw32_be:&sxgp_bnd_raw32_le,p,stop))return false;p+=4;}
  if(four&&fmt==4){if(!sxgp_row(v,be?&sxgp_bnd4_names_extra_be:&sxgp_bnd4_names_extra_le,p,stop))return false;p+=8;}
  if(p!=stop)return false;
 }return true;}
static bool sxgp_xp3(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p,z,stop;uint8_t tag[4];if(!SG_ROW(xp3_header,0,end)||!sxgp_word(v,11,8,false,&p,end)||!SG_ROW(xp3_index,p,end)||!sxgp_word(v,p+1,8,false,&z,end)||!sxgp_span(v,p+9,z,end))return false;p+=9;stop=p+z;
 while(p<stop){uint64_t fend;if(!SG_ROW(xp3_chunk,p,stop)||!sxgp_word(v,p+4,8,false,&z,stop)||!sxgp_span(v,p+12,z,stop))return false;p+=12;fend=p+z;
  while(p<fend){if(!SG_ROW(xp3_chunk,p,fend)||!sxgp_read(v,p,tag,4,fend)||!sxgp_word(v,p+4,8,false,&z,fend)||!sxgp_span(v,p+12,z,fend))return false;p+=12;
   const sx_layout*l=!xx_rt_memcmp(tag,"info",4)?&sxgp_xp3_info:!xx_rt_memcmp(tag,"segm",4)?&sxgp_xp3_segment:!xx_rt_memcmp(tag,"adlr",4)?&sxgp_xp3_checksum:NULL;if(l&&!sxgp_row(v,l,p,p+z))return false;p+=z;
  }
 }return p==stop;}
static bool sxgp_lspk(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,n;return SG_ROW(lspk_header,0,end)&&sxgp_word(v,20,4,false,&n,end)&&n<=4096&&sxgp_table(v,&sxgp_lspk_file,24,n,end);}
static bool sxgp_lsf(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p=52,z[4],buckets;if(!SG_ROW(lsf_header,0,end))return false;for(unsigned i=0;i<4;i++)if(!sxgp_word(v,12+i*8,4,false,&z[i],end))return false;
 if(!sxgp_span(v,p,z[0],end)||!SG_ROW(lsf_string_table,p,p+z[0])||!sxgp_word(v,p,4,false,&buckets,p+z[0])||buckets>4096)return false;uint64_t stop=p+z[0];p+=4;
 for(uint64_t i=0;i<buckets;i++){uint64_t n,len;if(!SG_ROW(lsf_bucket,p,stop)||!sxgp_word(v,p,2,false,&n,stop))return false;p+=2;for(uint64_t j=0;j<n;j++){if(!SG_ROW(lsf_string,p,stop)||!sxgp_word(v,p,2,false,&len,stop)||!sxgp_span(v,p+2,len,stop))return false;p+=2+len;}}
 if(p!=stop||z[1]%12||z[2]%12||!sxgp_table(v,&sxgp_lsf_node,p,z[1]/12,end))return false;p+=z[1];return sxgp_table(v,&sxgp_lsf_attribute,p,z[2]/12,end)&&sxgp_span(v,p+z[2],z[3],end);}
static bool sxgp_rpa(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,index=0;uint8_t text[16];if(!SG_ROW(rpa_header,0,end)||!sxgp_read(v,8,text,16,end))return false;for(unsigned i=0;i<16;i++){unsigned d=text[i]>='0'&&text[i]<='9'?text[i]-'0':text[i]>='a'&&text[i]<='f'?text[i]-'a'+10:text[i]>='A'&&text[i]<='F'?text[i]-'A'+10:16;if(d==16)return false;index=(index<<4)|d;}return end>=4&&SG_ROW(rpa_zlib,index,end)&&SG_ROW(rpa_adler,end-4,end);}
static bool sxgp_nbt_text(sxgp_view*v,uint64_t*p,uint64_t end)
{uint64_t z;if(!SG_ROW(nbt_string,*p,end)||!sxgp_word(v,*p,2,true,&z,end)||!sxgp_span(v,*p+2,z,end))return false;*p+=2+z;return true;}
static bool sxgp_nbt_value(sxgp_view*v,uint64_t*p,uint64_t end,unsigned type,unsigned depth)
{if(depth>32||++v->work>4000000)return false;uint64_t n,kind;const sx_layout*scalars[]={&sxgp_nbt_byte,&sxgp_nbt_short,&sxgp_nbt_int,&sxgp_nbt_long,&sxgp_nbt_float,&sxgp_nbt_double};
 if(type>=1&&type<=6){const sx_layout*l=scalars[type-1];if(!sxgp_row(v,l,*p,end))return false;*p+=(uint64_t)l->fields[0].size;return true;}
 if(type==8)return sxgp_nbt_text(v,p,end);
 if(type==7||type==11||type==12){if(!SG_ROW(nbt_array,*p,end)||!sxgp_word(v,*p,4,true,&n,end)||n>1048576)return false;*p+=4;const sx_layout*l=type==7?&sxgp_nbt_byte:type==11?&sxgp_nbt_int:&sxgp_nbt_long;uint64_t z=(uint64_t)l->fields[0].size;if(!sxgp_table(v,l,*p,n,end))return false;*p+=n*z;return true;}
 if(type==9){if(!SG_ROW(nbt_list,*p,end)||!sxgp_word(v,*p,1,false,&kind,end)||!sxgp_word(v,*p+1,4,true,&n,end)||n>65536||kind>12||(!kind&&n))return false;*p+=5;for(uint64_t i=0;i<n;i++)if(!sxgp_nbt_value(v,p,end,(unsigned)kind,depth+1))return false;return true;}
 if(type==10){for(unsigned i=0;i<=4096;i++){if(!SG_ROW(nbt_tag,*p,end)||!sxgp_word(v,*p,1,false,&kind,end))return false;(*p)++;if(!kind)return true;if(i==4096||!sxgp_nbt_text(v,p,end)||!sxgp_nbt_value(v,p,end,(unsigned)kind,depth+1))return false;}}
 return false;}
static bool sxgp_nbt(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,p=1;return SG_ROW(nbt_tag,0,end)&&sxgp_nbt_text(v,&p,end)&&sxgp_nbt_value(v,&p,end,10,0)&&p==end;}
static bool sxgp_szx(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p=8,z,minor;uint8_t tag[4];if(!SG_ROW(szx_header,0,end)||!sxgp_word(v,5,1,false,&minor,end))return false;
 while(p<end){if(!SG_ROW(szx_chunk,p,end)||!sxgp_read(v,p,tag,4,end)||!sxgp_word(v,p+4,4,false,&z,end)||!sxgp_span(v,p+8,z,end))return false;p+=8;uint64_t stop=p+z;const sx_layout*l=NULL;
  if(!xx_rt_memcmp(tag,"Z80R",4)){if(!SG_ROW(szx_z80,p,stop)||!sxgp_row(v,minor==0?&sxgp_szx_z80_v0_tail:minor<4?&sxgp_szx_z80_v1_tail:&sxgp_szx_z80_v4_tail,p+33,stop))return false;}
  else if(!xx_rt_memcmp(tag,"SPCR",4))l=&sxgp_szx_spectrum;
  else if(!xx_rt_memcmp(tag,"RAMP",4))l=&sxgp_szx_ram;
  else if(!xx_rt_memcmp(tag,"CRTR",4))l=&sxgp_szx_creator;
  else if(!xx_rt_memcmp(tag,"JOY\0",4))l=&sxgp_szx_joystick;
  else if(!xx_rt_memcmp(tag,"ZXPR",4))l=&sxgp_szx_printer;
  else if(!xx_rt_memcmp(tag,"AY\0\0",4))l=&sxgp_szx_ay;
  else if(!xx_rt_memcmp(tag,"KEYB",4)){l=&sxgp_szx_keyboard;if(minor&&!SG_ROW(szx_keyboard_joystick,p+4,stop))return false;}
  if(l&&!sxgp_row(v,l,p,stop))return false;p=stop;
 }return p==end;}
static bool sxgp_cpc(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,ver;return SG_ROW(cpc_header,0,end)&&sxgp_word(v,16,1,false,&ver,end)&&sxgp_row(v,ver==1?&sxgp_cpc_v1_tail:&sxgp_cpc_model,0x6d,end);}
static bool sxgp_fds(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,sides;if(!SG_ROW(fds_header,0,end)||!sxgp_word(v,4,1,false,&sides,end)||sides>8)return false;for(uint64_t i=0;i<sides;i++){uint64_t p=16+i*65500,n,z,stop=p+65500;if(!sxgp_span(v,p,65500,end)||!SG_ROW(fds_side,p,stop)||!SG_ROW(fds_file_count,p+56,stop)||!sxgp_word(v,p+57,1,false,&n,stop)||n>128)return false;p+=58;for(uint64_t j=0;j<n;j++){if(!SG_ROW(fds_file,p,stop)||!sxgp_word(v,p+13,2,false,&z,stop)||!sxgp_span(v,p+17,z,stop))return false;p+=17+z;}}return true;}
static bool sxgp_cia(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,tmd=0x2dc0,ts,ms,cs,n,meta;if(!SG_ROW(cia_header,0,end)||!sxgp_word(v,16,4,false,&ts,end)||!sxgp_word(v,20,4,false,&ms,end)||!sxgp_word(v,24,8,false,&cs,end)||!sxgp_span(v,tmd,ts,end))return false;
 uint64_t stop=tmd+ts;if(!SG_ROW(cia_signature,tmd,stop)||!SG_ROW(cia_tmd,tmd+0x140,stop)||!sxgp_table(v,&sxgp_cia_content_info,tmd+0x204,64,stop)||!sxgp_word(v,tmd+0x1de,2,true,&n,stop)||n>1024||!sxgp_table(v,&sxgp_cia_content,tmd+0xb04,n,stop))return false;
 uint64_t content=(stop+63)&~UINT64_C(63);if(!sxgp_span(v,content,cs,end))return false;meta=(content+cs+63)&~UINT64_C(63);return !ms||(sxgp_span(v,meta,ms,end)&&SG_ROW(cia_metadata,meta,meta+ms));}
static bool sxgp_gcm(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,dol,fst,fs,n;if(!SG_ROW(gcm_id,0,end)||!SG_ROW(gcm_title,32,end)||!SG_ROW(gcm_debug,0x400,end)||!SG_ROW(gcm_boot,0x420,end)||!SG_ROW(gcm_apploader,0x2440,end)||!sxgp_word(v,0x420,4,true,&dol,end)||!sxgp_word(v,0x424,4,true,&fst,end)||!sxgp_word(v,0x428,4,true,&fs,end)||!sxgp_span(v,fst,fs,end))return false;
 if(!sxgp_table(v,&sxgp_gcm_dol_offset,dol,18,end)||!sxgp_table(v,&sxgp_gcm_dol_address,dol+72,18,end)||!sxgp_table(v,&sxgp_gcm_dol_size,dol+144,18,end)||!SG_ROW(gcm_dol_tail,dol+216,end))return false;
 uint64_t stop=fst+fs;if(!SG_ROW(gcm_fst_root,fst,stop)||!sxgp_word(v,fst+8,4,true,&n,stop)||!n||n>4094||!sxgp_span(v,fst,n*12,stop))return false;
 for(uint64_t i=1;i<n;i++){uint64_t at=fst+i*12,kind;if(!sxgp_word(v,at,1,false,&kind,stop)||!sxgp_row(v,kind?&sxgp_gcm_fst_directory:&sxgp_gcm_fst_file,at,stop))return false;}return true;}
static bool sxgp_wbfs(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,shift,physical;uint8_t tag[4];if(!SG_ROW(wbfs_header,0,end)||!SG_ROW(gcm_id,512,end)||!SG_ROW(wbfs_disc_title,544,end)||!sxgp_word(v,9,1,false,&shift,end)||shift<19||shift>24)return false;
 uint64_t cluster=UINT64_C(1)<<shift,n=(UINT64_C(143432)*2*32768+cluster-1)/cluster;if(!sxgp_table(v,&sxgp_wbfs_block,768,n,end)||!sxgp_word(v,768,2,true,&physical,end)||!sxgp_span(v,physical*cluster,256,end)||!SG_ROW(gcm_id,physical*cluster,end)||!SG_ROW(wbfs_disc_title,physical*cluster+32,end))return false;
 if(!sxgp_read(v,512+236,tag,4,end))return false;return xx_rt_memcmp(tag,"MD5#",4)||SG_ROW(wbfs_md5,512+236,end);}

static bool sx_gameplatforms_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_UNITYFS:
case XX_FILE_TYPE_TOTALANNIHILATION_HPI:
case XX_FILE_TYPE_RAVENSOFT_RFF:
case XX_FILE_TYPE_KIRIKIRI_XP3:
case XX_FILE_TYPE_FROMSOFTWARE_BINDER:
case XX_FILE_TYPE_NINTENDO_NCCH:
case XX_FILE_TYPE_NINTENDO_NCSD:
case XX_FILE_TYPE_NINTENDO_CIA:
case XX_FILE_TYPE_NINTENDO_NDS:
case XX_FILE_TYPE_NINTENDO_GCM:
case XX_FILE_TYPE_LARIAN_LSPK:
case XX_FILE_TYPE_LARIAN_LSF:
case XX_FILE_TYPE_RENPY_RPA:
case XX_FILE_TYPE_NINTENDO_WBFS:
case XX_FILE_TYPE_SONY_PSP_PBP:
case XX_FILE_TYPE_NINTENDO_N64_ROM:
case XX_FILE_TYPE_NINTENDO_GB_ROM:
case XX_FILE_TYPE_NINTENDO_GBA_ROM:
case XX_FILE_TYPE_SEGA_MEGADRIVE_ROM:
case XX_FILE_TYPE_XNA_XNB:
case XX_FILE_TYPE_ZX_SPECTRUM_SZX:
case XX_FILE_TYPE_NINTENDO_UNIF:
case XX_FILE_TYPE_NINTENDO_FDS:
case XX_FILE_TYPE_ATARI_7800_A78:
case XX_FILE_TYPE_AMSTRAD_CPC_SNA:
case XX_FILE_TYPE_MINECRAFT_NBT:
case XX_FILE_TYPE_MSX_ROM:
case XX_FILE_TYPE_SEGA_SMS_ROM:
case XX_FILE_TYPE_TIC80:
return true;default:return false;}}
static bool sx_gameplatforms_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxgp_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_UNITYFS:ok=sxgp_unity(v);break;
case XX_FILE_TYPE_TOTALANNIHILATION_HPI:ok=sxgp_hpi(v);break;
case XX_FILE_TYPE_RAVENSOFT_RFF:ok=sxgp_rff(v);break;
case XX_FILE_TYPE_KIRIKIRI_XP3:ok=sxgp_xp3(v);break;
case XX_FILE_TYPE_FROMSOFTWARE_BINDER:ok=sxgp_binder(v);break;
case XX_FILE_TYPE_NINTENDO_NCCH:ok=sxgp_ncch(v);break;
case XX_FILE_TYPE_NINTENDO_NCSD:ok=sxgp_ncsd(v);break;
case XX_FILE_TYPE_NINTENDO_CIA:ok=sxgp_cia(v);break;
case XX_FILE_TYPE_NINTENDO_NDS:ok=sxgp_nds(v);break;
case XX_FILE_TYPE_NINTENDO_GCM:ok=sxgp_gcm(v);break;
case XX_FILE_TYPE_LARIAN_LSPK:ok=sxgp_lspk(v);break;
case XX_FILE_TYPE_LARIAN_LSF:ok=sxgp_lsf(v);break;
case XX_FILE_TYPE_RENPY_RPA:ok=sxgp_rpa(v);break;
case XX_FILE_TYPE_NINTENDO_WBFS:ok=sxgp_wbfs(v);break;
case XX_FILE_TYPE_SONY_PSP_PBP:ok=sxgp_pbp(v);break;
case XX_FILE_TYPE_NINTENDO_N64_ROM:ok=sxgp_n64(v);break;
case XX_FILE_TYPE_NINTENDO_GB_ROM:ok=sxgp_gb(v);break;
case XX_FILE_TYPE_NINTENDO_GBA_ROM:ok=sxgp_gba(v);break;
case XX_FILE_TYPE_SEGA_MEGADRIVE_ROM:ok=sxgp_megadrive(v);break;
case XX_FILE_TYPE_XNA_XNB:ok=sxgp_xnb(v);break;
case XX_FILE_TYPE_ZX_SPECTRUM_SZX:ok=sxgp_szx(v);break;
case XX_FILE_TYPE_NINTENDO_UNIF:ok=sxgp_unif(v);break;
case XX_FILE_TYPE_NINTENDO_FDS:ok=sxgp_fds(v);break;
case XX_FILE_TYPE_ATARI_7800_A78:ok=sxgp_a78(v);break;
case XX_FILE_TYPE_AMSTRAD_CPC_SNA:ok=sxgp_cpc(v);break;
case XX_FILE_TYPE_MINECRAFT_NBT:ok=sxgp_nbt(v);break;
case XX_FILE_TYPE_MSX_ROM:ok=sxgp_msx(v);break;
case XX_FILE_TYPE_SEGA_SMS_ROM:ok=sxgp_sms(v);break;
case XX_FILE_TYPE_TIC80:ok=sxgp_tic(v);break;
default:break;}
 return ok&&sxgp_finish(c);}
#undef SG_ROW
static bool sx_gameplatforms_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60360001)||id>=UINT32_C(0x60370000))return true;
 if(r->type&&!xx_rt_wcsncmp(r->type,L"ascii_",6)&&xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;
 if(id==1614151688u&&!xx_rt_wcscmp(r->name,L"cartridge_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"ROM_ONLY");
 case 1u:return xx_data_struct_record_set_comment(r,L"MBC1");
 case 2u:return xx_data_struct_record_set_comment(r,L"MBC1_RAM");
 case 3u:return xx_data_struct_record_set_comment(r,L"MBC1_RAM_BATTERY");
 case 5u:return xx_data_struct_record_set_comment(r,L"MBC2");
 case 6u:return xx_data_struct_record_set_comment(r,L"MBC2_BATTERY");
 case 8u:return xx_data_struct_record_set_comment(r,L"ROM_RAM");
 case 9u:return xx_data_struct_record_set_comment(r,L"ROM_RAM_BATTERY");
 case 15u:return xx_data_struct_record_set_comment(r,L"MBC3_TIMER_BATTERY");
 case 16u:return xx_data_struct_record_set_comment(r,L"MBC3_TIMER_RAM_BATTERY");
 case 17u:return xx_data_struct_record_set_comment(r,L"MBC3");
 case 18u:return xx_data_struct_record_set_comment(r,L"MBC3_RAM");
 case 19u:return xx_data_struct_record_set_comment(r,L"MBC3_RAM_BATTERY");
 case 25u:return xx_data_struct_record_set_comment(r,L"MBC5");
 case 26u:return xx_data_struct_record_set_comment(r,L"MBC5_RAM");
 case 27u:return xx_data_struct_record_set_comment(r,L"MBC5_RAM_BATTERY");
 default:break;}}
 if(id==1614151688u&&!xx_rt_wcscmp(r->name,L"destination_code")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"JAPAN");
 case 1u:return xx_data_struct_record_set_comment(r,L"OVERSEAS");
 default:break;}}
 if(id==1614151687u&&!xx_rt_wcscmp(r->name,L"cgb_flag")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 128u:return xx_data_struct_record_set_comment(r,L"CGB_COMPATIBLE");
 case 192u:return xx_data_struct_record_set_comment(r,L"CGB_ONLY");
 default:break;}}
 if(id==1614151688u&&!xx_rt_wcscmp(r->name,L"rom_size_code")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"32 KiB");
 case 1u:return xx_data_struct_record_set_comment(r,L"64 KiB");
 case 2u:return xx_data_struct_record_set_comment(r,L"128 KiB");
 case 3u:return xx_data_struct_record_set_comment(r,L"256 KiB");
 case 4u:return xx_data_struct_record_set_comment(r,L"512 KiB");
 case 5u:return xx_data_struct_record_set_comment(r,L"1024 KiB");
 case 6u:return xx_data_struct_record_set_comment(r,L"2048 KiB");
 case 7u:return xx_data_struct_record_set_comment(r,L"4096 KiB");
 case 8u:return xx_data_struct_record_set_comment(r,L"8192 KiB");
 default:break;}}
 if(id==1614151688u&&!xx_rt_wcscmp(r->name,L"ram_size_code")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"NONE");
 case 1u:return xx_data_struct_record_set_comment(r,L"2 KiB");
 case 2u:return xx_data_struct_record_set_comment(r,L"8 KiB");
 case 3u:return xx_data_struct_record_set_comment(r,L"32 KiB");
 case 4u:return xx_data_struct_record_set_comment(r,L"128 KiB");
 case 5u:return xx_data_struct_record_set_comment(r,L"64 KiB");
 default:break;}}
 if(id==1614151698u&&!xx_rt_wcscmp(r->name,L"mirroring")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"HORIZONTAL");
 case 1u:return xx_data_struct_record_set_comment(r,L"VERTICAL");
 case 2u:return xx_data_struct_record_set_comment(r,L"SINGLE_SCREEN_0");
 case 3u:return xx_data_struct_record_set_comment(r,L"SINGLE_SCREEN_1");
 case 4u:return xx_data_struct_record_set_comment(r,L"FOUR_SCREEN");
 case 5u:return xx_data_struct_record_set_comment(r,L"MAPPER_CONTROLLED");
 default:break;}}
 if(id==1614151701u&&!xx_rt_wcscmp(r->name,L"file_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PRG_RAM");
 case 1u:return xx_data_struct_record_set_comment(r,L"CHR_RAM");
 case 2u:return xx_data_struct_record_set_comment(r,L"NAMETABLE");
 default:break;}}
 if(id==1614151704u&&!xx_rt_wcscmp(r->name,L"data_format")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 4u:return xx_data_struct_record_set_comment(r,L"BINARY");
 case 516u:return xx_data_struct_record_set_comment(r,L"UTF8_STRING");
 case 1028u:return xx_data_struct_record_set_comment(r,L"INT32");
 default:break;}}
 if(id==1614151705u&&!xx_rt_wcscmp(r->name,L"target_platform")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 119u:return xx_data_struct_record_set_comment(r,L"WINDOWS");
 case 120u:return xx_data_struct_record_set_comment(r,L"XBOX360");
 case 109u:return xx_data_struct_record_set_comment(r,L"WINDOWS_PHONE");
 default:break;}}
 if(id==1614151705u&&!xx_rt_wcscmp(r->name,L"flags")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"UNCOMPRESSED_REACH");
 case 1u:return xx_data_struct_record_set_comment(r,L"UNCOMPRESSED_HIDEF");
 case 128u:return xx_data_struct_record_set_comment(r,L"LZX_COMPRESSED");
 case 64u:return xx_data_struct_record_set_comment(r,L"LZ4_COMPRESSED");
 default:break;}}
 if(id==1614151713u&&!xx_rt_wcscmp(r->name,L"surface_format")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"COLOR");
 case 1u:return xx_data_struct_record_set_comment(r,L"BGR565");
 case 2u:return xx_data_struct_record_set_comment(r,L"BGRA5551");
 case 3u:return xx_data_struct_record_set_comment(r,L"BGRA4444");
 case 4u:return xx_data_struct_record_set_comment(r,L"DXT1");
 case 5u:return xx_data_struct_record_set_comment(r,L"DXT3");
 case 6u:return xx_data_struct_record_set_comment(r,L"DXT5");
 case 7u:return xx_data_struct_record_set_comment(r,L"NORMALIZED_BYTE2");
 case 8u:return xx_data_struct_record_set_comment(r,L"NORMALIZED_BYTE4");
 case 9u:return xx_data_struct_record_set_comment(r,L"RGBA1010102");
 case 10u:return xx_data_struct_record_set_comment(r,L"RG32");
 case 11u:return xx_data_struct_record_set_comment(r,L"RGBA64");
 case 12u:return xx_data_struct_record_set_comment(r,L"ALPHA8");
 case 13u:return xx_data_struct_record_set_comment(r,L"SINGLE");
 case 14u:return xx_data_struct_record_set_comment(r,L"VECTOR2");
 case 15u:return xx_data_struct_record_set_comment(r,L"VECTOR4");
 case 16u:return xx_data_struct_record_set_comment(r,L"HALF_SINGLE");
 case 17u:return xx_data_struct_record_set_comment(r,L"HALF_VECTOR2");
 case 18u:return xx_data_struct_record_set_comment(r,L"HALF_VECTOR4");
 case 19u:return xx_data_struct_record_set_comment(r,L"HDR_BLENDABLE");
 default:break;}}
 if(id==1614151746u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"LZ77");
 case 2u:return xx_data_struct_record_set_comment(r,L"ZLIB");
 default:break;}}
 if(id==1614151819u&&!xx_rt_wcscmp(r->name,L"signature_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 65540u:return xx_data_struct_record_set_comment(r,L"RSA2048_SHA256");
 default:break;}}
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"version")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"NCCH_VERSION_0");
 case 1u:return xx_data_struct_record_set_comment(r,L"NCCH_VERSION_1");
 case 2u:return xx_data_struct_record_set_comment(r,L"NCCH_VERSION_2");
 default:break;}}
 if(id==1614151790u&&!xx_rt_wcscmp(r->name,L"tag_id")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"TAG_End");
 case 1u:return xx_data_struct_record_set_comment(r,L"TAG_Byte");
 case 2u:return xx_data_struct_record_set_comment(r,L"TAG_Short");
 case 3u:return xx_data_struct_record_set_comment(r,L"TAG_Int");
 case 4u:return xx_data_struct_record_set_comment(r,L"TAG_Long");
 case 5u:return xx_data_struct_record_set_comment(r,L"TAG_Float");
 case 6u:return xx_data_struct_record_set_comment(r,L"TAG_Double");
 case 7u:return xx_data_struct_record_set_comment(r,L"TAG_Byte_Array");
 case 8u:return xx_data_struct_record_set_comment(r,L"TAG_String");
 case 9u:return xx_data_struct_record_set_comment(r,L"TAG_List");
 case 10u:return xx_data_struct_record_set_comment(r,L"TAG_Compound");
 case 11u:return xx_data_struct_record_set_comment(r,L"TAG_Int_Array");
 case 12u:return xx_data_struct_record_set_comment(r,L"TAG_Long_Array");
 default:break;}}
 if(id==1614151793u&&!xx_rt_wcscmp(r->name,L"element_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"TAG_End");
 case 1u:return xx_data_struct_record_set_comment(r,L"TAG_Byte");
 case 2u:return xx_data_struct_record_set_comment(r,L"TAG_Short");
 case 3u:return xx_data_struct_record_set_comment(r,L"TAG_Int");
 case 4u:return xx_data_struct_record_set_comment(r,L"TAG_Long");
 case 5u:return xx_data_struct_record_set_comment(r,L"TAG_Float");
 case 6u:return xx_data_struct_record_set_comment(r,L"TAG_Double");
 case 7u:return xx_data_struct_record_set_comment(r,L"TAG_Byte_Array");
 case 8u:return xx_data_struct_record_set_comment(r,L"TAG_String");
 case 9u:return xx_data_struct_record_set_comment(r,L"TAG_List");
 case 10u:return xx_data_struct_record_set_comment(r,L"TAG_Compound");
 case 11u:return xx_data_struct_record_set_comment(r,L"TAG_Int_Array");
 case 12u:return xx_data_struct_record_set_comment(r,L"TAG_Long_Array");
 default:break;}}
 if(id==1614151800u&&!xx_rt_wcscmp(r->name,L"machine")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_16K");
 case 1u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_48K");
 case 2u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_128K");
 case 3u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_PLUS2");
 case 4u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_PLUS2A");
 case 5u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_PLUS3");
 default:break;}}
 if(id==1614151816u&&!xx_rt_wcscmp(r->name,L"machine_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"CPC464");
 case 1u:return xx_data_struct_record_set_comment(r,L"CPC664");
 case 2u:return xx_data_struct_record_set_comment(r,L"CPC6128");
 default:break;}}
 if(id==1614151681u&&!xx_rt_wcscmp(r->name,L"init_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151681u&&!xx_rt_wcscmp(r->name,L"runtime_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151681u&&!xx_rt_wcscmp(r->name,L"device_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151681u&&!xx_rt_wcscmp(r->name,L"text_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151682u&&!xx_rt_wcscmp(r->name,L"start_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151682u&&!xx_rt_wcscmp(r->name,L"end_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151682u&&!xx_rt_wcscmp(r->name,L"init_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151690u&&!xx_rt_wcscmp(r->name,L"stack_pointer"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151690u&&!xx_rt_wcscmp(r->name,L"reset_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151691u&&!xx_rt_wcscmp(r->name,L"handler_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"rom_start"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"rom_end"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"ram_start"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"ram_end"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"sram_start"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"sram_end"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151693u&&!xx_rt_wcscmp(r->name,L"entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151701u&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"param_sfo_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"icon0_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"icon1_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"pic0_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"pic1_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"snd0_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"data_psp_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"data_psar_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151703u&&!xx_rt_wcscmp(r->name,L"key_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded PARAM.SFO header");
 if(id==1614151703u&&!xx_rt_wcscmp(r->name,L"data_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded PARAM.SFO header");
 if(id==1614151704u&&!xx_rt_wcscmp(r->name,L"key_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the SFO key table");
 if(id==1614151704u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the SFO data table");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"content_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"plain_offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"plain_size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"logo_offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"logo_size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"exefs_offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"exefs_size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"exefs_hash_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"romfs_offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"romfs_size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"romfs_hash_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151719u&&!xx_rt_wcscmp(r->name,L"content_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151720u&&!xx_rt_wcscmp(r->name,L"offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151720u&&!xx_rt_wcscmp(r->name,L"size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151723u&&!xx_rt_wcscmp(r->name,L"address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_rom_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_rom_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"fnt_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"fat_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_overlay_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_overlay_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"banner_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_autoload_list_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_autoload_list_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"debug_rom_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"debug_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151730u&&!xx_rt_wcscmp(r->name,L"start_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151730u&&!xx_rt_wcscmp(r->name,L"end_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151731u&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151731u&&!xx_rt_wcscmp(r->name,L"static_init_start"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151731u&&!xx_rt_wcscmp(r->name,L"static_init_end"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151732u&&!xx_rt_wcscmp(r->name,L"subtable_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the file-name table");
 if(id==1614151736u&&!xx_rt_wcscmp(r->name,L"subtable_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the file-name table");
 if(id==1614151742u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the uncompressed block stream; supported blocks are stored");
 if(id==1614151743u&&!xx_rt_wcscmp(r->name,L"directory_end_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151743u&&!xx_rt_wcscmp(r->name,L"root_directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151744u&&!xx_rt_wcscmp(r->name,L"entries_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151745u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151745u&&!xx_rt_wcscmp(r->name,L"record_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151746u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151747u&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151748u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151749u&&!xx_rt_wcscmp(r->name,L"format_bits"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151749u&&!xx_rt_wcscmp(r->name,L"bit_big_endian"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151749u&&!xx_rt_wcscmp(r->name,L"headers_end"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151750u&&!xx_rt_wcscmp(r->name,L"reversed_bit_order"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151750u&&!xx_rt_wcscmp(r->name,L"headers_end"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151750u&&!xx_rt_wcscmp(r->name,L"format_bits"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151750u&&!xx_rt_wcscmp(r->name,L"hash_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151751u&&!xx_rt_wcscmp(r->name,L"file_flags"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151752u&&!xx_rt_wcscmp(r->name,L"file_flags"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151753u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151754u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151756u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151757u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151761u&&!xx_rt_wcscmp(r->name,L"format_bits"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151761u&&!xx_rt_wcscmp(r->name,L"bit_big_endian"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151761u&&!xx_rt_wcscmp(r->name,L"headers_end"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151762u&&!xx_rt_wcscmp(r->name,L"reversed_bit_order"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151762u&&!xx_rt_wcscmp(r->name,L"headers_end"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151762u&&!xx_rt_wcscmp(r->name,L"format_bits"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151762u&&!xx_rt_wcscmp(r->name,L"hash_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151763u&&!xx_rt_wcscmp(r->name,L"file_flags"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151764u&&!xx_rt_wcscmp(r->name,L"file_flags"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151765u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151766u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151768u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151769u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151773u&&!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151777u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151779u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151780u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151787u&&!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151802u&&!xx_rt_wcscmp(r->name,L"sp"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151802u&&!xx_rt_wcscmp(r->name,L"pc"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151805u&&!xx_rt_wcscmp(r->name,L"memptr"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151814u&&!xx_rt_wcscmp(r->name,L"sp"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151814u&&!xx_rt_wcscmp(r->name,L"pc"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151817u&&!xx_rt_wcscmp(r->name,L"manufacture_date_bcd"))return xx_data_struct_record_set_comment(r,L"Packed binary-coded decimal; original digits are preserved");
 if(id==1614151817u&&!xx_rt_wcscmp(r->name,L"rewrite_date_bcd"))return xx_data_struct_record_set_comment(r,L"Packed binary-coded decimal; original digits are preserved");
 if(id==1614151817u&&!xx_rt_wcscmp(r->name,L"rewrite_count_bcd"))return xx_data_struct_record_set_comment(r,L"Packed binary-coded decimal; original digits are preserved");
 if(id==1614151826u&&!xx_rt_wcscmp(r->name,L"debug_monitor_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151826u&&!xx_rt_wcscmp(r->name,L"debug_monitor_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151827u&&!xx_rt_wcscmp(r->name,L"dol_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151827u&&!xx_rt_wcscmp(r->name,L"fst_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151827u&&!xx_rt_wcscmp(r->name,L"fst_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151827u&&!xx_rt_wcscmp(r->name,L"user_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151828u&&!xx_rt_wcscmp(r->name,L"entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151829u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the FST string table");
 if(id==1614151829u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151830u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the FST string table");
 if(id==1614151831u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the FST string table");
 if(id==1614151832u&&!xx_rt_wcscmp(r->name,L"section_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded DOL header");
 if(id==1614151833u&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151835u&&!xx_rt_wcscmp(r->name,L"bss_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151835u&&!xx_rt_wcscmp(r->name,L"entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151732u&&!xx_rt_wcscmp(r->name,L"parent_id_or_directory_count"))return xx_data_struct_record_set_comment(r,L"Parent directory ID; the root uses a separate count layout");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"capacity_exponent"))return xx_data_struct_record_set_comment(r,L"ROM capacity exponent: 128 KiB multiplied by 2 to this power");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"secure_transfer_timeout"))return xx_data_struct_record_set_comment(r,L"Secure-area delay in 1/131000-second units");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"secure_area_disable"))return xx_data_struct_record_set_comment(r,L"Encrypted eight-byte secure-area-disable token");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"nand_rom_end_units"))return xx_data_struct_record_set_comment(r,L"NDS NAND position in 0x20000-byte units; zero means absent");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"nand_rw_start_units"))return xx_data_struct_record_set_comment(r,L"NDS NAND position in 0x20000-byte units; zero means absent");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"unknown_88"))return xx_data_struct_record_set_comment(r,L"Undocumented NDS word; retained without inferring an offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"reserved_or_fastboot"))return xx_data_struct_record_set_comment(r,L"Reserved bytes or homebrew fast-boot marker");
 if(id==1614151731u&&!xx_rt_wcscmp(r->name,L"compressed_size_flags"))return xx_data_struct_record_set_comment(r,L"Low 24 bits: compressed size in bytes; high 8 bits: flags");
 if(id==1614151723u&&!xx_rt_wcscmp(r->name,L"page_count"))return xx_data_struct_record_set_comment(r,L"Count of 4096-byte virtual-memory pages");
 if(id==1614151721u&&!xx_rt_wcscmp(r->name,L"sector_zero_offset_encoded"))return xx_data_struct_record_set_comment(r,L"Encoded sector-zero offset; retained in its on-disk units");
 if(id==1614151836u&&!xx_rt_wcscmp(r->name,L"host_sector_shift"))return xx_data_struct_record_set_comment(r,L"Base-2 logarithm of the host-sector size in bytes");
 if(id==1614151836u&&!xx_rt_wcscmp(r->name,L"wbfs_sector_shift"))return xx_data_struct_record_set_comment(r,L"Base-2 logarithm of the WBFS cluster size in bytes");
 if(id==1614151836u&&!xx_rt_wcscmp(r->name,L"host_sector_count"))return xx_data_struct_record_set_comment(r,L"Count of host sectors; size is 2 to host_sector_shift bytes");
 if(id==1614151838u&&!xx_rt_wcscmp(r->name,L"physical_cluster"))return xx_data_struct_record_set_comment(r,L"Physical WBFS cluster index; zero means unallocated; multiply by cluster size for bytes");
 if(id==1614151824u&&!xx_rt_wcscmp(r->name,L"stream_buffer_size"))return xx_data_struct_record_set_comment(r,L"Encoded audio streaming buffer-size selector");
 if(id==1614151821u&&!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Index of the first covered content record; not a byte offset");
 if(id==1614151823u&&!xx_rt_wcscmp(r->name,L"dependencies"))return xx_data_struct_record_set_comment(r,L"48 little-endian program IDs, each 64 bits");
 if(id==1614151814u&&!xx_rt_wcscmp(r->name,L"memory_dump_kib"))return xx_data_struct_record_set_comment(r,L"Memory dump length in 1024-byte units");
 if(id==1614151802u&&!xx_rt_wcscmp(r->name,L"tstates"))return xx_data_struct_record_set_comment(r,L"CPU T-state count within the current frame; not a wall-clock timestamp");
 if(id==1614151804u&&!xx_rt_wcscmp(r->name,L"hold_interrupt_cycles"))return xx_data_struct_record_set_comment(r,L"Remaining CPU cycles for the interrupt hold");
 if(id==1614151805u&&!xx_rt_wcscmp(r->name,L"hold_interrupt_cycles"))return xx_data_struct_record_set_comment(r,L"Remaining CPU cycles for the interrupt hold");
 if(id==1614151748u&&!xx_rt_wcscmp(r->name,L"runtime_state"))return xx_data_struct_record_set_comment(r,L"Serialized runtime/cache words; no pointer interpretation assumed");
 if(id==1614151748u&&!xx_rt_wcscmp(r->name,L"unknown_time_word"))return xx_data_struct_record_set_comment(r,L"Opaque on-disk word; epoch and interpretation not established by the native reader");
 if(id==1614151693u&&!xx_rt_wcscmp(r->name,L"pi_boot_config"))return xx_data_struct_record_set_comment(r,L"Packed initial peripheral-interface configuration bytes");
 if(id==1614151693u&&!xx_rt_wcscmp(r->name,L"clock_rate"))return xx_data_struct_record_set_comment(r,L"Encoded clock rate; boot code clears its low four bits");
 if(id==1614151693u&&!xx_rt_wcscmp(r->name,L"manufacturer"))return xx_data_struct_record_set_comment(r,L"32-bit manufacturer identifier, commonly ASCII N in its low byte");
 if(id==1614151683u&&!xx_rt_wcscmp(r->name,L"product_high_version"))return xx_data_struct_record_set_comment(r,L"High nibble: high product-code digit; low nibble: version");
 if(id==1614151683u&&!xx_rt_wcscmp(r->name,L"region_size"))return xx_data_struct_record_set_comment(r,L"High nibble: region/platform selector; low nibble: encoded ROM size");
 if(id==1614151684u&&!xx_rt_wcscmp(r->name,L"bank_type"))return xx_data_struct_record_set_comment(r,L"Bits 0..4: chunk type; bits 5..7: cartridge bank");
 if(id==1614151785u&&!xx_rt_wcscmp(r->name,L"name_reference"))return xx_data_struct_record_set_comment(r,L"Packed string-table bucket/index reference");
 if(id==1614151786u&&!xx_rt_wcscmp(r->name,L"name_reference"))return xx_data_struct_record_set_comment(r,L"Packed string-table bucket/index reference");
 if(id==1614151786u&&!xx_rt_wcscmp(r->name,L"type_length"))return xx_data_struct_record_set_comment(r,L"Low 6 bits: value type; upper 26 bits: stored value byte size");
 if(id==1614151786u&&!xx_rt_wcscmp(r->name,L"node_index"))return xx_data_struct_record_set_comment(r,L"Owning node index; signed sentinel values remain signed");
 if(id==1614151776u&&!xx_rt_wcscmp(r->name,L"name_utf16_units"))return xx_data_struct_record_set_comment(r,L"Count of UTF-16 code units in the following file name");
 return true;
}
