#ifdef XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM
#define SXARM_CHECKSUM XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM
#else
#define SXARM_CHECKSUM SX_NONE
#endif
/* SPDX-License-Identifier: MIT. Physical metadata. Scope: docs/data_struct_archiveremaining_scope.txt. */
static const xx_data_struct_field_desc sxarm_archiveremaining_name_fields[]={
 SX_FIELD("archiveremaining_name","char",0,0,SX_STRING),
};
static const sx_layout sxarm_archiveremaining_name={UINT32_C(0x607c0001),"archiveremaining_name",sxarm_archiveremaining_name_fields,SX_COUNT(sxarm_archiveremaining_name_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_version_fields[]={
 SX_FIELD("warc_version","char",0,0,SX_ID),
};
static const sx_layout sxarm_warc_version={UINT32_C(0x607c0002),"warc_version",sxarm_warc_version_fields,SX_COUNT(sxarm_warc_version_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_field_name_fields[]={
 SX_FIELD("warc_field_name","char",0,0,SX_STRING),
};
static const sx_layout sxarm_warc_field_name={UINT32_C(0x607c0003),"warc_field_name",sxarm_warc_field_name_fields,SX_COUNT(sxarm_warc_field_name_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_field_value_fields[]={
 SX_FIELD("warc_field_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxarm_warc_field_value={UINT32_C(0x607c0004),"warc_field_value",sxarm_warc_field_value_fields,SX_COUNT(sxarm_warc_field_value_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_content_length_fields[]={
 SX_FIELD("warc_content_length","ascii_decimal",0,0,SX_SIZE),
};
static const sx_layout sxarm_warc_content_length={UINT32_C(0x607c0005),"warc_content_length",sxarm_warc_content_length_fields,SX_COUNT(sxarm_warc_content_length_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_segment_number_fields[]={
 SX_FIELD("warc_segment_number","ascii_decimal",0,0,SX_NONE),
};
static const sx_layout sxarm_warc_segment_number={UINT32_C(0x607c0006),"warc_segment_number",sxarm_warc_segment_number_fields,SX_COUNT(sxarm_warc_segment_number_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_segment_total_length_fields[]={
 SX_FIELD("warc_segment_total_length","ascii_decimal",0,0,SX_SIZE),
};
static const sx_layout sxarm_warc_segment_total_length={UINT32_C(0x607c0007),"warc_segment_total_length",sxarm_warc_segment_total_length_fields,SX_COUNT(sxarm_warc_segment_total_length_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_warc_digest_fields[]={
 SX_FIELD("warc_digest","char",0,0,SXARM_CHECKSUM),
};
static const sx_layout sxarm_warc_digest={UINT32_C(0x607c0008),"warc_digest",sxarm_warc_digest_fields,SX_COUNT(sxarm_warc_digest_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_filename_fields[]={
 SX_FIELD("transport_filename","char",0,0,SX_STRING),
};
static const sx_layout sxarm_transport_filename={UINT32_C(0x607c0009),"transport_filename",sxarm_transport_filename_fields,SX_COUNT(sxarm_transport_filename_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_decimal_size_fields[]={
 SX_FIELD("transport_decimal_size","ascii_decimal",0,0,SX_SIZE),
};
static const sx_layout sxarm_transport_decimal_size={UINT32_C(0x607c000a),"transport_decimal_size",sxarm_transport_decimal_size_fields,SX_COUNT(sxarm_transport_decimal_size_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_hex_size_fields[]={
 SX_FIELD("transport_hex_size","ascii_hex",0,0,SX_SIZE),
};
static const sx_layout sxarm_transport_hex_size={UINT32_C(0x607c000b),"transport_hex_size",sxarm_transport_hex_size_fields,SX_COUNT(sxarm_transport_hex_size_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_crc_fields[]={
 SX_FIELD("transport_crc","ascii_hex",0,0,SXARM_CHECKSUM),
};
static const sx_layout sxarm_transport_crc={UINT32_C(0x607c000c),"transport_crc",sxarm_transport_crc_fields,SX_COUNT(sxarm_transport_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_attribute_name_fields[]={
 SX_FIELD("transport_attribute_name","char",0,0,SX_STRING),
};
static const sx_layout sxarm_transport_attribute_name={UINT32_C(0x607c000d),"transport_attribute_name",sxarm_transport_attribute_name_fields,SX_COUNT(sxarm_transport_attribute_name_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_attribute_value_fields[]={
 SX_FIELD("transport_attribute_value","char",0,0,SX_STRING),
};
static const sx_layout sxarm_transport_attribute_value={UINT32_C(0x607c000e),"transport_attribute_value",sxarm_transport_attribute_value_fields,SX_COUNT(sxarm_transport_attribute_value_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_line_width_fields[]={
 SX_FIELD("yenc_line_width","ascii_decimal",0,0,SX_COUNT_PROP),
};
static const sx_layout sxarm_yenc_line_width={UINT32_C(0x607c000f),"yenc_line_width",sxarm_yenc_line_width_fields,SX_COUNT(sxarm_yenc_line_width_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_part_number_fields[]={
 SX_FIELD("yenc_part_number","ascii_decimal",0,0,SX_NONE),
};
static const sx_layout sxarm_yenc_part_number={UINT32_C(0x607c0010),"yenc_part_number",sxarm_yenc_part_number_fields,SX_COUNT(sxarm_yenc_part_number_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_total_parts_fields[]={
 SX_FIELD("yenc_total_parts","ascii_decimal",0,0,SX_COUNT_PROP),
};
static const sx_layout sxarm_yenc_total_parts={UINT32_C(0x607c0011),"yenc_total_parts",sxarm_yenc_total_parts_fields,SX_COUNT(sxarm_yenc_total_parts_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_begin_position_fields[]={
 SX_FIELD("yenc_begin_position","ascii_decimal",0,0,SX_NONE),
};
static const sx_layout sxarm_yenc_begin_position={UINT32_C(0x607c0012),"yenc_begin_position",sxarm_yenc_begin_position_fields,SX_COUNT(sxarm_yenc_begin_position_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_end_position_fields[]={
 SX_FIELD("yenc_end_position","ascii_decimal",0,0,SX_NONE),
};
static const sx_layout sxarm_yenc_end_position={UINT32_C(0x607c0013),"yenc_end_position",sxarm_yenc_end_position_fields,SX_COUNT(sxarm_yenc_end_position_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa_line_width_fields[]={
 SX_FIELD("btoa_line_width","ascii_decimal",0,0,SX_COUNT_PROP),
};
static const sx_layout sxarm_btoa_line_width={UINT32_C(0x607c0014),"btoa_line_width",sxarm_btoa_line_width_fields,SX_COUNT(sxarm_btoa_line_width_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_pax_member_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("plaintext_prefix","uint8[4]",4,4,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unknown_header_bytes","uint8[16]",12,16,SX_NONE),
 SX_FIELD("name_size","uint16",28,2,SX_SIZE),
};
static const sx_layout sxarm_pax_member={UINT32_C(0x607c0015),"pax_member",sxarm_pax_member_fields,SX_COUNT(sxarm_pax_member_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_pcomm_literal_fields[]={
 SX_FIELD("control","uint8",0,1,SX_NONE),
};
static const sx_layout sxarm_pcomm_literal={UINT32_C(0x607c0016),"pcomm_literal",sxarm_pcomm_literal_fields,SX_COUNT(sxarm_pcomm_literal_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_pcomm_near_match_fields[]={
 SX_FIELD("length_and_distance_high","uint8",0,1,SX_NONE),
 SX_FIELD("distance_low","uint8",1,1,SX_NONE),
};
static const sx_layout sxarm_pcomm_near_match={UINT32_C(0x607c0017),"pcomm_near_match",sxarm_pcomm_near_match_fields,SX_COUNT(sxarm_pcomm_near_match_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_pcomm_far_match_fields[]={
 SX_FIELD("length_code","uint8",0,1,SX_NONE),
 SX_FIELD("decoded_block_source","uint16",1,2,SX_OFFSET),
};
static const sx_layout sxarm_pcomm_far_match={UINT32_C(0x607c0018),"pcomm_far_match",sxarm_pcomm_far_match_fields,SX_COUNT(sxarm_pcomm_far_match_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_pcomm_block_end_fields[]={
 SX_FIELD("end_code","uint8",0,1,SX_ID),
};
static const sx_layout sxarm_pcomm_block_end={UINT32_C(0x607c0019),"pcomm_block_end",sxarm_pcomm_block_end_fields,SX_COUNT(sxarm_pcomm_block_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_balz_header_fields[]={
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint64",1,8,SX_SIZE),
};
static const sx_layout sxarm_balz_header={UINT32_C(0x607c001a),"balz_header",sxarm_balz_header_fields,SX_COUNT(sxarm_balz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_bzip1_header_fields[]={
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("format_version","char[1]",2,1,SX_ID),
 SX_FIELD("block_size_digit","char[1]",3,1,SX_NONE),
};
static const sx_layout sxarm_bzip1_header={UINT32_C(0x607c001b),"bzip1_header",sxarm_bzip1_header_fields,SX_COUNT(sxarm_bzip1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_freeze2_header_fields[]={
 SX_FIELD("signature","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("format_version","uint8",1,1,SX_ID),
 SX_FIELD("distance_counts_1_to_5","uint16",2,2,SX_NONE),
 SX_FIELD("distance_count_6","uint8",4,1,SX_COUNT_PROP),
};
static const sx_layout sxarm_freeze2_header={UINT32_C(0x607c001c),"freeze2_header",sxarm_freeze2_header_fields,SX_COUNT(sxarm_freeze2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_he_tlkb_chunk_fields[]={
 SX_FIELD("encoded_tag","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_total_size","uint8[4]",4,4,SX_NONE),
};
static const sx_layout sxarm_he_tlkb_chunk={UINT32_C(0x607c001d),"he_tlkb_chunk",sxarm_he_tlkb_chunk_fields,SX_COUNT(sxarm_he_tlkb_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
static const sx_layout sxarm_sou_header={UINT32_C(0x607c001e),"sou_header",sxarm_sou_header_fields,SX_COUNT(sxarm_sou_header_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_sou_chunk_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("total_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxarm_sou_chunk={UINT32_C(0x607c001f),"sou_chunk",sxarm_sou_chunk_fields,SX_COUNT(sxarm_sou_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_sou_mouth_sync_fields[]={
 SX_FIELD("mouth_sync_time","uint16",0,2,SX_NONE),
};
static const sx_layout sxarm_sou_mouth_sync={UINT32_C(0x607c0020),"sou_mouth_sync",sxarm_sou_mouth_sync_fields,SX_COUNT(sxarm_sou_mouth_sync_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_sou_voc_header_fields[]={
 SX_FIELD("signature","char[20]",0,20,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",20,2,SX_SIZE),
 SX_FIELD("version","uint16",22,2,SX_NONE),
 SX_FIELD("version_checksum","uint16",24,2,SXARM_CHECKSUM),
};
static const sx_layout sxarm_sou_voc_header={UINT32_C(0x607c0021),"sou_voc_header",sxarm_sou_voc_header_fields,SX_COUNT(sxarm_sou_voc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_block_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
 SX_FIELD("payload_size","uint24",1,3,SX_SIZE),
};
static const sx_layout sxarm_sou_voc_block={UINT32_C(0x607c0022),"sou_voc_block",sxarm_sou_voc_block_fields,SX_COUNT(sxarm_sou_voc_block_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_end_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
};
static const sx_layout sxarm_sou_voc_end={UINT32_C(0x607c0023),"sou_voc_end",sxarm_sou_voc_end_fields,SX_COUNT(sxarm_sou_voc_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_sound_fields[]={
 SX_FIELD("time_constant","uint8",0,1,SX_NONE),
 SX_FIELD("codec","uint8",1,1,SX_ID),
};
static const sx_layout sxarm_sou_voc_sound={UINT32_C(0x607c0024),"sou_voc_sound",sxarm_sou_voc_sound_fields,SX_COUNT(sxarm_sou_voc_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_silence_fields[]={
 SX_FIELD("duration_minus_one","uint16",0,2,SX_NONE),
 SX_FIELD("time_constant","uint8",2,1,SX_NONE),
};
static const sx_layout sxarm_sou_voc_silence={UINT32_C(0x607c0025),"sou_voc_silence",sxarm_sou_voc_silence_fields,SX_COUNT(sxarm_sou_voc_silence_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_marker_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
};
static const sx_layout sxarm_sou_voc_marker={UINT32_C(0x607c0026),"sou_voc_marker",sxarm_sou_voc_marker_fields,SX_COUNT(sxarm_sou_voc_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_repeat_fields[]={
 SX_FIELD("repeat_count","uint16",0,2,SX_NONE),
};
static const sx_layout sxarm_sou_voc_repeat={UINT32_C(0x607c0027),"sou_voc_repeat",sxarm_sou_voc_repeat_fields,SX_COUNT(sxarm_sou_voc_repeat_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_extended_fields[]={
 SX_FIELD("time_constant","uint16",0,2,SX_NONE),
 SX_FIELD("codec","uint8",2,1,SX_ID),
 SX_FIELD("channel_mode","uint8",3,1,SX_NONE),
};
static const sx_layout sxarm_sou_voc_extended={UINT32_C(0x607c0028),"sou_voc_extended",sxarm_sou_voc_extended_fields,SX_COUNT(sxarm_sou_voc_extended_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_new_sound_fields[]={
 SX_FIELD("sample_rate","uint32",0,4,SX_NONE),
 SX_FIELD("bits_per_sample","uint8",4,1,SX_NONE),
 SX_FIELD("channels","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("codec","uint16",6,2,SX_ID),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
static const sx_layout sxarm_sou_voc_new_sound={UINT32_C(0x607c0029),"sou_voc_new_sound",sxarm_sou_voc_new_sound_fields,SX_COUNT(sxarm_sou_voc_new_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_rvz_file_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("compatible_version","uint32",8,4,SX_NONE),
 SX_FIELD("disc_header_size","uint32",12,4,SX_SIZE),
 SX_FIELD("disc_header_sha1","uint8[20]",16,20,SXARM_CHECKSUM),
 SX_FIELD("iso_file_size","uint64",36,8,SX_SIZE),
 SX_FIELD("rvz_file_size","uint64",44,8,SX_SIZE),
 SX_FIELD("file_header_sha1","uint8[20]",52,20,SXARM_CHECKSUM),
};
static const sx_layout sxarm_rvz_file_header={UINT32_C(0x607c002a),"rvz_file_header",sxarm_rvz_file_header_fields,SX_COUNT(sxarm_rvz_file_header_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_disc_header_fields[]={
 SX_FIELD("disc_type","uint32",0,4,SX_ID),
 SX_FIELD("compression","uint32",4,4,SX_ID),
 SX_FIELD("compression_level","int32",8,4,SX_NONE),
 SX_FIELD("chunk_size","uint32",12,4,SX_SIZE),
 SX_FIELD("disc_image_header","uint8[128]",16,128,SX_NONE),
 SX_FIELD("partition_count","uint32",144,4,SX_COUNT_PROP),
 SX_FIELD("partition_entry_size","uint32",148,4,SX_SIZE),
 SX_FIELD("partition_table_offset","uint64",152,8,SX_OFFSET),
 SX_FIELD("partition_table_sha1","uint8[20]",160,20,SXARM_CHECKSUM),
 SX_FIELD("raw_count","uint32",180,4,SX_COUNT_PROP),
 SX_FIELD("raw_table_offset","uint64",184,8,SX_OFFSET),
 SX_FIELD("raw_table_size","uint32",192,4,SX_SIZE),
 SX_FIELD("group_count","uint32",196,4,SX_COUNT_PROP),
 SX_FIELD("group_table_offset","uint64",200,8,SX_OFFSET),
 SX_FIELD("group_table_size","uint32",208,4,SX_SIZE),
 SX_FIELD("compression_properties_size","uint8",212,1,SX_SIZE),
};
static const sx_layout sxarm_rvz_disc_header={UINT32_C(0x607c002b),"rvz_disc_header",sxarm_rvz_disc_header_fields,SX_COUNT(sxarm_rvz_disc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_raw_entry_fields[]={
 SX_FIELD("iso_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("iso_size","uint64",8,8,SX_SIZE),
 SX_FIELD("first_group_index","uint32",16,4,SX_NONE),
 SX_FIELD("group_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxarm_rvz_raw_entry={UINT32_C(0x607c002c),"rvz_raw_entry",sxarm_rvz_raw_entry_fields,SX_COUNT(sxarm_rvz_raw_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_group_entry_fields[]={
 SX_FIELD("data_offset_div4","uint32",0,4,SX_NONE),
 SX_FIELD("data_size_and_compressed_flag","uint32",4,4,SX_NONE),
 SX_FIELD("rvz_packed_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxarm_rvz_group_entry={UINT32_C(0x607c002d),"rvz_group_entry",sxarm_rvz_group_entry_fields,SX_COUNT(sxarm_rvz_group_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_packing_run_fields[]={
 SX_FIELD("length_and_seed_flag","uint32",0,4,SX_NONE),
};
static const sx_layout sxarm_rvz_packing_run={UINT32_C(0x607c002e),"rvz_packing_run",sxarm_rvz_packing_run_fields,SX_COUNT(sxarm_rvz_packing_run_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_rvz_prng_seed_fields[]={
 SX_FIELD("seed_0","uint32",0,4,SX_NONE),
 SX_FIELD("seed_1","uint32",4,4,SX_NONE),
 SX_FIELD("seed_2","uint32",8,4,SX_NONE),
 SX_FIELD("seed_3","uint32",12,4,SX_NONE),
 SX_FIELD("seed_4","uint32",16,4,SX_NONE),
 SX_FIELD("seed_5","uint32",20,4,SX_NONE),
 SX_FIELD("seed_6","uint32",24,4,SX_NONE),
 SX_FIELD("seed_7","uint32",28,4,SX_NONE),
 SX_FIELD("seed_8","uint32",32,4,SX_NONE),
 SX_FIELD("seed_9","uint32",36,4,SX_NONE),
 SX_FIELD("seed_10","uint32",40,4,SX_NONE),
 SX_FIELD("seed_11","uint32",44,4,SX_NONE),
 SX_FIELD("seed_12","uint32",48,4,SX_NONE),
 SX_FIELD("seed_13","uint32",52,4,SX_NONE),
 SX_FIELD("seed_14","uint32",56,4,SX_NONE),
 SX_FIELD("seed_15","uint32",60,4,SX_NONE),
 SX_FIELD("seed_16","uint32",64,4,SX_NONE),
};
static const sx_layout sxarm_rvz_prng_seed={UINT32_C(0x607c002f),"rvz_prng_seed",sxarm_rvz_prng_seed_fields,SX_COUNT(sxarm_rvz_prng_seed_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_binscii_signature_fields[]={
 SX_FIELD("signature","char[18]",0,18,SX_SIGNATURE),
};
static const sx_layout sxarm_binscii_signature={UINT32_C(0x607c0030),"binscii_signature",sxarm_binscii_signature_fields,SX_COUNT(sxarm_binscii_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_binscii_alphabet_fields[]={
 SX_FIELD("alphabet","char[64]",0,64,SX_STRING),
};
static const sx_layout sxarm_binscii_alphabet={UINT32_C(0x607c0031),"binscii_alphabet",sxarm_binscii_alphabet_fields,SX_COUNT(sxarm_binscii_alphabet_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_binscii_header_fields[]={
 SX_FIELD("name_length_code","char[1]",0,1,SX_NONE),
 SX_FIELD("prodos_name","char[15]",1,15,SX_STRING),
 SX_FIELD("encoded_metadata","char[36]",16,36,SX_NONE),
};
static const sx_layout sxarm_binscii_header={UINT32_C(0x607c0032),"binscii_header",sxarm_binscii_header_fields,SX_COUNT(sxarm_binscii_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_binscii_data_crc_fields[]={
 SX_FIELD("encoded_crc_and_padding","char[4]",0,4,SXARM_CHECKSUM),
};
static const sx_layout sxarm_binscii_data_crc={UINT32_C(0x607c0033),"binscii_data_crc",sxarm_binscii_data_crc_fields,SX_COUNT(sxarm_binscii_data_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_begin_fields[]={
 SX_FIELD("marker","char[5]",0,5,SX_SIGNATURE),
};
static const sx_layout sxarm_uue_begin={UINT32_C(0x607c0034),"uue_begin",sxarm_uue_begin_fields,SX_COUNT(sxarm_uue_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_1_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[1]",0,1,SX_FLAGS),
};
static const sx_layout sxarm_uue_mode_1={UINT32_C(0x607c0035),"uue_mode_1",sxarm_uue_mode_1_fields,SX_COUNT(sxarm_uue_mode_1_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_2_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[2]",0,2,SX_FLAGS),
};
static const sx_layout sxarm_uue_mode_2={UINT32_C(0x607c0036),"uue_mode_2",sxarm_uue_mode_2_fields,SX_COUNT(sxarm_uue_mode_2_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_3_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[3]",0,3,SX_FLAGS),
};
static const sx_layout sxarm_uue_mode_3={UINT32_C(0x607c0037),"uue_mode_3",sxarm_uue_mode_3_fields,SX_COUNT(sxarm_uue_mode_3_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_4_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[4]",0,4,SX_FLAGS),
};
static const sx_layout sxarm_uue_mode_4={UINT32_C(0x607c0038),"uue_mode_4",sxarm_uue_mode_4_fields,SX_COUNT(sxarm_uue_mode_4_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_5_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[5]",0,5,SX_FLAGS),
};
static const sx_layout sxarm_uue_mode_5={UINT32_C(0x607c0039),"uue_mode_5",sxarm_uue_mode_5_fields,SX_COUNT(sxarm_uue_mode_5_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_mode_6_fields[]={
 SX_FIELD("permissions","ascii_octal_padded[6]",0,6,SX_FLAGS),
};
static const sx_layout sxarm_uue_mode_6={UINT32_C(0x607c003a),"uue_mode_6",sxarm_uue_mode_6_fields,SX_COUNT(sxarm_uue_mode_6_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_line_fields[]={
 SX_FIELD("encoded_decoded_length","char[1]",0,1,SX_NONE),
};
static const sx_layout sxarm_uue_line={UINT32_C(0x607c003b),"uue_line",sxarm_uue_line_fields,SX_COUNT(sxarm_uue_line_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_uue_end_fields[]={
 SX_FIELD("marker","char[3]",0,3,SX_ID),
};
static const sx_layout sxarm_uue_end={UINT32_C(0x607c003c),"uue_end",sxarm_uue_end_fields,SX_COUNT(sxarm_uue_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_begin_fields[]={
 SX_FIELD("marker","char[7]",0,7,SX_SIGNATURE),
};
static const sx_layout sxarm_yenc_begin={UINT32_C(0x607c003d),"yenc_begin",sxarm_yenc_begin_fields,SX_COUNT(sxarm_yenc_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_part_fields[]={
 SX_FIELD("marker","char[6]",0,6,SX_ID),
};
static const sx_layout sxarm_yenc_part={UINT32_C(0x607c003e),"yenc_part",sxarm_yenc_part_fields,SX_COUNT(sxarm_yenc_part_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_yenc_end_fields[]={
 SX_FIELD("marker","char[5]",0,5,SX_ID),
};
static const sx_layout sxarm_yenc_end={UINT32_C(0x607c003f),"yenc_end",sxarm_yenc_end_fields,SX_COUNT(sxarm_yenc_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa_begin_fields[]={
 SX_FIELD("marker","char[11]",0,11,SX_SIGNATURE),
};
static const sx_layout sxarm_btoa_begin={UINT32_C(0x607c0040),"btoa_begin",sxarm_btoa_begin_fields,SX_COUNT(sxarm_btoa_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa5_begin_fields[]={
 SX_FIELD("marker","char[6]",0,6,SX_SIGNATURE),
};
static const sx_layout sxarm_btoa5_begin={UINT32_C(0x607c0041),"btoa5_begin",sxarm_btoa5_begin_fields,SX_COUNT(sxarm_btoa5_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa_end_fields[]={
 SX_FIELD("marker","char[11]",0,11,SX_ID),
};
static const sx_layout sxarm_btoa_end={UINT32_C(0x607c0042),"btoa_end",sxarm_btoa_end_fields,SX_COUNT(sxarm_btoa_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_ascii85_begin_fields[]={
 SX_FIELD("marker","char[2]",0,2,SX_SIGNATURE),
};
static const sx_layout sxarm_ascii85_begin={UINT32_C(0x607c0043),"ascii85_begin",sxarm_ascii85_begin_fields,SX_COUNT(sxarm_ascii85_begin_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_ascii85_end_fields[]={
 SX_FIELD("marker","char[2]",0,2,SX_ID),
};
static const sx_layout sxarm_ascii85_end={UINT32_C(0x607c0044),"ascii85_end",sxarm_ascii85_end_fields,SX_COUNT(sxarm_ascii85_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_ascii85_group_fields[]={
 SX_FIELD("ascii85_group","char",0,0,SX_NONE),
};
static const sx_layout sxarm_ascii85_group={UINT32_C(0x607c0045),"ascii85_group",sxarm_ascii85_group_fields,SX_COUNT(sxarm_ascii85_group_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_ascii85_shorthand_fields[]={
 SX_FIELD("token","char[1]",0,1,SX_ID),
};
static const sx_layout sxarm_ascii85_shorthand={UINT32_C(0x607c0046),"ascii85_shorthand",sxarm_ascii85_shorthand_fields,SX_COUNT(sxarm_ascii85_shorthand_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_btoa_line_check_fields[]={
 SX_FIELD("line_check_character","char[1]",0,1,SXARM_CHECKSUM),
};
static const sx_layout sxarm_btoa_line_check={UINT32_C(0x607c0047),"btoa_line_check",sxarm_btoa_line_check_fields,SX_COUNT(sxarm_btoa_line_check_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_transport_invalid_number_fields[]={
 SX_FIELD("transport_invalid_number","char",0,0,SX_NONE),
};
static const sx_layout sxarm_transport_invalid_number={UINT32_C(0x607c0048),"transport_invalid_number",sxarm_transport_invalid_number_fields,SX_COUNT(sxarm_transport_invalid_number_fields),SX_LE};
static const sx_layout *const sx_archiveremaining_layouts[]={
 &sxarm_archiveremaining_name,
 &sxarm_warc_version,
 &sxarm_warc_field_name,
 &sxarm_warc_field_value,
 &sxarm_warc_content_length,
 &sxarm_warc_segment_number,
 &sxarm_warc_segment_total_length,
 &sxarm_warc_digest,
 &sxarm_transport_filename,
 &sxarm_transport_decimal_size,
 &sxarm_transport_hex_size,
 &sxarm_transport_crc,
 &sxarm_transport_attribute_name,
 &sxarm_transport_attribute_value,
 &sxarm_yenc_line_width,
 &sxarm_yenc_part_number,
 &sxarm_yenc_total_parts,
 &sxarm_yenc_begin_position,
 &sxarm_yenc_end_position,
 &sxarm_btoa_line_width,
 &sxarm_pax_member,
 &sxarm_pcomm_literal,
 &sxarm_pcomm_near_match,
 &sxarm_pcomm_far_match,
 &sxarm_pcomm_block_end,
 &sxarm_balz_header,
 &sxarm_bzip1_header,
 &sxarm_freeze2_header,
 &sxarm_he_tlkb_chunk,
 &sxarm_sou_header,
 &sxarm_sou_chunk,
 &sxarm_sou_mouth_sync,
 &sxarm_sou_voc_header,
 &sxarm_sou_voc_block,
 &sxarm_sou_voc_end,
 &sxarm_sou_voc_sound,
 &sxarm_sou_voc_silence,
 &sxarm_sou_voc_marker,
 &sxarm_sou_voc_repeat,
 &sxarm_sou_voc_extended,
 &sxarm_sou_voc_new_sound,
 &sxarm_rvz_file_header,
 &sxarm_rvz_disc_header,
 &sxarm_rvz_raw_entry,
 &sxarm_rvz_group_entry,
 &sxarm_rvz_packing_run,
 &sxarm_rvz_prng_seed,
 &sxarm_binscii_signature,
 &sxarm_binscii_alphabet,
 &sxarm_binscii_header,
 &sxarm_binscii_data_crc,
 &sxarm_uue_begin,
 &sxarm_uue_mode_1,
 &sxarm_uue_mode_2,
 &sxarm_uue_mode_3,
 &sxarm_uue_mode_4,
 &sxarm_uue_mode_5,
 &sxarm_uue_mode_6,
 &sxarm_uue_line,
 &sxarm_uue_end,
 &sxarm_yenc_begin,
 &sxarm_yenc_part,
 &sxarm_yenc_end,
 &sxarm_btoa_begin,
 &sxarm_btoa5_begin,
 &sxarm_btoa_end,
 &sxarm_ascii85_begin,
 &sxarm_ascii85_end,
 &sxarm_ascii85_group,
 &sxarm_ascii85_shorthand,
 &sxarm_btoa_line_check,
 &sxarm_transport_invalid_number,
};
static bool sx_archiveremaining_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x607c0000U||id>=0x607d0000U)return true;if(r->type&&!xx_rt_wcsncmp(r->type,L"ascii_decimal[",14)&&r->value.type==XX_VAR_TYPE_BYTES)return true;const wchar_t*text=NULL;switch(id){
 case 0x607c0006U:text=L"One-based part/segment number, not a byte offset or quantity.";break;
 case 0x607c000fU:text=L"Configured encoded characters per output line; escapes may extend the encoded line.";break;
 case 0x607c0010U:text=L"One-based part/segment number, not a byte offset or quantity.";break;
 case 0x607c0012U:text=L"One-based inclusive byte position in the reconstructed output, not a physical file offset.";break;
 case 0x607c0013U:text=L"One-based inclusive byte position in the reconstructed output, not a physical file offset.";break;
 case 0x607c0015U:text=L"Name size includes its terminating NUL. Unknown physical header bytes retained without inferred meaning; adaptive Huffman parameters/payload remain raw.";break;
 case 0x607c0016U:text=L"Literal run length = control - 0xE0 bytes. The immediately following bytes are literals.";break;
 case 0x607c0017U:text=L"Length=(control>>5)+2; distance=((control&31)<<8|distance_low)+1 in current decoded block; no physical file offset is stored.";break;
 case 0x607c0018U:text=L"Length=length_code+4; source is an absolute byte position inside the current decoded block, not a stored-file offset.";break;
 case 0x607c0019U:text=L"0xE0 ends a decoded block; a second consecutive empty block terminates the file.";break;
 case 0x607c001aU:text=L"BALZ 1.20 stored output byte length; the range-coded body has no independent byte-aligned per-symbol headers.";break;
 case 0x607c001bU:text=L"Original bzip 0 stream: ASCII block-size digit 1..9 multiplies 100000 bytes. Arithmetic-coded blocks and whole-file CRC are not mapped to fabricated byte fields.";break;
 case 0x607c001cU:text=L"Freeze 2 distance-code counts: low word bits 0,1..2,3..5,6..9,10..14 hold counts for lengths 1..5; next byte stores length 6 count. Length 7/8 counts are derived.";break;
 case 0x607c001dU:text=L"Each stored byte is XOR 0x69. Decoded tag is ASCII and decoded big-endian size includes this 8-byte header; decoded numbers are not the raw stored value.";break;
 case 0x607c001fU:text=L"SOU VCTL/VTTL/VTLK size includes its 8-byte header.";break;
 case 0x607c0020U:text=L"Big-endian mouth-sync timing value; time units depend on the game, not audio sample positions. 0xFFFF is the end sentinel.";break;
 case 0x607c0027U:text=L"Repeat count encoding; 0xFFFF means endless repetition.";break;
 case 0x607c002bU:text=L"RVZ v1 native scope is GameCube without partitions. Compression level is signed (Zstandard supports negative values).";break;
 case 0x607c002cU:text=L"Offset refers to reconstructed ISO bytes, not this physical RVZ file.";break;
 case 0x607c002dU:text=L"Physical payload offset=data_offset_div4*4. Size low 31 bits are stored bytes; bit 31 selects configured compression. Packed size 0 means RVZ packing is absent.";break;
 case 0x607c002eU:text=L"Low31 bits are output byte length; bit 31 selects 68 bytes of PRNG seed instead of literal bytes.";break;
 case 0x607c002fU:text=L"17 big-endian seed words for Dolphin RVZ lagged-Fibonacci padding generator.";break;
 case 0x607c0031U:text=L"Each distinct physical character maps to its 0..63 position; four encoded symbols represent three bytes in reverse group order.";break;
 case 0x607c0032U:text=L"Name length=first character-0x40. The 36 encoded symbols carry 27 decoded metadata bytes; fields that share encoded symbols are deliberately not assigned fictitious byte offsets.";break;
 case 0x607c0033U:text=L"Four alphabet symbols encode the little-endian CRC16/XMODEM plus one padding byte; checksum covers decoded padded data.";break;
 case 0x607c003bU:text=L"UU/XX alphabet value of this character gives decoded byte count. The following groups encode 3 bytes per 4 symbols.";break;
 case 0x607c0045U:text=L"Contiguous stored Ascii85 digit characters; whitespace can split a decoded group. z/y/w are separate shorthand tokens.";break;
 case 0x607c0046U:text=L"Ascii85/btoa shorthand: z=zeros, y=spaces (or legacy 0xFF), w=256x0xFF in old btoa; native validation determines legal dialect.";break;
 case 0x607c0047U:text=L"btoa5 line check character; retained physically. Native reader ignores its value and verifies trailer checksums.";break;
 case 0x607c0048U:text=L"Invalid or overflowing hexadecimal token; original encoded bytes retained without numeric interpretation.";break;
 default:break;}
 if(id==sxarm_rvz_disc_header.id&&!xx_rt_wcscmp(r->name,L"disc_type")){if(xx_var_get_u64(&r->value)==1)text=L"GameCube";else if(xx_var_get_u64(&r->value)==2)text=L"Wii";}
 if(id==sxarm_rvz_disc_header.id&&!xx_rt_wcscmp(r->name,L"compression")){switch(xx_var_get_u64(&r->value)){case 0:text=L"None (stored tables and groups)";break;case 5:text=L"Zstandard";break;default:text=L"Other RVZ compression method; compressed metadata remains raw";break;}}
 if(id==sxarm_sou_voc_block.id&&!xx_rt_wcscmp(r->name,L"block_type")){static const wchar_t*const names[]={L"Terminator",L"Sound data",L"Sound data continuation",L"Silence",L"Marker",L"Text",L"Repeat start",L"Repeat end",L"Extended sound information",L"New sound data"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names))text=names[v];}

 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXARM_LIMIT 20000U
static bool sxarm_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxarm_read(sx_context*c,uint64_t p,void*b,size_t n){return sxarm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxarm_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxarm_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxarm_read(c,p,b,n))return false;*v=sxarm_uint(b,n,be);return true;}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
static bool sxarm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXARM_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxarm_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxarm_add(sx_context*c,const sx_layout*l,uint64_t p){return sxarm_put(c,l,p,0,false);}
static bool sxarm_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxarm_put(c,l,p,n,aliases);}
static int sxarm_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxarm_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxarm_order);return !c->failed;}
static bool sxarm_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxarm_add(c,l,p+i*width))return false;return true;}
static bool sxarm_line(sx_context*c,uint64_t p,uint8_t*b,size_t cap,size_t*n,uint64_t*next){*n=0;uint64_t q=p;while(q<(uint64_t)c->size){uint8_t x;if(!sxarm_read(c,q,&x,1))return false;q++;if(x=='\r'||x=='\n'){if(x=='\r'&&q<(uint64_t)c->size){uint8_t y;if(!sxarm_read(c,q,&y,1))return false;if(y=='\n')q++;}*next=q;return true;}if(*n>=cap)return false;b[(*n)++]=x;}*next=q;return q>p;}
static bool sxarm_eq(const uint8_t*b,size_t n,const char*s){size_t z=xx_rt_strlen(s);if(z!=n)return false;for(size_t i=0;i<n;i++){unsigned x=b[i],y=(unsigned char)s[i];if(x>='A'&&x<='Z')x+=32;if(y>='A'&&y<='Z')y+=32;if(x!=y)return false;}return true;}
static bool sxarm_uint_text(const uint8_t*b,size_t n,unsigned radix,uint64_t*v){*v=0;if(!n||n>24)return false;for(size_t i=0;i<n;i++){unsigned x=b[i],d=x>='0'&&x<='9'?x-'0':x>='a'&&x<='f'?x-'a'+10:x>='A'&&x<='F'?x-'A'+10:255;if(d>=radix||*v>(UINT64_MAX-d)/radix)return false;*v=*v*radix+d;}return true;}
static bool sxarm_name(sx_context*c,uint64_t p,uint64_t n){return sxarm_text(c,&sxarm_archiveremaining_name,p,n,false);}

/* Strict encoded integers are emitted only when the physical token converts.
 * Damaged optional hexadecimal tokens remain in raw gaps. */
static bool sxarm_numeric_text(sx_context*c,const sx_layout*l,uint64_t p,const uint8_t*b,size_t n){uint64_t value;if(!xx_rt_wcsncmp(l->fields[0].type,L"ascii_hex",9)&&!sxarm_uint_text(b,n,16,&value))return sxarm_text(c,&sxarm_transport_invalid_number,p,n,false);return sxarm_text(c,l,p,n,false);}

static bool sxarm_pcomm(sx_context*c){uint8_t gate[2];if(c->size<4||!sxarm_read(c,0,gate,1)||gate[0]<0xe1||!sxarm_read(c,(uint64_t)c->size-2,gate,2)||gate[0]!=0xe0||gate[1]!=0xe0)return false;uint64_t p=0;while(p<(uint64_t)c->size){uint64_t b;if(!sxarm_word(c,p,1,false,&b))return false;if(b==224){if(!sxarm_add(c,&sxarm_pcomm_block_end,p++))return false;}else if(b>=225){if(!sxarm_add(c,&sxarm_pcomm_literal,p)||!sxarm_span(c,p+1,b-224))return false;p+=1+b-224;}else{unsigned z=b>=32?2:3;if(!sxarm_add(c,b>=32?&sxarm_pcomm_near_match:&sxarm_pcomm_far_match,p))return false;p+=z;}}return true;}
/* Native archive callbacks publish authenticated source extents. No reader
 * factory or decoder is called here, and callback state is always released. */
static bool sxarm_callback(sx_context*c,bool pax){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=true;for(unsigned i=0;i<SXARM_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r)break;if(r->header_offset>=f->base_address&&r->header_size>0){uint64_t p=(uint64_t)(r->header_offset-f->base_address),z=(uint64_t)r->header_size;if(!sxarm_span(c,p,z)){ok=false;break;}if(pax){if(z<32||!sxarm_add(c,&sxarm_pax_member,p)||!sxarm_name(c,p+30,z-30)){ok=false;break;}}else if(!sxarm_name(c,p,z)){ok=false;break;}}if(!(f->archive_record_move_to_next)(f,s,c->pd))break;}(f->free_archive_records_reading)(f,s);return ok;}
static bool sxarm_he(sx_context*c){uint8_t h[8];if(!sxarm_read(c,0,h,8)||h[0]!=('T'^0x69)||h[1]!=('L'^0x69)||h[2]!=('K'^0x69)||h[3]!=('B'^0x69))return false;uint64_t p=0,end=(uint64_t)c->size;for(unsigned i=0;p<end&&i<SXARM_LIMIT;i++){if(!sxarm_read(c,p,h,8)||!sxarm_add(c,&sxarm_he_tlkb_chunk,p))return false;for(unsigned j=0;j<8;j++)h[j]^=0x69;uint64_t z=sxarm_uint(h+4,4,true);if(z<8||z>end-p)return false;if(!p){end=z;p=8;}else p+=z;}return true;}
static bool sxarm_voc(sx_context*c,uint64_t p,uint64_t end,uint64_t*next){uint64_t z,t;if(p>end||end-p<26||!sxarm_add(c,&sxarm_sou_voc_header,p)||!sxarm_word(c,p+20,2,false,&z)||z<26||z>end-p)return false;p+=z;for(unsigned i=0;p<end&&i<4096;i++){if(!sxarm_word(c,p,1,false,&t))return false;if(!t){if(!sxarm_add(c,&sxarm_sou_voc_end,p))return false;*next=p+1;return true;}if(end-p<4||!sxarm_word(c,p+1,3,false,&z)||z>end-p-4||!sxarm_add(c,&sxarm_sou_voc_block,p))return false;p+=4;const sx_layout*l=NULL;unsigned min=0;switch(t){case 1:l=&sxarm_sou_voc_sound;min=2;break;case 3:l=&sxarm_sou_voc_silence;min=3;break;case 4:l=&sxarm_sou_voc_marker;min=2;break;case 6:l=&sxarm_sou_voc_repeat;min=2;break;case 8:l=&sxarm_sou_voc_extended;min=4;break;case 9:l=&sxarm_sou_voc_new_sound;min=12;break;default:break;}if(l&&z>=min&&!sxarm_add(c,l,p))return false;p+=z;}return false;}
static bool sxarm_sou(sx_context*c){uint8_t root[8];if(!sxarm_read(c,0,root,8)||xx_rt_memcmp(root,"SOU \0\0\0\0",8))return false;if(!sxarm_add(c,&sxarm_sou_header,0))return false;uint64_t p=8,end=(uint64_t)c->size,z,next;uint8_t tag[4];while(p<end){if(!sxarm_add(c,&sxarm_sou_chunk,p)||!sxarm_word(c,p+4,4,true,&z)||z<8||z>end-p)return false;if(!sxarm_table(c,&sxarm_sou_mouth_sync,p+8,2,(z-8)/2))return false;p+=z;if(p==end)return true;if(!sxarm_read(c,p,tag,4))return false;if(!xx_rt_memcmp(tag,"VTLK",4)){if(!sxarm_add(c,&sxarm_sou_chunk,p)||!sxarm_word(c,p+4,4,true,&z)||z<8||z>end-p||!sxarm_voc(c,p+8,p+z,&next))return false;p+=z;}else{if(!sxarm_voc(c,p,end,&next))return false;p=next;}}return true;}
static bool sxarm_rvz_packed(sx_context*c,uint64_t p,uint64_t n){uint64_t end=p+n;while(p<end){uint64_t word;if(end-p<4||!sxarm_word(c,p,4,true,&word)||!sxarm_add(c,&sxarm_rvz_packing_run,p))return false;p+=4;uint64_t z=(word&0x80000000U)?68:(word&0x7fffffffU);if(z>end-p)return false;if((word&0x80000000U)&&!sxarm_add(c,&sxarm_rvz_prng_seed,p))return false;p+=z;}return true;}
static bool sxarm_rvz(sx_context*c){uint8_t magic[4];if(!sxarm_read(c,0,magic,4)||xx_rt_memcmp(magic,"RVZ\1",4))return false;uint64_t compression,raw,n,rawz,group,gn,gz,p,z,packed;if(!sxarm_add(c,&sxarm_rvz_file_header,0)||!sxarm_add(c,&sxarm_rvz_disc_header,72)||!sxarm_word(c,76,4,true,&compression))return false;if(compression)return true;/* Compressed table coordinates cannot be mapped to plaintext fields. */
 if(!sxarm_word(c,72+0xb4,4,true,&n)||!sxarm_word(c,72+0xb8,8,true,&raw)||!sxarm_word(c,72+0xc0,4,true,&rawz)||n>rawz/24||!sxarm_span(c,raw,rawz)||!sxarm_table(c,&sxarm_rvz_raw_entry,raw,24,n)||!sxarm_word(c,72+0xc4,4,true,&gn)||!sxarm_word(c,72+0xc8,8,true,&group)||!sxarm_word(c,72+0xd0,4,true,&gz)||gn>gz/12||!sxarm_span(c,group,gz)||!sxarm_table(c,&sxarm_rvz_group_entry,group,12,gn))return false;
 for(uint64_t i=0;i<gn;i++){if(!sxarm_word(c,group+12*i,4,true,&p)||!sxarm_word(c,group+12*i+4,4,true,&z)||!sxarm_word(c,group+12*i+8,4,true,&packed))return false;p*=4;if(z&0x80000000U)continue;if(z&&packed&&sxarm_span(c,p,z)){/* Shared or overlapping payloads are legal; existing physical records are retained once. */size_t old=c->count;if(!sxarm_rvz_packed(c,p,z)){(void)old;return true;}}}return true;}

static bool sxarm_warc(sx_context*c){uint64_t p=0,next,z=0;uint8_t b[4096];size_t n;while(p<(uint64_t)c->size){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))return false;if(!n){p=next;continue;}if(n!=8||!sxarm_eq(b,5,"WARC/")||!sxarm_text(c,&sxarm_warc_version,p,n,false))return false;p=next;bool length=false;uint64_t header_start=p;for(;;){if(p-header_start>1048576||!sxarm_line(c,p,b,sizeof(b),&n,&next))return false;if(!n){p=next;break;}size_t k=0;while(k<n&&b[k]!=':')k++;if(k==n||!k)return true;size_t a=k+1;while(a<n&&(b[a]==' '||b[a]=='\t'))a++;size_t e=n;while(e>a&&(b[e-1]==' '||b[e-1]=='\t'))e--;const sx_layout*l=&sxarm_warc_field_value;if(sxarm_eq(b,k,"Content-Length")){l=&sxarm_warc_content_length;if(!sxarm_uint_text(b+a,e-a,10,&z))return true;length=true;}else if(sxarm_eq(b,k,"WARC-Segment-Number"))l=&sxarm_warc_segment_number;else if(sxarm_eq(b,k,"WARC-Segment-Total-Length"))l=&sxarm_warc_segment_total_length;else if(sxarm_eq(b,k,"WARC-Block-Digest")||sxarm_eq(b,k,"WARC-Payload-Digest"))l=&sxarm_warc_digest;if(!sxarm_text(c,&sxarm_warc_field_name,p,k,false)||!sxarm_text(c,l,p+a,e-a,false))return false;p=next;}if(!length||!sxarm_span(c,p,z))return true;p+=z;}return true;}
static bool sxarm_yenc(sx_context*c){uint64_t p=0,next;uint8_t b[4096];size_t n;bool body=false,part_allowed=false;while(p<(uint64_t)c->size){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))return true;unsigned head=0;const sx_layout*l=NULL;if(!body&&n>=7&&!xx_rt_memcmp(b,"=ybegin",7)){head=7;l=&sxarm_yenc_begin;}else if(part_allowed&&n>=6&&!xx_rt_memcmp(b,"=ypart",6)){head=6;l=&sxarm_yenc_part;}else if(body&&n>=5&&!xx_rt_memcmp(b,"=yend",5)){head=5;l=&sxarm_yenc_end;}if(l){if(head==7){body=true;part_allowed=true;}else if(head==6)part_allowed=false;else{body=false;part_allowed=false;}if(!sxarm_add(c,l,p))return false;size_t q=head;while(q<n){while(q<n&&(b[q]==' '||b[q]=='\t'))q++;size_t key=q;while(q<n&&b[q]!='='&&b[q]!=' '&&b[q]!='\t')q++;if(q==n||b[q]!='=')break;size_t keylen=q-key,a=++q;bool name=sxarm_eq(b+key,keylen,"name");if(name)q=n;else while(q<n&&b[q]!=' '&&b[q]!='\t')q++;l=&sxarm_transport_attribute_value;if(name)l=&sxarm_transport_filename;else if(sxarm_eq(b+key,keylen,"size"))l=&sxarm_transport_decimal_size;else if(sxarm_eq(b+key,keylen,"line"))l=&sxarm_yenc_line_width;else if(sxarm_eq(b+key,keylen,"part"))l=&sxarm_yenc_part_number;else if(sxarm_eq(b+key,keylen,"total"))l=&sxarm_yenc_total_parts;else if(sxarm_eq(b+key,keylen,"begin"))l=&sxarm_yenc_begin_position;else if(sxarm_eq(b+key,keylen,"end"))l=&sxarm_yenc_end_position;else if(sxarm_eq(b+key,keylen,"crc32")||sxarm_eq(b+key,keylen,"pcrc32"))l=&sxarm_transport_crc;if(!sxarm_text(c,&sxarm_transport_attribute_name,p+key,keylen,false)||!sxarm_numeric_text(c,l,p+a,b+a,q-a))return false;}}else part_allowed=false;p=next;}return true;}
static bool sxarm_uue(sx_context*c){Abstractformat*f=c->f;if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;xx_archive_record_state*st=(f->create_archive_records_reading)(f,NULL,c->pd);if(!st)return false;bool ok=true;uint8_t b[4096];size_t n;uint64_t next;for(unsigned i=0;i<SXARM_LIMIT&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(f->get_current_archive_record)(f,st);if(!r)break;if(r->header_offset<f->base_address||r->data_offset<f->base_address||r->header_size<0||r->compressed_size<0){ok=false;break;}uint64_t p=(uint64_t)(r->header_offset-f->base_address),data=(uint64_t)(r->data_offset-f->base_address),z=(uint64_t)r->compressed_size;if(!sxarm_span(c,p,(uint64_t)r->header_size)||!sxarm_span(c,data,z)||!sxarm_line(c,p,b,sizeof(b),&n,&next)||n<8||xx_rt_memcmp(b,"begin ",6)){ok=false;break;}size_t q=6,a=q;while(q<n&&b[q]>='0'&&b[q]<='7')q++;size_t digits=q-a;const sx_layout*modes[]={&sxarm_uue_mode_1,&sxarm_uue_mode_2,&sxarm_uue_mode_3,&sxarm_uue_mode_4,&sxarm_uue_mode_5,&sxarm_uue_mode_6};if(digits<1||digits>6||q==n||b[q]!=' '||!sxarm_add(c,&sxarm_uue_begin,p)||!sxarm_add(c,modes[digits-1],p+a)){ok=false;break;}q++;size_t name_end=n;while(name_end>q&&(b[name_end-1]==' '||b[name_end-1]=='\t'))name_end--;if(!sxarm_text(c,&sxarm_transport_filename,p+q,name_end-q,false)){ok=false;break;}p=data;while(p<data+z){if(!sxarm_line(c,p,b,sizeof(b),&n,&next)||next>data+z){ok=false;break;}if(n&&!sxarm_add(c,&sxarm_uue_line,p)){ok=false;break;}p=next;}if(!ok)break;/* At most one zero-length line plus native-bounded blank lines and end. */unsigned method=(unsigned)xx_archive_record_get_meta_u64(r,XX_META_ID_COMPRESSION_METHOD,0);bool zero=false;for(unsigned j=0;j<258&&p<(uint64_t)c->size;j++){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))break;if(n>=3&&!xx_rt_memcmp(b,"end",3)){size_t k=3;while(k<n&&(b[k]==' '||b[k]=='\t'))k++;if(k==n){ok=sxarm_add(c,&sxarm_uue_end,p);break;}}if(!zero&&n>=1&&(method?b[0]=='+':b[0]==' '||b[0]=='`')){ok=sxarm_add(c,&sxarm_uue_line,p);zero=true;}else if(!n)zero=true;else break;if(!ok)break;p=next;}if(!ok||!(f->archive_record_move_to_next)(f,st,c->pd))break;}(f->free_archive_records_reading)(f,st);return ok;}
/* Encoded Ascii85 digit runs keep their exact stored character positions.
 * Whitespace splits a run; no claim that a fragment is a full decoded word. */
static bool sxarm_a85(sx_context*c,uint64_t p,const uint8_t*b,size_t n){for(size_t i=0;i<n;){if(b[i]>='!'&&b[i]<='u'){size_t a=i;while(i<n&&b[i]>='!'&&b[i]<='u')i++;if(!sxarm_text(c,&sxarm_ascii85_group,p+a,i-a,false))return false;}else{if((b[i]=='z'||b[i]=='y'||b[i]=='w')&&!sxarm_add(c,&sxarm_ascii85_shorthand,p+i))return false;i++;}}return true;}
static bool sxarm_btoa(sx_context*c){uint64_t p=0,next;uint8_t b[4096];size_t n;bool body=false,new_format=false;while(p<(uint64_t)c->size){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))return true;if(n>=11&&!xx_rt_memcmp(b,"xbtoa Begin",11)){if(!sxarm_add(c,&sxarm_btoa_begin,p))return false;body=true;new_format=false;}else if(n>=7&&!xx_rt_memcmp(b,"xbtoa5",6)&&(b[6]==' '||b[6]=='\t')){if(!sxarm_add(c,&sxarm_btoa5_begin,p))return false;size_t q=6,e=n;while(e&& (b[e-1]==' '||b[e-1]=='\t'))e--;while(q<e&&(b[q]==' '||b[q]=='\t'))q++;size_t a=q;while(q<e&&b[q]>='0'&&b[q]<='9')q++;if(!sxarm_text(c,&sxarm_btoa_line_width,p+a,q-a,false))return false;while(q<e&&(b[q]==' '||b[q]=='\t'))q++;if(e<q+7||xx_rt_memcmp(b+e-5,"Begin",5))return true;size_t name_end=e-6;while(name_end>q&&(b[name_end-1]==' '||b[name_end-1]=='\t'))name_end--;if(!sxarm_text(c,&sxarm_transport_filename,p+q,name_end-q,false))return false;body=true;new_format=true;}else if(n>=11&&!xx_rt_memcmp(b,"xbtoa End N",11)){if(!sxarm_add(c,&sxarm_btoa_end,p))return false;size_t q=11;unsigned field=0;while(q<n){while(q<n&&(b[q]==' '||b[q]=='\t'))q++;size_t a=q;while(q<n&&b[q]!=' '&&b[q]!='\t')q++;if(q==a)break;if(q-a==1&&(b[a]=='E'||b[a]=='S'||b[a]=='R'))continue;const sx_layout*l=field==0?&sxarm_transport_decimal_size:field==1?&sxarm_transport_hex_size:&sxarm_transport_crc;if(!sxarm_numeric_text(c,l,p+a,b+a,q-a))return false;field++;}body=false;}else{size_t a=0,end=n;if(!body&&n>=2&&b[0]=='<'&&b[1]=='~'){if(!sxarm_add(c,&sxarm_ascii85_begin,p))return false;a=2;body=true;}if(body){if(new_format&&end>a){end--;if(!sxarm_add(c,&sxarm_btoa_line_check,p+end))return false;}for(size_t q=a;q+1<n;q++)if(b[q]=='~'&&b[q+1]=='>'){end=q;if(!sxarm_add(c,&sxarm_ascii85_end,p+q))return false;body=false;break;}if(!sxarm_a85(c,p+a,b+a,end-a))return false;}}p=next;}return true;}
static bool sxarm_binscii(sx_context*c){uint64_t p=0,next;uint8_t b[4096],alphabet[64];size_t n;unsigned state=0;uint64_t lines=0;while(p<(uint64_t)c->size){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))return true;size_t a=0;while(a<n&&b[a]<=32)a++;size_t len=n-a;if(len==18&&!xx_rt_memcmp(b+a,"FiLeStArTfIlEsTaRt",18)){if(!sxarm_add(c,&sxarm_binscii_signature,p+a))return false;state=1;}else if(state==1){if(len<64)return true;if(!sxarm_add(c,&sxarm_binscii_alphabet,p+a))return false;xx_rt_memcpy(alphabet,b+a,64);state=2;}else if(state==2){if(len<52||!sxarm_add(c,&sxarm_binscii_header,p+a))return true;uint8_t raw[27];for(unsigned i=0;i<9;i++){unsigned v[4];for(unsigned j=0;j<4;j++){v[j]=64;for(unsigned k=0;k<64;k++)if(alphabet[k]==b[a+16+4*i+j]){v[j]=k;break;}if(v[j]==64)return true;}raw[3*i]=(uint8_t)(v[3]<<2|v[2]>>4);raw[3*i+1]=(uint8_t)(v[2]<<4|v[1]>>2);raw[3*i+2]=(uint8_t)(v[1]<<6|v[0]);}lines=(sxarm_uint(raw+21,3,false)+47)/48;state=lines?3:4;}else if(state==3){if(lines&&!--lines)state=4;}else if(state==4){if(len>=4&&!sxarm_add(c,&sxarm_binscii_data_crc,p+a))return false;state=0;}p=next;}return true;}

static bool sx_archiveremaining_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_WARC:case XX_FILE_TYPE_GLU:case XX_FILE_TYPE_PCOMMOS2:case XX_FILE_TYPE_PAX:case XX_FILE_TYPE_BTOA:case XX_FILE_TYPE_UUE:case XX_FILE_TYPE_BINSCII:case XX_FILE_TYPE_YENC_ENCODED_FILE:case XX_FILE_TYPE_BALZ:case XX_FILE_TYPE_BZIP1:case XX_FILE_TYPE_FREEZE:case XX_FILE_TYPE_RVZ:case XX_FILE_TYPE_AUDIO_SCUMM_SOU:case XX_FILE_TYPE_HE_TLKB:return true;default:return false;}}
static bool sx_archiveremaining_build(sx_context*c){bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_WARC:ok=sxarm_warc(c);break;case XX_FILE_TYPE_GLU:ok=sxarm_callback(c,false);break;case XX_FILE_TYPE_PAX:ok=sxarm_callback(c,true);break;case XX_FILE_TYPE_PCOMMOS2:ok=sxarm_pcomm(c);break;case XX_FILE_TYPE_BTOA:ok=sxarm_btoa(c);break;case XX_FILE_TYPE_UUE:ok=sxarm_uue(c);break;case XX_FILE_TYPE_BINSCII:ok=sxarm_binscii(c);break;case XX_FILE_TYPE_YENC_ENCODED_FILE:ok=sxarm_yenc(c);break;case XX_FILE_TYPE_BALZ:{uint8_t b[2];if(sxarm_read(c,0,b,1)&&b[0]==0xba)ok=sxarm_add(c,&sxarm_balz_header,0);break;}case XX_FILE_TYPE_BZIP1:{uint8_t b[4];if(sxarm_read(c,0,b,4)&&!xx_rt_memcmp(b,"BZ0",3)&&b[3]>='1'&&b[3]<='9')ok=sxarm_add(c,&sxarm_bzip1_header,0);break;}case XX_FILE_TYPE_FREEZE:{uint64_t v;if(sxarm_word(c,0,2,true,&v)&&v==0x1f9f)ok=sxarm_add(c,&sxarm_freeze2_header,0);break;}case XX_FILE_TYPE_RVZ:ok=sxarm_rvz(c);break;case XX_FILE_TYPE_AUDIO_SCUMM_SOU:ok=sxarm_sou(c);break;case XX_FILE_TYPE_HE_TLKB:ok=sxarm_he(c);break;default:return false;}(void)ok;/* Bounded valid prefix survives damaged optional metadata or display cap. */return c->count&&sxarm_finish(c);}
