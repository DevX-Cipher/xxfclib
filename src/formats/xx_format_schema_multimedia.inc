/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical multimedia/scientific schemas. See docs/data_struct_multimedia_scope.txt
 * for native variants, source references and explicit payload limitations.
 */
static const xx_data_struct_field_desc sxmm_ym_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("check_string","char[8]",4,8,SX_SIGNATURE),
    SX_FIELD("frame_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("attributes","uint32",16,4,SX_FLAGS),
    SX_FIELD("digidrum_count","uint16",20,2,SX_COUNT_PROP),
    SX_FIELD("master_clock_hz","uint32",22,4,SX_NONE),
    SX_FIELD("frame_rate_hz","uint16",26,2,SX_NONE),
    SX_FIELD("loop_frame","uint32",28,4,SX_NONE),
    SX_FIELD("extra_data_size","uint16",32,2,SX_SIZE),
};
static const sx_layout sxmm_ym_header = {UINT32_C(0x600B0001),"ym_header",sxmm_ym_header_fields,SX_COUNT(sxmm_ym_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ym_digidrum_fields[] = {
    SX_FIELD("data_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmm_ym_digidrum = {UINT32_C(0x600B0002),"ym_digidrum",sxmm_ym_digidrum_fields,SX_COUNT(sxmm_ym_digidrum_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_hes_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("first_track","uint8",5,1,SX_NONE),
    SX_FIELD("init_address","uint16",6,2,SX_ADDRESS),
    SX_FIELD("mpr[0]","uint8",8,1,SX_NONE),
    SX_FIELD("mpr[1]","uint8",9,1,SX_NONE),
    SX_FIELD("mpr[2]","uint8",10,1,SX_NONE),
    SX_FIELD("mpr[3]","uint8",11,1,SX_NONE),
    SX_FIELD("mpr[4]","uint8",12,1,SX_NONE),
    SX_FIELD("mpr[5]","uint8",13,1,SX_NONE),
    SX_FIELD("mpr[6]","uint8",14,1,SX_NONE),
    SX_FIELD("mpr[7]","uint8",15,1,SX_NONE),
};
static const sx_layout sxmm_hes_header = {UINT32_C(0x600B0003),"hes_header",sxmm_hes_header_fields,SX_COUNT(sxmm_hes_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_hes_data_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("load_address","uint32",8,4,SX_ADDRESS),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxmm_hes_data_header = {UINT32_C(0x600B0004),"hes_data_header",sxmm_hes_data_header_fields,SX_COUNT(sxmm_hes_data_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_psid_header_v1_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("data_offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("load_address","uint16",8,2,SX_ADDRESS),
    SX_FIELD("init_address","uint16",10,2,SX_ADDRESS),
    SX_FIELD("play_address","uint16",12,2,SX_ADDRESS),
    SX_FIELD("song_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("start_song","uint16",16,2,SX_NONE),
    SX_FIELD("speed","uint32",18,4,SX_FLAGS),
    SX_FIELD("name","char[32]",22,32,SX_STRING),
    SX_FIELD("author","char[32]",54,32,SX_STRING),
    SX_FIELD("released","char[32]",86,32,SX_STRING),
};
static const sx_layout sxmm_psid_header_v1 = {UINT32_C(0x600B0005),"psid_header_v1",sxmm_psid_header_v1_fields,SX_COUNT(sxmm_psid_header_v1_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_psid_header_v2_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("data_offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("load_address","uint16",8,2,SX_ADDRESS),
    SX_FIELD("init_address","uint16",10,2,SX_ADDRESS),
    SX_FIELD("play_address","uint16",12,2,SX_ADDRESS),
    SX_FIELD("song_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("start_song","uint16",16,2,SX_NONE),
    SX_FIELD("speed","uint32",18,4,SX_FLAGS),
    SX_FIELD("name","char[32]",22,32,SX_STRING),
    SX_FIELD("author","char[32]",54,32,SX_STRING),
    SX_FIELD("released","char[32]",86,32,SX_STRING),
    SX_FIELD("flags","uint16",118,2,SX_FLAGS),
    SX_FIELD("start_page","uint8",120,1,SX_NONE),
    SX_FIELD("page_length","uint8",121,1,SX_NONE),
    SX_FIELD("reserved_122","uint16",122,2,SX_RESERVED),
};
static const sx_layout sxmm_psid_header_v2 = {UINT32_C(0x600B0006),"psid_header_v2",sxmm_psid_header_v2_fields,SX_COUNT(sxmm_psid_header_v2_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_psid_load_address_fields[] = {
    SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
};
static const sx_layout sxmm_psid_load_address = {UINT32_C(0x600B0007),"psid_load_address",sxmm_psid_load_address_fields,SX_COUNT(sxmm_psid_load_address_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_nsf_header_fields[] = {
    SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",5,1,SX_NONE),
    SX_FIELD("song_count","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("start_song","uint8",7,1,SX_NONE),
    SX_FIELD("load_address","uint16",8,2,SX_ADDRESS),
    SX_FIELD("init_address","uint16",10,2,SX_ADDRESS),
    SX_FIELD("play_address","uint16",12,2,SX_ADDRESS),
    SX_FIELD("name","char[32]",14,32,SX_STRING),
    SX_FIELD("artist","char[32]",46,32,SX_STRING),
    SX_FIELD("copyright","char[32]",78,32,SX_STRING),
    SX_FIELD("ntsc_speed_us","uint16",110,2,SX_NONE),
    SX_FIELD("bank[0]","uint8",112,1,SX_NONE),
    SX_FIELD("bank[1]","uint8",113,1,SX_NONE),
    SX_FIELD("bank[2]","uint8",114,1,SX_NONE),
    SX_FIELD("bank[3]","uint8",115,1,SX_NONE),
    SX_FIELD("bank[4]","uint8",116,1,SX_NONE),
    SX_FIELD("bank[5]","uint8",117,1,SX_NONE),
    SX_FIELD("bank[6]","uint8",118,1,SX_NONE),
    SX_FIELD("bank[7]","uint8",119,1,SX_NONE),
    SX_FIELD("pal_speed_us","uint16",120,2,SX_NONE),
    SX_FIELD("region_flags","uint8",122,1,SX_FLAGS),
    SX_FIELD("expansion_audio","uint8",123,1,SX_FLAGS),
    SX_FIELD("reserved","uint8[4]",124,4,SX_RESERVED),
};
static const sx_layout sxmm_nsf_header = {UINT32_C(0x600B0008),"nsf_header",sxmm_nsf_header_fields,SX_COUNT(sxmm_nsf_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_gbs_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("version","uint8",3,1,SX_NONE),
    SX_FIELD("song_count","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("first_song","uint8",5,1,SX_NONE),
    SX_FIELD("load_address","uint16",6,2,SX_ADDRESS),
    SX_FIELD("init_address","uint16",8,2,SX_ADDRESS),
    SX_FIELD("play_address","uint16",10,2,SX_ADDRESS),
    SX_FIELD("stack_pointer","uint16",12,2,SX_ADDRESS),
    SX_FIELD("timer_modulo","uint8",14,1,SX_NONE),
    SX_FIELD("timer_control","uint8",15,1,SX_NONE),
    SX_FIELD("title","char[32]",16,32,SX_STRING),
    SX_FIELD("author","char[32]",48,32,SX_STRING),
    SX_FIELD("copyright","char[32]",80,32,SX_STRING),
};
static const sx_layout sxmm_gbs_header = {UINT32_C(0x600B0009),"gbs_header",sxmm_gbs_header_fields,SX_COUNT(sxmm_gbs_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_sgc_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("region","uint8",5,1,SX_NONE),
    SX_FIELD("reserved_6","uint16",6,2,SX_RESERVED),
    SX_FIELD("load_address","uint16",8,2,SX_ADDRESS),
    SX_FIELD("init_address","uint16",10,2,SX_ADDRESS),
    SX_FIELD("play_address","uint16",12,2,SX_ADDRESS),
    SX_FIELD("stack_pointer","uint16",14,2,SX_ADDRESS),
    SX_FIELD("reserved_16","uint8[2]",16,2,SX_RESERVED),
    SX_FIELD("rst_address[0]","uint16",18,2,SX_ADDRESS),
    SX_FIELD("rst_address[1]","uint16",20,2,SX_ADDRESS),
    SX_FIELD("rst_address[2]","uint16",22,2,SX_ADDRESS),
    SX_FIELD("rst_address[3]","uint16",24,2,SX_ADDRESS),
    SX_FIELD("rst_address[4]","uint16",26,2,SX_ADDRESS),
    SX_FIELD("rst_address[5]","uint16",28,2,SX_ADDRESS),
    SX_FIELD("rst_address[6]","uint16",30,2,SX_ADDRESS),
    SX_FIELD("mapper[0]","uint8",32,1,SX_NONE),
    SX_FIELD("mapper[1]","uint8",33,1,SX_NONE),
    SX_FIELD("mapper[2]","uint8",34,1,SX_NONE),
    SX_FIELD("mapper[3]","uint8",35,1,SX_NONE),
    SX_FIELD("first_song","uint8",36,1,SX_NONE),
    SX_FIELD("song_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("first_effect","uint8",38,1,SX_NONE),
    SX_FIELD("last_effect","uint8",39,1,SX_NONE),
    SX_FIELD("system","uint8",40,1,SX_NONE),
    SX_FIELD("reserved_41","uint8[23]",41,23,SX_RESERVED),
    SX_FIELD("title","char[32]",64,32,SX_STRING),
    SX_FIELD("author","char[32]",96,32,SX_STRING),
    SX_FIELD("copyright","char[32]",128,32,SX_STRING),
};
static const sx_layout sxmm_sgc_header = {UINT32_C(0x600B000A),"sgc_header",sxmm_sgc_header_fields,SX_COUNT(sxmm_sgc_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_s98_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("timer_numerator","uint32",4,4,SX_NONE),
    SX_FIELD("timer_denominator","uint32",8,4,SX_NONE),
    SX_FIELD("compression","uint32",12,4,SX_NONE),
    SX_FIELD("tag_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("loop_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("device_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_s98_header = {UINT32_C(0x600B000B),"s98_header",sxmm_s98_header_fields,SX_COUNT(sxmm_s98_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_s98_device_fields[] = {
    SX_FIELD("device_type","uint32",0,4,SX_NONE),
    SX_FIELD("clock_hz","uint32",4,4,SX_NONE),
    SX_FIELD("pan","uint32",8,4,SX_NONE),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxmm_s98_device = {UINT32_C(0x600B000C),"s98_device",sxmm_s98_device_fields,SX_COUNT(sxmm_s98_device_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vst3_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("class_id","char[32]",8,32,SX_ID),
    SX_FIELD("list_offset","uint64",40,8,SX_OFFSET),
};
static const sx_layout sxmm_vst3_header = {UINT32_C(0x600B000D),"vst3_header",sxmm_vst3_header_fields,SX_COUNT(sxmm_vst3_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vst3_list_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_vst3_list = {UINT32_C(0x600B000E),"vst3_list",sxmm_vst3_list_fields,SX_COUNT(sxmm_vst3_list_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vst3_entry_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("offset","uint64",4,8,SX_OFFSET),
    SX_FIELD("size","uint64",12,8,SX_SIZE),
};
static const sx_layout sxmm_vst3_entry = {UINT32_C(0x600B000F),"vst3_entry",sxmm_vst3_entry_fields,SX_COUNT(sxmm_vst3_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vst2_program_fields[] = {
    SX_FIELD("chunk_magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_size","int32",4,4,SX_SIZE),
    SX_FIELD("fx_magic","char[4]",8,4,SX_ID),
    SX_FIELD("version","int32",12,4,SX_NONE),
    SX_FIELD("fx_id","int32",16,4,SX_NONE),
    SX_FIELD("fx_version","int32",20,4,SX_NONE),
    SX_FIELD("parameter_count","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("program_name","char[28]",28,28,SX_STRING),
};
static const sx_layout sxmm_vst2_program = {UINT32_C(0x600B0010),"vst2_program",sxmm_vst2_program_fields,SX_COUNT(sxmm_vst2_program_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_vst2_bank_v1_fields[] = {
    SX_FIELD("chunk_magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_size","int32",4,4,SX_SIZE),
    SX_FIELD("fx_magic","char[4]",8,4,SX_ID),
    SX_FIELD("version","int32",12,4,SX_NONE),
    SX_FIELD("fx_id","int32",16,4,SX_NONE),
    SX_FIELD("fx_version","int32",20,4,SX_NONE),
    SX_FIELD("program_count","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("future","uint8[128]",28,128,SX_RESERVED),
};
static const sx_layout sxmm_vst2_bank_v1 = {UINT32_C(0x600B0011),"vst2_bank_v1",sxmm_vst2_bank_v1_fields,SX_COUNT(sxmm_vst2_bank_v1_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_vst2_bank_v2_fields[] = {
    SX_FIELD("chunk_magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_size","int32",4,4,SX_SIZE),
    SX_FIELD("fx_magic","char[4]",8,4,SX_ID),
    SX_FIELD("version","int32",12,4,SX_NONE),
    SX_FIELD("fx_id","int32",16,4,SX_NONE),
    SX_FIELD("fx_version","int32",20,4,SX_NONE),
    SX_FIELD("program_count","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("current_program","int32",28,4,SX_NONE),
    SX_FIELD("future","uint8[124]",32,124,SX_RESERVED),
};
static const sx_layout sxmm_vst2_bank_v2 = {UINT32_C(0x600B0012),"vst2_bank_v2",sxmm_vst2_bank_v2_fields,SX_COUNT(sxmm_vst2_bank_v2_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_vst2_parameter_fields[] = {
    SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxmm_vst2_parameter = {UINT32_C(0x600B0013),"vst2_parameter",sxmm_vst2_parameter_fields,SX_COUNT(sxmm_vst2_parameter_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_vst2_chunk_fields[] = {
    SX_FIELD("chunk_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxmm_vst2_chunk = {UINT32_C(0x600B0014),"vst2_chunk",sxmm_vst2_chunk_fields,SX_COUNT(sxmm_vst2_chunk_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_dro_header_v2_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",8,2,SX_NONE),
    SX_FIELD("minor_version","uint16",10,2,SX_NONE),
    SX_FIELD("pair_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("duration_ms","uint32",16,4,SX_NONE),
    SX_FIELD("hardware","uint8",20,1,SX_NONE),
    SX_FIELD("format","uint8",21,1,SX_NONE),
    SX_FIELD("compression","uint8",22,1,SX_NONE),
    SX_FIELD("short_delay_code","uint8",23,1,SX_NONE),
    SX_FIELD("long_delay_code","uint8",24,1,SX_NONE),
    SX_FIELD("map_count","uint8",25,1,SX_COUNT_PROP),
};
static const sx_layout sxmm_dro_header_v2 = {UINT32_C(0x600B0015),"dro_header_v2",sxmm_dro_header_v2_fields,SX_COUNT(sxmm_dro_header_v2_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_dro_register_map_fields[] = {
    SX_FIELD("register","uint8",0,1,SX_ID),
};
static const sx_layout sxmm_dro_register_map = {UINT32_C(0x600B0016),"dro_register_map",sxmm_dro_register_map_fields,SX_COUNT(sxmm_dro_register_map_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_dro_pair_fields[] = {
    SX_FIELD("code","uint8",0,1,SX_NONE),
    SX_FIELD("value","uint8",1,1,SX_NONE),
};
static const sx_layout sxmm_dro_pair = {UINT32_C(0x600B0017),"dro_pair",sxmm_dro_pair_fields,SX_COUNT(sxmm_dro_pair_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_cmf_header_v1_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("instrument_offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("music_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("ticks_per_quarter","uint16",10,2,SX_NONE),
    SX_FIELD("ticks_per_second","uint16",12,2,SX_NONE),
    SX_FIELD("title_offset","uint16",14,2,SX_OFFSET),
    SX_FIELD("composer_offset","uint16",16,2,SX_OFFSET),
    SX_FIELD("remarks_offset","uint16",18,2,SX_OFFSET),
    SX_FIELD("channel_used[0]","uint8",20,1,SX_NONE),
    SX_FIELD("channel_used[1]","uint8",21,1,SX_NONE),
    SX_FIELD("channel_used[2]","uint8",22,1,SX_NONE),
    SX_FIELD("channel_used[3]","uint8",23,1,SX_NONE),
    SX_FIELD("channel_used[4]","uint8",24,1,SX_NONE),
    SX_FIELD("channel_used[5]","uint8",25,1,SX_NONE),
    SX_FIELD("channel_used[6]","uint8",26,1,SX_NONE),
    SX_FIELD("channel_used[7]","uint8",27,1,SX_NONE),
    SX_FIELD("channel_used[8]","uint8",28,1,SX_NONE),
    SX_FIELD("channel_used[9]","uint8",29,1,SX_NONE),
    SX_FIELD("channel_used[10]","uint8",30,1,SX_NONE),
    SX_FIELD("channel_used[11]","uint8",31,1,SX_NONE),
    SX_FIELD("channel_used[12]","uint8",32,1,SX_NONE),
    SX_FIELD("channel_used[13]","uint8",33,1,SX_NONE),
    SX_FIELD("channel_used[14]","uint8",34,1,SX_NONE),
    SX_FIELD("channel_used[15]","uint8",35,1,SX_NONE),
    SX_FIELD("instrument_count","uint8",36,1,SX_COUNT_PROP),
};
static const sx_layout sxmm_cmf_header_v1 = {UINT32_C(0x600B0018),"cmf_header_v1",sxmm_cmf_header_v1_fields,SX_COUNT(sxmm_cmf_header_v1_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_cmf_header_v11_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("instrument_offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("music_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("ticks_per_quarter","uint16",10,2,SX_NONE),
    SX_FIELD("ticks_per_second","uint16",12,2,SX_NONE),
    SX_FIELD("title_offset","uint16",14,2,SX_OFFSET),
    SX_FIELD("composer_offset","uint16",16,2,SX_OFFSET),
    SX_FIELD("remarks_offset","uint16",18,2,SX_OFFSET),
    SX_FIELD("channel_used[0]","uint8",20,1,SX_NONE),
    SX_FIELD("channel_used[1]","uint8",21,1,SX_NONE),
    SX_FIELD("channel_used[2]","uint8",22,1,SX_NONE),
    SX_FIELD("channel_used[3]","uint8",23,1,SX_NONE),
    SX_FIELD("channel_used[4]","uint8",24,1,SX_NONE),
    SX_FIELD("channel_used[5]","uint8",25,1,SX_NONE),
    SX_FIELD("channel_used[6]","uint8",26,1,SX_NONE),
    SX_FIELD("channel_used[7]","uint8",27,1,SX_NONE),
    SX_FIELD("channel_used[8]","uint8",28,1,SX_NONE),
    SX_FIELD("channel_used[9]","uint8",29,1,SX_NONE),
    SX_FIELD("channel_used[10]","uint8",30,1,SX_NONE),
    SX_FIELD("channel_used[11]","uint8",31,1,SX_NONE),
    SX_FIELD("channel_used[12]","uint8",32,1,SX_NONE),
    SX_FIELD("channel_used[13]","uint8",33,1,SX_NONE),
    SX_FIELD("channel_used[14]","uint8",34,1,SX_NONE),
    SX_FIELD("channel_used[15]","uint8",35,1,SX_NONE),
    SX_FIELD("instrument_count","uint16",36,2,SX_COUNT_PROP),
    SX_FIELD("basic_tempo","uint16",38,2,SX_NONE),
};
static const sx_layout sxmm_cmf_header_v11 = {UINT32_C(0x600B0019),"cmf_header_v11",sxmm_cmf_header_v11_fields,SX_COUNT(sxmm_cmf_header_v11_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_cmf_instrument_fields[] = {
    SX_FIELD("mod_characteristic","uint8",0,1,SX_NONE),
    SX_FIELD("car_characteristic","uint8",1,1,SX_NONE),
    SX_FIELD("mod_level","uint8",2,1,SX_NONE),
    SX_FIELD("car_level","uint8",3,1,SX_NONE),
    SX_FIELD("mod_attack_decay","uint8",4,1,SX_NONE),
    SX_FIELD("car_attack_decay","uint8",5,1,SX_NONE),
    SX_FIELD("mod_sustain_release","uint8",6,1,SX_NONE),
    SX_FIELD("car_sustain_release","uint8",7,1,SX_NONE),
    SX_FIELD("mod_waveform","uint8",8,1,SX_NONE),
    SX_FIELD("car_waveform","uint8",9,1,SX_NONE),
    SX_FIELD("feedback_connection","uint8",10,1,SX_NONE),
    SX_FIELD("reserved","uint8[5]",11,5,SX_RESERVED),
};
static const sx_layout sxmm_cmf_instrument = {UINT32_C(0x600B001A),"cmf_instrument",sxmm_cmf_instrument_fields,SX_COUNT(sxmm_cmf_instrument_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_spc_header_fields[] = {
    SX_FIELD("signature","char[33]",0,33,SX_SIGNATURE),
    SX_FIELD("terminator","uint8[2]",33,2,SX_SIGNATURE),
    SX_FIELD("id666_flag","uint8",35,1,SX_NONE),
    SX_FIELD("version","uint8",36,1,SX_NONE),
    SX_FIELD("pc","uint16",37,2,SX_ADDRESS),
    SX_FIELD("a","uint8",39,1,SX_NONE),
    SX_FIELD("x","uint8",40,1,SX_NONE),
    SX_FIELD("y","uint8",41,1,SX_NONE),
    SX_FIELD("psw","uint8",42,1,SX_NONE),
    SX_FIELD("sp","uint8",43,1,SX_NONE),
    SX_FIELD("reserved","uint8[2]",44,2,SX_RESERVED),
};
static const sx_layout sxmm_spc_header = {UINT32_C(0x600B001B),"spc_header",sxmm_spc_header_fields,SX_COUNT(sxmm_spc_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_spc_id666_common_fields[] = {
    SX_FIELD("song_title","char[32]",0,32,SX_STRING),
    SX_FIELD("game_title","char[32]",32,32,SX_STRING),
    SX_FIELD("dumper","char[16]",64,16,SX_STRING),
    SX_FIELD("comments","char[32]",80,32,SX_STRING),
};
static const sx_layout sxmm_spc_id666_common = {UINT32_C(0x600B001C),"spc_id666_common",sxmm_spc_id666_common_fields,SX_COUNT(sxmm_spc_id666_common_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_spc_xid6_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmm_spc_xid6_header = {UINT32_C(0x600B001D),"spc_xid6_header",sxmm_spc_xid6_header_fields,SX_COUNT(sxmm_spc_xid6_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_spc_xid6_item_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("type","uint8",1,1,SX_ID),
    SX_FIELD("length_or_value","uint16",2,2,SX_NONE),
};
static const sx_layout sxmm_spc_xid6_item = {UINT32_C(0x600B001E),"spc_xid6_item",sxmm_spc_xid6_item_fields,SX_COUNT(sxmm_spc_xid6_item_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_glb_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("length","uint32",8,4,SX_SIZE),
};
static const sx_layout sxmm_glb_header = {UINT32_C(0x600B001F),"glb_header",sxmm_glb_header_fields,SX_COUNT(sxmm_glb_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_glb_chunk_fields[] = {
    SX_FIELD("chunk_length","uint32",0,4,SX_SIZE),
    SX_FIELD("chunk_type","char[4]",4,4,SX_ID),
};
static const sx_layout sxmm_glb_chunk = {UINT32_C(0x600B0020),"glb_chunk",sxmm_glb_chunk_fields,SX_COUNT(sxmm_glb_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vox_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
};
static const sx_layout sxmm_vox_header = {UINT32_C(0x600B0021),"vox_header",sxmm_vox_header_fields,SX_COUNT(sxmm_vox_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vox_chunk_fields[] = {
    SX_FIELD("id","char[4]",0,4,SX_ID),
    SX_FIELD("content_size","uint32",4,4,SX_SIZE),
    SX_FIELD("children_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxmm_vox_chunk = {UINT32_C(0x600B0022),"vox_chunk",sxmm_vox_chunk_fields,SX_COUNT(sxmm_vox_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vox_pack_fields[] = {
    SX_FIELD("model_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_vox_pack = {UINT32_C(0x600B0023),"vox_pack",sxmm_vox_pack_fields,SX_COUNT(sxmm_vox_pack_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vox_size_fields[] = {
    SX_FIELD("size_x","int32",0,4,SX_NONE),
    SX_FIELD("size_y","int32",4,4,SX_NONE),
    SX_FIELD("size_z","int32",8,4,SX_NONE),
};
static const sx_layout sxmm_vox_size = {UINT32_C(0x600B0024),"vox_size",sxmm_vox_size_fields,SX_COUNT(sxmm_vox_size_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vox_xyzi_fields[] = {
    SX_FIELD("voxel_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_vox_xyzi = {UINT32_C(0x600B0025),"vox_xyzi",sxmm_vox_xyzi_fields,SX_COUNT(sxmm_vox_xyzi_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vox_voxel_fields[] = {
    SX_FIELD("x","uint8",0,1,SX_NONE),
    SX_FIELD("y","uint8",1,1,SX_NONE),
    SX_FIELD("z","uint8",2,1,SX_NONE),
    SX_FIELD("color_index","uint8",3,1,SX_NONE),
};
static const sx_layout sxmm_vox_voxel = {UINT32_C(0x600B0026),"vox_voxel",sxmm_vox_voxel_fields,SX_COUNT(sxmm_vox_voxel_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_vox_rgba_fields[] = {
    SX_FIELD("red","uint8",0,1,SX_NONE),
    SX_FIELD("green","uint8",1,1,SX_NONE),
    SX_FIELD("blue","uint8",2,1,SX_NONE),
    SX_FIELD("alpha","uint8",3,1,SX_NONE),
};
static const sx_layout sxmm_vox_rgba = {UINT32_C(0x600B0027),"vox_rgba",sxmm_vox_rgba_fields,SX_COUNT(sxmm_vox_rgba_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_ase_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_NONE),
    SX_FIELD("minor_version","uint16",6,2,SX_NONE),
    SX_FIELD("block_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_ase_header = {UINT32_C(0x600B0028),"ase_header",sxmm_ase_header_fields,SX_COUNT(sxmm_ase_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ase_block_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("data_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxmm_ase_block = {UINT32_C(0x600B0029),"ase_block",sxmm_ase_block_fields,SX_COUNT(sxmm_ase_block_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ase_name_fields[] = {
    SX_FIELD("name_units","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmm_ase_name = {UINT32_C(0x600B002A),"ase_name",sxmm_ase_name_fields,SX_COUNT(sxmm_ase_name_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_utf16_unit_fields[] = {
    SX_FIELD("code_unit","uint16",0,2,SX_NONE),
};
static const sx_layout sxmm_utf16_unit = {UINT32_C(0x600B002B),"utf16_unit",sxmm_utf16_unit_fields,SX_COUNT(sxmm_utf16_unit_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ase_rgb_fields[] = {
    SX_FIELD("color_model","char[4]",0,4,SX_ID),
    SX_FIELD("red","float32",4,4,SX_NONE),
    SX_FIELD("green","float32",8,4,SX_NONE),
    SX_FIELD("blue","float32",12,4,SX_NONE),
    SX_FIELD("color_type","uint16",16,2,SX_ID),
};
static const sx_layout sxmm_ase_rgb = {UINT32_C(0x600B002C),"ase_rgb",sxmm_ase_rgb_fields,SX_COUNT(sxmm_ase_rgb_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ase_lab_fields[] = {
    SX_FIELD("color_model","char[4]",0,4,SX_ID),
    SX_FIELD("lightness","float32",4,4,SX_NONE),
    SX_FIELD("a","float32",8,4,SX_NONE),
    SX_FIELD("b","float32",12,4,SX_NONE),
    SX_FIELD("color_type","uint16",16,2,SX_ID),
};
static const sx_layout sxmm_ase_lab = {UINT32_C(0x600B002D),"ase_lab",sxmm_ase_lab_fields,SX_COUNT(sxmm_ase_lab_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ase_cmyk_fields[] = {
    SX_FIELD("color_model","char[4]",0,4,SX_ID),
    SX_FIELD("cyan","float32",4,4,SX_NONE),
    SX_FIELD("magenta","float32",8,4,SX_NONE),
    SX_FIELD("yellow","float32",12,4,SX_NONE),
    SX_FIELD("black","float32",16,4,SX_NONE),
    SX_FIELD("color_type","uint16",20,2,SX_ID),
};
static const sx_layout sxmm_ase_cmyk = {UINT32_C(0x600B002E),"ase_cmyk",sxmm_ase_cmyk_fields,SX_COUNT(sxmm_ase_cmyk_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ase_gray_fields[] = {
    SX_FIELD("color_model","char[4]",0,4,SX_ID),
    SX_FIELD("gray","float32",4,4,SX_NONE),
    SX_FIELD("color_type","uint16",8,2,SX_ID),
};
static const sx_layout sxmm_ase_gray = {UINT32_C(0x600B002F),"ase_gray",sxmm_ase_gray_fields,SX_COUNT(sxmm_ase_gray_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_aco_header_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_NONE),
    SX_FIELD("color_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxmm_aco_header = {UINT32_C(0x600B0030),"aco_header",sxmm_aco_header_fields,SX_COUNT(sxmm_aco_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_aco_color_fields[] = {
    SX_FIELD("color_space","uint16",0,2,SX_ID),
    SX_FIELD("component_1","uint16",2,2,SX_NONE),
    SX_FIELD("component_2","uint16",4,2,SX_NONE),
    SX_FIELD("component_3","uint16",6,2,SX_NONE),
    SX_FIELD("component_4","uint16",8,2,SX_NONE),
};
static const sx_layout sxmm_aco_color = {UINT32_C(0x600B0031),"aco_color",sxmm_aco_color_fields,SX_COUNT(sxmm_aco_color_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_aco_lab_color_fields[] = {
    SX_FIELD("color_space","uint16",0,2,SX_ID),
    SX_FIELD("lightness","uint16",2,2,SX_NONE),
    SX_FIELD("a","int16",4,2,SX_NONE),
    SX_FIELD("b","int16",6,2,SX_NONE),
    SX_FIELD("unused","uint16",8,2,SX_NONE),
};
static const sx_layout sxmm_aco_lab_color = {UINT32_C(0x600B0032),"aco_lab_color",sxmm_aco_lab_color_fields,SX_COUNT(sxmm_aco_lab_color_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_aco_name_fields[] = {
    SX_FIELD("name_units","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_aco_name = {UINT32_C(0x600B0033),"aco_name",sxmm_aco_name_fields,SX_COUNT(sxmm_aco_name_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_acv_header_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_NONE),
    SX_FIELD("curve_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxmm_acv_header = {UINT32_C(0x600B0034),"acv_header",sxmm_acv_header_fields,SX_COUNT(sxmm_acv_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_acv_curve_fields[] = {
    SX_FIELD("point_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmm_acv_curve = {UINT32_C(0x600B0035),"acv_curve",sxmm_acv_curve_fields,SX_COUNT(sxmm_acv_curve_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_acv_point_fields[] = {
    SX_FIELD("output","uint16",0,2,SX_NONE),
    SX_FIELD("input","uint16",2,2,SX_NONE),
};
static const sx_layout sxmm_acv_point = {UINT32_C(0x600B0036),"acv_point",sxmm_acv_point_fields,SX_COUNT(sxmm_acv_point_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_act_color_fields[] = {
    SX_FIELD("red","uint8",0,1,SX_NONE),
    SX_FIELD("green","uint8",1,1,SX_NONE),
    SX_FIELD("blue","uint8",2,1,SX_NONE),
};
static const sx_layout sxmm_act_color = {UINT32_C(0x600B0037),"act_color",sxmm_act_color_fields,SX_COUNT(sxmm_act_color_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_act_footer_fields[] = {
    SX_FIELD("color_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("transparent_index","uint16",2,2,SX_NONE),
};
static const sx_layout sxmm_act_footer = {UINT32_C(0x600B0038),"act_footer",sxmm_act_footer_fields,SX_COUNT(sxmm_act_footer_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_pvr2_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("pixel_format","uint8",8,1,SX_NONE),
    SX_FIELD("data_format","uint8",9,1,SX_NONE),
    SX_FIELD("reserved","uint16",10,2,SX_RESERVED),
    SX_FIELD("width","uint16",12,2,SX_NONE),
    SX_FIELD("height","uint16",14,2,SX_NONE),
};
static const sx_layout sxmm_pvr2_header = {UINT32_C(0x600B0039),"pvr2_header",sxmm_pvr2_header_fields,SX_COUNT(sxmm_pvr2_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_tim_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxmm_tim_header = {UINT32_C(0x600B003A),"tim_header",sxmm_tim_header_fields,SX_COUNT(sxmm_tim_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_tim_block_fields[] = {
    SX_FIELD("block_size","uint32",0,4,SX_SIZE),
    SX_FIELD("vram_x","uint16",4,2,SX_NONE),
    SX_FIELD("vram_y","uint16",6,2,SX_NONE),
    SX_FIELD("width_words","uint16",8,2,SX_NONE),
    SX_FIELD("height","uint16",10,2,SX_NONE),
};
static const sx_layout sxmm_tim_block = {UINT32_C(0x600B003B),"tim_block",sxmm_tim_block_fields,SX_COUNT(sxmm_tim_block_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_tim2_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("format","uint8",5,1,SX_NONE),
    SX_FIELD("picture_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("reserved","uint8[8]",8,8,SX_RESERVED),
};
static const sx_layout sxmm_tim2_header = {UINT32_C(0x600B003C),"tim2_header",sxmm_tim2_header_fields,SX_COUNT(sxmm_tim2_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_tim2_picture_fields[] = {
    SX_FIELD("total_size","uint32",0,4,SX_SIZE),
    SX_FIELD("clut_size","uint32",4,4,SX_SIZE),
    SX_FIELD("image_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size","uint16",12,2,SX_SIZE),
    SX_FIELD("clut_colors","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("picture_format","uint8",16,1,SX_NONE),
    SX_FIELD("mipmap_count","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("clut_type","uint8",18,1,SX_NONE),
    SX_FIELD("image_type","uint8",19,1,SX_NONE),
    SX_FIELD("width","uint16",20,2,SX_NONE),
    SX_FIELD("height","uint16",22,2,SX_NONE),
    SX_FIELD("gs_tex0","uint64",24,8,SX_FLAGS),
    SX_FIELD("gs_tex1","uint64",32,8,SX_FLAGS),
    SX_FIELD("gs_regs","uint32",40,4,SX_FLAGS),
    SX_FIELD("gs_tex_clut","uint32",44,4,SX_FLAGS),
};
static const sx_layout sxmm_tim2_picture = {UINT32_C(0x600B003D),"tim2_picture",sxmm_tim2_picture_fields,SX_COUNT(sxmm_tim2_picture_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_tpl_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("table_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxmm_tpl_header = {UINT32_C(0x600B003E),"tpl_header",sxmm_tpl_header_fields,SX_COUNT(sxmm_tpl_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_tpl_entry_fields[] = {
    SX_FIELD("image_header_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("palette_header_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxmm_tpl_entry = {UINT32_C(0x600B003F),"tpl_entry",sxmm_tpl_entry_fields,SX_COUNT(sxmm_tpl_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_tpl_image_fields[] = {
    SX_FIELD("height","uint16",0,2,SX_NONE),
    SX_FIELD("width","uint16",2,2,SX_NONE),
    SX_FIELD("format","uint32",4,4,SX_ID),
    SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("wrap_s","uint32",12,4,SX_NONE),
    SX_FIELD("wrap_t","uint32",16,4,SX_NONE),
    SX_FIELD("min_filter","uint32",20,4,SX_NONE),
    SX_FIELD("mag_filter","uint32",24,4,SX_NONE),
    SX_FIELD("lod_bias","float32",28,4,SX_NONE),
    SX_FIELD("edge_lod","uint8",32,1,SX_NONE),
    SX_FIELD("min_lod","uint8",33,1,SX_NONE),
    SX_FIELD("max_lod","uint8",34,1,SX_NONE),
    SX_FIELD("unpacked","uint8",35,1,SX_NONE),
};
static const sx_layout sxmm_tpl_image = {UINT32_C(0x600B0040),"tpl_image",sxmm_tpl_image_fields,SX_COUNT(sxmm_tpl_image_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_tpl_palette_fields[] = {
    SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("unpacked","uint8",2,1,SX_NONE),
    SX_FIELD("padding","uint8",3,1,SX_RESERVED),
    SX_FIELD("format","uint32",4,4,SX_ID),
    SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxmm_tpl_palette = {UINT32_C(0x600B0041),"tpl_palette",sxmm_tpl_palette_fields,SX_COUNT(sxmm_tpl_palette_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_xcursor_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("version","uint32",8,4,SX_NONE),
    SX_FIELD("toc_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_xcursor_header = {UINT32_C(0x600B0042),"xcursor_header",sxmm_xcursor_header_fields,SX_COUNT(sxmm_xcursor_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_xcursor_toc_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("subtype","uint32",4,4,SX_NONE),
    SX_FIELD("position","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxmm_xcursor_toc = {UINT32_C(0x600B0043),"xcursor_toc",sxmm_xcursor_toc_fields,SX_COUNT(sxmm_xcursor_toc_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_xcursor_image_fields[] = {
    SX_FIELD("header_size","uint32",0,4,SX_SIZE),
    SX_FIELD("type","uint32",4,4,SX_ID),
    SX_FIELD("subtype","uint32",8,4,SX_NONE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("width","uint32",16,4,SX_NONE),
    SX_FIELD("height","uint32",20,4,SX_NONE),
    SX_FIELD("xhot","uint32",24,4,SX_NONE),
    SX_FIELD("yhot","uint32",28,4,SX_NONE),
    SX_FIELD("delay_ms","uint32",32,4,SX_NONE),
};
static const sx_layout sxmm_xcursor_image = {UINT32_C(0x600B0044),"xcursor_image",sxmm_xcursor_image_fields,SX_COUNT(sxmm_xcursor_image_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_xcursor_comment_fields[] = {
    SX_FIELD("header_size","uint32",0,4,SX_SIZE),
    SX_FIELD("type","uint32",4,4,SX_ID),
    SX_FIELD("subtype","uint32",8,4,SX_NONE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
};
static const sx_layout sxmm_xcursor_comment = {UINT32_C(0x600B0045),"xcursor_comment",sxmm_xcursor_comment_fields,SX_COUNT(sxmm_xcursor_comment_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_mdd_header_fields[] = {
    SX_FIELD("frame_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("point_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_mdd_header = {UINT32_C(0x600B0046),"mdd_header",sxmm_mdd_header_fields,SX_COUNT(sxmm_mdd_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_mdd_time_fields[] = {
    SX_FIELD("seconds","float32",0,4,SX_NONE),
};
static const sx_layout sxmm_mdd_time = {UINT32_C(0x600B0047),"mdd_time",sxmm_mdd_time_fields,SX_COUNT(sxmm_mdd_time_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_mdd_point_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxmm_mdd_point = {UINT32_C(0x600B0048),"mdd_point",sxmm_mdd_point_fields,SX_COUNT(sxmm_mdd_point_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_pic_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","float32",4,4,SX_NONE),
    SX_FIELD("comment","char[80]",8,80,SX_STRING),
    SX_FIELD("identifier","char[4]",88,4,SX_SIGNATURE),
    SX_FIELD("width","uint16",92,2,SX_NONE),
    SX_FIELD("height","uint16",94,2,SX_NONE),
    SX_FIELD("pixel_aspect","float32",96,4,SX_NONE),
    SX_FIELD("fields","uint16",100,2,SX_NONE),
    SX_FIELD("padding","uint16",102,2,SX_NONE),
};
static const sx_layout sxmm_pic_header = {UINT32_C(0x600B0049),"pic_header",sxmm_pic_header_fields,SX_COUNT(sxmm_pic_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_pic_packet_fields[] = {
    SX_FIELD("chained","uint8",0,1,SX_NONE),
    SX_FIELD("bits_per_sample","uint8",1,1,SX_NONE),
    SX_FIELD("encoding","uint8",2,1,SX_NONE),
    SX_FIELD("channel_mask","uint8",3,1,SX_NONE),
};
static const sx_layout sxmm_pic_packet = {UINT32_C(0x600B004A),"pic_packet",sxmm_pic_packet_fields,SX_COUNT(sxmm_pic_packet_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_fsh_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("directory_id","char[4]",12,4,SX_ID),
};
static const sx_layout sxmm_fsh_header = {UINT32_C(0x600B004B),"fsh_header",sxmm_fsh_header_fields,SX_COUNT(sxmm_fsh_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_fsh_entry_fields[] = {
    SX_FIELD("name","char[4]",0,4,SX_STRING),
    SX_FIELD("offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxmm_fsh_entry = {UINT32_C(0x600B004C),"fsh_entry",sxmm_fsh_entry_fields,SX_COUNT(sxmm_fsh_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_fsh_bitmap_fields[] = {
    SX_FIELD("record_code","uint8",0,1,SX_ID),
    SX_FIELD("next_block_relative_offset","uint24",1,3,SX_OFFSET),
    SX_FIELD("width","uint16",4,2,SX_NONE),
    SX_FIELD("height","uint16",6,2,SX_NONE),
    SX_FIELD("misc_1","uint16",8,2,SX_NONE),
    SX_FIELD("misc_2","uint16",10,2,SX_NONE),
    SX_FIELD("misc_3","uint16",12,2,SX_NONE),
    SX_FIELD("misc_4","uint16",14,2,SX_NONE),
};
static const sx_layout sxmm_fsh_bitmap = {UINT32_C(0x600B004D),"fsh_bitmap",sxmm_fsh_bitmap_fields,SX_COUNT(sxmm_fsh_bitmap_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_header_le_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("sequence_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxmm_twobit_header_le = {UINT32_C(0x600B004E),"twobit_header_le",sxmm_twobit_header_le_fields,SX_COUNT(sxmm_twobit_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_header_be_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("sequence_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxmm_twobit_header_be = {UINT32_C(0x600B004F),"twobit_header_be",sxmm_twobit_header_be_fields,SX_COUNT(sxmm_twobit_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_twobit_name_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxmm_twobit_name = {UINT32_C(0x600B0050),"twobit_name",sxmm_twobit_name_fields,SX_COUNT(sxmm_twobit_name_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_index_offset_le_fields[] = {
    SX_FIELD("sequence_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmm_twobit_index_offset_le = {UINT32_C(0x600B0051),"twobit_index_offset_le",sxmm_twobit_index_offset_le_fields,SX_COUNT(sxmm_twobit_index_offset_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_index_offset_be_fields[] = {
    SX_FIELD("sequence_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmm_twobit_index_offset_be = {UINT32_C(0x600B0052),"twobit_index_offset_be",sxmm_twobit_index_offset_be_fields,SX_COUNT(sxmm_twobit_index_offset_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_twobit_sequence_le_fields[] = {
    SX_FIELD("dna_size","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_twobit_sequence_le = {UINT32_C(0x600B0053),"twobit_sequence_le",sxmm_twobit_sequence_le_fields,SX_COUNT(sxmm_twobit_sequence_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_sequence_be_fields[] = {
    SX_FIELD("dna_size","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_twobit_sequence_be = {UINT32_C(0x600B0054),"twobit_sequence_be",sxmm_twobit_sequence_be_fields,SX_COUNT(sxmm_twobit_sequence_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_twobit_run_count_le_fields[] = {
    SX_FIELD("block_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_twobit_run_count_le = {UINT32_C(0x600B0055),"twobit_run_count_le",sxmm_twobit_run_count_le_fields,SX_COUNT(sxmm_twobit_run_count_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_run_count_be_fields[] = {
    SX_FIELD("block_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_twobit_run_count_be = {UINT32_C(0x600B0056),"twobit_run_count_be",sxmm_twobit_run_count_be_fields,SX_COUNT(sxmm_twobit_run_count_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_twobit_run_start_le_fields[] = {
    SX_FIELD("base_index","uint32",0,4,SX_NONE),
};
static const sx_layout sxmm_twobit_run_start_le = {UINT32_C(0x600B0057),"twobit_run_start_le",sxmm_twobit_run_start_le_fields,SX_COUNT(sxmm_twobit_run_start_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_run_start_be_fields[] = {
    SX_FIELD("base_index","uint32",0,4,SX_NONE),
};
static const sx_layout sxmm_twobit_run_start_be = {UINT32_C(0x600B0058),"twobit_run_start_be",sxmm_twobit_run_start_be_fields,SX_COUNT(sxmm_twobit_run_start_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_twobit_run_size_le_fields[] = {
    SX_FIELD("base_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_twobit_run_size_le = {UINT32_C(0x600B0059),"twobit_run_size_le",sxmm_twobit_run_size_le_fields,SX_COUNT(sxmm_twobit_run_size_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_run_size_be_fields[] = {
    SX_FIELD("base_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_twobit_run_size_be = {UINT32_C(0x600B005A),"twobit_run_size_be",sxmm_twobit_run_size_be_fields,SX_COUNT(sxmm_twobit_run_size_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_twobit_reserved_le_fields[] = {
    SX_FIELD("reserved","uint32",0,4,SX_RESERVED),
};
static const sx_layout sxmm_twobit_reserved_le = {UINT32_C(0x600B005B),"twobit_reserved_le",sxmm_twobit_reserved_le_fields,SX_COUNT(sxmm_twobit_reserved_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_twobit_reserved_be_fields[] = {
    SX_FIELD("reserved","uint32",0,4,SX_RESERVED),
};
static const sx_layout sxmm_twobit_reserved_be = {UINT32_C(0x600B005C),"twobit_reserved_be",sxmm_twobit_reserved_be_fields,SX_COUNT(sxmm_twobit_reserved_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_gds_record_fields[] = {
    SX_FIELD("record_length","uint16",0,2,SX_SIZE),
    SX_FIELD("record_type","uint8",2,1,SX_ID),
    SX_FIELD("data_type","uint8",3,1,SX_ID),
};
static const sx_layout sxmm_gds_record = {UINT32_C(0x600B005D),"gds_record",sxmm_gds_record_fields,SX_COUNT(sxmm_gds_record_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_gds_int16_fields[] = {
    SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxmm_gds_int16 = {UINT32_C(0x600B005E),"gds_int16",sxmm_gds_int16_fields,SX_COUNT(sxmm_gds_int16_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_gds_int32_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxmm_gds_int32 = {UINT32_C(0x600B005F),"gds_int32",sxmm_gds_int32_fields,SX_COUNT(sxmm_gds_int32_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_gds_bit_array_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxmm_gds_bit_array = {UINT32_C(0x600B0060),"gds_bit_array",sxmm_gds_bit_array_fields,SX_COUNT(sxmm_gds_bit_array_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_gds_real64_fields[] = {
    SX_FIELD("base16_real","uint8[8]",0,8,SX_NONE),
};
static const sx_layout sxmm_gds_real64 = {UINT32_C(0x600B0061),"gds_real64",sxmm_gds_real64_fields,SX_COUNT(sxmm_gds_real64_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_gds_timestamp_fields[] = {
    SX_FIELD("year","int16",0,2,SX_NONE),
    SX_FIELD("month","int16",2,2,SX_NONE),
    SX_FIELD("day","int16",4,2,SX_NONE),
    SX_FIELD("hour","int16",6,2,SX_NONE),
    SX_FIELD("minute","int16",8,2,SX_NONE),
    SX_FIELD("second","int16",10,2,SX_NONE),
};
static const sx_layout sxmm_gds_timestamp = {UINT32_C(0x600B0062),"gds_timestamp",sxmm_gds_timestamp_fields,SX_COUNT(sxmm_gds_timestamp_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ser_header_fields[] = {
    SX_FIELD("file_id","char[14]",0,14,SX_SIGNATURE),
    SX_FIELD("lu_id","uint32",14,4,SX_NONE),
    SX_FIELD("color_id","uint32",18,4,SX_NONE),
    SX_FIELD("little_endian","uint32",22,4,SX_NONE),
    SX_FIELD("width","uint32",26,4,SX_NONE),
    SX_FIELD("height","uint32",30,4,SX_NONE),
    SX_FIELD("pixel_depth","uint32",34,4,SX_NONE),
    SX_FIELD("frame_count","uint32",38,4,SX_COUNT_PROP),
    SX_FIELD("observer","char[40]",42,40,SX_STRING),
    SX_FIELD("instrument","char[40]",82,40,SX_STRING),
    SX_FIELD("telescope","char[40]",122,40,SX_STRING),
    SX_FIELD("date_time","uint64",162,8,SX_TIME),
    SX_FIELD("date_time_utc","uint64",170,8,SX_TIME),
};
static const sx_layout sxmm_ser_header = {UINT32_C(0x600B0063),"ser_header",sxmm_ser_header_fields,SX_COUNT(sxmm_ser_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_ser_timestamp_fields[] = {
    SX_FIELD("utc_ticks","uint64",0,8,SX_TIME),
};
static const sx_layout sxmm_ser_timestamp = {UINT32_C(0x600B0064),"ser_timestamp",sxmm_ser_timestamp_fields,SX_COUNT(sxmm_ser_timestamp_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_mgh_header_fields[] = {
    SX_FIELD("version","int32",0,4,SX_NONE),
    SX_FIELD("width","int32",4,4,SX_NONE),
    SX_FIELD("height","int32",8,4,SX_NONE),
    SX_FIELD("depth","int32",12,4,SX_NONE),
    SX_FIELD("frame_count","int32",16,4,SX_COUNT_PROP),
    SX_FIELD("type","int32",20,4,SX_NONE),
    SX_FIELD("degrees_of_freedom","int32",24,4,SX_NONE),
    SX_FIELD("ras_good_flag","int16",28,2,SX_NONE),
};
static const sx_layout sxmm_mgh_header = {UINT32_C(0x600B0065),"mgh_header",sxmm_mgh_header_fields,SX_COUNT(sxmm_mgh_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_mgh_ras_fields[] = {
    SX_FIELD("delta_x","float32",0,4,SX_NONE),
    SX_FIELD("delta_y","float32",4,4,SX_NONE),
    SX_FIELD("delta_z","float32",8,4,SX_NONE),
    SX_FIELD("direction_cosine[0]","float32",12,4,SX_NONE),
    SX_FIELD("direction_cosine[1]","float32",16,4,SX_NONE),
    SX_FIELD("direction_cosine[2]","float32",20,4,SX_NONE),
    SX_FIELD("direction_cosine[3]","float32",24,4,SX_NONE),
    SX_FIELD("direction_cosine[4]","float32",28,4,SX_NONE),
    SX_FIELD("direction_cosine[5]","float32",32,4,SX_NONE),
    SX_FIELD("direction_cosine[6]","float32",36,4,SX_NONE),
    SX_FIELD("direction_cosine[7]","float32",40,4,SX_NONE),
    SX_FIELD("direction_cosine[8]","float32",44,4,SX_NONE),
    SX_FIELD("center_x","float32",48,4,SX_NONE),
    SX_FIELD("center_y","float32",52,4,SX_NONE),
    SX_FIELD("center_z","float32",56,4,SX_NONE),
};
static const sx_layout sxmm_mgh_ras = {UINT32_C(0x600B0066),"mgh_ras",sxmm_mgh_ras_fields,SX_COUNT(sxmm_mgh_ras_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_gipl_header_le_fields[] = {
    SX_FIELD("dimension[0]","uint16",0,2,SX_NONE),
    SX_FIELD("dimension[1]","uint16",2,2,SX_NONE),
    SX_FIELD("dimension[2]","uint16",4,2,SX_NONE),
    SX_FIELD("dimension[3]","uint16",6,2,SX_NONE),
    SX_FIELD("image_type","uint16",8,2,SX_ID),
    SX_FIELD("pixel_spacing[0]","float32",10,4,SX_NONE),
    SX_FIELD("pixel_spacing[1]","float32",14,4,SX_NONE),
    SX_FIELD("pixel_spacing[2]","float32",18,4,SX_NONE),
    SX_FIELD("pixel_spacing[3]","float32",22,4,SX_NONE),
    SX_FIELD("patient_text","char[80]",26,80,SX_STRING),
    SX_FIELD("matrix[0]","float32",106,4,SX_NONE),
    SX_FIELD("matrix[1]","float32",110,4,SX_NONE),
    SX_FIELD("matrix[2]","float32",114,4,SX_NONE),
    SX_FIELD("matrix[3]","float32",118,4,SX_NONE),
    SX_FIELD("matrix[4]","float32",122,4,SX_NONE),
    SX_FIELD("matrix[5]","float32",126,4,SX_NONE),
    SX_FIELD("matrix[6]","float32",130,4,SX_NONE),
    SX_FIELD("matrix[7]","float32",134,4,SX_NONE),
    SX_FIELD("matrix[8]","float32",138,4,SX_NONE),
    SX_FIELD("matrix[9]","float32",142,4,SX_NONE),
    SX_FIELD("matrix[10]","float32",146,4,SX_NONE),
    SX_FIELD("matrix[11]","float32",150,4,SX_NONE),
    SX_FIELD("matrix[12]","float32",154,4,SX_NONE),
    SX_FIELD("matrix[13]","float32",158,4,SX_NONE),
    SX_FIELD("matrix[14]","float32",162,4,SX_NONE),
    SX_FIELD("matrix[15]","float32",166,4,SX_NONE),
    SX_FIELD("matrix[16]","float32",170,4,SX_NONE),
    SX_FIELD("matrix[17]","float32",174,4,SX_NONE),
    SX_FIELD("matrix[18]","float32",178,4,SX_NONE),
    SX_FIELD("matrix[19]","float32",182,4,SX_NONE),
    SX_FIELD("orientation_flag","uint8",186,1,SX_NONE),
    SX_FIELD("par2","uint8",187,1,SX_NONE),
    SX_FIELD("minimum","float64",188,8,SX_NONE),
    SX_FIELD("maximum","float64",196,8,SX_NONE),
    SX_FIELD("origin[0]","float64",204,8,SX_NONE),
    SX_FIELD("origin[1]","float64",212,8,SX_NONE),
    SX_FIELD("origin[2]","float64",220,8,SX_NONE),
    SX_FIELD("origin[3]","float64",228,8,SX_NONE),
    SX_FIELD("pixel_value_offset","float32",236,4,SX_NONE),
    SX_FIELD("pixel_value_calibration","float32",240,4,SX_NONE),
    SX_FIELD("interslice_gap","float32",244,4,SX_NONE),
    SX_FIELD("user_defined","float32",248,4,SX_NONE),
    SX_FIELD("magic","uint32",252,4,SX_SIGNATURE),
};
static const sx_layout sxmm_gipl_header_le = {UINT32_C(0x600B0067),"gipl_header_le",sxmm_gipl_header_le_fields,SX_COUNT(sxmm_gipl_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_gipl_header_be_fields[] = {
    SX_FIELD("dimension[0]","uint16",0,2,SX_NONE),
    SX_FIELD("dimension[1]","uint16",2,2,SX_NONE),
    SX_FIELD("dimension[2]","uint16",4,2,SX_NONE),
    SX_FIELD("dimension[3]","uint16",6,2,SX_NONE),
    SX_FIELD("image_type","uint16",8,2,SX_ID),
    SX_FIELD("pixel_spacing[0]","float32",10,4,SX_NONE),
    SX_FIELD("pixel_spacing[1]","float32",14,4,SX_NONE),
    SX_FIELD("pixel_spacing[2]","float32",18,4,SX_NONE),
    SX_FIELD("pixel_spacing[3]","float32",22,4,SX_NONE),
    SX_FIELD("patient_text","char[80]",26,80,SX_STRING),
    SX_FIELD("matrix[0]","float32",106,4,SX_NONE),
    SX_FIELD("matrix[1]","float32",110,4,SX_NONE),
    SX_FIELD("matrix[2]","float32",114,4,SX_NONE),
    SX_FIELD("matrix[3]","float32",118,4,SX_NONE),
    SX_FIELD("matrix[4]","float32",122,4,SX_NONE),
    SX_FIELD("matrix[5]","float32",126,4,SX_NONE),
    SX_FIELD("matrix[6]","float32",130,4,SX_NONE),
    SX_FIELD("matrix[7]","float32",134,4,SX_NONE),
    SX_FIELD("matrix[8]","float32",138,4,SX_NONE),
    SX_FIELD("matrix[9]","float32",142,4,SX_NONE),
    SX_FIELD("matrix[10]","float32",146,4,SX_NONE),
    SX_FIELD("matrix[11]","float32",150,4,SX_NONE),
    SX_FIELD("matrix[12]","float32",154,4,SX_NONE),
    SX_FIELD("matrix[13]","float32",158,4,SX_NONE),
    SX_FIELD("matrix[14]","float32",162,4,SX_NONE),
    SX_FIELD("matrix[15]","float32",166,4,SX_NONE),
    SX_FIELD("matrix[16]","float32",170,4,SX_NONE),
    SX_FIELD("matrix[17]","float32",174,4,SX_NONE),
    SX_FIELD("matrix[18]","float32",178,4,SX_NONE),
    SX_FIELD("matrix[19]","float32",182,4,SX_NONE),
    SX_FIELD("orientation_flag","uint8",186,1,SX_NONE),
    SX_FIELD("par2","uint8",187,1,SX_NONE),
    SX_FIELD("minimum","float64",188,8,SX_NONE),
    SX_FIELD("maximum","float64",196,8,SX_NONE),
    SX_FIELD("origin[0]","float64",204,8,SX_NONE),
    SX_FIELD("origin[1]","float64",212,8,SX_NONE),
    SX_FIELD("origin[2]","float64",220,8,SX_NONE),
    SX_FIELD("origin[3]","float64",228,8,SX_NONE),
    SX_FIELD("pixel_value_offset","float32",236,4,SX_NONE),
    SX_FIELD("pixel_value_calibration","float32",240,4,SX_NONE),
    SX_FIELD("interslice_gap","float32",244,4,SX_NONE),
    SX_FIELD("user_defined","float32",248,4,SX_NONE),
    SX_FIELD("magic","uint32",252,4,SX_SIGNATURE),
};
static const sx_layout sxmm_gipl_header_be = {UINT32_C(0x600B0068),"gipl_header_be",sxmm_gipl_header_be_fields,SX_COUNT(sxmm_gipl_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_nifti1_header_le_fields[] = {
    SX_FIELD("sizeof_hdr","int32",0,4,SX_SIZE),
    SX_FIELD("data_type","char[10]",4,10,SX_RESERVED),
    SX_FIELD("db_name","char[18]",14,18,SX_RESERVED),
    SX_FIELD("extents","int32",32,4,SX_RESERVED),
    SX_FIELD("session_error","int16",36,2,SX_RESERVED),
    SX_FIELD("regular","uint8",38,1,SX_RESERVED),
    SX_FIELD("dim_info","uint8",39,1,SX_FLAGS),
    SX_FIELD("dim[0]","int16",40,2,SX_NONE),
    SX_FIELD("dim[1]","int16",42,2,SX_NONE),
    SX_FIELD("dim[2]","int16",44,2,SX_NONE),
    SX_FIELD("dim[3]","int16",46,2,SX_NONE),
    SX_FIELD("dim[4]","int16",48,2,SX_NONE),
    SX_FIELD("dim[5]","int16",50,2,SX_NONE),
    SX_FIELD("dim[6]","int16",52,2,SX_NONE),
    SX_FIELD("dim[7]","int16",54,2,SX_NONE),
    SX_FIELD("intent_p1","float32",56,4,SX_NONE),
    SX_FIELD("intent_p2","float32",60,4,SX_NONE),
    SX_FIELD("intent_p3","float32",64,4,SX_NONE),
    SX_FIELD("intent_code","int16",68,2,SX_ID),
    SX_FIELD("datatype","int16",70,2,SX_ID),
    SX_FIELD("bitpix","int16",72,2,SX_NONE),
    SX_FIELD("slice_start","int16",74,2,SX_NONE),
    SX_FIELD("pixdim[0]","float32",76,4,SX_NONE),
    SX_FIELD("pixdim[1]","float32",80,4,SX_NONE),
    SX_FIELD("pixdim[2]","float32",84,4,SX_NONE),
    SX_FIELD("pixdim[3]","float32",88,4,SX_NONE),
    SX_FIELD("pixdim[4]","float32",92,4,SX_NONE),
    SX_FIELD("pixdim[5]","float32",96,4,SX_NONE),
    SX_FIELD("pixdim[6]","float32",100,4,SX_NONE),
    SX_FIELD("pixdim[7]","float32",104,4,SX_NONE),
    SX_FIELD("vox_offset","float32",108,4,SX_OFFSET),
    SX_FIELD("scl_slope","float32",112,4,SX_NONE),
    SX_FIELD("scl_inter","float32",116,4,SX_NONE),
    SX_FIELD("slice_end","int16",120,2,SX_NONE),
    SX_FIELD("slice_code","uint8",122,1,SX_ID),
    SX_FIELD("xyzt_units","uint8",123,1,SX_FLAGS),
    SX_FIELD("cal_max","float32",124,4,SX_NONE),
    SX_FIELD("cal_min","float32",128,4,SX_NONE),
    SX_FIELD("slice_duration","float32",132,4,SX_NONE),
    SX_FIELD("toffset","float32",136,4,SX_NONE),
    SX_FIELD("glmax","int32",140,4,SX_RESERVED),
    SX_FIELD("glmin","int32",144,4,SX_RESERVED),
    SX_FIELD("descrip","char[80]",148,80,SX_STRING),
    SX_FIELD("aux_file","char[24]",228,24,SX_STRING),
    SX_FIELD("qform_code","int16",252,2,SX_ID),
    SX_FIELD("sform_code","int16",254,2,SX_ID),
    SX_FIELD("quatern_b","float32",256,4,SX_NONE),
    SX_FIELD("quatern_c","float32",260,4,SX_NONE),
    SX_FIELD("quatern_d","float32",264,4,SX_NONE),
    SX_FIELD("qoffset_x","float32",268,4,SX_NONE),
    SX_FIELD("qoffset_y","float32",272,4,SX_NONE),
    SX_FIELD("qoffset_z","float32",276,4,SX_NONE),
    SX_FIELD("srow_x[0]","float32",280,4,SX_NONE),
    SX_FIELD("srow_x[1]","float32",284,4,SX_NONE),
    SX_FIELD("srow_x[2]","float32",288,4,SX_NONE),
    SX_FIELD("srow_x[3]","float32",292,4,SX_NONE),
    SX_FIELD("srow_y[0]","float32",296,4,SX_NONE),
    SX_FIELD("srow_y[1]","float32",300,4,SX_NONE),
    SX_FIELD("srow_y[2]","float32",304,4,SX_NONE),
    SX_FIELD("srow_y[3]","float32",308,4,SX_NONE),
    SX_FIELD("srow_z[0]","float32",312,4,SX_NONE),
    SX_FIELD("srow_z[1]","float32",316,4,SX_NONE),
    SX_FIELD("srow_z[2]","float32",320,4,SX_NONE),
    SX_FIELD("srow_z[3]","float32",324,4,SX_NONE),
    SX_FIELD("intent_name","char[16]",328,16,SX_STRING),
    SX_FIELD("magic","char[4]",344,4,SX_SIGNATURE),
};
static const sx_layout sxmm_nifti1_header_le = {UINT32_C(0x600B0069),"nifti1_header_le",sxmm_nifti1_header_le_fields,SX_COUNT(sxmm_nifti1_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_nifti1_header_be_fields[] = {
    SX_FIELD("sizeof_hdr","int32",0,4,SX_SIZE),
    SX_FIELD("data_type","char[10]",4,10,SX_RESERVED),
    SX_FIELD("db_name","char[18]",14,18,SX_RESERVED),
    SX_FIELD("extents","int32",32,4,SX_RESERVED),
    SX_FIELD("session_error","int16",36,2,SX_RESERVED),
    SX_FIELD("regular","uint8",38,1,SX_RESERVED),
    SX_FIELD("dim_info","uint8",39,1,SX_FLAGS),
    SX_FIELD("dim[0]","int16",40,2,SX_NONE),
    SX_FIELD("dim[1]","int16",42,2,SX_NONE),
    SX_FIELD("dim[2]","int16",44,2,SX_NONE),
    SX_FIELD("dim[3]","int16",46,2,SX_NONE),
    SX_FIELD("dim[4]","int16",48,2,SX_NONE),
    SX_FIELD("dim[5]","int16",50,2,SX_NONE),
    SX_FIELD("dim[6]","int16",52,2,SX_NONE),
    SX_FIELD("dim[7]","int16",54,2,SX_NONE),
    SX_FIELD("intent_p1","float32",56,4,SX_NONE),
    SX_FIELD("intent_p2","float32",60,4,SX_NONE),
    SX_FIELD("intent_p3","float32",64,4,SX_NONE),
    SX_FIELD("intent_code","int16",68,2,SX_ID),
    SX_FIELD("datatype","int16",70,2,SX_ID),
    SX_FIELD("bitpix","int16",72,2,SX_NONE),
    SX_FIELD("slice_start","int16",74,2,SX_NONE),
    SX_FIELD("pixdim[0]","float32",76,4,SX_NONE),
    SX_FIELD("pixdim[1]","float32",80,4,SX_NONE),
    SX_FIELD("pixdim[2]","float32",84,4,SX_NONE),
    SX_FIELD("pixdim[3]","float32",88,4,SX_NONE),
    SX_FIELD("pixdim[4]","float32",92,4,SX_NONE),
    SX_FIELD("pixdim[5]","float32",96,4,SX_NONE),
    SX_FIELD("pixdim[6]","float32",100,4,SX_NONE),
    SX_FIELD("pixdim[7]","float32",104,4,SX_NONE),
    SX_FIELD("vox_offset","float32",108,4,SX_OFFSET),
    SX_FIELD("scl_slope","float32",112,4,SX_NONE),
    SX_FIELD("scl_inter","float32",116,4,SX_NONE),
    SX_FIELD("slice_end","int16",120,2,SX_NONE),
    SX_FIELD("slice_code","uint8",122,1,SX_ID),
    SX_FIELD("xyzt_units","uint8",123,1,SX_FLAGS),
    SX_FIELD("cal_max","float32",124,4,SX_NONE),
    SX_FIELD("cal_min","float32",128,4,SX_NONE),
    SX_FIELD("slice_duration","float32",132,4,SX_NONE),
    SX_FIELD("toffset","float32",136,4,SX_NONE),
    SX_FIELD("glmax","int32",140,4,SX_RESERVED),
    SX_FIELD("glmin","int32",144,4,SX_RESERVED),
    SX_FIELD("descrip","char[80]",148,80,SX_STRING),
    SX_FIELD("aux_file","char[24]",228,24,SX_STRING),
    SX_FIELD("qform_code","int16",252,2,SX_ID),
    SX_FIELD("sform_code","int16",254,2,SX_ID),
    SX_FIELD("quatern_b","float32",256,4,SX_NONE),
    SX_FIELD("quatern_c","float32",260,4,SX_NONE),
    SX_FIELD("quatern_d","float32",264,4,SX_NONE),
    SX_FIELD("qoffset_x","float32",268,4,SX_NONE),
    SX_FIELD("qoffset_y","float32",272,4,SX_NONE),
    SX_FIELD("qoffset_z","float32",276,4,SX_NONE),
    SX_FIELD("srow_x[0]","float32",280,4,SX_NONE),
    SX_FIELD("srow_x[1]","float32",284,4,SX_NONE),
    SX_FIELD("srow_x[2]","float32",288,4,SX_NONE),
    SX_FIELD("srow_x[3]","float32",292,4,SX_NONE),
    SX_FIELD("srow_y[0]","float32",296,4,SX_NONE),
    SX_FIELD("srow_y[1]","float32",300,4,SX_NONE),
    SX_FIELD("srow_y[2]","float32",304,4,SX_NONE),
    SX_FIELD("srow_y[3]","float32",308,4,SX_NONE),
    SX_FIELD("srow_z[0]","float32",312,4,SX_NONE),
    SX_FIELD("srow_z[1]","float32",316,4,SX_NONE),
    SX_FIELD("srow_z[2]","float32",320,4,SX_NONE),
    SX_FIELD("srow_z[3]","float32",324,4,SX_NONE),
    SX_FIELD("intent_name","char[16]",328,16,SX_STRING),
    SX_FIELD("magic","char[4]",344,4,SX_SIGNATURE),
};
static const sx_layout sxmm_nifti1_header_be = {UINT32_C(0x600B006A),"nifti1_header_be",sxmm_nifti1_header_be_fields,SX_COUNT(sxmm_nifti1_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_nifti2_header_le_fields[] = {
    SX_FIELD("sizeof_hdr","int32",0,4,SX_SIZE),
    SX_FIELD("magic","char[8]",4,8,SX_SIGNATURE),
    SX_FIELD("datatype","int16",12,2,SX_ID),
    SX_FIELD("bitpix","int16",14,2,SX_NONE),
    SX_FIELD("dim[0]","int64",16,8,SX_NONE),
    SX_FIELD("dim[1]","int64",24,8,SX_NONE),
    SX_FIELD("dim[2]","int64",32,8,SX_NONE),
    SX_FIELD("dim[3]","int64",40,8,SX_NONE),
    SX_FIELD("dim[4]","int64",48,8,SX_NONE),
    SX_FIELD("dim[5]","int64",56,8,SX_NONE),
    SX_FIELD("dim[6]","int64",64,8,SX_NONE),
    SX_FIELD("dim[7]","int64",72,8,SX_NONE),
    SX_FIELD("intent_p1","float64",80,8,SX_NONE),
    SX_FIELD("intent_p2","float64",88,8,SX_NONE),
    SX_FIELD("intent_p3","float64",96,8,SX_NONE),
    SX_FIELD("pixdim[0]","float64",104,8,SX_NONE),
    SX_FIELD("pixdim[1]","float64",112,8,SX_NONE),
    SX_FIELD("pixdim[2]","float64",120,8,SX_NONE),
    SX_FIELD("pixdim[3]","float64",128,8,SX_NONE),
    SX_FIELD("pixdim[4]","float64",136,8,SX_NONE),
    SX_FIELD("pixdim[5]","float64",144,8,SX_NONE),
    SX_FIELD("pixdim[6]","float64",152,8,SX_NONE),
    SX_FIELD("pixdim[7]","float64",160,8,SX_NONE),
    SX_FIELD("vox_offset","int64",168,8,SX_OFFSET),
    SX_FIELD("scl_slope","float64",176,8,SX_NONE),
    SX_FIELD("scl_inter","float64",184,8,SX_NONE),
    SX_FIELD("cal_max","float64",192,8,SX_NONE),
    SX_FIELD("cal_min","float64",200,8,SX_NONE),
    SX_FIELD("slice_duration","float64",208,8,SX_NONE),
    SX_FIELD("toffset","float64",216,8,SX_NONE),
    SX_FIELD("slice_start","int64",224,8,SX_NONE),
    SX_FIELD("slice_end","int64",232,8,SX_NONE),
    SX_FIELD("descrip","char[80]",240,80,SX_STRING),
    SX_FIELD("aux_file","char[24]",320,24,SX_STRING),
    SX_FIELD("qform_code","int32",344,4,SX_ID),
    SX_FIELD("sform_code","int32",348,4,SX_ID),
    SX_FIELD("quatern_b","float64",352,8,SX_NONE),
    SX_FIELD("quatern_c","float64",360,8,SX_NONE),
    SX_FIELD("quatern_d","float64",368,8,SX_NONE),
    SX_FIELD("qoffset_x","float64",376,8,SX_NONE),
    SX_FIELD("qoffset_y","float64",384,8,SX_NONE),
    SX_FIELD("qoffset_z","float64",392,8,SX_NONE),
    SX_FIELD("srow_x[0]","float64",400,8,SX_NONE),
    SX_FIELD("srow_x[1]","float64",408,8,SX_NONE),
    SX_FIELD("srow_x[2]","float64",416,8,SX_NONE),
    SX_FIELD("srow_x[3]","float64",424,8,SX_NONE),
    SX_FIELD("srow_y[0]","float64",432,8,SX_NONE),
    SX_FIELD("srow_y[1]","float64",440,8,SX_NONE),
    SX_FIELD("srow_y[2]","float64",448,8,SX_NONE),
    SX_FIELD("srow_y[3]","float64",456,8,SX_NONE),
    SX_FIELD("srow_z[0]","float64",464,8,SX_NONE),
    SX_FIELD("srow_z[1]","float64",472,8,SX_NONE),
    SX_FIELD("srow_z[2]","float64",480,8,SX_NONE),
    SX_FIELD("srow_z[3]","float64",488,8,SX_NONE),
    SX_FIELD("slice_code","int32",496,4,SX_ID),
    SX_FIELD("xyzt_units","int32",500,4,SX_FLAGS),
    SX_FIELD("intent_code","int32",504,4,SX_ID),
    SX_FIELD("intent_name","char[16]",508,16,SX_STRING),
    SX_FIELD("dim_info","uint8",524,1,SX_FLAGS),
    SX_FIELD("unused_str","uint8[15]",525,15,SX_RESERVED),
};
static const sx_layout sxmm_nifti2_header_le = {UINT32_C(0x600B006B),"nifti2_header_le",sxmm_nifti2_header_le_fields,SX_COUNT(sxmm_nifti2_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_nifti2_header_be_fields[] = {
    SX_FIELD("sizeof_hdr","int32",0,4,SX_SIZE),
    SX_FIELD("magic","char[8]",4,8,SX_SIGNATURE),
    SX_FIELD("datatype","int16",12,2,SX_ID),
    SX_FIELD("bitpix","int16",14,2,SX_NONE),
    SX_FIELD("dim[0]","int64",16,8,SX_NONE),
    SX_FIELD("dim[1]","int64",24,8,SX_NONE),
    SX_FIELD("dim[2]","int64",32,8,SX_NONE),
    SX_FIELD("dim[3]","int64",40,8,SX_NONE),
    SX_FIELD("dim[4]","int64",48,8,SX_NONE),
    SX_FIELD("dim[5]","int64",56,8,SX_NONE),
    SX_FIELD("dim[6]","int64",64,8,SX_NONE),
    SX_FIELD("dim[7]","int64",72,8,SX_NONE),
    SX_FIELD("intent_p1","float64",80,8,SX_NONE),
    SX_FIELD("intent_p2","float64",88,8,SX_NONE),
    SX_FIELD("intent_p3","float64",96,8,SX_NONE),
    SX_FIELD("pixdim[0]","float64",104,8,SX_NONE),
    SX_FIELD("pixdim[1]","float64",112,8,SX_NONE),
    SX_FIELD("pixdim[2]","float64",120,8,SX_NONE),
    SX_FIELD("pixdim[3]","float64",128,8,SX_NONE),
    SX_FIELD("pixdim[4]","float64",136,8,SX_NONE),
    SX_FIELD("pixdim[5]","float64",144,8,SX_NONE),
    SX_FIELD("pixdim[6]","float64",152,8,SX_NONE),
    SX_FIELD("pixdim[7]","float64",160,8,SX_NONE),
    SX_FIELD("vox_offset","int64",168,8,SX_OFFSET),
    SX_FIELD("scl_slope","float64",176,8,SX_NONE),
    SX_FIELD("scl_inter","float64",184,8,SX_NONE),
    SX_FIELD("cal_max","float64",192,8,SX_NONE),
    SX_FIELD("cal_min","float64",200,8,SX_NONE),
    SX_FIELD("slice_duration","float64",208,8,SX_NONE),
    SX_FIELD("toffset","float64",216,8,SX_NONE),
    SX_FIELD("slice_start","int64",224,8,SX_NONE),
    SX_FIELD("slice_end","int64",232,8,SX_NONE),
    SX_FIELD("descrip","char[80]",240,80,SX_STRING),
    SX_FIELD("aux_file","char[24]",320,24,SX_STRING),
    SX_FIELD("qform_code","int32",344,4,SX_ID),
    SX_FIELD("sform_code","int32",348,4,SX_ID),
    SX_FIELD("quatern_b","float64",352,8,SX_NONE),
    SX_FIELD("quatern_c","float64",360,8,SX_NONE),
    SX_FIELD("quatern_d","float64",368,8,SX_NONE),
    SX_FIELD("qoffset_x","float64",376,8,SX_NONE),
    SX_FIELD("qoffset_y","float64",384,8,SX_NONE),
    SX_FIELD("qoffset_z","float64",392,8,SX_NONE),
    SX_FIELD("srow_x[0]","float64",400,8,SX_NONE),
    SX_FIELD("srow_x[1]","float64",408,8,SX_NONE),
    SX_FIELD("srow_x[2]","float64",416,8,SX_NONE),
    SX_FIELD("srow_x[3]","float64",424,8,SX_NONE),
    SX_FIELD("srow_y[0]","float64",432,8,SX_NONE),
    SX_FIELD("srow_y[1]","float64",440,8,SX_NONE),
    SX_FIELD("srow_y[2]","float64",448,8,SX_NONE),
    SX_FIELD("srow_y[3]","float64",456,8,SX_NONE),
    SX_FIELD("srow_z[0]","float64",464,8,SX_NONE),
    SX_FIELD("srow_z[1]","float64",472,8,SX_NONE),
    SX_FIELD("srow_z[2]","float64",480,8,SX_NONE),
    SX_FIELD("srow_z[3]","float64",488,8,SX_NONE),
    SX_FIELD("slice_code","int32",496,4,SX_ID),
    SX_FIELD("xyzt_units","int32",500,4,SX_FLAGS),
    SX_FIELD("intent_code","int32",504,4,SX_ID),
    SX_FIELD("intent_name","char[16]",508,16,SX_STRING),
    SX_FIELD("dim_info","uint8",524,1,SX_FLAGS),
    SX_FIELD("unused_str","uint8[15]",525,15,SX_RESERVED),
};
static const sx_layout sxmm_nifti2_header_be = {UINT32_C(0x600B006C),"nifti2_header_be",sxmm_nifti2_header_be_fields,SX_COUNT(sxmm_nifti2_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_nifti_extension_flag_fields[] = {
    SX_FIELD("extended","uint8",0,1,SX_NONE),
    SX_FIELD("reserved","uint8[3]",1,3,SX_RESERVED),
};
static const sx_layout sxmm_nifti_extension_flag = {UINT32_C(0x600B006D),"nifti_extension_flag",sxmm_nifti_extension_flag_fields,SX_COUNT(sxmm_nifti_extension_flag_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_nifti_extension_le_fields[] = {
    SX_FIELD("esize","int32",0,4,SX_SIZE),
    SX_FIELD("ecode","int32",4,4,SX_ID),
};
static const sx_layout sxmm_nifti_extension_le = {UINT32_C(0x600B006E),"nifti_extension_le",sxmm_nifti_extension_le_fields,SX_COUNT(sxmm_nifti_extension_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmm_nifti_extension_be_fields[] = {
    SX_FIELD("esize","int32",0,4,SX_SIZE),
    SX_FIELD("ecode","int32",4,4,SX_ID),
};
static const sx_layout sxmm_nifti_extension_be = {UINT32_C(0x600B006F),"nifti_extension_be",sxmm_nifti_extension_be_fields,SX_COUNT(sxmm_nifti_extension_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_pff2_section_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("length","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmm_pff2_section = {UINT32_C(0x600B0070),"pff2_section",sxmm_pff2_section_fields,SX_COUNT(sxmm_pff2_section_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_pff2_data_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("length_sentinel","uint32",4,4,SX_NONE),
};
static const sx_layout sxmm_pff2_data = {UINT32_C(0x600B0071),"pff2_data",sxmm_pff2_data_fields,SX_COUNT(sxmm_pff2_data_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_pff2_metric_fields[] = {
    SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxmm_pff2_metric = {UINT32_C(0x600B0072),"pff2_metric",sxmm_pff2_metric_fields,SX_COUNT(sxmm_pff2_metric_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_pff2_index_fields[] = {
    SX_FIELD("codepoint","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("offset","uint32",5,4,SX_OFFSET),
};
static const sx_layout sxmm_pff2_index = {UINT32_C(0x600B0073),"pff2_index",sxmm_pff2_index_fields,SX_COUNT(sxmm_pff2_index_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_pff2_glyph_fields[] = {
    SX_FIELD("width","uint16",0,2,SX_NONE),
    SX_FIELD("height","uint16",2,2,SX_NONE),
    SX_FIELD("x_offset","int16",4,2,SX_NONE),
    SX_FIELD("y_offset","int16",6,2,SX_NONE),
    SX_FIELD("device_width","int16",8,2,SX_NONE),
};
static const sx_layout sxmm_pff2_glyph = {UINT32_C(0x600B0074),"pff2_glyph",sxmm_pff2_glyph_fields,SX_COUNT(sxmm_pff2_glyph_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ttc_header_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("font_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmm_ttc_header = {UINT32_C(0x600B0075),"ttc_header",sxmm_ttc_header_fields,SX_COUNT(sxmm_ttc_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ttc_font_offset_fields[] = {
    SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmm_ttc_font_offset = {UINT32_C(0x600B0076),"ttc_font_offset",sxmm_ttc_font_offset_fields,SX_COUNT(sxmm_ttc_font_offset_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ttc_dsig_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("length","uint32",4,4,SX_SIZE),
    SX_FIELD("offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxmm_ttc_dsig = {UINT32_C(0x600B0077),"ttc_dsig",sxmm_ttc_dsig_fields,SX_COUNT(sxmm_ttc_dsig_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ttc_sfnt_fields[] = {
    SX_FIELD("sfnt_version","uint32",0,4,SX_ID),
    SX_FIELD("table_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("search_range","uint16",6,2,SX_SIZE),
    SX_FIELD("entry_selector","uint16",8,2,SX_NONE),
    SX_FIELD("range_shift","uint16",10,2,SX_SIZE),
};
static const sx_layout sxmm_ttc_sfnt = {UINT32_C(0x600B0078),"ttc_sfnt",sxmm_ttc_sfnt_fields,SX_COUNT(sxmm_ttc_sfnt_fields),SX_BE};

static const xx_data_struct_field_desc sxmm_ttc_table_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("length","uint32",12,4,SX_SIZE),
};
static const sx_layout sxmm_ttc_table = {UINT32_C(0x600B0079),"ttc_table",sxmm_ttc_table_fields,SX_COUNT(sxmm_ttc_table_fields),SX_BE};

static const sx_layout *const sx_multimedia_layouts[] = {
    &sxmm_ym_header,
    &sxmm_ym_digidrum,
    &sxmm_hes_header,
    &sxmm_hes_data_header,
    &sxmm_psid_header_v1,
    &sxmm_psid_header_v2,
    &sxmm_psid_load_address,
    &sxmm_nsf_header,
    &sxmm_gbs_header,
    &sxmm_sgc_header,
    &sxmm_s98_header,
    &sxmm_s98_device,
    &sxmm_vst3_header,
    &sxmm_vst3_list,
    &sxmm_vst3_entry,
    &sxmm_vst2_program,
    &sxmm_vst2_bank_v1,
    &sxmm_vst2_bank_v2,
    &sxmm_vst2_parameter,
    &sxmm_vst2_chunk,
    &sxmm_dro_header_v2,
    &sxmm_dro_register_map,
    &sxmm_dro_pair,
    &sxmm_cmf_header_v1,
    &sxmm_cmf_header_v11,
    &sxmm_cmf_instrument,
    &sxmm_spc_header,
    &sxmm_spc_id666_common,
    &sxmm_spc_xid6_header,
    &sxmm_spc_xid6_item,
    &sxmm_glb_header,
    &sxmm_glb_chunk,
    &sxmm_vox_header,
    &sxmm_vox_chunk,
    &sxmm_vox_pack,
    &sxmm_vox_size,
    &sxmm_vox_xyzi,
    &sxmm_vox_voxel,
    &sxmm_vox_rgba,
    &sxmm_ase_header,
    &sxmm_ase_block,
    &sxmm_ase_name,
    &sxmm_utf16_unit,
    &sxmm_ase_rgb,
    &sxmm_ase_lab,
    &sxmm_ase_cmyk,
    &sxmm_ase_gray,
    &sxmm_aco_header,
    &sxmm_aco_color,
    &sxmm_aco_lab_color,
    &sxmm_aco_name,
    &sxmm_acv_header,
    &sxmm_acv_curve,
    &sxmm_acv_point,
    &sxmm_act_color,
    &sxmm_act_footer,
    &sxmm_pvr2_header,
    &sxmm_tim_header,
    &sxmm_tim_block,
    &sxmm_tim2_header,
    &sxmm_tim2_picture,
    &sxmm_tpl_header,
    &sxmm_tpl_entry,
    &sxmm_tpl_image,
    &sxmm_tpl_palette,
    &sxmm_xcursor_header,
    &sxmm_xcursor_toc,
    &sxmm_xcursor_image,
    &sxmm_xcursor_comment,
    &sxmm_mdd_header,
    &sxmm_mdd_time,
    &sxmm_mdd_point,
    &sxmm_pic_header,
    &sxmm_pic_packet,
    &sxmm_fsh_header,
    &sxmm_fsh_entry,
    &sxmm_fsh_bitmap,
    &sxmm_twobit_header_le,
    &sxmm_twobit_header_be,
    &sxmm_twobit_name,
    &sxmm_twobit_index_offset_le,
    &sxmm_twobit_index_offset_be,
    &sxmm_twobit_sequence_le,
    &sxmm_twobit_sequence_be,
    &sxmm_twobit_run_count_le,
    &sxmm_twobit_run_count_be,
    &sxmm_twobit_run_start_le,
    &sxmm_twobit_run_start_be,
    &sxmm_twobit_run_size_le,
    &sxmm_twobit_run_size_be,
    &sxmm_twobit_reserved_le,
    &sxmm_twobit_reserved_be,
    &sxmm_gds_record,
    &sxmm_gds_int16,
    &sxmm_gds_int32,
    &sxmm_gds_bit_array,
    &sxmm_gds_real64,
    &sxmm_gds_timestamp,
    &sxmm_ser_header,
    &sxmm_ser_timestamp,
    &sxmm_mgh_header,
    &sxmm_mgh_ras,
    &sxmm_gipl_header_le,
    &sxmm_gipl_header_be,
    &sxmm_nifti1_header_le,
    &sxmm_nifti1_header_be,
    &sxmm_nifti2_header_le,
    &sxmm_nifti2_header_be,
    &sxmm_nifti_extension_flag,
    &sxmm_nifti_extension_le,
    &sxmm_nifti_extension_be,
    &sxmm_pff2_section,
    &sxmm_pff2_data,
    &sxmm_pff2_metric,
    &sxmm_pff2_index,
    &sxmm_pff2_glyph,
    &sxmm_ttc_header,
    &sxmm_ttc_font_offset,
    &sxmm_ttc_dsig,
    &sxmm_ttc_sfnt,
    &sxmm_ttc_table,
};

/* Metadata is collected independently of payloads, sorted and completed with
 * explicit raw gaps. An overlapping or out-of-range descriptor is rejected. */
static bool sxmm_span(sx_context *c,uint64_t at,uint64_t n){return at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
static bool sxmm_read(sx_context *c,uint64_t at,void *b,size_t n){return sxmm_span(c,at,n)&&sx_read(c,(int64_t)at,b,n);}
static bool sxmm_add(sx_context *c,const sx_layout *l,uint64_t at,uint64_t n){if(!sxmm_span(c,at,n))return false;for(size_t i=0;i<c->count;i++)if(c->items[i].id==l->id&&c->items[i].offset-c->f->base_address==(int64_t)at&&c->items[i].total_size==(int64_t)n)return true;return sxmm_span(c,at,n)&&sx_add(c,l,(int64_t)at,(int64_t)n);}
static bool sxmm_table(sx_context *c,const sx_layout *l,uint64_t at,uint64_t stride,uint64_t count){return stride&&count<=(uint64_t)c->size/stride&&sxmm_span(c,at,stride*count)&&sx_table(c,l,(int64_t)at,(int64_t)stride,count);}
static bool sxmm_u32(sx_context *c,uint64_t at,bool be,uint32_t *v){return sxmm_span(c,at,4)&&sx_u32(c,(int64_t)at,be,v);}
static void sxmm_sort(sx_context *c){for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){xx_data_struct v=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>v.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=v;}}
static bool sxmm_finish(sx_context *c){int64_t end=0;size_t n=c->count;sxmm_sort(c);for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;sxmm_sort(c);return !c->failed;}
#define MM_NEED(x) do{if(!(x))return false;}while(0)
#define MM_U16(p,b) xx_data_get_u16((p),2,0,(b))
#define MM_U32(p,b) xx_data_get_u32((p),4,0,(b))
#define MM_U64(p,b) xx_data_get_u64((p),8,0,(b))
#define MM_PAIR(n,b) ((b)?&sxmm_##n##_be:&sxmm_##n##_le)
static bool sxmm_vst_program(sx_context *c,uint64_t *at,uint64_t end)
{
    uint8_t h[56];uint32_t n,count;uint64_t p=*at;
    MM_NEED(sxmm_read(c,p,h,56)&&!xx_rt_memcmp(h,"CcnK",4));n=MM_U32(h+4,true);count=MM_U32(h+24,true);
    MM_NEED(count&&count<=65536&&sxmm_add(c,&sxmm_vst2_program,p,56));
    if(!xx_rt_memcmp(h+8,"FxCk",4)){MM_NEED(n==48+(uint64_t)count*4&&sxmm_table(c,&sxmm_vst2_parameter,p+56,4,count));p+=56+(uint64_t)count*4;}
    else if(!xx_rt_memcmp(h+8,"FPCh",4)){uint32_t z;MM_NEED(sxmm_u32(c,p+56,true,&z)&&z&&(n==0||n==52+(uint64_t)z)&&sxmm_add(c,&sxmm_vst2_chunk,p+56,4)&&sxmm_span(c,p+60,z));p+=60+(uint64_t)z;}
    else return false;
    MM_NEED(p<=end);*at=p;return true;
}
static bool sxmm_nifti(sx_context *c,bool two)
{
    uint8_t h[544];bool be;uint32_t want=two?540:348;uint64_t at,p=want+4;
    MM_NEED(sxmm_read(c,0,h,want+4));be=MM_U32(h,true)==want;MM_NEED(be||MM_U32(h,false)==want);
    if(two)at=MM_U64(h+168,be);else{uint32_t v=MM_U32(h+108,be),mant=(v&0x7fffff)|0x800000;int exp=(int)((v>>23)&255)-127-23;MM_NEED(!(v&0x80000000)&&((v>>23)&255)!=255&&exp<=39);if(exp>=0)at=(uint64_t)mant<<exp;else{MM_NEED(exp>=-23&&!(mant&((UINT32_C(1)<<(-exp))-1)));at=mant>>(-exp);}}
    MM_NEED(at>=p&&at<=(uint64_t)c->size&&sxmm_add(c,two?MM_PAIR(nifti2_header,be):MM_PAIR(nifti1_header,be),0,want)&&sxmm_add(c,&sxmm_nifti_extension_flag,want,4));
    if(h[want]){unsigned count=0;while(p<at){uint8_t e[8];uint32_t n;MM_NEED(++count<=4096&&sxmm_read(c,p,e,8));n=MM_U32(e,be);MM_NEED(n>=16&&!(n%16)&&n<=at-p&&sxmm_add(c,MM_PAIR(nifti_extension,be),p,8));p+=n;}}
    return true;
}
static bool sx_multimedia_supports(xx_file_type_t t)
{
    switch(t){
    case XX_FILE_TYPE_YAMAHA_YM:case XX_FILE_TYPE_HES_SOUND:case XX_FILE_TYPE_PSID_SID:case XX_FILE_TYPE_NINTENDO_NSF:case XX_FILE_TYPE_GAMEBOY_GBS:case XX_FILE_TYPE_SEGA_SGC:case XX_FILE_TYPE_S98_LOG:case XX_FILE_TYPE_STEINBERG_VST3PRESET:case XX_FILE_TYPE_STEINBERG_FXB:case XX_FILE_TYPE_DOSBOX_DRO:case XX_FILE_TYPE_CREATIVE_CMF:case XX_FILE_TYPE_SNES_SPC:
    case XX_FILE_TYPE_GLB:case XX_FILE_TYPE_MAGICAVOXEL_VOX:case XX_FILE_TYPE_ADOBE_ASE:case XX_FILE_TYPE_ADOBE_ACO:case XX_FILE_TYPE_ADOBE_ACV:case XX_FILE_TYPE_ADOBE_ACT:case XX_FILE_TYPE_SEGA_PVR2:case XX_FILE_TYPE_SONY_TIM:case XX_FILE_TYPE_SONY_TIM2:case XX_FILE_TYPE_NINTENDO_TPL:case XX_FILE_TYPE_XCURSOR:case XX_FILE_TYPE_LIGHTWAVE_MDD:case XX_FILE_TYPE_SOFTIMAGE_PIC:case XX_FILE_TYPE_EA_FSH:
    case XX_FILE_TYPE_UCSC_TWOBIT:case XX_FILE_TYPE_CALMA_GDSII:case XX_FILE_TYPE_ASTRONOMY_SER:case XX_FILE_TYPE_FREESURFER_MGH:case XX_FILE_TYPE_GIPL:case XX_FILE_TYPE_NIFTI1:case XX_FILE_TYPE_NIFTI2:case XX_FILE_TYPE_GRUB_PFF2:case XX_FILE_TYPE_SFNT_COLLECTION:return true;
    default:return false;}
}
static bool sxmm_build(sx_context *c)
{
    uint8_t h[256];uint64_t p=0;uint32_t count=0,z=0;
    switch(c->f->file_type){
    case XX_FILE_TYPE_YAMAHA_YM:{uint16_t drums;MM_NEED(sxmm_read(c,0,h,34)&&(!xx_rt_memcmp(h,"YM5!",4)||!xx_rt_memcmp(h,"YM6!",4))&&sxmm_add(c,&sxmm_ym_header,0,34));p=34U+MM_U16(h+32,true);drums=MM_U16(h+20,true);MM_NEED(drums<=256&&sxmm_span(c,0,p));for(unsigned i=0;i<drums;i++){MM_NEED(sxmm_u32(c,p,true,&z)&&sxmm_add(c,&sxmm_ym_digidrum,p,4)&&sxmm_span(c,p+4,z));p+=4U+(uint64_t)z;}return true;}
    case XX_FILE_TYPE_HES_SOUND:MM_NEED(sxmm_read(c,0,h,16)&&!xx_rt_memcmp(h,"HESM",4)&&sxmm_add(c,&sxmm_hes_header,0,16));p=16;while(p<(uint64_t)c->size){MM_NEED(++count<=64&&sxmm_read(c,p,h,16)&&!xx_rt_memcmp(h,"DATA",4));z=MM_U32(h+4,false);MM_NEED(z&&sxmm_add(c,&sxmm_hes_data_header,p,16)&&sxmm_span(c,p+16,z));p+=16U+(uint64_t)z;}return true;
    case XX_FILE_TYPE_PSID_SID:{uint16_t ver,off,load;MM_NEED(sxmm_read(c,0,h,18)&&(!xx_rt_memcmp(h,"PSID",4)||!xx_rt_memcmp(h,"RSID",4)));ver=MM_U16(h+4,true);off=MM_U16(h+6,true);load=MM_U16(h+8,true);MM_NEED(ver==1||ver==2);z=ver==1?118:124;MM_NEED(off>=z&&sxmm_add(c,ver==1?&sxmm_psid_header_v1:&sxmm_psid_header_v2,0,z));if(!load)MM_NEED(sxmm_add(c,&sxmm_psid_load_address,off,2));return true;}
    case XX_FILE_TYPE_NINTENDO_NSF:return sxmm_read(c,0,h,5)&&!xx_rt_memcmp(h,"NESM\x1a",5)&&sxmm_add(c,&sxmm_nsf_header,0,128);
    case XX_FILE_TYPE_GAMEBOY_GBS:return sxmm_read(c,0,h,4)&&!xx_rt_memcmp(h,"GBS\1",4)&&sxmm_add(c,&sxmm_gbs_header,0,112);
    case XX_FILE_TYPE_SEGA_SGC:return sxmm_read(c,0,h,5)&&!xx_rt_memcmp(h,"SGC\x1a\1",5)&&sxmm_add(c,&sxmm_sgc_header,0,160);
    case XX_FILE_TYPE_S98_LOG:MM_NEED(sxmm_read(c,0,h,32)&&!xx_rt_memcmp(h,"S983",4));count=MM_U32(h+28,false);return count<=64&&sxmm_add(c,&sxmm_s98_header,0,32)&&sxmm_table(c,&sxmm_s98_device,32,16,count);
    case XX_FILE_TYPE_STEINBERG_VST3PRESET:MM_NEED(sxmm_read(c,0,h,48)&&!xx_rt_memcmp(h,"VST3",4)&&sxmm_add(c,&sxmm_vst3_header,0,48));p=MM_U64(h+40,false);MM_NEED(p>=48&&sxmm_read(c,p,h,8)&&!xx_rt_memcmp(h,"List",4));count=MM_U32(h+4,false);return count<=3&&sxmm_add(c,&sxmm_vst3_list,p,8)&&sxmm_table(c,&sxmm_vst3_entry,p+8,20,count);
    case XX_FILE_TYPE_STEINBERG_FXB:MM_NEED(sxmm_read(c,0,h,32)&&!xx_rt_memcmp(h,"CcnK",4));if(!xx_rt_memcmp(h+8,"FxCk",4)||!xx_rt_memcmp(h+8,"FPCh",4))return sxmm_vst_program(c,&p,(uint64_t)c->size);count=MM_U32(h+24,true);z=MM_U32(h+12,true);MM_NEED(count&&count<=1024&&(z==1||z==2)&&sxmm_add(c,z==1?&sxmm_vst2_bank_v1:&sxmm_vst2_bank_v2,0,156));p=156;if(!xx_rt_memcmp(h+8,"FxBk",4)){for(uint32_t i=0;i<count;i++)MM_NEED(sxmm_vst_program(c,&p,(uint64_t)c->size));return true;}MM_NEED(!xx_rt_memcmp(h+8,"FBCh",4)&&sxmm_u32(c,156,true,&z)&&sxmm_span(c,160,z));return sxmm_add(c,&sxmm_vst2_chunk,156,4);
    case XX_FILE_TYPE_DOSBOX_DRO:MM_NEED(sxmm_read(c,0,h,26)&&!xx_rt_memcmp(h,"DBRAWOPL",8)&&MM_U16(h+8,false)==2);count=MM_U32(h+12,false);return count<=1000000&&h[25]<=128&&sxmm_add(c,&sxmm_dro_header_v2,0,26)&&sxmm_table(c,&sxmm_dro_register_map,26,1,h[25])&&sxmm_table(c,&sxmm_dro_pair,26U+h[25],2,count);
    case XX_FILE_TYPE_CREATIVE_CMF:{uint16_t ver,inst;MM_NEED(sxmm_read(c,0,h,40)&&!xx_rt_memcmp(h,"CTMF",4));ver=MM_U16(h+4,false);inst=MM_U16(h+6,false);count=ver==0x100?h[36]:MM_U16(h+36,false);MM_NEED((ver==0x100||ver==0x101)&&count<=128);z=ver==0x100?37:40;return inst>=z&&sxmm_add(c,ver==0x100?&sxmm_cmf_header_v1:&sxmm_cmf_header_v11,0,z)&&sxmm_table(c,&sxmm_cmf_instrument,inst,16,count);}
    case XX_FILE_TYPE_SNES_SPC:MM_NEED(sxmm_read(c,0,h,46)&&!xx_rt_memcmp(h,"SNES-SPC700 Sound File Data v0.30",33)&&sxmm_add(c,&sxmm_spc_header,0,46));if(h[35]==26)MM_NEED(sxmm_add(c,&sxmm_spc_id666_common,46,112));p=66048;if(p<(uint64_t)c->size){uint64_t end;MM_NEED(sxmm_read(c,p,h,8)&&!xx_rt_memcmp(h,"xid6",4)&&sxmm_add(c,&sxmm_spc_xid6_header,p,8));end=p+8+MM_U32(h+4,false);MM_NEED(end<=(uint64_t)c->size);p+=8;while(p<end){MM_NEED(++count<=4096&&sxmm_read(c,p,h,4)&&sxmm_add(c,&sxmm_spc_xid6_item,p,4));z=h[1]?MM_U16(h+2,false):0;MM_NEED(z<=end-p-4);p=(p+4+z+3)&~UINT64_C(3);MM_NEED(p<=end);}}return true;
    case XX_FILE_TYPE_GLB:MM_NEED(sxmm_read(c,0,h,12)&&!xx_rt_memcmp(h,"glTF",4)&&MM_U32(h+4,false)==2&&sxmm_add(c,&sxmm_glb_header,0,12));p=12;while(p<(uint64_t)c->size){MM_NEED(++count<=4096&&sxmm_read(c,p,h,8));z=MM_U32(h,false);MM_NEED(!(z%4)&&sxmm_add(c,&sxmm_glb_chunk,p,8)&&sxmm_span(c,p+8,z));p+=8U+(uint64_t)z;}return true;
    case XX_FILE_TYPE_MAGICAVOXEL_VOX:MM_NEED(sxmm_read(c,0,h,20)&&!xx_rt_memcmp(h,"VOX ",4)&&MM_U32(h+4,false)==150&&sxmm_add(c,&sxmm_vox_header,0,8)&&sxmm_add(c,&sxmm_vox_chunk,8,12));p=20;while(p<(uint64_t)c->size){MM_NEED(++count<=4096&&sxmm_read(c,p,h,12));z=MM_U32(h+4,false);MM_NEED(sxmm_add(c,&sxmm_vox_chunk,p,12)&&sxmm_span(c,p+12,z));if(!xx_rt_memcmp(h,"PACK",4))MM_NEED(z==4&&sxmm_add(c,&sxmm_vox_pack,p+12,4));else if(!xx_rt_memcmp(h,"SIZE",4))MM_NEED(z==12&&sxmm_add(c,&sxmm_vox_size,p+12,12));else if(!xx_rt_memcmp(h,"RGBA",4))MM_NEED(z==1024&&sxmm_table(c,&sxmm_vox_rgba,p+12,4,256));else if(!xx_rt_memcmp(h,"XYZI",4)){uint32_t n;MM_NEED(sxmm_u32(c,p+12,false,&n)&&n<=1048576&&z==4U+(uint64_t)n*4&&sxmm_add(c,&sxmm_vox_xyzi,p+12,4)&&sxmm_table(c,&sxmm_vox_voxel,p+16,4,n));}p+=12U+(uint64_t)z;}return true;
    case XX_FILE_TYPE_ADOBE_ASE:MM_NEED(sxmm_read(c,0,h,12)&&!xx_rt_memcmp(h,"ASEF",4));count=MM_U32(h+8,true);MM_NEED(count<=4096&&sxmm_add(c,&sxmm_ase_header,0,12));p=12;for(uint32_t i=0;i<count;i++){uint16_t type,n;uint64_t end;MM_NEED(sxmm_read(c,p,h,6));type=MM_U16(h,true);z=MM_U32(h+2,true);MM_NEED(sxmm_span(c,p+6,z)&&sxmm_add(c,&sxmm_ase_block,p,6));end=p+6+z;p+=6;if(type==1||type==0xc001){MM_NEED(sxmm_read(c,p,h,2));n=MM_U16(h,true);MM_NEED(n<=1024&&2U+(uint64_t)n*2<=z&&sxmm_add(c,&sxmm_ase_name,p,2)&&sxmm_table(c,&sxmm_utf16_unit,p+2,2,n));p+=2U+(uint64_t)n*2;if(type==1){const sx_layout *l;uint32_t len;MM_NEED(sxmm_read(c,p,h,4));if(!xx_rt_memcmp(h,"RGB ",4)){l=&sxmm_ase_rgb;len=18;}else if(!xx_rt_memcmp(h,"LAB ",4)){l=&sxmm_ase_lab;len=18;}else if(!xx_rt_memcmp(h,"CMYK",4)){l=&sxmm_ase_cmyk;len=22;}else if(!xx_rt_memcmp(h,"Gray",4)||!xx_rt_memcmp(h,"GRAY",4)){l=&sxmm_ase_gray;len=10;}else return false;MM_NEED(p+len==end&&sxmm_add(c,l,p,len));}}p=end;}return true;
    case XX_FILE_TYPE_ADOBE_ACO:for(unsigned ver=1;ver<=2;ver++){MM_NEED(sxmm_read(c,p,h,4)&&MM_U16(h,true)==ver);count=MM_U16(h+2,true);MM_NEED(count<=4096&&sxmm_add(c,&sxmm_aco_header,p,4));p+=4;for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_read(c,p,h,10)&&sxmm_add(c,MM_U16(h,true)==7?&sxmm_aco_lab_color:&sxmm_aco_color,p,10));p+=10;if(ver==2){MM_NEED(sxmm_u32(c,p,true,&z)&&z<=1024&&sxmm_add(c,&sxmm_aco_name,p,4)&&sxmm_table(c,&sxmm_utf16_unit,p+4,2,z));p+=4U+(uint64_t)z*2;}}}return true;
    case XX_FILE_TYPE_ADOBE_ACV:MM_NEED(sxmm_read(c,0,h,4));count=MM_U16(h+2,true);MM_NEED((MM_U16(h,true)==1||MM_U16(h,true)==4)&&count&&count<=16&&sxmm_add(c,&sxmm_acv_header,0,4));p=4;for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_read(c,p,h,2));z=MM_U16(h,true);MM_NEED(z>=2&&z<=19&&sxmm_add(c,&sxmm_acv_curve,p,2)&&sxmm_table(c,&sxmm_acv_point,p+2,4,z));p+=2U+(uint64_t)z*4;}return true;
    case XX_FILE_TYPE_ADOBE_ACT:return (c->size==768||c->size==772)&&sxmm_table(c,&sxmm_act_color,0,3,256)&&(c->size==768||sxmm_add(c,&sxmm_act_footer,768,4));
    case XX_FILE_TYPE_SEGA_PVR2:return sxmm_read(c,0,h,4)&&!xx_rt_memcmp(h,"PVRT",4)&&sxmm_add(c,&sxmm_pvr2_header,0,16);
    case XX_FILE_TYPE_SONY_TIM:MM_NEED(sxmm_read(c,0,h,8)&&MM_U32(h,false)==16&&sxmm_add(c,&sxmm_tim_header,0,8));count=(MM_U32(h+4,false)&8)?2:1;p=8;for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_u32(c,p,false,&z)&&z>=12&&sxmm_span(c,p,z)&&sxmm_add(c,&sxmm_tim_block,p,12));p+=z;}return true;
    case XX_FILE_TYPE_SONY_TIM2:MM_NEED(sxmm_read(c,0,h,16)&&!xx_rt_memcmp(h,"TIM2",4)&&sxmm_add(c,&sxmm_tim2_header,0,16));count=MM_U16(h+6,false);MM_NEED(count<=1024);p=16;for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_u32(c,p,false,&z)&&z>=48&&sxmm_span(c,p,z)&&sxmm_add(c,&sxmm_tim2_picture,p,48));p+=z;}return true;
    case XX_FILE_TYPE_NINTENDO_TPL:MM_NEED(sxmm_read(c,0,h,12)&&MM_U32(h,true)==0x20af30);count=MM_U32(h+4,true);p=MM_U32(h+8,true);MM_NEED(count<=1024&&p>=12&&sxmm_add(c,&sxmm_tpl_header,0,12)&&sxmm_table(c,&sxmm_tpl_entry,p,8,count));for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_read(c,p+(uint64_t)i*8,h,8));uint64_t a=MM_U32(h,true),b=MM_U32(h+4,true);MM_NEED(a>=p+(uint64_t)count*8&&sxmm_add(c,&sxmm_tpl_image,a,36));if(b)MM_NEED(b>=p+(uint64_t)count*8&&sxmm_add(c,&sxmm_tpl_palette,b,12));}return true;
    case XX_FILE_TYPE_XCURSOR:MM_NEED(sxmm_read(c,0,h,16)&&!xx_rt_memcmp(h,"Xcur",4));p=MM_U32(h+4,false);count=MM_U32(h+12,false);MM_NEED(p>=16&&count<=1024&&sxmm_add(c,&sxmm_xcursor_header,0,16)&&sxmm_table(c,&sxmm_xcursor_toc,p,12,count));for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_read(c,p+(uint64_t)i*12,h,12));uint32_t type=MM_U32(h,false),a=MM_U32(h+8,false);MM_NEED(a>=p+(uint64_t)count*12);if(type==0xfffd0002)MM_NEED(sxmm_add(c,&sxmm_xcursor_image,a,36));else if(type==0xfffe0001)MM_NEED(sxmm_add(c,&sxmm_xcursor_comment,a,20));else return false;}return true;
    case XX_FILE_TYPE_LIGHTWAVE_MDD:MM_NEED(sxmm_read(c,0,h,8));count=MM_U32(h,true);z=MM_U32(h+4,true);return count&&z&&count<=4096&&z<=65536&&(uint64_t)count*z<=1000000&&sxmm_add(c,&sxmm_mdd_header,0,8)&&sxmm_table(c,&sxmm_mdd_time,8,4,count)&&sxmm_table(c,&sxmm_mdd_point,8U+(uint64_t)count*4,12,(uint64_t)count*z);
    case XX_FILE_TYPE_SOFTIMAGE_PIC:MM_NEED(sxmm_read(c,0,h,4)&&MM_U32(h,true)==0x5380f634&&sxmm_add(c,&sxmm_pic_header,0,104));p=104;do{MM_NEED(++count<=4&&sxmm_read(c,p,h,4)&&sxmm_add(c,&sxmm_pic_packet,p,4));p+=4;}while(h[0]);return true;
    case XX_FILE_TYPE_EA_FSH:MM_NEED(sxmm_read(c,0,h,16)&&!xx_rt_memcmp(h,"SHP",3));count=MM_U32(h+8,false);MM_NEED(count<=8192&&sxmm_add(c,&sxmm_fsh_header,0,16)&&sxmm_table(c,&sxmm_fsh_entry,16,8,count));for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_u32(c,20U+(uint64_t)i*8,false,&z)&&z>=16U+(uint64_t)count*8&&sxmm_add(c,&sxmm_fsh_bitmap,z,16));}return true;
    case XX_FILE_TYPE_UCSC_TWOBIT:{bool be;uint64_t offsets[1024];MM_NEED(sxmm_read(c,0,h,16));be=MM_U32(h,true)==0x1a412743;MM_NEED(be||MM_U32(h,false)==0x1a412743);count=MM_U32(h+8,be);MM_NEED(count&&count<=1024&&sxmm_add(c,MM_PAIR(twobit_header,be),0,16));p=16;for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_read(c,p,h,1)&&h[0]&&sxmm_add(c,&sxmm_twobit_name,p,1));p+=1U+h[0];MM_NEED(sxmm_u32(c,p,be,&z)&&sxmm_add(c,MM_PAIR(twobit_index_offset,be),p,4));offsets[i]=z;p+=4;}for(uint32_t i=0;i<count;i++){uint64_t a=offsets[i];MM_NEED(a>=p&&sxmm_add(c,MM_PAIR(twobit_sequence,be),a,4));a+=4;for(unsigned j=0;j<2;j++){MM_NEED(sxmm_u32(c,a,be,&z)&&z<=65536&&sxmm_add(c,MM_PAIR(twobit_run_count,be),a,4)&&sxmm_table(c,MM_PAIR(twobit_run_start,be),a+4,4,z)&&sxmm_table(c,MM_PAIR(twobit_run_size,be),a+4U+(uint64_t)z*4,4,z));a+=4U+(uint64_t)z*8;}MM_NEED(sxmm_add(c,MM_PAIR(twobit_reserved,be),a,4));}return true;}
    case XX_FILE_TYPE_CALMA_GDSII:while(p<(uint64_t)c->size){MM_NEED(++count<=8192&&sxmm_read(c,p,h,4));z=MM_U16(h,true);MM_NEED(z>=4&&!(z&1)&&sxmm_span(c,p,z)&&sxmm_add(c,&sxmm_gds_record,p,4));const sx_layout *l=NULL;uint32_t stride=0;if((h[2]==1||h[2]==5)&&h[3]==2&&z==28){l=&sxmm_gds_timestamp;stride=12;}else if(h[3]==1){l=&sxmm_gds_bit_array;stride=2;}else if(h[3]==2){l=&sxmm_gds_int16;stride=2;}else if(h[3]==3){l=&sxmm_gds_int32;stride=4;}else if(h[3]==5){l=&sxmm_gds_real64;stride=8;}if(l){MM_NEED(!((z-4)%stride)&&sxmm_table(c,l,p+4,stride,(z-4)/stride));}p+=z;}return true;
    case XX_FILE_TYPE_ASTRONOMY_SER:{uint64_t bytes,end;MM_NEED(sxmm_read(c,0,h,178)&&!xx_rt_memcmp(h,"LUCAM-RECORDER",14)&&sxmm_add(c,&sxmm_ser_header,0,178));count=MM_U32(h+38,false);bytes=(uint64_t)MM_U32(h+26,false)*MM_U32(h+30,false);MM_NEED(bytes<=1048576&&count<=4094);bytes*=MM_U32(h+34,false)>8?2:1;bytes*=MM_U32(h+18,false)>=100?3:1;end=178+bytes*count;MM_NEED(end<=(uint64_t)c->size);return end==(uint64_t)c->size||sxmm_table(c,&sxmm_ser_timestamp,end,8,count);}
    case XX_FILE_TYPE_FREESURFER_MGH:MM_NEED(sxmm_read(c,0,h,30)&&MM_U32(h,true)==1&&sxmm_add(c,&sxmm_mgh_header,0,30));return !MM_U16(h+28,true)||sxmm_add(c,&sxmm_mgh_ras,30,60);
    case XX_FILE_TYPE_GIPL:{bool be;MM_NEED(sxmm_read(c,0,h,256));z=MM_U32(h+252,true);be=z==0xefffe9b0||z==0x2ae389b8;z=MM_U32(h+252,false);return (be||z==0xefffe9b0||z==0x2ae389b8)&&sxmm_add(c,MM_PAIR(gipl_header,be),0,256);}
    case XX_FILE_TYPE_NIFTI1:return sxmm_nifti(c,false);
    case XX_FILE_TYPE_NIFTI2:return sxmm_nifti(c,true);
    case XX_FILE_TYPE_GRUB_PFF2:{uint64_t index=0;uint32_t len=0;MM_NEED(sxmm_read(c,0,h,12)&&!xx_rt_memcmp(h,"FILE\0\0\0\4PFF2",12));while(p<(uint64_t)c->size){MM_NEED(++count<=4096&&sxmm_read(c,p,h,8));z=MM_U32(h+4,true);if(!xx_rt_memcmp(h,"DATA",4)){MM_NEED(z==UINT32_MAX&&sxmm_add(c,&sxmm_pff2_data,p,8));p+=8;break;}MM_NEED(sxmm_add(c,&sxmm_pff2_section,p,8));MM_NEED(sxmm_span(c,p+8,z));if(!xx_rt_memcmp(h,"CHIX",4)){MM_NEED(z&&!(z%9)&&z/9<=4000);index=p+8;len=z;MM_NEED(sxmm_table(c,&sxmm_pff2_index,index,9,z/9));}else if(!xx_rt_memcmp(h,"PTSZ",4)||!xx_rt_memcmp(h,"MAXW",4)||!xx_rt_memcmp(h,"MAXH",4)||!xx_rt_memcmp(h,"ASCE",4)||!xx_rt_memcmp(h,"DESC",4)){MM_NEED(z==2&&sxmm_add(c,&sxmm_pff2_metric,p+8,2));}p+=8U+(uint64_t)z;}MM_NEED(index);for(uint32_t i=0;i<len/9;i++){MM_NEED(sxmm_u32(c,index+(uint64_t)i*9+5,true,&z)&&z>=p&&sxmm_add(c,&sxmm_pff2_glyph,z,10));}return true;}
    case XX_FILE_TYPE_SFNT_COLLECTION:{uint32_t ver;MM_NEED(sxmm_read(c,0,h,12)&&!xx_rt_memcmp(h,"ttcf",4));ver=MM_U32(h+4,true);count=MM_U32(h+8,true);MM_NEED(count&&count<=256&&(ver==0x10000||ver==0x20000)&&sxmm_add(c,&sxmm_ttc_header,0,12)&&sxmm_table(c,&sxmm_ttc_font_offset,12,4,count));p=12U+(uint64_t)count*4;if(ver==0x20000){MM_NEED(sxmm_add(c,&sxmm_ttc_dsig,p,12));p+=12;}for(uint32_t i=0;i<count;i++){MM_NEED(sxmm_u32(c,12U+(uint64_t)i*4,true,&z)&&z>=p&&sxmm_read(c,z,h,12));uint32_t n=MM_U16(h+4,true);MM_NEED(n&&n<=4095&&sxmm_add(c,&sxmm_ttc_sfnt,z,12)&&sxmm_table(c,&sxmm_ttc_table,(uint64_t)z+12,16,n));}return true;}
    default:return false;
    }
}
static bool sx_multimedia_build(sx_context *c){return sxmm_build(c)&&sxmm_finish(c);}
static bool sx_multimedia_comment(xx_data_struct_record *r,uint32_t id)
{
    if(id<UINT32_C(0x600B0000)||id>=UINT32_C(0x600C0000)||!r||!r->name)return true;
    const wchar_t *n=r->name;
    if(!xx_rt_wcscmp(n,L"vox_offset")&&(id==sxmm_nifti1_header_le.id||id==sxmm_nifti1_header_be.id)){
        double value=xx_var_get_double(&r->value);if(value>=0.0&&value<9223372036854775808.0){char a[32];wchar_t w[32];uint64_t v=(uint64_t)value;if((double)v==value){int k=xx_rt_snprintf(a,sizeof(a),"0x%llX",(unsigned long long)v);if(k<0||k>=(int)sizeof(a))return false;for(int i=0;i<=k;i++)w[i]=(unsigned char)a[i];if(!xx_data_struct_record_set_display_value(r,w))return false;}}
        return xx_data_struct_record_set_comment(r,L"File offset stored as an IEEE-754 binary32 value");
    }
    if(!xx_rt_wcscmp(n,L"bitpix")||!xx_rt_wcscmp(n,L"pixel_depth")||!xx_rt_wcscmp(n,L"bits_per_sample"))return xx_data_struct_record_set_comment(r,L"Bits per voxel or sample");
    if(!xx_rt_wcscmp(n,L"width_words"))return xx_data_struct_record_set_comment(r,L"Width in 16-bit words");
    if(!xx_rt_wcscmp(n,L"duration_ms")||!xx_rt_wcscmp(n,L"delay_ms"))return xx_data_struct_record_set_comment(r,L"Milliseconds");
    if(!xx_rt_wcscmp(n,L"ntsc_speed_us")||!xx_rt_wcscmp(n,L"pal_speed_us"))return xx_data_struct_record_set_comment(r,L"Playback interval in microseconds");
    if(!xx_rt_wcscmp(n,L"clock_hz")||!xx_rt_wcscmp(n,L"master_clock_hz")||!xx_rt_wcscmp(n,L"frame_rate_hz"))return xx_data_struct_record_set_comment(r,L"Hertz");
    if(!xx_rt_wcscmp(n,L"base16_real"))return xx_data_struct_record_set_comment(r,L"GDSII sign/exponent and base-16 mantissa encoding; raw bytes retained");
    if(!xx_rt_wcscmp(n,L"length_or_value"))return xx_data_struct_record_set_comment(r,L"Inline integer when type is zero; payload byte length otherwise");
    if(!xx_rt_wcscmp(n,L"start_page")||!xx_rt_wcscmp(n,L"page_length"))return xx_data_struct_record_set_comment(r,L"Encoded 256-byte page value");
    if(!xx_rt_wcscmp(n,L"dna_size")||!xx_rt_wcscmp(n,L"base_count")||!xx_rt_wcscmp(n,L"base_index"))return xx_data_struct_record_set_comment(r,L"DNA base count or zero-based base index");
    if(id==sxmm_ser_timestamp.id||(!xx_rt_wcscmp(n,L"date_time")||!xx_rt_wcscmp(n,L"date_time_utc")))return xx_data_struct_record_set_comment(r,L"100-nanosecond ticks since 0001-01-01");
    if(id==sxmm_gds_record.id&&!xx_rt_wcscmp(n,L"data_type")){static const wchar_t *const names[]={L"NO_DATA",L"BIT_ARRAY",L"INTEGER_2",L"INTEGER_4",L"REAL_4",L"REAL_8",L"ASCII"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names))return xx_data_struct_record_set_comment(r,names[v]);}
    if(id==sxmm_gds_record.id&&!xx_rt_wcscmp(n,L"record_type")){static const wchar_t *const names[]={L"HEADER",L"BGNLIB",L"LIBNAME",L"UNITS",L"ENDLIB",L"BGNSTR",L"STRNAME",L"ENDSTR",L"BOUNDARY",L"PATH",L"SREF",L"AREF",L"TEXT",L"LAYER",L"DATATYPE",L"WIDTH",L"XY",L"ENDEL",L"SNAME",L"COLROW",NULL,L"NODE",L"TEXTTYPE",L"PRESENTATION",NULL,L"STRING",L"STRANS",L"MAG",L"ANGLE",NULL,NULL,NULL,NULL,L"PATHTYPE",NULL,NULL,NULL,NULL,L"ELFLAGS",NULL,NULL,NULL,L"NODETYPE",L"PROPATTR",L"PROPVALUE",L"BOX",L"BOXTYPE",L"PLEX",L"BGNEXTN",L"ENDEXTN"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names)&&names[v])return xx_data_struct_record_set_comment(r,names[v]);}
    if((id==sxmm_aco_color.id||id==sxmm_aco_lab_color.id)&&!xx_rt_wcscmp(n,L"color_space")){uint64_t v=xx_var_get_u64(&r->value);const wchar_t *s=v==0?L"RGB":v==1?L"HSB":v==2?L"CMYK":v==7?L"Lab":v==8?L"Grayscale":NULL;if(s)return xx_data_struct_record_set_comment(r,s);}
    if(!xx_rt_wcscmp(n,L"length_sentinel"))return xx_data_struct_record_set_comment(r,L"0xFFFFFFFF means glyph data continues to end of file");
    if(!xx_rt_wcscmp(n,L"next_block_relative_offset"))return xx_data_struct_record_set_comment(r,L"Offset relative to the current bitmap record; zero ends the attachment chain");
    if(!xx_rt_wcscmp(n,L"seconds"))return xx_data_struct_record_set_comment(r,L"Seconds");
    if((id==sxmm_nifti1_header_le.id||id==sxmm_nifti1_header_be.id||id==sxmm_nifti2_header_le.id||id==sxmm_nifti2_header_be.id)&&!xx_rt_wcscmp(n,L"datatype")){
        uint64_t v=xx_var_get_u64(&r->value);const wchar_t *s=v==2?L"NIFTI_TYPE_UINT8":v==4?L"NIFTI_TYPE_INT16":v==8?L"NIFTI_TYPE_INT32":v==16?L"NIFTI_TYPE_FLOAT32":v==32?L"NIFTI_TYPE_COMPLEX64":v==64?L"NIFTI_TYPE_FLOAT64":v==128?L"NIFTI_TYPE_RGB24":v==256?L"NIFTI_TYPE_INT8":v==512?L"NIFTI_TYPE_UINT16":v==768?L"NIFTI_TYPE_UINT32":v==1024?L"NIFTI_TYPE_INT64":v==1280?L"NIFTI_TYPE_UINT64":v==1536?L"NIFTI_TYPE_FLOAT128":v==1792?L"NIFTI_TYPE_COMPLEX128":v==2048?L"NIFTI_TYPE_COMPLEX256":v==2304?L"NIFTI_TYPE_RGBA32":NULL;if(s)return xx_data_struct_record_set_comment(r,s);
    }
    if((id==sxmm_gipl_header_le.id||id==sxmm_gipl_header_be.id)&&!xx_rt_wcscmp(n,L"image_type")){uint64_t v=xx_var_get_u64(&r->value);const wchar_t *s=v==7?L"GIPL_CHAR":v==8?L"GIPL_U_CHAR":v==15?L"GIPL_SHORT":v==16?L"GIPL_U_SHORT":v==31?L"GIPL_U_INT":v==32?L"GIPL_INT":v==64?L"GIPL_FLOAT":v==65?L"GIPL_DOUBLE":NULL;if(s)return xx_data_struct_record_set_comment(r,s);}
    if(!xx_rt_wcscmp(n,L"init_address")||!xx_rt_wcscmp(n,L"play_address")||!xx_rt_wcscmp(n,L"load_address"))return xx_data_struct_record_set_comment(r,L"Address in the emulated machine address space");
    return true;
}
#undef MM_PAIR
#undef MM_U64
#undef MM_U32
#undef MM_U16
#undef MM_NEED
