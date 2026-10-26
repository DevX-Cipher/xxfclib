/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivesystems schema family: what its family unit (xx_format_schema_archivesystems.c)
 * and its formats' data files share. Formats: ARC v2; ARC v4; CRU; PowerBoard BBS; FLD; IGF1; IGF2; InterEdu FT; JM93; MIZ; MVA; POV-Lab LZH; QIP1; Quarterdeck QP; RCF; RiverSoft; TGCF; TRC; NetWare packed; NetWare 2. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVESYSTEMS_H
#define XX_FORMAT_SCHEMA_ARCHIVESYSTEMS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

#define SXASY_LIMIT 20000U

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxasy_arcv2_header;
extern const sx_layout sxasy_arcv2_block;
extern const sx_layout sxasy_arcv2_attributes;
extern const sx_layout sxasy_arcv4_header;
extern const sx_layout sxasy_arcv4_record;
extern const sx_layout sxasy_arcv4_tag_size;
extern const sx_layout sxasy_arcv4_name_size;
extern const sx_layout sxasy_arcv4_attributes;
extern const sx_layout sxasy_arcv4_data;
extern const sx_layout sxasy_cru_header;
extern const sx_layout sxasy_cru_entry;
extern const sx_layout sxasy_powerbbs_name;
extern const sx_layout sxasy_powerbbs_size1;
extern const sx_layout sxasy_powerbbs_size2;
extern const sx_layout sxasy_powerbbs_size4;
extern const sx_layout sxasy_fld_member;
extern const sx_layout sxasy_igf1_header;
extern const sx_layout sxasy_igf2_header;
extern const sx_layout sxasy_igf2_member56;
extern const sx_layout sxasy_igf2_member44;
extern const sx_layout sxasy_igf2_end;
extern const sx_layout sxasy_inteduft_header;
extern const sx_layout sxasy_inteduft_index;
extern const sx_layout sxasy_inteduft_member;
extern const sx_layout sxasy_jm93_header;
extern const sx_layout sxasy_miz_header;
extern const sx_layout sxasy_miz_member;
extern const sx_layout sxasy_mva_header;
extern const sx_layout sxasy_mva_member;
extern const sx_layout sxasy_povlab_header;
extern const sx_layout sxasy_povlab_attributes;
extern const sx_layout sxasy_povlab_extension_size;
extern const sx_layout sxasy_povlab_extension_type;
extern const sx_layout sxasy_qip1_member;
extern const sx_layout sxasy_qp_header;
extern const sx_layout sxasy_qp_index;
extern const sx_layout sxasy_qp_path;
extern const sx_layout sxasy_qp_member;
extern const sx_layout sxasy_rcf_header;
extern const sx_layout sxasy_rcf_entry;
extern const sx_layout sxasy_rcf_count;
extern const sx_layout sxasy_riversoft_header;
extern const sx_layout sxasy_riversoft_entry;
extern const sx_layout sxasy_tgcf_header;
extern const sx_layout sxasy_tgcf_list_offset;
extern const sx_layout sxasy_tgcf_crc;
extern const sx_layout sxasy_tgcf_member_prefix;
extern const sx_layout sxasy_tgcf_member_attributes;
extern const sx_layout sxasy_tgcf_member_flag;
extern const sx_layout sxasy_tgcf_payload_offset;
extern const sx_layout sxasy_trc_header;
extern const sx_layout sxasy_netwarepacked_header;
extern const sx_layout sxasy_netware2_record;
extern const sx_layout sxasy_netware2_metadata;
extern const sx_layout sxasy_netware2_packed;
extern const sx_layout sxasy_miz_footer;
bool sxasy_span(sx_context*c,uint64_t p,uint64_t n);
bool sxasy_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxasy_uint(const uint8_t*b,unsigned n,bool be);
bool sxasy_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxasy_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxasy_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap);
bool sxasy_dcl(sx_context*c,uint64_t p,uint64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_arcv2_build(sx_context *c);  /* installer/arcv2/xx_arcv2_data.c */
bool sx_arcv4_build(sx_context *c);  /* installer/arcv4/xx_arcv4_data.c */
bool sx_cru_build(sx_context *c);  /* archive/cru/xx_cru_data.c */
bool sx_powerboardbbs_build(sx_context *c);  /* archive/powerboardbbs/xx_powerboardbbs_data.c */
bool sx_fld_build(sx_context *c);  /* installer/fld/xx_fld_data.c */
bool sx_igf1_build(sx_context *c);  /* archive/igf1/xx_igf1_data.c */
bool sx_igf2_build(sx_context *c);  /* installer/igf2/xx_igf2_data.c */
bool sx_inteduft_build(sx_context *c);  /* archive/inteduft/xx_inteduft_data.c */
bool sx_jm93_build(sx_context *c);  /* archive/jm93/xx_jm93_data.c */
bool sx_miz_build(sx_context *c);  /* archive/miz/xx_miz_data.c */
bool sx_mva_build(sx_context *c);  /* installer/mva/xx_mva_data.c */
bool sx_povlablzh_build(sx_context *c);  /* archive/povlablzh/xx_povlablzh_data.c */
bool sx_qip1_build(sx_context *c);  /* installer/qip1/xx_qip1_data.c */
bool sx_quarterdeckqp_build(sx_context *c);  /* installer/quarterdeckqp/xx_quarterdeckqp_data.c */
bool sx_rcf_build(sx_context *c);  /* installer/rcf/xx_rcf_data.c */
bool sx_riversoft_build(sx_context *c);  /* archive/riversoft/xx_riversoft_data.c */
bool sx_tgcf_build(sx_context *c);  /* archive/tgcf/xx_tgcf_data.c */
bool sx_trc_build(sx_context *c);  /* archive/trc/xx_trc_data.c */
bool sx_netwarepacked_build(sx_context *c);  /* archive/netwarepacked/xx_netwarepacked_data.c */
bool sx_netware2_build(sx_context *c);  /* installer/netware2/xx_netware2_data.c */

#endif
