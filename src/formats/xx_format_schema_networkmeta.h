/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The networkmeta schema family: what its family unit (xx_format_schema_networkmeta.c)
 * and its formats' data files share. Formats: IP PACKET; ETHERNET FRAME; GTP MESSAGE; ICMP MESSAGE; BGP MESSAGES; OSPF PACKET; SCTP PACKET; ISAKMP MESSAGE; RTP RTCP; TLS RECORDS; DIAMETER MESSAGE; TACACS PACKET; PFCP MESSAGE; PPTP MESSAGE; RSVP MESSAGE; PIM MESSAGE; LDP MESSAGE; GRE PACKET; L2TP PACKET; NETFLOW DATAGRAM; NTLM MESSAGE; DDS RTPS; DCERPC PDU; MQTT PACKETS; AMQP FRAMES; WEBSOCKET FRAMES. */
#ifndef XX_FORMAT_SCHEMA_NETWORKMETA_H
#define XX_FORMAT_SCHEMA_NETWORKMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Native readers establish protocol validity. This walker independently bounds
 * every physical subrecord before classification; payload bytes remain raw. */
typedef struct sxnm_view {sx_context *c;uint8_t *p;size_t n;unsigned work;}sxnm_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxnm_ethernet_header;
extern const sx_layout sxnm_icmp_echo_header;
extern const sx_layout sxnm_bgp_message_header;
extern const sx_layout sxnm_bgp_open;
extern const sx_layout sxnm_bgp_optional_parameter;
extern const sx_layout sxnm_bgp_capability_header;
extern const sx_layout sxnm_ospfv2_header;
extern const sx_layout sxnm_ospfv2_hello;
extern const sx_layout sxnm_ospfv2_neighbor;
extern const sx_layout sxnm_sctp_common_header;
extern const sx_layout sxnm_sctp_data_chunk;
extern const sx_layout sxnm_isakmp_header;
extern const sx_layout sxnm_isakmp_sa_payload;
extern const sx_layout sxnm_isakmp_proposal;
extern const sx_layout sxnm_isakmp_transform;
extern const sx_layout sxnm_isakmp_basic_attribute;
extern const sx_layout sxnm_isakmp_variable_attribute;
extern const sx_layout sxnm_rtp_header;
extern const sx_layout sxnm_rtp_csrc;
extern const sx_layout sxnm_rtp_extension_header;
extern const sx_layout sxnm_rtp_padding_count;
extern const sx_layout sxnm_rtcp_header;
extern const sx_layout sxnm_rtcp_sender_info;
extern const sx_layout sxnm_rtcp_receiver_info;
extern const sx_layout sxnm_rtcp_report_block;
extern const sx_layout sxnm_rtcp_source;
extern const sx_layout sxnm_rtcp_sdes_item;
extern const sx_layout sxnm_rtcp_sdes_end;
extern const sx_layout sxnm_rtcp_bye_reason;
extern const sx_layout sxnm_rtcp_app_header;
extern const sx_layout sxnm_tls_record_header;
extern const sx_layout sxnm_tls_handshake_header;
extern const sx_layout sxnm_tls_hello_prefix;
extern const sx_layout sxnm_tls_session_id_length;
extern const sx_layout sxnm_tls_cipher_suites_length;
extern const sx_layout sxnm_tls_cipher_suite;
extern const sx_layout sxnm_tls_compression_methods_length;
extern const sx_layout sxnm_tls_compression_method;
extern const sx_layout sxnm_tls_extensions_length;
extern const sx_layout sxnm_tls_extension_header;
extern const sx_layout sxnm_tls_change_cipher_spec;
extern const sx_layout sxnm_diameter_header;
extern const sx_layout sxnm_diameter_avp_header;
extern const sx_layout sxnm_diameter_address_family;
extern const sx_layout sxnm_diameter_vendor_id;
extern const sx_layout sxnm_tacacs_header;
extern const sx_layout sxnm_tacacs_authentication_start;
extern const sx_layout sxnm_gtpv1_header;
extern const sx_layout sxnm_pfcp_node_header;
extern const sx_layout sxnm_pfcp_information_element;
extern const sx_layout sxnm_pfcp_node_id_type;
extern const sx_layout sxnm_pfcp_node_ipv4;
extern const sx_layout sxnm_pfcp_node_ipv6;
extern const sx_layout sxnm_pfcp_dns_label;
extern const sx_layout sxnm_pfcp_recovery_time;
extern const sx_layout sxnm_pptp_control_header;
extern const sx_layout sxnm_pptp_start_control_connection;
extern const sx_layout sxnm_rsvp_header;
extern const sx_layout sxnm_rsvp_object_header;
extern const sx_layout sxnm_rsvp_hello_instances;
extern const sx_layout sxnm_pim_header;
extern const sx_layout sxnm_pim_option_header;
extern const sx_layout sxnm_pim_holdtime;
extern const sx_layout sxnm_pim_lan_prune_delay;
extern const sx_layout sxnm_pim_dr_priority;
extern const sx_layout sxnm_pim_generation_id;
extern const sx_layout sxnm_ldp_pdu_header;
extern const sx_layout sxnm_ldp_message_header;
extern const sx_layout sxnm_ldp_tlv_header;
extern const sx_layout sxnm_ldp_common_hello;
extern const sx_layout sxnm_ldp_ipv4_transport;
extern const sx_layout sxnm_ldp_configuration_sequence;
extern const sx_layout sxnm_gre_header;
extern const sx_layout sxnm_gre_checksum;
extern const sx_layout sxnm_gre_key;
extern const sx_layout sxnm_gre_sequence;
extern const sx_layout sxnm_l2tp_control_header;
extern const sx_layout sxnm_l2tp_avp_header;
extern const sx_layout sxnm_l2tp_message_type;
extern const sx_layout sxnm_l2tp_protocol_version;
extern const sx_layout sxnm_l2tp_firmware_revision;
extern const sx_layout sxnm_l2tp_assigned_tunnel;
extern const sx_layout sxnm_l2tp_receive_window;
extern const sx_layout sxnm_l2tp_framing_capabilities;
extern const sx_layout sxnm_l2tp_bearer_capabilities;
extern const sx_layout sxnm_netflow_v5_header;
extern const sx_layout sxnm_netflow_v5_record;
extern const sx_layout sxnm_ntlm_negotiate;
extern const sx_layout sxnm_ntlm_version;
extern const sx_layout sxnm_rtps_header;
extern const sx_layout sxnm_rtps_submessage_le;
extern const sx_layout sxnm_rtps_timestamp_le;
extern const sx_layout sxnm_rtps_heartbeat_le;
extern const sx_layout sxnm_rtps_data_le;
extern const sx_layout sxnm_dcerpc_header_le;
extern const sx_layout sxnm_dcerpc_bind_le;
extern const sx_layout sxnm_dcerpc_context_le;
extern const sx_layout sxnm_dcerpc_transfer_syntax_le;
extern const sx_layout sxnm_dcerpc_request_le;
extern const sx_layout sxnm_dcerpc_response_le;
extern const sx_layout sxnm_rtps_submessage_be;
extern const sx_layout sxnm_rtps_timestamp_be;
extern const sx_layout sxnm_rtps_heartbeat_be;
extern const sx_layout sxnm_rtps_data_be;
extern const sx_layout sxnm_dcerpc_header_be;
extern const sx_layout sxnm_dcerpc_bind_be;
extern const sx_layout sxnm_dcerpc_context_be;
extern const sx_layout sxnm_dcerpc_transfer_syntax_be;
extern const sx_layout sxnm_dcerpc_request_be;
extern const sx_layout sxnm_dcerpc_response_be;
extern const sx_layout sxnm_rtps_destination;
extern const sx_layout sxnm_rtps_cdr_encapsulation;
extern const sx_layout sxnm_mqtt_control_byte;
extern const sx_layout sxnm_mqtt_remaining_length_1;
extern const sx_layout sxnm_mqtt_remaining_length_2;
extern const sx_layout sxnm_mqtt_remaining_length_3;
extern const sx_layout sxnm_mqtt_remaining_length_4;
extern const sx_layout sxnm_mqtt_connect;
extern const sx_layout sxnm_mqtt_string_length;
extern const sx_layout sxnm_mqtt_connack;
extern const sx_layout sxnm_mqtt_packet_id;
extern const sx_layout sxnm_mqtt_requested_qos;
extern const sx_layout sxnm_mqtt_suback_result;
extern const sx_layout sxnm_amqp_protocol_header;
extern const sx_layout sxnm_amqp_frame_header;
extern const sx_layout sxnm_amqp_method_header;
extern const sx_layout sxnm_amqp_content_header;
extern const sx_layout sxnm_amqp_frame_end;
extern const sx_layout sxnm_amqp_publish_prefix;
extern const sx_layout sxnm_amqp_publish_flags;
extern const sx_layout sxnm_amqp_close_code;
extern const sx_layout sxnm_amqp_close_method;
extern const sx_layout sxnm_amqp_short_string;
extern const sx_layout sxnm_amqp_table_length;
extern const sx_layout sxnm_amqp_field_type;
extern const sx_layout sxnm_amqp_uint8;
extern const sx_layout sxnm_amqp_int8;
extern const sx_layout sxnm_amqp_uint16;
extern const sx_layout sxnm_amqp_int16;
extern const sx_layout sxnm_amqp_uint32;
extern const sx_layout sxnm_amqp_int32;
extern const sx_layout sxnm_amqp_uint64;
extern const sx_layout sxnm_amqp_int64;
extern const sx_layout sxnm_amqp_boolean;
extern const sx_layout sxnm_amqp_float_bits;
extern const sx_layout sxnm_amqp_double_bits;
extern const sx_layout sxnm_amqp_decimal;
extern const sx_layout sxnm_amqp_timestamp;
extern const sx_layout sxnm_amqp_long_string;
extern const sx_layout sxnm_amqp_delivery_mode;
extern const sx_layout sxnm_amqp_priority;
extern const sx_layout sxnm_websocket_frame_header;
extern const sx_layout sxnm_websocket_length16;
extern const sx_layout sxnm_websocket_length64;
extern const sx_layout sxnm_websocket_mask;
extern const sx_layout sxnm_websocket_close_code;
bool sxnm_need(sxnm_view *v,size_t at,uint64_t n,size_t end);
uint16_t sxnm_u16(const uint8_t *p);
uint32_t sxnm_u24(const uint8_t *p);
uint32_t sxnm_u32(const uint8_t *p);
bool sxnm_row(sxnm_view *v,const sx_layout *l,size_t at,size_t end);
bool sxnm_ip(sxnm_view *v,size_t at,size_t end);

/* Per-format walkers, called by the family's build. */
bool sx_ip_packet_build(sxnm_view*v);  /* other/ip_packet/xx_ip_packet_data.c */
bool sx_ethernet_frame_build(sxnm_view*v);  /* other/ethernet_frame/xx_ethernet_frame_data.c */
bool sx_gtp_message_build(sxnm_view*v);  /* other/gtp_message/xx_gtp_message_data.c */
bool sx_icmp_message_build(sxnm_view*v);  /* other/icmp_message/xx_icmp_message_data.c */
bool sx_bgp_messages_build(sxnm_view*v);  /* other/bgp_messages/xx_bgp_messages_data.c */
bool sx_ospf_packet_build(sxnm_view*v);  /* other/ospf_packet/xx_ospf_packet_data.c */
bool sx_sctp_packet_build(sxnm_view*v);  /* other/sctp_packet/xx_sctp_packet_data.c */
bool sx_isakmp_message_build(sxnm_view*v);  /* other/isakmp_message/xx_isakmp_message_data.c */
bool sx_rtp_rtcp_build(sxnm_view*v);  /* other/rtp_rtcp/xx_rtp_rtcp_data.c */
bool sx_tls_records_build(sxnm_view*v);  /* other/tls_records/xx_tls_records_data.c */
bool sx_diameter_message_build(sxnm_view*v);  /* other/diameter_message/xx_diameter_message_data.c */
bool sx_tacacs_packet_build(sxnm_view*v);  /* other/tacacs_packet/xx_tacacs_packet_data.c */
bool sx_pfcp_message_build(sxnm_view*v);  /* other/pfcp_message/xx_pfcp_message_data.c */
bool sx_pptp_message_build(sxnm_view*v);  /* other/pptp_message/xx_pptp_message_data.c */
bool sx_rsvp_message_build(sxnm_view*v);  /* other/rsvp_message/xx_rsvp_message_data.c */
bool sx_pim_message_build(sxnm_view*v);  /* other/pim_message/xx_pim_message_data.c */
bool sx_ldp_message_build(sxnm_view*v);  /* other/ldp_message/xx_ldp_message_data.c */
bool sx_gre_packet_build(sxnm_view*v);  /* other/gre_packet/xx_gre_packet_data.c */
bool sx_l2tp_packet_build(sxnm_view*v);  /* other/l2tp_packet/xx_l2tp_packet_data.c */
bool sx_netflow_datagram_build(sxnm_view*v);  /* other/netflow_datagram/xx_netflow_datagram_data.c */
bool sx_ntlm_message_build(sxnm_view*v);  /* other/ntlm_message/xx_ntlm_message_data.c */
bool sx_dds_rtps_build(sxnm_view*v);  /* other/dds_rtps/xx_dds_rtps_data.c */
bool sx_dcerpc_pdu_build(sxnm_view*v);  /* other/dcerpc_pdu/xx_dcerpc_pdu_data.c */
bool sx_mqtt_packets_build(sxnm_view*v);  /* other/mqtt_packets/xx_mqtt_packets_data.c */
bool sx_amqp_frames_build(sxnm_view*v);  /* other/amqp_frames/xx_amqp_frames_data.c */
bool sx_websocket_frames_build(sxnm_view*v);  /* other/websocket_frames/xx_websocket_frames_data.c */

#endif
