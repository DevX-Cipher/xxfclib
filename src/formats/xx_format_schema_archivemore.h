/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivemore schema family: what its family unit (xx_format_schema_archivemore.c)
 * and its formats' data files share. Formats: Pocket Soft RTPatch (.rtp) patch packages; Blizzard MoPaQ (MPQ) game archive; AppleSingle / AppleDouble; MacBinary; Apple II Binary II; NuFX (ShrinkIt) archives; Macintosh PackIt archives (.pit); StuffIt (SIT!) archives; Compact Pro (.cpt) archives; EGG archives; LZFSE stream; LZF stream; FastLZ 6pack; CP/M LU library (.LBR); PDP-11 ar archives; AIX big archives. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEMORE_H
#define XX_FORMAT_SCHEMA_ARCHIVEMORE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxar_mpq_header_v0;
extern const sx_layout sxar_mpq_header_v1;
extern const sx_layout sxar_mpq_header_v2;
extern const sx_layout sxar_mpq_header_v3;
extern const sx_layout sxar_mpq_high_block_entry;
extern const sx_layout sxar_applesingle_header;
extern const sx_layout sxar_applesingle_entry;
extern const sx_layout sxar_macbinary1_header;
extern const sx_layout sxar_macbinary2_header;
extern const sx_layout sxar_macbinary3_header;
extern const sx_layout sxar_binaryii_header;
extern const sx_layout sxar_nufx_master;
extern const sx_layout sxar_nufx_record;
extern const sx_layout sxar_nufx_option_size;
extern const sx_layout sxar_nufx_name_size;
extern const sx_layout sxar_nufx_thread;
extern const sx_layout sxar_stuffit_header;
extern const sx_layout sxar_stuffit_member;
extern const sx_layout sxar_compactpro_header;
extern const sx_layout sxar_compactpro_catalogue;
extern const sx_layout sxar_compactpro_name_size;
extern const sx_layout sxar_compactpro_directory;
extern const sx_layout sxar_compactpro_file;
extern const sx_layout sxar_egg_header;
extern const sx_layout sxar_egg_file;
extern const sx_layout sxar_egg_extra;
extern const sx_layout sxar_egg_block;
extern const sx_layout sxar_egg_end;
extern const sx_layout sxar_lzfse_raw_block;
extern const sx_layout sxar_lzfse_lzvn_block;
extern const sx_layout sxar_lzfse_v1_block;
extern const sx_layout sxar_lzfse_v2_block;
extern const sx_layout sxar_lzfse_end;
extern const sx_layout sxar_lzf_stored_block;
extern const sx_layout sxar_lzf_compressed_block;
extern const sx_layout sxar_lzf_end;
extern const sx_layout sxar_sixpack_header;
extern const sx_layout sxar_sixpack_chunk;
extern const sx_layout sxar_sixpack_file;
extern const sx_layout sxar_lbr_directory_entry;
extern const sx_layout sxar_pdp11ar_header;
extern const sx_layout sxar_pdp11ar_member;
extern const sx_layout sxar_bigaf_header;
extern const sx_layout sxar_bigaf_member;
extern const sx_layout sxar_bigaf_name_end;
bool sxar_span(sx_context *c,uint64_t p,uint64_t n);
bool sxar_read(sx_context *c,uint64_t p,void *b,size_t n);
uint16_t sxar16(const uint8_t *b,bool be);
uint32_t sxar32(const uint8_t *b,bool be);
uint64_t sxar64(const uint8_t *b);
bool sxar_add(sx_context *c,const sx_layout *l,uint64_t p);
bool sxar_native_records(sx_context *c,bool pit);

/* Per-format walkers, called by the family's build. */
bool sx_rtpatch_build(sx_context *c);  /* installer/rtpatch/xx_rtpatch_data.c */
bool sx_mpq_build(sx_context *c);  /* game/mpq/xx_mpq_data.c */
bool sx_applesingle_build(sx_context *c);  /* archive/applesingle/xx_applesingle_data.c */
bool sx_macbinary_build(sx_context *c);  /* archive/macbinary/xx_macbinary_data.c */
bool sx_binaryii_build(sx_context *c);  /* archive/binaryii/xx_binaryii_data.c */
bool sx_nufx_build(sx_context *c);  /* archive/nufx/xx_nufx_data.c */
bool sx_packit_mac_build(sx_context *c);  /* archive/packit_mac/xx_packit_mac_data.c */
bool sx_stuffit_build(sx_context *c);  /* archive/stuffit/xx_stuffit_data.c */
bool sx_compactpro_build(sx_context *c);  /* archive/compactpro/xx_compactpro_data.c */
bool sx_egg_build(sx_context *c);  /* archive/egg/xx_egg_data.c */
bool sx_lzfsestream_build(sx_context *c);  /* archive/lzfsestream/xx_lzfsestream_data.c */
bool sx_lzf_stream_build(sx_context *c);  /* archive/lzf_stream/xx_lzf_stream_data.c */
bool sx_fastlz_sixpack_build(sx_context *c);  /* archive/fastlz_sixpack/xx_fastlz_sixpack_data.c */
bool sx_lbr_build(sx_context *c);  /* archive/lbr/xx_lbr_data.c */
bool sx_pdp11ar_build(sx_context *c);  /* archive/pdp11ar/xx_pdp11ar_data.c */
bool sx_bigaf_build(sx_context *c);  /* archive/bigaf/xx_bigaf_data.c */

#endif
