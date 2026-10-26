/* SPDX-License-Identifier: MIT
 * Physical scientific text columns and tokens. Newline/delimiter bytes remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_scienceascii.h"
static const xx_data_struct_field_desc sxsa_record_type_fields[]={SX_FIELD("record_type","char",0,0,SX_STRING)};
const sx_layout sxsa_record_type={0x60510001U,"science_record_type",sxsa_record_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_metadata_key_fields[]={SX_FIELD("metadata_key","char",0,0,SX_STRING)};
static const sx_layout sxsa_metadata_key={0x60510002U,"science_metadata_key",sxsa_metadata_key_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_metadata_value_fields[]={SX_FIELD("metadata_value","utf8",0,0,SX_STRING)};
static const sx_layout sxsa_metadata_value={0x60510003U,"science_metadata_value",sxsa_metadata_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_comment_fields[]={SX_FIELD("comment","utf8",0,0,SX_STRING)};
const sx_layout sxsa_comment={0x60510004U,"science_comment",sxsa_comment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_title_fields[]={SX_FIELD("title","utf8",0,0,SX_STRING)};
const sx_layout sxsa_title={0x60510005U,"science_title",sxsa_title_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sequence_id_fields[]={SX_FIELD("sequence_id","char",0,0,SX_STRING)};
static const sx_layout sxsa_sequence_id={0x60510006U,"science_sequence_id",sxsa_sequence_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_description_fields[]={SX_FIELD("description","utf8",0,0,SX_STRING)};
static const sx_layout sxsa_description={0x60510007U,"science_description",sxsa_description_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sequence_fields[]={SX_FIELD("sequence","char",0,0,SX_STRING)};
const sx_layout sxsa_sequence={0x60510008U,"science_sequence",sxsa_sequence_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_quality_fields[]={SX_FIELD("quality","char",0,0,SX_STRING)};
const sx_layout sxsa_quality={0x60510009U,"science_quality",sxsa_quality_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_separator_fields[]={SX_FIELD("separator","char",0,0,SX_STRING)};
static const sx_layout sxsa_separator={0x6051000aU,"science_separator",sxsa_separator_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_reference_name_fields[]={SX_FIELD("reference_name","char",0,0,SX_STRING)};
static const sx_layout sxsa_reference_name={0x6051000bU,"science_reference_name",sxsa_reference_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_feature_source_fields[]={SX_FIELD("feature_source","char",0,0,SX_STRING)};
static const sx_layout sxsa_feature_source={0x6051000cU,"science_feature_source",sxsa_feature_source_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_feature_type_fields[]={SX_FIELD("feature_type","char",0,0,SX_STRING)};
static const sx_layout sxsa_feature_type={0x6051000dU,"science_feature_type",sxsa_feature_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_strand_fields[]={SX_FIELD("strand","char",0,0,SX_STRING)};
static const sx_layout sxsa_strand={0x6051000eU,"science_strand",sxsa_strand_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_attributes_fields[]={SX_FIELD("attributes","char",0,0,SX_STRING)};
static const sx_layout sxsa_attributes={0x6051000fU,"science_attributes",sxsa_attributes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_identifier_fields[]={SX_FIELD("identifier","char",0,0,SX_STRING)};
static const sx_layout sxsa_identifier={0x60510010U,"science_identifier",sxsa_identifier_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_element_fields[]={SX_FIELD("element","char",0,0,SX_STRING)};
const sx_layout sxsa_element={0x60510011U,"science_element",sxsa_element_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_atom_count_fields[]={SX_FIELD("atom_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_atom_count={0x60510015U,"science_atom_count",sxsa_atom_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_bond_count_fields[]={SX_FIELD("bond_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_bond_count={0x60510016U,"science_bond_count",sxsa_bond_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_feature_count_fields[]={SX_FIELD("feature_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_feature_count={0x60510018U,"science_feature_count",sxsa_feature_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_columns_fields[]={SX_FIELD("grid_columns","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsa_grid_columns={0x6051001dU,"science_grid_columns",sxsa_grid_columns_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_rows_fields[]={SX_FIELD("grid_rows","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsa_grid_rows={0x6051001eU,"science_grid_rows",sxsa_grid_rows_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_position_1_fields[]={SX_FIELD("position_1","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_position_1={0x60510020U,"science_position_1",sxsa_position_1_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_start_1_fields[]={SX_FIELD("start_1","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_start_1={0x60510021U,"science_start_1",sxsa_start_1_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_end_1_fields[]={SX_FIELD("end_1","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_end_1={0x60510022U,"science_end_1",sxsa_end_1_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_start_0_fields[]={SX_FIELD("start_0","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_start_0={0x60510023U,"science_start_0",sxsa_start_0_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_end_0_fields[]={SX_FIELD("end_0","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_end_0={0x60510024U,"science_end_0",sxsa_end_0_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_thick_start_0_fields[]={SX_FIELD("thick_start_0","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_thick_start_0={0x60510025U,"science_thick_start_0",sxsa_thick_start_0_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_thick_end_0_fields[]={SX_FIELD("thick_end_0","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_thick_end_0={0x60510026U,"science_thick_end_0",sxsa_thick_end_0_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_part_number_fields[]={SX_FIELD("part_number","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_part_number={0x60510027U,"science_part_number",sxsa_part_number_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_component_start_1_fields[]={SX_FIELD("component_start_1","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_component_start_1={0x60510028U,"science_component_start_1",sxsa_component_start_1_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_component_end_1_fields[]={SX_FIELD("component_end_1","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_component_end_1={0x60510029U,"science_component_end_1",sxsa_component_end_1_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gap_length_fields[]={SX_FIELD("gap_length","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_gap_length={0x6051002aU,"science_gap_length",sxsa_gap_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_span_fields[]={SX_FIELD("span","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_span={0x6051002bU,"science_span",sxsa_span_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_step_fields[]={SX_FIELD("step","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_step={0x6051002cU,"science_step",sxsa_step_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_block_size_fields[]={SX_FIELD("block_size","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_block_size={0x6051002dU,"science_block_size",sxsa_block_size_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_block_start_fields[]={SX_FIELD("block_start","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_block_start={0x6051002eU,"science_block_start",sxsa_block_start_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_score_fields[]={SX_FIELD("score","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_score={0x6051002fU,"science_score",sxsa_score_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_phase_fields[]={SX_FIELD("phase","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_phase={0x60510031U,"science_phase",sxsa_phase_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_rgb_fields[]={SX_FIELD("rgb","char",0,0,SX_STRING)};
static const sx_layout sxsa_rgb={0x60510032U,"science_rgb",sxsa_rgb_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_gap_type_fields[]={SX_FIELD("gap_type","char",0,0,SX_STRING)};
static const sx_layout sxsa_gap_type={0x60510033U,"science_gap_type",sxsa_gap_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_linkage_fields[]={SX_FIELD("linkage","char",0,0,SX_STRING)};
static const sx_layout sxsa_linkage={0x60510034U,"science_linkage",sxsa_linkage_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_evidence_fields[]={SX_FIELD("evidence","char",0,0,SX_STRING)};
static const sx_layout sxsa_evidence={0x60510035U,"science_evidence",sxsa_evidence_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_orientation_fields[]={SX_FIELD("orientation","char",0,0,SX_STRING)};
static const sx_layout sxsa_orientation={0x60510036U,"science_orientation",sxsa_orientation_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_component_type_fields[]={SX_FIELD("component_type","char",0,0,SX_STRING)};
static const sx_layout sxsa_component_type={0x60510037U,"science_component_type",sxsa_component_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_component_id_fields[]={SX_FIELD("component_id","char",0,0,SX_STRING)};
static const sx_layout sxsa_component_id={0x60510038U,"science_component_id",sxsa_component_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_feature_score_fields[]={SX_FIELD("feature_score","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_feature_score={0x60510039U,"science_feature_score",sxsa_feature_score_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_variant_quality_fields[]={SX_FIELD("variant_quality","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_variant_quality={0x6051003aU,"science_variant_quality",sxsa_variant_quality_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_wiggle_value_fields[]={SX_FIELD("wiggle_value","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_wiggle_value={0x6051003bU,"science_wiggle_value",sxsa_wiggle_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_block_count_fields[]={SX_FIELD("block_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsa_block_count={0x6051003cU,"science_block_count",sxsa_block_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_variant_reference_fields[]={SX_FIELD("variant_reference","char",0,0,SX_STRING)};
static const sx_layout sxsa_variant_reference={0x60510049U,"science_variant_reference",sxsa_variant_reference_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_variant_alternate_fields[]={SX_FIELD("variant_alternate","char",0,0,SX_STRING)};
static const sx_layout sxsa_variant_alternate={0x6051004aU,"science_variant_alternate",sxsa_variant_alternate_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_filter_info_fields[]={SX_FIELD("filter_info","char",0,0,SX_STRING)};
static const sx_layout sxsa_filter_info={0x6051004bU,"science_filter_info",sxsa_filter_info_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_info_field_fields[]={SX_FIELD("info_field","char",0,0,SX_STRING)};
static const sx_layout sxsa_info_field={0x6051004cU,"science_info_field",sxsa_info_field_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_x_origin_fields[]={SX_FIELD("grid_x_origin","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_x_origin={0x605100cbU,"science_grid_x_origin",sxsa_grid_x_origin_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_y_origin_fields[]={SX_FIELD("grid_y_origin","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_y_origin={0x605100ccU,"science_grid_y_origin",sxsa_grid_y_origin_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_cell_size_fields[]={SX_FIELD("grid_cell_size","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_cell_size={0x605100cdU,"science_grid_cell_size",sxsa_grid_cell_size_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_x_spacing_fields[]={SX_FIELD("grid_x_spacing","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_x_spacing={0x605100ceU,"science_grid_x_spacing",sxsa_grid_x_spacing_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_y_spacing_fields[]={SX_FIELD("grid_y_spacing","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_y_spacing={0x605100cfU,"science_grid_y_spacing",sxsa_grid_y_spacing_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_nodata_fields[]={SX_FIELD("grid_nodata","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_nodata={0x605100d0U,"science_grid_nodata",sxsa_grid_nodata_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_min_fields[]={SX_FIELD("grid_min","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_min={0x605100d1U,"science_grid_min",sxsa_grid_min_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_max_fields[]={SX_FIELD("grid_max","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_max={0x605100d2U,"science_grid_max",sxsa_grid_max_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_value_fields[]={SX_FIELD("grid_value","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_value={0x605100d3U,"science_grid_value",sxsa_grid_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_rotation_fields[]={SX_FIELD("grid_rotation","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsa_grid_rotation={0x605100d4U,"science_grid_rotation",sxsa_grid_rotation_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_sense_fields[]={SX_FIELD("grid_sense","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_grid_sense={0x605100d5U,"science_grid_sense",sxsa_grid_sense_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_grid_type_fields[]={SX_FIELD("grid_type","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxsa_grid_type={0x605100d6U,"science_grid_type",sxsa_grid_type_fields,1,SX_LE};
static const sx_layout*const sx_scienceascii_layouts[]={&sxsa_record_type,&sxsa_metadata_key,&sxsa_metadata_value,&sxsa_comment,&sxsa_title,&sxsa_sequence_id,&sxsa_description,&sxsa_sequence,&sxsa_quality,&sxsa_separator,&sxsa_reference_name,&sxsa_feature_source,&sxsa_feature_type,&sxsa_strand,&sxsa_attributes,&sxsa_identifier,&sxsa_element,&sxsa_molecule_type,&sxsa_charge_type,&sxsa_section,&sxsa_atom_count,&sxsa_bond_count,&sxsa_substructure_count,&sxsa_feature_count,&sxsa_set_count,&sxsa_matrix_rows,&sxsa_matrix_columns,&sxsa_matrix_entries,&sxsa_grid_columns,&sxsa_grid_rows,&sxsa_reference_length,&sxsa_position_1,&sxsa_start_1,&sxsa_end_1,&sxsa_start_0,&sxsa_end_0,&sxsa_thick_start_0,&sxsa_thick_end_0,&sxsa_part_number,&sxsa_component_start_1,&sxsa_component_end_1,&sxsa_gap_length,&sxsa_span,&sxsa_step,&sxsa_block_size,&sxsa_block_start,&sxsa_score,&sxsa_mapping_quality,&sxsa_phase,&sxsa_rgb,&sxsa_gap_type,&sxsa_linkage,&sxsa_evidence,&sxsa_orientation,&sxsa_component_type,&sxsa_component_id,&sxsa_feature_score,&sxsa_variant_quality,&sxsa_wiggle_value,&sxsa_block_count,&sxsa_sam_query_name,&sxsa_sam_reference,&sxsa_sam_cigar,&sxsa_sam_mate_reference,&sxsa_sam_tag,&sxsa_sam_tag_type,&sxsa_sam_text_value,&sxsa_sam_hex_value,&sxsa_sam_flag,&sxsa_sam_template_length,&sxsa_sam_integer_value,&sxsa_sam_real_value,&sxsa_variant_reference,&sxsa_variant_alternate,&sxsa_filter_info,&sxsa_info_field,&sxsa_matrix_row,&sxsa_matrix_column,&sxsa_matrix_object,&sxsa_matrix_storage,&sxsa_matrix_field,&sxsa_matrix_symmetry,&sxsa_matrix_integer,&sxsa_matrix_real,&sxsa_matrix_imaginary,&sxsa_pdb_atom_name,&sxsa_pdb_altloc,&sxsa_pdb_residue,&sxsa_pdb_chain,&sxsa_pdb_icode,&sxsa_pdb_element,&sxsa_pdb_charge,&sxsa_pdb_serial,&sxsa_pdb_residue_sequence,&sxsa_pdb_x,&sxsa_pdb_y,&sxsa_pdb_z,&sxsa_pdb_occupancy,&sxsa_pdb_temperature,&sxsa_pdb_u11,&sxsa_pdb_u22,&sxsa_pdb_u33,&sxsa_pdb_u12,&sxsa_pdb_u13,&sxsa_pdb_u23,&sxsa_gro_residue_name,&sxsa_gro_atom_name,&sxsa_gro_residue_number,&sxsa_gro_atom_number,&sxsa_gro_x,&sxsa_gro_y,&sxsa_gro_z,&sxsa_gro_vx,&sxsa_gro_vy,&sxsa_gro_vz,&sxsa_gro_box_xx,&sxsa_gro_box_yy,&sxsa_gro_box_zz,&sxsa_gro_box_xy,&sxsa_gro_box_xz,&sxsa_gro_box_yx,&sxsa_gro_box_yz,&sxsa_gro_box_zx,&sxsa_gro_box_zy,&sxsa_xyz_x,&sxsa_xyz_y,&sxsa_xyz_z,&sxsa_mol_program,&sxsa_mol_comment,&sxsa_mol_version,&sxsa_mol_atom_list_count,&sxsa_mol_obsolete_count,&sxsa_mol_chiral_flag,&sxsa_mol_stext_count,&sxsa_mol_obsolete_18,&sxsa_mol_obsolete_21,&sxsa_mol_obsolete_24,&sxsa_mol_obsolete_27,&sxsa_mol_property_count,&sxsa_mol_x,&sxsa_mol_y,&sxsa_mol_z,&sxsa_mol_mass_difference,&sxsa_mol_charge_code,&sxsa_mol_stereo_parity,&sxsa_mol_hydrogen_count,&sxsa_mol_stereo_care,&sxsa_mol_valence,&sxsa_mol_h0_designator,&sxsa_mol_unused_1,&sxsa_mol_unused_2,&sxsa_mol_mapping_number,&sxsa_mol_inversion,&sxsa_mol_exact_change,&sxsa_mol_bond_atom_1,&sxsa_mol_bond_atom_2,&sxsa_mol_bond_type,&sxsa_mol_bond_stereo,&sxsa_mol_bond_unused,&sxsa_mol_bond_topology,&sxsa_mol_bond_reaction,&sxsa_mol_property,&sxsa_mol_property_atom,&sxsa_mol_property_value,&sxsa_mol2_atom_id,&sxsa_mol2_substructure_id,&sxsa_mol2_bond_id,&sxsa_mol2_bond_origin,&sxsa_mol2_bond_target,&sxsa_mol2_root_atom,&sxsa_mol2_dictionary_type,&sxsa_mol2_inter_bonds,&sxsa_mol2_atom_name,&sxsa_mol2_atom_type,&sxsa_mol2_substructure_name,&sxsa_mol2_bond_type,&sxsa_mol2_substructure_type,&sxsa_mol2_chain,&sxsa_mol2_substructure_subtype,&sxsa_mol2_status,&sxsa_mol2_x,&sxsa_mol2_y,&sxsa_mol2_z,&sxsa_mol2_charge,&sxsa_cube_origin_x,&sxsa_cube_origin_y,&sxsa_cube_origin_z,&sxsa_cube_vector_x,&sxsa_cube_vector_y,&sxsa_cube_vector_z,&sxsa_cube_atom_x,&sxsa_cube_atom_y,&sxsa_cube_atom_z,&sxsa_cube_axis_count,&sxsa_atomic_number,&sxsa_cube_nuclear_charge,&sxsa_cube_value,&sxsa_amber_time,&sxsa_amber_coordinate,&sxsa_amber_velocity,&sxsa_amber_box_length,&sxsa_amber_box_angle,&sxsa_grid_x_origin,&sxsa_grid_y_origin,&sxsa_grid_cell_size,&sxsa_grid_x_spacing,&sxsa_grid_y_spacing,&sxsa_grid_nodata,&sxsa_grid_min,&sxsa_grid_max,&sxsa_grid_value,&sxsa_grid_rotation,&sxsa_grid_sense,&sxsa_grid_type,&sxsa_turbomole_units,&sxsa_turbomole_bohr_x,&sxsa_turbomole_bohr_y,&sxsa_turbomole_bohr_z,&sxsa_turbomole_angstrom_x,&sxsa_turbomole_angstrom_y,&sxsa_turbomole_angstrom_z};
static bool sx_scienceascii_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;if(id<0x60510001U||id>=0x60510001U+SX_COUNT(sx_scienceascii_layouts))return true;if(!r->name)return true;switch(id){
case 0x60510015U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60510016U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60510017U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60510018U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x60510019U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x6051001aU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x6051001bU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x6051001cU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x6051001dU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x6051001eU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of entries.");
case 0x6051001fU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Reference sequence length in bases.");
case 0x60510020U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"1-based biological sequence coordinate; SAM zero means unavailable. Not a file offset.");
case 0x60510021U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"1-based biological sequence coordinate; not a file offset.");
case 0x60510022U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"1-based biological sequence coordinate; not a file offset.");
case 0x60510023U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"0-based biological sequence coordinate; end is exclusive. Not a file offset.");
case 0x60510024U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"0-based biological sequence coordinate; end is exclusive. Not a file offset.");
case 0x60510025U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"0-based biological sequence coordinate; end is exclusive. Not a file offset.");
case 0x60510026U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"0-based biological sequence coordinate; end is exclusive. Not a file offset.");
case 0x60510027U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"1-based assembly part or component coordinate; not a byte offset.");
case 0x60510028U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"1-based assembly part or component coordinate; not a byte offset.");
case 0x60510029U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"1-based assembly part or component coordinate; not a byte offset.");
case 0x6051002aU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Length or step in bases; not a file byte size.");
case 0x6051002bU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Length or step in bases; not a file byte size.");
case 0x6051002cU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Length or step in bases; not a file byte size.");
case 0x6051002dU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Length or step in bases; not a file byte size.");
case 0x6051002eU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"0-based block start relative to chromStart, in bases.");
case 0x6051002fU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Format-defined numeric score, mapping quality or coding phase.");
case 0x60510030U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Format-defined numeric score, mapping quality or coding phase.");
case 0x60510031U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Format-defined numeric score, mapping quality or coding phase.");
case 0x6051003cU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of blocks.");
case 0x60510045U:{if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;uint64_t v=xx_var_get_u64(&r->value);wchar_t text[512];size_t used=0;text[0]=0;static const wchar_t*names[]={L"PAIRED",L"PROPER_PAIR",L"UNMAPPED",L"MATE_UNMAPPED",L"REVERSE",L"MATE_REVERSE",L"READ1",L"READ2",L"SECONDARY",L"QCFAIL",L"DUPLICATE",L"SUPPLEMENTARY"};for(unsigned i=0;i<12;i++)if(v&(UINT64_C(1)<<i)){if(used)text[used++]=124;size_t n=xx_rt_wcslen(names[i]);xx_rt_memcpy(text+used,names[i],n*sizeof(*text));used+=n;text[used]=0;}return used?xx_data_struct_record_set_comment(r,text):true;}
case 0x60510046U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Signed observed template length in bases.");
case 0x60510047U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"SAM integer or integer-array element.");
case 0x6051004dU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"1-based matrix index; not a byte offset.");
case 0x6051004eU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"1-based matrix index; not a byte offset.");
case 0x6051005dU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"PDB atom serial or residue sequence number.");
case 0x6051005eU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"PDB atom serial or residue sequence number.");
case 0x6051005fU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x60510060U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x60510061U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x60510062U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Occupancy fraction.");
case 0x60510063U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Isotropic temperature factor in square angstroms.");
case 0x60510064U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Anisotropic displacement tensor component in units of 1e-4 square angstroms.");
case 0x60510065U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Anisotropic displacement tensor component in units of 1e-4 square angstroms.");
case 0x60510066U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Anisotropic displacement tensor component in units of 1e-4 square angstroms.");
case 0x60510067U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Anisotropic displacement tensor component in units of 1e-4 square angstroms.");
case 0x60510068U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Anisotropic displacement tensor component in units of 1e-4 square angstroms.");
case 0x60510069U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Anisotropic displacement tensor component in units of 1e-4 square angstroms.");
case 0x6051006cU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO decimal identifier, modulo 100000.");
case 0x6051006dU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO decimal identifier, modulo 100000.");
case 0x6051006eU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Coordinate in nanometres.");
case 0x6051006fU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Coordinate in nanometres.");
case 0x60510070U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Coordinate in nanometres.");
case 0x60510071U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Velocity in nanometres per picosecond.");
case 0x60510072U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Velocity in nanometres per picosecond.");
case 0x60510073U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Velocity in nanometres per picosecond.");
case 0x60510074U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x60510075U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x60510076U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x60510077U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x60510078U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x60510079U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x6051007aU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x6051007bU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x6051007cU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GRO box vector component in nanometres; physical order v1(x), v2(y), v3(z), v1(y), v1(z), v2(x), v2(z), v3(x), v3(y).");
case 0x6051007dU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x6051007eU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x6051007fU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x60510083U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x60510084U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x60510085U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x60510086U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x60510087U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x60510088U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x60510089U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x6051008aU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x6051008bU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 counts-line field; legacy/obsolete slots retain their physical decimal value.");
case 0x6051008cU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Molfile coordinate in angstroms.");
case 0x6051008dU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Molfile coordinate in angstroms.");
case 0x6051008eU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Molfile coordinate in angstroms.");
case 0x6051008fU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Difference from the natural isotope mass number.");
case 0x60510090U:{if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;switch(xx_var_get_i64(&r->value)){case 0:return xx_data_struct_record_set_comment(r,L"UNCHARGED_OR_DEFAULT");case 1:return xx_data_struct_record_set_comment(r,L"PLUS_3");case 2:return xx_data_struct_record_set_comment(r,L"PLUS_2");case 3:return xx_data_struct_record_set_comment(r,L"PLUS_1");case 4:return xx_data_struct_record_set_comment(r,L"DOUBLET_RADICAL");case 5:return xx_data_struct_record_set_comment(r,L"MINUS_1");case 6:return xx_data_struct_record_set_comment(r,L"MINUS_2");case 7:return xx_data_struct_record_set_comment(r,L"MINUS_3");default:return true;}}
case 0x60510091U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x60510092U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x60510093U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x60510094U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x60510095U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x60510096U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x60510097U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x60510098U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x60510099U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x6051009aU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 atom-block decimal field; codes retain wire representation.");
case 0x6051009bU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 bond field; atom references are 1-based indices.");
case 0x6051009cU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 bond field; atom references are 1-based indices.");
case 0x6051009dU:{if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;switch(xx_var_get_i64(&r->value)){case 1:return xx_data_struct_record_set_comment(r,L"SINGLE");case 2:return xx_data_struct_record_set_comment(r,L"DOUBLE");case 3:return xx_data_struct_record_set_comment(r,L"TRIPLE");case 4:return xx_data_struct_record_set_comment(r,L"AROMATIC");default:return true;}}
case 0x6051009eU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 bond field; atom references are 1-based indices.");
case 0x6051009fU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 bond field; atom references are 1-based indices.");
case 0x605100a0U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 bond field; atom references are 1-based indices.");
case 0x605100a1U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"V2000 bond field; atom references are 1-based indices.");
case 0x605100a3U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Property atom index or signed property value; interpretation follows CHG/ISO/RAD.");
case 0x605100a4U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Property atom index or signed property value; interpretation follows CHG/ISO/RAD.");
case 0x605100a5U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 decimal identifier/index/count; atom references are 1-based.");
case 0x605100a6U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 decimal identifier/index/count; atom references are 1-based.");
case 0x605100a7U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 decimal identifier/index/count; atom references are 1-based.");
case 0x605100a8U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 decimal identifier/index/count; atom references are 1-based.");
case 0x605100a9U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 decimal identifier/index/count; atom references are 1-based.");
case 0x605100aaU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 decimal identifier/index/count; atom references are 1-based.");
case 0x605100abU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 decimal identifier/index/count; atom references are 1-based.");
case 0x605100acU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 decimal identifier/index/count; atom references are 1-based.");
case 0x605100b5U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 Cartesian coordinate in angstroms.");
case 0x605100b6U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 Cartesian coordinate in angstroms.");
case 0x605100b7U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"MOL2 Cartesian coordinate in angstroms.");
case 0x605100b8U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Atomic partial charge in elementary-charge units.");
case 0x605100b9U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100baU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100bbU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100bcU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100bdU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100beU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100bfU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100c0U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100c1U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Positive-count Gaussian Cube native subset: coordinates and grid-vector components in bohr.");
case 0x605100c2U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Number of grid points on this axis.");
case 0x605100c3U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Atomic number.");
case 0x605100c4U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Nuclear charge.");
case 0x605100c5U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Scalar grid value; units depend on the generating program.");
case 0x605100c6U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Simulation time in picoseconds, not wall-clock time.");
case 0x605100c7U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"AMBER restart Cartesian coordinate in angstroms.");
case 0x605100c8U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"AMBER restart stored velocity; multiply by 20.455 for angstroms per picosecond.");
case 0x605100c9U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Periodic cell length in angstroms.");
case 0x605100caU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Periodic cell angle in degrees.");
case 0x605100cbU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100ccU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100cdU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100ceU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100cfU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100d0U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100d1U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100d2U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100d3U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid coordinate, spacing or scalar in the dataset coordinate/value units; not a file offset.");
case 0x605100d4U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Grid rotation in degrees counter-clockwise from the X axis.");
case 0x605100d5U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"GXF traversal sense code.");
case 0x605100d6U:{if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;switch(xx_var_get_i64(&r->value)){case 0:return xx_data_struct_record_set_comment(r,L"UNCOMPRESSED");default:return true;}}
case 0x605100d7U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"angs selects angstroms; absence selects atomic units (bohr).");
case 0x605100d8U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in bohr.");
case 0x605100d9U:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in bohr.");
case 0x605100daU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in bohr.");
case 0x605100dbU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x605100dcU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
case 0x605100ddU:return xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES?true:xx_data_struct_record_set_comment(r,L"Cartesian coordinate in angstroms.");
default:return true;}}
bool sxsa_space(uint8_t c){return c==' '||c=='\t'||c=='\r'||c=='\n';}
bool sxsa_eq(sxsa_cursor*q,sxsa_token t,const char*s){size_t n=xx_rt_strlen(s);return t.a>=0&&t.z==(int64_t)n&&t.a<=q->n&&t.z<=q->n-t.a&&!xx_rt_memcmp(q->b+t.a,s,n);}
static bool sxsa_ci(sxsa_cursor*q,sxsa_token t,const char*s){size_t n=xx_rt_strlen(s);if(t.a<0||t.z!=(int64_t)n||t.a>q->n||t.z>q->n-t.a)return false;for(size_t i=0;i<n;i++){unsigned ch=q->b[t.a+i];if(ch>='A'&&ch<='Z')ch+=32;if(ch!=(unsigned char)s[i])return false;}return true;}
sxsa_token sxsa_trim(sxsa_cursor*q,sxsa_token t){while(t.z&&sxsa_space(q->b[t.a])){t.a++;t.z--;}while(t.z&&sxsa_space(q->b[t.a+t.z-1]))t.z--;return t;}
bool sxsa_line(sxsa_cursor*q,sxsa_token*t){if(q->p>=q->n||++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;t->a=q->p;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;t->z=q->p-t->a;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;return true;}
unsigned sxsa_split(sxsa_cursor*q,sxsa_token line,sxsa_token*t,unsigned cap,bool tabs){unsigned n=0;int64_t p=line.a,end=p+line.z;while(p<end){if(tabs){int64_t a=p;while(p<end&&q->b[p]!='\t')p++;if(n==cap)return cap+1;t[n++]=(sxsa_token){a,p-a};if(p<end)p++;}else{while(p<end&&sxsa_space(q->b[p]))p++;if(p==end)break;int64_t a=p;while(p<end&&!sxsa_space(q->b[p]))p++;if(n==cap)return cap+1;t[n++]=(sxsa_token){a,p-a};}}return n;}
bool sxsa_emit(sxsa_cursor*q,const sx_layout*l,sxsa_token t){if(t.a<0||t.z<0||t.a>q->n||t.z>q->n-t.a||xx_pd_is_stopped(q->c->pd))return false;if(!t.z||q->c->count>=24000)return true;if(t.z>sx_variable_field_limit(l->fields[0].type))return true;return sx_add(q->c,l,t.a,t.z);}
bool sxsa_number(sxsa_cursor*q,sxsa_token t,uint64_t*v){t=sxsa_trim(q,t);uint64_t n=0;int64_t i=0;if(t.z&&q->b[t.a]=='+')i++;if(i==t.z)return false;for(;i<t.z;i++){unsigned d=q->b[t.a+i]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*v=n;return true;}
bool sxsa_fields(sxsa_cursor*q,sxsa_token*t,unsigned n,const sx_layout*const*l,unsigned max){if(n>max)return false;for(unsigned i=0;i<n;i++)if(l[i]&&!sxsa_emit(q,l[i],t[i]))return false;return true;}
bool sxsa_column(sxsa_cursor*q,const sx_layout*l,sxsa_token line,unsigned at,unsigned width){if(at>(uint64_t)line.z||width>(uint64_t)line.z-at)return false;sxsa_token t={line.a+at,width};/* Blank optional numeric columns remain raw. */if(!sxsa_trim(q,t).z)return true;return sxsa_emit(q,l,t);}
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
bool sxsa_sequence_file(sxsa_cursor*q,bool fastq){sxsa_token l,t[2];unsigned phase=0;while(sxsa_line(q,&l)){if(q->c->count>=24000)return true;if(!l.z)return false;if((fastq&&phase==0)||(!fastq&&q->b[l.a]=='>')){SA_EMIT(record_type,((sxsa_token){l.a,1}));int64_t p=l.a+1,end=l.a+l.z;while(p<end&&!sxsa_space(q->b[p]))p++;SA_EMIT(sequence_id,((sxsa_token){l.a+1,p-l.a-1}));while(p<end&&sxsa_space(q->b[p]))p++;if(p<end)SA_EMIT(description,((sxsa_token){p,end-p}));}else if(fastq&&phase==2){SA_EMIT(separator,((sxsa_token){l.a,1}));if(l.z>1)SA_EMIT(description,((sxsa_token){l.a+1,l.z-1}));}else if(fastq&&phase==3){SA_EMIT(quality,l);}else SA_EMIT(sequence,l);if(fastq)phase=(phase+1)%4;}(void)t;return !fastq||phase==0;}
static bool sxsa_metadata(sxsa_cursor*q,sxsa_token l){int64_t p=l.a,end=p+l.z;while(p<end&&q->b[p]!='='&&q->b[p]!='\t'&&q->b[p]!=' ')p++;SA_EMIT(metadata_key,((sxsa_token){l.a,p-l.a}));while(p<end&&(q->b[p]=='='||sxsa_space(q->b[p])))p++;if(p<end)SA_EMIT(metadata_value,((sxsa_token){p,end-p}));return true;}
bool sxsa_csv(sxsa_cursor*q,sxsa_token t,const sx_layout*l){int64_t p=t.a,end=p+t.z;while(p<end){int64_t a=p;while(p<end&&q->b[p]!=',')p++;if(p>a&&!sxsa_emit(q,l,(sxsa_token){a,p-a}))return false;if(p<end)p++;}return true;}
bool sxsa_genomic_table(sxsa_cursor*q,xx_file_type_t type){sxsa_token line,t[16];bool wigfixed=false;const sx_layout*gff[]={&sxsa_reference_name,&sxsa_feature_source,&sxsa_feature_type,&sxsa_start_1,&sxsa_end_1,&sxsa_feature_score,&sxsa_strand,&sxsa_phase,&sxsa_attributes};const sx_layout*vcf[]={&sxsa_reference_name,&sxsa_position_1,&sxsa_identifier,&sxsa_variant_reference,&sxsa_variant_alternate,&sxsa_variant_quality,&sxsa_filter_info,&sxsa_info_field};const sx_layout*bed[]={&sxsa_reference_name,&sxsa_start_0,&sxsa_end_0,&sxsa_identifier,&sxsa_score,&sxsa_strand,&sxsa_thick_start_0,&sxsa_thick_end_0,&sxsa_rgb,&sxsa_block_count};const sx_layout*agp[]={&sxsa_identifier,&sxsa_start_1,&sxsa_end_1,&sxsa_part_number,&sxsa_component_type};while(sxsa_line(q,&line)){if(q->c->count>=24000)return true;line=sxsa_trim(q,line);if(!line.z)continue;if(q->b[line.a]=='#'){if(!sxsa_metadata(q,line))return false;continue;}unsigned n=sxsa_split(q,line,t,16,type!=XX_FILE_TYPE_GENOMICS_WIGGLE);if(!n||n>16)return false;if(sxsa_eq(q,t[0],"track")||sxsa_eq(q,t[0],"browser")||((line.z>=5)&&sxsa_eq(q,(sxsa_token){line.a,5},"track"))){if(!sxsa_metadata(q,line))return false;continue;}
 if(type==XX_FILE_TYPE_GENOMICS_WIGGLE){if(sxsa_eq(q,t[0],"fixedStep")||sxsa_eq(q,t[0],"variableStep")){wigfixed=sxsa_eq(q,t[0],"fixedStep");SA_EMIT(record_type,t[0]);for(unsigned i=1;i<n;i++){int64_t z=0;while(z<t[i].z&&q->b[t[i].a+z]!='=')z++;if(z==t[i].z)return false;sxsa_token k={t[i].a,z},v={t[i].a+z+1,t[i].z-z-1};const sx_layout*l=sxsa_eq(q,k,"chrom")?&sxsa_reference_name:sxsa_eq(q,k,"start")?&sxsa_start_1:sxsa_eq(q,k,"step")?&sxsa_step:sxsa_eq(q,k,"span")?&sxsa_span:NULL;if(!l||!sxsa_emit(q,l,v))return false;}}else{if(n!=(wigfixed?1U:2U))return false;if(!wigfixed)SA_EMIT(position_1,t[0]);SA_EMIT(wiggle_value,t[n-1]);}}
 else if(type==XX_FILE_TYPE_GENOMICS_BED){if(n<3||n>12||!sxsa_fields(q,t,n<10?n:10,bed,10))return false;if(n>10&&!sxsa_csv(q,t[10],&sxsa_block_size))return false;if(n>11&&!sxsa_csv(q,t[11],&sxsa_block_start))return false;}
 else if(type==XX_FILE_TYPE_GENOMICS_AGP){if(n!=9||!sxsa_fields(q,t,5,agp,5))return false;bool gap=sxsa_eq(q,t[4],"N")||sxsa_eq(q,t[4],"U");const sx_layout*tail[]={gap?&sxsa_gap_length:&sxsa_component_id,gap?&sxsa_gap_type:&sxsa_component_start_1,gap?&sxsa_linkage:&sxsa_component_end_1,gap?&sxsa_evidence:&sxsa_orientation};if(!sxsa_fields(q,t+5,4,tail,4))return false;}
 else {bool v=type==XX_FILE_TYPE_GENOMICS_VCF;if(n!=(v?8U:9U))return false;for(unsigned i=0;i<n;i++){const sx_layout*l=v?vcf[i]:gff[i];if(sxsa_eq(q,t[i],".")&&(i==5||(!v&&i==7)))l=&sxsa_metadata_value;if(!sxsa_emit(q,l,t[i]))return false;}}
 }return true;}
bool sxsa_grid(sxsa_cursor*q,bool gxf){sxsa_token line,t[32],key={0,0};bool data=false,pending=false;unsigned headers=0;while(sxsa_line(q,&line)){if(q->c->count>=24000)return true;line=sxsa_trim(q,line);if(!line.z){if(gxf&&pending)pending=false;continue;}unsigned n=sxsa_split(q,line,t,32,false);if(gxf){if(q->b[line.a]=='#'&&!pending){key=(sxsa_token){t[0].a+1,t[0].z-1};SA_EMIT(metadata_key,key);if(sxsa_ci(q,key,"grid"))data=true;pending=!data;continue;}if(!data){pending=false;const sx_layout*l=sxsa_ci(q,key,"points")||sxsa_ci(q,key,"poin")?&sxsa_grid_columns:sxsa_ci(q,key,"rows")?&sxsa_grid_rows:sxsa_ci(q,key,"ptseparation")||sxsa_ci(q,key,"ptse")?&sxsa_grid_x_spacing:sxsa_ci(q,key,"rwseparation")||sxsa_ci(q,key,"rwse")?&sxsa_grid_y_spacing:sxsa_ci(q,key,"xorigin")||sxsa_ci(q,key,"xori")?&sxsa_grid_x_origin:sxsa_ci(q,key,"yorigin")||sxsa_ci(q,key,"yori")?&sxsa_grid_y_origin:sxsa_ci(q,key,"sense")||sxsa_ci(q,key,"sens")?&sxsa_grid_sense:sxsa_ci(q,key,"gtype")?&sxsa_grid_type:sxsa_ci(q,key,"zmin")?&sxsa_grid_min:sxsa_ci(q,key,"zmax")?&sxsa_grid_max:sxsa_ci(q,key,"rotation")||sxsa_ci(q,key,"rota")?&sxsa_grid_rotation:sxsa_ci(q,key,"title")||sxsa_ci(q,key,"titl")?&sxsa_title:&sxsa_grid_nodata;if(!sxsa_emit(q,l,line))return false;continue;}}
 else if(headers<5||(n&&sxsa_ci(q,t[0],"nodata_value"))){if(n!=2)return false;SA_EMIT(metadata_key,t[0]);const sx_layout*l=headers==0?&sxsa_grid_columns:headers==1?&sxsa_grid_rows:headers==2?&sxsa_grid_x_origin:headers==3?&sxsa_grid_y_origin:headers==4?&sxsa_grid_cell_size:&sxsa_grid_nodata;if(!sxsa_emit(q,l,t[1]))return false;headers++;continue;}
 int64_t p=line.a,end=p+line.z;while(p<end){while(p<end&&sxsa_space(q->b[p]))p++;int64_t a=p;while(p<end&&!sxsa_space(q->b[p]))p++;if(p>a)SA_EMIT(grid_value,((sxsa_token){a,p-a}));}}
 return true;}
static int sxsa_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxsa_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsa_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsa_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_scienceascii_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_GENOMICS_FASTA:case XX_FILE_TYPE_GENOMICS_FASTQ:case XX_FILE_TYPE_GENOMICS_SAM:case XX_FILE_TYPE_GENOMICS_VCF:case XX_FILE_TYPE_GENOMICS_GFF3:case XX_FILE_TYPE_GENOMICS_BED:case XX_FILE_TYPE_GENOMICS_WIGGLE:case XX_FILE_TYPE_GENOMICS_GTF:case XX_FILE_TYPE_GENOMICS_AGP:case XX_FILE_TYPE_PROTEIN_PDB:case XX_FILE_TYPE_GROMACS_GRO:case XX_FILE_TYPE_MOLECULE_XYZ:case XX_FILE_TYPE_MDL_MOLFILE:case XX_FILE_TYPE_TRIPOS_MOL2:case XX_FILE_TYPE_GAUSSIAN_CUBE:case XX_FILE_TYPE_AMBER_RESTART:case XX_FILE_TYPE_MATRIX_MARKET:case XX_FILE_TYPE_ESRI_ASCII_GRID:case XX_FILE_TYPE_GXF_GRID:case XX_FILE_TYPE_TURBOMOLE_COORD:return true;default:return false;}}
static bool sx_scienceascii_build(sx_context*c){if(!c||!c->f||c->size<1||c->size>67108864||xx_pd_is_stopped(c->pd))return false;if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxsa_cursor cursor={c,b,c->size,0,0},*q=&cursor;xx_file_type_t type=c->f->file_type;if(ok)switch(type){
case XX_FILE_TYPE_GENOMICS_FASTA:ok=sx_genomics_fasta_build(q);break;
case XX_FILE_TYPE_GENOMICS_FASTQ:ok=sx_genomics_fastq_build(q);break;
case XX_FILE_TYPE_GENOMICS_SAM:ok=sx_genomics_sam_build(q);break;
case XX_FILE_TYPE_GENOMICS_VCF:ok=sx_genomics_vcf_build(q,type);break;
case XX_FILE_TYPE_GENOMICS_GFF3:ok=sx_genomics_gff3_build(q,type);break;
case XX_FILE_TYPE_GENOMICS_BED:ok=sx_genomics_bed_build(q,type);break;
case XX_FILE_TYPE_GENOMICS_WIGGLE:ok=sx_genomics_wiggle_build(q,type);break;
case XX_FILE_TYPE_GENOMICS_GTF:ok=sx_genomics_gtf_build(q,type);break;
case XX_FILE_TYPE_GENOMICS_AGP:ok=sx_genomics_agp_build(q,type);break;
case XX_FILE_TYPE_PROTEIN_PDB:ok=sx_protein_pdb_build(q);break;
case XX_FILE_TYPE_GROMACS_GRO:ok=sx_gromacs_gro_build(q);break;
case XX_FILE_TYPE_MOLECULE_XYZ:ok=sx_molecule_xyz_build(q);break;
case XX_FILE_TYPE_MDL_MOLFILE:ok=sx_mdl_molfile_build(q);break;
case XX_FILE_TYPE_TRIPOS_MOL2:ok=sx_tripos_mol2_build(q);break;
case XX_FILE_TYPE_GAUSSIAN_CUBE:ok=sx_gaussian_cube_build(q);break;
case XX_FILE_TYPE_AMBER_RESTART:ok=sx_amber_restart_build(q);break;
case XX_FILE_TYPE_MATRIX_MARKET:ok=sx_matrix_market_build(q);break;
case XX_FILE_TYPE_ESRI_ASCII_GRID:ok=sx_esri_ascii_grid_build(q);break;
case XX_FILE_TYPE_GXF_GRID:ok=sx_gxf_grid_build(q);break;
case XX_FILE_TYPE_TURBOMOLE_COORD:ok=sx_turbomole_coord_build(q);break;
default:ok=false;break;}xx_mem_free(b);return ok&&sxsa_finish(c);}
#undef SA_EMIT
const sx_family sx_scienceascii_family={sx_scienceascii_supports,sx_scienceascii_build,sx_scienceascii_layouts,SX_COUNT(sx_scienceascii_layouts),sx_scienceascii_comment};
