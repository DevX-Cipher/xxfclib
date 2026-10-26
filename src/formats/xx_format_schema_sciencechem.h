/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The sciencechem schema family: what its family unit (xx_format_schema_sciencechem.c)
 * and its formats' data files share. Formats: protein_mmcif; xcrysden_xsf; amber_prmtop; gaussian_fchk; dl_poly_config; lammps_data; lammps_dump; shelx_res; charmm_crd; castep_cell; crystal_fort34; siesta_xv; vasp_poscar; quantum_espresso_input; cp2k_input; nwchem_input; gamess_input; gaussian_input; abinit_input; aims_geometry; orca_input; demon_input; qchem_input. */
#ifndef XX_FORMAT_SCHEMA_SCIENCECHEM_H
#define XX_FORMAT_SCHEMA_SCIENCECHEM_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Native validation gates interpretation; every emitted span is checked again. */
typedef struct sxsch_cursor{sx_context*c;uint8_t*b;int64_t n,p;uint64_t work;}sxsch_cursor;
typedef struct sxsch_token{int64_t a,z;}sxsch_token;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsch_keyword;
extern const sx_layout sxsch_section;
extern const sx_layout sxsch_title;
extern const sx_layout sxsch_comment;
extern const sx_layout sxsch_text_value;
extern const sx_layout sxsch_element;
extern const sx_layout sxsch_atom_label;
extern const sx_layout sxsch_atom_name;
extern const sx_layout sxsch_residue_name;
extern const sx_layout sxsch_residue_id;
extern const sx_layout sxsch_segment_name;
extern const sx_layout sxsch_units;
extern const sx_layout sxsch_coordinate_mode;
extern const sx_layout sxsch_boolean_text;
extern const sx_layout sxsch_option_name;
extern const sx_layout sxsch_option_value;
extern const sx_layout sxsch_filename;
extern const sx_layout sxsch_format_string;
extern const sx_layout sxsch_value_type;
extern const sx_layout sxsch_atom_count;
extern const sx_layout sxsch_type_count;
extern const sx_layout sxsch_value_count;
extern const sx_layout sxsch_symmetry_count;
extern const sx_layout sxsch_species_count;
extern const sx_layout sxsch_atom_id;
extern const sx_layout sxsch_residue_index;
extern const sx_layout sxsch_species_index;
extern const sx_layout sxsch_atomic_number;
extern const sx_layout sxsch_charge;
extern const sx_layout sxsch_multiplicity;
extern const sx_layout sxsch_integer_value;
extern const sx_layout sxsch_real_value;
extern const sx_layout sxsch_mass;
extern const sx_layout sxsch_occupancy;
extern const sx_layout sxsch_weight;
extern const sx_layout sxsch_gaussian_coordinate_x;
extern const sx_layout sxsch_gaussian_coordinate_y;
extern const sx_layout sxsch_gaussian_coordinate_z;
extern const sx_layout sxsch_gaussian_lattice_x;
extern const sx_layout sxsch_gaussian_lattice_y;
extern const sx_layout sxsch_gaussian_lattice_z;
extern const sx_layout sxsch_mixing_factor;
extern const sx_layout sxsch_qe_total_charge;
extern const sx_layout sxsch_convergence_exponent;
extern const sx_layout sxsch_angstrom_x;
extern const sx_layout sxsch_angstrom_y;
extern const sx_layout sxsch_angstrom_z;
extern const sx_layout sxsch_fractional_x;
extern const sx_layout sxsch_fractional_y;
extern const sx_layout sxsch_fractional_z;
extern const sx_layout sxsch_lammps_mass;
extern const sx_layout sxsch_abinit_cell_scale_x;
extern const sx_layout sxsch_abinit_cell_scale_y;
extern const sx_layout sxsch_abinit_cell_scale_z;
extern const sx_layout sxsch_abinit_rprim_x;
extern const sx_layout sxsch_abinit_rprim_y;
extern const sx_layout sxsch_abinit_rprim_z;
extern const sx_layout sxsch_lammps_coordinate_x;
extern const sx_layout sxsch_lammps_coordinate_y;
extern const sx_layout sxsch_lammps_coordinate_z;
extern const sx_layout sxsch_lammps_velocity_x;
extern const sx_layout sxsch_lammps_velocity_y;
extern const sx_layout sxsch_lammps_velocity_z;
extern const sx_layout sxsch_scale;
extern const sx_layout sxsch_dlp_level;
extern const sx_layout sxsch_dlp_periodicity;
extern const sx_layout sxsch_dimension;
extern const sx_layout sxsch_crystal_centering;
extern const sx_layout sxsch_crystal_type;
extern const sx_layout sxsch_energy;
extern const sx_layout sxsch_energy_delta;
extern const sx_layout sxsch_symmetry_component;
extern const sx_layout sxsch_wavelength;
extern const sx_layout sxsch_cell_a;
extern const sx_layout sxsch_cell_b;
extern const sx_layout sxsch_cell_c;
extern const sx_layout sxsch_cell_alpha;
extern const sx_layout sxsch_cell_beta;
extern const sx_layout sxsch_cell_gamma;
extern const sx_layout sxsch_shelx_lattice;
extern const sx_layout sxsch_lammps_timestep;
extern const sx_layout sxsch_box_lower;
extern const sx_layout sxsch_box_upper;
extern const sx_layout sxsch_box_tilt;
extern const sx_layout sxsch_boundary_code;
extern const sx_layout sxsch_column_name;
extern const sx_layout sxsch_move_flag;
extern const sx_layout sxsch_k_grid;
extern const sx_layout sxsch_k_shift;
extern const sx_layout sxsch_cif_data_block;
extern const sx_layout sxsch_cif_tag;
extern const sx_layout sxsch_cif_group;
extern const sx_layout sxsch_cif_value;
extern const sx_layout sxsch_cif_atom_id;
extern const sx_layout sxsch_amber_flag;
extern const sx_layout sxsch_amber_atom_name;
extern const sx_layout sxsch_amber_residue_label;
extern const sx_layout sxsch_amber_atom_type_index;
extern const sx_layout sxsch_amber_excluded_count;
extern const sx_layout sxsch_amber_residue_pointer;
extern const sx_layout sxsch_amber_charge;
extern const sx_layout sxsch_amber_mass;
extern const sx_layout sxsch_amber_integer;
extern const sx_layout sxsch_amber_real;
extern const sx_layout sxsch_amber_string;
extern const sx_layout sxsch_amber_natom;
extern const sx_layout sxsch_amber_ntypes;
extern const sx_layout sxsch_amber_nbonh;
extern const sx_layout sxsch_amber_mbona;
extern const sx_layout sxsch_amber_ntheth;
extern const sx_layout sxsch_amber_mtheta;
extern const sx_layout sxsch_amber_nphih;
extern const sx_layout sxsch_amber_mphia;
extern const sx_layout sxsch_amber_nhparm;
extern const sx_layout sxsch_amber_nparm;
extern const sx_layout sxsch_amber_next;
extern const sx_layout sxsch_amber_nres;
extern const sx_layout sxsch_amber_nbona;
extern const sx_layout sxsch_amber_ntheta;
extern const sx_layout sxsch_amber_nphia;
extern const sx_layout sxsch_amber_numbnd;
extern const sx_layout sxsch_amber_numang;
extern const sx_layout sxsch_amber_nptra;
extern const sx_layout sxsch_amber_natyp;
extern const sx_layout sxsch_amber_nphb;
extern const sx_layout sxsch_amber_ifpert;
extern const sx_layout sxsch_amber_nbper;
extern const sx_layout sxsch_amber_ngper;
extern const sx_layout sxsch_amber_ndper;
extern const sx_layout sxsch_amber_mbper;
extern const sx_layout sxsch_amber_mgper;
extern const sx_layout sxsch_amber_mdper;
extern const sx_layout sxsch_amber_ifbox;
extern const sx_layout sxsch_amber_nmxrs;
extern const sx_layout sxsch_amber_ifcap;
extern const sx_layout sxsch_amber_numextra;
extern const sx_layout sxsch_amber_ncopy;
extern const sx_layout sxsch_fchk_label;
extern const sx_layout sxsch_fchk_job;
extern const sx_layout sxsch_fchk_method;
extern const sx_layout sxsch_fchk_basis;
extern const sx_layout sxsch_fchk_array_marker;
extern const sx_layout sxsch_fchk_integer;
extern const sx_layout sxsch_fchk_real;
extern const sx_layout sxsch_fchk_coordinate;
extern const sx_layout sxsch_relaxation_constraint;
extern const sx_layout sxsch_unpaired_electrons;
extern const sx_layout sxsch_basis_name;
extern const sx_layout sxsch_method_name;
extern const sx_layout sxsch_calculation_kind;
extern const sx_layout sxsch_iteration_count;
extern const sx_layout sxsch_threshold;
extern const sx_layout sxsch_processor_count;
extern const sx_layout sxsch_memory_amount;
extern const sx_layout sxsch_memory_mb;
extern const sx_layout sxsch_cutoff_ry;
extern const sx_layout sxsch_cutoff_selected;
extern const sx_layout sxsch_initial_charge;
extern const sx_layout sxsch_initial_spin;
extern const sx_layout sxsch_nuclear_charge;
extern const sx_layout sxsch_symmetry_name;
bool sxsch_space(uint8_t c);
bool sxsch_eq(sxsch_cursor*q,sxsch_token t,const char*s);
bool sxsch_ci(sxsch_cursor*q,sxsch_token t,const char*s);
sxsch_token sxsch_trim(sxsch_cursor*q,sxsch_token t);
bool sxsch_line(sxsch_cursor*q,sxsch_token*t);
unsigned sxsch_split(sxsch_cursor*q,sxsch_token line,sxsch_token*t,unsigned cap,bool tabs);
bool sxsch_emit(sxsch_cursor*q,const sx_layout*l,sxsch_token t);
bool sxsch_number(sxsch_cursor*q,sxsch_token t,uint64_t*v);
bool sxsch_fields(sxsch_cursor*q,sxsch_token*t,unsigned n,const sx_layout*const*l,unsigned max);
bool sxsch_column(sxsch_cursor*q,const sx_layout*l,sxsch_token line,unsigned at,unsigned width);
bool sxsch_next(sxsch_cursor*q,sxsch_token*line,sxsch_token*t,unsigned cap,unsigned*n,const char*comments);
bool sxsch_xyz(sxsch_cursor*q,sxsch_token*t,unsigned mode);
bool sxsch_each(sxsch_cursor*q,sxsch_token*t,unsigned n,const sx_layout*l);
bool sxsch_assignment(sxsch_cursor*q,sxsch_token row,sxsch_token*key,sxsch_token*value);
bool sxsch_option(sxsch_cursor*q,sxsch_token key,sxsch_token value,const sx_layout*layout);

/* Per-format walkers, called by the family's build. */
bool sx_protein_mmcif_build(sxsch_cursor*q);  /* science/protein_mmcif/xx_protein_mmcif_data.c */
bool sx_xcrysden_xsf_build(sxsch_cursor*q);  /* science/xcrysden_xsf/xx_xcrysden_xsf_data.c */
bool sx_amber_prmtop_build(sxsch_cursor*q);  /* science/amber_prmtop/xx_amber_prmtop_data.c */
bool sx_gaussian_fchk_build(sxsch_cursor*q);  /* science/gaussian_fchk/xx_gaussian_fchk_data.c */
bool sx_dl_poly_config_build(sxsch_cursor*q);  /* science/dl_poly_config/xx_dl_poly_config_data.c */
bool sx_lammps_data_build(sxsch_cursor*q);  /* science/lammps_data/xx_lammps_data_data.c */
bool sx_lammps_dump_build(sxsch_cursor*q);  /* science/lammps_dump/xx_lammps_dump_data.c */
bool sx_shelx_res_build(sxsch_cursor*q);  /* science/shelx_res/xx_shelx_res_data.c */
bool sx_charmm_crd_build(sxsch_cursor*q);  /* science/charmm_crd/xx_charmm_crd_data.c */
bool sx_castep_cell_build(sxsch_cursor*q);  /* science/castep_cell/xx_castep_cell_data.c */
bool sx_crystal_fort34_build(sxsch_cursor*q);  /* science/crystal_fort34/xx_crystal_fort34_data.c */
bool sx_siesta_xv_build(sxsch_cursor*q);  /* science/siesta_xv/xx_siesta_xv_data.c */
bool sx_vasp_poscar_build(sxsch_cursor*q);  /* science/vasp_poscar/xx_vasp_poscar_data.c */
bool sx_quantum_espresso_input_build(sxsch_cursor*q);  /* science/quantum_espresso_input/xx_quantum_espresso_input_data.c */
bool sx_cp2k_input_build(sxsch_cursor*q);  /* science/cp2k_input/xx_cp2k_input_data.c */
bool sx_nwchem_input_build(sxsch_cursor*q);  /* science/nwchem_input/xx_nwchem_input_data.c */
bool sx_gamess_input_build(sxsch_cursor*q);  /* science/gamess_input/xx_gamess_input_data.c */
bool sx_gaussian_input_build(sxsch_cursor*q);  /* science/gaussian_input/xx_gaussian_input_data.c */
bool sx_abinit_input_build(sxsch_cursor*q);  /* science/abinit_input/xx_abinit_input_data.c */
bool sx_aims_geometry_build(sxsch_cursor*q);  /* science/aims_geometry/xx_aims_geometry_data.c */
bool sx_orca_input_build(sxsch_cursor*q);  /* science/orca_input/xx_orca_input_data.c */
bool sx_demon_input_build(sxsch_cursor*q);  /* science/demon_input/xx_demon_input_data.c */
bool sx_qchem_input_build(sxsch_cursor*q);  /* science/qchem_input/xx_qchem_input_data.c */

#endif
