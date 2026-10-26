/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The gamearchives schema family: what its family unit (xx_format_schema_gamearchives.c)
 * and its formats' data files share. Formats: hog2; volitionvpft; wintermutedcp; cat; sar_ns; ns2; nsa; maxis_far_archive; valve_xzp; pbo; goldsrc_bsp; majiro; nexas_pac; telltale_ttarch; wux; stunts; ea; earefpack; agis; teacy; settlersft; wolfft; silmarilsft; infogramesft; ppd; epf. */
#ifndef XX_FORMAT_SCHEMA_GAMEARCHIVES_H
#define XX_FORMAT_SCHEMA_GAMEARCHIVES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxga_view {sx_context*c;unsigned work;}sxga_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxga_name_length8;
extern const sx_layout sxga_name_length32;
extern const sx_layout sxga_count32;
extern const sx_layout sxga_offset32;
extern const sx_layout sxga_length16;
extern const sx_layout sxga_hog2_header;
extern const sx_layout sxga_hog2_entry;
extern const sx_layout sxga_vp_header;
extern const sx_layout sxga_vp_entry;
extern const sx_layout sxga_cat_entry;
extern const sx_layout sxga_teacy_entry;
extern const sx_layout sxga_settlers_header;
extern const sx_layout sxga_settlers_slot;
extern const sx_layout sxga_wolf_header;
extern const sx_layout sxga_ea_entry;
extern const sx_layout sxga_agis_entry;
extern const sx_layout sxga_epf_header;
extern const sx_layout sxga_epf_entry;
extern const sx_layout sxga_ppd_entry;
extern const sx_layout sxga_wux_header;
extern const sx_layout sxga_wux_block;
extern const sx_layout sxga_refpack_header24;
extern const sx_layout sxga_refpack_header24_packed;
extern const sx_layout sxga_refpack_header32;
extern const sx_layout sxga_refpack_header32_packed;
extern const sx_layout sxga_stunts_header;
extern const sx_layout sxga_stunts_pass;
extern const sx_layout sxga_stunts_rle;
extern const sx_layout sxga_stunts_vle;
extern const sx_layout sxga_stunts_escape;
extern const sx_layout sxga_stunts_level;
extern const sx_layout sxga_stunts_symbol;
extern const sx_layout sxga_silmarils_header_le;
extern const sx_layout sxga_silmarils_header_be;
extern const sx_layout sxga_silmarils_offset_widths;
extern const sx_layout sxga_ns2_header;
extern const sx_layout sxga_ns2_size;
extern const sx_layout sxga_ns2_quote;
extern const sx_layout sxga_ns2_end;
extern const sx_layout sxga_dcp_header;
extern const sx_layout sxga_dcp_directory_offset;
extern const sx_layout sxga_dcp_directory;
extern const sx_layout sxga_dcp_entry1;
extern const sx_layout sxga_dcp_entry2;
extern const sx_layout sxga_far_header;
extern const sx_layout sxga_far_entry16;
extern const sx_layout sxga_far_entry32;
extern const sx_layout sxga_xzp_header;
extern const sx_layout sxga_xzp_entry;
extern const sx_layout sxga_xzp_mapping;
extern const sx_layout sxga_xzp_name;
extern const sx_layout sxga_xzp_footer;
extern const sx_layout sxga_pbo_entry;
extern const sx_layout sxga_majiro_header;
extern const sx_layout sxga_majiro_entry1;
extern const sx_layout sxga_majiro_entry2;
extern const sx_layout sxga_majiro_entry3;
extern const sx_layout sxga_nexas_header;
extern const sx_layout sxga_nexas_entry32;
extern const sx_layout sxga_nexas_entry64;
extern const sx_layout sxga_nexas_footer;
extern const sx_layout sxga_tt_nctt;
extern const sx_layout sxga_tt_chunked;
extern const sx_layout sxga_tt_chunk_offset;
extern const sx_layout sxga_tt_header3;
extern const sx_layout sxga_tt_header4;
extern const sx_layout sxga_tt_entry;
extern const sx_layout sxga_ipak_offset;
extern const sx_layout sxga_ipak_entry;
extern const sx_layout sxga_ipak_local_crumb;
extern const sx_layout sxga_ipak_central_crumb;
extern const sx_layout sxga_ipak_inline_prefix;
extern const sx_layout sxga_bsp_header;
extern const sx_layout sxga_bsp_lump;
extern const sx_layout sxga_bsp_plane;
extern const sx_layout sxga_bsp_vertex;
extern const sx_layout sxga_bsp_node;
extern const sx_layout sxga_bsp_texinfo;
extern const sx_layout sxga_bsp_face;
extern const sx_layout sxga_bsp_clipnode;
extern const sx_layout sxga_bsp_leaf;
extern const sx_layout sxga_bsp_marksurface;
extern const sx_layout sxga_bsp_edge;
extern const sx_layout sxga_bsp_surfedge;
extern const sx_layout sxga_bsp_model;
extern const sx_layout sxga_bsp_textures;
extern const sx_layout sxga_bsp_texture_offset;
extern const sx_layout sxga_bsp_miptex;
extern const sx_layout sxga_bsp_palette;
extern const sx_layout sxga_bsp_color;
bool sxga_span(sxga_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxga_read(sxga_view*v,uint64_t at,void*p,size_t n,uint64_t end);
bool sxga_word(sxga_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end);
bool sxga_row(sxga_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxga_table(sxga_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxga_cstring(sxga_view*v,uint64_t*p,uint64_t end,uint64_t max);
bool sxga_named(sxga_view*v,uint64_t at,uint64_t n,uint64_t end,bool encoded);
bool sxga_counted(sxga_view*v,const sx_layout*l);
bool sxga_ns(sxga_view*v,bool nsa);

/* Per-format walkers, called by the family's build. */
bool sx_hog2_build(sxga_view*v);  /* game/hog2/xx_hog2_data.c */
bool sx_volitionvpft_build(sxga_view*v);  /* game/volitionvpft/xx_volitionvpft_data.c */
bool sx_wintermutedcp_build(sxga_view*v);  /* game/wintermutedcp/xx_wintermutedcp_data.c */
bool sx_cat_build(sxga_view*v);  /* game/cat/xx_cat_data.c */
bool sx_sar_ns_build(sxga_view*v);  /* game/sar_ns/xx_sar_ns_data.c */
bool sx_ns2_build(sxga_view*v);  /* game/ns2/xx_ns2_data.c */
bool sx_nsa_build(sxga_view*v);  /* game/nsa/xx_nsa_data.c */
bool sx_maxis_far_archive_build(sxga_view*v);  /* game/maxis_far_archive/xx_maxis_far_archive_data.c */
bool sx_valve_xzp_build(sxga_view*v);  /* game/valve_xzp/xx_valve_xzp_data.c */
bool sx_pbo_build(sxga_view*v);  /* game/pbo/xx_pbo_data.c */
bool sx_goldsrc_bsp_build(sxga_view*v);  /* game/goldsrc_bsp/xx_goldsrc_bsp_data.c */
bool sx_majiro_build(sxga_view*v);  /* game/majiro/xx_majiro_data.c */
bool sx_nexas_pac_build(sxga_view*v);  /* game/nexas_pac/xx_nexas_pac_data.c */
bool sx_telltale_ttarch_build(sxga_view*v);  /* game/telltale_ttarch/xx_telltale_ttarch_data.c */
bool sx_wux_build(sxga_view*v);  /* game/wux/xx_wux_data.c */
bool sx_stunts_build(sxga_view*v);  /* game/stunts/xx_stunts_data.c */
bool sx_ea_build(sxga_view*v);  /* game/ea/xx_ea_data.c */
bool sx_earefpack_build(sxga_view*v);  /* game/earefpack/xx_earefpack_data.c */
bool sx_agis_build(sxga_view*v);  /* game/agis/xx_agis_data.c */
bool sx_teacy_build(sxga_view*v);  /* game/teacy/xx_teacy_data.c */
bool sx_settlersft_build(sxga_view*v);  /* game/settlersft/xx_settlersft_data.c */
bool sx_wolfft_build(sxga_view*v);  /* game/wolfft/xx_wolfft_data.c */
bool sx_silmarilsft_build(sxga_view*v);  /* game/silmarilsft/xx_silmarilsft_data.c */
bool sx_infogramesft_build(sxga_view*v);  /* game/infogramesft/xx_infogramesft_data.c */
bool sx_ppd_build(sxga_view*v);  /* game/ppd/xx_ppd_data.c */
bool sx_epf_build(sxga_view*v);  /* game/epf/xx_epf_data.c */

#endif
