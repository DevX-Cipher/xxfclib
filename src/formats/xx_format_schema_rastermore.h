/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The rastermore schema family: what its family unit (xx_format_schema_rastermore.c)
 * and its formats' data files share. Formats: valve vtf; openexr; jpeg2000 jp2; nintendo bntx; sega gvr; iff ilbm; utah rle; dpx; cineon; aseprite; godot ctex; jbig2; fujifilm raf; sigma x3f; minolta mrw; basis texture. */
#ifndef XX_FORMAT_SCHEMA_RASTERMORE_H
#define XX_FORMAT_SCHEMA_RASTERMORE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxrm_vtf70_header;
extern const sx_layout sxrm_vtf72_header;
extern const sx_layout sxrm_exr_header;
extern const sx_layout sxrm_exr_attribute_length;
extern const sx_layout sxrm_exr_channel;
extern const sx_layout sxrm_exr_box2i;
extern const sx_layout sxrm_exr_float;
extern const sx_layout sxrm_exr_v2f;
extern const sx_layout sxrm_exr_compression;
extern const sx_layout sxrm_exr_line_order;
extern const sx_layout sxrm_exr_chunk_offset;
extern const sx_layout sxrm_exr_scanline_chunk;
extern const sx_layout sxrm_jp2_box;
extern const sx_layout sxrm_jp2_extended_size;
extern const sx_layout sxrm_jp2_signature;
extern const sx_layout sxrm_jp2_file_type;
extern const sx_layout sxrm_jp2_compatible_brand;
extern const sx_layout sxrm_jp2_image_header;
extern const sx_layout sxrm_jp2_color_header;
extern const sx_layout sxrm_jp2_enumerated_color;
extern const sx_layout sxrm_j2k_marker;
extern const sx_layout sxrm_j2k_segment_length;
extern const sx_layout sxrm_j2k_siz;
extern const sx_layout sxrm_j2k_component;
extern const sx_layout sxrm_j2k_sot;
extern const sx_layout sxrm_bntx_header;
extern const sx_layout sxrm_bntx_container;
extern const sx_layout sxrm_bntx_block;
extern const sx_layout sxrm_bntx_texture_info;
extern const sx_layout sxrm_bntx_pointer;
extern const sx_layout sxrm_bntx_string_length;
extern const sx_layout sxrm_bntx_relocation_header;
extern const sx_layout sxrm_gvr_prefix;
extern const sx_layout sxrm_gvr_dimensions;
extern const sx_layout sxrm_ilbm_form;
extern const sx_layout sxrm_ilbm_chunk;
extern const sx_layout sxrm_ilbm_bitmap_header;
extern const sx_layout sxrm_ilbm_palette_entry;
extern const sx_layout sxrm_ilbm_view_mode;
extern const sx_layout sxrm_utah_rle_header;
extern const sx_layout sxrm_utah_background;
extern const sx_layout sxrm_utah_colormap;
extern const sx_layout sxrm_utah_comment_length;
extern const sx_layout sxrm_utah_opcode;
extern const sx_layout sxrm_utah_long_opcode;
extern const sx_layout sxrm_utah_run_value;
extern const sx_layout sxrm_dpx_file_header_be;
extern const sx_layout sxrm_dpx_image_header_be;
extern const sx_layout sxrm_dpx_element_be;
extern const sx_layout sxrm_dpx_image_reserved_be;
extern const sx_layout sxrm_dpx_orientation_be;
extern const sx_layout sxrm_dpx_film_be;
extern const sx_layout sxrm_dpx_television_be;
extern const sx_layout sxrm_cineon_file_header_be;
extern const sx_layout sxrm_cineon_image_header_be;
extern const sx_layout sxrm_cineon_channel_be;
extern const sx_layout sxrm_cineon_color_be;
extern const sx_layout sxrm_cineon_data_format_be;
extern const sx_layout sxrm_cineon_origin_be;
extern const sx_layout sxrm_cineon_film_be;
extern const sx_layout sxrm_dpx_file_header_le;
extern const sx_layout sxrm_dpx_image_header_le;
extern const sx_layout sxrm_dpx_element_le;
extern const sx_layout sxrm_dpx_image_reserved_le;
extern const sx_layout sxrm_dpx_orientation_le;
extern const sx_layout sxrm_dpx_film_le;
extern const sx_layout sxrm_dpx_television_le;
extern const sx_layout sxrm_cineon_file_header_le;
extern const sx_layout sxrm_cineon_image_header_le;
extern const sx_layout sxrm_cineon_channel_le;
extern const sx_layout sxrm_cineon_color_le;
extern const sx_layout sxrm_cineon_data_format_le;
extern const sx_layout sxrm_cineon_origin_le;
extern const sx_layout sxrm_cineon_film_le;
extern const sx_layout sxrm_aseprite_header;
extern const sx_layout sxrm_aseprite_frame;
extern const sx_layout sxrm_aseprite_chunk;
extern const sx_layout sxrm_aseprite_layer;
extern const sx_layout sxrm_aseprite_layer_uuid;
extern const sx_layout sxrm_aseprite_cel;
extern const sx_layout sxrm_aseprite_cel_dimensions;
extern const sx_layout sxrm_aseprite_linked_cel;
extern const sx_layout sxrm_aseprite_palette;
extern const sx_layout sxrm_aseprite_palette_entry;
extern const sx_layout sxrm_aseprite_string_length;
extern const sx_layout sxrm_aseprite_user_flags;
extern const sx_layout sxrm_aseprite_rgba;
extern const sx_layout sxrm_godot_ctex_header;
extern const sx_layout sxrm_jbig2_file_header;
extern const sx_layout sxrm_jbig2_page_count;
extern const sx_layout sxrm_jbig2_segment_prefix;
extern const sx_layout sxrm_jbig2_reference1;
extern const sx_layout sxrm_jbig2_reference2;
extern const sx_layout sxrm_jbig2_reference4;
extern const sx_layout sxrm_jbig2_segment_tail1;
extern const sx_layout sxrm_jbig2_segment_tail4;
extern const sx_layout sxrm_jbig2_page_info;
extern const sx_layout sxrm_jbig2_region;
extern const sx_layout sxrm_jbig2_extension;
extern const sx_layout sxrm_raf_header;
extern const sx_layout sxrm_raf_metadata_count;
extern const sx_layout sxrm_raf_metadata_entry;
extern const sx_layout sxrm_raf_dimensions;
extern const sx_layout sxrm_x3f_header20;
extern const sx_layout sxrm_x3f_header21;
extern const sx_layout sxrm_x3f_header23;
extern const sx_layout sxrm_x3f_directory_offset;
extern const sx_layout sxrm_x3f_directory;
extern const sx_layout sxrm_x3f_directory_entry;
extern const sx_layout sxrm_x3f_image;
extern const sx_layout sxrm_x3f_camf2;
extern const sx_layout sxrm_x3f_properties;
extern const sx_layout sxrm_x3f_property;
extern const sx_layout sxrm_mrw_header;
extern const sx_layout sxrm_mrw_chunk;
extern const sx_layout sxrm_mrw_prd;
extern const sx_layout sxrm_mrw_white_balance;
extern const sx_layout sxrm_mrw_tiff_header_le;
extern const sx_layout sxrm_mrw_tiff_header_be;
extern const sx_layout sxrm_basis_header;
extern const sx_layout sxrm_basis_slice;
bool sxrm_span(sx_context *c,uint64_t p,uint64_t n);
bool sxrm_read(sx_context *c,uint64_t p,void *b,size_t n);
uint64_t sxrm_uint(const uint8_t *b,unsigned n,bool be);
uint16_t sxrm16(const uint8_t *b,bool be);
uint32_t sxrm32(const uint8_t *b,bool be);
bool sxrm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n);
bool sxrm_add(sx_context *c,const sx_layout *l,uint64_t p);

/* Per-format walkers, called by the family's build. */
bool sx_valve_vtf_build(sx_context *c);  /* image/valve_vtf/xx_valve_vtf_data.c */
bool sx_openexr_build(sx_context *c);  /* image/openexr/xx_openexr_data.c */
bool sx_jpeg2000_jp2_build(sx_context *c);  /* image/jpeg2000_jp2/xx_jpeg2000_jp2_data.c */
bool sx_nintendo_bntx_build(sx_context *c);  /* image/nintendo_bntx/xx_nintendo_bntx_data.c */
bool sx_sega_gvr_build(sx_context *c);  /* image/sega_gvr/xx_sega_gvr_data.c */
bool sx_iff_ilbm_build(sx_context *c);  /* image/iff_ilbm/xx_iff_ilbm_data.c */
bool sx_utah_rle_build(sx_context *c);  /* image/utah_rle/xx_utah_rle_data.c */
bool sx_dpx_build(sx_context *c);  /* image/dpx/xx_dpx_data.c */
bool sx_cineon_build(sx_context *c);  /* image/cineon/xx_cineon_data.c */
bool sx_aseprite_build(sx_context *c);  /* image/aseprite/xx_aseprite_data.c */
bool sx_godot_ctex_build(sx_context *c);  /* image/godot_ctex/xx_godot_ctex_data.c */
bool sx_jbig2_build(sx_context *c);  /* image/jbig2/xx_jbig2_data.c */
bool sx_fujifilm_raf_build(sx_context *c);  /* image/fujifilm_raf/xx_fujifilm_raf_data.c */
bool sx_sigma_x3f_build(sx_context *c);  /* image/sigma_x3f/xx_sigma_x3f_data.c */
bool sx_minolta_mrw_build(sx_context *c);  /* image/minolta_mrw/xx_minolta_mrw_data.c */
bool sx_basis_texture_build(sx_context *c);  /* image/basis_texture/xx_basis_texture_data.c */

#endif
