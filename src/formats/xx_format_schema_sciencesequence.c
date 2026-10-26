/* SPDX-License-Identifier: MIT
 * Physical native-supported sequence/alignment and MD5 metadata. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_sciencesequence.h"
static const xx_data_struct_field_desc sxseq_signature_fields[]={SX_FIELD("signature","char",0,0,SX_STRING)};
const sx_layout sxseq_signature={0x60730001U,"sequence_signature",sxseq_signature_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_keyword_fields[]={SX_FIELD("keyword","char",0,0,SX_STRING)};
const sx_layout sxseq_keyword={0x60730002U,"sequence_keyword",sxseq_keyword_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_field_key_fields[]={SX_FIELD("field_key","char",0,0,SX_STRING)};
const sx_layout sxseq_field_key={0x60730003U,"sequence_field_key",sxseq_field_key_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_field_text_fields[]={SX_FIELD("field_text","char",0,0,SX_STRING)};
const sx_layout sxseq_field_text={0x60730004U,"sequence_field_text",sxseq_field_text_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_identifier_fields[]={SX_FIELD("identifier","char",0,0,SX_STRING)};
const sx_layout sxseq_identifier={0x60730005U,"sequence_identifier",sxseq_identifier_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_locus_options_fields[]={SX_FIELD("locus_options","char",0,0,SX_STRING)};
const sx_layout sxseq_locus_options={0x60730007U,"sequence_locus_options",sxseq_locus_options_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_unit_fields[]={SX_FIELD("unit","char",0,0,SX_STRING)};
const sx_layout sxseq_unit={0x60730008U,"sequence_unit",sxseq_unit_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_accession_fields[]={SX_FIELD("accession","char",0,0,SX_STRING)};
const sx_layout sxseq_accession={0x60730009U,"sequence_accession",sxseq_accession_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_feature_key_fields[]={SX_FIELD("feature_key","char",0,0,SX_STRING)};
const sx_layout sxseq_feature_key={0x6073000aU,"sequence_feature_key",sxseq_feature_key_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_feature_location_fields[]={SX_FIELD("feature_location","char",0,0,SX_STRING)};
const sx_layout sxseq_feature_location={0x6073000bU,"sequence_feature_location",sxseq_feature_location_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_feature_qualifier_fields[]={SX_FIELD("feature_qualifier","char",0,0,SX_STRING)};
const sx_layout sxseq_feature_qualifier={0x6073000cU,"sequence_feature_qualifier",sxseq_feature_qualifier_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_comment_fields[]={SX_FIELD("comment","char",0,0,SX_STRING)};
const sx_layout sxseq_comment={0x6073000dU,"sequence_comment",sxseq_comment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_terminator_fields[]={SX_FIELD("terminator","char",0,0,SX_STRING)};
const sx_layout sxseq_terminator={0x6073000eU,"sequence_terminator",sxseq_terminator_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_entry_status_fields[]={SX_FIELD("entry_status","char",0,0,SX_STRING)};
static const sx_layout sxseq_entry_status={0x6073000fU,"sequence_entry_status",sxseq_entry_status_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_date_text_fields[]={SX_FIELD("date_text","char",0,0,SX_STRING)};
static const sx_layout sxseq_date_text={0x60730010U,"sequence_date_text",sxseq_date_text_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_sequence_length_fields[]={SX_FIELD("sequence_length","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxseq_sequence_length={0x60730011U,"sequence_sequence_length",sxseq_sequence_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_adenine_count_fields[]={SX_FIELD("adenine_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_adenine_count={0x60730014U,"sequence_adenine_count",sxseq_adenine_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_cytosine_count_fields[]={SX_FIELD("cytosine_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_cytosine_count={0x60730015U,"sequence_cytosine_count",sxseq_cytosine_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_guanine_count_fields[]={SX_FIELD("guanine_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_guanine_count={0x60730016U,"sequence_guanine_count",sxseq_guanine_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_thymine_count_fields[]={SX_FIELD("thymine_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_thymine_count={0x60730017U,"sequence_thymine_count",sxseq_thymine_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_other_base_count_fields[]={SX_FIELD("other_base_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_other_base_count={0x60730018U,"sequence_other_base_count",sxseq_other_base_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_residue_total_fields[]={SX_FIELD("residue_total","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxseq_residue_total={0x6073001aU,"sequence_residue_total",sxseq_residue_total_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_sequence_text_fields[]={SX_FIELD("sequence_text","char",0,0,SX_STRING)};
const sx_layout sxseq_sequence_text={0x6073001bU,"sequence_sequence_text",sxseq_sequence_text_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_molecular_weight_fields[]={SX_FIELD("molecular_weight","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxseq_molecular_weight={0x6073001fU,"sequence_molecular_weight",sxseq_molecular_weight_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_crc64_fields[]={SX_FIELD("crc64","ascii_hex",0,0,SX_CHECKSUM)};
static const sx_layout sxseq_crc64={0x60730020U,"sequence_crc64",sxseq_crc64_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_strand_fields[]={SX_FIELD("strand","char",0,0,SX_STRING)};
const sx_layout sxseq_strand={0x60730026U,"sequence_strand",sxseq_strand_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_commandline_fields[]={SX_FIELD("commandline","char",0,0,SX_STRING)};
static const sx_layout sxseq_commandline={0x6073003bU,"sequence_commandline",sxseq_commandline_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_joint_name_fields[]={SX_FIELD("joint_name","char",0,0,SX_STRING)};
static const sx_layout sxseq_joint_name={0x6073003cU,"sequence_joint_name",sxseq_joint_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_shader_name_fields[]={SX_FIELD("shader_name","char",0,0,SX_STRING)};
static const sx_layout sxseq_shader_name={0x6073003dU,"sequence_shader_name",sxseq_shader_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_md5_version_fields[]={SX_FIELD("md5_version","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxseq_md5_version={0x6073003eU,"sequence_md5_version",sxseq_md5_version_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_joint_count_fields[]={SX_FIELD("joint_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_joint_count={0x6073003fU,"sequence_joint_count",sxseq_joint_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_mesh_count_fields[]={SX_FIELD("mesh_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_mesh_count={0x60730040U,"sequence_mesh_count",sxseq_mesh_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_vertex_count_fields[]={SX_FIELD("vertex_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_vertex_count={0x60730041U,"sequence_vertex_count",sxseq_vertex_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_triangle_count_fields[]={SX_FIELD("triangle_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_triangle_count={0x60730042U,"sequence_triangle_count",sxseq_triangle_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_weight_count_fields[]={SX_FIELD("weight_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_weight_count={0x60730043U,"sequence_weight_count",sxseq_weight_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_frame_count_fields[]={SX_FIELD("frame_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_frame_count={0x60730044U,"sequence_frame_count",sxseq_frame_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_animated_component_count_fields[]={SX_FIELD("animated_component_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_animated_component_count={0x60730045U,"sequence_animated_component_count",sxseq_animated_component_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_frame_rate_fields[]={SX_FIELD("frame_rate","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxseq_frame_rate={0x60730046U,"sequence_frame_rate",sxseq_frame_rate_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_parent_joint_fields[]={SX_FIELD("parent_joint","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxseq_parent_joint={0x60730047U,"sequence_parent_joint",sxseq_parent_joint_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_vertex_index_fields[]={SX_FIELD("vertex_index","ascii_signed",0,0,SX_ID)};
static const sx_layout sxseq_vertex_index={0x60730048U,"sequence_vertex_index",sxseq_vertex_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_triangle_index_fields[]={SX_FIELD("triangle_index","ascii_signed",0,0,SX_ID)};
static const sx_layout sxseq_triangle_index={0x60730049U,"sequence_triangle_index",sxseq_triangle_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_weight_index_fields[]={SX_FIELD("weight_index","ascii_signed",0,0,SX_ID)};
static const sx_layout sxseq_weight_index={0x6073004aU,"sequence_weight_index",sxseq_weight_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_joint_index_fields[]={SX_FIELD("joint_index","ascii_signed",0,0,SX_ID)};
static const sx_layout sxseq_joint_index={0x6073004bU,"sequence_joint_index",sxseq_joint_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_frame_index_fields[]={SX_FIELD("frame_index","ascii_signed",0,0,SX_ID)};
static const sx_layout sxseq_frame_index={0x6073004cU,"sequence_frame_index",sxseq_frame_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_first_weight_fields[]={SX_FIELD("first_weight","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxseq_first_weight={0x6073004dU,"sequence_first_weight",sxseq_first_weight_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_component_start_fields[]={SX_FIELD("component_start","ascii_signed",0,0,SX_NONE)};
static const sx_layout sxseq_component_start={0x6073004eU,"sequence_component_start",sxseq_component_start_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_vertex_weight_count_fields[]={SX_FIELD("vertex_weight_count","ascii_signed",0,0,SX_COUNT_PROP)};
static const sx_layout sxseq_vertex_weight_count={0x6073004fU,"sequence_vertex_weight_count",sxseq_vertex_weight_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_animation_flags_fields[]={SX_FIELD("animation_flags","ascii_signed",0,0,SX_FLAGS)};
static const sx_layout sxseq_animation_flags={0x60730050U,"sequence_animation_flags",sxseq_animation_flags_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_texture_u_fields[]={SX_FIELD("texture_u","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_texture_u={0x60730051U,"sequence_texture_u",sxseq_texture_u_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_texture_v_fields[]={SX_FIELD("texture_v","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_texture_v={0x60730052U,"sequence_texture_v",sxseq_texture_v_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_weight_bias_fields[]={SX_FIELD("weight_bias","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_weight_bias={0x60730053U,"sequence_weight_bias",sxseq_weight_bias_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_position_x_fields[]={SX_FIELD("position_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_position_x={0x60730054U,"sequence_position_x",sxseq_position_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_position_y_fields[]={SX_FIELD("position_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_position_y={0x60730055U,"sequence_position_y",sxseq_position_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_position_z_fields[]={SX_FIELD("position_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_position_z={0x60730056U,"sequence_position_z",sxseq_position_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_bounds_min_x_fields[]={SX_FIELD("bounds_min_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_bounds_min_x={0x60730057U,"sequence_bounds_min_x",sxseq_bounds_min_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_bounds_min_y_fields[]={SX_FIELD("bounds_min_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_bounds_min_y={0x60730058U,"sequence_bounds_min_y",sxseq_bounds_min_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_bounds_min_z_fields[]={SX_FIELD("bounds_min_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_bounds_min_z={0x60730059U,"sequence_bounds_min_z",sxseq_bounds_min_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_bounds_max_x_fields[]={SX_FIELD("bounds_max_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_bounds_max_x={0x6073005aU,"sequence_bounds_max_x",sxseq_bounds_max_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_bounds_max_y_fields[]={SX_FIELD("bounds_max_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_bounds_max_y={0x6073005bU,"sequence_bounds_max_y",sxseq_bounds_max_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_bounds_max_z_fields[]={SX_FIELD("bounds_max_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_bounds_max_z={0x6073005cU,"sequence_bounds_max_z",sxseq_bounds_max_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_weight_position_x_fields[]={SX_FIELD("weight_position_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_weight_position_x={0x6073005dU,"sequence_weight_position_x",sxseq_weight_position_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_weight_position_y_fields[]={SX_FIELD("weight_position_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_weight_position_y={0x6073005eU,"sequence_weight_position_y",sxseq_weight_position_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_weight_position_z_fields[]={SX_FIELD("weight_position_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_weight_position_z={0x6073005fU,"sequence_weight_position_z",sxseq_weight_position_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_local_position_x_fields[]={SX_FIELD("local_position_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_local_position_x={0x60730060U,"sequence_local_position_x",sxseq_local_position_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_local_position_y_fields[]={SX_FIELD("local_position_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_local_position_y={0x60730061U,"sequence_local_position_y",sxseq_local_position_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_local_position_z_fields[]={SX_FIELD("local_position_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_local_position_z={0x60730062U,"sequence_local_position_z",sxseq_local_position_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_orientation_x_fields[]={SX_FIELD("orientation_x","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_orientation_x={0x60730063U,"sequence_orientation_x",sxseq_orientation_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_orientation_y_fields[]={SX_FIELD("orientation_y","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_orientation_y={0x60730064U,"sequence_orientation_y",sxseq_orientation_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_orientation_z_fields[]={SX_FIELD("orientation_z","ascii_real",0,0,SX_NONE)};
static const sx_layout sxseq_orientation_z={0x60730065U,"sequence_orientation_z",sxseq_orientation_z_fields,1,SX_LE};
static const sx_layout*const sx_sciencesequence_layouts[]={&sxseq_signature,&sxseq_keyword,&sxseq_field_key,&sxseq_field_text,&sxseq_identifier,&sxseq_molecule_type,&sxseq_locus_options,&sxseq_unit,&sxseq_accession,&sxseq_feature_key,&sxseq_feature_location,&sxseq_feature_qualifier,&sxseq_comment,&sxseq_terminator,&sxseq_entry_status,&sxseq_date_text,&sxseq_sequence_length,&sxseq_alignment_columns,&sxseq_sequence_count,&sxseq_adenine_count,&sxseq_cytosine_count,&sxseq_guanine_count,&sxseq_thymine_count,&sxseq_other_base_count,&sxseq_sequence_position,&sxseq_residue_total,&sxseq_sequence_text,&sxseq_consensus,&sxseq_annotation_key,&sxseq_annotation_text,&sxseq_molecular_weight,&sxseq_crc64,&sxseq_maf_scoring,&sxseq_alignment_score,&sxseq_maf_start,&sxseq_maf_size,&sxseq_source_length,&sxseq_strand,&sxseq_mauve_sequence_id,&sxseq_mauve_start,&sxseq_mauve_end,&sxseq_source_filename,&sxseq_gfa_record_type,&sxseq_segment_name,&sxseq_path_name,&sxseq_orientation,&sxseq_overlap_length,&sxseq_cigar_operation,&sxseq_missing_overlap,&sxseq_tag_name,&sxseq_tag_type,&sxseq_tag_integer,&sxseq_tag_real,&sxseq_tag_string,&sxseq_tag_character,&sxseq_tag_hex_bytes,&sxseq_gfa_declared_length,&sxseq_version,&sxseq_commandline,&sxseq_joint_name,&sxseq_shader_name,&sxseq_md5_version,&sxseq_joint_count,&sxseq_mesh_count,&sxseq_vertex_count,&sxseq_triangle_count,&sxseq_weight_count,&sxseq_frame_count,&sxseq_animated_component_count,&sxseq_frame_rate,&sxseq_parent_joint,&sxseq_vertex_index,&sxseq_triangle_index,&sxseq_weight_index,&sxseq_joint_index,&sxseq_frame_index,&sxseq_first_weight,&sxseq_component_start,&sxseq_vertex_weight_count,&sxseq_animation_flags,&sxseq_texture_u,&sxseq_texture_v,&sxseq_weight_bias,&sxseq_position_x,&sxseq_position_y,&sxseq_position_z,&sxseq_bounds_min_x,&sxseq_bounds_min_y,&sxseq_bounds_min_z,&sxseq_bounds_max_x,&sxseq_bounds_max_y,&sxseq_bounds_max_z,&sxseq_weight_position_x,&sxseq_weight_position_y,&sxseq_weight_position_z,&sxseq_local_position_x,&sxseq_local_position_y,&sxseq_local_position_z,&sxseq_orientation_x,&sxseq_orientation_y,&sxseq_orientation_z};
static bool sx_sciencesequence_comment(xx_data_struct_record*r,uint32_t id){if(!r)return false;if(id<0x60730001U||id>=0x60730001U+SX_COUNT(sx_sciencesequence_layouts))return true;if(!r->name||xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;switch(id){
case 0x60730001U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730002U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730003U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730004U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730005U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730006U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730007U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730008U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730009U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x6073000aU:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x6073000bU:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x6073000cU:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x6073000dU:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x6073000eU:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x6073000fU:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730010U:return xx_data_struct_record_set_comment(r,L"Original source text; no normalization or decoded reconstruction.");
case 0x60730011U:return xx_data_struct_record_set_comment(r,L"Count of biological residues, alignment columns or records, not a byte length.");
case 0x60730012U:return xx_data_struct_record_set_comment(r,L"Count of biological residues, alignment columns or records, not a byte length.");
case 0x60730013U:return xx_data_struct_record_set_comment(r,L"Count of biological residues, alignment columns or records, not a byte length.");
case 0x60730014U:return xx_data_struct_record_set_comment(r,L"Count of biological residues, alignment columns or records, not a byte length.");
case 0x60730015U:return xx_data_struct_record_set_comment(r,L"Count of biological residues, alignment columns or records, not a byte length.");
case 0x60730016U:return xx_data_struct_record_set_comment(r,L"Count of biological residues, alignment columns or records, not a byte length.");
case 0x60730017U:return xx_data_struct_record_set_comment(r,L"Count of biological residues, alignment columns or records, not a byte length.");
case 0x60730018U:return xx_data_struct_record_set_comment(r,L"Count of biological residues, alignment columns or records, not a byte length.");
case 0x60730019U:return xx_data_struct_record_set_comment(r,L"One-based position of the first residue on this physical GenBank line; not a byte offset.");
case 0x6073001aU:return xx_data_struct_record_set_comment(r,L"Cumulative ungapped residue count through this physical sequence line.");
case 0x6073001bU:return xx_data_struct_record_set_comment(r,L"Original biological sequence/alignment characters including source case and gaps; not normalized or decoded.");
case 0x6073001cU:return xx_data_struct_record_set_comment(r,L"Physical Clustal conservation symbols: *=identical, colon=strong group, dot=weak group; spaces retained.");
case 0x6073001dU:return xx_data_struct_record_set_comment(r,L"Original Stockholm annotation key/value; annotation symbols retain their stored alignment positions.");
case 0x6073001eU:return xx_data_struct_record_set_comment(r,L"Original Stockholm annotation key/value; annotation symbols retain their stored alignment positions.");
case 0x6073001fU:return xx_data_struct_record_set_comment(r,L"Stored relative molecular mass in daltons, not a byte size.");
case 0x60730020U:return xx_data_struct_record_set_comment(r,L"Physical Swiss-Prot CRC64 hexadecimal checksum, validated by the native reader.");
case 0x60730021U:return xx_data_struct_record_set_comment(r,L"Name of the alignment scoring scheme; score units depend on this scheme.");
case 0x60730022U:return xx_data_struct_record_set_comment(r,L"Stored MAF alignment score in scoring-scheme units.");
case 0x60730023U:return xx_data_struct_record_set_comment(r,L"Zero-based source start on the indicated strand; reverse-strand coordinates count from the reverse complement, not the forward sequence.");
case 0x60730024U:return xx_data_struct_record_set_comment(r,L"Ungapped residue count or complete source-sequence length, not a byte size.");
case 0x60730025U:return xx_data_struct_record_set_comment(r,L"Ungapped residue count or complete source-sequence length, not a byte size.");
case 0x60730026U:return xx_data_struct_record_set_comment(r,L"Source orientation: plus=forward, minus=reverse complement; stored sequence is not reoriented.");
case 0x60730027U:return xx_data_struct_record_set_comment(r,L"One-based source sequence number in the XMFA alignment.");
case 0x60730028U:return xx_data_struct_record_set_comment(r,L"One-based inclusive source coordinates; the native 0-0 sentinel denotes missing/unspecified coordinates, not a file offset.");
case 0x60730029U:return xx_data_struct_record_set_comment(r,L"One-based inclusive source coordinates; the native 0-0 sentinel denotes missing/unspecified coordinates, not a file offset.");
case 0x6073002aU:return xx_data_struct_record_set_comment(r,L"Original source filename from the alignment; no file is opened.");
case 0x6073002bU:return xx_data_struct_record_set_comment(r,L"GFA1 record code: H=header, S=segment, L=link, P=path.");
case 0x6073002cU:return xx_data_struct_record_set_comment(r,L"Original graph identifier or reference, not a physical file address.");
case 0x6073002dU:return xx_data_struct_record_set_comment(r,L"Original graph identifier or reference, not a physical file address.");
case 0x6073002eU:return xx_data_struct_record_set_comment(r,L"Stored segment orientation, plus or minus.");
case 0x6073002fU:return xx_data_struct_record_set_comment(r,L"Count of matched residues in the native-supported M-only CIGAR.");
case 0x60730030U:return xx_data_struct_record_set_comment(r,L"Native-supported M operation: alignment match/mismatch; no generalized CIGAR interpretation.");
case 0x60730031U:return xx_data_struct_record_set_comment(r,L"Asterisk preserves an unspecified path-overlap list.");
case 0x60730032U:return xx_data_struct_record_set_comment(r,L"Two-character GFA tag identifier, case retained.");
case 0x60730033U:return xx_data_struct_record_set_comment(r,L"GFA native-supported value type: A=character, i=signed integer, f=single-precision-compatible real, Z=string, H=hexadecimal bytes.");
case 0x60730034U:return xx_data_struct_record_set_comment(r,L"Stored signed32-compatible GFA integer; semantic meaning depends on the tag.");
case 0x60730035U:return xx_data_struct_record_set_comment(r,L"Original GFA decimal real token validated as finite single-precision-compatible by the native reader; source value is not rounded.");
case 0x60730036U:return xx_data_struct_record_set_comment(r,L"Original GFA textual tag value.");
case 0x60730037U:return xx_data_struct_record_set_comment(r,L"Original GFA textual tag value.");
case 0x60730038U:return xx_data_struct_record_set_comment(r,L"Original hexadecimal byte-array spelling, not a numeric address or decoded payload.");
case 0x60730039U:return xx_data_struct_record_set_comment(r,L"LN tag: declared segment residue count.");
case 0x6073003aU:return xx_data_struct_record_set_comment(r,L"Original format version token.");
case 0x6073003bU:return xx_data_struct_record_set_comment(r,L"Original MD5 directive/name token. Quoted content retains source spelling; no command or shader is executed.");
case 0x6073003cU:return xx_data_struct_record_set_comment(r,L"Original MD5 directive/name token. Quoted content retains source spelling; no command or shader is executed.");
case 0x6073003dU:return xx_data_struct_record_set_comment(r,L"Original MD5 directive/name token. Quoted content retains source spelling; no command or shader is executed.");
case 0x6073003eU:return xx_data_struct_record_set_comment(r,L"MD5 text format version; native subset supports10.");
case 0x6073003fU:return xx_data_struct_record_set_comment(r,L"Number of MD5 records/components.");
case 0x60730040U:return xx_data_struct_record_set_comment(r,L"Number of MD5 records/components.");
case 0x60730041U:return xx_data_struct_record_set_comment(r,L"Number of MD5 records/components.");
case 0x60730042U:return xx_data_struct_record_set_comment(r,L"Number of MD5 records/components.");
case 0x60730043U:return xx_data_struct_record_set_comment(r,L"Number of MD5 records/components.");
case 0x60730044U:return xx_data_struct_record_set_comment(r,L"Number of MD5 records/components.");
case 0x60730045U:return xx_data_struct_record_set_comment(r,L"Number of MD5 records/components.");
case 0x60730046U:return xx_data_struct_record_set_comment(r,L"Animation frames per second; not a timestamp.");
case 0x60730047U:return xx_data_struct_record_set_comment(r,L"Zero-based parent joint index; -1 is a root, not an address.");
case 0x60730048U:return xx_data_struct_record_set_comment(r,L"Zero-based MD5 record/reference index, not a byte offset.");
case 0x60730049U:return xx_data_struct_record_set_comment(r,L"Zero-based MD5 record/reference index, not a byte offset.");
case 0x6073004aU:return xx_data_struct_record_set_comment(r,L"Zero-based MD5 record/reference index, not a byte offset.");
case 0x6073004bU:return xx_data_struct_record_set_comment(r,L"Zero-based MD5 record/reference index, not a byte offset.");
case 0x6073004cU:return xx_data_struct_record_set_comment(r,L"Zero-based MD5 record/reference index, not a byte offset.");
case 0x6073004dU:return xx_data_struct_record_set_comment(r,L"Zero-based index into weight or frame-component array, not a byte offset.");
case 0x6073004eU:return xx_data_struct_record_set_comment(r,L"Zero-based index into weight or frame-component array, not a byte offset.");
case 0x6073004fU:return xx_data_struct_record_set_comment(r,L"Number of influences assigned to this vertex.");
case 0x60730050U:return xx_data_struct_record_set_comment(r,L"Bits0..5 select animated translation X/Y/Z and quaternion X/Y/Z components.");
case 0x60730051U:return xx_data_struct_record_set_comment(r,L"Stored texture coordinates; shader-specific mapping, no unit conversion.");
case 0x60730052U:return xx_data_struct_record_set_comment(r,L"Stored texture coordinates; shader-specific mapping, no unit conversion.");
case 0x60730053U:return xx_data_struct_record_set_comment(r,L"Dimensionless skinning influence; native weights for each vertex sum approximately to1.");
case 0x60730054U:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x60730055U:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x60730056U:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x60730057U:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x60730058U:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x60730059U:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x6073005aU:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x6073005bU:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x6073005cU:return xx_data_struct_record_set_comment(r,L"Stored model-space coordinate in engine/model units; no world transform or byte address.");
case 0x6073005dU:return xx_data_struct_record_set_comment(r,L"Stored joint-local weight position, transformed by its referenced joint; engine/model units, not a file address.");
case 0x6073005eU:return xx_data_struct_record_set_comment(r,L"Stored joint-local weight position, transformed by its referenced joint; engine/model units, not a file address.");
case 0x6073005fU:return xx_data_struct_record_set_comment(r,L"Stored joint-local weight position, transformed by its referenced joint; engine/model units, not a file address.");
case 0x60730060U:return xx_data_struct_record_set_comment(r,L"Stored animation translation relative to the parent joint; root translation is model-local, not a world transform or file address.");
case 0x60730061U:return xx_data_struct_record_set_comment(r,L"Stored animation translation relative to the parent joint; root translation is model-local, not a world transform or file address.");
case 0x60730062U:return xx_data_struct_record_set_comment(r,L"Stored animation translation relative to the parent joint; root translation is model-local, not a world transform or file address.");
case 0x60730063U:return xx_data_struct_record_set_comment(r,L"Stored dimensionless quaternion XYZ; W is reconstructed by the engine and has no physical field.");
case 0x60730064U:return xx_data_struct_record_set_comment(r,L"Stored dimensionless quaternion XYZ; W is reconstructed by the engine and has no physical field.");
case 0x60730065U:return xx_data_struct_record_set_comment(r,L"Stored dimensionless quaternion XYZ; W is reconstructed by the engine and has no physical field.");
default:return true;}}
static bool sxseq_space(uint8_t c){return c==' '||c=='\t'||c=='\r'||c=='\n';}
bool sxseq_eq(sxseq_cursor*q,sxseq_token t,const char*s){size_t n=xx_rt_strlen(s);return t.a>=0&&t.z==(int64_t)n&&t.a<=q->n&&t.z<=q->n-t.a&&!xx_rt_memcmp(q->b+t.a,s,n);}
sxseq_token sxseq_trim(sxseq_cursor*q,sxseq_token t){while(t.z&&sxseq_space(q->b[t.a])){t.a++;t.z--;}while(t.z&&sxseq_space(q->b[t.a+t.z-1]))t.z--;return t;}
bool sxseq_line(sxseq_cursor*q,sxseq_token*t){if(q->p>=q->n||++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;t->a=q->p;while(q->p<q->n&&q->b[q->p]!='\n'&&q->b[q->p]!='\r')q->p++;t->z=q->p-t->a;if(q->p<q->n&&q->b[q->p]=='\r')q->p++;if(q->p<q->n&&q->b[q->p]=='\n')q->p++;return true;}
unsigned sxseq_split(sxseq_cursor*q,sxseq_token line,sxseq_token*t,unsigned cap,bool tabs){unsigned n=0;int64_t p=line.a,end=p+line.z;while(p<end){if(tabs){int64_t a=p;while(p<end&&q->b[p]!='\t')p++;if(n==cap)return cap+1;t[n++]=(sxseq_token){a,p-a};if(p<end)p++;}else{while(p<end&&sxseq_space(q->b[p]))p++;if(p==end)break;int64_t a=p;while(p<end&&!sxseq_space(q->b[p]))p++;if(n==cap)return cap+1;t[n++]=(sxseq_token){a,p-a};}}return n;}
bool sxseq_emit(sxseq_cursor*q,const sx_layout*l,sxseq_token t){if(t.a<0||t.z<0||t.a>q->n||t.z>q->n-t.a||xx_pd_is_stopped(q->c->pd))return false;if(!t.z||q->c->count>=24000)return true;if(!l->fields[0].size&&t.z>sx_variable_field_limit(l->fields[0].type))return true;return sx_add(q->c,l,t.a,t.z);}
bool sxseq_number(sxseq_cursor*q,sxseq_token t,uint64_t*v){t=sxseq_trim(q,t);uint64_t n=0;int64_t i=0;if(t.z&&q->b[t.a]=='+')i++;if(i==t.z)return false;for(;i<t.z;i++){unsigned d=q->b[t.a+i]-'0';if(d>9||n>(UINT64_MAX-d)/10)return false;n=n*10+d;}*v=n;return true;}
#define SEQ_EMIT(n,t) do{if(!sxseq_emit(q,&sxseq_##n,(t)))return false;}while(0)
bool sxseq_chunks(sxseq_cursor*q,const sx_layout*l,sxseq_token t)
{
 while(t.z){int64_t n=t.z>4096?4096:t.z;if(!sxseq_emit(q,l,(sxseq_token){t.a,n}))return false;t.a+=n;t.z-=n;if(q->c->count>=24000)return true;}return true;
}
bool sxseq_embl_swiss(sxseq_cursor*q,bool swiss)
{
 sxseq_token line,t[64];bool sequence=false;
 while(sxseq_line(q,&line)){
  if(q->c->count>=24000)return true;sxseq_token trim=sxseq_trim(q,line);if(!trim.z)continue;
  if(sxseq_eq(q,trim,"//")){SEQ_EMIT(terminator,trim);sequence=false;continue;}
  unsigned n=0;
  if(sequence||(line.z>=2&&(sxseq_eq(q,(sxseq_token){line.a,2},"ID")||sxseq_eq(q,(sxseq_token){line.a,2},"SQ")))){n=sxseq_split(q,line,t,64,false);if(!n||n>64)return false;}
  if(sequence){unsigned count=swiss?n:n-1;for(unsigned i=0;i<count;i++)SEQ_EMIT(sequence_text,t[i]);if(!swiss)SEQ_EMIT(residue_total,t[n-1]);continue;}
  if(n&&sxseq_eq(q,t[0],"ID")){
   if(n<4)return false;SEQ_EMIT(keyword,t[0]);sxseq_token id=t[1];if(!swiss&&id.z&&q->b[id.a+id.z-1]==';')id.z--;SEQ_EMIT(identifier,id);
   if(swiss){if(n!=5)return false;SEQ_EMIT(entry_status,t[2]);SEQ_EMIT(sequence_length,t[3]);SEQ_EMIT(unit,t[4]);}
   else{if(n>4)SEQ_EMIT(locus_options,((sxseq_token){t[2].a,t[n-2].a-t[2].a}));SEQ_EMIT(sequence_length,t[n-2]);SEQ_EMIT(unit,t[n-1]);}continue;
  }
  if(n&&sxseq_eq(q,t[0],"SQ")){
   if(n!=(swiss?8U:14U))return false;SEQ_EMIT(keyword,t[0]);SEQ_EMIT(keyword,t[1]);SEQ_EMIT(sequence_length,t[2]);SEQ_EMIT(unit,t[3]);
   if(swiss){SEQ_EMIT(molecular_weight,t[4]);SEQ_EMIT(unit,t[5]);if(t[6].z==16){bool valid=true;for(int64_t k=0;k<t[6].z;k++){unsigned ch=q->b[t[6].a+k];if(!((ch>='0'&&ch<='9')||(ch>='a'&&ch<='f')||(ch>='A'&&ch<='F')))valid=false;}if(valid){SEQ_EMIT(crc64,t[6]);}}SEQ_EMIT(unit,t[7]);}
   else{const sx_layout*counts[]={&sxseq_adenine_count,&sxseq_cytosine_count,&sxseq_guanine_count,&sxseq_thymine_count,&sxseq_other_base_count};for(unsigned i=0;i<5;i++){if(!sxseq_emit(q,counts[i],t[4+i*2]))return false;SEQ_EMIT(unit,t[5+i*2]);}}
   sequence=true;continue;
  }
  if(line.z<2)return false;sxseq_token key={line.a,2};SEQ_EMIT(field_key,key);if(line.z<=5)continue;sxseq_token value=sxseq_trim(q,(sxseq_token){line.a+5,line.z-5});
  if(sxseq_eq(q,key,"FT")&&line.z>21){sxseq_token feature=sxseq_trim(q,(sxseq_token){line.a+5,16}),data=sxseq_trim(q,(sxseq_token){line.a+21,line.z-21});bool named=true;for(int64_t i=0;i<feature.z;i++){unsigned ch=q->b[feature.a+i];if(!((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||ch=='_'))named=false;}if(feature.z&&named){SEQ_EMIT(feature_key,feature);SEQ_EMIT(feature_location,data);}else if(!feature.z){SEQ_EMIT(feature_qualifier,data);}else{SEQ_EMIT(field_text,value);}}
  else if(sxseq_eq(q,key,"AC")){SEQ_EMIT(accession,value);}else if(sxseq_eq(q,key,"DT")){SEQ_EMIT(date_text,value);}else{SEQ_EMIT(field_text,value);}
 }return true;
}
/* The native MD5 lexer bounds names/numbers to255 bytes. This walker records
 * original token coordinates; native validation owns hierarchy/value semantics. */
static bool sxseq_lex(sxseq_cursor*q,sxseq_token*t,bool*quoted)
{
 while(q->p<q->n){if(++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;if(sxseq_space(q->b[q->p])){q->p++;continue;}
  if(q->n-q->p>=2&&q->b[q->p]=='/'&&q->b[q->p+1]=='/'){int64_t start=q->p;while(q->p<q->n&&q->b[q->p]!='\n')q->p++;SEQ_EMIT(comment,((sxseq_token){start,q->p-start}));continue;}break;
 }
 if(q->p==q->n)return false;int64_t start=q->p;uint8_t ch=q->b[q->p++];*quoted=ch=='"';
 if(*quoted){start=q->p;while(q->p<q->n&&q->b[q->p]!='"'){ch=q->b[q->p];if(ch<32||ch>126||ch=='\\'||q->p-start>=255)return false;q->p++;}if(q->p==q->n)return false;*t=(sxseq_token){start,q->p-start};q->p++;return true;}
 if(!xx_rt_strchr("{}()",ch)){while(q->p<q->n&&!sxseq_space(q->b[q->p])&&!xx_rt_strchr("{}()",q->b[q->p])){if(q->p-start>=255||q->b[q->p]<33||q->b[q->p]>126)return false;q->p++;}}
 *t=(sxseq_token){start,q->p-start};return true;
}
static bool sxseq_word(sxseq_cursor*q,const char*word,bool emit)
{
 sxseq_token t;bool quoted;if(!sxseq_lex(q,&t,&quoted)||quoted||!sxseq_eq(q,t,word))return false;if(emit)SEQ_EMIT(keyword,t);return true;
}
static bool sxseq_md5_value(sxseq_cursor*q,const sx_layout*l,bool name)
{
 sxseq_token t;bool quoted;return sxseq_lex(q,&t,&quoted)&&quoted==name&&sxseq_emit(q,l,t);
}
static bool sxseq_md5_count(sxseq_cursor*q,const char*word,const sx_layout*l,uint64_t*count,uint64_t max)
{
 sxseq_token t;bool quoted;return (!word||sxseq_word(q,word,true))&&sxseq_lex(q,&t,&quoted)&&!quoted&&sxseq_number(q,t,count)&&*count<=max&&sxseq_emit(q,l,t);
}
static bool sxseq_vector(sxseq_cursor*q,unsigned kind)
{
 const sx_layout*l[][3]={{&sxseq_position_x,&sxseq_position_y,&sxseq_position_z},{&sxseq_orientation_x,&sxseq_orientation_y,&sxseq_orientation_z},{&sxseq_weight_position_x,&sxseq_weight_position_y,&sxseq_weight_position_z},{&sxseq_bounds_min_x,&sxseq_bounds_min_y,&sxseq_bounds_min_z},{&sxseq_bounds_max_x,&sxseq_bounds_max_y,&sxseq_bounds_max_z},{&sxseq_local_position_x,&sxseq_local_position_y,&sxseq_local_position_z}};
 if(kind>=SX_COUNT(l)||!sxseq_word(q,"(",false))return false;for(unsigned i=0;i<3;i++)if(!sxseq_md5_value(q,l[kind][i],false))return false;return sxseq_word(q,")",false);
}
static bool sxseq_md5_mesh(sxseq_cursor*q,uint64_t joints)
{
 (void)joints;uint64_t n,index;if(!sxseq_word(q,"{",false)||!sxseq_word(q,"shader",true)||!sxseq_md5_value(q,&sxseq_shader_name,true)||!sxseq_md5_count(q,"numverts",&sxseq_vertex_count,&n,65536))return false;
 for(uint64_t i=0;i<n;i++){
  if(q->c->count>=24000)return true;if(!sxseq_md5_count(q,"vert",&sxseq_vertex_index,&index,65535)||!sxseq_word(q,"(",false)||!sxseq_md5_value(q,&sxseq_texture_u,false)||!sxseq_md5_value(q,&sxseq_texture_v,false)||!sxseq_word(q,")",false)||!sxseq_md5_value(q,&sxseq_first_weight,false)||!sxseq_md5_value(q,&sxseq_vertex_weight_count,false))return false;
 }
 if(!sxseq_md5_count(q,"numtris",&sxseq_triangle_count,&n,65536))return false;for(uint64_t i=0;i<n;i++){if(q->c->count>=24000)return true;if(!sxseq_md5_count(q,"tri",&sxseq_triangle_index,&index,65535))return false;for(unsigned j=0;j<3;j++)if(!sxseq_md5_value(q,&sxseq_vertex_index,false))return false;}
 if(!sxseq_md5_count(q,"numweights",&sxseq_weight_count,&n,65536))return false;for(uint64_t i=0;i<n;i++){if(q->c->count>=24000)return true;if(!sxseq_md5_count(q,"weight",&sxseq_weight_index,&index,65535)||!sxseq_md5_value(q,&sxseq_joint_index,false)||!sxseq_md5_value(q,&sxseq_weight_bias,false)||!sxseq_vector(q,2))return false;}
 return sxseq_word(q,"}",false);
}
bool sxseq_md5(sxseq_cursor*q,bool animation)
{
 uint64_t joints,meshes=0,frames=0,components=0,unused;const sx_layout*animated[1536]={0};
 if(!sxseq_md5_count(q,"MD5Version",&sxseq_md5_version,&unused,10)||!sxseq_word(q,"commandline",true)||!sxseq_md5_value(q,&sxseq_commandline,true))return false;
 if(animation&&!sxseq_md5_count(q,"numFrames",&sxseq_frame_count,&frames,1024))return false;
 if(!sxseq_md5_count(q,"numJoints",&sxseq_joint_count,&joints,256))return false;
 if(!animation){if(!sxseq_md5_count(q,"numMeshes",&sxseq_mesh_count,&meshes,256)||!sxseq_word(q,"joints",true)||!sxseq_word(q,"{",false))return false;
  for(uint64_t i=0;i<joints;i++)if(!sxseq_md5_value(q,&sxseq_joint_name,true)||!sxseq_md5_value(q,&sxseq_parent_joint,false)||!sxseq_vector(q,0)||!sxseq_vector(q,1))return false;
  if(!sxseq_word(q,"}",false))return false;for(uint64_t i=0;i<meshes;i++){if(q->c->count>=24000)return true;if(!sxseq_word(q,"mesh",true)||!sxseq_md5_mesh(q,joints))return false;}return true;
 }
 if(!sxseq_md5_count(q,"frameRate",&sxseq_frame_rate,&unused,1000)||!sxseq_md5_count(q,"numAnimatedComponents",&sxseq_animated_component_count,&components,1536)||!sxseq_word(q,"hierarchy",true)||!sxseq_word(q,"{",false))return false;
 const sx_layout*fields[]={&sxseq_local_position_x,&sxseq_local_position_y,&sxseq_local_position_z,&sxseq_orientation_x,&sxseq_orientation_y,&sxseq_orientation_z};
 for(uint64_t i=0;i<joints;i++){
  uint64_t flags,start;if(!sxseq_md5_value(q,&sxseq_joint_name,true)||!sxseq_md5_value(q,&sxseq_parent_joint,false)||!sxseq_md5_count(q,NULL,&sxseq_animation_flags,&flags,63)||!sxseq_md5_count(q,NULL,&sxseq_component_start,&start,components))return false;
  for(unsigned bit=0;bit<6;bit++)if(flags&(1U<<bit)){if(start>=components||animated[start])return false;animated[start++]=fields[bit];}
 }
 for(uint64_t i=0;i<components;i++)if(!animated[i])return false;
 if(!sxseq_word(q,"}",false)||!sxseq_word(q,"bounds",true)||!sxseq_word(q,"{",false))return false;
 for(uint64_t i=0;i<frames;i++){if(q->c->count>=24000)return true;if(!sxseq_vector(q,3)||!sxseq_vector(q,4))return false;}
 if(!sxseq_word(q,"}",false)||!sxseq_word(q,"baseframe",true)||!sxseq_word(q,"{",false))return false;
 for(uint64_t i=0;i<joints;i++){if(q->c->count>=24000)return true;if(!sxseq_vector(q,5)||!sxseq_vector(q,1))return false;}
 if(!sxseq_word(q,"}",false))return false;
 for(uint64_t i=0;i<frames;i++){if(q->c->count>=24000)return true;if(!sxseq_md5_count(q,"frame",&sxseq_frame_index,&unused,1023)||!sxseq_word(q,"{",false))return false;for(uint64_t j=0;j<components;j++){if(q->c->count>=24000)return true;if(!sxseq_md5_value(q,animated[j],false))return false;}if(!sxseq_word(q,"}",false))return false;}
 return true;
}
static int sxseq_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxseq_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxseq_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxseq_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_sciencesequence_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_GENOMICS_GENBANK:case XX_FILE_TYPE_GENOMICS_EMBL:case XX_FILE_TYPE_GENOMICS_SWISSPROT:case XX_FILE_TYPE_ALIGNMENT_CLUSTAL:case XX_FILE_TYPE_ALIGNMENT_STOCKHOLM:case XX_FILE_TYPE_ALIGNMENT_PHYLIP:case XX_FILE_TYPE_ALIGNMENT_MAF:case XX_FILE_TYPE_ALIGNMENT_MAUVE:case XX_FILE_TYPE_ASSEMBLY_GFA:case XX_FILE_TYPE_QUAKE_MD5MESH:case XX_FILE_TYPE_IDTECH_MD5ANIM:return true;default:return false;}}
static bool sx_sciencesequence_build(sx_context*c){if(!c||!c->f||c->size<1||c->size>67108864||xx_pd_is_stopped(c->pd))return false;if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);sxseq_cursor cursor={c,b,c->size,0,0},*q=&cursor;xx_file_type_t type=c->f->file_type;if(ok)switch(type){
case XX_FILE_TYPE_GENOMICS_GENBANK:ok=sx_genomics_genbank_build(q);break;
case XX_FILE_TYPE_GENOMICS_EMBL:ok=sx_genomics_embl_build(q);break;
case XX_FILE_TYPE_GENOMICS_SWISSPROT:ok=sx_genomics_swissprot_build(q);break;
case XX_FILE_TYPE_ALIGNMENT_CLUSTAL:ok=sx_alignment_clustal_build(q);break;
case XX_FILE_TYPE_ALIGNMENT_STOCKHOLM:ok=sx_alignment_stockholm_build(q);break;
case XX_FILE_TYPE_ALIGNMENT_PHYLIP:ok=sx_alignment_phylip_build(q);break;
case XX_FILE_TYPE_ALIGNMENT_MAF:ok=sx_alignment_maf_build(q);break;
case XX_FILE_TYPE_ALIGNMENT_MAUVE:ok=sx_alignment_mauve_build(q);break;
case XX_FILE_TYPE_ASSEMBLY_GFA:ok=sx_assembly_gfa_build(q);break;
case XX_FILE_TYPE_QUAKE_MD5MESH:ok=sx_quake_md5mesh_build(q);break;
case XX_FILE_TYPE_IDTECH_MD5ANIM:ok=sx_idtech_md5anim_build(q);break;
default:ok=false;break;}xx_mem_free(b);return ok&&sxseq_finish(c);}
#undef SEQ_EMIT
#undef SEQ_COL
const sx_family sx_sciencesequence_family={sx_sciencesequence_supports,sx_sciencesequence_build,sx_sciencesequence_layouts,SX_COUNT(sx_sciencesequence_layouts),sx_sciencesequence_comment};
