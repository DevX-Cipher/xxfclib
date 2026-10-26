/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The systemtail schema family: what its family unit (xx_format_schema_systemtail.c)
 * and its formats' data files share. Formats: IRIXSA; SOS; Zoom disk image; TRDOS; CSIDOS; CopyDisk; Apricot; adam; pc magazine flp; WARP; LHWARP; COMPDISK; CRUNCHDISK; LISA_BLU; CISCOPY; COPYTAPE; WC_DISK_IMAGE; DRI_DISKCOPY; MAXI_DISK; RAY_DIM; RS_IDE; T98_HDD; PC_86F; FDX68_FDX; HEATHKIT_H17. */
#ifndef XX_FORMAT_SCHEMA_SYSTEMTAIL_H
#define XX_FORMAT_SCHEMA_SYSTEMTAIL_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxst_irixsa_header;
extern const sx_layout sxst_irixsa_directory_entry;
extern const sx_layout sxst_sos_boot_prefix;
extern const sx_layout sxst_sos_directory_entry;
extern const sx_layout sxst_zoom_header;
extern const sx_layout sxst_zoom_note_checksum;
extern const sx_layout sxst_zoom_chunk;
extern const sx_layout sxst_trdos_entry;
extern const sx_layout sxst_trdos_disk_descriptor;
extern const sx_layout sxst_csidos_root_block;
extern const sx_layout sxst_csidos_catalogue_block;
extern const sx_layout sxst_csidos_entry;
extern const sx_layout sxst_copydisk_header;
extern const sx_layout sxst_apricot_image_header;
extern const sx_layout sxst_apricot_chunk;
extern const sx_layout sxst_apricot_run;
extern const sx_layout sxst_adam_volume;
extern const sx_layout sxst_adam_entry;
extern const sx_layout sxst_adam_entry_split_prefix;
extern const sx_layout sxst_adam_entry_split_tail;
extern const sx_layout sxst_pcmag_flp_header;
extern const sx_layout sxst_warp_track;
extern const sx_layout sxst_lhwarp_header0;
extern const sx_layout sxst_lhwarp_header3;
extern const sx_layout sxst_lhwarp_cylinder0;
extern const sx_layout sxst_lhwarp_cylinder;
extern const sx_layout sxst_compdisk_header;
extern const sx_layout sxst_compdisk_cylinder;
extern const sx_layout sxst_crunchdisk_header;
extern const sx_layout sxst_crunchdisk_cylinder;
extern const sx_layout sxst_lisa_blu_header;
extern const sx_layout sxst_ciscopy_header;
extern const sx_layout sxst_ciscopy_track_state;
extern const sx_layout sxst_ciscopy_compression;
extern const sx_layout sxst_copytape_block;
extern const sx_layout sxst_copytape_mark;
extern const sx_layout sxst_copytape_separator;
extern const sx_layout sxst_wcdisk_header;
extern const sx_layout sxst_wcdisk_sector;
extern const sx_layout sxst_wcdisk_fill;
extern const sx_layout sxst_wcdisk_extra;
extern const sx_layout sxst_dri_signature;
extern const sx_layout sxst_dri_diskcopy_bpb;
extern const sx_layout sxst_maxidisk_header;
extern const sx_layout sxst_raydim_header_indices;
extern const sx_layout sxst_raydim_header_counts;
extern const sx_layout sxst_raydim_sector_status;
extern const sx_layout sxst_rside_header;
extern const sx_layout sxst_rside_identify;
extern const sx_layout sxst_t98_header;
extern const sx_layout sxst_pc86f_header;
extern const sx_layout sxst_pc86f_track_offset;
extern const sx_layout sxst_pc86f_track;
extern const sx_layout sxst_pc86f_track_extra;
extern const sx_layout sxst_fdx68_header;
extern const sx_layout sxst_fdx68_track;
extern const sx_layout sxst_h17_header;
extern const sx_layout sxst_h17_chunk;
extern const sx_layout sxst_h17_disk_format2;
extern const sx_layout sxst_h17_disk_format3;
extern const sx_layout sxst_h17_parameters1;
extern const sx_layout sxst_h17_parameters2;
extern const sx_layout sxst_h17_sector_metadata;
bool sxst_span(sx_context*c,uint64_t p,uint64_t n);
bool sxst_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxst_uint(const uint8_t*b,unsigned n,bool be);
uint16_t sxst16(const uint8_t*b);
uint32_t sxst32(const uint8_t*b);
bool sxst_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxst_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_irixsa_build(sx_context *c);  /* filesystem/irixsa/xx_irixsa_data.c */
bool sx_sos_build(sx_context *c);  /* filesystem/sos/xx_sos_data.c */
bool sx_zoom_build(sx_context *c);  /* filesystem/zoom/xx_zoom_data.c */
bool sx_trdos_build(sx_context *c);  /* filesystem/trdos/xx_trdos_data.c */
bool sx_csidos_build(sx_context *c);  /* filesystem/csidos/xx_csidos_data.c */
bool sx_copydisk_build(sx_context *c);  /* filesystem/copydisk/xx_copydisk_data.c */
bool sx_apricot_build(sx_context *c);  /* filesystem/apricot/xx_apricot_data.c */
bool sx_adam_build(sx_context *c);  /* filesystem/adam/xx_adam_data.c */
bool sx_pc_magazine_flp_build(sx_context *c);  /* filesystem/pc_magazine_flp/xx_pc_magazine_flp_data.c */
bool sx_warp_build(sx_context *c);  /* filesystem/warp/xx_warp_data.c */
bool sx_lhwarp_build(sx_context *c);  /* filesystem/lhwarp/xx_lhwarp_data.c */
bool sx_compdisk_build(sx_context *c);  /* filesystem/compdisk/xx_compdisk_data.c */
bool sx_crunchdisk_build(sx_context *c);  /* filesystem/crunchdisk/xx_crunchdisk_data.c */
bool sx_lisa_blu_build(sx_context *c);  /* filesystem/lisa_blu/xx_lisa_blu_data.c */
bool sx_ciscopy_build(sx_context *c);  /* filesystem/ciscopy/xx_ciscopy_data.c */
bool sx_copytape_build(sx_context *c);  /* filesystem/copytape/xx_copytape_data.c */
bool sx_wc_disk_image_build(sx_context *c);  /* filesystem/wc_disk_image/xx_wc_disk_image_data.c */
bool sx_dri_diskcopy_build(sx_context *c);  /* filesystem/dri_diskcopy/xx_dri_diskcopy_data.c */
bool sx_maxi_disk_build(sx_context *c);  /* filesystem/maxi_disk/xx_maxi_disk_data.c */
bool sx_ray_dim_build(sx_context *c);  /* filesystem/ray_dim/xx_ray_dim_data.c */
bool sx_rs_ide_build(sx_context *c);  /* filesystem/rs_ide/xx_rs_ide_data.c */
bool sx_t98_hdd_build(sx_context *c);  /* filesystem/t98_hdd/xx_t98_hdd_data.c */
bool sx_pc_86f_build(sx_context *c);  /* filesystem/pc_86f/xx_pc_86f_data.c */
bool sx_fdx68_fdx_build(sx_context *c);  /* filesystem/fdx68_fdx/xx_fdx68_fdx_data.c */
bool sx_heathkit_h17_build(sx_context *c);  /* filesystem/heathkit_h17/xx_heathkit_h17_data.c */

#endif
