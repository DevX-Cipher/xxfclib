/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The audiomore schema family: what its family unit (xx_format_schema_audiomore.c)
 * and its formats' data files share. Formats: cri_awb; microsoft_xwb; microsoft_xsb; audio_ast; audio_hca; iff_8svx; vgm_log; audio_dolby_ac3; audio_mpeg_mp3; audio_aac_adts; audio_monkeys_ape; ircam_sdif; atari_sap; sc68_music; amiga_ahx; sony_vab; zx_ayemul; fmod_sample_bank; interplay_acm; cri_ahx; olympus_dss; ea_exa; audio_nitro_strm; ensoniq_paf; abylight_strm; lego_alp; parsec_pmm. */
#ifndef XX_FORMAT_SCHEMA_AUDIOMORE_H
#define XX_FORMAT_SCHEMA_AUDIOMORE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Every walker bounds its physical reads independently. Native readers decide
 * validity; compressed samples and unimplemented extensions stay RAW_DATA. */
typedef struct sxau_view {sx_context *c;uint8_t *p;size_t n;unsigned work;}sxau_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxau_awb_header;
extern const sx_layout sxau_awb_id16;
extern const sx_layout sxau_awb_offset16;
extern const sx_layout sxau_awb_id32;
extern const sx_layout sxau_awb_offset32;
extern const sx_layout sxau_xwb_header;
extern const sx_layout sxau_xwb_segment;
extern const sx_layout sxau_xwb_bank_data;
extern const sx_layout sxau_xwb_entry;
extern const sx_layout sxau_xact_name;
extern const sx_layout sxau_xsb_header;
extern const sx_layout sxau_xsb_cue;
extern const sx_layout sxau_xsb_simple_sound;
extern const sx_layout sxau_ast_header;
extern const sx_layout sxau_ast_block;
extern const sx_layout sxau_hca_header;
extern const sx_layout sxau_hca_format;
extern const sx_layout sxau_hca_compression;
extern const sx_layout sxau_hca_ath;
extern const sx_layout sxau_hca_loop;
extern const sx_layout sxau_hca_cipher;
extern const sx_layout sxau_hca_relative_volume;
extern const sx_layout sxau_hca_comment;
extern const sx_layout sxau_hca_pad;
extern const sx_layout sxau_hca_checksum;
extern const sx_layout sxau_hca_frame_sync;
extern const sx_layout sxau_iff8svx_form;
extern const sx_layout sxau_iff8svx_chunk;
extern const sx_layout sxau_iff8svx_voice;
extern const sx_layout sxau_iff8svx_channel;
extern const sx_layout sxau_vgm_header;
extern const sx_layout sxau_vgm_gd3;
extern const sx_layout sxau_vgm_command;
extern const sx_layout sxau_vgm_register8;
extern const sx_layout sxau_vgm_register16;
extern const sx_layout sxau_vgm_wait;
extern const sx_layout sxau_vgm_data_block;
extern const sx_layout sxau_vgm_pcm_seek;
extern const sx_layout sxau_vgm_dac_setup;
extern const sx_layout sxau_vgm_dac_data;
extern const sx_layout sxau_vgm_dac_frequency;
extern const sx_layout sxau_vgm_dac_start;
extern const sx_layout sxau_vgm_dac_stop;
extern const sx_layout sxau_vgm_dac_fast_start;
extern const sx_layout sxau_ac3_sync_info;
extern const sx_layout sxau_ac3_checksum2;
extern const sx_layout sxau_mp3_frame_header;
extern const sx_layout sxau_id3_header;
extern const sx_layout sxau_id3v23_frame;
extern const sx_layout sxau_id3v24_frame;
extern const sx_layout sxau_ape_descriptor;
extern const sx_layout sxau_ape_header;
extern const sx_layout sxau_ape_seek;
extern const sx_layout sxau_ape_tag;
extern const sx_layout sxau_ape_tag_item;
extern const sx_layout sxau_sdif_header;
extern const sx_layout sxau_sdif_frame;
extern const sx_layout sxau_sdif_matrix;
extern const sx_layout sxau_sap_binary_marker;
extern const sx_layout sxau_sap_load_segment;
extern const sx_layout sxau_sc68_header;
extern const sx_layout sxau_sc68_chunk;
extern const sx_layout sxau_sc68_default;
extern const sx_layout sxau_sc68_load_address;
extern const sx_layout sxau_sc68_integer;
extern const sx_layout sxau_amiga_ahx_header;
extern const sx_layout sxau_amiga_ahx_subsong;
extern const sx_layout sxau_amiga_ahx_channel_order;
extern const sx_layout sxau_amiga_ahx_instrument;
extern const sx_layout sxau_amiga_ahx_playlist;
extern const sx_layout sxau_vab_header;
extern const sx_layout sxau_vab_program;
extern const sx_layout sxau_vab_tone;
extern const sx_layout sxau_vab_sample_size;
extern const sx_layout sxau_ay_header;
extern const sx_layout sxau_ay_track_index;
extern const sx_layout sxau_ay_track;
extern const sx_layout sxau_ay_cpu_state;
extern const sx_layout sxau_ay_block;
extern const sx_layout sxau_ay_blocks_end;
extern const sx_layout sxau_fsb1_header;
extern const sx_layout sxau_fsb1_sample;
extern const sx_layout sxau_fsb2_header;
extern const sx_layout sxau_fsb34_version;
extern const sx_layout sxau_fsb4_hash;
extern const sx_layout sxau_fsb_sample;
extern const sx_layout sxau_fsb_sample_basic;
extern const sx_layout sxau_fsb5_header;
extern const sx_layout sxau_fsb5_sample;
extern const sx_layout sxau_fsb5_chunk;
extern const sx_layout sxau_fsb5_channels;
extern const sx_layout sxau_fsb5_frequency;
extern const sx_layout sxau_fsb5_name_offset;
extern const sx_layout sxau_acm_header;
extern const sx_layout sxau_cri_ahx_header;
extern const sx_layout sxau_cri_ahx_copyright;
extern const sx_layout sxau_cri_ahx_footer;
extern const sx_layout sxau_dss_header;
extern const sx_layout sxau_ea_block_le;
extern const sx_layout sxau_nitro_header_le;
extern const sx_layout sxau_nitro_chunk_le;
extern const sx_layout sxau_nitro_stream_le;
extern const sx_layout sxau_paf_header_le;
extern const sx_layout sxau_ea_block_be;
extern const sx_layout sxau_nitro_header_be;
extern const sx_layout sxau_nitro_chunk_be;
extern const sx_layout sxau_nitro_stream_be;
extern const sx_layout sxau_paf_header_be;
extern const sx_layout sxau_abylight_header;
extern const sx_layout sxau_alp_header;
extern const sx_layout sxau_alp_sample_rate;
extern const sx_layout sxau_pmm_header;
extern const sx_layout sxau_pmm_sample;
extern const sx_layout sxau_pmm_instrument;
bool sxau_need(sxau_view *v,size_t at,uint64_t n,size_t end);
uint16_t sxau_u16(const uint8_t*p,bool be);
uint32_t sxau_u32(const uint8_t*p,bool be);
bool sxau_row(sxau_view *v,const sx_layout*l,size_t at,size_t end);
bool sxau_table(sxau_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end);
bool sxau_adts(sxau_view*v,size_t at,size_t end);

/* Per-format walkers, called by the family's build. */
bool sx_cri_awb_build(sxau_view*v);  /* audio/cri_awb/xx_cri_awb_data.c */
bool sx_microsoft_xwb_build(sxau_view*v);  /* audio/microsoft_xwb/xx_microsoft_xwb_data.c */
bool sx_microsoft_xsb_build(sxau_view*v);  /* audio/microsoft_xsb/xx_microsoft_xsb_data.c */
bool sx_audio_ast_build(sxau_view*v);  /* audio/audio_ast/xx_audio_ast_data.c */
bool sx_audio_hca_build(sxau_view*v);  /* audio/audio_hca/xx_audio_hca_data.c */
bool sx_iff_8svx_build(sxau_view*v);  /* audio/iff_8svx/xx_iff_8svx_data.c */
bool sx_vgm_log_build(sxau_view*v);  /* audio/vgm_log/xx_vgm_log_data.c */
bool sx_audio_dolby_ac3_build(sxau_view*v);  /* audio/audio_dolby_ac3/xx_audio_dolby_ac3_data.c */
bool sx_audio_mpeg_mp3_build(sxau_view*v);  /* audio/audio_mpeg_mp3/xx_audio_mpeg_mp3_data.c */
bool sx_audio_aac_adts_build(sxau_view*v);  /* audio/audio_aac_adts/xx_audio_aac_adts_data.c */
bool sx_audio_monkeys_ape_build(sxau_view*v);  /* audio/audio_monkeys_ape/xx_audio_monkeys_ape_data.c */
bool sx_ircam_sdif_build(sxau_view*v);  /* audio/ircam_sdif/xx_ircam_sdif_data.c */
bool sx_atari_sap_build(sxau_view*v);  /* audio/atari_sap/xx_atari_sap_data.c */
bool sx_sc68_music_build(sxau_view*v);  /* audio/sc68_music/xx_sc68_music_data.c */
bool sx_amiga_ahx_build(sxau_view*v);  /* audio/amiga_ahx/xx_amiga_ahx_data.c */
bool sx_sony_vab_build(sxau_view*v);  /* audio/sony_vab/xx_sony_vab_data.c */
bool sx_zx_ayemul_build(sxau_view*v);  /* audio/zx_ayemul/xx_zx_ayemul_data.c */
bool sx_fmod_sample_bank_build(sxau_view*v);  /* audio/fmod_sample_bank/xx_fmod_sample_bank_data.c */
bool sx_interplay_acm_build(sxau_view*v);  /* audio/interplay_acm/xx_interplay_acm_data.c */
bool sx_cri_ahx_build(sxau_view*v);  /* audio/cri_ahx/xx_cri_ahx_data.c */
bool sx_olympus_dss_build(sxau_view*v);  /* audio/olympus_dss/xx_olympus_dss_data.c */
bool sx_ea_exa_build(sxau_view*v);  /* audio/ea_exa/xx_ea_exa_data.c */
bool sx_audio_nitro_strm_build(sxau_view*v);  /* audio/audio_nitro_strm/xx_audio_nitro_strm_data.c */
bool sx_ensoniq_paf_build(sxau_view*v);  /* audio/ensoniq_paf/xx_ensoniq_paf_data.c */
bool sx_abylight_strm_build(sxau_view*v);  /* audio/abylight_strm/xx_abylight_strm_data.c */
bool sx_lego_alp_build(sxau_view*v);  /* audio/lego_alp/xx_lego_alp_data.c */
bool sx_parsec_pmm_build(sxau_view*v);  /* audio/parsec_pmm/xx_parsec_pmm_data.c */

#endif
