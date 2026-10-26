/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The documentwire schema family: what its family unit (xx_format_schema_documentwire.c)
 * and its formats' data files share. Formats: MathCAD; Radare project; FRONTPAGETHEME; ELM; NoteTab; pjl; hp3000 wrq; snmp message; ldap message; ssh transport; Text; MIME email / HTML archive. */
#ifndef XX_FORMAT_SCHEMA_DOCUMENTWIRE_H
#define XX_FORMAT_SCHEMA_DOCUMENTWIRE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

typedef struct sxdw_cursor{sx_context*c;uint8_t*b;int64_t n,p;}sxdw_cursor;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxdw_mathcad_header;
extern const sx_layout sxdw_mathcad_literal_bit0;
extern const sx_layout sxdw_mathcad_match_bit0;
extern const sx_layout sxdw_mathcad_end_bit0;
extern const sx_layout sxdw_mathcad_literal_bit1;
extern const sx_layout sxdw_mathcad_match_bit1;
extern const sx_layout sxdw_mathcad_end_bit1;
extern const sx_layout sxdw_mathcad_literal_bit2;
extern const sx_layout sxdw_mathcad_match_bit2;
extern const sx_layout sxdw_mathcad_end_bit2;
extern const sx_layout sxdw_mathcad_literal_bit3;
extern const sx_layout sxdw_mathcad_match_bit3;
extern const sx_layout sxdw_mathcad_end_bit3;
extern const sx_layout sxdw_mathcad_literal_bit4;
extern const sx_layout sxdw_mathcad_match_bit4;
extern const sx_layout sxdw_mathcad_end_bit4;
extern const sx_layout sxdw_mathcad_literal_bit5;
extern const sx_layout sxdw_mathcad_match_bit5;
extern const sx_layout sxdw_mathcad_end_bit5;
extern const sx_layout sxdw_mathcad_literal_bit6;
extern const sx_layout sxdw_mathcad_match_bit6;
extern const sx_layout sxdw_mathcad_end_bit6;
extern const sx_layout sxdw_mathcad_literal_bit7;
extern const sx_layout sxdw_mathcad_match_bit7;
extern const sx_layout sxdw_mathcad_end_bit7;
extern const sx_layout sxdw_rprj_header;
extern const sx_layout sxdw_notetab_option;
extern const sx_layout sxdw_notetab_heading;
extern const sx_layout sxdw_notetab_body_line;
extern const sx_layout sxdw_pjl_command;
extern const sx_layout sxdw_pjl_parameter;
extern const sx_layout sxdw_pjl_value;
extern const sx_layout sxdw_pjl_text;
extern const sx_layout sxdw_wrq_record_size;
extern const sx_layout sxdw_wrq_block_factor;
extern const sx_layout sxdw_wrq_file_code;
extern const sx_layout sxdw_wrq_extents;
extern const sx_layout sxdw_wrq_record_count;
extern const sx_layout sxdw_notetab_declaration;
extern const sx_layout sxdw_pjl_uel;
extern const sx_layout sxdw_wrq_format;
extern const sx_layout sxdw_ssh_identification;
extern const sx_layout sxdw_ssh_packet_header;
extern const sx_layout sxdw_ssh_cookie;
extern const sx_layout sxdw_ssh_string_length;
extern const sx_layout sxdw_ssh_kex_algorithms;
extern const sx_layout sxdw_ssh_server_host_key_algorithms;
extern const sx_layout sxdw_ssh_encryption_client_to_server;
extern const sx_layout sxdw_ssh_encryption_server_to_client;
extern const sx_layout sxdw_ssh_mac_client_to_server;
extern const sx_layout sxdw_ssh_mac_server_to_client;
extern const sx_layout sxdw_ssh_compression_client_to_server;
extern const sx_layout sxdw_ssh_compression_server_to_client;
extern const sx_layout sxdw_ssh_languages_client_to_server;
extern const sx_layout sxdw_ssh_languages_server_to_client;
extern const sx_layout sxdw_ssh_kex_tail;
extern const sx_layout sxdw_text_bom2;
extern const sx_layout sxdw_text_bom3;
extern const sx_layout sxdw_text_bom4;
extern const sx_layout sxdw_text_utf16le;
extern const sx_layout sxdw_text_utf16be;
extern const sx_layout sxdw_text_utf32le;
extern const sx_layout sxdw_text_utf32be;
extern const sx_layout sxdw_text_line;
extern const sx_layout sxdw_mime_field_name;
extern const sx_layout sxdw_mime_field_value;
extern const sx_layout sxdw_mime_continuation;
extern const sx_layout sxdw_mime_boundary;
bool sxdw_emit(sxdw_cursor*q,const sx_layout*l,int64_t at,int64_t n);
bool sxdw_value(sxdw_cursor*q,const sx_layout*l,int64_t at,int64_t n);
bool sxdw_line(sxdw_cursor*q,int64_t*start,int64_t*end);
bool sxdw_decimal(sxdw_cursor*q,int64_t at,int64_t end,uint64_t*v);
bool sxdw_prefix(sxdw_cursor*q,int64_t at,int64_t end,const char*text);
bool sxdw_theme(sxdw_cursor*q,bool elm);
bool sxdw_ber(sxdw_cursor*q,int64_t p,int64_t end,unsigned depth);

/* Per-format walkers, called by the family's build. */
bool sx_mathcad_build(sxdw_cursor*q);  /* document/mathcad/xx_mathcad_data.c */
bool sx_rprj_build(sxdw_cursor*q);  /* other/rprj/xx_rprj_data.c */
bool sx_frontpagetheme_build(sxdw_cursor*q);  /* document/frontpagetheme/xx_frontpagetheme_data.c */
bool sx_elm_build(sxdw_cursor*q);  /* other/elm/xx_elm_data.c */
bool sx_notetab_build(sxdw_cursor*q);  /* document/notetab/xx_notetab_data.c */
bool sx_pjl_build(sxdw_cursor*q);  /* document/pjl/xx_pjl_data.c */
bool sx_hp3000_wrq_build(sxdw_cursor*q);  /* other/hp3000_wrq/xx_hp3000_wrq_data.c */
bool sx_snmp_message_build(sxdw_cursor*q);  /* other/snmp_message/xx_snmp_message_data.c */
bool sx_ldap_message_build(sxdw_cursor*q);  /* other/ldap_message/xx_ldap_message_data.c */
bool sx_ssh_transport_build(sxdw_cursor*q);  /* other/ssh_transport/xx_ssh_transport_data.c */
bool sx_text_build(sxdw_cursor*q);  /* document/text/xx_text_data.c */
bool sx_ue2_documents_mime_build(sxdw_cursor*q);  /* document/ue2_documents/xx_ue2_documents_mime_data.c */

#endif
