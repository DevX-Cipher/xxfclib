/* SPDX-License-Identifier: MIT
 * Native-supported scientific mesh/measurement metadata. Unsupported bytes remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_sciencemesh.h"
static const xx_data_struct_field_desc sxsm_signature_fields[]={SX_FIELD("signature","char",0,0,SX_STRING)};
const sx_layout sxsm_signature={0x60630001U,"mesh_signature",sxsm_signature_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_keyword_fields[]={SX_FIELD("keyword","char",0,0,SX_STRING)};
const sx_layout sxsm_keyword={0x60630002U,"mesh_keyword",sxsm_keyword_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_section_fields[]={SX_FIELD("section","char",0,0,SX_STRING)};
const sx_layout sxsm_section={0x60630003U,"mesh_section",sxsm_section_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_key_fields[]={SX_FIELD("key","char",0,0,SX_STRING)};
const sx_layout sxsm_key={0x60630004U,"mesh_key",sxsm_key_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_option_value_fields[]={SX_FIELD("option_value","char",0,0,SX_STRING)};
const sx_layout sxsm_option_value={0x60630005U,"mesh_option_value",sxsm_option_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_title_fields[]={SX_FIELD("title","utf8",0,0,SX_STRING)};
const sx_layout sxsm_title={0x60630006U,"mesh_title",sxsm_title_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_comment_fields[]={SX_FIELD("comment","utf8",0,0,SX_STRING)};
const sx_layout sxsm_comment={0x60630007U,"mesh_comment",sxsm_comment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_name_fields[]={SX_FIELD("name","utf8",0,0,SX_STRING)};
const sx_layout sxsm_name={0x60630008U,"mesh_name",sxsm_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_text_value_fields[]={SX_FIELD("text_value","utf8",0,0,SX_STRING)};
const sx_layout sxsm_text_value={0x60630009U,"mesh_text_value",sxsm_text_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_type_name_fields[]={SX_FIELD("type_name","char",0,0,SX_STRING)};
const sx_layout sxsm_type_name={0x6063000aU,"mesh_type_name",sxsm_type_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_encoding_fields[]={SX_FIELD("encoding","char",0,0,SX_STRING)};
const sx_layout sxsm_encoding={0x6063000bU,"mesh_encoding",sxsm_encoding_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_endian_fields[]={SX_FIELD("endian","char",0,0,SX_STRING)};
const sx_layout sxsm_endian={0x6063000cU,"mesh_endian",sxsm_endian_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_units_fields[]={SX_FIELD("units","char",0,0,SX_STRING)};
const sx_layout sxsm_units={0x6063000dU,"mesh_units",sxsm_units_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_boolean_text_fields[]={SX_FIELD("boolean_text","char",0,0,SX_STRING)};
static const sx_layout sxsm_boolean_text={0x60630010U,"mesh_boolean_text",sxsm_boolean_text_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_dimension_fields[]={SX_FIELD("dimension","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_dimension={0x60630011U,"mesh_dimension",sxsm_dimension_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_axis_count_fields[]={SX_FIELD("axis_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_axis_count={0x60630012U,"mesh_axis_count",sxsm_axis_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_node_count_fields[]={SX_FIELD("node_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_node_count={0x60630013U,"mesh_node_count",sxsm_node_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_element_count_fields[]={SX_FIELD("element_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_element_count={0x60630014U,"mesh_element_count",sxsm_element_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_value_count_fields[]={SX_FIELD("value_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_value_count={0x60630015U,"mesh_value_count",sxsm_value_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_component_count_fields[]={SX_FIELD("component_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_component_count={0x60630016U,"mesh_component_count",sxsm_component_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_node_id_fields[]={SX_FIELD("node_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_node_id={0x60630019U,"mesh_node_id",sxsm_node_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_element_id_fields[]={SX_FIELD("element_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_element_id={0x6063001aU,"mesh_element_id",sxsm_element_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_node_index_fields[]={SX_FIELD("node_index","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_node_index={0x6063001bU,"mesh_node_index",sxsm_node_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_property_id_fields[]={SX_FIELD("property_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_property_id={0x6063001cU,"mesh_property_id",sxsm_property_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_entity_id_fields[]={SX_FIELD("entity_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_entity_id={0x6063001eU,"mesh_entity_id",sxsm_entity_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_integer_value_fields[]={SX_FIELD("integer_value","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_integer_value={0x60630020U,"mesh_integer_value",sxsm_integer_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_real_value_fields[]={SX_FIELD("real_value","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_real_value={0x60630021U,"mesh_real_value",sxsm_real_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_coordinate_x_fields[]={SX_FIELD("coordinate_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_coordinate_x={0x60630022U,"mesh_coordinate_x",sxsm_coordinate_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_coordinate_y_fields[]={SX_FIELD("coordinate_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_coordinate_y={0x60630023U,"mesh_coordinate_y",sxsm_coordinate_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_coordinate_z_fields[]={SX_FIELD("coordinate_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_coordinate_z={0x60630024U,"mesh_coordinate_z",sxsm_coordinate_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_origin_x_fields[]={SX_FIELD("origin_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_origin_x={0x60630025U,"mesh_origin_x",sxsm_origin_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_origin_y_fields[]={SX_FIELD("origin_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_origin_y={0x60630026U,"mesh_origin_y",sxsm_origin_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_origin_z_fields[]={SX_FIELD("origin_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_origin_z={0x60630027U,"mesh_origin_z",sxsm_origin_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spacing_x_fields[]={SX_FIELD("spacing_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_spacing_x={0x60630028U,"mesh_spacing_x",sxsm_spacing_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spacing_y_fields[]={SX_FIELD("spacing_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_spacing_y={0x60630029U,"mesh_spacing_y",sxsm_spacing_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spacing_z_fields[]={SX_FIELD("spacing_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_spacing_z={0x6063002aU,"mesh_spacing_z",sxsm_spacing_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_delta_x_fields[]={SX_FIELD("delta_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_delta_x={0x6063002bU,"mesh_delta_x",sxsm_delta_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_delta_y_fields[]={SX_FIELD("delta_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_delta_y={0x6063002cU,"mesh_delta_y",sxsm_delta_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_delta_z_fields[]={SX_FIELD("delta_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_delta_z={0x6063002dU,"mesh_delta_z",sxsm_delta_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_min_x_fields[]={SX_FIELD("box_min_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_box_min_x={0x6063002eU,"mesh_box_min_x",sxsm_box_min_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_min_y_fields[]={SX_FIELD("box_min_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_box_min_y={0x6063002fU,"mesh_box_min_y",sxsm_box_min_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_max_x_fields[]={SX_FIELD("box_max_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_box_max_x={0x60630031U,"mesh_box_max_x",sxsm_box_max_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_max_y_fields[]={SX_FIELD("box_max_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_box_max_y={0x60630032U,"mesh_box_max_y",sxsm_box_max_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_scalar_value_fields[]={SX_FIELD("scalar_value","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_scalar_value={0x60630036U,"mesh_scalar_value",sxsm_scalar_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_attribute_value_fields[]={SX_FIELD("attribute_value","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_attribute_value={0x60630037U,"mesh_attribute_value",sxsm_attribute_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_sample_bytes_fields[]={SX_FIELD("sample_bytes","ascii_signed",0,0,SX_SIZE)};
const sx_layout sxsm_sample_bytes={0x60630038U,"mesh_sample_bytes",sxsm_sample_bytes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_header_bytes_fields[]={SX_FIELD("header_bytes","ascii_signed",0,0,SX_SIZE)};
static const sx_layout sxsm_header_bytes={0x60630039U,"mesh_header_bytes",sxsm_header_bytes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_sample_bits_fields[]={SX_FIELD("sample_bits","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_sample_bits={0x6063003aU,"mesh_sample_bits",sxsm_sample_bits_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_node_label_fields[]={SX_FIELD("node_label","utf8",0,0,SX_STRING)};
static const sx_layout sxsm_node_label={0x60630048U,"mesh_node_label",sxsm_node_label_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_tree_name_fields[]={SX_FIELD("tree_name","char",0,0,SX_STRING)};
static const sx_layout sxsm_tree_name={0x60630049U,"mesh_tree_name",sxsm_tree_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_taxon_count_fields[]={SX_FIELD("taxon_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxsm_taxon_count={0x6063004aU,"mesh_taxon_count",sxsm_taxon_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_branch_length_fields[]={SX_FIELD("branch_length","ascii_real",0,0,SX_NONE)};
static const sx_layout sxsm_branch_length={0x6063004bU,"mesh_branch_length",sxsm_branch_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_step_index_fields[]={SX_FIELD("step_index","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_step_index={0x60630063U,"mesh_step_index",sxsm_step_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_simulation_time_fields[]={SX_FIELD("simulation_time","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_simulation_time={0x60630064U,"mesh_simulation_time",sxsm_simulation_time_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_boundary_id_fields[]={SX_FIELD("boundary_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_boundary_id={0x60630067U,"mesh_boundary_id",sxsm_boundary_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_red_fields[]={SX_FIELD("red","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_red={0x60630070U,"mesh_red",sxsm_red_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_green_fields[]={SX_FIELD("green","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_green={0x60630071U,"mesh_green",sxsm_green_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_blue_fields[]={SX_FIELD("blue","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_blue={0x60630072U,"mesh_blue",sxsm_blue_fields,1,SX_LE};
static const sx_layout*const sx_sciencemesh_layouts[]={&sxsm_signature,&sxsm_keyword,&sxsm_section,&sxsm_key,&sxsm_option_value,&sxsm_title,&sxsm_comment,&sxsm_name,&sxsm_text_value,&sxsm_type_name,&sxsm_encoding,&sxsm_endian,&sxsm_units,&sxsm_filename,&sxsm_format_string,&sxsm_boolean_text,&sxsm_dimension,&sxsm_axis_count,&sxsm_node_count,&sxsm_element_count,&sxsm_value_count,&sxsm_component_count,&sxsm_tag_count,&sxsm_attribute_count,&sxsm_node_id,&sxsm_element_id,&sxsm_node_index,&sxsm_property_id,&sxsm_region_id,&sxsm_entity_id,&sxsm_label_id,&sxsm_integer_value,&sxsm_real_value,&sxsm_coordinate_x,&sxsm_coordinate_y,&sxsm_coordinate_z,&sxsm_origin_x,&sxsm_origin_y,&sxsm_origin_z,&sxsm_spacing_x,&sxsm_spacing_y,&sxsm_spacing_z,&sxsm_delta_x,&sxsm_delta_y,&sxsm_delta_z,&sxsm_box_min_x,&sxsm_box_min_y,&sxsm_box_min_z,&sxsm_box_max_x,&sxsm_box_max_y,&sxsm_box_max_z,&sxsm_scalar_min,&sxsm_scalar_max,&sxsm_scalar_value,&sxsm_attribute_value,&sxsm_sample_bytes,&sxsm_header_bytes,&sxsm_sample_bits,&sxsm_significant_bits,&sxsm_ics_parameter_count,&sxsm_byte_order_index,&sxsm_parameter_origin,&sxsm_parameter_scale,&sxsm_x_increment,&sxsm_x_zero,&sxsm_point_offset,&sxsm_y_multiplier,&sxsm_y_zero,&sxsm_y_offset,&sxsm_length_digits,&sxsm_payload_bytes,&sxsm_node_label,&sxsm_tree_name,&sxsm_taxon_count,&sxsm_branch_length,&sxsm_jcamp_version,&sxsm_first_x,&sxsm_last_x,&sxsm_x_factor,&sxsm_y_factor,&sxsm_spectral_x,&sxsm_spectral_y,&sxsm_hb_total_lines,&sxsm_hb_pointer_lines,&sxsm_hb_index_lines,&sxsm_hb_value_lines,&sxsm_hb_rhs_lines,&sxsm_matrix_rows,&sxsm_matrix_columns,&sxsm_nonzero_count,&sxsm_elemental_values,&sxsm_column_pointer,&sxsm_row_index,&sxsm_matrix_key,&sxsm_matrix_type,&sxsm_mesh_version,&sxsm_element_type,&sxsm_tag_value,&sxsm_step_index,&sxsm_simulation_time,&sxsm_boundary_marker,&sxsm_surface_id,&sxsm_boundary_id,&sxsm_inside_domain,&sxsm_outside_domain,&sxsm_edge_region,&sxsm_edge_triangle,&sxsm_edge_surface,&sxsm_edge_id,&sxsm_edge_distance,&sxsm_geometry_type,&sxsm_red,&sxsm_green,&sxsm_blue,&sxsm_alpha,&sxsm_axis_name,&sxsm_axis_unit,&sxsm_z_direction,&sxsm_topology_name,&sxsm_variable_name,&sxsm_material_name,&sxsm_surface_face,&sxsm_material_id,&sxsm_coordinate_system,&sxsm_displacement_coordinate_system,&sxsm_permanent_constraints,&sxsm_superelement_id,&sxsm_nastran_x,&sxsm_nastran_y,&sxsm_nastran_z,&sxsm_bar_orientation_x,&sxsm_bar_orientation_y,&sxsm_bar_orientation_z,&sxsm_binary_count,&sxsm_binary_arity,&sxsm_binary_node_index,&sxsm_binary_material_id,&sxsm_binary_flag_value,&sxsm_binary_cycle,&sxsm_binary_location,&sxsm_binary_scalar,&sxsm_binary_coordinate,&sxsm_binary_velocity,&sxsm_binary_time,&sxsm_binary_name};
static bool sx_sciencemesh_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;if(id<0x60630001U||id>=0x60630001U+SX_COUNT(sx_sciencemesh_layouts))return true;if(!r->name||xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;switch(id){
case 0x60630011U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630012U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630013U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630014U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630015U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630016U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630017U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630018U:return xx_data_struct_record_set_comment(r,L"Number of declared dimensions or entries.");
case 0x60630019U:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001aU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001bU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001cU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001dU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001eU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x6063001fU:return xx_data_struct_record_set_comment(r,L"Physical integer identifier or connectivity index, not a file offset.");
case 0x60630020U:return xx_data_struct_record_set_comment(r,L"Format-defined physical integer; interpretation follows the preceding key.");
case 0x60630021U:return xx_data_struct_record_set_comment(r,L"Format-defined physical real; values remain stored without transformation.");
case 0x60630022U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630023U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630024U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630025U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630026U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630027U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630028U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630029U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002aU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002bU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002cU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002dU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002eU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x6063002fU:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630030U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630031U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630032U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630033U:return xx_data_struct_record_set_comment(r,L"Dataset coordinate-system units; no unit conversion or implied byte offset.");
case 0x60630034U:return xx_data_struct_record_set_comment(r,L"Stored scalar value in the dataset-defined units.");
case 0x60630035U:return xx_data_struct_record_set_comment(r,L"Stored scalar value in the dataset-defined units.");
case 0x60630036U:return xx_data_struct_record_set_comment(r,L"Stored scalar value in the dataset-defined units.");
case 0x60630037U:return xx_data_struct_record_set_comment(r,L"Stored scalar value in the dataset-defined units.");
case 0x60630038U:return xx_data_struct_record_set_comment(r,L"Stored length in bytes.");
case 0x60630039U:return xx_data_struct_record_set_comment(r,L"Stored length in bytes.");
case 0x6063003aU:return xx_data_struct_record_set_comment(r,L"Number of bits per sample; not a byte size.");
case 0x6063003bU:return xx_data_struct_record_set_comment(r,L"Number of bits per sample; not a byte size.");
case 0x6063003cU:return xx_data_struct_record_set_comment(r,L"ICS layout parameters including the initial bits axis.");
case 0x6063003dU:return xx_data_struct_record_set_comment(r,L"One-based byte position defining the stored byte permutation.");
case 0x6063003eU:return xx_data_struct_record_set_comment(r,L"ICS per-axis origin or scale in its corresponding parameter units.");
case 0x6063003fU:return xx_data_struct_record_set_comment(r,L"ICS per-axis origin or scale in its corresponding parameter units.");
case 0x60630040U:return xx_data_struct_record_set_comment(r,L"ISF horizontal scale/origin in declared X units.");
case 0x60630041U:return xx_data_struct_record_set_comment(r,L"ISF horizontal scale/origin in declared X units.");
case 0x60630042U:return xx_data_struct_record_set_comment(r,L"ISF sample-position offset, not a file byte offset.");
case 0x60630043U:return xx_data_struct_record_set_comment(r,L"ISF vertical calibration in declared Y units.");
case 0x60630044U:return xx_data_struct_record_set_comment(r,L"ISF vertical calibration in declared Y units.");
case 0x60630045U:return xx_data_struct_record_set_comment(r,L"ISF stored sample-value offset, not a file byte offset.");
case 0x60630046U:return xx_data_struct_record_set_comment(r,L"Number of decimal digits in the following IEEE488.2 byte count.");
case 0x60630047U:return xx_data_struct_record_set_comment(r,L"Physical following binary payload length in bytes.");
case 0x60630048U:return xx_data_struct_record_set_comment(r,L"Original Newick label, with quote/escape spelling retained.");
case 0x60630049U:return xx_data_struct_record_set_comment(r,L"Original Nexus tree identifier; no label decoding or renaming.");
case 0x6063004aU:return xx_data_struct_record_set_comment(r,L"Declared number of taxa.");
case 0x6063004bU:return xx_data_struct_record_set_comment(r,L"Stored phylogenetic branch length; units belong to the dataset.");
case 0x6063004cU:return xx_data_struct_record_set_comment(r,L"JCAMP-DX numeric format version.");
case 0x6063004dU:return xx_data_struct_record_set_comment(r,L"Spectral endpoint after applying XFACTOR, in XUNITS.");
case 0x6063004eU:return xx_data_struct_record_set_comment(r,L"Spectral endpoint after applying XFACTOR, in XUNITS.");
case 0x6063004fU:return xx_data_struct_record_set_comment(r,L"JCAMP multiplicative factor; original data values are not rescaled.");
case 0x60630050U:return xx_data_struct_record_set_comment(r,L"JCAMP multiplicative factor; original data values are not rescaled.");
case 0x60630051U:return xx_data_struct_record_set_comment(r,L"Stored abscissa; multiply by XFACTOR for XUNITS.");
case 0x60630052U:return xx_data_struct_record_set_comment(r,L"Stored ordinate; multiply by YFACTOR for YUNITS.");
case 0x60630053U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630054U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630055U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630056U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630057U:return xx_data_struct_record_set_comment(r,L"Harwell-Boeing physical data line count.");
case 0x60630058U:return xx_data_struct_record_set_comment(r,L"Matrix dimension/value count.");
case 0x60630059U:return xx_data_struct_record_set_comment(r,L"Matrix dimension/value count.");
case 0x6063005aU:return xx_data_struct_record_set_comment(r,L"Matrix dimension/value count.");
case 0x6063005bU:return xx_data_struct_record_set_comment(r,L"Matrix dimension/value count.");
case 0x6063005cU:return xx_data_struct_record_set_comment(r,L"One-based index into the matrix index/value arrays; not a file offset.");
case 0x6063005dU:return xx_data_struct_record_set_comment(r,L"One-based matrix row index; not a file offset.");
case 0x60630060U:return xx_data_struct_record_set_comment(r,L"Mesh format version number.");
case 0x60630061U:{static const wchar_t*names[]={L"Gmsh unknown",L"Gmsh line2",L"Gmsh triangle3",L"Gmsh quadrangle4",L"Gmsh tetrahedron4",L"Gmsh hexahedron8",L"Gmsh prism6",L"Gmsh pyramid5",L"Gmsh line3",L"Gmsh triangle6",L"Gmsh quadrangle9",L"Gmsh tetrahedron10",L"Gmsh hexahedron27",L"Gmsh prism18",L"Gmsh pyramid14",L"Gmsh point1",L"Gmsh quadrangle8",L"Gmsh hexahedron20",L"Gmsh prism15",L"Gmsh pyramid13",L"Gmsh triangle9 incomplete",L"Gmsh triangle10",L"Gmsh triangle12 incomplete",L"Gmsh triangle15",L"Gmsh triangle15 incomplete",L"Gmsh triangle21",L"Gmsh line4",L"Gmsh line5",L"Gmsh line6",L"Gmsh tetrahedron20",L"Gmsh tetrahedron35",L"Gmsh tetrahedron56"};if(xx_var_get_type(&r->value)!=XX_VAR_TYPE_INT64)return true;int64_t v=xx_var_get_i64(&r->value);return v>0&&(uint64_t)v<SX_COUNT(names)?xx_data_struct_record_set_comment(r,names[v]):true;}
case 0x60630062U:return xx_data_struct_record_set_comment(r,L"Gmsh integer tag; meaning depends on tag position.");
case 0x60630063U:return xx_data_struct_record_set_comment(r,L"Simulation step index; not a wall-clock timestamp.");
case 0x60630064U:return xx_data_struct_record_set_comment(r,L"Stored simulation time in model-defined units, not a wall-clock timestamp.");
case 0x60630065U:return xx_data_struct_record_set_comment(r,L"TetGen boundary marker or mesh boundary/reference label.");
case 0x60630066U:return xx_data_struct_record_set_comment(r,L"Netgen physical surface/domain identifier.");
case 0x60630067U:return xx_data_struct_record_set_comment(r,L"Netgen physical surface/domain identifier.");
case 0x60630068U:return xx_data_struct_record_set_comment(r,L"Netgen physical surface/domain identifier.");
case 0x60630069U:return xx_data_struct_record_set_comment(r,L"Netgen physical surface/domain identifier.");
case 0x6063006aU:return xx_data_struct_record_set_comment(r,L"Netgen stored edge-region, geometry triangle, surface or edge identifier.");
case 0x6063006bU:return xx_data_struct_record_set_comment(r,L"Netgen stored edge-region, geometry triangle, surface or edge identifier.");
case 0x6063006cU:return xx_data_struct_record_set_comment(r,L"Netgen stored edge-region, geometry triangle, surface or edge identifier.");
case 0x6063006dU:return xx_data_struct_record_set_comment(r,L"Netgen stored edge-region, geometry triangle, surface or edge identifier.");
case 0x6063006eU:return xx_data_struct_record_set_comment(r,L"Netgen stored geometric edge parameter/distance; not a file offset or necessarily Euclidean length.");
case 0x6063006fU:return xx_data_struct_record_set_comment(r,L"Netgen geometry implementation code.");
case 0x60630070U:return xx_data_struct_record_set_comment(r,L"Normalized color component in0..1.");
case 0x60630071U:return xx_data_struct_record_set_comment(r,L"Normalized color component in0..1.");
case 0x60630072U:return xx_data_struct_record_set_comment(r,L"Normalized color component in0..1.");
case 0x60630073U:return xx_data_struct_record_set_comment(r,L"Normalized color component in0..1.");
case 0x6063007bU:return xx_data_struct_record_set_comment(r,L"Integer material/flag assignment, not a file offset.");
case 0x6063007cU:return xx_data_struct_record_set_comment(r,L"NASTRAN coordinate system identifier; native subset requires0.");
case 0x6063007dU:return xx_data_struct_record_set_comment(r,L"NASTRAN GRID CD displacement coordinate-system identifier; native subset requires0.");
case 0x6063007eU:return xx_data_struct_record_set_comment(r,L"NASTRAN GRID PS permanent constraint component digits; native subset requires0.");
case 0x6063007fU:return xx_data_struct_record_set_comment(r,L"NASTRAN GRID SEID superelement identifier; native subset requires0.");
case 0x60630080U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630081U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630082U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630083U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630084U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630085U:return xx_data_struct_record_set_comment(r,L"NASTRAN stored real; E/D and implicit exponent spellings retain exact source bytes.");
case 0x60630086U:return xx_data_struct_record_set_comment(r,L"Native GMV signed32 entry count.");
case 0x60630087U:return xx_data_struct_record_set_comment(r,L"Native GMV signed32 entry count.");
case 0x60630088U:return xx_data_struct_record_set_comment(r,L"Native GMV physical integer/index; not a file offset.");
case 0x60630089U:return xx_data_struct_record_set_comment(r,L"Native GMV physical integer/index; not a file offset.");
case 0x6063008aU:return xx_data_struct_record_set_comment(r,L"Native GMV physical integer/index; not a file offset.");
case 0x6063008bU:return xx_data_struct_record_set_comment(r,L"Native GMV physical integer/index; not a file offset.");
case 0x6063008cU:return xx_data_struct_record_set_comment(r,L"GMV association selector: 0=cell-centered, 1=node-centered.");
case 0x6063008dU:return xx_data_struct_record_set_comment(r,L"Native GMV stored IEEE754 binary32; model-defined units.");
case 0x6063008eU:return xx_data_struct_record_set_comment(r,L"Native GMV stored IEEE754 binary32; model-defined units.");
case 0x6063008fU:return xx_data_struct_record_set_comment(r,L"Native GMV stored IEEE754 binary32; model-defined units.");
case 0x60630090U:return xx_data_struct_record_set_comment(r,L"Native GMV stored IEEE754 binary32; model-defined units.");
case 0x60630091U:return xx_data_struct_record_set_comment(r,L"Fixed GMV eight-byte keyword/name, padding retained.");
default:return true;}}
bool sxsm_space(uint8_t c){return c==' '||c=='\t'||c=='\r'||c=='\n';}
bool sxsm_eq(sxsm_cursor*q,sxsm_token t,const char*s){size_t n=xx_rt_strlen(s);return t.a>=0&&t.z==(int64_t)n&&t.a<=q->n&&t.z<=q->n-t.a&&!xx_rt_memcmp(q->b+t.a,s,n);}
bool sxsm_ci(sxsm_cursor*q,sxsm_token t,const char*s){size_t n=xx_rt_strlen(s);if(t.a<0||t.z!=(int64_t)n||t.a>q->n||t.z>q->n-t.a)return false;for(size_t i=0;i<n;i++){unsigned ch=q->b[t.a+i];if(ch>='A'&&ch<='Z')ch+=32;if(ch!=(unsigned char)s[i])return false;}return true;}
sxsm_token sxsm_trim(sxsm_cursor*q,sxsm_token t){while(t.z&&sxsm_space(q->b[t.a])){t.a++;t.z--;}while(t.z&&sxsm_space(q->b[t.a+t.z-1]))t.z--;return t;}
bool sxsm_line(sxsm_cursor*q,sxsm_token*t){if(q->p>=q->n||++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;t->a=q->p;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;t->z=q->p-t->a;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;return true;}
unsigned sxsm_split(sxsm_cursor*q,sxsm_token line,sxsm_token*t,unsigned cap,bool tabs){unsigned n=0;int64_t p=line.a,end=p+line.z;while(p<end){if(tabs){int64_t a=p;while(p<end&&q->b[p]!='\t')p++;if(n==cap)return cap+1;t[n++]=(sxsm_token){a,p-a};if(p<end)p++;}else{while(p<end&&sxsm_space(q->b[p]))p++;if(p==end)break;int64_t a=p;while(p<end&&!sxsm_space(q->b[p]))p++;if(n==cap)return cap+1;t[n++]=(sxsm_token){a,p-a};}}return n;}
bool sxsm_emit(sxsm_cursor*q,const sx_layout*l,sxsm_token t){if(t.a<0||t.z<0||t.a>q->n||t.z>q->n-t.a||xx_pd_is_stopped(q->c->pd))return false;if(!t.z||q->c->count>=24000)return true;if(!l->fields[0].size&&t.z>sx_variable_field_limit(l->fields[0].type))return true;return sx_add(q->c,l,t.a,t.z);}
bool sxsm_number(sxsm_cursor*q,sxsm_token t,uint64_t*v){t=sxsm_trim(q,t);uint64_t n=0;int64_t i=0;if(t.z&&q->b[t.a]=='+')i++;if(i==t.z)return false;for(;i<t.z;i++){unsigned d=q->b[t.a+i]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*v=n;return true;}
bool sxsm_fields(sxsm_cursor*q,sxsm_token*t,unsigned n,const sx_layout*const*l,unsigned max){if(n>max)return false;for(unsigned i=0;i<n;i++)if(l[i]&&!sxsm_emit(q,l[i],t[i]))return false;return true;}
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
bool sxsm_next(sxsm_cursor*q,sxsm_token*line,sxsm_token*t,unsigned cap,unsigned*n,const char*comments){while(sxsm_line(q,line)){int64_t i=0;uint8_t quote=0;for(;i<line->z;i++){uint8_t ch=q->b[line->a+i];if(quote){if(ch==quote)quote=0;else if(ch==92&&i+1<line->z)i++;continue;}if(ch==34||ch==39){quote=ch;continue;}if(xx_rt_strchr(comments,ch)){SM_EMIT(comment,((sxsm_token){line->a+i,line->z-i}));line->z=i;break;}}*line=sxsm_trim(q,*line);if(line->z){*n=sxsm_split(q,*line,t,cap,false);return *n<=cap;}}return false;}
bool sxsm_each(sxsm_cursor*q,sxsm_token*t,unsigned n,const sx_layout*l){for(unsigned i=0;i<n;i++)if(!sxsm_emit(q,l,t[i]))return false;return true;}
bool sxsm_xyz(sxsm_cursor*q,sxsm_token*t,unsigned kind){const sx_layout*const rows[][3]={{&sxsm_coordinate_x,&sxsm_coordinate_y,&sxsm_coordinate_z},{&sxsm_origin_x,&sxsm_origin_y,&sxsm_origin_z},{&sxsm_spacing_x,&sxsm_spacing_y,&sxsm_spacing_z},{&sxsm_delta_x,&sxsm_delta_y,&sxsm_delta_z}};return kind<SX_COUNT(rows)&&sxsm_fields(q,t,3,rows[kind],3);}
unsigned sxsm_csv(sxsm_cursor*q,sxsm_token line,sxsm_token*t,unsigned cap){unsigned n=0;int64_t p=line.a,end=p+line.z;do{int64_t a=p;while(p<end&&q->b[p]!=',')p++;if(n==cap)return cap+1;t[n++]=sxsm_trim(q,(sxsm_token){a,p-a});if(p==end)break;p++;}while(p<=end);return n;}
bool sxsm_keyvalue(sxsm_cursor*q,sxsm_token line,uint8_t delim,sxsm_token*key,sxsm_token*value){int64_t i=0;while(i<line.z&&q->b[line.a+i]!=delim)i++;if(i==line.z)return false;*key=sxsm_trim(q,(sxsm_token){line.a,i});*value=sxsm_trim(q,(sxsm_token){line.a+i+1,line.z-i-1});return key->z!=0;}
bool sxsm_nrrd_meta(sxsm_cursor*q,bool meta){sxsm_token line,key,value,t[32];unsigned n;if(!meta){if(!sxsm_line(q,&line))return false;SM_EMIT(signature,line);}while(sxsm_line(q,&line)){if(q->c->count>=24000)return true;line=sxsm_trim(q,line);if(!line.z){if(!meta)return true;continue;}if(q->b[line.a]=='#'){SM_EMIT(comment,line);continue;}if(!sxsm_keyvalue(q,line,meta?'=':':',&key,&value))return false;SM_EMIT(key,key);const sx_layout*l=&sxsm_option_value;
 if(sxsm_ci(q,key,meta?"ndims":"dimension"))l=&sxsm_dimension;
 else if(sxsm_ci(q,key,meta?"elementtype":"type"))l=&sxsm_type_name;
 else if(sxsm_ci(q,key,"encoding"))l=&sxsm_encoding;
 else if(sxsm_ci(q,key,"endian"))l=&sxsm_endian;
 else if(meta&&(sxsm_ci(q,key,"binarydata")||sxsm_ci(q,key,"compresseddata")||sxsm_ci(q,key,"binarydatabyteordermsb")||sxsm_ci(q,key,"elementbyteordermsb")))l=&sxsm_boolean_text;
 else if(meta&&sxsm_ci(q,key,"elementnumberofchannels"))l=&sxsm_component_count;
 else if(meta&&sxsm_ci(q,key,"headersize"))l=&sxsm_header_bytes;
 else if(sxsm_ci(q,key,meta?"dimsize":"sizes")){n=sxsm_split(q,value,t,32,false);if(n>32||!sxsm_each(q,t,n,&sxsm_axis_count))return false;continue;}
 if(!sxsm_emit(q,l,value))return false;if(meta&&sxsm_ci(q,key,"elementdatafile"))return true;
 }return false;}
bool sxsm_phylo(sxsm_cursor*q,bool nexus){bool length=false,count=false,tree=false,treeeq=false,topology=!nexus,taxa=false;while(q->p<q->n){if(q->c->count>=24000)return true;if(++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;uint8_t ch=q->b[q->p];if(sxsm_space(ch)){q->p++;continue;}int64_t a=q->p;if(ch=='['){unsigned depth=1;q->p++;while(q->p<q->n&&depth){ch=q->b[q->p++];if(ch=='['&&++depth>64)return false;if(ch==']')depth--;}if(depth)return false;SM_EMIT(comment,((sxsm_token){a,q->p-a}));continue;}if(xx_rt_strchr("(),:;=*",ch)){if(ch==':'&&topology)length=true;if(ch=='='&&treeeq){topology=true;treeeq=false;}if(ch==';'&&nexus){topology=false;taxa=false;}q->p++;continue;}if(ch=='\''){q->p++;bool closed=false;while(q->p<q->n){if(q->b[q->p++]=='\''){if(q->p<q->n&&q->b[q->p]=='\''){q->p++;continue;}closed=true;break;}}if(!closed)return false;}else{while(q->p<q->n&&!sxsm_space(q->b[q->p])&&!xx_rt_strchr("(),:;=[]",q->b[q->p]))q->p++;}if(q->p==a)return false;sxsm_token t={a,q->p-a};const sx_layout*l=&sxsm_node_label;
 if(length){l=&sxsm_branch_length;length=false;}else if(count){l=&sxsm_taxon_count;count=false;}else if(tree){l=&sxsm_tree_name;tree=false;treeeq=true;}else if(nexus&&!topology&&!taxa&&(sxsm_ci(q,t,"#nexus")||sxsm_ci(q,t,"begin")||sxsm_ci(q,t,"taxa")||sxsm_ci(q,t,"dimensions")||sxsm_ci(q,t,"ntax")||sxsm_ci(q,t,"taxlabels")||sxsm_ci(q,t,"trees")||sxsm_ci(q,t,"tree")||sxsm_ci(q,t,"utree")||sxsm_ci(q,t,"end")||sxsm_ci(q,t,"endblock"))){l=&sxsm_keyword;taxa=sxsm_ci(q,t,"taxlabels");count=sxsm_ci(q,t,"ntax");tree=sxsm_ci(q,t,"tree")||sxsm_ci(q,t,"utree");}
 if(!sxsm_emit(q,l,t))return false;}return true;}
/* Bounded physical token cursor for native lexer-based mesh grammars. */
bool sxsm_lex(sxsm_cursor*q,sxsm_token*t,bool hash){while(q->p<q->n){if(++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;uint8_t ch=q->b[q->p];if(sxsm_space(ch)){q->p++;continue;}int64_t a=q->p;if((hash&&(ch=='#'||ch=='!'))||(ch=='/'&&q->n-q->p>=2&&q->b[q->p+1]=='/')){while(q->p<q->n&&q->b[q->p]!='\r'&&q->b[q->p]!='\n')q->p++;SM_EMIT(comment,((sxsm_token){a,q->p-a}));continue;}if(ch=='/'&&q->n-q->p>=2&&q->b[q->p+1]=='*'){q->p+=2;while(q->n-q->p>=2&&(q->b[q->p]!='*'||q->b[q->p+1]!='/'))q->p++;if(q->n-q->p<2)return false;q->p+=2;SM_EMIT(comment,((sxsm_token){a,q->p-a}));continue;}
 if(xx_rt_strchr("{}()[],;@",ch)){q->p++;*t=(sxsm_token){a,1};return true;}if(ch=='"'){q->p++;bool closed=false;while(q->p<q->n){ch=q->b[q->p++];if(ch=='"'){closed=true;break;}if(ch=='\\'&&q->p<q->n)q->p++;}if(!closed)return false;}else{while(q->p<q->n&&!sxsm_space(q->b[q->p])&&!xx_rt_strchr("{}()[],;@",q->b[q->p]))q->p++;}if(q->p==a)return false;*t=(sxsm_token){a,q->p-a};return true;}return false;}
bool sxsm_expect(sxsm_cursor*q,const char*s,bool hash){sxsm_token t;return sxsm_lex(q,&t,hash)&&sxsm_eq(q,t,s);}
bool sxsm_one(sxsm_cursor*q,const sx_layout*l,bool hash){sxsm_token t;return sxsm_lex(q,&t,hash)&&sxsm_emit(q,l,t);}
bool sxsm_many(sxsm_cursor*q,const sx_layout*l,uint64_t count,bool hash){if(count>1000000)return false;for(uint64_t i=0;i<count;i++){if(q->c->count>=24000)return true;if(!sxsm_one(q,l,hash))return false;}return true;}
bool sxsm_count(sxsm_cursor*q,const sx_layout*l,uint64_t*v,bool hash){sxsm_token t;return sxsm_lex(q,&t,hash)&&sxsm_number(q,t,v)&&*v<=1000000&&sxsm_emit(q,l,t);}
static int sxsm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxsm_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsm_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_sciencemesh_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_NRRD:case XX_FILE_TYPE_METAIMAGE:case XX_FILE_TYPE_VTK_LEGACY:case XX_FILE_TYPE_MICROSCOPY_ICS:case XX_FILE_TYPE_TEKTRONIX_ISF:case XX_FILE_TYPE_PHYLO_NEXUS:case XX_FILE_TYPE_PHYLO_NEWICK:case XX_FILE_TYPE_OPENDX_FIELD:case XX_FILE_TYPE_GMSH_MSH:case XX_FILE_TYPE_NETGEN_VOL:case XX_FILE_TYPE_JCAMP_DX:case XX_FILE_TYPE_SURFER_GRID:case XX_FILE_TYPE_HARWELL_BOEING:case XX_FILE_TYPE_OPENFOAM_POINTS:case XX_FILE_TYPE_MEDIT_MESH:case XX_FILE_TYPE_GOCAD_MODEL:case XX_FILE_TYPE_NASTRAN_BULK:case XX_FILE_TYPE_ABAQUS_INPUT:case XX_FILE_TYPE_GMV_MESH:case XX_FILE_TYPE_AMIRA_MESH:case XX_FILE_TYPE_TETGEN_MESH:return true;default:return false;}}
static bool sx_sciencemesh_build(sx_context*c){if(!c||!c->f||c->size<1||c->size>67108864||xx_pd_is_stopped(c->pd))return false;if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxsm_cursor cursor={c,b,c->size,0,0},*q=&cursor;xx_file_type_t type=c->f->file_type;if(ok)switch(type){
case XX_FILE_TYPE_NRRD:ok=sx_nrrd_build(q);break;
case XX_FILE_TYPE_METAIMAGE:ok=sx_metaimage_build(q);break;
case XX_FILE_TYPE_VTK_LEGACY:ok=sx_vtk_legacy_build(q);break;
case XX_FILE_TYPE_MICROSCOPY_ICS:ok=sx_microscopy_ics_build(q);break;
case XX_FILE_TYPE_TEKTRONIX_ISF:ok=sx_tektronix_isf_build(q);break;
case XX_FILE_TYPE_PHYLO_NEXUS:ok=sx_phylo_nexus_build(q);break;
case XX_FILE_TYPE_PHYLO_NEWICK:ok=sx_phylo_newick_build(q);break;
case XX_FILE_TYPE_OPENDX_FIELD:ok=sx_opendx_field_build(q);break;
case XX_FILE_TYPE_GMSH_MSH:ok=sx_gmsh_msh_build(q);break;
case XX_FILE_TYPE_NETGEN_VOL:ok=sx_netgen_vol_build(q);break;
case XX_FILE_TYPE_JCAMP_DX:ok=sx_jcamp_dx_build(q);break;
case XX_FILE_TYPE_SURFER_GRID:ok=sx_surfer_grid_build(q);break;
case XX_FILE_TYPE_HARWELL_BOEING:ok=sx_harwell_boeing_build(q);break;
case XX_FILE_TYPE_OPENFOAM_POINTS:ok=sx_openfoam_points_build(q);break;
case XX_FILE_TYPE_MEDIT_MESH:ok=sx_medit_mesh_build(q);break;
case XX_FILE_TYPE_GOCAD_MODEL:ok=sx_gocad_model_build(q);break;
case XX_FILE_TYPE_NASTRAN_BULK:ok=sx_nastran_bulk_build(q);break;
case XX_FILE_TYPE_ABAQUS_INPUT:ok=sx_abaqus_input_build(q);break;
case XX_FILE_TYPE_GMV_MESH:ok=sx_gmv_mesh_build(q);break;
case XX_FILE_TYPE_AMIRA_MESH:ok=sx_amira_mesh_build(q);break;
case XX_FILE_TYPE_TETGEN_MESH:ok=sx_tetgen_mesh_build(q);break;
default:ok=false;break;}xx_mem_free(b);return ok&&sxsm_finish(c);}
#undef SM_EMIT
const sx_family sx_sciencemesh_family={sx_sciencemesh_supports,sx_sciencemesh_build,sx_sciencemesh_layouts,SX_COUNT(sx_sciencemesh_layouts),sx_sciencemesh_comment};
