/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archiveclassic_scope.txt. */
static const xx_data_struct_field_desc sxacl_dtpacked_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_NONE),
 SX_FIELD("flags","uint16",4,2,SX_NONE),
 SX_FIELD("uninitialized1","uint8[23]",6,23,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",29,4,SX_SIZE),
 SX_FIELD("uninitialized2","uint8[4]",33,4,SX_NONE),
 SX_FIELD("dos_date","uint16",37,2,SX_NONE),
 SX_FIELD("dos_time","uint16",39,2,SX_NONE),
};
static const sx_layout sxacl_dtpacked_header = {UINT32_C(0x60500001),"dtpacked_header",sxacl_dtpacked_header_fields,SX_COUNT(sxacl_dtpacked_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_zlwb_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("marker","uint8",4,1,SX_SIGNATURE),
 SX_FIELD("version","uint32",5,4,SX_NONE),
 SX_FIELD("opaque1","uint8[9]",9,9,SX_NONE),
 SX_FIELD("member_count","int32",18,4,SX_COUNT_PROP),
 SX_FIELD("directory_offset","int32",22,4,SX_OFFSET),
 SX_FIELD("opaque2","uint8[4]",26,4,SX_NONE),
};
static const sx_layout sxacl_zlwb_header = {UINT32_C(0x60500002),"zlwb_header",sxacl_zlwb_header_fields,SX_COUNT(sxacl_zlwb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_zlwb_blob_fields[] = {
 SX_FIELD("unused1","uint32",0,4,SX_NONE),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("record_size","int32",8,4,SX_SIZE),
 SX_FIELD("unused2","uint32",12,4,SX_NONE),
};
static const sx_layout sxacl_zlwb_blob = {UINT32_C(0x60500003),"zlwb_blob",sxacl_zlwb_blob_fields,SX_COUNT(sxacl_zlwb_blob_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_zz_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint64",8,8,SX_NONE),
};
static const sx_layout sxacl_zz_header = {UINT32_C(0x60500004),"zz_header",sxacl_zz_header_fields,SX_COUNT(sxacl_zz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_zzz_member_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",3,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("name","char[12]",11,12,SX_NONE),
 SX_FIELD("reserved","uint8",23,1,SX_NONE),
};
static const sx_layout sxacl_zzz_member = {UINT32_C(0x60500005),"zzz_member",sxacl_zzz_member_fields,SX_COUNT(sxacl_zzz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_header_fields[] = {
 SX_FIELD("signature","uint8[7]",0,7,SX_SIGNATURE),
 SX_FIELD("description_size","int32",7,4,SX_SIZE),
};
static const sx_layout sxacl_jgpak_header = {UINT32_C(0x60500006),"jgpak_header",sxacl_jgpak_header_fields,SX_COUNT(sxacl_jgpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_version_size_fields[] = {
 SX_FIELD("version_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxacl_jgpak_version_size = {UINT32_C(0x60500007),"jgpak_version_size",sxacl_jgpak_version_size_fields,SX_COUNT(sxacl_jgpak_version_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_count_fields[] = {
 SX_FIELD("flag","uint8",0,1,SX_NONE),
 SX_FIELD("member_count","int32",1,4,SX_COUNT_PROP),
};
static const sx_layout sxacl_jgpak_count = {UINT32_C(0x60500008),"jgpak_count",sxacl_jgpak_count_fields,SX_COUNT(sxacl_jgpak_count_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_name_size_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxacl_jgpak_name_size = {UINT32_C(0x60500009),"jgpak_name_size",sxacl_jgpak_name_size_fields,SX_COUNT(sxacl_jgpak_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jgpak_member_fields[] = {
 SX_FIELD("dos_time","uint16",0,2,SX_NONE),
 SX_FIELD("dos_date","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("payload_offset","int32",8,4,SX_OFFSET),
 SX_FIELD("compressed_size","int32",12,4,SX_SIZE),
 SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("unused","uint8[4]",20,4,SX_NONE),
};
static const sx_layout sxacl_jgpak_member = {UINT32_C(0x6050000a),"jgpak_member",sxacl_jgpak_member_fields,SX_COUNT(sxacl_jgpak_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_borlandpack_header_fields[] = {
 SX_FIELD("signature","uint8[23]",0,23,SX_SIGNATURE),
 SX_FIELD("method_tag","char[4]",23,4,SX_SIGNATURE),
 SX_FIELD("method","ascii_decimal[2]",27,2,SX_NONE),
 SX_FIELD("separator","char[1]",29,1,SX_NONE),
 SX_FIELD("version","ascii_decimal[3]",30,3,SX_NONE),
 SX_FIELD("suffix","char[3]",33,3,SX_NONE),
};
static const sx_layout sxacl_borlandpack_header = {UINT32_C(0x6050000b),"borlandpack_header",sxacl_borlandpack_header_fields,SX_COUNT(sxacl_borlandpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_borlandpack_attributes_fields[] = {
 SX_FIELD("uncompressed_size","ascii_decimal[11]",0,11,SX_SIZE),
 SX_FIELD("separator1","char[1]",11,1,SX_NONE),
 SX_FIELD("checksum","ascii_hex[4]",12,4,SX_CHECKSUM),
 SX_FIELD("separator2","char[1]",16,1,SX_NONE),
 SX_FIELD("dos_date","ascii_hex[4]",17,4,SX_NONE),
 SX_FIELD("separator3","char[1]",21,1,SX_NONE),
 SX_FIELD("dos_time","ascii_hex[4]",22,4,SX_NONE),
};
static const sx_layout sxacl_borlandpack_attributes = {UINT32_C(0x6050000c),"borlandpack_attributes",sxacl_borlandpack_attributes_fields,SX_COUNT(sxacl_borlandpack_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_borlandpack_size_fields[] = {
 SX_FIELD("compressed_size","ascii_decimal[10]",0,10,SX_SIZE),
 SX_FIELD("line_end","char[2]",10,2,SX_NONE),
};
static const sx_layout sxacl_borlandpack_size = {UINT32_C(0x6050000d),"borlandpack_size",sxacl_borlandpack_size_fields,SX_COUNT(sxacl_borlandpack_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_borlandpack_lzw_flags_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_NONE),
};
static const sx_layout sxacl_borlandpack_lzw_flags = {UINT32_C(0x6050000e),"borlandpack_lzw_flags",sxacl_borlandpack_lzw_flags_fields,SX_COUNT(sxacl_borlandpack_lzw_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_member_fields[] = {
 SX_FIELD("header_payload_size","uint8",0,1,SX_SIZE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_NONE),
 SX_FIELD("compressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_NONE),
 SX_FIELD("level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
static const sx_layout sxacl_jetbbs_member = {UINT32_C(0x6050000f),"jetbbs_member",sxacl_jetbbs_member_fields,SX_COUNT(sxacl_jetbbs_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_crc16_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxacl_jetbbs_crc16 = {UINT32_C(0x60500010),"jetbbs_crc16",sxacl_jetbbs_crc16_fields,SX_COUNT(sxacl_jetbbs_crc16_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_os_fields[] = {
 SX_FIELD("origin_os","uint8",0,1,SX_NONE),
};
static const sx_layout sxacl_jetbbs_os = {UINT32_C(0x60500011),"jetbbs_os",sxacl_jetbbs_os_fields,SX_COUNT(sxacl_jetbbs_os_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_extension_size_fields[] = {
 SX_FIELD("next_header_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxacl_jetbbs_extension_size = {UINT32_C(0x60500012),"jetbbs_extension_size",sxacl_jetbbs_extension_size_fields,SX_COUNT(sxacl_jetbbs_extension_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_extension_type_fields[] = {
 SX_FIELD("type","uint8",0,1,SX_NONE),
};
static const sx_layout sxacl_jetbbs_extension_type = {UINT32_C(0x60500013),"jetbbs_extension_type",sxacl_jetbbs_extension_type_fields,SX_COUNT(sxacl_jetbbs_extension_type_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_sizes64_fields[] = {
 SX_FIELD("compressed_size","uint64",0,8,SX_SIZE),
 SX_FIELD("uncompressed_size","uint64",8,8,SX_SIZE),
};
static const sx_layout sxacl_jetbbs_sizes64 = {UINT32_C(0x60500014),"jetbbs_sizes64",sxacl_jetbbs_sizes64_fields,SX_COUNT(sxacl_jetbbs_sizes64_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_qualitas_header_fields[] = {
 SX_FIELD("opaque1","uint8[4]",0,4,SX_NONE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("directory_size","uint16",6,2,SX_SIZE),
 SX_FIELD("opaque2","uint8[2]",8,2,SX_NONE),
 SX_FIELD("member_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("opaque3","uint8[2]",12,2,SX_NONE),
};
static const sx_layout sxacl_qualitas_header = {UINT32_C(0x60500015),"qualitas_header",sxacl_qualitas_header_fields,SX_COUNT(sxacl_qualitas_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_qualitas_member_fields[] = {
 SX_FIELD("next_record_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("unused","uint8[2]",4,2,SX_NONE),
 SX_FIELD("payload_offset","int32",6,4,SX_OFFSET),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",14,4,SX_SIZE),
 SX_FIELD("block_size","int32",18,4,SX_SIZE),
 SX_FIELD("attributes","uint16",22,2,SX_NONE),
 SX_FIELD("disk_number","uint8",24,1,SX_NONE),
 SX_FIELD("method","uint8",25,1,SX_NONE),
};
static const sx_layout sxacl_qualitas_member = {UINT32_C(0x60500016),"qualitas_member",sxacl_qualitas_member_fields,SX_COUNT(sxacl_qualitas_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_qualitas_crc32_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxacl_qualitas_crc32 = {UINT32_C(0x60500017),"qualitas_crc32",sxacl_qualitas_crc32_fields,SX_COUNT(sxacl_qualitas_crc32_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwf_member_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("name","char[13]",1,13,SX_NONE),
 SX_FIELD("dos_timestamp","uint32",14,4,SX_NONE),
 SX_FIELD("compressed_size","int32",18,4,SX_SIZE),
};
static const sx_layout sxacl_bwf_member = {UINT32_C(0x60500018),"bwf_member",sxacl_bwf_member_fields,SX_COUNT(sxacl_bwf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_zap_member_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("dos_time","uint16",13,2,SX_NONE),
 SX_FIELD("dos_date","uint16",15,2,SX_NONE),
 SX_FIELD("compressed_size","int32",17,4,SX_SIZE),
};
static const sx_layout sxacl_zap_member = {UINT32_C(0x60500019),"zap_member",sxacl_zap_member_fields,SX_COUNT(sxacl_zap_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_stork_member_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("terminator","char[1]",17,1,SX_SIGNATURE),
};
static const sx_layout sxacl_stork_member = {UINT32_C(0x6050001a),"stork_member",sxacl_stork_member_fields,SX_COUNT(sxacl_stork_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_ascendbackup_name_size_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxacl_ascendbackup_name_size = {UINT32_C(0x6050001b),"ascendbackup_name_size",sxacl_ascendbackup_name_size_fields,SX_COUNT(sxacl_ascendbackup_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_ascendbackup_size_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxacl_ascendbackup_size = {UINT32_C(0x6050001c),"ascendbackup_size",sxacl_ascendbackup_size_fields,SX_COUNT(sxacl_ascendbackup_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fmc1_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxacl_fmc1_header = {UINT32_C(0x6050001d),"fmc1_header",sxacl_fmc1_header_fields,SX_COUNT(sxacl_fmc1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fmc1_member_fields[] = {
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
 SX_FIELD("unknown","uint16",16,2,SX_NONE),
 SX_FIELD("reserved","int16",18,2,SX_NONE),
 SX_FIELD("compressed_size","int32",20,4,SX_SIZE),
};
static const sx_layout sxacl_fmc1_member = {UINT32_C(0x6050001e),"fmc1_member",sxacl_fmc1_member_fields,SX_COUNT(sxacl_fmc1_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_spis_header_fields[] = {
 SX_FIELD("signature","uint8[5]",0,5,SX_SIGNATURE),
 SX_FIELD("method_tag","char[3]",5,3,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("archive_type","uint8",12,1,SX_NONE),
 SX_FIELD("checksum","uint32",13,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",17,4,SX_NONE),
};
static const sx_layout sxacl_spis_header = {UINT32_C(0x6050001f),"spis_header",sxacl_spis_header_fields,SX_COUNT(sxacl_spis_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_spis_member_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",2,4,SX_NONE),
 SX_FIELD("attributes","uint16",6,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("method","uint8",16,1,SX_NONE),
 SX_FIELD("checksum","uint32",17,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",21,4,SX_NONE),
};
static const sx_layout sxacl_spis_member = {UINT32_C(0x60500020),"spis_member",sxacl_spis_member_fields,SX_COUNT(sxacl_spis_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("description","char[81]",5,81,SX_NONE),
};
static const sx_layout sxacl_bwcf_header = {UINT32_C(0x60500021),"bwcf_header",sxacl_bwcf_header_fields,SX_COUNT(sxacl_bwcf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_name_v1_fields[] = {
 SX_FIELD("name","char[268]",0,268,SX_NONE),
};
static const sx_layout sxacl_bwcf_name_v1 = {UINT32_C(0x60500022),"bwcf_name_v1",sxacl_bwcf_name_v1_fields,SX_COUNT(sxacl_bwcf_name_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_name_v2_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("name_size","uint8",5,1,SX_SIZE),
};
static const sx_layout sxacl_bwcf_name_v2 = {UINT32_C(0x60500023),"bwcf_name_v2",sxacl_bwcf_name_v2_fields,SX_COUNT(sxacl_bwcf_name_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_directory_size_fields[] = {
 SX_FIELD("directory_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxacl_bwcf_directory_size = {UINT32_C(0x60500024),"bwcf_directory_size",sxacl_bwcf_directory_size_fields,SX_COUNT(sxacl_bwcf_directory_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_member_fields[] = {
 SX_FIELD("dos_time","uint16",0,2,SX_NONE),
 SX_FIELD("dos_date","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("block_size","int32",8,4,SX_SIZE),
 SX_FIELD("reserved","uint32",12,4,SX_NONE),
 SX_FIELD("method","uint8",16,1,SX_NONE),
};
static const sx_layout sxacl_bwcf_member = {UINT32_C(0x60500025),"bwcf_member",sxacl_bwcf_member_fields,SX_COUNT(sxacl_bwcf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_block_size_fields[] = {
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxacl_bwcf_block_size = {UINT32_C(0x60500026),"bwcf_block_size",sxacl_bwcf_block_size_fields,SX_COUNT(sxacl_bwcf_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_cmp_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",2,2,SX_SIZE),
 SX_FIELD("method","uint16",4,2,SX_NONE),
 SX_FIELD("opaque1","uint8[8]",6,8,SX_NONE),
 SX_FIELD("variant","uint16",14,2,SX_NONE),
 SX_FIELD("opaque2","uint8[24]",16,24,SX_NONE),
 SX_FIELD("name","char[15]",40,15,SX_NONE),
 SX_FIELD("block_size","uint16",55,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",57,4,SX_SIZE),
};
static const sx_layout sxacl_cmp_header = {UINT32_C(0x60500027),"cmp_header",sxacl_cmp_header_fields,SX_COUNT(sxacl_cmp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_count_fields[] = {
 SX_FIELD("record_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxacl_fls_count = {UINT32_C(0x60500028),"fls_count",sxacl_fls_count_fields,SX_COUNT(sxacl_fls_count_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_header_record_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("reserved","uint8",1,1,SX_NONE),
 SX_FIELD("signature","uint8[6]",2,6,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[15]",8,15,SX_NONE),
 SX_FIELD("name_block_size","uint32",23,4,SX_SIZE),
 SX_FIELD("opaque2","uint8[17]",27,17,SX_NONE),
};
static const sx_layout sxacl_fls_header_record = {UINT32_C(0x60500029),"fls_header_record",sxacl_fls_header_record_fields,SX_COUNT(sxacl_fls_header_record_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_member_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("compressed","uint8",1,1,SX_NONE),
 SX_FIELD("signature","uint8[4]",2,4,SX_SIGNATURE),
 SX_FIELD("flag","uint8",6,1,SX_NONE),
 SX_FIELD("letter","char[1]",7,1,SX_NONE),
 SX_FIELD("name_reference","uint32",8,4,SX_OFFSET),
 SX_FIELD("component_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("tail_size","uint32",14,4,SX_SIZE),
 SX_FIELD("opaque1","uint8",18,1,SX_NONE),
 SX_FIELD("payload_offset","uint32",19,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",23,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",27,2,SX_NONE),
 SX_FIELD("dos_time","uint16",29,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",31,4,SX_SIZE),
 SX_FIELD("opaque2","uint8[9]",35,9,SX_NONE),
};
static const sx_layout sxacl_fls_member = {UINT32_C(0x6050002a),"fls_member",sxacl_fls_member_fields,SX_COUNT(sxacl_fls_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_name_header_fields[] = {
 SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("signature","char[7]",2,7,SX_SIGNATURE),
};
static const sx_layout sxacl_fls_name_header = {UINT32_C(0x6050002b),"fls_name_header",sxacl_fls_name_header_fields,SX_COUNT(sxacl_fls_name_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_component_offset_fields[] = {
 SX_FIELD("component_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxacl_fls_component_offset = {UINT32_C(0x6050002c),"fls_component_offset",sxacl_fls_component_offset_fields,SX_COUNT(sxacl_fls_component_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_component_size_fields[] = {
 SX_FIELD("component_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxacl_fls_component_size = {UINT32_C(0x6050002d),"fls_component_size",sxacl_fls_component_size_fields,SX_COUNT(sxacl_fls_component_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_genius_header_fields[] = {
 SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
 SX_FIELD("terminator","uint8",14,1,SX_NONE),
 SX_FIELD("unused","uint8",15,1,SX_NONE),
 SX_FIELD("reserved","uint16",16,2,SX_NONE),
 SX_FIELD("uninitialized","uint8[2]",18,2,SX_NONE),
 SX_FIELD("member_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("opaque","uint8[8]",24,8,SX_NONE),
};
static const sx_layout sxacl_genius_header = {UINT32_C(0x6050002e),"genius_header",sxacl_genius_header_fields,SX_COUNT(sxacl_genius_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_genius_member_fields[] = {
 SX_FIELD("payload_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("compressed_size","uint64",8,8,SX_SIZE),
 SX_FIELD("uncompressed_size","uint64",16,8,SX_SIZE),
 SX_FIELD("opaque1","uint8[16]",24,16,SX_NONE),
 SX_FIELD("write_time","uint64",40,8,SX_NONE),
 SX_FIELD("opaque2","uint8[3]",48,3,SX_NONE),
 SX_FIELD("method","uint8",51,1,SX_NONE),
 SX_FIELD("name_size","uint16",52,2,SX_SIZE),
};
static const sx_layout sxacl_genius_member = {UINT32_C(0x6050002f),"genius_member",sxacl_genius_member_fields,SX_COUNT(sxacl_genius_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_genius_block_size_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxacl_genius_block_size = {UINT32_C(0x60500030),"genius_block_size",sxacl_genius_block_size_fields,SX_COUNT(sxacl_genius_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_genius_footer_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
};
static const sx_layout sxacl_genius_footer = {UINT32_C(0x60500031),"genius_footer",sxacl_genius_footer_fields,SX_COUNT(sxacl_genius_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_hzl_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("separator","char[1]",8,1,SX_SIGNATURE),
 SX_FIELD("extension","char[3]",9,3,SX_NONE),
};
static const sx_layout sxacl_hzl_header = {UINT32_C(0x60500032),"hzl_header",sxacl_hzl_header_fields,SX_COUNT(sxacl_hzl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_kboom_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",8,2,SX_NONE),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
};
static const sx_layout sxacl_kboom_header = {UINT32_C(0x60500033),"kboom_header",sxacl_kboom_header_fields,SX_COUNT(sxacl_kboom_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_archiveclassic_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxacl_archiveclassic_dcl = {UINT32_C(0x60500034),"archiveclassic_dcl",sxacl_archiveclassic_dcl_fields,SX_COUNT(sxacl_archiveclassic_dcl_fields),SX_LE};
static const sx_layout *const sx_archiveclassic_layouts[] = {
 &sxacl_dtpacked_header,
 &sxacl_zlwb_header,
 &sxacl_zlwb_blob,
 &sxacl_zz_header,
 &sxacl_zzz_member,
 &sxacl_jgpak_header,
 &sxacl_jgpak_version_size,
 &sxacl_jgpak_count,
 &sxacl_jgpak_name_size,
 &sxacl_jgpak_member,
 &sxacl_borlandpack_header,
 &sxacl_borlandpack_attributes,
 &sxacl_borlandpack_size,
 &sxacl_borlandpack_lzw_flags,
 &sxacl_jetbbs_member,
 &sxacl_jetbbs_crc16,
 &sxacl_jetbbs_os,
 &sxacl_jetbbs_extension_size,
 &sxacl_jetbbs_extension_type,
 &sxacl_jetbbs_sizes64,
 &sxacl_qualitas_header,
 &sxacl_qualitas_member,
 &sxacl_qualitas_crc32,
 &sxacl_bwf_member,
 &sxacl_zap_member,
 &sxacl_stork_member,
 &sxacl_ascendbackup_name_size,
 &sxacl_ascendbackup_size,
 &sxacl_fmc1_header,
 &sxacl_fmc1_member,
 &sxacl_spis_header,
 &sxacl_spis_member,
 &sxacl_bwcf_header,
 &sxacl_bwcf_name_v1,
 &sxacl_bwcf_name_v2,
 &sxacl_bwcf_directory_size,
 &sxacl_bwcf_member,
 &sxacl_bwcf_block_size,
 &sxacl_cmp_header,
 &sxacl_fls_count,
 &sxacl_fls_header_record,
 &sxacl_fls_member,
 &sxacl_fls_name_header,
 &sxacl_fls_component_offset,
 &sxacl_fls_component_size,
 &sxacl_genius_header,
 &sxacl_genius_member,
 &sxacl_genius_block_size,
 &sxacl_genius_footer,
 &sxacl_hzl_header,
 &sxacl_kboom_header,
 &sxacl_archiveclassic_dcl,
};
static bool sx_archiveclassic_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60500000U||id>=0x60510000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60500001U:
 if(!xx_rt_wcscmp(r->name,L"uninitialized1"))text=L"Uninitialized writer memory, not a filename or checksum";
 if(!xx_rt_wcscmp(r->name,L"uninitialized2"))text=L"Uninitialized writer memory";
 break;
 case 0x60500003U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Decoded record width, 272 or 552";
 break;
 case 0x6050000bU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"Archive-wide method";
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"100 denotes version 1.00";
 break;
 case 0x6050000cU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Unidentified checksum algorithm";
 break;
 case 0x6050000eU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Unix compress flags: 0x80 block mode, low five bits maximum code width; the 1F9D magic is not stored";
 break;
 case 0x6050000fU:
 if(!xx_rt_wcscmp(r->name,L"header_payload_size"))text=L"Excludes size and checksum bytes";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"-mg0- stored, -mg4- lh4, -mg5- lh5";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Level 1 includes extended-header bytes";
 break;
 case 0x60500012U:
 if(!xx_rt_wcscmp(r->name,L"next_header_size"))text=L"Zero ends the extension chain; nonzero counts the physical extension bytes following the current length word";
 break;
 case 0x60500013U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"0 header CRC, 1 replacement filename, 2 directory, 0x42 64-bit size copies";
 break;
 case 0x60500015U:
 if(!xx_rt_wcscmp(r->name,L"directory_size"))text=L"Excludes the 14-byte archive header";
 break;
 case 0x60500016U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Includes the four-byte checksum preceding DCL data";
 if(!xx_rt_wcscmp(r->name,L"disk_number"))text=L"1 means current volume";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"Observed 0 and 1 both carry DCL; not a codec selector";
 break;
 case 0x60500018U:
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"Native name stops before the last slot, which may contain stale memory";
 break;
 case 0x6050001fU:
 if(!xx_rt_wcscmp(r->name,L"method_tag"))text=L"NON, RLE, LZH, CUS or LH5";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Total plaintext size of this segment";
 if(!xx_rt_wcscmp(r->name,L"archive_type"))text=L"0 single stream, 1 named members";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Byte sum, used only by type 0";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"0..2; 2 means XOR-masked data";
 break;
 case 0x60500020U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 NON, 1 RLE, 2 LZH, 3 CUS, 4 LH5";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of uncompressed bytes";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"0..2; 2 means XOR-masked data";
 break;
 case 0x60500025U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Includes the four-byte repeated plain length";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 LZHUF, 3 stored";
 break;
 case 0x60500027U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 framed LZW/stored; 2 LZSS or DCL selected by payload preamble";
 if(!xx_rt_wcscmp(r->name,L"variant"))text=L"9 old, 11 newer";
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"LZW framing width, 0x1000 bytes";
 break;
 case 0x60500028U:
 if(!xx_rt_wcscmp(r->name,L"record_count"))text=L"Includes the leading header record; member count is one less";
 break;
 case 0x6050002aU:
 if(!xx_rt_wcscmp(r->name,L"compressed"))text=L"0 stored, 1 FLS-LZ";
 if(!xx_rt_wcscmp(r->name,L"name_reference"))text=L"Relative to the start of the name block";
 if(!xx_rt_wcscmp(r->name,L"tail_size"))text=L"Padding following this member payload";
 break;
 case 0x6050002cU:
 if(!xx_rt_wcscmp(r->name,L"component_offset"))text=L"Relative to the start of the name block";
 break;
 case 0x6050002eU:
 if(!xx_rt_wcscmp(r->name,L"uninitialized"))text=L"Uninitialized writer memory, not a version";
 break;
 case 0x6050002fU:
 if(!xx_rt_wcscmp(r->name,L"write_time"))text=L"Stored timestamp; epoch unspecified";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 separately framed DCL blocks";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Includes the stored NUL";
 break;
 case 0x60500031U:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Unfinalized reflected EDB88320 accumulator seeded with 0xFFFFFFFF, equivalent to CRC-32/JAMCRC";
 break;
 case 0x60500034U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 binary or 1 coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4, 5 or 6; PKWARE DCL dictionary parameter";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXACL_LIMIT 20000U
static bool sxacl_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxacl_read(sx_context*c,uint64_t p,void*b,size_t n){return sxacl_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxacl_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxacl_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxacl_read(c,p,b,n))return false;*v=sxacl_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
static bool sxacl_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXACL_LIMIT||!sxacl_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxacl_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxacl_read(c,(*p)++,&b,1))return false;if(!b)return true;}return false;}
static bool sxacl_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t h[2];return n<2||!sxacl_read(c,p,h,2)||h[0]>1||h[1]<4||h[1]>6?true:sxacl_add(c,&sxacl_archiveclassic_dcl,p);}
static bool sxacl_zlwb(sx_context*c){uint64_t n,p;if(!sxacl_word(c,18,4,false,&n)||n>INT32_MAX||!sxacl_word(c,22,4,false,&p)||p<30||p>INT32_MAX||!sxacl_add(c,&sxacl_zlwb_header,0))return false;for(uint64_t i=0;i<n;i++){uint8_t b[16];if(!sxacl_read(c,p,b,16))return false;uint64_t z=sxacl_uint(b+4,4,false),plain=sxacl_uint(b+8,4,false);if(z>INT32_MAX||(plain!=272&&plain!=552)||!sxacl_span(c,p+16,z)||!sxacl_add(c,&sxacl_zlwb_blob,p))return false;p+=16+z;}return true;}
static bool sxacl_chain(sx_context*c,const sx_layout*l,uint64_t p,unsigned hs,unsigned sizeoff,bool sign,bool dcl){for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[24];if(hs>sizeof(h)||sizeoff>hs||hs-sizeoff<4||!sxacl_read(c,p,h,hs))return false;if((l==&sxacl_zzz_member&&xx_rt_memcmp(h,"ZZZ",3))||(l==&sxacl_bwf_member&&h[0]!=1)||((l==&sxacl_zap_member||l==&sxacl_stork_member)&&(!h[0]||h[0]>12))||(l==&sxacl_stork_member&&h[17]!='$'))return false;uint64_t z=sxacl_uint(h+sizeoff,4,false);if((sign&&z>INT32_MAX)||!sxacl_span(c,p+hs,z)||!sxacl_add(c,l,p))return false;if(dcl&&!sxacl_dcl(c,p+hs,z))return false;p+=hs+z;}return true;}
static bool sxacl_jg(sx_context*c){uint64_t z,p,n;if(!sxacl_word(c,7,4,false,&z)||z>INT32_MAX||!sxacl_span(c,11,z)||!sxacl_add(c,&sxacl_jgpak_header,0))return false;p=11+z;if(!sxacl_word(c,p,4,false,&z)||z>INT32_MAX||!sxacl_span(c,p+4,z)||!sxacl_add(c,&sxacl_jgpak_version_size,p))return false;p+=4+z;if(!sxacl_word(c,p+1,4,false,&n)||n>INT32_MAX||!sxacl_add(c,&sxacl_jgpak_count,p))return false;p+=5;for(uint64_t i=0;i<n;i++){if(!sxacl_word(c,p,1,false,&z)||!z||!sxacl_span(c,p+1,z+24)||!sxacl_add(c,&sxacl_jgpak_name_size,p)||!sxacl_add(c,&sxacl_jgpak_member,p+1+z))return false;p+=25+z;}return true;}
static bool sxacl_decimal(sx_context*c,uint64_t p,unsigned n,uint64_t*v){uint8_t b[24];if(n>24||!sxacl_read(c,p,b,n))return false;unsigned i=0;while(i<n&&b[i]==' ')i++;if(i==n)return false;uint64_t a=0;for(;i<n;i++){if(b[i]<'0'||b[i]>'9'||a>(UINT64_MAX-(b[i]-'0'))/10)return false;a=a*10+b[i]-'0';}*v=a;return true;}
static bool sxacl_hex4(sx_context*c,uint64_t p){uint8_t b[4];if(!sxacl_read(c,p,b,4))return false;for(unsigned i=0;i<4;i++)if(!((b[i]>='0'&&b[i]<='9')||(b[i]>='A'&&b[i]<='F')))return false;return true;}
static bool sxacl_borland(sx_context*c){uint64_t p=36;if(!sxacl_add(c,&sxacl_borlandpack_header,0))return false;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint64_t q=p+1,z;bool found=false;for(unsigned j=0;j<4096;j++,q++){uint8_t b[2];if(!sxacl_read(c,q,b,2))return false;if(b[0]=='\r'&&b[1]=='\n'){found=true;break;}}if(!found||q-p<28||!sxacl_hex4(c,q-14)||!sxacl_hex4(c,q-9)||!sxacl_hex4(c,q-4)||!sxacl_add(c,&sxacl_borlandpack_attributes,q-26)||!sxacl_add(c,&sxacl_borlandpack_size,q+2)||!sxacl_decimal(c,q+2,10,&z)||!sxacl_span(c,q+14,z))return false;if(z&&!sxacl_add(c,&sxacl_borlandpack_lzw_flags,q+14))return false;p=q+14+z;}return true;}
static bool sxacl_jet(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[22];if(!sxacl_read(c,p,h,1)||!h[0])return true;if(!sxacl_read(c,p,h,22)||h[20]>1)return false;uint64_t hs=h[0]+2,n=h[21],z=sxacl_uint(h+7,4,false),q=p+hs,used=0;if(hs<(h[20]?27:24)+n||!sxacl_span(c,p,hs)||!sxacl_span(c,q,z)||!sxacl_add(c,&sxacl_jetbbs_member,p)||!sxacl_add(c,&sxacl_jetbbs_crc16,p+22+n))return false;if(h[20]){uint64_t ex;if(!sxacl_add(c,&sxacl_jetbbs_os,p+24+n)||!sxacl_add(c,&sxacl_jetbbs_extension_size,p+hs-2)||!sxacl_word(c,p+hs-2,2,false,&ex))return false;while(ex){uint8_t type;if(ex<3||ex>z-used||!sxacl_read(c,q,&type,1)||!sxacl_add(c,&sxacl_jetbbs_extension_type,q))return false;if(type==0&&ex>=5){if(!sxacl_add(c,&sxacl_jetbbs_crc16,q+1))return false;}else if(type==0x42&&ex>=19){if(!sxacl_add(c,&sxacl_jetbbs_sizes64,q+1))return false;}if(!sxacl_add(c,&sxacl_jetbbs_extension_size,q+ex-2))return false;used+=ex;q+=ex;if(!sxacl_word(c,q-2,2,false,&ex))return false;}}p+=hs+z;}return true;}
static bool sxacl_qualitas(sx_context*c){uint64_t z,n,p=14;if(!sxacl_word(c,6,2,false,&z)||!sxacl_word(c,10,2,false,&n)||!sxacl_span(c,p,z)||!sxacl_add(c,&sxacl_qualitas_header,0))return false;uint64_t end=p+z;for(uint64_t i=0;i<n;i++){uint8_t h[26];if(p>end||end-p<26||!sxacl_read(c,p,h,26)||!sxacl_add(c,&sxacl_qualitas_member,p))return false;uint64_t next=sxacl_uint(h,4,false),data=sxacl_uint(h+6,4,false),packed=sxacl_uint(h+18,4,false),q=p+26;if(!sxacl_zstr(c,&q,end,256)||next!=q)return false;if(h[24]==1&&h[25]<=1&&data>=end&&packed>=4&&packed<=INT32_MAX&&sxacl_span(c,data,packed)){if(!sxacl_add(c,&sxacl_qualitas_crc32,data)||!sxacl_dcl(c,data+4,packed-4))return false;}p=q;}return true;}
static bool sxacl_ascend(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint64_t n,z;if(!sxacl_word(c,p,2,false,&n)||!n||n>12||!sxacl_word(c,p+2+n,4,false,&z)||!sxacl_span(c,p+6+n,z)||!sxacl_add(c,&sxacl_ascendbackup_name_size,p)||!sxacl_add(c,&sxacl_ascendbackup_size,p+2+n)||!sxacl_dcl(c,p+6+n,z))return false;p+=6+n+z;}return true;}
static bool sxacl_spis(sx_context*c){uint64_t p=0;bool members=false;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[25];if(!sxacl_read(c,p,h,5))return false;if(!xx_rt_memcmp(h,"SPIS\032",5)){if(!sxacl_read(c,p,h,21)||!sxacl_add(c,&sxacl_spis_header,p))return false;members=h[12]==1;p+=21;if(!members)return true;}else{if(!members||!sxacl_read(c,p,h,25))return false;uint64_t n=sxacl_uint(h,2,false),z=sxacl_uint(h+12,4,false);if(!n||n>4096||!sxacl_span(c,p+25,n)||!sxacl_span(c,p+25+n,z)||!sxacl_add(c,&sxacl_spis_member,p))return false;p+=25+n+z;}}return true;}
static bool sxacl_bwcf(sx_context*c){uint64_t version,p=86;if(!sxacl_word(c,4,1,false,&version)||(version!=1&&version!=2)||!sxacl_add(c,&sxacl_bwcf_header,0))return false;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){if(version==1){if(!sxacl_add(c,&sxacl_bwcf_name_v1,p))return false;p+=268;}else{uint64_t n;if(!sxacl_word(c,p+5,1,false,&n)||!sxacl_span(c,p+6,n)||!sxacl_add(c,&sxacl_bwcf_name_v2,p))return false;p+=6+n;if(!sxacl_word(c,p,1,false,&n)||!sxacl_span(c,p+1,n)||!sxacl_add(c,&sxacl_bwcf_directory_size,p))return false;p+=1+n;}uint64_t z;if(!sxacl_word(c,p+8,4,false,&z)||z<4||z>INT32_MAX||!sxacl_span(c,p+17,z)||!sxacl_add(c,&sxacl_bwcf_member,p)||!sxacl_add(c,&sxacl_bwcf_block_size,p+17))return false;p+=17+z;}return true;}
static bool sxacl_fls(sx_context*c){uint64_t n,names,base,bytes;if(!sxacl_word(c,0,2,false,&n)||n<2||!sxacl_span(c,2,n*44)||!sxacl_word(c,25,4,false,&bytes)||!sxacl_add(c,&sxacl_fls_count,0)||!sxacl_add(c,&sxacl_fls_header_record,2))return false;base=2+n*44;if(bytes<9||!sxacl_span(c,base,bytes)||!sxacl_add(c,&sxacl_fls_name_header,base))return false;for(uint64_t i=1;i<n;i++)if(!sxacl_add(c,&sxacl_fls_member,2+i*44))return false;for(uint64_t i=1;i<n;i++){uint8_t h[14];if(!sxacl_read(c,2+i*44,h,14))return false;uint64_t off=sxacl_uint(h+8,4,false);names=sxacl_uint(h+12,2,false);if(off>bytes||names>(bytes-off)/4)continue;for(uint64_t j=0;j<names;j++){uint64_t q,z;if(!sxacl_word(c,base+off+j*4,4,false,&q)||!sxacl_add(c,&sxacl_fls_component_offset,base+off+j*4))return false;if(q<9||q>=bytes||!sxacl_word(c,base+q,1,false,&z)||z>bytes-q-1)continue;if(!sxacl_add(c,&sxacl_fls_component_size,base+q))return false;}}return true;}
static bool sxacl_genius(sx_context*c){uint64_t n,p=32;if(!sxacl_word(c,20,4,false,&n)||!sxacl_add(c,&sxacl_genius_header,0))return false;for(uint64_t i=0;i<n;i++){uint8_t h[54];if(!sxacl_read(c,p,h,54))return false;uint64_t z=sxacl_uint(h+8,8,false),names=sxacl_uint(h+52,2,false),q=p+54+names;if(!sxacl_span(c,p+54,names)||!sxacl_span(c,q,z)||!sxacl_add(c,&sxacl_genius_member,p))return false;if(h[51]==1&&z>=8){uint64_t cursor=q,end=q+z-8;while(cursor<end){uint64_t k;if(end-cursor<4||!sxacl_word(c,cursor,4,false,&k)||k>end-cursor-4)break;if(!sxacl_add(c,&sxacl_genius_block_size,cursor)||!sxacl_dcl(c,cursor+4,k))return false;cursor+=4+k;}if(!sxacl_add(c,&sxacl_genius_footer,end))return false;}p=q+z;}return true;}
static int sxacl_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxacl_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxacl_order);return !c->failed;}
static bool sxacl_cmp(sx_context*c){uint64_t method;if(!sxacl_word(c,4,2,false,&method)||!sxacl_add(c,&sxacl_cmp_header,0))return false;return method!=2||sxacl_dcl(c,61,(uint64_t)c->size-61);}
static bool sx_archiveclassic_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_DTPACKED:case XX_FILE_TYPE_ZLWB:case XX_FILE_TYPE_ZZ:case XX_FILE_TYPE_ZZZ:case XX_FILE_TYPE_JGPAK:case XX_FILE_TYPE_BORLANDPACK:case XX_FILE_TYPE_JETBBS:case XX_FILE_TYPE_QUALITAS:case XX_FILE_TYPE_BWF:case XX_FILE_TYPE_ZAP:case XX_FILE_TYPE_STORK:case XX_FILE_TYPE_ASCENDBACKUP:case XX_FILE_TYPE_FMC1:case XX_FILE_TYPE_SPIS:case XX_FILE_TYPE_BWCF:case XX_FILE_TYPE_CMP:case XX_FILE_TYPE_FLS:case XX_FILE_TYPE_GENIUS:case XX_FILE_TYPE_HZL:case XX_FILE_TYPE_KBOOM:return true;default:return false;}}
static bool sx_archiveclassic_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_DTPACKED:ok=sxacl_add(c,&sxacl_dtpacked_header,0)&&sxacl_dcl(c,41,(uint64_t)c->size-41);break;case XX_FILE_TYPE_ZLWB:ok=sxacl_zlwb(c);break;case XX_FILE_TYPE_ZZ:ok=sxacl_add(c,&sxacl_zz_header,0);break;case XX_FILE_TYPE_ZZZ:ok=sxacl_chain(c,&sxacl_zzz_member,0,24,3,false,true);break;case XX_FILE_TYPE_JGPAK:ok=sxacl_jg(c);break;case XX_FILE_TYPE_BORLANDPACK:ok=sxacl_borland(c);break;case XX_FILE_TYPE_JETBBS:ok=sxacl_jet(c);break;case XX_FILE_TYPE_QUALITAS:ok=sxacl_qualitas(c);break;case XX_FILE_TYPE_BWF:ok=sxacl_chain(c,&sxacl_bwf_member,0,22,18,true,true);break;case XX_FILE_TYPE_ZAP:ok=sxacl_chain(c,&sxacl_zap_member,0,21,17,true,true);break;case XX_FILE_TYPE_STORK:ok=sxacl_chain(c,&sxacl_stork_member,0,18,13,true,true);break;case XX_FILE_TYPE_ASCENDBACKUP:ok=sxacl_ascend(c);break;case XX_FILE_TYPE_FMC1:ok=sxacl_add(c,&sxacl_fmc1_header,0)&&sxacl_chain(c,&sxacl_fmc1_member,4,24,20,true,false);break;case XX_FILE_TYPE_SPIS:ok=sxacl_spis(c);break;case XX_FILE_TYPE_BWCF:ok=sxacl_bwcf(c);break;case XX_FILE_TYPE_CMP:ok=sxacl_cmp(c);break;case XX_FILE_TYPE_FLS:ok=sxacl_fls(c);break;case XX_FILE_TYPE_GENIUS:ok=sxacl_genius(c);break;case XX_FILE_TYPE_HZL:ok=sxacl_add(c,&sxacl_hzl_header,0);break;case XX_FILE_TYPE_KBOOM:ok=sxacl_add(c,&sxacl_kboom_header,0);break;default:break;}(void)ok;return c->count&&sxacl_finish(c);}
