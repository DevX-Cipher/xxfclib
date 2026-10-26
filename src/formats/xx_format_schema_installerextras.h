/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The installerextras schema family: what its family unit (xx_format_schema_installerextras.c)
 * and its formats' data files share. Formats: sfx_sbx_extractor; sfx_analogx_emucore_ffs; sfx_krzip; sfx_warpin_package; sfx_hci_instalit; sfx_clickteam_multimedia_fusion; sfx_abbyy_fine_objects; sfx_flashjester_jugglor; sfx_jgsoft_deploymaster_package; sfx_nullsoft_pimp; sfx_compaq_softpaq; sfx_wasp_windows_auto; sfxstart; sfx_ebook_compiler_executables; sfx_packagefortheweb; sfx_red. */
#ifndef XX_FORMAT_SCHEMA_INSTALLEREXTRAS_H
#define XX_FORMAT_SCHEMA_INSTALLEREXTRAS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

typedef struct sxiex_member { uint64_t header,header_size,data,packed; } sxiex_member;
typedef struct sxiex_records { sxiex_member *items; size_t count; } sxiex_records;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxiex_sbx_member;
extern const sx_layout sxiex_sbx_plain_size;
extern const sx_layout sxiex_installer_name;
extern const sx_layout sxiex_installer_utf16_name;
extern const sx_layout sxiex_installer_encoded_bytes;
extern const sx_layout sxiex_ffs_header;
extern const sx_layout sxiex_ffs_index;
extern const sx_layout sxiex_ffs_member;
extern const sx_layout sxiex_ffs_cmp1;
extern const sx_layout sxiex_ffs_cmp2;
extern const sx_layout sxiex_ffs_footer;
extern const sx_layout sxiex_krzip_header;
extern const sx_layout sxiex_krzip_encoded_name_length;
extern const sx_layout sxiex_krzip_encoded_fields;
extern const sx_layout sxiex_krzip_footer;
extern const sx_layout sxiex_warpin_header;
extern const sx_layout sxiex_warpin_extension;
extern const sx_layout sxiex_warpin_package;
extern const sx_layout sxiex_warpin_member;
extern const sx_layout sxiex_instalit_engine;
extern const sx_layout sxiex_instalit_footer;
extern const sx_layout sxiex_instalit_catalog_prefix;
extern const sx_layout sxiex_instalit_catalog_1c55;
extern const sx_layout sxiex_instalit_catalog_1c59;
extern const sx_layout sxiex_instalit_catalog_1a47;
extern const sx_layout sxiex_instalit_script;
extern const sx_layout sxiex_instalit_data_marker;
extern const sx_layout sxiex_abbyy_count;
extern const sx_layout sxiex_abbyy_string;
extern const sx_layout sxiex_abbyy_stream_size;
extern const sx_layout sxiex_abbyy_dates;
extern const sx_layout sxiex_abbyy_finear;
extern const sx_layout sxiex_abbyy_trailer;
extern const sx_layout sxiex_deploymaster_record;
extern const sx_layout sxiex_deploymaster_separator;
extern const sx_layout sxiex_deploymaster_bzip2;
extern const sx_layout sxiex_pimp_header;
extern const sx_layout sxiex_pimp_directory;
extern const sx_layout sxiex_pimp_text;
extern const sx_layout sxiex_pimp_v1_count;
extern const sx_layout sxiex_pimp_v2_count;
extern const sx_layout sxiex_pimp_name_length;
extern const sx_layout sxiex_pimp_v1_sizes;
extern const sx_layout sxiex_pimp_v2_sizes;
extern const sx_layout sxiex_pimp_command_length;
extern const sx_layout sxiex_softpaq_fit1;
extern const sx_layout sxiex_softpaq_fit2;
extern const sx_layout sxiex_wasp_resource_shift;
extern const sx_layout sxiex_wasp_resource_type;
extern const sx_layout sxiex_wasp_resource_entry;
extern const sx_layout sxiex_wasp_string_length;
extern const sx_layout sxiex_wasp_payload_size;
extern const sx_layout sxiex_sfxstart_header;
extern const sx_layout sxiex_sfxstart_name;
extern const sx_layout sxiex_sfxstart_size;
extern const sx_layout sxiex_sfxstart_separator;
extern const sx_layout sxiex_sfxstart_command;
extern const sx_layout sxiex_sfxstart_footer;
extern const sx_layout sxiex_clickteam_pack;
extern const sx_layout sxiex_clickteam_name;
extern const sx_layout sxiex_clickteam_size;
extern const sx_layout sxiex_clickteam_checksum_size;
extern const sx_layout sxiex_jugglor_member;
extern const sx_layout sxiex_exeattachment_member;
extern const sx_layout sxiex_jugglor_trailer;
extern const sx_layout sxiex_exeattachment_trailer;
extern const sx_layout sxiex_ebook_creator_header;
extern const sx_layout sxiex_ebook_creator_member;
extern const sx_layout sxiex_ebook_creator_ref;
extern const sx_layout sxiex_ebook_creator_list;
extern const sx_layout sxiex_ebook_creator_element;
extern const sx_layout sxiex_ebook_creator_name;
extern const sx_layout sxiex_ebook_creator_footer;
extern const sx_layout sxiex_sbook_header;
extern const sx_layout sxiex_sbook_count;
extern const sx_layout sxiex_sbook_name_length;
extern const sx_layout sxiex_sbook_member;
extern const sx_layout sxiex_sbook_chunk;
extern const sx_layout sxiex_sbook_footer;
extern const sx_layout sxiex_pftw_settings_size;
extern const sx_layout sxiex_pftw_settings_new;
extern const sx_layout sxiex_pftw_settings_old;
extern const sx_layout sxiex_pftw_cab_header;
extern const sx_layout sxiex_pftw_cab_reserve;
extern const sx_layout sxiex_pftw_cab_folder;
extern const sx_layout sxiex_pftw_cab_file;
extern const sx_layout sxiex_pftw_cab_data;
extern const sx_layout sxiex_sfx_red_header;
extern const sx_layout sxiex_sfx_red_name;
extern const sx_layout sxiex_sfx_red_short_name;
extern const sx_layout sxiex_sfx_red_crc16;
extern const sx_layout sxiex_instalit_resource_shift;
extern const sx_layout sxiex_instalit_resource_type;
extern const sx_layout sxiex_instalit_resource_entry;
extern const sx_layout sxiex_instalit_resource_end;
extern const sx_layout sxiex_instalit_resource_name_length;
extern const sx_layout sxiex_wasp_name_separator;
extern const sx_layout sxiex_wasp_run_marker;
extern const sx_layout sxiex_wasp_resource_end;
bool sxiex_span(sx_context*c,uint64_t p,uint64_t n);
bool sxiex_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxiex16(const uint8_t*b,bool be);
uint32_t sxiex32(const uint8_t*b,bool be);
bool sxiex_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxiex_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxiex_u32(sx_context*c,uint64_t p,uint32_t*v);
bool sxiex_u16(sx_context*c,uint64_t p,uint16_t*v);
bool sxiex_eq(sx_context*c,uint64_t p,const void*s,size_t n);
bool sxiex_name(sx_context*c,uint64_t p,uint64_t n);
bool sxiex_zstr(sx_context*c,uint64_t*p,uint64_t end);
bool sxiex_pe(sx_context*c,uint64_t*out);

/* Per-format walkers, called by the family's build. */
bool sx_sfx_sbx_extractor_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_sbx_extractor/xx_sfx_sbx_extractor_data.c */
bool sx_sfx_analogx_emucore_ffs_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_analogx_emucore_ffs/xx_sfx_analogx_emucore_ffs_data.c */
bool sx_sfx_krzip_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_krzip/xx_sfx_krzip_data.c */
bool sx_sfx_warpin_package_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_warpin_package/xx_sfx_warpin_package_data.c */
bool sx_sfx_hci_instalit_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_hci_instalit/xx_sfx_hci_instalit_data.c */
bool sx_sfx_clickteam_multimedia_fusion_build(sx_context*c,const sxiex_records*records);  /* game/sfx_clickteam_multimedia_fusion/xx_sfx_clickteam_multimedia_fusion_data.c */
bool sx_sfx_abbyy_fine_objects_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_abbyy_fine_objects/xx_sfx_abbyy_fine_objects_data.c */
bool sx_sfx_flashjester_jugglor_build(sx_context*c,const sxiex_records*records);  /* executable/sfx_flashjester_jugglor/xx_sfx_flashjester_jugglor_data.c */
bool sx_sfx_jgsoft_deploymaster_package_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_jgsoft_deploymaster_package/xx_sfx_jgsoft_deploymaster_package_data.c */
bool sx_sfx_nullsoft_pimp_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_nullsoft_pimp/xx_sfx_nullsoft_pimp_data.c */
bool sx_sfx_compaq_softpaq_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_compaq_softpaq/xx_sfx_compaq_softpaq_data.c */
bool sx_sfx_wasp_windows_auto_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_wasp_windows_auto/xx_sfx_wasp_windows_auto_data.c */
bool sx_sfxstart_build(sx_context*c,const sxiex_records*records);  /* installer/sfxstart/xx_sfxstart_data.c */
bool sx_sfx_ebook_compiler_executables_build(sx_context*c,const sxiex_records*records);  /* document/sfx_ebook_compiler_executables/xx_sfx_ebook_compiler_executables_data.c */
bool sx_sfx_packagefortheweb_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_packagefortheweb/xx_sfx_packagefortheweb_data.c */
bool sx_sfx_red_build(sx_context*c,const sxiex_records*records);  /* installer/sfx_red/xx_sfx_red_data.c */

#endif
