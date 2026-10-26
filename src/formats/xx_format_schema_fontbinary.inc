/* SPDX-License-Identifier: MIT
 * Physical binary-font metadata. See docs/data_struct_fontbinary_scope.txt. */
static const xx_data_struct_field_desc sxfb_nintendo_font_header_be_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_ID),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_font_header_be = {UINT32_C(0x60190001),"nintendo_font_header_be",sxfb_nintendo_font_header_be_fields,SX_COUNT(sxfb_nintendo_font_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_font_chunk_be_fields[] = {
    SX_FIELD("block_id","char[4]",0,4,SX_ID),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxfb_nintendo_font_chunk_be = {UINT32_C(0x60190002),"nintendo_font_chunk_be",sxfb_nintendo_font_chunk_be_fields,SX_COUNT(sxfb_nintendo_font_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_bfnt_finf_fields[] = {
    SX_FIELD("font_type","uint8",0,1,SX_ID),
    SX_FIELD("height","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("width","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("ascent","uint8",3,1,SX_NONE),
    SX_FIELD("line_feed","uint16",4,2,SX_NONE),
    SX_FIELD("alternate_character_index","uint16",6,2,SX_ID),
    SX_FIELD("default_left","int8",8,1,SX_NONE),
    SX_FIELD("default_glyph_width","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("default_character_width","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("encoding","uint8",11,1,SX_ID),
    SX_FIELD("texture_header_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("width_header_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("map_header_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxfb_bfnt_finf = {UINT32_C(0x60190003),"bfnt_finf",sxfb_bfnt_finf_fields,SX_COUNT(sxfb_bfnt_finf_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_bfnt_tglp_fields[] = {
    SX_FIELD("cell_width","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("cell_height","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("sheet_count","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("maximum_character_width","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sheet_size","uint32",4,4,SX_SIZE),
    SX_FIELD("baseline_position","uint16",8,2,SX_NONE),
    SX_FIELD("sheet_format","uint16",10,2,SX_ID),
    SX_FIELD("sheet_columns","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("sheet_rows","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("sheet_width","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("sheet_height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("sheet_data_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxfb_bfnt_tglp = {UINT32_C(0x60190004),"bfnt_tglp",sxfb_bfnt_tglp_fields,SX_COUNT(sxfb_bfnt_tglp_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_cwdh_be_fields[] = {
    SX_FIELD("first_glyph","uint16",0,2,SX_ID),
    SX_FIELD("last_glyph","uint16",2,2,SX_ID),
    SX_FIELD("next_body_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxfb_nintendo_cwdh_be = {UINT32_C(0x60190005),"nintendo_cwdh_be",sxfb_nintendo_cwdh_be_fields,SX_COUNT(sxfb_nintendo_cwdh_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_width_be_fields[] = {
    SX_FIELD("left_bearing","int8",0,1,SX_NONE),
    SX_FIELD("glyph_width","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("character_width","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_width_be = {UINT32_C(0x60190006),"nintendo_width_be",sxfb_nintendo_width_be_fields,SX_COUNT(sxfb_nintendo_width_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_cmap_be_fields[] = {
    SX_FIELD("first_character","uint16",0,2,SX_ID),
    SX_FIELD("last_character","uint16",2,2,SX_ID),
    SX_FIELD("method","uint16",4,2,SX_ID),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("next_body_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxfb_nintendo_cmap_be = {UINT32_C(0x60190007),"nintendo_cmap_be",sxfb_nintendo_cmap_be_fields,SX_COUNT(sxfb_nintendo_cmap_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_map_index_be_fields[] = {
    SX_FIELD("glyph_index","uint16",0,2,SX_ID),
};
static const sx_layout sxfb_nintendo_map_index_be = {UINT32_C(0x60190008),"nintendo_map_index_be",sxfb_nintendo_map_index_be_fields,SX_COUNT(sxfb_nintendo_map_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_map_count_be_fields[] = {
    SX_FIELD("pair_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_map_count_be = {UINT32_C(0x60190009),"nintendo_map_count_be",sxfb_nintendo_map_count_be_fields,SX_COUNT(sxfb_nintendo_map_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_map_pair_be_fields[] = {
    SX_FIELD("character","uint16",0,2,SX_ID),
    SX_FIELD("glyph_index","uint16",2,2,SX_ID),
};
static const sx_layout sxfb_nintendo_map_pair_be = {UINT32_C(0x6019000a),"nintendo_map_pair_be",sxfb_nintendo_map_pair_be_fields,SX_COUNT(sxfb_nintendo_map_pair_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_nintendo_font_header_le_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_ID),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_font_header_le = {UINT32_C(0x6019000b),"nintendo_font_header_le",sxfb_nintendo_font_header_le_fields,SX_COUNT(sxfb_nintendo_font_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_font_chunk_le_fields[] = {
    SX_FIELD("block_id","char[4]",0,4,SX_ID),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxfb_nintendo_font_chunk_le = {UINT32_C(0x6019000c),"nintendo_font_chunk_le",sxfb_nintendo_font_chunk_le_fields,SX_COUNT(sxfb_nintendo_font_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_bcfnt_finf_fields[] = {
    SX_FIELD("font_type","uint8",0,1,SX_ID),
    SX_FIELD("line_feed","uint8",1,1,SX_NONE),
    SX_FIELD("alternate_character_index","uint16",2,2,SX_ID),
    SX_FIELD("default_left","int8",4,1,SX_NONE),
    SX_FIELD("default_glyph_width","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("default_character_width","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("encoding","uint8",7,1,SX_ID),
    SX_FIELD("texture_header_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("width_header_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("map_header_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("height","uint8",20,1,SX_COUNT_PROP),
    SX_FIELD("width","uint8",21,1,SX_COUNT_PROP),
    SX_FIELD("ascent","uint8",22,1,SX_NONE),
    SX_FIELD("padding","uint8",23,1,SX_RESERVED),
};
static const sx_layout sxfb_bcfnt_finf = {UINT32_C(0x6019000d),"bcfnt_finf",sxfb_bcfnt_finf_fields,SX_COUNT(sxfb_bcfnt_finf_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_bcfnt_tglp_fields[] = {
    SX_FIELD("cell_width","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("cell_height","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("baseline_position","uint8",2,1,SX_NONE),
    SX_FIELD("maximum_character_width","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sheet_size","uint32",4,4,SX_SIZE),
    SX_FIELD("sheet_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("sheet_format","uint16",10,2,SX_ID),
    SX_FIELD("sheet_columns","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("sheet_rows","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("sheet_width","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("sheet_height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("sheet_data_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxfb_bcfnt_tglp = {UINT32_C(0x6019000e),"bcfnt_tglp",sxfb_bcfnt_tglp_fields,SX_COUNT(sxfb_bcfnt_tglp_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_cwdh_le_fields[] = {
    SX_FIELD("first_glyph","uint16",0,2,SX_ID),
    SX_FIELD("last_glyph","uint16",2,2,SX_ID),
    SX_FIELD("next_body_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxfb_nintendo_cwdh_le = {UINT32_C(0x6019000f),"nintendo_cwdh_le",sxfb_nintendo_cwdh_le_fields,SX_COUNT(sxfb_nintendo_cwdh_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_width_le_fields[] = {
    SX_FIELD("left_bearing","int8",0,1,SX_NONE),
    SX_FIELD("glyph_width","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("character_width","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_width_le = {UINT32_C(0x60190010),"nintendo_width_le",sxfb_nintendo_width_le_fields,SX_COUNT(sxfb_nintendo_width_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_cmap_le_fields[] = {
    SX_FIELD("first_character","uint16",0,2,SX_ID),
    SX_FIELD("last_character","uint16",2,2,SX_ID),
    SX_FIELD("method","uint16",4,2,SX_ID),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("next_body_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxfb_nintendo_cmap_le = {UINT32_C(0x60190011),"nintendo_cmap_le",sxfb_nintendo_cmap_le_fields,SX_COUNT(sxfb_nintendo_cmap_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_map_index_le_fields[] = {
    SX_FIELD("glyph_index","uint16",0,2,SX_ID),
};
static const sx_layout sxfb_nintendo_map_index_le = {UINT32_C(0x60190012),"nintendo_map_index_le",sxfb_nintendo_map_index_le_fields,SX_COUNT(sxfb_nintendo_map_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_map_count_le_fields[] = {
    SX_FIELD("pair_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxfb_nintendo_map_count_le = {UINT32_C(0x60190013),"nintendo_map_count_le",sxfb_nintendo_map_count_le_fields,SX_COUNT(sxfb_nintendo_map_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_nintendo_map_pair_le_fields[] = {
    SX_FIELD("character","uint16",0,2,SX_ID),
    SX_FIELD("glyph_index","uint16",2,2,SX_ID),
};
static const sx_layout sxfb_nintendo_map_pair_le = {UINT32_C(0x60190014),"nintendo_map_pair_le",sxfb_nintendo_map_pair_le_fields,SX_COUNT(sxfb_nintendo_map_pair_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_windows_fnt2_header_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("file_size","uint32",2,4,SX_SIZE),
    SX_FIELD("copyright","char[60]",6,60,SX_STRING),
    SX_FIELD("font_type","uint16",66,2,SX_FLAGS),
    SX_FIELD("point_size","uint16",68,2,SX_NONE),
    SX_FIELD("vertical_resolution","uint16",70,2,SX_NONE),
    SX_FIELD("horizontal_resolution","uint16",72,2,SX_NONE),
    SX_FIELD("ascent","uint16",74,2,SX_NONE),
    SX_FIELD("internal_leading","uint16",76,2,SX_NONE),
    SX_FIELD("external_leading","uint16",78,2,SX_NONE),
    SX_FIELD("italic","uint8",80,1,SX_FLAGS),
    SX_FIELD("underline","uint8",81,1,SX_FLAGS),
    SX_FIELD("strikeout","uint8",82,1,SX_FLAGS),
    SX_FIELD("weight","uint16",83,2,SX_NONE),
    SX_FIELD("character_set","uint8",85,1,SX_ID),
    SX_FIELD("pixel_width","uint16",86,2,SX_COUNT_PROP),
    SX_FIELD("pixel_height","uint16",88,2,SX_COUNT_PROP),
    SX_FIELD("pitch_and_family","uint8",90,1,SX_FLAGS),
    SX_FIELD("average_width","uint16",91,2,SX_COUNT_PROP),
    SX_FIELD("maximum_width","uint16",93,2,SX_COUNT_PROP),
    SX_FIELD("first_character","uint8",95,1,SX_ID),
    SX_FIELD("last_character","uint8",96,1,SX_ID),
    SX_FIELD("default_character_index","uint8",97,1,SX_ID),
    SX_FIELD("break_character_index","uint8",98,1,SX_ID),
    SX_FIELD("bytes_per_row","uint16",99,2,SX_SIZE),
    SX_FIELD("device_name_offset","uint32",101,4,SX_OFFSET),
    SX_FIELD("face_name_offset","uint32",105,4,SX_OFFSET),
    SX_FIELD("bits_pointer","uint32",109,4,SX_POINTER),
    SX_FIELD("bits_offset","uint32",113,4,SX_OFFSET),
    SX_FIELD("reserved","uint8",117,1,SX_RESERVED),
};
static const sx_layout sxfb_windows_fnt2_header = {UINT32_C(0x60190015),"windows_fnt2_header",sxfb_windows_fnt2_header_fields,SX_COUNT(sxfb_windows_fnt2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_windows_fnt3_header_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("file_size","uint32",2,4,SX_SIZE),
    SX_FIELD("copyright","char[60]",6,60,SX_STRING),
    SX_FIELD("font_type","uint16",66,2,SX_FLAGS),
    SX_FIELD("point_size","uint16",68,2,SX_NONE),
    SX_FIELD("vertical_resolution","uint16",70,2,SX_NONE),
    SX_FIELD("horizontal_resolution","uint16",72,2,SX_NONE),
    SX_FIELD("ascent","uint16",74,2,SX_NONE),
    SX_FIELD("internal_leading","uint16",76,2,SX_NONE),
    SX_FIELD("external_leading","uint16",78,2,SX_NONE),
    SX_FIELD("italic","uint8",80,1,SX_FLAGS),
    SX_FIELD("underline","uint8",81,1,SX_FLAGS),
    SX_FIELD("strikeout","uint8",82,1,SX_FLAGS),
    SX_FIELD("weight","uint16",83,2,SX_NONE),
    SX_FIELD("character_set","uint8",85,1,SX_ID),
    SX_FIELD("pixel_width","uint16",86,2,SX_COUNT_PROP),
    SX_FIELD("pixel_height","uint16",88,2,SX_COUNT_PROP),
    SX_FIELD("pitch_and_family","uint8",90,1,SX_FLAGS),
    SX_FIELD("average_width","uint16",91,2,SX_COUNT_PROP),
    SX_FIELD("maximum_width","uint16",93,2,SX_COUNT_PROP),
    SX_FIELD("first_character","uint8",95,1,SX_ID),
    SX_FIELD("last_character","uint8",96,1,SX_ID),
    SX_FIELD("default_character_index","uint8",97,1,SX_ID),
    SX_FIELD("break_character_index","uint8",98,1,SX_ID),
    SX_FIELD("bytes_per_row","uint16",99,2,SX_SIZE),
    SX_FIELD("device_name_offset","uint32",101,4,SX_OFFSET),
    SX_FIELD("face_name_offset","uint32",105,4,SX_OFFSET),
    SX_FIELD("bits_pointer","uint32",109,4,SX_POINTER),
    SX_FIELD("bits_offset","uint32",113,4,SX_OFFSET),
    SX_FIELD("reserved","uint8",117,1,SX_RESERVED),
    SX_FIELD("flags","uint32",118,4,SX_FLAGS),
    SX_FIELD("a_space","uint16",122,2,SX_NONE),
    SX_FIELD("b_space","uint16",124,2,SX_NONE),
    SX_FIELD("c_space","uint16",126,2,SX_NONE),
    SX_FIELD("color_table_offset","uint32",128,4,SX_OFFSET),
    SX_FIELD("reserved1","uint32[4]",132,16,SX_RESERVED),
};
static const sx_layout sxfb_windows_fnt3_header = {UINT32_C(0x60190016),"windows_fnt3_header",sxfb_windows_fnt3_header_fields,SX_COUNT(sxfb_windows_fnt3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_windows_fnt2_glyph_fields[] = {
    SX_FIELD("pixel_width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_offset","uint16",2,2,SX_OFFSET),
};
static const sx_layout sxfb_windows_fnt2_glyph = {UINT32_C(0x60190017),"windows_fnt2_glyph",sxfb_windows_fnt2_glyph_fields,SX_COUNT(sxfb_windows_fnt2_glyph_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_windows_fnt3_glyph_fields[] = {
    SX_FIELD("pixel_width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_offset","uint32",2,4,SX_OFFSET),
};
static const sx_layout sxfb_windows_fnt3_glyph = {UINT32_C(0x60190018),"windows_fnt3_glyph",sxfb_windows_fnt3_glyph_fields,SX_COUNT(sxfb_windows_fnt3_glyph_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_gem_font_header_le_fields[] = {
    SX_FIELD("font_id","int16",0,2,SX_ID),
    SX_FIELD("point_size","int16",2,2,SX_NONE),
    SX_FIELD("font_name","char[32]",4,32,SX_STRING),
    SX_FIELD("first_character","uint16",36,2,SX_ID),
    SX_FIELD("last_character","uint16",38,2,SX_ID),
    SX_FIELD("top","uint16",40,2,SX_NONE),
    SX_FIELD("ascent","uint16",42,2,SX_NONE),
    SX_FIELD("half","uint16",44,2,SX_NONE),
    SX_FIELD("descent","uint16",46,2,SX_NONE),
    SX_FIELD("bottom","uint16",48,2,SX_NONE),
    SX_FIELD("maximum_character_width","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("maximum_cell_width","uint16",52,2,SX_COUNT_PROP),
    SX_FIELD("left_skew_offset","uint16",54,2,SX_NONE),
    SX_FIELD("right_skew_offset","uint16",56,2,SX_NONE),
    SX_FIELD("thicken","uint16",58,2,SX_NONE),
    SX_FIELD("underline_height","uint16",60,2,SX_COUNT_PROP),
    SX_FIELD("lighten_mask","uint16",62,2,SX_FLAGS),
    SX_FIELD("skew_mask","uint16",64,2,SX_FLAGS),
    SX_FIELD("flags","uint16",66,2,SX_FLAGS),
    SX_FIELD("horizontal_table_offset","uint32",68,4,SX_OFFSET),
    SX_FIELD("glyph_offset_table_offset","uint32",72,4,SX_OFFSET),
    SX_FIELD("bitmap_offset","uint32",76,4,SX_OFFSET),
    SX_FIELD("form_width_bytes","uint16",80,2,SX_SIZE),
    SX_FIELD("form_height_lines","uint16",82,2,SX_COUNT_PROP),
    SX_FIELD("next_font_pointer","uint32",84,4,SX_POINTER),
};
static const sx_layout sxfb_gem_font_header_le = {UINT32_C(0x60190019),"gem_font_header_le",sxfb_gem_font_header_le_fields,SX_COUNT(sxfb_gem_font_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_gem_glyph_bit_position_le_fields[] = {
    SX_FIELD("bit_position","uint16",0,2,SX_NONE),
};
static const sx_layout sxfb_gem_glyph_bit_position_le = {UINT32_C(0x6019001a),"gem_glyph_bit_position_le",sxfb_gem_glyph_bit_position_le_fields,SX_COUNT(sxfb_gem_glyph_bit_position_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_gem_font_header_be_fields[] = {
    SX_FIELD("font_id","int16",0,2,SX_ID),
    SX_FIELD("point_size","int16",2,2,SX_NONE),
    SX_FIELD("font_name","char[32]",4,32,SX_STRING),
    SX_FIELD("first_character","uint16",36,2,SX_ID),
    SX_FIELD("last_character","uint16",38,2,SX_ID),
    SX_FIELD("top","uint16",40,2,SX_NONE),
    SX_FIELD("ascent","uint16",42,2,SX_NONE),
    SX_FIELD("half","uint16",44,2,SX_NONE),
    SX_FIELD("descent","uint16",46,2,SX_NONE),
    SX_FIELD("bottom","uint16",48,2,SX_NONE),
    SX_FIELD("maximum_character_width","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("maximum_cell_width","uint16",52,2,SX_COUNT_PROP),
    SX_FIELD("left_skew_offset","uint16",54,2,SX_NONE),
    SX_FIELD("right_skew_offset","uint16",56,2,SX_NONE),
    SX_FIELD("thicken","uint16",58,2,SX_NONE),
    SX_FIELD("underline_height","uint16",60,2,SX_COUNT_PROP),
    SX_FIELD("lighten_mask","uint16",62,2,SX_FLAGS),
    SX_FIELD("skew_mask","uint16",64,2,SX_FLAGS),
    SX_FIELD("flags","uint16",66,2,SX_FLAGS),
    SX_FIELD("horizontal_table_offset","uint32",68,4,SX_OFFSET),
    SX_FIELD("glyph_offset_table_offset","uint32",72,4,SX_OFFSET),
    SX_FIELD("bitmap_offset","uint32",76,4,SX_OFFSET),
    SX_FIELD("form_width_bytes","uint16",80,2,SX_SIZE),
    SX_FIELD("form_height_lines","uint16",82,2,SX_COUNT_PROP),
    SX_FIELD("next_font_pointer","uint32",84,4,SX_POINTER),
};
static const sx_layout sxfb_gem_font_header_be = {UINT32_C(0x6019001b),"gem_font_header_be",sxfb_gem_font_header_be_fields,SX_COUNT(sxfb_gem_font_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gem_glyph_bit_position_be_fields[] = {
    SX_FIELD("bit_position","uint16",0,2,SX_NONE),
};
static const sx_layout sxfb_gem_glyph_bit_position_be = {UINT32_C(0x6019001c),"gem_glyph_bit_position_be",sxfb_gem_glyph_bit_position_be_fields,SX_COUNT(sxfb_gem_glyph_bit_position_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gem_horizontal_offsets_fields[] = {
    SX_FIELD("encoded_offsets","uint8[2]",0,2,SX_NONE),
};
static const sx_layout sxfb_gem_horizontal_offsets = {UINT32_C(0x6019001d),"gem_horizontal_offsets",sxfb_gem_horizontal_offsets_fields,SX_COUNT(sxfb_gem_horizontal_offsets_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_counts_fields[] = {
    SX_FIELD("file_words","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("header_words","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("first_character","uint16",4,2,SX_ID),
    SX_FIELD("last_character","uint16",6,2,SX_ID),
    SX_FIELD("width_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("height_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("depth_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("italic_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("ligature_kern_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("kern_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("recipe_count","uint16",20,2,SX_COUNT_PROP),
    SX_FIELD("parameter_count","uint16",22,2,SX_COUNT_PROP),
};
static const sx_layout sxfb_tfm_counts = {UINT32_C(0x6019001e),"tfm_counts",sxfb_tfm_counts_fields,SX_COUNT(sxfb_tfm_counts_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_header_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("design_size","int32",4,4,SX_NONE),
};
static const sx_layout sxfb_tfm_header = {UINT32_C(0x6019001f),"tfm_header",sxfb_tfm_header_fields,SX_COUNT(sxfb_tfm_header_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_coding_scheme_fields[] = {
    SX_FIELD("string_length","uint8",0,1,SX_SIZE),
    SX_FIELD("coding_scheme","char[39]",1,39,SX_STRING),
};
static const sx_layout sxfb_tfm_coding_scheme = {UINT32_C(0x60190020),"tfm_coding_scheme",sxfb_tfm_coding_scheme_fields,SX_COUNT(sxfb_tfm_coding_scheme_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_family_fields[] = {
    SX_FIELD("string_length","uint8",0,1,SX_SIZE),
    SX_FIELD("family","char[19]",1,19,SX_STRING),
};
static const sx_layout sxfb_tfm_family = {UINT32_C(0x60190021),"tfm_family",sxfb_tfm_family_fields,SX_COUNT(sxfb_tfm_family_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_face_fields[] = {
    SX_FIELD("seven_bit_safe","uint8",0,1,SX_FLAGS),
    SX_FIELD("unused","uint8[2]",1,2,SX_RESERVED),
    SX_FIELD("face","uint8",3,1,SX_ID),
};
static const sx_layout sxfb_tfm_face = {UINT32_C(0x60190022),"tfm_face",sxfb_tfm_face_fields,SX_COUNT(sxfb_tfm_face_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_character_fields[] = {
    SX_FIELD("width_index","uint8",0,1,SX_ID),
    SX_FIELD("height_depth_indexes","uint8",1,1,SX_NONE),
    SX_FIELD("italic_index_and_tag","uint8",2,1,SX_NONE),
    SX_FIELD("remainder","uint8",3,1,SX_ID),
};
static const sx_layout sxfb_tfm_character = {UINT32_C(0x60190023),"tfm_character",sxfb_tfm_character_fields,SX_COUNT(sxfb_tfm_character_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_width_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxfb_tfm_width = {UINT32_C(0x60190024),"tfm_width",sxfb_tfm_width_fields,SX_COUNT(sxfb_tfm_width_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_height_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxfb_tfm_height = {UINT32_C(0x60190025),"tfm_height",sxfb_tfm_height_fields,SX_COUNT(sxfb_tfm_height_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_depth_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxfb_tfm_depth = {UINT32_C(0x60190026),"tfm_depth",sxfb_tfm_depth_fields,SX_COUNT(sxfb_tfm_depth_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_italic_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxfb_tfm_italic = {UINT32_C(0x60190027),"tfm_italic",sxfb_tfm_italic_fields,SX_COUNT(sxfb_tfm_italic_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_kern_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxfb_tfm_kern = {UINT32_C(0x60190028),"tfm_kern",sxfb_tfm_kern_fields,SX_COUNT(sxfb_tfm_kern_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_parameter_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxfb_tfm_parameter = {UINT32_C(0x60190029),"tfm_parameter",sxfb_tfm_parameter_fields,SX_COUNT(sxfb_tfm_parameter_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_ligature_kern_fields[] = {
    SX_FIELD("skip_byte","uint8",0,1,SX_NONE),
    SX_FIELD("next_character","uint8",1,1,SX_ID),
    SX_FIELD("operation_byte","uint8",2,1,SX_NONE),
    SX_FIELD("remainder","uint8",3,1,SX_NONE),
};
static const sx_layout sxfb_tfm_ligature_kern = {UINT32_C(0x6019002a),"tfm_ligature_kern",sxfb_tfm_ligature_kern_fields,SX_COUNT(sxfb_tfm_ligature_kern_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_extensible_recipe_fields[] = {
    SX_FIELD("top_character","uint8",0,1,SX_ID),
    SX_FIELD("middle_character","uint8",1,1,SX_ID),
    SX_FIELD("bottom_character","uint8",2,1,SX_ID),
    SX_FIELD("repeat_character","uint8",3,1,SX_ID),
};
static const sx_layout sxfb_tfm_extensible_recipe = {UINT32_C(0x6019002b),"tfm_extensible_recipe",sxfb_tfm_extensible_recipe_fields,SX_COUNT(sxfb_tfm_extensible_recipe_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_font_preamble_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("format_id","uint8",1,1,SX_ID),
    SX_FIELD("comment_length","uint8",2,1,SX_SIZE),
};
static const sx_layout sxfb_tex_font_preamble = {UINT32_C(0x6019002c),"tex_font_preamble",sxfb_tex_font_preamble_fields,SX_COUNT(sxfb_tex_font_preamble_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_pk_metrics_fields[] = {
    SX_FIELD("design_size","int32",0,4,SX_NONE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("horizontal_pixels_per_point","int32",8,4,SX_NONE),
    SX_FIELD("vertical_pixels_per_point","int32",12,4,SX_NONE),
};
static const sx_layout sxfb_pk_metrics = {UINT32_C(0x6019002d),"pk_metrics",sxfb_pk_metrics_fields,SX_COUNT(sxfb_pk_metrics_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_pk_short_glyph_fields[] = {
    SX_FIELD("flag","uint8",0,1,SX_FLAGS),
    SX_FIELD("packet_size_low","uint8",1,1,SX_NONE),
    SX_FIELD("character_code","uint8",2,1,SX_ID),
    SX_FIELD("tfm_width","uint24",3,3,SX_NONE),
    SX_FIELD("dx","uint8",6,1,SX_NONE),
    SX_FIELD("width_pixels","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("height_pixels","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("horizontal_offset","int8",9,1,SX_NONE),
    SX_FIELD("vertical_offset","int8",10,1,SX_NONE),
};
static const sx_layout sxfb_pk_short_glyph = {UINT32_C(0x6019002e),"pk_short_glyph",sxfb_pk_short_glyph_fields,SX_COUNT(sxfb_pk_short_glyph_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_pk_extended_glyph_fields[] = {
    SX_FIELD("flag","uint8",0,1,SX_FLAGS),
    SX_FIELD("packet_size_low","uint16",1,2,SX_NONE),
    SX_FIELD("character_code","uint8",3,1,SX_ID),
    SX_FIELD("tfm_width","uint24",4,3,SX_NONE),
    SX_FIELD("dx","uint16",7,2,SX_NONE),
    SX_FIELD("width_pixels","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("height_pixels","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("horizontal_offset","int16",13,2,SX_NONE),
    SX_FIELD("vertical_offset","int16",15,2,SX_NONE),
};
static const sx_layout sxfb_pk_extended_glyph = {UINT32_C(0x6019002f),"pk_extended_glyph",sxfb_pk_extended_glyph_fields,SX_COUNT(sxfb_pk_extended_glyph_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_pk_long_glyph_fields[] = {
    SX_FIELD("flag","uint8",0,1,SX_FLAGS),
    SX_FIELD("packet_size","int32",1,4,SX_SIZE),
    SX_FIELD("character_code","int32",5,4,SX_ID),
    SX_FIELD("tfm_width","int32",9,4,SX_NONE),
    SX_FIELD("dx","int32",13,4,SX_NONE),
    SX_FIELD("dy","int32",17,4,SX_NONE),
    SX_FIELD("width_pixels","int32",21,4,SX_COUNT_PROP),
    SX_FIELD("height_pixels","int32",25,4,SX_COUNT_PROP),
    SX_FIELD("horizontal_offset","int32",29,4,SX_NONE),
    SX_FIELD("vertical_offset","int32",33,4,SX_NONE),
};
static const sx_layout sxfb_pk_long_glyph = {UINT32_C(0x60190030),"pk_long_glyph",sxfb_pk_long_glyph_fields,SX_COUNT(sxfb_pk_long_glyph_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_opcode_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
};
static const sx_layout sxfb_tex_opcode = {UINT32_C(0x60190031),"tex_opcode",sxfb_tex_opcode_fields,SX_COUNT(sxfb_tex_opcode_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_special1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("payload_size","uint8",1,1,SX_SIZE),
};
static const sx_layout sxfb_tex_special1 = {UINT32_C(0x60190032),"tex_special1",sxfb_tex_special1_fields,SX_COUNT(sxfb_tex_special1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_special2_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("payload_size","uint16",1,2,SX_SIZE),
};
static const sx_layout sxfb_tex_special2 = {UINT32_C(0x60190033),"tex_special2",sxfb_tex_special2_fields,SX_COUNT(sxfb_tex_special2_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_special3_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("payload_size","uint24",1,3,SX_SIZE),
};
static const sx_layout sxfb_tex_special3 = {UINT32_C(0x60190034),"tex_special3",sxfb_tex_special3_fields,SX_COUNT(sxfb_tex_special3_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_special4_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("payload_size","int32",1,4,SX_SIZE),
};
static const sx_layout sxfb_tex_special4 = {UINT32_C(0x60190035),"tex_special4",sxfb_tex_special4_fields,SX_COUNT(sxfb_tex_special4_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tex_numeric_special_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("value","int32",1,4,SX_NONE),
};
static const sx_layout sxfb_tex_numeric_special = {UINT32_C(0x60190036),"tex_numeric_special",sxfb_tex_numeric_special_fields,SX_COUNT(sxfb_tex_numeric_special_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_boc_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("character_code","int32",1,4,SX_ID),
    SX_FIELD("previous_boc_offset","int32",5,4,SX_OFFSET),
    SX_FIELD("minimum_m","int32",9,4,SX_NONE),
    SX_FIELD("maximum_m","int32",13,4,SX_NONE),
    SX_FIELD("minimum_n","int32",17,4,SX_NONE),
    SX_FIELD("maximum_n","int32",21,4,SX_NONE),
};
static const sx_layout sxfb_gf_boc = {UINT32_C(0x60190037),"gf_boc",sxfb_gf_boc_fields,SX_COUNT(sxfb_gf_boc_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_boc1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("character_code","uint8",1,1,SX_ID),
    SX_FIELD("delta_m","uint8",2,1,SX_NONE),
    SX_FIELD("maximum_m","uint8",3,1,SX_NONE),
    SX_FIELD("delta_n","uint8",4,1,SX_NONE),
    SX_FIELD("maximum_n","uint8",5,1,SX_NONE),
};
static const sx_layout sxfb_gf_boc1 = {UINT32_C(0x60190038),"gf_boc1",sxfb_gf_boc1_fields,SX_COUNT(sxfb_gf_boc1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_paint1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("pixel_count","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxfb_gf_paint1 = {UINT32_C(0x60190039),"gf_paint1",sxfb_gf_paint1_fields,SX_COUNT(sxfb_gf_paint1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_skip1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("extra_rows","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxfb_gf_skip1 = {UINT32_C(0x6019003a),"gf_skip1",sxfb_gf_skip1_fields,SX_COUNT(sxfb_gf_skip1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_paint2_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("pixel_count","uint16",1,2,SX_COUNT_PROP),
};
static const sx_layout sxfb_gf_paint2 = {UINT32_C(0x6019003b),"gf_paint2",sxfb_gf_paint2_fields,SX_COUNT(sxfb_gf_paint2_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_skip2_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("extra_rows","uint16",1,2,SX_COUNT_PROP),
};
static const sx_layout sxfb_gf_skip2 = {UINT32_C(0x6019003c),"gf_skip2",sxfb_gf_skip2_fields,SX_COUNT(sxfb_gf_skip2_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_paint3_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("pixel_count","uint24",1,3,SX_COUNT_PROP),
};
static const sx_layout sxfb_gf_paint3 = {UINT32_C(0x6019003d),"gf_paint3",sxfb_gf_paint3_fields,SX_COUNT(sxfb_gf_paint3_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_skip3_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("extra_rows","uint24",1,3,SX_COUNT_PROP),
};
static const sx_layout sxfb_gf_skip3 = {UINT32_C(0x6019003e),"gf_skip3",sxfb_gf_skip3_fields,SX_COUNT(sxfb_gf_skip3_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_post_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("previous_eoc_offset","int32",1,4,SX_OFFSET),
    SX_FIELD("design_size","int32",5,4,SX_NONE),
    SX_FIELD("checksum","uint32",9,4,SX_CHECKSUM),
    SX_FIELD("horizontal_pixels_per_point","int32",13,4,SX_NONE),
    SX_FIELD("vertical_pixels_per_point","int32",17,4,SX_NONE),
    SX_FIELD("minimum_m","int32",21,4,SX_NONE),
    SX_FIELD("maximum_m","int32",25,4,SX_NONE),
    SX_FIELD("minimum_n","int32",29,4,SX_NONE),
    SX_FIELD("maximum_n","int32",33,4,SX_NONE),
};
static const sx_layout sxfb_gf_post = {UINT32_C(0x6019003f),"gf_post",sxfb_gf_post_fields,SX_COUNT(sxfb_gf_post_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_char_loc_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("character_code","uint8",1,1,SX_ID),
    SX_FIELD("dx","int32",2,4,SX_NONE),
    SX_FIELD("dy","int32",6,4,SX_NONE),
    SX_FIELD("tfm_width","int32",10,4,SX_NONE),
    SX_FIELD("packet_offset","int32",14,4,SX_OFFSET),
};
static const sx_layout sxfb_gf_char_loc = {UINT32_C(0x60190040),"gf_char_loc",sxfb_gf_char_loc_fields,SX_COUNT(sxfb_gf_char_loc_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_char_loc0_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("character_code","uint8",1,1,SX_ID),
    SX_FIELD("dx","uint8",2,1,SX_NONE),
    SX_FIELD("tfm_width","int32",3,4,SX_NONE),
    SX_FIELD("packet_offset","int32",7,4,SX_OFFSET),
};
static const sx_layout sxfb_gf_char_loc0 = {UINT32_C(0x60190041),"gf_char_loc0",sxfb_gf_char_loc0_fields,SX_COUNT(sxfb_gf_char_loc0_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_postpost_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("postamble_offset","int32",1,4,SX_OFFSET),
    SX_FIELD("format_id","uint8",5,1,SX_ID),
};
static const sx_layout sxfb_gf_postpost = {UINT32_C(0x60190042),"gf_postpost",sxfb_gf_postpost_fields,SX_COUNT(sxfb_gf_postpost_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_metrics_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("design_size","int32",4,4,SX_NONE),
};
static const sx_layout sxfb_vf_metrics = {UINT32_C(0x60190043),"vf_metrics",sxfb_vf_metrics_fields,SX_COUNT(sxfb_vf_metrics_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_font_definition1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("font_number","uint8",1,1,SX_ID),
    SX_FIELD("checksum","uint32",2,4,SX_CHECKSUM),
    SX_FIELD("scale","int32",6,4,SX_NONE),
    SX_FIELD("design_size","int32",10,4,SX_NONE),
    SX_FIELD("area_length","uint8",14,1,SX_SIZE),
    SX_FIELD("name_length","uint8",15,1,SX_SIZE),
};
static const sx_layout sxfb_vf_font_definition1 = {UINT32_C(0x60190044),"vf_font_definition1",sxfb_vf_font_definition1_fields,SX_COUNT(sxfb_vf_font_definition1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_font_definition2_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("font_number","uint16",1,2,SX_ID),
    SX_FIELD("checksum","uint32",3,4,SX_CHECKSUM),
    SX_FIELD("scale","int32",7,4,SX_NONE),
    SX_FIELD("design_size","int32",11,4,SX_NONE),
    SX_FIELD("area_length","uint8",15,1,SX_SIZE),
    SX_FIELD("name_length","uint8",16,1,SX_SIZE),
};
static const sx_layout sxfb_vf_font_definition2 = {UINT32_C(0x60190045),"vf_font_definition2",sxfb_vf_font_definition2_fields,SX_COUNT(sxfb_vf_font_definition2_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_font_definition3_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("font_number","uint24",1,3,SX_ID),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("scale","int32",8,4,SX_NONE),
    SX_FIELD("design_size","int32",12,4,SX_NONE),
    SX_FIELD("area_length","uint8",16,1,SX_SIZE),
    SX_FIELD("name_length","uint8",17,1,SX_SIZE),
};
static const sx_layout sxfb_vf_font_definition3 = {UINT32_C(0x60190046),"vf_font_definition3",sxfb_vf_font_definition3_fields,SX_COUNT(sxfb_vf_font_definition3_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_font_definition4_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("font_number","int32",1,4,SX_ID),
    SX_FIELD("checksum","uint32",5,4,SX_CHECKSUM),
    SX_FIELD("scale","int32",9,4,SX_NONE),
    SX_FIELD("design_size","int32",13,4,SX_NONE),
    SX_FIELD("area_length","uint8",17,1,SX_SIZE),
    SX_FIELD("name_length","uint8",18,1,SX_SIZE),
};
static const sx_layout sxfb_vf_font_definition4 = {UINT32_C(0x60190047),"vf_font_definition4",sxfb_vf_font_definition4_fields,SX_COUNT(sxfb_vf_font_definition4_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_short_packet_fields[] = {
    SX_FIELD("packet_size","uint8",0,1,SX_SIZE),
    SX_FIELD("character_code","uint8",1,1,SX_ID),
    SX_FIELD("tfm_width","uint24",2,3,SX_NONE),
};
static const sx_layout sxfb_vf_short_packet = {UINT32_C(0x60190048),"vf_short_packet",sxfb_vf_short_packet_fields,SX_COUNT(sxfb_vf_short_packet_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_long_packet_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("packet_size","int32",1,4,SX_SIZE),
    SX_FIELD("character_code","int32",5,4,SX_ID),
    SX_FIELD("tfm_width","int32",9,4,SX_NONE),
};
static const sx_layout sxfb_vf_long_packet = {UINT32_C(0x60190049),"vf_long_packet",sxfb_vf_long_packet_fields,SX_COUNT(sxfb_vf_long_packet_fields),SX_BE};
static const sx_layout *const sx_fontbinary_layouts[] = {
    &sxfb_nintendo_font_header_be,
    &sxfb_nintendo_font_chunk_be,
    &sxfb_bfnt_finf,
    &sxfb_bfnt_tglp,
    &sxfb_nintendo_cwdh_be,
    &sxfb_nintendo_width_be,
    &sxfb_nintendo_cmap_be,
    &sxfb_nintendo_map_index_be,
    &sxfb_nintendo_map_count_be,
    &sxfb_nintendo_map_pair_be,
    &sxfb_nintendo_font_header_le,
    &sxfb_nintendo_font_chunk_le,
    &sxfb_bcfnt_finf,
    &sxfb_bcfnt_tglp,
    &sxfb_nintendo_cwdh_le,
    &sxfb_nintendo_width_le,
    &sxfb_nintendo_cmap_le,
    &sxfb_nintendo_map_index_le,
    &sxfb_nintendo_map_count_le,
    &sxfb_nintendo_map_pair_le,
    &sxfb_windows_fnt2_header,
    &sxfb_windows_fnt3_header,
    &sxfb_windows_fnt2_glyph,
    &sxfb_windows_fnt3_glyph,
    &sxfb_gem_font_header_le,
    &sxfb_gem_glyph_bit_position_le,
    &sxfb_gem_font_header_be,
    &sxfb_gem_glyph_bit_position_be,
    &sxfb_gem_horizontal_offsets,
    &sxfb_tfm_counts,
    &sxfb_tfm_header,
    &sxfb_tfm_coding_scheme,
    &sxfb_tfm_family,
    &sxfb_tfm_face,
    &sxfb_tfm_character,
    &sxfb_tfm_width,
    &sxfb_tfm_height,
    &sxfb_tfm_depth,
    &sxfb_tfm_italic,
    &sxfb_tfm_kern,
    &sxfb_tfm_parameter,
    &sxfb_tfm_ligature_kern,
    &sxfb_tfm_extensible_recipe,
    &sxfb_tex_font_preamble,
    &sxfb_pk_metrics,
    &sxfb_pk_short_glyph,
    &sxfb_pk_extended_glyph,
    &sxfb_pk_long_glyph,
    &sxfb_tex_opcode,
    &sxfb_tex_special1,
    &sxfb_tex_special2,
    &sxfb_tex_special3,
    &sxfb_tex_special4,
    &sxfb_tex_numeric_special,
    &sxfb_gf_boc,
    &sxfb_gf_boc1,
    &sxfb_gf_paint1,
    &sxfb_gf_skip1,
    &sxfb_gf_paint2,
    &sxfb_gf_skip2,
    &sxfb_gf_paint3,
    &sxfb_gf_skip3,
    &sxfb_gf_post,
    &sxfb_gf_char_loc,
    &sxfb_gf_char_loc0,
    &sxfb_gf_postpost,
    &sxfb_vf_metrics,
    &sxfb_vf_font_definition1,
    &sxfb_vf_font_definition2,
    &sxfb_vf_font_definition3,
    &sxfb_vf_font_definition4,
    &sxfb_vf_short_packet,
    &sxfb_vf_long_packet,
};
static bool sx_fontbinary_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60190000U||id>=0x601a0000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60190003U:
        if(!xx_rt_wcscmp(r->name,L"texture_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        if(!xx_rt_wcscmp(r->name,L"width_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        if(!xx_rt_wcscmp(r->name,L"map_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        break;
    case 0x60190005U:
        if(!xx_rt_wcscmp(r->name,L"next_body_offset"))text=L"File-relative byte offset to next CWDH body; zero ends the chain.";
        break;
    case 0x60190007U:
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=direct, 1=table, 2=scan pairs.";
        if(!xx_rt_wcscmp(r->name,L"next_body_offset"))text=L"File-relative byte offset to next CMAP body; zero ends the chain.";
        break;
    case 0x60190008U:
        if(!xx_rt_wcscmp(r->name,L"glyph_index"))text=L"Direct mapping start or indexed glyph; 65535 marks an absent indexed glyph.";
        break;
    case 0x6019000dU:
        if(!xx_rt_wcscmp(r->name,L"texture_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        if(!xx_rt_wcscmp(r->name,L"width_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        if(!xx_rt_wcscmp(r->name,L"map_header_offset"))text=L"File-relative byte offset to block body, eight bytes after its magic.";
        break;
    case 0x6019000fU:
        if(!xx_rt_wcscmp(r->name,L"next_body_offset"))text=L"File-relative byte offset to next CWDH body; zero ends the chain.";
        break;
    case 0x60190011U:
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=direct, 1=table, 2=scan pairs.";
        if(!xx_rt_wcscmp(r->name,L"next_body_offset"))text=L"File-relative byte offset to next CMAP body; zero ends the chain.";
        break;
    case 0x60190012U:
        if(!xx_rt_wcscmp(r->name,L"glyph_index"))text=L"Direct mapping start or indexed glyph; 65535 marks an absent indexed glyph.";
        break;
    case 0x60190015U:
        if(!xx_rt_wcscmp(r->name,L"default_character_index"))text=L"Relative to first_character, not an absolute character code.";
        if(!xx_rt_wcscmp(r->name,L"break_character_index"))text=L"Relative to first_character, not an absolute character code.";
        if(!xx_rt_wcscmp(r->name,L"bits_pointer"))text=L"Runtime pointer word, normally zero in a disk font.";
        break;
    case 0x60190016U:
        if(!xx_rt_wcscmp(r->name,L"default_character_index"))text=L"Relative to first_character, not an absolute character code.";
        if(!xx_rt_wcscmp(r->name,L"break_character_index"))text=L"Relative to first_character, not an absolute character code.";
        if(!xx_rt_wcscmp(r->name,L"bits_pointer"))text=L"Runtime pointer word, normally zero in a disk font.";
        break;
    case 0x60190019U:
        if(!xx_rt_wcscmp(r->name,L"left_skew_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"right_skew_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"1=default, 2=horizontal table, 4=Motorola standard bitmap, 8=monospaced.";
        if(!xx_rt_wcscmp(r->name,L"next_font_pointer"))text=L"Runtime linked-font pointer; native standalone files require zero.";
        break;
    case 0x6019001aU:
        if(!xx_rt_wcscmp(r->name,L"bit_position"))text=L"Horizontal bit position in a raster row; not a byte offset.";
        break;
    case 0x6019001bU:
        if(!xx_rt_wcscmp(r->name,L"left_skew_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"right_skew_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"1=default, 2=horizontal table, 4=Motorola standard bitmap, 8=monospaced.";
        if(!xx_rt_wcscmp(r->name,L"next_font_pointer"))text=L"Runtime linked-font pointer; native standalone files require zero.";
        break;
    case 0x6019001cU:
        if(!xx_rt_wcscmp(r->name,L"bit_position"))text=L"Horizontal bit position in a raster row; not a byte offset.";
        break;
    case 0x6019001dU:
        if(!xx_rt_wcscmp(r->name,L"encoded_offsets"))text=L"Original two-byte horizontal offset entry; preserved without synthesizing metrics.";
        break;
    case 0x6019001eU:
        if(!xx_rt_wcscmp(r->name,L"file_words"))text=L"Total file length in four-byte words.";
        if(!xx_rt_wcscmp(r->name,L"header_words"))text=L"Header length in four-byte words.";
        break;
    case 0x6019001fU:
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Signed fixed-point points with 20 fractional bits.";
        break;
    case 0x60190023U:
        if(!xx_rt_wcscmp(r->name,L"height_depth_indexes"))text=L"High nibble=height table index; low nibble=depth table index.";
        if(!xx_rt_wcscmp(r->name,L"italic_index_and_tag"))text=L"High 6 bits=italic index; low 2 bits select remainder interpretation.";
        if(!xx_rt_wcscmp(r->name,L"remainder"))text=L"Tag 0=unused,1=ligature program,2=next character,3=extensible recipe.";
        break;
    case 0x60190024U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190025U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190026U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190027U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190028U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x60190029U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed fixed-point word with 20 fractional bits; units depend on the metric or parameter.";
        break;
    case 0x6019002aU:
        if(!xx_rt_wcscmp(r->name,L"remainder"))text=L"Ligature operation or kern/restart index component, selected by skip and operation bytes.";
        break;
    case 0x6019002dU:
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_pixels_per_point"))text=L"Fixed-point ratio with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"vertical_pixels_per_point"))text=L"Fixed-point ratio with 16 fractional bits.";
        break;
    case 0x6019002eU:
        if(!xx_rt_wcscmp(r->name,L"packet_size_low"))text=L"Low packet-length bits; remaining bits are encoded in the low three flag bits.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"width_pixels"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"height_pixels"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_offset"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"vertical_offset"))text=L"Pixel quantity, not a file offset.";
        break;
    case 0x6019002fU:
        if(!xx_rt_wcscmp(r->name,L"packet_size_low"))text=L"Low packet-length bits; remaining bits are encoded in the low three flag bits.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"width_pixels"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"height_pixels"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_offset"))text=L"Pixel quantity, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"vertical_offset"))text=L"Pixel quantity, not a file offset.";
        break;
    case 0x60190030U:
        if(!xx_rt_wcscmp(r->name,L"packet_size"))text=L"Byte count beginning at tfm_width, including metrics and raster.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Signed fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Pixel escapement with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dy"))text=L"Pixel escapement with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"vertical_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x60190037U:
        if(!xx_rt_wcscmp(r->name,L"previous_boc_offset"))text=L"Relative file byte offset; -1 means no previous character packet.";
        break;
    case 0x6019003aU:
        if(!xx_rt_wcscmp(r->name,L"extra_rows"))text=L"Actual row advance is this value plus one.";
        break;
    case 0x6019003cU:
        if(!xx_rt_wcscmp(r->name,L"extra_rows"))text=L"Actual row advance is this value plus one.";
        break;
    case 0x6019003eU:
        if(!xx_rt_wcscmp(r->name,L"extra_rows"))text=L"Actual row advance is this value plus one.";
        break;
    case 0x6019003fU:
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"horizontal_pixels_per_point"))text=L"Fixed-point ratio with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"vertical_pixels_per_point"))text=L"Fixed-point ratio with 16 fractional bits.";
        break;
    case 0x60190040U:
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Pixel escapement with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"dy"))text=L"Pixel escapement with 16 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Signed fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"packet_offset"))text=L"File-relative byte offset; -1 means no packet.";
        break;
    case 0x60190041U:
        if(!xx_rt_wcscmp(r->name,L"dx"))text=L"Whole-pixel horizontal escapement.";
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Signed fixed-point width with 20 fractional bits.";
        if(!xx_rt_wcscmp(r->name,L"packet_offset"))text=L"File-relative byte offset; -1 means no packet.";
        break;
    case 0x60190043U:
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190044U:
        if(!xx_rt_wcscmp(r->name,L"scale"))text=L"Fixed-point scale with 20 fractional bits relative to the VF design size.";
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190045U:
        if(!xx_rt_wcscmp(r->name,L"scale"))text=L"Fixed-point scale with 20 fractional bits relative to the VF design size.";
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190046U:
        if(!xx_rt_wcscmp(r->name,L"scale"))text=L"Fixed-point scale with 20 fractional bits relative to the VF design size.";
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190047U:
        if(!xx_rt_wcscmp(r->name,L"scale"))text=L"Fixed-point scale with 20 fractional bits relative to the VF design size.";
        if(!xx_rt_wcscmp(r->name,L"design_size"))text=L"Fixed-point points with 20 fractional bits.";
        break;
    case 0x60190048U:
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Fixed-point width with 20 fractional bits.";
        break;
    case 0x60190049U:
        if(!xx_rt_wcscmp(r->name,L"tfm_width"))text=L"Signed fixed-point width with 20 fractional bits.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}

/* These walkers describe only original bytes, not decoded glyph raster data. */
static bool sxfb_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxfb_read(sx_context *c,uint64_t p,void *b,size_t n){return sxfb_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint32_t sxfb_uint(const uint8_t *b,unsigned n,bool be){uint32_t x=0;for(unsigned i=0;i<n;i++)x|=(uint32_t)b[i]<<(8*(be?n-1-i:i));return x;}
static uint16_t sxfb16(const uint8_t *b,bool be){return (uint16_t)sxfb_uint(b,2,be);}
static uint32_t sxfb32(const uint8_t *b,bool be){return sxfb_uint(b,4,be);}
static bool sxfb_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return p<=INT64_MAX&&sx_add(c,l,(int64_t)p,f->rel_offset+f->size);}
static bool sxfb_nintendo(sx_context *c,bool be)
{
 uint8_t h[32];if(!sxfb_read(c,0,h,20)||xx_rt_memcmp(h,be?"FFNT":"CFNT",4)||sxfb16(h+4,be)!=0xfeff||sxfb16(h+6,be)!=20)return false;
 uint32_t size=sxfb32(h+12,be),blocks=sxfb32(h+16,be);if(size<20||!sxfb_span(c,0,size)||blocks>1024)return false;
 if(!sxfb_add(c,be?&sxfb_nintendo_font_header_be:&sxfb_nintendo_font_header_le,0))return false;uint64_t p=20;
 for(uint32_t i=0;i<blocks;i++){
  if(p>size||size-p<8||!sxfb_read(c,p,h,8))break;uint32_t z=sxfb32(h+4,be);if(z<8||z>size-p)break;
  if(!sxfb_add(c,be?&sxfb_nintendo_font_chunk_be:&sxfb_nintendo_font_chunk_le,p))return false;
  if(!xx_rt_memcmp(h,"FINF",4)&&z>=32){if(!sxfb_add(c,be?&sxfb_bfnt_finf:&sxfb_bcfnt_finf,p+8))return false;}
  else if(!xx_rt_memcmp(h,"TGLP",4)&&z>=32){if(!sxfb_add(c,be?&sxfb_bfnt_tglp:&sxfb_bcfnt_tglp,p+8))return false;}
  else if(!xx_rt_memcmp(h,"CWDH",4)&&z>=16){if(!sxfb_read(c,p+8,h,8)||!sxfb_add(c,be?&sxfb_nintendo_cwdh_be:&sxfb_nintendo_cwdh_le,p+8))return false;
   uint32_t first=sxfb16(h,be),last=sxfb16(h+2,be);if(last>=first&&(uint64_t)(last-first+1)*3<=z-16&&!sx_table(c,be?&sxfb_nintendo_width_be:&sxfb_nintendo_width_le,(int64_t)p+16,3,last-first+1))return false;
  }else if(!xx_rt_memcmp(h,"CMAP",4)&&z>=20){if(!sxfb_read(c,p+8,h,12)||!sxfb_add(c,be?&sxfb_nintendo_cmap_be:&sxfb_nintendo_cmap_le,p+8))return false;
   uint32_t first=sxfb16(h,be),last=sxfb16(h+2,be),method=sxfb16(h+4,be);
   if(!method&&z>=22){if(!sxfb_add(c,be?&sxfb_nintendo_map_index_be:&sxfb_nintendo_map_index_le,p+20))return false;}
   else if(method==1&&last>=first&&(uint64_t)(last-first+1)*2<=z-20){if(!sx_table(c,be?&sxfb_nintendo_map_index_be:&sxfb_nintendo_map_index_le,(int64_t)p+20,2,last-first+1))return false;}
   else if(method==2&&z>=22){if(!sxfb_read(c,p+20,h,2)||!sxfb_add(c,be?&sxfb_nintendo_map_count_be:&sxfb_nintendo_map_count_le,p+20))return false;uint32_t count=sxfb16(h,be);
    if(count&&(uint64_t)count*4<=z-22&&!sx_table(c,be?&sxfb_nintendo_map_pair_be:&sxfb_nintendo_map_pair_le,(int64_t)p+22,4,count))return false;}
  }p+=z;
 }return true;
}
static bool sxfb_windows(sx_context *c)
{
 uint8_t h[148];if(!sxfb_read(c,0,h,118))return false;uint32_t version=sxfb16(h,false),size=version==0x200?118:version==0x300?148:0;
 if(!size||!sxfb_read(c,0,h,size)||!sxfb_add(c,size==118?&sxfb_windows_fnt2_header:&sxfb_windows_fnt3_header,0))return false;
 if(h[96]<h[95])return true;uint32_t count=(uint32_t)h[96]-h[95]+2,entry=size==118?4:6;
 if(sxfb_span(c,size,(uint64_t)entry*count)&&!sx_table(c,size==118?&sxfb_windows_fnt2_glyph:&sxfb_windows_fnt3_glyph,size,entry,count))return false;return true;
}
static bool sxfb_gem_header(sx_context *c,const uint8_t *h,bool be)
{
 uint32_t first=sxfb16(h+36,be),last=sxfb16(h+38,be),point=sxfb16(h+2,be),flags=sxfb16(h+66,be),width=sxfb16(h+80,be),height=sxfb16(h+82,be),off=sxfb32(h+72,be),data=sxfb32(h+76,be);
 return point>0&&point<256&&first<=last&&last<256&&!(flags&~15U)&&width&&height&&height<=8192&&off>=88&&data>=88&&!sxfb32(h+84,be)&&sxfb_span(c,off,(uint64_t)(last-first+2)*2)&&sxfb_span(c,data,(uint64_t)width*height);
}
static bool sxfb_gem(sx_context *c)
{
 uint8_t h[88];if(!sxfb_read(c,0,h,88))return false;bool be=false;if(!sxfb_gem_header(c,h,false)){be=true;if(!sxfb_gem_header(c,h,true))return false;}
 if(!sxfb_add(c,be?&sxfb_gem_font_header_be:&sxfb_gem_font_header_le,0))return false;uint32_t count=sxfb16(h+38,be)-sxfb16(h+36,be)+1,hor=sxfb32(h+68,be),off=sxfb32(h+72,be),data=sxfb32(h+76,be);
 if(off<88||(uint64_t)off+(count+1)*2!=data)return true;
 if(sxfb16(h+66,be)&2){if(hor<88||(uint64_t)hor+count*2!=off)return true;if(!sx_table(c,&sxfb_gem_horizontal_offsets,hor,2,count))return false;}
 return sx_table(c,be?&sxfb_gem_glyph_bit_position_be:&sxfb_gem_glyph_bit_position_le,off,2,count+1);
}
static bool sxfb_tfm(sx_context *c)
{
 uint8_t h[24];if(!sxfb_read(c,0,h,24))return false;uint32_t q[12];for(unsigned i=0;i<12;i++)q[i]=sxfb16(h+i*2,true);
 if(q[1]<2||q[1]>1024||q[2]>255||q[3]>255||!sxfb_span(c,0,(uint64_t)q[0]*4)||!sxfb_add(c,&sxfb_tfm_counts,0))return false;
 uint64_t p=24,header=(uint64_t)q[1]*4;if(!sxfb_span(c,p,header))return true;if(!sxfb_add(c,&sxfb_tfm_header,p))return false;
 if(header>=48&&!sxfb_add(c,&sxfb_tfm_coding_scheme,p+8))return false;
 if(header>=68&&!sxfb_add(c,&sxfb_tfm_family,p+48))return false;
 if(header>=72&&!sxfb_add(c,&sxfb_tfm_face,p+68))return false;p+=header;
 const sx_layout *tables[]={&sxfb_tfm_character,&sxfb_tfm_width,&sxfb_tfm_height,&sxfb_tfm_depth,&sxfb_tfm_italic,&sxfb_tfm_ligature_kern,&sxfb_tfm_kern,&sxfb_tfm_extensible_recipe,&sxfb_tfm_parameter};
 for(unsigned i=0;i<9;i++){uint32_t n=i?q[i+3]:(q[3]>=q[2]?q[3]-q[2]+1:0);if(!sxfb_span(c,p,(uint64_t)n*4))break;if(n&&!sx_table(c,tables[i],(int64_t)p,4,n))return false;p+=(uint64_t)n*4;}return true;
}
/* PK/GF xxx special commands share their physical length/payload encoding. */
static bool sxfb_special(sx_context *c,uint64_t *p,unsigned width)
{
 const sx_layout *l[]={&sxfb_tex_special1,&sxfb_tex_special2,&sxfb_tex_special3,&sxfb_tex_special4};uint8_t b[5];
 if(width<1||width>4||!sxfb_read(c,*p,b,width+1))return false;uint32_t n=sxfb_uint(b+1,width,true);if(!sxfb_span(c,*p,(uint64_t)width+1+n))return false;
 if(!sxfb_add(c,l[width-1],*p))return false;*p+=width+1+(uint64_t)n;return true;
}
static bool sxfb_preamble(sx_context *c,unsigned id,uint64_t *p)
{
 uint8_t h[3];if(!sxfb_read(c,0,h,3)||h[0]!=247||h[1]!=id||!sxfb_span(c,3,h[2])||!sxfb_add(c,&sxfb_tex_font_preamble,0))return false;*p=3+h[2];return true;
}
static bool sxfb_pk(sx_context *c)
{
 uint64_t p;if(!sxfb_preamble(c,89,&p)||!sxfb_span(c,p,16)||!sxfb_add(c,&sxfb_pk_metrics,p))return false;p+=16;
 for(unsigned step=0;p<(uint64_t)c->size&&step<20000;step++){uint8_t h[37];if(!sxfb_read(c,p,h,1))return false;unsigned op=h[0];
  if(op<240){unsigned form=op&7,size=form<4?11:form<7?17:37,at=form<4?3:form<7?4:9;if(!sxfb_read(c,p,h,size))break;
   uint64_t packet=form<4?(uint64_t)form*256+h[1]:form<7?(uint64_t)(form-4)*65536+sxfb16(h+1,true):sxfb32(h+1,true);
   if(packet<size-at||!sxfb_span(c,p,at+packet))break;if(!sxfb_add(c,form<4?&sxfb_pk_short_glyph:form<7?&sxfb_pk_extended_glyph:&sxfb_pk_long_glyph,p))return false;p+=at+packet;
  }else if(op<=243){if(!sxfb_special(c,&p,op-239))break;}
  else if(op==244){if(!sxfb_span(c,p,5))break;if(!sxfb_add(c,&sxfb_tex_numeric_special,p))return false;p+=5;}
  else if(op==245||op==246){if(!sxfb_add(c,&sxfb_tex_opcode,p++))return false;}
  else break;
 }return !c->failed;
}
static bool sxfb_gf(sx_context *c)
{
 uint64_t p;if(!sxfb_preamble(c,131,&p))return false;
 for(unsigned step=0;p<(uint64_t)c->size&&step<20000;step++){uint8_t op;if(!sxfb_read(c,p,&op,1))return false;const sx_layout *l=NULL;unsigned size=1;
  if(op>=239&&op<=242){if(!sxfb_special(c,&p,op-238))break;continue;}
  if(op<=63||op==69||op==70||(op>=74&&op<=238)||op==244)l=&sxfb_tex_opcode;
  else if(op>=64&&op<=66){const sx_layout *a[]={&sxfb_gf_paint1,&sxfb_gf_paint2,&sxfb_gf_paint3};l=a[op-64];size=op-62;}
  else if(op>=71&&op<=73){const sx_layout *a[]={&sxfb_gf_skip1,&sxfb_gf_skip2,&sxfb_gf_skip3};l=a[op-71];size=op-69;}
  else if(op==67){l=&sxfb_gf_boc;size=25;}else if(op==68){l=&sxfb_gf_boc1;size=6;}
  else if(op==243){l=&sxfb_tex_numeric_special;size=5;}else if(op==245){l=&sxfb_gf_char_loc;size=18;}
  else if(op==246){l=&sxfb_gf_char_loc0;size=11;}else if(op==248){l=&sxfb_gf_post;size=37;}
  else if(op==249){if(sxfb_span(c,p,6)&&!sxfb_add(c,&sxfb_gf_postpost,p))return false;break;}
  else break;if(!sxfb_span(c,p,size))break;if(!sxfb_add(c,l,p))return false;p+=size;
 }return !c->failed;
}
static bool sxfb_vf(sx_context *c)
{
 uint64_t p;if(!sxfb_preamble(c,202,&p)||!sxfb_span(c,p,8)||!sxfb_add(c,&sxfb_vf_metrics,p))return false;p+=8;
 for(unsigned step=0;p<(uint64_t)c->size&&step<20000;step++){uint8_t h[19];if(!sxfb_read(c,p,h,1))return false;unsigned op=h[0],size=0;uint64_t payload=0;const sx_layout *l=NULL;
  if(op<=241){size=5;payload=op;l=&sxfb_vf_short_packet;}
  else if(op==242){size=13;if(!sxfb_read(c,p,h,size))break;payload=sxfb32(h+1,true);l=&sxfb_vf_long_packet;}
  else if(op<=246){unsigned width=op-242;size=15+width;if(!sxfb_read(c,p,h,size))break;payload=(unsigned)h[width+13]+h[width+14];const sx_layout *a[]={&sxfb_vf_font_definition1,&sxfb_vf_font_definition2,&sxfb_vf_font_definition3,&sxfb_vf_font_definition4};l=a[width-1];}
  else if(op==248){size=1;l=&sxfb_tex_opcode;}else break;
  if(!sxfb_span(c,p,size+payload))break;if(!sxfb_add(c,l,p))return false;p+=size+payload;
 }return !c->failed;
}
static int sxfb_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxfb_finish(sx_context *c)
{
 size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxfb_order);
 for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxfb_order);return !c->failed;
}
static bool sx_fontbinary_supports(xx_file_type_t type)
{
 switch(type){case XX_FILE_TYPE_NINTENDO_BFNT:case XX_FILE_TYPE_NINTENDO_BCFNT:case XX_FILE_TYPE_FONT_WINDOWS_FNT:case XX_FILE_TYPE_FONT_GEM_FNT:case XX_FILE_TYPE_TEX_TFM:case XX_FILE_TYPE_TEX_PK:case XX_FILE_TYPE_TEX_GF:case XX_FILE_TYPE_TEX_VF:return true;default:return false;}
}
static bool sx_fontbinary_build(sx_context *c)
{
 bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_NINTENDO_BFNT:ok=sxfb_nintendo(c,true);break;case XX_FILE_TYPE_NINTENDO_BCFNT:ok=sxfb_nintendo(c,false);break;case XX_FILE_TYPE_FONT_WINDOWS_FNT:ok=sxfb_windows(c);break;case XX_FILE_TYPE_FONT_GEM_FNT:ok=sxfb_gem(c);break;case XX_FILE_TYPE_TEX_TFM:ok=sxfb_tfm(c);break;case XX_FILE_TYPE_TEX_PK:ok=sxfb_pk(c);break;case XX_FILE_TYPE_TEX_GF:ok=sxfb_gf(c);break;case XX_FILE_TYPE_TEX_VF:ok=sxfb_vf(c);break;default:break;}return ok&&sxfb_finish(c);
}
