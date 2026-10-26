/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical NintendoWare and UCSC BBI schemas. See docs/data_struct_extendedmedia_scope.txt
 * for native variants, source references and explicit payload limitations.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_extendedmedia.h"
static const xx_data_struct_field_desc sxem_nw_header_le_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("block_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("padding","uint16",18,2,SX_RESERVED),
};
static const sx_layout sxem_nw_header_le = {UINT32_C(0x600D0001),"nw_header_le",sxem_nw_header_le_fields,SX_COUNT(sxem_nw_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_nw_header_be_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("header_size","uint16",6,2,SX_SIZE),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("block_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("padding","uint16",18,2,SX_RESERVED),
};
static const sx_layout sxem_nw_header_be = {UINT32_C(0x600D0002),"nw_header_be",sxem_nw_header_be_fields,SX_COUNT(sxem_nw_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_nw_sized_reference_le_fields[] = {
    SX_FIELD("type_id","uint16",0,2,SX_ID),
    SX_FIELD("padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("offset","int32",4,4,SX_OFFSET),
    SX_FIELD("size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxem_nw_sized_reference_le = {UINT32_C(0x600D0003),"nw_sized_reference_le",sxem_nw_sized_reference_le_fields,SX_COUNT(sxem_nw_sized_reference_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_nw_sized_reference_be_fields[] = {
    SX_FIELD("type_id","uint16",0,2,SX_ID),
    SX_FIELD("padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("offset","int32",4,4,SX_OFFSET),
    SX_FIELD("size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxem_nw_sized_reference_be = {UINT32_C(0x600D0004),"nw_sized_reference_be",sxem_nw_sized_reference_be_fields,SX_COUNT(sxem_nw_sized_reference_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_nw_reference_le_fields[] = {
    SX_FIELD("type_id","uint16",0,2,SX_ID),
    SX_FIELD("padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("offset","int32",4,4,SX_OFFSET),
};
static const sx_layout sxem_nw_reference_le = {UINT32_C(0x600D0005),"nw_reference_le",sxem_nw_reference_le_fields,SX_COUNT(sxem_nw_reference_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_nw_reference_be_fields[] = {
    SX_FIELD("type_id","uint16",0,2,SX_ID),
    SX_FIELD("padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("offset","int32",4,4,SX_OFFSET),
};
static const sx_layout sxem_nw_reference_be = {UINT32_C(0x600D0006),"nw_reference_be",sxem_nw_reference_be_fields,SX_COUNT(sxem_nw_reference_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_nw_block_le_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_ID),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxem_nw_block_le = {UINT32_C(0x600D0007),"nw_block_le",sxem_nw_block_le_fields,SX_COUNT(sxem_nw_block_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_nw_block_be_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_ID),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxem_nw_block_be = {UINT32_C(0x600D0008),"nw_block_be",sxem_nw_block_be_fields,SX_COUNT(sxem_nw_block_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_nw_wave_info_le_fields[] = {
    SX_FIELD("encoding","uint8",0,1,SX_NONE),
    SX_FIELD("loop_flag","uint8",1,1,SX_NONE),
    SX_FIELD("padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("sample_rate_hz","uint32",4,4,SX_NONE),
    SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
    SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
    SX_FIELD("channel_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxem_nw_wave_info_le = {UINT32_C(0x600D0009),"nw_wave_info_le",sxem_nw_wave_info_le_fields,SX_COUNT(sxem_nw_wave_info_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_nw_wave_info_be_fields[] = {
    SX_FIELD("encoding","uint8",0,1,SX_NONE),
    SX_FIELD("loop_flag","uint8",1,1,SX_NONE),
    SX_FIELD("padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("sample_rate_hz","uint32",4,4,SX_NONE),
    SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
    SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
    SX_FIELD("channel_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxem_nw_wave_info_be = {UINT32_C(0x600D000A),"nw_wave_info_be",sxem_nw_wave_info_be_fields,SX_COUNT(sxem_nw_wave_info_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_nw_wave_channel_le_fields[] = {
    SX_FIELD("sample_type_id","uint16",0,2,SX_ID),
    SX_FIELD("padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("sample_offset","int32",4,4,SX_OFFSET),
    SX_FIELD("adpcm_type_id","uint16",8,2,SX_ID),
    SX_FIELD("adpcm_padding","uint16",10,2,SX_RESERVED),
    SX_FIELD("adpcm_offset","int32",12,4,SX_OFFSET),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
static const sx_layout sxem_nw_wave_channel_le = {UINT32_C(0x600D000B),"nw_wave_channel_le",sxem_nw_wave_channel_le_fields,SX_COUNT(sxem_nw_wave_channel_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_nw_wave_channel_be_fields[] = {
    SX_FIELD("sample_type_id","uint16",0,2,SX_ID),
    SX_FIELD("padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("sample_offset","int32",4,4,SX_OFFSET),
    SX_FIELD("adpcm_type_id","uint16",8,2,SX_ID),
    SX_FIELD("adpcm_padding","uint16",10,2,SX_RESERVED),
    SX_FIELD("adpcm_offset","int32",12,4,SX_OFFSET),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
static const sx_layout sxem_nw_wave_channel_be = {UINT32_C(0x600D000C),"nw_wave_channel_be",sxem_nw_wave_channel_be_fields,SX_COUNT(sxem_nw_wave_channel_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_nw_stream_info_le_fields[] = {
    SX_FIELD("encoding","uint8",0,1,SX_NONE),
    SX_FIELD("loop_flag","uint8",1,1,SX_NONE),
    SX_FIELD("channel_count","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("region_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sample_rate_hz","uint32",4,4,SX_NONE),
    SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
    SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",20,4,SX_SIZE),
    SX_FIELD("samples_per_block","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("last_block_size","uint32",28,4,SX_SIZE),
    SX_FIELD("last_block_samples","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("last_block_padded_size","uint32",36,4,SX_SIZE),
    SX_FIELD("seek_entry_size","uint32",40,4,SX_SIZE),
    SX_FIELD("seek_interval_samples","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("sample_type_id","uint16",48,2,SX_ID),
    SX_FIELD("sample_padding","uint16",50,2,SX_RESERVED),
    SX_FIELD("sample_offset","int32",52,4,SX_OFFSET),
    SX_FIELD("region_info_size","uint16",56,2,SX_SIZE),
    SX_FIELD("region_padding","uint16",58,2,SX_RESERVED),
    SX_FIELD("region_type_id","uint16",60,2,SX_ID),
    SX_FIELD("region_reference_padding","uint16",62,2,SX_RESERVED),
    SX_FIELD("region_offset","int32",64,4,SX_OFFSET),
};
static const sx_layout sxem_nw_stream_info_le = {UINT32_C(0x600D000D),"nw_stream_info_le",sxem_nw_stream_info_le_fields,SX_COUNT(sxem_nw_stream_info_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_nw_stream_info_be_fields[] = {
    SX_FIELD("encoding","uint8",0,1,SX_NONE),
    SX_FIELD("loop_flag","uint8",1,1,SX_NONE),
    SX_FIELD("channel_count","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("region_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sample_rate_hz","uint32",4,4,SX_NONE),
    SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
    SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",20,4,SX_SIZE),
    SX_FIELD("samples_per_block","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("last_block_size","uint32",28,4,SX_SIZE),
    SX_FIELD("last_block_samples","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("last_block_padded_size","uint32",36,4,SX_SIZE),
    SX_FIELD("seek_entry_size","uint32",40,4,SX_SIZE),
    SX_FIELD("seek_interval_samples","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("sample_type_id","uint16",48,2,SX_ID),
    SX_FIELD("sample_padding","uint16",50,2,SX_RESERVED),
    SX_FIELD("sample_offset","int32",52,4,SX_OFFSET),
    SX_FIELD("region_info_size","uint16",56,2,SX_SIZE),
    SX_FIELD("region_padding","uint16",58,2,SX_RESERVED),
    SX_FIELD("region_type_id","uint16",60,2,SX_ID),
    SX_FIELD("region_reference_padding","uint16",62,2,SX_RESERVED),
    SX_FIELD("region_offset","int32",64,4,SX_OFFSET),
};
static const sx_layout sxem_nw_stream_info_be = {UINT32_C(0x600D000E),"nw_stream_info_be",sxem_nw_stream_info_be_fields,SX_COUNT(sxem_nw_stream_info_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("zoom_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("chromosome_tree_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("full_data_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("full_index_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("field_count","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("defined_field_count","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("auto_sql_offset","uint64",36,8,SX_OFFSET),
    SX_FIELD("total_summary_offset","uint64",44,8,SX_OFFSET),
    SX_FIELD("uncompress_buffer_size","uint32",52,4,SX_SIZE),
    SX_FIELD("extension_offset","uint64",56,8,SX_OFFSET),
};
static const sx_layout sxem_bbi_header_le = {UINT32_C(0x600D000F),"bbi_header_le",sxem_bbi_header_le_fields,SX_COUNT(sxem_bbi_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("zoom_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("chromosome_tree_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("full_data_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("full_index_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("field_count","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("defined_field_count","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("auto_sql_offset","uint64",36,8,SX_OFFSET),
    SX_FIELD("total_summary_offset","uint64",44,8,SX_OFFSET),
    SX_FIELD("uncompress_buffer_size","uint32",52,4,SX_SIZE),
    SX_FIELD("extension_offset","uint64",56,8,SX_OFFSET),
};
static const sx_layout sxem_bbi_header_be = {UINT32_C(0x600D0010),"bbi_header_be",sxem_bbi_header_be_fields,SX_COUNT(sxem_bbi_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_zoom_header_le_fields[] = {
    SX_FIELD("reduction_level","uint32",0,4,SX_NONE),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
    SX_FIELD("data_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("index_offset","uint64",16,8,SX_OFFSET),
};
static const sx_layout sxem_bbi_zoom_header_le = {UINT32_C(0x600D0011),"bbi_zoom_header_le",sxem_bbi_zoom_header_le_fields,SX_COUNT(sxem_bbi_zoom_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_zoom_header_be_fields[] = {
    SX_FIELD("reduction_level","uint32",0,4,SX_NONE),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
    SX_FIELD("data_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("index_offset","uint64",16,8,SX_OFFSET),
};
static const sx_layout sxem_bbi_zoom_header_be = {UINT32_C(0x600D0012),"bbi_zoom_header_be",sxem_bbi_zoom_header_be_fields,SX_COUNT(sxem_bbi_zoom_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_tree_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("block_capacity","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("key_size","uint32",8,4,SX_SIZE),
    SX_FIELD("value_size","uint32",12,4,SX_SIZE),
    SX_FIELD("item_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("reserved","uint64",24,8,SX_RESERVED),
};
static const sx_layout sxem_bbi_chromosome_tree_le = {UINT32_C(0x600D0013),"bbi_chromosome_tree_le",sxem_bbi_chromosome_tree_le_fields,SX_COUNT(sxem_bbi_chromosome_tree_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_tree_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("block_capacity","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("key_size","uint32",8,4,SX_SIZE),
    SX_FIELD("value_size","uint32",12,4,SX_SIZE),
    SX_FIELD("item_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("reserved","uint64",24,8,SX_RESERVED),
};
static const sx_layout sxem_bbi_chromosome_tree_be = {UINT32_C(0x600D0014),"bbi_chromosome_tree_be",sxem_bbi_chromosome_tree_be_fields,SX_COUNT(sxem_bbi_chromosome_tree_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_tree_node_le_fields[] = {
    SX_FIELD("is_leaf","uint8",0,1,SX_NONE),
    SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
    SX_FIELD("child_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_tree_node_le = {UINT32_C(0x600D0015),"bbi_tree_node_le",sxem_bbi_tree_node_le_fields,SX_COUNT(sxem_bbi_tree_node_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_tree_node_be_fields[] = {
    SX_FIELD("is_leaf","uint8",0,1,SX_NONE),
    SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
    SX_FIELD("child_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_tree_node_be = {UINT32_C(0x600D0016),"bbi_tree_node_be",sxem_bbi_tree_node_be_fields,SX_COUNT(sxem_bbi_tree_node_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_1_le_fields[] = {
    SX_FIELD("name","char[1]",0,1,SX_STRING),
    SX_FIELD("chromosome_id","uint32",1,4,SX_ID),
    SX_FIELD("base_count","uint32",5,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_1_le = {UINT32_C(0x600D0017),"bbi_chromosome_1_le",sxem_bbi_chromosome_1_le_fields,SX_COUNT(sxem_bbi_chromosome_1_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_1_be_fields[] = {
    SX_FIELD("name","char[1]",0,1,SX_STRING),
    SX_FIELD("chromosome_id","uint32",1,4,SX_ID),
    SX_FIELD("base_count","uint32",5,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_1_be = {UINT32_C(0x600D0018),"bbi_chromosome_1_be",sxem_bbi_chromosome_1_be_fields,SX_COUNT(sxem_bbi_chromosome_1_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_2_le_fields[] = {
    SX_FIELD("name","char[2]",0,2,SX_STRING),
    SX_FIELD("chromosome_id","uint32",2,4,SX_ID),
    SX_FIELD("base_count","uint32",6,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_2_le = {UINT32_C(0x600D0019),"bbi_chromosome_2_le",sxem_bbi_chromosome_2_le_fields,SX_COUNT(sxem_bbi_chromosome_2_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_2_be_fields[] = {
    SX_FIELD("name","char[2]",0,2,SX_STRING),
    SX_FIELD("chromosome_id","uint32",2,4,SX_ID),
    SX_FIELD("base_count","uint32",6,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_2_be = {UINT32_C(0x600D001A),"bbi_chromosome_2_be",sxem_bbi_chromosome_2_be_fields,SX_COUNT(sxem_bbi_chromosome_2_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_3_le_fields[] = {
    SX_FIELD("name","char[3]",0,3,SX_STRING),
    SX_FIELD("chromosome_id","uint32",3,4,SX_ID),
    SX_FIELD("base_count","uint32",7,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_3_le = {UINT32_C(0x600D001B),"bbi_chromosome_3_le",sxem_bbi_chromosome_3_le_fields,SX_COUNT(sxem_bbi_chromosome_3_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_3_be_fields[] = {
    SX_FIELD("name","char[3]",0,3,SX_STRING),
    SX_FIELD("chromosome_id","uint32",3,4,SX_ID),
    SX_FIELD("base_count","uint32",7,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_3_be = {UINT32_C(0x600D001C),"bbi_chromosome_3_be",sxem_bbi_chromosome_3_be_fields,SX_COUNT(sxem_bbi_chromosome_3_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_4_le_fields[] = {
    SX_FIELD("name","char[4]",0,4,SX_STRING),
    SX_FIELD("chromosome_id","uint32",4,4,SX_ID),
    SX_FIELD("base_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_4_le = {UINT32_C(0x600D001D),"bbi_chromosome_4_le",sxem_bbi_chromosome_4_le_fields,SX_COUNT(sxem_bbi_chromosome_4_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_4_be_fields[] = {
    SX_FIELD("name","char[4]",0,4,SX_STRING),
    SX_FIELD("chromosome_id","uint32",4,4,SX_ID),
    SX_FIELD("base_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_4_be = {UINT32_C(0x600D001E),"bbi_chromosome_4_be",sxem_bbi_chromosome_4_be_fields,SX_COUNT(sxem_bbi_chromosome_4_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_5_le_fields[] = {
    SX_FIELD("name","char[5]",0,5,SX_STRING),
    SX_FIELD("chromosome_id","uint32",5,4,SX_ID),
    SX_FIELD("base_count","uint32",9,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_5_le = {UINT32_C(0x600D001F),"bbi_chromosome_5_le",sxem_bbi_chromosome_5_le_fields,SX_COUNT(sxem_bbi_chromosome_5_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_5_be_fields[] = {
    SX_FIELD("name","char[5]",0,5,SX_STRING),
    SX_FIELD("chromosome_id","uint32",5,4,SX_ID),
    SX_FIELD("base_count","uint32",9,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_5_be = {UINT32_C(0x600D0020),"bbi_chromosome_5_be",sxem_bbi_chromosome_5_be_fields,SX_COUNT(sxem_bbi_chromosome_5_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_6_le_fields[] = {
    SX_FIELD("name","char[6]",0,6,SX_STRING),
    SX_FIELD("chromosome_id","uint32",6,4,SX_ID),
    SX_FIELD("base_count","uint32",10,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_6_le = {UINT32_C(0x600D0021),"bbi_chromosome_6_le",sxem_bbi_chromosome_6_le_fields,SX_COUNT(sxem_bbi_chromosome_6_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_6_be_fields[] = {
    SX_FIELD("name","char[6]",0,6,SX_STRING),
    SX_FIELD("chromosome_id","uint32",6,4,SX_ID),
    SX_FIELD("base_count","uint32",10,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_6_be = {UINT32_C(0x600D0022),"bbi_chromosome_6_be",sxem_bbi_chromosome_6_be_fields,SX_COUNT(sxem_bbi_chromosome_6_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_7_le_fields[] = {
    SX_FIELD("name","char[7]",0,7,SX_STRING),
    SX_FIELD("chromosome_id","uint32",7,4,SX_ID),
    SX_FIELD("base_count","uint32",11,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_7_le = {UINT32_C(0x600D0023),"bbi_chromosome_7_le",sxem_bbi_chromosome_7_le_fields,SX_COUNT(sxem_bbi_chromosome_7_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_7_be_fields[] = {
    SX_FIELD("name","char[7]",0,7,SX_STRING),
    SX_FIELD("chromosome_id","uint32",7,4,SX_ID),
    SX_FIELD("base_count","uint32",11,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_7_be = {UINT32_C(0x600D0024),"bbi_chromosome_7_be",sxem_bbi_chromosome_7_be_fields,SX_COUNT(sxem_bbi_chromosome_7_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_8_le_fields[] = {
    SX_FIELD("name","char[8]",0,8,SX_STRING),
    SX_FIELD("chromosome_id","uint32",8,4,SX_ID),
    SX_FIELD("base_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_8_le = {UINT32_C(0x600D0025),"bbi_chromosome_8_le",sxem_bbi_chromosome_8_le_fields,SX_COUNT(sxem_bbi_chromosome_8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_8_be_fields[] = {
    SX_FIELD("name","char[8]",0,8,SX_STRING),
    SX_FIELD("chromosome_id","uint32",8,4,SX_ID),
    SX_FIELD("base_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_8_be = {UINT32_C(0x600D0026),"bbi_chromosome_8_be",sxem_bbi_chromosome_8_be_fields,SX_COUNT(sxem_bbi_chromosome_8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_9_le_fields[] = {
    SX_FIELD("name","char[9]",0,9,SX_STRING),
    SX_FIELD("chromosome_id","uint32",9,4,SX_ID),
    SX_FIELD("base_count","uint32",13,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_9_le = {UINT32_C(0x600D0027),"bbi_chromosome_9_le",sxem_bbi_chromosome_9_le_fields,SX_COUNT(sxem_bbi_chromosome_9_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_9_be_fields[] = {
    SX_FIELD("name","char[9]",0,9,SX_STRING),
    SX_FIELD("chromosome_id","uint32",9,4,SX_ID),
    SX_FIELD("base_count","uint32",13,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_9_be = {UINT32_C(0x600D0028),"bbi_chromosome_9_be",sxem_bbi_chromosome_9_be_fields,SX_COUNT(sxem_bbi_chromosome_9_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_10_le_fields[] = {
    SX_FIELD("name","char[10]",0,10,SX_STRING),
    SX_FIELD("chromosome_id","uint32",10,4,SX_ID),
    SX_FIELD("base_count","uint32",14,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_10_le = {UINT32_C(0x600D0029),"bbi_chromosome_10_le",sxem_bbi_chromosome_10_le_fields,SX_COUNT(sxem_bbi_chromosome_10_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_10_be_fields[] = {
    SX_FIELD("name","char[10]",0,10,SX_STRING),
    SX_FIELD("chromosome_id","uint32",10,4,SX_ID),
    SX_FIELD("base_count","uint32",14,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_10_be = {UINT32_C(0x600D002A),"bbi_chromosome_10_be",sxem_bbi_chromosome_10_be_fields,SX_COUNT(sxem_bbi_chromosome_10_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_11_le_fields[] = {
    SX_FIELD("name","char[11]",0,11,SX_STRING),
    SX_FIELD("chromosome_id","uint32",11,4,SX_ID),
    SX_FIELD("base_count","uint32",15,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_11_le = {UINT32_C(0x600D002B),"bbi_chromosome_11_le",sxem_bbi_chromosome_11_le_fields,SX_COUNT(sxem_bbi_chromosome_11_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_11_be_fields[] = {
    SX_FIELD("name","char[11]",0,11,SX_STRING),
    SX_FIELD("chromosome_id","uint32",11,4,SX_ID),
    SX_FIELD("base_count","uint32",15,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_11_be = {UINT32_C(0x600D002C),"bbi_chromosome_11_be",sxem_bbi_chromosome_11_be_fields,SX_COUNT(sxem_bbi_chromosome_11_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_12_le_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_STRING),
    SX_FIELD("chromosome_id","uint32",12,4,SX_ID),
    SX_FIELD("base_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_12_le = {UINT32_C(0x600D002D),"bbi_chromosome_12_le",sxem_bbi_chromosome_12_le_fields,SX_COUNT(sxem_bbi_chromosome_12_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_12_be_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_STRING),
    SX_FIELD("chromosome_id","uint32",12,4,SX_ID),
    SX_FIELD("base_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_12_be = {UINT32_C(0x600D002E),"bbi_chromosome_12_be",sxem_bbi_chromosome_12_be_fields,SX_COUNT(sxem_bbi_chromosome_12_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_13_le_fields[] = {
    SX_FIELD("name","char[13]",0,13,SX_STRING),
    SX_FIELD("chromosome_id","uint32",13,4,SX_ID),
    SX_FIELD("base_count","uint32",17,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_13_le = {UINT32_C(0x600D002F),"bbi_chromosome_13_le",sxem_bbi_chromosome_13_le_fields,SX_COUNT(sxem_bbi_chromosome_13_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_13_be_fields[] = {
    SX_FIELD("name","char[13]",0,13,SX_STRING),
    SX_FIELD("chromosome_id","uint32",13,4,SX_ID),
    SX_FIELD("base_count","uint32",17,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_13_be = {UINT32_C(0x600D0030),"bbi_chromosome_13_be",sxem_bbi_chromosome_13_be_fields,SX_COUNT(sxem_bbi_chromosome_13_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_14_le_fields[] = {
    SX_FIELD("name","char[14]",0,14,SX_STRING),
    SX_FIELD("chromosome_id","uint32",14,4,SX_ID),
    SX_FIELD("base_count","uint32",18,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_14_le = {UINT32_C(0x600D0031),"bbi_chromosome_14_le",sxem_bbi_chromosome_14_le_fields,SX_COUNT(sxem_bbi_chromosome_14_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_14_be_fields[] = {
    SX_FIELD("name","char[14]",0,14,SX_STRING),
    SX_FIELD("chromosome_id","uint32",14,4,SX_ID),
    SX_FIELD("base_count","uint32",18,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_14_be = {UINT32_C(0x600D0032),"bbi_chromosome_14_be",sxem_bbi_chromosome_14_be_fields,SX_COUNT(sxem_bbi_chromosome_14_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_15_le_fields[] = {
    SX_FIELD("name","char[15]",0,15,SX_STRING),
    SX_FIELD("chromosome_id","uint32",15,4,SX_ID),
    SX_FIELD("base_count","uint32",19,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_15_le = {UINT32_C(0x600D0033),"bbi_chromosome_15_le",sxem_bbi_chromosome_15_le_fields,SX_COUNT(sxem_bbi_chromosome_15_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_15_be_fields[] = {
    SX_FIELD("name","char[15]",0,15,SX_STRING),
    SX_FIELD("chromosome_id","uint32",15,4,SX_ID),
    SX_FIELD("base_count","uint32",19,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_15_be = {UINT32_C(0x600D0034),"bbi_chromosome_15_be",sxem_bbi_chromosome_15_be_fields,SX_COUNT(sxem_bbi_chromosome_15_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_16_le_fields[] = {
    SX_FIELD("name","char[16]",0,16,SX_STRING),
    SX_FIELD("chromosome_id","uint32",16,4,SX_ID),
    SX_FIELD("base_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_16_le = {UINT32_C(0x600D0035),"bbi_chromosome_16_le",sxem_bbi_chromosome_16_le_fields,SX_COUNT(sxem_bbi_chromosome_16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_16_be_fields[] = {
    SX_FIELD("name","char[16]",0,16,SX_STRING),
    SX_FIELD("chromosome_id","uint32",16,4,SX_ID),
    SX_FIELD("base_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_16_be = {UINT32_C(0x600D0036),"bbi_chromosome_16_be",sxem_bbi_chromosome_16_be_fields,SX_COUNT(sxem_bbi_chromosome_16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_17_le_fields[] = {
    SX_FIELD("name","char[17]",0,17,SX_STRING),
    SX_FIELD("chromosome_id","uint32",17,4,SX_ID),
    SX_FIELD("base_count","uint32",21,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_17_le = {UINT32_C(0x600D0037),"bbi_chromosome_17_le",sxem_bbi_chromosome_17_le_fields,SX_COUNT(sxem_bbi_chromosome_17_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_17_be_fields[] = {
    SX_FIELD("name","char[17]",0,17,SX_STRING),
    SX_FIELD("chromosome_id","uint32",17,4,SX_ID),
    SX_FIELD("base_count","uint32",21,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_17_be = {UINT32_C(0x600D0038),"bbi_chromosome_17_be",sxem_bbi_chromosome_17_be_fields,SX_COUNT(sxem_bbi_chromosome_17_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_18_le_fields[] = {
    SX_FIELD("name","char[18]",0,18,SX_STRING),
    SX_FIELD("chromosome_id","uint32",18,4,SX_ID),
    SX_FIELD("base_count","uint32",22,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_18_le = {UINT32_C(0x600D0039),"bbi_chromosome_18_le",sxem_bbi_chromosome_18_le_fields,SX_COUNT(sxem_bbi_chromosome_18_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_18_be_fields[] = {
    SX_FIELD("name","char[18]",0,18,SX_STRING),
    SX_FIELD("chromosome_id","uint32",18,4,SX_ID),
    SX_FIELD("base_count","uint32",22,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_18_be = {UINT32_C(0x600D003A),"bbi_chromosome_18_be",sxem_bbi_chromosome_18_be_fields,SX_COUNT(sxem_bbi_chromosome_18_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_19_le_fields[] = {
    SX_FIELD("name","char[19]",0,19,SX_STRING),
    SX_FIELD("chromosome_id","uint32",19,4,SX_ID),
    SX_FIELD("base_count","uint32",23,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_19_le = {UINT32_C(0x600D003B),"bbi_chromosome_19_le",sxem_bbi_chromosome_19_le_fields,SX_COUNT(sxem_bbi_chromosome_19_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_19_be_fields[] = {
    SX_FIELD("name","char[19]",0,19,SX_STRING),
    SX_FIELD("chromosome_id","uint32",19,4,SX_ID),
    SX_FIELD("base_count","uint32",23,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_19_be = {UINT32_C(0x600D003C),"bbi_chromosome_19_be",sxem_bbi_chromosome_19_be_fields,SX_COUNT(sxem_bbi_chromosome_19_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_20_le_fields[] = {
    SX_FIELD("name","char[20]",0,20,SX_STRING),
    SX_FIELD("chromosome_id","uint32",20,4,SX_ID),
    SX_FIELD("base_count","uint32",24,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_20_le = {UINT32_C(0x600D003D),"bbi_chromosome_20_le",sxem_bbi_chromosome_20_le_fields,SX_COUNT(sxem_bbi_chromosome_20_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_20_be_fields[] = {
    SX_FIELD("name","char[20]",0,20,SX_STRING),
    SX_FIELD("chromosome_id","uint32",20,4,SX_ID),
    SX_FIELD("base_count","uint32",24,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_20_be = {UINT32_C(0x600D003E),"bbi_chromosome_20_be",sxem_bbi_chromosome_20_be_fields,SX_COUNT(sxem_bbi_chromosome_20_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_21_le_fields[] = {
    SX_FIELD("name","char[21]",0,21,SX_STRING),
    SX_FIELD("chromosome_id","uint32",21,4,SX_ID),
    SX_FIELD("base_count","uint32",25,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_21_le = {UINT32_C(0x600D003F),"bbi_chromosome_21_le",sxem_bbi_chromosome_21_le_fields,SX_COUNT(sxem_bbi_chromosome_21_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_21_be_fields[] = {
    SX_FIELD("name","char[21]",0,21,SX_STRING),
    SX_FIELD("chromosome_id","uint32",21,4,SX_ID),
    SX_FIELD("base_count","uint32",25,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_21_be = {UINT32_C(0x600D0040),"bbi_chromosome_21_be",sxem_bbi_chromosome_21_be_fields,SX_COUNT(sxem_bbi_chromosome_21_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_22_le_fields[] = {
    SX_FIELD("name","char[22]",0,22,SX_STRING),
    SX_FIELD("chromosome_id","uint32",22,4,SX_ID),
    SX_FIELD("base_count","uint32",26,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_22_le = {UINT32_C(0x600D0041),"bbi_chromosome_22_le",sxem_bbi_chromosome_22_le_fields,SX_COUNT(sxem_bbi_chromosome_22_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_22_be_fields[] = {
    SX_FIELD("name","char[22]",0,22,SX_STRING),
    SX_FIELD("chromosome_id","uint32",22,4,SX_ID),
    SX_FIELD("base_count","uint32",26,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_22_be = {UINT32_C(0x600D0042),"bbi_chromosome_22_be",sxem_bbi_chromosome_22_be_fields,SX_COUNT(sxem_bbi_chromosome_22_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_23_le_fields[] = {
    SX_FIELD("name","char[23]",0,23,SX_STRING),
    SX_FIELD("chromosome_id","uint32",23,4,SX_ID),
    SX_FIELD("base_count","uint32",27,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_23_le = {UINT32_C(0x600D0043),"bbi_chromosome_23_le",sxem_bbi_chromosome_23_le_fields,SX_COUNT(sxem_bbi_chromosome_23_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_23_be_fields[] = {
    SX_FIELD("name","char[23]",0,23,SX_STRING),
    SX_FIELD("chromosome_id","uint32",23,4,SX_ID),
    SX_FIELD("base_count","uint32",27,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_23_be = {UINT32_C(0x600D0044),"bbi_chromosome_23_be",sxem_bbi_chromosome_23_be_fields,SX_COUNT(sxem_bbi_chromosome_23_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_24_le_fields[] = {
    SX_FIELD("name","char[24]",0,24,SX_STRING),
    SX_FIELD("chromosome_id","uint32",24,4,SX_ID),
    SX_FIELD("base_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_24_le = {UINT32_C(0x600D0045),"bbi_chromosome_24_le",sxem_bbi_chromosome_24_le_fields,SX_COUNT(sxem_bbi_chromosome_24_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_24_be_fields[] = {
    SX_FIELD("name","char[24]",0,24,SX_STRING),
    SX_FIELD("chromosome_id","uint32",24,4,SX_ID),
    SX_FIELD("base_count","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_24_be = {UINT32_C(0x600D0046),"bbi_chromosome_24_be",sxem_bbi_chromosome_24_be_fields,SX_COUNT(sxem_bbi_chromosome_24_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_25_le_fields[] = {
    SX_FIELD("name","char[25]",0,25,SX_STRING),
    SX_FIELD("chromosome_id","uint32",25,4,SX_ID),
    SX_FIELD("base_count","uint32",29,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_25_le = {UINT32_C(0x600D0047),"bbi_chromosome_25_le",sxem_bbi_chromosome_25_le_fields,SX_COUNT(sxem_bbi_chromosome_25_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_25_be_fields[] = {
    SX_FIELD("name","char[25]",0,25,SX_STRING),
    SX_FIELD("chromosome_id","uint32",25,4,SX_ID),
    SX_FIELD("base_count","uint32",29,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_25_be = {UINT32_C(0x600D0048),"bbi_chromosome_25_be",sxem_bbi_chromosome_25_be_fields,SX_COUNT(sxem_bbi_chromosome_25_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_26_le_fields[] = {
    SX_FIELD("name","char[26]",0,26,SX_STRING),
    SX_FIELD("chromosome_id","uint32",26,4,SX_ID),
    SX_FIELD("base_count","uint32",30,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_26_le = {UINT32_C(0x600D0049),"bbi_chromosome_26_le",sxem_bbi_chromosome_26_le_fields,SX_COUNT(sxem_bbi_chromosome_26_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_26_be_fields[] = {
    SX_FIELD("name","char[26]",0,26,SX_STRING),
    SX_FIELD("chromosome_id","uint32",26,4,SX_ID),
    SX_FIELD("base_count","uint32",30,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_26_be = {UINT32_C(0x600D004A),"bbi_chromosome_26_be",sxem_bbi_chromosome_26_be_fields,SX_COUNT(sxem_bbi_chromosome_26_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_27_le_fields[] = {
    SX_FIELD("name","char[27]",0,27,SX_STRING),
    SX_FIELD("chromosome_id","uint32",27,4,SX_ID),
    SX_FIELD("base_count","uint32",31,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_27_le = {UINT32_C(0x600D004B),"bbi_chromosome_27_le",sxem_bbi_chromosome_27_le_fields,SX_COUNT(sxem_bbi_chromosome_27_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_27_be_fields[] = {
    SX_FIELD("name","char[27]",0,27,SX_STRING),
    SX_FIELD("chromosome_id","uint32",27,4,SX_ID),
    SX_FIELD("base_count","uint32",31,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_27_be = {UINT32_C(0x600D004C),"bbi_chromosome_27_be",sxem_bbi_chromosome_27_be_fields,SX_COUNT(sxem_bbi_chromosome_27_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_28_le_fields[] = {
    SX_FIELD("name","char[28]",0,28,SX_STRING),
    SX_FIELD("chromosome_id","uint32",28,4,SX_ID),
    SX_FIELD("base_count","uint32",32,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_28_le = {UINT32_C(0x600D004D),"bbi_chromosome_28_le",sxem_bbi_chromosome_28_le_fields,SX_COUNT(sxem_bbi_chromosome_28_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_28_be_fields[] = {
    SX_FIELD("name","char[28]",0,28,SX_STRING),
    SX_FIELD("chromosome_id","uint32",28,4,SX_ID),
    SX_FIELD("base_count","uint32",32,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_28_be = {UINT32_C(0x600D004E),"bbi_chromosome_28_be",sxem_bbi_chromosome_28_be_fields,SX_COUNT(sxem_bbi_chromosome_28_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_29_le_fields[] = {
    SX_FIELD("name","char[29]",0,29,SX_STRING),
    SX_FIELD("chromosome_id","uint32",29,4,SX_ID),
    SX_FIELD("base_count","uint32",33,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_29_le = {UINT32_C(0x600D004F),"bbi_chromosome_29_le",sxem_bbi_chromosome_29_le_fields,SX_COUNT(sxem_bbi_chromosome_29_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_29_be_fields[] = {
    SX_FIELD("name","char[29]",0,29,SX_STRING),
    SX_FIELD("chromosome_id","uint32",29,4,SX_ID),
    SX_FIELD("base_count","uint32",33,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_29_be = {UINT32_C(0x600D0050),"bbi_chromosome_29_be",sxem_bbi_chromosome_29_be_fields,SX_COUNT(sxem_bbi_chromosome_29_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_30_le_fields[] = {
    SX_FIELD("name","char[30]",0,30,SX_STRING),
    SX_FIELD("chromosome_id","uint32",30,4,SX_ID),
    SX_FIELD("base_count","uint32",34,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_30_le = {UINT32_C(0x600D0051),"bbi_chromosome_30_le",sxem_bbi_chromosome_30_le_fields,SX_COUNT(sxem_bbi_chromosome_30_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_30_be_fields[] = {
    SX_FIELD("name","char[30]",0,30,SX_STRING),
    SX_FIELD("chromosome_id","uint32",30,4,SX_ID),
    SX_FIELD("base_count","uint32",34,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_30_be = {UINT32_C(0x600D0052),"bbi_chromosome_30_be",sxem_bbi_chromosome_30_be_fields,SX_COUNT(sxem_bbi_chromosome_30_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_31_le_fields[] = {
    SX_FIELD("name","char[31]",0,31,SX_STRING),
    SX_FIELD("chromosome_id","uint32",31,4,SX_ID),
    SX_FIELD("base_count","uint32",35,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_31_le = {UINT32_C(0x600D0053),"bbi_chromosome_31_le",sxem_bbi_chromosome_31_le_fields,SX_COUNT(sxem_bbi_chromosome_31_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_31_be_fields[] = {
    SX_FIELD("name","char[31]",0,31,SX_STRING),
    SX_FIELD("chromosome_id","uint32",31,4,SX_ID),
    SX_FIELD("base_count","uint32",35,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_31_be = {UINT32_C(0x600D0054),"bbi_chromosome_31_be",sxem_bbi_chromosome_31_be_fields,SX_COUNT(sxem_bbi_chromosome_31_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_32_le_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_STRING),
    SX_FIELD("chromosome_id","uint32",32,4,SX_ID),
    SX_FIELD("base_count","uint32",36,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_32_le = {UINT32_C(0x600D0055),"bbi_chromosome_32_le",sxem_bbi_chromosome_32_le_fields,SX_COUNT(sxem_bbi_chromosome_32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_32_be_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_STRING),
    SX_FIELD("chromosome_id","uint32",32,4,SX_ID),
    SX_FIELD("base_count","uint32",36,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_32_be = {UINT32_C(0x600D0056),"bbi_chromosome_32_be",sxem_bbi_chromosome_32_be_fields,SX_COUNT(sxem_bbi_chromosome_32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_33_le_fields[] = {
    SX_FIELD("name","char[33]",0,33,SX_STRING),
    SX_FIELD("chromosome_id","uint32",33,4,SX_ID),
    SX_FIELD("base_count","uint32",37,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_33_le = {UINT32_C(0x600D0057),"bbi_chromosome_33_le",sxem_bbi_chromosome_33_le_fields,SX_COUNT(sxem_bbi_chromosome_33_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_33_be_fields[] = {
    SX_FIELD("name","char[33]",0,33,SX_STRING),
    SX_FIELD("chromosome_id","uint32",33,4,SX_ID),
    SX_FIELD("base_count","uint32",37,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_33_be = {UINT32_C(0x600D0058),"bbi_chromosome_33_be",sxem_bbi_chromosome_33_be_fields,SX_COUNT(sxem_bbi_chromosome_33_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_34_le_fields[] = {
    SX_FIELD("name","char[34]",0,34,SX_STRING),
    SX_FIELD("chromosome_id","uint32",34,4,SX_ID),
    SX_FIELD("base_count","uint32",38,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_34_le = {UINT32_C(0x600D0059),"bbi_chromosome_34_le",sxem_bbi_chromosome_34_le_fields,SX_COUNT(sxem_bbi_chromosome_34_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_34_be_fields[] = {
    SX_FIELD("name","char[34]",0,34,SX_STRING),
    SX_FIELD("chromosome_id","uint32",34,4,SX_ID),
    SX_FIELD("base_count","uint32",38,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_34_be = {UINT32_C(0x600D005A),"bbi_chromosome_34_be",sxem_bbi_chromosome_34_be_fields,SX_COUNT(sxem_bbi_chromosome_34_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_35_le_fields[] = {
    SX_FIELD("name","char[35]",0,35,SX_STRING),
    SX_FIELD("chromosome_id","uint32",35,4,SX_ID),
    SX_FIELD("base_count","uint32",39,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_35_le = {UINT32_C(0x600D005B),"bbi_chromosome_35_le",sxem_bbi_chromosome_35_le_fields,SX_COUNT(sxem_bbi_chromosome_35_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_35_be_fields[] = {
    SX_FIELD("name","char[35]",0,35,SX_STRING),
    SX_FIELD("chromosome_id","uint32",35,4,SX_ID),
    SX_FIELD("base_count","uint32",39,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_35_be = {UINT32_C(0x600D005C),"bbi_chromosome_35_be",sxem_bbi_chromosome_35_be_fields,SX_COUNT(sxem_bbi_chromosome_35_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_36_le_fields[] = {
    SX_FIELD("name","char[36]",0,36,SX_STRING),
    SX_FIELD("chromosome_id","uint32",36,4,SX_ID),
    SX_FIELD("base_count","uint32",40,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_36_le = {UINT32_C(0x600D005D),"bbi_chromosome_36_le",sxem_bbi_chromosome_36_le_fields,SX_COUNT(sxem_bbi_chromosome_36_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_36_be_fields[] = {
    SX_FIELD("name","char[36]",0,36,SX_STRING),
    SX_FIELD("chromosome_id","uint32",36,4,SX_ID),
    SX_FIELD("base_count","uint32",40,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_36_be = {UINT32_C(0x600D005E),"bbi_chromosome_36_be",sxem_bbi_chromosome_36_be_fields,SX_COUNT(sxem_bbi_chromosome_36_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_37_le_fields[] = {
    SX_FIELD("name","char[37]",0,37,SX_STRING),
    SX_FIELD("chromosome_id","uint32",37,4,SX_ID),
    SX_FIELD("base_count","uint32",41,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_37_le = {UINT32_C(0x600D005F),"bbi_chromosome_37_le",sxem_bbi_chromosome_37_le_fields,SX_COUNT(sxem_bbi_chromosome_37_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_37_be_fields[] = {
    SX_FIELD("name","char[37]",0,37,SX_STRING),
    SX_FIELD("chromosome_id","uint32",37,4,SX_ID),
    SX_FIELD("base_count","uint32",41,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_37_be = {UINT32_C(0x600D0060),"bbi_chromosome_37_be",sxem_bbi_chromosome_37_be_fields,SX_COUNT(sxem_bbi_chromosome_37_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_38_le_fields[] = {
    SX_FIELD("name","char[38]",0,38,SX_STRING),
    SX_FIELD("chromosome_id","uint32",38,4,SX_ID),
    SX_FIELD("base_count","uint32",42,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_38_le = {UINT32_C(0x600D0061),"bbi_chromosome_38_le",sxem_bbi_chromosome_38_le_fields,SX_COUNT(sxem_bbi_chromosome_38_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_38_be_fields[] = {
    SX_FIELD("name","char[38]",0,38,SX_STRING),
    SX_FIELD("chromosome_id","uint32",38,4,SX_ID),
    SX_FIELD("base_count","uint32",42,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_38_be = {UINT32_C(0x600D0062),"bbi_chromosome_38_be",sxem_bbi_chromosome_38_be_fields,SX_COUNT(sxem_bbi_chromosome_38_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_39_le_fields[] = {
    SX_FIELD("name","char[39]",0,39,SX_STRING),
    SX_FIELD("chromosome_id","uint32",39,4,SX_ID),
    SX_FIELD("base_count","uint32",43,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_39_le = {UINT32_C(0x600D0063),"bbi_chromosome_39_le",sxem_bbi_chromosome_39_le_fields,SX_COUNT(sxem_bbi_chromosome_39_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_39_be_fields[] = {
    SX_FIELD("name","char[39]",0,39,SX_STRING),
    SX_FIELD("chromosome_id","uint32",39,4,SX_ID),
    SX_FIELD("base_count","uint32",43,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_39_be = {UINT32_C(0x600D0064),"bbi_chromosome_39_be",sxem_bbi_chromosome_39_be_fields,SX_COUNT(sxem_bbi_chromosome_39_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_40_le_fields[] = {
    SX_FIELD("name","char[40]",0,40,SX_STRING),
    SX_FIELD("chromosome_id","uint32",40,4,SX_ID),
    SX_FIELD("base_count","uint32",44,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_40_le = {UINT32_C(0x600D0065),"bbi_chromosome_40_le",sxem_bbi_chromosome_40_le_fields,SX_COUNT(sxem_bbi_chromosome_40_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_40_be_fields[] = {
    SX_FIELD("name","char[40]",0,40,SX_STRING),
    SX_FIELD("chromosome_id","uint32",40,4,SX_ID),
    SX_FIELD("base_count","uint32",44,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_40_be = {UINT32_C(0x600D0066),"bbi_chromosome_40_be",sxem_bbi_chromosome_40_be_fields,SX_COUNT(sxem_bbi_chromosome_40_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_41_le_fields[] = {
    SX_FIELD("name","char[41]",0,41,SX_STRING),
    SX_FIELD("chromosome_id","uint32",41,4,SX_ID),
    SX_FIELD("base_count","uint32",45,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_41_le = {UINT32_C(0x600D0067),"bbi_chromosome_41_le",sxem_bbi_chromosome_41_le_fields,SX_COUNT(sxem_bbi_chromosome_41_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_41_be_fields[] = {
    SX_FIELD("name","char[41]",0,41,SX_STRING),
    SX_FIELD("chromosome_id","uint32",41,4,SX_ID),
    SX_FIELD("base_count","uint32",45,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_41_be = {UINT32_C(0x600D0068),"bbi_chromosome_41_be",sxem_bbi_chromosome_41_be_fields,SX_COUNT(sxem_bbi_chromosome_41_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_42_le_fields[] = {
    SX_FIELD("name","char[42]",0,42,SX_STRING),
    SX_FIELD("chromosome_id","uint32",42,4,SX_ID),
    SX_FIELD("base_count","uint32",46,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_42_le = {UINT32_C(0x600D0069),"bbi_chromosome_42_le",sxem_bbi_chromosome_42_le_fields,SX_COUNT(sxem_bbi_chromosome_42_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_42_be_fields[] = {
    SX_FIELD("name","char[42]",0,42,SX_STRING),
    SX_FIELD("chromosome_id","uint32",42,4,SX_ID),
    SX_FIELD("base_count","uint32",46,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_42_be = {UINT32_C(0x600D006A),"bbi_chromosome_42_be",sxem_bbi_chromosome_42_be_fields,SX_COUNT(sxem_bbi_chromosome_42_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_43_le_fields[] = {
    SX_FIELD("name","char[43]",0,43,SX_STRING),
    SX_FIELD("chromosome_id","uint32",43,4,SX_ID),
    SX_FIELD("base_count","uint32",47,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_43_le = {UINT32_C(0x600D006B),"bbi_chromosome_43_le",sxem_bbi_chromosome_43_le_fields,SX_COUNT(sxem_bbi_chromosome_43_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_43_be_fields[] = {
    SX_FIELD("name","char[43]",0,43,SX_STRING),
    SX_FIELD("chromosome_id","uint32",43,4,SX_ID),
    SX_FIELD("base_count","uint32",47,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_43_be = {UINT32_C(0x600D006C),"bbi_chromosome_43_be",sxem_bbi_chromosome_43_be_fields,SX_COUNT(sxem_bbi_chromosome_43_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_44_le_fields[] = {
    SX_FIELD("name","char[44]",0,44,SX_STRING),
    SX_FIELD("chromosome_id","uint32",44,4,SX_ID),
    SX_FIELD("base_count","uint32",48,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_44_le = {UINT32_C(0x600D006D),"bbi_chromosome_44_le",sxem_bbi_chromosome_44_le_fields,SX_COUNT(sxem_bbi_chromosome_44_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_44_be_fields[] = {
    SX_FIELD("name","char[44]",0,44,SX_STRING),
    SX_FIELD("chromosome_id","uint32",44,4,SX_ID),
    SX_FIELD("base_count","uint32",48,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_44_be = {UINT32_C(0x600D006E),"bbi_chromosome_44_be",sxem_bbi_chromosome_44_be_fields,SX_COUNT(sxem_bbi_chromosome_44_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_45_le_fields[] = {
    SX_FIELD("name","char[45]",0,45,SX_STRING),
    SX_FIELD("chromosome_id","uint32",45,4,SX_ID),
    SX_FIELD("base_count","uint32",49,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_45_le = {UINT32_C(0x600D006F),"bbi_chromosome_45_le",sxem_bbi_chromosome_45_le_fields,SX_COUNT(sxem_bbi_chromosome_45_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_45_be_fields[] = {
    SX_FIELD("name","char[45]",0,45,SX_STRING),
    SX_FIELD("chromosome_id","uint32",45,4,SX_ID),
    SX_FIELD("base_count","uint32",49,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_45_be = {UINT32_C(0x600D0070),"bbi_chromosome_45_be",sxem_bbi_chromosome_45_be_fields,SX_COUNT(sxem_bbi_chromosome_45_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_46_le_fields[] = {
    SX_FIELD("name","char[46]",0,46,SX_STRING),
    SX_FIELD("chromosome_id","uint32",46,4,SX_ID),
    SX_FIELD("base_count","uint32",50,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_46_le = {UINT32_C(0x600D0071),"bbi_chromosome_46_le",sxem_bbi_chromosome_46_le_fields,SX_COUNT(sxem_bbi_chromosome_46_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_46_be_fields[] = {
    SX_FIELD("name","char[46]",0,46,SX_STRING),
    SX_FIELD("chromosome_id","uint32",46,4,SX_ID),
    SX_FIELD("base_count","uint32",50,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_46_be = {UINT32_C(0x600D0072),"bbi_chromosome_46_be",sxem_bbi_chromosome_46_be_fields,SX_COUNT(sxem_bbi_chromosome_46_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_47_le_fields[] = {
    SX_FIELD("name","char[47]",0,47,SX_STRING),
    SX_FIELD("chromosome_id","uint32",47,4,SX_ID),
    SX_FIELD("base_count","uint32",51,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_47_le = {UINT32_C(0x600D0073),"bbi_chromosome_47_le",sxem_bbi_chromosome_47_le_fields,SX_COUNT(sxem_bbi_chromosome_47_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_47_be_fields[] = {
    SX_FIELD("name","char[47]",0,47,SX_STRING),
    SX_FIELD("chromosome_id","uint32",47,4,SX_ID),
    SX_FIELD("base_count","uint32",51,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_47_be = {UINT32_C(0x600D0074),"bbi_chromosome_47_be",sxem_bbi_chromosome_47_be_fields,SX_COUNT(sxem_bbi_chromosome_47_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_48_le_fields[] = {
    SX_FIELD("name","char[48]",0,48,SX_STRING),
    SX_FIELD("chromosome_id","uint32",48,4,SX_ID),
    SX_FIELD("base_count","uint32",52,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_48_le = {UINT32_C(0x600D0075),"bbi_chromosome_48_le",sxem_bbi_chromosome_48_le_fields,SX_COUNT(sxem_bbi_chromosome_48_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_48_be_fields[] = {
    SX_FIELD("name","char[48]",0,48,SX_STRING),
    SX_FIELD("chromosome_id","uint32",48,4,SX_ID),
    SX_FIELD("base_count","uint32",52,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_48_be = {UINT32_C(0x600D0076),"bbi_chromosome_48_be",sxem_bbi_chromosome_48_be_fields,SX_COUNT(sxem_bbi_chromosome_48_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_49_le_fields[] = {
    SX_FIELD("name","char[49]",0,49,SX_STRING),
    SX_FIELD("chromosome_id","uint32",49,4,SX_ID),
    SX_FIELD("base_count","uint32",53,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_49_le = {UINT32_C(0x600D0077),"bbi_chromosome_49_le",sxem_bbi_chromosome_49_le_fields,SX_COUNT(sxem_bbi_chromosome_49_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_49_be_fields[] = {
    SX_FIELD("name","char[49]",0,49,SX_STRING),
    SX_FIELD("chromosome_id","uint32",49,4,SX_ID),
    SX_FIELD("base_count","uint32",53,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_49_be = {UINT32_C(0x600D0078),"bbi_chromosome_49_be",sxem_bbi_chromosome_49_be_fields,SX_COUNT(sxem_bbi_chromosome_49_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_50_le_fields[] = {
    SX_FIELD("name","char[50]",0,50,SX_STRING),
    SX_FIELD("chromosome_id","uint32",50,4,SX_ID),
    SX_FIELD("base_count","uint32",54,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_50_le = {UINT32_C(0x600D0079),"bbi_chromosome_50_le",sxem_bbi_chromosome_50_le_fields,SX_COUNT(sxem_bbi_chromosome_50_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_50_be_fields[] = {
    SX_FIELD("name","char[50]",0,50,SX_STRING),
    SX_FIELD("chromosome_id","uint32",50,4,SX_ID),
    SX_FIELD("base_count","uint32",54,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_50_be = {UINT32_C(0x600D007A),"bbi_chromosome_50_be",sxem_bbi_chromosome_50_be_fields,SX_COUNT(sxem_bbi_chromosome_50_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_51_le_fields[] = {
    SX_FIELD("name","char[51]",0,51,SX_STRING),
    SX_FIELD("chromosome_id","uint32",51,4,SX_ID),
    SX_FIELD("base_count","uint32",55,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_51_le = {UINT32_C(0x600D007B),"bbi_chromosome_51_le",sxem_bbi_chromosome_51_le_fields,SX_COUNT(sxem_bbi_chromosome_51_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_51_be_fields[] = {
    SX_FIELD("name","char[51]",0,51,SX_STRING),
    SX_FIELD("chromosome_id","uint32",51,4,SX_ID),
    SX_FIELD("base_count","uint32",55,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_51_be = {UINT32_C(0x600D007C),"bbi_chromosome_51_be",sxem_bbi_chromosome_51_be_fields,SX_COUNT(sxem_bbi_chromosome_51_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_52_le_fields[] = {
    SX_FIELD("name","char[52]",0,52,SX_STRING),
    SX_FIELD("chromosome_id","uint32",52,4,SX_ID),
    SX_FIELD("base_count","uint32",56,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_52_le = {UINT32_C(0x600D007D),"bbi_chromosome_52_le",sxem_bbi_chromosome_52_le_fields,SX_COUNT(sxem_bbi_chromosome_52_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_52_be_fields[] = {
    SX_FIELD("name","char[52]",0,52,SX_STRING),
    SX_FIELD("chromosome_id","uint32",52,4,SX_ID),
    SX_FIELD("base_count","uint32",56,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_52_be = {UINT32_C(0x600D007E),"bbi_chromosome_52_be",sxem_bbi_chromosome_52_be_fields,SX_COUNT(sxem_bbi_chromosome_52_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_53_le_fields[] = {
    SX_FIELD("name","char[53]",0,53,SX_STRING),
    SX_FIELD("chromosome_id","uint32",53,4,SX_ID),
    SX_FIELD("base_count","uint32",57,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_53_le = {UINT32_C(0x600D007F),"bbi_chromosome_53_le",sxem_bbi_chromosome_53_le_fields,SX_COUNT(sxem_bbi_chromosome_53_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_53_be_fields[] = {
    SX_FIELD("name","char[53]",0,53,SX_STRING),
    SX_FIELD("chromosome_id","uint32",53,4,SX_ID),
    SX_FIELD("base_count","uint32",57,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_53_be = {UINT32_C(0x600D0080),"bbi_chromosome_53_be",sxem_bbi_chromosome_53_be_fields,SX_COUNT(sxem_bbi_chromosome_53_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_54_le_fields[] = {
    SX_FIELD("name","char[54]",0,54,SX_STRING),
    SX_FIELD("chromosome_id","uint32",54,4,SX_ID),
    SX_FIELD("base_count","uint32",58,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_54_le = {UINT32_C(0x600D0081),"bbi_chromosome_54_le",sxem_bbi_chromosome_54_le_fields,SX_COUNT(sxem_bbi_chromosome_54_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_54_be_fields[] = {
    SX_FIELD("name","char[54]",0,54,SX_STRING),
    SX_FIELD("chromosome_id","uint32",54,4,SX_ID),
    SX_FIELD("base_count","uint32",58,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_54_be = {UINT32_C(0x600D0082),"bbi_chromosome_54_be",sxem_bbi_chromosome_54_be_fields,SX_COUNT(sxem_bbi_chromosome_54_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_55_le_fields[] = {
    SX_FIELD("name","char[55]",0,55,SX_STRING),
    SX_FIELD("chromosome_id","uint32",55,4,SX_ID),
    SX_FIELD("base_count","uint32",59,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_55_le = {UINT32_C(0x600D0083),"bbi_chromosome_55_le",sxem_bbi_chromosome_55_le_fields,SX_COUNT(sxem_bbi_chromosome_55_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_55_be_fields[] = {
    SX_FIELD("name","char[55]",0,55,SX_STRING),
    SX_FIELD("chromosome_id","uint32",55,4,SX_ID),
    SX_FIELD("base_count","uint32",59,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_55_be = {UINT32_C(0x600D0084),"bbi_chromosome_55_be",sxem_bbi_chromosome_55_be_fields,SX_COUNT(sxem_bbi_chromosome_55_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_56_le_fields[] = {
    SX_FIELD("name","char[56]",0,56,SX_STRING),
    SX_FIELD("chromosome_id","uint32",56,4,SX_ID),
    SX_FIELD("base_count","uint32",60,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_56_le = {UINT32_C(0x600D0085),"bbi_chromosome_56_le",sxem_bbi_chromosome_56_le_fields,SX_COUNT(sxem_bbi_chromosome_56_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_56_be_fields[] = {
    SX_FIELD("name","char[56]",0,56,SX_STRING),
    SX_FIELD("chromosome_id","uint32",56,4,SX_ID),
    SX_FIELD("base_count","uint32",60,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_56_be = {UINT32_C(0x600D0086),"bbi_chromosome_56_be",sxem_bbi_chromosome_56_be_fields,SX_COUNT(sxem_bbi_chromosome_56_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_57_le_fields[] = {
    SX_FIELD("name","char[57]",0,57,SX_STRING),
    SX_FIELD("chromosome_id","uint32",57,4,SX_ID),
    SX_FIELD("base_count","uint32",61,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_57_le = {UINT32_C(0x600D0087),"bbi_chromosome_57_le",sxem_bbi_chromosome_57_le_fields,SX_COUNT(sxem_bbi_chromosome_57_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_57_be_fields[] = {
    SX_FIELD("name","char[57]",0,57,SX_STRING),
    SX_FIELD("chromosome_id","uint32",57,4,SX_ID),
    SX_FIELD("base_count","uint32",61,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_57_be = {UINT32_C(0x600D0088),"bbi_chromosome_57_be",sxem_bbi_chromosome_57_be_fields,SX_COUNT(sxem_bbi_chromosome_57_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_58_le_fields[] = {
    SX_FIELD("name","char[58]",0,58,SX_STRING),
    SX_FIELD("chromosome_id","uint32",58,4,SX_ID),
    SX_FIELD("base_count","uint32",62,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_58_le = {UINT32_C(0x600D0089),"bbi_chromosome_58_le",sxem_bbi_chromosome_58_le_fields,SX_COUNT(sxem_bbi_chromosome_58_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_58_be_fields[] = {
    SX_FIELD("name","char[58]",0,58,SX_STRING),
    SX_FIELD("chromosome_id","uint32",58,4,SX_ID),
    SX_FIELD("base_count","uint32",62,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_58_be = {UINT32_C(0x600D008A),"bbi_chromosome_58_be",sxem_bbi_chromosome_58_be_fields,SX_COUNT(sxem_bbi_chromosome_58_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_59_le_fields[] = {
    SX_FIELD("name","char[59]",0,59,SX_STRING),
    SX_FIELD("chromosome_id","uint32",59,4,SX_ID),
    SX_FIELD("base_count","uint32",63,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_59_le = {UINT32_C(0x600D008B),"bbi_chromosome_59_le",sxem_bbi_chromosome_59_le_fields,SX_COUNT(sxem_bbi_chromosome_59_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_59_be_fields[] = {
    SX_FIELD("name","char[59]",0,59,SX_STRING),
    SX_FIELD("chromosome_id","uint32",59,4,SX_ID),
    SX_FIELD("base_count","uint32",63,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_59_be = {UINT32_C(0x600D008C),"bbi_chromosome_59_be",sxem_bbi_chromosome_59_be_fields,SX_COUNT(sxem_bbi_chromosome_59_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_60_le_fields[] = {
    SX_FIELD("name","char[60]",0,60,SX_STRING),
    SX_FIELD("chromosome_id","uint32",60,4,SX_ID),
    SX_FIELD("base_count","uint32",64,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_60_le = {UINT32_C(0x600D008D),"bbi_chromosome_60_le",sxem_bbi_chromosome_60_le_fields,SX_COUNT(sxem_bbi_chromosome_60_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_60_be_fields[] = {
    SX_FIELD("name","char[60]",0,60,SX_STRING),
    SX_FIELD("chromosome_id","uint32",60,4,SX_ID),
    SX_FIELD("base_count","uint32",64,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_60_be = {UINT32_C(0x600D008E),"bbi_chromosome_60_be",sxem_bbi_chromosome_60_be_fields,SX_COUNT(sxem_bbi_chromosome_60_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_61_le_fields[] = {
    SX_FIELD("name","char[61]",0,61,SX_STRING),
    SX_FIELD("chromosome_id","uint32",61,4,SX_ID),
    SX_FIELD("base_count","uint32",65,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_61_le = {UINT32_C(0x600D008F),"bbi_chromosome_61_le",sxem_bbi_chromosome_61_le_fields,SX_COUNT(sxem_bbi_chromosome_61_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_61_be_fields[] = {
    SX_FIELD("name","char[61]",0,61,SX_STRING),
    SX_FIELD("chromosome_id","uint32",61,4,SX_ID),
    SX_FIELD("base_count","uint32",65,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_61_be = {UINT32_C(0x600D0090),"bbi_chromosome_61_be",sxem_bbi_chromosome_61_be_fields,SX_COUNT(sxem_bbi_chromosome_61_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_62_le_fields[] = {
    SX_FIELD("name","char[62]",0,62,SX_STRING),
    SX_FIELD("chromosome_id","uint32",62,4,SX_ID),
    SX_FIELD("base_count","uint32",66,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_62_le = {UINT32_C(0x600D0091),"bbi_chromosome_62_le",sxem_bbi_chromosome_62_le_fields,SX_COUNT(sxem_bbi_chromosome_62_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_62_be_fields[] = {
    SX_FIELD("name","char[62]",0,62,SX_STRING),
    SX_FIELD("chromosome_id","uint32",62,4,SX_ID),
    SX_FIELD("base_count","uint32",66,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_62_be = {UINT32_C(0x600D0092),"bbi_chromosome_62_be",sxem_bbi_chromosome_62_be_fields,SX_COUNT(sxem_bbi_chromosome_62_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_63_le_fields[] = {
    SX_FIELD("name","char[63]",0,63,SX_STRING),
    SX_FIELD("chromosome_id","uint32",63,4,SX_ID),
    SX_FIELD("base_count","uint32",67,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_63_le = {UINT32_C(0x600D0093),"bbi_chromosome_63_le",sxem_bbi_chromosome_63_le_fields,SX_COUNT(sxem_bbi_chromosome_63_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_63_be_fields[] = {
    SX_FIELD("name","char[63]",0,63,SX_STRING),
    SX_FIELD("chromosome_id","uint32",63,4,SX_ID),
    SX_FIELD("base_count","uint32",67,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_63_be = {UINT32_C(0x600D0094),"bbi_chromosome_63_be",sxem_bbi_chromosome_63_be_fields,SX_COUNT(sxem_bbi_chromosome_63_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_64_le_fields[] = {
    SX_FIELD("name","char[64]",0,64,SX_STRING),
    SX_FIELD("chromosome_id","uint32",64,4,SX_ID),
    SX_FIELD("base_count","uint32",68,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_64_le = {UINT32_C(0x600D0095),"bbi_chromosome_64_le",sxem_bbi_chromosome_64_le_fields,SX_COUNT(sxem_bbi_chromosome_64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_64_be_fields[] = {
    SX_FIELD("name","char[64]",0,64,SX_STRING),
    SX_FIELD("chromosome_id","uint32",64,4,SX_ID),
    SX_FIELD("base_count","uint32",68,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_64_be = {UINT32_C(0x600D0096),"bbi_chromosome_64_be",sxem_bbi_chromosome_64_be_fields,SX_COUNT(sxem_bbi_chromosome_64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_65_le_fields[] = {
    SX_FIELD("name","char[65]",0,65,SX_STRING),
    SX_FIELD("chromosome_id","uint32",65,4,SX_ID),
    SX_FIELD("base_count","uint32",69,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_65_le = {UINT32_C(0x600D0097),"bbi_chromosome_65_le",sxem_bbi_chromosome_65_le_fields,SX_COUNT(sxem_bbi_chromosome_65_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_65_be_fields[] = {
    SX_FIELD("name","char[65]",0,65,SX_STRING),
    SX_FIELD("chromosome_id","uint32",65,4,SX_ID),
    SX_FIELD("base_count","uint32",69,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_65_be = {UINT32_C(0x600D0098),"bbi_chromosome_65_be",sxem_bbi_chromosome_65_be_fields,SX_COUNT(sxem_bbi_chromosome_65_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_66_le_fields[] = {
    SX_FIELD("name","char[66]",0,66,SX_STRING),
    SX_FIELD("chromosome_id","uint32",66,4,SX_ID),
    SX_FIELD("base_count","uint32",70,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_66_le = {UINT32_C(0x600D0099),"bbi_chromosome_66_le",sxem_bbi_chromosome_66_le_fields,SX_COUNT(sxem_bbi_chromosome_66_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_66_be_fields[] = {
    SX_FIELD("name","char[66]",0,66,SX_STRING),
    SX_FIELD("chromosome_id","uint32",66,4,SX_ID),
    SX_FIELD("base_count","uint32",70,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_66_be = {UINT32_C(0x600D009A),"bbi_chromosome_66_be",sxem_bbi_chromosome_66_be_fields,SX_COUNT(sxem_bbi_chromosome_66_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_67_le_fields[] = {
    SX_FIELD("name","char[67]",0,67,SX_STRING),
    SX_FIELD("chromosome_id","uint32",67,4,SX_ID),
    SX_FIELD("base_count","uint32",71,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_67_le = {UINT32_C(0x600D009B),"bbi_chromosome_67_le",sxem_bbi_chromosome_67_le_fields,SX_COUNT(sxem_bbi_chromosome_67_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_67_be_fields[] = {
    SX_FIELD("name","char[67]",0,67,SX_STRING),
    SX_FIELD("chromosome_id","uint32",67,4,SX_ID),
    SX_FIELD("base_count","uint32",71,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_67_be = {UINT32_C(0x600D009C),"bbi_chromosome_67_be",sxem_bbi_chromosome_67_be_fields,SX_COUNT(sxem_bbi_chromosome_67_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_68_le_fields[] = {
    SX_FIELD("name","char[68]",0,68,SX_STRING),
    SX_FIELD("chromosome_id","uint32",68,4,SX_ID),
    SX_FIELD("base_count","uint32",72,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_68_le = {UINT32_C(0x600D009D),"bbi_chromosome_68_le",sxem_bbi_chromosome_68_le_fields,SX_COUNT(sxem_bbi_chromosome_68_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_68_be_fields[] = {
    SX_FIELD("name","char[68]",0,68,SX_STRING),
    SX_FIELD("chromosome_id","uint32",68,4,SX_ID),
    SX_FIELD("base_count","uint32",72,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_68_be = {UINT32_C(0x600D009E),"bbi_chromosome_68_be",sxem_bbi_chromosome_68_be_fields,SX_COUNT(sxem_bbi_chromosome_68_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_69_le_fields[] = {
    SX_FIELD("name","char[69]",0,69,SX_STRING),
    SX_FIELD("chromosome_id","uint32",69,4,SX_ID),
    SX_FIELD("base_count","uint32",73,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_69_le = {UINT32_C(0x600D009F),"bbi_chromosome_69_le",sxem_bbi_chromosome_69_le_fields,SX_COUNT(sxem_bbi_chromosome_69_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_69_be_fields[] = {
    SX_FIELD("name","char[69]",0,69,SX_STRING),
    SX_FIELD("chromosome_id","uint32",69,4,SX_ID),
    SX_FIELD("base_count","uint32",73,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_69_be = {UINT32_C(0x600D00A0),"bbi_chromosome_69_be",sxem_bbi_chromosome_69_be_fields,SX_COUNT(sxem_bbi_chromosome_69_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_70_le_fields[] = {
    SX_FIELD("name","char[70]",0,70,SX_STRING),
    SX_FIELD("chromosome_id","uint32",70,4,SX_ID),
    SX_FIELD("base_count","uint32",74,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_70_le = {UINT32_C(0x600D00A1),"bbi_chromosome_70_le",sxem_bbi_chromosome_70_le_fields,SX_COUNT(sxem_bbi_chromosome_70_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_70_be_fields[] = {
    SX_FIELD("name","char[70]",0,70,SX_STRING),
    SX_FIELD("chromosome_id","uint32",70,4,SX_ID),
    SX_FIELD("base_count","uint32",74,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_70_be = {UINT32_C(0x600D00A2),"bbi_chromosome_70_be",sxem_bbi_chromosome_70_be_fields,SX_COUNT(sxem_bbi_chromosome_70_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_71_le_fields[] = {
    SX_FIELD("name","char[71]",0,71,SX_STRING),
    SX_FIELD("chromosome_id","uint32",71,4,SX_ID),
    SX_FIELD("base_count","uint32",75,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_71_le = {UINT32_C(0x600D00A3),"bbi_chromosome_71_le",sxem_bbi_chromosome_71_le_fields,SX_COUNT(sxem_bbi_chromosome_71_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_71_be_fields[] = {
    SX_FIELD("name","char[71]",0,71,SX_STRING),
    SX_FIELD("chromosome_id","uint32",71,4,SX_ID),
    SX_FIELD("base_count","uint32",75,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_71_be = {UINT32_C(0x600D00A4),"bbi_chromosome_71_be",sxem_bbi_chromosome_71_be_fields,SX_COUNT(sxem_bbi_chromosome_71_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_72_le_fields[] = {
    SX_FIELD("name","char[72]",0,72,SX_STRING),
    SX_FIELD("chromosome_id","uint32",72,4,SX_ID),
    SX_FIELD("base_count","uint32",76,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_72_le = {UINT32_C(0x600D00A5),"bbi_chromosome_72_le",sxem_bbi_chromosome_72_le_fields,SX_COUNT(sxem_bbi_chromosome_72_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_72_be_fields[] = {
    SX_FIELD("name","char[72]",0,72,SX_STRING),
    SX_FIELD("chromosome_id","uint32",72,4,SX_ID),
    SX_FIELD("base_count","uint32",76,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_72_be = {UINT32_C(0x600D00A6),"bbi_chromosome_72_be",sxem_bbi_chromosome_72_be_fields,SX_COUNT(sxem_bbi_chromosome_72_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_73_le_fields[] = {
    SX_FIELD("name","char[73]",0,73,SX_STRING),
    SX_FIELD("chromosome_id","uint32",73,4,SX_ID),
    SX_FIELD("base_count","uint32",77,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_73_le = {UINT32_C(0x600D00A7),"bbi_chromosome_73_le",sxem_bbi_chromosome_73_le_fields,SX_COUNT(sxem_bbi_chromosome_73_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_73_be_fields[] = {
    SX_FIELD("name","char[73]",0,73,SX_STRING),
    SX_FIELD("chromosome_id","uint32",73,4,SX_ID),
    SX_FIELD("base_count","uint32",77,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_73_be = {UINT32_C(0x600D00A8),"bbi_chromosome_73_be",sxem_bbi_chromosome_73_be_fields,SX_COUNT(sxem_bbi_chromosome_73_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_74_le_fields[] = {
    SX_FIELD("name","char[74]",0,74,SX_STRING),
    SX_FIELD("chromosome_id","uint32",74,4,SX_ID),
    SX_FIELD("base_count","uint32",78,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_74_le = {UINT32_C(0x600D00A9),"bbi_chromosome_74_le",sxem_bbi_chromosome_74_le_fields,SX_COUNT(sxem_bbi_chromosome_74_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_74_be_fields[] = {
    SX_FIELD("name","char[74]",0,74,SX_STRING),
    SX_FIELD("chromosome_id","uint32",74,4,SX_ID),
    SX_FIELD("base_count","uint32",78,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_74_be = {UINT32_C(0x600D00AA),"bbi_chromosome_74_be",sxem_bbi_chromosome_74_be_fields,SX_COUNT(sxem_bbi_chromosome_74_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_75_le_fields[] = {
    SX_FIELD("name","char[75]",0,75,SX_STRING),
    SX_FIELD("chromosome_id","uint32",75,4,SX_ID),
    SX_FIELD("base_count","uint32",79,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_75_le = {UINT32_C(0x600D00AB),"bbi_chromosome_75_le",sxem_bbi_chromosome_75_le_fields,SX_COUNT(sxem_bbi_chromosome_75_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_75_be_fields[] = {
    SX_FIELD("name","char[75]",0,75,SX_STRING),
    SX_FIELD("chromosome_id","uint32",75,4,SX_ID),
    SX_FIELD("base_count","uint32",79,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_75_be = {UINT32_C(0x600D00AC),"bbi_chromosome_75_be",sxem_bbi_chromosome_75_be_fields,SX_COUNT(sxem_bbi_chromosome_75_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_76_le_fields[] = {
    SX_FIELD("name","char[76]",0,76,SX_STRING),
    SX_FIELD("chromosome_id","uint32",76,4,SX_ID),
    SX_FIELD("base_count","uint32",80,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_76_le = {UINT32_C(0x600D00AD),"bbi_chromosome_76_le",sxem_bbi_chromosome_76_le_fields,SX_COUNT(sxem_bbi_chromosome_76_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_76_be_fields[] = {
    SX_FIELD("name","char[76]",0,76,SX_STRING),
    SX_FIELD("chromosome_id","uint32",76,4,SX_ID),
    SX_FIELD("base_count","uint32",80,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_76_be = {UINT32_C(0x600D00AE),"bbi_chromosome_76_be",sxem_bbi_chromosome_76_be_fields,SX_COUNT(sxem_bbi_chromosome_76_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_77_le_fields[] = {
    SX_FIELD("name","char[77]",0,77,SX_STRING),
    SX_FIELD("chromosome_id","uint32",77,4,SX_ID),
    SX_FIELD("base_count","uint32",81,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_77_le = {UINT32_C(0x600D00AF),"bbi_chromosome_77_le",sxem_bbi_chromosome_77_le_fields,SX_COUNT(sxem_bbi_chromosome_77_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_77_be_fields[] = {
    SX_FIELD("name","char[77]",0,77,SX_STRING),
    SX_FIELD("chromosome_id","uint32",77,4,SX_ID),
    SX_FIELD("base_count","uint32",81,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_77_be = {UINT32_C(0x600D00B0),"bbi_chromosome_77_be",sxem_bbi_chromosome_77_be_fields,SX_COUNT(sxem_bbi_chromosome_77_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_78_le_fields[] = {
    SX_FIELD("name","char[78]",0,78,SX_STRING),
    SX_FIELD("chromosome_id","uint32",78,4,SX_ID),
    SX_FIELD("base_count","uint32",82,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_78_le = {UINT32_C(0x600D00B1),"bbi_chromosome_78_le",sxem_bbi_chromosome_78_le_fields,SX_COUNT(sxem_bbi_chromosome_78_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_78_be_fields[] = {
    SX_FIELD("name","char[78]",0,78,SX_STRING),
    SX_FIELD("chromosome_id","uint32",78,4,SX_ID),
    SX_FIELD("base_count","uint32",82,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_78_be = {UINT32_C(0x600D00B2),"bbi_chromosome_78_be",sxem_bbi_chromosome_78_be_fields,SX_COUNT(sxem_bbi_chromosome_78_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_79_le_fields[] = {
    SX_FIELD("name","char[79]",0,79,SX_STRING),
    SX_FIELD("chromosome_id","uint32",79,4,SX_ID),
    SX_FIELD("base_count","uint32",83,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_79_le = {UINT32_C(0x600D00B3),"bbi_chromosome_79_le",sxem_bbi_chromosome_79_le_fields,SX_COUNT(sxem_bbi_chromosome_79_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_79_be_fields[] = {
    SX_FIELD("name","char[79]",0,79,SX_STRING),
    SX_FIELD("chromosome_id","uint32",79,4,SX_ID),
    SX_FIELD("base_count","uint32",83,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_79_be = {UINT32_C(0x600D00B4),"bbi_chromosome_79_be",sxem_bbi_chromosome_79_be_fields,SX_COUNT(sxem_bbi_chromosome_79_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_80_le_fields[] = {
    SX_FIELD("name","char[80]",0,80,SX_STRING),
    SX_FIELD("chromosome_id","uint32",80,4,SX_ID),
    SX_FIELD("base_count","uint32",84,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_80_le = {UINT32_C(0x600D00B5),"bbi_chromosome_80_le",sxem_bbi_chromosome_80_le_fields,SX_COUNT(sxem_bbi_chromosome_80_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_80_be_fields[] = {
    SX_FIELD("name","char[80]",0,80,SX_STRING),
    SX_FIELD("chromosome_id","uint32",80,4,SX_ID),
    SX_FIELD("base_count","uint32",84,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_80_be = {UINT32_C(0x600D00B6),"bbi_chromosome_80_be",sxem_bbi_chromosome_80_be_fields,SX_COUNT(sxem_bbi_chromosome_80_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_81_le_fields[] = {
    SX_FIELD("name","char[81]",0,81,SX_STRING),
    SX_FIELD("chromosome_id","uint32",81,4,SX_ID),
    SX_FIELD("base_count","uint32",85,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_81_le = {UINT32_C(0x600D00B7),"bbi_chromosome_81_le",sxem_bbi_chromosome_81_le_fields,SX_COUNT(sxem_bbi_chromosome_81_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_81_be_fields[] = {
    SX_FIELD("name","char[81]",0,81,SX_STRING),
    SX_FIELD("chromosome_id","uint32",81,4,SX_ID),
    SX_FIELD("base_count","uint32",85,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_81_be = {UINT32_C(0x600D00B8),"bbi_chromosome_81_be",sxem_bbi_chromosome_81_be_fields,SX_COUNT(sxem_bbi_chromosome_81_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_82_le_fields[] = {
    SX_FIELD("name","char[82]",0,82,SX_STRING),
    SX_FIELD("chromosome_id","uint32",82,4,SX_ID),
    SX_FIELD("base_count","uint32",86,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_82_le = {UINT32_C(0x600D00B9),"bbi_chromosome_82_le",sxem_bbi_chromosome_82_le_fields,SX_COUNT(sxem_bbi_chromosome_82_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_82_be_fields[] = {
    SX_FIELD("name","char[82]",0,82,SX_STRING),
    SX_FIELD("chromosome_id","uint32",82,4,SX_ID),
    SX_FIELD("base_count","uint32",86,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_82_be = {UINT32_C(0x600D00BA),"bbi_chromosome_82_be",sxem_bbi_chromosome_82_be_fields,SX_COUNT(sxem_bbi_chromosome_82_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_83_le_fields[] = {
    SX_FIELD("name","char[83]",0,83,SX_STRING),
    SX_FIELD("chromosome_id","uint32",83,4,SX_ID),
    SX_FIELD("base_count","uint32",87,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_83_le = {UINT32_C(0x600D00BB),"bbi_chromosome_83_le",sxem_bbi_chromosome_83_le_fields,SX_COUNT(sxem_bbi_chromosome_83_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_83_be_fields[] = {
    SX_FIELD("name","char[83]",0,83,SX_STRING),
    SX_FIELD("chromosome_id","uint32",83,4,SX_ID),
    SX_FIELD("base_count","uint32",87,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_83_be = {UINT32_C(0x600D00BC),"bbi_chromosome_83_be",sxem_bbi_chromosome_83_be_fields,SX_COUNT(sxem_bbi_chromosome_83_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_84_le_fields[] = {
    SX_FIELD("name","char[84]",0,84,SX_STRING),
    SX_FIELD("chromosome_id","uint32",84,4,SX_ID),
    SX_FIELD("base_count","uint32",88,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_84_le = {UINT32_C(0x600D00BD),"bbi_chromosome_84_le",sxem_bbi_chromosome_84_le_fields,SX_COUNT(sxem_bbi_chromosome_84_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_84_be_fields[] = {
    SX_FIELD("name","char[84]",0,84,SX_STRING),
    SX_FIELD("chromosome_id","uint32",84,4,SX_ID),
    SX_FIELD("base_count","uint32",88,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_84_be = {UINT32_C(0x600D00BE),"bbi_chromosome_84_be",sxem_bbi_chromosome_84_be_fields,SX_COUNT(sxem_bbi_chromosome_84_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_85_le_fields[] = {
    SX_FIELD("name","char[85]",0,85,SX_STRING),
    SX_FIELD("chromosome_id","uint32",85,4,SX_ID),
    SX_FIELD("base_count","uint32",89,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_85_le = {UINT32_C(0x600D00BF),"bbi_chromosome_85_le",sxem_bbi_chromosome_85_le_fields,SX_COUNT(sxem_bbi_chromosome_85_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_85_be_fields[] = {
    SX_FIELD("name","char[85]",0,85,SX_STRING),
    SX_FIELD("chromosome_id","uint32",85,4,SX_ID),
    SX_FIELD("base_count","uint32",89,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_85_be = {UINT32_C(0x600D00C0),"bbi_chromosome_85_be",sxem_bbi_chromosome_85_be_fields,SX_COUNT(sxem_bbi_chromosome_85_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_86_le_fields[] = {
    SX_FIELD("name","char[86]",0,86,SX_STRING),
    SX_FIELD("chromosome_id","uint32",86,4,SX_ID),
    SX_FIELD("base_count","uint32",90,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_86_le = {UINT32_C(0x600D00C1),"bbi_chromosome_86_le",sxem_bbi_chromosome_86_le_fields,SX_COUNT(sxem_bbi_chromosome_86_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_86_be_fields[] = {
    SX_FIELD("name","char[86]",0,86,SX_STRING),
    SX_FIELD("chromosome_id","uint32",86,4,SX_ID),
    SX_FIELD("base_count","uint32",90,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_86_be = {UINT32_C(0x600D00C2),"bbi_chromosome_86_be",sxem_bbi_chromosome_86_be_fields,SX_COUNT(sxem_bbi_chromosome_86_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_87_le_fields[] = {
    SX_FIELD("name","char[87]",0,87,SX_STRING),
    SX_FIELD("chromosome_id","uint32",87,4,SX_ID),
    SX_FIELD("base_count","uint32",91,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_87_le = {UINT32_C(0x600D00C3),"bbi_chromosome_87_le",sxem_bbi_chromosome_87_le_fields,SX_COUNT(sxem_bbi_chromosome_87_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_87_be_fields[] = {
    SX_FIELD("name","char[87]",0,87,SX_STRING),
    SX_FIELD("chromosome_id","uint32",87,4,SX_ID),
    SX_FIELD("base_count","uint32",91,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_87_be = {UINT32_C(0x600D00C4),"bbi_chromosome_87_be",sxem_bbi_chromosome_87_be_fields,SX_COUNT(sxem_bbi_chromosome_87_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_88_le_fields[] = {
    SX_FIELD("name","char[88]",0,88,SX_STRING),
    SX_FIELD("chromosome_id","uint32",88,4,SX_ID),
    SX_FIELD("base_count","uint32",92,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_88_le = {UINT32_C(0x600D00C5),"bbi_chromosome_88_le",sxem_bbi_chromosome_88_le_fields,SX_COUNT(sxem_bbi_chromosome_88_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_88_be_fields[] = {
    SX_FIELD("name","char[88]",0,88,SX_STRING),
    SX_FIELD("chromosome_id","uint32",88,4,SX_ID),
    SX_FIELD("base_count","uint32",92,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_88_be = {UINT32_C(0x600D00C6),"bbi_chromosome_88_be",sxem_bbi_chromosome_88_be_fields,SX_COUNT(sxem_bbi_chromosome_88_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_89_le_fields[] = {
    SX_FIELD("name","char[89]",0,89,SX_STRING),
    SX_FIELD("chromosome_id","uint32",89,4,SX_ID),
    SX_FIELD("base_count","uint32",93,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_89_le = {UINT32_C(0x600D00C7),"bbi_chromosome_89_le",sxem_bbi_chromosome_89_le_fields,SX_COUNT(sxem_bbi_chromosome_89_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_89_be_fields[] = {
    SX_FIELD("name","char[89]",0,89,SX_STRING),
    SX_FIELD("chromosome_id","uint32",89,4,SX_ID),
    SX_FIELD("base_count","uint32",93,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_89_be = {UINT32_C(0x600D00C8),"bbi_chromosome_89_be",sxem_bbi_chromosome_89_be_fields,SX_COUNT(sxem_bbi_chromosome_89_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_90_le_fields[] = {
    SX_FIELD("name","char[90]",0,90,SX_STRING),
    SX_FIELD("chromosome_id","uint32",90,4,SX_ID),
    SX_FIELD("base_count","uint32",94,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_90_le = {UINT32_C(0x600D00C9),"bbi_chromosome_90_le",sxem_bbi_chromosome_90_le_fields,SX_COUNT(sxem_bbi_chromosome_90_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_90_be_fields[] = {
    SX_FIELD("name","char[90]",0,90,SX_STRING),
    SX_FIELD("chromosome_id","uint32",90,4,SX_ID),
    SX_FIELD("base_count","uint32",94,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_90_be = {UINT32_C(0x600D00CA),"bbi_chromosome_90_be",sxem_bbi_chromosome_90_be_fields,SX_COUNT(sxem_bbi_chromosome_90_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_91_le_fields[] = {
    SX_FIELD("name","char[91]",0,91,SX_STRING),
    SX_FIELD("chromosome_id","uint32",91,4,SX_ID),
    SX_FIELD("base_count","uint32",95,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_91_le = {UINT32_C(0x600D00CB),"bbi_chromosome_91_le",sxem_bbi_chromosome_91_le_fields,SX_COUNT(sxem_bbi_chromosome_91_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_91_be_fields[] = {
    SX_FIELD("name","char[91]",0,91,SX_STRING),
    SX_FIELD("chromosome_id","uint32",91,4,SX_ID),
    SX_FIELD("base_count","uint32",95,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_91_be = {UINT32_C(0x600D00CC),"bbi_chromosome_91_be",sxem_bbi_chromosome_91_be_fields,SX_COUNT(sxem_bbi_chromosome_91_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_92_le_fields[] = {
    SX_FIELD("name","char[92]",0,92,SX_STRING),
    SX_FIELD("chromosome_id","uint32",92,4,SX_ID),
    SX_FIELD("base_count","uint32",96,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_92_le = {UINT32_C(0x600D00CD),"bbi_chromosome_92_le",sxem_bbi_chromosome_92_le_fields,SX_COUNT(sxem_bbi_chromosome_92_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_92_be_fields[] = {
    SX_FIELD("name","char[92]",0,92,SX_STRING),
    SX_FIELD("chromosome_id","uint32",92,4,SX_ID),
    SX_FIELD("base_count","uint32",96,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_92_be = {UINT32_C(0x600D00CE),"bbi_chromosome_92_be",sxem_bbi_chromosome_92_be_fields,SX_COUNT(sxem_bbi_chromosome_92_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_93_le_fields[] = {
    SX_FIELD("name","char[93]",0,93,SX_STRING),
    SX_FIELD("chromosome_id","uint32",93,4,SX_ID),
    SX_FIELD("base_count","uint32",97,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_93_le = {UINT32_C(0x600D00CF),"bbi_chromosome_93_le",sxem_bbi_chromosome_93_le_fields,SX_COUNT(sxem_bbi_chromosome_93_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_93_be_fields[] = {
    SX_FIELD("name","char[93]",0,93,SX_STRING),
    SX_FIELD("chromosome_id","uint32",93,4,SX_ID),
    SX_FIELD("base_count","uint32",97,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_93_be = {UINT32_C(0x600D00D0),"bbi_chromosome_93_be",sxem_bbi_chromosome_93_be_fields,SX_COUNT(sxem_bbi_chromosome_93_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_94_le_fields[] = {
    SX_FIELD("name","char[94]",0,94,SX_STRING),
    SX_FIELD("chromosome_id","uint32",94,4,SX_ID),
    SX_FIELD("base_count","uint32",98,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_94_le = {UINT32_C(0x600D00D1),"bbi_chromosome_94_le",sxem_bbi_chromosome_94_le_fields,SX_COUNT(sxem_bbi_chromosome_94_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_94_be_fields[] = {
    SX_FIELD("name","char[94]",0,94,SX_STRING),
    SX_FIELD("chromosome_id","uint32",94,4,SX_ID),
    SX_FIELD("base_count","uint32",98,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_94_be = {UINT32_C(0x600D00D2),"bbi_chromosome_94_be",sxem_bbi_chromosome_94_be_fields,SX_COUNT(sxem_bbi_chromosome_94_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_95_le_fields[] = {
    SX_FIELD("name","char[95]",0,95,SX_STRING),
    SX_FIELD("chromosome_id","uint32",95,4,SX_ID),
    SX_FIELD("base_count","uint32",99,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_95_le = {UINT32_C(0x600D00D3),"bbi_chromosome_95_le",sxem_bbi_chromosome_95_le_fields,SX_COUNT(sxem_bbi_chromosome_95_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_95_be_fields[] = {
    SX_FIELD("name","char[95]",0,95,SX_STRING),
    SX_FIELD("chromosome_id","uint32",95,4,SX_ID),
    SX_FIELD("base_count","uint32",99,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_95_be = {UINT32_C(0x600D00D4),"bbi_chromosome_95_be",sxem_bbi_chromosome_95_be_fields,SX_COUNT(sxem_bbi_chromosome_95_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_96_le_fields[] = {
    SX_FIELD("name","char[96]",0,96,SX_STRING),
    SX_FIELD("chromosome_id","uint32",96,4,SX_ID),
    SX_FIELD("base_count","uint32",100,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_96_le = {UINT32_C(0x600D00D5),"bbi_chromosome_96_le",sxem_bbi_chromosome_96_le_fields,SX_COUNT(sxem_bbi_chromosome_96_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_96_be_fields[] = {
    SX_FIELD("name","char[96]",0,96,SX_STRING),
    SX_FIELD("chromosome_id","uint32",96,4,SX_ID),
    SX_FIELD("base_count","uint32",100,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_96_be = {UINT32_C(0x600D00D6),"bbi_chromosome_96_be",sxem_bbi_chromosome_96_be_fields,SX_COUNT(sxem_bbi_chromosome_96_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_97_le_fields[] = {
    SX_FIELD("name","char[97]",0,97,SX_STRING),
    SX_FIELD("chromosome_id","uint32",97,4,SX_ID),
    SX_FIELD("base_count","uint32",101,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_97_le = {UINT32_C(0x600D00D7),"bbi_chromosome_97_le",sxem_bbi_chromosome_97_le_fields,SX_COUNT(sxem_bbi_chromosome_97_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_97_be_fields[] = {
    SX_FIELD("name","char[97]",0,97,SX_STRING),
    SX_FIELD("chromosome_id","uint32",97,4,SX_ID),
    SX_FIELD("base_count","uint32",101,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_97_be = {UINT32_C(0x600D00D8),"bbi_chromosome_97_be",sxem_bbi_chromosome_97_be_fields,SX_COUNT(sxem_bbi_chromosome_97_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_98_le_fields[] = {
    SX_FIELD("name","char[98]",0,98,SX_STRING),
    SX_FIELD("chromosome_id","uint32",98,4,SX_ID),
    SX_FIELD("base_count","uint32",102,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_98_le = {UINT32_C(0x600D00D9),"bbi_chromosome_98_le",sxem_bbi_chromosome_98_le_fields,SX_COUNT(sxem_bbi_chromosome_98_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_98_be_fields[] = {
    SX_FIELD("name","char[98]",0,98,SX_STRING),
    SX_FIELD("chromosome_id","uint32",98,4,SX_ID),
    SX_FIELD("base_count","uint32",102,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_98_be = {UINT32_C(0x600D00DA),"bbi_chromosome_98_be",sxem_bbi_chromosome_98_be_fields,SX_COUNT(sxem_bbi_chromosome_98_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_99_le_fields[] = {
    SX_FIELD("name","char[99]",0,99,SX_STRING),
    SX_FIELD("chromosome_id","uint32",99,4,SX_ID),
    SX_FIELD("base_count","uint32",103,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_99_le = {UINT32_C(0x600D00DB),"bbi_chromosome_99_le",sxem_bbi_chromosome_99_le_fields,SX_COUNT(sxem_bbi_chromosome_99_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_99_be_fields[] = {
    SX_FIELD("name","char[99]",0,99,SX_STRING),
    SX_FIELD("chromosome_id","uint32",99,4,SX_ID),
    SX_FIELD("base_count","uint32",103,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_99_be = {UINT32_C(0x600D00DC),"bbi_chromosome_99_be",sxem_bbi_chromosome_99_be_fields,SX_COUNT(sxem_bbi_chromosome_99_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_100_le_fields[] = {
    SX_FIELD("name","char[100]",0,100,SX_STRING),
    SX_FIELD("chromosome_id","uint32",100,4,SX_ID),
    SX_FIELD("base_count","uint32",104,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_100_le = {UINT32_C(0x600D00DD),"bbi_chromosome_100_le",sxem_bbi_chromosome_100_le_fields,SX_COUNT(sxem_bbi_chromosome_100_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_100_be_fields[] = {
    SX_FIELD("name","char[100]",0,100,SX_STRING),
    SX_FIELD("chromosome_id","uint32",100,4,SX_ID),
    SX_FIELD("base_count","uint32",104,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_100_be = {UINT32_C(0x600D00DE),"bbi_chromosome_100_be",sxem_bbi_chromosome_100_be_fields,SX_COUNT(sxem_bbi_chromosome_100_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_101_le_fields[] = {
    SX_FIELD("name","char[101]",0,101,SX_STRING),
    SX_FIELD("chromosome_id","uint32",101,4,SX_ID),
    SX_FIELD("base_count","uint32",105,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_101_le = {UINT32_C(0x600D00DF),"bbi_chromosome_101_le",sxem_bbi_chromosome_101_le_fields,SX_COUNT(sxem_bbi_chromosome_101_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_101_be_fields[] = {
    SX_FIELD("name","char[101]",0,101,SX_STRING),
    SX_FIELD("chromosome_id","uint32",101,4,SX_ID),
    SX_FIELD("base_count","uint32",105,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_101_be = {UINT32_C(0x600D00E0),"bbi_chromosome_101_be",sxem_bbi_chromosome_101_be_fields,SX_COUNT(sxem_bbi_chromosome_101_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_102_le_fields[] = {
    SX_FIELD("name","char[102]",0,102,SX_STRING),
    SX_FIELD("chromosome_id","uint32",102,4,SX_ID),
    SX_FIELD("base_count","uint32",106,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_102_le = {UINT32_C(0x600D00E1),"bbi_chromosome_102_le",sxem_bbi_chromosome_102_le_fields,SX_COUNT(sxem_bbi_chromosome_102_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_102_be_fields[] = {
    SX_FIELD("name","char[102]",0,102,SX_STRING),
    SX_FIELD("chromosome_id","uint32",102,4,SX_ID),
    SX_FIELD("base_count","uint32",106,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_102_be = {UINT32_C(0x600D00E2),"bbi_chromosome_102_be",sxem_bbi_chromosome_102_be_fields,SX_COUNT(sxem_bbi_chromosome_102_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_103_le_fields[] = {
    SX_FIELD("name","char[103]",0,103,SX_STRING),
    SX_FIELD("chromosome_id","uint32",103,4,SX_ID),
    SX_FIELD("base_count","uint32",107,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_103_le = {UINT32_C(0x600D00E3),"bbi_chromosome_103_le",sxem_bbi_chromosome_103_le_fields,SX_COUNT(sxem_bbi_chromosome_103_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_103_be_fields[] = {
    SX_FIELD("name","char[103]",0,103,SX_STRING),
    SX_FIELD("chromosome_id","uint32",103,4,SX_ID),
    SX_FIELD("base_count","uint32",107,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_103_be = {UINT32_C(0x600D00E4),"bbi_chromosome_103_be",sxem_bbi_chromosome_103_be_fields,SX_COUNT(sxem_bbi_chromosome_103_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_104_le_fields[] = {
    SX_FIELD("name","char[104]",0,104,SX_STRING),
    SX_FIELD("chromosome_id","uint32",104,4,SX_ID),
    SX_FIELD("base_count","uint32",108,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_104_le = {UINT32_C(0x600D00E5),"bbi_chromosome_104_le",sxem_bbi_chromosome_104_le_fields,SX_COUNT(sxem_bbi_chromosome_104_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_104_be_fields[] = {
    SX_FIELD("name","char[104]",0,104,SX_STRING),
    SX_FIELD("chromosome_id","uint32",104,4,SX_ID),
    SX_FIELD("base_count","uint32",108,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_104_be = {UINT32_C(0x600D00E6),"bbi_chromosome_104_be",sxem_bbi_chromosome_104_be_fields,SX_COUNT(sxem_bbi_chromosome_104_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_105_le_fields[] = {
    SX_FIELD("name","char[105]",0,105,SX_STRING),
    SX_FIELD("chromosome_id","uint32",105,4,SX_ID),
    SX_FIELD("base_count","uint32",109,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_105_le = {UINT32_C(0x600D00E7),"bbi_chromosome_105_le",sxem_bbi_chromosome_105_le_fields,SX_COUNT(sxem_bbi_chromosome_105_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_105_be_fields[] = {
    SX_FIELD("name","char[105]",0,105,SX_STRING),
    SX_FIELD("chromosome_id","uint32",105,4,SX_ID),
    SX_FIELD("base_count","uint32",109,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_105_be = {UINT32_C(0x600D00E8),"bbi_chromosome_105_be",sxem_bbi_chromosome_105_be_fields,SX_COUNT(sxem_bbi_chromosome_105_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_106_le_fields[] = {
    SX_FIELD("name","char[106]",0,106,SX_STRING),
    SX_FIELD("chromosome_id","uint32",106,4,SX_ID),
    SX_FIELD("base_count","uint32",110,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_106_le = {UINT32_C(0x600D00E9),"bbi_chromosome_106_le",sxem_bbi_chromosome_106_le_fields,SX_COUNT(sxem_bbi_chromosome_106_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_106_be_fields[] = {
    SX_FIELD("name","char[106]",0,106,SX_STRING),
    SX_FIELD("chromosome_id","uint32",106,4,SX_ID),
    SX_FIELD("base_count","uint32",110,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_106_be = {UINT32_C(0x600D00EA),"bbi_chromosome_106_be",sxem_bbi_chromosome_106_be_fields,SX_COUNT(sxem_bbi_chromosome_106_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_107_le_fields[] = {
    SX_FIELD("name","char[107]",0,107,SX_STRING),
    SX_FIELD("chromosome_id","uint32",107,4,SX_ID),
    SX_FIELD("base_count","uint32",111,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_107_le = {UINT32_C(0x600D00EB),"bbi_chromosome_107_le",sxem_bbi_chromosome_107_le_fields,SX_COUNT(sxem_bbi_chromosome_107_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_107_be_fields[] = {
    SX_FIELD("name","char[107]",0,107,SX_STRING),
    SX_FIELD("chromosome_id","uint32",107,4,SX_ID),
    SX_FIELD("base_count","uint32",111,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_107_be = {UINT32_C(0x600D00EC),"bbi_chromosome_107_be",sxem_bbi_chromosome_107_be_fields,SX_COUNT(sxem_bbi_chromosome_107_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_108_le_fields[] = {
    SX_FIELD("name","char[108]",0,108,SX_STRING),
    SX_FIELD("chromosome_id","uint32",108,4,SX_ID),
    SX_FIELD("base_count","uint32",112,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_108_le = {UINT32_C(0x600D00ED),"bbi_chromosome_108_le",sxem_bbi_chromosome_108_le_fields,SX_COUNT(sxem_bbi_chromosome_108_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_108_be_fields[] = {
    SX_FIELD("name","char[108]",0,108,SX_STRING),
    SX_FIELD("chromosome_id","uint32",108,4,SX_ID),
    SX_FIELD("base_count","uint32",112,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_108_be = {UINT32_C(0x600D00EE),"bbi_chromosome_108_be",sxem_bbi_chromosome_108_be_fields,SX_COUNT(sxem_bbi_chromosome_108_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_109_le_fields[] = {
    SX_FIELD("name","char[109]",0,109,SX_STRING),
    SX_FIELD("chromosome_id","uint32",109,4,SX_ID),
    SX_FIELD("base_count","uint32",113,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_109_le = {UINT32_C(0x600D00EF),"bbi_chromosome_109_le",sxem_bbi_chromosome_109_le_fields,SX_COUNT(sxem_bbi_chromosome_109_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_109_be_fields[] = {
    SX_FIELD("name","char[109]",0,109,SX_STRING),
    SX_FIELD("chromosome_id","uint32",109,4,SX_ID),
    SX_FIELD("base_count","uint32",113,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_109_be = {UINT32_C(0x600D00F0),"bbi_chromosome_109_be",sxem_bbi_chromosome_109_be_fields,SX_COUNT(sxem_bbi_chromosome_109_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_110_le_fields[] = {
    SX_FIELD("name","char[110]",0,110,SX_STRING),
    SX_FIELD("chromosome_id","uint32",110,4,SX_ID),
    SX_FIELD("base_count","uint32",114,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_110_le = {UINT32_C(0x600D00F1),"bbi_chromosome_110_le",sxem_bbi_chromosome_110_le_fields,SX_COUNT(sxem_bbi_chromosome_110_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_110_be_fields[] = {
    SX_FIELD("name","char[110]",0,110,SX_STRING),
    SX_FIELD("chromosome_id","uint32",110,4,SX_ID),
    SX_FIELD("base_count","uint32",114,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_110_be = {UINT32_C(0x600D00F2),"bbi_chromosome_110_be",sxem_bbi_chromosome_110_be_fields,SX_COUNT(sxem_bbi_chromosome_110_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_111_le_fields[] = {
    SX_FIELD("name","char[111]",0,111,SX_STRING),
    SX_FIELD("chromosome_id","uint32",111,4,SX_ID),
    SX_FIELD("base_count","uint32",115,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_111_le = {UINT32_C(0x600D00F3),"bbi_chromosome_111_le",sxem_bbi_chromosome_111_le_fields,SX_COUNT(sxem_bbi_chromosome_111_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_111_be_fields[] = {
    SX_FIELD("name","char[111]",0,111,SX_STRING),
    SX_FIELD("chromosome_id","uint32",111,4,SX_ID),
    SX_FIELD("base_count","uint32",115,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_111_be = {UINT32_C(0x600D00F4),"bbi_chromosome_111_be",sxem_bbi_chromosome_111_be_fields,SX_COUNT(sxem_bbi_chromosome_111_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_112_le_fields[] = {
    SX_FIELD("name","char[112]",0,112,SX_STRING),
    SX_FIELD("chromosome_id","uint32",112,4,SX_ID),
    SX_FIELD("base_count","uint32",116,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_112_le = {UINT32_C(0x600D00F5),"bbi_chromosome_112_le",sxem_bbi_chromosome_112_le_fields,SX_COUNT(sxem_bbi_chromosome_112_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_112_be_fields[] = {
    SX_FIELD("name","char[112]",0,112,SX_STRING),
    SX_FIELD("chromosome_id","uint32",112,4,SX_ID),
    SX_FIELD("base_count","uint32",116,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_112_be = {UINT32_C(0x600D00F6),"bbi_chromosome_112_be",sxem_bbi_chromosome_112_be_fields,SX_COUNT(sxem_bbi_chromosome_112_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_113_le_fields[] = {
    SX_FIELD("name","char[113]",0,113,SX_STRING),
    SX_FIELD("chromosome_id","uint32",113,4,SX_ID),
    SX_FIELD("base_count","uint32",117,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_113_le = {UINT32_C(0x600D00F7),"bbi_chromosome_113_le",sxem_bbi_chromosome_113_le_fields,SX_COUNT(sxem_bbi_chromosome_113_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_113_be_fields[] = {
    SX_FIELD("name","char[113]",0,113,SX_STRING),
    SX_FIELD("chromosome_id","uint32",113,4,SX_ID),
    SX_FIELD("base_count","uint32",117,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_113_be = {UINT32_C(0x600D00F8),"bbi_chromosome_113_be",sxem_bbi_chromosome_113_be_fields,SX_COUNT(sxem_bbi_chromosome_113_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_114_le_fields[] = {
    SX_FIELD("name","char[114]",0,114,SX_STRING),
    SX_FIELD("chromosome_id","uint32",114,4,SX_ID),
    SX_FIELD("base_count","uint32",118,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_114_le = {UINT32_C(0x600D00F9),"bbi_chromosome_114_le",sxem_bbi_chromosome_114_le_fields,SX_COUNT(sxem_bbi_chromosome_114_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_114_be_fields[] = {
    SX_FIELD("name","char[114]",0,114,SX_STRING),
    SX_FIELD("chromosome_id","uint32",114,4,SX_ID),
    SX_FIELD("base_count","uint32",118,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_114_be = {UINT32_C(0x600D00FA),"bbi_chromosome_114_be",sxem_bbi_chromosome_114_be_fields,SX_COUNT(sxem_bbi_chromosome_114_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_115_le_fields[] = {
    SX_FIELD("name","char[115]",0,115,SX_STRING),
    SX_FIELD("chromosome_id","uint32",115,4,SX_ID),
    SX_FIELD("base_count","uint32",119,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_115_le = {UINT32_C(0x600D00FB),"bbi_chromosome_115_le",sxem_bbi_chromosome_115_le_fields,SX_COUNT(sxem_bbi_chromosome_115_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_115_be_fields[] = {
    SX_FIELD("name","char[115]",0,115,SX_STRING),
    SX_FIELD("chromosome_id","uint32",115,4,SX_ID),
    SX_FIELD("base_count","uint32",119,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_115_be = {UINT32_C(0x600D00FC),"bbi_chromosome_115_be",sxem_bbi_chromosome_115_be_fields,SX_COUNT(sxem_bbi_chromosome_115_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_116_le_fields[] = {
    SX_FIELD("name","char[116]",0,116,SX_STRING),
    SX_FIELD("chromosome_id","uint32",116,4,SX_ID),
    SX_FIELD("base_count","uint32",120,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_116_le = {UINT32_C(0x600D00FD),"bbi_chromosome_116_le",sxem_bbi_chromosome_116_le_fields,SX_COUNT(sxem_bbi_chromosome_116_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_116_be_fields[] = {
    SX_FIELD("name","char[116]",0,116,SX_STRING),
    SX_FIELD("chromosome_id","uint32",116,4,SX_ID),
    SX_FIELD("base_count","uint32",120,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_116_be = {UINT32_C(0x600D00FE),"bbi_chromosome_116_be",sxem_bbi_chromosome_116_be_fields,SX_COUNT(sxem_bbi_chromosome_116_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_117_le_fields[] = {
    SX_FIELD("name","char[117]",0,117,SX_STRING),
    SX_FIELD("chromosome_id","uint32",117,4,SX_ID),
    SX_FIELD("base_count","uint32",121,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_117_le = {UINT32_C(0x600D00FF),"bbi_chromosome_117_le",sxem_bbi_chromosome_117_le_fields,SX_COUNT(sxem_bbi_chromosome_117_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_117_be_fields[] = {
    SX_FIELD("name","char[117]",0,117,SX_STRING),
    SX_FIELD("chromosome_id","uint32",117,4,SX_ID),
    SX_FIELD("base_count","uint32",121,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_117_be = {UINT32_C(0x600D0100),"bbi_chromosome_117_be",sxem_bbi_chromosome_117_be_fields,SX_COUNT(sxem_bbi_chromosome_117_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_118_le_fields[] = {
    SX_FIELD("name","char[118]",0,118,SX_STRING),
    SX_FIELD("chromosome_id","uint32",118,4,SX_ID),
    SX_FIELD("base_count","uint32",122,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_118_le = {UINT32_C(0x600D0101),"bbi_chromosome_118_le",sxem_bbi_chromosome_118_le_fields,SX_COUNT(sxem_bbi_chromosome_118_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_118_be_fields[] = {
    SX_FIELD("name","char[118]",0,118,SX_STRING),
    SX_FIELD("chromosome_id","uint32",118,4,SX_ID),
    SX_FIELD("base_count","uint32",122,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_118_be = {UINT32_C(0x600D0102),"bbi_chromosome_118_be",sxem_bbi_chromosome_118_be_fields,SX_COUNT(sxem_bbi_chromosome_118_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_119_le_fields[] = {
    SX_FIELD("name","char[119]",0,119,SX_STRING),
    SX_FIELD("chromosome_id","uint32",119,4,SX_ID),
    SX_FIELD("base_count","uint32",123,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_119_le = {UINT32_C(0x600D0103),"bbi_chromosome_119_le",sxem_bbi_chromosome_119_le_fields,SX_COUNT(sxem_bbi_chromosome_119_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_119_be_fields[] = {
    SX_FIELD("name","char[119]",0,119,SX_STRING),
    SX_FIELD("chromosome_id","uint32",119,4,SX_ID),
    SX_FIELD("base_count","uint32",123,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_119_be = {UINT32_C(0x600D0104),"bbi_chromosome_119_be",sxem_bbi_chromosome_119_be_fields,SX_COUNT(sxem_bbi_chromosome_119_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_120_le_fields[] = {
    SX_FIELD("name","char[120]",0,120,SX_STRING),
    SX_FIELD("chromosome_id","uint32",120,4,SX_ID),
    SX_FIELD("base_count","uint32",124,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_120_le = {UINT32_C(0x600D0105),"bbi_chromosome_120_le",sxem_bbi_chromosome_120_le_fields,SX_COUNT(sxem_bbi_chromosome_120_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_120_be_fields[] = {
    SX_FIELD("name","char[120]",0,120,SX_STRING),
    SX_FIELD("chromosome_id","uint32",120,4,SX_ID),
    SX_FIELD("base_count","uint32",124,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_120_be = {UINT32_C(0x600D0106),"bbi_chromosome_120_be",sxem_bbi_chromosome_120_be_fields,SX_COUNT(sxem_bbi_chromosome_120_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_121_le_fields[] = {
    SX_FIELD("name","char[121]",0,121,SX_STRING),
    SX_FIELD("chromosome_id","uint32",121,4,SX_ID),
    SX_FIELD("base_count","uint32",125,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_121_le = {UINT32_C(0x600D0107),"bbi_chromosome_121_le",sxem_bbi_chromosome_121_le_fields,SX_COUNT(sxem_bbi_chromosome_121_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_121_be_fields[] = {
    SX_FIELD("name","char[121]",0,121,SX_STRING),
    SX_FIELD("chromosome_id","uint32",121,4,SX_ID),
    SX_FIELD("base_count","uint32",125,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_121_be = {UINT32_C(0x600D0108),"bbi_chromosome_121_be",sxem_bbi_chromosome_121_be_fields,SX_COUNT(sxem_bbi_chromosome_121_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_122_le_fields[] = {
    SX_FIELD("name","char[122]",0,122,SX_STRING),
    SX_FIELD("chromosome_id","uint32",122,4,SX_ID),
    SX_FIELD("base_count","uint32",126,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_122_le = {UINT32_C(0x600D0109),"bbi_chromosome_122_le",sxem_bbi_chromosome_122_le_fields,SX_COUNT(sxem_bbi_chromosome_122_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_122_be_fields[] = {
    SX_FIELD("name","char[122]",0,122,SX_STRING),
    SX_FIELD("chromosome_id","uint32",122,4,SX_ID),
    SX_FIELD("base_count","uint32",126,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_122_be = {UINT32_C(0x600D010A),"bbi_chromosome_122_be",sxem_bbi_chromosome_122_be_fields,SX_COUNT(sxem_bbi_chromosome_122_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_123_le_fields[] = {
    SX_FIELD("name","char[123]",0,123,SX_STRING),
    SX_FIELD("chromosome_id","uint32",123,4,SX_ID),
    SX_FIELD("base_count","uint32",127,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_123_le = {UINT32_C(0x600D010B),"bbi_chromosome_123_le",sxem_bbi_chromosome_123_le_fields,SX_COUNT(sxem_bbi_chromosome_123_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_123_be_fields[] = {
    SX_FIELD("name","char[123]",0,123,SX_STRING),
    SX_FIELD("chromosome_id","uint32",123,4,SX_ID),
    SX_FIELD("base_count","uint32",127,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_123_be = {UINT32_C(0x600D010C),"bbi_chromosome_123_be",sxem_bbi_chromosome_123_be_fields,SX_COUNT(sxem_bbi_chromosome_123_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_124_le_fields[] = {
    SX_FIELD("name","char[124]",0,124,SX_STRING),
    SX_FIELD("chromosome_id","uint32",124,4,SX_ID),
    SX_FIELD("base_count","uint32",128,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_124_le = {UINT32_C(0x600D010D),"bbi_chromosome_124_le",sxem_bbi_chromosome_124_le_fields,SX_COUNT(sxem_bbi_chromosome_124_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_124_be_fields[] = {
    SX_FIELD("name","char[124]",0,124,SX_STRING),
    SX_FIELD("chromosome_id","uint32",124,4,SX_ID),
    SX_FIELD("base_count","uint32",128,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_124_be = {UINT32_C(0x600D010E),"bbi_chromosome_124_be",sxem_bbi_chromosome_124_be_fields,SX_COUNT(sxem_bbi_chromosome_124_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_125_le_fields[] = {
    SX_FIELD("name","char[125]",0,125,SX_STRING),
    SX_FIELD("chromosome_id","uint32",125,4,SX_ID),
    SX_FIELD("base_count","uint32",129,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_125_le = {UINT32_C(0x600D010F),"bbi_chromosome_125_le",sxem_bbi_chromosome_125_le_fields,SX_COUNT(sxem_bbi_chromosome_125_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_125_be_fields[] = {
    SX_FIELD("name","char[125]",0,125,SX_STRING),
    SX_FIELD("chromosome_id","uint32",125,4,SX_ID),
    SX_FIELD("base_count","uint32",129,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_125_be = {UINT32_C(0x600D0110),"bbi_chromosome_125_be",sxem_bbi_chromosome_125_be_fields,SX_COUNT(sxem_bbi_chromosome_125_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_126_le_fields[] = {
    SX_FIELD("name","char[126]",0,126,SX_STRING),
    SX_FIELD("chromosome_id","uint32",126,4,SX_ID),
    SX_FIELD("base_count","uint32",130,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_126_le = {UINT32_C(0x600D0111),"bbi_chromosome_126_le",sxem_bbi_chromosome_126_le_fields,SX_COUNT(sxem_bbi_chromosome_126_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_126_be_fields[] = {
    SX_FIELD("name","char[126]",0,126,SX_STRING),
    SX_FIELD("chromosome_id","uint32",126,4,SX_ID),
    SX_FIELD("base_count","uint32",130,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_126_be = {UINT32_C(0x600D0112),"bbi_chromosome_126_be",sxem_bbi_chromosome_126_be_fields,SX_COUNT(sxem_bbi_chromosome_126_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_127_le_fields[] = {
    SX_FIELD("name","char[127]",0,127,SX_STRING),
    SX_FIELD("chromosome_id","uint32",127,4,SX_ID),
    SX_FIELD("base_count","uint32",131,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_127_le = {UINT32_C(0x600D0113),"bbi_chromosome_127_le",sxem_bbi_chromosome_127_le_fields,SX_COUNT(sxem_bbi_chromosome_127_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_127_be_fields[] = {
    SX_FIELD("name","char[127]",0,127,SX_STRING),
    SX_FIELD("chromosome_id","uint32",127,4,SX_ID),
    SX_FIELD("base_count","uint32",131,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_127_be = {UINT32_C(0x600D0114),"bbi_chromosome_127_be",sxem_bbi_chromosome_127_be_fields,SX_COUNT(sxem_bbi_chromosome_127_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_128_le_fields[] = {
    SX_FIELD("name","char[128]",0,128,SX_STRING),
    SX_FIELD("chromosome_id","uint32",128,4,SX_ID),
    SX_FIELD("base_count","uint32",132,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_128_le = {UINT32_C(0x600D0115),"bbi_chromosome_128_le",sxem_bbi_chromosome_128_le_fields,SX_COUNT(sxem_bbi_chromosome_128_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_chromosome_128_be_fields[] = {
    SX_FIELD("name","char[128]",0,128,SX_STRING),
    SX_FIELD("chromosome_id","uint32",128,4,SX_ID),
    SX_FIELD("base_count","uint32",132,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_chromosome_128_be = {UINT32_C(0x600D0116),"bbi_chromosome_128_be",sxem_bbi_chromosome_128_be_fields,SX_COUNT(sxem_bbi_chromosome_128_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_interval_tree_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("block_capacity","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("item_count","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("start_chromosome","uint32",16,4,SX_NONE),
    SX_FIELD("start_base","uint32",20,4,SX_NONE),
    SX_FIELD("end_chromosome","uint32",24,4,SX_NONE),
    SX_FIELD("end_base","uint32",28,4,SX_NONE),
    SX_FIELD("end_file_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("items_per_slot","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",44,4,SX_RESERVED),
};
static const sx_layout sxem_bbi_interval_tree_le = {UINT32_C(0x600D0117),"bbi_interval_tree_le",sxem_bbi_interval_tree_le_fields,SX_COUNT(sxem_bbi_interval_tree_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_interval_tree_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("block_capacity","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("item_count","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("start_chromosome","uint32",16,4,SX_NONE),
    SX_FIELD("start_base","uint32",20,4,SX_NONE),
    SX_FIELD("end_chromosome","uint32",24,4,SX_NONE),
    SX_FIELD("end_base","uint32",28,4,SX_NONE),
    SX_FIELD("end_file_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("items_per_slot","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",44,4,SX_RESERVED),
};
static const sx_layout sxem_bbi_interval_tree_be = {UINT32_C(0x600D0118),"bbi_interval_tree_be",sxem_bbi_interval_tree_be_fields,SX_COUNT(sxem_bbi_interval_tree_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_interval_leaf_le_fields[] = {
    SX_FIELD("start_chromosome","uint32",0,4,SX_NONE),
    SX_FIELD("start_base","uint32",4,4,SX_NONE),
    SX_FIELD("end_chromosome","uint32",8,4,SX_NONE),
    SX_FIELD("end_base","uint32",12,4,SX_NONE),
    SX_FIELD("data_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("data_size","uint64",24,8,SX_SIZE),
};
static const sx_layout sxem_bbi_interval_leaf_le = {UINT32_C(0x600D0119),"bbi_interval_leaf_le",sxem_bbi_interval_leaf_le_fields,SX_COUNT(sxem_bbi_interval_leaf_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_interval_leaf_be_fields[] = {
    SX_FIELD("start_chromosome","uint32",0,4,SX_NONE),
    SX_FIELD("start_base","uint32",4,4,SX_NONE),
    SX_FIELD("end_chromosome","uint32",8,4,SX_NONE),
    SX_FIELD("end_base","uint32",12,4,SX_NONE),
    SX_FIELD("data_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("data_size","uint64",24,8,SX_SIZE),
};
static const sx_layout sxem_bbi_interval_leaf_be = {UINT32_C(0x600D011A),"bbi_interval_leaf_be",sxem_bbi_interval_leaf_be_fields,SX_COUNT(sxem_bbi_interval_leaf_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_total_summary_le_fields[] = {
    SX_FIELD("bases_covered","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("minimum","float64",8,8,SX_NONE),
    SX_FIELD("maximum","float64",16,8,SX_NONE),
    SX_FIELD("sum","float64",24,8,SX_NONE),
    SX_FIELD("sum_squares","float64",32,8,SX_NONE),
};
static const sx_layout sxem_bbi_total_summary_le = {UINT32_C(0x600D011B),"bbi_total_summary_le",sxem_bbi_total_summary_le_fields,SX_COUNT(sxem_bbi_total_summary_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_total_summary_be_fields[] = {
    SX_FIELD("bases_covered","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("minimum","float64",8,8,SX_NONE),
    SX_FIELD("maximum","float64",16,8,SX_NONE),
    SX_FIELD("sum","float64",24,8,SX_NONE),
    SX_FIELD("sum_squares","float64",32,8,SX_NONE),
};
static const sx_layout sxem_bbi_total_summary_be = {UINT32_C(0x600D011C),"bbi_total_summary_be",sxem_bbi_total_summary_be_fields,SX_COUNT(sxem_bbi_total_summary_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_extension_le_fields[] = {
    SX_FIELD("extension_size","uint16",0,2,SX_SIZE),
    SX_FIELD("extra_index_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("extra_index_list_offset","uint64",4,8,SX_OFFSET),
    SX_FIELD("reserved","uint8[52]",12,52,SX_RESERVED),
};
static const sx_layout sxem_bbi_extension_le = {UINT32_C(0x600D011D),"bbi_extension_le",sxem_bbi_extension_le_fields,SX_COUNT(sxem_bbi_extension_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_extension_be_fields[] = {
    SX_FIELD("extension_size","uint16",0,2,SX_SIZE),
    SX_FIELD("extra_index_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("extra_index_list_offset","uint64",4,8,SX_OFFSET),
    SX_FIELD("reserved","uint8[52]",12,52,SX_RESERVED),
};
static const sx_layout sxem_bbi_extension_be = {UINT32_C(0x600D011E),"bbi_extension_be",sxem_bbi_extension_be_fields,SX_COUNT(sxem_bbi_extension_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_data_count_le_fields[] = {
    SX_FIELD("record_count","uint64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_data_count_le = {UINT32_C(0x600D011F),"bbi_data_count_le",sxem_bbi_data_count_le_fields,SX_COUNT(sxem_bbi_data_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_data_count_be_fields[] = {
    SX_FIELD("record_count","uint64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_data_count_be = {UINT32_C(0x600D0120),"bbi_data_count_be",sxem_bbi_data_count_be_fields,SX_COUNT(sxem_bbi_data_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_zoom_count_le_fields[] = {
    SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_zoom_count_le = {UINT32_C(0x600D0121),"bbi_zoom_count_le",sxem_bbi_zoom_count_le_fields,SX_COUNT(sxem_bbi_zoom_count_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_zoom_count_be_fields[] = {
    SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_zoom_count_be = {UINT32_C(0x600D0122),"bbi_zoom_count_be",sxem_bbi_zoom_count_be_fields,SX_COUNT(sxem_bbi_zoom_count_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_trailer_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxem_bbi_trailer_le = {UINT32_C(0x600D0123),"bbi_trailer_le",sxem_bbi_trailer_le_fields,SX_COUNT(sxem_bbi_trailer_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_trailer_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxem_bbi_trailer_be = {UINT32_C(0x600D0124),"bbi_trailer_be",sxem_bbi_trailer_be_fields,SX_COUNT(sxem_bbi_trailer_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_wig_section_le_fields[] = {
    SX_FIELD("chromosome_id","uint32",0,4,SX_NONE),
    SX_FIELD("start_base","uint32",4,4,SX_NONE),
    SX_FIELD("end_base","uint32",8,4,SX_NONE),
    SX_FIELD("step_bases","uint32",12,4,SX_NONE),
    SX_FIELD("span_bases","uint32",16,4,SX_NONE),
    SX_FIELD("type","uint8",20,1,SX_ID),
    SX_FIELD("reserved","uint8",21,1,SX_RESERVED),
    SX_FIELD("item_count","uint16",22,2,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_wig_section_le = {UINT32_C(0x600D0125),"bbi_wig_section_le",sxem_bbi_wig_section_le_fields,SX_COUNT(sxem_bbi_wig_section_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_wig_section_be_fields[] = {
    SX_FIELD("chromosome_id","uint32",0,4,SX_NONE),
    SX_FIELD("start_base","uint32",4,4,SX_NONE),
    SX_FIELD("end_base","uint32",8,4,SX_NONE),
    SX_FIELD("step_bases","uint32",12,4,SX_NONE),
    SX_FIELD("span_bases","uint32",16,4,SX_NONE),
    SX_FIELD("type","uint8",20,1,SX_ID),
    SX_FIELD("reserved","uint8",21,1,SX_RESERVED),
    SX_FIELD("item_count","uint16",22,2,SX_COUNT_PROP),
};
static const sx_layout sxem_bbi_wig_section_be = {UINT32_C(0x600D0126),"bbi_wig_section_be",sxem_bbi_wig_section_be_fields,SX_COUNT(sxem_bbi_wig_section_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_bedgraph_le_fields[] = {
    SX_FIELD("start_base","uint32",0,4,SX_NONE),
    SX_FIELD("end_base","uint32",4,4,SX_NONE),
    SX_FIELD("value","float32",8,4,SX_NONE),
};
static const sx_layout sxem_bbi_bedgraph_le = {UINT32_C(0x600D0127),"bbi_bedgraph_le",sxem_bbi_bedgraph_le_fields,SX_COUNT(sxem_bbi_bedgraph_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_bedgraph_be_fields[] = {
    SX_FIELD("start_base","uint32",0,4,SX_NONE),
    SX_FIELD("end_base","uint32",4,4,SX_NONE),
    SX_FIELD("value","float32",8,4,SX_NONE),
};
static const sx_layout sxem_bbi_bedgraph_be = {UINT32_C(0x600D0128),"bbi_bedgraph_be",sxem_bbi_bedgraph_be_fields,SX_COUNT(sxem_bbi_bedgraph_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_variable_step_le_fields[] = {
    SX_FIELD("start_base","uint32",0,4,SX_NONE),
    SX_FIELD("value","float32",4,4,SX_NONE),
};
static const sx_layout sxem_bbi_variable_step_le = {UINT32_C(0x600D0129),"bbi_variable_step_le",sxem_bbi_variable_step_le_fields,SX_COUNT(sxem_bbi_variable_step_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_variable_step_be_fields[] = {
    SX_FIELD("start_base","uint32",0,4,SX_NONE),
    SX_FIELD("value","float32",4,4,SX_NONE),
};
static const sx_layout sxem_bbi_variable_step_be = {UINT32_C(0x600D012A),"bbi_variable_step_be",sxem_bbi_variable_step_be_fields,SX_COUNT(sxem_bbi_variable_step_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_fixed_step_le_fields[] = {
    SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxem_bbi_fixed_step_le = {UINT32_C(0x600D012B),"bbi_fixed_step_le",sxem_bbi_fixed_step_le_fields,SX_COUNT(sxem_bbi_fixed_step_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_fixed_step_be_fields[] = {
    SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxem_bbi_fixed_step_be = {UINT32_C(0x600D012C),"bbi_fixed_step_be",sxem_bbi_fixed_step_be_fields,SX_COUNT(sxem_bbi_fixed_step_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_bed_record_le_fields[] = {
    SX_FIELD("chromosome_id","uint32",0,4,SX_NONE),
    SX_FIELD("start_base","uint32",4,4,SX_NONE),
    SX_FIELD("end_base","uint32",8,4,SX_NONE),
};
static const sx_layout sxem_bbi_bed_record_le = {UINT32_C(0x600D012D),"bbi_bed_record_le",sxem_bbi_bed_record_le_fields,SX_COUNT(sxem_bbi_bed_record_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_bed_record_be_fields[] = {
    SX_FIELD("chromosome_id","uint32",0,4,SX_NONE),
    SX_FIELD("start_base","uint32",4,4,SX_NONE),
    SX_FIELD("end_base","uint32",8,4,SX_NONE),
};
static const sx_layout sxem_bbi_bed_record_be = {UINT32_C(0x600D012E),"bbi_bed_record_be",sxem_bbi_bed_record_be_fields,SX_COUNT(sxem_bbi_bed_record_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_bbi_zoom_record_le_fields[] = {
    SX_FIELD("chromosome_id","uint32",0,4,SX_NONE),
    SX_FIELD("start_base","uint32",4,4,SX_NONE),
    SX_FIELD("end_base","uint32",8,4,SX_NONE),
    SX_FIELD("valid_base_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("minimum","float32",16,4,SX_NONE),
    SX_FIELD("maximum","float32",20,4,SX_NONE),
    SX_FIELD("sum","float32",24,4,SX_NONE),
    SX_FIELD("sum_squares","float32",28,4,SX_NONE),
};
static const sx_layout sxem_bbi_zoom_record_le = {UINT32_C(0x600D012F),"bbi_zoom_record_le",sxem_bbi_zoom_record_le_fields,SX_COUNT(sxem_bbi_zoom_record_le_fields),SX_LE};
static const xx_data_struct_field_desc sxem_bbi_zoom_record_be_fields[] = {
    SX_FIELD("chromosome_id","uint32",0,4,SX_NONE),
    SX_FIELD("start_base","uint32",4,4,SX_NONE),
    SX_FIELD("end_base","uint32",8,4,SX_NONE),
    SX_FIELD("valid_base_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("minimum","float32",16,4,SX_NONE),
    SX_FIELD("maximum","float32",20,4,SX_NONE),
    SX_FIELD("sum","float32",24,4,SX_NONE),
    SX_FIELD("sum_squares","float32",28,4,SX_NONE),
};
static const sx_layout sxem_bbi_zoom_record_be = {UINT32_C(0x600D0130),"bbi_zoom_record_be",sxem_bbi_zoom_record_be_fields,SX_COUNT(sxem_bbi_zoom_record_be_fields),SX_BE};
static const xx_data_struct_field_desc sxem_rstm_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("version","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size","uint16",12,2,SX_SIZE),
    SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("head_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("head_size","uint32",20,4,SX_SIZE),
    SX_FIELD("adpc_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("adpc_size","uint32",28,4,SX_SIZE),
    SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",36,4,SX_SIZE),
    SX_FIELD("reserved","uint8[24]",40,24,SX_RESERVED),
};
static const sx_layout sxem_rstm_header = {UINT32_C(0x600D0131),"rstm_header",sxem_rstm_header_fields,SX_COUNT(sxem_rstm_header_fields),SX_BE};
static const xx_data_struct_field_desc sxem_rwav_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("version","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_size","uint16",12,2,SX_SIZE),
    SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("info_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("info_size","uint32",20,4,SX_SIZE),
    SX_FIELD("data_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxem_rwav_header = {UINT32_C(0x600D0132),"rwav_header",sxem_rwav_header_fields,SX_COUNT(sxem_rwav_header_fields),SX_BE};
static const xx_data_struct_field_desc sxem_revolution_reference_fields[] = {
    SX_FIELD("reference_type","uint8",0,1,SX_ID),
    SX_FIELD("padding","uint8[3]",1,3,SX_RESERVED),
    SX_FIELD("offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxem_revolution_reference = {UINT32_C(0x600D0133),"revolution_reference",sxem_revolution_reference_fields,SX_COUNT(sxem_revolution_reference_fields),SX_BE};
static const xx_data_struct_field_desc sxem_revolution_count_fields[] = {
    SX_FIELD("record_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("padding","uint8[3]",1,3,SX_RESERVED),
};
static const sx_layout sxem_revolution_count = {UINT32_C(0x600D0134),"revolution_count",sxem_revolution_count_fields,SX_COUNT(sxem_revolution_count_fields),SX_BE};
static const xx_data_struct_field_desc sxem_revolution_offset_fields[] = {
    SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxem_revolution_offset = {UINT32_C(0x600D0135),"revolution_offset",sxem_revolution_offset_fields,SX_COUNT(sxem_revolution_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxem_rstm_stream_info_fields[] = {
    SX_FIELD("encoding","uint8",0,1,SX_NONE),
    SX_FIELD("loop_flag","uint8",1,1,SX_NONE),
    SX_FIELD("channel_count","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("sample_rate_high","uint8",3,1,SX_NONE),
    SX_FIELD("sample_rate_hz","uint16",4,2,SX_NONE),
    SX_FIELD("padding","uint16",6,2,SX_RESERVED),
    SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
    SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("sample_data_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",24,4,SX_SIZE),
    SX_FIELD("samples_per_block","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("last_block_size","uint32",32,4,SX_SIZE),
    SX_FIELD("last_block_samples","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("last_block_padded_size","uint32",40,4,SX_SIZE),
    SX_FIELD("adpc_interval_samples","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("adpc_entry_size","uint32",48,4,SX_SIZE),
};
static const sx_layout sxem_rstm_stream_info = {UINT32_C(0x600D0136),"rstm_stream_info",sxem_rstm_stream_info_fields,SX_COUNT(sxem_rstm_stream_info_fields),SX_BE};
static const xx_data_struct_field_desc sxem_rstm_track_fields[] = {
    SX_FIELD("channel_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("first_channel_id","uint8",1,1,SX_ID),
    SX_FIELD("second_channel_id","uint8",2,1,SX_ID),
    SX_FIELD("padding","uint8",3,1,SX_RESERVED),
};
static const sx_layout sxem_rstm_track = {UINT32_C(0x600D0137),"rstm_track",sxem_rstm_track_fields,SX_COUNT(sxem_rstm_track_fields),SX_BE};
static const xx_data_struct_field_desc sxem_rwav_wave_info_fields[] = {
    SX_FIELD("encoding","uint8",0,1,SX_NONE),
    SX_FIELD("loop_flag","uint8",1,1,SX_NONE),
    SX_FIELD("channel_count","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("sample_rate_high","uint8",3,1,SX_NONE),
    SX_FIELD("sample_rate_hz","uint16",4,2,SX_NONE),
    SX_FIELD("data_location_type","uint8",6,1,SX_ID),
    SX_FIELD("padding","uint8",7,1,SX_RESERVED),
    SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
    SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("channel_info_table_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("data_location_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("reserved","uint32",24,4,SX_RESERVED),
};
static const sx_layout sxem_rwav_wave_info = {UINT32_C(0x600D0138),"rwav_wave_info",sxem_rwav_wave_info_fields,SX_COUNT(sxem_rwav_wave_info_fields),SX_BE};
static const xx_data_struct_field_desc sxem_rwav_channel_fields[] = {
    SX_FIELD("channel_data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("adpcm_info_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("volume_front_left","uint8[4]",8,4,SX_NONE),
    SX_FIELD("volume_front_right","uint8[4]",12,4,SX_NONE),
    SX_FIELD("volume_back_left","uint8[4]",16,4,SX_NONE),
    SX_FIELD("volume_back_right","uint8[4]",20,4,SX_NONE),
    SX_FIELD("reserved","uint32",24,4,SX_RESERVED),
};
static const sx_layout sxem_rwav_channel = {UINT32_C(0x600D0139),"rwav_channel",sxem_rwav_channel_fields,SX_COUNT(sxem_rwav_channel_fields),SX_BE};
static const xx_data_struct_field_desc sxem_sdat_group_entry_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("load_flags","uint16",1,2,SX_FLAGS),
    SX_FIELD("padding","uint8",3,1,SX_RESERVED),
    SX_FIELD("item_id","uint32",4,4,SX_ID),
};
const sx_layout sxem_sdat_group_entry = {UINT32_C(0x600D0144),"sdat_group_entry",sxem_sdat_group_entry_fields,SX_COUNT(sxem_sdat_group_entry_fields),SX_LE};
static const sx_layout *const sx_extendedmedia_layouts[] = {
    &sxem_nw_header_le,
    &sxem_nw_header_be,
    &sxem_nw_sized_reference_le,
    &sxem_nw_sized_reference_be,
    &sxem_nw_reference_le,
    &sxem_nw_reference_be,
    &sxem_nw_block_le,
    &sxem_nw_block_be,
    &sxem_nw_wave_info_le,
    &sxem_nw_wave_info_be,
    &sxem_nw_wave_channel_le,
    &sxem_nw_wave_channel_be,
    &sxem_nw_stream_info_le,
    &sxem_nw_stream_info_be,
    &sxem_bbi_header_le,
    &sxem_bbi_header_be,
    &sxem_bbi_zoom_header_le,
    &sxem_bbi_zoom_header_be,
    &sxem_bbi_chromosome_tree_le,
    &sxem_bbi_chromosome_tree_be,
    &sxem_bbi_tree_node_le,
    &sxem_bbi_tree_node_be,
    &sxem_bbi_chromosome_1_le,
    &sxem_bbi_chromosome_1_be,
    &sxem_bbi_chromosome_2_le,
    &sxem_bbi_chromosome_2_be,
    &sxem_bbi_chromosome_3_le,
    &sxem_bbi_chromosome_3_be,
    &sxem_bbi_chromosome_4_le,
    &sxem_bbi_chromosome_4_be,
    &sxem_bbi_chromosome_5_le,
    &sxem_bbi_chromosome_5_be,
    &sxem_bbi_chromosome_6_le,
    &sxem_bbi_chromosome_6_be,
    &sxem_bbi_chromosome_7_le,
    &sxem_bbi_chromosome_7_be,
    &sxem_bbi_chromosome_8_le,
    &sxem_bbi_chromosome_8_be,
    &sxem_bbi_chromosome_9_le,
    &sxem_bbi_chromosome_9_be,
    &sxem_bbi_chromosome_10_le,
    &sxem_bbi_chromosome_10_be,
    &sxem_bbi_chromosome_11_le,
    &sxem_bbi_chromosome_11_be,
    &sxem_bbi_chromosome_12_le,
    &sxem_bbi_chromosome_12_be,
    &sxem_bbi_chromosome_13_le,
    &sxem_bbi_chromosome_13_be,
    &sxem_bbi_chromosome_14_le,
    &sxem_bbi_chromosome_14_be,
    &sxem_bbi_chromosome_15_le,
    &sxem_bbi_chromosome_15_be,
    &sxem_bbi_chromosome_16_le,
    &sxem_bbi_chromosome_16_be,
    &sxem_bbi_chromosome_17_le,
    &sxem_bbi_chromosome_17_be,
    &sxem_bbi_chromosome_18_le,
    &sxem_bbi_chromosome_18_be,
    &sxem_bbi_chromosome_19_le,
    &sxem_bbi_chromosome_19_be,
    &sxem_bbi_chromosome_20_le,
    &sxem_bbi_chromosome_20_be,
    &sxem_bbi_chromosome_21_le,
    &sxem_bbi_chromosome_21_be,
    &sxem_bbi_chromosome_22_le,
    &sxem_bbi_chromosome_22_be,
    &sxem_bbi_chromosome_23_le,
    &sxem_bbi_chromosome_23_be,
    &sxem_bbi_chromosome_24_le,
    &sxem_bbi_chromosome_24_be,
    &sxem_bbi_chromosome_25_le,
    &sxem_bbi_chromosome_25_be,
    &sxem_bbi_chromosome_26_le,
    &sxem_bbi_chromosome_26_be,
    &sxem_bbi_chromosome_27_le,
    &sxem_bbi_chromosome_27_be,
    &sxem_bbi_chromosome_28_le,
    &sxem_bbi_chromosome_28_be,
    &sxem_bbi_chromosome_29_le,
    &sxem_bbi_chromosome_29_be,
    &sxem_bbi_chromosome_30_le,
    &sxem_bbi_chromosome_30_be,
    &sxem_bbi_chromosome_31_le,
    &sxem_bbi_chromosome_31_be,
    &sxem_bbi_chromosome_32_le,
    &sxem_bbi_chromosome_32_be,
    &sxem_bbi_chromosome_33_le,
    &sxem_bbi_chromosome_33_be,
    &sxem_bbi_chromosome_34_le,
    &sxem_bbi_chromosome_34_be,
    &sxem_bbi_chromosome_35_le,
    &sxem_bbi_chromosome_35_be,
    &sxem_bbi_chromosome_36_le,
    &sxem_bbi_chromosome_36_be,
    &sxem_bbi_chromosome_37_le,
    &sxem_bbi_chromosome_37_be,
    &sxem_bbi_chromosome_38_le,
    &sxem_bbi_chromosome_38_be,
    &sxem_bbi_chromosome_39_le,
    &sxem_bbi_chromosome_39_be,
    &sxem_bbi_chromosome_40_le,
    &sxem_bbi_chromosome_40_be,
    &sxem_bbi_chromosome_41_le,
    &sxem_bbi_chromosome_41_be,
    &sxem_bbi_chromosome_42_le,
    &sxem_bbi_chromosome_42_be,
    &sxem_bbi_chromosome_43_le,
    &sxem_bbi_chromosome_43_be,
    &sxem_bbi_chromosome_44_le,
    &sxem_bbi_chromosome_44_be,
    &sxem_bbi_chromosome_45_le,
    &sxem_bbi_chromosome_45_be,
    &sxem_bbi_chromosome_46_le,
    &sxem_bbi_chromosome_46_be,
    &sxem_bbi_chromosome_47_le,
    &sxem_bbi_chromosome_47_be,
    &sxem_bbi_chromosome_48_le,
    &sxem_bbi_chromosome_48_be,
    &sxem_bbi_chromosome_49_le,
    &sxem_bbi_chromosome_49_be,
    &sxem_bbi_chromosome_50_le,
    &sxem_bbi_chromosome_50_be,
    &sxem_bbi_chromosome_51_le,
    &sxem_bbi_chromosome_51_be,
    &sxem_bbi_chromosome_52_le,
    &sxem_bbi_chromosome_52_be,
    &sxem_bbi_chromosome_53_le,
    &sxem_bbi_chromosome_53_be,
    &sxem_bbi_chromosome_54_le,
    &sxem_bbi_chromosome_54_be,
    &sxem_bbi_chromosome_55_le,
    &sxem_bbi_chromosome_55_be,
    &sxem_bbi_chromosome_56_le,
    &sxem_bbi_chromosome_56_be,
    &sxem_bbi_chromosome_57_le,
    &sxem_bbi_chromosome_57_be,
    &sxem_bbi_chromosome_58_le,
    &sxem_bbi_chromosome_58_be,
    &sxem_bbi_chromosome_59_le,
    &sxem_bbi_chromosome_59_be,
    &sxem_bbi_chromosome_60_le,
    &sxem_bbi_chromosome_60_be,
    &sxem_bbi_chromosome_61_le,
    &sxem_bbi_chromosome_61_be,
    &sxem_bbi_chromosome_62_le,
    &sxem_bbi_chromosome_62_be,
    &sxem_bbi_chromosome_63_le,
    &sxem_bbi_chromosome_63_be,
    &sxem_bbi_chromosome_64_le,
    &sxem_bbi_chromosome_64_be,
    &sxem_bbi_chromosome_65_le,
    &sxem_bbi_chromosome_65_be,
    &sxem_bbi_chromosome_66_le,
    &sxem_bbi_chromosome_66_be,
    &sxem_bbi_chromosome_67_le,
    &sxem_bbi_chromosome_67_be,
    &sxem_bbi_chromosome_68_le,
    &sxem_bbi_chromosome_68_be,
    &sxem_bbi_chromosome_69_le,
    &sxem_bbi_chromosome_69_be,
    &sxem_bbi_chromosome_70_le,
    &sxem_bbi_chromosome_70_be,
    &sxem_bbi_chromosome_71_le,
    &sxem_bbi_chromosome_71_be,
    &sxem_bbi_chromosome_72_le,
    &sxem_bbi_chromosome_72_be,
    &sxem_bbi_chromosome_73_le,
    &sxem_bbi_chromosome_73_be,
    &sxem_bbi_chromosome_74_le,
    &sxem_bbi_chromosome_74_be,
    &sxem_bbi_chromosome_75_le,
    &sxem_bbi_chromosome_75_be,
    &sxem_bbi_chromosome_76_le,
    &sxem_bbi_chromosome_76_be,
    &sxem_bbi_chromosome_77_le,
    &sxem_bbi_chromosome_77_be,
    &sxem_bbi_chromosome_78_le,
    &sxem_bbi_chromosome_78_be,
    &sxem_bbi_chromosome_79_le,
    &sxem_bbi_chromosome_79_be,
    &sxem_bbi_chromosome_80_le,
    &sxem_bbi_chromosome_80_be,
    &sxem_bbi_chromosome_81_le,
    &sxem_bbi_chromosome_81_be,
    &sxem_bbi_chromosome_82_le,
    &sxem_bbi_chromosome_82_be,
    &sxem_bbi_chromosome_83_le,
    &sxem_bbi_chromosome_83_be,
    &sxem_bbi_chromosome_84_le,
    &sxem_bbi_chromosome_84_be,
    &sxem_bbi_chromosome_85_le,
    &sxem_bbi_chromosome_85_be,
    &sxem_bbi_chromosome_86_le,
    &sxem_bbi_chromosome_86_be,
    &sxem_bbi_chromosome_87_le,
    &sxem_bbi_chromosome_87_be,
    &sxem_bbi_chromosome_88_le,
    &sxem_bbi_chromosome_88_be,
    &sxem_bbi_chromosome_89_le,
    &sxem_bbi_chromosome_89_be,
    &sxem_bbi_chromosome_90_le,
    &sxem_bbi_chromosome_90_be,
    &sxem_bbi_chromosome_91_le,
    &sxem_bbi_chromosome_91_be,
    &sxem_bbi_chromosome_92_le,
    &sxem_bbi_chromosome_92_be,
    &sxem_bbi_chromosome_93_le,
    &sxem_bbi_chromosome_93_be,
    &sxem_bbi_chromosome_94_le,
    &sxem_bbi_chromosome_94_be,
    &sxem_bbi_chromosome_95_le,
    &sxem_bbi_chromosome_95_be,
    &sxem_bbi_chromosome_96_le,
    &sxem_bbi_chromosome_96_be,
    &sxem_bbi_chromosome_97_le,
    &sxem_bbi_chromosome_97_be,
    &sxem_bbi_chromosome_98_le,
    &sxem_bbi_chromosome_98_be,
    &sxem_bbi_chromosome_99_le,
    &sxem_bbi_chromosome_99_be,
    &sxem_bbi_chromosome_100_le,
    &sxem_bbi_chromosome_100_be,
    &sxem_bbi_chromosome_101_le,
    &sxem_bbi_chromosome_101_be,
    &sxem_bbi_chromosome_102_le,
    &sxem_bbi_chromosome_102_be,
    &sxem_bbi_chromosome_103_le,
    &sxem_bbi_chromosome_103_be,
    &sxem_bbi_chromosome_104_le,
    &sxem_bbi_chromosome_104_be,
    &sxem_bbi_chromosome_105_le,
    &sxem_bbi_chromosome_105_be,
    &sxem_bbi_chromosome_106_le,
    &sxem_bbi_chromosome_106_be,
    &sxem_bbi_chromosome_107_le,
    &sxem_bbi_chromosome_107_be,
    &sxem_bbi_chromosome_108_le,
    &sxem_bbi_chromosome_108_be,
    &sxem_bbi_chromosome_109_le,
    &sxem_bbi_chromosome_109_be,
    &sxem_bbi_chromosome_110_le,
    &sxem_bbi_chromosome_110_be,
    &sxem_bbi_chromosome_111_le,
    &sxem_bbi_chromosome_111_be,
    &sxem_bbi_chromosome_112_le,
    &sxem_bbi_chromosome_112_be,
    &sxem_bbi_chromosome_113_le,
    &sxem_bbi_chromosome_113_be,
    &sxem_bbi_chromosome_114_le,
    &sxem_bbi_chromosome_114_be,
    &sxem_bbi_chromosome_115_le,
    &sxem_bbi_chromosome_115_be,
    &sxem_bbi_chromosome_116_le,
    &sxem_bbi_chromosome_116_be,
    &sxem_bbi_chromosome_117_le,
    &sxem_bbi_chromosome_117_be,
    &sxem_bbi_chromosome_118_le,
    &sxem_bbi_chromosome_118_be,
    &sxem_bbi_chromosome_119_le,
    &sxem_bbi_chromosome_119_be,
    &sxem_bbi_chromosome_120_le,
    &sxem_bbi_chromosome_120_be,
    &sxem_bbi_chromosome_121_le,
    &sxem_bbi_chromosome_121_be,
    &sxem_bbi_chromosome_122_le,
    &sxem_bbi_chromosome_122_be,
    &sxem_bbi_chromosome_123_le,
    &sxem_bbi_chromosome_123_be,
    &sxem_bbi_chromosome_124_le,
    &sxem_bbi_chromosome_124_be,
    &sxem_bbi_chromosome_125_le,
    &sxem_bbi_chromosome_125_be,
    &sxem_bbi_chromosome_126_le,
    &sxem_bbi_chromosome_126_be,
    &sxem_bbi_chromosome_127_le,
    &sxem_bbi_chromosome_127_be,
    &sxem_bbi_chromosome_128_le,
    &sxem_bbi_chromosome_128_be,
    &sxem_bbi_interval_tree_le,
    &sxem_bbi_interval_tree_be,
    &sxem_bbi_interval_leaf_le,
    &sxem_bbi_interval_leaf_be,
    &sxem_bbi_total_summary_le,
    &sxem_bbi_total_summary_be,
    &sxem_bbi_extension_le,
    &sxem_bbi_extension_be,
    &sxem_bbi_data_count_le,
    &sxem_bbi_data_count_be,
    &sxem_bbi_zoom_count_le,
    &sxem_bbi_zoom_count_be,
    &sxem_bbi_trailer_le,
    &sxem_bbi_trailer_be,
    &sxem_bbi_wig_section_le,
    &sxem_bbi_wig_section_be,
    &sxem_bbi_bedgraph_le,
    &sxem_bbi_bedgraph_be,
    &sxem_bbi_variable_step_le,
    &sxem_bbi_variable_step_be,
    &sxem_bbi_fixed_step_le,
    &sxem_bbi_fixed_step_be,
    &sxem_bbi_bed_record_le,
    &sxem_bbi_bed_record_be,
    &sxem_bbi_zoom_record_le,
    &sxem_bbi_zoom_record_be,
    &sxem_rstm_header,
    &sxem_rwav_header,
    &sxem_revolution_reference,
    &sxem_revolution_count,
    &sxem_revolution_offset,
    &sxem_rstm_stream_info,
    &sxem_rstm_track,
    &sxem_rwav_wave_info,
    &sxem_rwav_channel,
    &sxem_sdat_header,
    &sxem_nitro_header,
    &sxem_sdat_directory,
    &sxem_sdat_count,
    &sxem_sdat_offset,
    &sxem_sdat_archive_symbol,
    &sxem_sdat_sequence,
    &sxem_sdat_file_reference,
    &sxem_sdat_bank,
    &sxem_sdat_player,
    &sxem_sdat_group_entry,
    &sxem_sdat_stream_player,
    &sxem_sdat_stream,
    &sxem_sdat_fat_entry,
    &sxem_sdat_file_header,
};
/* Metadata is collected independently of payloads, sorted and completed with
 * explicit raw gaps. An overlapping or out-of-range descriptor is rejected. */
static bool sxem_span(sx_context *c,uint64_t at,uint64_t n){return at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
bool sxem_read(sx_context *c,uint64_t at,void *b,size_t n){return sxem_span(c,at,n)&&sx_read(c,(int64_t)at,b,n);}
bool sxem_add(sx_context *c,const sx_layout *l,uint64_t at,uint64_t n){if(!sxem_span(c,at,n))return false;for(size_t i=0;i<c->count;i++)if(c->items[i].id==l->id&&c->items[i].offset-c->f->base_address==(int64_t)at&&c->items[i].total_size==(int64_t)n)return true;return sxem_span(c,at,n)&&sx_add(c,l,(int64_t)at,(int64_t)n);}
bool sxem_table(sx_context *c,const sx_layout *l,uint64_t at,uint64_t stride,uint64_t count){for(size_t i=0;i<c->count;i++)if(c->items[i].id==l->id&&c->items[i].offset-c->f->base_address==(int64_t)at&&c->items[i].entry_size==(int64_t)stride&&c->items[i].count==count)return true;return stride&&count<=(uint64_t)c->size/stride&&sxem_span(c,at,stride*count)&&sx_table(c,l,(int64_t)at,(int64_t)stride,count);}
bool sxem_u32(sx_context *c,uint64_t at,bool be,uint32_t *v){return sxem_span(c,at,4)&&sx_u32(c,(int64_t)at,be,v);}
static void sxem_sort(sx_context *c){for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){xx_data_struct v=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>v.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=v;}}
static bool sxem_finish(sx_context *c){int64_t end=0;size_t n=c->count;sxem_sort(c);for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;sxem_sort(c);return !c->failed;}
#define EM_NEED(x) do{if(!(x))return false;}while(0)
#define EM_U16(p,b) xx_data_get_u16((p),2,0,(b))
#define EM_U32(p,b) xx_data_get_u32((p),4,0,(b))
#define EM_U64(p,b) xx_data_get_u64((p),8,0,(b))
#define EM_PAIR(n,b) ((b)?&sxem_##n##_be:&sxem_##n##_le)
static bool sxem_nw(sx_context *c)
{
    uint8_t h[68];uint32_t total,at[4]={0},len[4]={0};uint16_t count,header,first;
    bool be,wave=false,stream=false;const char *magic;
    switch(c->f->file_type){
    case XX_FILE_TYPE_NINTENDO_BCSTM:magic="CSTM";first=0x4000;break;
    case XX_FILE_TYPE_NINTENDO_BFSTM:magic="FSTM";first=0x4000;stream=true;break;
    case XX_FILE_TYPE_NINTENDO_BFWAV:magic="FWAV";first=0x7000;wave=true;break;
    case XX_FILE_TYPE_NINTENDO_BCWAV:magic="CWAV";first=0x7000;wave=true;break;
    case XX_FILE_TYPE_NINTENDO_BFSAR:magic="FSAR";first=0x2000;break;
    case XX_FILE_TYPE_NINTENDO_BCSAR:magic="CSAR";first=0x2000;break;
    default:return false;}
    EM_NEED(sxem_read(c,0,h,20)&&!xx_rt_memcmp(h,magic,4));be=h[4]==0xfe&&h[5]==0xff;
    EM_NEED(be||(h[4]==0xff&&h[5]==0xfe));header=EM_U16(h+6,be);total=EM_U32(h+12,be);count=EM_U16(h+16,be);
    EM_NEED(count>=2&&count<=4&&header>=20U+12U*count&&header<=total&&total<=(uint64_t)c->size);
    EM_NEED(sxem_add(c,EM_PAIR(nw_header,be),0,20)&&sxem_table(c,EM_PAIR(nw_sized_reference,be),20,12,count));
    for(unsigned i=0;i<count;i++){
        uint16_t kind;uint32_t p,n;
        EM_NEED(sxem_read(c,20U+12U*i,h,12));kind=EM_U16(h,be);p=EM_U32(h+4,be);n=EM_U32(h+8,be);
        EM_NEED(kind>=first&&kind<first+4&&p>=header&&n>=8&&p<=total&&n<=total-p&&!len[kind-first]);
        at[kind-first]=p;len[kind-first]=n;EM_NEED(sxem_read(c,p,h,8)&&EM_U32(h+4,be)==n&&sxem_add(c,EM_PAIR(nw_block,be),p,8));
    }
    if(wave){
        uint32_t channels;EM_NEED(len[0]>=32&&len[1]>=8&&sxem_read(c,(uint64_t)at[0]+8,h,24));channels=EM_U32(h+20,be);
        EM_NEED(channels&&channels<=2&&32U+(uint64_t)channels*8<=len[0]&&sxem_add(c,EM_PAIR(nw_wave_info,be),(uint64_t)at[0]+8,24)&&sxem_table(c,EM_PAIR(nw_reference,be),(uint64_t)at[0]+32,8,channels));
        for(uint32_t i=0;i<channels;i++){
            uint32_t off;EM_NEED(sxem_u32(c,(uint64_t)at[0]+36+8U*i,be,&off));uint64_t p=28U+(uint64_t)off;
            EM_NEED(p>=32U+(uint64_t)channels*8&&p<=len[0]&&20<=len[0]-p&&sxem_add(c,EM_PAIR(nw_wave_channel,be),(uint64_t)at[0]+p,20));
        }
    }else if(stream){
        uint32_t off;EM_NEED(len[0]>=32&&sxem_table(c,EM_PAIR(nw_reference,be),(uint64_t)at[0]+8,8,3)&&sxem_u32(c,(uint64_t)at[0]+12,be,&off));
        EM_NEED(off>=24&&8U+(uint64_t)off<=len[0]&&68<=len[0]-8U-(uint64_t)off&&sxem_add(c,EM_PAIR(nw_stream_info,be),(uint64_t)at[0]+8+off,68));
    }
    return true;
}
static const sx_layout *const sxem_chrom_layouts[128][2]={
{&sxem_bbi_chromosome_1_le,&sxem_bbi_chromosome_1_be},
{&sxem_bbi_chromosome_2_le,&sxem_bbi_chromosome_2_be},
{&sxem_bbi_chromosome_3_le,&sxem_bbi_chromosome_3_be},
{&sxem_bbi_chromosome_4_le,&sxem_bbi_chromosome_4_be},
{&sxem_bbi_chromosome_5_le,&sxem_bbi_chromosome_5_be},
{&sxem_bbi_chromosome_6_le,&sxem_bbi_chromosome_6_be},
{&sxem_bbi_chromosome_7_le,&sxem_bbi_chromosome_7_be},
{&sxem_bbi_chromosome_8_le,&sxem_bbi_chromosome_8_be},
{&sxem_bbi_chromosome_9_le,&sxem_bbi_chromosome_9_be},
{&sxem_bbi_chromosome_10_le,&sxem_bbi_chromosome_10_be},
{&sxem_bbi_chromosome_11_le,&sxem_bbi_chromosome_11_be},
{&sxem_bbi_chromosome_12_le,&sxem_bbi_chromosome_12_be},
{&sxem_bbi_chromosome_13_le,&sxem_bbi_chromosome_13_be},
{&sxem_bbi_chromosome_14_le,&sxem_bbi_chromosome_14_be},
{&sxem_bbi_chromosome_15_le,&sxem_bbi_chromosome_15_be},
{&sxem_bbi_chromosome_16_le,&sxem_bbi_chromosome_16_be},
{&sxem_bbi_chromosome_17_le,&sxem_bbi_chromosome_17_be},
{&sxem_bbi_chromosome_18_le,&sxem_bbi_chromosome_18_be},
{&sxem_bbi_chromosome_19_le,&sxem_bbi_chromosome_19_be},
{&sxem_bbi_chromosome_20_le,&sxem_bbi_chromosome_20_be},
{&sxem_bbi_chromosome_21_le,&sxem_bbi_chromosome_21_be},
{&sxem_bbi_chromosome_22_le,&sxem_bbi_chromosome_22_be},
{&sxem_bbi_chromosome_23_le,&sxem_bbi_chromosome_23_be},
{&sxem_bbi_chromosome_24_le,&sxem_bbi_chromosome_24_be},
{&sxem_bbi_chromosome_25_le,&sxem_bbi_chromosome_25_be},
{&sxem_bbi_chromosome_26_le,&sxem_bbi_chromosome_26_be},
{&sxem_bbi_chromosome_27_le,&sxem_bbi_chromosome_27_be},
{&sxem_bbi_chromosome_28_le,&sxem_bbi_chromosome_28_be},
{&sxem_bbi_chromosome_29_le,&sxem_bbi_chromosome_29_be},
{&sxem_bbi_chromosome_30_le,&sxem_bbi_chromosome_30_be},
{&sxem_bbi_chromosome_31_le,&sxem_bbi_chromosome_31_be},
{&sxem_bbi_chromosome_32_le,&sxem_bbi_chromosome_32_be},
{&sxem_bbi_chromosome_33_le,&sxem_bbi_chromosome_33_be},
{&sxem_bbi_chromosome_34_le,&sxem_bbi_chromosome_34_be},
{&sxem_bbi_chromosome_35_le,&sxem_bbi_chromosome_35_be},
{&sxem_bbi_chromosome_36_le,&sxem_bbi_chromosome_36_be},
{&sxem_bbi_chromosome_37_le,&sxem_bbi_chromosome_37_be},
{&sxem_bbi_chromosome_38_le,&sxem_bbi_chromosome_38_be},
{&sxem_bbi_chromosome_39_le,&sxem_bbi_chromosome_39_be},
{&sxem_bbi_chromosome_40_le,&sxem_bbi_chromosome_40_be},
{&sxem_bbi_chromosome_41_le,&sxem_bbi_chromosome_41_be},
{&sxem_bbi_chromosome_42_le,&sxem_bbi_chromosome_42_be},
{&sxem_bbi_chromosome_43_le,&sxem_bbi_chromosome_43_be},
{&sxem_bbi_chromosome_44_le,&sxem_bbi_chromosome_44_be},
{&sxem_bbi_chromosome_45_le,&sxem_bbi_chromosome_45_be},
{&sxem_bbi_chromosome_46_le,&sxem_bbi_chromosome_46_be},
{&sxem_bbi_chromosome_47_le,&sxem_bbi_chromosome_47_be},
{&sxem_bbi_chromosome_48_le,&sxem_bbi_chromosome_48_be},
{&sxem_bbi_chromosome_49_le,&sxem_bbi_chromosome_49_be},
{&sxem_bbi_chromosome_50_le,&sxem_bbi_chromosome_50_be},
{&sxem_bbi_chromosome_51_le,&sxem_bbi_chromosome_51_be},
{&sxem_bbi_chromosome_52_le,&sxem_bbi_chromosome_52_be},
{&sxem_bbi_chromosome_53_le,&sxem_bbi_chromosome_53_be},
{&sxem_bbi_chromosome_54_le,&sxem_bbi_chromosome_54_be},
{&sxem_bbi_chromosome_55_le,&sxem_bbi_chromosome_55_be},
{&sxem_bbi_chromosome_56_le,&sxem_bbi_chromosome_56_be},
{&sxem_bbi_chromosome_57_le,&sxem_bbi_chromosome_57_be},
{&sxem_bbi_chromosome_58_le,&sxem_bbi_chromosome_58_be},
{&sxem_bbi_chromosome_59_le,&sxem_bbi_chromosome_59_be},
{&sxem_bbi_chromosome_60_le,&sxem_bbi_chromosome_60_be},
{&sxem_bbi_chromosome_61_le,&sxem_bbi_chromosome_61_be},
{&sxem_bbi_chromosome_62_le,&sxem_bbi_chromosome_62_be},
{&sxem_bbi_chromosome_63_le,&sxem_bbi_chromosome_63_be},
{&sxem_bbi_chromosome_64_le,&sxem_bbi_chromosome_64_be},
{&sxem_bbi_chromosome_65_le,&sxem_bbi_chromosome_65_be},
{&sxem_bbi_chromosome_66_le,&sxem_bbi_chromosome_66_be},
{&sxem_bbi_chromosome_67_le,&sxem_bbi_chromosome_67_be},
{&sxem_bbi_chromosome_68_le,&sxem_bbi_chromosome_68_be},
{&sxem_bbi_chromosome_69_le,&sxem_bbi_chromosome_69_be},
{&sxem_bbi_chromosome_70_le,&sxem_bbi_chromosome_70_be},
{&sxem_bbi_chromosome_71_le,&sxem_bbi_chromosome_71_be},
{&sxem_bbi_chromosome_72_le,&sxem_bbi_chromosome_72_be},
{&sxem_bbi_chromosome_73_le,&sxem_bbi_chromosome_73_be},
{&sxem_bbi_chromosome_74_le,&sxem_bbi_chromosome_74_be},
{&sxem_bbi_chromosome_75_le,&sxem_bbi_chromosome_75_be},
{&sxem_bbi_chromosome_76_le,&sxem_bbi_chromosome_76_be},
{&sxem_bbi_chromosome_77_le,&sxem_bbi_chromosome_77_be},
{&sxem_bbi_chromosome_78_le,&sxem_bbi_chromosome_78_be},
{&sxem_bbi_chromosome_79_le,&sxem_bbi_chromosome_79_be},
{&sxem_bbi_chromosome_80_le,&sxem_bbi_chromosome_80_be},
{&sxem_bbi_chromosome_81_le,&sxem_bbi_chromosome_81_be},
{&sxem_bbi_chromosome_82_le,&sxem_bbi_chromosome_82_be},
{&sxem_bbi_chromosome_83_le,&sxem_bbi_chromosome_83_be},
{&sxem_bbi_chromosome_84_le,&sxem_bbi_chromosome_84_be},
{&sxem_bbi_chromosome_85_le,&sxem_bbi_chromosome_85_be},
{&sxem_bbi_chromosome_86_le,&sxem_bbi_chromosome_86_be},
{&sxem_bbi_chromosome_87_le,&sxem_bbi_chromosome_87_be},
{&sxem_bbi_chromosome_88_le,&sxem_bbi_chromosome_88_be},
{&sxem_bbi_chromosome_89_le,&sxem_bbi_chromosome_89_be},
{&sxem_bbi_chromosome_90_le,&sxem_bbi_chromosome_90_be},
{&sxem_bbi_chromosome_91_le,&sxem_bbi_chromosome_91_be},
{&sxem_bbi_chromosome_92_le,&sxem_bbi_chromosome_92_be},
{&sxem_bbi_chromosome_93_le,&sxem_bbi_chromosome_93_be},
{&sxem_bbi_chromosome_94_le,&sxem_bbi_chromosome_94_be},
{&sxem_bbi_chromosome_95_le,&sxem_bbi_chromosome_95_be},
{&sxem_bbi_chromosome_96_le,&sxem_bbi_chromosome_96_be},
{&sxem_bbi_chromosome_97_le,&sxem_bbi_chromosome_97_be},
{&sxem_bbi_chromosome_98_le,&sxem_bbi_chromosome_98_be},
{&sxem_bbi_chromosome_99_le,&sxem_bbi_chromosome_99_be},
{&sxem_bbi_chromosome_100_le,&sxem_bbi_chromosome_100_be},
{&sxem_bbi_chromosome_101_le,&sxem_bbi_chromosome_101_be},
{&sxem_bbi_chromosome_102_le,&sxem_bbi_chromosome_102_be},
{&sxem_bbi_chromosome_103_le,&sxem_bbi_chromosome_103_be},
{&sxem_bbi_chromosome_104_le,&sxem_bbi_chromosome_104_be},
{&sxem_bbi_chromosome_105_le,&sxem_bbi_chromosome_105_be},
{&sxem_bbi_chromosome_106_le,&sxem_bbi_chromosome_106_be},
{&sxem_bbi_chromosome_107_le,&sxem_bbi_chromosome_107_be},
{&sxem_bbi_chromosome_108_le,&sxem_bbi_chromosome_108_be},
{&sxem_bbi_chromosome_109_le,&sxem_bbi_chromosome_109_be},
{&sxem_bbi_chromosome_110_le,&sxem_bbi_chromosome_110_be},
{&sxem_bbi_chromosome_111_le,&sxem_bbi_chromosome_111_be},
{&sxem_bbi_chromosome_112_le,&sxem_bbi_chromosome_112_be},
{&sxem_bbi_chromosome_113_le,&sxem_bbi_chromosome_113_be},
{&sxem_bbi_chromosome_114_le,&sxem_bbi_chromosome_114_be},
{&sxem_bbi_chromosome_115_le,&sxem_bbi_chromosome_115_be},
{&sxem_bbi_chromosome_116_le,&sxem_bbi_chromosome_116_be},
{&sxem_bbi_chromosome_117_le,&sxem_bbi_chromosome_117_be},
{&sxem_bbi_chromosome_118_le,&sxem_bbi_chromosome_118_be},
{&sxem_bbi_chromosome_119_le,&sxem_bbi_chromosome_119_be},
{&sxem_bbi_chromosome_120_le,&sxem_bbi_chromosome_120_be},
{&sxem_bbi_chromosome_121_le,&sxem_bbi_chromosome_121_be},
{&sxem_bbi_chromosome_122_le,&sxem_bbi_chromosome_122_be},
{&sxem_bbi_chromosome_123_le,&sxem_bbi_chromosome_123_be},
{&sxem_bbi_chromosome_124_le,&sxem_bbi_chromosome_124_be},
{&sxem_bbi_chromosome_125_le,&sxem_bbi_chromosome_125_be},
{&sxem_bbi_chromosome_126_le,&sxem_bbi_chromosome_126_be},
{&sxem_bbi_chromosome_127_le,&sxem_bbi_chromosome_127_be},
{&sxem_bbi_chromosome_128_le,&sxem_bbi_chromosome_128_be}
};
static bool sxem_bbi_data(sx_context *c,uint64_t at,uint64_t size,bool be,bool bed,bool zoom)
{
    uint8_t h[24];uint64_t end;unsigned work=0;
    EM_NEED(sxem_span(c,at,size));end=at+size;
    if(zoom)return size&&size%32==0&&sxem_table(c,EM_PAIR(bbi_zoom_record,be),at,32,size/32);
    while(at<end){
        EM_NEED(++work<=65536);
        if(bed){
            uint64_t p=at+12;uint8_t ch;
            EM_NEED(end-at>=13&&sxem_add(c,EM_PAIR(bbi_bed_record,be),at,12));
            do{EM_NEED(p<end&&p-at<=65548&&sxem_read(c,p++,&ch,1));}while(ch);
            at=p;
        }else{
            uint32_t count,width;const sx_layout *l;
            EM_NEED(end-at>=24&&sxem_read(c,at,h,24));count=EM_U16(h+22,be);
            switch(h[20]){case 1:width=12;l=EM_PAIR(bbi_bedgraph,be);break;case 2:width=8;l=EM_PAIR(bbi_variable_step,be);break;case 3:width=4;l=EM_PAIR(bbi_fixed_step,be);break;default:return false;}
            EM_NEED(count&&count<=(end-at-24)/width&&sxem_add(c,EM_PAIR(bbi_wig_section,be),at,24)&&sxem_table(c,l,at+24,width,count));at+=24U+(uint64_t)count*width;
        }
    }
    return at==end;
}
static bool sxem_bbi_index(sx_context *c,uint64_t index,uint64_t data,uint64_t limit,bool be,bool bed,bool zoom,bool compressed)
{
    uint8_t h[52],leaf[32];uint32_t count;uint64_t next;
    EM_NEED(index<limit&&limit<=(uint64_t)c->size&&limit-index>=52&&sxem_read(c,index,h,52)&&EM_U32(h,be)==0x2468ace0&&h[48]==1);
    count=EM_U16(h+50,be);EM_NEED(count&&count<=1024&&count<=(limit-index-52)/32);
    EM_NEED(data<index&&index-data>=(zoom?4U:8U)&&sxem_add(c,zoom?EM_PAIR(bbi_zoom_count,be):EM_PAIR(bbi_data_count,be),data,zoom?4:8));
    EM_NEED(sxem_add(c,EM_PAIR(bbi_interval_tree,be),index,48)&&sxem_add(c,EM_PAIR(bbi_tree_node,be),index+48,4)&&sxem_table(c,EM_PAIR(bbi_interval_leaf,be),index+52,32,count));
    next=data+(zoom?4:8);
    for(unsigned i=0;i<count;i++){
        uint64_t p,n;EM_NEED(sxem_read(c,index+52U+(uint64_t)i*32,leaf,32));p=EM_U64(leaf+16,be);n=EM_U64(leaf+24,be);
        EM_NEED(p==next&&p<=index&&n&&n<=index-p);
        if(!compressed)EM_NEED(sxem_bbi_data(c,p,n,be,bed,zoom));next=p+n;
    }
    return next==index;
}
static bool sxem_bbi(sx_context *c)
{
    uint8_t h[64],t[36];bool bed=c->f->file_type==XX_FILE_TYPE_UCSC_BIGBED,be;uint32_t magic=bed?0x8789f2eb:0x888ffc26,key,count;uint16_t zooms;
    uint64_t chrom,data,index,summary,ext,limit;bool compressed;
    EM_NEED(c->size>=152&&sxem_read(c,0,h,64));be=EM_U32(h,true)==magic;EM_NEED(EM_U32(h,be)==magic&&EM_U16(h+4,be)==4);
    zooms=EM_U16(h+6,be);chrom=EM_U64(h+8,be);data=EM_U64(h+16,be);index=EM_U64(h+24,be);summary=EM_U64(h+44,be);ext=EM_U64(h+56,be);compressed=EM_U32(h+52,be)!=0;
    EM_NEED(zooms<=10&&chrom>=64U+(uint64_t)zooms*24&&chrom<data&&data<index&&index<(uint64_t)c->size-4);
    EM_NEED(sxem_add(c,EM_PAIR(bbi_header,be),0,64)&&sxem_table(c,EM_PAIR(bbi_zoom_header,be),64,24,zooms));
    if(summary)EM_NEED(summary>=64U+(uint64_t)zooms*24&&summary<=chrom&&40<=chrom-summary&&sxem_add(c,EM_PAIR(bbi_total_summary,be),summary,40));
    if(ext)EM_NEED(ext>=64U+(uint64_t)zooms*24&&ext<=chrom&&64<=chrom-ext&&sxem_add(c,EM_PAIR(bbi_extension,be),ext,64));
    EM_NEED(sxem_read(c,chrom,t,36)&&EM_U32(t,be)==0x78ca8c91&&t[32]==1);key=EM_U32(t+8,be);count=EM_U16(t+34,be);
    EM_NEED(key&&key<=128&&count&&count<=512&&data-chrom>=36&&(uint64_t)count*(key+8)<=data-chrom-36);
    EM_NEED(sxem_add(c,EM_PAIR(bbi_chromosome_tree,be),chrom,32)&&sxem_add(c,EM_PAIR(bbi_tree_node,be),chrom+32,4)&&sxem_table(c,sxem_chrom_layouts[key-1][be],chrom+36,key+8,count));
    limit=(uint64_t)c->size-4;if(zooms){EM_NEED(sxem_read(c,64,h,24));limit=EM_U64(h+8,be);}
    EM_NEED(sxem_bbi_index(c,index,data,limit,be,bed,false,compressed));
    for(unsigned z=0;z<zooms;z++){
        EM_NEED(sxem_read(c,64U+24U*z,h,24));data=EM_U64(h+8,be);index=EM_U64(h+16,be);limit=(uint64_t)c->size-4;
        if(z+1<zooms){EM_NEED(sxem_read(c,64U+24U*(z+1),h,24));limit=EM_U64(h+8,be);}
        EM_NEED(sxem_bbi_index(c,index,data,limit,be,bed,true,compressed));
    }
    return sxem_add(c,EM_PAIR(bbi_trailer,be),(uint64_t)c->size-4,4);
}
bool sxem_block(sx_context *c,uint64_t at,uint64_t size,uint64_t total,bool be,const char *magic)
{
    uint8_t h[8];return at<=total&&size>=8&&size<=total-at&&sxem_read(c,at,h,8)&&!xx_rt_memcmp(h,magic,4)&&EM_U32(h+4,be)==size&&sxem_add(c,EM_PAIR(nw_block,be),at,8);
}
static bool sxem_revolution(sx_context *c)
{
    uint8_t h[64],info[52],r[8];uint32_t total,io,in,da,dn,channels;bool stream=c->f->file_type==XX_FILE_TYPE_NINTENDO_BRSTM;
    EM_NEED(sxem_read(c,0,h,stream?64:32)&&!xx_rt_memcmp(h,stream?"RSTM":"RWAV",4)&&EM_U16(h+4,true)==0xfeff);
    total=EM_U32(h+8,true);io=EM_U32(h+16,true);in=EM_U32(h+20,true);da=EM_U32(h+(stream?32:24),true);dn=EM_U32(h+(stream?36:28),true);
    EM_NEED(total<=(uint64_t)c->size&&io>=(stream?64U:32U)&&da>=(stream?64U:32U)&&sxem_add(c,stream?&sxem_rstm_header:&sxem_rwav_header,0,stream?64:32));
    EM_NEED(sxem_block(c,io,in,total,true,stream?"HEAD":"INFO")&&sxem_block(c,da,dn,total,true,"DATA"));
    if(stream){
        uint32_t rel[3],track;EM_NEED(in>=32&&sxem_table(c,&sxem_revolution_reference,(uint64_t)io+8,8,3));
        for(unsigned i=0;i<3;i++){EM_NEED(sxem_read(c,(uint64_t)io+8+8*i,r,8));rel[i]=EM_U32(r+4,true);EM_NEED(rel[i]>=24&&rel[i]<=in-8);}
        EM_NEED(52<=in-8-rel[0]&&sxem_read(c,(uint64_t)io+8+rel[0],info,52)&&sxem_add(c,&sxem_rstm_stream_info,(uint64_t)io+8+rel[0],52));channels=info[2];EM_NEED(channels&&channels<=2);
        EM_NEED(12<=in-8-rel[1]&&sxem_read(c,(uint64_t)io+12+rel[1],r,8)&&sxem_add(c,&sxem_revolution_count,(uint64_t)io+8+rel[1],4)&&sxem_add(c,&sxem_revolution_reference,(uint64_t)io+12+rel[1],8));
        track=EM_U32(r+4,true);EM_NEED(track>=24&&track<=in-8&&4<=in-8-track&&sxem_add(c,&sxem_rstm_track,(uint64_t)io+8+track,4));
        EM_NEED(4U+8U*channels<=in-8-rel[2]&&sxem_add(c,&sxem_revolution_count,(uint64_t)io+8+rel[2],4)&&sxem_table(c,&sxem_revolution_reference,(uint64_t)io+12+rel[2],8,channels));
        for(unsigned i=0;i<channels;i++){uint32_t p;EM_NEED(sxem_read(c,(uint64_t)io+12+rel[2]+8*i,r,8));p=EM_U32(r+4,true);EM_NEED(p>=24&&p<=in-8&&8<=in-8-p&&sxem_add(c,&sxem_revolution_reference,(uint64_t)io+8+p,8));}
        EM_NEED(dn>=12&&sxem_add(c,&sxem_revolution_offset,(uint64_t)da+8,4));
    }else{
        uint32_t table;EM_NEED(in>=36&&sxem_read(c,(uint64_t)io+8,info,28)&&sxem_add(c,&sxem_rwav_wave_info,(uint64_t)io+8,28));channels=info[2];table=EM_U32(info+16,true);
        EM_NEED(channels&&channels<=8&&table>=28&&table<=in-8&&4U*channels<=in-8-table&&sxem_table(c,&sxem_revolution_offset,(uint64_t)io+8+table,4,channels));
        for(unsigned i=0;i<channels;i++){uint32_t p;EM_NEED(sxem_u32(c,(uint64_t)io+8+table+4*i,true,&p)&&p>=28&&p<=in-8&&28<=in-8-p&&sxem_add(c,&sxem_rwav_channel,(uint64_t)io+8+p,28));}
    }
    return true;
}
static bool sx_extendedmedia_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_NINTENDO_BRSTM:case XX_FILE_TYPE_NINTENDO_BRWAV:case XX_FILE_TYPE_NINTENDO_SDAT:case XX_FILE_TYPE_NINTENDO_BCSTM:case XX_FILE_TYPE_NINTENDO_BFSTM:case XX_FILE_TYPE_NINTENDO_BFWAV:case XX_FILE_TYPE_NINTENDO_BCWAV:case XX_FILE_TYPE_NINTENDO_BFSAR:case XX_FILE_TYPE_NINTENDO_BCSAR:case XX_FILE_TYPE_UCSC_BIGWIG:case XX_FILE_TYPE_UCSC_BIGBED:return true;default:return false;}
}
static bool sx_extendedmedia_build(sx_context *c)
{
    bool ok=c->f->file_type==XX_FILE_TYPE_NINTENDO_SDAT?sx_nintendo_sdat_build(c):(c->f->file_type==XX_FILE_TYPE_NINTENDO_BRSTM||c->f->file_type==XX_FILE_TYPE_NINTENDO_BRWAV)?sxem_revolution(c):c->f->file_type==XX_FILE_TYPE_UCSC_BIGWIG||c->f->file_type==XX_FILE_TYPE_UCSC_BIGBED?sxem_bbi(c):sxem_nw(c);
    return ok&&sxem_finish(c);
}
static bool sx_extendedmedia_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x600D0000)||id>=UINT32_C(0x600E0000))return true;
    if(!xx_rt_wcscmp(r->name,L"encoding")){
        uint64_t v=xx_var_get_u64(&r->value);const wchar_t *s=v==0?L"PCM8":v==1?L"PCM16":v==2?L"DSP_ADPCM":L"Unknown encoding";return xx_data_struct_record_set_comment(r,s);
    }
    if(!xx_rt_wcscmp(r->name,L"sample_rate_hz"))return xx_data_struct_record_set_comment(r,L"Samples per second (Hz)");
    if(!xx_rt_wcscmp(r->name,L"sample_offset"))return xx_data_struct_record_set_comment(r,L"Relative to the DATA block body; -1 denotes a null reference");
    if(!xx_rt_wcscmp(r->name,L"adpcm_offset"))return xx_data_struct_record_set_comment(r,L"Relative to the channel information structure; -1 denotes a null reference");
    if(!xx_rt_wcscmp(r->name,L"region_offset"))return xx_data_struct_record_set_comment(r,L"Relative to the REGN block body; -1 denotes a null reference");
    if(!xx_rt_wcscmp(r->name,L"base_count")||!xx_rt_wcscmp(r->name,L"bases_covered")||!xx_rt_wcscmp(r->name,L"valid_base_count"))return xx_data_struct_record_set_comment(r,L"Count of genomic bases, not bytes");
    if(id==sxem_sdat_group_entry.id&&!xx_rt_wcscmp(r->name,L"type")){static const wchar_t *const names[]={L"SSEQ",L"SBNK",L"SWAR",L"SSAR"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names))return xx_data_struct_record_set_comment(r,names[v]);}
    if(id==sxem_sdat_group_entry.id&&!xx_rt_wcscmp(r->name,L"load_flags"))return xx_data_struct_record_set_comment(r,L"Bit 0: load SSEQ; bit 1: select SWAR IDs; bit 2: load SWAR; bit 3: load SSAR");
    if(id==sxem_rwav_channel.id&&!xx_rt_wcsncmp(r->name,L"volume_",7))return xx_data_struct_record_set_comment(r,L"Encoded four-byte volume parameter; wire bytes retained without assuming numeric interpretation");
    if(!xx_rt_wcscmp(r->name,L"sample_rate_high"))return xx_data_struct_record_set_comment(r,L"Encoded high byte of the sample rate; zero in the native-supported PCM variants");
    if(id==sxem_rwav_wave_info.id&&(!xx_rt_wcscmp(r->name,L"sample_count")||!xx_rt_wcscmp(r->name,L"loop_start_sample")))return xx_data_struct_record_set_comment(r,L"PCM sample units in this reader; DSP ADPCM uses encoded nibble positions and is outside native scope");
    if(id==sxem_rwav_wave_info.id&&!xx_rt_wcscmp(r->name,L"channel_info_table_offset"))return xx_data_struct_record_set_comment(r,L"Offset relative to the WaveInfo structure (INFO block + 8)");
    if(!xx_rt_wcscmp(r->name,L"data_location_offset"))return xx_data_struct_record_set_comment(r,L"Offset relative to the DATA block body in the supported offset-location variant");
    if(!xx_rt_wcscmp(r->name,L"channel_data_offset"))return xx_data_struct_record_set_comment(r,L"Offset relative to WaveInfo data_location within the DATA block body");
    if(!xx_rt_wcscmp(r->name,L"adpcm_info_offset"))return xx_data_struct_record_set_comment(r,L"Offset relative to WaveInfo; zero for the supported PCM channels");
    if(!xx_rt_wcscmp(r->name,L"byte_order"))return xx_data_struct_record_set_comment(r,L"BOM bytes FE FF: big endian; FF FE: little endian");
    return true;
}
#undef EM_NEED
#undef EM_U16
#undef EM_U32
#undef EM_U64
#undef EM_PAIR
const sx_family sx_extendedmedia_family={sx_extendedmedia_supports,sx_extendedmedia_build,sx_extendedmedia_layouts,SX_COUNT(sx_extendedmedia_layouts),sx_extendedmedia_comment};
