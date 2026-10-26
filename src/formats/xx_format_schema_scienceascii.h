/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The scienceascii schema family: what its family unit (xx_format_schema_scienceascii.c)
 * and its formats' data files share. Formats: genomics_fasta; genomics_fastq; genomics_sam; genomics_vcf; genomics_gff3; genomics_bed; genomics_wiggle; genomics_gtf; genomics_agp; protein_pdb; gromacs_gro; molecule_xyz; mdl_molfile; tripos_mol2; gaussian_cube; amber_restart; matrix_market; esri_ascii_grid; gxf_grid; turbomole_coord. */
#ifndef XX_FORMAT_SCHEMA_SCIENCEASCII_H
#define XX_FORMAT_SCHEMA_SCIENCEASCII_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Native validation gates interpretation; every emitted span is checked again. */
typedef struct sxsa_cursor{sx_context*c;uint8_t*b;int64_t n,p;uint64_t work;}sxsa_cursor;
typedef struct sxsa_token{int64_t a,z;}sxsa_token;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsa_record_type;
extern const sx_layout sxsa_comment;
extern const sx_layout sxsa_title;
extern const sx_layout sxsa_sequence;
extern const sx_layout sxsa_quality;
extern const sx_layout sxsa_element;
extern const sx_layout sxsa_molecule_type;
extern const sx_layout sxsa_charge_type;
extern const sx_layout sxsa_section;
extern const sx_layout sxsa_atom_count;
extern const sx_layout sxsa_bond_count;
extern const sx_layout sxsa_substructure_count;
extern const sx_layout sxsa_feature_count;
extern const sx_layout sxsa_set_count;
extern const sx_layout sxsa_matrix_rows;
extern const sx_layout sxsa_matrix_columns;
extern const sx_layout sxsa_matrix_entries;
extern const sx_layout sxsa_reference_length;
extern const sx_layout sxsa_position_1;
extern const sx_layout sxsa_mapping_quality;
extern const sx_layout sxsa_sam_query_name;
extern const sx_layout sxsa_sam_reference;
extern const sx_layout sxsa_sam_cigar;
extern const sx_layout sxsa_sam_mate_reference;
extern const sx_layout sxsa_sam_tag;
extern const sx_layout sxsa_sam_tag_type;
extern const sx_layout sxsa_sam_text_value;
extern const sx_layout sxsa_sam_hex_value;
extern const sx_layout sxsa_sam_flag;
extern const sx_layout sxsa_sam_template_length;
extern const sx_layout sxsa_sam_integer_value;
extern const sx_layout sxsa_sam_real_value;
extern const sx_layout sxsa_matrix_row;
extern const sx_layout sxsa_matrix_column;
extern const sx_layout sxsa_matrix_object;
extern const sx_layout sxsa_matrix_storage;
extern const sx_layout sxsa_matrix_field;
extern const sx_layout sxsa_matrix_symmetry;
extern const sx_layout sxsa_matrix_integer;
extern const sx_layout sxsa_matrix_real;
extern const sx_layout sxsa_matrix_imaginary;
extern const sx_layout sxsa_pdb_atom_name;
extern const sx_layout sxsa_pdb_altloc;
extern const sx_layout sxsa_pdb_residue;
extern const sx_layout sxsa_pdb_chain;
extern const sx_layout sxsa_pdb_icode;
extern const sx_layout sxsa_pdb_element;
extern const sx_layout sxsa_pdb_charge;
extern const sx_layout sxsa_pdb_serial;
extern const sx_layout sxsa_pdb_residue_sequence;
extern const sx_layout sxsa_pdb_x;
extern const sx_layout sxsa_pdb_y;
extern const sx_layout sxsa_pdb_z;
extern const sx_layout sxsa_pdb_occupancy;
extern const sx_layout sxsa_pdb_temperature;
extern const sx_layout sxsa_pdb_u11;
extern const sx_layout sxsa_pdb_u22;
extern const sx_layout sxsa_pdb_u33;
extern const sx_layout sxsa_pdb_u12;
extern const sx_layout sxsa_pdb_u13;
extern const sx_layout sxsa_pdb_u23;
extern const sx_layout sxsa_gro_residue_name;
extern const sx_layout sxsa_gro_atom_name;
extern const sx_layout sxsa_gro_residue_number;
extern const sx_layout sxsa_gro_atom_number;
extern const sx_layout sxsa_gro_x;
extern const sx_layout sxsa_gro_y;
extern const sx_layout sxsa_gro_z;
extern const sx_layout sxsa_gro_vx;
extern const sx_layout sxsa_gro_vy;
extern const sx_layout sxsa_gro_vz;
extern const sx_layout sxsa_gro_box_xx;
extern const sx_layout sxsa_gro_box_yy;
extern const sx_layout sxsa_gro_box_zz;
extern const sx_layout sxsa_gro_box_xy;
extern const sx_layout sxsa_gro_box_xz;
extern const sx_layout sxsa_gro_box_yx;
extern const sx_layout sxsa_gro_box_yz;
extern const sx_layout sxsa_gro_box_zx;
extern const sx_layout sxsa_gro_box_zy;
extern const sx_layout sxsa_xyz_x;
extern const sx_layout sxsa_xyz_y;
extern const sx_layout sxsa_xyz_z;
extern const sx_layout sxsa_mol_program;
extern const sx_layout sxsa_mol_comment;
extern const sx_layout sxsa_mol_version;
extern const sx_layout sxsa_mol_atom_list_count;
extern const sx_layout sxsa_mol_obsolete_count;
extern const sx_layout sxsa_mol_chiral_flag;
extern const sx_layout sxsa_mol_stext_count;
extern const sx_layout sxsa_mol_obsolete_18;
extern const sx_layout sxsa_mol_obsolete_21;
extern const sx_layout sxsa_mol_obsolete_24;
extern const sx_layout sxsa_mol_obsolete_27;
extern const sx_layout sxsa_mol_property_count;
extern const sx_layout sxsa_mol_x;
extern const sx_layout sxsa_mol_y;
extern const sx_layout sxsa_mol_z;
extern const sx_layout sxsa_mol_mass_difference;
extern const sx_layout sxsa_mol_charge_code;
extern const sx_layout sxsa_mol_stereo_parity;
extern const sx_layout sxsa_mol_hydrogen_count;
extern const sx_layout sxsa_mol_stereo_care;
extern const sx_layout sxsa_mol_valence;
extern const sx_layout sxsa_mol_h0_designator;
extern const sx_layout sxsa_mol_unused_1;
extern const sx_layout sxsa_mol_unused_2;
extern const sx_layout sxsa_mol_mapping_number;
extern const sx_layout sxsa_mol_inversion;
extern const sx_layout sxsa_mol_exact_change;
extern const sx_layout sxsa_mol_bond_atom_1;
extern const sx_layout sxsa_mol_bond_atom_2;
extern const sx_layout sxsa_mol_bond_type;
extern const sx_layout sxsa_mol_bond_stereo;
extern const sx_layout sxsa_mol_bond_unused;
extern const sx_layout sxsa_mol_bond_topology;
extern const sx_layout sxsa_mol_bond_reaction;
extern const sx_layout sxsa_mol_property;
extern const sx_layout sxsa_mol_property_atom;
extern const sx_layout sxsa_mol_property_value;
extern const sx_layout sxsa_mol2_atom_id;
extern const sx_layout sxsa_mol2_substructure_id;
extern const sx_layout sxsa_mol2_bond_id;
extern const sx_layout sxsa_mol2_bond_origin;
extern const sx_layout sxsa_mol2_bond_target;
extern const sx_layout sxsa_mol2_root_atom;
extern const sx_layout sxsa_mol2_dictionary_type;
extern const sx_layout sxsa_mol2_inter_bonds;
extern const sx_layout sxsa_mol2_atom_name;
extern const sx_layout sxsa_mol2_atom_type;
extern const sx_layout sxsa_mol2_substructure_name;
extern const sx_layout sxsa_mol2_bond_type;
extern const sx_layout sxsa_mol2_substructure_type;
extern const sx_layout sxsa_mol2_chain;
extern const sx_layout sxsa_mol2_substructure_subtype;
extern const sx_layout sxsa_mol2_status;
extern const sx_layout sxsa_mol2_x;
extern const sx_layout sxsa_mol2_y;
extern const sx_layout sxsa_mol2_z;
extern const sx_layout sxsa_mol2_charge;
extern const sx_layout sxsa_cube_origin_x;
extern const sx_layout sxsa_cube_origin_y;
extern const sx_layout sxsa_cube_origin_z;
extern const sx_layout sxsa_cube_vector_x;
extern const sx_layout sxsa_cube_vector_y;
extern const sx_layout sxsa_cube_vector_z;
extern const sx_layout sxsa_cube_atom_x;
extern const sx_layout sxsa_cube_atom_y;
extern const sx_layout sxsa_cube_atom_z;
extern const sx_layout sxsa_cube_axis_count;
extern const sx_layout sxsa_atomic_number;
extern const sx_layout sxsa_cube_nuclear_charge;
extern const sx_layout sxsa_cube_value;
extern const sx_layout sxsa_amber_time;
extern const sx_layout sxsa_amber_coordinate;
extern const sx_layout sxsa_amber_velocity;
extern const sx_layout sxsa_amber_box_length;
extern const sx_layout sxsa_amber_box_angle;
extern const sx_layout sxsa_turbomole_units;
extern const sx_layout sxsa_turbomole_bohr_x;
extern const sx_layout sxsa_turbomole_bohr_y;
extern const sx_layout sxsa_turbomole_bohr_z;
extern const sx_layout sxsa_turbomole_angstrom_x;
extern const sx_layout sxsa_turbomole_angstrom_y;
extern const sx_layout sxsa_turbomole_angstrom_z;
bool sxsa_space(uint8_t c);
bool sxsa_eq(sxsa_cursor*q,sxsa_token t,const char*s);
sxsa_token sxsa_trim(sxsa_cursor*q,sxsa_token t);
bool sxsa_line(sxsa_cursor*q,sxsa_token*t);
unsigned sxsa_split(sxsa_cursor*q,sxsa_token line,sxsa_token*t,unsigned cap,bool tabs);
bool sxsa_emit(sxsa_cursor*q,const sx_layout*l,sxsa_token t);
bool sxsa_number(sxsa_cursor*q,sxsa_token t,uint64_t*v);
bool sxsa_fields(sxsa_cursor*q,sxsa_token*t,unsigned n,const sx_layout*const*l,unsigned max);
bool sxsa_column(sxsa_cursor*q,const sx_layout*l,sxsa_token line,unsigned at,unsigned width);
bool sxsa_sequence_file(sxsa_cursor*q,bool fastq);
bool sxsa_csv(sxsa_cursor*q,sxsa_token t,const sx_layout*l);
bool sxsa_genomic_table(sxsa_cursor*q,xx_file_type_t type);
bool sxsa_grid(sxsa_cursor*q,bool gxf);

/* Per-format walkers, called by the family's build. */
bool sx_genomics_fasta_build(sxsa_cursor*q);  /* science/genomics_fasta/xx_genomics_fasta_data.c */
bool sx_genomics_fastq_build(sxsa_cursor*q);  /* science/genomics_fastq/xx_genomics_fastq_data.c */
bool sx_genomics_sam_build(sxsa_cursor*q);  /* science/genomics_sam/xx_genomics_sam_data.c */
bool sx_genomics_vcf_build(sxsa_cursor*q,xx_file_type_t type);  /* science/genomics_vcf/xx_genomics_vcf_data.c */
bool sx_genomics_gff3_build(sxsa_cursor*q,xx_file_type_t type);  /* science/genomics_gff3/xx_genomics_gff3_data.c */
bool sx_genomics_bed_build(sxsa_cursor*q,xx_file_type_t type);  /* science/genomics_bed/xx_genomics_bed_data.c */
bool sx_genomics_wiggle_build(sxsa_cursor*q,xx_file_type_t type);  /* science/genomics_wiggle/xx_genomics_wiggle_data.c */
bool sx_genomics_gtf_build(sxsa_cursor*q,xx_file_type_t type);  /* science/genomics_gtf/xx_genomics_gtf_data.c */
bool sx_genomics_agp_build(sxsa_cursor*q,xx_file_type_t type);  /* science/genomics_agp/xx_genomics_agp_data.c */
bool sx_protein_pdb_build(sxsa_cursor*q);  /* science/protein_pdb/xx_protein_pdb_data.c */
bool sx_gromacs_gro_build(sxsa_cursor*q);  /* science/gromacs_gro/xx_gromacs_gro_data.c */
bool sx_molecule_xyz_build(sxsa_cursor*q);  /* science/molecule_xyz/xx_molecule_xyz_data.c */
bool sx_mdl_molfile_build(sxsa_cursor*q);  /* science/mdl_molfile/xx_mdl_molfile_data.c */
bool sx_tripos_mol2_build(sxsa_cursor*q);  /* science/tripos_mol2/xx_tripos_mol2_data.c */
bool sx_gaussian_cube_build(sxsa_cursor*q);  /* science/gaussian_cube/xx_gaussian_cube_data.c */
bool sx_amber_restart_build(sxsa_cursor*q);  /* science/amber_restart/xx_amber_restart_data.c */
bool sx_matrix_market_build(sxsa_cursor*q);  /* science/matrix_market/xx_matrix_market_data.c */
bool sx_esri_ascii_grid_build(sxsa_cursor*q);  /* science/esri_ascii_grid/xx_esri_ascii_grid_data.c */
bool sx_gxf_grid_build(sxsa_cursor*q);  /* science/gxf_grid/xx_gxf_grid_data.c */
bool sx_turbomole_coord_build(sxsa_cursor*q);  /* science/turbomole_coord/xx_turbomole_coord_data.c */

#endif
