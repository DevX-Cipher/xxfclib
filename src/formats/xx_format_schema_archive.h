/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archive schema family: what its family unit (xx_format_schema_archive.c)
 * and its formats' data files share. Formats: CPIO; Microsoft Cabinet (CAB); LZ4 frame; Zstandard; Lzip; LZOP. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVE_H
#define XX_FORMAT_SCHEMA_ARCHIVE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_a_cpio_newc_header;
extern const sx_layout sx_a_cpio_odc_header;
extern const sx_layout sx_a_cpio_afio_header;
extern const sx_layout sx_a_cpio_binary_le_header;
extern const sx_layout sx_a_cpio_binary_be_header;
extern const sx_layout sx_a_cpio_solaris_tl;
extern const sx_layout sx_a_cpio_solaris_tg;
extern const sx_layout sx_a_cpio_solaris_block;
extern const sx_layout sx_a_cab_header;
extern const sx_layout sx_a_cab_reserve_sizes;
extern const sx_layout sx_a_cab_folder;
extern const sx_layout sx_a_cab_file;
extern const sx_layout sx_a_cab_data;
extern const sx_layout sx_a_lz4_frame_header_00;
extern const sx_layout sx_a_lz4_frame_header_01;
extern const sx_layout sx_a_lz4_frame_header_10;
extern const sx_layout sx_a_lz4_frame_header_11;
extern const sx_layout sx_a_lz4_block_header;
extern const sx_layout sx_a_checksum_le;
extern const sx_layout sx_a_checksum_be;
extern const sx_layout sx_a_lz4_legacy_header;
extern const sx_layout sx_a_zstd_frame_header_000;
extern const sx_layout sx_a_zstd_frame_header_001;
extern const sx_layout sx_a_zstd_frame_header_002;
extern const sx_layout sx_a_zstd_frame_header_003;
extern const sx_layout sx_a_zstd_frame_header_010;
extern const sx_layout sx_a_zstd_frame_header_011;
extern const sx_layout sx_a_zstd_frame_header_012;
extern const sx_layout sx_a_zstd_frame_header_013;
extern const sx_layout sx_a_zstd_frame_header_020;
extern const sx_layout sx_a_zstd_frame_header_021;
extern const sx_layout sx_a_zstd_frame_header_022;
extern const sx_layout sx_a_zstd_frame_header_023;
extern const sx_layout sx_a_zstd_frame_header_030;
extern const sx_layout sx_a_zstd_frame_header_031;
extern const sx_layout sx_a_zstd_frame_header_032;
extern const sx_layout sx_a_zstd_frame_header_033;
extern const sx_layout sx_a_zstd_frame_header_100;
extern const sx_layout sx_a_zstd_frame_header_101;
extern const sx_layout sx_a_zstd_frame_header_102;
extern const sx_layout sx_a_zstd_frame_header_103;
extern const sx_layout sx_a_zstd_frame_header_110;
extern const sx_layout sx_a_zstd_frame_header_111;
extern const sx_layout sx_a_zstd_frame_header_112;
extern const sx_layout sx_a_zstd_frame_header_113;
extern const sx_layout sx_a_zstd_frame_header_120;
extern const sx_layout sx_a_zstd_frame_header_121;
extern const sx_layout sx_a_zstd_frame_header_122;
extern const sx_layout sx_a_zstd_frame_header_123;
extern const sx_layout sx_a_zstd_frame_header_130;
extern const sx_layout sx_a_zstd_frame_header_131;
extern const sx_layout sx_a_zstd_frame_header_132;
extern const sx_layout sx_a_zstd_frame_header_133;
extern const sx_layout sx_a_zstd_block_header;
extern const sx_layout sx_a_lzip_header;
extern const sx_layout sx_a_lzip_trailer;
extern const sx_layout sx_a_lzop_header_00;
extern const sx_layout sx_a_lzop_header_01;
extern const sx_layout sx_a_lzop_header_10;
extern const sx_layout sx_a_lzop_header_11;
extern const sx_layout sx_a_lzop_block_sizes;
extern const sx_layout sx_a_lzop_end;
extern const sx_layout sx_a_lzop_extra_size;
bool sx_a_raw_advance(sx_context *c,int64_t *at,uint64_t size);
bool sx_a_skippable(sx_context *c,int64_t *at);

/* Per-format walkers, called by the family's build. */
bool sx_cpio_build(sx_context *c);  /* archive/cpio/xx_cpio_data.c */
bool sx_cab_build(sx_context *c);  /* archive/cab/xx_cab_data.c */
bool sx_lz4_build(sx_context *c);  /* archive/lz4/xx_lz4_data.c */
bool sx_zstd_build(sx_context *c);  /* archive/zstd/xx_zstd_data.c */
bool sx_lzip_build(sx_context *c);  /* archive/lzip/xx_lzip_data.c */
bool sx_lzop_build(sx_context *c);  /* archive/lzop/xx_lzop_data.c */

#endif
