/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The gamecontainers schema family: what its family unit (xx_format_schema_gamecontainers.c)
 * and its formats' data files share. Formats: krml; sci; seadata; stk; beatthehouse; battleisle; mxs; sinner; megatechvol; res; rsc; visionaire_studio_vis; bgi; bgi2; cpk; dxa; livemaker; noa; rpg_maker_rgssad; stos_memory_bank; valve_gcf_cache; ypf; nitroplus_npk2; catsystem_kif; malie_lib; nitroplus_npa; qlie_pack. */
#ifndef XX_FORMAT_SCHEMA_GAMECONTAINERS_H
#define XX_FORMAT_SCHEMA_GAMECONTAINERS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxgco_view {sx_context*c;unsigned work;}sxgco_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxgco_filename_byte;
extern const sx_layout sxgco_encoded_byte;
extern const sx_layout sxgco_count16;
extern const sx_layout sxgco_offset32;
extern const sx_layout sxgco_size32;
extern const sx_layout sxgco_name_size32;
extern const sx_layout sxgco_krml_header;
extern const sx_layout sxgco_krml_entry;
extern const sx_layout sxgco_sci_header;
extern const sx_layout sxgco_sci_entry;
extern const sx_layout sxgco_seadata_header;
extern const sx_layout sxgco_seadata_entry;
extern const sx_layout sxgco_seadata_end;
extern const sx_layout sxgco_stk_entry;
extern const sx_layout sxgco_stk2_header;
extern const sx_layout sxgco_stk2_directory;
extern const sx_layout sxgco_stk2_entry;
extern const sx_layout sxgco_bth_header;
extern const sx_layout sxgco_battle_tct;
extern const sx_layout sxgco_battle_entry;
extern const sx_layout sxgco_mxs_entry;
extern const sx_layout sxgco_sinner_header;
extern const sx_layout sxgco_sinner_entry;
extern const sx_layout sxgco_res_entry;
extern const sx_layout sxgco_rsc_entry;
extern const sx_layout sxgco_vis_header_le;
extern const sx_layout sxgco_vis_header_be;
extern const sx_layout sxgco_vis_index_marker;
extern const sx_layout sxgco_vis_entry;
extern const sx_layout sxgco_dxa_header1;
extern const sx_layout sxgco_dxa_header4;
extern const sx_layout sxgco_dxa_header6;
extern const sx_layout sxgco_livemaker_header;
extern const sx_layout sxgco_livemaker_offset;
extern const sx_layout sxgco_livemaker_flags;
extern const sx_layout sxgco_livemaker_scramble;
extern const sx_layout sxgco_noa_header;
extern const sx_layout sxgco_noa_record;
extern const sx_layout sxgco_noa_entry;
extern const sx_layout sxgco_rgss_header;
extern const sx_layout sxgco_rgss_seed;
extern const sx_layout sxgco_rgss_name_size;
extern const sx_layout sxgco_rgss_data_size;
extern const sx_layout sxgco_rgss_entry3;
extern const sx_layout sxgco_rgss_end3;
extern const sx_layout sxgco_stos_header;
extern const sx_layout sxgco_stos_sprite;
extern const sx_layout sxgco_stos_sprite_param;
extern const sx_layout sxgco_stos_palette_header;
extern const sx_layout sxgco_stos_color;
extern const sx_layout sxgco_stos_icon_header;
extern const sx_layout sxgco_npk2_header;
extern const sx_layout sxgco_kif_header;
extern const sx_layout sxgco_kif_entry32;
extern const sx_layout sxgco_kif_entry64;
extern const sx_layout sxgco_malie_header;
extern const sx_layout sxgco_malieu_header;
extern const sx_layout sxgco_malie_entry;
extern const sx_layout sxgco_malieu_entry;
extern const sx_layout sxgco_ypf_header;
extern const sx_layout sxgco_ypf_name;
extern const sx_layout sxgco_ypf_fields;
extern const sx_layout sxgco_ypf_extra8;
extern const sx_layout sxgco_ypf_offset_high;
extern const sx_layout sxgco_npa_header;
extern const sx_layout sxgco_npa_name_size;
extern const sx_layout sxgco_npa_fields;
extern const sx_layout sxgco_qlie_footer;
extern const sx_layout sxgco_qlie_name_units;
extern const sx_layout sxgco_qlie_entry;
extern const sx_layout sxgco_cpk_packet;
extern const sx_layout sxgco_cpk_utf_header;
extern const sx_layout sxgco_cpk_utf_column;
extern const sx_layout sxgco_cpk_crilayla;
extern const sx_layout sxgco_gcf_header;
extern const sx_layout sxgco_gcf_block_header;
extern const sx_layout sxgco_gcf_block_entry;
extern const sx_layout sxgco_gcf_fragment_header;
extern const sx_layout sxgco_gcf_block_link;
extern const sx_layout sxgco_gcf_map_header;
extern const sx_layout sxgco_gcf_map_entry;
extern const sx_layout sxgco_gcf_directory_header;
extern const sx_layout sxgco_gcf_directory_file;
extern const sx_layout sxgco_gcf_directory_folder;
extern const sx_layout sxgco_gcf_directory_map;
extern const sx_layout sxgco_gcf_directory_link;
extern const sx_layout sxgco_gcf_checksum_header;
extern const sx_layout sxgco_gcf_data_header3;
extern const sx_layout sxgco_gcf_data_header5;
extern const sx_layout sxgco_noa_directory_record;
extern const sx_layout sxgco_noa_count;
extern const sx_layout sxgco_stos_icon;
extern const sx_layout sxgco_gcf_info_word;
extern const sx_layout sxgco_gcf_directory_index;
extern const sx_layout sxgco_gcf_checksum_map_header;
extern const sx_layout sxgco_gcf_checksum_map_entry;
extern const sx_layout sxgco_gcf_checksum;
bool sxgco_span(sxgco_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxgco_read(sxgco_view*v,uint64_t at,void*p,size_t n,uint64_t end);
bool sxgco_word(sxgco_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end);
bool sxgco_row(sxgco_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxgco_table(sxgco_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxgco_counted(sxgco_view*v,const sx_layout*l);
bool sxgco_bgi_common(sxgco_view*v,bool two);

/* Per-format walkers, called by the family's build. */
bool sx_krml_build(sxgco_view*v);  /* game/krml/xx_krml_data.c */
bool sx_sci_build(sxgco_view*v);  /* game/sci/xx_sci_data.c */
bool sx_seadata_build(sxgco_view*v);  /* game/seadata/xx_seadata_data.c */
bool sx_stk_build(sxgco_view*v);  /* game/stk/xx_stk_data.c */
bool sx_beatthehouse_build(sxgco_view*v);  /* game/beatthehouse/xx_beatthehouse_data.c */
bool sx_battleisle_build(sxgco_view*v);  /* game/battleisle/xx_battleisle_data.c */
bool sx_mxs_build(sxgco_view*v);  /* game/mxs/xx_mxs_data.c */
bool sx_sinner_build(sxgco_view*v);  /* game/sinner/xx_sinner_data.c */
bool sx_megatechvol_build(sxgco_view*v);  /* game/megatechvol/xx_megatechvol_data.c */
bool sx_res_build(sxgco_view*v);  /* game/res/xx_res_data.c */
bool sx_rsc_build(sxgco_view*v);  /* game/rsc/xx_rsc_data.c */
bool sx_visionaire_studio_vis_build(sxgco_view*v);  /* game/visionaire_studio_vis/xx_visionaire_studio_vis_data.c */
bool sx_bgi_build(sxgco_view*v);  /* game/bgi/xx_bgi_data.c */
bool sx_bgi2_build(sxgco_view*v);  /* game/bgi2/xx_bgi2_data.c */
bool sx_cpk_build(sxgco_view*v);  /* game/cpk/xx_cpk_data.c */
bool sx_dxa_build(sxgco_view*v);  /* game/dxa/xx_dxa_data.c */
bool sx_livemaker_build(sxgco_view*v);  /* game/livemaker/xx_livemaker_data.c */
bool sx_noa_build(sxgco_view*v);  /* game/noa/xx_noa_data.c */
bool sx_rpg_maker_rgssad_build(sxgco_view*v);  /* game/rpg_maker_rgssad/xx_rpg_maker_rgssad_data.c */
bool sx_stos_memory_bank_build(sxgco_view*v);  /* game/stos_memory_bank/xx_stos_memory_bank_data.c */
bool sx_valve_gcf_cache_build(sxgco_view*v);  /* game/valve_gcf_cache/xx_valve_gcf_cache_data.c */
bool sx_ypf_build(sxgco_view*v);  /* game/ypf/xx_ypf_data.c */
bool sx_nitroplus_npk2_build(sxgco_view*v);  /* game/nitroplus_npk2/xx_nitroplus_npk2_data.c */
bool sx_catsystem_kif_build(sxgco_view*v);  /* game/catsystem_kif/xx_catsystem_kif_data.c */
bool sx_malie_lib_build(sxgco_view*v);  /* game/malie_lib/xx_malie_lib_data.c */
bool sx_nitroplus_npa_build(sxgco_view*v);  /* game/nitroplus_npa/xx_nitroplus_npa_data.c */
bool sx_qlie_pack_build(sxgco_view*v);  /* game/qlie_pack/xx_qlie_pack_data.c */

#endif
