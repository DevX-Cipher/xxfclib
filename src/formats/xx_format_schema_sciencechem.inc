/* SPDX-License-Identifier: MIT
 * Native-supported physical chemistry fields. Delimiters and unsupported text remain raw. */
static const xx_data_struct_field_desc sxsch_keyword_fields[]={SX_FIELD("keyword","char",0,0,SX_STRING)};
static const sx_layout sxsch_keyword={0x60610001U,"chemistry_keyword",sxsch_keyword_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_section_fields[]={SX_FIELD("section","char",0,0,SX_STRING)};
static const sx_layout sxsch_section={0x60610002U,"chemistry_section",sxsch_section_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_title_fields[]={SX_FIELD("title","utf8",0,0,SX_STRING)};
static const sx_layout sxsch_title={0x60610003U,"chemistry_title",sxsch_title_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_comment_fields[]={SX_FIELD("comment","utf8",0,0,SX_STRING)};
static const sx_layout sxsch_comment={0x60610004U,"chemistry_comment",sxsch_comment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_text_value_fields[]={SX_FIELD("text_value","utf8",0,0,SX_STRING)};
static const sx_layout sxsch_text_value={0x60610005U,"chemistry_text_value",sxsch_text_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_element_fields[]={SX_FIELD("element","char",0,0,SX_STRING)};
static const sx_layout sxsch_element={0x60610006U,"chemistry_element",sxsch_element_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atom_label_fields[]={SX_FIELD("atom_label","char",0,0,SX_STRING)};
static const sx_layout sxsch_atom_label={0x60610007U,"chemistry_atom_label",sxsch_atom_label_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atom_name_fields[]={SX_FIELD("atom_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_atom_name={0x60610008U,"chemistry_atom_name",sxsch_atom_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_residue_name_fields[]={SX_FIELD("residue_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_residue_name={0x60610009U,"chemistry_residue_name",sxsch_residue_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_residue_id_fields[]={SX_FIELD("residue_id","char",0,0,SX_STRING)};
static const sx_layout sxsch_residue_id={0x6061000aU,"chemistry_residue_id",sxsch_residue_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_segment_name_fields[]={SX_FIELD("segment_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_segment_name={0x6061000bU,"chemistry_segment_name",sxsch_segment_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_units_fields[]={SX_FIELD("units","char",0,0,SX_STRING)};
static const sx_layout sxsch_units={0x6061000cU,"chemistry_units",sxsch_units_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_coordinate_mode_fields[]={SX_FIELD("coordinate_mode","char",0,0,SX_STRING)};
static const sx_layout sxsch_coordinate_mode={0x6061000dU,"chemistry_coordinate_mode",sxsch_coordinate_mode_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_boolean_text_fields[]={SX_FIELD("boolean_text","char",0,0,SX_STRING)};
static const sx_layout sxsch_boolean_text={0x6061000eU,"chemistry_boolean_text",sxsch_boolean_text_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_option_name_fields[]={SX_FIELD("option_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_option_name={0x6061000fU,"chemistry_option_name",sxsch_option_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_option_value_fields[]={SX_FIELD("option_value","char",0,0,SX_STRING)};
static const sx_layout sxsch_option_value={0x60610010U,"chemistry_option_value",sxsch_option_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_filename_fields[]={SX_FIELD("filename","char",0,0,SX_STRING)};
static const sx_layout sxsch_filename={0x60610011U,"chemistry_filename",sxsch_filename_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_format_string_fields[]={SX_FIELD("format_string","char",0,0,SX_STRING)};
static const sx_layout sxsch_format_string={0x60610012U,"chemistry_format_string",sxsch_format_string_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_value_type_fields[]={SX_FIELD("value_type","char",0,0,SX_STRING)};
static const sx_layout sxsch_value_type={0x60610013U,"chemistry_value_type",sxsch_value_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atom_count_fields[]={SX_FIELD("atom_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_atom_count={0x60610014U,"chemistry_atom_count",sxsch_atom_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_type_count_fields[]={SX_FIELD("type_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_type_count={0x60610015U,"chemistry_type_count",sxsch_type_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_value_count_fields[]={SX_FIELD("value_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_value_count={0x60610016U,"chemistry_value_count",sxsch_value_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_symmetry_count_fields[]={SX_FIELD("symmetry_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_symmetry_count={0x60610017U,"chemistry_symmetry_count",sxsch_symmetry_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_species_count_fields[]={SX_FIELD("species_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_species_count={0x60610018U,"chemistry_species_count",sxsch_species_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atom_id_fields[]={SX_FIELD("atom_id","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_atom_id={0x60610019U,"chemistry_atom_id",sxsch_atom_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_residue_index_fields[]={SX_FIELD("residue_index","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_residue_index={0x6061001aU,"chemistry_residue_index",sxsch_residue_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_species_index_fields[]={SX_FIELD("species_index","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_species_index={0x6061001bU,"chemistry_species_index",sxsch_species_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_atomic_number_fields[]={SX_FIELD("atomic_number","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_atomic_number={0x6061001cU,"chemistry_atomic_number",sxsch_atomic_number_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_charge_fields[]={SX_FIELD("charge","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_charge={0x6061001dU,"chemistry_charge",sxsch_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_multiplicity_fields[]={SX_FIELD("multiplicity","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_multiplicity={0x6061001eU,"chemistry_multiplicity",sxsch_multiplicity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_integer_value_fields[]={SX_FIELD("integer_value","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_integer_value={0x6061001fU,"chemistry_integer_value",sxsch_integer_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_real_value_fields[]={SX_FIELD("real_value","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_real_value={0x60610020U,"chemistry_real_value",sxsch_real_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_mass_fields[]={SX_FIELD("mass","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_mass={0x60610021U,"chemistry_mass",sxsch_mass_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_occupancy_fields[]={SX_FIELD("occupancy","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_occupancy={0x60610022U,"chemistry_occupancy",sxsch_occupancy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_weight_fields[]={SX_FIELD("weight","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_weight={0x60610023U,"chemistry_weight",sxsch_weight_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_coordinate_x_fields[]={SX_FIELD("gaussian_coordinate_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_gaussian_coordinate_x={0x60610024U,"chemistry_gaussian_coordinate_x",sxsch_gaussian_coordinate_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_coordinate_y_fields[]={SX_FIELD("gaussian_coordinate_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_gaussian_coordinate_y={0x60610025U,"chemistry_gaussian_coordinate_y",sxsch_gaussian_coordinate_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_coordinate_z_fields[]={SX_FIELD("gaussian_coordinate_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_gaussian_coordinate_z={0x60610026U,"chemistry_gaussian_coordinate_z",sxsch_gaussian_coordinate_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_lattice_x_fields[]={SX_FIELD("gaussian_lattice_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_gaussian_lattice_x={0x60610027U,"chemistry_gaussian_lattice_x",sxsch_gaussian_lattice_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_lattice_y_fields[]={SX_FIELD("gaussian_lattice_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_gaussian_lattice_y={0x60610028U,"chemistry_gaussian_lattice_y",sxsch_gaussian_lattice_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_gaussian_lattice_z_fields[]={SX_FIELD("gaussian_lattice_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_gaussian_lattice_z={0x60610029U,"chemistry_gaussian_lattice_z",sxsch_gaussian_lattice_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_mixing_factor_fields[]={SX_FIELD("mixing_factor","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_mixing_factor={0x6061002aU,"chemistry_mixing_factor",sxsch_mixing_factor_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_qe_total_charge_fields[]={SX_FIELD("qe_total_charge","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_qe_total_charge={0x6061002bU,"chemistry_qe_total_charge",sxsch_qe_total_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_convergence_exponent_fields[]={SX_FIELD("convergence_exponent","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_convergence_exponent={0x6061002cU,"chemistry_convergence_exponent",sxsch_convergence_exponent_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_angstrom_x_fields[]={SX_FIELD("angstrom_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_angstrom_x={0x6061002dU,"chemistry_angstrom_x",sxsch_angstrom_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_angstrom_y_fields[]={SX_FIELD("angstrom_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_angstrom_y={0x6061002eU,"chemistry_angstrom_y",sxsch_angstrom_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_angstrom_z_fields[]={SX_FIELD("angstrom_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_angstrom_z={0x6061002fU,"chemistry_angstrom_z",sxsch_angstrom_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_bohr_x_fields[]={SX_FIELD("bohr_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_bohr_x={0x60610030U,"chemistry_bohr_x",sxsch_bohr_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_bohr_y_fields[]={SX_FIELD("bohr_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_bohr_y={0x60610031U,"chemistry_bohr_y",sxsch_bohr_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_bohr_z_fields[]={SX_FIELD("bohr_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_bohr_z={0x60610032U,"chemistry_bohr_z",sxsch_bohr_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fractional_x_fields[]={SX_FIELD("fractional_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_fractional_x={0x60610033U,"chemistry_fractional_x",sxsch_fractional_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fractional_y_fields[]={SX_FIELD("fractional_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_fractional_y={0x60610034U,"chemistry_fractional_y",sxsch_fractional_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fractional_z_fields[]={SX_FIELD("fractional_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_fractional_z={0x60610035U,"chemistry_fractional_z",sxsch_fractional_z_fields,1,SX_LE};
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
static const xx_data_struct_field_desc sxsch_lammps_mass_fields[]={SX_FIELD("lammps_mass","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lammps_mass={0x6061003cU,"chemistry_lammps_mass",sxsch_lammps_mass_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_cell_scale_x_fields[]={SX_FIELD("abinit_cell_scale_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_abinit_cell_scale_x={0x6061003dU,"chemistry_abinit_cell_scale_x",sxsch_abinit_cell_scale_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_cell_scale_y_fields[]={SX_FIELD("abinit_cell_scale_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_abinit_cell_scale_y={0x6061003eU,"chemistry_abinit_cell_scale_y",sxsch_abinit_cell_scale_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_cell_scale_z_fields[]={SX_FIELD("abinit_cell_scale_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_abinit_cell_scale_z={0x6061003fU,"chemistry_abinit_cell_scale_z",sxsch_abinit_cell_scale_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_rprim_x_fields[]={SX_FIELD("abinit_rprim_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_abinit_rprim_x={0x60610040U,"chemistry_abinit_rprim_x",sxsch_abinit_rprim_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_rprim_y_fields[]={SX_FIELD("abinit_rprim_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_abinit_rprim_y={0x60610041U,"chemistry_abinit_rprim_y",sxsch_abinit_rprim_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_abinit_rprim_z_fields[]={SX_FIELD("abinit_rprim_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_abinit_rprim_z={0x60610042U,"chemistry_abinit_rprim_z",sxsch_abinit_rprim_z_fields,1,SX_LE};
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
static const sx_layout sxsch_lammps_coordinate_x={0x60610049U,"chemistry_lammps_coordinate_x",sxsch_lammps_coordinate_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_coordinate_y_fields[]={SX_FIELD("lammps_coordinate_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lammps_coordinate_y={0x6061004aU,"chemistry_lammps_coordinate_y",sxsch_lammps_coordinate_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_coordinate_z_fields[]={SX_FIELD("lammps_coordinate_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lammps_coordinate_z={0x6061004bU,"chemistry_lammps_coordinate_z",sxsch_lammps_coordinate_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_velocity_x_fields[]={SX_FIELD("lammps_velocity_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lammps_velocity_x={0x6061004cU,"chemistry_lammps_velocity_x",sxsch_lammps_velocity_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_velocity_y_fields[]={SX_FIELD("lammps_velocity_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lammps_velocity_y={0x6061004dU,"chemistry_lammps_velocity_y",sxsch_lammps_velocity_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_velocity_z_fields[]={SX_FIELD("lammps_velocity_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_lammps_velocity_z={0x6061004eU,"chemistry_lammps_velocity_z",sxsch_lammps_velocity_z_fields,1,SX_LE};
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
static const xx_data_struct_field_desc sxsch_scale_fields[]={SX_FIELD("scale","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_scale={0x6061005eU,"chemistry_scale",sxsch_scale_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_level_fields[]={SX_FIELD("dlp_level","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_dlp_level={0x6061005fU,"chemistry_dlp_level",sxsch_dlp_level_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dlp_periodicity_fields[]={SX_FIELD("dlp_periodicity","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_dlp_periodicity={0x60610060U,"chemistry_dlp_periodicity",sxsch_dlp_periodicity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_dimension_fields[]={SX_FIELD("dimension","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_dimension={0x60610061U,"chemistry_dimension",sxsch_dimension_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_crystal_centering_fields[]={SX_FIELD("crystal_centering","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_crystal_centering={0x60610062U,"chemistry_crystal_centering",sxsch_crystal_centering_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_crystal_type_fields[]={SX_FIELD("crystal_type","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_crystal_type={0x60610063U,"chemistry_crystal_type",sxsch_crystal_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_energy_fields[]={SX_FIELD("energy","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_energy={0x60610064U,"chemistry_energy",sxsch_energy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_energy_delta_fields[]={SX_FIELD("energy_delta","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_energy_delta={0x60610065U,"chemistry_energy_delta",sxsch_energy_delta_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_symmetry_component_fields[]={SX_FIELD("symmetry_component","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_symmetry_component={0x60610066U,"chemistry_symmetry_component",sxsch_symmetry_component_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_wavelength_fields[]={SX_FIELD("wavelength","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_wavelength={0x60610067U,"chemistry_wavelength",sxsch_wavelength_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_a_fields[]={SX_FIELD("cell_a","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_cell_a={0x60610068U,"chemistry_cell_a",sxsch_cell_a_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_b_fields[]={SX_FIELD("cell_b","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_cell_b={0x60610069U,"chemistry_cell_b",sxsch_cell_b_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_c_fields[]={SX_FIELD("cell_c","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_cell_c={0x6061006aU,"chemistry_cell_c",sxsch_cell_c_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_alpha_fields[]={SX_FIELD("cell_alpha","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_cell_alpha={0x6061006bU,"chemistry_cell_alpha",sxsch_cell_alpha_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_beta_fields[]={SX_FIELD("cell_beta","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_cell_beta={0x6061006cU,"chemistry_cell_beta",sxsch_cell_beta_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cell_gamma_fields[]={SX_FIELD("cell_gamma","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_cell_gamma={0x6061006dU,"chemistry_cell_gamma",sxsch_cell_gamma_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_shelx_lattice_fields[]={SX_FIELD("shelx_lattice","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_shelx_lattice={0x6061006eU,"chemistry_shelx_lattice",sxsch_shelx_lattice_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_lammps_timestep_fields[]={SX_FIELD("lammps_timestep","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_lammps_timestep={0x6061006fU,"chemistry_lammps_timestep",sxsch_lammps_timestep_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_box_lower_fields[]={SX_FIELD("box_lower","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_box_lower={0x60610070U,"chemistry_box_lower",sxsch_box_lower_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_box_upper_fields[]={SX_FIELD("box_upper","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_box_upper={0x60610071U,"chemistry_box_upper",sxsch_box_upper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_box_tilt_fields[]={SX_FIELD("box_tilt","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_box_tilt={0x60610072U,"chemistry_box_tilt",sxsch_box_tilt_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_boundary_code_fields[]={SX_FIELD("boundary_code","char",0,0,SX_STRING)};
static const sx_layout sxsch_boundary_code={0x60610073U,"chemistry_boundary_code",sxsch_boundary_code_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_column_name_fields[]={SX_FIELD("column_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_column_name={0x60610074U,"chemistry_column_name",sxsch_column_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_move_flag_fields[]={SX_FIELD("move_flag","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_move_flag={0x60610075U,"chemistry_move_flag",sxsch_move_flag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_k_grid_fields[]={SX_FIELD("k_grid","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_k_grid={0x60610076U,"chemistry_k_grid",sxsch_k_grid_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_k_shift_fields[]={SX_FIELD("k_shift","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_k_shift={0x60610077U,"chemistry_k_shift",sxsch_k_shift_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_data_block_fields[]={SX_FIELD("cif_data_block","char",0,0,SX_STRING)};
static const sx_layout sxsch_cif_data_block={0x60610078U,"chemistry_cif_data_block",sxsch_cif_data_block_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_tag_fields[]={SX_FIELD("cif_tag","char",0,0,SX_STRING)};
static const sx_layout sxsch_cif_tag={0x60610079U,"chemistry_cif_tag",sxsch_cif_tag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_group_fields[]={SX_FIELD("cif_group","char",0,0,SX_STRING)};
static const sx_layout sxsch_cif_group={0x6061007aU,"chemistry_cif_group",sxsch_cif_group_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_value_fields[]={SX_FIELD("cif_value","char",0,0,SX_STRING)};
static const sx_layout sxsch_cif_value={0x6061007bU,"chemistry_cif_value",sxsch_cif_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_atom_id_fields[]={SX_FIELD("cif_atom_id","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_cif_atom_id={0x6061007cU,"chemistry_cif_atom_id",sxsch_cif_atom_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_flag_fields[]={SX_FIELD("amber_flag","char",0,0,SX_STRING)};
static const sx_layout sxsch_amber_flag={0x6061007dU,"chemistry_amber_flag",sxsch_amber_flag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_atom_name_fields[]={SX_FIELD("amber_atom_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_amber_atom_name={0x6061007eU,"chemistry_amber_atom_name",sxsch_amber_atom_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_residue_label_fields[]={SX_FIELD("amber_residue_label","char",0,0,SX_STRING)};
static const sx_layout sxsch_amber_residue_label={0x6061007fU,"chemistry_amber_residue_label",sxsch_amber_residue_label_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_atom_type_index_fields[]={SX_FIELD("amber_atom_type_index","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_amber_atom_type_index={0x60610080U,"chemistry_amber_atom_type_index",sxsch_amber_atom_type_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_excluded_count_fields[]={SX_FIELD("amber_excluded_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_excluded_count={0x60610081U,"chemistry_amber_excluded_count",sxsch_amber_excluded_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_residue_pointer_fields[]={SX_FIELD("amber_residue_pointer","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_amber_residue_pointer={0x60610082U,"chemistry_amber_residue_pointer",sxsch_amber_residue_pointer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_charge_fields[]={SX_FIELD("amber_charge","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_amber_charge={0x60610083U,"chemistry_amber_charge",sxsch_amber_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mass_fields[]={SX_FIELD("amber_mass","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_amber_mass={0x60610084U,"chemistry_amber_mass",sxsch_amber_mass_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_integer_fields[]={SX_FIELD("amber_integer","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_amber_integer={0x60610085U,"chemistry_amber_integer",sxsch_amber_integer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_real_fields[]={SX_FIELD("amber_real","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_amber_real={0x60610086U,"chemistry_amber_real",sxsch_amber_real_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_string_fields[]={SX_FIELD("amber_string","char",0,0,SX_STRING)};
static const sx_layout sxsch_amber_string={0x60610087U,"chemistry_amber_string",sxsch_amber_string_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_natom_fields[]={SX_FIELD("amber_natom","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_natom={0x60610088U,"chemistry_amber_natom",sxsch_amber_natom_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ntypes_fields[]={SX_FIELD("amber_ntypes","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_ntypes={0x60610089U,"chemistry_amber_ntypes",sxsch_amber_ntypes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nbonh_fields[]={SX_FIELD("amber_nbonh","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nbonh={0x6061008aU,"chemistry_amber_nbonh",sxsch_amber_nbonh_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mbona_fields[]={SX_FIELD("amber_mbona","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_mbona={0x6061008bU,"chemistry_amber_mbona",sxsch_amber_mbona_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ntheth_fields[]={SX_FIELD("amber_ntheth","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_ntheth={0x6061008cU,"chemistry_amber_ntheth",sxsch_amber_ntheth_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mtheta_fields[]={SX_FIELD("amber_mtheta","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_mtheta={0x6061008dU,"chemistry_amber_mtheta",sxsch_amber_mtheta_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nphih_fields[]={SX_FIELD("amber_nphih","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nphih={0x6061008eU,"chemistry_amber_nphih",sxsch_amber_nphih_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mphia_fields[]={SX_FIELD("amber_mphia","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_mphia={0x6061008fU,"chemistry_amber_mphia",sxsch_amber_mphia_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nhparm_fields[]={SX_FIELD("amber_nhparm","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_amber_nhparm={0x60610090U,"chemistry_amber_nhparm",sxsch_amber_nhparm_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nparm_fields[]={SX_FIELD("amber_nparm","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_amber_nparm={0x60610091U,"chemistry_amber_nparm",sxsch_amber_nparm_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_next_fields[]={SX_FIELD("amber_next","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_next={0x60610092U,"chemistry_amber_next",sxsch_amber_next_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nres_fields[]={SX_FIELD("amber_nres","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nres={0x60610093U,"chemistry_amber_nres",sxsch_amber_nres_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nbona_fields[]={SX_FIELD("amber_nbona","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nbona={0x60610094U,"chemistry_amber_nbona",sxsch_amber_nbona_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ntheta_fields[]={SX_FIELD("amber_ntheta","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_ntheta={0x60610095U,"chemistry_amber_ntheta",sxsch_amber_ntheta_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nphia_fields[]={SX_FIELD("amber_nphia","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nphia={0x60610096U,"chemistry_amber_nphia",sxsch_amber_nphia_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_numbnd_fields[]={SX_FIELD("amber_numbnd","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_numbnd={0x60610097U,"chemistry_amber_numbnd",sxsch_amber_numbnd_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_numang_fields[]={SX_FIELD("amber_numang","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_numang={0x60610098U,"chemistry_amber_numang",sxsch_amber_numang_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nptra_fields[]={SX_FIELD("amber_nptra","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nptra={0x60610099U,"chemistry_amber_nptra",sxsch_amber_nptra_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_natyp_fields[]={SX_FIELD("amber_natyp","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_natyp={0x6061009aU,"chemistry_amber_natyp",sxsch_amber_natyp_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nphb_fields[]={SX_FIELD("amber_nphb","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nphb={0x6061009bU,"chemistry_amber_nphb",sxsch_amber_nphb_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ifpert_fields[]={SX_FIELD("amber_ifpert","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_amber_ifpert={0x6061009cU,"chemistry_amber_ifpert",sxsch_amber_ifpert_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nbper_fields[]={SX_FIELD("amber_nbper","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nbper={0x6061009dU,"chemistry_amber_nbper",sxsch_amber_nbper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ngper_fields[]={SX_FIELD("amber_ngper","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_ngper={0x6061009eU,"chemistry_amber_ngper",sxsch_amber_ngper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ndper_fields[]={SX_FIELD("amber_ndper","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_ndper={0x6061009fU,"chemistry_amber_ndper",sxsch_amber_ndper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mbper_fields[]={SX_FIELD("amber_mbper","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_mbper={0x606100a0U,"chemistry_amber_mbper",sxsch_amber_mbper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mgper_fields[]={SX_FIELD("amber_mgper","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_mgper={0x606100a1U,"chemistry_amber_mgper",sxsch_amber_mgper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mdper_fields[]={SX_FIELD("amber_mdper","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_mdper={0x606100a2U,"chemistry_amber_mdper",sxsch_amber_mdper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ifbox_fields[]={SX_FIELD("amber_ifbox","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_amber_ifbox={0x606100a3U,"chemistry_amber_ifbox",sxsch_amber_ifbox_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nmxrs_fields[]={SX_FIELD("amber_nmxrs","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_nmxrs={0x606100a4U,"chemistry_amber_nmxrs",sxsch_amber_nmxrs_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ifcap_fields[]={SX_FIELD("amber_ifcap","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_amber_ifcap={0x606100a5U,"chemistry_amber_ifcap",sxsch_amber_ifcap_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_numextra_fields[]={SX_FIELD("amber_numextra","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_numextra={0x606100a6U,"chemistry_amber_numextra",sxsch_amber_numextra_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ncopy_fields[]={SX_FIELD("amber_ncopy","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_amber_ncopy={0x606100a7U,"chemistry_amber_ncopy",sxsch_amber_ncopy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_label_fields[]={SX_FIELD("fchk_label","char",0,0,SX_STRING)};
static const sx_layout sxsch_fchk_label={0x606100a8U,"chemistry_fchk_label",sxsch_fchk_label_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_job_fields[]={SX_FIELD("fchk_job","char",0,0,SX_STRING)};
static const sx_layout sxsch_fchk_job={0x606100a9U,"chemistry_fchk_job",sxsch_fchk_job_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_method_fields[]={SX_FIELD("fchk_method","char",0,0,SX_STRING)};
static const sx_layout sxsch_fchk_method={0x606100aaU,"chemistry_fchk_method",sxsch_fchk_method_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_basis_fields[]={SX_FIELD("fchk_basis","char",0,0,SX_STRING)};
static const sx_layout sxsch_fchk_basis={0x606100abU,"chemistry_fchk_basis",sxsch_fchk_basis_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_array_marker_fields[]={SX_FIELD("fchk_array_marker","char",0,0,SX_STRING)};
static const sx_layout sxsch_fchk_array_marker={0x606100acU,"chemistry_fchk_array_marker",sxsch_fchk_array_marker_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_integer_fields[]={SX_FIELD("fchk_integer","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_fchk_integer={0x606100adU,"chemistry_fchk_integer",sxsch_fchk_integer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_real_fields[]={SX_FIELD("fchk_real","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_fchk_real={0x606100aeU,"chemistry_fchk_real",sxsch_fchk_real_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_fchk_coordinate_fields[]={SX_FIELD("fchk_coordinate","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_fchk_coordinate={0x606100afU,"chemistry_fchk_coordinate",sxsch_fchk_coordinate_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_relaxation_constraint_fields[]={SX_FIELD("relaxation_constraint","char",0,0,SX_STRING)};
static const sx_layout sxsch_relaxation_constraint={0x606100b0U,"chemistry_relaxation_constraint",sxsch_relaxation_constraint_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_unpaired_electrons_fields[]={SX_FIELD("unpaired_electrons","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_unpaired_electrons={0x606100b1U,"chemistry_unpaired_electrons",sxsch_unpaired_electrons_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_basis_name_fields[]={SX_FIELD("basis_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_basis_name={0x606100b2U,"chemistry_basis_name",sxsch_basis_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_method_name_fields[]={SX_FIELD("method_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_method_name={0x606100b3U,"chemistry_method_name",sxsch_method_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_calculation_kind_fields[]={SX_FIELD("calculation_kind","char",0,0,SX_STRING)};
static const sx_layout sxsch_calculation_kind={0x606100b4U,"chemistry_calculation_kind",sxsch_calculation_kind_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_iteration_count_fields[]={SX_FIELD("iteration_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_iteration_count={0x606100b5U,"chemistry_iteration_count",sxsch_iteration_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_threshold_fields[]={SX_FIELD("threshold","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_threshold={0x606100b6U,"chemistry_threshold",sxsch_threshold_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_processor_count_fields[]={SX_FIELD("processor_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsch_processor_count={0x606100b7U,"chemistry_processor_count",sxsch_processor_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_memory_amount_fields[]={SX_FIELD("memory_amount","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_memory_amount={0x606100b8U,"chemistry_memory_amount",sxsch_memory_amount_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_memory_mb_fields[]={SX_FIELD("memory_mb","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsch_memory_mb={0x606100b9U,"chemistry_memory_mb",sxsch_memory_mb_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cutoff_ry_fields[]={SX_FIELD("cutoff_ry","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_cutoff_ry={0x606100baU,"chemistry_cutoff_ry",sxsch_cutoff_ry_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cutoff_selected_fields[]={SX_FIELD("cutoff_selected","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_cutoff_selected={0x606100bbU,"chemistry_cutoff_selected",sxsch_cutoff_selected_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_initial_charge_fields[]={SX_FIELD("initial_charge","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_initial_charge={0x606100bcU,"chemistry_initial_charge",sxsch_initial_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_initial_spin_fields[]={SX_FIELD("initial_spin","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_initial_spin={0x606100bdU,"chemistry_initial_spin",sxsch_initial_spin_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_nuclear_charge_fields[]={SX_FIELD("nuclear_charge","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsch_nuclear_charge={0x606100beU,"chemistry_nuclear_charge",sxsch_nuclear_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_symmetry_name_fields[]={SX_FIELD("symmetry_name","char",0,0,SX_STRING)};
static const sx_layout sxsch_symmetry_name={0x606100bfU,"chemistry_symmetry_name",sxsch_symmetry_name_fields,1,SX_LE};
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
/* Native validation gates interpretation; every emitted span is checked again. */
typedef struct sxsch_cursor{sx_context*c;uint8_t*b;int64_t n,p;uint64_t work;}sxsch_cursor;
typedef struct sxsch_token{int64_t a,z;}sxsch_token;
static bool sxsch_space(uint8_t c){return c==' '||c=='\t'||c=='\r'||c=='\n';}
static bool sxsch_eq(sxsch_cursor*q,sxsch_token t,const char*s){size_t n=xx_rt_strlen(s);return t.a>=0&&t.z==(int64_t)n&&t.a<=q->n&&t.z<=q->n-t.a&&!xx_rt_memcmp(q->b+t.a,s,n);}
static bool sxsch_ci(sxsch_cursor*q,sxsch_token t,const char*s){size_t n=xx_rt_strlen(s);if(t.a<0||t.z!=(int64_t)n||t.a>q->n||t.z>q->n-t.a)return false;for(size_t i=0;i<n;i++){unsigned ch=q->b[t.a+i];if(ch>='A'&&ch<='Z')ch+=32;if(ch!=(unsigned char)s[i])return false;}return true;}
static sxsch_token sxsch_trim(sxsch_cursor*q,sxsch_token t){while(t.z&&sxsch_space(q->b[t.a])){t.a++;t.z--;}while(t.z&&sxsch_space(q->b[t.a+t.z-1]))t.z--;return t;}
static bool sxsch_line(sxsch_cursor*q,sxsch_token*t){if(q->p>=q->n||++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;t->a=q->p;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;t->z=q->p-t->a;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;return true;}
static unsigned sxsch_split(sxsch_cursor*q,sxsch_token line,sxsch_token*t,unsigned cap,bool tabs){unsigned n=0;int64_t p=line.a,end=p+line.z;while(p<end){if(tabs){int64_t a=p;while(p<end&&q->b[p]!='\t')p++;if(n==cap)return cap+1;t[n++]=(sxsch_token){a,p-a};if(p<end)p++;}else{while(p<end&&sxsch_space(q->b[p]))p++;if(p==end)break;int64_t a=p;while(p<end&&!sxsch_space(q->b[p]))p++;if(n==cap)return cap+1;t[n++]=(sxsch_token){a,p-a};}}return n;}
static bool sxsch_emit(sxsch_cursor*q,const sx_layout*l,sxsch_token t){if(t.a<0||t.z<0||t.a>q->n||t.z>q->n-t.a||xx_pd_is_stopped(q->c->pd))return false;if(!t.z||q->c->count>=24000)return true;if(t.z>sx_variable_field_limit(l->fields[0].type))return true;return sx_add(q->c,l,t.a,t.z);}
static bool sxsch_number(sxsch_cursor*q,sxsch_token t,uint64_t*v){t=sxsch_trim(q,t);uint64_t n=0;int64_t i=0;if(t.z&&q->b[t.a]=='+')i++;if(i==t.z)return false;for(;i<t.z;i++){unsigned d=q->b[t.a+i]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*v=n;return true;}
static bool sxsch_fields(sxsch_cursor*q,sxsch_token*t,unsigned n,const sx_layout*const*l,unsigned max){if(n>max)return false;for(unsigned i=0;i<n;i++)if(l[i]&&!sxsch_emit(q,l[i],t[i]))return false;return true;}
static bool sxsch_column(sxsch_cursor*q,const sx_layout*l,sxsch_token line,unsigned at,unsigned width){if(at>(uint64_t)line.z||width>(uint64_t)line.z-at)return false;sxsch_token t={line.a+at,width};/* Blank optional numeric columns remain raw. */if(!sxsch_trim(q,t).z)return true;return sxsch_emit(q,l,t);}
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
#define SC_COL(n,o,z) do{if(!sxsch_column(q,&sxsch_##n,line,(o),(z)))return false;}while(0)
static bool sxsch_next(sxsch_cursor*q,sxsch_token*line,sxsch_token*t,unsigned cap,unsigned*n,const char*comments){while(sxsch_line(q,line)){int64_t i=0;for(;i<line->z;i++){if(xx_rt_strchr(comments,q->b[line->a+i])){SC_EMIT(comment,((sxsch_token){line->a+i,line->z-i}));line->z=i;break;}}*line=sxsch_trim(q,*line);if(line->z){*n=sxsch_split(q,*line,t,cap,false);return *n<=cap;}}return false;}
static bool sxsch_xyz(sxsch_cursor*q,sxsch_token*t,unsigned mode){const sx_layout*const rows[][3]={{&sxsch_angstrom_x,&sxsch_angstrom_y,&sxsch_angstrom_z},{&sxsch_bohr_x,&sxsch_bohr_y,&sxsch_bohr_z},{&sxsch_fractional_x,&sxsch_fractional_y,&sxsch_fractional_z},{&sxsch_lattice_angstrom_x,&sxsch_lattice_angstrom_y,&sxsch_lattice_angstrom_z},{&sxsch_lattice_bohr_x,&sxsch_lattice_bohr_y,&sxsch_lattice_bohr_z},{&sxsch_lattice_scaled_x,&sxsch_lattice_scaled_y,&sxsch_lattice_scaled_z},{&sxsch_coordinate_scaled_x,&sxsch_coordinate_scaled_y,&sxsch_coordinate_scaled_z},{&sxsch_lammps_coordinate_x,&sxsch_lammps_coordinate_y,&sxsch_lammps_coordinate_z},{&sxsch_lammps_velocity_x,&sxsch_lammps_velocity_y,&sxsch_lammps_velocity_z},{&sxsch_dlp_velocity_x,&sxsch_dlp_velocity_y,&sxsch_dlp_velocity_z},{&sxsch_dlp_force_x,&sxsch_dlp_force_y,&sxsch_dlp_force_z},{&sxsch_siesta_velocity_x,&sxsch_siesta_velocity_y,&sxsch_siesta_velocity_z},{&sxsch_siesta_cell_velocity_x,&sxsch_siesta_cell_velocity_y,&sxsch_siesta_cell_velocity_z},{&sxsch_xsf_force_x,&sxsch_xsf_force_y,&sxsch_xsf_force_z}};return mode<SX_COUNT(rows)&&sxsch_fields(q,t,3,rows[mode],3);}
static bool sxsch_each(sxsch_cursor*q,sxsch_token*t,unsigned n,const sx_layout*l){for(unsigned i=0;i<n;i++)if(!sxsch_emit(q,l,t[i]))return false;return true;}
static bool sxsch_xsf(sxsch_cursor*q){sxsch_token l,t[8];unsigned n;bool crystal=false;uint64_t count=0;if(!sxsch_next(q,&l,t,8,&n,"#"))return false;SC_EMIT(keyword,t[0]);crystal=sxsch_eq(q,t[0],"CRYSTAL");if(crystal){if(!sxsch_next(q,&l,t,8,&n,"#"))return false;SC_EMIT(keyword,t[0]);for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,8,&n,"")||n!=3||!sxsch_xyz(q,t,3))return false;if(!sxsch_next(q,&l,t,8,&n,"#"))return false;SC_EMIT(keyword,t[0]);if(!sxsch_next(q,&l,t,8,&n,"")||n!=2||!sxsch_number(q,t[0],&count))return false;SC_EMIT(atom_count,t[0]);SC_EMIT(integer_value,t[1]);}uint64_t got=0;while(sxsch_next(q,&l,t,8,&n,"#")){if(q->c->count>=24000)return true;if(n!=4&&n!=7)return false;uint64_t z;if(sxsch_number(q,t[0],&z))SC_EMIT(atomic_number,t[0]);else SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,0)||(n==7&&!sxsch_xyz(q,t+4,13)))return false;got++;}return got&&(!crystal||got==count);}
static bool sxsch_dlp(sxsch_cursor*q){sxsch_token l,t[4];unsigned n;uint64_t level,periodic,atoms;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);if(!sxsch_next(q,&l,t,4,&n,"")||n!=3||!sxsch_number(q,t[0],&level)||level>2||!sxsch_number(q,t[1],&periodic)||!sxsch_number(q,t[2],&atoms))return false;SC_EMIT(dlp_level,t[0]);SC_EMIT(dlp_periodicity,t[1]);SC_EMIT(atom_count,t[2]);if(periodic)for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,4,&n,"")||n!=3||!sxsch_xyz(q,t,3))return false;for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,4,&n,"")||n!=2)return false;SC_EMIT(element,t[0]);SC_EMIT(atom_id,t[1]);for(unsigned k=0;k<=level;k++)if(!sxsch_next(q,&l,t,4,&n,"")||n!=3||!sxsch_xyz(q,t,k==0?0:k==1?9:10))return false;}return true;}
static bool sxsch_charmm(sxsch_cursor*q){sxsch_token l,t[12];unsigned n;uint64_t atoms;if(!sxsch_next(q,&l,t,12,&n,"*"))return false;if(!n||n>2||!sxsch_number(q,t[0],&atoms))return false;SC_EMIT(atom_count,t[0]);if(n==2)SC_EMIT(keyword,t[1]);for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,12,&n,"*")||n!=10)return false;SC_EMIT(atom_id,t[0]);SC_EMIT(residue_index,t[1]);SC_EMIT(residue_name,t[2]);SC_EMIT(atom_name,t[3]);if(!sxsch_xyz(q,t+4,0))return false;SC_EMIT(segment_name,t[7]);SC_EMIT(residue_id,t[8]);SC_EMIT(weight,t[9]);}return true;}
static bool sxsch_siesta(sxsch_cursor*q){sxsch_token l,t[10];unsigned n;uint64_t atoms;for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,10,&n,"#")||n!=6||!sxsch_xyz(q,t,4)||!sxsch_xyz(q,t+3,12))return false;if(!sxsch_next(q,&l,t,10,&n,"#")||n!=1||!sxsch_number(q,t[0],&atoms))return false;SC_EMIT(atom_count,t[0]);for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,10,&n,"#")||n!=8)return false;SC_EMIT(species_index,t[0]);SC_EMIT(atomic_number,t[1]);if(!sxsch_xyz(q,t+2,1)||!sxsch_xyz(q,t+5,11))return false;}return true;}
static bool sxsch_crystal(sxsch_cursor*q){sxsch_token l,t[16];unsigned n;uint64_t atoms,ops;if(!sxsch_next(q,&l,t,16,&n,"#")||(n!=3&&n!=8))return false;SC_EMIT(dimension,t[0]);SC_EMIT(crystal_centering,t[1]);SC_EMIT(crystal_type,t[2]);if(n==8){SC_EMIT(keyword,t[3]);SC_EMIT(energy,t[4]);SC_EMIT(keyword,t[5]);if(t[6].z<2)return false;SC_EMIT(energy_delta,((sxsch_token){t[6].a,t[6].z-1}));SC_EMIT(text_value,t[7]);}for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,16,&n,"#")||n!=3||!sxsch_xyz(q,t,3))return false;if(!sxsch_next(q,&l,t,16,&n,"#")||n!=1||!sxsch_number(q,t[0],&ops)||ops!=1)return false;SC_EMIT(symmetry_count,t[0]);for(unsigned j=0;j<4;j++)if(!sxsch_next(q,&l,t,16,&n,"#")||n!=3||!sxsch_each(q,t,3,&sxsch_symmetry_component))return false;if(!sxsch_next(q,&l,t,16,&n,"#")||n!=1||!sxsch_number(q,t[0],&atoms))return false;SC_EMIT(atom_count,t[0]);for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,16,&n,"#")||n!=4)return false;SC_EMIT(atomic_number,t[0]);if(!sxsch_xyz(q,t+1,0))return false;}return true;}
static bool sxsch_shelx(sxsch_cursor*q){sxsch_token l,t[128];unsigned n;while(sxsch_next(q,&l,t,128,&n,"!")){if(q->c->count>=24000)return true;if(sxsch_eq(q,t[0],"TITL")){SC_EMIT(keyword,t[0]);if(n>1)SC_EMIT(title,((sxsch_token){t[1].a,l.a+l.z-t[1].a}));}else if(sxsch_eq(q,t[0],"CELL")){if(n!=8)return false;SC_EMIT(keyword,t[0]);const sx_layout*cols[]={&sxsch_wavelength,&sxsch_cell_a,&sxsch_cell_b,&sxsch_cell_c,&sxsch_cell_alpha,&sxsch_cell_beta,&sxsch_cell_gamma};if(!sxsch_fields(q,t+1,7,cols,7))return false;}else if(sxsch_eq(q,t[0],"LATT")){if(n!=2)return false;SC_EMIT(keyword,t[0]);SC_EMIT(shelx_lattice,t[1]);}else if(sxsch_eq(q,t[0],"SFAC")){SC_EMIT(keyword,t[0]);if(!sxsch_each(q,t+1,n-1,&sxsch_element))return false;}else if(sxsch_eq(q,t[0],"END")){SC_EMIT(keyword,t[0]);}else{if(n!=6)return false;SC_EMIT(atom_label,t[0]);SC_EMIT(species_index,t[1]);if(!sxsch_xyz(q,t+2,2))return false;SC_EMIT(occupancy,t[5]);}}return true;}
static bool sxsch_castep(sxsch_cursor*q){sxsch_token l,t[12];unsigned n,mode=0;bool lattice=false;while(sxsch_next(q,&l,t,12,&n,"#!")){if(q->c->count>=24000)return true;if(sxsch_ci(q,t[0],"%block")){if(n!=2)return false;SC_EMIT(keyword,t[0]);SC_EMIT(section,t[1]);lattice=sxsch_ci(q,t[1],"lattice_cart");mode=sxsch_ci(q,t[1],"positions_frac")?2:0;}else if(sxsch_ci(q,t[0],"%endblock")){if(n!=2)return false;SC_EMIT(keyword,t[0]);SC_EMIT(section,t[1]);}else if(n==1){SC_EMIT(units,t[0]);mode=sxsch_ci(q,t[0],"bohr")?1:0;}else if(lattice){if(n!=3||!sxsch_xyz(q,t,mode==1?4:3))return false;}else{if(n!=4)return false;SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,mode))return false;}}return true;}
static bool sxsch_vasp(sxsch_cursor*q){sxsch_token l,t[128];unsigned n;uint64_t atoms=0;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);if(!sxsch_next(q,&l,t,128,&n,"#")||n!=1)return false;SC_EMIT(scale,t[0]);for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,128,&n,"#")||n!=3||!sxsch_xyz(q,t,5))return false;if(!sxsch_next(q,&l,t,128,&n,"#")||!sxsch_each(q,t,n,&sxsch_element))return false;if(!sxsch_next(q,&l,t,128,&n,"#"))return false;for(unsigned i=0;i<n;i++){uint64_t v;if(!sxsch_number(q,t[i],&v)||v>100000-atoms)return false;atoms+=v;SC_EMIT(species_count,t[i]);}if(!sxsch_next(q,&l,t,128,&n,"#"))return false;bool selective=sxsch_ci(q,t[0],"selective");if(selective){if(!sxsch_each(q,t,n,&sxsch_keyword)||!sxsch_next(q,&l,t,128,&n,"#"))return false;}if(n!=1)return false;SC_EMIT(coordinate_mode,t[0]);unsigned mode=sxsch_ci(q,t[0],"direct")?2:6;for(uint64_t a=0;a<atoms;a++){if(q->c->count>=24000)return true;if(!sxsch_next(q,&l,t,128,&n,"#")||n!=(selective?6U:3U)||!sxsch_xyz(q,t,mode))return false;if(selective&&!sxsch_each(q,t+3,3,&sxsch_boolean_text))return false;}return true;}
static const sx_layout*sxsch_lammps_col(sxsch_cursor*q,sxsch_token t){if(sxsch_eq(q,t,"id"))return &sxsch_atom_id;if(sxsch_eq(q,t,"type"))return &sxsch_species_index;if(sxsch_eq(q,t,"element"))return &sxsch_element;const char*keys[]={"x","y","z","xu","yu","zu","xs","ys","zs","vx","vy","vz"};const sx_layout*rows[]={&sxsch_lammps_coordinate_x,&sxsch_lammps_coordinate_y,&sxsch_lammps_coordinate_z,&sxsch_lammps_coordinate_x,&sxsch_lammps_coordinate_y,&sxsch_lammps_coordinate_z,&sxsch_fractional_x,&sxsch_fractional_y,&sxsch_fractional_z,&sxsch_lammps_velocity_x,&sxsch_lammps_velocity_y,&sxsch_lammps_velocity_z};for(unsigned i=0;i<SX_COUNT(keys);i++)if(sxsch_eq(q,t,keys[i]))return rows[i];return &sxsch_real_value;}
static bool sxsch_dump(sxsch_cursor*q){sxsch_token l,t[80];const sx_layout*cols[64];unsigned n,ncol=0,phase=0,bounds=0;uint64_t count=0;while(sxsch_next(q,&l,t,80,&n,"#")){if(q->c->count>=24000)return true;if(sxsch_eq(q,t[0],"ITEM:")){if(n<2)return false;SC_EMIT(keyword,t[0]);if(sxsch_eq(q,t[1],"TIMESTEP")){phase=1;SC_EMIT(section,t[1]);}else if(sxsch_eq(q,t[1],"NUMBER")){phase=2;if(!sxsch_each(q,t+1,n-1,&sxsch_keyword))return false;}else if(sxsch_eq(q,t[1],"BOX")){if(n!=6&&n!=9)return false;phase=3;bounds=3;if(!sxsch_each(q,t+1,n-4,&sxsch_keyword)||!sxsch_each(q,t+n-3,3,&sxsch_boundary_code))return false;}else if(sxsch_eq(q,t[1],"ATOMS")){if(n<7||n>66)return false;phase=4;ncol=n-2;SC_EMIT(section,t[1]);for(unsigned i=0;i<ncol;i++){SC_EMIT(column_name,t[i+2]);cols[i]=sxsch_lammps_col(q,t[i+2]);}}else return false;}else if(phase==1){if(n!=1)return false;SC_EMIT(lammps_timestep,t[0]);}else if(phase==2){if(n!=1||!sxsch_number(q,t[0],&count))return false;SC_EMIT(atom_count,t[0]);}else if(phase==3){if(!bounds||(n!=2&&n!=3))return false;bounds--;SC_EMIT(box_lower,t[0]);SC_EMIT(box_upper,t[1]);if(n==3)SC_EMIT(box_tilt,t[2]);}else if(phase==4){if(!count||n!=ncol||!sxsch_fields(q,t,n,cols,ncol))return false;count--;}else return false;}return count==0;}
static bool sxsch_lammps(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,section=0;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);while(sxsch_next(q,&l,t,16,&n,"#")){if(q->c->count>=24000)return true;if(n==1&&(sxsch_eq(q,t[0],"Atoms")||sxsch_eq(q,t[0],"Masses")||sxsch_eq(q,t[0],"Velocities"))){section=sxsch_eq(q,t[0],"Atoms")?1:sxsch_eq(q,t[0],"Masses")?2:3;SC_EMIT(section,t[0]);continue;}if(!section){if(n==2){SC_EMIT(atom_count,t[0]);SC_EMIT(keyword,t[1]);}else if(n==3){SC_EMIT(type_count,t[0]);if(!sxsch_each(q,t+1,2,&sxsch_keyword))return false;}else if(n==4){SC_EMIT(box_lower,t[0]);SC_EMIT(box_upper,t[1]);if(!sxsch_each(q,t+2,2,&sxsch_keyword))return false;}else if(n==6){if(!sxsch_each(q,t,3,&sxsch_box_tilt)||!sxsch_each(q,t+3,3,&sxsch_keyword))return false;}else return false;}else if(section==1){if(n!=5)return false;SC_EMIT(atom_id,t[0]);SC_EMIT(species_index,t[1]);if(!sxsch_xyz(q,t+2,7))return false;}else if(section==2){if(n!=2)return false;SC_EMIT(species_index,t[0]);SC_EMIT(lammps_mass,t[1]);}else{if(n!=4)return false;SC_EMIT(atom_id,t[0]);if(!sxsch_xyz(q,t+1,8))return false;}}return section!=0;}
static bool sxsch_fchk(sxsch_cursor*q){sxsch_token l,t[4];unsigned n;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);if(!sxsch_next(q,&l,t,4,&n,"")||n!=3)return false;SC_EMIT(fchk_job,t[0]);SC_EMIT(fchk_method,t[1]);SC_EMIT(fchk_basis,t[2]);while(sxsch_line(q,&l)){if(q->c->count>=24000)return true;if(l.z<47)return false;sxsch_token key=sxsch_trim(q,(sxsch_token){l.a,40});SC_EMIT(fchk_label,((sxsch_token){l.a,40}));SC_EMIT(value_type,((sxsch_token){l.a+43,1}));bool real=q->b[l.a+43]=='R';n=sxsch_split(q,(sxsch_token){l.a+45,l.z-45},t,4,false);if(n!=1&&n!=2)return false;bool coordinates=sxsch_eq(q,key,"Current cartesian coordinates");const sx_layout*layout=coordinates?&sxsch_fchk_coordinate:real?&sxsch_fchk_real:sxsch_eq(q,key,"Number of atoms")?&sxsch_atom_count:sxsch_eq(q,key,"Atomic numbers")?&sxsch_atomic_number:&sxsch_fchk_integer;if(n==1){if(!sxsch_emit(q,layout,t[0]))return false;}else{uint64_t remaining;if(!sxsch_number(q,t[1],&remaining))return false;SC_EMIT(fchk_array_marker,t[0]);SC_EMIT(value_count,t[1]);unsigned width=real?16:12;while(remaining){if(!sxsch_line(q,&l)||l.z%width)return false;uint64_t got=(uint64_t)l.z/width;if(!got||got>remaining)return false;for(unsigned j=0;j<got;j++)if(!sxsch_column(q,layout,l,j*width,width))return false;remaining-=got;if(q->c->count>=24000)return true;}}}return true;}
static bool sxsch_prmtop(sxsch_cursor*q){sxsch_token l,t[4];unsigned n,width=0,pointer_index=0;bool real=false,chars=false,ptr=false;const sx_layout*layout=&sxsch_amber_string;if(!sxsch_line(q,&l))return false;SC_EMIT(text_value,l);while(sxsch_line(q,&l)){if(q->c->count>=24000)return true;if(l.z&&q->b[l.a]=='%'){n=sxsch_split(q,l,t,4,false);if(n==2&&sxsch_eq(q,t[0],"%FLAG")){SC_EMIT(keyword,t[0]);SC_EMIT(amber_flag,t[1]);sxsch_token name=t[1];if(!sxsch_line(q,&l))return false;SC_EMIT(format_string,l);l=sxsch_trim(q,l);ptr=sxsch_eq(q,name,"POINTERS");pointer_index=0;chars=sxsch_eq(q,l,"%FORMAT(20a4)")||sxsch_eq(q,l,"%FORMAT(20A4)")||sxsch_eq(q,l,"%FORMAT(1a80)")||sxsch_eq(q,l,"%FORMAT(1A80)");real=sxsch_eq(q,l,"%FORMAT(5E16.8)");width=chars?(sxsch_eq(q,l,"%FORMAT(1a80)")||sxsch_eq(q,l,"%FORMAT(1A80)")?80:4):real?16:8;
 layout=sxsch_eq(q,name,"ATOM_NAME")?&sxsch_amber_atom_name:sxsch_eq(q,name,"CHARGE")?&sxsch_amber_charge:sxsch_eq(q,name,"MASS")?&sxsch_amber_mass:sxsch_eq(q,name,"ATOM_TYPE_INDEX")?&sxsch_amber_atom_type_index:sxsch_eq(q,name,"NUMBER_EXCLUDED_ATOMS")?&sxsch_amber_excluded_count:sxsch_eq(q,name,"RESIDUE_LABEL")?&sxsch_amber_residue_label:sxsch_eq(q,name,"RESIDUE_POINTER")?&sxsch_amber_residue_pointer:sxsch_eq(q,name,"ATOMIC_NUMBER")?&sxsch_atomic_number:chars?&sxsch_amber_string:real?&sxsch_amber_real:&sxsch_amber_integer;
 }else SC_EMIT(comment,l);}else{if(!width||l.z%width)return false;for(int64_t o=0;o<l.z;o+=width){const sx_layout*item=layout;if(ptr){const sx_layout*const pointers[]={&sxsch_amber_natom,&sxsch_amber_ntypes,&sxsch_amber_nbonh,&sxsch_amber_mbona,&sxsch_amber_ntheth,&sxsch_amber_mtheta,&sxsch_amber_nphih,&sxsch_amber_mphia,&sxsch_amber_nhparm,&sxsch_amber_nparm,&sxsch_amber_next,&sxsch_amber_nres,&sxsch_amber_nbona,&sxsch_amber_ntheta,&sxsch_amber_nphia,&sxsch_amber_numbnd,&sxsch_amber_numang,&sxsch_amber_nptra,&sxsch_amber_natyp,&sxsch_amber_nphb,&sxsch_amber_ifpert,&sxsch_amber_nbper,&sxsch_amber_ngper,&sxsch_amber_ndper,&sxsch_amber_mbper,&sxsch_amber_mgper,&sxsch_amber_mdper,&sxsch_amber_ifbox,&sxsch_amber_nmxrs,&sxsch_amber_ifcap,&sxsch_amber_numextra,&sxsch_amber_ncopy};if(!sxsch_trim(q,(sxsch_token){l.a+o,width}).z)continue;if(pointer_index>=SX_COUNT(pointers))return false;item=pointers[pointer_index++];}if(!sxsch_column(q,item,l,(unsigned)o,width))return false;}}}return true;}
static bool sxsch_cif_next(sxsch_cursor*q,sxsch_token*t,bool*quoted,bool*have){*have=false;*quoted=false;while(q->p<q->n){if(sxsch_space(q->b[q->p])){q->p++;continue;}if(q->b[q->p]=='#'){int64_t start=q->p;while(q->p<q->n&&q->b[q->p]!='\n')q->p++;SC_EMIT(comment,((sxsch_token){start,q->p-start}));continue;}break;}if(q->p==q->n)return true;if(++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;int64_t begin=q->p;unsigned ch=q->b[q->p];if(ch=='\''||ch=='"'){*quoted=true;begin=++q->p;while(q->p<q->n){if(q->b[q->p]=='\n'||q->b[q->p]=='\r')return false;if(q->b[q->p]==ch&&(q->p+1==q->n||sxsch_space(q->b[q->p+1]))){*t=(sxsch_token){begin,q->p-begin};q->p++;*have=true;return true;}q->p++;}return false;}if(ch==';'&&(!q->p||q->b[q->p-1]=='\n')){*quoted=true;begin=++q->p;while(q->p<q->n){if(q->b[q->p]==';'&&q->b[q->p-1]=='\n'){*t=(sxsch_token){begin,q->p-begin};q->p++;*have=true;return true;}q->p++;}return false;}while(q->p<q->n&&!sxsch_space(q->b[q->p]))q->p++;*t=(sxsch_token){begin,q->p-begin};*have=true;return true;}
static bool sxsch_cif_reserved(sxsch_cursor*q,sxsch_token t,bool quoted){return !quoted&&t.z&&(q->b[t.a]=='_'||sxsch_ci(q,t,"loop_")||sxsch_ci(q,t,"stop_")||sxsch_ci(q,t,"global_")||(t.z>=5&&(sxsch_ci(q,(sxsch_token){t.a,5},"data_")||sxsch_ci(q,(sxsch_token){t.a,5},"save_"))));}
static const sx_layout*sxsch_cif_type(sxsch_cursor*q,sxsch_token t){const char*names[]={"_atom_site.group_pdb","_atom_site.id","_atom_site.type_symbol","_atom_site.label_atom_id","_atom_site.label_comp_id","_atom_site.cartn_x","_atom_site.cartn_y","_atom_site.cartn_z"};const sx_layout*types[]={&sxsch_cif_group,&sxsch_cif_atom_id,&sxsch_element,&sxsch_atom_name,&sxsch_residue_name,&sxsch_angstrom_x,&sxsch_angstrom_y,&sxsch_angstrom_z};for(unsigned i=0;i<SX_COUNT(names);i++)if(sxsch_ci(q,t,names[i]))return types[i];return &sxsch_cif_value;}
static bool sxsch_cif(sxsch_cursor*q){sxsch_token t;bool quoted,have;if(!sxsch_cif_next(q,&t,&quoted,&have)||!have)return false;SC_EMIT(cif_data_block,t);if(!sxsch_cif_next(q,&t,&quoted,&have))return false;while(have){if(q->c->count>=24000)return true;if(!quoted&&sxsch_ci(q,t,"loop_")){SC_EMIT(keyword,t);const sx_layout*cols[128];unsigned n=0;if(!sxsch_cif_next(q,&t,&quoted,&have))return false;while(have&&!quoted&&t.z&&q->b[t.a]=='_'){if(n==128)return false;cols[n++]=sxsch_cif_type(q,t);SC_EMIT(cif_tag,t);if(!sxsch_cif_next(q,&t,&quoted,&have))return false;}if(!n)return false;uint64_t index=0;while(have&&!sxsch_cif_reserved(q,t,quoted)){if(!sxsch_emit(q,cols[index%n],t))return false;index++;if(q->c->count>=24000)return true;if(!sxsch_cif_next(q,&t,&quoted,&have))return false;}if(index%n)return false;}else if(!quoted&&t.z&&q->b[t.a]=='_'){const sx_layout*l=sxsch_cif_type(q,t);SC_EMIT(cif_tag,t);if(!sxsch_cif_next(q,&t,&quoted,&have)||!have||!sxsch_emit(q,l,t)||!sxsch_cif_next(q,&t,&quoted,&have))return false;}else return false;}return true;}
static bool sxsch_assignment(sxsch_cursor*q,sxsch_token row,sxsch_token*key,sxsch_token*value){int64_t p=0;while(p<row.z&&q->b[row.a+p]!='=')p++;if(!p||p==row.z)return false;*key=sxsch_trim(q,(sxsch_token){row.a,p});*value=sxsch_trim(q,(sxsch_token){row.a+p+1,row.z-p-1});if(value->z&&q->b[value->a+value->z-1]==','){value->z--;*value=sxsch_trim(q,*value);}if(value->z>=2&&((q->b[value->a]=='\''&&q->b[value->a+value->z-1]=='\'')||(q->b[value->a]=='"'&&q->b[value->a+value->z-1]=='"'))){value->a++;value->z-=2;}return key->z&&value->z;}
static bool sxsch_option(sxsch_cursor*q,sxsch_token key,sxsch_token value,const sx_layout*layout){SC_EMIT(option_name,key);return sxsch_emit(q,layout,value);}
static bool sxsch_aims(sxsch_cursor*q){sxsch_token l,t[8];unsigned n;while(sxsch_next(q,&l,t,8,&n,"#")){if(q->c->count>=24000)return true;SC_EMIT(keyword,t[0]);if(sxsch_eq(q,t[0],"lattice_vector")){if(n!=4||!sxsch_xyz(q,t+1,3))return false;}else if(sxsch_eq(q,t[0],"atom")||sxsch_eq(q,t[0],"atom_frac")){if(n!=5||!sxsch_xyz(q,t+1,sxsch_eq(q,t[0],"atom")?0:2))return false;SC_EMIT(element,t[4]);}else{if(n!=2)return false;const sx_layout*layout=sxsch_eq(q,t[0],"initial_charge")?&sxsch_initial_charge:sxsch_eq(q,t[0],"initial_moment")?&sxsch_initial_spin:&sxsch_relaxation_constraint;if(!sxsch_emit(q,layout,t[1]))return false;}}return true;}
static bool sxsch_abinit(sxsch_cursor*q){sxsch_token l,t[128];unsigned n;uint64_t atoms=0;while(sxsch_next(q,&l,t,128,&n,"#")){if(q->c->count>=24000)return true;SC_EMIT(keyword,t[0]);if(sxsch_ci(q,t[0],"acell")){if(!sxsch_next(q,&l,t,128,&n,"#")||(n!=3&&n!=4))return false;const sx_layout*cols[]={&sxsch_abinit_cell_scale_x,&sxsch_abinit_cell_scale_y,&sxsch_abinit_cell_scale_z};if(!sxsch_fields(q,t,3,cols,3))return false;if(n==4)SC_EMIT(units,t[3]);}else if(sxsch_ci(q,t[0],"rprim")){const sx_layout*cols[]={&sxsch_abinit_rprim_x,&sxsch_abinit_rprim_y,&sxsch_abinit_rprim_z};for(unsigned j=0;j<3;j++)if(!sxsch_next(q,&l,t,128,&n,"#")||n!=3||!sxsch_fields(q,t,3,cols,3))return false;}else if(sxsch_ci(q,t[0],"typat")){uint64_t count=0;while(count<atoms){if(!sxsch_next(q,&l,t,128,&n,"#")||n>atoms-count||!sxsch_each(q,t,n,&sxsch_species_index))return false;count+=n;if(q->c->count>=24000)return true;}}else if(sxsch_ci(q,t[0],"xcart")){for(uint64_t j=0;j<atoms;j++){if(!sxsch_next(q,&l,t,128,&n,"#")||n!=3||!sxsch_xyz(q,t,1))return false;if(q->c->count>=24000)return true;}}else{if(n<2)return false;const sx_layout*layout=&sxsch_integer_value;if(sxsch_ci(q,t[0],"natom")){if(!sxsch_number(q,t[1],&atoms))return false;layout=&sxsch_atom_count;}else if(sxsch_ci(q,t[0],"ntypat"))layout=&sxsch_type_count;else if(sxsch_ci(q,t[0],"znucl"))layout=&sxsch_atomic_number;else if(sxsch_ci(q,t[0],"ecut"))layout=&sxsch_cutoff_selected;if(!sxsch_each(q,t+1,layout==&sxsch_cutoff_selected?1:n-1,layout))return false;if(layout==&sxsch_cutoff_selected&&n>2)SC_EMIT(units,t[2]);}}return true;}
static bool sxsch_gaussian(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,phase=0;bool route=false;while(sxsch_line(q,&l)){if(q->c->count>=24000)return true;l=sxsch_trim(q,l);if(!l.z){if(phase<2&&route)phase++;continue;}if(phase==0){if(q->b[l.a]=='%'){sxsch_token key,value;if(!sxsch_assignment(q,(sxsch_token){l.a+1,l.z-1},&key,&value))return false;const sx_layout*layout=sxsch_ci(q,key,"nprocshared")?&sxsch_processor_count:sxsch_ci(q,key,"chk")?&sxsch_filename:&sxsch_option_value;if(!sxsch_option(q,key,value,layout))return false;}else{route=true;SC_EMIT(option_value,l);}}else if(phase==1){SC_EMIT(title,l);}else{n=sxsch_split(q,l,t,16,false);if(phase==2){if(n!=2)return false;SC_EMIT(charge,t[0]);SC_EMIT(multiplicity,t[1]);phase=3;}else{if(n!=4)return false;bool lattice=sxsch_ci(q,t[0],"tv");if(lattice)SC_EMIT(keyword,t[0]);else SC_EMIT(element,t[0]);const sx_layout*const coords[]={&sxsch_gaussian_coordinate_x,&sxsch_gaussian_coordinate_y,&sxsch_gaussian_coordinate_z};const sx_layout*const tv[]={&sxsch_gaussian_lattice_x,&sxsch_gaussian_lattice_y,&sxsch_gaussian_lattice_z};if(!sxsch_fields(q,t+1,3,lattice?tv:coords,3))return false;}}}return phase==3;}
static bool sxsch_gamess(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,section=0;while(sxsch_next(q,&l,t,16,&n,"!")){if(q->c->count>=24000)return true;if(q->b[t[0].a]=='$'){SC_EMIT(section,t[0]);if(sxsch_ci(q,t[0],"$data")){section=2;if(!sxsch_line(q,&l))return false;SC_EMIT(title,l);if(!sxsch_next(q,&l,t,16,&n,"!")||n!=1)return false;SC_EMIT(symmetry_name,t[0]);}else if(sxsch_ci(q,t[0],"$end"))section=0;else section=1;}else if(section==2){if(n!=5)return false;SC_EMIT(element,t[0]);SC_EMIT(nuclear_charge,t[1]);if(!sxsch_xyz(q,t+2,0))return false;}else if(section==1){for(unsigned j=0;j<n;j++){sxsch_token key,value;if(!sxsch_assignment(q,t[j],&key,&value))return false;const sx_layout*layout=sxsch_ci(q,key,"mult")?&sxsch_multiplicity:sxsch_ci(q,key,"icharg")?&sxsch_charge:sxsch_ci(q,key,"ngauss")||sxsch_ci(q,key,"ndfunc")||sxsch_ci(q,key,"npfunc")?&sxsch_integer_value:sxsch_ci(q,key,"units")?&sxsch_units:sxsch_ci(q,key,"gbasis")?&sxsch_basis_name:sxsch_ci(q,key,"scftyp")?&sxsch_method_name:sxsch_ci(q,key,"runtyp")?&sxsch_calculation_kind:&sxsch_option_value;if(!sxsch_option(q,key,value,layout))return false;}}else return false;}return true;}
static bool sxsch_orca(sxsch_cursor*q){sxsch_token l,t[64];unsigned n;bool geometry=false;if(!sxsch_next(q,&l,t,64,&n,"#"))return false;SC_EMIT(keyword,t[0]);if(!sxsch_each(q,t+1,n-1,&sxsch_option_value))return false;while(sxsch_next(q,&l,t,64,&n,"#")){if(q->c->count>=24000)return true;if(sxsch_ci(q,t[0],"*xyz")){if(n!=3)return false;SC_EMIT(keyword,t[0]);SC_EMIT(charge,t[1]);SC_EMIT(multiplicity,t[2]);geometry=true;}else if(sxsch_eq(q,t[0],"*")){SC_EMIT(keyword,t[0]);geometry=false;}else if(geometry){if(n!=4)return false;SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,0))return false;}else{SC_EMIT(keyword,t[0]);if(n>1&&!sxsch_each(q,t+1,n-1,sxsch_ci(q,t[0],"%maxcore")?&sxsch_memory_mb:sxsch_ci(q,t[0],"nprocs")?&sxsch_processor_count:&sxsch_option_value))return false;}}return true;}
static bool sxsch_demon(sxsch_cursor*q){sxsch_token l,t[16];unsigned n;bool geometry=false;while(sxsch_next(q,&l,t,16,&n,"#")){if(q->c->count>=24000)return true;if(geometry){if(n!=6)return false;SC_EMIT(atom_label,t[0]);if(!sxsch_xyz(q,t+1,0))return false;SC_EMIT(atomic_number,t[4]);SC_EMIT(mass,t[5]);}else{SC_EMIT(keyword,t[0]);if(sxsch_ci(q,t[0],"geometry")){geometry=true;if(!sxsch_each(q,t+1,n-1,&sxsch_units))return false;}else if(sxsch_ci(q,t[0],"title")){if(n>1)SC_EMIT(title,((sxsch_token){t[1].a,l.a+l.z-t[1].a}));}else if(!sxsch_each(q,t+1,n-1,sxsch_ci(q,t[0],"basis")?&sxsch_basis_name:sxsch_ci(q,t[0],"scftype")?&sxsch_method_name:&sxsch_option_value))return false;}}return geometry;}
static bool sxsch_qchem(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,section=0;bool first=false;while(sxsch_line(q,&l)){if(q->c->count>=24000)return true;l=sxsch_trim(q,l);if(!l.z)continue;if(section==1&&q->b[l.a]!='$'){SC_EMIT(comment,l);continue;}int64_t comment=0;while(comment<l.z&&q->b[l.a+comment]!='#')comment++;if(comment<l.z){SC_EMIT(comment,((sxsch_token){l.a+comment,l.z-comment}));l.z=comment;l=sxsch_trim(q,l);if(!l.z)continue;}n=sxsch_split(q,l,t,16,false);if(!n||n>16)return false;if(q->b[t[0].a]=='$'){SC_EMIT(section,t[0]);section=sxsch_ci(q,t[0],"$comment")?1:sxsch_ci(q,t[0],"$rem")?2:sxsch_ci(q,t[0],"$molecule")?3:0;first=section==3;}else if(section==1)SC_EMIT(comment,l);else if(section==2){if(n!=2)return false;const sx_layout*layout=sxsch_ci(q,t[0],"scf_convergence")||sxsch_ci(q,t[0],"thresh")?&sxsch_convergence_exponent:sxsch_ci(q,t[0],"max_scf_cycles")?&sxsch_iteration_count:sxsch_ci(q,t[0],"method")?&sxsch_method_name:sxsch_ci(q,t[0],"basis")?&sxsch_basis_name:sxsch_ci(q,t[0],"jobtype")?&sxsch_calculation_kind:&sxsch_option_value;if(!sxsch_option(q,t[0],t[1],layout))return false;}else if(section==3){if(first){if(n!=2)return false;SC_EMIT(charge,t[0]);SC_EMIT(multiplicity,t[1]);first=false;}else{if(n!=4)return false;SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,0))return false;}}else return false;}return true;}
static bool sxsch_nwchem(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,mode=0,lattice=0;bool geometry=false,system=false;while(sxsch_next(q,&l,t,16,&n,"#")){if(q->c->count>=24000)return true;if(lattice){if(n!=3||!sxsch_xyz(q,t,3))return false;lattice--;continue;}if(geometry&&n==4&&!sxsch_ci(q,t[0],"system")){SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,mode))return false;continue;}SC_EMIT(keyword,t[0]);if(sxsch_ci(q,t[0],"geometry")){geometry=true;mode=0;for(unsigned i=1;i<n;i++){if(sxsch_ci(q,t[i],"au"))mode=1;SC_EMIT(option_value,t[i]);}}else if(sxsch_ci(q,t[0],"system")){system=true;if(!sxsch_each(q,t+1,n-1,&sxsch_option_value))return false;}else if(sxsch_ci(q,t[0],"lattice_vectors"))lattice=3;else if(sxsch_ci(q,t[0],"end")){if(system)system=false;else geometry=false;}else if(sxsch_ci(q,t[0],"title")){if(n>1)SC_EMIT(title,((sxsch_token){t[1].a,l.a+l.z-t[1].a}));}else if(n>1){const sx_layout*layout=sxsch_ci(q,t[0],"charge")?&sxsch_charge:sxsch_ci(q,t[0],"mult")?&sxsch_multiplicity:sxsch_ci(q,t[0],"nopen")?&sxsch_unpaired_electrons:sxsch_ci(q,t[0],"maxiter")?&sxsch_iteration_count:sxsch_ci(q,t[0],"thresh")?&sxsch_threshold:sxsch_ci(q,t[0],"memory")?&sxsch_memory_amount:sxsch_ci(q,t[0],"start")||sxsch_ci(q,t[0],"permanent_dir")||sxsch_ci(q,t[0],"scratch_dir")?&sxsch_filename:&sxsch_option_value;if(!sxsch_emit(q,layout,t[1]))return false;if(n>2&&!sxsch_each(q,t+2,n-2,sxsch_ci(q,t[0],"memory")?&sxsch_units:&sxsch_option_value))return false;}}return true;}
static bool sxsch_cp2k(sxsch_cursor*q){sxsch_token l,t[16],stack[16];unsigned n,depth=0;while(sxsch_next(q,&l,t,16,&n,"#!")){if(q->c->count>=24000)return true;if(q->b[t[0].a]=='&'){SC_EMIT(section,t[0]);if(sxsch_ci(q,t[0],"&end")){if(!depth)return false;depth--;}else{if(depth==16)return false;stack[depth++]=t[0];}if(n>1&&!sxsch_each(q,t+1,n-1,&sxsch_option_value))return false;}else if(depth&&sxsch_ci(q,stack[depth-1],"&coord")){if(n!=4)return false;SC_EMIT(element,t[0]);if(!sxsch_xyz(q,t+1,0))return false;}else{SC_EMIT(option_name,t[0]);if(sxsch_ci(q,t[0],"abc")){if(n!=4)return false;const sx_layout*cols[]={&sxsch_cell_a,&sxsch_cell_b,&sxsch_cell_c};if(!sxsch_fields(q,t+1,3,cols,3))return false;}else if(n>1){const sx_layout*layout=sxsch_ci(q,t[0],"cutoff")||sxsch_ci(q,t[0],"rel_cutoff")?&sxsch_cutoff_ry:sxsch_ci(q,t[0],"eps_scf")||sxsch_ci(q,t[0],"eps_default")?&sxsch_threshold:sxsch_ci(q,t[0],"alpha_weights")?&sxsch_real_value:sxsch_ci(q,t[0],"basis_set_file_name")||sxsch_ci(q,t[0],"potential_file_name")?&sxsch_filename:sxsch_ci(q,t[0],"method")?&sxsch_method_name:sxsch_ci(q,t[0],"basis_set")?&sxsch_basis_name:&sxsch_option_value;if(!sxsch_each(q,t+1,n-1,layout))return false;}}}return !depth;}
static bool sxsch_qe(sxsch_cursor*q){sxsch_token l,t[16];unsigned n,section=0,mode=0,left=0;bool namelist=false;while(sxsch_next(q,&l,t,16,&n,"!#")){if(q->c->count>=24000)return true;if(q->b[t[0].a]=='&'||sxsch_eq(q,t[0],"/")){namelist=q->b[t[0].a]=='&';SC_EMIT(section,t[0]);continue;}if(namelist){sxsch_token key,value;if(!sxsch_assignment(q,l,&key,&value))return false;const sx_layout*layout=sxsch_ci(q,key,"nat")?&sxsch_atom_count:sxsch_ci(q,key,"ntyp")?&sxsch_type_count:sxsch_ci(q,key,"ibrav")?&sxsch_integer_value:sxsch_ci(q,key,"ecutwfc")||sxsch_ci(q,key,"ecutrho")?&sxsch_cutoff_ry:sxsch_ci(q,key,"tot_charge")?&sxsch_qe_total_charge:sxsch_ci(q,key,"mixing_beta")?&sxsch_mixing_factor:sxsch_ci(q,key,"conv_thr")?&sxsch_threshold:sxsch_ci(q,key,"electron_maxstep")?&sxsch_iteration_count:sxsch_ci(q,key,"calculation")?&sxsch_calculation_kind:&sxsch_option_value;if(!sxsch_option(q,key,value,layout))return false;continue;}if(sxsch_ci(q,t[0],"atomic_species")){section=1;SC_EMIT(section,t[0]);}else if(sxsch_ci(q,t[0],"atomic_positions")){if(n!=2)return false;section=2;mode=sxsch_ci(q,t[1],"bohr")?1:sxsch_ci(q,t[1],"crystal")?2:0;SC_EMIT(section,t[0]);SC_EMIT(units,t[1]);}else if(sxsch_ci(q,t[0],"cell_parameters")){if(n!=2)return false;section=3;left=3;mode=sxsch_ci(q,t[1],"bohr")?4:3;SC_EMIT(section,t[0]);SC_EMIT(units,t[1]);}else if(sxsch_ci(q,t[0],"k_points")){if(n!=2)return false;section=4;left=sxsch_ci(q,t[1],"automatic")?1:0;SC_EMIT(section,t[0]);SC_EMIT(coordinate_mode,t[1]);}else if(section==1){if(n!=3)return false;SC_EMIT(element,t[0]);SC_EMIT(mass,t[1]);SC_EMIT(filename,t[2]);}else if(section==2){if((n!=4&&n!=7)||!sxsch_xyz(q,t+1,mode))return false;SC_EMIT(element,t[0]);if(n==7&&!sxsch_each(q,t+4,3,&sxsch_move_flag))return false;}else if(section==3){if(!left||n!=3||!sxsch_xyz(q,t,mode))return false;left--;}else if(section==4){if(!left||n!=6||!sxsch_each(q,t,3,&sxsch_k_grid)||!sxsch_each(q,t+3,3,&sxsch_k_shift))return false;left--;}else return false;}return true;}
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
case XX_FILE_TYPE_PROTEIN_MMCIF:ok=sxsch_cif(q);break;
case XX_FILE_TYPE_XCRYSDEN_XSF:ok=sxsch_xsf(q);break;
case XX_FILE_TYPE_AMBER_PRMTOP:ok=sxsch_prmtop(q);break;
case XX_FILE_TYPE_GAUSSIAN_FCHK:ok=sxsch_fchk(q);break;
case XX_FILE_TYPE_DL_POLY_CONFIG:ok=sxsch_dlp(q);break;
case XX_FILE_TYPE_LAMMPS_DATA:ok=sxsch_lammps(q);break;
case XX_FILE_TYPE_LAMMPS_DUMP:ok=sxsch_dump(q);break;
case XX_FILE_TYPE_SHELX_RES:ok=sxsch_shelx(q);break;
case XX_FILE_TYPE_CHARMM_CRD:ok=sxsch_charmm(q);break;
case XX_FILE_TYPE_CASTEP_CELL:ok=sxsch_castep(q);break;
case XX_FILE_TYPE_CRYSTAL_FORT34:ok=sxsch_crystal(q);break;
case XX_FILE_TYPE_SIESTA_XV:ok=sxsch_siesta(q);break;
case XX_FILE_TYPE_VASP_POSCAR:ok=sxsch_vasp(q);break;
case XX_FILE_TYPE_QUANTUM_ESPRESSO_INPUT:ok=sxsch_qe(q);break;
case XX_FILE_TYPE_CP2K_INPUT:ok=sxsch_cp2k(q);break;
case XX_FILE_TYPE_NWCHEM_INPUT:ok=sxsch_nwchem(q);break;
case XX_FILE_TYPE_GAMESS_INPUT:ok=sxsch_gamess(q);break;
case XX_FILE_TYPE_GAUSSIAN_INPUT:ok=sxsch_gaussian(q);break;
case XX_FILE_TYPE_ABINIT_INPUT:ok=sxsch_abinit(q);break;
case XX_FILE_TYPE_AIMS_GEOMETRY:ok=sxsch_aims(q);break;
case XX_FILE_TYPE_ORCA_INPUT:ok=sxsch_orca(q);break;
case XX_FILE_TYPE_DEMON_INPUT:ok=sxsch_demon(q);break;
case XX_FILE_TYPE_QCHEM_INPUT:ok=sxsch_qchem(q);break;
default:ok=false;break;}xx_mem_free(b);return ok&&sxsch_finish(c);}
#undef SC_EMIT
#undef SC_COL
