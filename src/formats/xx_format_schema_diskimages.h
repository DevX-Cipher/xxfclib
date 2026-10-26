/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The diskimages schema family: what its family unit (xx_format_schema_diskimages.c)
 * and its formats' data files share. Formats: AnaDisk sector disk image; PCE TransCopy TC bitstream disk image; CopyQM; IMD; FDI; NEC PC-98 FDI; TeleDisk; pc98 d88; amiga ipf. */
#ifndef XX_FORMAT_SCHEMA_DISKIMAGES_H
#define XX_FORMAT_SCHEMA_DISKIMAGES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxdi_anadisk_sector_header;
extern const sx_layout sxdi_transcopy_header;
extern const sx_layout sxdi_transcopy_geometry;
extern const sx_layout sxdi_transcopy_track_offset;
extern const sx_layout sxdi_transcopy_track_length;
extern const sx_layout sxdi_copyqm_header;
extern const sx_layout sxdi_copyqm_rle_token;
extern const sx_layout sxdi_disk_fill_byte;
extern const sx_layout sxdi_imd_track_header;
extern const sx_layout sxdi_imd_sector_id;
extern const sx_layout sxdi_imd_cylinder_map;
extern const sx_layout sxdi_imd_head_map;
extern const sx_layout sxdi_imd_size_map;
extern const sx_layout sxdi_imd_sector_status;
extern const sx_layout sxdi_fdi_header;
extern const sx_layout sxdi_fdi_track_header;
extern const sx_layout sxdi_fdi_sector_header;
extern const sx_layout sxdi_nec_pc98_fdi_header;
extern const sx_layout sxdi_teledisk_header;
extern const sx_layout sxdi_teledisk_comment;
extern const sx_layout sxdi_teledisk_track;
extern const sx_layout sxdi_teledisk_end;
extern const sx_layout sxdi_teledisk_sector;
extern const sx_layout sxdi_teledisk_data_block;
extern const sx_layout sxdi_d88_disk_header;
extern const sx_layout sxdi_d88_track_offset;
extern const sx_layout sxdi_d88_sector_header;
extern const sx_layout sxdi_ipf_chunk_header;
extern const sx_layout sxdi_ipf_info;
extern const sx_layout sxdi_ipf_image;
extern const sx_layout sxdi_ipf_data;
extern const sx_layout sxdi_ipf_block_encoder1;
extern const sx_layout sxdi_ipf_block_encoder2;
bool sxdi_span(sx_context *c,uint64_t at,uint64_t n);
bool sxdi_read(sx_context *c,uint64_t at,void *p,size_t n);
uint16_t sxdi_le16(const uint8_t *p);
uint32_t sxdi_le32(const uint8_t *p);

/* Per-format walkers, called by the family's build. */
bool sx_pce_anadisk_build(sx_context *c);  /* filesystem/pce_anadisk/xx_pce_anadisk_data.c */
bool sx_pce_tc_build(sx_context *c);  /* filesystem/pce_tc/xx_pce_tc_data.c */
bool sx_copyqm_build(sx_context *c);  /* filesystem/copyqm/xx_copyqm_data.c */
bool sx_imd_build(sx_context *c);  /* filesystem/imd/xx_imd_data.c */
bool sx_fdi_build(sx_context *c);  /* filesystem/fdi/xx_fdi_data.c */
bool sx_nec_pc_98_fdi_build(sx_context *c);  /* filesystem/nec_pc_98_fdi/xx_nec_pc_98_fdi_data.c */
bool sx_teledisk_build(sx_context *c);  /* filesystem/teledisk/xx_teledisk_data.c */
bool sx_pc98_d88_build(sx_context *c);  /* filesystem/pc98_d88/xx_pc98_d88_data.c */
bool sx_amiga_ipf_build(sx_context *c);  /* filesystem/amiga_ipf/xx_amiga_ipf_data.c */

#endif
