/* SPDX-License-Identifier: MIT. Genuine physical metadata; see docs/data_struct_archivetransport_scope.txt. */
static const xx_data_struct_field_desc sxatp_dgca_chunk_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",4,4,SX_SIZE),
 SX_FIELD("payload_size","uint64",8,8,SX_SIZE),
 SX_FIELD("flags","uint32",16,4,SX_FLAGS),
 SX_FIELD("alignment","uint32",20,4,SX_NONE),
 SX_FIELD("payload_crc32","uint32",24,4,SX_CHECKSUM),
 SX_FIELD("header_crc32","uint32",28,4,SX_CHECKSUM),
};
static const sx_layout sxatp_dgca_chunk={UINT32_C(0x60890001),"dgca_chunk",sxatp_dgca_chunk_fields,SX_COUNT(sxatp_dgca_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_iarc_prefix_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("version","char[4]",4,4,SX_NONE),
 SX_FIELD("unknown_08","uint8[24]",8,24,SX_NONE),
};
static const sx_layout sxatp_dgca_iarc_prefix={UINT32_C(0x60890002),"dgca_iarc_prefix",sxatp_dgca_iarc_prefix_fields,SX_COUNT(sxatp_dgca_iarc_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_iarc_clear_tail_fields[]={
 SX_FIELD("password_verifier","uint64",0,8,SX_NONE),
 SX_FIELD("member_count","uint64",8,8,SX_COUNT_PROP),
 SX_FIELD("uncompressed_size","uint64",16,8,SX_SIZE),
 SX_FIELD("directory_size","uint64",24,8,SX_SIZE),
 SX_FIELD("names_size","uint64",32,8,SX_SIZE),
 SX_FIELD("unknown_72","uint8[8]",40,8,SX_NONE),
};
static const sx_layout sxatp_dgca_iarc_clear_tail={UINT32_C(0x60890003),"dgca_iarc_clear_tail",sxatp_dgca_iarc_clear_tail_fields,SX_COUNT(sxatp_dgca_iarc_clear_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_stored_unit_fields[]={
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxatp_dgca_stored_unit={UINT32_C(0x60890004),"dgca_stored_unit",sxatp_dgca_stored_unit_fields,SX_COUNT(sxatp_dgca_stored_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_compressed_unit_fields[]={
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("parameter_nibbles","uint32",12,4,SX_FLAGS),
 SX_FIELD("bwt_primary_index","uint32",16,4,SX_NONE),
 SX_FIELD("literal_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("first_stream_size","uint32",24,4,SX_SIZE),
 SX_FIELD("second_stream_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxatp_dgca_compressed_unit={UINT32_C(0x60890005),"dgca_compressed_unit",sxatp_dgca_compressed_unit_fields,SX_COUNT(sxatp_dgca_compressed_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_plane_unit_fields[]={
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("plane_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxatp_dgca_plane_unit={UINT32_C(0x60890006),"dgca_plane_unit",sxatp_dgca_plane_unit_fields,SX_COUNT(sxatp_dgca_plane_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_signature_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxatp_stuffitx_signature={UINT32_C(0x60890007),"stuffitx_signature",sxatp_stuffitx_signature_fields,SX_COUNT(sxatp_stuffitx_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_element_flag_fields[]={
 SX_FIELD("flag","lsb_bits[0,1]",0,1,SX_FLAGS),
};
static const sx_layout sxatp_stuffitx_element_flag={UINT32_C(0x60890008),"stuffitx_element_flag",sxatp_stuffitx_element_flag_fields,SX_COUNT(sxatp_stuffitx_element_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_element_type_bit1_fields[]={
 SX_FIELD("element_type","stuffitx_p2_1",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_element_type_bit1={UINT32_C(0x60890009),"stuffitx_element_type_bit1",sxatp_stuffitx_element_type_bit1_fields,SX_COUNT(sxatp_stuffitx_element_type_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit0_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_0",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_attribute_key_bit0={UINT32_C(0x6089000a),"stuffitx_attribute_key_bit0",sxatp_stuffitx_attribute_key_bit0_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit1_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_1",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_attribute_key_bit1={UINT32_C(0x6089000b),"stuffitx_attribute_key_bit1",sxatp_stuffitx_attribute_key_bit1_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit2_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_2",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_attribute_key_bit2={UINT32_C(0x6089000c),"stuffitx_attribute_key_bit2",sxatp_stuffitx_attribute_key_bit2_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit3_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_3",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_attribute_key_bit3={UINT32_C(0x6089000d),"stuffitx_attribute_key_bit3",sxatp_stuffitx_attribute_key_bit3_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit4_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_4",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_attribute_key_bit4={UINT32_C(0x6089000e),"stuffitx_attribute_key_bit4",sxatp_stuffitx_attribute_key_bit4_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit5_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_5",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_attribute_key_bit5={UINT32_C(0x6089000f),"stuffitx_attribute_key_bit5",sxatp_stuffitx_attribute_key_bit5_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit6_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_6",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_attribute_key_bit6={UINT32_C(0x60890010),"stuffitx_attribute_key_bit6",sxatp_stuffitx_attribute_key_bit6_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit7_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_7",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_attribute_key_bit7={UINT32_C(0x60890011),"stuffitx_attribute_key_bit7",sxatp_stuffitx_attribute_key_bit7_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit0_fields[]={
 SX_FIELD("object_id","stuffitx_p2_0",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_object_id_bit0={UINT32_C(0x60890012),"stuffitx_object_id_bit0",sxatp_stuffitx_object_id_bit0_fields,SX_COUNT(sxatp_stuffitx_object_id_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit1_fields[]={
 SX_FIELD("object_id","stuffitx_p2_1",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_object_id_bit1={UINT32_C(0x60890013),"stuffitx_object_id_bit1",sxatp_stuffitx_object_id_bit1_fields,SX_COUNT(sxatp_stuffitx_object_id_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit2_fields[]={
 SX_FIELD("object_id","stuffitx_p2_2",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_object_id_bit2={UINT32_C(0x60890014),"stuffitx_object_id_bit2",sxatp_stuffitx_object_id_bit2_fields,SX_COUNT(sxatp_stuffitx_object_id_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit3_fields[]={
 SX_FIELD("object_id","stuffitx_p2_3",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_object_id_bit3={UINT32_C(0x60890015),"stuffitx_object_id_bit3",sxatp_stuffitx_object_id_bit3_fields,SX_COUNT(sxatp_stuffitx_object_id_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit4_fields[]={
 SX_FIELD("object_id","stuffitx_p2_4",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_object_id_bit4={UINT32_C(0x60890016),"stuffitx_object_id_bit4",sxatp_stuffitx_object_id_bit4_fields,SX_COUNT(sxatp_stuffitx_object_id_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit5_fields[]={
 SX_FIELD("object_id","stuffitx_p2_5",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_object_id_bit5={UINT32_C(0x60890017),"stuffitx_object_id_bit5",sxatp_stuffitx_object_id_bit5_fields,SX_COUNT(sxatp_stuffitx_object_id_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit6_fields[]={
 SX_FIELD("object_id","stuffitx_p2_6",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_object_id_bit6={UINT32_C(0x60890018),"stuffitx_object_id_bit6",sxatp_stuffitx_object_id_bit6_fields,SX_COUNT(sxatp_stuffitx_object_id_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit7_fields[]={
 SX_FIELD("object_id","stuffitx_p2_7",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_object_id_bit7={UINT32_C(0x60890019),"stuffitx_object_id_bit7",sxatp_stuffitx_object_id_bit7_fields,SX_COUNT(sxatp_stuffitx_object_id_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit0_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_0",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_parent_id_bit0={UINT32_C(0x6089001a),"stuffitx_parent_id_bit0",sxatp_stuffitx_parent_id_bit0_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit1_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_1",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_parent_id_bit1={UINT32_C(0x6089001b),"stuffitx_parent_id_bit1",sxatp_stuffitx_parent_id_bit1_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit2_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_2",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_parent_id_bit2={UINT32_C(0x6089001c),"stuffitx_parent_id_bit2",sxatp_stuffitx_parent_id_bit2_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit3_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_3",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_parent_id_bit3={UINT32_C(0x6089001d),"stuffitx_parent_id_bit3",sxatp_stuffitx_parent_id_bit3_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit4_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_4",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_parent_id_bit4={UINT32_C(0x6089001e),"stuffitx_parent_id_bit4",sxatp_stuffitx_parent_id_bit4_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit5_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_5",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_parent_id_bit5={UINT32_C(0x6089001f),"stuffitx_parent_id_bit5",sxatp_stuffitx_parent_id_bit5_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit6_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_6",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_parent_id_bit6={UINT32_C(0x60890020),"stuffitx_parent_id_bit6",sxatp_stuffitx_parent_id_bit6_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit7_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_7",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_parent_id_bit7={UINT32_C(0x60890021),"stuffitx_parent_id_bit7",sxatp_stuffitx_parent_id_bit7_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit0_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_0",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_stream_id_bit0={UINT32_C(0x60890022),"stuffitx_stream_id_bit0",sxatp_stuffitx_stream_id_bit0_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit1_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_1",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_stream_id_bit1={UINT32_C(0x60890023),"stuffitx_stream_id_bit1",sxatp_stuffitx_stream_id_bit1_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit2_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_2",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_stream_id_bit2={UINT32_C(0x60890024),"stuffitx_stream_id_bit2",sxatp_stuffitx_stream_id_bit2_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit3_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_3",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_stream_id_bit3={UINT32_C(0x60890025),"stuffitx_stream_id_bit3",sxatp_stuffitx_stream_id_bit3_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit4_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_4",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_stream_id_bit4={UINT32_C(0x60890026),"stuffitx_stream_id_bit4",sxatp_stuffitx_stream_id_bit4_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit5_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_5",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_stream_id_bit5={UINT32_C(0x60890027),"stuffitx_stream_id_bit5",sxatp_stuffitx_stream_id_bit5_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit6_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_6",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_stream_id_bit6={UINT32_C(0x60890028),"stuffitx_stream_id_bit6",sxatp_stuffitx_stream_id_bit6_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit7_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_7",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_stream_id_bit7={UINT32_C(0x60890029),"stuffitx_stream_id_bit7",sxatp_stuffitx_stream_id_bit7_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit0_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_0",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_fork_index_bit0={UINT32_C(0x6089002a),"stuffitx_fork_index_bit0",sxatp_stuffitx_fork_index_bit0_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit1_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_1",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_fork_index_bit1={UINT32_C(0x6089002b),"stuffitx_fork_index_bit1",sxatp_stuffitx_fork_index_bit1_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit2_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_2",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_fork_index_bit2={UINT32_C(0x6089002c),"stuffitx_fork_index_bit2",sxatp_stuffitx_fork_index_bit2_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit3_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_3",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_fork_index_bit3={UINT32_C(0x6089002d),"stuffitx_fork_index_bit3",sxatp_stuffitx_fork_index_bit3_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit4_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_4",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_fork_index_bit4={UINT32_C(0x6089002e),"stuffitx_fork_index_bit4",sxatp_stuffitx_fork_index_bit4_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit5_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_5",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_fork_index_bit5={UINT32_C(0x6089002f),"stuffitx_fork_index_bit5",sxatp_stuffitx_fork_index_bit5_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit6_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_6",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_fork_index_bit6={UINT32_C(0x60890030),"stuffitx_fork_index_bit6",sxatp_stuffitx_fork_index_bit6_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit7_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_7",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_fork_index_bit7={UINT32_C(0x60890031),"stuffitx_fork_index_bit7",sxatp_stuffitx_fork_index_bit7_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit0_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_0",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_declared_size_bit0={UINT32_C(0x60890032),"stuffitx_declared_size_bit0",sxatp_stuffitx_declared_size_bit0_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit1_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_1",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_declared_size_bit1={UINT32_C(0x60890033),"stuffitx_declared_size_bit1",sxatp_stuffitx_declared_size_bit1_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit2_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_2",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_declared_size_bit2={UINT32_C(0x60890034),"stuffitx_declared_size_bit2",sxatp_stuffitx_declared_size_bit2_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit3_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_3",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_declared_size_bit3={UINT32_C(0x60890035),"stuffitx_declared_size_bit3",sxatp_stuffitx_declared_size_bit3_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit4_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_4",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_declared_size_bit4={UINT32_C(0x60890036),"stuffitx_declared_size_bit4",sxatp_stuffitx_declared_size_bit4_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit5_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_5",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_declared_size_bit5={UINT32_C(0x60890037),"stuffitx_declared_size_bit5",sxatp_stuffitx_declared_size_bit5_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit6_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_6",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_declared_size_bit6={UINT32_C(0x60890038),"stuffitx_declared_size_bit6",sxatp_stuffitx_declared_size_bit6_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit7_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_7",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_declared_size_bit7={UINT32_C(0x60890039),"stuffitx_declared_size_bit7",sxatp_stuffitx_declared_size_bit7_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit0_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_0",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_attribute_value_bit0={UINT32_C(0x6089003a),"stuffitx_attribute_value_bit0",sxatp_stuffitx_attribute_value_bit0_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit1_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_1",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_attribute_value_bit1={UINT32_C(0x6089003b),"stuffitx_attribute_value_bit1",sxatp_stuffitx_attribute_value_bit1_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit2_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_2",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_attribute_value_bit2={UINT32_C(0x6089003c),"stuffitx_attribute_value_bit2",sxatp_stuffitx_attribute_value_bit2_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit3_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_3",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_attribute_value_bit3={UINT32_C(0x6089003d),"stuffitx_attribute_value_bit3",sxatp_stuffitx_attribute_value_bit3_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit4_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_4",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_attribute_value_bit4={UINT32_C(0x6089003e),"stuffitx_attribute_value_bit4",sxatp_stuffitx_attribute_value_bit4_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit5_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_5",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_attribute_value_bit5={UINT32_C(0x6089003f),"stuffitx_attribute_value_bit5",sxatp_stuffitx_attribute_value_bit5_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit6_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_6",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_attribute_value_bit6={UINT32_C(0x60890040),"stuffitx_attribute_value_bit6",sxatp_stuffitx_attribute_value_bit6_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit7_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_7",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_attribute_value_bit7={UINT32_C(0x60890041),"stuffitx_attribute_value_bit7",sxatp_stuffitx_attribute_value_bit7_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit0_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_0",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_algorithm_key_bit0={UINT32_C(0x60890042),"stuffitx_algorithm_key_bit0",sxatp_stuffitx_algorithm_key_bit0_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit1_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_1",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_algorithm_key_bit1={UINT32_C(0x60890043),"stuffitx_algorithm_key_bit1",sxatp_stuffitx_algorithm_key_bit1_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit2_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_2",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_algorithm_key_bit2={UINT32_C(0x60890044),"stuffitx_algorithm_key_bit2",sxatp_stuffitx_algorithm_key_bit2_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit3_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_3",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_algorithm_key_bit3={UINT32_C(0x60890045),"stuffitx_algorithm_key_bit3",sxatp_stuffitx_algorithm_key_bit3_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit4_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_4",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_algorithm_key_bit4={UINT32_C(0x60890046),"stuffitx_algorithm_key_bit4",sxatp_stuffitx_algorithm_key_bit4_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit5_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_5",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_algorithm_key_bit5={UINT32_C(0x60890047),"stuffitx_algorithm_key_bit5",sxatp_stuffitx_algorithm_key_bit5_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit6_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_6",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_algorithm_key_bit6={UINT32_C(0x60890048),"stuffitx_algorithm_key_bit6",sxatp_stuffitx_algorithm_key_bit6_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit7_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_7",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_algorithm_key_bit7={UINT32_C(0x60890049),"stuffitx_algorithm_key_bit7",sxatp_stuffitx_algorithm_key_bit7_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit0_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_0",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_algorithm_value_bit0={UINT32_C(0x6089004a),"stuffitx_algorithm_value_bit0",sxatp_stuffitx_algorithm_value_bit0_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit1_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_1",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_algorithm_value_bit1={UINT32_C(0x6089004b),"stuffitx_algorithm_value_bit1",sxatp_stuffitx_algorithm_value_bit1_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit2_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_2",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_algorithm_value_bit2={UINT32_C(0x6089004c),"stuffitx_algorithm_value_bit2",sxatp_stuffitx_algorithm_value_bit2_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit3_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_3",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_algorithm_value_bit3={UINT32_C(0x6089004d),"stuffitx_algorithm_value_bit3",sxatp_stuffitx_algorithm_value_bit3_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit4_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_4",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_algorithm_value_bit4={UINT32_C(0x6089004e),"stuffitx_algorithm_value_bit4",sxatp_stuffitx_algorithm_value_bit4_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit5_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_5",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_algorithm_value_bit5={UINT32_C(0x6089004f),"stuffitx_algorithm_value_bit5",sxatp_stuffitx_algorithm_value_bit5_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit6_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_6",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_algorithm_value_bit6={UINT32_C(0x60890050),"stuffitx_algorithm_value_bit6",sxatp_stuffitx_algorithm_value_bit6_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit7_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_7",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_algorithm_value_bit7={UINT32_C(0x60890051),"stuffitx_algorithm_value_bit7",sxatp_stuffitx_algorithm_value_bit7_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit0_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_0",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_cipher_extra_bit0={UINT32_C(0x60890052),"stuffitx_cipher_extra_bit0",sxatp_stuffitx_cipher_extra_bit0_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit1_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_1",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_cipher_extra_bit1={UINT32_C(0x60890053),"stuffitx_cipher_extra_bit1",sxatp_stuffitx_cipher_extra_bit1_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit2_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_2",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_cipher_extra_bit2={UINT32_C(0x60890054),"stuffitx_cipher_extra_bit2",sxatp_stuffitx_cipher_extra_bit2_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit3_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_3",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_cipher_extra_bit3={UINT32_C(0x60890055),"stuffitx_cipher_extra_bit3",sxatp_stuffitx_cipher_extra_bit3_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit4_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_4",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_cipher_extra_bit4={UINT32_C(0x60890056),"stuffitx_cipher_extra_bit4",sxatp_stuffitx_cipher_extra_bit4_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit5_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_5",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_cipher_extra_bit5={UINT32_C(0x60890057),"stuffitx_cipher_extra_bit5",sxatp_stuffitx_cipher_extra_bit5_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit6_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_6",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_cipher_extra_bit6={UINT32_C(0x60890058),"stuffitx_cipher_extra_bit6",sxatp_stuffitx_cipher_extra_bit6_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit7_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_7",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_cipher_extra_bit7={UINT32_C(0x60890059),"stuffitx_cipher_extra_bit7",sxatp_stuffitx_cipher_extra_bit7_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit0_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_0",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_fork_type_bit0={UINT32_C(0x6089005a),"stuffitx_fork_type_bit0",sxatp_stuffitx_fork_type_bit0_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit1_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_1",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_fork_type_bit1={UINT32_C(0x6089005b),"stuffitx_fork_type_bit1",sxatp_stuffitx_fork_type_bit1_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit2_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_2",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_fork_type_bit2={UINT32_C(0x6089005c),"stuffitx_fork_type_bit2",sxatp_stuffitx_fork_type_bit2_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit3_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_3",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_fork_type_bit3={UINT32_C(0x6089005d),"stuffitx_fork_type_bit3",sxatp_stuffitx_fork_type_bit3_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit4_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_4",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_fork_type_bit4={UINT32_C(0x6089005e),"stuffitx_fork_type_bit4",sxatp_stuffitx_fork_type_bit4_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit5_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_5",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_fork_type_bit5={UINT32_C(0x6089005f),"stuffitx_fork_type_bit5",sxatp_stuffitx_fork_type_bit5_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit6_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_6",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_fork_type_bit6={UINT32_C(0x60890060),"stuffitx_fork_type_bit6",sxatp_stuffitx_fork_type_bit6_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit7_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_7",0,0,SX_ID),
};
static const sx_layout sxatp_stuffitx_fork_type_bit7={UINT32_C(0x60890061),"stuffitx_fork_type_bit7",sxatp_stuffitx_fork_type_bit7_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit0_fields[]={
 SX_FIELD("root_value","stuffitx_p2_0",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_root_value_bit0={UINT32_C(0x60890062),"stuffitx_root_value_bit0",sxatp_stuffitx_root_value_bit0_fields,SX_COUNT(sxatp_stuffitx_root_value_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit1_fields[]={
 SX_FIELD("root_value","stuffitx_p2_1",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_root_value_bit1={UINT32_C(0x60890063),"stuffitx_root_value_bit1",sxatp_stuffitx_root_value_bit1_fields,SX_COUNT(sxatp_stuffitx_root_value_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit2_fields[]={
 SX_FIELD("root_value","stuffitx_p2_2",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_root_value_bit2={UINT32_C(0x60890064),"stuffitx_root_value_bit2",sxatp_stuffitx_root_value_bit2_fields,SX_COUNT(sxatp_stuffitx_root_value_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit3_fields[]={
 SX_FIELD("root_value","stuffitx_p2_3",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_root_value_bit3={UINT32_C(0x60890065),"stuffitx_root_value_bit3",sxatp_stuffitx_root_value_bit3_fields,SX_COUNT(sxatp_stuffitx_root_value_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit4_fields[]={
 SX_FIELD("root_value","stuffitx_p2_4",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_root_value_bit4={UINT32_C(0x60890066),"stuffitx_root_value_bit4",sxatp_stuffitx_root_value_bit4_fields,SX_COUNT(sxatp_stuffitx_root_value_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit5_fields[]={
 SX_FIELD("root_value","stuffitx_p2_5",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_root_value_bit5={UINT32_C(0x60890067),"stuffitx_root_value_bit5",sxatp_stuffitx_root_value_bit5_fields,SX_COUNT(sxatp_stuffitx_root_value_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit6_fields[]={
 SX_FIELD("root_value","stuffitx_p2_6",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_root_value_bit6={UINT32_C(0x60890068),"stuffitx_root_value_bit6",sxatp_stuffitx_root_value_bit6_fields,SX_COUNT(sxatp_stuffitx_root_value_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit7_fields[]={
 SX_FIELD("root_value","stuffitx_p2_7",0,0,SX_NONE),
};
static const sx_layout sxatp_stuffitx_root_value_bit7={UINT32_C(0x60890069),"stuffitx_root_value_bit7",sxatp_stuffitx_root_value_bit7_fields,SX_COUNT(sxatp_stuffitx_root_value_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_block_size_bit0_fields[]={
 SX_FIELD("block_size","stuffitx_p2_0",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_block_size_bit0={UINT32_C(0x6089006a),"stuffitx_block_size_bit0",sxatp_stuffitx_block_size_bit0_fields,SX_COUNT(sxatp_stuffitx_block_size_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_trailer_size_bit0_fields[]={
 SX_FIELD("trailer_size","stuffitx_p2_0",0,0,SX_SIZE),
};
static const sx_layout sxatp_stuffitx_trailer_size_bit0={UINT32_C(0x6089006b),"stuffitx_trailer_size_bit0",sxatp_stuffitx_trailer_size_bit0_fields,SX_COUNT(sxatp_stuffitx_trailer_size_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_crc32_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxatp_stuffitx_crc32={UINT32_C(0x6089006c),"stuffitx_crc32",sxatp_stuffitx_crc32_fields,SX_COUNT(sxatp_stuffitx_crc32_fields),SX_BE};
static const xx_data_struct_field_desc sxatp_powerarc_header_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxatp_powerarc_header={UINT32_C(0x6089006d),"powerarc_header",sxatp_powerarc_header_fields,SX_COUNT(sxatp_powerarc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_powerarc_bzip2_stream_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("block_size_digit","char[1]",3,1,SX_NONE),
};
static const sx_layout sxatp_powerarc_bzip2_stream={UINT32_C(0x6089006e),"powerarc_bzip2_stream",sxatp_powerarc_bzip2_stream_fields,SX_COUNT(sxatp_powerarc_bzip2_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxatp_powerarc_bzip2_first_block_fields[]={
 SX_FIELD("block_magic","uint48",0,6,SX_SIGNATURE),
 SX_FIELD("block_crc32","uint32",6,4,SX_CHECKSUM),
 SX_FIELD("randomized","msb_bits[0,1]",10,1,SX_FLAGS),
 SX_FIELD("bwt_original_pointer","msb_bits[1,24]",10,4,SX_NONE),
};
static const sx_layout sxatp_powerarc_bzip2_first_block={UINT32_C(0x6089006f),"powerarc_bzip2_first_block",sxatp_powerarc_bzip2_first_block_fields,SX_COUNT(sxatp_powerarc_bzip2_first_block_fields),SX_BE};
static const xx_data_struct_field_desc sxatp_powerarc_bzip2_empty_end_fields[]={
 SX_FIELD("end_magic","uint48",0,6,SX_SIGNATURE),
 SX_FIELD("combined_crc32","uint32",6,4,SX_CHECKSUM),
};
static const sx_layout sxatp_powerarc_bzip2_empty_end={UINT32_C(0x60890070),"powerarc_bzip2_empty_end",sxatp_powerarc_bzip2_empty_end_fields,SX_COUNT(sxatp_powerarc_bzip2_empty_end_fields),SX_BE};
static const xx_data_struct_field_desc sxatp_binhex_banner_fields[]={
 SX_FIELD("banner","char[45]",0,45,SX_SIGNATURE),
};
static const sx_layout sxatp_binhex_banner={UINT32_C(0x60890071),"binhex_banner",sxatp_binhex_banner_fields,SX_COUNT(sxatp_binhex_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_binhex_delimiter_fields[]={
 SX_FIELD("delimiter","char[1]",0,1,SX_NONE),
};
static const sx_layout sxatp_binhex_delimiter={UINT32_C(0x60890072),"binhex_delimiter",sxatp_binhex_delimiter_fields,SX_COUNT(sxatp_binhex_delimiter_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_binhex_encoded_run_fields[]={
 SX_FIELD("encoded_six_bit_characters","char",0,0,SX_NONE),
};
static const sx_layout sxatp_binhex_encoded_run={UINT32_C(0x60890073),"binhex_encoded_run",sxatp_binhex_encoded_run_fields,SX_COUNT(sxatp_binhex_encoded_run_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_transport_line_end_fields[]={
 SX_FIELD("line_ending","uint8",0,0,SX_NONE),
};
static const sx_layout sxatp_transport_line_end={UINT32_C(0x60890074),"transport_line_end",sxatp_transport_line_end_fields,SX_COUNT(sxatp_transport_line_end_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_transport_whitespace_fields[]={
 SX_FIELD("whitespace","uint8",0,0,SX_NONE),
};
static const sx_layout sxatp_transport_whitespace={UINT32_C(0x60890075),"transport_whitespace",sxatp_transport_whitespace_fields,SX_COUNT(sxatp_transport_whitespace_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_qp_literal_run_fields[]={
 SX_FIELD("literal_bytes","uint8",0,0,SX_NONE),
};
static const sx_layout sxatp_qp_literal_run={UINT32_C(0x60890076),"qp_literal_run",sxatp_qp_literal_run_fields,SX_COUNT(sxatp_qp_literal_run_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_qp_hex_escape_fields[]={
 SX_FIELD("escape_marker","char[1]",0,1,SX_NONE),
 SX_FIELD("encoded_octet","ascii_hex[2]",1,2,SX_NONE),
};
static const sx_layout sxatp_qp_hex_escape={UINT32_C(0x60890077),"qp_hex_escape",sxatp_qp_hex_escape_fields,SX_COUNT(sxatp_qp_hex_escape_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_qp_soft_break_fields[]={
 SX_FIELD("soft_line_break","uint8",0,0,SX_NONE),
};
static const sx_layout sxatp_qp_soft_break={UINT32_C(0x60890078),"qp_soft_break",sxatp_qp_soft_break_fields,SX_COUNT(sxatp_qp_soft_break_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_qp_padding_fields[]={
 SX_FIELD("padding","uint8",0,0,SX_NONE),
};
static const sx_layout sxatp_qp_padding={UINT32_C(0x60890079),"qp_padding",sxatp_qp_padding_fields,SX_COUNT(sxatp_qp_padding_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_command_fields[]={
 SX_FIELD("command","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_command={UINT32_C(0x6089007a),"shar_command",sxatp_shar_command_fields,SX_COUNT(sxatp_shar_command_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_redirection_fields[]={
 SX_FIELD("redirection_operator","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_redirection={UINT32_C(0x6089007b),"shar_redirection",sxatp_shar_redirection_fields,SX_COUNT(sxatp_shar_redirection_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_heredoc_operator_fields[]={
 SX_FIELD("here_document_operator","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_heredoc_operator={UINT32_C(0x6089007c),"shar_heredoc_operator",sxatp_shar_heredoc_operator_fields,SX_COUNT(sxatp_shar_heredoc_operator_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_delimiter_fields[]={
 SX_FIELD("delimiter","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_delimiter={UINT32_C(0x6089007d),"shar_delimiter",sxatp_shar_delimiter_fields,SX_COUNT(sxatp_shar_delimiter_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_name_fields[]={
 SX_FIELD("member_name","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_name={UINT32_C(0x6089007e),"shar_name",sxatp_shar_name_fields,SX_COUNT(sxatp_shar_name_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_quoted_marker_fields[]={
 SX_FIELD("quoting_marker","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_quoted_marker={UINT32_C(0x6089007f),"shar_quoted_marker",sxatp_shar_quoted_marker_fields,SX_COUNT(sxatp_shar_quoted_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_terminator_fields[]={
 SX_FIELD("terminating_delimiter","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_terminator={UINT32_C(0x60890080),"shar_terminator",sxatp_shar_terminator_fields,SX_COUNT(sxatp_shar_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_prefix_expression_fields[]={
 SX_FIELD("prefix_expression","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_prefix_expression={UINT32_C(0x60890081),"shar_prefix_expression",sxatp_shar_prefix_expression_fields,SX_COUNT(sxatp_shar_prefix_expression_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_shar_uu_begin_fields[]={
 SX_FIELD("uuencode_begin_line","char",0,0,SX_NONE),
};
static const sx_layout sxatp_shar_uu_begin={UINT32_C(0x60890082),"shar_uu_begin",sxatp_shar_uu_begin_fields,SX_COUNT(sxatp_shar_uu_begin_fields),SX_LE};
static const sx_layout *const sx_archivetransport_layouts[]={
 &sxatp_dgca_chunk,
 &sxatp_dgca_iarc_prefix,
 &sxatp_dgca_iarc_clear_tail,
 &sxatp_dgca_stored_unit,
 &sxatp_dgca_compressed_unit,
 &sxatp_dgca_plane_unit,
 &sxatp_stuffitx_signature,
 &sxatp_stuffitx_element_flag,
 &sxatp_stuffitx_element_type_bit1,
 &sxatp_stuffitx_attribute_key_bit0,
 &sxatp_stuffitx_attribute_key_bit1,
 &sxatp_stuffitx_attribute_key_bit2,
 &sxatp_stuffitx_attribute_key_bit3,
 &sxatp_stuffitx_attribute_key_bit4,
 &sxatp_stuffitx_attribute_key_bit5,
 &sxatp_stuffitx_attribute_key_bit6,
 &sxatp_stuffitx_attribute_key_bit7,
 &sxatp_stuffitx_object_id_bit0,
 &sxatp_stuffitx_object_id_bit1,
 &sxatp_stuffitx_object_id_bit2,
 &sxatp_stuffitx_object_id_bit3,
 &sxatp_stuffitx_object_id_bit4,
 &sxatp_stuffitx_object_id_bit5,
 &sxatp_stuffitx_object_id_bit6,
 &sxatp_stuffitx_object_id_bit7,
 &sxatp_stuffitx_parent_id_bit0,
 &sxatp_stuffitx_parent_id_bit1,
 &sxatp_stuffitx_parent_id_bit2,
 &sxatp_stuffitx_parent_id_bit3,
 &sxatp_stuffitx_parent_id_bit4,
 &sxatp_stuffitx_parent_id_bit5,
 &sxatp_stuffitx_parent_id_bit6,
 &sxatp_stuffitx_parent_id_bit7,
 &sxatp_stuffitx_stream_id_bit0,
 &sxatp_stuffitx_stream_id_bit1,
 &sxatp_stuffitx_stream_id_bit2,
 &sxatp_stuffitx_stream_id_bit3,
 &sxatp_stuffitx_stream_id_bit4,
 &sxatp_stuffitx_stream_id_bit5,
 &sxatp_stuffitx_stream_id_bit6,
 &sxatp_stuffitx_stream_id_bit7,
 &sxatp_stuffitx_fork_index_bit0,
 &sxatp_stuffitx_fork_index_bit1,
 &sxatp_stuffitx_fork_index_bit2,
 &sxatp_stuffitx_fork_index_bit3,
 &sxatp_stuffitx_fork_index_bit4,
 &sxatp_stuffitx_fork_index_bit5,
 &sxatp_stuffitx_fork_index_bit6,
 &sxatp_stuffitx_fork_index_bit7,
 &sxatp_stuffitx_declared_size_bit0,
 &sxatp_stuffitx_declared_size_bit1,
 &sxatp_stuffitx_declared_size_bit2,
 &sxatp_stuffitx_declared_size_bit3,
 &sxatp_stuffitx_declared_size_bit4,
 &sxatp_stuffitx_declared_size_bit5,
 &sxatp_stuffitx_declared_size_bit6,
 &sxatp_stuffitx_declared_size_bit7,
 &sxatp_stuffitx_attribute_value_bit0,
 &sxatp_stuffitx_attribute_value_bit1,
 &sxatp_stuffitx_attribute_value_bit2,
 &sxatp_stuffitx_attribute_value_bit3,
 &sxatp_stuffitx_attribute_value_bit4,
 &sxatp_stuffitx_attribute_value_bit5,
 &sxatp_stuffitx_attribute_value_bit6,
 &sxatp_stuffitx_attribute_value_bit7,
 &sxatp_stuffitx_algorithm_key_bit0,
 &sxatp_stuffitx_algorithm_key_bit1,
 &sxatp_stuffitx_algorithm_key_bit2,
 &sxatp_stuffitx_algorithm_key_bit3,
 &sxatp_stuffitx_algorithm_key_bit4,
 &sxatp_stuffitx_algorithm_key_bit5,
 &sxatp_stuffitx_algorithm_key_bit6,
 &sxatp_stuffitx_algorithm_key_bit7,
 &sxatp_stuffitx_algorithm_value_bit0,
 &sxatp_stuffitx_algorithm_value_bit1,
 &sxatp_stuffitx_algorithm_value_bit2,
 &sxatp_stuffitx_algorithm_value_bit3,
 &sxatp_stuffitx_algorithm_value_bit4,
 &sxatp_stuffitx_algorithm_value_bit5,
 &sxatp_stuffitx_algorithm_value_bit6,
 &sxatp_stuffitx_algorithm_value_bit7,
 &sxatp_stuffitx_cipher_extra_bit0,
 &sxatp_stuffitx_cipher_extra_bit1,
 &sxatp_stuffitx_cipher_extra_bit2,
 &sxatp_stuffitx_cipher_extra_bit3,
 &sxatp_stuffitx_cipher_extra_bit4,
 &sxatp_stuffitx_cipher_extra_bit5,
 &sxatp_stuffitx_cipher_extra_bit6,
 &sxatp_stuffitx_cipher_extra_bit7,
 &sxatp_stuffitx_fork_type_bit0,
 &sxatp_stuffitx_fork_type_bit1,
 &sxatp_stuffitx_fork_type_bit2,
 &sxatp_stuffitx_fork_type_bit3,
 &sxatp_stuffitx_fork_type_bit4,
 &sxatp_stuffitx_fork_type_bit5,
 &sxatp_stuffitx_fork_type_bit6,
 &sxatp_stuffitx_fork_type_bit7,
 &sxatp_stuffitx_root_value_bit0,
 &sxatp_stuffitx_root_value_bit1,
 &sxatp_stuffitx_root_value_bit2,
 &sxatp_stuffitx_root_value_bit3,
 &sxatp_stuffitx_root_value_bit4,
 &sxatp_stuffitx_root_value_bit5,
 &sxatp_stuffitx_root_value_bit6,
 &sxatp_stuffitx_root_value_bit7,
 &sxatp_stuffitx_block_size_bit0,
 &sxatp_stuffitx_trailer_size_bit0,
 &sxatp_stuffitx_crc32,
 &sxatp_powerarc_header,
 &sxatp_powerarc_bzip2_stream,
 &sxatp_powerarc_bzip2_first_block,
 &sxatp_powerarc_bzip2_empty_end,
 &sxatp_binhex_banner,
 &sxatp_binhex_delimiter,
 &sxatp_binhex_encoded_run,
 &sxatp_transport_line_end,
 &sxatp_transport_whitespace,
 &sxatp_qp_literal_run,
 &sxatp_qp_hex_escape,
 &sxatp_qp_soft_break,
 &sxatp_qp_padding,
 &sxatp_shar_command,
 &sxatp_shar_redirection,
 &sxatp_shar_heredoc_operator,
 &sxatp_shar_delimiter,
 &sxatp_shar_name,
 &sxatp_shar_quoted_marker,
 &sxatp_shar_terminator,
 &sxatp_shar_prefix_expression,
 &sxatp_shar_uu_begin,
};
static bool sx_archivetransport_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60890000U||id>=0x608a0000U)return true;const wchar_t*text=NULL;switch(id){
 case 0x60890001U:text=L"Payload excludes padding; chunk payload is rounded up to16bytes. Header CRC32 zeros its own field, retaining payload CRC32.";break;
 case 0x60890002U:text=L"Flag1 encrypts bytes32..79 and DGCC headers/payloads. Unknown physical bytes are retained without invented semantics.";break;
 case 0x60890004U:text=L"Method0: exactly uncompressed_size stored bytes follow.";break;
 case 0x60890005U:text=L"Method1 entropy/LZP streams follow. BWT index is an index, not a file offset; high flags encode integration order.";break;
 case 0x60890006U:text=L"Method2: plane_count consecutive stored/compressed units; decoded bytes are interleaved.";break;
 case 0x60890008U:text=L"Physical first LSB of each byte-aligned element; native reader does not assign a semantic meaning.";break;
 case 0x60890009U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890010U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890011U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890012U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890013U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890014U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890015U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890016U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890017U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890018U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890019U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890020U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890021U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890022U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890023U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890024U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890025U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890026U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890027U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890028U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890029U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890030U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890031U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890032U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890033U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890034U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890035U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890036U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890037U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890038U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890039U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890040U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890041U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890042U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890043U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890044U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890045U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890046U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890047U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890048U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890049U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890050U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890051U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890052U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890053U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890054U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890055U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890056U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890057U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890058U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890059U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890060U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890061U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890062U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890063U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890064U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890065U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890066U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890067U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890068U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890069U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089006aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089006bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089006cU:text=L"First4-byte trailing chunk: big-endian decoded-stream CRC32; stored value only.";break;
 case 0x6089006eU:text=L"ASCII digit1..9 encodes maximum block size in100000-byte units.";break;
 case 0x6089006fU:text=L"First data block physical prefix only. BWT original pointer is a row index. Later variable-bit blocks and Huffman payload remain raw.";break;
 case 0x60890072U:text=L"Colon separates physical HQX transport. Decoded RLE header/forks have no linear source-field offsets.";break;
 case 0x60890073U:text=L"Original HQX alphabet bytes; whitespace may split groups. No plaintext header/fork fields are assigned false positions.";break;
 case 0x60890074U:text=L"Original CR/LF physical separator bytes.";break;
 case 0x60890077U:text=L"RFC2045 hexadecimal escape. Displayed octet comes from its two original hex characters; it is not a file address.";break;
 case 0x60890078U:text=L"Equals plus physical CRLF/LF, or a final equals at EOF; contributes no decoded octet.";break;
 case 0x60890079U:text=L"Native-supported trailing NUL/SUB padding; not decoded text.";break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXATP_LIMIT 20000U
static bool sxatp_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxatp_read(sx_context*c,uint64_t p,void*b,size_t n){return sxatp_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxatp_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxatp_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxatp_read(c,p,b,n))return false;*v=sxatp_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxatp_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXATP_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxatp_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxatp_add(sx_context*c,const sx_layout*l,uint64_t p){return sxatp_put(c,l,p,0,false);}
static bool sxatp_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxatp_put(c,l,p,n,aliases);}
static int sxatp_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxatp_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxatp_order);return !c->failed;}
static bool sxatp_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxatp_add(c,l,p+i*width))return false;return true;}
static bool sxatp_line(sx_context*c,uint64_t p,uint8_t*b,size_t cap,size_t*n,uint64_t*next){*n=0;uint64_t q=p;while(q<(uint64_t)c->size){uint8_t x;if(!sxatp_read(c,q,&x,1))return false;q++;if(x=='\r'||x=='\n'){if(x=='\r'&&q<(uint64_t)c->size){uint8_t y;if(!sxatp_read(c,q,&y,1))return false;if(y=='\n')q++;}*next=q;return true;}if(*n>=cap)return false;b[(*n)++]=x;}*next=q;return q>p;}



static const sx_layout*const sxatp_p2_element_type[8]={NULL,&sxatp_stuffitx_element_type_bit1,NULL,NULL,NULL,NULL,NULL,NULL};
static const sx_layout*const sxatp_p2_attribute_key[8]={&sxatp_stuffitx_attribute_key_bit0,&sxatp_stuffitx_attribute_key_bit1,&sxatp_stuffitx_attribute_key_bit2,&sxatp_stuffitx_attribute_key_bit3,&sxatp_stuffitx_attribute_key_bit4,&sxatp_stuffitx_attribute_key_bit5,&sxatp_stuffitx_attribute_key_bit6,&sxatp_stuffitx_attribute_key_bit7};
static const sx_layout*const sxatp_p2_object_id[8]={&sxatp_stuffitx_object_id_bit0,&sxatp_stuffitx_object_id_bit1,&sxatp_stuffitx_object_id_bit2,&sxatp_stuffitx_object_id_bit3,&sxatp_stuffitx_object_id_bit4,&sxatp_stuffitx_object_id_bit5,&sxatp_stuffitx_object_id_bit6,&sxatp_stuffitx_object_id_bit7};
static const sx_layout*const sxatp_p2_parent_id[8]={&sxatp_stuffitx_parent_id_bit0,&sxatp_stuffitx_parent_id_bit1,&sxatp_stuffitx_parent_id_bit2,&sxatp_stuffitx_parent_id_bit3,&sxatp_stuffitx_parent_id_bit4,&sxatp_stuffitx_parent_id_bit5,&sxatp_stuffitx_parent_id_bit6,&sxatp_stuffitx_parent_id_bit7};
static const sx_layout*const sxatp_p2_stream_id[8]={&sxatp_stuffitx_stream_id_bit0,&sxatp_stuffitx_stream_id_bit1,&sxatp_stuffitx_stream_id_bit2,&sxatp_stuffitx_stream_id_bit3,&sxatp_stuffitx_stream_id_bit4,&sxatp_stuffitx_stream_id_bit5,&sxatp_stuffitx_stream_id_bit6,&sxatp_stuffitx_stream_id_bit7};
static const sx_layout*const sxatp_p2_fork_index[8]={&sxatp_stuffitx_fork_index_bit0,&sxatp_stuffitx_fork_index_bit1,&sxatp_stuffitx_fork_index_bit2,&sxatp_stuffitx_fork_index_bit3,&sxatp_stuffitx_fork_index_bit4,&sxatp_stuffitx_fork_index_bit5,&sxatp_stuffitx_fork_index_bit6,&sxatp_stuffitx_fork_index_bit7};
static const sx_layout*const sxatp_p2_declared_size[8]={&sxatp_stuffitx_declared_size_bit0,&sxatp_stuffitx_declared_size_bit1,&sxatp_stuffitx_declared_size_bit2,&sxatp_stuffitx_declared_size_bit3,&sxatp_stuffitx_declared_size_bit4,&sxatp_stuffitx_declared_size_bit5,&sxatp_stuffitx_declared_size_bit6,&sxatp_stuffitx_declared_size_bit7};
static const sx_layout*const sxatp_p2_attribute_value[8]={&sxatp_stuffitx_attribute_value_bit0,&sxatp_stuffitx_attribute_value_bit1,&sxatp_stuffitx_attribute_value_bit2,&sxatp_stuffitx_attribute_value_bit3,&sxatp_stuffitx_attribute_value_bit4,&sxatp_stuffitx_attribute_value_bit5,&sxatp_stuffitx_attribute_value_bit6,&sxatp_stuffitx_attribute_value_bit7};
static const sx_layout*const sxatp_p2_algorithm_key[8]={&sxatp_stuffitx_algorithm_key_bit0,&sxatp_stuffitx_algorithm_key_bit1,&sxatp_stuffitx_algorithm_key_bit2,&sxatp_stuffitx_algorithm_key_bit3,&sxatp_stuffitx_algorithm_key_bit4,&sxatp_stuffitx_algorithm_key_bit5,&sxatp_stuffitx_algorithm_key_bit6,&sxatp_stuffitx_algorithm_key_bit7};
static const sx_layout*const sxatp_p2_algorithm_value[8]={&sxatp_stuffitx_algorithm_value_bit0,&sxatp_stuffitx_algorithm_value_bit1,&sxatp_stuffitx_algorithm_value_bit2,&sxatp_stuffitx_algorithm_value_bit3,&sxatp_stuffitx_algorithm_value_bit4,&sxatp_stuffitx_algorithm_value_bit5,&sxatp_stuffitx_algorithm_value_bit6,&sxatp_stuffitx_algorithm_value_bit7};
static const sx_layout*const sxatp_p2_cipher_extra[8]={&sxatp_stuffitx_cipher_extra_bit0,&sxatp_stuffitx_cipher_extra_bit1,&sxatp_stuffitx_cipher_extra_bit2,&sxatp_stuffitx_cipher_extra_bit3,&sxatp_stuffitx_cipher_extra_bit4,&sxatp_stuffitx_cipher_extra_bit5,&sxatp_stuffitx_cipher_extra_bit6,&sxatp_stuffitx_cipher_extra_bit7};
static const sx_layout*const sxatp_p2_fork_type[8]={&sxatp_stuffitx_fork_type_bit0,&sxatp_stuffitx_fork_type_bit1,&sxatp_stuffitx_fork_type_bit2,&sxatp_stuffitx_fork_type_bit3,&sxatp_stuffitx_fork_type_bit4,&sxatp_stuffitx_fork_type_bit5,&sxatp_stuffitx_fork_type_bit6,&sxatp_stuffitx_fork_type_bit7};
static const sx_layout*const sxatp_p2_root_value[8]={&sxatp_stuffitx_root_value_bit0,&sxatp_stuffitx_root_value_bit1,&sxatp_stuffitx_root_value_bit2,&sxatp_stuffitx_root_value_bit3,&sxatp_stuffitx_root_value_bit4,&sxatp_stuffitx_root_value_bit5,&sxatp_stuffitx_root_value_bit6,&sxatp_stuffitx_root_value_bit7};
static const sx_layout*const sxatp_p2_block_size[8]={&sxatp_stuffitx_block_size_bit0,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
static const sx_layout*const sxatp_p2_trailer_size[8]={&sxatp_stuffitx_trailer_size_bit0,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

static bool sxatp_dg_unit(sx_context*c,uint64_t p,uint64_t end,unsigned depth,uint64_t*next){uint8_t b[32];if(depth>2||p>end||end-p<8||!sxatp_read(c,p,b,8))return false;uint64_t m=sxatp_uint(b,4,false),n=sxatp_uint(b+4,4,false),z=8;if(m==0){if(n>end-p-8||!sxatp_add(c,&sxatp_dgca_stored_unit,p))return false;z+=n;}else if(m==1){if(end-p<32||!sxatp_read(c,p,b,32))return false;z=32+sxatp_uint(b+24,4,false)+sxatp_uint(b+28,4,false);if(z>end-p||!sxatp_add(c,&sxatp_dgca_compressed_unit,p))return false;}else if(m==2&&depth==0){if(!n||n>(end-p-8)/8||!sxatp_add(c,&sxatp_dgca_plane_unit,p))return false;uint64_t at=p+8;for(uint64_t i=0;i<n;i++)if(!sxatp_dg_unit(c,at,end,depth+1,&at))return false;z=at-p;}else return false;*next=p+z;return true;}
static bool sxatp_dg_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,bool encrypted){if(depth>4)return false;while(p<end){uint8_t h[32];if(end-p<32||!sxatp_read(c,p,h,32))return false;uint64_t z=sxatp_uint(h+8,8,false);if(sxatp_uint(h+4,4,false)!=32||sxatp_uint(h+20,4,false)!=16||z>end-p-32||z>UINT64_MAX-15)return false;uint64_t body=p+32,next=body+((z+15)&~UINT64_C(15));if(next>end||!sxatp_add(c,&sxatp_dgca_chunk,p))return false;
 if(!xx_rt_memcmp(h,"IARC",4)&&z==80){uint64_t flags;if(!sxatp_word(c,body,4,false,&flags)||!sxatp_add(c,&sxatp_dgca_iarc_prefix,body))return false;if(!(flags&1)&&!sxatp_add(c,&sxatp_dgca_iarc_clear_tail,body+32))return false;}
 else if(!xx_rt_memcmp(h,"DGCC",4)&&!encrypted){uint64_t q;if(!sxatp_dg_unit(c,body,body+z,0,&q))return false;}
 else if(!xx_rt_memcmp(h,"DGCA",4)||!xx_rt_memcmp(h,"INFO",4)||(!encrypted&&(!xx_rt_memcmp(h,"DATA",4)||!xx_rt_memcmp(h,"IFDT",4)||!xx_rt_memcmp(h,"IFNM",4)))){if(!sxatp_dg_chunks(c,body,body+z,depth+1,encrypted))return false;}
 p=next;}return true;}
/* Locate the clear IARC flag before interpreting any possibly encrypted DGCC. */
static bool sxatp_dgca(sx_context*c){uint8_t h[32];if(!sxatp_read(c,0,h,32)||xx_rt_memcmp(h,"DGCA",4))return false;uint64_t root=sxatp_uint(h+8,8,false);if(root>(uint64_t)c->size-32)return false;bool encrypted=false;uint64_t p=32;while(p<root+32){if(root+32-p<32||!sxatp_read(c,p,h,32))return false;uint64_t z=sxatp_uint(h+8,8,false);if(z>root+32-p-32||z>UINT64_MAX-15)return false;if(!xx_rt_memcmp(h,"INFO",4)){uint64_t q=p+32,e=q+z;while(q<e){uint8_t a[32];if(e-q<32||!sxatp_read(c,q,a,32))return false;uint64_t n=sxatp_uint(a+8,8,false);if(n>e-q-32||n>UINT64_MAX-15)return false;if(!xx_rt_memcmp(a,"IARC",4)){uint64_t f;if(n<4||!sxatp_word(c,q+32,4,false,&f))return false;encrypted=(f&1)!=0;}uint64_t step=32+((n+15)&~UINT64_C(15));if(step>e-q)return false;q+=step;}}
 uint64_t step=32+((z+15)&~UINT64_C(15));if(step>root+32-p)return false;p+=step;}return sxatp_dg_chunks(c,0,root+32,0,encrypted);}
static bool sxatp_powerarc(sx_context*c){uint8_t h[18];if(!sxatp_read(c,0,h,18)||xx_rt_memcmp(h,"BZIP0001BZh",11)||h[11]<'1'||h[11]>'9'||!sxatp_add(c,&sxatp_powerarc_header,0)||!sxatp_add(c,&sxatp_powerarc_bzip2_stream,8))return false;static const uint8_t block[6]={0x31,0x41,0x59,0x26,0x53,0x59},end[6]={0x17,0x72,0x45,0x38,0x50,0x90};if(!xx_rt_memcmp(h+12,block,6))return sxatp_add(c,&sxatp_powerarc_bzip2_first_block,12);if(!xx_rt_memcmp(h+12,end,6))return sxatp_add(c,&sxatp_powerarc_bzip2_empty_end,12);return false;}

static bool sxatp_space(uint8_t x){return x==' '||x=='\t'||x=='\r'||x=='\n';}
static bool sxatp_hqxchar(uint8_t x){const char*a="!\"#$%&'()*+,-012345689@ABCDEFGHIJKLMNPQRSTUVXYZ[`abcdefhijklmpqr";return x&&xx_rt_strchr(a,x)!=NULL;}
static bool sxatp_binhex(sx_context*c){if(!sxatp_add(c,&sxatp_binhex_banner,0))return false;uint64_t p=45;unsigned colons=0;while(p<(uint64_t)c->size&&c->count<SXATP_LIMIT){uint8_t x;if(!sxatp_read(c,p,&x,1))return false;if(x==':'){if(!sxatp_add(c,&sxatp_binhex_delimiter,p++))return false;if(++colons==2)return true;continue;}const sx_layout*l=sxatp_space(x)?&sxatp_transport_whitespace:colons==1&&sxatp_hqxchar(x)?&sxatp_binhex_encoded_run:NULL;if(!l)return false;uint64_t q=p+1;while(q<(uint64_t)c->size&&q-p<4096){uint8_t y;if(!sxatp_read(c,q,&y,1))return false;if(l==&sxatp_transport_whitespace?!sxatp_space(y):!sxatp_hqxchar(y))break;q++;}if(!sxatp_text(c,l,p,q-p,false))return false;p=q;}return true;}
static bool sxatp_hex(uint8_t x){return(x>='0'&&x<='9')||(x>='A'&&x<='F')||(x>='a'&&x<='f');}
static bool sxatp_qp(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size&&c->count<SXATP_LIMIT){uint8_t b[3];if(!sxatp_read(c,p,b,1))return false;uint64_t q=p+1;const sx_layout*l=&sxatp_qp_literal_run;if(b[0]=='='){if(q==(uint64_t)c->size)l=&sxatp_qp_soft_break;else{if(!sxatp_read(c,q,b+1,1))return false;if(b[1]=='\n')q++,l=&sxatp_qp_soft_break;else if(b[1]=='\r'&&sxatp_read(c,q+1,b+2,1)&&b[2]=='\n')q+=2,l=&sxatp_qp_soft_break;else if(sxatp_hex(b[1])&&sxatp_read(c,q+1,b+2,1)&&sxatp_hex(b[2])){if(!sxatp_add(c,&sxatp_qp_hex_escape,p))return false;p+=3;continue;}else return false;}}
 else if(b[0]=='\r'||b[0]=='\n'){l=&sxatp_transport_line_end;if(b[0]=='\r'&&q<(uint64_t)c->size&&sxatp_read(c,q,b+1,1)&&b[1]=='\n')q++;}
 else if(!b[0]||b[0]==26){l=&sxatp_qp_padding;while(q<(uint64_t)c->size&&q-p<4096){uint8_t x;if(!sxatp_read(c,q,&x,1))return false;if(x&&x!=26)break;q++;}}
 else{while(q<(uint64_t)c->size&&q-p<4096){uint8_t x;if(!sxatp_read(c,q,&x,1))return false;if(x=='='||x=='\r'||x=='\n'||!x||x==26)break;q++;}}
 if(!sxatp_text(c,l,p,q-p,false))return false;p=q;}return true;}
static bool sxatp_shword(sx_context*c,const uint8_t*b,size_t n,size_t p,uint64_t base,const sx_layout*l,size_t*end,size_t*start,size_t*len){while(p<n&&(b[p]==' '||b[p]=='\t'||b[p]=='\r'))p++;if(p>=n)return false;size_t original=p;if(b[p]=='\\')p++;if(p>=n)return false;size_t a=p,z;if(b[p]=='\''||b[p]=='"'){uint8_t quote=b[p++];a=p;while(p<n&&b[p]!=quote)p++;if(p>=n)return false;z=p-a;*end=p+1;}else{a=p;while(p<n&&!sxatp_space(b[p])&&!xx_rt_strchr(";&|<>()",b[p]))p++;z=p-a;*end=p;}if(!z)return false;if(a>original&&!sxatp_text(c,&sxatp_shar_quoted_marker,base+original,a-original,false))return false;if(*end>a+z&&!sxatp_text(c,&sxatp_shar_quoted_marker,base+a+z,*end-a-z,false))return false;if(!sxatp_text(c,l,base+a,z,false))return false;*start=a;*len=z;return true;}
static bool sxatp_shar_one(sx_context*c,uint64_t p,uint64_t header_size,uint64_t end){uint8_t b[4096];size_t n;uint64_t next;if(!header_size||!sxatp_line(c,p,b,sizeof(b),&n,&next)||next-p>header_size)return false;size_t a=0;while(a<n&&(b[a]==' '||b[a]=='\t'))a++;size_t cmd=a;while(a<n&&!sxatp_space(b[a])&&!xx_rt_strchr(";&|<>()",b[a]))a++;if(!sxatp_text(c,&sxatp_shar_command,p+cmd,a-cmd,false))return false;size_t here=a;while(here+1<n&&(b[here]!='<'||b[here+1]!='<'))here++;if(here+1>=n)return false;size_t op=2;if(here+2<n&&b[here+2]=='-')op++;if(!sxatp_text(c,&sxatp_shar_heredoc_operator,p+here,op,false))return false;size_t de,ds,dn;if(!sxatp_shword(c,b,n,here+op,p,&sxatp_shar_delimiter,&de,&ds,&dn))return false;
 for(size_t k=a;k+5<here;k++)if(b[k]=='s'&&b[k+1]=='/'&&b[k+2]=='^'){size_t z=(b[k+3]=='\\'&&b[k+4]=='t')?7:6;if(k+z<=here&&b[k+z-1]=='/'&&b[k+z-2]=='/')if(!sxatp_text(c,&sxatp_shar_prefix_expression,p+k,z,false))return false;}
 size_t red=a;while(red<n&&(b[red]!='>'||(red>=here&&red<de)))red++;if(red<n){size_t rz=red+1<n&&b[red+1]=='>'?2:1,e,s,z;if(!sxatp_text(c,&sxatp_shar_redirection,p+red,rz,false)||!sxatp_shword(c,b,n,red+rz,p,&sxatp_shar_name,&e,&s,&z))return false;}else if(next<p+header_size){size_t z;uint64_t nn;if(!sxatp_line(c,next,b,sizeof(b),&z,&nn)||!sxatp_text(c,&sxatp_shar_uu_begin,next,z,false))return false;}
 /* Native record cursor excludes the ending delimiter. A truncated body has no terminator. */
 if(end<(uint64_t)c->size){uint8_t t[4096];size_t z;uint64_t nn;if(!sxatp_line(c,end,t,sizeof(t),&z,&nn))return false;size_t k=0;if(op==3)while(k<z&&t[k]=='\t')k++;if(z-k==dn&&!sxatp_text(c,&sxatp_shar_terminator,end+k,dn,false))return false;}return true;}
static bool sxatp_shar(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXATP_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;if(r->header_offset<f->base_address||r->header_size<=0||r->data_offset<f->base_address||r->compressed_size<0){ok=false;break;}uint64_t p=(uint64_t)(r->header_offset-f->base_address),d=(uint64_t)(r->data_offset-f->base_address),z=(uint64_t)r->compressed_size;if(!sxatp_span(c,p,(uint64_t)r->header_size)||!sxatp_span(c,d,z)||!sxatp_shar_one(c,p,(uint64_t)r->header_size,d+z)){ok=false;break;}if(!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);return ok;}

typedef struct sxatp_bits{uint64_t pos;unsigned bit;}sxatp_bits;
static void sxatp_align(sxatp_bits*b){if(b->bit){b->pos++;b->bit=0;}}
static bool sxatp_bit(sx_context*c,sxatp_bits*b,unsigned*v){uint8_t x;if(!sxatp_read(c,b->pos,&x,1))return false;*v=(x>>b->bit)&1U;if(++b->bit==8){b->pos++;b->bit=0;}return true;}
static bool sxatp_p2(sx_context*c,sxatp_bits*b,const sx_layout*const rows[8],uint64_t*v){sxatp_bits first=*b;unsigned ones=1,pos=0,x;uint64_t value=0;for(;;){if(!sxatp_bit(c,b,&x))return false;if(!x)break;if(++ones>=64)return false;}while(ones){if(pos>=64||!sxatp_bit(c,b,&x))return false;if(x){value|=UINT64_C(1)<<pos;ones--;}pos++;}*v=value-1;uint64_t bytes=b->pos+(b->bit!=0)-first.pos;if(!bytes||bytes>17)return false;return sxatp_put(c,rows[first.bit],first.pos,bytes,true);}
static bool sxatp_sxblocks(sx_context*c,sxatp_bits*b){uint64_t n;sxatp_align(b);for(unsigned i=0;i<SXATP_LIMIT;i++){if(!sxatp_p2(c,b,sxatp_p2_block_size,&n))return false;if(!n)break;sxatp_align(b);if(!sxatp_span(c,b->pos,n))return false;b->pos+=n;}sxatp_align(b);bool first=true;for(unsigned i=0;i<SXATP_LIMIT;i++){if(!sxatp_p2(c,b,sxatp_p2_trailer_size,&n))return false;if(!n)return true;sxatp_align(b);if(!sxatp_span(c,b->pos,n))return false;if(first&&n==4&&!sxatp_add(c,&sxatp_stuffitx_crc32,b->pos))return false;b->pos+=n;first=false;}return false;}
static bool sxatp_stuffitx(sx_context*c){if(!sxatp_add(c,&sxatp_stuffitx_signature,0))return false;sxatp_bits b={8,0};for(unsigned e=0;e<SXATP_LIMIT;e++){sxatp_align(&b);if(!sxatp_put(c,&sxatp_stuffitx_element_flag,b.pos,1,true))return false;unsigned flag;if(!sxatp_bit(c,&b,&flag))return false;uint64_t type,key,value,size=0;bool has_size=false;if(!sxatp_p2(c,&b,sxatp_p2_element_type,&type))return false;for(unsigned k=0;;k++){if(k>256||!sxatp_p2(c,&b,sxatp_p2_attribute_key,&key))return false;if(!key)break;const sx_layout*const*rows=key==1?sxatp_p2_object_id:key==2?sxatp_p2_parent_id:key==3?sxatp_p2_stream_id:key==4?sxatp_p2_fork_index:key==5?sxatp_p2_declared_size:sxatp_p2_attribute_value;if(!sxatp_p2(c,&b,rows,&value))return false;if(key==5)size=value,has_size=true;}
 for(unsigned k=0;;k++){if(k>256||!sxatp_p2(c,&b,sxatp_p2_algorithm_key,&key))return false;if(!key)break;if(!sxatp_p2(c,&b,sxatp_p2_algorithm_value,&value))return false;if(key==4&&!sxatp_p2(c,&b,sxatp_p2_cipher_extra,&value))return false;}
 if(type==0)return true;if(type==1||type==5||type>10){if(!sxatp_sxblocks(c,&b))return false;}else if(type==3){if(!sxatp_p2(c,&b,sxatp_p2_fork_type,&value))return false;}else if(type==7){if(!sxatp_p2(c,&b,sxatp_p2_root_value,&value))return false;}else if(type==6){if(!has_size)return false;if(size){sxatp_align(&b);if(!sxatp_span(c,b.pos,size))return false;b.pos+=size;}}else if(type==10)return false;}return false;}

static bool sx_archivetransport_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_DGCA:case XX_FILE_TYPE_STUFFITX:case XX_FILE_TYPE_SHAR:case XX_FILE_TYPE_BINHEX:case XX_FILE_TYPE_QUOTED_PRINTABLE_ENCODED_FIL:case XX_FILE_TYPE_POWERARC:return true;default:return false;}}
static bool sx_archivetransport_build(sx_context*c){if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_DGCA:ok=sxatp_dgca(c);break;case XX_FILE_TYPE_STUFFITX:ok=sxatp_stuffitx(c);break;case XX_FILE_TYPE_SHAR:ok=sxatp_shar(c);break;case XX_FILE_TYPE_BINHEX:ok=sxatp_binhex(c);break;case XX_FILE_TYPE_QUOTED_PRINTABLE_ENCODED_FIL:ok=sxatp_qp(c);break;case XX_FILE_TYPE_POWERARC:ok=sxatp_powerarc(c);break;default:return false;}(void)ok;return c->count&&sxatp_finish(c);}
