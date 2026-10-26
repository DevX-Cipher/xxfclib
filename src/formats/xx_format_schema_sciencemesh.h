/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The sciencemesh schema family: what its family unit (xx_format_schema_sciencemesh.c)
 * and its formats' data files share. Formats: NRRD; METAIMAGE; VTK LEGACY; MICROSCOPY ICS; TEKTRONIX ISF; PHYLO NEXUS; PHYLO NEWICK; OPENDX FIELD; GMSH MSH; NETGEN VOL; JCAMP DX; SURFER GRID; HARWELL BOEING; OPENFOAM POINTS; MEDIT MESH; GOCAD MODEL; NASTRAN BULK; ABAQUS INPUT; GMV MESH; AMIRA MESH; TETGEN MESH. */
#ifndef XX_FORMAT_SCHEMA_SCIENCEMESH_H
#define XX_FORMAT_SCHEMA_SCIENCEMESH_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Native validation gates interpretation; every emitted span is checked again. */
typedef struct sxsm_cursor{sx_context*c;uint8_t*b;int64_t n,p;uint64_t work;}sxsm_cursor;
typedef struct sxsm_token{int64_t a,z;}sxsm_token;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsm_signature;
extern const sx_layout sxsm_keyword;
extern const sx_layout sxsm_section;
extern const sx_layout sxsm_key;
extern const sx_layout sxsm_option_value;
extern const sx_layout sxsm_title;
extern const sx_layout sxsm_comment;
extern const sx_layout sxsm_name;
extern const sx_layout sxsm_text_value;
extern const sx_layout sxsm_type_name;
extern const sx_layout sxsm_encoding;
extern const sx_layout sxsm_endian;
extern const sx_layout sxsm_units;
extern const sx_layout sxsm_filename;
extern const sx_layout sxsm_format_string;
extern const sx_layout sxsm_dimension;
extern const sx_layout sxsm_axis_count;
extern const sx_layout sxsm_node_count;
extern const sx_layout sxsm_element_count;
extern const sx_layout sxsm_value_count;
extern const sx_layout sxsm_component_count;
extern const sx_layout sxsm_tag_count;
extern const sx_layout sxsm_attribute_count;
extern const sx_layout sxsm_node_id;
extern const sx_layout sxsm_element_id;
extern const sx_layout sxsm_node_index;
extern const sx_layout sxsm_property_id;
extern const sx_layout sxsm_region_id;
extern const sx_layout sxsm_entity_id;
extern const sx_layout sxsm_label_id;
extern const sx_layout sxsm_integer_value;
extern const sx_layout sxsm_real_value;
extern const sx_layout sxsm_coordinate_x;
extern const sx_layout sxsm_coordinate_y;
extern const sx_layout sxsm_coordinate_z;
extern const sx_layout sxsm_box_min_x;
extern const sx_layout sxsm_box_min_y;
extern const sx_layout sxsm_box_min_z;
extern const sx_layout sxsm_box_max_x;
extern const sx_layout sxsm_box_max_y;
extern const sx_layout sxsm_box_max_z;
extern const sx_layout sxsm_scalar_min;
extern const sx_layout sxsm_scalar_max;
extern const sx_layout sxsm_scalar_value;
extern const sx_layout sxsm_attribute_value;
extern const sx_layout sxsm_sample_bytes;
extern const sx_layout sxsm_sample_bits;
extern const sx_layout sxsm_significant_bits;
extern const sx_layout sxsm_ics_parameter_count;
extern const sx_layout sxsm_byte_order_index;
extern const sx_layout sxsm_parameter_origin;
extern const sx_layout sxsm_parameter_scale;
extern const sx_layout sxsm_x_increment;
extern const sx_layout sxsm_x_zero;
extern const sx_layout sxsm_point_offset;
extern const sx_layout sxsm_y_multiplier;
extern const sx_layout sxsm_y_zero;
extern const sx_layout sxsm_y_offset;
extern const sx_layout sxsm_length_digits;
extern const sx_layout sxsm_payload_bytes;
extern const sx_layout sxsm_jcamp_version;
extern const sx_layout sxsm_first_x;
extern const sx_layout sxsm_last_x;
extern const sx_layout sxsm_x_factor;
extern const sx_layout sxsm_y_factor;
extern const sx_layout sxsm_spectral_x;
extern const sx_layout sxsm_spectral_y;
extern const sx_layout sxsm_hb_total_lines;
extern const sx_layout sxsm_hb_pointer_lines;
extern const sx_layout sxsm_hb_index_lines;
extern const sx_layout sxsm_hb_value_lines;
extern const sx_layout sxsm_hb_rhs_lines;
extern const sx_layout sxsm_matrix_rows;
extern const sx_layout sxsm_matrix_columns;
extern const sx_layout sxsm_nonzero_count;
extern const sx_layout sxsm_elemental_values;
extern const sx_layout sxsm_column_pointer;
extern const sx_layout sxsm_row_index;
extern const sx_layout sxsm_matrix_key;
extern const sx_layout sxsm_matrix_type;
extern const sx_layout sxsm_mesh_version;
extern const sx_layout sxsm_element_type;
extern const sx_layout sxsm_tag_value;
extern const sx_layout sxsm_step_index;
extern const sx_layout sxsm_simulation_time;
extern const sx_layout sxsm_boundary_marker;
extern const sx_layout sxsm_surface_id;
extern const sx_layout sxsm_boundary_id;
extern const sx_layout sxsm_inside_domain;
extern const sx_layout sxsm_outside_domain;
extern const sx_layout sxsm_edge_region;
extern const sx_layout sxsm_edge_triangle;
extern const sx_layout sxsm_edge_surface;
extern const sx_layout sxsm_edge_id;
extern const sx_layout sxsm_edge_distance;
extern const sx_layout sxsm_geometry_type;
extern const sx_layout sxsm_red;
extern const sx_layout sxsm_green;
extern const sx_layout sxsm_blue;
extern const sx_layout sxsm_alpha;
extern const sx_layout sxsm_axis_name;
extern const sx_layout sxsm_axis_unit;
extern const sx_layout sxsm_z_direction;
extern const sx_layout sxsm_topology_name;
extern const sx_layout sxsm_variable_name;
extern const sx_layout sxsm_material_name;
extern const sx_layout sxsm_surface_face;
extern const sx_layout sxsm_material_id;
extern const sx_layout sxsm_coordinate_system;
extern const sx_layout sxsm_displacement_coordinate_system;
extern const sx_layout sxsm_permanent_constraints;
extern const sx_layout sxsm_superelement_id;
extern const sx_layout sxsm_nastran_x;
extern const sx_layout sxsm_nastran_y;
extern const sx_layout sxsm_nastran_z;
extern const sx_layout sxsm_bar_orientation_x;
extern const sx_layout sxsm_bar_orientation_y;
extern const sx_layout sxsm_bar_orientation_z;
extern const sx_layout sxsm_binary_count;
extern const sx_layout sxsm_binary_arity;
extern const sx_layout sxsm_binary_node_index;
extern const sx_layout sxsm_binary_material_id;
extern const sx_layout sxsm_binary_flag_value;
extern const sx_layout sxsm_binary_cycle;
extern const sx_layout sxsm_binary_location;
extern const sx_layout sxsm_binary_scalar;
extern const sx_layout sxsm_binary_coordinate;
extern const sx_layout sxsm_binary_velocity;
extern const sx_layout sxsm_binary_time;
extern const sx_layout sxsm_binary_name;
bool sxsm_space(uint8_t c);
bool sxsm_eq(sxsm_cursor*q,sxsm_token t,const char*s);
bool sxsm_ci(sxsm_cursor*q,sxsm_token t,const char*s);
sxsm_token sxsm_trim(sxsm_cursor*q,sxsm_token t);
bool sxsm_line(sxsm_cursor*q,sxsm_token*t);
unsigned sxsm_split(sxsm_cursor*q,sxsm_token line,sxsm_token*t,unsigned cap,bool tabs);
bool sxsm_emit(sxsm_cursor*q,const sx_layout*l,sxsm_token t);
bool sxsm_number(sxsm_cursor*q,sxsm_token t,uint64_t*v);
bool sxsm_fields(sxsm_cursor*q,sxsm_token*t,unsigned n,const sx_layout*const*l,unsigned max);
bool sxsm_next(sxsm_cursor*q,sxsm_token*line,sxsm_token*t,unsigned cap,unsigned*n,const char*comments);
bool sxsm_each(sxsm_cursor*q,sxsm_token*t,unsigned n,const sx_layout*l);
bool sxsm_xyz(sxsm_cursor*q,sxsm_token*t,unsigned kind);
unsigned sxsm_csv(sxsm_cursor*q,sxsm_token line,sxsm_token*t,unsigned cap);
bool sxsm_keyvalue(sxsm_cursor*q,sxsm_token line,uint8_t delim,sxsm_token*key,sxsm_token*value);
bool sxsm_nrrd_meta(sxsm_cursor*q,bool meta);
bool sxsm_phylo(sxsm_cursor*q,bool nexus);
bool sxsm_lex(sxsm_cursor*q,sxsm_token*t,bool hash);
bool sxsm_expect(sxsm_cursor*q,const char*s,bool hash);
bool sxsm_one(sxsm_cursor*q,const sx_layout*l,bool hash);
bool sxsm_many(sxsm_cursor*q,const sx_layout*l,uint64_t count,bool hash);
bool sxsm_count(sxsm_cursor*q,const sx_layout*l,uint64_t*v,bool hash);

/* Per-format walkers, called by the family's build. */
bool sx_nrrd_build(sxsm_cursor*q);  /* science/nrrd/xx_nrrd_data.c */
bool sx_metaimage_build(sxsm_cursor*q);  /* science/metaimage/xx_metaimage_data.c */
bool sx_vtk_legacy_build(sxsm_cursor*q);  /* science/vtk_legacy/xx_vtk_legacy_data.c */
bool sx_microscopy_ics_build(sxsm_cursor*q);  /* science/microscopy_ics/xx_microscopy_ics_data.c */
bool sx_tektronix_isf_build(sxsm_cursor*q);  /* science/tektronix_isf/xx_tektronix_isf_data.c */
bool sx_phylo_nexus_build(sxsm_cursor*q);  /* science/phylo_nexus/xx_phylo_nexus_data.c */
bool sx_phylo_newick_build(sxsm_cursor*q);  /* science/phylo_newick/xx_phylo_newick_data.c */
bool sx_opendx_field_build(sxsm_cursor*q);  /* science/opendx_field/xx_opendx_field_data.c */
bool sx_gmsh_msh_build(sxsm_cursor*q);  /* science/gmsh_msh/xx_gmsh_msh_data.c */
bool sx_netgen_vol_build(sxsm_cursor*q);  /* science/netgen_vol/xx_netgen_vol_data.c */
bool sx_jcamp_dx_build(sxsm_cursor*q);  /* science/jcamp_dx/xx_jcamp_dx_data.c */
bool sx_surfer_grid_build(sxsm_cursor*q);  /* science/surfer_grid/xx_surfer_grid_data.c */
bool sx_harwell_boeing_build(sxsm_cursor*q);  /* science/harwell_boeing/xx_harwell_boeing_data.c */
bool sx_openfoam_points_build(sxsm_cursor*q);  /* science/openfoam_points/xx_openfoam_points_data.c */
bool sx_medit_mesh_build(sxsm_cursor*q);  /* science/medit_mesh/xx_medit_mesh_data.c */
bool sx_gocad_model_build(sxsm_cursor*q);  /* science/gocad_model/xx_gocad_model_data.c */
bool sx_nastran_bulk_build(sxsm_cursor*q);  /* science/nastran_bulk/xx_nastran_bulk_data.c */
bool sx_abaqus_input_build(sxsm_cursor*q);  /* science/abaqus_input/xx_abaqus_input_data.c */
bool sx_gmv_mesh_build(sxsm_cursor*q);  /* science/gmv_mesh/xx_gmv_mesh_data.c */
bool sx_amira_mesh_build(sxsm_cursor*q);  /* science/amira_mesh/xx_amira_mesh_data.c */
bool sx_tetgen_mesh_build(sxsm_cursor*q);  /* science/tetgen_mesh/xx_tetgen_mesh_data.c */

#endif
