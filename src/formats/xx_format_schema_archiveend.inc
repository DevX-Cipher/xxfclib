/* SPDX-License-Identifier: MIT. Genuine physical metadata; see docs/data_struct_archiveend_scope.txt. */
static const xx_data_struct_field_desc sxaend_archiveend_name_fields[]={
 SX_FIELD("archiveend_name","char",0,0,SX_STRING),
};
static const sx_layout sxaend_archiveend_name={UINT32_C(0x60840001),"archiveend_name",sxaend_archiveend_name_fields,SX_COUNT(sxaend_archiveend_name_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_archiveend_comment_fields[]={
 SX_FIELD("archiveend_comment","char",0,0,SX_STRING),
};
static const sx_layout sxaend_archiveend_comment={UINT32_C(0x60840002),"archiveend_comment",sxaend_archiveend_comment_fields,SX_COUNT(sxaend_archiveend_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sds_sfx_member_fields[]={
 SX_FIELD("name","char[20]",0,20,SX_STRING),
 SX_FIELD("packed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("data_checksum","uint16",28,2,SX_CHECKSUM),
};
static const sx_layout sxaend_sds_sfx_member={UINT32_C(0x60840003),"sds_sfx_member",sxaend_sds_sfx_member_fields,SX_COUNT(sxaend_sds_sfx_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_lhpak_sfx_position_fields[]={
 SX_FIELD("archive_offset_longs","uint32",0,4,SX_NONE),
};
static const sx_layout sxaend_lhpak_sfx_position={UINT32_C(0x60840004),"lhpak_sfx_position",sxaend_lhpak_sfx_position_fields,SX_COUNT(sxaend_lhpak_sfx_position_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_lhpak_sfx_member_fields[]={
 SX_FIELD("next_block_displacement","uint32",0,4,SX_OFFSET),
 SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("block_number","uint16",6,2,SX_NONE),
 SX_FIELD("uncompressed_block_size","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("unknown_20","uint8[4]",20,4,SX_NONE),
 SX_FIELD("uncompressed_file_size","uint32",24,4,SX_SIZE),
 SX_FIELD("unknown_28","uint8[14]",28,14,SX_NONE),
 SX_FIELD("name_longs","uint8",42,1,SX_NONE),
 SX_FIELD("comment_longs","uint8",43,1,SX_NONE),
};
static const sx_layout sxaend_lhpak_sfx_member={UINT32_C(0x60840005),"lhpak_sfx_member",sxaend_lhpak_sfx_member_fields,SX_COUNT(sxaend_lhpak_sfx_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_lhpak_sfx_block_fields[]={
 SX_FIELD("next_block_displacement","uint32",0,4,SX_OFFSET),
 SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("block_number","uint16",6,2,SX_NONE),
 SX_FIELD("uncompressed_block_size","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxaend_lhpak_sfx_block={UINT32_C(0x60840006),"lhpak_sfx_block",sxaend_lhpak_sfx_block_fields,SX_COUNT(sxaend_lhpak_sfx_block_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_lhsfx_control_fields[]={
 SX_FIELD("control","uint32",0,4,SX_NONE),
};
static const sx_layout sxaend_lhsfx_control={UINT32_C(0x60840007),"lhsfx_control",sxaend_lhsfx_control_fields,SX_COUNT(sxaend_lhsfx_control_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_lhsfx_member_fields[]={
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown_8","uint8[4]",8,4,SX_NONE),
 SX_FIELD("name","char[48]",12,48,SX_STRING),
};
static const sx_layout sxaend_lhsfx_member={UINT32_C(0x60840008),"lhsfx_member",sxaend_lhsfx_member_fields,SX_COUNT(sxaend_lhsfx_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_mode_fields[]={
 SX_FIELD("mode","uint16",0,2,SX_ID),
};
static const sx_layout sxaend_omni_mode={UINT32_C(0x60840009),"omni_mode",sxaend_omni_mode_fields,SX_COUNT(sxaend_omni_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_comment_size_fields[]={
 SX_FIELD("comment_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxaend_omni_comment_size={UINT32_C(0x6084000a),"omni_comment_size",sxaend_omni_comment_size_fields,SX_COUNT(sxaend_omni_comment_size_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_name_size_fields[]={
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxaend_omni_name_size={UINT32_C(0x6084000b),"omni_name_size",sxaend_omni_name_size_fields,SX_COUNT(sxaend_omni_name_size_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_data_size_fields[]={
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxaend_omni_data_size={UINT32_C(0x6084000c),"omni_data_size",sxaend_omni_data_size_fields,SX_COUNT(sxaend_omni_data_size_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_omni_member_tail_fields[]={
 SX_FIELD("unknown_tail","uint8[2]",0,2,SX_NONE),
};
static const sx_layout sxaend_omni_member_tail={UINT32_C(0x6084000d),"omni_member_tail",sxaend_omni_member_tail_fields,SX_COUNT(sxaend_omni_member_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_omni_lh_block_fields[]={
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",2,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("packed_raw_crc32","uint32",10,4,SX_CHECKSUM),
};
static const sx_layout sxaend_omni_lh_block={UINT32_C(0x6084000e),"omni_lh_block",sxaend_omni_lh_block_fields,SX_COUNT(sxaend_omni_lh_block_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_diet_data_v100_fields[]={
 SX_FIELD("exit_instructions","uint8[4]",0,4,SX_NONE),
 SX_FIELD("signature","uint8[2]",4,2,SX_SIGNATURE),
 SX_FIELD("compressed_crc16","uint16",6,2,SX_CHECKSUM),
};
static const sx_layout sxaend_diet_data_v100={UINT32_C(0x6084000f),"diet_data_v100",sxaend_diet_data_v100_fields,SX_COUNT(sxaend_diet_data_v100_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_diet_data_v102_fields[]={
 SX_FIELD("signature","uint8[5]",0,5,SX_SIGNATURE),
};
static const sx_layout sxaend_diet_data_v102={UINT32_C(0x60840010),"diet_data_v102",sxaend_diet_data_v102_fields,SX_COUNT(sxaend_diet_data_v102_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_diet_data_v144_fields[]={
 SX_FIELD("exit_instructions","uint8[4]",0,4,SX_NONE),
 SX_FIELD("signature","uint8[5]",4,5,SX_SIGNATURE),
};
static const sx_layout sxaend_diet_data_v144={UINT32_C(0x60840011),"diet_data_v144",sxaend_diet_data_v144_fields,SX_COUNT(sxaend_diet_data_v144_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_diet_data_lengths_fields[]={
 SX_FIELD("flags_and_packed_size_high","uint8",0,1,SX_NONE),
 SX_FIELD("packed_size_low","uint16",1,2,SX_NONE),
 SX_FIELD("compressed_crc16","uint16",3,2,SX_CHECKSUM),
 SX_FIELD("uncompressed_size_high","uint8",5,1,SX_NONE),
 SX_FIELD("uncompressed_size_low","uint16",6,2,SX_NONE),
};
static const sx_layout sxaend_diet_data_lengths={UINT32_C(0x60840012),"diet_data_lengths",sxaend_diet_data_lengths_fields,SX_COUNT(sxaend_diet_data_lengths_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dclraw_stream_fields[]={
 SX_FIELD("literal_mode","uint8",0,1,SX_ID),
 SX_FIELD("dictionary_selector","uint8",1,1,SX_NONE),
};
static const sx_layout sxaend_dclraw_stream={UINT32_C(0x60840013),"dclraw_stream",sxaend_dclraw_stream_fields,SX_COUNT(sxaend_dclraw_stream_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_header_fields[]={
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("node_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("screen_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("body_size","uint32",6,4,SX_SIZE),
 SX_FIELD("node_count_copy","uint16",10,2,SX_COUNT_PROP),
};
static const sx_layout sxaend_copyqm_tx_header={UINT32_C(0x60840014),"copyqm_tx_header",sxaend_copyqm_tx_header_fields,SX_COUNT(sxaend_copyqm_tx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_leaf_fields[]={
 SX_FIELD("leaf_marker","uint8",0,1,SX_ID),
 SX_FIELD("symbol","uint8",1,1,SX_NONE),
};
static const sx_layout sxaend_copyqm_tx_leaf={UINT32_C(0x60840015),"copyqm_tx_leaf",sxaend_copyqm_tx_leaf_fields,SX_COUNT(sxaend_copyqm_tx_leaf_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_branch_fields[]={
 SX_FIELD("zero_child","uint8",0,1,SX_NONE),
 SX_FIELD("one_child","uint8",1,1,SX_NONE),
};
static const sx_layout sxaend_copyqm_tx_branch={UINT32_C(0x60840016),"copyqm_tx_branch",sxaend_copyqm_tx_branch_fields,SX_COUNT(sxaend_copyqm_tx_branch_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_screen6_fields[]={
 SX_FIELD("line_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",2,4,SX_OFFSET),
};
static const sx_layout sxaend_copyqm_tx_screen6={UINT32_C(0x60840017),"copyqm_tx_screen6",sxaend_copyqm_tx_screen6_fields,SX_COUNT(sxaend_copyqm_tx_screen6_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_screen8_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
 SX_FIELD("line_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxaend_copyqm_tx_screen8={UINT32_C(0x60840018),"copyqm_tx_screen8",sxaend_copyqm_tx_screen8_fields,SX_COUNT(sxaend_copyqm_tx_screen8_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_geometry_fields[]={
 SX_FIELD("geometry_0","uint16",0,2,SX_NONE),
 SX_FIELD("geometry_1","uint16",2,2,SX_NONE),
 SX_FIELD("geometry_2","uint16",4,2,SX_NONE),
};
static const sx_layout sxaend_copyqm_tx_geometry={UINT32_C(0x60840019),"copyqm_tx_geometry",sxaend_copyqm_tx_geometry_fields,SX_COUNT(sxaend_copyqm_tx_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_copyqm_tx_line_fields[]={
 SX_FIELD("record_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxaend_copyqm_tx_line={UINT32_C(0x6084001a),"copyqm_tx_line",sxaend_copyqm_tx_line_fields,SX_COUNT(sxaend_copyqm_tx_line_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_nss_member_fields[]={
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("packed_size","uint32",2,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("unknown_10","uint8[14]",10,14,SX_NONE),
 SX_FIELD("compression","uint16",24,2,SX_ID),
 SX_FIELD("unknown_26","uint8[4]",26,4,SX_NONE),
 SX_FIELD("signature","char[8]",30,8,SX_SIGNATURE),
 SX_FIELD("initialization_vector","uint8[8]",38,8,SX_NONE),
 SX_FIELD("name","char[256]",46,256,SX_STRING),
 SX_FIELD("unknown_302","uint8[14]",302,14,SX_NONE),
};
static const sx_layout sxaend_nss_member={UINT32_C(0x6084001b),"nss_member",sxaend_nss_member_fields,SX_COUNT(sxaend_nss_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_header_fields[]={
 SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
 SX_FIELD("fdl_uncompressed_size","uint16",32,2,SX_SIZE),
 SX_FIELD("group_marker","uint32",34,4,SX_ID),
 SX_FIELD("table_size_copy","uint32",38,4,SX_SIZE),
};
static const sx_layout sxaend_dcx_ftsv_header={UINT32_C(0x6084001c),"dcx_ftsv_header",sxaend_dcx_ftsv_header_fields,SX_COUNT(sxaend_dcx_ftsv_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_table_fields[]={
 SX_FIELD("table_size","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved_4","uint32",4,4,SX_RESERVED),
 SX_FIELD("signature","uint32",8,4,SX_SIGNATURE),
 SX_FIELD("reserved_12","uint32",12,4,SX_RESERVED),
 SX_FIELD("context_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("header_size","uint16",18,2,SX_SIZE),
};
static const sx_layout sxaend_dcx_ftsv_table={UINT32_C(0x6084001d),"dcx_ftsv_table",sxaend_dcx_ftsv_table_fields,SX_COUNT(sxaend_dcx_ftsv_table_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_context_fields[]={
 SX_FIELD("context_size","uint16",0,2,SX_SIZE),
 SX_FIELD("first_symbol","uint8",2,1,SX_NONE),
 SX_FIELD("last_symbol","uint8",3,1,SX_NONE),
 SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("nodes_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("map_offset","uint16",10,2,SX_OFFSET),
};
static const sx_layout sxaend_dcx_ftsv_context={UINT32_C(0x6084001e),"dcx_ftsv_context",sxaend_dcx_ftsv_context_fields,SX_COUNT(sxaend_dcx_ftsv_context_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_leaf_bitmap_fields[]={
 SX_FIELD("dcx_ftsv_leaf_bitmap","uint8",0,0,SX_NONE),
};
static const sx_layout sxaend_dcx_ftsv_leaf_bitmap={UINT32_C(0x6084001f),"dcx_ftsv_leaf_bitmap",sxaend_dcx_ftsv_leaf_bitmap_fields,SX_COUNT(sxaend_dcx_ftsv_leaf_bitmap_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_nodes_fields[]={
 SX_FIELD("dcx_ftsv_nodes","uint8",0,0,SX_NONE),
};
static const sx_layout sxaend_dcx_ftsv_nodes={UINT32_C(0x60840020),"dcx_ftsv_nodes",sxaend_dcx_ftsv_nodes_fields,SX_COUNT(sxaend_dcx_ftsv_nodes_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_map_fields[]={
 SX_FIELD("next_context","uint16",0,2,SX_NONE),
};
static const sx_layout sxaend_dcx_ftsv_map={UINT32_C(0x60840021),"dcx_ftsv_map",sxaend_dcx_ftsv_map_fields,SX_COUNT(sxaend_dcx_ftsv_map_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_first_frame_fields[]={
 SX_FIELD("group_marker","uint32",0,4,SX_ID),
 SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxaend_dcx_ftsv_first_frame={UINT32_C(0x60840022),"dcx_ftsv_first_frame",sxaend_dcx_ftsv_first_frame_fields,SX_COUNT(sxaend_dcx_ftsv_first_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_second_group_fields[]={
 SX_FIELD("end_marker","uint32",0,4,SX_ID),
 SX_FIELD("begin_marker","uint32",4,4,SX_ID),
 SX_FIELD("table_size_copy","uint32",8,4,SX_SIZE),
};
static const sx_layout sxaend_dcx_ftsv_second_group={UINT32_C(0x60840023),"dcx_ftsv_second_group",sxaend_dcx_ftsv_second_group_fields,SX_COUNT(sxaend_dcx_ftsv_second_group_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_frame_fields[]={
 SX_FIELD("frame_marker","uint16",0,2,SX_ID),
 SX_FIELD("packed_size","uint16",2,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",4,2,SX_SIZE),
};
static const sx_layout sxaend_dcx_ftsv_frame={UINT32_C(0x60840024),"dcx_ftsv_frame",sxaend_dcx_ftsv_frame_fields,SX_COUNT(sxaend_dcx_ftsv_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_group_start_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
};
static const sx_layout sxaend_dcx_ftsv_group_start={UINT32_C(0x60840025),"dcx_ftsv_group_start",sxaend_dcx_ftsv_group_start_fields,SX_COUNT(sxaend_dcx_ftsv_group_start_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_group_end_fields[]={
 SX_FIELD("marker","uint32",0,4,SX_ID),
};
static const sx_layout sxaend_dcx_ftsv_group_end={UINT32_C(0x60840026),"dcx_ftsv_group_end",sxaend_dcx_ftsv_group_end_fields,SX_COUNT(sxaend_dcx_ftsv_group_end_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pmarc_member_fields[]={
 SX_FIELD("header_size_minus_two","uint8",0,1,SX_NONE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_ID),
 SX_FIELD("packed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_date_time","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
 SX_FIELD("header_level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
static const sx_layout sxaend_pmarc_member={UINT32_C(0x60840027),"pmarc_member",sxaend_pmarc_member_fields,SX_COUNT(sxaend_pmarc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pmarc_crc_fields[]={
 SX_FIELD("data_crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxaend_pmarc_crc={UINT32_C(0x60840028),"pmarc_crc",sxaend_pmarc_crc_fields,SX_COUNT(sxaend_pmarc_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pmarc_end_fields[]={
 SX_FIELD("end_marker","uint8",0,1,SX_ID),
};
static const sx_layout sxaend_pmarc_end={UINT32_C(0x60840029),"pmarc_end",sxaend_pmarc_end_fields,SX_COUNT(sxaend_pmarc_end_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_boo_name_fields[]={
 SX_FIELD("boo_name","char",0,0,SX_STRING),
};
static const sx_layout sxaend_boo_name={UINT32_C(0x6084002a),"boo_name",sxaend_boo_name_fields,SX_COUNT(sxaend_boo_name_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_boo_encoded_line_fields[]={
 SX_FIELD("boo_encoded_line","char",0,0,SX_NONE),
};
static const sx_layout sxaend_boo_encoded_line={UINT32_C(0x6084002b),"boo_encoded_line",sxaend_boo_encoded_line_fields,SX_COUNT(sxaend_boo_encoded_line_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_arcv2_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("volume_flags","uint32",8,4,SX_NONE),
 SX_FIELD("disk_number","uint16",12,2,SX_NONE),
};
static const sx_layout sxaend_sfx_arcv2_header={UINT32_C(0x6084002c),"sfx_arcv2_header",sxaend_sfx_arcv2_header_fields,SX_COUNT(sxaend_sfx_arcv2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_arcv2_block_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("flags","uint32",8,4,SX_NONE),
 SX_FIELD("volume_payload_size","uint32",12,4,SX_SIZE),
 SX_FIELD("name_size","uint8",16,1,SX_SIZE),
};
static const sx_layout sxaend_sfx_arcv2_block={UINT32_C(0x6084002d),"sfx_arcv2_block",sxaend_sfx_arcv2_block_fields,SX_COUNT(sxaend_sfx_arcv2_block_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_arcv2_attributes_fields[]={
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("attributes","uint32",8,4,SX_NONE),
 SX_FIELD("dos_timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("opaque","uint8[8]",16,8,SX_NONE),
 SX_FIELD("packed_crc32","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sxaend_sfx_arcv2_attributes={UINT32_C(0x6084002e),"sfx_arcv2_attributes",sxaend_sfx_arcv2_attributes_fields,SX_COUNT(sxaend_sfx_arcv2_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[2]",4,2,SX_NONE),
 SX_FIELD("version","uint16",6,2,SX_NONE),
 SX_FIELD("opaque2","uint8[18]",8,18,SX_NONE),
 SX_FIELD("volume_name_size","uint16",26,2,SX_SIZE),
};
static const sx_layout sxaend_sfx_tgcf_header={UINT32_C(0x6084002f),"sfx_tgcf_header",sxaend_sfx_tgcf_header_fields,SX_COUNT(sxaend_sfx_tgcf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_list_offset_fields[]={
 SX_FIELD("member_list_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxaend_sfx_tgcf_list_offset={UINT32_C(0x60840030),"sfx_tgcf_list_offset",sxaend_sfx_tgcf_list_offset_fields,SX_COUNT(sxaend_sfx_tgcf_list_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_crc_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxaend_sfx_tgcf_crc={UINT32_C(0x60840031),"sfx_tgcf_crc",sxaend_sfx_tgcf_crc_fields,SX_COUNT(sxaend_sfx_tgcf_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_member_prefix_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque","uint8[8]",4,8,SX_NONE),
 SX_FIELD("split_kind","uint16",12,2,SX_NONE),
 SX_FIELD("method","uint16",14,2,SX_NONE),
};
static const sx_layout sxaend_sfx_tgcf_member_prefix={UINT32_C(0x60840032),"sfx_tgcf_member_prefix",sxaend_sfx_tgcf_member_prefix_fields,SX_COUNT(sxaend_sfx_tgcf_member_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_member_attributes_fields[]={
 SX_FIELD("timestamp","uint32",0,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint32",16,4,SX_NONE),
};
static const sx_layout sxaend_sfx_tgcf_member_attributes={UINT32_C(0x60840033),"sfx_tgcf_member_attributes",sxaend_sfx_tgcf_member_attributes_fields,SX_COUNT(sxaend_sfx_tgcf_member_attributes_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_member_flag_fields[]={
 SX_FIELD("flag","uint8",0,1,SX_NONE),
};
static const sx_layout sxaend_sfx_tgcf_member_flag={UINT32_C(0x60840034),"sfx_tgcf_member_flag",sxaend_sfx_tgcf_member_flag_fields,SX_COUNT(sxaend_sfx_tgcf_member_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_tgcf_payload_offset_fields[]={
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxaend_sfx_tgcf_payload_offset={UINT32_C(0x60840035),"sfx_tgcf_payload_offset",sxaend_sfx_tgcf_payload_offset_fields,SX_COUNT(sxaend_sfx_tgcf_payload_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_imp_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("opaque","uint8[26]",12,26,SX_NONE),
 SX_FIELD("flags","uint16",38,2,SX_FLAGS),
 SX_FIELD("header_crc16","uint16",40,2,SX_CHECKSUM),
};
static const sx_layout sxaend_sfx_imp_header={UINT32_C(0x60840036),"sfx_imp_header",sxaend_sfx_imp_header_fields,SX_COUNT(sxaend_sfx_imp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_imp_directory_block_fields[]={
 SX_FIELD("signature","uint8[6]",0,6,SX_SIGNATURE),
 SX_FIELD("method_and_lengths","uint48",6,6,SX_FLAGS),
};
static const sx_layout sxaend_sfx_imp_directory_block={UINT32_C(0x60840037),"sfx_imp_directory_block",sxaend_sfx_imp_directory_block_fields,SX_COUNT(sxaend_sfx_imp_directory_block_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_cazip_header_fields[]={
 SX_FIELD("lead_in","uint8[3]",0,3,SX_SIGNATURE),
 SX_FIELD("signature","char[5]",3,5,SX_SIGNATURE),
 SX_FIELD("version","char[2]",8,2,SX_NONE),
 SX_FIELD("fixed_word","uint16",10,2,SX_NONE),
 SX_FIELD("volume_flag","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("reserved","uint8[2]",18,2,SX_NONE),
};
static const sx_layout sxaend_sfx_cazip_header={UINT32_C(0x60840038),"sfx_cazip_header",sxaend_sfx_cazip_header_fields,SX_COUNT(sxaend_sfx_cazip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_cazip_dcl_prefix_fields[]={
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxaend_sfx_cazip_dcl_prefix={UINT32_C(0x60840039),"sfx_cazip_dcl_prefix",sxaend_sfx_cazip_dcl_prefix_fields,SX_COUNT(sxaend_sfx_cazip_dcl_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_starkit_header_fields[]={
 SX_FIELD("magic","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxaend_sfx_starkit_header={UINT32_C(0x6084003a),"sfx_starkit_header",sxaend_sfx_starkit_header_fields,SX_COUNT(sxaend_sfx_starkit_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_starkit_commit_fields[]={
 SX_FIELD("commit_tag","uint32",0,4,SX_FLAGS),
 SX_FIELD("footer_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("root_size_and_tag","uint32",8,4,SX_FLAGS),
 SX_FIELD("root_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxaend_sfx_starkit_commit={UINT32_C(0x6084003b),"sfx_starkit_commit",sxaend_sfx_starkit_commit_fields,SX_COUNT(sxaend_sfx_starkit_commit_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_sfx_starkit_root_prefix_fields[]={
 SX_FIELD("root_tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("schema_size_and_tag","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxaend_sfx_starkit_root_prefix={UINT32_C(0x6084003c),"sfx_starkit_root_prefix",sxaend_sfx_starkit_root_prefix_fields,SX_COUNT(sxaend_sfx_starkit_root_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_spis_header_fields[]={
 SX_FIELD("signature","uint8[5]",0,5,SX_SIGNATURE),
 SX_FIELD("method_tag","char[3]",5,3,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("archive_type","uint8",12,1,SX_NONE),
 SX_FIELD("checksum","uint32",13,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",17,4,SX_NONE),
};
static const sx_layout sxaend_sfx_spis_header={UINT32_C(0x6084003d),"sfx_spis_header",sxaend_sfx_spis_header_fields,SX_COUNT(sxaend_sfx_spis_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_spis_member_fields[]={
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",2,4,SX_NONE),
 SX_FIELD("attributes","uint16",6,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("method","uint8",16,1,SX_NONE),
 SX_FIELD("checksum","uint32",17,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",21,4,SX_NONE),
};
static const sx_layout sxaend_sfx_spis_member={UINT32_C(0x6084003e),"sfx_spis_member",sxaend_sfx_spis_member_fields,SX_COUNT(sxaend_sfx_spis_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pfx_gemdos_header_fields[]={
 SX_FIELD("branch","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("text_size","uint32",2,4,SX_SIZE),
 SX_FIELD("data_size","uint32",6,4,SX_SIZE),
 SX_FIELD("bss_size","uint32",10,4,SX_SIZE),
 SX_FIELD("symbol_size","uint32",14,4,SX_SIZE),
 SX_FIELD("reserved","uint32",18,4,SX_RESERVED),
 SX_FIELD("flags","uint32",22,4,SX_FLAGS),
 SX_FIELD("absolute_flag","uint16",26,2,SX_FLAGS),
};
static const sx_layout sxaend_pfx_gemdos_header={UINT32_C(0x6084003f),"pfx_gemdos_header",sxaend_pfx_gemdos_header_fields,SX_COUNT(sxaend_pfx_gemdos_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaend_pfx_lha_member_fields[]={
 SX_FIELD("header_size_minus_two","uint8",0,1,SX_NONE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_ID),
 SX_FIELD("packed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_date_time","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
 SX_FIELD("header_level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
static const sx_layout sxaend_pfx_lha_member={UINT32_C(0x60840040),"pfx_lha_member",sxaend_pfx_lha_member_fields,SX_COUNT(sxaend_pfx_lha_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pfx_lha_crc_fields[]={
 SX_FIELD("data_crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxaend_pfx_lha_crc={UINT32_C(0x60840041),"pfx_lha_crc",sxaend_pfx_lha_crc_fields,SX_COUNT(sxaend_pfx_lha_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_zip_local_fields[]={
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version_needed","uint16",4,2,SX_NONE),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("method","uint16",8,2,SX_ID),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("name_size","uint16",26,2,SX_SIZE),
 SX_FIELD("extra_size","uint16",28,2,SX_SIZE),
};
static const sx_layout sxaend_sfx_zip_local={UINT32_C(0x60840042),"sfx_zip_local",sxaend_sfx_zip_local_fields,SX_COUNT(sxaend_sfx_zip_local_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_sfx_zip_extra_fields[]={
 SX_FIELD("tag","uint16",0,2,SX_ID),
 SX_FIELD("payload_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxaend_sfx_zip_extra={UINT32_C(0x60840043),"sfx_zip_extra",sxaend_sfx_zip_extra_fields,SX_COUNT(sxaend_sfx_zip_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_localzip_softpaq_table_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown_4","uint8[4]",4,4,SX_NONE),
 SX_FIELD("first_size","uint32",8,4,SX_SIZE),
 SX_FIELD("first_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("unknown_16","uint8[8]",16,8,SX_NONE),
 SX_FIELD("second_size","uint32",24,4,SX_SIZE),
 SX_FIELD("second_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("third_size","uint32",32,4,SX_SIZE),
 SX_FIELD("third_offset","uint32",36,4,SX_OFFSET),
};
static const sx_layout sxaend_localzip_softpaq_table={UINT32_C(0x60840044),"localzip_softpaq_table",sxaend_localzip_softpaq_table_fields,SX_COUNT(sxaend_localzip_softpaq_table_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_localzip_softpaq_member_fields[]={
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxaend_localzip_softpaq_member={UINT32_C(0x60840045),"localzip_softpaq_member",sxaend_localzip_softpaq_member_fields,SX_COUNT(sxaend_localzip_softpaq_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_signature_fields[]={
 SX_FIELD("signature","uint8[7]",0,7,SX_SIGNATURE),
};
static const sx_layout sxaend_rsfx_rar_signature={UINT32_C(0x60840046),"rsfx_rar_signature",sxaend_rsfx_rar_signature_fields,SX_COUNT(sxaend_rsfx_rar_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_block_fields[]={
 SX_FIELD("header_crc16","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("block_type","uint8",2,1,SX_ID),
 SX_FIELD("flags","uint16",3,2,SX_FLAGS),
 SX_FIELD("header_size","uint16",5,2,SX_SIZE),
};
static const sx_layout sxaend_rsfx_rar_block={UINT32_C(0x60840047),"rsfx_rar_block",sxaend_rsfx_rar_block_fields,SX_COUNT(sxaend_rsfx_rar_block_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_main_fields[]={
 SX_FIELD("reserved_low","uint16",0,2,SX_RESERVED),
 SX_FIELD("reserved_high","uint32",2,4,SX_RESERVED),
};
static const sx_layout sxaend_rsfx_rar_main={UINT32_C(0x60840048),"rsfx_rar_main",sxaend_rsfx_rar_main_fields,SX_COUNT(sxaend_rsfx_rar_main_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_file_fields[]={
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("host_os","uint8",8,1,SX_ID),
 SX_FIELD("file_crc32","uint32",9,4,SX_CHECKSUM),
 SX_FIELD("dos_timestamp","uint32",13,4,SX_NONE),
 SX_FIELD("unpack_version","uint8",17,1,SX_NONE),
 SX_FIELD("method","uint8",18,1,SX_ID),
 SX_FIELD("name_size","uint16",19,2,SX_SIZE),
 SX_FIELD("attributes","uint32",21,4,SX_FLAGS),
};
static const sx_layout sxaend_rsfx_rar_file={UINT32_C(0x60840049),"rsfx_rar_file",sxaend_rsfx_rar_file_fields,SX_COUNT(sxaend_rsfx_rar_file_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_rsfx_rar_service_size_fields[]={
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxaend_rsfx_rar_service_size={UINT32_C(0x6084004a),"rsfx_rar_service_size",sxaend_rsfx_rar_service_size_fields,SX_COUNT(sxaend_rsfx_rar_service_size_fields),SX_LE};
static const sx_layout *const sx_archiveend_layouts[]={
 &sxaend_archiveend_name,
 &sxaend_archiveend_comment,
 &sxaend_sds_sfx_member,
 &sxaend_lhpak_sfx_position,
 &sxaend_lhpak_sfx_member,
 &sxaend_lhpak_sfx_block,
 &sxaend_lhsfx_control,
 &sxaend_lhsfx_member,
 &sxaend_omni_mode,
 &sxaend_omni_comment_size,
 &sxaend_omni_name_size,
 &sxaend_omni_data_size,
 &sxaend_omni_member_tail,
 &sxaend_omni_lh_block,
 &sxaend_diet_data_v100,
 &sxaend_diet_data_v102,
 &sxaend_diet_data_v144,
 &sxaend_diet_data_lengths,
 &sxaend_dclraw_stream,
 &sxaend_copyqm_tx_header,
 &sxaend_copyqm_tx_leaf,
 &sxaend_copyqm_tx_branch,
 &sxaend_copyqm_tx_screen6,
 &sxaend_copyqm_tx_screen8,
 &sxaend_copyqm_tx_geometry,
 &sxaend_copyqm_tx_line,
 &sxaend_nss_member,
 &sxaend_dcx_ftsv_header,
 &sxaend_dcx_ftsv_table,
 &sxaend_dcx_ftsv_context,
 &sxaend_dcx_ftsv_leaf_bitmap,
 &sxaend_dcx_ftsv_nodes,
 &sxaend_dcx_ftsv_map,
 &sxaend_dcx_ftsv_first_frame,
 &sxaend_dcx_ftsv_second_group,
 &sxaend_dcx_ftsv_frame,
 &sxaend_dcx_ftsv_group_start,
 &sxaend_dcx_ftsv_group_end,
 &sxaend_pmarc_member,
 &sxaend_pmarc_crc,
 &sxaend_pmarc_end,
 &sxaend_boo_name,
 &sxaend_boo_encoded_line,
 &sxaend_sfx_arcv2_header,
 &sxaend_sfx_arcv2_block,
 &sxaend_sfx_arcv2_attributes,
 &sxaend_sfx_tgcf_header,
 &sxaend_sfx_tgcf_list_offset,
 &sxaend_sfx_tgcf_crc,
 &sxaend_sfx_tgcf_member_prefix,
 &sxaend_sfx_tgcf_member_attributes,
 &sxaend_sfx_tgcf_member_flag,
 &sxaend_sfx_tgcf_payload_offset,
 &sxaend_sfx_imp_header,
 &sxaend_sfx_imp_directory_block,
 &sxaend_sfx_cazip_header,
 &sxaend_sfx_cazip_dcl_prefix,
 &sxaend_sfx_starkit_header,
 &sxaend_sfx_starkit_commit,
 &sxaend_sfx_starkit_root_prefix,
 &sxaend_sfx_spis_header,
 &sxaend_sfx_spis_member,
 &sxaend_pfx_gemdos_header,
 &sxaend_pfx_lha_member,
 &sxaend_pfx_lha_crc,
 &sxaend_sfx_zip_local,
 &sxaend_sfx_zip_extra,
 &sxaend_localzip_softpaq_table,
 &sxaend_localzip_softpaq_member,
 &sxaend_rsfx_rar_signature,
 &sxaend_rsfx_rar_block,
 &sxaend_rsfx_rar_main,
 &sxaend_rsfx_rar_file,
 &sxaend_rsfx_rar_service_size,
};
static bool sx_archiveend_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60840000U||id>=0x60850000U)return true;const wchar_t*text=NULL;switch(id){
 case 0x60840003U:text=L"Checksum is the low 16 bits of the sum of decoded bytes. A zero first name byte marks the final 30-byte record.";break;
 case 0x60840004U:text=L"First member offset = 128 + 4*archive_offset_longs, relative to the carrier start.";break;
 case 0x60840005U:text=L"Header checksum makes the sum of all big-endian header words zero. Name/comment lengths are four-byte units. Block displacement is relative to this header; zero is the final archive block.";break;
 case 0x60840006U:text=L"Continuation header is 20 bytes. Next displacement is relative to this block; zero marks the final archive block.";break;
 case 0x60840007U:text=L"0xFFFFFFFF ends the archive; otherwise followed by a 60-byte member header.";break;
 case 0x60840009U:text=L"Mode 1 has a length-prefixed archive comment before members.";break;
 case 0x6084000bU:text=L"Zero terminates the archive.";break;
 case 0x6084000dU:text=L"Physical two-byte trailer; native reader does not interpret it.";break;
 case 0x6084000eU:text=L"CRC32 uses the native raw initial-zero convention. Other member payloads are stored bytes.";break;
 case 0x6084000fU:text=L"Data-file v1.00 exit instructions and compressed-stream CRC16/ARC. Native reports but does not enforce the stored CRC.";break;
 case 0x60840012U:text=L"Packed length=((first&15)<<16)|packed_size_low. Plain length=((uncompressed_size_high>>2)<<16)|uncompressed_size_low. High first nibble is flags; 0x80 continuation is outside native scope.";break;
 case 0x60840013U:text=L"Mode 0=fixed literals, 1=coded literals. Dictionary selector 4/5/6 means 1/2/4 KiB. The authenticated native decoder determines each stream end.";break;
 case 0x60840014U:text=L"TX body size excludes the first ten bytes. Native supports six- and eight-byte screen directory rows.";break;
 case 0x60840015U:text=L"Zero marker means a decoded byte symbol; 0x0A ends a display line.";break;
 case 0x60840016U:text=L"One-based node indices; the last node is the Huffman root.";break;
 case 0x60840017U:text=L"Offset is relative to the TX compressed line-data area.";break;
 case 0x60840018U:text=L"Offset is relative to the TX compressed line-data area.";break;
 case 0x60840019U:text=L"Three equal nonzero producer geometry words; their screen-unit meaning is not assumed.";break;
 case 0x6084001aU:text=L"Total stored line size includes this one-byte prefix; following bits encode display characters and controls.";break;
 case 0x6084001bU:text=L"Norton Secret Stuff stores encrypted member bodies, in eight-byte blocks. Compression 0=stored, nonzero=compressed. Only serialized header fields are shown; ciphertext remains raw.";break;
 case 0x6084001eU:text=L"Node/map offsets are relative to this context header. Map entries select contexts; zero map_offset uses context zero.";break;
 case 0x6084001fU:text=L"Leaf flags for the Huffman node slots; bit index is the node index.";break;
 case 0x60840020U:text=L"A leaf slot holds a symbol; a branch slot holds child index/2; zero branch child is an end code.";break;
 case 0x60840021U:text=L"Context index selected after decoding the corresponding symbol.";break;
 case 0x60840027U:text=L"Total header size=first byte+2. Header checksum is byte sum from method through header end modulo256. DOS date/time is packed, not Unix seconds.";break;
 case 0x6084002bU:text=L"Six-bit characters encode decoded bytes. Tilde followed by an encoded count expands a zero run; no decoded-byte coordinates are invented.";break;
 case 0x6084002cU:text=L"Physical arcv2 header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084002dU:text=L"Physical arcv2 block inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084002eU:text=L"Physical arcv2 attributes inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084002fU:text=L"Physical tgcf header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840030U:text=L"Physical tgcf list offset inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840031U:text=L"Physical tgcf crc inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840032U:text=L"Physical tgcf member prefix inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840033U:text=L"Physical tgcf member attributes inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840034U:text=L"Physical tgcf member flag inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840035U:text=L"Physical tgcf payload offset inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840036U:text=L"Physical imp header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840037U:text=L"Physical imp directory block inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840038U:text=L"Physical cazip header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x60840039U:text=L"Physical cazip dcl prefix inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003aU:text=L"Physical starkit header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003bU:text=L"Physical starkit commit inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003cU:text=L"Physical starkit root prefix inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003dU:text=L"Physical spis header inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003eU:text=L"Physical spis member inside the authenticated carrier. Offsets retain the inner archive coordinate system. Encoded payload and unmodeled optional tables remain raw.";break;
 case 0x6084003fU:text=L"GEMDOS sizes are bytes. Physical archive starts at 28+text_size and is bounded by data_size.";break;
 case 0x60840040U:text=L"LArc PFX level0 LZ5/LH1 header. Stored packed length may exceed the authenticated DATA segment in known producer variants; its encoded value is preserved. DOS timestamp/attributes remain encoded.";break;
 case 0x60840041U:text=L"Known PFX LZ5 producer variants do not enforce the stored CRC; no checksum verification is implied by this field role.";break;
 case 0x60840043U:text=L"ZIP extra-field TLV header; unknown field payload remains raw.";break;
 case 0x60840044U:text=L"All three contiguous stored-member offsets are relative to the outer executable start.";break;
 case 0x60840047U:text=L"Original physical RAR1.5 header bytes are retained. The native extractor may repair known producer CRC/solid flags in its private decoded view only.";break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAEND_LIMIT 20000U
static bool sxaend_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxaend_read(sx_context*c,uint64_t p,void*b,size_t n){return sxaend_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxaend_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxaend_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxaend_read(c,p,b,n))return false;*v=sxaend_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxaend_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXAEND_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxaend_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxaend_add(sx_context*c,const sx_layout*l,uint64_t p){return sxaend_put(c,l,p,0,false);}
static bool sxaend_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxaend_put(c,l,p,n,aliases);}
static int sxaend_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxaend_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxaend_order);return !c->failed;}
static bool sxaend_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxaend_add(c,l,p+i*width))return false;return true;}
static bool sxaend_line(sx_context*c,uint64_t p,uint8_t*b,size_t cap,size_t*n,uint64_t*next){*n=0;uint64_t q=p;while(q<(uint64_t)c->size){uint8_t x;if(!sxaend_read(c,q,&x,1))return false;q++;if(x=='\r'||x=='\n'){if(x=='\r'&&q<(uint64_t)c->size){uint8_t y;if(!sxaend_read(c,q,&y,1))return false;if(y=='\n')q++;}*next=q;return true;}if(*n>=cap)return false;b[(*n)++]=x;}*next=q;return q>p;}
static bool sxaend_name(sx_context*c,uint64_t p,uint64_t n){return sxaend_text(c,&sxaend_archiveend_name,p,n,false);}


static bool sxaend_sds(sx_context*c){uint64_t p=0x41c;for(unsigned i=0;i<SXAEND_LIMIT;i++){uint8_t h[30];if(!sxaend_read(c,p,h,30)||!sxaend_add(c,&sxaend_sds_sfx_member,p))return false;if(!h[0])return true;uint64_t z=sxaend_uint(h+20,4,true);if(!sxaend_span(c,p+30,z))return false;p+=30+z;}return true;}
static bool sxaend_lhsfx(sx_context*c){uint64_t p=0x918,z,t;for(unsigned i=0;i<SXAEND_LIMIT;i++){if(!sxaend_word(c,p,4,true,&t)||!sxaend_add(c,&sxaend_lhsfx_control,p))return false;p+=4;if(t==UINT32_MAX)return true;if(!sxaend_add(c,&sxaend_lhsfx_member,p)||!sxaend_word(c,p+4,4,true,&z)||!sxaend_span(c,p+60,z))return false;p+=60+z;}return true;}
static bool sxaend_lhpak(sx_context*c){uint64_t p,x;if(!sxaend_word(c,20,4,true,&x)||x>(UINT64_MAX-128)/4||!sxaend_add(c,&sxaend_lhpak_sfx_position,20))return false;p=128+4*x;for(unsigned i=0;i<SXAEND_LIMIT;i++){uint8_t h[44];if(!sxaend_read(c,p,h,44))return false;uint64_t total=sxaend_uint(h+24,4,true),done=0,hs=44+4*(h[42]+h[43]),header=p;if(!sxaend_span(c,p,hs)||!sxaend_add(c,&sxaend_lhpak_sfx_member,p)||!sxaend_name(c,p+44,4*h[42])||!sxaend_text(c,&sxaend_archiveend_comment,p+44+4*h[42],4*h[43],false))return false;for(unsigned j=0;j<SXAEND_LIMIT;j++){uint8_t b[20];if(!sxaend_read(c,header,b,20))return false;uint64_t step=sxaend_uint(b,4,true),packed=sxaend_uint(b+4,2,true),plain=sxaend_uint(b+8,4,true);if(!plain||done>total||plain>total-done||!sxaend_span(c,header+hs,packed))return false;done+=plain;uint64_t next=header+hs+packed;if(step){if(step<hs||packed>step-hs||!sxaend_span(c,header,step))return false;next=header+step;}if(done==total){if(!step)return true;p=next;break;}if(!step||!sxaend_add(c,&sxaend_lhpak_sfx_block,next))return false;header=next;hs=20;if(j+1==SXAEND_LIMIT)return true;}}return true;}
static bool sxaend_omni(sx_context*c){uint64_t tag,p,mode,z;if(!sxaend_word(c,0x208,4,true,&tag))return false;p=tag==0x51cdfffc?0x7a8:tag==0x76002c7a?0x744:0;if(!p||!sxaend_word(c,p,2,true,&mode)||!sxaend_add(c,&sxaend_omni_mode,p))return false;p+=2;if(mode==1){if(!sxaend_word(c,p,2,true,&z)||!sxaend_add(c,&sxaend_omni_comment_size,p)||!sxaend_span(c,p+2,z)||!sxaend_text(c,&sxaend_archiveend_comment,p+2,z,false))return false;p+=2+z;}for(unsigned i=0;i<SXAEND_LIMIT;i++){if(!sxaend_word(c,p,2,true,&z)||!sxaend_add(c,&sxaend_omni_name_size,p))return false;p+=2;if(!z)return true;if(!sxaend_span(c,p,z)||!sxaend_name(c,p,z))return false;p+=z;if(!sxaend_word(c,p,4,true,&z)||!sxaend_add(c,&sxaend_omni_data_size,p)||!sxaend_span(c,p+4,z+2))return false;p+=4;uint8_t h[14];if(z>=14&&sxaend_read(c,p,h,14)&&h[0]=='L'&&h[1]=='H'&&!h[2]&&!h[6]&&sxaend_uint(h+6,4,true)==z-14&&!sxaend_add(c,&sxaend_omni_lh_block,p))return false;p+=z;if(!sxaend_add(c,&sxaend_omni_member_tail,p))return false;p+=2;}return true;}
static bool sxaend_nss(sx_context*c){uint8_t h[64];if(!sxaend_read(c,0,h,64)||h[0]!='M'||h[1]!='Z')return false;uint64_t pages=sxaend_uint(h+4,2,false),last=sxaend_uint(h+2,2,false);if(!pages||last>511)return false;uint64_t p=(pages-1)*512+(last?last:512);for(unsigned i=0;p<(uint64_t)c->size&&i<SXAEND_LIMIT;i++){uint8_t b[316];if(!sxaend_read(c,p,b,316)||sxaend_uint(b,2,false)!=316||xx_rt_memcmp(b+30,"CCRITTER",8)||!sxaend_add(c,&sxaend_nss_member,p))return false;uint64_t z=sxaend_uint(b+2,4,false);if(!z||!sxaend_span(c,p+316,z))return false;p+=316+z;}return true;}
static bool sxaend_diet(sx_context*c){uint8_t h[9];if(!sxaend_read(c,0,h,8))return false;uint64_t p=0;if(!xx_rt_memcmp(h,"\x9d\x89" "dlz",5)){if(!sxaend_add(c,&sxaend_diet_data_v102,0))return false;p=5;}else if(!xx_rt_memcmp(h,"\xb4\x4c\xcd\x21\x9d\x89",6)){if(sxaend_read(c,6,h,3)&&!xx_rt_memcmp(h,"dlz",3)){if(!sxaend_add(c,&sxaend_diet_data_v144,0))return false;p=9;}else return sxaend_add(c,&sxaend_diet_data_v100,0);}else return false;return sxaend_add(c,&sxaend_diet_data_lengths,p);}
static bool sxaend_dcl(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXAEND_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;if(r->header_offset<f->base_address||r->compressed_size<2||!sxaend_span(c,(uint64_t)(r->header_offset-f->base_address),(uint64_t)r->compressed_size)||!sxaend_add(c,&sxaend_dclraw_stream,(uint64_t)(r->header_offset-f->base_address))){ok=false;break;}if(!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);return ok;}
static bool sxaend_boo(sx_context*c){uint8_t b[4096];size_t n;uint64_t p=0,next;if(!sxaend_line(c,0,b,sizeof(b),&n,&next)||n<3||n>12||!sxaend_text(c,&sxaend_boo_name,0,n,false))return false;p=next;for(unsigned i=0;p<(uint64_t)c->size&&i<SXAEND_LIMIT;i++){if(!sxaend_line(c,p,b,sizeof(b),&n,&next)||next<=p)return false;if(n&&!sxaend_text(c,&sxaend_boo_encoded_line,p,n,false))return false;p=next;}return true;}
static bool sxaend_copyqm(sx_context*c){uint8_t h[64];if(!sxaend_read(c,0,h,64)||h[0]!='M'||h[1]!='Z')return false;uint64_t pages=sxaend_uint(h+4,2,false),last=sxaend_uint(h+2,2,false);if(!pages||last>511)return false;uint64_t start=(pages-1)*512+(last?last:512);if(!sxaend_read(c,start,h,12)||h[0]!='T'||h[1]!='X')return false;uint64_t nc=sxaend_uint(h+2,2,false),sc=sxaend_uint(h+4,2,false),body=sxaend_uint(h+6,4,false);if(nc<3||nc>255||!(nc&1)||!sc||sc>1000||!sxaend_span(c,start,10+body)||!sxaend_add(c,&sxaend_copyqm_tx_header,start))return false;uint64_t end=start+10+body,dir=start+12+2*nc,data=0,stride=0;for(unsigned z=6;z<=8;z+=2){uint64_t begin=dir+sc*z,prev=0;bool valid=begin<end;for(uint64_t i=0;valid&&i<sc;i++){uint64_t lines=0,off=0;if(!sxaend_word(c,dir+i*z+(z==8?2:0),2,false,&lines)||!sxaend_word(c,dir+i*z+(z==8?4:2),4,false,&off)||!lines||off>=end-begin||(i&&off<=prev))valid=false;prev=off;}if(valid){if(stride)return false;stride=z;data=begin;}}if(!stride)return false;for(uint64_t i=0;i<nc;i++){uint64_t v;if(!sxaend_word(c,start+12+i*2,1,false,&v)||!sxaend_add(c,v?&sxaend_copyqm_tx_branch:&sxaend_copyqm_tx_leaf,start+12+i*2))return false;}for(uint64_t i=0;i<sc;i++){uint64_t row=dir+i*stride,n,off,limit=end;if(!sxaend_add(c,stride==6?&sxaend_copyqm_tx_screen6:&sxaend_copyqm_tx_screen8,row)||!sxaend_word(c,row+(stride==8?2:0),2,false,&n)||!sxaend_word(c,row+(stride==8?4:2),4,false,&off))return false;if(i==0&&off==6&&!sxaend_add(c,&sxaend_copyqm_tx_geometry,data))return false;if(i+1<sc){uint64_t q;if(!sxaend_word(c,row+stride+(stride==8?4:2),4,false,&q))return false;limit=data+q;}uint64_t p=data+off;for(uint64_t j=0;j<n&&j<SXAEND_LIMIT;j++){uint64_t z;if(p>=limit||!sxaend_word(c,p,1,false,&z)||z<2||z>limit-p||!sxaend_add(c,&sxaend_copyqm_tx_line,p))return false;p+=z;}}return true;}
/* Consume only the original reader's authenticated first physical member. */
static bool sxaend_first_source(sx_context*c,uint64_t*at,uint64_t*size){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;const xx_archive_record*r=(f->get_current_archive_record)(f,s);bool ok=r&&r->data_offset>=f->base_address&&r->compressed_size>0;if(ok){*at=(uint64_t)(r->data_offset-f->base_address);*size=(uint64_t)r->compressed_size;ok=sxaend_span(c,*at,*size);}(f->free_archive_records_reading)(f,s);return ok;}
static bool sxaend_pmarc(sx_context*c){uint64_t p,n;if(!sxaend_first_source(c,&p,&n))return false;uint64_t end=p+n;for(unsigned i=0;p<end&&i<SXAEND_LIMIT;i++){uint8_t h[22];if(!sxaend_read(c,p,h,1))return false;if(!h[0])return sxaend_add(c,&sxaend_pmarc_end,p);uint64_t z=h[0]+2;if(z<24||z>end-p||!sxaend_read(c,p,h,22)||z<24+h[21]||xx_rt_memcmp(h+2,"-pm",3)||!sxaend_add(c,&sxaend_pmarc_member,p)||!sxaend_name(c,p+22,h[21])||!sxaend_add(c,&sxaend_pmarc_crc,p+22+h[21]))return false;uint64_t packed=sxaend_uint(h+7,4,false);if(packed>end-p-z)return false;p+=z+packed;}return true;}
static bool sxaend_dcx_table(sx_context*c,uint64_t p,uint64_t*end,bool emit){uint8_t h[20];if(!sxaend_read(c,p,h,20))return false;uint64_t z=sxaend_uint(h,4,false),n=sxaend_uint(h+16,2,false);if(z<20||z>1048576||!n||n>256||!sxaend_span(c,p,z)||sxaend_uint(h+8,4,false)!=0x5bf5a3a7||sxaend_uint(h+18,2,false)!=20)return false;if(emit&&!sxaend_add(c,&sxaend_dcx_ftsv_table,p))return false;*end=p+z;p+=20;for(uint64_t i=0;i<n;i++){uint8_t b[12];if(*end-p<12||!sxaend_read(c,p,b,12))return false;uint64_t len=sxaend_uint(b,2,false),nodes=sxaend_uint(b+8,2,false),map=sxaend_uint(b+10,2,false),nodeend=map?map:len;if(len>*end-p||nodes<=12||nodes-12>64||nodeend<=nodes||nodeend>len||nodeend-nodes>512||b[2]>b[3]||(map&&len-map!=2*(uint64_t)(b[3]-b[2]+1)))return false;if(emit&&(!sxaend_add(c,&sxaend_dcx_ftsv_context,p)||!sxaend_text(c,&sxaend_dcx_ftsv_leaf_bitmap,p+12,nodes-12,false)||!sxaend_text(c,&sxaend_dcx_ftsv_nodes,p+nodes,nodeend-nodes,false)||(map&&!sxaend_table(c,&sxaend_dcx_ftsv_map,p+map,2,b[3]-b[2]+1))))return false;p+=len;}return p==*end;}
static bool sxaend_dcx(sx_context*c){uint64_t payload,payloadz;if(!sxaend_first_source(c,&payload,&payloadz))return false;uint64_t cap=(uint64_t)c->size<1048576?(uint64_t)c->size:1048576;for(uint64_t p=0;p+42<=cap;p++){uint8_t h[42];if((p&4095)==0&&xx_pd_is_stopped(c->pd))return false;if(!sxaend_read(c,p,h,1))return false;if(h[0]!='O')continue;if(!sxaend_read(c,p,h,42)||xx_rt_memcmp(h,"OpenVMS DCX FTSV Compressed File",32))continue;uint64_t end;if(!sxaend_dcx_table(c,p+42,&end,false)||end+8!=payload)continue;if(!sxaend_add(c,&sxaend_dcx_ftsv_header,p)||!sxaend_dcx_table(c,p+42,&end,true)||!sxaend_add(c,&sxaend_dcx_ftsv_first_frame,end))return false;uint64_t next=payload+payloadz;if(!sxaend_add(c,&sxaend_dcx_ftsv_second_group,next)||!sxaend_dcx_table(c,next+12,&end,true)||!sxaend_add(c,&sxaend_dcx_ftsv_group_start,end))return false;end+=2;for(unsigned i=0;end+4<(uint64_t)c->size&&i<SXAEND_LIMIT;i++){uint64_t z;if(!sxaend_word(c,end+2,2,false,&z)||!z||!sxaend_span(c,end+6,z)||!sxaend_add(c,&sxaend_dcx_ftsv_frame,end))return false;end+=6+z;}return end+4==(uint64_t)c->size&&sxaend_add(c,&sxaend_dcx_ftsv_group_end,end);}return false;}

static bool sxaend_arcv2(sx_context*c,uint64_t p,uint64_t z){uint64_t end=p+z;if(z<14||!sxaend_add(c,&sxaend_sfx_arcv2_header,p))return false;p+=14;for(unsigned i=0;p<end&&i<SXAEND_LIMIT;i++){uint8_t h[17];if(end-p<17||!sxaend_read(c,p,h,17)||xx_rt_memcmp(h,"BLCK",4))return false;uint64_t hs=sxaend_uint(h+6,2,false),n=sxaend_uint(h+12,4,false);if(hs!=45U+h[16]||hs>end-p||n>end-p-hs||!sxaend_add(c,&sxaend_sfx_arcv2_block,p)||!sxaend_name(c,p+17,h[16])||!sxaend_add(c,&sxaend_sfx_arcv2_attributes,p+17+h[16]))return false;p+=hs+n;}return true;}
static bool sxaend_imp(sx_context*c,uint64_t base,uint64_t z){uint64_t rel,n;if(z<42||!sxaend_word(c,base+4,4,false,&rel)||!sxaend_word(c,base+8,4,false,&n)||rel>z||!sxaend_add(c,&sxaend_sfx_imp_header,base))return false;uint64_t p=base+rel,end=base+z;for(unsigned i=0;p<end&&i<SXAEND_LIMIT;i++){uint8_t h[12];if(end-p<12||!sxaend_read(c,p,h,12)||xx_rt_memcmp(h,"IMPDE\0",6)||!sxaend_add(c,&sxaend_sfx_imp_directory_block,p))return false;uint64_t bits=sxaend_uint(h+6,6,false),packed=(bits>>25)&0xfffff;if(packed<6||packed>end-p-6)return false;p+=6+packed;}return true;}
static bool sxaend_starkit(sx_context*c,uint64_t p,uint64_t z){uint64_t n,off;if(z<24||!sxaend_add(c,&sxaend_sfx_starkit_header,p)||!sxaend_add(c,&sxaend_sfx_starkit_commit,p+z-16)||!sxaend_word(c,p+z-8,4,true,&n)||!sxaend_word(c,p+z-4,4,true,&off))return false;n&=0x7fffffff;if(n<2||off>z||n>z-off)return true;uint8_t b[2];if(!sxaend_read(c,p+off,b,2)||b[0]!=128||!(b[1]&128))return true;if(!sxaend_add(c,&sxaend_sfx_starkit_root_prefix,p+off))return false;uint64_t len=b[1]&127;return len<=n-2?sxaend_text(c,&sxaend_archiveend_comment,p+off+2,len,false):true;}
static bool sxaend_zip_record(sx_context*c,uint64_t p,uint64_t z){uint8_t h[30];if(z<30||!sxaend_read(c,p,h,30)||xx_rt_memcmp(h,"PK\3\4",4))return false;uint64_t n=sxaend_uint(h+26,2,false),extra=sxaend_uint(h+28,2,false);if(n>z-30||extra>z-30-n||!sxaend_add(c,&sxaend_sfx_zip_local,p)||!sxaend_name(c,p+30,n))return false;uint64_t q=p+30+n,end=q+extra;while(q+4<=end){uint64_t a;if(!sxaend_word(c,q+2,2,false,&a)||a>end-q-4)break;if(!sxaend_add(c,&sxaend_sfx_zip_extra,q))return false;q+=4+a;}return true;}
static bool sxaend_tgcf_record(sx_context*c,uint64_t p,uint64_t z){uint8_t h[36];if(z<43||!sxaend_read(c,p,h,36)||xx_rt_memcmp(h,"TGCF",4)||!sxaend_add(c,&sxaend_sfx_tgcf_member_prefix,p)||!sxaend_add(c,&sxaend_sfx_tgcf_member_attributes,p+16))return false;uint64_t q=p+36,end=p+z;for(unsigned n=0;n<2;n++){uint64_t start=q;uint8_t ch;while(q<end){if(!sxaend_read(c,q++,&ch,1))return false;if(!ch)break;}if(q==end||!sxaend_name(c,start,q-start))return false;}if(end-q!=5&&end-q!=9)return false;if(!sxaend_add(c,&sxaend_sfx_tgcf_member_flag,q++))return false;if(end-q==8){if(!sxaend_add(c,&sxaend_sfx_tgcf_payload_offset,q))return false;q+=4;}return sxaend_add(c,&sxaend_sfx_tgcf_crc,q);}
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif
static bool sxaend_tgcf_header(sx_context*c,uint64_t first){
#if SX_ALIAS_READER_FACTORY
 int64_t at,z;if(!xx_sfx_tgcf_get_payload_span(c->f,&at,&z,c->pd)||at<c->f->base_address||z<28)return true;
 uint64_t p=(uint64_t)(at-c->f->base_address),end=p+(uint64_t)z;uint8_t h[28];
 if(!sxaend_span(c,p,(uint64_t)z)||!sxaend_read(c,p,h,28)||xx_rt_memcmp(h,"TGCF",4))return true;
 uint64_t ver=sxaend_uint(h+6,2,true),n=sxaend_uint(h+26,2,true),list,q=p+28+n;
 if((ver!=0x130&&ver!=0x140&&ver!=0x160)||!n||n>1024||q>end||(ver>=0x160?8U:4U)>end-q)return true;
 if(ver>=0x160){if(!sxaend_word(c,q,4,true,&list)||list>(uint64_t)z||p+list!=first)return true;}else if(q+4!=first)return true;
 if(!sxaend_add(c,&sxaend_sfx_tgcf_header,p)||!sxaend_name(c,p+28,n))return false;
 if(ver>=0x160){if(!sxaend_add(c,&sxaend_sfx_tgcf_list_offset,q))return false;q+=4;}
 return sxaend_add(c,&sxaend_sfx_tgcf_crc,q);
#else
 (void)c;(void)first;return true;
#endif
}
static bool sxaend_carrier_records(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXAEND_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;uint64_t p=0,z=0;bool header=r->header_offset>=f->base_address&&r->header_size>0;if(header){p=(uint64_t)(r->header_offset-f->base_address);z=(uint64_t)r->header_size;header=sxaend_span(c,p,z);}switch(f->file_type){case XX_FILE_TYPE_SFX_ARCV2:case XX_FILE_TYPE_SFX_IMP:case XX_FILE_TYPE_SFX_CAZIP:case XX_FILE_TYPE_SFX_STARKIT:if(r->data_offset<f->base_address||r->compressed_size<=0){ok=false;break;}p=(uint64_t)(r->data_offset-f->base_address);z=(uint64_t)r->compressed_size;if(!sxaend_span(c,p,z)){ok=false;break;}ok=f->file_type==XX_FILE_TYPE_SFX_ARCV2?sxaend_arcv2(c,p,z):f->file_type==XX_FILE_TYPE_SFX_IMP?sxaend_imp(c,p,z):f->file_type==XX_FILE_TYPE_SFX_STARKIT?sxaend_starkit(c,p,z):z>=24&&sxaend_add(c,&sxaend_sfx_cazip_header,p)&&sxaend_add(c,&sxaend_sfx_cazip_dcl_prefix,p+20);break;
 case XX_FILE_TYPE_SFX_TGCF:if(header){if(!i)ok=sxaend_tgcf_header(c,p);if(ok)ok=sxaend_tgcf_record(c,p,z);}break;
 case XX_FILE_TYPE_SFX_SPIS:if(!i){uint64_t start=0;bool candidate=false;if(header&&p>=21){start=p-21;candidate=true;}else if(!header&&r->data_offset>=f->base_address&&r->compressed_size>=21){start=(uint64_t)(r->data_offset-f->base_address);candidate=sxaend_span(c,start,(uint64_t)r->compressed_size);}if(candidate){uint8_t blob[21];if(sxaend_read(c,start,blob,21)&&!xx_rt_memcmp(blob,"SPIS\032",5)&&blob[12]==1&&!sxaend_add(c,&sxaend_sfx_spis_header,start)){ok=false;break;}}}if(header){uint8_t h[25];if(z==21&&sxaend_read(c,p,h,5)&&!xx_rt_memcmp(h,"SPIS\032",5))ok=sxaend_add(c,&sxaend_sfx_spis_header,p);else if(z>=25&&sxaend_read(c,p,h,25)&&sxaend_uint(h,2,false)==z-25)ok=sxaend_add(c,&sxaend_sfx_spis_member,p)&&sxaend_name(c,p+25,z-25);}break;
 case XX_FILE_TYPE_SFX_LOCALZIP:if(header){uint8_t h[4];if(z>=30&&sxaend_read(c,p,h,4)&&!xx_rt_memcmp(h,"PK\3\4",4))ok=sxaend_zip_record(c,p,z);else if(z>=2){uint64_t n;if(sxaend_word(c,p,1,false,&n)&&n==z-1)ok=sxaend_add(c,&sxaend_localzip_softpaq_member,p)&&sxaend_name(c,p+1,n);}}break;
 case XX_FILE_TYPE_LARC_PFX:if(header){uint8_t h[22];if(z<24||!sxaend_read(c,p,h,22)||h[0]+2!=z||h[21]>z-24){ok=false;break;}ok=sxaend_add(c,&sxaend_pfx_lha_member,p)&&sxaend_name(c,p+22,h[21])&&sxaend_add(c,&sxaend_pfx_lha_crc,p+22+h[21]);}break;default:ok=false;break;}if(!ok||!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);return ok;}
static bool sxaend_localzip(sx_context*c){uint64_t cap=(uint64_t)c->size<131072?(uint64_t)c->size:131072;for(uint64_t p=0;p+40<=cap;p++){uint8_t h[40];if((p&4095)==0&&xx_pd_is_stopped(c->pd))return false;if(!sxaend_read(c,p,h,1))return false;if(h[0]!='!')continue;if(!sxaend_read(c,p,h,40)||xx_rt_memcmp(h,"!3PS",4))continue;uint64_t a=sxaend_uint(h+12,4,false),az=sxaend_uint(h+8,4,false),b=sxaend_uint(h+28,4,false),bz=sxaend_uint(h+24,4,false),d=sxaend_uint(h+36,4,false),dz=sxaend_uint(h+32,4,false);if(a>=p+40&&sxaend_span(c,a,az)&&b==a+az&&sxaend_span(c,b,bz)&&d==b+bz&&sxaend_span(c,d,dz)&&d+dz==(uint64_t)c->size&&!sxaend_add(c,&sxaend_localzip_softpaq_table,p))return false;break;}return sxaend_carrier_records(c);}
static bool sxaend_rsfx(sx_context*c){uint64_t lx,p,cap=(uint64_t)c->size<1048576?(uint64_t)c->size:1048576;uint8_t h[32];if(!sxaend_word(c,60,4,false,&lx)||lx<64||lx+2>cap||!sxaend_read(c,lx,h,2)||xx_rt_memcmp(h,"LX",2))return false;for(p=lx+2;p+7<=cap;p++){if((p&4095)==0&&xx_pd_is_stopped(c->pd))return false;if(!sxaend_read(c,p,h,7))return false;if(!xx_rt_memcmp(h,"Rar!\032\7\0",7))break;}if(p+7>cap||!sxaend_add(c,&sxaend_rsfx_rar_signature,p))return false;p+=7;for(unsigned i=0;p<(uint64_t)c->size&&i<SXAEND_LIMIT;i++){if(!sxaend_read(c,p,h,7))return false;uint64_t flags=sxaend_uint(h+3,2,false),z=sxaend_uint(h+5,2,false),packed=0;if(z<7||!sxaend_span(c,p,z)||!sxaend_add(c,&sxaend_rsfx_rar_block,p))return false;if(flags&0x8000){if(z<11||!sxaend_word(c,p+7,4,false,&packed))return false;}if(h[2]==0x73){if(z<13||!sxaend_add(c,&sxaend_rsfx_rar_main,p+7))return false;}else if(h[2]==0x74){uint64_t names;if(z<32||!sxaend_word(c,p+26,2,false,&names)||names>z-32||!sxaend_add(c,&sxaend_rsfx_rar_file,p+7)||!sxaend_name(c,p+32,names))return false;}else if((flags&0x8000)&&!sxaend_add(c,&sxaend_rsfx_rar_service_size,p+7))return false;if(!sxaend_span(c,p+z,packed))return false;p+=z+packed;}return true;}

static bool sx_archiveend_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_SDS_SFX:case XX_FILE_TYPE_LHPAK_SFX:case XX_FILE_TYPE_LHSFX:case XX_FILE_TYPE_S_OMNI:case XX_FILE_TYPE_PMARC_SFX:case XX_FILE_TYPE_SFX_VMS_DCX:case XX_FILE_TYPE_SFX_NSS:case XX_FILE_TYPE_COPYQMEXE:case XX_FILE_TYPE_DCLRAW:case XX_FILE_TYPE_DIET_COMPRESSION:case XX_FILE_TYPE_BOO:case XX_FILE_TYPE_SFX_ARCV2:case XX_FILE_TYPE_SFX_IMP:case XX_FILE_TYPE_SFX_CAZIP:case XX_FILE_TYPE_SFX_STARKIT:case XX_FILE_TYPE_SFX_TGCF:case XX_FILE_TYPE_SFX_SPIS:case XX_FILE_TYPE_LARC_PFX:case XX_FILE_TYPE_SFX_LOCALZIP:case XX_FILE_TYPE_SFX_RSFX:return true;default:return false;}}
static bool sx_archiveend_build(sx_context*c){if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_SDS_SFX:ok=sxaend_sds(c);break;case XX_FILE_TYPE_LHPAK_SFX:ok=sxaend_lhpak(c);break;case XX_FILE_TYPE_LHSFX:ok=sxaend_lhsfx(c);break;case XX_FILE_TYPE_S_OMNI:ok=sxaend_omni(c);break;case XX_FILE_TYPE_PMARC_SFX:ok=sxaend_pmarc(c);break;case XX_FILE_TYPE_SFX_VMS_DCX:ok=sxaend_dcx(c);break;case XX_FILE_TYPE_SFX_NSS:ok=sxaend_nss(c);break;case XX_FILE_TYPE_COPYQMEXE:ok=sxaend_copyqm(c);break;case XX_FILE_TYPE_DCLRAW:ok=sxaend_dcl(c);break;case XX_FILE_TYPE_DIET_COMPRESSION:ok=sxaend_diet(c);break;case XX_FILE_TYPE_BOO:ok=sxaend_boo(c);break;case XX_FILE_TYPE_SFX_ARCV2:ok=sxaend_carrier_records(c);break;case XX_FILE_TYPE_SFX_IMP:ok=sxaend_carrier_records(c);break;case XX_FILE_TYPE_SFX_CAZIP:ok=sxaend_carrier_records(c);break;case XX_FILE_TYPE_SFX_STARKIT:ok=sxaend_carrier_records(c);break;case XX_FILE_TYPE_SFX_TGCF:ok=sxaend_carrier_records(c);break;case XX_FILE_TYPE_SFX_SPIS:ok=sxaend_carrier_records(c);break;case XX_FILE_TYPE_LARC_PFX:ok=sxaend_add(c,&sxaend_pfx_gemdos_header,0)&&sxaend_carrier_records(c);break;case XX_FILE_TYPE_SFX_LOCALZIP:ok=sxaend_localzip(c);break;case XX_FILE_TYPE_SFX_RSFX:ok=sxaend_rsfx(c);break;default:return false;}(void)ok;/* Partial bounded metadata survives optional damaged records/display caps. */return c->count&&sxaend_finish(c);}
