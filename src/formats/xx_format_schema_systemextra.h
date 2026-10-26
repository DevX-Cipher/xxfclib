/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The systemextra schema family: what its family unit (xx_format_schema_systemextra.c)
 * and its formats' data files share. Formats: Vice X64; Commodore G64; Commodore P64; Commodore Tap; Zx Spectrum Tzx; Amstrad Cpc Dsk; Atari St Msa; Supercard Scp; Apple Woz; Zx Spectrum Pzx; Acorn Uef; Commodore Pc64; Atari Cas; Oric Tap; Dragon Vdk; Apple A2R; Atari Atr; Atari Pasti Stx; Hxc Mfm; Yaze Ydsk; T98 Next Nfd; Hfe; Hxc Stream Hfe; Hxc Hfe Extended; Hxc Hfe Hddd A2 Variant; Hxc Hfe V3. */
#ifndef XX_FORMAT_SCHEMA_SYSTEMEXTRA_H
#define XX_FORMAT_SCHEMA_SYSTEMEXTRA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxse_x64_header;
extern const sx_layout sxse_g64_header;
extern const sx_layout sxse_g64_track_offset;
extern const sx_layout sxse_g64_constant_speed;
extern const sx_layout sxse_g64_speed_offset;
extern const sx_layout sxse_g64_track_header;
extern const sx_layout sxse_p64_header;
extern const sx_layout sxse_p64_chunk_header;
extern const sx_layout sxse_p64_halftrack_header;
extern const sx_layout sxse_c64_tap_header;
extern const sx_layout sxse_tzx_header;
extern const sx_layout sxse_tzx_standard_data;
extern const sx_layout sxse_tzx_turbo_data;
extern const sx_layout sxse_tzx_pure_tone;
extern const sx_layout sxse_tzx_pulse_sequence;
extern const sx_layout sxse_tzx_pulse;
extern const sx_layout sxse_tzx_pure_data;
extern const sx_layout sxse_tzx_pause;
extern const sx_layout sxse_tzx_text_header;
extern const sx_layout sxse_tzx_group_end;
extern const sx_layout sxse_tzx_archive_info;
extern const sx_layout sxse_tzx_archive_string;
extern const sx_layout sxse_tzx_custom_info;
extern const sx_layout sxse_cpc_disk_header;
extern const sx_layout sxse_cpc_extended_disk_header;
extern const sx_layout sxse_cpc_track_size;
extern const sx_layout sxse_cpc_track_header;
extern const sx_layout sxse_cpc_sector_standard;
extern const sx_layout sxse_cpc_sector_extended;
extern const sx_layout sxse_cpc_offset_info;
extern const sx_layout sxse_cpc_track_length;
extern const sx_layout sxse_cpc_sector_timing;
extern const sx_layout sxse_msa_header;
extern const sx_layout sxse_msa_track_header;
extern const sx_layout sxse_scp_header;
extern const sx_layout sxse_scp_track_offset;
extern const sx_layout sxse_scp_track_header;
extern const sx_layout sxse_scp_revolution;
extern const sx_layout sxse_scp_extension_header;
extern const sx_layout sxse_scp_write_splices_header;
extern const sx_layout sxse_scp_write_splice;
extern const sx_layout sxse_scp_footer;
extern const sx_layout sxse_scp_string_header;
extern const sx_layout sxse_uef_header;
extern const sx_layout sxse_uef_chunk;
extern const sx_layout sxse_uef_carrier;
extern const sx_layout sxse_uef_carrier_dummy;
extern const sx_layout sxse_uef_gap;
extern const sx_layout sxse_uef_phase;
extern const sx_layout sxse_pc64_header;
extern const sx_layout sxse_atari_cas_description;
extern const sx_layout sxse_atari_cas_baud;
extern const sx_layout sxse_atari_cas_data;
extern const sx_layout sxse_atari_cas_fsk;
extern const sx_layout sxse_oric_tap_header;
extern const sx_layout sxse_vdk_header;
extern const sx_layout sxse_atr_header;
extern const sx_layout sxse_stx_header;
extern const sx_layout sxse_stx_track;
extern const sx_layout sxse_stx_sector;
extern const sx_layout sxse_hxc_mfm_header;
extern const sx_layout sxse_hxc_mfm_track;
extern const sx_layout sxse_ydsk_header;
extern const sx_layout sxse_nfd_header;
extern const sx_layout sxse_nfd_sector_r0;
extern const sx_layout sxse_nfd_sector_r1;
extern const sx_layout sxse_nfd_track_offset;
extern const sx_layout sxse_nfd_additional_info;
extern const sx_layout sxse_nfd_track_header;
extern const sx_layout sxse_nfd_diagnostic;
bool sxse_span(sx_context*c,uint64_t p,uint64_t n);
bool sxse_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxse_u16(const void*b,unsigned p,bool be);
uint32_t sxse_u32(const void*b,unsigned p,bool be);
bool sxse_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z,uint64_t n);
bool sxse_chunks(sx_context*c,bool woz,bool a2r);
bool sxse_hfe(sx_context*c,bool stream);

/* Per-format walkers, called by the family's build. */
bool sx_vice_x64_build(sx_context *c);  /* filesystem/vice_x64/xx_vice_x64_data.c */
bool sx_commodore_g64_build(sx_context *c);  /* filesystem/commodore_g64/xx_commodore_g64_data.c */
bool sx_commodore_p64_build(sx_context *c);  /* filesystem/commodore_p64/xx_commodore_p64_data.c */
bool sx_commodore_tap_build(sx_context *c);  /* filesystem/commodore_tap/xx_commodore_tap_data.c */
bool sx_zx_spectrum_tzx_build(sx_context *c);  /* filesystem/zx_spectrum_tzx/xx_zx_spectrum_tzx_data.c */
bool sx_amstrad_cpc_dsk_build(sx_context *c);  /* filesystem/amstrad_cpc_dsk/xx_amstrad_cpc_dsk_data.c */
bool sx_atari_st_msa_build(sx_context *c);  /* filesystem/atari_st_msa/xx_atari_st_msa_data.c */
bool sx_supercard_scp_build(sx_context *c);  /* filesystem/supercard_scp/xx_supercard_scp_data.c */
bool sx_apple_woz_build(sx_context *c);  /* filesystem/apple_woz/xx_apple_woz_data.c */
bool sx_zx_spectrum_pzx_build(sx_context *c);  /* filesystem/zx_spectrum_pzx/xx_zx_spectrum_pzx_data.c */
bool sx_acorn_uef_build(sx_context *c);  /* filesystem/acorn_uef/xx_acorn_uef_data.c */
bool sx_commodore_pc64_build(sx_context *c);  /* filesystem/commodore_pc64/xx_commodore_pc64_data.c */
bool sx_atari_cas_build(sx_context *c);  /* filesystem/atari_cas/xx_atari_cas_data.c */
bool sx_oric_tap_build(sx_context *c);  /* filesystem/oric_tap/xx_oric_tap_data.c */
bool sx_dragon_vdk_build(sx_context *c);  /* filesystem/dragon_vdk/xx_dragon_vdk_data.c */
bool sx_apple_a2r_build(sx_context *c);  /* filesystem/apple_a2r/xx_apple_a2r_data.c */
bool sx_atari_atr_build(sx_context *c);  /* filesystem/atari_atr/xx_atari_atr_data.c */
bool sx_atari_pasti_stx_build(sx_context *c);  /* filesystem/atari_pasti_stx/xx_atari_pasti_stx_data.c */
bool sx_hxc_mfm_build(sx_context *c);  /* filesystem/hxc_mfm/xx_hxc_mfm_data.c */
bool sx_yaze_ydsk_build(sx_context *c);  /* filesystem/yaze_ydsk/xx_yaze_ydsk_data.c */
bool sx_t98_next_nfd_build(sx_context *c);  /* filesystem/t98_next_nfd/xx_t98_next_nfd_data.c */
bool sx_hfe_build(sx_context *c);  /* filesystem/hfe/xx_hfe_data.c */
bool sx_hxc_stream_hfe_build(sx_context *c);  /* filesystem/hxc_stream_hfe/xx_hxc_stream_hfe_data.c */
bool sx_hxc_hfe_extended_build(sx_context *c);  /* filesystem/hxc_hfe_extended/xx_hxc_hfe_extended_data.c */
bool sx_hxc_hfe_hddd_a2_variant_build(sx_context *c);  /* filesystem/hxc_hfe_hddd_a2_variant/xx_hxc_hfe_hddd_a2_variant_data.c */
bool sx_hxc_hfe_v3_build(sx_context *c);  /* filesystem/hxc_hfe_v3/xx_hxc_hfe_v3_data.c */

#endif
