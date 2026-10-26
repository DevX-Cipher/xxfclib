/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical game archive and index metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxga_filename_byte_fields[]={
 SX_FIELD("byte","char[1]",0,1,SX_STRING),
};
static const sx_layout sxga_filename_byte={UINT32_C(0x603B0001),"filename_byte",sxga_filename_byte_fields,SX_COUNT(sxga_filename_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxga_encoded_name_byte_fields[]={
 SX_FIELD("byte","bytes",0,1,SX_NONE),
};
static const sx_layout sxga_encoded_name_byte={UINT32_C(0x603B0002),"encoded_name_byte",sxga_encoded_name_byte_fields,SX_COUNT(sxga_encoded_name_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxga_name_length8_fields[]={
 SX_FIELD("name_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxga_name_length8={UINT32_C(0x603B0003),"name_length8",sxga_name_length8_fields,SX_COUNT(sxga_name_length8_fields),SX_LE};
static const xx_data_struct_field_desc sxga_name_length32_fields[]={
 SX_FIELD("name_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxga_name_length32={UINT32_C(0x603B0004),"name_length32",sxga_name_length32_fields,SX_COUNT(sxga_name_length32_fields),SX_LE};
static const xx_data_struct_field_desc sxga_count16_fields[]={
 SX_FIELD("entries","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxga_count16={UINT32_C(0x603B0005),"count16",sxga_count16_fields,SX_COUNT(sxga_count16_fields),SX_LE};
static const xx_data_struct_field_desc sxga_count32_fields[]={
 SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxga_count32={UINT32_C(0x603B0006),"count32",sxga_count32_fields,SX_COUNT(sxga_count32_fields),SX_LE};
static const xx_data_struct_field_desc sxga_offset32_fields[]={
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxga_offset32={UINT32_C(0x603B0007),"offset32",sxga_offset32_fields,SX_COUNT(sxga_offset32_fields),SX_LE};
static const xx_data_struct_field_desc sxga_length16_fields[]={
 SX_FIELD("data_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxga_length16={UINT32_C(0x603B0008),"length16",sxga_length16_fields,SX_COUNT(sxga_length16_fields),SX_LE};
static const xx_data_struct_field_desc sxga_hog2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("reserved","bytes",12,56,SX_RESERVED),
};
static const sx_layout sxga_hog2_header={UINT32_C(0x603B0009),"hog2_header",sxga_hog2_header_fields,SX_COUNT(sxga_hog2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_hog2_entry_fields[]={
 SX_FIELD("name","char[36]",0,36,SX_STRING),
 SX_FIELD("flags","uint32",36,4,SX_FLAGS),
 SX_FIELD("data_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("modified","uint32",44,4,SX_TIME),
};
static const sx_layout sxga_hog2_entry={UINT32_C(0x603B000A),"hog2_entry",sxga_hog2_entry_fields,SX_COUNT(sxga_hog2_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_vp_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("index_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("entries","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxga_vp_header={UINT32_C(0x603B000B),"vp_header",sxga_vp_header_fields,SX_COUNT(sxga_vp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_vp_entry_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("name","char[32]",8,32,SX_STRING),
 SX_FIELD("modified","uint32",40,4,SX_TIME),
};
static const sx_layout sxga_vp_entry={UINT32_C(0x603B000C),"vp_entry",sxga_vp_entry_fields,SX_COUNT(sxga_vp_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_cat_entry_fields[]={
 SX_FIELD("name","char[12]",0,12,SX_STRING),
 SX_FIELD("dos_timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("data_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxga_cat_entry={UINT32_C(0x603B000D),"cat_entry",sxga_cat_entry_fields,SX_COUNT(sxga_cat_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_teacy_entry_fields[]={
 SX_FIELD("reserved","bytes",0,3,SX_RESERVED),
 SX_FIELD("name","char[13]",3,13,SX_STRING),
 SX_FIELD("data_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxga_teacy_entry={UINT32_C(0x603B000E),"teacy_entry",sxga_teacy_entry_fields,SX_COUNT(sxga_teacy_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_settlers_header_fields[]={
 SX_FIELD("file_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("slots","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxga_settlers_header={UINT32_C(0x603B000F),"settlers_header",sxga_settlers_header_fields,SX_COUNT(sxga_settlers_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_settlers_slot_fields[]={
 SX_FIELD("data_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxga_settlers_slot={UINT32_C(0x603B0010),"settlers_slot",sxga_settlers_slot_fields,SX_COUNT(sxga_settlers_slot_fields),SX_LE};
static const xx_data_struct_field_desc sxga_wolf_header_fields[]={
 SX_FIELD("chunks","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("first_sprite","uint16",2,2,SX_ID),
 SX_FIELD("first_sound","uint16",4,2,SX_ID),
};
static const sx_layout sxga_wolf_header={UINT32_C(0x603B0011),"wolf_header",sxga_wolf_header_fields,SX_COUNT(sxga_wolf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ea_entry_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("magic","char[2]",1,2,SX_SIGNATURE),
 SX_FIELD("name","char[12]",3,12,SX_STRING),
 SX_FIELD("name_terminator","uint8",15,1,SX_RESERVED),
 SX_FIELD("stamp","uint32",16,4,SX_NONE),
 SX_FIELD("method","uint8",20,1,SX_ID),
 SX_FIELD("decoded_bytes","int32",21,4,SX_SIZE),
 SX_FIELD("packed_bytes","int32",25,4,SX_SIZE),
 SX_FIELD("format_tag","uint32",29,4,SX_ID),
 SX_FIELD("reserved","bytes",33,15,SX_RESERVED),
};
static const sx_layout sxga_ea_entry={UINT32_C(0x603B0012),"ea_entry",sxga_ea_entry_fields,SX_COUNT(sxga_ea_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_agis_entry_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("method","uint8",5,1,SX_ID),
 SX_FIELD("crc32","uint32",6,4,SX_CHECKSUM),
 SX_FIELD("decoded_bytes","uint32",10,4,SX_SIZE),
 SX_FIELD("record_bytes","uint32",14,4,SX_SIZE),
 SX_FIELD("name_bytes","uint8",18,1,SX_SIZE),
 SX_FIELD("name","char[12]",19,12,SX_STRING),
};
static const sx_layout sxga_agis_entry={UINT32_C(0x603B0013),"agis_entry",sxga_agis_entry_fields,SX_COUNT(sxga_agis_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_epf_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
 SX_FIELD("entries","uint16",9,2,SX_COUNT_PROP),
};
static const sx_layout sxga_epf_header={UINT32_C(0x603B0014),"epf_header",sxga_epf_header_fields,SX_COUNT(sxga_epf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_epf_entry_fields[]={
 SX_FIELD("name","char[13]",0,13,SX_STRING),
 SX_FIELD("method","uint8",13,1,SX_ID),
 SX_FIELD("packed_bytes","uint32",14,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",18,4,SX_SIZE),
};
static const sx_layout sxga_epf_entry={UINT32_C(0x603B0015),"epf_entry",sxga_epf_entry_fields,SX_COUNT(sxga_epf_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ppd_entry_fields[]={
 SX_FIELD("decoded_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("unknown","bytes",8,4,SX_NONE),
};
static const sx_layout sxga_ppd_entry={UINT32_C(0x603B0016),"ppd_entry",sxga_ppd_entry_fields,SX_COUNT(sxga_ppd_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_wux_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("signature","uint32",4,4,SX_SIGNATURE),
 SX_FIELD("block_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("alignment12","bytes",12,4,SX_NONE),
 SX_FIELD("decoded_bytes","uint64",16,8,SX_SIZE),
 SX_FIELD("flags","uint32",24,4,SX_FLAGS),
 SX_FIELD("alignment28","bytes",28,4,SX_NONE),
};
static const sx_layout sxga_wux_header={UINT32_C(0x603B0017),"wux_header",sxga_wux_header_fields,SX_COUNT(sxga_wux_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_wux_block_fields[]={
 SX_FIELD("stored_block_index","uint32",0,4,SX_ID),
};
static const sx_layout sxga_wux_block={UINT32_C(0x603B0018),"wux_block",sxga_wux_block_fields,SX_COUNT(sxga_wux_block_fields),SX_LE};
static const xx_data_struct_field_desc sxga_refpack_header24_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("decoded_bytes","uint24",2,3,SX_SIZE),
};
static const sx_layout sxga_refpack_header24={UINT32_C(0x603B0019),"refpack_header24",sxga_refpack_header24_fields,SX_COUNT(sxga_refpack_header24_fields),SX_BE};
static const xx_data_struct_field_desc sxga_refpack_header24_packed_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("packed_bytes","uint24",2,3,SX_SIZE),
 SX_FIELD("decoded_bytes","uint24",5,3,SX_SIZE),
};
static const sx_layout sxga_refpack_header24_packed={UINT32_C(0x603B001A),"refpack_header24_packed",sxga_refpack_header24_packed_fields,SX_COUNT(sxga_refpack_header24_packed_fields),SX_BE};
static const xx_data_struct_field_desc sxga_refpack_header32_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("decoded_bytes","uint32",2,4,SX_SIZE),
};
static const sx_layout sxga_refpack_header32={UINT32_C(0x603B001B),"refpack_header32",sxga_refpack_header32_fields,SX_COUNT(sxga_refpack_header32_fields),SX_BE};
static const xx_data_struct_field_desc sxga_refpack_header32_packed_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("packed_bytes","uint32",2,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",6,4,SX_SIZE),
};
static const sx_layout sxga_refpack_header32_packed={UINT32_C(0x603B001C),"refpack_header32_packed",sxga_refpack_header32_packed_fields,SX_COUNT(sxga_refpack_header32_packed_fields),SX_BE};
static const xx_data_struct_field_desc sxga_stunts_header_fields[]={
 SX_FIELD("passes","uint8",0,1,SX_FLAGS),
 SX_FIELD("decoded_bytes","uint24",1,3,SX_SIZE),
};
static const sx_layout sxga_stunts_header={UINT32_C(0x603B001D),"stunts_header",sxga_stunts_header_fields,SX_COUNT(sxga_stunts_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_stunts_pass_fields[]={
 SX_FIELD("codec","uint8",0,1,SX_ID),
 SX_FIELD("decoded_bytes","uint24",1,3,SX_SIZE),
};
static const sx_layout sxga_stunts_pass={UINT32_C(0x603B001E),"stunts_pass",sxga_stunts_pass_fields,SX_COUNT(sxga_stunts_pass_fields),SX_LE};
static const xx_data_struct_field_desc sxga_stunts_rle_fields[]={
 SX_FIELD("source_bytes","uint24",0,3,SX_SIZE),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("escape_flags","uint8",4,1,SX_FLAGS),
};
static const sx_layout sxga_stunts_rle={UINT32_C(0x603B001F),"stunts_rle",sxga_stunts_rle_fields,SX_COUNT(sxga_stunts_rle_fields),SX_LE};
static const xx_data_struct_field_desc sxga_stunts_vle_fields[]={
 SX_FIELD("level_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxga_stunts_vle={UINT32_C(0x603B0020),"stunts_vle",sxga_stunts_vle_fields,SX_COUNT(sxga_stunts_vle_fields),SX_LE};
static const xx_data_struct_field_desc sxga_stunts_escape_fields[]={
 SX_FIELD("escape","uint8",0,1,SX_ID),
};
static const sx_layout sxga_stunts_escape={UINT32_C(0x603B0021),"stunts_escape",sxga_stunts_escape_fields,SX_COUNT(sxga_stunts_escape_fields),SX_LE};
static const xx_data_struct_field_desc sxga_stunts_level_fields[]={
 SX_FIELD("symbols","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxga_stunts_level={UINT32_C(0x603B0022),"stunts_level",sxga_stunts_level_fields,SX_COUNT(sxga_stunts_level_fields),SX_LE};
static const xx_data_struct_field_desc sxga_stunts_symbol_fields[]={
 SX_FIELD("symbol","uint8",0,1,SX_ID),
};
static const sx_layout sxga_stunts_symbol={UINT32_C(0x603B0023),"stunts_symbol",sxga_stunts_symbol_fields,SX_COUNT(sxga_stunts_symbol_fields),SX_LE};
static const xx_data_struct_field_desc sxga_silmarils_header_le_fields[]={
 SX_FIELD("decoded_bytes","uint24",0,3,SX_SIZE),
 SX_FIELD("method","uint8",3,1,SX_ID),
 SX_FIELD("not_main_script","uint16",4,2,SX_FLAGS),
};
static const sx_layout sxga_silmarils_header_le={UINT32_C(0x603B0024),"silmarils_header_le",sxga_silmarils_header_le_fields,SX_COUNT(sxga_silmarils_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxga_silmarils_header_be_fields[]={
 SX_FIELD("method","uint8",0,1,SX_ID),
 SX_FIELD("decoded_bytes","uint24",1,3,SX_SIZE),
 SX_FIELD("not_main_script","uint16",4,2,SX_FLAGS),
};
static const sx_layout sxga_silmarils_header_be={UINT32_C(0x603B0025),"silmarils_header_be",sxga_silmarils_header_be_fields,SX_COUNT(sxga_silmarils_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxga_silmarils_offset_widths_fields[]={
 SX_FIELD("width0","uint8",0,1,SX_NONE),
 SX_FIELD("width1","uint8",1,1,SX_NONE),
 SX_FIELD("width2","uint8",2,1,SX_NONE),
 SX_FIELD("width3","uint8",3,1,SX_NONE),
 SX_FIELD("width4","uint8",4,1,SX_NONE),
 SX_FIELD("width5","uint8",5,1,SX_NONE),
 SX_FIELD("width6","uint8",6,1,SX_NONE),
 SX_FIELD("width7","uint8",7,1,SX_NONE),
};
static const sx_layout sxga_silmarils_offset_widths={UINT32_C(0x603B0026),"silmarils_offset_widths",sxga_silmarils_offset_widths_fields,SX_COUNT(sxga_silmarils_offset_widths_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ns_header_fields[]={
 SX_FIELD("entries","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("data_base","uint32",2,4,SX_OFFSET),
};
static const sx_layout sxga_ns_header={UINT32_C(0x603B0027),"ns_header",sxga_ns_header_fields,SX_COUNT(sxga_ns_header_fields),SX_BE};
static const xx_data_struct_field_desc sxga_ns_zero_prefix_fields[]={
 SX_FIELD("prefix","uint16",0,2,SX_RESERVED),
};
static const sx_layout sxga_ns_zero_prefix={UINT32_C(0x603B0028),"ns_zero_prefix",sxga_ns_zero_prefix_fields,SX_COUNT(sxga_ns_zero_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxga_sar_entry_fields[]={
 SX_FIELD("relative_data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxga_sar_entry={UINT32_C(0x603B0029),"sar_entry",sxga_sar_entry_fields,SX_COUNT(sxga_sar_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxga_nsa_entry_fields[]={
 SX_FIELD("method","uint8",0,1,SX_ID),
 SX_FIELD("relative_data_offset","uint32",1,4,SX_OFFSET),
 SX_FIELD("packed_bytes","uint32",5,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",9,4,SX_SIZE),
};
static const sx_layout sxga_nsa_entry={UINT32_C(0x603B002A),"nsa_entry",sxga_nsa_entry_fields,SX_COUNT(sxga_nsa_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxga_ns2_header_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxga_ns2_header={UINT32_C(0x603B002B),"ns2_header",sxga_ns2_header_fields,SX_COUNT(sxga_ns2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ns2_size_fields[]={
 SX_FIELD("data_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxga_ns2_size={UINT32_C(0x603B002C),"ns2_size",sxga_ns2_size_fields,SX_COUNT(sxga_ns2_size_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ns2_quote_fields[]={
 SX_FIELD("quote","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxga_ns2_quote={UINT32_C(0x603B002D),"ns2_quote",sxga_ns2_quote_fields,SX_COUNT(sxga_ns2_quote_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ns2_end_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxga_ns2_end={UINT32_C(0x603B002E),"ns2_end",sxga_ns2_end_fields,SX_COUNT(sxga_ns2_end_fields),SX_LE};
static const xx_data_struct_field_desc sxga_dcp_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("package_version","uint32",8,4,SX_ID),
 SX_FIELD("game_version","uint32",12,4,SX_ID),
 SX_FIELD("priority","uint8",16,1,SX_NONE),
 SX_FIELD("cd","uint8",17,1,SX_ID),
 SX_FIELD("master_index","uint8",18,1,SX_FLAGS),
 SX_FIELD("alignment","uint8",19,1,SX_NONE),
 SX_FIELD("creation_time","uint32",20,4,SX_TIME),
 SX_FIELD("description","char[100]",24,100,SX_STRING),
 SX_FIELD("directories","uint32",124,4,SX_COUNT_PROP),
};
static const sx_layout sxga_dcp_header={UINT32_C(0x603B002F),"dcp_header",sxga_dcp_header_fields,SX_COUNT(sxga_dcp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_dcp_directory_offset_fields[]={
 SX_FIELD("directory_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxga_dcp_directory_offset={UINT32_C(0x603B0030),"dcp_directory_offset",sxga_dcp_directory_offset_fields,SX_COUNT(sxga_dcp_directory_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxga_dcp_directory_fields[]={
 SX_FIELD("cd","uint8",0,1,SX_ID),
 SX_FIELD("files","uint32",1,4,SX_COUNT_PROP),
};
static const sx_layout sxga_dcp_directory={UINT32_C(0x603B0031),"dcp_directory",sxga_dcp_directory_fields,SX_COUNT(sxga_dcp_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxga_dcp_entry1_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("decoded_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("packed_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxga_dcp_entry1={UINT32_C(0x603B0032),"dcp_entry1",sxga_dcp_entry1_fields,SX_COUNT(sxga_dcp_entry1_fields),SX_LE};
static const xx_data_struct_field_desc sxga_dcp_entry2_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("decoded_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("packed_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("timestamp_low","uint32",16,4,SX_NONE),
 SX_FIELD("timestamp_high","uint32",20,4,SX_NONE),
};
static const sx_layout sxga_dcp_entry2={UINT32_C(0x603B0033),"dcp_entry2",sxga_dcp_entry2_fields,SX_COUNT(sxga_dcp_entry2_fields),SX_LE};
static const xx_data_struct_field_desc sxga_far_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("manifest_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxga_far_header={UINT32_C(0x603B0034),"far_header",sxga_far_header_fields,SX_COUNT(sxga_far_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_far_entry16_fields[]={
 SX_FIELD("decoded_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("stored_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("name_bytes","uint16",12,2,SX_SIZE),
};
static const sx_layout sxga_far_entry16={UINT32_C(0x603B0035),"far_entry16",sxga_far_entry16_fields,SX_COUNT(sxga_far_entry16_fields),SX_LE};
static const xx_data_struct_field_desc sxga_far_entry32_fields[]={
 SX_FIELD("decoded_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("stored_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("name_bytes","uint32",12,4,SX_SIZE),
};
static const sx_layout sxga_far_entry32={UINT32_C(0x603B0036),"far_entry32",sxga_far_entry32_fields,SX_COUNT(sxga_far_entry32_fields),SX_LE};
static const xx_data_struct_field_desc sxga_xzp_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("preload_entries","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("entries","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("preload_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("header_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("name_entries","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("name_table_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("name_table_bytes","uint32",32,4,SX_SIZE),
};
static const sx_layout sxga_xzp_header={UINT32_C(0x603B0037),"xzp_header",sxga_xzp_header_fields,SX_COUNT(sxga_xzp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_xzp_entry_fields[]={
 SX_FIELD("name_crc","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("data_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxga_xzp_entry={UINT32_C(0x603B0038),"xzp_entry",sxga_xzp_entry_fields,SX_COUNT(sxga_xzp_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_xzp_mapping_fields[]={
 SX_FIELD("preload_entry","uint16",0,2,SX_ID),
};
static const sx_layout sxga_xzp_mapping={UINT32_C(0x603B0039),"xzp_mapping",sxga_xzp_mapping_fields,SX_COUNT(sxga_xzp_mapping_fields),SX_LE};
static const xx_data_struct_field_desc sxga_xzp_name_fields[]={
 SX_FIELD("name_crc","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("created","uint32",8,4,SX_TIME),
};
static const sx_layout sxga_xzp_name={UINT32_C(0x603B003A),"xzp_name",sxga_xzp_name_fields,SX_COUNT(sxga_xzp_name_fields),SX_LE};
static const xx_data_struct_field_desc sxga_xzp_footer_fields[]={
 SX_FIELD("file_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("magic","char[4]",4,4,SX_SIGNATURE),
};
static const sx_layout sxga_xzp_footer={UINT32_C(0x603B003B),"xzp_footer",sxga_xzp_footer_fields,SX_COUNT(sxga_xzp_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxga_pbo_entry_fields[]={
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("decoded_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
 SX_FIELD("modified","uint32",12,4,SX_TIME),
 SX_FIELD("data_bytes","uint32",16,4,SX_SIZE),
};
static const sx_layout sxga_pbo_entry={UINT32_C(0x603B003C),"pbo_entry",sxga_pbo_entry_fields,SX_COUNT(sxga_pbo_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_majiro_header_fields[]={
 SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("entries","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("names_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",24,4,SX_OFFSET),
};
static const sx_layout sxga_majiro_header={UINT32_C(0x603B003D),"majiro_header",sxga_majiro_header_fields,SX_COUNT(sxga_majiro_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_majiro_entry1_fields[]={
 SX_FIELD("name_hash","uint32",0,4,SX_ID),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxga_majiro_entry1={UINT32_C(0x603B003E),"majiro_entry1",sxga_majiro_entry1_fields,SX_COUNT(sxga_majiro_entry1_fields),SX_LE};
static const xx_data_struct_field_desc sxga_majiro_entry2_fields[]={
 SX_FIELD("name_hash","uint32",0,4,SX_ID),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",8,4,SX_SIZE),
};
static const sx_layout sxga_majiro_entry2={UINT32_C(0x603B003F),"majiro_entry2",sxga_majiro_entry2_fields,SX_COUNT(sxga_majiro_entry2_fields),SX_LE};
static const xx_data_struct_field_desc sxga_majiro_entry3_fields[]={
 SX_FIELD("name_hash","uint64",0,8,SX_ID),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",12,4,SX_SIZE),
};
static const sx_layout sxga_majiro_entry3={UINT32_C(0x603B0040),"majiro_entry3",sxga_majiro_entry3_fields,SX_COUNT(sxga_majiro_entry3_fields),SX_LE};
static const xx_data_struct_field_desc sxga_nexas_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("variant","uint8",3,1,SX_NONE),
 SX_FIELD("entries","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("method","uint32",8,4,SX_ID),
};
static const sx_layout sxga_nexas_header={UINT32_C(0x603B0041),"nexas_header",sxga_nexas_header_fields,SX_COUNT(sxga_nexas_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_nexas_entry32_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_STRING),
 SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("decoded_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("packed_bytes","uint32",40,4,SX_SIZE),
};
static const sx_layout sxga_nexas_entry32={UINT32_C(0x603B0042),"nexas_entry32",sxga_nexas_entry32_fields,SX_COUNT(sxga_nexas_entry32_fields),SX_LE};
static const xx_data_struct_field_desc sxga_nexas_entry64_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("data_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("decoded_bytes","uint32",68,4,SX_SIZE),
 SX_FIELD("packed_bytes","uint32",72,4,SX_SIZE),
};
static const sx_layout sxga_nexas_entry64={UINT32_C(0x603B0043),"nexas_entry64",sxga_nexas_entry64_fields,SX_COUNT(sxga_nexas_entry64_fields),SX_LE};
static const xx_data_struct_field_desc sxga_nexas_footer_fields[]={
 SX_FIELD("packed_index_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxga_nexas_footer={UINT32_C(0x603B0044),"nexas_footer",sxga_nexas_footer_fields,SX_COUNT(sxga_nexas_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_nctt_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("inner_bytes","uint64",4,8,SX_SIZE),
};
static const sx_layout sxga_tt_nctt={UINT32_C(0x603B0045),"tt_nctt",sxga_tt_nctt_fields,SX_COUNT(sxga_tt_nctt_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_chunked_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("chunk_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("chunks","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxga_tt_chunked={UINT32_C(0x603B0046),"tt_chunked",sxga_tt_chunked_fields,SX_COUNT(sxga_tt_chunked_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_chunk_offset_fields[]={
 SX_FIELD("offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxga_tt_chunk_offset={UINT32_C(0x603B0047),"tt_chunk_offset",sxga_tt_chunk_offset_fields,SX_COUNT(sxga_tt_chunk_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_header3_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
 SX_FIELD("names_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("entries","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxga_tt_header3={UINT32_C(0x603B0048),"tt_header3",sxga_tt_header3_fields,SX_COUNT(sxga_tt_header3_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_header4_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("names_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("entries","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxga_tt_header4={UINT32_C(0x603B0049),"tt_header4",sxga_tt_header4_fields,SX_COUNT(sxga_tt_header4_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_entry_fields[]={
 SX_FIELD("name_crc64","uint64",0,8,SX_CHECKSUM),
 SX_FIELD("relative_data_offset","uint64",8,8,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("unknown","uint32",20,4,SX_NONE),
 SX_FIELD("name_page","uint16",24,2,SX_ID),
 SX_FIELD("name_offset_in_page","uint16",26,2,SX_OFFSET),
};
static const sx_layout sxga_tt_entry={UINT32_C(0x603B004A),"tt_entry",sxga_tt_entry_fields,SX_COUNT(sxga_tt_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ipak_offset_fields[]={
 SX_FIELD("record_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxga_ipak_offset={UINT32_C(0x603B004B),"ipak_offset",sxga_ipak_offset_fields,SX_COUNT(sxga_ipak_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ipak_entry_fields[]={
 SX_FIELD("extra_descriptor_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("packed_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("method","uint8",12,1,SX_ID),
 SX_FIELD("codec_parameter","uint8",13,1,SX_NONE),
 SX_FIELD("inline_descriptor_bytes","uint16",14,2,SX_SIZE),
};
static const sx_layout sxga_ipak_entry={UINT32_C(0x603B004C),"ipak_entry",sxga_ipak_entry_fields,SX_COUNT(sxga_ipak_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ipak_local_crumb_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("method","uint16",8,2,SX_ID),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("crc32_low","uint16",14,2,SX_CHECKSUM),
};
static const sx_layout sxga_ipak_local_crumb={UINT32_C(0x603B004D),"ipak_local_crumb",sxga_ipak_local_crumb_fields,SX_COUNT(sxga_ipak_local_crumb_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ipak_central_crumb_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version_made","uint16",4,2,SX_ID),
 SX_FIELD("version_needed","uint16",6,2,SX_ID),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
 SX_FIELD("method","uint16",10,2,SX_ID),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
};
static const sx_layout sxga_ipak_central_crumb={UINT32_C(0x603B004E),"ipak_central_crumb",sxga_ipak_central_crumb_fields,SX_COUNT(sxga_ipak_central_crumb_fields),SX_LE};
static const xx_data_struct_field_desc sxga_ipak_inline_prefix_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("descriptor_bytes","uint8",1,1,SX_SIZE),
};
static const sx_layout sxga_ipak_inline_prefix={UINT32_C(0x603B004F),"ipak_inline_prefix",sxga_ipak_inline_prefix_fields,SX_COUNT(sxga_ipak_inline_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_header_fields[]={
 SX_FIELD("version","int32",0,4,SX_ID),
};
static const sx_layout sxga_bsp_header={UINT32_C(0x603B0050),"bsp_header",sxga_bsp_header_fields,SX_COUNT(sxga_bsp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_lump_fields[]={
 SX_FIELD("data_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("data_bytes","int32",4,4,SX_SIZE),
};
static const sx_layout sxga_bsp_lump={UINT32_C(0x603B0051),"bsp_lump",sxga_bsp_lump_fields,SX_COUNT(sxga_bsp_lump_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_plane_fields[]={
 SX_FIELD("normal_x","float",0,4,SX_NONE),
 SX_FIELD("normal_y","float",4,4,SX_NONE),
 SX_FIELD("normal_z","float",8,4,SX_NONE),
 SX_FIELD("distance","float",12,4,SX_NONE),
 SX_FIELD("type","int32",16,4,SX_ID),
};
static const sx_layout sxga_bsp_plane={UINT32_C(0x603B0052),"bsp_plane",sxga_bsp_plane_fields,SX_COUNT(sxga_bsp_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_vertex_fields[]={
 SX_FIELD("x","float",0,4,SX_NONE),
 SX_FIELD("y","float",4,4,SX_NONE),
 SX_FIELD("z","float",8,4,SX_NONE),
};
static const sx_layout sxga_bsp_vertex={UINT32_C(0x603B0053),"bsp_vertex",sxga_bsp_vertex_fields,SX_COUNT(sxga_bsp_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_node_fields[]={
 SX_FIELD("plane","int32",0,4,SX_ID),
 SX_FIELD("child0","int16",4,2,SX_ID),
 SX_FIELD("child1","int16",6,2,SX_ID),
 SX_FIELD("min_x","int16",8,2,SX_NONE),
 SX_FIELD("min_y","int16",10,2,SX_NONE),
 SX_FIELD("min_z","int16",12,2,SX_NONE),
 SX_FIELD("max_x","int16",14,2,SX_NONE),
 SX_FIELD("max_y","int16",16,2,SX_NONE),
 SX_FIELD("max_z","int16",18,2,SX_NONE),
 SX_FIELD("first_face","uint16",20,2,SX_ID),
 SX_FIELD("faces","uint16",22,2,SX_COUNT_PROP),
};
static const sx_layout sxga_bsp_node={UINT32_C(0x603B0054),"bsp_node",sxga_bsp_node_fields,SX_COUNT(sxga_bsp_node_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_texinfo_fields[]={
 SX_FIELD("s_x","float",0,4,SX_NONE),
 SX_FIELD("s_y","float",4,4,SX_NONE),
 SX_FIELD("s_z","float",8,4,SX_NONE),
 SX_FIELD("s_shift","float",12,4,SX_NONE),
 SX_FIELD("t_x","float",16,4,SX_NONE),
 SX_FIELD("t_y","float",20,4,SX_NONE),
 SX_FIELD("t_z","float",24,4,SX_NONE),
 SX_FIELD("t_shift","float",28,4,SX_NONE),
 SX_FIELD("miptex","int32",32,4,SX_ID),
 SX_FIELD("flags","int32",36,4,SX_FLAGS),
};
static const sx_layout sxga_bsp_texinfo={UINT32_C(0x603B0055),"bsp_texinfo",sxga_bsp_texinfo_fields,SX_COUNT(sxga_bsp_texinfo_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_face_fields[]={
 SX_FIELD("plane","int16",0,2,SX_ID),
 SX_FIELD("side","int16",2,2,SX_NONE),
 SX_FIELD("first_edge","int32",4,4,SX_ID),
 SX_FIELD("edges","int16",8,2,SX_COUNT_PROP),
 SX_FIELD("texinfo","int16",10,2,SX_ID),
 SX_FIELD("style0","uint8",12,1,SX_ID),
 SX_FIELD("style1","uint8",13,1,SX_ID),
 SX_FIELD("style2","uint8",14,1,SX_ID),
 SX_FIELD("style3","uint8",15,1,SX_ID),
 SX_FIELD("light_offset","int32",16,4,SX_OFFSET),
};
static const sx_layout sxga_bsp_face={UINT32_C(0x603B0056),"bsp_face",sxga_bsp_face_fields,SX_COUNT(sxga_bsp_face_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_clipnode_fields[]={
 SX_FIELD("plane","int32",0,4,SX_ID),
 SX_FIELD("child0","int16",4,2,SX_ID),
 SX_FIELD("child1","int16",6,2,SX_ID),
};
static const sx_layout sxga_bsp_clipnode={UINT32_C(0x603B0057),"bsp_clipnode",sxga_bsp_clipnode_fields,SX_COUNT(sxga_bsp_clipnode_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_leaf_fields[]={
 SX_FIELD("contents","int32",0,4,SX_ID),
 SX_FIELD("visibility_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("min_x","int16",8,2,SX_NONE),
 SX_FIELD("min_y","int16",10,2,SX_NONE),
 SX_FIELD("min_z","int16",12,2,SX_NONE),
 SX_FIELD("max_x","int16",14,2,SX_NONE),
 SX_FIELD("max_y","int16",16,2,SX_NONE),
 SX_FIELD("max_z","int16",18,2,SX_NONE),
 SX_FIELD("first_marksurface","uint16",20,2,SX_ID),
 SX_FIELD("marksurfaces","uint16",22,2,SX_COUNT_PROP),
 SX_FIELD("ambient_water","uint8",24,1,SX_NONE),
 SX_FIELD("ambient_sky","uint8",25,1,SX_NONE),
 SX_FIELD("ambient_slime","uint8",26,1,SX_NONE),
 SX_FIELD("ambient_lava","uint8",27,1,SX_NONE),
};
static const sx_layout sxga_bsp_leaf={UINT32_C(0x603B0058),"bsp_leaf",sxga_bsp_leaf_fields,SX_COUNT(sxga_bsp_leaf_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_marksurface_fields[]={
 SX_FIELD("face","uint16",0,2,SX_ID),
};
static const sx_layout sxga_bsp_marksurface={UINT32_C(0x603B0059),"bsp_marksurface",sxga_bsp_marksurface_fields,SX_COUNT(sxga_bsp_marksurface_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_edge_fields[]={
 SX_FIELD("vertex0","uint16",0,2,SX_ID),
 SX_FIELD("vertex1","uint16",2,2,SX_ID),
};
static const sx_layout sxga_bsp_edge={UINT32_C(0x603B005A),"bsp_edge",sxga_bsp_edge_fields,SX_COUNT(sxga_bsp_edge_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_surfedge_fields[]={
 SX_FIELD("edge","int32",0,4,SX_ID),
};
static const sx_layout sxga_bsp_surfedge={UINT32_C(0x603B005B),"bsp_surfedge",sxga_bsp_surfedge_fields,SX_COUNT(sxga_bsp_surfedge_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_model_fields[]={
 SX_FIELD("min_x","float",0,4,SX_NONE),
 SX_FIELD("min_y","float",4,4,SX_NONE),
 SX_FIELD("min_z","float",8,4,SX_NONE),
 SX_FIELD("max_x","float",12,4,SX_NONE),
 SX_FIELD("max_y","float",16,4,SX_NONE),
 SX_FIELD("max_z","float",20,4,SX_NONE),
 SX_FIELD("origin_x","float",24,4,SX_NONE),
 SX_FIELD("origin_y","float",28,4,SX_NONE),
 SX_FIELD("origin_z","float",32,4,SX_NONE),
 SX_FIELD("headnode0","int32",36,4,SX_ID),
 SX_FIELD("headnode1","int32",40,4,SX_ID),
 SX_FIELD("headnode2","int32",44,4,SX_ID),
 SX_FIELD("headnode3","int32",48,4,SX_ID),
 SX_FIELD("visibility_leaves","int32",52,4,SX_COUNT_PROP),
 SX_FIELD("first_face","int32",56,4,SX_ID),
 SX_FIELD("faces","int32",60,4,SX_COUNT_PROP),
};
static const sx_layout sxga_bsp_model={UINT32_C(0x603B005C),"bsp_model",sxga_bsp_model_fields,SX_COUNT(sxga_bsp_model_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_textures_fields[]={
 SX_FIELD("textures","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxga_bsp_textures={UINT32_C(0x603B005D),"bsp_textures",sxga_bsp_textures_fields,SX_COUNT(sxga_bsp_textures_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_texture_offset_fields[]={
 SX_FIELD("texture_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxga_bsp_texture_offset={UINT32_C(0x603B005E),"bsp_texture_offset",sxga_bsp_texture_offset_fields,SX_COUNT(sxga_bsp_texture_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_miptex_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_STRING),
 SX_FIELD("width","uint32",16,4,SX_NONE),
 SX_FIELD("height","uint32",20,4,SX_NONE),
 SX_FIELD("mip0_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("mip1_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("mip2_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("mip3_offset","uint32",36,4,SX_OFFSET),
};
static const sx_layout sxga_bsp_miptex={UINT32_C(0x603B005F),"bsp_miptex",sxga_bsp_miptex_fields,SX_COUNT(sxga_bsp_miptex_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_palette_fields[]={
 SX_FIELD("colors","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxga_bsp_palette={UINT32_C(0x603B0060),"bsp_palette",sxga_bsp_palette_fields,SX_COUNT(sxga_bsp_palette_fields),SX_LE};
static const xx_data_struct_field_desc sxga_bsp_color_fields[]={
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
};
static const sx_layout sxga_bsp_color={UINT32_C(0x603B0061),"bsp_color",sxga_bsp_color_fields,SX_COUNT(sxga_bsp_color_fields),SX_LE};
static const sx_layout *const sx_gamearchives_layouts[]={
 &sxga_filename_byte,
 &sxga_encoded_name_byte,
 &sxga_name_length8,
 &sxga_name_length32,
 &sxga_count16,
 &sxga_count32,
 &sxga_offset32,
 &sxga_length16,
 &sxga_hog2_header,
 &sxga_hog2_entry,
 &sxga_vp_header,
 &sxga_vp_entry,
 &sxga_cat_entry,
 &sxga_teacy_entry,
 &sxga_settlers_header,
 &sxga_settlers_slot,
 &sxga_wolf_header,
 &sxga_ea_entry,
 &sxga_agis_entry,
 &sxga_epf_header,
 &sxga_epf_entry,
 &sxga_ppd_entry,
 &sxga_wux_header,
 &sxga_wux_block,
 &sxga_refpack_header24,
 &sxga_refpack_header24_packed,
 &sxga_refpack_header32,
 &sxga_refpack_header32_packed,
 &sxga_stunts_header,
 &sxga_stunts_pass,
 &sxga_stunts_rle,
 &sxga_stunts_vle,
 &sxga_stunts_escape,
 &sxga_stunts_level,
 &sxga_stunts_symbol,
 &sxga_silmarils_header_le,
 &sxga_silmarils_header_be,
 &sxga_silmarils_offset_widths,
 &sxga_ns_header,
 &sxga_ns_zero_prefix,
 &sxga_sar_entry,
 &sxga_nsa_entry,
 &sxga_ns2_header,
 &sxga_ns2_size,
 &sxga_ns2_quote,
 &sxga_ns2_end,
 &sxga_dcp_header,
 &sxga_dcp_directory_offset,
 &sxga_dcp_directory,
 &sxga_dcp_entry1,
 &sxga_dcp_entry2,
 &sxga_far_header,
 &sxga_far_entry16,
 &sxga_far_entry32,
 &sxga_xzp_header,
 &sxga_xzp_entry,
 &sxga_xzp_mapping,
 &sxga_xzp_name,
 &sxga_xzp_footer,
 &sxga_pbo_entry,
 &sxga_majiro_header,
 &sxga_majiro_entry1,
 &sxga_majiro_entry2,
 &sxga_majiro_entry3,
 &sxga_nexas_header,
 &sxga_nexas_entry32,
 &sxga_nexas_entry64,
 &sxga_nexas_footer,
 &sxga_tt_nctt,
 &sxga_tt_chunked,
 &sxga_tt_chunk_offset,
 &sxga_tt_header3,
 &sxga_tt_header4,
 &sxga_tt_entry,
 &sxga_ipak_offset,
 &sxga_ipak_entry,
 &sxga_ipak_local_crumb,
 &sxga_ipak_central_crumb,
 &sxga_ipak_inline_prefix,
 &sxga_bsp_header,
 &sxga_bsp_lump,
 &sxga_bsp_plane,
 &sxga_bsp_vertex,
 &sxga_bsp_node,
 &sxga_bsp_texinfo,
 &sxga_bsp_face,
 &sxga_bsp_clipnode,
 &sxga_bsp_leaf,
 &sxga_bsp_marksurface,
 &sxga_bsp_edge,
 &sxga_bsp_surfedge,
 &sxga_bsp_model,
 &sxga_bsp_textures,
 &sxga_bsp_texture_offset,
 &sxga_bsp_miptex,
 &sxga_bsp_palette,
 &sxga_bsp_color,
};
/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxga_view {sx_context*c;unsigned work;}sxga_view;
static bool sxga_span(sxga_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxga_read(sxga_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return sxga_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxga_word(sxga_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxga_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxga_row(sxga_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxga_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_table(sxga_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxga_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxga_row(v,l,at,end))return false;return true;}
static int sxga_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxga_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxga_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxga_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxga_cstring(sxga_view*v,uint64_t*p,uint64_t end,uint64_t max)
{uint64_t start=*p,c;while(*p<end&&*p-start<max){if(++v->work>4000000||!sxga_word(v,*p,1,false,&c,end))return false;(*p)++;if(!c)return true;}return false;}
static bool sxga_named(sxga_view*v,uint64_t at,uint64_t n,uint64_t end,bool encoded)
{if(!sxga_span(v,at,n,end))return false;return !n||v->c->count>=24000||sx_table(v->c,encoded?&sxga_encoded_name_byte:&sxga_filename_byte,(int64_t)at,1,n);}
static bool sxga_hog(sxga_view*v)
{uint64_t end=v->c->size,n;if(!GA_ROW(hog2_header,0,end)||!sxga_word(v,4,4,false,&n,end))return false;return sxga_table(v,&sxga_hog2_entry,68,n,end);}
static bool sxga_vp(sxga_view*v)
{uint64_t end=v->c->size,n,at;if(!GA_ROW(vp_header,0,end)||!sxga_word(v,8,4,false,&at,end)||!sxga_word(v,12,4,false,&n,end))return false;return sxga_table(v,&sxga_vp_entry,at,n,end);}
static bool sxga_counted(sxga_view*v,const sx_layout*l)
{uint64_t end=v->c->size,n;return GA_ROW(count16,0,end)&&sxga_word(v,0,2,false,&n,end)&&sxga_table(v,l,2,n,end);}
static bool sxga_settlers(sxga_view*v)
{uint64_t end=v->c->size,n;return GA_ROW(settlers_header,0,end)&&sxga_word(v,4,4,false,&n,end)&&sxga_table(v,&sxga_settlers_slot,8,n,end);}
static bool sxga_wolf(sxga_view*v)
{uint64_t end=v->c->size,n;return GA_ROW(wolf_header,0,end)&&sxga_word(v,0,2,false,&n,end)&&sxga_table(v,&sxga_offset32,6,n,end)&&sxga_table(v,&sxga_length16,6+n*4,n,end);}
static bool sxga_ea(sxga_view*v)
{uint64_t end=v->c->size,at=0,n;while(at<end){if(!GA_ROW(ea_entry,at,end)||!sxga_word(v,at+25,4,false,&n,end)||!sxga_span(v,at+48,n,end))return false;at+=48+n;}return true;}
static bool sxga_agis(sxga_view*v)
{uint64_t end=v->c->size,at=0,n;while(at<end){if(!GA_ROW(agis_entry,at,end)||!sxga_word(v,at+14,4,false,&n,end)||n<31||!sxga_span(v,at,n,end))return false;at+=n;}return true;}
static bool sxga_epf(sxga_view*v)
{uint64_t end=v->c->size,at,n;return GA_ROW(epf_header,0,end)&&sxga_word(v,4,4,false,&at,end)&&sxga_word(v,9,2,false,&n,end)&&sxga_table(v,&sxga_epf_entry,at,n,end);}
static bool sxga_ppd(sxga_view*v)
{uint64_t end=v->c->size,at=4,n,z;if(!GA_ROW(count32,0,end)||!sxga_word(v,0,4,false,&n,end)||n>4096)return false;for(uint64_t i=0;i<n;i++){if(!GA_ROW(name_length32,at,end)||!sxga_word(v,at,4,false,&z,end))return false;at+=4;if(!sxga_named(v,at,z,end,false))return false;at+=z;if(!GA_ROW(ppd_entry,at,end))return false;at+=12;}return true;}
static bool sxga_wux(sxga_view*v)
{uint64_t end=v->c->size,z,n;if(!GA_ROW(wux_header,0,end)||!sxga_word(v,8,4,false,&z,end)||!z||!sxga_word(v,16,8,false,&n,end))return false;return sxga_table(v,&sxga_wux_block,32,n/z+(n%z!=0),end);}
static bool sxga_refpack(sxga_view*v)
{uint64_t end=v->c->size,b;if(!sxga_word(v,0,1,false,&b,end))return false;const sx_layout*l=(b&1)?((b&128)?&sxga_refpack_header32_packed:&sxga_refpack_header32):((b&128)?&sxga_refpack_header24_packed:&sxga_refpack_header24);return sxga_row(v,l,0,end);}
static bool sxga_stunts(sxga_view*v)
{uint64_t end=v->c->size,b,at=0,n;if(!sxga_word(v,0,1,false,&b,end))return false;if(b&128){if(!GA_ROW(stunts_header,0,end))return false;at=4;}if(!GA_ROW(stunts_pass,at,end)||!sxga_word(v,at,1,false,&b,end))return false;at+=4;if(b==1){if(!GA_ROW(stunts_rle,at,end)||!sxga_word(v,at+4,1,false,&n,end))return false;return sxga_table(v,&sxga_stunts_escape,at+5,n&127,end);}if(b==2){if(!GA_ROW(stunts_vle,at,end)||!sxga_word(v,at,1,false,&n,end))return false;at++;n&=127;uint64_t total=0;for(uint64_t i=0;i<n;i++){uint64_t z;if(!GA_ROW(stunts_level,at+i,end)||!sxga_word(v,at+i,1,false,&z,end))return false;total+=z;}return sxga_table(v,&sxga_stunts_symbol,at+n,total,end);}return false;}
static bool sxga_silmarils(sxga_view*v)
{uint64_t end=v->c->size,flag,method;if(!sxga_word(v,4,2,false,&flag,end))return false;bool be=flag!=1;if(!sxga_row(v,be?&sxga_silmarils_header_be:&sxga_silmarils_header_le,0,end)||!sxga_word(v,be?0:3,1,false,&method,end))return false;return method!=0xa1||GA_ROW(silmarils_offset_widths,6,end);}
static bool sxga_ns(sxga_view*v,bool nsa)
{uint64_t end=v->c->size,base=0,n,at,first;if(!sxga_word(v,0,2,true,&first,end))return false;/* Native NSA selects the two-zero-byte prefix when the first word is zero. */
 if(nsa&&!first){base=2;if(!GA_ROW(ns_zero_prefix,0,end))return false;}
 if(!GA_ROW(ns_header,base,end)||!sxga_word(v,base,2,true,&n,end))return false;at=base+6;for(uint64_t i=0;i<n;i++){uint64_t start=at;if(!sxga_cstring(v,&at,end,1025)||!sxga_named(v,start,at-start,end,false)||!sxga_row(v,nsa?&sxga_nsa_entry:&sxga_sar_entry,at,end))return false;at+=nsa?13:8;}return true;}
static bool sxga_ns2(sxga_view*v)
{uint64_t end=v->c->size,base,at=4,b;if(!GA_ROW(ns2_header,0,end)||!sxga_word(v,0,4,false,&base,end)||base>end)return false;while(at<base){if(!sxga_word(v,at,1,false,&b,base))return false;if(b=='e')return GA_ROW(ns2_end,at,base);if(b!='"'||!GA_ROW(ns2_quote,at,base))return false;uint64_t start=++at;while(at<base){if(!sxga_word(v,at,1,false,&b,base))return false;if(b=='"')break;at++;if(++v->work>4000000)return false;}if(!sxga_named(v,start,at-start,base,false)||!GA_ROW(ns2_quote,at,base)||!GA_ROW(ns2_size,at+1,base))return false;at+=5;}return false;}
static bool sxga_dcp(sxga_view*v)
{uint64_t end=v->c->size,at=128,version,dirs,n,z;if(!GA_ROW(dcp_header,0,end)||!sxga_word(v,8,4,false,&version,end)||!sxga_word(v,124,4,false,&dirs,end)||dirs>1000000)return false;if(version==0x200){if(!GA_ROW(dcp_directory_offset,128,end)||!sxga_word(v,128,4,false,&at,end))return false;}for(uint64_t i=0;i<dirs;i++){if(!GA_ROW(name_length8,at,end)||!sxga_word(v,at,1,false,&z,end))return false;at++;if(!sxga_named(v,at,z,end,false))return false;at+=z;if(!GA_ROW(dcp_directory,at,end)||!sxga_word(v,at+1,4,false,&n,end)||n>1000000)return false;at+=5;for(uint64_t j=0;j<n;j++){if(!GA_ROW(name_length8,at,end)||!sxga_word(v,at,1,false,&z,end))return false;at++;if(!sxga_named(v,at,z,end,version==0x200))return false;at+=z;if(!sxga_row(v,version==0x200?&sxga_dcp_entry2:&sxga_dcp_entry1,at,end))return false;at+=version==0x200?24:16;}}return true;}
/* Reuse validated native record boundaries for ambiguous directory variants. */
static bool sxga_far(sxga_view*v)
{uint64_t end=v->c->size,at,n;if(!GA_ROW(far_header,0,end)||!sxga_word(v,12,4,false,&at,end)||!GA_ROW(count32,at,end)||!sxga_word(v,at,4,false,&n,end))return false;
 xx_archive_record_state*state=xx_format_create_archive_records_reading(v->c->f,NULL,v->c->pd);if(!state)return false;bool ok=true;
 do{const xx_archive_record*r=xx_format_get_current_archive_record(v->c->f,state);if(!r)break;uint64_t z,wide=0,width=0;if(r->header_offset<v->c->f->base_address||r->header_size<14){ok=false;break;}at=(uint64_t)(r->header_offset-v->c->f->base_address);if(!sxga_span(v,at,(uint64_t)r->header_size,end)||!sxga_word(v,at+12,2,false,&z,end)){ok=false;break;}
  if(r->header_size>=16&&sxga_word(v,at+12,4,false,&wide,end)&&wide==(uint64_t)r->header_size-16){width=4;z=wide;}else if(z==(uint64_t)r->header_size-14)width=2;
  if(!width||!sxga_row(v,width==2?&sxga_far_entry16:&sxga_far_entry32,at,end)||!sxga_named(v,at+12+width,z,end,false)){ok=false;break;}
 }while(xx_format_archive_record_move_to_next(v->c->f,state,v->c->pd));xx_format_free_archive_records_reading(v->c->f,state);return ok;}
static bool sxga_nexas_candidate(sxga_view*v,unsigned width,uint64_t n,uint64_t end,uint64_t mode)
{uint64_t z=width+12,table=n*z;if(table>16777216||!sxga_span(v,12,table,end))return false;for(uint64_t i=0;i<n;i++){uint8_t b[76];if(!sxga_read(v,12+i*z,b,(size_t)z,end))return false;bool nonspace=false;unsigned length=0;while(length<width&&b[length]){if(b[length]>32)nonspace=true;length++;}uint64_t at=xx_data_get_u32(b+width,4,0,false),raw=xx_data_get_u32(b+width+4,4,0,false),packed=xx_data_get_u32(b+width+8,4,0,false);if(!length||!nonspace||at<12+table||!sxga_span(v,at,packed,end)||(!mode&&packed!=raw))return false;}return true;}
static bool sxga_nexas(sxga_view*v)
{uint64_t end=v->c->size,n,mode;if(!GA_ROW(nexas_header,0,end)||!sxga_word(v,4,4,false,&n,end)||!n||n>0xfffff||!sxga_word(v,8,4,false,&mode,end))return false;
 if(sxga_nexas_candidate(v,32,n,end,mode))return sxga_table(v,&sxga_nexas_entry32,12,n,end);
 if(sxga_nexas_candidate(v,64,n,end,mode))return sxga_table(v,&sxga_nexas_entry64,12,n,end);
 return end>=4&&GA_ROW(nexas_footer,end-4,end);}
static bool sxga_xzp(sxga_view*v)
{uint64_t end=v->c->size,n,p,z,m,at,names,table_end;if(!GA_ROW(xzp_header,0,end)||!sxga_word(v,8,4,false,&p,end)||!sxga_word(v,12,4,false,&n,end)||!sxga_word(v,16,4,false,&z,end)||!sxga_word(v,24,4,false,&m,end)||!sxga_word(v,28,4,false,&at,end)||!sxga_word(v,32,4,false,&names,end)||m>1000000)return false;if(!sxga_table(v,&sxga_xzp_entry,36,n,end))return false;if(z&&(!sxga_table(v,&sxga_xzp_entry,36+12*n,p,end)||!sxga_table(v,&sxga_xzp_mapping,36+12*(n+p),n,end)))return false;if(!sxga_span(v,at,names,end)||!sxga_table(v,&sxga_xzp_name,at,m,at+names))return false;table_end=at+names;for(uint64_t i=0;i<m;i++){uint64_t pos,start;if(!sxga_word(v,at+12*i+4,4,false,&pos,table_end))return false;start=pos;if(pos>=at+12*m&&pos<table_end&&sxga_cstring(v,&pos,table_end,256)&&!sxga_named(v,start,pos-start,table_end,false))return false;}return end>=8&&GA_ROW(xzp_footer,end-8,end);}
static bool sxga_pbo(sxga_view*v)
{uint64_t end=v->c->size,at=0,method;while(at<end){uint64_t start=at;if(!sxga_cstring(v,&at,end,4097)||!sxga_named(v,start,at-start,end,false)||!GA_ROW(pbo_entry,at,end)||!sxga_word(v,at,4,false,&method,end))return false;bool empty=at==start+1;at+=20;if(empty&&method==0x56657273){for(;;){start=at;if(!sxga_cstring(v,&at,end,4097)||!sxga_named(v,start,at-start,end,false))return false;if(at==start+1)break;start=at;if(!sxga_cstring(v,&at,end,4097)||!sxga_named(v,start,at-start,end,false))return false;}continue;}if(empty)return true;}return false;}
static bool sxga_majiro(sxga_view*v)
{uint64_t end=v->c->size,version,n,at,data;if(!GA_ROW(majiro_header,0,end)||!sxga_word(v,10,1,false,&version,end)||!sxga_word(v,16,4,false,&n,end)||!sxga_word(v,20,4,false,&at,end)||!sxga_word(v,24,4,false,&data,end)||data>end)return false;const sx_layout*l=version=='1'?&sxga_majiro_entry1:version=='2'?&sxga_majiro_entry2:&sxga_majiro_entry3;if(!sxga_table(v,l,28,n+(version=='1'),end))return false;for(uint64_t i=0;i<n;i++){uint64_t start=at;if(!sxga_cstring(v,&at,data,4097)||!sxga_named(v,start,at-start,data,false))return false;}return true;}
static bool sxga_tt(sxga_view*v)
{uint64_t end=v->c->size,at=0,n,z,tag;if(!sxga_word(v,0,4,false,&tag,end))return false;if(tag==UINT32_C(0x5454434e)){if(!GA_ROW(tt_nctt,0,end)||!sxga_word(v,4,8,false,&z,end)||!sxga_span(v,12,z,end))return false;at=12;end=at+z;if(!sxga_word(v,at,4,false,&tag,end))return false;}else if(tag==UINT32_C(0x5454435a)||tag==UINT32_C(0x54544345)){return GA_ROW(tt_chunked,0,end)&&sxga_word(v,8,4,false,&n,end)&&sxga_table(v,&sxga_tt_chunk_offset,12,n+1,end);}bool v3=tag==UINT32_C(0x54544133);if(!sxga_row(v,v3?&sxga_tt_header3:&sxga_tt_header4,at,end)||!sxga_word(v,at+(v3?8:4),4,false,&z,end)||!sxga_word(v,at+(v3?12:8),4,false,&n,end))return false;at+=v3?16:12;if(!sxga_table(v,&sxga_tt_entry,at,n,end))return false;at+=n*28;/* The stored name pool can contain page padding; preserve its bytes exactly. */return sxga_named(v,at,z,end,false);}
static bool sxga_ipak(sxga_view*v)
{uint64_t end=v->c->size,table,last=0;if(!sxga_word(v,4,4,false,&table,end)||table%4||!sxga_table(v,&sxga_ipak_offset,0,table/4,end))return false;
 xx_archive_record_state*state=xx_format_create_archive_records_reading(v->c->f,NULL,v->c->pd);if(!state)return false;bool ok=true;
 do{const xx_archive_record*r=xx_format_get_current_archive_record(v->c->f,state);if(!r)break;uint64_t off,n,extra,inl,packed,mark,length;if(r->header_offset<v->c->f->base_address){ok=false;break;}off=(uint64_t)(r->header_offset-v->c->f->base_address);
  /* The public native record includes a leading local PKZIP crumb. */
  if(!sxga_word(v,off,4,false,&n,end)){ok=false;break;}
  if(n==UINT32_C(0x04034b50)){if(!GA_ROW(ipak_local_crumb,off,end)){ok=false;break;}off+=16;}
  if(!GA_ROW(ipak_entry,off,end)||!sxga_word(v,off,4,false,&extra,end)||!sxga_word(v,off+4,4,false,&packed,end)||!sxga_word(v,off+14,2,false,&inl,end)||!sxga_span(v,off+16,inl+extra+packed,end)){ok=false;break;}
  if(inl>=3&&sxga_word(v,off+16,1,false,&mark,end)&&sxga_word(v,off+17,1,false,&length,end)&&mark==0x49&&length==inl){if(!GA_ROW(ipak_inline_prefix,off+16,end)||!sxga_named(v,off+18,inl-2,end,false)){ok=false;break;}}
  if(off+16+inl+extra+packed>last)last=off+16+inl+extra+packed;
 }while(xx_format_archive_record_move_to_next(v->c->f,state,v->c->pd));xx_format_free_archive_records_reading(v->c->f,state);
 uint64_t tag;if(ok&&sxga_span(v,last,16,end)&&sxga_word(v,last,4,false,&tag,end)&&tag==UINT32_C(0x02014b50))ok=GA_ROW(ipak_central_crumb,last,end);return ok;}
static bool sxga_bsp(sxga_view*v)
{uint64_t end=v->c->size,offsets[15],sizes[15];if(!GA_ROW(bsp_header,0,end)||!sxga_table(v,&sxga_bsp_lump,4,15,end))return false;for(unsigned i=0;i<15;i++)if(!sxga_word(v,4+i*8,4,false,&offsets[i],end)||!sxga_word(v,8+i*8,4,false,&sizes[i],end)||!sxga_span(v,offsets[i],sizes[i],end))return false;
 unsigned plane=sizes[1]%20==0?1:0;const sx_layout*layouts[15]={NULL,NULL,NULL,&sxga_bsp_vertex,NULL,&sxga_bsp_node,&sxga_bsp_texinfo,&sxga_bsp_face,NULL,&sxga_bsp_clipnode,&sxga_bsp_leaf,&sxga_bsp_marksurface,&sxga_bsp_edge,&sxga_bsp_surfedge,&sxga_bsp_model};layouts[plane]=&sxga_bsp_plane;
 for(unsigned i=0;i<15;i++)if(layouts[i]&&sizes[i]){const sx_layout*l=layouts[i];const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=f->rel_offset+f->size;if(sizes[i]%z||!sxga_table(v,l,offsets[i],sizes[i]/z,end))return false;}
 if(sizes[2]){uint64_t at=offsets[2],limit=at+sizes[2],n;if(!GA_ROW(bsp_textures,at,limit)||!sxga_word(v,at,4,false,&n,limit)||!sxga_table(v,&sxga_bsp_texture_offset,at+4,n,limit))return false;for(uint64_t i=0;i<n;i++){uint64_t rel,tex,w,h,mip,palette,colors;if(!sxga_word(v,at+4+i*4,4,false,&rel,limit))return false;if(rel<4+4*n||rel>sizes[2]||sizes[2]-rel<40)continue;tex=at+rel;if(!GA_ROW(bsp_miptex,tex,limit)||!sxga_word(v,tex+16,4,false,&w,limit)||!sxga_word(v,tex+20,4,false,&h,limit)||!sxga_word(v,tex+36,4,false,&mip,limit))return false;if(!w||!h||w>sizes[2]||h>sizes[2]||w*h>sizes[2]||mip>sizes[2]-rel)continue;bool valid=true;for(unsigned level=0;level<4;level++){uint64_t mo,sz=(w>>level)*(h>>level);if(!sxga_word(v,tex+24+4*level,4,false,&mo,limit))return false;if(mo<40||mo>limit-tex||sz>limit-tex-mo){valid=false;break;}}if(!valid)continue;palette=tex+mip+(w>>3)*(h>>3);if(!sxga_span(v,palette,2,limit))continue;if(!sxga_word(v,palette,2,false,&colors,limit))return false;if(colors>256||!sxga_span(v,palette+2,colors*3,limit))continue;if(!GA_ROW(bsp_palette,palette,limit)||!sxga_table(v,&sxga_bsp_color,palette+2,colors,limit))return false;}}
 return true;}

static bool sx_gamearchives_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_HOG2:
case XX_FILE_TYPE_VOLITIONVPFT:
case XX_FILE_TYPE_WINTERMUTEDCP:
case XX_FILE_TYPE_CAT:
case XX_FILE_TYPE_SAR_NS:
case XX_FILE_TYPE_NS2:
case XX_FILE_TYPE_NSA:
case XX_FILE_TYPE_MAXIS_FAR_ARCHIVE:
case XX_FILE_TYPE_VALVE_XZP:
case XX_FILE_TYPE_PBO:
case XX_FILE_TYPE_GOLDSRC_BSP:
case XX_FILE_TYPE_MAJIRO:
case XX_FILE_TYPE_NEXAS_PAC:
case XX_FILE_TYPE_TELLTALE_TTARCH:
case XX_FILE_TYPE_WUX:
case XX_FILE_TYPE_STUNTS:
case XX_FILE_TYPE_EA:
case XX_FILE_TYPE_EAREFPACK:
case XX_FILE_TYPE_AGIS:
case XX_FILE_TYPE_TEACY:
case XX_FILE_TYPE_SETTLERSFT:
case XX_FILE_TYPE_WOLFFT:
case XX_FILE_TYPE_SILMARILSFT:
case XX_FILE_TYPE_INFOGRAMESFT:
case XX_FILE_TYPE_PPD:
case XX_FILE_TYPE_EPF:
return true;default:return false;}}
static bool sx_gamearchives_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxga_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_HOG2:ok=sxga_hog(v);break;
case XX_FILE_TYPE_VOLITIONVPFT:ok=sxga_vp(v);break;
case XX_FILE_TYPE_WINTERMUTEDCP:ok=sxga_dcp(v);break;
case XX_FILE_TYPE_CAT:ok=sxga_counted(v,&sxga_cat_entry);break;
case XX_FILE_TYPE_SAR_NS:ok=sxga_ns(v,false);break;
case XX_FILE_TYPE_NS2:ok=sxga_ns2(v);break;
case XX_FILE_TYPE_NSA:ok=sxga_ns(v,true);break;
case XX_FILE_TYPE_MAXIS_FAR_ARCHIVE:ok=sxga_far(v);break;
case XX_FILE_TYPE_VALVE_XZP:ok=sxga_xzp(v);break;
case XX_FILE_TYPE_PBO:ok=sxga_pbo(v);break;
case XX_FILE_TYPE_GOLDSRC_BSP:ok=sxga_bsp(v);break;
case XX_FILE_TYPE_MAJIRO:ok=sxga_majiro(v);break;
case XX_FILE_TYPE_NEXAS_PAC:ok=sxga_nexas(v);break;
case XX_FILE_TYPE_TELLTALE_TTARCH:ok=sxga_tt(v);break;
case XX_FILE_TYPE_WUX:ok=sxga_wux(v);break;
case XX_FILE_TYPE_STUNTS:ok=sxga_stunts(v);break;
case XX_FILE_TYPE_EA:ok=sxga_ea(v);break;
case XX_FILE_TYPE_EAREFPACK:ok=sxga_refpack(v);break;
case XX_FILE_TYPE_AGIS:ok=sxga_agis(v);break;
case XX_FILE_TYPE_TEACY:ok=sxga_counted(v,&sxga_teacy_entry);break;
case XX_FILE_TYPE_SETTLERSFT:ok=sxga_settlers(v);break;
case XX_FILE_TYPE_WOLFFT:ok=sxga_wolf(v);break;
case XX_FILE_TYPE_SILMARILSFT:ok=sxga_silmarils(v);break;
case XX_FILE_TYPE_INFOGRAMESFT:ok=sxga_ipak(v);break;
case XX_FILE_TYPE_PPD:ok=sxga_ppd(v);break;
case XX_FILE_TYPE_EPF:ok=sxga_epf(v);break;
default:break;}
 return ok&&sxga_finish(c);}
#undef GA_ROW
static bool sx_gamearchives_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<=UINT32_C(0x603b0000)||id>=UINT32_C(0x603c0000))return true;
 if(id==sxga_filename_byte.id&&!xx_rt_wcscmp(r->name,L"byte"))return xx_data_struct_record_set_comment(r,L"Physical string or name-pool byte; character encoding and terminators are preserved.");
 if(id==sxga_encoded_name_byte.id&&!xx_rt_wcscmp(r->name,L"byte"))return xx_data_struct_record_set_comment(r,L"Physical filename byte; Wintermute version2 names are XOR0x44 encoded.");
 if(id==sxga_offset32.id&&!xx_rt_wcscmp(r->name,L"offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_hog2_header.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_hog2_entry.id&&!xx_rt_wcscmp(r->name,L"modified"))return xx_data_struct_record_set_comment(r,L"Stored Unix timestamp in seconds.");
 if(id==sxga_vp_header.id&&!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_vp_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_vp_entry.id&&!xx_rt_wcscmp(r->name,L"modified"))return xx_data_struct_record_set_comment(r,L"Stored Unix timestamp in seconds.");
 if(id==sxga_cat_entry.id&&!xx_rt_wcscmp(r->name,L"dos_timestamp"))return xx_data_struct_record_set_comment(r,L"Packed DOS date (high16) and time (low16); retain the stored word.");
 if(id==sxga_cat_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_teacy_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_settlers_slot.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_ea_entry.id&&!xx_rt_wcscmp(r->name,L"stamp"))return xx_data_struct_record_set_comment(r,L"Unknown archive stamp; native evidence does not identify it as a DOS timestamp.");
 if(id==sxga_epf_header.id&&!xx_rt_wcscmp(r->name,L"table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_ppd_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_ppd_entry.id&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Stored four-byte entry tail; semantics are unknown.");
 if(id==sxga_wux_header.id&&!xx_rt_wcscmp(r->name,L"alignment12"))return xx_data_struct_record_set_comment(r,L"ABI alignment padding before the 64-bit image length; retain the original bytes.");
 if(id==sxga_wux_header.id&&!xx_rt_wcscmp(r->name,L"decoded_bytes"))return xx_data_struct_record_set_comment(r,L"Logical uncompressed disc size in bytes.");
 if(id==sxga_wux_header.id&&!xx_rt_wcscmp(r->name,L"alignment28"))return xx_data_struct_record_set_comment(r,L"Trailing ABI alignment padding; retain the original bytes.");
 if(id==sxga_wux_block.id&&!xx_rt_wcscmp(r->name,L"stored_block_index"))return xx_data_struct_record_set_comment(r,L"Physical stored block index, multiplied by block_bytes after the aligned index table; this is not a byte offset.");
 if(id==sxga_stunts_header.id&&!xx_rt_wcscmp(r->name,L"passes"))return xx_data_struct_record_set_comment(r,L"Bit7 marks the wrapper; low7 bits give the pass count.");
 if(id==sxga_stunts_header.id&&!xx_rt_wcscmp(r->name,L"decoded_bytes"))return xx_data_struct_record_set_comment(r,L"Final decoded size in bytes; subsequent passes are inside decoded data.");
 if(id==sxga_stunts_rle.id&&!xx_rt_wcscmp(r->name,L"source_bytes"))return xx_data_struct_record_set_comment(r,L"Stored source-length value; native decoding is bounded by the physical input extent.");
 if(id==sxga_stunts_rle.id&&!xx_rt_wcscmp(r->name,L"escape_flags"))return xx_data_struct_record_set_comment(r,L"Low7 bits: escape-byte count; bit7 disables the sequence-repeat layer.");
 if(id==sxga_stunts_vle.id&&!xx_rt_wcscmp(r->name,L"level_flags"))return xx_data_struct_record_set_comment(r,L"Low7 bits: code-width levels; bit7: delta-coded alphabet.");
 if(id==sxga_silmarils_header_le.id&&!xx_rt_wcscmp(r->name,L"decoded_bytes"))return xx_data_struct_record_set_comment(r,L"Stored decoded size includes the six-byte resource header.");
 if(id==sxga_silmarils_header_be.id&&!xx_rt_wcscmp(r->name,L"decoded_bytes"))return xx_data_struct_record_set_comment(r,L"Stored decoded size includes the six-byte resource header.");
 if(id==sxga_ns_header.id&&!xx_rt_wcscmp(r->name,L"data_base"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this header, after any two-byte NSA prefix.");
 if(id==sxga_sar_entry.id&&!xx_rt_wcscmp(r->name,L"relative_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the archive data area given by data_base.");
 if(id==sxga_nsa_entry.id&&!xx_rt_wcscmp(r->name,L"relative_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the archive data area given by data_base.");
 if(id==sxga_ns2_header.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_dcp_header.id&&!xx_rt_wcscmp(r->name,L"creation_time"))return xx_data_struct_record_set_comment(r,L"Stored package creation timestamp; the schema preserves its numeric value.");
 if(id==sxga_dcp_directory_offset.id&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_dcp_entry1.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_dcp_entry2.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_dcp_entry2.id&&!xx_rt_wcscmp(r->name,L"timestamp_low"))return xx_data_struct_record_set_comment(r,L"Low32 bits of the stored two-word timestamp; preserve the split representation.");
 if(id==sxga_dcp_entry2.id&&!xx_rt_wcscmp(r->name,L"timestamp_high"))return xx_data_struct_record_set_comment(r,L"High32 bits of the stored two-word timestamp; preserve the split representation.");
 if(id==sxga_far_header.id&&!xx_rt_wcscmp(r->name,L"manifest_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_far_entry16.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_far_entry32.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_xzp_header.id&&!xx_rt_wcscmp(r->name,L"name_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_xzp_entry.id&&!xx_rt_wcscmp(r->name,L"name_crc"))return xx_data_struct_record_set_comment(r,L"Resource-name CRC used as a lookup key.");
 if(id==sxga_xzp_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_xzp_name.id&&!xx_rt_wcscmp(r->name,L"name_crc"))return xx_data_struct_record_set_comment(r,L"Resource-name CRC used as a lookup key.");
 if(id==sxga_xzp_name.id&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_xzp_name.id&&!xx_rt_wcscmp(r->name,L"created"))return xx_data_struct_record_set_comment(r,L"Stored creation time in Unix seconds.");
 if(id==sxga_pbo_entry.id&&!xx_rt_wcscmp(r->name,L"modified"))return xx_data_struct_record_set_comment(r,L"Stored Unix timestamp in seconds.");
 if(id==sxga_majiro_header.id&&!xx_rt_wcscmp(r->name,L"names_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_majiro_header.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_majiro_entry1.id&&!xx_rt_wcscmp(r->name,L"name_hash"))return xx_data_struct_record_set_comment(r,L"Resource-name lookup hash; not a payload checksum.");
 if(id==sxga_majiro_entry1.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_majiro_entry2.id&&!xx_rt_wcscmp(r->name,L"name_hash"))return xx_data_struct_record_set_comment(r,L"Resource-name lookup hash; not a payload checksum.");
 if(id==sxga_majiro_entry2.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_majiro_entry3.id&&!xx_rt_wcscmp(r->name,L"name_hash"))return xx_data_struct_record_set_comment(r,L"64-bit resource-name lookup hash; not a payload checksum.");
 if(id==sxga_majiro_entry3.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_nexas_entry32.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_nexas_entry64.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_tt_chunk_offset.id&&!xx_rt_wcscmp(r->name,L"offset"))return xx_data_struct_record_set_comment(r,L"Stored byte boundary. Physical chunk offset is table-end plus this value minus the first stored boundary.");
 if(id==sxga_tt_entry.id&&!xx_rt_wcscmp(r->name,L"name_crc64"))return xx_data_struct_record_set_comment(r,L"CRC64 of the resource name; not a payload checksum.");
 if(id==sxga_tt_entry.id&&!xx_rt_wcscmp(r->name,L"relative_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the end of the inner name table.");
 if(id==sxga_tt_entry.id&&!xx_rt_wcscmp(r->name,L"name_page"))return xx_data_struct_record_set_comment(r,L"Index of a 65536-byte name-pool page.");
 if(id==sxga_tt_entry.id&&!xx_rt_wcscmp(r->name,L"name_offset_in_page"))return xx_data_struct_record_set_comment(r,L"Byte offset within the selected 65536-byte name page.");
 if(id==sxga_ipak_offset.id&&!xx_rt_wcscmp(r->name,L"record_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_ipak_local_crumb.id&&!xx_rt_wcscmp(r->name,L"dos_time"))return xx_data_struct_record_set_comment(r,L"Packed DOS time: hours5, minutes6, two-second count5.");
 if(id==sxga_ipak_local_crumb.id&&!xx_rt_wcscmp(r->name,L"dos_date"))return xx_data_struct_record_set_comment(r,L"Packed DOS date: year since1980, month4, day5.");
 if(id==sxga_ipak_local_crumb.id&&!xx_rt_wcscmp(r->name,L"crc32_low"))return xx_data_struct_record_set_comment(r,L"Stored low16 bits of an unverified CRC32; crumbs can be reused by producers.");
 if(id==sxga_ipak_central_crumb.id&&!xx_rt_wcscmp(r->name,L"dos_time"))return xx_data_struct_record_set_comment(r,L"Packed DOS time: hours5, minutes6, two-second count5.");
 if(id==sxga_ipak_central_crumb.id&&!xx_rt_wcscmp(r->name,L"dos_date"))return xx_data_struct_record_set_comment(r,L"Packed DOS date: year since1980, month4, day5.");
 if(id==sxga_bsp_lump.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxga_bsp_node.id&&!xx_rt_wcscmp(r->name,L"child0"))return xx_data_struct_record_set_comment(r,L"Node index; a negative value encodes -(leaf_index+1).");
 if(id==sxga_bsp_node.id&&!xx_rt_wcscmp(r->name,L"child1"))return xx_data_struct_record_set_comment(r,L"Node index; a negative value encodes -(leaf_index+1).");
 if(id==sxga_bsp_face.id&&!xx_rt_wcscmp(r->name,L"light_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset into the lighting lump; -1 denotes no light samples.");
 if(id==sxga_bsp_clipnode.id&&!xx_rt_wcscmp(r->name,L"child0"))return xx_data_struct_record_set_comment(r,L"Clipnode index; a negative value is a contents code.");
 if(id==sxga_bsp_clipnode.id&&!xx_rt_wcscmp(r->name,L"child1"))return xx_data_struct_record_set_comment(r,L"Clipnode index; a negative value is a contents code.");
 if(id==sxga_bsp_leaf.id&&!xx_rt_wcscmp(r->name,L"visibility_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset into the visibility lump; -1 denotes no visibility data.");
 if(id==sxga_bsp_surfedge.id&&!xx_rt_wcscmp(r->name,L"edge"))return xx_data_struct_record_set_comment(r,L"Signed edge index; the sign selects traversal direction.");
 if(id==sxga_bsp_texture_offset.id&&!xx_rt_wcscmp(r->name,L"texture_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the texture lump; -1 denotes an absent texture.");
 if(id==sxga_bsp_miptex.id&&!xx_rt_wcscmp(r->name,L"mip0_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this miptex header.");
 if(id==sxga_bsp_miptex.id&&!xx_rt_wcscmp(r->name,L"mip1_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this miptex header.");
 if(id==sxga_bsp_miptex.id&&!xx_rt_wcscmp(r->name,L"mip2_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this miptex header.");
 if(id==sxga_bsp_miptex.id&&!xx_rt_wcscmp(r->name,L"mip3_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this miptex header.");
 if(id==sxga_pbo_entry.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(1131442803):return xx_data_struct_record_set_comment(r,L"Cprs compressed member");
 case UINT64_C(1449489011):return xx_data_struct_record_set_comment(r,L"Vers property extension");
 default:break;}}
 if(id==sxga_nsa_entry.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"SPB image");
 case UINT64_C(2):return xx_data_struct_record_set_comment(r,L"LZSS");
 case UINT64_C(4):return xx_data_struct_record_set_comment(r,L"NBZ bzip2");
 default:break;}}
 if(id==sxga_agis_entry.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"DCL binary");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"DCL ASCII");
 case UINT64_C(255):return xx_data_struct_record_set_comment(r,L"Stored");
 default:break;}}
 if(id==sxga_ea_entry.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"12-bit LZW");
 default:break;}}
 if(id==sxga_epf_entry.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"LZW");
 default:break;}}
 if(id==sxga_ipak_entry.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"Infogrames implode");
 case UINT64_C(4):return xx_data_struct_record_set_comment(r,L"Raw Deflate");
 default:break;}}
 if(id==sxga_nexas_header.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"LZSS");
 case UINT64_C(2):return xx_data_struct_record_set_comment(r,L"Huffman");
 case UINT64_C(3):return xx_data_struct_record_set_comment(r,L"zlib");
 case UINT64_C(4):return xx_data_struct_record_set_comment(r,L"Stored if sizes match; otherwise zlib");
 default:break;}}
 if(id==sxga_stunts_pass.id&&!xx_rt_wcscmp(r->name,L"codec")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"Run length encoding");
 case UINT64_C(2):return xx_data_struct_record_set_comment(r,L"Variable-length codes");
 default:break;}}
 if(id==sxga_silmarils_header_le.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(129):return xx_data_struct_record_set_comment(r,L"Byte-run codec");
 case UINT64_C(161):return xx_data_struct_record_set_comment(r,L"Bit-stream LZ");
 default:break;}}
 if(id==sxga_silmarils_header_be.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(129):return xx_data_struct_record_set_comment(r,L"Byte-run codec");
 case UINT64_C(161):return xx_data_struct_record_set_comment(r,L"Bit-stream LZ");
 default:break;}}
 if(id==sxga_bsp_plane.id&&!xx_rt_wcscmp(r->name,L"type")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"PLANE_X");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"PLANE_Y");
 case UINT64_C(2):return xx_data_struct_record_set_comment(r,L"PLANE_Z");
 case UINT64_C(3):return xx_data_struct_record_set_comment(r,L"PLANE_ANYX");
 case UINT64_C(4):return xx_data_struct_record_set_comment(r,L"PLANE_ANYY");
 case UINT64_C(5):return xx_data_struct_record_set_comment(r,L"PLANE_ANYZ");
 default:break;}}
 if(id==sxga_dcp_header.id&&!xx_rt_wcscmp(r->name,L"package_version")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(256):return xx_data_struct_record_set_comment(r,L"Wintermute DCP version1");
 case UINT64_C(512):return xx_data_struct_record_set_comment(r,L"Wintermute DCP version2");
 default:break;}}
 return true;}
