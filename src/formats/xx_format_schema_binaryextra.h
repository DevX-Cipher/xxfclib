/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The binaryextra schema family: what its family unit (xx_format_schema_binaryextra.c)
 * and its formats' data files share. Formats: CLP; lmd container; vice snapshot; mcap; windows registry hive; windows evtx; kafka record batch; capnproto message; adobe acb; kerberos keytab; kerberos ccache; jks keystore; gguf; NVP image/configuration container; LBRCOBOL; PYZ; PyInstaller CArchive; Starkit; Enigma Virtual Box filesystem; GTA IMG v2 archive; PAM PAK archive; PFPK archive. */
#ifndef XX_FORMAT_SCHEMA_BINARYEXTRA_H
#define XX_FORMAT_SCHEMA_BINARYEXTRA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxbx_clp_header;
extern const sx_layout sxbx_clp_record;
extern const sx_layout sxbx_lmd_header;
extern const sx_layout sxbx_lmd_record_offset;
extern const sx_layout sxbx_lmd_flags;
extern const sx_layout sxbx_lmd_name_length;
extern const sx_layout sxbx_lmd_optional_value;
extern const sx_layout sxbx_lmd_bitmap_size;
extern const sx_layout sxbx_lmd_block_header;
extern const sx_layout sxbx_vice_snapshot_header;
extern const sx_layout sxbx_vice_version_header;
extern const sx_layout sxbx_vice_module_header;
extern const sx_layout sxbx_mcap_magic;
extern const sx_layout sxbx_mcap_record_header;
extern const sx_layout sxbx_mcap_schema_id;
extern const sx_layout sxbx_mcap_channel_ids;
extern const sx_layout sxbx_mcap_message;
extern const sx_layout sxbx_mcap_attachment_times;
extern const sx_layout sxbx_mcap_footer;
extern const sx_layout sxbx_mcap_crc;
extern const sx_layout sxbx_mcap_map_size;
extern const sx_layout sxbx_mcap_string_size;
extern const sx_layout sxbx_mcap_data_size;
extern const sx_layout sxbx_mcap_attachment_size;
extern const sx_layout sxbx_regf_header;
extern const sx_layout sxbx_regf_checksum;
extern const sx_layout sxbx_regf_hbin;
extern const sx_layout sxbx_regf_cell;
extern const sx_layout sxbx_regf_nk;
extern const sx_layout sxbx_regf_sk;
extern const sx_layout sxbx_regf_list;
extern const sx_layout sxbx_regf_list_offset;
extern const sx_layout sxbx_regf_list_hash;
extern const sx_layout sxbx_regf_vk;
extern const sx_layout sxbx_regf_db;
extern const sx_layout sxbx_evtx_header;
extern const sx_layout sxbx_evtx_chunk;
extern const sx_layout sxbx_evtx_string_offset;
extern const sx_layout sxbx_evtx_template_offset;
extern const sx_layout sxbx_evtx_record;
extern const sx_layout sxbx_evtx_record_trailer;
extern const sx_layout sxbx_kafka_batch;
extern const sx_layout sxbx_kafka_attributes;
extern const sx_layout sxbx_kafka_record_size1;
extern const sx_layout sxbx_kafka_record_size2;
extern const sx_layout sxbx_kafka_record_size3;
extern const sx_layout sxbx_kafka_record_size4;
extern const sx_layout sxbx_kafka_record_size5;
extern const sx_layout sxbx_kafka_record_size6;
extern const sx_layout sxbx_kafka_record_size7;
extern const sx_layout sxbx_kafka_record_size8;
extern const sx_layout sxbx_kafka_record_size9;
extern const sx_layout sxbx_kafka_record_size10;
extern const sx_layout sxbx_kafka_timestamp_delta1;
extern const sx_layout sxbx_kafka_timestamp_delta2;
extern const sx_layout sxbx_kafka_timestamp_delta3;
extern const sx_layout sxbx_kafka_timestamp_delta4;
extern const sx_layout sxbx_kafka_timestamp_delta5;
extern const sx_layout sxbx_kafka_timestamp_delta6;
extern const sx_layout sxbx_kafka_timestamp_delta7;
extern const sx_layout sxbx_kafka_timestamp_delta8;
extern const sx_layout sxbx_kafka_timestamp_delta9;
extern const sx_layout sxbx_kafka_timestamp_delta10;
extern const sx_layout sxbx_kafka_offset_delta1;
extern const sx_layout sxbx_kafka_offset_delta2;
extern const sx_layout sxbx_kafka_offset_delta3;
extern const sx_layout sxbx_kafka_offset_delta4;
extern const sx_layout sxbx_kafka_offset_delta5;
extern const sx_layout sxbx_kafka_offset_delta6;
extern const sx_layout sxbx_kafka_offset_delta7;
extern const sx_layout sxbx_kafka_offset_delta8;
extern const sx_layout sxbx_kafka_offset_delta9;
extern const sx_layout sxbx_kafka_offset_delta10;
extern const sx_layout sxbx_kafka_nullable_size1;
extern const sx_layout sxbx_kafka_nullable_size2;
extern const sx_layout sxbx_kafka_nullable_size3;
extern const sx_layout sxbx_kafka_nullable_size4;
extern const sx_layout sxbx_kafka_nullable_size5;
extern const sx_layout sxbx_kafka_nullable_size6;
extern const sx_layout sxbx_kafka_nullable_size7;
extern const sx_layout sxbx_kafka_nullable_size8;
extern const sx_layout sxbx_kafka_nullable_size9;
extern const sx_layout sxbx_kafka_nullable_size10;
extern const sx_layout sxbx_kafka_header_count1;
extern const sx_layout sxbx_kafka_header_count2;
extern const sx_layout sxbx_kafka_header_count3;
extern const sx_layout sxbx_kafka_header_count4;
extern const sx_layout sxbx_kafka_header_count5;
extern const sx_layout sxbx_kafka_header_count6;
extern const sx_layout sxbx_kafka_header_count7;
extern const sx_layout sxbx_kafka_header_count8;
extern const sx_layout sxbx_kafka_header_count9;
extern const sx_layout sxbx_kafka_header_count10;
extern const sx_layout sxbx_kafka_header_key_size1;
extern const sx_layout sxbx_kafka_header_key_size2;
extern const sx_layout sxbx_kafka_header_key_size3;
extern const sx_layout sxbx_kafka_header_key_size4;
extern const sx_layout sxbx_kafka_header_key_size5;
extern const sx_layout sxbx_kafka_header_key_size6;
extern const sx_layout sxbx_kafka_header_key_size7;
extern const sx_layout sxbx_kafka_header_key_size8;
extern const sx_layout sxbx_kafka_header_key_size9;
extern const sx_layout sxbx_kafka_header_key_size10;
extern const sx_layout sxbx_capnp_segment_table;
extern const sx_layout sxbx_capnp_struct_pointer;
extern const sx_layout sxbx_capnp_list_pointer;
extern const sx_layout sxbx_capnp_composite_tag;
extern const sx_layout sxbx_capnp_null_pointer;
extern const sx_layout sxbx_acb_header;
extern const sx_layout sxbx_acb_string_length;
extern const sx_layout sxbx_acb_palette;
extern const sx_layout sxbx_acb_color_rgb;
extern const sx_layout sxbx_acb_color_cmyk;
extern const sx_layout sxbx_acb_color_lab;
extern const sx_layout sxbx_acb_trailer;
extern const sx_layout sxbx_keytab_header;
extern const sx_layout sxbx_keytab_entry_length;
extern const sx_layout sxbx_keytab_component_count;
extern const sx_layout sxbx_keytab_string_length;
extern const sx_layout sxbx_kerberos_name_type;
extern const sx_layout sxbx_keytab_key;
extern const sx_layout sxbx_keytab_extended_kvno;
extern const sx_layout sxbx_ccache_header;
extern const sx_layout sxbx_ccache_tag;
extern const sx_layout sxbx_ccache_time_offset;
extern const sx_layout sxbx_ccache_principal;
extern const sx_layout sxbx_ccache_blob_size;
extern const sx_layout sxbx_ccache_key;
extern const sx_layout sxbx_ccache_times_flags;
extern const sx_layout sxbx_ccache_list_count;
extern const sx_layout sxbx_ccache_typed_blob;
extern const sx_layout sxbx_jks_header;
extern const sx_layout sxbx_jks_entry_tag;
extern const sx_layout sxbx_jks_string_size;
extern const sx_layout sxbx_jks_timestamp;
extern const sx_layout sxbx_jks_blob_size;
extern const sx_layout sxbx_jks_certificate_count;
extern const sx_layout sxbx_jks_digest;
extern const sx_layout sxbx_gguf_header;
extern const sx_layout sxbx_gguf_string_size;
extern const sx_layout sxbx_gguf_value_type;
extern const sx_layout sxbx_gguf_array;
extern const sx_layout sxbx_gguf_value0;
extern const sx_layout sxbx_gguf_value1;
extern const sx_layout sxbx_gguf_value2;
extern const sx_layout sxbx_gguf_value3;
extern const sx_layout sxbx_gguf_value4;
extern const sx_layout sxbx_gguf_value5;
extern const sx_layout sxbx_gguf_value6;
extern const sx_layout sxbx_gguf_value7;
extern const sx_layout sxbx_gguf_value10;
extern const sx_layout sxbx_gguf_value11;
extern const sx_layout sxbx_gguf_value12;
extern const sx_layout sxbx_gguf_dimensions;
extern const sx_layout sxbx_gguf_dimension;
extern const sx_layout sxbx_gguf_tensor_storage;
extern const sx_layout sxbx_nvp_header;
extern const sx_layout sxbx_nvp_directory;
extern const sx_layout sxbx_nvp_record;
extern const sx_layout sxbx_nvp_jpeg_size;
extern const sx_layout sxbx_nvp_string_list;
extern const sx_layout sxbx_lbrcobol_title;
extern const sx_layout sxbx_lbrcobol_directory_header;
extern const sx_layout sxbx_lbrcobol_header_constants;
extern const sx_layout sxbx_lbrcobol_member;
extern const sx_layout sxbx_lbrcobol_member_tail;
extern const sx_layout sxbx_pyz_header_le;
extern const sx_layout sxbx_pyz_header_be;
extern const sx_layout sxbx_pyz_marshal_tag;
extern const sx_layout sxbx_pyz_marshal_int32;
extern const sx_layout sxbx_pyz_marshal_int64;
extern const sx_layout sxbx_pyz_marshal_length;
extern const sx_layout sxbx_pyz_marshal_count;
extern const sx_layout sxbx_pyz_marshal_short_count;
extern const sx_layout sxbx_pyz_marshal_short_length;
extern const sx_layout sxbx_pyz_marshal_reference;
extern const sx_layout sxbx_pyz_marshal_long_digits;
extern const sx_layout sxbx_pyz_marshal_digit;
extern const sx_layout sxbx_pyinstaller_cookie24;
extern const sx_layout sxbx_pyinstaller_library;
extern const sx_layout sxbx_pyinstaller_toc;
extern const sx_layout sxbx_starkit_header;
extern const sx_layout sxbx_starkit_commit;
extern const sx_layout sxbx_starkit_root_prefix;
extern const sx_layout sxbx_starkit_row_count1;
extern const sx_layout sxbx_starkit_row_count2;
extern const sx_layout sxbx_starkit_row_count3;
extern const sx_layout sxbx_starkit_row_count4;
extern const sx_layout sxbx_starkit_row_count5;
extern const sx_layout sxbx_starkit_row_count6;
extern const sx_layout sxbx_starkit_row_count7;
extern const sx_layout sxbx_starkit_row_count8;
extern const sx_layout sxbx_starkit_row_count9;
extern const sx_layout sxbx_starkit_column_size1;
extern const sx_layout sxbx_starkit_column_size2;
extern const sx_layout sxbx_starkit_column_size3;
extern const sx_layout sxbx_starkit_column_size4;
extern const sx_layout sxbx_starkit_column_size5;
extern const sx_layout sxbx_starkit_column_size6;
extern const sx_layout sxbx_starkit_column_size7;
extern const sx_layout sxbx_starkit_column_size8;
extern const sx_layout sxbx_starkit_column_size9;
extern const sx_layout sxbx_starkit_column_offset1;
extern const sx_layout sxbx_starkit_column_offset2;
extern const sx_layout sxbx_starkit_column_offset3;
extern const sx_layout sxbx_starkit_column_offset4;
extern const sx_layout sxbx_starkit_column_offset5;
extern const sx_layout sxbx_starkit_column_offset6;
extern const sx_layout sxbx_starkit_column_offset7;
extern const sx_layout sxbx_starkit_column_offset8;
extern const sx_layout sxbx_starkit_column_offset9;
extern const sx_layout sxbx_starkit_memo_row_delta1;
extern const sx_layout sxbx_starkit_memo_row_delta2;
extern const sx_layout sxbx_starkit_memo_row_delta3;
extern const sx_layout sxbx_starkit_memo_row_delta4;
extern const sx_layout sxbx_starkit_memo_row_delta5;
extern const sx_layout sxbx_starkit_memo_row_delta6;
extern const sx_layout sxbx_starkit_memo_row_delta7;
extern const sx_layout sxbx_starkit_memo_row_delta8;
extern const sx_layout sxbx_starkit_memo_row_delta9;
extern const sx_layout sxbx_starkit_view_tag1;
extern const sx_layout sxbx_starkit_view_tag2;
extern const sx_layout sxbx_starkit_view_tag3;
extern const sx_layout sxbx_starkit_view_tag4;
extern const sx_layout sxbx_starkit_view_tag5;
extern const sx_layout sxbx_starkit_view_tag6;
extern const sx_layout sxbx_starkit_view_tag7;
extern const sx_layout sxbx_starkit_view_tag8;
extern const sx_layout sxbx_starkit_view_tag9;
extern const sx_layout sxbx_evb_header;
extern const sx_layout sxbx_evb_table_prefix;
extern const sx_layout sxbx_evb_node;
extern const sx_layout sxbx_evb_node_type;
extern const sx_layout sxbx_evb_file_stored_size;
extern const sx_layout sxbx_gta_img_header;
extern const sx_layout sxbx_gta_img_entry;
extern const sx_layout sxbx_pam_pak_header;
extern const sx_layout sxbx_pam_pak_data;
extern const sx_layout sxbx_pam_pak_directory_marker;
extern const sx_layout sxbx_pam_pak_index;
extern const sx_layout sxbx_pfpk_header;
extern const sx_layout sxbx_pfpk_name_size;
extern const sx_layout sxbx_pfpk_member;
extern const sx_layout sxbx_pyz_marshal_offset32;
extern const sx_layout sxbx_pyz_marshal_size32;
extern const sx_layout sxbx_pyz_marshal_offset64;
extern const sx_layout sxbx_pyz_marshal_size64;
extern const sx_layout sxbx_evb_file_modern;
extern const sx_layout sxbx_evb_file_legacy;
extern const sx_layout sxbx_evb_chunk_header;
extern const sx_layout sxbx_evb_chunk_entry;
extern const sx_layout sxbx_evb_ap32;
bool sxbx_span(sx_context *c,uint64_t p,uint64_t n);
bool sxbx_read(sx_context *c,uint64_t p,void *b,size_t n);
uint64_t sxbx_uint(const uint8_t *b,unsigned n,bool be);
uint32_t sxbx32(const uint8_t *b,bool be);
bool sxbx_free(sx_context *c,uint64_t p,uint64_t n);
bool sxbx_add(sx_context *c,const sx_layout *l,uint64_t p);
bool sxbx_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n);
bool sxbx_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v);
bool sxbx_counted(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l,unsigned width,bool be,unsigned multiplier);
bool sxbx_zero_string(sx_context*c,uint64_t*p,uint64_t end,unsigned width);

/* Per-format walkers, called by the family's build. */
bool sx_clp_build(sx_context *c);  /* other/clp/xx_clp_data.c */
bool sx_lmd_container_build(sx_context *c);  /* other/lmd_container/xx_lmd_container_data.c */
bool sx_vice_snapshot_build(sx_context *c);  /* other/vice_snapshot/xx_vice_snapshot_data.c */
bool sx_mcap_build(sx_context *c);  /* other/mcap/xx_mcap_data.c */
bool sx_windows_registry_hive_build(sx_context *c);  /* other/windows_registry_hive/xx_windows_registry_hive_data.c */
bool sx_windows_evtx_build(sx_context *c);  /* other/windows_evtx/xx_windows_evtx_data.c */
bool sx_kafka_record_batch_build(sx_context *c);  /* other/kafka_record_batch/xx_kafka_record_batch_data.c */
bool sx_capnproto_message_build(sx_context *c);  /* other/capnproto_message/xx_capnproto_message_data.c */
bool sx_adobe_acb_build(sx_context *c);  /* other/adobe_acb/xx_adobe_acb_data.c */
bool sx_kerberos_keytab_build(sx_context *c);  /* other/kerberos_keytab/xx_kerberos_keytab_data.c */
bool sx_kerberos_ccache_build(sx_context *c);  /* other/kerberos_ccache/xx_kerberos_ccache_data.c */
bool sx_jks_keystore_build(sx_context *c);  /* other/jks_keystore/xx_jks_keystore_data.c */
bool sx_gguf_build(sx_context *c);  /* other/gguf/xx_gguf_data.c */
bool sx_nvp_build(sx_context *c);  /* other/nvp/xx_nvp_data.c */
bool sx_lbrcobol_build(sx_context *c);  /* executable/lbrcobol/xx_lbrcobol_data.c */
bool sx_pyz_build(sx_context *c);  /* executable/pyz/xx_pyz_data.c */
bool sx_pyinstaller_one_executable_build(sx_context *c);  /* executable/pyinstaller_one_executable/xx_pyinstaller_one_executable_data.c */
bool sx_starkit_build(sx_context *c);  /* executable/starkit/xx_starkit_data.c */
bool sx_enigma_virtual_box_build(sx_context *c);  /* executable/enigma_virtual_box/xx_enigma_virtual_box_data.c */
bool sx_gta_img_build(sx_context *c);  /* game/gta_img/xx_gta_img_data.c */
bool sx_pam_pak_build(sx_context *c);  /* game/pam_pak/xx_pam_pak_data.c */
bool sx_pfpk_build(sx_context *c);  /* game/pfpk/xx_pfpk_data.c */

#endif
