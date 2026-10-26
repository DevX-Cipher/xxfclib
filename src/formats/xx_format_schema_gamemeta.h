/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The gamemeta schema family: what its family unit (xx_format_schema_gamemeta.c)
 * and its formats' data files share. Formats: nes_rom; lynx_lnx; godot_engine_pck; valve_vpk; nintendo_rarc; nintendo_narc; nintendo_sarc; sony_psarc; bioware_biff; bioware_erf; bioware_rim; bethesda_bsa; bethesda_ba2; idtech_bsp; valve_bsp; idtech_md2; idtech_md3; idtech_qvm; quake_sprite; idtech_mdl; valve_studio_mdl. */
#ifndef XX_FORMAT_SCHEMA_GAMEMETA_H
#define XX_FORMAT_SCHEMA_GAMEMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxgm_ines_header;
extern const sx_layout sxgm_nes2_header;
extern const sx_layout sxgm_lynx_header;
extern const sx_layout sxgm_godot_pck_v1;
extern const sx_layout sxgm_godot_pck_v2;
extern const sx_layout sxgm_godot_pck_v3;
extern const sx_layout sxgm_godot_pck_v4_salted;
extern const sx_layout sxgm_godot_file_count;
extern const sx_layout sxgm_godot_path_length;
extern const sx_layout sxgm_godot_entry_v1;
extern const sx_layout sxgm_godot_entry_v2;
extern const sx_layout sxgm_godot_encrypted_block;
extern const sx_layout sxgm_godot_trailer;
extern const sx_layout sxgm_vpk_header;
extern const sx_layout sxgm_vpk_v2_sections;
extern const sx_layout sxgm_vpk_entry;
extern const sx_layout sxgm_vpk_archive_md5;
extern const sx_layout sxgm_vpk_other_md5;
extern const sx_layout sxgm_vpk_public_key_length;
extern const sx_layout sxgm_vpk_signature_length;
extern const sx_layout sxgm_rarc_header_le;
extern const sx_layout sxgm_rarc_header_be;
extern const sx_layout sxgm_rarc_node_le;
extern const sx_layout sxgm_rarc_node_be;
extern const sx_layout sxgm_rarc_file_le;
extern const sx_layout sxgm_rarc_directory_le;
extern const sx_layout sxgm_rarc_file_be;
extern const sx_layout sxgm_rarc_directory_be;
extern const sx_layout sxgm_narc_header;
extern const sx_layout sxgm_narc_fat;
extern const sx_layout sxgm_narc_entry;
extern const sx_layout sxgm_narc_block;
extern const sx_layout sxgm_sarc_header_le;
extern const sx_layout sxgm_sarc_header_be;
extern const sx_layout sxgm_sarc_fat_le;
extern const sx_layout sxgm_sarc_fat_be;
extern const sx_layout sxgm_sarc_entry_le;
extern const sx_layout sxgm_sarc_entry_be;
extern const sx_layout sxgm_sarc_names_le;
extern const sx_layout sxgm_sarc_names_be;
extern const sx_layout sxgm_psarc_header;
extern const sx_layout sxgm_psarc_entry;
extern const sx_layout sxgm_psarc_block_length;
extern const sx_layout sxgm_biff_header;
extern const sx_layout sxgm_biff_entry_v1;
extern const sx_layout sxgm_biff_entry_v2;
extern const sx_layout sxgm_erf_header;
extern const sx_layout sxgm_erf_key16;
extern const sx_layout sxgm_erf_key32;
extern const sx_layout sxgm_erf_resource;
extern const sx_layout sxgm_erf_localized;
extern const sx_layout sxgm_rim_header;
extern const sx_layout sxgm_rim_entry;
extern const sx_layout sxgm_bsa_header;
extern const sx_layout sxgm_bsa_folder;
extern const sx_layout sxgm_bsa_folder105;
extern const sx_layout sxgm_bsa_file;
extern const sx_layout sxgm_game_name_length8;
extern const sx_layout sxgm_game_name_length16;
extern const sx_layout sxgm_ba2_header;
extern const sx_layout sxgm_ba2_v2_extension;
extern const sx_layout sxgm_ba2_v3_compression;
extern const sx_layout sxgm_ba2_general_entry;
extern const sx_layout sxgm_idtech_bsp_header;
extern const sx_layout sxgm_idtech_bsp_lump;
extern const sx_layout sxgm_valve_bsp_lump;
extern const sx_layout sxgm_valve_bsp_revision;
extern const sx_layout sxgm_md2_header;
extern const sx_layout sxgm_game_skin_name;
extern const sx_layout sxgm_md2_texcoord;
extern const sx_layout sxgm_md2_triangle;
extern const sx_layout sxgm_md2_frame;
extern const sx_layout sxgm_quake_vertex;
extern const sx_layout sxgm_md2_gl_command;
extern const sx_layout sxgm_md2_gl_vertex;
extern const sx_layout sxgm_md3_header;
extern const sx_layout sxgm_md3_frame;
extern const sx_layout sxgm_md3_tag;
extern const sx_layout sxgm_md3_surface;
extern const sx_layout sxgm_md3_triangle;
extern const sx_layout sxgm_md3_shader;
extern const sx_layout sxgm_md3_texcoord;
extern const sx_layout sxgm_md3_vertex;
extern const sx_layout sxgm_qvm_header;
extern const sx_layout sxgm_quake_sprite_header;
extern const sx_layout sxgm_quake_frame_type;
extern const sx_layout sxgm_quake_group_count;
extern const sx_layout sxgm_quake_interval;
extern const sx_layout sxgm_quake_sprite_frame;
extern const sx_layout sxgm_quake_mdl_header;
extern const sx_layout sxgm_quake_skin_type;
extern const sx_layout sxgm_quake_stvert;
extern const sx_layout sxgm_quake_triangle;
extern const sx_layout sxgm_quake_mdl_frame;
extern const sx_layout sxgm_studio_v10_header;
extern const sx_layout sxgm_studio_texture;
extern const sx_layout sxgm_studio_skinref;
bool sxgm_span(sx_context *c,uint64_t p,uint64_t n);
bool sxgm_read(sx_context *c,uint64_t p,void *b,size_t n);
uint64_t sxgm_uint(const uint8_t *b,unsigned n,bool be);
uint16_t sxgm16(const uint8_t *b,bool be);
uint32_t sxgm32(const uint8_t *b,bool be);
bool sxgm_add(sx_context *c,const sx_layout *l,uint64_t p);
bool sxgm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n);
bool sxgm_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v);
bool sxgm_fixed(sx_context *c,const sx_layout *h,const sx_layout *e,unsigned off,unsigned size,unsigned noff,unsigned nwidth,unsigned poff,unsigned pwidth,bool be);

/* Per-format walkers, called by the family's build. */
bool sx_nes_rom_build(sx_context*c,uint8_t*b);  /* game/nes_rom/xx_nes_rom_data.c */
bool sx_lynx_lnx_build(sx_context *c);  /* game/lynx_lnx/xx_lynx_lnx_data.c */
bool sx_godot_engine_pck_build(sx_context *c);  /* game/godot_engine_pck/xx_godot_engine_pck_data.c */
bool sx_valve_vpk_build(sx_context *c);  /* game/valve_vpk/xx_valve_vpk_data.c */
bool sx_nintendo_rarc_build(sx_context *c);  /* game/nintendo_rarc/xx_nintendo_rarc_data.c */
bool sx_nintendo_narc_build(sx_context *c);  /* game/nintendo_narc/xx_nintendo_narc_data.c */
bool sx_nintendo_sarc_build(sx_context *c);  /* game/nintendo_sarc/xx_nintendo_sarc_data.c */
bool sx_sony_psarc_build(sx_context *c);  /* game/sony_psarc/xx_sony_psarc_data.c */
bool sx_bioware_biff_build(sx_context *c);  /* game/bioware_biff/xx_bioware_biff_data.c */
bool sx_bioware_erf_build(sx_context *c);  /* game/bioware_erf/xx_bioware_erf_data.c */
bool sx_bioware_rim_build(sx_context *c);  /* game/bioware_rim/xx_bioware_rim_data.c */
bool sx_bethesda_bsa_build(sx_context *c);  /* game/bethesda_bsa/xx_bethesda_bsa_data.c */
bool sx_bethesda_ba2_build(sx_context *c);  /* game/bethesda_ba2/xx_bethesda_ba2_data.c */
bool sx_idtech_bsp_build(sx_context*c,uint8_t*b);  /* game/idtech_bsp/xx_idtech_bsp_data.c */
bool sx_valve_bsp_build(sx_context *c);  /* game/valve_bsp/xx_valve_bsp_data.c */
bool sx_idtech_md2_build(sx_context *c);  /* game/idtech_md2/xx_idtech_md2_data.c */
bool sx_idtech_md3_build(sx_context *c);  /* game/idtech_md3/xx_idtech_md3_data.c */
bool sx_idtech_qvm_build(sx_context *c);  /* game/idtech_qvm/xx_idtech_qvm_data.c */
bool sx_quake_sprite_build(sx_context *c);  /* game/quake_sprite/xx_quake_sprite_data.c */
bool sx_idtech_mdl_build(sx_context *c);  /* game/idtech_mdl/xx_idtech_mdl_data.c */
bool sx_valve_studio_mdl_build(sx_context *c);  /* game/valve_studio_mdl/xx_valve_studio_mdl_data.c */

#endif
