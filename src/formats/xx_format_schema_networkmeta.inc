/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical metadata of native-validated network protocol streams. */
static const xx_data_struct_field_desc sxnm_ethernet_header_fields[]={
 SX_FIELD("destination_mac","bytes",0,6,SX_NONE),
 SX_FIELD("source_mac","bytes",6,6,SX_NONE),
 SX_FIELD("ether_type","uint16",12,2,SX_ID),
};
static const sx_layout sxnm_ethernet_header={UINT32_C(0x60260001),"ethernet_header",sxnm_ethernet_header_fields,SX_COUNT(sxnm_ethernet_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ipv4_header_fields[]={
 SX_FIELD("version_and_ihl","uint8",0,1,SX_FLAGS),
 SX_FIELD("dscp_and_ecn","uint8",1,1,SX_FLAGS),
 SX_FIELD("total_length","uint16",2,2,SX_SIZE),
 SX_FIELD("identification","uint16",4,2,SX_ID),
 SX_FIELD("flags_and_fragment_offset","uint16",6,2,SX_FLAGS),
 SX_FIELD("ttl","uint8",8,1,SX_NONE),
 SX_FIELD("protocol","uint8",9,1,SX_ID),
 SX_FIELD("header_checksum","uint16",10,2,SX_CHECKSUM),
 SX_FIELD("source_ipv4","bytes",12,4,SX_NONE),
 SX_FIELD("destination_ipv4","bytes",16,4,SX_NONE),
};
static const sx_layout sxnm_ipv4_header={UINT32_C(0x60260002),"ipv4_header",sxnm_ipv4_header_fields,SX_COUNT(sxnm_ipv4_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ipv6_header_fields[]={
 SX_FIELD("version_traffic_class_flow_label","uint32",0,4,SX_FLAGS),
 SX_FIELD("payload_length","uint16",4,2,SX_SIZE),
 SX_FIELD("next_header","uint8",6,1,SX_ID),
 SX_FIELD("hop_limit","uint8",7,1,SX_NONE),
 SX_FIELD("source_ipv6","bytes",8,16,SX_NONE),
 SX_FIELD("destination_ipv6","bytes",24,16,SX_NONE),
};
static const sx_layout sxnm_ipv6_header={UINT32_C(0x60260003),"ipv6_header",sxnm_ipv6_header_fields,SX_COUNT(sxnm_ipv6_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ipv4_single_byte_option_fields[]={
 SX_FIELD("option_type","uint8",0,1,SX_ID),
};
static const sx_layout sxnm_ipv4_single_byte_option={UINT32_C(0x60260004),"ipv4_single_byte_option",sxnm_ipv4_single_byte_option_fields,SX_COUNT(sxnm_ipv4_single_byte_option_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ipv4_option_header_fields[]={
 SX_FIELD("option_type","uint8",0,1,SX_ID),
 SX_FIELD("option_length","uint8",1,1,SX_SIZE),
};
static const sx_layout sxnm_ipv4_option_header={UINT32_C(0x60260005),"ipv4_option_header",sxnm_ipv4_option_header_fields,SX_COUNT(sxnm_ipv4_option_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_udp_header_fields[]={
 SX_FIELD("source_port","uint16",0,2,SX_ID),
 SX_FIELD("destination_port","uint16",2,2,SX_ID),
 SX_FIELD("datagram_length","uint16",4,2,SX_SIZE),
 SX_FIELD("checksum","uint16",6,2,SX_CHECKSUM),
};
static const sx_layout sxnm_udp_header={UINT32_C(0x60260006),"udp_header",sxnm_udp_header_fields,SX_COUNT(sxnm_udp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_icmp_echo_header_fields[]={
 SX_FIELD("message_type","uint8",0,1,SX_ID),
 SX_FIELD("code","uint8",1,1,SX_ID),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("identifier","uint16",4,2,SX_ID),
 SX_FIELD("sequence","uint16",6,2,SX_ID),
};
static const sx_layout sxnm_icmp_echo_header={UINT32_C(0x60260007),"icmp_echo_header",sxnm_icmp_echo_header_fields,SX_COUNT(sxnm_icmp_echo_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_bgp_message_header_fields[]={
 SX_FIELD("marker","bytes",0,16,SX_SIGNATURE),
 SX_FIELD("message_length","uint16",16,2,SX_SIZE),
 SX_FIELD("message_type","uint8",18,1,SX_ID),
};
static const sx_layout sxnm_bgp_message_header={UINT32_C(0x60260008),"bgp_message_header",sxnm_bgp_message_header_fields,SX_COUNT(sxnm_bgp_message_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_bgp_open_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("autonomous_system","uint16",1,2,SX_ID),
 SX_FIELD("hold_time","uint16",3,2,SX_NONE),
 SX_FIELD("router_identifier","bytes",5,4,SX_NONE),
 SX_FIELD("optional_parameters_length","uint8",9,1,SX_SIZE),
};
static const sx_layout sxnm_bgp_open={UINT32_C(0x60260009),"bgp_open",sxnm_bgp_open_fields,SX_COUNT(sxnm_bgp_open_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_bgp_optional_parameter_fields[]={
 SX_FIELD("parameter_type","uint8",0,1,SX_ID),
 SX_FIELD("parameter_length","uint8",1,1,SX_SIZE),
};
static const sx_layout sxnm_bgp_optional_parameter={UINT32_C(0x6026000A),"bgp_optional_parameter",sxnm_bgp_optional_parameter_fields,SX_COUNT(sxnm_bgp_optional_parameter_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_bgp_capability_header_fields[]={
 SX_FIELD("capability_code","uint8",0,1,SX_ID),
 SX_FIELD("capability_length","uint8",1,1,SX_SIZE),
};
static const sx_layout sxnm_bgp_capability_header={UINT32_C(0x6026000B),"bgp_capability_header",sxnm_bgp_capability_header_fields,SX_COUNT(sxnm_bgp_capability_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ospfv2_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("packet_type","uint8",1,1,SX_ID),
 SX_FIELD("packet_length","uint16",2,2,SX_SIZE),
 SX_FIELD("router_id","bytes",4,4,SX_NONE),
 SX_FIELD("area_id","bytes",8,4,SX_NONE),
 SX_FIELD("checksum","uint16",12,2,SX_CHECKSUM),
 SX_FIELD("authentication_type","uint16",14,2,SX_ID),
 SX_FIELD("authentication","bytes",16,8,SX_NONE),
};
static const sx_layout sxnm_ospfv2_header={UINT32_C(0x6026000C),"ospfv2_header",sxnm_ospfv2_header_fields,SX_COUNT(sxnm_ospfv2_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ospfv2_hello_fields[]={
 SX_FIELD("network_mask","bytes",0,4,SX_NONE),
 SX_FIELD("hello_interval","uint16",4,2,SX_NONE),
 SX_FIELD("options","uint8",6,1,SX_FLAGS),
 SX_FIELD("router_priority","uint8",7,1,SX_NONE),
 SX_FIELD("router_dead_interval","uint32",8,4,SX_NONE),
 SX_FIELD("designated_router","bytes",12,4,SX_NONE),
 SX_FIELD("backup_designated_router","bytes",16,4,SX_NONE),
};
static const sx_layout sxnm_ospfv2_hello={UINT32_C(0x6026000D),"ospfv2_hello",sxnm_ospfv2_hello_fields,SX_COUNT(sxnm_ospfv2_hello_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ospfv2_neighbor_fields[]={
 SX_FIELD("neighbor_router_id","bytes",0,4,SX_NONE),
};
static const sx_layout sxnm_ospfv2_neighbor={UINT32_C(0x6026000E),"ospfv2_neighbor",sxnm_ospfv2_neighbor_fields,SX_COUNT(sxnm_ospfv2_neighbor_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_sctp_common_header_fields[]={
 SX_FIELD("source_port","uint16",0,2,SX_ID),
 SX_FIELD("destination_port","uint16",2,2,SX_ID),
 SX_FIELD("verification_tag","uint32",4,4,SX_ID),
 SX_FIELD("checksum_crc32c","uint32le",8,4,SX_CHECKSUM),
};
static const sx_layout sxnm_sctp_common_header={UINT32_C(0x6026000F),"sctp_common_header",sxnm_sctp_common_header_fields,SX_COUNT(sxnm_sctp_common_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_sctp_data_chunk_fields[]={
 SX_FIELD("chunk_type","uint8",0,1,SX_ID),
 SX_FIELD("chunk_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("chunk_length","uint16",2,2,SX_SIZE),
 SX_FIELD("transmission_sequence","uint32",4,4,SX_ID),
 SX_FIELD("stream_identifier","uint16",8,2,SX_ID),
 SX_FIELD("stream_sequence","uint16",10,2,SX_ID),
 SX_FIELD("payload_protocol_identifier","uint32",12,4,SX_ID),
};
static const sx_layout sxnm_sctp_data_chunk={UINT32_C(0x60260010),"sctp_data_chunk",sxnm_sctp_data_chunk_fields,SX_COUNT(sxnm_sctp_data_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_header_fields[]={
 SX_FIELD("initiator_cookie","bytes",0,8,SX_ID),
 SX_FIELD("responder_cookie","bytes",8,8,SX_ID),
 SX_FIELD("next_payload","uint8",16,1,SX_ID),
 SX_FIELD("version","uint8",17,1,SX_ID),
 SX_FIELD("exchange_type","uint8",18,1,SX_ID),
 SX_FIELD("flags","uint8",19,1,SX_FLAGS),
 SX_FIELD("message_id","uint32",20,4,SX_ID),
 SX_FIELD("message_length","uint32",24,4,SX_SIZE),
};
static const sx_layout sxnm_isakmp_header={UINT32_C(0x60260011),"isakmp_header",sxnm_isakmp_header_fields,SX_COUNT(sxnm_isakmp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_sa_payload_fields[]={
 SX_FIELD("next_payload","uint8",0,1,SX_ID),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("payload_length","uint16",2,2,SX_SIZE),
 SX_FIELD("domain_of_interpretation","uint32",4,4,SX_ID),
 SX_FIELD("situation","uint32",8,4,SX_FLAGS),
};
static const sx_layout sxnm_isakmp_sa_payload={UINT32_C(0x60260012),"isakmp_sa_payload",sxnm_isakmp_sa_payload_fields,SX_COUNT(sxnm_isakmp_sa_payload_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_proposal_fields[]={
 SX_FIELD("next_payload","uint8",0,1,SX_ID),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("payload_length","uint16",2,2,SX_SIZE),
 SX_FIELD("proposal_number","uint8",4,1,SX_ID),
 SX_FIELD("protocol_id","uint8",5,1,SX_ID),
 SX_FIELD("spi_size","uint8",6,1,SX_SIZE),
 SX_FIELD("transform_count","uint8",7,1,SX_COUNT_PROP),
};
static const sx_layout sxnm_isakmp_proposal={UINT32_C(0x60260013),"isakmp_proposal",sxnm_isakmp_proposal_fields,SX_COUNT(sxnm_isakmp_proposal_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_transform_fields[]={
 SX_FIELD("next_payload","uint8",0,1,SX_ID),
 SX_FIELD("reserved1","uint8",1,1,SX_RESERVED),
 SX_FIELD("payload_length","uint16",2,2,SX_SIZE),
 SX_FIELD("transform_number","uint8",4,1,SX_ID),
 SX_FIELD("transform_id","uint8",5,1,SX_ID),
 SX_FIELD("reserved2","uint16",6,2,SX_RESERVED),
};
static const sx_layout sxnm_isakmp_transform={UINT32_C(0x60260014),"isakmp_transform",sxnm_isakmp_transform_fields,SX_COUNT(sxnm_isakmp_transform_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_basic_attribute_fields[]={
 SX_FIELD("format_and_type","uint16",0,2,SX_FLAGS),
 SX_FIELD("attribute_value","uint16",2,2,SX_NONE),
};
static const sx_layout sxnm_isakmp_basic_attribute={UINT32_C(0x60260015),"isakmp_basic_attribute",sxnm_isakmp_basic_attribute_fields,SX_COUNT(sxnm_isakmp_basic_attribute_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_variable_attribute_fields[]={
 SX_FIELD("format_and_type","uint16",0,2,SX_FLAGS),
 SX_FIELD("attribute_length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnm_isakmp_variable_attribute={UINT32_C(0x60260016),"isakmp_variable_attribute",sxnm_isakmp_variable_attribute_fields,SX_COUNT(sxnm_isakmp_variable_attribute_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtp_header_fields[]={
 SX_FIELD("version_padding_extension_csrc_count","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker_and_payload_type","uint8",1,1,SX_FLAGS),
 SX_FIELD("sequence_number","uint16",2,2,SX_ID),
 SX_FIELD("timestamp","uint32",4,4,SX_NONE),
 SX_FIELD("synchronization_source","uint32",8,4,SX_ID),
};
static const sx_layout sxnm_rtp_header={UINT32_C(0x60260017),"rtp_header",sxnm_rtp_header_fields,SX_COUNT(sxnm_rtp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtp_csrc_fields[]={
 SX_FIELD("contributing_source","uint32",0,4,SX_ID),
};
static const sx_layout sxnm_rtp_csrc={UINT32_C(0x60260018),"rtp_csrc",sxnm_rtp_csrc_fields,SX_COUNT(sxnm_rtp_csrc_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtp_extension_header_fields[]={
 SX_FIELD("profile","uint16",0,2,SX_ID),
 SX_FIELD("data_length_words","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxnm_rtp_extension_header={UINT32_C(0x60260019),"rtp_extension_header",sxnm_rtp_extension_header_fields,SX_COUNT(sxnm_rtp_extension_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtp_padding_count_fields[]={
 SX_FIELD("padding_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnm_rtp_padding_count={UINT32_C(0x6026001A),"rtp_padding_count",sxnm_rtp_padding_count_fields,SX_COUNT(sxnm_rtp_padding_count_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_header_fields[]={
 SX_FIELD("version_padding_count","uint8",0,1,SX_FLAGS),
 SX_FIELD("packet_type","uint8",1,1,SX_ID),
 SX_FIELD("length_words_minus_one","uint16",2,2,SX_NONE),
};
static const sx_layout sxnm_rtcp_header={UINT32_C(0x6026001B),"rtcp_header",sxnm_rtcp_header_fields,SX_COUNT(sxnm_rtcp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_sender_info_fields[]={
 SX_FIELD("synchronization_source","uint32",0,4,SX_ID),
 SX_FIELD("ntp_seconds","uint32",4,4,SX_TIME),
 SX_FIELD("ntp_fraction","uint32",8,4,SX_NONE),
 SX_FIELD("rtp_timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("sender_packet_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("sender_octet_count","uint32",20,4,SX_SIZE),
};
static const sx_layout sxnm_rtcp_sender_info={UINT32_C(0x6026001C),"rtcp_sender_info",sxnm_rtcp_sender_info_fields,SX_COUNT(sxnm_rtcp_sender_info_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_receiver_info_fields[]={
 SX_FIELD("synchronization_source","uint32",0,4,SX_ID),
};
static const sx_layout sxnm_rtcp_receiver_info={UINT32_C(0x6026001D),"rtcp_receiver_info",sxnm_rtcp_receiver_info_fields,SX_COUNT(sxnm_rtcp_receiver_info_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_report_block_fields[]={
 SX_FIELD("source_identifier","uint32",0,4,SX_ID),
 SX_FIELD("fraction_lost","uint8",4,1,SX_NONE),
 SX_FIELD("cumulative_packets_lost","int24",5,3,SX_NONE),
 SX_FIELD("extended_highest_sequence","uint32",8,4,SX_ID),
 SX_FIELD("interarrival_jitter","uint32",12,4,SX_NONE),
 SX_FIELD("last_sender_report","uint32",16,4,SX_NONE),
 SX_FIELD("delay_since_last_report","uint32",20,4,SX_NONE),
};
static const sx_layout sxnm_rtcp_report_block={UINT32_C(0x6026001E),"rtcp_report_block",sxnm_rtcp_report_block_fields,SX_COUNT(sxnm_rtcp_report_block_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_source_fields[]={
 SX_FIELD("source_identifier","uint32",0,4,SX_ID),
};
static const sx_layout sxnm_rtcp_source={UINT32_C(0x6026001F),"rtcp_source",sxnm_rtcp_source_fields,SX_COUNT(sxnm_rtcp_source_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_sdes_item_fields[]={
 SX_FIELD("item_type","uint8",0,1,SX_ID),
 SX_FIELD("text_length","uint8",1,1,SX_SIZE),
};
static const sx_layout sxnm_rtcp_sdes_item={UINT32_C(0x60260020),"rtcp_sdes_item",sxnm_rtcp_sdes_item_fields,SX_COUNT(sxnm_rtcp_sdes_item_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_sdes_end_fields[]={
 SX_FIELD("zero","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxnm_rtcp_sdes_end={UINT32_C(0x60260021),"rtcp_sdes_end",sxnm_rtcp_sdes_end_fields,SX_COUNT(sxnm_rtcp_sdes_end_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_bye_reason_fields[]={
 SX_FIELD("reason_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnm_rtcp_bye_reason={UINT32_C(0x60260022),"rtcp_bye_reason",sxnm_rtcp_bye_reason_fields,SX_COUNT(sxnm_rtcp_bye_reason_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_app_header_fields[]={
 SX_FIELD("source_identifier","uint32",0,4,SX_ID),
 SX_FIELD("name","char[4]",4,4,SX_ID),
};
static const sx_layout sxnm_rtcp_app_header={UINT32_C(0x60260023),"rtcp_app_header",sxnm_rtcp_app_header_fields,SX_COUNT(sxnm_rtcp_app_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_record_header_fields[]={
 SX_FIELD("content_type","uint8",0,1,SX_ID),
 SX_FIELD("legacy_record_version","uint16",1,2,SX_ID),
 SX_FIELD("payload_length","uint16",3,2,SX_SIZE),
};
static const sx_layout sxnm_tls_record_header={UINT32_C(0x60260024),"tls_record_header",sxnm_tls_record_header_fields,SX_COUNT(sxnm_tls_record_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_handshake_header_fields[]={
 SX_FIELD("handshake_type","uint8",0,1,SX_ID),
 SX_FIELD("body_length","uint24",1,3,SX_SIZE),
};
static const sx_layout sxnm_tls_handshake_header={UINT32_C(0x60260025),"tls_handshake_header",sxnm_tls_handshake_header_fields,SX_COUNT(sxnm_tls_handshake_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_hello_prefix_fields[]={
 SX_FIELD("legacy_version","uint16",0,2,SX_ID),
 SX_FIELD("random","bytes",2,32,SX_NONE),
};
static const sx_layout sxnm_tls_hello_prefix={UINT32_C(0x60260026),"tls_hello_prefix",sxnm_tls_hello_prefix_fields,SX_COUNT(sxnm_tls_hello_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_session_id_length_fields[]={
 SX_FIELD("session_id_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnm_tls_session_id_length={UINT32_C(0x60260027),"tls_session_id_length",sxnm_tls_session_id_length_fields,SX_COUNT(sxnm_tls_session_id_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_cipher_suites_length_fields[]={
 SX_FIELD("cipher_suites_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnm_tls_cipher_suites_length={UINT32_C(0x60260028),"tls_cipher_suites_length",sxnm_tls_cipher_suites_length_fields,SX_COUNT(sxnm_tls_cipher_suites_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_cipher_suite_fields[]={
 SX_FIELD("cipher_suite","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_tls_cipher_suite={UINT32_C(0x60260029),"tls_cipher_suite",sxnm_tls_cipher_suite_fields,SX_COUNT(sxnm_tls_cipher_suite_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_compression_methods_length_fields[]={
 SX_FIELD("compression_methods_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnm_tls_compression_methods_length={UINT32_C(0x6026002A),"tls_compression_methods_length",sxnm_tls_compression_methods_length_fields,SX_COUNT(sxnm_tls_compression_methods_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_compression_method_fields[]={
 SX_FIELD("compression_method","uint8",0,1,SX_ID),
};
static const sx_layout sxnm_tls_compression_method={UINT32_C(0x6026002B),"tls_compression_method",sxnm_tls_compression_method_fields,SX_COUNT(sxnm_tls_compression_method_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_extensions_length_fields[]={
 SX_FIELD("extensions_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnm_tls_extensions_length={UINT32_C(0x6026002C),"tls_extensions_length",sxnm_tls_extensions_length_fields,SX_COUNT(sxnm_tls_extensions_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_extension_header_fields[]={
 SX_FIELD("extension_type","uint16",0,2,SX_ID),
 SX_FIELD("extension_length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnm_tls_extension_header={UINT32_C(0x6026002D),"tls_extension_header",sxnm_tls_extension_header_fields,SX_COUNT(sxnm_tls_extension_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_change_cipher_spec_fields[]={
 SX_FIELD("compatibility_value","uint8",0,1,SX_ID),
};
static const sx_layout sxnm_tls_change_cipher_spec={UINT32_C(0x6026002E),"tls_change_cipher_spec",sxnm_tls_change_cipher_spec_fields,SX_COUNT(sxnm_tls_change_cipher_spec_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_diameter_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("message_length","uint24",1,3,SX_SIZE),
 SX_FIELD("command_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("command_code","uint24",5,3,SX_ID),
 SX_FIELD("application_id","uint32",8,4,SX_ID),
 SX_FIELD("hop_by_hop_identifier","uint32",12,4,SX_ID),
 SX_FIELD("end_to_end_identifier","uint32",16,4,SX_ID),
};
static const sx_layout sxnm_diameter_header={UINT32_C(0x6026002F),"diameter_header",sxnm_diameter_header_fields,SX_COUNT(sxnm_diameter_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_diameter_avp_header_fields[]={
 SX_FIELD("avp_code","uint32",0,4,SX_ID),
 SX_FIELD("avp_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("avp_length","uint24",5,3,SX_SIZE),
};
static const sx_layout sxnm_diameter_avp_header={UINT32_C(0x60260030),"diameter_avp_header",sxnm_diameter_avp_header_fields,SX_COUNT(sxnm_diameter_avp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_diameter_address_family_fields[]={
 SX_FIELD("address_family","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_diameter_address_family={UINT32_C(0x60260031),"diameter_address_family",sxnm_diameter_address_family_fields,SX_COUNT(sxnm_diameter_address_family_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_diameter_vendor_id_fields[]={
 SX_FIELD("vendor_id","uint32",0,4,SX_ID),
};
static const sx_layout sxnm_diameter_vendor_id={UINT32_C(0x60260032),"diameter_vendor_id",sxnm_diameter_vendor_id_fields,SX_COUNT(sxnm_diameter_vendor_id_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tacacs_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("packet_type","uint8",1,1,SX_ID),
 SX_FIELD("sequence_number","uint8",2,1,SX_ID),
 SX_FIELD("flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("session_id","uint32",4,4,SX_ID),
 SX_FIELD("body_length","uint32",8,4,SX_SIZE),
};
static const sx_layout sxnm_tacacs_header={UINT32_C(0x60260033),"tacacs_header",sxnm_tacacs_header_fields,SX_COUNT(sxnm_tacacs_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tacacs_authentication_start_fields[]={
 SX_FIELD("action","uint8",0,1,SX_ID),
 SX_FIELD("privilege_level","uint8",1,1,SX_NONE),
 SX_FIELD("authentication_type","uint8",2,1,SX_ID),
 SX_FIELD("service","uint8",3,1,SX_ID),
 SX_FIELD("user_length","uint8",4,1,SX_SIZE),
 SX_FIELD("port_length","uint8",5,1,SX_SIZE),
 SX_FIELD("remote_address_length","uint8",6,1,SX_SIZE),
 SX_FIELD("data_length","uint8",7,1,SX_SIZE),
};
static const sx_layout sxnm_tacacs_authentication_start={UINT32_C(0x60260034),"tacacs_authentication_start",sxnm_tacacs_authentication_start_fields,SX_COUNT(sxnm_tacacs_authentication_start_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gtpv1_header_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("message_type","uint8",1,1,SX_ID),
 SX_FIELD("payload_length","uint16",2,2,SX_SIZE),
 SX_FIELD("tunnel_endpoint_identifier","uint32",4,4,SX_ID),
};
static const sx_layout sxnm_gtpv1_header={UINT32_C(0x60260035),"gtpv1_header",sxnm_gtpv1_header_fields,SX_COUNT(sxnm_gtpv1_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_node_header_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("message_type","uint8",1,1,SX_ID),
 SX_FIELD("message_length","uint16",2,2,SX_SIZE),
 SX_FIELD("sequence_number","uint24",4,3,SX_ID),
 SX_FIELD("spare","uint8",7,1,SX_RESERVED),
};
static const sx_layout sxnm_pfcp_node_header={UINT32_C(0x60260036),"pfcp_node_header",sxnm_pfcp_node_header_fields,SX_COUNT(sxnm_pfcp_node_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_information_element_fields[]={
 SX_FIELD("ie_type","uint16",0,2,SX_ID),
 SX_FIELD("value_length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnm_pfcp_information_element={UINT32_C(0x60260037),"pfcp_information_element",sxnm_pfcp_information_element_fields,SX_COUNT(sxnm_pfcp_information_element_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_node_id_type_fields[]={
 SX_FIELD("node_id_type","uint8",0,1,SX_ID),
};
static const sx_layout sxnm_pfcp_node_id_type={UINT32_C(0x60260038),"pfcp_node_id_type",sxnm_pfcp_node_id_type_fields,SX_COUNT(sxnm_pfcp_node_id_type_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_node_ipv4_fields[]={
 SX_FIELD("node_ipv4","bytes",0,4,SX_NONE),
};
static const sx_layout sxnm_pfcp_node_ipv4={UINT32_C(0x60260039),"pfcp_node_ipv4",sxnm_pfcp_node_ipv4_fields,SX_COUNT(sxnm_pfcp_node_ipv4_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_node_ipv6_fields[]={
 SX_FIELD("node_ipv6","bytes",0,16,SX_NONE),
};
static const sx_layout sxnm_pfcp_node_ipv6={UINT32_C(0x6026003A),"pfcp_node_ipv6",sxnm_pfcp_node_ipv6_fields,SX_COUNT(sxnm_pfcp_node_ipv6_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_dns_label_fields[]={
 SX_FIELD("label_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnm_pfcp_dns_label={UINT32_C(0x6026003B),"pfcp_dns_label",sxnm_pfcp_dns_label_fields,SX_COUNT(sxnm_pfcp_dns_label_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_recovery_time_fields[]={
 SX_FIELD("ntp_seconds","uint32",0,4,SX_TIME),
};
static const sx_layout sxnm_pfcp_recovery_time={UINT32_C(0x6026003C),"pfcp_recovery_time",sxnm_pfcp_recovery_time_fields,SX_COUNT(sxnm_pfcp_recovery_time_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pptp_control_header_fields[]={
 SX_FIELD("message_length","uint16",0,2,SX_SIZE),
 SX_FIELD("message_type","uint16",2,2,SX_ID),
 SX_FIELD("magic_cookie","uint32",4,4,SX_SIGNATURE),
 SX_FIELD("control_message_type","uint16",8,2,SX_ID),
 SX_FIELD("reserved","uint16",10,2,SX_RESERVED),
};
static const sx_layout sxnm_pptp_control_header={UINT32_C(0x6026003D),"pptp_control_header",sxnm_pptp_control_header_fields,SX_COUNT(sxnm_pptp_control_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pptp_start_control_connection_fields[]={
 SX_FIELD("protocol_version","uint16",0,2,SX_ID),
 SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
 SX_FIELD("framing_capabilities","uint32",4,4,SX_FLAGS),
 SX_FIELD("bearer_capabilities","uint32",8,4,SX_FLAGS),
 SX_FIELD("maximum_channels","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("firmware_revision","uint16",14,2,SX_ID),
 SX_FIELD("host_name","char[64]",16,64,SX_STRING),
 SX_FIELD("vendor_string","char[64]",80,64,SX_STRING),
};
static const sx_layout sxnm_pptp_start_control_connection={UINT32_C(0x6026003E),"pptp_start_control_connection",sxnm_pptp_start_control_connection_fields,SX_COUNT(sxnm_pptp_start_control_connection_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rsvp_header_fields[]={
 SX_FIELD("version_and_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("message_type","uint8",1,1,SX_ID),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("send_ttl","uint8",4,1,SX_NONE),
 SX_FIELD("reserved","uint8",5,1,SX_RESERVED),
 SX_FIELD("message_length","uint16",6,2,SX_SIZE),
};
static const sx_layout sxnm_rsvp_header={UINT32_C(0x6026003F),"rsvp_header",sxnm_rsvp_header_fields,SX_COUNT(sxnm_rsvp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rsvp_object_header_fields[]={
 SX_FIELD("object_length","uint16",0,2,SX_SIZE),
 SX_FIELD("class_number","uint8",2,1,SX_ID),
 SX_FIELD("class_type","uint8",3,1,SX_ID),
};
static const sx_layout sxnm_rsvp_object_header={UINT32_C(0x60260040),"rsvp_object_header",sxnm_rsvp_object_header_fields,SX_COUNT(sxnm_rsvp_object_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rsvp_hello_instances_fields[]={
 SX_FIELD("source_instance","uint32",0,4,SX_ID),
 SX_FIELD("destination_instance","uint32",4,4,SX_ID),
};
static const sx_layout sxnm_rsvp_hello_instances={UINT32_C(0x60260041),"rsvp_hello_instances",sxnm_rsvp_hello_instances_fields,SX_COUNT(sxnm_rsvp_hello_instances_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_header_fields[]={
 SX_FIELD("version_and_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
};
static const sx_layout sxnm_pim_header={UINT32_C(0x60260042),"pim_header",sxnm_pim_header_fields,SX_COUNT(sxnm_pim_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_option_header_fields[]={
 SX_FIELD("option_type","uint16",0,2,SX_ID),
 SX_FIELD("option_length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnm_pim_option_header={UINT32_C(0x60260043),"pim_option_header",sxnm_pim_option_header_fields,SX_COUNT(sxnm_pim_option_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_holdtime_fields[]={
 SX_FIELD("hold_time","uint16",0,2,SX_NONE),
};
static const sx_layout sxnm_pim_holdtime={UINT32_C(0x60260044),"pim_holdtime",sxnm_pim_holdtime_fields,SX_COUNT(sxnm_pim_holdtime_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_lan_prune_delay_fields[]={
 SX_FIELD("tracking_and_propagation_delay","uint16",0,2,SX_FLAGS),
 SX_FIELD("override_interval","uint16",2,2,SX_NONE),
};
static const sx_layout sxnm_pim_lan_prune_delay={UINT32_C(0x60260045),"pim_lan_prune_delay",sxnm_pim_lan_prune_delay_fields,SX_COUNT(sxnm_pim_lan_prune_delay_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_dr_priority_fields[]={
 SX_FIELD("designated_router_priority","uint32",0,4,SX_NONE),
};
static const sx_layout sxnm_pim_dr_priority={UINT32_C(0x60260046),"pim_dr_priority",sxnm_pim_dr_priority_fields,SX_COUNT(sxnm_pim_dr_priority_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_generation_id_fields[]={
 SX_FIELD("generation_identifier","uint32",0,4,SX_ID),
};
static const sx_layout sxnm_pim_generation_id={UINT32_C(0x60260047),"pim_generation_id",sxnm_pim_generation_id_fields,SX_COUNT(sxnm_pim_generation_id_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_pdu_header_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("pdu_length","uint16",2,2,SX_SIZE),
 SX_FIELD("router_identifier","bytes",4,4,SX_NONE),
 SX_FIELD("label_space","uint16",8,2,SX_ID),
};
static const sx_layout sxnm_ldp_pdu_header={UINT32_C(0x60260048),"ldp_pdu_header",sxnm_ldp_pdu_header_fields,SX_COUNT(sxnm_ldp_pdu_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_message_header_fields[]={
 SX_FIELD("unknown_bit_and_type","uint16",0,2,SX_FLAGS),
 SX_FIELD("message_length","uint16",2,2,SX_SIZE),
 SX_FIELD("message_id","uint32",4,4,SX_ID),
};
static const sx_layout sxnm_ldp_message_header={UINT32_C(0x60260049),"ldp_message_header",sxnm_ldp_message_header_fields,SX_COUNT(sxnm_ldp_message_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_tlv_header_fields[]={
 SX_FIELD("flags_and_type","uint16",0,2,SX_FLAGS),
 SX_FIELD("value_length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnm_ldp_tlv_header={UINT32_C(0x6026004A),"ldp_tlv_header",sxnm_ldp_tlv_header_fields,SX_COUNT(sxnm_ldp_tlv_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_common_hello_fields[]={
 SX_FIELD("hold_time","uint16",0,2,SX_NONE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
};
static const sx_layout sxnm_ldp_common_hello={UINT32_C(0x6026004B),"ldp_common_hello",sxnm_ldp_common_hello_fields,SX_COUNT(sxnm_ldp_common_hello_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_ipv4_transport_fields[]={
 SX_FIELD("transport_ipv4","bytes",0,4,SX_NONE),
};
static const sx_layout sxnm_ldp_ipv4_transport={UINT32_C(0x6026004C),"ldp_ipv4_transport",sxnm_ldp_ipv4_transport_fields,SX_COUNT(sxnm_ldp_ipv4_transport_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_configuration_sequence_fields[]={
 SX_FIELD("configuration_sequence","uint32",0,4,SX_ID),
};
static const sx_layout sxnm_ldp_configuration_sequence={UINT32_C(0x6026004D),"ldp_configuration_sequence",sxnm_ldp_configuration_sequence_fields,SX_COUNT(sxnm_ldp_configuration_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gre_header_fields[]={
 SX_FIELD("flags_and_version","uint16",0,2,SX_FLAGS),
 SX_FIELD("protocol_type","uint16",2,2,SX_ID),
};
static const sx_layout sxnm_gre_header={UINT32_C(0x6026004E),"gre_header",sxnm_gre_header_fields,SX_COUNT(sxnm_gre_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gre_checksum_fields[]={
 SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
};
static const sx_layout sxnm_gre_checksum={UINT32_C(0x6026004F),"gre_checksum",sxnm_gre_checksum_fields,SX_COUNT(sxnm_gre_checksum_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gre_key_fields[]={
 SX_FIELD("key","uint32",0,4,SX_ID),
};
static const sx_layout sxnm_gre_key={UINT32_C(0x60260050),"gre_key",sxnm_gre_key_fields,SX_COUNT(sxnm_gre_key_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gre_sequence_fields[]={
 SX_FIELD("sequence_number","uint32",0,4,SX_ID),
};
static const sx_layout sxnm_gre_sequence={UINT32_C(0x60260051),"gre_sequence",sxnm_gre_sequence_fields,SX_COUNT(sxnm_gre_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_control_header_fields[]={
 SX_FIELD("flags_and_version","uint16",0,2,SX_FLAGS),
 SX_FIELD("message_length","uint16",2,2,SX_SIZE),
 SX_FIELD("tunnel_id","uint16",4,2,SX_ID),
 SX_FIELD("session_id","uint16",6,2,SX_ID),
 SX_FIELD("send_sequence","uint16",8,2,SX_ID),
 SX_FIELD("receive_sequence","uint16",10,2,SX_ID),
};
static const sx_layout sxnm_l2tp_control_header={UINT32_C(0x60260052),"l2tp_control_header",sxnm_l2tp_control_header_fields,SX_COUNT(sxnm_l2tp_control_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_avp_header_fields[]={
 SX_FIELD("flags_and_length","uint16",0,2,SX_FLAGS),
 SX_FIELD("vendor_id","uint16",2,2,SX_ID),
 SX_FIELD("attribute_type","uint16",4,2,SX_ID),
};
static const sx_layout sxnm_l2tp_avp_header={UINT32_C(0x60260053),"l2tp_avp_header",sxnm_l2tp_avp_header_fields,SX_COUNT(sxnm_l2tp_avp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_message_type_fields[]={
 SX_FIELD("message_type","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_l2tp_message_type={UINT32_C(0x60260054),"l2tp_message_type",sxnm_l2tp_message_type_fields,SX_COUNT(sxnm_l2tp_message_type_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_protocol_version_fields[]={
 SX_FIELD("protocol_version","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_l2tp_protocol_version={UINT32_C(0x60260055),"l2tp_protocol_version",sxnm_l2tp_protocol_version_fields,SX_COUNT(sxnm_l2tp_protocol_version_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_firmware_revision_fields[]={
 SX_FIELD("firmware_revision","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_l2tp_firmware_revision={UINT32_C(0x60260056),"l2tp_firmware_revision",sxnm_l2tp_firmware_revision_fields,SX_COUNT(sxnm_l2tp_firmware_revision_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_assigned_tunnel_fields[]={
 SX_FIELD("tunnel_id","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_l2tp_assigned_tunnel={UINT32_C(0x60260057),"l2tp_assigned_tunnel",sxnm_l2tp_assigned_tunnel_fields,SX_COUNT(sxnm_l2tp_assigned_tunnel_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_receive_window_fields[]={
 SX_FIELD("window_packets","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnm_l2tp_receive_window={UINT32_C(0x60260058),"l2tp_receive_window",sxnm_l2tp_receive_window_fields,SX_COUNT(sxnm_l2tp_receive_window_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_framing_capabilities_fields[]={
 SX_FIELD("framing_capabilities","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxnm_l2tp_framing_capabilities={UINT32_C(0x60260059),"l2tp_framing_capabilities",sxnm_l2tp_framing_capabilities_fields,SX_COUNT(sxnm_l2tp_framing_capabilities_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_bearer_capabilities_fields[]={
 SX_FIELD("bearer_capabilities","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxnm_l2tp_bearer_capabilities={UINT32_C(0x6026005A),"l2tp_bearer_capabilities",sxnm_l2tp_bearer_capabilities_fields,SX_COUNT(sxnm_l2tp_bearer_capabilities_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_netflow_v5_header_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("record_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("system_uptime_ms","uint32",4,4,SX_NONE),
 SX_FIELD("unix_seconds","uint32",8,4,SX_TIME),
 SX_FIELD("unix_nanoseconds","uint32",12,4,SX_NONE),
 SX_FIELD("flow_sequence","uint32",16,4,SX_ID),
 SX_FIELD("engine_type","uint8",20,1,SX_ID),
 SX_FIELD("engine_id","uint8",21,1,SX_ID),
 SX_FIELD("sampling_mode_and_interval","uint16",22,2,SX_FLAGS),
};
static const sx_layout sxnm_netflow_v5_header={UINT32_C(0x6026005B),"netflow_v5_header",sxnm_netflow_v5_header_fields,SX_COUNT(sxnm_netflow_v5_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_netflow_v5_record_fields[]={
 SX_FIELD("source_ipv4","bytes",0,4,SX_NONE),
 SX_FIELD("destination_ipv4","bytes",4,4,SX_NONE),
 SX_FIELD("next_hop_ipv4","bytes",8,4,SX_NONE),
 SX_FIELD("input_interface","uint16",12,2,SX_ID),
 SX_FIELD("output_interface","uint16",14,2,SX_ID),
 SX_FIELD("packet_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("octet_count","uint32",20,4,SX_SIZE),
 SX_FIELD("first_uptime_ms","uint32",24,4,SX_NONE),
 SX_FIELD("last_uptime_ms","uint32",28,4,SX_NONE),
 SX_FIELD("source_port","uint16",32,2,SX_ID),
 SX_FIELD("destination_port","uint16",34,2,SX_ID),
 SX_FIELD("reserved1","uint8",36,1,SX_RESERVED),
 SX_FIELD("tcp_flags","uint8",37,1,SX_FLAGS),
 SX_FIELD("protocol","uint8",38,1,SX_ID),
 SX_FIELD("type_of_service","uint8",39,1,SX_FLAGS),
 SX_FIELD("source_as","uint16",40,2,SX_ID),
 SX_FIELD("destination_as","uint16",42,2,SX_ID),
 SX_FIELD("source_mask_bits","uint8",44,1,SX_NONE),
 SX_FIELD("destination_mask_bits","uint8",45,1,SX_NONE),
 SX_FIELD("reserved2","uint16",46,2,SX_RESERVED),
};
static const sx_layout sxnm_netflow_v5_record={UINT32_C(0x6026005C),"netflow_v5_record",sxnm_netflow_v5_record_fields,SX_COUNT(sxnm_netflow_v5_record_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ntlm_negotiate_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("message_type","uint32",8,4,SX_ID),
 SX_FIELD("negotiate_flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("domain_length","uint16",16,2,SX_SIZE),
 SX_FIELD("domain_max_length","uint16",18,2,SX_SIZE),
 SX_FIELD("domain_buffer_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("workstation_length","uint16",24,2,SX_SIZE),
 SX_FIELD("workstation_max_length","uint16",26,2,SX_SIZE),
 SX_FIELD("workstation_buffer_offset","uint32",28,4,SX_OFFSET),
};
static const sx_layout sxnm_ntlm_negotiate={UINT32_C(0x6026005D),"ntlm_negotiate",sxnm_ntlm_negotiate_fields,SX_COUNT(sxnm_ntlm_negotiate_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_ntlm_version_fields[]={
 SX_FIELD("product_major","uint8",0,1,SX_ID),
 SX_FIELD("product_minor","uint8",1,1,SX_ID),
 SX_FIELD("product_build","uint16",2,2,SX_ID),
 SX_FIELD("reserved","bytes",4,3,SX_RESERVED),
 SX_FIELD("revision","uint8",7,1,SX_ID),
};
static const sx_layout sxnm_ntlm_version={UINT32_C(0x6026005E),"ntlm_version",sxnm_ntlm_version_fields,SX_COUNT(sxnm_ntlm_version_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("protocol_major","uint8",4,1,SX_ID),
 SX_FIELD("protocol_minor","uint8",5,1,SX_ID),
 SX_FIELD("vendor_id","bytes",6,2,SX_ID),
 SX_FIELD("guid_prefix","bytes",8,12,SX_ID),
};
static const sx_layout sxnm_rtps_header={UINT32_C(0x6026005F),"rtps_header",sxnm_rtps_header_fields,SX_COUNT(sxnm_rtps_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_submessage_le_fields[]={
 SX_FIELD("submessage_id","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("following_length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnm_rtps_submessage_le={UINT32_C(0x60260060),"rtps_submessage_le",sxnm_rtps_submessage_le_fields,SX_COUNT(sxnm_rtps_submessage_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_timestamp_le_fields[]={
 SX_FIELD("seconds","int32",0,4,SX_TIME),
 SX_FIELD("fraction","uint32",4,4,SX_NONE),
};
static const sx_layout sxnm_rtps_timestamp_le={UINT32_C(0x60260061),"rtps_timestamp_le",sxnm_rtps_timestamp_le_fields,SX_COUNT(sxnm_rtps_timestamp_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_heartbeat_le_fields[]={
 SX_FIELD("reader_entity_id","bytes",0,4,SX_ID),
 SX_FIELD("writer_entity_id","bytes",4,4,SX_ID),
 SX_FIELD("first_sequence_high","int32",8,4,SX_NONE),
 SX_FIELD("first_sequence_low","uint32",12,4,SX_NONE),
 SX_FIELD("last_sequence_high","int32",16,4,SX_NONE),
 SX_FIELD("last_sequence_low","uint32",20,4,SX_NONE),
 SX_FIELD("heartbeat_count","int32",24,4,SX_ID),
};
static const sx_layout sxnm_rtps_heartbeat_le={UINT32_C(0x60260062),"rtps_heartbeat_le",sxnm_rtps_heartbeat_le_fields,SX_COUNT(sxnm_rtps_heartbeat_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_data_le_fields[]={
 SX_FIELD("extra_flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("inline_qos_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("reader_entity_id","bytes",4,4,SX_ID),
 SX_FIELD("writer_entity_id","bytes",8,4,SX_ID),
 SX_FIELD("sequence_high","int32",12,4,SX_NONE),
 SX_FIELD("sequence_low","uint32",16,4,SX_NONE),
};
static const sx_layout sxnm_rtps_data_le={UINT32_C(0x60260063),"rtps_data_le",sxnm_rtps_data_le_fields,SX_COUNT(sxnm_rtps_data_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_header_le_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("minor_version","uint8",1,1,SX_ID),
 SX_FIELD("packet_type","uint8",2,1,SX_ID),
 SX_FIELD("packet_flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("data_representation","bytes",4,4,SX_NONE),
 SX_FIELD("fragment_length","uint16",8,2,SX_SIZE),
 SX_FIELD("authentication_length","uint16",10,2,SX_SIZE),
 SX_FIELD("call_id","uint32",12,4,SX_ID),
};
static const sx_layout sxnm_dcerpc_header_le={UINT32_C(0x60260064),"dcerpc_header_le",sxnm_dcerpc_header_le_fields,SX_COUNT(sxnm_dcerpc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_bind_le_fields[]={
 SX_FIELD("maximum_transmit_fragment","uint16",0,2,SX_SIZE),
 SX_FIELD("maximum_receive_fragment","uint16",2,2,SX_SIZE),
 SX_FIELD("association_group","uint32",4,4,SX_ID),
 SX_FIELD("context_count","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",9,3,SX_RESERVED),
};
static const sx_layout sxnm_dcerpc_bind_le={UINT32_C(0x60260065),"dcerpc_bind_le",sxnm_dcerpc_bind_le_fields,SX_COUNT(sxnm_dcerpc_bind_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_context_le_fields[]={
 SX_FIELD("context_id","uint16",0,2,SX_ID),
 SX_FIELD("transfer_syntax_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("abstract_syntax_uuid","bytes",4,16,SX_ID),
 SX_FIELD("abstract_syntax_version","uint32",20,4,SX_ID),
};
static const sx_layout sxnm_dcerpc_context_le={UINT32_C(0x60260066),"dcerpc_context_le",sxnm_dcerpc_context_le_fields,SX_COUNT(sxnm_dcerpc_context_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_transfer_syntax_le_fields[]={
 SX_FIELD("transfer_syntax_uuid","bytes",0,16,SX_ID),
 SX_FIELD("transfer_syntax_version","uint32",16,4,SX_ID),
};
static const sx_layout sxnm_dcerpc_transfer_syntax_le={UINT32_C(0x60260067),"dcerpc_transfer_syntax_le",sxnm_dcerpc_transfer_syntax_le_fields,SX_COUNT(sxnm_dcerpc_transfer_syntax_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_request_le_fields[]={
 SX_FIELD("allocation_hint","uint32",0,4,SX_SIZE),
 SX_FIELD("context_id","uint16",4,2,SX_ID),
 SX_FIELD("operation_number","uint16",6,2,SX_ID),
};
static const sx_layout sxnm_dcerpc_request_le={UINT32_C(0x60260068),"dcerpc_request_le",sxnm_dcerpc_request_le_fields,SX_COUNT(sxnm_dcerpc_request_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_response_le_fields[]={
 SX_FIELD("allocation_hint","uint32",0,4,SX_SIZE),
 SX_FIELD("context_id","uint16",4,2,SX_ID),
 SX_FIELD("cancel_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
};
static const sx_layout sxnm_dcerpc_response_le={UINT32_C(0x60260069),"dcerpc_response_le",sxnm_dcerpc_response_le_fields,SX_COUNT(sxnm_dcerpc_response_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_submessage_be_fields[]={
 SX_FIELD("submessage_id","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("following_length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnm_rtps_submessage_be={UINT32_C(0x6026006A),"rtps_submessage_be",sxnm_rtps_submessage_be_fields,SX_COUNT(sxnm_rtps_submessage_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_timestamp_be_fields[]={
 SX_FIELD("seconds","int32",0,4,SX_TIME),
 SX_FIELD("fraction","uint32",4,4,SX_NONE),
};
static const sx_layout sxnm_rtps_timestamp_be={UINT32_C(0x6026006B),"rtps_timestamp_be",sxnm_rtps_timestamp_be_fields,SX_COUNT(sxnm_rtps_timestamp_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_heartbeat_be_fields[]={
 SX_FIELD("reader_entity_id","bytes",0,4,SX_ID),
 SX_FIELD("writer_entity_id","bytes",4,4,SX_ID),
 SX_FIELD("first_sequence_high","int32",8,4,SX_NONE),
 SX_FIELD("first_sequence_low","uint32",12,4,SX_NONE),
 SX_FIELD("last_sequence_high","int32",16,4,SX_NONE),
 SX_FIELD("last_sequence_low","uint32",20,4,SX_NONE),
 SX_FIELD("heartbeat_count","int32",24,4,SX_ID),
};
static const sx_layout sxnm_rtps_heartbeat_be={UINT32_C(0x6026006C),"rtps_heartbeat_be",sxnm_rtps_heartbeat_be_fields,SX_COUNT(sxnm_rtps_heartbeat_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_data_be_fields[]={
 SX_FIELD("extra_flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("inline_qos_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("reader_entity_id","bytes",4,4,SX_ID),
 SX_FIELD("writer_entity_id","bytes",8,4,SX_ID),
 SX_FIELD("sequence_high","int32",12,4,SX_NONE),
 SX_FIELD("sequence_low","uint32",16,4,SX_NONE),
};
static const sx_layout sxnm_rtps_data_be={UINT32_C(0x6026006D),"rtps_data_be",sxnm_rtps_data_be_fields,SX_COUNT(sxnm_rtps_data_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_header_be_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("minor_version","uint8",1,1,SX_ID),
 SX_FIELD("packet_type","uint8",2,1,SX_ID),
 SX_FIELD("packet_flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("data_representation","bytes",4,4,SX_NONE),
 SX_FIELD("fragment_length","uint16",8,2,SX_SIZE),
 SX_FIELD("authentication_length","uint16",10,2,SX_SIZE),
 SX_FIELD("call_id","uint32",12,4,SX_ID),
};
static const sx_layout sxnm_dcerpc_header_be={UINT32_C(0x6026006E),"dcerpc_header_be",sxnm_dcerpc_header_be_fields,SX_COUNT(sxnm_dcerpc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_bind_be_fields[]={
 SX_FIELD("maximum_transmit_fragment","uint16",0,2,SX_SIZE),
 SX_FIELD("maximum_receive_fragment","uint16",2,2,SX_SIZE),
 SX_FIELD("association_group","uint32",4,4,SX_ID),
 SX_FIELD("context_count","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",9,3,SX_RESERVED),
};
static const sx_layout sxnm_dcerpc_bind_be={UINT32_C(0x6026006F),"dcerpc_bind_be",sxnm_dcerpc_bind_be_fields,SX_COUNT(sxnm_dcerpc_bind_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_context_be_fields[]={
 SX_FIELD("context_id","uint16",0,2,SX_ID),
 SX_FIELD("transfer_syntax_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("abstract_syntax_uuid","bytes",4,16,SX_ID),
 SX_FIELD("abstract_syntax_version","uint32",20,4,SX_ID),
};
static const sx_layout sxnm_dcerpc_context_be={UINT32_C(0x60260070),"dcerpc_context_be",sxnm_dcerpc_context_be_fields,SX_COUNT(sxnm_dcerpc_context_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_transfer_syntax_be_fields[]={
 SX_FIELD("transfer_syntax_uuid","bytes",0,16,SX_ID),
 SX_FIELD("transfer_syntax_version","uint32",16,4,SX_ID),
};
static const sx_layout sxnm_dcerpc_transfer_syntax_be={UINT32_C(0x60260071),"dcerpc_transfer_syntax_be",sxnm_dcerpc_transfer_syntax_be_fields,SX_COUNT(sxnm_dcerpc_transfer_syntax_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_request_be_fields[]={
 SX_FIELD("allocation_hint","uint32",0,4,SX_SIZE),
 SX_FIELD("context_id","uint16",4,2,SX_ID),
 SX_FIELD("operation_number","uint16",6,2,SX_ID),
};
static const sx_layout sxnm_dcerpc_request_be={UINT32_C(0x60260072),"dcerpc_request_be",sxnm_dcerpc_request_be_fields,SX_COUNT(sxnm_dcerpc_request_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_response_be_fields[]={
 SX_FIELD("allocation_hint","uint32",0,4,SX_SIZE),
 SX_FIELD("context_id","uint16",4,2,SX_ID),
 SX_FIELD("cancel_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
};
static const sx_layout sxnm_dcerpc_response_be={UINT32_C(0x60260073),"dcerpc_response_be",sxnm_dcerpc_response_be_fields,SX_COUNT(sxnm_dcerpc_response_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_destination_fields[]={
 SX_FIELD("guid_prefix","bytes",0,12,SX_ID),
};
static const sx_layout sxnm_rtps_destination={UINT32_C(0x60260074),"rtps_destination",sxnm_rtps_destination_fields,SX_COUNT(sxnm_rtps_destination_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_cdr_encapsulation_fields[]={
 SX_FIELD("representation_identifier","uint16",0,2,SX_ID),
 SX_FIELD("representation_options","uint16",2,2,SX_FLAGS),
};
static const sx_layout sxnm_rtps_cdr_encapsulation={UINT32_C(0x60260075),"rtps_cdr_encapsulation",sxnm_rtps_cdr_encapsulation_fields,SX_COUNT(sxnm_rtps_cdr_encapsulation_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_control_byte_fields[]={
 SX_FIELD("packet_type_and_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnm_mqtt_control_byte={UINT32_C(0x60260076),"mqtt_control_byte",sxnm_mqtt_control_byte_fields,SX_COUNT(sxnm_mqtt_control_byte_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_remaining_length_1_fields[]={
 SX_FIELD("remaining_length","uleb128_64",0,1,SX_SIZE),
};
static const sx_layout sxnm_mqtt_remaining_length_1={UINT32_C(0x60260077),"mqtt_remaining_length_1",sxnm_mqtt_remaining_length_1_fields,SX_COUNT(sxnm_mqtt_remaining_length_1_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_remaining_length_2_fields[]={
 SX_FIELD("remaining_length","uleb128_64",0,2,SX_SIZE),
};
static const sx_layout sxnm_mqtt_remaining_length_2={UINT32_C(0x60260078),"mqtt_remaining_length_2",sxnm_mqtt_remaining_length_2_fields,SX_COUNT(sxnm_mqtt_remaining_length_2_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_remaining_length_3_fields[]={
 SX_FIELD("remaining_length","uleb128_64",0,3,SX_SIZE),
};
static const sx_layout sxnm_mqtt_remaining_length_3={UINT32_C(0x60260079),"mqtt_remaining_length_3",sxnm_mqtt_remaining_length_3_fields,SX_COUNT(sxnm_mqtt_remaining_length_3_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_remaining_length_4_fields[]={
 SX_FIELD("remaining_length","uleb128_64",0,4,SX_SIZE),
};
static const sx_layout sxnm_mqtt_remaining_length_4={UINT32_C(0x6026007A),"mqtt_remaining_length_4",sxnm_mqtt_remaining_length_4_fields,SX_COUNT(sxnm_mqtt_remaining_length_4_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_connect_fields[]={
 SX_FIELD("protocol_name_length","uint16",0,2,SX_SIZE),
 SX_FIELD("protocol_name","char[4]",2,4,SX_SIGNATURE),
 SX_FIELD("protocol_level","uint8",6,1,SX_ID),
 SX_FIELD("connect_flags","uint8",7,1,SX_FLAGS),
 SX_FIELD("keepalive_seconds","uint16",8,2,SX_NONE),
};
static const sx_layout sxnm_mqtt_connect={UINT32_C(0x6026007B),"mqtt_connect",sxnm_mqtt_connect_fields,SX_COUNT(sxnm_mqtt_connect_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_string_length_fields[]={
 SX_FIELD("string_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnm_mqtt_string_length={UINT32_C(0x6026007C),"mqtt_string_length",sxnm_mqtt_string_length_fields,SX_COUNT(sxnm_mqtt_string_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_connack_fields[]={
 SX_FIELD("session_present_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("return_code","uint8",1,1,SX_ID),
};
static const sx_layout sxnm_mqtt_connack={UINT32_C(0x6026007D),"mqtt_connack",sxnm_mqtt_connack_fields,SX_COUNT(sxnm_mqtt_connack_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_packet_id_fields[]={
 SX_FIELD("packet_identifier","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_mqtt_packet_id={UINT32_C(0x6026007E),"mqtt_packet_id",sxnm_mqtt_packet_id_fields,SX_COUNT(sxnm_mqtt_packet_id_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_requested_qos_fields[]={
 SX_FIELD("requested_qos","uint8",0,1,SX_ID),
};
static const sx_layout sxnm_mqtt_requested_qos={UINT32_C(0x6026007F),"mqtt_requested_qos",sxnm_mqtt_requested_qos_fields,SX_COUNT(sxnm_mqtt_requested_qos_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_suback_result_fields[]={
 SX_FIELD("result_code","uint8",0,1,SX_ID),
};
static const sx_layout sxnm_mqtt_suback_result={UINT32_C(0x60260080),"mqtt_suback_result",sxnm_mqtt_suback_result_fields,SX_COUNT(sxnm_mqtt_suback_result_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_protocol_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("protocol_id","uint8",4,1,SX_ID),
 SX_FIELD("major_version","uint8",5,1,SX_ID),
 SX_FIELD("minor_version","uint8",6,1,SX_ID),
 SX_FIELD("revision","uint8",7,1,SX_ID),
};
static const sx_layout sxnm_amqp_protocol_header={UINT32_C(0x60260081),"amqp_protocol_header",sxnm_amqp_protocol_header_fields,SX_COUNT(sxnm_amqp_protocol_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_frame_header_fields[]={
 SX_FIELD("frame_type","uint8",0,1,SX_ID),
 SX_FIELD("channel","uint16",1,2,SX_ID),
 SX_FIELD("payload_length","uint32",3,4,SX_SIZE),
};
static const sx_layout sxnm_amqp_frame_header={UINT32_C(0x60260082),"amqp_frame_header",sxnm_amqp_frame_header_fields,SX_COUNT(sxnm_amqp_frame_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_method_header_fields[]={
 SX_FIELD("class_id","uint16",0,2,SX_ID),
 SX_FIELD("method_id","uint16",2,2,SX_ID),
};
static const sx_layout sxnm_amqp_method_header={UINT32_C(0x60260083),"amqp_method_header",sxnm_amqp_method_header_fields,SX_COUNT(sxnm_amqp_method_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_content_header_fields[]={
 SX_FIELD("class_id","uint16",0,2,SX_ID),
 SX_FIELD("weight","uint16",2,2,SX_NONE),
 SX_FIELD("body_size","uint64",4,8,SX_SIZE),
 SX_FIELD("property_flags","uint16",12,2,SX_FLAGS),
};
static const sx_layout sxnm_amqp_content_header={UINT32_C(0x60260084),"amqp_content_header",sxnm_amqp_content_header_fields,SX_COUNT(sxnm_amqp_content_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_frame_end_fields[]={
 SX_FIELD("end_marker","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxnm_amqp_frame_end={UINT32_C(0x60260085),"amqp_frame_end",sxnm_amqp_frame_end_fields,SX_COUNT(sxnm_amqp_frame_end_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_publish_prefix_fields[]={
 SX_FIELD("reserved_ticket","uint16",0,2,SX_RESERVED),
};
static const sx_layout sxnm_amqp_publish_prefix={UINT32_C(0x60260086),"amqp_publish_prefix",sxnm_amqp_publish_prefix_fields,SX_COUNT(sxnm_amqp_publish_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_publish_flags_fields[]={
 SX_FIELD("mandatory_and_immediate","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnm_amqp_publish_flags={UINT32_C(0x60260087),"amqp_publish_flags",sxnm_amqp_publish_flags_fields,SX_COUNT(sxnm_amqp_publish_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_close_code_fields[]={
 SX_FIELD("reply_code","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_amqp_close_code={UINT32_C(0x60260088),"amqp_close_code",sxnm_amqp_close_code_fields,SX_COUNT(sxnm_amqp_close_code_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_close_method_fields[]={
 SX_FIELD("class_id","uint16",0,2,SX_ID),
 SX_FIELD("method_id","uint16",2,2,SX_ID),
};
static const sx_layout sxnm_amqp_close_method={UINT32_C(0x60260089),"amqp_close_method",sxnm_amqp_close_method_fields,SX_COUNT(sxnm_amqp_close_method_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_short_string_fields[]={
 SX_FIELD("byte_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxnm_amqp_short_string={UINT32_C(0x6026008A),"amqp_short_string",sxnm_amqp_short_string_fields,SX_COUNT(sxnm_amqp_short_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_table_length_fields[]={
 SX_FIELD("table_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnm_amqp_table_length={UINT32_C(0x6026008B),"amqp_table_length",sxnm_amqp_table_length_fields,SX_COUNT(sxnm_amqp_table_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_field_type_fields[]={
 SX_FIELD("field_type","uint8",0,1,SX_ID),
};
static const sx_layout sxnm_amqp_field_type={UINT32_C(0x6026008C),"amqp_field_type",sxnm_amqp_field_type_fields,SX_COUNT(sxnm_amqp_field_type_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_uint8_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxnm_amqp_uint8={UINT32_C(0x6026008D),"amqp_uint8",sxnm_amqp_uint8_fields,SX_COUNT(sxnm_amqp_uint8_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_int8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxnm_amqp_int8={UINT32_C(0x6026008E),"amqp_int8",sxnm_amqp_int8_fields,SX_COUNT(sxnm_amqp_int8_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_uint16_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxnm_amqp_uint16={UINT32_C(0x6026008F),"amqp_uint16",sxnm_amqp_uint16_fields,SX_COUNT(sxnm_amqp_uint16_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_int16_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxnm_amqp_int16={UINT32_C(0x60260090),"amqp_int16",sxnm_amqp_int16_fields,SX_COUNT(sxnm_amqp_int16_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_uint32_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxnm_amqp_uint32={UINT32_C(0x60260091),"amqp_uint32",sxnm_amqp_uint32_fields,SX_COUNT(sxnm_amqp_uint32_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_int32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxnm_amqp_int32={UINT32_C(0x60260092),"amqp_int32",sxnm_amqp_int32_fields,SX_COUNT(sxnm_amqp_int32_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_uint64_fields[]={
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
static const sx_layout sxnm_amqp_uint64={UINT32_C(0x60260093),"amqp_uint64",sxnm_amqp_uint64_fields,SX_COUNT(sxnm_amqp_uint64_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_int64_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxnm_amqp_int64={UINT32_C(0x60260094),"amqp_int64",sxnm_amqp_int64_fields,SX_COUNT(sxnm_amqp_int64_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_boolean_fields[]={
 SX_FIELD("value","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnm_amqp_boolean={UINT32_C(0x60260095),"amqp_boolean",sxnm_amqp_boolean_fields,SX_COUNT(sxnm_amqp_boolean_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_float_bits_fields[]={
 SX_FIELD("ieee754_binary32_bits","uint32",0,4,SX_NONE),
};
static const sx_layout sxnm_amqp_float_bits={UINT32_C(0x60260096),"amqp_float_bits",sxnm_amqp_float_bits_fields,SX_COUNT(sxnm_amqp_float_bits_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_double_bits_fields[]={
 SX_FIELD("ieee754_binary64_bits","uint64",0,8,SX_NONE),
};
static const sx_layout sxnm_amqp_double_bits={UINT32_C(0x60260097),"amqp_double_bits",sxnm_amqp_double_bits_fields,SX_COUNT(sxnm_amqp_double_bits_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_decimal_fields[]={
 SX_FIELD("scale","uint8",0,1,SX_NONE),
 SX_FIELD("mantissa","int32",1,4,SX_NONE),
};
static const sx_layout sxnm_amqp_decimal={UINT32_C(0x60260098),"amqp_decimal",sxnm_amqp_decimal_fields,SX_COUNT(sxnm_amqp_decimal_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_timestamp_fields[]={
 SX_FIELD("unix_seconds","uint64",0,8,SX_TIME),
};
static const sx_layout sxnm_amqp_timestamp={UINT32_C(0x60260099),"amqp_timestamp",sxnm_amqp_timestamp_fields,SX_COUNT(sxnm_amqp_timestamp_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_long_string_fields[]={
 SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnm_amqp_long_string={UINT32_C(0x6026009A),"amqp_long_string",sxnm_amqp_long_string_fields,SX_COUNT(sxnm_amqp_long_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_delivery_mode_fields[]={
 SX_FIELD("delivery_mode","uint8",0,1,SX_ID),
};
static const sx_layout sxnm_amqp_delivery_mode={UINT32_C(0x6026009B),"amqp_delivery_mode",sxnm_amqp_delivery_mode_fields,SX_COUNT(sxnm_amqp_delivery_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_priority_fields[]={
 SX_FIELD("priority","uint8",0,1,SX_NONE),
};
static const sx_layout sxnm_amqp_priority={UINT32_C(0x6026009C),"amqp_priority",sxnm_amqp_priority_fields,SX_COUNT(sxnm_amqp_priority_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_frame_header_fields[]={
 SX_FIELD("fin_rsv_opcode","uint8",0,1,SX_FLAGS),
 SX_FIELD("mask_and_length","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxnm_websocket_frame_header={UINT32_C(0x6026009D),"websocket_frame_header",sxnm_websocket_frame_header_fields,SX_COUNT(sxnm_websocket_frame_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_length16_fields[]={
 SX_FIELD("payload_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnm_websocket_length16={UINT32_C(0x6026009E),"websocket_length16",sxnm_websocket_length16_fields,SX_COUNT(sxnm_websocket_length16_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_length64_fields[]={
 SX_FIELD("payload_length","uint64",0,8,SX_SIZE),
};
static const sx_layout sxnm_websocket_length64={UINT32_C(0x6026009F),"websocket_length64",sxnm_websocket_length64_fields,SX_COUNT(sxnm_websocket_length64_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_mask_fields[]={
 SX_FIELD("masking_key","bytes",0,4,SX_NONE),
};
static const sx_layout sxnm_websocket_mask={UINT32_C(0x602600A0),"websocket_mask",sxnm_websocket_mask_fields,SX_COUNT(sxnm_websocket_mask_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_close_code_fields[]={
 SX_FIELD("status_code","uint16",0,2,SX_ID),
};
static const sx_layout sxnm_websocket_close_code={UINT32_C(0x602600A1),"websocket_close_code",sxnm_websocket_close_code_fields,SX_COUNT(sxnm_websocket_close_code_fields),SX_BE};
static const sx_layout *const sx_networkmeta_layouts[]={
 &sxnm_ethernet_header,
 &sxnm_ipv4_header,
 &sxnm_ipv6_header,
 &sxnm_ipv4_single_byte_option,
 &sxnm_ipv4_option_header,
 &sxnm_udp_header,
 &sxnm_icmp_echo_header,
 &sxnm_bgp_message_header,
 &sxnm_bgp_open,
 &sxnm_bgp_optional_parameter,
 &sxnm_bgp_capability_header,
 &sxnm_ospfv2_header,
 &sxnm_ospfv2_hello,
 &sxnm_ospfv2_neighbor,
 &sxnm_sctp_common_header,
 &sxnm_sctp_data_chunk,
 &sxnm_isakmp_header,
 &sxnm_isakmp_sa_payload,
 &sxnm_isakmp_proposal,
 &sxnm_isakmp_transform,
 &sxnm_isakmp_basic_attribute,
 &sxnm_isakmp_variable_attribute,
 &sxnm_rtp_header,
 &sxnm_rtp_csrc,
 &sxnm_rtp_extension_header,
 &sxnm_rtp_padding_count,
 &sxnm_rtcp_header,
 &sxnm_rtcp_sender_info,
 &sxnm_rtcp_receiver_info,
 &sxnm_rtcp_report_block,
 &sxnm_rtcp_source,
 &sxnm_rtcp_sdes_item,
 &sxnm_rtcp_sdes_end,
 &sxnm_rtcp_bye_reason,
 &sxnm_rtcp_app_header,
 &sxnm_tls_record_header,
 &sxnm_tls_handshake_header,
 &sxnm_tls_hello_prefix,
 &sxnm_tls_session_id_length,
 &sxnm_tls_cipher_suites_length,
 &sxnm_tls_cipher_suite,
 &sxnm_tls_compression_methods_length,
 &sxnm_tls_compression_method,
 &sxnm_tls_extensions_length,
 &sxnm_tls_extension_header,
 &sxnm_tls_change_cipher_spec,
 &sxnm_diameter_header,
 &sxnm_diameter_avp_header,
 &sxnm_diameter_address_family,
 &sxnm_diameter_vendor_id,
 &sxnm_tacacs_header,
 &sxnm_tacacs_authentication_start,
 &sxnm_gtpv1_header,
 &sxnm_pfcp_node_header,
 &sxnm_pfcp_information_element,
 &sxnm_pfcp_node_id_type,
 &sxnm_pfcp_node_ipv4,
 &sxnm_pfcp_node_ipv6,
 &sxnm_pfcp_dns_label,
 &sxnm_pfcp_recovery_time,
 &sxnm_pptp_control_header,
 &sxnm_pptp_start_control_connection,
 &sxnm_rsvp_header,
 &sxnm_rsvp_object_header,
 &sxnm_rsvp_hello_instances,
 &sxnm_pim_header,
 &sxnm_pim_option_header,
 &sxnm_pim_holdtime,
 &sxnm_pim_lan_prune_delay,
 &sxnm_pim_dr_priority,
 &sxnm_pim_generation_id,
 &sxnm_ldp_pdu_header,
 &sxnm_ldp_message_header,
 &sxnm_ldp_tlv_header,
 &sxnm_ldp_common_hello,
 &sxnm_ldp_ipv4_transport,
 &sxnm_ldp_configuration_sequence,
 &sxnm_gre_header,
 &sxnm_gre_checksum,
 &sxnm_gre_key,
 &sxnm_gre_sequence,
 &sxnm_l2tp_control_header,
 &sxnm_l2tp_avp_header,
 &sxnm_l2tp_message_type,
 &sxnm_l2tp_protocol_version,
 &sxnm_l2tp_firmware_revision,
 &sxnm_l2tp_assigned_tunnel,
 &sxnm_l2tp_receive_window,
 &sxnm_l2tp_framing_capabilities,
 &sxnm_l2tp_bearer_capabilities,
 &sxnm_netflow_v5_header,
 &sxnm_netflow_v5_record,
 &sxnm_ntlm_negotiate,
 &sxnm_ntlm_version,
 &sxnm_rtps_header,
 &sxnm_rtps_submessage_le,
 &sxnm_rtps_timestamp_le,
 &sxnm_rtps_heartbeat_le,
 &sxnm_rtps_data_le,
 &sxnm_dcerpc_header_le,
 &sxnm_dcerpc_bind_le,
 &sxnm_dcerpc_context_le,
 &sxnm_dcerpc_transfer_syntax_le,
 &sxnm_dcerpc_request_le,
 &sxnm_dcerpc_response_le,
 &sxnm_rtps_submessage_be,
 &sxnm_rtps_timestamp_be,
 &sxnm_rtps_heartbeat_be,
 &sxnm_rtps_data_be,
 &sxnm_dcerpc_header_be,
 &sxnm_dcerpc_bind_be,
 &sxnm_dcerpc_context_be,
 &sxnm_dcerpc_transfer_syntax_be,
 &sxnm_dcerpc_request_be,
 &sxnm_dcerpc_response_be,
 &sxnm_rtps_destination,
 &sxnm_rtps_cdr_encapsulation,
 &sxnm_mqtt_control_byte,
 &sxnm_mqtt_remaining_length_1,
 &sxnm_mqtt_remaining_length_2,
 &sxnm_mqtt_remaining_length_3,
 &sxnm_mqtt_remaining_length_4,
 &sxnm_mqtt_connect,
 &sxnm_mqtt_string_length,
 &sxnm_mqtt_connack,
 &sxnm_mqtt_packet_id,
 &sxnm_mqtt_requested_qos,
 &sxnm_mqtt_suback_result,
 &sxnm_amqp_protocol_header,
 &sxnm_amqp_frame_header,
 &sxnm_amqp_method_header,
 &sxnm_amqp_content_header,
 &sxnm_amqp_frame_end,
 &sxnm_amqp_publish_prefix,
 &sxnm_amqp_publish_flags,
 &sxnm_amqp_close_code,
 &sxnm_amqp_close_method,
 &sxnm_amqp_short_string,
 &sxnm_amqp_table_length,
 &sxnm_amqp_field_type,
 &sxnm_amqp_uint8,
 &sxnm_amqp_int8,
 &sxnm_amqp_uint16,
 &sxnm_amqp_int16,
 &sxnm_amqp_uint32,
 &sxnm_amqp_int32,
 &sxnm_amqp_uint64,
 &sxnm_amqp_int64,
 &sxnm_amqp_boolean,
 &sxnm_amqp_float_bits,
 &sxnm_amqp_double_bits,
 &sxnm_amqp_decimal,
 &sxnm_amqp_timestamp,
 &sxnm_amqp_long_string,
 &sxnm_amqp_delivery_mode,
 &sxnm_amqp_priority,
 &sxnm_websocket_frame_header,
 &sxnm_websocket_length16,
 &sxnm_websocket_length64,
 &sxnm_websocket_mask,
 &sxnm_websocket_close_code,
};
static const sx_layout *const sxnm_mqtt_remaining_rows[]={&sxnm_mqtt_remaining_length_1,&sxnm_mqtt_remaining_length_2,&sxnm_mqtt_remaining_length_3,&sxnm_mqtt_remaining_length_4};
/* Native readers establish protocol validity. This walker independently bounds
 * every physical subrecord before classification; payload bytes remain raw. */
typedef struct sxnm_view {sx_context *c;uint8_t *p;size_t n;unsigned work;}sxnm_view;
static bool sx_networkmeta_supports(xx_file_type_t t)
{
 switch(t){case XX_FILE_TYPE_RTP_RTCP:case XX_FILE_TYPE_BGP_MESSAGES:case XX_FILE_TYPE_OSPF_PACKET:case XX_FILE_TYPE_SCTP_PACKET:case XX_FILE_TYPE_ISAKMP_MESSAGE:case XX_FILE_TYPE_TLS_RECORDS:case XX_FILE_TYPE_ETHERNET_FRAME:case XX_FILE_TYPE_IP_PACKET:case XX_FILE_TYPE_ICMP_MESSAGE:case XX_FILE_TYPE_DIAMETER_MESSAGE:case XX_FILE_TYPE_TACACS_PACKET:case XX_FILE_TYPE_GTP_MESSAGE:case XX_FILE_TYPE_PFCP_MESSAGE:case XX_FILE_TYPE_PPTP_MESSAGE:case XX_FILE_TYPE_RSVP_MESSAGE:case XX_FILE_TYPE_DDS_RTPS:case XX_FILE_TYPE_PIM_MESSAGE:case XX_FILE_TYPE_LDP_MESSAGE:case XX_FILE_TYPE_GRE_PACKET:case XX_FILE_TYPE_L2TP_PACKET:case XX_FILE_TYPE_NETFLOW_DATAGRAM:case XX_FILE_TYPE_NTLM_MESSAGE:case XX_FILE_TYPE_DCERPC_PDU:case XX_FILE_TYPE_MQTT_PACKETS:case XX_FILE_TYPE_AMQP_FRAMES:case XX_FILE_TYPE_WEBSOCKET_FRAMES:return true;default:return false;}
}
static bool sxnm_need(sxnm_view *v,size_t at,uint64_t n,size_t end){return !xx_pd_is_stopped(v->c->pd)&&end<=v->n&&at<=end&&n<=end-at;}
static uint16_t sxnm_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,true);}
static uint32_t sxnm_u24(const uint8_t *p){return ((uint32_t)p[0]<<16)|((uint32_t)p[1]<<8)|p[2];}
static uint32_t sxnm_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,true);}
static uint64_t sxnm_u64(const uint8_t *p){return xx_data_get_u64(p,8,0,true);}
static bool sxnm_row(sxnm_view *v,const sx_layout *l,size_t at,size_t end)
{
 const xx_data_struct_field_desc *f=l->fields+l->field_count-1;size_t n=(size_t)(f->rel_offset+f->size);
 if(++v->work>2000000||!sxnm_need(v,at,n,end))return false;
 /* Leave enough room for one raw gap per retained row. Native AMQP tables
  * can contain many more fields than the common descriptor limit. Continue
  * the bounded walk, retaining omitted metadata as source RAW_DATA. */
 return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)n);
}
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static int sxnm_order(const void *aa,const void *bb){const xx_data_struct *a=aa,*b=bb;return a->offset<b->offset?-1:a->offset>b->offset?1:0;}
static bool sxnm_finish(sx_context *c)
{
 size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxnm_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxnm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sxnm_ip(sxnm_view *v,size_t at,size_t end)
{
 if(!sxnm_need(v,at,1,end))return false;unsigned ver=v->p[at]>>4;size_t udp;
 if(ver==4){if(!SN_ROW(ipv4_header,at,end))return false;size_t h=(v->p[at]&15)*4;if(h<20||!sxnm_need(v,at,h+8,end)||sxnm_u16(v->p+at+2)!=end-at||v->p[at+9]!=17)return false;udp=at+h;size_t o=at+20;
  while(o<udp){uint8_t type=v->p[o];if(type<2){if(!SN_ROW(ipv4_single_byte_option,o,udp))return false;o++;if(!type)break;}else{if(!SN_ROW(ipv4_option_header,o,udp))return false;unsigned n=v->p[o+1];if(n<2||!sxnm_need(v,o,n,udp))return false;o+=n;}}
 }else if(ver==6){if(!SN_ROW(ipv6_header,at,end)||sxnm_u16(v->p+at+4)!=end-at-40||v->p[at+6]!=17)return false;udp=at+40;}else return false;
 return SN_ROW(udp_header,udp,end)&&sxnm_u16(v->p+udp+4)==end-udp;
}
static bool sxnm_bgp(sxnm_view *v)
{
 size_t at=0;
 for(unsigned msg=0;at<v->n;msg++){
  if(msg>=128||!SN_ROW(bgp_message_header,at,v->n))return false;size_t n=sxnm_u16(v->p+at+16);if(n<19||!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;
  if(v->p[at+18]==1){if(!SN_ROW(bgp_open,at+19,end))return false;size_t p=at+29;if(v->p[at+28]!=end-p)return false;
   while(p<end){if(!SN_ROW(bgp_optional_parameter,p,end))return false;size_t pe=p+2+v->p[p+1];if(pe>end)return false;unsigned type=v->p[p];p+=2;if(type==2)while(p<pe){if(!SN_ROW(bgp_capability_header,p,pe))return false;size_t ncap=v->p[p+1];p+=2;if(!sxnm_need(v,p,ncap,pe))return false;p+=ncap;}p=pe;}
  }at=end;
 }return at==v->n;
}
static bool sxnm_ospf(sxnm_view *v){if(!SN_ROW(ospfv2_header,0,v->n)||!SN_ROW(ospfv2_hello,24,v->n)||sxnm_u16(v->p+2)!=v->n)return false;for(size_t at=44;at<v->n;at+=4)if(!SN_ROW(ospfv2_neighbor,at,v->n))return false;return true;}
static bool sxnm_sctp(sxnm_view *v)
{
 if(!SN_ROW(sctp_common_header,0,v->n))return false;size_t at=12;
 while(at<v->n){if(!SN_ROW(sctp_data_chunk,at,v->n)||v->p[at])return false;size_t n=sxnm_u16(v->p+at+2);if(n<16||!sxnm_need(v,at,n+(4-n%4)%4,v->n))return false;at+=n+(4-n%4)%4;}return true;
}
static bool sxnm_isakmp(sxnm_view *v)
{
 if(!SN_ROW(isakmp_header,0,v->n)||!SN_ROW(isakmp_sa_payload,28,v->n)||sxnm_u32(v->p+24)!=v->n||sxnm_u16(v->p+30)!=v->n-28)return false;size_t p=40;
 while(p<v->n){if(!SN_ROW(isakmp_proposal,p,v->n))return false;size_t n=sxnm_u16(v->p+p+2);if(n<8||!sxnm_need(v,p,n,v->n))return false;size_t end=p+n,t=p+8+v->p[p+6];unsigned count=v->p[p+7];if(t>end)return false;
  for(unsigned j=0;j<count;j++){if(!SN_ROW(isakmp_transform,t,end))return false;size_t z=sxnm_u16(v->p+t+2);if(z<8||!sxnm_need(v,t,z,end))return false;size_t te=t+z,a=t+8;
   while(a<te){if(!sxnm_need(v,a,4,te))return false;bool basic=(v->p[a]&128)!=0;if(!sxnm_row(v,basic?&sxnm_isakmp_basic_attribute:&sxnm_isakmp_variable_attribute,a,te))return false;size_t extra=basic?0:sxnm_u16(v->p+a+2);a+=4;if(!sxnm_need(v,a,extra,te))return false;a+=extra;}t=te;
  }if(t!=end)return false;p=end;
 }return true;
}
static bool sxnm_rtcp(sxnm_view *v)
{
 size_t at=0;
 while(at<v->n){if(!SN_ROW(rtcp_header,at,v->n))return false;unsigned flags=v->p[at],type=v->p[at+1],count=flags&31;size_t n=((size_t)sxnm_u16(v->p+at+2)+1)*4;if(n<4||!sxnm_need(v,at,n,v->n))return false;size_t end=at+n,body=end,p=at+4;
  if(flags&32){unsigned pad=v->p[end-1];if(!pad||pad>n-4||!SN_ROW(rtp_padding_count,end-1,end))return false;body-=pad;}
  if(type==200||type==201){size_t fixed=type==200?24:4;if(!sxnm_row(v,type==200?&sxnm_rtcp_sender_info:&sxnm_rtcp_receiver_info,p,body))return false;p+=fixed;for(unsigned i=0;i<count;i++,p+=24)if(!SN_ROW(rtcp_report_block,p,body))return false;if(p!=body)return false;}
  else if(type==202){for(unsigned i=0;i<count;i++){if(!SN_ROW(rtcp_source,p,body))return false;p+=4;bool ended=false;while(p<body){if(!v->p[p]){if(!SN_ROW(rtcp_sdes_end,p,body))return false;p++;size_t pad=(4-(p-at)%4)%4;if(!sxnm_need(v,p,pad,body))return false;p+=pad;ended=true;break;}if(!SN_ROW(rtcp_sdes_item,p,body))return false;size_t bytes=v->p[p+1];p+=2;if(!sxnm_need(v,p,bytes,body))return false;p+=bytes;}if(!ended)return false;}if(p!=body)return false;}
  else if(type==203){for(unsigned i=0;i<count;i++,p+=4)if(!SN_ROW(rtcp_source,p,body))return false;if(p<body){if(!SN_ROW(rtcp_bye_reason,p,body)||!sxnm_need(v,p+1,v->p[p],body))return false;}}
  else if(type==204){if(!SN_ROW(rtcp_app_header,p,body))return false;}else return false;at=end;
 }return true;
}
static bool sxnm_rtp(sxnm_view *v)
{
 if(!sxnm_need(v,0,2,v->n))return false;if(v->p[1]>=192&&v->p[1]<=223)return sxnm_rtcp(v);
 if(!SN_ROW(rtp_header,0,v->n))return false;unsigned flags=v->p[0],count=flags&15;size_t at=12,end=v->n;
 for(unsigned i=0;i<count;i++,at+=4)if(!SN_ROW(rtp_csrc,at,end))return false;
 if(flags&16){if(!SN_ROW(rtp_extension_header,at,end))return false;size_t n=(size_t)sxnm_u16(v->p+at+2)*4;at+=4;if(!sxnm_need(v,at,n,end))return false;at+=n;}
 if(flags&32){unsigned n=v->p[end-1];if(!n||n>end-at||!SN_ROW(rtp_padding_count,end-1,end))return false;end-=n;}return at<end;
}
static bool sxnm_tls_hello(sxnm_view *v,size_t at,size_t end,unsigned type)
{
 if(!SN_ROW(tls_hello_prefix,at,end))return false;at+=34;if(!SN_ROW(tls_session_id_length,at,end))return false;size_t n=v->p[at++];if(!sxnm_need(v,at,n,end))return false;at+=n;
 if(type==1){if(!SN_ROW(tls_cipher_suites_length,at,end))return false;n=sxnm_u16(v->p+at);at+=2;if(n%2||!sxnm_need(v,at,n,end))return false;size_t ce=at+n;for(;at<ce;at+=2)if(!SN_ROW(tls_cipher_suite,at,ce))return false;
  if(!SN_ROW(tls_compression_methods_length,at,end))return false;n=v->p[at++];if(!sxnm_need(v,at,n,end))return false;size_t ce2=at+n;for(;at<ce2;at++)if(!SN_ROW(tls_compression_method,at,ce2))return false;
 }else if(type==2){if(!SN_ROW(tls_cipher_suite,at,end)||!SN_ROW(tls_compression_method,at+2,end))return false;at+=3;}else return false;
 if(!SN_ROW(tls_extensions_length,at,end))return false;n=sxnm_u16(v->p+at);at+=2;if(n!=end-at)return false;
 while(at<end){if(!SN_ROW(tls_extension_header,at,end))return false;n=sxnm_u16(v->p+at+2);at+=4;if(!sxnm_need(v,at,n,end))return false;at+=n;}return true;
}
static bool sxnm_tls(sxnm_view *v)
{
 size_t at=0;
 while(at<v->n){if(!SN_ROW(tls_record_header,at,v->n))return false;unsigned type=v->p[at];size_t n=sxnm_u16(v->p+at+3);at+=5;if(!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;
  if(type==22){size_t p=at;while(p<end){if(!SN_ROW(tls_handshake_header,p,end))return false;unsigned ht=v->p[p];size_t hn=sxnm_u24(v->p+p+1);p+=4;if(!sxnm_need(v,p,hn,end)||!sxnm_tls_hello(v,p,p+hn,ht))return false;p+=hn;}}
  else if(type==20){if(n!=1||!SN_ROW(tls_change_cipher_spec,at,end))return false;}else if(type!=23)return false;at=end;
 }return true;
}
static bool sxnm_diameter(sxnm_view *v)
{
 if(!SN_ROW(diameter_header,0,v->n)||sxnm_u24(v->p+1)!=v->n)return false;size_t at=20;
 while(at<v->n){if(!SN_ROW(diameter_avp_header,at,v->n))return false;uint32_t code=sxnm_u32(v->p+at);size_t n=sxnm_u24(v->p+at+5);if(n<8||!sxnm_need(v,at,n+(4-n%4)%4,v->n))return false;
  if(code==257&&!SN_ROW(diameter_address_family,at+8,at+n))return false;if(code==266&&!SN_ROW(diameter_vendor_id,at+8,at+n))return false;at+=n+(4-n%4)%4;
 }return true;
}
static bool sxnm_tacacs(sxnm_view *v){if(!SN_ROW(tacacs_header,0,v->n)||!SN_ROW(tacacs_authentication_start,12,v->n)||sxnm_u32(v->p+8)!=v->n-12)return false;return (size_t)v->p[16]+v->p[17]+v->p[18]+v->p[19]==v->n-20;}
static bool sxnm_pfcp(sxnm_view *v)
{
 if(!SN_ROW(pfcp_node_header,0,v->n)||sxnm_u16(v->p+2)!=v->n-4)return false;size_t at=8;
 while(at<v->n){if(!SN_ROW(pfcp_information_element,at,v->n))return false;unsigned type=sxnm_u16(v->p+at),n=sxnm_u16(v->p+at+2);at+=4;if(!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;
  if(type==60){if(!SN_ROW(pfcp_node_id_type,at,end))return false;unsigned kind=v->p[at++];if(kind<2){if(!sxnm_row(v,kind?&sxnm_pfcp_node_ipv6:&sxnm_pfcp_node_ipv4,at,end))return false;}else if(kind==2){while(at<end){if(!SN_ROW(pfcp_dns_label,at,end))return false;unsigned len=v->p[at++];if(!len||!sxnm_need(v,at,len,end))return false;at+=len;}}else return false;}
  else if(type==96&&!SN_ROW(pfcp_recovery_time,at,end))return false;at=end;
 }return true;
}
static bool sxnm_pim(sxnm_view *v)
{
 if(!SN_ROW(pim_header,0,v->n))return false;size_t at=4;while(at<v->n){if(!SN_ROW(pim_option_header,at,v->n))return false;unsigned t=sxnm_u16(v->p+at),n=sxnm_u16(v->p+at+2);at+=4;if(!sxnm_need(v,at,n,v->n))return false;const sx_layout *l=t==1?&sxnm_pim_holdtime:t==2?&sxnm_pim_lan_prune_delay:t==19?&sxnm_pim_dr_priority:t==20?&sxnm_pim_generation_id:NULL;if(l&&!sxnm_row(v,l,at,at+n))return false;at+=n;}return true;
}
static bool sxnm_ldp(sxnm_view *v)
{
 if(!SN_ROW(ldp_pdu_header,0,v->n)||sxnm_u16(v->p+2)!=v->n-4)return false;size_t at=10;
 while(at<v->n){if(!SN_ROW(ldp_message_header,at,v->n))return false;size_t n=(size_t)sxnm_u16(v->p+at+2)+4;if(n<8||!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;at+=8;
  while(at<end){if(!SN_ROW(ldp_tlv_header,at,end))return false;unsigned type=sxnm_u16(v->p+at)&0x3fff,nv=sxnm_u16(v->p+at+2);at+=4;if(!sxnm_need(v,at,nv,end))return false;const sx_layout *l=type==0x400?&sxnm_ldp_common_hello:type==0x401?&sxnm_ldp_ipv4_transport:type==0x402?&sxnm_ldp_configuration_sequence:NULL;if(l&&!sxnm_row(v,l,at,at+nv))return false;at+=nv;}
 }return true;
}
static bool sxnm_gre(sxnm_view *v)
{
 if(!SN_ROW(gre_header,0,v->n))return false;unsigned f=sxnm_u16(v->p);size_t at=4;if(f&0x8000){if(!SN_ROW(gre_checksum,at,v->n))return false;at+=4;}if(f&0x2000){if(!SN_ROW(gre_key,at,v->n))return false;at+=4;}if(f&0x1000){if(!SN_ROW(gre_sequence,at,v->n))return false;at+=4;}return sxnm_ip(v,at,v->n);
}
static bool sxnm_l2tp(sxnm_view *v)
{
 if(!SN_ROW(l2tp_control_header,0,v->n)||sxnm_u16(v->p+2)!=v->n)return false;size_t at=12;
 while(at<v->n){if(!SN_ROW(l2tp_avp_header,at,v->n))return false;unsigned n=sxnm_u16(v->p+at)&1023,type=sxnm_u16(v->p+at+4);if(n<6||!sxnm_need(v,at,n,v->n))return false;const sx_layout *l=NULL;
  switch(type){case 0:l=&sxnm_l2tp_message_type;break;case 2:l=&sxnm_l2tp_protocol_version;break;case 3:l=&sxnm_l2tp_framing_capabilities;break;case 4:l=&sxnm_l2tp_bearer_capabilities;break;case 6:l=&sxnm_l2tp_firmware_revision;break;case 9:l=&sxnm_l2tp_assigned_tunnel;break;case 10:l=&sxnm_l2tp_receive_window;break;default:break;}if(l&&!sxnm_row(v,l,at+6,at+n))return false;at+=n;
 }return true;
}
static bool sxnm_netflow(sxnm_view *v){if(!SN_ROW(netflow_v5_header,0,v->n))return false;unsigned count=sxnm_u16(v->p+2);if((uint64_t)count*48!=v->n-24)return false;for(unsigned i=0;i<count;i++)if(!SN_ROW(netflow_v5_record,24+(size_t)i*48,v->n))return false;return true;}
static bool sxnm_ntlm(sxnm_view *v)
{
 if(!SN_ROW(ntlm_negotiate,0,v->n))return false;uint32_t flags=xx_data_get_u32(v->p+12,4,0,false);if(flags&0x02000000&&!SN_ROW(ntlm_version,32,v->n))return false;
 for(unsigned i=0;i<2;i++){size_t at=16+i*8;uint16_t n=xx_data_get_u16(v->p+at,2,0,false);uint32_t off=xx_data_get_u32(v->p+at+4,4,0,false);if(n&&!sxnm_need(v,off,n,v->n))return false;}return true;
}
static bool sxnm_rtps(sxnm_view *v)
{
 if(!SN_ROW(rtps_header,0,v->n))return false;size_t at=20;
 while(at<v->n){if(!sxnm_need(v,at,4,v->n))return false;unsigned type=v->p[at],f=v->p[at+1];bool be=!(f&1);size_t n=xx_data_get_u16(v->p+at+2,2,0,be);if(!sxnm_row(v,be?&sxnm_rtps_submessage_be:&sxnm_rtps_submessage_le,at,v->n))return false;at+=4;if(!n&&!(type==9&&(f&2)))n=v->n-at;if(!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;const sx_layout *l=NULL;
  if(type==9&&!(f&2))l=be?&sxnm_rtps_timestamp_be:&sxnm_rtps_timestamp_le;else if(type==14)l=&sxnm_rtps_destination;else if(type==7)l=be?&sxnm_rtps_heartbeat_be:&sxnm_rtps_heartbeat_le;else if(type==21){l=be?&sxnm_rtps_data_be:&sxnm_rtps_data_le;if(!SN_ROW(rtps_cdr_encapsulation,at+20,end))return false;}
  if(l&&!sxnm_row(v,l,at,end))return false;at=end;
 }return true;
}
static bool sxnm_rpc(sxnm_view *v)
{
 if(!sxnm_need(v,0,16,v->n))return false;bool be=v->p[4]!=16;unsigned type=v->p[2];if(!sxnm_row(v,be?&sxnm_dcerpc_header_be:&sxnm_dcerpc_header_le,0,v->n)||xx_data_get_u16(v->p+8,2,0,be)!=v->n)return false;
 if(type==0||type==2)return sxnm_row(v,type==0?(be?&sxnm_dcerpc_request_be:&sxnm_dcerpc_request_le):(be?&sxnm_dcerpc_response_be:&sxnm_dcerpc_response_le),16,v->n);
 if(type!=11||!sxnm_row(v,be?&sxnm_dcerpc_bind_be:&sxnm_dcerpc_bind_le,16,v->n))return false;unsigned count=v->p[24];size_t at=28;
 for(unsigned i=0;i<count;i++){if(!sxnm_row(v,be?&sxnm_dcerpc_context_be:&sxnm_dcerpc_context_le,at,v->n))return false;unsigned n=v->p[at+2];at+=24;for(unsigned j=0;j<n;j++,at+=20)if(!sxnm_row(v,be?&sxnm_dcerpc_transfer_syntax_be:&sxnm_dcerpc_transfer_syntax_le,at,v->n))return false;}return at==v->n;
}
static bool sxnm_mq_string(sxnm_view *v,size_t *at,size_t end){if(!SN_ROW(mqtt_string_length,*at,end))return false;size_t n=sxnm_u16(v->p+*at);*at+=2;if(!sxnm_need(v,*at,n,end))return false;*at+=n;return true;}
static bool sxnm_mqtt(sxnm_view *v)
{
 size_t at=0;
 while(at<v->n){if(!SN_ROW(mqtt_control_byte,at,v->n))return false;unsigned flags=v->p[at++],type=flags>>4;size_t start=at,bytes=0;unsigned w=0;
  for(;w<4;w++){if(!sxnm_need(v,at,1,v->n))return false;unsigned b=v->p[at++];bytes|=(size_t)(b&127)<<(7*w);if(!(b&128))break;}if(w==4||!sxnm_row(v,sxnm_mqtt_remaining_rows[w],start,v->n)||!sxnm_need(v,at,bytes,v->n))return false;size_t end=at+bytes;
  if(type==1){if(!SN_ROW(mqtt_connect,at,end))return false;unsigned f=v->p[at+7];at+=10;if(!sxnm_mq_string(v,&at,end))return false;if(f&4){if(!sxnm_mq_string(v,&at,end)||!sxnm_mq_string(v,&at,end))return false;}if(f&128&&!sxnm_mq_string(v,&at,end))return false;if(f&64&&!sxnm_mq_string(v,&at,end))return false;}
  else if(type==2){if(!SN_ROW(mqtt_connack,at,end))return false;at+=2;}
  else if(type==3){if(!sxnm_mq_string(v,&at,end))return false;if((flags>>1)&3){if(!SN_ROW(mqtt_packet_id,at,end))return false;at+=2;}at=end;}
  else if(type==8||type==9||type==10){if(!SN_ROW(mqtt_packet_id,at,end))return false;at+=2;while(at<end){if(type==9){if(!SN_ROW(mqtt_suback_result,at,end))return false;at++;}else{if(!sxnm_mq_string(v,&at,end))return false;if(type==8){if(!SN_ROW(mqtt_requested_qos,at,end))return false;at++;}}}}
  else if((type>=4&&type<=7)||type==11){if(!SN_ROW(mqtt_packet_id,at,end))return false;at+=2;}
  else if(type<12||type>14)return false;
  if(at!=end)return false;
 }return true;
}
static bool sxnm_aq_short(sxnm_view *v,size_t *at,size_t end){if(!SN_ROW(amqp_short_string,*at,end))return false;unsigned n=v->p[(*at)++];if(!sxnm_need(v,*at,n,end))return false;*at+=n;return true;}
static bool sxnm_aq_table(sxnm_view *v,size_t *at,size_t end,unsigned depth,bool array);
static bool sxnm_aq_value(sxnm_view *v,size_t *at,size_t end,unsigned depth)
{
 if(!SN_ROW(amqp_field_type,*at,end))return false;unsigned type=v->p[(*at)++];const sx_layout *l=NULL;
 switch(type){case 't':l=&sxnm_amqp_boolean;break;case 'b':l=&sxnm_amqp_int8;break;case 'B':l=&sxnm_amqp_uint8;break;case 'U':l=&sxnm_amqp_int16;break;case 'u':l=&sxnm_amqp_uint16;break;case 'I':l=&sxnm_amqp_int32;break;case 'i':l=&sxnm_amqp_uint32;break;case 'L':l=&sxnm_amqp_int64;break;case 'l':l=&sxnm_amqp_uint64;break;case 'f':l=&sxnm_amqp_float_bits;break;case 'd':l=&sxnm_amqp_double_bits;break;case 'D':l=&sxnm_amqp_decimal;break;case 'T':l=&sxnm_amqp_timestamp;break;case 'V':return true;case 's':return sxnm_aq_short(v,at,end);case 'A':case 'F':return sxnm_aq_table(v,at,end,depth+1,type=='A');case 'S':case 'x':{if(!SN_ROW(amqp_long_string,*at,end))return false;size_t n=sxnm_u32(v->p+*at);*at+=4;if(!sxnm_need(v,*at,n,end))return false;*at+=n;return true;}default:return false;}
 if(!sxnm_row(v,l,*at,end))return false;const xx_data_struct_field_desc *f=l->fields+l->field_count-1;*at+=(size_t)(f->rel_offset+f->size);return true;
}
static bool sxnm_aq_table(sxnm_view *v,size_t *at,size_t end,unsigned depth,bool array)
{
 if(depth>32||!SN_ROW(amqp_table_length,*at,end))return false;size_t n=sxnm_u32(v->p+*at);*at+=4;if(!sxnm_need(v,*at,n,end))return false;size_t stop=*at+n;
 while(*at<stop){if(!array&&!sxnm_aq_short(v,at,stop))return false;if(!sxnm_aq_value(v,at,stop,depth))return false;}return true;
}
static bool sxnm_amqp(sxnm_view *v)
{
 if(!SN_ROW(amqp_protocol_header,0,v->n))return false;size_t at=8;
 while(at<v->n){if(!SN_ROW(amqp_frame_header,at,v->n))return false;unsigned type=v->p[at];size_t n=sxnm_u32(v->p+at+3);at+=7;if(!sxnm_need(v,at,(uint64_t)n+1,v->n))return false;size_t end=at+n;if(!SN_ROW(amqp_frame_end,end,v->n))return false;
  if(type==1){if(!SN_ROW(amqp_method_header,at,end))return false;unsigned cl=sxnm_u16(v->p+at),me=sxnm_u16(v->p+at+2);at+=4;
   if(cl==20&&me==10){if(!sxnm_aq_short(v,&at,end))return false;}
   else if(cl==60&&me==40){if(!SN_ROW(amqp_publish_prefix,at,end))return false;at+=2;if(!sxnm_aq_short(v,&at,end)||!sxnm_aq_short(v,&at,end)||!SN_ROW(amqp_publish_flags,at,end))return false;at++;}
   else if(cl==10&&me==50){if(!SN_ROW(amqp_close_code,at,end))return false;at+=2;if(!sxnm_aq_short(v,&at,end)||!SN_ROW(amqp_close_method,at,end))return false;at+=4;}else return false;
   if(at!=end)return false;
  }else if(type==2){if(!SN_ROW(amqp_content_header,at,end))return false;unsigned flags=sxnm_u16(v->p+at+12);at+=14;
   for(int bit=15;bit>=2;bit--){if(!(flags&(1U<<bit)))continue;if(bit==13){if(!sxnm_aq_table(v,&at,end,0,false))return false;}else if(bit==12||bit==11){if(!sxnm_row(v,bit==12?&sxnm_amqp_delivery_mode:&sxnm_amqp_priority,at,end))return false;at++;}else if(bit==6){if(!SN_ROW(amqp_timestamp,at,end))return false;at+=8;}else if(!sxnm_aq_short(v,&at,end))return false;}if(at!=end)return false;
  }else if(type!=3&&type!=8)return false;at=end+1;
 }return true;
}
static bool sxnm_websocket(sxnm_view *v)
{
 size_t at=0;
 while(at<v->n){if(!SN_ROW(websocket_frame_header,at,v->n))return false;unsigned op=v->p[at]&15,f=v->p[at+1];uint64_t n=f&127;at+=2;
  if(n==126){if(!SN_ROW(websocket_length16,at,v->n))return false;n=sxnm_u16(v->p+at);at+=2;}else if(n==127){if(!SN_ROW(websocket_length64,at,v->n))return false;n=sxnm_u64(v->p+at);at+=8;}
  if(f&128){if(!SN_ROW(websocket_mask,at,v->n))return false;at+=4;}if(!sxnm_need(v,at,n,v->n))return false;if(!(f&128)&&op==8&&n>=2&&!SN_ROW(websocket_close_code,at,at+(size_t)n))return false;at+=(size_t)n;
 }return true;
}
static bool sx_networkmeta_build(sx_context *c)
{
 if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>64*1024*1024||xx_pd_is_stopped(c->pd))return false;sxnm_view view={c,NULL,(size_t)c->size,0},*v=&view;v->p=xx_mem_alloc(v->n);if(!v->p)return false;bool ok=false;if(!sx_read(c,0,v->p,v->n))goto done;
 switch(c->f->file_type){
 case XX_FILE_TYPE_IP_PACKET:ok=sxnm_ip(v,0,v->n);break;case XX_FILE_TYPE_ETHERNET_FRAME:ok=SN_ROW(ethernet_header,0,v->n)&&sxnm_ip(v,14,v->n);break;case XX_FILE_TYPE_GTP_MESSAGE:ok=SN_ROW(gtpv1_header,0,v->n)&&sxnm_ip(v,8,v->n);break;case XX_FILE_TYPE_ICMP_MESSAGE:ok=SN_ROW(icmp_echo_header,0,v->n);break;
 case XX_FILE_TYPE_BGP_MESSAGES:ok=sxnm_bgp(v);break;case XX_FILE_TYPE_OSPF_PACKET:ok=sxnm_ospf(v);break;case XX_FILE_TYPE_SCTP_PACKET:ok=sxnm_sctp(v);break;case XX_FILE_TYPE_ISAKMP_MESSAGE:ok=sxnm_isakmp(v);break;case XX_FILE_TYPE_RTP_RTCP:ok=sxnm_rtp(v);break;case XX_FILE_TYPE_TLS_RECORDS:ok=sxnm_tls(v);break;case XX_FILE_TYPE_DIAMETER_MESSAGE:ok=sxnm_diameter(v);break;case XX_FILE_TYPE_TACACS_PACKET:ok=sxnm_tacacs(v);break;case XX_FILE_TYPE_PFCP_MESSAGE:ok=sxnm_pfcp(v);break;
 case XX_FILE_TYPE_PPTP_MESSAGE:ok=SN_ROW(pptp_control_header,0,v->n)&&SN_ROW(pptp_start_control_connection,12,v->n);break;case XX_FILE_TYPE_RSVP_MESSAGE:ok=SN_ROW(rsvp_header,0,v->n)&&SN_ROW(rsvp_object_header,8,v->n)&&SN_ROW(rsvp_hello_instances,12,v->n);break;
 case XX_FILE_TYPE_PIM_MESSAGE:ok=sxnm_pim(v);break;case XX_FILE_TYPE_LDP_MESSAGE:ok=sxnm_ldp(v);break;case XX_FILE_TYPE_GRE_PACKET:ok=sxnm_gre(v);break;case XX_FILE_TYPE_L2TP_PACKET:ok=sxnm_l2tp(v);break;case XX_FILE_TYPE_NETFLOW_DATAGRAM:ok=sxnm_netflow(v);break;case XX_FILE_TYPE_NTLM_MESSAGE:ok=sxnm_ntlm(v);break;case XX_FILE_TYPE_DDS_RTPS:ok=sxnm_rtps(v);break;case XX_FILE_TYPE_DCERPC_PDU:ok=sxnm_rpc(v);break;case XX_FILE_TYPE_MQTT_PACKETS:ok=sxnm_mqtt(v);break;case XX_FILE_TYPE_AMQP_FRAMES:ok=sxnm_amqp(v);break;case XX_FILE_TYPE_WEBSOCKET_FRAMES:ok=sxnm_websocket(v);break;default:break;
 }
done:xx_mem_free(v->p);return ok&&sxnm_finish(c);
}
#undef SN_ROW
static bool sx_networkmeta_comment(xx_data_struct_record *r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60260001)||id>UINT32_C(0x6026ffff))return true;
 const wchar_t *text=NULL;xx_var_type_t type=xx_var_get_type(&r->value);bool number=type>=XX_VAR_TYPE_INT8&&type<=XX_VAR_TYPE_UINT64;uint64_t value=number?xx_var_get_u64(&r->value):0;
 if(id==sxnm_ipv4_header.id&&!xx_rt_wcscmp(r->name,L"version_and_ihl"))text=L"High nibble: IP version; low nibble: header length in 32-bit words";
 if(id==sxnm_ipv4_header.id&&!xx_rt_wcscmp(r->name,L"dscp_and_ecn"))text=L"High 6 bits: DSCP; low 2 bits: ECN";
 if(id==sxnm_ipv4_header.id&&!xx_rt_wcscmp(r->name,L"flags_and_fragment_offset"))text=L"Flags in high 3 bits; low 13 bits: fragment offset in 8-byte units";
 if(id==sxnm_ipv4_header.id&&!xx_rt_wcscmp(r->name,L"ttl"))text=L"Time to live, decremented at each forwarding hop";
 if(id==sxnm_ipv6_header.id&&!xx_rt_wcscmp(r->name,L"version_traffic_class_flow_label"))text=L"Version:4, traffic class:8, flow label:20";
 if(id==sxnm_ipv6_header.id&&!xx_rt_wcscmp(r->name,L"payload_length"))text=L"Bytes after the 40-byte IPv6 header";
 if(id==sxnm_bgp_open.id&&!xx_rt_wcscmp(r->name,L"hold_time"))text=L"Seconds; zero disables the hold timer";
 if(id==sxnm_ospfv2_hello.id&&!xx_rt_wcscmp(r->name,L"hello_interval"))text=L"Seconds between Hello packets";
 if(id==sxnm_ospfv2_hello.id&&!xx_rt_wcscmp(r->name,L"router_dead_interval"))text=L"Seconds before declaring a silent router down";
 if(id==sxnm_sctp_common_header.id&&!xx_rt_wcscmp(r->name,L"checksum_crc32c"))text=L"CRC32C; wire checksum bytes are little-endian, independently of the other network-order fields";
 if(id==sxnm_sctp_data_chunk.id&&!xx_rt_wcscmp(r->name,L"chunk_length"))text=L"Chunk bytes including its header, excluding alignment padding";
 if(id==sxnm_sctp_data_chunk.id&&!xx_rt_wcscmp(r->name,L"chunk_flags"))text=L"Bits: I=8, U=4, B=2, E=1; native reader accepts U/B/E";
 if(id==sxnm_isakmp_header.id&&!xx_rt_wcscmp(r->name,L"version"))text=L"High nibble: major; low nibble: minor version";
 if(id==sxnm_isakmp_basic_attribute.id&&!xx_rt_wcscmp(r->name,L"format_and_type"))text=L"High bit set: basic 16-bit attribute value; low 15 bits: attribute type";
 if(id==sxnm_isakmp_variable_attribute.id&&!xx_rt_wcscmp(r->name,L"format_and_type"))text=L"High bit clear: variable-length attribute; low 15 bits: attribute type";
 if(id==sxnm_rtp_header.id&&!xx_rt_wcscmp(r->name,L"version_padding_extension_csrc_count"))text=L"Version:2, padding:1, extension:1, CSRC count:4";
 if(id==sxnm_rtp_header.id&&!xx_rt_wcscmp(r->name,L"marker_and_payload_type"))text=L"Marker:1, payload type:7; dynamic payload types require session negotiation";
 if(id==sxnm_rtp_header.id&&!xx_rt_wcscmp(r->name,L"timestamp"))text=L"RTP sampling-clock units; clock rate depends on the negotiated payload format";
 if(id==sxnm_rtp_extension_header.id&&!xx_rt_wcscmp(r->name,L"data_length_words"))text=L"Extension data in 32-bit words, excluding the four-byte extension header";
 if(id==sxnm_rtp_padding_count.id&&!xx_rt_wcscmp(r->name,L"padding_bytes"))text=L"Padding bytes including this final count byte";
 if(id==sxnm_rtcp_header.id&&!xx_rt_wcscmp(r->name,L"version_padding_count"))text=L"Version:2, padding:1, report/source count or subtype:5";
 if(id==sxnm_rtcp_header.id&&!xx_rt_wcscmp(r->name,L"length_words_minus_one"))text=L"Packet length in 32-bit words minus one, including header and padding";
 if(id==sxnm_rtcp_sender_info.id&&!xx_rt_wcscmp(r->name,L"ntp_seconds"))text=L"NTP seconds since 1900-01-01, subject to NTP era rollover";
 if(id==sxnm_rtcp_sender_info.id&&!xx_rt_wcscmp(r->name,L"ntp_fraction"))text=L"Fractional second in units of 2^-32 seconds";
 if(id==sxnm_rtcp_sender_info.id&&!xx_rt_wcscmp(r->name,L"rtp_timestamp"))text=L"RTP sampling-clock timestamp corresponding to the NTP time";
 if(id==sxnm_rtcp_report_block.id&&!xx_rt_wcscmp(r->name,L"fraction_lost"))text=L"Fraction of packets lost, in units of 1/256";
 if(id==sxnm_rtcp_report_block.id&&!xx_rt_wcscmp(r->name,L"cumulative_packets_lost"))text=L"Signed 24-bit cumulative packet-loss count; may be negative for duplicates";
 if(id==sxnm_rtcp_report_block.id&&!xx_rt_wcscmp(r->name,L"interarrival_jitter"))text=L"RTP timestamp units";
 if(id==sxnm_rtcp_report_block.id&&!xx_rt_wcscmp(r->name,L"last_sender_report"))text=L"Middle 32 bits of the last sender-report NTP timestamp";
 if(id==sxnm_rtcp_report_block.id&&!xx_rt_wcscmp(r->name,L"delay_since_last_report"))text=L"Units of 1/65536 second since the last sender report";
 if(id==sxnm_diameter_header.id&&!xx_rt_wcscmp(r->name,L"message_length"))text=L"Bytes including the 20-byte Diameter header";
 if(id==sxnm_diameter_avp_header.id&&!xx_rt_wcscmp(r->name,L"avp_length"))text=L"AVP bytes including its header, excluding four-byte alignment padding";
 if(id==sxnm_pfcp_node_header.id&&!xx_rt_wcscmp(r->name,L"message_length"))text=L"Bytes after the first four PFCP header bytes";
 if(id==sxnm_pfcp_recovery_time.id&&!xx_rt_wcscmp(r->name,L"ntp_seconds"))text=L"NTP seconds since 1900-01-01";
 if(id==sxnm_pim_holdtime.id&&!xx_rt_wcscmp(r->name,L"hold_time"))text=L"Seconds; 65535 means indefinite";
 if(id==sxnm_pim_lan_prune_delay.id&&!xx_rt_wcscmp(r->name,L"tracking_and_propagation_delay"))text=L"High bit: explicit tracking support; low 15 bits: propagation delay in milliseconds";
 if(id==sxnm_pim_lan_prune_delay.id&&!xx_rt_wcscmp(r->name,L"override_interval"))text=L"Milliseconds";
 if(id==sxnm_ldp_pdu_header.id&&!xx_rt_wcscmp(r->name,L"pdu_length"))text=L"Bytes after the version and PDU length words";
 if(id==sxnm_ldp_message_header.id&&!xx_rt_wcscmp(r->name,L"message_length"))text=L"Bytes after the message type and length words, including message identifier";
 if(id==sxnm_ldp_common_hello.id&&!xx_rt_wcscmp(r->name,L"hold_time"))text=L"Seconds; zero requests the default hold time";
 if(id==sxnm_ldp_message_header.id&&!xx_rt_wcscmp(r->name,L"unknown_bit_and_type"))text=L"High bit: unknown-message handling flag; low 15 bits: message type";
 if(id==sxnm_ldp_tlv_header.id&&!xx_rt_wcscmp(r->name,L"flags_and_type"))text=L"High bits: U/F flags; low 14 bits: TLV type";
 if(id==sxnm_gre_header.id&&!xx_rt_wcscmp(r->name,L"flags_and_version"))text=L"C=0x8000, K=0x2000, S=0x1000; low 3 bits: version";
 if(id==sxnm_l2tp_avp_header.id&&!xx_rt_wcscmp(r->name,L"flags_and_length"))text=L"M=0x8000, H=0x4000; low 10 bits: AVP length including the six-byte header";
 if(id==sxnm_l2tp_control_header.id&&!xx_rt_wcscmp(r->name,L"flags_and_version"))text=L"T=0x8000, L=0x4000, S=0x0800, O=0x0200, P=0x0100; low 4 bits: version";
 if(id==sxnm_netflow_v5_header.id&&!xx_rt_wcscmp(r->name,L"system_uptime_ms"))text=L"Milliseconds since the export device booted";
 if(id==sxnm_netflow_v5_header.id&&!xx_rt_wcscmp(r->name,L"unix_seconds"))text=L"Seconds since 1970-01-01 UTC";
 if(id==sxnm_netflow_v5_header.id&&!xx_rt_wcscmp(r->name,L"unix_nanoseconds"))text=L"Additional nanoseconds within the export timestamp second";
 if(id==sxnm_netflow_v5_header.id&&!xx_rt_wcscmp(r->name,L"sampling_mode_and_interval"))text=L"High 2 bits: sampling mode; low 14 bits: sampling interval";
 if(id==sxnm_netflow_v5_record.id&&!xx_rt_wcscmp(r->name,L"first_uptime_ms"))text=L"Device uptime in milliseconds at the first packet";
 if(id==sxnm_netflow_v5_record.id&&!xx_rt_wcscmp(r->name,L"last_uptime_ms"))text=L"Device uptime in milliseconds at the last packet";
 if(id==sxnm_netflow_v5_record.id&&!xx_rt_wcscmp(r->name,L"source_mask_bits"))text=L"IPv4 source-prefix length in bits";
 if(id==sxnm_netflow_v5_record.id&&!xx_rt_wcscmp(r->name,L"destination_mask_bits"))text=L"IPv4 destination-prefix length in bits";
 if(id==sxnm_ntlm_negotiate.id&&!xx_rt_wcscmp(r->name,L"domain_buffer_offset"))text=L"Byte offset from the start of the NTLM message";
 if(id==sxnm_ntlm_negotiate.id&&!xx_rt_wcscmp(r->name,L"workstation_buffer_offset"))text=L"Byte offset from the start of the NTLM message";
 if(id==sxnm_mqtt_connect.id&&!xx_rt_wcscmp(r->name,L"keepalive_seconds"))text=L"Maximum allowed idle interval in seconds; zero disables keepalive";
 if(id==sxnm_mqtt_connect.id&&!xx_rt_wcscmp(r->name,L"connect_flags"))text=L"Username:0x80, password:0x40, will-retain:0x20, will-QoS:0x18, will:0x04, clean-session:0x02";
 if(id==sxnm_mqtt_control_byte.id&&!xx_rt_wcscmp(r->name,L"packet_type_and_flags"))text=L"High nibble: MQTT control packet type; low nibble: packet-specific flags";
 if(id==sxnm_amqp_content_header.id&&!xx_rt_wcscmp(r->name,L"body_size"))text=L"Total body bytes across the following content-body frames";
 if(id==sxnm_amqp_content_header.id&&!xx_rt_wcscmp(r->name,L"property_flags"))text=L"Presence bits for Basic properties in descending wire order; low bit indicates continuation";
 if(id==sxnm_amqp_field_type.id&&!xx_rt_wcscmp(r->name,L"field_type"))text=L"Published AMQP 0-9-1 field-table dialect: s=short string, l=unsigned 64-bit; other broker dialects differ";
 if(id==sxnm_amqp_decimal.id&&!xx_rt_wcscmp(r->name,L"scale"))text=L"Power-of-ten fractional scale applied to the signed mantissa";
 if(id==sxnm_amqp_timestamp.id&&!xx_rt_wcscmp(r->name,L"unix_seconds"))text=L"Seconds since 1970-01-01 UTC";
 if(id==sxnm_amqp_float_bits.id&&!xx_rt_wcscmp(r->name,L"ieee754_binary32_bits"))text=L"Raw IEEE 754 binary32 bit pattern in network byte order";
 if(id==sxnm_amqp_double_bits.id&&!xx_rt_wcscmp(r->name,L"ieee754_binary64_bits"))text=L"Raw IEEE 754 binary64 bit pattern in network byte order";
 if(id==sxnm_websocket_frame_header.id&&!xx_rt_wcscmp(r->name,L"fin_rsv_opcode"))text=L"FIN=0x80, RSV1..3=0x70, opcode=low 4 bits";
 if(id==sxnm_websocket_frame_header.id&&!xx_rt_wcscmp(r->name,L"mask_and_length"))text=L"High bit: masking; low 7 bits: length or 126/127 extended-length marker";
 if(id==sxnm_rtps_data_le.id&&!xx_rt_wcscmp(r->name,L"inline_qos_offset"))text=L"Byte offset from immediately after this offset field to the inline-QoS/data boundary";
 if(id==sxnm_rtps_timestamp_le.id&&!xx_rt_wcscmp(r->name,L"seconds"))text=L"Signed seconds relative to the RTPS timestamp epoch";
 if(id==sxnm_rtps_timestamp_le.id&&!xx_rt_wcscmp(r->name,L"fraction"))text=L"Fractional second in units of 2^-32 seconds";
 if(id==sxnm_rtps_submessage_le.id&&!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 selects little-endian submessage fields; other bits depend on submessage kind";
 if(id==sxnm_rtps_submessage_le.id&&!xx_rt_wcscmp(r->name,L"following_length"))text=L"Bytes following the four-byte submessage header; zero can mean the remaining message";
 if(id==sxnm_rtps_data_le.id&&!xx_rt_wcscmp(r->name,L"sequence_high"))text=L"Signed high 32 bits of a sequence number; followed by its unsigned low 32 bits";
 if(id==sxnm_rtps_heartbeat_le.id&&!xx_rt_wcscmp(r->name,L"first_sequence_high"))text=L"Signed high 32 bits of a sequence number; followed by its unsigned low 32 bits";
 if(id==sxnm_rtps_heartbeat_le.id&&!xx_rt_wcscmp(r->name,L"last_sequence_high"))text=L"Signed high 32 bits of a sequence number; followed by its unsigned low 32 bits";
 if(id==sxnm_dcerpc_header_le.id&&!xx_rt_wcscmp(r->name,L"data_representation"))text=L"Byte 0: integer byte order; remaining representation bytes are defined by DCE/RPC";
 if(id==sxnm_dcerpc_request_le.id&&!xx_rt_wcscmp(r->name,L"allocation_hint"))text=L"Advisory total stub bytes for this call; not a source-file offset";
 if(id==sxnm_dcerpc_response_le.id&&!xx_rt_wcscmp(r->name,L"allocation_hint"))text=L"Advisory total stub bytes for this call; not a source-file offset";
 if(id==sxnm_rtps_data_be.id&&!xx_rt_wcscmp(r->name,L"inline_qos_offset"))text=L"Byte offset from immediately after this offset field to the inline-QoS/data boundary";
 if(id==sxnm_rtps_timestamp_be.id&&!xx_rt_wcscmp(r->name,L"seconds"))text=L"Signed seconds relative to the RTPS timestamp epoch";
 if(id==sxnm_rtps_timestamp_be.id&&!xx_rt_wcscmp(r->name,L"fraction"))text=L"Fractional second in units of 2^-32 seconds";
 if(id==sxnm_rtps_submessage_be.id&&!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 selects little-endian submessage fields; other bits depend on submessage kind";
 if(id==sxnm_rtps_submessage_be.id&&!xx_rt_wcscmp(r->name,L"following_length"))text=L"Bytes following the four-byte submessage header; zero can mean the remaining message";
 if(id==sxnm_rtps_data_be.id&&!xx_rt_wcscmp(r->name,L"sequence_high"))text=L"Signed high 32 bits of a sequence number; followed by its unsigned low 32 bits";
 if(id==sxnm_rtps_heartbeat_be.id&&!xx_rt_wcscmp(r->name,L"first_sequence_high"))text=L"Signed high 32 bits of a sequence number; followed by its unsigned low 32 bits";
 if(id==sxnm_rtps_heartbeat_be.id&&!xx_rt_wcscmp(r->name,L"last_sequence_high"))text=L"Signed high 32 bits of a sequence number; followed by its unsigned low 32 bits";
 if(id==sxnm_dcerpc_header_be.id&&!xx_rt_wcscmp(r->name,L"data_representation"))text=L"Byte 0: integer byte order; remaining representation bytes are defined by DCE/RPC";
 if(id==sxnm_dcerpc_request_be.id&&!xx_rt_wcscmp(r->name,L"allocation_hint"))text=L"Advisory total stub bytes for this call; not a source-file offset";
 if(id==sxnm_dcerpc_response_be.id&&!xx_rt_wcscmp(r->name,L"allocation_hint"))text=L"Advisory total stub bytes for this call; not a source-file offset";
 if(id==sxnm_mqtt_remaining_length_1.id&&!xx_rt_wcscmp(r->name,L"remaining_length"))text=L"Unsigned base-128 byte count after this variable-length field";
 if(id==sxnm_mqtt_remaining_length_2.id&&!xx_rt_wcscmp(r->name,L"remaining_length"))text=L"Unsigned base-128 byte count after this variable-length field";
 if(id==sxnm_mqtt_remaining_length_3.id&&!xx_rt_wcscmp(r->name,L"remaining_length"))text=L"Unsigned base-128 byte count after this variable-length field";
 if(id==sxnm_mqtt_remaining_length_4.id&&!xx_rt_wcscmp(r->name,L"remaining_length"))text=L"Unsigned base-128 byte count after this variable-length field";
 if(number&&id==sxnm_ethernet_header.id&&!xx_rt_wcscmp(r->name,L"ether_type")){switch(value){case 2048:text=L"ETHERTYPE_IPV4";break;case 34525:text=L"ETHERTYPE_IPV6";break;default:break;}}
 if(number&&id==sxnm_ipv4_header.id&&!xx_rt_wcscmp(r->name,L"protocol")){switch(value){case 17:text=L"IPPROTO_UDP";break;default:break;}}
 if(number&&id==sxnm_ipv6_header.id&&!xx_rt_wcscmp(r->name,L"next_header")){switch(value){case 17:text=L"IPPROTO_UDP";break;default:break;}}
 if(number&&id==sxnm_icmp_echo_header.id&&!xx_rt_wcscmp(r->name,L"message_type")){switch(value){case 0:text=L"ICMP_ECHO_REPLY";break;case 8:text=L"ICMP_ECHO_REQUEST";break;default:break;}}
 if(number&&id==sxnm_bgp_message_header.id&&!xx_rt_wcscmp(r->name,L"message_type")){switch(value){case 1:text=L"BGP_OPEN";break;case 4:text=L"BGP_KEEPALIVE";break;default:break;}}
 if(number&&id==sxnm_bgp_optional_parameter.id&&!xx_rt_wcscmp(r->name,L"parameter_type")){switch(value){case 2:text=L"CAPABILITY";break;default:break;}}
 if(number&&id==sxnm_bgp_capability_header.id&&!xx_rt_wcscmp(r->name,L"capability_code")){switch(value){case 1:text=L"MULTIPROTOCOL_EXTENSIONS";break;case 2:text=L"ROUTE_REFRESH";break;case 65:text=L"FOUR_OCTET_AS_NUMBER";break;default:break;}}
 if(number&&id==sxnm_ospfv2_header.id&&!xx_rt_wcscmp(r->name,L"packet_type")){switch(value){case 1:text=L"HELLO";break;default:break;}}
 if(number&&id==sxnm_ospfv2_header.id&&!xx_rt_wcscmp(r->name,L"authentication_type")){switch(value){case 0:text=L"NULL_AUTHENTICATION";break;default:break;}}
 if(number&&id==sxnm_sctp_data_chunk.id&&!xx_rt_wcscmp(r->name,L"chunk_type")){switch(value){case 0:text=L"DATA";break;default:break;}}
 if(number&&id==sxnm_isakmp_header.id&&!xx_rt_wcscmp(r->name,L"next_payload")){switch(value){case 1:text=L"SECURITY_ASSOCIATION";break;default:break;}}
 if(number&&id==sxnm_isakmp_header.id&&!xx_rt_wcscmp(r->name,L"exchange_type")){switch(value){case 2:text=L"IDENTITY_PROTECTION";break;default:break;}}
 if(number&&id==sxnm_isakmp_sa_payload.id&&!xx_rt_wcscmp(r->name,L"domain_of_interpretation")){switch(value){case 1:text=L"IPSEC_DOI";break;default:break;}}
 if(number&&id==sxnm_isakmp_proposal.id&&!xx_rt_wcscmp(r->name,L"protocol_id")){switch(value){case 1:text=L"ISAKMP";break;default:break;}}
 if(number&&id==sxnm_isakmp_transform.id&&!xx_rt_wcscmp(r->name,L"transform_id")){switch(value){case 1:text=L"KEY_IKE";break;default:break;}}
 if(number&&id==sxnm_rtcp_header.id&&!xx_rt_wcscmp(r->name,L"packet_type")){switch(value){case 200:text=L"SR";break;case 201:text=L"RR";break;case 202:text=L"SDES";break;case 203:text=L"BYE";break;case 204:text=L"APP";break;default:break;}}
 if(number&&id==sxnm_rtcp_sdes_item.id&&!xx_rt_wcscmp(r->name,L"item_type")){switch(value){case 1:text=L"CNAME";break;case 2:text=L"NAME";break;case 3:text=L"EMAIL";break;case 4:text=L"PHONE";break;case 5:text=L"LOC";break;case 6:text=L"TOOL";break;case 7:text=L"NOTE";break;default:break;}}
 if(number&&id==sxnm_tls_record_header.id&&!xx_rt_wcscmp(r->name,L"content_type")){switch(value){case 20:text=L"change_cipher_spec";break;case 22:text=L"handshake";break;case 23:text=L"application_data";break;default:break;}}
 if(number&&id==sxnm_tls_handshake_header.id&&!xx_rt_wcscmp(r->name,L"handshake_type")){switch(value){case 1:text=L"client_hello";break;case 2:text=L"server_hello";break;default:break;}}
 if(number&&id==sxnm_tls_extension_header.id&&!xx_rt_wcscmp(r->name,L"extension_type")){switch(value){case 0:text=L"server_name";break;case 10:text=L"supported_groups";break;case 11:text=L"ec_point_formats";break;case 13:text=L"signature_algorithms";break;case 43:text=L"supported_versions";break;case 50:text=L"signature_algorithms_cert";break;case 51:text=L"key_share";break;default:break;}}
 if(number&&id==sxnm_tls_cipher_suite.id&&!xx_rt_wcscmp(r->name,L"cipher_suite")){switch(value){case 4865:text=L"TLS_AES_128_GCM_SHA256";break;case 4866:text=L"TLS_AES_256_GCM_SHA384";break;case 4867:text=L"TLS_CHACHA20_POLY1305_SHA256";break;default:break;}}
 if(number&&id==sxnm_tls_compression_method.id&&!xx_rt_wcscmp(r->name,L"compression_method")){switch(value){case 0:text=L"NULL_COMPRESSION";break;default:break;}}
 if(number&&id==sxnm_diameter_header.id&&!xx_rt_wcscmp(r->name,L"command_code")){switch(value){case 257:text=L"CAPABILITIES_EXCHANGE";break;default:break;}}
 if(number&&id==sxnm_diameter_avp_header.id&&!xx_rt_wcscmp(r->name,L"avp_code")){switch(value){case 264:text=L"Origin-Host";break;case 296:text=L"Origin-Realm";break;case 257:text=L"Host-IP-Address";break;case 266:text=L"Vendor-Id";break;case 269:text=L"Product-Name";break;default:break;}}
 if(number&&id==sxnm_diameter_address_family.id&&!xx_rt_wcscmp(r->name,L"address_family")){switch(value){case 1:text=L"IPv4";break;case 2:text=L"IPv6";break;default:break;}}
 if(number&&id==sxnm_tacacs_header.id&&!xx_rt_wcscmp(r->name,L"packet_type")){switch(value){case 1:text=L"AUTHENTICATION";break;default:break;}}
 if(number&&id==sxnm_tacacs_authentication_start.id&&!xx_rt_wcscmp(r->name,L"action")){switch(value){case 1:text=L"LOGIN";break;default:break;}}
 if(number&&id==sxnm_gtpv1_header.id&&!xx_rt_wcscmp(r->name,L"message_type")){switch(value){case 255:text=L"G_PDU";break;default:break;}}
 if(number&&id==sxnm_pfcp_node_header.id&&!xx_rt_wcscmp(r->name,L"message_type")){switch(value){case 5:text=L"ASSOCIATION_SETUP_REQUEST";break;default:break;}}
 if(number&&id==sxnm_pfcp_information_element.id&&!xx_rt_wcscmp(r->name,L"ie_type")){switch(value){case 60:text=L"Node_ID";break;case 96:text=L"Recovery_Time_Stamp";break;default:break;}}
 if(number&&id==sxnm_pfcp_node_id_type.id&&!xx_rt_wcscmp(r->name,L"node_id_type")){switch(value){case 0:text=L"IPv4";break;case 1:text=L"IPv6";break;case 2:text=L"FQDN";break;default:break;}}
 if(number&&id==sxnm_pptp_control_header.id&&!xx_rt_wcscmp(r->name,L"control_message_type")){switch(value){case 1:text=L"START_CONTROL_CONNECTION_REQUEST";break;default:break;}}
 if(number&&id==sxnm_rsvp_header.id&&!xx_rt_wcscmp(r->name,L"message_type")){switch(value){case 20:text=L"HELLO";break;default:break;}}
 if(number&&id==sxnm_rsvp_object_header.id&&!xx_rt_wcscmp(r->name,L"class_number")){switch(value){case 22:text=L"HELLO";break;default:break;}}
 if(number&&id==sxnm_rsvp_object_header.id&&!xx_rt_wcscmp(r->name,L"class_type")){switch(value){case 1:text=L"HELLO_REQUEST";break;case 2:text=L"HELLO_ACK";break;default:break;}}
 if(number&&id==sxnm_pim_option_header.id&&!xx_rt_wcscmp(r->name,L"option_type")){switch(value){case 1:text=L"Holdtime";break;case 2:text=L"LAN_Prune_Delay";break;case 19:text=L"DR_Priority";break;case 20:text=L"Generation_ID";break;default:break;}}
 if(number&&id==sxnm_l2tp_message_type.id&&!xx_rt_wcscmp(r->name,L"message_type")){switch(value){case 1:text=L"SCCRQ";break;default:break;}}
 if(number&&id==sxnm_l2tp_avp_header.id&&!xx_rt_wcscmp(r->name,L"attribute_type")){switch(value){case 0:text=L"Message_Type";break;case 2:text=L"Protocol_Version";break;case 3:text=L"Framing_Capabilities";break;case 4:text=L"Bearer_Capabilities";break;case 6:text=L"Firmware_Revision";break;case 7:text=L"Host_Name";break;case 8:text=L"Vendor_Name";break;case 9:text=L"Assigned_Tunnel_ID";break;case 10:text=L"Receive_Window_Size";break;default:break;}}
 if(number&&id==sxnm_ntlm_negotiate.id&&!xx_rt_wcscmp(r->name,L"message_type")){switch(value){case 1:text=L"NEGOTIATE_MESSAGE";break;default:break;}}
 if(number&&id==sxnm_rtps_cdr_encapsulation.id&&!xx_rt_wcscmp(r->name,L"representation_identifier")){switch(value){case 0:text=L"CDR_BE";break;case 1:text=L"CDR_LE";break;default:break;}}
 if(number&&id==sxnm_mqtt_connack.id&&!xx_rt_wcscmp(r->name,L"return_code")){switch(value){case 0:text=L"CONNECTION_ACCEPTED";break;case 1:text=L"UNACCEPTABLE_PROTOCOL_VERSION";break;case 2:text=L"IDENTIFIER_REJECTED";break;case 3:text=L"SERVER_UNAVAILABLE";break;case 4:text=L"BAD_USERNAME_OR_PASSWORD";break;case 5:text=L"NOT_AUTHORIZED";break;default:break;}}
 if(number&&id==sxnm_amqp_frame_header.id&&!xx_rt_wcscmp(r->name,L"frame_type")){switch(value){case 1:text=L"METHOD";break;case 2:text=L"HEADER";break;case 3:text=L"BODY";break;case 8:text=L"HEARTBEAT";break;default:break;}}
 if(number&&id==sxnm_amqp_delivery_mode.id&&!xx_rt_wcscmp(r->name,L"delivery_mode")){switch(value){case 1:text=L"NON_PERSISTENT";break;case 2:text=L"PERSISTENT";break;default:break;}}
 if(number&&id==sxnm_websocket_close_code.id&&!xx_rt_wcscmp(r->name,L"status_code")){switch(value){case 1000:text=L"NORMAL_CLOSURE";break;case 1001:text=L"GOING_AWAY";break;case 1002:text=L"PROTOCOL_ERROR";break;case 1003:text=L"UNSUPPORTED_DATA";break;case 1007:text=L"INVALID_PAYLOAD_DATA";break;case 1008:text=L"POLICY_VIOLATION";break;case 1009:text=L"MESSAGE_TOO_BIG";break;case 1010:text=L"MANDATORY_EXTENSION";break;case 1011:text=L"INTERNAL_ERROR";break;default:break;}}
 if(number&&id==sxnm_rtps_submessage_le.id&&!xx_rt_wcscmp(r->name,L"submessage_id")){switch(value){case 7:text=L"HEARTBEAT";break;case 9:text=L"INFO_TS";break;case 14:text=L"INFO_DST";break;case 21:text=L"DATA";break;default:break;}}
 if(number&&id==sxnm_dcerpc_header_le.id&&!xx_rt_wcscmp(r->name,L"packet_type")){switch(value){case 0:text=L"REQUEST";break;case 2:text=L"RESPONSE";break;case 11:text=L"BIND";break;default:break;}}
 if(number&&id==sxnm_rtps_submessage_be.id&&!xx_rt_wcscmp(r->name,L"submessage_id")){switch(value){case 7:text=L"HEARTBEAT";break;case 9:text=L"INFO_TS";break;case 14:text=L"INFO_DST";break;case 21:text=L"DATA";break;default:break;}}
 if(number&&id==sxnm_dcerpc_header_be.id&&!xx_rt_wcscmp(r->name,L"packet_type")){switch(value){case 0:text=L"REQUEST";break;case 2:text=L"RESPONSE";break;case 11:text=L"BIND";break;default:break;}}
 return !text||xx_data_struct_record_set_comment(r,text);
}
