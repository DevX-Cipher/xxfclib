/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The media schema family: what its family unit (xx_format_schema_media.c)
 * and its formats' data files share. Formats: tga; pcx; dds; photoshop_psd; farbfeld; sgi_rgb; sun_raster; avs_image; alias_pix; astc_texture; pkm_texture; ktx; ktx2; pvr; icns; xwd; font_psf; font_pcf; font_type1_pfb; font_bmfont; processing_vlw; numpy_npy; ucsc_nib; sequencing_scf; sequencing_abif; genomics_sff; matlab_mat4; matlab_mat5; hdf4. */
#ifndef XX_FORMAT_SCHEMA_MEDIA_H
#define XX_FORMAT_SCHEMA_MEDIA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxm_tga_header;
extern const sx_layout sxm_tga_footer;
extern const sx_layout sxm_pcx_header;
extern const sx_layout sxm_dds_header;
extern const sx_layout sxm_dds_dx10;
extern const sx_layout sxm_psd_header;
extern const sx_layout sxm_be_length32;
extern const sx_layout sxm_be_length64;
extern const sx_layout sxm_psd_compression;
extern const sx_layout sxm_farbfeld_header;
extern const sx_layout sxm_sgi_header;
extern const sx_layout sxm_be_offset32;
extern const sx_layout sxm_le_length32;
extern const sx_layout sxm_sun_raster_header;
extern const sx_layout sxm_avs_header;
extern const sx_layout sxm_alias_pix_header;
extern const sx_layout sxm_astc_header;
extern const sx_layout sxm_pkm_header;
extern const sx_layout sxm_ktx_header_le;
extern const sx_layout sxm_ktx_header_be;
extern const sx_layout sxm_ktx2_header;
extern const sx_layout sxm_ktx2_level;
extern const sx_layout sxm_pvr_header_le;
extern const sx_layout sxm_pvr_metadata_le;
extern const sx_layout sxm_pvr_header_be;
extern const sx_layout sxm_pvr_metadata_be;
extern const sx_layout sxm_icns_header;
extern const sx_layout sxm_icns_element;
extern const sx_layout sxm_xwd_header;
extern const sx_layout sxm_xwd_color;
extern const sx_layout sxm_psf1_header;
extern const sx_layout sxm_psf2_header;
extern const sx_layout sxm_pcf_header;
extern const sx_layout sxm_pcf_directory;
extern const sx_layout sxm_pfb_segment;
extern const sx_layout sxm_pfb_end;
extern const sx_layout sxm_bmfont_header;
extern const sx_layout sxm_bmfont_block;
extern const sx_layout sxm_bmfont_info;
extern const sx_layout sxm_bmfont_common;
extern const sx_layout sxm_bmfont_char;
extern const sx_layout sxm_bmfont_kerning;
extern const sx_layout sxm_vlw_header;
extern const sx_layout sxm_vlw_glyph;
extern const sx_layout sxm_npy_v1;
extern const sx_layout sxm_npy_v2;
extern const sx_layout sxm_nib_header_le;
extern const sx_layout sxm_nib_header_be;
extern const sx_layout sxm_scf_header;
extern const sx_layout sxm_abif_header;
extern const sx_layout sxm_abif_directory;
extern const sx_layout sxm_abif_inline_directory;
extern const sx_layout sxm_sff_header;
extern const sx_layout sxm_sff_read_header;
extern const sx_layout sxm_mat4_header_le;
extern const sx_layout sxm_mat5_header_le;
extern const sx_layout sxm_mat5_tag_le;
extern const sx_layout sxm_mat5_small_tag_le;
extern const sx_layout sxm_mat4_header_be;
extern const sx_layout sxm_mat5_header_be;
extern const sx_layout sxm_mat5_tag_be;
extern const sx_layout sxm_mat5_small_tag_be;
extern const sx_layout sxm_hdf4_dd_block;
extern const sx_layout sxm_hdf4_descriptor;
extern const sx_layout sxm_hdf4_first_block;
bool sxm_span(sx_context *c,uint64_t at,uint64_t n);
bool sxm_raw(sx_context *c,uint64_t at,uint64_t n);
bool sxm_tail(sx_context *c,uint64_t at);
bool sxm_fixed(sx_context *c,const sx_layout *l,int64_t bytes);

/* Per-format walkers, called by the family's build. */
bool sx_tga_build(sx_context *c);  /* image/tga/xx_tga_data.c */
bool sx_pcx_build(sx_context*c,uint8_t*h);  /* image/pcx/xx_pcx_data.c */
bool sx_dds_build(sx_context*c,uint8_t*h,size_t n);  /* image/dds/xx_dds_data.c */
bool sx_photoshop_psd_build(sx_context*c,uint8_t*h,size_t n);  /* image/photoshop_psd/xx_photoshop_psd_data.c */
bool sx_farbfeld_build(sx_context*c,uint8_t*h,size_t n);  /* image/farbfeld/xx_farbfeld_data.c */
bool sx_sgi_rgb_build(sx_context*c,uint8_t*h,size_t n);  /* image/sgi_rgb/xx_sgi_rgb_data.c */
bool sx_sun_raster_build(sx_context*c,uint8_t*h,size_t n);  /* image/sun_raster/xx_sun_raster_data.c */
bool sx_avs_image_build(sx_context*c,uint8_t*h,size_t n);  /* image/avs_image/xx_avs_image_data.c */
bool sx_alias_pix_build(sx_context*c,size_t n);  /* image/alias_pix/xx_alias_pix_data.c */
bool sx_astc_texture_build(sx_context*c,uint8_t*h,size_t n);  /* image/astc_texture/xx_astc_texture_data.c */
bool sx_pkm_texture_build(sx_context*c,uint8_t*h,size_t n);  /* image/pkm_texture/xx_pkm_texture_data.c */
bool sx_ktx_build(sx_context*c,uint8_t*h,size_t n);  /* image/ktx/xx_ktx_data.c */
bool sx_ktx2_build(sx_context*c,uint8_t*h,size_t n);  /* image/ktx2/xx_ktx2_data.c */
bool sx_pvr_build(sx_context*c,uint8_t*h,size_t n);  /* image/pvr/xx_pvr_data.c */
bool sx_icns_build(sx_context*c,uint8_t*h,size_t n);  /* image/icns/xx_icns_data.c */
bool sx_xwd_build(sx_context*c,uint8_t*h,size_t n);  /* image/xwd/xx_xwd_data.c */
bool sx_font_psf_build(sx_context*c,uint8_t*h,size_t n);  /* font/font_psf/xx_font_psf_data.c */
bool sx_font_pcf_build(sx_context*c,uint8_t*h,size_t n);  /* font/font_pcf/xx_font_pcf_data.c */
bool sx_font_type1_pfb_build(sx_context *c);  /* font/font_type1_pfb/xx_font_type1_pfb_data.c */
bool sx_font_bmfont_build(sx_context*c,uint8_t*h,size_t n);  /* font/font_bmfont/xx_font_bmfont_data.c */
bool sx_processing_vlw_build(sx_context*c,uint8_t*h,size_t n);  /* font/processing_vlw/xx_processing_vlw_data.c */
bool sx_numpy_npy_build(sx_context*c,uint8_t*h,size_t n);  /* science/numpy_npy/xx_numpy_npy_data.c */
bool sx_ucsc_nib_build(sx_context*c,uint8_t*h,size_t n);  /* science/ucsc_nib/xx_ucsc_nib_data.c */
bool sx_sequencing_scf_build(sx_context*c,uint8_t*h,size_t n);  /* science/sequencing_scf/xx_sequencing_scf_data.c */
bool sx_sequencing_abif_build(sx_context*c,uint8_t*h,size_t n);  /* science/sequencing_abif/xx_sequencing_abif_data.c */
bool sx_genomics_sff_build(sx_context*c,uint8_t*h,size_t n);  /* science/genomics_sff/xx_genomics_sff_data.c */
bool sx_matlab_mat4_build(sx_context *c);  /* science/matlab_mat4/xx_matlab_mat4_data.c */
bool sx_matlab_mat5_build(sx_context*c,uint8_t*h,size_t n);  /* science/matlab_mat5/xx_matlab_mat5_data.c */
bool sx_hdf4_build(sx_context*c,uint8_t*h,size_t n);  /* science/hdf4/xx_hdf4_data.c */

#endif
