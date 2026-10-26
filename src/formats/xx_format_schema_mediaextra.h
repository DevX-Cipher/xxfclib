/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The mediaextra schema family: what its family unit (xx_format_schema_mediaextra.c)
 * and its formats' data files share. Formats: lucas lab; lucas bun; mohawk mhk; nintendo brres; terminalreality pod; volition vpp; mythic myp; lithtech rez; valve hpak; unreal package; nintendo bfres; nintendo bflyt; nintendo bclyt; relic sga; unity serialized; nintendo cgfx; nintendo byaml; relic chunky; nintendo j3d bmd; nintendo j3d btk; nintendo brlyt; nintendo brlan; nintendo bfsha; cri utf; idtech iqm; unreal psk; unreal psa. */
#ifndef XX_FORMAT_SCHEMA_MEDIAEXTRA_H
#define XX_FORMAT_SCHEMA_MEDIAEXTRA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

typedef struct sxmx_view {sx_context *c;uint8_t *p;size_t n;unsigned work;}sxmx_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmx_lab_header;
extern const sx_layout sxmx_lab_entry;
extern const sx_layout sxmx_bun_header;
extern const sx_layout sxmx_bun_lb83_entry;
extern const sx_layout sxmx_bun_lb23_entry;
extern const sx_layout sxmx_mhk_header;
extern const sx_layout sxmx_mhk_directory;
extern const sx_layout sxmx_mhk_type;
extern const sx_layout sxmx_mhk_count32;
extern const sx_layout sxmx_mhk_count16;
extern const sx_layout sxmx_mhk_file;
extern const sx_layout sxmx_mhk_resource;
extern const sx_layout sxmx_mhk_name;
extern const sx_layout sxmx_pod2_header;
extern const sx_layout sxmx_pod2_entry;
extern const sx_layout sxmx_pod2_audit;
extern const sx_layout sxmx_vpp3_header_le;
extern const sx_layout sxmx_vpp3_entry_le;
extern const sx_layout sxmx_vpp3_header_be;
extern const sx_layout sxmx_vpp3_entry_be;
extern const sx_layout sxmx_myp_header;
extern const sx_layout sxmx_myp_block;
extern const sx_layout sxmx_myp_entry;
extern const sx_layout sxmx_rez_header;
extern const sx_layout sxmx_rez_directory_entry;
extern const sx_layout sxmx_rez_resource_entry;
extern const sx_layout sxmx_rez_key;
extern const sx_layout sxmx_hpak_header;
extern const sx_layout sxmx_hpak_directory;
extern const sx_layout sxmx_hpak_entry;
extern const sx_layout sxmx_brres_header;
extern const sx_layout sxmx_brres_root;
extern const sx_layout sxmx_brres_dictionary;
extern const sx_layout sxmx_brres_node;
extern const sx_layout sxmx_brres_resource;
extern const sx_layout sxmx_cflyt_header_le;
extern const sx_layout sxmx_section_le;
extern const sx_layout sxmx_section_be;
extern const sx_layout sxmx_nw_header;
extern const sx_layout sxmx_chunky_header;
extern const sx_layout sxmx_chunky_chunk;
extern const sx_layout sxmx_j3d_header;
extern const sx_layout sxmx_btk_ttk1;
extern const sx_layout sxmx_btk_selection;
extern const sx_layout sxmx_btk_remap;
extern const sx_layout sxmx_btk_texture_matrix_index;
extern const sx_layout sxmx_btk_float;
extern const sx_layout sxmx_btk_rotation;
extern const sx_layout sxmx_j3d_name_table;
extern const sx_layout sxmx_j3d_name;
extern const sx_layout sxmx_brlan_pai1;
extern const sx_layout sxmx_brlan_binding;
extern const sx_layout sxmx_brlan_group;
extern const sx_layout sxmx_brlan_track;
extern const sx_layout sxmx_brlan_key;
extern const sx_layout sxmx_relative_offset_be;
extern const sx_layout sxmx_bfres_header;
extern const sx_layout sxmx_bfres_dictionary;
extern const sx_layout sxmx_bfres_node;
extern const sx_layout sxmx_bfres_external;
extern const sx_layout sxmx_cgfx_slot;
extern const sx_layout sxmx_cgfx_dictionary;
extern const sx_layout sxmx_cgfx_node;
extern const sx_layout sxmx_unity_header;
extern const sx_layout sxmx_unity_metadata_flags;
extern const sx_layout sxmx_unity_type;
extern const sx_layout sxmx_unity_object_count;
extern const sx_layout sxmx_unity_object;
extern const sx_layout sxmx_unity_tail_counts;
extern const sx_layout sxmx_ue1_header;
extern const sx_layout sxmx_ue1_name_flags;
extern const sx_layout sxmx_ue1_heritage;
extern const sx_layout sxmx_sga6_header;
extern const sx_layout sxmx_sga6_table_slot;
extern const sx_layout sxmx_sga6_drive;
extern const sx_layout sxmx_sga6_folder;
extern const sx_layout sxmx_sga6_file;
extern const sx_layout sxmx_byaml_header_le;
extern const sx_layout sxmx_byaml_node_le;
extern const sx_layout sxmx_byaml_string_offset_le;
extern const sx_layout sxmx_byaml_map_key_le;
extern const sx_layout sxmx_byaml_array_kind_le;
extern const sx_layout sxmx_byaml_string_le;
extern const sx_layout sxmx_byaml_bool_le;
extern const sx_layout sxmx_byaml_int_le;
extern const sx_layout sxmx_byaml_float_le;
extern const sx_layout sxmx_byaml_uint_le;
extern const sx_layout sxmx_byaml_node_value_le;
extern const sx_layout sxmx_byaml_null_le;
extern const sx_layout sxmx_byaml_header_be;
extern const sx_layout sxmx_byaml_node_be;
extern const sx_layout sxmx_byaml_string_offset_be;
extern const sx_layout sxmx_byaml_map_key_be;
extern const sx_layout sxmx_byaml_array_kind_be;
extern const sx_layout sxmx_byaml_string_be;
extern const sx_layout sxmx_byaml_bool_be;
extern const sx_layout sxmx_byaml_int_be;
extern const sx_layout sxmx_byaml_float_be;
extern const sx_layout sxmx_byaml_uint_be;
extern const sx_layout sxmx_byaml_node_value_be;
extern const sx_layout sxmx_byaml_null_be;
extern const sx_layout sxmx_fsha_header;
extern const sx_layout sxmx_fsha_string_length;
extern const sx_layout sxmx_fsha_model;
extern const sx_layout sxmx_fsha_program;
extern const sx_layout sxmx_fsha_vertex_shader;
extern const sx_layout sxmx_fsha_pixel_shader;
extern const sx_layout sxmx_utf_header;
extern const sx_layout sxmx_utf_column;
extern const sx_layout sxmx_utf_u8;
extern const sx_layout sxmx_utf_i8;
extern const sx_layout sxmx_utf_u16;
extern const sx_layout sxmx_utf_i16;
extern const sx_layout sxmx_utf_u32;
extern const sx_layout sxmx_utf_i32;
extern const sx_layout sxmx_utf_u64;
extern const sx_layout sxmx_utf_i64;
extern const sx_layout sxmx_utf_float;
extern const sx_layout sxmx_utf_double;
extern const sx_layout sxmx_utf_string;
extern const sx_layout sxmx_utf_binary;
extern const sx_layout sxmx_utf_guid;
extern const sx_layout sxmx_iqm_header;
extern const sx_layout sxmx_iqm_mesh;
extern const sx_layout sxmx_iqm_vertex_array;
extern const sx_layout sxmx_iqm_triangle;
extern const sx_layout sxmx_iqm_adjacency;
extern const sx_layout sxmx_iqm_float;
extern const sx_layout sxmx_iqm_color;
bool sxmx_need(sxmx_view *v,size_t at,uint64_t n,size_t end);
uint16_t sxmx_u16(const uint8_t*p,bool be);
uint32_t sxmx_u32(const uint8_t*p,bool be);
bool sxmx_row(sxmx_view *v,const sx_layout*l,size_t at,size_t end);
bool sxmx_table(sxmx_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end);
bool sxmx_cstr(sxmx_view*v,size_t*at,size_t end);
bool sxmx_nw(sxmx_view*v);
bool sxmx_relative(sxmx_view*v,size_t word,bool be,size_t*target);
bool sxmx_psx(sxmx_view*v);

/* Per-format walkers, called by the family's build. */
bool sx_lucas_lab_build(sxmx_view*v);  /* game/lucas_lab/xx_lucas_lab_data.c */
bool sx_lucas_bun_build(sxmx_view*v);  /* game/lucas_bun/xx_lucas_bun_data.c */
bool sx_mohawk_mhk_build(sxmx_view*v);  /* game/mohawk_mhk/xx_mohawk_mhk_data.c */
bool sx_nintendo_brres_build(sxmx_view*v);  /* game/nintendo_brres/xx_nintendo_brres_data.c */
bool sx_terminalreality_pod_build(sxmx_view*v);  /* game/terminalreality_pod/xx_terminalreality_pod_data.c */
bool sx_volition_vpp_build(sxmx_view*v);  /* game/volition_vpp/xx_volition_vpp_data.c */
bool sx_mythic_myp_build(sxmx_view*v);  /* game/mythic_myp/xx_mythic_myp_data.c */
bool sx_lithtech_rez_build(sxmx_view*v);  /* game/lithtech_rez/xx_lithtech_rez_data.c */
bool sx_valve_hpak_build(sxmx_view*v);  /* game/valve_hpak/xx_valve_hpak_data.c */
bool sx_unreal_package_build(sxmx_view*v);  /* game/unreal_package/xx_unreal_package_data.c */
bool sx_nintendo_bfres_build(sxmx_view*v);  /* game/nintendo_bfres/xx_nintendo_bfres_data.c */
bool sx_nintendo_bflyt_build(sxmx_view*v);  /* game/nintendo_bflyt/xx_nintendo_bflyt_data.c */
bool sx_nintendo_bclyt_build(sxmx_view*v);  /* game/nintendo_bclyt/xx_nintendo_bclyt_data.c */
bool sx_relic_sga_build(sxmx_view*v);  /* game/relic_sga/xx_relic_sga_data.c */
bool sx_unity_serialized_build(sxmx_view*v);  /* game/unity_serialized/xx_unity_serialized_data.c */
bool sx_nintendo_cgfx_build(sxmx_view*v);  /* game/nintendo_cgfx/xx_nintendo_cgfx_data.c */
bool sx_nintendo_byaml_build(sxmx_view*v);  /* game/nintendo_byaml/xx_nintendo_byaml_data.c */
bool sx_relic_chunky_build(sxmx_view*v);  /* game/relic_chunky/xx_relic_chunky_data.c */
bool sx_nintendo_j3d_bmd_build(sxmx_view*v);  /* game/nintendo_j3d_bmd/xx_nintendo_j3d_bmd_data.c */
bool sx_nintendo_j3d_btk_build(sxmx_view*v);  /* game/nintendo_j3d_btk/xx_nintendo_j3d_btk_data.c */
bool sx_nintendo_brlyt_build(sxmx_view*v);  /* game/nintendo_brlyt/xx_nintendo_brlyt_data.c */
bool sx_nintendo_brlan_build(sxmx_view*v);  /* game/nintendo_brlan/xx_nintendo_brlan_data.c */
bool sx_nintendo_bfsha_build(sxmx_view*v);  /* game/nintendo_bfsha/xx_nintendo_bfsha_data.c */
bool sx_cri_utf_build(sxmx_view*v);  /* game/cri_utf/xx_cri_utf_data.c */
bool sx_idtech_iqm_build(sxmx_view*v);  /* game/idtech_iqm/xx_idtech_iqm_data.c */
bool sx_unreal_psk_build(sxmx_view*v);  /* game/unreal_psk/xx_unreal_psk_data.c */
bool sx_unreal_psa_build(sxmx_view*v);  /* game/unreal_psa/xx_unreal_psa_data.c */

#endif
