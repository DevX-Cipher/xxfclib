/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical game archive and index metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxgco_filename_byte_fields[]={
 SX_FIELD("byte","char[1]",0,1,SX_STRING),
};
static const sx_layout sxgco_filename_byte={UINT32_C(0x60400001),"filename_byte",sxgco_filename_byte_fields,SX_COUNT(sxgco_filename_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_encoded_byte_fields[]={
 SX_FIELD("byte","bytes",0,1,SX_NONE),
};
static const sx_layout sxgco_encoded_byte={UINT32_C(0x60400002),"encoded_byte",sxgco_encoded_byte_fields,SX_COUNT(sxgco_encoded_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_count16_fields[]={
 SX_FIELD("entries","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxgco_count16={UINT32_C(0x60400003),"count16",sxgco_count16_fields,SX_COUNT(sxgco_count16_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_offset32_fields[]={
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxgco_offset32={UINT32_C(0x60400004),"offset32",sxgco_offset32_fields,SX_COUNT(sxgco_offset32_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_size32_fields[]={
 SX_FIELD("bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgco_size32={UINT32_C(0x60400005),"size32",sxgco_size32_fields,SX_COUNT(sxgco_size32_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_name_size32_fields[]={
 SX_FIELD("name_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgco_name_size32={UINT32_C(0x60400006),"name_size32",sxgco_name_size32_fields,SX_COUNT(sxgco_name_size32_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_krml_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxgco_krml_header={UINT32_C(0x60400007),"krml_header",sxgco_krml_header_fields,SX_COUNT(sxgco_krml_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_krml_entry_fields[]={
 SX_FIELD("name","char[13]",0,13,SX_STRING),
 SX_FIELD("data_offset","int32",13,4,SX_OFFSET),
 SX_FIELD("data_bytes","int32",17,4,SX_SIZE),
};
static const sx_layout sxgco_krml_entry={UINT32_C(0x60400008),"krml_entry",sxgco_krml_entry_fields,SX_COUNT(sxgco_krml_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_sci_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("banner","char[42]",4,42,SX_STRING),
};
static const sx_layout sxgco_sci_header={UINT32_C(0x60400009),"sci_header",sxgco_sci_header_fields,SX_COUNT(sxgco_sci_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_sci_entry_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("name","char[50]",1,50,SX_STRING),
 SX_FIELD("data_bytes","int32",51,4,SX_SIZE),
};
static const sx_layout sxgco_sci_entry={UINT32_C(0x6040000A),"sci_entry",sxgco_sci_entry_fields,SX_COUNT(sxgco_sci_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_seadata_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxgco_seadata_header={UINT32_C(0x6040000B),"seadata_header",sxgco_seadata_header_fields,SX_COUNT(sxgco_seadata_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_seadata_entry_fields[]={
 SX_FIELD("tag","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("next_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("name_bytes","int32",8,4,SX_SIZE),
};
static const sx_layout sxgco_seadata_entry={UINT32_C(0x6040000C),"seadata_entry",sxgco_seadata_entry_fields,SX_COUNT(sxgco_seadata_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_seadata_end_fields[]={
 SX_FIELD("terminator","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxgco_seadata_end={UINT32_C(0x6040000D),"seadata_end",sxgco_seadata_end_fields,SX_COUNT(sxgco_seadata_end_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stk_entry_fields[]={
 SX_FIELD("name","char[13]",0,13,SX_STRING),
 SX_FIELD("stored_bytes","uint32",13,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",17,4,SX_OFFSET),
 SX_FIELD("method","uint8",21,1,SX_ID),
};
static const sx_layout sxgco_stk_entry={UINT32_C(0x6040000E),"stk_entry",sxgco_stk_entry_fields,SX_COUNT(sxgco_stk_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stk2_header_fields[]={
 SX_FIELD("magic","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("version","uint8",5,1,SX_ID),
 SX_FIELD("timestamp","char[14]",6,14,SX_STRING),
 SX_FIELD("creator","char[8]",20,8,SX_STRING),
 SX_FIELD("directory_offset","uint32",28,4,SX_OFFSET),
};
static const sx_layout sxgco_stk2_header={UINT32_C(0x6040000F),"stk2_header",sxgco_stk2_header_fields,SX_COUNT(sxgco_stk2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stk2_directory_fields[]={
 SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("metadata_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxgco_stk2_directory={UINT32_C(0x60400010),"stk2_directory",sxgco_stk2_directory_fields,SX_COUNT(sxgco_stk2_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stk2_entry_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unknown04","bytes",4,36,SX_NONE),
 SX_FIELD("stored_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",44,4,SX_SIZE),
 SX_FIELD("unknown30","bytes",48,13,SX_NONE),
};
static const sx_layout sxgco_stk2_entry={UINT32_C(0x60400011),"stk2_entry",sxgco_stk2_entry_fields,SX_COUNT(sxgco_stk2_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_bth_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("payload_kind","uint8",3,1,SX_ID),
 SX_FIELD("decoded_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxgco_bth_header={UINT32_C(0x60400012),"bth_header",sxgco_bth_header_fields,SX_COUNT(sxgco_bth_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_battle_tct_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("unknown","bytes",6,2,SX_NONE),
};
static const sx_layout sxgco_battle_tct={UINT32_C(0x60400013),"battle_tct",sxgco_battle_tct_fields,SX_COUNT(sxgco_battle_tct_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_battle_entry_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxgco_battle_entry={UINT32_C(0x60400014),"battle_entry",sxgco_battle_entry_fields,SX_COUNT(sxgco_battle_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_mxs_entry_fields[]={
 SX_FIELD("stored_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("name","char[13]",4,13,SX_STRING),
 SX_FIELD("decoded_bytes","uint32",17,4,SX_SIZE),
};
static const sx_layout sxgco_mxs_entry={UINT32_C(0x60400015),"mxs_entry",sxgco_mxs_entry_fields,SX_COUNT(sxgco_mxs_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_sinner_header_fields[]={
 SX_FIELD("magic","char[10]",0,10,SX_SIGNATURE),
 SX_FIELD("unknown","bytes",10,10,SX_NONE),
 SX_FIELD("entries","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxgco_sinner_header={UINT32_C(0x60400016),"sinner_header",sxgco_sinner_header_fields,SX_COUNT(sxgco_sinner_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_sinner_entry_fields[]={
 SX_FIELD("name","char[256]",0,256,SX_STRING),
 SX_FIELD("data_bytes","uint32",256,4,SX_SIZE),
 SX_FIELD("relative_offset","uint32",260,4,SX_OFFSET),
};
static const sx_layout sxgco_sinner_entry={UINT32_C(0x60400017),"sinner_entry",sxgco_sinner_entry_fields,SX_COUNT(sxgco_sinner_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_res_entry_fields[]={
 SX_FIELD("name_bytes","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_STRING),
 SX_FIELD("data_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",17,4,SX_SIZE),
 SX_FIELD("type","uint8",21,1,SX_ID),
};
static const sx_layout sxgco_res_entry={UINT32_C(0x60400018),"res_entry",sxgco_res_entry_fields,SX_COUNT(sxgco_res_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rsc_entry_fields[]={
 SX_FIELD("data_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",4,4,SX_NONE),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("name","char[13]",12,13,SX_STRING),
};
static const sx_layout sxgco_rsc_entry={UINT32_C(0x60400019),"rsc_entry",sxgco_rsc_entry_fields,SX_COUNT(sxgco_rsc_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_vis_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxgco_vis_header_le={UINT32_C(0x6040001A),"vis_header_le",sxgco_vis_header_le_fields,SX_COUNT(sxgco_vis_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_vis_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxgco_vis_header_be={UINT32_C(0x6040001B),"vis_header_be",sxgco_vis_header_be_fields,SX_COUNT(sxgco_vis_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_vis_index_marker_fields[]={
 SX_FIELD("encrypted_marker","bytes",0,3,SX_NONE),
};
static const sx_layout sxgco_vis_index_marker={UINT32_C(0x6040001C),"vis_index_marker",sxgco_vis_index_marker_fields,SX_COUNT(sxgco_vis_index_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_vis_entry_fields[]={
 SX_FIELD("encrypted_relative_offset","bytes",0,4,SX_NONE),
 SX_FIELD("encrypted_stored_bytes","bytes",4,4,SX_NONE),
 SX_FIELD("encrypted_decoded_bytes","bytes",8,4,SX_NONE),
 SX_FIELD("encrypted_flags","bytes",12,4,SX_NONE),
};
static const sx_layout sxgco_vis_entry={UINT32_C(0x6040001D),"vis_entry",sxgco_vis_entry_fields,SX_COUNT(sxgco_vis_entry_fields),SX_LE};
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
static const sx_layout sxgco_dxa_header1={UINT32_C(0x60400021),"dxa_header1",sxgco_dxa_header1_fields,SX_COUNT(sxgco_dxa_header1_fields),SX_LE};
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
static const sx_layout sxgco_dxa_header4={UINT32_C(0x60400022),"dxa_header4",sxgco_dxa_header4_fields,SX_COUNT(sxgco_dxa_header4_fields),SX_LE};
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
static const sx_layout sxgco_dxa_header6={UINT32_C(0x60400023),"dxa_header6",sxgco_dxa_header6_fields,SX_COUNT(sxgco_dxa_header6_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_livemaker_header_fields[]={
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint32",2,4,SX_ID),
 SX_FIELD("entries","uint32",6,4,SX_COUNT_PROP),
};
static const sx_layout sxgco_livemaker_header={UINT32_C(0x60400024),"livemaker_header",sxgco_livemaker_header_fields,SX_COUNT(sxgco_livemaker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_livemaker_offset_fields[]={
 SX_FIELD("encrypted_offset","bytes",0,8,SX_NONE),
};
static const sx_layout sxgco_livemaker_offset={UINT32_C(0x60400025),"livemaker_offset",sxgco_livemaker_offset_fields,SX_COUNT(sxgco_livemaker_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_livemaker_flags_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxgco_livemaker_flags={UINT32_C(0x60400026),"livemaker_flags",sxgco_livemaker_flags_fields,SX_COUNT(sxgco_livemaker_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_livemaker_scramble_fields[]={
 SX_FIELD("chunk_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("encoded_seed","uint32",4,4,SX_NONE),
};
static const sx_layout sxgco_livemaker_scramble={UINT32_C(0x60400027),"livemaker_scramble",sxgco_livemaker_scramble_fields,SX_COUNT(sxgco_livemaker_scramble_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("file_id","uint32",8,4,SX_ID),
 SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
 SX_FIELD("description","char[48]",16,48,SX_STRING),
};
static const sx_layout sxgco_noa_header={UINT32_C(0x60400028),"noa_header",sxgco_noa_header_fields,SX_COUNT(sxgco_noa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_record_fields[]={
 SX_FIELD("tag","char[8]",0,8,SX_ID),
 SX_FIELD("body_bytes","uint64",8,8,SX_SIZE),
};
static const sx_layout sxgco_noa_record={UINT32_C(0x60400029),"noa_record",sxgco_noa_record_fields,SX_COUNT(sxgco_noa_record_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_entry_fields[]={
 SX_FIELD("decoded_bytes","uint64",0,8,SX_SIZE),
 SX_FIELD("attributes","uint32",8,4,SX_FLAGS),
 SX_FIELD("encoding","uint32",12,4,SX_ID),
 SX_FIELD("relative_record_offset","int64",16,8,SX_OFFSET),
 SX_FIELD("timestamp","uint64",24,8,SX_NONE),
 SX_FIELD("extra_bytes","uint32",32,4,SX_SIZE),
};
static const sx_layout sxgco_noa_entry={UINT32_C(0x6040002A),"noa_entry",sxgco_noa_entry_fields,SX_COUNT(sxgco_noa_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_header_fields[]={
 SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("version","uint8",7,1,SX_ID),
};
static const sx_layout sxgco_rgss_header={UINT32_C(0x6040002B),"rgss_header",sxgco_rgss_header_fields,SX_COUNT(sxgco_rgss_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_seed_fields[]={
 SX_FIELD("seed","uint32",0,4,SX_NONE),
};
static const sx_layout sxgco_rgss_seed={UINT32_C(0x6040002C),"rgss_seed",sxgco_rgss_seed_fields,SX_COUNT(sxgco_rgss_seed_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_name_size_fields[]={
 SX_FIELD("encrypted_name_bytes","bytes",0,4,SX_NONE),
};
static const sx_layout sxgco_rgss_name_size={UINT32_C(0x6040002D),"rgss_name_size",sxgco_rgss_name_size_fields,SX_COUNT(sxgco_rgss_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_data_size_fields[]={
 SX_FIELD("encrypted_data_bytes","bytes",0,4,SX_NONE),
};
static const sx_layout sxgco_rgss_data_size={UINT32_C(0x6040002E),"rgss_data_size",sxgco_rgss_data_size_fields,SX_COUNT(sxgco_rgss_data_size_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_entry3_fields[]={
 SX_FIELD("encrypted_data_offset","bytes",0,4,SX_NONE),
 SX_FIELD("encrypted_data_bytes","bytes",4,4,SX_NONE),
 SX_FIELD("encrypted_data_key","bytes",8,4,SX_NONE),
 SX_FIELD("encrypted_name_bytes","bytes",12,4,SX_NONE),
};
static const sx_layout sxgco_rgss_entry3={UINT32_C(0x6040002F),"rgss_entry3",sxgco_rgss_entry3_fields,SX_COUNT(sxgco_rgss_entry3_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_end3_fields[]={
 SX_FIELD("encrypted_terminator","bytes",0,4,SX_NONE),
};
static const sx_layout sxgco_rgss_end3={UINT32_C(0x60400030),"rgss_end3",sxgco_rgss_end3_fields,SX_COUNT(sxgco_rgss_end3_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stos_header_fields[]={
 SX_FIELD("magic","char[10]",0,10,SX_SIGNATURE),
 SX_FIELD("bank_number","uint32",10,4,SX_ID),
 SX_FIELD("bank_type","uint8",14,1,SX_ID),
 SX_FIELD("encoded_bank_size","uint24",15,3,SX_NONE),
};
static const sx_layout sxgco_stos_header={UINT32_C(0x60400031),"stos_header",sxgco_stos_header_fields,SX_COUNT(sxgco_stos_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_stos_sprite_fields[]={
 SX_FIELD("bank_id","uint32",0,4,SX_ID),
 SX_FIELD("low_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("medium_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("high_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("low_sprites","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("medium_sprites","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("high_sprites","uint16",20,2,SX_COUNT_PROP),
};
static const sx_layout sxgco_stos_sprite={UINT32_C(0x60400032),"stos_sprite",sxgco_stos_sprite_fields,SX_COUNT(sxgco_stos_sprite_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_stos_sprite_param_fields[]={
 SX_FIELD("relative_data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("width_words","uint8",4,1,SX_NONE),
 SX_FIELD("height","uint8",5,1,SX_NONE),
 SX_FIELD("unknown06","bytes",6,2,SX_NONE),
};
static const sx_layout sxgco_stos_sprite_param={UINT32_C(0x60400033),"stos_sprite_param",sxgco_stos_sprite_param_fields,SX_COUNT(sxgco_stos_sprite_param_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_stos_palette_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxgco_stos_palette_header={UINT32_C(0x60400034),"stos_palette_header",sxgco_stos_palette_header_fields,SX_COUNT(sxgco_stos_palette_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stos_color_fields[]={
 SX_FIELD("color","uint16",0,2,SX_NONE),
};
static const sx_layout sxgco_stos_color={UINT32_C(0x60400035),"stos_color",sxgco_stos_color_fields,SX_COUNT(sxgco_stos_color_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_stos_icon_header_fields[]={
 SX_FIELD("bank_id","uint32",0,4,SX_ID),
 SX_FIELD("icons","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxgco_stos_icon_header={UINT32_C(0x60400036),"stos_icon_header",sxgco_stos_icon_header_fields,SX_COUNT(sxgco_stos_icon_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_npk2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","uint32",4,4,SX_NONE),
 SX_FIELD("iv","bytes",8,16,SX_NONE),
 SX_FIELD("entries","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("encrypted_index_bytes","uint32",28,4,SX_SIZE),
};
static const sx_layout sxgco_npk2_header={UINT32_C(0x60400037),"npk2_header",sxgco_npk2_header_fields,SX_COUNT(sxgco_npk2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_kif_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxgco_kif_header={UINT32_C(0x60400038),"kif_header",sxgco_kif_header_fields,SX_COUNT(sxgco_kif_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_kif_entry32_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_STRING),
 SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",36,4,SX_SIZE),
};
static const sx_layout sxgco_kif_entry32={UINT32_C(0x60400039),"kif_entry32",sxgco_kif_entry32_fields,SX_COUNT(sxgco_kif_entry32_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_kif_entry64_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("data_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",68,4,SX_SIZE),
};
static const sx_layout sxgco_kif_entry64={UINT32_C(0x6040003A),"kif_entry64",sxgco_kif_entry64_fields,SX_COUNT(sxgco_kif_entry64_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_malie_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","bytes",4,4,SX_NONE),
 SX_FIELD("entries","int16",8,2,SX_COUNT_PROP),
 SX_FIELD("unknown0a","bytes",10,6,SX_NONE),
};
static const sx_layout sxgco_malie_header={UINT32_C(0x6040003B),"malie_header",sxgco_malie_header_fields,SX_COUNT(sxgco_malie_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_malieu_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","bytes",4,4,SX_NONE),
 SX_FIELD("entries","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("unknown0c","bytes",12,4,SX_NONE),
};
static const sx_layout sxgco_malieu_header={UINT32_C(0x6040003C),"malieu_header",sxgco_malieu_header_fields,SX_COUNT(sxgco_malieu_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_malie_entry_fields[]={
 SX_FIELD("name","char[36]",0,36,SX_STRING),
 SX_FIELD("data_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("relative_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("unknown2c","bytes",44,4,SX_NONE),
};
static const sx_layout sxgco_malie_entry={UINT32_C(0x6040003D),"malie_entry",sxgco_malie_entry_fields,SX_COUNT(sxgco_malie_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_malieu_entry_fields[]={
 SX_FIELD("name_utf16le","bytes",0,68,SX_NONE),
 SX_FIELD("data_bytes","uint32",68,4,SX_SIZE),
 SX_FIELD("relative_offset","int64",72,8,SX_OFFSET),
};
static const sx_layout sxgco_malieu_entry={UINT32_C(0x6040003E),"malieu_entry",sxgco_malieu_entry_fields,SX_COUNT(sxgco_malieu_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("entries","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("index_end","uint32",12,4,SX_OFFSET),
 SX_FIELD("reserved","bytes",16,16,SX_RESERVED),
};
static const sx_layout sxgco_ypf_header={UINT32_C(0x6040003F),"ypf_header",sxgco_ypf_header_fields,SX_COUNT(sxgco_ypf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_name_fields[]={
 SX_FIELD("name_hash","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("encoded_name_bytes","uint8",4,1,SX_NONE),
};
static const sx_layout sxgco_ypf_name={UINT32_C(0x60400040),"ypf_name",sxgco_ypf_name_fields,SX_COUNT(sxgco_ypf_name_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_fields_fields[]={
 SX_FIELD("file_type","uint8",0,1,SX_ID),
 SX_FIELD("packed","uint8",1,1,SX_FLAGS),
 SX_FIELD("decoded_bytes","uint32",2,4,SX_SIZE),
 SX_FIELD("stored_bytes","uint32",6,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",10,4,SX_OFFSET),
 SX_FIELD("stored_checksum","uint32",14,4,SX_CHECKSUM),
};
static const sx_layout sxgco_ypf_fields={UINT32_C(0x60400041),"ypf_fields",sxgco_ypf_fields_fields,SX_COUNT(sxgco_ypf_fields_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_extra8_fields[]={
 SX_FIELD("extra","bytes",0,8,SX_NONE),
};
static const sx_layout sxgco_ypf_extra8={UINT32_C(0x60400042),"ypf_extra8",sxgco_ypf_extra8_fields,SX_COUNT(sxgco_ypf_extra8_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_ypf_offset_high_fields[]={
 SX_FIELD("data_offset_high","uint32",0,4,SX_NONE),
};
static const sx_layout sxgco_ypf_offset_high={UINT32_C(0x60400043),"ypf_offset_high",sxgco_ypf_offset_high_fields,SX_COUNT(sxgco_ypf_offset_high_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_npa_header_fields[]={
 SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("key1","uint32",7,4,SX_NONE),
 SX_FIELD("key2","uint32",11,4,SX_NONE),
 SX_FIELD("compressed","uint8",15,1,SX_FLAGS),
 SX_FIELD("encrypted","uint8",16,1,SX_FLAGS),
 SX_FIELD("entries","int32",17,4,SX_COUNT_PROP),
 SX_FIELD("directories","int32",21,4,SX_COUNT_PROP),
 SX_FIELD("files","int32",25,4,SX_COUNT_PROP),
 SX_FIELD("unknown1d","bytes",29,8,SX_NONE),
 SX_FIELD("index_bytes","uint32",37,4,SX_SIZE),
};
static const sx_layout sxgco_npa_header={UINT32_C(0x60400044),"npa_header",sxgco_npa_header_fields,SX_COUNT(sxgco_npa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_npa_name_size_fields[]={
 SX_FIELD("name_bytes","int32",0,4,SX_SIZE),
};
static const sx_layout sxgco_npa_name_size={UINT32_C(0x60400045),"npa_name_size",sxgco_npa_name_size_fields,SX_COUNT(sxgco_npa_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_npa_fields_fields[]={
 SX_FIELD("entry_type","uint8",0,1,SX_ID),
 SX_FIELD("directory_id","int32",1,4,SX_ID),
 SX_FIELD("relative_offset","uint32",5,4,SX_OFFSET),
 SX_FIELD("stored_bytes","uint32",9,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",13,4,SX_SIZE),
};
static const sx_layout sxgco_npa_fields={UINT32_C(0x60400046),"npa_fields",sxgco_npa_fields_fields,SX_COUNT(sxgco_npa_fields_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_qlie_footer_fields[]={
 SX_FIELD("magic","char[11]",0,11,SX_SIGNATURE),
 SX_FIELD("major","char[1]",11,1,SX_ID),
 SX_FIELD("dot","char[1]",12,1,SX_NONE),
 SX_FIELD("minor","char[1]",13,1,SX_ID),
 SX_FIELD("reserved","bytes",14,2,SX_RESERVED),
 SX_FIELD("entries","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("index_offset","uint64",20,8,SX_OFFSET),
};
static const sx_layout sxgco_qlie_footer={UINT32_C(0x60400047),"qlie_footer",sxgco_qlie_footer_fields,SX_COUNT(sxgco_qlie_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_qlie_name_units_fields[]={
 SX_FIELD("name_units","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxgco_qlie_name_units={UINT32_C(0x60400048),"qlie_name_units",sxgco_qlie_name_units_fields,SX_COUNT(sxgco_qlie_name_units_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_qlie_entry_fields[]={
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("stored_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("decoded_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("packed","uint32",16,4,SX_FLAGS),
 SX_FIELD("encryption","uint32",20,4,SX_ID),
 SX_FIELD("ciphertext_hash","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sxgco_qlie_entry={UINT32_C(0x60400049),"qlie_entry",sxgco_qlie_entry_fields,SX_COUNT(sxgco_qlie_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_cpk_packet_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("table_bytes","uint64",8,8,SX_SIZE),
};
static const sx_layout sxgco_cpk_packet={UINT32_C(0x6040004A),"cpk_packet",sxgco_cpk_packet_fields,SX_COUNT(sxgco_cpk_packet_fields),SX_LE};
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
static const sx_layout sxgco_cpk_utf_header={UINT32_C(0x6040004B),"cpk_utf_header",sxgco_cpk_utf_header_fields,SX_COUNT(sxgco_cpk_utf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_cpk_utf_column_fields[]={
 SX_FIELD("storage_and_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint32",1,4,SX_OFFSET),
};
static const sx_layout sxgco_cpk_utf_column={UINT32_C(0x6040004C),"cpk_utf_column",sxgco_cpk_utf_column_fields,SX_COUNT(sxgco_cpk_utf_column_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_cpk_crilayla_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("decoded_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_bytes","uint32",12,4,SX_SIZE),
};
static const sx_layout sxgco_cpk_crilayla={UINT32_C(0x6040004D),"cpk_crilayla",sxgco_cpk_crilayla_fields,SX_COUNT(sxgco_cpk_crilayla_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_header_fields[]={
 SX_FIELD("marker","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("major_version","uint32",4,4,SX_ID),
 SX_FIELD("minor_version","uint32",8,4,SX_ID),
 SX_FIELD("cache_id","uint32",12,4,SX_ID),
 SX_FIELD("last_version_played","uint32",16,4,SX_ID),
 SX_FIELD("unknown14","uint32",20,4,SX_NONE),
 SX_FIELD("unknown18","uint32",24,4,SX_NONE),
 SX_FIELD("file_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("block_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("blocks","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("unknown28","uint32",40,4,SX_NONE),
};
static const sx_layout sxgco_gcf_header={UINT32_C(0x6040004E),"gcf_header",sxgco_gcf_header_fields,SX_COUNT(sxgco_gcf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_block_header_fields[]={
 SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("used_entries","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("unknown08","bytes",8,20,SX_NONE),
 SX_FIELD("checksum","uint32",28,4,SX_CHECKSUM),
};
static const sx_layout sxgco_gcf_block_header={UINT32_C(0x6040004F),"gcf_block_header",sxgco_gcf_block_header_fields,SX_COUNT(sxgco_gcf_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_block_entry_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("file_data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("file_data_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("first_block","uint32",12,4,SX_ID),
 SX_FIELD("next_entry","uint32",16,4,SX_ID),
 SX_FIELD("previous_entry","uint32",20,4,SX_ID),
 SX_FIELD("directory_item","uint32",24,4,SX_ID),
};
static const sx_layout sxgco_gcf_block_entry={UINT32_C(0x60400050),"gcf_block_entry",sxgco_gcf_block_entry_fields,SX_COUNT(sxgco_gcf_block_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_fragment_header_fields[]={
 SX_FIELD("blocks","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_unused_block","uint32",4,4,SX_ID),
 SX_FIELD("terminator","uint32",8,4,SX_ID),
 SX_FIELD("checksum","uint32",12,4,SX_CHECKSUM),
};
static const sx_layout sxgco_gcf_fragment_header={UINT32_C(0x60400051),"gcf_fragment_header",sxgco_gcf_fragment_header_fields,SX_COUNT(sxgco_gcf_fragment_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_block_link_fields[]={
 SX_FIELD("next_block","uint32",0,4,SX_ID),
};
static const sx_layout sxgco_gcf_block_link={UINT32_C(0x60400052),"gcf_block_link",sxgco_gcf_block_link_fields,SX_COUNT(sxgco_gcf_block_link_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_map_header_fields[]={
 SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_entry","uint32",4,4,SX_ID),
 SX_FIELD("last_entry","uint32",8,4,SX_ID),
 SX_FIELD("unknown0c","uint32",12,4,SX_NONE),
 SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxgco_gcf_map_header={UINT32_C(0x60400053),"gcf_map_header",sxgco_gcf_map_header_fields,SX_COUNT(sxgco_gcf_map_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_map_entry_fields[]={
 SX_FIELD("previous_entry","uint32",0,4,SX_ID),
 SX_FIELD("next_entry","uint32",4,4,SX_ID),
};
static const sx_layout sxgco_gcf_map_entry={UINT32_C(0x60400054),"gcf_map_entry",sxgco_gcf_map_entry_fields,SX_COUNT(sxgco_gcf_map_entry_fields),SX_LE};
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
static const sx_layout sxgco_gcf_directory_header={UINT32_C(0x60400055),"gcf_directory_header",sxgco_gcf_directory_header_fields,SX_COUNT(sxgco_gcf_directory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_file_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("checksum_index","uint32",8,4,SX_ID),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("parent_item","uint32",16,4,SX_ID),
 SX_FIELD("next_sibling","uint32",20,4,SX_ID),
 SX_FIELD("first_child","uint32",24,4,SX_ID),
};
static const sx_layout sxgco_gcf_directory_file={UINT32_C(0x60400056),"gcf_directory_file",sxgco_gcf_directory_file_fields,SX_COUNT(sxgco_gcf_directory_file_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_folder_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("child_items","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("checksum_index","uint32",8,4,SX_ID),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("parent_item","uint32",16,4,SX_ID),
 SX_FIELD("next_sibling","uint32",20,4,SX_ID),
 SX_FIELD("first_child","uint32",24,4,SX_ID),
};
static const sx_layout sxgco_gcf_directory_folder={UINT32_C(0x60400057),"gcf_directory_folder",sxgco_gcf_directory_folder_fields,SX_COUNT(sxgco_gcf_directory_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_map_fields[]={
 SX_FIELD("unknown00","uint32",0,4,SX_NONE),
 SX_FIELD("unknown04","uint32",4,4,SX_NONE),
};
static const sx_layout sxgco_gcf_directory_map={UINT32_C(0x60400058),"gcf_directory_map",sxgco_gcf_directory_map_fields,SX_COUNT(sxgco_gcf_directory_map_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_link_fields[]={
 SX_FIELD("first_block_entry","uint32",0,4,SX_ID),
};
static const sx_layout sxgco_gcf_directory_link={UINT32_C(0x60400059),"gcf_directory_link",sxgco_gcf_directory_link_fields,SX_COUNT(sxgco_gcf_directory_link_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_checksum_header_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("checksum_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxgco_gcf_checksum_header={UINT32_C(0x6040005A),"gcf_checksum_header",sxgco_gcf_checksum_header_fields,SX_COUNT(sxgco_gcf_checksum_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_data_header3_fields[]={
 SX_FIELD("blocks","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("block_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("first_block_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("used_blocks","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
};
static const sx_layout sxgco_gcf_data_header3={UINT32_C(0x6040005B),"gcf_data_header3",sxgco_gcf_data_header3_fields,SX_COUNT(sxgco_gcf_data_header3_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_data_header5_fields[]={
 SX_FIELD("last_version_played","uint32",0,4,SX_ID),
 SX_FIELD("blocks","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("block_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("first_block_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("used_blocks","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("checksum","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxgco_gcf_data_header5={UINT32_C(0x6040005C),"gcf_data_header5",sxgco_gcf_data_header5_fields,SX_COUNT(sxgco_gcf_data_header5_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_directory_record_fields[]={
 SX_FIELD("tag","char[8]",0,8,SX_ID),
 SX_FIELD("body_bytes","int64",8,8,SX_SIZE),
};
static const sx_layout sxgco_noa_directory_record={UINT32_C(0x6040005D),"noa_directory_record",sxgco_noa_directory_record_fields,SX_COUNT(sxgco_noa_directory_record_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_noa_count_fields[]={
 SX_FIELD("entries","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxgco_noa_count={UINT32_C(0x6040005E),"noa_count",sxgco_noa_count_fields,SX_COUNT(sxgco_noa_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stos_icon_fields[]={
 SX_FIELD("unknown00","bytes",0,4,SX_NONE),
 SX_FIELD("format_flags","uint16",4,2,SX_FLAGS),
 SX_FIELD("background","uint16",6,2,SX_NONE),
 SX_FIELD("foreground","uint16",8,2,SX_NONE),
};
static const sx_layout sxgco_stos_icon={UINT32_C(0x6040005F),"stos_icon",sxgco_stos_icon_fields,SX_COUNT(sxgco_stos_icon_fields),SX_BE};
static const xx_data_struct_field_desc sxgco_gcf_info_word_fields[]={
 SX_FIELD("unknown","uint32",0,4,SX_NONE),
};
static const sx_layout sxgco_gcf_info_word={UINT32_C(0x60400060),"gcf_info_word",sxgco_gcf_info_word_fields,SX_COUNT(sxgco_gcf_info_word_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_directory_index_fields[]={
 SX_FIELD("directory_item","uint32",0,4,SX_ID),
};
static const sx_layout sxgco_gcf_directory_index={UINT32_C(0x60400061),"gcf_directory_index",sxgco_gcf_directory_index_fields,SX_COUNT(sxgco_gcf_directory_index_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_checksum_map_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("items","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("checksums","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxgco_gcf_checksum_map_header={UINT32_C(0x60400062),"gcf_checksum_map_header",sxgco_gcf_checksum_map_header_fields,SX_COUNT(sxgco_gcf_checksum_map_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_checksum_map_entry_fields[]={
 SX_FIELD("checksums","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_checksum","uint32",4,4,SX_ID),
};
static const sx_layout sxgco_gcf_checksum_map_entry={UINT32_C(0x60400063),"gcf_checksum_map_entry",sxgco_gcf_checksum_map_entry_fields,SX_COUNT(sxgco_gcf_checksum_map_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_gcf_checksum_fields[]={
 SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxgco_gcf_checksum={UINT32_C(0x60400064),"gcf_checksum",sxgco_gcf_checksum_fields,SX_COUNT(sxgco_gcf_checksum_fields),SX_LE};
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
/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxgco_view {sx_context*c;unsigned work;}sxgco_view;
static bool sxgco_span(sxgco_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxgco_read(sxgco_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return sxgco_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxgco_word(sxgco_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxgco_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxgco_row(sxgco_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxgco_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_table(sxgco_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxgco_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxgco_row(v,l,at,end))return false;return true;}
static int sxgco_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxgco_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxgco_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxgco_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxgco_npk2(sxgco_view*v)
{return GC_ROW(npk2_header,0,(uint64_t)v->c->size);}
static bool sxgco_krml(sxgco_view*v)
{uint64_t n,e=v->c->size;return GC_ROW(krml_header,0,e)&&sxgco_word(v,4,2,false,&n,e)&&sxgco_table(v,&sxgco_krml_entry,6,n,e);}
static bool sxgco_sci(sxgco_view*v)
{uint64_t p=46,e=v->c->size,n;bool ok=GC_ROW(sci_header,0,e);while(ok&&p<e){if(!sxgco_span(v,p,55,e))break;if(!GC_ROW(sci_entry,p,e)||!sxgco_word(v,p+51,4,false,&n,e))return false;p+=55;if(n>INT32_MAX||n>e-p)break;p+=n;}return ok;}
static bool sxgco_seadata(sxgco_view*v)
{uint64_t p=4,e=v->c->size,t,next,n;if(!GC_ROW(seadata_header,0,e))return false;while(p<e){if(!sxgco_word(v,p,4,false,&t,e))return false;if(!t)return GC_ROW(seadata_end,p,e);if(t!=UINT32_C(0x23324554)||!GC_ROW(seadata_entry,p,e)||!sxgco_word(v,p+4,4,false,&next,e)||!sxgco_word(v,p+8,4,false,&n,e)||next>INT32_MAX||n>INT32_MAX||next<=p||!sxgco_span(v,p+12,n+1,next)||!sxgco_table(v,&sxgco_filename_byte,p+12,n+1,next))return false;p=next;}return false;}
static bool sxgco_stk(sxgco_view*v)
{uint64_t e=v->c->size,n,at,meta,stored,plain,p=32;uint8_t h[6];if(!sxgco_read(v,0,h,6,e))return false;
 if(!xx_rt_memcmp(h,"STK2.",5)){if(!GC_ROW(stk2_header,0,e)||!sxgco_word(v,28,4,false,&at,e)||!GC_ROW(stk2_directory,at,e)||!sxgco_word(v,at,4,false,&n,e)||!sxgco_word(v,at+4,4,false,&meta,e)||meta<at+8||!sxgco_table(v,&sxgco_filename_byte,at+8,meta-at-8,e)||!sxgco_table(v,&sxgco_stk2_entry,meta,n,e))return false;
 for(uint64_t i=0;i<n;i++){if(!sxgco_word(v,meta+61*i+40,4,false,&stored,e)||!sxgco_word(v,meta+61*i+44,4,false,&plain,e)||!sxgco_span(v,p,stored,at))return false;if(stored>=4&&stored!=plain&&!GC_ROW(size32,p,at))return false;p+=stored;}return p==at;}
 if(!GC_ROW(count16,0,e)||!sxgco_word(v,0,2,false,&n,e)||!sxgco_table(v,&sxgco_stk_entry,2,n,e))return false;
 for(uint64_t i=0;i<n;i++){uint64_t method;if(!sxgco_word(v,2+i*22+17,4,false,&p,e)||!sxgco_word(v,2+i*22+21,1,false,&method,e))return false;if(method&&!GC_ROW(size32,p,e))return false;}return true;}
static bool sxgco_house(sxgco_view*v){return GC_ROW(bth_header,0,v->c->size);}
static bool sxgco_battle(sxgco_view*v)
{uint64_t e=v->c->size,at;uint8_t h[4];if(!GC_ROW(offset32,0,e)||!sxgco_word(v,0,4,false,&at,e)||at>e||(e-at)%12)return false;if(sxgco_read(v,4,h,4,e)&&!xx_rt_memcmp(h,"TCT ",4)&&!GC_ROW(battle_tct,4,e))return false;return sxgco_table(v,&sxgco_battle_entry,at,(e-at)/12,e);}
static bool sxgco_mxs(sxgco_view*v)
{uint64_t p=0,e=v->c->size,n;while(p<e){if(!GC_ROW(mxs_entry,p,e)||!sxgco_word(v,p,4,false,&n,e)||n<4||!sxgco_span(v,p+17,n,e))return false;p+=17+n;}return p==e;}
static bool sxgco_sinner(sxgco_view*v)
{uint64_t n,e=v->c->size;return GC_ROW(sinner_header,0,e)&&sxgco_word(v,20,4,false,&n,e)&&sxgco_table(v,&sxgco_sinner_entry,24,n,e);}
static bool sxgco_megavol(sxgco_view*v)
{uint64_t n,e=v->c->size;return sxgco_word(v,0,4,false,&n,e)&&n>=8&&!(n&3)&&sxgco_table(v,&sxgco_offset32,0,n/4,e);}
static bool sxgco_counted(sxgco_view*v,const sx_layout*l)
{uint64_t n,e=v->c->size;return GC_ROW(count16,0,e)&&sxgco_word(v,0,2,false,&n,e)&&sxgco_table(v,l,2,n,e);}
static bool sxgco_res(sxgco_view*v){return sxgco_counted(v,&sxgco_res_entry);}
static bool sxgco_rsc(sxgco_view*v){return sxgco_counted(v,&sxgco_rsc_entry);}
static bool sxgco_vis(sxgco_view*v)
{uint64_t n,b,e=v->c->size;if(!sxgco_word(v,4,4,false,&n,e)||!sxgco_word(v,4,4,true,&b,e))return false;bool be=b<n;if(be)n=b;return sxgco_row(v,be?&sxgco_vis_header_be:&sxgco_vis_header_le,0,e)&&GC_ROW(vis_index_marker,8,e)&&sxgco_table(v,&sxgco_vis_entry,11,n,e)&&n<=(UINT64_MAX-11)/16&&GC_ROW(vis_index_marker,11+16*n,e);}
static bool sxgco_bgi_common(sxgco_view*v,bool two)
{uint64_t n,e=v->c->size;return GC_ROW(bgi_header,0,e)&&sxgco_word(v,12,4,false,&n,e)&&sxgco_table(v,two?&sxgco_bgi2_entry:&sxgco_bgi_entry,16,n,e);}
static bool sxgco_bgi(sxgco_view*v){return sxgco_bgi_common(v,false);}
static bool sxgco_bgi2(sxgco_view*v){return sxgco_bgi_common(v,true);}
static bool sxgco_dxa(sxgco_view*v)
{unsigned version=(unsigned char)v->c->f->version[0]-'0';if(version>=1&&version<=3)return GC_ROW(dxa_header1,0,v->c->size);if(version==4)return GC_ROW(dxa_header4,0,v->c->size);if(version==6)return GC_ROW(dxa_header6,0,v->c->size);return false;}
static bool sxgco_lm(sxgco_view*v)
{uint64_t p=10,n,z,e=v->c->size;if(!GC_ROW(livemaker_header,0,e)||!sxgco_word(v,6,4,false,&n,e)||n>UINT32_C(0x40000))return false;
 for(uint64_t i=0;i<n;i++){if(!GC_ROW(name_size32,p,e)||!sxgco_word(v,p,4,false,&z,e)||!z||z>256||!sxgco_table(v,&sxgco_encoded_byte,p+4,z,e))return false;p+=4+z;}
 if(!sxgco_table(v,&sxgco_livemaker_offset,p,n+1,e))return false;uint64_t offsets=p,flags=p+(n+1)*8;if(!sxgco_table(v,&sxgco_livemaker_flags,flags,n,e))return false;
 uint32_t state=0;uint64_t previous=0;for(uint64_t i=0;i<=n;i++){uint64_t raw,flag;state=state*5U+UINT32_C(0x75d6ee39);uint64_t mask=(uint64_t)state;if(state&UINT32_C(0x80000000))mask|=UINT64_C(0xffffffff00000000);if(!sxgco_word(v,offsets+i*8,8,false,&raw,e))return false;raw^=mask;if(raw>e||(i&&raw<previous))return false;if(i){if(!sxgco_word(v,flags+i-1,1,false,&flag,e))return false;if((flag==2||flag==3)&&raw-previous>=8&&!GC_ROW(livemaker_scramble,previous,raw))return false;}previous=raw;}return true;}
static bool sxgco_rgss(sxgco_view*v)
{uint64_t e=v->c->size,p=8,x,n,off,version;uint32_t key=UINT32_C(0xDEADCAFE);if(!GC_ROW(rgss_header,0,e)||!sxgco_word(v,7,1,false,&version,e))return false;
 if(version==1){while(p<e){if(!GC_ROW(rgss_name_size,p,e)||!sxgco_word(v,p,4,false,&x,e))return false;n=(uint32_t)x^key;key=key*7U+3U;p+=4;if(!n||n>1024||!sxgco_table(v,&sxgco_encoded_byte,p,n,e))return false;p+=n;for(uint64_t i=0;i<n;i++)key=key*7U+3U;if(!GC_ROW(rgss_data_size,p,e)||!sxgco_word(v,p,4,false,&x,e))return false;n=(uint32_t)x^key;key=key*7U+3U;p+=4;if(!sxgco_span(v,p,n,e))return false;p+=n;}return true;}
 if(version!=3||!GC_ROW(rgss_seed,8,e)||!sxgco_word(v,8,4,false,&x,e))return false;key=(uint32_t)x*9U+3U;p=12;
 while(p<e){if(!sxgco_word(v,p,4,false,&off,e))return false;off=(uint32_t)off^key;if(!off)return GC_ROW(rgss_end3,p,e);if(!GC_ROW(rgss_entry3,p,e)||!sxgco_word(v,p+12,4,false,&x,e))return false;n=(uint32_t)x^key;if(!n||n>1024||!sxgco_table(v,&sxgco_encoded_byte,p+16,n,e))return false;p+=16+n;}return false;}
static bool sxgco_npa(sxgco_view*v)
{uint64_t e=v->c->size,n,z,end,p=41;if(!GC_ROW(npa_header,0,e)||!sxgco_word(v,17,4,false,&n,e)||!sxgco_word(v,37,4,false,&end,e)||!sxgco_span(v,41,end,e)||n>UINT32_C(0xfffff))return false;end+=41;
 for(uint64_t i=0;i<n;i++){if(!GC_ROW(npa_name_size,p,end)||!sxgco_word(v,p,4,false,&z,end)||!z||z>4096||!sxgco_table(v,&sxgco_encoded_byte,p+4,z,end)||!GC_ROW(npa_fields,p+4+z,end))return false;p+=21+z;}return p==end;}
static bool sxgco_qlie(sxgco_view*v)
{uint64_t e=v->c->size,p,n,z,major,minor;if(e<28||!GC_ROW(qlie_footer,e-28,e)||!sxgco_word(v,e-12,4,false,&n,e)||!sxgco_word(v,e-8,8,false,&p,e)||!sxgco_word(v,e-17,1,false,&major,e)||!sxgco_word(v,e-15,1,false,&minor,e)||n>UINT32_C(0xfffff))return false;
 uint64_t bound=e-28;bool unicode=major=='3'&&minor=='1';if(major=='3'){if(e<0x440)return false;bound=e-0x440;}if(major=='1')return true;
 for(uint64_t i=0;i<n;i++){if(!GC_ROW(qlie_name_units,p,bound)||!sxgco_word(v,p,2,false,&z,bound)||!z||z>256)return false;if(unicode)z*=2;if(!sxgco_table(v,&sxgco_encoded_byte,p+2,z,bound)||!GC_ROW(qlie_entry,p+2+z,bound))return false;p+=30+z;}return true;}
static bool sxgco_stos(sxgco_view*v)
{uint64_t e=v->c->size,p=0,id,n,total=0,off;uint8_t magic[10];if(!sxgco_read(v,0,magic,10,e))return false;
 if(!xx_rt_memcmp(magic,"Lionpoubnk",10)){if(!GC_ROW(stos_header,0,e))return false;p=18;uint64_t type;if(!sxgco_word(v,14,1,false,&type,e))return false;if(type!=0x81)return true;}
 if(!sxgco_word(v,p,4,true,&id,e))return false;
 if(id==UINT32_C(0x19861987)){if(!GC_ROW(stos_sprite,p,e))return false;
 for(unsigned i=0;i<3;i++){if(!sxgco_word(v,p+16+2*i,2,true,&n,e)||!sxgco_word(v,p+4+4*i,4,true,&off,e))return false;total+=n;off+=p+4;if(sxgco_span(v,off,n*8,e)&&!sxgco_table(v,&sxgco_stos_sprite_param,off,n,e))return false;}
 uint64_t pal=p+22+total*8;if(sxgco_word(v,pal,4,true,&id,e)&&id==UINT32_C(0x50414c54))return GC_ROW(stos_palette_header,pal,e)&&sxgco_table(v,&sxgco_stos_color,pal+4,16,e);return true;}
 if(id==UINT32_C(0x28091960)){if(!GC_ROW(stos_icon_header,p,e)||!sxgco_word(v,p+4,2,true,&n,e)||!sxgco_span(v,p+6,n*84,e))return false;for(uint64_t i=0;i<n;i++)if(!GC_ROW(stos_icon,p+6+i*84,e))return false;}return true;}
static bool sxgco_noa_dir(sxgco_view*v,uint64_t p,uint64_t end,unsigned depth)
{uint64_t length,n,at,attr,relative,extra,z;uint8_t tag[8];if(depth>32||!sxgco_read(v,p,tag,8,end)||xx_rt_memcmp(tag,"DirEntry",8)||!GC_ROW(noa_directory_record,p,end)||!sxgco_word(v,p+8,8,false,&length,end)||length>INT32_MAX)return false;
 uint64_t limit=end-p-16;if(length<limit)limit=length;limit+=p+16;if(!GC_ROW(noa_count,p+16,limit)||!sxgco_word(v,p+16,4,false,&n,limit))return false;if(n>INT32_MAX)return true;at=p+20;
 for(uint64_t i=0;i<n;i++){if(!GC_ROW(noa_entry,at,limit)||!sxgco_word(v,at+8,4,false,&attr,limit)||!sxgco_word(v,at+16,8,false,&relative,limit)||!sxgco_word(v,at+32,4,false,&extra,limit))return false;at+=36;if(!sxgco_span(v,at,extra,limit))return false;at+=extra;if(!GC_ROW(name_size32,at,limit)||!sxgco_word(v,at,4,false,&z,limit)||z>0x10000||!sxgco_table(v,&sxgco_filename_byte,at+4,z,limit))return false;at+=4+z;
 if(attr==0x20||attr==0x40)break;uint64_t target;bool valid;if(relative>>63){uint64_t back=(~relative)+1;valid=back<=p;target=valid?p-back:0;}else{valid=relative<=end-p;target=valid?p+relative:0;}
 if(valid&&sxgco_span(v,target,16,end)){if(!GC_ROW(noa_record,target,end))return false;if(attr==0x10&&!sxgco_noa_dir(v,target+16,end,depth+1))return false;}}
 return true;}
static bool sxgco_noa(sxgco_view*v){return GC_ROW(noa_header,0,v->c->size)&&sxgco_noa_dir(v,64,v->c->size,0);}
static bool sxgco_malie_dir(sxgco_view*v,uint64_t p,uint64_t end,unsigned depth)
{uint8_t magic[4];uint64_t n,stride,namez,at,off,z;bool u;if(depth>=64||!sxgco_read(v,p,magic,4,end))return false;u=!xx_rt_memcmp(magic,"LIBU",4);if(!u&&xx_rt_memcmp(magic,"LIB\0",4))return true;
 if(!sxgco_word(v,p+8,u?4:2,false,&n,end)||!n||n>UINT32_C(0xfffff)||(!u&&n>=0x8000)||n>INT32_MAX)return true;stride=u?80:48;namez=u?68:36;if(!sxgco_span(v,p,16+n*stride,end))return true;
 /* Check the entire immediate index before interpreting a possible nested
  * resource as a directory; native LIB keeps malformed children opaque. */
 for(uint64_t i=0;i<n;i++){at=p+16+i*stride;if(!sxgco_word(v,at+namez,4,false,&z,end)||!sxgco_word(v,at+namez+4,u?8:4,false,&off,end)||off<16+n*stride||off>end-p||z>end-p-off)return true;}
 if(!sxgco_row(v,u?&sxgco_malieu_header:&sxgco_malie_header,p,end)||!sxgco_table(v,u?&sxgco_malieu_entry:&sxgco_malie_entry,p+16,n,end))return false;
 for(uint64_t i=0;i<n;i++){at=p+16+i*stride;uint8_t name[68];if(!sxgco_read(v,at,name,(size_t)namez,end)||!sxgco_word(v,at+namez,4,false,&z,end)||!sxgco_word(v,at+namez+4,u?8:4,false,&off,end))return false;bool dot=false;for(unsigned j=0;j<namez;j+=u?2:1){unsigned c=name[j]|(u?(unsigned)name[j+1]<<8:0);if(!c)break;if(c=='.')dot=true;}if(!dot&&z>=4&&!sxgco_malie_dir(v,p+off,p+off+z,depth+1))return false;}return true;}
static bool sxgco_malie(sxgco_view*v){return sxgco_malie_dir(v,0,v->c->size,0);}
static bool sxgco_ypf(sxgco_view*v)
{uint64_t e=v->c->size,version;if(!GC_ROW(ypf_header,0,e)||!sxgco_word(v,4,4,false,&version,e))return false;
 Abstractformat*f=v->c->f;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,v->c->pd);if(!s)return false;bool ok=true;unsigned count=0;
 do{const xx_archive_record*r=xx_format_get_current_archive_record(f,s);if(!r)break;if(++count>UINT32_C(0xfffff)||r->header_offset<f->base_address||r->header_size<24){ok=false;break;}uint64_t at=(uint64_t)(r->header_offset-f->base_address),n=(uint64_t)r->header_size-23;
 if(!GC_ROW(ypf_name,at,e)||!sxgco_table(v,&sxgco_encoded_byte,at+5,n,e)||!GC_ROW(ypf_fields,at+5+n,e)){ok=false;break;}at+=(uint64_t)r->header_size;if(version>=0x1d9)ok=GC_ROW(ypf_offset_high,at,e);else if(version==0xde)ok=GC_ROW(ypf_extra8,at,e);if(!ok)break;
 }while(xx_format_archive_record_move_to_next(f,s,v->c->pd));xx_format_free_archive_records_reading(f,s);return ok&&!xx_pd_is_stopped(v->c->pd);}
static bool sxgco_kif(sxgco_view*v)
{uint64_t e=v->c->size,n;if(!GC_ROW(kif_header,0,e)||!sxgco_word(v,4,4,false,&n,e)||n>UINT32_C(0xfffff))return false;uint8_t name[11];if(sxgco_read(v,8,name,11,e)&&!xx_rt_memcmp(name,"__key__.dat",11))return true;
 Abstractformat*f=v->c->f;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,v->c->pd);if(!s)return false;const xx_archive_record*r=xx_format_get_current_archive_record(f,s);int64_t size=r?r->header_size:0;xx_format_free_archive_records_reading(f,s);if(size!=40&&size!=72)return false;return sxgco_table(v,size==40?&sxgco_kif_entry32:&sxgco_kif_entry64,8,n,e);}
static bool sxgco_cpk_utf(sxgco_view*v,uint64_t at,uint64_t size,uint64_t packets[2],unsigned depth)
{uint64_t end=at+size,declared,rows,strings,data,cols,width,count,p,rowpos=0;uint8_t sig[4];if(depth>4||!sxgco_span(v,at,size,v->c->size)||size<32||!sxgco_read(v,at,sig,4,end))return false;
 /* XOR-obfuscated table bytes are retained verbatim. There are no physical
  * clear columns or offsets to display inside that byte stream. */
 if(xx_rt_memcmp(sig,"@UTF",4))return true;
 if(!GC_ROW(cpk_utf_header,at,end)||!sxgco_word(v,at+4,4,true,&declared,end)||declared+8>size||!sxgco_word(v,at+10,2,true,&rows,end)||!sxgco_word(v,at+12,4,true,&strings,end)||!sxgco_word(v,at+16,4,true,&data,end)||!sxgco_word(v,at+24,2,true,&cols,end)||!sxgco_word(v,at+26,2,true,&width,end)||!sxgco_word(v,at+28,4,true,&count,end)||!cols||cols>256||count>UINT32_C(0x100000))return false;
 end=at+8+declared;rows+=at+8;strings+=at+8;data+=at+8;if(rows<at+32||strings<rows||data<strings||data>end||(count&&(width>(strings-rows)/count)))return false;p=at+32;
 for(uint64_t i=0;i<cols;i++){uint64_t flags,no,value=0,cell=0,z;char name[32];if(!GC_ROW(cpk_utf_column,p,rows)||!sxgco_word(v,p,1,false,&flags,rows)||!sxgco_word(v,p+1,4,true,&no,rows))return false;unsigned type=(unsigned)flags&15,storage=(unsigned)flags&0xf0;static const uint8_t sizes[12]={1,1,2,2,4,4,8,8,4,8,4,8};if(type>11||no>=data-strings)return false;z=sizes[type];p+=5;
 if(storage==0x30){cell=p;if(!sxgco_span(v,p,z,rows))return false;p+=z;}else if(storage==0x50){if(z>width-rowpos)return false;cell=rows+rowpos;rowpos+=z;}else if(storage!=0x10&&storage!=0)return false;
 uint64_t q=strings+no;unsigned j=0;for(;j<sizeof(name)-1&&q+j<data;j++){uint64_t c;if(!sxgco_word(v,q+j,1,false,&c,data))return false;name[j]=(char)c;if(!c)break;}name[j]=0;
 if(cell&&count&&type<8&&!sxgco_word(v,cell,(unsigned)z,true,&value,end))return false;
 if(packets&&count&&type<8){if(!xx_rt_strcmp(name,"TocOffset"))packets[0]=value;else if(!xx_rt_strcmp(name,"ItocOffset"))packets[1]=value;}
 if(cell&&count&&type==11&&(!xx_rt_strcmp(name,"DataL")||!xx_rt_strcmp(name,"DataH"))){uint64_t off,len;if(!sxgco_word(v,cell,4,true,&off,end)||!sxgco_word(v,cell+4,4,true,&len,end)||off>end-data||len>end-data-off)return false;if(len&&!sxgco_cpk_utf(v,data+off,len,NULL,depth+1))return false;}}
 return sxgco_table(v,&sxgco_filename_byte,strings,data-strings,end);}
static bool sxgco_cpk_parse_packet(sxgco_view*v,uint64_t at,uint64_t pointers[2])
{uint64_t z,e=v->c->size;return GC_ROW(cpk_packet,at,e)&&sxgco_word(v,at+8,8,false,&z,e)&&sxgco_span(v,at+16,z,e)&&sxgco_cpk_utf(v,at+16,z,pointers,0);}
static bool sxgco_cpk(sxgco_view*v)
{uint64_t refs[2]={0,0},e=v->c->size;if(!sxgco_cpk_parse_packet(v,0,refs))return false;for(unsigned i=0;i<2;i++)if(refs[i]&&refs[i]!=UINT64_MAX){uint8_t tag[4];if(!sxgco_read(v,refs[i],tag,4,e)||xx_rt_memcmp(tag,i?"ITOC":"TOC ",4)||!sxgco_cpk_parse_packet(v,refs[i],NULL))return false;}
 Abstractformat*f=v->c->f;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,v->c->pd);if(!s)return true;bool ok=true;unsigned count=0;
 do{const xx_archive_record*r=xx_format_get_current_archive_record(f,s);if(!r)break;if(++count>UINT32_C(0x100000)){ok=false;break;}if(r->data_offset<f->base_address||r->compressed_size<16)continue;uint64_t at=(uint64_t)(r->data_offset-f->base_address);uint8_t h[8];if(sxgco_read(v,at,h,8,e)&&!xx_rt_memcmp(h,"CRILAYLA",8)&&!GC_ROW(cpk_crilayla,at,e)){ok=false;break;}
 }while(xx_format_archive_record_move_to_next(f,s,v->c->pd));xx_format_free_archive_records_reading(f,s);return ok&&!xx_pd_is_stopped(v->c->pd);}
static bool sxgco_gcf(sxgco_view*v)
{uint64_t e=v->c->size,minor,blocks,blocksize,p=44,n,names,info,copies,locals,dirsize,dir,needed,map=0,check=0,datahead=0,dhsize;
 if(!GC_ROW(gcf_header,0,e)||!sxgco_word(v,8,4,false,&minor,e)||!sxgco_word(v,32,4,false,&blocksize,e)||!sxgco_word(v,36,4,false,&blocks,e)||blocks>UINT32_C(0x1000000)||!GC_ROW(gcf_block_header,p,e))return false;p+=32;
 if(!sxgco_table(v,&sxgco_gcf_block_entry,p,blocks,e))return false;p+=28*blocks;if(!GC_ROW(gcf_fragment_header,p,e))return false;p+=16;if(!sxgco_table(v,&sxgco_gcf_block_link,p,blocks,e))return false;p+=4*blocks;
 if(minor<6){if(!GC_ROW(gcf_map_header,p,e))return false;p+=20;if(!sxgco_table(v,&sxgco_gcf_map_entry,p,blocks,e))return false;p+=8*blocks;}
 dir=p;if(!GC_ROW(gcf_directory_header,p,e)||!sxgco_word(v,p+12,4,false,&n,e)||!sxgco_word(v,p+24,4,false,&dirsize,e)||!sxgco_word(v,p+28,4,false,&names,e)||!sxgco_word(v,p+32,4,false,&info,e)||!sxgco_word(v,p+36,4,false,&copies,e)||!sxgco_word(v,p+40,4,false,&locals,e)||!n||n>UINT32_C(0x100000))return false;
 needed=56+n*28+names+4*(info+n+copies+locals);if(!sxgco_span(v,dir,needed,e)||!sxgco_table(v,&sxgco_filename_byte,dir+56+n*28,names,e))return false;
 for(uint64_t i=0;i<n;i++){uint64_t flags;if(!sxgco_word(v,dir+56+i*28+12,4,false,&flags,e)||!sxgco_row(v,(flags&0x4000)?&sxgco_gcf_directory_file:&sxgco_gcf_directory_folder,dir+56+i*28,e))return false;}
 p=dir+56+n*28+names;if(!sxgco_table(v,&sxgco_gcf_info_word,p,info+n,e)||!sxgco_table(v,&sxgco_gcf_directory_index,p+4*(info+n),copies+locals,e))return false;
 uint64_t ends[3]={dir+needed,dir+dirsize,dir+56+dirsize};bool found=false,with=false;dhsize=minor>=5?24:20;
 for(unsigned i=0;i<3&&!found;i++)for(unsigned j=0;j<2&&!found;j++){uint64_t m,c,d,z,b,s,first,used;bool header=(minor>=5)==(j==0);if(ends[i]<dir+needed||ends[i]>e||!sxgco_span(v,ends[i],(header?8:0)+n*4+8,e))continue;m=ends[i]+(header?8:0);c=m+n*4;if(!sxgco_word(v,c+4,4,false,&z,e)||z>e-c-8)continue;d=c+8+z;if(!sxgco_span(v,d,dhsize,e))continue;uint64_t q=d+(minor>=5?4:0);if(!sxgco_word(v,q,4,false,&b,e)||!sxgco_word(v,q+4,4,false,&s,e)||!sxgco_word(v,q+8,4,false,&first,e)||!sxgco_word(v,q+12,4,false,&used,e)||b!=blocks||s!=blocksize||used>blocks||first<d+dhsize||first>e)continue;map=m;check=c;datahead=d;with=header;found=true;}
 if(!found)return false;if(with&&!GC_ROW(gcf_directory_map,map-8,e))return false;
 uint64_t sumsize,magic,itemcount,sumcount;if(!sxgco_word(v,check+4,4,false,&sumsize,e))return false;p=check+8;
 if(sumsize>=16&&sxgco_word(v,p,4,false,&magic,e)&&magic==UINT32_C(0x14893721)&&sxgco_word(v,p+8,4,false,&itemcount,e)&&sxgco_word(v,p+12,4,false,&sumcount,e)&&itemcount<=(sumsize-16)/8&&sumcount<=(sumsize-16-itemcount*8)/4){if(!GC_ROW(gcf_checksum_map_header,p,e)||!sxgco_table(v,&sxgco_gcf_checksum_map_entry,p+16,itemcount,e)||!sxgco_table(v,&sxgco_gcf_checksum,p+16+itemcount*8,sumcount,e))return false;}
 return sxgco_table(v,&sxgco_gcf_directory_link,map,n,e)&&GC_ROW(gcf_checksum_header,check,e)&&sxgco_row(v,minor>=5?&sxgco_gcf_data_header5:&sxgco_gcf_data_header3,datahead,e);}

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
case XX_FILE_TYPE_KRML:ok=sxgco_krml(v);break;
case XX_FILE_TYPE_SCI:ok=sxgco_sci(v);break;
case XX_FILE_TYPE_SEADATA:ok=sxgco_seadata(v);break;
case XX_FILE_TYPE_STK:ok=sxgco_stk(v);break;
case XX_FILE_TYPE_BEATTHEHOUSE:ok=sxgco_house(v);break;
case XX_FILE_TYPE_BATTLEISLE:ok=sxgco_battle(v);break;
case XX_FILE_TYPE_MXS:ok=sxgco_mxs(v);break;
case XX_FILE_TYPE_SINNER:ok=sxgco_sinner(v);break;
case XX_FILE_TYPE_MEGATECHVOL:ok=sxgco_megavol(v);break;
case XX_FILE_TYPE_RES:ok=sxgco_res(v);break;
case XX_FILE_TYPE_RSC:ok=sxgco_rsc(v);break;
case XX_FILE_TYPE_VISIONAIRE_STUDIO_VIS:ok=sxgco_vis(v);break;
case XX_FILE_TYPE_BGI:ok=sxgco_bgi(v);break;
case XX_FILE_TYPE_BGI2:ok=sxgco_bgi2(v);break;
case XX_FILE_TYPE_CPK:ok=sxgco_cpk(v);break;
case XX_FILE_TYPE_DXA:ok=sxgco_dxa(v);break;
case XX_FILE_TYPE_LIVEMAKER:ok=sxgco_lm(v);break;
case XX_FILE_TYPE_NOA:ok=sxgco_noa(v);break;
case XX_FILE_TYPE_RPG_MAKER_RGSSAD:ok=sxgco_rgss(v);break;
case XX_FILE_TYPE_STOS_MEMORY_BANK:ok=sxgco_stos(v);break;
case XX_FILE_TYPE_VALVE_GCF_CACHE:ok=sxgco_gcf(v);break;
case XX_FILE_TYPE_YPF:ok=sxgco_ypf(v);break;
case XX_FILE_TYPE_NITROPLUS_NPK2:ok=sxgco_npk2(v);break;
case XX_FILE_TYPE_CATSYSTEM_KIF:ok=sxgco_kif(v);break;
case XX_FILE_TYPE_MALIE_LIB:ok=sxgco_malie(v);break;
case XX_FILE_TYPE_NITROPLUS_NPA:ok=sxgco_npa(v);break;
case XX_FILE_TYPE_QLIE_PACK:ok=sxgco_qlie(v);break;
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
