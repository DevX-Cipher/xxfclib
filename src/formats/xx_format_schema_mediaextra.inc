/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical game resource metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxmx_lab_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("name_table_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxmx_lab_header={UINT32_C(0x602E0001),"lab_header",sxmx_lab_header_fields,SX_COUNT(sxmx_lab_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_lab_entry_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("file_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
};
static const sx_layout sxmx_lab_entry={UINT32_C(0x602E0002),"lab_entry",sxmx_lab_entry_fields,SX_COUNT(sxmx_lab_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_bun_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_bun_header={UINT32_C(0x602E0003),"bun_header",sxmx_bun_header_fields,SX_COUNT(sxmx_bun_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bun_lb83_entry_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("extension","char[4]",8,4,SX_STRING),
 SX_FIELD("file_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxmx_bun_lb83_entry={UINT32_C(0x602E0004),"bun_lb83_entry",sxmx_bun_lb83_entry_fields,SX_COUNT(sxmx_bun_lb83_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bun_lb23_entry_fields[]={
 SX_FIELD("name","char[24]",0,24,SX_STRING),
 SX_FIELD("file_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxmx_bun_lb23_entry={UINT32_C(0x602E0005),"bun_lb23_entry",sxmx_bun_lb23_entry_fields,SX_COUNT(sxmx_bun_lb23_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("resource_magic","char[4]",8,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",12,2,SX_ID),
 SX_FIELD("compaction","uint16",14,2,SX_NONE),
 SX_FIELD("resource_size","uint32",16,4,SX_SIZE),
 SX_FIELD("directory_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("file_table_offset","uint16",24,2,SX_OFFSET),
 SX_FIELD("file_table_size","uint16",26,2,SX_SIZE),
};
static const sx_layout sxmx_mhk_header={UINT32_C(0x602E0006),"mhk_header",sxmx_mhk_header_fields,SX_COUNT(sxmx_mhk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_directory_fields[]={
 SX_FIELD("string_table_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("type_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxmx_mhk_directory={UINT32_C(0x602E0007),"mhk_directory",sxmx_mhk_directory_fields,SX_COUNT(sxmx_mhk_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_type_fields[]={
 SX_FIELD("type_tag","char[4]",0,4,SX_ID),
 SX_FIELD("resource_table_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("name_table_offset","uint16",6,2,SX_OFFSET),
};
static const sx_layout sxmx_mhk_type={UINT32_C(0x602E0008),"mhk_type",sxmx_mhk_type_fields,SX_COUNT(sxmx_mhk_type_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_count32_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_mhk_count32={UINT32_C(0x602E0009),"mhk_count32",sxmx_mhk_count32_fields,SX_COUNT(sxmx_mhk_count32_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_count16_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmx_mhk_count16={UINT32_C(0x602E000A),"mhk_count16",sxmx_mhk_count16_fields,SX_COUNT(sxmx_mhk_count16_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_file_fields[]={
 SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("size_low16","uint16",4,2,SX_NONE),
 SX_FIELD("size_high8","uint8",6,1,SX_NONE),
 SX_FIELD("size_high3_and_flags","uint8",7,1,SX_FLAGS),
 SX_FIELD("unknown","uint16",8,2,SX_NONE),
};
static const sx_layout sxmx_mhk_file={UINT32_C(0x602E000B),"mhk_file",sxmx_mhk_file_fields,SX_COUNT(sxmx_mhk_file_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_resource_fields[]={
 SX_FIELD("resource_id","uint16",0,2,SX_ID),
 SX_FIELD("file_index","uint16",2,2,SX_ID),
};
static const sx_layout sxmx_mhk_resource={UINT32_C(0x602E000C),"mhk_resource",sxmx_mhk_resource_fields,SX_COUNT(sxmx_mhk_resource_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_name_fields[]={
 SX_FIELD("string_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("file_index","uint16",2,2,SX_ID),
};
static const sx_layout sxmx_mhk_name={UINT32_C(0x602E000D),"mhk_name",sxmx_mhk_name_fields,SX_COUNT(sxmx_mhk_name_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_pod2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("comment","char[80]",8,80,SX_STRING),
 SX_FIELD("entry_count","uint32",88,4,SX_COUNT_PROP),
 SX_FIELD("audit_count","uint32",92,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_pod2_header={UINT32_C(0x602E000E),"pod2_header",sxmx_pod2_header_fields,SX_COUNT(sxmx_pod2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_pod2_entry_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("file_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("timestamp","int32",12,4,SX_TIME),
 SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxmx_pod2_entry={UINT32_C(0x602E000F),"pod2_entry",sxmx_pod2_entry_fields,SX_COUNT(sxmx_pod2_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_pod2_audit_fields[]={
 SX_FIELD("user","char[32]",0,32,SX_STRING),
 SX_FIELD("timestamp","int32",32,4,SX_TIME),
 SX_FIELD("action","uint32",36,4,SX_ID),
 SX_FIELD("name","char[256]",40,256,SX_STRING),
 SX_FIELD("old_timestamp","int32",296,4,SX_TIME),
 SX_FIELD("old_size","uint32",300,4,SX_SIZE),
 SX_FIELD("new_timestamp","int32",304,4,SX_TIME),
 SX_FIELD("new_size","uint32",308,4,SX_SIZE),
};
static const sx_layout sxmx_pod2_audit={UINT32_C(0x602E0010),"pod2_audit",sxmx_pod2_audit_fields,SX_COUNT(sxmx_pod2_audit_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_vpp3_header_le_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("name","char[65]",8,65,SX_STRING),
 SX_FIELD("path","char[256]",73,256,SX_STRING),
 SX_FIELD("alignment","bytes",329,3,SX_NONE),
 SX_FIELD("flags","uint32",332,4,SX_FLAGS),
 SX_FIELD("unknown_150","uint32",336,4,SX_NONE),
 SX_FIELD("entry_count","uint32",340,4,SX_COUNT_PROP),
 SX_FIELD("package_size","uint32",344,4,SX_SIZE),
 SX_FIELD("directory_size","uint32",348,4,SX_SIZE),
 SX_FIELD("names_size","uint32",352,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",356,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",360,4,SX_SIZE),
 SX_FIELD("directory_pointer","uint32",364,4,SX_POINTER),
 SX_FIELD("names_pointer","uint32",368,4,SX_POINTER),
 SX_FIELD("data_pointer","uint32",372,4,SX_POINTER),
};
static const sx_layout sxmx_vpp3_header_le={UINT32_C(0x602E0011),"vpp3_header_le",sxmx_vpp3_header_le_fields,SX_COUNT(sxmx_vpp3_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_vpp3_entry_le_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("runtime_offset","uint32",4,4,SX_ADDRESS),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("name_hash","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("package_pointer","uint32",24,4,SX_POINTER),
};
static const sx_layout sxmx_vpp3_entry_le={UINT32_C(0x602E0012),"vpp3_entry_le",sxmx_vpp3_entry_le_fields,SX_COUNT(sxmx_vpp3_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_vpp3_header_be_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("name","char[65]",8,65,SX_STRING),
 SX_FIELD("path","char[256]",73,256,SX_STRING),
 SX_FIELD("alignment","bytes",329,3,SX_NONE),
 SX_FIELD("flags","uint32",332,4,SX_FLAGS),
 SX_FIELD("unknown_150","uint32",336,4,SX_NONE),
 SX_FIELD("entry_count","uint32",340,4,SX_COUNT_PROP),
 SX_FIELD("package_size","uint32",344,4,SX_SIZE),
 SX_FIELD("directory_size","uint32",348,4,SX_SIZE),
 SX_FIELD("names_size","uint32",352,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",356,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",360,4,SX_SIZE),
 SX_FIELD("directory_pointer","uint32",364,4,SX_POINTER),
 SX_FIELD("names_pointer","uint32",368,4,SX_POINTER),
 SX_FIELD("data_pointer","uint32",372,4,SX_POINTER),
};
static const sx_layout sxmx_vpp3_header_be={UINT32_C(0x602E0013),"vpp3_header_be",sxmx_vpp3_header_be_fields,SX_COUNT(sxmx_vpp3_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_vpp3_entry_be_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("runtime_offset","uint32",4,4,SX_ADDRESS),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("name_hash","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("package_pointer","uint32",24,4,SX_POINTER),
};
static const sx_layout sxmx_vpp3_entry_be={UINT32_C(0x602E0014),"vpp3_entry_be",sxmx_vpp3_entry_be_fields,SX_COUNT(sxmx_vpp3_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_myp_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("signature","uint32",8,4,SX_SIGNATURE),
 SX_FIELD("first_block_offset","uint64",12,8,SX_OFFSET),
 SX_FIELD("block_capacity","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("file_count","uint32",24,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_myp_header={UINT32_C(0x602E0015),"myp_header",sxmx_myp_header_fields,SX_COUNT(sxmx_myp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_myp_block_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("next_block_offset","uint64",4,8,SX_OFFSET),
};
static const sx_layout sxmx_myp_block={UINT32_C(0x602E0016),"myp_block",sxmx_myp_block_fields,SX_COUNT(sxmx_myp_block_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_myp_entry_fields[]={
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name_hash","uint64",20,8,SX_CHECKSUM),
 SX_FIELD("data_hash","uint32",28,4,SX_CHECKSUM),
 SX_FIELD("compression","uint16",32,2,SX_ID),
};
static const sx_layout sxmx_myp_entry={UINT32_C(0x602E0017),"myp_entry",sxmx_myp_entry_fields,SX_COUNT(sxmx_myp_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_rez_header_fields[]={
 SX_FIELD("newline0","bytes",0,2,SX_SIGNATURE),
 SX_FIELD("format_text","char[60]",2,60,SX_STRING),
 SX_FIELD("newline1","bytes",62,2,SX_SIGNATURE),
 SX_FIELD("title","char[60]",64,60,SX_STRING),
 SX_FIELD("newline_eof","bytes",124,3,SX_SIGNATURE),
 SX_FIELD("version","uint32",127,4,SX_ID),
 SX_FIELD("root_offset","uint32",131,4,SX_OFFSET),
 SX_FIELD("root_size","uint32",135,4,SX_SIZE),
 SX_FIELD("root_time","uint32",139,4,SX_TIME),
 SX_FIELD("directory_boundary","uint32",143,4,SX_OFFSET),
 SX_FIELD("unknown_limits","bytes",147,20,SX_NONE),
 SX_FIELD("sorted","uint8",167,1,SX_FLAGS),
};
static const sx_layout sxmx_rez_header={UINT32_C(0x602E0018),"rez_header",sxmx_rez_header_fields,SX_COUNT(sxmx_rez_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_rez_directory_entry_fields[]={
 SX_FIELD("kind","uint32",0,4,SX_ID),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("directory_size","uint32",8,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",12,4,SX_TIME),
};
static const sx_layout sxmx_rez_directory_entry={UINT32_C(0x602E0019),"rez_directory_entry",sxmx_rez_directory_entry_fields,SX_COUNT(sxmx_rez_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_rez_resource_entry_fields[]={
 SX_FIELD("kind","uint32",0,4,SX_ID),
 SX_FIELD("file_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",12,4,SX_TIME),
 SX_FIELD("resource_id","uint32",16,4,SX_ID),
 SX_FIELD("resource_type","uint32",20,4,SX_ID),
 SX_FIELD("key_count","uint32",24,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_rez_resource_entry={UINT32_C(0x602E001A),"rez_resource_entry",sxmx_rez_resource_entry_fields,SX_COUNT(sxmx_rez_resource_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_rez_key_fields[]={
 SX_FIELD("key","uint32",0,4,SX_ID),
};
static const sx_layout sxmx_rez_key={UINT32_C(0x602E001B),"rez_key",sxmx_rez_key_fields,SX_COUNT(sxmx_rez_key_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_hpak_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("directory_offset","int32",8,4,SX_OFFSET),
};
static const sx_layout sxmx_hpak_header={UINT32_C(0x602E001C),"hpak_header",sxmx_hpak_header_fields,SX_COUNT(sxmx_hpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_hpak_directory_fields[]={
 SX_FIELD("entry_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_hpak_directory={UINT32_C(0x602E001D),"hpak_directory",sxmx_hpak_directory_fields,SX_COUNT(sxmx_hpak_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_hpak_entry_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("resource_type","int32",64,4,SX_ID),
 SX_FIELD("resource_index","int32",68,4,SX_ID),
 SX_FIELD("download_size","int32",72,4,SX_SIZE),
 SX_FIELD("flags","uint8",76,1,SX_FLAGS),
 SX_FIELD("md5","bytes",77,16,SX_CHECKSUM),
 SX_FIELD("player_index","uint8",93,1,SX_ID),
 SX_FIELD("reserved","bytes",94,32,SX_RESERVED),
 SX_FIELD("alignment","bytes",126,2,SX_NONE),
 SX_FIELD("next_pointer","uint32",128,4,SX_POINTER),
 SX_FIELD("previous_pointer","uint32",132,4,SX_POINTER),
 SX_FIELD("file_offset","int32",136,4,SX_OFFSET),
 SX_FIELD("file_size","int32",140,4,SX_SIZE),
};
static const sx_layout sxmx_hpak_entry={UINT32_C(0x602E001E),"hpak_entry",sxmx_hpak_entry_fields,SX_COUNT(sxmx_hpak_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_brres_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("root_offset","uint16",12,2,SX_OFFSET),
 SX_FIELD("section_count","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxmx_brres_header={UINT32_C(0x602E001F),"brres_header",sxmx_brres_header_fields,SX_COUNT(sxmx_brres_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brres_root_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("size","int32",4,4,SX_SIZE),
};
static const sx_layout sxmx_brres_root={UINT32_C(0x602E0020),"brres_root",sxmx_brres_root_fields,SX_COUNT(sxmx_brres_root_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brres_dictionary_fields[]={
 SX_FIELD("size","int32",0,4,SX_SIZE),
 SX_FIELD("entry_count","int32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_brres_dictionary={UINT32_C(0x602E0021),"brres_dictionary",sxmx_brres_dictionary_fields,SX_COUNT(sxmx_brres_dictionary_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brres_node_fields[]={
 SX_FIELD("reference_id","uint16",0,2,SX_ID),
 SX_FIELD("unknown","uint16",2,2,SX_NONE),
 SX_FIELD("left_index","uint16",4,2,SX_ID),
 SX_FIELD("right_index","uint16",6,2,SX_ID),
 SX_FIELD("name_relative","int32",8,4,SX_OFFSET),
 SX_FIELD("data_relative","int32",12,4,SX_OFFSET),
};
static const sx_layout sxmx_brres_node={UINT32_C(0x602E0022),"brres_node",sxmx_brres_node_fields,SX_COUNT(sxmx_brres_node_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brres_resource_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("size","int32",4,4,SX_SIZE),
 SX_FIELD("version","int32",8,4,SX_ID),
 SX_FIELD("archive_relative","int32",12,4,SX_OFFSET),
};
static const sx_layout sxmx_brres_resource={UINT32_C(0x602E0023),"brres_resource",sxmx_brres_resource_fields,SX_COUNT(sxmx_brres_resource_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_cflyt_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("section_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_cflyt_header_le={UINT32_C(0x602E0024),"cflyt_header_le",sxmx_cflyt_header_le_fields,SX_COUNT(sxmx_cflyt_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_bflyt_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("section_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",18,2,SX_NONE),
};
static const sx_layout sxmx_bflyt_header_le={UINT32_C(0x602E0025),"bflyt_header_le",sxmx_bflyt_header_le_fields,SX_COUNT(sxmx_bflyt_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_section_le_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmx_section_le={UINT32_C(0x602E0026),"section_le",sxmx_section_le_fields,SX_COUNT(sxmx_section_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_nw_layout_le_fields[]={
 SX_FIELD("draw_from_center","uint8",0,1,SX_FLAGS),
 SX_FIELD("padding","bytes",1,3,SX_NONE),
 SX_FIELD("width","float",4,4,SX_NONE),
 SX_FIELD("height","float",8,4,SX_NONE),
};
static const sx_layout sxmx_nw_layout_le={UINT32_C(0x602E0027),"nw_layout_le",sxmx_nw_layout_le_fields,SX_COUNT(sxmx_nw_layout_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_clyt_layout_le_fields[]={
 SX_FIELD("screen_origin","uint32",0,4,SX_ID),
 SX_FIELD("width","float",4,4,SX_NONE),
 SX_FIELD("height","float",8,4,SX_NONE),
};
static const sx_layout sxmx_clyt_layout_le={UINT32_C(0x602E0028),"clyt_layout_le",sxmx_clyt_layout_le_fields,SX_COUNT(sxmx_clyt_layout_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_nw_names_le_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_nw_names_le={UINT32_C(0x602E0029),"nw_names_le",sxmx_nw_names_le_fields,SX_COUNT(sxmx_nw_names_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_nw_name_offset_le_fields[]={
 SX_FIELD("name_relative","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_nw_name_offset_le={UINT32_C(0x602E002A),"nw_name_offset_le",sxmx_nw_name_offset_le_fields,SX_COUNT(sxmx_nw_name_offset_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_cflyt_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("section_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_cflyt_header_be={UINT32_C(0x602E002B),"cflyt_header_be",sxmx_cflyt_header_be_fields,SX_COUNT(sxmx_cflyt_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bflyt_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("section_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",18,2,SX_NONE),
};
static const sx_layout sxmx_bflyt_header_be={UINT32_C(0x602E002C),"bflyt_header_be",sxmx_bflyt_header_be_fields,SX_COUNT(sxmx_bflyt_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_section_be_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmx_section_be={UINT32_C(0x602E002D),"section_be",sxmx_section_be_fields,SX_COUNT(sxmx_section_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_layout_be_fields[]={
 SX_FIELD("draw_from_center","uint8",0,1,SX_FLAGS),
 SX_FIELD("padding","bytes",1,3,SX_NONE),
 SX_FIELD("width","float",4,4,SX_NONE),
 SX_FIELD("height","float",8,4,SX_NONE),
};
static const sx_layout sxmx_nw_layout_be={UINT32_C(0x602E002E),"nw_layout_be",sxmx_nw_layout_be_fields,SX_COUNT(sxmx_nw_layout_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_clyt_layout_be_fields[]={
 SX_FIELD("screen_origin","uint32",0,4,SX_ID),
 SX_FIELD("width","float",4,4,SX_NONE),
 SX_FIELD("height","float",8,4,SX_NONE),
};
static const sx_layout sxmx_clyt_layout_be={UINT32_C(0x602E002F),"clyt_layout_be",sxmx_clyt_layout_be_fields,SX_COUNT(sxmx_clyt_layout_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_names_be_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_nw_names_be={UINT32_C(0x602E0030),"nw_names_be",sxmx_nw_names_be_fields,SX_COUNT(sxmx_nw_names_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_name_offset_be_fields[]={
 SX_FIELD("name_relative","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_nw_name_offset_be={UINT32_C(0x602E0031),"nw_name_offset_be",sxmx_nw_name_offset_be_fields,SX_COUNT(sxmx_nw_name_offset_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("header_size","uint16",12,2,SX_SIZE),
 SX_FIELD("section_count","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxmx_nw_header={UINT32_C(0x602E0032),"nw_header",sxmx_nw_header_fields,SX_COUNT(sxmx_nw_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_pane_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("origin","uint8",1,1,SX_ID),
 SX_FIELD("alpha","uint8",2,1,SX_NONE),
 SX_FIELD("user_flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("name","char[16]",4,16,SX_STRING),
 SX_FIELD("user_data","char[8]",20,8,SX_STRING),
 SX_FIELD("translation_x","float",28,4,SX_NONE),
 SX_FIELD("translation_y","float",32,4,SX_NONE),
 SX_FIELD("translation_z","float",36,4,SX_NONE),
 SX_FIELD("rotation_x","float",40,4,SX_NONE),
 SX_FIELD("rotation_y","float",44,4,SX_NONE),
 SX_FIELD("rotation_z","float",48,4,SX_NONE),
 SX_FIELD("scale_x","float",52,4,SX_NONE),
 SX_FIELD("scale_y","float",56,4,SX_NONE),
 SX_FIELD("width","float",60,4,SX_NONE),
 SX_FIELD("height","float",64,4,SX_NONE),
};
static const sx_layout sxmx_nw_pane={UINT32_C(0x602E0033),"nw_pane",sxmx_nw_pane_fields,SX_COUNT(sxmx_nw_pane_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_legacy_names_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",2,2,SX_NONE),
};
static const sx_layout sxmx_nw_legacy_names={UINT32_C(0x602E0034),"nw_legacy_names",sxmx_nw_legacy_names_fields,SX_COUNT(sxmx_nw_legacy_names_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_legacy_name_fields[]={
 SX_FIELD("name_relative","uint32",0,4,SX_OFFSET),
 SX_FIELD("type","uint8",4,1,SX_ID),
 SX_FIELD("padding","bytes",5,3,SX_NONE),
};
static const sx_layout sxmx_nw_legacy_name={UINT32_C(0x602E0035),"nw_legacy_name",sxmx_nw_legacy_name_fields,SX_COUNT(sxmx_nw_legacy_name_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_group_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_STRING),
 SX_FIELD("pane_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",18,2,SX_NONE),
};
static const sx_layout sxmx_nw_group={UINT32_C(0x602E0036),"nw_group",sxmx_nw_group_fields,SX_COUNT(sxmx_nw_group_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_pane_reference_fields[]={
 SX_FIELD("pane_name","char[16]",0,16,SX_STRING),
};
static const sx_layout sxmx_nw_pane_reference={UINT32_C(0x602E0037),"nw_pane_reference",sxmx_nw_pane_reference_fields,SX_COUNT(sxmx_nw_pane_reference_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_chunky_header_fields[]={
 SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("version","uint32",16,4,SX_ID),
 SX_FIELD("platform","uint32",20,4,SX_ID),
 SX_FIELD("header_size","uint32",24,4,SX_SIZE),
 SX_FIELD("chunk_header_size","uint32",28,4,SX_SIZE),
 SX_FIELD("unknown","uint32",32,4,SX_NONE),
};
static const sx_layout sxmx_chunky_header={UINT32_C(0x602E0038),"chunky_header",sxmx_chunky_header_fields,SX_COUNT(sxmx_chunky_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_chunky_chunk_fields[]={
 SX_FIELD("kind","char[4]",0,4,SX_ID),
 SX_FIELD("chunk_id","char[4]",4,4,SX_ID),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("name_size","uint32",16,4,SX_SIZE),
 SX_FIELD("unknown1","uint32",20,4,SX_NONE),
 SX_FIELD("unknown2","uint32",24,4,SX_NONE),
};
static const sx_layout sxmx_chunky_chunk={UINT32_C(0x602E0039),"chunky_chunk",sxmx_chunky_chunk_fields,SX_COUNT(sxmx_chunky_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_j3d_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("section_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("opaque_creator","bytes",16,16,SX_NONE),
};
static const sx_layout sxmx_j3d_header={UINT32_C(0x602E003A),"j3d_header",sxmx_j3d_header_fields,SX_COUNT(sxmx_j3d_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_ttk1_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
 SX_FIELD("loop_mode","uint8",8,1,SX_ID),
 SX_FIELD("angle_scale","uint8",9,1,SX_NONE),
 SX_FIELD("duration_frames","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("animation_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("scale_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("rotation_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("translation_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("animation_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("remap_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("name_table_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("texture_matrix_index_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("center_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("scale_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("rotation_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("translation_offset","uint32",48,4,SX_OFFSET),
};
static const sx_layout sxmx_btk_ttk1={UINT32_C(0x602E003B),"btk_ttk1",sxmx_btk_ttk1_fields,SX_COUNT(sxmx_btk_ttk1_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_selection_fields[]={
 SX_FIELD("scale_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("scale_first","uint16",2,2,SX_ID),
 SX_FIELD("scale_tangent_type","uint16",4,2,SX_ID),
 SX_FIELD("rotation_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("rotation_first","uint16",8,2,SX_ID),
 SX_FIELD("rotation_tangent_type","uint16",10,2,SX_ID),
 SX_FIELD("translation_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("translation_first","uint16",14,2,SX_ID),
 SX_FIELD("translation_tangent_type","uint16",16,2,SX_ID),
};
static const sx_layout sxmx_btk_selection={UINT32_C(0x602E003C),"btk_selection",sxmx_btk_selection_fields,SX_COUNT(sxmx_btk_selection_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_remap_fields[]={
 SX_FIELD("animation_index","uint16",0,2,SX_ID),
};
static const sx_layout sxmx_btk_remap={UINT32_C(0x602E003D),"btk_remap",sxmx_btk_remap_fields,SX_COUNT(sxmx_btk_remap_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_texture_matrix_index_fields[]={
 SX_FIELD("texture_matrix_index","uint8",0,1,SX_ID),
};
static const sx_layout sxmx_btk_texture_matrix_index={UINT32_C(0x602E003E),"btk_texture_matrix_index",sxmx_btk_texture_matrix_index_fields,SX_COUNT(sxmx_btk_texture_matrix_index_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_float_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
static const sx_layout sxmx_btk_float={UINT32_C(0x602E003F),"btk_float",sxmx_btk_float_fields,SX_COUNT(sxmx_btk_float_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_rotation_fields[]={
 SX_FIELD("angle_units","int16",0,2,SX_NONE),
};
static const sx_layout sxmx_btk_rotation={UINT32_C(0x602E0040),"btk_rotation",sxmx_btk_rotation_fields,SX_COUNT(sxmx_btk_rotation_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_j3d_name_table_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",2,2,SX_NONE),
};
static const sx_layout sxmx_j3d_name_table={UINT32_C(0x602E0041),"j3d_name_table",sxmx_j3d_name_table_fields,SX_COUNT(sxmx_j3d_name_table_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_j3d_name_fields[]={
 SX_FIELD("hash","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("name_relative","uint16",2,2,SX_OFFSET),
};
static const sx_layout sxmx_j3d_name={UINT32_C(0x602E0042),"j3d_name",sxmx_j3d_name_fields,SX_COUNT(sxmx_j3d_name_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_pai1_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
 SX_FIELD("frame_count","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("loop","uint8",10,1,SX_FLAGS),
 SX_FIELD("padding","uint8",11,1,SX_NONE),
 SX_FIELD("texture_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("binding_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("binding_table_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxmx_brlan_pai1={UINT32_C(0x602E0043),"brlan_pai1",sxmx_brlan_pai1_fields,SX_COUNT(sxmx_brlan_pai1_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_binding_fields[]={
 SX_FIELD("name","char[20]",0,20,SX_STRING),
 SX_FIELD("group_count","uint8",20,1,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",21,3,SX_NONE),
 SX_FIELD("group_relative","uint32",24,4,SX_OFFSET),
};
static const sx_layout sxmx_brlan_binding={UINT32_C(0x602E0044),"brlan_binding",sxmx_brlan_binding_fields,SX_COUNT(sxmx_brlan_binding_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_group_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("track_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",5,3,SX_NONE),
};
static const sx_layout sxmx_brlan_group={UINT32_C(0x602E0045),"brlan_group",sxmx_brlan_group_fields,SX_COUNT(sxmx_brlan_group_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_track_fields[]={
 SX_FIELD("index","uint8",0,1,SX_ID),
 SX_FIELD("channel","uint8",1,1,SX_ID),
 SX_FIELD("curve_type","uint8",2,1,SX_ID),
 SX_FIELD("padding","uint8",3,1,SX_NONE),
 SX_FIELD("key_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
 SX_FIELD("keys_relative","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxmx_brlan_track={UINT32_C(0x602E0046),"brlan_track",sxmx_brlan_track_fields,SX_COUNT(sxmx_brlan_track_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_key_fields[]={
 SX_FIELD("frame","float",0,4,SX_NONE),
 SX_FIELD("value","float",4,4,SX_NONE),
 SX_FIELD("tangent","float",8,4,SX_NONE),
};
static const sx_layout sxmx_brlan_key={UINT32_C(0x602E0047),"brlan_key",sxmx_brlan_key_fields,SX_COUNT(sxmx_brlan_key_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_relative_offset_be_fields[]={
 SX_FIELD("relative_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_relative_offset_be={UINT32_C(0x602E0048),"relative_offset_be",sxmx_relative_offset_be_fields,SX_COUNT(sxmx_relative_offset_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bfres_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("byte_order","uint16",8,2,SX_ID),
 SX_FIELD("header_size","uint16",10,2,SX_SIZE),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("alignment","uint32",16,4,SX_SIZE),
 SX_FIELD("name_relative","int32",20,4,SX_OFFSET),
 SX_FIELD("string_pool_size","uint32",24,4,SX_SIZE),
 SX_FIELD("string_pool_relative","int32",28,4,SX_OFFSET),
 SX_FIELD("model_dictionary_relative","int32",32,4,SX_OFFSET),
 SX_FIELD("texture_dictionary_relative","int32",36,4,SX_OFFSET),
 SX_FIELD("skeletal_animation_dictionary_relative","int32",40,4,SX_OFFSET),
 SX_FIELD("shader_parameter_animation_dictionary_relative","int32",44,4,SX_OFFSET),
 SX_FIELD("color_animation_dictionary_relative","int32",48,4,SX_OFFSET),
 SX_FIELD("texture_srt_animation_dictionary_relative","int32",52,4,SX_OFFSET),
 SX_FIELD("texture_pattern_animation_dictionary_relative","int32",56,4,SX_OFFSET),
 SX_FIELD("bone_visibility_animation_dictionary_relative","int32",60,4,SX_OFFSET),
 SX_FIELD("material_visibility_animation_dictionary_relative","int32",64,4,SX_OFFSET),
 SX_FIELD("shape_animation_dictionary_relative","int32",68,4,SX_OFFSET),
 SX_FIELD("scene_animation_dictionary_relative","int32",72,4,SX_OFFSET),
 SX_FIELD("external_file_dictionary_relative","int32",76,4,SX_OFFSET),
 SX_FIELD("model_count","uint16",80,2,SX_COUNT_PROP),
 SX_FIELD("texture_count","uint16",82,2,SX_COUNT_PROP),
 SX_FIELD("skeletal_animation_count","uint16",84,2,SX_COUNT_PROP),
 SX_FIELD("shader_parameter_animation_count","uint16",86,2,SX_COUNT_PROP),
 SX_FIELD("color_animation_count","uint16",88,2,SX_COUNT_PROP),
 SX_FIELD("texture_srt_animation_count","uint16",90,2,SX_COUNT_PROP),
 SX_FIELD("texture_pattern_animation_count","uint16",92,2,SX_COUNT_PROP),
 SX_FIELD("bone_visibility_animation_count","uint16",94,2,SX_COUNT_PROP),
 SX_FIELD("material_visibility_animation_count","uint16",96,2,SX_COUNT_PROP),
 SX_FIELD("shape_animation_count","uint16",98,2,SX_COUNT_PROP),
 SX_FIELD("scene_animation_count","uint16",100,2,SX_COUNT_PROP),
 SX_FIELD("external_file_count","uint16",102,2,SX_COUNT_PROP),
 SX_FIELD("user_pointer","uint32",104,4,SX_POINTER),
};
static const sx_layout sxmx_bfres_header={UINT32_C(0x602E0049),"bfres_header",sxmx_bfres_header_fields,SX_COUNT(sxmx_bfres_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bfres_dictionary_fields[]={
 SX_FIELD("dictionary_size","uint32",0,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_bfres_dictionary={UINT32_C(0x602E004A),"bfres_dictionary",sxmx_bfres_dictionary_fields,SX_COUNT(sxmx_bfres_dictionary_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bfres_node_fields[]={
 SX_FIELD("reference_bit","uint32",0,4,SX_NONE),
 SX_FIELD("left_index","uint16",4,2,SX_ID),
 SX_FIELD("right_index","uint16",6,2,SX_ID),
 SX_FIELD("name_relative","int32",8,4,SX_OFFSET),
 SX_FIELD("data_relative","int32",12,4,SX_OFFSET),
};
static const sx_layout sxmx_bfres_node={UINT32_C(0x602E004B),"bfres_node",sxmx_bfres_node_fields,SX_COUNT(sxmx_bfres_node_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bfres_external_fields[]={
 SX_FIELD("data_relative","int32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmx_bfres_external={UINT32_C(0x602E004C),"bfres_external",sxmx_bfres_external_fields,SX_COUNT(sxmx_bfres_external_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_cgfx_slot_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("dictionary_relative","int32",4,4,SX_OFFSET),
};
static const sx_layout sxmx_cgfx_slot={UINT32_C(0x602E004D),"cgfx_slot",sxmx_cgfx_slot_fields,SX_COUNT(sxmx_cgfx_slot_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_cgfx_dictionary_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("dictionary_size","uint32",4,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_cgfx_dictionary={UINT32_C(0x602E004E),"cgfx_dictionary",sxmx_cgfx_dictionary_fields,SX_COUNT(sxmx_cgfx_dictionary_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_cgfx_node_fields[]={
 SX_FIELD("reference_bit","uint32",0,4,SX_NONE),
 SX_FIELD("left_index","uint16",4,2,SX_ID),
 SX_FIELD("right_index","uint16",6,2,SX_ID),
 SX_FIELD("name_relative","int32",8,4,SX_OFFSET),
 SX_FIELD("data_relative","int32",12,4,SX_OFFSET),
};
static const sx_layout sxmx_cgfx_node={UINT32_C(0x602E004F),"cgfx_node",sxmx_cgfx_node_fields,SX_COUNT(sxmx_cgfx_node_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_header_fields[]={
 SX_FIELD("legacy_metadata_size","uint32",0,4,SX_SIZE),
 SX_FIELD("legacy_file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("legacy_data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("byte_order","uint8",16,1,SX_ID),
 SX_FIELD("reserved","bytes",17,3,SX_RESERVED),
 SX_FIELD("metadata_size","uint32",20,4,SX_SIZE),
 SX_FIELD("file_size","uint64",24,8,SX_SIZE),
 SX_FIELD("data_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("unknown","uint64",40,8,SX_NONE),
};
static const sx_layout sxmx_unity_header={UINT32_C(0x602E0050),"unity_header",sxmx_unity_header_fields,SX_COUNT(sxmx_unity_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_unity_metadata_flags_fields[]={
 SX_FIELD("target_platform","int32",0,4,SX_ID),
 SX_FIELD("enable_type_tree","uint8",4,1,SX_FLAGS),
 SX_FIELD("type_count","int32",5,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_unity_metadata_flags={UINT32_C(0x602E0051),"unity_metadata_flags",sxmx_unity_metadata_flags_fields,SX_COUNT(sxmx_unity_metadata_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_type_fields[]={
 SX_FIELD("class_id","int32",0,4,SX_ID),
 SX_FIELD("stripped_type","uint8",4,1,SX_FLAGS),
 SX_FIELD("script_type_index","int16",5,2,SX_ID),
 SX_FIELD("old_type_hash","bytes",7,16,SX_CHECKSUM),
};
static const sx_layout sxmx_unity_type={UINT32_C(0x602E0052),"unity_type",sxmx_unity_type_fields,SX_COUNT(sxmx_unity_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_object_count_fields[]={
 SX_FIELD("object_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_unity_object_count={UINT32_C(0x602E0053),"unity_object_count",sxmx_unity_object_count_fields,SX_COUNT(sxmx_unity_object_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_object_fields[]={
 SX_FIELD("path_id","int64",0,8,SX_ID),
 SX_FIELD("data_relative","int64",8,8,SX_OFFSET),
 SX_FIELD("data_size","uint32",16,4,SX_SIZE),
 SX_FIELD("type_index","int32",20,4,SX_ID),
};
static const sx_layout sxmx_unity_object={UINT32_C(0x602E0054),"unity_object",sxmx_unity_object_fields,SX_COUNT(sxmx_unity_object_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_tail_counts_fields[]={
 SX_FIELD("script_type_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("external_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("reference_type_count","int32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_unity_tail_counts={UINT32_C(0x602E0055),"unity_tail_counts",sxmx_unity_tail_counts_fields,SX_COUNT(sxmx_unity_tail_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_ue1_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("licensee_version","uint16",6,2,SX_ID),
 SX_FIELD("package_flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("name_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("name_offset","int32",16,4,SX_OFFSET),
 SX_FIELD("export_count","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("export_offset","int32",24,4,SX_OFFSET),
 SX_FIELD("import_count","int32",28,4,SX_COUNT_PROP),
 SX_FIELD("import_offset","int32",32,4,SX_OFFSET),
 SX_FIELD("heritage_count","int32",36,4,SX_COUNT_PROP),
 SX_FIELD("heritage_offset","int32",40,4,SX_OFFSET),
};
static const sx_layout sxmx_ue1_header={UINT32_C(0x602E0056),"ue1_header",sxmx_ue1_header_fields,SX_COUNT(sxmx_ue1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_ue1_name_flags_fields[]={
 SX_FIELD("object_flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmx_ue1_name_flags={UINT32_C(0x602E0057),"ue1_name_flags",sxmx_ue1_name_flags_fields,SX_COUNT(sxmx_ue1_name_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_ue1_heritage_fields[]={
 SX_FIELD("guid","bytes",0,16,SX_ID),
};
static const sx_layout sxmx_ue1_heritage={UINT32_C(0x602E0058),"ue1_heritage",sxmx_ue1_heritage_fields,SX_COUNT(sxmx_ue1_heritage_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("major_version","uint16",8,2,SX_ID),
 SX_FIELD("minor_version","uint16",10,2,SX_ID),
 SX_FIELD("archive_name_utf16le","bytes",12,128,SX_NONE),
 SX_FIELD("table_size","uint32",140,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",144,4,SX_OFFSET),
 SX_FIELD("platform","uint32",148,4,SX_ID),
};
static const sx_layout sxmx_sga6_header={UINT32_C(0x602E0059),"sga6_header",sxmx_sga6_header_fields,SX_COUNT(sxmx_sga6_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_table_slot_fields[]={
 SX_FIELD("table_relative","uint32",0,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_sga6_table_slot={UINT32_C(0x602E005A),"sga6_table_slot",sxmx_sga6_table_slot_fields,SX_COUNT(sxmx_sga6_table_slot_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_drive_fields[]={
 SX_FIELD("alias","char[64]",0,64,SX_STRING),
 SX_FIELD("name","char[64]",64,64,SX_STRING),
 SX_FIELD("first_folder","uint32",128,4,SX_ID),
 SX_FIELD("end_folder","uint32",132,4,SX_ID),
 SX_FIELD("first_file","uint32",136,4,SX_ID),
 SX_FIELD("end_file","uint32",140,4,SX_ID),
 SX_FIELD("root_folder","uint32",144,4,SX_ID),
};
static const sx_layout sxmx_sga6_drive={UINT32_C(0x602E005B),"sga6_drive",sxmx_sga6_drive_fields,SX_COUNT(sxmx_sga6_drive_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_folder_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("first_folder","uint32",4,4,SX_ID),
 SX_FIELD("end_folder","uint32",8,4,SX_ID),
 SX_FIELD("first_file","uint32",12,4,SX_ID),
 SX_FIELD("end_file","uint32",16,4,SX_ID),
};
static const sx_layout sxmx_sga6_folder={UINT32_C(0x602E005C),"sga6_folder",sxmx_sga6_folder_fields,SX_COUNT(sxmx_sga6_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_file_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_relative","uint32",4,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",16,4,SX_TIME),
 SX_FIELD("verification","uint8",20,1,SX_ID),
 SX_FIELD("storage_type","uint8",21,1,SX_ID),
 SX_FIELD("crc32","uint32",22,4,SX_CHECKSUM),
};
static const sx_layout sxmx_sga6_file={UINT32_C(0x602E005D),"sga6_file",sxmx_sga6_file_fields,SX_COUNT(sxmx_sga6_file_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_header_le_fields[]={
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_ID),
 SX_FIELD("key_table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("string_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("root_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxmx_byaml_header_le={UINT32_C(0x602E005E),"byaml_header_le",sxmx_byaml_header_le_fields,SX_COUNT(sxmx_byaml_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_node_le_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("entry_count","uint24",1,3,SX_COUNT_PROP),
};
static const sx_layout sxmx_byaml_node_le={UINT32_C(0x602E005F),"byaml_node_le",sxmx_byaml_node_le_fields,SX_COUNT(sxmx_byaml_node_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_string_offset_le_fields[]={
 SX_FIELD("string_relative","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_byaml_string_offset_le={UINT32_C(0x602E0060),"byaml_string_offset_le",sxmx_byaml_string_offset_le_fields,SX_COUNT(sxmx_byaml_string_offset_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_map_key_le_fields[]={
 SX_FIELD("key_index","uint24",0,3,SX_ID),
 SX_FIELD("value_kind","uint8",3,1,SX_ID),
};
static const sx_layout sxmx_byaml_map_key_le={UINT32_C(0x602E0061),"byaml_map_key_le",sxmx_byaml_map_key_le_fields,SX_COUNT(sxmx_byaml_map_key_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_array_kind_le_fields[]={
 SX_FIELD("value_kind","uint8",0,1,SX_ID),
};
static const sx_layout sxmx_byaml_array_kind_le={UINT32_C(0x602E0062),"byaml_array_kind_le",sxmx_byaml_array_kind_le_fields,SX_COUNT(sxmx_byaml_array_kind_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_string_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_ID),
};
static const sx_layout sxmx_byaml_string_le={UINT32_C(0x602E0063),"byaml_string_le",sxmx_byaml_string_le_fields,SX_COUNT(sxmx_byaml_string_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_bool_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmx_byaml_bool_le={UINT32_C(0x602E0064),"byaml_bool_le",sxmx_byaml_bool_le_fields,SX_COUNT(sxmx_byaml_bool_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_int_le_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxmx_byaml_int_le={UINT32_C(0x602E0065),"byaml_int_le",sxmx_byaml_int_le_fields,SX_COUNT(sxmx_byaml_int_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_float_le_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
static const sx_layout sxmx_byaml_float_le={UINT32_C(0x602E0066),"byaml_float_le",sxmx_byaml_float_le_fields,SX_COUNT(sxmx_byaml_float_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_uint_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxmx_byaml_uint_le={UINT32_C(0x602E0067),"byaml_uint_le",sxmx_byaml_uint_le_fields,SX_COUNT(sxmx_byaml_uint_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_node_value_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_byaml_node_value_le={UINT32_C(0x602E0068),"byaml_node_value_le",sxmx_byaml_node_value_le_fields,SX_COUNT(sxmx_byaml_node_value_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_null_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_RESERVED),
};
static const sx_layout sxmx_byaml_null_le={UINT32_C(0x602E0069),"byaml_null_le",sxmx_byaml_null_le_fields,SX_COUNT(sxmx_byaml_null_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_header_be_fields[]={
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_ID),
 SX_FIELD("key_table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("string_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("root_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxmx_byaml_header_be={UINT32_C(0x602E006A),"byaml_header_be",sxmx_byaml_header_be_fields,SX_COUNT(sxmx_byaml_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_node_be_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("entry_count","uint24",1,3,SX_COUNT_PROP),
};
static const sx_layout sxmx_byaml_node_be={UINT32_C(0x602E006B),"byaml_node_be",sxmx_byaml_node_be_fields,SX_COUNT(sxmx_byaml_node_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_string_offset_be_fields[]={
 SX_FIELD("string_relative","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_byaml_string_offset_be={UINT32_C(0x602E006C),"byaml_string_offset_be",sxmx_byaml_string_offset_be_fields,SX_COUNT(sxmx_byaml_string_offset_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_map_key_be_fields[]={
 SX_FIELD("key_index","uint24",0,3,SX_ID),
 SX_FIELD("value_kind","uint8",3,1,SX_ID),
};
static const sx_layout sxmx_byaml_map_key_be={UINT32_C(0x602E006D),"byaml_map_key_be",sxmx_byaml_map_key_be_fields,SX_COUNT(sxmx_byaml_map_key_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_array_kind_be_fields[]={
 SX_FIELD("value_kind","uint8",0,1,SX_ID),
};
static const sx_layout sxmx_byaml_array_kind_be={UINT32_C(0x602E006E),"byaml_array_kind_be",sxmx_byaml_array_kind_be_fields,SX_COUNT(sxmx_byaml_array_kind_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_string_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_ID),
};
static const sx_layout sxmx_byaml_string_be={UINT32_C(0x602E006F),"byaml_string_be",sxmx_byaml_string_be_fields,SX_COUNT(sxmx_byaml_string_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_bool_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmx_byaml_bool_be={UINT32_C(0x602E0070),"byaml_bool_be",sxmx_byaml_bool_be_fields,SX_COUNT(sxmx_byaml_bool_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_int_be_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxmx_byaml_int_be={UINT32_C(0x602E0071),"byaml_int_be",sxmx_byaml_int_be_fields,SX_COUNT(sxmx_byaml_int_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_float_be_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
static const sx_layout sxmx_byaml_float_be={UINT32_C(0x602E0072),"byaml_float_be",sxmx_byaml_float_be_fields,SX_COUNT(sxmx_byaml_float_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_uint_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxmx_byaml_uint_be={UINT32_C(0x602E0073),"byaml_uint_be",sxmx_byaml_uint_be_fields,SX_COUNT(sxmx_byaml_uint_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_node_value_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_byaml_node_value_be={UINT32_C(0x602E0074),"byaml_node_value_be",sxmx_byaml_node_value_be_fields,SX_COUNT(sxmx_byaml_node_value_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_null_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_RESERVED),
};
static const sx_layout sxmx_byaml_null_be={UINT32_C(0x602E0075),"byaml_null_be",sxmx_byaml_null_be_fields,SX_COUNT(sxmx_byaml_null_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("byte_order","uint16",8,2,SX_ID),
 SX_FIELD("header_size","uint16",10,2,SX_SIZE),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("alignment","uint32",16,4,SX_SIZE),
 SX_FIELD("name_relative","int32",20,4,SX_OFFSET),
 SX_FIELD("string_pool_size","uint32",24,4,SX_SIZE),
 SX_FIELD("string_pool_relative","int32",28,4,SX_OFFSET),
 SX_FIELD("path_relative","int32",32,4,SX_OFFSET),
 SX_FIELD("model_count","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("unknown_26","uint16",38,2,SX_NONE),
 SX_FIELD("unknown_28","uint32",40,4,SX_NONE),
 SX_FIELD("model_dictionary_relative","int32",44,4,SX_OFFSET),
 SX_FIELD("unknown_30","uint32",48,4,SX_NONE),
 SX_FIELD("unknown_34","uint32",52,4,SX_NONE),
};
static const sx_layout sxmx_fsha_header={UINT32_C(0x602E0076),"fsha_header",sxmx_fsha_header_fields,SX_COUNT(sxmx_fsha_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_string_length_fields[]={
 SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmx_fsha_string_length={UINT32_C(0x602E0077),"fsha_string_length",sxmx_fsha_string_length_fields,SX_COUNT(sxmx_fsha_string_length_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_model_fields[]={
 SX_FIELD("opaque_0","bytes",0,6,SX_NONE),
 SX_FIELD("program_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("opaque_8","bytes",8,20,SX_NONE),
 SX_FIELD("program_index","uint32",28,4,SX_ID),
 SX_FIELD("name_relative","int32",32,4,SX_OFFSET),
 SX_FIELD("opaque_24","bytes",36,52,SX_NONE),
 SX_FIELD("programs_relative","int32",88,4,SX_OFFSET),
 SX_FIELD("unknown_5c","uint32",92,4,SX_NONE),
 SX_FIELD("archive_relative","int32",96,4,SX_OFFSET),
 SX_FIELD("unknown_64","bytes",100,12,SX_NONE),
};
static const sx_layout sxmx_fsha_model={UINT32_C(0x602E0078),"fsha_model",sxmx_fsha_model_fields,SX_COUNT(sxmx_fsha_model_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_program_fields[]={
 SX_FIELD("opaque_0","bytes",0,40,SX_NONE),
 SX_FIELD("vertex_shader_relative","int32",40,4,SX_OFFSET),
 SX_FIELD("geometry_shader_relative","int32",44,4,SX_OFFSET),
 SX_FIELD("pixel_shader_relative","int32",48,4,SX_OFFSET),
 SX_FIELD("model_relative","int32",52,4,SX_OFFSET),
};
static const sx_layout sxmx_fsha_program={UINT32_C(0x602E0079),"fsha_program",sxmx_fsha_program_fields,SX_COUNT(sxmx_fsha_program_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_vertex_shader_fields[]={
 SX_FIELD("gpu_registers","bytes",0,208,SX_NONE),
 SX_FIELD("code_size","uint32",208,4,SX_SIZE),
 SX_FIELD("code_relative","int32",212,4,SX_OFFSET),
 SX_FIELD("shader_mode","uint32",216,4,SX_ID),
 SX_FIELD("unused_native_metadata","bytes",220,88,SX_NONE),
};
static const sx_layout sxmx_fsha_vertex_shader={UINT32_C(0x602E007A),"fsha_vertex_shader",sxmx_fsha_vertex_shader_fields,SX_COUNT(sxmx_fsha_vertex_shader_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_pixel_shader_fields[]={
 SX_FIELD("gpu_registers","bytes",0,164,SX_NONE),
 SX_FIELD("code_size","uint32",164,4,SX_SIZE),
 SX_FIELD("code_relative","int32",168,4,SX_OFFSET),
 SX_FIELD("shader_mode","uint32",172,4,SX_ID),
 SX_FIELD("unused_native_metadata","bytes",176,56,SX_NONE),
};
static const sx_layout sxmx_fsha_pixel_shader={UINT32_C(0x602E007B),"fsha_pixel_shader",sxmx_fsha_pixel_shader_fields,SX_COUNT(sxmx_fsha_pixel_shader_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("table_size_after_prefix","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_ID),
 SX_FIELD("rows_relative","uint16",10,2,SX_OFFSET),
 SX_FIELD("strings_relative","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_relative","uint32",16,4,SX_OFFSET),
 SX_FIELD("table_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("column_count","uint16",24,2,SX_COUNT_PROP),
 SX_FIELD("row_size","uint16",26,2,SX_SIZE),
 SX_FIELD("row_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_utf_header={UINT32_C(0x602E007C),"utf_header",sxmx_utf_header_fields,SX_COUNT(sxmx_utf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_column_fields[]={
 SX_FIELD("storage_and_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint32",1,4,SX_OFFSET),
};
static const sx_layout sxmx_utf_column={UINT32_C(0x602E007D),"utf_column",sxmx_utf_column_fields,SX_COUNT(sxmx_utf_column_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_u8_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxmx_utf_u8={UINT32_C(0x602E007E),"utf_u8",sxmx_utf_u8_fields,SX_COUNT(sxmx_utf_u8_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_i8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxmx_utf_i8={UINT32_C(0x602E007F),"utf_i8",sxmx_utf_i8_fields,SX_COUNT(sxmx_utf_i8_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_u16_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxmx_utf_u16={UINT32_C(0x602E0080),"utf_u16",sxmx_utf_u16_fields,SX_COUNT(sxmx_utf_u16_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_i16_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxmx_utf_i16={UINT32_C(0x602E0081),"utf_i16",sxmx_utf_i16_fields,SX_COUNT(sxmx_utf_i16_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_u32_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxmx_utf_u32={UINT32_C(0x602E0082),"utf_u32",sxmx_utf_u32_fields,SX_COUNT(sxmx_utf_u32_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_i32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxmx_utf_i32={UINT32_C(0x602E0083),"utf_i32",sxmx_utf_i32_fields,SX_COUNT(sxmx_utf_i32_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_u64_fields[]={
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
static const sx_layout sxmx_utf_u64={UINT32_C(0x602E0084),"utf_u64",sxmx_utf_u64_fields,SX_COUNT(sxmx_utf_u64_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_i64_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxmx_utf_i64={UINT32_C(0x602E0085),"utf_i64",sxmx_utf_i64_fields,SX_COUNT(sxmx_utf_i64_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_float_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
static const sx_layout sxmx_utf_float={UINT32_C(0x602E0086),"utf_float",sxmx_utf_float_fields,SX_COUNT(sxmx_utf_float_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_double_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
static const sx_layout sxmx_utf_double={UINT32_C(0x602E0087),"utf_double",sxmx_utf_double_fields,SX_COUNT(sxmx_utf_double_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_string_fields[]={
 SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_utf_string={UINT32_C(0x602E0088),"utf_string",sxmx_utf_string_fields,SX_COUNT(sxmx_utf_string_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_binary_fields[]={
 SX_FIELD("data_relative","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmx_utf_binary={UINT32_C(0x602E0089),"utf_binary",sxmx_utf_binary_fields,SX_COUNT(sxmx_utf_binary_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_guid_fields[]={
 SX_FIELD("guid","bytes",0,16,SX_ID),
};
static const sx_layout sxmx_utf_guid={UINT32_C(0x602E008A),"utf_guid",sxmx_utf_guid_fields,SX_COUNT(sxmx_utf_guid_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_iqm_header_fields[]={
 SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("version","uint32",16,4,SX_ID),
 SX_FIELD("file_size","uint32",20,4,SX_SIZE),
 SX_FIELD("flags","uint32",24,4,SX_FLAGS),
 SX_FIELD("text_size","uint32",28,4,SX_SIZE),
 SX_FIELD("text_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("mesh_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("mesh_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("vertex_array_count","uint32",44,4,SX_COUNT_PROP),
 SX_FIELD("vertex_count","uint32",48,4,SX_COUNT_PROP),
 SX_FIELD("vertex_array_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("triangle_count","uint32",56,4,SX_COUNT_PROP),
 SX_FIELD("triangle_offset","uint32",60,4,SX_OFFSET),
 SX_FIELD("adjacency_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("joint_count","uint32",68,4,SX_COUNT_PROP),
 SX_FIELD("joint_offset","uint32",72,4,SX_OFFSET),
 SX_FIELD("pose_count","uint32",76,4,SX_COUNT_PROP),
 SX_FIELD("pose_offset","uint32",80,4,SX_OFFSET),
 SX_FIELD("animation_count","uint32",84,4,SX_COUNT_PROP),
 SX_FIELD("animation_offset","uint32",88,4,SX_OFFSET),
 SX_FIELD("frame_count","uint32",92,4,SX_COUNT_PROP),
 SX_FIELD("frame_channel_count","uint32",96,4,SX_COUNT_PROP),
 SX_FIELD("frame_offset","uint32",100,4,SX_OFFSET),
 SX_FIELD("bounds_offset","uint32",104,4,SX_OFFSET),
 SX_FIELD("comment_size","uint32",108,4,SX_SIZE),
 SX_FIELD("comment_offset","uint32",112,4,SX_OFFSET),
 SX_FIELD("extension_count","uint32",116,4,SX_COUNT_PROP),
 SX_FIELD("extension_offset","uint32",120,4,SX_OFFSET),
};
static const sx_layout sxmx_iqm_header={UINT32_C(0x602E008B),"iqm_header",sxmx_iqm_header_fields,SX_COUNT(sxmx_iqm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_mesh_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("material_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("first_vertex","uint32",8,4,SX_ID),
 SX_FIELD("vertex_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("first_triangle","uint32",16,4,SX_ID),
 SX_FIELD("triangle_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_iqm_mesh={UINT32_C(0x602E008C),"iqm_mesh",sxmx_iqm_mesh_fields,SX_COUNT(sxmx_iqm_mesh_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_vertex_array_fields[]={
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("format","uint32",8,4,SX_ID),
 SX_FIELD("components","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxmx_iqm_vertex_array={UINT32_C(0x602E008D),"iqm_vertex_array",sxmx_iqm_vertex_array_fields,SX_COUNT(sxmx_iqm_vertex_array_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_triangle_fields[]={
 SX_FIELD("vertex0","uint32",0,4,SX_ID),
 SX_FIELD("vertex1","uint32",4,4,SX_ID),
 SX_FIELD("vertex2","uint32",8,4,SX_ID),
};
static const sx_layout sxmx_iqm_triangle={UINT32_C(0x602E008E),"iqm_triangle",sxmx_iqm_triangle_fields,SX_COUNT(sxmx_iqm_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_adjacency_fields[]={
 SX_FIELD("triangle0","uint32",0,4,SX_ID),
 SX_FIELD("triangle1","uint32",4,4,SX_ID),
 SX_FIELD("triangle2","uint32",8,4,SX_ID),
};
static const sx_layout sxmx_iqm_adjacency={UINT32_C(0x602E008F),"iqm_adjacency",sxmx_iqm_adjacency_fields,SX_COUNT(sxmx_iqm_adjacency_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_float_fields[]={
 SX_FIELD("component","float",0,4,SX_NONE),
};
static const sx_layout sxmx_iqm_float={UINT32_C(0x602E0090),"iqm_float",sxmx_iqm_float_fields,SX_COUNT(sxmx_iqm_float_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_color_fields[]={
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
 SX_FIELD("alpha","uint8",3,1,SX_NONE),
};
static const sx_layout sxmx_iqm_color={UINT32_C(0x602E0091),"iqm_color",sxmx_iqm_color_fields,SX_COUNT(sxmx_iqm_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psx_chunk_fields[]={
 SX_FIELD("name","char[20]",0,20,SX_ID),
 SX_FIELD("type_flags","int32",20,4,SX_FLAGS),
 SX_FIELD("entry_size","int32",24,4,SX_SIZE),
 SX_FIELD("entry_count","int32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_psx_chunk={UINT32_C(0x602E0092),"psx_chunk",sxmx_psx_chunk_fields,SX_COUNT(sxmx_psx_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psx_bone_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("flags","int32",64,4,SX_FLAGS),
 SX_FIELD("child_count","int32",68,4,SX_COUNT_PROP),
 SX_FIELD("parent_index","int32",72,4,SX_ID),
 SX_FIELD("rotation_x","float",76,4,SX_NONE),
 SX_FIELD("rotation_y","float",80,4,SX_NONE),
 SX_FIELD("rotation_z","float",84,4,SX_NONE),
 SX_FIELD("rotation_w","float",88,4,SX_NONE),
 SX_FIELD("location_x","float",92,4,SX_NONE),
 SX_FIELD("location_y","float",96,4,SX_NONE),
 SX_FIELD("location_z","float",100,4,SX_NONE),
 SX_FIELD("length","float",104,4,SX_NONE),
 SX_FIELD("size_x","float",108,4,SX_NONE),
 SX_FIELD("size_y","float",112,4,SX_NONE),
 SX_FIELD("size_z","float",116,4,SX_NONE),
};
static const sx_layout sxmx_psx_bone={UINT32_C(0x602E0093),"psx_bone",sxmx_psx_bone_fields,SX_COUNT(sxmx_psx_bone_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_point_fields[]={
 SX_FIELD("x","float",0,4,SX_NONE),
 SX_FIELD("y","float",4,4,SX_NONE),
 SX_FIELD("z","float",8,4,SX_NONE),
};
static const sx_layout sxmx_psk_point={UINT32_C(0x602E0094),"psk_point",sxmx_psk_point_fields,SX_COUNT(sxmx_psk_point_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_wedge_fields[]={
 SX_FIELD("point_index","uint32",0,4,SX_ID),
 SX_FIELD("u","float",4,4,SX_NONE),
 SX_FIELD("v","float",8,4,SX_NONE),
 SX_FIELD("material_index","uint8",12,1,SX_ID),
 SX_FIELD("reserved","int8",13,1,SX_RESERVED),
 SX_FIELD("padding","int16",14,2,SX_NONE),
};
static const sx_layout sxmx_psk_wedge={UINT32_C(0x602E0095),"psk_wedge",sxmx_psk_wedge_fields,SX_COUNT(sxmx_psk_wedge_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_face_fields[]={
 SX_FIELD("wedge0","uint16",0,2,SX_ID),
 SX_FIELD("wedge1","uint16",2,2,SX_ID),
 SX_FIELD("wedge2","uint16",4,2,SX_ID),
 SX_FIELD("material_index","uint8",6,1,SX_ID),
 SX_FIELD("auxiliary_material","uint8",7,1,SX_ID),
 SX_FIELD("smoothing_groups","int32",8,4,SX_FLAGS),
};
static const sx_layout sxmx_psk_face={UINT32_C(0x602E0096),"psk_face",sxmx_psk_face_fields,SX_COUNT(sxmx_psk_face_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_material_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("texture_index","int32",64,4,SX_ID),
 SX_FIELD("polygon_flags","int32",68,4,SX_FLAGS),
 SX_FIELD("auxiliary_material","int32",72,4,SX_ID),
 SX_FIELD("auxiliary_flags","int32",76,4,SX_FLAGS),
 SX_FIELD("lod_bias","int32",80,4,SX_NONE),
 SX_FIELD("lod_style","int32",84,4,SX_ID),
};
static const sx_layout sxmx_psk_material={UINT32_C(0x602E0097),"psk_material",sxmx_psk_material_fields,SX_COUNT(sxmx_psk_material_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_weight_fields[]={
 SX_FIELD("weight","float",0,4,SX_NONE),
 SX_FIELD("point_index","int32",4,4,SX_ID),
 SX_FIELD("bone_index","int32",8,4,SX_ID),
};
static const sx_layout sxmx_psk_weight={UINT32_C(0x602E0098),"psk_weight",sxmx_psk_weight_fields,SX_COUNT(sxmx_psk_weight_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psa_sequence_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("group","char[64]",64,64,SX_STRING),
 SX_FIELD("bone_count","int32",128,4,SX_COUNT_PROP),
 SX_FIELD("root_include","int32",132,4,SX_FLAGS),
 SX_FIELD("compression_style","int32",136,4,SX_ID),
 SX_FIELD("key_quotum","int32",140,4,SX_COUNT_PROP),
 SX_FIELD("key_reduction","float",144,4,SX_NONE),
 SX_FIELD("track_time","float",148,4,SX_NONE),
 SX_FIELD("frames_per_second","float",152,4,SX_NONE),
 SX_FIELD("start_bone","int32",156,4,SX_ID),
 SX_FIELD("first_frame","int32",160,4,SX_ID),
 SX_FIELD("frame_count","int32",164,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_psa_sequence={UINT32_C(0x602E0099),"psa_sequence",sxmx_psa_sequence_fields,SX_COUNT(sxmx_psa_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psa_key_fields[]={
 SX_FIELD("location_x","float",0,4,SX_NONE),
 SX_FIELD("location_y","float",4,4,SX_NONE),
 SX_FIELD("location_z","float",8,4,SX_NONE),
 SX_FIELD("rotation_x","float",12,4,SX_NONE),
 SX_FIELD("rotation_y","float",16,4,SX_NONE),
 SX_FIELD("rotation_z","float",20,4,SX_NONE),
 SX_FIELD("rotation_w","float",24,4,SX_NONE),
 SX_FIELD("time","float",28,4,SX_NONE),
};
static const sx_layout sxmx_psa_key={UINT32_C(0x602E009A),"psa_key",sxmx_psa_key_fields,SX_COUNT(sxmx_psa_key_fields),SX_LE};
static const sx_layout *const sx_mediaextra_layouts[]={
 &sxmx_lab_header,
 &sxmx_lab_entry,
 &sxmx_bun_header,
 &sxmx_bun_lb83_entry,
 &sxmx_bun_lb23_entry,
 &sxmx_mhk_header,
 &sxmx_mhk_directory,
 &sxmx_mhk_type,
 &sxmx_mhk_count32,
 &sxmx_mhk_count16,
 &sxmx_mhk_file,
 &sxmx_mhk_resource,
 &sxmx_mhk_name,
 &sxmx_pod2_header,
 &sxmx_pod2_entry,
 &sxmx_pod2_audit,
 &sxmx_vpp3_header_le,
 &sxmx_vpp3_entry_le,
 &sxmx_vpp3_header_be,
 &sxmx_vpp3_entry_be,
 &sxmx_myp_header,
 &sxmx_myp_block,
 &sxmx_myp_entry,
 &sxmx_rez_header,
 &sxmx_rez_directory_entry,
 &sxmx_rez_resource_entry,
 &sxmx_rez_key,
 &sxmx_hpak_header,
 &sxmx_hpak_directory,
 &sxmx_hpak_entry,
 &sxmx_brres_header,
 &sxmx_brres_root,
 &sxmx_brres_dictionary,
 &sxmx_brres_node,
 &sxmx_brres_resource,
 &sxmx_cflyt_header_le,
 &sxmx_bflyt_header_le,
 &sxmx_section_le,
 &sxmx_nw_layout_le,
 &sxmx_clyt_layout_le,
 &sxmx_nw_names_le,
 &sxmx_nw_name_offset_le,
 &sxmx_cflyt_header_be,
 &sxmx_bflyt_header_be,
 &sxmx_section_be,
 &sxmx_nw_layout_be,
 &sxmx_clyt_layout_be,
 &sxmx_nw_names_be,
 &sxmx_nw_name_offset_be,
 &sxmx_nw_header,
 &sxmx_nw_pane,
 &sxmx_nw_legacy_names,
 &sxmx_nw_legacy_name,
 &sxmx_nw_group,
 &sxmx_nw_pane_reference,
 &sxmx_chunky_header,
 &sxmx_chunky_chunk,
 &sxmx_j3d_header,
 &sxmx_btk_ttk1,
 &sxmx_btk_selection,
 &sxmx_btk_remap,
 &sxmx_btk_texture_matrix_index,
 &sxmx_btk_float,
 &sxmx_btk_rotation,
 &sxmx_j3d_name_table,
 &sxmx_j3d_name,
 &sxmx_brlan_pai1,
 &sxmx_brlan_binding,
 &sxmx_brlan_group,
 &sxmx_brlan_track,
 &sxmx_brlan_key,
 &sxmx_relative_offset_be,
 &sxmx_bfres_header,
 &sxmx_bfres_dictionary,
 &sxmx_bfres_node,
 &sxmx_bfres_external,
 &sxmx_cgfx_slot,
 &sxmx_cgfx_dictionary,
 &sxmx_cgfx_node,
 &sxmx_unity_header,
 &sxmx_unity_metadata_flags,
 &sxmx_unity_type,
 &sxmx_unity_object_count,
 &sxmx_unity_object,
 &sxmx_unity_tail_counts,
 &sxmx_ue1_header,
 &sxmx_ue1_name_flags,
 &sxmx_ue1_heritage,
 &sxmx_sga6_header,
 &sxmx_sga6_table_slot,
 &sxmx_sga6_drive,
 &sxmx_sga6_folder,
 &sxmx_sga6_file,
 &sxmx_byaml_header_le,
 &sxmx_byaml_node_le,
 &sxmx_byaml_string_offset_le,
 &sxmx_byaml_map_key_le,
 &sxmx_byaml_array_kind_le,
 &sxmx_byaml_string_le,
 &sxmx_byaml_bool_le,
 &sxmx_byaml_int_le,
 &sxmx_byaml_float_le,
 &sxmx_byaml_uint_le,
 &sxmx_byaml_node_value_le,
 &sxmx_byaml_null_le,
 &sxmx_byaml_header_be,
 &sxmx_byaml_node_be,
 &sxmx_byaml_string_offset_be,
 &sxmx_byaml_map_key_be,
 &sxmx_byaml_array_kind_be,
 &sxmx_byaml_string_be,
 &sxmx_byaml_bool_be,
 &sxmx_byaml_int_be,
 &sxmx_byaml_float_be,
 &sxmx_byaml_uint_be,
 &sxmx_byaml_node_value_be,
 &sxmx_byaml_null_be,
 &sxmx_fsha_header,
 &sxmx_fsha_string_length,
 &sxmx_fsha_model,
 &sxmx_fsha_program,
 &sxmx_fsha_vertex_shader,
 &sxmx_fsha_pixel_shader,
 &sxmx_utf_header,
 &sxmx_utf_column,
 &sxmx_utf_u8,
 &sxmx_utf_i8,
 &sxmx_utf_u16,
 &sxmx_utf_i16,
 &sxmx_utf_u32,
 &sxmx_utf_i32,
 &sxmx_utf_u64,
 &sxmx_utf_i64,
 &sxmx_utf_float,
 &sxmx_utf_double,
 &sxmx_utf_string,
 &sxmx_utf_binary,
 &sxmx_utf_guid,
 &sxmx_iqm_header,
 &sxmx_iqm_mesh,
 &sxmx_iqm_vertex_array,
 &sxmx_iqm_triangle,
 &sxmx_iqm_adjacency,
 &sxmx_iqm_float,
 &sxmx_iqm_color,
 &sxmx_psx_chunk,
 &sxmx_psx_bone,
 &sxmx_psk_point,
 &sxmx_psk_wedge,
 &sxmx_psk_face,
 &sxmx_psk_material,
 &sxmx_psk_weight,
 &sxmx_psa_sequence,
 &sxmx_psa_key,
};
typedef struct sxmx_view {sx_context *c;uint8_t *p;size_t n;unsigned work;}sxmx_view;
static bool sxmx_need(sxmx_view *v,size_t at,uint64_t n,size_t end){return !xx_pd_is_stopped(v->c->pd)&&end<=v->n&&at<=end&&n<=end-at;}
static uint16_t sxmx_u16(const uint8_t*p,bool be){return xx_data_get_u16(p,2,0,be);}
static uint32_t sxmx_u32(const uint8_t*p,bool be){return xx_data_get_u32(p,4,0,be);}
static bool sxmx_row(sxmx_view *v,const sx_layout*l,size_t at,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t n=(size_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxmx_need(v,at,n,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)n);}
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_table(sxmx_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t z=(size_t)(f->rel_offset+f->size);if(count>4000000||!sxmx_need(v,at,count*z,end))return false;for(uint64_t i=0;i<count;i++,at+=z)if(!sxmx_row(v,l,at,end))return false;return true;}
static int sxmx_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmx_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmx_order);
 /* Native readers can permit shared descriptor ranges. Keep one physical interpretation;
  * never repeat identical source bytes as overlapping structures. */
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmx_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}

static uint64_t sxmx_u64(const uint8_t*p,bool be){return xx_data_get_u64(p,8,0,be);}
static bool sxmx_cstr(sxmx_view*v,size_t*at,size_t end){size_t n=0;while(*at<end&&n<4096&&sxmx_need(v,*at,1,end)){if(!v->p[(*at)++])return true;n++;}return false;}
static bool sxmx_lab(sxmx_view*v)
{return SM_ROW(lab_header,0,v->n)&&sxmx_table(v,&sxmx_lab_entry,16,sxmx_u32(v->p+8,false),v->n);}
static bool sxmx_bun(sxmx_view*v)
{if(!SM_ROW(bun_header,0,v->n))return false;return sxmx_table(v,!xx_rt_memcmp(v->p,"LB83",4)?&sxmx_bun_lb83_entry:&sxmx_bun_lb23_entry,sxmx_u32(v->p+4,true),sxmx_u32(v->p+8,true),v->n);}
static bool sxmx_mhk(sxmx_view*v)
{if(!SM_ROW(mhk_header,0,v->n))return false;size_t base=sxmx_u32(v->p+20,true),ft=base+sxmx_u16(v->p+24,true);if(!SM_ROW(mhk_directory,base,v->n)||!SM_ROW(mhk_count32,ft,v->n))return false;uint32_t n=sxmx_u32(v->p+ft,true),types=sxmx_u16(v->p+base+2,true);if(!sxmx_table(v,&sxmx_mhk_file,ft+4,n,v->n)||!sxmx_table(v,&sxmx_mhk_type,base+4,types,v->n))return false;for(uint32_t i=0;i<types;i++){const uint8_t*p=v->p+base+4+(size_t)i*8;size_t rt=base+sxmx_u16(p+4,true),nt=base+sxmx_u16(p+6,true);if(!SM_ROW(mhk_count16,rt,v->n)||!SM_ROW(mhk_count16,nt,v->n)||!sxmx_table(v,&sxmx_mhk_resource,rt+2,sxmx_u16(v->p+rt,true),v->n)||!sxmx_table(v,&sxmx_mhk_name,nt+2,sxmx_u16(v->p+nt,true),v->n))return false;}return true;}
static bool sxmx_pod(sxmx_view*v)
{if(!SM_ROW(pod2_header,0,v->n))return false;uint32_t n=sxmx_u32(v->p+88,false),a=sxmx_u32(v->p+92,false);uint64_t bytes=(uint64_t)a*312;if(bytes>v->n)return false;return sxmx_table(v,&sxmx_pod2_entry,96,n,v->n)&&sxmx_table(v,&sxmx_pod2_audit,v->n-(size_t)bytes,a,v->n);}
static bool sxmx_vpp(sxmx_view*v)
{if(!sxmx_need(v,0,376,v->n))return false;bool be=sxmx_u32(v->p,true)==0x51890ace;return sxmx_row(v,be?&sxmx_vpp3_header_be:&sxmx_vpp3_header_le,0,v->n)&&sxmx_table(v,be?&sxmx_vpp3_entry_be:&sxmx_vpp3_entry_le,2048,sxmx_u32(v->p+340,be),v->n);}
static bool sxmx_myp(sxmx_view*v)
{if(!SM_ROW(myp_header,0,v->n))return false;uint64_t at=sxmx_u64(v->p+12,false);for(unsigned steps=0;at;steps++){if(steps>=1024||at>v->n||!SM_ROW(myp_block,(size_t)at,v->n))return false;uint32_t n=sxmx_u32(v->p+at,false);uint64_t next=sxmx_u64(v->p+at+4,false);if(!sxmx_table(v,&sxmx_myp_entry,(size_t)at+12,n,v->n))return false;if(next&&next<at+12+(uint64_t)n*34)return false;at=next;}return true;}
static bool sxmx_rez(sxmx_view*v)
{if(!SM_ROW(rez_header,0,v->n))return false;struct{size_t at,n;}q[1024];unsigned used=0,count=1;q[0].at=sxmx_u32(v->p+131,false);q[0].n=sxmx_u32(v->p+135,false);while(used<count){size_t at=q[used].at,n=q[used++].n;if(!sxmx_need(v,at,n,v->n))return false;size_t end=at+n;while(at<end){if(!sxmx_need(v,at,16,end))return false;uint32_t kind=sxmx_u32(v->p+at,false),off=sxmx_u32(v->p+at+4,false),bytes=sxmx_u32(v->p+at+8,false);if(kind==1){if(count>=1024||!SM_ROW(rez_directory_entry,at,end))return false;at+=16;if(!sxmx_cstr(v,&at,end))return false;q[count].at=off;q[count++].n=bytes;}else if(kind==0){if(!SM_ROW(rez_resource_entry,at,end))return false;uint32_t keys=sxmx_u32(v->p+at+24,false);at+=28;if(!sxmx_cstr(v,&at,end)||!sxmx_cstr(v,&at,end)||!sxmx_table(v,&sxmx_rez_key,at,keys,end))return false;at+=(size_t)keys*4;}else return false;}}return true;}
static bool sxmx_hpak(sxmx_view*v)
{if(!SM_ROW(hpak_header,0,v->n))return false;size_t at=sxmx_u32(v->p+8,false);if(!SM_ROW(hpak_directory,at,v->n))return false;return sxmx_table(v,&sxmx_hpak_entry,at+4,sxmx_u32(v->p+at,false),v->n);}
static bool sxmx_brres(sxmx_view*v)
{if(!SM_ROW(brres_header,0,v->n))return false;size_t root=sxmx_u16(v->p+12,true),master=root+8;if(!SM_ROW(brres_root,root,v->n)||!SM_ROW(brres_dictionary,master,v->n))return false;uint32_t groups=sxmx_u32(v->p+master+4,true);if(!sxmx_table(v,&sxmx_brres_node,master+8,(uint64_t)groups+1,v->n))return false;for(uint32_t i=0;i<groups;i++){int64_t sub=(int64_t)master+(int32_t)sxmx_u32(v->p+master+24+(size_t)i*16+12,true);if(sub<0||(uint64_t)sub>v->n||!SM_ROW(brres_dictionary,(size_t)sub,v->n))return false;uint32_t n=sxmx_u32(v->p+sub+4,true);if(!sxmx_table(v,&sxmx_brres_node,(size_t)sub+8,(uint64_t)n+1,v->n))return false;for(uint32_t j=0;j<n;j++){int64_t at=sub+(int32_t)sxmx_u32(v->p+sub+24+(size_t)j*16+12,true);if(at<0||(uint64_t)at>v->n||!SM_ROW(brres_resource,(size_t)at,v->n))return false;}}return true;}
static bool sxmx_nw(sxmx_view*v)
{xx_file_type_t t=v->c->f->file_type;bool legacy=t==XX_FILE_TYPE_NINTENDO_BRLYT,fly=t==XX_FILE_TYPE_NINTENDO_BFLYT,be=legacy||(v->n>=6&&v->p[4]==0xfe);const sx_layout*head=legacy?&sxmx_nw_header:fly?(be?&sxmx_bflyt_header_be:&sxmx_bflyt_header_le):(be?&sxmx_cflyt_header_be:&sxmx_cflyt_header_le);if(!sxmx_row(v,head,0,v->n))return false;size_t at=legacy?16:20;uint32_t n=legacy?sxmx_u16(v->p+14,true):fly?sxmx_u16(v->p+16,be):sxmx_u32(v->p+16,be);if(n>4096)return false;for(uint32_t i=0;i<n;i++){if(!sxmx_need(v,at,8,v->n))return false;size_t size=sxmx_u32(v->p+at+4,be);if(size<8||!sxmx_need(v,at,size,v->n)||!sxmx_row(v,be?&sxmx_section_be:&sxmx_section_le,at,at+size))return false;size_t end=at+size;const uint8_t*p=v->p+at;if(!xx_rt_memcmp(p,"lyt1",4)){const sx_layout*l=legacy||fly?(be?&sxmx_nw_layout_be:&sxmx_nw_layout_le):(be?&sxmx_clyt_layout_be:&sxmx_clyt_layout_le);if(!sxmx_row(v,l,at+8,end))return false;}else if(legacy&&!xx_rt_memcmp(p,"pan1",4)){if(!SM_ROW(nw_pane,at+8,end))return false;}else if(!xx_rt_memcmp(p,"txl1",4)||!xx_rt_memcmp(p,"fnl1",4)){const sx_layout*l=legacy?&sxmx_nw_legacy_names:be?&sxmx_nw_names_be:&sxmx_nw_names_le;if(!sxmx_row(v,l,at+8,end))return false;uint32_t num=legacy?sxmx_u16(p+8,true):sxmx_u32(p+8,be);if(!sxmx_table(v,legacy?&sxmx_nw_legacy_name:be?&sxmx_nw_name_offset_be:&sxmx_nw_name_offset_le,at+12,num,end))return false;}else if(legacy&&!xx_rt_memcmp(p,"grp1",4)){if(!SM_ROW(nw_group,at+8,end)||!sxmx_table(v,&sxmx_nw_pane_reference,at+28,sxmx_u16(p+24,true),end))return false;}at=end;}return at==v->n;}
static bool sxmx_chunky_nodes(sxmx_view*v,size_t at,size_t end,unsigned depth)
{if(depth>32)return false;while(at<end){if(!SM_ROW(chunky_chunk,at,end))return false;uint32_t size=sxmx_u32(v->p+at+12,false),names=sxmx_u32(v->p+at+16,false);bool folder=!xx_rt_memcmp(v->p+at,"FOLD",4);at+=28;if(!sxmx_need(v,at,(uint64_t)names+size,end))return false;at+=names;if(folder&&!sxmx_chunky_nodes(v,at,at+size,depth+1))return false;at+=size;}return at==end;}
static bool sxmx_chunky(sxmx_view*v){return SM_ROW(chunky_header,0,v->n)&&sxmx_chunky_nodes(v,36,v->n,0);}
static bool sxmx_j3d(sxmx_view*v)
{if(!SM_ROW(j3d_header,0,v->n))return false;uint32_t n=sxmx_u32(v->p+12,true);if(n>4096)return false;size_t at=32;for(uint32_t i=0;i<n;i++){if(!SM_ROW(section_be,at,v->n))return false;size_t size=sxmx_u32(v->p+at+4,true);if(size<8||!sxmx_need(v,at,size,v->n))return false;at+=size;}return at==v->n;}
static bool sxmx_btk(sxmx_view*v)
{if(!SM_ROW(j3d_header,0,v->n)||!SM_ROW(btk_ttk1,32,v->n))return false;const uint8_t*p=v->p+32;size_t end=32+(size_t)sxmx_u32(p+4,true);if(end>v->n)return false;uint32_t n=sxmx_u16(p+12,true);uint32_t count[8]={n,n/3,n/3,n/3,n,sxmx_u16(p+14,true),sxmx_u16(p+16,true),sxmx_u16(p+18,true)};const sx_layout*ls[8]={&sxmx_btk_selection,&sxmx_btk_remap,NULL,&sxmx_btk_texture_matrix_index,&sxmx_btk_float,&sxmx_btk_float,&sxmx_btk_rotation,&sxmx_btk_float};for(unsigned i=0;i<8;i++){size_t at=32+(size_t)sxmx_u32(p+20+i*4,true);if(i==2){if(!SM_ROW(j3d_name_table,at,end)||!sxmx_table(v,&sxmx_j3d_name,at+4,count[i],end))return false;}else if(!sxmx_table(v,ls[i],at,count[i],end))return false;}return true;}
static bool sxmx_brlan(sxmx_view*v)
{if(!SM_ROW(nw_header,0,v->n)||!SM_ROW(brlan_pai1,16,v->n))return false;uint32_t n=sxmx_u16(v->p+30,true);size_t table=16+(size_t)sxmx_u32(v->p+32,true);if(n>32||!sxmx_table(v,&sxmx_relative_offset_be,table,n,v->n))return false;for(uint32_t i=0;i<n;i++){size_t at=16+(size_t)sxmx_u32(v->p+table+(size_t)i*4,true);if(!SM_ROW(brlan_binding,at,v->n))return false;size_t group=at+sxmx_u32(v->p+at+24,true);if(!SM_ROW(brlan_group,group,v->n))return false;uint32_t tracks=v->p[group+4];if(tracks>10||!sxmx_table(v,&sxmx_relative_offset_be,group+8,tracks,v->n))return false;for(uint32_t j=0;j<tracks;j++){size_t track=group+sxmx_u32(v->p+group+8+(size_t)j*4,true);if(!SM_ROW(brlan_track,track,v->n))return false;size_t key=track+sxmx_u32(v->p+track+8,true);if(!sxmx_table(v,&sxmx_brlan_key,key,sxmx_u16(v->p+track+4,true),v->n))return false;}}return true;}
static bool sxmx_relative(sxmx_view*v,size_t word,bool be,size_t*target)
{if(!sxmx_need(v,word,4,v->n))return false;int64_t at=(int64_t)word+(int32_t)sxmx_u32(v->p+word,be);if(at<0||(uint64_t)at>v->n)return false;*target=(size_t)at;return true;}
static bool sxmx_bfres(sxmx_view*v)
{size_t at;if(!SM_ROW(bfres_header,0,v->n)||!sxmx_relative(v,76,true,&at)||!SM_ROW(bfres_dictionary,at,v->n))return false;uint32_t n=sxmx_u32(v->p+at+4,true);if(n>1024||!sxmx_table(v,&sxmx_bfres_node,at+8,(uint64_t)n+1,v->n))return false;for(uint32_t i=1;i<=n;i++){size_t target;if(!sxmx_relative(v,at+8+(size_t)i*16+12,true,&target)||!SM_ROW(bfres_external,target,v->n))return false;}return true;}
static bool sxmx_cgfx(sxmx_view*v)
{if(!SM_ROW(cflyt_header_le,0,v->n)||!SM_ROW(section_le,20,v->n)||!sxmx_table(v,&sxmx_cgfx_slot,28,16,v->n))return false;size_t end=20+(size_t)sxmx_u32(v->p+24,false);if(end>v->n)return false;for(unsigned i=0;i<16;i++){size_t word=32+(size_t)i*8;if(sxmx_u32(v->p+word-4,false)){size_t at;if(!sxmx_relative(v,word,false,&at)||!SM_ROW(cgfx_dictionary,at,end))return false;uint32_t n=sxmx_u32(v->p+at+8,false);if(n>1024||!sxmx_table(v,&sxmx_cgfx_node,at+12,(uint64_t)n+1,end))return false;}}return sxmx_u32(v->p+16,false)!=2||SM_ROW(section_le,end,v->n);}
static bool sxmx_unity(sxmx_view*v)
{if(!SM_ROW(unity_header,0,v->n))return false;size_t at=48,end=48+(size_t)sxmx_u32(v->p+20,true);if(end>v->n||!sxmx_cstr(v,&at,end)||!SM_ROW(unity_metadata_flags,at,end))return false;uint32_t types=sxmx_u32(v->p+at+5,false);at+=9;if(!sxmx_table(v,&sxmx_unity_type,at,types,end))return false;at+=(size_t)types*23;if(!SM_ROW(unity_object_count,at,end))return false;uint32_t n=sxmx_u32(v->p+at,false);at+=4;if(n>1024)return false;for(uint32_t i=0;i<n;i++){at=(at+3)&~(size_t)3;if(!SM_ROW(unity_object,at,end))return false;at+=24;}return SM_ROW(unity_tail_counts,at,end);}
static bool sxmx_ue1(sxmx_view*v)
{if(!SM_ROW(ue1_header,0,v->n))return false;size_t at=sxmx_u32(v->p+16,false);uint32_t n=sxmx_u32(v->p+12,false);if(n>4096)return false;for(uint32_t i=0;i<n;i++){if(!sxmx_cstr(v,&at,v->n)||!SM_ROW(ue1_name_flags,at,v->n))return false;at+=4;}return sxmx_table(v,&sxmx_ue1_heritage,sxmx_u32(v->p+40,false),sxmx_u32(v->p+36,false),v->n);}
static bool sxmx_sga(sxmx_view*v)
{if(!SM_ROW(sga6_header,0,v->n)||!sxmx_table(v,&sxmx_sga6_table_slot,152,4,v->n))return false;size_t end=152+(size_t)sxmx_u32(v->p+140,false);if(end>v->n)return false;const sx_layout*ls[]={&sxmx_sga6_drive,&sxmx_sga6_folder,&sxmx_sga6_file};for(unsigned i=0;i<3;i++){const uint8_t*p=v->p+152+i*8;if(!sxmx_table(v,ls[i],152+(size_t)sxmx_u32(p,false),sxmx_u32(p+4,false),end))return false;}return true;}
static bool sxmx_by_value(sxmx_view*v,size_t at,unsigned kind,bool be,unsigned depth);
static bool sxmx_by_node(sxmx_view*v,size_t at,bool be,unsigned depth)
{if(depth>32||!sxmx_row(v,be?&sxmx_byaml_node_be:&sxmx_byaml_node_le,at,v->n))return false;uint32_t n=xx_data_get_u24(v->p+at+1,3,0,be);unsigned kind=v->p[at];if(n>1024||(kind!=0xc0&&kind!=0xc1))return false;if(kind==0xc1){if(!sxmx_need(v,at+4,(uint64_t)n*8,v->n))return false;for(uint32_t i=0;i<n;i++){size_t row=at+4+(size_t)i*8;if(!sxmx_row(v,be?&sxmx_byaml_map_key_be:&sxmx_byaml_map_key_le,row,v->n)||!sxmx_by_value(v,row+4,v->p[row+3],be,depth))return false;}}else{size_t values=at+4+((n+3U)&~3U);if(!sxmx_table(v,be?&sxmx_byaml_array_kind_be:&sxmx_byaml_array_kind_le,at+4,n,v->n)||!sxmx_need(v,values,(uint64_t)n*4,v->n))return false;for(uint32_t i=0;i<n;i++)if(!sxmx_by_value(v,values+(size_t)i*4,v->p[at+4+i],be,depth))return false;}return true;}
static bool sxmx_by_value(sxmx_view*v,size_t at,unsigned kind,bool be,unsigned depth)
{const sx_layout*l=NULL;switch(kind){case 0xa0:l=be?&sxmx_byaml_string_be:&sxmx_byaml_string_le;break;case 0xd0:l=be?&sxmx_byaml_bool_be:&sxmx_byaml_bool_le;break;case 0xd1:l=be?&sxmx_byaml_int_be:&sxmx_byaml_int_le;break;case 0xd2:l=be?&sxmx_byaml_float_be:&sxmx_byaml_float_le;break;case 0xd3:l=be?&sxmx_byaml_uint_be:&sxmx_byaml_uint_le;break;case 0xff:l=be?&sxmx_byaml_null_be:&sxmx_byaml_null_le;break;case 0xc0:case 0xc1:l=be?&sxmx_byaml_node_value_be:&sxmx_byaml_node_value_le;break;default:return false;}
 if(kind==0xc0||kind==0xc1){if(!sxmx_row(v,be?&sxmx_byaml_node_value_be:&sxmx_byaml_node_value_le,at,v->n))return false;return sxmx_by_node(v,sxmx_u32(v->p+at,be),be,depth+1);}return sxmx_row(v,l,at,v->n);}
static bool sxmx_byaml(sxmx_view*v)
{if(!sxmx_need(v,0,16,v->n))return false;bool be=v->p[0]=='B';if(!sxmx_row(v,be?&sxmx_byaml_header_be:&sxmx_byaml_header_le,0,v->n))return false;for(unsigned i=4;i<=8;i+=4){size_t at=sxmx_u32(v->p+i,be);if(at){if(!sxmx_row(v,be?&sxmx_byaml_node_be:&sxmx_byaml_node_le,at,v->n))return false;uint32_t n=xx_data_get_u24(v->p+at+1,3,0,be);if(n>1024||!sxmx_table(v,be?&sxmx_byaml_string_offset_be:&sxmx_byaml_string_offset_le,at+4,(uint64_t)n+1,v->n))return false;}}return sxmx_by_node(v,sxmx_u32(v->p+12,be),be,0);}
static bool sxmx_fsha_shader(sxmx_view*v,size_t word,bool pixel)
{size_t at;if(!sxmx_relative(v,word,true,&at))return false;if(at==word&&!sxmx_u32(v->p+word,true))return true;return sxmx_row(v,pixel?&sxmx_fsha_pixel_shader:&sxmx_fsha_vertex_shader,at,v->n);}
static bool sxmx_fsha(sxmx_view*v)
{size_t dict,pool;if(!SM_ROW(fsha_header,0,v->n)||!sxmx_relative(v,44,true,&dict)||!SM_ROW(bfres_dictionary,dict,v->n)||!sxmx_relative(v,28,true,&pool))return false;uint32_t n=sxmx_u32(v->p+dict+4,true);if(n>32||!sxmx_table(v,&sxmx_bfres_node,dict+8,(uint64_t)n+1,v->n))return false;size_t size=sxmx_u32(v->p+24,true);if(!sxmx_need(v,pool,size,v->n))return false;size_t at=pool,end=pool+size;while(at<end){if(!SM_ROW(fsha_string_length,at,end))return false;uint32_t z=sxmx_u32(v->p+at,true);at+=4;if(!sxmx_need(v,at,(uint64_t)z+1,end))return false;at=(at+z+1+3)&~(size_t)3;if(at>end)return false;}for(uint32_t i=1;i<=n;i++){size_t model,program;if(!sxmx_relative(v,dict+8+(size_t)i*16+12,true,&model)||!SM_ROW(fsha_model,model,v->n)||!sxmx_relative(v,model+88,true,&program))return false;uint32_t count=sxmx_u16(v->p+model+6,true);if(count>256||!sxmx_table(v,&sxmx_fsha_program,program,count,v->n))return false;for(uint32_t j=0;j<count;j++){size_t p=program+(size_t)j*56;if(!sxmx_fsha_shader(v,p+40,false)||!sxmx_fsha_shader(v,p+48,true))return false;}}return true;}
static bool sxmx_utf(sxmx_view*v)
{if(!SM_ROW(utf_header,0,v->n))return false;const sx_layout*ls[]={&sxmx_utf_u8,&sxmx_utf_i8,&sxmx_utf_u16,&sxmx_utf_i16,&sxmx_utf_u32,&sxmx_utf_i32,&sxmx_utf_u64,&sxmx_utf_i64,&sxmx_utf_float,&sxmx_utf_double,&sxmx_utf_string,&sxmx_utf_binary,&sxmx_utf_guid};const unsigned sizes[]={1,1,2,2,4,4,8,8,4,8,4,8,16};unsigned kinds[128],flags[128];size_t positions[128],width=0,at=32,row=8+(size_t)sxmx_u16(v->p+10,true),strings=8+(size_t)sxmx_u32(v->p+12,true);uint32_t n=sxmx_u16(v->p+24,true),rows=sxmx_u32(v->p+28,true),stride=sxmx_u16(v->p+26,true);if(n>128||rows>1024||row>strings||strings>v->n)return false;for(uint32_t i=0;i<n;i++){if(!SM_ROW(utf_column,at,row))return false;kinds[i]=v->p[at]&15;flags[i]=v->p[at]&0xf0;positions[i]=width;at+=5;if(kinds[i]>12)return false;if(flags[i]&0x20){if(!sxmx_row(v,ls[kinds[i]],at,row))return false;at+=sizes[kinds[i]];}if(flags[i]&0x40)width+=sizes[kinds[i]];}if(width!=stride||!sxmx_need(v,row,(uint64_t)rows*stride,strings))return false;for(uint32_t j=0;j<rows;j++)for(uint32_t i=0;i<n;i++)if((flags[i]&0x40)&&!sxmx_row(v,ls[kinds[i]],row+(size_t)j*stride+positions[i],strings))return false;return true;}
static bool sxmx_iqm(sxmx_view*v)
{if(!SM_ROW(iqm_header,0,v->n))return false;uint32_t meshes=sxmx_u32(v->p+36,false),arrays=sxmx_u32(v->p+44,false),verts=sxmx_u32(v->p+48,false),tris=sxmx_u32(v->p+56,false);size_t ao=sxmx_u32(v->p+52,false);if(arrays>7||verts>65536||!sxmx_table(v,&sxmx_iqm_mesh,sxmx_u32(v->p+40,false),meshes,v->n)||!sxmx_table(v,&sxmx_iqm_vertex_array,ao,arrays,v->n)||!sxmx_table(v,&sxmx_iqm_triangle,sxmx_u32(v->p+60,false),tris,v->n))return false;size_t adj=sxmx_u32(v->p+64,false);if(adj&&!sxmx_table(v,&sxmx_iqm_adjacency,adj,tris,v->n))return false;for(uint32_t i=0;i<arrays;i++){const uint8_t*p=v->p+ao+(size_t)i*20;uint32_t fmt=sxmx_u32(p+8,false),components=sxmx_u32(p+12,false);size_t at=sxmx_u32(p+16,false);if(components>4)return false;if(fmt==7){if(!sxmx_table(v,&sxmx_iqm_float,at,(uint64_t)verts*components,v->n))return false;}else if(fmt==1&&components==4){if(!sxmx_table(v,&sxmx_iqm_color,at,verts,v->n))return false;}}return true;}
static bool sxmx_psx(sxmx_view*v)
{size_t at=0;while(at<v->n){if(!SM_ROW(psx_chunk,at,v->n))return false;const uint8_t*p=v->p+at;uint32_t size=sxmx_u32(p+24,false),n=sxmx_u32(p+28,false);const sx_layout*l=NULL;if(!xx_rt_memcmp(p,"PNTS0000",8))l=&sxmx_psk_point;else if(!xx_rt_memcmp(p,"VTXW0000",8))l=&sxmx_psk_wedge;else if(!xx_rt_memcmp(p,"FACE0000",8))l=&sxmx_psk_face;else if(!xx_rt_memcmp(p,"MATT0000",8))l=&sxmx_psk_material;else if(!xx_rt_memcmp(p,"REFSKELT",8)||!xx_rt_memcmp(p,"BONENAMES",9))l=&sxmx_psx_bone;else if(!xx_rt_memcmp(p,"RAWWEIGHTS",10))l=&sxmx_psk_weight;else if(!xx_rt_memcmp(p,"ANIMINFO",8))l=&sxmx_psa_sequence;else if(!xx_rt_memcmp(p,"ANIMKEYS",8))l=&sxmx_psa_key;at+=32;if(!sxmx_need(v,at,(uint64_t)n*size,v->n))return false;if(l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;if((uint64_t)(f->rel_offset+f->size)!=size||!sxmx_table(v,l,at,n,v->n))return false;}at+=(size_t)n*size;}return true;}

static bool sx_mediaextra_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_LUCAS_LAB:
case XX_FILE_TYPE_LUCAS_BUN:
case XX_FILE_TYPE_MOHAWK_MHK:
case XX_FILE_TYPE_NINTENDO_BRRES:
case XX_FILE_TYPE_TERMINALREALITY_POD:
case XX_FILE_TYPE_VOLITION_VPP:
case XX_FILE_TYPE_MYTHIC_MYP:
case XX_FILE_TYPE_LITHTECH_REZ:
case XX_FILE_TYPE_VALVE_HPAK:
case XX_FILE_TYPE_UNREAL_PACKAGE:
case XX_FILE_TYPE_NINTENDO_BFRES:
case XX_FILE_TYPE_NINTENDO_BFLYT:
case XX_FILE_TYPE_NINTENDO_BCLYT:
case XX_FILE_TYPE_RELIC_SGA:
case XX_FILE_TYPE_UNITY_SERIALIZED:
case XX_FILE_TYPE_NINTENDO_CGFX:
case XX_FILE_TYPE_NINTENDO_BYAML:
case XX_FILE_TYPE_RELIC_CHUNKY:
case XX_FILE_TYPE_NINTENDO_J3D_BMD:
case XX_FILE_TYPE_NINTENDO_J3D_BTK:
case XX_FILE_TYPE_NINTENDO_BRLYT:
case XX_FILE_TYPE_NINTENDO_BRLAN:
case XX_FILE_TYPE_NINTENDO_BFSHA:
case XX_FILE_TYPE_CRI_UTF:
case XX_FILE_TYPE_IDTECH_IQM:
case XX_FILE_TYPE_UNREAL_PSK:
case XX_FILE_TYPE_UNREAL_PSA:
return true;default:return false;}}
static bool sx_mediaextra_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>134217728)return false;sxmx_view view={c,NULL,(size_t)c->size,0},*v=&view;v->p=(uint8_t*)xx_mem_alloc(v->n);if(!v->p||!sx_read(c,0,v->p,v->n)){xx_mem_free(v->p);return false;}bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_LUCAS_LAB:ok=sxmx_lab(v);break;
case XX_FILE_TYPE_LUCAS_BUN:ok=sxmx_bun(v);break;
case XX_FILE_TYPE_MOHAWK_MHK:ok=sxmx_mhk(v);break;
case XX_FILE_TYPE_NINTENDO_BRRES:ok=sxmx_brres(v);break;
case XX_FILE_TYPE_TERMINALREALITY_POD:ok=sxmx_pod(v);break;
case XX_FILE_TYPE_VOLITION_VPP:ok=sxmx_vpp(v);break;
case XX_FILE_TYPE_MYTHIC_MYP:ok=sxmx_myp(v);break;
case XX_FILE_TYPE_LITHTECH_REZ:ok=sxmx_rez(v);break;
case XX_FILE_TYPE_VALVE_HPAK:ok=sxmx_hpak(v);break;
case XX_FILE_TYPE_UNREAL_PACKAGE:ok=sxmx_ue1(v);break;
case XX_FILE_TYPE_NINTENDO_BFRES:ok=sxmx_bfres(v);break;
case XX_FILE_TYPE_NINTENDO_BFLYT:ok=sxmx_nw(v);break;
case XX_FILE_TYPE_NINTENDO_BCLYT:ok=sxmx_nw(v);break;
case XX_FILE_TYPE_RELIC_SGA:ok=sxmx_sga(v);break;
case XX_FILE_TYPE_UNITY_SERIALIZED:ok=sxmx_unity(v);break;
case XX_FILE_TYPE_NINTENDO_CGFX:ok=sxmx_cgfx(v);break;
case XX_FILE_TYPE_NINTENDO_BYAML:ok=sxmx_byaml(v);break;
case XX_FILE_TYPE_RELIC_CHUNKY:ok=sxmx_chunky(v);break;
case XX_FILE_TYPE_NINTENDO_J3D_BMD:ok=sxmx_j3d(v);break;
case XX_FILE_TYPE_NINTENDO_J3D_BTK:ok=sxmx_btk(v);break;
case XX_FILE_TYPE_NINTENDO_BRLYT:ok=sxmx_nw(v);break;
case XX_FILE_TYPE_NINTENDO_BRLAN:ok=sxmx_brlan(v);break;
case XX_FILE_TYPE_NINTENDO_BFSHA:ok=sxmx_fsha(v);break;
case XX_FILE_TYPE_CRI_UTF:ok=sxmx_utf(v);break;
case XX_FILE_TYPE_IDTECH_IQM:ok=sxmx_iqm(v);break;
case XX_FILE_TYPE_UNREAL_PSK:ok=sxmx_psx(v);break;
case XX_FILE_TYPE_UNREAL_PSA:ok=sxmx_psx(v);break;
default:break;}
 xx_mem_free(v->p);return ok&&sxmx_finish(c);}
#undef SM_ROW
static bool sx_mediaextra_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x602e0000)||id>=UINT32_C(0x602f0000))return true;
 if(id==1613627408u&&!xx_rt_wcscmp(r->name,L"action")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"ADD");
 case 1u:return xx_data_struct_record_set_comment(r,L"REMOVE");
 case 2u:return xx_data_struct_record_set_comment(r,L"CHANGE");
 default:break;}}
 if(id==1613627415u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"ZLIB");
 default:break;}}
 if(id==1613627417u&&!xx_rt_wcscmp(r->name,L"kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"DIRECTORY");
 default:break;}}
 if(id==1613627418u&&!xx_rt_wcscmp(r->name,L"kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"RESOURCE");
 default:break;}}
 if(id==1613627422u&&!xx_rt_wcscmp(r->name,L"resource_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SOUND");
 case 1u:return xx_data_struct_record_set_comment(r,L"SKIN");
 case 2u:return xx_data_struct_record_set_comment(r,L"MODEL");
 case 3u:return xx_data_struct_record_set_comment(r,L"DECAL");
 case 4u:return xx_data_struct_record_set_comment(r,L"GENERIC");
 case 5u:return xx_data_struct_record_set_comment(r,L"EVENTSCRIPT");
 case 6u:return xx_data_struct_record_set_comment(r,L"WORLD");
 default:break;}}
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"byte_order")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"LITTLE_ENDIAN");
 case 1u:return xx_data_struct_record_set_comment(r,L"BIG_ENDIAN");
 default:break;}}
 if(id==1613627462u&&!xx_rt_wcscmp(r->name,L"curve_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"HERMITE");
 default:break;}}
 if(id==1613627462u&&!xx_rt_wcscmp(r->name,L"channel")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"TRANSLATION_X");
 case 1u:return xx_data_struct_record_set_comment(r,L"TRANSLATION_Y");
 case 2u:return xx_data_struct_record_set_comment(r,L"TRANSLATION_Z");
 case 3u:return xx_data_struct_record_set_comment(r,L"ROTATION_X");
 case 4u:return xx_data_struct_record_set_comment(r,L"ROTATION_Y");
 case 5u:return xx_data_struct_record_set_comment(r,L"ROTATION_Z");
 case 6u:return xx_data_struct_record_set_comment(r,L"SCALE_X");
 case 7u:return xx_data_struct_record_set_comment(r,L"SCALE_Y");
 case 8u:return xx_data_struct_record_set_comment(r,L"WIDTH");
 case 9u:return xx_data_struct_record_set_comment(r,L"HEIGHT");
 default:break;}}
 if(id==1613627487u&&!xx_rt_wcscmp(r->name,L"kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP");
 case 194u:return xx_data_struct_record_set_comment(r,L"STRING_TABLE");
 default:break;}}
 if(id==1613627489u&&!xx_rt_wcscmp(r->name,L"value_kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 160u:return xx_data_struct_record_set_comment(r,L"STRING_INDEX");
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY_OFFSET");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP_OFFSET");
 case 208u:return xx_data_struct_record_set_comment(r,L"BOOLEAN");
 case 209u:return xx_data_struct_record_set_comment(r,L"INT32");
 case 210u:return xx_data_struct_record_set_comment(r,L"FLOAT32");
 case 211u:return xx_data_struct_record_set_comment(r,L"UINT32");
 case 255u:return xx_data_struct_record_set_comment(r,L"NULL");
 default:break;}}
 if(id==1613627490u&&!xx_rt_wcscmp(r->name,L"value_kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 160u:return xx_data_struct_record_set_comment(r,L"STRING_INDEX");
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY_OFFSET");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP_OFFSET");
 case 208u:return xx_data_struct_record_set_comment(r,L"BOOLEAN");
 case 209u:return xx_data_struct_record_set_comment(r,L"INT32");
 case 210u:return xx_data_struct_record_set_comment(r,L"FLOAT32");
 case 211u:return xx_data_struct_record_set_comment(r,L"UINT32");
 case 255u:return xx_data_struct_record_set_comment(r,L"NULL");
 default:break;}}
 if(id==1613627492u&&!xx_rt_wcscmp(r->name,L"value")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"FALSE");
 case 1u:return xx_data_struct_record_set_comment(r,L"TRUE");
 default:break;}}
 if(id==1613627499u&&!xx_rt_wcscmp(r->name,L"kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP");
 case 194u:return xx_data_struct_record_set_comment(r,L"STRING_TABLE");
 default:break;}}
 if(id==1613627501u&&!xx_rt_wcscmp(r->name,L"value_kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 160u:return xx_data_struct_record_set_comment(r,L"STRING_INDEX");
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY_OFFSET");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP_OFFSET");
 case 208u:return xx_data_struct_record_set_comment(r,L"BOOLEAN");
 case 209u:return xx_data_struct_record_set_comment(r,L"INT32");
 case 210u:return xx_data_struct_record_set_comment(r,L"FLOAT32");
 case 211u:return xx_data_struct_record_set_comment(r,L"UINT32");
 case 255u:return xx_data_struct_record_set_comment(r,L"NULL");
 default:break;}}
 if(id==1613627502u&&!xx_rt_wcscmp(r->name,L"value_kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 160u:return xx_data_struct_record_set_comment(r,L"STRING_INDEX");
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY_OFFSET");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP_OFFSET");
 case 208u:return xx_data_struct_record_set_comment(r,L"BOOLEAN");
 case 209u:return xx_data_struct_record_set_comment(r,L"INT32");
 case 210u:return xx_data_struct_record_set_comment(r,L"FLOAT32");
 case 211u:return xx_data_struct_record_set_comment(r,L"UINT32");
 case 255u:return xx_data_struct_record_set_comment(r,L"NULL");
 default:break;}}
 if(id==1613627504u&&!xx_rt_wcscmp(r->name,L"value")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"FALSE");
 case 1u:return xx_data_struct_record_set_comment(r,L"TRUE");
 default:break;}}
 if(id==1613627452u&&!xx_rt_wcscmp(r->name,L"scale_tangent_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SINGLE_TANGENT");
 case 1u:return xx_data_struct_record_set_comment(r,L"IN_OUT_TANGENTS");
 default:break;}}
 if(id==1613627452u&&!xx_rt_wcscmp(r->name,L"rotation_tangent_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SINGLE_TANGENT");
 case 1u:return xx_data_struct_record_set_comment(r,L"IN_OUT_TANGENTS");
 default:break;}}
 if(id==1613627452u&&!xx_rt_wcscmp(r->name,L"translation_tangent_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SINGLE_TANGENT");
 case 1u:return xx_data_struct_record_set_comment(r,L"IN_OUT_TANGENTS");
 default:break;}}
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"loop_mode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"ONCE");
 case 1u:return xx_data_struct_record_set_comment(r,L"ONCE_RESET");
 case 2u:return xx_data_struct_record_set_comment(r,L"REPEAT");
 case 3u:return xx_data_struct_record_set_comment(r,L"MIRRORED_ONCE");
 case 4u:return xx_data_struct_record_set_comment(r,L"MIRRORED_REPEAT");
 default:break;}}
 if(id==1613627533u&&!xx_rt_wcscmp(r->name,L"type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"POSITION");
 case 1u:return xx_data_struct_record_set_comment(r,L"TEXCOORD");
 case 2u:return xx_data_struct_record_set_comment(r,L"NORMAL");
 case 3u:return xx_data_struct_record_set_comment(r,L"TANGENT");
 case 4u:return xx_data_struct_record_set_comment(r,L"BLEND_INDICES");
 case 5u:return xx_data_struct_record_set_comment(r,L"BLEND_WEIGHTS");
 case 6u:return xx_data_struct_record_set_comment(r,L"COLOR");
 default:break;}}
 if(id==1613627533u&&!xx_rt_wcscmp(r->name,L"format")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"BYTE");
 case 1u:return xx_data_struct_record_set_comment(r,L"UBYTE");
 case 2u:return xx_data_struct_record_set_comment(r,L"SHORT");
 case 3u:return xx_data_struct_record_set_comment(r,L"USHORT");
 case 4u:return xx_data_struct_record_set_comment(r,L"INT");
 case 5u:return xx_data_struct_record_set_comment(r,L"UINT");
 case 6u:return xx_data_struct_record_set_comment(r,L"HALF");
 case 7u:return xx_data_struct_record_set_comment(r,L"FLOAT");
 case 8u:return xx_data_struct_record_set_comment(r,L"DOUBLE");
 default:break;}}
 if(id==1613627394u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name table after all directory entries.");
 if(id==1613627394u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627394u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627395u&&!xx_rt_wcscmp(r->name,L"table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627396u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627397u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627398u&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627398u&&!xx_rt_wcscmp(r->name,L"file_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource directory indicated by directory_offset.");
 if(id==1613627399u&&!xx_rt_wcscmp(r->name,L"string_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource directory indicated by directory_offset.");
 if(id==1613627400u&&!xx_rt_wcscmp(r->name,L"resource_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource directory indicated by directory_offset.");
 if(id==1613627400u&&!xx_rt_wcscmp(r->name,L"name_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource directory indicated by directory_offset.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627405u&&!xx_rt_wcscmp(r->name,L"string_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource string table, itself relative to the resource directory.");
 if(id==1613627407u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name table immediately following the fixed file-entry array.");
 if(id==1613627407u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627407u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627408u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627408u&&!xx_rt_wcscmp(r->name,L"old_timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627408u&&!xx_rt_wcscmp(r->name,L"new_timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"unknown_150"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"directory_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"names_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"data_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the aligned name table.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"runtime_offset"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the aligned data region after directory and names.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"package_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"unknown_150"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"directory_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"names_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"data_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the aligned name table.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"runtime_offset"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the aligned data region after directory and names.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"package_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627413u&&!xx_rt_wcscmp(r->name,L"first_block_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627414u&&!xx_rt_wcscmp(r->name,L"next_block_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627415u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627416u&&!xx_rt_wcscmp(r->name,L"root_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627416u&&!xx_rt_wcscmp(r->name,L"root_time"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627416u&&!xx_rt_wcscmp(r->name,L"directory_boundary"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627416u&&!xx_rt_wcscmp(r->name,L"unknown_limits"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627417u&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627417u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627418u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627418u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627420u&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627422u&&!xx_rt_wcscmp(r->name,L"next_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627422u&&!xx_rt_wcscmp(r->name,L"previous_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627422u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627423u&&!xx_rt_wcscmp(r->name,L"root_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627426u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627426u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the containing resource dictionary, not the pointer word.");
 if(id==1613627426u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the containing resource dictionary, not the pointer word.");
 if(id==1613627427u&&!xx_rt_wcscmp(r->name,L"archive_relative"))return xx_data_struct_record_set_comment(r,L"Signed displacement relative to this resource-section beginning; points back to BRRES header.");
 if(id==1613627434u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement from the beginning of the name-offset table (section byte 12).");
 if(id==1613627441u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement from the beginning of the name-offset table (section byte 12).");
 if(id==1613627445u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement from the beginning of the name-entry table (section byte 12).");
 if(id==1613627448u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627449u&&!xx_rt_wcscmp(r->name,L"unknown1"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627449u&&!xx_rt_wcscmp(r->name,L"unknown2"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627450u&&!xx_rt_wcscmp(r->name,L"opaque_creator"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"animation_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"remap_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"name_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"texture_matrix_index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"center_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"scale_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"rotation_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"translation_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627458u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the string-table header, not this entry.");
 if(id==1613627459u&&!xx_rt_wcscmp(r->name,L"binding_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the pai1 section beginning.");
 if(id==1613627460u&&!xx_rt_wcscmp(r->name,L"group_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to this binding record beginning.");
 if(id==1613627462u&&!xx_rt_wcscmp(r->name,L"keys_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to this track record beginning.");
 if(id==1613627464u&&!xx_rt_wcscmp(r->name,L"relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to the owning pai1 section or animation group, according to the enclosing table.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"string_pool_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"model_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"texture_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"skeletal_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"shader_parameter_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"color_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"texture_srt_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"texture_pattern_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"bone_visibility_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"material_visibility_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"shape_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"scene_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"external_file_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"user_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627467u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627467u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627468u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627469u&&!xx_rt_wcscmp(r->name,L"dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627471u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627471u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"legacy_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627476u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to data_offset in the file header.");
 if(id==1613627478u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to null-terminated name strings followed by 32-bit flags.");
 if(id==1613627478u&&!xx_rt_wcscmp(r->name,L"export_offset"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to variable CompactIndex export records; record bodies remain raw.");
 if(id==1613627478u&&!xx_rt_wcscmp(r->name,L"import_offset"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to variable CompactIndex import records; record bodies remain raw.");
 if(id==1613627478u&&!xx_rt_wcscmp(r->name,L"heritage_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627481u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627482u&&!xx_rt_wcscmp(r->name,L"table_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the table region at file byte 152.");
 if(id==1613627483u&&!xx_rt_wcscmp(r->name,L"first_folder"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627483u&&!xx_rt_wcscmp(r->name,L"end_folder"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627483u&&!xx_rt_wcscmp(r->name,L"first_file"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627483u&&!xx_rt_wcscmp(r->name,L"end_file"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name table identified by the fourth table slot.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"first_folder"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"end_folder"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"first_file"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"end_file"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627485u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name table identified by the fourth table slot.");
 if(id==1613627485u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to the data region selected in the archive header.");
 if(id==1613627485u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627486u&&!xx_rt_wcscmp(r->name,L"key_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627486u&&!xx_rt_wcscmp(r->name,L"string_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627486u&&!xx_rt_wcscmp(r->name,L"root_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627488u&&!xx_rt_wcscmp(r->name,L"string_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this string/key table beginning; final entry is the end offset.");
 if(id==1613627496u&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to a nested map or array.");
 if(id==1613627498u&&!xx_rt_wcscmp(r->name,L"key_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627498u&&!xx_rt_wcscmp(r->name,L"string_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627498u&&!xx_rt_wcscmp(r->name,L"root_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627500u&&!xx_rt_wcscmp(r->name,L"string_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this string/key table beginning; final entry is the end offset.");
 if(id==1613627508u&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to a nested map or array.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"string_pool_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"path_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"unknown_26"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"unknown_28"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"model_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"unknown_30"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"unknown_34"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"opaque_0"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"opaque_8"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"opaque_24"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"programs_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"unknown_5c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"archive_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"unknown_64"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"opaque_0"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"vertex_shader_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"geometry_shader_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"pixel_shader_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"model_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627514u&&!xx_rt_wcscmp(r->name,L"code_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627514u&&!xx_rt_wcscmp(r->name,L"unused_native_metadata"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627515u&&!xx_rt_wcscmp(r->name,L"code_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627515u&&!xx_rt_wcscmp(r->name,L"unused_native_metadata"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"rows_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to file byte 8, immediately after the @UTF prefix.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"strings_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to file byte 8, immediately after the @UTF prefix.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to file byte 8, immediately after the @UTF prefix.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"table_name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool.");
 if(id==1613627517u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool.");
 if(id==1613627528u&&!xx_rt_wcscmp(r->name,L"string_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool.");
 if(id==1613627529u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF binary-data region.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"text_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"mesh_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"vertex_array_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"triangle_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"adjacency_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"joint_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"pose_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"animation_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"frame_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"bounds_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"comment_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"extension_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627532u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the IQM text table.");
 if(id==1613627532u&&!xx_rt_wcscmp(r->name,L"material_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the IQM text table.");
 if(id==1613627532u&&!xx_rt_wcscmp(r->name,L"first_vertex"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627532u&&!xx_rt_wcscmp(r->name,L"first_triangle"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627533u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627545u&&!xx_rt_wcscmp(r->name,L"first_frame"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"size_low16"))return xx_data_struct_record_set_comment(r,L"Bits 0..15 of the encoded 27-bit file byte length.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"size_high8"))return xx_data_struct_record_set_comment(r,L"Bits 16..23 of the encoded file byte length.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"size_high3_and_flags"))return xx_data_struct_record_set_comment(r,L"Low 3 bits provide byte-length bits 24..26; high 5 bits are flags.");
 if(id==1613627404u&&!xx_rt_wcscmp(r->name,L"file_index"))return xx_data_struct_record_set_comment(r,L"One-based index in the file table.");
 if(id==1613627405u&&!xx_rt_wcscmp(r->name,L"file_index"))return xx_data_struct_record_set_comment(r,L"One-based index in the file table.");
 if(id==1613627406u&&!xx_rt_wcscmp(r->name,L"checksum"))return xx_data_struct_record_set_comment(r,L"CRC-32/MPEG-2 of source bytes after the first 8 bytes. Native validation checks it.");
 if(id==1613627407u&&!xx_rt_wcscmp(r->name,L"checksum"))return xx_data_struct_record_set_comment(r,L"CRC-32/MPEG-2 of this member payload. Native validation checks it.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"compressed_size"))return xx_data_struct_record_set_comment(r,L"Stored compressed byte count; 0xFFFFFFFF is the uncompressed sentinel.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"compressed_size"))return xx_data_struct_record_set_comment(r,L"Stored compressed byte count; 0xFFFFFFFF is the uncompressed sentinel.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"compressed_size"))return xx_data_struct_record_set_comment(r,L"Stored compressed byte count; 0xFFFFFFFF is the uncompressed sentinel.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"compressed_size"))return xx_data_struct_record_set_comment(r,L"Stored compressed byte count; 0xFFFFFFFF is the uncompressed sentinel.");
 if(id==1613627430u&&!xx_rt_wcscmp(r->name,L"section_size"))return xx_data_struct_record_set_comment(r,L"Total section bytes including its 8-byte prefix.");
 if(id==1613627437u&&!xx_rt_wcscmp(r->name,L"section_size"))return xx_data_struct_record_set_comment(r,L"Total section bytes including its 8-byte prefix.");
 if(id==1613627431u&&!xx_rt_wcscmp(r->name,L"width"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627431u&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627432u&&!xx_rt_wcscmp(r->name,L"width"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627432u&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627438u&&!xx_rt_wcscmp(r->name,L"width"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627438u&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627439u&&!xx_rt_wcscmp(r->name,L"width"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627439u&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627449u&&!xx_rt_wcscmp(r->name,L"data_size"))return xx_data_struct_record_set_comment(r,L"Payload bytes following the variable-length chunk name; excludes fixed header and name.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"animation_count"))return xx_data_struct_record_set_comment(r,L"Number of axis animation records; three axis records form one texture-matrix animation.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"angle_scale"))return xx_data_struct_record_set_comment(r,L"Rotation-angle conversion uses this power-of-two scale; not a byte count.");
 if(id==1613627456u&&!xx_rt_wcscmp(r->name,L"angle_units"))return xx_data_struct_record_set_comment(r,L"Signed encoded rotation value; angle scale is in the containing TTK1 header.");
 if(id==1613627463u&&!xx_rt_wcscmp(r->name,L"frame"))return xx_data_struct_record_set_comment(r,L"Animation-frame position; not a wall-clock timestamp.");
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"byte_order"))return xx_data_struct_record_set_comment(r,L"Metadata byte order: 0 little endian, 1 big endian. Extended header fields remain big endian.");
 if(id==1613627474u&&!xx_rt_wcscmp(r->name,L"script_type_index"))return xx_data_struct_record_set_comment(r,L"Signed script-type index; -1 means no script type.");
 if(id==1613627481u&&!xx_rt_wcscmp(r->name,L"archive_name_utf16le"))return xx_data_struct_record_set_comment(r,L"64 UTF-16LE code units; kept as source bytes without a guessed locale.");
 if(id==1613627491u&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"Zero-based index in the string-value table.");
 if(id==1613627503u&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"Zero-based index in the string-value table.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"table_size_after_prefix"))return xx_data_struct_record_set_comment(r,L"Total table length minus the first 8 bytes.");
 if(id==1613627517u&&!xx_rt_wcscmp(r->name,L"storage_and_type"))return xx_data_struct_record_set_comment(r,L"Low nibble: scalar type (0..12); 0x10 name present, 0x20 default value stored, 0x40 value stored in every row.");
 if(id==1613627533u&&!xx_rt_wcscmp(r->name,L"components"))return xx_data_struct_record_set_comment(r,L"Number of components per vertex; multiply by element width to obtain the byte stride.");
 if(id==1613627536u&&!xx_rt_wcscmp(r->name,L"component"))return xx_data_struct_record_set_comment(r,L"IEEE754 vertex-array component. Array type determines position, UV, normal or tangent units.");
 if(id==1613627546u&&!xx_rt_wcscmp(r->name,L"time"))return xx_data_struct_record_set_comment(r,L"Animation time/duration scalar in ActorX units; not a Unix timestamp.");
 if(id==1613627545u&&!xx_rt_wcscmp(r->name,L"track_time"))return xx_data_struct_record_set_comment(r,L"Animation-track duration scalar; not a wall-clock timestamp.");
 if(id==1613627545u&&!xx_rt_wcscmp(r->name,L"frames_per_second"))return xx_data_struct_record_set_comment(r,L"Animation frame rate in frames per second.");
 if(id==1613627539u&&!xx_rt_wcscmp(r->name,L"parent_index"))return xx_data_struct_record_set_comment(r,L"Signed parent-bone index; native root permits 0 or -1.");
 return true;
}
