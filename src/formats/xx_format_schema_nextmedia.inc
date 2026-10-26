/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical image and audiovisual metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxnx_emf_header_fields[]={
 SX_FIELD("record_type","uint32",0,4,SX_ID),
 SX_FIELD("record_size","uint32",4,4,SX_SIZE),
 SX_FIELD("bounds_left","int32",8,4,SX_NONE),
 SX_FIELD("bounds_top","int32",12,4,SX_NONE),
 SX_FIELD("bounds_right","int32",16,4,SX_NONE),
 SX_FIELD("bounds_bottom","int32",20,4,SX_NONE),
 SX_FIELD("frame_left","int32",24,4,SX_NONE),
 SX_FIELD("frame_top","int32",28,4,SX_NONE),
 SX_FIELD("frame_right","int32",32,4,SX_NONE),
 SX_FIELD("frame_bottom","int32",36,4,SX_NONE),
 SX_FIELD("signature","uint32",40,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",44,4,SX_ID),
 SX_FIELD("file_size","uint32",48,4,SX_SIZE),
 SX_FIELD("record_count","uint32",52,4,SX_COUNT_PROP),
 SX_FIELD("handle_count","uint16",56,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",58,2,SX_RESERVED),
 SX_FIELD("description_chars","uint32",60,4,SX_COUNT_PROP),
 SX_FIELD("description_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("palette_entries","uint32",68,4,SX_COUNT_PROP),
 SX_FIELD("device_width","int32",72,4,SX_NONE),
 SX_FIELD("device_height","int32",76,4,SX_NONE),
 SX_FIELD("millimeters_width","int32",80,4,SX_NONE),
 SX_FIELD("millimeters_height","int32",84,4,SX_NONE),
};
static const sx_layout sxnx_emf_header={UINT32_C(0x60320001),"emf_header",sxnx_emf_header_fields,SX_COUNT(sxnx_emf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_record_fields[]={
 SX_FIELD("record_type","uint32",0,4,SX_ID),
 SX_FIELD("record_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnx_emf_record={UINT32_C(0x60320002),"emf_record",sxnx_emf_record_fields,SX_COUNT(sxnx_emf_record_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_rectangle_fields[]={
 SX_FIELD("left","int32",0,4,SX_NONE),
 SX_FIELD("top","int32",4,4,SX_NONE),
 SX_FIELD("right","int32",8,4,SX_NONE),
 SX_FIELD("bottom","int32",12,4,SX_NONE),
};
static const sx_layout sxnx_emf_rectangle={UINT32_C(0x60320003),"emf_rectangle",sxnx_emf_rectangle_fields,SX_COUNT(sxnx_emf_rectangle_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_point_fields[]={
 SX_FIELD("x","int32",0,4,SX_NONE),
 SX_FIELD("y","int32",4,4,SX_NONE),
};
static const sx_layout sxnx_emf_point={UINT32_C(0x60320004),"emf_point",sxnx_emf_point_fields,SX_COUNT(sxnx_emf_point_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_poly_count_fields[]={
 SX_FIELD("point_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_emf_poly_count={UINT32_C(0x60320005),"emf_poly_count",sxnx_emf_poly_count_fields,SX_COUNT(sxnx_emf_poly_count_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_mode_fields[]={
 SX_FIELD("mode","uint32",0,4,SX_ID),
};
static const sx_layout sxnx_emf_mode={UINT32_C(0x60320006),"emf_mode",sxnx_emf_mode_fields,SX_COUNT(sxnx_emf_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_flags_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxnx_emf_flags={UINT32_C(0x60320007),"emf_flags",sxnx_emf_flags_fields,SX_COUNT(sxnx_emf_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_color_fields[]={
 SX_FIELD("color_ref","uint32",0,4,SX_NONE),
};
static const sx_layout sxnx_emf_color={UINT32_C(0x60320008),"emf_color",sxnx_emf_color_fields,SX_COUNT(sxnx_emf_color_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_restore_fields[]={
 SX_FIELD("relative_level","int32",0,4,SX_NONE),
};
static const sx_layout sxnx_emf_restore={UINT32_C(0x60320009),"emf_restore",sxnx_emf_restore_fields,SX_COUNT(sxnx_emf_restore_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_handle_fields[]={
 SX_FIELD("object_index","uint32",0,4,SX_ID),
};
static const sx_layout sxnx_emf_handle={UINT32_C(0x6032000A),"emf_handle",sxnx_emf_handle_fields,SX_COUNT(sxnx_emf_handle_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_pen_fields[]={
 SX_FIELD("object_index","uint32",0,4,SX_ID),
 SX_FIELD("style","uint32",4,4,SX_FLAGS),
 SX_FIELD("width_x","int32",8,4,SX_NONE),
 SX_FIELD("width_y","int32",12,4,SX_NONE),
 SX_FIELD("color_ref","uint32",16,4,SX_NONE),
};
static const sx_layout sxnx_emf_pen={UINT32_C(0x6032000B),"emf_pen",sxnx_emf_pen_fields,SX_COUNT(sxnx_emf_pen_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_brush_fields[]={
 SX_FIELD("object_index","uint32",0,4,SX_ID),
 SX_FIELD("style","uint32",4,4,SX_ID),
 SX_FIELD("color_ref","uint32",8,4,SX_NONE),
 SX_FIELD("hatch","uint32",12,4,SX_ID),
};
static const sx_layout sxnx_emf_brush={UINT32_C(0x6032000C),"emf_brush",sxnx_emf_brush_fields,SX_COUNT(sxnx_emf_brush_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_emf_eof_fields[]={
 SX_FIELD("palette_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("palette_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("last_record_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxnx_emf_eof={UINT32_C(0x6032000D),"emf_eof",sxnx_emf_eof_fields,SX_COUNT(sxnx_emf_eof_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_placeable_fields[]={
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("handle","uint16",4,2,SX_RESERVED),
 SX_FIELD("left","int16",6,2,SX_NONE),
 SX_FIELD("top","int16",8,2,SX_NONE),
 SX_FIELD("right","int16",10,2,SX_NONE),
 SX_FIELD("bottom","int16",12,2,SX_NONE),
 SX_FIELD("units_per_inch","uint16",14,2,SX_NONE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
 SX_FIELD("checksum","uint16",20,2,SX_CHECKSUM),
};
static const sx_layout sxnx_wmf_placeable={UINT32_C(0x6032000E),"wmf_placeable",sxnx_wmf_placeable_fields,SX_COUNT(sxnx_wmf_placeable_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_header_fields[]={
 SX_FIELD("file_type","uint16",0,2,SX_ID),
 SX_FIELD("header_words","uint16",2,2,SX_NONE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("file_words","uint32",6,4,SX_NONE),
 SX_FIELD("object_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("maximum_record_words","uint32",12,4,SX_NONE),
 SX_FIELD("parameter_count","uint16",16,2,SX_RESERVED),
};
static const sx_layout sxnx_wmf_header={UINT32_C(0x6032000F),"wmf_header",sxnx_wmf_header_fields,SX_COUNT(sxnx_wmf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_record_fields[]={
 SX_FIELD("record_words","uint32",0,4,SX_NONE),
 SX_FIELD("function","uint16",4,2,SX_ID),
};
static const sx_layout sxnx_wmf_record={UINT32_C(0x60320010),"wmf_record",sxnx_wmf_record_fields,SX_COUNT(sxnx_wmf_record_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_point_fields[]={
 SX_FIELD("x","int16",0,2,SX_NONE),
 SX_FIELD("y","int16",2,2,SX_NONE),
};
static const sx_layout sxnx_wmf_point={UINT32_C(0x60320011),"wmf_point",sxnx_wmf_point_fields,SX_COUNT(sxnx_wmf_point_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_coordinate_pair_fields[]={
 SX_FIELD("y","int16",0,2,SX_NONE),
 SX_FIELD("x","int16",2,2,SX_NONE),
};
static const sx_layout sxnx_wmf_coordinate_pair={UINT32_C(0x60320012),"wmf_coordinate_pair",sxnx_wmf_coordinate_pair_fields,SX_COUNT(sxnx_wmf_coordinate_pair_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_rectangle_fields[]={
 SX_FIELD("bottom","int16",0,2,SX_NONE),
 SX_FIELD("right","int16",2,2,SX_NONE),
 SX_FIELD("top","int16",4,2,SX_NONE),
 SX_FIELD("left","int16",6,2,SX_NONE),
};
static const sx_layout sxnx_wmf_rectangle={UINT32_C(0x60320013),"wmf_rectangle",sxnx_wmf_rectangle_fields,SX_COUNT(sxnx_wmf_rectangle_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_poly_count_fields[]={
 SX_FIELD("point_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_wmf_poly_count={UINT32_C(0x60320014),"wmf_poly_count",sxnx_wmf_poly_count_fields,SX_COUNT(sxnx_wmf_poly_count_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_mode_fields[]={
 SX_FIELD("mode","uint16",0,2,SX_ID),
};
static const sx_layout sxnx_wmf_mode={UINT32_C(0x60320015),"wmf_mode",sxnx_wmf_mode_fields,SX_COUNT(sxnx_wmf_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_restore_fields[]={
 SX_FIELD("relative_level","int16",0,2,SX_NONE),
};
static const sx_layout sxnx_wmf_restore={UINT32_C(0x60320016),"wmf_restore",sxnx_wmf_restore_fields,SX_COUNT(sxnx_wmf_restore_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_handle_fields[]={
 SX_FIELD("object_index","uint16",0,2,SX_ID),
};
static const sx_layout sxnx_wmf_handle={UINT32_C(0x60320017),"wmf_handle",sxnx_wmf_handle_fields,SX_COUNT(sxnx_wmf_handle_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_color_fields[]={
 SX_FIELD("color_ref","uint32",0,4,SX_NONE),
};
static const sx_layout sxnx_wmf_color={UINT32_C(0x60320018),"wmf_color",sxnx_wmf_color_fields,SX_COUNT(sxnx_wmf_color_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_pen_fields[]={
 SX_FIELD("style","uint16",0,2,SX_FLAGS),
 SX_FIELD("width_x","int16",2,2,SX_NONE),
 SX_FIELD("width_y","int16",4,2,SX_NONE),
 SX_FIELD("color_ref","uint32",6,4,SX_NONE),
};
static const sx_layout sxnx_wmf_pen={UINT32_C(0x60320019),"wmf_pen",sxnx_wmf_pen_fields,SX_COUNT(sxnx_wmf_pen_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wmf_brush_fields[]={
 SX_FIELD("style","uint16",0,2,SX_ID),
 SX_FIELD("color_ref","uint32",2,4,SX_NONE),
 SX_FIELD("hatch","uint16",6,2,SX_ID),
};
static const sx_layout sxnx_wmf_brush={UINT32_C(0x6032001A),"wmf_brush",sxnx_wmf_brush_fields,SX_COUNT(sxnx_wmf_brush_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_header_fields[]={
 SX_FIELD("type","uint8",0,1,SX_ID),
 SX_FIELD("fixed_header","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxnx_wbmp_header={UINT32_C(0x6032001B),"wbmp_header",sxnx_wbmp_header_fields,SX_COUNT(sxnx_wbmp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_width_1_fields[]={
 SX_FIELD("width","uintbase128",0,1,SX_COUNT_PROP),
};
static const sx_layout sxnx_wbmp_width_1={UINT32_C(0x6032001C),"wbmp_width_1",sxnx_wbmp_width_1_fields,SX_COUNT(sxnx_wbmp_width_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_height_1_fields[]={
 SX_FIELD("height","uintbase128",0,1,SX_COUNT_PROP),
};
static const sx_layout sxnx_wbmp_height_1={UINT32_C(0x6032001D),"wbmp_height_1",sxnx_wbmp_height_1_fields,SX_COUNT(sxnx_wbmp_height_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_width_2_fields[]={
 SX_FIELD("width","uintbase128",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_wbmp_width_2={UINT32_C(0x6032001E),"wbmp_width_2",sxnx_wbmp_width_2_fields,SX_COUNT(sxnx_wbmp_width_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wbmp_height_2_fields[]={
 SX_FIELD("height","uintbase128",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_wbmp_height_2={UINT32_C(0x6032001F),"wbmp_height_2",sxnx_wbmp_height_2_fields,SX_COUNT(sxnx_wbmp_height_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_palm_bitmap_header_fields[]={
 SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("row_bytes","uint16",4,2,SX_SIZE),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("pixel_bits","uint8",8,1,SX_NONE),
 SX_FIELD("version","uint8",9,1,SX_ID),
 SX_FIELD("next_bitmap_words","uint16",10,2,SX_NONE),
 SX_FIELD("transparent_index","uint8",12,1,SX_ID),
 SX_FIELD("compression","uint8",13,1,SX_ID),
 SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
};
static const sx_layout sxnx_palm_bitmap_header={UINT32_C(0x60320020),"palm_bitmap_header",sxnx_palm_bitmap_header_fields,SX_COUNT(sxnx_palm_bitmap_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_palm_palette_header_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_palm_palette_header={UINT32_C(0x60320021),"palm_palette_header",sxnx_palm_palette_header_fields,SX_COUNT(sxnx_palm_palette_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_palm_palette_entry_fields[]={
 SX_FIELD("index","uint8",0,1,SX_ID),
 SX_FIELD("red","uint8",1,1,SX_NONE),
 SX_FIELD("green","uint8",2,1,SX_NONE),
 SX_FIELD("blue","uint8",3,1,SX_NONE),
};
static const sx_layout sxnx_palm_palette_entry={UINT32_C(0x60320022),"palm_palette_entry",sxnx_palm_palette_entry_fields,SX_COUNT(sxnx_palm_palette_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_palm_compressed_header_fields[]={
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_palm_compressed_header={UINT32_C(0x60320023),"palm_compressed_header",sxnx_palm_compressed_header_fields,SX_COUNT(sxnx_palm_compressed_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_viff_header_le_fields[]={
 SX_FIELD("identifier","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("file_type","uint8",1,1,SX_ID),
 SX_FIELD("release","uint8",2,1,SX_ID),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("machine_dependency","uint8",4,1,SX_ID),
 SX_FIELD("reserved","bytes",5,3,SX_RESERVED),
 SX_FIELD("comment","char[512]",8,512,SX_STRING),
 SX_FIELD("rows","uint32",520,4,SX_COUNT_PROP),
 SX_FIELD("columns","uint32",524,4,SX_COUNT_PROP),
 SX_FIELD("subrows","uint32",528,4,SX_COUNT_PROP),
 SX_FIELD("x_offset","int32",532,4,SX_NONE),
 SX_FIELD("y_offset","int32",536,4,SX_NONE),
 SX_FIELD("x_bits_per_pixel","float",540,4,SX_NONE),
 SX_FIELD("y_bits_per_pixel","float",544,4,SX_NONE),
 SX_FIELD("location_type","uint32",548,4,SX_ID),
 SX_FIELD("location_dimension","uint32",552,4,SX_COUNT_PROP),
 SX_FIELD("image_count","uint32",556,4,SX_COUNT_PROP),
 SX_FIELD("band_count","uint32",560,4,SX_COUNT_PROP),
 SX_FIELD("storage_type","uint32",564,4,SX_ID),
 SX_FIELD("encoding","uint32",568,4,SX_ID),
 SX_FIELD("map_scheme","uint32",572,4,SX_ID),
 SX_FIELD("map_storage_type","uint32",576,4,SX_ID),
 SX_FIELD("map_rows","uint32",580,4,SX_COUNT_PROP),
 SX_FIELD("map_columns","uint32",584,4,SX_COUNT_PROP),
 SX_FIELD("map_subrows","uint32",588,4,SX_COUNT_PROP),
 SX_FIELD("map_enable","uint32",592,4,SX_FLAGS),
 SX_FIELD("maps_per_cycle","uint32",596,4,SX_COUNT_PROP),
 SX_FIELD("color_space","uint32",600,4,SX_ID),
 SX_FIELD("reserved_tail","bytes",604,420,SX_RESERVED),
};
static const sx_layout sxnx_viff_header_le={UINT32_C(0x60320024),"viff_header_le",sxnx_viff_header_le_fields,SX_COUNT(sxnx_viff_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_viff_header_be_fields[]={
 SX_FIELD("identifier","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("file_type","uint8",1,1,SX_ID),
 SX_FIELD("release","uint8",2,1,SX_ID),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("machine_dependency","uint8",4,1,SX_ID),
 SX_FIELD("reserved","bytes",5,3,SX_RESERVED),
 SX_FIELD("comment","char[512]",8,512,SX_STRING),
 SX_FIELD("rows","uint32",520,4,SX_COUNT_PROP),
 SX_FIELD("columns","uint32",524,4,SX_COUNT_PROP),
 SX_FIELD("subrows","uint32",528,4,SX_COUNT_PROP),
 SX_FIELD("x_offset","int32",532,4,SX_NONE),
 SX_FIELD("y_offset","int32",536,4,SX_NONE),
 SX_FIELD("x_bits_per_pixel","float",540,4,SX_NONE),
 SX_FIELD("y_bits_per_pixel","float",544,4,SX_NONE),
 SX_FIELD("location_type","uint32",548,4,SX_ID),
 SX_FIELD("location_dimension","uint32",552,4,SX_COUNT_PROP),
 SX_FIELD("image_count","uint32",556,4,SX_COUNT_PROP),
 SX_FIELD("band_count","uint32",560,4,SX_COUNT_PROP),
 SX_FIELD("storage_type","uint32",564,4,SX_ID),
 SX_FIELD("encoding","uint32",568,4,SX_ID),
 SX_FIELD("map_scheme","uint32",572,4,SX_ID),
 SX_FIELD("map_storage_type","uint32",576,4,SX_ID),
 SX_FIELD("map_rows","uint32",580,4,SX_COUNT_PROP),
 SX_FIELD("map_columns","uint32",584,4,SX_COUNT_PROP),
 SX_FIELD("map_subrows","uint32",588,4,SX_COUNT_PROP),
 SX_FIELD("map_enable","uint32",592,4,SX_FLAGS),
 SX_FIELD("maps_per_cycle","uint32",596,4,SX_COUNT_PROP),
 SX_FIELD("color_space","uint32",600,4,SX_ID),
 SX_FIELD("reserved_tail","bytes",604,420,SX_RESERVED),
};
static const sx_layout sxnx_viff_header_be={UINT32_C(0x60320025),"viff_header_be",sxnx_viff_header_be_fields,SX_COUNT(sxnx_viff_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_viff_header_dec_fields[]={
 SX_FIELD("identifier","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("file_type","uint8",1,1,SX_ID),
 SX_FIELD("release","uint8",2,1,SX_ID),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("machine_dependency","uint8",4,1,SX_ID),
 SX_FIELD("reserved","bytes",5,3,SX_RESERVED),
 SX_FIELD("comment","char[512]",8,512,SX_STRING),
 SX_FIELD("rows","uint32",520,4,SX_COUNT_PROP),
 SX_FIELD("columns","uint32",524,4,SX_COUNT_PROP),
 SX_FIELD("subrows","uint32",528,4,SX_COUNT_PROP),
 SX_FIELD("x_offset","int32",532,4,SX_NONE),
 SX_FIELD("y_offset","int32",536,4,SX_NONE),
 SX_FIELD("x_bits_per_pixel_vax","bytes",540,4,SX_NONE),
 SX_FIELD("y_bits_per_pixel_vax","bytes",544,4,SX_NONE),
 SX_FIELD("location_type","uint32",548,4,SX_ID),
 SX_FIELD("location_dimension","uint32",552,4,SX_COUNT_PROP),
 SX_FIELD("image_count","uint32",556,4,SX_COUNT_PROP),
 SX_FIELD("band_count","uint32",560,4,SX_COUNT_PROP),
 SX_FIELD("storage_type","uint32",564,4,SX_ID),
 SX_FIELD("encoding","uint32",568,4,SX_ID),
 SX_FIELD("map_scheme","uint32",572,4,SX_ID),
 SX_FIELD("map_storage_type","uint32",576,4,SX_ID),
 SX_FIELD("map_rows","uint32",580,4,SX_COUNT_PROP),
 SX_FIELD("map_columns","uint32",584,4,SX_COUNT_PROP),
 SX_FIELD("map_subrows","uint32",588,4,SX_COUNT_PROP),
 SX_FIELD("map_enable","uint32",592,4,SX_FLAGS),
 SX_FIELD("maps_per_cycle","uint32",596,4,SX_COUNT_PROP),
 SX_FIELD("color_space","uint32",600,4,SX_ID),
 SX_FIELD("reserved_tail","bytes",604,420,SX_RESERVED),
};
static const sx_layout sxnx_viff_header_dec={UINT32_C(0x60320026),"viff_header_dec",sxnx_viff_header_dec_fields,SX_COUNT(sxnx_viff_header_dec_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_abr_header_fields[]={
 SX_FIELD("version","int16",0,2,SX_ID),
 SX_FIELD("brush_count","int16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_abr_header={UINT32_C(0x60320027),"abr_header",sxnx_abr_header_fields,SX_COUNT(sxnx_abr_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_record_fields[]={
 SX_FIELD("brush_type","int16",0,2,SX_ID),
 SX_FIELD("data_size","int32",2,4,SX_SIZE),
};
static const sx_layout sxnx_abr_record={UINT32_C(0x60320028),"abr_record",sxnx_abr_record_fields,SX_COUNT(sxnx_abr_record_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_sample_prefix_fields[]={
 SX_FIELD("misc","int32",0,4,SX_NONE),
 SX_FIELD("spacing","int16",4,2,SX_NONE),
};
static const sx_layout sxnx_abr_sample_prefix={UINT32_C(0x60320029),"abr_sample_prefix",sxnx_abr_sample_prefix_fields,SX_COUNT(sxnx_abr_sample_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_name_header_fields[]={
 SX_FIELD("utf16_units","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_abr_name_header={UINT32_C(0x6032002A),"abr_name_header",sxnx_abr_name_header_fields,SX_COUNT(sxnx_abr_name_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_sample_geometry_fields[]={
 SX_FIELD("antialias","uint8",0,1,SX_FLAGS),
 SX_FIELD("bounds_top","int16",1,2,SX_NONE),
 SX_FIELD("bounds_left","int16",3,2,SX_NONE),
 SX_FIELD("bounds_bottom","int16",5,2,SX_NONE),
 SX_FIELD("bounds_right","int16",7,2,SX_NONE),
 SX_FIELD("top","int32",9,4,SX_NONE),
 SX_FIELD("left","int32",13,4,SX_NONE),
 SX_FIELD("bottom","int32",17,4,SX_NONE),
 SX_FIELD("right","int32",21,4,SX_NONE),
 SX_FIELD("depth","int16",25,2,SX_NONE),
 SX_FIELD("compression","uint8",27,1,SX_ID),
};
static const sx_layout sxnx_abr_sample_geometry={UINT32_C(0x6032002B),"abr_sample_geometry",sxnx_abr_sample_geometry_fields,SX_COUNT(sxnx_abr_sample_geometry_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_abr_row_size_fields[]={
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_abr_row_size={UINT32_C(0x6032002C),"abr_row_size",sxnx_abr_row_size_fields,SX_COUNT(sxnx_abr_row_size_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_wpg_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("product_type","uint8",8,1,SX_ID),
 SX_FIELD("file_type","uint8",9,1,SX_ID),
 SX_FIELD("major_version","uint8",10,1,SX_ID),
 SX_FIELD("minor_version","uint8",11,1,SX_ID),
 SX_FIELD("encryption_key","uint16",12,2,SX_ID),
 SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
};
static const sx_layout sxnx_wpg_header={UINT32_C(0x6032002D),"wpg_header",sxnx_wpg_header_fields,SX_COUNT(sxnx_wpg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_record_short_fields[]={
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("data_size","uint8",1,1,SX_SIZE),
};
static const sx_layout sxnx_wpg_record_short={UINT32_C(0x6032002E),"wpg_record_short",sxnx_wpg_record_short_fields,SX_COUNT(sxnx_wpg_record_short_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_record_medium_fields[]={
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("length_marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("data_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnx_wpg_record_medium={UINT32_C(0x6032002F),"wpg_record_medium",sxnx_wpg_record_medium_fields,SX_COUNT(sxnx_wpg_record_medium_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_record_long_fields[]={
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("length_marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("length_high15_and_flag","uint16",2,2,SX_FLAGS),
 SX_FIELD("length_low16","uint16",4,2,SX_NONE),
};
static const sx_layout sxnx_wpg_record_long={UINT32_C(0x60320030),"wpg_record_long",sxnx_wpg_record_long_fields,SX_COUNT(sxnx_wpg_record_long_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_start_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("canvas_width","uint16",2,2,SX_NONE),
 SX_FIELD("canvas_height","uint16",4,2,SX_NONE),
};
static const sx_layout sxnx_wpg_start={UINT32_C(0x60320031),"wpg_start",sxnx_wpg_start_fields,SX_COUNT(sxnx_wpg_start_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_palette_fields[]={
 SX_FIELD("first_index","uint16",0,2,SX_ID),
 SX_FIELD("end_index","uint16",2,2,SX_ID),
};
static const sx_layout sxnx_wpg_palette={UINT32_C(0x60320032),"wpg_palette",sxnx_wpg_palette_fields,SX_COUNT(sxnx_wpg_palette_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_rgb_palette_entry_fields[]={
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
};
static const sx_layout sxnx_rgb_palette_entry={UINT32_C(0x60320033),"rgb_palette_entry",sxnx_rgb_palette_entry_fields,SX_COUNT(sxnx_rgb_palette_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_bitmap_fields[]={
 SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("depth","uint16",4,2,SX_NONE),
 SX_FIELD("horizontal_resolution","uint16",6,2,SX_NONE),
 SX_FIELD("vertical_resolution","uint16",8,2,SX_NONE),
};
static const sx_layout sxnx_wpg_bitmap={UINT32_C(0x60320034),"wpg_bitmap",sxnx_wpg_bitmap_fields,SX_COUNT(sxnx_wpg_bitmap_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_header_fields[]={
 SX_FIELD("signature","bytes",0,27,SX_SIGNATURE),
 SX_FIELD("reserved","bytes",27,5,SX_RESERVED),
 SX_FIELD("major_version","uint16",32,2,SX_ID),
 SX_FIELD("minor_version","uint16",34,2,SX_ID),
};
static const sx_layout sxnx_psp_header={UINT32_C(0x60320035),"psp_header",sxnx_psp_header_fields,SX_COUNT(sxnx_psp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_block_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("block_id","uint16",4,2,SX_ID),
 SX_FIELD("initial_size","uint32",6,4,SX_SIZE),
 SX_FIELD("data_size","uint32",10,4,SX_SIZE),
};
static const sx_layout sxnx_psp_block={UINT32_C(0x60320036),"psp_block",sxnx_psp_block_fields,SX_COUNT(sxnx_psp_block_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_image_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("resolution","double",8,8,SX_NONE),
 SX_FIELD("resolution_unit","uint8",16,1,SX_ID),
 SX_FIELD("compression","uint16",17,2,SX_ID),
 SX_FIELD("bit_depth","uint16",19,2,SX_NONE),
 SX_FIELD("plane_count","uint16",21,2,SX_COUNT_PROP),
 SX_FIELD("color_count","uint32",23,4,SX_COUNT_PROP),
 SX_FIELD("grayscale","uint8",27,1,SX_FLAGS),
 SX_FIELD("total_image_size","uint32",28,4,SX_SIZE),
 SX_FIELD("active_layer","uint32",32,4,SX_ID),
 SX_FIELD("layer_count","uint16",36,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_psp_image={UINT32_C(0x60320037),"psp_image",sxnx_psp_image_fields,SX_COUNT(sxnx_psp_image_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_layer_fields[]={
 SX_FIELD("name","char[256]",0,256,SX_STRING),
 SX_FIELD("layer_type","uint8",256,1,SX_ID),
 SX_FIELD("image_left","int32",257,4,SX_NONE),
 SX_FIELD("image_top","int32",261,4,SX_NONE),
 SX_FIELD("image_right","int32",265,4,SX_NONE),
 SX_FIELD("image_bottom","int32",269,4,SX_NONE),
 SX_FIELD("saved_image_left","int32",273,4,SX_NONE),
 SX_FIELD("saved_image_top","int32",277,4,SX_NONE),
 SX_FIELD("saved_image_right","int32",281,4,SX_NONE),
 SX_FIELD("saved_image_bottom","int32",285,4,SX_NONE),
 SX_FIELD("opacity","uint8",289,1,SX_NONE),
 SX_FIELD("blend_mode","uint8",290,1,SX_ID),
 SX_FIELD("visible","uint8",291,1,SX_FLAGS),
 SX_FIELD("transparency_protected","uint8",292,1,SX_FLAGS),
 SX_FIELD("link_group","uint8",293,1,SX_ID),
 SX_FIELD("mask_left","int32",294,4,SX_NONE),
 SX_FIELD("mask_top","int32",298,4,SX_NONE),
 SX_FIELD("mask_right","int32",302,4,SX_NONE),
 SX_FIELD("mask_bottom","int32",306,4,SX_NONE),
 SX_FIELD("saved_mask_left","int32",310,4,SX_NONE),
 SX_FIELD("saved_mask_top","int32",314,4,SX_NONE),
 SX_FIELD("saved_mask_right","int32",318,4,SX_NONE),
 SX_FIELD("saved_mask_bottom","int32",322,4,SX_NONE),
 SX_FIELD("mask_linked","uint8",326,1,SX_FLAGS),
 SX_FIELD("mask_disabled","uint8",327,1,SX_FLAGS),
 SX_FIELD("opaque_blend_ranges","bytes",328,43,SX_NONE),
 SX_FIELD("bitmap_count","uint16",371,2,SX_COUNT_PROP),
 SX_FIELD("channel_count","uint16",373,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_psp_layer={UINT32_C(0x60320038),"psp_layer",sxnx_psp_layer_fields,SX_COUNT(sxnx_psp_layer_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_psp_channel_fields[]={
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
 SX_FIELD("bitmap_type","uint16",8,2,SX_ID),
 SX_FIELD("channel_type","uint16",10,2,SX_ID),
};
static const sx_layout sxnx_psp_channel={UINT32_C(0x60320039),"psp_channel",sxnx_psp_channel_fields,SX_COUNT(sxnx_psp_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_pat_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("pattern_count","uint32",6,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_pat_header={UINT32_C(0x6032003A),"pat_header",sxnx_pat_header_fields,SX_COUNT(sxnx_pat_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_pattern_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("image_mode","uint32",4,4,SX_ID),
 SX_FIELD("height","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("width","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("name_utf16_units","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_pat_pattern={UINT32_C(0x6032003B),"pat_pattern",sxnx_pat_pattern_fields,SX_COUNT(sxnx_pat_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_id_length_fields[]={
 SX_FIELD("id_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnx_pat_id_length={UINT32_C(0x6032003C),"pat_id_length",sxnx_pat_id_length_fields,SX_COUNT(sxnx_pat_id_length_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_pat_vma_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("top","int32",8,4,SX_NONE),
 SX_FIELD("left","int32",12,4,SX_NONE),
 SX_FIELD("bottom","int32",16,4,SX_NONE),
 SX_FIELD("right","int32",20,4,SX_NONE),
 SX_FIELD("channel_count","uint32",24,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_pat_vma={UINT32_C(0x6032003D),"pat_vma",sxnx_pat_vma_fields,SX_COUNT(sxnx_pat_vma_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_slot_fields[]={
 SX_FIELD("present","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxnx_pat_slot={UINT32_C(0x6032003E),"pat_slot",sxnx_pat_slot_fields,SX_COUNT(sxnx_pat_slot_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_channel_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("depth","uint32",4,4,SX_NONE),
 SX_FIELD("top","int32",8,4,SX_NONE),
 SX_FIELD("left","int32",12,4,SX_NONE),
 SX_FIELD("bottom","int32",16,4,SX_NONE),
 SX_FIELD("right","int32",20,4,SX_NONE),
 SX_FIELD("pixel_depth","uint16",24,2,SX_NONE),
 SX_FIELD("compression","uint8",26,1,SX_ID),
};
static const sx_layout sxnx_pat_channel={UINT32_C(0x6032003F),"pat_channel",sxnx_pat_channel_fields,SX_COUNT(sxnx_pat_channel_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_row_size_fields[]={
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_pat_row_size={UINT32_C(0x60320040),"pat_row_size",sxnx_pat_row_size_fields,SX_COUNT(sxnx_pat_row_size_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_hierarchy_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("key","bytes",4,4,SX_ID),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxnx_pat_hierarchy={UINT32_C(0x60320041),"pat_hierarchy",sxnx_pat_hierarchy_fields,SX_COUNT(sxnx_pat_hierarchy_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pat_empty_descriptor_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("name_utf16_units","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("name_utf16","bytes",8,2,SX_NONE),
 SX_FIELD("class_id_length","uint32",10,4,SX_SIZE),
 SX_FIELD("class_id","bytes",14,4,SX_ID),
 SX_FIELD("item_count","uint32",18,4,SX_COUNT_PROP),
 SX_FIELD("key_length","uint32",22,4,SX_SIZE),
 SX_FIELD("key","char[9]",26,9,SX_STRING),
 SX_FIELD("value_type","bytes",35,4,SX_ID),
 SX_FIELD("list_count","uint32",39,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_pat_empty_descriptor={UINT32_C(0x60320042),"pat_empty_descriptor",sxnx_pat_empty_descriptor_fields,SX_COUNT(sxnx_pat_empty_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("major_version","uint16",6,2,SX_ID),
 SX_FIELD("minor_version","uint16",8,2,SX_ID),
 SX_FIELD("begin_opcode","uint8",10,1,SX_ID),
 SX_FIELD("begin_length","uint8",11,1,SX_SIZE),
 SX_FIELD("left","int32",12,4,SX_NONE),
 SX_FIELD("top","int32",16,4,SX_NONE),
 SX_FIELD("width","int32",20,4,SX_NONE),
 SX_FIELD("height","int32",24,4,SX_NONE),
 SX_FIELD("record_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_qpic_header={UINT32_C(0x60320043),"qpic_header",sxnx_qpic_header_fields,SX_COUNT(sxnx_qpic_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_record_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("data_size","uint8",1,1,SX_SIZE),
};
static const sx_layout sxnx_qpic_record={UINT32_C(0x60320044),"qpic_record",sxnx_qpic_record_fields,SX_COUNT(sxnx_qpic_record_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_qpic_record_long_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("size_marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxnx_qpic_record_long={UINT32_C(0x60320045),"qpic_record_long",sxnx_qpic_record_long_fields,SX_COUNT(sxnx_qpic_record_long_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_point_fields[]={
 SX_FIELD("x","double",0,8,SX_NONE),
 SX_FIELD("y","double",8,8,SX_NONE),
};
static const sx_layout sxnx_qpic_point={UINT32_C(0x60320046),"qpic_point",sxnx_qpic_point_fields,SX_COUNT(sxnx_qpic_point_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_rectangle_fields[]={
 SX_FIELD("x","double",0,8,SX_NONE),
 SX_FIELD("y","double",8,8,SX_NONE),
 SX_FIELD("width","double",16,8,SX_NONE),
 SX_FIELD("height","double",24,8,SX_NONE),
};
static const sx_layout sxnx_qpic_rectangle={UINT32_C(0x60320047),"qpic_rectangle",sxnx_qpic_rectangle_fields,SX_COUNT(sxnx_qpic_rectangle_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_line_fields[]={
 SX_FIELD("x1","double",0,8,SX_NONE),
 SX_FIELD("y1","double",8,8,SX_NONE),
 SX_FIELD("x2","double",16,8,SX_NONE),
 SX_FIELD("y2","double",24,8,SX_NONE),
};
static const sx_layout sxnx_qpic_line={UINT32_C(0x60320048),"qpic_line",sxnx_qpic_line_fields,SX_COUNT(sxnx_qpic_line_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_rounding_fields[]={
 SX_FIELD("x_rounding","int16",0,2,SX_NONE),
 SX_FIELD("y_rounding","int16",2,2,SX_NONE),
};
static const sx_layout sxnx_qpic_rounding={UINT32_C(0x60320049),"qpic_rounding",sxnx_qpic_rounding_fields,SX_COUNT(sxnx_qpic_rounding_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_angles_fields[]={
 SX_FIELD("start_angle","int16",0,2,SX_NONE),
 SX_FIELD("span_angle","int16",2,2,SX_NONE),
};
static const sx_layout sxnx_qpic_angles={UINT32_C(0x6032004A),"qpic_angles",sxnx_qpic_angles_fields,SX_COUNT(sxnx_qpic_angles_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_point_count_fields[]={
 SX_FIELD("point_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_qpic_point_count={UINT32_C(0x6032004B),"qpic_point_count",sxnx_qpic_point_count_fields,SX_COUNT(sxnx_qpic_point_count_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_fill_rule_fields[]={
 SX_FIELD("fill_rule","uint8",0,1,SX_ID),
};
static const sx_layout sxnx_qpic_fill_rule={UINT32_C(0x6032004C),"qpic_fill_rule",sxnx_qpic_fill_rule_fields,SX_COUNT(sxnx_qpic_fill_rule_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_qpic_mode_fields[]={
 SX_FIELD("mode","int32",0,4,SX_ID),
};
static const sx_layout sxnx_qpic_mode={UINT32_C(0x6032004D),"qpic_mode",sxnx_qpic_mode_fields,SX_COUNT(sxnx_qpic_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_flags_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxnx_qpic_flags={UINT32_C(0x6032004E),"qpic_flags",sxnx_qpic_flags_fields,SX_COUNT(sxnx_qpic_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_raster_operation_fields[]={
 SX_FIELD("raster_operation","int32",0,4,SX_ID),
};
static const sx_layout sxnx_qpic_raster_operation={UINT32_C(0x6032004F),"qpic_raster_operation",sxnx_qpic_raster_operation_fields,SX_COUNT(sxnx_qpic_raster_operation_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_qpic_boolean_fields[]={
 SX_FIELD("enabled","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnx_qpic_boolean={UINT32_C(0x60320050),"qpic_boolean",sxnx_qpic_boolean_fields,SX_COUNT(sxnx_qpic_boolean_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_qpic_opacity_fields[]={
 SX_FIELD("opacity","double",0,8,SX_NONE),
};
static const sx_layout sxnx_qpic_opacity={UINT32_C(0x60320051),"qpic_opacity",sxnx_qpic_opacity_fields,SX_COUNT(sxnx_qpic_opacity_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_diskobject_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_ID),
 SX_FIELD("next_gadget","uint32",4,4,SX_POINTER),
 SX_FIELD("left","int16",8,2,SX_NONE),
 SX_FIELD("top","int16",10,2,SX_NONE),
 SX_FIELD("width","int16",12,2,SX_NONE),
 SX_FIELD("height","int16",14,2,SX_NONE),
 SX_FIELD("gadget_flags","uint16",16,2,SX_FLAGS),
 SX_FIELD("activation","uint16",18,2,SX_FLAGS),
 SX_FIELD("gadget_type","uint16",20,2,SX_FLAGS),
 SX_FIELD("gadget_render","uint32",22,4,SX_POINTER),
 SX_FIELD("select_render","uint32",26,4,SX_POINTER),
 SX_FIELD("gadget_text","uint32",30,4,SX_POINTER),
 SX_FIELD("mutual_exclude","int32",34,4,SX_NONE),
 SX_FIELD("special_info","uint32",38,4,SX_POINTER),
 SX_FIELD("gadget_id","uint16",42,2,SX_ID),
 SX_FIELD("user_data","uint32",44,4,SX_POINTER),
 SX_FIELD("object_type","uint8",48,1,SX_ID),
 SX_FIELD("padding","uint8",49,1,SX_RESERVED),
 SX_FIELD("default_tool","uint32",50,4,SX_POINTER),
 SX_FIELD("tool_types","uint32",54,4,SX_POINTER),
 SX_FIELD("current_x","int32",58,4,SX_NONE),
 SX_FIELD("current_y","int32",62,4,SX_NONE),
 SX_FIELD("drawer_data","uint32",66,4,SX_POINTER),
 SX_FIELD("tool_window","uint32",70,4,SX_POINTER),
 SX_FIELD("stack_size","int32",74,4,SX_SIZE),
};
static const sx_layout sxnx_icon_diskobject={UINT32_C(0x60320052),"icon_diskobject",sxnx_icon_diskobject_fields,SX_COUNT(sxnx_icon_diskobject_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_drawer_fields[]={
 SX_FIELD("left","int16",0,2,SX_NONE),
 SX_FIELD("top","int16",2,2,SX_NONE),
 SX_FIELD("width","int16",4,2,SX_NONE),
 SX_FIELD("height","int16",6,2,SX_NONE),
 SX_FIELD("detail_pen","uint8",8,1,SX_NONE),
 SX_FIELD("block_pen","uint8",9,1,SX_NONE),
 SX_FIELD("idcmp_flags","uint32",10,4,SX_FLAGS),
 SX_FIELD("window_flags","uint32",14,4,SX_FLAGS),
 SX_FIELD("first_gadget","uint32",18,4,SX_POINTER),
 SX_FIELD("check_mark","uint32",22,4,SX_POINTER),
 SX_FIELD("title","uint32",26,4,SX_POINTER),
 SX_FIELD("screen","uint32",30,4,SX_POINTER),
 SX_FIELD("bitmap","uint32",34,4,SX_POINTER),
 SX_FIELD("min_width","int16",38,2,SX_NONE),
 SX_FIELD("min_height","int16",40,2,SX_NONE),
 SX_FIELD("max_width","uint16",42,2,SX_NONE),
 SX_FIELD("max_height","uint16",44,2,SX_NONE),
 SX_FIELD("window_type","uint16",46,2,SX_ID),
 SX_FIELD("current_x","int32",48,4,SX_NONE),
 SX_FIELD("current_y","int32",52,4,SX_NONE),
};
static const sx_layout sxnx_icon_drawer={UINT32_C(0x60320053),"icon_drawer",sxnx_icon_drawer_fields,SX_COUNT(sxnx_icon_drawer_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_image_fields[]={
 SX_FIELD("left","int16",0,2,SX_NONE),
 SX_FIELD("top","int16",2,2,SX_NONE),
 SX_FIELD("width","int16",4,2,SX_NONE),
 SX_FIELD("height","int16",6,2,SX_NONE),
 SX_FIELD("depth","int16",8,2,SX_NONE),
 SX_FIELD("image_data","uint32",10,4,SX_POINTER),
 SX_FIELD("plane_pick","uint8",14,1,SX_FLAGS),
 SX_FIELD("plane_on_off","uint8",15,1,SX_FLAGS),
 SX_FIELD("next_image","uint32",16,4,SX_POINTER),
};
static const sx_layout sxnx_icon_image={UINT32_C(0x60320054),"icon_image",sxnx_icon_image_fields,SX_COUNT(sxnx_icon_image_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_string_fields[]={
 SX_FIELD("string_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnx_icon_string={UINT32_C(0x60320055),"icon_string",sxnx_icon_string_fields,SX_COUNT(sxnx_icon_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_tooltypes_fields[]={
 SX_FIELD("pointer_array_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnx_icon_tooltypes={UINT32_C(0x60320056),"icon_tooltypes",sxnx_icon_tooltypes_fields,SX_COUNT(sxnx_icon_tooltypes_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_icon_new_drawer_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("view_mode","uint16",4,2,SX_ID),
};
static const sx_layout sxnx_icon_new_drawer={UINT32_C(0x60320057),"icon_new_drawer",sxnx_icon_new_drawer_fields,SX_COUNT(sxnx_icon_new_drawer_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_header_fields[]={
 SX_FIELD("picture_size","uint16",0,2,SX_SIZE),
 SX_FIELD("frame_top","int16",2,2,SX_NONE),
 SX_FIELD("frame_left","int16",4,2,SX_NONE),
 SX_FIELD("frame_bottom","int16",6,2,SX_NONE),
 SX_FIELD("frame_right","int16",8,2,SX_NONE),
 SX_FIELD("version_opcode","uint16",10,2,SX_ID),
 SX_FIELD("version","uint16",12,2,SX_ID),
 SX_FIELD("header_opcode","uint16",14,2,SX_ID),
 SX_FIELD("header_version","int16",16,2,SX_NONE),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
 SX_FIELD("horizontal_resolution_fixed","uint32",20,4,SX_NONE),
 SX_FIELD("vertical_resolution_fixed","uint32",24,4,SX_NONE),
 SX_FIELD("source_top","int16",28,2,SX_NONE),
 SX_FIELD("source_left","int16",30,2,SX_NONE),
 SX_FIELD("source_bottom","int16",32,2,SX_NONE),
 SX_FIELD("source_right","int16",34,2,SX_NONE),
 SX_FIELD("reserved_tail","uint32",36,4,SX_RESERVED),
};
static const sx_layout sxnx_pict_header={UINT32_C(0x60320058),"pict_header",sxnx_pict_header_fields,SX_COUNT(sxnx_pict_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_clip_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("region_size","uint16",2,2,SX_SIZE),
 SX_FIELD("top","int16",4,2,SX_NONE),
 SX_FIELD("left","int16",6,2,SX_NONE),
 SX_FIELD("bottom","int16",8,2,SX_NONE),
 SX_FIELD("right","int16",10,2,SX_NONE),
};
static const sx_layout sxnx_pict_clip={UINT32_C(0x60320059),"pict_clip",sxnx_pict_clip_fields,SX_COUNT(sxnx_pict_clip_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_directbits_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("base_address","uint32",2,4,SX_POINTER),
 SX_FIELD("row_bytes_and_flag","uint16",6,2,SX_FLAGS),
 SX_FIELD("top","int16",8,2,SX_NONE),
 SX_FIELD("left","int16",10,2,SX_NONE),
 SX_FIELD("bottom","int16",12,2,SX_NONE),
 SX_FIELD("right","int16",14,2,SX_NONE),
 SX_FIELD("pixmap_version","uint16",16,2,SX_ID),
 SX_FIELD("pack_type","uint16",18,2,SX_ID),
 SX_FIELD("pack_size","uint32",20,4,SX_SIZE),
 SX_FIELD("horizontal_resolution_fixed","uint32",24,4,SX_NONE),
 SX_FIELD("vertical_resolution_fixed","uint32",28,4,SX_NONE),
 SX_FIELD("pixel_type","uint16",32,2,SX_ID),
 SX_FIELD("pixel_bits","uint16",34,2,SX_NONE),
 SX_FIELD("component_count","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("component_bits","uint16",38,2,SX_NONE),
 SX_FIELD("plane_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("color_table","uint32",44,4,SX_POINTER),
 SX_FIELD("reserved","uint32",48,4,SX_RESERVED),
 SX_FIELD("source_top","int16",52,2,SX_NONE),
 SX_FIELD("source_left","int16",54,2,SX_NONE),
 SX_FIELD("source_bottom","int16",56,2,SX_NONE),
 SX_FIELD("source_right","int16",58,2,SX_NONE),
 SX_FIELD("destination_top","int16",60,2,SX_NONE),
 SX_FIELD("destination_left","int16",62,2,SX_NONE),
 SX_FIELD("destination_bottom","int16",64,2,SX_NONE),
 SX_FIELD("destination_right","int16",66,2,SX_NONE),
 SX_FIELD("transfer_mode","uint16",68,2,SX_ID),
};
static const sx_layout sxnx_pict_directbits={UINT32_C(0x6032005A),"pict_directbits",sxnx_pict_directbits_fields,SX_COUNT(sxnx_pict_directbits_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_row_short_fields[]={
 SX_FIELD("packed_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnx_pict_row_short={UINT32_C(0x6032005B),"pict_row_short",sxnx_pict_row_short_fields,SX_COUNT(sxnx_pict_row_short_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_pict_row_long_fields[]={
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_pict_row_long={UINT32_C(0x6032005C),"pict_row_long",sxnx_pict_row_long_fields,SX_COUNT(sxnx_pict_row_long_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_end_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
};
static const sx_layout sxnx_pict_end={UINT32_C(0x6032005D),"pict_end",sxnx_pict_end_fields,SX_COUNT(sxnx_pict_end_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_sprite_area_fields[]={
 SX_FIELD("sprite_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_sprite_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("free_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxnx_sprite_area={UINT32_C(0x6032005E),"sprite_area",sxnx_sprite_area_fields,SX_COUNT(sxnx_sprite_area_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_sprite_header_fields[]={
 SX_FIELD("next_sprite_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name","char[12]",4,12,SX_STRING),
 SX_FIELD("width_words_minus_one","uint32",16,4,SX_NONE),
 SX_FIELD("height_minus_one","uint32",20,4,SX_NONE),
 SX_FIELD("first_used_bit","uint32",24,4,SX_NONE),
 SX_FIELD("last_used_bit","uint32",28,4,SX_NONE),
 SX_FIELD("image_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("mask_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("mode","uint32",40,4,SX_FLAGS),
};
static const sx_layout sxnx_sprite_header={UINT32_C(0x6032005F),"sprite_header",sxnx_sprite_header_fields,SX_COUNT(sxnx_sprite_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_sprite_palette_fields[]={
 SX_FIELD("color1","uint32",0,4,SX_NONE),
 SX_FIELD("color2","uint32",4,4,SX_NONE),
};
static const sx_layout sxnx_sprite_palette={UINT32_C(0x60320060),"sprite_palette",sxnx_sprite_palette_fields,SX_COUNT(sxnx_sprite_palette_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_header_old_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("cache_type","uint32",8,4,SX_ID),
 SX_FIELD("first_entry_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("available_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_thumb_header_old={UINT32_C(0x60320061),"thumb_header_old",sxnx_thumb_header_old_fields,SX_COUNT(sxnx_thumb_header_old_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_header_28_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("cache_type","uint32",8,4,SX_ID),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
 SX_FIELD("first_entry_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("available_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",24,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_thumb_header_28={UINT32_C(0x60320062),"thumb_header_28",sxnx_thumb_header_28_fields,SX_COUNT(sxnx_thumb_header_28_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_header_new_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("cache_type","uint32",8,4,SX_ID),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
 SX_FIELD("first_entry_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("available_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxnx_thumb_header_new={UINT32_C(0x60320063),"thumb_header_new",sxnx_thumb_header_new_fields,SX_COUNT(sxnx_thumb_header_new_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_entry_20_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("entry_size","uint32",4,4,SX_SIZE),
 SX_FIELD("cache_id","uint64",8,8,SX_ID),
 SX_FIELD("extension_utf16","bytes",16,8,SX_NONE),
 SX_FIELD("identifier_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("padding_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("data_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("unknown","uint32",36,4,SX_NONE),
 SX_FIELD("data_checksum","uint64",40,8,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint64",48,8,SX_CHECKSUM),
};
static const sx_layout sxnx_thumb_entry_20={UINT32_C(0x60320064),"thumb_entry_20",sxnx_thumb_entry_20_fields,SX_COUNT(sxnx_thumb_entry_20_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_entry_21_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("entry_size","uint32",4,4,SX_SIZE),
 SX_FIELD("cache_id","uint64",8,8,SX_ID),
 SX_FIELD("identifier_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("padding_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("data_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("unknown","uint32",28,4,SX_NONE),
 SX_FIELD("data_checksum","uint64",32,8,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint64",40,8,SX_CHECKSUM),
};
static const sx_layout sxnx_thumb_entry_21={UINT32_C(0x60320065),"thumb_entry_21",sxnx_thumb_entry_21_fields,SX_COUNT(sxnx_thumb_entry_21_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_entry_new_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("entry_size","uint32",4,4,SX_SIZE),
 SX_FIELD("cache_id","uint64",8,8,SX_ID),
 SX_FIELD("identifier_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("padding_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("data_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("width","uint32",28,4,SX_NONE),
 SX_FIELD("height","uint32",32,4,SX_NONE),
 SX_FIELD("unknown","uint32",36,4,SX_NONE),
 SX_FIELD("data_checksum","uint64",40,8,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint64",48,8,SX_CHECKSUM),
};
static const sx_layout sxnx_thumb_entry_new={UINT32_C(0x60320066),"thumb_entry_new",sxnx_thumb_entry_new_fields,SX_COUNT(sxnx_thumb_entry_new_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_xcf_header_fields[]={
 SX_FIELD("signature","bytes",0,9,SX_SIGNATURE),
 SX_FIELD("version","char[5]",9,5,SX_ID),
 SX_FIELD("width","uint32",14,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",18,4,SX_COUNT_PROP),
 SX_FIELD("image_type","uint32",22,4,SX_ID),
};
static const sx_layout sxnx_xcf_header={UINT32_C(0x60320067),"xcf_header",sxnx_xcf_header_fields,SX_COUNT(sxnx_xcf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_property_fields[]={
 SX_FIELD("property_type","uint32",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnx_xcf_property={UINT32_C(0x60320068),"xcf_property",sxnx_xcf_property_fields,SX_COUNT(sxnx_xcf_property_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_string_fields[]={
 SX_FIELD("string_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnx_xcf_string={UINT32_C(0x60320069),"xcf_string",sxnx_xcf_string_fields,SX_COUNT(sxnx_xcf_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_offset_fields[]={
 SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxnx_xcf_offset={UINT32_C(0x6032006A),"xcf_offset",sxnx_xcf_offset_fields,SX_COUNT(sxnx_xcf_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_layer_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("layer_type","uint32",8,4,SX_ID),
};
static const sx_layout sxnx_xcf_layer={UINT32_C(0x6032006B),"xcf_layer",sxnx_xcf_layer_fields,SX_COUNT(sxnx_xcf_layer_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_channel_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_xcf_channel={UINT32_C(0x6032006C),"xcf_channel",sxnx_xcf_channel_fields,SX_COUNT(sxnx_xcf_channel_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_hierarchy_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("bytes_per_pixel","uint32",8,4,SX_SIZE),
};
static const sx_layout sxnx_xcf_hierarchy={UINT32_C(0x6032006D),"xcf_hierarchy",sxnx_xcf_hierarchy_fields,SX_COUNT(sxnx_xcf_hierarchy_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_level_fields[]={
 SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_xcf_level={UINT32_C(0x6032006E),"xcf_level",sxnx_xcf_level_fields,SX_COUNT(sxnx_xcf_level_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_color_count_fields[]={
 SX_FIELD("color_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_xcf_color_count={UINT32_C(0x6032006F),"xcf_color_count",sxnx_xcf_color_count_fields,SX_COUNT(sxnx_xcf_color_count_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_opacity_fields[]={
 SX_FIELD("opacity","uint32",0,4,SX_NONE),
};
static const sx_layout sxnx_xcf_opacity={UINT32_C(0x60320070),"xcf_opacity",sxnx_xcf_opacity_fields,SX_COUNT(sxnx_xcf_opacity_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_mode_fields[]={
 SX_FIELD("mode","uint32",0,4,SX_ID),
};
static const sx_layout sxnx_xcf_mode={UINT32_C(0x60320071),"xcf_mode",sxnx_xcf_mode_fields,SX_COUNT(sxnx_xcf_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_boolean_fields[]={
 SX_FIELD("enabled","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxnx_xcf_boolean={UINT32_C(0x60320072),"xcf_boolean",sxnx_xcf_boolean_fields,SX_COUNT(sxnx_xcf_boolean_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_geometry_offset_fields[]={
 SX_FIELD("x","int32",0,4,SX_NONE),
 SX_FIELD("y","int32",4,4,SX_NONE),
};
static const sx_layout sxnx_xcf_geometry_offset={UINT32_C(0x60320073),"xcf_geometry_offset",sxnx_xcf_geometry_offset_fields,SX_COUNT(sxnx_xcf_geometry_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_compression_fields[]={
 SX_FIELD("compression","uint8",0,1,SX_ID),
};
static const sx_layout sxnx_xcf_compression={UINT32_C(0x60320074),"xcf_compression",sxnx_xcf_compression_fields,SX_COUNT(sxnx_xcf_compression_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_xcf_guide_fields[]={
 SX_FIELD("position","int32",0,4,SX_NONE),
 SX_FIELD("orientation","uint8",4,1,SX_ID),
};
static const sx_layout sxnx_xcf_guide={UINT32_C(0x60320075),"xcf_guide",sxnx_xcf_guide_fields,SX_COUNT(sxnx_xcf_guide_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_resolution_fields[]={
 SX_FIELD("horizontal","float",0,4,SX_NONE),
 SX_FIELD("vertical","float",4,4,SX_NONE),
};
static const sx_layout sxnx_xcf_resolution={UINT32_C(0x60320076),"xcf_resolution",sxnx_xcf_resolution_fields,SX_COUNT(sxnx_xcf_resolution_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_tattoo_fields[]={
 SX_FIELD("tattoo","uint32",0,4,SX_ID),
};
static const sx_layout sxnx_xcf_tattoo={UINT32_C(0x60320077),"xcf_tattoo",sxnx_xcf_tattoo_fields,SX_COUNT(sxnx_xcf_tattoo_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_unit_fields[]={
 SX_FIELD("unit","uint32",0,4,SX_ID),
};
static const sx_layout sxnx_xcf_unit={UINT32_C(0x60320078),"xcf_unit",sxnx_xcf_unit_fields,SX_COUNT(sxnx_xcf_unit_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_parasite_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnx_xcf_parasite={UINT32_C(0x60320079),"xcf_parasite",sxnx_xcf_parasite_fields,SX_COUNT(sxnx_xcf_parasite_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_xcf_sample_point_fields[]={
 SX_FIELD("x","int32",0,4,SX_NONE),
 SX_FIELD("y","int32",4,4,SX_NONE),
};
static const sx_layout sxnx_xcf_sample_point={UINT32_C(0x6032007A),"xcf_sample_point",sxnx_xcf_sample_point_fields,SX_COUNT(sxnx_xcf_sample_point_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_bpg_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("pixel_format_alpha_depth","uint8",4,1,SX_FLAGS),
 SX_FIELD("color_space_extensions_alpha_flags","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxnx_bpg_header={UINT32_C(0x6032007B),"bpg_header",sxnx_bpg_header_fields,SX_COUNT(sxnx_bpg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_width_1_fields[]={
 SX_FIELD("width","uintbase128",0,1,SX_COUNT_PROP),
};
static const sx_layout sxnx_bpg_width_1={UINT32_C(0x6032007C),"bpg_width_1",sxnx_bpg_width_1_fields,SX_COUNT(sxnx_bpg_width_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_width_2_fields[]={
 SX_FIELD("width","uintbase128",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_bpg_width_2={UINT32_C(0x6032007D),"bpg_width_2",sxnx_bpg_width_2_fields,SX_COUNT(sxnx_bpg_width_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_width_3_fields[]={
 SX_FIELD("width","uintbase128",0,3,SX_COUNT_PROP),
};
static const sx_layout sxnx_bpg_width_3={UINT32_C(0x6032007E),"bpg_width_3",sxnx_bpg_width_3_fields,SX_COUNT(sxnx_bpg_width_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_height_1_fields[]={
 SX_FIELD("height","uintbase128",0,1,SX_COUNT_PROP),
};
static const sx_layout sxnx_bpg_height_1={UINT32_C(0x6032007F),"bpg_height_1",sxnx_bpg_height_1_fields,SX_COUNT(sxnx_bpg_height_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_height_2_fields[]={
 SX_FIELD("height","uintbase128",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_bpg_height_2={UINT32_C(0x60320080),"bpg_height_2",sxnx_bpg_height_2_fields,SX_COUNT(sxnx_bpg_height_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_height_3_fields[]={
 SX_FIELD("height","uintbase128",0,3,SX_COUNT_PROP),
};
static const sx_layout sxnx_bpg_height_3={UINT32_C(0x60320081),"bpg_height_3",sxnx_bpg_height_3_fields,SX_COUNT(sxnx_bpg_height_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_picture_bytes_1_fields[]={
 SX_FIELD("picture_bytes","uintbase128",0,1,SX_SIZE),
};
static const sx_layout sxnx_bpg_picture_bytes_1={UINT32_C(0x60320082),"bpg_picture_bytes_1",sxnx_bpg_picture_bytes_1_fields,SX_COUNT(sxnx_bpg_picture_bytes_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_picture_bytes_2_fields[]={
 SX_FIELD("picture_bytes","uintbase128",0,2,SX_SIZE),
};
static const sx_layout sxnx_bpg_picture_bytes_2={UINT32_C(0x60320083),"bpg_picture_bytes_2",sxnx_bpg_picture_bytes_2_fields,SX_COUNT(sxnx_bpg_picture_bytes_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_picture_bytes_3_fields[]={
 SX_FIELD("picture_bytes","uintbase128",0,3,SX_SIZE),
};
static const sx_layout sxnx_bpg_picture_bytes_3={UINT32_C(0x60320084),"bpg_picture_bytes_3",sxnx_bpg_picture_bytes_3_fields,SX_COUNT(sxnx_bpg_picture_bytes_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_picture_bytes_4_fields[]={
 SX_FIELD("picture_bytes","uintbase128",0,4,SX_SIZE),
};
static const sx_layout sxnx_bpg_picture_bytes_4={UINT32_C(0x60320085),"bpg_picture_bytes_4",sxnx_bpg_picture_bytes_4_fields,SX_COUNT(sxnx_bpg_picture_bytes_4_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_bytes_1_fields[]={
 SX_FIELD("extension_bytes","uintbase128",0,1,SX_SIZE),
};
static const sx_layout sxnx_bpg_extension_bytes_1={UINT32_C(0x60320086),"bpg_extension_bytes_1",sxnx_bpg_extension_bytes_1_fields,SX_COUNT(sxnx_bpg_extension_bytes_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_bytes_2_fields[]={
 SX_FIELD("extension_bytes","uintbase128",0,2,SX_SIZE),
};
static const sx_layout sxnx_bpg_extension_bytes_2={UINT32_C(0x60320087),"bpg_extension_bytes_2",sxnx_bpg_extension_bytes_2_fields,SX_COUNT(sxnx_bpg_extension_bytes_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_bytes_3_fields[]={
 SX_FIELD("extension_bytes","uintbase128",0,3,SX_SIZE),
};
static const sx_layout sxnx_bpg_extension_bytes_3={UINT32_C(0x60320088),"bpg_extension_bytes_3",sxnx_bpg_extension_bytes_3_fields,SX_COUNT(sxnx_bpg_extension_bytes_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_1_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,1,SX_ID),
};
static const sx_layout sxnx_bpg_extension_tag_1={UINT32_C(0x60320089),"bpg_extension_tag_1",sxnx_bpg_extension_tag_1_fields,SX_COUNT(sxnx_bpg_extension_tag_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_2_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,2,SX_ID),
};
static const sx_layout sxnx_bpg_extension_tag_2={UINT32_C(0x6032008A),"bpg_extension_tag_2",sxnx_bpg_extension_tag_2_fields,SX_COUNT(sxnx_bpg_extension_tag_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_3_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,3,SX_ID),
};
static const sx_layout sxnx_bpg_extension_tag_3={UINT32_C(0x6032008B),"bpg_extension_tag_3",sxnx_bpg_extension_tag_3_fields,SX_COUNT(sxnx_bpg_extension_tag_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_4_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,4,SX_ID),
};
static const sx_layout sxnx_bpg_extension_tag_4={UINT32_C(0x6032008C),"bpg_extension_tag_4",sxnx_bpg_extension_tag_4_fields,SX_COUNT(sxnx_bpg_extension_tag_4_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_tag_5_fields[]={
 SX_FIELD("extension_tag","uintbase128",0,5,SX_ID),
};
static const sx_layout sxnx_bpg_extension_tag_5={UINT32_C(0x6032008D),"bpg_extension_tag_5",sxnx_bpg_extension_tag_5_fields,SX_COUNT(sxnx_bpg_extension_tag_5_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_data_bytes_1_fields[]={
 SX_FIELD("extension_data_bytes","uintbase128",0,1,SX_SIZE),
};
static const sx_layout sxnx_bpg_extension_data_bytes_1={UINT32_C(0x6032008E),"bpg_extension_data_bytes_1",sxnx_bpg_extension_data_bytes_1_fields,SX_COUNT(sxnx_bpg_extension_data_bytes_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_data_bytes_2_fields[]={
 SX_FIELD("extension_data_bytes","uintbase128",0,2,SX_SIZE),
};
static const sx_layout sxnx_bpg_extension_data_bytes_2={UINT32_C(0x6032008F),"bpg_extension_data_bytes_2",sxnx_bpg_extension_data_bytes_2_fields,SX_COUNT(sxnx_bpg_extension_data_bytes_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_extension_data_bytes_3_fields[]={
 SX_FIELD("extension_data_bytes","uintbase128",0,3,SX_SIZE),
};
static const sx_layout sxnx_bpg_extension_data_bytes_3={UINT32_C(0x60320090),"bpg_extension_data_bytes_3",sxnx_bpg_extension_data_bytes_3_fields,SX_COUNT(sxnx_bpg_extension_data_bytes_3_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_hevc_header_bytes_1_fields[]={
 SX_FIELD("hevc_header_bytes","uintbase128",0,1,SX_SIZE),
};
static const sx_layout sxnx_bpg_hevc_header_bytes_1={UINT32_C(0x60320091),"bpg_hevc_header_bytes_1",sxnx_bpg_hevc_header_bytes_1_fields,SX_COUNT(sxnx_bpg_hevc_header_bytes_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_bpg_nal_fields[]={
 SX_FIELD("type_layer","uint8",0,1,SX_FLAGS),
 SX_FIELD("layer_temporal_id","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxnx_bpg_nal={UINT32_C(0x60320092),"bpg_nal",sxnx_bpg_nal_fields,SX_COUNT(sxnx_bpg_nal_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_riff_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
static const sx_layout sxnx_ani_riff={UINT32_C(0x60320093),"ani_riff",sxnx_ani_riff_fields,SX_COUNT(sxnx_ani_riff_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnx_ani_chunk={UINT32_C(0x60320094),"ani_chunk",sxnx_ani_chunk_fields,SX_COUNT(sxnx_ani_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_list_fields[]={
 SX_FIELD("list_type","bytes",0,4,SX_ID),
};
static const sx_layout sxnx_ani_list={UINT32_C(0x60320095),"ani_list",sxnx_ani_list_fields,SX_COUNT(sxnx_ani_list_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_header_fields[]={
 SX_FIELD("header_size","uint32",0,4,SX_SIZE),
 SX_FIELD("frame_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("step_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("width","uint32",12,4,SX_NONE),
 SX_FIELD("height","uint32",16,4,SX_NONE),
 SX_FIELD("pixel_bits","uint32",20,4,SX_NONE),
 SX_FIELD("plane_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("display_rate_jiffies","uint32",28,4,SX_NONE),
 SX_FIELD("flags","uint32",32,4,SX_FLAGS),
};
static const sx_layout sxnx_ani_header={UINT32_C(0x60320096),"ani_header",sxnx_ani_header_fields,SX_COUNT(sxnx_ani_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_rate_fields[]={
 SX_FIELD("duration_jiffies","uint32",0,4,SX_NONE),
};
static const sx_layout sxnx_ani_rate={UINT32_C(0x60320097),"ani_rate",sxnx_ani_rate_fields,SX_COUNT(sxnx_ani_rate_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_sequence_fields[]={
 SX_FIELD("frame_index","uint32",0,4,SX_ID),
};
static const sx_layout sxnx_ani_sequence={UINT32_C(0x60320098),"ani_sequence",sxnx_ani_sequence_fields,SX_COUNT(sxnx_ani_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_icon_header_fields[]={
 SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
 SX_FIELD("image_type","uint16",2,2,SX_ID),
 SX_FIELD("image_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_ani_icon_header={UINT32_C(0x60320099),"ani_icon_header",sxnx_ani_icon_header_fields,SX_COUNT(sxnx_ani_icon_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_icon_entry_fields[]={
 SX_FIELD("width","uint8",0,1,SX_NONE),
 SX_FIELD("height","uint8",1,1,SX_NONE),
 SX_FIELD("color_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("planes","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("bit_count","uint16",6,2,SX_NONE),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxnx_ani_icon_entry={UINT32_C(0x6032009A),"ani_icon_entry",sxnx_ani_icon_entry_fields,SX_COUNT(sxnx_ani_icon_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_cursor_entry_fields[]={
 SX_FIELD("width","uint8",0,1,SX_NONE),
 SX_FIELD("height","uint8",1,1,SX_NONE),
 SX_FIELD("color_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("hotspot_x","uint16",4,2,SX_NONE),
 SX_FIELD("hotspot_y","uint16",6,2,SX_NONE),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxnx_ani_cursor_entry={UINT32_C(0x6032009B),"ani_cursor_entry",sxnx_ani_cursor_entry_fields,SX_COUNT(sxnx_ani_cursor_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_pamf_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[4]",4,4,SX_ID),
 SX_FIELD("header_blocks","uint32",8,4,SX_NONE),
 SX_FIELD("data_blocks","uint32",12,4,SX_NONE),
 SX_FIELD("psmf_marks_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("psmf_marks_size","uint32",20,4,SX_SIZE),
 SX_FIELD("unknown_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("unknown_size","uint32",28,4,SX_SIZE),
 SX_FIELD("reserved","bytes",32,48,SX_RESERVED),
};
static const sx_layout sxnx_pamf_header={UINT32_C(0x6032009C),"pamf_header",sxnx_pamf_header_fields,SX_COUNT(sxnx_pamf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_sequence_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
 SX_FIELD("start_pts_high","uint16",6,2,SX_NONE),
 SX_FIELD("start_pts_low","uint32",8,4,SX_NONE),
 SX_FIELD("end_pts_high","uint16",12,2,SX_NONE),
 SX_FIELD("end_pts_low","uint32",14,4,SX_NONE),
 SX_FIELD("mux_rate_bound","uint32",18,4,SX_NONE),
 SX_FIELD("std_delay_bound","uint32",22,4,SX_NONE),
 SX_FIELD("stream_count","uint32",26,4,SX_COUNT_PROP),
 SX_FIELD("reserved2","uint8",30,1,SX_RESERVED),
 SX_FIELD("grouping_period_count","uint8",31,1,SX_COUNT_PROP),
};
static const sx_layout sxnx_pamf_sequence={UINT32_C(0x6032009D),"pamf_sequence",sxnx_pamf_sequence_fields,SX_COUNT(sxnx_pamf_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_period_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("start_pts_high","uint16",4,2,SX_NONE),
 SX_FIELD("start_pts_low","uint32",6,4,SX_NONE),
 SX_FIELD("end_pts_high","uint16",10,2,SX_NONE),
 SX_FIELD("end_pts_low","uint32",12,4,SX_NONE),
 SX_FIELD("reserved","uint8",16,1,SX_RESERVED),
 SX_FIELD("group_count","uint8",17,1,SX_COUNT_PROP),
};
static const sx_layout sxnx_pamf_period={UINT32_C(0x6032009E),"pamf_period",sxnx_pamf_period_fields,SX_COUNT(sxnx_pamf_period_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_group_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved","uint8",4,1,SX_RESERVED),
 SX_FIELD("stream_count","uint8",5,1,SX_COUNT_PROP),
};
static const sx_layout sxnx_pamf_group={UINT32_C(0x6032009F),"pamf_group",sxnx_pamf_group_fields,SX_COUNT(sxnx_pamf_group_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_stream_fields[]={
 SX_FIELD("coding_type","uint8",0,1,SX_ID),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("stream_id","uint8",4,1,SX_ID),
 SX_FIELD("private_stream_id","uint8",5,1,SX_ID),
 SX_FIELD("std_buffer_scale_size","uint16",6,2,SX_FLAGS),
 SX_FIELD("entry_point_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("entry_point_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_pamf_stream={UINT32_C(0x603200A0),"pamf_stream",sxnx_pamf_stream_fields,SX_COUNT(sxnx_pamf_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_avc_fields[]={
 SX_FIELD("profile","uint8",0,1,SX_ID),
 SX_FIELD("level","uint8",1,1,SX_ID),
 SX_FIELD("frame_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("aspect_ratio_id","uint8",3,1,SX_ID),
 SX_FIELD("sar_width","uint16",4,2,SX_NONE),
 SX_FIELD("sar_height","uint16",6,2,SX_NONE),
 SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
 SX_FIELD("width_16pixels","uint8",9,1,SX_NONE),
 SX_FIELD("reserved2","uint8",10,1,SX_RESERVED),
 SX_FIELD("height_16pixels","uint8",11,1,SX_NONE),
 SX_FIELD("crop_left","uint16",12,2,SX_NONE),
 SX_FIELD("crop_right","uint16",14,2,SX_NONE),
 SX_FIELD("crop_top","uint16",16,2,SX_NONE),
 SX_FIELD("crop_bottom","uint16",18,2,SX_NONE),
 SX_FIELD("signal_flags","uint8",20,1,SX_FLAGS),
 SX_FIELD("color_primaries","uint8",21,1,SX_ID),
 SX_FIELD("transfer_characteristics","uint8",22,1,SX_ID),
 SX_FIELD("matrix_coefficients","uint8",23,1,SX_ID),
 SX_FIELD("coding_flags","uint8",24,1,SX_FLAGS),
 SX_FIELD("max_mean_bitrate","uint8",25,1,SX_NONE),
 SX_FIELD("unused_tail","bytes",26,6,SX_NONE),
};
static const sx_layout sxnx_pamf_avc={UINT32_C(0x603200A1),"pamf_avc",sxnx_pamf_avc_fields,SX_COUNT(sxnx_pamf_avc_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_m2v_fields[]={
 SX_FIELD("profile_level","uint8",0,1,SX_FLAGS),
 SX_FIELD("unused","uint8",1,1,SX_NONE),
 SX_FIELD("frame_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("aspect_ratio_id","uint8",3,1,SX_ID),
 SX_FIELD("sar_width","uint16",4,2,SX_NONE),
 SX_FIELD("sar_height","uint16",6,2,SX_NONE),
 SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
 SX_FIELD("width_16pixels","uint8",9,1,SX_NONE),
 SX_FIELD("reserved2","uint8",10,1,SX_RESERVED),
 SX_FIELD("height_16pixels","uint8",11,1,SX_NONE),
 SX_FIELD("width","uint16",12,2,SX_NONE),
 SX_FIELD("height","uint16",14,2,SX_NONE),
 SX_FIELD("unused_word","uint32",16,4,SX_NONE),
 SX_FIELD("signal_flags","uint8",20,1,SX_FLAGS),
 SX_FIELD("color_primaries","uint8",21,1,SX_ID),
 SX_FIELD("transfer_characteristics","uint8",22,1,SX_ID),
 SX_FIELD("matrix_coefficients","uint8",23,1,SX_ID),
 SX_FIELD("unused_tail","bytes",24,8,SX_NONE),
};
static const sx_layout sxnx_pamf_m2v={UINT32_C(0x603200A2),"pamf_m2v",sxnx_pamf_m2v_fields,SX_COUNT(sxnx_pamf_m2v_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_audio_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
 SX_FIELD("channel_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("sample_rate_code","uint8",3,1,SX_ID),
 SX_FIELD("bits_per_sample_code","uint8",4,1,SX_ID),
 SX_FIELD("unused_tail","bytes",5,27,SX_NONE),
};
static const sx_layout sxnx_pamf_audio={UINT32_C(0x603200A3),"pamf_audio",sxnx_pamf_audio_fields,SX_COUNT(sxnx_pamf_audio_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_userdata_fields[]={
 SX_FIELD("specific_info","bytes",0,32,SX_NONE),
};
static const sx_layout sxnx_pamf_userdata={UINT32_C(0x603200A4),"pamf_userdata",sxnx_pamf_userdata_fields,SX_COUNT(sxnx_pamf_userdata_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_pamf_entry_point_fields[]={
 SX_FIELD("index_reference_picture_blocks","uint16",0,2,SX_FLAGS),
 SX_FIELD("pts_high","uint16",2,2,SX_NONE),
 SX_FIELD("pts_low","uint32",4,4,SX_NONE),
 SX_FIELD("relative_packet_blocks","uint32",8,4,SX_NONE),
};
static const sx_layout sxnx_pamf_entry_point={UINT32_C(0x603200A5),"pamf_entry_point",sxnx_pamf_entry_point_fields,SX_COUNT(sxnx_pamf_entry_point_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("payload_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("padding_size","uint16",10,2,SX_SIZE),
 SX_FIELD("channel","uint8",12,1,SX_ID),
 SX_FIELD("reserved","uint8",13,1,SX_RESERVED),
 SX_FIELD("payload_type","uint16",14,2,SX_ID),
 SX_FIELD("frame_time","uint32",16,4,SX_NONE),
 SX_FIELD("frame_rate","uint32",20,4,SX_NONE),
 SX_FIELD("reserved1","uint32",24,4,SX_RESERVED),
 SX_FIELD("reserved2","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxnx_usm_chunk={UINT32_C(0x603200A6),"usm_chunk",sxnx_usm_chunk_fields,SX_COUNT(sxnx_usm_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_ID),
 SX_FIELD("rows_offset","uint16",10,2,SX_OFFSET),
 SX_FIELD("strings_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("table_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("column_count","uint16",24,2,SX_COUNT_PROP),
 SX_FIELD("row_size","uint16",26,2,SX_SIZE),
 SX_FIELD("row_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_usm_utf_header={UINT32_C(0x603200A7),"usm_utf_header",sxnx_usm_utf_header_fields,SX_COUNT(sxnx_usm_utf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_column_fields[]={
 SX_FIELD("storage_and_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint32",1,4,SX_OFFSET),
};
static const sx_layout sxnx_usm_utf_column={UINT32_C(0x603200A8),"usm_utf_column",sxnx_usm_utf_column_fields,SX_COUNT(sxnx_usm_utf_column_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_u8_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_u8={UINT32_C(0x603200A9),"usm_utf_value_u8",sxnx_usm_utf_value_u8_fields,SX_COUNT(sxnx_usm_utf_value_u8_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_i8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_i8={UINT32_C(0x603200AA),"usm_utf_value_i8",sxnx_usm_utf_value_i8_fields,SX_COUNT(sxnx_usm_utf_value_i8_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_u16_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_u16={UINT32_C(0x603200AB),"usm_utf_value_u16",sxnx_usm_utf_value_u16_fields,SX_COUNT(sxnx_usm_utf_value_u16_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_i16_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_i16={UINT32_C(0x603200AC),"usm_utf_value_i16",sxnx_usm_utf_value_i16_fields,SX_COUNT(sxnx_usm_utf_value_i16_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_u32_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_u32={UINT32_C(0x603200AD),"usm_utf_value_u32",sxnx_usm_utf_value_u32_fields,SX_COUNT(sxnx_usm_utf_value_u32_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_i32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_i32={UINT32_C(0x603200AE),"usm_utf_value_i32",sxnx_usm_utf_value_i32_fields,SX_COUNT(sxnx_usm_utf_value_i32_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_u64_fields[]={
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_u64={UINT32_C(0x603200AF),"usm_utf_value_u64",sxnx_usm_utf_value_u64_fields,SX_COUNT(sxnx_usm_utf_value_u64_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_i64_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_i64={UINT32_C(0x603200B0),"usm_utf_value_i64",sxnx_usm_utf_value_i64_fields,SX_COUNT(sxnx_usm_utf_value_i64_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_f32_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_f32={UINT32_C(0x603200B1),"usm_utf_value_f32",sxnx_usm_utf_value_f32_fields,SX_COUNT(sxnx_usm_utf_value_f32_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_f64_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
static const sx_layout sxnx_usm_utf_value_f64={UINT32_C(0x603200B2),"usm_utf_value_f64",sxnx_usm_utf_value_f64_fields,SX_COUNT(sxnx_usm_utf_value_f64_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_string_fields[]={
 SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxnx_usm_utf_string={UINT32_C(0x603200B3),"usm_utf_string",sxnx_usm_utf_string_fields,SX_COUNT(sxnx_usm_utf_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_data_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnx_usm_utf_data={UINT32_C(0x603200B4),"usm_utf_data",sxnx_usm_utf_data_fields,SX_COUNT(sxnx_usm_utf_data_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_guid_fields[]={
 SX_FIELD("guid","bytes",0,16,SX_ID),
};
static const sx_layout sxnx_usm_utf_guid={UINT32_C(0x603200B5),"usm_utf_guid",sxnx_usm_utf_guid_fields,SX_COUNT(sxnx_usm_utf_guid_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_header_fields[]={
 SX_FIELD("signature","bytes",0,20,SX_SIGNATURE),
 SX_FIELD("magic1","uint16",20,2,SX_SIGNATURE),
 SX_FIELD("magic2","uint16",22,2,SX_SIGNATURE),
 SX_FIELD("magic3","uint16",24,2,SX_SIGNATURE),
};
static const sx_layout sxnx_mve_header={UINT32_C(0x603200B6),"mve_header",sxnx_mve_header_fields,SX_COUNT(sxnx_mve_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_chunk_fields[]={
 SX_FIELD("data_size","uint16",0,2,SX_SIZE),
 SX_FIELD("chunk_type","uint16",2,2,SX_ID),
};
static const sx_layout sxnx_mve_chunk={UINT32_C(0x603200B7),"mve_chunk",sxnx_mve_chunk_fields,SX_COUNT(sxnx_mve_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_opcode_fields[]={
 SX_FIELD("data_size","uint16",0,2,SX_SIZE),
 SX_FIELD("opcode","uint8",2,1,SX_ID),
 SX_FIELD("version","uint8",3,1,SX_ID),
};
static const sx_layout sxnx_mve_opcode={UINT32_C(0x603200B8),"mve_opcode",sxnx_mve_opcode_fields,SX_COUNT(sxnx_mve_opcode_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_timer_fields[]={
 SX_FIELD("microsecond_rate","uint32",0,4,SX_NONE),
 SX_FIELD("rate_divisor","uint16",4,2,SX_NONE),
};
static const sx_layout sxnx_mve_timer={UINT32_C(0x603200B9),"mve_timer",sxnx_mve_timer_fields,SX_COUNT(sxnx_mve_timer_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_audio_init_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("sample_rate","uint16",4,2,SX_NONE),
};
static const sx_layout sxnx_mve_audio_init={UINT32_C(0x603200BA),"mve_audio_init",sxnx_mve_audio_init_fields,SX_COUNT(sxnx_mve_audio_init_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_video_init_0_fields[]={
 SX_FIELD("width_8pixels","uint16",0,2,SX_NONE),
 SX_FIELD("height_8pixels","uint16",2,2,SX_NONE),
};
static const sx_layout sxnx_mve_video_init_0={UINT32_C(0x603200BB),"mve_video_init_0",sxnx_mve_video_init_0_fields,SX_COUNT(sxnx_mve_video_init_0_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_video_init_1_fields[]={
 SX_FIELD("width_8pixels","uint16",0,2,SX_NONE),
 SX_FIELD("height_8pixels","uint16",2,2,SX_NONE),
 SX_FIELD("buffer_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_mve_video_init_1={UINT32_C(0x603200BC),"mve_video_init_1",sxnx_mve_video_init_1_fields,SX_COUNT(sxnx_mve_video_init_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_video_init_2_fields[]={
 SX_FIELD("width_8pixels","uint16",0,2,SX_NONE),
 SX_FIELD("height_8pixels","uint16",2,2,SX_NONE),
 SX_FIELD("buffer_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("true_color","uint16",6,2,SX_FLAGS),
};
static const sx_layout sxnx_mve_video_init_2={UINT32_C(0x603200BD),"mve_video_init_2",sxnx_mve_video_init_2_fields,SX_COUNT(sxnx_mve_video_init_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_send_buffer_fields[]={
 SX_FIELD("palette_start","uint16",0,2,SX_ID),
 SX_FIELD("palette_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("unknown","uint16",4,2,SX_NONE),
};
static const sx_layout sxnx_mve_send_buffer={UINT32_C(0x603200BE),"mve_send_buffer",sxnx_mve_send_buffer_fields,SX_COUNT(sxnx_mve_send_buffer_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_audio_frame_fields[]={
 SX_FIELD("sequence_index","uint16",0,2,SX_ID),
 SX_FIELD("stream_mask","uint16",2,2,SX_FLAGS),
 SX_FIELD("unpacked_bytes","uint16",4,2,SX_SIZE),
};
static const sx_layout sxnx_mve_audio_frame={UINT32_C(0x603200BF),"mve_audio_frame",sxnx_mve_audio_frame_fields,SX_COUNT(sxnx_mve_audio_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_video_mode_fields[]={
 SX_FIELD("width","uint16",0,2,SX_NONE),
 SX_FIELD("height","uint16",2,2,SX_NONE),
 SX_FIELD("flags","uint16",4,2,SX_FLAGS),
};
static const sx_layout sxnx_mve_video_mode={UINT32_C(0x603200C0),"mve_video_mode",sxnx_mve_video_mode_fields,SX_COUNT(sxnx_mve_video_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_palette_fields[]={
 SX_FIELD("first_index","uint16",0,2,SX_ID),
 SX_FIELD("color_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxnx_mve_palette={UINT32_C(0x603200C1),"mve_palette",sxnx_mve_palette_fields,SX_COUNT(sxnx_mve_palette_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_vqa_form_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
static const sx_layout sxnx_vqa_form={UINT32_C(0x603200C2),"vqa_form",sxnx_vqa_form_fields,SX_COUNT(sxnx_vqa_form_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_vqa_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnx_vqa_chunk={UINT32_C(0x603200C3),"vqa_chunk",sxnx_vqa_chunk_fields,SX_COUNT(sxnx_vqa_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_vqa_header_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("frame_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("width","uint16",6,2,SX_NONE),
 SX_FIELD("height","uint16",8,2,SX_NONE),
 SX_FIELD("block_width","uint8",10,1,SX_NONE),
 SX_FIELD("block_height","uint8",11,1,SX_NONE),
 SX_FIELD("frame_rate","uint8",12,1,SX_NONE),
 SX_FIELD("codebook_parts","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("color_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("max_blocks","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("opaque1","bytes",18,6,SX_NONE),
 SX_FIELD("sample_rate","uint16",24,2,SX_NONE),
 SX_FIELD("channel_count","uint8",26,1,SX_COUNT_PROP),
 SX_FIELD("sample_bits","uint8",27,1,SX_NONE),
 SX_FIELD("opaque2","bytes",28,14,SX_NONE),
};
static const sx_layout sxnx_vqa_header={UINT32_C(0x603200C4),"vqa_header",sxnx_vqa_header_fields,SX_COUNT(sxnx_vqa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_vqa_frame_index_fields[]={
 SX_FIELD("word_offset_and_flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxnx_vqa_frame_index={UINT32_C(0x603200C5),"vqa_frame_index",sxnx_vqa_frame_index_fields,SX_COUNT(sxnx_vqa_frame_index_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_vqa_sound_fields[]={
 SX_FIELD("unpacked_bytes","uint16",0,2,SX_SIZE),
 SX_FIELD("packed_bytes","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnx_vqa_sound={UINT32_C(0x603200C6),"vqa_sound",sxnx_vqa_sound_fields,SX_COUNT(sxnx_vqa_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_signature_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
};
static const sx_layout sxnx_mng_signature={UINT32_C(0x603200C7),"mng_signature",sxnx_mng_signature_fields,SX_COUNT(sxnx_mng_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_chunk_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("chunk_type","bytes",4,4,SX_ID),
};
static const sx_layout sxnx_mng_chunk={UINT32_C(0x603200C8),"mng_chunk",sxnx_mng_chunk_fields,SX_COUNT(sxnx_mng_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_crc_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxnx_mng_crc={UINT32_C(0x603200C9),"mng_crc",sxnx_mng_crc_fields,SX_COUNT(sxnx_mng_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_header_fields[]={
 SX_FIELD("width","uint32",0,4,SX_NONE),
 SX_FIELD("height","uint32",4,4,SX_NONE),
 SX_FIELD("ticks_per_second","uint32",8,4,SX_NONE),
 SX_FIELD("nominal_layer_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("nominal_frame_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("nominal_play_time_ticks","uint32",20,4,SX_NONE),
 SX_FIELD("simplicity_profile","uint32",24,4,SX_FLAGS),
};
static const sx_layout sxnx_mng_header={UINT32_C(0x603200CA),"mng_header",sxnx_mng_header_fields,SX_COUNT(sxnx_mng_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_png_header_fields[]={
 SX_FIELD("width","uint32",0,4,SX_NONE),
 SX_FIELD("height","uint32",4,4,SX_NONE),
 SX_FIELD("depth","uint8",8,1,SX_NONE),
 SX_FIELD("color_type","uint8",9,1,SX_ID),
 SX_FIELD("compression","uint8",10,1,SX_ID),
 SX_FIELD("filter","uint8",11,1,SX_ID),
 SX_FIELD("interlace","uint8",12,1,SX_ID),
};
static const sx_layout sxnx_mng_png_header={UINT32_C(0x603200CB),"mng_png_header",sxnx_mng_png_header_fields,SX_COUNT(sxnx_mng_png_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_gray_fields[]={
 SX_FIELD("gray","uint16",0,2,SX_NONE),
};
static const sx_layout sxnx_mng_gray={UINT32_C(0x603200CC),"mng_gray",sxnx_mng_gray_fields,SX_COUNT(sxnx_mng_gray_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_rgb_fields[]={
 SX_FIELD("red","uint16",0,2,SX_NONE),
 SX_FIELD("green","uint16",2,2,SX_NONE),
 SX_FIELD("blue","uint16",4,2,SX_NONE),
};
static const sx_layout sxnx_mng_rgb={UINT32_C(0x603200CD),"mng_rgb",sxnx_mng_rgb_fields,SX_COUNT(sxnx_mng_rgb_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_palette_index_fields[]={
 SX_FIELD("index","uint8",0,1,SX_ID),
};
static const sx_layout sxnx_mng_palette_index={UINT32_C(0x603200CE),"mng_palette_index",sxnx_mng_palette_index_fields,SX_COUNT(sxnx_mng_palette_index_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_alpha_fields[]={
 SX_FIELD("alpha","uint8",0,1,SX_NONE),
};
static const sx_layout sxnx_mng_alpha={UINT32_C(0x603200CF),"mng_alpha",sxnx_mng_alpha_fields,SX_COUNT(sxnx_mng_alpha_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_gamma_fields[]={
 SX_FIELD("gamma_100000","uint32",0,4,SX_NONE),
};
static const sx_layout sxnx_mng_gamma={UINT32_C(0x603200D0),"mng_gamma",sxnx_mng_gamma_fields,SX_COUNT(sxnx_mng_gamma_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_chromaticity_fields[]={
 SX_FIELD("white_x_100000","uint32",0,4,SX_NONE),
 SX_FIELD("white_y_100000","uint32",4,4,SX_NONE),
 SX_FIELD("red_x_100000","uint32",8,4,SX_NONE),
 SX_FIELD("red_y_100000","uint32",12,4,SX_NONE),
 SX_FIELD("green_x_100000","uint32",16,4,SX_NONE),
 SX_FIELD("green_y_100000","uint32",20,4,SX_NONE),
 SX_FIELD("blue_x_100000","uint32",24,4,SX_NONE),
 SX_FIELD("blue_y_100000","uint32",28,4,SX_NONE),
};
static const sx_layout sxnx_mng_chromaticity={UINT32_C(0x603200D1),"mng_chromaticity",sxnx_mng_chromaticity_fields,SX_COUNT(sxnx_mng_chromaticity_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_srgb_fields[]={
 SX_FIELD("rendering_intent","uint8",0,1,SX_ID),
};
static const sx_layout sxnx_mng_srgb={UINT32_C(0x603200D2),"mng_srgb",sxnx_mng_srgb_fields,SX_COUNT(sxnx_mng_srgb_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_physical_fields[]={
 SX_FIELD("horizontal_pixels","uint32",0,4,SX_NONE),
 SX_FIELD("vertical_pixels","uint32",4,4,SX_NONE),
 SX_FIELD("unit","uint8",8,1,SX_ID),
};
static const sx_layout sxnx_mng_physical={UINT32_C(0x603200D3),"mng_physical",sxnx_mng_physical_fields,SX_COUNT(sxnx_mng_physical_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_term_fields[]={
 SX_FIELD("termination_action","uint8",0,1,SX_ID),
};
static const sx_layout sxnx_mng_term={UINT32_C(0x603200D4),"mng_term",sxnx_mng_term_fields,SX_COUNT(sxnx_mng_term_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_fram_fields[]={
 SX_FIELD("framing_mode","uint8",0,1,SX_ID),
};
static const sx_layout sxnx_mng_fram={UINT32_C(0x603200D5),"mng_fram",sxnx_mng_fram_fields,SX_COUNT(sxnx_mng_fram_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_defi_fields[]={
 SX_FIELD("object_id","uint16",0,2,SX_ID),
};
static const sx_layout sxnx_mng_defi={UINT32_C(0x603200D6),"mng_defi",sxnx_mng_defi_fields,SX_COUNT(sxnx_mng_defi_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_back_flag_fields[]={
 SX_FIELD("mandatory","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnx_mng_back_flag={UINT32_C(0x603200D7),"mng_back_flag",sxnx_mng_back_flag_fields,SX_COUNT(sxnx_mng_back_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_dxa_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("frame_count","uint16",5,2,SX_COUNT_PROP),
 SX_FIELD("frame_duration","int32",7,4,SX_NONE),
 SX_FIELD("width","uint16",11,2,SX_NONE),
 SX_FIELD("height","uint16",13,2,SX_NONE),
 SX_FIELD("audio_tag","bytes",15,4,SX_ID),
};
static const sx_layout sxnx_dxa_header={UINT32_C(0x603200D8),"dxa_header",sxnx_dxa_header_fields,SX_COUNT(sxnx_dxa_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_dxa_wave_size_fields[]={
 SX_FIELD("wave_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnx_dxa_wave_size={UINT32_C(0x603200D9),"dxa_wave_size",sxnx_dxa_wave_size_fields,SX_COUNT(sxnx_dxa_wave_size_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_dxa_riff_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
static const sx_layout sxnx_dxa_riff={UINT32_C(0x603200DA),"dxa_riff",sxnx_dxa_riff_fields,SX_COUNT(sxnx_dxa_riff_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_dxa_tag_fields[]={
 SX_FIELD("tag","bytes",0,4,SX_ID),
};
static const sx_layout sxnx_dxa_tag={UINT32_C(0x603200DB),"dxa_tag",sxnx_dxa_tag_fields,SX_COUNT(sxnx_dxa_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_dxa_frame_fields[]={
 SX_FIELD("tag","bytes",0,4,SX_ID),
 SX_FIELD("compression","uint8",4,1,SX_ID),
 SX_FIELD("packed_size","uint32",5,4,SX_SIZE),
};
static const sx_layout sxnx_dxa_frame={UINT32_C(0x603200DC),"dxa_frame",sxnx_dxa_frame_fields,SX_COUNT(sxnx_dxa_frame_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rmf_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",4,4,SX_SIZE),
 SX_FIELD("object_version","uint16",8,2,SX_ID),
 SX_FIELD("file_version","uint32",10,4,SX_ID),
 SX_FIELD("header_count","uint32",14,4,SX_COUNT_PROP),
};
static const sx_layout sxnx_rmf_header={UINT32_C(0x603200DD),"rmf_header",sxnx_rmf_header_fields,SX_COUNT(sxnx_rmf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_object_fields[]={
 SX_FIELD("object_id","bytes",0,4,SX_ID),
 SX_FIELD("object_size","uint32",4,4,SX_SIZE),
 SX_FIELD("object_version","uint16",8,2,SX_ID),
};
static const sx_layout sxnx_rm_object={UINT32_C(0x603200DE),"rm_object",sxnx_rm_object_fields,SX_COUNT(sxnx_rm_object_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_prop_fields[]={
 SX_FIELD("max_bit_rate","uint32",0,4,SX_NONE),
 SX_FIELD("average_bit_rate","uint32",4,4,SX_NONE),
 SX_FIELD("max_packet_size","uint32",8,4,SX_SIZE),
 SX_FIELD("average_packet_size","uint32",12,4,SX_SIZE),
 SX_FIELD("packet_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("duration_ms","uint32",20,4,SX_NONE),
 SX_FIELD("preroll_ms","uint32",24,4,SX_NONE),
 SX_FIELD("index_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("stream_count","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("flags","uint16",38,2,SX_FLAGS),
};
static const sx_layout sxnx_rm_prop={UINT32_C(0x603200DF),"rm_prop",sxnx_rm_prop_fields,SX_COUNT(sxnx_rm_prop_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_title_length_fields[]={
 SX_FIELD("title_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_rm_title_length={UINT32_C(0x603200E0),"rm_title_length",sxnx_rm_title_length_fields,SX_COUNT(sxnx_rm_title_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_author_length_fields[]={
 SX_FIELD("author_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_rm_author_length={UINT32_C(0x603200E1),"rm_author_length",sxnx_rm_author_length_fields,SX_COUNT(sxnx_rm_author_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_copyright_length_fields[]={
 SX_FIELD("copyright_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_rm_copyright_length={UINT32_C(0x603200E2),"rm_copyright_length",sxnx_rm_copyright_length_fields,SX_COUNT(sxnx_rm_copyright_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_comment_length_fields[]={
 SX_FIELD("comment_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_rm_comment_length={UINT32_C(0x603200E3),"rm_comment_length",sxnx_rm_comment_length_fields,SX_COUNT(sxnx_rm_comment_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_mdpr_fields[]={
 SX_FIELD("stream_number","uint16",0,2,SX_ID),
 SX_FIELD("max_bit_rate","uint32",2,4,SX_NONE),
 SX_FIELD("average_bit_rate","uint32",6,4,SX_NONE),
 SX_FIELD("max_packet_size","uint32",10,4,SX_SIZE),
 SX_FIELD("average_packet_size","uint32",14,4,SX_SIZE),
 SX_FIELD("start_time_ms","uint32",18,4,SX_NONE),
 SX_FIELD("preroll_ms","uint32",22,4,SX_NONE),
 SX_FIELD("duration_ms","uint32",26,4,SX_NONE),
};
static const sx_layout sxnx_rm_mdpr={UINT32_C(0x603200E4),"rm_mdpr",sxnx_rm_mdpr_fields,SX_COUNT(sxnx_rm_mdpr_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_name_length_fields[]={
 SX_FIELD("name_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnx_rm_name_length={UINT32_C(0x603200E5),"rm_name_length",sxnx_rm_name_length_fields,SX_COUNT(sxnx_rm_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_rm_mime_length_fields[]={
 SX_FIELD("mime_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnx_rm_mime_length={UINT32_C(0x603200E6),"rm_mime_length",sxnx_rm_mime_length_fields,SX_COUNT(sxnx_rm_mime_length_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_rm_specific_length_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnx_rm_specific_length={UINT32_C(0x603200E7),"rm_specific_length",sxnx_rm_specific_length_fields,SX_COUNT(sxnx_rm_specific_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_video_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("signature","bytes",4,4,SX_SIGNATURE),
 SX_FIELD("codec_id","bytes",8,4,SX_ID),
 SX_FIELD("width","uint16",12,2,SX_NONE),
 SX_FIELD("height","uint16",14,2,SX_NONE),
 SX_FIELD("bits_per_pixel","uint16",16,2,SX_NONE),
 SX_FIELD("pad_width","uint16",18,2,SX_NONE),
 SX_FIELD("pad_height","uint16",20,2,SX_NONE),
 SX_FIELD("frame_rate_fixed","uint32",22,4,SX_NONE),
};
static const sx_layout sxnx_rm_video={UINT32_C(0x603200E8),"rm_video",sxnx_rm_video_fields,SX_COUNT(sxnx_rm_video_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_audio_prefix_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("revision","uint16",6,2,SX_ID),
};
static const sx_layout sxnx_rm_audio_prefix={UINT32_C(0x603200E9),"rm_audio_prefix",sxnx_rm_audio_prefix_fields,SX_COUNT(sxnx_rm_audio_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_data_fields[]={
 SX_FIELD("packet_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("next_data_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxnx_rm_data={UINT32_C(0x603200EA),"rm_data",sxnx_rm_data_fields,SX_COUNT(sxnx_rm_data_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_packet_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("packet_size","uint16",2,2,SX_SIZE),
 SX_FIELD("stream_number","uint16",4,2,SX_ID),
 SX_FIELD("timestamp_ms","uint32",6,4,SX_NONE),
 SX_FIELD("reserved","uint8",10,1,SX_RESERVED),
 SX_FIELD("flags","uint8",11,1,SX_FLAGS),
};
static const sx_layout sxnx_rm_packet={UINT32_C(0x603200EB),"rm_packet",sxnx_rm_packet_fields,SX_COUNT(sxnx_rm_packet_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_index_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("stream_number","uint16",4,2,SX_ID),
 SX_FIELD("next_index_offset","uint32",6,4,SX_OFFSET),
};
static const sx_layout sxnx_rm_index={UINT32_C(0x603200EC),"rm_index",sxnx_rm_index_fields,SX_COUNT(sxnx_rm_index_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_rm_index_entry_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("timestamp_ms","uint32",2,4,SX_NONE),
 SX_FIELD("packet_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("packet_number","uint32",10,4,SX_ID),
};
static const sx_layout sxnx_rm_index_entry={UINT32_C(0x603200ED),"rm_index_entry",sxnx_rm_index_entry_fields,SX_COUNT(sxnx_rm_index_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_start_code_fields[]={
 SX_FIELD("prefix","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("stream_id","uint8",3,1,SX_ID),
};
static const sx_layout sxnx_mpeg_start_code={UINT32_C(0x603200EE),"mpeg_start_code",sxnx_mpeg_start_code_fields,SX_COUNT(sxnx_mpeg_start_code_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mpeg_pack1_fields[]={
 SX_FIELD("prefix","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("pack_id","uint8",3,1,SX_ID),
 SX_FIELD("scr_marker_bits","uint40",4,5,SX_FLAGS),
 SX_FIELD("mux_rate_marker_bits","uint24",9,3,SX_FLAGS),
};
static const sx_layout sxnx_mpeg_pack1={UINT32_C(0x603200EF),"mpeg_pack1",sxnx_mpeg_pack1_fields,SX_COUNT(sxnx_mpeg_pack1_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_pack2_fields[]={
 SX_FIELD("prefix","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("pack_id","uint8",3,1,SX_ID),
 SX_FIELD("scr_base_extension_marker_bits","uint48",4,6,SX_FLAGS),
 SX_FIELD("mux_rate_marker_bits","uint24",10,3,SX_FLAGS),
 SX_FIELD("reserved_stuffing_length","uint8",13,1,SX_FLAGS),
};
static const sx_layout sxnx_mpeg_pack2={UINT32_C(0x603200F0),"mpeg_pack2",sxnx_mpeg_pack2_fields,SX_COUNT(sxnx_mpeg_pack2_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_packet_fields[]={
 SX_FIELD("prefix","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("stream_id","uint8",3,1,SX_ID),
 SX_FIELD("packet_bytes","uint16",4,2,SX_SIZE),
};
static const sx_layout sxnx_mpeg_packet={UINT32_C(0x603200F1),"mpeg_packet",sxnx_mpeg_packet_fields,SX_COUNT(sxnx_mpeg_packet_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_pes2_fields[]={
 SX_FIELD("control","uint8",0,1,SX_FLAGS),
 SX_FIELD("timestamp_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("header_bytes","uint8",2,1,SX_SIZE),
};
static const sx_layout sxnx_mpeg_pes2={UINT32_C(0x603200F2),"mpeg_pes2",sxnx_mpeg_pes2_fields,SX_COUNT(sxnx_mpeg_pes2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mpeg_timestamp_fields[]={
 SX_FIELD("tag_high_and_marker","uint8",0,1,SX_FLAGS),
 SX_FIELD("middle_and_marker","uint16",1,2,SX_FLAGS),
 SX_FIELD("low_and_marker","uint16",3,2,SX_FLAGS),
};
static const sx_layout sxnx_mpeg_timestamp={UINT32_C(0x603200F3),"mpeg_timestamp",sxnx_mpeg_timestamp_fields,SX_COUNT(sxnx_mpeg_timestamp_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_pes1_buffer_fields[]={
 SX_FIELD("std_buffer_scale_size","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxnx_mpeg_pes1_buffer={UINT32_C(0x603200F4),"mpeg_pes1_buffer",sxnx_mpeg_pes1_buffer_fields,SX_COUNT(sxnx_mpeg_pes1_buffer_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_pes1_no_timestamp_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxnx_mpeg_pes1_no_timestamp={UINT32_C(0x603200F5),"mpeg_pes1_no_timestamp",sxnx_mpeg_pes1_no_timestamp_fields,SX_COUNT(sxnx_mpeg_pes1_no_timestamp_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mpeg_system_fields[]={
 SX_FIELD("rate_bound_marker_bits","uint24",0,3,SX_FLAGS),
 SX_FIELD("audio_bound_flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("video_bound_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("packet_rate_restriction_reserved","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxnx_mpeg_system={UINT32_C(0x603200F6),"mpeg_system",sxnx_mpeg_system_fields,SX_COUNT(sxnx_mpeg_system_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_system_stream_fields[]={
 SX_FIELD("stream_id","uint8",0,1,SX_ID),
 SX_FIELD("buffer_scale_size","uint16",1,2,SX_FLAGS),
};
static const sx_layout sxnx_mpeg_system_stream={UINT32_C(0x603200F7),"mpeg_system_stream",sxnx_mpeg_system_stream_fields,SX_COUNT(sxnx_mpeg_system_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_map_fields[]={
 SX_FIELD("version_current_next","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved_marker","uint8",1,1,SX_FLAGS),
 SX_FIELD("program_info_bytes","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnx_mpeg_map={UINT32_C(0x603200F8),"mpeg_map",sxnx_mpeg_map_fields,SX_COUNT(sxnx_mpeg_map_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_map_length_fields[]={
 SX_FIELD("elementary_map_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnx_mpeg_map_length={UINT32_C(0x603200F9),"mpeg_map_length",sxnx_mpeg_map_length_fields,SX_COUNT(sxnx_mpeg_map_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_map_stream_fields[]={
 SX_FIELD("stream_type","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("descriptor_bytes","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnx_mpeg_map_stream={UINT32_C(0x603200FA),"mpeg_map_stream",sxnx_mpeg_map_stream_fields,SX_COUNT(sxnx_mpeg_map_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mpeg_crc_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxnx_mpeg_crc={UINT32_C(0x603200FB),"mpeg_crc",sxnx_mpeg_crc_fields,SX_COUNT(sxnx_mpeg_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_header_fields[]={
 SX_FIELD("sync","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("flags_pid","uint16",1,2,SX_FLAGS),
 SX_FIELD("scrambling_adaptation_counter","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxnx_ts_header={UINT32_C(0x603200FC),"ts_header",sxnx_ts_header_fields,SX_COUNT(sxnx_ts_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_adaptation_size_fields[]={
 SX_FIELD("data_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnx_ts_adaptation_size={UINT32_C(0x603200FD),"ts_adaptation_size",sxnx_ts_adaptation_size_fields,SX_COUNT(sxnx_ts_adaptation_size_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_adaptation_flags_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnx_ts_adaptation_flags={UINT32_C(0x603200FE),"ts_adaptation_flags",sxnx_ts_adaptation_flags_fields,SX_COUNT(sxnx_ts_adaptation_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_clock_fields[]={
 SX_FIELD("base_high","uint32",0,4,SX_NONE),
 SX_FIELD("base_low_reserved_extension_high","uint8",4,1,SX_FLAGS),
 SX_FIELD("extension_low","uint8",5,1,SX_NONE),
};
static const sx_layout sxnx_ts_clock={UINT32_C(0x603200FF),"ts_clock",sxnx_ts_clock_fields,SX_COUNT(sxnx_ts_clock_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_splice_fields[]={
 SX_FIELD("countdown","int8",0,1,SX_NONE),
};
static const sx_layout sxnx_ts_splice={UINT32_C(0x60320100),"ts_splice",sxnx_ts_splice_fields,SX_COUNT(sxnx_ts_splice_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_private_size_fields[]={
 SX_FIELD("data_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnx_ts_private_size={UINT32_C(0x60320101),"ts_private_size",sxnx_ts_private_size_fields,SX_COUNT(sxnx_ts_private_size_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_pointer_fields[]={
 SX_FIELD("pointer_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnx_ts_pointer={UINT32_C(0x60320102),"ts_pointer",sxnx_ts_pointer_fields,SX_COUNT(sxnx_ts_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ts_section_fields[]={
 SX_FIELD("table_id","uint8",0,1,SX_ID),
 SX_FIELD("flags_section_length","uint16",1,2,SX_FLAGS),
 SX_FIELD("table_id_extension","uint16",3,2,SX_ID),
 SX_FIELD("version_current_next","uint8",5,1,SX_FLAGS),
 SX_FIELD("section_number","uint8",6,1,SX_ID),
 SX_FIELD("last_section_number","uint8",7,1,SX_ID),
};
static const sx_layout sxnx_ts_section={UINT32_C(0x60320103),"ts_section",sxnx_ts_section_fields,SX_COUNT(sxnx_ts_section_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_pat_program_fields[]={
 SX_FIELD("program_number","uint16",0,2,SX_ID),
 SX_FIELD("reserved_pid","uint16",2,2,SX_FLAGS),
};
static const sx_layout sxnx_ts_pat_program={UINT32_C(0x60320104),"ts_pat_program",sxnx_ts_pat_program_fields,SX_COUNT(sxnx_ts_pat_program_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_pmt_fields[]={
 SX_FIELD("reserved_pcr_pid","uint16",0,2,SX_FLAGS),
 SX_FIELD("reserved_program_info_length","uint16",2,2,SX_FLAGS),
};
static const sx_layout sxnx_ts_pmt={UINT32_C(0x60320105),"ts_pmt",sxnx_ts_pmt_fields,SX_COUNT(sxnx_ts_pmt_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_pmt_stream_fields[]={
 SX_FIELD("stream_type","uint8",0,1,SX_ID),
 SX_FIELD("reserved_elementary_pid","uint16",1,2,SX_FLAGS),
 SX_FIELD("reserved_info_length","uint16",3,2,SX_FLAGS),
};
static const sx_layout sxnx_ts_pmt_stream={UINT32_C(0x60320106),"ts_pmt_stream",sxnx_ts_pmt_stream_fields,SX_COUNT(sxnx_ts_pmt_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_sdt_fields[]={
 SX_FIELD("original_network_id","uint16",0,2,SX_ID),
 SX_FIELD("reserved","uint8",2,1,SX_RESERVED),
};
static const sx_layout sxnx_ts_sdt={UINT32_C(0x60320107),"ts_sdt",sxnx_ts_sdt_fields,SX_COUNT(sxnx_ts_sdt_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_sdt_service_fields[]={
 SX_FIELD("service_id","uint16",0,2,SX_ID),
 SX_FIELD("eit_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("running_free_ca_descriptor_length","uint16",3,2,SX_FLAGS),
};
static const sx_layout sxnx_ts_sdt_service={UINT32_C(0x60320108),"ts_sdt_service",sxnx_ts_sdt_service_fields,SX_COUNT(sxnx_ts_sdt_service_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_ts_descriptor_fields[]={
 SX_FIELD("tag","uint8",0,1,SX_ID),
 SX_FIELD("data_bytes","uint8",1,1,SX_SIZE),
};
static const sx_layout sxnx_ts_descriptor={UINT32_C(0x60320109),"ts_descriptor",sxnx_ts_descriptor_fields,SX_COUNT(sxnx_ts_descriptor_fields),SX_LE};
static const sx_layout *const sx_nextmedia_layouts[]={
 &sxnx_emf_header,
 &sxnx_emf_record,
 &sxnx_emf_rectangle,
 &sxnx_emf_point,
 &sxnx_emf_poly_count,
 &sxnx_emf_mode,
 &sxnx_emf_flags,
 &sxnx_emf_color,
 &sxnx_emf_restore,
 &sxnx_emf_handle,
 &sxnx_emf_pen,
 &sxnx_emf_brush,
 &sxnx_emf_eof,
 &sxnx_wmf_placeable,
 &sxnx_wmf_header,
 &sxnx_wmf_record,
 &sxnx_wmf_point,
 &sxnx_wmf_coordinate_pair,
 &sxnx_wmf_rectangle,
 &sxnx_wmf_poly_count,
 &sxnx_wmf_mode,
 &sxnx_wmf_restore,
 &sxnx_wmf_handle,
 &sxnx_wmf_color,
 &sxnx_wmf_pen,
 &sxnx_wmf_brush,
 &sxnx_wbmp_header,
 &sxnx_wbmp_width_1,
 &sxnx_wbmp_height_1,
 &sxnx_wbmp_width_2,
 &sxnx_wbmp_height_2,
 &sxnx_palm_bitmap_header,
 &sxnx_palm_palette_header,
 &sxnx_palm_palette_entry,
 &sxnx_palm_compressed_header,
 &sxnx_viff_header_le,
 &sxnx_viff_header_be,
 &sxnx_viff_header_dec,
 &sxnx_abr_header,
 &sxnx_abr_record,
 &sxnx_abr_sample_prefix,
 &sxnx_abr_name_header,
 &sxnx_abr_sample_geometry,
 &sxnx_abr_row_size,
 &sxnx_wpg_header,
 &sxnx_wpg_record_short,
 &sxnx_wpg_record_medium,
 &sxnx_wpg_record_long,
 &sxnx_wpg_start,
 &sxnx_wpg_palette,
 &sxnx_rgb_palette_entry,
 &sxnx_wpg_bitmap,
 &sxnx_psp_header,
 &sxnx_psp_block,
 &sxnx_psp_image,
 &sxnx_psp_layer,
 &sxnx_psp_channel,
 &sxnx_pat_header,
 &sxnx_pat_pattern,
 &sxnx_pat_id_length,
 &sxnx_pat_vma,
 &sxnx_pat_slot,
 &sxnx_pat_channel,
 &sxnx_pat_row_size,
 &sxnx_pat_hierarchy,
 &sxnx_pat_empty_descriptor,
 &sxnx_qpic_header,
 &sxnx_qpic_record,
 &sxnx_qpic_record_long,
 &sxnx_qpic_point,
 &sxnx_qpic_rectangle,
 &sxnx_qpic_line,
 &sxnx_qpic_rounding,
 &sxnx_qpic_angles,
 &sxnx_qpic_point_count,
 &sxnx_qpic_fill_rule,
 &sxnx_qpic_mode,
 &sxnx_qpic_flags,
 &sxnx_qpic_raster_operation,
 &sxnx_qpic_boolean,
 &sxnx_qpic_opacity,
 &sxnx_icon_diskobject,
 &sxnx_icon_drawer,
 &sxnx_icon_image,
 &sxnx_icon_string,
 &sxnx_icon_tooltypes,
 &sxnx_icon_new_drawer,
 &sxnx_pict_header,
 &sxnx_pict_clip,
 &sxnx_pict_directbits,
 &sxnx_pict_row_short,
 &sxnx_pict_row_long,
 &sxnx_pict_end,
 &sxnx_sprite_area,
 &sxnx_sprite_header,
 &sxnx_sprite_palette,
 &sxnx_thumb_header_old,
 &sxnx_thumb_header_28,
 &sxnx_thumb_header_new,
 &sxnx_thumb_entry_20,
 &sxnx_thumb_entry_21,
 &sxnx_thumb_entry_new,
 &sxnx_xcf_header,
 &sxnx_xcf_property,
 &sxnx_xcf_string,
 &sxnx_xcf_offset,
 &sxnx_xcf_layer,
 &sxnx_xcf_channel,
 &sxnx_xcf_hierarchy,
 &sxnx_xcf_level,
 &sxnx_xcf_color_count,
 &sxnx_xcf_opacity,
 &sxnx_xcf_mode,
 &sxnx_xcf_boolean,
 &sxnx_xcf_geometry_offset,
 &sxnx_xcf_compression,
 &sxnx_xcf_guide,
 &sxnx_xcf_resolution,
 &sxnx_xcf_tattoo,
 &sxnx_xcf_unit,
 &sxnx_xcf_parasite,
 &sxnx_xcf_sample_point,
 &sxnx_bpg_header,
 &sxnx_bpg_width_1,
 &sxnx_bpg_width_2,
 &sxnx_bpg_width_3,
 &sxnx_bpg_height_1,
 &sxnx_bpg_height_2,
 &sxnx_bpg_height_3,
 &sxnx_bpg_picture_bytes_1,
 &sxnx_bpg_picture_bytes_2,
 &sxnx_bpg_picture_bytes_3,
 &sxnx_bpg_picture_bytes_4,
 &sxnx_bpg_extension_bytes_1,
 &sxnx_bpg_extension_bytes_2,
 &sxnx_bpg_extension_bytes_3,
 &sxnx_bpg_extension_tag_1,
 &sxnx_bpg_extension_tag_2,
 &sxnx_bpg_extension_tag_3,
 &sxnx_bpg_extension_tag_4,
 &sxnx_bpg_extension_tag_5,
 &sxnx_bpg_extension_data_bytes_1,
 &sxnx_bpg_extension_data_bytes_2,
 &sxnx_bpg_extension_data_bytes_3,
 &sxnx_bpg_hevc_header_bytes_1,
 &sxnx_bpg_nal,
 &sxnx_ani_riff,
 &sxnx_ani_chunk,
 &sxnx_ani_list,
 &sxnx_ani_header,
 &sxnx_ani_rate,
 &sxnx_ani_sequence,
 &sxnx_ani_icon_header,
 &sxnx_ani_icon_entry,
 &sxnx_ani_cursor_entry,
 &sxnx_pamf_header,
 &sxnx_pamf_sequence,
 &sxnx_pamf_period,
 &sxnx_pamf_group,
 &sxnx_pamf_stream,
 &sxnx_pamf_avc,
 &sxnx_pamf_m2v,
 &sxnx_pamf_audio,
 &sxnx_pamf_userdata,
 &sxnx_pamf_entry_point,
 &sxnx_usm_chunk,
 &sxnx_usm_utf_header,
 &sxnx_usm_utf_column,
 &sxnx_usm_utf_value_u8,
 &sxnx_usm_utf_value_i8,
 &sxnx_usm_utf_value_u16,
 &sxnx_usm_utf_value_i16,
 &sxnx_usm_utf_value_u32,
 &sxnx_usm_utf_value_i32,
 &sxnx_usm_utf_value_u64,
 &sxnx_usm_utf_value_i64,
 &sxnx_usm_utf_value_f32,
 &sxnx_usm_utf_value_f64,
 &sxnx_usm_utf_string,
 &sxnx_usm_utf_data,
 &sxnx_usm_utf_guid,
 &sxnx_mve_header,
 &sxnx_mve_chunk,
 &sxnx_mve_opcode,
 &sxnx_mve_timer,
 &sxnx_mve_audio_init,
 &sxnx_mve_video_init_0,
 &sxnx_mve_video_init_1,
 &sxnx_mve_video_init_2,
 &sxnx_mve_send_buffer,
 &sxnx_mve_audio_frame,
 &sxnx_mve_video_mode,
 &sxnx_mve_palette,
 &sxnx_vqa_form,
 &sxnx_vqa_chunk,
 &sxnx_vqa_header,
 &sxnx_vqa_frame_index,
 &sxnx_vqa_sound,
 &sxnx_mng_signature,
 &sxnx_mng_chunk,
 &sxnx_mng_crc,
 &sxnx_mng_header,
 &sxnx_mng_png_header,
 &sxnx_mng_gray,
 &sxnx_mng_rgb,
 &sxnx_mng_palette_index,
 &sxnx_mng_alpha,
 &sxnx_mng_gamma,
 &sxnx_mng_chromaticity,
 &sxnx_mng_srgb,
 &sxnx_mng_physical,
 &sxnx_mng_term,
 &sxnx_mng_fram,
 &sxnx_mng_defi,
 &sxnx_mng_back_flag,
 &sxnx_dxa_header,
 &sxnx_dxa_wave_size,
 &sxnx_dxa_riff,
 &sxnx_dxa_tag,
 &sxnx_dxa_frame,
 &sxnx_rmf_header,
 &sxnx_rm_object,
 &sxnx_rm_prop,
 &sxnx_rm_title_length,
 &sxnx_rm_author_length,
 &sxnx_rm_copyright_length,
 &sxnx_rm_comment_length,
 &sxnx_rm_mdpr,
 &sxnx_rm_name_length,
 &sxnx_rm_mime_length,
 &sxnx_rm_specific_length,
 &sxnx_rm_video,
 &sxnx_rm_audio_prefix,
 &sxnx_rm_data,
 &sxnx_rm_packet,
 &sxnx_rm_index,
 &sxnx_rm_index_entry,
 &sxnx_mpeg_start_code,
 &sxnx_mpeg_pack1,
 &sxnx_mpeg_pack2,
 &sxnx_mpeg_packet,
 &sxnx_mpeg_pes2,
 &sxnx_mpeg_timestamp,
 &sxnx_mpeg_pes1_buffer,
 &sxnx_mpeg_pes1_no_timestamp,
 &sxnx_mpeg_system,
 &sxnx_mpeg_system_stream,
 &sxnx_mpeg_map,
 &sxnx_mpeg_map_length,
 &sxnx_mpeg_map_stream,
 &sxnx_mpeg_crc,
 &sxnx_ts_header,
 &sxnx_ts_adaptation_size,
 &sxnx_ts_adaptation_flags,
 &sxnx_ts_clock,
 &sxnx_ts_splice,
 &sxnx_ts_private_size,
 &sxnx_ts_pointer,
 &sxnx_ts_section,
 &sxnx_ts_pat_program,
 &sxnx_ts_pmt,
 &sxnx_ts_pmt_stream,
 &sxnx_ts_sdt,
 &sxnx_ts_sdt_service,
 &sxnx_ts_descriptor,
};
typedef struct sxnx_view {sx_context *c;uint8_t *p;size_t n;unsigned work;}sxnx_view;
static bool sxnx_need(sxnx_view *v,size_t at,uint64_t n,size_t end){return !xx_pd_is_stopped(v->c->pd)&&end<=v->n&&at<=end&&n<=end-at;}
static uint16_t sxnx_u16(const uint8_t*p,bool be){return xx_data_get_u16(p,2,0,be);}
static uint32_t sxnx_u32(const uint8_t*p,bool be){return xx_data_get_u32(p,4,0,be);}
static bool sxnx_row(sxnx_view *v,const sx_layout*l,size_t at,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t n=(size_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxnx_need(v,at,n,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)n);}
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_table(sxnx_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t z=(size_t)(f->rel_offset+f->size);if(count>4000000||!sxnx_need(v,at,count*z,end))return false;for(uint64_t i=0;i<count;i++,at+=z)if(!sxnx_row(v,l,at,end))return false;return true;}
static int sxnx_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxnx_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxnx_order);
 /* Native readers can permit shared descriptor ranges. Keep one physical interpretation;
  * never repeat identical source bytes as overlapping structures. */
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxnx_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxnx_emf(sxnx_view*v)
{
 if(!SN_ROW(emf_header,0,v->n))return false;size_t at=sxnx_u32(v->p+4,false);unsigned work=0;
 while(at<v->n){if(++work>4096||!SN_ROW(emf_record,at,v->n))return false;uint32_t kind=sxnx_u32(v->p+at,false),size=sxnx_u32(v->p+at+4,false);if(size<8||!sxnx_need(v,at,size,v->n))return false;size_t p=at+8,end=at+size;const sx_layout*l=NULL;
 if(kind>=2&&kind<=4){if(!SN_ROW(emf_rectangle,p,end)||!SN_ROW(emf_poly_count,p+16,end)||!sxnx_table(v,&sxnx_emf_point,p+20,sxnx_u32(v->p+p+16,false),end))return false;}
 else{if((kind>=9&&kind<=13)||kind==27||kind==54)l=&sxnx_emf_point;else if(kind==15){if(!SN_ROW(emf_point,p,end))return false;l=&sxnx_emf_color;p+=8;}else if(kind==16||kind==22)l=&sxnx_emf_flags;else if(kind>=17&&kind<=21)l=&sxnx_emf_mode;else if(kind==24||kind==25)l=&sxnx_emf_color;else if(kind==34)l=&sxnx_emf_restore;else if(kind==37||kind==40)l=&sxnx_emf_handle;else if(kind==29||kind==30||kind==42||kind==43)l=&sxnx_emf_rectangle;else if(kind==38)l=&sxnx_emf_pen;else if(kind==39)l=&sxnx_emf_brush;else if(kind==14)l=&sxnx_emf_eof;if(l&&!sxnx_row(v,l,p,end))return false;}
 at=end;}return at==v->n;
}
static bool sxnx_wmf(sxnx_view*v)
{
 if(!SN_ROW(wmf_placeable,0,v->n)||!SN_ROW(wmf_header,22,v->n))return false;size_t at=40;unsigned work=0;
 while(at<v->n){if(++work>4096||!SN_ROW(wmf_record,at,v->n))return false;uint64_t size=2*(uint64_t)sxnx_u32(v->p+at,false);uint16_t kind=sxnx_u16(v->p+at+4,false);if(size<6||!sxnx_need(v,at,size,v->n))return false;size_t p=at+6,end=at+(size_t)size;const sx_layout*l=NULL;
 if(kind==0x324||kind==0x325){if(!SN_ROW(wmf_poly_count,p,end)||!sxnx_table(v,&sxnx_wmf_point,p+2,sxnx_u16(v->p+p,false),end))return false;}
 else{if(kind==0x214||kind==0x213||(kind>=0x20b&&kind<=0x20e))l=&sxnx_wmf_coordinate_pair;else if(kind==0x201||kind==0x209)l=&sxnx_wmf_color;else if(kind==0x41b||kind==0x418)l=&sxnx_wmf_rectangle;else if(kind==0x12d||kind==0x1f0)l=&sxnx_wmf_handle;else if(kind==0x127)l=&sxnx_wmf_restore;else if(kind==0x102||kind==0x103||kind==0x104||kind==0x106||kind==0x107||kind==0x108)l=&sxnx_wmf_mode;else if(kind==0x2fa)l=&sxnx_wmf_pen;else if(kind==0x2fc)l=&sxnx_wmf_brush;if(l&&!sxnx_row(v,l,p,end))return false;}
 at=end;}return at==v->n;
}
static bool sxnx_varuint(sxnx_view*v,size_t*at,size_t end,uint32_t*out,unsigned*width)
{size_t start=*at;uint32_t u=0;for(unsigned i=0;i<5;i++){if(!sxnx_need(v,*at,1,end))return false;unsigned b=v->p[(*at)++];if((!i&&b==128)||u>UINT32_MAX>>7)return false;u=(u<<7)|(b&127);if(!(b&128)){*out=u;*width=(unsigned)(*at-start);return true;}}return false;}
static bool sxnx_wbmp(sxnx_view*v)
{if(!SN_ROW(wbmp_header,0,v->n))return false;size_t p=2;for(unsigned i=0;i<2;i++){size_t start=p;uint32_t n;unsigned width;if(!sxnx_varuint(v,&p,v->n,&n,&width)||width>2)return false;const sx_layout*l=i?(width==1?&sxnx_wbmp_height_1:&sxnx_wbmp_height_2):(width==1?&sxnx_wbmp_width_1:&sxnx_wbmp_width_2);if(!sxnx_row(v,l,start,p))return false;}return true;}
static bool sxnx_palm(sxnx_view*v)
{if(!SN_ROW(palm_bitmap_header,0,v->n))return false;size_t p=16;unsigned flags=sxnx_u16(v->p+6,true);if(v->p[8]==8&&(flags&0x4000)){if(!SN_ROW(palm_palette_header,p,v->n))return false;unsigned n=sxnx_u16(v->p+p,true);p+=2;if(!sxnx_table(v,&sxnx_palm_palette_entry,p,n,v->n))return false;p+=4*(size_t)n;}return !(flags&0x8000)||SN_ROW(palm_compressed_header,p,v->n);}
static bool sxnx_viff(sxnx_view*v)
{return sxnx_need(v,0,5,v->n)&&sxnx_row(v,v->p[4]==2?&sxnx_viff_header_be:v->p[4]==4?&sxnx_viff_header_dec:&sxnx_viff_header_le,0,v->n);}
static bool sxnx_abr(sxnx_view*v)
{if(!SN_ROW(abr_header,0,v->n))return false;unsigned version=sxnx_u16(v->p,true),count=sxnx_u16(v->p+2,true);if(count>1024)return false;size_t p=4;
 for(unsigned i=0;i<count;i++){if(!SN_ROW(abr_record,p,v->n))return false;uint32_t n=sxnx_u32(v->p+p+2,true);p+=6;if(!sxnx_need(v,p,n,v->n))return false;size_t end=p+n;if(!SN_ROW(abr_sample_prefix,p,end))return false;p+=6;if(version==2){if(!SN_ROW(abr_name_header,p,end))return false;uint32_t units=sxnx_u32(v->p+p,true);p+=4;if(!sxnx_need(v,p,(uint64_t)units*2,end))return false;p+=units*2;}
 if(!SN_ROW(abr_sample_geometry,p,end))return false;int64_t top=(int32_t)sxnx_u32(v->p+p+9,true),bottom=(int32_t)sxnx_u32(v->p+p+17,true);unsigned compression=v->p[p+27];p+=28;if(bottom<top)return false;if(compression==1&&!sxnx_table(v,&sxnx_abr_row_size,p,(uint64_t)(bottom-top),end))return false;p=end;}return p==v->n;}
static bool sxnx_wpg(sxnx_view*v)
{if(!SN_ROW(wpg_header,0,v->n))return false;size_t p=16;unsigned work=0;
 while(p<v->n){if(++work>1024||!sxnx_need(v,p,2,v->n))return false;unsigned kind=v->p[p];uint32_t n=v->p[p+1];const sx_layout*l=&sxnx_wpg_record_short;unsigned hs=2;if(n==255){if(!sxnx_need(v,p,4,v->n))return false;n=sxnx_u16(v->p+p+2,false);hs=4;l=&sxnx_wpg_record_medium;if(n&0x8000){if(!sxnx_need(v,p,6,v->n))return false;n=((n&0x7fff)<<16)|sxnx_u16(v->p+p+4,false);hs=6;l=&sxnx_wpg_record_long;}}
 if(!sxnx_row(v,l,p,v->n))return false;p+=hs;if(!sxnx_need(v,p,n,v->n))return false;size_t end=p+n;
 if(kind==0x0f){if(!SN_ROW(wpg_start,p,end))return false;}else if(kind==0x0e){if(!SN_ROW(wpg_palette,p,end))return false;unsigned first=sxnx_u16(v->p+p,false),last=sxnx_u16(v->p+p+2,false);if(last<first||!sxnx_table(v,&sxnx_rgb_palette_entry,p+4,last-first,end))return false;}else if(kind==0x0b){if(!SN_ROW(wpg_bitmap,p,end))return false;}p=end;}return true;}
static bool sxnx_psp_blocks(sxnx_view*v,size_t p,size_t end,unsigned depth)
{if(depth>3)return false;while(p<end){if(!SN_ROW(psp_block,p,end))return false;unsigned id=sxnx_u16(v->p+p+4,false);uint32_t init=sxnx_u32(v->p+p+6,false),n=sxnx_u32(v->p+p+10,false);p+=14;if(init>n||!sxnx_need(v,p,n,end))return false;size_t finish=p+n;
 const sx_layout*l=id==0?&sxnx_psp_image:id==4?&sxnx_psp_layer:id==5?&sxnx_psp_channel:NULL;
 if(l&&!sxnx_row(v,l,p,p+init))return false;if((id==3||id==4)&&!sxnx_psp_blocks(v,p+init,finish,depth+1))return false;p=finish;}return p==end;}
static bool sxnx_psp(sxnx_view*v){return SN_ROW(psp_header,0,v->n)&&sxnx_psp_blocks(v,36,v->n,0);}
static bool sxnx_pat(sxnx_view*v)
{if(!SN_ROW(pat_header,0,v->n))return false;unsigned count=sxnx_u32(v->p+6,true);if(count>4094)return false;size_t p=10;
 for(unsigned i=0;i<count;i++){if(!SN_ROW(pat_pattern,p,v->n))return false;unsigned h=sxnx_u16(v->p+p+8,true),units=sxnx_u32(v->p+p+12,true);p+=16;if(!sxnx_need(v,p,(uint64_t)units*2,v->n))return false;p+=units*2;if(!SN_ROW(pat_id_length,p,v->n))return false;unsigned id=v->p[p++];if(!sxnx_need(v,p,id,v->n))return false;p+=id;if(!SN_ROW(pat_vma,p,v->n))return false;uint32_t n=sxnx_u32(v->p+p+4,true),channels=sxnx_u32(v->p+p+24,true);if(n<20||channels>64||!sxnx_need(v,p+8,n,v->n))return false;size_t end=p+8+n;p+=28;
 for(unsigned j=0;j<channels+2;j++){if(!SN_ROW(pat_slot,p,end))return false;unsigned yes=sxnx_u32(v->p+p,true);p+=4;if(yes){if(!SN_ROW(pat_channel,p,end))return false;uint32_t z=sxnx_u32(v->p+p,true);if(z<23||!sxnx_need(v,p+4,z,end))return false;if(v->p[p+26]==1&&!sxnx_table(v,&sxnx_pat_row_size,p+27,h,p+4+z))return false;p+=4+z;}}if(p!=end)return false;}
 if(p<v->n){if(!SN_ROW(pat_hierarchy,p,v->n)||!SN_ROW(pat_empty_descriptor,p+12,v->n))return false;p+=55;}return p==v->n;}
static bool sxnx_qpic(sxnx_view*v)
{if(!SN_ROW(qpic_header,0,v->n))return false;unsigned count=sxnx_u32(v->p+28,true);if(count>4095)return false;size_t p=32;for(unsigned i=0;i<count;i++){if(!sxnx_need(v,p,2,v->n))return false;unsigned op=v->p[p],n=v->p[p+1];if(n==255){if(!SN_ROW(qpic_record_long,p,v->n))return false;n=sxnx_u32(v->p+p+2,true);p+=6;}else{if(!SN_ROW(qpic_record,p,v->n))return false;p+=2;}if(!sxnx_need(v,p,n,v->n))return false;size_t end=p+n;const sx_layout*l=NULL;
 if(op==1)l=&sxnx_qpic_point;else if(op==4)l=&sxnx_qpic_line;else if(op==5||op==7)l=&sxnx_qpic_rectangle;else if(op==6||(op>=8&&op<=10)){if(!SN_ROW(qpic_rectangle,p,end)||!sxnx_row(v,op==6?&sxnx_qpic_rounding:&sxnx_qpic_angles,p+32,end))return false;}else if(op==12||op==13){if(!SN_ROW(qpic_point_count,p,end))return false;unsigned num=sxnx_u32(v->p+p,true);if(!sxnx_table(v,&sxnx_qpic_point,p+4,num,end))return false;if(op==13&&!SN_ROW(qpic_fill_rule,p+4+(size_t)num*16,end))return false;}else if(op==41||op==64)l=&sxnx_qpic_mode;else if(op==42)l=&sxnx_qpic_raster_operation;else if(op==63)l=&sxnx_qpic_flags;else if(op==65)l=&sxnx_qpic_boolean;else if(op==66)l=&sxnx_qpic_opacity;if(l&&!sxnx_row(v,l,p,end))return false;p=end;}return p==v->n;}
static bool sxnx_walk_icon_string(sxnx_view*v,size_t*p){if(!SN_ROW(icon_string,*p,v->n))return false;unsigned n=sxnx_u32(v->p+*p,true);*p+=4;if(!sxnx_need(v,*p,n,v->n))return false;*p+=n;return true;}
static bool sxnx_icon(sxnx_view*v)
{if(!SN_ROW(icon_diskobject,0,v->n))return false;size_t p=78;bool drawer=sxnx_u32(v->p+66,true)!=0;if(drawer){if(!SN_ROW(icon_drawer,p,v->n))return false;p+=56;}
 for(unsigned i=0;i<(sxnx_u32(v->p+26,true)?2:1);i++){if(!SN_ROW(icon_image,p,v->n))return false;uint64_t w=sxnx_u16(v->p+p+4,true),h=sxnx_u16(v->p+p+6,true),d=sxnx_u16(v->p+p+8,true),z=((w+15)/16)*2*h*d;p+=20;if(!sxnx_need(v,p,z,v->n))return false;p+=(size_t)z;}
 if(sxnx_u32(v->p+50,true)&&!sxnx_walk_icon_string(v,&p))return false;if(sxnx_u32(v->p+54,true)){if(!SN_ROW(icon_tooltypes,p,v->n))return false;unsigned n=sxnx_u32(v->p+p,true);p+=4;if(n<4||n>8192||(n&3))return false;for(unsigned i=0;i<n/4-1;i++)if(!sxnx_walk_icon_string(v,&p))return false;}if(sxnx_u32(v->p+70,true)&&!sxnx_walk_icon_string(v,&p))return false;if(drawer&&(sxnx_u32(v->p+44,true)&255)){if(!SN_ROW(icon_new_drawer,p,v->n))return false;p+=6;}return p==v->n;}
static bool sxnx_pict(sxnx_view*v)
{size_t base=0;if(sxnx_need(v,0,14,v->n)){bool zero=true;for(unsigned i=0;i<14;i++)if(v->p[i])zero=false;if(zero)base=512;}if(!SN_ROW(pict_header,base,v->n)||!SN_ROW(pict_clip,base+40,v->n)||!SN_ROW(pict_directbits,base+52,v->n))return false;int32_t height=(int32_t)xx_data_get_i16(v->p+base+6,2,0,true)-(int32_t)xx_data_get_i16(v->p+base+2,2,0,true);if(height<=0||height>4091)return false;unsigned h=(unsigned)height,rb=sxnx_u16(v->p+base+58,true)&0x7fff;size_t p=base+122;
 for(unsigned i=0;i<h;i++){if(!sxnx_row(v,rb>250?&sxnx_pict_row_long:&sxnx_pict_row_short,p,v->n))return false;unsigned n=rb>250?sxnx_u16(v->p+p,true):v->p[p];p+=rb>250?2:1;if(!sxnx_need(v,p,n,v->n))return false;p+=n;}if((p-base)&1)p++;return SN_ROW(pict_end,p,v->n)&&p+2==v->n;}
static bool sxnx_sprite(sxnx_view*v)
{if(!SN_ROW(sprite_area,0,v->n))return false;unsigned n=sxnx_u32(v->p,false),start=sxnx_u32(v->p+4,false);if(start<4||n>10000)return false;size_t p=start-4;
 for(unsigned i=0;i<n;i++){if(!SN_ROW(sprite_header,p,v->n))return false;unsigned z=sxnx_u32(v->p+p,false),img=sxnx_u32(v->p+p+32,false);if(z<44||img<44||img>z||!sxnx_need(v,p,z,v->n))return false;if(!sxnx_table(v,&sxnx_sprite_palette,p+44,(img-44)/8,p+img))return false;p+=z;}return true;}
static bool sxnx_thumb(sxnx_view*v)
{if(!sxnx_need(v,0,12,v->n))return false;unsigned version=sxnx_u32(v->p+4,false),hs=version==28?28:24;const sx_layout*l=version<=26?&sxnx_thumb_header_old:version==28?&sxnx_thumb_header_28:&sxnx_thumb_header_new;if(!sxnx_row(v,l,0,v->n))return false;unsigned off=version<=26?12:16,start=sxnx_u32(v->p+off,false),available=sxnx_u32(v->p+off+4,false);size_t p=start?start:hs,end=available?available:v->n;if(end>v->n||p>end)return false;l=version==20?&sxnx_thumb_entry_20:version==21?&sxnx_thumb_entry_21:&sxnx_thumb_entry_new;
 while(p<end){if(!sxnx_row(v,l,p,end))return false;unsigned n=sxnx_u32(v->p+p+4,false);if(n<(version==21?48:56)||!sxnx_need(v,p,n,end))return false;p+=n;}return true;}
static bool sxnx_walk_xcf_string(sxnx_view*v,size_t*p,size_t end)
{if(!SN_ROW(xcf_string,*p,end))return false;unsigned z=sxnx_u32(v->p+*p,true);*p+=4;if(!sxnx_need(v,*p,z,end))return false;*p+=z;return true;}
static bool sxnx_xcf_props(sxnx_view*v,size_t*p)
{for(unsigned i=0;i<1024;i++){if(!SN_ROW(xcf_property,*p,v->n))return false;unsigned type=sxnx_u32(v->p+*p,true),z=sxnx_u32(v->p+*p+4,true);*p+=8;if(!sxnx_need(v,*p,z,v->n))return false;size_t end=*p+z;if(!type)return z==0;const sx_layout*l=NULL;
 if(type==1){if(!SN_ROW(xcf_color_count,*p,end)||!sxnx_table(v,&sxnx_rgb_palette_entry,*p+4,sxnx_u32(v->p+*p,true),end))return false;}else if(type==6)l=&sxnx_xcf_opacity;else if(type==7)l=&sxnx_xcf_mode;else if(type>=8&&type<=14)l=&sxnx_xcf_boolean;else if(type==15)l=&sxnx_xcf_geometry_offset;else if(type==16)l=&sxnx_rgb_palette_entry;else if(type==17)l=&sxnx_xcf_compression;else if(type==18){if(z%5||!sxnx_table(v,&sxnx_xcf_guide,*p,z/5,end))return false;}else if(type==19)l=&sxnx_xcf_resolution;else if(type==20)l=&sxnx_xcf_tattoo;else if(type==22)l=&sxnx_xcf_unit;else if(type==21){while(*p<end){if(!sxnx_walk_xcf_string(v,p,end)||!SN_ROW(xcf_parasite,*p,end))return false;unsigned n=sxnx_u32(v->p+*p+4,true);*p+=8;if(!sxnx_need(v,*p,n,end))return false;*p+=n;}}else if(type==27){if(z%8||!sxnx_table(v,&sxnx_xcf_sample_point,*p,z/8,end))return false;}
 if(l&&!sxnx_row(v,l,*p,end))return false;*p=end;}return false;}
static bool sxnx_walk_xcf_hierarchy(sxnx_view*v,size_t p)
{if(!SN_ROW(xcf_hierarchy,p,v->n))return false;p+=12;for(unsigned i=0;i<=16;i++){if(!SN_ROW(xcf_offset,p,v->n))return false;size_t at=sxnx_u32(v->p+p,true);p+=4;if(!at)return true;if(i==16||!SN_ROW(xcf_level,at,v->n))return false;uint64_t w=sxnx_u32(v->p+at,true),h=sxnx_u32(v->p+at+4,true),tiles=((w+63)/64)*((h+63)/64);if(!tiles||tiles>4096)return false;at+=8;for(uint64_t j=0;j<=tiles;j++){if(!SN_ROW(xcf_offset,at,v->n))return false;unsigned value=sxnx_u32(v->p+at,true);at+=4;if(!value)break;if(j==tiles)return false;}}
 return false;}
static bool sxnx_xcf_drawable(sxnx_view*v,size_t p,bool layer)
{if(!sxnx_row(v,layer?&sxnx_xcf_layer:&sxnx_xcf_channel,p,v->n))return false;p+=layer?12:8;if(!sxnx_walk_xcf_string(v,&p,v->n)||!sxnx_xcf_props(v,&p)||!SN_ROW(xcf_offset,p,v->n))return false;unsigned hierarchy=sxnx_u32(v->p+p,true);p+=4;unsigned mask=0;if(layer){if(!SN_ROW(xcf_offset,p,v->n))return false;mask=sxnx_u32(v->p+p,true);}if(hierarchy&&!sxnx_walk_xcf_hierarchy(v,hierarchy))return false;return !mask||sxnx_xcf_drawable(v,mask,false);}
static bool sxnx_xcf(sxnx_view*v)
{if(!SN_ROW(xcf_header,0,v->n))return false;size_t p=26;if(!sxnx_xcf_props(v,&p))return false;for(unsigned kind=0;kind<2;kind++){bool done=false;for(unsigned i=0;i<=1024;i++){if(!SN_ROW(xcf_offset,p,v->n))return false;unsigned at=sxnx_u32(v->p+p,true);p+=4;if(!at){done=true;break;}if(i==1024||!sxnx_xcf_drawable(v,at,kind==0))return false;}if(!done)return false;}return true;}
static bool sxnx_bpg_uint(sxnx_view*v,size_t*p,size_t end,unsigned kind,uint32_t*out)
{size_t start=*p;unsigned width;if(!sxnx_varuint(v,p,end,out,&width))return false;const sx_layout*l=NULL;switch(kind){
case 0:switch(width){case 1:l=&sxnx_bpg_width_1;break;case 2:l=&sxnx_bpg_width_2;break;case 3:l=&sxnx_bpg_width_3;break;}break;
case 1:switch(width){case 1:l=&sxnx_bpg_height_1;break;case 2:l=&sxnx_bpg_height_2;break;case 3:l=&sxnx_bpg_height_3;break;}break;
case 2:switch(width){case 1:l=&sxnx_bpg_picture_bytes_1;break;case 2:l=&sxnx_bpg_picture_bytes_2;break;case 3:l=&sxnx_bpg_picture_bytes_3;break;case 4:l=&sxnx_bpg_picture_bytes_4;break;}break;
case 3:switch(width){case 1:l=&sxnx_bpg_extension_bytes_1;break;case 2:l=&sxnx_bpg_extension_bytes_2;break;case 3:l=&sxnx_bpg_extension_bytes_3;break;}break;
case 4:switch(width){case 1:l=&sxnx_bpg_extension_tag_1;break;case 2:l=&sxnx_bpg_extension_tag_2;break;case 3:l=&sxnx_bpg_extension_tag_3;break;case 4:l=&sxnx_bpg_extension_tag_4;break;case 5:l=&sxnx_bpg_extension_tag_5;break;}break;
case 5:switch(width){case 1:l=&sxnx_bpg_extension_data_bytes_1;break;case 2:l=&sxnx_bpg_extension_data_bytes_2;break;case 3:l=&sxnx_bpg_extension_data_bytes_3;break;}break;
case 6:switch(width){case 1:l=&sxnx_bpg_hevc_header_bytes_1;break;}break;
}return l&&sxnx_row(v,l,start,*p);}
static bool sxnx_bpg(sxnx_view*v)
{if(!SN_ROW(bpg_header,0,v->n))return false;size_t p=6;uint32_t z;for(unsigned i=0;i<3;i++)if(!sxnx_bpg_uint(v,&p,v->n,i,&z))return false;if(v->p[5]&8){if(!sxnx_bpg_uint(v,&p,v->n,3,&z)||!sxnx_need(v,p,z,v->n))return false;size_t end=p+z;while(p<end){if(!sxnx_bpg_uint(v,&p,end,4,&z)||!sxnx_bpg_uint(v,&p,end,5,&z)||!sxnx_need(v,p,z,end))return false;p+=z;}}
 for(unsigned i=0;i<(((v->p[4]&16)||(v->p[5]&4))?2U:1U);i++){if(!sxnx_bpg_uint(v,&p,v->n,6,&z)||!sxnx_need(v,p,z,v->n))return false;p+=z;}
 unsigned work=0;while(p<v->n){if(++work>2048||!SN_ROW(bpg_nal,p,v->n))return false;p+=2;size_t end=p;unsigned zeros=0;while(end<v->n){if(!sxnx_need(v,end,1,v->n))return false;if(!v->p[end]){zeros++;end++;continue;}if(v->p[end]==1&&zeros>=2){end-=zeros;break;}zeros=0;end++;}p=end;if(p<v->n){unsigned zero=0;while(p<v->n&&!v->p[p]){p++;zero++;}if(p==v->n)break;if(v->p[p]!=1||zero<2||zero>16)return false;p++;}}
 return true;}
static bool sxnx_ani_chunks(sxnx_view*v,size_t p,size_t end,bool frames)
{while(p<end){if(!SN_ROW(ani_chunk,p,end))return false;uint32_t id=sxnx_u32(v->p+p,true),z=sxnx_u32(v->p+p+4,false);p+=8;if(!sxnx_need(v,p,(uint64_t)z+(z&1),end))return false;size_t next=p+z+(z&1);
 if(id==UINT32_C(0x616e6968)){if(!SN_ROW(ani_header,p,p+z))return false;}else if(id==UINT32_C(0x4c495354)){if(!SN_ROW(ani_list,p,p+z))return false;if(!frames&&sxnx_u32(v->p+p,true)==UINT32_C(0x6672616d)&&!sxnx_ani_chunks(v,p+4,p+z,true))return false;}else if(id==UINT32_C(0x72617465)||id==UINT32_C(0x73657120)){if(z%4||!sxnx_table(v,id==UINT32_C(0x72617465)?&sxnx_ani_rate:&sxnx_ani_sequence,p,z/4,p+z))return false;}else if(frames&&id==UINT32_C(0x69636f6e)){if(!SN_ROW(ani_icon_header,p,p+z))return false;unsigned count=sxnx_u16(v->p+p+4,false);if(!sxnx_table(v,sxnx_u16(v->p+p+2,false)==2?&sxnx_ani_cursor_entry:&sxnx_ani_icon_entry,p+6,count,p+z))return false;}p=next;}return p==end;}
static bool sxnx_ani(sxnx_view*v){return SN_ROW(ani_riff,0,v->n)&&sxnx_ani_chunks(v,12,v->n,false);}
static bool sxnx_pamf(sxnx_view*v)
{if(!SN_ROW(pamf_header,0,v->n)||!SN_ROW(pamf_sequence,80,v->n)||!SN_ROW(pamf_period,112,v->n)||!SN_ROW(pamf_group,130,v->n))return false;unsigned n=v->p[135];if(n>32)return false;uint64_t header=(uint64_t)sxnx_u32(v->p+8,true)*2048;if(header>v->n)return false;for(unsigned i=0;i<n;i++){size_t p=136+i*48;if(!SN_ROW(pamf_stream,p,(size_t)header))return false;unsigned type=v->p[p];const sx_layout*l=type==0x1b?&sxnx_pamf_avc:type==2?&sxnx_pamf_m2v:type==0xdc||type==0x80||type==0x81?&sxnx_pamf_audio:&sxnx_pamf_userdata;if(!sxnx_row(v,l,p+16,(size_t)header)||!sxnx_table(v,&sxnx_pamf_entry_point,sxnx_u32(v->p+p+8,true),sxnx_u32(v->p+p+12,true),(size_t)header))return false;}return true;}
static bool sxnx_usm_utf(sxnx_view*v,size_t base,size_t end)
{if(!SN_ROW(usm_utf_header,base,end))return false;uint64_t sz=8+(uint64_t)sxnx_u32(v->p+base+4,true);if(!sxnx_need(v,base,sz,end))return false;end=base+(size_t)sz;size_t rows=base+8+sxnx_u16(v->p+base+10,true),strings=base+8+sxnx_u32(v->p+base+12,true),p=base+32;unsigned count=sxnx_u16(v->p+base+24,true),width=sxnx_u16(v->p+base+26,true),nr=sxnx_u32(v->p+base+28,true);if(count>128||nr>1024||rows>strings||strings>end||!sxnx_need(v,rows,(uint64_t)width*nr,strings))return false;
 const sx_layout*types[]={&sxnx_usm_utf_value_u8,&sxnx_usm_utf_value_i8,&sxnx_usm_utf_value_u16,&sxnx_usm_utf_value_i16,&sxnx_usm_utf_value_u32,&sxnx_usm_utf_value_i32,&sxnx_usm_utf_value_u64,&sxnx_usm_utf_value_i64,&sxnx_usm_utf_value_f32,&sxnx_usm_utf_value_f64,&sxnx_usm_utf_string,&sxnx_usm_utf_data,&sxnx_usm_utf_guid};unsigned colsize[]={1,1,2,2,4,4,8,8,4,8,4,8,16},kind[128],flags[128],offset[128],rw=0;
 for(unsigned i=0;i<count;i++){if(!SN_ROW(usm_utf_column,p,rows))return false;kind[i]=v->p[p]&15;flags[i]=v->p[p]&0xf0;offset[i]=rw;p+=5;if(kind[i]>12)return false;if(flags[i]&0x20){if(!sxnx_row(v,types[kind[i]],p,rows))return false;p+=colsize[kind[i]];}if(flags[i]&0x40){if(rw>width||colsize[kind[i]]>width-rw)return false;rw+=colsize[kind[i]];}}
 for(unsigned j=0;j<nr;j++)for(unsigned i=0;i<count;i++)if((flags[i]&0x40)&&!sxnx_row(v,types[kind[i]],rows+(size_t)j*width+offset[i],strings))return false;return true;}
static bool sxnx_usm(sxnx_view*v)
{size_t p=0;unsigned count=0;while(p<v->n){if(++count>4096||!SN_ROW(usm_chunk,p,v->n))return false;uint64_t size=8+(uint64_t)sxnx_u32(v->p+p+4,true);unsigned offset=sxnx_u16(v->p+p+8,true),pad=sxnx_u16(v->p+p+10,true),type=sxnx_u16(v->p+p+14,true);if(size<32||!sxnx_need(v,p,size,v->n)||offset+8U>size||pad>size-offset-8)return false;size_t end=p+(size_t)size;if((type==1||type==3)&&!sxnx_usm_utf(v,p+8+offset,end-pad))return false;p=end;}return true;}
static bool sxnx_mve(sxnx_view*v)
{if(!SN_ROW(mve_header,0,v->n))return false;size_t p=26;while(p<v->n){if(!SN_ROW(mve_chunk,p,v->n))return false;unsigned z=sxnx_u16(v->p+p,false);p+=4;if(!sxnx_need(v,p,z,v->n))return false;size_t end=p+z;
 while(p<end){if(!SN_ROW(mve_opcode,p,end))return false;unsigned n=sxnx_u16(v->p+p,false),op=v->p[p+2],version=v->p[p+3];p+=4;if(!sxnx_need(v,p,n,end))return false;const sx_layout*l=NULL;if(op==2)l=&sxnx_mve_timer;else if(op==3)l=&sxnx_mve_audio_init;else if(op==5){if(version>2)return false;l=version==0?&sxnx_mve_video_init_0:version==1?&sxnx_mve_video_init_1:&sxnx_mve_video_init_2;}else if(op==7)l=&sxnx_mve_send_buffer;else if(op==8||op==9)l=&sxnx_mve_audio_frame;else if(op==10)l=&sxnx_mve_video_mode;else if(op==12){if(!SN_ROW(mve_palette,p,p+n)||!sxnx_table(v,&sxnx_rgb_palette_entry,p+4,sxnx_u16(v->p+p+2,false),p+n))return false;}if(l&&!sxnx_row(v,l,p,p+n))return false;p+=n;}}return true;}
static bool sxnx_vqa_chunks(sxnx_view*v,size_t p,size_t end,bool nested)
{while(p<end){if(!SN_ROW(vqa_chunk,p,end))return false;unsigned z=sxnx_u32(v->p+p+4,true),id=sxnx_u32(v->p+p,true);p+=8;if(!sxnx_need(v,p,(uint64_t)z+(z&1),end))return false;if(id==UINT32_C(0x46494e46)){if(z%4||!sxnx_table(v,&sxnx_vqa_frame_index,p,z/4,p+z))return false;}else if(!nested&&(id==UINT32_C(0x56514652)||id==UINT32_C(0x5651464c))){if(!sxnx_vqa_chunks(v,p,p+z,true))return false;}else if(id==UINT32_C(0x534e4431)){if(!SN_ROW(vqa_sound,p,p+z))return false;}else if(id==UINT32_C(0x43504c30)){if(z%3||!sxnx_table(v,&sxnx_rgb_palette_entry,p,z/3,p+z))return false;}p+=z+(z&1);}return p==end;}
static bool sxnx_vqa(sxnx_view*v){return SN_ROW(vqa_form,0,v->n)&&SN_ROW(vqa_chunk,12,v->n)&&SN_ROW(vqa_header,20,v->n)&&sxnx_vqa_chunks(v,62,v->n,false);}
static bool sxnx_mng(sxnx_view*v)
{if(!SN_ROW(mng_signature,0,v->n))return false;size_t p=8;unsigned color=0;while(p<v->n){if(!SN_ROW(mng_chunk,p,v->n))return false;unsigned z=sxnx_u32(v->p+p,true),id=sxnx_u32(v->p+p+4,true);p+=8;if(!sxnx_need(v,p,(uint64_t)z+4,v->n)||!SN_ROW(mng_crc,p+z,v->n))return false;const sx_layout*l=NULL;
 switch(id){case 0x4d484452:l=&sxnx_mng_header;break;case 0x49484452:l=&sxnx_mng_png_header;if(!sxnx_need(v,p,13,p+z))return false;color=v->p[p+9];break;case 0x504c5445:if(z%3||!sxnx_table(v,&sxnx_rgb_palette_entry,p,z/3,p+z))return false;break;case 0x74524e53:if(color==3){if(!sxnx_table(v,&sxnx_mng_alpha,p,z,p+z))return false;}else l=color==0?&sxnx_mng_gray:&sxnx_mng_rgb;break;case 0x624b4744:l=color==3?&sxnx_mng_palette_index:color==0||color==4?&sxnx_mng_gray:&sxnx_mng_rgb;break;case 0x67414d41:l=&sxnx_mng_gamma;break;case 0x6348524d:l=&sxnx_mng_chromaticity;break;case 0x73524742:l=&sxnx_mng_srgb;break;case 0x70485973:l=&sxnx_mng_physical;break;case 0x5445524d:l=&sxnx_mng_term;break;case 0x4652414d:l=&sxnx_mng_fram;break;case 0x44454649:l=&sxnx_mng_defi;break;case 0x4241434b:l=&sxnx_mng_rgb;if(z==7&&!SN_ROW(mng_back_flag,p+6,p+z))return false;break;default:break;}
 if(l&&!sxnx_row(v,l,p,p+z))return false;p+=z+4;}return true;}
static bool sxnx_dxa(sxnx_view*v)
{if(!SN_ROW(dxa_header,0,v->n))return false;size_t p=19;unsigned count=sxnx_u16(v->p+5,true);if(!xx_rt_memcmp(v->p+15,"WAVE",4)){if(!SN_ROW(dxa_wave_size,p,v->n))return false;unsigned n=sxnx_u32(v->p+p,true);p+=4;if(!sxnx_need(v,p,n,v->n)||!SN_ROW(dxa_riff,p,p+n))return false;p+=n;}
 for(unsigned i=0;i<count;i++){if(!SN_ROW(dxa_tag,p,v->n))return false;unsigned id=sxnx_u32(v->p+p,true);p+=4;if(id==UINT32_C(0x434d4150)){if(!sxnx_table(v,&sxnx_rgb_palette_entry,p,256,v->n))return false;p+=768;}if(!sxnx_need(v,p,4,v->n))return false;if(!xx_rt_memcmp(v->p+p,"FRAM",4)){if(!SN_ROW(dxa_frame,p,v->n))return false;unsigned n=sxnx_u32(v->p+p+5,true);p+=9;if(!sxnx_need(v,p,n,v->n))return false;p+=n;}else{if(!SN_ROW(dxa_tag,p,v->n))return false;p+=4;}}return p<=v->n;}
static bool sxnx_rm(sxnx_view*v)
{if(!SN_ROW(rmf_header,0,v->n))return false;size_t p=18;unsigned work=0;while(p<v->n){if(++work>20||!SN_ROW(rm_object,p,v->n))return false;unsigned id=sxnx_u32(v->p+p,true),n=sxnx_u32(v->p+p+4,true);size_t start=p;p+=10;if(n<10)return false;
 if(id==UINT32_C(0x44415441)){if(!SN_ROW(rm_data,p,v->n))return false;unsigned count=sxnx_u32(v->p+p,true);if(count>4090)return false;p+=8;for(unsigned i=0;i<count;i++){if(!SN_ROW(rm_packet,p,v->n))return false;unsigned z=sxnx_u16(v->p+p+2,true);if(z<12||!sxnx_need(v,p,z,v->n))return false;p+=z;}if(n==(uint64_t)(p-start)+18){if(!sxnx_need(v,p,8,v->n))return false;p+=8;}else if(n!=p-start)return false;continue;}
 if(!sxnx_need(v,start,n,v->n))return false;size_t end=start+n;
 if(id==UINT32_C(0x50524f50)){if(!SN_ROW(rm_prop,p,end))return false;}else if(id==UINT32_C(0x434f4e54)){const sx_layout*l[]={&sxnx_rm_title_length,&sxnx_rm_author_length,&sxnx_rm_copyright_length,&sxnx_rm_comment_length};for(unsigned i=0;i<4;i++){if(!sxnx_row(v,l[i],p,end))return false;unsigned z=sxnx_u16(v->p+p,true);p+=2;if(!sxnx_need(v,p,z,end))return false;p+=z;}}else if(id==UINT32_C(0x4d445052)){if(!SN_ROW(rm_mdpr,p,end))return false;p+=30;const sx_layout*l[]={&sxnx_rm_name_length,&sxnx_rm_mime_length};for(unsigned i=0;i<2;i++){if(!sxnx_row(v,l[i],p,end))return false;unsigned z=v->p[p++];if(!sxnx_need(v,p,z,end))return false;p+=z;}if(!SN_ROW(rm_specific_length,p,end))return false;unsigned z=sxnx_u32(v->p+p,true);p+=4;if(!sxnx_need(v,p,z,end))return false;if(z>=12&&!xx_rt_memcmp(v->p+p+4,"VIDO",4)){if(!SN_ROW(rm_video,p,p+z))return false;}else if(!SN_ROW(rm_audio_prefix,p,p+z))return false;
 }else if(id==UINT32_C(0x494e4458)){if(!SN_ROW(rm_index,p,end)||!sxnx_table(v,&sxnx_rm_index_entry,p+10,sxnx_u32(v->p+p,true),end))return false;}p=end;}return true;}
static bool sxnx_pes(sxnx_view*v,size_t p,size_t end)
{if(!sxnx_need(v,p,1,end))return false;if((v->p[p]&0xc0)==0x80){if(!SN_ROW(mpeg_pes2,p,end))return false;unsigned flags=v->p[p+1]>>6,z=v->p[p+2];p+=3;if(!sxnx_need(v,p,z,end))return false;if(flags>=2){if(!SN_ROW(mpeg_timestamp,p,p+z))return false;if(flags==3&&!SN_ROW(mpeg_timestamp,p+5,p+z))return false;}return true;}
 unsigned work=0;while(p<end&&v->p[p]==255){if(++work>16)return false;p++;}if(!sxnx_need(v,p,1,end))return false;if((v->p[p]&0xc0)==0x40){if(!SN_ROW(mpeg_pes1_buffer,p,end))return false;p+=2;}if(!sxnx_need(v,p,1,end))return false;if(v->p[p]==15)return SN_ROW(mpeg_pes1_no_timestamp,p,end);unsigned tag=v->p[p]>>4;if(tag==2||tag==3){if(!SN_ROW(mpeg_timestamp,p,end))return false;return tag!=3||SN_ROW(mpeg_timestamp,p+5,end);}return false;}
static bool sxnx_ps(sxnx_view*v)
{size_t p=0;while(p<v->n){if(!sxnx_need(v,p,4,v->n))return false;unsigned kind=v->p[p+3];if(kind==0xb9){if(!SN_ROW(mpeg_start_code,p,v->n))return false;p+=4;continue;}if(kind==0xba){if(!sxnx_need(v,p,5,v->n))return false;bool one=(v->p[p+4]>>4)==2;if(!sxnx_row(v,one?&sxnx_mpeg_pack1:&sxnx_mpeg_pack2,p,v->n))return false;unsigned z=one?0:v->p[p+13]&7;p+=one?12:14;if(!sxnx_need(v,p,z,v->n))return false;p+=z;continue;}
 if(!SN_ROW(mpeg_packet,p,v->n))return false;unsigned z=sxnx_u16(v->p+p+4,true);p+=6;if(!sxnx_need(v,p,z,v->n))return false;size_t end=p+z;
 if(kind==0xbb){if(!SN_ROW(mpeg_system,p,end)||z<6||(z-6)%3||!sxnx_table(v,&sxnx_mpeg_system_stream,p+6,(z-6)/3,end))return false;}else if(kind==0xbc){if(z<10||!SN_ROW(mpeg_map,p,end))return false;unsigned bytes=sxnx_u16(v->p+p+2,true);p+=4;if(!sxnx_need(v,p,bytes,end-4))return false;p+=bytes;if(!SN_ROW(mpeg_map_length,p,end-4))return false;bytes=sxnx_u16(v->p+p,true);p+=2;if(!sxnx_need(v,p,bytes,end-4))return false;size_t stop=p+bytes;while(p<stop){if(!SN_ROW(mpeg_map_stream,p,stop))return false;unsigned n=sxnx_u16(v->p+p+2,true);p+=4;if(!sxnx_need(v,p,n,stop))return false;p+=n;}if(!SN_ROW(mpeg_crc,end-4,end))return false;}else if(kind==0xbd||(kind>=0xc0&&kind<=0xef)){if(!sxnx_pes(v,p,end))return false;}p=end;}return true;}
static bool sxnx_ts_descriptors(sxnx_view*v,size_t p,size_t end)
{while(p<end){if(!SN_ROW(ts_descriptor,p,end))return false;unsigned n=v->p[p+1];p+=2;if(!sxnx_need(v,p,n,end))return false;p+=n;}return true;}
static bool sxnx_ts(sxnx_view*v)
{if(v->n%188||v->n/188>4096)return false;unsigned pmt=8191;for(size_t at=0;at<v->n;at+=188){size_t end=at+188,p=at+4;if(!SN_ROW(ts_header,at,end))return false;unsigned pid=sxnx_u16(v->p+at+1,true)&8191,control=(v->p[at+3]>>4)&3;bool start=(v->p[at+1]&64)!=0;
 if(control&2){if(!SN_ROW(ts_adaptation_size,p,end))return false;unsigned z=v->p[p++];if(!sxnx_need(v,p,z,end))return false;size_t ae=p+z;if(z){if(!SN_ROW(ts_adaptation_flags,p,ae))return false;unsigned flags=v->p[p++];if(flags&16){if(!SN_ROW(ts_clock,p,ae))return false;p+=6;}if(flags&8){if(!SN_ROW(ts_clock,p,ae))return false;p+=6;}if(flags&4){if(!SN_ROW(ts_splice,p,ae))return false;p++;}if(flags&2){if(!SN_ROW(ts_private_size,p,ae))return false;unsigned n=v->p[p++];if(!sxnx_need(v,p,n,ae))return false;p+=n;}}p=ae;}
 if(!(control&1)||p>=end)continue;if(start&&(pid==0||pid==17||pid==pmt)){if(!SN_ROW(ts_pointer,p,end))return false;unsigned pointer=v->p[p++];if(!sxnx_need(v,p,pointer,end))return false;p+=pointer;if(!SN_ROW(ts_section,p,end))return false;unsigned z=sxnx_u16(v->p+p+1,true)&4095;if(z<9||!sxnx_need(v,p,3+z,end))return false;size_t finish=p+3+z,q=p+8;if(!SN_ROW(mpeg_crc,finish-4,finish))return false;
 if(pid==0){if(!SN_ROW(ts_pat_program,q,finish-4))return false;pmt=sxnx_u16(v->p+q+2,true)&8191;}else if(pid==17){if(!SN_ROW(ts_sdt,q,finish-4))return false;q+=3;while(q<finish-4){if(!SN_ROW(ts_sdt_service,q,finish-4))return false;unsigned n=sxnx_u16(v->p+q+3,true)&4095;q+=5;if(!sxnx_need(v,q,n,finish-4)||!sxnx_ts_descriptors(v,q,q+n))return false;q+=n;}}
 else{if(!SN_ROW(ts_pmt,q,finish-4))return false;unsigned n=sxnx_u16(v->p+q+2,true)&4095;q+=4;if(!sxnx_need(v,q,n,finish-4)||!sxnx_ts_descriptors(v,q,q+n))return false;q+=n;while(q<finish-4){if(!SN_ROW(ts_pmt_stream,q,finish-4))return false;n=sxnx_u16(v->p+q+3,true)&4095;q+=5;if(!sxnx_need(v,q,n,finish-4)||!sxnx_ts_descriptors(v,q,q+n))return false;q+=n;}}
 }else if(start&&pid!=8191){if(!SN_ROW(mpeg_packet,p,end)||!sxnx_pes(v,p+6,end))return false;}}
 return true;}

static bool sx_nextmedia_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_EMF:
case XX_FILE_TYPE_WMF:
case XX_FILE_TYPE_GIMP_XCF:
case XX_FILE_TYPE_PHOTOSHOP_ABR:
case XX_FILE_TYPE_QT_QPICTURE:
case XX_FILE_TYPE_BPG_IMAGE:
case XX_FILE_TYPE_PAINTSHOP_PSP:
case XX_FILE_TYPE_PHOTOSHOP_PAT:
case XX_FILE_TYPE_AMIGA_DISKOBJECT:
case XX_FILE_TYPE_WBMP_IMAGE:
case XX_FILE_TYPE_PALM_BITMAP:
case XX_FILE_TYPE_APPLE_PICT:
case XX_FILE_TYPE_WORDPERFECT_WPG:
case XX_FILE_TYPE_KHOROS_VIFF:
case XX_FILE_TYPE_RISC_OS_SPRITE:
case XX_FILE_TYPE_WINDOWS_ANI:
case XX_FILE_TYPE_WINDOWS_THUMBNAIL_CACHE:
case XX_FILE_TYPE_SONY_PAMF:
case XX_FILE_TYPE_CRI_USM:
case XX_FILE_TYPE_MPEG_TRANSPORT_STREAM:
case XX_FILE_TYPE_MPEG_PROGRAM_STREAM:
case XX_FILE_TYPE_REALMEDIA_RM:
case XX_FILE_TYPE_INTERPLAY_MVE:
case XX_FILE_TYPE_WESTWOOD_VQA:
case XX_FILE_TYPE_MNG_ANIMATION:
case XX_FILE_TYPE_SCUMMVM_DXA:
return true;default:return false;}}
static bool sx_nextmedia_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>134217728)return false;sxnx_view view={c,NULL,(size_t)c->size,0},*v=&view;v->p=(uint8_t*)xx_mem_alloc(v->n);if(!v->p||!sx_read(c,0,v->p,v->n)){xx_mem_free(v->p);return false;}bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_EMF:ok=sxnx_emf(v);break;
case XX_FILE_TYPE_WMF:ok=sxnx_wmf(v);break;
case XX_FILE_TYPE_GIMP_XCF:ok=sxnx_xcf(v);break;
case XX_FILE_TYPE_PHOTOSHOP_ABR:ok=sxnx_abr(v);break;
case XX_FILE_TYPE_QT_QPICTURE:ok=sxnx_qpic(v);break;
case XX_FILE_TYPE_BPG_IMAGE:ok=sxnx_bpg(v);break;
case XX_FILE_TYPE_PAINTSHOP_PSP:ok=sxnx_psp(v);break;
case XX_FILE_TYPE_PHOTOSHOP_PAT:ok=sxnx_pat(v);break;
case XX_FILE_TYPE_AMIGA_DISKOBJECT:ok=sxnx_icon(v);break;
case XX_FILE_TYPE_WBMP_IMAGE:ok=sxnx_wbmp(v);break;
case XX_FILE_TYPE_PALM_BITMAP:ok=sxnx_palm(v);break;
case XX_FILE_TYPE_APPLE_PICT:ok=sxnx_pict(v);break;
case XX_FILE_TYPE_WORDPERFECT_WPG:ok=sxnx_wpg(v);break;
case XX_FILE_TYPE_KHOROS_VIFF:ok=sxnx_viff(v);break;
case XX_FILE_TYPE_RISC_OS_SPRITE:ok=sxnx_sprite(v);break;
case XX_FILE_TYPE_WINDOWS_ANI:ok=sxnx_ani(v);break;
case XX_FILE_TYPE_WINDOWS_THUMBNAIL_CACHE:ok=sxnx_thumb(v);break;
case XX_FILE_TYPE_SONY_PAMF:ok=sxnx_pamf(v);break;
case XX_FILE_TYPE_CRI_USM:ok=sxnx_usm(v);break;
case XX_FILE_TYPE_MPEG_TRANSPORT_STREAM:ok=sxnx_ts(v);break;
case XX_FILE_TYPE_MPEG_PROGRAM_STREAM:ok=sxnx_ps(v);break;
case XX_FILE_TYPE_REALMEDIA_RM:ok=sxnx_rm(v);break;
case XX_FILE_TYPE_INTERPLAY_MVE:ok=sxnx_mve(v);break;
case XX_FILE_TYPE_WESTWOOD_VQA:ok=sxnx_vqa(v);break;
case XX_FILE_TYPE_MNG_ANIMATION:ok=sxnx_mng(v);break;
case XX_FILE_TYPE_SCUMMVM_DXA:ok=sxnx_dxa(v);break;
default:break;}
 xx_mem_free(v->p);return ok&&sxnx_finish(c);}
#undef SN_ROW
static bool sx_nextmedia_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60320001)||id>=UINT32_C(0x60330000))return true;
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"EMR_HEADER");
 case 2u:return xx_data_struct_record_set_comment(r,L"EMR_POLYBEZIER");
 case 3u:return xx_data_struct_record_set_comment(r,L"EMR_POLYGON");
 case 4u:return xx_data_struct_record_set_comment(r,L"EMR_POLYLINE");
 case 5u:return xx_data_struct_record_set_comment(r,L"EMR_POLYBEZIERTO");
 case 6u:return xx_data_struct_record_set_comment(r,L"EMR_POLYLINETO");
 case 9u:return xx_data_struct_record_set_comment(r,L"EMR_SETWINDOWEXTEX");
 case 10u:return xx_data_struct_record_set_comment(r,L"EMR_SETWINDOWORGEX");
 case 11u:return xx_data_struct_record_set_comment(r,L"EMR_SETVIEWPORTEXTEX");
 case 12u:return xx_data_struct_record_set_comment(r,L"EMR_SETVIEWPORTORGEX");
 case 14u:return xx_data_struct_record_set_comment(r,L"EMR_EOF");
 case 15u:return xx_data_struct_record_set_comment(r,L"EMR_SETPIXELV");
 case 16u:return xx_data_struct_record_set_comment(r,L"EMR_SETMAPPERFLAGS");
 case 17u:return xx_data_struct_record_set_comment(r,L"EMR_SETMAPMODE");
 case 18u:return xx_data_struct_record_set_comment(r,L"EMR_SETBKMODE");
 case 19u:return xx_data_struct_record_set_comment(r,L"EMR_SETPOLYFILLMODE");
 case 20u:return xx_data_struct_record_set_comment(r,L"EMR_SETROP2");
 case 21u:return xx_data_struct_record_set_comment(r,L"EMR_SETSTRETCHBLTMODE");
 case 22u:return xx_data_struct_record_set_comment(r,L"EMR_SETTEXTALIGN");
 case 24u:return xx_data_struct_record_set_comment(r,L"EMR_SETTEXTCOLOR");
 case 25u:return xx_data_struct_record_set_comment(r,L"EMR_SETBKCOLOR");
 case 27u:return xx_data_struct_record_set_comment(r,L"EMR_MOVETOEX");
 case 33u:return xx_data_struct_record_set_comment(r,L"EMR_SAVEDC");
 case 34u:return xx_data_struct_record_set_comment(r,L"EMR_RESTOREDC");
 case 37u:return xx_data_struct_record_set_comment(r,L"EMR_SELECTOBJECT");
 case 38u:return xx_data_struct_record_set_comment(r,L"EMR_CREATEPEN");
 case 39u:return xx_data_struct_record_set_comment(r,L"EMR_CREATEBRUSHINDIRECT");
 case 40u:return xx_data_struct_record_set_comment(r,L"EMR_DELETEOBJECT");
 case 42u:return xx_data_struct_record_set_comment(r,L"EMR_ELLIPSE");
 case 43u:return xx_data_struct_record_set_comment(r,L"EMR_RECTANGLE");
 case 54u:return xx_data_struct_record_set_comment(r,L"EMR_LINETO");
 default:break;}}
 if(id==1613889538u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"EMR_HEADER");
 case 2u:return xx_data_struct_record_set_comment(r,L"EMR_POLYBEZIER");
 case 3u:return xx_data_struct_record_set_comment(r,L"EMR_POLYGON");
 case 4u:return xx_data_struct_record_set_comment(r,L"EMR_POLYLINE");
 case 5u:return xx_data_struct_record_set_comment(r,L"EMR_POLYBEZIERTO");
 case 6u:return xx_data_struct_record_set_comment(r,L"EMR_POLYLINETO");
 case 9u:return xx_data_struct_record_set_comment(r,L"EMR_SETWINDOWEXTEX");
 case 10u:return xx_data_struct_record_set_comment(r,L"EMR_SETWINDOWORGEX");
 case 11u:return xx_data_struct_record_set_comment(r,L"EMR_SETVIEWPORTEXTEX");
 case 12u:return xx_data_struct_record_set_comment(r,L"EMR_SETVIEWPORTORGEX");
 case 14u:return xx_data_struct_record_set_comment(r,L"EMR_EOF");
 case 15u:return xx_data_struct_record_set_comment(r,L"EMR_SETPIXELV");
 case 16u:return xx_data_struct_record_set_comment(r,L"EMR_SETMAPPERFLAGS");
 case 17u:return xx_data_struct_record_set_comment(r,L"EMR_SETMAPMODE");
 case 18u:return xx_data_struct_record_set_comment(r,L"EMR_SETBKMODE");
 case 19u:return xx_data_struct_record_set_comment(r,L"EMR_SETPOLYFILLMODE");
 case 20u:return xx_data_struct_record_set_comment(r,L"EMR_SETROP2");
 case 21u:return xx_data_struct_record_set_comment(r,L"EMR_SETSTRETCHBLTMODE");
 case 22u:return xx_data_struct_record_set_comment(r,L"EMR_SETTEXTALIGN");
 case 24u:return xx_data_struct_record_set_comment(r,L"EMR_SETTEXTCOLOR");
 case 25u:return xx_data_struct_record_set_comment(r,L"EMR_SETBKCOLOR");
 case 27u:return xx_data_struct_record_set_comment(r,L"EMR_MOVETOEX");
 case 33u:return xx_data_struct_record_set_comment(r,L"EMR_SAVEDC");
 case 34u:return xx_data_struct_record_set_comment(r,L"EMR_RESTOREDC");
 case 37u:return xx_data_struct_record_set_comment(r,L"EMR_SELECTOBJECT");
 case 38u:return xx_data_struct_record_set_comment(r,L"EMR_CREATEPEN");
 case 39u:return xx_data_struct_record_set_comment(r,L"EMR_CREATEBRUSHINDIRECT");
 case 40u:return xx_data_struct_record_set_comment(r,L"EMR_DELETEOBJECT");
 case 42u:return xx_data_struct_record_set_comment(r,L"EMR_ELLIPSE");
 case 43u:return xx_data_struct_record_set_comment(r,L"EMR_RECTANGLE");
 case 54u:return xx_data_struct_record_set_comment(r,L"EMR_LINETO");
 default:break;}}
 if(id==1613889552u&&!xx_rt_wcscmp(r->name,L"function")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"META_EOF");
 case 30u:return xx_data_struct_record_set_comment(r,L"META_SAVEDC");
 case 295u:return xx_data_struct_record_set_comment(r,L"META_RESTOREDC");
 case 301u:return xx_data_struct_record_set_comment(r,L"META_SELECTOBJECT");
 case 496u:return xx_data_struct_record_set_comment(r,L"META_DELETEOBJECT");
 case 513u:return xx_data_struct_record_set_comment(r,L"META_SETBKCOLOR");
 case 521u:return xx_data_struct_record_set_comment(r,L"META_SETTEXTCOLOR");
 case 531u:return xx_data_struct_record_set_comment(r,L"META_LINETO");
 case 532u:return xx_data_struct_record_set_comment(r,L"META_MOVETO");
 case 762u:return xx_data_struct_record_set_comment(r,L"META_CREATEPENINDIRECT");
 case 764u:return xx_data_struct_record_set_comment(r,L"META_CREATEBRUSHINDIRECT");
 case 804u:return xx_data_struct_record_set_comment(r,L"META_POLYGON");
 case 805u:return xx_data_struct_record_set_comment(r,L"META_POLYLINE");
 case 1048u:return xx_data_struct_record_set_comment(r,L"META_ELLIPSE");
 case 1051u:return xx_data_struct_record_set_comment(r,L"META_RECTANGLE");
 default:break;}}
 if(id==1613889551u&&!xx_rt_wcscmp(r->name,L"file_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"MEMORY_METAFILE");
 case 2u:return xx_data_struct_record_set_comment(r,L"DISK_METAFILE");
 default:break;}}
 if(id==1613889548u&&!xx_rt_wcscmp(r->name,L"style")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"BS_SOLID");
 case 1u:return xx_data_struct_record_set_comment(r,L"BS_NULL");
 case 2u:return xx_data_struct_record_set_comment(r,L"BS_HATCHED");
 case 3u:return xx_data_struct_record_set_comment(r,L"BS_PATTERN");
 case 5u:return xx_data_struct_record_set_comment(r,L"BS_DIBPATTERN");
 default:break;}}
 if(id==1613889562u&&!xx_rt_wcscmp(r->name,L"style")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"BS_SOLID");
 case 1u:return xx_data_struct_record_set_comment(r,L"BS_NULL");
 case 2u:return xx_data_struct_record_set_comment(r,L"BS_HATCHED");
 case 3u:return xx_data_struct_record_set_comment(r,L"BS_PATTERN");
 case 5u:return xx_data_struct_record_set_comment(r,L"BS_DIBPATTERN");
 default:break;}}
 if(id==1613889548u&&!xx_rt_wcscmp(r->name,L"hatch")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"HS_HORIZONTAL");
 case 1u:return xx_data_struct_record_set_comment(r,L"HS_VERTICAL");
 case 2u:return xx_data_struct_record_set_comment(r,L"HS_FDIAGONAL");
 case 3u:return xx_data_struct_record_set_comment(r,L"HS_BDIAGONAL");
 case 4u:return xx_data_struct_record_set_comment(r,L"HS_CROSS");
 case 5u:return xx_data_struct_record_set_comment(r,L"HS_DIAGCROSS");
 default:break;}}
 if(id==1613889562u&&!xx_rt_wcscmp(r->name,L"hatch")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"HS_HORIZONTAL");
 case 1u:return xx_data_struct_record_set_comment(r,L"HS_VERTICAL");
 case 2u:return xx_data_struct_record_set_comment(r,L"HS_FDIAGONAL");
 case 3u:return xx_data_struct_record_set_comment(r,L"HS_BDIAGONAL");
 case 4u:return xx_data_struct_record_set_comment(r,L"HS_CROSS");
 case 5u:return xx_data_struct_record_set_comment(r,L"HS_DIAGCROSS");
 default:break;}}
 if(id==1613889563u&&!xx_rt_wcscmp(r->name,L"type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"WBMP_TYPE_0_MONOCHROME");
 default:break;}}
 if(id==1613889568u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SCANLINE");
 case 1u:return xx_data_struct_record_set_comment(r,L"RLE");
 case 2u:return xx_data_struct_record_set_comment(r,L"PACKBITS");
 case 255u:return xx_data_struct_record_set_comment(r,L"UNCOMPRESSED");
 default:break;}}
 if(id==1613889572u&&!xx_rt_wcscmp(r->name,L"machine_dependency")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"IEEE_BIG_ENDIAN");
 case 4u:return xx_data_struct_record_set_comment(r,L"DEC_VAX");
 case 8u:return xx_data_struct_record_set_comment(r,L"IEEE_LITTLE_ENDIAN");
 default:break;}}
 if(id==1613889573u&&!xx_rt_wcscmp(r->name,L"machine_dependency")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"IEEE_BIG_ENDIAN");
 case 4u:return xx_data_struct_record_set_comment(r,L"DEC_VAX");
 case 8u:return xx_data_struct_record_set_comment(r,L"IEEE_LITTLE_ENDIAN");
 default:break;}}
 if(id==1613889574u&&!xx_rt_wcscmp(r->name,L"machine_dependency")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"IEEE_BIG_ENDIAN");
 case 4u:return xx_data_struct_record_set_comment(r,L"DEC_VAX");
 case 8u:return xx_data_struct_record_set_comment(r,L"IEEE_LITTLE_ENDIAN");
 default:break;}}
 if(id==1613889572u&&!xx_rt_wcscmp(r->name,L"storage_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_1_BYTE");
 case 2u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_2_BYTE");
 case 4u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_4_BYTE");
 case 5u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_FLOAT");
 case 9u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_DOUBLE");
 default:break;}}
 if(id==1613889573u&&!xx_rt_wcscmp(r->name,L"storage_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_1_BYTE");
 case 2u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_2_BYTE");
 case 4u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_4_BYTE");
 case 5u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_FLOAT");
 case 9u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_DOUBLE");
 default:break;}}
 if(id==1613889574u&&!xx_rt_wcscmp(r->name,L"storage_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_1_BYTE");
 case 2u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_2_BYTE");
 case 4u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_4_BYTE");
 case 5u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_FLOAT");
 case 9u:return xx_data_struct_record_set_comment(r,L"VFF_TYP_DOUBLE");
 default:break;}}
 if(id==1613889576u&&!xx_rt_wcscmp(r->name,L"brush_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"COMPUTED_BRUSH");
 case 2u:return xx_data_struct_record_set_comment(r,L"SAMPLED_BRUSH");
 default:break;}}
 if(id==1613889579u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"PACKBITS");
 default:break;}}
 if(id==1613889599u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"PACKBITS");
 default:break;}}
 if(id==1613889582u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 11u:return xx_data_struct_record_set_comment(r,L"BITMAP_TYPE_1");
 case 14u:return xx_data_struct_record_set_comment(r,L"COLORMAP");
 case 15u:return xx_data_struct_record_set_comment(r,L"START_WPG");
 case 16u:return xx_data_struct_record_set_comment(r,L"END_WPG");
 default:break;}}
 if(id==1613889583u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 11u:return xx_data_struct_record_set_comment(r,L"BITMAP_TYPE_1");
 case 14u:return xx_data_struct_record_set_comment(r,L"COLORMAP");
 case 15u:return xx_data_struct_record_set_comment(r,L"START_WPG");
 case 16u:return xx_data_struct_record_set_comment(r,L"END_WPG");
 default:break;}}
 if(id==1613889584u&&!xx_rt_wcscmp(r->name,L"record_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 11u:return xx_data_struct_record_set_comment(r,L"BITMAP_TYPE_1");
 case 14u:return xx_data_struct_record_set_comment(r,L"COLORMAP");
 case 15u:return xx_data_struct_record_set_comment(r,L"START_WPG");
 case 16u:return xx_data_struct_record_set_comment(r,L"END_WPG");
 default:break;}}
 if(id==1613889590u&&!xx_rt_wcscmp(r->name,L"block_id")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PSP_IMAGE_BLOCK");
 case 1u:return xx_data_struct_record_set_comment(r,L"PSP_CREATOR_BLOCK");
 case 2u:return xx_data_struct_record_set_comment(r,L"PSP_COLOR_BLOCK");
 case 3u:return xx_data_struct_record_set_comment(r,L"PSP_LAYER_START_BLOCK");
 case 4u:return xx_data_struct_record_set_comment(r,L"PSP_LAYER_BLOCK");
 case 5u:return xx_data_struct_record_set_comment(r,L"PSP_CHANNEL_BLOCK");
 case 6u:return xx_data_struct_record_set_comment(r,L"PSP_SELECTION_BLOCK");
 case 7u:return xx_data_struct_record_set_comment(r,L"PSP_ALPHA_BANK_BLOCK");
 case 8u:return xx_data_struct_record_set_comment(r,L"PSP_ALPHA_CHANNEL_BLOCK");
 case 9u:return xx_data_struct_record_set_comment(r,L"PSP_COMPOSITE_IMAGE_BLOCK");
 case 10u:return xx_data_struct_record_set_comment(r,L"PSP_EXTENDED_DATA_BLOCK");
 default:break;}}
 if(id==1613889591u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PSP_COMP_NONE");
 case 1u:return xx_data_struct_record_set_comment(r,L"PSP_COMP_RLE");
 case 2u:return xx_data_struct_record_set_comment(r,L"PSP_COMP_LZ77");
 case 3u:return xx_data_struct_record_set_comment(r,L"PSP_COMP_JPEG");
 default:break;}}
 if(id==1613889591u&&!xx_rt_wcscmp(r->name,L"resolution_unit")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"UNDEFINED");
 case 1u:return xx_data_struct_record_set_comment(r,L"INCHES");
 case 2u:return xx_data_struct_record_set_comment(r,L"CENTIMETERS");
 default:break;}}
 if(id==1613889592u&&!xx_rt_wcscmp(r->name,L"layer_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"NORMAL_RASTER");
 case 1u:return xx_data_struct_record_set_comment(r,L"FLOATING_SELECTION");
 case 2u:return xx_data_struct_record_set_comment(r,L"VECTOR");
 default:break;}}
 if(id==1613889595u&&!xx_rt_wcscmp(r->name,L"image_mode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"GRAYSCALE");
 case 2u:return xx_data_struct_record_set_comment(r,L"INDEXED");
 case 3u:return xx_data_struct_record_set_comment(r,L"RGB");
 default:break;}}
 if(id==1613889603u&&!xx_rt_wcscmp(r->name,L"begin_opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 30u:return xx_data_struct_record_set_comment(r,L"PdcBegin");
 default:break;}}
 if(id==1613889604u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PdcNOP");
 case 1u:return xx_data_struct_record_set_comment(r,L"PdcDrawPoint");
 case 4u:return xx_data_struct_record_set_comment(r,L"PdcDrawLine");
 case 5u:return xx_data_struct_record_set_comment(r,L"PdcDrawRect");
 case 6u:return xx_data_struct_record_set_comment(r,L"PdcDrawRoundRect");
 case 7u:return xx_data_struct_record_set_comment(r,L"PdcDrawEllipse");
 case 8u:return xx_data_struct_record_set_comment(r,L"PdcDrawArc");
 case 9u:return xx_data_struct_record_set_comment(r,L"PdcDrawPie");
 case 10u:return xx_data_struct_record_set_comment(r,L"PdcDrawChord");
 case 12u:return xx_data_struct_record_set_comment(r,L"PdcDrawPolyline");
 case 13u:return xx_data_struct_record_set_comment(r,L"PdcDrawPolygon");
 case 31u:return xx_data_struct_record_set_comment(r,L"PdcEnd");
 case 32u:return xx_data_struct_record_set_comment(r,L"PdcSave");
 case 33u:return xx_data_struct_record_set_comment(r,L"PdcRestore");
 case 41u:return xx_data_struct_record_set_comment(r,L"PdcSetBkMode");
 case 42u:return xx_data_struct_record_set_comment(r,L"PdcSetROP");
 case 63u:return xx_data_struct_record_set_comment(r,L"PdcSetRenderHint");
 case 64u:return xx_data_struct_record_set_comment(r,L"PdcSetCompositionMode");
 case 65u:return xx_data_struct_record_set_comment(r,L"PdcSetClipEnabled");
 case 66u:return xx_data_struct_record_set_comment(r,L"PdcSetOpacity");
 default:break;}}
 if(id==1613889605u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PdcNOP");
 case 1u:return xx_data_struct_record_set_comment(r,L"PdcDrawPoint");
 case 4u:return xx_data_struct_record_set_comment(r,L"PdcDrawLine");
 case 5u:return xx_data_struct_record_set_comment(r,L"PdcDrawRect");
 case 6u:return xx_data_struct_record_set_comment(r,L"PdcDrawRoundRect");
 case 7u:return xx_data_struct_record_set_comment(r,L"PdcDrawEllipse");
 case 8u:return xx_data_struct_record_set_comment(r,L"PdcDrawArc");
 case 9u:return xx_data_struct_record_set_comment(r,L"PdcDrawPie");
 case 10u:return xx_data_struct_record_set_comment(r,L"PdcDrawChord");
 case 12u:return xx_data_struct_record_set_comment(r,L"PdcDrawPolyline");
 case 13u:return xx_data_struct_record_set_comment(r,L"PdcDrawPolygon");
 case 31u:return xx_data_struct_record_set_comment(r,L"PdcEnd");
 case 32u:return xx_data_struct_record_set_comment(r,L"PdcSave");
 case 33u:return xx_data_struct_record_set_comment(r,L"PdcRestore");
 case 41u:return xx_data_struct_record_set_comment(r,L"PdcSetBkMode");
 case 42u:return xx_data_struct_record_set_comment(r,L"PdcSetROP");
 case 63u:return xx_data_struct_record_set_comment(r,L"PdcSetRenderHint");
 case 64u:return xx_data_struct_record_set_comment(r,L"PdcSetCompositionMode");
 case 65u:return xx_data_struct_record_set_comment(r,L"PdcSetClipEnabled");
 case 66u:return xx_data_struct_record_set_comment(r,L"PdcSetOpacity");
 default:break;}}
 if(id==1613889612u&&!xx_rt_wcscmp(r->name,L"fill_rule")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"OddEvenFill");
 case 1u:return xx_data_struct_record_set_comment(r,L"WindingFill");
 default:break;}}
 if(id==1613889616u&&!xx_rt_wcscmp(r->name,L"enabled")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"FALSE");
 case 1u:return xx_data_struct_record_set_comment(r,L"TRUE");
 default:break;}}
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"object_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"WBDISK");
 case 2u:return xx_data_struct_record_set_comment(r,L"WBDRAWER");
 case 3u:return xx_data_struct_record_set_comment(r,L"WBTOOL");
 case 4u:return xx_data_struct_record_set_comment(r,L"WBPROJECT");
 case 5u:return xx_data_struct_record_set_comment(r,L"WBGARBAGE");
 case 6u:return xx_data_struct_record_set_comment(r,L"WBDEVICE");
 case 7u:return xx_data_struct_record_set_comment(r,L"WBKICK");
 case 8u:return xx_data_struct_record_set_comment(r,L"WBAPPICON");
 default:break;}}
 if(id==1613889625u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"Clip");
 case 154u:return xx_data_struct_record_set_comment(r,L"DirectBitsRect");
 case 255u:return xx_data_struct_record_set_comment(r,L"EndPic");
 default:break;}}
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"Clip");
 case 154u:return xx_data_struct_record_set_comment(r,L"DirectBitsRect");
 case 255u:return xx_data_struct_record_set_comment(r,L"EndPic");
 default:break;}}
 if(id==1613889629u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"Clip");
 case 154u:return xx_data_struct_record_set_comment(r,L"DirectBitsRect");
 case 255u:return xx_data_struct_record_set_comment(r,L"EndPic");
 default:break;}}
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"pack_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 4u:return xx_data_struct_record_set_comment(r,L"COMPONENT_PACKBITS");
 default:break;}}
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"transfer_mode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 64u:return xx_data_struct_record_set_comment(r,L"ditherCopy");
 default:break;}}
 if(id==1613889639u&&!xx_rt_wcscmp(r->name,L"image_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"RGB");
 case 1u:return xx_data_struct_record_set_comment(r,L"GRAY");
 case 2u:return xx_data_struct_record_set_comment(r,L"INDEXED");
 default:break;}}
 if(id==1613889652u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"RLE");
 case 2u:return xx_data_struct_record_set_comment(r,L"ZLIB");
 case 3u:return xx_data_struct_record_set_comment(r,L"FRACTAL");
 default:break;}}
 if(id==1613889640u&&!xx_rt_wcscmp(r->name,L"property_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PROP_END");
 case 1u:return xx_data_struct_record_set_comment(r,L"PROP_COLORMAP");
 case 6u:return xx_data_struct_record_set_comment(r,L"PROP_OPACITY");
 case 7u:return xx_data_struct_record_set_comment(r,L"PROP_MODE");
 case 8u:return xx_data_struct_record_set_comment(r,L"PROP_VISIBLE");
 case 9u:return xx_data_struct_record_set_comment(r,L"PROP_LINKED");
 case 10u:return xx_data_struct_record_set_comment(r,L"PROP_LOCK_ALPHA");
 case 11u:return xx_data_struct_record_set_comment(r,L"PROP_APPLY_MASK");
 case 12u:return xx_data_struct_record_set_comment(r,L"PROP_EDIT_MASK");
 case 13u:return xx_data_struct_record_set_comment(r,L"PROP_SHOW_MASK");
 case 14u:return xx_data_struct_record_set_comment(r,L"PROP_SHOW_MASKED");
 case 15u:return xx_data_struct_record_set_comment(r,L"PROP_OFFSETS");
 case 16u:return xx_data_struct_record_set_comment(r,L"PROP_COLOR");
 case 17u:return xx_data_struct_record_set_comment(r,L"PROP_COMPRESSION");
 case 18u:return xx_data_struct_record_set_comment(r,L"PROP_GUIDES");
 case 19u:return xx_data_struct_record_set_comment(r,L"PROP_RESOLUTION");
 case 20u:return xx_data_struct_record_set_comment(r,L"PROP_TATTOO");
 case 21u:return xx_data_struct_record_set_comment(r,L"PROP_PARASITES");
 case 22u:return xx_data_struct_record_set_comment(r,L"PROP_UNIT");
 case 27u:return xx_data_struct_record_set_comment(r,L"PROP_SAMPLE_POINTS");
 default:break;}}
 if(id==1613889689u&&!xx_rt_wcscmp(r->name,L"image_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"ICON");
 case 2u:return xx_data_struct_record_set_comment(r,L"CURSOR");
 default:break;}}
 if(id==1613889696u&&!xx_rt_wcscmp(r->name,L"coding_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 27u:return xx_data_struct_record_set_comment(r,L"AVC");
 case 2u:return xx_data_struct_record_set_comment(r,L"MPEG2_VIDEO");
 case 220u:return xx_data_struct_record_set_comment(r,L"ATRAC3PLUS");
 case 128u:return xx_data_struct_record_set_comment(r,L"LPCM");
 case 129u:return xx_data_struct_record_set_comment(r,L"AC3");
 case 221u:return xx_data_struct_record_set_comment(r,L"USER_DATA");
 default:break;}}
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"payload_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STREAM");
 case 1u:return xx_data_struct_record_set_comment(r,L"HEADER");
 case 2u:return xx_data_struct_record_set_comment(r,L"SECTION_END");
 case 3u:return xx_data_struct_record_set_comment(r,L"METADATA");
 default:break;}}
 if(id==1613889719u&&!xx_rt_wcscmp(r->name,L"chunk_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"INIT_AUDIO");
 case 1u:return xx_data_struct_record_set_comment(r,L"AUDIO_ONLY");
 case 2u:return xx_data_struct_record_set_comment(r,L"INIT_VIDEO");
 case 3u:return xx_data_struct_record_set_comment(r,L"VIDEO");
 case 4u:return xx_data_struct_record_set_comment(r,L"SHUTDOWN");
 case 5u:return xx_data_struct_record_set_comment(r,L"END");
 default:break;}}
 if(id==1613889720u&&!xx_rt_wcscmp(r->name,L"opcode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"END_OF_STREAM");
 case 1u:return xx_data_struct_record_set_comment(r,L"END_OF_CHUNK");
 case 2u:return xx_data_struct_record_set_comment(r,L"CREATE_TIMER");
 case 3u:return xx_data_struct_record_set_comment(r,L"INIT_AUDIO");
 case 4u:return xx_data_struct_record_set_comment(r,L"START_STOP_AUDIO");
 case 5u:return xx_data_struct_record_set_comment(r,L"INIT_VIDEO");
 case 6u:return xx_data_struct_record_set_comment(r,L"VIDEO_DATA_06");
 case 7u:return xx_data_struct_record_set_comment(r,L"SEND_BUFFER");
 case 8u:return xx_data_struct_record_set_comment(r,L"AUDIO_FRAME");
 case 9u:return xx_data_struct_record_set_comment(r,L"AUDIO_SILENCE");
 case 10u:return xx_data_struct_record_set_comment(r,L"SET_VIDEO_MODE");
 case 12u:return xx_data_struct_record_set_comment(r,L"SET_PALETTE");
 case 15u:return xx_data_struct_record_set_comment(r,L"SET_DECODING_MAP");
 case 16u:return xx_data_struct_record_set_comment(r,L"VIDEO_DATA_10");
 case 17u:return xx_data_struct_record_set_comment(r,L"VIDEO_DATA_11");
 default:break;}}
 if(id==1613889739u&&!xx_rt_wcscmp(r->name,L"color_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"GRAYSCALE");
 case 2u:return xx_data_struct_record_set_comment(r,L"TRUECOLOR");
 case 3u:return xx_data_struct_record_set_comment(r,L"INDEXED_COLOR");
 case 4u:return xx_data_struct_record_set_comment(r,L"GRAYSCALE_ALPHA");
 case 6u:return xx_data_struct_record_set_comment(r,L"TRUECOLOR_ALPHA");
 default:break;}}
 if(id==1613889739u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"DEFLATE");
 default:break;}}
 if(id==1613889739u&&!xx_rt_wcscmp(r->name,L"interlace")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"NONE");
 case 1u:return xx_data_struct_record_set_comment(r,L"ADAM7");
 default:break;}}
 if(id==1613889746u&&!xx_rt_wcscmp(r->name,L"rendering_intent")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PERCEPTUAL");
 case 1u:return xx_data_struct_record_set_comment(r,L"RELATIVE_COLORIMETRIC");
 case 2u:return xx_data_struct_record_set_comment(r,L"SATURATION");
 case 3u:return xx_data_struct_record_set_comment(r,L"ABSOLUTE_COLORIMETRIC");
 default:break;}}
 if(id==1613889747u&&!xx_rt_wcscmp(r->name,L"unit")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"UNSPECIFIED");
 case 1u:return xx_data_struct_record_set_comment(r,L"METERS");
 default:break;}}
 if(id==1613889756u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"ZLIB");
 case 3u:return xx_data_struct_record_set_comment(r,L"ZLIB_XOR_PREVIOUS");
 default:break;}}
 if(id==1613889795u&&!xx_rt_wcscmp(r->name,L"table_id")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PAT");
 case 2u:return xx_data_struct_record_set_comment(r,L"PMT");
 case 66u:return xx_data_struct_record_set_comment(r,L"SDT_ACTUAL");
 case 70u:return xx_data_struct_record_set_comment(r,L"SDT_OTHER");
 default:break;}}
 if(id==1613889798u&&!xx_rt_wcscmp(r->name,L"stream_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"MPEG1_VIDEO");
 case 2u:return xx_data_struct_record_set_comment(r,L"MPEG2_VIDEO");
 case 3u:return xx_data_struct_record_set_comment(r,L"MPEG1_AUDIO");
 case 4u:return xx_data_struct_record_set_comment(r,L"MPEG2_AUDIO");
 case 6u:return xx_data_struct_record_set_comment(r,L"PRIVATE_DATA");
 case 15u:return xx_data_struct_record_set_comment(r,L"AAC_ADTS");
 case 16u:return xx_data_struct_record_set_comment(r,L"MPEG4_VIDEO");
 case 17u:return xx_data_struct_record_set_comment(r,L"AAC_LATM");
 case 27u:return xx_data_struct_record_set_comment(r,L"H264_AVC");
 case 36u:return xx_data_struct_record_set_comment(r,L"H265_HEVC");
 case 129u:return xx_data_struct_record_set_comment(r,L"AC3");
 default:break;}}
 if(id==1613889786u&&!xx_rt_wcscmp(r->name,L"stream_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"MPEG1_VIDEO");
 case 2u:return xx_data_struct_record_set_comment(r,L"MPEG2_VIDEO");
 case 3u:return xx_data_struct_record_set_comment(r,L"MPEG1_AUDIO");
 case 4u:return xx_data_struct_record_set_comment(r,L"MPEG2_AUDIO");
 case 6u:return xx_data_struct_record_set_comment(r,L"PRIVATE_DATA");
 case 15u:return xx_data_struct_record_set_comment(r,L"AAC_ADTS");
 case 16u:return xx_data_struct_record_set_comment(r,L"MPEG4_VIDEO");
 case 17u:return xx_data_struct_record_set_comment(r,L"AAC_LATM");
 case 27u:return xx_data_struct_record_set_comment(r,L"H264_AVC");
 case 36u:return xx_data_struct_record_set_comment(r,L"H265_HEVC");
 case 129u:return xx_data_struct_record_set_comment(r,L"AC3");
 default:break;}}
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"frame_left"))return xx_data_struct_record_set_comment(r,L"Frame coordinate in 0.01 millimeter units");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"frame_top"))return xx_data_struct_record_set_comment(r,L"Frame coordinate in 0.01 millimeter units");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"frame_right"))return xx_data_struct_record_set_comment(r,L"Frame coordinate in 0.01 millimeter units");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"frame_bottom"))return xx_data_struct_record_set_comment(r,L"Frame coordinate in 0.01 millimeter units");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"device_width"))return xx_data_struct_record_set_comment(r,L"Reference device size in pixels");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"device_height"))return xx_data_struct_record_set_comment(r,L"Reference device size in pixels");
 if(id==1613889544u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889547u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889548u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889551u&&!xx_rt_wcscmp(r->name,L"header_words"))return xx_data_struct_record_set_comment(r,L"Count of 16-bit words; multiply by 2 for bytes");
 if(id==1613889551u&&!xx_rt_wcscmp(r->name,L"file_words"))return xx_data_struct_record_set_comment(r,L"Count of 16-bit words; multiply by 2 for bytes");
 if(id==1613889551u&&!xx_rt_wcscmp(r->name,L"maximum_record_words"))return xx_data_struct_record_set_comment(r,L"Count of 16-bit words; multiply by 2 for bytes");
 if(id==1613889552u&&!xx_rt_wcscmp(r->name,L"record_words"))return xx_data_struct_record_set_comment(r,L"Count of 16-bit words; multiply by 2 for bytes");
 if(id==1613889560u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889561u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889562u&&!xx_rt_wcscmp(r->name,L"color_ref"))return xx_data_struct_record_set_comment(r,L"COLORREF packed as 0x00BBGGRR");
 if(id==1613889568u&&!xx_rt_wcscmp(r->name,L"next_bitmap_words"))return xx_data_struct_record_set_comment(r,L"Bitmap-relative offset in 32-bit words; multiply by 4 for bytes");
 if(id==1613889574u&&!xx_rt_wcscmp(r->name,L"x_bits_per_pixel_vax"))return xx_data_struct_record_set_comment(r,L"Original DEC VAX floating-point bytes; not IEEE decoded");
 if(id==1613889574u&&!xx_rt_wcscmp(r->name,L"y_bits_per_pixel_vax"))return xx_data_struct_record_set_comment(r,L"Original DEC VAX floating-point bytes; not IEEE decoded");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"next_gadget"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"gadget_render"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"select_render"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"gadget_text"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"special_info"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"user_data"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"default_tool"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"tool_types"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"drawer_data"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889618u&&!xx_rt_wcscmp(r->name,L"tool_window"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"first_gadget"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"check_mark"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"title"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"screen"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889619u&&!xx_rt_wcscmp(r->name,L"bitmap"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889620u&&!xx_rt_wcscmp(r->name,L"image_data"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889620u&&!xx_rt_wcscmp(r->name,L"next_image"))return xx_data_struct_record_set_comment(r,L"Serialized pointer or presence marker; not a file offset");
 if(id==1613889624u&&!xx_rt_wcscmp(r->name,L"horizontal_resolution_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889624u&&!xx_rt_wcscmp(r->name,L"vertical_resolution_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"horizontal_resolution_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"vertical_resolution_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889630u&&!xx_rt_wcscmp(r->name,L"first_sprite_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the omitted area-size word, 4 bytes before the file");
 if(id==1613889630u&&!xx_rt_wcscmp(r->name,L"free_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the omitted area-size word, 4 bytes before the file");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"next_sprite_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the current sprite header");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"image_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the current sprite header");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"mask_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the current sprite header");
 if(id==1613889686u&&!xx_rt_wcscmp(r->name,L"display_rate_jiffies"))return xx_data_struct_record_set_comment(r,L"Duration in 1/60-second jiffies");
 if(id==1613889687u&&!xx_rt_wcscmp(r->name,L"duration_jiffies"))return xx_data_struct_record_set_comment(r,L"Duration in 1/60-second jiffies");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"start_pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"start_pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"end_pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"end_pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889694u&&!xx_rt_wcscmp(r->name,L"start_pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889694u&&!xx_rt_wcscmp(r->name,L"start_pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889694u&&!xx_rt_wcscmp(r->name,L"end_pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889694u&&!xx_rt_wcscmp(r->name,L"end_pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889697u&&!xx_rt_wcscmp(r->name,L"width_16pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 16-pixel units");
 if(id==1613889697u&&!xx_rt_wcscmp(r->name,L"height_16pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 16-pixel units");
 if(id==1613889698u&&!xx_rt_wcscmp(r->name,L"width_16pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 16-pixel units");
 if(id==1613889698u&&!xx_rt_wcscmp(r->name,L"height_16pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 16-pixel units");
 if(id==1613889701u&&!xx_rt_wcscmp(r->name,L"pts_high"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889701u&&!xx_rt_wcscmp(r->name,L"pts_low"))return xx_data_struct_record_set_comment(r,L"Split 90 kHz presentation timestamp; combine high and low words");
 if(id==1613889703u&&!xx_rt_wcscmp(r->name,L"rows_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the UTF table base plus 8");
 if(id==1613889703u&&!xx_rt_wcscmp(r->name,L"strings_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the UTF table base plus 8");
 if(id==1613889703u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the UTF table base plus 8");
 if(id==1613889703u&&!xx_rt_wcscmp(r->name,L"table_name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool");
 if(id==1613889704u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool");
 if(id==1613889715u&&!xx_rt_wcscmp(r->name,L"string_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool");
 if(id==1613889716u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF data pool");
 if(id==1613889723u&&!xx_rt_wcscmp(r->name,L"width_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889723u&&!xx_rt_wcscmp(r->name,L"height_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889724u&&!xx_rt_wcscmp(r->name,L"width_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889724u&&!xx_rt_wcscmp(r->name,L"height_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889725u&&!xx_rt_wcscmp(r->name,L"width_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889725u&&!xx_rt_wcscmp(r->name,L"height_8pixels"))return xx_data_struct_record_set_comment(r,L"Encoded dimension in 8-pixel units");
 if(id==1613889744u&&!xx_rt_wcscmp(r->name,L"gamma_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"white_x_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"white_y_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"red_x_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"red_y_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"green_x_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"green_y_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"blue_x_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889745u&&!xx_rt_wcscmp(r->name,L"blue_y_100000"))return xx_data_struct_record_set_comment(r,L"Fixed-point value scaled by 100000");
 if(id==1613889759u&&!xx_rt_wcscmp(r->name,L"duration_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889759u&&!xx_rt_wcscmp(r->name,L"preroll_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889764u&&!xx_rt_wcscmp(r->name,L"start_time_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889764u&&!xx_rt_wcscmp(r->name,L"preroll_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889764u&&!xx_rt_wcscmp(r->name,L"duration_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889768u&&!xx_rt_wcscmp(r->name,L"frame_rate_fixed"))return xx_data_struct_record_set_comment(r,L"Unsigned 16.16 fixed-point value");
 if(id==1613889771u&&!xx_rt_wcscmp(r->name,L"timestamp_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889773u&&!xx_rt_wcscmp(r->name,L"timestamp_ms"))return xx_data_struct_record_set_comment(r,L"Stream-relative time in milliseconds");
 if(id==1613889775u&&!xx_rt_wcscmp(r->name,L"scr_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889775u&&!xx_rt_wcscmp(r->name,L"mux_rate_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889776u&&!xx_rt_wcscmp(r->name,L"scr_base_extension_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889776u&&!xx_rt_wcscmp(r->name,L"mux_rate_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889778u&&!xx_rt_wcscmp(r->name,L"timestamp_flags"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889779u&&!xx_rt_wcscmp(r->name,L"tag_high_and_marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889779u&&!xx_rt_wcscmp(r->name,L"middle_and_marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889779u&&!xx_rt_wcscmp(r->name,L"low_and_marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889781u&&!xx_rt_wcscmp(r->name,L"marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889782u&&!xx_rt_wcscmp(r->name,L"rate_bound_marker_bits"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889782u&&!xx_rt_wcscmp(r->name,L"audio_bound_flags"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889782u&&!xx_rt_wcscmp(r->name,L"video_bound_flags"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889784u&&!xx_rt_wcscmp(r->name,L"reserved_marker"))return xx_data_struct_record_set_comment(r,L"Packed MPEG field; marker, reserved and data bits preserved");
 if(id==1613889788u&&!xx_rt_wcscmp(r->name,L"flags_pid"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889788u&&!xx_rt_wcscmp(r->name,L"scrambling_adaptation_counter"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889790u&&!xx_rt_wcscmp(r->name,L"flags"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889791u&&!xx_rt_wcscmp(r->name,L"base_low_reserved_extension_high"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889795u&&!xx_rt_wcscmp(r->name,L"flags_section_length"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889795u&&!xx_rt_wcscmp(r->name,L"version_current_next"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889796u&&!xx_rt_wcscmp(r->name,L"reserved_pid"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889797u&&!xx_rt_wcscmp(r->name,L"reserved_pcr_pid"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889797u&&!xx_rt_wcscmp(r->name,L"reserved_program_info_length"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889798u&&!xx_rt_wcscmp(r->name,L"reserved_elementary_pid"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889798u&&!xx_rt_wcscmp(r->name,L"reserved_info_length"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889800u&&!xx_rt_wcscmp(r->name,L"eit_flags"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889800u&&!xx_rt_wcscmp(r->name,L"running_free_ca_descriptor_length"))return xx_data_struct_record_set_comment(r,L"Packed transport field; flags, reserved bits and encoded values preserved");
 if(id==1613889549u&&!xx_rt_wcscmp(r->name,L"palette_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this EMR_EOF record");
 if(id==1613889537u&&!xx_rt_wcscmp(r->name,L"description_chars"))return xx_data_struct_record_set_comment(r,L"UTF-16 code units, including terminators");
 if(id==1613889550u&&!xx_rt_wcscmp(r->name,L"units_per_inch"))return xx_data_struct_record_set_comment(r,L"Metafile coordinate units per inch");
 if(id==1613889610u&&!xx_rt_wcscmp(r->name,L"start_angle"))return xx_data_struct_record_set_comment(r,L"Angle in 1/16 degree units");
 if(id==1613889610u&&!xx_rt_wcscmp(r->name,L"span_angle"))return xx_data_struct_record_set_comment(r,L"Angle in 1/16 degree units");
 if(id==1613889609u&&!xx_rt_wcscmp(r->name,L"x_rounding"))return xx_data_struct_record_set_comment(r,L"Horizontal rounding percentage");
 if(id==1613889609u&&!xx_rt_wcscmp(r->name,L"y_rounding"))return xx_data_struct_record_set_comment(r,L"Vertical rounding percentage");
 if(id==1613889622u&&!xx_rt_wcscmp(r->name,L"pointer_array_bytes"))return xx_data_struct_record_set_comment(r,L"Serialized pointer-array byte size, including its terminating null pointer");
 if(id==1613889624u&&!xx_rt_wcscmp(r->name,L"picture_size"))return xx_data_struct_record_set_comment(r,L"Legacy informational size; may be zero for PICT v2");
 if(id==1613889626u&&!xx_rt_wcscmp(r->name,L"row_bytes_and_flag"))return xx_data_struct_record_set_comment(r,L"Bit 15 marks PixMap; bits 0..14 are bytes per decoded row");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"width_words_minus_one"))return xx_data_struct_record_set_comment(r,L"Words per image row minus one; each word is 32 bits");
 if(id==1613889631u&&!xx_rt_wcscmp(r->name,L"height_minus_one"))return xx_data_struct_record_set_comment(r,L"Image rows minus one");
 if(id==1613889632u&&!xx_rt_wcscmp(r->name,L"color1"))return xx_data_struct_record_set_comment(r,L"First flashing palette color, packed as 0xBBGGRR00");
 if(id==1613889632u&&!xx_rt_wcscmp(r->name,L"color2"))return xx_data_struct_record_set_comment(r,L"Second flashing palette color, packed as 0xBBGGRR00");
 if(id==1613889692u&&!xx_rt_wcscmp(r->name,L"header_blocks"))return xx_data_struct_record_set_comment(r,L"Count of 2048-byte blocks");
 if(id==1613889692u&&!xx_rt_wcscmp(r->name,L"data_blocks"))return xx_data_struct_record_set_comment(r,L"Count of 2048-byte blocks");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"mux_rate_bound"))return xx_data_struct_record_set_comment(r,L"Rate in units of 50 bytes per second");
 if(id==1613889693u&&!xx_rt_wcscmp(r->name,L"std_delay_bound"))return xx_data_struct_record_set_comment(r,L"Delay in 1/90000-second units");
 if(id==1613889701u&&!xx_rt_wcscmp(r->name,L"relative_packet_blocks"))return xx_data_struct_record_set_comment(r,L"Data-relative packet position in 2048-byte blocks");
 if(id==1613889701u&&!xx_rt_wcscmp(r->name,L"index_reference_picture_blocks"))return xx_data_struct_record_set_comment(r,L"Packed entry index and reference-picture size in 2048-byte blocks");
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"payload_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from this chunk base plus 8");
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"data_size"))return xx_data_struct_record_set_comment(r,L"Chunk bytes excluding its first 8 bytes");
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"frame_time"))return xx_data_struct_record_set_comment(r,L"Frame time in the accompanying stream frame-rate units");
 if(id==1613889702u&&!xx_rt_wcscmp(r->name,L"frame_rate"))return xx_data_struct_record_set_comment(r,L"Stream frame-rate value");
 if(id==1613889721u&&!xx_rt_wcscmp(r->name,L"microsecond_rate"))return xx_data_struct_record_set_comment(r,L"Frame duration is this microsecond rate multiplied by rate_divisor");
 if(id==1613889721u&&!xx_rt_wcscmp(r->name,L"rate_divisor"))return xx_data_struct_record_set_comment(r,L"Multiplicative factor used with microsecond_rate");
 if(id==1613889733u&&!xx_rt_wcscmp(r->name,L"word_offset_and_flags"))return xx_data_struct_record_set_comment(r,L"Low 30 bits hold the offset in 16-bit words; top two bits are flags");
 if(id==1613889738u&&!xx_rt_wcscmp(r->name,L"nominal_play_time_ticks"))return xx_data_struct_record_set_comment(r,L"Duration in ticks at ticks_per_second");
 if(id==1613889752u&&!xx_rt_wcscmp(r->name,L"frame_duration"))return xx_data_struct_record_set_comment(r,L"Positive: milliseconds; negative: magnitude in 1/100000 second units; zero: 10 fps");
 if(id==1613889791u&&!xx_rt_wcscmp(r->name,L"base_high"))return xx_data_struct_record_set_comment(r,L"Upper 32 bits of the 33-bit 90 kHz clock base");
 if(id==1613889791u&&!xx_rt_wcscmp(r->name,L"extension_low"))return xx_data_struct_record_set_comment(r,L"Low 8 bits of the 9-bit 27 MHz clock extension");
 if(id==1613889794u&&!xx_rt_wcscmp(r->name,L"pointer_bytes"))return xx_data_struct_record_set_comment(r,L"Bytes to skip before the next PSI section");
 if(id==1613889586u&&!xx_rt_wcscmp(r->name,L"end_index"))return xx_data_struct_record_set_comment(r,L"Exclusive ending palette index");
 return true;
}
