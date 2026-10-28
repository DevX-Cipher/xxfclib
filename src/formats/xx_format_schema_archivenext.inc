/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivenext_scope.txt. */
static const xx_data_struct_field_desc sxan_is3_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("reserved","uint16",6,2,SX_NONE),
 SX_FIELD("unknown1","uint8[4]",8,4,SX_NONE),
 SX_FIELD("member_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("timestamp","uint32",14,4,SX_NONE),
 SX_FIELD("archive_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",26,4,SX_OFFSET),
 SX_FIELD("unknown2","uint8[11]",30,11,SX_NONE),
 SX_FIELD("directory_offset","uint32",41,4,SX_OFFSET),
 SX_FIELD("directory_size","uint32",45,4,SX_SIZE),
 SX_FIELD("directory_count","uint16",49,2,SX_COUNT_PROP),
 SX_FIELD("file_table_offset","uint32",51,4,SX_OFFSET),
 SX_FIELD("file_table_size","uint32",55,4,SX_SIZE),
};
static const sx_layout sxan_is3_header = {UINT32_C(0x60770001),"is3_header",sxan_is3_header_fields,SX_COUNT(sxan_is3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_directory_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("entry_size","uint16",2,2,SX_SIZE),
 SX_FIELD("name_size","uint16",4,2,SX_SIZE),
};
static const sx_layout sxan_is3_directory = {UINT32_C(0x60770002),"is3_directory",sxan_is3_directory_fields,SX_COUNT(sxan_is3_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_member_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","uint16",1,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",3,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",11,4,SX_OFFSET),
 SX_FIELD("timestamp","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint32",19,4,SX_FLAGS),
 SX_FIELD("entry_size","uint16",23,2,SX_SIZE),
 SX_FIELD("volume","uint16",25,2,SX_NONE),
 SX_FIELD("unknown","uint16",27,2,SX_NONE),
 SX_FIELD("name_size","uint8",29,1,SX_SIZE),
};
static const sx_layout sxan_is3_member = {UINT32_C(0x60770003),"is3_member",sxan_is3_member_fields,SX_COUNT(sxan_is3_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_payload_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("copyright","char[70]",8,70,SX_NONE),
 SX_FIELD("member_count","uint32",78,4,SX_COUNT_PROP),
};
static const sx_layout sxan_is3_payload_header = {UINT32_C(0x60770004),"is3_payload_header",sxan_is3_payload_header_fields,SX_COUNT(sxan_is3_payload_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_payload_member_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("reserved1","uint32",12,4,SX_NONE),
 SX_FIELD("reserved2","uint32",16,4,SX_NONE),
 SX_FIELD("name_size","uint16",20,2,SX_SIZE),
};
static const sx_layout sxan_is3_payload_member = {UINT32_C(0x60770005),"is3_payload_member",sxan_is3_payload_member_fields,SX_COUNT(sxan_is3_payload_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_second_name_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxan_is3_second_name = {UINT32_C(0x60770006),"is3_second_name",sxan_is3_second_name_fields,SX_COUNT(sxan_is3_second_name_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("volume_info","uint32",8,4,SX_FLAGS),
 SX_FIELD("descriptor_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("descriptor_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxan_is5_header = {UINT32_C(0x60770007),"is5_header",sxan_is5_header_fields,SX_COUNT(sxan_is5_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_descriptor_fields[] = {
 SX_FIELD("unknown0","uint8[12]",0,12,SX_NONE),
 SX_FIELD("file_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("unknown1","uint32",16,4,SX_NONE),
 SX_FIELD("file_table_size","uint32",20,4,SX_SIZE),
 SX_FIELD("repeated_table_size","uint32",24,4,SX_SIZE),
 SX_FIELD("directory_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("unknown2","uint8[8]",32,8,SX_NONE),
 SX_FIELD("member_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("second_table_offset","uint32",44,4,SX_OFFSET),
};
static const sx_layout sxan_is5_descriptor = {UINT32_C(0x60770008),"is5_descriptor",sxan_is5_descriptor_fields,SX_COUNT(sxan_is5_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_member_v5_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("directory_index","uint32",4,4,SX_NONE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
 SX_FIELD("uncompressed_size","uint32",10,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",14,4,SX_SIZE),
 SX_FIELD("unknown","uint8[20]",18,20,SX_NONE),
 SX_FIELD("data_offset","uint32",38,4,SX_OFFSET),
};
static const sx_layout sxan_is5_member_v5 = {UINT32_C(0x60770009),"is5_member_v5",sxan_is5_member_v5_fields,SX_COUNT(sxan_is5_member_v5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_member_v6_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("uncompressed_size","uint64",2,8,SX_SIZE),
 SX_FIELD("compressed_size","uint64",10,8,SX_SIZE),
 SX_FIELD("data_offset","uint64",18,8,SX_OFFSET),
 SX_FIELD("md5","uint8[16]",26,16,SX_CHECKSUM),
 SX_FIELD("unknown1","uint8[16]",42,16,SX_NONE),
 SX_FIELD("name_offset","uint32",58,4,SX_OFFSET),
 SX_FIELD("directory_index","uint16",62,2,SX_NONE),
 SX_FIELD("unknown2","uint8[23]",64,23,SX_NONE),
};
static const sx_layout sxan_is5_member_v6 = {UINT32_C(0x6077000a),"is5_member_v6",sxan_is5_member_v6_fields,SX_COUNT(sxan_is5_member_v6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is5_table_offset_fields[] = {
 SX_FIELD("entry_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxan_is5_table_offset = {UINT32_C(0x6077000b),"is5_table_offset",sxan_is5_table_offset_fields,SX_COUNT(sxan_is5_table_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is11_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("format_version","uint32",4,4,SX_NONE),
 SX_FIELD("variant","uint8",8,1,SX_NONE),
 SX_FIELD("reserved","uint32",9,4,SX_NONE),
};
static const sx_layout sxan_is11_header = {UINT32_C(0x6077000c),"is11_header",sxan_is11_header_fields,SX_COUNT(sxan_is11_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is11_member_v1_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("compressed_size","int32",1,4,SX_SIZE),
 SX_FIELD("next_offset","int32",5,4,SX_OFFSET),
 SX_FIELD("reserved","uint16",9,2,SX_NONE),
 SX_FIELD("name_size","uint8",11,1,SX_SIZE),
};
static const sx_layout sxan_is11_member_v1 = {UINT32_C(0x6077000d),"is11_member_v1",sxan_is11_member_v1_fields,SX_COUNT(sxan_is11_member_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is11_member_v3_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("compressed_size","int32",1,4,SX_SIZE),
 SX_FIELD("next_offset","int32",5,4,SX_OFFSET),
 SX_FIELD("dos_date","uint16",9,2,SX_NONE),
 SX_FIELD("dos_time","uint16",11,2,SX_NONE),
 SX_FIELD("reserved","uint16",13,2,SX_NONE),
 SX_FIELD("name_size","uint8",15,1,SX_SIZE),
};
static const sx_layout sxan_is11_member_v3 = {UINT32_C(0x6077000e),"is11_member_v3",sxan_is11_member_v3_fields,SX_COUNT(sxan_is11_member_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_gksetup_banner_fields[] = {
 SX_FIELD("banner","char[39]",0,39,SX_SIGNATURE),
};
static const sx_layout sxan_gksetup_banner = {UINT32_C(0x6077000f),"gksetup_banner",sxan_gksetup_banner_fields,SX_COUNT(sxan_gksetup_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxan_gksetup_signature_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
};
static const sx_layout sxan_gksetup_signature = {UINT32_C(0x60770010),"gksetup_signature",sxan_gksetup_signature_fields,SX_COUNT(sxan_gksetup_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_gksetup_data_offset_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxan_gksetup_data_offset = {UINT32_C(0x60770011),"gksetup_data_offset",sxan_gksetup_data_offset_fields,SX_COUNT(sxan_gksetup_data_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_gksetup_member_fields[] = {
 SX_FIELD("name","char[260]",0,260,SX_NONE),
 SX_FIELD("attributes","uint32",260,4,SX_FLAGS),
 SX_FIELD("creation_time","uint64",264,8,SX_NONE),
 SX_FIELD("access_time","uint64",272,8,SX_NONE),
 SX_FIELD("modification_time","uint64",280,8,SX_NONE),
 SX_FIELD("payload_size","int32",288,4,SX_SIZE),
};
static const sx_layout sxan_gksetup_member = {UINT32_C(0x60770012),"gksetup_member",sxan_gksetup_member_fields,SX_COUNT(sxan_gksetup_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pcinstall_header_fields[] = {
 SX_FIELD("zero","uint8[13]",0,13,SX_NONE),
 SX_FIELD("tag","uint8",13,1,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("tag2","uint32",16,4,SX_SIGNATURE),
 SX_FIELD("reserved","uint8[36]",20,36,SX_NONE),
};
static const sx_layout sxan_pcinstall_header = {UINT32_C(0x60770013),"pcinstall_header",sxan_pcinstall_header_fields,SX_COUNT(sxan_pcinstall_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pcinstall_member_fields[] = {
 SX_FIELD("name","char[20]",0,20,SX_NONE),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",24,2,SX_NONE),
 SX_FIELD("dos_time","uint16",26,2,SX_NONE),
 SX_FIELD("reserved","uint8[20]",28,20,SX_NONE),
};
static const sx_layout sxan_pcinstall_member = {UINT32_C(0x60770014),"pcinstall_member",sxan_pcinstall_member_fields,SX_COUNT(sxan_pcinstall_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_finstall_header_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("signature","char[10]",1,10,SX_SIGNATURE),
 SX_FIELD("version","char[1]",11,1,SX_NONE),
 SX_FIELD("capacity","uint32",12,4,SX_SIZE),
 SX_FIELD("member_count","uint16",16,2,SX_COUNT_PROP),
};
static const sx_layout sxan_finstall_header = {UINT32_C(0x60770015),"finstall_header",sxan_finstall_header_fields,SX_COUNT(sxan_finstall_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_finstall_member_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("name","char[16]",8,16,SX_NONE),
};
static const sx_layout sxan_finstall_member = {UINT32_C(0x60770016),"finstall_member",sxan_finstall_member_fields,SX_COUNT(sxan_finstall_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ifah_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("declared_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown1","uint32",8,4,SX_NONE),
 SX_FIELD("unknown2","uint8",12,1,SX_NONE),
 SX_FIELD("member_count","uint32",13,4,SX_COUNT_PROP),
};
static const sx_layout sxan_ifah_header = {UINT32_C(0x60770017),"ifah_header",sxan_ifah_header_fields,SX_COUNT(sxan_ifah_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ifah_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("dos_time","uint16",16,2,SX_NONE),
 SX_FIELD("dos_date","uint16",18,2,SX_NONE),
 SX_FIELD("version_high","uint32",20,4,SX_NONE),
 SX_FIELD("version_low","uint32",24,4,SX_NONE),
 SX_FIELD("name_size","uint8",28,1,SX_SIZE),
};
static const sx_layout sxan_ifah_member = {UINT32_C(0x60770018),"ifah_member",sxan_ifah_member_fields,SX_COUNT(sxan_ifah_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osetup_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("modification_time","uint32",8,4,SX_TIME),
 SX_FIELD("name","char[13]",12,13,SX_NONE),
 SX_FIELD("writer_memory","uint8[19]",25,19,SX_NONE),
};
static const sx_layout sxan_osetup_member = {UINT32_C(0x60770019),"osetup_member",sxan_osetup_member_fields,SX_COUNT(sxan_osetup_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osetup_trailer_6_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("first_record_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("member_count","uint16",10,2,SX_COUNT_PROP),
};
static const sx_layout sxan_osetup_trailer_6 = {UINT32_C(0x6077001a),"osetup_trailer_6",sxan_osetup_trailer_6_fields,SX_COUNT(sxan_osetup_trailer_6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osetup_trailer_8_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_record_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("member_count","uint16",12,2,SX_COUNT_PROP),
};
static const sx_layout sxan_osetup_trailer_8 = {UINT32_C(0x6077001b),"osetup_trailer_8",sxan_osetup_trailer_8_fields,SX_COUNT(sxan_osetup_trailer_8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_member_fields[] = {
 SX_FIELD("next_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("dos_time","uint16",8,2,SX_NONE),
 SX_FIELD("time_padding","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("date_padding","uint16",14,2,SX_NONE),
 SX_FIELD("payload_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name","char[256]",20,256,SX_NONE),
};
static const sx_layout sxan_pc_install_member = {UINT32_C(0x6077001c),"pc_install_member",sxan_pc_install_member_fields,SX_COUNT(sxan_pc_install_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_trailer_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_record_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("last_record_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxan_pc_install_trailer = {UINT32_C(0x6077001d),"pc_install_trailer",sxan_pc_install_trailer_fields,SX_COUNT(sxan_pc_install_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_group_fields[] = {
 SX_FIELD("cross_volume","uint8[14]",0,14,SX_NONE),
 SX_FIELD("marker1","uint16",14,2,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("marker2","uint16",18,2,SX_SIGNATURE),
 SX_FIELD("reserved","uint8[38]",20,38,SX_NONE),
};
static const sx_layout sxan_pc_install_group = {UINT32_C(0x6077001e),"pc_install_group",sxan_pc_install_group_fields,SX_COUNT(sxan_pc_install_group_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_group_member_fields[] = {
 SX_FIELD("name","char[128]",0,128,SX_NONE),
 SX_FIELD("attributes","uint32",128,4,SX_FLAGS),
 SX_FIELD("reserved1","uint32",132,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",136,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",140,2,SX_NONE),
 SX_FIELD("date_padding","uint16",142,2,SX_NONE),
 SX_FIELD("dos_time","uint16",144,2,SX_NONE),
 SX_FIELD("time_padding","uint16",146,2,SX_NONE),
 SX_FIELD("unknown","uint8[8]",148,8,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",156,4,SX_SIZE),
 SX_FIELD("unknown_tail","uint8[8]",160,8,SX_NONE),
};
static const sx_layout sxan_pc_install_group_member = {UINT32_C(0x6077001f),"pc_install_group_member",sxan_pc_install_group_member_fields,SX_COUNT(sxan_pc_install_group_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_rtpatch_setup_member_fields[] = {
 SX_FIELD("compressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("attributes","uint16",8,2,SX_FLAGS),
 SX_FIELD("dos_date","uint16",10,2,SX_NONE),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("name_size","uint16",14,2,SX_SIZE),
};
static const sx_layout sxan_rtpatch_setup_member = {UINT32_C(0x60770020),"rtpatch_setup_member",sxan_rtpatch_setup_member_fields,SX_COUNT(sxan_rtpatch_setup_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_spoon_footer_fields[] = {
 SX_FIELD("unknown1","uint32",0,4,SX_NONE),
 SX_FIELD("unknown2","uint32",4,4,SX_NONE),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("signature","uint8[8]",16,8,SX_SIGNATURE),
};
static const sx_layout sxan_spoon_footer = {UINT32_C(0x60770021),"spoon_footer",sxan_spoon_footer_fields,SX_COUNT(sxan_spoon_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxan_spoon_member_fields[] = {
 SX_FIELD("stream_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("byte_sum","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",16,1,SX_SIZE),
};
static const sx_layout sxan_spoon_member = {UINT32_C(0x60770022),"spoon_member",sxan_spoon_member_fields,SX_COUNT(sxan_spoon_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_issetup_header_fields[] = {
 SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("version","uint8",16,1,SX_NONE),
 SX_FIELD("reserved","uint8[29]",17,29,SX_NONE),
};
static const sx_layout sxan_issetup_header = {UINT32_C(0x60770023),"issetup_header",sxan_issetup_header_fields,SX_COUNT(sxan_issetup_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_issetup_member_fields[] = {
 SX_FIELD("name_size","uint32",0,4,SX_SIZE),
 SX_FIELD("cipher_selector","uint32",4,4,SX_NONE),
 SX_FIELD("reserved1","uint16",8,2,SX_NONE),
 SX_FIELD("stream_size","uint32",10,4,SX_SIZE),
 SX_FIELD("reserved2","uint64",14,8,SX_NONE),
 SX_FIELD("storage","uint16",22,2,SX_NONE),
};
static const sx_layout sxan_issetup_member = {UINT32_C(0x60770024),"issetup_member",sxan_issetup_member_fields,SX_COUNT(sxan_issetup_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_epsf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("runtime_size","uint32",6,4,SX_SIZE),
 SX_FIELD("runtime_packed_size","uint32",10,4,SX_SIZE),
 SX_FIELD("runtime_byte_sum","uint32",14,4,SX_CHECKSUM),
};
static const sx_layout sxan_epsf_header = {UINT32_C(0x60770025),"epsf_header",sxan_epsf_header_fields,SX_COUNT(sxan_epsf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_setup_factory_header_fields[] = {
 SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
 SX_FIELD("engine_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxan_setup_factory_header = {UINT32_C(0x60770026),"setup_factory_header",sxan_setup_factory_header_fields,SX_COUNT(sxan_setup_factory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_setup_factory_engine_16_fields[] = {
 SX_FIELD("name","char[16]",0,16,SX_NONE),
 SX_FIELD("compressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("crc32","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxan_setup_factory_engine_16 = {UINT32_C(0x60770027),"setup_factory_engine_16",sxan_setup_factory_engine_16_fields,SX_COUNT(sxan_setup_factory_engine_16_fields),SX_LE};
static const xx_data_struct_field_desc sxan_setup_factory_engine_260_fields[] = {
 SX_FIELD("name","char[260]",0,260,SX_NONE),
 SX_FIELD("compressed_size","uint32",260,4,SX_SIZE),
 SX_FIELD("crc32","uint32",264,4,SX_CHECKSUM),
};
static const sx_layout sxan_setup_factory_engine_260 = {UINT32_C(0x60770028),"setup_factory_engine_260",sxan_setup_factory_engine_260_fields,SX_COUNT(sxan_setup_factory_engine_260_fields),SX_LE};
static const xx_data_struct_field_desc sxan_westwood_offset_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxan_westwood_offset = {UINT32_C(0x60770029),"westwood_offset",sxan_westwood_offset_fields,SX_COUNT(sxan_westwood_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ckpedp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("member_count","uint32",6,4,SX_COUNT_PROP),
 SX_FIELD("unknown","uint32",10,4,SX_NONE),
};
static const sx_layout sxan_ckpedp_header = {UINT32_C(0x6077002a),"ckpedp_header",sxan_ckpedp_header_fields,SX_COUNT(sxan_ckpedp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ckpedp_name_size_fields[] = {
 SX_FIELD("name_units","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxan_ckpedp_name_size = {UINT32_C(0x6077002b),"ckpedp_name_size",sxan_ckpedp_name_size_fields,SX_COUNT(sxan_ckpedp_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ckpedp_member_tail_fields[] = {
 SX_FIELD("unknown","uint8[8]",0,8,SX_NONE),
 SX_FIELD("reserved","uint32",8,4,SX_NONE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxan_ckpedp_member_tail = {UINT32_C(0x6077002c),"ckpedp_member_tail",sxan_ckpedp_member_tail_fields,SX_COUNT(sxan_ckpedp_member_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ckpedp_encoded_name_fields[] = {
 SX_FIELD("encoded_name","uint8",0,0,SX_NONE),
};
static const sx_layout sxan_ckpedp_encoded_name = {UINT32_C(0x6077002d),"ckpedp_encoded_name",sxan_ckpedp_encoded_name_fields,SX_COUNT(sxan_ckpedp_encoded_name_fields),SX_LE};
static const xx_data_struct_field_desc sxan_parsec_rib_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxan_parsec_rib_header = {UINT32_C(0x6077002e),"parsec_rib_header",sxan_parsec_rib_header_fields,SX_COUNT(sxan_parsec_rib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_parsec_member_offset_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxan_parsec_member_offset = {UINT32_C(0x6077002f),"parsec_member_offset",sxan_parsec_member_offset_fields,SX_COUNT(sxan_parsec_member_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_parsec_member_size_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxan_parsec_member_size = {UINT32_C(0x60770030),"parsec_member_size",sxan_parsec_member_size_fields,SX_COUNT(sxan_parsec_member_size_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ptero_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("marker","char[3]",5,3,SX_SIGNATURE),
 SX_FIELD("archive_size","uint64",8,8,SX_SIZE),
 SX_FIELD("member_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("directory_offset","uint64",20,8,SX_OFFSET),
 SX_FIELD("directory_size","uint64",28,8,SX_SIZE),
 SX_FIELD("data_offset","uint64",36,8,SX_OFFSET),
 SX_FIELD("unknown","uint8[20]",44,20,SX_NONE),
};
static const sx_layout sxan_ptero_header = {UINT32_C(0x60770031),"ptero_header",sxan_ptero_header_fields,SX_COUNT(sxan_ptero_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ptero_member_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("marker","uint32",8,4,SX_NONE),
 SX_FIELD("timestamp","uint64",12,8,SX_NONE),
 SX_FIELD("uncompressed_size","uint64",20,8,SX_SIZE),
 SX_FIELD("compressed_size","uint32",28,4,SX_SIZE),
 SX_FIELD("method","uint32",32,4,SX_NONE),
 SX_FIELD("unknown","uint32",36,4,SX_NONE),
};
static const sx_layout sxan_ptero_member = {UINT32_C(0x60770032),"ptero_member",sxan_ptero_member_fields,SX_COUNT(sxan_ptero_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ptero_block_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxan_ptero_block = {UINT32_C(0x60770033),"ptero_block",sxan_ptero_block_fields,SX_COUNT(sxan_ptero_block_fields),SX_LE};
static const xx_data_struct_field_desc sxan_titan_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("block_table_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name_table_size","uint32",20,4,SX_SIZE),
 SX_FIELD("block_table_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("unknown","uint32",28,4,SX_NONE),
};
static const sx_layout sxan_titan_header = {UINT32_C(0x60770034),"titan_header",sxan_titan_header_fields,SX_COUNT(sxan_titan_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_titan_block_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxan_titan_block = {UINT32_C(0x60770035),"titan_block",sxan_titan_block_fields,SX_COUNT(sxan_titan_block_fields),SX_LE};
static const xx_data_struct_field_desc sxan_titan_member_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_NONE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("adler32","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("unknown","uint8[8]",20,8,SX_NONE),
 SX_FIELD("block_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("first_block_index","uint32",32,4,SX_NONE),
 SX_FIELD("name_size","uint32",36,4,SX_SIZE),
 SX_FIELD("name_offset","uint32",40,4,SX_OFFSET),
};
static const sx_layout sxan_titan_member = {UINT32_C(0x60770036),"titan_member",sxan_titan_member_fields,SX_COUNT(sxan_titan_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_cgjp_signature_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxan_cgjp_signature = {UINT32_C(0x60770037),"cgjp_signature",sxan_cgjp_signature_fields,SX_COUNT(sxan_cgjp_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_cgjp_block_fields[] = {
 SX_FIELD("uncompressed_size","uint16",0,2,SX_SIZE),
 SX_FIELD("compressed_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxan_cgjp_block = {UINT32_C(0x60770038),"cgjp_block",sxan_cgjp_block_fields,SX_COUNT(sxan_cgjp_block_fields),SX_LE};
static const xx_data_struct_field_desc sxan_birdies_header_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("member_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxan_birdies_header = {UINT32_C(0x60770039),"birdies_header",sxan_birdies_header_fields,SX_COUNT(sxan_birdies_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_birdies_member_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxan_birdies_member = {UINT32_C(0x6077003a),"birdies_member",sxan_birdies_member_fields,SX_COUNT(sxan_birdies_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_xuiz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("archive_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
 SX_FIELD("directory_size","uint32",16,4,SX_SIZE),
 SX_FIELD("member_count","uint16",20,2,SX_COUNT_PROP),
};
static const sx_layout sxan_xuiz_header = {UINT32_C(0x6077003b),"xuiz_header",sxan_xuiz_header_fields,SX_COUNT(sxan_xuiz_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_xuiz_member_0_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("name_units","uint8",8,1,SX_COUNT_PROP),
};
static const sx_layout sxan_xuiz_member_0 = {UINT32_C(0x6077003c),"xuiz_member_0",sxan_xuiz_member_0_fields,SX_COUNT(sxan_xuiz_member_0_fields),SX_BE};
static const xx_data_struct_field_desc sxan_xuiz_member_10_fields[] = {
 SX_FIELD("unknown","uint8[10]",0,10,SX_NONE),
 SX_FIELD("payload_size","uint32",10,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",14,4,SX_OFFSET),
 SX_FIELD("name_units","uint8",18,1,SX_COUNT_PROP),
};
static const sx_layout sxan_xuiz_member_10 = {UINT32_C(0x6077003d),"xuiz_member_10",sxan_xuiz_member_10_fields,SX_COUNT(sxan_xuiz_member_10_fields),SX_BE};
static const xx_data_struct_field_desc sxan_dcs_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxan_dcs_header = {UINT32_C(0x6077003e),"dcs_header",sxan_dcs_header_fields,SX_COUNT(sxan_dcs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_dcs_block_fields[] = {
 SX_FIELD("stored_size","uint32",0,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxan_dcs_block = {UINT32_C(0x6077003f),"dcs_block",sxan_dcs_block_fields,SX_COUNT(sxan_dcs_block_fields),SX_LE};
static const xx_data_struct_field_desc sxan_audials_count_fields[] = {
 SX_FIELD("member_count","ascii_decimal",0,0,SX_COUNT_PROP),
};
static const sx_layout sxan_audials_count = {UINT32_C(0x60770040),"audials_count",sxan_audials_count_fields,SX_COUNT(sxan_audials_count_fields),SX_LE};
static const xx_data_struct_field_desc sxan_audials_offset_fields[] = {
 SX_FIELD("data_offset","ascii_decimal",0,0,SX_OFFSET),
};
static const sx_layout sxan_audials_offset = {UINT32_C(0x60770041),"audials_offset",sxan_audials_offset_fields,SX_COUNT(sxan_audials_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_audials_size_fields[] = {
 SX_FIELD("payload_size","ascii_decimal",0,0,SX_SIZE),
};
static const sx_layout sxan_audials_size = {UINT32_C(0x60770042),"audials_size",sxan_audials_size_fields,SX_COUNT(sxan_audials_size_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_name_fields[] = {
 SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxan_archivenext_name = {UINT32_C(0x60770043),"archivenext_name",sxan_archivenext_name_fields,SX_COUNT(sxan_archivenext_name_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_utf16le_fields[] = {
 SX_FIELD("name_units","uint16",0,0,SX_NONE),
};
static const sx_layout sxan_archivenext_utf16le = {UINT32_C(0x60770044),"archivenext_utf16le",sxan_archivenext_utf16le_fields,SX_COUNT(sxan_archivenext_utf16le_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_utf16be_fields[] = {
 SX_FIELD("name_units","uint16",0,0,SX_NONE),
};
static const sx_layout sxan_archivenext_utf16be = {UINT32_C(0x60770045),"archivenext_utf16be",sxan_archivenext_utf16be_fields,SX_COUNT(sxan_archivenext_utf16be_fields),SX_BE};
static const xx_data_struct_field_desc sxan_is5_volume_prefix_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
 SX_FIELD("first_file_index","uint32",8,4,SX_NONE),
 SX_FIELD("last_file_index","uint32",12,4,SX_NONE),
};
static const sx_layout sxan_is5_volume_prefix = {UINT32_C(0x60770046),"is5_volume_prefix",sxan_is5_volume_prefix_fields,SX_COUNT(sxan_is5_volume_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_padding32_fields[] = {
 SX_FIELD("padding","uint32",0,4,SX_NONE),
};
static const sx_layout sxan_archivenext_padding32 = {UINT32_C(0x60770047),"archivenext_padding32",sxan_archivenext_padding32_fields,SX_COUNT(sxan_archivenext_padding32_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_separator_fields[] = {
 SX_FIELD("separator","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_archivenext_separator = {UINT32_C(0x60770048),"archivenext_separator",sxan_archivenext_separator_fields,SX_COUNT(sxan_archivenext_separator_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pc_install_tag_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxan_pc_install_tag = {UINT32_C(0x60770049),"pc_install_tag",sxan_pc_install_tag_fields,SX_COUNT(sxan_pc_install_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxan_wad_header_fields[] = {
 SX_FIELD("header_size","uint32",0,4,SX_SIZE),
 SX_FIELD("type","char[2]",4,2,SX_NONE),
 SX_FIELD("version","uint16",6,2,SX_NONE),
 SX_FIELD("certificate_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crl_size","uint32",12,4,SX_SIZE),
 SX_FIELD("ticket_size","uint32",16,4,SX_SIZE),
 SX_FIELD("tmd_size","uint32",20,4,SX_SIZE),
 SX_FIELD("data_size","uint32",24,4,SX_SIZE),
 SX_FIELD("footer_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxan_wad_header = {UINT32_C(0x6077004a),"wad_header",sxan_wad_header_fields,SX_COUNT(sxan_wad_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_rsa2048_fields[] = {
 SX_FIELD("signature_type","uint32",0,4,SX_NONE),
 SX_FIELD("signature","uint8[256]",4,256,SX_NONE),
 SX_FIELD("padding","uint8[60]",260,60,SX_NONE),
};
static const sx_layout sxan_wad_rsa2048 = {UINT32_C(0x6077004b),"wad_rsa2048",sxan_wad_rsa2048_fields,SX_COUNT(sxan_wad_rsa2048_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_ticket_fields[] = {
 SX_FIELD("issuer","char[64]",0,64,SX_NONE),
 SX_FIELD("unknown","uint8[63]",64,63,SX_NONE),
 SX_FIELD("encrypted_title_key","uint8[16]",127,16,SX_NONE),
 SX_FIELD("reserved1","uint8",143,1,SX_NONE),
 SX_FIELD("ticket_id","uint64",144,8,SX_NONE),
 SX_FIELD("device_type","uint32",152,4,SX_NONE),
 SX_FIELD("title_id","uint64",156,8,SX_NONE),
 SX_FIELD("access_mask","uint16",164,2,SX_FLAGS),
 SX_FIELD("reserved2","uint8[60]",166,60,SX_NONE),
 SX_FIELD("content_index_mask","uint8[64]",226,64,SX_FLAGS),
 SX_FIELD("padding","uint16",290,2,SX_NONE),
};
static const sx_layout sxan_wad_ticket = {UINT32_C(0x6077004c),"wad_ticket",sxan_wad_ticket_fields,SX_COUNT(sxan_wad_ticket_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_limit_fields[] = {
 SX_FIELD("tag","uint32",0,4,SX_NONE),
 SX_FIELD("value","uint32",4,4,SX_NONE),
};
static const sx_layout sxan_wad_limit = {UINT32_C(0x6077004d),"wad_limit",sxan_wad_limit_fields,SX_COUNT(sxan_wad_limit_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_tmd_fields[] = {
 SX_FIELD("issuer","char[64]",0,64,SX_NONE),
 SX_FIELD("version","uint8",64,1,SX_NONE),
 SX_FIELD("ca_crl_version","uint8",65,1,SX_NONE),
 SX_FIELD("signer_crl_version","uint8",66,1,SX_NONE),
 SX_FIELD("vwii_title","uint8",67,1,SX_NONE),
 SX_FIELD("system_version","uint64",68,8,SX_NONE),
 SX_FIELD("title_id","uint64",76,8,SX_NONE),
 SX_FIELD("title_type","uint32",84,4,SX_FLAGS),
 SX_FIELD("group_id","uint16",88,2,SX_NONE),
 SX_FIELD("zero","uint16",90,2,SX_NONE),
 SX_FIELD("region","uint16",92,2,SX_NONE),
 SX_FIELD("ratings","uint8[16]",94,16,SX_NONE),
 SX_FIELD("reserved1","uint8[12]",110,12,SX_NONE),
 SX_FIELD("ipc_mask","uint8[12]",122,12,SX_FLAGS),
 SX_FIELD("reserved2","uint8[18]",134,18,SX_NONE),
 SX_FIELD("access_rights","uint32",152,4,SX_FLAGS),
 SX_FIELD("title_version","uint16",156,2,SX_NONE),
 SX_FIELD("content_count","uint16",158,2,SX_COUNT_PROP),
 SX_FIELD("boot_index","uint16",160,2,SX_NONE),
 SX_FIELD("padding","uint16",162,2,SX_NONE),
};
static const sx_layout sxan_wad_tmd = {UINT32_C(0x6077004e),"wad_tmd",sxan_wad_tmd_fields,SX_COUNT(sxan_wad_tmd_fields),SX_BE};
static const xx_data_struct_field_desc sxan_wad_content_fields[] = {
 SX_FIELD("content_id","uint32",0,4,SX_NONE),
 SX_FIELD("content_index","uint16",4,2,SX_NONE),
 SX_FIELD("type","uint16",6,2,SX_FLAGS),
 SX_FIELD("uncompressed_size","uint64",8,8,SX_SIZE),
 SX_FIELD("sha1","uint8[20]",16,20,SX_CHECKSUM),
};
static const sx_layout sxan_wad_content = {UINT32_C(0x6077004f),"wad_content",sxan_wad_content_fields,SX_COUNT(sxan_wad_content_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_signature_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxan_stfs_signature = {UINT32_C(0x60770050),"stfs_signature",sxan_stfs_signature_fields,SX_COUNT(sxan_stfs_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_stfs_metadata_digest_fields[] = {
 SX_FIELD("sha1","uint8[20]",0,20,SX_CHECKSUM),
 SX_FIELD("header_size","uint32",20,4,SX_SIZE),
};
static const sx_layout sxan_stfs_metadata_digest = {UINT32_C(0x60770051),"stfs_metadata_digest",sxan_stfs_metadata_digest_fields,SX_COUNT(sxan_stfs_metadata_digest_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_volume_le_fields[] = {
 SX_FIELD("descriptor_size","uint8",0,1,SX_SIZE),
 SX_FIELD("reserved","uint8",1,1,SX_NONE),
 SX_FIELD("block_separation","uint8",2,1,SX_FLAGS),
 SX_FIELD("file_table_blocks","uint16",3,2,SX_NONE),
 SX_FIELD("first_file_table_block","uint24",5,3,SX_NONE),
};
static const sx_layout sxan_stfs_volume_le = {UINT32_C(0x60770052),"stfs_volume_le",sxan_stfs_volume_le_fields,SX_COUNT(sxan_stfs_volume_le_fields),SX_LE};
static const xx_data_struct_field_desc sxan_stfs_volume_be_fields[] = {
 SX_FIELD("top_sha1","uint8[20]",0,20,SX_CHECKSUM),
 SX_FIELD("allocated_blocks","uint32",20,4,SX_NONE),
 SX_FIELD("unallocated_blocks","uint32",24,4,SX_NONE),
};
static const sx_layout sxan_stfs_volume_be = {UINT32_C(0x60770053),"stfs_volume_be",sxan_stfs_volume_be_fields,SX_COUNT(sxan_stfs_volume_be_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_data_file_count_fields[] = {
 SX_FIELD("data_file_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxan_stfs_data_file_count = {UINT32_C(0x60770054),"stfs_data_file_count",sxan_stfs_data_file_count_fields,SX_COUNT(sxan_stfs_data_file_count_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_hash_entry_fields[] = {
 SX_FIELD("sha1","uint8[20]",0,20,SX_CHECKSUM),
 SX_FIELD("status","uint8",20,1,SX_FLAGS),
 SX_FIELD("next_block","uint24",21,3,SX_NONE),
};
static const sx_layout sxan_stfs_hash_entry = {UINT32_C(0x60770055),"stfs_hash_entry",sxan_stfs_hash_entry_fields,SX_COUNT(sxan_stfs_hash_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxan_stfs_file_le_fields[] = {
 SX_FIELD("name","char[40]",0,40,SX_NONE),
 SX_FIELD("name_length_flags","uint8",40,1,SX_FLAGS),
 SX_FIELD("allocated_blocks","uint24",41,3,SX_NONE),
 SX_FIELD("repeated_allocated_blocks","uint24",44,3,SX_NONE),
 SX_FIELD("first_block","uint24",47,3,SX_NONE),
};
static const sx_layout sxan_stfs_file_le = {UINT32_C(0x60770056),"stfs_file_le",sxan_stfs_file_le_fields,SX_COUNT(sxan_stfs_file_le_fields),SX_LE};
static const xx_data_struct_field_desc sxan_stfs_file_be_fields[] = {
 SX_FIELD("parent_index","uint16",0,2,SX_NONE),
 SX_FIELD("payload_size","uint32",2,4,SX_SIZE),
 SX_FIELD("creation_time","uint32",6,4,SX_NONE),
 SX_FIELD("access_time","uint32",10,4,SX_NONE),
};
static const sx_layout sxan_stfs_file_be = {UINT32_C(0x60770057),"stfs_file_be",sxan_stfs_file_be_fields,SX_COUNT(sxan_stfs_file_be_fields),SX_BE};
static const xx_data_struct_field_desc sxan_lha_dialect_header_fields[] = {
 SX_FIELD("header_size","uint8",0,1,SX_SIZE),
 SX_FIELD("header_sum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_NONE),
 SX_FIELD("compressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_datetime","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
 SX_FIELD("level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
static const sx_layout sxan_lha_dialect_header = {UINT32_C(0x60770058),"lha_dialect_header",sxan_lha_dialect_header_fields,SX_COUNT(sxan_lha_dialect_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_crc_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxan_lha_dialect_crc = {UINT32_C(0x60770059),"lha_dialect_crc",sxan_lha_dialect_crc_fields,SX_COUNT(sxan_lha_dialect_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_os_fields[] = {
 SX_FIELD("originating_os","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_lha_dialect_os = {UINT32_C(0x6077005a),"lha_dialect_os",sxan_lha_dialect_os_fields,SX_COUNT(sxan_lha_dialect_os_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_next_fields[] = {
 SX_FIELD("next_header_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxan_lha_dialect_next = {UINT32_C(0x6077005b),"lha_dialect_next",sxan_lha_dialect_next_fields,SX_COUNT(sxan_lha_dialect_next_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_type_fields[] = {
 SX_FIELD("extension_type","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_lha_dialect_type = {UINT32_C(0x6077005c),"lha_dialect_type",sxan_lha_dialect_type_fields,SX_COUNT(sxan_lha_dialect_type_fields),SX_LE};
static const xx_data_struct_field_desc sxan_lha_dialect_end_fields[] = {
 SX_FIELD("terminator","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_lha_dialect_end = {UINT32_C(0x6077005d),"lha_dialect_end",sxan_lha_dialect_end_fields,SX_COUNT(sxan_lha_dialect_end_fields),SX_LE};
static const xx_data_struct_field_desc sxan_bytekiller_header_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("xor_checksum","uint32",8,4,SX_CHECKSUM),
};
static const sx_layout sxan_bytekiller_header = {UINT32_C(0x6077005e),"bytekiller_header",sxan_bytekiller_header_fields,SX_COUNT(sxan_bytekiller_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_ace_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("xor_checksum","uint32",12,4,SX_CHECKSUM),
};
static const sx_layout sxan_bytekiller_ace_header = {UINT32_C(0x6077005f),"bytekiller_ace_header",sxan_bytekiller_ace_header_fields,SX_COUNT(sxan_bytekiller_ace_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_anc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxan_bytekiller_anc_header = {UINT32_C(0x60770060),"bytekiller_anc_header",sxan_bytekiller_anc_header_fields,SX_COUNT(sxan_bytekiller_anc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_grac_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
};
static const sx_layout sxan_bytekiller_grac_header = {UINT32_C(0x60770061),"bytekiller_grac_header",sxan_bytekiller_grac_header_fields,SX_COUNT(sxan_bytekiller_grac_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_md11_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("encoded_size","uint32",4,4,SX_NONE),
};
static const sx_layout sxan_bytekiller_md11_header = {UINT32_C(0x60770062),"bytekiller_md11_header",sxan_bytekiller_md11_header_fields,SX_COUNT(sxan_bytekiller_md11_header_fields),SX_BE};
static const xx_data_struct_field_desc sxan_bytekiller_signature_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxan_bytekiller_signature = {UINT32_C(0x60770063),"bytekiller_signature",sxan_bytekiller_signature_fields,SX_COUNT(sxan_bytekiller_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_bytekiller_footer_fields[] = {
 SX_FIELD("xor_checksum","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxan_bytekiller_footer = {UINT32_C(0x60770064),"bytekiller_footer",sxan_bytekiller_footer_fields,SX_COUNT(sxan_bytekiller_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxan_osl_encoded_record_fields[] = {
 SX_FIELD("encoded_header","uint8[16]",0,16,SX_NONE),
};
static const sx_layout sxan_osl_encoded_record = {UINT32_C(0x60770065),"osl_encoded_record",sxan_osl_encoded_record_fields,SX_COUNT(sxan_osl_encoded_record_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osl_payload_checksum_fields[] = {
 SX_FIELD("rolling_checksum","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxan_osl_payload_checksum = {UINT32_C(0x60770066),"osl_payload_checksum",sxan_osl_payload_checksum_fields,SX_COUNT(sxan_osl_payload_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osl_signature_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
};
static const sx_layout sxan_osl_signature = {UINT32_C(0x60770067),"osl_signature",sxan_osl_signature_fields,SX_COUNT(sxan_osl_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_sbpak_header_fields[] = {
 SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
 SX_FIELD("unknown0","uint8[7]",13,7,SX_NONE),
 SX_FIELD("endian_marker","uint32",20,4,SX_SIGNATURE),
 SX_FIELD("marker","uint32",24,4,SX_NONE),
 SX_FIELD("version","uint32",28,4,SX_NONE),
 SX_FIELD("unknown1","uint32",32,4,SX_NONE),
 SX_FIELD("member_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("unknown2","uint32",40,4,SX_NONE),
 SX_FIELD("data_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("archive_size","uint32",48,4,SX_SIZE),
};
static const sx_layout sxan_sbpak_header = {UINT32_C(0x60770068),"sbpak_header",sxan_sbpak_header_fields,SX_COUNT(sxan_sbpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_sbpak_encoded_header_fields[] = {
 SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
 SX_FIELD("unknown0","uint8[7]",13,7,SX_NONE),
 SX_FIELD("encoded_endian_marker","uint8[4]",20,4,SX_NONE),
 SX_FIELD("encoded_marker","uint8[4]",24,4,SX_NONE),
 SX_FIELD("xor_key","uint8",28,1,SX_NONE),
 SX_FIELD("encoded_version_tail","uint8[3]",29,3,SX_NONE),
 SX_FIELD("encoded_unknown1","uint8[4]",32,4,SX_NONE),
 SX_FIELD("encoded_member_count","uint8[4]",36,4,SX_NONE),
 SX_FIELD("encoded_unknown2","uint8[4]",40,4,SX_NONE),
 SX_FIELD("encoded_data_offset","uint8[4]",44,4,SX_NONE),
 SX_FIELD("encoded_archive_size","uint8[4]",48,4,SX_NONE),
};
static const sx_layout sxan_sbpak_encoded_header = {UINT32_C(0x60770069),"sbpak_encoded_header",sxan_sbpak_encoded_header_fields,SX_COUNT(sxan_sbpak_encoded_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_sbpak_member_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("name_offset_flags","uint32",8,4,SX_NONE),
 SX_FIELD("directory_offset_flags","uint32",12,4,SX_NONE),
};
static const sx_layout sxan_sbpak_member = {UINT32_C(0x6077006a),"sbpak_member",sxan_sbpak_member_fields,SX_COUNT(sxan_sbpak_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_sbpak_encoded_member_fields[] = {
 SX_FIELD("encoded_size","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_data_offset","uint8[4]",4,4,SX_NONE),
 SX_FIELD("encoded_name_offset_flags","uint8[4]",8,4,SX_NONE),
 SX_FIELD("encoded_directory_offset_flags","uint8[4]",12,4,SX_NONE),
};
static const sx_layout sxan_sbpak_encoded_member = {UINT32_C(0x6077006b),"sbpak_encoded_member",sxan_sbpak_encoded_member_fields,SX_COUNT(sxan_sbpak_encoded_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint16",4,2,SX_FLAGS),
 SX_FIELD("version","uint16",6,2,SX_NONE),
};
static const sx_layout sxan_freearc_header = {UINT32_C(0x6077006c),"freearc_header",sxan_freearc_header_fields,SX_COUNT(sxan_freearc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_magic_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxan_freearc_magic = {UINT32_C(0x6077006d),"freearc_magic",sxan_freearc_magic_fields,SX_COUNT(sxan_freearc_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_crc_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxan_freearc_crc = {UINT32_C(0x6077006e),"freearc_crc",sxan_freearc_crc_fields,SX_COUNT(sxan_freearc_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_time_fields[] = {
 SX_FIELD("modification_time","uint32",0,4,SX_TIME),
};
static const sx_layout sxan_freearc_time = {UINT32_C(0x6077006f),"freearc_time",sxan_freearc_time_fields,SX_COUNT(sxan_freearc_time_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_folder_fields[] = {
 SX_FIELD("is_folder","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_freearc_folder = {UINT32_C(0x60770070),"freearc_folder",sxan_freearc_folder_fields,SX_COUNT(sxan_freearc_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_method_fields[] = {
 SX_FIELD("method","char",0,0,SX_NONE),
};
static const sx_layout sxan_freearc_method = {UINT32_C(0x60770071),"freearc_method",sxan_freearc_method_fields,SX_COUNT(sxan_freearc_method_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type1_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,1,SX_NONE),
};
static const sx_layout sxan_freearc_type1 = {UINT32_C(0x60770072),"freearc_type1",sxan_freearc_type1_fields,SX_COUNT(sxan_freearc_type1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count1_fields[] = {
 SX_FIELD("count","freearc_uint",0,1,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count1 = {UINT32_C(0x60770073),"freearc_count1",sxan_freearc_count1_fields,SX_COUNT(sxan_freearc_count1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset1_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,1,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset1 = {UINT32_C(0x60770074),"freearc_offset1",sxan_freearc_offset1_fields,SX_COUNT(sxan_freearc_offset1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size1_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,1,SX_SIZE),
};
static const sx_layout sxan_freearc_size1 = {UINT32_C(0x60770075),"freearc_size1",sxan_freearc_size1_fields,SX_COUNT(sxan_freearc_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed1_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,1,SX_SIZE),
};
static const sx_layout sxan_freearc_packed1 = {UINT32_C(0x60770076),"freearc_packed1",sxan_freearc_packed1_fields,SX_COUNT(sxan_freearc_packed1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index1_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,1,SX_NONE),
};
static const sx_layout sxan_freearc_index1 = {UINT32_C(0x60770077),"freearc_index1",sxan_freearc_index1_fields,SX_COUNT(sxan_freearc_index1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type2_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,2,SX_NONE),
};
static const sx_layout sxan_freearc_type2 = {UINT32_C(0x60770078),"freearc_type2",sxan_freearc_type2_fields,SX_COUNT(sxan_freearc_type2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count2_fields[] = {
 SX_FIELD("count","freearc_uint",0,2,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count2 = {UINT32_C(0x60770079),"freearc_count2",sxan_freearc_count2_fields,SX_COUNT(sxan_freearc_count2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset2_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,2,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset2 = {UINT32_C(0x6077007a),"freearc_offset2",sxan_freearc_offset2_fields,SX_COUNT(sxan_freearc_offset2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size2_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,2,SX_SIZE),
};
static const sx_layout sxan_freearc_size2 = {UINT32_C(0x6077007b),"freearc_size2",sxan_freearc_size2_fields,SX_COUNT(sxan_freearc_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed2_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,2,SX_SIZE),
};
static const sx_layout sxan_freearc_packed2 = {UINT32_C(0x6077007c),"freearc_packed2",sxan_freearc_packed2_fields,SX_COUNT(sxan_freearc_packed2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index2_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,2,SX_NONE),
};
static const sx_layout sxan_freearc_index2 = {UINT32_C(0x6077007d),"freearc_index2",sxan_freearc_index2_fields,SX_COUNT(sxan_freearc_index2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type3_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,3,SX_NONE),
};
static const sx_layout sxan_freearc_type3 = {UINT32_C(0x6077007e),"freearc_type3",sxan_freearc_type3_fields,SX_COUNT(sxan_freearc_type3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count3_fields[] = {
 SX_FIELD("count","freearc_uint",0,3,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count3 = {UINT32_C(0x6077007f),"freearc_count3",sxan_freearc_count3_fields,SX_COUNT(sxan_freearc_count3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset3_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,3,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset3 = {UINT32_C(0x60770080),"freearc_offset3",sxan_freearc_offset3_fields,SX_COUNT(sxan_freearc_offset3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size3_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,3,SX_SIZE),
};
static const sx_layout sxan_freearc_size3 = {UINT32_C(0x60770081),"freearc_size3",sxan_freearc_size3_fields,SX_COUNT(sxan_freearc_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed3_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,3,SX_SIZE),
};
static const sx_layout sxan_freearc_packed3 = {UINT32_C(0x60770082),"freearc_packed3",sxan_freearc_packed3_fields,SX_COUNT(sxan_freearc_packed3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index3_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,3,SX_NONE),
};
static const sx_layout sxan_freearc_index3 = {UINT32_C(0x60770083),"freearc_index3",sxan_freearc_index3_fields,SX_COUNT(sxan_freearc_index3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type4_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,4,SX_NONE),
};
static const sx_layout sxan_freearc_type4 = {UINT32_C(0x60770084),"freearc_type4",sxan_freearc_type4_fields,SX_COUNT(sxan_freearc_type4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count4_fields[] = {
 SX_FIELD("count","freearc_uint",0,4,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count4 = {UINT32_C(0x60770085),"freearc_count4",sxan_freearc_count4_fields,SX_COUNT(sxan_freearc_count4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset4_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,4,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset4 = {UINT32_C(0x60770086),"freearc_offset4",sxan_freearc_offset4_fields,SX_COUNT(sxan_freearc_offset4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size4_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,4,SX_SIZE),
};
static const sx_layout sxan_freearc_size4 = {UINT32_C(0x60770087),"freearc_size4",sxan_freearc_size4_fields,SX_COUNT(sxan_freearc_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed4_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,4,SX_SIZE),
};
static const sx_layout sxan_freearc_packed4 = {UINT32_C(0x60770088),"freearc_packed4",sxan_freearc_packed4_fields,SX_COUNT(sxan_freearc_packed4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index4_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,4,SX_NONE),
};
static const sx_layout sxan_freearc_index4 = {UINT32_C(0x60770089),"freearc_index4",sxan_freearc_index4_fields,SX_COUNT(sxan_freearc_index4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type5_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,5,SX_NONE),
};
static const sx_layout sxan_freearc_type5 = {UINT32_C(0x6077008a),"freearc_type5",sxan_freearc_type5_fields,SX_COUNT(sxan_freearc_type5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count5_fields[] = {
 SX_FIELD("count","freearc_uint",0,5,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count5 = {UINT32_C(0x6077008b),"freearc_count5",sxan_freearc_count5_fields,SX_COUNT(sxan_freearc_count5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset5_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,5,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset5 = {UINT32_C(0x6077008c),"freearc_offset5",sxan_freearc_offset5_fields,SX_COUNT(sxan_freearc_offset5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size5_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,5,SX_SIZE),
};
static const sx_layout sxan_freearc_size5 = {UINT32_C(0x6077008d),"freearc_size5",sxan_freearc_size5_fields,SX_COUNT(sxan_freearc_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed5_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,5,SX_SIZE),
};
static const sx_layout sxan_freearc_packed5 = {UINT32_C(0x6077008e),"freearc_packed5",sxan_freearc_packed5_fields,SX_COUNT(sxan_freearc_packed5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index5_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,5,SX_NONE),
};
static const sx_layout sxan_freearc_index5 = {UINT32_C(0x6077008f),"freearc_index5",sxan_freearc_index5_fields,SX_COUNT(sxan_freearc_index5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type6_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,6,SX_NONE),
};
static const sx_layout sxan_freearc_type6 = {UINT32_C(0x60770090),"freearc_type6",sxan_freearc_type6_fields,SX_COUNT(sxan_freearc_type6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count6_fields[] = {
 SX_FIELD("count","freearc_uint",0,6,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count6 = {UINT32_C(0x60770091),"freearc_count6",sxan_freearc_count6_fields,SX_COUNT(sxan_freearc_count6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset6_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,6,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset6 = {UINT32_C(0x60770092),"freearc_offset6",sxan_freearc_offset6_fields,SX_COUNT(sxan_freearc_offset6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size6_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,6,SX_SIZE),
};
static const sx_layout sxan_freearc_size6 = {UINT32_C(0x60770093),"freearc_size6",sxan_freearc_size6_fields,SX_COUNT(sxan_freearc_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed6_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,6,SX_SIZE),
};
static const sx_layout sxan_freearc_packed6 = {UINT32_C(0x60770094),"freearc_packed6",sxan_freearc_packed6_fields,SX_COUNT(sxan_freearc_packed6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index6_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,6,SX_NONE),
};
static const sx_layout sxan_freearc_index6 = {UINT32_C(0x60770095),"freearc_index6",sxan_freearc_index6_fields,SX_COUNT(sxan_freearc_index6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type7_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,7,SX_NONE),
};
static const sx_layout sxan_freearc_type7 = {UINT32_C(0x60770096),"freearc_type7",sxan_freearc_type7_fields,SX_COUNT(sxan_freearc_type7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count7_fields[] = {
 SX_FIELD("count","freearc_uint",0,7,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count7 = {UINT32_C(0x60770097),"freearc_count7",sxan_freearc_count7_fields,SX_COUNT(sxan_freearc_count7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset7_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,7,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset7 = {UINT32_C(0x60770098),"freearc_offset7",sxan_freearc_offset7_fields,SX_COUNT(sxan_freearc_offset7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size7_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,7,SX_SIZE),
};
static const sx_layout sxan_freearc_size7 = {UINT32_C(0x60770099),"freearc_size7",sxan_freearc_size7_fields,SX_COUNT(sxan_freearc_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed7_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,7,SX_SIZE),
};
static const sx_layout sxan_freearc_packed7 = {UINT32_C(0x6077009a),"freearc_packed7",sxan_freearc_packed7_fields,SX_COUNT(sxan_freearc_packed7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index7_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,7,SX_NONE),
};
static const sx_layout sxan_freearc_index7 = {UINT32_C(0x6077009b),"freearc_index7",sxan_freearc_index7_fields,SX_COUNT(sxan_freearc_index7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type8_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,8,SX_NONE),
};
static const sx_layout sxan_freearc_type8 = {UINT32_C(0x6077009c),"freearc_type8",sxan_freearc_type8_fields,SX_COUNT(sxan_freearc_type8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count8_fields[] = {
 SX_FIELD("count","freearc_uint",0,8,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count8 = {UINT32_C(0x6077009d),"freearc_count8",sxan_freearc_count8_fields,SX_COUNT(sxan_freearc_count8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset8_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,8,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset8 = {UINT32_C(0x6077009e),"freearc_offset8",sxan_freearc_offset8_fields,SX_COUNT(sxan_freearc_offset8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size8_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,8,SX_SIZE),
};
static const sx_layout sxan_freearc_size8 = {UINT32_C(0x6077009f),"freearc_size8",sxan_freearc_size8_fields,SX_COUNT(sxan_freearc_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed8_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,8,SX_SIZE),
};
static const sx_layout sxan_freearc_packed8 = {UINT32_C(0x607700a0),"freearc_packed8",sxan_freearc_packed8_fields,SX_COUNT(sxan_freearc_packed8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index8_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,8,SX_NONE),
};
static const sx_layout sxan_freearc_index8 = {UINT32_C(0x607700a1),"freearc_index8",sxan_freearc_index8_fields,SX_COUNT(sxan_freearc_index8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type9_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,9,SX_NONE),
};
static const sx_layout sxan_freearc_type9 = {UINT32_C(0x607700a2),"freearc_type9",sxan_freearc_type9_fields,SX_COUNT(sxan_freearc_type9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count9_fields[] = {
 SX_FIELD("count","freearc_uint",0,9,SX_COUNT_PROP),
};
static const sx_layout sxan_freearc_count9 = {UINT32_C(0x607700a3),"freearc_count9",sxan_freearc_count9_fields,SX_COUNT(sxan_freearc_count9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset9_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,9,SX_OFFSET),
};
static const sx_layout sxan_freearc_offset9 = {UINT32_C(0x607700a4),"freearc_offset9",sxan_freearc_offset9_fields,SX_COUNT(sxan_freearc_offset9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size9_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,9,SX_SIZE),
};
static const sx_layout sxan_freearc_size9 = {UINT32_C(0x607700a5),"freearc_size9",sxan_freearc_size9_fields,SX_COUNT(sxan_freearc_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed9_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,9,SX_SIZE),
};
static const sx_layout sxan_freearc_packed9 = {UINT32_C(0x607700a6),"freearc_packed9",sxan_freearc_packed9_fields,SX_COUNT(sxan_freearc_packed9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index9_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,9,SX_NONE),
};
static const sx_layout sxan_freearc_index9 = {UINT32_C(0x607700a7),"freearc_index9",sxan_freearc_index9_fields,SX_COUNT(sxan_freearc_index9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_block_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("level","uint8",3,1,SX_NONE),
 SX_FIELD("type","uint8",4,1,SX_NONE),
 SX_FIELD("header_size","uint16",5,2,SX_SIZE),
};
static const sx_layout sxan_zpaq_block = {UINT32_C(0x607700a8),"zpaq_block",sxan_zpaq_block_fields,SX_COUNT(sxan_zpaq_block_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_model_fields[] = {
 SX_FIELD("hcomp_hash_bits","uint8",0,1,SX_NONE),
 SX_FIELD("hcomp_memory_bits","uint8",1,1,SX_NONE),
 SX_FIELD("pcomp_hash_bits","uint8",2,1,SX_NONE),
 SX_FIELD("pcomp_memory_bits","uint8",3,1,SX_NONE),
 SX_FIELD("component_count","uint8",4,1,SX_COUNT_PROP),
};
static const sx_layout sxan_zpaq_model = {UINT32_C(0x607700a9),"zpaq_model",sxan_zpaq_model_fields,SX_COUNT(sxan_zpaq_model_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_locator_fields[] = {
 SX_FIELD("locator","uint8[13]",0,13,SX_SIGNATURE),
};
static const sx_layout sxan_zpaq_locator = {UINT32_C(0x607700aa),"zpaq_locator",sxan_zpaq_locator_fields,SX_COUNT(sxan_zpaq_locator_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_marker_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_NONE),
};
static const sx_layout sxan_zpaq_marker = {UINT32_C(0x607700ab),"zpaq_marker",sxan_zpaq_marker_fields,SX_COUNT(sxan_zpaq_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_stored_run_fields[] = {
 SX_FIELD("run_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxan_zpaq_stored_run = {UINT32_C(0x607700ac),"zpaq_stored_run",sxan_zpaq_stored_run_fields,SX_COUNT(sxan_zpaq_stored_run_fields),SX_BE};
static const xx_data_struct_field_desc sxan_zpaq_sha1_fields[] = {
 SX_FIELD("sha1","uint8[20]",0,20,SX_CHECKSUM),
};
static const sx_layout sxan_zpaq_sha1 = {UINT32_C(0x607700ad),"zpaq_sha1",sxan_zpaq_sha1_fields,SX_COUNT(sxan_zpaq_sha1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_comment_fields[] = {
 SX_FIELD("comment","char",0,0,SX_NONE),
};
static const sx_layout sxan_zpaq_comment = {UINT32_C(0x607700ae),"zpaq_comment",sxan_zpaq_comment_fields,SX_COUNT(sxan_zpaq_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_cons_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("constant","uint8",1,1,SX_NONE),
};
static const sx_layout sxan_zpaq_cons = {UINT32_C(0x607700af),"zpaq_cons",sxan_zpaq_cons_fields,SX_COUNT(sxan_zpaq_cons_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_cm_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("limit","uint8",2,1,SX_NONE),
};
static const sx_layout sxan_zpaq_cm = {UINT32_C(0x607700b0),"zpaq_cm",sxan_zpaq_cm_fields,SX_COUNT(sxan_zpaq_cm_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_icm_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
};
static const sx_layout sxan_zpaq_icm = {UINT32_C(0x607700b1),"zpaq_icm",sxan_zpaq_icm_fields,SX_COUNT(sxan_zpaq_icm_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_match_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("bufferbits","uint8",2,1,SX_NONE),
};
static const sx_layout sxan_zpaq_match = {UINT32_C(0x607700b2),"zpaq_match",sxan_zpaq_match_fields,SX_COUNT(sxan_zpaq_match_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_avg_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("component_j","uint8",1,1,SX_NONE),
 SX_FIELD("component_k","uint8",2,1,SX_NONE),
 SX_FIELD("weight","uint8",3,1,SX_NONE),
};
static const sx_layout sxan_zpaq_avg = {UINT32_C(0x607700b3),"zpaq_avg",sxan_zpaq_avg_fields,SX_COUNT(sxan_zpaq_avg_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_mix2_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("component_j","uint8",2,1,SX_NONE),
 SX_FIELD("component_k","uint8",3,1,SX_NONE),
 SX_FIELD("rate","uint8",4,1,SX_NONE),
 SX_FIELD("mask","uint8",5,1,SX_NONE),
};
static const sx_layout sxan_zpaq_mix2 = {UINT32_C(0x607700b4),"zpaq_mix2",sxan_zpaq_mix2_fields,SX_COUNT(sxan_zpaq_mix2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_mix_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("first_component","uint8",2,1,SX_NONE),
 SX_FIELD("component_count","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("rate","uint8",4,1,SX_NONE),
 SX_FIELD("mask","uint8",5,1,SX_NONE),
};
static const sx_layout sxan_zpaq_mix = {UINT32_C(0x607700b5),"zpaq_mix",sxan_zpaq_mix_fields,SX_COUNT(sxan_zpaq_mix_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_isse_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("component_j","uint8",2,1,SX_NONE),
};
static const sx_layout sxan_zpaq_isse = {UINT32_C(0x607700b6),"zpaq_isse",sxan_zpaq_isse_fields,SX_COUNT(sxan_zpaq_isse_fields),SX_LE};
static const xx_data_struct_field_desc sxan_zpaq_sse_fields[] = {
 SX_FIELD("component_type","uint8",0,1,SX_NONE),
 SX_FIELD("sizebits","uint8",1,1,SX_NONE),
 SX_FIELD("component_j","uint8",2,1,SX_NONE),
 SX_FIELD("start","uint8",3,1,SX_NONE),
 SX_FIELD("limit","uint8",4,1,SX_NONE),
};
static const sx_layout sxan_zpaq_sse = {UINT32_C(0x607700b7),"zpaq_sse",sxan_zpaq_sse_fields,SX_COUNT(sxan_zpaq_sse_fields),SX_LE};
static const sx_layout *const sx_archivenext_layouts[] = {
 &sxan_is3_header,
 &sxan_is3_directory,
 &sxan_is3_member,
 &sxan_is3_payload_header,
 &sxan_is3_payload_member,
 &sxan_is3_second_name,
 &sxan_is5_header,
 &sxan_is5_descriptor,
 &sxan_is5_member_v5,
 &sxan_is5_member_v6,
 &sxan_is5_table_offset,
 &sxan_is11_header,
 &sxan_is11_member_v1,
 &sxan_is11_member_v3,
 &sxan_gksetup_banner,
 &sxan_gksetup_signature,
 &sxan_gksetup_data_offset,
 &sxan_gksetup_member,
 &sxan_pcinstall_header,
 &sxan_pcinstall_member,
 &sxan_finstall_header,
 &sxan_finstall_member,
 &sxan_ifah_header,
 &sxan_ifah_member,
 &sxan_osetup_member,
 &sxan_osetup_trailer_6,
 &sxan_osetup_trailer_8,
 &sxan_pc_install_member,
 &sxan_pc_install_trailer,
 &sxan_pc_install_group,
 &sxan_pc_install_group_member,
 &sxan_rtpatch_setup_member,
 &sxan_spoon_footer,
 &sxan_spoon_member,
 &sxan_issetup_header,
 &sxan_issetup_member,
 &sxan_epsf_header,
 &sxan_setup_factory_header,
 &sxan_setup_factory_engine_16,
 &sxan_setup_factory_engine_260,
 &sxan_westwood_offset,
 &sxan_ckpedp_header,
 &sxan_ckpedp_name_size,
 &sxan_ckpedp_member_tail,
 &sxan_ckpedp_encoded_name,
 &sxan_parsec_rib_header,
 &sxan_parsec_member_offset,
 &sxan_parsec_member_size,
 &sxan_ptero_header,
 &sxan_ptero_member,
 &sxan_ptero_block,
 &sxan_titan_header,
 &sxan_titan_block,
 &sxan_titan_member,
 &sxan_cgjp_signature,
 &sxan_cgjp_block,
 &sxan_birdies_header,
 &sxan_birdies_member,
 &sxan_xuiz_header,
 &sxan_xuiz_member_0,
 &sxan_xuiz_member_10,
 &sxan_dcs_header,
 &sxan_dcs_block,
 &sxan_audials_count,
 &sxan_audials_offset,
 &sxan_audials_size,
 &sxan_archivenext_name,
 &sxan_archivenext_utf16le,
 &sxan_archivenext_utf16be,
 &sxan_is5_volume_prefix,
 &sxan_archivenext_padding32,
 &sxan_archivenext_separator,
 &sxan_pc_install_tag,
 &sxan_wad_header,
 &sxan_wad_rsa2048,
 &sxan_wad_ticket,
 &sxan_wad_limit,
 &sxan_wad_tmd,
 &sxan_wad_content,
 &sxan_stfs_signature,
 &sxan_stfs_metadata_digest,
 &sxan_stfs_volume_le,
 &sxan_stfs_volume_be,
 &sxan_stfs_data_file_count,
 &sxan_stfs_hash_entry,
 &sxan_stfs_file_le,
 &sxan_stfs_file_be,
 &sxan_lha_dialect_header,
 &sxan_lha_dialect_crc,
 &sxan_lha_dialect_os,
 &sxan_lha_dialect_next,
 &sxan_lha_dialect_type,
 &sxan_lha_dialect_end,
 &sxan_bytekiller_header,
 &sxan_bytekiller_ace_header,
 &sxan_bytekiller_anc_header,
 &sxan_bytekiller_grac_header,
 &sxan_bytekiller_md11_header,
 &sxan_bytekiller_signature,
 &sxan_bytekiller_footer,
 &sxan_osl_encoded_record,
 &sxan_osl_payload_checksum,
 &sxan_osl_signature,
 &sxan_sbpak_header,
 &sxan_sbpak_encoded_header,
 &sxan_sbpak_member,
 &sxan_sbpak_encoded_member,
 &sxan_freearc_header,
 &sxan_freearc_magic,
 &sxan_freearc_crc,
 &sxan_freearc_time,
 &sxan_freearc_folder,
 &sxan_freearc_method,
 &sxan_freearc_type1,
 &sxan_freearc_count1,
 &sxan_freearc_offset1,
 &sxan_freearc_size1,
 &sxan_freearc_packed1,
 &sxan_freearc_index1,
 &sxan_freearc_type2,
 &sxan_freearc_count2,
 &sxan_freearc_offset2,
 &sxan_freearc_size2,
 &sxan_freearc_packed2,
 &sxan_freearc_index2,
 &sxan_freearc_type3,
 &sxan_freearc_count3,
 &sxan_freearc_offset3,
 &sxan_freearc_size3,
 &sxan_freearc_packed3,
 &sxan_freearc_index3,
 &sxan_freearc_type4,
 &sxan_freearc_count4,
 &sxan_freearc_offset4,
 &sxan_freearc_size4,
 &sxan_freearc_packed4,
 &sxan_freearc_index4,
 &sxan_freearc_type5,
 &sxan_freearc_count5,
 &sxan_freearc_offset5,
 &sxan_freearc_size5,
 &sxan_freearc_packed5,
 &sxan_freearc_index5,
 &sxan_freearc_type6,
 &sxan_freearc_count6,
 &sxan_freearc_offset6,
 &sxan_freearc_size6,
 &sxan_freearc_packed6,
 &sxan_freearc_index6,
 &sxan_freearc_type7,
 &sxan_freearc_count7,
 &sxan_freearc_offset7,
 &sxan_freearc_size7,
 &sxan_freearc_packed7,
 &sxan_freearc_index7,
 &sxan_freearc_type8,
 &sxan_freearc_count8,
 &sxan_freearc_offset8,
 &sxan_freearc_size8,
 &sxan_freearc_packed8,
 &sxan_freearc_index8,
 &sxan_freearc_type9,
 &sxan_freearc_count9,
 &sxan_freearc_offset9,
 &sxan_freearc_size9,
 &sxan_freearc_packed9,
 &sxan_freearc_index9,
 &sxan_zpaq_block,
 &sxan_zpaq_model,
 &sxan_zpaq_locator,
 &sxan_zpaq_marker,
 &sxan_zpaq_stored_run,
 &sxan_zpaq_sha1,
 &sxan_zpaq_comment,
 &sxan_zpaq_cons,
 &sxan_zpaq_cm,
 &sxan_zpaq_icm,
 &sxan_zpaq_match,
 &sxan_zpaq_avg,
 &sxan_zpaq_mix2,
 &sxan_zpaq_mix,
 &sxan_zpaq_isse,
 &sxan_zpaq_sse,
};
static bool sx_archivenext_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60770000U||id>=0x60780000U)return true;
 if(r->type&&(!xx_rt_wcsncmp(r->type,L"ascii_decimal[",14)||!xx_rt_wcsncmp(r->type,L"ascii_octal_padded[",19))&&r->value.type!=XX_VAR_TYPE_UINT64&&r->value.type!=XX_VAR_TYPE_INT64)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60770001U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored archive timestamp; epoch not established";
 if(!xx_rt_wcscmp(r->name,L"archive_size"))text=L"Total across all volumes";
 break;
 case 0x60770003U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Offset in the archive volume";
 break;
 case 0x60770008U:
 if(!xx_rt_wcscmp(r->name,L"file_table_offset"))text=L"Relative to cabinet descriptor";
 if(!xx_rt_wcscmp(r->name,L"second_table_offset"))text=L"Relative to the file table";
 break;
 case 0x60770009U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to file table";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to applicable cabinet volume";
 break;
 case 0x6077000aU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to applicable cabinet volume";
 if(!xx_rt_wcscmp(r->name,L"md5"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to file table";
 break;
 case 0x6077000bU:
 if(!xx_rt_wcscmp(r->name,L"entry_offset"))text=L"Relative to file table";
 break;
 case 0x60770012U:
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Windows FILETIME100ns ticks since1601";
 if(!xx_rt_wcscmp(r->name,L"access_time"))text=L"Windows FILETIME100ns ticks since1601";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Windows FILETIME100ns ticks since1601";
 break;
 case 0x60770016U:
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"DOS codepage437 bytes";
 break;
 case 0x60770017U:
 if(!xx_rt_wcscmp(r->name,L"declared_size"))text=L"Whole setup size, including stub when present";
 break;
 case 0x60770018U:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Stored checksum or digest";
 break;
 case 0x60770019U:
 if(!xx_rt_wcscmp(r->name,L"writer_memory"))text=L"Uninitialized writer bytes, not interpreted";
 break;
 case 0x6077001cU:
 if(!xx_rt_wcscmp(r->name,L"next_offset"))text=L"Stored original base-relative record offset; may require native relocation";
 break;
 case 0x60770022U:
 if(!xx_rt_wcscmp(r->name,L"byte_sum"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Includes NUL terminator";
 break;
 case 0x60770024U:
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"UTF16LE byte count";
 if(!xx_rt_wcscmp(r->name,L"cipher_selector"))text=L"0,0xffffffff,0xfffffffd=none;2,6=name-keyed filter";
 if(!xx_rt_wcscmp(r->name,L"storage"))text=L"0=stored,1=zlib stream";
 break;
 case 0x60770025U:
 if(!xx_rt_wcscmp(r->name,L"runtime_byte_sum"))text=L"Stored checksum or digest";
 break;
 case 0x60770027U:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Stored checksum or digest";
 break;
 case 0x60770028U:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Stored checksum or digest";
 break;
 case 0x60770029U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Zero denotes directory termination in supported variants";
 break;
 case 0x6077002bU:
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"Encoded bytes for CKP, encoded UTF16LE units for EDP";
 break;
 case 0x6077002dU:
 if(!xx_rt_wcscmp(r->name,L"encoded_name"))text=L"Inverted bytes/UTF16LE plus native character remapping; retained exactly as stored";
 break;
 case 0x6077002fU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"First entry also equals physical directory size; final offset word is zero";
 break;
 case 0x60770032U:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Native-supported value32";
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored timestamp; epoch not established";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=stored,1=framed Ptero LZW";
 break;
 case 0x60770036U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"1=stored contiguous,3=block chain";
 if(!xx_rt_wcscmp(r->name,L"adler32"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Excludes terminating NUL";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to name table";
 break;
 case 0x60770038U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Zero means stored bytes of uncompressed_size";
 break;
 case 0x6077003cU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to end of directory";
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"UTF16BE code units";
 break;
 case 0x6077003dU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to end of directory";
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"UTF16BE code units";
 break;
 case 0x6077003fU:
 if(!xx_rt_wcscmp(r->name,L"stored_size"))text=L"Includes four-byte expected-size word, excludes this word";
 break;
 case 0x60770041U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the end of the complete text directory";
 break;
 case 0x60770044U:
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"UTF16LE serialized units; retained as an array";
 break;
 case 0x60770045U:
 if(!xx_rt_wcscmp(r->name,L"name_units"))text=L"UTF16BE serialized units; retained as an array";
 break;
 case 0x6077004bU:
 if(!xx_rt_wcscmp(r->name,L"signature_type"))text=L"0x10001=RSA2048/SHA1";
 if(!xx_rt_wcscmp(r->name,L"signature"))text=L"RSA2048 signature bytes";
 break;
 case 0x6077004fU:
 if(!xx_rt_wcscmp(r->name,L"sha1"))text=L"Stored checksum or digest";
 break;
 case 0x60770051U:
 if(!xx_rt_wcscmp(r->name,L"sha1"))text=L"Stored checksum or digest";
 break;
 case 0x60770052U:
 if(!xx_rt_wcscmp(r->name,L"block_separation"))text=L"Bit0 selects single/double hash-table copies; bit1 selects top copy";
 if(!xx_rt_wcscmp(r->name,L"file_table_blocks"))text=L"Number of4096-byte logical blocks";
 if(!xx_rt_wcscmp(r->name,L"first_file_table_block"))text=L"Logical block index";
 break;
 case 0x60770053U:
 if(!xx_rt_wcscmp(r->name,L"top_sha1"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"allocated_blocks"))text=L"4096-byte logical blocks";
 if(!xx_rt_wcscmp(r->name,L"unallocated_blocks"))text=L"4096-byte logical blocks";
 break;
 case 0x60770055U:
 if(!xx_rt_wcscmp(r->name,L"sha1"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"status"))text=L">=0x80 allocated; parent bit0x40 selects alternate hash table";
 if(!xx_rt_wcscmp(r->name,L"next_block"))text=L"Logical block index;0xffffff terminates chain";
 break;
 case 0x60770056U:
 if(!xx_rt_wcscmp(r->name,L"name_length_flags"))text=L"Low6 bits=name byte count;0x40=consecutive;0x80=directory";
 if(!xx_rt_wcscmp(r->name,L"allocated_blocks"))text=L"4096-byte logical blocks";
 if(!xx_rt_wcscmp(r->name,L"first_block"))text=L"Logical block index";
 break;
 case 0x60770057U:
 if(!xx_rt_wcscmp(r->name,L"parent_index"))text=L"0xffff=root";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Packed FAT date/time";
 if(!xx_rt_wcscmp(r->name,L"access_time"))text=L"Packed FAT date/time";
 break;
 case 0x60770058U:
 if(!xx_rt_wcscmp(r->name,L"header_size"))text=L"Excludes this byte and checksum byte";
 if(!xx_rt_wcscmp(r->name,L"header_sum"))text=L"Stored checksum or digest";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Level1 includes extended headers";
 break;
 case 0x60770059U:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC16 checksum";
 break;
 case 0x6077005cU:
 if(!xx_rt_wcscmp(r->name,L"extension_type"))text=L"0=header CRC16;1=replacement filename;2=directory with0xff separators";
 break;
 case 0x6077005eU:
 if(!xx_rt_wcscmp(r->name,L"xor_checksum"))text=L"Stored checksum or digest";
 break;
 case 0x6077005fU:
 if(!xx_rt_wcscmp(r->name,L"stored_size"))text=L"Physical extent minus12; includes checksum word";
 if(!xx_rt_wcscmp(r->name,L"xor_checksum"))text=L"Stored checksum or digest";
 break;
 case 0x60770060U:
 if(!xx_rt_wcscmp(r->name,L"stored_size"))text=L"Physical extent minus8; includes final checksum and size words";
 break;
 case 0x60770062U:
 if(!xx_rt_wcscmp(r->name,L"encoded_size"))text=L"XOR with0x4d443131 gives two repeated16-bit plaintext lengths";
 break;
 case 0x60770064U:
 if(!xx_rt_wcscmp(r->name,L"xor_checksum"))text=L"Stored checksum or digest";
 break;
 case 0x60770065U:
 if(!xx_rt_wcscmp(r->name,L"encoded_header"))text=L"Whole transformed record header: decoded marker16, length32 and name10; byte rotations and previous-byte mixing prevent independent ciphertext-field semantics";
 break;
 case 0x60770066U:
 if(!xx_rt_wcscmp(r->name,L"rolling_checksum"))text=L"16-bit rotate-left sum over decoded member bytes";
 break;
 case 0x6077006aU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to data area";
 if(!xx_rt_wcscmp(r->name,L"name_offset_flags"))text=L"Low24 bits=name-table-relative offset; physical name begins two bytes later";
 if(!xx_rt_wcscmp(r->name,L"directory_offset_flags"))text=L"Low24 bits=name-table-relative offset; zero=no parent";
 break;
 case 0x6077006eU:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the applicable physical or decoded block";
 break;
 case 0x60770072U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770073U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770074U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x60770077U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x60770078U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770079U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x6077007aU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x6077007dU:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x6077007eU:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x6077007fU:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770080U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x60770083U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x60770084U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770085U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770086U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x60770089U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x6077008aU:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x6077008bU:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x6077008cU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x6077008fU:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x60770090U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770091U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770092U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x60770095U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x60770096U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x60770097U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x60770098U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x6077009bU:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x6077009cU:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x6077009dU:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x6077009eU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x607700a1U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x607700a2U:
 if(!xx_rt_wcscmp(r->name,L"block_type"))text=L"1=header,3=directory,4=footer";
 break;
 case 0x607700a3U:
 if(!xx_rt_wcscmp(r->name,L"count"))text=L"Physical FreeArc variable-length count";
 break;
 case 0x607700a4U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Backward distance from containing directory/footer data start";
 break;
 case 0x607700a7U:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"Zero-based directory index";
 break;
 case 0x607700abU:
 if(!xx_rt_wcscmp(r->name,L"marker"))text=L"0=header terminator/reserved;1=segment;253=SHA1 follows;254=no SHA1;255=end block";
 break;
 case 0x607700acU:
 if(!xx_rt_wcscmp(r->name,L"run_size"))text=L"Zero ends stored segment; decoded payload may include PCOMP controls";
 break;
 case 0x607700adU:
 if(!xx_rt_wcscmp(r->name,L"sha1"))text=L"SHA1 digest of decoded segment bytes";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXAN_LIMIT 20000U
static bool sxan_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxan_read(sx_context*c,uint64_t p,void*b,size_t n){return sxan_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxan_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxan_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxan_read(c,p,b,n))return false;*v=sxan_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxan_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXAN_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxan_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxan_add(sx_context*c,const sx_layout*l,uint64_t p){return sxan_put(c,l,p,0,false);}
static bool sxan_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxan_put(c,l,p,n,aliases);}
static bool sxan_zlen(sx_context*c,uint64_t p,uint64_t end,uint64_t*n){uint8_t b;*n=0;while(p<end&&*n<4096){if(!sxan_read(c,p++,&b,1))return false;(*n)++;if(!b)return true;}return false;}
static int sxan_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxan_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxan_order);return !c->failed;}
static bool sxan_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxan_add(c,l,p+i*width))return false;return true;}

/* Locate the same physical PE overlay used by the native installer readers.
 * This parses only wire headers and introduces no constructor/profile dependency. */
static bool sxan_pe_overlay(sx_context*c,uint64_t*out){uint8_t h[40];uint64_t pe,sections,optional,end=0;if(!sxan_read(c,0,h,2)||h[0]!='M'||h[1]!='Z'||!sxan_word(c,60,4,false,&pe)||!sxan_read(c,pe,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;sections=sxan_uint(h+6,2,false);optional=sxan_uint(h+20,2,false);if(!sections||sections>4096||!sxan_span(c,pe+24,optional)||!sxan_span(c,pe+24+optional,40*sections))return false;for(uint64_t i=0;i<sections;i++){if(!sxan_read(c,pe+24+optional+40*i,h,40))return false;uint64_t z=sxan_uint(h+16,4,false),p=sxan_uint(h+20,4,false);if(!sxan_span(c,p,z))return false;if(z&&p+z>end)end=p+z;}if(!end)return false;*out=end;return true;}
static bool sxan_named(sx_context*c,uint64_t p,uint64_t n){return sxan_span(c,p,n)&&sxan_text(c,&sxan_archivenext_name,p,n,false);}
static bool sxan_is3(sx_context*c){uint64_t magic,n,p,end,z,len;if(!sxan_word(c,0,4,false,&magic))return false;if(magic==0xd879ab2aU){if(!sxan_add(c,&sxan_is3_payload_header,0)||!sxan_word(c,78,4,false,&n))return false;p=82;for(uint64_t i=0;i<n;i++){if(!sxan_add(c,&sxan_is3_payload_member,p)||!sxan_word(c,p+20,2,false,&len)||!sxan_named(c,p+22,len))return false;p+=22+len;if(!sxan_word(c,p,2,false,&len)||!sxan_add(c,&sxan_is3_second_name,p)||!sxan_named(c,p+2,len))return false;p+=2+len;}return true;}
 if(!sxan_add(c,&sxan_is3_header,0)||!sxan_word(c,41,4,false,&p)||!sxan_word(c,45,4,false,&z)||!sxan_span(c,p,z)||!sxan_word(c,49,2,false,&n))return false;end=p+z;for(uint64_t i=0;i<n;i++){if(p>end||end-p<6||!sxan_word(c,p+2,2,false,&z)||!sxan_word(c,p+4,2,false,&len)||z<6||z>end-p||len>z-6||!sxan_add(c,&sxan_is3_directory,p)||!sxan_named(c,p+6,len))return false;p+=z;}
 if(!sxan_word(c,51,4,false,&p)||!sxan_word(c,55,4,false,&z)||!sxan_span(c,p,z)||!sxan_word(c,12,2,false,&n))return false;end=p+z;for(uint64_t i=0;i<n;i++){if(p>end||end-p<30||!sxan_word(c,p+23,2,false,&z)||!sxan_word(c,p+29,1,false,&len)||z<30||z>end-p||len>z-30||!sxan_add(c,&sxan_is3_member,p)||!sxan_named(c,p+30,len))return false;p+=z;}return true;}
static bool sxan_is5(sx_context*c){uint64_t version,desc,descz,table,z,dirs,n,second,p,no,len;if(!sxan_add(c,&sxan_is5_header,0)||!sxan_word(c,4,4,false,&version)||!sxan_word(c,12,4,false,&desc)||!sxan_word(c,16,4,false,&descz)||descz<48||!sxan_span(c,desc,descz)||!sxan_add(c,&sxan_is5_descriptor,desc))return false;unsigned major=(version>>24)==1?(unsigned)(version>>12)&15:0;if(desc>=36&&!sxan_add(c,&sxan_is5_volume_prefix,20))return false;if(!sxan_word(c,desc+12,4,false,&table)||!sxan_word(c,desc+20,4,false,&z)||!sxan_word(c,desc+28,4,false,&dirs)||!sxan_word(c,desc+40,4,false,&n)||!sxan_word(c,desc+44,4,false,&second))return false;table+=desc;if(!sxan_span(c,table,z)||dirs>z/4||!sxan_table(c,&sxan_is5_table_offset,table,4,dirs))return false;for(uint64_t i=0;i<dirs;i++){if(!sxan_word(c,table+4*i,4,false,&no)||no>=z||!sxan_zlen(c,table+no,table+z,&len)||!sxan_named(c,table+no,len))return false;}
 for(uint64_t i=0;i<n;i++){if(major>=6){if(second>z||i>=(z-second)/87)return false;p=table+second+i*87;if(!sxan_add(c,&sxan_is5_member_v6,p)||!sxan_word(c,p+58,4,false,&no))return false;}else{if(dirs+i>=z/4||!sxan_add(c,&sxan_is5_table_offset,table+4*(dirs+i))||!sxan_word(c,table+4*(dirs+i),4,false,&p)||p>z||z-p<42)return false;p+=table;if(!sxan_add(c,&sxan_is5_member_v5,p)||!sxan_word(c,p,4,false,&no))return false;}uint64_t flags,packed;if(!sxan_word(c,p+(major>=6?0:8),2,false,&flags)||!sxan_word(c,p+(major>=6?10:14),major>=6?8:4,false,&packed))return false;if(!(flags&8)&&packed&&no<z&&sxan_zlen(c,table+no,table+z,&len)&&!sxan_named(c,table+no,len))return false;}return true;}
static bool sxan_is11(sx_context*c){uint64_t version,p=13,z,len;if(!sxan_word(c,4,4,false,&version)||!sxan_add(c,&sxan_is11_header,0))return false;unsigned fixed=version==0x00030108?16:12;while(sxan_span(c,p,fixed)){if(!sxan_word(c,p+1,4,false,&z)||z>INT32_MAX||!sxan_word(c,p+fixed-1,1,false,&len)||!sxan_add(c,fixed==16?&sxan_is11_member_v3:&sxan_is11_member_v1,p)||!sxan_named(c,p+fixed,len)||!sxan_add(c,&sxan_archivenext_separator,p+fixed+len))return false;p+=fixed+len+1;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
static bool sxan_gk_header(sx_context*c,uint64_t p,uint64_t*z,uint64_t*attrs,bool*pop){uint8_t h[292];if(!sxan_read(c,p,h,sizeof(h)))return false;unsigned len=0;while(len<259&&h[len]){if(h[len]<32)return false;len++;}if(!len)return false;*z=sxan_uint(h+288,4,false);*attrs=sxan_uint(h+260,4,false);*pop=len==2&&h[0]=='.'&&h[1]=='.';return *z<=INT32_MAX;}
static bool sxan_gk(sx_context*c){uint64_t p,z,attrs;bool pop,padded=true;if(!sxan_add(c,&sxan_gksetup_banner,0)||!sxan_add(c,&sxan_gksetup_signature,80)||!sxan_add(c,&sxan_gksetup_data_offset,296)||!sxan_word(c,296,4,false,&p))return false;uint64_t q=p;for(unsigned i=0;i<2;i++){uint64_t zero;if(!sxan_gk_header(c,q,&z,&attrs,&pop)||!sxan_span(c,q+292,z)||!sxan_word(c,q+292,4,false,&zero)||zero){padded=false;break;}q+=296+z;}while(sxan_gk_header(c,p,&z,&attrs,&pop)){if(!sxan_add(c,&sxan_gksetup_member,p))return false;p+=292;if(padded){uint64_t zero;if(!sxan_word(c,p,4,false,&zero)||zero)return true;if(!sxan_add(c,&sxan_archivenext_padding32,p))return false;p+=4;}if(pop)continue;if(attrs&16){if(z)return true;continue;}if(!sxan_span(c,p,z))return true;p+=z;}return true;}
static bool sxan_pcinstall(sx_context*c){uint64_t n,p=56,z;if(!sxan_add(c,&sxan_pcinstall_header,0)||!sxan_word(c,14,2,false,&n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_add(c,&sxan_pcinstall_member,p)||!sxan_word(c,p+20,4,false,&z))return false;p+=48;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
static bool sxan_finstall(sx_context*c){uint64_t n;return sxan_add(c,&sxan_finstall_header,0)&&sxan_word(c,16,2,false,&n)&&sxan_table(c,&sxan_finstall_member,18,24,n);}
static bool sxan_ifah(sx_context*c){uint8_t h[4];uint64_t p=0,n,z,len;if(!sxan_read(c,0,h,4))return false;if(xx_rt_memcmp(h,"IFAH",4)&&!sxan_pe_overlay(c,&p))return false;if(!sxan_add(c,&sxan_ifah_header,p)||!sxan_word(c,p+13,4,false,&n))return false;p+=17;for(uint64_t i=0;i<n;i++){if(!sxan_add(c,&sxan_ifah_member,p)||!sxan_word(c,p+8,4,false,&z)||!sxan_word(c,p+28,1,false,&len)||!sxan_named(c,p+29,len))return false;p+=29+len;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
static bool sxan_osetup(sx_context*c){uint8_t h[8];uint64_t trailer,p,n,z;unsigned tag=8;if(c->size<14)return false;trailer=(uint64_t)c->size-14;if(!sxan_read(c,trailer,h,8))return false;if(xx_rt_memcmp(h,"OSETUPS\0",8)&&xx_rt_memcmp(h,"OSETUPA\0",8)){tag=6;trailer=(uint64_t)c->size-12;if(!sxan_read(c,trailer,h,6)||xx_rt_memcmp(h,"OSETUP",6))return false;}if(!sxan_add(c,tag==8?&sxan_osetup_trailer_8:&sxan_osetup_trailer_6,trailer)||!sxan_word(c,trailer+tag,4,false,&p)||!sxan_word(c,trailer+tag+4,2,false,&n))return false;for(uint64_t i=0;i<n;i++){if(p>trailer||trailer-p<44||!sxan_word(c,p+4,4,false,&z)||!sxan_add(c,&sxan_osetup_member,p))return false;p+=44;if(z>trailer-p)return true;p+=z;}return true;}
/* Native callback offsets are authenticated, physical, and already include
 * the reader base. They identify relocated PC-Install records and Spoon
 * directories without scanning the executable for coincidental strings. */
static bool sxan_callback(sx_context*c,unsigned kind){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return true;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return true;bool ok=true;uint64_t last=0,first=UINT64_MAX,nested_first=UINT64_MAX;for(unsigned i=0;i<SXAN_LIMIT;i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;if(r->header_offset>=f->base_address&&r->header_size>0){uint64_t p=(uint64_t)(r->header_offset-f->base_address),z=(uint64_t)r->header_size;if(sxan_span(c,p,z)){if(kind==1&&z>=17){ok=sxan_add(c,&sxan_spoon_member,p)&&sxan_named(c,p+17,z-17);if(p+z>last)last=p+z;}else if(kind==2){if(z==276){ok=sxan_add(c,&sxan_pc_install_member,p);if(p<first)first=p;/* The native stream publishes authenticated nested entries before the raw group. A prefix match alone is insufficient. */if(nested_first==p+276+58&&r->compressed_size>=58&&r->data_offset==r->header_offset+276)ok=ok&&sxan_add(c,&sxan_pc_install_group,p+276);nested_first=UINT64_MAX;}else if(z==168){if(p<nested_first)nested_first=p;ok=sxan_add(c,&sxan_pc_install_group_member,p);}}}}if(!ok||!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);if(!ok)return false;if(kind==1&&last&&sxan_span(c,last,24))return sxan_add(c,&sxan_spoon_footer,last);if(kind==2){if(first>=8&&first!=UINT64_MAX&&!sxan_add(c,&sxan_pc_install_tag,first-8))return false;return c->size<16||sxan_add(c,&sxan_pc_install_trailer,(uint64_t)c->size-16);}return true;}
static bool sxan_rtsetup(sx_context*c){uint64_t p=0,n,z;while(sxan_span(c,p,16)){if(!sxan_word(c,p,4,false,&z)||z>INT32_MAX||!sxan_word(c,p+14,2,false,&n)||n<2||n>13||!sxan_add(c,&sxan_rtpatch_setup_member,p)||!sxan_named(c,p+16,n))return false;p+=16+n;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
static bool sxan_issetup(sx_context*c){uint8_t h[14];uint64_t p=0,n,z,len;if(!sxan_read(c,0,h,14))return false;if(xx_rt_memcmp(h,"ISSetupStream\0",14)&&!sxan_pe_overlay(c,&p))return false;if(!sxan_add(c,&sxan_issetup_header,p)||!sxan_word(c,p+14,2,false,&n))return false;p+=46;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,p,4,false,&len)||!sxan_word(c,p+10,4,false,&z)||!sxan_add(c,&sxan_issetup_member,p)||!sxan_span(c,p+24,len))return true;if(!(len&1)&&!sxan_text(c,&sxan_archivenext_utf16le,p+24,len,false))return false;p+=24+len;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
static bool sxan_epsf(sx_context*c){uint64_t p;return sxan_pe_overlay(c,&p)&&sxan_add(c,&sxan_epsf_header,p);}
static bool sxan_sf_name(const uint8_t*h,unsigned width){unsigned i=0;for(;i<width&&h[i];i++)if(h[i]<32||h[i]>126||h[i]=='/'||h[i]=='\\'||h[i]==':')return false;if(!i||i==width)return false;for(;i<width;i++)if(h[i])return false;return true;}
static bool sxan_setup_factory(sx_context*c){uint64_t p,n,z;uint8_t h[268];if(!sxan_pe_overlay(c,&p)||!sxan_add(c,&sxan_setup_factory_header,p)||!sxan_word(c,p+8,4,false,&n))return false;p+=12;unsigned width=0;for(uint64_t i=0;i<n;i++){if(!width){if(sxan_read(c,p,h,268)&&sxan_sf_name(h,260)&&sxan_uint(h+260,4,false))width=260;else width=16;}if(!sxan_word(c,p+width,4,false,&z)||!z||!sxan_add(c,width==260?&sxan_setup_factory_engine_260:&sxan_setup_factory_engine_16,p))return false;p+=width+8;if(!sxan_span(c,p,z))return true;p+=z;}return true;}

static bool sxan_westwood(sx_context*c){uint64_t end,p=0,z,len;if(!sxan_word(c,0,4,false,&end)||!sxan_span(c,0,end))return false;while(p<end){if(end-p<4||!sxan_word(c,p,4,false,&z)||!sxan_add(c,&sxan_westwood_offset,p))return false;p+=4;if(!z)break;if(p==end)break;if(!sxan_zlen(c,p,end,&len)||!sxan_named(c,p,len))return false;p+=len;}return true;}
static bool sxan_ckpedp(sx_context*c){uint64_t n,p=14,len;unsigned width=c->f->file_type==XX_FILE_TYPE_EDP?2:1;if(!sxan_add(c,&sxan_ckpedp_header,0)||!sxan_word(c,6,4,false,&n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,p,2,false,&len)||!sxan_add(c,&sxan_ckpedp_name_size,p)||!sxan_span(c,p+2,len*width)||!sxan_text(c,&sxan_ckpedp_encoded_name,p+2,len*width,false))return false;p+=2+len*width;if(!sxan_add(c,&sxan_ckpedp_member_tail,p))return false;p+=20;}return true;}
static bool sxan_parsec(sx_context*c){uint64_t z,n,p,len;uint8_t h[8];if(c->f->file_type==XX_FILE_TYPE_PARSEC_RIB)return sxan_add(c,&sxan_parsec_rib_header,0);if(!sxan_word(c,0,4,false,&z)||z<12||(z-4)%8||!sxan_span(c,0,z))return false;n=(z-4)/8;if(!sxan_table(c,&sxan_parsec_member_offset,0,4,n+1)||!sxan_table(c,&sxan_parsec_member_size,4*(n+1),4,n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,4*i,4,false,&p)||!sxan_word(c,4*(n+1+i),4,false,&len))return false;if(len>=8&&sxan_span(c,p,len)&&sxan_read(c,p,h,8)&&!xx_rt_memcmp(h,"RIB\0",4)&&!sxan_add(c,&sxan_parsec_rib_header,p))return false;}return true;}
static bool sxan_ptero(sx_context*c){uint64_t n,p,z,end,len,at,packed,method;if(!sxan_add(c,&sxan_ptero_header,0)||!sxan_word(c,16,4,false,&n)||!sxan_word(c,20,8,false,&p)||!sxan_word(c,28,8,false,&z)||!sxan_span(c,p,z))return false;end=p+z;for(uint64_t i=0;i<n;i++){if(p>end||end-p<40||!sxan_add(c,&sxan_ptero_member,p)||!sxan_word(c,p,8,false,&at)||!sxan_word(c,p+28,4,false,&packed)||!sxan_word(c,p+32,4,false,&method)||!sxan_zlen(c,p+40,end,&len)||!sxan_named(c,p+40,len))return false;p+=40+len;if(method==1&&sxan_span(c,at,packed)){uint64_t stop=at+packed;while(at<stop){uint8_t h[12];if(stop-at<12||!sxan_read(c,at,h,12)||xx_rt_memcmp(h,"[..]",4))break;z=sxan_uint(h+4,4,false);if(z>stop-at-12||!sxan_add(c,&sxan_ptero_block,at))return false;at+=12+z;}}}return true;}
static bool sxan_titan(sx_context*c){uint64_t n,blocks,p,z,names,namesz,rows,off,len;if(!sxan_add(c,&sxan_titan_header,0)||!sxan_word(c,8,4,false,&n)||!sxan_word(c,12,4,false,&blocks)||!sxan_word(c,16,4,false,&z)||!sxan_word(c,20,4,false,&namesz)||!sxan_word(c,24,4,false,&p))return false;names=p+z;rows=names+namesz;if(!sxan_span(c,names,namesz)||!sxan_table(c,&sxan_titan_block,p,12,blocks)||!sxan_table(c,&sxan_titan_member,rows,44,n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,rows+44*i+36,4,false,&len)||!sxan_word(c,rows+44*i+40,4,false,&off)||off>=namesz||len>=namesz-off||!sxan_named(c,names+off,len+1))return false;}return true;}
static bool sxan_cgjp(sx_context*c){uint64_t p=0,z,plain;uint8_t h[4];while(sxan_read(c,p,h,4)){if(!xx_rt_memcmp(h,"CGJP",4)){if(!sxan_add(c,&sxan_cgjp_signature,p))return false;p+=4;continue;}plain=sxan_uint(h,2,false);z=sxan_uint(h+2,2,false);if(!plain||plain>32768||z>32768||!sxan_add(c,&sxan_cgjp_block,p))return false;p+=4;if(!z)z=plain;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
static bool sxan_birdies(sx_context*c){uint64_t n,p=8,len;if(!sxan_add(c,&sxan_birdies_header,0)||!sxan_word(c,4,4,false,&n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_zlen(c,p,(uint64_t)c->size,&len)||!sxan_named(c,p,len)||!sxan_add(c,&sxan_birdies_member,p+len))return false;p+=len+8;}return true;}
static bool sxan_xuiz_walk(sx_context*c,uint64_t n,uint64_t end,unsigned extra,bool emit){uint64_t p=22,len;for(uint64_t i=0;i<n;i++){if(p>end||end-p<9+extra||!sxan_word(c,p+8+extra,1,false,&len)||!len||2*len>end-p-9-extra)return false;if(emit&&(!sxan_add(c,extra?&sxan_xuiz_member_10:&sxan_xuiz_member_0,p)||!sxan_text(c,&sxan_archivenext_utf16be,p+9+extra,len*2,false)))return false;p+=9+extra+len*2;}return p==end;}
static bool sxan_xuiz(sx_context*c){uint64_t n,z;if(!sxan_add(c,&sxan_xuiz_header,0)||!sxan_word(c,16,4,true,&z)||!sxan_word(c,20,2,true,&n)||!sxan_span(c,22,z))return false;bool short_ok=sxan_xuiz_walk(c,n,22+z,0,false),long_ok=sxan_xuiz_walk(c,n,22+z,10,false);if(short_ok==long_ok)return true;return sxan_xuiz_walk(c,n,22+z,long_ok?10:0,true);}
static bool sxan_dcs(sx_context*c){uint64_t n,p=12,z;if(!sxan_add(c,&sxan_dcs_header,0)||!sxan_word(c,4,4,false,&n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_word(c,p,4,false,&z)||z<4||!sxan_add(c,&sxan_dcs_block,p))return false;p+=8;if(!sxan_span(c,p,z-4))return true;p+=z-4;}return true;}
static bool sxan_line(sx_context*c,uint64_t p,uint64_t*end){uint8_t b;*end=p;for(unsigned i=0;i<8192;i++){if(!sxan_read(c,*end,&b,1))return false;if(b==13){uint8_t next;if(!sxan_read(c,*end+1,&next,1)||next!=10)return false;return true;}if(b<32&&b!=9)return false;(*end)++;}return false;}
static bool sxan_audials(sx_context*c){uint64_t p=0,end,n=0;if(!sxan_line(c,p,&end)||end<=12||end-12>20)return false;uint8_t digits[20];if(!sxan_read(c,12,digits,(size_t)(end-12)))return false;for(uint64_t i=0;i<end-12;i++){if(digits[i]==' ')continue;if(digits[i]<'0'||digits[i]>'9'||n>65536)return false;n=n*10+digits[i]-'0';}if(!sxan_text(c,&sxan_audials_count,12,end-12,false))return false;p=end+2;for(uint64_t i=0;i<n;i++){uint64_t tab1=p,tab2;uint8_t b;if(!sxan_line(c,p,&end))return false;while(tab1<end){if(!sxan_read(c,tab1,&b,1))return false;if(b==9)break;tab1++;}tab2=tab1+1;while(tab2<end){if(!sxan_read(c,tab2,&b,1))return false;if(b==9)break;tab2++;}if(tab1>=end||tab2>=end||!sxan_named(c,p,tab1-p)||!sxan_text(c,&sxan_audials_offset,tab1+1,tab2-tab1-1,false)||!sxan_text(c,&sxan_audials_size,tab2+1,end-tab2-1,false))return false;p=end+2;}return true;}

static bool sxan_wad(sx_context*c){uint8_t h[32];uint64_t p=64,n;if(!sxan_read(c,0,h,32)||!sxan_add(c,&sxan_wad_header,0))return false;for(unsigned i=0;i<6;i++){uint64_t z=sxan_uint(h+8+4*i,4,true);if(!z)continue;if(!sxan_span(c,p,z))return true;if(i==2&&z>=676){if(!sxan_add(c,&sxan_wad_rsa2048,p)||!sxan_add(c,&sxan_wad_ticket,p+320)||!sxan_table(c,&sxan_wad_limit,p+612,8,8))return false;}if(i==3&&z>=484){if(!sxan_add(c,&sxan_wad_rsa2048,p)||!sxan_add(c,&sxan_wad_tmd,p+320)||!sxan_word(c,p+478,2,true,&n)||n>(z-484)/36||!sxan_table(c,&sxan_wad_content,p+484,36,n))return false;}p=(p+z+63)&~UINT64_C(63);}return true;}
typedef struct sxan_stfs{uint64_t first;uint32_t allocated;unsigned sex,level;uint64_t top;}sxan_stfs;
static uint64_t sxan_stfs_data(const sxan_stfs*v,uint32_t b){uint64_t p=b+(((uint64_t)b+170)/170<<v->sex);if(b>=170)p+=((uint64_t)b+28900)/28900<<v->sex;if(b>=28900)p+=UINT64_C(1)<<v->sex;return v->first+p*4096;}
static uint64_t sxan_stfs_table(const sxan_stfs*v,uint32_t b,unsigned level){uint64_t copies=UINT64_C(1)<<v->sex,step0=170+copies,step1=28900+171*copies,p;if(level==2)p=step1;else if(level==1)p=b<28900?step0:copies+(uint64_t)(b/28900)*step1;else if(b<170)p=0;else p=(uint64_t)(b/170)*step0+(((uint64_t)b/28900+1)<<v->sex)+(b>=28900?copies:0);return v->first+p*4096;}
static bool sxan_stfs_bottom(sx_context*c,const sxan_stfs*v,uint32_t block,uint64_t*out){uint8_t h[24];uint64_t parent;if(!v->level){*out=v->top;return true;}if(v->level==1)parent=v->top+(block/170)*24;else{uint64_t upper=v->top+(block/28900)*24;if(!sxan_read(c,upper,h,24)||!sxan_add(c,&sxan_stfs_hash_entry,upper))return false;uint64_t middle=sxan_stfs_table(v,block,1)+(v->sex?(uint64_t)(h[20]&64)*64:0);parent=middle+((block/170)%170)*24;}if(!sxan_read(c,parent,h,24)||!sxan_add(c,&sxan_stfs_hash_entry,parent))return false;*out=sxan_stfs_table(v,block,0)+(v->sex?(uint64_t)(h[20]&64)*64:0);return sxan_span(c,*out,4096);}
static bool sxan_pirs(sx_context*c){sxan_stfs v;uint64_t hs,blocks,start,allocated,flags;if(!sxan_add(c,&sxan_stfs_signature,0)||!sxan_add(c,&sxan_stfs_metadata_digest,0x32c)||!sxan_add(c,&sxan_stfs_volume_le,0x379)||!sxan_add(c,&sxan_stfs_volume_be,0x381)||!sxan_add(c,&sxan_stfs_data_file_count,0x3a9)||!sxan_word(c,0x340,4,true,&hs)||!sxan_word(c,0x395,4,true,&allocated)||!sxan_word(c,0x37b,1,false,&flags)||!sxan_word(c,0x37c,2,false,&blocks)||!sxan_word(c,0x37e,3,false,&start))return false;if(!allocated||allocated>1000000||start>=allocated||blocks>allocated)return true;v.first=(hs+4095)&~UINT64_C(4095);v.allocated=(uint32_t)allocated;v.sex=(unsigned)(~flags)&1;v.level=allocated<=170?0:allocated<=28900?1:2;v.top=sxan_stfs_table(&v,0,v.level)+(flags&2)*2048;if(!sxan_span(c,v.top,4096))return true;
 for(uint32_t block=0;block<v.allocated;block+=170){uint64_t bottom;if(!sxan_stfs_bottom(c,&v,block,&bottom)||!sxan_table(c,&sxan_stfs_hash_entry,bottom,24,v.allocated-block<170?v.allocated-block:170))return false;}
 uint32_t block=(uint32_t)start;for(uint64_t i=0;i<blocks;i++){uint64_t bottom,next,p;if(block>=v.allocated||!sxan_stfs_bottom(c,&v,block,&bottom)||!sxan_word(c,bottom+(block%170)*24+21,3,true,&next))return true;p=sxan_stfs_data(&v,block);if(!sxan_span(c,p,4096))return true;for(unsigned j=0;j<64;j++){uint64_t len;if(!sxan_word(c,p+64*j+40,1,false,&len))return false;if(!(len&63))continue;if((len&63)>40)return true;if(!sxan_add(c,&sxan_stfs_file_le,p+64*j)||!sxan_add(c,&sxan_stfs_file_be,p+64*j+50))return false;}block=(uint32_t)next;}return true;}
static bool sxan_lha(sx_context*c){uint64_t p=0;while(sxan_span(c,p,1)){uint8_t h[22];if(!sxan_read(c,p,h,1))return false;if(!h[0])return sxan_add(c,&sxan_lha_dialect_end,p);if(!sxan_read(c,p,h,22))return true;uint64_t total=(uint64_t)h[0]+2,packed=sxan_uint(h+7,4,false),len=h[21],q,next=0,used=0;if(h[20]>1||total<24+len||!sxan_span(c,p,total)||!sxan_add(c,&sxan_lha_dialect_header,p)||!sxan_named(c,p+22,len)||!sxan_add(c,&sxan_lha_dialect_crc,p+22+len))return false;q=p+total;if(h[20]==1){if(total<27+len||!sxan_add(c,&sxan_lha_dialect_os,p+24+len)||!sxan_add(c,&sxan_lha_dialect_next,p+total-2)||!sxan_word(c,p+total-2,2,false,&next))return false;for(unsigned i=0;next&&i<SXAN_LIMIT;i++){uint64_t z=next;if(z<3||used>packed||z>packed-used||!sxan_span(c,q,z)||!sxan_add(c,&sxan_lha_dialect_type,q)||!sxan_add(c,&sxan_lha_dialect_next,q+z-2)||!sxan_word(c,q+z-2,2,false,&next))return false;uint64_t type;if(!sxan_word(c,q,1,false,&type))return false;if(type==0&&z>=5){if(!sxan_add(c,&sxan_lha_dialect_crc,q+1))return false;}else if((type==1||type==2)&&!sxan_named(c,q+1,z-3))return false;q+=z;used+=z;}}if(used>packed||!sxan_span(c,q,packed-used))return true;p=q+packed-used;}return true;}
static bool sxan_bytekiller(sx_context*c){uint64_t head,foot,z;if(c->size<12||!sxan_word(c,0,4,true,&head)||!sxan_word(c,(uint64_t)c->size-4,4,true,&foot))return false;switch(head){case 0x41434521:return sxan_add(c,&sxan_bytekiller_ace_header,0);case 0x46564c30:if(!sxan_word(c,4,4,true,&z)||z<8)return false;return sxan_add(c,&sxan_bytekiller_anc_header,0)&&sxan_add(c,&sxan_bytekiller_footer,z);case 0x47523230:return sxan_add(c,&sxan_bytekiller_grac_header,0)&&sxan_add(c,&sxan_bytekiller_footer,(uint64_t)c->size-8);case 0x4d443130:return sxan_add(c,&sxan_bytekiller_signature,0)&&sxan_add(c,&sxan_bytekiller_footer,(uint64_t)c->size-8);case 0x4d443131:return sxan_add(c,&sxan_bytekiller_md11_header,0)&&sxan_add(c,&sxan_bytekiller_footer,(uint64_t)c->size-8);default:if(foot==0x4a454b21)return c->size>=16&&sxan_add(c,&sxan_bytekiller_footer,(uint64_t)c->size-12)&&sxan_add(c,&sxan_bytekiller_signature,(uint64_t)c->size-4);if(!sxan_add(c,&sxan_bytekiller_header,0))return false;return foot!=0x64617461||sxan_add(c,&sxan_bytekiller_signature,head+12);}}
static uint8_t sxan_rol8(uint8_t b){return (uint8_t)((b<<1)|(b>>7));}
static uint8_t sxan_ror8(uint8_t b){return (uint8_t)((b>>1)|(b<<7));}
static bool sxan_osl(sx_context*c){uint64_t p=3;if(!sxan_add(c,&sxan_osl_signature,0))return false;while(sxan_span(c,p,16)){uint8_t b[16];if(!sxan_read(c,p,b,16))return false;for(unsigned i=16;i--;){uint8_t v=b[i];if(i)v=b[i-1]^(uint8_t)(sxan_rol8(v)+i);b[i]=(uint8_t)(sxan_ror8(v)-i)^90;}if(sxan_uint(b,2,false)!=0x4948)return true;uint64_t z=sxan_uint(b+2,4,false);if(!sxan_add(c,&sxan_osl_encoded_record,p))return false;p+=16;if(!sxan_span(c,p,z+2))return true;if(!sxan_add(c,&sxan_osl_payload_checksum,p+z))return false;p+=z+2;}return true;}
static bool sxan_sbpak(sx_context*c){uint8_t h[52];if(!sxan_read(c,0,h,52))return false;uint8_t key=h[28];for(unsigned i=0;i<52;i++)h[i]^=key;uint64_t n=sxan_uint(h+36,4,false);return sxan_add(c,key?&sxan_sbpak_encoded_header:&sxan_sbpak_header,0)&&sxan_table(c,key?&sxan_sbpak_encoded_member:&sxan_sbpak_member,52,16,n);}

static const sx_layout*const sxan_fa_type[9]={&sxan_freearc_type1,&sxan_freearc_type2,&sxan_freearc_type3,&sxan_freearc_type4,&sxan_freearc_type5,&sxan_freearc_type6,&sxan_freearc_type7,&sxan_freearc_type8,&sxan_freearc_type9};
static const sx_layout*const sxan_fa_count[9]={&sxan_freearc_count1,&sxan_freearc_count2,&sxan_freearc_count3,&sxan_freearc_count4,&sxan_freearc_count5,&sxan_freearc_count6,&sxan_freearc_count7,&sxan_freearc_count8,&sxan_freearc_count9};
static const sx_layout*const sxan_fa_offset[9]={&sxan_freearc_offset1,&sxan_freearc_offset2,&sxan_freearc_offset3,&sxan_freearc_offset4,&sxan_freearc_offset5,&sxan_freearc_offset6,&sxan_freearc_offset7,&sxan_freearc_offset8,&sxan_freearc_offset9};
static const sx_layout*const sxan_fa_size[9]={&sxan_freearc_size1,&sxan_freearc_size2,&sxan_freearc_size3,&sxan_freearc_size4,&sxan_freearc_size5,&sxan_freearc_size6,&sxan_freearc_size7,&sxan_freearc_size8,&sxan_freearc_size9};
static const sx_layout*const sxan_fa_packed[9]={&sxan_freearc_packed1,&sxan_freearc_packed2,&sxan_freearc_packed3,&sxan_freearc_packed4,&sxan_freearc_packed5,&sxan_freearc_packed6,&sxan_freearc_packed7,&sxan_freearc_packed8,&sxan_freearc_packed9};
static const sx_layout*const sxan_fa_index[9]={&sxan_freearc_index1,&sxan_freearc_index2,&sxan_freearc_index3,&sxan_freearc_index4,&sxan_freearc_index5,&sxan_freearc_index6,&sxan_freearc_index7,&sxan_freearc_index8,&sxan_freearc_index9};
static bool sxan_fa_num(sx_context*c,uint64_t*p,uint64_t end,uint64_t*v,const sx_layout*const*layouts,bool emit){uint8_t b[9];if(*p>=end||!sxan_read(c,*p,b,1))return false;unsigned extra=0;while(extra<8&&(b[0]&(1U<<extra)))extra++;unsigned width=extra+1;if(width>end-*p||!sxan_read(c,*p,b,width))return false;*v=0;if(extra==8){for(unsigned i=0;i<8;i++)*v|=(uint64_t)b[i+1]<<(8*i);}else{for(unsigned i=0;i<width;i++)*v|=(uint64_t)b[i]<<(8*i);*v>>=width;}if(*v>INT64_MAX|| (emit&&!sxan_add(c,layouts[width-1],*p)))return false;*p+=width;return true;}
static bool sxan_crc32(sx_context*c,uint64_t p,uint64_t n,uint64_t*out){uint8_t b[1024];uint32_t v=UINT32_MAX;if(!sxan_span(c,p,n))return false;while(n){size_t take=n<sizeof(b)?(size_t)n:sizeof(b);if(xx_pd_is_stopped(c->pd)||!sxan_read(c,p,b,take))return false;for(size_t i=0;i<take;i++){v^=b[i];for(unsigned k=0;k<8;k++)v=(v>>1)^(0xedb88320U&(0U-(v&1)));}p+=take;n-=take;}*out=~v;return true;}
typedef struct sxan_fa_desc{uint64_t type,packed,plain,start,end,crc;bool stored;}sxan_fa_desc;
static bool sxan_fa_string(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l,bool emit,bool*stored){uint64_t n;uint8_t b[8];if(!sxan_zlen(c,*p,end,&n))return false;if(stored)*stored=n==8&&sxan_read(c,*p,b,8)&&!xx_rt_memcmp(b,"storing\0",8);if(emit&&!sxan_text(c,l,*p,n,false))return false;*p+=n;return true;}
static bool sxan_fa_descriptor(sx_context*c,uint64_t at,sxan_fa_desc*d,bool emit){uint8_t b[4];uint64_t p=at+4,own,actual;if(!sxan_read(c,at,b,4)||xx_rt_memcmp(b,"ArC\1",4)||!sxan_fa_num(c,&p,(uint64_t)c->size,&d->type,sxan_fa_type,false)||!sxan_fa_string(c,&p,(uint64_t)c->size,&sxan_freearc_method,false,&d->stored)||p-at>1040||!sxan_fa_num(c,&p,(uint64_t)c->size,&d->plain,sxan_fa_size,false)||!sxan_fa_num(c,&p,(uint64_t)c->size,&d->packed,sxan_fa_packed,false)||!sxan_word(c,p,4,false,&d->crc)||!sxan_word(c,p+4,4,false,&own)||d->packed>at||!sxan_crc32(c,at,p+4-at,&actual)||own!=actual)return false;d->start=at-d->packed;d->end=p+8;if(emit){uint64_t v;p=at+4;if(!sxan_add(c,&sxan_freearc_magic,at)||!sxan_fa_num(c,&p,d->end,&v,sxan_fa_type,true)||!sxan_fa_string(c,&p,d->end,&sxan_freearc_method,true,NULL)||!sxan_fa_num(c,&p,d->end,&v,sxan_fa_size,true)||!sxan_fa_num(c,&p,d->end,&v,sxan_fa_packed,true)||!sxan_add(c,&sxan_freearc_crc,p)||!sxan_add(c,&sxan_freearc_crc,p+4))return false;}return true;}
static bool sxan_fa_directory(sx_context*c,uint64_t p,uint64_t z){uint64_t end=p+z,blocks,files=0,dirs,v;if(!sxan_span(c,p,z)||!sxan_fa_num(c,&p,end,&blocks,sxan_fa_count,true)||blocks>SXAN_LIMIT)return false;for(uint64_t i=0;i<blocks;i++){if(!sxan_fa_num(c,&p,end,&v,sxan_fa_count,true)||v>SXAN_LIMIT-files)return false;files+=v;}for(uint64_t i=0;i<blocks;i++)if(!sxan_fa_string(c,&p,end,&sxan_freearc_method,true,NULL))return false;for(uint64_t i=0;i<blocks;i++)if(!sxan_fa_num(c,&p,end,&v,sxan_fa_offset,true))return false;for(uint64_t i=0;i<blocks;i++)if(!sxan_fa_num(c,&p,end,&v,sxan_fa_packed,true))return false;if(!sxan_fa_num(c,&p,end,&dirs,sxan_fa_count,true)||dirs>SXAN_LIMIT)return false;for(uint64_t i=0;i<dirs+files;i++)if(!sxan_fa_string(c,&p,end,&sxan_archivenext_name,true,NULL))return false;for(uint64_t i=0;i<files;i++)if(!sxan_fa_num(c,&p,end,&v,sxan_fa_index,true))return false;for(uint64_t i=0;i<files;i++)if(!sxan_fa_num(c,&p,end,&v,sxan_fa_size,true))return false;if(files>(end-p)/4||!sxan_table(c,&sxan_freearc_time,p,4,files))return false;p+=4*files;if(files>end-p||!sxan_table(c,&sxan_freearc_folder,p,1,files))return false;p+=files;if(files>(end-p)/4||!sxan_table(c,&sxan_freearc_crc,p,4,files))return false;return true;}
static bool sxan_freearc(sx_context*c){sxan_fa_desc header,footer;if(!sxan_add(c,&sxan_freearc_header,0))return false;if(sxan_fa_descriptor(c,8,&header,false)&&header.type==1&&!sxan_fa_descriptor(c,8,&header,true))return false;uint64_t size=(uint64_t)c->size,low=size>4096?size-4096:0,at=size>=4?size-4:0;bool found=false;if(size<4)return true;for(;;){if(sxan_fa_descriptor(c,at,&footer,false)&&footer.type==4){found=true;break;}if(at==low)break;at--;}if(!found)return true;if(!sxan_fa_descriptor(c,at,&footer,true))return false;uint64_t actual;if(!footer.stored||footer.packed!=footer.plain||!sxan_crc32(c,footer.start,footer.packed,&actual)||actual!=footer.crc)return true;uint64_t p=footer.start,end=footer.start+footer.packed,n;if(!sxan_fa_num(c,&p,end,&n,sxan_fa_count,true)||n>SXAN_LIMIT)return false;for(uint64_t i=0;i<n;i++){uint64_t type,dist,plain,packed,crc;bool stored;if(!sxan_fa_num(c,&p,end,&type,sxan_fa_type,true)||!sxan_fa_string(c,&p,end,&sxan_freearc_method,true,&stored)||!sxan_fa_num(c,&p,end,&dist,sxan_fa_offset,true)||!sxan_fa_num(c,&p,end,&plain,sxan_fa_size,true)||!sxan_fa_num(c,&p,end,&packed,sxan_fa_packed,true)||!sxan_word(c,p,4,false,&crc)||!sxan_add(c,&sxan_freearc_crc,p))return false;p+=4;if(dist>footer.start||packed>dist)continue;uint64_t start=footer.start-dist; sxan_fa_desc d;if(sxan_fa_descriptor(c,start+packed,&d,false)&&d.type==type&&d.start==start&&d.packed==packed&&d.plain==plain&&d.crc==crc&&!sxan_fa_descriptor(c,start+packed,&d,true))return false;if(type==3&&stored&&packed==plain&&sxan_crc32(c,start,packed,&actual)&&actual==crc&&!sxan_fa_directory(c,start,packed))return false;}return true;}

static bool sxan_zpaq(sx_context*c){static const uint8_t locator[13]={0x37,0x6b,0x53,0x74,0xa0,0x31,0x83,0xd3,0x8c,0xb2,0x28,0xb0,0xd3};static const uint8_t width[10]={0,2,3,2,3,4,6,6,3,5};static const sx_layout*const layouts[10]={NULL,&sxan_zpaq_cons,&sxan_zpaq_cm,&sxan_zpaq_icm,&sxan_zpaq_match,&sxan_zpaq_avg,&sxan_zpaq_mix2,&sxan_zpaq_mix,&sxan_zpaq_isse,&sxan_zpaq_sse};uint64_t p=0;for(unsigned blocks=0;blocks<SXAN_LIMIT&&p<(uint64_t)c->size;blocks++){uint8_t h[13];if(sxan_read(c,p,h,13)&&!xx_rt_memcmp(h,locator,13)){if(!sxan_add(c,&sxan_zpaq_locator,p))return false;p+=13;}if(!sxan_read(c,p,h,7)||xx_rt_memcmp(h,"zPQ",3))return true;uint64_t z=sxan_uint(h+5,2,false);if(z<7||!sxan_span(c,p+7,z)||!sxan_add(c,&sxan_zpaq_block,p))return false;p+=7;uint64_t header_end=p+z;if(!sxan_read(c,p,h,5)||!sxan_add(c,&sxan_zpaq_model,p))return false;unsigned count=h[4];p+=5;for(unsigned i=0;i<count;i++){uint64_t kind;if(!sxan_word(c,p,1,false,&kind)||kind<1||kind>9||p>header_end||width[kind]>header_end-p||!sxan_add(c,layouts[kind],p))return false;p+=width[kind];}if(p>=header_end||!sxan_add(c,&sxan_zpaq_marker,p))return false;if(header_end-1>p&&!sxan_add(c,&sxan_zpaq_marker,header_end-1))return false;p=header_end;for(unsigned segments=0;segments<SXAN_LIMIT;segments++){uint64_t marker,len;if(!sxan_word(c,p,1,false,&marker)||!sxan_add(c,&sxan_zpaq_marker,p))return false;p++;if(marker==255)break;if(marker!=1)return true;if(!sxan_zlen(c,p,(uint64_t)c->size,&len)||!sxan_named(c,p,len))return false;p+=len;if(!sxan_zlen(c,p,(uint64_t)c->size,&len)||!sxan_text(c,&sxan_zpaq_comment,p,len,false))return false;p+=len;if(!sxan_add(c,&sxan_zpaq_marker,p))return false;p++;
 /* Arithmetic-coded segment ends require execution of the probability model.
  * Preserve that opaque suffix instead of searching for marker-like bytes. */
 if(count)return true;for(unsigned runs=0;runs<SXAN_LIMIT;runs++){if(!sxan_word(c,p,4,true,&z)||!sxan_add(c,&sxan_zpaq_stored_run,p))return false;p+=4;if(!z)break;if(!sxan_span(c,p,z))return true;p+=z;}if(!sxan_word(c,p,1,false,&marker)||!sxan_add(c,&sxan_zpaq_marker,p))return false;p++;if(marker==253){if(!sxan_add(c,&sxan_zpaq_sha1,p))return false;p+=20;}else if(marker!=254)return true;}}return true;}

static bool sx_archivenext_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_IS3:case XX_FILE_TYPE_IS5:case XX_FILE_TYPE_IS11:case XX_FILE_TYPE_GKSETUP:case XX_FILE_TYPE_PCINSTALL:case XX_FILE_TYPE_FINSTALL:case XX_FILE_TYPE_IFAH_INSTALLER:case XX_FILE_TYPE_O_SETUP:case XX_FILE_TYPE_PC_INSTALL_SETUP:case XX_FILE_TYPE_RTPATCH_SETUP_DATA:case XX_FILE_TYPE_SPOON_INSTALLER:case XX_FILE_TYPE_INSTALLSHIELD_ISSETUPSTREAM:case XX_FILE_TYPE_ESCHALON_SETUP_EPSF:case XX_FILE_TYPE_SETUP_FACTORY:case XX_FILE_TYPE_WESTWOOD_PAK:case XX_FILE_TYPE_CKP:case XX_FILE_TYPE_EDP:case XX_FILE_TYPE_PARSEC_RIB:case XX_FILE_TYPE_PARSEC_ARCHIVE:case XX_FILE_TYPE_PTERO_BIGF:case XX_FILE_TYPE_PIRS:case XX_FILE_TYPE_SBPAK:case XX_FILE_TYPE_TITAN_QUEST:case XX_FILE_TYPE_CGJP:case XX_FILE_TYPE_BIRDIES:case XX_FILE_TYPE_XUIZ:case XX_FILE_TYPE_WII_WAD:case XX_FILE_TYPE_FREEARC:case XX_FILE_TYPE_ZPAQ:case XX_FILE_TYPE_BYTEKILLER:case XX_FILE_TYPE_DCS:case XX_FILE_TYPE_AUDIALS:case XX_FILE_TYPE_OSL2000:case XX_FILE_TYPE_MICROFOX_PUT:case XX_FILE_TYPE_SAR:return true;default:return false;}}
static bool sx_archivenext_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_IS3:ok=sxan_is3(c);break;case XX_FILE_TYPE_IS5:ok=sxan_is5(c);break;case XX_FILE_TYPE_IS11:ok=sxan_is11(c);break;case XX_FILE_TYPE_GKSETUP:ok=sxan_gk(c);break;case XX_FILE_TYPE_PCINSTALL:ok=sxan_pcinstall(c);break;case XX_FILE_TYPE_FINSTALL:ok=sxan_finstall(c);break;case XX_FILE_TYPE_IFAH_INSTALLER:ok=sxan_ifah(c);break;case XX_FILE_TYPE_O_SETUP:ok=sxan_osetup(c);break;case XX_FILE_TYPE_PC_INSTALL_SETUP:ok=sxan_callback(c,2);break;case XX_FILE_TYPE_RTPATCH_SETUP_DATA:ok=sxan_rtsetup(c);break;case XX_FILE_TYPE_SPOON_INSTALLER:ok=sxan_callback(c,1);break;case XX_FILE_TYPE_INSTALLSHIELD_ISSETUPSTREAM:ok=sxan_issetup(c);break;case XX_FILE_TYPE_ESCHALON_SETUP_EPSF:ok=sxan_epsf(c);break;case XX_FILE_TYPE_SETUP_FACTORY:ok=sxan_setup_factory(c);break;case XX_FILE_TYPE_WESTWOOD_PAK:ok=sxan_westwood(c);break;case XX_FILE_TYPE_CKP:ok=sxan_ckpedp(c);break;case XX_FILE_TYPE_EDP:ok=sxan_ckpedp(c);break;case XX_FILE_TYPE_PARSEC_RIB:ok=sxan_parsec(c);break;case XX_FILE_TYPE_PARSEC_ARCHIVE:ok=sxan_parsec(c);break;case XX_FILE_TYPE_PTERO_BIGF:ok=sxan_ptero(c);break;case XX_FILE_TYPE_PIRS:ok=sxan_pirs(c);break;case XX_FILE_TYPE_SBPAK:ok=sxan_sbpak(c);break;case XX_FILE_TYPE_TITAN_QUEST:ok=sxan_titan(c);break;case XX_FILE_TYPE_CGJP:ok=sxan_cgjp(c);break;case XX_FILE_TYPE_BIRDIES:ok=sxan_birdies(c);break;case XX_FILE_TYPE_XUIZ:ok=sxan_xuiz(c);break;case XX_FILE_TYPE_WII_WAD:ok=sxan_wad(c);break;case XX_FILE_TYPE_FREEARC:ok=sxan_freearc(c);break;case XX_FILE_TYPE_ZPAQ:ok=sxan_zpaq(c);break;case XX_FILE_TYPE_BYTEKILLER:ok=sxan_bytekiller(c);break;case XX_FILE_TYPE_DCS:ok=sxan_dcs(c);break;case XX_FILE_TYPE_AUDIALS:ok=sxan_audials(c);break;case XX_FILE_TYPE_OSL2000:ok=sxan_osl(c);break;case XX_FILE_TYPE_MICROFOX_PUT:ok=sxan_lha(c);break;case XX_FILE_TYPE_SAR:ok=sxan_lha(c);break;default:break;}(void)ok;return c->count&&sxan_finish(c);}
