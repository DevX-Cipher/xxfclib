/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The videotail schema family: what its family unit (xx_format_schema_videotail.c)
 * and its formats' data files share. Formats: GRASP; swf; mp4; matroska; Adobe Director CXT. */
#ifndef XX_FORMAT_SCHEMA_VIDEOTAIL_H
#define XX_FORMAT_SCHEMA_VIDEOTAIL_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxvt_grasp_header;
extern const sx_layout sxvt_grasp_entry;
extern const sx_layout sxvt_grasp_member_size;
extern const sx_layout sxvt_swf_header;
extern const sx_layout sxvt_swf_lzma_header;
extern const sx_layout sxvt_swf_rect1;
extern const sx_layout sxvt_swf_rect2;
extern const sx_layout sxvt_swf_rect3;
extern const sx_layout sxvt_swf_rect4;
extern const sx_layout sxvt_swf_rect5;
extern const sx_layout sxvt_swf_rect6;
extern const sx_layout sxvt_swf_rect7;
extern const sx_layout sxvt_swf_rect8;
extern const sx_layout sxvt_swf_rect9;
extern const sx_layout sxvt_swf_rect10;
extern const sx_layout sxvt_swf_rect11;
extern const sx_layout sxvt_swf_rect12;
extern const sx_layout sxvt_swf_rect13;
extern const sx_layout sxvt_swf_rect14;
extern const sx_layout sxvt_swf_rect15;
extern const sx_layout sxvt_swf_rect16;
extern const sx_layout sxvt_swf_rect17;
extern const sx_layout sxvt_swf_movie;
extern const sx_layout sxvt_swf_tag_short;
extern const sx_layout sxvt_swf_tag_long;
extern const sx_layout sxvt_swf_sprite;
extern const sx_layout sxvt_swf_background;
extern const sx_layout sxvt_swf_character_id;
extern const sx_layout sxvt_swf_jpeg3;
extern const sx_layout sxvt_swf_jpeg4;
extern const sx_layout sxvt_swf_lossless;
extern const sx_layout sxvt_swf_palette_count;
extern const sx_layout sxvt_swf_sound;
extern const sx_layout sxvt_swf_mp3_seek;
extern const sx_layout sxvt_swf_stream_sound;
extern const sx_layout sxvt_swf_binary;
extern const sx_layout sxvt_swf_file_attributes;
extern const sx_layout sxvt_director_header_le;
extern const sx_layout sxvt_director_chunk_le;
extern const sx_layout sxvt_director_header_be;
extern const sx_layout sxvt_director_chunk_be;
extern const sx_layout sxvt_mp4_box;
extern const sx_layout sxvt_mp4_box64;
extern const sx_layout sxvt_mp4_uuid;
extern const sx_layout sxvt_mp4_ftyp;
extern const sx_layout sxvt_mp4_brand;
extern const sx_layout sxvt_mp4_mvhd_v0;
extern const sx_layout sxvt_mp4_tkhd_v0;
extern const sx_layout sxvt_mp4_mdhd_v0;
extern const sx_layout sxvt_mp4_elst_entry_v0;
extern const sx_layout sxvt_mp4_mvhd_v1;
extern const sx_layout sxvt_mp4_tkhd_v1;
extern const sx_layout sxvt_mp4_mdhd_v1;
extern const sx_layout sxvt_mp4_elst_entry_v1;
extern const sx_layout sxvt_mp4_hdlr;
extern const sx_layout sxvt_mp4_table;
extern const sx_layout sxvt_mp4_stsz;
extern const sx_layout sxvt_mp4_stco;
extern const sx_layout sxvt_mp4_co64;
extern const sx_layout sxvt_mp4_stts;
extern const sx_layout sxvt_mp4_ctts_v0;
extern const sx_layout sxvt_mp4_ctts_v1;
extern const sx_layout sxvt_mp4_stsc;
extern const sx_layout sxvt_mp4_stss;
extern const sx_layout sxvt_mp4_sample_size;
extern const sx_layout sxvt_mp4_sample_entry;
extern const sx_layout sxvt_mp4_vmhd;
extern const sx_layout sxvt_mp4_smhd;
extern const sx_layout sxvt_mp4_fullbox;
extern const sx_layout sxvt_ebml_id1;
extern const sx_layout sxvt_ebml_id2;
extern const sx_layout sxvt_ebml_id3;
extern const sx_layout sxvt_ebml_id4;
extern const sx_layout sxvt_ebml_size1;
extern const sx_layout sxvt_matroska_track1;
extern const sx_layout sxvt_matroska_lace_size1;
extern const sx_layout sxvt_matroska_lace_delta1;
extern const sx_layout sxvt_matroska_uint1;
extern const sx_layout sxvt_matroska_offset1;
extern const sx_layout sxvt_ebml_size2;
extern const sx_layout sxvt_matroska_track2;
extern const sx_layout sxvt_matroska_lace_size2;
extern const sx_layout sxvt_matroska_lace_delta2;
extern const sx_layout sxvt_matroska_uint2;
extern const sx_layout sxvt_matroska_offset2;
extern const sx_layout sxvt_ebml_size3;
extern const sx_layout sxvt_matroska_track3;
extern const sx_layout sxvt_matroska_lace_size3;
extern const sx_layout sxvt_matroska_lace_delta3;
extern const sx_layout sxvt_matroska_uint3;
extern const sx_layout sxvt_matroska_offset3;
extern const sx_layout sxvt_ebml_size4;
extern const sx_layout sxvt_matroska_track4;
extern const sx_layout sxvt_matroska_lace_size4;
extern const sx_layout sxvt_matroska_lace_delta4;
extern const sx_layout sxvt_matroska_uint4;
extern const sx_layout sxvt_matroska_offset4;
extern const sx_layout sxvt_ebml_size5;
extern const sx_layout sxvt_matroska_track5;
extern const sx_layout sxvt_matroska_lace_size5;
extern const sx_layout sxvt_matroska_lace_delta5;
extern const sx_layout sxvt_matroska_uint5;
extern const sx_layout sxvt_matroska_offset5;
extern const sx_layout sxvt_ebml_size6;
extern const sx_layout sxvt_matroska_track6;
extern const sx_layout sxvt_matroska_lace_size6;
extern const sx_layout sxvt_matroska_lace_delta6;
extern const sx_layout sxvt_matroska_uint6;
extern const sx_layout sxvt_matroska_offset6;
extern const sx_layout sxvt_ebml_size7;
extern const sx_layout sxvt_matroska_track7;
extern const sx_layout sxvt_matroska_lace_size7;
extern const sx_layout sxvt_matroska_lace_delta7;
extern const sx_layout sxvt_matroska_uint7;
extern const sx_layout sxvt_matroska_offset7;
extern const sx_layout sxvt_ebml_size8;
extern const sx_layout sxvt_matroska_track8;
extern const sx_layout sxvt_matroska_lace_size8;
extern const sx_layout sxvt_matroska_lace_delta8;
extern const sx_layout sxvt_matroska_uint8;
extern const sx_layout sxvt_matroska_offset8;
extern const sx_layout sxvt_matroska_date;
extern const sx_layout sxvt_matroska_float4;
extern const sx_layout sxvt_matroska_float8;
extern const sx_layout sxvt_matroska_crc32;
extern const sx_layout sxvt_matroska_block;
extern const sx_layout sxvt_matroska_lace_count;
extern const sx_layout sxvt_matroska_xiph_size;
extern const sx_layout sxvt_director_imap_le;
extern const sx_layout sxvt_director_mmap_le;
extern const sx_layout sxvt_director_mmap_entry_le;
extern const sx_layout sxvt_director_key_le;
extern const sx_layout sxvt_director_key_entry_le;
extern const sx_layout sxvt_director_imap_be;
extern const sx_layout sxvt_director_mmap_be;
extern const sx_layout sxvt_director_mmap_entry_be;
extern const sx_layout sxvt_director_key_be;
extern const sx_layout sxvt_director_key_entry_be;
extern const sx_layout sxvt_director_cast_index;
bool sxvt_span(sx_context*c,uint64_t p,uint64_t n);
bool sxvt_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxvt_uint(const uint8_t*b,unsigned n,bool be);
bool sxvt_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxvt_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxvt_byte(sx_context*c,uint64_t p,uint8_t*v);

/* Per-format walkers, called by the family's build. */
bool sx_grasp_build(sx_context *c);  /* video/grasp/xx_grasp_data.c */
bool sx_swf_build(sx_context *c);  /* video/swf/xx_swf_data.c */
bool sx_mp4_build(sx_context *c);  /* video/mp4/xx_mp4_data.c */
bool sx_matroska_build(sx_context *c);  /* video/matroska/xx_matroska_data.c */
bool sx_adobe_director_cxt_build(sx_context *c);  /* video/adobe_director_cxt/xx_adobe_director_cxt_data.c */

#endif
