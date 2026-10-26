/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical game resource metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_mediaextra.h"
static const xx_data_struct_field_desc sxmx_cflyt_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("section_count","uint32",16,4,SX_COUNT_PROP),
};
const sx_layout sxmx_cflyt_header_le={UINT32_C(0x602E0024),"cflyt_header_le",sxmx_cflyt_header_le_fields,SX_COUNT(sxmx_cflyt_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_bflyt_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("section_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",18,2,SX_NONE),
};
static const sx_layout sxmx_bflyt_header_le={UINT32_C(0x602E0025),"bflyt_header_le",sxmx_bflyt_header_le_fields,SX_COUNT(sxmx_bflyt_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_section_le_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxmx_section_le={UINT32_C(0x602E0026),"section_le",sxmx_section_le_fields,SX_COUNT(sxmx_section_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_nw_layout_le_fields[]={
 SX_FIELD("draw_from_center","uint8",0,1,SX_FLAGS),
 SX_FIELD("padding","bytes",1,3,SX_NONE),
 SX_FIELD("width","float",4,4,SX_NONE),
 SX_FIELD("height","float",8,4,SX_NONE),
};
static const sx_layout sxmx_nw_layout_le={UINT32_C(0x602E0027),"nw_layout_le",sxmx_nw_layout_le_fields,SX_COUNT(sxmx_nw_layout_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_clyt_layout_le_fields[]={
 SX_FIELD("screen_origin","uint32",0,4,SX_ID),
 SX_FIELD("width","float",4,4,SX_NONE),
 SX_FIELD("height","float",8,4,SX_NONE),
};
static const sx_layout sxmx_clyt_layout_le={UINT32_C(0x602E0028),"clyt_layout_le",sxmx_clyt_layout_le_fields,SX_COUNT(sxmx_clyt_layout_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_nw_names_le_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_nw_names_le={UINT32_C(0x602E0029),"nw_names_le",sxmx_nw_names_le_fields,SX_COUNT(sxmx_nw_names_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_nw_name_offset_le_fields[]={
 SX_FIELD("name_relative","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_nw_name_offset_le={UINT32_C(0x602E002A),"nw_name_offset_le",sxmx_nw_name_offset_le_fields,SX_COUNT(sxmx_nw_name_offset_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_cflyt_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("section_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_cflyt_header_be={UINT32_C(0x602E002B),"cflyt_header_be",sxmx_cflyt_header_be_fields,SX_COUNT(sxmx_cflyt_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bflyt_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("section_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",18,2,SX_NONE),
};
static const sx_layout sxmx_bflyt_header_be={UINT32_C(0x602E002C),"bflyt_header_be",sxmx_bflyt_header_be_fields,SX_COUNT(sxmx_bflyt_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_section_be_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxmx_section_be={UINT32_C(0x602E002D),"section_be",sxmx_section_be_fields,SX_COUNT(sxmx_section_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_layout_be_fields[]={
 SX_FIELD("draw_from_center","uint8",0,1,SX_FLAGS),
 SX_FIELD("padding","bytes",1,3,SX_NONE),
 SX_FIELD("width","float",4,4,SX_NONE),
 SX_FIELD("height","float",8,4,SX_NONE),
};
static const sx_layout sxmx_nw_layout_be={UINT32_C(0x602E002E),"nw_layout_be",sxmx_nw_layout_be_fields,SX_COUNT(sxmx_nw_layout_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_clyt_layout_be_fields[]={
 SX_FIELD("screen_origin","uint32",0,4,SX_ID),
 SX_FIELD("width","float",4,4,SX_NONE),
 SX_FIELD("height","float",8,4,SX_NONE),
};
static const sx_layout sxmx_clyt_layout_be={UINT32_C(0x602E002F),"clyt_layout_be",sxmx_clyt_layout_be_fields,SX_COUNT(sxmx_clyt_layout_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_names_be_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_nw_names_be={UINT32_C(0x602E0030),"nw_names_be",sxmx_nw_names_be_fields,SX_COUNT(sxmx_nw_names_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_name_offset_be_fields[]={
 SX_FIELD("name_relative","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmx_nw_name_offset_be={UINT32_C(0x602E0031),"nw_name_offset_be",sxmx_nw_name_offset_be_fields,SX_COUNT(sxmx_nw_name_offset_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("header_size","uint16",12,2,SX_SIZE),
 SX_FIELD("section_count","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxmx_nw_header={UINT32_C(0x602E0032),"nw_header",sxmx_nw_header_fields,SX_COUNT(sxmx_nw_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_pane_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("origin","uint8",1,1,SX_ID),
 SX_FIELD("alpha","uint8",2,1,SX_NONE),
 SX_FIELD("user_flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("name","char[16]",4,16,SX_STRING),
 SX_FIELD("user_data","char[8]",20,8,SX_STRING),
 SX_FIELD("translation_x","float",28,4,SX_NONE),
 SX_FIELD("translation_y","float",32,4,SX_NONE),
 SX_FIELD("translation_z","float",36,4,SX_NONE),
 SX_FIELD("rotation_x","float",40,4,SX_NONE),
 SX_FIELD("rotation_y","float",44,4,SX_NONE),
 SX_FIELD("rotation_z","float",48,4,SX_NONE),
 SX_FIELD("scale_x","float",52,4,SX_NONE),
 SX_FIELD("scale_y","float",56,4,SX_NONE),
 SX_FIELD("width","float",60,4,SX_NONE),
 SX_FIELD("height","float",64,4,SX_NONE),
};
static const sx_layout sxmx_nw_pane={UINT32_C(0x602E0033),"nw_pane",sxmx_nw_pane_fields,SX_COUNT(sxmx_nw_pane_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_legacy_names_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",2,2,SX_NONE),
};
static const sx_layout sxmx_nw_legacy_names={UINT32_C(0x602E0034),"nw_legacy_names",sxmx_nw_legacy_names_fields,SX_COUNT(sxmx_nw_legacy_names_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_legacy_name_fields[]={
 SX_FIELD("name_relative","uint32",0,4,SX_OFFSET),
 SX_FIELD("type","uint8",4,1,SX_ID),
 SX_FIELD("padding","bytes",5,3,SX_NONE),
};
static const sx_layout sxmx_nw_legacy_name={UINT32_C(0x602E0035),"nw_legacy_name",sxmx_nw_legacy_name_fields,SX_COUNT(sxmx_nw_legacy_name_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_group_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_STRING),
 SX_FIELD("pane_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",18,2,SX_NONE),
};
static const sx_layout sxmx_nw_group={UINT32_C(0x602E0036),"nw_group",sxmx_nw_group_fields,SX_COUNT(sxmx_nw_group_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_nw_pane_reference_fields[]={
 SX_FIELD("pane_name","char[16]",0,16,SX_STRING),
};
static const sx_layout sxmx_nw_pane_reference={UINT32_C(0x602E0037),"nw_pane_reference",sxmx_nw_pane_reference_fields,SX_COUNT(sxmx_nw_pane_reference_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_j3d_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("section_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("opaque_creator","bytes",16,16,SX_NONE),
};
const sx_layout sxmx_j3d_header={UINT32_C(0x602E003A),"j3d_header",sxmx_j3d_header_fields,SX_COUNT(sxmx_j3d_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bfres_dictionary_fields[]={
 SX_FIELD("dictionary_size","uint32",0,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmx_bfres_dictionary={UINT32_C(0x602E004A),"bfres_dictionary",sxmx_bfres_dictionary_fields,SX_COUNT(sxmx_bfres_dictionary_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bfres_node_fields[]={
 SX_FIELD("reference_bit","uint32",0,4,SX_NONE),
 SX_FIELD("left_index","uint16",4,2,SX_ID),
 SX_FIELD("right_index","uint16",6,2,SX_ID),
 SX_FIELD("name_relative","int32",8,4,SX_OFFSET),
 SX_FIELD("data_relative","int32",12,4,SX_OFFSET),
};
const sx_layout sxmx_bfres_node={UINT32_C(0x602E004B),"bfres_node",sxmx_bfres_node_fields,SX_COUNT(sxmx_bfres_node_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_psx_chunk_fields[]={
 SX_FIELD("name","char[20]",0,20,SX_ID),
 SX_FIELD("type_flags","int32",20,4,SX_FLAGS),
 SX_FIELD("entry_size","int32",24,4,SX_SIZE),
 SX_FIELD("entry_count","int32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_psx_chunk={UINT32_C(0x602E0092),"psx_chunk",sxmx_psx_chunk_fields,SX_COUNT(sxmx_psx_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psx_bone_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("flags","int32",64,4,SX_FLAGS),
 SX_FIELD("child_count","int32",68,4,SX_COUNT_PROP),
 SX_FIELD("parent_index","int32",72,4,SX_ID),
 SX_FIELD("rotation_x","float",76,4,SX_NONE),
 SX_FIELD("rotation_y","float",80,4,SX_NONE),
 SX_FIELD("rotation_z","float",84,4,SX_NONE),
 SX_FIELD("rotation_w","float",88,4,SX_NONE),
 SX_FIELD("location_x","float",92,4,SX_NONE),
 SX_FIELD("location_y","float",96,4,SX_NONE),
 SX_FIELD("location_z","float",100,4,SX_NONE),
 SX_FIELD("length","float",104,4,SX_NONE),
 SX_FIELD("size_x","float",108,4,SX_NONE),
 SX_FIELD("size_y","float",112,4,SX_NONE),
 SX_FIELD("size_z","float",116,4,SX_NONE),
};
static const sx_layout sxmx_psx_bone={UINT32_C(0x602E0093),"psx_bone",sxmx_psx_bone_fields,SX_COUNT(sxmx_psx_bone_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_point_fields[]={
 SX_FIELD("x","float",0,4,SX_NONE),
 SX_FIELD("y","float",4,4,SX_NONE),
 SX_FIELD("z","float",8,4,SX_NONE),
};
static const sx_layout sxmx_psk_point={UINT32_C(0x602E0094),"psk_point",sxmx_psk_point_fields,SX_COUNT(sxmx_psk_point_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_wedge_fields[]={
 SX_FIELD("point_index","uint32",0,4,SX_ID),
 SX_FIELD("u","float",4,4,SX_NONE),
 SX_FIELD("v","float",8,4,SX_NONE),
 SX_FIELD("material_index","uint8",12,1,SX_ID),
 SX_FIELD("reserved","int8",13,1,SX_RESERVED),
 SX_FIELD("padding","int16",14,2,SX_NONE),
};
static const sx_layout sxmx_psk_wedge={UINT32_C(0x602E0095),"psk_wedge",sxmx_psk_wedge_fields,SX_COUNT(sxmx_psk_wedge_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_face_fields[]={
 SX_FIELD("wedge0","uint16",0,2,SX_ID),
 SX_FIELD("wedge1","uint16",2,2,SX_ID),
 SX_FIELD("wedge2","uint16",4,2,SX_ID),
 SX_FIELD("material_index","uint8",6,1,SX_ID),
 SX_FIELD("auxiliary_material","uint8",7,1,SX_ID),
 SX_FIELD("smoothing_groups","int32",8,4,SX_FLAGS),
};
static const sx_layout sxmx_psk_face={UINT32_C(0x602E0096),"psk_face",sxmx_psk_face_fields,SX_COUNT(sxmx_psk_face_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_material_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("texture_index","int32",64,4,SX_ID),
 SX_FIELD("polygon_flags","int32",68,4,SX_FLAGS),
 SX_FIELD("auxiliary_material","int32",72,4,SX_ID),
 SX_FIELD("auxiliary_flags","int32",76,4,SX_FLAGS),
 SX_FIELD("lod_bias","int32",80,4,SX_NONE),
 SX_FIELD("lod_style","int32",84,4,SX_ID),
};
static const sx_layout sxmx_psk_material={UINT32_C(0x602E0097),"psk_material",sxmx_psk_material_fields,SX_COUNT(sxmx_psk_material_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psk_weight_fields[]={
 SX_FIELD("weight","float",0,4,SX_NONE),
 SX_FIELD("point_index","int32",4,4,SX_ID),
 SX_FIELD("bone_index","int32",8,4,SX_ID),
};
static const sx_layout sxmx_psk_weight={UINT32_C(0x602E0098),"psk_weight",sxmx_psk_weight_fields,SX_COUNT(sxmx_psk_weight_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psa_sequence_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("group","char[64]",64,64,SX_STRING),
 SX_FIELD("bone_count","int32",128,4,SX_COUNT_PROP),
 SX_FIELD("root_include","int32",132,4,SX_FLAGS),
 SX_FIELD("compression_style","int32",136,4,SX_ID),
 SX_FIELD("key_quotum","int32",140,4,SX_COUNT_PROP),
 SX_FIELD("key_reduction","float",144,4,SX_NONE),
 SX_FIELD("track_time","float",148,4,SX_NONE),
 SX_FIELD("frames_per_second","float",152,4,SX_NONE),
 SX_FIELD("start_bone","int32",156,4,SX_ID),
 SX_FIELD("first_frame","int32",160,4,SX_ID),
 SX_FIELD("frame_count","int32",164,4,SX_COUNT_PROP),
};
static const sx_layout sxmx_psa_sequence={UINT32_C(0x602E0099),"psa_sequence",sxmx_psa_sequence_fields,SX_COUNT(sxmx_psa_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_psa_key_fields[]={
 SX_FIELD("location_x","float",0,4,SX_NONE),
 SX_FIELD("location_y","float",4,4,SX_NONE),
 SX_FIELD("location_z","float",8,4,SX_NONE),
 SX_FIELD("rotation_x","float",12,4,SX_NONE),
 SX_FIELD("rotation_y","float",16,4,SX_NONE),
 SX_FIELD("rotation_z","float",20,4,SX_NONE),
 SX_FIELD("rotation_w","float",24,4,SX_NONE),
 SX_FIELD("time","float",28,4,SX_NONE),
};
static const sx_layout sxmx_psa_key={UINT32_C(0x602E009A),"psa_key",sxmx_psa_key_fields,SX_COUNT(sxmx_psa_key_fields),SX_LE};
static const sx_layout *const sx_mediaextra_layouts[]={
 &sxmx_lab_header,
 &sxmx_lab_entry,
 &sxmx_bun_header,
 &sxmx_bun_lb83_entry,
 &sxmx_bun_lb23_entry,
 &sxmx_mhk_header,
 &sxmx_mhk_directory,
 &sxmx_mhk_type,
 &sxmx_mhk_count32,
 &sxmx_mhk_count16,
 &sxmx_mhk_file,
 &sxmx_mhk_resource,
 &sxmx_mhk_name,
 &sxmx_pod2_header,
 &sxmx_pod2_entry,
 &sxmx_pod2_audit,
 &sxmx_vpp3_header_le,
 &sxmx_vpp3_entry_le,
 &sxmx_vpp3_header_be,
 &sxmx_vpp3_entry_be,
 &sxmx_myp_header,
 &sxmx_myp_block,
 &sxmx_myp_entry,
 &sxmx_rez_header,
 &sxmx_rez_directory_entry,
 &sxmx_rez_resource_entry,
 &sxmx_rez_key,
 &sxmx_hpak_header,
 &sxmx_hpak_directory,
 &sxmx_hpak_entry,
 &sxmx_brres_header,
 &sxmx_brres_root,
 &sxmx_brres_dictionary,
 &sxmx_brres_node,
 &sxmx_brres_resource,
 &sxmx_cflyt_header_le,
 &sxmx_bflyt_header_le,
 &sxmx_section_le,
 &sxmx_nw_layout_le,
 &sxmx_clyt_layout_le,
 &sxmx_nw_names_le,
 &sxmx_nw_name_offset_le,
 &sxmx_cflyt_header_be,
 &sxmx_bflyt_header_be,
 &sxmx_section_be,
 &sxmx_nw_layout_be,
 &sxmx_clyt_layout_be,
 &sxmx_nw_names_be,
 &sxmx_nw_name_offset_be,
 &sxmx_nw_header,
 &sxmx_nw_pane,
 &sxmx_nw_legacy_names,
 &sxmx_nw_legacy_name,
 &sxmx_nw_group,
 &sxmx_nw_pane_reference,
 &sxmx_chunky_header,
 &sxmx_chunky_chunk,
 &sxmx_j3d_header,
 &sxmx_btk_ttk1,
 &sxmx_btk_selection,
 &sxmx_btk_remap,
 &sxmx_btk_texture_matrix_index,
 &sxmx_btk_float,
 &sxmx_btk_rotation,
 &sxmx_j3d_name_table,
 &sxmx_j3d_name,
 &sxmx_brlan_pai1,
 &sxmx_brlan_binding,
 &sxmx_brlan_group,
 &sxmx_brlan_track,
 &sxmx_brlan_key,
 &sxmx_relative_offset_be,
 &sxmx_bfres_header,
 &sxmx_bfres_dictionary,
 &sxmx_bfres_node,
 &sxmx_bfres_external,
 &sxmx_cgfx_slot,
 &sxmx_cgfx_dictionary,
 &sxmx_cgfx_node,
 &sxmx_unity_header,
 &sxmx_unity_metadata_flags,
 &sxmx_unity_type,
 &sxmx_unity_object_count,
 &sxmx_unity_object,
 &sxmx_unity_tail_counts,
 &sxmx_ue1_header,
 &sxmx_ue1_name_flags,
 &sxmx_ue1_heritage,
 &sxmx_sga6_header,
 &sxmx_sga6_table_slot,
 &sxmx_sga6_drive,
 &sxmx_sga6_folder,
 &sxmx_sga6_file,
 &sxmx_byaml_header_le,
 &sxmx_byaml_node_le,
 &sxmx_byaml_string_offset_le,
 &sxmx_byaml_map_key_le,
 &sxmx_byaml_array_kind_le,
 &sxmx_byaml_string_le,
 &sxmx_byaml_bool_le,
 &sxmx_byaml_int_le,
 &sxmx_byaml_float_le,
 &sxmx_byaml_uint_le,
 &sxmx_byaml_node_value_le,
 &sxmx_byaml_null_le,
 &sxmx_byaml_header_be,
 &sxmx_byaml_node_be,
 &sxmx_byaml_string_offset_be,
 &sxmx_byaml_map_key_be,
 &sxmx_byaml_array_kind_be,
 &sxmx_byaml_string_be,
 &sxmx_byaml_bool_be,
 &sxmx_byaml_int_be,
 &sxmx_byaml_float_be,
 &sxmx_byaml_uint_be,
 &sxmx_byaml_node_value_be,
 &sxmx_byaml_null_be,
 &sxmx_fsha_header,
 &sxmx_fsha_string_length,
 &sxmx_fsha_model,
 &sxmx_fsha_program,
 &sxmx_fsha_vertex_shader,
 &sxmx_fsha_pixel_shader,
 &sxmx_utf_header,
 &sxmx_utf_column,
 &sxmx_utf_u8,
 &sxmx_utf_i8,
 &sxmx_utf_u16,
 &sxmx_utf_i16,
 &sxmx_utf_u32,
 &sxmx_utf_i32,
 &sxmx_utf_u64,
 &sxmx_utf_i64,
 &sxmx_utf_float,
 &sxmx_utf_double,
 &sxmx_utf_string,
 &sxmx_utf_binary,
 &sxmx_utf_guid,
 &sxmx_iqm_header,
 &sxmx_iqm_mesh,
 &sxmx_iqm_vertex_array,
 &sxmx_iqm_triangle,
 &sxmx_iqm_adjacency,
 &sxmx_iqm_float,
 &sxmx_iqm_color,
 &sxmx_psx_chunk,
 &sxmx_psx_bone,
 &sxmx_psk_point,
 &sxmx_psk_wedge,
 &sxmx_psk_face,
 &sxmx_psk_material,
 &sxmx_psk_weight,
 &sxmx_psa_sequence,
 &sxmx_psa_key,
};
bool sxmx_need(sxmx_view *v,size_t at,uint64_t n,size_t end){return !xx_pd_is_stopped(v->c->pd)&&end<=v->n&&at<=end&&n<=end-at;}
uint16_t sxmx_u16(const uint8_t*p,bool be){return xx_data_get_u16(p,2,0,be);}
uint32_t sxmx_u32(const uint8_t*p,bool be){return xx_data_get_u32(p,4,0,be);}
bool sxmx_row(sxmx_view *v,const sx_layout*l,size_t at,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t n=(size_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxmx_need(v,at,n,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)n);}
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
bool sxmx_table(sxmx_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t z=(size_t)(f->rel_offset+f->size);if(count>4000000||!sxmx_need(v,at,count*z,end))return false;for(uint64_t i=0;i<count;i++,at+=z)if(!sxmx_row(v,l,at,end))return false;return true;}
static int sxmx_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmx_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmx_order);
 /* Native readers can permit shared descriptor ranges. Keep one physical interpretation;
  * never repeat identical source bytes as overlapping structures. */
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmx_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxmx_cstr(sxmx_view*v,size_t*at,size_t end){size_t n=0;while(*at<end&&n<4096&&sxmx_need(v,*at,1,end)){if(!v->p[(*at)++])return true;n++;}return false;}
bool sxmx_nw(sxmx_view*v)
{xx_file_type_t t=v->c->f->file_type;bool legacy=t==XX_FILE_TYPE_NINTENDO_BRLYT,fly=t==XX_FILE_TYPE_NINTENDO_BFLYT,be=legacy||(v->n>=6&&v->p[4]==0xfe);const sx_layout*head=legacy?&sxmx_nw_header:fly?(be?&sxmx_bflyt_header_be:&sxmx_bflyt_header_le):(be?&sxmx_cflyt_header_be:&sxmx_cflyt_header_le);if(!sxmx_row(v,head,0,v->n))return false;size_t at=legacy?16:20;uint32_t n=legacy?sxmx_u16(v->p+14,true):fly?sxmx_u16(v->p+16,be):sxmx_u32(v->p+16,be);if(n>4096)return false;for(uint32_t i=0;i<n;i++){if(!sxmx_need(v,at,8,v->n))return false;size_t size=sxmx_u32(v->p+at+4,be);if(size<8||!sxmx_need(v,at,size,v->n)||!sxmx_row(v,be?&sxmx_section_be:&sxmx_section_le,at,at+size))return false;size_t end=at+size;const uint8_t*p=v->p+at;if(!xx_rt_memcmp(p,"lyt1",4)){const sx_layout*l=legacy||fly?(be?&sxmx_nw_layout_be:&sxmx_nw_layout_le):(be?&sxmx_clyt_layout_be:&sxmx_clyt_layout_le);if(!sxmx_row(v,l,at+8,end))return false;}else if(legacy&&!xx_rt_memcmp(p,"pan1",4)){if(!SM_ROW(nw_pane,at+8,end))return false;}else if(!xx_rt_memcmp(p,"txl1",4)||!xx_rt_memcmp(p,"fnl1",4)){const sx_layout*l=legacy?&sxmx_nw_legacy_names:be?&sxmx_nw_names_be:&sxmx_nw_names_le;if(!sxmx_row(v,l,at+8,end))return false;uint32_t num=legacy?sxmx_u16(p+8,true):sxmx_u32(p+8,be);if(!sxmx_table(v,legacy?&sxmx_nw_legacy_name:be?&sxmx_nw_name_offset_be:&sxmx_nw_name_offset_le,at+12,num,end))return false;}else if(legacy&&!xx_rt_memcmp(p,"grp1",4)){if(!SM_ROW(nw_group,at+8,end)||!sxmx_table(v,&sxmx_nw_pane_reference,at+28,sxmx_u16(p+24,true),end))return false;}at=end;}return at==v->n;}
bool sxmx_relative(sxmx_view*v,size_t word,bool be,size_t*target)
{if(!sxmx_need(v,word,4,v->n))return false;int64_t at=(int64_t)word+(int32_t)sxmx_u32(v->p+word,be);if(at<0||(uint64_t)at>v->n)return false;*target=(size_t)at;return true;}
bool sxmx_psx(sxmx_view*v)
{size_t at=0;while(at<v->n){if(!SM_ROW(psx_chunk,at,v->n))return false;const uint8_t*p=v->p+at;uint32_t size=sxmx_u32(p+24,false),n=sxmx_u32(p+28,false);const sx_layout*l=NULL;if(!xx_rt_memcmp(p,"PNTS0000",8))l=&sxmx_psk_point;else if(!xx_rt_memcmp(p,"VTXW0000",8))l=&sxmx_psk_wedge;else if(!xx_rt_memcmp(p,"FACE0000",8))l=&sxmx_psk_face;else if(!xx_rt_memcmp(p,"MATT0000",8))l=&sxmx_psk_material;else if(!xx_rt_memcmp(p,"REFSKELT",8)||!xx_rt_memcmp(p,"BONENAMES",9))l=&sxmx_psx_bone;else if(!xx_rt_memcmp(p,"RAWWEIGHTS",10))l=&sxmx_psk_weight;else if(!xx_rt_memcmp(p,"ANIMINFO",8))l=&sxmx_psa_sequence;else if(!xx_rt_memcmp(p,"ANIMKEYS",8))l=&sxmx_psa_key;at+=32;if(!sxmx_need(v,at,(uint64_t)n*size,v->n))return false;if(l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;if((uint64_t)(f->rel_offset+f->size)!=size||!sxmx_table(v,l,at,n,v->n))return false;}at+=(size_t)n*size;}return true;}
static bool sx_mediaextra_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_LUCAS_LAB:
case XX_FILE_TYPE_LUCAS_BUN:
case XX_FILE_TYPE_MOHAWK_MHK:
case XX_FILE_TYPE_NINTENDO_BRRES:
case XX_FILE_TYPE_TERMINALREALITY_POD:
case XX_FILE_TYPE_VOLITION_VPP:
case XX_FILE_TYPE_MYTHIC_MYP:
case XX_FILE_TYPE_LITHTECH_REZ:
case XX_FILE_TYPE_VALVE_HPAK:
case XX_FILE_TYPE_UNREAL_PACKAGE:
case XX_FILE_TYPE_NINTENDO_BFRES:
case XX_FILE_TYPE_NINTENDO_BFLYT:
case XX_FILE_TYPE_NINTENDO_BCLYT:
case XX_FILE_TYPE_RELIC_SGA:
case XX_FILE_TYPE_UNITY_SERIALIZED:
case XX_FILE_TYPE_NINTENDO_CGFX:
case XX_FILE_TYPE_NINTENDO_BYAML:
case XX_FILE_TYPE_RELIC_CHUNKY:
case XX_FILE_TYPE_NINTENDO_J3D_BMD:
case XX_FILE_TYPE_NINTENDO_J3D_BTK:
case XX_FILE_TYPE_NINTENDO_BRLYT:
case XX_FILE_TYPE_NINTENDO_BRLAN:
case XX_FILE_TYPE_NINTENDO_BFSHA:
case XX_FILE_TYPE_CRI_UTF:
case XX_FILE_TYPE_IDTECH_IQM:
case XX_FILE_TYPE_UNREAL_PSK:
case XX_FILE_TYPE_UNREAL_PSA:
return true;default:return false;}}
static bool sx_mediaextra_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>134217728)return false;sxmx_view view={c,NULL,(size_t)c->size,0},*v=&view;v->p=(uint8_t*)xx_mem_alloc(v->n);if(!v->p||!sx_read(c,0,v->p,v->n)){xx_mem_free(v->p);return false;}bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_LUCAS_LAB:ok=sx_lucas_lab_build(v);break;
case XX_FILE_TYPE_LUCAS_BUN:ok=sx_lucas_bun_build(v);break;
case XX_FILE_TYPE_MOHAWK_MHK:ok=sx_mohawk_mhk_build(v);break;
case XX_FILE_TYPE_NINTENDO_BRRES:ok=sx_nintendo_brres_build(v);break;
case XX_FILE_TYPE_TERMINALREALITY_POD:ok=sx_terminalreality_pod_build(v);break;
case XX_FILE_TYPE_VOLITION_VPP:ok=sx_volition_vpp_build(v);break;
case XX_FILE_TYPE_MYTHIC_MYP:ok=sx_mythic_myp_build(v);break;
case XX_FILE_TYPE_LITHTECH_REZ:ok=sx_lithtech_rez_build(v);break;
case XX_FILE_TYPE_VALVE_HPAK:ok=sx_valve_hpak_build(v);break;
case XX_FILE_TYPE_UNREAL_PACKAGE:ok=sx_unreal_package_build(v);break;
case XX_FILE_TYPE_NINTENDO_BFRES:ok=sx_nintendo_bfres_build(v);break;
case XX_FILE_TYPE_NINTENDO_BFLYT:ok=sx_nintendo_bflyt_build(v);break;
case XX_FILE_TYPE_NINTENDO_BCLYT:ok=sx_nintendo_bclyt_build(v);break;
case XX_FILE_TYPE_RELIC_SGA:ok=sx_relic_sga_build(v);break;
case XX_FILE_TYPE_UNITY_SERIALIZED:ok=sx_unity_serialized_build(v);break;
case XX_FILE_TYPE_NINTENDO_CGFX:ok=sx_nintendo_cgfx_build(v);break;
case XX_FILE_TYPE_NINTENDO_BYAML:ok=sx_nintendo_byaml_build(v);break;
case XX_FILE_TYPE_RELIC_CHUNKY:ok=sx_relic_chunky_build(v);break;
case XX_FILE_TYPE_NINTENDO_J3D_BMD:ok=sx_nintendo_j3d_bmd_build(v);break;
case XX_FILE_TYPE_NINTENDO_J3D_BTK:ok=sx_nintendo_j3d_btk_build(v);break;
case XX_FILE_TYPE_NINTENDO_BRLYT:ok=sx_nintendo_brlyt_build(v);break;
case XX_FILE_TYPE_NINTENDO_BRLAN:ok=sx_nintendo_brlan_build(v);break;
case XX_FILE_TYPE_NINTENDO_BFSHA:ok=sx_nintendo_bfsha_build(v);break;
case XX_FILE_TYPE_CRI_UTF:ok=sx_cri_utf_build(v);break;
case XX_FILE_TYPE_IDTECH_IQM:ok=sx_idtech_iqm_build(v);break;
case XX_FILE_TYPE_UNREAL_PSK:ok=sx_unreal_psk_build(v);break;
case XX_FILE_TYPE_UNREAL_PSA:ok=sx_unreal_psa_build(v);break;
default:break;}
 xx_mem_free(v->p);return ok&&sxmx_finish(c);}
#undef SM_ROW
static bool sx_mediaextra_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x602e0000)||id>=UINT32_C(0x602f0000))return true;
 if(id==1613627408u&&!xx_rt_wcscmp(r->name,L"action")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"ADD");
 case 1u:return xx_data_struct_record_set_comment(r,L"REMOVE");
 case 2u:return xx_data_struct_record_set_comment(r,L"CHANGE");
 default:break;}}
 if(id==1613627415u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"ZLIB");
 default:break;}}
 if(id==1613627417u&&!xx_rt_wcscmp(r->name,L"kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 1u:return xx_data_struct_record_set_comment(r,L"DIRECTORY");
 default:break;}}
 if(id==1613627418u&&!xx_rt_wcscmp(r->name,L"kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"RESOURCE");
 default:break;}}
 if(id==1613627422u&&!xx_rt_wcscmp(r->name,L"resource_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SOUND");
 case 1u:return xx_data_struct_record_set_comment(r,L"SKIN");
 case 2u:return xx_data_struct_record_set_comment(r,L"MODEL");
 case 3u:return xx_data_struct_record_set_comment(r,L"DECAL");
 case 4u:return xx_data_struct_record_set_comment(r,L"GENERIC");
 case 5u:return xx_data_struct_record_set_comment(r,L"EVENTSCRIPT");
 case 6u:return xx_data_struct_record_set_comment(r,L"WORLD");
 default:break;}}
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"byte_order")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"LITTLE_ENDIAN");
 case 1u:return xx_data_struct_record_set_comment(r,L"BIG_ENDIAN");
 default:break;}}
 if(id==1613627462u&&!xx_rt_wcscmp(r->name,L"curve_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 2u:return xx_data_struct_record_set_comment(r,L"HERMITE");
 default:break;}}
 if(id==1613627462u&&!xx_rt_wcscmp(r->name,L"channel")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"TRANSLATION_X");
 case 1u:return xx_data_struct_record_set_comment(r,L"TRANSLATION_Y");
 case 2u:return xx_data_struct_record_set_comment(r,L"TRANSLATION_Z");
 case 3u:return xx_data_struct_record_set_comment(r,L"ROTATION_X");
 case 4u:return xx_data_struct_record_set_comment(r,L"ROTATION_Y");
 case 5u:return xx_data_struct_record_set_comment(r,L"ROTATION_Z");
 case 6u:return xx_data_struct_record_set_comment(r,L"SCALE_X");
 case 7u:return xx_data_struct_record_set_comment(r,L"SCALE_Y");
 case 8u:return xx_data_struct_record_set_comment(r,L"WIDTH");
 case 9u:return xx_data_struct_record_set_comment(r,L"HEIGHT");
 default:break;}}
 if(id==1613627487u&&!xx_rt_wcscmp(r->name,L"kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP");
 case 194u:return xx_data_struct_record_set_comment(r,L"STRING_TABLE");
 default:break;}}
 if(id==1613627489u&&!xx_rt_wcscmp(r->name,L"value_kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 160u:return xx_data_struct_record_set_comment(r,L"STRING_INDEX");
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY_OFFSET");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP_OFFSET");
 case 208u:return xx_data_struct_record_set_comment(r,L"BOOLEAN");
 case 209u:return xx_data_struct_record_set_comment(r,L"INT32");
 case 210u:return xx_data_struct_record_set_comment(r,L"FLOAT32");
 case 211u:return xx_data_struct_record_set_comment(r,L"UINT32");
 case 255u:return xx_data_struct_record_set_comment(r,L"NULL");
 default:break;}}
 if(id==1613627490u&&!xx_rt_wcscmp(r->name,L"value_kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 160u:return xx_data_struct_record_set_comment(r,L"STRING_INDEX");
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY_OFFSET");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP_OFFSET");
 case 208u:return xx_data_struct_record_set_comment(r,L"BOOLEAN");
 case 209u:return xx_data_struct_record_set_comment(r,L"INT32");
 case 210u:return xx_data_struct_record_set_comment(r,L"FLOAT32");
 case 211u:return xx_data_struct_record_set_comment(r,L"UINT32");
 case 255u:return xx_data_struct_record_set_comment(r,L"NULL");
 default:break;}}
 if(id==1613627492u&&!xx_rt_wcscmp(r->name,L"value")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"FALSE");
 case 1u:return xx_data_struct_record_set_comment(r,L"TRUE");
 default:break;}}
 if(id==1613627499u&&!xx_rt_wcscmp(r->name,L"kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP");
 case 194u:return xx_data_struct_record_set_comment(r,L"STRING_TABLE");
 default:break;}}
 if(id==1613627501u&&!xx_rt_wcscmp(r->name,L"value_kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 160u:return xx_data_struct_record_set_comment(r,L"STRING_INDEX");
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY_OFFSET");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP_OFFSET");
 case 208u:return xx_data_struct_record_set_comment(r,L"BOOLEAN");
 case 209u:return xx_data_struct_record_set_comment(r,L"INT32");
 case 210u:return xx_data_struct_record_set_comment(r,L"FLOAT32");
 case 211u:return xx_data_struct_record_set_comment(r,L"UINT32");
 case 255u:return xx_data_struct_record_set_comment(r,L"NULL");
 default:break;}}
 if(id==1613627502u&&!xx_rt_wcscmp(r->name,L"value_kind")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 160u:return xx_data_struct_record_set_comment(r,L"STRING_INDEX");
 case 192u:return xx_data_struct_record_set_comment(r,L"ARRAY_OFFSET");
 case 193u:return xx_data_struct_record_set_comment(r,L"MAP_OFFSET");
 case 208u:return xx_data_struct_record_set_comment(r,L"BOOLEAN");
 case 209u:return xx_data_struct_record_set_comment(r,L"INT32");
 case 210u:return xx_data_struct_record_set_comment(r,L"FLOAT32");
 case 211u:return xx_data_struct_record_set_comment(r,L"UINT32");
 case 255u:return xx_data_struct_record_set_comment(r,L"NULL");
 default:break;}}
 if(id==1613627504u&&!xx_rt_wcscmp(r->name,L"value")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"FALSE");
 case 1u:return xx_data_struct_record_set_comment(r,L"TRUE");
 default:break;}}
 if(id==1613627452u&&!xx_rt_wcscmp(r->name,L"scale_tangent_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SINGLE_TANGENT");
 case 1u:return xx_data_struct_record_set_comment(r,L"IN_OUT_TANGENTS");
 default:break;}}
 if(id==1613627452u&&!xx_rt_wcscmp(r->name,L"rotation_tangent_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SINGLE_TANGENT");
 case 1u:return xx_data_struct_record_set_comment(r,L"IN_OUT_TANGENTS");
 default:break;}}
 if(id==1613627452u&&!xx_rt_wcscmp(r->name,L"translation_tangent_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"SINGLE_TANGENT");
 case 1u:return xx_data_struct_record_set_comment(r,L"IN_OUT_TANGENTS");
 default:break;}}
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"loop_mode")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"ONCE");
 case 1u:return xx_data_struct_record_set_comment(r,L"ONCE_RESET");
 case 2u:return xx_data_struct_record_set_comment(r,L"REPEAT");
 case 3u:return xx_data_struct_record_set_comment(r,L"MIRRORED_ONCE");
 case 4u:return xx_data_struct_record_set_comment(r,L"MIRRORED_REPEAT");
 default:break;}}
 if(id==1613627533u&&!xx_rt_wcscmp(r->name,L"type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"POSITION");
 case 1u:return xx_data_struct_record_set_comment(r,L"TEXCOORD");
 case 2u:return xx_data_struct_record_set_comment(r,L"NORMAL");
 case 3u:return xx_data_struct_record_set_comment(r,L"TANGENT");
 case 4u:return xx_data_struct_record_set_comment(r,L"BLEND_INDICES");
 case 5u:return xx_data_struct_record_set_comment(r,L"BLEND_WEIGHTS");
 case 6u:return xx_data_struct_record_set_comment(r,L"COLOR");
 default:break;}}
 if(id==1613627533u&&!xx_rt_wcscmp(r->name,L"format")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"BYTE");
 case 1u:return xx_data_struct_record_set_comment(r,L"UBYTE");
 case 2u:return xx_data_struct_record_set_comment(r,L"SHORT");
 case 3u:return xx_data_struct_record_set_comment(r,L"USHORT");
 case 4u:return xx_data_struct_record_set_comment(r,L"INT");
 case 5u:return xx_data_struct_record_set_comment(r,L"UINT");
 case 6u:return xx_data_struct_record_set_comment(r,L"HALF");
 case 7u:return xx_data_struct_record_set_comment(r,L"FLOAT");
 case 8u:return xx_data_struct_record_set_comment(r,L"DOUBLE");
 default:break;}}
 if(id==1613627394u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name table after all directory entries.");
 if(id==1613627394u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627394u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627395u&&!xx_rt_wcscmp(r->name,L"table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627396u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627397u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627398u&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627398u&&!xx_rt_wcscmp(r->name,L"file_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource directory indicated by directory_offset.");
 if(id==1613627399u&&!xx_rt_wcscmp(r->name,L"string_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource directory indicated by directory_offset.");
 if(id==1613627400u&&!xx_rt_wcscmp(r->name,L"resource_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource directory indicated by directory_offset.");
 if(id==1613627400u&&!xx_rt_wcscmp(r->name,L"name_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource directory indicated by directory_offset.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627405u&&!xx_rt_wcscmp(r->name,L"string_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the resource string table, itself relative to the resource directory.");
 if(id==1613627407u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name table immediately following the fixed file-entry array.");
 if(id==1613627407u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627407u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627408u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627408u&&!xx_rt_wcscmp(r->name,L"old_timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627408u&&!xx_rt_wcscmp(r->name,L"new_timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"unknown_150"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"directory_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"names_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"data_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the aligned name table.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"runtime_offset"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the aligned data region after directory and names.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"package_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"unknown_150"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"directory_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"names_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"data_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the aligned name table.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"runtime_offset"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the aligned data region after directory and names.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"package_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627413u&&!xx_rt_wcscmp(r->name,L"first_block_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627414u&&!xx_rt_wcscmp(r->name,L"next_block_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627415u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627416u&&!xx_rt_wcscmp(r->name,L"root_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627416u&&!xx_rt_wcscmp(r->name,L"root_time"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627416u&&!xx_rt_wcscmp(r->name,L"directory_boundary"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627416u&&!xx_rt_wcscmp(r->name,L"unknown_limits"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627417u&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627417u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627418u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627418u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627420u&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627422u&&!xx_rt_wcscmp(r->name,L"next_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627422u&&!xx_rt_wcscmp(r->name,L"previous_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627422u&&!xx_rt_wcscmp(r->name,L"file_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627423u&&!xx_rt_wcscmp(r->name,L"root_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627426u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627426u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the containing resource dictionary, not the pointer word.");
 if(id==1613627426u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the containing resource dictionary, not the pointer word.");
 if(id==1613627427u&&!xx_rt_wcscmp(r->name,L"archive_relative"))return xx_data_struct_record_set_comment(r,L"Signed displacement relative to this resource-section beginning; points back to BRRES header.");
 if(id==1613627434u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement from the beginning of the name-offset table (section byte 12).");
 if(id==1613627441u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement from the beginning of the name-offset table (section byte 12).");
 if(id==1613627445u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement from the beginning of the name-entry table (section byte 12).");
 if(id==1613627448u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627449u&&!xx_rt_wcscmp(r->name,L"unknown1"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627449u&&!xx_rt_wcscmp(r->name,L"unknown2"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627450u&&!xx_rt_wcscmp(r->name,L"opaque_creator"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"animation_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"remap_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"name_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"texture_matrix_index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"center_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"scale_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"rotation_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"translation_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the TTK1 section beginning.");
 if(id==1613627458u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the string-table header, not this entry.");
 if(id==1613627459u&&!xx_rt_wcscmp(r->name,L"binding_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the pai1 section beginning.");
 if(id==1613627460u&&!xx_rt_wcscmp(r->name,L"group_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to this binding record beginning.");
 if(id==1613627462u&&!xx_rt_wcscmp(r->name,L"keys_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to this track record beginning.");
 if(id==1613627464u&&!xx_rt_wcscmp(r->name,L"relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to the owning pai1 section or animation group, according to the enclosing table.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"string_pool_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"model_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"texture_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"skeletal_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"shader_parameter_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"color_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"texture_srt_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"texture_pattern_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"bone_visibility_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"material_visibility_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"shape_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"scene_animation_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"external_file_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627465u&&!xx_rt_wcscmp(r->name,L"user_pointer"))return xx_data_struct_record_set_comment(r,L"Stored runtime pointer/address value; not a file offset.");
 if(id==1613627467u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627467u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627468u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627469u&&!xx_rt_wcscmp(r->name,L"dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627471u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627471u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"legacy_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627476u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to data_offset in the file header.");
 if(id==1613627478u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to null-terminated name strings followed by 32-bit flags.");
 if(id==1613627478u&&!xx_rt_wcscmp(r->name,L"export_offset"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to variable CompactIndex export records; record bodies remain raw.");
 if(id==1613627478u&&!xx_rt_wcscmp(r->name,L"import_offset"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to variable CompactIndex import records; record bodies remain raw.");
 if(id==1613627478u&&!xx_rt_wcscmp(r->name,L"heritage_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627481u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627482u&&!xx_rt_wcscmp(r->name,L"table_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the table region at file byte 152.");
 if(id==1613627483u&&!xx_rt_wcscmp(r->name,L"first_folder"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627483u&&!xx_rt_wcscmp(r->name,L"end_folder"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627483u&&!xx_rt_wcscmp(r->name,L"first_file"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627483u&&!xx_rt_wcscmp(r->name,L"end_file"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name table identified by the fourth table slot.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"first_folder"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"end_folder"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"first_file"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627484u&&!xx_rt_wcscmp(r->name,L"end_file"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627485u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name table identified by the fourth table slot.");
 if(id==1613627485u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to the data region selected in the archive header.");
 if(id==1613627485u&&!xx_rt_wcscmp(r->name,L"timestamp"))return xx_data_struct_record_set_comment(r,L"Unix timestamp in seconds; original signedness and stored value retained.");
 if(id==1613627486u&&!xx_rt_wcscmp(r->name,L"key_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627486u&&!xx_rt_wcscmp(r->name,L"string_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627486u&&!xx_rt_wcscmp(r->name,L"root_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627488u&&!xx_rt_wcscmp(r->name,L"string_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this string/key table beginning; final entry is the end offset.");
 if(id==1613627496u&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to a nested map or array.");
 if(id==1613627498u&&!xx_rt_wcscmp(r->name,L"key_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627498u&&!xx_rt_wcscmp(r->name,L"string_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627498u&&!xx_rt_wcscmp(r->name,L"root_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627500u&&!xx_rt_wcscmp(r->name,L"string_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this string/key table beginning; final entry is the end offset.");
 if(id==1613627508u&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"Absolute byte offset to a nested map or array.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"string_pool_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"path_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"unknown_26"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"unknown_28"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"model_dictionary_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"unknown_30"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627510u&&!xx_rt_wcscmp(r->name,L"unknown_34"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"opaque_0"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"opaque_8"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"opaque_24"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"programs_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"unknown_5c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"archive_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627512u&&!xx_rt_wcscmp(r->name,L"unknown_64"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"opaque_0"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"vertex_shader_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"geometry_shader_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"pixel_shader_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627513u&&!xx_rt_wcscmp(r->name,L"model_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627514u&&!xx_rt_wcscmp(r->name,L"code_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627514u&&!xx_rt_wcscmp(r->name,L"unused_native_metadata"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627515u&&!xx_rt_wcscmp(r->name,L"code_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement relative to the beginning of this pointer word; zero can denote no target.");
 if(id==1613627515u&&!xx_rt_wcscmp(r->name,L"unused_native_metadata"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical bytes; additional semantics are not inferred.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"rows_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to file byte 8, immediately after the @UTF prefix.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"strings_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to file byte 8, immediately after the @UTF prefix.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to file byte 8, immediately after the @UTF prefix.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"table_name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool.");
 if(id==1613627517u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool.");
 if(id==1613627528u&&!xx_rt_wcscmp(r->name,L"string_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF string pool.");
 if(id==1613627529u&&!xx_rt_wcscmp(r->name,L"data_relative"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the UTF binary-data region.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"text_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"mesh_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"vertex_array_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"triangle_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"adjacency_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"joint_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"pose_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"animation_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"frame_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"bounds_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"comment_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627531u&&!xx_rt_wcscmp(r->name,L"extension_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627532u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the IQM text table.");
 if(id==1613627532u&&!xx_rt_wcscmp(r->name,L"material_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the IQM text table.");
 if(id==1613627532u&&!xx_rt_wcscmp(r->name,L"first_vertex"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627532u&&!xx_rt_wcscmp(r->name,L"first_triangle"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627533u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of the source file.");
 if(id==1613627545u&&!xx_rt_wcscmp(r->name,L"first_frame"))return xx_data_struct_record_set_comment(r,L"Table element index; not a byte offset. End indexes are exclusive.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"size_low16"))return xx_data_struct_record_set_comment(r,L"Bits 0..15 of the encoded 27-bit file byte length.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"size_high8"))return xx_data_struct_record_set_comment(r,L"Bits 16..23 of the encoded file byte length.");
 if(id==1613627403u&&!xx_rt_wcscmp(r->name,L"size_high3_and_flags"))return xx_data_struct_record_set_comment(r,L"Low 3 bits provide byte-length bits 24..26; high 5 bits are flags.");
 if(id==1613627404u&&!xx_rt_wcscmp(r->name,L"file_index"))return xx_data_struct_record_set_comment(r,L"One-based index in the file table.");
 if(id==1613627405u&&!xx_rt_wcscmp(r->name,L"file_index"))return xx_data_struct_record_set_comment(r,L"One-based index in the file table.");
 if(id==1613627406u&&!xx_rt_wcscmp(r->name,L"checksum"))return xx_data_struct_record_set_comment(r,L"CRC-32/MPEG-2 of source bytes after the first 8 bytes. Native validation checks it.");
 if(id==1613627407u&&!xx_rt_wcscmp(r->name,L"checksum"))return xx_data_struct_record_set_comment(r,L"CRC-32/MPEG-2 of this member payload. Native validation checks it.");
 if(id==1613627409u&&!xx_rt_wcscmp(r->name,L"compressed_size"))return xx_data_struct_record_set_comment(r,L"Stored compressed byte count; 0xFFFFFFFF is the uncompressed sentinel.");
 if(id==1613627410u&&!xx_rt_wcscmp(r->name,L"compressed_size"))return xx_data_struct_record_set_comment(r,L"Stored compressed byte count; 0xFFFFFFFF is the uncompressed sentinel.");
 if(id==1613627411u&&!xx_rt_wcscmp(r->name,L"compressed_size"))return xx_data_struct_record_set_comment(r,L"Stored compressed byte count; 0xFFFFFFFF is the uncompressed sentinel.");
 if(id==1613627412u&&!xx_rt_wcscmp(r->name,L"compressed_size"))return xx_data_struct_record_set_comment(r,L"Stored compressed byte count; 0xFFFFFFFF is the uncompressed sentinel.");
 if(id==1613627430u&&!xx_rt_wcscmp(r->name,L"section_size"))return xx_data_struct_record_set_comment(r,L"Total section bytes including its 8-byte prefix.");
 if(id==1613627437u&&!xx_rt_wcscmp(r->name,L"section_size"))return xx_data_struct_record_set_comment(r,L"Total section bytes including its 8-byte prefix.");
 if(id==1613627431u&&!xx_rt_wcscmp(r->name,L"width"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627431u&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627432u&&!xx_rt_wcscmp(r->name,L"width"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627432u&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627438u&&!xx_rt_wcscmp(r->name,L"width"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627438u&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627439u&&!xx_rt_wcscmp(r->name,L"width"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627439u&&!xx_rt_wcscmp(r->name,L"height"))return xx_data_struct_record_set_comment(r,L"Layout coordinate units, not byte count.");
 if(id==1613627449u&&!xx_rt_wcscmp(r->name,L"data_size"))return xx_data_struct_record_set_comment(r,L"Payload bytes following the variable-length chunk name; excludes fixed header and name.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"animation_count"))return xx_data_struct_record_set_comment(r,L"Number of axis animation records; three axis records form one texture-matrix animation.");
 if(id==1613627451u&&!xx_rt_wcscmp(r->name,L"angle_scale"))return xx_data_struct_record_set_comment(r,L"Rotation-angle conversion uses this power-of-two scale; not a byte count.");
 if(id==1613627456u&&!xx_rt_wcscmp(r->name,L"angle_units"))return xx_data_struct_record_set_comment(r,L"Signed encoded rotation value; angle scale is in the containing TTK1 header.");
 if(id==1613627463u&&!xx_rt_wcscmp(r->name,L"frame"))return xx_data_struct_record_set_comment(r,L"Animation-frame position; not a wall-clock timestamp.");
 if(id==1613627472u&&!xx_rt_wcscmp(r->name,L"byte_order"))return xx_data_struct_record_set_comment(r,L"Metadata byte order: 0 little endian, 1 big endian. Extended header fields remain big endian.");
 if(id==1613627474u&&!xx_rt_wcscmp(r->name,L"script_type_index"))return xx_data_struct_record_set_comment(r,L"Signed script-type index; -1 means no script type.");
 if(id==1613627481u&&!xx_rt_wcscmp(r->name,L"archive_name_utf16le"))return xx_data_struct_record_set_comment(r,L"64 UTF-16LE code units; kept as source bytes without a guessed locale.");
 if(id==1613627491u&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"Zero-based index in the string-value table.");
 if(id==1613627503u&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"Zero-based index in the string-value table.");
 if(id==1613627516u&&!xx_rt_wcscmp(r->name,L"table_size_after_prefix"))return xx_data_struct_record_set_comment(r,L"Total table length minus the first 8 bytes.");
 if(id==1613627517u&&!xx_rt_wcscmp(r->name,L"storage_and_type"))return xx_data_struct_record_set_comment(r,L"Low nibble: scalar type (0..12); 0x10 name present, 0x20 default value stored, 0x40 value stored in every row.");
 if(id==1613627533u&&!xx_rt_wcscmp(r->name,L"components"))return xx_data_struct_record_set_comment(r,L"Number of components per vertex; multiply by element width to obtain the byte stride.");
 if(id==1613627536u&&!xx_rt_wcscmp(r->name,L"component"))return xx_data_struct_record_set_comment(r,L"IEEE754 vertex-array component. Array type determines position, UV, normal or tangent units.");
 if(id==1613627546u&&!xx_rt_wcscmp(r->name,L"time"))return xx_data_struct_record_set_comment(r,L"Animation time/duration scalar in ActorX units; not a Unix timestamp.");
 if(id==1613627545u&&!xx_rt_wcscmp(r->name,L"track_time"))return xx_data_struct_record_set_comment(r,L"Animation-track duration scalar; not a wall-clock timestamp.");
 if(id==1613627545u&&!xx_rt_wcscmp(r->name,L"frames_per_second"))return xx_data_struct_record_set_comment(r,L"Animation frame rate in frames per second.");
 if(id==1613627539u&&!xx_rt_wcscmp(r->name,L"parent_index"))return xx_data_struct_record_set_comment(r,L"Signed parent-bone index; native root permits 0 or -1.");
 return true;
}
const sx_family sx_mediaextra_family={sx_mediaextra_supports,sx_mediaextra_build,sx_mediaextra_layouts,SX_COUNT(sx_mediaextra_layouts),sx_mediaextra_comment};
