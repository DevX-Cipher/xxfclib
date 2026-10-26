/* SPDX-License-Identifier: MIT. Physical metadata. Scope: docs/data_struct_installerwire_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_installerwire.h"
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
static const xx_data_struct_field_desc sxiw_shell_block_count_fields[]={
 SX_FIELD("shell_block_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxiw_shell_block_count={UINT32_C(0x60790070),"shell_block_count",sxiw_shell_block_count_fields,SX_COUNT(sxiw_shell_block_count_fields),SX_LE};
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
bool sxiw_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxiw_read(sx_context*c,uint64_t p,void*b,size_t n){return sxiw_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxiw_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxiw_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxiw_read(c,p,b,n))return false;*v=sxiw_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxiw_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXIW_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxiw_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxiw_add(sx_context*c,const sx_layout*l,uint64_t p){return sxiw_put(c,l,p,0,false);}
bool sxiw_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxiw_put(c,l,p,n,aliases);}
static int sxiw_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxiw_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxiw_order);return !c->failed;}
bool sxiw_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxiw_add(c,l,p+i*width))return false;return true;}
bool sxiw_emit(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l){uint64_t n=(uint64_t)(l->fields[l->field_count-1].rel_offset+l->fields[l->field_count-1].size);if(*p>end||n>end-*p||!sxiw_add(c,l,*p))return false;*p+=n;return true;}
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
#endif
#if SX_ALIAS_READER_FACTORY
#else
static bool sxiw_starkit(sx_context*c){(void)c;return false;}
#endif
const sx_layout*sxiw_starkit_lookup(uint32_t id,const char*name){for(size_t i=0;i<SX_COUNT(sx_installerwire_layouts);i++){const sx_layout*l=sx_installerwire_layouts[i];if((name&&!xx_rt_strcmp(name,l->name))||(!name&&id==l->id))return l;}for(size_t i=0;i<sx_binaryextra_family.layout_count;i++){const sx_layout*l=sx_binaryextra_family.layouts[i];if(!xx_rt_strncmp(l->name,"starkit_",8)&&((name&&!xx_rt_strcmp(name,l->name))||(!name&&id==l->id)))return l;}return NULL;}
static bool sx_installerwire_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_IS7INX:case XX_FILE_TYPE_IZPACK:case XX_FILE_TYPE_SOLARISPKG:case XX_FILE_TYPE_OPC:case XX_FILE_TYPE_MAKESELF:case XX_FILE_TYPE_SUN_JAVA_BINSH:case XX_FILE_TYPE_INSTALLANYWHERE_UNIX:case XX_FILE_TYPE_BINSH_SFX:case XX_FILE_TYPE_SIS:case XX_FILE_TYPE_DAHUA_ZIP:case XX_FILE_TYPE_ARCADYAN:case XX_FILE_TYPE_BINSH_STARKIT:case XX_FILE_TYPE_ASF:case XX_FILE_TYPE_AUDIBLE_AA:return true;default:return false;}}
static bool sx_installerwire_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!(c->f->handle_base_info?xx_format_handle_base_info(c->f,c->pd):xx_format_is_valid(c->f,c->pd)))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_IS7INX:ok=sx_is7inx_build(c);break;
 case XX_FILE_TYPE_IZPACK:ok=sx_izpack_build(c);break;
 case XX_FILE_TYPE_SOLARISPKG:ok=sx_solarispkg_build(c);break;
 case XX_FILE_TYPE_OPC:ok=sx_opc_build(c);break;
 case XX_FILE_TYPE_MAKESELF:case XX_FILE_TYPE_SUN_JAVA_BINSH:case XX_FILE_TYPE_INSTALLANYWHERE_UNIX:case XX_FILE_TYPE_BINSH_SFX:ok=sxiw_shell(c,sxiw_shell_bound(c));break;
 case XX_FILE_TYPE_BINSH_STARKIT:return sxiw_starkit(c);
 case XX_FILE_TYPE_SIS:ok=sx_sis_build(c);break;
 case XX_FILE_TYPE_DAHUA_ZIP:ok=sx_dahuazip_build(c);break;
 case XX_FILE_TYPE_ARCADYAN:ok=sx_arcadyan_build(c);break;
 case XX_FILE_TYPE_ASF:ok=sxiw_asf(c);break;
 case XX_FILE_TYPE_AUDIBLE_AA:ok=sxiw_aa(c);break;
 default:break;}(void)ok;return c->count&&sxiw_finish(c);}
const sx_family sx_installerwire_family={sx_installerwire_supports,sx_installerwire_build,sx_installerwire_layouts,SX_COUNT(sx_installerwire_layouts),sx_installerwire_comment};
