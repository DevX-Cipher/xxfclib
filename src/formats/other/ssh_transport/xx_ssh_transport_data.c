/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ssh transport data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdw_ssh_identification_fields[]={
 SX_FIELD("ssh_identification","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_identification={0x60740045U,"documentwire_ssh_identification",sxdw_ssh_identification_fields,SX_COUNT(sxdw_ssh_identification_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_packet_header_fields[]={
 SX_FIELD("packet_length","uint32be",0,4,SX_SIZE),
 SX_FIELD("padding_length","uint8",4,1,SX_SIZE),
 SX_FIELD("message_type","uint8",5,1,SX_ID),
};
const sx_layout sxdw_ssh_packet_header={0x60740046U,"documentwire_ssh_packet_header",sxdw_ssh_packet_header_fields,SX_COUNT(sxdw_ssh_packet_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_cookie_fields[]={
 SX_FIELD("cookie","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxdw_ssh_cookie={0x60740047U,"documentwire_ssh_cookie",sxdw_ssh_cookie_fields,SX_COUNT(sxdw_ssh_cookie_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_string_length_fields[]={
 SX_FIELD("byte_length","uint32be",0,4,SX_SIZE),
};
const sx_layout sxdw_ssh_string_length={0x60740048U,"documentwire_ssh_string_length",sxdw_ssh_string_length_fields,SX_COUNT(sxdw_ssh_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_kex_algorithms_fields[]={
 SX_FIELD("ssh_kex_algorithms","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_kex_algorithms={0x60740049U,"documentwire_ssh_kex_algorithms",sxdw_ssh_kex_algorithms_fields,SX_COUNT(sxdw_ssh_kex_algorithms_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_server_host_key_algorithms_fields[]={
 SX_FIELD("ssh_server_host_key_algorithms","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_server_host_key_algorithms={0x6074004aU,"documentwire_ssh_server_host_key_algorithms",sxdw_ssh_server_host_key_algorithms_fields,SX_COUNT(sxdw_ssh_server_host_key_algorithms_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_encryption_client_to_server_fields[]={
 SX_FIELD("ssh_encryption_client_to_server","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_encryption_client_to_server={0x6074004bU,"documentwire_ssh_encryption_client_to_server",sxdw_ssh_encryption_client_to_server_fields,SX_COUNT(sxdw_ssh_encryption_client_to_server_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_encryption_server_to_client_fields[]={
 SX_FIELD("ssh_encryption_server_to_client","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_encryption_server_to_client={0x6074004cU,"documentwire_ssh_encryption_server_to_client",sxdw_ssh_encryption_server_to_client_fields,SX_COUNT(sxdw_ssh_encryption_server_to_client_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_mac_client_to_server_fields[]={
 SX_FIELD("ssh_mac_client_to_server","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_mac_client_to_server={0x6074004dU,"documentwire_ssh_mac_client_to_server",sxdw_ssh_mac_client_to_server_fields,SX_COUNT(sxdw_ssh_mac_client_to_server_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_mac_server_to_client_fields[]={
 SX_FIELD("ssh_mac_server_to_client","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_mac_server_to_client={0x6074004eU,"documentwire_ssh_mac_server_to_client",sxdw_ssh_mac_server_to_client_fields,SX_COUNT(sxdw_ssh_mac_server_to_client_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_compression_client_to_server_fields[]={
 SX_FIELD("ssh_compression_client_to_server","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_compression_client_to_server={0x6074004fU,"documentwire_ssh_compression_client_to_server",sxdw_ssh_compression_client_to_server_fields,SX_COUNT(sxdw_ssh_compression_client_to_server_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_compression_server_to_client_fields[]={
 SX_FIELD("ssh_compression_server_to_client","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_compression_server_to_client={0x60740050U,"documentwire_ssh_compression_server_to_client",sxdw_ssh_compression_server_to_client_fields,SX_COUNT(sxdw_ssh_compression_server_to_client_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_languages_client_to_server_fields[]={
 SX_FIELD("ssh_languages_client_to_server","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_languages_client_to_server={0x60740051U,"documentwire_ssh_languages_client_to_server",sxdw_ssh_languages_client_to_server_fields,SX_COUNT(sxdw_ssh_languages_client_to_server_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_languages_server_to_client_fields[]={
 SX_FIELD("ssh_languages_server_to_client","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_ssh_languages_server_to_client={0x60740052U,"documentwire_ssh_languages_server_to_client",sxdw_ssh_languages_server_to_client_fields,SX_COUNT(sxdw_ssh_languages_server_to_client_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_ssh_kex_tail_fields[]={
 SX_FIELD("first_kex_packet_follows","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","uint32be",1,4,SX_RESERVED),
};
const sx_layout sxdw_ssh_kex_tail={0x60740053U,"documentwire_ssh_kex_tail",sxdw_ssh_kex_tail_fields,SX_COUNT(sxdw_ssh_kex_tail_fields),SX_LE};
static bool sxdw_ssh(sxdw_cursor*q)
{
 int64_t a,e;if(!sxdw_line(q,&a,&e)||!sxdw_value(q,&sxdw_ssh_identification,a,e-a))return false;
 const sx_layout*lists[]={&sxdw_ssh_kex_algorithms,&sxdw_ssh_server_host_key_algorithms,&sxdw_ssh_encryption_client_to_server,&sxdw_ssh_encryption_server_to_client,&sxdw_ssh_mac_client_to_server,&sxdw_ssh_mac_server_to_client,&sxdw_ssh_compression_client_to_server,&sxdw_ssh_compression_server_to_client,&sxdw_ssh_languages_client_to_server,&sxdw_ssh_languages_server_to_client};
 while(q->p<q->n&&q->c->count<32000){int64_t start=q->p;if(q->n-start<6)return false;uint64_t n=xx_data_get_u32(q->b+start,4,0,true);unsigned pad=q->b[start+4],type=q->b[start+5];if(n<2||pad>=n-1||n>(uint64_t)(q->n-start-4)||!sxdw_emit(q,&sxdw_ssh_packet_header,start,6))return false;
  int64_t end=start+4+(int64_t)n-pad;q->p=start+6;
  if(type==20){if(end-q->p<16||!sxdw_emit(q,&sxdw_ssh_cookie,q->p,16))return false;q->p+=16;
   for(unsigned i=0;i<10;i++){if(end-q->p<4)return false;uint32_t z=xx_data_get_u32(q->b+q->p,4,0,true);if(!sxdw_emit(q,&sxdw_ssh_string_length,q->p,4))return false;q->p+=4;if(z>(uint64_t)(end-q->p)||!sxdw_value(q,lists[i],q->p,z))return false;q->p+=z;}
   if(end-q->p!=5||!sxdw_emit(q,&sxdw_ssh_kex_tail,q->p,5))return false;
  }else if(type==30){if(end-q->p<4||!sxdw_emit(q,&sxdw_ssh_string_length,q->p,4))return false;}
  q->p=start+4+(int64_t)n;
 }return !xx_pd_is_stopped(q->c->pd);
}
bool sx_ssh_transport_build(sxdw_cursor*q)
{
 return sxdw_ssh(q);
}
