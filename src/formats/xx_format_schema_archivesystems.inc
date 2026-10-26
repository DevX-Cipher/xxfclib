/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archivesystems_scope.txt. */
static const xx_data_struct_field_desc sxasy_arcv2_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("volume_flags","uint32",8,4,SX_NONE),
 SX_FIELD("disk_number","uint16",12,2,SX_NONE),
};
static const sx_layout sxasy_arcv2_header = {UINT32_C(0x60440001),"arcv2_header",sxasy_arcv2_header_fields,SX_COUNT(sxasy_arcv2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv2_block_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("flags","uint32",8,4,SX_NONE),
 SX_FIELD("volume_payload_size","uint32",12,4,SX_SIZE),
 SX_FIELD("name_size","uint8",16,1,SX_SIZE),
};
static const sx_layout sxasy_arcv2_block = {UINT32_C(0x60440002),"arcv2_block",sxasy_arcv2_block_fields,SX_COUNT(sxasy_arcv2_block_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv2_attributes_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("attributes","uint32",8,4,SX_NONE),
 SX_FIELD("dos_timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("opaque","uint8[8]",16,8,SX_NONE),
 SX_FIELD("packed_crc32","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sxasy_arcv2_attributes = {UINT32_C(0x60440003),"arcv2_attributes",sxasy_arcv2_attributes_fields,SX_COUNT(sxasy_arcv2_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("subvariant","uint16",6,2,SX_NONE),
};
static const sx_layout sxasy_arcv4_header = {UINT32_C(0x60440004),"arcv4_header",sxasy_arcv4_header_fields,SX_COUNT(sxasy_arcv4_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_record_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("chunk_type","uint32",4,4,SX_NONE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("record_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxasy_arcv4_record = {UINT32_C(0x60440005),"arcv4_record",sxasy_arcv4_record_fields,SX_COUNT(sxasy_arcv4_record_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_tag_size_fields[] = {
 SX_FIELD("tag_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxasy_arcv4_tag_size = {UINT32_C(0x60440006),"arcv4_tag_size",sxasy_arcv4_tag_size_fields,SX_COUNT(sxasy_arcv4_tag_size_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_name_size_fields[] = {
 SX_FIELD("name_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxasy_arcv4_name_size = {UINT32_C(0x60440007),"arcv4_name_size",sxasy_arcv4_name_size_fields,SX_COUNT(sxasy_arcv4_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_attributes_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("flags","uint32",4,4,SX_NONE),
 SX_FIELD("filetime","uint64",8,8,SX_NONE),
 SX_FIELD("opaque","uint8[8]",16,8,SX_NONE),
 SX_FIELD("compressed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("method","uint32",28,4,SX_NONE),
};
static const sx_layout sxasy_arcv4_attributes = {UINT32_C(0x60440008),"arcv4_attributes",sxasy_arcv4_attributes_fields,SX_COUNT(sxasy_arcv4_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_data_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("chunk_type","uint32",4,4,SX_NONE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved1","uint32",16,4,SX_NONE),
 SX_FIELD("crc32","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("reserved2","uint32",24,4,SX_NONE),
 SX_FIELD("reserved3","uint32",28,4,SX_NONE),
};
static const sx_layout sxasy_arcv4_data = {UINT32_C(0x60440009),"arcv4_data",sxasy_arcv4_data_fields,SX_COUNT(sxasy_arcv4_data_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_cru_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("separator","char[1]",8,1,SX_NONE),
 SX_FIELD("minor_version","uint8",9,1,SX_NONE),
 SX_FIELD("guard","uint8[3]",10,3,SX_SIGNATURE),
 SX_FIELD("opaque","uint8[3]",13,3,SX_NONE),
 SX_FIELD("directory_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("member_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",20,2,SX_NONE),
 SX_FIELD("directory_offset","uint32",22,4,SX_OFFSET),
};
static const sx_layout sxasy_cru_header = {UINT32_C(0x6044000a),"cru_header",sxasy_cru_header_fields,SX_COUNT(sxasy_cru_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_cru_entry_fields[] = {
 SX_FIELD("directory_index","uint8",0,1,SX_NONE),
 SX_FIELD("opaque1","uint8",1,1,SX_NONE),
 SX_FIELD("dos_time","uint16",2,2,SX_NONE),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("stored_size","uint32",6,4,SX_SIZE),
 SX_FIELD("name","char[12]",10,12,SX_NONE),
 SX_FIELD("opaque2","uint8[2]",22,2,SX_NONE),
};
static const sx_layout sxasy_cru_entry = {UINT32_C(0x6044000b),"cru_entry",sxasy_cru_entry_fields,SX_COUNT(sxasy_cru_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_powerbbs_name_fields[] = {
 SX_FIELD("encoded_name_length","uint8",0,1,SX_NONE),
};
static const sx_layout sxasy_powerbbs_name = {UINT32_C(0x6044000c),"powerbbs_name",sxasy_powerbbs_name_fields,SX_COUNT(sxasy_powerbbs_name_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_powerbbs_size1_fields[] = {
 SX_FIELD("payload_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxasy_powerbbs_size1 = {UINT32_C(0x6044000d),"powerbbs_size1",sxasy_powerbbs_size1_fields,SX_COUNT(sxasy_powerbbs_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_powerbbs_size2_fields[] = {
 SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxasy_powerbbs_size2 = {UINT32_C(0x6044000e),"powerbbs_size2",sxasy_powerbbs_size2_fields,SX_COUNT(sxasy_powerbbs_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_powerbbs_size4_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxasy_powerbbs_size4 = {UINT32_C(0x6044000f),"powerbbs_size4",sxasy_powerbbs_size4_fields,SX_COUNT(sxasy_powerbbs_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_fld_member_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",17,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("dos_date","uint16",23,2,SX_NONE),
 SX_FIELD("method","uint8",25,1,SX_NONE),
 SX_FIELD("marker","char[1]",26,1,SX_SIGNATURE),
};
static const sx_layout sxasy_fld_member = {UINT32_C(0x60440010),"fld_member",sxasy_fld_member_fields,SX_COUNT(sxasy_fld_member_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_igf1_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_NONE),
 SX_FIELD("opaque1","uint8[2]",4,2,SX_NONE),
 SX_FIELD("group_id","uint16",6,2,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",8,4,SX_NONE),
 SX_FIELD("file_id","uint32",12,4,SX_NONE),
 SX_FIELD("pack_time","uint32",16,4,SX_NONE),
 SX_FIELD("file_time","uint32",20,4,SX_NONE),
 SX_FIELD("opaque3","uint8[4]",24,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",28,4,SX_SIZE),
 SX_FIELD("unpacked_checksum","uint32",32,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","int32",36,4,SX_SIZE),
 SX_FIELD("packed_checksum","uint32",40,4,SX_CHECKSUM),
 SX_FIELD("data_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("complemented_data_offset","uint32_ones_le",48,4,SX_OFFSET),
 SX_FIELD("compressed_size_copy","int32",52,4,SX_SIZE),
};
static const sx_layout sxasy_igf1_header = {UINT32_C(0x60440011),"igf1_header",sxasy_igf1_header_fields,SX_COUNT(sxasy_igf1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_igf2_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[6]",2,6,SX_NONE),
 SX_FIELD("container_size","int32",8,4,SX_SIZE),
 SX_FIELD("positive_count_word","int32",12,4,SX_NONE),
 SX_FIELD("opaque2","uint8[16]",16,16,SX_NONE),
 SX_FIELD("first_record_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("complemented_record_offset","uint32_ones_le",36,4,SX_OFFSET),
};
static const sx_layout sxasy_igf2_header = {UINT32_C(0x60440012),"igf2_header",sxasy_igf2_header_fields,SX_COUNT(sxasy_igf2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_igf2_member56_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("tag","uint16",2,2,SX_NONE),
 SX_FIELD("opaque1","uint8[16]",4,16,SX_NONE),
 SX_FIELD("file_time","uint32",20,4,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",24,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",28,4,SX_SIZE),
 SX_FIELD("opaque3","uint8[4]",32,4,SX_NONE),
 SX_FIELD("compressed_size","int32",36,4,SX_SIZE),
 SX_FIELD("opaque4","uint8[16]",40,16,SX_NONE),
};
static const sx_layout sxasy_igf2_member56 = {UINT32_C(0x60440013),"igf2_member56",sxasy_igf2_member56_fields,SX_COUNT(sxasy_igf2_member56_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_igf2_member44_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("tag","uint16",2,2,SX_NONE),
 SX_FIELD("opaque1","uint8[12]",4,12,SX_NONE),
 SX_FIELD("file_time","uint32",16,4,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",20,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",24,4,SX_SIZE),
 SX_FIELD("opaque3","uint8[4]",28,4,SX_NONE),
 SX_FIELD("compressed_size","int32",32,4,SX_SIZE),
 SX_FIELD("opaque4","uint8[8]",36,8,SX_NONE),
};
static const sx_layout sxasy_igf2_member44 = {UINT32_C(0x60440014),"igf2_member44",sxasy_igf2_member44_fields,SX_COUNT(sxasy_igf2_member44_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_igf2_end_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("end_tag","uint16",2,2,SX_SIGNATURE),
};
static const sx_layout sxasy_igf2_end = {UINT32_C(0x60440015),"igf2_end",sxasy_igf2_end_fields,SX_COUNT(sxasy_igf2_end_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_inteduft_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxasy_inteduft_header = {UINT32_C(0x60440016),"inteduft_header",sxasy_inteduft_header_fields,SX_COUNT(sxasy_inteduft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_inteduft_index_fields[] = {
 SX_FIELD("member_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("name_size","uint8",4,1,SX_SIZE),
};
static const sx_layout sxasy_inteduft_index = {UINT32_C(0x60440017),"inteduft_index",sxasy_inteduft_index_fields,SX_COUNT(sxasy_inteduft_index_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_inteduft_member_fields[] = {
 SX_FIELD("reserved_flags","uint16",0,2,SX_NONE),
 SX_FIELD("method","uint16",2,2,SX_NONE),
 SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","int32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",12,4,SX_SIZE),
};
static const sx_layout sxasy_inteduft_member = {UINT32_C(0x60440018),"inteduft_member",sxasy_inteduft_member_fields,SX_COUNT(sxasy_inteduft_member_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_jm93_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("name","char[60]",5,60,SX_NONE),
 SX_FIELD("compressed_size","uint32",65,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",69,4,SX_SIZE),
};
static const sx_layout sxasy_jm93_header = {UINT32_C(0x60440019),"jm93_header",sxasy_jm93_header_fields,SX_COUNT(sxasy_jm93_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_miz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("signature2","char[4]",6,4,SX_SIGNATURE),
 SX_FIELD("name_field_size","uint16",10,2,SX_SIZE),
};
static const sx_layout sxasy_miz_header = {UINT32_C(0x6044001a),"miz_header",sxasy_miz_header_fields,SX_COUNT(sxasy_miz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_miz_member_fields[] = {
 SX_FIELD("dos_time","uint16",0,2,SX_NONE),
 SX_FIELD("dos_date","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",8,4,SX_SIZE),
};
static const sx_layout sxasy_miz_member = {UINT32_C(0x6044001b),"miz_member",sxasy_miz_member_fields,SX_COUNT(sxasy_miz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_mva_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
};
static const sx_layout sxasy_mva_header = {UINT32_C(0x6044001c),"mva_header",sxasy_mva_header_fields,SX_COUNT(sxasy_mva_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_mva_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("modification_time","uint32",8,4,SX_NONE),
 SX_FIELD("creation_time","uint32",12,4,SX_NONE),
 SX_FIELD("path","char[260]",16,260,SX_NONE),
 SX_FIELD("uncompressed_size","int32",276,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",280,4,SX_SIZE),
 SX_FIELD("checksum1","uint32",284,4,SX_CHECKSUM),
 SX_FIELD("checksum2","uint32",288,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint32",292,4,SX_NONE),
 SX_FIELD("opaque","uint8[50]",296,50,SX_NONE),
};
static const sx_layout sxasy_mva_member = {UINT32_C(0x6044001d),"mva_member",sxasy_mva_member_fields,SX_COUNT(sxasy_mva_member_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_povlab_header_fields[] = {
 SX_FIELD("header_payload_size","uint8",0,1,SX_SIZE),
 SX_FIELD("checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_NONE),
 SX_FIELD("skip_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_NONE),
 SX_FIELD("level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
static const sx_layout sxasy_povlab_header = {UINT32_C(0x6044001e),"povlab_header",sxasy_povlab_header_fields,SX_COUNT(sxasy_povlab_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_povlab_attributes_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("origin_os","uint8",2,1,SX_NONE),
};
static const sx_layout sxasy_povlab_attributes = {UINT32_C(0x6044001f),"povlab_attributes",sxasy_povlab_attributes_fields,SX_COUNT(sxasy_povlab_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_povlab_extension_size_fields[] = {
 SX_FIELD("next_header_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxasy_povlab_extension_size = {UINT32_C(0x60440020),"povlab_extension_size",sxasy_povlab_extension_size_fields,SX_COUNT(sxasy_povlab_extension_size_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_povlab_extension_type_fields[] = {
 SX_FIELD("type","uint8",0,1,SX_NONE),
};
static const sx_layout sxasy_povlab_extension_type = {UINT32_C(0x60440021),"povlab_extension_type",sxasy_povlab_extension_type_fields,SX_COUNT(sxasy_povlab_extension_type_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_qip1_member_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("sequence","uint16",8,2,SX_NONE),
 SX_FIELD("flag","uint8",10,1,SX_NONE),
 SX_FIELD("dos_time","uint16",11,2,SX_NONE),
 SX_FIELD("dos_date","uint16",13,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",15,4,SX_SIZE),
 SX_FIELD("name","char[13]",19,13,SX_NONE),
};
static const sx_layout sxasy_qip1_member = {UINT32_C(0x60440022),"qip1_member",sxasy_qip1_member_fields,SX_COUNT(sxasy_qip1_member_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_qp_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("index_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_NONE),
 SX_FIELD("reserved","uint8[6]",10,6,SX_NONE),
};
static const sx_layout sxasy_qp_header = {UINT32_C(0x60440023),"qp_header",sxasy_qp_header_fields,SX_COUNT(sxasy_qp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_qp_index_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name","char[12]",4,12,SX_NONE),
};
static const sx_layout sxasy_qp_index = {UINT32_C(0x60440024),"qp_index",sxasy_qp_index_fields,SX_COUNT(sxasy_qp_index_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_qp_path_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("path_blob_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sequence","uint16",8,2,SX_NONE),
 SX_FIELD("reserved","uint32",10,4,SX_NONE),
};
static const sx_layout sxasy_qp_path = {UINT32_C(0x60440025),"qp_path",sxasy_qp_path_fields,SX_COUNT(sxasy_qp_path_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_qp_member_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sequence","uint16",8,2,SX_NONE),
 SX_FIELD("crc32","uint32",10,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint8",14,1,SX_NONE),
 SX_FIELD("dos_time","uint16",15,2,SX_NONE),
 SX_FIELD("dos_date","uint16",17,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",19,4,SX_SIZE),
 SX_FIELD("name","char[13]",23,13,SX_NONE),
};
static const sx_layout sxasy_qp_member = {UINT32_C(0x60440026),"qp_member",sxasy_qp_member_fields,SX_COUNT(sxasy_qp_member_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_rcf_header_fields[] = {
 SX_FIELD("tag_size","uint8",0,1,SX_SIZE),
 SX_FIELD("encoded_signature","uint8[3]",1,3,SX_SIGNATURE),
 SX_FIELD("version_size","uint8",4,1,SX_SIZE),
 SX_FIELD("version","char[3]",5,3,SX_NONE),
 SX_FIELD("reserved","uint16",8,2,SX_NONE),
};
static const sx_layout sxasy_rcf_header = {UINT32_C(0x60440027),"rcf_header",sxasy_rcf_header_fields,SX_COUNT(sxasy_rcf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_rcf_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
};
static const sx_layout sxasy_rcf_entry = {UINT32_C(0x60440028),"rcf_entry",sxasy_rcf_entry_fields,SX_COUNT(sxasy_rcf_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_rcf_count_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxasy_rcf_count = {UINT32_C(0x60440029),"rcf_count",sxasy_rcf_count_fields,SX_COUNT(sxasy_rcf_count_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_riversoft_header_fields[] = {
 SX_FIELD("signature","char[23]",0,23,SX_SIGNATURE),
 SX_FIELD("major_version","uint8",23,1,SX_NONE),
 SX_FIELD("opaque","uint8",24,1,SX_NONE),
 SX_FIELD("minor_version","uint8",25,1,SX_NONE),
 SX_FIELD("member_count","uint16",26,2,SX_COUNT_PROP),
 SX_FIELD("total_uncompressed_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxasy_riversoft_header = {UINT32_C(0x6044002a),"riversoft_header",sxasy_riversoft_header_fields,SX_COUNT(sxasy_riversoft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_riversoft_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("payload_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint16",17,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",19,2,SX_SIZE),
};
static const sx_layout sxasy_riversoft_entry = {UINT32_C(0x6044002b),"riversoft_entry",sxasy_riversoft_entry_fields,SX_COUNT(sxasy_riversoft_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_tgcf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[2]",4,2,SX_NONE),
 SX_FIELD("version","uint16",6,2,SX_NONE),
 SX_FIELD("opaque2","uint8[18]",8,18,SX_NONE),
 SX_FIELD("volume_name_size","uint16",26,2,SX_SIZE),
};
static const sx_layout sxasy_tgcf_header = {UINT32_C(0x6044002c),"tgcf_header",sxasy_tgcf_header_fields,SX_COUNT(sxasy_tgcf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_tgcf_list_offset_fields[] = {
 SX_FIELD("member_list_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxasy_tgcf_list_offset = {UINT32_C(0x6044002d),"tgcf_list_offset",sxasy_tgcf_list_offset_fields,SX_COUNT(sxasy_tgcf_list_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_tgcf_crc_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxasy_tgcf_crc = {UINT32_C(0x6044002e),"tgcf_crc",sxasy_tgcf_crc_fields,SX_COUNT(sxasy_tgcf_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_tgcf_member_prefix_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque","uint8[8]",4,8,SX_NONE),
 SX_FIELD("split_kind","uint16",12,2,SX_NONE),
 SX_FIELD("method","uint16",14,2,SX_NONE),
};
static const sx_layout sxasy_tgcf_member_prefix = {UINT32_C(0x6044002f),"tgcf_member_prefix",sxasy_tgcf_member_prefix_fields,SX_COUNT(sxasy_tgcf_member_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_tgcf_member_attributes_fields[] = {
 SX_FIELD("timestamp","uint32",0,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint32",16,4,SX_NONE),
};
static const sx_layout sxasy_tgcf_member_attributes = {UINT32_C(0x60440030),"tgcf_member_attributes",sxasy_tgcf_member_attributes_fields,SX_COUNT(sxasy_tgcf_member_attributes_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_tgcf_member_flag_fields[] = {
 SX_FIELD("flag","uint8",0,1,SX_NONE),
};
static const sx_layout sxasy_tgcf_member_flag = {UINT32_C(0x60440031),"tgcf_member_flag",sxasy_tgcf_member_flag_fields,SX_COUNT(sxasy_tgcf_member_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_tgcf_payload_offset_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxasy_tgcf_payload_offset = {UINT32_C(0x60440032),"tgcf_payload_offset",sxasy_tgcf_payload_offset_fields,SX_COUNT(sxasy_tgcf_payload_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_trc_header_fields[] = {
 SX_FIELD("signature","uint8[12]",0,12,SX_SIGNATURE),
 SX_FIELD("version","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("separator","char[1]",18,1,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[31]",19,31,SX_NONE),
 SX_FIELD("name","char[13]",50,13,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",63,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",67,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",71,4,SX_SIZE),
 SX_FIELD("signature2","char[8]",75,8,SX_SIGNATURE),
 SX_FIELD("opaque3","uint8[4]",83,4,SX_NONE),
 SX_FIELD("crc32_copy","uint32",87,4,SX_CHECKSUM),
 SX_FIELD("opaque4","uint8[68]",91,68,SX_NONE),
 SX_FIELD("uncompressed_size_copy","int32",159,4,SX_SIZE),
 SX_FIELD("opaque5","uint8[143]",163,143,SX_NONE),
};
static const sx_layout sxasy_trc_header = {UINT32_C(0x60440033),"trc_header",sxasy_trc_header_fields,SX_COUNT(sxasy_trc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_netwarepacked_header_fields[] = {
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("name","char[12]",12,12,SX_NONE),
 SX_FIELD("marker","uint8",24,1,SX_SIGNATURE),
 SX_FIELD("version","uint8",25,1,SX_NONE),
 SX_FIELD("method","uint8",26,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",27,4,SX_SIZE),
};
static const sx_layout sxasy_netwarepacked_header = {UINT32_C(0x60440034),"netwarepacked_header",sxasy_netwarepacked_header_fields,SX_COUNT(sxasy_netwarepacked_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_netware2_record_fields[] = {
 SX_FIELD("record_size","uint32",0,4,SX_SIZE),
 SX_FIELD("name_count","uint8",4,1,SX_NONE),
};
static const sx_layout sxasy_netware2_record = {UINT32_C(0x60440035),"netware2_record",sxasy_netware2_record_fields,SX_COUNT(sxasy_netware2_record_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_netware2_metadata_fields[] = {
 SX_FIELD("subtag","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("flags","uint8",1,1,SX_NONE),
 SX_FIELD("date_text","char[8]",2,8,SX_NONE),
 SX_FIELD("time_text","char[8]",10,8,SX_NONE),
 SX_FIELD("attribute_identifier_text","char[34]",18,34,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",52,4,SX_SIZE),
 SX_FIELD("unidentified_stamp","uint32",56,4,SX_NONE),
 SX_FIELD("name_size","uint8",60,1,SX_SIZE),
};
static const sx_layout sxasy_netware2_metadata = {UINT32_C(0x60440036),"netware2_metadata",sxasy_netware2_metadata_fields,SX_COUNT(sxasy_netware2_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_netware2_packed_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_NONE),
 SX_FIELD("method","uint8",1,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxasy_netware2_packed = {UINT32_C(0x60440037),"netware2_packed",sxasy_netware2_packed_fields,SX_COUNT(sxasy_netware2_packed_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_archivesystems_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxasy_archivesystems_dcl = {UINT32_C(0x60440038),"archivesystems_dcl",sxasy_archivesystems_dcl_fields,SX_COUNT(sxasy_archivesystems_dcl_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_miz_footer_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxasy_miz_footer = {UINT32_C(0x60440039),"miz_footer",sxasy_miz_footer_fields,SX_COUNT(sxasy_miz_footer_fields),SX_LE};
static const sx_layout *const sx_archivesystems_layouts[] = {
 &sxasy_arcv2_header,
 &sxasy_arcv2_block,
 &sxasy_arcv2_attributes,
 &sxasy_arcv4_header,
 &sxasy_arcv4_record,
 &sxasy_arcv4_tag_size,
 &sxasy_arcv4_name_size,
 &sxasy_arcv4_attributes,
 &sxasy_arcv4_data,
 &sxasy_cru_header,
 &sxasy_cru_entry,
 &sxasy_powerbbs_name,
 &sxasy_powerbbs_size1,
 &sxasy_powerbbs_size2,
 &sxasy_powerbbs_size4,
 &sxasy_fld_member,
 &sxasy_igf1_header,
 &sxasy_igf2_header,
 &sxasy_igf2_member56,
 &sxasy_igf2_member44,
 &sxasy_igf2_end,
 &sxasy_inteduft_header,
 &sxasy_inteduft_index,
 &sxasy_inteduft_member,
 &sxasy_jm93_header,
 &sxasy_miz_header,
 &sxasy_miz_member,
 &sxasy_mva_header,
 &sxasy_mva_member,
 &sxasy_povlab_header,
 &sxasy_povlab_attributes,
 &sxasy_povlab_extension_size,
 &sxasy_povlab_extension_type,
 &sxasy_qip1_member,
 &sxasy_qp_header,
 &sxasy_qp_index,
 &sxasy_qp_path,
 &sxasy_qp_member,
 &sxasy_rcf_header,
 &sxasy_rcf_entry,
 &sxasy_rcf_count,
 &sxasy_riversoft_header,
 &sxasy_riversoft_entry,
 &sxasy_tgcf_header,
 &sxasy_tgcf_list_offset,
 &sxasy_tgcf_crc,
 &sxasy_tgcf_member_prefix,
 &sxasy_tgcf_member_attributes,
 &sxasy_tgcf_member_flag,
 &sxasy_tgcf_payload_offset,
 &sxasy_trc_header,
 &sxasy_netwarepacked_header,
 &sxasy_netware2_record,
 &sxasy_netware2_metadata,
 &sxasy_netware2_packed,
 &sxasy_archivesystems_dcl,
 &sxasy_miz_footer,
};
static bool sx_archivesystems_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60440000U||id>=0x60450000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60440001U:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"ARCV 0x0200";
 if(!xx_rt_wcscmp(r->name,L"volume_flags"))text=L"1 single, 2 first, 4 middle, 8 last volume";
 break;
 case 0x60440002U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"1 whole, 2 split head, 8 split tail; 0x10 stored, 0x20 compressed";
 break;
 case 0x60440003U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Total compressed bytes across volumes";
 if(!xx_rt_wcscmp(r->name,L"dos_timestamp"))text=L"Packed DOS date and time";
 if(!xx_rt_wcscmp(r->name,L"packed_crc32"))text=L"CRC-32/JAMCRC of the stored packed bytes";
 break;
 case 0x60440004U:
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"ARCV 0x0400";
 if(!xx_rt_wcscmp(r->name,L"subvariant"))text=L"Observed 1 or 5";
 break;
 case 0x60440005U:
 if(!xx_rt_wcscmp(r->name,L"chunk_type"))text=L"Low byte 1 FILE, 3 EOFM";
 break;
 case 0x60440008U:
 if(!xx_rt_wcscmp(r->name,L"filetime"))text=L"Windows FILETIME, 100 ns since 1601";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"0xFFFFFFFF indicates a split stream";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 2 compressed";
 break;
 case 0x60440009U:
 if(!xx_rt_wcscmp(r->name,L"chunk_type"))text=L"Low byte 1 split, 5 whole";
 break;
 case 0x6044000bU:
 if(!xx_rt_wcscmp(r->name,L"directory_index"))text=L"One based directory index; zero means root";
 break;
 case 0x6044000cU:
 if(!xx_rt_wcscmp(r->name,L"encoded_name_length"))text=L"1..8: basename length and 2/4-byte size; 11..18: basename length minus 10 and 1-byte size; extension occupies 3 bytes";
 break;
 case 0x60440010U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 PKWARE DCL";
 break;
 case 0x60440011U:
 if(!xx_rt_wcscmp(r->name,L"pack_time"))text=L"Unix seconds";
 if(!xx_rt_wcscmp(r->name,L"file_time"))text=L"Unix seconds, zero unspecified";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Zero selects stored data";
 if(!xx_rt_wcscmp(r->name,L"unpacked_checksum"))text=L"Unidentified checksum algorithm";
 if(!xx_rt_wcscmp(r->name,L"packed_checksum"))text=L"Unidentified checksum algorithm";
 if(!xx_rt_wcscmp(r->name,L"complemented_data_offset"))text=L"One's complement of the data offset";
 break;
 case 0x60440012U:
 if(!xx_rt_wcscmp(r->name,L"positive_count_word"))text=L"Positive header word; not used as the member traversal count";
 if(!xx_rt_wcscmp(r->name,L"complemented_record_offset"))text=L"One's complement of the first record offset";
 break;
 case 0x60440013U:
 if(!xx_rt_wcscmp(r->name,L"file_time"))text=L"Unix seconds";
 break;
 case 0x60440014U:
 if(!xx_rt_wcscmp(r->name,L"file_time"))text=L"Unix seconds";
 break;
 case 0x60440015U:
 if(!xx_rt_wcscmp(r->name,L"end_tag"))text=L"0xFFFF terminates the member chain";
 break;
 case 0x60440018U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 8 raw DEFLATE";
 break;
 case 0x6044001dU:
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Unix seconds";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Unix seconds";
 if(!xx_rt_wcscmp(r->name,L"checksum1"))text=L"Unidentified checksum algorithm";
 if(!xx_rt_wcscmp(r->name,L"checksum2"))text=L"Unidentified checksum algorithm";
 break;
 case 0x6044001eU:
 if(!xx_rt_wcscmp(r->name,L"header_payload_size"))text=L"Excludes size and checksum bytes";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of base-header bytes after this byte modulo 256";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"-ARS- stored; -ARA- LHA lh5";
 if(!xx_rt_wcscmp(r->name,L"skip_size"))text=L"Compressed payload plus all extended-header bytes";
 break;
 case 0x6044001fU:
 if(!xx_rt_wcscmp(r->name,L"crc16"))text=L"CRC-16/ARC of the member data";
 break;
 case 0x60440020U:
 if(!xx_rt_wcscmp(r->name,L"next_header_size"))text=L"Zero ends the extended-header chain; nonzero includes type/body and its final next-size word";
 break;
 case 0x60440021U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"Extension type; remaining body bytes are preserved raw";
 break;
 case 0x60440022U:
 if(!xx_rt_wcscmp(r->name,L"flag"))text=L"Observed 0x21, not a codec selector";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Zero selects stored data, positive selects DCL";
 break;
 case 0x60440025U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"1 path record";
 break;
 case 0x60440026U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0 member record";
 break;
 case 0x60440027U:
 if(!xx_rt_wcscmp(r->name,L"encoded_signature"))text=L"Biased RCF signature F7 E8 EB";
 break;
 case 0x6044002fU:
 if(!xx_rt_wcscmp(r->name,L"split_kind"))text=L"2 continuation fragment";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 4 zlib";
 break;
 case 0x60440030U:
 if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Stored timestamp, retained without assuming an epoch";
 break;
 case 0x60440034U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0x0A NetWare LZH";
 break;
 case 0x60440035U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Includes this four-byte size word";
 if(!xx_rt_wcscmp(r->name,L"name_count"))text=L"Stored tag length plus one; the counted NUL is not physically present";
 break;
 case 0x60440036U:
 if(!xx_rt_wcscmp(r->name,L"date_text"))text=L"MM-DD-YY";
 if(!xx_rt_wcscmp(r->name,L"time_text"))text=L"HH:MM:SS";
 if(!xx_rt_wcscmp(r->name,L"attribute_identifier_text"))text=L"Printable attributes and identifier text with no further established field boundaries";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Exact stored DOS-name bytes, followed by an additional NUL";
 break;
 case 0x60440037U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0x0A NetWare LZH";
 break;
 case 0x60440038U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 binary literals, 1 coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4, 5 or 6; PKWARE DCL dictionary size parameter";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXASY_LIMIT 20000U
static bool sxasy_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxasy_read(sx_context*c,uint64_t p,void*b,size_t n){return sxasy_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxasy_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxasy_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxasy_read(c,p,b,n))return false;*v=sxasy_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
static bool sxasy_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXASY_LIMIT||!sxasy_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxasy_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxasy_read(c,(*p)++,&b,1))return false;if(!b)return true;}return false;}
static bool sxasy_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t h[2];return n<2||!sxasy_read(c,p,h,2)||h[0]>1||h[1]<4||h[1]>6?true:sxasy_add(c,&sxasy_archivesystems_dcl,p);}
static bool sxasy_arcv2(sx_context*c){uint64_t p=14;if(!sxasy_add(c,&sxasy_arcv2_header,0))return false;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[17];if(!sxasy_read(c,p,h,17)||xx_rt_memcmp(h,"BLCK",4))return false;uint64_t hs=sxasy_uint(h+6,2,false),z=sxasy_uint(h+12,4,false);if(hs!=45U+h[16]||!sxasy_span(c,p,hs)||!sxasy_span(c,p+hs,z)||!sxasy_add(c,&sxasy_arcv2_block,p)||!sxasy_add(c,&sxasy_arcv2_attributes,p+17+h[16]))return false;p+=hs+z;}return p==(uint64_t)c->size;}
static bool sxasy_arcv4(sx_context*c){uint64_t p=0x79c;if(!sxasy_span(c,0,p)||!sxasy_add(c,&sxasy_arcv4_header,0))return false;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[32];if(!sxasy_read(c,p,h,16))return false;uint64_t hs=sxasy_uint(h+8,4,false),z=sxasy_uint(h+12,4,false);if(hs!=16||!sxasy_span(c,p+16,z)||(!xx_rt_memcmp(h,"EOFM",4)&&z))return false;if(!sxasy_add(c,&sxasy_arcv4_record,p))return false;if(!xx_rt_memcmp(h,"EOFM",4))return true;if(xx_rt_memcmp(h,"FILE",4))return false;uint64_t end=p+16+z,q=p+16,n;if(end-q<4||!sxasy_word(c,q,4,false,&n)||n>end-q-4||!sxasy_add(c,&sxasy_arcv4_tag_size,q))return false;q+=4+n;if(q>end||end-q<4||!sxasy_word(c,q,4,false,&n)||n>end-q-4||!sxasy_add(c,&sxasy_arcv4_name_size,q))return false;q+=4+n;if(end-q<32||!sxasy_add(c,&sxasy_arcv4_attributes,q))return false;p=end;if(!sxasy_read(c,p,h,32)||xx_rt_memcmp(h,"DATA",4)||sxasy_uint(h+8,4,false)!=32)return false;z=sxasy_uint(h+12,4,false);if(!sxasy_span(c,p+32,z)||!sxasy_add(c,&sxasy_arcv4_data,p))return false;p+=32+z;}return false;}
static bool sxasy_cru(sx_context*c){uint64_t n,p;if(!sxasy_word(c,18,2,false,&n)||!sxasy_word(c,22,4,false,&p)||!sxasy_span(c,p,n*24)||!sxasy_add(c,&sxasy_cru_header,0))return false;for(uint64_t i=0;i<n;i++)if(!sxasy_add(c,&sxasy_cru_entry,p+i*24))return false;return true;}
/* The native backtracking parser is authoritative for ambiguous 16/32-bit sizes. */
static bool sxasy_power(sx_context*c){if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return false;xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXASY_LIMIT;i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;uint8_t lead;uint64_t p,ns,width;if(r->header_offset<c->f->base_address||r->header_size<5||r->compressed_size<0||r->data_offset!=r->header_offset+r->header_size){ok=false;break;}p=(uint64_t)(r->header_offset-c->f->base_address);if(!sxasy_read(c,p,&lead,1)){ok=false;break;}ns=(lead>=11&&lead<=18?lead-10:lead)+3;width=(uint64_t)r->header_size-1-ns;if(!((lead>=11&&lead<=18&&width==1)||(lead>=1&&lead<=8&&(width==2||width==4)))||!sxasy_span(c,p,(uint64_t)r->header_size+(uint64_t)r->compressed_size)||!sxasy_add(c,&sxasy_powerbbs_name,p)||!sxasy_add(c,width==1?&sxasy_powerbbs_size1:width==2?&sxasy_powerbbs_size2:&sxasy_powerbbs_size4,p+1+ns)){ok=false;break;}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static bool sxasy_fld(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXASY_LIMIT&&sxasy_span(c,p,27);i++){uint8_t h[27];if(!sxasy_read(c,p,h,27)||h[0]!=12||h[26]!='$')return false;uint64_t n=sxasy_uint(h+13,4,false);if(n>INT32_MAX||!sxasy_span(c,p+27,n)||!sxasy_add(c,&sxasy_fld_member,p))return false;if(h[25]==1&&!sxasy_dcl(c,p+27,n))return false;p+=27+n;}return true;}
static bool sxasy_igf1(sx_context*c){return sxasy_add(c,&sxasy_igf1_header,0);}
static bool sxasy_igf2_scan(sx_context*c,uint64_t start,unsigned hs,bool emit,uint64_t*count,bool*ended){uint64_t p=start;*count=0;*ended=false;for(unsigned i=0;i<65537;i++){uint8_t b[56];if(!sxasy_read(c,p,b,4))return false;if(sxasy_uint(b+2,2,false)==65535){*ended=true;return !emit||sxasy_add(c,&sxasy_igf2_end,p);}if(!sxasy_read(c,p,b,56)||sxasy_uint(b,2,false)!=0xecdb)return false;unsigned packedoff=hs==56?36:32,plainoff=hs==56?28:24;uint64_t z=sxasy_uint(b+packedoff,4,false),plain=sxasy_uint(b+plainoff,4,false),q=p+hs;if(z>INT32_MAX||plain>INT32_MAX||!sxasy_zstr(c,&q,(uint64_t)c->size,1024)||q==p+hs+1)return false;uint64_t relative=(q-p+4)&~UINT64_C(3);if(!sxasy_span(c,p,relative)||!sxasy_span(c,p+relative,z))return false;if(emit&&!sxasy_add(c,hs==56?&sxasy_igf2_member56:&sxasy_igf2_member44,p))return false;(*count)++;p+=relative+z;}return false;}
static bool sxasy_igf2(sx_context*c){uint64_t p,a,b;bool ae,be;if(!sxasy_word(c,32,4,false,&p)||p<40||!sxasy_add(c,&sxasy_igf2_header,0))return false;(void)sxasy_igf2_scan(c,p,56,false,&a,&ae);unsigned hs=56;if(!ae){(void)sxasy_igf2_scan(c,p,44,false,&b,&be);if(be||b>a)hs=44;}return sxasy_igf2_scan(c,p,hs,true,&a,&ae);}
static bool sxasy_intedu(sx_context*c){uint64_t n,p=6;if(!sxasy_word(c,4,2,false,&n)||!sxasy_add(c,&sxasy_inteduft_header,0))return false;for(uint64_t i=0;i<n;i++){uint8_t h[5];if(!sxasy_read(c,p,h,5)||!sxasy_span(c,p+5,h[4])||!sxasy_add(c,&sxasy_inteduft_index,p))return false;p+=5+h[4];}uint64_t end=p;p=6;for(uint64_t i=0;i<n;i++){uint8_t h[16],idx[5];if(!sxasy_read(c,p,idx,5))return false;uint64_t q=sxasy_uint(idx,4,false);if(q<end||q>INT32_MAX||!sxasy_read(c,q,h,16)||!sxasy_span(c,q+16,sxasy_uint(h+8,4,false))||!sxasy_add(c,&sxasy_inteduft_member,q))return false;p+=5+idx[4];}return true;}
static bool sxasy_jm(sx_context*c){uint64_t n;return sxasy_word(c,65,4,false,&n)&&sxasy_add(c,&sxasy_jm93_header,0)&&sxasy_dcl(c,73,n);}
static bool sxasy_miz(sx_context*c){uint64_t n,z;if(!sxasy_word(c,10,2,false,&n)||n<2||n>64||!sxasy_add(c,&sxasy_miz_header,0)||!sxasy_word(c,20+n,4,false,&z)||!sxasy_add(c,&sxasy_miz_member,12+n))return false;return sxasy_dcl(c,24+n,z)&&sxasy_add(c,&sxasy_miz_footer,24+n+z);}
static bool sxasy_mva(sx_context*c){uint64_t p=8;if(!sxasy_add(c,&sxasy_mva_header,0))return false;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[346];if(!sxasy_read(c,p,h,346)||xx_rt_memcmp(h,"mfen",4))return false;uint64_t z=sxasy_uint(h+280,4,false);if(z>INT32_MAX||!sxasy_span(c,p+346,z)||!sxasy_add(c,&sxasy_mva_member,p))return false;p+=346+z;}return true;}
static bool sxasy_pov(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[22];if(!sxasy_read(c,p,h,1)||!h[0])return true;if(!sxasy_read(c,p,h,22))return false;uint64_t hs=h[0]+2,z=sxasy_uint(h+7,4,false),n=h[21],ex,q;if(hs<27+n||!sxasy_span(c,p,hs)||!sxasy_span(c,p+hs,z)||!sxasy_add(c,&sxasy_povlab_header,p)||!sxasy_add(c,&sxasy_povlab_attributes,p+22+n)||!sxasy_add(c,&sxasy_povlab_extension_size,p+hs-2)||!sxasy_word(c,p+hs-2,2,false,&ex))return false;q=p+hs;uint64_t used=0;while(ex){if(ex<3||ex>z-used||!sxasy_span(c,q,ex)||!sxasy_add(c,&sxasy_povlab_extension_type,q)||!sxasy_add(c,&sxasy_povlab_extension_size,q+ex-2))return false;used+=ex;q+=ex;if(!sxasy_word(c,q-2,2,false,&ex))return false;}p+=hs+z;}return true;}
static bool sxasy_qip(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[32];if(!sxasy_read(c,p,h,32)||h[0]!='Q'||h[1]!='D')return false;uint64_t z=sxasy_uint(h+4,4,false);if(z>INT32_MAX||!sxasy_span(c,p+32,z)||!sxasy_add(c,&sxasy_qip1_member,p))return false;if(sxasy_uint(h+15,4,false)&&!sxasy_dcl(c,p+32,z))return false;p+=32+z;}return true;}
static bool sxasy_qp(sx_context*c){uint64_t n,p;if(!sxasy_word(c,2,2,false,&n)||!sxasy_span(c,16,n*16)||!sxasy_add(c,&sxasy_qp_header,0))return false;for(uint64_t i=0;i<n;i++)if(!sxasy_add(c,&sxasy_qp_index,16+16*i))return false;p=16+16*n;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[36];if(!sxasy_read(c,p,h,14)||h[0]!='Q'||h[1]!='D')return false;uint64_t kind=sxasy_uint(h+2,2,false),z=sxasy_uint(h+4,4,false),hs=kind==1?14:36;if(kind>1||!sxasy_span(c,p,hs)||!sxasy_span(c,p+hs,z)||!sxasy_add(c,kind?&sxasy_qp_path:&sxasy_qp_member,p))return false;if(!kind&&!sxasy_dcl(c,p+hs,z))return false;p+=hs+z;}return true;}
static bool sxasy_rcf(sx_context*c){uint64_t n,end=(uint64_t)c->size;if(end<12||!sxasy_word(c,end-2,2,false,&n)||n>(end-12)/17||!sxasy_add(c,&sxasy_rcf_header,0)||!sxasy_add(c,&sxasy_rcf_count,end-2))return false;uint64_t table=end-2-n*17,p=10;for(uint64_t i=0;i<n;i++){uint64_t z;if(!sxasy_word(c,table+i*17+13,4,false,&z)||z>INT32_MAX||p>table||z>table-p||!sxasy_add(c,&sxasy_rcf_entry,table+i*17)||!sxasy_dcl(c,p,z))return false;p+=z;}return p==table;}
static bool sxasy_river(sx_context*c){uint64_t n,end=(uint64_t)c->size;if(!sxasy_word(c,26,2,false,&n)||end<32||n>(end-32)/21||!sxasy_add(c,&sxasy_riversoft_header,0))return false;uint64_t p=end-n*21;for(uint64_t i=0;i<n;i++){uint8_t h[21];if(!sxasy_read(c,p+i*21,h,21)||!sxasy_add(c,&sxasy_riversoft_entry,p+i*21))return false;uint64_t off=sxasy_uint(h+13,4,false),z=sxasy_uint(h+17,2,false);if(off>=32&&off<=p&&z<=p-off&&!sxasy_dcl(c,off,z))return false;}return true;}
static bool sxasy_tgcf(sx_context*c){uint64_t version,n,p;if(!sxasy_word(c,6,2,true,&version)||!sxasy_word(c,26,2,true,&n)||n>1024||!sxasy_span(c,28,n)||!sxasy_add(c,&sxasy_tgcf_header,0))return false;p=28+n;if(version>=0x160){uint64_t list;if(!sxasy_word(c,p,4,true,&list)||!sxasy_add(c,&sxasy_tgcf_list_offset,p)||!sxasy_add(c,&sxasy_tgcf_crc,p+4))return false;p=list;}else{if(!sxasy_add(c,&sxasy_tgcf_crc,p))return false;p+=4;}for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[36];if(!sxasy_read(c,p,h,36)||xx_rt_memcmp(h,"TGCF",4))return false;uint64_t z=sxasy_uint(h+20,4,true),q=p+36;if(!sxasy_zstr(c,&q,(uint64_t)c->size,1024)||!sxasy_zstr(c,&q,(uint64_t)c->size,1024)||!sxasy_span(c,q,version>=0x160?9:5)||!sxasy_add(c,&sxasy_tgcf_member_prefix,p)||!sxasy_add(c,&sxasy_tgcf_member_attributes,p+16)||!sxasy_add(c,&sxasy_tgcf_member_flag,q))return false;q++;if(version>=0x160){uint64_t data;if(!sxasy_word(c,q,4,true,&data)||!sxasy_span(c,data,z)||!sxasy_add(c,&sxasy_tgcf_payload_offset,q))return false;q+=4;}if(!sxasy_add(c,&sxasy_tgcf_crc,q))return false;q+=4;if(version<0x160){if(!sxasy_span(c,q,z))return false;q+=z;}p=q;}return true;}
static bool sxasy_trc(sx_context*c){uint64_t n;return sxasy_word(c,71,4,false,&n)&&sxasy_add(c,&sxasy_trc_header,0)&&sxasy_dcl(c,306,n);}
static bool sxasy_netware2(sx_context*c){uint64_t p=0;for(unsigned i=0;i<256&&p<(uint64_t)c->size;i++){uint8_t h[69];if(!sxasy_read(c,p,h,5))return false;uint64_t z=sxasy_uint(h,4,false),n=h[4];if(!n||n>65||z<4+n||!sxasy_span(c,p,z)||!sxasy_read(c,p+5,h,(size_t)n-1)||!sxasy_add(c,&sxasy_netware2_record,p))return false;uint64_t q=p+4+n,left=z-4-n;if(n==12&&!xx_rt_memcmp(h,"NetWareFile",11)){if(left<61||!sxasy_add(c,&sxasy_netware2_metadata,q))return false;}else if(n==11&&!xx_rt_memcmp(h,"PackedData",10)){if(left<6||!sxasy_add(c,&sxasy_netware2_packed,q))return false;}p+=z;}return true;}
static int sxasy_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxasy_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxasy_order);return !c->failed;}
static bool sx_archivesystems_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_ARCV2:case XX_FILE_TYPE_ARCV4:case XX_FILE_TYPE_CRU:case XX_FILE_TYPE_POWERBOARDBBS:case XX_FILE_TYPE_FLD:case XX_FILE_TYPE_IGF1:case XX_FILE_TYPE_IGF2:case XX_FILE_TYPE_INTEDUFT:case XX_FILE_TYPE_JM93:case XX_FILE_TYPE_MIZ:case XX_FILE_TYPE_MVA:case XX_FILE_TYPE_POVLABLZH:case XX_FILE_TYPE_QIP1:case XX_FILE_TYPE_QUARTERDECKQP:case XX_FILE_TYPE_RCF:case XX_FILE_TYPE_RIVERSOFT:case XX_FILE_TYPE_TGCF:case XX_FILE_TYPE_TRC:case XX_FILE_TYPE_NETWAREPACKED:case XX_FILE_TYPE_NETWARE2:return true;default:return false;}}
static bool sx_archivesystems_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_ARCV2:ok=sxasy_arcv2(c);break;case XX_FILE_TYPE_ARCV4:ok=sxasy_arcv4(c);break;case XX_FILE_TYPE_CRU:ok=sxasy_cru(c);break;case XX_FILE_TYPE_POWERBOARDBBS:ok=sxasy_power(c);break;case XX_FILE_TYPE_FLD:ok=sxasy_fld(c);break;case XX_FILE_TYPE_IGF1:ok=sxasy_igf1(c);break;case XX_FILE_TYPE_IGF2:ok=sxasy_igf2(c);break;case XX_FILE_TYPE_INTEDUFT:ok=sxasy_intedu(c);break;case XX_FILE_TYPE_JM93:ok=sxasy_jm(c);break;case XX_FILE_TYPE_MIZ:ok=sxasy_miz(c);break;case XX_FILE_TYPE_MVA:ok=sxasy_mva(c);break;case XX_FILE_TYPE_POVLABLZH:ok=sxasy_pov(c);break;case XX_FILE_TYPE_QIP1:ok=sxasy_qip(c);break;case XX_FILE_TYPE_QUARTERDECKQP:ok=sxasy_qp(c);break;case XX_FILE_TYPE_RCF:ok=sxasy_rcf(c);break;case XX_FILE_TYPE_RIVERSOFT:ok=sxasy_river(c);break;case XX_FILE_TYPE_TGCF:ok=sxasy_tgcf(c);break;case XX_FILE_TYPE_TRC:ok=sxasy_trc(c);break;case XX_FILE_TYPE_NETWAREPACKED:ok=sxasy_add(c,&sxasy_netwarepacked_header,0);break;case XX_FILE_TYPE_NETWARE2:ok=sxasy_netware2(c);break;default:break;}(void)ok;return c->count&&sxasy_finish(c);}
