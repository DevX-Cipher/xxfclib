/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_videotail_scope.txt. */
static const xx_data_struct_field_desc sxvt_grasp_header_fields[] = {
 SX_FIELD("index_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxvt_grasp_header = {UINT32_C(0x60390001),"grasp_header",sxvt_grasp_header_fields,SX_COUNT(sxvt_grasp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_grasp_entry_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name","char[13]",4,13,SX_STRING),
};
static const sx_layout sxvt_grasp_entry = {UINT32_C(0x60390002),"grasp_entry",sxvt_grasp_entry_fields,SX_COUNT(sxvt_grasp_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_grasp_member_size_fields[] = {
 SX_FIELD("member_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxvt_grasp_member_size = {UINT32_C(0x60390003),"grasp_member_size",sxvt_grasp_member_size_fields,SX_COUNT(sxvt_grasp_member_size_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_header_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("uncompressed_file_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxvt_swf_header = {UINT32_C(0x60390004),"swf_header",sxvt_swf_header_fields,SX_COUNT(sxvt_swf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_lzma_header_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("lc_lp_pb","uint8",4,1,SX_FLAGS),
 SX_FIELD("dictionary_size","uint32",5,4,SX_SIZE),
};
static const sx_layout sxvt_swf_lzma_header = {UINT32_C(0x60390005),"swf_lzma_header",sxvt_swf_lzma_header_fields,SX_COUNT(sxvt_swf_lzma_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect1_fields[] = {
 SX_FIELD("encoded_rect","uint8[1]",0,1,SX_NONE),
};
static const sx_layout sxvt_swf_rect1 = {UINT32_C(0x60390006),"swf_rect1",sxvt_swf_rect1_fields,SX_COUNT(sxvt_swf_rect1_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect2_fields[] = {
 SX_FIELD("encoded_rect","uint8[2]",0,2,SX_NONE),
};
static const sx_layout sxvt_swf_rect2 = {UINT32_C(0x60390007),"swf_rect2",sxvt_swf_rect2_fields,SX_COUNT(sxvt_swf_rect2_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect3_fields[] = {
 SX_FIELD("encoded_rect","uint8[3]",0,3,SX_NONE),
};
static const sx_layout sxvt_swf_rect3 = {UINT32_C(0x60390008),"swf_rect3",sxvt_swf_rect3_fields,SX_COUNT(sxvt_swf_rect3_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect4_fields[] = {
 SX_FIELD("encoded_rect","uint8[4]",0,4,SX_NONE),
};
static const sx_layout sxvt_swf_rect4 = {UINT32_C(0x60390009),"swf_rect4",sxvt_swf_rect4_fields,SX_COUNT(sxvt_swf_rect4_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect5_fields[] = {
 SX_FIELD("encoded_rect","uint8[5]",0,5,SX_NONE),
};
static const sx_layout sxvt_swf_rect5 = {UINT32_C(0x6039000a),"swf_rect5",sxvt_swf_rect5_fields,SX_COUNT(sxvt_swf_rect5_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect6_fields[] = {
 SX_FIELD("encoded_rect","uint8[6]",0,6,SX_NONE),
};
static const sx_layout sxvt_swf_rect6 = {UINT32_C(0x6039000b),"swf_rect6",sxvt_swf_rect6_fields,SX_COUNT(sxvt_swf_rect6_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect7_fields[] = {
 SX_FIELD("encoded_rect","uint8[7]",0,7,SX_NONE),
};
static const sx_layout sxvt_swf_rect7 = {UINT32_C(0x6039000c),"swf_rect7",sxvt_swf_rect7_fields,SX_COUNT(sxvt_swf_rect7_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect8_fields[] = {
 SX_FIELD("encoded_rect","uint8[8]",0,8,SX_NONE),
};
static const sx_layout sxvt_swf_rect8 = {UINT32_C(0x6039000d),"swf_rect8",sxvt_swf_rect8_fields,SX_COUNT(sxvt_swf_rect8_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect9_fields[] = {
 SX_FIELD("encoded_rect","uint8[9]",0,9,SX_NONE),
};
static const sx_layout sxvt_swf_rect9 = {UINT32_C(0x6039000e),"swf_rect9",sxvt_swf_rect9_fields,SX_COUNT(sxvt_swf_rect9_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect10_fields[] = {
 SX_FIELD("encoded_rect","uint8[10]",0,10,SX_NONE),
};
static const sx_layout sxvt_swf_rect10 = {UINT32_C(0x6039000f),"swf_rect10",sxvt_swf_rect10_fields,SX_COUNT(sxvt_swf_rect10_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect11_fields[] = {
 SX_FIELD("encoded_rect","uint8[11]",0,11,SX_NONE),
};
static const sx_layout sxvt_swf_rect11 = {UINT32_C(0x60390010),"swf_rect11",sxvt_swf_rect11_fields,SX_COUNT(sxvt_swf_rect11_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect12_fields[] = {
 SX_FIELD("encoded_rect","uint8[12]",0,12,SX_NONE),
};
static const sx_layout sxvt_swf_rect12 = {UINT32_C(0x60390011),"swf_rect12",sxvt_swf_rect12_fields,SX_COUNT(sxvt_swf_rect12_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect13_fields[] = {
 SX_FIELD("encoded_rect","uint8[13]",0,13,SX_NONE),
};
static const sx_layout sxvt_swf_rect13 = {UINT32_C(0x60390012),"swf_rect13",sxvt_swf_rect13_fields,SX_COUNT(sxvt_swf_rect13_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect14_fields[] = {
 SX_FIELD("encoded_rect","uint8[14]",0,14,SX_NONE),
};
static const sx_layout sxvt_swf_rect14 = {UINT32_C(0x60390013),"swf_rect14",sxvt_swf_rect14_fields,SX_COUNT(sxvt_swf_rect14_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect15_fields[] = {
 SX_FIELD("encoded_rect","uint8[15]",0,15,SX_NONE),
};
static const sx_layout sxvt_swf_rect15 = {UINT32_C(0x60390014),"swf_rect15",sxvt_swf_rect15_fields,SX_COUNT(sxvt_swf_rect15_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect16_fields[] = {
 SX_FIELD("encoded_rect","uint8[16]",0,16,SX_NONE),
};
static const sx_layout sxvt_swf_rect16 = {UINT32_C(0x60390015),"swf_rect16",sxvt_swf_rect16_fields,SX_COUNT(sxvt_swf_rect16_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect17_fields[] = {
 SX_FIELD("encoded_rect","uint8[17]",0,17,SX_NONE),
};
static const sx_layout sxvt_swf_rect17 = {UINT32_C(0x60390016),"swf_rect17",sxvt_swf_rect17_fields,SX_COUNT(sxvt_swf_rect17_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_movie_fields[] = {
 SX_FIELD("frame_rate_fixed8","uint16",0,2,SX_NONE),
 SX_FIELD("frame_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxvt_swf_movie = {UINT32_C(0x60390017),"swf_movie",sxvt_swf_movie_fields,SX_COUNT(sxvt_swf_movie_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_tag_short_fields[] = {
 SX_FIELD("code_and_length","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxvt_swf_tag_short = {UINT32_C(0x60390018),"swf_tag_short",sxvt_swf_tag_short_fields,SX_COUNT(sxvt_swf_tag_short_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_tag_long_fields[] = {
 SX_FIELD("code_and_length","uint16",0,2,SX_FLAGS),
 SX_FIELD("body_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxvt_swf_tag_long = {UINT32_C(0x60390019),"swf_tag_long",sxvt_swf_tag_long_fields,SX_COUNT(sxvt_swf_tag_long_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_sprite_fields[] = {
 SX_FIELD("sprite_id","uint16",0,2,SX_ID),
 SX_FIELD("frame_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxvt_swf_sprite = {UINT32_C(0x6039001a),"swf_sprite",sxvt_swf_sprite_fields,SX_COUNT(sxvt_swf_sprite_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_background_fields[] = {
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
};
static const sx_layout sxvt_swf_background = {UINT32_C(0x6039001b),"swf_background",sxvt_swf_background_fields,SX_COUNT(sxvt_swf_background_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_character_id_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
};
static const sx_layout sxvt_swf_character_id = {UINT32_C(0x6039001c),"swf_character_id",sxvt_swf_character_id_fields,SX_COUNT(sxvt_swf_character_id_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_jpeg3_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
 SX_FIELD("alpha_data_offset","uint32",2,4,SX_OFFSET),
};
static const sx_layout sxvt_swf_jpeg3 = {UINT32_C(0x6039001d),"swf_jpeg3",sxvt_swf_jpeg3_fields,SX_COUNT(sxvt_swf_jpeg3_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_jpeg4_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
 SX_FIELD("alpha_data_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("deblock_fixed8","uint16",6,2,SX_NONE),
};
static const sx_layout sxvt_swf_jpeg4 = {UINT32_C(0x6039001e),"swf_jpeg4",sxvt_swf_jpeg4_fields,SX_COUNT(sxvt_swf_jpeg4_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_lossless_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
 SX_FIELD("bitmap_format","uint8",2,1,SX_ID),
 SX_FIELD("width","uint16",3,2,SX_NONE),
 SX_FIELD("height","uint16",5,2,SX_NONE),
};
static const sx_layout sxvt_swf_lossless = {UINT32_C(0x6039001f),"swf_lossless",sxvt_swf_lossless_fields,SX_COUNT(sxvt_swf_lossless_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_palette_count_fields[] = {
 SX_FIELD("palette_count_minus_one","uint8",0,1,SX_NONE),
};
static const sx_layout sxvt_swf_palette_count = {UINT32_C(0x60390020),"swf_palette_count",sxvt_swf_palette_count_fields,SX_COUNT(sxvt_swf_palette_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_sound_fields[] = {
 SX_FIELD("sound_id","uint16",0,2,SX_ID),
 SX_FIELD("sound_format_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("sample_count","uint32",3,4,SX_COUNT_PROP),
};
static const sx_layout sxvt_swf_sound = {UINT32_C(0x60390021),"swf_sound",sxvt_swf_sound_fields,SX_COUNT(sxvt_swf_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_mp3_seek_fields[] = {
 SX_FIELD("seek_samples","int16",0,2,SX_NONE),
};
static const sx_layout sxvt_swf_mp3_seek = {UINT32_C(0x60390022),"swf_mp3_seek",sxvt_swf_mp3_seek_fields,SX_COUNT(sxvt_swf_mp3_seek_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_stream_sound_fields[] = {
 SX_FIELD("playback_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("stream_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("sample_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxvt_swf_stream_sound = {UINT32_C(0x60390023),"swf_stream_sound",sxvt_swf_stream_sound_fields,SX_COUNT(sxvt_swf_stream_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_binary_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
 SX_FIELD("reserved","uint32",2,4,SX_RESERVED),
};
static const sx_layout sxvt_swf_binary = {UINT32_C(0x60390024),"swf_binary",sxvt_swf_binary_fields,SX_COUNT(sxvt_swf_binary_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_file_attributes_fields[] = {
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxvt_swf_file_attributes = {UINT32_C(0x60390025),"swf_file_attributes",sxvt_swf_file_attributes_fields,SX_COUNT(sxvt_swf_file_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_header_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form","char[4]",8,4,SX_ID),
};
static const sx_layout sxvt_director_header_le = {UINT32_C(0x60390026),"director_header_le",sxvt_director_header_le_fields,SX_COUNT(sxvt_director_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_chunk_le_fields[] = {
 SX_FIELD("type","char[4]",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxvt_director_chunk_le = {UINT32_C(0x60390027),"director_chunk_le",sxvt_director_chunk_le_fields,SX_COUNT(sxvt_director_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_header_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form","char[4]",8,4,SX_ID),
};
static const sx_layout sxvt_director_header_be = {UINT32_C(0x60390028),"director_header_be",sxvt_director_header_be_fields,SX_COUNT(sxvt_director_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_chunk_be_fields[] = {
 SX_FIELD("type","char[4]",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxvt_director_chunk_be = {UINT32_C(0x60390029),"director_chunk_be",sxvt_director_chunk_be_fields,SX_COUNT(sxvt_director_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_box_fields[] = {
 SX_FIELD("box_size","uint32",0,4,SX_SIZE),
 SX_FIELD("type","char[4]",4,4,SX_ID),
};
static const sx_layout sxvt_mp4_box = {UINT32_C(0x6039002a),"mp4_box",sxvt_mp4_box_fields,SX_COUNT(sxvt_mp4_box_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_box64_fields[] = {
 SX_FIELD("box_size","uint32",0,4,SX_NONE),
 SX_FIELD("type","char[4]",4,4,SX_ID),
 SX_FIELD("extended_size","uint64",8,8,SX_SIZE),
};
static const sx_layout sxvt_mp4_box64 = {UINT32_C(0x6039002b),"mp4_box64",sxvt_mp4_box64_fields,SX_COUNT(sxvt_mp4_box64_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_uuid_fields[] = {
 SX_FIELD("user_type","uint8[16]",0,16,SX_ID),
};
static const sx_layout sxvt_mp4_uuid = {UINT32_C(0x6039002c),"mp4_uuid",sxvt_mp4_uuid_fields,SX_COUNT(sxvt_mp4_uuid_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_ftyp_fields[] = {
 SX_FIELD("major_brand","char[4]",0,4,SX_ID),
 SX_FIELD("minor_version","uint32",4,4,SX_ID),
};
static const sx_layout sxvt_mp4_ftyp = {UINT32_C(0x6039002d),"mp4_ftyp",sxvt_mp4_ftyp_fields,SX_COUNT(sxvt_mp4_ftyp_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_brand_fields[] = {
 SX_FIELD("compatible_brand","char[4]",0,4,SX_ID),
};
static const sx_layout sxvt_mp4_brand = {UINT32_C(0x6039002e),"mp4_brand",sxvt_mp4_brand_fields,SX_COUNT(sxvt_mp4_brand_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_mvhd_v0_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint32",4,4,SX_NONE),
 SX_FIELD("modification_time","uint32",8,4,SX_NONE),
 SX_FIELD("timescale","uint32",12,4,SX_NONE),
 SX_FIELD("duration","uint32",16,4,SX_NONE),
 SX_FIELD("rate_fixed16","int32",20,4,SX_NONE),
 SX_FIELD("volume_fixed8","int16",24,2,SX_NONE),
 SX_FIELD("reserved0","uint16",26,2,SX_RESERVED),
 SX_FIELD("reserved1","uint32[2]",28,8,SX_RESERVED),
 SX_FIELD("matrix","int32[9]",36,36,SX_NONE),
 SX_FIELD("pre_defined","uint32[6]",72,24,SX_RESERVED),
 SX_FIELD("next_track_id","uint32",96,4,SX_ID),
};
static const sx_layout sxvt_mp4_mvhd_v0 = {UINT32_C(0x6039002f),"mp4_mvhd_v0",sxvt_mp4_mvhd_v0_fields,SX_COUNT(sxvt_mp4_mvhd_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_tkhd_v0_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint32",4,4,SX_NONE),
 SX_FIELD("modification_time","uint32",8,4,SX_NONE),
 SX_FIELD("track_id","uint32",12,4,SX_ID),
 SX_FIELD("reserved0","uint32",16,4,SX_RESERVED),
 SX_FIELD("duration","uint32",20,4,SX_NONE),
 SX_FIELD("reserved1","uint32[2]",24,8,SX_RESERVED),
 SX_FIELD("layer","int16",32,2,SX_NONE),
 SX_FIELD("alternate_group","int16",34,2,SX_ID),
 SX_FIELD("volume_fixed8","int16",36,2,SX_NONE),
 SX_FIELD("reserved2","uint16",38,2,SX_RESERVED),
 SX_FIELD("matrix","int32[9]",40,36,SX_NONE),
 SX_FIELD("width_fixed16","uint32",76,4,SX_NONE),
 SX_FIELD("height_fixed16","uint32",80,4,SX_NONE),
};
static const sx_layout sxvt_mp4_tkhd_v0 = {UINT32_C(0x60390030),"mp4_tkhd_v0",sxvt_mp4_tkhd_v0_fields,SX_COUNT(sxvt_mp4_tkhd_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_mdhd_v0_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint32",4,4,SX_NONE),
 SX_FIELD("modification_time","uint32",8,4,SX_NONE),
 SX_FIELD("timescale","uint32",12,4,SX_NONE),
 SX_FIELD("duration","uint32",16,4,SX_NONE),
 SX_FIELD("language","uint16",20,2,SX_FLAGS),
 SX_FIELD("pre_defined","uint16",22,2,SX_RESERVED),
};
static const sx_layout sxvt_mp4_mdhd_v0 = {UINT32_C(0x60390031),"mp4_mdhd_v0",sxvt_mp4_mdhd_v0_fields,SX_COUNT(sxvt_mp4_mdhd_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_elst_entry_v0_fields[] = {
 SX_FIELD("segment_duration","uint32",0,4,SX_NONE),
 SX_FIELD("media_time","int32",4,4,SX_NONE),
 SX_FIELD("media_rate_integer","int16",8,2,SX_NONE),
 SX_FIELD("media_rate_fraction","int16",10,2,SX_NONE),
};
static const sx_layout sxvt_mp4_elst_entry_v0 = {UINT32_C(0x60390032),"mp4_elst_entry_v0",sxvt_mp4_elst_entry_v0_fields,SX_COUNT(sxvt_mp4_elst_entry_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_mvhd_v1_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint64",4,8,SX_NONE),
 SX_FIELD("modification_time","uint64",12,8,SX_NONE),
 SX_FIELD("timescale","uint32",20,4,SX_NONE),
 SX_FIELD("duration","uint64",24,8,SX_NONE),
 SX_FIELD("rate_fixed16","int32",32,4,SX_NONE),
 SX_FIELD("volume_fixed8","int16",36,2,SX_NONE),
 SX_FIELD("reserved0","uint16",38,2,SX_RESERVED),
 SX_FIELD("reserved1","uint32[2]",40,8,SX_RESERVED),
 SX_FIELD("matrix","int32[9]",48,36,SX_NONE),
 SX_FIELD("pre_defined","uint32[6]",84,24,SX_RESERVED),
 SX_FIELD("next_track_id","uint32",108,4,SX_ID),
};
static const sx_layout sxvt_mp4_mvhd_v1 = {UINT32_C(0x60390033),"mp4_mvhd_v1",sxvt_mp4_mvhd_v1_fields,SX_COUNT(sxvt_mp4_mvhd_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_tkhd_v1_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint64",4,8,SX_NONE),
 SX_FIELD("modification_time","uint64",12,8,SX_NONE),
 SX_FIELD("track_id","uint32",20,4,SX_ID),
 SX_FIELD("reserved0","uint32",24,4,SX_RESERVED),
 SX_FIELD("duration","uint64",28,8,SX_NONE),
 SX_FIELD("reserved1","uint32[2]",36,8,SX_RESERVED),
 SX_FIELD("layer","int16",44,2,SX_NONE),
 SX_FIELD("alternate_group","int16",46,2,SX_ID),
 SX_FIELD("volume_fixed8","int16",48,2,SX_NONE),
 SX_FIELD("reserved2","uint16",50,2,SX_RESERVED),
 SX_FIELD("matrix","int32[9]",52,36,SX_NONE),
 SX_FIELD("width_fixed16","uint32",88,4,SX_NONE),
 SX_FIELD("height_fixed16","uint32",92,4,SX_NONE),
};
static const sx_layout sxvt_mp4_tkhd_v1 = {UINT32_C(0x60390034),"mp4_tkhd_v1",sxvt_mp4_tkhd_v1_fields,SX_COUNT(sxvt_mp4_tkhd_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_mdhd_v1_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("creation_time","uint64",4,8,SX_NONE),
 SX_FIELD("modification_time","uint64",12,8,SX_NONE),
 SX_FIELD("timescale","uint32",20,4,SX_NONE),
 SX_FIELD("duration","uint64",24,8,SX_NONE),
 SX_FIELD("language","uint16",32,2,SX_FLAGS),
 SX_FIELD("pre_defined","uint16",34,2,SX_RESERVED),
};
static const sx_layout sxvt_mp4_mdhd_v1 = {UINT32_C(0x60390035),"mp4_mdhd_v1",sxvt_mp4_mdhd_v1_fields,SX_COUNT(sxvt_mp4_mdhd_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_elst_entry_v1_fields[] = {
 SX_FIELD("segment_duration","uint64",0,8,SX_NONE),
 SX_FIELD("media_time","int64",8,8,SX_NONE),
 SX_FIELD("media_rate_integer","int16",16,2,SX_NONE),
 SX_FIELD("media_rate_fraction","int16",18,2,SX_NONE),
};
static const sx_layout sxvt_mp4_elst_entry_v1 = {UINT32_C(0x60390036),"mp4_elst_entry_v1",sxvt_mp4_elst_entry_v1_fields,SX_COUNT(sxvt_mp4_elst_entry_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_hdlr_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("pre_defined","uint32",4,4,SX_NONE),
 SX_FIELD("handler_type","char[4]",8,4,SX_ID),
 SX_FIELD("reserved","uint32[3]",12,12,SX_RESERVED),
};
static const sx_layout sxvt_mp4_hdlr = {UINT32_C(0x60390037),"mp4_hdlr",sxvt_mp4_hdlr_fields,SX_COUNT(sxvt_mp4_hdlr_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_table_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxvt_mp4_table = {UINT32_C(0x60390038),"mp4_table",sxvt_mp4_table_fields,SX_COUNT(sxvt_mp4_table_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stsz_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("sample_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sample_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxvt_mp4_stsz = {UINT32_C(0x60390039),"mp4_stsz",sxvt_mp4_stsz_fields,SX_COUNT(sxvt_mp4_stsz_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stco_fields[] = {
 SX_FIELD("chunk_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxvt_mp4_stco = {UINT32_C(0x6039003a),"mp4_stco",sxvt_mp4_stco_fields,SX_COUNT(sxvt_mp4_stco_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_co64_fields[] = {
 SX_FIELD("chunk_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxvt_mp4_co64 = {UINT32_C(0x6039003b),"mp4_co64",sxvt_mp4_co64_fields,SX_COUNT(sxvt_mp4_co64_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stts_fields[] = {
 SX_FIELD("sample_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("sample_delta","uint32",4,4,SX_NONE),
};
static const sx_layout sxvt_mp4_stts = {UINT32_C(0x6039003c),"mp4_stts",sxvt_mp4_stts_fields,SX_COUNT(sxvt_mp4_stts_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_ctts_v0_fields[] = {
 SX_FIELD("sample_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("sample_offset","uint32",4,4,SX_NONE),
};
static const sx_layout sxvt_mp4_ctts_v0 = {UINT32_C(0x6039003d),"mp4_ctts_v0",sxvt_mp4_ctts_v0_fields,SX_COUNT(sxvt_mp4_ctts_v0_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_ctts_v1_fields[] = {
 SX_FIELD("sample_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("sample_offset","int32",4,4,SX_NONE),
};
static const sx_layout sxvt_mp4_ctts_v1 = {UINT32_C(0x6039003e),"mp4_ctts_v1",sxvt_mp4_ctts_v1_fields,SX_COUNT(sxvt_mp4_ctts_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stsc_fields[] = {
 SX_FIELD("first_chunk","uint32",0,4,SX_ID),
 SX_FIELD("samples_per_chunk","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("sample_description_index","uint32",8,4,SX_ID),
};
static const sx_layout sxvt_mp4_stsc = {UINT32_C(0x6039003f),"mp4_stsc",sxvt_mp4_stsc_fields,SX_COUNT(sxvt_mp4_stsc_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_stss_fields[] = {
 SX_FIELD("sample_number","uint32",0,4,SX_ID),
};
static const sx_layout sxvt_mp4_stss = {UINT32_C(0x60390040),"mp4_stss",sxvt_mp4_stss_fields,SX_COUNT(sxvt_mp4_stss_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_sample_size_fields[] = {
 SX_FIELD("sample_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxvt_mp4_sample_size = {UINT32_C(0x60390041),"mp4_sample_size",sxvt_mp4_sample_size_fields,SX_COUNT(sxvt_mp4_sample_size_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_sample_entry_fields[] = {
 SX_FIELD("reserved","uint8[6]",0,6,SX_RESERVED),
 SX_FIELD("data_reference_index","uint16",6,2,SX_ID),
};
static const sx_layout sxvt_mp4_sample_entry = {UINT32_C(0x60390042),"mp4_sample_entry",sxvt_mp4_sample_entry_fields,SX_COUNT(sxvt_mp4_sample_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_vmhd_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("graphics_mode","uint16",4,2,SX_ID),
 SX_FIELD("opcolour","uint16[3]",6,6,SX_NONE),
};
static const sx_layout sxvt_mp4_vmhd = {UINT32_C(0x60390043),"mp4_vmhd",sxvt_mp4_vmhd_fields,SX_COUNT(sxvt_mp4_vmhd_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_smhd_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
 SX_FIELD("balance_fixed8","int16",4,2,SX_NONE),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
};
static const sx_layout sxvt_mp4_smhd = {UINT32_C(0x60390044),"mp4_smhd",sxvt_mp4_smhd_fields,SX_COUNT(sxvt_mp4_smhd_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_mp4_fullbox_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint24",1,3,SX_FLAGS),
};
static const sx_layout sxvt_mp4_fullbox = {UINT32_C(0x60390045),"mp4_fullbox",sxvt_mp4_fullbox_fields,SX_COUNT(sxvt_mp4_fullbox_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_id1_fields[] = {
 SX_FIELD("element_id","uint8",0,1,SX_ID),
};
static const sx_layout sxvt_ebml_id1 = {UINT32_C(0x60390046),"ebml_id1",sxvt_ebml_id1_fields,SX_COUNT(sxvt_ebml_id1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_id2_fields[] = {
 SX_FIELD("element_id","uint16",0,2,SX_ID),
};
static const sx_layout sxvt_ebml_id2 = {UINT32_C(0x60390047),"ebml_id2",sxvt_ebml_id2_fields,SX_COUNT(sxvt_ebml_id2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_id3_fields[] = {
 SX_FIELD("element_id","uint24",0,3,SX_ID),
};
static const sx_layout sxvt_ebml_id3 = {UINT32_C(0x60390048),"ebml_id3",sxvt_ebml_id3_fields,SX_COUNT(sxvt_ebml_id3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_id4_fields[] = {
 SX_FIELD("element_id","uint32",0,4,SX_ID),
};
static const sx_layout sxvt_ebml_id4 = {UINT32_C(0x60390049),"ebml_id4",sxvt_ebml_id4_fields,SX_COUNT(sxvt_ebml_id4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size1_fields[] = {
 SX_FIELD("encoded_size","uint8",0,1,SX_NONE),
};
static const sx_layout sxvt_ebml_size1 = {UINT32_C(0x6039004a),"ebml_size1",sxvt_ebml_size1_fields,SX_COUNT(sxvt_ebml_size1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track1_fields[] = {
 SX_FIELD("encoded_track","uint8",0,1,SX_NONE),
};
static const sx_layout sxvt_matroska_track1 = {UINT32_C(0x6039004b),"matroska_track1",sxvt_matroska_track1_fields,SX_COUNT(sxvt_matroska_track1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size1_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint8",0,1,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_size1 = {UINT32_C(0x6039004c),"matroska_lace_size1",sxvt_matroska_lace_size1_fields,SX_COUNT(sxvt_matroska_lace_size1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta1_fields[] = {
 SX_FIELD("encoded_size_delta","uint8",0,1,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_delta1 = {UINT32_C(0x6039004d),"matroska_lace_delta1",sxvt_matroska_lace_delta1_fields,SX_COUNT(sxvt_matroska_lace_delta1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint1_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxvt_matroska_uint1 = {UINT32_C(0x6039004e),"matroska_uint1",sxvt_matroska_uint1_fields,SX_COUNT(sxvt_matroska_uint1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset1_fields[] = {
 SX_FIELD("relative_offset","uint8",0,1,SX_OFFSET),
};
static const sx_layout sxvt_matroska_offset1 = {UINT32_C(0x6039004f),"matroska_offset1",sxvt_matroska_offset1_fields,SX_COUNT(sxvt_matroska_offset1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size2_fields[] = {
 SX_FIELD("encoded_size","uint16",0,2,SX_NONE),
};
static const sx_layout sxvt_ebml_size2 = {UINT32_C(0x60390050),"ebml_size2",sxvt_ebml_size2_fields,SX_COUNT(sxvt_ebml_size2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track2_fields[] = {
 SX_FIELD("encoded_track","uint16",0,2,SX_NONE),
};
static const sx_layout sxvt_matroska_track2 = {UINT32_C(0x60390051),"matroska_track2",sxvt_matroska_track2_fields,SX_COUNT(sxvt_matroska_track2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size2_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint16",0,2,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_size2 = {UINT32_C(0x60390052),"matroska_lace_size2",sxvt_matroska_lace_size2_fields,SX_COUNT(sxvt_matroska_lace_size2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta2_fields[] = {
 SX_FIELD("encoded_size_delta","uint16",0,2,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_delta2 = {UINT32_C(0x60390053),"matroska_lace_delta2",sxvt_matroska_lace_delta2_fields,SX_COUNT(sxvt_matroska_lace_delta2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint2_fields[] = {
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxvt_matroska_uint2 = {UINT32_C(0x60390054),"matroska_uint2",sxvt_matroska_uint2_fields,SX_COUNT(sxvt_matroska_uint2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset2_fields[] = {
 SX_FIELD("relative_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxvt_matroska_offset2 = {UINT32_C(0x60390055),"matroska_offset2",sxvt_matroska_offset2_fields,SX_COUNT(sxvt_matroska_offset2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size3_fields[] = {
 SX_FIELD("encoded_size","uint24",0,3,SX_NONE),
};
static const sx_layout sxvt_ebml_size3 = {UINT32_C(0x60390056),"ebml_size3",sxvt_ebml_size3_fields,SX_COUNT(sxvt_ebml_size3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track3_fields[] = {
 SX_FIELD("encoded_track","uint24",0,3,SX_NONE),
};
static const sx_layout sxvt_matroska_track3 = {UINT32_C(0x60390057),"matroska_track3",sxvt_matroska_track3_fields,SX_COUNT(sxvt_matroska_track3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size3_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint24",0,3,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_size3 = {UINT32_C(0x60390058),"matroska_lace_size3",sxvt_matroska_lace_size3_fields,SX_COUNT(sxvt_matroska_lace_size3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta3_fields[] = {
 SX_FIELD("encoded_size_delta","uint24",0,3,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_delta3 = {UINT32_C(0x60390059),"matroska_lace_delta3",sxvt_matroska_lace_delta3_fields,SX_COUNT(sxvt_matroska_lace_delta3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint3_fields[] = {
 SX_FIELD("value","uint24",0,3,SX_NONE),
};
static const sx_layout sxvt_matroska_uint3 = {UINT32_C(0x6039005a),"matroska_uint3",sxvt_matroska_uint3_fields,SX_COUNT(sxvt_matroska_uint3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset3_fields[] = {
 SX_FIELD("relative_offset","uint24",0,3,SX_OFFSET),
};
static const sx_layout sxvt_matroska_offset3 = {UINT32_C(0x6039005b),"matroska_offset3",sxvt_matroska_offset3_fields,SX_COUNT(sxvt_matroska_offset3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size4_fields[] = {
 SX_FIELD("encoded_size","uint32",0,4,SX_NONE),
};
static const sx_layout sxvt_ebml_size4 = {UINT32_C(0x6039005c),"ebml_size4",sxvt_ebml_size4_fields,SX_COUNT(sxvt_ebml_size4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track4_fields[] = {
 SX_FIELD("encoded_track","uint32",0,4,SX_NONE),
};
static const sx_layout sxvt_matroska_track4 = {UINT32_C(0x6039005d),"matroska_track4",sxvt_matroska_track4_fields,SX_COUNT(sxvt_matroska_track4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size4_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint32",0,4,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_size4 = {UINT32_C(0x6039005e),"matroska_lace_size4",sxvt_matroska_lace_size4_fields,SX_COUNT(sxvt_matroska_lace_size4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta4_fields[] = {
 SX_FIELD("encoded_size_delta","uint32",0,4,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_delta4 = {UINT32_C(0x6039005f),"matroska_lace_delta4",sxvt_matroska_lace_delta4_fields,SX_COUNT(sxvt_matroska_lace_delta4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint4_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxvt_matroska_uint4 = {UINT32_C(0x60390060),"matroska_uint4",sxvt_matroska_uint4_fields,SX_COUNT(sxvt_matroska_uint4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset4_fields[] = {
 SX_FIELD("relative_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxvt_matroska_offset4 = {UINT32_C(0x60390061),"matroska_offset4",sxvt_matroska_offset4_fields,SX_COUNT(sxvt_matroska_offset4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size5_fields[] = {
 SX_FIELD("encoded_size","uint40",0,5,SX_NONE),
};
static const sx_layout sxvt_ebml_size5 = {UINT32_C(0x60390062),"ebml_size5",sxvt_ebml_size5_fields,SX_COUNT(sxvt_ebml_size5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track5_fields[] = {
 SX_FIELD("encoded_track","uint40",0,5,SX_NONE),
};
static const sx_layout sxvt_matroska_track5 = {UINT32_C(0x60390063),"matroska_track5",sxvt_matroska_track5_fields,SX_COUNT(sxvt_matroska_track5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size5_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint40",0,5,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_size5 = {UINT32_C(0x60390064),"matroska_lace_size5",sxvt_matroska_lace_size5_fields,SX_COUNT(sxvt_matroska_lace_size5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta5_fields[] = {
 SX_FIELD("encoded_size_delta","uint40",0,5,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_delta5 = {UINT32_C(0x60390065),"matroska_lace_delta5",sxvt_matroska_lace_delta5_fields,SX_COUNT(sxvt_matroska_lace_delta5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint5_fields[] = {
 SX_FIELD("value","uint40",0,5,SX_NONE),
};
static const sx_layout sxvt_matroska_uint5 = {UINT32_C(0x60390066),"matroska_uint5",sxvt_matroska_uint5_fields,SX_COUNT(sxvt_matroska_uint5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset5_fields[] = {
 SX_FIELD("relative_offset","uint40",0,5,SX_OFFSET),
};
static const sx_layout sxvt_matroska_offset5 = {UINT32_C(0x60390067),"matroska_offset5",sxvt_matroska_offset5_fields,SX_COUNT(sxvt_matroska_offset5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size6_fields[] = {
 SX_FIELD("encoded_size","uint48",0,6,SX_NONE),
};
static const sx_layout sxvt_ebml_size6 = {UINT32_C(0x60390068),"ebml_size6",sxvt_ebml_size6_fields,SX_COUNT(sxvt_ebml_size6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track6_fields[] = {
 SX_FIELD("encoded_track","uint48",0,6,SX_NONE),
};
static const sx_layout sxvt_matroska_track6 = {UINT32_C(0x60390069),"matroska_track6",sxvt_matroska_track6_fields,SX_COUNT(sxvt_matroska_track6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size6_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint48",0,6,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_size6 = {UINT32_C(0x6039006a),"matroska_lace_size6",sxvt_matroska_lace_size6_fields,SX_COUNT(sxvt_matroska_lace_size6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta6_fields[] = {
 SX_FIELD("encoded_size_delta","uint48",0,6,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_delta6 = {UINT32_C(0x6039006b),"matroska_lace_delta6",sxvt_matroska_lace_delta6_fields,SX_COUNT(sxvt_matroska_lace_delta6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint6_fields[] = {
 SX_FIELD("value","uint48",0,6,SX_NONE),
};
static const sx_layout sxvt_matroska_uint6 = {UINT32_C(0x6039006c),"matroska_uint6",sxvt_matroska_uint6_fields,SX_COUNT(sxvt_matroska_uint6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset6_fields[] = {
 SX_FIELD("relative_offset","uint48",0,6,SX_OFFSET),
};
static const sx_layout sxvt_matroska_offset6 = {UINT32_C(0x6039006d),"matroska_offset6",sxvt_matroska_offset6_fields,SX_COUNT(sxvt_matroska_offset6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size7_fields[] = {
 SX_FIELD("encoded_size","uint56",0,7,SX_NONE),
};
static const sx_layout sxvt_ebml_size7 = {UINT32_C(0x6039006e),"ebml_size7",sxvt_ebml_size7_fields,SX_COUNT(sxvt_ebml_size7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track7_fields[] = {
 SX_FIELD("encoded_track","uint56",0,7,SX_NONE),
};
static const sx_layout sxvt_matroska_track7 = {UINT32_C(0x6039006f),"matroska_track7",sxvt_matroska_track7_fields,SX_COUNT(sxvt_matroska_track7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size7_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint56",0,7,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_size7 = {UINT32_C(0x60390070),"matroska_lace_size7",sxvt_matroska_lace_size7_fields,SX_COUNT(sxvt_matroska_lace_size7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta7_fields[] = {
 SX_FIELD("encoded_size_delta","uint56",0,7,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_delta7 = {UINT32_C(0x60390071),"matroska_lace_delta7",sxvt_matroska_lace_delta7_fields,SX_COUNT(sxvt_matroska_lace_delta7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint7_fields[] = {
 SX_FIELD("value","uint56",0,7,SX_NONE),
};
static const sx_layout sxvt_matroska_uint7 = {UINT32_C(0x60390072),"matroska_uint7",sxvt_matroska_uint7_fields,SX_COUNT(sxvt_matroska_uint7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset7_fields[] = {
 SX_FIELD("relative_offset","uint56",0,7,SX_OFFSET),
};
static const sx_layout sxvt_matroska_offset7 = {UINT32_C(0x60390073),"matroska_offset7",sxvt_matroska_offset7_fields,SX_COUNT(sxvt_matroska_offset7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size8_fields[] = {
 SX_FIELD("encoded_size","uint64",0,8,SX_NONE),
};
static const sx_layout sxvt_ebml_size8 = {UINT32_C(0x60390074),"ebml_size8",sxvt_ebml_size8_fields,SX_COUNT(sxvt_ebml_size8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track8_fields[] = {
 SX_FIELD("encoded_track","uint64",0,8,SX_NONE),
};
static const sx_layout sxvt_matroska_track8 = {UINT32_C(0x60390075),"matroska_track8",sxvt_matroska_track8_fields,SX_COUNT(sxvt_matroska_track8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size8_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint64",0,8,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_size8 = {UINT32_C(0x60390076),"matroska_lace_size8",sxvt_matroska_lace_size8_fields,SX_COUNT(sxvt_matroska_lace_size8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta8_fields[] = {
 SX_FIELD("encoded_size_delta","uint64",0,8,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_delta8 = {UINT32_C(0x60390077),"matroska_lace_delta8",sxvt_matroska_lace_delta8_fields,SX_COUNT(sxvt_matroska_lace_delta8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint8_fields[] = {
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
static const sx_layout sxvt_matroska_uint8 = {UINT32_C(0x60390078),"matroska_uint8",sxvt_matroska_uint8_fields,SX_COUNT(sxvt_matroska_uint8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset8_fields[] = {
 SX_FIELD("relative_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxvt_matroska_offset8 = {UINT32_C(0x60390079),"matroska_offset8",sxvt_matroska_offset8_fields,SX_COUNT(sxvt_matroska_offset8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_date_fields[] = {
 SX_FIELD("nanoseconds_since_2001","int64",0,8,SX_NONE),
};
static const sx_layout sxvt_matroska_date = {UINT32_C(0x6039007a),"matroska_date",sxvt_matroska_date_fields,SX_COUNT(sxvt_matroska_date_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_float4_fields[] = {
 SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxvt_matroska_float4 = {UINT32_C(0x6039007b),"matroska_float4",sxvt_matroska_float4_fields,SX_COUNT(sxvt_matroska_float4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_float8_fields[] = {
 SX_FIELD("value","float64",0,8,SX_NONE),
};
static const sx_layout sxvt_matroska_float8 = {UINT32_C(0x6039007c),"matroska_float8",sxvt_matroska_float8_fields,SX_COUNT(sxvt_matroska_float8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_crc32_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxvt_matroska_crc32 = {UINT32_C(0x6039007d),"matroska_crc32",sxvt_matroska_crc32_fields,SX_COUNT(sxvt_matroska_crc32_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_matroska_block_fields[] = {
 SX_FIELD("relative_timestamp","int16",0,2,SX_NONE),
 SX_FIELD("flags","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxvt_matroska_block = {UINT32_C(0x6039007e),"matroska_block",sxvt_matroska_block_fields,SX_COUNT(sxvt_matroska_block_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_count_fields[] = {
 SX_FIELD("frame_count_minus_one","uint8",0,1,SX_NONE),
};
static const sx_layout sxvt_matroska_lace_count = {UINT32_C(0x6039007f),"matroska_lace_count",sxvt_matroska_lace_count_fields,SX_COUNT(sxvt_matroska_lace_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_matroska_xiph_size_fields[] = {
 SX_FIELD("size_part","uint8",0,1,SX_NONE),
};
static const sx_layout sxvt_matroska_xiph_size = {UINT32_C(0x60390080),"matroska_xiph_size",sxvt_matroska_xiph_size_fields,SX_COUNT(sxvt_matroska_xiph_size_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_imap_le_fields[] = {
 SX_FIELD("map_version","uint32",0,4,SX_ID),
 SX_FIELD("mmap_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("director_version","uint32",8,4,SX_ID),
};
static const sx_layout sxvt_director_imap_le = {UINT32_C(0x60390081),"director_imap_le",sxvt_director_imap_le_fields,SX_COUNT(sxvt_director_imap_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_mmap_le_fields[] = {
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_size","uint16",2,2,SX_SIZE),
 SX_FIELD("allocated_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("used_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint32[2]",12,8,SX_RESERVED),
 SX_FIELD("first_free_resource_id","int32",20,4,SX_ID),
};
static const sx_layout sxvt_director_mmap_le = {UINT32_C(0x60390082),"director_mmap_le",sxvt_director_mmap_le_fields,SX_COUNT(sxvt_director_mmap_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_mmap_entry_le_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("chunk_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("flags","uint16",12,2,SX_FLAGS),
 SX_FIELD("unknown","uint16",14,2,SX_NONE),
 SX_FIELD("next_free_resource_id","uint32",16,4,SX_ID),
};
static const sx_layout sxvt_director_mmap_entry_le = {UINT32_C(0x60390083),"director_mmap_entry_le",sxvt_director_mmap_entry_le_fields,SX_COUNT(sxvt_director_mmap_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_key_le_fields[] = {
 SX_FIELD("entry_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_size_secondary","uint16",2,2,SX_SIZE),
 SX_FIELD("allocated_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("used_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxvt_director_key_le = {UINT32_C(0x60390084),"director_key_le",sxvt_director_key_le_fields,SX_COUNT(sxvt_director_key_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_key_entry_le_fields[] = {
 SX_FIELD("child_resource_index","uint32",0,4,SX_ID),
 SX_FIELD("parent_resource_index","uint32",4,4,SX_ID),
 SX_FIELD("child_type","uint32",8,4,SX_ID),
};
static const sx_layout sxvt_director_key_entry_le = {UINT32_C(0x60390085),"director_key_entry_le",sxvt_director_key_entry_le_fields,SX_COUNT(sxvt_director_key_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_imap_be_fields[] = {
 SX_FIELD("map_version","uint32",0,4,SX_ID),
 SX_FIELD("mmap_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("director_version","uint32",8,4,SX_ID),
};
static const sx_layout sxvt_director_imap_be = {UINT32_C(0x60390086),"director_imap_be",sxvt_director_imap_be_fields,SX_COUNT(sxvt_director_imap_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_mmap_be_fields[] = {
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_size","uint16",2,2,SX_SIZE),
 SX_FIELD("allocated_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("used_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint32[2]",12,8,SX_RESERVED),
 SX_FIELD("first_free_resource_id","int32",20,4,SX_ID),
};
static const sx_layout sxvt_director_mmap_be = {UINT32_C(0x60390087),"director_mmap_be",sxvt_director_mmap_be_fields,SX_COUNT(sxvt_director_mmap_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_mmap_entry_be_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("chunk_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("flags","uint16",12,2,SX_FLAGS),
 SX_FIELD("unknown","uint16",14,2,SX_NONE),
 SX_FIELD("next_free_resource_id","uint32",16,4,SX_ID),
};
static const sx_layout sxvt_director_mmap_entry_be = {UINT32_C(0x60390088),"director_mmap_entry_be",sxvt_director_mmap_entry_be_fields,SX_COUNT(sxvt_director_mmap_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_key_be_fields[] = {
 SX_FIELD("entry_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_size_secondary","uint16",2,2,SX_SIZE),
 SX_FIELD("allocated_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("used_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxvt_director_key_be = {UINT32_C(0x60390089),"director_key_be",sxvt_director_key_be_fields,SX_COUNT(sxvt_director_key_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_key_entry_be_fields[] = {
 SX_FIELD("child_resource_index","uint32",0,4,SX_ID),
 SX_FIELD("parent_resource_index","uint32",4,4,SX_ID),
 SX_FIELD("child_type","uint32",8,4,SX_ID),
};
static const sx_layout sxvt_director_key_entry_be = {UINT32_C(0x6039008a),"director_key_entry_be",sxvt_director_key_entry_be_fields,SX_COUNT(sxvt_director_key_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_cast_index_fields[] = {
 SX_FIELD("cast_resource_index","uint32",0,4,SX_ID),
};
static const sx_layout sxvt_director_cast_index = {UINT32_C(0x6039008b),"director_cast_index",sxvt_director_cast_index_fields,SX_COUNT(sxvt_director_cast_index_fields),SX_BE};
static const sx_layout *const sx_videotail_layouts[] = {
 &sxvt_grasp_header,
 &sxvt_grasp_entry,
 &sxvt_grasp_member_size,
 &sxvt_swf_header,
 &sxvt_swf_lzma_header,
 &sxvt_swf_rect1,
 &sxvt_swf_rect2,
 &sxvt_swf_rect3,
 &sxvt_swf_rect4,
 &sxvt_swf_rect5,
 &sxvt_swf_rect6,
 &sxvt_swf_rect7,
 &sxvt_swf_rect8,
 &sxvt_swf_rect9,
 &sxvt_swf_rect10,
 &sxvt_swf_rect11,
 &sxvt_swf_rect12,
 &sxvt_swf_rect13,
 &sxvt_swf_rect14,
 &sxvt_swf_rect15,
 &sxvt_swf_rect16,
 &sxvt_swf_rect17,
 &sxvt_swf_movie,
 &sxvt_swf_tag_short,
 &sxvt_swf_tag_long,
 &sxvt_swf_sprite,
 &sxvt_swf_background,
 &sxvt_swf_character_id,
 &sxvt_swf_jpeg3,
 &sxvt_swf_jpeg4,
 &sxvt_swf_lossless,
 &sxvt_swf_palette_count,
 &sxvt_swf_sound,
 &sxvt_swf_mp3_seek,
 &sxvt_swf_stream_sound,
 &sxvt_swf_binary,
 &sxvt_swf_file_attributes,
 &sxvt_director_header_le,
 &sxvt_director_chunk_le,
 &sxvt_director_header_be,
 &sxvt_director_chunk_be,
 &sxvt_mp4_box,
 &sxvt_mp4_box64,
 &sxvt_mp4_uuid,
 &sxvt_mp4_ftyp,
 &sxvt_mp4_brand,
 &sxvt_mp4_mvhd_v0,
 &sxvt_mp4_tkhd_v0,
 &sxvt_mp4_mdhd_v0,
 &sxvt_mp4_elst_entry_v0,
 &sxvt_mp4_mvhd_v1,
 &sxvt_mp4_tkhd_v1,
 &sxvt_mp4_mdhd_v1,
 &sxvt_mp4_elst_entry_v1,
 &sxvt_mp4_hdlr,
 &sxvt_mp4_table,
 &sxvt_mp4_stsz,
 &sxvt_mp4_stco,
 &sxvt_mp4_co64,
 &sxvt_mp4_stts,
 &sxvt_mp4_ctts_v0,
 &sxvt_mp4_ctts_v1,
 &sxvt_mp4_stsc,
 &sxvt_mp4_stss,
 &sxvt_mp4_sample_size,
 &sxvt_mp4_sample_entry,
 &sxvt_mp4_vmhd,
 &sxvt_mp4_smhd,
 &sxvt_mp4_fullbox,
 &sxvt_ebml_id1,
 &sxvt_ebml_id2,
 &sxvt_ebml_id3,
 &sxvt_ebml_id4,
 &sxvt_ebml_size1,
 &sxvt_matroska_track1,
 &sxvt_matroska_lace_size1,
 &sxvt_matroska_lace_delta1,
 &sxvt_matroska_uint1,
 &sxvt_matroska_offset1,
 &sxvt_ebml_size2,
 &sxvt_matroska_track2,
 &sxvt_matroska_lace_size2,
 &sxvt_matroska_lace_delta2,
 &sxvt_matroska_uint2,
 &sxvt_matroska_offset2,
 &sxvt_ebml_size3,
 &sxvt_matroska_track3,
 &sxvt_matroska_lace_size3,
 &sxvt_matroska_lace_delta3,
 &sxvt_matroska_uint3,
 &sxvt_matroska_offset3,
 &sxvt_ebml_size4,
 &sxvt_matroska_track4,
 &sxvt_matroska_lace_size4,
 &sxvt_matroska_lace_delta4,
 &sxvt_matroska_uint4,
 &sxvt_matroska_offset4,
 &sxvt_ebml_size5,
 &sxvt_matroska_track5,
 &sxvt_matroska_lace_size5,
 &sxvt_matroska_lace_delta5,
 &sxvt_matroska_uint5,
 &sxvt_matroska_offset5,
 &sxvt_ebml_size6,
 &sxvt_matroska_track6,
 &sxvt_matroska_lace_size6,
 &sxvt_matroska_lace_delta6,
 &sxvt_matroska_uint6,
 &sxvt_matroska_offset6,
 &sxvt_ebml_size7,
 &sxvt_matroska_track7,
 &sxvt_matroska_lace_size7,
 &sxvt_matroska_lace_delta7,
 &sxvt_matroska_uint7,
 &sxvt_matroska_offset7,
 &sxvt_ebml_size8,
 &sxvt_matroska_track8,
 &sxvt_matroska_lace_size8,
 &sxvt_matroska_lace_delta8,
 &sxvt_matroska_uint8,
 &sxvt_matroska_offset8,
 &sxvt_matroska_date,
 &sxvt_matroska_float4,
 &sxvt_matroska_float8,
 &sxvt_matroska_crc32,
 &sxvt_matroska_block,
 &sxvt_matroska_lace_count,
 &sxvt_matroska_xiph_size,
 &sxvt_director_imap_le,
 &sxvt_director_mmap_le,
 &sxvt_director_mmap_entry_le,
 &sxvt_director_key_le,
 &sxvt_director_key_entry_le,
 &sxvt_director_imap_be,
 &sxvt_director_mmap_be,
 &sxvt_director_mmap_entry_be,
 &sxvt_director_key_be,
 &sxvt_director_key_entry_be,
 &sxvt_director_cast_index,
};
static bool sx_videotail_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60390000U||id>=0x603a0000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60390001U:
 if(!xx_rt_wcscmp(r->name,L"index_size"))text=L"Byte length of the following17-byte-entry index.";
 break;
 case 0x60390002U:
 if(!xx_rt_wcscmp(r->name,L"member_offset"))text=L"File-relative offset of the member length word; zero ends the index.";
 break;
 case 0x60390004U:
 if(!xx_rt_wcscmp(r->name,L"uncompressed_file_size"))text=L"Complete uncompressed movie length including this8-byte header; compressed storage extent can differ.";
 break;
 case 0x60390005U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Length of LZMA compressed data, excluding the five property bytes.";
 if(!xx_rt_wcscmp(r->name,L"lc_lp_pb"))text=L"LZMA property byte encodes lc,lp,pb.";
 break;
 case 0x60390006U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390007U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390008U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390009U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000aU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000bU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000cU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000dU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000eU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000fU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390010U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390011U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390012U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390013U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390014U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390015U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390016U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390017U:
 if(!xx_rt_wcscmp(r->name,L"frame_rate_fixed8"))text=L"Adobe SWF19 physical UI16 field; unsigned8.8 frames per second.";
 break;
 case 0x60390018U: if(!xx_rt_wcscmp(r->name,L"code_and_length")){switch(xx_var_get_u64(&r->value)>>6){
 case 0:text=L"End; low6bits encode body length or63 for long header";break;
 case 1:text=L"ShowFrame; low6bits encode body length or63 for long header";break;
 case 6:text=L"DefineBits; low6bits encode body length or63 for long header";break;
 case 8:text=L"JPEGTables; low6bits encode body length or63 for long header";break;
 case 9:text=L"SetBackgroundColor; low6bits encode body length or63 for long header";break;
 case 14:text=L"DefineSound; low6bits encode body length or63 for long header";break;
 case 18:text=L"SoundStreamHead; low6bits encode body length or63 for long header";break;
 case 19:text=L"SoundStreamBlock; low6bits encode body length or63 for long header";break;
 case 20:text=L"DefineBitsLossless; low6bits encode body length or63 for long header";break;
 case 21:text=L"DefineBitsJPEG2; low6bits encode body length or63 for long header";break;
 case 35:text=L"DefineBitsJPEG3; low6bits encode body length or63 for long header";break;
 case 36:text=L"DefineBitsLossless2; low6bits encode body length or63 for long header";break;
 case 39:text=L"DefineSprite; low6bits encode body length or63 for long header";break;
 case 45:text=L"SoundStreamHead2; low6bits encode body length or63 for long header";break;
 case 69:text=L"FileAttributes; low6bits encode body length or63 for long header";break;
 case 87:text=L"DefineBinaryData; low6bits encode body length or63 for long header";break;
 case 90:text=L"DefineBitsJPEG4; low6bits encode body length or63 for long header";break;
 default:text=L"Upper10bits tag code; low6bits body length or63 for long header";break;}}break;
 case 0x60390019U: if(!xx_rt_wcscmp(r->name,L"code_and_length")){switch(xx_var_get_u64(&r->value)>>6){
 case 0:text=L"End; low6bits encode body length or63 for long header";break;
 case 1:text=L"ShowFrame; low6bits encode body length or63 for long header";break;
 case 6:text=L"DefineBits; low6bits encode body length or63 for long header";break;
 case 8:text=L"JPEGTables; low6bits encode body length or63 for long header";break;
 case 9:text=L"SetBackgroundColor; low6bits encode body length or63 for long header";break;
 case 14:text=L"DefineSound; low6bits encode body length or63 for long header";break;
 case 18:text=L"SoundStreamHead; low6bits encode body length or63 for long header";break;
 case 19:text=L"SoundStreamBlock; low6bits encode body length or63 for long header";break;
 case 20:text=L"DefineBitsLossless; low6bits encode body length or63 for long header";break;
 case 21:text=L"DefineBitsJPEG2; low6bits encode body length or63 for long header";break;
 case 35:text=L"DefineBitsJPEG3; low6bits encode body length or63 for long header";break;
 case 36:text=L"DefineBitsLossless2; low6bits encode body length or63 for long header";break;
 case 39:text=L"DefineSprite; low6bits encode body length or63 for long header";break;
 case 45:text=L"SoundStreamHead2; low6bits encode body length or63 for long header";break;
 case 69:text=L"FileAttributes; low6bits encode body length or63 for long header";break;
 case 87:text=L"DefineBinaryData; low6bits encode body length or63 for long header";break;
 case 90:text=L"DefineBitsJPEG4; low6bits encode body length or63 for long header";break;
 default:text=L"Upper10bits tag code; low6bits body length or63 for long header";break;}}break;
 case 0x6039001dU:
 if(!xx_rt_wcscmp(r->name,L"alpha_data_offset"))text=L"Relative to the end of this fixed header, where JPEG bytes begin.";
 break;
 case 0x6039001eU:
 if(!xx_rt_wcscmp(r->name,L"alpha_data_offset"))text=L"Byte count of ImageData; alpha bytes begin this many bytes after the8-byte fixed header.";
 if(!xx_rt_wcscmp(r->name,L"deblock_fixed8"))text=L"Unsigned8.8 normalized deblocking strength; Adobe SWF19 declares UI16.";
 break;
 case 0x60390020U:
 if(!xx_rt_wcscmp(r->name,L"palette_count_minus_one"))text=L"Encoded number of colour-table entries minus1.";
 break;
 case 0x60390021U:
 if(!xx_rt_wcscmp(r->name,L"sound_format_flags"))text=L"High4bits codec, next2bits sample-rate selector, bit1 sample width, bit0 stereo.";
 break;
 case 0x60390026U:
 if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Container length minus8.";
 break;
 case 0x60390028U:
 if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Container length minus8.";
 break;
 case 0x6039002aU:
 if(!xx_rt_wcscmp(r->name,L"box_size"))text=L"Includes this header;1 selects64-bit extended size;0 extends to parent end.";
 break;
 case 0x6039002bU:
 if(!xx_rt_wcscmp(r->name,L"box_size"))text=L"Value1 selects the following64-bit size.";
 break;
 case 0x6039002fU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"timescale"))text=L"Ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"rate_fixed16"))text=L"Signed16.16 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"volume_fixed8"))text=L"Signed8.8 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"matrix"))text=L"Signed16.16 values except u,v,w use2.30.";
 break;
 case 0x60390030U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"TrackEnabled=1,TrackInMovie=2,TrackInPreview=4,TrackSizeIsAspectRatio=8.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"volume_fixed8"))text=L"Signed8.8 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"matrix"))text=L"Signed16.16 values except u,v,w use2.30.";
 if(!xx_rt_wcscmp(r->name,L"width_fixed16"))text=L"Unsigned16.16 pixels.";
 if(!xx_rt_wcscmp(r->name,L"height_fixed16"))text=L"Unsigned16.16 pixels.";
 break;
 case 0x60390031U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"timescale"))text=L"Ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Media timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"language"))text=L"Low15bits encode three5-bit ISO639-2 letters, each plus0x60.";
 break;
 case 0x60390032U:
 if(!xx_rt_wcscmp(r->name,L"segment_duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"media_time"))text=L"Media timescale ticks;-1 means empty edit.";
 break;
 case 0x60390033U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"timescale"))text=L"Ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"rate_fixed16"))text=L"Signed16.16 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"volume_fixed8"))text=L"Signed8.8 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"matrix"))text=L"Signed16.16 values except u,v,w use2.30.";
 break;
 case 0x60390034U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"TrackEnabled=1,TrackInMovie=2,TrackInPreview=4,TrackSizeIsAspectRatio=8.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"volume_fixed8"))text=L"Signed8.8 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"matrix"))text=L"Signed16.16 values except u,v,w use2.30.";
 if(!xx_rt_wcscmp(r->name,L"width_fixed16"))text=L"Unsigned16.16 pixels.";
 if(!xx_rt_wcscmp(r->name,L"height_fixed16"))text=L"Unsigned16.16 pixels.";
 break;
 case 0x60390035U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"timescale"))text=L"Ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Media timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"language"))text=L"Low15bits encode three5-bit ISO639-2 letters, each plus0x60.";
 break;
 case 0x60390036U:
 if(!xx_rt_wcscmp(r->name,L"segment_duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"media_time"))text=L"Media timescale ticks;-1 means empty edit.";
 break;
 case 0x60390037U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 break;
 case 0x60390038U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 break;
 case 0x60390039U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"sample_size"))text=L"Zero selects one size per sample.";
 break;
 case 0x6039003aU:
 if(!xx_rt_wcscmp(r->name,L"chunk_offset"))text=L"File-relative byte offset of the media chunk.";
 break;
 case 0x6039003bU:
 if(!xx_rt_wcscmp(r->name,L"chunk_offset"))text=L"File-relative byte offset of the media chunk.";
 break;
 case 0x6039003cU:
 if(!xx_rt_wcscmp(r->name,L"sample_delta"))text=L"Decode duration in media timescale ticks.";
 break;
 case 0x6039003dU:
 if(!xx_rt_wcscmp(r->name,L"sample_offset"))text=L"Composition offset in media timescale ticks.";
 break;
 case 0x6039003eU:
 if(!xx_rt_wcscmp(r->name,L"sample_offset"))text=L"Signed composition offset in media timescale ticks.";
 break;
 case 0x6039003fU:
 if(!xx_rt_wcscmp(r->name,L"first_chunk"))text=L"One-based chunk index.";
 if(!xx_rt_wcscmp(r->name,L"sample_description_index"))text=L"One-based sample description index.";
 break;
 case 0x60390040U:
 if(!xx_rt_wcscmp(r->name,L"sample_number"))text=L"One-based sync sample index.";
 break;
 case 0x60390043U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 break;
 case 0x60390044U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"balance_fixed8"))text=L"Signed8.8 fixed point.";
 break;
 case 0x60390045U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 break;
 case 0x60390046U: switch(xx_var_get_u64(&r->value)) {
 case 440786851:text=L"EBML";break;
 case 408125543:text=L"Segment";break;
 case 357149030:text=L"Info";break;
 case 374648427:text=L"Tracks";break;
 case 174:text=L"TrackEntry";break;
 case 524531317:text=L"Cluster";break;
 case 160:text=L"BlockGroup";break;
 case 163:text=L"SimpleBlock";break;
 case 161:text=L"Block";break;
 case 236:text=L"Void";break;
 case 191:text=L"CRC32";break;
 case 17026:text=L"DocType";break;
 case 17030:text=L"EBMLVersion";break;
 case 17143:text=L"EBMLReadVersion";break;
 case 17138:text=L"EBMLMaxIDLength";break;
 case 17139:text=L"EBMLMaxSizeLength";break;
 case 17031:text=L"DocTypeVersion";break;
 case 17029:text=L"DocTypeReadVersion";break;
 case 2807729:text=L"TimestampScale";break;
 case 17545:text=L"Duration";break;
 case 17505:text=L"DateUTC";break;
 case 19840:text=L"MuxingApp";break;
 case 22337:text=L"WritingApp";break;
 case 215:text=L"TrackNumber";break;
 case 29637:text=L"TrackUID";break;
 case 131:text=L"TrackType";break;
 case 134:text=L"CodecID";break;
 case 224:text=L"Video";break;
 case 225:text=L"Audio";break;
 case 176:text=L"PixelWidth";break;
 case 186:text=L"PixelHeight";break;
 case 181:text=L"SamplingFrequency";break;
 case 159:text=L"Channels";break;
 case 231:text=L"Timestamp";break;
 case 21420:text=L"SeekPosition";break;
 case 290298740:text=L"SeekHead";break;
 case 19899:text=L"Seek";break;
 case 241:text=L"CueClusterPosition";break;
 case 240:text=L"CueRelativePosition";break;
 default:text=L"EBML element ID including its marker bit";break;}break;
 case 0x60390047U: switch(xx_var_get_u64(&r->value)) {
 case 440786851:text=L"EBML";break;
 case 408125543:text=L"Segment";break;
 case 357149030:text=L"Info";break;
 case 374648427:text=L"Tracks";break;
 case 174:text=L"TrackEntry";break;
 case 524531317:text=L"Cluster";break;
 case 160:text=L"BlockGroup";break;
 case 163:text=L"SimpleBlock";break;
 case 161:text=L"Block";break;
 case 236:text=L"Void";break;
 case 191:text=L"CRC32";break;
 case 17026:text=L"DocType";break;
 case 17030:text=L"EBMLVersion";break;
 case 17143:text=L"EBMLReadVersion";break;
 case 17138:text=L"EBMLMaxIDLength";break;
 case 17139:text=L"EBMLMaxSizeLength";break;
 case 17031:text=L"DocTypeVersion";break;
 case 17029:text=L"DocTypeReadVersion";break;
 case 2807729:text=L"TimestampScale";break;
 case 17545:text=L"Duration";break;
 case 17505:text=L"DateUTC";break;
 case 19840:text=L"MuxingApp";break;
 case 22337:text=L"WritingApp";break;
 case 215:text=L"TrackNumber";break;
 case 29637:text=L"TrackUID";break;
 case 131:text=L"TrackType";break;
 case 134:text=L"CodecID";break;
 case 224:text=L"Video";break;
 case 225:text=L"Audio";break;
 case 176:text=L"PixelWidth";break;
 case 186:text=L"PixelHeight";break;
 case 181:text=L"SamplingFrequency";break;
 case 159:text=L"Channels";break;
 case 231:text=L"Timestamp";break;
 case 21420:text=L"SeekPosition";break;
 case 290298740:text=L"SeekHead";break;
 case 19899:text=L"Seek";break;
 case 241:text=L"CueClusterPosition";break;
 case 240:text=L"CueRelativePosition";break;
 default:text=L"EBML element ID including its marker bit";break;}break;
 case 0x60390048U: switch(xx_var_get_u64(&r->value)) {
 case 440786851:text=L"EBML";break;
 case 408125543:text=L"Segment";break;
 case 357149030:text=L"Info";break;
 case 374648427:text=L"Tracks";break;
 case 174:text=L"TrackEntry";break;
 case 524531317:text=L"Cluster";break;
 case 160:text=L"BlockGroup";break;
 case 163:text=L"SimpleBlock";break;
 case 161:text=L"Block";break;
 case 236:text=L"Void";break;
 case 191:text=L"CRC32";break;
 case 17026:text=L"DocType";break;
 case 17030:text=L"EBMLVersion";break;
 case 17143:text=L"EBMLReadVersion";break;
 case 17138:text=L"EBMLMaxIDLength";break;
 case 17139:text=L"EBMLMaxSizeLength";break;
 case 17031:text=L"DocTypeVersion";break;
 case 17029:text=L"DocTypeReadVersion";break;
 case 2807729:text=L"TimestampScale";break;
 case 17545:text=L"Duration";break;
 case 17505:text=L"DateUTC";break;
 case 19840:text=L"MuxingApp";break;
 case 22337:text=L"WritingApp";break;
 case 215:text=L"TrackNumber";break;
 case 29637:text=L"TrackUID";break;
 case 131:text=L"TrackType";break;
 case 134:text=L"CodecID";break;
 case 224:text=L"Video";break;
 case 225:text=L"Audio";break;
 case 176:text=L"PixelWidth";break;
 case 186:text=L"PixelHeight";break;
 case 181:text=L"SamplingFrequency";break;
 case 159:text=L"Channels";break;
 case 231:text=L"Timestamp";break;
 case 21420:text=L"SeekPosition";break;
 case 290298740:text=L"SeekHead";break;
 case 19899:text=L"Seek";break;
 case 241:text=L"CueClusterPosition";break;
 case 240:text=L"CueRelativePosition";break;
 default:text=L"EBML element ID including its marker bit";break;}break;
 case 0x60390049U: switch(xx_var_get_u64(&r->value)) {
 case 440786851:text=L"EBML";break;
 case 408125543:text=L"Segment";break;
 case 357149030:text=L"Info";break;
 case 374648427:text=L"Tracks";break;
 case 174:text=L"TrackEntry";break;
 case 524531317:text=L"Cluster";break;
 case 160:text=L"BlockGroup";break;
 case 163:text=L"SimpleBlock";break;
 case 161:text=L"Block";break;
 case 236:text=L"Void";break;
 case 191:text=L"CRC32";break;
 case 17026:text=L"DocType";break;
 case 17030:text=L"EBMLVersion";break;
 case 17143:text=L"EBMLReadVersion";break;
 case 17138:text=L"EBMLMaxIDLength";break;
 case 17139:text=L"EBMLMaxSizeLength";break;
 case 17031:text=L"DocTypeVersion";break;
 case 17029:text=L"DocTypeReadVersion";break;
 case 2807729:text=L"TimestampScale";break;
 case 17545:text=L"Duration";break;
 case 17505:text=L"DateUTC";break;
 case 19840:text=L"MuxingApp";break;
 case 22337:text=L"WritingApp";break;
 case 215:text=L"TrackNumber";break;
 case 29637:text=L"TrackUID";break;
 case 131:text=L"TrackType";break;
 case 134:text=L"CodecID";break;
 case 224:text=L"Video";break;
 case 225:text=L"Audio";break;
 case 176:text=L"PixelWidth";break;
 case 186:text=L"PixelHeight";break;
 case 181:text=L"SamplingFrequency";break;
 case 159:text=L"Channels";break;
 case 231:text=L"Timestamp";break;
 case 21420:text=L"SeekPosition";break;
 case 290298740:text=L"SeekHead";break;
 case 19899:text=L"Seek";break;
 case 241:text=L"CueClusterPosition";break;
 case 240:text=L"CueRelativePosition";break;
 default:text=L"EBML element ID including its marker bit";break;}break;
 case 0x6039004aU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(127);char b[160];wchar_t wide[160];
 if((raw>>7)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(127))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039004bU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(127);char b[160];wchar_t wide[160];
 if((raw>>7)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039004cU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(127);char b[160];wchar_t wide[160];
 if((raw>>7)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039004dU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(127);char b[160];wchar_t wide[160];
 if((raw>>7)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(63)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039004fU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390050U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(16383);char b[160];wchar_t wide[160];
 if((raw>>14)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(16383))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390051U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(16383);char b[160];wchar_t wide[160];
 if((raw>>14)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390052U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(16383);char b[160];wchar_t wide[160];
 if((raw>>14)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390053U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(16383);char b[160];wchar_t wide[160];
 if((raw>>14)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(8191)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390055U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390056U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(2097151);char b[160];wchar_t wide[160];
 if((raw>>21)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(2097151))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390057U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(2097151);char b[160];wchar_t wide[160];
 if((raw>>21)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390058U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(2097151);char b[160];wchar_t wide[160];
 if((raw>>21)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390059U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(2097151);char b[160];wchar_t wide[160];
 if((raw>>21)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(1048575)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039005bU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x6039005cU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(268435455);char b[160];wchar_t wide[160];
 if((raw>>28)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(268435455))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039005dU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(268435455);char b[160];wchar_t wide[160];
 if((raw>>28)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039005eU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(268435455);char b[160];wchar_t wide[160];
 if((raw>>28)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039005fU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(268435455);char b[160];wchar_t wide[160];
 if((raw>>28)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(134217727)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390061U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390062U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(34359738367);char b[160];wchar_t wide[160];
 if((raw>>35)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(34359738367))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390063U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(34359738367);char b[160];wchar_t wide[160];
 if((raw>>35)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390064U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(34359738367);char b[160];wchar_t wide[160];
 if((raw>>35)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390065U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(34359738367);char b[160];wchar_t wide[160];
 if((raw>>35)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(17179869183)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390067U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390068U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(4398046511103);char b[160];wchar_t wide[160];
 if((raw>>42)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(4398046511103))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390069U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(4398046511103);char b[160];wchar_t wide[160];
 if((raw>>42)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039006aU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(4398046511103);char b[160];wchar_t wide[160];
 if((raw>>42)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039006bU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(4398046511103);char b[160];wchar_t wide[160];
 if((raw>>42)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(2199023255551)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039006dU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x6039006eU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(562949953421311);char b[160];wchar_t wide[160];
 if((raw>>49)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(562949953421311))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039006fU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(562949953421311);char b[160];wchar_t wide[160];
 if((raw>>49)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390070U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(562949953421311);char b[160];wchar_t wide[160];
 if((raw>>49)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390071U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(562949953421311);char b[160];wchar_t wide[160];
 if((raw>>49)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(281474976710655)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390073U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390074U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(72057594037927935);char b[160];wchar_t wide[160];
 if((raw>>56)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(72057594037927935))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390075U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(72057594037927935);char b[160];wchar_t wide[160];
 if((raw>>56)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390076U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(72057594037927935);char b[160];wchar_t wide[160];
 if((raw>>56)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390077U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(72057594037927935);char b[160];wchar_t wide[160];
 if((raw>>56)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(36028797018963967)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390079U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x6039007dU:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 over parent contents except this complete CRC element.";
 break;
 case 0x6039007eU:
 if(!xx_rt_wcscmp(r->name,L"relative_timestamp"))text=L"Signed offset from Cluster timestamp in track ticks.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Lacing bits1..2:0none,1Xiph,2fixed,3EBML; SimpleBlock bit7keyframe,bit0discardable.";
 break;
 case 0x6039007fU:
 if(!xx_rt_wcscmp(r->name,L"frame_count_minus_one"))text=L"Number of frames minus1; lacing requires at least2frames.";
 break;
 case 0x60390080U:
 if(!xx_rt_wcscmp(r->name,L"size_part"))text=L"Add255 continuations and a terminating byte below255 to obtain one frame size.";
 break;
 case 0x60390081U:
 if(!xx_rt_wcscmp(r->name,L"mmap_offset"))text=L"File-relative offset of the memory-map chunk.";
 break;
 case 0x60390082U:
 if(!xx_rt_wcscmp(r->name,L"first_free_resource_id"))text=L"Minus1 means no free resource.";
 break;
 case 0x60390083U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"Packed four-character resource type.";
 if(!xx_rt_wcscmp(r->name,L"chunk_offset"))text=L"File-relative chunk-header offset.";
 if(!xx_rt_wcscmp(r->name,L"next_free_resource_id"))text=L"Resource index for free entries, flags for special resources.";
 break;
 case 0x60390085U:
 if(!xx_rt_wcscmp(r->name,L"child_type"))text=L"Packed four-character type.";
 break;
 case 0x60390086U:
 if(!xx_rt_wcscmp(r->name,L"mmap_offset"))text=L"File-relative offset of the memory-map chunk.";
 break;
 case 0x60390087U:
 if(!xx_rt_wcscmp(r->name,L"first_free_resource_id"))text=L"Minus1 means no free resource.";
 break;
 case 0x60390088U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"Packed four-character resource type.";
 if(!xx_rt_wcscmp(r->name,L"chunk_offset"))text=L"File-relative chunk-header offset.";
 if(!xx_rt_wcscmp(r->name,L"next_free_resource_id"))text=L"Resource index for free entries, flags for special resources.";
 break;
 case 0x6039008aU:
 if(!xx_rt_wcscmp(r->name,L"child_type"))text=L"Packed four-character type.";
 break;
 case 0x6039008bU:
 if(!xx_rt_wcscmp(r->name,L"cast_resource_index"))text=L"Cast-list indices are stored big-endian independently of container byte order.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXVT_LIMIT 20000U
static bool sxvt_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxvt_read(sx_context*c,uint64_t p,void*b,size_t n){return sxvt_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxvt_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxvt_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxvt_read(c,p,b,n))return false;*v=sxvt_uint(b,n,be);return true;}
static bool sxvt_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];int64_t n=f->rel_offset+f->size;return c->count<SXVT_LIMIT&&sxvt_span(c,p,(uint64_t)n)&&sx_add(c,l,(int64_t)p,n);}
static bool sxvt_byte(sx_context*c,uint64_t p,uint8_t*v){return sxvt_read(c,p,v,1);}
static bool sxvt_grasp(sx_context*c){uint64_t z;if(!sxvt_word(c,0,2,false,&z)||z%17||!sxvt_span(c,2,z)||!sxvt_add(c,&sxvt_grasp_header,0))return false;for(uint64_t p=2;p<2+z;p+=17){uint64_t off,n;if(!sxvt_word(c,p,4,false,&off)||!sxvt_add(c,&sxvt_grasp_entry,p))return false;if(!off)break;if(!sxvt_word(c,off,4,false,&n)||!sxvt_span(c,off+4,n)||!sxvt_add(c,&sxvt_grasp_member_size,off))return false;}return true;}
static bool sxvt_swftags(sx_context*c,uint64_t p,uint64_t end,unsigned depth){if(depth>16)return false;while(p<end&&c->count<SXVT_LIMIT){uint64_t h,n;unsigned z=2;if(end-p<2||!sxvt_word(c,p,2,false,&h))return false;n=h&63;if(n==63){z=6;if(end-p<6||!sxvt_word(c,p+2,4,false,&n))return false;}if(n>end-p-z)return false;if(!sxvt_add(c,z==2?&sxvt_swf_tag_short:&sxvt_swf_tag_long,p))return false;unsigned code=(unsigned)(h>>6);p+=z;uint64_t stop=p+n;const sx_layout*l=NULL;if(!code)return true;
 switch(code){case 39:if(n>=4){if(!sxvt_add(c,&sxvt_swf_sprite,p))return false;(void)sxvt_swftags(c,p+4,stop,depth+1);}break;case 9:if(n==3)l=&sxvt_swf_background;break;case 6:case 21:if(n>=2)l=&sxvt_swf_character_id;break;case 35:if(n>=6)l=&sxvt_swf_jpeg3;break;case 90:if(n>=8)l=&sxvt_swf_jpeg4;break;case 20:case 36:if(n>=7){uint8_t f;if(!sxvt_add(c,&sxvt_swf_lossless,p)||!sxvt_byte(c,p+2,&f))return false;if(f==3&&n>=8&&!sxvt_add(c,&sxvt_swf_palette_count,p+7))return false;}break;
 case 14:if(n>=7){uint8_t f;if(!sxvt_add(c,&sxvt_swf_sound,p)||!sxvt_byte(c,p+2,&f))return false;if((f>>4)==2&&n>=9&&!sxvt_add(c,&sxvt_swf_mp3_seek,p+7))return false;}break;
 case 18:case 45:if(n>=4){uint8_t f;if(!sxvt_add(c,&sxvt_swf_stream_sound,p)||!sxvt_byte(c,p+1,&f))return false;if((f>>4)==2&&n>=6&&!sxvt_add(c,&sxvt_swf_mp3_seek,p+4))return false;}break;case 69:if(n==4)l=&sxvt_swf_file_attributes;break;case 87:if(n>=6)l=&sxvt_swf_binary;break;default:break;}
 if(l&&!sxvt_add(c,l,p))return false;p=stop;}return p==end;}
static bool sxvt_swf(sx_context*c){uint8_t h[9];if(!sxvt_read(c,0,h,8)||!sxvt_add(c,&sxvt_swf_header,0))return false;if(h[0]=='Z')return sxvt_add(c,&sxvt_swf_lzma_header,8);if(h[0]!='F')return h[0]=='C';if(!sxvt_byte(c,8,h+8))return false;unsigned z=(5+4*(h[8]>>3)+7)/8;const sx_layout*const a[]={&sxvt_swf_rect1,&sxvt_swf_rect2,&sxvt_swf_rect3,&sxvt_swf_rect4,&sxvt_swf_rect5,&sxvt_swf_rect6,&sxvt_swf_rect7,&sxvt_swf_rect8,&sxvt_swf_rect9,&sxvt_swf_rect10,&sxvt_swf_rect11,&sxvt_swf_rect12,&sxvt_swf_rect13,&sxvt_swf_rect14,&sxvt_swf_rect15,&sxvt_swf_rect16,&sxvt_swf_rect17};if(!z||z>17||!sxvt_add(c,a[z-1],8)||!sxvt_add(c,&sxvt_swf_movie,8+z))return false;uint64_t end=sxvt_uint(h+4,4,false);if(end>(uint64_t)c->size)end=(uint64_t)c->size;return sxvt_swftags(c,12+z,end,0);}
static bool sxvt_dtag(const uint8_t*b,const char*t,bool be){if(!xx_rt_memcmp(b,t,4))return true;return !be&&b[0]==(uint8_t)t[3]&&b[1]==(uint8_t)t[2]&&b[2]==(uint8_t)t[1]&&b[3]==(uint8_t)t[0];}
static bool sxvt_director(sx_context*c){uint8_t h[12];if(!sxvt_read(c,0,h,12))return false;bool be=h[0]=='R';uint64_t end=8+sxvt_uint(h+4,4,be);if(end<12||!sxvt_span(c,0,end)||!sxvt_add(c,be?&sxvt_director_header_be:&sxvt_director_header_le,0))return false;bool plain=!xx_rt_memcmp(h+8,be?"MV93":"39VM",4)||!xx_rt_memcmp(h+8,be?"MC95":"59CM",4);
 for(uint64_t p=12;p<end;){uint8_t b[8];if(end-p<8||!sxvt_read(c,p,b,8))return false;uint64_t n=sxvt_uint(b+4,4,be);if(n>end-p-8||!sxvt_add(c,be?&sxvt_director_chunk_be:&sxvt_director_chunk_le,p))return false;uint64_t q=p+8;if(plain){const sx_layout*l=NULL,*e=NULL;uint64_t hs=0,es=0,count=0;
 if(sxvt_dtag(b,"imap",be)&&n>=12)l=be?&sxvt_director_imap_be:&sxvt_director_imap_le;
 else if(sxvt_dtag(b,"mmap",be)&&n>=24){l=be?&sxvt_director_mmap_be:&sxvt_director_mmap_le;e=be?&sxvt_director_mmap_entry_be:&sxvt_director_mmap_entry_le;if(!sxvt_word(c,q,2,be,&hs)||!sxvt_word(c,q+2,2,be,&es)||!sxvt_word(c,q+8,4,be,&count))return false;if(hs<24||es<20||hs>n||count>(n-hs)/es){e=NULL;} }
 else if(sxvt_dtag(b,"KEY*",be)&&n>=12){l=be?&sxvt_director_key_be:&sxvt_director_key_le;e=be?&sxvt_director_key_entry_be:&sxvt_director_key_entry_le;hs=12;if(!sxvt_word(c,q,2,be,&es)||!sxvt_word(c,q+8,4,be,&count))return false;if(es<12||count>(n-hs)/es)e=NULL;}
 else if(sxvt_dtag(b,"CAS*",be)&&!(n%4)){hs=0;es=4;count=n/4;e=&sxvt_director_cast_index;}
 if(l&&!sxvt_add(c,l,q))return false;if(e){for(uint64_t i=0;i<count;i++)if(!sxvt_add(c,e,q+hs+i*es))return false;}}
 p=q+n;if(n&1){if(p==end)return false;p++;}}
 return true;}
static bool sxvt_four(const uint8_t*a,const char*b){return !xx_rt_memcmp(a,b,4);}
static bool sxvt_mp4_container(const uint8_t*t){const char*const names[]={"moov","trak","mdia","minf","stbl","edts","dinf","mvex","moof","traf","mfra","udta"};for(size_t i=0;i<SX_COUNT(names);i++)if(sxvt_four(t,names[i]))return true;return false;}
static bool sxvt_mp4(sx_context*c,uint64_t p,uint64_t end,unsigned depth){if(depth>24)return false;while(p<end&&c->count<SXVT_LIMIT){uint8_t b[16];uint64_t n,z=8;if(end-p<8||!sxvt_read(c,p,b,8))return false;n=sxvt_uint(b,4,true);if(n==1){if(end-p<16||!sxvt_read(c,p+8,b+8,8))return false;n=sxvt_uint(b+8,8,true);z=16;}else if(!n)n=end-p;if(n<z||n>end-p)return false;if(!sxvt_add(c,z==8?&sxvt_mp4_box:&sxvt_mp4_box64,p))return false;uint64_t q=p+z,stop=p+n;if(sxvt_four(b+4,"uuid")){if(stop-q<16||!sxvt_add(c,&sxvt_mp4_uuid,q))return false;q+=16;}
 if(sxvt_mp4_container(b+4)){(void)sxvt_mp4(c,q,stop,depth+1);p=stop;continue;}const sx_layout*l=NULL,*entry=NULL;uint64_t es=0,count=0;uint8_t v=0;if(q<stop&&!sxvt_byte(c,q,&v))return false;
 if(sxvt_four(b+4,"ftyp")&&stop-q>=8){l=&sxvt_mp4_ftyp;entry=&sxvt_mp4_brand;es=4;count=(stop-q-8)/4;}
 else if(sxvt_four(b+4,"mvhd")&&v<2)l=v?&sxvt_mp4_mvhd_v1:&sxvt_mp4_mvhd_v0;
 else if(sxvt_four(b+4,"tkhd")&&v<2)l=v?&sxvt_mp4_tkhd_v1:&sxvt_mp4_tkhd_v0;
 else if(sxvt_four(b+4,"mdhd")&&v<2)l=v?&sxvt_mp4_mdhd_v1:&sxvt_mp4_mdhd_v0;
 else if(sxvt_four(b+4,"hdlr"))l=&sxvt_mp4_hdlr;
 else if(sxvt_four(b+4,"vmhd"))l=&sxvt_mp4_vmhd;
 else if(sxvt_four(b+4,"smhd"))l=&sxvt_mp4_smhd;
 else if(sxvt_four(b+4,"nmhd"))l=&sxvt_mp4_fullbox;
 else if(sxvt_four(b+4,"stsz")&&stop-q>=12){uint64_t sz;if(!sxvt_word(c,q+4,4,true,&sz)||!sxvt_word(c,q+8,4,true,&count))return false;l=&sxvt_mp4_stsz;if(!sz){es=4;entry=&sxvt_mp4_sample_size;}}
 else if(sxvt_four(b+4,"stco")){entry=&sxvt_mp4_stco;es=4;}
 else if(sxvt_four(b+4,"co64")){entry=&sxvt_mp4_co64;es=8;}
 else if(sxvt_four(b+4,"stts")){entry=&sxvt_mp4_stts;es=8;}
 else if(sxvt_four(b+4,"ctts")&&v<2){entry=v?&sxvt_mp4_ctts_v1:&sxvt_mp4_ctts_v0;es=8;}
 else if(sxvt_four(b+4,"stsc")){entry=&sxvt_mp4_stsc;es=12;}
 else if(sxvt_four(b+4,"stss")){entry=&sxvt_mp4_stss;es=4;}
 else if(sxvt_four(b+4,"elst")&&v<2){entry=v?&sxvt_mp4_elst_entry_v1:&sxvt_mp4_elst_entry_v0;es=v?20:12;}
 else if((sxvt_four(b+4,"stsd")||sxvt_four(b+4,"dref"))&&stop-q>=8){if(!sxvt_word(c,q+4,4,true,&count)||!sxvt_add(c,&sxvt_mp4_table,q))return false;uint64_t cur=q+8;for(uint64_t i=0;i<count&&c->count<SXVT_LIMIT;i++){uint8_t eb[8];if(cur>stop||stop-cur<8||!sxvt_read(c,cur,eb,8))break;uint64_t en=sxvt_uint(eb,4,true);if(en<8||en>stop-cur)break;if(!sxvt_add(c,&sxvt_mp4_box,cur))return false;if(sxvt_four(b+4,"stsd")&&en>=16&&!sxvt_add(c,&sxvt_mp4_sample_entry,cur+8))return false;if(sxvt_four(b+4,"dref")&&en>=12&&!sxvt_add(c,&sxvt_mp4_fullbox,cur+8))return false;cur+=en;}p=stop;continue;}
 if(entry&&!l){l=&sxvt_mp4_table;if(stop-q<8||!sxvt_word(c,q+4,4,true,&count)){p=stop;continue;}}
 if(l){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t hs=(uint64_t)(f->rel_offset+f->size);if(hs<=stop-q){if(!sxvt_add(c,l,q))return false;if(entry&&es&&count<=(stop-q-hs)/es)for(uint64_t i=0;i<count;i++)if(!sxvt_add(c,entry,q+hs+i*es))return false;}}
 p=stop;}return p==end;}
static bool sxvt_vint(sx_context*c,uint64_t*p,uint64_t end,bool id,uint64_t*v,unsigned*w){uint8_t b[8];if(*p>=end||!sxvt_byte(c,*p,b)||!b[0])return false;unsigned z=1;uint8_t mask=128;while(!(b[0]&mask)){z++;mask>>=1;}if(z>(id?4U:8U)||z>end-*p||!sxvt_read(c,*p,b,z))return false;*v=id?b[0]:b[0]&((unsigned)mask-1U);for(unsigned i=1;i<z;i++)*v=(*v<<8)|b[i];*p+=z;*w=z;return true;}
static const sx_layout*const sxvt_ebml_ids[]={&sxvt_ebml_id1,&sxvt_ebml_id2,&sxvt_ebml_id3,&sxvt_ebml_id4};
static const sx_layout*const sxvt_sizes[]={&sxvt_ebml_size1,&sxvt_ebml_size2,&sxvt_ebml_size3,&sxvt_ebml_size4,&sxvt_ebml_size5,&sxvt_ebml_size6,&sxvt_ebml_size7,&sxvt_ebml_size8};
static const sx_layout*const sxvt_tracks[]={&sxvt_matroska_track1,&sxvt_matroska_track2,&sxvt_matroska_track3,&sxvt_matroska_track4,&sxvt_matroska_track5,&sxvt_matroska_track6,&sxvt_matroska_track7,&sxvt_matroska_track8};
static const sx_layout*const sxvt_laces[]={&sxvt_matroska_lace_size1,&sxvt_matroska_lace_size2,&sxvt_matroska_lace_size3,&sxvt_matroska_lace_size4,&sxvt_matroska_lace_size5,&sxvt_matroska_lace_size6,&sxvt_matroska_lace_size7,&sxvt_matroska_lace_size8};
static const sx_layout*const sxvt_deltas[]={&sxvt_matroska_lace_delta1,&sxvt_matroska_lace_delta2,&sxvt_matroska_lace_delta3,&sxvt_matroska_lace_delta4,&sxvt_matroska_lace_delta5,&sxvt_matroska_lace_delta6,&sxvt_matroska_lace_delta7,&sxvt_matroska_lace_delta8};
static const sx_layout*const sxvt_uints[]={&sxvt_matroska_uint1,&sxvt_matroska_uint2,&sxvt_matroska_uint3,&sxvt_matroska_uint4,&sxvt_matroska_uint5,&sxvt_matroska_uint6,&sxvt_matroska_uint7,&sxvt_matroska_uint8};
static const sx_layout*const sxvt_offsets[]={&sxvt_matroska_offset1,&sxvt_matroska_offset2,&sxvt_matroska_offset3,&sxvt_matroska_offset4,&sxvt_matroska_offset5,&sxvt_matroska_offset6,&sxvt_matroska_offset7,&sxvt_matroska_offset8};
static bool sxvt_mkblock(sx_context*c,uint64_t p,uint64_t end){uint64_t v,start=p;unsigned z;uint8_t b;if(!sxvt_vint(c,&p,end,false,&v,&z)||!sxvt_add(c,sxvt_tracks[z-1],start)||end-p<3||!sxvt_byte(c,p+2,&b)||!sxvt_add(c,&sxvt_matroska_block,p))return false;p+=3;unsigned lace=(b>>1)&3;if(lace){if(p==end||!sxvt_byte(c,p,&b)||!sxvt_add(c,&sxvt_matroska_lace_count,p))return false;p++;unsigned count=(unsigned)b+1;if(lace==1){for(unsigned i=1;i<count;i++){do{if(p==end||!sxvt_byte(c,p,&b)||!sxvt_add(c,&sxvt_matroska_xiph_size,p++))return false;}while(b==255);}}else if(lace==3){for(unsigned i=1;i<count;i++){start=p;if(!sxvt_vint(c,&p,end,false,&v,&z)||!sxvt_add(c,i==1?sxvt_laces[z-1]:sxvt_deltas[z-1],start))return false;}}}return true;}
static bool sxvt_mkmaster(uint64_t id){switch(id){case 0x1A45DFA3:case 0x18538067:case 0x1549A966:case 0x1654AE6B:case 0xAE:case 0x1F43B675:case 0xA0:case 0xE0:case 0xE1:case 0x6D80:case 0x6240:case 0x5034:case 0x5035:case 0x1043A770:case 0x45B9:case 0xB6:case 0x80:case 0x1254C367:case 0x7373:case 0x63C0:case 0x67C8:case 0x1941A469:case 0x61A7:case 0x114D9B74:case 0x4DBB:case 0x1C53BB6B:case 0xBB:case 0xB7:return true;default:return false;}}
static unsigned sxvt_mkkind(uint64_t id){switch(id){case 0x42F7:case 0x4286:case 0x42F2:case 0x42F3:case 0x4287:case 0x4285:case 0x2AD7B1:case 0xD7:case 0x73C5:case 0x83:case 0xB9:case 0x88:case 0x55AA:case 0x9C:case 0x6DE7:case 0x6DF8:case 0x23E383:case 0xB0:case 0xBA:case 0x54B0:case 0x54BA:case 0x54B2:case 0x9F:case 0x6264:case 0xE7:case 0xF7:case 0x5378:case 0xB3:case 0x9B:return 1;
 case 0x53AC:case 0xF1:case 0xA7:case 0xF0:return 2;
 case 0x4489:case 0xB5:case 0x78B5:case 0x23314F:return 3;
 case 0x4461:return 4;case 0xBF:return 5;default:return 0;}}
static bool sxvt_mk(sx_context*c,uint64_t p,uint64_t end,unsigned depth,uint64_t parent){if(depth>24)return false;while(p<end&&c->count<SXVT_LIMIT){uint64_t id,n,a=p;unsigned iz,sz;if(!sxvt_vint(c,&p,end,true,&id,&iz))return false;uint64_t b=p;if(!sxvt_vint(c,&p,end,false,&n,&sz))return false;bool unknown=n==((UINT64_C(1)<<(7*sz))-1);if(unknown){if(id!=0x18538067)return false;n=end-p;}if(n>end-p)return false;uint64_t stop=p+n;if(!sxvt_add(c,sxvt_ebml_ids[iz-1],a)||!sxvt_add(c,sxvt_sizes[sz-1],b))return false;
 if(sxvt_mkmaster(id)){(void)sxvt_mk(c,p,stop,depth+1,id);}else if((id==0xA3&&parent==0x1F43B675)||(id==0xA1&&parent==0xA0)){(void)sxvt_mkblock(c,p,stop);}else{unsigned kind=sxvt_mkkind(id);const sx_layout*l=NULL;if((kind==1||kind==2)&&n&&n<=8)l=(kind==1?sxvt_uints:sxvt_offsets)[n-1];else if(kind==3&&(n==4||n==8))l=n==4?&sxvt_matroska_float4:&sxvt_matroska_float8;else if(kind==4&&n==8)l=&sxvt_matroska_date;else if(kind==5&&n==4)l=&sxvt_matroska_crc32;if(l&&!sxvt_add(c,l,p))return false;}p=stop;}return p==end;}
static int sxvt_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxvt_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxvt_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxvt_order);return !c->failed;}
static bool sx_videotail_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_GRASP:case XX_FILE_TYPE_SWF:case XX_FILE_TYPE_MP4:case XX_FILE_TYPE_MATROSKA:case XX_FILE_TYPE_ADOBE_DIRECTOR_CXT:return true;default:return false;}}
static bool sx_videotail_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_GRASP:ok=sxvt_grasp(c);break;case XX_FILE_TYPE_SWF:ok=sxvt_swf(c);break;case XX_FILE_TYPE_MP4:ok=sxvt_mp4(c,0,(uint64_t)c->size,0);break;case XX_FILE_TYPE_MATROSKA:ok=sxvt_mk(c,0,(uint64_t)c->size,0,0);break;case XX_FILE_TYPE_ADOBE_DIRECTOR_CXT:ok=sxvt_director(c);break;default:break;}/* Optional damaged/capped metadata remains raw; keep already framed records. */(void)ok;return c->count&&sxvt_finish(c);}
