/* SPDX-License-Identifier: MIT. Genuine physical metadata; see docs/data_struct_archivetransport_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivetransport.h"

static const sx_layout *const sx_archivetransport_layouts[]={
 &sxatp_dgca_chunk,
 &sxatp_dgca_iarc_prefix,
 &sxatp_dgca_iarc_clear_tail,
 &sxatp_dgca_stored_unit,
 &sxatp_dgca_compressed_unit,
 &sxatp_dgca_plane_unit,
 &sxatp_stuffitx_signature,
 &sxatp_stuffitx_element_flag,
 &sxatp_stuffitx_element_type_bit1,
 &sxatp_stuffitx_attribute_key_bit0,
 &sxatp_stuffitx_attribute_key_bit1,
 &sxatp_stuffitx_attribute_key_bit2,
 &sxatp_stuffitx_attribute_key_bit3,
 &sxatp_stuffitx_attribute_key_bit4,
 &sxatp_stuffitx_attribute_key_bit5,
 &sxatp_stuffitx_attribute_key_bit6,
 &sxatp_stuffitx_attribute_key_bit7,
 &sxatp_stuffitx_object_id_bit0,
 &sxatp_stuffitx_object_id_bit1,
 &sxatp_stuffitx_object_id_bit2,
 &sxatp_stuffitx_object_id_bit3,
 &sxatp_stuffitx_object_id_bit4,
 &sxatp_stuffitx_object_id_bit5,
 &sxatp_stuffitx_object_id_bit6,
 &sxatp_stuffitx_object_id_bit7,
 &sxatp_stuffitx_parent_id_bit0,
 &sxatp_stuffitx_parent_id_bit1,
 &sxatp_stuffitx_parent_id_bit2,
 &sxatp_stuffitx_parent_id_bit3,
 &sxatp_stuffitx_parent_id_bit4,
 &sxatp_stuffitx_parent_id_bit5,
 &sxatp_stuffitx_parent_id_bit6,
 &sxatp_stuffitx_parent_id_bit7,
 &sxatp_stuffitx_stream_id_bit0,
 &sxatp_stuffitx_stream_id_bit1,
 &sxatp_stuffitx_stream_id_bit2,
 &sxatp_stuffitx_stream_id_bit3,
 &sxatp_stuffitx_stream_id_bit4,
 &sxatp_stuffitx_stream_id_bit5,
 &sxatp_stuffitx_stream_id_bit6,
 &sxatp_stuffitx_stream_id_bit7,
 &sxatp_stuffitx_fork_index_bit0,
 &sxatp_stuffitx_fork_index_bit1,
 &sxatp_stuffitx_fork_index_bit2,
 &sxatp_stuffitx_fork_index_bit3,
 &sxatp_stuffitx_fork_index_bit4,
 &sxatp_stuffitx_fork_index_bit5,
 &sxatp_stuffitx_fork_index_bit6,
 &sxatp_stuffitx_fork_index_bit7,
 &sxatp_stuffitx_declared_size_bit0,
 &sxatp_stuffitx_declared_size_bit1,
 &sxatp_stuffitx_declared_size_bit2,
 &sxatp_stuffitx_declared_size_bit3,
 &sxatp_stuffitx_declared_size_bit4,
 &sxatp_stuffitx_declared_size_bit5,
 &sxatp_stuffitx_declared_size_bit6,
 &sxatp_stuffitx_declared_size_bit7,
 &sxatp_stuffitx_attribute_value_bit0,
 &sxatp_stuffitx_attribute_value_bit1,
 &sxatp_stuffitx_attribute_value_bit2,
 &sxatp_stuffitx_attribute_value_bit3,
 &sxatp_stuffitx_attribute_value_bit4,
 &sxatp_stuffitx_attribute_value_bit5,
 &sxatp_stuffitx_attribute_value_bit6,
 &sxatp_stuffitx_attribute_value_bit7,
 &sxatp_stuffitx_algorithm_key_bit0,
 &sxatp_stuffitx_algorithm_key_bit1,
 &sxatp_stuffitx_algorithm_key_bit2,
 &sxatp_stuffitx_algorithm_key_bit3,
 &sxatp_stuffitx_algorithm_key_bit4,
 &sxatp_stuffitx_algorithm_key_bit5,
 &sxatp_stuffitx_algorithm_key_bit6,
 &sxatp_stuffitx_algorithm_key_bit7,
 &sxatp_stuffitx_algorithm_value_bit0,
 &sxatp_stuffitx_algorithm_value_bit1,
 &sxatp_stuffitx_algorithm_value_bit2,
 &sxatp_stuffitx_algorithm_value_bit3,
 &sxatp_stuffitx_algorithm_value_bit4,
 &sxatp_stuffitx_algorithm_value_bit5,
 &sxatp_stuffitx_algorithm_value_bit6,
 &sxatp_stuffitx_algorithm_value_bit7,
 &sxatp_stuffitx_cipher_extra_bit0,
 &sxatp_stuffitx_cipher_extra_bit1,
 &sxatp_stuffitx_cipher_extra_bit2,
 &sxatp_stuffitx_cipher_extra_bit3,
 &sxatp_stuffitx_cipher_extra_bit4,
 &sxatp_stuffitx_cipher_extra_bit5,
 &sxatp_stuffitx_cipher_extra_bit6,
 &sxatp_stuffitx_cipher_extra_bit7,
 &sxatp_stuffitx_fork_type_bit0,
 &sxatp_stuffitx_fork_type_bit1,
 &sxatp_stuffitx_fork_type_bit2,
 &sxatp_stuffitx_fork_type_bit3,
 &sxatp_stuffitx_fork_type_bit4,
 &sxatp_stuffitx_fork_type_bit5,
 &sxatp_stuffitx_fork_type_bit6,
 &sxatp_stuffitx_fork_type_bit7,
 &sxatp_stuffitx_root_value_bit0,
 &sxatp_stuffitx_root_value_bit1,
 &sxatp_stuffitx_root_value_bit2,
 &sxatp_stuffitx_root_value_bit3,
 &sxatp_stuffitx_root_value_bit4,
 &sxatp_stuffitx_root_value_bit5,
 &sxatp_stuffitx_root_value_bit6,
 &sxatp_stuffitx_root_value_bit7,
 &sxatp_stuffitx_block_size_bit0,
 &sxatp_stuffitx_trailer_size_bit0,
 &sxatp_stuffitx_crc32,
 &sxatp_powerarc_header,
 &sxatp_powerarc_bzip2_stream,
 &sxatp_powerarc_bzip2_first_block,
 &sxatp_powerarc_bzip2_empty_end,
 &sxatp_binhex_banner,
 &sxatp_binhex_delimiter,
 &sxatp_binhex_encoded_run,
 &sxatp_transport_line_end,
 &sxatp_transport_whitespace,
 &sxatp_qp_literal_run,
 &sxatp_qp_hex_escape,
 &sxatp_qp_soft_break,
 &sxatp_qp_padding,
 &sxatp_shar_command,
 &sxatp_shar_redirection,
 &sxatp_shar_heredoc_operator,
 &sxatp_shar_delimiter,
 &sxatp_shar_name,
 &sxatp_shar_quoted_marker,
 &sxatp_shar_terminator,
 &sxatp_shar_prefix_expression,
 &sxatp_shar_uu_begin,
};
static bool sx_archivetransport_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60890000U||id>=0x608a0000U)return true;const wchar_t*text=NULL;switch(id){
 case 0x60890001U:text=L"Payload excludes padding; chunk payload is rounded up to16bytes. Header CRC32 zeros its own field, retaining payload CRC32.";break;
 case 0x60890002U:text=L"Flag1 encrypts bytes32..79 and DGCC headers/payloads. Unknown physical bytes are retained without invented semantics.";break;
 case 0x60890004U:text=L"Method0: exactly uncompressed_size stored bytes follow.";break;
 case 0x60890005U:text=L"Method1 entropy/LZP streams follow. BWT index is an index, not a file offset; high flags encode integration order.";break;
 case 0x60890006U:text=L"Method2: plane_count consecutive stored/compressed units; decoded bytes are interleaved.";break;
 case 0x60890008U:text=L"Physical first LSB of each byte-aligned element; native reader does not assign a semantic meaning.";break;
 case 0x60890009U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089000fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890010U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890011U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890012U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890013U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890014U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890015U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890016U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890017U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890018U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890019U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089001fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890020U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890021U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890022U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890023U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890024U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890025U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890026U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890027U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890028U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890029U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089002fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890030U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890031U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890032U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890033U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890034U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890035U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890036U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890037U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890038U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890039U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089003fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890040U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890041U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890042U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890043U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890044U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890045U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890046U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890047U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890048U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890049U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089004fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890050U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890051U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890052U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890053U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890054U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890055U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890056U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890057U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890058U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890059U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005cU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005dU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005eU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089005fU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890060U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890061U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890062U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890063U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890064U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890065U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890066U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890067U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890068U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x60890069U:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089006aU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089006bU:text=L"P2 integer: LSB-first unary one-count, then bits through that many ones, minus1. Original byte window is retained; adjacent bit fields may share its boundary bytes.";break;
 case 0x6089006cU:text=L"First4-byte trailing chunk: big-endian decoded-stream CRC32; stored value only.";break;
 case 0x6089006eU:text=L"ASCII digit1..9 encodes maximum block size in100000-byte units.";break;
 case 0x6089006fU:text=L"First data block physical prefix only. BWT original pointer is a row index. Later variable-bit blocks and Huffman payload remain raw.";break;
 case 0x60890072U:text=L"Colon separates physical HQX transport. Decoded RLE header/forks have no linear source-field offsets.";break;
 case 0x60890073U:text=L"Original HQX alphabet bytes; whitespace may split groups. No plaintext header/fork fields are assigned false positions.";break;
 case 0x60890074U:text=L"Original CR/LF physical separator bytes.";break;
 case 0x60890077U:text=L"RFC2045 hexadecimal escape. Displayed octet comes from its two original hex characters; it is not a file address.";break;
 case 0x60890078U:text=L"Equals plus physical CRLF/LF, or a final equals at EOF; contributes no decoded octet.";break;
 case 0x60890079U:text=L"Native-supported trailing NUL/SUB padding; not decoded text.";break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
bool sxatp_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxatp_read(sx_context*c,uint64_t p,void*b,size_t n){return sxatp_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
/* All coordinates are physical. Only documented byte aliases opt into overlap. */
bool sxatp_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){if(c->count>=SXATP_LIMIT||xx_pd_is_stopped(c->pd))return false;if(!n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];if(!f->size)return false;n=(uint64_t)(f->rel_offset+f->size);}if(!sxatp_span(c,p,n))return false;int64_t a=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<a)lo=m+1;else hi=m;}if(!aliases&&((lo<c->count&&c->items[lo].offset<a+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>a)))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxatp_add(sx_context*c,const sx_layout*l,uint64_t p){return sxatp_put(c,l,p,0,false);}
bool sxatp_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases){int64_t max=sx_variable_field_limit(l->fields[l->field_count-1].type);return !n||n>(uint64_t)(max?max:4096)?true:sxatp_put(c,l,p,n,aliases);}
static int sxatp_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxatp_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxatp_order);return !c->failed;}
static bool sxatp_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxatp_add(c,l,p+i*width))return false;return true;}
bool sxatp_space(uint8_t x){return x==' '||x=='\t'||x=='\r'||x=='\n';}
static bool sx_archivetransport_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_DGCA:case XX_FILE_TYPE_STUFFITX:case XX_FILE_TYPE_SHAR:case XX_FILE_TYPE_BINHEX:case XX_FILE_TYPE_QUOTED_PRINTABLE_ENCODED_FIL:case XX_FILE_TYPE_POWERARC:return true;default:return false;}}
static bool sx_archivetransport_build(sx_context*c){if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_DGCA:ok=sx_dgca_build(c);break;case XX_FILE_TYPE_STUFFITX:ok=sx_stuffitx_build(c);break;case XX_FILE_TYPE_SHAR:ok=sx_shar_build(c);break;case XX_FILE_TYPE_BINHEX:ok=sx_binhex_build(c);break;case XX_FILE_TYPE_QUOTED_PRINTABLE_ENCODED_FIL:ok=sx_quoted_printable_encoded_fil_build(c);break;case XX_FILE_TYPE_POWERARC:ok=sx_powerarc_build(c);break;default:return false;}(void)ok;return c->count&&sxatp_finish(c);}
const sx_family sx_archivetransport_family={sx_archivetransport_supports,sx_archivetransport_build,sx_archivetransport_layouts,SX_COUNT(sx_archivetransport_layouts),sx_archivetransport_comment};
