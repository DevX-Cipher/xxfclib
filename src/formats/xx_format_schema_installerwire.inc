/* SPDX-License-Identifier: MIT. Physical metadata. Scope: docs/data_struct_installerwire_scope.txt. */
static const xx_data_struct_field_desc sxiw_is7inx_header_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
 SX_FIELD("encoded_reserved","uint8[2]",4,2,SX_NONE),
 SX_FIELD("encoded_copyright","uint8[73]",6,73,SX_NONE),
 SX_FIELD("encoded_padding","uint8[25]",79,25,SX_NONE),
 SX_FIELD("encoded_header_size","uint8[4]",104,4,SX_NONE),
 SX_FIELD("encoded_section_offset_0","uint8[4]",108,4,SX_NONE),
 SX_FIELD("encoded_section_offset_1","uint8[4]",112,4,SX_NONE),
 SX_FIELD("encoded_section_offset_2","uint8[4]",116,4,SX_NONE),
 SX_FIELD("encoded_section_offset_3","uint8[4]",120,4,SX_NONE),
};
static const sx_layout sxiw_is7inx_header={UINT32_C(0x60790001),"is7inx_header",sxiw_is7inx_header_fields,SX_COUNT(sxiw_is7inx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_izpack_stream_header_fields[]={
 SX_FIELD("stream_magic","uint16be",0,2,SX_SIGNATURE),
 SX_FIELD("stream_version","uint16be",2,2,SX_NONE),
 SX_FIELD("block_data_tag","uint8",4,1,SX_ID),
 SX_FIELD("count_block_size","uint8",5,1,SX_SIZE),
 SX_FIELD("record_count","int32be",6,4,SX_COUNT_PROP),
};
static const sx_layout sxiw_izpack_stream_header={UINT32_C(0x60790002),"izpack_stream_header",sxiw_izpack_stream_header_fields,SX_COUNT(sxiw_izpack_stream_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_object_tag_fields[]={
 SX_FIELD("object_tag","uint8",0,1,SX_ID),
};
static const sx_layout sxiw_java_object_tag={UINT32_C(0x60790003),"java_object_tag",sxiw_java_object_tag_fields,SX_COUNT(sxiw_java_object_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_class_tag_fields[]={
 SX_FIELD("class_descriptor_tag","uint8",0,1,SX_ID),
};
static const sx_layout sxiw_java_class_tag={UINT32_C(0x60790004),"java_class_tag",sxiw_java_class_tag_fields,SX_COUNT(sxiw_java_class_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_utf_length_fields[]={
 SX_FIELD("modified_utf8_length","uint16be",0,2,SX_SIZE),
};
static const sx_layout sxiw_java_utf_length={UINT32_C(0x60790005),"java_utf_length",sxiw_java_utf_length_fields,SX_COUNT(sxiw_java_utf_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_class_metadata_fields[]={
 SX_FIELD("serial_version_uid","uint64be",0,8,SX_ID),
 SX_FIELD("class_flags","uint8",8,1,SX_FLAGS),
 SX_FIELD("field_count","uint16be",9,2,SX_COUNT_PROP),
};
static const sx_layout sxiw_java_class_metadata={UINT32_C(0x60790006),"java_class_metadata",sxiw_java_class_metadata_fields,SX_COUNT(sxiw_java_class_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_field_type_fields[]={
 SX_FIELD("type_code","char[1]",0,1,SX_ID),
};
static const sx_layout sxiw_java_field_type={UINT32_C(0x60790007),"java_field_type",sxiw_java_field_type_fields,SX_COUNT(sxiw_java_field_type_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_reference_fields[]={
 SX_FIELD("reference_tag","uint8",0,1,SX_ID),
 SX_FIELD("wire_handle","uint32be",1,4,SX_ID),
};
static const sx_layout sxiw_java_reference={UINT32_C(0x60790008),"java_reference",sxiw_java_reference_fields,SX_COUNT(sxiw_java_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_string_fields[]={
 SX_FIELD("string_tag","uint8",0,1,SX_ID),
 SX_FIELD("modified_utf8_length","uint16be",1,2,SX_SIZE),
};
static const sx_layout sxiw_java_string={UINT32_C(0x60790009),"java_string",sxiw_java_string_fields,SX_COUNT(sxiw_java_string_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_long_string_fields[]={
 SX_FIELD("string_tag","uint8",0,1,SX_ID),
 SX_FIELD("modified_utf8_length","uint64be",1,8,SX_SIZE),
};
static const sx_layout sxiw_java_long_string={UINT32_C(0x6079000a),"java_long_string",sxiw_java_long_string_fields,SX_COUNT(sxiw_java_long_string_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_block_fields[]={
 SX_FIELD("block_tag","uint8",0,1,SX_ID),
 SX_FIELD("block_length","uint8",1,1,SX_SIZE),
};
static const sx_layout sxiw_java_block={UINT32_C(0x6079000b),"java_block",sxiw_java_block_fields,SX_COUNT(sxiw_java_block_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_long_block_fields[]={
 SX_FIELD("block_tag","uint8",0,1,SX_ID),
 SX_FIELD("block_length","uint32be",1,4,SX_SIZE),
};
static const sx_layout sxiw_java_long_block={UINT32_C(0x6079000c),"java_long_block",sxiw_java_long_block_fields,SX_COUNT(sxiw_java_long_block_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_boolean_fields[]={
 SX_FIELD("boolean","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxiw_java_boolean={UINT32_C(0x6079000d),"java_boolean",sxiw_java_boolean_fields,SX_COUNT(sxiw_java_boolean_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_byte_fields[]={
 SX_FIELD("byte","int8",0,1,SX_NONE),
};
static const sx_layout sxiw_java_byte={UINT32_C(0x6079000e),"java_byte",sxiw_java_byte_fields,SX_COUNT(sxiw_java_byte_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_char_fields[]={
 SX_FIELD("char","uint16be",0,2,SX_NONE),
};
static const sx_layout sxiw_java_char={UINT32_C(0x6079000f),"java_char",sxiw_java_char_fields,SX_COUNT(sxiw_java_char_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_short_fields[]={
 SX_FIELD("short","int16be",0,2,SX_NONE),
};
static const sx_layout sxiw_java_short={UINT32_C(0x60790010),"java_short",sxiw_java_short_fields,SX_COUNT(sxiw_java_short_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_int_fields[]={
 SX_FIELD("int","int32be",0,4,SX_NONE),
};
static const sx_layout sxiw_java_int={UINT32_C(0x60790011),"java_int",sxiw_java_int_fields,SX_COUNT(sxiw_java_int_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_long_fields[]={
 SX_FIELD("long","int64be",0,8,SX_NONE),
};
static const sx_layout sxiw_java_long={UINT32_C(0x60790012),"java_long",sxiw_java_long_fields,SX_COUNT(sxiw_java_long_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_float_fields[]={
 SX_FIELD("float","float",0,4,SX_NONE),
};
static const sx_layout sxiw_java_float={UINT32_C(0x60790013),"java_float",sxiw_java_float_fields,SX_COUNT(sxiw_java_float_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_double_fields[]={
 SX_FIELD("double","double",0,8,SX_NONE),
};
static const sx_layout sxiw_java_double={UINT32_C(0x60790014),"java_double",sxiw_java_double_fields,SX_COUNT(sxiw_java_double_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_shell_interpreter_fields[]={
 SX_FIELD("shell_interpreter","utf8",0,0,SX_STRING),
};
static const sx_layout sxiw_shell_interpreter={UINT32_C(0x60790015),"shell_interpreter",sxiw_shell_interpreter_fields,SX_COUNT(sxiw_shell_interpreter_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_shell_assignment_name_fields[]={
 SX_FIELD("shell_assignment_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxiw_shell_assignment_name={UINT32_C(0x60790016),"shell_assignment_name",sxiw_shell_assignment_name_fields,SX_COUNT(sxiw_shell_assignment_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_shell_assignment_value_fields[]={
 SX_FIELD("shell_assignment_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxiw_shell_assignment_value={UINT32_C(0x60790017),"shell_assignment_value",sxiw_shell_assignment_value_fields,SX_COUNT(sxiw_shell_assignment_value_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_shell_line_count_fields[]={
 SX_FIELD("shell_line_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxiw_shell_line_count={UINT32_C(0x60790018),"shell_line_count",sxiw_shell_line_count_fields,SX_COUNT(sxiw_shell_line_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_shell_block_index_fields[]={
 SX_FIELD("shell_block_index","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxiw_shell_block_index={UINT32_C(0x60790019),"shell_block_index",sxiw_shell_block_index_fields,SX_COUNT(sxiw_shell_block_index_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_shell_payload_size_fields[]={
 SX_FIELD("shell_payload_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxiw_shell_payload_size={UINT32_C(0x6079001a),"shell_payload_size",sxiw_shell_payload_size_fields,SX_COUNT(sxiw_shell_payload_size_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_shell_block_size_fields[]={
 SX_FIELD("shell_block_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxiw_shell_block_size={UINT32_C(0x6079001b),"shell_block_size",sxiw_shell_block_size_fields,SX_COUNT(sxiw_shell_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_package_name_fields[]={
 SX_FIELD("solaris_package_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxiw_solaris_package_name={UINT32_C(0x6079001c),"solaris_package_name",sxiw_solaris_package_name_fields,SX_COUNT(sxiw_solaris_package_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_part_count_fields[]={
 SX_FIELD("solaris_part_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxiw_solaris_part_count={UINT32_C(0x6079001d),"solaris_part_count",sxiw_solaris_part_count_fields,SX_COUNT(sxiw_solaris_part_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_block_count_fields[]={
 SX_FIELD("solaris_block_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxiw_solaris_block_count={UINT32_C(0x6079001e),"solaris_block_count",sxiw_solaris_block_count_fields,SX_COUNT(sxiw_solaris_block_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_banner_fields[]={
 SX_FIELD("signature","char[21]",0,21,SX_SIGNATURE),
};
static const sx_layout sxiw_solaris_banner={UINT32_C(0x6079001f),"solaris_banner",sxiw_solaris_banner_fields,SX_COUNT(sxiw_solaris_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_end_header_fields[]={
 SX_FIELD("end_marker","char[15]",0,15,SX_SIGNATURE),
};
static const sx_layout sxiw_solaris_end_header={UINT32_C(0x60790020),"solaris_end_header",sxiw_solaris_end_header_fields,SX_COUNT(sxiw_solaris_end_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_opc_banner_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version_and_part_description","char[71]",8,71,SX_STRING),
 SX_FIELD("terminator","uint8",79,1,SX_SIGNATURE),
};
static const sx_layout sxiw_opc_banner={UINT32_C(0x60790021),"opc_banner",sxiw_opc_banner_fields,SX_COUNT(sxiw_opc_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_uids_fields[]={
 SX_FIELD("uid1","uint32le",0,4,SX_ID),
 SX_FIELD("uid2","uint32le",4,4,SX_ID),
 SX_FIELD("uid3","uint32le",8,4,SX_ID),
 SX_FIELD("uid_checksum","uint32le",12,4,SX_CHECKSUM),
};
static const sx_layout sxiw_sis_uids={UINT32_C(0x60790022),"sis_uids",sxiw_sis_uids_fields,SX_COUNT(sxiw_sis_uids_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_epoc_header_fields[]={
 SX_FIELD("uid1","uint32le",0,4,SX_ID),
 SX_FIELD("uid2","uint32le",4,4,SX_ID),
 SX_FIELD("uid3","uint32le",8,4,SX_ID),
 SX_FIELD("uid_checksum","uint32le",12,4,SX_CHECKSUM),
 SX_FIELD("file_crc16","uint16le",16,2,SX_CHECKSUM),
 SX_FIELD("language_count","uint16le",18,2,SX_COUNT_PROP),
 SX_FIELD("file_record_count","uint16le",20,2,SX_COUNT_PROP),
 SX_FIELD("requisite_count","uint16le",22,2,SX_COUNT_PROP),
 SX_FIELD("installation_language","uint16le",24,2,SX_ID),
 SX_FIELD("installation_files","uint16le",26,2,SX_COUNT_PROP),
 SX_FIELD("installation_drive","uint16le",28,2,SX_ID),
 SX_FIELD("capability_count","uint16le",30,2,SX_COUNT_PROP),
 SX_FIELD("installer_version","uint32le",32,4,SX_NONE),
 SX_FIELD("options","uint16le",36,2,SX_FLAGS),
 SX_FIELD("package_type","uint16le",38,2,SX_ID),
 SX_FIELD("version_major","uint16le",40,2,SX_NONE),
 SX_FIELD("version_minor","uint16le",42,2,SX_NONE),
 SX_FIELD("variant","uint32le",44,4,SX_NONE),
 SX_FIELD("languages_offset","uint32le",48,4,SX_OFFSET),
 SX_FIELD("file_records_offset","uint32le",52,4,SX_OFFSET),
 SX_FIELD("requisites_offset","uint32le",56,4,SX_OFFSET),
 SX_FIELD("certificates_offset","uint32le",60,4,SX_OFFSET),
 SX_FIELD("component_names_offset","uint32le",64,4,SX_OFFSET),
};
static const sx_layout sxiw_sis_epoc_header={UINT32_C(0x60790023),"sis_epoc_header",sxiw_sis_epoc_header_fields,SX_COUNT(sxiw_sis_epoc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_epoc6_extension_fields[]={
 SX_FIELD("signature_offset","uint32le",0,4,SX_OFFSET),
 SX_FIELD("capabilities_offset","uint32le",4,4,SX_OFFSET),
};
static const sx_layout sxiw_sis_epoc6_extension={UINT32_C(0x60790024),"sis_epoc6_extension",sxiw_sis_epoc6_extension_fields,SX_COUNT(sxiw_sis_epoc6_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_installed_space_fields[]={
 SX_FIELD("installed_space","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxiw_sis_installed_space={UINT32_C(0x60790025),"sis_installed_space",sxiw_sis_installed_space_fields,SX_COUNT(sxiw_sis_installed_space_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_maximum_installed_space_fields[]={
 SX_FIELD("maximum_installed_space","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxiw_sis_maximum_installed_space={UINT32_C(0x60790026),"sis_maximum_installed_space",sxiw_sis_maximum_installed_space_fields,SX_COUNT(sxiw_sis_maximum_installed_space_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_epoc6_reserved_fields[]={
 SX_FIELD("reserved","uint8[16]",0,16,SX_RESERVED),
};
static const sx_layout sxiw_sis_epoc6_reserved={UINT32_C(0x60790027),"sis_epoc6_reserved",sxiw_sis_epoc6_reserved_fields,SX_COUNT(sxiw_sis_epoc6_reserved_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_requisite_fields[]={
 SX_FIELD("uid","uint32le",0,4,SX_ID),
 SX_FIELD("version_major","uint16le",4,2,SX_NONE),
 SX_FIELD("version_minor","uint16le",6,2,SX_NONE),
 SX_FIELD("variant","uint32le",8,4,SX_NONE),
};
static const sx_layout sxiw_sis_requisite={UINT32_C(0x60790028),"sis_requisite",sxiw_sis_requisite_fields,SX_COUNT(sxiw_sis_requisite_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_certificate_header_fields[]={
 SX_FIELD("year","uint16le",0,2,SX_NONE),
 SX_FIELD("month","uint16le",2,2,SX_NONE),
 SX_FIELD("day","uint16le",4,2,SX_NONE),
 SX_FIELD("hour","uint16le",6,2,SX_NONE),
 SX_FIELD("minute","uint16le",8,2,SX_NONE),
 SX_FIELD("second","uint16le",10,2,SX_NONE),
 SX_FIELD("certificate_count","uint32le",12,4,SX_COUNT_PROP),
};
static const sx_layout sxiw_sis_certificate_header={UINT32_C(0x60790029),"sis_certificate_header",sxiw_sis_certificate_header_fields,SX_COUNT(sxiw_sis_certificate_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_language_fields[]={
 SX_FIELD("language_code","uint16le",0,2,SX_ID),
};
static const sx_layout sxiw_sis_language={UINT32_C(0x6079002a),"sis_language",sxiw_sis_language_fields,SX_COUNT(sxiw_sis_language_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_file_record_fields[]={
 SX_FIELD("record_type","uint32le",0,4,SX_ID),
 SX_FIELD("file_type","uint32le",4,4,SX_ID),
 SX_FIELD("details","uint32le",8,4,SX_FLAGS),
 SX_FIELD("source_name_length","uint32le",12,4,SX_SIZE),
 SX_FIELD("source_name_offset","uint32le",16,4,SX_OFFSET),
 SX_FIELD("destination_name_length","uint32le",20,4,SX_SIZE),
 SX_FIELD("destination_name_offset","uint32le",24,4,SX_OFFSET),
};
static const sx_layout sxiw_sis_file_record={UINT32_C(0x6079002b),"sis_file_record",sxiw_sis_file_record_fields,SX_COUNT(sxiw_sis_file_record_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_payload_length_fields[]={
 SX_FIELD("payload_length","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxiw_sis_payload_length={UINT32_C(0x6079002c),"sis_payload_length",sxiw_sis_payload_length_fields,SX_COUNT(sxiw_sis_payload_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_payload_offset_fields[]={
 SX_FIELD("payload_offset","uint32le",0,4,SX_OFFSET),
};
static const sx_layout sxiw_sis_payload_offset={UINT32_C(0x6079002d),"sis_payload_offset",sxiw_sis_payload_offset_fields,SX_COUNT(sxiw_sis_payload_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_uncompressed_length_fields[]={
 SX_FIELD("uncompressed_length","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxiw_sis_uncompressed_length={UINT32_C(0x6079002e),"sis_uncompressed_length",sxiw_sis_uncompressed_length_fields,SX_COUNT(sxiw_sis_uncompressed_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_mime_length_fields[]={
 SX_FIELD("mime_length","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxiw_sis_mime_length={UINT32_C(0x6079002f),"sis_mime_length",sxiw_sis_mime_length_fields,SX_COUNT(sxiw_sis_mime_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_mime_offset_fields[]={
 SX_FIELD("mime_offset","uint32le",0,4,SX_OFFSET),
};
static const sx_layout sxiw_sis_mime_offset={UINT32_C(0x60790030),"sis_mime_offset",sxiw_sis_mime_offset_fields,SX_COUNT(sxiw_sis_mime_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_conditional_fields[]={
 SX_FIELD("record_type","uint32le",0,4,SX_ID),
 SX_FIELD("expression_length","uint32le",4,4,SX_SIZE),
};
static const sx_layout sxiw_sis_conditional={UINT32_C(0x60790031),"sis_conditional",sxiw_sis_conditional_fields,SX_COUNT(sxiw_sis_conditional_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_control_type_fields[]={
 SX_FIELD("record_type","uint32le",0,4,SX_ID),
};
static const sx_layout sxiw_sis_control_type={UINT32_C(0x60790032),"sis_control_type",sxiw_sis_control_type_fields,SX_COUNT(sxiw_sis_control_type_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_field_fields[]={
 SX_FIELD("type","uint32le",0,4,SX_ID),
 SX_FIELD("length","uint32le",4,4,SX_SIZE),
};
static const sx_layout sxiw_sisx_field={UINT32_C(0x60790033),"sisx_field",sxiw_sisx_field_fields,SX_COUNT(sxiw_sisx_field_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_long_field_fields[]={
 SX_FIELD("type","uint32le",0,4,SX_ID),
 SX_FIELD("length_low_with_flag","uint32le",4,4,SX_FLAGS),
 SX_FIELD("length_high","uint32le",8,4,SX_NONE),
};
static const sx_layout sxiw_sisx_long_field={UINT32_C(0x60790034),"sisx_long_field",sxiw_sisx_long_field_fields,SX_COUNT(sxiw_sisx_long_field_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_array_element_fields[]={
 SX_FIELD("element_type","uint32le",0,4,SX_ID),
};
static const sx_layout sxiw_sisx_array_element={UINT32_C(0x60790035),"sisx_array_element",sxiw_sisx_array_element_fields,SX_COUNT(sxiw_sisx_array_element_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_array_length_fields[]={
 SX_FIELD("length","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxiw_sisx_array_length={UINT32_C(0x60790036),"sisx_array_length",sxiw_sisx_array_length_fields,SX_COUNT(sxiw_sisx_array_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_array_long_length_fields[]={
 SX_FIELD("length_low_with_flag","uint32le",0,4,SX_FLAGS),
 SX_FIELD("length_high","uint32le",4,4,SX_NONE),
};
static const sx_layout sxiw_sisx_array_long_length={UINT32_C(0x60790037),"sisx_array_long_length",sxiw_sisx_array_long_length_fields,SX_COUNT(sxiw_sisx_array_long_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_compressed_fields[]={
 SX_FIELD("algorithm","uint32le",0,4,SX_ID),
 SX_FIELD("uncompressed_size","uint64le",4,8,SX_SIZE),
};
static const sx_layout sxiw_sisx_compressed={UINT32_C(0x60790038),"sisx_compressed",sxiw_sisx_compressed_fields,SX_COUNT(sxiw_sisx_compressed_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_aa_header_fields[]={
 SX_FIELD("file_size","uint32be",0,4,SX_SIZE),
 SX_FIELD("magic","uint32be",4,4,SX_SIGNATURE),
 SX_FIELD("toc_count","uint32be",8,4,SX_COUNT_PROP),
 SX_FIELD("unknown","uint32be",12,4,SX_NONE),
};
static const sx_layout sxiw_aa_header={UINT32_C(0x60790039),"aa_header",sxiw_aa_header_fields,SX_COUNT(sxiw_aa_header_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_aa_toc_fields[]={
 SX_FIELD("block_index","uint32be",0,4,SX_ID),
 SX_FIELD("block_offset","uint32be",4,4,SX_OFFSET),
 SX_FIELD("block_size","uint32be",8,4,SX_SIZE),
};
static const sx_layout sxiw_aa_toc={UINT32_C(0x6079003a),"aa_toc",sxiw_aa_toc_fields,SX_COUNT(sxiw_aa_toc_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_aa_dictionary_count_fields[]={
 SX_FIELD("entry_count","uint32be",0,4,SX_COUNT_PROP),
};
static const sx_layout sxiw_aa_dictionary_count={UINT32_C(0x6079003b),"aa_dictionary_count",sxiw_aa_dictionary_count_fields,SX_COUNT(sxiw_aa_dictionary_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_aa_dictionary_entry_fields[]={
 SX_FIELD("unknown","uint8",0,1,SX_NONE),
 SX_FIELD("key_length","uint32be",1,4,SX_SIZE),
 SX_FIELD("value_length","uint32be",5,4,SX_SIZE),
};
static const sx_layout sxiw_aa_dictionary_entry={UINT32_C(0x6079003c),"aa_dictionary_entry",sxiw_aa_dictionary_entry_fields,SX_COUNT(sxiw_aa_dictionary_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_aa_dictionary_key_fields[]={
 SX_FIELD("aa_dictionary_key","utf8",0,0,SX_STRING),
};
static const sx_layout sxiw_aa_dictionary_key={UINT32_C(0x6079003d),"aa_dictionary_key",sxiw_aa_dictionary_key_fields,SX_COUNT(sxiw_aa_dictionary_key_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_aa_dictionary_value_fields[]={
 SX_FIELD("aa_dictionary_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxiw_aa_dictionary_value={UINT32_C(0x6079003e),"aa_dictionary_value",sxiw_aa_dictionary_value_fields,SX_COUNT(sxiw_aa_dictionary_value_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_object_fields[]={
 SX_FIELD("object_guid","uint8[16]",0,16,SX_ID),
 SX_FIELD("object_size","uint64le",16,8,SX_SIZE),
};
static const sx_layout sxiw_asf_object={UINT32_C(0x6079003f),"asf_object",sxiw_asf_object_fields,SX_COUNT(sxiw_asf_object_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_header_fields[]={
 SX_FIELD("object_guid","uint8[16]",0,16,SX_SIGNATURE),
 SX_FIELD("object_size","uint64le",16,8,SX_SIZE),
 SX_FIELD("header_object_count","uint32le",24,4,SX_COUNT_PROP),
 SX_FIELD("reserved1","uint8",28,1,SX_RESERVED),
 SX_FIELD("reserved2","uint8",29,1,SX_RESERVED),
};
static const sx_layout sxiw_asf_header={UINT32_C(0x60790040),"asf_header",sxiw_asf_header_fields,SX_COUNT(sxiw_asf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_file_properties_fields[]={
 SX_FIELD("file_id","uint8[16]",0,16,SX_ID),
 SX_FIELD("file_size","uint64le",16,8,SX_SIZE),
 SX_FIELD("creation_filetime","uint64le",24,8,SX_NONE),
 SX_FIELD("data_packet_count","uint64le",32,8,SX_COUNT_PROP),
 SX_FIELD("play_duration_100ns","uint64le",40,8,SX_NONE),
 SX_FIELD("send_duration_100ns","uint64le",48,8,SX_NONE),
 SX_FIELD("preroll_ms","uint64le",56,8,SX_NONE),
 SX_FIELD("flags","uint32le",64,4,SX_FLAGS),
 SX_FIELD("minimum_packet_size","uint32le",68,4,SX_SIZE),
 SX_FIELD("maximum_packet_size","uint32le",72,4,SX_SIZE),
 SX_FIELD("maximum_bitrate","uint32le",76,4,SX_NONE),
};
static const sx_layout sxiw_asf_file_properties={UINT32_C(0x60790041),"asf_file_properties",sxiw_asf_file_properties_fields,SX_COUNT(sxiw_asf_file_properties_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_stream_properties_fields[]={
 SX_FIELD("stream_type_guid","uint8[16]",0,16,SX_ID),
 SX_FIELD("error_correction_guid","uint8[16]",16,16,SX_ID),
 SX_FIELD("time_shift_100ns","uint64le",32,8,SX_NONE),
 SX_FIELD("type_specific_size","uint32le",40,4,SX_SIZE),
 SX_FIELD("error_correction_size","uint32le",44,4,SX_SIZE),
 SX_FIELD("stream_flags","uint16le",48,2,SX_FLAGS),
 SX_FIELD("reserved","uint32le",50,4,SX_RESERVED),
};
static const sx_layout sxiw_asf_stream_properties={UINT32_C(0x60790042),"asf_stream_properties",sxiw_asf_stream_properties_fields,SX_COUNT(sxiw_asf_stream_properties_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_header_extension_fields[]={
 SX_FIELD("reserved_guid","uint8[16]",0,16,SX_RESERVED),
 SX_FIELD("reserved_word","uint16le",16,2,SX_RESERVED),
 SX_FIELD("extension_data_size","uint32le",18,4,SX_SIZE),
};
static const sx_layout sxiw_asf_header_extension={UINT32_C(0x60790043),"asf_header_extension",sxiw_asf_header_extension_fields,SX_COUNT(sxiw_asf_header_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_data_header_fields[]={
 SX_FIELD("file_id","uint8[16]",0,16,SX_ID),
 SX_FIELD("data_packet_count","uint64le",16,8,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16le",24,2,SX_RESERVED),
};
static const sx_layout sxiw_asf_data_header={UINT32_C(0x60790044),"asf_data_header",sxiw_asf_data_header_fields,SX_COUNT(sxiw_asf_data_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_content_lengths_fields[]={
 SX_FIELD("title_length","uint16le",0,2,SX_SIZE),
 SX_FIELD("author_length","uint16le",2,2,SX_SIZE),
 SX_FIELD("copyright_length","uint16le",4,2,SX_SIZE),
 SX_FIELD("description_length","uint16le",6,2,SX_SIZE),
 SX_FIELD("rating_length","uint16le",8,2,SX_SIZE),
};
static const sx_layout sxiw_asf_content_lengths={UINT32_C(0x60790045),"asf_content_lengths",sxiw_asf_content_lengths_fields,SX_COUNT(sxiw_asf_content_lengths_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_descriptor_count_fields[]={
 SX_FIELD("descriptor_count","uint16le",0,2,SX_COUNT_PROP),
};
static const sx_layout sxiw_asf_descriptor_count={UINT32_C(0x60790046),"asf_descriptor_count",sxiw_asf_descriptor_count_fields,SX_COUNT(sxiw_asf_descriptor_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_name_length_fields[]={
 SX_FIELD("name_length","uint16le",0,2,SX_SIZE),
};
static const sx_layout sxiw_asf_name_length={UINT32_C(0x60790047),"asf_name_length",sxiw_asf_name_length_fields,SX_COUNT(sxiw_asf_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_value_header_fields[]={
 SX_FIELD("data_type","uint16le",0,2,SX_ID),
 SX_FIELD("value_length","uint16le",2,2,SX_SIZE),
};
static const sx_layout sxiw_asf_value_header={UINT32_C(0x60790048),"asf_value_header",sxiw_asf_value_header_fields,SX_COUNT(sxiw_asf_value_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_metadata_header_fields[]={
 SX_FIELD("language_index","uint16le",0,2,SX_NONE),
 SX_FIELD("stream_number","uint16le",2,2,SX_ID),
 SX_FIELD("name_length","uint16le",4,2,SX_SIZE),
 SX_FIELD("data_type","uint16le",6,2,SX_ID),
 SX_FIELD("value_length","uint32le",8,4,SX_SIZE),
};
static const sx_layout sxiw_asf_metadata_header={UINT32_C(0x60790049),"asf_metadata_header",sxiw_asf_metadata_header_fields,SX_COUNT(sxiw_asf_metadata_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_bitrate_fields[]={
 SX_FIELD("stream_flags","uint16le",0,2,SX_FLAGS),
 SX_FIELD("average_bitrate","uint32le",2,4,SX_NONE),
};
static const sx_layout sxiw_asf_bitrate={UINT32_C(0x6079004a),"asf_bitrate",sxiw_asf_bitrate_fields,SX_COUNT(sxiw_asf_bitrate_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_language_length_fields[]={
 SX_FIELD("language_id_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxiw_asf_language_length={UINT32_C(0x6079004b),"asf_language_length",sxiw_asf_language_length_fields,SX_COUNT(sxiw_asf_language_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_utf16_units_fields[]={
 SX_FIELD("asf_utf16_units","uint16",0,0,SX_NONE),
};
static const sx_layout sxiw_asf_utf16_units={UINT32_C(0x6079004c),"asf_utf16_units",sxiw_asf_utf16_units_fields,SX_COUNT(sxiw_asf_utf16_units_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_binary_value_fields[]={
 SX_FIELD("asf_binary_value","uint8",0,0,SX_NONE),
};
static const sx_layout sxiw_asf_binary_value={UINT32_C(0x6079004d),"asf_binary_value",sxiw_asf_binary_value_fields,SX_COUNT(sxiw_asf_binary_value_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_modified_utf8_fields[]={
 SX_FIELD("java_modified_utf8","uint8",0,0,SX_NONE),
};
static const sx_layout sxiw_java_modified_utf8={UINT32_C(0x6079004e),"java_modified_utf8",sxiw_java_modified_utf8_fields,SX_COUNT(sxiw_java_modified_utf8_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_latin1_fields[]={
 SX_FIELD("sis_latin1","uint8",0,0,SX_NONE),
};
static const sx_layout sxiw_sis_latin1={UINT32_C(0x6079004f),"sis_latin1",sxiw_sis_latin1_fields,SX_COUNT(sxiw_sis_latin1_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_utf16_fields[]={
 SX_FIELD("sis_utf16","uint16",0,0,SX_NONE),
};
static const sx_layout sxiw_sis_utf16={UINT32_C(0x60790050),"sis_utf16",sxiw_sis_utf16_fields,SX_COUNT(sxiw_sis_utf16_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_capability_fields[]={
 SX_FIELD("capability_key","uint32le",0,4,SX_ID),
 SX_FIELD("capability_value","uint32le",4,4,SX_NONE),
};
static const sx_layout sxiw_sis_capability={UINT32_C(0x60790051),"sis_capability",sxiw_sis_capability_fields,SX_COUNT(sxiw_sis_capability_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_checksum_fields[]={
 SX_FIELD("crc16","uint16le",0,2,SX_CHECKSUM),
};
static const sx_layout sxiw_sisx_checksum={UINT32_C(0x60790052),"sisx_checksum",sxiw_sisx_checksum_fields,SX_COUNT(sxiw_sisx_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sisx_data_index_fields[]={
 SX_FIELD("data_index","uint32le",0,4,SX_NONE),
};
static const sx_layout sxiw_sisx_data_index={UINT32_C(0x60790053),"sisx_data_index",sxiw_sisx_data_index_fields,SX_COUNT(sxiw_sisx_data_index_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_arcadyan_lzma_fragments_fields[]={
 SX_FIELD("encoded_dictionary_byte_0","uint8",0,1,SX_NONE),
 SX_FIELD("encoded_properties","uint8",1,1,SX_NONE),
 SX_FIELD("encoded_dictionary_byte_2","uint8",2,1,SX_NONE),
 SX_FIELD("encoded_dictionary_byte_1","uint8",3,1,SX_NONE),
 SX_FIELD("encoded_size_byte_0","uint8",4,1,SX_NONE),
 SX_FIELD("encoded_dictionary_byte_3","uint8",5,1,SX_NONE),
 SX_FIELD("encoded_size_byte_2","uint8",6,1,SX_NONE),
 SX_FIELD("encoded_size_byte_1","uint8",7,1,SX_NONE),
 SX_FIELD("encoded_size_byte_4","uint8",8,1,SX_NONE),
 SX_FIELD("encoded_size_byte_3","uint8",9,1,SX_NONE),
 SX_FIELD("encoded_size_byte_6","uint8",10,1,SX_NONE),
 SX_FIELD("encoded_size_byte_5","uint8",11,1,SX_NONE),
 SX_FIELD("encoded_range_coder_zero","uint8",12,1,SX_NONE),
 SX_FIELD("encoded_size_byte_7","uint8",13,1,SX_NONE),
};
static const sx_layout sxiw_arcadyan_lzma_fragments={UINT32_C(0x60790054),"arcadyan_lzma_fragments",sxiw_arcadyan_lzma_fragments_fields,SX_COUNT(sxiw_arcadyan_lzma_fragments_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_local_fields[]={
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version_needed","uint16le",4,2,SX_NONE),
 SX_FIELD("flags","uint16le",6,2,SX_FLAGS),
 SX_FIELD("method","uint16le",8,2,SX_ID),
 SX_FIELD("dos_time","uint16le",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16le",12,2,SX_NONE),
 SX_FIELD("crc32","uint32le",14,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32le",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32le",22,4,SX_SIZE),
 SX_FIELD("name_length","uint16le",26,2,SX_SIZE),
 SX_FIELD("extra_length","uint16le",28,2,SX_SIZE),
};
static const sx_layout sxiw_installer_zip_local={UINT32_C(0x60790055),"installer_zip_local",sxiw_installer_zip_local_fields,SX_COUNT(sxiw_installer_zip_local_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_central_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
 SX_FIELD("version_made_by","uint16le",4,2,SX_NONE),
 SX_FIELD("version_needed","uint16le",6,2,SX_NONE),
 SX_FIELD("flags","uint16le",8,2,SX_FLAGS),
 SX_FIELD("method","uint16le",10,2,SX_ID),
 SX_FIELD("dos_time","uint16le",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16le",14,2,SX_NONE),
 SX_FIELD("crc32","uint32le",16,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32le",20,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32le",24,4,SX_SIZE),
 SX_FIELD("name_length","uint16le",28,2,SX_SIZE),
 SX_FIELD("extra_length","uint16le",30,2,SX_SIZE),
 SX_FIELD("comment_length","uint16le",32,2,SX_SIZE),
 SX_FIELD("disk_start","uint16le",34,2,SX_NONE),
 SX_FIELD("internal_attributes","uint16le",36,2,SX_FLAGS),
 SX_FIELD("external_attributes","uint32le",38,4,SX_FLAGS),
 SX_FIELD("local_header_offset","uint32le",42,4,SX_OFFSET),
};
static const sx_layout sxiw_installer_zip_central={UINT32_C(0x60790056),"installer_zip_central",sxiw_installer_zip_central_fields,SX_COUNT(sxiw_installer_zip_central_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_eocd_fields[]={
 SX_FIELD("signature","uint32le",0,4,SX_SIGNATURE),
 SX_FIELD("disk_number","uint16le",4,2,SX_NONE),
 SX_FIELD("directory_disk","uint16le",6,2,SX_NONE),
 SX_FIELD("disk_entries","uint16le",8,2,SX_COUNT_PROP),
 SX_FIELD("total_entries","uint16le",10,2,SX_COUNT_PROP),
 SX_FIELD("directory_size","uint32le",12,4,SX_SIZE),
 SX_FIELD("directory_offset","uint32le",16,4,SX_OFFSET),
 SX_FIELD("comment_length","uint16le",20,2,SX_SIZE),
};
static const sx_layout sxiw_installer_zip_eocd={UINT32_C(0x60790057),"installer_zip_eocd",sxiw_installer_zip_eocd_fields,SX_COUNT(sxiw_installer_zip_eocd_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_extra_fields[]={
 SX_FIELD("tag","uint16le",0,2,SX_ID),
 SX_FIELD("data_size","uint16le",2,2,SX_SIZE),
};
static const sx_layout sxiw_installer_zip_extra={UINT32_C(0x60790058),"installer_zip_extra",sxiw_installer_zip_extra_fields,SX_COUNT(sxiw_installer_zip_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_name_fields[]={
 SX_FIELD("installer_zip_name","uint8",0,0,SX_NONE),
};
static const sx_layout sxiw_installer_zip_name={UINT32_C(0x60790059),"installer_zip_name",sxiw_installer_zip_name_fields,SX_COUNT(sxiw_installer_zip_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_installer_zip_comment_fields[]={
 SX_FIELD("installer_zip_comment","uint8",0,0,SX_NONE),
};
static const sx_layout sxiw_installer_zip_comment={UINT32_C(0x6079005a),"installer_zip_comment",sxiw_installer_zip_comment_fields,SX_COUNT(sxiw_installer_zip_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_newc_fields[]={
 SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("inode","ascii_cpio_hex[8]",6,8,SX_ID),
 SX_FIELD("mode","ascii_cpio_hex[8]",14,8,SX_FLAGS),
 SX_FIELD("uid","ascii_cpio_hex[8]",22,8,SX_NONE),
 SX_FIELD("gid","ascii_cpio_hex[8]",30,8,SX_NONE),
 SX_FIELD("link_count","ascii_cpio_hex[8]",38,8,SX_COUNT_PROP),
 SX_FIELD("modification_time","ascii_cpio_hex[8]",46,8,SX_TIME),
 SX_FIELD("file_size","ascii_cpio_hex[8]",54,8,SX_SIZE),
 SX_FIELD("device_major","ascii_cpio_hex[8]",62,8,SX_NONE),
 SX_FIELD("device_minor","ascii_cpio_hex[8]",70,8,SX_NONE),
 SX_FIELD("rdevice_major","ascii_cpio_hex[8]",78,8,SX_NONE),
 SX_FIELD("rdevice_minor","ascii_cpio_hex[8]",86,8,SX_NONE),
 SX_FIELD("name_size","ascii_cpio_hex[8]",94,8,SX_SIZE),
 SX_FIELD("checksum","ascii_cpio_hex[8]",102,8,SX_CHECKSUM),
};
static const sx_layout sxiw_solaris_cpio_newc={UINT32_C(0x6079005b),"solaris_cpio_newc",sxiw_solaris_cpio_newc_fields,SX_COUNT(sxiw_solaris_cpio_newc_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_odc_fields[]={
 SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("device","ascii_cpio_octal[6]",6,6,SX_NONE),
 SX_FIELD("inode","ascii_cpio_octal[6]",12,6,SX_ID),
 SX_FIELD("mode","ascii_cpio_octal[6]",18,6,SX_FLAGS),
 SX_FIELD("uid","ascii_cpio_octal[6]",24,6,SX_NONE),
 SX_FIELD("gid","ascii_cpio_octal[6]",30,6,SX_NONE),
 SX_FIELD("link_count","ascii_cpio_octal[6]",36,6,SX_COUNT_PROP),
 SX_FIELD("rdevice","ascii_cpio_octal[6]",42,6,SX_NONE),
 SX_FIELD("modification_time","ascii_cpio_octal[11]",48,11,SX_TIME),
 SX_FIELD("name_size","ascii_cpio_octal[6]",59,6,SX_SIZE),
 SX_FIELD("file_size","ascii_cpio_octal[11]",65,11,SX_SIZE),
};
static const sx_layout sxiw_solaris_cpio_odc={UINT32_C(0x6079005c),"solaris_cpio_odc",sxiw_solaris_cpio_odc_fields,SX_COUNT(sxiw_solaris_cpio_odc_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_binary_le_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("device","uint16",2,2,SX_NONE),
 SX_FIELD("inode","uint16",4,2,SX_ID),
 SX_FIELD("mode","uint16",6,2,SX_FLAGS),
 SX_FIELD("uid","uint16",8,2,SX_NONE),
 SX_FIELD("gid","uint16",10,2,SX_NONE),
 SX_FIELD("link_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("rdevice","uint16",14,2,SX_NONE),
 SX_FIELD("mtime_high","uint16",16,2,SX_NONE),
 SX_FIELD("mtime_low","uint16",18,2,SX_NONE),
 SX_FIELD("name_size","uint16",20,2,SX_SIZE),
 SX_FIELD("file_size_high","uint16",22,2,SX_NONE),
 SX_FIELD("file_size_low","uint16",24,2,SX_NONE),
};
static const sx_layout sxiw_solaris_cpio_binary_le={UINT32_C(0x6079005d),"solaris_cpio_binary_le",sxiw_solaris_cpio_binary_le_fields,SX_COUNT(sxiw_solaris_cpio_binary_le_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_binary_be_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("device","uint16",2,2,SX_NONE),
 SX_FIELD("inode","uint16",4,2,SX_ID),
 SX_FIELD("mode","uint16",6,2,SX_FLAGS),
 SX_FIELD("uid","uint16",8,2,SX_NONE),
 SX_FIELD("gid","uint16",10,2,SX_NONE),
 SX_FIELD("link_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("rdevice","uint16",14,2,SX_NONE),
 SX_FIELD("mtime_high","uint16",16,2,SX_NONE),
 SX_FIELD("mtime_low","uint16",18,2,SX_NONE),
 SX_FIELD("name_size","uint16",20,2,SX_SIZE),
 SX_FIELD("file_size_high","uint16",22,2,SX_NONE),
 SX_FIELD("file_size_low","uint16",24,2,SX_NONE),
};
static const sx_layout sxiw_solaris_cpio_binary_be={UINT32_C(0x6079005e),"solaris_cpio_binary_be",sxiw_solaris_cpio_binary_be_fields,SX_COUNT(sxiw_solaris_cpio_binary_be_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_solaris_cpio_name_fields[]={
 SX_FIELD("solaris_cpio_name","uint8",0,0,SX_NONE),
};
static const sx_layout sxiw_solaris_cpio_name={UINT32_C(0x6079005f),"solaris_cpio_name",sxiw_solaris_cpio_name_fields,SX_COUNT(sxiw_solaris_cpio_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_aa_chapter_fields[]={
 SX_FIELD("chapter_size","uint32be",0,4,SX_SIZE),
 SX_FIELD("unknown","uint32be",4,4,SX_NONE),
};
static const sx_layout sxiw_aa_chapter={UINT32_C(0x60790060),"aa_chapter",sxiw_aa_chapter_fields,SX_COUNT(sxiw_aa_chapter_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_asf_simple_index_fields[]={
 SX_FIELD("file_id","uint8[16]",0,16,SX_ID),
 SX_FIELD("interval_100ns","uint64le",16,8,SX_NONE),
 SX_FIELD("maximum_packet_count","uint32le",24,4,SX_COUNT_PROP),
 SX_FIELD("entry_count","uint32le",28,4,SX_COUNT_PROP),
};
static const sx_layout sxiw_asf_simple_index={UINT32_C(0x60790061),"asf_simple_index",sxiw_asf_simple_index_fields,SX_COUNT(sxiw_asf_simple_index_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_index_entry_fields[]={
 SX_FIELD("packet_number","uint32le",0,4,SX_NONE),
 SX_FIELD("packet_count","uint16le",4,2,SX_COUNT_PROP),
};
static const sx_layout sxiw_asf_index_entry={UINT32_C(0x60790062),"asf_index_entry",sxiw_asf_index_entry_fields,SX_COUNT(sxiw_asf_index_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_value_word_fields[]={
 SX_FIELD("word","uint16le",0,2,SX_NONE),
};
static const sx_layout sxiw_asf_value_word={UINT32_C(0x60790063),"asf_value_word",sxiw_asf_value_word_fields,SX_COUNT(sxiw_asf_value_word_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_value_dword_fields[]={
 SX_FIELD("dword","uint32le",0,4,SX_NONE),
};
static const sx_layout sxiw_asf_value_dword={UINT32_C(0x60790064),"asf_value_dword",sxiw_asf_value_dword_fields,SX_COUNT(sxiw_asf_value_dword_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_value_qword_fields[]={
 SX_FIELD("qword","uint64le",0,8,SX_NONE),
};
static const sx_layout sxiw_asf_value_qword={UINT32_C(0x60790065),"asf_value_qword",sxiw_asf_value_qword_fields,SX_COUNT(sxiw_asf_value_qword_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_asf_value_boolean_fields[]={
 SX_FIELD("boolean","uint32le",0,4,SX_NONE),
};
static const sx_layout sxiw_asf_value_boolean={UINT32_C(0x60790066),"asf_value_boolean",sxiw_asf_value_boolean_fields,SX_COUNT(sxiw_asf_value_boolean_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_izpack_record_v1_fields[]={
 SX_FIELD("length","int64be",0,8,SX_SIZE),
};
static const sx_layout sxiw_izpack_record_v1={UINT32_C(0x60790067),"izpack_record_v1",sxiw_izpack_record_v1_fields,SX_COUNT(sxiw_izpack_record_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v2_fields[]={
 SX_FIELD("length","int64be",0,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",8,8,SX_NONE),
 SX_FIELD("override_or_previous_pack_number","int32be",16,4,SX_NONE),
};
static const sx_layout sxiw_izpack_record_v2={UINT32_C(0x60790068),"izpack_record_v2",sxiw_izpack_record_v2_fields,SX_COUNT(sxiw_izpack_record_v2_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v3_fields[]={
 SX_FIELD("length","int64be",0,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",8,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",16,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",24,4,SX_NONE),
 SX_FIELD("previous_pack_number","int32be",28,4,SX_NONE),
};
static const sx_layout sxiw_izpack_record_v3={UINT32_C(0x60790069),"izpack_record_v3",sxiw_izpack_record_v3_fields,SX_COUNT(sxiw_izpack_record_v3_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v4_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("length","int64be",1,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",9,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",17,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",25,4,SX_NONE),
 SX_FIELD("previous_pack_number","int32be",29,4,SX_NONE),
};
static const sx_layout sxiw_izpack_record_v4={UINT32_C(0x6079006a),"izpack_record_v4",sxiw_izpack_record_v4_fields,SX_COUNT(sxiw_izpack_record_v4_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v5_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("length","int64be",1,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",9,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",17,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",25,4,SX_NONE),
 SX_FIELD("previous_pack_number","int32be",29,4,SX_NONE),
};
static const sx_layout sxiw_izpack_record_v5={UINT32_C(0x6079006b),"izpack_record_v5",sxiw_izpack_record_v5_fields,SX_COUNT(sxiw_izpack_record_v5_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v6_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("length","int64be",1,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",9,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",17,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",25,4,SX_NONE),
};
static const sx_layout sxiw_izpack_record_v6={UINT32_C(0x6079006c),"izpack_record_v6",sxiw_izpack_record_v6_fields,SX_COUNT(sxiw_izpack_record_v6_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v7_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("length","int64be",1,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",9,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",17,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",25,4,SX_NONE),
 SX_FIELD("pack200","uint8",29,1,SX_FLAGS),
};
static const sx_layout sxiw_izpack_record_v7={UINT32_C(0x6079006d),"izpack_record_v7",sxiw_izpack_record_v7_fields,SX_COUNT(sxiw_izpack_record_v7_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_sis_localized_name_length_fields[]={
 SX_FIELD("name_length","uint32le",0,4,SX_SIZE),
};
static const sx_layout sxiw_sis_localized_name_length={UINT32_C(0x6079006e),"sis_localized_name_length",sxiw_sis_localized_name_length_fields,SX_COUNT(sxiw_sis_localized_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_sis_localized_name_offset_fields[]={
 SX_FIELD("name_offset","uint32le",0,4,SX_OFFSET),
};
static const sx_layout sxiw_sis_localized_name_offset={UINT32_C(0x6079006f),"sis_localized_name_offset",sxiw_sis_localized_name_offset_fields,SX_COUNT(sxiw_sis_localized_name_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_shell_block_count_fields[]={
 SX_FIELD("shell_block_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxiw_shell_block_count={UINT32_C(0x60790070),"shell_block_count",sxiw_shell_block_count_fields,SX_COUNT(sxiw_shell_block_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_izpack_list_count_fields[]={
 SX_FIELD("element_count","int32be",0,4,SX_COUNT_PROP),
};
static const sx_layout sxiw_izpack_list_count={UINT32_C(0x60790071),"izpack_list_count",sxiw_izpack_list_count_fields,SX_COUNT(sxiw_izpack_list_count_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_shell_start_line_fields[]={
 SX_FIELD("shell_start_line","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxiw_shell_start_line={UINT32_C(0x60790072),"shell_start_line",sxiw_shell_start_line_fields,SX_COUNT(sxiw_shell_start_line_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_shell_skip_parameter_fields[]={
 SX_FIELD("shell_skip_parameter","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxiw_shell_skip_parameter={UINT32_C(0x60790073),"shell_skip_parameter",sxiw_shell_skip_parameter_fields,SX_COUNT(sxiw_shell_skip_parameter_fields),SX_LE};
static const sx_layout *const sx_installerwire_layouts[]={
 &sxiw_is7inx_header,
 &sxiw_izpack_stream_header,
 &sxiw_java_object_tag,
 &sxiw_java_class_tag,
 &sxiw_java_utf_length,
 &sxiw_java_class_metadata,
 &sxiw_java_field_type,
 &sxiw_java_reference,
 &sxiw_java_string,
 &sxiw_java_long_string,
 &sxiw_java_block,
 &sxiw_java_long_block,
 &sxiw_java_boolean,
 &sxiw_java_byte,
 &sxiw_java_char,
 &sxiw_java_short,
 &sxiw_java_int,
 &sxiw_java_long,
 &sxiw_java_float,
 &sxiw_java_double,
 &sxiw_shell_interpreter,
 &sxiw_shell_assignment_name,
 &sxiw_shell_assignment_value,
 &sxiw_shell_line_count,
 &sxiw_shell_block_index,
 &sxiw_shell_payload_size,
 &sxiw_shell_block_size,
 &sxiw_solaris_package_name,
 &sxiw_solaris_part_count,
 &sxiw_solaris_block_count,
 &sxiw_solaris_banner,
 &sxiw_solaris_end_header,
 &sxiw_opc_banner,
 &sxiw_sis_uids,
 &sxiw_sis_epoc_header,
 &sxiw_sis_epoc6_extension,
 &sxiw_sis_installed_space,
 &sxiw_sis_maximum_installed_space,
 &sxiw_sis_epoc6_reserved,
 &sxiw_sis_requisite,
 &sxiw_sis_certificate_header,
 &sxiw_sis_language,
 &sxiw_sis_file_record,
 &sxiw_sis_payload_length,
 &sxiw_sis_payload_offset,
 &sxiw_sis_uncompressed_length,
 &sxiw_sis_mime_length,
 &sxiw_sis_mime_offset,
 &sxiw_sis_conditional,
 &sxiw_sis_control_type,
 &sxiw_sisx_field,
 &sxiw_sisx_long_field,
 &sxiw_sisx_array_element,
 &sxiw_sisx_array_length,
 &sxiw_sisx_array_long_length,
 &sxiw_sisx_compressed,
 &sxiw_aa_header,
 &sxiw_aa_toc,
 &sxiw_aa_dictionary_count,
 &sxiw_aa_dictionary_entry,
 &sxiw_aa_dictionary_key,
 &sxiw_aa_dictionary_value,
 &sxiw_asf_object,
 &sxiw_asf_header,
 &sxiw_asf_file_properties,
 &sxiw_asf_stream_properties,
 &sxiw_asf_header_extension,
 &sxiw_asf_data_header,
 &sxiw_asf_content_lengths,
 &sxiw_asf_descriptor_count,
 &sxiw_asf_name_length,
 &sxiw_asf_value_header,
 &sxiw_asf_metadata_header,
 &sxiw_asf_bitrate,
 &sxiw_asf_language_length,
 &sxiw_asf_utf16_units,
 &sxiw_asf_binary_value,
 &sxiw_java_modified_utf8,
 &sxiw_sis_latin1,
 &sxiw_sis_utf16,
 &sxiw_sis_capability,
 &sxiw_sisx_checksum,
 &sxiw_sisx_data_index,
 &sxiw_arcadyan_lzma_fragments,
 &sxiw_installer_zip_local,
 &sxiw_installer_zip_central,
 &sxiw_installer_zip_eocd,
 &sxiw_installer_zip_extra,
 &sxiw_installer_zip_name,
 &sxiw_installer_zip_comment,
 &sxiw_solaris_cpio_newc,
 &sxiw_solaris_cpio_odc,
 &sxiw_solaris_cpio_binary_le,
 &sxiw_solaris_cpio_binary_be,
 &sxiw_solaris_cpio_name,
 &sxiw_aa_chapter,
 &sxiw_asf_simple_index,
 &sxiw_asf_index_entry,
 &sxiw_asf_value_word,
 &sxiw_asf_value_dword,
 &sxiw_asf_value_qword,
 &sxiw_asf_value_boolean,
 &sxiw_izpack_record_v1,
 &sxiw_izpack_record_v2,
 &sxiw_izpack_record_v3,
 &sxiw_izpack_record_v4,
 &sxiw_izpack_record_v5,
 &sxiw_izpack_record_v6,
 &sxiw_izpack_record_v7,
 &sxiw_sis_localized_name_length,
 &sxiw_sis_localized_name_offset,
 &sxiw_shell_block_count,
 &sxiw_izpack_list_count,
 &sxiw_shell_start_line,
 &sxiw_shell_skip_parameter,
};
static bool sx_installerwire_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60790000U||id>=0x607a0000U)return true;const wchar_t*text=NULL;switch(id){
 case 0x60790001U:text=L"The stored bytes are position-obfuscated. These arrays preserve ciphertext spans; decoded positions are not source bytes.";break;
 case 0x60790005U:text=L"Java strings use modified UTF8, which differs from ordinary UTF8 for NUL and supplementary characters.";break;
 case 0x60790008U:text=L"Serialization handle, not a physical file offset.";break;
 case 0x60790021U:text=L"The following ZIP bytes are stored with an additive transform of0x67. The banner itself is plain.";break;
 case 0x60790034U:text=L"Length is low31 bits plus high shifted left31; the high flag in the low word selects this encoding.";break;
 case 0x60790042U:text=L"Stream flags include7-bit stream number and encrypted-content bit15; time shift is temporal, not a file position.";break;
 case 0x6079004cU:text=L"Original little-endian UTF16 code units, including any trailing NUL. Supplementary characters occupy a surrogate pair.";break;
 case 0x6079004dU:text=L"Stored metadata bytes. No interpretation is assigned to unsupported value types.";break;
 case 0x6079004eU:text=L"Encoded Java modified-UTF8 bytes, including its special NUL and surrogate encodings; not ordinary UTF8.";break;
 case 0x6079004fU:text=L"Physical Latin1 bytes; strings are length-delimited, not NUL-terminated.";break;
 case 0x60790050U:text=L"Physical little-endian UTF16 code units; strings are length-delimited.";break;
 case 0x60790052U:text=L"CRC16 checksum, not format magic.";break;
 case 0x60790054U:text=L"Stored at file offset0x68. Each stored byte has swapped nibbles; adjacent bytes are swapped. Indexed fragments refer to the little-endian LZMA-alone dictionary and size words. UINT64_MAX decoded size means unknown.";break;
 case 0x60790055U:text=L"Dahua replaces the first local signature PK with DH; all remaining fields retain ZIP wire encoding. CRC32 is a checksum; DOS date/time are packed words.";break;
 case 0x60790059U:text=L"ZIP name bytes; character encoding depends on flags and Unicode extra fields.";break;
 case 0x6079005aU:text=L"ZIP comment bytes; no unconditional character encoding is assumed.";break;
 case 0x6079005dU:text=L"Split size/time words are encoded high/low16 bits, not independent byte quantities.";break;
 case 0x6079005eU:text=L"Split size/time words are encoded high/low16 bits, not independent byte quantities.";break;
 case 0x6079005fU:text=L"Physical pathname bytes, including the trailing NUL.";break;
 case 0x60790067U:text=L"mtime is Java milliseconds since Unix epoch. Offset in previous pack belongs to another physical pack; -1 means this pack. Version-dependent int field naming is retained as a union where the native reader does not distinguish it.";break;
 case 0x60790068U:text=L"mtime is Java milliseconds since Unix epoch. Offset in previous pack belongs to another physical pack; -1 means this pack. Version-dependent int field naming is retained as a union where the native reader does not distinguish it.";break;
 case 0x60790069U:text=L"mtime is Java milliseconds since Unix epoch. Offset in previous pack belongs to another physical pack; -1 means this pack. Version-dependent int field naming is retained as a union where the native reader does not distinguish it.";break;
 case 0x6079006aU:text=L"mtime is Java milliseconds since Unix epoch. Offset in previous pack belongs to another physical pack; -1 means this pack. Version-dependent int field naming is retained as a union where the native reader does not distinguish it.";break;
 case 0x6079006bU:text=L"mtime is Java milliseconds since Unix epoch. Offset in previous pack belongs to another physical pack; -1 means this pack. Version-dependent int field naming is retained as a union where the native reader does not distinguish it.";break;
 case 0x6079006cU:text=L"mtime is Java milliseconds since Unix epoch. Offset in previous pack belongs to another physical pack; -1 means this pack. Version-dependent int field naming is retained as a union where the native reader does not distinguish it.";break;
 case 0x6079006dU:text=L"mtime is Java milliseconds since Unix epoch. Offset in previous pack belongs to another physical pack; -1 means this pack. Version-dependent int field naming is retained as a union where the native reader does not distinguish it.";break;
 case 0x60790070U:text=L"Count of BLOCKSIZE-sized units, not bytes.";break;
 case 0x60790071U:text=L"ArrayList serialized element count.";break;
 case 0x60790072U:text=L"One-based starting line number for tail +N; not a count of lines.";break;
 case 0x60790073U:text=L"Makeself1.x skip parameter: one-based starting line for tail +$skip. Native modern filesizes branches instead interpret skip as a count.";break;
 default:break;}
 if(!xx_rt_wcscmp(r->name,L"creation_filetime"))text=L"FILETIME ticks of100 nanoseconds since1601-01-01 UTC, not Unix seconds.";
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXIW_LIMIT 20000U
static bool sxiw_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxiw_read(sx_context*c,uint64_t p,void*b,size_t n){return sxiw_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxiw_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxiw_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxiw_read(c,p,b,n))return false;*v=sxiw_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxiw_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXIW_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxiw_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxiw_add(sx_context*c,const sx_layout*l,uint64_t p){return sxiw_put(c,l,p,0,false);}
static bool sxiw_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxiw_put(c,l,p,n,aliases);}
static int sxiw_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxiw_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxiw_order);return !c->failed;}
static bool sxiw_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxiw_add(c,l,p+i*width))return false;return true;}
static bool sxiw_emit(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l){uint64_t n=(uint64_t)(l->fields[l->field_count-1].rel_offset+l->fields[l->field_count-1].size);if(*p>end||n>end-*p||!sxiw_add(c,l,*p))return false;*p+=n;return true;}
static bool sxiw_ascii(sx_context*c,uint64_t p,unsigned n,unsigned radix,uint64_t*v){uint8_t b[24];if(n>sizeof(b)||!sxiw_read(c,p,b,n))return false;*v=0;bool any=false;unsigned i=0;while(i<n&&(b[i]==' '||!b[i]))i++;for(;i<n;i++){unsigned d;if(b[i]==' '||!b[i]){for(;i<n;i++)if(b[i]&&b[i]!=' ')return false;break;}if(b[i]>='0'&&b[i]<='9')d=b[i]-'0';else if(b[i]>='a'&&b[i]<='f')d=b[i]-'a'+10;else if(b[i]>='A'&&b[i]<='F')d=b[i]-'A'+10;else return false;if(d>=radix||*v>(UINT64_MAX-d)/radix)return false;*v=*v*radix+d;any=true;}(void)any;return true;}

static bool sxiw_aa(sx_context*c){
 uint64_t n,p=16,end=(uint64_t)c->size,largest=0,lsize=0;
 if(!sxiw_add(c,&sxiw_aa_header,0)||!sxiw_word(c,8,4,true,&n)||n<2||n>65536||!sxiw_span(c,p,n*12))return false;
 for(uint64_t i=0;i<n;i++,p+=12){uint64_t off,z;if(!sxiw_word(c,p+4,4,true,&off)||!sxiw_word(c,p+8,4,true,&z)||!sxiw_add(c,&sxiw_aa_toc,p))return false;if(i&&z>lsize&&sxiw_span(c,off,z)){largest=off;lsize=z;}}
 /* The fixed 24-byte termination block is undocumented and remains raw. */
 if(p+24>end)return true;p+=24;if(!sxiw_word(c,p,4,true,&n)||!sxiw_emit(c,&p,end,&sxiw_aa_dictionary_count)||n>65536)return true;
 for(uint64_t i=0;i<n;i++){uint64_t k,v;if(!sxiw_word(c,p+1,4,true,&k)||!sxiw_word(c,p+5,4,true,&v)||p>end||9>end-p||k>end-p-9||v>end-p-9-k||!sxiw_emit(c,&p,end,&sxiw_aa_dictionary_entry))break;if(!sxiw_text(c,&sxiw_aa_dictionary_key,p,k,false))break;p+=k;if(!sxiw_text(c,&sxiw_aa_dictionary_value,p,v,false))break;p+=v;}
 /* Audio framing follows the demuxer's largest nonfirst TOC extent. No decryption. */
 p=largest;end=largest+lsize;for(unsigned i=0;lsize&&p<end&&i<SXIW_LIMIT;i++){uint64_t z;if(end-p<8||!sxiw_word(c,p,4,true,&z)||!z||z>end-p-8||!sxiw_add(c,&sxiw_aa_chapter,p))break;p+=8+z;}return true;
}
static const uint8_t sxiw_guid_header[16]={48,38,178,117,142,102,207,17,166,217,0,170,0,98,206,108};
static const uint8_t sxiw_guid_file_header[16]={161,220,171,140,71,169,207,17,142,228,0,192,12,32,83,101};
static const uint8_t sxiw_guid_stream_header[16]={145,7,220,183,183,169,207,17,142,230,0,192,12,32,83,101};
static const uint8_t sxiw_guid_head1_guid[16]={181,3,191,95,46,169,207,17,142,227,0,192,12,32,83,101};
static const uint8_t sxiw_guid_data_header[16]={54,38,178,117,142,102,207,17,166,217,0,170,0,98,206,108};
static const uint8_t sxiw_guid_comment_header[16]={51,38,178,117,142,102,207,17,166,217,0,170,0,98,206,108};
static const uint8_t sxiw_guid_extended_content_header[16]={64,164,208,210,7,227,210,17,151,240,0,160,201,94,168,80};
static const uint8_t sxiw_guid_metadata_header[16]={234,203,248,197,175,91,119,72,132,103,170,140,68,250,76,202};
static const uint8_t sxiw_guid_metadata_library_header[16]={148,28,35,68,152,148,209,73,161,65,29,19,78,69,112,84};
static const uint8_t sxiw_guid_language_guid[16]={169,70,67,124,224,239,252,75,178,41,57,62,222,65,92,133};
static const uint8_t sxiw_guid_bitrate[16]={206,117,248,123,141,70,209,17,141,130,0,96,151,201,162,178};
static const uint8_t sxiw_guid_simple_index_header[16]={144,8,0,51,177,229,207,17,137,244,0,160,201,3,73,203};
static bool sxiw_asf_value(sx_context*c,uint64_t p,uint64_t z,unsigned type){const sx_layout*l=type==0?&sxiw_asf_utf16_units:type==2?&sxiw_asf_value_boolean:type==3?&sxiw_asf_value_dword:type==4?&sxiw_asf_value_qword:type==5?&sxiw_asf_value_word:&sxiw_asf_binary_value;if(type==0&&(z&1))return true;if(type>=2&&type<=5){uint64_t expected=type==4?8:type==5?2:4;return z==expected?sxiw_add(c,l,p):true;}return sxiw_text(c,l,p,z,false);}
static bool sxiw_asf_objects(sx_context*c,uint64_t p,uint64_t end,unsigned depth,uint64_t maximum){
 if(depth>16||end>(uint64_t)c->size||p>end)return false;
 for(uint64_t k=0;k<maximum&&p<end&&c->count<SXIW_LIMIT;k++){
 uint8_t guid[16];uint64_t z,q,stop,n=0;
 if(end-p<24||!sxiw_read(c,p,guid,16)||!sxiw_word(c,p+16,8,false,&z)||z<24||z>end-p)return true;
 q=p+24;stop=p+z;
 if(!xx_rt_memcmp(guid,sxiw_guid_header,16)){if(z<30||!sxiw_word(c,p+24,4,false,&n)||!sxiw_add(c,&sxiw_asf_header,p))return false;if(!sxiw_asf_objects(c,p+30,stop,depth+1,n))return false;p=stop;continue;}
 if(!sxiw_add(c,&sxiw_asf_object,p))return false;
 if(!xx_rt_memcmp(guid,sxiw_guid_file_header,16)){if(stop-q>=80&&!sxiw_add(c,&sxiw_asf_file_properties,q))return false;}
 else if(!xx_rt_memcmp(guid,sxiw_guid_stream_header,16)){if(stop-q>=54&&!sxiw_add(c,&sxiw_asf_stream_properties,q))return false;}
 else if(!xx_rt_memcmp(guid,sxiw_guid_data_header,16)){if(stop-q>=26&&!sxiw_add(c,&sxiw_asf_data_header,q))return false;}
 else if(!xx_rt_memcmp(guid,sxiw_guid_head1_guid,16)){uint64_t sz;if(stop-q>=22&&sxiw_word(c,q+18,4,false,&sz)&&sz<=stop-q-22){if(!sxiw_add(c,&sxiw_asf_header_extension,q)||!sxiw_asf_objects(c,q+22,q+22+sz,depth+1,SXIW_LIMIT))return false;}}
 else if(!xx_rt_memcmp(guid,sxiw_guid_comment_header,16)){uint8_t lens[10];if(stop-q>=10&&sxiw_read(c,q,lens,10)){if(!sxiw_add(c,&sxiw_asf_content_lengths,q))return false;q+=10;for(unsigned i=0;i<5;i++){uint64_t a=sxiw_uint(lens+i*2,2,false);if(a>stop-q)break;if(!(a&1)&&!sxiw_text(c,&sxiw_asf_utf16_units,q,a,false))return false;q+=a;}}}
 else if(!xx_rt_memcmp(guid,sxiw_guid_extended_content_header,16)||!xx_rt_memcmp(guid,sxiw_guid_metadata_header,16)||!xx_rt_memcmp(guid,sxiw_guid_metadata_library_header,16)){
 bool ext=!xx_rt_memcmp(guid,sxiw_guid_extended_content_header,16);if(stop-q>=2&&sxiw_word(c,q,2,false,&n)&&sxiw_emit(c,&q,stop,&sxiw_asf_descriptor_count))for(uint64_t i=0;i<n&&c->count<SXIW_LIMIT;i++){
 uint64_t nam,typ,val;if(ext){if(stop-q<2||!sxiw_word(c,q,2,false,&nam)||nam>stop-q-2||!sxiw_emit(c,&q,stop,&sxiw_asf_name_length))break;if(!(nam&1)&&!sxiw_text(c,&sxiw_asf_utf16_units,q,nam,false))return false;q+=nam;if(stop-q<4||!sxiw_word(c,q,2,false,&typ)||!sxiw_word(c,q+2,2,false,&val)||val>stop-q-4||!sxiw_emit(c,&q,stop,&sxiw_asf_value_header))break;}
 else{if(stop-q<12||!sxiw_word(c,q+4,2,false,&nam)||!sxiw_word(c,q+6,2,false,&typ)||!sxiw_word(c,q+8,4,false,&val)||nam>stop-q-12||val>stop-q-12-nam||!sxiw_emit(c,&q,stop,&sxiw_asf_metadata_header))break;if(!(nam&1)&&!sxiw_text(c,&sxiw_asf_utf16_units,q,nam,false))return false;q+=nam;}
 if(!sxiw_asf_value(c,q,val,(unsigned)typ))return false;q+=val;
 }}else if(!xx_rt_memcmp(guid,sxiw_guid_language_guid,16)){if(stop-q>=2&&sxiw_word(c,q,2,false,&n)&&sxiw_emit(c,&q,stop,&sxiw_asf_descriptor_count))for(uint64_t i=0;i<n;i++){uint64_t z;if(q>=stop||!sxiw_word(c,q,1,false,&z)||z>stop-q-1||!sxiw_emit(c,&q,stop,&sxiw_asf_language_length))break;if(!(z&1)&&!sxiw_text(c,&sxiw_asf_utf16_units,q,z,false))return false;q+=z;}}
 else if(!xx_rt_memcmp(guid,sxiw_guid_bitrate,16)){if(stop-q>=2&&sxiw_word(c,q,2,false,&n)&&sxiw_emit(c,&q,stop,&sxiw_asf_descriptor_count)){if(n<=(stop-q)/6&&!sxiw_table(c,&sxiw_asf_bitrate,q,6,n))return false;}}
 else if(!xx_rt_memcmp(guid,sxiw_guid_simple_index_header,16)){if(stop-q>=32&&sxiw_word(c,q+28,4,false,&n)&&sxiw_emit(c,&q,stop,&sxiw_asf_simple_index)){if(n<=(stop-q)/6&&!sxiw_table(c,&sxiw_asf_index_entry,q,6,n))return false;}}
 p=stop;
 }return true;
}
static bool sxiw_asf(sx_context*c){uint64_t size,n;if(!sxiw_add(c,&sxiw_asf_header,0)||!sxiw_word(c,16,8,false,&size)||!sxiw_word(c,24,4,false,&n))return false;if(size<30||size>(uint64_t)c->size)return true;return sxiw_asf_objects(c,30,size,1,n)&&sxiw_asf_objects(c,size,(uint64_t)c->size,0,SXIW_LIMIT);}

static bool sxiw_sisx(sx_context*c,uint64_t p,uint64_t end,unsigned depth,uint32_t implicit){
 if(depth>32||p>end||end>(uint64_t)c->size)return false;
 for(unsigned count=0;p<end&&count<SXIW_LIMIT&&c->count<SXIW_LIMIT;count++){
 uint64_t type=implicit,low,high=0,z,q,stop;const sx_layout*l;
 q=p;if(!implicit){if(end-q<4||!sxiw_word(c,q,4,false,&type))return true;q+=4;}
 if(end-q<4||!sxiw_word(c,q,4,false,&low))return true;q+=4;
 if(low&0x80000000U){if(end-q<4||!sxiw_word(c,q,4,false,&high)||high>=0x80000000U)return true;q+=4;}
 z=(low&0x7fffffffU)|(high<<31);if(z>end-q)return true;stop=q+z;
 l=implicit?(low&0x80000000U?&sxiw_sisx_array_long_length:&sxiw_sisx_array_length):(low&0x80000000U?&sxiw_sisx_long_field:&sxiw_sisx_field);
 if(!sxiw_add(c,l,p))return false;
 if(type==2&&z>=4){uint64_t element;if(!sxiw_word(c,q,4,false,&element)||!sxiw_add(c,&sxiw_sisx_array_element,q))return false;if(element&&element<=42&&!sxiw_sisx(c,q+4,stop,depth+1,(uint32_t)element))return false;}
 else if(type==3&&z>=12){uint64_t algo,uz;if(!sxiw_word(c,q,4,false,&algo)||!sxiw_word(c,q+4,8,false,&uz)||!sxiw_add(c,&sxiw_sisx_compressed,q))return false;if(!algo&&uz==z-12&&!sxiw_sisx(c,q+12,stop,depth+1,0))return false;}
 else if(type==1&&!(z&1)){if(!sxiw_text(c,&sxiw_sis_utf16,q,z,false))return false;}
 else if((type==34||type==35)&&z>=2){if(!sxiw_add(c,&sxiw_sisx_checksum,q))return false;}
 else if(type==40&&z>=4){if(!sxiw_add(c,&sxiw_sisx_data_index,q))return false;}
 else if(type==12||type==13||type==28||type==30||type==31||type==32){if(!sxiw_sisx(c,q,stop,depth+1,0))return false;}
 p=stop;uint64_t pad=(4-(z&3))&3;if(pad>end-p)p=end;else p+=pad;
 }return true;
}
static bool sxiw_sis(sx_context*c){uint8_t h[68];uint64_t uid;if(!sxiw_word(c,0,4,false,&uid))return false;if(uid==0x10201a7aU)return sxiw_add(c,&sxiw_sis_uids,0)&&sxiw_sisx(c,16,(uint64_t)c->size,0,0);
 if(!sxiw_read(c,0,h,68)||!sxiw_add(c,&sxiw_sis_epoc_header,0))return false;
 bool r6=sxiw_uint(h+4,4,false)==0x10003a12U,unicode=(h[36]&1)!=0;uint64_t langs=sxiw_uint(h+18,2,false),files=sxiw_uint(h+20,2,false),lp=sxiw_uint(h+48,4,false),fp=sxiw_uint(h+52,4,false),limit=(uint64_t)c->size;const sx_layout*str=unicode?&sxiw_sis_utf16:&sxiw_sis_latin1;
 for(unsigned k=48;k<=64;k+=4){uint64_t a=sxiw_uint(h+k,4,false);if(a>=68&&a<limit)limit=a;}
 if(r6){if(limit>=76&&!sxiw_add(c,&sxiw_sis_epoc6_extension,68))return false;if(limit>=80&&!sxiw_add(c,&sxiw_sis_installed_space,76))return false;if(limit>=84&&!sxiw_add(c,&sxiw_sis_maximum_installed_space,80))return false;if(limit>=100&&!sxiw_add(c,&sxiw_sis_epoc6_reserved,84))return false;}
 if(langs<=256&&lp>=68&&sxiw_span(c,lp,langs*2)&&!sxiw_table(c,&sxiw_sis_language,lp,2,langs))return false;
 uint64_t p=fp;for(uint64_t i=0;i<files&&c->count<SXIW_LIMIT;i++){uint64_t typ;if(!sxiw_word(c,p,4,false,&typ))break;if(typ==3||typ==4){uint64_t n;if(!sxiw_word(c,p+4,4,false,&n)||!sxiw_span(c,p,8+n)||!sxiw_add(c,&sxiw_sis_conditional,p))break;p+=8+n;continue;}if(typ==5||typ==6){if(!sxiw_add(c,&sxiw_sis_control_type,p))break;p+=4;continue;}if(typ>1)break;
 uint64_t forks=typ?langs:1,z=28+(r6?12*forks+8:8*forks);uint8_t r[28];if(forks>256||!sxiw_span(c,p,z)||!sxiw_read(c,p,r,28)||!sxiw_add(c,&sxiw_sis_file_record,p))break;
 for(unsigned j=12;j<=20;j+=8){uint64_t n=sxiw_uint(r+j,4,false),off=sxiw_uint(r+j+4,4,false);if(sxiw_span(c,off,n)&&(!unicode||!(n&1))&&!sxiw_text(c,str,off,n,false))return false;}
 uint64_t q=p+28;if(!sxiw_table(c,&sxiw_sis_payload_length,q,4,forks)||!sxiw_table(c,&sxiw_sis_payload_offset,q+4*forks,4,forks))return false;q+=8*forks;
 if(r6){if(!sxiw_table(c,&sxiw_sis_uncompressed_length,q,4,forks))return false;q+=4*forks;if(!sxiw_add(c,&sxiw_sis_mime_length,q)||!sxiw_add(c,&sxiw_sis_mime_offset,q+4))return false;}
 p+=z;}
 /* Requisites and component names store parallel arrays of localized lengths and pointers. */
 p=sxiw_uint(h+56,4,false);uint64_t req=sxiw_uint(h+22,2,false),width=12+8*langs;if(p>=68&&langs<=256&&width&&sxiw_span(c,p,req*width))for(uint64_t i=0;i<req&&c->count<SXIW_LIMIT;i++,p+=width){if(!sxiw_add(c,&sxiw_sis_requisite,p)||!sxiw_table(c,&sxiw_sis_localized_name_length,p+12,4,langs)||!sxiw_table(c,&sxiw_sis_localized_name_offset,p+12+4*langs,4,langs))return false;}
 p=sxiw_uint(h+64,4,false);if(p>=68&&langs<=256&&sxiw_span(c,p,8*langs)){if(!sxiw_table(c,&sxiw_sis_localized_name_length,p,4,langs)||!sxiw_table(c,&sxiw_sis_localized_name_offset,p+4*langs,4,langs))return false;}
 p=sxiw_uint(h+60,4,false);if(p>=68&&sxiw_span(c,p,16)&&!sxiw_add(c,&sxiw_sis_certificate_header,p))return false;
 if(r6&&limit>=76){uint64_t cp,n=sxiw_uint(h+30,2,false);if(sxiw_word(c,72,4,false,&cp)&&cp>=68&&sxiw_span(c,cp,n*8)&&!sxiw_table(c,&sxiw_sis_capability,cp,8,n))return false;}
 return true;
}

static bool sxiw_zip_extras(sx_context*c,uint64_t p,uint64_t end){for(unsigned i=0;p<end&&i<SXIW_LIMIT;i++){uint64_t z;if(end-p<4||!sxiw_word(c,p+2,2,false,&z)||z>end-p-4)return true;if(!sxiw_add(c,&sxiw_installer_zip_extra,p))return false;p+=4+z;}return true;}
static bool sxiw_dahua(sx_context*c){uint64_t end=(uint64_t)c->size,eo=0,n,dir,ds;uint8_t b[4];if(end<22)return false;uint64_t begin=end>65557?end-65557:0;for(uint64_t p=end-22;;p--){uint64_t z;if(sxiw_read(c,p,b,4)&&!xx_rt_memcmp(b,"PK\5\6",4)&&sxiw_word(c,p+20,2,false,&z)&&z<=end-p-22){eo=p;break;}if(p==begin)break;}if(!eo)return sxiw_add(c,&sxiw_installer_zip_local,0);if(!sxiw_add(c,&sxiw_installer_zip_eocd,eo)||!sxiw_word(c,eo+10,2,false,&n)||!sxiw_word(c,eo+12,4,false,&ds)||!sxiw_word(c,eo+16,4,false,&dir))return false;
 uint64_t comment;if(sxiw_word(c,eo+20,2,false,&comment)&&!sxiw_text(c,&sxiw_installer_zip_comment,eo+22,comment,false))return false;
 if(!sxiw_span(c,dir,ds)||dir+ds>eo||n>ds/46)return true;uint64_t p=dir;for(uint64_t i=0;i<n&&c->count<SXIW_LIMIT;i++){uint8_t h[46];if(dir+ds-p<46||!sxiw_read(c,p,h,46)||xx_rt_memcmp(h,"PK\1\2",4))break;uint64_t a=sxiw_uint(h+28,2,false),b=sxiw_uint(h+30,2,false),z=sxiw_uint(h+32,2,false),lo=sxiw_uint(h+42,4,false);if(a+b+z>dir+ds-p-46)break;if(!sxiw_add(c,&sxiw_installer_zip_central,p)||!sxiw_text(c,&sxiw_installer_zip_name,p+46,a,false)||!sxiw_zip_extras(c,p+46+a,p+46+a+b)||!sxiw_text(c,&sxiw_installer_zip_comment,p+46+a+b,z,false))return false;
 uint8_t l[30];if(sxiw_read(c,lo,l,30)&&((!lo&&!xx_rt_memcmp(l,"DH\3\4",4))||!xx_rt_memcmp(l,"PK\3\4",4))){uint64_t ln=sxiw_uint(l+26,2,false),ex=sxiw_uint(l+28,2,false);if(sxiw_span(c,lo,30+ln+ex)){if(!sxiw_add(c,&sxiw_installer_zip_local,lo)||!sxiw_text(c,&sxiw_installer_zip_name,lo+30,ln,false)||!sxiw_zip_extras(c,lo+30+ln,lo+30+ln+ex))return false;}}
 p+=46+a+b+z;}return true;}
static bool sxiw_cpio(sx_context*c,uint64_t start,uint64_t*next){uint64_t p=start;for(unsigned i=0;i<SXIW_LIMIT&&c->count<SXIW_LIMIT;i++){uint8_t h[6];uint64_t head,name,z,align=1;const sx_layout*l;if(!sxiw_read(c,p,h,6))return false;
 if(!xx_rt_memcmp(h,"070701",6)||!xx_rt_memcmp(h,"070702",6)){head=110;align=4;l=&sxiw_solaris_cpio_newc;if(!sxiw_ascii(c,p+94,8,16,&name)||!sxiw_ascii(c,p+54,8,16,&z))return false;}
 else if(!xx_rt_memcmp(h,"070707",6)){head=76;l=&sxiw_solaris_cpio_odc;if(!sxiw_ascii(c,p+59,6,8,&name)||!sxiw_ascii(c,p+65,11,8,&z))return false;}
 else if(sxiw_uint(h,2,false)==070707||sxiw_uint(h,2,true)==070707){bool be=sxiw_uint(h,2,true)==070707;uint64_t hi,lo;head=26;align=2;l=be?&sxiw_solaris_cpio_binary_be:&sxiw_solaris_cpio_binary_le;if(!sxiw_word(c,p+20,2,be,&name)||!sxiw_word(c,p+22,2,be,&hi)||!sxiw_word(c,p+24,2,be,&lo))return false;z=(hi<<16)|lo;}
 else return false;if(!name||name>4096||!sxiw_span(c,p,head+name))return false;uint64_t data=p+head+name;data+=((align-(data-start)%align)%align);if(!sxiw_span(c,data,z)||!sxiw_add(c,l,p)||!sxiw_text(c,&sxiw_solaris_cpio_name,p+head,name,false))return false;uint8_t tag[11];bool last=name==11&&sxiw_read(c,p+head,tag,11)&&!xx_rt_memcmp(tag,"TRAILER!!!\0",11);p=data+z;p+=((align-(p-start)%align)%align);if(last){*next=p;return true;}}
 return false;}
static bool sxiw_solaris(sx_context*c){if(!sxiw_add(c,&sxiw_solaris_banner,0))return false;uint8_t h[512];if(!sxiw_read(c,0,h,512))return true;uint64_t p=21;while(p<512){uint64_t a=p;while(p<512&&h[p]!='\n'&&h[p])p++;uint64_t e=p;if(p<512)p++;if(e-a>=15&&!xx_rt_memcmp(h+a,"# end of header",15)){if(!sxiw_add(c,&sxiw_solaris_end_header,a))return false;break;}uint64_t b=a;while(b<e&&h[b]!=' '&&h[b]!='\t')b++;if(b>a&&!sxiw_text(c,&sxiw_solaris_package_name,a,b-a,false))return false;for(unsigned k=0;k<2;k++){while(b<e&&(h[b]==' '||h[b]=='\t'))b++;a=b;while(b<e&&h[b]>='0'&&h[b]<='9')b++;if(a==b)break;if(!sxiw_text(c,k?&sxiw_solaris_block_count:&sxiw_solaris_part_count,a,b-a,false))return false;}if(e>=512||!h[e])break;}
 p=512;for(unsigned i=0;p<(uint64_t)c->size&&i<1024&&c->count<SXIW_LIMIT;i++){uint64_t next;if(!sxiw_cpio(c,p,&next))break;p=next+((512-(next%512))%512);}return true;}

typedef struct sxiw_java_handle {uint8_t*types;uint16_t count;}sxiw_java_handle;
typedef struct sxiw_java {sx_context*c;uint64_t p,end;sxiw_java_handle h[4096];unsigned count;}sxiw_java;
static bool sxiw_jreserve(sxiw_java*j,unsigned*index){if(j->count>=4096)return false;*index=j->count++;return true;}
static bool sxiw_jvalue(sxiw_java*j,unsigned depth);
static bool sxiw_jutf(sxiw_java*j){uint64_t n;if(!sxiw_word(j->c,j->p,2,true,&n)||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_utf_length)||n>j->end-j->p||!sxiw_text(j->c,&sxiw_java_modified_utf8,j->p,n,false))return false;j->p+=n;return true;}
static bool sxiw_jclass(sxiw_java*j,unsigned depth,unsigned*handle){uint64_t tag,n;unsigned h;if(depth>32||!sxiw_word(j->c,j->p,1,false,&tag))return false;if(tag==0x71){if(!sxiw_word(j->c,j->p+1,4,true,&n)||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_reference)||n<0x7e0000||n-0x7e0000>=j->count||!j->h[n-0x7e0000].types)return false;*handle=(unsigned)(n-0x7e0000);return true;}if(tag!=0x72||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_class_tag)||!sxiw_jutf(j)||j->end-j->p<11||!sxiw_word(j->c,j->p+9,2,true,&n)||n>4096||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_class_metadata)||!sxiw_jreserve(j,&h))return false;
 j->h[h].types=xx_mem_alloc(n?n:1);if(!j->h[h].types)return false;j->h[h].count=(uint16_t)n;
 for(unsigned i=0;i<n;i++){uint64_t t;if(!sxiw_word(j->c,j->p,1,false,&t)||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_field_type)||!sxiw_jutf(j))return false;j->h[h].types[i]=(uint8_t)t;if((t=='L'||t=='[')&&!sxiw_jvalue(j,depth+1))return false;}
 for(unsigned i=0;i<2;i++){if(!sxiw_word(j->c,j->p,1,false,&tag)||tag!=(i?0x70:0x78)||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag))return false;}*handle=h;return true;}
static bool sxiw_jvalue(sxiw_java*j,unsigned depth){uint64_t tag,n;unsigned idx;if(depth>32||j->c->count>=SXIW_LIMIT||!sxiw_word(j->c,j->p,1,false,&tag))return false;
 if(tag==0x70||tag==0x78)return sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag);
 if(tag==0x71)return sxiw_emit(j->c,&j->p,j->end,&sxiw_java_reference);
 if(tag==0x74||tag==0x7c){unsigned width=tag==0x74?2:8;if(!sxiw_word(j->c,j->p+1,width,true,&n)||!sxiw_emit(j->c,&j->p,j->end,tag==0x74?&sxiw_java_string:&sxiw_java_long_string)||n>j->end-j->p||!sxiw_text(j->c,&sxiw_java_modified_utf8,j->p,n,false)||!sxiw_jreserve(j,&idx))return false;j->p+=n;return true;}
 if(tag==0x77||tag==0x7a){if(!sxiw_word(j->c,j->p+1,tag==0x77?1:4,true,&n)||!sxiw_emit(j->c,&j->p,j->end,tag==0x77?&sxiw_java_block:&sxiw_java_long_block)||n>j->end-j->p)return false;j->p+=n;return true;}
 if(tag==0x72)return sxiw_jclass(j,depth+1,&idx);
 if(tag!=0x73||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag)||!sxiw_jclass(j,depth+1,&idx))return false;unsigned reserved;if(!sxiw_jreserve(j,&reserved))return false;
 for(unsigned i=0;i<j->h[idx].count;i++){uint8_t t=j->h[idx].types[i];const sx_layout*l=NULL;switch(t){case'B':l=&sxiw_java_byte;break;case'C':l=&sxiw_java_char;break;case'D':l=&sxiw_java_double;break;case'F':l=&sxiw_java_float;break;case'I':l=&sxiw_java_int;break;case'J':l=&sxiw_java_long;break;case'S':l=&sxiw_java_short;break;case'Z':l=&sxiw_java_boolean;break;case'L':case'[':if(!sxiw_jvalue(j,depth+1))return false;break;default:return false;}if(l&&!sxiw_emit(j->c,&j->p,j->end,l))return false;}return true;}
static bool sxiw_jlist(sxiw_java*j){uint64_t tag,n;unsigned h;if(!sxiw_word(j->c,j->p,1,false,&tag))return false;if(tag==0x71)return sxiw_jvalue(j,0);if(tag!=0x73||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag)||!sxiw_jclass(j,0,&h)||!sxiw_jreserve(j,&h)||!sxiw_word(j->c,j->p,4,true,&n)||n>4096||!sxiw_emit(j->c,&j->p,j->end,&sxiw_izpack_list_count)||!sxiw_jvalue(j,0))return false;for(uint64_t i=0;i<n;i++)if(!sxiw_jvalue(j,0))return false;return sxiw_word(j->c,j->p,1,false,&tag)&&tag==0x78&&sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag);}
static bool sxiw_izpack(sx_context*c){sxiw_java*j=xx_mem_calloc(1,sizeof(*j));if(!j)return false;j->c=c;j->p=10;j->end=(uint64_t)c->size;uint64_t count,uid,n;bool ok=false;unsigned version=0;
 if(!sxiw_add(c,&sxiw_izpack_stream_header,0)||!sxiw_word(c,6,4,true,&count)||count>1000000||!sxiw_word(c,41,8,true,&uid)||!sxiw_word(c,50,2,true,&n))goto done;
 if(uid==UINT64_C(0x76a523b293a5e5c3)&&n==2)version=1;else if(uid==UINT64_C(0x11e206a67610577a)&&n==5)version=2;else if(uid==UINT64_C(0x9856d67cc286140e)&&n==7)version=3;else if(uid==UINT64_C(0x99e53bc9ae638cb7)&&n==8)version=4;else if(uid==UINT64_C(0xf46bb277b6f32403)&&n>=10&&n<=12)version=(unsigned)n-5;else goto done;
 const sx_layout*records[]={&sxiw_izpack_record_v1,&sxiw_izpack_record_v2,&sxiw_izpack_record_v3,&sxiw_izpack_record_v4,&sxiw_izpack_record_v5,&sxiw_izpack_record_v6,&sxiw_izpack_record_v7};
 for(uint64_t i=0;i<count&&c->count<SXIW_LIMIT;i++){uint64_t tag,len,previous=UINT64_MAX,directory=0,pack=0;unsigned h;if(!sxiw_word(c,j->p,1,false,&tag)||tag!=0x73||!sxiw_emit(c,&j->p,j->end,&sxiw_java_object_tag)||!sxiw_jclass(j,0,&h)||!sxiw_jreserve(j,&h))goto done;uint64_t a=j->p;
 if(version>=4&&!sxiw_word(c,a++,1,false,&directory))goto done;if(!sxiw_word(c,a,8,true,&len))goto done;a+=8;if(version!=1)a+=8;if(version>=3&&!sxiw_word(c,a,8,true,&previous))goto done;if(!sxiw_emit(c,&j->p,j->end,records[version-1]))goto done;if(version==7&&!sxiw_word(c,j->p-1,1,false,&pack))goto done;
 if(version>=5&&!sxiw_jvalue(j,0))goto done;if(version>=6&&!sxiw_jvalue(j,0))goto done;if(version!=1&&!sxiw_jlist(j))goto done;if(version>=6&&!sxiw_jvalue(j,0))goto done;if(version>=5&&!sxiw_jvalue(j,0))goto done;if(!sxiw_jvalue(j,0))goto done;if(previous!=UINT64_MAX)continue;
 uint64_t left=pack?4:directory?0:len;while(left){uint64_t z;if(!sxiw_word(c,j->p,1,false,&tag)||(tag!=0x77&&tag!=0x7a)||!sxiw_word(c,j->p+1,tag==0x77?1:4,true,&z)||!z||!sxiw_emit(c,&j->p,j->end,tag==0x77?&sxiw_java_block:&sxiw_java_long_block)||z>j->end-j->p)goto done;j->p+=z;if(z>=left)left=0;else left-=z;}}
 ok=true;done:for(unsigned i=0;i<j->count;i++)xx_mem_free(j->h[i].types);xx_mem_free(j);return ok;}

static bool sxiw_shell_word(uint8_t c){return(c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='_';}
static bool sxiw_shell(sx_context*c,uint64_t bound){
 uint64_t end=bound<(uint64_t)c->size?bound:(uint64_t)c->size;if(end>65536)end=65536;uint8_t*b=xx_mem_alloc((size_t)end+1);if(!b)return false;bool ok=sxiw_read(c,0,b,(size_t)end);if(!ok)goto done;b[end]=0;bool legacy=xx_rt_strstr((const char*)b,"This script was generated using Makeself 1.")!=NULL;
 uint64_t p=0;while(p<end&&c->count<SXIW_LIMIT){uint64_t start=p;while(p<end&&b[p]&&b[p]!='\n')p++;uint64_t e=p;if(p<end&&b[p])p++;else end=p;if(e>start&&b[e-1]=='\r')e--;if(e-start>=2&&b[start]=='#'&&b[start+1]=='!'){uint64_t a=start+2;while(a<e&&(b[a]==' '||b[a]=='\t'))a++;if(!sxiw_text(c,&sxiw_shell_interpreter,a,e-a,false)){ok=false;break;}continue;}
 uint64_t q=start;while(q<e&&sxiw_shell_word(b[q]))q++;if(q>start&&q<e&&b[q]=='='){
 uint64_t k=q-start,a=q+1,z=e;while(a<z&&(b[a]==' '||b[a]=='\t'))a++;while(z>a&&(b[z-1]==' '||b[z-1]=='\t'))z--;if(z-a>=2&&b[a]=='"'&&b[z-1]=='"'){a++;z--;}
 const sx_layout*l=&sxiw_shell_assignment_value;
 #define SXIW_KEY(s) (k==sizeof(s)-1&&!xx_rt_memcmp(b+start,s,sizeof(s)-1))
 if(SXIW_KEY("skip"))l=legacy?&sxiw_shell_skip_parameter:&sxiw_shell_line_count;else if(SXIW_KEY("BLOCKSIZE"))l=&sxiw_shell_block_size;else if(SXIW_KEY("ARCHSTART")||SXIW_KEY("JRESTART"))l=&sxiw_shell_block_index;else if(SXIW_KEY("ARCHREALSIZE")||SXIW_KEY("JREREALSIZE")||SXIW_KEY("RESREALSIZE"))l=&sxiw_shell_payload_size;else if(SXIW_KEY("ARCHSIZE")||SXIW_KEY("RESSIZE"))l=&sxiw_shell_block_count;
 bool sizes=SXIW_KEY("filesizes");
 #undef SXIW_KEY
 if(!sxiw_text(c,&sxiw_shell_assignment_name,start,k,false)){ok=false;break;}
 if(sizes){while(a<z){while(a<z&&(b[a]==' '||b[a]=='\t'))a++;uint64_t x=a;while(a<z&&b[a]>='0'&&b[a]<='9')a++;if(x==a)break;if(!sxiw_text(c,&sxiw_shell_payload_size,x,a-x,false)){ok=false;break;}}}
 else{if(l!=&sxiw_shell_assignment_value){bool numeric=a<z;for(uint64_t x=a;x<z;x++)if(b[x]<'0'||b[x]>'9')numeric=false;if(!numeric)l=&sxiw_shell_assignment_value;}if(!sxiw_text(c,l,a,z-a,false)){ok=false;break;}}
 }else{for(uint64_t a=start;a+4<e;a++){if((a>start&&sxiw_shell_word(b[a-1]))||xx_rt_memcmp(b+a,"tail",4))continue;uint64_t q=a+4;while(q<e&&(b[q]==' '||b[q]=='\t'))q++;if(q+2<e&&b[q]=='-'&&b[q+1]=='n'){q+=2;while(q<e&&(b[q]==' '||b[q]=='\t'))q++;}if(q>=e||b[q++]!='+')continue;uint64_t n=q;while(q<e&&b[q]>='0'&&b[q]<='9')q++;if(q>n&&!sxiw_text(c,&sxiw_shell_start_line,n,q-n,false)){ok=false;break;}}}
 }done:xx_mem_free(b);return ok;
}
/* Native callbacks supply only the first authenticated payload boundary. */
static uint64_t sxiw_shell_bound(sx_context*c){uint64_t end=(uint64_t)c->size;Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->free_archive_records_reading)return end;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,c->pd);if(!s)return end;for(unsigned i=0;i<256;i++){const xx_archive_record*r=xx_format_get_current_archive_record(f,s);if(!r)break;if(r->data_offset>=f->base_address){uint64_t p=(uint64_t)(r->data_offset-f->base_address);if(p<end)end=p;}if(!xx_format_archive_record_move_to_next(f,s,c->pd))break;}xx_format_free_archive_records_reading(f,s);return end;}
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
static bool sxiw_starkit(sx_context*c){int64_t base,size,inner;if(!xx_binsh_starkit_get_container_span(c->f,&base,&size,&inner))return false;Abstractformat view=*c->f,*prior=c->f;int64_t oldsize=c->size;view.base_address=base;c->f=&view;c->size=size;bool ok=sxiw_shell(c,(uint64_t)(inner-base));if(ok){view.base_address=inner;c->size=size-(inner-base);ok=sxbx_starkit(c);}view.base_address=base;c->size=size;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxiw_order);if(c->count)ok=sxiw_finish(c);c->f=prior;c->size=oldsize;return ok;}
#else
static bool sxiw_starkit(sx_context*c){(void)c;return false;}
#endif

static const sx_layout*sxiw_starkit_lookup(uint32_t id,const char*name){for(size_t i=0;i<SX_COUNT(sx_installerwire_layouts);i++){const sx_layout*l=sx_installerwire_layouts[i];if((name&&!xx_rt_strcmp(name,l->name))||(!name&&id==l->id))return l;}for(size_t i=0;i<SX_COUNT(sx_binaryextra_layouts);i++){const sx_layout*l=sx_binaryextra_layouts[i];if(!xx_rt_strncmp(l->name,"starkit_",8)&&((name&&!xx_rt_strcmp(name,l->name))||(!name&&id==l->id)))return l;}return NULL;}
static bool sx_installerwire_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_IS7INX:case XX_FILE_TYPE_IZPACK:case XX_FILE_TYPE_SOLARISPKG:case XX_FILE_TYPE_OPC:case XX_FILE_TYPE_MAKESELF:case XX_FILE_TYPE_SUN_JAVA_BINSH:case XX_FILE_TYPE_INSTALLANYWHERE_UNIX:case XX_FILE_TYPE_BINSH_SFX:case XX_FILE_TYPE_SIS:case XX_FILE_TYPE_DAHUA_ZIP:case XX_FILE_TYPE_ARCADYAN:case XX_FILE_TYPE_BINSH_STARKIT:case XX_FILE_TYPE_ASF:case XX_FILE_TYPE_AUDIBLE_AA:return true;default:return false;}}
static bool sx_installerwire_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!(c->f->handle_base_info?xx_format_handle_base_info(c->f,c->pd):xx_format_is_valid(c->f,c->pd)))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_IS7INX:ok=sxiw_add(c,&sxiw_is7inx_header,0);break;
 case XX_FILE_TYPE_IZPACK:ok=sxiw_izpack(c);break;
 case XX_FILE_TYPE_SOLARISPKG:ok=sxiw_solaris(c);break;
 case XX_FILE_TYPE_OPC:ok=sxiw_add(c,&sxiw_opc_banner,0);break;
 case XX_FILE_TYPE_MAKESELF:case XX_FILE_TYPE_SUN_JAVA_BINSH:case XX_FILE_TYPE_INSTALLANYWHERE_UNIX:case XX_FILE_TYPE_BINSH_SFX:ok=sxiw_shell(c,sxiw_shell_bound(c));break;
 case XX_FILE_TYPE_BINSH_STARKIT:return sxiw_starkit(c);
 case XX_FILE_TYPE_SIS:ok=sxiw_sis(c);break;
 case XX_FILE_TYPE_DAHUA_ZIP:ok=sxiw_dahua(c);break;
 case XX_FILE_TYPE_ARCADYAN:ok=sxiw_add(c,&sxiw_arcadyan_lzma_fragments,0x68);break;
 case XX_FILE_TYPE_ASF:ok=sxiw_asf(c);break;
 case XX_FILE_TYPE_AUDIBLE_AA:ok=sxiw_aa(c);break;
 default:break;}(void)ok;return c->count&&sxiw_finish(c);}
