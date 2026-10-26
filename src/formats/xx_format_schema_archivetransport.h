/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivetransport schema family: what its family unit (xx_format_schema_archivetransport.c)
 * and its formats' data files share. Formats: DGCA; StuffIt X; shar; BinHex 4.0; Quoted-printable; PowerArc. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVETRANSPORT_H
#define XX_FORMAT_SCHEMA_ARCHIVETRANSPORT_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

#define SXATP_LIMIT 20000U

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxatp_dgca_chunk;
extern const sx_layout sxatp_dgca_iarc_prefix;
extern const sx_layout sxatp_dgca_iarc_clear_tail;
extern const sx_layout sxatp_dgca_stored_unit;
extern const sx_layout sxatp_dgca_compressed_unit;
extern const sx_layout sxatp_dgca_plane_unit;
extern const sx_layout sxatp_stuffitx_signature;
extern const sx_layout sxatp_stuffitx_element_flag;
extern const sx_layout sxatp_stuffitx_element_type_bit1;
extern const sx_layout sxatp_stuffitx_attribute_key_bit0;
extern const sx_layout sxatp_stuffitx_attribute_key_bit1;
extern const sx_layout sxatp_stuffitx_attribute_key_bit2;
extern const sx_layout sxatp_stuffitx_attribute_key_bit3;
extern const sx_layout sxatp_stuffitx_attribute_key_bit4;
extern const sx_layout sxatp_stuffitx_attribute_key_bit5;
extern const sx_layout sxatp_stuffitx_attribute_key_bit6;
extern const sx_layout sxatp_stuffitx_attribute_key_bit7;
extern const sx_layout sxatp_stuffitx_object_id_bit0;
extern const sx_layout sxatp_stuffitx_object_id_bit1;
extern const sx_layout sxatp_stuffitx_object_id_bit2;
extern const sx_layout sxatp_stuffitx_object_id_bit3;
extern const sx_layout sxatp_stuffitx_object_id_bit4;
extern const sx_layout sxatp_stuffitx_object_id_bit5;
extern const sx_layout sxatp_stuffitx_object_id_bit6;
extern const sx_layout sxatp_stuffitx_object_id_bit7;
extern const sx_layout sxatp_stuffitx_parent_id_bit0;
extern const sx_layout sxatp_stuffitx_parent_id_bit1;
extern const sx_layout sxatp_stuffitx_parent_id_bit2;
extern const sx_layout sxatp_stuffitx_parent_id_bit3;
extern const sx_layout sxatp_stuffitx_parent_id_bit4;
extern const sx_layout sxatp_stuffitx_parent_id_bit5;
extern const sx_layout sxatp_stuffitx_parent_id_bit6;
extern const sx_layout sxatp_stuffitx_parent_id_bit7;
extern const sx_layout sxatp_stuffitx_stream_id_bit0;
extern const sx_layout sxatp_stuffitx_stream_id_bit1;
extern const sx_layout sxatp_stuffitx_stream_id_bit2;
extern const sx_layout sxatp_stuffitx_stream_id_bit3;
extern const sx_layout sxatp_stuffitx_stream_id_bit4;
extern const sx_layout sxatp_stuffitx_stream_id_bit5;
extern const sx_layout sxatp_stuffitx_stream_id_bit6;
extern const sx_layout sxatp_stuffitx_stream_id_bit7;
extern const sx_layout sxatp_stuffitx_fork_index_bit0;
extern const sx_layout sxatp_stuffitx_fork_index_bit1;
extern const sx_layout sxatp_stuffitx_fork_index_bit2;
extern const sx_layout sxatp_stuffitx_fork_index_bit3;
extern const sx_layout sxatp_stuffitx_fork_index_bit4;
extern const sx_layout sxatp_stuffitx_fork_index_bit5;
extern const sx_layout sxatp_stuffitx_fork_index_bit6;
extern const sx_layout sxatp_stuffitx_fork_index_bit7;
extern const sx_layout sxatp_stuffitx_declared_size_bit0;
extern const sx_layout sxatp_stuffitx_declared_size_bit1;
extern const sx_layout sxatp_stuffitx_declared_size_bit2;
extern const sx_layout sxatp_stuffitx_declared_size_bit3;
extern const sx_layout sxatp_stuffitx_declared_size_bit4;
extern const sx_layout sxatp_stuffitx_declared_size_bit5;
extern const sx_layout sxatp_stuffitx_declared_size_bit6;
extern const sx_layout sxatp_stuffitx_declared_size_bit7;
extern const sx_layout sxatp_stuffitx_attribute_value_bit0;
extern const sx_layout sxatp_stuffitx_attribute_value_bit1;
extern const sx_layout sxatp_stuffitx_attribute_value_bit2;
extern const sx_layout sxatp_stuffitx_attribute_value_bit3;
extern const sx_layout sxatp_stuffitx_attribute_value_bit4;
extern const sx_layout sxatp_stuffitx_attribute_value_bit5;
extern const sx_layout sxatp_stuffitx_attribute_value_bit6;
extern const sx_layout sxatp_stuffitx_attribute_value_bit7;
extern const sx_layout sxatp_stuffitx_algorithm_key_bit0;
extern const sx_layout sxatp_stuffitx_algorithm_key_bit1;
extern const sx_layout sxatp_stuffitx_algorithm_key_bit2;
extern const sx_layout sxatp_stuffitx_algorithm_key_bit3;
extern const sx_layout sxatp_stuffitx_algorithm_key_bit4;
extern const sx_layout sxatp_stuffitx_algorithm_key_bit5;
extern const sx_layout sxatp_stuffitx_algorithm_key_bit6;
extern const sx_layout sxatp_stuffitx_algorithm_key_bit7;
extern const sx_layout sxatp_stuffitx_algorithm_value_bit0;
extern const sx_layout sxatp_stuffitx_algorithm_value_bit1;
extern const sx_layout sxatp_stuffitx_algorithm_value_bit2;
extern const sx_layout sxatp_stuffitx_algorithm_value_bit3;
extern const sx_layout sxatp_stuffitx_algorithm_value_bit4;
extern const sx_layout sxatp_stuffitx_algorithm_value_bit5;
extern const sx_layout sxatp_stuffitx_algorithm_value_bit6;
extern const sx_layout sxatp_stuffitx_algorithm_value_bit7;
extern const sx_layout sxatp_stuffitx_cipher_extra_bit0;
extern const sx_layout sxatp_stuffitx_cipher_extra_bit1;
extern const sx_layout sxatp_stuffitx_cipher_extra_bit2;
extern const sx_layout sxatp_stuffitx_cipher_extra_bit3;
extern const sx_layout sxatp_stuffitx_cipher_extra_bit4;
extern const sx_layout sxatp_stuffitx_cipher_extra_bit5;
extern const sx_layout sxatp_stuffitx_cipher_extra_bit6;
extern const sx_layout sxatp_stuffitx_cipher_extra_bit7;
extern const sx_layout sxatp_stuffitx_fork_type_bit0;
extern const sx_layout sxatp_stuffitx_fork_type_bit1;
extern const sx_layout sxatp_stuffitx_fork_type_bit2;
extern const sx_layout sxatp_stuffitx_fork_type_bit3;
extern const sx_layout sxatp_stuffitx_fork_type_bit4;
extern const sx_layout sxatp_stuffitx_fork_type_bit5;
extern const sx_layout sxatp_stuffitx_fork_type_bit6;
extern const sx_layout sxatp_stuffitx_fork_type_bit7;
extern const sx_layout sxatp_stuffitx_root_value_bit0;
extern const sx_layout sxatp_stuffitx_root_value_bit1;
extern const sx_layout sxatp_stuffitx_root_value_bit2;
extern const sx_layout sxatp_stuffitx_root_value_bit3;
extern const sx_layout sxatp_stuffitx_root_value_bit4;
extern const sx_layout sxatp_stuffitx_root_value_bit5;
extern const sx_layout sxatp_stuffitx_root_value_bit6;
extern const sx_layout sxatp_stuffitx_root_value_bit7;
extern const sx_layout sxatp_stuffitx_block_size_bit0;
extern const sx_layout sxatp_stuffitx_trailer_size_bit0;
extern const sx_layout sxatp_stuffitx_crc32;
extern const sx_layout sxatp_powerarc_header;
extern const sx_layout sxatp_powerarc_bzip2_stream;
extern const sx_layout sxatp_powerarc_bzip2_first_block;
extern const sx_layout sxatp_powerarc_bzip2_empty_end;
extern const sx_layout sxatp_binhex_banner;
extern const sx_layout sxatp_binhex_delimiter;
extern const sx_layout sxatp_binhex_encoded_run;
extern const sx_layout sxatp_transport_line_end;
extern const sx_layout sxatp_transport_whitespace;
extern const sx_layout sxatp_qp_literal_run;
extern const sx_layout sxatp_qp_hex_escape;
extern const sx_layout sxatp_qp_soft_break;
extern const sx_layout sxatp_qp_padding;
extern const sx_layout sxatp_shar_command;
extern const sx_layout sxatp_shar_redirection;
extern const sx_layout sxatp_shar_heredoc_operator;
extern const sx_layout sxatp_shar_delimiter;
extern const sx_layout sxatp_shar_name;
extern const sx_layout sxatp_shar_quoted_marker;
extern const sx_layout sxatp_shar_terminator;
extern const sx_layout sxatp_shar_prefix_expression;
extern const sx_layout sxatp_shar_uu_begin;
bool sxatp_span(sx_context*c,uint64_t p,uint64_t n);
bool sxatp_read(sx_context*c,uint64_t p,void*b,size_t n);
bool sxatp_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxatp_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxatp_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxatp_space(uint8_t x);

/* Per-format walkers, called by the family's build. */
bool sx_dgca_build(sx_context *c);  /* archive/dgca/xx_dgca_data.c */
bool sx_stuffitx_build(sx_context *c);  /* archive/stuffitx/xx_stuffitx_data.c */
bool sx_shar_build(sx_context *c);  /* archive/shar/xx_shar_data.c */
bool sx_binhex_build(sx_context *c);  /* archive/binhex/xx_binhex_data.c */
bool sx_quoted_printable_encoded_fil_build(sx_context *c);  /* archive/quoted_printable_encoded_fil/xx_quoted_printable_encoded_fil_data.c */
bool sx_powerarc_build(sx_context *c);  /* archive/powerarc/xx_powerarc_data.c */

#endif
