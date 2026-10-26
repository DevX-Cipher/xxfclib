/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The adlib schema family: what its family unit (xx_format_schema_adlib.c)
 * and its formats' data files share. Formats: AdLib RAD; AdLib HSC; AdLib D00; AdLib BNK; AdLib BAM; AdLib BMF; AdLib DFM; AdLib LDS; AdLib ROL; AdLib JBM; AdLib XSM; Ken Silverman KSM; RDOS RAW. */
#ifndef XX_FORMAT_SCHEMA_ADLIB_H
#define XX_FORMAT_SCHEMA_ADLIB_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxad_adlib_rad_header;
extern const sx_layout sxad_adlib_rad_instrument;
extern const sx_layout sxad_adlib_instrument_end;
extern const sx_layout sxad_adlib_rad_order_count;
extern const sx_layout sxad_adlib_rad_order;
extern const sx_layout sxad_adlib_rad_pattern_offset;
extern const sx_layout sxad_adlib_rad_row;
extern const sx_layout sxad_adlib_rad_event;
extern const sx_layout sxad_adlib_rad_effect_event;
extern const sx_layout sxad_adlib_hsc_instrument;
extern const sx_layout sxad_adlib_hsc_order;
extern const sx_layout sxad_adlib_hsc_event;
extern const sx_layout sxad_adlib_zero_terminator;
extern const sx_layout sxad_adlib_d00_header;
extern const sx_layout sxad_adlib_d00_subsong;
extern const sx_layout sxad_adlib_d00_order_header;
extern const sx_layout sxad_adlib_d00_order_word;
extern const sx_layout sxad_adlib_d00_sequence_offset;
extern const sx_layout sxad_adlib_d00_sequence_word;
extern const sx_layout sxad_adlib_d00_instrument;
extern const sx_layout sxad_adlib_d00_data_info_end;
extern const sx_layout sxad_adlib_bnk_header;
extern const sx_layout sxad_adlib_bnk_name;
extern const sx_layout sxad_adlib_bnk_instrument;
extern const sx_layout sxad_adlib_bam_header;
extern const sx_layout sxad_adlib_bam_command;
extern const sx_layout sxad_adlib_bam_note;
extern const sx_layout sxad_adlib_bam_instrument;
extern const sx_layout sxad_adlib_bam_jump;
extern const sx_layout sxad_adlib_bmf_signature;
extern const sx_layout sxad_adlib_bmf_settings;
extern const sx_layout sxad_adlib_bmf_instrument;
extern const sx_layout sxad_adlib_bmf_stream_flags;
extern const sx_layout sxad_adlib_bmf_note_or_control;
extern const sx_layout sxad_adlib_bmf_loop;
extern const sx_layout sxad_adlib_bmf_note_delay;
extern const sx_layout sxad_adlib_bmf_note_command;
extern const sx_layout sxad_adlib_bmf_note_delay_command;
extern const sx_layout sxad_adlib_dfm_header;
extern const sx_layout sxad_adlib_dfm_instrument_name;
extern const sx_layout sxad_adlib_dfm_instrument;
extern const sx_layout sxad_adlib_dfm_order;
extern const sx_layout sxad_adlib_dfm_pattern_count;
extern const sx_layout sxad_adlib_dfm_pattern_header;
extern const sx_layout sxad_adlib_dfm_note;
extern const sx_layout sxad_adlib_dfm_note_effect;
extern const sx_layout sxad_adlib_lds_header;
extern const sx_layout sxad_adlib_lds_patch;
extern const sx_layout sxad_adlib_lds_position_count;
extern const sx_layout sxad_adlib_lds_position;
extern const sx_layout sxad_adlib_lds_digital_count;
extern const sx_layout sxad_adlib_lds_pattern_word;
extern const sx_layout sxad_adlib_rol_header;
extern const sx_layout sxad_adlib_rol_tempo_count;
extern const sx_layout sxad_adlib_rol_tempo_event;
extern const sx_layout sxad_adlib_rol_note_header;
extern const sx_layout sxad_adlib_rol_note_event;
extern const sx_layout sxad_adlib_rol_event_header;
extern const sx_layout sxad_adlib_rol_instrument_event;
extern const sx_layout sxad_adlib_rol_volume_event;
extern const sx_layout sxad_adlib_rol_pitch_event;
extern const sx_layout sxad_adlib_jbm_header;
extern const sx_layout sxad_adlib_jbm_sequence_offset;
extern const sx_layout sxad_adlib_jbm_order;
extern const sx_layout sxad_adlib_jbm_end;
extern const sx_layout sxad_adlib_jbm_instrument_select;
extern const sx_layout sxad_adlib_jbm_note;
extern const sx_layout sxad_adlib_jbm_instrument;
extern const sx_layout sxad_adlib_xsm_header;
extern const sx_layout sxad_adlib_xsm_instrument;
extern const sx_layout sxad_adlib_xsm_note;
extern const sx_layout sxad_adlib_ksm_header;
extern const sx_layout sxad_adlib_ksm_event;
extern const sx_layout sxad_adlib_raw_header;
extern const sx_layout sxad_adlib_raw_command;
extern const sx_layout sxad_adlib_raw_timer;
extern const sx_layout sxad_adlib_raw_metadata_tag;
bool sxad_byte(sx_context *c,int64_t at,uint8_t *v);
bool sxad_tag(sx_context *c,int64_t at,const char *tag,size_t n);
bool sxad_zraw(sx_context *c,int64_t *at,size_t limit);
bool sxad_header(sx_context *c,const sx_layout *l,int64_t *at,int64_t size);

/* Per-format walkers, called by the family's build. */
bool sx_adlib_rad_build(sx_context *c);  /* audio/adlib_rad/xx_adlib_rad_data.c */
bool sx_adlib_hsc_build(sx_context *c);  /* audio/adlib_hsc/xx_adlib_hsc_data.c */
bool sx_adlib_d00_build(sx_context *c);  /* audio/adlib_d00/xx_adlib_d00_data.c */
bool sx_adlib_bnk_build(sx_context *c);  /* audio/adlib_bnk/xx_adlib_bnk_data.c */
bool sx_adlib_bam_build(sx_context *c);  /* audio/adlib_bam/xx_adlib_bam_data.c */
bool sx_adlib_bmf_build(sx_context *c);  /* audio/adlib_bmf/xx_adlib_bmf_data.c */
bool sx_adlib_dfm_build(sx_context *c);  /* audio/adlib_dfm/xx_adlib_dfm_data.c */
bool sx_adlib_lds_build(sx_context *c);  /* audio/adlib_lds/xx_adlib_lds_data.c */
bool sx_adlib_rol_build(sx_context *c);  /* audio/adlib_rol/xx_adlib_rol_data.c */
bool sx_adlib_jbm_build(sx_context *c);  /* audio/adlib_jbm/xx_adlib_jbm_data.c */
bool sx_adlib_xsm_build(sx_context *c);  /* audio/adlib_xsm/xx_adlib_xsm_data.c */
bool sx_ken_ksm_build(sx_context *c);  /* audio/ken_ksm/xx_ken_ksm_data.c */
bool sx_rdos_raw_build(sx_context *c);  /* audio/rdos_raw/xx_rdos_raw_data.c */

#endif
