/* SPDX-License-Identifier: MIT. Physical archive metadata. Scope: docs/data_struct_archivelater_scope.txt. */
static const xx_data_struct_field_desc sxal_aldus_header_fields[] = {
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",16,2,SX_SIZE),
 SX_FIELD("name","char[32]",18,32,SX_STRING),
 SX_FIELD("unpacked_size","uint32",50,4,SX_SIZE),
};
static const sx_layout sxal_aldus_header = {UINT32_C(0x60200001),"aldus_header",sxal_aldus_header_fields,SX_COUNT(sxal_aldus_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_aldus_timestamp_fields[] = {
 SX_FIELD("modified","uint32",0,4,SX_NONE),
};
static const sx_layout sxal_aldus_timestamp = {UINT32_C(0x60200002),"aldus_timestamp",sxal_aldus_timestamp_fields,SX_COUNT(sxal_aldus_timestamp_fields),SX_LE};
static const xx_data_struct_field_desc sxal_aldus_stream_fields[] = {
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("block_size","uint16",2,2,SX_SIZE),
 SX_FIELD("last_block_size","uint16",4,2,SX_SIZE),
 SX_FIELD("block_count","uint32",6,4,SX_COUNT_PROP),
 SX_FIELD("block_table_offset","uint32",10,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",14,4,SX_OFFSET),
 SX_FIELD("archive_size","uint32",18,4,SX_SIZE),
};
static const sx_layout sxal_aldus_stream = {UINT32_C(0x60200003),"aldus_stream",sxal_aldus_stream_fields,SX_COUNT(sxal_aldus_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxal_aldus_block_size_fields[] = {
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxal_aldus_block_size = {UINT32_C(0x60200004),"aldus_block_size",sxal_aldus_block_size_fields,SX_COUNT(sxal_aldus_block_size_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ampk_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("reserved5","uint8",5,1,SX_RESERVED),
 SX_FIELD("directory_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("file_count","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("unpacked_size","uint32",10,4,SX_SIZE),
 SX_FIELD("packed_size_hint","uint32",14,4,SX_SIZE),
 SX_FIELD("unused","uint8[2]",18,2,SX_NONE),
};
static const sx_layout sxal_ampk_header = {UINT32_C(0x60200005),"ampk_header",sxal_ampk_header_fields,SX_COUNT(sxal_ampk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ampk_record_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("name_size","uint8",1,1,SX_SIZE),
 SX_FIELD("directory_size_plus3","uint32",2,4,SX_NONE),
};
static const sx_layout sxal_ampk_record = {UINT32_C(0x60200006),"ampk_record",sxal_ampk_record_fields,SX_COUNT(sxal_ampk_record_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ampk_file_fields[] = {
 SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
 SX_FIELD("packed_size_hint","uint32",4,4,SX_SIZE),
 SX_FIELD("method","uint8",8,1,SX_ID),
 SX_FIELD("padding9","uint8",9,1,SX_RESERVED),
 SX_FIELD("protection","uint32",10,4,SX_FLAGS),
 SX_FIELD("padding14","uint8[2]",14,2,SX_RESERVED),
 SX_FIELD("comment_size","uint8",16,1,SX_SIZE),
 SX_FIELD("padding17","uint8",17,1,SX_RESERVED),
};
static const sx_layout sxal_ampk_file = {UINT32_C(0x60200007),"ampk_file",sxal_ampk_file_fields,SX_COUNT(sxal_ampk_file_fields),SX_BE};
static const xx_data_struct_field_desc sxal_arx_member_fields[] = {
 SX_FIELD("header_size_minus2","uint8",0,1,SX_NONE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_ID),
 SX_FIELD("zero7","uint8",7,1,SX_RESERVED),
 SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("time","uint16",16,2,SX_NONE),
 SX_FIELD("date","uint16",18,2,SX_NONE),
 SX_FIELD("unknown20","uint8[2]",20,2,SX_NONE),
 SX_FIELD("name_size","uint8",22,1,SX_SIZE),
};
static const sx_layout sxal_arx_member = {UINT32_C(0x60200008),"arx_member",sxal_arx_member_fields,SX_COUNT(sxal_arx_member_fields),SX_LE};
static const xx_data_struct_field_desc sxal_arx_end_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxal_arx_end = {UINT32_C(0x60200009),"arx_end",sxal_arx_end_fields,SX_COUNT(sxal_arx_end_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_packit_header_fields[] = {
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
};
static const sx_layout sxal_dos_packit_header = {UINT32_C(0x6020000a),"dos_packit_header",sxal_dos_packit_header_fields,SX_COUNT(sxal_dos_packit_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_packit_member_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_ID),
 SX_FIELD("data_size","int32",2,4,SX_SIZE),
 SX_FIELD("repeated_data_size","int32",6,4,SX_SIZE),
 SX_FIELD("date","uint16",10,2,SX_NONE),
 SX_FIELD("time","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",18,1,SX_SIZE),
};
static const sx_layout sxal_dos_packit_member = {UINT32_C(0x6020000b),"dos_packit_member",sxal_dos_packit_member_fields,SX_COUNT(sxal_dos_packit_member_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_packit_end_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxal_dos_packit_end = {UINT32_C(0x6020000c),"dos_packit_end",sxal_dos_packit_end_fields,SX_COUNT(sxal_dos_packit_end_fields),SX_LE};
static const xx_data_struct_field_desc sxal_asar_header_fields[] = {
 SX_FIELD("size_pickle_payload_size","uint32",0,4,SX_SIZE),
 SX_FIELD("header_pickle_size","uint32",4,4,SX_SIZE),
 SX_FIELD("header_pickle_payload_size","uint32",8,4,SX_SIZE),
 SX_FIELD("json_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxal_asar_header = {UINT32_C(0x6020000d),"asar_header",sxal_asar_header_fields,SX_COUNT(sxal_asar_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_header_fields[] = {
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("version","uint8",1,1,SX_ID),
 SX_FIELD("revision","uint8",2,1,SX_ID),
 SX_FIELD("volume_control","uint8",3,1,SX_ID),
 SX_FIELD("writer_data","uint8[4]",4,4,SX_NONE),
 SX_FIELD("byte_order_flags","uint8",8,1,SX_FLAGS),
 SX_FIELD("writer_data9","uint8",9,1,SX_NONE),
};
static const sx_layout sxal_pea_header = {UINT32_C(0x6020000e),"pea_header",sxal_pea_header_fields,SX_COUNT(sxal_pea_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_trigger_le_fields[] = {
 SX_FIELD("zero_name_size","uint16",0,2,SX_SIZE),
 SX_FIELD("signature","char[4]",2,4,SX_SIGNATURE),
};
static const sx_layout sxal_pea_trigger_le = {UINT32_C(0x6020000f),"pea_trigger_le",sxal_pea_trigger_le_fields,SX_COUNT(sxal_pea_trigger_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_stream_le_fields[] = {
 SX_FIELD("compression","uint8",0,1,SX_ID),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("stream_control","uint8",2,1,SX_ID),
 SX_FIELD("object_control","uint8",3,1,SX_ID),
};
static const sx_layout sxal_pea_stream_le = {UINT32_C(0x60200010),"pea_stream_le",sxal_pea_stream_le_fields,SX_COUNT(sxal_pea_stream_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_block_size_le_fields[] = {
 SX_FIELD("block_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxal_pea_block_size_le = {UINT32_C(0x60200011),"pea_block_size_le",sxal_pea_block_size_le_fields,SX_COUNT(sxal_pea_block_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_name_size_le_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxal_pea_name_size_le = {UINT32_C(0x60200012),"pea_name_size_le",sxal_pea_name_size_le_fields,SX_COUNT(sxal_pea_name_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_object_le_fields[] = {
 SX_FIELD("modified","uint32",0,4,SX_NONE),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxal_pea_object_le = {UINT32_C(0x60200013),"pea_object_le",sxal_pea_object_le_fields,SX_COUNT(sxal_pea_object_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_file_size_le_fields[] = {
 SX_FIELD("unpacked_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxal_pea_file_size_le = {UINT32_C(0x60200014),"pea_file_size_le",sxal_pea_file_size_le_fields,SX_COUNT(sxal_pea_file_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_packed_size_le_fields[] = {
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxal_pea_packed_size_le = {UINT32_C(0x60200015),"pea_packed_size_le",sxal_pea_packed_size_le_fields,SX_COUNT(sxal_pea_packed_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_last_size_le_fields[] = {
 SX_FIELD("repeated_last_block_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxal_pea_last_size_le = {UINT32_C(0x60200016),"pea_last_size_le",sxal_pea_last_size_le_fields,SX_COUNT(sxal_pea_last_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxal_pea_trigger_be_fields[] = {
 SX_FIELD("zero_name_size","uint16",0,2,SX_SIZE),
 SX_FIELD("signature","char[4]",2,4,SX_SIGNATURE),
};
static const sx_layout sxal_pea_trigger_be = {UINT32_C(0x60200017),"pea_trigger_be",sxal_pea_trigger_be_fields,SX_COUNT(sxal_pea_trigger_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_stream_be_fields[] = {
 SX_FIELD("compression","uint8",0,1,SX_ID),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("stream_control","uint8",2,1,SX_ID),
 SX_FIELD("object_control","uint8",3,1,SX_ID),
};
static const sx_layout sxal_pea_stream_be = {UINT32_C(0x60200018),"pea_stream_be",sxal_pea_stream_be_fields,SX_COUNT(sxal_pea_stream_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_block_size_be_fields[] = {
 SX_FIELD("block_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxal_pea_block_size_be = {UINT32_C(0x60200019),"pea_block_size_be",sxal_pea_block_size_be_fields,SX_COUNT(sxal_pea_block_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_name_size_be_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxal_pea_name_size_be = {UINT32_C(0x6020001a),"pea_name_size_be",sxal_pea_name_size_be_fields,SX_COUNT(sxal_pea_name_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_object_be_fields[] = {
 SX_FIELD("modified","uint32",0,4,SX_NONE),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxal_pea_object_be = {UINT32_C(0x6020001b),"pea_object_be",sxal_pea_object_be_fields,SX_COUNT(sxal_pea_object_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_file_size_be_fields[] = {
 SX_FIELD("unpacked_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxal_pea_file_size_be = {UINT32_C(0x6020001c),"pea_file_size_be",sxal_pea_file_size_be_fields,SX_COUNT(sxal_pea_file_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_packed_size_be_fields[] = {
 SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxal_pea_packed_size_be = {UINT32_C(0x6020001d),"pea_packed_size_be",sxal_pea_packed_size_be_fields,SX_COUNT(sxal_pea_packed_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_pea_last_size_be_fields[] = {
 SX_FIELD("repeated_last_block_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxal_pea_last_size_be = {UINT32_C(0x6020001e),"pea_last_size_be",sxal_pea_last_size_be_fields,SX_COUNT(sxal_pea_last_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_header_fields[] = {
 SX_FIELD("banner","char[80]",0,80,SX_SIGNATURE),
 SX_FIELD("marker","uint16",80,2,SX_SIGNATURE),
 SX_FIELD("version","uint8",82,1,SX_ID),
 SX_FIELD("flags","uint8",83,1,SX_FLAGS),
 SX_FIELD("archive_size","uint32",84,4,SX_SIZE),
 SX_FIELD("entry_offset","uint32",88,4,SX_OFFSET),
 SX_FIELD("root_entry_count","uint16",92,2,SX_COUNT_PROP),
 SX_FIELD("first_entry_offset","uint32",94,4,SX_OFFSET),
 SX_FIELD("header_crc16","uint16",98,2,SX_CHECKSUM),
};
static const sx_layout sxal_sit5_header = {UINT32_C(0x6020001f),"sit5_header",sxal_sit5_header_fields,SX_COUNT(sxal_sit5_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_file_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("unknown5","uint8",5,1,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown8","uint8",8,1,SX_NONE),
 SX_FIELD("flags","uint8",9,1,SX_FLAGS),
 SX_FIELD("created","uint32",10,4,SX_NONE),
 SX_FIELD("modified","uint32",14,4,SX_NONE),
 SX_FIELD("previous_entry_offset","uint32",18,4,SX_OFFSET),
 SX_FIELD("next_entry_offset","uint32",22,4,SX_OFFSET),
 SX_FIELD("parent_entry_offset","uint32",26,4,SX_OFFSET),
 SX_FIELD("name_size","uint16",30,2,SX_SIZE),
 SX_FIELD("header_crc16","uint16",32,2,SX_CHECKSUM),
 SX_FIELD("data_unpacked_size","uint32",34,4,SX_SIZE),
 SX_FIELD("data_packed_size","uint32",38,4,SX_SIZE),
 SX_FIELD("data_crc16","uint16",42,2,SX_CHECKSUM),
 SX_FIELD("unknown44","uint16",44,2,SX_NONE),
 SX_FIELD("method","uint8",46,1,SX_ID),
 SX_FIELD("password_size","uint8",47,1,SX_SIZE),
};
static const sx_layout sxal_sit5_file = {UINT32_C(0x60200020),"sit5_file",sxal_sit5_file_fields,SX_COUNT(sxal_sit5_file_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_folder_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("unknown5","uint8",5,1,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown8","uint8",8,1,SX_NONE),
 SX_FIELD("flags","uint8",9,1,SX_FLAGS),
 SX_FIELD("created","uint32",10,4,SX_NONE),
 SX_FIELD("modified","uint32",14,4,SX_NONE),
 SX_FIELD("previous_entry_offset","uint32",18,4,SX_OFFSET),
 SX_FIELD("next_entry_offset","uint32",22,4,SX_OFFSET),
 SX_FIELD("parent_entry_offset","uint32",26,4,SX_OFFSET),
 SX_FIELD("name_size","uint16",30,2,SX_SIZE),
 SX_FIELD("header_crc16","uint16",32,2,SX_CHECKSUM),
 SX_FIELD("first_child_offset","uint32",34,4,SX_OFFSET),
 SX_FIELD("folder_size","uint32",38,4,SX_SIZE),
 SX_FIELD("unknown42","uint8[4]",42,4,SX_NONE),
 SX_FIELD("child_count","uint16",46,2,SX_COUNT_PROP),
};
static const sx_layout sxal_sit5_folder = {UINT32_C(0x60200021),"sit5_folder",sxal_sit5_folder_fields,SX_COUNT(sxal_sit5_folder_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_second_v1_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("unknown2","uint16",2,2,SX_NONE),
 SX_FIELD("file_type","char[4]",4,4,SX_ID),
 SX_FIELD("creator","char[4]",8,4,SX_ID),
 SX_FIELD("finder_flags","uint16",12,2,SX_FLAGS),
 SX_FIELD("finder_metadata","uint8[22]",14,22,SX_NONE),
};
static const sx_layout sxal_sit5_second_v1 = {UINT32_C(0x60200022),"sit5_second_v1",sxal_sit5_second_v1_fields,SX_COUNT(sxal_sit5_second_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_second_v3_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("unknown2","uint16",2,2,SX_NONE),
 SX_FIELD("file_type","char[4]",4,4,SX_ID),
 SX_FIELD("creator","char[4]",8,4,SX_ID),
 SX_FIELD("finder_flags","uint16",12,2,SX_FLAGS),
 SX_FIELD("finder_metadata","uint8[18]",14,18,SX_NONE),
};
static const sx_layout sxal_sit5_second_v3 = {UINT32_C(0x60200023),"sit5_second_v3",sxal_sit5_second_v3_fields,SX_COUNT(sxal_sit5_second_v3_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_resource_fields[] = {
 SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("crc16","uint16",8,2,SX_CHECKSUM),
 SX_FIELD("unknown10","uint16",10,2,SX_NONE),
 SX_FIELD("method","uint8",12,1,SX_ID),
 SX_FIELD("password_size","uint8",13,1,SX_SIZE),
};
static const sx_layout sxal_sit5_resource = {UINT32_C(0x60200024),"sit5_resource",sxal_sit5_resource_fields,SX_COUNT(sxal_sit5_resource_fields),SX_BE};
static const xx_data_struct_field_desc sxal_diskdoubler_file_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("data_unpacked_size","uint32",4,4,SX_SIZE),
 SX_FIELD("data_packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("resource_unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("resource_packed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("data_method","uint8",20,1,SX_ID),
 SX_FIELD("resource_method","uint8",21,1,SX_ID),
 SX_FIELD("generation","uint8",22,1,SX_ID),
 SX_FIELD("finder_metadata23","uint8[25]",23,25,SX_NONE),
 SX_FIELD("data_sum16","uint16",48,2,SX_CHECKSUM),
 SX_FIELD("resource_sum16","uint16",50,2,SX_CHECKSUM),
 SX_FIELD("lzw_info","uint8",52,1,SX_NONE),
 SX_FIELD("padding","uint8",53,1,SX_NONE),
 SX_FIELD("data_delta_filter","uint16",54,2,SX_ID),
 SX_FIELD("resource_delta_filter","uint16",56,2,SX_ID),
 SX_FIELD("finder_metadata58","uint8[24]",58,24,SX_NONE),
 SX_FIELD("header_crc16","uint16",82,2,SX_CHECKSUM),
};
static const sx_layout sxal_diskdoubler_file = {UINT32_C(0x60200025),"diskdoubler_file",sxal_diskdoubler_file_fields,SX_COUNT(sxal_diskdoubler_file_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_header_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("metadata6","uint8[22]",6,22,SX_NONE),
 SX_FIELD("unpacked_size","uint32",28,4,SX_SIZE),
 SX_FIELD("metadata32","uint8[4]",32,4,SX_NONE),
 SX_FIELD("archive_size","uint32",36,4,SX_SIZE),
 SX_FIELD("end_record_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("metadata44","uint8[16]",44,16,SX_NONE),
 SX_FIELD("header_crc16","uint16",60,2,SX_CHECKSUM),
};
static const sx_layout sxal_dda2_header = {UINT32_C(0x60200026),"dda2_header",sxal_dda2_header_fields,SX_COUNT(sxal_dda2_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_packed_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("kind","uint16",4,2,SX_FLAGS),
 SX_FIELD("name_size","uint8",6,1,SX_SIZE),
 SX_FIELD("name","char[31]",7,31,SX_STRING),
 SX_FIELD("parent_folder_id","uint32",38,4,SX_ID),
 SX_FIELD("record_size","uint32",42,4,SX_SIZE),
 SX_FIELD("metadata46","uint8[8]",46,8,SX_NONE),
 SX_FIELD("header_crc16","uint16",54,2,SX_CHECKSUM),
};
static const sx_layout sxal_dda2_packed = {UINT32_C(0x60200027),"dda2_packed",sxal_dda2_packed_fields,SX_COUNT(sxal_dda2_packed_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_folder_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("kind","uint16",4,2,SX_FLAGS),
 SX_FIELD("name_size","uint8",6,1,SX_SIZE),
 SX_FIELD("name","char[31]",7,31,SX_STRING),
 SX_FIELD("parent_folder_id","uint32",38,4,SX_ID),
 SX_FIELD("record_size","uint32",42,4,SX_SIZE),
 SX_FIELD("metadata46","uint8[16]",46,16,SX_NONE),
 SX_FIELD("folder_id","uint32",62,4,SX_ID),
 SX_FIELD("metadata66","uint8[20]",66,20,SX_NONE),
 SX_FIELD("header_crc16","uint16",86,2,SX_CHECKSUM),
};
static const sx_layout sxal_dda2_folder = {UINT32_C(0x60200028),"dda2_folder",sxal_dda2_folder_fields,SX_COUNT(sxal_dda2_folder_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_stored_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("kind","uint16",4,2,SX_FLAGS),
 SX_FIELD("name_size","uint8",6,1,SX_SIZE),
 SX_FIELD("name","char[31]",7,31,SX_STRING),
 SX_FIELD("parent_folder_id","uint32",38,4,SX_ID),
 SX_FIELD("record_size","uint32",42,4,SX_SIZE),
 SX_FIELD("metadata46","uint8[32]",46,32,SX_NONE),
 SX_FIELD("data_size","uint32",78,4,SX_SIZE),
 SX_FIELD("resource_size","uint32",82,4,SX_SIZE),
 SX_FIELD("data_xor8","uint8",86,1,SX_SIGNATURE),
 SX_FIELD("resource_xor8","uint8",87,1,SX_SIGNATURE),
 SX_FIELD("header_crc16","uint16",88,2,SX_CHECKSUM),
};
static const sx_layout sxal_dda2_stored = {UINT32_C(0x60200029),"dda2_stored",sxal_dda2_stored_fields,SX_COUNT(sxal_dda2_stored_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_end_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("kind","uint16",4,2,SX_SIGNATURE),
};
static const sx_layout sxal_dda2_end = {UINT32_C(0x6020002a),"dda2_end",sxal_dda2_end_fields,SX_COUNT(sxal_dda2_end_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_footer_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("index_size","uint32",2,4,SX_SIZE),
 SX_FIELD("index_crc16","uint16",6,2,SX_CHECKSUM),
 SX_FIELD("reserved","uint8[8]",8,8,SX_RESERVED),
};
static const sx_layout sxal_dda2_footer = {UINT32_C(0x6020002b),"dda2_footer",sxal_dda2_footer_fields,SX_COUNT(sxal_dda2_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxal_dda2_index_word_fields[] = {
 SX_FIELD("folder_id_or_record_offset","uint32",0,4,SX_NONE),
};
static const sx_layout sxal_dda2_index_word = {UINT32_C(0x6020002c),"dda2_index_word",sxal_dda2_index_word_fields,SX_COUNT(sxal_dda2_index_word_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ddar_header_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("archive_metadata","uint8[72]",4,72,SX_NONE),
 SX_FIELD("header_crc16","uint16",76,2,SX_CHECKSUM),
};
static const sx_layout sxal_ddar_header = {UINT32_C(0x6020002d),"ddar_header",sxal_ddar_header_fields,SX_COUNT(sxal_ddar_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ddar_member_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown4","uint8[4]",4,4,SX_NONE),
 SX_FIELD("name_size","uint8",8,1,SX_SIZE),
 SX_FIELD("name","char[63]",9,63,SX_STRING),
 SX_FIELD("folder_start","uint8",72,1,SX_FLAGS),
 SX_FIELD("folder_end","uint8",73,1,SX_FLAGS),
 SX_FIELD("data_size","uint32",74,4,SX_SIZE),
 SX_FIELD("resource_size","uint32",78,4,SX_SIZE),
 SX_FIELD("finder_metadata","uint8[36]",82,36,SX_NONE),
 SX_FIELD("data_sum16","uint16",118,2,SX_CHECKSUM),
 SX_FIELD("resource_sum16","uint16",120,2,SX_CHECKSUM),
 SX_FIELD("header_crc16","uint16",122,2,SX_CHECKSUM),
};
static const sx_layout sxal_ddar_member = {UINT32_C(0x6020002e),"ddar_member",sxal_ddar_member_fields,SX_COUNT(sxal_ddar_member_fields),SX_BE};
static const xx_data_struct_field_desc sxal_xpk_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("packed_size_minus8","uint32",4,4,SX_NONE),
 SX_FIELD("subpacker","char[4]",8,4,SX_ID),
 SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("plaintext_prefix","uint8[16]",16,16,SX_NONE),
 SX_FIELD("flags","uint8",32,1,SX_FLAGS),
 SX_FIELD("header_xor8","uint8",33,1,SX_SIGNATURE),
 SX_FIELD("subpacker_version","uint8",34,1,SX_ID),
 SX_FIELD("master_version","uint8",35,1,SX_ID),
};
static const sx_layout sxal_xpk_header = {UINT32_C(0x6020002f),"xpk_header",sxal_xpk_header_fields,SX_COUNT(sxal_xpk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_xpk_extension_size_fields[] = {
 SX_FIELD("extension_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxal_xpk_extension_size = {UINT32_C(0x60200030),"xpk_extension_size",sxal_xpk_extension_size_fields,SX_COUNT(sxal_xpk_extension_size_fields),SX_BE};
static const xx_data_struct_field_desc sxal_xpk_chunk2_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("header_xor8","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("data_xor16","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("unpacked_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxal_xpk_chunk2 = {UINT32_C(0x60200031),"xpk_chunk2",sxal_xpk_chunk2_fields,SX_COUNT(sxal_xpk_chunk2_fields),SX_BE};
static const xx_data_struct_field_desc sxal_xpk_chunk4_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("header_xor8","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("data_xor16","uint16",2,2,SX_SIGNATURE),
 SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxal_xpk_chunk4 = {UINT32_C(0x60200032),"xpk_chunk4",sxal_xpk_chunk4_fields,SX_COUNT(sxal_xpk_chunk4_fields),SX_BE};
static const xx_data_struct_field_desc sxal_ppmd_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("model_info","uint16",8,2,SX_FLAGS),
 SX_FIELD("name_size_and_restore","uint16",10,2,SX_NONE),
 SX_FIELD("modified","uint32",12,4,SX_NONE),
};
static const sx_layout sxal_ppmd_header = {UINT32_C(0x60200033),"ppmd_header",sxal_ppmd_header_fields,SX_COUNT(sxal_ppmd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("major","uint8",4,1,SX_ID),
 SX_FIELD("minor","uint8",5,1,SX_ID),
 SX_FIELD("unpacked_size","uint64",6,8,SX_SIZE),
 SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
 SX_FIELD("lzma_properties","uint8",16,1,SX_NONE),
 SX_FIELD("lzma_dictionary_size","uint32",17,4,SX_SIZE),
 SX_FIELD("md5_present","uint8",21,1,SX_FLAGS),
 SX_FIELD("encrypted","uint8",22,1,SX_FLAGS),
 SX_FIELD("reserved23","uint8",23,1,SX_RESERVED),
};
static const sx_layout sxal_lrzip_header = {UINT32_C(0x60200034),"lrzip_header",sxal_lrzip_header_fields,SX_COUNT(sxal_lrzip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk1_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint8",2,1,SX_SIZE),
};
static const sx_layout sxal_lrzip_chunk1 = {UINT32_C(0x60200035),"lrzip_chunk1",sxal_lrzip_chunk1_fields,SX_COUNT(sxal_lrzip_chunk1_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block1_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint8",1,1,SX_SIZE),
 SX_FIELD("unpacked_size","uint8",2,1,SX_SIZE),
 SX_FIELD("next_block_offset","uint8",3,1,SX_OFFSET),
};
static const sx_layout sxal_lrzip_block1 = {UINT32_C(0x60200036),"lrzip_block1",sxal_lrzip_block1_fields,SX_COUNT(sxal_lrzip_block1_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk2_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxal_lrzip_chunk2 = {UINT32_C(0x60200037),"lrzip_chunk2",sxal_lrzip_chunk2_fields,SX_COUNT(sxal_lrzip_chunk2_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block2_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint16",1,2,SX_SIZE),
 SX_FIELD("unpacked_size","uint16",3,2,SX_SIZE),
 SX_FIELD("next_block_offset","uint16",5,2,SX_OFFSET),
};
static const sx_layout sxal_lrzip_block2 = {UINT32_C(0x60200038),"lrzip_block2",sxal_lrzip_block2_fields,SX_COUNT(sxal_lrzip_block2_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk3_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint24",2,3,SX_SIZE),
};
static const sx_layout sxal_lrzip_chunk3 = {UINT32_C(0x60200039),"lrzip_chunk3",sxal_lrzip_chunk3_fields,SX_COUNT(sxal_lrzip_chunk3_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block3_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint24",1,3,SX_SIZE),
 SX_FIELD("unpacked_size","uint24",4,3,SX_SIZE),
 SX_FIELD("next_block_offset","uint24",7,3,SX_OFFSET),
};
static const sx_layout sxal_lrzip_block3 = {UINT32_C(0x6020003a),"lrzip_block3",sxal_lrzip_block3_fields,SX_COUNT(sxal_lrzip_block3_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk4_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxal_lrzip_chunk4 = {UINT32_C(0x6020003b),"lrzip_chunk4",sxal_lrzip_chunk4_fields,SX_COUNT(sxal_lrzip_chunk4_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block4_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint32",1,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",5,4,SX_SIZE),
 SX_FIELD("next_block_offset","uint32",9,4,SX_OFFSET),
};
static const sx_layout sxal_lrzip_block4 = {UINT32_C(0x6020003c),"lrzip_block4",sxal_lrzip_block4_fields,SX_COUNT(sxal_lrzip_block4_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk5_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint40",2,5,SX_SIZE),
};
static const sx_layout sxal_lrzip_chunk5 = {UINT32_C(0x6020003d),"lrzip_chunk5",sxal_lrzip_chunk5_fields,SX_COUNT(sxal_lrzip_chunk5_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block5_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint40",1,5,SX_SIZE),
 SX_FIELD("unpacked_size","uint40",6,5,SX_SIZE),
 SX_FIELD("next_block_offset","uint40",11,5,SX_OFFSET),
};
static const sx_layout sxal_lrzip_block5 = {UINT32_C(0x6020003e),"lrzip_block5",sxal_lrzip_block5_fields,SX_COUNT(sxal_lrzip_block5_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk6_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint48",2,6,SX_SIZE),
};
static const sx_layout sxal_lrzip_chunk6 = {UINT32_C(0x6020003f),"lrzip_chunk6",sxal_lrzip_chunk6_fields,SX_COUNT(sxal_lrzip_chunk6_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block6_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint48",1,6,SX_SIZE),
 SX_FIELD("unpacked_size","uint48",7,6,SX_SIZE),
 SX_FIELD("next_block_offset","uint48",13,6,SX_OFFSET),
};
static const sx_layout sxal_lrzip_block6 = {UINT32_C(0x60200040),"lrzip_block6",sxal_lrzip_block6_fields,SX_COUNT(sxal_lrzip_block6_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk7_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint56",2,7,SX_SIZE),
};
static const sx_layout sxal_lrzip_chunk7 = {UINT32_C(0x60200041),"lrzip_chunk7",sxal_lrzip_chunk7_fields,SX_COUNT(sxal_lrzip_chunk7_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block7_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint56",1,7,SX_SIZE),
 SX_FIELD("unpacked_size","uint56",8,7,SX_SIZE),
 SX_FIELD("next_block_offset","uint56",15,7,SX_OFFSET),
};
static const sx_layout sxal_lrzip_block7 = {UINT32_C(0x60200042),"lrzip_block7",sxal_lrzip_block7_fields,SX_COUNT(sxal_lrzip_block7_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_chunk8_fields[] = {
 SX_FIELD("integer_width","uint8",0,1,SX_SIZE),
 SX_FIELD("final_chunk","uint8",1,1,SX_FLAGS),
 SX_FIELD("unpacked_size","uint64",2,8,SX_SIZE),
};
static const sx_layout sxal_lrzip_chunk8 = {UINT32_C(0x60200043),"lrzip_chunk8",sxal_lrzip_chunk8_fields,SX_COUNT(sxal_lrzip_chunk8_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_block8_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint64",1,8,SX_SIZE),
 SX_FIELD("unpacked_size","uint64",9,8,SX_SIZE),
 SX_FIELD("next_block_offset","uint64",17,8,SX_OFFSET),
};
static const sx_layout sxal_lrzip_block8 = {UINT32_C(0x60200044),"lrzip_block8",sxal_lrzip_block8_fields,SX_COUNT(sxal_lrzip_block8_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lrzip_md5_fields[] = {
 SX_FIELD("digest","uint8[16]",0,16,SX_CHECKSUM),
};
static const sx_layout sxal_lrzip_md5 = {UINT32_C(0x60200045),"lrzip_md5",sxal_lrzip_md5_fields,SX_COUNT(sxal_lrzip_md5_fields),SX_LE};
static const xx_data_struct_field_desc sxal_rzip_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("major","uint8",4,1,SX_ID),
 SX_FIELD("minor","uint8",5,1,SX_ID),
 SX_FIELD("unpacked_size_low","uint32",6,4,SX_NONE),
 SX_FIELD("unpacked_size_high","uint32",10,4,SX_NONE),
 SX_FIELD("reserved","uint8[10]",14,10,SX_RESERVED),
};
static const sx_layout sxal_rzip_header = {UINT32_C(0x60200046),"rzip_header",sxal_rzip_header_fields,SX_COUNT(sxal_rzip_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_rzip_block_fields[] = {
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("packed_size","uint32",1,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",5,4,SX_SIZE),
 SX_FIELD("next_block_offset","uint32",9,4,SX_OFFSET),
};
static const sx_layout sxal_rzip_block = {UINT32_C(0x60200047),"rzip_block",sxal_rzip_block_fields,SX_COUNT(sxal_rzip_block_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_backup_header_fields[] = {
 SX_FIELD("last_fragment","uint8",0,1,SX_FLAGS),
 SX_FIELD("sequence","uint16",1,2,SX_ID),
 SX_FIELD("zero","uint16",3,2,SX_RESERVED),
 SX_FIELD("original_path","char[78]",5,78,SX_STRING),
 SX_FIELD("path_size","uint8",83,1,SX_SIZE),
 SX_FIELD("reserved","uint8[44]",84,44,SX_RESERVED),
};
static const sx_layout sxal_dos_backup_header = {UINT32_C(0x60200048),"dos_backup_header",sxal_dos_backup_header_fields,SX_COUNT(sxal_dos_backup_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_backup2_header_fields[] = {
 SX_FIELD("header_size","uint8",0,1,SX_SIZE),
 SX_FIELD("signature","char[8]",1,8,SX_SIGNATURE),
 SX_FIELD("volume_number","uint8",9,1,SX_ID),
 SX_FIELD("reserved","uint8[128]",10,128,SX_RESERVED),
 SX_FIELD("last_volume","uint8",138,1,SX_FLAGS),
};
static const sx_layout sxal_dos_backup2_header = {UINT32_C(0x60200049),"dos_backup2_header",sxal_dos_backup2_header_fields,SX_COUNT(sxal_dos_backup2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_backup2_directory_fields[] = {
 SX_FIELD("record_size","uint8",0,1,SX_SIZE),
 SX_FIELD("path","char[63]",1,63,SX_STRING),
 SX_FIELD("file_count","uint16",64,2,SX_COUNT_PROP),
 SX_FIELD("next_directory_offset","uint32",66,4,SX_OFFSET),
};
static const sx_layout sxal_dos_backup2_directory = {UINT32_C(0x6020004a),"dos_backup2_directory",sxal_dos_backup2_directory_fields,SX_COUNT(sxal_dos_backup2_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_backup2_file_fields[] = {
 SX_FIELD("record_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_STRING),
 SX_FIELD("flags","uint8",13,1,SX_FLAGS),
 SX_FIELD("total_size","uint32",14,4,SX_SIZE),
 SX_FIELD("fragment_number","uint16",18,2,SX_ID),
 SX_FIELD("data_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("fragment_size","uint32",24,4,SX_SIZE),
 SX_FIELD("attributes","uint16",28,2,SX_FLAGS),
 SX_FIELD("time","uint16",30,2,SX_NONE),
 SX_FIELD("date","uint16",32,2,SX_NONE),
};
static const sx_layout sxal_dos_backup2_file = {UINT32_C(0x6020004b),"dos_backup2_file",sxal_dos_backup2_file_fields,SX_COUNT(sxal_dos_backup2_file_fields),SX_LE};
static const xx_data_struct_field_desc sxal_esp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("directory_offset","uint32",6,4,SX_OFFSET),
};
static const sx_layout sxal_esp_header = {UINT32_C(0x6020004c),"esp_header",sxal_esp_header_fields,SX_COUNT(sxal_esp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_lpak_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxal_lpak_header = {UINT32_C(0x6020004d),"lpak_header",sxal_lpak_header_fields,SX_COUNT(sxal_lpak_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_uharc_header_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
};
static const sx_layout sxal_uharc_header = {UINT32_C(0x6020004e),"uharc_header",sxal_uharc_header_fields,SX_COUNT(sxal_uharc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_is_stored_signature_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxal_is_stored_signature = {UINT32_C(0x6020004f),"is_stored_signature",sxal_is_stored_signature_fields,SX_COUNT(sxal_is_stored_signature_fields),SX_BE};
static const xx_data_struct_field_desc sxal_is_stored_marker_fields[] = {
 SX_FIELD("marker","char[3]",0,3,SX_SIGNATURE),
};
static const sx_layout sxal_is_stored_marker = {UINT32_C(0x60200050),"is_stored_marker",sxal_is_stored_marker_fields,SX_COUNT(sxal_is_stored_marker_fields),SX_BE};
static const xx_data_struct_field_desc sxal_tarx2_signature_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxal_tarx2_signature = {UINT32_C(0x60200051),"tarx2_signature",sxal_tarx2_signature_fields,SX_COUNT(sxal_tarx2_signature_fields),SX_BE};
static const xx_data_struct_field_desc sxal_tarx2_marker_fields[] = {
 SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxal_tarx2_marker = {UINT32_C(0x60200052),"tarx2_marker",sxal_tarx2_marker_fields,SX_COUNT(sxal_tarx2_marker_fields),SX_BE};
static const sx_layout *const sx_archivelater_layouts[] = {
 &sxal_aldus_header,
 &sxal_aldus_timestamp,
 &sxal_aldus_stream,
 &sxal_aldus_block_size,
 &sxal_ampk_header,
 &sxal_ampk_record,
 &sxal_ampk_file,
 &sxal_arx_member,
 &sxal_arx_end,
 &sxal_dos_packit_header,
 &sxal_dos_packit_member,
 &sxal_dos_packit_end,
 &sxal_asar_header,
 &sxal_pea_header,
 &sxal_pea_trigger_le,
 &sxal_pea_stream_le,
 &sxal_pea_block_size_le,
 &sxal_pea_name_size_le,
 &sxal_pea_object_le,
 &sxal_pea_file_size_le,
 &sxal_pea_packed_size_le,
 &sxal_pea_last_size_le,
 &sxal_pea_trigger_be,
 &sxal_pea_stream_be,
 &sxal_pea_block_size_be,
 &sxal_pea_name_size_be,
 &sxal_pea_object_be,
 &sxal_pea_file_size_be,
 &sxal_pea_packed_size_be,
 &sxal_pea_last_size_be,
 &sxal_sit5_header,
 &sxal_sit5_file,
 &sxal_sit5_folder,
 &sxal_sit5_second_v1,
 &sxal_sit5_second_v3,
 &sxal_sit5_resource,
 &sxal_diskdoubler_file,
 &sxal_dda2_header,
 &sxal_dda2_packed,
 &sxal_dda2_folder,
 &sxal_dda2_stored,
 &sxal_dda2_end,
 &sxal_dda2_footer,
 &sxal_dda2_index_word,
 &sxal_ddar_header,
 &sxal_ddar_member,
 &sxal_xpk_header,
 &sxal_xpk_extension_size,
 &sxal_xpk_chunk2,
 &sxal_xpk_chunk4,
 &sxal_ppmd_header,
 &sxal_lrzip_header,
 &sxal_lrzip_chunk1,
 &sxal_lrzip_block1,
 &sxal_lrzip_chunk2,
 &sxal_lrzip_block2,
 &sxal_lrzip_chunk3,
 &sxal_lrzip_block3,
 &sxal_lrzip_chunk4,
 &sxal_lrzip_block4,
 &sxal_lrzip_chunk5,
 &sxal_lrzip_block5,
 &sxal_lrzip_chunk6,
 &sxal_lrzip_block6,
 &sxal_lrzip_chunk7,
 &sxal_lrzip_block7,
 &sxal_lrzip_chunk8,
 &sxal_lrzip_block8,
 &sxal_lrzip_md5,
 &sxal_rzip_header,
 &sxal_rzip_block,
 &sxal_dos_backup_header,
 &sxal_dos_backup2_header,
 &sxal_dos_backup2_directory,
 &sxal_dos_backup2_file,
 &sxal_esp_header,
 &sxal_lpak_header,
 &sxal_uharc_header,
 &sxal_is_stored_signature,
 &sxal_is_stored_marker,
 &sxal_tarx2_signature,
 &sxal_tarx2_marker,
};
static bool sx_archivelater_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x60200000U||id>=0x60210000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x6020004eU:
 if(!xx_rt_wcscmp(r->name,L"signature"))text=L"Three-byte UHA container signature; the entropy-coded archive stream begins at offset 4.";
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"Stored UHARC version byte: high nibble is major and low nibble is minor (for example, 0x04 is version 0.4).";
 break;
 case 0x6020004fU:
 if(!xx_rt_wcscmp(r->name,L"signature"))text=L"Four-byte fixed marker in the XOR-A9 stored wrapper, verified by the native reader at offsets 0 and 6.";
 break;
 case 0x60200050U:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Three-byte fixed marker verified by the native reader at offset 12. Bytes 4-5, 10-11 and 15 are left raw.";
 break;
 case 0x60200051U:
 if(!xx_rt_wcscmp(r->name,L"signature"))text=L"Four-byte TARX2 clear-header signature at offset 0, checked by the native transport decoder.";
 break;
 case 0x60200052U:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Four-byte TARX2 clear-header marker at offset 8, checked by the native transport decoder.";
 break;
 case 0x60200002U:
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60200005U:
 if(!xx_rt_wcscmp(r->name,L"directory_count"))text=L"Stored count hint omits the first directory in historical writers.";
 if(!xx_rt_wcscmp(r->name,L"file_count"))text=L"Stored count hint can be inaccurate in historical writers.";
 if(!xx_rt_wcscmp(r->name,L"packed_size_hint"))text=L"Declared total packed-data byte count; historical writers may leave unreliable hints.";
 break;
 case 0x60200006U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=directory end, 1=directory start, 2=file.";
 if(!xx_rt_wcscmp(r->name,L"directory_size_plus3"))text=L"Directory records encode their complete subtree byte size plus 3; other record kinds use zero.";
 break;
 case 0x60200007U:
 if(!xx_rt_wcscmp(r->name,L"packed_size_hint"))text=L"Stored files consume unpacked_size bytes regardless of this hint.";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored, 1=LZARI, 2=LZSS, 3=LH1.";
 if(!xx_rt_wcscmp(r->name,L"protection"))text=L"Complete big-endian Amiga protection flags; the low byte alone is not the full physical field.";
 break;
 case 0x60200008U:
 if(!xx_rt_wcscmp(r->name,L"header_size_minus2"))text=L"Complete member header byte size is this value plus 2.";
 if(!xx_rt_wcscmp(r->name,L"packed_size"))text=L"Zero means stored, with unpacked_size physical payload bytes.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x6020000bU:
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x6020000dU:
 if(!xx_rt_wcscmp(r->name,L"header_pickle_size"))text=L"Physical payload starts at byte 8 plus this value.";
 if(!xx_rt_wcscmp(r->name,L"json_size"))text=L"JSON directory byte count excluding alignment padding; its members remain text.";
 break;
 case 0x6020000eU:
 if(!xx_rt_wcscmp(r->name,L"byte_order_flags"))text=L"Bit 7 selects big-endian size fields.";
 break;
 case 0x60200010U:
 if(!xx_rt_wcscmp(r->name,L"compression"))text=L"0=stored; 1..3=zlib block compression.";
 break;
 case 0x60200013U:
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60200018U:
 if(!xx_rt_wcscmp(r->name,L"compression"))text=L"0=stored; 1..3=zlib block compression.";
 break;
 case 0x6020001bU:
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60200020U:
 if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 break;
 case 0x60200021U:
 if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"first_child_offset"))text=L"0xFFFFFFFF marks a folder-end record, which has no second header or payload.";
 break;
 case 0x60200025U:
 if(!xx_rt_wcscmp(r->name,L"data_method"))text=L"Low 7 bits select the fork codec; high bit carries codec-specific flags.";
 if(!xx_rt_wcscmp(r->name,L"resource_method"))text=L"Low 7 bits select the fork codec; high bit carries codec-specific flags.";
 break;
 case 0x6020002cU:
 if(!xx_rt_wcscmp(r->name,L"folder_id_or_record_offset"))text=L"High bit marks a folder id; otherwise this is a record byte offset. A marked folder id is followed by its record offset.";
 break;
 case 0x6020002eU:
 if(!xx_rt_wcscmp(r->name,L"data_size"))text=L"Ignored for folder-end records, which have no payload.";
 if(!xx_rt_wcscmp(r->name,L"resource_size"))text=L"Ignored for folder-end records, which have no payload.";
 break;
 case 0x6020002fU:
 if(!xx_rt_wcscmp(r->name,L"packed_size_minus8"))text=L"Physical stream byte length is this value plus 8.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=long chunk headers, bit 1=password, bit 2=extended header.";
 break;
 case 0x60200031U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=raw, 1=packed, 15=end marker.";
 break;
 case 0x60200032U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0=raw, 1=packed, 15=end marker.";
 break;
 case 0x60200033U:
 if(!xx_rt_wcscmp(r->name,L"model_info"))text=L"Low 4 bits=order minus1; next 8=memory MiB minus1; high 4=variant minus A (7=H,8=I).";
 if(!xx_rt_wcscmp(r->name,L"name_size_and_restore"))text=L"Variant I: low 14 bits=name byte length, high 2=model restore method. Variant H uses all 16 bits for length.";
 if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x60200036U:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the chunk stream-header base, after the chunk prefix.";
 break;
 case 0x60200038U:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the chunk stream-header base, after the chunk prefix.";
 break;
 case 0x6020003aU:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the chunk stream-header base, after the chunk prefix.";
 break;
 case 0x6020003cU:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the chunk stream-header base, after the chunk prefix.";
 break;
 case 0x6020003eU:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the chunk stream-header base, after the chunk prefix.";
 break;
 case 0x60200040U:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the chunk stream-header base, after the chunk prefix.";
 break;
 case 0x60200042U:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the chunk stream-header base, after the chunk prefix.";
 break;
 case 0x60200044U:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the chunk stream-header base, after the chunk prefix.";
 break;
 case 0x60200046U:
 if(!xx_rt_wcscmp(r->name,L"unpacked_size_low"))text=L"Low 32 bits of the uncompressed byte length; combine the following high word.";
 if(!xx_rt_wcscmp(r->name,L"unpacked_size_high"))text=L"High 32 bits of the uncompressed byte length.";
 break;
 case 0x60200047U:
 if(!xx_rt_wcscmp(r->name,L"next_block_offset"))text=L"Byte offset relative to the current two-stream chunk header base.";
 break;
 case 0x6020004aU:
 if(!xx_rt_wcscmp(r->name,L"next_directory_offset"))text=L"0xFFFFFFFF means the final directory. Other values are writer offsets/hints; the native reader visits complete directory items sequentially.";
 break;
 case 0x6020004bU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset in the separate BACKUP.nnn file, not this CONTROL catalogue.";
 if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time, not a Unix timestamp.";
 if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time, not a Unix timestamp.";
 break;
 case 0x6020004cU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Low 3 bits select compression; bit3 applies delta filter. Directory bytes are compressed and may be XOR-scrambled.";
 break;
 default:break;}
 if(id==0x6020002cU){char a[32];wchar_t b[32];int n=xx_rt_snprintf(a,sizeof(a),"0x%llX",(unsigned long long)xx_var_get_u64(&r->value));if(n<0||n>=(int)sizeof(a))return false;for(int i=0;i<=n;i++)b[i]=(unsigned char)a[i];if(!xx_data_struct_record_set_display_value(r,b))return false;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAL_LIMIT 20000U
static bool sxal_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxal_read(sx_context *c,uint64_t p,void *b,size_t n){return sxal_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxal_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint16_t sxal16(const uint8_t *b,bool be){return (uint16_t)sxal_uint(b,2,be);}
static uint32_t sxal32(const uint8_t *b,bool be){return (uint32_t)sxal_uint(b,4,be);}
static bool sxal_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return c->count<SXAL_LIMIT&&p<=INT64_MAX&&sx_add(c,l,(int64_t)p,f->rel_offset+f->size);}
static bool sxal_aldus(sx_context *c){uint8_t b[64];if(!sxal_read(c,0,b,58)||!sxal_add(c,&sxal_aldus_header,0)||!sxal_add(c,&sxal_aldus_timestamp,54))return false;uint32_t h=sxal16(b+16,true);if((h!=100&&h!=200)||!sxal_read(c,h,b,22)||!sxal_add(c,&sxal_aldus_stream,h))return true;uint64_t n=sxal32(b+6,true),p=sxal32(b+10,true);if(n&&n<=SXAL_LIMIT&&p>=h+22&&sxal_span(c,p,n*2)&&!sx_table(c,&sxal_aldus_block_size,(int64_t)p,2,n))return false;return true;}
static bool sxal_ampk(sx_context *c){uint8_t b[24];if(!sxal_read(c,0,b,20)||!sxal_add(c,&sxal_ampk_header,0))return false;uint64_t p=20;for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,6)||b[0]>2)break;unsigned kind=b[0],name=b[1];if(!sxal_span(c,p+6,name))break;if(!sxal_add(c,&sxal_ampk_record,p))return false;p+=6+name;if(kind!=2)continue;if(!sxal_read(c,p,b,18))break;uint64_t n=b[8]?sxal32(b+4,true):sxal32(b,true);unsigned comment=b[16],method=b[8];if(method>3)break;if(!sxal_add(c,&sxal_ampk_file,p))return false;p+=18;if(!sxal_span(c,p,comment))break;p+=comment;if(method==3&&!n&&sxal32(b,true))break;if(!sxal_span(c,p,n))break;p+=n;}return true;}
static bool sxal_arx(sx_context *c){uint8_t b[23];uint64_t p=0;for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,1))break;if(!b[0])return sxal_add(c,&sxal_arx_end,p);uint64_t h=b[0]+2U;if(h<24||!sxal_read(c,p,b,23)||!sxal_span(c,p,h)||23U+b[22]>h)break;uint64_t n=sxal32(b+8,false);if(!n)n=sxal32(b+12,false);if(!sxal_add(c,&sxal_arx_member,p))return false;if(!sxal_span(c,p+h,n))break;p+=h+n;}return c->count!=0;}
static bool sxal_packit(sx_context *c){uint8_t b[19];if(!sxal_read(c,0,b,16)||!sxal_add(c,&sxal_dos_packit_header,0))return false;uint64_t p=16;for(unsigned i=0;i<SXAL_LIMIT;i++){if(!sxal_read(c,p,b,2))break;unsigned tag=sxal16(b,false);if(tag==65535)return sxal_add(c,&sxal_dos_packit_end,p);if(tag!=255||!sxal_read(c,p,b,19))break;uint64_t n=sxal32(b+2,false),head=20U+b[18];if(n>INT32_MAX||!sxal_span(c,p,head)||!sxal_add(c,&sxal_dos_packit_member,p))break;if(!sxal_span(c,p+head,n))break;p+=head+n;}return !c->failed;}
static int sxal_pea_tag(unsigned v){if(v==0)return 0;if(v==1||v==2)return 4;if(v==3)return 8;if(v==0x10)return 16;if(v==0x11||v==0x12)return 20;if(v==0x13||v==0x16||v==0x18)return 32;if(v==0x14||v==0x15||v==0x17||v==0x19)return 64;return -1;}
static bool sxal_pea(sx_context *c){uint8_t b[24];if(!sxal_read(c,0,b,20)||!sxal_add(c,&sxal_pea_header,0))return false;bool be=(b[8]&128)!=0;unsigned compression=b[16];int volume=sxal_pea_tag(b[3]),stream=sxal_pea_tag(b[18]),object=sxal_pea_tag(b[19]);uint64_t p=20,block=0;
 if(!sxal_add(c,be?&sxal_pea_trigger_be:&sxal_pea_trigger_le,10)||!sxal_add(c,be?&sxal_pea_stream_be:&sxal_pea_stream_le,16))return false;if(stream<0||object<0||volume<0)return true;
 if(compression){if(!sxal_read(c,p,b,4))return true;block=sxal32(b,be);if(!sxal_add(c,be?&sxal_pea_block_size_be:&sxal_pea_block_size_le,p))return false;p+=4;if(block<1024||block>33554432)return true;}
 for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,2))break;unsigned name=sxal16(b,be);if(!name){if(sxal_read(c,p,b,6)&&!xx_rt_memcmp(b+2,"EOA\0",4)&&!sxal_add(c,be?&sxal_pea_trigger_be:&sxal_pea_trigger_le,p))return false;break;}
  if(!sxal_span(c,p+2,name+8U))break;if(!sxal_add(c,be?&sxal_pea_name_size_be:&sxal_pea_name_size_le,p))return false;p+=2+name;if(!sxal_read(c,p,b,8)||!sxal_add(c,be?&sxal_pea_object_be:&sxal_pea_object_le,p))return false;bool folder=(sxal32(b+4,be)&16)!=0;p+=8;uint64_t n=0;
  if(!folder){if(!sxal_read(c,p,b,8))break;n=sxal_uint(b,8,be);if(!sxal_add(c,be?&sxal_pea_file_size_be:&sxal_pea_file_size_le,p))return false;p+=8;}
  if(!compression){if(!sxal_span(c,p,n))break;p+=n;}else{uint64_t left=n;unsigned steps=0;while(left&&steps++<SXAL_LIMIT){if(!sxal_read(c,p,b,4))return true;uint64_t z=sxal32(b,be),plain=left>block?block:left;if(!z||z>plain||!sxal_span(c,p+4,z))return true;if(!sxal_add(c,be?&sxal_pea_packed_size_be:&sxal_pea_packed_size_le,p))return false;p+=4+z;left-=plain;}if(left)return true;if(n){if(!sxal_span(c,p,4))break;if(!sxal_add(c,be?&sxal_pea_last_size_be:&sxal_pea_last_size_le,p))return false;p+=4;}}
  if(!sxal_span(c,p,(uint64_t)object))break;p+=(uint64_t)object;
 }return true;}
static bool sxal_sit5(sx_context *c){uint8_t b[100];if(!sxal_read(c,0,b,100)||!sxal_add(c,&sxal_sit5_header,0))return false;uint64_t p=sxal32(b+94,true);if(p<100)return true;
 for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,48)||sxal32(b,true)!=0xa5a5a5a5U)break;unsigned head=sxal16(b+6,true),v=b[4];bool folder=(b[9]&64)!=0;uint64_t packed=folder?0:sxal32(b+38,true);bool last=folder&&sxal32(b+34,true)==UINT32_MAX;if(head<48||!sxal_span(c,p,head))break;if(!sxal_add(c,folder?&sxal_sit5_folder:&sxal_sit5_file,p))return false;p+=head;if(last)continue;
  unsigned second=v==1?36:32;if(!sxal_read(c,p,b,second))break;bool resource=(sxal16(b,true)&1)!=0;if(!sxal_add(c,v==1?&sxal_sit5_second_v1:&sxal_sit5_second_v3,p))return false;p+=second;
  if(!folder&&resource){if(!sxal_read(c,p,b,14))break;packed+=sxal32(b+4,true);if(!sxal_add(c,&sxal_sit5_resource,p))return false;p+=14;if(!sxal_span(c,p,b[13]))break;p+=b[13];}if(!sxal_span(c,p,packed))break;p+=packed;
 }return true;}
static uint16_t sxal_ccitt(const uint8_t *b,size_t n){uint16_t crc=0;for(size_t i=0;i<n;i++){crc^=(uint16_t)b[i]<<8;for(unsigned j=0;j<8;j++)crc=(uint16_t)((crc<<1)^((crc&32768)?0x1021:0));}return crc;}
static bool sxal_dd_method(unsigned v){v&=127;return v==0||v==1||v==6||v==8||v==9||v==10;}
static bool sxal_dd_single(sx_context *c,uint64_t p,uint64_t room){uint8_t b[84];if(room<84||!sxal_read(c,p,b,84)||sxal32(b,true)!=0xabcd0054U)return true;uint64_t size=84+(uint64_t)sxal32(b+8,true)+sxal32(b+16,true);unsigned crc=sxal16(b+82,true);if(size>room||(crc&&crc!=sxal_ccitt(b,82))||sxal16(b+54,true)||sxal16(b+56,true))return true;uint32_t plain=sxal32(b+4,true),resource=sxal32(b+12,true);if((plain&&!sxal_dd_method(b[20]))||(resource&&!sxal_dd_method(b[21]))||(!(b[20]&127)&&plain!=sxal32(b+8,true))||(!(b[21]&127)&&resource!=sxal32(b+16,true)))return true;return sxal_add(c,&sxal_diskdoubler_file,p);}
static bool sxal_diskdoubler(sx_context *c){uint8_t b[124];if(!sxal_read(c,0,b,4))return false;
 if(sxal32(b,true)==0xabcd0054U){if(!sxal_read(c,0,b,84)||!sxal_add(c,&sxal_diskdoubler_file,0))return false;uint64_t n=84+(uint64_t)sxal32(b+8,true)+sxal32(b+16,true);if(sxal_span(c,n,84)){uint8_t copy[84];if(sxal_read(c,n,copy,84)&&!xx_rt_memcmp(b,copy,84)&&!sxal_add(c,&sxal_diskdoubler_file,n))return false;}return true;}
 bool dda=!xx_rt_memcmp(b,"DDA2",4);if(!dda&&xx_rt_memcmp(b,"DDAR",4))return false;uint64_t p=dda?62:78;if(!sxal_add(c,dda?&sxal_dda2_header:&sxal_ddar_header,0))return false;
 for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){
  if(dda){if(!sxal_read(c,p,b,6)||xx_rt_memcmp(b,"DDA2",4))break;unsigned type=sxal16(b+4,true);if(type==0xbbbb){if(!sxal_add(c,&sxal_dda2_end,p))return false;p+=6;if(sxal_read(c,p,b,16)&&sxal16(b,true)==0xbecd){uint64_t n=sxal32(b+2,true);if(sxal_span(c,p+16,n)&&!sxal_add(c,&sxal_dda2_footer,p))return false;if(n&&!(n&3)&&n/4<=SXAL_LIMIT&&sxal_span(c,p+16,n)&&!sx_table(c,&sxal_dda2_index_word,(int64_t)p+16,4,n/4))return false;}break;}
   unsigned h=type&0x8000?88:type&0x4000?56:90;if(h==90&&(!sxal_read(c,p,b,90)||sxal16(b+88,true)!=sxal_ccitt(b,88)))h=56;if(!sxal_read(c,p,b,h)||sxal16(b+h-2,true)!=sxal_ccitt(b,h-2))break;uint64_t n=sxal32(b+42,true);if(n<h||!sxal_span(c,p,n))break;if(!sxal_add(c,h==88?&sxal_dda2_folder:h==56?&sxal_dda2_packed:&sxal_dda2_stored,p))return false;if(h==56&&!sxal_dd_single(c,p+h,n-h))return false;p+=n;
  }else{if(!sxal_read(c,p,b,124)||xx_rt_memcmp(b,"DDAR",4)||sxal16(b+122,true)!=sxal_ccitt(b,122))break;uint64_t data=sxal32(b+74,true),resource=sxal32(b+78,true),n=b[73]?0:data+resource;if(!sxal_span(c,p+124,n))break;if(!sxal_add(c,&sxal_ddar_member,p))return false;if(!b[72]&&!b[73]&&!resource&&!sxal_dd_single(c,p+124,data))return false;p+=124+n;}
 }return true;}
static bool sxal_xpk(sx_context *c){uint8_t b[36];if(!sxal_read(c,0,b,36)||!sxal_add(c,&sxal_xpk_header,0))return false;unsigned flags=b[32],head=flags&1?12:8;uint64_t p=36;if(flags&4){if(!sxal_read(c,p,b,2))return true;uint64_t n=sxal16(b,true);if(!sxal_add(c,&sxal_xpk_extension_size,p))return false;p+=2;if(!sxal_span(c,p,n))return true;p+=n;}p=(p+3)&~UINT64_C(3);
 for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,head)||(b[0]!=0&&b[0]!=1&&b[0]!=15))break;uint64_t n=sxal_uint(b+4,head==12?4:2,true);if(!sxal_span(c,p+head,n))break;if(!sxal_add(c,head==12?&sxal_xpk_chunk4:&sxal_xpk_chunk2,p))return false;if(b[0]==15)break;p=(p+head+n+3)&~UINT64_C(3);}return true;}
static bool sxal_ppmd(sx_context *c){if(!sxal_add(c,&sxal_ppmd_header,0))return false;if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;
 xx_archive_record_state *s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;uint64_t last=0;
 for(unsigned i=0;i<1024;i++){const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>c->f->base_address){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);uint8_t b[16];if(p>last&&sxal_read(c,p,b,16)&&sxal32(b,false)==0x84acaf8fU){if(!sxal_add(c,&sxal_ppmd_header,p)){ok=false;break;}last=p;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static const sx_layout *const sxal_lr_chunks[]={&sxal_lrzip_chunk1,&sxal_lrzip_chunk2,&sxal_lrzip_chunk3,&sxal_lrzip_chunk4,&sxal_lrzip_chunk5,&sxal_lrzip_chunk6,&sxal_lrzip_chunk7,&sxal_lrzip_chunk8};
static const sx_layout *const sxal_lr_blocks[]={&sxal_lrzip_block1,&sxal_lrzip_block2,&sxal_lrzip_block3,&sxal_lrzip_block4,&sxal_lrzip_block5,&sxal_lrzip_block6,&sxal_lrzip_block7,&sxal_lrzip_block8};
static bool sxal_lrzip(sx_context *c){uint8_t b[25];if(!sxal_read(c,0,b,24)||!sxal_add(c,&sxal_lrzip_header,0))return false;bool md5=b[21]!=0;uint64_t end=(uint64_t)c->size,p=24;if(md5){if(end<40)return true;end-=16;if(!sxal_add(c,&sxal_lrzip_md5,end))return false;}
 for(unsigned i=0;i<SXAL_LIMIT&&p<end;i++){if(!sxal_read(c,p,b,2))break;unsigned width=b[0];bool final=b[1]!=0;if(width<1||width>8||b[1]>1||2U+width>end-p)break;if(!sxal_add(c,sxal_lr_chunks[width-1],p))return false;uint64_t base=p+2+width,head=1+3*width,readend=base+2*head;if(readend>end)break;size_t save=c->count;bool valid=true;
  for(unsigned stream=0;stream<2&&valid;stream++){uint64_t at=base+stream*head;if(!sxal_read(c,at,b,(size_t)head)||!sxal_add(c,sxal_lr_blocks[width-1],at))return false;uint64_t next=sxal_uint(b+1+2*width,width,false);unsigned steps=0;
   while(next&&steps++<SXAL_LIMIT){if(next<2*head||next>end-base||head>end-base-next||!sxal_read(c,base+next,b,(size_t)head)){valid=false;break;}uint64_t packed=sxal_uint(b+1,width,false),link=sxal_uint(b+1+2*width,width,false);if(!packed||packed>end-base-next-head||(link&&link<=next)){valid=false;break;}if(!sxal_add(c,sxal_lr_blocks[width-1],base+next))return false;uint64_t stop=base+next+head+packed;if(stop>readend)readend=stop;next=link;}if(next)valid=false;
  }if(!valid){c->count=save;break;}p=readend;if(final)break;
 }return true;}
static bool sxal_rzip(sx_context *c){uint8_t b[13];if(!sxal_add(c,&sxal_rzip_header,0))return false;uint64_t p=24;for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,13)||(b[0]!=3&&b[0]!=4))break;uint64_t n=sxal32(b+1,false);if(!sxal_span(c,p+13,n))break;if(!sxal_add(c,&sxal_rzip_block,p))return false;p+=13+n;}return true;}
static bool sxal_backup2(sx_context *c){uint8_t b[70];if(!sxal_add(c,&sxal_dos_backup2_header,0))return false;uint64_t p=139;for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,70)||b[0]!=70)break;unsigned n=sxal16(b+64,false);bool last=sxal32(b+66,false)==UINT32_MAX;if(!sxal_add(c,&sxal_dos_backup2_directory,p))return false;p+=70;for(unsigned j=0;j<n;j++){if(!sxal_read(c,p,b,34)||b[0]!=34)return true;if(!sxal_add(c,&sxal_dos_backup2_file,p))return false;p+=34;}if(last)break;}return true;}
static int sxal_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxal_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxal_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxal_order);return !c->failed;}
static bool sxal_is_stored(sx_context*c){uint8_t b[16];if(!sxal_read(c,0,b,sizeof(b)))return false;if(xx_rt_memcmp(b,"\xe7\x50\xa9\xae",4)||xx_rt_memcmp(b+6,"\xe7\x50\xa9\xae",4)||xx_rt_memcmp(b+12,"\xdd\xc1\xc0",3))return false;return sxal_add(c,&sxal_is_stored_signature,0)&&sxal_add(c,&sxal_is_stored_signature,6)&&sxal_add(c,&sxal_is_stored_marker,12);}
static bool sxal_tarx2(sx_context*c){uint8_t b[16];static const uint8_t a[4]={0x78,0x76,0x95,0x7d},z[4]={0x9c,0x3b,0xad,0x45};if(!sxal_read(c,0,b,sizeof(b))||xx_rt_memcmp(b,a,4)||xx_rt_memcmp(b+8,z,4))return false;return sxal_add(c,&sxal_tarx2_signature,0)&&sxal_add(c,&sxal_tarx2_marker,8);}
static bool sx_archivelater_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_ALDUS:case XX_FILE_TYPE_AMPK:case XX_FILE_TYPE_ARX:case XX_FILE_TYPE_PACKIT:case XX_FILE_TYPE_ASAR:case XX_FILE_TYPE_PEA:case XX_FILE_TYPE_STUFFIT5:case XX_FILE_TYPE_DISKDOUBLER:case XX_FILE_TYPE_XPK_COMPRESSED_FILE:case XX_FILE_TYPE_PPMD:case XX_FILE_TYPE_LRZIP:case XX_FILE_TYPE_RZIP:case XX_FILE_TYPE_MS_DOS_BACKUP:case XX_FILE_TYPE_MS_DOS_BACKUP2:case XX_FILE_TYPE_ESP_ARCHIVE:case XX_FILE_TYPE_LPAK:case XX_FILE_TYPE_UHARC:case XX_FILE_TYPE_IS_STORED:case XX_FILE_TYPE_TARX2:return true;default:return false;}}
static bool sx_archivelater_build(sx_context *c){if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_ALDUS:ok=sxal_aldus(c);break;case XX_FILE_TYPE_AMPK:ok=sxal_ampk(c);break;case XX_FILE_TYPE_ARX:ok=sxal_arx(c);break;case XX_FILE_TYPE_PACKIT:ok=sxal_packit(c);break;case XX_FILE_TYPE_ASAR:ok=sxal_add(c,&sxal_asar_header,0);break;case XX_FILE_TYPE_PEA:ok=sxal_pea(c);break;case XX_FILE_TYPE_STUFFIT5:ok=sxal_sit5(c);break;case XX_FILE_TYPE_DISKDOUBLER:ok=sxal_diskdoubler(c);break;case XX_FILE_TYPE_XPK_COMPRESSED_FILE:ok=sxal_xpk(c);break;case XX_FILE_TYPE_PPMD:ok=sxal_ppmd(c);break;case XX_FILE_TYPE_LRZIP:ok=sxal_lrzip(c);break;case XX_FILE_TYPE_RZIP:ok=sxal_rzip(c);break;case XX_FILE_TYPE_MS_DOS_BACKUP:ok=sxal_add(c,&sxal_dos_backup_header,0);break;case XX_FILE_TYPE_MS_DOS_BACKUP2:ok=sxal_backup2(c);break;case XX_FILE_TYPE_ESP_ARCHIVE:{uint8_t b[4];ok=sxal_read(c,0,b,4)&&!xx_rt_memcmp(b,"ESP>",4)&&sxal_add(c,&sxal_esp_header,0);break;}case XX_FILE_TYPE_LPAK:ok=sxal_add(c,&sxal_lpak_header,0);break;case XX_FILE_TYPE_UHARC:ok=sxal_add(c,&sxal_uharc_header,0);break;case XX_FILE_TYPE_IS_STORED:ok=sxal_is_stored(c);break;case XX_FILE_TYPE_TARX2:ok=sxal_tarx2(c);break;default:break;}return ok&&sxal_finish(c);}
