/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archiveobsolete schema family: what its family unit (xx_format_schema_archiveobsolete.c)
 * and its formats' data files share. Formats: SW; DSL2; TOPSPEED; ULEAD; QUANTUM; C64WRAPTOR; CORELLTEC; RSVK; ARCV; BCW; SCF; RECOGNITA; JASC; BND; SMSIPAK; CPX / CPX4; RED; AIAFF; SOFTPAQ2. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEOBSOLETE_H
#define XX_FORMAT_SCHEMA_ARCHIVEOBSOLETE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxao_sw_header;
extern const sx_layout sxao_archiveobsolete_name;
extern const sx_layout sxao_archiveobsolete_path;
extern const sx_layout sxao_dsl2_header;
extern const sx_layout sxao_dsl2_path_length;
extern const sx_layout sxao_dsl2_member;
extern const sx_layout sxao_dsl2_name_length;
extern const sx_layout sxao_dsl2_name;
extern const sx_layout sxao_topspeed_block;
extern const sx_layout sxao_ulead_prefix;
extern const sx_layout sxao_ulead_name;
extern const sx_layout sxao_ulead_block_counts;
extern const sx_layout sxao_ulead_block_size;
extern const sx_layout sxao_quantum_header;
extern const sx_layout sxao_quantum_length1;
extern const sx_layout sxao_quantum_length2;
extern const sx_layout sxao_quantum_member;
extern const sx_layout sxao_quantum_crc16;
extern const sx_layout sxao_corelltec_header;
extern const sx_layout sxao_rsvk_container;
extern const sx_layout sxao_rsvk_block;
extern const sx_layout sxao_rsvk_member;
extern const sx_layout sxao_rsvk_trailer;
extern const sx_layout sxao_arcv_header;
extern const sx_layout sxao_arcv_member;
extern const sx_layout sxao_arcv_chunk;
extern const sx_layout sxao_bcw_header;
extern const sx_layout sxao_bcw_record;
extern const sx_layout sxao_bcw_time;
extern const sx_layout sxao_scf_header;
extern const sx_layout sxao_scf_member;
extern const sx_layout sxao_recognita_member;
extern const sx_layout sxao_jasc_member;
extern const sx_layout sxao_jasc_end;
extern const sx_layout sxao_bnd_header;
extern const sx_layout sxao_bnd_record;
extern const sx_layout sxao_bnd_prologue;
extern const sx_layout sxao_bnd_member_tail;
extern const sx_layout sxao_bnd_trailer;
extern const sx_layout sxao_smsipak_header;
extern const sx_layout sxao_smsipak_member;
extern const sx_layout sxao_smsipak_index;
extern const sx_layout sxao_smsipak_index_entry;
extern const sx_layout sxao_cpx_header;
extern const sx_layout sxao_cpx_member;
extern const sx_layout sxao_cpx4_header;
extern const sx_layout sxao_cpx4_member;
extern const sx_layout sxao_red_member;
extern const sx_layout sxao_red_header_crc;
extern const sx_layout sxao_red_segment_crc;
extern const sx_layout sxao_aiaff_header;
extern const sx_layout sxao_aiaff_member;
extern const sx_layout sxao_aiaff_terminator;
extern const sx_layout sxao_softpaq2_locator;
extern const sx_layout sxao_softpaq2_stored;
extern const sx_layout sxao_softpaq2_compressed;
bool sxao_span(sx_context*c,uint64_t p,uint64_t n);
bool sxao_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxao_uint(const uint8_t*b,unsigned n,bool be);
bool sxao_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxao_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxao_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxao_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxao_zlen(sx_context*c,uint64_t p,uint64_t end,uint64_t*n);
bool sxao_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n);
bool sxao_dcl(sx_context*c,uint64_t p,uint64_t n);
bool sxao_native_members(sx_context*c);

/* Per-format walkers, called by the family's build. */
bool sx_sw_build(sx_context *c);  /* installer/sw/xx_sw_data.c */
bool sx_dsl2_build(sx_context *c);  /* installer/dsl2/xx_dsl2_data.c */
bool sx_topspeed_build(sx_context *c);  /* installer/topspeed/xx_topspeed_data.c */
bool sx_ulead_build(sx_context *c);  /* archive/ulead/xx_ulead_data.c */
bool sx_quantum_build(sx_context *c);  /* archive/quantum/xx_quantum_data.c */
bool sx_c64wraptor_build(sx_context *c);  /* archive/c64wraptor/xx_c64wraptor_data.c */
bool sx_corelltec_build(sx_context *c);  /* installer/corelltec/xx_corelltec_data.c */
bool sx_rsvk_build(sx_context *c);  /* archive/rsvk/xx_rsvk_data.c */
bool sx_arcv_build(sx_context *c);  /* installer/arcv/xx_arcv_data.c */
bool sx_bcw_build(sx_context *c);  /* installer/bcw/xx_bcw_data.c */
bool sx_scf_build(sx_context *c);  /* installer/scf/xx_scf_data.c */
bool sx_recognita_build(sx_context *c);  /* installer/recognita/xx_recognita_data.c */
bool sx_jasc_build(sx_context *c);  /* installer/jasc/xx_jasc_data.c */
bool sx_bnd_build(sx_context *c);  /* installer/bnd/xx_bnd_data.c */
bool sx_smsipak_build(sx_context *c);  /* installer/smsipak/xx_smsipak_data.c */
bool sx_cpx_build(sx_context *c);  /* archive/cpx/xx_cpx_data.c */
bool sx_red_build(sx_context *c);  /* installer/red/xx_red_data.c */
bool sx_aiaff_build(sx_context *c);  /* archive/aiaff/xx_aiaff_data.c */
bool sx_softpaq2_build(sx_context *c);  /* installer/softpaq2/xx_softpaq2_data.c */

#endif
