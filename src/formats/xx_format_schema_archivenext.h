/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivenext schema family: what its family unit (xx_format_schema_archivenext.c)
 * and its formats' data files share. Formats: IS3; IS5; IS11; GKSETUP; PCINSTALL; FINSTALL; IFAH_INSTALLER; O_SETUP; PC_INSTALL_SETUP; RTPATCH_SETUP_DATA; SPOON_INSTALLER; INSTALLSHIELD_ISSETUPSTREAM; ESCHALON_SETUP_EPSF; SETUP_FACTORY; WESTWOOD_PAK; CKP; EDP; PARSEC_RIB; PARSEC_ARCHIVE; PTERO_BIGF; PIRS; SBPAK; TITAN_QUEST; CGJP; BIRDIES; XUIZ; WII_WAD; FREEARC; ZPAQ; BYTEKILLER; DCS; AUDIALS; OSL2000; MICROFOX_PUT; SAR. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVENEXT_H
#define XX_FORMAT_SCHEMA_ARCHIVENEXT_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxan_is3_header;
extern const sx_layout sxan_is3_directory;
extern const sx_layout sxan_is3_member;
extern const sx_layout sxan_is3_payload_header;
extern const sx_layout sxan_is3_payload_member;
extern const sx_layout sxan_is3_second_name;
extern const sx_layout sxan_is5_header;
extern const sx_layout sxan_is5_descriptor;
extern const sx_layout sxan_is5_member_v5;
extern const sx_layout sxan_is5_member_v6;
extern const sx_layout sxan_is5_table_offset;
extern const sx_layout sxan_is11_header;
extern const sx_layout sxan_is11_member_v1;
extern const sx_layout sxan_is11_member_v3;
extern const sx_layout sxan_gksetup_banner;
extern const sx_layout sxan_gksetup_signature;
extern const sx_layout sxan_gksetup_data_offset;
extern const sx_layout sxan_gksetup_member;
extern const sx_layout sxan_pcinstall_header;
extern const sx_layout sxan_pcinstall_member;
extern const sx_layout sxan_finstall_header;
extern const sx_layout sxan_finstall_member;
extern const sx_layout sxan_ifah_header;
extern const sx_layout sxan_ifah_member;
extern const sx_layout sxan_osetup_member;
extern const sx_layout sxan_osetup_trailer_6;
extern const sx_layout sxan_osetup_trailer_8;
extern const sx_layout sxan_rtpatch_setup_member;
extern const sx_layout sxan_issetup_header;
extern const sx_layout sxan_issetup_member;
extern const sx_layout sxan_epsf_header;
extern const sx_layout sxan_setup_factory_header;
extern const sx_layout sxan_setup_factory_engine_16;
extern const sx_layout sxan_setup_factory_engine_260;
extern const sx_layout sxan_westwood_offset;
extern const sx_layout sxan_ptero_header;
extern const sx_layout sxan_ptero_member;
extern const sx_layout sxan_ptero_block;
extern const sx_layout sxan_titan_header;
extern const sx_layout sxan_titan_block;
extern const sx_layout sxan_titan_member;
extern const sx_layout sxan_cgjp_signature;
extern const sx_layout sxan_cgjp_block;
extern const sx_layout sxan_birdies_header;
extern const sx_layout sxan_birdies_member;
extern const sx_layout sxan_xuiz_header;
extern const sx_layout sxan_xuiz_member_0;
extern const sx_layout sxan_xuiz_member_10;
extern const sx_layout sxan_dcs_header;
extern const sx_layout sxan_dcs_block;
extern const sx_layout sxan_audials_count;
extern const sx_layout sxan_audials_offset;
extern const sx_layout sxan_audials_size;
extern const sx_layout sxan_archivenext_name;
extern const sx_layout sxan_archivenext_utf16le;
extern const sx_layout sxan_archivenext_utf16be;
extern const sx_layout sxan_is5_volume_prefix;
extern const sx_layout sxan_archivenext_padding32;
extern const sx_layout sxan_archivenext_separator;
extern const sx_layout sxan_wad_header;
extern const sx_layout sxan_wad_rsa2048;
extern const sx_layout sxan_wad_ticket;
extern const sx_layout sxan_wad_limit;
extern const sx_layout sxan_wad_tmd;
extern const sx_layout sxan_wad_content;
extern const sx_layout sxan_stfs_signature;
extern const sx_layout sxan_stfs_metadata_digest;
extern const sx_layout sxan_stfs_volume_le;
extern const sx_layout sxan_stfs_volume_be;
extern const sx_layout sxan_stfs_data_file_count;
extern const sx_layout sxan_stfs_hash_entry;
extern const sx_layout sxan_stfs_file_le;
extern const sx_layout sxan_stfs_file_be;
extern const sx_layout sxan_bytekiller_header;
extern const sx_layout sxan_bytekiller_ace_header;
extern const sx_layout sxan_bytekiller_anc_header;
extern const sx_layout sxan_bytekiller_grac_header;
extern const sx_layout sxan_bytekiller_md11_header;
extern const sx_layout sxan_bytekiller_signature;
extern const sx_layout sxan_bytekiller_footer;
extern const sx_layout sxan_osl_encoded_record;
extern const sx_layout sxan_osl_payload_checksum;
extern const sx_layout sxan_osl_signature;
extern const sx_layout sxan_sbpak_header;
extern const sx_layout sxan_sbpak_encoded_header;
extern const sx_layout sxan_sbpak_member;
extern const sx_layout sxan_sbpak_encoded_member;
extern const sx_layout sxan_freearc_header;
extern const sx_layout sxan_freearc_magic;
extern const sx_layout sxan_freearc_crc;
extern const sx_layout sxan_freearc_time;
extern const sx_layout sxan_freearc_folder;
extern const sx_layout sxan_freearc_method;
extern const sx_layout sxan_freearc_type1;
extern const sx_layout sxan_freearc_count1;
extern const sx_layout sxan_freearc_offset1;
extern const sx_layout sxan_freearc_size1;
extern const sx_layout sxan_freearc_packed1;
extern const sx_layout sxan_freearc_index1;
extern const sx_layout sxan_freearc_type2;
extern const sx_layout sxan_freearc_count2;
extern const sx_layout sxan_freearc_offset2;
extern const sx_layout sxan_freearc_size2;
extern const sx_layout sxan_freearc_packed2;
extern const sx_layout sxan_freearc_index2;
extern const sx_layout sxan_freearc_type3;
extern const sx_layout sxan_freearc_count3;
extern const sx_layout sxan_freearc_offset3;
extern const sx_layout sxan_freearc_size3;
extern const sx_layout sxan_freearc_packed3;
extern const sx_layout sxan_freearc_index3;
extern const sx_layout sxan_freearc_type4;
extern const sx_layout sxan_freearc_count4;
extern const sx_layout sxan_freearc_offset4;
extern const sx_layout sxan_freearc_size4;
extern const sx_layout sxan_freearc_packed4;
extern const sx_layout sxan_freearc_index4;
extern const sx_layout sxan_freearc_type5;
extern const sx_layout sxan_freearc_count5;
extern const sx_layout sxan_freearc_offset5;
extern const sx_layout sxan_freearc_size5;
extern const sx_layout sxan_freearc_packed5;
extern const sx_layout sxan_freearc_index5;
extern const sx_layout sxan_freearc_type6;
extern const sx_layout sxan_freearc_count6;
extern const sx_layout sxan_freearc_offset6;
extern const sx_layout sxan_freearc_size6;
extern const sx_layout sxan_freearc_packed6;
extern const sx_layout sxan_freearc_index6;
extern const sx_layout sxan_freearc_type7;
extern const sx_layout sxan_freearc_count7;
extern const sx_layout sxan_freearc_offset7;
extern const sx_layout sxan_freearc_size7;
extern const sx_layout sxan_freearc_packed7;
extern const sx_layout sxan_freearc_index7;
extern const sx_layout sxan_freearc_type8;
extern const sx_layout sxan_freearc_count8;
extern const sx_layout sxan_freearc_offset8;
extern const sx_layout sxan_freearc_size8;
extern const sx_layout sxan_freearc_packed8;
extern const sx_layout sxan_freearc_index8;
extern const sx_layout sxan_freearc_type9;
extern const sx_layout sxan_freearc_count9;
extern const sx_layout sxan_freearc_offset9;
extern const sx_layout sxan_freearc_size9;
extern const sx_layout sxan_freearc_packed9;
extern const sx_layout sxan_freearc_index9;
extern const sx_layout sxan_zpaq_block;
extern const sx_layout sxan_zpaq_model;
extern const sx_layout sxan_zpaq_locator;
extern const sx_layout sxan_zpaq_marker;
extern const sx_layout sxan_zpaq_stored_run;
extern const sx_layout sxan_zpaq_sha1;
extern const sx_layout sxan_zpaq_comment;
extern const sx_layout sxan_zpaq_cons;
extern const sx_layout sxan_zpaq_cm;
extern const sx_layout sxan_zpaq_icm;
extern const sx_layout sxan_zpaq_match;
extern const sx_layout sxan_zpaq_avg;
extern const sx_layout sxan_zpaq_mix2;
extern const sx_layout sxan_zpaq_mix;
extern const sx_layout sxan_zpaq_isse;
extern const sx_layout sxan_zpaq_sse;
bool sxan_span(sx_context*c,uint64_t p,uint64_t n);
bool sxan_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxan_uint(const uint8_t*b,unsigned n,bool be);
bool sxan_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxan_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxan_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxan_zlen(sx_context*c,uint64_t p,uint64_t end,uint64_t*n);
bool sxan_finish(sx_context*c);
bool sxan_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n);
bool sxan_pe_overlay(sx_context*c,uint64_t*out);
bool sxan_named(sx_context*c,uint64_t p,uint64_t n);
bool sxan_callback(sx_context*c,unsigned kind);
bool sxan_ckpedp(sx_context*c);
bool sxan_parsec(sx_context*c);
bool sxan_lha(sx_context*c);

/* Per-format walkers, called by the family's build. */
bool sx_is3_build(sx_context *c);  /* installer/is3/xx_is3_data.c */
bool sx_is5_build(sx_context *c);  /* installer/is5/xx_is5_data.c */
bool sx_is11_build(sx_context *c);  /* installer/is11/xx_is11_data.c */
bool sx_gksetup_build(sx_context *c);  /* installer/gksetup/xx_gksetup_data.c */
bool sx_pcinstall_build(sx_context *c);  /* installer/pcinstall/xx_pcinstall_data.c */
bool sx_finstall_build(sx_context *c);  /* installer/finstall/xx_finstall_data.c */
bool sx_ifah_installer_build(sx_context *c);  /* installer/ifah_installer/xx_ifah_installer_data.c */
bool sx_o_setup_build(sx_context *c);  /* installer/o_setup/xx_o_setup_data.c */
bool sx_pc_install_setup_build(sx_context *c);  /* installer/pc_install_setup/xx_pc_install_setup_data.c */
bool sx_rtpatch_setup_data_build(sx_context *c);  /* installer/rtpatch_setup_data/xx_rtpatch_setup_data_data.c */
bool sx_spoon_installer_build(sx_context *c);  /* installer/spoon_installer/xx_spoon_installer_data.c */
bool sx_installshield_issetupstream_build(sx_context *c);  /* installer/installshield_issetupstream/xx_installshield_issetupstream_data.c */
bool sx_eschalon_setup_epsf_build(sx_context *c);  /* installer/eschalon_setup_epsf/xx_eschalon_setup_epsf_data.c */
bool sx_setup_factory_build(sx_context *c);  /* installer/setup_factory/xx_setup_factory_data.c */
bool sx_westwood_pak_build(sx_context *c);  /* game/westwood_pak/xx_westwood_pak_data.c */
bool sx_ckp_build(sx_context *c);  /* game/ckp/xx_ckp_data.c */
bool sx_edp_build(sx_context *c);  /* game/edp/xx_edp_data.c */
bool sx_parsec_rib_build(sx_context *c);  /* game/parsec_rib/xx_parsec_rib_data.c */
bool sx_parsec_archive_build(sx_context *c);  /* game/parsec_archive/xx_parsec_archive_data.c */
bool sx_ptero_bigf_build(sx_context *c);  /* game/ptero_bigf/xx_ptero_bigf_data.c */
bool sx_pirs_build(sx_context *c);  /* game/pirs/xx_pirs_data.c */
bool sx_sbpak_build(sx_context *c);  /* game/sbpak/xx_sbpak_data.c */
bool sx_titan_quest_build(sx_context *c);  /* game/titan_quest/xx_titan_quest_data.c */
bool sx_cgjp_build(sx_context *c);  /* game/cgjp/xx_cgjp_data.c */
bool sx_birdies_build(sx_context *c);  /* game/birdies/xx_birdies_data.c */
bool sx_xuiz_build(sx_context *c);  /* game/xuiz/xx_xuiz_data.c */
bool sx_wii_wad_build(sx_context *c);  /* game/wii_wad/xx_wii_wad_data.c */
bool sx_freearc_build(sx_context *c);  /* archive/freearc/xx_freearc_data.c */
bool sx_zpaq_build(sx_context *c);  /* archive/zpaq/xx_zpaq_data.c */
bool sx_bytekiller_build(sx_context *c);  /* archive/bytekiller/xx_bytekiller_data.c */
bool sx_dcs_build(sx_context *c);  /* archive/dcs/xx_dcs_data.c */
bool sx_audials_build(sx_context *c);  /* archive/audials/xx_audials_data.c */
bool sx_osl2000_build(sx_context *c);  /* archive/osl2000/xx_osl2000_data.c */
bool sx_microfox_put_build(sx_context *c);  /* archive/microfox_put/xx_microfox_put_data.c */
bool sx_sar_build(sx_context *c);  /* archive/sar/xx_sar_data.c */

#endif
