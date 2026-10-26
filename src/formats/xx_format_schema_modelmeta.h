/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The modelmeta schema family: what its family unit (xx_format_schema_modelmeta.c)
 * and its formats' data files share. Formats: BLITZ3D_B3D; MILKSHAPE_MS3D; NINTENDO_BCH; OGRE_MESH; BLENDER_BLEND; AUTODESK_FBX; AUTODESK_3DS; LIGHTWAVE_LWO2; SPRING_S3O; STEREOLITHOGRAPHY_STL; OPENCTM_MESH; QUBICLE_QB; TERRAGEN_TER; MMD_PMX; OGRE_SKELETON; CAL3D_SKELETON. */
#ifndef XX_FORMAT_SCHEMA_MODELMETA_H
#define XX_FORMAT_SCHEMA_MODELMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmo_b3d_header;
extern const sx_layout sxmo_b3d_chunk;
extern const sx_layout sxmo_b3d_texture;
extern const sx_layout sxmo_b3d_brush_count;
extern const sx_layout sxmo_b3d_texture_index;
extern const sx_layout sxmo_b3d_brush;
extern const sx_layout sxmo_b3d_node;
extern const sx_layout sxmo_b3d_brush_index;
extern const sx_layout sxmo_b3d_vertices;
extern const sx_layout sxmo_b3d_position;
extern const sx_layout sxmo_b3d_normal;
extern const sx_layout sxmo_b3d_color;
extern const sx_layout sxmo_b3d_texture_coordinate;
extern const sx_layout sxmo_b3d_triangle;
extern const sx_layout sxmo_ms3d_header;
extern const sx_layout sxmo_ms3d_vertex_count;
extern const sx_layout sxmo_ms3d_triangle_count;
extern const sx_layout sxmo_ms3d_group_count;
extern const sx_layout sxmo_ms3d_material_count;
extern const sx_layout sxmo_ms3d_vertex;
extern const sx_layout sxmo_ms3d_triangle;
extern const sx_layout sxmo_ms3d_group;
extern const sx_layout sxmo_ms3d_triangle_index;
extern const sx_layout sxmo_ms3d_material_index;
extern const sx_layout sxmo_ms3d_material;
extern const sx_layout sxmo_ms3d_animation;
extern const sx_layout sxmo_bch21_header;
extern const sx_layout sxmo_bch_relocation;
extern const sx_layout sxmo_ogre_mesh_header;
extern const sx_layout sxmo_ogre_mesh_chunk;
extern const sx_layout sxmo_ogre_mesh_animation;
extern const sx_layout sxmo_ogre_submesh;
extern const sx_layout sxmo_ogre_index16;
extern const sx_layout sxmo_ogre_vertex_count;
extern const sx_layout sxmo_ogre_vertex_element;
extern const sx_layout sxmo_ogre_vertex_buffer;
extern const sx_layout sxmo_ogre_position;
extern const sx_layout sxmo_ogre_operation;
extern const sx_layout sxmo_ogre_bounds;
extern const sx_layout sxmo_blend_header;
extern const sx_layout sxmo_blend_block32_le;
extern const sx_layout sxmo_blend_block64_le;
extern const sx_layout sxmo_blend_dna_names_le;
extern const sx_layout sxmo_blend_dna_types_le;
extern const sx_layout sxmo_blend_dna_structures_le;
extern const sx_layout sxmo_blend_dna_lengths_tag_le;
extern const sx_layout sxmo_blend_dna_type_size_le;
extern const sx_layout sxmo_blend_dna_structure_le;
extern const sx_layout sxmo_blend_dna_field_le;
extern const sx_layout sxmo_blend_block32_be;
extern const sx_layout sxmo_blend_block64_be;
extern const sx_layout sxmo_blend_dna_names_be;
extern const sx_layout sxmo_blend_dna_types_be;
extern const sx_layout sxmo_blend_dna_structures_be;
extern const sx_layout sxmo_blend_dna_lengths_tag_be;
extern const sx_layout sxmo_blend_dna_type_size_be;
extern const sx_layout sxmo_blend_dna_structure_be;
extern const sx_layout sxmo_blend_dna_field_be;
extern const sx_layout sxmo_fbx_header;
extern const sx_layout sxmo_fbx_node32;
extern const sx_layout sxmo_fbx_node64;
extern const sx_layout sxmo_fbx_scalar_y;
extern const sx_layout sxmo_fbx_scalar_c;
extern const sx_layout sxmo_fbx_scalar_i;
extern const sx_layout sxmo_fbx_scalar_f;
extern const sx_layout sxmo_fbx_scalar_l;
extern const sx_layout sxmo_fbx_scalar_d;
extern const sx_layout sxmo_fbx_blob;
extern const sx_layout sxmo_fbx_array;
extern const sx_layout sxmo_fbx_footer_prefix;
extern const sx_layout sxmo_fbx_footer_tail;
extern const sx_layout sxmo_3ds_chunk;
extern const sx_layout sxmo_3ds_version;
extern const sx_layout sxmo_3ds_vertex_count;
extern const sx_layout sxmo_3ds_face_count;
extern const sx_layout sxmo_3ds_uv_count;
extern const sx_layout sxmo_3ds_vertex;
extern const sx_layout sxmo_3ds_uv;
extern const sx_layout sxmo_3ds_face;
extern const sx_layout sxmo_3ds_local_matrix;
extern const sx_layout sxmo_lwo2_form;
extern const sx_layout sxmo_lwo2_chunk;
extern const sx_layout sxmo_lwo2_layer;
extern const sx_layout sxmo_lwo2_point;
extern const sx_layout sxmo_lwo2_polygon_type;
extern const sx_layout sxmo_lwo2_tag_type;
extern const sx_layout sxmo_lwo2_polygon;
extern const sx_layout sxmo_lwo2_index16;
extern const sx_layout sxmo_lwo2_index24;
extern const sx_layout sxmo_lwo2_tag_index;
extern const sx_layout sxmo_s3o_header;
extern const sx_layout sxmo_s3o_piece;
extern const sx_layout sxmo_s3o_vertex;
extern const sx_layout sxmo_s3o_child;
extern const sx_layout sxmo_s3o_index;
extern const sx_layout sxmo_stl_binary_header;
extern const sx_layout sxmo_stl_binary_facet;
extern const sx_layout sxmo_openctm_header;
extern const sx_layout sxmo_openctm_string_length;
extern const sx_layout sxmo_openctm_tag;
extern const sx_layout sxmo_openctm_triangle;
extern const sx_layout sxmo_openctm_vertex;
extern const sx_layout sxmo_openctm_normal;
extern const sx_layout sxmo_openctm_uv;
extern const sx_layout sxmo_openctm_attribute;
extern const sx_layout sxmo_qb_header;
extern const sx_layout sxmo_qb_name_length;
extern const sx_layout sxmo_qb_matrix;
extern const sx_layout sxmo_qb_voxel;
extern const sx_layout sxmo_qb_rle_marker;
extern const sx_layout sxmo_qb_rle_run;
extern const sx_layout sxmo_ter_header;
extern const sx_layout sxmo_ter_end;
extern const sx_layout sxmo_ter_size;
extern const sx_layout sxmo_ter_point_count;
extern const sx_layout sxmo_ter_scale;
extern const sx_layout sxmo_ter_radius;
extern const sx_layout sxmo_ter_curvature;
extern const sx_layout sxmo_ter_altitude;
extern const sx_layout sxmo_ter_height;
extern const sx_layout sxmo_pmx20_header;
extern const sx_layout sxmo_pmx_text_length;
extern const sx_layout sxmo_pmx_vertex_count;
extern const sx_layout sxmo_pmx_face_index_count;
extern const sx_layout sxmo_pmx_texture_count;
extern const sx_layout sxmo_pmx_vertex;
extern const sx_layout sxmo_pmx_additional_uv;
extern const sx_layout sxmo_pmx_skinning;
extern const sx_layout sxmo_pmx_bone_index1;
extern const sx_layout sxmo_pmx_vertex_index1;
extern const sx_layout sxmo_pmx_bone_index2;
extern const sx_layout sxmo_pmx_vertex_index2;
extern const sx_layout sxmo_pmx_bone_index4;
extern const sx_layout sxmo_pmx_vertex_index4;
extern const sx_layout sxmo_pmx_weight;
extern const sx_layout sxmo_pmx_edge_scale;
extern const sx_layout sxmo_pmx_sdef;
extern const sx_layout sxmo_pmx_material_count;
extern const sx_layout sxmo_ogre_skeleton_header;
extern const sx_layout sxmo_ogre_skeleton_chunk;
extern const sx_layout sxmo_ogre_skeleton_bone_chunk;
extern const sx_layout sxmo_ogre_skeleton_bone;
extern const sx_layout sxmo_ogre_skeleton_scale;
extern const sx_layout sxmo_ogre_skeleton_parent;
extern const sx_layout sxmo_ogre_skeleton_blend;
extern const sx_layout sxmo_ogre_skeleton_duration;
extern const sx_layout sxmo_ogre_skeleton_track;
extern const sx_layout sxmo_ogre_skeleton_keyframe;
extern const sx_layout sxmo_cal3d_skeleton_header;
extern const sx_layout sxmo_cal3d_bone_name;
extern const sx_layout sxmo_cal3d_bone;
extern const sx_layout sxmo_cal3d_child;
bool sxmo_span(sx_context*c,uint64_t p,uint64_t n);
bool sxmo_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxmo_uint(const uint8_t*b,unsigned n,bool be);
uint32_t sxmo32(const uint8_t*b,bool be);
uint16_t sxmo16(const uint8_t*b,bool be);
bool sxmo_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxmo_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxmo_string(sx_context*c,uint64_t*p,uint64_t end,uint8_t terminal);
bool sxmo_take(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end);
bool sxmo_text(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end);
bool sxmo_finish(sx_context*c);

/* Per-format walkers, called by the family's build. */
bool sx_blitz3d_b3d_build(sx_context *c);  /* image/blitz3d_b3d/xx_blitz3d_b3d_data.c */
bool sx_milkshape_ms3d_build(sx_context *c);  /* image/milkshape_ms3d/xx_milkshape_ms3d_data.c */
bool sx_nintendo_bch_build(sx_context *c);  /* image/nintendo_bch/xx_nintendo_bch_data.c */
bool sx_ogre_mesh_build(sx_context *c);  /* image/ogre_mesh/xx_ogre_mesh_data.c */
bool sx_blender_blend_build(sx_context *c);  /* image/blender_blend/xx_blender_blend_data.c */
bool sx_autodesk_fbx_build(sx_context *c);  /* image/autodesk_fbx/xx_autodesk_fbx_data.c */
bool sx_autodesk_3ds_build(sx_context *c);  /* image/autodesk_3ds/xx_autodesk_3ds_data.c */
bool sx_lightwave_lwo2_build(sx_context *c);  /* image/lightwave_lwo2/xx_lightwave_lwo2_data.c */
bool sx_spring_s3o_build(sx_context *c);  /* image/spring_s3o/xx_spring_s3o_data.c */
bool sx_stereolithography_stl_build(sx_context *c);  /* image/stereolithography_stl/xx_stereolithography_stl_data.c */
bool sx_openctm_mesh_build(sx_context *c);  /* image/openctm_mesh/xx_openctm_mesh_data.c */
bool sx_qubicle_qb_build(sx_context *c);  /* image/qubicle_qb/xx_qubicle_qb_data.c */
bool sx_terragen_ter_build(sx_context *c);  /* image/terragen_ter/xx_terragen_ter_data.c */
bool sx_mmd_pmx_build(sx_context *c);  /* image/mmd_pmx/xx_mmd_pmx_data.c */
bool sx_ogre_skeleton_build(sx_context *c);  /* image/ogre_skeleton/xx_ogre_skeleton_data.c */
bool sx_cal3d_skeleton_build(sx_context *c);  /* image/cal3d_skeleton/xx_cal3d_skeleton_data.c */

#endif
