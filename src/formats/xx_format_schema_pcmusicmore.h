/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The pcmusicmore schema family: what its family unit (xx_format_schema_pcmusicmore.c)
 * and its formats' data files share. Formats: DIE_MUSIC_WEBFOOT_DSMIAMFHACK; DIE_MUSIC_SAHARASURFERS_IXALANCE_CO; DIE_MUSIC_CULCHAN_MDC; DIE_MUSIC_MULTITRACKCONTAINER; DIE_MUSIC_BAKTERY_SKALETRACKER_SKM; DIE_MUSIC_GARGAJ_MVX_MVM. */
#ifndef XX_FORMAT_SCHEMA_PCMUSICMORE_H
#define XX_FORMAT_SCHEMA_PCMUSICMORE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxpcmore_pcmore_text;
extern const sx_layout sxpcmore_webfoot_dmf_header;
extern const sx_layout sxpcmore_webfoot_dmf_panning;
extern const sx_layout sxpcmore_webfoot_dmf_timing;
extern const sx_layout sxpcmore_webfoot_dmf_order;
extern const sx_layout sxpcmore_webfoot_dmf_track_reference;
extern const sx_layout sxpcmore_webfoot_dmf_sample;
extern const sx_layout sxpcmore_webfoot_dmf_track_map;
extern const sx_layout sxpcmore_webfoot_dmf_track;
extern const sx_layout sxpcmore_webfoot_dmf_event;
extern const sx_layout sxpcmore_ixs_compressed_header;
extern const sx_layout sxpcmore_mdc_header;
extern const sx_layout sxpcmore_mdc_track_count;
extern const sx_layout sxpcmore_mdc_track;
extern const sx_layout sxpcmore_mtc_chunk;
extern const sx_layout sxpcmore_skm_chunk;
extern const sx_layout sxpcmore_skm_file_payload;
extern const sx_layout sxpcmore_skm_song_timing;
extern const sx_layout sxpcmore_skm_title;
extern const sx_layout sxpcmore_skm_message;
extern const sx_layout sxpcmore_skm_orders;
extern const sx_layout sxpcmore_skm_pattern;
extern const sx_layout sxpcmore_skm_track_chunk;
extern const sx_layout sxpcmore_skm_channel;
extern const sx_layout sxpcmore_mvx_header;
extern const sx_layout sxpcmore_mvx_machine_id;
extern const sx_layout sxpcmore_mvx_machine_order;
extern const sx_layout sxpcmore_mvx_connection_count;
extern const sx_layout sxpcmore_mvx_connection;
bool sxpcmore_span(sx_context*c,uint64_t p,uint64_t n);
bool sxpcmore_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxpcmore16(const uint8_t*b);
bool sxpcmore_u8(sx_context*c,uint64_t p,uint8_t*v);
uint64_t sxpcmore_width(const sx_layout*l);
bool sxpcmore_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxpcmore_finish(sx_context*c);
uint32_t sxpcmore_be32(const uint8_t*b);

/* Per-format walkers, called by the family's build. */
bool sx_webfoot_dsmiamfhack_build(sx_context *c);  /* audio/die_music/webfoot_dsmiamfhack/xx_webfoot_dsmiamfhack_data.c */
bool sx_saharasurfers_ixalance_co_build(sx_context *c);  /* audio/die_music/saharasurfers_ixalance_co/xx_saharasurfers_ixalance_co_data.c */
bool sx_culchan_mdc_build(sx_context *c);  /* audio/die_music/culchan_mdc/xx_culchan_mdc_data.c */
bool sx_multitrackcontainer_build(sx_context *c);  /* audio/die_music/multitrackcontainer/xx_multitrackcontainer_data.c */
bool sx_baktery_skaletracker_skm_build(sx_context *c);  /* audio/die_music/baktery_skaletracker_skm/xx_baktery_skaletracker_skm_data.c */
bool sx_gargaj_mvx_mvm_build(sx_context *c);  /* audio/die_music/gargaj_mvx_mvm/xx_gargaj_mvx_mvm_data.c */

#endif
