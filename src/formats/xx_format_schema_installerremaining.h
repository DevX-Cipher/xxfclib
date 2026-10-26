/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The installerremaining schema family: what its family unit (xx_format_schema_installerremaining.c)
 * and its formats' data files share. Formats: NSIS; BitRock (CookFS); Smart Install Maker; Excelsior Installer; NetopSystems FEAD; SuperDAT; Solaris package (ZIP); DeskSoft; MetaProducts; VisualWare; Lyme SFX; Instalit data; AD01 SFX; SoftPaq 4 SFX; INFTool SFX. */
#ifndef XX_FORMAT_SCHEMA_INSTALLERREMAINING_H
#define XX_FORMAT_SCHEMA_INSTALLERREMAINING_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Reads use physical file coordinates, never decoded-buffer offsets. */
typedef struct sxir_view {sx_context*c;uint64_t work;} sxir_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxir_nsis_firstheader;
extern const sx_layout sxir_nsis_common_flags;
extern const sx_layout sxir_nsis_block32;
extern const sx_layout sxir_nsis_block64;
extern const sx_layout sxir_nsis_instruction;
extern const sx_layout sxir_nsis_block_length;
extern const sx_layout sxir_installer_crc32;
extern const sx_layout sxir_installer_name;
extern const sx_layout sxir_installer_utf8;
extern const sx_layout sxir_installer_terminator;
extern const sx_layout sxir_installer_size;
extern const sx_layout sxir_cookfs_footer;
extern const sx_layout sxir_cookfs_page_digest;
extern const sx_layout sxir_cookfs_page_size;
extern const sx_layout sxir_cookfs_blob;
extern const sx_layout sxir_cookfs_index;
extern const sx_layout sxir_cookfs_directory;
extern const sx_layout sxir_cookfs_name_length;
extern const sx_layout sxir_cookfs_entry;
extern const sx_layout sxir_cookfs_block;
extern const sx_layout sxir_sim_footer;
extern const sx_layout sxir_sim_stored_file;
extern const sx_layout sxir_excelsior_header;
extern const sx_layout sxir_excelsior_lzma_stream;
extern const sx_layout sxir_fead_outer_prefix;
extern const sx_layout sxir_fead_encoded_header;
extern const sx_layout sxir_superdat_group;
extern const sx_layout sxir_superdat_member;
extern const sx_layout sxir_superdat_lh1_stream;
extern const sx_layout sxir_superdat_group_trailer;
extern const sx_layout sxir_superdat_original_footer;
extern const sx_layout sxir_superdat_footer_v0;
extern const sx_layout sxir_superdat_footer_v1;
extern const sx_layout sxir_superdat_footer_v12;
extern const sx_layout sxir_superdat_manifest_170;
extern const sx_layout sxir_superdat_manifest_178;
extern const sx_layout sxir_solaris_zip_signature;
extern const sx_layout sxir_solaris_zip_object;
extern const sx_layout sxir_solaris_zip_group;
extern const sx_layout sxir_solaris_zip_block;
extern const sx_layout sxir_desksoft_header;
extern const sx_layout sxir_desksoft_end;
extern const sx_layout sxir_metaproducts_header;
extern const sx_layout sxir_metaproducts_member;
extern const sx_layout sxir_metaproducts_footer;
extern const sx_layout sxir_visualware_header;
extern const sx_layout sxir_visualware_legacy_header;
extern const sx_layout sxir_visualware_legacy_data_header;
extern const sx_layout sxir_lyme_footer;
extern const sx_layout sxir_lyme_member;
extern const sx_layout sxir_lyme_name_length;
extern const sx_layout sxir_lyme_label;
extern const sx_layout sxir_instalit_dcl_header;
extern const sx_layout sxir_softpaq4_descriptor_0;
extern const sx_layout sxir_softpaq4_descriptor_8;
extern const sx_layout sxir_softpaq4_name_length;
extern const sx_layout sxir_softpaq4_footer;
extern const sx_layout sxir_inftool_header_22;
extern const sx_layout sxir_inftool_header_24;
extern const sx_layout sxir_active_delivery_header;
extern const sx_layout sxir_lyme_zero_sentinel;
extern const sx_layout sxir_nsis_string_pool;
bool sxir_span(sxir_view*v,uint64_t at,uint64_t z,uint64_t end);
bool sxir_read(sxir_view*v,uint64_t at,void*b,size_t z,uint64_t end);
bool sxir_u(sxir_view*v,uint64_t at,unsigned z,bool be,uint64_t*out,uint64_t end);
bool sxir_eq(sxir_view*v,uint64_t at,const char*s,size_t z,uint64_t end);
bool sxir_emit(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t z,uint64_t end);
bool sxir_row(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxir_table(sxir_view*v,const sx_layout*l,uint64_t at,uint64_t n,uint64_t end);
bool sxir_zstr(sxir_view*v,uint64_t*at,uint64_t end,uint64_t*length);
bool sxir_find(sxir_view*v,uint64_t begin,uint64_t end,const char*sig,size_t z,bool last,uint64_t*out);
bool sxir_pe(sxir_view*v,uint64_t start,uint64_t end,uint64_t*out,uint64_t*certificate);

/* Per-format walkers, called by the family's build. */
bool sx_nsis_build(sx_context *c);  /* installer/nsis/xx_nsis_data.c */
bool sx_bitrock_build(sx_context *c);  /* installer/bitrock/xx_bitrock_data.c */
bool sx_smart_install_maker_build(sx_context *c);  /* installer/smart_install_maker/xx_smart_install_maker_data.c */
bool sx_excelsior_build(sx_context *c);  /* installer/excelsior/xx_excelsior_data.c */
bool sx_fead_build(sx_context *c);  /* installer/fead/xx_fead_data.c */
bool sx_superdat_build(sx_context *c);  /* installer/superdat/xx_superdat_data.c */
bool sx_solarispkg_zip_build(sx_context *c);  /* installer/solarispkg_zip/xx_solarispkg_zip_data.c */
bool sx_desksoft_build(sx_context *c);  /* installer/desksoft/xx_desksoft_data.c */
bool sx_metaproducts_build(sx_context *c);  /* installer/metaproducts/xx_metaproducts_data.c */
bool sx_visualware_build(sx_context *c);  /* installer/visualware/xx_visualware_data.c */
bool sx_lyme_sfx_build(sx_context *c);  /* installer/lyme_sfx/xx_lyme_sfx_data.c */
bool sx_instalit_data_build(sx_context *c);  /* installer/instalit_data/xx_instalit_data_data.c */
bool sx_sfx_ad01_build(sx_context *c);  /* installer/sfx_ad01/xx_sfx_ad01_data.c */
bool sx_sfx_softpaq4_build(sx_context *c);  /* installer/sfx_softpaq4/xx_sfx_softpaq4_data.c */
bool sx_sfx_inftool_build(sx_context *c);  /* installer/sfx_inftool/xx_sfx_inftool_data.c */

#endif
