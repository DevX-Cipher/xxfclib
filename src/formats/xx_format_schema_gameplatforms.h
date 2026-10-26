/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The gameplatforms schema family: what its family unit (xx_format_schema_gameplatforms.c)
 * and its formats' data files share. Formats: unityfs; totalannihilation_hpi; ravensoft_rff; kirikiri_xp3; fromsoftware_binder; nintendo_ncch; nintendo_ncsd; nintendo_cia; nintendo_nds; nintendo_gcm; larian_lspk; larian_lsf; renpy_rpa; nintendo_wbfs; sony_psp_pbp; nintendo_n64_rom; nintendo_gb_rom; nintendo_gba_rom; sega_megadrive_rom; xna_xnb; zx_spectrum_szx; nintendo_unif; nintendo_fds; atari_7800_a78; amstrad_cpc_sna; minecraft_nbt; msx_rom; sega_sms_rom; tic80. */
#ifndef XX_FORMAT_SCHEMA_GAMEPLATFORMS_H
#define XX_FORMAT_SCHEMA_GAMEPLATFORMS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxgp_view {sx_context*c;unsigned work;}sxgp_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxgp_msx_rom_header;
extern const sx_layout sxgp_msx_binary_header;
extern const sx_layout sxgp_sms_header;
extern const sx_layout sxgp_tic_chunk;
extern const sx_layout sxgp_gb_common;
extern const sx_layout sxgp_gb_title;
extern const sx_layout sxgp_cgb_title;
extern const sx_layout sxgp_gb_cartridge;
extern const sx_layout sxgp_gba_header;
extern const sx_layout sxgp_megadrive_boot;
extern const sx_layout sxgp_megadrive_vector;
extern const sx_layout sxgp_megadrive_header;
extern const sx_layout sxgp_n64_header;
extern const sx_layout sxgp_a78_header;
extern const sx_layout sxgp_unif_header;
extern const sx_layout sxgp_unif_chunk;
extern const sx_layout sxgp_unif_crc;
extern const sx_layout sxgp_unif_mirroring;
extern const sx_layout sxgp_fds_header;
extern const sx_layout sxgp_fds_file_count;
extern const sx_layout sxgp_fds_file;
extern const sx_layout sxgp_pbp_header;
extern const sx_layout sxgp_sfo_header;
extern const sx_layout sxgp_sfo_entry;
extern const sx_layout sxgp_xnb_header;
extern const sx_layout sxgp_xnb_count;
extern const sx_layout sxgp_xnb_reader_id;
extern const sx_layout sxgp_xnb_length_1;
extern const sx_layout sxgp_xnb_length_2;
extern const sx_layout sxgp_xnb_length_3;
extern const sx_layout sxgp_xnb_length_4;
extern const sx_layout sxgp_xnb_reader_version;
extern const sx_layout sxgp_xnb_texture;
extern const sx_layout sxgp_xnb_mip;
extern const sx_layout sxgp_xnb_int32;
extern const sx_layout sxgp_xnb_float32;
extern const sx_layout sxgp_xnb_byte;
extern const sx_layout sxgp_ncsd_header;
extern const sx_layout sxgp_ncsd_partition;
extern const sx_layout sxgp_ncsd_tail;
extern const sx_layout sxgp_nds_header;
extern const sx_layout sxgp_nds_fat;
extern const sx_layout sxgp_nds_overlay;
extern const sx_layout sxgp_nds_directory;
extern const sx_layout sxgp_nds_name;
extern const sx_layout sxgp_nds_subdirectory;
extern const sx_layout sxgp_sfo_int32;
extern const sx_layout sxgp_nds_root_directory;
extern const sx_layout sxgp_unity_header;
extern const sx_layout sxgp_unity_sizes;
extern const sx_layout sxgp_unity_info;
extern const sx_layout sxgp_unity_block;
extern const sx_layout sxgp_unity_node_count;
extern const sx_layout sxgp_unity_node;
extern const sx_layout sxgp_hpi_header;
extern const sx_layout sxgp_hpi_directory;
extern const sx_layout sxgp_hpi_entry;
extern const sx_layout sxgp_hpi_file;
extern const sx_layout sxgp_rff_header;
extern const sx_layout sxgp_rff_entry;
extern const sx_layout sxgp_bnd3_header_le;
extern const sx_layout sxgp_bnd4_header_le;
extern const sx_layout sxgp_bnd3_entry_le;
extern const sx_layout sxgp_bnd4_entry_le;
extern const sx_layout sxgp_bnd_offset32_le;
extern const sx_layout sxgp_bnd_offset64_le;
extern const sx_layout sxgp_bnd_id_le;
extern const sx_layout sxgp_bnd3_name_le;
extern const sx_layout sxgp_bnd4_name_le;
extern const sx_layout sxgp_bnd_raw32_le;
extern const sx_layout sxgp_bnd_raw64_le;
extern const sx_layout sxgp_bnd4_names_extra_le;
extern const sx_layout sxgp_bnd3_header_be;
extern const sx_layout sxgp_bnd4_header_be;
extern const sx_layout sxgp_bnd3_entry_be;
extern const sx_layout sxgp_bnd4_entry_be;
extern const sx_layout sxgp_bnd_offset32_be;
extern const sx_layout sxgp_bnd_offset64_be;
extern const sx_layout sxgp_bnd_id_be;
extern const sx_layout sxgp_bnd3_name_be;
extern const sx_layout sxgp_bnd4_name_be;
extern const sx_layout sxgp_bnd_raw32_be;
extern const sx_layout sxgp_bnd_raw64_be;
extern const sx_layout sxgp_bnd4_names_extra_be;
extern const sx_layout sxgp_xp3_header;
extern const sx_layout sxgp_xp3_index;
extern const sx_layout sxgp_xp3_chunk;
extern const sx_layout sxgp_xp3_info;
extern const sx_layout sxgp_xp3_segment;
extern const sx_layout sxgp_xp3_checksum;
extern const sx_layout sxgp_lspk_header;
extern const sx_layout sxgp_lspk_file;
extern const sx_layout sxgp_lsf_header;
extern const sx_layout sxgp_lsf_string_table;
extern const sx_layout sxgp_lsf_bucket;
extern const sx_layout sxgp_lsf_string;
extern const sx_layout sxgp_lsf_node;
extern const sx_layout sxgp_lsf_attribute;
extern const sx_layout sxgp_rpa_header;
extern const sx_layout sxgp_rpa_zlib;
extern const sx_layout sxgp_rpa_adler;
extern const sx_layout sxgp_nbt_tag;
extern const sx_layout sxgp_nbt_string;
extern const sx_layout sxgp_nbt_array;
extern const sx_layout sxgp_nbt_list;
extern const sx_layout sxgp_nbt_byte;
extern const sx_layout sxgp_nbt_short;
extern const sx_layout sxgp_nbt_int;
extern const sx_layout sxgp_nbt_long;
extern const sx_layout sxgp_nbt_float;
extern const sx_layout sxgp_nbt_double;
extern const sx_layout sxgp_szx_header;
extern const sx_layout sxgp_szx_chunk;
extern const sx_layout sxgp_szx_z80;
extern const sx_layout sxgp_szx_z80_v0_tail;
extern const sx_layout sxgp_szx_z80_v1_tail;
extern const sx_layout sxgp_szx_z80_v4_tail;
extern const sx_layout sxgp_szx_spectrum;
extern const sx_layout sxgp_szx_ram;
extern const sx_layout sxgp_szx_creator;
extern const sx_layout sxgp_szx_joystick;
extern const sx_layout sxgp_szx_keyboard;
extern const sx_layout sxgp_szx_keyboard_joystick;
extern const sx_layout sxgp_szx_printer;
extern const sx_layout sxgp_szx_ay;
extern const sx_layout sxgp_cpc_header;
extern const sx_layout sxgp_cpc_v1_tail;
extern const sx_layout sxgp_cpc_model;
extern const sx_layout sxgp_fds_side;
extern const sx_layout sxgp_cia_header;
extern const sx_layout sxgp_cia_signature;
extern const sx_layout sxgp_cia_tmd;
extern const sx_layout sxgp_cia_content_info;
extern const sx_layout sxgp_cia_content;
extern const sx_layout sxgp_cia_metadata;
extern const sx_layout sxgp_gcm_id;
extern const sx_layout sxgp_gcm_title;
extern const sx_layout sxgp_gcm_debug;
extern const sx_layout sxgp_gcm_boot;
extern const sx_layout sxgp_gcm_apploader;
extern const sx_layout sxgp_gcm_fst_file;
extern const sx_layout sxgp_gcm_fst_directory;
extern const sx_layout sxgp_gcm_fst_root;
extern const sx_layout sxgp_gcm_dol_offset;
extern const sx_layout sxgp_gcm_dol_address;
extern const sx_layout sxgp_gcm_dol_size;
extern const sx_layout sxgp_gcm_dol_tail;
extern const sx_layout sxgp_wbfs_header;
extern const sx_layout sxgp_wbfs_disc_title;
extern const sx_layout sxgp_wbfs_block;
extern const sx_layout sxgp_wbfs_md5;
bool sxgp_span(sxgp_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxgp_read(sxgp_view*v,uint64_t at,void*p,size_t n,uint64_t end);
bool sxgp_word(sxgp_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end);
bool sxgp_row(sxgp_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxgp_table(sxgp_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxgp_ncch_at(sxgp_view*v,uint64_t at,uint64_t end,bool extended);

/* Per-format walkers, called by the family's build. */
bool sx_unityfs_build(sxgp_view*v);  /* game/unityfs/xx_unityfs_data.c */
bool sx_totalannihilation_hpi_build(sxgp_view*v);  /* game/totalannihilation_hpi/xx_totalannihilation_hpi_data.c */
bool sx_ravensoft_rff_build(sxgp_view*v);  /* game/ravensoft_rff/xx_ravensoft_rff_data.c */
bool sx_kirikiri_xp3_build(sxgp_view*v);  /* game/kirikiri_xp3/xx_kirikiri_xp3_data.c */
bool sx_fromsoftware_binder_build(sxgp_view*v);  /* game/fromsoftware_binder/xx_fromsoftware_binder_data.c */
bool sx_nintendo_ncch_build(sxgp_view*v);  /* game/nintendo_ncch/xx_nintendo_ncch_data.c */
bool sx_nintendo_ncsd_build(sxgp_view*v);  /* game/nintendo_ncsd/xx_nintendo_ncsd_data.c */
bool sx_nintendo_cia_build(sxgp_view*v);  /* game/nintendo_cia/xx_nintendo_cia_data.c */
bool sx_nintendo_nds_build(sxgp_view*v);  /* game/nintendo_nds/xx_nintendo_nds_data.c */
bool sx_nintendo_gcm_build(sxgp_view*v);  /* game/nintendo_gcm/xx_nintendo_gcm_data.c */
bool sx_larian_lspk_build(sxgp_view*v);  /* game/larian_lspk/xx_larian_lspk_data.c */
bool sx_larian_lsf_build(sxgp_view*v);  /* game/larian_lsf/xx_larian_lsf_data.c */
bool sx_renpy_rpa_build(sxgp_view*v);  /* game/renpy_rpa/xx_renpy_rpa_data.c */
bool sx_nintendo_wbfs_build(sxgp_view*v);  /* game/nintendo_wbfs/xx_nintendo_wbfs_data.c */
bool sx_sony_psp_pbp_build(sxgp_view*v);  /* game/sony_psp_pbp/xx_sony_psp_pbp_data.c */
bool sx_nintendo_n64_rom_build(sxgp_view*v);  /* game/nintendo_n64_rom/xx_nintendo_n64_rom_data.c */
bool sx_nintendo_gb_rom_build(sxgp_view*v);  /* game/nintendo_gb_rom/xx_nintendo_gb_rom_data.c */
bool sx_nintendo_gba_rom_build(sxgp_view*v);  /* game/nintendo_gba_rom/xx_nintendo_gba_rom_data.c */
bool sx_sega_megadrive_rom_build(sxgp_view*v);  /* game/sega_megadrive_rom/xx_sega_megadrive_rom_data.c */
bool sx_xna_xnb_build(sxgp_view*v);  /* game/xna_xnb/xx_xna_xnb_data.c */
bool sx_zx_spectrum_szx_build(sxgp_view*v);  /* game/zx_spectrum_szx/xx_zx_spectrum_szx_data.c */
bool sx_nintendo_unif_build(sxgp_view*v);  /* game/nintendo_unif/xx_nintendo_unif_data.c */
bool sx_nintendo_fds_build(sxgp_view*v);  /* game/nintendo_fds/xx_nintendo_fds_data.c */
bool sx_atari_7800_a78_build(sxgp_view*v);  /* game/atari_7800_a78/xx_atari_7800_a78_data.c */
bool sx_amstrad_cpc_sna_build(sxgp_view*v);  /* game/amstrad_cpc_sna/xx_amstrad_cpc_sna_data.c */
bool sx_minecraft_nbt_build(sxgp_view*v);  /* game/minecraft_nbt/xx_minecraft_nbt_data.c */
bool sx_msx_rom_build(sxgp_view*v);  /* game/msx_rom/xx_msx_rom_data.c */
bool sx_sega_sms_rom_build(sxgp_view*v);  /* game/sega_sms_rom/xx_sega_sms_rom_data.c */
bool sx_tic80_build(sxgp_view*v);  /* game/tic80/xx_tic80_data.c */

#endif
