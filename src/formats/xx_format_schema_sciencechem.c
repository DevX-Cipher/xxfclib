/* SPDX-License-Identifier: MIT
 * Native-supported physical chemistry fields. Delimiters and unsupported text remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_sciencechem.h"
static const xx_data_struct_field_desc sxsch_keyword_fields[]={SX_FIELD("keyword","char",0,0,SX_STRING)};
const sx_layout sxsch_keyword={0x60610001U,"chemistry_keyword",sxsch_keyword_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_section_fields[]={SX_FIELD("section","char",0,0,SX_STRING)};
const sx_layout sxsch_section={0x60610002U,"chemistry_section",sxsch_section_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_title_fields[]={SX_FIELD("title","utf8",0,0,SX_STRING)};
const sx_layout sxsch_title={0x60610003U,"chemistry_title",sxsch_title_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_comment_fields[]={SX_FIELD("comment","utf8",0,0,SX_STRING)};
const sx_layout sxsch_comment={0x60610004U,"chemistry_comment",sxsch_comment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_text_value_fields[]={SX_FIELD("text_value","utf8",0,0,SX_STRING)};
const sx_layout sxsch_text_value={0x60610005U,"chemistry_text_value",sxsch_text_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_element_fields[]={SX_FIELD("element","char",0,0,SX_STRING)};
const sx_layout sxsch_element={0x60610006U,"chemistry_element",sxsch_element_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atom_label_fields[]={SX_FIELD("atom_label","char",0,0,SX_STRING)};
const sx_layout sxsch_atom_label={0x60610007U,"chemistry_atom_label",sxsch_atom_label_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atom_name_fields[]={SX_FIELD("atom_name","char",0,0,SX_STRING)};
const sx_layout sxsch_atom_name={0x60610008U,"chemistry_atom_name",sxsch_atom_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_residue_name_fields[]={SX_FIELD("residue_name","char",0,0,SX_STRING)};
const sx_layout sxsch_residue_name={0x60610009U,"chemistry_residue_name",sxsch_residue_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_units_fields[]={SX_FIELD("units","char",0,0,SX_STRING)};
const sx_layout sxsch_units={0x6061000cU,"chemistry_units",sxsch_units_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_coordinate_mode_fields[]={SX_FIELD("coordinate_mode","char",0,0,SX_STRING)};
const sx_layout sxsch_coordinate_mode={0x6061000dU,"chemistry_coordinate_mode",sxsch_coordinate_mode_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_option_name_fields[]={SX_FIELD("option_name","char",0,0,SX_STRING)};
const sx_layout sxsch_option_name={0x6061000fU,"chemistry_option_name",sxsch_option_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_option_value_fields[]={SX_FIELD("option_value","char",0,0,SX_STRING)};
const sx_layout sxsch_option_value={0x60610010U,"chemistry_option_value",sxsch_option_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_filename_fields[]={SX_FIELD("filename","char",0,0,SX_STRING)};
const sx_layout sxsch_filename={0x60610011U,"chemistry_filename",sxsch_filename_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atom_count_fields[]={SX_FIELD("atom_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_atom_count={0x60610014U,"chemistry_atom_count",sxsch_atom_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_type_count_fields[]={SX_FIELD("type_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_type_count={0x60610015U,"chemistry_type_count",sxsch_type_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atom_id_fields[]={SX_FIELD("atom_id","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_atom_id={0x60610019U,"chemistry_atom_id",sxsch_atom_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_species_index_fields[]={SX_FIELD("species_index","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_species_index={0x6061001bU,"chemistry_species_index",sxsch_species_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atomic_number_fields[]={SX_FIELD("atomic_number","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_atomic_number={0x6061001cU,"chemistry_atomic_number",sxsch_atomic_number_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_charge_fields[]={SX_FIELD("charge","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_charge={0x6061001dU,"chemistry_charge",sxsch_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_multiplicity_fields[]={SX_FIELD("multiplicity","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_multiplicity={0x6061001eU,"chemistry_multiplicity",sxsch_multiplicity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_integer_value_fields[]={SX_FIELD("integer_value","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_integer_value={0x6061001fU,"chemistry_integer_value",sxsch_integer_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_real_value_fields[]={SX_FIELD("real_value","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_real_value={0x60610020U,"chemistry_real_value",sxsch_real_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_mass_fields[]={SX_FIELD("mass","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_mass={0x60610021U,"chemistry_mass",sxsch_mass_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_angstrom_x_fields[]={SX_FIELD("angstrom_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_angstrom_x={0x6061002dU,"chemistry_angstrom_x",sxsch_angstrom_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_angstrom_y_fields[]={SX_FIELD("angstrom_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_angstrom_y={0x6061002eU,"chemistry_angstrom_y",sxsch_angstrom_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_angstrom_z_fields[]={SX_FIELD("angstrom_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_angstrom_z={0x6061002fU,"chemistry_angstrom_z",sxsch_angstrom_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_bohr_x_fields[]={SX_FIELD("bohr_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_bohr_x={0x60610030U,"chemistry_bohr_x",sxsch_bohr_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_bohr_y_fields[]={SX_FIELD("bohr_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_bohr_y={0x60610031U,"chemistry_bohr_y",sxsch_bohr_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_bohr_z_fields[]={SX_FIELD("bohr_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_bohr_z={0x60610032U,"chemistry_bohr_z",sxsch_bohr_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fractional_x_fields[]={SX_FIELD("fractional_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_fractional_x={0x60610033U,"chemistry_fractional_x",sxsch_fractional_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fractional_y_fields[]={SX_FIELD("fractional_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_fractional_y={0x60610034U,"chemistry_fractional_y",sxsch_fractional_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fractional_z_fields[]={SX_FIELD("fractional_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_fractional_z={0x60610035U,"chemistry_fractional_z",sxsch_fractional_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_angstrom_x_fields[]={SX_FIELD("lattice_angstrom_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_angstrom_x={0x60610036U,"chemistry_lattice_angstrom_x",sxsch_lattice_angstrom_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_angstrom_y_fields[]={SX_FIELD("lattice_angstrom_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_angstrom_y={0x60610037U,"chemistry_lattice_angstrom_y",sxsch_lattice_angstrom_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_angstrom_z_fields[]={SX_FIELD("lattice_angstrom_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_angstrom_z={0x60610038U,"chemistry_lattice_angstrom_z",sxsch_lattice_angstrom_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_bohr_x_fields[]={SX_FIELD("lattice_bohr_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_bohr_x={0x60610039U,"chemistry_lattice_bohr_x",sxsch_lattice_bohr_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_bohr_y_fields[]={SX_FIELD("lattice_bohr_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_bohr_y={0x6061003aU,"chemistry_lattice_bohr_y",sxsch_lattice_bohr_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_bohr_z_fields[]={SX_FIELD("lattice_bohr_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_bohr_z={0x6061003bU,"chemistry_lattice_bohr_z",sxsch_lattice_bohr_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_scaled_x_fields[]={SX_FIELD("lattice_scaled_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_scaled_x={0x60610043U,"chemistry_lattice_scaled_x",sxsch_lattice_scaled_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_scaled_y_fields[]={SX_FIELD("lattice_scaled_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_scaled_y={0x60610044U,"chemistry_lattice_scaled_y",sxsch_lattice_scaled_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lattice_scaled_z_fields[]={SX_FIELD("lattice_scaled_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lattice_scaled_z={0x60610045U,"chemistry_lattice_scaled_z",sxsch_lattice_scaled_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_coordinate_scaled_x_fields[]={SX_FIELD("coordinate_scaled_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_coordinate_scaled_x={0x60610046U,"chemistry_coordinate_scaled_x",sxsch_coordinate_scaled_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_coordinate_scaled_y_fields[]={SX_FIELD("coordinate_scaled_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_coordinate_scaled_y={0x60610047U,"chemistry_coordinate_scaled_y",sxsch_coordinate_scaled_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_coordinate_scaled_z_fields[]={SX_FIELD("coordinate_scaled_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_coordinate_scaled_z={0x60610048U,"chemistry_coordinate_scaled_z",sxsch_coordinate_scaled_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_coordinate_x_fields[]={SX_FIELD("lammps_coordinate_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_lammps_coordinate_x={0x60610049U,"chemistry_lammps_coordinate_x",sxsch_lammps_coordinate_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_coordinate_y_fields[]={SX_FIELD("lammps_coordinate_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_lammps_coordinate_y={0x6061004aU,"chemistry_lammps_coordinate_y",sxsch_lammps_coordinate_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_coordinate_z_fields[]={SX_FIELD("lammps_coordinate_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_lammps_coordinate_z={0x6061004bU,"chemistry_lammps_coordinate_z",sxsch_lammps_coordinate_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_velocity_x_fields[]={SX_FIELD("lammps_velocity_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_lammps_velocity_x={0x6061004cU,"chemistry_lammps_velocity_x",sxsch_lammps_velocity_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_velocity_y_fields[]={SX_FIELD("lammps_velocity_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_lammps_velocity_y={0x6061004dU,"chemistry_lammps_velocity_y",sxsch_lammps_velocity_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_velocity_z_fields[]={SX_FIELD("lammps_velocity_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_lammps_velocity_z={0x6061004eU,"chemistry_lammps_velocity_z",sxsch_lammps_velocity_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_velocity_x_fields[]={SX_FIELD("dlp_velocity_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_dlp_velocity_x={0x6061004fU,"chemistry_dlp_velocity_x",sxsch_dlp_velocity_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_velocity_y_fields[]={SX_FIELD("dlp_velocity_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_dlp_velocity_y={0x60610050U,"chemistry_dlp_velocity_y",sxsch_dlp_velocity_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_velocity_z_fields[]={SX_FIELD("dlp_velocity_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_dlp_velocity_z={0x60610051U,"chemistry_dlp_velocity_z",sxsch_dlp_velocity_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_force_x_fields[]={SX_FIELD("dlp_force_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_dlp_force_x={0x60610052U,"chemistry_dlp_force_x",sxsch_dlp_force_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_force_y_fields[]={SX_FIELD("dlp_force_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_dlp_force_y={0x60610053U,"chemistry_dlp_force_y",sxsch_dlp_force_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_force_z_fields[]={SX_FIELD("dlp_force_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_dlp_force_z={0x60610054U,"chemistry_dlp_force_z",sxsch_dlp_force_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_siesta_velocity_x_fields[]={SX_FIELD("siesta_velocity_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_siesta_velocity_x={0x60610055U,"chemistry_siesta_velocity_x",sxsch_siesta_velocity_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_siesta_velocity_y_fields[]={SX_FIELD("siesta_velocity_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_siesta_velocity_y={0x60610056U,"chemistry_siesta_velocity_y",sxsch_siesta_velocity_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_siesta_velocity_z_fields[]={SX_FIELD("siesta_velocity_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_siesta_velocity_z={0x60610057U,"chemistry_siesta_velocity_z",sxsch_siesta_velocity_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_siesta_cell_velocity_x_fields[]={SX_FIELD("siesta_cell_velocity_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_siesta_cell_velocity_x={0x60610058U,"chemistry_siesta_cell_velocity_x",sxsch_siesta_cell_velocity_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_siesta_cell_velocity_y_fields[]={SX_FIELD("siesta_cell_velocity_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_siesta_cell_velocity_y={0x60610059U,"chemistry_siesta_cell_velocity_y",sxsch_siesta_cell_velocity_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_siesta_cell_velocity_z_fields[]={SX_FIELD("siesta_cell_velocity_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_siesta_cell_velocity_z={0x6061005aU,"chemistry_siesta_cell_velocity_z",sxsch_siesta_cell_velocity_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_xsf_force_x_fields[]={SX_FIELD("xsf_force_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_xsf_force_x={0x6061005bU,"chemistry_xsf_force_x",sxsch_xsf_force_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_xsf_force_y_fields[]={SX_FIELD("xsf_force_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_xsf_force_y={0x6061005cU,"chemistry_xsf_force_y",sxsch_xsf_force_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_xsf_force_z_fields[]={SX_FIELD("xsf_force_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_xsf_force_z={0x6061005dU,"chemistry_xsf_force_z",sxsch_xsf_force_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_a_fields[]={SX_FIELD("cell_a","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_cell_a={0x60610068U,"chemistry_cell_a",sxsch_cell_a_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_b_fields[]={SX_FIELD("cell_b","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_cell_b={0x60610069U,"chemistry_cell_b",sxsch_cell_b_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_c_fields[]={SX_FIELD("cell_c","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_cell_c={0x6061006aU,"chemistry_cell_c",sxsch_cell_c_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_box_lower_fields[]={SX_FIELD("box_lower","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_box_lower={0x60610070U,"chemistry_box_lower",sxsch_box_lower_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_box_upper_fields[]={SX_FIELD("box_upper","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_box_upper={0x60610071U,"chemistry_box_upper",sxsch_box_upper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_box_tilt_fields[]={SX_FIELD("box_tilt","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_box_tilt={0x60610072U,"chemistry_box_tilt",sxsch_box_tilt_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_basis_name_fields[]={SX_FIELD("basis_name","char",0,0,SX_STRING)};
const sx_layout sxsch_basis_name={0x606100b2U,"chemistry_basis_name",sxsch_basis_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_method_name_fields[]={SX_FIELD("method_name","char",0,0,SX_STRING)};
const sx_layout sxsch_method_name={0x606100b3U,"chemistry_method_name",sxsch_method_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_calculation_kind_fields[]={SX_FIELD("calculation_kind","char",0,0,SX_STRING)};
const sx_layout sxsch_calculation_kind={0x606100b4U,"chemistry_calculation_kind",sxsch_calculation_kind_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_iteration_count_fields[]={SX_FIELD("iteration_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_iteration_count={0x606100b5U,"chemistry_iteration_count",sxsch_iteration_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_threshold_fields[]={SX_FIELD("threshold","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_threshold={0x606100b6U,"chemistry_threshold",sxsch_threshold_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_processor_count_fields[]={SX_FIELD("processor_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_processor_count={0x606100b7U,"chemistry_processor_count",sxsch_processor_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cutoff_ry_fields[]={SX_FIELD("cutoff_ry","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_cutoff_ry={0x606100baU,"chemistry_cutoff_ry",sxsch_cutoff_ry_fields,1,SX_LE};
static const sx_layout*const sx_sciencechem_layouts[]={&sxsch_keyword,&sxsch_section,&sxsch_title,&sxsch_comment,&sxsch_text_value,&sxsch_element,&sxsch_atom_label,&sxsch_atom_name,&sxsch_residue_name,&sxsch_residue_id,&sxsch_segment_name,&sxsch_units,&sxsch_coordinate_mode,&sxsch_boolean_text,&sxsch_option_name,&sxsch_option_value,&sxsch_filename,&sxsch_format_string,&sxsch_value_type,&sxsch_atom_count,&sxsch_type_count,&sxsch_value_count,&sxsch_symmetry_count,&sxsch_species_count,&sxsch_atom_id,&sxsch_residue_index,&sxsch_species_index,&sxsch_atomic_number,&sxsch_charge,&sxsch_multiplicity,&sxsch_integer_value,&sxsch_real_value,&sxsch_mass,&sxsch_occupancy,&sxsch_weight,&sxsch_gaussian_coordinate_x,&sxsch_gaussian_coordinate_y,&sxsch_gaussian_coordinate_z,&sxsch_gaussian_lattice_x,&sxsch_gaussian_lattice_y,&sxsch_gaussian_lattice_z,&sxsch_mixing_factor,&sxsch_qe_total_charge,&sxsch_convergence_exponent,&sxsch_angstrom_x,&sxsch_angstrom_y,&sxsch_angstrom_z,&sxsch_bohr_x,&sxsch_bohr_y,&sxsch_bohr_z,&sxsch_fractional_x,&sxsch_fractional_y,&sxsch_fractional_z,&sxsch_lattice_angstrom_x,&sxsch_lattice_angstrom_y,&sxsch_lattice_angstrom_z,&sxsch_lattice_bohr_x,&sxsch_lattice_bohr_y,&sxsch_lattice_bohr_z,&sxsch_lammps_mass,&sxsch_abinit_cell_scale_x,&sxsch_abinit_cell_scale_y,&sxsch_abinit_cell_scale_z,&sxsch_abinit_rprim_x,&sxsch_abinit_rprim_y,&sxsch_abinit_rprim_z,&sxsch_lattice_scaled_x,&sxsch_lattice_scaled_y,&sxsch_lattice_scaled_z,&sxsch_coordinate_scaled_x,&sxsch_coordinate_scaled_y,&sxsch_coordinate_scaled_z,&sxsch_lammps_coordinate_x,&sxsch_lammps_coordinate_y,&sxsch_lammps_coordinate_z,&sxsch_lammps_velocity_x,&sxsch_lammps_velocity_y,&sxsch_lammps_velocity_z,&sxsch_dlp_velocity_x,&sxsch_dlp_velocity_y,&sxsch_dlp_velocity_z,&sxsch_dlp_force_x,&sxsch_dlp_force_y,&sxsch_dlp_force_z,&sxsch_siesta_velocity_x,&sxsch_siesta_velocity_y,&sxsch_siesta_velocity_z,&sxsch_siesta_cell_velocity_x,&sxsch_siesta_cell_velocity_y,&sxsch_siesta_cell_velocity_z,&sxsch_xsf_force_x,&sxsch_xsf_force_y,&sxsch_xsf_force_z,&sxsch_scale,&sxsch_dlp_level,&sxsch_dlp_periodicity,&sxsch_dimension,&sxsch_crystal_centering,&sxsch_crystal_type,&sxsch_energy,&sxsch_energy_delta,&sxsch_symmetry_component,&sxsch_wavelength,&sxsch_cell_a,&sxsch_cell_b,&sxsch_cell_c,&sxsch_cell_alpha,&sxsch_cell_beta,&sxsch_cell_gamma,&sxsch_shelx_lattice,&sxsch_lammps_timestep,&sxsch_box_lower,&sxsch_box_upper,&sxsch_box_tilt,&sxsch_boundary_code,&sxsch_column_name,&sxsch_move_flag,&sxsch_k_grid,&sxsch_k_shift,&sxsch_cif_data_block,&sxsch_cif_tag,&sxsch_cif_group,&sxsch_cif_value,&sxsch_cif_atom_id,&sxsch_amber_flag,&sxsch_amber_atom_name,&sxsch_amber_residue_label,&sxsch_amber_atom_type_index,&sxsch_amber_excluded_count,&sxsch_amber_residue_pointer,&sxsch_amber_charge,&sxsch_amber_mass,&sxsch_amber_integer,&sxsch_amber_real,&sxsch_amber_string,&sxsch_amber_natom,&sxsch_amber_ntypes,&sxsch_amber_nbonh,&sxsch_amber_mbona,&sxsch_amber_ntheth,&sxsch_amber_mtheta,&sxsch_amber_nphih,&sxsch_amber_mphia,&sxsch_amber_nhparm,&sxsch_amber_nparm,&sxsch_amber_next,&sxsch_amber_nres,&sxsch_amber_nbona,&sxsch_amber_ntheta,&sxsch_amber_nphia,&sxsch_amber_numbnd,&sxsch_amber_numang,&sxsch_amber_nptra,&sxsch_amber_natyp,&sxsch_amber_nphb,&sxsch_amber_ifpert,&sxsch_amber_nbper,&sxsch_amber_ngper,&sxsch_amber_ndper,&sxsch_amber_mbper,&sxsch_amber_mgper,&sxsch_amber_mdper,&sxsch_amber_ifbox,&sxsch_amber_nmxrs,&sxsch_amber_ifcap,&sxsch_amber_numextra,&sxsch_amber_ncopy,&sxsch_fchk_label,&sxsch_fchk_job,&sxsch_fchk_method,&sxsch_fchk_basis,&sxsch_fchk_array_marker,&sxsch_fchk_integer,&sxsch_fchk_real,&sxsch_fchk_coordinate,&sxsch_relaxation_constraint,&sxsch_unpaired_electrons,&sxsch_basis_name,&sxsch_method_name,&sxsch_calculation_kind,&sxsch_iteration_count,&sxsch_threshold,&sxsch_processor_count,&sxsch_memory_amount,&sxsch_memory_mb,&sxsch_cutoff_ry,&sxsch_cutoff_selected,&sxsch_initial_charge,&sxsch_initial_spin,&sxsch_nuclear_charge,&sxsch_symmetry_name};
static bool sx_sciencechem_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;if(id<0x60610001U||id>=0x60610001U+SX_COUNT(sx_sciencechem_layouts))return true;if(!r->name||xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;switch(id){
case 0x60610014U:return xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60610015U:return xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60610016U:return xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60610017U:return xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60610018U:return xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60610019U:return xx_data_struct_record_set_comment(r,L"Physical decimal identifier or one-based species index, not a source-file offset.");
case 0x6061001aU:return xx_data_struct_record_set_comment(r,L"Physical decimal identifier or one-based species index, not a source-file offset.");
case 0x6061001bU:return xx_data_struct_record_set_comment(r,L"Physical decimal identifier or one-based species index, not a source-file offset.");
case 0x6061001cU:return xx_data_struct_record_set_comment(r,L"Physical decimal identifier or one-based species index, not a source-file offset.");
case 0x6061001dU:return xx_data_struct_record_set_comment(r,L"Total charge in elementary-charge units.");
case 0x6061001eU:return xx_data_struct_record_set_comment(r,L"Spin multiplicity 2S+1.");
case 0x6061001fU:return xx_data_struct_record_set_comment(r,L"Format-defined signed scalar; interpretation belongs to the preceding physical key.");
case 0x60610020U:return xx_data_struct_record_set_comment(r,L"Format-defined real scalar; interpretation belongs to the preceding physical key.");
case 0x60610021U:return xx_data_struct_record_set_comment(r,L"Atomic mass in unified atomic mass units.");
case 0x60610022U:return xx_data_struct_record_set_comment(r,L"Site occupancy fraction.");
case 0x60610023U:return xx_data_struct_record_set_comment(r,L"CHARMM per-atom weighting scalar.");
case 0x60610024U:return xx_data_struct_record_set_comment(r,L"Gaussian Cartesian coordinate; default angstroms, but the preserved route section may override units.");
case 0x60610025U:return xx_data_struct_record_set_comment(r,L"Gaussian Cartesian coordinate; default angstroms, but the preserved route section may override units.");
case 0x60610026U:return xx_data_struct_record_set_comment(r,L"Gaussian Cartesian coordinate; default angstroms, but the preserved route section may override units.");
case 0x60610027U:return xx_data_struct_record_set_comment(r,L"Gaussian Tv lattice-vector component; default angstroms, but the preserved route section may override units.");
case 0x60610028U:return xx_data_struct_record_set_comment(r,L"Gaussian Tv lattice-vector component; default angstroms, but the preserved route section may override units.");
case 0x60610029U:return xx_data_struct_record_set_comment(r,L"Gaussian Tv lattice-vector component; default angstroms, but the preserved route section may override units.");
case 0x6061002aU:return xx_data_struct_record_set_comment(r,L"Dimensionless electron-density mixing factor.");
case 0x6061002bU:return xx_data_struct_record_set_comment(r,L"Total charge in elementary-charge units.");
case 0x6061002cU:return xx_data_struct_record_set_comment(r,L"Decimal convergence/threshold exponent, not an iteration count.");
case 0x6061002dU:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x6061002eU:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x6061002fU:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x60610030U:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate in bohr.");
case 0x60610031U:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate in bohr.");
case 0x60610032U:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate in bohr.");
case 0x60610033U:return xx_data_struct_record_set_comment(r,L"Fractional coordinate in the declared lattice; dimensionless.");
case 0x60610034U:return xx_data_struct_record_set_comment(r,L"Fractional coordinate in the declared lattice; dimensionless.");
case 0x60610035U:return xx_data_struct_record_set_comment(r,L"Fractional coordinate in the declared lattice; dimensionless.");
case 0x60610036U:return xx_data_struct_record_set_comment(r,L"Lattice-vector component in angstroms.");
case 0x60610037U:return xx_data_struct_record_set_comment(r,L"Lattice-vector component in angstroms.");
case 0x60610038U:return xx_data_struct_record_set_comment(r,L"Lattice-vector component in angstroms.");
case 0x60610039U:return xx_data_struct_record_set_comment(r,L"Lattice-vector component in bohr.");
case 0x6061003aU:return xx_data_struct_record_set_comment(r,L"Lattice-vector component in bohr.");
case 0x6061003bU:return xx_data_struct_record_set_comment(r,L"Lattice-vector component in bohr.");
case 0x6061003cU:return xx_data_struct_record_set_comment(r,L"LAMMPS mass in the externally selected unit system; no unit style is stored in this file.");
case 0x6061003dU:return xx_data_struct_record_set_comment(r,L"ABINIT acell length in the following declared units; default bohr.");
case 0x6061003eU:return xx_data_struct_record_set_comment(r,L"ABINIT acell length in the following declared units; default bohr.");
case 0x6061003fU:return xx_data_struct_record_set_comment(r,L"ABINIT acell length in the following declared units; default bohr.");
case 0x60610040U:return xx_data_struct_record_set_comment(r,L"ABINIT dimensionless primitive lattice vector; components are multiplied by acell.");
case 0x60610041U:return xx_data_struct_record_set_comment(r,L"ABINIT dimensionless primitive lattice vector; components are multiplied by acell.");
case 0x60610042U:return xx_data_struct_record_set_comment(r,L"ABINIT dimensionless primitive lattice vector; components are multiplied by acell.");
case 0x60610043U:return xx_data_struct_record_set_comment(r,L"Lattice-vector component multiplied by the declared scale; not a source-file offset.");
case 0x60610044U:return xx_data_struct_record_set_comment(r,L"Lattice-vector component multiplied by the declared scale; not a source-file offset.");
case 0x60610045U:return xx_data_struct_record_set_comment(r,L"Lattice-vector component multiplied by the declared scale; not a source-file offset.");
case 0x60610046U:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate multiplied by the declared scale; not a source-file offset.");
case 0x60610047U:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate multiplied by the declared scale; not a source-file offset.");
case 0x60610048U:return xx_data_struct_record_set_comment(r,L"Cartesian coordinate multiplied by the declared scale; not a source-file offset.");
case 0x60610049U:return xx_data_struct_record_set_comment(r,L"LAMMPS coordinate in the externally selected unit system; no unit style is stored in this file.");
case 0x6061004aU:return xx_data_struct_record_set_comment(r,L"LAMMPS coordinate in the externally selected unit system; no unit style is stored in this file.");
case 0x6061004bU:return xx_data_struct_record_set_comment(r,L"LAMMPS coordinate in the externally selected unit system; no unit style is stored in this file.");
case 0x6061004cU:return xx_data_struct_record_set_comment(r,L"LAMMPS velocity in the externally selected unit system.");
case 0x6061004dU:return xx_data_struct_record_set_comment(r,L"LAMMPS velocity in the externally selected unit system.");
case 0x6061004eU:return xx_data_struct_record_set_comment(r,L"LAMMPS velocity in the externally selected unit system.");
case 0x6061004fU:return xx_data_struct_record_set_comment(r,L"DL_POLY velocity in angstroms per picosecond.");
case 0x60610050U:return xx_data_struct_record_set_comment(r,L"DL_POLY velocity in angstroms per picosecond.");
case 0x60610051U:return xx_data_struct_record_set_comment(r,L"DL_POLY velocity in angstroms per picosecond.");
case 0x60610052U:return xx_data_struct_record_set_comment(r,L"DL_POLY force in internal mass-length-time units (amu angstrom per picosecond squared).");
case 0x60610053U:return xx_data_struct_record_set_comment(r,L"DL_POLY force in internal mass-length-time units (amu angstrom per picosecond squared).");
case 0x60610054U:return xx_data_struct_record_set_comment(r,L"DL_POLY force in internal mass-length-time units (amu angstrom per picosecond squared).");
case 0x60610055U:return xx_data_struct_record_set_comment(r,L"SIESTA XV stored atomic velocity component; retained without unit conversion.");
case 0x60610056U:return xx_data_struct_record_set_comment(r,L"SIESTA XV stored atomic velocity component; retained without unit conversion.");
case 0x60610057U:return xx_data_struct_record_set_comment(r,L"SIESTA XV stored atomic velocity component; retained without unit conversion.");
case 0x60610058U:return xx_data_struct_record_set_comment(r,L"SIESTA XV stored lattice-vector velocity component; retained without unit conversion.");
case 0x60610059U:return xx_data_struct_record_set_comment(r,L"SIESTA XV stored lattice-vector velocity component; retained without unit conversion.");
case 0x6061005aU:return xx_data_struct_record_set_comment(r,L"SIESTA XV stored lattice-vector velocity component; retained without unit conversion.");
case 0x6061005bU:return xx_data_struct_record_set_comment(r,L"XSF force component in hartree per angstrom.");
case 0x6061005cU:return xx_data_struct_record_set_comment(r,L"XSF force component in hartree per angstrom.");
case 0x6061005dU:return xx_data_struct_record_set_comment(r,L"XSF force component in hartree per angstrom.");
case 0x6061005eU:return xx_data_struct_record_set_comment(r,L"Positive POSCAR universal scale factor; lattice and Cartesian position values retain their original unscaled values.");
case 0x6061005fU:return xx_data_struct_record_set_comment(r,L"0: positions; 1: positions and velocities; 2: positions, velocities and forces.");
case 0x60610060U:return xx_data_struct_record_set_comment(r,L"DL_POLY periodic boundary code; native accepts0..3.");
case 0x60610061U:return xx_data_struct_record_set_comment(r,L"Periodicity dimension0..3.");
case 0x60610062U:return xx_data_struct_record_set_comment(r,L"CRYSTAL physical geometry header code; native accepts1.");
case 0x60610063U:return xx_data_struct_record_set_comment(r,L"CRYSTAL physical geometry header code; native accepts1.");
case 0x60610064U:return xx_data_struct_record_set_comment(r,L"CRYSTAL optional energy or energy-change value; units belong to the producing calculation.");
case 0x60610065U:return xx_data_struct_record_set_comment(r,L"CRYSTAL optional energy or energy-change value; units belong to the producing calculation.");
case 0x60610066U:return xx_data_struct_record_set_comment(r,L"Physical symmetry matrix or translation component; native supports identity symmetry only.");
case 0x60610067U:return xx_data_struct_record_set_comment(r,L"X-ray wavelength in angstroms.");
case 0x60610068U:return xx_data_struct_record_set_comment(r,L"Cell length in angstroms.");
case 0x60610069U:return xx_data_struct_record_set_comment(r,L"Cell length in angstroms.");
case 0x6061006aU:return xx_data_struct_record_set_comment(r,L"Cell length in angstroms.");
case 0x6061006bU:return xx_data_struct_record_set_comment(r,L"Cell angle in degrees.");
case 0x6061006cU:return xx_data_struct_record_set_comment(r,L"Cell angle in degrees.");
case 0x6061006dU:return xx_data_struct_record_set_comment(r,L"Cell angle in degrees.");
case 0x6061006eU:return xx_data_struct_record_set_comment(r,L"SHELX LATT code; native subset accepts -1 (primitive, non-centrosymmetric).");
case 0x6061006fU:return xx_data_struct_record_set_comment(r,L"Simulation step number, not a wall-clock timestamp.");
case 0x60610070U:return xx_data_struct_record_set_comment(r,L"LAMMPS box bound or tilt in the externally selected distance units.");
case 0x60610071U:return xx_data_struct_record_set_comment(r,L"LAMMPS box bound or tilt in the externally selected distance units.");
case 0x60610072U:return xx_data_struct_record_set_comment(r,L"LAMMPS box bound or tilt in the externally selected distance units.");
case 0x60610073U:return xx_data_struct_record_set_comment(r,L"Two boundary flags: p periodic, f fixed, s shrink-wrap, m minimum shrink-wrap.");
case 0x60610075U:return xx_data_struct_record_set_comment(r,L"0: frozen; 1: movable in the corresponding Cartesian component.");
case 0x60610076U:return xx_data_struct_record_set_comment(r,L"Number of k-point grid subdivisions.");
case 0x60610077U:return xx_data_struct_record_set_comment(r,L"0: unshifted; 1: half-grid shift.");
case 0x60610078U:return xx_data_struct_record_set_comment(r,L"Original mmCIF token content; quoting delimiters remain raw.");
case 0x60610079U:return xx_data_struct_record_set_comment(r,L"Original mmCIF token content; quoting delimiters remain raw.");
case 0x6061007aU:return xx_data_struct_record_set_comment(r,L"Original mmCIF token content; quoting delimiters remain raw.");
case 0x6061007bU:return xx_data_struct_record_set_comment(r,L"Original mmCIF token content; quoting delimiters remain raw.");
case 0x6061007cU:return xx_data_struct_record_set_comment(r,L"Atom-site decimal ID, not a byte offset.");
case 0x60610080U:return xx_data_struct_record_set_comment(r,L"One-based nonbonded atom-type index.");
case 0x60610081U:return xx_data_struct_record_set_comment(r,L"Number of excluded atoms for this atom.");
case 0x60610082U:return xx_data_struct_record_set_comment(r,L"One-based index of the first atom in the residue.");
case 0x60610083U:return xx_data_struct_record_set_comment(r,L"AMBER stored charge; divide by18.2223 for elementary-charge units.");
case 0x60610084U:return xx_data_struct_record_set_comment(r,L"Atomic mass in unified atomic mass units.");
case 0x60610085U:return xx_data_struct_record_set_comment(r,L"Physical signed integer in a %FLAG section.");
case 0x60610086U:return xx_data_struct_record_set_comment(r,L"Physical real in a %FLAG section; units depend on the named flag.");
case 0x60610088U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NATOM: physical count or control word, not a source-file pointer.");
case 0x60610089U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NTYPES: physical count or control word, not a source-file pointer.");
case 0x6061008aU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NBONH: physical count or control word, not a source-file pointer.");
case 0x6061008bU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS MBONA: physical count or control word, not a source-file pointer.");
case 0x6061008cU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NTHETH: physical count or control word, not a source-file pointer.");
case 0x6061008dU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS MTHETA: physical count or control word, not a source-file pointer.");
case 0x6061008eU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NPHIH: physical count or control word, not a source-file pointer.");
case 0x6061008fU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS MPHIA: physical count or control word, not a source-file pointer.");
case 0x60610090U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NHPARM: physical count or control word, not a source-file pointer.");
case 0x60610091U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NPARM: physical count or control word, not a source-file pointer.");
case 0x60610092U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NEXT: physical count or control word, not a source-file pointer.");
case 0x60610093U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NRES: physical count or control word, not a source-file pointer.");
case 0x60610094U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NBONA: physical count or control word, not a source-file pointer.");
case 0x60610095U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NTHETA: physical count or control word, not a source-file pointer.");
case 0x60610096U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NPHIA: physical count or control word, not a source-file pointer.");
case 0x60610097U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NUMBND: physical count or control word, not a source-file pointer.");
case 0x60610098U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NUMANG: physical count or control word, not a source-file pointer.");
case 0x60610099U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NPTRA: physical count or control word, not a source-file pointer.");
case 0x6061009aU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NATYP: physical count or control word, not a source-file pointer.");
case 0x6061009bU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NPHB: physical count or control word, not a source-file pointer.");
case 0x6061009cU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS IFPERT: physical count or control word, not a source-file pointer.");
case 0x6061009dU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NBPER: physical count or control word, not a source-file pointer.");
case 0x6061009eU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NGPER: physical count or control word, not a source-file pointer.");
case 0x6061009fU:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NDPER: physical count or control word, not a source-file pointer.");
case 0x606100a0U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS MBPER: physical count or control word, not a source-file pointer.");
case 0x606100a1U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS MGPER: physical count or control word, not a source-file pointer.");
case 0x606100a2U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS MDPER: physical count or control word, not a source-file pointer.");
case 0x606100a3U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS IFBOX: physical count or control word, not a source-file pointer.");
case 0x606100a4U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NMXRS: physical count or control word, not a source-file pointer.");
case 0x606100a5U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS IFCAP: physical count or control word, not a source-file pointer.");
case 0x606100a6U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NUMEXTRA: physical count or control word, not a source-file pointer.");
case 0x606100a7U:return xx_data_struct_record_set_comment(r,L"AMBER POINTERS NCOPY: physical count or control word, not a source-file pointer.");
case 0x606100adU:return xx_data_struct_record_set_comment(r,L"Physical signed integer scalar or array member.");
case 0x606100aeU:return xx_data_struct_record_set_comment(r,L"Physical real scalar or array member; units depend on the label.");
case 0x606100afU:return xx_data_struct_record_set_comment(r,L"Gaussian Cartesian coordinate in bohr.");
case 0x606100b0U:return xx_data_struct_record_set_comment(r,L"FHI-aims constraint: .true. fixes all coordinates; x/y/z fixes the named Cartesian component.");
case 0x606100b1U:return xx_data_struct_record_set_comment(r,L"NWChem number of unpaired electrons.");
case 0x606100b5U:return xx_data_struct_record_set_comment(r,L"Maximum iterations or steps.");
case 0x606100b6U:return xx_data_struct_record_set_comment(r,L"Convergence threshold; units depend on the option name.");
case 0x606100b7U:return xx_data_struct_record_set_comment(r,L"Number of processors.");
case 0x606100b8U:return xx_data_struct_record_set_comment(r,L"Requested memory amount in the following encoded units; not bytes unless explicitly selected.");
case 0x606100b9U:return xx_data_struct_record_set_comment(r,L"ORCA per-process memory request in MB; not a byte size.");
case 0x606100baU:return xx_data_struct_record_set_comment(r,L"Plane-wave or integration-grid cutoff in rydberg.");
case 0x606100bbU:return xx_data_struct_record_set_comment(r,L"Energy cutoff in explicit following units, default hartree.");
case 0x606100bcU:return xx_data_struct_record_set_comment(r,L"Initial atomic charge in elementary-charge units.");
case 0x606100bdU:return xx_data_struct_record_set_comment(r,L"Initial atomic spin moment, following FHI-aims convention.");
case 0x606100beU:return xx_data_struct_record_set_comment(r,L"Atomic nuclear charge.");
default:return true;}}
bool sxsch_space(uint8_t c){return c==' '||c=='\t'||c=='\r'||c=='\n';}
bool sxsch_eq(sxsch_cursor*q,sxsch_token t,const char*s){size_t n=xx_rt_strlen(s);return t.a>=0&&t.z==(int64_t)n&&t.a<=q->n&&t.z<=q->n-t.a&&!xx_rt_memcmp(q->b+t.a,s,n);}
bool sxsch_ci(sxsch_cursor*q,sxsch_token t,const char*s){size_t n=xx_rt_strlen(s);if(t.a<0||t.z!=(int64_t)n||t.a>q->n||t.z>q->n-t.a)return false;for(size_t i=0;i<n;i++){unsigned ch=q->b[t.a+i];if(ch>='A'&&ch<='Z')ch+=32;if(ch!=(unsigned char)s[i])return false;}return true;}
sxsch_token sxsch_trim(sxsch_cursor*q,sxsch_token t){while(t.z&&sxsch_space(q->b[t.a])){t.a++;t.z--;}while(t.z&&sxsch_space(q->b[t.a+t.z-1]))t.z--;return t;}
bool sxsch_line(sxsch_cursor*q,sxsch_token*t){if(q->p>=q->n||++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;t->a=q->p;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;t->z=q->p-t->a;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;return true;}
unsigned sxsch_split(sxsch_cursor*q,sxsch_token line,sxsch_token*t,unsigned cap,bool tabs){unsigned n=0;int64_t p=line.a,end=p+line.z;while(p<end){if(tabs){int64_t a=p;while(p<end&&q->b[p]!='\t')p++;if(n==cap)return cap+1;t[n++]=(sxsch_token){a,p-a};if(p<end)p++;}else{while(p<end&&sxsch_space(q->b[p]))p++;if(p==end)break;int64_t a=p;while(p<end&&!sxsch_space(q->b[p]))p++;if(n==cap)return cap+1;t[n++]=(sxsch_token){a,p-a};}}return n;}
bool sxsch_emit(sxsch_cursor*q,const sx_layout*l,sxsch_token t){if(t.a<0||t.z<0||t.a>q->n||t.z>q->n-t.a||xx_pd_is_stopped(q->c->pd))return false;if(!t.z||q->c->count>=24000)return true;if(t.z>sx_variable_field_limit(l->fields[0].type))return true;return sx_add(q->c,l,t.a,t.z);}
bool sxsch_number(sxsch_cursor*q,sxsch_token t,uint64_t*v){t=sxsch_trim(q,t);uint64_t n=0;int64_t i=0;if(t.z&&q->b[t.a]=='+')i++;if(i==t.z)return false;for(;i<t.z;i++){unsigned d=q->b[t.a+i]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*v=n;return true;}
bool sxsch_fields(sxsch_cursor*q,sxsch_token*t,unsigned n,const sx_layout*const*l,unsigned max){if(n>max)return false;for(unsigned i=0;i<n;i++)if(l[i]&&!sxsch_emit(q,l[i],t[i]))return false;return true;}
bool sxsch_column(sxsch_cursor*q,const sx_layout*l,sxsch_token line,unsigned at,unsigned width){if(at>(uint64_t)line.z||width>(uint64_t)line.z-at)return false;sxsch_token t={line.a+at,width};/* Blank optional numeric columns remain raw. */if(!sxsch_trim(q,t).z)return true;return sxsch_emit(q,l,t);}
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
#define SC_COL(n,o,z) do{if(!sxsch_column(q,&sxsch_##n,line,(o),(z)))return false;}while(0)
bool sxsch_next(sxsch_cursor*q,sxsch_token*line,sxsch_token*t,unsigned cap,unsigned*n,const char*comments){while(sxsch_line(q,line)){int64_t i=0;for(;i<line->z;i++){if(xx_rt_strchr(comments,q->b[line->a+i])){SC_EMIT(comment,((sxsch_token){line->a+i,line->z-i}));line->z=i;break;}}*line=sxsch_trim(q,*line);if(line->z){*n=sxsch_split(q,*line,t,cap,false);return *n<=cap;}}return false;}
bool sxsch_xyz(sxsch_cursor*q,sxsch_token*t,unsigned mode){const sx_layout*const rows[][3]={{&sxsch_angstrom_x,&sxsch_angstrom_y,&sxsch_angstrom_z},{&sxsch_bohr_x,&sxsch_bohr_y,&sxsch_bohr_z},{&sxsch_fractional_x,&sxsch_fractional_y,&sxsch_fractional_z},{&sxsch_lattice_angstrom_x,&sxsch_lattice_angstrom_y,&sxsch_lattice_angstrom_z},{&sxsch_lattice_bohr_x,&sxsch_lattice_bohr_y,&sxsch_lattice_bohr_z},{&sxsch_lattice_scaled_x,&sxsch_lattice_scaled_y,&sxsch_lattice_scaled_z},{&sxsch_coordinate_scaled_x,&sxsch_coordinate_scaled_y,&sxsch_coordinate_scaled_z},{&sxsch_lammps_coordinate_x,&sxsch_lammps_coordinate_y,&sxsch_lammps_coordinate_z},{&sxsch_lammps_velocity_x,&sxsch_lammps_velocity_y,&sxsch_lammps_velocity_z},{&sxsch_dlp_velocity_x,&sxsch_dlp_velocity_y,&sxsch_dlp_velocity_z},{&sxsch_dlp_force_x,&sxsch_dlp_force_y,&sxsch_dlp_force_z},{&sxsch_siesta_velocity_x,&sxsch_siesta_velocity_y,&sxsch_siesta_velocity_z},{&sxsch_siesta_cell_velocity_x,&sxsch_siesta_cell_velocity_y,&sxsch_siesta_cell_velocity_z},{&sxsch_xsf_force_x,&sxsch_xsf_force_y,&sxsch_xsf_force_z}};return mode<SX_COUNT(rows)&&sxsch_fields(q,t,3,rows[mode],3);}
bool sxsch_each(sxsch_cursor*q,sxsch_token*t,unsigned n,const sx_layout*l){for(unsigned i=0;i<n;i++)if(!sxsch_emit(q,l,t[i]))return false;return true;}
bool sxsch_assignment(sxsch_cursor*q,sxsch_token row,sxsch_token*key,sxsch_token*value){int64_t p=0;while(p<row.z&&q->b[row.a+p]!='=')p++;if(!p||p==row.z)return false;*key=sxsch_trim(q,(sxsch_token){row.a,p});*value=sxsch_trim(q,(sxsch_token){row.a+p+1,row.z-p-1});if(value->z&&q->b[value->a+value->z-1]==','){value->z--;*value=sxsch_trim(q,*value);}if(value->z>=2&&((q->b[value->a]=='\''&&q->b[value->a+value->z-1]=='\'')||(q->b[value->a]=='"'&&q->b[value->a+value->z-1]=='"'))){value->a++;value->z-=2;}return key->z&&value->z;}
bool sxsch_option(sxsch_cursor*q,sxsch_token key,sxsch_token value,const sx_layout*layout){SC_EMIT(option_name,key);return sxsch_emit(q,layout,value);}
static int sxsch_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxsch_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsch_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsch_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_sciencechem_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_PROTEIN_MMCIF:case XX_FILE_TYPE_XCRYSDEN_XSF:case XX_FILE_TYPE_AMBER_PRMTOP:case XX_FILE_TYPE_GAUSSIAN_FCHK:case XX_FILE_TYPE_DL_POLY_CONFIG:case XX_FILE_TYPE_LAMMPS_DATA:case XX_FILE_TYPE_LAMMPS_DUMP:case XX_FILE_TYPE_SHELX_RES:case XX_FILE_TYPE_CHARMM_CRD:case XX_FILE_TYPE_CASTEP_CELL:case XX_FILE_TYPE_CRYSTAL_FORT34:case XX_FILE_TYPE_SIESTA_XV:case XX_FILE_TYPE_VASP_POSCAR:case XX_FILE_TYPE_QUANTUM_ESPRESSO_INPUT:case XX_FILE_TYPE_CP2K_INPUT:case XX_FILE_TYPE_NWCHEM_INPUT:case XX_FILE_TYPE_GAMESS_INPUT:case XX_FILE_TYPE_GAUSSIAN_INPUT:case XX_FILE_TYPE_ABINIT_INPUT:case XX_FILE_TYPE_AIMS_GEOMETRY:case XX_FILE_TYPE_ORCA_INPUT:case XX_FILE_TYPE_DEMON_INPUT:case XX_FILE_TYPE_QCHEM_INPUT:return true;default:return false;}}
static bool sx_sciencechem_build(sx_context*c){if(!c||!c->f||c->size<1||c->size>67108864||xx_pd_is_stopped(c->pd))return false;if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxsch_cursor cursor={c,b,c->size,0,0},*q=&cursor;xx_file_type_t type=c->f->file_type;if(ok)switch(type){
case XX_FILE_TYPE_PROTEIN_MMCIF:ok=sx_protein_mmcif_build(q);break;
case XX_FILE_TYPE_XCRYSDEN_XSF:ok=sx_xcrysden_xsf_build(q);break;
case XX_FILE_TYPE_AMBER_PRMTOP:ok=sx_amber_prmtop_build(q);break;
case XX_FILE_TYPE_GAUSSIAN_FCHK:ok=sx_gaussian_fchk_build(q);break;
case XX_FILE_TYPE_DL_POLY_CONFIG:ok=sx_dl_poly_config_build(q);break;
case XX_FILE_TYPE_LAMMPS_DATA:ok=sx_lammps_data_build(q);break;
case XX_FILE_TYPE_LAMMPS_DUMP:ok=sx_lammps_dump_build(q);break;
case XX_FILE_TYPE_SHELX_RES:ok=sx_shelx_res_build(q);break;
case XX_FILE_TYPE_CHARMM_CRD:ok=sx_charmm_crd_build(q);break;
case XX_FILE_TYPE_CASTEP_CELL:ok=sx_castep_cell_build(q);break;
case XX_FILE_TYPE_CRYSTAL_FORT34:ok=sx_crystal_fort34_build(q);break;
case XX_FILE_TYPE_SIESTA_XV:ok=sx_siesta_xv_build(q);break;
case XX_FILE_TYPE_VASP_POSCAR:ok=sx_vasp_poscar_build(q);break;
case XX_FILE_TYPE_QUANTUM_ESPRESSO_INPUT:ok=sx_quantum_espresso_input_build(q);break;
case XX_FILE_TYPE_CP2K_INPUT:ok=sx_cp2k_input_build(q);break;
case XX_FILE_TYPE_NWCHEM_INPUT:ok=sx_nwchem_input_build(q);break;
case XX_FILE_TYPE_GAMESS_INPUT:ok=sx_gamess_input_build(q);break;
case XX_FILE_TYPE_GAUSSIAN_INPUT:ok=sx_gaussian_input_build(q);break;
case XX_FILE_TYPE_ABINIT_INPUT:ok=sx_abinit_input_build(q);break;
case XX_FILE_TYPE_AIMS_GEOMETRY:ok=sx_aims_geometry_build(q);break;
case XX_FILE_TYPE_ORCA_INPUT:ok=sx_orca_input_build(q);break;
case XX_FILE_TYPE_DEMON_INPUT:ok=sx_demon_input_build(q);break;
case XX_FILE_TYPE_QCHEM_INPUT:ok=sx_qchem_input_build(q);break;
default:ok=false;break;}xx_mem_free(b);return ok&&sxsch_finish(c);}
#undef SC_EMIT
#undef SC_COL
const sx_family sx_sciencechem_family={sx_sciencechem_supports,sx_sciencechem_build,sx_sciencechem_layouts,SX_COUNT(sx_sciencechem_layouts),sx_sciencechem_comment};
