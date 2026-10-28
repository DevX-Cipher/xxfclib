/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical document/mailbox metadata; undecoded bodies remain raw. */
static const xx_data_struct_field_desc sxdm_djvu_form_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("form_size","uint32",8,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",12,4,SX_ID),
};
static const sx_layout sxdm_djvu_form_header={UINT32_C(0x60230001),"djvu_form_header",sxdm_djvu_form_header_fields,SX_COUNT(sxdm_djvu_form_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdm_djvu_chunk_header_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxdm_djvu_chunk_header={UINT32_C(0x60230002),"djvu_chunk_header",sxdm_djvu_chunk_header_fields,SX_COUNT(sxdm_djvu_chunk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdm_djvu_info_fields[]={
 SX_FIELD("width","uint16be",0,2,SX_COUNT_PROP),
 SX_FIELD("height","uint16be",2,2,SX_COUNT_PROP),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("dpi","uint16",6,2,SX_NONE),
 SX_FIELD("gamma_times_ten","uint8",8,1,SX_NONE),
 SX_FIELD("orientation","uint8",9,1,SX_ID),
};
static const sx_layout sxdm_djvu_info={UINT32_C(0x60230003),"djvu_info",sxdm_djvu_info_fields,SX_COUNT(sxdm_djvu_info_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zxml_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxdm_zxml_header={UINT32_C(0x60230004),"zxml_header",sxdm_zxml_header_fields,SX_COUNT(sxdm_zxml_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_lsz_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
};
static const sx_layout sxdm_lsz_header={UINT32_C(0x60230005),"lsz_header",sxdm_lsz_header_fields,SX_COUNT(sxdm_lsz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_lsz_member_header_fields[]={
 SX_FIELD("tag","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("filename","char[13]",4,13,SX_STRING),
 SX_FIELD("reserved","uint16",17,2,SX_RESERVED),
 SX_FIELD("unpacked_size","int32",19,4,SX_SIZE),
 SX_FIELD("packed_size","int32",23,4,SX_SIZE),
 SX_FIELD("checksum","uint32",27,4,SX_CHECKSUM),
 SX_FIELD("dos_time","uint16",31,2,SX_TIME),
 SX_FIELD("dos_date","uint16",33,2,SX_TIME),
 SX_FIELD("attributes","uint16",35,2,SX_FLAGS),
 SX_FIELD("method","uint16",37,2,SX_ID),
 SX_FIELD("reserved_tail","bytes",39,12,SX_RESERVED),
};
static const sx_layout sxdm_lsz_member_header={UINT32_C(0x60230006),"lsz_member_header",sxdm_lsz_member_header_fields,SX_COUNT(sxdm_lsz_member_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_pain_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxdm_pain_header={UINT32_C(0x60230007),"pain_header",sxdm_pain_header_fields,SX_COUNT(sxdm_pain_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_pain_directory_entry_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("method","uint32",4,4,SX_ID),
 SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("filename","char[64]",16,64,SX_STRING),
};
static const sx_layout sxdm_pain_directory_entry={UINT32_C(0x60230008),"pain_directory_entry",sxdm_pain_directory_entry_fields,SX_COUNT(sxdm_pain_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_pain_lzss_block_header_fields[]={
 SX_FIELD("block_type","uint32",0,4,SX_ID),
};
static const sx_layout sxdm_pain_lzss_block_header={UINT32_C(0x60230009),"pain_lzss_block_header",sxdm_pain_lzss_block_header_fields,SX_COUNT(sxdm_pain_lzss_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_thebat_msb_header_fields[]={
 SX_FIELD("header_value1","uint32",0,4,SX_NONE),
 SX_FIELD("header_value2","uint32",4,4,SX_NONE),
 SX_FIELD("sentinel","uint32",8,4,SX_SIGNATURE),
 SX_FIELD("metadata","bytes",12,68,SX_NONE),
};
static const sx_layout sxdm_thebat_msb_header={UINT32_C(0x6023000A),"thebat_msb_header",sxdm_thebat_msb_header_fields,SX_COUNT(sxdm_thebat_msb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_thebat_msb_record_fields[]={
 SX_FIELD("record_body_size","uint32",0,4,SX_SIZE),
 SX_FIELD("metadata_size","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
 SX_FIELD("flags","uint8",12,1,SX_FLAGS),
};
static const sx_layout sxdm_thebat_msb_record={UINT32_C(0x6023000B),"thebat_msb_record",sxdm_thebat_msb_record_fields,SX_COUNT(sxdm_thebat_msb_record_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_stylus_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("stream_kind","uint8",6,1,SX_ID),
 SX_FIELD("payload_tag","char[3]",7,3,SX_ID),
 SX_FIELD("unknown","bytes",10,2,SX_NONE),
 SX_FIELD("plaintext_crc32","uint32",12,4,SX_CHECKSUM),
};
static const sx_layout sxdm_stylus_header={UINT32_C(0x6023000C),"stylus_header",sxdm_stylus_header_fields,SX_COUNT(sxdm_stylus_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_perform_header_fields[]={
 SX_FIELD("signature","char[34]",0,34,SX_SIGNATURE),
 SX_FIELD("plaintext_crc16","uint16",34,2,SX_CHECKSUM),
};
static const sx_layout sxdm_perform_header={UINT32_C(0x6023000D),"perform_header",sxdm_perform_header_fields,SX_COUNT(sxdm_perform_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_pkt_type2_header_fields[]={
 SX_FIELD("origin_node","uint16",0,2,SX_ID),
 SX_FIELD("destination_node","uint16",2,2,SX_ID),
 SX_FIELD("year","uint16",4,2,SX_NONE),
 SX_FIELD("month_zero_based","uint16",6,2,SX_NONE),
 SX_FIELD("day","uint16",8,2,SX_NONE),
 SX_FIELD("hour","uint16",10,2,SX_NONE),
 SX_FIELD("minute","uint16",12,2,SX_NONE),
 SX_FIELD("second","uint16",14,2,SX_NONE),
 SX_FIELD("baud_rate","uint16",16,2,SX_NONE),
 SX_FIELD("packet_type","uint16",18,2,SX_ID),
 SX_FIELD("origin_net","uint16",20,2,SX_ID),
 SX_FIELD("destination_net","uint16",22,2,SX_ID),
 SX_FIELD("product_code","uint8",24,1,SX_ID),
 SX_FIELD("serial_number","uint8",25,1,SX_NONE),
 SX_FIELD("password","char[8]",26,8,SX_NONE),
 SX_FIELD("origin_zone","uint16",34,2,SX_ID),
 SX_FIELD("destination_zone","uint16",36,2,SX_ID),
 SX_FIELD("reserved_or_extension","bytes",38,20,SX_NONE),
};
static const sx_layout sxdm_pkt_type2_header={UINT32_C(0x6023000E),"pkt_type2_header",sxdm_pkt_type2_header_fields,SX_COUNT(sxdm_pkt_type2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_pkt_message_header_fields[]={
 SX_FIELD("message_type","uint16",0,2,SX_ID),
 SX_FIELD("origin_node","uint16",2,2,SX_ID),
 SX_FIELD("destination_node","uint16",4,2,SX_ID),
 SX_FIELD("origin_net","uint16",6,2,SX_ID),
 SX_FIELD("destination_net","uint16",8,2,SX_ID),
 SX_FIELD("attributes","uint16",10,2,SX_FLAGS),
 SX_FIELD("cost","uint16",12,2,SX_NONE),
};
static const sx_layout sxdm_pkt_message_header={UINT32_C(0x6023000F),"pkt_message_header",sxdm_pkt_message_header_fields,SX_COUNT(sxdm_pkt_message_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("variant","uint8",3,1,SX_ID),
 SX_FIELD("unknown1","uint8",4,1,SX_NONE),
 SX_FIELD("marker","uint8",5,1,SX_SIGNATURE),
 SX_FIELD("metadata","bytes",6,158,SX_NONE),
 SX_FIELD("root_offset","int32",164,4,SX_OFFSET),
 SX_FIELD("unknown_tail","bytes",168,32,SX_NONE),
};
static const sx_layout sxdm_paperport_header={UINT32_C(0x60230010),"paperport_header",sxdm_paperport_header_fields,SX_COUNT(sxdm_paperport_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_chunk_header_fields[]={
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("payload_size","int32",2,4,SX_SIZE),
 SX_FIELD("unknown1","bytes",6,20,SX_NONE),
 SX_FIELD("chunk_type","uint16",26,2,SX_ID),
 SX_FIELD("unknown2","bytes",28,4,SX_NONE),
};
static const sx_layout sxdm_paperport_chunk_header={UINT32_C(0x60230011),"paperport_chunk_header",sxdm_paperport_chunk_header_fields,SX_COUNT(sxdm_paperport_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_root_prefix_fields[]={
 SX_FIELD("page_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("unknown1","bytes",2,8,SX_NONE),
 SX_FIELD("page_count_copy","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("unknown2","bytes",12,10,SX_NONE),
};
static const sx_layout sxdm_paperport_root_prefix={UINT32_C(0x60230012),"paperport_root_prefix",sxdm_paperport_root_prefix_fields,SX_COUNT(sxdm_paperport_root_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_root_entry_fields[]={
 SX_FIELD("unknown1","bytes",0,4,SX_NONE),
 SX_FIELD("item_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("unknown2","bytes",8,4,SX_NONE),
};
static const sx_layout sxdm_paperport_root_entry={UINT32_C(0x60230013),"paperport_root_entry",sxdm_paperport_root_entry_fields,SX_COUNT(sxdm_paperport_root_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_paperport_page_item_fields[]={
 SX_FIELD("unknown1","bytes",0,34,SX_NONE),
 SX_FIELD("image_offset","int32",34,4,SX_OFFSET),
 SX_FIELD("unknown2","bytes",38,24,SX_NONE),
};
static const sx_layout sxdm_paperport_page_item={UINT32_C(0x60230014),"paperport_page_item",sxdm_paperport_page_item_fields,SX_COUNT(sxdm_paperport_page_item_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("free_chain_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sxdm_winhelp_header={UINT32_C(0x60230015),"winhelp_header",sxdm_winhelp_header_fields,SX_COUNT(sxdm_winhelp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_internal_file_header_fields[]={
 SX_FIELD("allocated_size","uint32",0,4,SX_SIZE),
 SX_FIELD("used_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint8",8,1,SX_FLAGS),
};
static const sx_layout sxdm_winhelp_internal_file_header={UINT32_C(0x60230016),"winhelp_internal_file_header",sxdm_winhelp_internal_file_header_fields,SX_COUNT(sxdm_winhelp_internal_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_btree_header_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("page_size","uint16",4,2,SX_SIZE),
 SX_FIELD("data_format","char[16]",6,16,SX_NONE),
 SX_FIELD("unknown1","uint16",22,2,SX_NONE),
 SX_FIELD("page_split","uint16",24,2,SX_NONE),
 SX_FIELD("root_page","uint16",26,2,SX_ID),
 SX_FIELD("unknown2","uint16",28,2,SX_NONE),
 SX_FIELD("page_count","uint16",30,2,SX_COUNT_PROP),
 SX_FIELD("level_count","uint16",32,2,SX_COUNT_PROP),
 SX_FIELD("entry_count","uint32",34,4,SX_COUNT_PROP),
};
static const sx_layout sxdm_winhelp_btree_header={UINT32_C(0x60230017),"winhelp_btree_header",sxdm_winhelp_btree_header_fields,SX_COUNT(sxdm_winhelp_btree_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_index_header_fields[]={
 SX_FIELD("unused_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("first_child","uint16",4,2,SX_ID),
};
static const sx_layout sxdm_winhelp_index_header={UINT32_C(0x60230018),"winhelp_index_header",sxdm_winhelp_index_header_fields,SX_COUNT(sxdm_winhelp_index_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_leaf_header_fields[]={
 SX_FIELD("unused_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("previous_page","uint16",4,2,SX_ID),
 SX_FIELD("next_page","uint16",6,2,SX_ID),
};
static const sx_layout sxdm_winhelp_leaf_header={UINT32_C(0x60230019),"winhelp_leaf_header",sxdm_winhelp_leaf_header_fields,SX_COUNT(sxdm_winhelp_leaf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_winhelp_file_pointer_fields[]={
 SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdm_winhelp_file_pointer={UINT32_C(0x6023001A),"winhelp_file_pointer",sxdm_winhelp_file_pointer_fields,SX_COUNT(sxdm_winhelp_file_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("directory_offset","int32",4,4,SX_OFFSET),
};
static const sx_layout sxdm_ivt_header={UINT32_C(0x6023001B),"ivt_header",sxdm_ivt_header_fields,SX_COUNT(sxdm_ivt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_btree_header_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("page_size","uint16",4,2,SX_SIZE),
 SX_FIELD("unknown1","bytes",6,20,SX_NONE),
 SX_FIELD("last_leaf_page","uint32",26,4,SX_ID),
 SX_FIELD("root_page","uint32",30,4,SX_ID),
 SX_FIELD("unknown2","bytes",34,4,SX_NONE),
 SX_FIELD("page_count","int32",38,4,SX_COUNT_PROP),
 SX_FIELD("level_count","uint16",42,2,SX_COUNT_PROP),
 SX_FIELD("entry_count","int32",44,4,SX_COUNT_PROP),
};
static const sx_layout sxdm_ivt_btree_header={UINT32_C(0x6023001C),"ivt_btree_header",sxdm_ivt_btree_header_fields,SX_COUNT(sxdm_ivt_btree_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leaf_header_fields[]={
 SX_FIELD("unused_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("previous_page","uint32",4,4,SX_ID),
 SX_FIELD("next_page","uint32",8,4,SX_ID),
};
static const sx_layout sxdm_ivt_leaf_header={UINT32_C(0x6023001D),"ivt_leaf_header",sxdm_ivt_leaf_header_fields,SX_COUNT(sxdm_ivt_leaf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_index_header_fields[]={
 SX_FIELD("unused_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("first_child","uint32",4,4,SX_ID),
};
static const sx_layout sxdm_ivt_index_header={UINT32_C(0x6023001E),"ivt_index_header",sxdm_ivt_index_header_fields,SX_COUNT(sxdm_ivt_index_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_key_length_fields[]={
 SX_FIELD("name_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxdm_ivt_key_length={UINT32_C(0x6023001F),"ivt_key_length",sxdm_ivt_key_length_fields,SX_COUNT(sxdm_ivt_key_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_child_pointer_fields[]={
 SX_FIELD("child_page","uint32",0,4,SX_ID),
};
static const sx_layout sxdm_ivt_child_pointer={UINT32_C(0x60230020),"ivt_child_pointer",sxdm_ivt_child_pointer_fields,SX_COUNT(sxdm_ivt_child_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_entry_terminator_fields[]={
 SX_FIELD("zero","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxdm_ivt_entry_terminator={UINT32_C(0x60230021),"ivt_entry_terminator",sxdm_ivt_entry_terminator_fields,SX_COUNT(sxdm_ivt_entry_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_mszip_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
static const sx_layout sxdm_ivt_mszip_header={UINT32_C(0x60230022),"ivt_mszip_header",sxdm_ivt_mszip_header_fields,SX_COUNT(sxdm_ivt_mszip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_mszip_block_header_fields[]={
 SX_FIELD("unpacked_size","uint16",0,2,SX_SIZE),
 SX_FIELD("packed_size","uint16",2,2,SX_SIZE),
 SX_FIELD("signature","char[2]",4,2,SX_SIGNATURE),
};
static const sx_layout sxdm_ivt_mszip_block_header={UINT32_C(0x60230023),"ivt_mszip_block_header",sxdm_ivt_mszip_block_header_fields,SX_COUNT(sxdm_ivt_mszip_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_1_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,1,SX_OFFSET),
};
static const sx_layout sxdm_ivt_leb_offset_1={UINT32_C(0x60230024),"ivt_leb_offset_1",sxdm_ivt_leb_offset_1_fields,SX_COUNT(sxdm_ivt_leb_offset_1_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_2_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,2,SX_OFFSET),
};
static const sx_layout sxdm_ivt_leb_offset_2={UINT32_C(0x60230025),"ivt_leb_offset_2",sxdm_ivt_leb_offset_2_fields,SX_COUNT(sxdm_ivt_leb_offset_2_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_3_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,3,SX_OFFSET),
};
static const sx_layout sxdm_ivt_leb_offset_3={UINT32_C(0x60230026),"ivt_leb_offset_3",sxdm_ivt_leb_offset_3_fields,SX_COUNT(sxdm_ivt_leb_offset_3_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_4_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,4,SX_OFFSET),
};
static const sx_layout sxdm_ivt_leb_offset_4={UINT32_C(0x60230027),"ivt_leb_offset_4",sxdm_ivt_leb_offset_4_fields,SX_COUNT(sxdm_ivt_leb_offset_4_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_offset_5_fields[]={
 SX_FIELD("file_offset","uleb128_64",0,5,SX_OFFSET),
};
static const sx_layout sxdm_ivt_leb_offset_5={UINT32_C(0x60230028),"ivt_leb_offset_5",sxdm_ivt_leb_offset_5_fields,SX_COUNT(sxdm_ivt_leb_offset_5_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_1_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,1,SX_SIZE),
};
static const sx_layout sxdm_ivt_leb_size_1={UINT32_C(0x60230029),"ivt_leb_size_1",sxdm_ivt_leb_size_1_fields,SX_COUNT(sxdm_ivt_leb_size_1_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_2_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,2,SX_SIZE),
};
static const sx_layout sxdm_ivt_leb_size_2={UINT32_C(0x6023002A),"ivt_leb_size_2",sxdm_ivt_leb_size_2_fields,SX_COUNT(sxdm_ivt_leb_size_2_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_3_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,3,SX_SIZE),
};
static const sx_layout sxdm_ivt_leb_size_3={UINT32_C(0x6023002B),"ivt_leb_size_3",sxdm_ivt_leb_size_3_fields,SX_COUNT(sxdm_ivt_leb_size_3_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_4_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,4,SX_SIZE),
};
static const sx_layout sxdm_ivt_leb_size_4={UINT32_C(0x6023002C),"ivt_leb_size_4",sxdm_ivt_leb_size_4_fields,SX_COUNT(sxdm_ivt_leb_size_4_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_ivt_leb_size_5_fields[]={
 SX_FIELD("stream_size","uleb128_64",0,5,SX_SIZE),
};
static const sx_layout sxdm_ivt_leb_size_5={UINT32_C(0x6023002D),"ivt_leb_size_5",sxdm_ivt_leb_size_5_fields,SX_COUNT(sxdm_ivt_leb_size_5_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("major_version","uint16",4,2,SX_ID),
 SX_FIELD("minor_version","uint16",6,2,SX_ID),
 SX_FIELD("uuid","bytes",8,16,SX_ID),
 SX_FIELD("entry_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("cluster_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("url_pointer_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("title_pointer_offset","uint64",40,8,SX_OFFSET),
 SX_FIELD("cluster_pointer_offset","uint64",48,8,SX_OFFSET),
 SX_FIELD("mime_list_offset","uint64",56,8,SX_OFFSET),
 SX_FIELD("main_page","uint32",64,4,SX_ID),
 SX_FIELD("layout_page","uint32",68,4,SX_ID),
 SX_FIELD("checksum_offset","uint64",72,8,SX_OFFSET),
};
static const sx_layout sxdm_zim_header={UINT32_C(0x6023002E),"zim_header",sxdm_zim_header_fields,SX_COUNT(sxdm_zim_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_url_pointer_fields[]={
 SX_FIELD("directory_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxdm_zim_url_pointer={UINT32_C(0x6023002F),"zim_url_pointer",sxdm_zim_url_pointer_fields,SX_COUNT(sxdm_zim_url_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_title_pointer_fields[]={
 SX_FIELD("entry_index","uint32",0,4,SX_ID),
};
static const sx_layout sxdm_zim_title_pointer={UINT32_C(0x60230030),"zim_title_pointer",sxdm_zim_title_pointer_fields,SX_COUNT(sxdm_zim_title_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_cluster_pointer_fields[]={
 SX_FIELD("cluster_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxdm_zim_cluster_pointer={UINT32_C(0x60230031),"zim_cluster_pointer",sxdm_zim_cluster_pointer_fields,SX_COUNT(sxdm_zim_cluster_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_article_entry_fields[]={
 SX_FIELD("mime_type","uint16",0,2,SX_ID),
 SX_FIELD("parameter_length","uint8",2,1,SX_SIZE),
 SX_FIELD("namespace","uint8",3,1,SX_ID),
 SX_FIELD("revision","uint32",4,4,SX_NONE),
 SX_FIELD("cluster_index","uint32",8,4,SX_ID),
 SX_FIELD("blob_index","uint32",12,4,SX_ID),
};
static const sx_layout sxdm_zim_article_entry={UINT32_C(0x60230032),"zim_article_entry",sxdm_zim_article_entry_fields,SX_COUNT(sxdm_zim_article_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_redirect_entry_fields[]={
 SX_FIELD("mime_type","uint16",0,2,SX_ID),
 SX_FIELD("parameter_length","uint8",2,1,SX_SIZE),
 SX_FIELD("namespace","uint8",3,1,SX_ID),
 SX_FIELD("revision","uint32",4,4,SX_NONE),
 SX_FIELD("redirect_index","uint32",8,4,SX_ID),
};
static const sx_layout sxdm_zim_redirect_entry={UINT32_C(0x60230033),"zim_redirect_entry",sxdm_zim_redirect_entry_fields,SX_COUNT(sxdm_zim_redirect_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_cluster_header_fields[]={
 SX_FIELD("compression_and_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxdm_zim_cluster_header={UINT32_C(0x60230034),"zim_cluster_header",sxdm_zim_cluster_header_fields,SX_COUNT(sxdm_zim_cluster_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_blob_offset32_fields[]={
 SX_FIELD("cluster_data_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdm_zim_blob_offset32={UINT32_C(0x60230035),"zim_blob_offset32",sxdm_zim_blob_offset32_fields,SX_COUNT(sxdm_zim_blob_offset32_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_blob_offset64_fields[]={
 SX_FIELD("cluster_data_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxdm_zim_blob_offset64={UINT32_C(0x60230036),"zim_blob_offset64",sxdm_zim_blob_offset64_fields,SX_COUNT(sxdm_zim_blob_offset64_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_zim_checksum_fields[]={
 SX_FIELD("md5","bytes",0,16,SX_CHECKSUM),
};
static const sx_layout sxdm_zim_checksum={UINT32_C(0x60230037),"zim_checksum",sxdm_zim_checksum_fields,SX_COUNT(sxdm_zim_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_itolitls_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("section_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("postheader_size","uint32",20,4,SX_SIZE),
 SX_FIELD("format_guid","bytes",24,16,SX_ID),
};
static const sx_layout sxdm_itolitls_header={UINT32_C(0x60230038),"itolitls_header",sxdm_itolitls_header_fields,SX_COUNT(sxdm_itolitls_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_itolitls_section_fields[]={
 SX_FIELD("section_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("section_size","uint64",8,8,SX_SIZE),
};
static const sx_layout sxdm_itolitls_section={UINT32_C(0x60230039),"itolitls_section",sxdm_itolitls_section_fields,SX_COUNT(sxdm_itolitls_section_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_post_header_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("caol_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("directory_metadata","bytes",8,56,SX_NONE),
 SX_FIELD("entry_count","uint64",64,8,SX_COUNT_PROP),
 SX_FIELD("index_metadata","bytes",72,80,SX_NONE),
};
static const sx_layout sxdm_hxs_post_header={UINT32_C(0x6023003A),"hxs_post_header",sxdm_hxs_post_header_fields,SX_COUNT(sxdm_hxs_post_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_caol_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("metadata","bytes",12,36,SX_NONE),
};
static const sx_layout sxdm_hxs_caol={UINT32_C(0x6023003B),"hxs_caol",sxdm_hxs_caol_fields,SX_COUNT(sxdm_hxs_caol_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_itsf_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("content_offset","uint64",16,8,SX_OFFSET),
 SX_FIELD("timestamp","uint32",24,4,SX_TIME),
 SX_FIELD("language_id","uint32",28,4,SX_ID),
};
static const sx_layout sxdm_hxs_itsf={UINT32_C(0x6023003C),"hxs_itsf",sxdm_hxs_itsf_fields,SX_COUNT(sxdm_hxs_itsf_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_file_size_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("reserved1","uint32",4,4,SX_RESERVED),
 SX_FIELD("file_size","uint64",8,8,SX_SIZE),
 SX_FIELD("reserved2","bytes",16,8,SX_RESERVED),
};
static const sx_layout sxdm_hxs_file_size_header={UINT32_C(0x6023003D),"hxs_file_size_header",sxdm_hxs_file_size_header_fields,SX_COUNT(sxdm_hxs_file_size_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_ifcm_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("chunk_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
 SX_FIELD("sentinel1","int32",16,4,SX_NONE),
 SX_FIELD("sentinel2","int32",20,4,SX_NONE),
 SX_FIELD("chunk_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxdm_hxs_ifcm={UINT32_C(0x6023003E),"hxs_ifcm",sxdm_hxs_ifcm_fields,SX_COUNT(sxdm_hxs_ifcm_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_aoll_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("quickref_size","uint32",4,4,SX_SIZE),
 SX_FIELD("metadata","bytes",8,40,SX_NONE),
};
static const sx_layout sxdm_hxs_aoll_header={UINT32_C(0x6023003F),"hxs_aoll_header",sxdm_hxs_aoll_header_fields,SX_COUNT(sxdm_hxs_aoll_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_hxs_aoll_count_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxdm_hxs_aoll_count={UINT32_C(0x60230040),"hxs_aoll_count",sxdm_hxs_aoll_count_fields,SX_COUNT(sxdm_hxs_aoll_count_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("class_guid","bytes",4,16,SX_ID),
 SX_FIELD("unknown1","bytes",20,176,SX_NONE),
 SX_FIELD("message_count","uint32",196,4,SX_COUNT_PROP),
 SX_FIELD("unknown2","bytes",200,28,SX_NONE),
 SX_FIELD("root_offset","uint32",228,4,SX_OFFSET),
 SX_FIELD("unknown3","bytes",232,9172,SX_NONE),
};
static const sx_layout sxdm_dbx_header={UINT32_C(0x60230041),"dbx_header",sxdm_dbx_header_fields,SX_COUNT(sxdm_dbx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_node_header_fields[]={
 SX_FIELD("self_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unknown1","uint32",4,4,SX_NONE),
 SX_FIELD("left_child_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("parent_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("unknown2","uint8",16,1,SX_NONE),
 SX_FIELD("entry_count","uint8",17,1,SX_COUNT_PROP),
 SX_FIELD("unknown3","bytes",18,2,SX_NONE),
 SX_FIELD("left_subtree_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxdm_dbx_node_header={UINT32_C(0x60230042),"dbx_node_header",sxdm_dbx_node_header_fields,SX_COUNT(sxdm_dbx_node_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_node_entry_fields[]={
 SX_FIELD("info_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("right_child_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("right_subtree_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxdm_dbx_node_entry={UINT32_C(0x60230043),"dbx_node_entry",sxdm_dbx_node_entry_fields,SX_COUNT(sxdm_dbx_node_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_info_header_fields[]={
 SX_FIELD("self_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown1","uint16",8,2,SX_NONE),
 SX_FIELD("attribute_count","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("unknown2","uint8",11,1,SX_NONE),
};
static const sx_layout sxdm_dbx_info_header={UINT32_C(0x60230044),"dbx_info_header",sxdm_dbx_info_header_fields,SX_COUNT(sxdm_dbx_info_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_attribute_fields[]={
 SX_FIELD("id_and_direct_flag","uint8",0,1,SX_FLAGS),
 SX_FIELD("direct_value","uint24",1,3,SX_NONE),
};
static const sx_layout sxdm_dbx_attribute={UINT32_C(0x60230045),"dbx_attribute",sxdm_dbx_attribute_fields,SX_COUNT(sxdm_dbx_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_attribute_indirect_fields[]={
 SX_FIELD("id_and_direct_flag","uint8",0,1,SX_FLAGS),
 SX_FIELD("data_offset","uint24",1,3,SX_OFFSET),
};
static const sx_layout sxdm_dbx_attribute_indirect={UINT32_C(0x60230046),"dbx_attribute_indirect",sxdm_dbx_attribute_indirect_fields,SX_COUNT(sxdm_dbx_attribute_indirect_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_attribute_message_fields[]={
 SX_FIELD("id_and_direct_flag","uint8",0,1,SX_FLAGS),
 SX_FIELD("first_block_offset","uint24",1,3,SX_OFFSET),
};
static const sx_layout sxdm_dbx_attribute_message={UINT32_C(0x60230047),"dbx_attribute_message",sxdm_dbx_attribute_message_fields,SX_COUNT(sxdm_dbx_attribute_message_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_message_pointer_fields[]={
 SX_FIELD("first_block_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdm_dbx_message_pointer={UINT32_C(0x60230048),"dbx_message_pointer",sxdm_dbx_message_pointer_fields,SX_COUNT(sxdm_dbx_message_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_dbx_block_header_fields[]={
 SX_FIELD("self_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("allocated_body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("used_body_size","uint32",8,4,SX_SIZE),
 SX_FIELD("next_block_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxdm_dbx_block_header={UINT32_C(0x60230049),"dbx_block_header",sxdm_dbx_block_header_fields,SX_COUNT(sxdm_dbx_block_header_fields),SX_LE};
static const sx_layout *const sx_docmeta_layouts[]={
 &sxdm_djvu_form_header,
 &sxdm_djvu_chunk_header,
 &sxdm_djvu_info,
 &sxdm_zxml_header,
 &sxdm_lsz_header,
 &sxdm_lsz_member_header,
 &sxdm_pain_header,
 &sxdm_pain_directory_entry,
 &sxdm_pain_lzss_block_header,
 &sxdm_thebat_msb_header,
 &sxdm_thebat_msb_record,
 &sxdm_stylus_header,
 &sxdm_perform_header,
 &sxdm_pkt_type2_header,
 &sxdm_pkt_message_header,
 &sxdm_paperport_header,
 &sxdm_paperport_chunk_header,
 &sxdm_paperport_root_prefix,
 &sxdm_paperport_root_entry,
 &sxdm_paperport_page_item,
 &sxdm_winhelp_header,
 &sxdm_winhelp_internal_file_header,
 &sxdm_winhelp_btree_header,
 &sxdm_winhelp_index_header,
 &sxdm_winhelp_leaf_header,
 &sxdm_winhelp_file_pointer,
 &sxdm_ivt_header,
 &sxdm_ivt_btree_header,
 &sxdm_ivt_leaf_header,
 &sxdm_ivt_index_header,
 &sxdm_ivt_key_length,
 &sxdm_ivt_child_pointer,
 &sxdm_ivt_entry_terminator,
 &sxdm_ivt_mszip_header,
 &sxdm_ivt_mszip_block_header,
 &sxdm_ivt_leb_offset_1,
 &sxdm_ivt_leb_offset_2,
 &sxdm_ivt_leb_offset_3,
 &sxdm_ivt_leb_offset_4,
 &sxdm_ivt_leb_offset_5,
 &sxdm_ivt_leb_size_1,
 &sxdm_ivt_leb_size_2,
 &sxdm_ivt_leb_size_3,
 &sxdm_ivt_leb_size_4,
 &sxdm_ivt_leb_size_5,
 &sxdm_zim_header,
 &sxdm_zim_url_pointer,
 &sxdm_zim_title_pointer,
 &sxdm_zim_cluster_pointer,
 &sxdm_zim_article_entry,
 &sxdm_zim_redirect_entry,
 &sxdm_zim_cluster_header,
 &sxdm_zim_blob_offset32,
 &sxdm_zim_blob_offset64,
 &sxdm_zim_checksum,
 &sxdm_itolitls_header,
 &sxdm_itolitls_section,
 &sxdm_hxs_post_header,
 &sxdm_hxs_caol,
 &sxdm_hxs_itsf,
 &sxdm_hxs_file_size_header,
 &sxdm_hxs_ifcm,
 &sxdm_hxs_aoll_header,
 &sxdm_hxs_aoll_count,
 &sxdm_dbx_header,
 &sxdm_dbx_node_header,
 &sxdm_dbx_node_entry,
 &sxdm_dbx_info_header,
 &sxdm_dbx_attribute,
 &sxdm_dbx_attribute_indirect,
 &sxdm_dbx_attribute_message,
 &sxdm_dbx_message_pointer,
 &sxdm_dbx_block_header,
};
static const sx_layout *const sxdm_ivt_leb_offset_rows[]={&sxdm_ivt_leb_offset_1,&sxdm_ivt_leb_offset_2,&sxdm_ivt_leb_offset_3,&sxdm_ivt_leb_offset_4,&sxdm_ivt_leb_offset_5};
static const sx_layout *const sxdm_ivt_leb_size_rows[]={&sxdm_ivt_leb_size_1,&sxdm_ivt_leb_size_2,&sxdm_ivt_leb_size_3,&sxdm_ivt_leb_size_4,&sxdm_ivt_leb_size_5};
static bool sx_docmeta_supports(xx_file_type_t t)
{
 switch(t){case XX_FILE_TYPE_DJVU:case XX_FILE_TYPE_ZXML:case XX_FILE_TYPE_LSZ:case XX_FILE_TYPE_PAIN:case XX_FILE_TYPE_THEBAT_MSB:case XX_FILE_TYPE_STYLUS:case XX_FILE_TYPE_PERFORM:case XX_FILE_TYPE_PKT:case XX_FILE_TYPE_PAPERPORT:case XX_FILE_TYPE_WINDOWS_HELP:case XX_FILE_TYPE_IVT:case XX_FILE_TYPE_OPENZIM:case XX_FILE_TYPE_HXS:case XX_FILE_TYPE_MICROSOFT_LIT:case XX_FILE_TYPE_OUTLOOK_EXPRESS_DBX_MAILBOX:return true;default:return false;}
}
static uint16_t sxdm_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
static uint32_t sxdm_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
static uint64_t sxdm_u64(const uint8_t *p){return xx_data_get_u64(p,8,0,false);}
static bool sxdm_span(sx_context *c,int64_t at,uint64_t n){return !xx_pd_is_stopped(c->pd)&&at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at);}
static bool sxdm_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n)
{
 if(n<=0||!sxdm_span(c,at,(uint64_t)n))return false;
 return sx_add(c,l,at,n);
}
static int sxdm_order(const void *aa,const void *bb){const xx_data_struct *a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;if(a->total_size!=b->total_size)return a->total_size<b->total_size?-1:1;return a->id<b->id?-1:a->id>b->id;}
static bool sxdm_finish(sx_context *c)
{
 size_t n=c->count,out=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxdm_order);
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];int64_t at=d.offset-c->f->base_address;
  if(out&&sxdm_order(&c->items[out-1],&d)==0)continue;
  if(at<end){if(c->f->file_type==XX_FILE_TYPE_OUTLOOK_EXPRESS_DBX_MAILBOX||c->f->file_type==XX_FILE_TYPE_PAPERPORT)continue;return false;}c->items[out++]=d;end=at+d.total_size;
 }
 c->count=out;end=0;
 for(size_t i=0;i<out;i++){int64_t at=c->items[i].offset-c->f->base_address,nbytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+nbytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sxdm_zero(sx_context *c,int64_t *at,int64_t end,unsigned limit)
{
 uint8_t b[256];unsigned used=0;
 while(*at<end&&used<limit){size_t n=(size_t)(end-*at>256?256:end-*at);if(n>limit-used)n=limit-used;if(!sx_read(c,*at,b,n))return false;for(size_t i=0;i<n;i++){++*at;++used;if(!b[i])return true;}}return false;
}
static bool sxdm_djvu(sx_context *c)
{
 uint8_t b[16];if(!sx_read(c,0,b,16)||xx_rt_memcmp(b,"AT&TFORM",8)||xx_rt_memcmp(b+12,"DJVU",4)||!sxdm_add(c,&sxdm_djvu_form_header,0,16))return false;
 uint32_t n=xx_data_get_u32(b+8,4,0,true);int64_t end=12+(int64_t)n,at=16;if(n<4||!sxdm_span(c,0,(uint64_t)end))return false;
 for(unsigned i=0;at<end;i++){if(i>=4096||end-at<8||!sx_read(c,at,b,8))return false;n=xx_data_get_u32(b+4,4,0,true);if((uint64_t)n+(n&1)> (uint64_t)(end-at-8)||!sxdm_add(c,&sxdm_djvu_chunk_header,at,8))return false;if(!xx_rt_memcmp(b,"INFO",4)&&n==10&&!sxdm_add(c,&sxdm_djvu_info,at+8,10))return false;at+=8+(int64_t)n+(n&1);}return true;
}
static bool sxdm_lsz(sx_context *c)
{
 uint8_t b[51];int64_t at=6;if(!sxdm_add(c,&sxdm_lsz_header,0,6))return false;
 for(unsigned i=0;at<c->size;i++){if(i>=65536||!sx_read(c,at,b,51))return false;int32_t n=(int32_t)sxdm_u32(b+23);if(n<0||!sxdm_span(c,at+51,(uint32_t)n)||!sxdm_add(c,&sxdm_lsz_member_header,at,51))return false;at+=51+(int64_t)n;}return true;
}
static bool sxdm_pain(sx_context *c)
{
 uint8_t b[80];if(!sx_read(c,0,b,16)||!sxdm_add(c,&sxdm_pain_header,0,16))return false;uint32_t dir=sxdm_u32(b+8),n=sxdm_u32(b+12);if(n>65536||dir<16||!sxdm_span(c,dir,(uint64_t)n*80))return false;
 for(uint32_t i=0;i<n;i++){int64_t at=(int64_t)dir+i*80;if(!sx_read(c,at,b,80)||!sxdm_add(c,&sxdm_pain_directory_entry,at,80))return false;uint32_t pos=sxdm_u32(b),method=sxdm_u32(b+4),bytes=sxdm_u32(b+8);if(!sxdm_span(c,pos,bytes))return false;if(method==3&&bytes>=4){uint32_t tag;if(!sx_u32(c,pos,false,&tag))return false;if(tag<=1&&!sxdm_add(c,&sxdm_pain_lzss_block_header,pos,4))return false;}}
 return true;
}
static bool sxdm_msb(sx_context *c)
{
 uint8_t b[13];int64_t at=80;if(!sxdm_add(c,&sxdm_thebat_msb_header,0,80))return false;
 for(unsigned i=0;at<c->size;i++){if(i>=65536||!sx_read(c,at,b,13))return false;uint32_t n=sxdm_u32(b),meta=sxdm_u32(b+4);if(n<=meta||!sxdm_span(c,at+13,n)||!sxdm_add(c,&sxdm_thebat_msb_record,at,13))return false;at+=13+(int64_t)n;}return true;
}
static bool sxdm_pkt(sx_context *c)
{
 int64_t at=58;uint16_t type;if(!sxdm_add(c,&sxdm_pkt_type2_header,0,58))return false;
 for(unsigned i=0;at<c->size;i++){
  if(i>=65536)return false;if(c->size-at<2)return true;if(!sx_u16(c,at,false,&type))return false;
  if(!type)return true;if(c->size-at<3)return true;
  if(type!=2||!sxdm_add(c,&sxdm_pkt_message_header,at,14))return false;at+=14;
  for(unsigned j=0;j<5;j++)if(!sxdm_zero(c,&at,c->size,16*1024*1024))return false;
 }return true;
}
static bool sxdm_pp_chunk(sx_context *c,int64_t at,uint16_t type,uint32_t minimum,uint32_t *size)
{
 uint8_t b[32];if(!sx_read(c,at,b,32)||xx_rt_memcmp(b,"VZ",2)||sxdm_u16(b+26)!=type||(int32_t)sxdm_u32(b+2)<0)return false;*size=sxdm_u32(b+2);return *size>=minimum&&sxdm_span(c,at+32,*size)&&sxdm_add(c,&sxdm_paperport_chunk_header,at,32);
}
static bool sxdm_paperport(sx_context *c)
{
 uint8_t b[200];uint32_t n;if(!sx_read(c,0,b,200)||!sxdm_add(c,&sxdm_paperport_header,0,200))return false;int64_t root=(int32_t)sxdm_u32(b+164);
 if(!sxdm_pp_chunk(c,root,0x8000,54,&n)||!sx_read(c,root+32,b,22)||!sxdm_add(c,&sxdm_paperport_root_prefix,root+32,22))return false;uint16_t count=sxdm_u16(b);if((uint64_t)count*12>n-22)return false;
 for(unsigned i=0;i<count;i++){int64_t at=root+54+(int64_t)i*12;if(!sx_read(c,at,b,12)||!sxdm_add(c,&sxdm_paperport_root_entry,at,12))return false;int64_t item=(int32_t)sxdm_u32(b+4);if(!sxdm_pp_chunk(c,item,0x4000,62,&n)||!sx_read(c,item+32,b,62)||!sxdm_add(c,&sxdm_paperport_page_item,item+32,62)||!sxdm_pp_chunk(c,(int32_t)sxdm_u32(b+34),0x1000,136,&n))return false;}return true;
}
/* Walk native WinHelp root-to-first-leaf path and leaf chain. Other index
 * branches are not traversed by the native reader and remain raw. */
static bool sxdm_hlp(sx_context *c)
{
 uint8_t b[38];uint32_t dir;if(!sx_u32(c,4,false,&dir)||!sxdm_add(c,&sxdm_winhelp_header,0,16)||!sxdm_add(c,&sxdm_winhelp_internal_file_header,dir,9)||!sx_read(c,dir+9,b,38)||!sxdm_add(c,&sxdm_winhelp_btree_header,dir+9,38))return false;
 uint16_t page=sxdm_u16(b+4),count=sxdm_u16(b+30),levels=sxdm_u16(b+32),cur=sxdm_u16(b+26);int64_t pages=(int64_t)dir+47;uint8_t *seen=NULL;bool ok=false;
 if(page<64||!count||levels<1||levels>64||!sxdm_span(c,pages,(uint64_t)page*count))return false;seen=xx_mem_calloc(count,1);if(!seen)return false;
 for(unsigned i=1;i<levels;i++){if(cur>=count||seen[cur])goto done;seen[cur]=1;int64_t at=pages+(int64_t)cur*page;if(!sx_read(c,at,b,6)||!sxdm_add(c,&sxdm_winhelp_index_header,at,6))goto done;cur=sxdm_u16(b+4);}
 for(unsigned i=0;cur!=65535;i++){
  if(i>=count||cur>=count||seen[cur])goto done;seen[cur]=1;int64_t start=pages+(int64_t)cur*page,at=start+8;
  if(!sx_read(c,start,b,8)||!sxdm_add(c,&sxdm_winhelp_leaf_header,start,8))goto done;uint16_t unused=sxdm_u16(b),entries=sxdm_u16(b+2),next=sxdm_u16(b+6);if(unused>page-8)goto done;int64_t end=start+page-unused;
  for(unsigned j=0;j<entries;j++){
   uint32_t off,alloc,used;if(!sxdm_zero(c,&at,end,256)||end-at<4||!sx_u32(c,at,false,&off)||!sxdm_add(c,&sxdm_winhelp_file_pointer,at,4))goto done;at+=4;
   if(!sx_u32(c,off,false,&alloc)||!sx_u32(c,(int64_t)off+4,false,&used)||alloc<9||used>alloc-9||!sxdm_span(c,off,alloc)||!sxdm_add(c,&sxdm_winhelp_internal_file_header,off,9))goto done;
  }if(at!=end)goto done;cur=next;
 }ok=true;
done:xx_mem_free(seen);return ok;
}
static bool sxdm_ivt_leb(sx_context *c,int64_t *at,int64_t end,bool size,uint32_t *value)
{
 int64_t start=*at;uint32_t v=0;uint8_t b;
 for(unsigned i=0;i<5;i++){if(*at>=end||!sx_read(c,(*at)++,&b,1))return false;if(i==4&&(b&0xf8))return false;v|=(uint32_t)(b&127)<<(7*i);if(!(b&128)){*value=v;return sxdm_add(c,size?sxdm_ivt_leb_size_rows[i]:sxdm_ivt_leb_offset_rows[i],start,(int64_t)i+1);}}return false;
}
static bool sxdm_ivt_mszip(sx_context *c,uint32_t off,uint32_t size)
{
 uint8_t b[12];if(size<12)return true;if(!sx_read(c,off,b,12))return false;if((xx_rt_memcmp(b,"mszp",4)&&xx_rt_memcmp(b,"nszp",4))||sxdm_u32(b+8))return true;
 if(!sxdm_add(c,&sxdm_ivt_mszip_header,off,12))return false;int64_t at=(int64_t)off+12,end=(int64_t)off+size;
 for(unsigned i=0;at<end;i++){if(i>=65536||end-at<6||!sx_read(c,at,b,6))return true;uint16_t packed=sxdm_u16(b+2);if(packed<2||packed>(uint64_t)(end-at-4)||xx_rt_memcmp(b+4,"CK",2))return true;if(!sxdm_add(c,&sxdm_ivt_mszip_block_header,at,6))return false;at+=4+packed;}return true;
}
static bool sxdm_ivt_page(sx_context *c,int64_t pages,uint32_t count,uint32_t index,unsigned depth,uint8_t *seen)
{
 uint8_t b[12];if(index>=count||seen[index]||depth>31)return false;seen[index]=1;int64_t start=pages+(int64_t)index*8192;
 if(!sx_read(c,start,b,12))return false;uint16_t unused=sxdm_u16(b),n=sxdm_u16(b+2);if(!n||unused>8180)return false;int64_t end=start+8192-unused,at=start+(depth?8:12);
 if(!sxdm_add(c,depth?&sxdm_ivt_index_header:&sxdm_ivt_leaf_header,start,depth?8:12))return false;
 if(depth&&!sxdm_ivt_page(c,pages,count,sxdm_u32(b+4),depth-1,seen))return false;
 for(unsigned i=0;i<n;i++){
  if(at>=end||!sx_read(c,at,b,1)||!b[0]||!sxdm_add(c,&sxdm_ivt_key_length,at,1))return false;uint8_t name=b[0];at++;if(name>(uint64_t)(end-at))return false;at+=name;
  if(depth){uint32_t child;if(end-at<4||!sx_u32(c,at,false,&child)||!sxdm_add(c,&sxdm_ivt_child_pointer,at,4)||!sxdm_ivt_page(c,pages,count,child,depth-1,seen))return false;at+=4;}
  else{uint32_t off,size;if(!sxdm_ivt_leb(c,&at,end,false,&off)||!sxdm_ivt_leb(c,&at,end,true,&size)||at>=end||!sx_read(c,at,b,1)||b[0]||!sxdm_add(c,&sxdm_ivt_entry_terminator,at++,1))return false;if(size&&sxdm_span(c,off,size)&&!sxdm_ivt_mszip(c,off,size))return false;}
 }return at==end;
}
static bool sxdm_ivt(sx_context *c)
{
 uint8_t b[48];uint32_t dir;if(!sx_u32(c,4,false,&dir)||dir>INT32_MAX||!sxdm_add(c,&sxdm_ivt_header,0,8)||!sx_read(c,dir,b,48)||!sxdm_add(c,&sxdm_ivt_btree_header,dir,48))return false;
 uint32_t count=sxdm_u32(b+38),root=sxdm_u32(b+30);uint16_t levels=sxdm_u16(b+42);if(!count||count>65536||!levels||levels>32||!sxdm_span(c,(int64_t)dir+48,(uint64_t)count*8192))return false;
 uint8_t *seen=xx_mem_calloc(count,1);if(!seen)return false;bool ok=sxdm_ivt_page(c,(int64_t)dir+48,count,root,levels-1,seen);xx_mem_free(seen);return ok;
}
static bool sxdm_zim(sx_context *c)
{
 uint8_t b[80];uint64_t *clusters=NULL,*dirs=NULL;bool ok=false;
 if(!sx_read(c,0,b,80)||!sxdm_add(c,&sxdm_zim_header,0,80))return false;
 uint32_t ne=sxdm_u32(b+24),nc=sxdm_u32(b+28);uint64_t urls=sxdm_u64(b+32),titles=sxdm_u64(b+40),cp=sxdm_u64(b+48),checksum=sxdm_u64(b+72);
 if(!ne||ne>2048||!nc||nc>1024||checksum>INT64_MAX||!sxdm_span(c,(int64_t)checksum,16)||urls>checksum||titles>checksum||cp>checksum||!sxdm_span(c,(int64_t)urls,(uint64_t)ne*8)||!sxdm_span(c,(int64_t)titles,(uint64_t)ne*4)||!sxdm_span(c,(int64_t)cp,(uint64_t)nc*8))return false;
 clusters=xx_mem_alloc(nc*sizeof(*clusters));dirs=xx_mem_alloc(ne*sizeof(*dirs));if(!clusters||!dirs)goto done;
 for(uint32_t i=0;i<nc;i++){if(!sx_u64(c,(int64_t)cp+i*8,false,&clusters[i])||clusters[i]>=checksum||!sxdm_add(c,&sxdm_zim_cluster_pointer,(int64_t)cp+i*8,8))goto done;}
 for(uint32_t i=0;i<ne;i++){
  if(!sx_u64(c,(int64_t)urls+i*8,false,&dirs[i])||dirs[i]>=checksum||!sxdm_add(c,&sxdm_zim_url_pointer,(int64_t)urls+i*8,8)||!sxdm_add(c,&sxdm_zim_title_pointer,(int64_t)titles+i*4,4)||!sx_read(c,(int64_t)dirs[i],b,12))goto done;
  unsigned fixed=sxdm_u16(b)==65535?12:16;if(!sxdm_add(c,fixed==12?&sxdm_zim_redirect_entry:&sxdm_zim_article_entry,(int64_t)dirs[i],fixed))goto done;
 }
 for(uint32_t i=0;i<nc;i++){
  uint64_t at=clusters[i],end=i+1<nc?clusters[i+1]:checksum;if(end<=at)goto done;
  uint64_t tables[]={urls,titles,cp};for(unsigned j=0;j<3;j++)if(tables[j]>at&&tables[j]<end)end=tables[j];for(uint32_t j=0;j<ne;j++)if(dirs[j]>at&&dirs[j]<end)end=dirs[j];
  if(!sx_read(c,(int64_t)at,b,1)||!sxdm_add(c,&sxdm_zim_cluster_header,(int64_t)at,1))goto done;
  if((b[0]&15)<=1){unsigned width=b[0]&16?8:4;uint64_t first;if(end-at-1<width||!sx_read(c,(int64_t)at+1,b,width))goto done;first=width==8?sxdm_u64(b):sxdm_u32(b);if(first<2*width||first%width||first>end-at-1||first/width>65536)goto done;
   for(uint64_t j=0;j<first/width;j++)if(!sxdm_add(c,width==8?&sxdm_zim_blob_offset64:&sxdm_zim_blob_offset32,(int64_t)at+1+(int64_t)j*width,width))goto done;
  }
 }
 ok=sxdm_add(c,&sxdm_zim_checksum,(int64_t)checksum,16);
done:xx_mem_free(clusters);xx_mem_free(dirs);return ok;
}
/* LIT shares the transport header but its native reader validates only that
 * layer before invoking an external decoder. We do not invoke that decoder. */
static bool sxdm_itolitls(sx_context *c)
{
 uint8_t b[152];uint64_t offsets[5],sizes[5];if(!sx_read(c,0,b,40)||!sxdm_add(c,&sxdm_itolitls_header,0,40))return false;
 uint32_t table=sxdm_u32(b+12),post=sxdm_u32(b+20);if(sxdm_u32(b+16)!=5||table<40||post<232||!sxdm_span(c,table,80U+(uint64_t)post))return false;
 for(unsigned i=0;i<5;i++){int64_t at=(int64_t)table+i*16;if(!sx_read(c,at,b,16)||!sxdm_add(c,&sxdm_itolitls_section,at,16))return false;offsets[i]=sxdm_u64(b);sizes[i]=sxdm_u64(b+8);if(offsets[i]>INT64_MAX||!sxdm_span(c,(int64_t)offsets[i],sizes[i]))return false;}
 if(c->f->file_type==XX_FILE_TYPE_MICROSOFT_LIT)return true;
 int64_t p=(int64_t)table+80;
 if(!sxdm_add(c,&sxdm_hxs_post_header,p,152)||!sxdm_add(c,&sxdm_hxs_caol,p+152,48)||!sxdm_add(c,&sxdm_hxs_itsf,p+200,32)||sizes[0]<24||!sxdm_add(c,&sxdm_hxs_file_size_header,(int64_t)offsets[0],24)||sizes[1]<32||!sx_read(c,(int64_t)offsets[1],b,32)||!sxdm_add(c,&sxdm_hxs_ifcm,(int64_t)offsets[1],32))return false;
 uint32_t width=sxdm_u32(b+8),count=sxdm_u32(b+24);if(width<50||count>65536||(uint64_t)count*width>sizes[1]-32)return false;
 for(uint32_t i=0;i<count;i++){int64_t at=(int64_t)offsets[1]+32+(int64_t)i*width;if(!sx_read(c,at,b,8))return false;if(xx_rt_memcmp(b,"AOLL",4))continue;uint32_t qr=sxdm_u32(b+4);if(qr<2||qr>width-48)return false;if(!sxdm_add(c,&sxdm_hxs_aoll_header,at,48)||!sxdm_add(c,&sxdm_hxs_aoll_count,at+width-2,2))return false;}
 return true;
}
/* DBX intentionally accepts damaged subtrees. Only complete, self-identifying
 * nodes/objects/blocks are classified; damaged links remain raw. A single
 * finite queue tracks ownership and stops cycles/shared targets. */
typedef struct sxdm_dbx_job{uint32_t at,parent;unsigned kind,depth;}sxdm_dbx_job;
static bool sxdm_dbx_push(sxdm_dbx_job *q,uint32_t *seen,size_t *n,uint32_t at,uint32_t parent,unsigned kind,unsigned depth)
{
 if(!at||depth>64)return true;size_t slot=((uint32_t)(at*UINT32_C(2654435761)))&131071;while(seen[slot]){if(seen[slot]==at)return true;slot=(slot+1)&131071;}if(*n>=65536)return false;seen[slot]=at;q[(*n)++]=(sxdm_dbx_job){at,parent,kind,depth};return true;
}
static bool sxdm_dbx(sx_context *c)
{
 uint8_t b[636];uint32_t root;size_t count=0;bool ok=false;sxdm_dbx_job *queue=NULL;uint32_t *seen=NULL;
 if(!sxdm_add(c,&sxdm_dbx_header,0,9404)||!sx_u32(c,228,false,&root))return false;queue=xx_mem_alloc(65536*sizeof(*queue));seen=xx_mem_calloc(131072,sizeof(*seen));if(!queue||!seen)goto done;if(!sxdm_dbx_push(queue,seen,&count,root,0,0,0))goto done;
 for(size_t i=0;i<count;i++){
  sxdm_dbx_job j=queue[i];uint32_t at=j.at;if(xx_pd_is_stopped(c->pd))goto done;if(at<9404)continue;
  if(j.kind==0){
   if(!sxdm_span(c,at,24)||!sx_read(c,at,b,24)||sxdm_u32(b)!=at||(j.parent&&sxdm_u32(b+12)!=j.parent)||b[17]>51||!sxdm_span(c,(int64_t)at+24,(uint64_t)b[17]*12))continue;
   unsigned n=b[17];uint32_t left=sxdm_u32(b+8);if(!sxdm_add(c,&sxdm_dbx_node_header,at,24)||!sxdm_dbx_push(queue,seen,&count,left,at,0,j.depth+1))goto done;
   for(unsigned k=0;k<n;k++){int64_t pos=(int64_t)at+24+k*12;if(!sx_read(c,pos,b,12)||!sxdm_add(c,&sxdm_dbx_node_entry,pos,12)||!sxdm_dbx_push(queue,seen,&count,sxdm_u32(b),0,1,0)||!sxdm_dbx_push(queue,seen,&count,sxdm_u32(b+4),at,0,j.depth+1))goto done;}
  }else if(j.kind==1){
   if(!sxdm_span(c,at,12)||!sx_read(c,at,b,12)||sxdm_u32(b)!=at)continue;uint32_t body=sxdm_u32(b+4);unsigned n=b[10];if(n*4>body||!sxdm_span(c,(int64_t)at+12,body))continue;
   if(!sxdm_add(c,&sxdm_dbx_info_header,at,12))goto done;bool found=false;
   for(unsigned k=0;k<n;k++){int64_t pos=(int64_t)at+12+k*4;if(!sx_read(c,pos,b,4))goto done;const sx_layout *al=!(b[0]&128)?&sxdm_dbx_attribute_indirect:(b[0]&127)==4?&sxdm_dbx_attribute_message:&sxdm_dbx_attribute;if(!sxdm_add(c,al,pos,4))goto done;uint32_t v=sxdm_u32(b)>>8;if((b[0]&127)!=4||found)continue;found=true;
    if(!(b[0]&128)){uint64_t rel=(uint64_t)n*4+v;if(rel+4>body)continue;pos=(int64_t)at+12+(int64_t)rel;if(!sx_u32(c,pos,false,&v)||!sxdm_add(c,&sxdm_dbx_message_pointer,pos,4))goto done;}
    if(!sxdm_dbx_push(queue,seen,&count,v,0,2,0))goto done;
   }
  }else{
   if(!sxdm_span(c,at,16)||!sx_read(c,at,b,16)||sxdm_u32(b)!=at)continue;uint32_t allocated=sxdm_u32(b+4),used=sxdm_u32(b+8);if(!allocated||allocated>1048576||used>allocated||!sxdm_span(c,(int64_t)at+16,used))continue;
   if(!sxdm_add(c,&sxdm_dbx_block_header,at,16)||!sxdm_dbx_push(queue,seen,&count,sxdm_u32(b+12),0,2,0))goto done;
  }
 }ok=true;
done:xx_mem_free(queue);xx_mem_free(seen);return ok;
}
static bool sx_docmeta_build(sx_context *c)
{
 bool ok=false;
 switch(c->f->file_type){
 case XX_FILE_TYPE_DJVU:ok=sxdm_djvu(c);break;case XX_FILE_TYPE_ZXML:ok=sxdm_add(c,&sxdm_zxml_header,0,12);break;case XX_FILE_TYPE_LSZ:ok=sxdm_lsz(c);break;case XX_FILE_TYPE_PAIN:ok=sxdm_pain(c);break;case XX_FILE_TYPE_THEBAT_MSB:ok=sxdm_msb(c);break;case XX_FILE_TYPE_STYLUS:ok=sxdm_add(c,&sxdm_stylus_header,0,16);break;case XX_FILE_TYPE_PERFORM:ok=sxdm_add(c,&sxdm_perform_header,0,36);break;case XX_FILE_TYPE_PKT:ok=sxdm_pkt(c);break;case XX_FILE_TYPE_PAPERPORT:ok=sxdm_paperport(c);break;case XX_FILE_TYPE_WINDOWS_HELP:ok=sxdm_hlp(c);break;case XX_FILE_TYPE_IVT:ok=sxdm_ivt(c);break;case XX_FILE_TYPE_OPENZIM:ok=sxdm_zim(c);break;case XX_FILE_TYPE_HXS:case XX_FILE_TYPE_MICROSOFT_LIT:ok=sxdm_itolitls(c);break;case XX_FILE_TYPE_OUTLOOK_EXPRESS_DBX_MAILBOX:ok=sxdm_dbx(c);break;default:return false;}
 return ok&&sxdm_finish(c);
}
static bool sx_docmeta_comment(xx_data_struct_record *r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60230001)||id>UINT32_C(0x6023ffff))return true;
 const wchar_t *comment=NULL;uint64_t v=0;bool number=xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64;
 if(number)v=xx_var_get_u64(&r->value);
#define SDM_IS(l,n) (id==sxdm_##l.id&&!xx_rt_wcscmp(r->name,L##n))
 if(SDM_IS(djvu_info,"gamma_times_ten"))comment=L"Gamma multiplied by 10";
 else if(SDM_IS(djvu_info,"dpi"))comment=L"Dots per inch";
 else if(SDM_IS(djvu_info,"orientation"))comment=v==1?L"Upright":v==2?L"Upside down":v==5?L"Quarter-turn rotation, flag 5":v==6?L"Quarter-turn rotation, flag 6":L"Unknown orientation";
 else if(SDM_IS(djvu_form_header,"form_size"))comment=L"Bytes after the FORM size word, including form type and chunk padding";
 else if(SDM_IS(lsz_member_header,"method"))comment=v==1?L"Stored":v==2?L"PKWARE DCL implode":v==6?L"Empty member":NULL;
 else if(SDM_IS(lsz_member_header,"dos_time"))comment=L"DOS packed local time: hour:5, minute:6, seconds/2:5";
 else if(SDM_IS(lsz_member_header,"dos_date"))comment=L"DOS packed date: years since 1980:7, month:4, day:5";
 else if(SDM_IS(lsz_member_header,"attributes"))comment=L"DOS file attribute bits";
 else if(SDM_IS(pain_directory_entry,"method"))comment=v==0?L"Stored":v==3?L"PAiN LZSS":NULL;
 else if(SDM_IS(pain_lzss_block_header,"block_type"))comment=v==0?L"Compressed LZSS block":v==1?L"Stored block":NULL;
 else if(SDM_IS(stylus_header,"plaintext_crc32"))comment=L"CRC-32 of decoded dictionary";
 else if(SDM_IS(perform_header,"plaintext_crc16"))comment=L"CRC-16/ARC of decoded database";
 else if(SDM_IS(pkt_type2_header,"month_zero_based"))comment=L"0=January, 11=December";
 else if(SDM_IS(pkt_type2_header,"packet_type")||SDM_IS(pkt_message_header,"message_type"))comment=v==2?L"FidoNet Type 2":NULL;
 else if(SDM_IS(pkt_type2_header,"baud_rate"))comment=L"Bits per second";
 else if(SDM_IS(paperport_chunk_header,"chunk_type"))comment=v==0x8000?L"Root":v==0x4000?L"Page item":v==0x1000?L"Image object":NULL;
 else if(SDM_IS(zim_cluster_header,"compression_and_flags"))comment=(v&15)<=1?((v&16)?L"Stored; 64-bit blob offsets":L"Stored; 32-bit blob offsets"):(v&15)==4?L"XZ compressed cluster":(v&15)==5?L"Zstandard compressed cluster":L"Unknown cluster compression";
 else if(SDM_IS(zim_blob_offset32,"cluster_data_offset")||SDM_IS(zim_blob_offset64,"cluster_data_offset"))comment=L"Byte offset from stored cluster data, after its flag byte";
 else if(SDM_IS(zim_redirect_entry,"mime_type"))comment=L"Redirect entry (0xFFFF)";
 else if(SDM_IS(hxs_post_header,"caol_offset"))comment=L"Byte offset relative to post-header";
 else if(SDM_IS(dbx_attribute,"id_and_direct_flag")||SDM_IS(dbx_attribute_indirect,"id_and_direct_flag")||SDM_IS(dbx_attribute_message,"id_and_direct_flag"))comment=(v&128)?((v&127)==4?L"First message block; value stored directly":L"Direct attribute value"):((v&127)==4?L"First message block; value is data-area offset":L"Indirect attribute; offset into data area");
 else if(SDM_IS(dbx_attribute,"direct_value"))comment=L"24-bit direct attribute value";
 else if(SDM_IS(dbx_attribute_indirect,"data_offset"))comment=L"Byte offset relative to attribute data area, after all attribute words";
 else if(SDM_IS(dbx_attribute_message,"first_block_offset"))comment=L"Byte offset relative to file base, stored directly in the attribute";
 else if(r->property==SX_OFFSET)comment=L"Byte offset relative to file base";
 else if((!xx_rt_wcscmp(r->name,L"root_page")||!xx_rt_wcscmp(r->name,L"previous_page")||!xx_rt_wcscmp(r->name,L"next_page")||!xx_rt_wcscmp(r->name,L"child_page")||!xx_rt_wcscmp(r->name,L"last_leaf_page"))&&r->property==SX_ID)comment=L"Page index; sentinel values may denote no page";
#undef SDM_IS
 return !comment||xx_data_struct_record_set_comment(r,comment);
}
