/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The disklegacy schema family: what its family unit (xx_format_schema_disklegacy.c)
 * and its formats' data files share. Formats: ShrinkWrap; TRS-80 JV3; X68000 DIM floppy image; dart; daemon_tools_mdx; LibDsk LDBS disk image; atari dim; atari stt; atari stw; discferret dfi; hxc afi; hxc qd; hxc stream; oric dsk; ensoniq gkh; ensoniq ede; samcoupe sad; Trackstar APP; Xbox FATX filesystem; xbox xdvdfs; FocusDrive partition map; Apple MicroDrive partition map. */
#ifndef XX_FORMAT_SCHEMA_DISKLEGACY_H
#define XX_FORMAT_SCHEMA_DISKLEGACY_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxdleg_shrinkwrap_header;
extern const sx_layout sxdleg_jv3_sector_descriptor;
extern const sx_layout sxdleg_jv3_write_protection;
extern const sx_layout sxdleg_x68000_dim_header;
extern const sx_layout sxdleg_dart_header;
extern const sx_layout sxdleg_dart_block_length;
extern const sx_layout sxdleg_mds2_header;
extern const sx_layout sxdleg_mdx_header;
extern const sx_layout sxdleg_mdx_key_salt;
extern const sx_layout sxdleg_ldbs_header;
extern const sx_layout sxdleg_ldbs_block_header;
extern const sx_layout sxdleg_ldbs_directory_header;
extern const sx_layout sxdleg_ldbs_directory_entry;
extern const sx_layout sxdleg_ldbs_track_header;
extern const sx_layout sxdleg_ldbs_sector16;
extern const sx_layout sxdleg_ldbs_sector18;
extern const sx_layout sxdleg_ldbs_geometry;
extern const sx_layout sxdleg_atari_dim_header;
extern const sx_layout sxdleg_stt_header;
extern const sx_layout sxdleg_stt_track_entry;
extern const sx_layout sxdleg_stt_track_header;
extern const sx_layout sxdleg_stt_sector_section;
extern const sx_layout sxdleg_stt_sector_descriptor;
extern const sx_layout sxdleg_stt_raw_section;
extern const sx_layout sxdleg_stt_unknown_section;
extern const sx_layout sxdleg_stw_header;
extern const sx_layout sxdleg_stw_track_header;
extern const sx_layout sxdleg_discferret_header;
extern const sx_layout sxdleg_discferret_capture;
extern const sx_layout sxdleg_afi_header;
extern const sx_layout sxdleg_afi_info;
extern const sx_layout sxdleg_afi_string_offset;
extern const sx_layout sxdleg_afi_track_offset;
extern const sx_layout sxdleg_afi_data_offset;
extern const sx_layout sxdleg_afi_crc;
extern const sx_layout sxdleg_afi_string;
extern const sx_layout sxdleg_afi_track_list;
extern const sx_layout sxdleg_afi_track;
extern const sx_layout sxdleg_afi_data;
extern const sx_layout sxdleg_hxc_qd_header;
extern const sx_layout sxdleg_hxc_qd_track;
extern const sx_layout sxdleg_hxc_stream_chunk;
extern const sx_layout sxdleg_hxc_stream_metadata;
extern const sx_layout sxdleg_hxc_stream_io;
extern const sx_layout sxdleg_hxc_stream_flux;
extern const sx_layout sxdleg_hxc_stream_crc;
extern const sx_layout sxdleg_oric_sector_header;
extern const sx_layout sxdleg_oric_mfm_header;
extern const sx_layout sxdleg_gkh_header;
extern const sx_layout sxdleg_gkh_format_tag;
extern const sx_layout sxdleg_gkh_geometry_tag;
extern const sx_layout sxdleg_gkh_location_tag;
extern const sx_layout sxdleg_ede_text_header;
extern const sx_layout sxdleg_ede_bitmap_marker;
extern const sx_layout sxdleg_ede_bitmap_byte;
extern const sx_layout sxdleg_ede_format;
extern const sx_layout sxdleg_sad_header;
extern const sx_layout sxdleg_trackstar_track_header;
extern const sx_layout sxdleg_trackstar_track_size;
extern const sx_layout sxdleg_fatx_superblock;
extern const sx_layout sxdleg_fatx_fat16_entry;
extern const sx_layout sxdleg_fatx_fat32_entry;
extern const sx_layout sxdleg_fatx_directory_entry;
extern const sx_layout sxdleg_xdvdfs_volume_descriptor;
extern const sx_layout sxdleg_xdvdfs_directory_entry;
extern const sx_layout sxdleg_focusdrive_header;
extern const sx_layout sxdleg_focusdrive_partition;
extern const sx_layout sxdleg_focusdrive_name_header;
extern const sx_layout sxdleg_focusdrive_partition_name;
extern const sx_layout sxdleg_microdrive_header;
extern const sx_layout sxdleg_microdrive_start;
extern const sx_layout sxdleg_microdrive_size;
extern const sx_layout sxdleg_ldbs_track_directory_entry;
extern const sx_layout sxdleg_ldbs_track_block_header;
extern const sx_layout sxdleg_ldbs_sector_block_header;
bool sxdleg_span(sx_context*c,uint64_t p,uint64_t n);
bool sxdleg_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxdleg16(const uint8_t*b,unsigned o);
uint32_t sxdleg32(const uint8_t*b,unsigned o);
bool sxdleg_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_shrinkwrap_build(sx_context *c);  /* filesystem/shrinkwrap/xx_shrinkwrap_data.c */
bool sx_trs_80_jv3_build(sx_context *c);  /* filesystem/trs_80_jv3/xx_trs_80_jv3_data.c */
bool sx_x68000_dim_build(sx_context *c);  /* filesystem/x68000_dim/xx_x68000_dim_data.c */
bool sx_dart_build(sx_context *c);  /* filesystem/dart/xx_dart_data.c */
bool sx_daemon_tools_mdx_build(sx_context *c);  /* filesystem/daemon_tools_mdx/xx_daemon_tools_mdx_data.c */
bool sx_ldbs_build(sx_context *c);  /* filesystem/ldbs/xx_ldbs_data.c */
bool sx_atari_dim_build(sx_context *c);  /* filesystem/atari_dim/xx_atari_dim_data.c */
bool sx_atari_stt_build(sx_context *c);  /* filesystem/atari_stt/xx_atari_stt_data.c */
bool sx_atari_stw_build(sx_context *c);  /* filesystem/atari_stw/xx_atari_stw_data.c */
bool sx_discferret_dfi_build(sx_context *c);  /* filesystem/discferret_dfi/xx_discferret_dfi_data.c */
bool sx_hxc_afi_build(sx_context *c);  /* filesystem/hxc_afi/xx_hxc_afi_data.c */
bool sx_hxc_qd_build(sx_context *c);  /* filesystem/hxc_qd/xx_hxc_qd_data.c */
bool sx_hxc_stream_build(sx_context *c);  /* filesystem/hxc_stream/xx_hxc_stream_data.c */
bool sx_oric_dsk_build(sx_context *c);  /* filesystem/oric_dsk/xx_oric_dsk_data.c */
bool sx_ensoniq_gkh_build(sx_context *c);  /* filesystem/ensoniq_gkh/xx_ensoniq_gkh_data.c */
bool sx_ensoniq_ede_build(sx_context *c);  /* filesystem/ensoniq_ede/xx_ensoniq_ede_data.c */
bool sx_samcoupe_sad_build(sx_context *c);  /* filesystem/samcoupe_sad/xx_samcoupe_sad_data.c */
bool sx_trackstar_build(sx_context *c);  /* filesystem/trackstar/xx_trackstar_data.c */
bool sx_fatx_build(sx_context *c);  /* filesystem/fatx/xx_fatx_data.c */
bool sx_xbox_xdvdfs_build(sx_context *c);  /* filesystem/xbox_xdvdfs/xx_xbox_xdvdfs_data.c */
bool sx_focusdrive_build(sx_context *c);  /* filesystem/focusdrive/xx_focusdrive_data.c */
bool sx_microdrive_build(sx_context *c);  /* filesystem/microdrive/xx_microdrive_data.c */

#endif
