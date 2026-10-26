/* SPDX-License-Identifier: MIT
 * Scientific file metadata. Scope: docs/data_struct_sciencemeta_scope.txt. */
static const xx_data_struct_field_desc sxsc_mrc_header_le_fields[] = {
    SX_FIELD("nx","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("ny","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("nz","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("mode","int32",12,4,SX_ID),
    SX_FIELD("nxstart","int32",16,4,SX_NONE),
    SX_FIELD("nystart","int32",20,4,SX_NONE),
    SX_FIELD("nzstart","int32",24,4,SX_NONE),
    SX_FIELD("mx","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("my","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("mz","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("cella_x","float32",40,4,SX_NONE),
    SX_FIELD("cella_y","float32",44,4,SX_NONE),
    SX_FIELD("cella_z","float32",48,4,SX_NONE),
    SX_FIELD("cellb_alpha","float32",52,4,SX_NONE),
    SX_FIELD("cellb_beta","float32",56,4,SX_NONE),
    SX_FIELD("cellb_gamma","float32",60,4,SX_NONE),
    SX_FIELD("mapc","int32",64,4,SX_ID),
    SX_FIELD("mapr","int32",68,4,SX_ID),
    SX_FIELD("maps","int32",72,4,SX_ID),
    SX_FIELD("dmin","float32",76,4,SX_NONE),
    SX_FIELD("dmax","float32",80,4,SX_NONE),
    SX_FIELD("dmean","float32",84,4,SX_NONE),
    SX_FIELD("ispg","int32",88,4,SX_ID),
    SX_FIELD("nsymbt","int32",92,4,SX_SIZE),
    SX_FIELD("extra1","uint8[8]",96,8,SX_NONE),
    SX_FIELD("exttyp","char[4]",104,4,SX_ID),
    SX_FIELD("nversion","int32",108,4,SX_ID),
    SX_FIELD("extra2","uint8[84]",112,84,SX_NONE),
    SX_FIELD("origin_x","float32",196,4,SX_NONE),
    SX_FIELD("origin_y","float32",200,4,SX_NONE),
    SX_FIELD("origin_z","float32",204,4,SX_NONE),
    SX_FIELD("map","char[4]",208,4,SX_SIGNATURE),
    SX_FIELD("machst","uint8[4]",212,4,SX_ID),
    SX_FIELD("rms","float32",216,4,SX_NONE),
    SX_FIELD("nlabl","int32",220,4,SX_COUNT_PROP),
};
static const sx_layout sxsc_mrc_header_le = {UINT32_C(0x60280001),"mrc_header_le",sxsc_mrc_header_le_fields,SX_COUNT(sxsc_mrc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_mrc_header_be_fields[] = {
    SX_FIELD("nx","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("ny","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("nz","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("mode","int32",12,4,SX_ID),
    SX_FIELD("nxstart","int32",16,4,SX_NONE),
    SX_FIELD("nystart","int32",20,4,SX_NONE),
    SX_FIELD("nzstart","int32",24,4,SX_NONE),
    SX_FIELD("mx","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("my","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("mz","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("cella_x","float32",40,4,SX_NONE),
    SX_FIELD("cella_y","float32",44,4,SX_NONE),
    SX_FIELD("cella_z","float32",48,4,SX_NONE),
    SX_FIELD("cellb_alpha","float32",52,4,SX_NONE),
    SX_FIELD("cellb_beta","float32",56,4,SX_NONE),
    SX_FIELD("cellb_gamma","float32",60,4,SX_NONE),
    SX_FIELD("mapc","int32",64,4,SX_ID),
    SX_FIELD("mapr","int32",68,4,SX_ID),
    SX_FIELD("maps","int32",72,4,SX_ID),
    SX_FIELD("dmin","float32",76,4,SX_NONE),
    SX_FIELD("dmax","float32",80,4,SX_NONE),
    SX_FIELD("dmean","float32",84,4,SX_NONE),
    SX_FIELD("ispg","int32",88,4,SX_ID),
    SX_FIELD("nsymbt","int32",92,4,SX_SIZE),
    SX_FIELD("extra1","uint8[8]",96,8,SX_NONE),
    SX_FIELD("exttyp","char[4]",104,4,SX_ID),
    SX_FIELD("nversion","int32",108,4,SX_ID),
    SX_FIELD("extra2","uint8[84]",112,84,SX_NONE),
    SX_FIELD("origin_x","float32",196,4,SX_NONE),
    SX_FIELD("origin_y","float32",200,4,SX_NONE),
    SX_FIELD("origin_z","float32",204,4,SX_NONE),
    SX_FIELD("map","char[4]",208,4,SX_SIGNATURE),
    SX_FIELD("machst","uint8[4]",212,4,SX_ID),
    SX_FIELD("rms","float32",216,4,SX_NONE),
    SX_FIELD("nlabl","int32",220,4,SX_COUNT_PROP),
};
static const sx_layout sxsc_mrc_header_be = {UINT32_C(0x60280002),"mrc_header_be",sxsc_mrc_header_be_fields,SX_COUNT(sxsc_mrc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_mrc_label_fields[] = {
    SX_FIELD("label","char[80]",0,80,SX_STRING),
};
static const sx_layout sxsc_mrc_label = {UINT32_C(0x60280003),"mrc_label",sxsc_mrc_label_fields,SX_COUNT(sxsc_mrc_label_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_file_header_fields[] = {
    SX_FIELD("file_code","int32be",0,4,SX_SIGNATURE),
    SX_FIELD("unused","int32be[5]",4,20,SX_RESERVED),
    SX_FIELD("file_length_words","int32be",24,4,SX_NONE),
    SX_FIELD("version","int32le",28,4,SX_ID),
    SX_FIELD("shape_type","int32le",32,4,SX_ID),
    SX_FIELD("xmin","float64",36,8,SX_NONE),
    SX_FIELD("ymin","float64",44,8,SX_NONE),
    SX_FIELD("xmax","float64",52,8,SX_NONE),
    SX_FIELD("ymax","float64",60,8,SX_NONE),
    SX_FIELD("zmin","float64",68,8,SX_NONE),
    SX_FIELD("zmax","float64",76,8,SX_NONE),
    SX_FIELD("mmin","float64",84,8,SX_NONE),
    SX_FIELD("mmax","float64",92,8,SX_NONE),
};
static const sx_layout sxsc_shp_file_header = {UINT32_C(0x60280004),"shp_file_header",sxsc_shp_file_header_fields,SX_COUNT(sxsc_shp_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_record_header_fields[] = {
    SX_FIELD("record_number","int32be",0,4,SX_ID),
    SX_FIELD("content_length_words","int32be",4,4,SX_NONE),
};
static const sx_layout sxsc_shp_record_header = {UINT32_C(0x60280005),"shp_record_header",sxsc_shp_record_header_fields,SX_COUNT(sxsc_shp_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_shape_type_fields[] = {
    SX_FIELD("shape_type","int32",0,4,SX_ID),
};
static const sx_layout sxsc_shp_shape_type = {UINT32_C(0x60280006),"shp_shape_type",sxsc_shp_shape_type_fields,SX_COUNT(sxsc_shp_shape_type_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_point_fields[] = {
    SX_FIELD("shape_type","int32",0,4,SX_ID),
    SX_FIELD("x","float64",4,8,SX_NONE),
    SX_FIELD("y","float64",12,8,SX_NONE),
};
static const sx_layout sxsc_shp_point = {UINT32_C(0x60280007),"shp_point",sxsc_shp_point_fields,SX_COUNT(sxsc_shp_point_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_multipoint_fields[] = {
    SX_FIELD("shape_type","int32",0,4,SX_ID),
    SX_FIELD("xmin","float64",4,8,SX_NONE),
    SX_FIELD("ymin","float64",12,8,SX_NONE),
    SX_FIELD("xmax","float64",20,8,SX_NONE),
    SX_FIELD("ymax","float64",28,8,SX_NONE),
    SX_FIELD("point_count","int32",36,4,SX_COUNT_PROP),
};
static const sx_layout sxsc_shp_multipoint = {UINT32_C(0x60280008),"shp_multipoint",sxsc_shp_multipoint_fields,SX_COUNT(sxsc_shp_multipoint_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_polyline_polygon_fields[] = {
    SX_FIELD("shape_type","int32",0,4,SX_ID),
    SX_FIELD("xmin","float64",4,8,SX_NONE),
    SX_FIELD("ymin","float64",12,8,SX_NONE),
    SX_FIELD("xmax","float64",20,8,SX_NONE),
    SX_FIELD("ymax","float64",28,8,SX_NONE),
    SX_FIELD("part_count","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("point_count","int32",40,4,SX_COUNT_PROP),
};
static const sx_layout sxsc_shp_polyline_polygon = {UINT32_C(0x60280009),"shp_polyline_polygon",sxsc_shp_polyline_polygon_fields,SX_COUNT(sxsc_shp_polyline_polygon_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_part_fields[] = {
    SX_FIELD("first_point_index","int32",0,4,SX_ID),
};
static const sx_layout sxsc_shp_part = {UINT32_C(0x6028000a),"shp_part",sxsc_shp_part_fields,SX_COUNT(sxsc_shp_part_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_xy_fields[] = {
    SX_FIELD("x","float64",0,8,SX_NONE),
    SX_FIELD("y","float64",8,8,SX_NONE),
};
static const sx_layout sxsc_shp_xy = {UINT32_C(0x6028000b),"shp_xy",sxsc_shp_xy_fields,SX_COUNT(sxsc_shp_xy_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las12_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("file_source_id","uint16",4,2,SX_ID),
    SX_FIELD("global_encoding","uint16",6,2,SX_FLAGS),
    SX_FIELD("project_id1","uint32",8,4,SX_ID),
    SX_FIELD("project_id2","uint16",12,2,SX_ID),
    SX_FIELD("project_id3","uint16",14,2,SX_ID),
    SX_FIELD("project_id4","uint8[8]",16,8,SX_ID),
    SX_FIELD("version_major","uint8",24,1,SX_ID),
    SX_FIELD("version_minor","uint8",25,1,SX_ID),
    SX_FIELD("system_identifier","char[32]",26,32,SX_STRING),
    SX_FIELD("generating_software","char[32]",58,32,SX_STRING),
    SX_FIELD("creation_day","uint16",90,2,SX_NONE),
    SX_FIELD("creation_year","uint16",92,2,SX_NONE),
    SX_FIELD("header_size","uint16",94,2,SX_SIZE),
    SX_FIELD("point_data_offset","uint32",96,4,SX_OFFSET),
    SX_FIELD("variable_record_count","uint32",100,4,SX_COUNT_PROP),
    SX_FIELD("point_data_format","uint8",104,1,SX_ID),
    SX_FIELD("point_record_size","uint16",105,2,SX_SIZE),
    SX_FIELD("point_count","uint32",107,4,SX_COUNT_PROP),
    SX_FIELD("points_by_return","uint32[5]",111,20,SX_COUNT_PROP),
    SX_FIELD("x_scale","float64",131,8,SX_NONE),
    SX_FIELD("y_scale","float64",139,8,SX_NONE),
    SX_FIELD("z_scale","float64",147,8,SX_NONE),
    SX_FIELD("x_offset","float64",155,8,SX_NONE),
    SX_FIELD("y_offset","float64",163,8,SX_NONE),
    SX_FIELD("z_offset","float64",171,8,SX_NONE),
    SX_FIELD("xmax","float64",179,8,SX_NONE),
    SX_FIELD("xmin","float64",187,8,SX_NONE),
    SX_FIELD("ymax","float64",195,8,SX_NONE),
    SX_FIELD("ymin","float64",203,8,SX_NONE),
    SX_FIELD("zmax","float64",211,8,SX_NONE),
    SX_FIELD("zmin","float64",219,8,SX_NONE),
};
static const sx_layout sxsc_las12_header = {UINT32_C(0x6028000c),"las12_header",sxsc_las12_header_fields,SX_COUNT(sxsc_las12_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_vlr_fields[] = {
    SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
    SX_FIELD("user_id","char[16]",2,16,SX_STRING),
    SX_FIELD("record_id","uint16",18,2,SX_ID),
    SX_FIELD("payload_size","uint16",20,2,SX_SIZE),
    SX_FIELD("description","char[32]",22,32,SX_STRING),
};
static const sx_layout sxsc_las_vlr = {UINT32_C(0x6028000d),"las_vlr",sxsc_las_vlr_fields,SX_COUNT(sxsc_las_vlr_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_point0_fields[] = {
    SX_FIELD("x","int32",0,4,SX_NONE),
    SX_FIELD("y","int32",4,4,SX_NONE),
    SX_FIELD("z","int32",8,4,SX_NONE),
    SX_FIELD("intensity","uint16",12,2,SX_NONE),
    SX_FIELD("return_flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("classification","uint8",15,1,SX_FLAGS),
    SX_FIELD("scan_angle_rank","int8",16,1,SX_NONE),
    SX_FIELD("user_data","uint8",17,1,SX_NONE),
    SX_FIELD("point_source_id","uint16",18,2,SX_ID),
};
static const sx_layout sxsc_las_point0 = {UINT32_C(0x6028000e),"las_point0",sxsc_las_point0_fields,SX_COUNT(sxsc_las_point0_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_point1_fields[] = {
    SX_FIELD("x","int32",0,4,SX_NONE),
    SX_FIELD("y","int32",4,4,SX_NONE),
    SX_FIELD("z","int32",8,4,SX_NONE),
    SX_FIELD("intensity","uint16",12,2,SX_NONE),
    SX_FIELD("return_flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("classification","uint8",15,1,SX_FLAGS),
    SX_FIELD("scan_angle_rank","int8",16,1,SX_NONE),
    SX_FIELD("user_data","uint8",17,1,SX_NONE),
    SX_FIELD("point_source_id","uint16",18,2,SX_ID),
    SX_FIELD("gps_time","float64",20,8,SX_NONE),
};
static const sx_layout sxsc_las_point1 = {UINT32_C(0x6028000f),"las_point1",sxsc_las_point1_fields,SX_COUNT(sxsc_las_point1_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_point2_fields[] = {
    SX_FIELD("x","int32",0,4,SX_NONE),
    SX_FIELD("y","int32",4,4,SX_NONE),
    SX_FIELD("z","int32",8,4,SX_NONE),
    SX_FIELD("intensity","uint16",12,2,SX_NONE),
    SX_FIELD("return_flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("classification","uint8",15,1,SX_FLAGS),
    SX_FIELD("scan_angle_rank","int8",16,1,SX_NONE),
    SX_FIELD("user_data","uint8",17,1,SX_NONE),
    SX_FIELD("point_source_id","uint16",18,2,SX_ID),
    SX_FIELD("red","uint16",20,2,SX_NONE),
    SX_FIELD("green","uint16",22,2,SX_NONE),
    SX_FIELD("blue","uint16",24,2,SX_NONE),
};
static const sx_layout sxsc_las_point2 = {UINT32_C(0x60280010),"las_point2",sxsc_las_point2_fields,SX_COUNT(sxsc_las_point2_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_point3_fields[] = {
    SX_FIELD("x","int32",0,4,SX_NONE),
    SX_FIELD("y","int32",4,4,SX_NONE),
    SX_FIELD("z","int32",8,4,SX_NONE),
    SX_FIELD("intensity","uint16",12,2,SX_NONE),
    SX_FIELD("return_flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("classification","uint8",15,1,SX_FLAGS),
    SX_FIELD("scan_angle_rank","int8",16,1,SX_NONE),
    SX_FIELD("user_data","uint8",17,1,SX_NONE),
    SX_FIELD("point_source_id","uint16",18,2,SX_ID),
    SX_FIELD("gps_time","float64",20,8,SX_NONE),
    SX_FIELD("red","uint16",28,2,SX_NONE),
    SX_FIELD("green","uint16",30,2,SX_NONE),
    SX_FIELD("blue","uint16",32,2,SX_NONE),
};
static const sx_layout sxsc_las_point3 = {UINT32_C(0x60280011),"las_point3",sxsc_las_point3_fields,SX_COUNT(sxsc_las_point3_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_seg2_file_header_le_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("revision","uint16",2,2,SX_ID),
    SX_FIELD("trace_pointer_size","uint16",4,2,SX_SIZE),
    SX_FIELD("trace_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("string_terminator_size","uint8",8,1,SX_SIZE),
    SX_FIELD("string_terminator","uint8[2]",9,2,SX_NONE),
    SX_FIELD("line_terminator_size","uint8",11,1,SX_SIZE),
    SX_FIELD("line_terminator","uint8[2]",12,2,SX_NONE),
    SX_FIELD("reserved","uint8[18]",14,18,SX_RESERVED),
};
static const sx_layout sxsc_seg2_file_header_le = {UINT32_C(0x60280012),"seg2_file_header_le",sxsc_seg2_file_header_le_fields,SX_COUNT(sxsc_seg2_file_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_seg2_trace_pointer_le_fields[] = {
    SX_FIELD("trace_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxsc_seg2_trace_pointer_le = {UINT32_C(0x60280013),"seg2_trace_pointer_le",sxsc_seg2_trace_pointer_le_fields,SX_COUNT(sxsc_seg2_trace_pointer_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_seg2_trace_header_le_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("sample_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("sample_format","uint8",12,1,SX_ID),
    SX_FIELD("reserved","uint8[19]",13,19,SX_RESERVED),
};
static const sx_layout sxsc_seg2_trace_header_le = {UINT32_C(0x60280014),"seg2_trace_header_le",sxsc_seg2_trace_header_le_fields,SX_COUNT(sxsc_seg2_trace_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_seg2_string_length_le_fields[] = {
    SX_FIELD("record_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxsc_seg2_string_length_le = {UINT32_C(0x60280015),"seg2_string_length_le",sxsc_seg2_string_length_le_fields,SX_COUNT(sxsc_seg2_string_length_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_seg2_file_header_be_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("revision","uint16",2,2,SX_ID),
    SX_FIELD("trace_pointer_size","uint16",4,2,SX_SIZE),
    SX_FIELD("trace_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("string_terminator_size","uint8",8,1,SX_SIZE),
    SX_FIELD("string_terminator","uint8[2]",9,2,SX_NONE),
    SX_FIELD("line_terminator_size","uint8",11,1,SX_SIZE),
    SX_FIELD("line_terminator","uint8[2]",12,2,SX_NONE),
    SX_FIELD("reserved","uint8[18]",14,18,SX_RESERVED),
};
static const sx_layout sxsc_seg2_file_header_be = {UINT32_C(0x60280016),"seg2_file_header_be",sxsc_seg2_file_header_be_fields,SX_COUNT(sxsc_seg2_file_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_seg2_trace_pointer_be_fields[] = {
    SX_FIELD("trace_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxsc_seg2_trace_pointer_be = {UINT32_C(0x60280017),"seg2_trace_pointer_be",sxsc_seg2_trace_pointer_be_fields,SX_COUNT(sxsc_seg2_trace_pointer_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_seg2_trace_header_be_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("sample_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("sample_format","uint8",12,1,SX_ID),
    SX_FIELD("reserved","uint8[19]",13,19,SX_RESERVED),
};
static const sx_layout sxsc_seg2_trace_header_be = {UINT32_C(0x60280018),"seg2_trace_header_be",sxsc_seg2_trace_header_be_fields,SX_COUNT(sxsc_seg2_trace_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_seg2_string_length_be_fields[] = {
    SX_FIELD("record_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxsc_seg2_string_length_be = {UINT32_C(0x60280019),"seg2_string_length_be",sxsc_seg2_string_length_be_fields,SX_COUNT(sxsc_seg2_string_length_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_fit_file_header_fields[] = {
    SX_FIELD("header_size","uint8",0,1,SX_SIZE),
    SX_FIELD("protocol_version","uint8",1,1,SX_ID),
    SX_FIELD("profile_version","uint16",2,2,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("signature","char[4]",8,4,SX_SIGNATURE),
};
static const sx_layout sxsc_fit_file_header = {UINT32_C(0x6028001a),"fit_file_header",sxsc_fit_file_header_fields,SX_COUNT(sxsc_fit_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_crc16_fields[] = {
    SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxsc_fit_crc16 = {UINT32_C(0x6028001b),"fit_crc16",sxsc_fit_crc16_fields,SX_COUNT(sxsc_fit_crc16_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_record_header_fields[] = {
    SX_FIELD("record_header","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxsc_fit_record_header = {UINT32_C(0x6028001c),"fit_record_header",sxsc_fit_record_header_fields,SX_COUNT(sxsc_fit_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_definition_le_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
    SX_FIELD("architecture","uint8",1,1,SX_ID),
    SX_FIELD("global_message_number","uint16",2,2,SX_ID),
    SX_FIELD("field_count","uint8",4,1,SX_COUNT_PROP),
};
static const sx_layout sxsc_fit_definition_le = {UINT32_C(0x6028001d),"fit_definition_le",sxsc_fit_definition_le_fields,SX_COUNT(sxsc_fit_definition_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_definition_be_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
    SX_FIELD("architecture","uint8",1,1,SX_ID),
    SX_FIELD("global_message_number","uint16",2,2,SX_ID),
    SX_FIELD("field_count","uint8",4,1,SX_COUNT_PROP),
};
static const sx_layout sxsc_fit_definition_be = {UINT32_C(0x6028001e),"fit_definition_be",sxsc_fit_definition_be_fields,SX_COUNT(sxsc_fit_definition_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_fit_field_definition_fields[] = {
    SX_FIELD("field_definition_number","uint8",0,1,SX_ID),
    SX_FIELD("size","uint8",1,1,SX_SIZE),
    SX_FIELD("base_type","uint8",2,1,SX_ID),
};
static const sx_layout sxsc_fit_field_definition = {UINT32_C(0x6028001f),"fit_field_definition",sxsc_fit_field_definition_fields,SX_COUNT(sxsc_fit_field_definition_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_developer_count_fields[] = {
    SX_FIELD("developer_field_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxsc_fit_developer_count = {UINT32_C(0x60280020),"fit_developer_count",sxsc_fit_developer_count_fields,SX_COUNT(sxsc_fit_developer_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_fit_developer_field_fields[] = {
    SX_FIELD("field_definition_number","uint8",0,1,SX_ID),
    SX_FIELD("size","uint8",1,1,SX_SIZE),
    SX_FIELD("developer_data_index","uint8",2,1,SX_ID),
};
static const sx_layout sxsc_fit_developer_field = {UINT32_C(0x60280021),"fit_developer_field",sxsc_fit_developer_field_fields,SX_COUNT(sxsc_fit_developer_field_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_mda_header_fields[] = {
    SX_FIELD("data_type","int32",0,4,SX_ID),
    SX_FIELD("bytes_per_entry","int32",4,4,SX_SIZE),
    SX_FIELD("dimension_count","int32",8,4,SX_NONE),
};
static const sx_layout sxsc_mda_header = {UINT32_C(0x60280022),"mda_header",sxsc_mda_header_fields,SX_COUNT(sxsc_mda_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_mda_dimension32_fields[] = {
    SX_FIELD("dimension","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxsc_mda_dimension32 = {UINT32_C(0x60280023),"mda_dimension32",sxsc_mda_dimension32_fields,SX_COUNT(sxsc_mda_dimension32_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_mda_dimension64_fields[] = {
    SX_FIELD("dimension","int64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxsc_mda_dimension64 = {UINT32_C(0x60280024),"mda_dimension64",sxsc_mda_dimension64_fields,SX_COUNT(sxsc_mda_dimension64_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("version","char[8]",8,8,SX_STRING),
};
static const sx_layout sxsc_picoquant_header = {UINT32_C(0x60280025),"picoquant_header",sxsc_picoquant_header_fields,SX_COUNT(sxsc_picoquant_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_empty_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","uint64",40,8,SX_RESERVED),
};
static const sx_layout sxsc_picoquant_tag_empty = {UINT32_C(0x60280026),"picoquant_tag_empty",sxsc_picoquant_tag_empty_fields,SX_COUNT(sxsc_picoquant_tag_empty_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_bool_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","uint64",40,8,SX_FLAGS),
};
static const sx_layout sxsc_picoquant_tag_bool = {UINT32_C(0x60280027),"picoquant_tag_bool",sxsc_picoquant_tag_bool_fields,SX_COUNT(sxsc_picoquant_tag_bool_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_integer_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","int64",40,8,SX_NONE),
};
static const sx_layout sxsc_picoquant_tag_integer = {UINT32_C(0x60280028),"picoquant_tag_integer",sxsc_picoquant_tag_integer_fields,SX_COUNT(sxsc_picoquant_tag_integer_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_bitset_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","uint64",40,8,SX_FLAGS),
};
static const sx_layout sxsc_picoquant_tag_bitset = {UINT32_C(0x60280029),"picoquant_tag_bitset",sxsc_picoquant_tag_bitset_fields,SX_COUNT(sxsc_picoquant_tag_bitset_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_color_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","uint64",40,8,SX_ID),
};
static const sx_layout sxsc_picoquant_tag_color = {UINT32_C(0x6028002a),"picoquant_tag_color",sxsc_picoquant_tag_color_fields,SX_COUNT(sxsc_picoquant_tag_color_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_float_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","float64",40,8,SX_NONE),
};
static const sx_layout sxsc_picoquant_tag_float = {UINT32_C(0x6028002b),"picoquant_tag_float",sxsc_picoquant_tag_float_fields,SX_COUNT(sxsc_picoquant_tag_float_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_datetime_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","float64",40,8,SX_NONE),
};
static const sx_layout sxsc_picoquant_tag_datetime = {UINT32_C(0x6028002c),"picoquant_tag_datetime",sxsc_picoquant_tag_datetime_fields,SX_COUNT(sxsc_picoquant_tag_datetime_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_blob_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","uint64",40,8,SX_SIZE),
};
static const sx_layout sxsc_picoquant_tag_blob = {UINT32_C(0x6028002d),"picoquant_tag_blob",sxsc_picoquant_tag_blob_fields,SX_COUNT(sxsc_picoquant_tag_blob_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_picoquant_tag_offset_fields[] = {
    SX_FIELD("identifier","char[32]",0,32,SX_STRING),
    SX_FIELD("index","int32",32,4,SX_ID),
    SX_FIELD("type","uint32",36,4,SX_ID),
    SX_FIELD("value","int64",40,8,SX_OFFSET),
};
static const sx_layout sxsc_picoquant_tag_offset = {UINT32_C(0x6028002e),"picoquant_tag_offset",sxsc_picoquant_tag_offset_fields,SX_COUNT(sxsc_picoquant_tag_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_freesurfer_signature_fields[] = {
    SX_FIELD("signature","uint24",0,3,SX_SIGNATURE),
};
static const sx_layout sxsc_freesurfer_signature = {UINT32_C(0x6028002f),"freesurfer_signature",sxsc_freesurfer_signature_fields,SX_COUNT(sxsc_freesurfer_signature_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_counts_fields[] = {
    SX_FIELD("vertex_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("face_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxsc_freesurfer_counts = {UINT32_C(0x60280030),"freesurfer_counts",sxsc_freesurfer_counts_fields,SX_COUNT(sxsc_freesurfer_counts_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_vertex_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxsc_freesurfer_vertex = {UINT32_C(0x60280031),"freesurfer_vertex",sxsc_freesurfer_vertex_fields,SX_COUNT(sxsc_freesurfer_vertex_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_face_fields[] = {
    SX_FIELD("vertex0","uint32",0,4,SX_ID),
    SX_FIELD("vertex1","uint32",4,4,SX_ID),
    SX_FIELD("vertex2","uint32",8,4,SX_ID),
};
static const sx_layout sxsc_freesurfer_face = {UINT32_C(0x60280032),"freesurfer_face",sxsc_freesurfer_face_fields,SX_COUNT(sxsc_freesurfer_face_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_volume_marker_fields[] = {
    SX_FIELD("marker","uint32",0,4,SX_ID),
};
static const sx_layout sxsc_freesurfer_volume_marker = {UINT32_C(0x60280033),"freesurfer_volume_marker",sxsc_freesurfer_volume_marker_fields,SX_COUNT(sxsc_freesurfer_volume_marker_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_freesurfer_volume_marker_long_fields[] = {
    SX_FIELD("marker","uint32",0,4,SX_ID),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
    SX_FIELD("volume_marker","uint32",8,4,SX_ID),
};
static const sx_layout sxsc_freesurfer_volume_marker_long = {UINT32_C(0x60280034),"freesurfer_volume_marker_long",sxsc_freesurfer_volume_marker_long_fields,SX_COUNT(sxsc_freesurfer_volume_marker_long_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_sac_header_le_fields[] = {
    SX_FIELD("delta","float32",0,4,SX_NONE),
    SX_FIELD("depmin","float32",4,4,SX_NONE),
    SX_FIELD("depmax","float32",8,4,SX_NONE),
    SX_FIELD("scale","float32",12,4,SX_NONE),
    SX_FIELD("odelta","float32",16,4,SX_NONE),
    SX_FIELD("b","float32",20,4,SX_NONE),
    SX_FIELD("e","float32",24,4,SX_NONE),
    SX_FIELD("o","float32",28,4,SX_NONE),
    SX_FIELD("a","float32",32,4,SX_NONE),
    SX_FIELD("internal0","float32",36,4,SX_NONE),
    SX_FIELD("t0","float32",40,4,SX_NONE),
    SX_FIELD("t1","float32",44,4,SX_NONE),
    SX_FIELD("t2","float32",48,4,SX_NONE),
    SX_FIELD("t3","float32",52,4,SX_NONE),
    SX_FIELD("t4","float32",56,4,SX_NONE),
    SX_FIELD("t5","float32",60,4,SX_NONE),
    SX_FIELD("t6","float32",64,4,SX_NONE),
    SX_FIELD("t7","float32",68,4,SX_NONE),
    SX_FIELD("t8","float32",72,4,SX_NONE),
    SX_FIELD("t9","float32",76,4,SX_NONE),
    SX_FIELD("f","float32",80,4,SX_NONE),
    SX_FIELD("resp0","float32",84,4,SX_NONE),
    SX_FIELD("resp1","float32",88,4,SX_NONE),
    SX_FIELD("resp2","float32",92,4,SX_NONE),
    SX_FIELD("resp3","float32",96,4,SX_NONE),
    SX_FIELD("resp4","float32",100,4,SX_NONE),
    SX_FIELD("resp5","float32",104,4,SX_NONE),
    SX_FIELD("resp6","float32",108,4,SX_NONE),
    SX_FIELD("resp7","float32",112,4,SX_NONE),
    SX_FIELD("resp8","float32",116,4,SX_NONE),
    SX_FIELD("resp9","float32",120,4,SX_NONE),
    SX_FIELD("stla","float32",124,4,SX_NONE),
    SX_FIELD("stlo","float32",128,4,SX_NONE),
    SX_FIELD("stel","float32",132,4,SX_NONE),
    SX_FIELD("stdp","float32",136,4,SX_NONE),
    SX_FIELD("evla","float32",140,4,SX_NONE),
    SX_FIELD("evlo","float32",144,4,SX_NONE),
    SX_FIELD("evel","float32",148,4,SX_NONE),
    SX_FIELD("evdp","float32",152,4,SX_NONE),
    SX_FIELD("mag","float32",156,4,SX_NONE),
    SX_FIELD("user0","float32",160,4,SX_NONE),
    SX_FIELD("user1","float32",164,4,SX_NONE),
    SX_FIELD("user2","float32",168,4,SX_NONE),
    SX_FIELD("user3","float32",172,4,SX_NONE),
    SX_FIELD("user4","float32",176,4,SX_NONE),
    SX_FIELD("user5","float32",180,4,SX_NONE),
    SX_FIELD("user6","float32",184,4,SX_NONE),
    SX_FIELD("user7","float32",188,4,SX_NONE),
    SX_FIELD("user8","float32",192,4,SX_NONE),
    SX_FIELD("user9","float32",196,4,SX_NONE),
    SX_FIELD("dist","float32",200,4,SX_NONE),
    SX_FIELD("az","float32",204,4,SX_NONE),
    SX_FIELD("baz","float32",208,4,SX_NONE),
    SX_FIELD("gcarc","float32",212,4,SX_NONE),
    SX_FIELD("internal1","float32",216,4,SX_NONE),
    SX_FIELD("internal2","float32",220,4,SX_NONE),
    SX_FIELD("depmen","float32",224,4,SX_NONE),
    SX_FIELD("cmpaz","float32",228,4,SX_NONE),
    SX_FIELD("cmpinc","float32",232,4,SX_NONE),
    SX_FIELD("xminimum","float32",236,4,SX_NONE),
    SX_FIELD("xmaximum","float32",240,4,SX_NONE),
    SX_FIELD("yminimum","float32",244,4,SX_NONE),
    SX_FIELD("ymaximum","float32",248,4,SX_NONE),
    SX_FIELD("unused6","float32",252,4,SX_NONE),
    SX_FIELD("unused7","float32",256,4,SX_NONE),
    SX_FIELD("unused8","float32",260,4,SX_NONE),
    SX_FIELD("unused9","float32",264,4,SX_NONE),
    SX_FIELD("unused10","float32",268,4,SX_NONE),
    SX_FIELD("unused11","float32",272,4,SX_NONE),
    SX_FIELD("unused12","float32",276,4,SX_NONE),
    SX_FIELD("nzyear","int32",280,4,SX_NONE),
    SX_FIELD("nzjday","int32",284,4,SX_NONE),
    SX_FIELD("nzhour","int32",288,4,SX_NONE),
    SX_FIELD("nzmin","int32",292,4,SX_NONE),
    SX_FIELD("nzsec","int32",296,4,SX_NONE),
    SX_FIELD("nzmsec","int32",300,4,SX_NONE),
    SX_FIELD("nvhdr","int32",304,4,SX_ID),
    SX_FIELD("norid","int32",308,4,SX_ID),
    SX_FIELD("nevid","int32",312,4,SX_ID),
    SX_FIELD("npts","int32",316,4,SX_COUNT_PROP),
    SX_FIELD("internal3","int32",320,4,SX_NONE),
    SX_FIELD("nwfid","int32",324,4,SX_ID),
    SX_FIELD("nxsize","int32",328,4,SX_COUNT_PROP),
    SX_FIELD("nysize","int32",332,4,SX_COUNT_PROP),
    SX_FIELD("unused13","int32",336,4,SX_NONE),
    SX_FIELD("iftype","int32",340,4,SX_ID),
    SX_FIELD("idep","int32",344,4,SX_ID),
    SX_FIELD("iztype","int32",348,4,SX_ID),
    SX_FIELD("unused14","int32",352,4,SX_NONE),
    SX_FIELD("iinst","int32",356,4,SX_ID),
    SX_FIELD("istreg","int32",360,4,SX_ID),
    SX_FIELD("ievreg","int32",364,4,SX_ID),
    SX_FIELD("ievtyp","int32",368,4,SX_ID),
    SX_FIELD("iqual","int32",372,4,SX_ID),
    SX_FIELD("isynth","int32",376,4,SX_ID),
    SX_FIELD("imagtyp","int32",380,4,SX_ID),
    SX_FIELD("imagsrc","int32",384,4,SX_ID),
    SX_FIELD("unused15","int32",388,4,SX_NONE),
    SX_FIELD("unused16","int32",392,4,SX_NONE),
    SX_FIELD("unused17","int32",396,4,SX_NONE),
    SX_FIELD("unused18","int32",400,4,SX_NONE),
    SX_FIELD("unused19","int32",404,4,SX_NONE),
    SX_FIELD("unused20","int32",408,4,SX_NONE),
    SX_FIELD("unused21","int32",412,4,SX_NONE),
    SX_FIELD("unused22","int32",416,4,SX_NONE),
    SX_FIELD("leven","int32",420,4,SX_FLAGS),
    SX_FIELD("lpspol","int32",424,4,SX_FLAGS),
    SX_FIELD("lovrok","int32",428,4,SX_FLAGS),
    SX_FIELD("lcalda","int32",432,4,SX_FLAGS),
    SX_FIELD("unused23","int32",436,4,SX_NONE),
    SX_FIELD("kstnm","char[8]",440,8,SX_STRING),
    SX_FIELD("kevnm","char[16]",448,16,SX_STRING),
    SX_FIELD("khole","char[8]",464,8,SX_STRING),
    SX_FIELD("ko","char[8]",472,8,SX_STRING),
    SX_FIELD("ka","char[8]",480,8,SX_STRING),
    SX_FIELD("kt0","char[8]",488,8,SX_STRING),
    SX_FIELD("kt1","char[8]",496,8,SX_STRING),
    SX_FIELD("kt2","char[8]",504,8,SX_STRING),
    SX_FIELD("kt3","char[8]",512,8,SX_STRING),
    SX_FIELD("kt4","char[8]",520,8,SX_STRING),
    SX_FIELD("kt5","char[8]",528,8,SX_STRING),
    SX_FIELD("kt6","char[8]",536,8,SX_STRING),
    SX_FIELD("kt7","char[8]",544,8,SX_STRING),
    SX_FIELD("kt8","char[8]",552,8,SX_STRING),
    SX_FIELD("kt9","char[8]",560,8,SX_STRING),
    SX_FIELD("kf","char[8]",568,8,SX_STRING),
    SX_FIELD("kuser0","char[8]",576,8,SX_STRING),
    SX_FIELD("kuser1","char[8]",584,8,SX_STRING),
    SX_FIELD("kuser2","char[8]",592,8,SX_STRING),
    SX_FIELD("kcmpnm","char[8]",600,8,SX_STRING),
    SX_FIELD("knetwk","char[8]",608,8,SX_STRING),
    SX_FIELD("kdatrd","char[8]",616,8,SX_STRING),
    SX_FIELD("kinst","char[8]",624,8,SX_STRING),
};
static const sx_layout sxsc_sac_header_le = {UINT32_C(0x60280035),"sac_header_le",sxsc_sac_header_le_fields,SX_COUNT(sxsc_sac_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_sac_header_be_fields[] = {
    SX_FIELD("delta","float32",0,4,SX_NONE),
    SX_FIELD("depmin","float32",4,4,SX_NONE),
    SX_FIELD("depmax","float32",8,4,SX_NONE),
    SX_FIELD("scale","float32",12,4,SX_NONE),
    SX_FIELD("odelta","float32",16,4,SX_NONE),
    SX_FIELD("b","float32",20,4,SX_NONE),
    SX_FIELD("e","float32",24,4,SX_NONE),
    SX_FIELD("o","float32",28,4,SX_NONE),
    SX_FIELD("a","float32",32,4,SX_NONE),
    SX_FIELD("internal0","float32",36,4,SX_NONE),
    SX_FIELD("t0","float32",40,4,SX_NONE),
    SX_FIELD("t1","float32",44,4,SX_NONE),
    SX_FIELD("t2","float32",48,4,SX_NONE),
    SX_FIELD("t3","float32",52,4,SX_NONE),
    SX_FIELD("t4","float32",56,4,SX_NONE),
    SX_FIELD("t5","float32",60,4,SX_NONE),
    SX_FIELD("t6","float32",64,4,SX_NONE),
    SX_FIELD("t7","float32",68,4,SX_NONE),
    SX_FIELD("t8","float32",72,4,SX_NONE),
    SX_FIELD("t9","float32",76,4,SX_NONE),
    SX_FIELD("f","float32",80,4,SX_NONE),
    SX_FIELD("resp0","float32",84,4,SX_NONE),
    SX_FIELD("resp1","float32",88,4,SX_NONE),
    SX_FIELD("resp2","float32",92,4,SX_NONE),
    SX_FIELD("resp3","float32",96,4,SX_NONE),
    SX_FIELD("resp4","float32",100,4,SX_NONE),
    SX_FIELD("resp5","float32",104,4,SX_NONE),
    SX_FIELD("resp6","float32",108,4,SX_NONE),
    SX_FIELD("resp7","float32",112,4,SX_NONE),
    SX_FIELD("resp8","float32",116,4,SX_NONE),
    SX_FIELD("resp9","float32",120,4,SX_NONE),
    SX_FIELD("stla","float32",124,4,SX_NONE),
    SX_FIELD("stlo","float32",128,4,SX_NONE),
    SX_FIELD("stel","float32",132,4,SX_NONE),
    SX_FIELD("stdp","float32",136,4,SX_NONE),
    SX_FIELD("evla","float32",140,4,SX_NONE),
    SX_FIELD("evlo","float32",144,4,SX_NONE),
    SX_FIELD("evel","float32",148,4,SX_NONE),
    SX_FIELD("evdp","float32",152,4,SX_NONE),
    SX_FIELD("mag","float32",156,4,SX_NONE),
    SX_FIELD("user0","float32",160,4,SX_NONE),
    SX_FIELD("user1","float32",164,4,SX_NONE),
    SX_FIELD("user2","float32",168,4,SX_NONE),
    SX_FIELD("user3","float32",172,4,SX_NONE),
    SX_FIELD("user4","float32",176,4,SX_NONE),
    SX_FIELD("user5","float32",180,4,SX_NONE),
    SX_FIELD("user6","float32",184,4,SX_NONE),
    SX_FIELD("user7","float32",188,4,SX_NONE),
    SX_FIELD("user8","float32",192,4,SX_NONE),
    SX_FIELD("user9","float32",196,4,SX_NONE),
    SX_FIELD("dist","float32",200,4,SX_NONE),
    SX_FIELD("az","float32",204,4,SX_NONE),
    SX_FIELD("baz","float32",208,4,SX_NONE),
    SX_FIELD("gcarc","float32",212,4,SX_NONE),
    SX_FIELD("internal1","float32",216,4,SX_NONE),
    SX_FIELD("internal2","float32",220,4,SX_NONE),
    SX_FIELD("depmen","float32",224,4,SX_NONE),
    SX_FIELD("cmpaz","float32",228,4,SX_NONE),
    SX_FIELD("cmpinc","float32",232,4,SX_NONE),
    SX_FIELD("xminimum","float32",236,4,SX_NONE),
    SX_FIELD("xmaximum","float32",240,4,SX_NONE),
    SX_FIELD("yminimum","float32",244,4,SX_NONE),
    SX_FIELD("ymaximum","float32",248,4,SX_NONE),
    SX_FIELD("unused6","float32",252,4,SX_NONE),
    SX_FIELD("unused7","float32",256,4,SX_NONE),
    SX_FIELD("unused8","float32",260,4,SX_NONE),
    SX_FIELD("unused9","float32",264,4,SX_NONE),
    SX_FIELD("unused10","float32",268,4,SX_NONE),
    SX_FIELD("unused11","float32",272,4,SX_NONE),
    SX_FIELD("unused12","float32",276,4,SX_NONE),
    SX_FIELD("nzyear","int32",280,4,SX_NONE),
    SX_FIELD("nzjday","int32",284,4,SX_NONE),
    SX_FIELD("nzhour","int32",288,4,SX_NONE),
    SX_FIELD("nzmin","int32",292,4,SX_NONE),
    SX_FIELD("nzsec","int32",296,4,SX_NONE),
    SX_FIELD("nzmsec","int32",300,4,SX_NONE),
    SX_FIELD("nvhdr","int32",304,4,SX_ID),
    SX_FIELD("norid","int32",308,4,SX_ID),
    SX_FIELD("nevid","int32",312,4,SX_ID),
    SX_FIELD("npts","int32",316,4,SX_COUNT_PROP),
    SX_FIELD("internal3","int32",320,4,SX_NONE),
    SX_FIELD("nwfid","int32",324,4,SX_ID),
    SX_FIELD("nxsize","int32",328,4,SX_COUNT_PROP),
    SX_FIELD("nysize","int32",332,4,SX_COUNT_PROP),
    SX_FIELD("unused13","int32",336,4,SX_NONE),
    SX_FIELD("iftype","int32",340,4,SX_ID),
    SX_FIELD("idep","int32",344,4,SX_ID),
    SX_FIELD("iztype","int32",348,4,SX_ID),
    SX_FIELD("unused14","int32",352,4,SX_NONE),
    SX_FIELD("iinst","int32",356,4,SX_ID),
    SX_FIELD("istreg","int32",360,4,SX_ID),
    SX_FIELD("ievreg","int32",364,4,SX_ID),
    SX_FIELD("ievtyp","int32",368,4,SX_ID),
    SX_FIELD("iqual","int32",372,4,SX_ID),
    SX_FIELD("isynth","int32",376,4,SX_ID),
    SX_FIELD("imagtyp","int32",380,4,SX_ID),
    SX_FIELD("imagsrc","int32",384,4,SX_ID),
    SX_FIELD("unused15","int32",388,4,SX_NONE),
    SX_FIELD("unused16","int32",392,4,SX_NONE),
    SX_FIELD("unused17","int32",396,4,SX_NONE),
    SX_FIELD("unused18","int32",400,4,SX_NONE),
    SX_FIELD("unused19","int32",404,4,SX_NONE),
    SX_FIELD("unused20","int32",408,4,SX_NONE),
    SX_FIELD("unused21","int32",412,4,SX_NONE),
    SX_FIELD("unused22","int32",416,4,SX_NONE),
    SX_FIELD("leven","int32",420,4,SX_FLAGS),
    SX_FIELD("lpspol","int32",424,4,SX_FLAGS),
    SX_FIELD("lovrok","int32",428,4,SX_FLAGS),
    SX_FIELD("lcalda","int32",432,4,SX_FLAGS),
    SX_FIELD("unused23","int32",436,4,SX_NONE),
    SX_FIELD("kstnm","char[8]",440,8,SX_STRING),
    SX_FIELD("kevnm","char[16]",448,16,SX_STRING),
    SX_FIELD("khole","char[8]",464,8,SX_STRING),
    SX_FIELD("ko","char[8]",472,8,SX_STRING),
    SX_FIELD("ka","char[8]",480,8,SX_STRING),
    SX_FIELD("kt0","char[8]",488,8,SX_STRING),
    SX_FIELD("kt1","char[8]",496,8,SX_STRING),
    SX_FIELD("kt2","char[8]",504,8,SX_STRING),
    SX_FIELD("kt3","char[8]",512,8,SX_STRING),
    SX_FIELD("kt4","char[8]",520,8,SX_STRING),
    SX_FIELD("kt5","char[8]",528,8,SX_STRING),
    SX_FIELD("kt6","char[8]",536,8,SX_STRING),
    SX_FIELD("kt7","char[8]",544,8,SX_STRING),
    SX_FIELD("kt8","char[8]",552,8,SX_STRING),
    SX_FIELD("kt9","char[8]",560,8,SX_STRING),
    SX_FIELD("kf","char[8]",568,8,SX_STRING),
    SX_FIELD("kuser0","char[8]",576,8,SX_STRING),
    SX_FIELD("kuser1","char[8]",584,8,SX_STRING),
    SX_FIELD("kuser2","char[8]",592,8,SX_STRING),
    SX_FIELD("kcmpnm","char[8]",600,8,SX_STRING),
    SX_FIELD("knetwk","char[8]",608,8,SX_STRING),
    SX_FIELD("kdatrd","char[8]",616,8,SX_STRING),
    SX_FIELD("kinst","char[8]",624,8,SX_STRING),
};
static const sx_layout sxsc_sac_header_be = {UINT32_C(0x60280036),"sac_header_be",sxsc_sac_header_be_fields,SX_COUNT(sxsc_sac_header_be_fields),SX_BE};
static const sx_layout *const sx_sciencemeta_layouts[] = {
    &sxsc_mrc_header_le,
    &sxsc_mrc_header_be,
    &sxsc_mrc_label,
    &sxsc_shp_file_header,
    &sxsc_shp_record_header,
    &sxsc_shp_shape_type,
    &sxsc_shp_point,
    &sxsc_shp_multipoint,
    &sxsc_shp_polyline_polygon,
    &sxsc_shp_part,
    &sxsc_shp_xy,
    &sxsc_las12_header,
    &sxsc_las_vlr,
    &sxsc_las_point0,
    &sxsc_las_point1,
    &sxsc_las_point2,
    &sxsc_las_point3,
    &sxsc_seg2_file_header_le,
    &sxsc_seg2_trace_pointer_le,
    &sxsc_seg2_trace_header_le,
    &sxsc_seg2_string_length_le,
    &sxsc_seg2_file_header_be,
    &sxsc_seg2_trace_pointer_be,
    &sxsc_seg2_trace_header_be,
    &sxsc_seg2_string_length_be,
    &sxsc_fit_file_header,
    &sxsc_fit_crc16,
    &sxsc_fit_record_header,
    &sxsc_fit_definition_le,
    &sxsc_fit_definition_be,
    &sxsc_fit_field_definition,
    &sxsc_fit_developer_count,
    &sxsc_fit_developer_field,
    &sxsc_mda_header,
    &sxsc_mda_dimension32,
    &sxsc_mda_dimension64,
    &sxsc_picoquant_header,
    &sxsc_picoquant_tag_empty,
    &sxsc_picoquant_tag_bool,
    &sxsc_picoquant_tag_integer,
    &sxsc_picoquant_tag_bitset,
    &sxsc_picoquant_tag_color,
    &sxsc_picoquant_tag_float,
    &sxsc_picoquant_tag_datetime,
    &sxsc_picoquant_tag_blob,
    &sxsc_picoquant_tag_offset,
    &sxsc_freesurfer_signature,
    &sxsc_freesurfer_counts,
    &sxsc_freesurfer_vertex,
    &sxsc_freesurfer_face,
    &sxsc_freesurfer_volume_marker,
    &sxsc_freesurfer_volume_marker_long,
    &sxsc_sac_header_le,
    &sxsc_sac_header_be,
};
static bool sx_sciencemeta_static_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60280000U||id>=0x60290000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60280001U:
        if(!xx_rt_wcscmp(r->name,L"mapc"))text=L"1=X, 2=Y, 3=Z.";
        if(!xx_rt_wcscmp(r->name,L"mapr"))text=L"1=X, 2=Y, 3=Z.";
        if(!xx_rt_wcscmp(r->name,L"maps"))text=L"1=X, 2=Y, 3=Z.";
        if(!xx_rt_wcscmp(r->name,L"nsymbt"))text=L"Byte length of the extended header after the 1024-byte main header.";
        break;
    case 0x60280002U:
        if(!xx_rt_wcscmp(r->name,L"mapc"))text=L"1=X, 2=Y, 3=Z.";
        if(!xx_rt_wcscmp(r->name,L"mapr"))text=L"1=X, 2=Y, 3=Z.";
        if(!xx_rt_wcscmp(r->name,L"maps"))text=L"1=X, 2=Y, 3=Z.";
        if(!xx_rt_wcscmp(r->name,L"nsymbt"))text=L"Byte length of the extended header after the 1024-byte main header.";
        break;
    case 0x60280004U:
        if(!xx_rt_wcscmp(r->name,L"file_length_words"))text=L"File length in 16-bit words; multiply by two for bytes.";
        break;
    case 0x60280005U:
        if(!xx_rt_wcscmp(r->name,L"content_length_words"))text=L"Payload length in 16-bit words, excluding the eight-byte record header.";
        break;
    case 0x6028000cU:
        if(!xx_rt_wcscmp(r->name,L"global_encoding"))text=L"Bit 0 selects adjusted standard GPS time instead of GPS week time.";
        if(!xx_rt_wcscmp(r->name,L"point_data_offset"))text=L"Byte offset from the file base.";
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Coordinate translation, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Coordinate translation, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"z_offset"))text=L"Coordinate translation, not a file offset.";
        break;
    case 0x6028000eU:
        if(!xx_rt_wcscmp(r->name,L"return_flags"))text=L"Bits 0..2 return number, 3..5 number of returns, 6 scan direction, 7 edge of flight line.";
        if(!xx_rt_wcscmp(r->name,L"classification"))text=L"Low 5 bits classification; high bits synthetic, key-point and withheld.";
        break;
    case 0x6028000fU:
        if(!xx_rt_wcscmp(r->name,L"return_flags"))text=L"Bits 0..2 return number, 3..5 number of returns, 6 scan direction, 7 edge of flight line.";
        if(!xx_rt_wcscmp(r->name,L"classification"))text=L"Low 5 bits classification; high bits synthetic, key-point and withheld.";
        break;
    case 0x60280010U:
        if(!xx_rt_wcscmp(r->name,L"return_flags"))text=L"Bits 0..2 return number, 3..5 number of returns, 6 scan direction, 7 edge of flight line.";
        if(!xx_rt_wcscmp(r->name,L"classification"))text=L"Low 5 bits classification; high bits synthetic, key-point and withheld.";
        break;
    case 0x60280011U:
        if(!xx_rt_wcscmp(r->name,L"return_flags"))text=L"Bits 0..2 return number, 3..5 number of returns, 6 scan direction, 7 edge of flight line.";
        if(!xx_rt_wcscmp(r->name,L"classification"))text=L"Low 5 bits classification; high bits synthetic, key-point and withheld.";
        break;
    case 0x60280013U:
        if(!xx_rt_wcscmp(r->name,L"trace_offset"))text=L"Byte offset from the file base.";
        break;
    case 0x60280015U:
        if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Includes this length field and the configured string terminator; zero ends the string block.";
        break;
    case 0x60280017U:
        if(!xx_rt_wcscmp(r->name,L"trace_offset"))text=L"Byte offset from the file base.";
        break;
    case 0x60280019U:
        if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Includes this length field and the configured string terminator; zero ends the string block.";
        break;
    case 0x6028001aU:
        if(!xx_rt_wcscmp(r->name,L"protocol_version"))text=L"High nibble is major; low nibble is minor.";
        break;
    case 0x6028001bU:
        if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"FIT CRC-16 checksum.";
        break;
    case 0x6028001cU:
        if(!xx_rt_wcscmp(r->name,L"record_header"))text=L"Bit 7 compressed timestamp; otherwise bit 6 definition and bit 5 developer fields; low bits select local message.";
        break;
    case 0x6028001dU:
        if(!xx_rt_wcscmp(r->name,L"architecture"))text=L"0=little-endian, 1=big-endian.";
        break;
    case 0x6028001eU:
        if(!xx_rt_wcscmp(r->name,L"architecture"))text=L"0=little-endian, 1=big-endian.";
        break;
    case 0x60280022U:
        if(!xx_rt_wcscmp(r->name,L"dimension_count"))text=L"Negative count selects 64-bit dimension values; positive selects 32-bit.";
        break;
    case 0x60280026U:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Empty tag value.";
        break;
    case 0x60280027U:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Boolean tag value.";
        break;
    case 0x60280028U:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Signed integer tag value.";
        break;
    case 0x60280029U:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Bitset tag value.";
        break;
    case 0x6028002aU:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Packed color tag value.";
        break;
    case 0x6028002bU:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Floating-point tag value.";
        break;
    case 0x6028002cU:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Date/time in days relative to 1899-12-30.";
        break;
    case 0x6028002dU:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Byte count of the following tag payload.";
        break;
    case 0x6028002eU:
        if(!xx_rt_wcscmp(r->name,L"index"))text=L"-1 denotes an unindexed tag.";
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Byte offset from the file base to histogram data.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}

static bool sx_sciencemeta_comment(xx_data_struct_record *r,uint32_t id)
{
 if(!r||!r->name||id<0x60280000U||id>=0x60290000U)return true;
 if(!sx_sciencemeta_static_comment(r,id))return false;
 xx_var_type_t type=xx_var_get_type(&r->value);
 if(type==XX_VAR_TYPE_FLOAT||type==XX_VAR_TYPE_DOUBLE||type==XX_VAR_TYPE_STRING||type==XX_VAR_TYPE_BYTES)return true;
 const wchar_t *text=NULL;uint64_t v=xx_var_get_u64(&r->value);
#define SSC_FIELD(n) (!xx_rt_wcscmp(r->name,L##n))
 if((id==sxsc_mrc_header_le.id||id==sxsc_mrc_header_be.id)&&SSC_FIELD("mode")){
  switch(v){case 0:text=L"MODE_INT8";break;case 1:text=L"MODE_INT16";break;case 2:text=L"MODE_FLOAT32";break;case 3:text=L"MODE_COMPLEX_INT16";break;case 4:text=L"MODE_COMPLEX_FLOAT32";break;case 6:text=L"MODE_UINT16";break;case 12:text=L"MODE_FLOAT16";break;case 101:text=L"MODE_PACKED_4BIT";break;}
 }else if(SSC_FIELD("shape_type")){
  switch(v){case 0:text=L"NULL_SHAPE";break;case 1:text=L"POINT";break;case 3:text=L"POLYLINE";break;case 5:text=L"POLYGON";break;case 8:text=L"MULTIPOINT";break;}
 }else if(id==sxsc_las12_header.id&&SSC_FIELD("point_data_format")){
  switch(v){case 0:text=L"POINT_FORMAT_0";break;case 1:text=L"POINT_FORMAT_1_GPS_TIME";break;case 2:text=L"POINT_FORMAT_2_RGB";break;case 3:text=L"POINT_FORMAT_3_GPS_TIME_RGB";break;}
 }else if((id==sxsc_seg2_trace_header_le.id||id==sxsc_seg2_trace_header_be.id)&&SSC_FIELD("sample_format")){
  switch(v){case 1:text=L"INT16";break;case 2:text=L"INT32";break;case 3:text=L"20_BIT_FLOAT";break;case 4:text=L"IEEE_FLOAT32";break;case 5:text=L"IEEE_FLOAT64";break;}
 }else if(id==sxsc_mda_header.id&&SSC_FIELD("data_type")){
  switch((int64_t)v){case -2:text=L"MDA_UINT8";break;case -3:text=L"MDA_FLOAT32";break;case -4:text=L"MDA_INT16";break;case -5:text=L"MDA_INT32";break;case -6:text=L"MDA_UINT16";break;case -7:text=L"MDA_FLOAT64";break;case -8:text=L"MDA_UINT32";break;}
 }else if(SSC_FIELD("type")){
  switch(v){case 0xffff0008U:text=L"tyEmpty8";break;case 0x00000008U:text=L"tyBool8";break;case 0x10000008U:text=L"tyInt8";break;case 0x11000008U:text=L"tyBitSet64";break;case 0x12000008U:text=L"tyColor8";break;case 0x20000008U:text=L"tyFloat8";break;case 0x21000008U:text=L"tyTDateTime";break;case 0x2001ffffU:text=L"tyFloat8Array";break;case 0x4001ffffU:text=L"tyAnsiString";break;case 0x4002ffffU:text=L"tyWideString";break;case 0xffffffffU:text=L"tyBinaryBlob";break;}
 }else if(id==sxsc_fit_field_definition.id&&SSC_FIELD("base_type")){
  switch(v){case 0:text=L"FIT_ENUM";break;case 1:text=L"FIT_SINT8";break;case 2:text=L"FIT_UINT8";break;case 0x83:text=L"FIT_SINT16";break;case 0x84:text=L"FIT_UINT16";break;case 0x85:text=L"FIT_SINT32";break;case 0x86:text=L"FIT_UINT32";break;case 7:text=L"FIT_STRING";break;case 0x88:text=L"FIT_FLOAT32";break;case 0x89:text=L"FIT_FLOAT64";break;case 10:text=L"FIT_UINT8Z";break;case 0x8b:text=L"FIT_UINT16Z";break;case 0x8c:text=L"FIT_UINT32Z";break;case 13:text=L"FIT_BYTE";break;case 0x8e:text=L"FIT_SINT64";break;case 0x8f:text=L"FIT_UINT64";break;case 0x90:text=L"FIT_UINT64Z";break;}
 }else if(id==sxsc_sac_header_le.id||id==sxsc_sac_header_be.id){
  if((int64_t)v==-12345&&xx_var_get_type(&r->value)!=XX_VAR_TYPE_DOUBLE)text=L"SAC_UNDEFINED";
  else if(SSC_FIELD("iftype")){switch(v){case 1:text=L"ITIME";break;case 2:text=L"IRLIM";break;case 3:text=L"IAMPH";break;case 4:text=L"IXY";break;}}
  else if(SSC_FIELD("idep")){switch(v){case 5:text=L"IUNKN";break;case 6:text=L"IDISP";break;case 7:text=L"IVEL";break;case 8:text=L"IACC";break;case 50:text=L"IVOLTS";break;}}
  else if(SSC_FIELD("leven")||SSC_FIELD("lpspol")||SSC_FIELD("lovrok")||SSC_FIELD("lcalda")){if(v==0)text=L"FALSE";else if(v==1)text=L"TRUE";}
 }
#undef SSC_FIELD
 return !text||xx_data_struct_record_set_comment(r,text);
}

static bool sx_sciencemeta_supports(xx_file_type_t t)
{
 switch(t){case XX_FILE_TYPE_MRC:case XX_FILE_TYPE_ESRI_SHP:case XX_FILE_TYPE_LIDAR_LAS:case XX_FILE_TYPE_SEISMIC_SEG2:case XX_FILE_TYPE_GARMIN_FIT:case XX_FILE_TYPE_MOUNTAINSORT_MDA:case XX_FILE_TYPE_PHOTONTIMING_PTU:case XX_FILE_TYPE_PHOTONTIMING_PHU:case XX_FILE_TYPE_FREESURFER_SURFACE:case XX_FILE_TYPE_SEISMIC_SAC:return true;default:return false;}
}
static uint16_t sxsc16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
static uint32_t sxsc32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
static bool sxsc_span(sx_context *c,int64_t at,uint64_t n){return c&&!xx_pd_is_stopped(c->pd)&&at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at);}
static bool sxsc_add(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes){return c->count<32000&&sxsc_span(c,at,(uint64_t)bytes)&&sx_add(c,l,at,bytes);}
static bool sxsc_table(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes,uint64_t count){return c->count<32000&&bytes>0&&count<=INT64_MAX/(uint64_t)bytes&&sxsc_span(c,at,(uint64_t)bytes*count)&&sx_table(c,l,at,bytes,count);}
static int sxsc_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:0;}
static bool sxsc_finish(sx_context *c)
{
 size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsc_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsc_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sxsc_mrc(sx_context *c)
{
 uint8_t b[224];if(!sx_read(c,0,b,sizeof(b))||xx_rt_memcmp(b+208,"MAP ",4))return false;
 bool be=b[212]==0x11&&b[213]==0x11;if(!be&&!(b[212]==0x44&&(b[213]==0x44||b[213]==0x41)))return false;
 return sxsc_add(c,be?&sxsc_mrc_header_be:&sxsc_mrc_header_le,0,224)&&sxsc_table(c,&sxsc_mrc_label,224,80,10);
}
static bool sxsc_shp(sx_context *c)
{
 uint8_t b[44];uint32_t words;if(!sx_u32(c,24,true,&words)||!sxsc_add(c,&sxsc_shp_file_header,0,100))return false;
 int64_t end=(int64_t)words*2,at=100;if(!sxsc_span(c,0,end)||end<100)return false;
 for(unsigned n=0;at<end;n++){
  if(n>=4095||end-at<12||!sx_read(c,at,b,12))return false;uint64_t size=(uint64_t)sxsc32(b+4,true)*2;uint32_t kind=sxsc32(b+8,false);int64_t data=at+8;
  if(size<4||size>(uint64_t)(end-data)||!sxsc_add(c,&sxsc_shp_record_header,at,8))return false;
  if(kind==0){if(size!=4||!sxsc_add(c,&sxsc_shp_shape_type,data,4))return false;}
  else if(kind==1){if(size!=20||!sxsc_add(c,&sxsc_shp_point,data,20))return false;}
  else if(kind==3||kind==5||kind==8){
   unsigned h=kind==8?40:44;uint32_t parts=0,points;if(size<h||!sx_read(c,data,b,h))return false;
   if(kind==8)points=sxsc32(b+36,false);else{parts=sxsc32(b+36,false);points=sxsc32(b+40,false);}
   if(parts>4096||points>1000000||size!=h+(uint64_t)parts*4+(uint64_t)points*16||!sxsc_add(c,kind==8?&sxsc_shp_multipoint:&sxsc_shp_polyline_polygon,data,h)||!sxsc_table(c,&sxsc_shp_part,data+h,4,parts)||!sxsc_table(c,&sxsc_shp_xy,data+h+(int64_t)parts*4,16,points))return false;
  }else return false;
  at=data+(int64_t)size;
 }return at==end;
}
static bool sxsc_las(sx_context *c)
{
 uint8_t b[227];if(!sx_read(c,0,b,sizeof(b))||xx_rt_memcmp(b,"LASF",4)||b[24]!=1||b[25]!=2||!sxsc_add(c,&sxsc_las12_header,0,227))return false;
 uint32_t data=sxsc32(b+96,false),vlrs=sxsc32(b+100,false),count=sxsc32(b+107,false);unsigned fmt=b[104],width=sxsc16(b+105,false);int64_t at=sxsc16(b+94,false);
 const sx_layout *ls[]={&sxsc_las_point0,&sxsc_las_point1,&sxsc_las_point2,&sxsc_las_point3};const unsigned widths[]={20,28,26,34};
 if(at<227||data<(uint64_t)at||vlrs>1024||fmt>3||width<widths[fmt]||count>1000000||!sxsc_span(c,data,(uint64_t)width*count))return false;
 for(uint32_t i=0;i<vlrs;i++){if(data-(uint64_t)at<54||!sx_read(c,at,b,54)||!sxsc_add(c,&sxsc_las_vlr,at,54))return false;uint64_t n=54U+sxsc16(b+20,false);if(n>data-(uint64_t)at)return false;at+=(int64_t)n;}
 /* Vendor point extensions remain raw. A stride is not represented as fields. */
 if(width==widths[fmt])return sxsc_table(c,ls[fmt],data,width,count);
 if(count>16000)return true;
 for(uint32_t i=0;i<count;i++)if(!sxsc_add(c,ls[fmt],(int64_t)data+(int64_t)i*width,widths[fmt]))return false;
 return true;
}
static bool sxsc_seg2_strings(sx_context *c,int64_t at,int64_t end,bool be)
{
 for(unsigned i=0;at<end;i++){uint16_t n;if(i>=512||end-at<2||!sx_u16(c,at,be,&n)||!sxsc_add(c,be?&sxsc_seg2_string_length_be:&sxsc_seg2_string_length_le,at,2))return false;if(!n)return true;if(n<3||n>end-at)return false;at+=n;}return true;
}
static bool sxsc_seg2(sx_context *c)
{
 uint8_t b[32];if(!sx_read(c,0,b,32))return false;bool be=sxsc16(b,true)==0x3a55;if(!be&&sxsc16(b,false)!=0x3a55)return false;
 uint32_t count=sxsc16(b+6,be),pointers=sxsc16(b+4,be),first;if(!count||count>1024||pointers!=count*4||!sxsc_add(c,be?&sxsc_seg2_file_header_be:&sxsc_seg2_file_header_le,0,32)||!sxsc_table(c,be?&sxsc_seg2_trace_pointer_be:&sxsc_seg2_trace_pointer_le,32,4,count)||!sx_u32(c,32,be,&first)||first<32+pointers||!sxsc_span(c,0,first)||!sxsc_seg2_strings(c,32+pointers,first,be))return false;
 for(uint32_t i=0;i<count;i++){
  uint32_t pos;if(!sx_u32(c,32+(int64_t)i*4,be,&pos)||!sx_read(c,pos,b,32)||sxsc16(b,be)!=0x4422)return false;uint32_t header=sxsc16(b+2,be),bytes=sxsc32(b+4,be);
  if(header<34||!sxsc_span(c,pos,(uint64_t)header+bytes)||!sxsc_add(c,be?&sxsc_seg2_trace_header_be:&sxsc_seg2_trace_header_le,pos,32)||!sxsc_seg2_strings(c,(int64_t)pos+32,(int64_t)pos+header,be))return false;
 }return true;
}
static bool sxsc_fit(sx_context *c)
{
 uint8_t b[16];uint32_t sizes[16]={0};if(!sx_read(c,0,b,12)||(b[0]!=12&&b[0]!=14)||xx_rt_memcmp(b+8,".FIT",4)||!sxsc_add(c,&sxsc_fit_file_header,0,12))return false;
 int64_t at=b[0],end=at+(int64_t)sxsc32(b+4,false);if(!sxsc_span(c,end,2))return false;if(at==14&&!sxsc_add(c,&sxsc_fit_crc16,12,2))return false;
 for(unsigned n=0;at<end;n++){
  if(n>=4094||!sx_read(c,at,b,1)||!sxsc_add(c,&sxsc_fit_record_header,at,1))return false;unsigned code=b[0],local=code&15;at++;
  if(code&128){local=(code>>5)&3;if(sizes[local]<4||sizes[local]-4>(uint64_t)(end-at))return false;at+=sizes[local]-4;}
  else if(code&64){
   if(end-at<5||!sx_read(c,at,b,5)||b[1]>1)return false;bool be=b[1]!=0;unsigned count=b[4];if(!sxsc_add(c,be?&sxsc_fit_definition_be:&sxsc_fit_definition_le,at,5))return false;at+=5;uint32_t size=0;
   if(!count||count*3U>(uint64_t)(end-at))return false;
   for(unsigned i=0;i<count;i++){if(!sx_read(c,at,b,3)||!b[1]||!sxsc_add(c,&sxsc_fit_field_definition,at,3))return false;size+=b[1];at+=3;}
   if(code&32){if(at>=end||!sx_read(c,at,b,1)||!sxsc_add(c,&sxsc_fit_developer_count,at,1))return false;count=b[0];at++;if(count*3U>(uint64_t)(end-at))return false;for(unsigned i=0;i<count;i++){if(!sx_read(c,at,b,3)||!b[1]||!sxsc_add(c,&sxsc_fit_developer_field,at,3))return false;size+=b[1];at+=3;}}
   sizes[local]=size;
  }else{if(!sizes[local]||sizes[local]>(uint64_t)(end-at))return false;at+=sizes[local];}
 }return at==end&&sxsc_add(c,&sxsc_fit_crc16,end,2);
}
static bool sxsc_mda(sx_context *c)
{
 uint32_t raw;if(!sx_u32(c,8,false,&raw)||!sxsc_add(c,&sxsc_mda_header,0,12))return false;bool wide=(raw&0x80000000U)!=0;uint32_t count=wide?0U-raw:raw;
 return count>=2&&count<=6&&sxsc_table(c,wide?&sxsc_mda_dimension64:&sxsc_mda_dimension32,12,wide?8:4,count);
}
static bool sxsc_pq(sx_context *c)
{
 uint8_t b[48];if(!sx_read(c,0,b,16)||!sxsc_add(c,&sxsc_picoquant_header,0,16))return false;int64_t at=16;
 for(unsigned i=0;i<1024;i++){
  if(at>4194256||!sx_read(c,at,b,48)||!xx_rt_memchr(b,0,32))return false;uint32_t type=sxsc32(b+36,false);uint64_t value=xx_data_get_u64(b+40,8,0,false),payload=0;const sx_layout *l=NULL;
  switch(type){case 0xffff0008U:l=&sxsc_picoquant_tag_empty;break;case 0x00000008:l=&sxsc_picoquant_tag_bool;break;case 0x10000008:l=!xx_rt_strcmp((const char *)b,"HistResDscr_DataOffset")?&sxsc_picoquant_tag_offset:&sxsc_picoquant_tag_integer;break;case 0x11000008:l=&sxsc_picoquant_tag_bitset;break;case 0x12000008:l=&sxsc_picoquant_tag_color;break;case 0x20000008:l=&sxsc_picoquant_tag_float;break;case 0x21000008:l=&sxsc_picoquant_tag_datetime;break;case 0x2001ffff:case 0x4001ffff:case 0x4002ffff:case 0xffffffff:l=&sxsc_picoquant_tag_blob;payload=value;break;default:return false;}
  if(payload>1048576||!sxsc_span(c,at+48,payload)||!sxsc_add(c,l,at,48))return false;at+=48+(int64_t)payload;if(!xx_rt_strcmp((const char *)b,"Header_End"))return true;
 }return false;
}
static bool sxsc_freesurfer(sx_context *c)
{
 uint8_t b;int64_t at=3;if(!sxsc_add(c,&sxsc_freesurfer_signature,0,3))return false;
 for(unsigned line=0;line<2;line++){unsigned used=0;do{if(used++>4096||!sx_read(c,at++,&b,1))return false;}while(b!=10);}
 uint32_t vertices,faces;if(!sx_u32(c,at,true,&vertices)||!sx_u32(c,at+4,true,&faces)||vertices>1000000||faces>1000000||!sxsc_add(c,&sxsc_freesurfer_counts,at,8))return false;at+=8;
 if(!sxsc_table(c,&sxsc_freesurfer_vertex,at,12,vertices))return false;at+=(int64_t)vertices*12;if(!sxsc_table(c,&sxsc_freesurfer_face,at,12,faces))return false;at+=(int64_t)faces*12;
 if(at<c->size){uint32_t marker;if(!sx_u32(c,at,true,&marker))return false;if(marker==20)return sxsc_add(c,&sxsc_freesurfer_volume_marker,at,4);if(marker==2)return sxsc_add(c,&sxsc_freesurfer_volume_marker_long,at,12);return false;}return true;
}
static bool sx_sciencemeta_build(sx_context *c)
{
 if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;
 switch(c->f->file_type){case XX_FILE_TYPE_MRC:ok=sxsc_mrc(c);break;case XX_FILE_TYPE_ESRI_SHP:ok=sxsc_shp(c);break;case XX_FILE_TYPE_LIDAR_LAS:ok=sxsc_las(c);break;case XX_FILE_TYPE_SEISMIC_SEG2:ok=sxsc_seg2(c);break;case XX_FILE_TYPE_GARMIN_FIT:ok=sxsc_fit(c);break;case XX_FILE_TYPE_MOUNTAINSORT_MDA:ok=sxsc_mda(c);break;case XX_FILE_TYPE_PHOTONTIMING_PTU:case XX_FILE_TYPE_PHOTONTIMING_PHU:ok=sxsc_pq(c);break;case XX_FILE_TYPE_FREESURFER_SURFACE:ok=sxsc_freesurfer(c);break;case XX_FILE_TYPE_SEISMIC_SAC:{uint32_t v;if(!sx_u32(c,304,false,&v))return false;bool be=v!=6;if(be&&!sx_u32(c,304,true,&v))return false;ok=v==6&&sxsc_add(c,be?&sxsc_sac_header_be:&sxsc_sac_header_le,0,632);break;}default:return false;}
 return ok&&sxsc_finish(c);
}
