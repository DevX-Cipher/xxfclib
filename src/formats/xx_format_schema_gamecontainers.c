/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical game archive and index metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_gamecontainers.h"
static const xx_data_struct_field_desc sxgco_filename_byte_fields[]={
 SX_FIELD("byte","char[1]",0,1,SX_STRING),
};
const sx_layout sxgco_filename_byte={UINT32_C(0x60400001),"filename_byte",sxgco_filename_byte_fields,SX_COUNT(sxgco_filename_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_encoded_byte_fields[]={
 SX_FIELD("byte","bytes",0,1,SX_NONE),
};
const sx_layout sxgco_encoded_byte={UINT32_C(0x60400002),"encoded_byte",sxgco_encoded_byte_fields,SX_COUNT(sxgco_encoded_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_count16_fields[]={
 SX_FIELD("entries","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxgco_count16={UINT32_C(0x60400003),"count16",sxgco_count16_fields,SX_COUNT(sxgco_count16_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_offset32_fields[]={
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxgco_offset32={UINT32_C(0x60400004),"offset32",sxgco_offset32_fields,SX_COUNT(sxgco_offset32_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_name_size32_fields[]={
 SX_FIELD("name_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxgco_name_size32={UINT32_C(0x60400006),"name_size32",sxgco_name_size32_fields,SX_COUNT(sxgco_name_size32_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_krml_entry_fields[]={
 SX_FIELD("name","char[13]",0,13,SX_STRING),
 SX_FIELD("data_offset","int32",13,4,SX_OFFSET),
 SX_FIELD("data_bytes","int32",17,4,SX_SIZE),
};
const sx_layout sxgco_krml_entry={UINT32_C(0x60400008),"krml_entry",sxgco_krml_entry_fields,SX_COUNT(sxgco_krml_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_sci_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("banner","char[42]",4,42,SX_STRING),
};
const sx_layout sxgco_sci_header={UINT32_C(0x60400009),"sci_header",sxgco_sci_header_fields,SX_COUNT(sxgco_sci_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_seadata_entry_fields[]={
 SX_FIELD("tag","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("next_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("name_bytes","int32",8,4,SX_SIZE),
};
const sx_layout sxgco_seadata_entry={UINT32_C(0x6040000C),"seadata_entry",sxgco_seadata_entry_fields,SX_COUNT(sxgco_seadata_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stk_entry_fields[]={
 SX_FIELD("name","char[13]",0,13,SX_STRING),
 SX_FIELD("stored_bytes","uint32",13,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",17,4,SX_OFFSET),
 SX_FIELD("method","uint8",21,1,SX_ID),
};
const sx_layout sxgco_stk_entry={UINT32_C(0x6040000E),"stk_entry",sxgco_stk_entry_fields,SX_COUNT(sxgco_stk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stk2_header_fields[]={
 SX_FIELD("magic","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("version","uint8",5,1,SX_ID),
 SX_FIELD("timestamp","char[14]",6,14,SX_STRING),
 SX_FIELD("creator","char[8]",20,8,SX_STRING),
 SX_FIELD("directory_offset","uint32",28,4,SX_OFFSET),
};
const sx_layout sxgco_stk2_header={UINT32_C(0x6040000F),"stk2_header",sxgco_stk2_header_fields,SX_COUNT(sxgco_stk2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stk2_directory_fields[]={
 SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("metadata_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxgco_stk2_directory={UINT32_C(0x60400010),"stk2_directory",sxgco_stk2_directory_fields,SX_COUNT(sxgco_stk2_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stk2_entry_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unknown04","bytes",4,36,SX_NONE),
 SX_FIELD("stored_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",44,4,SX_SIZE),
 SX_FIELD("unknown30","bytes",48,13,SX_NONE),
};
const sx_layout sxgco_stk2_entry={UINT32_C(0x60400011),"stk2_entry",sxgco_stk2_entry_fields,SX_COUNT(sxgco_stk2_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_battle_entry_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxgco_battle_entry={UINT32_C(0x60400014),"battle_entry",sxgco_battle_entry_fields,SX_COUNT(sxgco_battle_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_mxs_entry_fields[]={
 SX_FIELD("stored_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("name","char[13]",4,13,SX_STRING),
 SX_FIELD("decoded_bytes","uint32",17,4,SX_SIZE),
};
const sx_layout sxgco_mxs_entry={UINT32_C(0x60400015),"mxs_entry",sxgco_mxs_entry_fields,SX_COUNT(sxgco_mxs_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_sinner_entry_fields[]={
 SX_FIELD("name","char[256]",0,256,SX_STRING),
 SX_FIELD("data_bytes","uint32",256,4,SX_SIZE),
 SX_FIELD("relative_offset","uint32",260,4,SX_OFFSET),
};
const sx_layout sxgco_sinner_entry={UINT32_C(0x60400017),"sinner_entry",sxgco_sinner_entry_fields,SX_COUNT(sxgco_sinner_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_res_entry_fields[]={
 SX_FIELD("name_bytes","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_STRING),
 SX_FIELD("data_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",17,4,SX_SIZE),
 SX_FIELD("type","uint8",21,1,SX_ID),
};
const sx_layout sxgco_res_entry={UINT32_C(0x60400018),"res_entry",sxgco_res_entry_fields,SX_COUNT(sxgco_res_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rsc_entry_fields[]={
 SX_FIELD("data_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",4,4,SX_NONE),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("name","char[13]",12,13,SX_STRING),
};
const sx_layout sxgco_rsc_entry={UINT32_C(0x60400019),"rsc_entry",sxgco_rsc_entry_fields,SX_COUNT(sxgco_rsc_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_vis_index_marker_fields[]={
 SX_FIELD("encrypted_marker","bytes",0,3,SX_NONE),
};
const sx_layout sxgco_vis_index_marker={UINT32_C(0x6040001C),"vis_index_marker",sxgco_vis_index_marker_fields,SX_COUNT(sxgco_vis_index_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_vis_entry_fields[]={
 SX_FIELD("encrypted_relative_offset","bytes",0,4,SX_NONE),
 SX_FIELD("encrypted_stored_bytes","bytes",4,4,SX_NONE),
 SX_FIELD("encrypted_decoded_bytes","bytes",8,4,SX_NONE),
 SX_FIELD("encrypted_flags","bytes",12,4,SX_NONE),
};
const sx_layout sxgco_vis_entry={UINT32_C(0x6040001D),"vis_entry",sxgco_vis_entry_fields,SX_COUNT(sxgco_vis_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_bgi_header_fields[]={
 SX_FIELD("magic","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("entries","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxgco_bgi_header={UINT32_C(0x6040001E),"bgi_header",sxgco_bgi_header_fields,SX_COUNT(sxgco_bgi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_bgi_entry_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_STRING),
 SX_FIELD("relative_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("unknown","bytes",24,8,SX_NONE),
};
static const sx_layout sxgco_bgi_entry={UINT32_C(0x6040001F),"bgi_entry",sxgco_bgi_entry_fields,SX_COUNT(sxgco_bgi_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_bgi2_entry_fields[]={
 SX_FIELD("name","char[96]",0,96,SX_STRING),
 SX_FIELD("relative_offset","uint32",96,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",100,4,SX_SIZE),
 SX_FIELD("unknown","bytes",104,24,SX_NONE),
};
static const sx_layout sxgco_bgi2_entry={UINT32_C(0x60400020),"bgi2_entry",sxgco_bgi2_entry_fields,SX_COUNT(sxgco_bgi2_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_dxa_header1_fields[]={
 SX_FIELD("encrypted_magic","bytes",0,2,SX_NONE),
 SX_FIELD("encrypted_version","bytes",2,2,SX_NONE),
 SX_FIELD("encrypted_index_bytes","bytes",4,4,SX_NONE),
 SX_FIELD("encrypted_data_offset","bytes",8,4,SX_NONE),
 SX_FIELD("encrypted_index_offset","bytes",12,4,SX_NONE),
 SX_FIELD("encrypted_file_table_offset","bytes",16,4,SX_NONE),
 SX_FIELD("encrypted_directory_table_offset","bytes",20,4,SX_NONE),
};
const sx_layout sxgco_dxa_header1={UINT32_C(0x60400021),"dxa_header1",sxgco_dxa_header1_fields,SX_COUNT(sxgco_dxa_header1_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_dxa_header4_fields[]={
 SX_FIELD("encrypted_magic","bytes",0,2,SX_NONE),
 SX_FIELD("encrypted_version","bytes",2,2,SX_NONE),
 SX_FIELD("encrypted_index_bytes","bytes",4,4,SX_NONE),
 SX_FIELD("encrypted_data_offset","bytes",8,4,SX_NONE),
 SX_FIELD("encrypted_index_offset","bytes",12,4,SX_NONE),
 SX_FIELD("encrypted_file_table_offset","bytes",16,4,SX_NONE),
 SX_FIELD("encrypted_directory_table_offset","bytes",20,4,SX_NONE),
 SX_FIELD("encrypted_unknown18","bytes",24,4,SX_NONE),
};
const sx_layout sxgco_dxa_header4={UINT32_C(0x60400022),"dxa_header4",sxgco_dxa_header4_fields,SX_COUNT(sxgco_dxa_header4_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_dxa_header6_fields[]={
 SX_FIELD("encrypted_magic","bytes",0,2,SX_NONE),
 SX_FIELD("encrypted_version","bytes",2,2,SX_NONE),
 SX_FIELD("encrypted_index_bytes","bytes",4,4,SX_NONE),
 SX_FIELD("encrypted_data_offset","bytes",8,8,SX_NONE),
 SX_FIELD("encrypted_index_offset","bytes",16,8,SX_NONE),
 SX_FIELD("encrypted_file_table_offset","bytes",24,8,SX_NONE),
 SX_FIELD("encrypted_directory_table_offset","bytes",32,8,SX_NONE),
 SX_FIELD("encrypted_codepage","bytes",40,4,SX_NONE),
 SX_FIELD("encrypted_unknown2c","bytes",44,4,SX_NONE),
};
const sx_layout sxgco_dxa_header6={UINT32_C(0x60400023),"dxa_header6",sxgco_dxa_header6_fields,SX_COUNT(sxgco_dxa_header6_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_livemaker_offset_fields[]={
 SX_FIELD("encrypted_offset","bytes",0,8,SX_NONE),
};
const sx_layout sxgco_livemaker_offset={UINT32_C(0x60400025),"livemaker_offset",sxgco_livemaker_offset_fields,SX_COUNT(sxgco_livemaker_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_livemaker_flags_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxgco_livemaker_flags={UINT32_C(0x60400026),"livemaker_flags",sxgco_livemaker_flags_fields,SX_COUNT(sxgco_livemaker_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_entry_fields[]={
 SX_FIELD("decoded_bytes","uint64",0,8,SX_SIZE),
 SX_FIELD("attributes","uint32",8,4,SX_FLAGS),
 SX_FIELD("encoding","uint32",12,4,SX_ID),
 SX_FIELD("relative_record_offset","int64",16,8,SX_OFFSET),
 SX_FIELD("timestamp","uint64",24,8,SX_NONE),
 SX_FIELD("extra_bytes","uint32",32,4,SX_SIZE),
};
const sx_layout sxgco_noa_entry={UINT32_C(0x6040002A),"noa_entry",sxgco_noa_entry_fields,SX_COUNT(sxgco_noa_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_name_size_fields[]={
 SX_FIELD("encrypted_name_bytes","bytes",0,4,SX_NONE),
};
const sx_layout sxgco_rgss_name_size={UINT32_C(0x6040002D),"rgss_name_size",sxgco_rgss_name_size_fields,SX_COUNT(sxgco_rgss_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_data_size_fields[]={
 SX_FIELD("encrypted_data_bytes","bytes",0,4,SX_NONE),
};
const sx_layout sxgco_rgss_data_size={UINT32_C(0x6040002E),"rgss_data_size",sxgco_rgss_data_size_fields,SX_COUNT(sxgco_rgss_data_size_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_entry3_fields[]={
 SX_FIELD("encrypted_data_offset","bytes",0,4,SX_NONE),
 SX_FIELD("encrypted_data_bytes","bytes",4,4,SX_NONE),
 SX_FIELD("encrypted_data_key","bytes",8,4,SX_NONE),
 SX_FIELD("encrypted_name_bytes","bytes",12,4,SX_NONE),
};
const sx_layout sxgco_rgss_entry3={UINT32_C(0x6040002F),"rgss_entry3",sxgco_rgss_entry3_fields,SX_COUNT(sxgco_rgss_entry3_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_end3_fields[]={
 SX_FIELD("encrypted_terminator","bytes",0,4,SX_NONE),
};
const sx_layout sxgco_rgss_end3={UINT32_C(0x60400030),"rgss_end3",sxgco_rgss_end3_fields,SX_COUNT(sxgco_rgss_end3_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stos_header_fields[]={
 SX_FIELD("magic","char[10]",0,10,SX_SIGNATURE),
 SX_FIELD("bank_number","uint32",10,4,SX_ID),
 SX_FIELD("bank_type","uint8",14,1,SX_ID),
 SX_FIELD("encoded_bank_size","uint24",15,3,SX_NONE),
};
const sx_layout sxgco_stos_header={UINT32_C(0x60400031),"stos_header",sxgco_stos_header_fields,SX_COUNT(sxgco_stos_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_stos_sprite_fields[]={
 SX_FIELD("bank_id","uint32",0,4,SX_ID),
 SX_FIELD("low_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("medium_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("high_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("low_sprites","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("medium_sprites","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("high_sprites","uint16",20,2,SX_COUNT_PROP),
};
const sx_layout sxgco_stos_sprite={UINT32_C(0x60400032),"stos_sprite",sxgco_stos_sprite_fields,SX_COUNT(sxgco_stos_sprite_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_stos_sprite_param_fields[]={
 SX_FIELD("relative_data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("width_words","uint8",4,1,SX_NONE),
 SX_FIELD("height","uint8",5,1,SX_NONE),
 SX_FIELD("unknown06","bytes",6,2,SX_NONE),
};
const sx_layout sxgco_stos_sprite_param={UINT32_C(0x60400033),"stos_sprite_param",sxgco_stos_sprite_param_fields,SX_COUNT(sxgco_stos_sprite_param_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_stos_color_fields[]={
 SX_FIELD("color","uint16",0,2,SX_NONE),
};
const sx_layout sxgco_stos_color={UINT32_C(0x60400035),"stos_color",sxgco_stos_color_fields,SX_COUNT(sxgco_stos_color_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_npk2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","uint32",4,4,SX_NONE),
 SX_FIELD("iv","bytes",8,16,SX_NONE),
 SX_FIELD("entries","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("encrypted_index_bytes","uint32",28,4,SX_SIZE),
};
const sx_layout sxgco_npk2_header={UINT32_C(0x60400037),"npk2_header",sxgco_npk2_header_fields,SX_COUNT(sxgco_npk2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_kif_entry32_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_STRING),
 SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",36,4,SX_SIZE),
};
const sx_layout sxgco_kif_entry32={UINT32_C(0x60400039),"kif_entry32",sxgco_kif_entry32_fields,SX_COUNT(sxgco_kif_entry32_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_kif_entry64_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("data_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",68,4,SX_SIZE),
};
const sx_layout sxgco_kif_entry64={UINT32_C(0x6040003A),"kif_entry64",sxgco_kif_entry64_fields,SX_COUNT(sxgco_kif_entry64_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_malie_entry_fields[]={
 SX_FIELD("name","char[36]",0,36,SX_STRING),
 SX_FIELD("data_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("relative_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("unknown2c","bytes",44,4,SX_NONE),
};
const sx_layout sxgco_malie_entry={UINT32_C(0x6040003D),"malie_entry",sxgco_malie_entry_fields,SX_COUNT(sxgco_malie_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_malieu_entry_fields[]={
 SX_FIELD("name_utf16le","bytes",0,68,SX_NONE),
 SX_FIELD("data_bytes","uint32",68,4,SX_SIZE),
 SX_FIELD("relative_offset","int64",72,8,SX_OFFSET),
};
const sx_layout sxgco_malieu_entry={UINT32_C(0x6040003E),"malieu_entry",sxgco_malieu_entry_fields,SX_COUNT(sxgco_malieu_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("entries","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("index_end","uint32",12,4,SX_OFFSET),
 SX_FIELD("reserved","bytes",16,16,SX_RESERVED),
};
const sx_layout sxgco_ypf_header={UINT32_C(0x6040003F),"ypf_header",sxgco_ypf_header_fields,SX_COUNT(sxgco_ypf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_name_fields[]={
 SX_FIELD("name_hash","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("encoded_name_bytes","uint8",4,1,SX_NONE),
};
const sx_layout sxgco_ypf_name={UINT32_C(0x60400040),"ypf_name",sxgco_ypf_name_fields,SX_COUNT(sxgco_ypf_name_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_fields_fields[]={
 SX_FIELD("file_type","uint8",0,1,SX_ID),
 SX_FIELD("packed","uint8",1,1,SX_FLAGS),
 SX_FIELD("decoded_bytes","uint32",2,4,SX_SIZE),
 SX_FIELD("stored_bytes","uint32",6,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",10,4,SX_OFFSET),
 SX_FIELD("stored_checksum","uint32",14,4,SX_CHECKSUM),
};
const sx_layout sxgco_ypf_fields={UINT32_C(0x60400041),"ypf_fields",sxgco_ypf_fields_fields,SX_COUNT(sxgco_ypf_fields_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_offset_high_fields[]={
 SX_FIELD("data_offset_high","uint32",0,4,SX_NONE),
};
const sx_layout sxgco_ypf_offset_high={UINT32_C(0x60400043),"ypf_offset_high",sxgco_ypf_offset_high_fields,SX_COUNT(sxgco_ypf_offset_high_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_npa_fields_fields[]={
 SX_FIELD("entry_type","uint8",0,1,SX_ID),
 SX_FIELD("directory_id","int32",1,4,SX_ID),
 SX_FIELD("relative_offset","uint32",5,4,SX_OFFSET),
 SX_FIELD("stored_bytes","uint32",9,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",13,4,SX_SIZE),
};
const sx_layout sxgco_npa_fields={UINT32_C(0x60400046),"npa_fields",sxgco_npa_fields_fields,SX_COUNT(sxgco_npa_fields_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_qlie_footer_fields[]={
 SX_FIELD("magic","char[11]",0,11,SX_SIGNATURE),
 SX_FIELD("major","char[1]",11,1,SX_ID),
 SX_FIELD("dot","char[1]",12,1,SX_NONE),
 SX_FIELD("minor","char[1]",13,1,SX_ID),
 SX_FIELD("reserved","bytes",14,2,SX_RESERVED),
 SX_FIELD("entries","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("index_offset","uint64",20,8,SX_OFFSET),
};
const sx_layout sxgco_qlie_footer={UINT32_C(0x60400047),"qlie_footer",sxgco_qlie_footer_fields,SX_COUNT(sxgco_qlie_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_qlie_name_units_fields[]={
 SX_FIELD("name_units","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxgco_qlie_name_units={UINT32_C(0x60400048),"qlie_name_units",sxgco_qlie_name_units_fields,SX_COUNT(sxgco_qlie_name_units_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_qlie_entry_fields[]={
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("stored_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("packed","uint32",16,4,SX_FLAGS),
 SX_FIELD("encryption","uint32",20,4,SX_ID),
 SX_FIELD("ciphertext_hash","uint32",24,4,SX_CHECKSUM),
};
const sx_layout sxgco_qlie_entry={UINT32_C(0x60400049),"qlie_entry",sxgco_qlie_entry_fields,SX_COUNT(sxgco_qlie_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_cpk_utf_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("size_minus8","uint32",4,4,SX_NONE),
 SX_FIELD("encoding","uint16",8,2,SX_ID),
 SX_FIELD("rows_offset","uint16",10,2,SX_OFFSET),
 SX_FIELD("strings_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("table_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("columns","uint16",24,2,SX_COUNT_PROP),
 SX_FIELD("row_bytes","uint16",26,2,SX_SIZE),
 SX_FIELD("rows","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxgco_cpk_utf_header={UINT32_C(0x6040004B),"cpk_utf_header",sxgco_cpk_utf_header_fields,SX_COUNT(sxgco_cpk_utf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_cpk_utf_column_fields[]={
 SX_FIELD("storage_and_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint32",1,4,SX_OFFSET),
};
const sx_layout sxgco_cpk_utf_column={UINT32_C(0x6040004C),"cpk_utf_column",sxgco_cpk_utf_column_fields,SX_COUNT(sxgco_cpk_utf_column_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_cpk_crilayla_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("decoded_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_bytes","uint32",12,4,SX_SIZE),
};
const sx_layout sxgco_cpk_crilayla={UINT32_C(0x6040004D),"cpk_crilayla",sxgco_cpk_crilayla_fields,SX_COUNT(sxgco_cpk_crilayla_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_block_entry_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("file_data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("file_data_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("first_block","uint32",12,4,SX_ID),
 SX_FIELD("next_entry","uint32",16,4,SX_ID),
 SX_FIELD("previous_entry","uint32",20,4,SX_ID),
 SX_FIELD("directory_item","uint32",24,4,SX_ID),
};
const sx_layout sxgco_gcf_block_entry={UINT32_C(0x60400050),"gcf_block_entry",sxgco_gcf_block_entry_fields,SX_COUNT(sxgco_gcf_block_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_fragment_header_fields[]={
 SX_FIELD("blocks","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_unused_block","uint32",4,4,SX_ID),
 SX_FIELD("terminator","uint32",8,4,SX_ID),
 SX_FIELD("checksum","uint32",12,4,SX_CHECKSUM),
};
const sx_layout sxgco_gcf_fragment_header={UINT32_C(0x60400051),"gcf_fragment_header",sxgco_gcf_fragment_header_fields,SX_COUNT(sxgco_gcf_fragment_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_header_fields[]={
 SX_FIELD("unknown00","uint32",0,4,SX_NONE),
 SX_FIELD("cache_id","uint32",4,4,SX_ID),
 SX_FIELD("last_version_played","uint32",8,4,SX_ID),
 SX_FIELD("items","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("files","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("unknown14","uint32",20,4,SX_NONE),
 SX_FIELD("directory_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("name_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("info1_count","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("copy_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("local_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("unknown2c","uint32",44,4,SX_NONE),
 SX_FIELD("unknown30","uint32",48,4,SX_NONE),
 SX_FIELD("checksum","uint32",52,4,SX_CHECKSUM),
};
const sx_layout sxgco_gcf_directory_header={UINT32_C(0x60400055),"gcf_directory_header",sxgco_gcf_directory_header_fields,SX_COUNT(sxgco_gcf_directory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_file_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("checksum_index","uint32",8,4,SX_ID),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("parent_item","uint32",16,4,SX_ID),
 SX_FIELD("next_sibling","uint32",20,4,SX_ID),
 SX_FIELD("first_child","uint32",24,4,SX_ID),
};
const sx_layout sxgco_gcf_directory_file={UINT32_C(0x60400056),"gcf_directory_file",sxgco_gcf_directory_file_fields,SX_COUNT(sxgco_gcf_directory_file_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_folder_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("child_items","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("checksum_index","uint32",8,4,SX_ID),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("parent_item","uint32",16,4,SX_ID),
 SX_FIELD("next_sibling","uint32",20,4,SX_ID),
 SX_FIELD("first_child","uint32",24,4,SX_ID),
};
const sx_layout sxgco_gcf_directory_folder={UINT32_C(0x60400057),"gcf_directory_folder",sxgco_gcf_directory_folder_fields,SX_COUNT(sxgco_gcf_directory_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_data_header3_fields[]={
 SX_FIELD("blocks","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("block_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("first_block_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("used_blocks","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
};
const sx_layout sxgco_gcf_data_header3={UINT32_C(0x6040005B),"gcf_data_header3",sxgco_gcf_data_header3_fields,SX_COUNT(sxgco_gcf_data_header3_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_data_header5_fields[]={
 SX_FIELD("last_version_played","uint32",0,4,SX_ID),
 SX_FIELD("blocks","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("block_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("first_block_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("used_blocks","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("checksum","uint32",20,4,SX_CHECKSUM),
};
const sx_layout sxgco_gcf_data_header5={UINT32_C(0x6040005C),"gcf_data_header5",sxgco_gcf_data_header5_fields,SX_COUNT(sxgco_gcf_data_header5_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_directory_record_fields[]={
 SX_FIELD("tag","char[8]",0,8,SX_ID),
 SX_FIELD("body_bytes","int64",8,8,SX_SIZE),
};
const sx_layout sxgco_noa_directory_record={UINT32_C(0x6040005D),"noa_directory_record",sxgco_noa_directory_record_fields,SX_COUNT(sxgco_noa_directory_record_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stos_icon_fields[]={
 SX_FIELD("unknown00","bytes",0,4,SX_NONE),
 SX_FIELD("format_flags","uint16",4,2,SX_FLAGS),
 SX_FIELD("background","uint16",6,2,SX_NONE),
 SX_FIELD("foreground","uint16",8,2,SX_NONE),
};
const sx_layout sxgco_stos_icon={UINT32_C(0x6040005F),"stos_icon",sxgco_stos_icon_fields,SX_COUNT(sxgco_stos_icon_fields),SX_BE};
static const sx_layout *const sx_gamecontainers_layouts[]={
 &sxgco_filename_byte,
 &sxgco_encoded_byte,
 &sxgco_count16,
 &sxgco_offset32,
 &sxgco_size32,
 &sxgco_name_size32,
 &sxgco_krml_header,
 &sxgco_krml_entry,
 &sxgco_sci_header,
 &sxgco_sci_entry,
 &sxgco_seadata_header,
 &sxgco_seadata_entry,
 &sxgco_seadata_end,
 &sxgco_stk_entry,
 &sxgco_stk2_header,
 &sxgco_stk2_directory,
 &sxgco_stk2_entry,
 &sxgco_bth_header,
 &sxgco_battle_tct,
 &sxgco_battle_entry,
 &sxgco_mxs_entry,
 &sxgco_sinner_header,
 &sxgco_sinner_entry,
 &sxgco_res_entry,
 &sxgco_rsc_entry,
 &sxgco_vis_header_le,
 &sxgco_vis_header_be,
 &sxgco_vis_index_marker,
 &sxgco_vis_entry,
 &sxgco_bgi_header,
 &sxgco_bgi_entry,
 &sxgco_bgi2_entry,
 &sxgco_dxa_header1,
 &sxgco_dxa_header4,
 &sxgco_dxa_header6,
 &sxgco_livemaker_header,
 &sxgco_livemaker_offset,
 &sxgco_livemaker_flags,
 &sxgco_livemaker_scramble,
 &sxgco_noa_header,
 &sxgco_noa_record,
 &sxgco_noa_entry,
 &sxgco_rgss_header,
 &sxgco_rgss_seed,
 &sxgco_rgss_name_size,
 &sxgco_rgss_data_size,
 &sxgco_rgss_entry3,
 &sxgco_rgss_end3,
 &sxgco_stos_header,
 &sxgco_stos_sprite,
 &sxgco_stos_sprite_param,
 &sxgco_stos_palette_header,
 &sxgco_stos_color,
 &sxgco_stos_icon_header,
 &sxgco_npk2_header,
 &sxgco_kif_header,
 &sxgco_kif_entry32,
 &sxgco_kif_entry64,
 &sxgco_malie_header,
 &sxgco_malieu_header,
 &sxgco_malie_entry,
 &sxgco_malieu_entry,
 &sxgco_ypf_header,
 &sxgco_ypf_name,
 &sxgco_ypf_fields,
 &sxgco_ypf_extra8,
 &sxgco_ypf_offset_high,
 &sxgco_npa_header,
 &sxgco_npa_name_size,
 &sxgco_npa_fields,
 &sxgco_qlie_footer,
 &sxgco_qlie_name_units,
 &sxgco_qlie_entry,
 &sxgco_cpk_packet,
 &sxgco_cpk_utf_header,
 &sxgco_cpk_utf_column,
 &sxgco_cpk_crilayla,
 &sxgco_gcf_header,
 &sxgco_gcf_block_header,
 &sxgco_gcf_block_entry,
 &sxgco_gcf_fragment_header,
 &sxgco_gcf_block_link,
 &sxgco_gcf_map_header,
 &sxgco_gcf_map_entry,
 &sxgco_gcf_directory_header,
 &sxgco_gcf_directory_file,
 &sxgco_gcf_directory_folder,
 &sxgco_gcf_directory_map,
 &sxgco_gcf_directory_link,
 &sxgco_gcf_checksum_header,
 &sxgco_gcf_data_header3,
 &sxgco_gcf_data_header5,
 &sxgco_noa_directory_record,
 &sxgco_noa_count,
 &sxgco_stos_icon,
 &sxgco_gcf_info_word,
 &sxgco_gcf_directory_index,
 &sxgco_gcf_checksum_map_header,
 &sxgco_gcf_checksum_map_entry,
 &sxgco_gcf_checksum,
};
bool sxgco_span(sxgco_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
bool sxgco_read(sxgco_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return sxgco_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
bool sxgco_word(sxgco_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxgco_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
bool sxgco_row(sxgco_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxgco_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
bool sxgco_table(sxgco_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxgco_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxgco_row(v,l,at,end))return false;return true;}
static int sxgco_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxgco_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxgco_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxgco_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxgco_counted(sxgco_view*v,const sx_layout*l)
{uint64_t n,e=v->c->size;return GC_ROW(count16,0,e)&&sxgco_word(v,0,2,false,&n,e)&&sxgco_table(v,l,2,n,e);}
bool sxgco_bgi_common(sxgco_view*v,bool two)
{uint64_t n,e=v->c->size;return GC_ROW(bgi_header,0,e)&&sxgco_word(v,12,4,false,&n,e)&&sxgco_table(v,two?&sxgco_bgi2_entry:&sxgco_bgi_entry,16,n,e);}
static bool sx_gamecontainers_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_KRML:
case XX_FILE_TYPE_SCI:
case XX_FILE_TYPE_SEADATA:
case XX_FILE_TYPE_STK:
case XX_FILE_TYPE_BEATTHEHOUSE:
case XX_FILE_TYPE_BATTLEISLE:
case XX_FILE_TYPE_MXS:
case XX_FILE_TYPE_SINNER:
case XX_FILE_TYPE_MEGATECHVOL:
case XX_FILE_TYPE_RES:
case XX_FILE_TYPE_RSC:
case XX_FILE_TYPE_VISIONAIRE_STUDIO_VIS:
case XX_FILE_TYPE_BGI:
case XX_FILE_TYPE_BGI2:
case XX_FILE_TYPE_CPK:
case XX_FILE_TYPE_DXA:
case XX_FILE_TYPE_LIVEMAKER:
case XX_FILE_TYPE_NOA:
case XX_FILE_TYPE_RPG_MAKER_RGSSAD:
case XX_FILE_TYPE_STOS_MEMORY_BANK:
case XX_FILE_TYPE_VALVE_GCF_CACHE:
case XX_FILE_TYPE_YPF:
case XX_FILE_TYPE_NITROPLUS_NPK2:
case XX_FILE_TYPE_CATSYSTEM_KIF:
case XX_FILE_TYPE_MALIE_LIB:
case XX_FILE_TYPE_NITROPLUS_NPA:
case XX_FILE_TYPE_QLIE_PACK:
return true;default:return false;}}
static bool sx_gamecontainers_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxgco_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_KRML:ok=sx_krml_build(v);break;
case XX_FILE_TYPE_SCI:ok=sx_sci_build(v);break;
case XX_FILE_TYPE_SEADATA:ok=sx_seadata_build(v);break;
case XX_FILE_TYPE_STK:ok=sx_stk_build(v);break;
case XX_FILE_TYPE_BEATTHEHOUSE:ok=sx_beatthehouse_build(v);break;
case XX_FILE_TYPE_BATTLEISLE:ok=sx_battleisle_build(v);break;
case XX_FILE_TYPE_MXS:ok=sx_mxs_build(v);break;
case XX_FILE_TYPE_SINNER:ok=sx_sinner_build(v);break;
case XX_FILE_TYPE_MEGATECHVOL:ok=sx_megatechvol_build(v);break;
case XX_FILE_TYPE_RES:ok=sx_res_build(v);break;
case XX_FILE_TYPE_RSC:ok=sx_rsc_build(v);break;
case XX_FILE_TYPE_VISIONAIRE_STUDIO_VIS:ok=sx_visionaire_studio_vis_build(v);break;
case XX_FILE_TYPE_BGI:ok=sx_bgi_build(v);break;
case XX_FILE_TYPE_BGI2:ok=sx_bgi2_build(v);break;
case XX_FILE_TYPE_CPK:ok=sx_cpk_build(v);break;
case XX_FILE_TYPE_DXA:ok=sx_dxa_build(v);break;
case XX_FILE_TYPE_LIVEMAKER:ok=sx_livemaker_build(v);break;
case XX_FILE_TYPE_NOA:ok=sx_noa_build(v);break;
case XX_FILE_TYPE_RPG_MAKER_RGSSAD:ok=sx_rpg_maker_rgssad_build(v);break;
case XX_FILE_TYPE_STOS_MEMORY_BANK:ok=sx_stos_memory_bank_build(v);break;
case XX_FILE_TYPE_VALVE_GCF_CACHE:ok=sx_valve_gcf_cache_build(v);break;
case XX_FILE_TYPE_YPF:ok=sx_ypf_build(v);break;
case XX_FILE_TYPE_NITROPLUS_NPK2:ok=sx_nitroplus_npk2_build(v);break;
case XX_FILE_TYPE_CATSYSTEM_KIF:ok=sx_catsystem_kif_build(v);break;
case XX_FILE_TYPE_MALIE_LIB:ok=sx_malie_lib_build(v);break;
case XX_FILE_TYPE_NITROPLUS_NPA:ok=sx_nitroplus_npa_build(v);break;
case XX_FILE_TYPE_QLIE_PACK:ok=sx_qlie_pack_build(v);break;
default:break;}
 return ok&&sxgco_finish(c);}
#undef GC_ROW
static bool sx_gamecontainers_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<=UINT32_C(0x60400000)||id>=UINT32_C(0x60410000))return true;
 if(id==sxgco_filename_byte.id&&!xx_rt_wcscmp(r->name,L"byte"))return xx_data_struct_record_set_comment(r,L"Physical name/string-pool byte, including terminators; original encoding is preserved.");
 if(id==sxgco_encoded_byte.id&&!xx_rt_wcscmp(r->name,L"byte"))return xx_data_struct_record_set_comment(r,L"Original obfuscated filename byte; decoded text is not substituted for physical bytes.");
 if(id==sxgco_offset32.id&&!xx_rt_wcscmp(r->name,L"offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_krml_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_seadata_entry.id&&!xx_rt_wcscmp(r->name,L"next_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_stk_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_stk2_header.id&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_stk2_directory.id&&!xx_rt_wcscmp(r->name,L"metadata_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_stk2_entry.id&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_battle_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_mxs_entry.id&&!xx_rt_wcscmp(r->name,L"stored_bytes"))return xx_data_struct_record_set_comment(r,L"Stored member length includes the four-byte decoded-length word after the filename.");
 if(id==sxgco_sinner_entry.id&&!xx_rt_wcscmp(r->name,L"relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the end of the complete archive index.");
 if(id==sxgco_res_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_rsc_entry.id&&!xx_rt_wcscmp(r->name,L"dos_timestamp"))return xx_data_struct_record_set_comment(r,L"Packed DOS date high16 (year since1980,month4,day5) and time low16 (hour5,minute6,two-second count5).");
 if(id==sxgco_rsc_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_vis_index_marker.id&&!xx_rt_wcscmp(r->name,L"encrypted_marker"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_vis_entry.id&&!xx_rt_wcscmp(r->name,L"encrypted_relative_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_vis_entry.id&&!xx_rt_wcscmp(r->name,L"encrypted_stored_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_vis_entry.id&&!xx_rt_wcscmp(r->name,L"encrypted_decoded_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_vis_entry.id&&!xx_rt_wcscmp(r->name,L"encrypted_flags"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_bgi_entry.id&&!xx_rt_wcscmp(r->name,L"relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the end of the complete archive index.");
 if(id==sxgco_bgi2_entry.id&&!xx_rt_wcscmp(r->name,L"relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the end of the complete archive index.");
 if(id==sxgco_dxa_header1.id&&!xx_rt_wcscmp(r->name,L"encrypted_magic"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header1.id&&!xx_rt_wcscmp(r->name,L"encrypted_version"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header1.id&&!xx_rt_wcscmp(r->name,L"encrypted_index_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header1.id&&!xx_rt_wcscmp(r->name,L"encrypted_data_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header1.id&&!xx_rt_wcscmp(r->name,L"encrypted_index_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header1.id&&!xx_rt_wcscmp(r->name,L"encrypted_file_table_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header1.id&&!xx_rt_wcscmp(r->name,L"encrypted_directory_table_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header4.id&&!xx_rt_wcscmp(r->name,L"encrypted_magic"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header4.id&&!xx_rt_wcscmp(r->name,L"encrypted_version"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header4.id&&!xx_rt_wcscmp(r->name,L"encrypted_index_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header4.id&&!xx_rt_wcscmp(r->name,L"encrypted_data_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header4.id&&!xx_rt_wcscmp(r->name,L"encrypted_index_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header4.id&&!xx_rt_wcscmp(r->name,L"encrypted_file_table_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header4.id&&!xx_rt_wcscmp(r->name,L"encrypted_directory_table_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header4.id&&!xx_rt_wcscmp(r->name,L"encrypted_unknown18"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_magic"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_version"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_index_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_data_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_index_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_file_table_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_directory_table_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_codepage"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_dxa_header6.id&&!xx_rt_wcscmp(r->name,L"encrypted_unknown2c"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_livemaker_offset.id&&!xx_rt_wcscmp(r->name,L"encrypted_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_noa_entry.id&&!xx_rt_wcscmp(r->name,L"relative_record_offset"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the containing DirEntry record; may point backwards.");
 if(id==sxgco_noa_entry.id&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Stored eight-byte time metadata; retained verbatim because the native reader does not interpret its epoch.");
 if(id==sxgco_rgss_name_size.id&&!xx_rt_wcscmp(r->name,L"encrypted_name_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_rgss_data_size.id&&!xx_rt_wcscmp(r->name,L"encrypted_data_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_rgss_entry3.id&&!xx_rt_wcscmp(r->name,L"encrypted_data_offset"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_rgss_entry3.id&&!xx_rt_wcscmp(r->name,L"encrypted_data_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_rgss_entry3.id&&!xx_rt_wcscmp(r->name,L"encrypted_data_key"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_rgss_entry3.id&&!xx_rt_wcscmp(r->name,L"encrypted_name_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_rgss_end3.id&&!xx_rt_wcscmp(r->name,L"encrypted_terminator"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_stos_header.id&&!xx_rt_wcscmp(r->name,L"encoded_bank_size"))return xx_data_struct_record_set_comment(r,L"Stored low24-bit bank-size value; producers can round it to256 bytes and truncate it. Physical bounds come from the file.");
 if(id==sxgco_stos_sprite.id&&!xx_rt_wcscmp(r->name,L"low_offset"))return xx_data_struct_record_set_comment(r,L"Parameter-table byte offset relative to four bytes after the sprite-bank header start.");
 if(id==sxgco_stos_sprite.id&&!xx_rt_wcscmp(r->name,L"medium_offset"))return xx_data_struct_record_set_comment(r,L"Parameter-table byte offset relative to four bytes after the sprite-bank header start.");
 if(id==sxgco_stos_sprite.id&&!xx_rt_wcscmp(r->name,L"high_offset"))return xx_data_struct_record_set_comment(r,L"Parameter-table byte offset relative to four bytes after the sprite-bank header start.");
 if(id==sxgco_stos_sprite_param.id&&!xx_rt_wcscmp(r->name,L"relative_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this resolution's parameter-block group, not this individual parameter.");
 if(id==sxgco_stos_sprite_param.id&&!xx_rt_wcscmp(r->name,L"width_words"))return xx_data_struct_record_set_comment(r,L"Width in 16-pixel words.");
 if(id==sxgco_stos_sprite_param.id&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Height in pixels.");
 if(id==sxgco_stos_sprite_param.id&&!xx_rt_wcscmp(r->name,L"unknown06"))return xx_data_struct_record_set_comment(r,L"Two original bytes unused by the native sprite parser; no hotspot meaning is assumed.");
 if(id==sxgco_stos_color.id&&!xx_rt_wcscmp(r->name,L"color"))return xx_data_struct_record_set_comment(r,L"Stored Atari ST palette word; native rendering supports both9-bit and12-bit channel encodings.");
 if(id==sxgco_npk2_header.id&&!xx_rt_wcscmp(r->name,L"magic"))return xx_data_struct_record_set_comment(r,L"Encrypted NPK2 archive: clear-header metadata only; encrypted index and payload remain raw.");
 if(id==sxgco_npk2_header.id&&!xx_rt_wcscmp(r->name,L"unknown04"))return xx_data_struct_record_set_comment(r,L"Stored word written as 1 by the reference producer; no broader meaning is assumed.");
 if(id==sxgco_npk2_header.id&&!xx_rt_wcscmp(r->name,L"iv"))return xx_data_struct_record_set_comment(r,L"AES-CBC initialization vector used independently by the encrypted index and each segment.");
 if(id==sxgco_npk2_header.id&&!xx_rt_wcscmp(r->name,L"entries"))return xx_data_struct_record_set_comment(r,L"Declared encrypted-index record count; without a key it is not authenticated.");
 if(id==sxgco_npk2_header.id&&!xx_rt_wcscmp(r->name,L"encrypted_index_bytes"))return xx_data_struct_record_set_comment(r,L"Original encrypted bytes; neither decoded numeric values nor decoded offsets are substituted.");
 if(id==sxgco_kif_entry32.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_kif_entry64.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_malie_entry.id&&!xx_rt_wcscmp(r->name,L"relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of the immediate containing LIB/LIBU directory.");
 if(id==sxgco_malieu_entry.id&&!xx_rt_wcscmp(r->name,L"relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of the immediate containing LIB/LIBU directory.");
 if(id==sxgco_ypf_header.id&&!xx_rt_wcscmp(r->name,L"index_end"))return xx_data_struct_record_set_comment(r,L"Writer stores header32 plus index bytes; this is an archive-relative byte boundary.");
 if(id==sxgco_ypf_header.id&&!xx_rt_wcscmp(r->name,L"reserved"))return xx_data_struct_record_set_comment(r,L"Original16-byte header tail; normally zero, not enforced by the native reader.");
 if(id==sxgco_ypf_name.id&&!xx_rt_wcscmp(r->name,L"name_hash"))return xx_data_struct_record_set_comment(r,L"Stored resource-name lookup hash; not a payload checksum.");
 if(id==sxgco_ypf_name.id&&!xx_rt_wcscmp(r->name,L"encoded_name_bytes"))return xx_data_struct_record_set_comment(r,L"Name length is bitwise inverted, then transformed by a version-selected swap table.");
 if(id==sxgco_ypf_fields.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_ypf_fields.id&&!xx_rt_wcscmp(r->name,L"stored_checksum"))return xx_data_struct_record_set_comment(r,L"Stored payload checksum; not verified by the native reader.");
 if(id==sxgco_ypf_offset_high.id&&!xx_rt_wcscmp(r->name,L"data_offset_high"))return xx_data_struct_record_set_comment(r,L"Original extra32-bit entry word for newer versions; native parsing uses the preceding32-bit data offset and leaves this word uninterpreted.");
 if(id==sxgco_npa_fields.id&&!xx_rt_wcscmp(r->name,L"relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the end of the 41-byte header plus the complete index.");
 if(id==sxgco_qlie_footer.id&&!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_qlie_name_units.id&&!xx_rt_wcscmp(r->name,L"name_units"))return xx_data_struct_record_set_comment(r,L"Name length in bytes for1.0/2.0/3.0; UTF-16 code units for3.1.");
 if(id==sxgco_qlie_entry.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_qlie_entry.id&&!xx_rt_wcscmp(r->name,L"ciphertext_hash"))return xx_data_struct_record_set_comment(r,L"Stored hash over complete ciphertext qwords forversion3; older versions do not verify this field.");
 if(id==sxgco_cpk_utf_header.id&&!xx_rt_wcscmp(r->name,L"size_minus8"))return xx_data_struct_record_set_comment(r,L"Stored table length excludes the first eight bytes.");
 if(id==sxgco_cpk_utf_header.id&&!xx_rt_wcscmp(r->name,L"rows_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to eight bytes after this UTF table header start.");
 if(id==sxgco_cpk_utf_header.id&&!xx_rt_wcscmp(r->name,L"strings_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to eight bytes after this UTF table header start.");
 if(id==sxgco_cpk_utf_header.id&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to eight bytes after this UTF table header start.");
 if(id==sxgco_cpk_utf_header.id&&!xx_rt_wcscmp(r->name,L"table_name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset in this UTF table's string pool.");
 if(id==sxgco_cpk_utf_column.id&&!xx_rt_wcscmp(r->name,L"storage_and_type"))return xx_data_struct_record_set_comment(r,L"High nibble selects NONE/ZERO/CONSTANT/PER_ROW; low nibble selects UTF scalar/string/data type. Constant and row values remain raw.");
 if(id==sxgco_cpk_utf_column.id&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset in this UTF table's string pool.");
 if(id==sxgco_cpk_crilayla.id&&!xx_rt_wcscmp(r->name,L"decoded_bytes"))return xx_data_struct_record_set_comment(r,L"Decoded suffix size; the uncompressed prefix after the packed stream is additional output.");
 if(id==sxgco_gcf_block_entry.id&&!xx_rt_wcscmp(r->name,L"file_data_offset"))return xx_data_struct_record_set_comment(r,L"Logical byte offset within the extracted member, not the physical GCF file.");
 if(id==sxgco_gcf_fragment_header.id&&!xx_rt_wcscmp(r->name,L"terminator"))return xx_data_struct_record_set_comment(r,L"Stored fragmentation terminator selector:0 denotes0xFFFF,1 denotes0xFFFFFFFF; native compatibility preserves other values.");
 if(id==sxgco_gcf_directory_header.id&&!xx_rt_wcscmp(r->name,L"directory_bytes"))return xx_data_struct_record_set_comment(r,L"Stored directory extent; native readers accept header-inclusive and legacy header-exclusive variants when the following tables validate.");
 if(id==sxgco_gcf_directory_file.id&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset in the directory-name pool after all directory entries.");
 if(id==sxgco_gcf_directory_folder.id&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset in the directory-name pool after all directory entries.");
 if(id==sxgco_gcf_directory_folder.id&&!xx_rt_wcscmp(r->name,L"child_items"))return xx_data_struct_record_set_comment(r,L"Directory item count; the same physical word is a byte length for file entries.");
 if(id==sxgco_gcf_data_header3.id&&!xx_rt_wcscmp(r->name,L"first_block_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_gcf_data_header5.id&&!xx_rt_wcscmp(r->name,L"first_block_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the start of this archive.");
 if(id==sxgco_noa_directory_record.id&&!xx_rt_wcscmp(r->name,L"body_bytes"))return xx_data_struct_record_set_comment(r,L"Declared directory-body length; native compatibility may accept a body clipped by the physical file end.");
 if(id==sxgco_stos_icon.id&&!xx_rt_wcscmp(r->name,L"background"))return xx_data_struct_record_set_comment(r,L"Stored monochrome background-color selector; retained without inventing a palette mapping.");
 if(id==sxgco_stos_icon.id&&!xx_rt_wcscmp(r->name,L"foreground"))return xx_data_struct_record_set_comment(r,L"Stored monochrome foreground-color selector; retained without inventing a palette mapping.");
 if(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 if(id==sxgco_stk_entry.id&&!xx_rt_wcscmp(r->name,L"method")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"LZSS with a physical four-byte decoded-size prefix");
 default:break;}}
 if(id==sxgco_npa_fields.id&&!xx_rt_wcscmp(r->name,L"entry_type")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"Directory");
 case UINT64_C(2):return xx_data_struct_record_set_comment(r,L"File");
 default:break;}}
 if(id==sxgco_livemaker_flags.id&&!xx_rt_wcscmp(r->name,L"flags")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Zlib");
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(2):return xx_data_struct_record_set_comment(r,L"Chunk-scrambled");
 case UINT64_C(3):return xx_data_struct_record_set_comment(r,L"Chunk-scrambled then zlib");
 default:break;}}
 if(id==sxgco_stos_header.id&&!xx_rt_wcscmp(r->name,L"bank_type")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(1):return xx_data_struct_record_set_comment(r,L"Work");
 case UINT64_C(2):return xx_data_struct_record_set_comment(r,L"Screen");
 case UINT64_C(129):return xx_data_struct_record_set_comment(r,L"Data");
 case UINT64_C(130):return xx_data_struct_record_set_comment(r,L"Data screen");
 case UINT64_C(132):return xx_data_struct_record_set_comment(r,L"Set");
 case UINT64_C(133):return xx_data_struct_record_set_comment(r,L"Packed files");
 default:break;}}
 if(id==sxgco_noa_entry.id&&!xx_rt_wcscmp(r->name,L"attributes")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(16):return xx_data_struct_record_set_comment(r,L"Directory");
 case UINT64_C(32):return xx_data_struct_record_set_comment(r,L"End of directory");
 case UINT64_C(64):return xx_data_struct_record_set_comment(r,L"End of directory");
 default:break;}}
 if(id==sxgco_noa_entry.id&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(0):return xx_data_struct_record_set_comment(r,L"Stored");
 case UINT64_C(2147483664):return xx_data_struct_record_set_comment(r,L"ERISA/Nemesis coded");
 default:break;}}
 if(id==sxgco_sci_header.id&&!xx_rt_wcscmp(r->name,L"version")){switch(xx_var_get_u64(&r->value)){
 case UINT64_C(49):return xx_data_struct_record_set_comment(r,L"ASCII version1");
 case UINT64_C(50):return xx_data_struct_record_set_comment(r,L"ASCII version2");
 default:break;}}
 return true;}
const sx_family sx_gamecontainers_family={sx_gamecontainers_supports,sx_gamecontainers_build,sx_gamecontainers_layouts,SX_COUNT(sx_gamecontainers_layouts),sx_gamecontainers_comment};
