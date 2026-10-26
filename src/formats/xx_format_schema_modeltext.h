/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The modeltext schema family: what its family unit (xx_format_schema_modeltext.c)
 * and its formats' data files share. Formats: polygon_ply; pointcloud_pcd; wavefront_obj; off_mesh; ac3d_model; xfig; autocad_dxf; font_bdf; font_afm; fontforge_sfd; gts_surface; bvh_motion; directx_x; lightwave_scene; metasequoia_mqo; autodesk_ase. */
#ifndef XX_FORMAT_SCHEMA_MODELTEXT_H
#define XX_FORMAT_SCHEMA_MODELTEXT_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Bounded physical tokens. Whitespace and unparsed bodies retain raw spans. */
typedef struct sxmt_cursor {sx_context*c;uint8_t*b;int64_t n,p;} sxmt_cursor;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmt_signature;
extern const sx_layout sxmt_version;
extern const sx_layout sxmt_encoding;
extern const sx_layout sxmt_element_name;
extern const sx_layout sxmt_property_name;
extern const sx_layout sxmt_property_type;
extern const sx_layout sxmt_count_type;
extern const sx_layout sxmt_field_type;
extern const sx_layout sxmt_object_type;
extern const sx_layout sxmt_keyword;
extern const sx_layout sxmt_group_name;
extern const sx_layout sxmt_material_name;
extern const sx_layout sxmt_font_name;
extern const sx_layout sxmt_glyph_name;
extern const sx_layout sxmt_name;
extern const sx_layout sxmt_string_value;
extern const sx_layout sxmt_vertex_count;
extern const sx_layout sxmt_face_count;
extern const sx_layout sxmt_edge_count;
extern const sx_layout sxmt_list_count;
extern const sx_layout sxmt_element_count;
extern const sx_layout sxmt_point_count;
extern const sx_layout sxmt_width;
extern const sx_layout sxmt_height;
extern const sx_layout sxmt_sample_count;
extern const sx_layout sxmt_vertex_index;
extern const sx_layout sxmt_texture_index;
extern const sx_layout sxmt_normal_index;
extern const sx_layout sxmt_edge_index;
extern const sx_layout sxmt_material_index;
extern const sx_layout sxmt_smoothing_group;
extern const sx_layout sxmt_child_count;
extern const sx_layout sxmt_data_bytes;
extern const sx_layout sxmt_surface_count;
extern const sx_layout sxmt_reference_count;
extern const sx_layout sxmt_glyph_count;
extern const sx_layout sxmt_property_total;
extern const sx_layout sxmt_codepoint;
extern const sx_layout sxmt_glyph_index;
extern const sx_layout sxmt_font_size;
extern const sx_layout sxmt_resolution_x;
extern const sx_layout sxmt_resolution_y;
extern const sx_layout sxmt_bbox_width;
extern const sx_layout sxmt_bbox_height;
extern const sx_layout sxmt_bbox_x;
extern const sx_layout sxmt_bbox_y;
extern const sx_layout sxmt_swidth_x;
extern const sx_layout sxmt_swidth_y;
extern const sx_layout sxmt_dwidth_x;
extern const sx_layout sxmt_dwidth_y;
extern const sx_layout sxmt_integer_value;
extern const sx_layout sxmt_curve_flags;
extern const sx_layout sxmt_x;
extern const sx_layout sxmt_y;
extern const sx_layout sxmt_z;
extern const sx_layout sxmt_w;
extern const sx_layout sxmt_u;
extern const sx_layout sxmt_v;
extern const sx_layout sxmt_normal_x;
extern const sx_layout sxmt_normal_y;
extern const sx_layout sxmt_normal_z;
extern const sx_layout sxmt_red;
extern const sx_layout sxmt_green;
extern const sx_layout sxmt_blue;
extern const sx_layout sxmt_alpha;
extern const sx_layout sxmt_translate_x;
extern const sx_layout sxmt_translate_y;
extern const sx_layout sxmt_translate_z;
extern const sx_layout sxmt_quaternion_w;
extern const sx_layout sxmt_quaternion_x;
extern const sx_layout sxmt_quaternion_y;
extern const sx_layout sxmt_quaternion_z;
extern const sx_layout sxmt_rotation_value;
extern const sx_layout sxmt_transparency;
extern const sx_layout sxmt_shininess;
extern const sx_layout sxmt_ambient_red;
extern const sx_layout sxmt_ambient_green;
extern const sx_layout sxmt_ambient_blue;
extern const sx_layout sxmt_emission_red;
extern const sx_layout sxmt_emission_green;
extern const sx_layout sxmt_emission_blue;
extern const sx_layout sxmt_specular_red;
extern const sx_layout sxmt_specular_green;
extern const sx_layout sxmt_specular_blue;
extern const sx_layout sxmt_font_metric;
extern const sx_layout sxmt_surface_flags;
extern const sx_layout sxmt_glyph_attributes;
extern const sx_layout sxmt_bitmap_byte;
extern const sx_layout sxmt_character_code_hex;
extern const sx_layout sxmt_list_uint8_le;
extern const sx_layout sxmt_list_uint16_le;
extern const sx_layout sxmt_list_uint32_le;
extern const sx_layout sxmt_list_uint8_be;
extern const sx_layout sxmt_list_uint16_be;
extern const sx_layout sxmt_list_uint32_be;
extern const sx_layout sxmt_dxf_signature;
extern const sx_layout sxmt_dxf_group_code;
extern const sx_layout sxmt_dxf_int8;
extern const sx_layout sxmt_dxf_int16;
extern const sx_layout sxmt_dxf_int32;
extern const sx_layout sxmt_dxf_int64;
extern const sx_layout sxmt_dxf_double;
extern const sx_layout sxmt_dxf_chunk_length;
extern const sx_layout sxmt_fig_orientation;
extern const sx_layout sxmt_fig_justification;
extern const sx_layout sxmt_fig_units;
extern const sx_layout sxmt_fig_paper_size;
extern const sx_layout sxmt_fig_page_mode;
extern const sx_layout sxmt_fig_object_code;
extern const sx_layout sxmt_fig_subtype;
extern const sx_layout sxmt_fig_line_style;
extern const sx_layout sxmt_fig_thickness;
extern const sx_layout sxmt_fig_pen_color;
extern const sx_layout sxmt_fig_fill_color;
extern const sx_layout sxmt_fig_depth;
extern const sx_layout sxmt_fig_pen_style;
extern const sx_layout sxmt_fig_area_fill;
extern const sx_layout sxmt_fig_direction;
extern const sx_layout sxmt_fig_center_x;
extern const sx_layout sxmt_fig_center_y;
extern const sx_layout sxmt_fig_radius_x;
extern const sx_layout sxmt_fig_radius_y;
extern const sx_layout sxmt_fig_start_x;
extern const sx_layout sxmt_fig_start_y;
extern const sx_layout sxmt_fig_end_x;
extern const sx_layout sxmt_fig_end_y;
extern const sx_layout sxmt_fig_join_style;
extern const sx_layout sxmt_fig_cap_style;
extern const sx_layout sxmt_fig_radius;
extern const sx_layout sxmt_fig_forward_arrow;
extern const sx_layout sxmt_fig_backward_arrow;
extern const sx_layout sxmt_fig_point_count;
extern const sx_layout sxmt_fig_color_index;
extern const sx_layout sxmt_fig_transparent_color;
extern const sx_layout sxmt_fig_resolution;
extern const sx_layout sxmt_fig_coordinate_system;
extern const sx_layout sxmt_fig_magnification;
extern const sx_layout sxmt_fig_style_value;
extern const sx_layout sxmt_fig_angle;
extern const sx_layout sxmt_fig_rgb;
bool sxmt_space(uint8_t x);
bool sxmt_emit(sxmt_cursor*q,const sx_layout*l,int64_t a,int64_t z);
bool sxmt_token(sxmt_cursor*q,int64_t end,int64_t*a,int64_t*z,bool comments);
bool sxmt_value(sxmt_cursor*q,const sx_layout*l,int64_t end,uint64_t*out);
bool sxmt_line(sxmt_cursor*q,int64_t*a,int64_t*end,bool comments);
bool sxmt_eq(sxmt_cursor*q,int64_t a,int64_t z,const char*s);
bool sxmt_table(sxmt_cursor*q,const sx_layout*l,int64_t at,int64_t width,uint64_t count);
bool sxmt_many(sxmt_cursor*q,const sx_layout*l,int64_t end);
bool sxmt_uint_token(sxmt_cursor*q,int64_t a,int64_t z,uint64_t*v);
const sx_layout*sxmt_binary_type(unsigned kind,unsigned width,bool be);
bool sxmt_remainder(sxmt_cursor*q,const sx_layout*l,int64_t end);
bool sxmt_quoted(sxmt_cursor*q,const sx_layout*l,int64_t end);
bool sxmt_lex(sxmt_cursor*q,xx_file_type_t type);

/* Per-format walkers, called by the family's build. */
bool sx_polygon_ply_build(sxmt_cursor*q);  /* image/polygon_ply/xx_polygon_ply_data.c */
bool sx_pointcloud_pcd_build(sxmt_cursor*q);  /* image/pointcloud_pcd/xx_pointcloud_pcd_data.c */
bool sx_wavefront_obj_build(sxmt_cursor*q);  /* image/wavefront_obj/xx_wavefront_obj_data.c */
bool sx_off_mesh_build(sxmt_cursor*q);  /* image/off_mesh/xx_off_mesh_data.c */
bool sx_ac3d_model_build(sxmt_cursor*q);  /* image/ac3d_model/xx_ac3d_model_data.c */
bool sx_xfig_build(sxmt_cursor*q);  /* image/xfig/xx_xfig_data.c */
bool sx_autocad_dxf_build(sxmt_cursor*q);  /* image/autocad_dxf/xx_autocad_dxf_data.c */
bool sx_font_bdf_build(sxmt_cursor*q);  /* font/font_bdf/xx_font_bdf_data.c */
bool sx_font_afm_build(sxmt_cursor*q);  /* font/font_afm/xx_font_afm_data.c */
bool sx_fontforge_sfd_build(sxmt_cursor*q);  /* font/fontforge_sfd/xx_fontforge_sfd_data.c */
bool sx_gts_surface_build(sxmt_cursor*q);  /* image/gts_surface/xx_gts_surface_data.c */
bool sx_bvh_motion_build(sxmt_cursor*q,xx_file_type_t type);  /* image/bvh_motion/xx_bvh_motion_data.c */
bool sx_directx_x_build(sxmt_cursor*q,xx_file_type_t type);  /* image/directx_x/xx_directx_x_data.c */
bool sx_lightwave_scene_build(sxmt_cursor*q,xx_file_type_t type);  /* image/lightwave_scene/xx_lightwave_scene_data.c */
bool sx_metasequoia_mqo_build(sxmt_cursor*q,xx_file_type_t type);  /* image/metasequoia_mqo/xx_metasequoia_mqo_data.c */
bool sx_autodesk_ase_build(sxmt_cursor*q,xx_file_type_t type);  /* image/autodesk_ase/xx_autodesk_ase_data.c */

#endif
