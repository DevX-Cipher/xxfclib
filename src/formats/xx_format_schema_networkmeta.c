/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical metadata of native-validated network protocol streams. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_networkmeta.h"
static const xx_data_struct_field_desc sxnm_ethernet_header_fields[]={
 SX_FIELD("destination_mac","bytes",0,6,SX_NONE),
 SX_FIELD("source_mac","bytes",6,6,SX_NONE),
 SX_FIELD("ether_type","uint16",12,2,SX_ID),
};
const sx_layout sxnm_ethernet_header={UINT32_C(0x60260001),"ethernet_header",sxnm_ethernet_header_fields,SX_COUNT(sxnm_ethernet_header_fields),SX_BE};
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
const sx_layout sxnm_icmp_echo_header={UINT32_C(0x60260007),"icmp_echo_header",sxnm_icmp_echo_header_fields,SX_COUNT(sxnm_icmp_echo_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_bgp_message_header_fields[]={
 SX_FIELD("marker","bytes",0,16,SX_SIGNATURE),
 SX_FIELD("message_length","uint16",16,2,SX_SIZE),
 SX_FIELD("message_type","uint8",18,1,SX_ID),
};
const sx_layout sxnm_bgp_message_header={UINT32_C(0x60260008),"bgp_message_header",sxnm_bgp_message_header_fields,SX_COUNT(sxnm_bgp_message_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_bgp_open_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("autonomous_system","uint16",1,2,SX_ID),
 SX_FIELD("hold_time","uint16",3,2,SX_NONE),
 SX_FIELD("router_identifier","bytes",5,4,SX_NONE),
 SX_FIELD("optional_parameters_length","uint8",9,1,SX_SIZE),
};
const sx_layout sxnm_bgp_open={UINT32_C(0x60260009),"bgp_open",sxnm_bgp_open_fields,SX_COUNT(sxnm_bgp_open_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_bgp_optional_parameter_fields[]={
 SX_FIELD("parameter_type","uint8",0,1,SX_ID),
 SX_FIELD("parameter_length","uint8",1,1,SX_SIZE),
};
const sx_layout sxnm_bgp_optional_parameter={UINT32_C(0x6026000A),"bgp_optional_parameter",sxnm_bgp_optional_parameter_fields,SX_COUNT(sxnm_bgp_optional_parameter_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_bgp_capability_header_fields[]={
 SX_FIELD("capability_code","uint8",0,1,SX_ID),
 SX_FIELD("capability_length","uint8",1,1,SX_SIZE),
};
const sx_layout sxnm_bgp_capability_header={UINT32_C(0x6026000B),"bgp_capability_header",sxnm_bgp_capability_header_fields,SX_COUNT(sxnm_bgp_capability_header_fields),SX_BE};
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
const sx_layout sxnm_ospfv2_header={UINT32_C(0x6026000C),"ospfv2_header",sxnm_ospfv2_header_fields,SX_COUNT(sxnm_ospfv2_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ospfv2_hello_fields[]={
 SX_FIELD("network_mask","bytes",0,4,SX_NONE),
 SX_FIELD("hello_interval","uint16",4,2,SX_NONE),
 SX_FIELD("options","uint8",6,1,SX_FLAGS),
 SX_FIELD("router_priority","uint8",7,1,SX_NONE),
 SX_FIELD("router_dead_interval","uint32",8,4,SX_NONE),
 SX_FIELD("designated_router","bytes",12,4,SX_NONE),
 SX_FIELD("backup_designated_router","bytes",16,4,SX_NONE),
};
const sx_layout sxnm_ospfv2_hello={UINT32_C(0x6026000D),"ospfv2_hello",sxnm_ospfv2_hello_fields,SX_COUNT(sxnm_ospfv2_hello_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_sctp_common_header_fields[]={
 SX_FIELD("source_port","uint16",0,2,SX_ID),
 SX_FIELD("destination_port","uint16",2,2,SX_ID),
 SX_FIELD("verification_tag","uint32",4,4,SX_ID),
 SX_FIELD("checksum_crc32c","uint32le",8,4,SX_CHECKSUM),
};
const sx_layout sxnm_sctp_common_header={UINT32_C(0x6026000F),"sctp_common_header",sxnm_sctp_common_header_fields,SX_COUNT(sxnm_sctp_common_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_sctp_data_chunk_fields[]={
 SX_FIELD("chunk_type","uint8",0,1,SX_ID),
 SX_FIELD("chunk_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("chunk_length","uint16",2,2,SX_SIZE),
 SX_FIELD("transmission_sequence","uint32",4,4,SX_ID),
 SX_FIELD("stream_identifier","uint16",8,2,SX_ID),
 SX_FIELD("stream_sequence","uint16",10,2,SX_ID),
 SX_FIELD("payload_protocol_identifier","uint32",12,4,SX_ID),
};
const sx_layout sxnm_sctp_data_chunk={UINT32_C(0x60260010),"sctp_data_chunk",sxnm_sctp_data_chunk_fields,SX_COUNT(sxnm_sctp_data_chunk_fields),SX_BE};
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
const sx_layout sxnm_isakmp_header={UINT32_C(0x60260011),"isakmp_header",sxnm_isakmp_header_fields,SX_COUNT(sxnm_isakmp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_sa_payload_fields[]={
 SX_FIELD("next_payload","uint8",0,1,SX_ID),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("payload_length","uint16",2,2,SX_SIZE),
 SX_FIELD("domain_of_interpretation","uint32",4,4,SX_ID),
 SX_FIELD("situation","uint32",8,4,SX_FLAGS),
};
const sx_layout sxnm_isakmp_sa_payload={UINT32_C(0x60260012),"isakmp_sa_payload",sxnm_isakmp_sa_payload_fields,SX_COUNT(sxnm_isakmp_sa_payload_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_proposal_fields[]={
 SX_FIELD("next_payload","uint8",0,1,SX_ID),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("payload_length","uint16",2,2,SX_SIZE),
 SX_FIELD("proposal_number","uint8",4,1,SX_ID),
 SX_FIELD("protocol_id","uint8",5,1,SX_ID),
 SX_FIELD("spi_size","uint8",6,1,SX_SIZE),
 SX_FIELD("transform_count","uint8",7,1,SX_COUNT_PROP),
};
const sx_layout sxnm_isakmp_proposal={UINT32_C(0x60260013),"isakmp_proposal",sxnm_isakmp_proposal_fields,SX_COUNT(sxnm_isakmp_proposal_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_transform_fields[]={
 SX_FIELD("next_payload","uint8",0,1,SX_ID),
 SX_FIELD("reserved1","uint8",1,1,SX_RESERVED),
 SX_FIELD("payload_length","uint16",2,2,SX_SIZE),
 SX_FIELD("transform_number","uint8",4,1,SX_ID),
 SX_FIELD("transform_id","uint8",5,1,SX_ID),
 SX_FIELD("reserved2","uint16",6,2,SX_RESERVED),
};
const sx_layout sxnm_isakmp_transform={UINT32_C(0x60260014),"isakmp_transform",sxnm_isakmp_transform_fields,SX_COUNT(sxnm_isakmp_transform_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_basic_attribute_fields[]={
 SX_FIELD("format_and_type","uint16",0,2,SX_FLAGS),
 SX_FIELD("attribute_value","uint16",2,2,SX_NONE),
};
const sx_layout sxnm_isakmp_basic_attribute={UINT32_C(0x60260015),"isakmp_basic_attribute",sxnm_isakmp_basic_attribute_fields,SX_COUNT(sxnm_isakmp_basic_attribute_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_isakmp_variable_attribute_fields[]={
 SX_FIELD("format_and_type","uint16",0,2,SX_FLAGS),
 SX_FIELD("attribute_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxnm_isakmp_variable_attribute={UINT32_C(0x60260016),"isakmp_variable_attribute",sxnm_isakmp_variable_attribute_fields,SX_COUNT(sxnm_isakmp_variable_attribute_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtp_header_fields[]={
 SX_FIELD("version_padding_extension_csrc_count","uint8",0,1,SX_FLAGS),
 SX_FIELD("marker_and_payload_type","uint8",1,1,SX_FLAGS),
 SX_FIELD("sequence_number","uint16",2,2,SX_ID),
 SX_FIELD("timestamp","uint32",4,4,SX_NONE),
 SX_FIELD("synchronization_source","uint32",8,4,SX_ID),
};
const sx_layout sxnm_rtp_header={UINT32_C(0x60260017),"rtp_header",sxnm_rtp_header_fields,SX_COUNT(sxnm_rtp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtp_extension_header_fields[]={
 SX_FIELD("profile","uint16",0,2,SX_ID),
 SX_FIELD("data_length_words","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxnm_rtp_extension_header={UINT32_C(0x60260019),"rtp_extension_header",sxnm_rtp_extension_header_fields,SX_COUNT(sxnm_rtp_extension_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtp_padding_count_fields[]={
 SX_FIELD("padding_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxnm_rtp_padding_count={UINT32_C(0x6026001A),"rtp_padding_count",sxnm_rtp_padding_count_fields,SX_COUNT(sxnm_rtp_padding_count_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_header_fields[]={
 SX_FIELD("version_padding_count","uint8",0,1,SX_FLAGS),
 SX_FIELD("packet_type","uint8",1,1,SX_ID),
 SX_FIELD("length_words_minus_one","uint16",2,2,SX_NONE),
};
const sx_layout sxnm_rtcp_header={UINT32_C(0x6026001B),"rtcp_header",sxnm_rtcp_header_fields,SX_COUNT(sxnm_rtcp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_sender_info_fields[]={
 SX_FIELD("synchronization_source","uint32",0,4,SX_ID),
 SX_FIELD("ntp_seconds","uint32",4,4,SX_TIME),
 SX_FIELD("ntp_fraction","uint32",8,4,SX_NONE),
 SX_FIELD("rtp_timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("sender_packet_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("sender_octet_count","uint32",20,4,SX_SIZE),
};
const sx_layout sxnm_rtcp_sender_info={UINT32_C(0x6026001C),"rtcp_sender_info",sxnm_rtcp_sender_info_fields,SX_COUNT(sxnm_rtcp_sender_info_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_report_block_fields[]={
 SX_FIELD("source_identifier","uint32",0,4,SX_ID),
 SX_FIELD("fraction_lost","uint8",4,1,SX_NONE),
 SX_FIELD("cumulative_packets_lost","int24",5,3,SX_NONE),
 SX_FIELD("extended_highest_sequence","uint32",8,4,SX_ID),
 SX_FIELD("interarrival_jitter","uint32",12,4,SX_NONE),
 SX_FIELD("last_sender_report","uint32",16,4,SX_NONE),
 SX_FIELD("delay_since_last_report","uint32",20,4,SX_NONE),
};
const sx_layout sxnm_rtcp_report_block={UINT32_C(0x6026001E),"rtcp_report_block",sxnm_rtcp_report_block_fields,SX_COUNT(sxnm_rtcp_report_block_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_sdes_item_fields[]={
 SX_FIELD("item_type","uint8",0,1,SX_ID),
 SX_FIELD("text_length","uint8",1,1,SX_SIZE),
};
const sx_layout sxnm_rtcp_sdes_item={UINT32_C(0x60260020),"rtcp_sdes_item",sxnm_rtcp_sdes_item_fields,SX_COUNT(sxnm_rtcp_sdes_item_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_record_header_fields[]={
 SX_FIELD("content_type","uint8",0,1,SX_ID),
 SX_FIELD("legacy_record_version","uint16",1,2,SX_ID),
 SX_FIELD("payload_length","uint16",3,2,SX_SIZE),
};
const sx_layout sxnm_tls_record_header={UINT32_C(0x60260024),"tls_record_header",sxnm_tls_record_header_fields,SX_COUNT(sxnm_tls_record_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_handshake_header_fields[]={
 SX_FIELD("handshake_type","uint8",0,1,SX_ID),
 SX_FIELD("body_length","uint24",1,3,SX_SIZE),
};
const sx_layout sxnm_tls_handshake_header={UINT32_C(0x60260025),"tls_handshake_header",sxnm_tls_handshake_header_fields,SX_COUNT(sxnm_tls_handshake_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_cipher_suite_fields[]={
 SX_FIELD("cipher_suite","uint16",0,2,SX_ID),
};
const sx_layout sxnm_tls_cipher_suite={UINT32_C(0x60260029),"tls_cipher_suite",sxnm_tls_cipher_suite_fields,SX_COUNT(sxnm_tls_cipher_suite_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_compression_method_fields[]={
 SX_FIELD("compression_method","uint8",0,1,SX_ID),
};
const sx_layout sxnm_tls_compression_method={UINT32_C(0x6026002B),"tls_compression_method",sxnm_tls_compression_method_fields,SX_COUNT(sxnm_tls_compression_method_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_extension_header_fields[]={
 SX_FIELD("extension_type","uint16",0,2,SX_ID),
 SX_FIELD("extension_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxnm_tls_extension_header={UINT32_C(0x6026002D),"tls_extension_header",sxnm_tls_extension_header_fields,SX_COUNT(sxnm_tls_extension_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_diameter_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("message_length","uint24",1,3,SX_SIZE),
 SX_FIELD("command_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("command_code","uint24",5,3,SX_ID),
 SX_FIELD("application_id","uint32",8,4,SX_ID),
 SX_FIELD("hop_by_hop_identifier","uint32",12,4,SX_ID),
 SX_FIELD("end_to_end_identifier","uint32",16,4,SX_ID),
};
const sx_layout sxnm_diameter_header={UINT32_C(0x6026002F),"diameter_header",sxnm_diameter_header_fields,SX_COUNT(sxnm_diameter_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_diameter_avp_header_fields[]={
 SX_FIELD("avp_code","uint32",0,4,SX_ID),
 SX_FIELD("avp_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("avp_length","uint24",5,3,SX_SIZE),
};
const sx_layout sxnm_diameter_avp_header={UINT32_C(0x60260030),"diameter_avp_header",sxnm_diameter_avp_header_fields,SX_COUNT(sxnm_diameter_avp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_diameter_address_family_fields[]={
 SX_FIELD("address_family","uint16",0,2,SX_ID),
};
const sx_layout sxnm_diameter_address_family={UINT32_C(0x60260031),"diameter_address_family",sxnm_diameter_address_family_fields,SX_COUNT(sxnm_diameter_address_family_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tacacs_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("packet_type","uint8",1,1,SX_ID),
 SX_FIELD("sequence_number","uint8",2,1,SX_ID),
 SX_FIELD("flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("session_id","uint32",4,4,SX_ID),
 SX_FIELD("body_length","uint32",8,4,SX_SIZE),
};
const sx_layout sxnm_tacacs_header={UINT32_C(0x60260033),"tacacs_header",sxnm_tacacs_header_fields,SX_COUNT(sxnm_tacacs_header_fields),SX_BE};
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
const sx_layout sxnm_tacacs_authentication_start={UINT32_C(0x60260034),"tacacs_authentication_start",sxnm_tacacs_authentication_start_fields,SX_COUNT(sxnm_tacacs_authentication_start_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gtpv1_header_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("message_type","uint8",1,1,SX_ID),
 SX_FIELD("payload_length","uint16",2,2,SX_SIZE),
 SX_FIELD("tunnel_endpoint_identifier","uint32",4,4,SX_ID),
};
const sx_layout sxnm_gtpv1_header={UINT32_C(0x60260035),"gtpv1_header",sxnm_gtpv1_header_fields,SX_COUNT(sxnm_gtpv1_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_node_header_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("message_type","uint8",1,1,SX_ID),
 SX_FIELD("message_length","uint16",2,2,SX_SIZE),
 SX_FIELD("sequence_number","uint24",4,3,SX_ID),
 SX_FIELD("spare","uint8",7,1,SX_RESERVED),
};
const sx_layout sxnm_pfcp_node_header={UINT32_C(0x60260036),"pfcp_node_header",sxnm_pfcp_node_header_fields,SX_COUNT(sxnm_pfcp_node_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_information_element_fields[]={
 SX_FIELD("ie_type","uint16",0,2,SX_ID),
 SX_FIELD("value_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxnm_pfcp_information_element={UINT32_C(0x60260037),"pfcp_information_element",sxnm_pfcp_information_element_fields,SX_COUNT(sxnm_pfcp_information_element_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_node_id_type_fields[]={
 SX_FIELD("node_id_type","uint8",0,1,SX_ID),
};
const sx_layout sxnm_pfcp_node_id_type={UINT32_C(0x60260038),"pfcp_node_id_type",sxnm_pfcp_node_id_type_fields,SX_COUNT(sxnm_pfcp_node_id_type_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_recovery_time_fields[]={
 SX_FIELD("ntp_seconds","uint32",0,4,SX_TIME),
};
const sx_layout sxnm_pfcp_recovery_time={UINT32_C(0x6026003C),"pfcp_recovery_time",sxnm_pfcp_recovery_time_fields,SX_COUNT(sxnm_pfcp_recovery_time_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pptp_control_header_fields[]={
 SX_FIELD("message_length","uint16",0,2,SX_SIZE),
 SX_FIELD("message_type","uint16",2,2,SX_ID),
 SX_FIELD("magic_cookie","uint32",4,4,SX_SIGNATURE),
 SX_FIELD("control_message_type","uint16",8,2,SX_ID),
 SX_FIELD("reserved","uint16",10,2,SX_RESERVED),
};
const sx_layout sxnm_pptp_control_header={UINT32_C(0x6026003D),"pptp_control_header",sxnm_pptp_control_header_fields,SX_COUNT(sxnm_pptp_control_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rsvp_header_fields[]={
 SX_FIELD("version_and_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("message_type","uint8",1,1,SX_ID),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("send_ttl","uint8",4,1,SX_NONE),
 SX_FIELD("reserved","uint8",5,1,SX_RESERVED),
 SX_FIELD("message_length","uint16",6,2,SX_SIZE),
};
const sx_layout sxnm_rsvp_header={UINT32_C(0x6026003F),"rsvp_header",sxnm_rsvp_header_fields,SX_COUNT(sxnm_rsvp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rsvp_object_header_fields[]={
 SX_FIELD("object_length","uint16",0,2,SX_SIZE),
 SX_FIELD("class_number","uint8",2,1,SX_ID),
 SX_FIELD("class_type","uint8",3,1,SX_ID),
};
const sx_layout sxnm_rsvp_object_header={UINT32_C(0x60260040),"rsvp_object_header",sxnm_rsvp_object_header_fields,SX_COUNT(sxnm_rsvp_object_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_option_header_fields[]={
 SX_FIELD("option_type","uint16",0,2,SX_ID),
 SX_FIELD("option_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxnm_pim_option_header={UINT32_C(0x60260043),"pim_option_header",sxnm_pim_option_header_fields,SX_COUNT(sxnm_pim_option_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_holdtime_fields[]={
 SX_FIELD("hold_time","uint16",0,2,SX_NONE),
};
const sx_layout sxnm_pim_holdtime={UINT32_C(0x60260044),"pim_holdtime",sxnm_pim_holdtime_fields,SX_COUNT(sxnm_pim_holdtime_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_lan_prune_delay_fields[]={
 SX_FIELD("tracking_and_propagation_delay","uint16",0,2,SX_FLAGS),
 SX_FIELD("override_interval","uint16",2,2,SX_NONE),
};
const sx_layout sxnm_pim_lan_prune_delay={UINT32_C(0x60260045),"pim_lan_prune_delay",sxnm_pim_lan_prune_delay_fields,SX_COUNT(sxnm_pim_lan_prune_delay_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_pdu_header_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("pdu_length","uint16",2,2,SX_SIZE),
 SX_FIELD("router_identifier","bytes",4,4,SX_NONE),
 SX_FIELD("label_space","uint16",8,2,SX_ID),
};
const sx_layout sxnm_ldp_pdu_header={UINT32_C(0x60260048),"ldp_pdu_header",sxnm_ldp_pdu_header_fields,SX_COUNT(sxnm_ldp_pdu_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_message_header_fields[]={
 SX_FIELD("unknown_bit_and_type","uint16",0,2,SX_FLAGS),
 SX_FIELD("message_length","uint16",2,2,SX_SIZE),
 SX_FIELD("message_id","uint32",4,4,SX_ID),
};
const sx_layout sxnm_ldp_message_header={UINT32_C(0x60260049),"ldp_message_header",sxnm_ldp_message_header_fields,SX_COUNT(sxnm_ldp_message_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_tlv_header_fields[]={
 SX_FIELD("flags_and_type","uint16",0,2,SX_FLAGS),
 SX_FIELD("value_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxnm_ldp_tlv_header={UINT32_C(0x6026004A),"ldp_tlv_header",sxnm_ldp_tlv_header_fields,SX_COUNT(sxnm_ldp_tlv_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_common_hello_fields[]={
 SX_FIELD("hold_time","uint16",0,2,SX_NONE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
};
const sx_layout sxnm_ldp_common_hello={UINT32_C(0x6026004B),"ldp_common_hello",sxnm_ldp_common_hello_fields,SX_COUNT(sxnm_ldp_common_hello_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gre_header_fields[]={
 SX_FIELD("flags_and_version","uint16",0,2,SX_FLAGS),
 SX_FIELD("protocol_type","uint16",2,2,SX_ID),
};
const sx_layout sxnm_gre_header={UINT32_C(0x6026004E),"gre_header",sxnm_gre_header_fields,SX_COUNT(sxnm_gre_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_control_header_fields[]={
 SX_FIELD("flags_and_version","uint16",0,2,SX_FLAGS),
 SX_FIELD("message_length","uint16",2,2,SX_SIZE),
 SX_FIELD("tunnel_id","uint16",4,2,SX_ID),
 SX_FIELD("session_id","uint16",6,2,SX_ID),
 SX_FIELD("send_sequence","uint16",8,2,SX_ID),
 SX_FIELD("receive_sequence","uint16",10,2,SX_ID),
};
const sx_layout sxnm_l2tp_control_header={UINT32_C(0x60260052),"l2tp_control_header",sxnm_l2tp_control_header_fields,SX_COUNT(sxnm_l2tp_control_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_avp_header_fields[]={
 SX_FIELD("flags_and_length","uint16",0,2,SX_FLAGS),
 SX_FIELD("vendor_id","uint16",2,2,SX_ID),
 SX_FIELD("attribute_type","uint16",4,2,SX_ID),
};
const sx_layout sxnm_l2tp_avp_header={UINT32_C(0x60260053),"l2tp_avp_header",sxnm_l2tp_avp_header_fields,SX_COUNT(sxnm_l2tp_avp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_message_type_fields[]={
 SX_FIELD("message_type","uint16",0,2,SX_ID),
};
const sx_layout sxnm_l2tp_message_type={UINT32_C(0x60260054),"l2tp_message_type",sxnm_l2tp_message_type_fields,SX_COUNT(sxnm_l2tp_message_type_fields),SX_BE};
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
const sx_layout sxnm_netflow_v5_header={UINT32_C(0x6026005B),"netflow_v5_header",sxnm_netflow_v5_header_fields,SX_COUNT(sxnm_netflow_v5_header_fields),SX_BE};
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
const sx_layout sxnm_netflow_v5_record={UINT32_C(0x6026005C),"netflow_v5_record",sxnm_netflow_v5_record_fields,SX_COUNT(sxnm_netflow_v5_record_fields),SX_BE};
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
const sx_layout sxnm_ntlm_negotiate={UINT32_C(0x6026005D),"ntlm_negotiate",sxnm_ntlm_negotiate_fields,SX_COUNT(sxnm_ntlm_negotiate_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_submessage_le_fields[]={
 SX_FIELD("submessage_id","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("following_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxnm_rtps_submessage_le={UINT32_C(0x60260060),"rtps_submessage_le",sxnm_rtps_submessage_le_fields,SX_COUNT(sxnm_rtps_submessage_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_timestamp_le_fields[]={
 SX_FIELD("seconds","int32",0,4,SX_TIME),
 SX_FIELD("fraction","uint32",4,4,SX_NONE),
};
const sx_layout sxnm_rtps_timestamp_le={UINT32_C(0x60260061),"rtps_timestamp_le",sxnm_rtps_timestamp_le_fields,SX_COUNT(sxnm_rtps_timestamp_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_heartbeat_le_fields[]={
 SX_FIELD("reader_entity_id","bytes",0,4,SX_ID),
 SX_FIELD("writer_entity_id","bytes",4,4,SX_ID),
 SX_FIELD("first_sequence_high","int32",8,4,SX_NONE),
 SX_FIELD("first_sequence_low","uint32",12,4,SX_NONE),
 SX_FIELD("last_sequence_high","int32",16,4,SX_NONE),
 SX_FIELD("last_sequence_low","uint32",20,4,SX_NONE),
 SX_FIELD("heartbeat_count","int32",24,4,SX_ID),
};
const sx_layout sxnm_rtps_heartbeat_le={UINT32_C(0x60260062),"rtps_heartbeat_le",sxnm_rtps_heartbeat_le_fields,SX_COUNT(sxnm_rtps_heartbeat_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_data_le_fields[]={
 SX_FIELD("extra_flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("inline_qos_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("reader_entity_id","bytes",4,4,SX_ID),
 SX_FIELD("writer_entity_id","bytes",8,4,SX_ID),
 SX_FIELD("sequence_high","int32",12,4,SX_NONE),
 SX_FIELD("sequence_low","uint32",16,4,SX_NONE),
};
const sx_layout sxnm_rtps_data_le={UINT32_C(0x60260063),"rtps_data_le",sxnm_rtps_data_le_fields,SX_COUNT(sxnm_rtps_data_le_fields),SX_LE};
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
const sx_layout sxnm_dcerpc_header_le={UINT32_C(0x60260064),"dcerpc_header_le",sxnm_dcerpc_header_le_fields,SX_COUNT(sxnm_dcerpc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_request_le_fields[]={
 SX_FIELD("allocation_hint","uint32",0,4,SX_SIZE),
 SX_FIELD("context_id","uint16",4,2,SX_ID),
 SX_FIELD("operation_number","uint16",6,2,SX_ID),
};
const sx_layout sxnm_dcerpc_request_le={UINT32_C(0x60260068),"dcerpc_request_le",sxnm_dcerpc_request_le_fields,SX_COUNT(sxnm_dcerpc_request_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_response_le_fields[]={
 SX_FIELD("allocation_hint","uint32",0,4,SX_SIZE),
 SX_FIELD("context_id","uint16",4,2,SX_ID),
 SX_FIELD("cancel_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
};
const sx_layout sxnm_dcerpc_response_le={UINT32_C(0x60260069),"dcerpc_response_le",sxnm_dcerpc_response_le_fields,SX_COUNT(sxnm_dcerpc_response_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_rtps_submessage_be_fields[]={
 SX_FIELD("submessage_id","uint8",0,1,SX_ID),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("following_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxnm_rtps_submessage_be={UINT32_C(0x6026006A),"rtps_submessage_be",sxnm_rtps_submessage_be_fields,SX_COUNT(sxnm_rtps_submessage_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_timestamp_be_fields[]={
 SX_FIELD("seconds","int32",0,4,SX_TIME),
 SX_FIELD("fraction","uint32",4,4,SX_NONE),
};
const sx_layout sxnm_rtps_timestamp_be={UINT32_C(0x6026006B),"rtps_timestamp_be",sxnm_rtps_timestamp_be_fields,SX_COUNT(sxnm_rtps_timestamp_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_heartbeat_be_fields[]={
 SX_FIELD("reader_entity_id","bytes",0,4,SX_ID),
 SX_FIELD("writer_entity_id","bytes",4,4,SX_ID),
 SX_FIELD("first_sequence_high","int32",8,4,SX_NONE),
 SX_FIELD("first_sequence_low","uint32",12,4,SX_NONE),
 SX_FIELD("last_sequence_high","int32",16,4,SX_NONE),
 SX_FIELD("last_sequence_low","uint32",20,4,SX_NONE),
 SX_FIELD("heartbeat_count","int32",24,4,SX_ID),
};
const sx_layout sxnm_rtps_heartbeat_be={UINT32_C(0x6026006C),"rtps_heartbeat_be",sxnm_rtps_heartbeat_be_fields,SX_COUNT(sxnm_rtps_heartbeat_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_data_be_fields[]={
 SX_FIELD("extra_flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("inline_qos_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("reader_entity_id","bytes",4,4,SX_ID),
 SX_FIELD("writer_entity_id","bytes",8,4,SX_ID),
 SX_FIELD("sequence_high","int32",12,4,SX_NONE),
 SX_FIELD("sequence_low","uint32",16,4,SX_NONE),
};
const sx_layout sxnm_rtps_data_be={UINT32_C(0x6026006D),"rtps_data_be",sxnm_rtps_data_be_fields,SX_COUNT(sxnm_rtps_data_be_fields),SX_BE};
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
const sx_layout sxnm_dcerpc_header_be={UINT32_C(0x6026006E),"dcerpc_header_be",sxnm_dcerpc_header_be_fields,SX_COUNT(sxnm_dcerpc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_request_be_fields[]={
 SX_FIELD("allocation_hint","uint32",0,4,SX_SIZE),
 SX_FIELD("context_id","uint16",4,2,SX_ID),
 SX_FIELD("operation_number","uint16",6,2,SX_ID),
};
const sx_layout sxnm_dcerpc_request_be={UINT32_C(0x60260072),"dcerpc_request_be",sxnm_dcerpc_request_be_fields,SX_COUNT(sxnm_dcerpc_request_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_response_be_fields[]={
 SX_FIELD("allocation_hint","uint32",0,4,SX_SIZE),
 SX_FIELD("context_id","uint16",4,2,SX_ID),
 SX_FIELD("cancel_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
};
const sx_layout sxnm_dcerpc_response_be={UINT32_C(0x60260073),"dcerpc_response_be",sxnm_dcerpc_response_be_fields,SX_COUNT(sxnm_dcerpc_response_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_cdr_encapsulation_fields[]={
 SX_FIELD("representation_identifier","uint16",0,2,SX_ID),
 SX_FIELD("representation_options","uint16",2,2,SX_FLAGS),
};
const sx_layout sxnm_rtps_cdr_encapsulation={UINT32_C(0x60260075),"rtps_cdr_encapsulation",sxnm_rtps_cdr_encapsulation_fields,SX_COUNT(sxnm_rtps_cdr_encapsulation_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_control_byte_fields[]={
 SX_FIELD("packet_type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnm_mqtt_control_byte={UINT32_C(0x60260076),"mqtt_control_byte",sxnm_mqtt_control_byte_fields,SX_COUNT(sxnm_mqtt_control_byte_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_remaining_length_1_fields[]={
 SX_FIELD("remaining_length","uleb128_64",0,1,SX_SIZE),
};
const sx_layout sxnm_mqtt_remaining_length_1={UINT32_C(0x60260077),"mqtt_remaining_length_1",sxnm_mqtt_remaining_length_1_fields,SX_COUNT(sxnm_mqtt_remaining_length_1_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_remaining_length_2_fields[]={
 SX_FIELD("remaining_length","uleb128_64",0,2,SX_SIZE),
};
const sx_layout sxnm_mqtt_remaining_length_2={UINT32_C(0x60260078),"mqtt_remaining_length_2",sxnm_mqtt_remaining_length_2_fields,SX_COUNT(sxnm_mqtt_remaining_length_2_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_remaining_length_3_fields[]={
 SX_FIELD("remaining_length","uleb128_64",0,3,SX_SIZE),
};
const sx_layout sxnm_mqtt_remaining_length_3={UINT32_C(0x60260079),"mqtt_remaining_length_3",sxnm_mqtt_remaining_length_3_fields,SX_COUNT(sxnm_mqtt_remaining_length_3_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_remaining_length_4_fields[]={
 SX_FIELD("remaining_length","uleb128_64",0,4,SX_SIZE),
};
const sx_layout sxnm_mqtt_remaining_length_4={UINT32_C(0x6026007A),"mqtt_remaining_length_4",sxnm_mqtt_remaining_length_4_fields,SX_COUNT(sxnm_mqtt_remaining_length_4_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_connect_fields[]={
 SX_FIELD("protocol_name_length","uint16",0,2,SX_SIZE),
 SX_FIELD("protocol_name","char[4]",2,4,SX_SIGNATURE),
 SX_FIELD("protocol_level","uint8",6,1,SX_ID),
 SX_FIELD("connect_flags","uint8",7,1,SX_FLAGS),
 SX_FIELD("keepalive_seconds","uint16",8,2,SX_NONE),
};
const sx_layout sxnm_mqtt_connect={UINT32_C(0x6026007B),"mqtt_connect",sxnm_mqtt_connect_fields,SX_COUNT(sxnm_mqtt_connect_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_mqtt_connack_fields[]={
 SX_FIELD("session_present_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("return_code","uint8",1,1,SX_ID),
};
const sx_layout sxnm_mqtt_connack={UINT32_C(0x6026007D),"mqtt_connack",sxnm_mqtt_connack_fields,SX_COUNT(sxnm_mqtt_connack_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_frame_header_fields[]={
 SX_FIELD("frame_type","uint8",0,1,SX_ID),
 SX_FIELD("channel","uint16",1,2,SX_ID),
 SX_FIELD("payload_length","uint32",3,4,SX_SIZE),
};
const sx_layout sxnm_amqp_frame_header={UINT32_C(0x60260082),"amqp_frame_header",sxnm_amqp_frame_header_fields,SX_COUNT(sxnm_amqp_frame_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_content_header_fields[]={
 SX_FIELD("class_id","uint16",0,2,SX_ID),
 SX_FIELD("weight","uint16",2,2,SX_NONE),
 SX_FIELD("body_size","uint64",4,8,SX_SIZE),
 SX_FIELD("property_flags","uint16",12,2,SX_FLAGS),
};
const sx_layout sxnm_amqp_content_header={UINT32_C(0x60260084),"amqp_content_header",sxnm_amqp_content_header_fields,SX_COUNT(sxnm_amqp_content_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_field_type_fields[]={
 SX_FIELD("field_type","uint8",0,1,SX_ID),
};
const sx_layout sxnm_amqp_field_type={UINT32_C(0x6026008C),"amqp_field_type",sxnm_amqp_field_type_fields,SX_COUNT(sxnm_amqp_field_type_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_float_bits_fields[]={
 SX_FIELD("ieee754_binary32_bits","uint32",0,4,SX_NONE),
};
const sx_layout sxnm_amqp_float_bits={UINT32_C(0x60260096),"amqp_float_bits",sxnm_amqp_float_bits_fields,SX_COUNT(sxnm_amqp_float_bits_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_double_bits_fields[]={
 SX_FIELD("ieee754_binary64_bits","uint64",0,8,SX_NONE),
};
const sx_layout sxnm_amqp_double_bits={UINT32_C(0x60260097),"amqp_double_bits",sxnm_amqp_double_bits_fields,SX_COUNT(sxnm_amqp_double_bits_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_decimal_fields[]={
 SX_FIELD("scale","uint8",0,1,SX_NONE),
 SX_FIELD("mantissa","int32",1,4,SX_NONE),
};
const sx_layout sxnm_amqp_decimal={UINT32_C(0x60260098),"amqp_decimal",sxnm_amqp_decimal_fields,SX_COUNT(sxnm_amqp_decimal_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_timestamp_fields[]={
 SX_FIELD("unix_seconds","uint64",0,8,SX_TIME),
};
const sx_layout sxnm_amqp_timestamp={UINT32_C(0x60260099),"amqp_timestamp",sxnm_amqp_timestamp_fields,SX_COUNT(sxnm_amqp_timestamp_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_amqp_delivery_mode_fields[]={
 SX_FIELD("delivery_mode","uint8",0,1,SX_ID),
};
const sx_layout sxnm_amqp_delivery_mode={UINT32_C(0x6026009B),"amqp_delivery_mode",sxnm_amqp_delivery_mode_fields,SX_COUNT(sxnm_amqp_delivery_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_frame_header_fields[]={
 SX_FIELD("fin_rsv_opcode","uint8",0,1,SX_FLAGS),
 SX_FIELD("mask_and_length","uint8",1,1,SX_FLAGS),
};
const sx_layout sxnm_websocket_frame_header={UINT32_C(0x6026009D),"websocket_frame_header",sxnm_websocket_frame_header_fields,SX_COUNT(sxnm_websocket_frame_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_websocket_close_code_fields[]={
 SX_FIELD("status_code","uint16",0,2,SX_ID),
};
const sx_layout sxnm_websocket_close_code={UINT32_C(0x602600A1),"websocket_close_code",sxnm_websocket_close_code_fields,SX_COUNT(sxnm_websocket_close_code_fields),SX_BE};
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
static bool sx_networkmeta_supports(xx_file_type_t t)
{
 switch(t){case XX_FILE_TYPE_RTP_RTCP:case XX_FILE_TYPE_BGP_MESSAGES:case XX_FILE_TYPE_OSPF_PACKET:case XX_FILE_TYPE_SCTP_PACKET:case XX_FILE_TYPE_ISAKMP_MESSAGE:case XX_FILE_TYPE_TLS_RECORDS:case XX_FILE_TYPE_ETHERNET_FRAME:case XX_FILE_TYPE_IP_PACKET:case XX_FILE_TYPE_ICMP_MESSAGE:case XX_FILE_TYPE_DIAMETER_MESSAGE:case XX_FILE_TYPE_TACACS_PACKET:case XX_FILE_TYPE_GTP_MESSAGE:case XX_FILE_TYPE_PFCP_MESSAGE:case XX_FILE_TYPE_PPTP_MESSAGE:case XX_FILE_TYPE_RSVP_MESSAGE:case XX_FILE_TYPE_DDS_RTPS:case XX_FILE_TYPE_PIM_MESSAGE:case XX_FILE_TYPE_LDP_MESSAGE:case XX_FILE_TYPE_GRE_PACKET:case XX_FILE_TYPE_L2TP_PACKET:case XX_FILE_TYPE_NETFLOW_DATAGRAM:case XX_FILE_TYPE_NTLM_MESSAGE:case XX_FILE_TYPE_DCERPC_PDU:case XX_FILE_TYPE_MQTT_PACKETS:case XX_FILE_TYPE_AMQP_FRAMES:case XX_FILE_TYPE_WEBSOCKET_FRAMES:return true;default:return false;}
}
bool sxnm_need(sxnm_view *v,size_t at,uint64_t n,size_t end){return !xx_pd_is_stopped(v->c->pd)&&end<=v->n&&at<=end&&n<=end-at;}
uint16_t sxnm_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,true);}
uint32_t sxnm_u24(const uint8_t *p){return ((uint32_t)p[0]<<16)|((uint32_t)p[1]<<8)|p[2];}
uint32_t sxnm_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,true);}
bool sxnm_row(sxnm_view *v,const sx_layout *l,size_t at,size_t end)
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
bool sxnm_ip(sxnm_view *v,size_t at,size_t end)
{
 if(!sxnm_need(v,at,1,end))return false;unsigned ver=v->p[at]>>4;size_t udp;
 if(ver==4){if(!SN_ROW(ipv4_header,at,end))return false;size_t h=(v->p[at]&15)*4;if(h<20||!sxnm_need(v,at,h+8,end)||sxnm_u16(v->p+at+2)!=end-at||v->p[at+9]!=17)return false;udp=at+h;size_t o=at+20;
  while(o<udp){uint8_t type=v->p[o];if(type<2){if(!SN_ROW(ipv4_single_byte_option,o,udp))return false;o++;if(!type)break;}else{if(!SN_ROW(ipv4_option_header,o,udp))return false;unsigned n=v->p[o+1];if(n<2||!sxnm_need(v,o,n,udp))return false;o+=n;}}
 }else if(ver==6){if(!SN_ROW(ipv6_header,at,end)||sxnm_u16(v->p+at+4)!=end-at-40||v->p[at+6]!=17)return false;udp=at+40;}else return false;
 return SN_ROW(udp_header,udp,end)&&sxnm_u16(v->p+udp+4)==end-udp;
}
static bool sx_networkmeta_build(sx_context *c)
{
 if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>64*1024*1024||xx_pd_is_stopped(c->pd))return false;sxnm_view view={c,NULL,(size_t)c->size,0},*v=&view;v->p=xx_mem_alloc(v->n);if(!v->p)return false;bool ok=false;if(!sx_read(c,0,v->p,v->n))goto done;
 switch(c->f->file_type){
 case XX_FILE_TYPE_IP_PACKET:ok=sx_ip_packet_build(v);break;case XX_FILE_TYPE_ETHERNET_FRAME:ok=sx_ethernet_frame_build(v);break;case XX_FILE_TYPE_GTP_MESSAGE:ok=sx_gtp_message_build(v);break;case XX_FILE_TYPE_ICMP_MESSAGE:ok=sx_icmp_message_build(v);break;
 case XX_FILE_TYPE_BGP_MESSAGES:ok=sx_bgp_messages_build(v);break;case XX_FILE_TYPE_OSPF_PACKET:ok=sx_ospf_packet_build(v);break;case XX_FILE_TYPE_SCTP_PACKET:ok=sx_sctp_packet_build(v);break;case XX_FILE_TYPE_ISAKMP_MESSAGE:ok=sx_isakmp_message_build(v);break;case XX_FILE_TYPE_RTP_RTCP:ok=sx_rtp_rtcp_build(v);break;case XX_FILE_TYPE_TLS_RECORDS:ok=sx_tls_records_build(v);break;case XX_FILE_TYPE_DIAMETER_MESSAGE:ok=sx_diameter_message_build(v);break;case XX_FILE_TYPE_TACACS_PACKET:ok=sx_tacacs_packet_build(v);break;case XX_FILE_TYPE_PFCP_MESSAGE:ok=sx_pfcp_message_build(v);break;
 case XX_FILE_TYPE_PPTP_MESSAGE:ok=sx_pptp_message_build(v);break;case XX_FILE_TYPE_RSVP_MESSAGE:ok=sx_rsvp_message_build(v);break;
 case XX_FILE_TYPE_PIM_MESSAGE:ok=sx_pim_message_build(v);break;case XX_FILE_TYPE_LDP_MESSAGE:ok=sx_ldp_message_build(v);break;case XX_FILE_TYPE_GRE_PACKET:ok=sx_gre_packet_build(v);break;case XX_FILE_TYPE_L2TP_PACKET:ok=sx_l2tp_packet_build(v);break;case XX_FILE_TYPE_NETFLOW_DATAGRAM:ok=sx_netflow_datagram_build(v);break;case XX_FILE_TYPE_NTLM_MESSAGE:ok=sx_ntlm_message_build(v);break;case XX_FILE_TYPE_DDS_RTPS:ok=sx_dds_rtps_build(v);break;case XX_FILE_TYPE_DCERPC_PDU:ok=sx_dcerpc_pdu_build(v);break;case XX_FILE_TYPE_MQTT_PACKETS:ok=sx_mqtt_packets_build(v);break;case XX_FILE_TYPE_AMQP_FRAMES:ok=sx_amqp_frames_build(v);break;case XX_FILE_TYPE_WEBSOCKET_FRAMES:ok=sx_websocket_frames_build(v);break;default:break;
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
const sx_family sx_networkmeta_family={sx_networkmeta_supports,sx_networkmeta_build,sx_networkmeta_layouts,SX_COUNT(sx_networkmeta_layouts),sx_networkmeta_comment};
