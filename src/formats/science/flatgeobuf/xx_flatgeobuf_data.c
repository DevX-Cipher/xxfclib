/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * flatgeobuf data structures, moved out of the scientificextra schema family. */
#include "../../xx_format_schema_scientificextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxscx_fgb_prefix_fields[] = {
    SX_FIELD("magic","uint8[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxscx_fgb_prefix = {UINT32_C(0x60310018),"fgb_prefix",sxscx_fgb_prefix_fields,SX_COUNT(sxscx_fgb_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_root_fields[] = {
    SX_FIELD("root_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_root = {UINT32_C(0x60310019),"fgb_root",sxscx_fgb_root_fields,SX_COUNT(sxscx_fgb_root_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_feature_size_fields[] = {
    SX_FIELD("feature_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxscx_fgb_feature_size = {UINT32_C(0x6031001a),"fgb_feature_size",sxscx_fgb_feature_size_fields,SX_COUNT(sxscx_fgb_feature_size_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_table_header_fields[] = {
    SX_FIELD("vtable_displacement","int32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_table_header = {UINT32_C(0x6031001b),"fgb_table_header",sxscx_fgb_table_header_fields,SX_COUNT(sxscx_fgb_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_vtable_header_fields[] = {
    SX_FIELD("vtable_size","uint16",0,2,SX_SIZE),
    SX_FIELD("object_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxscx_fgb_vtable_header = {UINT32_C(0x6031001c),"fgb_vtable_header",sxscx_fgb_vtable_header_fields,SX_COUNT(sxscx_fgb_vtable_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_vtable_entry_fields[] = {
    SX_FIELD("member_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxscx_fgb_vtable_entry = {UINT32_C(0x6031001d),"fgb_vtable_entry",sxscx_fgb_vtable_entry_fields,SX_COUNT(sxscx_fgb_vtable_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_vector_header_fields[] = {
    SX_FIELD("element_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxscx_fgb_vector_header = {UINT32_C(0x6031001e),"fgb_vector_header",sxscx_fgb_vector_header_fields,SX_COUNT(sxscx_fgb_vector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_string_header_fields[] = {
    SX_FIELD("utf8_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxscx_fgb_string_header = {UINT32_C(0x6031001f),"fgb_string_header",sxscx_fgb_string_header_fields,SX_COUNT(sxscx_fgb_string_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_vector_reference_fields[] = {
    SX_FIELD("relative_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_vector_reference = {UINT32_C(0x60310020),"fgb_vector_reference",sxscx_fgb_vector_reference_fields,SX_COUNT(sxscx_fgb_vector_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_end_fields[] = {
    SX_FIELD("point_end_index","uint32",0,4,SX_NONE),
};
const sx_layout sxscx_fgb_geometry_end = {UINT32_C(0x60310021),"fgb_geometry_end",sxscx_fgb_geometry_end_fields,SX_COUNT(sxscx_fgb_geometry_end_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_coordinate_fields[] = {
    SX_FIELD("coordinate","float64",0,8,SX_NONE),
};
const sx_layout sxscx_fgb_coordinate = {UINT32_C(0x60310022),"fgb_coordinate",sxscx_fgb_coordinate_fields,SX_COUNT(sxscx_fgb_coordinate_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_time_fields[] = {
    SX_FIELD("time_nanoseconds","uint64",0,8,SX_NONE),
};
const sx_layout sxscx_fgb_geometry_time = {UINT32_C(0x60310023),"fgb_geometry_time",sxscx_fgb_geometry_time_fields,SX_COUNT(sxscx_fgb_geometry_time_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_index_internal_fields[] = {
    SX_FIELD("min_x","float64",0,8,SX_NONE),
    SX_FIELD("min_y","float64",8,8,SX_NONE),
    SX_FIELD("max_x","float64",16,8,SX_NONE),
    SX_FIELD("max_y","float64",24,8,SX_NONE),
    SX_FIELD("child_node_index","uint64",32,8,SX_NONE),
};
const sx_layout sxscx_fgb_index_internal = {UINT32_C(0x60310024),"fgb_index_internal",sxscx_fgb_index_internal_fields,SX_COUNT(sxscx_fgb_index_internal_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_index_leaf_fields[] = {
    SX_FIELD("min_x","float64",0,8,SX_NONE),
    SX_FIELD("min_y","float64",8,8,SX_NONE),
    SX_FIELD("max_x","float64",16,8,SX_NONE),
    SX_FIELD("max_y","float64",24,8,SX_NONE),
    SX_FIELD("feature_offset","uint64",32,8,SX_OFFSET),
};
const sx_layout sxscx_fgb_index_leaf = {UINT32_C(0x60310025),"fgb_index_leaf",sxscx_fgb_index_leaf_fields,SX_COUNT(sxscx_fgb_index_leaf_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_name_fields[] = {
    SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_header_name = {UINT32_C(0x60310026),"fgb_header_name",sxscx_fgb_header_name_fields,SX_COUNT(sxscx_fgb_header_name_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_envelope_fields[] = {
    SX_FIELD("envelope_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_header_envelope = {UINT32_C(0x60310027),"fgb_header_envelope",sxscx_fgb_header_envelope_fields,SX_COUNT(sxscx_fgb_header_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_has_z_fields[] = {
    SX_FIELD("has_z","uint8",0,1,SX_FLAGS),
};
const sx_layout sxscx_fgb_header_has_z = {UINT32_C(0x60310029),"fgb_header_has_z",sxscx_fgb_header_has_z_fields,SX_COUNT(sxscx_fgb_header_has_z_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_has_m_fields[] = {
    SX_FIELD("has_m","uint8",0,1,SX_FLAGS),
};
const sx_layout sxscx_fgb_header_has_m = {UINT32_C(0x6031002a),"fgb_header_has_m",sxscx_fgb_header_has_m_fields,SX_COUNT(sxscx_fgb_header_has_m_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_has_t_fields[] = {
    SX_FIELD("has_t","uint8",0,1,SX_FLAGS),
};
const sx_layout sxscx_fgb_header_has_t = {UINT32_C(0x6031002b),"fgb_header_has_t",sxscx_fgb_header_has_t_fields,SX_COUNT(sxscx_fgb_header_has_t_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_has_tm_fields[] = {
    SX_FIELD("has_tm","uint8",0,1,SX_FLAGS),
};
const sx_layout sxscx_fgb_header_has_tm = {UINT32_C(0x6031002c),"fgb_header_has_tm",sxscx_fgb_header_has_tm_fields,SX_COUNT(sxscx_fgb_header_has_tm_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_columns_fields[] = {
    SX_FIELD("columns_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_header_columns = {UINT32_C(0x6031002d),"fgb_header_columns",sxscx_fgb_header_columns_fields,SX_COUNT(sxscx_fgb_header_columns_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_features_count_fields[] = {
    SX_FIELD("features_count","uint64",0,8,SX_COUNT_PROP),
};
const sx_layout sxscx_fgb_header_features_count = {UINT32_C(0x6031002e),"fgb_header_features_count",sxscx_fgb_header_features_count_fields,SX_COUNT(sxscx_fgb_header_features_count_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_index_node_size_fields[] = {
    SX_FIELD("index_node_size","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxscx_fgb_header_index_node_size = {UINT32_C(0x6031002f),"fgb_header_index_node_size",sxscx_fgb_header_index_node_size_fields,SX_COUNT(sxscx_fgb_header_index_node_size_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_crs_fields[] = {
    SX_FIELD("crs_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_header_crs = {UINT32_C(0x60310030),"fgb_header_crs",sxscx_fgb_header_crs_fields,SX_COUNT(sxscx_fgb_header_crs_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_title_fields[] = {
    SX_FIELD("title_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_header_title = {UINT32_C(0x60310031),"fgb_header_title",sxscx_fgb_header_title_fields,SX_COUNT(sxscx_fgb_header_title_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_description_fields[] = {
    SX_FIELD("description_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_header_description = {UINT32_C(0x60310032),"fgb_header_description",sxscx_fgb_header_description_fields,SX_COUNT(sxscx_fgb_header_description_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_header_metadata_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_header_metadata = {UINT32_C(0x60310033),"fgb_header_metadata",sxscx_fgb_header_metadata_fields,SX_COUNT(sxscx_fgb_header_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_name_fields[] = {
    SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_column_name = {UINT32_C(0x60310034),"fgb_column_name",sxscx_fgb_column_name_fields,SX_COUNT(sxscx_fgb_column_name_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_title_fields[] = {
    SX_FIELD("title_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_column_title = {UINT32_C(0x60310036),"fgb_column_title",sxscx_fgb_column_title_fields,SX_COUNT(sxscx_fgb_column_title_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_description_fields[] = {
    SX_FIELD("description_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_column_description = {UINT32_C(0x60310037),"fgb_column_description",sxscx_fgb_column_description_fields,SX_COUNT(sxscx_fgb_column_description_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_width_fields[] = {
    SX_FIELD("width","int32",0,4,SX_NONE),
};
const sx_layout sxscx_fgb_column_width = {UINT32_C(0x60310038),"fgb_column_width",sxscx_fgb_column_width_fields,SX_COUNT(sxscx_fgb_column_width_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_precision_fields[] = {
    SX_FIELD("precision","int32",0,4,SX_NONE),
};
const sx_layout sxscx_fgb_column_precision = {UINT32_C(0x60310039),"fgb_column_precision",sxscx_fgb_column_precision_fields,SX_COUNT(sxscx_fgb_column_precision_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_scale_fields[] = {
    SX_FIELD("scale","int32",0,4,SX_NONE),
};
const sx_layout sxscx_fgb_column_scale = {UINT32_C(0x6031003a),"fgb_column_scale",sxscx_fgb_column_scale_fields,SX_COUNT(sxscx_fgb_column_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_nullable_fields[] = {
    SX_FIELD("nullable","uint8",0,1,SX_FLAGS),
};
const sx_layout sxscx_fgb_column_nullable = {UINT32_C(0x6031003b),"fgb_column_nullable",sxscx_fgb_column_nullable_fields,SX_COUNT(sxscx_fgb_column_nullable_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_unique_fields[] = {
    SX_FIELD("unique","uint8",0,1,SX_FLAGS),
};
const sx_layout sxscx_fgb_column_unique = {UINT32_C(0x6031003c),"fgb_column_unique",sxscx_fgb_column_unique_fields,SX_COUNT(sxscx_fgb_column_unique_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_primary_key_fields[] = {
    SX_FIELD("primary_key","uint8",0,1,SX_FLAGS),
};
const sx_layout sxscx_fgb_column_primary_key = {UINT32_C(0x6031003d),"fgb_column_primary_key",sxscx_fgb_column_primary_key_fields,SX_COUNT(sxscx_fgb_column_primary_key_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_metadata_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_column_metadata = {UINT32_C(0x6031003e),"fgb_column_metadata",sxscx_fgb_column_metadata_fields,SX_COUNT(sxscx_fgb_column_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_org_fields[] = {
    SX_FIELD("org_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_crs_org = {UINT32_C(0x6031003f),"fgb_crs_org",sxscx_fgb_crs_org_fields,SX_COUNT(sxscx_fgb_crs_org_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_code_fields[] = {
    SX_FIELD("code","int32",0,4,SX_ID),
};
const sx_layout sxscx_fgb_crs_code = {UINT32_C(0x60310040),"fgb_crs_code",sxscx_fgb_crs_code_fields,SX_COUNT(sxscx_fgb_crs_code_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_name_fields[] = {
    SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_crs_name = {UINT32_C(0x60310041),"fgb_crs_name",sxscx_fgb_crs_name_fields,SX_COUNT(sxscx_fgb_crs_name_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_description_fields[] = {
    SX_FIELD("description_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_crs_description = {UINT32_C(0x60310042),"fgb_crs_description",sxscx_fgb_crs_description_fields,SX_COUNT(sxscx_fgb_crs_description_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_wkt_fields[] = {
    SX_FIELD("wkt_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_crs_wkt = {UINT32_C(0x60310043),"fgb_crs_wkt",sxscx_fgb_crs_wkt_fields,SX_COUNT(sxscx_fgb_crs_wkt_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_crs_code_string_fields[] = {
    SX_FIELD("code_string_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_crs_code_string = {UINT32_C(0x60310044),"fgb_crs_code_string",sxscx_fgb_crs_code_string_fields,SX_COUNT(sxscx_fgb_crs_code_string_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_ends_fields[] = {
    SX_FIELD("ends_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_geometry_ends = {UINT32_C(0x60310045),"fgb_geometry_ends",sxscx_fgb_geometry_ends_fields,SX_COUNT(sxscx_fgb_geometry_ends_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_xy_fields[] = {
    SX_FIELD("xy_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_geometry_xy = {UINT32_C(0x60310046),"fgb_geometry_xy",sxscx_fgb_geometry_xy_fields,SX_COUNT(sxscx_fgb_geometry_xy_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_z_fields[] = {
    SX_FIELD("z_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_geometry_z = {UINT32_C(0x60310047),"fgb_geometry_z",sxscx_fgb_geometry_z_fields,SX_COUNT(sxscx_fgb_geometry_z_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_m_fields[] = {
    SX_FIELD("m_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_geometry_m = {UINT32_C(0x60310048),"fgb_geometry_m",sxscx_fgb_geometry_m_fields,SX_COUNT(sxscx_fgb_geometry_m_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_t_fields[] = {
    SX_FIELD("t_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_geometry_t = {UINT32_C(0x60310049),"fgb_geometry_t",sxscx_fgb_geometry_t_fields,SX_COUNT(sxscx_fgb_geometry_t_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_tm_fields[] = {
    SX_FIELD("tm_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_geometry_tm = {UINT32_C(0x6031004a),"fgb_geometry_tm",sxscx_fgb_geometry_tm_fields,SX_COUNT(sxscx_fgb_geometry_tm_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_parts_fields[] = {
    SX_FIELD("parts_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_geometry_parts = {UINT32_C(0x6031004c),"fgb_geometry_parts",sxscx_fgb_geometry_parts_fields,SX_COUNT(sxscx_fgb_geometry_parts_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_feature_geometry_fields[] = {
    SX_FIELD("geometry_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_feature_geometry = {UINT32_C(0x6031004d),"fgb_feature_geometry",sxscx_fgb_feature_geometry_fields,SX_COUNT(sxscx_fgb_feature_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_feature_properties_fields[] = {
    SX_FIELD("properties_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxscx_fgb_feature_properties = {UINT32_C(0x6031004e),"fgb_feature_properties",sxscx_fgb_feature_properties_fields,SX_COUNT(sxscx_fgb_feature_properties_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_0_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","int8",2,1,SX_NONE),
};
const sx_layout sxscx_fgb_property_0 = {UINT32_C(0x6031004f),"fgb_property_0",sxscx_fgb_property_0_fields,SX_COUNT(sxscx_fgb_property_0_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_1_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint8",2,1,SX_NONE),
};
const sx_layout sxscx_fgb_property_1 = {UINT32_C(0x60310050),"fgb_property_1",sxscx_fgb_property_1_fields,SX_COUNT(sxscx_fgb_property_1_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_2_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint8",2,1,SX_NONE),
};
const sx_layout sxscx_fgb_property_2 = {UINT32_C(0x60310051),"fgb_property_2",sxscx_fgb_property_2_fields,SX_COUNT(sxscx_fgb_property_2_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_3_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","int16",2,2,SX_NONE),
};
const sx_layout sxscx_fgb_property_3 = {UINT32_C(0x60310052),"fgb_property_3",sxscx_fgb_property_3_fields,SX_COUNT(sxscx_fgb_property_3_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_4_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint16",2,2,SX_NONE),
};
const sx_layout sxscx_fgb_property_4 = {UINT32_C(0x60310053),"fgb_property_4",sxscx_fgb_property_4_fields,SX_COUNT(sxscx_fgb_property_4_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_5_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","int32",2,4,SX_NONE),
};
const sx_layout sxscx_fgb_property_5 = {UINT32_C(0x60310054),"fgb_property_5",sxscx_fgb_property_5_fields,SX_COUNT(sxscx_fgb_property_5_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_6_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint32",2,4,SX_NONE),
};
const sx_layout sxscx_fgb_property_6 = {UINT32_C(0x60310055),"fgb_property_6",sxscx_fgb_property_6_fields,SX_COUNT(sxscx_fgb_property_6_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_7_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","int64",2,8,SX_NONE),
};
const sx_layout sxscx_fgb_property_7 = {UINT32_C(0x60310056),"fgb_property_7",sxscx_fgb_property_7_fields,SX_COUNT(sxscx_fgb_property_7_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_8_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","uint64",2,8,SX_NONE),
};
const sx_layout sxscx_fgb_property_8 = {UINT32_C(0x60310057),"fgb_property_8",sxscx_fgb_property_8_fields,SX_COUNT(sxscx_fgb_property_8_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_9_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","float32",2,4,SX_NONE),
};
const sx_layout sxscx_fgb_property_9 = {UINT32_C(0x60310058),"fgb_property_9",sxscx_fgb_property_9_fields,SX_COUNT(sxscx_fgb_property_9_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_10_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("value","float64",2,8,SX_NONE),
};
const sx_layout sxscx_fgb_property_10 = {UINT32_C(0x60310059),"fgb_property_10",sxscx_fgb_property_10_fields,SX_COUNT(sxscx_fgb_property_10_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_11_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("byte_length","uint32",2,4,SX_SIZE),
};
const sx_layout sxscx_fgb_property_11 = {UINT32_C(0x6031005a),"fgb_property_11",sxscx_fgb_property_11_fields,SX_COUNT(sxscx_fgb_property_11_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_12_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("byte_length","uint32",2,4,SX_SIZE),
};
const sx_layout sxscx_fgb_property_12 = {UINT32_C(0x6031005b),"fgb_property_12",sxscx_fgb_property_12_fields,SX_COUNT(sxscx_fgb_property_12_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_13_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("byte_length","uint32",2,4,SX_SIZE),
};
const sx_layout sxscx_fgb_property_13 = {UINT32_C(0x6031005c),"fgb_property_13",sxscx_fgb_property_13_fields,SX_COUNT(sxscx_fgb_property_13_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_property_14_fields[] = {
    SX_FIELD("column_index","uint16",0,2,SX_ID),
    SX_FIELD("byte_length","uint32",2,4,SX_SIZE),
};
const sx_layout sxscx_fgb_property_14 = {UINT32_C(0x6031005d),"fgb_property_14",sxscx_fgb_property_14_fields,SX_COUNT(sxscx_fgb_property_14_fields),SX_LE};
static const sx_layout *const sxscx_fgb_header_rows[]={&sxscx_fgb_header_name,&sxscx_fgb_header_envelope,&sxscx_fgb_header_geometry_type,&sxscx_fgb_header_has_z,&sxscx_fgb_header_has_m,&sxscx_fgb_header_has_t,&sxscx_fgb_header_has_tm,&sxscx_fgb_header_columns,&sxscx_fgb_header_features_count,&sxscx_fgb_header_index_node_size,&sxscx_fgb_header_crs,&sxscx_fgb_header_title,&sxscx_fgb_header_description,&sxscx_fgb_header_metadata};
static const sx_layout *const sxscx_fgb_column_rows[]={&sxscx_fgb_column_name,&sxscx_fgb_column_type,&sxscx_fgb_column_title,&sxscx_fgb_column_description,&sxscx_fgb_column_width,&sxscx_fgb_column_precision,&sxscx_fgb_column_scale,&sxscx_fgb_column_nullable,&sxscx_fgb_column_unique,&sxscx_fgb_column_primary_key,&sxscx_fgb_column_metadata};
static const sx_layout *const sxscx_fgb_crs_rows[]={&sxscx_fgb_crs_org,&sxscx_fgb_crs_code,&sxscx_fgb_crs_name,&sxscx_fgb_crs_description,&sxscx_fgb_crs_wkt,&sxscx_fgb_crs_code_string};
static const sx_layout *const sxscx_fgb_geometry_rows[]={&sxscx_fgb_geometry_ends,&sxscx_fgb_geometry_xy,&sxscx_fgb_geometry_z,&sxscx_fgb_geometry_m,&sxscx_fgb_geometry_t,&sxscx_fgb_geometry_tm,&sxscx_fgb_geometry_type,&sxscx_fgb_geometry_parts};
static const sx_layout *const sxscx_fgb_feature_rows[]={&sxscx_fgb_feature_geometry,&sxscx_fgb_feature_properties,NULL};
static const sx_layout *const sxscx_fgb_property_rows[]={&sxscx_fgb_property_0,&sxscx_fgb_property_1,&sxscx_fgb_property_2,&sxscx_fgb_property_3,&sxscx_fgb_property_4,&sxscx_fgb_property_5,&sxscx_fgb_property_6,&sxscx_fgb_property_7,&sxscx_fgb_property_8,&sxscx_fgb_property_9,&sxscx_fgb_property_10,&sxscx_fgb_property_11,&sxscx_fgb_property_12,&sxscx_fgb_property_13,&sxscx_fgb_property_14};
static uint64_t sxscx64(const uint8_t *p,bool be){return xx_data_get_u64(p,8,0,be);}
typedef struct sxscx_fb {sx_context *c;const uint8_t *b;uint64_t base,n;uint8_t types[256];unsigned columns,work;} sxscx_fb;
static bool sxscx_fb_span(sxscx_fb *w,uint64_t at,uint64_t n){return !xx_pd_is_stopped(w->c->pd)&&at<=w->n&&n<=w->n-at;}
static bool sxscx_fb_add(sxscx_fb *w,const sx_layout *l,uint64_t at){return sxscx_fb_span(w,at,sxscx_extent(l))&&sxscx_add(w->c,l,w->base+at);}
static bool sxscx_fb_table(sxscx_fb *w,const sx_layout *l,uint64_t at,uint64_t count){uint64_t z=sxscx_extent(l);return !count||(count<=UINT64_MAX/z&&sxscx_fb_span(w,at,count*z)&&sxscx_table(w->c,l,w->base+at,count));}
static bool sxscx_fb_field(sxscx_fb *w,uint64_t table,unsigned id,unsigned width,uint64_t *out)
{
 if(!sxscx_fb_span(w,table,4))return false;int64_t delta=(int32_t)sxscx32(w->b+table,false),v=(int64_t)table-delta;
 if(v<0||!sxscx_fb_span(w,(uint64_t)v,4))return false;uint16_t vn=sxscx16(w->b+v,false),on=sxscx16(w->b+v+2,false);
 if(vn<4||(vn&1)||on<4||!sxscx_fb_span(w,(uint64_t)v,vn)||!sxscx_fb_span(w,table,on))return false;
 *out=0;if(4+id*2>=vn)return true;unsigned off=sxscx16(w->b+v+4+id*2,false);if(!off)return true;if(off<4||off>on||width>on-off)return false;*out=table+off;return true;
}
static bool sxscx_fb_ref(sxscx_fb *w,uint64_t field,uint64_t *out){*out=0;if(!field)return true;if(!sxscx_fb_span(w,field,4))return false;uint32_t off=sxscx32(w->b+field,false);if(!off||!sxscx_fb_span(w,field+off,4))return false;*out=field+off;return true;}
static bool sxscx_fb_string(sxscx_fb *w,uint64_t field){uint64_t at;if(!sxscx_fb_ref(w,field,&at))return false;if(!at)return true;uint32_t n=sxscx32(w->b+at,false);return n<=65536&&sxscx_fb_span(w,at+4,(uint64_t)n+1)&&w->b[at+4+n]==0&&sxscx_fb_add(w,&sxscx_fgb_string_header,at);}
static bool sxscx_fb_vector(sxscx_fb *w,uint64_t field,unsigned width,uint64_t *at,uint64_t *count)
{
 uint64_t v;*at=*count=0;if(!sxscx_fb_ref(w,field,&v))return false;if(!v)return true;
 *count=sxscx32(w->b+v,false);*at=v+4;return width&&*count<=UINT64_MAX/width&&sxscx_fb_span(w,*at,*count*width)&&sxscx_fb_add(w,&sxscx_fgb_vector_header,v);
}
static bool sxscx_fb_parse(sxscx_fb *w,uint64_t table,unsigned kind,unsigned depth);
static bool sxscx_fb_children(sxscx_fb *w,uint64_t field,unsigned kind,unsigned depth)
{
 uint64_t at,count;if(!sxscx_fb_vector(w,field,4,&at,&count)||count>1024)return false;
 if(!sxscx_fb_table(w,&sxscx_fgb_vector_reference,at,count))return false;
 for(uint64_t i=0;i<count;i++){uint64_t target;if(!sxscx_fb_ref(w,at+i*4,&target)||!target||!sxscx_fb_parse(w,target,kind,depth+1))return false;}return true;
}
static bool sxscx_fb_properties(sxscx_fb *w,uint64_t field)
{
 uint64_t at,count;if(!sxscx_fb_vector(w,field,1,&at,&count))return false;uint64_t end=at+count;
 while(at<end){if(end-at==1&&!w->b[at])return true;if(end-at<2)return false;unsigned col=sxscx16(w->b+at,false);if(col>=w->columns)return false;unsigned type=w->types[col];if(type>14)return false;
  const sx_layout *l=sxscx_fgb_property_rows[type];uint64_t z=sxscx_extent(l);if(z>end-at||!sxscx_fb_add(w,l,at))return false;
  uint64_t len=type>=11?sxscx32(w->b+at+2,false):0;if(len>end-at-z)return false;at+=z+len;
 }return at==end;
}
static bool sxscx_fb_parse(sxscx_fb *w,uint64_t table,unsigned kind,unsigned depth)
{
 static const sx_layout *const *const sets[]={sxscx_fgb_header_rows,sxscx_fgb_column_rows,sxscx_fgb_crs_rows,sxscx_fgb_geometry_rows,sxscx_fgb_feature_rows};
 static const unsigned counts[]={14,11,6,8,3};
 if(kind>=5||depth>19||!sxscx_fb_span(w,table,4))return false;
 /* Native validation has already checked the grammar. A bounded physical
  * metadata prefix is enough when shared graph expansion would be excessive. */
 if(++w->work>32768||w->c->count>=32000)return true;
 int64_t vt=(int64_t)table-(int32_t)sxscx32(w->b+table,false);if(vt<0||!sxscx_fb_span(w,(uint64_t)vt,4))return false;unsigned vn=sxscx16(w->b+vt,false);uint64_t fields[14]={0};
 if(vn<4||(vn&1)||vn>4+2*counts[kind]||!sxscx_fb_span(w,(uint64_t)vt,vn)||!sxscx_fb_add(w,&sxscx_fgb_table_header,table)||!sxscx_fb_add(w,&sxscx_fgb_vtable_header,(uint64_t)vt)||!sxscx_fb_table(w,&sxscx_fgb_vtable_entry,(uint64_t)vt+4,(vn-4)/2))return false;
 for(unsigned i=0;i<counts[kind];i++){
  const sx_layout *l=sets[kind][i];if(!sxscx_fb_field(w,table,i,l?(unsigned)sxscx_extent(l):4,&fields[i]))return false;
  if(fields[i]&&l&&!sxscx_fb_add(w,l,fields[i]))return false;
 }
 uint64_t at,count,target;
 if(kind==0){
  const unsigned strings[]={0,11,12,13};for(unsigned i=0;i<4;i++)if(!sxscx_fb_string(w,fields[strings[i]]))return false;
  if(!sxscx_fb_vector(w,fields[1],8,&at,&count)||!sxscx_fb_table(w,&sxscx_fgb_coordinate,at,count))return false;
  if(!sxscx_fb_children(w,fields[7],1,depth)||!sxscx_fb_ref(w,fields[10],&target))return false;
  return !target||sxscx_fb_parse(w,target,2,depth+1);
 }
 if(kind==1){const unsigned strings[]={0,2,3,10};for(unsigned i=0;i<4;i++)if(!sxscx_fb_string(w,fields[strings[i]]))return false;return true;}
 if(kind==2){for(unsigned i=0;i<6;i++)if(i!=1&&!sxscx_fb_string(w,fields[i]))return false;return true;}
 if(kind==3){
  if(!sxscx_fb_vector(w,fields[0],4,&at,&count)||!sxscx_fb_table(w,&sxscx_fgb_geometry_end,at,count))return false;
  for(unsigned i=1;i<=5;i++)if(!sxscx_fb_vector(w,fields[i],8,&at,&count)||!sxscx_fb_table(w,i==5?&sxscx_fgb_geometry_time:&sxscx_fgb_coordinate,at,count))return false;
  return sxscx_fb_children(w,fields[7],3,depth);
 }
 if(!sxscx_fb_ref(w,fields[0],&target)||!target||!sxscx_fb_parse(w,target,3,depth+1)||!sxscx_fb_properties(w,fields[1]))return false;
 return !fields[2];
}
static bool sxscx_flatgeobuf(sx_context *c,const uint8_t *b,size_t n)
{
 if(n<16||!sxscx_add(c,&sxscx_fgb_prefix,0))return false;uint32_t header=sxscx32(b+8,false);if(header<8||!sxscx_span(c,12,header))return false;
 sxscx_fb w={c,b+12,12,header,{0},0,0};uint64_t root=sxscx32(w.b,false),f,at,count,features,index_size=16;
 if(!sxscx_fb_add(&w,&sxscx_fgb_root,0)||!sxscx_fb_parse(&w,root,0,0)||!sxscx_fb_field(&w,root,8,8,&f)||!f)return false;features=sxscx64(w.b+f,false);if(!features||features>1024)return false;
 if(!sxscx_fb_field(&w,root,9,2,&f))return false;if(f)index_size=sxscx16(w.b+f,false);if(index_size==1)return false;
 if(!sxscx_fb_field(&w,root,7,4,&f)||!sxscx_fb_vector(&w,f,4,&at,&count)||count>256)return false;w.columns=(unsigned)count;
 for(unsigned i=0;i<w.columns;i++){
  uint64_t target,t;if(!sxscx_fb_ref(&w,at+i*4,&target)||!target||!sxscx_fb_field(&w,target,1,1,&t))return false;w.types[i]=t?w.b[t]:0;if(w.types[i]>14)return false;
 }
 at=12+(uint64_t)header;
 if(index_size){uint64_t nodes=features,level=features;unsigned depth=0;do{if(++depth>16)return false;level=(level+index_size-1)/index_size;nodes+=level;}while(level!=1);
  if(!sxscx_table(c,&sxscx_fgb_index_internal,at,nodes-features)||!sxscx_table(c,&sxscx_fgb_index_leaf,at+(nodes-features)*40,features))return false;at+=nodes*40;
 }
 for(uint64_t i=0;i<features;i++){
  if(!sxscx_span(c,at,8))return false;uint32_t z=sxscx32(b+at,false);if(z<8||z>8388608||!sxscx_span(c,at+4,z)||!sxscx_add(c,&sxscx_fgb_feature_size,at))return false;
  w.b=b+at+4;w.base=at+4;w.n=z;w.work=0;root=sxscx32(w.b,false);
  if(!sxscx_fb_add(&w,&sxscx_fgb_root,0)||!sxscx_fb_parse(&w,root,4,0))return false;at+=4+(uint64_t)z;
 }return at==n;
}
bool sx_flatgeobuf_build(sx_context *c,uint8_t *b)
{
 return sxscx_flatgeobuf(c,b,(size_t)c->size);
}
