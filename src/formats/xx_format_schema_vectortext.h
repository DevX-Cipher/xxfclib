/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The vectortext schema family: what its family unit (xx_format_schema_vectortext.c)
 * and its formats' data files share. Formats: vrml scene; renderman rib; opengex model; openusd usda; imagemagick mvg; motif uil; step part21; ogc wkt; mapinfo mif; collada dae; tiled tmx; ufo glif; imagemagick miff; nasa vicar; hpgl plot; iges model; gerber rs274x; excellon drill; jedec fuse; usgs dem. */
#ifndef XX_FORMAT_SCHEMA_VECTORTEXT_H
#define XX_FORMAT_SCHEMA_VECTORTEXT_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Bounded physical tokens. Whitespace and unparsed bodies retain raw spans. */
typedef struct sxvtx_cursor {sx_context*c;uint8_t*b;int64_t n,p;} sxvtx_cursor;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxvtx_keyword;
extern const sx_layout sxvtx_name;
extern const sx_layout sxvtx_string_value;
extern const sx_layout sxvtx_record_text;
extern const sx_layout sxvtx_units;
extern const sx_layout sxvtx_fuse_count;
extern const sx_layout sxvtx_pin_count;
extern const sx_layout sxvtx_fuse_index;
extern const sx_layout sxvtx_default_fuse;
extern const sx_layout sxvtx_security_fuse;
extern const sx_layout sxvtx_entity_type;
extern const sx_layout sxvtx_directory_reference;
extern const sx_layout sxvtx_parameter_reference;
extern const sx_layout sxvtx_level;
extern const sx_layout sxvtx_line_font_pattern;
extern const sx_layout sxvtx_line_weight;
extern const sx_layout sxvtx_color_number;
extern const sx_layout sxvtx_form_number;
extern const sx_layout sxvtx_profile_count;
extern const sx_layout sxvtx_row_count;
extern const sx_layout sxvtx_column_number;
extern const sx_layout sxvtx_elevation_sample;
extern const sx_layout sxvtx_dem_level;
extern const sx_layout sxvtx_elevation_pattern;
extern const sx_layout sxvtx_reference_system;
extern const sx_layout sxvtx_zone;
extern const sx_layout sxvtx_ground_unit;
extern const sx_layout sxvtx_elevation_unit;
extern const sx_layout sxvtx_polygon_side_count;
extern const sx_layout sxvtx_accuracy_code;
extern const sx_layout sxvtx_tool_number;
extern const sx_layout sxvtx_aperture_number;
extern const sx_layout sxvtx_command_code;
extern const sx_layout sxvtx_x;
extern const sx_layout sxvtx_y;
extern const sx_layout sxvtx_rotation;
extern const sx_layout sxvtx_line_width;
extern const sx_layout sxvtx_real_value;
extern const sx_layout sxvtx_encoded_x;
extern const sx_layout sxvtx_encoded_y;
extern const sx_layout sxvtx_radius;
extern const sx_layout sxvtx_diameter;
extern const sx_layout sxvtx_pen_number;
extern const sx_layout sxvtx_zero_suppression;
extern const sx_layout sxvtx_label_terminator;
extern const sx_layout sxvtx_x_integer_digits;
extern const sx_layout sxvtx_x_fraction_digits;
extern const sx_layout sxvtx_y_integer_digits;
extern const sx_layout sxvtx_y_fraction_digits;
extern const sx_layout sxvtx_vertex_count;
extern const sx_layout sxvtx_d_code;
extern const sx_layout sxvtx_aperture_width;
extern const sx_layout sxvtx_aperture_height;
extern const sx_layout sxvtx_hole_diameter;
extern const sx_layout sxvtx_coordinate_notation;
extern const sx_layout sxvtx_polarity;
extern const sx_layout sxvtx_aperture_shape;
extern const sx_layout sxvtx_row_number;
extern const sx_layout sxvtx_column_count;
extern const sx_layout sxvtx_structure_reference;
extern const sx_layout sxvtx_view_reference;
extern const sx_layout sxvtx_transform_reference;
extern const sx_layout sxvtx_label_display_reference;
extern const sx_layout sxvtx_parameter_line_count;
extern const sx_layout sxvtx_entity_subscript;
extern const sx_layout sxvtx_section_record_count;
extern const sx_layout sxvtx_dem_x;
extern const sx_layout sxvtx_dem_y;
extern const sx_layout sxvtx_dem_coordinate_value;
extern const sx_layout sxvtx_dem_minimum_elevation;
extern const sx_layout sxvtx_dem_maximum_elevation;
extern const sx_layout sxvtx_dem_rotation;
extern const sx_layout sxvtx_dem_x_resolution;
extern const sx_layout sxvtx_dem_y_resolution;
extern const sx_layout sxvtx_dem_z_resolution;
extern const sx_layout sxvtx_dem_elevation_datum;
extern const sx_layout sxvtx_dem_projection_parameter;
extern const sx_layout sxvtx_iges_status;
extern const sx_layout sxvtx_checksum;
extern const sx_layout sxvtx_transmission_checksum;
extern const sx_layout sxvtx_fuse_bits;
extern const sx_layout sxvtx_jedec_stx;
extern const sx_layout sxvtx_jedec_etx;
extern const sx_layout sxvtx_iges_record_label;
bool sxvtx_space(uint8_t x);
bool sxvtx_emit(sxvtx_cursor*q,const sx_layout*l,int64_t a,int64_t z);
bool sxvtx_eq(sxvtx_cursor*q,int64_t a,int64_t z,const char*s);
bool sxvtx_uint_at(sxvtx_cursor*q,int64_t a,int64_t z,uint64_t*out);
bool sxvtx_nonblank(sxvtx_cursor*q,int64_t a,int64_t z);
bool sxvtx_image_header(sxvtx_cursor*q,bool vicar);
bool sxvtx_xml(sxvtx_cursor*q,int mode);
bool sxvtx_lex(sxvtx_cursor*q,xx_file_type_t type);

/* Per-format walkers, called by the family's build. */
bool sx_vrml_scene_build(sxvtx_cursor*q,xx_file_type_t type);  /* image/vrml_scene/xx_vrml_scene_data.c */
bool sx_renderman_rib_build(sxvtx_cursor*q,xx_file_type_t type);  /* image/renderman_rib/xx_renderman_rib_data.c */
bool sx_opengex_model_build(sxvtx_cursor*q,xx_file_type_t type);  /* image/opengex_model/xx_opengex_model_data.c */
bool sx_openusd_usda_build(sxvtx_cursor*q,xx_file_type_t type);  /* image/openusd_usda/xx_openusd_usda_data.c */
bool sx_imagemagick_mvg_build(sxvtx_cursor*q,xx_file_type_t type);  /* image/imagemagick_mvg/xx_imagemagick_mvg_data.c */
bool sx_motif_uil_build(sxvtx_cursor*q,xx_file_type_t type);  /* image/motif_uil/xx_motif_uil_data.c */
bool sx_step_part21_build(sxvtx_cursor*q,xx_file_type_t type);  /* science/step_part21/xx_step_part21_data.c */
bool sx_ogc_wkt_build(sxvtx_cursor*q,xx_file_type_t type);  /* science/ogc_wkt/xx_ogc_wkt_data.c */
bool sx_mapinfo_mif_build(sxvtx_cursor*q,xx_file_type_t type);  /* science/mapinfo_mif/xx_mapinfo_mif_data.c */
bool sx_collada_dae_build(sxvtx_cursor*q);  /* image/collada_dae/xx_collada_dae_data.c */
bool sx_tiled_tmx_build(sxvtx_cursor*q);  /* game/tiled_tmx/xx_tiled_tmx_data.c */
bool sx_ufo_glif_build(sxvtx_cursor*q);  /* font/ufo_glif/xx_ufo_glif_data.c */
bool sx_imagemagick_miff_build(sxvtx_cursor*q);  /* image/imagemagick_miff/xx_imagemagick_miff_data.c */
bool sx_nasa_vicar_build(sxvtx_cursor*q);  /* science/nasa_vicar/xx_nasa_vicar_data.c */
bool sx_hpgl_plot_build(sxvtx_cursor*q);  /* image/hpgl_plot/xx_hpgl_plot_data.c */
bool sx_iges_model_build(sxvtx_cursor*q);  /* science/iges_model/xx_iges_model_data.c */
bool sx_gerber_rs274x_build(sxvtx_cursor*q);  /* science/gerber_rs274x/xx_gerber_rs274x_data.c */
bool sx_excellon_drill_build(sxvtx_cursor*q);  /* science/excellon_drill/xx_excellon_drill_data.c */
bool sx_jedec_fuse_build(sxvtx_cursor*q);  /* firmware/jedec_fuse/xx_jedec_fuse_data.c */
bool sx_usgs_dem_build(sxvtx_cursor*q);  /* science/usgs_dem/xx_usgs_dem_data.c */

#endif
