/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The systemlater schema family: what its family unit (xx_format_schema_systemlater.c)
 * and its formats' data files share. Formats: LOFI; DMS; SAVEDSKF; DISKDUPE; PMDISKCOPY; QRST; HDCOPY; APRIDISK; DISKCOPY42; NRG; ISZ; MAME_FLOPPY_IMAGE_MFI; SDI; NHD; VIRTUAL98; ANEX86_HDI; THOMSON_SAP; DMK; AMIGA_EXT_ADF; AMIGA_OLD_EXT_ADF; SPECTRUM_UDI; MOOF; BOCHS_GROWING; VMDK_COWD_SPARSE; VMDK_SESPARSE; PARTCLONE_IMAGE. */
#ifndef XX_FORMAT_SCHEMA_SYSTEMLATER_H
#define XX_FORMAT_SCHEMA_SYSTEMLATER_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsl_lofi_header;
extern const sx_layout sxsl_lofi_index;
extern const sx_layout sxsl_lofi_segment;
extern const sx_layout sxsl_lofi_lzma_header;
extern const sx_layout sxsl_savedskf_header;
extern const sx_layout sxsl_diskdupe_header;
extern const sx_layout sxsl_diskdupe_track;
extern const sx_layout sxsl_pmdiskcopy_header;
extern const sx_layout sxsl_qrst_header;
extern const sx_layout sxsl_qrst_track;
extern const sx_layout sxsl_qrst_fill;
extern const sx_layout sxsl_qrst_encoded_size;
extern const sx_layout sxsl_hdcopy_header;
extern const sx_layout sxsl_hdcopy_block;
extern const sx_layout sxsl_apridisk_header;
extern const sx_layout sxsl_apridisk_record;
extern const sx_layout sxsl_diskcopy42_header;
extern const sx_layout sxsl_isz_header;
extern const sx_layout sxsl_isz_checksum_tail;
extern const sx_layout sxsl_isz_encoded_pointer1;
extern const sx_layout sxsl_isz_encoded_pointer2;
extern const sx_layout sxsl_isz_encoded_pointer3;
extern const sx_layout sxsl_isz_encoded_pointer4;
extern const sx_layout sxsl_isz_encoded_segment;
extern const sx_layout sxsl_mfi_header;
extern const sx_layout sxsl_mfi_track;
extern const sx_layout sxsl_sdi_header;
extern const sx_layout sxsl_sdi_section;
extern const sx_layout sxsl_nhd_header;
extern const sx_layout sxsl_virtual98_header;
extern const sx_layout sxsl_anex86_header;
extern const sx_layout sxsl_sap_header;
extern const sx_layout sxsl_sap_sector;
extern const sx_layout sxsl_sap_checksum;
extern const sx_layout sxsl_dmk_header;
extern const sx_layout sxsl_dmk_idam_pointer;
extern const sx_layout sxsl_dmk_idam;
extern const sx_layout sxsl_udi_header;
extern const sx_layout sxsl_udi_track;
extern const sx_layout sxsl_udi_compressed_track;
extern const sx_layout sxsl_udi_checksum;
extern const sx_layout sxsl_moof_header;
extern const sx_layout sxsl_moof_chunk;
extern const sx_layout sxsl_moof_info;
extern const sx_layout sxsl_moof_track_map;
extern const sx_layout sxsl_moof_track;
extern const sx_layout sxsl_bochs_growing_v1;
extern const sx_layout sxsl_bochs_growing_v2;
extern const sx_layout sxsl_bochs_catalog_entry;
extern const sx_layout sxsl_bochs_bitmap_byte;
extern const sx_layout sxsl_partclone_header_le;
extern const sx_layout sxsl_partclone_bitmap_crc_le;
extern const sx_layout sxsl_partclone_header_be;
extern const sx_layout sxsl_partclone_bitmap_crc_be;
extern const sx_layout sxsl_dms_header;
extern const sx_layout sxsl_dms_track;
extern const sx_layout sxsl_nrg_footer32;
extern const sx_layout sxsl_nrg_dao_track32;
extern const sx_layout sxsl_nrg_etn_track32;
extern const sx_layout sxsl_nrg_footer64;
extern const sx_layout sxsl_nrg_dao_track64;
extern const sx_layout sxsl_nrg_etn_track64;
extern const sx_layout sxsl_nrg_chunk;
extern const sx_layout sxsl_nrg_dao_header;
extern const sx_layout sxsl_nrg_cuex;
extern const sx_layout sxsl_nrg_cues;
extern const sx_layout sxsl_nrg_session;
extern const sx_layout sxsl_nrg_media;
extern const sx_layout sxsl_cowd_header;
extern const sx_layout sxsl_cowd_root;
extern const sx_layout sxsl_cowd_child;
extern const sx_layout sxsl_cowd_tail;
extern const sx_layout sxsl_cowd_directory;
extern const sx_layout sxsl_cowd_grain;
extern const sx_layout sxsl_sesparse_header;
extern const sx_layout sxsl_sesparse_volatile;
extern const sx_layout sxsl_sesparse_directory;
extern const sx_layout sxsl_sesparse_grain;
extern const sx_layout sxsl_dmk_idam_doubled;
extern const sx_layout sxsl_partclone_bitmap_byte;
extern const sx_layout sxsl_partclone_data_checksum4;
extern const sx_layout sxsl_partclone_data_checksum16;
bool sxsl_span(sx_context*c,uint64_t p,uint64_t n);
bool sxsl_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxsl_uint(const uint8_t*b,unsigned n,bool be);
uint16_t sxsl16(const uint8_t*b);
uint32_t sxsl32(const uint8_t*b);
bool sxsl_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxsl_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxsl_extadf(sx_context*c,bool old);
bool sxsl_finish(sx_context*c);

/* Per-format walkers, called by the family's build. */
bool sx_lofi_build(sx_context *c);  /* filesystem/lofi/xx_lofi_data.c */
bool sx_dms_build(sx_context *c);  /* filesystem/dms/xx_dms_data.c */
bool sx_savedskf_build(sx_context *c);  /* filesystem/savedskf/xx_savedskf_data.c */
bool sx_diskdupe_build(sx_context *c);  /* filesystem/diskdupe/xx_diskdupe_data.c */
bool sx_pmdiskcopy_build(sx_context *c);  /* filesystem/pmdiskcopy/xx_pmdiskcopy_data.c */
bool sx_qrst_build(sx_context *c);  /* filesystem/qrst/xx_qrst_data.c */
bool sx_hdcopy_build(sx_context *c);  /* filesystem/hdcopy/xx_hdcopy_data.c */
bool sx_apridisk_build(sx_context *c);  /* filesystem/apridisk/xx_apridisk_data.c */
bool sx_diskcopy42_build(sx_context *c);  /* filesystem/diskcopy42/xx_diskcopy42_data.c */
bool sx_nrg_build(sx_context *c);  /* filesystem/nrg/xx_nrg_data.c */
bool sx_isz_build(sx_context *c);  /* filesystem/isz/xx_isz_data.c */
bool sx_mame_floppy_image_mfi_build(sx_context *c);  /* filesystem/mame_floppy_image_mfi/xx_mame_floppy_image_mfi_data.c */
bool sx_sdi_build(sx_context *c);  /* filesystem/sdi/xx_sdi_data.c */
bool sx_nhd_build(sx_context *c);  /* filesystem/nhd/xx_nhd_data.c */
bool sx_virtual98_build(sx_context *c);  /* filesystem/virtual98/xx_virtual98_data.c */
bool sx_anex86_hdi_build(sx_context *c);  /* filesystem/anex86_hdi/xx_anex86_hdi_data.c */
bool sx_thomson_sap_build(sx_context *c);  /* filesystem/thomson_sap/xx_thomson_sap_data.c */
bool sx_dmk_build(sx_context *c);  /* filesystem/dmk/xx_dmk_data.c */
bool sx_amiga_ext_adf_build(sx_context *c);  /* filesystem/amiga_ext_adf/xx_amiga_ext_adf_data.c */
bool sx_amiga_old_ext_adf_build(sx_context *c);  /* filesystem/amiga_old_ext_adf/xx_amiga_old_ext_adf_data.c */
bool sx_spectrum_udi_build(sx_context *c);  /* filesystem/spectrum_udi/xx_spectrum_udi_data.c */
bool sx_moof_build(sx_context *c);  /* filesystem/moof/xx_moof_data.c */
bool sx_bochs_growing_build(sx_context *c);  /* filesystem/bochs_growing/xx_bochs_growing_data.c */
bool sx_vmdk_cowd_sparse_build(sx_context *c);  /* filesystem/vmdk_cowd_sparse/xx_vmdk_cowd_sparse_data.c */
bool sx_vmdk_sesparse_build(sx_context *c);  /* filesystem/vmdk_sesparse/xx_vmdk_sesparse_data.c */
bool sx_partclone_image_build(sx_context *c);  /* filesystem/partclone_image/xx_partclone_image_data.c */

#endif
