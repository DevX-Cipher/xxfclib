/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archiveremaining schema family: what its family unit (xx_format_schema_archiveremaining.c)
 * and its formats' data files share. Formats: WARC; PCOMM OS/2; btoa / Ascii85; UUE; BinSCII; yEnc; BALZ; bzip 0.21 (bzip1); Freeze 2; Dolphin RVZ; SCUMM SOU; Humongous TLKB. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEREMAINING_H
#define XX_FORMAT_SCHEMA_ARCHIVEREMAINING_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

#ifdef XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM
#define SXARM_CHECKSUM XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM
#endif
#define SXARM_LIMIT 20000U

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxarm_warc_version;
extern const sx_layout sxarm_warc_field_name;
extern const sx_layout sxarm_warc_field_value;
extern const sx_layout sxarm_warc_content_length;
extern const sx_layout sxarm_warc_segment_number;
extern const sx_layout sxarm_warc_segment_total_length;
extern const sx_layout sxarm_warc_digest;
extern const sx_layout sxarm_transport_filename;
extern const sx_layout sxarm_transport_decimal_size;
extern const sx_layout sxarm_transport_hex_size;
extern const sx_layout sxarm_transport_crc;
extern const sx_layout sxarm_transport_attribute_name;
extern const sx_layout sxarm_transport_attribute_value;
extern const sx_layout sxarm_yenc_line_width;
extern const sx_layout sxarm_yenc_part_number;
extern const sx_layout sxarm_yenc_total_parts;
extern const sx_layout sxarm_yenc_begin_position;
extern const sx_layout sxarm_yenc_end_position;
extern const sx_layout sxarm_btoa_line_width;
extern const sx_layout sxarm_pcomm_literal;
extern const sx_layout sxarm_pcomm_near_match;
extern const sx_layout sxarm_pcomm_far_match;
extern const sx_layout sxarm_pcomm_block_end;
extern const sx_layout sxarm_balz_header;
extern const sx_layout sxarm_bzip1_header;
extern const sx_layout sxarm_freeze2_header;
extern const sx_layout sxarm_he_tlkb_chunk;
extern const sx_layout sxarm_sou_header;
extern const sx_layout sxarm_sou_chunk;
extern const sx_layout sxarm_sou_mouth_sync;
extern const sx_layout sxarm_sou_voc_header;
extern const sx_layout sxarm_sou_voc_block;
extern const sx_layout sxarm_sou_voc_end;
extern const sx_layout sxarm_sou_voc_sound;
extern const sx_layout sxarm_sou_voc_silence;
extern const sx_layout sxarm_sou_voc_marker;
extern const sx_layout sxarm_sou_voc_repeat;
extern const sx_layout sxarm_sou_voc_extended;
extern const sx_layout sxarm_sou_voc_new_sound;
extern const sx_layout sxarm_rvz_file_header;
extern const sx_layout sxarm_rvz_disc_header;
extern const sx_layout sxarm_rvz_raw_entry;
extern const sx_layout sxarm_rvz_group_entry;
extern const sx_layout sxarm_rvz_packing_run;
extern const sx_layout sxarm_rvz_prng_seed;
extern const sx_layout sxarm_binscii_signature;
extern const sx_layout sxarm_binscii_alphabet;
extern const sx_layout sxarm_binscii_header;
extern const sx_layout sxarm_binscii_data_crc;
extern const sx_layout sxarm_uue_begin;
extern const sx_layout sxarm_uue_mode_1;
extern const sx_layout sxarm_uue_mode_2;
extern const sx_layout sxarm_uue_mode_3;
extern const sx_layout sxarm_uue_mode_4;
extern const sx_layout sxarm_uue_mode_5;
extern const sx_layout sxarm_uue_mode_6;
extern const sx_layout sxarm_uue_line;
extern const sx_layout sxarm_uue_end;
extern const sx_layout sxarm_yenc_begin;
extern const sx_layout sxarm_yenc_part;
extern const sx_layout sxarm_yenc_end;
extern const sx_layout sxarm_btoa_begin;
extern const sx_layout sxarm_btoa5_begin;
extern const sx_layout sxarm_btoa_end;
extern const sx_layout sxarm_ascii85_begin;
extern const sx_layout sxarm_ascii85_end;
extern const sx_layout sxarm_ascii85_group;
extern const sx_layout sxarm_ascii85_shorthand;
extern const sx_layout sxarm_btoa_line_check;
bool sxarm_span(sx_context*c,uint64_t p,uint64_t n);
bool sxarm_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxarm_uint(const uint8_t*b,unsigned n,bool be);
bool sxarm_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxarm_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxarm_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxarm_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n);
bool sxarm_line(sx_context*c,uint64_t p,uint8_t*b,size_t cap,size_t*n,uint64_t*next);
bool sxarm_eq(const uint8_t*b,size_t n,const char*s);
bool sxarm_uint_text(const uint8_t*b,size_t n,unsigned radix,uint64_t*v);
bool sxarm_numeric_text(sx_context*c,const sx_layout*l,uint64_t p,const uint8_t*b,size_t n);

/* Per-format walkers, called by the family's build. */
bool sx_warc_build(sx_context *c);  /* archive/warc/xx_warc_data.c */
bool sx_pcommos2_build(sx_context *c);  /* archive/pcommos2/xx_pcommos2_data.c */
bool sx_btoa_build(sx_context *c);  /* archive/btoa/xx_btoa_data.c */
bool sx_uue_build(sx_context *c);  /* archive/uue/xx_uue_data.c */
bool sx_binscii_build(sx_context *c);  /* archive/binscii/xx_binscii_data.c */
bool sx_yenc_encoded_file_build(sx_context *c);  /* archive/yenc_encoded_file/xx_yenc_encoded_file_data.c */
bool sx_balz_build(sx_context *c);  /* archive/balz/xx_balz_data.c */
bool sx_bzip1_build(sx_context *c);  /* archive/bzip1/xx_bzip1_data.c */
bool sx_freeze_build(sx_context *c);  /* archive/freeze/xx_freeze_data.c */
bool sx_rvz_build(sx_context *c);  /* game/rvz/xx_rvz_data.c */
bool sx_audio_scumm_sou_build(sx_context *c);  /* game/audio_scumm_sou/xx_audio_scumm_sou_data.c */
bool sx_he_tlkb_build(sx_context *c);  /* game/he_tlkb/xx_he_tlkb_data.c */

#endif
