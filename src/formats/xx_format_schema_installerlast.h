/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The installerlast schema family: what its family unit (xx_format_schema_installerlast.c)
 * and its formats' data files share. Formats: Wise Installation System; Gentee installer; Clickteam Install Creator; Advanced Installer bootstrapper; ARDI OS/2 installer; ARNI installer container; ej-technologies install4j / exe4j; Ghost Installer; IBM ZPAK installer; Inno Setup; Installer VISE for Windows; InstallShield 12-2012 Setup; InstallShield 3.x/5.x SFX; InstallShield 7 All-in-One Setup; InstallShield 7 setup.boot; InstallShield Developer 7; InstallShield MultiPlatform; InstallShield skin; QSetup; Tarma Installer. */
#ifndef XX_FORMAT_SCHEMA_INSTALLERLAST_H
#define XX_FORMAT_SCHEMA_INSTALLERLAST_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

typedef struct sxil_member { uint64_t header,header_size,data,packed,crc; } sxil_member;
typedef struct sxil_records { sxil_member *items; size_t count; } sxil_records;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxil_installerlast_utf16_name;
extern const sx_layout sxil_advanced_installer_footer;
extern const sx_layout sxil_advanced_installer_record;
extern const sx_layout sxil_advanced_installer_external;
extern const sx_layout sxil_ardi_trailer;
extern const sx_layout sxil_ardi_block_tag;
extern const sx_layout sxil_ardi_block_length;
extern const sx_layout sxil_ardi_member_time;
extern const sx_layout sxil_ardi_chain_start;
extern const sx_layout sxil_arni_member;
extern const sx_layout sxil_arni_end;
extern const sx_layout sxil_ej_technologies_header;
extern const sx_layout sxil_ej_technologies_variable;
extern const sx_layout sxil_ej_technologies_extra_count;
extern const sx_layout sxil_ej_technologies_member;
extern const sx_layout sxil_ej_technologies_member_later;
extern const sx_layout sxil_ej_technologies_trailer;
extern const sx_layout sxil_ej_technologies_trailer_name;
extern const sx_layout sxil_ej_technologies_trailer_size;
extern const sx_layout sxil_ibm_zpak_sfx_header;
extern const sx_layout sxil_ibm_zpak_sfx_v1_directory;
extern const sx_layout sxil_ibm_zpak_sfx_v2_record;
extern const sx_layout sxil_ibm_zpak_sfx_v1_trailer;
extern const sx_layout sxil_ibm_zpak_sfx_v2_trailer;
extern const sx_layout sxil_installerlast_dcl_prelude;
extern const sx_layout sxil_installshield3_descriptor;
extern const sx_layout sxil_installshield3_name_size;
extern const sx_layout sxil_installshield3_member;
extern const sx_layout sxil_installshield_developer_header;
extern const sx_layout sxil_installshield_developer_record;
extern const sx_layout sxil_installshield_multiplatform_footer;
extern const sx_layout sxil_installshield_multiplatform_count;
extern const sx_layout sxil_installshield_multiplatform_record;
extern const sx_layout sxil_installshield_multiplatform_optional;
extern const sx_layout sxil_installshield_multiplatform_u64;
extern const sx_layout sxil_installshield_skin_encoded_name;
extern const sx_layout sxil_installshield_skin_encoded_size;
extern const sx_layout sxil_qsetup_length;
extern const sx_layout sxil_qsetup_record;
extern const sx_layout sxil_qsetup_trailer;
extern const sx_layout sxil_tarma_section;
extern const sx_layout sxil_tarma_lzma_properties;
extern const sx_layout sxil_tarma_separator;
extern const sx_layout sxil_gentee_locator;
extern const sx_layout sxil_gentee_block_size;
extern const sx_layout sxil_clickteam_creator_tag;
extern const sx_layout sxil_clickteam_creator_chunk;
extern const sx_layout sxil_clickteam_creator_data_chunk;
extern const sx_layout sxil_clickteam_creator_compression1;
extern const sx_layout sxil_clickteam_creator_compression2;
extern const sx_layout sxil_clickteam_creator_method;
extern const sx_layout sxil_vise_header;
extern const sx_layout sxil_vise_footer;
extern const sx_layout sxil_vise_wrapper;
extern const sx_layout sxil_vise_string8;
extern const sx_layout sxil_vise_string16;
extern const sx_layout sxil_vise_masked_length;
extern const sx_layout sxil_vise_setup_count;
extern const sx_layout sxil_vise_setup_fields;
extern const sx_layout sxil_vise_packed_size;
extern const sx_layout sxil_vise_object4;
extern const sx_layout sxil_vise_object6;
extern const sx_layout sxil_wise_member_crc32;
extern const sx_layout sxil_wise_zip_local;
extern const sx_layout sxil_wise_zip_central;
extern const sx_layout sxil_wise_zip_end;
extern const sx_layout sxil_ghost_encoded_cab_header;
extern const sx_layout sxil_ghost_encoded_cab_reserve;
extern const sx_layout sxil_ghost_encoded_cab_folder;
extern const sx_layout sxil_ghost_encoded_cab_file;
extern const sx_layout sxil_ghost_encoded_cab_data;
extern const sx_layout sxil_ghost_trailer26;
extern const sx_layout sxil_ghost_trailer34;
extern const sx_layout sxil_inno_loader_pointer;
extern const sx_layout sxil_inno_loader2;
extern const sx_layout sxil_inno_loader4;
extern const sx_layout sxil_inno_loader5;
extern const sx_layout sxil_inno_loader6;
extern const sx_layout sxil_inno_loader7;
extern const sx_layout sxil_inno_loader_revision1;
extern const sx_layout sxil_inno_loader_revision2;
extern const sx_layout sxil_inno_setup_version;
extern const sx_layout sxil_inno_encryption_envelope;
extern const sx_layout sxil_inno_block_legacy;
extern const sx_layout sxil_inno_block32;
extern const sx_layout sxil_inno_block64;
extern const sx_layout sxil_inno_block_crc32;
extern const sx_layout sxil_inno_data_marker;
bool sxil_span(sx_context*c,uint64_t p,uint64_t n);
bool sxil_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxil16(const uint8_t*b,bool be);
uint32_t sxil32(const uint8_t*b,bool be);
bool sxil_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxil_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxil_u32(sx_context*c,uint64_t p,uint32_t*v);
bool sxil_u16(sx_context*c,uint64_t p,uint16_t*v);
bool sxil_eq(sx_context*c,uint64_t p,const void*s,size_t n);
bool sxil_name(sx_context*c,uint64_t p,uint64_t n);
bool sxil_encoded(sx_context*c,uint64_t p,uint64_t n);
bool sxil_pe(sx_context*c,uint64_t*out);
bool sxil_find(sx_context*c,const uint8_t*needle,size_t n,uint64_t start,uint64_t end,uint64_t*out);
bool sxil_resource(sx_context*c,uint32_t type,uint32_t id,const char*name,uint64_t*out,uint32_t*length);
bool sxil_is_strings(sx_context*c,sxil_records*r,bool wide,bool boot);

/* Per-format walkers, called by the family's build. */
bool sx_wise_installation_system_build(sx_context*c,sxil_records records);  /* installer/wise_installation_system/xx_wise_installation_system_data.c */
bool sx_gentee_installer_build(sx_context*c,sxil_records records);  /* installer/gentee_installer/xx_gentee_installer_data.c */
bool sx_clickteam_install_creator_build(sx_context*c,sxil_records records);  /* installer/clickteam_install_creator/xx_clickteam_install_creator_data.c */
bool sx_advanced_installer_bootstrapper_build(sx_context*c,sxil_records records);  /* installer/advanced_installer_bootstrapper/xx_advanced_installer_bootstrapper_data.c */
bool sx_ardi_installer_build(sx_context*c);  /* installer/ardi_installer/xx_ardi_installer_data.c */
bool sx_arni_installer_container_build(sx_context*c,sxil_records records);  /* installer/arni_installer_container/xx_arni_installer_container_data.c */
bool sx_ej_technologies_install_build(sx_context*c,sxil_records records);  /* installer/ej_technologies_install/xx_ej_technologies_install_data.c */
bool sx_ghost_installer_build(sx_context*c);  /* installer/ghost_installer/xx_ghost_installer_data.c */
bool sx_ibm_zpak_installer_build(sx_context*c);  /* installer/ibm_zpak_installer/xx_ibm_zpak_installer_data.c */
bool sx_inno_setup_build(sx_context*c);  /* installer/inno_setup/xx_inno_setup_data.c */
bool sx_installer_vise_windows_build(sx_context*c,sxil_records records);  /* installer/installer_vise_windows/xx_installer_vise_windows_data.c */
bool sx_installshield_12_setup_build(sx_context*c,sxil_records records);  /* installer/installshield_12_setup/xx_installshield_12_setup_data.c */
bool sx_installshield_3_build(sx_context*c,sxil_records records);  /* installer/installshield_3/xx_installshield_3_data.c */
bool sx_installshield_7_setup_build(sx_context*c,sxil_records records);  /* installer/installshield_7_setup/xx_installshield_7_setup_data.c */
bool sx_installshield_7_setup2_build(sx_context*c,sxil_records records);  /* installer/installshield_7_setup2/xx_installshield_7_setup2_data.c */
bool sx_installshield_developer_build(sx_context*c);  /* installer/installshield_developer/xx_installshield_developer_data.c */
bool sx_installshield_multiplatform_build(sx_context*c);  /* installer/installshield_multiplatform/xx_installshield_multiplatform_data.c */
bool sx_installshield_skin_build(sx_context*c,sxil_records records);  /* installer/installshield_skin/xx_installshield_skin_data.c */
bool sx_qsetup_installation_suite_build(sx_context*c);  /* installer/qsetup_installation_suite/xx_qsetup_installation_suite_data.c */
bool sx_tarma_installer_build(sx_context*c);  /* installer/tarma_installer/xx_tarma_installer_data.c */

#endif
