/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musiclate schema family: what its family unit (xx_format_schema_musiclate.c)
 * and its formats' data files share. Formats: Stepanov Buzzic2; Rhino Jaytraxsyntrax Jxs; Saharasurfers Ixalance Ixs Unp; Msxperformer Opx; Tran Cdfm Composer670 Co; Microdeal Quartet Smp; Originsystems Ultima6. */
#ifndef XX_FORMAT_SCHEMA_MUSICLATE_H
#define XX_FORMAT_SCHEMA_MUSICLATE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxlate_buzz2_header;
extern const sx_layout sxlate_buzz2_counts;
extern const sx_layout sxlate_buzz2_capacities;
extern const sx_layout sxlate_buzz2_pattern;
extern const sx_layout sxlate_buzz2_sequence;
extern const sx_layout sxlate_buzz2_name;
extern const sx_layout sxlate_buzz2_instrument_count;
extern const sx_layout sxlate_buzz2_instrument;
extern const sx_layout sxlate_buzz2_connection;
extern const sx_layout sxlate_buzz2_instrument_tail;
extern const sx_layout sxlate_buzz2_operation;
extern const sx_layout sxlate_jxs_header;
extern const sx_layout sxlate_jxs_subsong;
extern const sx_layout sxlate_jxs_order;
extern const sx_layout sxlate_jxs_event;
extern const sx_layout sxlate_jxs_pattern_name_size;
extern const sx_layout sxlate_jxs_pattern_name;
extern const sx_layout sxlate_jxs_instrument;
extern const sx_layout sxlate_jxs_effect;
extern const sx_layout sxlate_jxs_sample_info;
extern const sx_layout sxlate_jxs_wave;
extern const sx_layout sxlate_jxs_arpeggio;
extern const sx_layout sxlate_ixs_header;
extern const sx_layout sxlate_ixs_orders;
extern const sx_layout sxlate_ixs_record_tag;
extern const sx_layout sxlate_ixs_instrument;
extern const sx_layout sxlate_ixs_keyboard;
extern const sx_layout sxlate_ixs_envelope_flags;
extern const sx_layout sxlate_ixs_envelope;
extern const sx_layout sxlate_ixs_envelope_point;
extern const sx_layout sxlate_ixs_sample;
extern const sx_layout sxlate_ixs_pattern;
extern const sx_layout sxlate_opx_text_header;
extern const sx_layout sxlate_opx_info;
extern const sx_layout sxlate_c670_header;
extern const sx_layout sxlate_c670_sample;
extern const sx_layout sxlate_c670_fm_instrument;
extern const sx_layout sxlate_c670_orders;
extern const sx_layout sxlate_c670_pattern_offset;
extern const sx_layout sxlate_c670_note;
extern const sx_layout sxlate_c670_volume;
extern const sx_layout sxlate_c670_delay;
extern const sx_layout sxlate_c670_end;
extern const sx_layout sxlate_quartet_header;
extern const sx_layout sxlate_quartet_sequence;
extern const sx_layout sxlate_ultima6_header;
bool sxlate_span(sx_context*c,uint64_t p,uint64_t n,uint64_t end);
bool sxlate_read(sx_context*c,uint64_t p,void*b,size_t n,uint64_t end);
bool sxlate_byte(sx_context*c,uint64_t p,uint8_t*b,uint64_t end);
bool sxlate_row(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,uint64_t end);
bool sxlate_plane(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t n,uint64_t end);
bool sxlate_table(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t stride,uint64_t count,uint64_t end);
bool sxlate_u32(sx_context*c,uint64_t p,uint32_t*v,uint64_t end);

/* Per-format walkers, called by the family's build. */
bool sx_stepanov_buzzic2_build(sx_context *c);  /* audio/die_music/stepanov_buzzic2/xx_stepanov_buzzic2_data.c */
bool sx_rhino_jaytraxsyntrax_jxs_build(sx_context *c);  /* audio/die_music/rhino_jaytraxsyntrax_jxs/xx_rhino_jaytraxsyntrax_jxs_data.c */
bool sx_saharasurfers_ixalance_ixs_unp_build(sx_context *c);  /* audio/die_music/saharasurfers_ixalance_ixs_unp/xx_saharasurfers_ixalance_ixs_unp_data.c */
bool sx_msxperformer_opx_build(sx_context *c);  /* audio/die_music/msxperformer_opx/xx_msxperformer_opx_data.c */
bool sx_tran_cdfm_composer670_co_build(sx_context *c);  /* audio/die_music/tran_cdfm_composer670_co/xx_tran_cdfm_composer670_co_data.c */
bool sx_microdeal_quartet_smp_build(sx_context *c);  /* audio/die_music/microdeal_quartet_smp/xx_microdeal_quartet_smp_data.c */
bool sx_originsystems_ultima6_build(sx_context *c);  /* audio/die_music/originsystems_ultima6/xx_originsystems_ultima6_data.c */

#endif
