/* SPDX-License-Identifier: MIT
 * Physical raster metadata. Scope: docs/data_struct_rastermore_scope.txt. */
static const xx_data_struct_field_desc sxrm_vtf70_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint32",4,4,SX_ID),
    SX_FIELD("version_minor","uint32",8,4,SX_ID),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("width","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("frames","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("first_frame","uint16",26,2,SX_ID),
    SX_FIELD("padding0","uint8[4]",28,4,SX_RESERVED),
    SX_FIELD("reflectivity_red","float32",32,4,SX_NONE),
    SX_FIELD("reflectivity_green","float32",36,4,SX_NONE),
    SX_FIELD("reflectivity_blue","float32",40,4,SX_NONE),
    SX_FIELD("padding1","uint8[4]",44,4,SX_RESERVED),
    SX_FIELD("bumpmap_scale","float32",48,4,SX_NONE),
    SX_FIELD("high_resolution_format","int32",52,4,SX_ID),
    SX_FIELD("mipmap_count","uint8",56,1,SX_COUNT_PROP),
    SX_FIELD("low_resolution_format","int32",57,4,SX_ID),
    SX_FIELD("low_resolution_width","uint8",61,1,SX_COUNT_PROP),
    SX_FIELD("low_resolution_height","uint8",62,1,SX_COUNT_PROP),
};
static const sx_layout sxrm_vtf70_header = {UINT32_C(0x601d0001),"vtf70_header",sxrm_vtf70_header_fields,SX_COUNT(sxrm_vtf70_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_vtf72_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint32",4,4,SX_ID),
    SX_FIELD("version_minor","uint32",8,4,SX_ID),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("width","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("frames","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("first_frame","uint16",26,2,SX_ID),
    SX_FIELD("padding0","uint8[4]",28,4,SX_RESERVED),
    SX_FIELD("reflectivity_red","float32",32,4,SX_NONE),
    SX_FIELD("reflectivity_green","float32",36,4,SX_NONE),
    SX_FIELD("reflectivity_blue","float32",40,4,SX_NONE),
    SX_FIELD("padding1","uint8[4]",44,4,SX_RESERVED),
    SX_FIELD("bumpmap_scale","float32",48,4,SX_NONE),
    SX_FIELD("high_resolution_format","int32",52,4,SX_ID),
    SX_FIELD("mipmap_count","uint8",56,1,SX_COUNT_PROP),
    SX_FIELD("low_resolution_format","int32",57,4,SX_ID),
    SX_FIELD("low_resolution_width","uint8",61,1,SX_COUNT_PROP),
    SX_FIELD("low_resolution_height","uint8",62,1,SX_COUNT_PROP),
    SX_FIELD("depth","uint16",63,2,SX_COUNT_PROP),
};
static const sx_layout sxrm_vtf72_header = {UINT32_C(0x601d0002),"vtf72_header",sxrm_vtf72_header_fields,SX_COUNT(sxrm_vtf72_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version_and_flags","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxrm_exr_header = {UINT32_C(0x601d0003),"exr_header",sxrm_exr_header_fields,SX_COUNT(sxrm_exr_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_attribute_length_fields[] = {
    SX_FIELD("value_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxrm_exr_attribute_length = {UINT32_C(0x601d0004),"exr_attribute_length",sxrm_exr_attribute_length_fields,SX_COUNT(sxrm_exr_attribute_length_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_channel_fields[] = {
    SX_FIELD("pixel_type","int32",0,4,SX_ID),
    SX_FIELD("perceptually_linear","uint8",4,1,SX_FLAGS),
    SX_FIELD("reserved","uint8[3]",5,3,SX_RESERVED),
    SX_FIELD("x_sampling","int32",8,4,SX_NONE),
    SX_FIELD("y_sampling","int32",12,4,SX_NONE),
};
static const sx_layout sxrm_exr_channel = {UINT32_C(0x601d0005),"exr_channel",sxrm_exr_channel_fields,SX_COUNT(sxrm_exr_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_box2i_fields[] = {
    SX_FIELD("minimum_x","int32",0,4,SX_NONE),
    SX_FIELD("minimum_y","int32",4,4,SX_NONE),
    SX_FIELD("maximum_x","int32",8,4,SX_NONE),
    SX_FIELD("maximum_y","int32",12,4,SX_NONE),
};
static const sx_layout sxrm_exr_box2i = {UINT32_C(0x601d0006),"exr_box2i",sxrm_exr_box2i_fields,SX_COUNT(sxrm_exr_box2i_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_float_fields[] = {
    SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxrm_exr_float = {UINT32_C(0x601d0007),"exr_float",sxrm_exr_float_fields,SX_COUNT(sxrm_exr_float_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_v2f_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
};
static const sx_layout sxrm_exr_v2f = {UINT32_C(0x601d0008),"exr_v2f",sxrm_exr_v2f_fields,SX_COUNT(sxrm_exr_v2f_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_compression_fields[] = {
    SX_FIELD("method","uint8",0,1,SX_ID),
};
static const sx_layout sxrm_exr_compression = {UINT32_C(0x601d0009),"exr_compression",sxrm_exr_compression_fields,SX_COUNT(sxrm_exr_compression_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_line_order_fields[] = {
    SX_FIELD("order","uint8",0,1,SX_ID),
};
static const sx_layout sxrm_exr_line_order = {UINT32_C(0x601d000a),"exr_line_order",sxrm_exr_line_order_fields,SX_COUNT(sxrm_exr_line_order_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_chunk_offset_fields[] = {
    SX_FIELD("chunk_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxrm_exr_chunk_offset = {UINT32_C(0x601d000b),"exr_chunk_offset",sxrm_exr_chunk_offset_fields,SX_COUNT(sxrm_exr_chunk_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_scanline_chunk_fields[] = {
    SX_FIELD("y_coordinate","int32",0,4,SX_NONE),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxrm_exr_scanline_chunk = {UINT32_C(0x601d000c),"exr_scanline_chunk",sxrm_exr_scanline_chunk_fields,SX_COUNT(sxrm_exr_scanline_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_jp2_box_fields[] = {
    SX_FIELD("box_size","uint32",0,4,SX_SIZE),
    SX_FIELD("box_type","char[4]",4,4,SX_ID),
};
static const sx_layout sxrm_jp2_box = {UINT32_C(0x601d000d),"jp2_box",sxrm_jp2_box_fields,SX_COUNT(sxrm_jp2_box_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_extended_size_fields[] = {
    SX_FIELD("box_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxrm_jp2_extended_size = {UINT32_C(0x601d000e),"jp2_extended_size",sxrm_jp2_extended_size_fields,SX_COUNT(sxrm_jp2_extended_size_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_signature_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxrm_jp2_signature = {UINT32_C(0x601d000f),"jp2_signature",sxrm_jp2_signature_fields,SX_COUNT(sxrm_jp2_signature_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_file_type_fields[] = {
    SX_FIELD("brand","char[4]",0,4,SX_ID),
    SX_FIELD("minor_version","uint32",4,4,SX_ID),
};
static const sx_layout sxrm_jp2_file_type = {UINT32_C(0x601d0010),"jp2_file_type",sxrm_jp2_file_type_fields,SX_COUNT(sxrm_jp2_file_type_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_compatible_brand_fields[] = {
    SX_FIELD("brand","char[4]",0,4,SX_ID),
};
static const sx_layout sxrm_jp2_compatible_brand = {UINT32_C(0x601d0011),"jp2_compatible_brand",sxrm_jp2_compatible_brand_fields,SX_COUNT(sxrm_jp2_compatible_brand_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_image_header_fields[] = {
    SX_FIELD("height","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("width","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("components","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("bits_per_component","uint8",10,1,SX_NONE),
    SX_FIELD("compression_type","uint8",11,1,SX_ID),
    SX_FIELD("unknown_colorspace","uint8",12,1,SX_FLAGS),
    SX_FIELD("intellectual_property","uint8",13,1,SX_FLAGS),
};
static const sx_layout sxrm_jp2_image_header = {UINT32_C(0x601d0012),"jp2_image_header",sxrm_jp2_image_header_fields,SX_COUNT(sxrm_jp2_image_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_color_header_fields[] = {
    SX_FIELD("method","uint8",0,1,SX_ID),
    SX_FIELD("precedence","uint8",1,1,SX_NONE),
    SX_FIELD("approximation","uint8",2,1,SX_NONE),
};
static const sx_layout sxrm_jp2_color_header = {UINT32_C(0x601d0013),"jp2_color_header",sxrm_jp2_color_header_fields,SX_COUNT(sxrm_jp2_color_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_enumerated_color_fields[] = {
    SX_FIELD("colorspace","uint32",0,4,SX_ID),
};
static const sx_layout sxrm_jp2_enumerated_color = {UINT32_C(0x601d0014),"jp2_enumerated_color",sxrm_jp2_enumerated_color_fields,SX_COUNT(sxrm_jp2_enumerated_color_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_marker_fields[] = {
    SX_FIELD("marker","uint16",0,2,SX_ID),
};
static const sx_layout sxrm_j2k_marker = {UINT32_C(0x601d0015),"j2k_marker",sxrm_j2k_marker_fields,SX_COUNT(sxrm_j2k_marker_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_segment_length_fields[] = {
    SX_FIELD("segment_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxrm_j2k_segment_length = {UINT32_C(0x601d0016),"j2k_segment_length",sxrm_j2k_segment_length_fields,SX_COUNT(sxrm_j2k_segment_length_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_siz_fields[] = {
    SX_FIELD("capabilities","uint16",0,2,SX_FLAGS),
    SX_FIELD("reference_grid_width","uint32",2,4,SX_COUNT_PROP),
    SX_FIELD("reference_grid_height","uint32",6,4,SX_COUNT_PROP),
    SX_FIELD("image_origin_x","uint32",10,4,SX_NONE),
    SX_FIELD("image_origin_y","uint32",14,4,SX_NONE),
    SX_FIELD("tile_width","uint32",18,4,SX_COUNT_PROP),
    SX_FIELD("tile_height","uint32",22,4,SX_COUNT_PROP),
    SX_FIELD("tile_origin_x","uint32",26,4,SX_NONE),
    SX_FIELD("tile_origin_y","uint32",30,4,SX_NONE),
    SX_FIELD("components","uint16",34,2,SX_COUNT_PROP),
};
static const sx_layout sxrm_j2k_siz = {UINT32_C(0x601d0017),"j2k_siz",sxrm_j2k_siz_fields,SX_COUNT(sxrm_j2k_siz_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_component_fields[] = {
    SX_FIELD("precision_and_sign","uint8",0,1,SX_NONE),
    SX_FIELD("horizontal_separation","uint8",1,1,SX_NONE),
    SX_FIELD("vertical_separation","uint8",2,1,SX_NONE),
};
static const sx_layout sxrm_j2k_component = {UINT32_C(0x601d0018),"j2k_component",sxrm_j2k_component_fields,SX_COUNT(sxrm_j2k_component_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_sot_fields[] = {
    SX_FIELD("tile_index","uint16",0,2,SX_ID),
    SX_FIELD("tile_part_size","uint32",2,4,SX_SIZE),
    SX_FIELD("tile_part_index","uint8",6,1,SX_ID),
    SX_FIELD("tile_part_count","uint8",7,1,SX_COUNT_PROP),
};
static const sx_layout sxrm_j2k_sot = {UINT32_C(0x601d0019),"j2k_sot",sxrm_j2k_sot_fields,SX_COUNT(sxrm_j2k_sot_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_bntx_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint32",8,4,SX_ID),
    SX_FIELD("byte_order","uint16",12,2,SX_ID),
    SX_FIELD("alignment_shift","uint8",14,1,SX_NONE),
    SX_FIELD("target_address_bits","uint8",15,1,SX_NONE),
    SX_FIELD("filename_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("flags","uint16",20,2,SX_FLAGS),
    SX_FIELD("first_block_offset","uint16",22,2,SX_OFFSET),
    SX_FIELD("relocation_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxrm_bntx_header = {UINT32_C(0x601d001a),"bntx_header",sxrm_bntx_header_fields,SX_COUNT(sxrm_bntx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_container_fields[] = {
    SX_FIELD("target","char[4]",0,4,SX_ID),
    SX_FIELD("texture_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("texture_pointer_table_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("data_block_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("dictionary_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("memory_pool_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("memory_pool_pointer","uint64",40,8,SX_POINTER),
    SX_FIELD("base_memory_pool_offset","uint32",48,4,SX_OFFSET),
    SX_FIELD("padding","uint8[4]",52,4,SX_RESERVED),
};
static const sx_layout sxrm_bntx_container = {UINT32_C(0x601d001b),"bntx_container",sxrm_bntx_container_fields,SX_COUNT(sxrm_bntx_container_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_block_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("next_block_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("block_size","uint32",8,4,SX_SIZE),
    SX_FIELD("padding","uint8[4]",12,4,SX_RESERVED),
};
static const sx_layout sxrm_bntx_block = {UINT32_C(0x601d001c),"bntx_block",sxrm_bntx_block_fields,SX_COUNT(sxrm_bntx_block_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_texture_info_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("dimensions","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("tile_mode","uint16",2,2,SX_ID),
    SX_FIELD("swizzle","uint16",4,2,SX_NONE),
    SX_FIELD("mipmap_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("sample_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("padding0","uint8[2]",10,2,SX_RESERVED),
    SX_FIELD("format","uint32",12,4,SX_ID),
    SX_FIELD("access_flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("width","int32",20,4,SX_COUNT_PROP),
    SX_FIELD("height","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("depth","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("array_length","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("texture_layout","uint32",36,4,SX_FLAGS),
    SX_FIELD("texture_layout2","uint32",40,4,SX_FLAGS),
    SX_FIELD("padding1","uint8[20]",44,20,SX_RESERVED),
    SX_FIELD("image_size","uint32",64,4,SX_SIZE),
    SX_FIELD("alignment_bytes","uint32",68,4,SX_SIZE),
    SX_FIELD("component_selection","uint32",72,4,SX_FLAGS),
    SX_FIELD("texture_type","uint8",76,1,SX_ID),
    SX_FIELD("padding2","uint8[3]",77,3,SX_RESERVED),
    SX_FIELD("name_offset","uint64",80,8,SX_OFFSET),
    SX_FIELD("parent_offset","uint64",88,8,SX_OFFSET),
    SX_FIELD("mipmap_pointer_table_offset","uint64",96,8,SX_OFFSET),
    SX_FIELD("user_data_offset","uint64",104,8,SX_OFFSET),
    SX_FIELD("texture_pointer","uint64",112,8,SX_POINTER),
    SX_FIELD("texture_view_pointer","uint64",120,8,SX_POINTER),
    SX_FIELD("descriptor_slot_offset","uint64",128,8,SX_OFFSET),
    SX_FIELD("user_dictionary_offset","uint64",136,8,SX_OFFSET),
};
static const sx_layout sxrm_bntx_texture_info = {UINT32_C(0x601d001d),"bntx_texture_info",sxrm_bntx_texture_info_fields,SX_COUNT(sxrm_bntx_texture_info_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_pointer_fields[] = {
    SX_FIELD("file_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxrm_bntx_pointer = {UINT32_C(0x601d001e),"bntx_pointer",sxrm_bntx_pointer_fields,SX_COUNT(sxrm_bntx_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_string_length_fields[] = {
    SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxrm_bntx_string_length = {UINT32_C(0x601d001f),"bntx_string_length",sxrm_bntx_string_length_fields,SX_COUNT(sxrm_bntx_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_bntx_relocation_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("self_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("section_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxrm_bntx_relocation_header = {UINT32_C(0x601d0020),"bntx_relocation_header",sxrm_bntx_relocation_header_fields,SX_COUNT(sxrm_bntx_relocation_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_gvr_prefix_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("reserved","uint16",8,2,SX_RESERVED),
    SX_FIELD("palette_format_and_flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("texture_format","uint8",11,1,SX_ID),
};
static const sx_layout sxrm_gvr_prefix = {UINT32_C(0x601d0021),"gvr_prefix",sxrm_gvr_prefix_fields,SX_COUNT(sxrm_gvr_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_gvr_dimensions_fields[] = {
    SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxrm_gvr_dimensions = {UINT32_C(0x601d0022),"gvr_dimensions",sxrm_gvr_dimensions_fields,SX_COUNT(sxrm_gvr_dimensions_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_form_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("form_size","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxrm_ilbm_form = {UINT32_C(0x601d0023),"ilbm_form",sxrm_ilbm_form_fields,SX_COUNT(sxrm_ilbm_form_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_chunk_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxrm_ilbm_chunk = {UINT32_C(0x601d0024),"ilbm_chunk",sxrm_ilbm_chunk_fields,SX_COUNT(sxrm_ilbm_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_bitmap_header_fields[] = {
    SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("x","int16",4,2,SX_NONE),
    SX_FIELD("y","int16",6,2,SX_NONE),
    SX_FIELD("planes","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("masking","uint8",9,1,SX_ID),
    SX_FIELD("compression","uint8",10,1,SX_ID),
    SX_FIELD("padding","uint8",11,1,SX_RESERVED),
    SX_FIELD("transparent_color","uint16",12,2,SX_ID),
    SX_FIELD("x_aspect","uint8",14,1,SX_NONE),
    SX_FIELD("y_aspect","uint8",15,1,SX_NONE),
    SX_FIELD("page_width","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("page_height","int16",18,2,SX_COUNT_PROP),
};
static const sx_layout sxrm_ilbm_bitmap_header = {UINT32_C(0x601d0025),"ilbm_bitmap_header",sxrm_ilbm_bitmap_header_fields,SX_COUNT(sxrm_ilbm_bitmap_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_palette_entry_fields[] = {
    SX_FIELD("red","uint8",0,1,SX_NONE),
    SX_FIELD("green","uint8",1,1,SX_NONE),
    SX_FIELD("blue","uint8",2,1,SX_NONE),
};
static const sx_layout sxrm_ilbm_palette_entry = {UINT32_C(0x601d0026),"ilbm_palette_entry",sxrm_ilbm_palette_entry_fields,SX_COUNT(sxrm_ilbm_palette_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_view_mode_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxrm_ilbm_view_mode = {UINT32_C(0x601d0027),"ilbm_view_mode",sxrm_ilbm_view_mode_fields,SX_COUNT(sxrm_ilbm_view_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_utah_rle_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("x_position","int16",2,2,SX_NONE),
    SX_FIELD("y_position","int16",4,2,SX_NONE),
    SX_FIELD("width","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("color_channels","uint8",11,1,SX_COUNT_PROP),
    SX_FIELD("pixel_bits","uint8",12,1,SX_NONE),
    SX_FIELD("colormap_channels","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("colormap_length_log2","uint8",14,1,SX_NONE),
};
static const sx_layout sxrm_utah_rle_header = {UINT32_C(0x601d0028),"utah_rle_header",sxrm_utah_rle_header_fields,SX_COUNT(sxrm_utah_rle_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_background_fields[] = {
    SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxrm_utah_background = {UINT32_C(0x601d0029),"utah_background",sxrm_utah_background_fields,SX_COUNT(sxrm_utah_background_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_colormap_fields[] = {
    SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxrm_utah_colormap = {UINT32_C(0x601d002a),"utah_colormap",sxrm_utah_colormap_fields,SX_COUNT(sxrm_utah_colormap_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_comment_length_fields[] = {
    SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxrm_utah_comment_length = {UINT32_C(0x601d002b),"utah_comment_length",sxrm_utah_comment_length_fields,SX_COUNT(sxrm_utah_comment_length_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_opcode_fields[] = {
    SX_FIELD("opcode_and_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("operand","uint8",1,1,SX_NONE),
};
static const sx_layout sxrm_utah_opcode = {UINT32_C(0x601d002c),"utah_opcode",sxrm_utah_opcode_fields,SX_COUNT(sxrm_utah_opcode_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_long_opcode_fields[] = {
    SX_FIELD("opcode_and_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("unused","uint8",1,1,SX_RESERVED),
    SX_FIELD("operand","uint16",2,2,SX_NONE),
};
static const sx_layout sxrm_utah_long_opcode = {UINT32_C(0x601d002d),"utah_long_opcode",sxrm_utah_long_opcode_fields,SX_COUNT(sxrm_utah_long_opcode_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_utah_run_value_fields[] = {
    SX_FIELD("value","uint8",0,1,SX_NONE),
    SX_FIELD("padding","uint8",1,1,SX_RESERVED),
};
static const sx_layout sxrm_utah_run_value = {UINT32_C(0x601d002e),"utah_run_value",sxrm_utah_run_value_fields,SX_COUNT(sxrm_utah_run_value_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_file_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("version","char[8]",8,8,SX_STRING),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("ditto_key","uint32",20,4,SX_ID),
    SX_FIELD("generic_header_size","uint32",24,4,SX_SIZE),
    SX_FIELD("industry_header_size","uint32",28,4,SX_SIZE),
    SX_FIELD("user_header_size","uint32",32,4,SX_SIZE),
    SX_FIELD("filename","char[100]",36,100,SX_STRING),
    SX_FIELD("creation_time","char[24]",136,24,SX_STRING),
    SX_FIELD("creator","char[100]",160,100,SX_STRING),
    SX_FIELD("project","char[200]",260,200,SX_STRING),
    SX_FIELD("copyright","char[200]",460,200,SX_STRING),
    SX_FIELD("encryption_key","uint32",660,4,SX_ID),
    SX_FIELD("reserved","uint8[104]",664,104,SX_RESERVED),
};
static const sx_layout sxrm_dpx_file_header_be = {UINT32_C(0x601d002f),"dpx_file_header_be",sxrm_dpx_file_header_be_fields,SX_COUNT(sxrm_dpx_file_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_image_header_be_fields[] = {
    SX_FIELD("orientation","uint16",0,2,SX_ID),
    SX_FIELD("element_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("pixels_per_line","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("lines_per_element","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxrm_dpx_image_header_be = {UINT32_C(0x601d0030),"dpx_image_header_be",sxrm_dpx_image_header_be_fields,SX_COUNT(sxrm_dpx_image_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_element_be_fields[] = {
    SX_FIELD("data_sign","uint32",0,4,SX_ID),
    SX_FIELD("reference_low_data","uint32",4,4,SX_NONE),
    SX_FIELD("reference_low_quantity","float32",8,4,SX_NONE),
    SX_FIELD("reference_high_data","uint32",12,4,SX_NONE),
    SX_FIELD("reference_high_quantity","float32",16,4,SX_NONE),
    SX_FIELD("descriptor","uint8",20,1,SX_ID),
    SX_FIELD("transfer_characteristic","uint8",21,1,SX_ID),
    SX_FIELD("colorimetric","uint8",22,1,SX_ID),
    SX_FIELD("bit_depth","uint8",23,1,SX_NONE),
    SX_FIELD("packing","uint16",24,2,SX_ID),
    SX_FIELD("encoding","uint16",26,2,SX_ID),
    SX_FIELD("data_offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("end_of_line_padding","uint32",32,4,SX_SIZE),
    SX_FIELD("end_of_image_padding","uint32",36,4,SX_SIZE),
    SX_FIELD("description","char[32]",40,32,SX_STRING),
};
static const sx_layout sxrm_dpx_element_be = {UINT32_C(0x601d0031),"dpx_element_be",sxrm_dpx_element_be_fields,SX_COUNT(sxrm_dpx_element_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_image_reserved_be_fields[] = {
    SX_FIELD("reserved","uint8[52]",0,52,SX_RESERVED),
};
static const sx_layout sxrm_dpx_image_reserved_be = {UINT32_C(0x601d0032),"dpx_image_reserved_be",sxrm_dpx_image_reserved_be_fields,SX_COUNT(sxrm_dpx_image_reserved_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_orientation_be_fields[] = {
    SX_FIELD("x_offset","uint32",0,4,SX_NONE),
    SX_FIELD("y_offset","uint32",4,4,SX_NONE),
    SX_FIELD("x_center","float32",8,4,SX_NONE),
    SX_FIELD("y_center","float32",12,4,SX_NONE),
    SX_FIELD("original_width","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("original_height","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("source_filename","char[100]",24,100,SX_STRING),
    SX_FIELD("source_creation_time","char[24]",124,24,SX_STRING),
    SX_FIELD("input_device","char[32]",148,32,SX_STRING),
    SX_FIELD("input_serial","char[32]",180,32,SX_STRING),
    SX_FIELD("border_validity","uint16[4]",212,8,SX_NONE),
    SX_FIELD("pixel_aspect_horizontal","uint32",220,4,SX_NONE),
    SX_FIELD("pixel_aspect_vertical","uint32",224,4,SX_NONE),
    SX_FIELD("reserved","uint8[28]",228,28,SX_RESERVED),
};
static const sx_layout sxrm_dpx_orientation_be = {UINT32_C(0x601d0033),"dpx_orientation_be",sxrm_dpx_orientation_be_fields,SX_COUNT(sxrm_dpx_orientation_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_film_be_fields[] = {
    SX_FIELD("manufacturer_id","char[2]",0,2,SX_STRING),
    SX_FIELD("film_type","char[2]",2,2,SX_STRING),
    SX_FIELD("perforation_offset","char[2]",4,2,SX_STRING),
    SX_FIELD("prefix","char[6]",6,6,SX_STRING),
    SX_FIELD("count","char[4]",12,4,SX_STRING),
    SX_FIELD("format","char[32]",16,32,SX_STRING),
    SX_FIELD("frame_position","uint32",48,4,SX_NONE),
    SX_FIELD("sequence_extent","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("held_count","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("frame_rate","float32",60,4,SX_NONE),
    SX_FIELD("shutter_angle","float32",64,4,SX_NONE),
    SX_FIELD("frame_id","char[32]",68,32,SX_STRING),
    SX_FIELD("slate","char[100]",100,100,SX_STRING),
    SX_FIELD("reserved","uint8[56]",200,56,SX_RESERVED),
};
static const sx_layout sxrm_dpx_film_be = {UINT32_C(0x601d0034),"dpx_film_be",sxrm_dpx_film_be_fields,SX_COUNT(sxrm_dpx_film_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_television_be_fields[] = {
    SX_FIELD("time_code","uint32",0,4,SX_NONE),
    SX_FIELD("user_bits","uint32",4,4,SX_FLAGS),
    SX_FIELD("interlace","uint8",8,1,SX_ID),
    SX_FIELD("field_number","uint8",9,1,SX_ID),
    SX_FIELD("video_signal","uint8",10,1,SX_ID),
    SX_FIELD("padding","uint8",11,1,SX_RESERVED),
    SX_FIELD("horizontal_sample_rate","float32",12,4,SX_NONE),
    SX_FIELD("vertical_sample_rate","float32",16,4,SX_NONE),
    SX_FIELD("frame_rate","float32",20,4,SX_NONE),
    SX_FIELD("time_offset","float32",24,4,SX_NONE),
    SX_FIELD("gamma","float32",28,4,SX_NONE),
    SX_FIELD("black_level","float32",32,4,SX_NONE),
    SX_FIELD("black_gain","float32",36,4,SX_NONE),
    SX_FIELD("break_point","float32",40,4,SX_NONE),
    SX_FIELD("white_level","float32",44,4,SX_NONE),
    SX_FIELD("integration_time","float32",48,4,SX_NONE),
    SX_FIELD("reserved","uint8[76]",52,76,SX_RESERVED),
};
static const sx_layout sxrm_dpx_television_be = {UINT32_C(0x601d0035),"dpx_television_be",sxrm_dpx_television_be_fields,SX_COUNT(sxrm_dpx_television_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_file_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("generic_header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("industry_header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("user_header_size","uint32",16,4,SX_SIZE),
    SX_FIELD("file_size","uint32",20,4,SX_SIZE),
    SX_FIELD("version","char[8]",24,8,SX_STRING),
    SX_FIELD("filename","char[100]",32,100,SX_STRING),
    SX_FIELD("creation_date","char[12]",132,12,SX_STRING),
    SX_FIELD("creation_time","char[12]",144,12,SX_STRING),
    SX_FIELD("reserved","uint8[36]",156,36,SX_RESERVED),
};
static const sx_layout sxrm_cineon_file_header_be = {UINT32_C(0x601d0036),"cineon_file_header_be",sxrm_cineon_file_header_be_fields,SX_COUNT(sxrm_cineon_file_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_image_header_be_fields[] = {
    SX_FIELD("orientation","uint8",0,1,SX_ID),
    SX_FIELD("channel_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("reserved","uint8[2]",2,2,SX_RESERVED),
};
static const sx_layout sxrm_cineon_image_header_be = {UINT32_C(0x601d0037),"cineon_image_header_be",sxrm_cineon_image_header_be_fields,SX_COUNT(sxrm_cineon_image_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_channel_be_fields[] = {
    SX_FIELD("designator0","uint8",0,1,SX_ID),
    SX_FIELD("designator1","uint8",1,1,SX_ID),
    SX_FIELD("bit_depth","uint8",2,1,SX_NONE),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("width","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("minimum_data","float32",12,4,SX_NONE),
    SX_FIELD("minimum_quantity","float32",16,4,SX_NONE),
    SX_FIELD("maximum_data","float32",20,4,SX_NONE),
    SX_FIELD("maximum_quantity","float32",24,4,SX_NONE),
};
static const sx_layout sxrm_cineon_channel_be = {UINT32_C(0x601d0038),"cineon_channel_be",sxrm_cineon_channel_be_fields,SX_COUNT(sxrm_cineon_channel_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_color_be_fields[] = {
    SX_FIELD("white_x","float32",0,4,SX_NONE),
    SX_FIELD("white_y","float32",4,4,SX_NONE),
    SX_FIELD("red_x","float32",8,4,SX_NONE),
    SX_FIELD("red_y","float32",12,4,SX_NONE),
    SX_FIELD("green_x","float32",16,4,SX_NONE),
    SX_FIELD("green_y","float32",20,4,SX_NONE),
    SX_FIELD("blue_x","float32",24,4,SX_NONE),
    SX_FIELD("blue_y","float32",28,4,SX_NONE),
    SX_FIELD("label","char[200]",32,200,SX_STRING),
    SX_FIELD("reserved","uint8[28]",232,28,SX_RESERVED),
};
static const sx_layout sxrm_cineon_color_be = {UINT32_C(0x601d0039),"cineon_color_be",sxrm_cineon_color_be_fields,SX_COUNT(sxrm_cineon_color_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_data_format_be_fields[] = {
    SX_FIELD("interleave","uint8",0,1,SX_ID),
    SX_FIELD("packing","uint8",1,1,SX_ID),
    SX_FIELD("data_sign","uint8",2,1,SX_ID),
    SX_FIELD("image_sense","uint8",3,1,SX_ID),
    SX_FIELD("line_padding","uint32",4,4,SX_SIZE),
    SX_FIELD("channel_padding","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint8[20]",12,20,SX_RESERVED),
};
static const sx_layout sxrm_cineon_data_format_be = {UINT32_C(0x601d003a),"cineon_data_format_be",sxrm_cineon_data_format_be_fields,SX_COUNT(sxrm_cineon_data_format_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_origin_be_fields[] = {
    SX_FIELD("x_offset","int32",0,4,SX_NONE),
    SX_FIELD("y_offset","int32",4,4,SX_NONE),
    SX_FIELD("source_filename","char[100]",8,100,SX_STRING),
    SX_FIELD("source_date","char[12]",108,12,SX_STRING),
    SX_FIELD("source_time","char[12]",120,12,SX_STRING),
    SX_FIELD("input_device","char[64]",132,64,SX_STRING),
    SX_FIELD("input_model","char[32]",196,32,SX_STRING),
    SX_FIELD("input_serial","char[32]",228,32,SX_STRING),
    SX_FIELD("x_pitch","float32",260,4,SX_NONE),
    SX_FIELD("y_pitch","float32",264,4,SX_NONE),
    SX_FIELD("gamma","float32",268,4,SX_NONE),
    SX_FIELD("reserved","uint8[40]",272,40,SX_RESERVED),
};
static const sx_layout sxrm_cineon_origin_be = {UINT32_C(0x601d003b),"cineon_origin_be",sxrm_cineon_origin_be_fields,SX_COUNT(sxrm_cineon_origin_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_film_be_fields[] = {
    SX_FIELD("manufacturer_id","uint8",0,1,SX_ID),
    SX_FIELD("film_type","uint8",1,1,SX_ID),
    SX_FIELD("perforation_offset","uint8",2,1,SX_NONE),
    SX_FIELD("reserved0","uint8",3,1,SX_RESERVED),
    SX_FIELD("prefix","uint32",4,4,SX_ID),
    SX_FIELD("count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("format","char[32]",12,32,SX_STRING),
    SX_FIELD("frame_position","uint32",44,4,SX_NONE),
    SX_FIELD("frame_rate","float32",48,4,SX_NONE),
    SX_FIELD("frame_id","char[32]",52,32,SX_STRING),
    SX_FIELD("slate","char[200]",84,200,SX_STRING),
    SX_FIELD("reserved1","uint8[740]",284,740,SX_RESERVED),
};
static const sx_layout sxrm_cineon_film_be = {UINT32_C(0x601d003c),"cineon_film_be",sxrm_cineon_film_be_fields,SX_COUNT(sxrm_cineon_film_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_file_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("version","char[8]",8,8,SX_STRING),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("ditto_key","uint32",20,4,SX_ID),
    SX_FIELD("generic_header_size","uint32",24,4,SX_SIZE),
    SX_FIELD("industry_header_size","uint32",28,4,SX_SIZE),
    SX_FIELD("user_header_size","uint32",32,4,SX_SIZE),
    SX_FIELD("filename","char[100]",36,100,SX_STRING),
    SX_FIELD("creation_time","char[24]",136,24,SX_STRING),
    SX_FIELD("creator","char[100]",160,100,SX_STRING),
    SX_FIELD("project","char[200]",260,200,SX_STRING),
    SX_FIELD("copyright","char[200]",460,200,SX_STRING),
    SX_FIELD("encryption_key","uint32",660,4,SX_ID),
    SX_FIELD("reserved","uint8[104]",664,104,SX_RESERVED),
};
static const sx_layout sxrm_dpx_file_header_le = {UINT32_C(0x601d003d),"dpx_file_header_le",sxrm_dpx_file_header_le_fields,SX_COUNT(sxrm_dpx_file_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_image_header_le_fields[] = {
    SX_FIELD("orientation","uint16",0,2,SX_ID),
    SX_FIELD("element_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("pixels_per_line","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("lines_per_element","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxrm_dpx_image_header_le = {UINT32_C(0x601d003e),"dpx_image_header_le",sxrm_dpx_image_header_le_fields,SX_COUNT(sxrm_dpx_image_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_element_le_fields[] = {
    SX_FIELD("data_sign","uint32",0,4,SX_ID),
    SX_FIELD("reference_low_data","uint32",4,4,SX_NONE),
    SX_FIELD("reference_low_quantity","float32",8,4,SX_NONE),
    SX_FIELD("reference_high_data","uint32",12,4,SX_NONE),
    SX_FIELD("reference_high_quantity","float32",16,4,SX_NONE),
    SX_FIELD("descriptor","uint8",20,1,SX_ID),
    SX_FIELD("transfer_characteristic","uint8",21,1,SX_ID),
    SX_FIELD("colorimetric","uint8",22,1,SX_ID),
    SX_FIELD("bit_depth","uint8",23,1,SX_NONE),
    SX_FIELD("packing","uint16",24,2,SX_ID),
    SX_FIELD("encoding","uint16",26,2,SX_ID),
    SX_FIELD("data_offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("end_of_line_padding","uint32",32,4,SX_SIZE),
    SX_FIELD("end_of_image_padding","uint32",36,4,SX_SIZE),
    SX_FIELD("description","char[32]",40,32,SX_STRING),
};
static const sx_layout sxrm_dpx_element_le = {UINT32_C(0x601d003f),"dpx_element_le",sxrm_dpx_element_le_fields,SX_COUNT(sxrm_dpx_element_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_image_reserved_le_fields[] = {
    SX_FIELD("reserved","uint8[52]",0,52,SX_RESERVED),
};
static const sx_layout sxrm_dpx_image_reserved_le = {UINT32_C(0x601d0040),"dpx_image_reserved_le",sxrm_dpx_image_reserved_le_fields,SX_COUNT(sxrm_dpx_image_reserved_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_orientation_le_fields[] = {
    SX_FIELD("x_offset","uint32",0,4,SX_NONE),
    SX_FIELD("y_offset","uint32",4,4,SX_NONE),
    SX_FIELD("x_center","float32",8,4,SX_NONE),
    SX_FIELD("y_center","float32",12,4,SX_NONE),
    SX_FIELD("original_width","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("original_height","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("source_filename","char[100]",24,100,SX_STRING),
    SX_FIELD("source_creation_time","char[24]",124,24,SX_STRING),
    SX_FIELD("input_device","char[32]",148,32,SX_STRING),
    SX_FIELD("input_serial","char[32]",180,32,SX_STRING),
    SX_FIELD("border_validity","uint16[4]",212,8,SX_NONE),
    SX_FIELD("pixel_aspect_horizontal","uint32",220,4,SX_NONE),
    SX_FIELD("pixel_aspect_vertical","uint32",224,4,SX_NONE),
    SX_FIELD("reserved","uint8[28]",228,28,SX_RESERVED),
};
static const sx_layout sxrm_dpx_orientation_le = {UINT32_C(0x601d0041),"dpx_orientation_le",sxrm_dpx_orientation_le_fields,SX_COUNT(sxrm_dpx_orientation_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_film_le_fields[] = {
    SX_FIELD("manufacturer_id","char[2]",0,2,SX_STRING),
    SX_FIELD("film_type","char[2]",2,2,SX_STRING),
    SX_FIELD("perforation_offset","char[2]",4,2,SX_STRING),
    SX_FIELD("prefix","char[6]",6,6,SX_STRING),
    SX_FIELD("count","char[4]",12,4,SX_STRING),
    SX_FIELD("format","char[32]",16,32,SX_STRING),
    SX_FIELD("frame_position","uint32",48,4,SX_NONE),
    SX_FIELD("sequence_extent","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("held_count","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("frame_rate","float32",60,4,SX_NONE),
    SX_FIELD("shutter_angle","float32",64,4,SX_NONE),
    SX_FIELD("frame_id","char[32]",68,32,SX_STRING),
    SX_FIELD("slate","char[100]",100,100,SX_STRING),
    SX_FIELD("reserved","uint8[56]",200,56,SX_RESERVED),
};
static const sx_layout sxrm_dpx_film_le = {UINT32_C(0x601d0042),"dpx_film_le",sxrm_dpx_film_le_fields,SX_COUNT(sxrm_dpx_film_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_television_le_fields[] = {
    SX_FIELD("time_code","uint32",0,4,SX_NONE),
    SX_FIELD("user_bits","uint32",4,4,SX_FLAGS),
    SX_FIELD("interlace","uint8",8,1,SX_ID),
    SX_FIELD("field_number","uint8",9,1,SX_ID),
    SX_FIELD("video_signal","uint8",10,1,SX_ID),
    SX_FIELD("padding","uint8",11,1,SX_RESERVED),
    SX_FIELD("horizontal_sample_rate","float32",12,4,SX_NONE),
    SX_FIELD("vertical_sample_rate","float32",16,4,SX_NONE),
    SX_FIELD("frame_rate","float32",20,4,SX_NONE),
    SX_FIELD("time_offset","float32",24,4,SX_NONE),
    SX_FIELD("gamma","float32",28,4,SX_NONE),
    SX_FIELD("black_level","float32",32,4,SX_NONE),
    SX_FIELD("black_gain","float32",36,4,SX_NONE),
    SX_FIELD("break_point","float32",40,4,SX_NONE),
    SX_FIELD("white_level","float32",44,4,SX_NONE),
    SX_FIELD("integration_time","float32",48,4,SX_NONE),
    SX_FIELD("reserved","uint8[76]",52,76,SX_RESERVED),
};
static const sx_layout sxrm_dpx_television_le = {UINT32_C(0x601d0043),"dpx_television_le",sxrm_dpx_television_le_fields,SX_COUNT(sxrm_dpx_television_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_file_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("generic_header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("industry_header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("user_header_size","uint32",16,4,SX_SIZE),
    SX_FIELD("file_size","uint32",20,4,SX_SIZE),
    SX_FIELD("version","char[8]",24,8,SX_STRING),
    SX_FIELD("filename","char[100]",32,100,SX_STRING),
    SX_FIELD("creation_date","char[12]",132,12,SX_STRING),
    SX_FIELD("creation_time","char[12]",144,12,SX_STRING),
    SX_FIELD("reserved","uint8[36]",156,36,SX_RESERVED),
};
static const sx_layout sxrm_cineon_file_header_le = {UINT32_C(0x601d0044),"cineon_file_header_le",sxrm_cineon_file_header_le_fields,SX_COUNT(sxrm_cineon_file_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_image_header_le_fields[] = {
    SX_FIELD("orientation","uint8",0,1,SX_ID),
    SX_FIELD("channel_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("reserved","uint8[2]",2,2,SX_RESERVED),
};
static const sx_layout sxrm_cineon_image_header_le = {UINT32_C(0x601d0045),"cineon_image_header_le",sxrm_cineon_image_header_le_fields,SX_COUNT(sxrm_cineon_image_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_channel_le_fields[] = {
    SX_FIELD("designator0","uint8",0,1,SX_ID),
    SX_FIELD("designator1","uint8",1,1,SX_ID),
    SX_FIELD("bit_depth","uint8",2,1,SX_NONE),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("width","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("minimum_data","float32",12,4,SX_NONE),
    SX_FIELD("minimum_quantity","float32",16,4,SX_NONE),
    SX_FIELD("maximum_data","float32",20,4,SX_NONE),
    SX_FIELD("maximum_quantity","float32",24,4,SX_NONE),
};
static const sx_layout sxrm_cineon_channel_le = {UINT32_C(0x601d0046),"cineon_channel_le",sxrm_cineon_channel_le_fields,SX_COUNT(sxrm_cineon_channel_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_color_le_fields[] = {
    SX_FIELD("white_x","float32",0,4,SX_NONE),
    SX_FIELD("white_y","float32",4,4,SX_NONE),
    SX_FIELD("red_x","float32",8,4,SX_NONE),
    SX_FIELD("red_y","float32",12,4,SX_NONE),
    SX_FIELD("green_x","float32",16,4,SX_NONE),
    SX_FIELD("green_y","float32",20,4,SX_NONE),
    SX_FIELD("blue_x","float32",24,4,SX_NONE),
    SX_FIELD("blue_y","float32",28,4,SX_NONE),
    SX_FIELD("label","char[200]",32,200,SX_STRING),
    SX_FIELD("reserved","uint8[28]",232,28,SX_RESERVED),
};
static const sx_layout sxrm_cineon_color_le = {UINT32_C(0x601d0047),"cineon_color_le",sxrm_cineon_color_le_fields,SX_COUNT(sxrm_cineon_color_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_data_format_le_fields[] = {
    SX_FIELD("interleave","uint8",0,1,SX_ID),
    SX_FIELD("packing","uint8",1,1,SX_ID),
    SX_FIELD("data_sign","uint8",2,1,SX_ID),
    SX_FIELD("image_sense","uint8",3,1,SX_ID),
    SX_FIELD("line_padding","uint32",4,4,SX_SIZE),
    SX_FIELD("channel_padding","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint8[20]",12,20,SX_RESERVED),
};
static const sx_layout sxrm_cineon_data_format_le = {UINT32_C(0x601d0048),"cineon_data_format_le",sxrm_cineon_data_format_le_fields,SX_COUNT(sxrm_cineon_data_format_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_origin_le_fields[] = {
    SX_FIELD("x_offset","int32",0,4,SX_NONE),
    SX_FIELD("y_offset","int32",4,4,SX_NONE),
    SX_FIELD("source_filename","char[100]",8,100,SX_STRING),
    SX_FIELD("source_date","char[12]",108,12,SX_STRING),
    SX_FIELD("source_time","char[12]",120,12,SX_STRING),
    SX_FIELD("input_device","char[64]",132,64,SX_STRING),
    SX_FIELD("input_model","char[32]",196,32,SX_STRING),
    SX_FIELD("input_serial","char[32]",228,32,SX_STRING),
    SX_FIELD("x_pitch","float32",260,4,SX_NONE),
    SX_FIELD("y_pitch","float32",264,4,SX_NONE),
    SX_FIELD("gamma","float32",268,4,SX_NONE),
    SX_FIELD("reserved","uint8[40]",272,40,SX_RESERVED),
};
static const sx_layout sxrm_cineon_origin_le = {UINT32_C(0x601d0049),"cineon_origin_le",sxrm_cineon_origin_le_fields,SX_COUNT(sxrm_cineon_origin_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_film_le_fields[] = {
    SX_FIELD("manufacturer_id","uint8",0,1,SX_ID),
    SX_FIELD("film_type","uint8",1,1,SX_ID),
    SX_FIELD("perforation_offset","uint8",2,1,SX_NONE),
    SX_FIELD("reserved0","uint8",3,1,SX_RESERVED),
    SX_FIELD("prefix","uint32",4,4,SX_ID),
    SX_FIELD("count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("format","char[32]",12,32,SX_STRING),
    SX_FIELD("frame_position","uint32",44,4,SX_NONE),
    SX_FIELD("frame_rate","float32",48,4,SX_NONE),
    SX_FIELD("frame_id","char[32]",52,32,SX_STRING),
    SX_FIELD("slate","char[200]",84,200,SX_STRING),
    SX_FIELD("reserved1","uint8[740]",284,740,SX_RESERVED),
};
static const sx_layout sxrm_cineon_film_le = {UINT32_C(0x601d004a),"cineon_film_le",sxrm_cineon_film_le_fields,SX_COUNT(sxrm_cineon_film_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_header_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
    SX_FIELD("magic","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("frames","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("width","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("color_depth","uint16",12,2,SX_NONE),
    SX_FIELD("flags","uint32",14,4,SX_FLAGS),
    SX_FIELD("speed_milliseconds","uint16",18,2,SX_NONE),
    SX_FIELD("reserved0","uint32",20,4,SX_RESERVED),
    SX_FIELD("reserved1","uint32",24,4,SX_RESERVED),
    SX_FIELD("transparent_palette_index","uint8",28,1,SX_ID),
    SX_FIELD("ignored","uint8[3]",29,3,SX_RESERVED),
    SX_FIELD("color_count","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("pixel_width","uint8",34,1,SX_NONE),
    SX_FIELD("pixel_height","uint8",35,1,SX_NONE),
    SX_FIELD("grid_x","int16",36,2,SX_NONE),
    SX_FIELD("grid_y","int16",38,2,SX_NONE),
    SX_FIELD("grid_width","uint16",40,2,SX_COUNT_PROP),
    SX_FIELD("grid_height","uint16",42,2,SX_COUNT_PROP),
    SX_FIELD("reserved2","uint8[84]",44,84,SX_RESERVED),
};
static const sx_layout sxrm_aseprite_header = {UINT32_C(0x601d004b),"aseprite_header",sxrm_aseprite_header_fields,SX_COUNT(sxrm_aseprite_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_frame_fields[] = {
    SX_FIELD("frame_size","uint32",0,4,SX_SIZE),
    SX_FIELD("magic","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("old_chunk_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("duration_milliseconds","uint16",8,2,SX_NONE),
    SX_FIELD("reserved","uint8[2]",10,2,SX_RESERVED),
    SX_FIELD("chunk_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxrm_aseprite_frame = {UINT32_C(0x601d004c),"aseprite_frame",sxrm_aseprite_frame_fields,SX_COUNT(sxrm_aseprite_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_chunk_fields[] = {
    SX_FIELD("chunk_size","uint32",0,4,SX_SIZE),
    SX_FIELD("chunk_type","uint16",4,2,SX_ID),
};
static const sx_layout sxrm_aseprite_chunk = {UINT32_C(0x601d004d),"aseprite_chunk",sxrm_aseprite_chunk_fields,SX_COUNT(sxrm_aseprite_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_layer_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("layer_type","uint16",2,2,SX_ID),
    SX_FIELD("child_level","uint16",4,2,SX_NONE),
    SX_FIELD("default_width","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("default_height","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("blend_mode","uint16",10,2,SX_ID),
    SX_FIELD("opacity","uint8",12,1,SX_NONE),
    SX_FIELD("reserved","uint8[3]",13,3,SX_RESERVED),
    SX_FIELD("name_length","uint16",16,2,SX_SIZE),
};
static const sx_layout sxrm_aseprite_layer = {UINT32_C(0x601d004e),"aseprite_layer",sxrm_aseprite_layer_fields,SX_COUNT(sxrm_aseprite_layer_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_layer_uuid_fields[] = {
    SX_FIELD("uuid","uint8[16]",0,16,SX_ID),
};
static const sx_layout sxrm_aseprite_layer_uuid = {UINT32_C(0x601d004f),"aseprite_layer_uuid",sxrm_aseprite_layer_uuid_fields,SX_COUNT(sxrm_aseprite_layer_uuid_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_cel_fields[] = {
    SX_FIELD("layer_index","uint16",0,2,SX_ID),
    SX_FIELD("x","int16",2,2,SX_NONE),
    SX_FIELD("y","int16",4,2,SX_NONE),
    SX_FIELD("opacity","uint8",6,1,SX_NONE),
    SX_FIELD("cel_type","uint16",7,2,SX_ID),
    SX_FIELD("z_index","int16",9,2,SX_NONE),
    SX_FIELD("reserved","uint8[5]",11,5,SX_RESERVED),
};
static const sx_layout sxrm_aseprite_cel = {UINT32_C(0x601d0050),"aseprite_cel",sxrm_aseprite_cel_fields,SX_COUNT(sxrm_aseprite_cel_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_cel_dimensions_fields[] = {
    SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxrm_aseprite_cel_dimensions = {UINT32_C(0x601d0051),"aseprite_cel_dimensions",sxrm_aseprite_cel_dimensions_fields,SX_COUNT(sxrm_aseprite_cel_dimensions_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_linked_cel_fields[] = {
    SX_FIELD("frame_index","uint16",0,2,SX_ID),
};
static const sx_layout sxrm_aseprite_linked_cel = {UINT32_C(0x601d0052),"aseprite_linked_cel",sxrm_aseprite_linked_cel_fields,SX_COUNT(sxrm_aseprite_linked_cel_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_palette_fields[] = {
    SX_FIELD("palette_size","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("first_index","uint32",4,4,SX_ID),
    SX_FIELD("last_index","uint32",8,4,SX_ID),
    SX_FIELD("reserved","uint8[8]",12,8,SX_RESERVED),
};
static const sx_layout sxrm_aseprite_palette = {UINT32_C(0x601d0053),"aseprite_palette",sxrm_aseprite_palette_fields,SX_COUNT(sxrm_aseprite_palette_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_palette_entry_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("red","uint8",2,1,SX_NONE),
    SX_FIELD("green","uint8",3,1,SX_NONE),
    SX_FIELD("blue","uint8",4,1,SX_NONE),
    SX_FIELD("alpha","uint8",5,1,SX_NONE),
};
static const sx_layout sxrm_aseprite_palette_entry = {UINT32_C(0x601d0054),"aseprite_palette_entry",sxrm_aseprite_palette_entry_fields,SX_COUNT(sxrm_aseprite_palette_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_string_length_fields[] = {
    SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxrm_aseprite_string_length = {UINT32_C(0x601d0055),"aseprite_string_length",sxrm_aseprite_string_length_fields,SX_COUNT(sxrm_aseprite_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_user_flags_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxrm_aseprite_user_flags = {UINT32_C(0x601d0056),"aseprite_user_flags",sxrm_aseprite_user_flags_fields,SX_COUNT(sxrm_aseprite_user_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_aseprite_rgba_fields[] = {
    SX_FIELD("red","uint8",0,1,SX_NONE),
    SX_FIELD("green","uint8",1,1,SX_NONE),
    SX_FIELD("blue","uint8",2,1,SX_NONE),
    SX_FIELD("alpha","uint8",3,1,SX_NONE),
};
static const sx_layout sxrm_aseprite_rgba = {UINT32_C(0x601d0057),"aseprite_rgba",sxrm_aseprite_rgba_fields,SX_COUNT(sxrm_aseprite_rgba_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_godot_ctex_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("original_width","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("original_height","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("mipmap_limit","int32",20,4,SX_NONE),
    SX_FIELD("reserved","uint32[3]",24,12,SX_RESERVED),
    SX_FIELD("data_format","uint32",36,4,SX_ID),
    SX_FIELD("width","uint16",40,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",42,2,SX_COUNT_PROP),
    SX_FIELD("mipmap_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("image_format","uint32",48,4,SX_ID),
};
static const sx_layout sxrm_godot_ctex_header = {UINT32_C(0x601d0058),"godot_ctex_header",sxrm_godot_ctex_header_fields,SX_COUNT(sxrm_godot_ctex_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_jbig2_file_header_fields[] = {
    SX_FIELD("signature","uint8[8]",0,8,SX_SIGNATURE),
    SX_FIELD("flags","uint8",8,1,SX_FLAGS),
};
static const sx_layout sxrm_jbig2_file_header = {UINT32_C(0x601d0059),"jbig2_file_header",sxrm_jbig2_file_header_fields,SX_COUNT(sxrm_jbig2_file_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_page_count_fields[] = {
    SX_FIELD("pages","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxrm_jbig2_page_count = {UINT32_C(0x601d005a),"jbig2_page_count",sxrm_jbig2_page_count_fields,SX_COUNT(sxrm_jbig2_page_count_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_segment_prefix_fields[] = {
    SX_FIELD("segment_number","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("reference_count_and_retention","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxrm_jbig2_segment_prefix = {UINT32_C(0x601d005b),"jbig2_segment_prefix",sxrm_jbig2_segment_prefix_fields,SX_COUNT(sxrm_jbig2_segment_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_reference1_fields[] = {
    SX_FIELD("segment_number","uint8",0,1,SX_ID),
};
static const sx_layout sxrm_jbig2_reference1 = {UINT32_C(0x601d005c),"jbig2_reference1",sxrm_jbig2_reference1_fields,SX_COUNT(sxrm_jbig2_reference1_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_reference2_fields[] = {
    SX_FIELD("segment_number","uint16",0,2,SX_ID),
};
static const sx_layout sxrm_jbig2_reference2 = {UINT32_C(0x601d005d),"jbig2_reference2",sxrm_jbig2_reference2_fields,SX_COUNT(sxrm_jbig2_reference2_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_reference4_fields[] = {
    SX_FIELD("segment_number","uint32",0,4,SX_ID),
};
static const sx_layout sxrm_jbig2_reference4 = {UINT32_C(0x601d005e),"jbig2_reference4",sxrm_jbig2_reference4_fields,SX_COUNT(sxrm_jbig2_reference4_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_segment_tail1_fields[] = {
    SX_FIELD("page_association","uint8",0,1,SX_ID),
    SX_FIELD("data_size","uint32",1,4,SX_SIZE),
};
static const sx_layout sxrm_jbig2_segment_tail1 = {UINT32_C(0x601d005f),"jbig2_segment_tail1",sxrm_jbig2_segment_tail1_fields,SX_COUNT(sxrm_jbig2_segment_tail1_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_segment_tail4_fields[] = {
    SX_FIELD("page_association","uint32",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxrm_jbig2_segment_tail4 = {UINT32_C(0x601d0060),"jbig2_segment_tail4",sxrm_jbig2_segment_tail4_fields,SX_COUNT(sxrm_jbig2_segment_tail4_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_page_info_fields[] = {
    SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("x_resolution","uint32",8,4,SX_NONE),
    SX_FIELD("y_resolution","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint8",16,1,SX_FLAGS),
    SX_FIELD("striping_information","uint16",17,2,SX_FLAGS),
};
static const sx_layout sxrm_jbig2_page_info = {UINT32_C(0x601d0061),"jbig2_page_info",sxrm_jbig2_page_info_fields,SX_COUNT(sxrm_jbig2_page_info_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_region_fields[] = {
    SX_FIELD("width","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("x","uint32",8,4,SX_NONE),
    SX_FIELD("y","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint8",16,1,SX_FLAGS),
};
static const sx_layout sxrm_jbig2_region = {UINT32_C(0x601d0062),"jbig2_region",sxrm_jbig2_region_fields,SX_COUNT(sxrm_jbig2_region_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jbig2_extension_fields[] = {
    SX_FIELD("extension_type","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxrm_jbig2_extension = {UINT32_C(0x601d0063),"jbig2_extension",sxrm_jbig2_extension_fields,SX_COUNT(sxrm_jbig2_extension_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_raf_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("format_version","char[4]",16,4,SX_STRING),
    SX_FIELD("camera_identifier","uint8[8]",20,8,SX_ID),
    SX_FIELD("camera_name","char[32]",28,32,SX_STRING),
    SX_FIELD("directory_version","char[4]",60,4,SX_STRING),
    SX_FIELD("unknown","uint8[20]",64,20,SX_NONE),
    SX_FIELD("jpeg_offset","uint32",84,4,SX_OFFSET),
    SX_FIELD("jpeg_size","uint32",88,4,SX_SIZE),
    SX_FIELD("metadata_offset","uint32",92,4,SX_OFFSET),
    SX_FIELD("metadata_size","uint32",96,4,SX_SIZE),
    SX_FIELD("cfa_offset","uint32",100,4,SX_OFFSET),
    SX_FIELD("cfa_size","uint32",104,4,SX_SIZE),
};
static const sx_layout sxrm_raf_header = {UINT32_C(0x601d0064),"raf_header",sxrm_raf_header_fields,SX_COUNT(sxrm_raf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_raf_metadata_count_fields[] = {
    SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxrm_raf_metadata_count = {UINT32_C(0x601d0065),"raf_metadata_count",sxrm_raf_metadata_count_fields,SX_COUNT(sxrm_raf_metadata_count_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_raf_metadata_entry_fields[] = {
    SX_FIELD("tag","uint16",0,2,SX_ID),
    SX_FIELD("data_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxrm_raf_metadata_entry = {UINT32_C(0x601d0066),"raf_metadata_entry",sxrm_raf_metadata_entry_fields,SX_COUNT(sxrm_raf_metadata_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_raf_dimensions_fields[] = {
    SX_FIELD("height","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("width","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxrm_raf_dimensions = {UINT32_C(0x601d0067),"raf_dimensions",sxrm_raf_dimensions_fields,SX_COUNT(sxrm_raf_dimensions_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_x3f_header20_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("unique_identifier","uint8[16]",8,16,SX_ID),
    SX_FIELD("mark_bits","uint32",24,4,SX_FLAGS),
    SX_FIELD("columns","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("rows","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("rotation_degrees","uint32",36,4,SX_NONE),
};
static const sx_layout sxrm_x3f_header20 = {UINT32_C(0x601d0068),"x3f_header20",sxrm_x3f_header20_fields,SX_COUNT(sxrm_x3f_header20_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_header21_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("unique_identifier","uint8[16]",8,16,SX_ID),
    SX_FIELD("mark_bits","uint32",24,4,SX_FLAGS),
    SX_FIELD("columns","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("rows","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("rotation_degrees","uint32",36,4,SX_NONE),
    SX_FIELD("white_balance","char[32]",40,32,SX_STRING),
    SX_FIELD("extended_types","uint8[32]",72,32,SX_ID),
    SX_FIELD("extended_data","float32[32]",104,128,SX_NONE),
};
static const sx_layout sxrm_x3f_header21 = {UINT32_C(0x601d0069),"x3f_header21",sxrm_x3f_header21_fields,SX_COUNT(sxrm_x3f_header21_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_header23_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("unique_identifier","uint8[16]",8,16,SX_ID),
    SX_FIELD("mark_bits","uint32",24,4,SX_FLAGS),
    SX_FIELD("columns","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("rows","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("rotation_degrees","uint32",36,4,SX_NONE),
    SX_FIELD("white_balance","char[32]",40,32,SX_STRING),
    SX_FIELD("color_mode","char[32]",72,32,SX_STRING),
    SX_FIELD("extended_types","uint8[32]",104,32,SX_ID),
    SX_FIELD("extended_data","float32[32]",136,128,SX_NONE),
};
static const sx_layout sxrm_x3f_header23 = {UINT32_C(0x601d006a),"x3f_header23",sxrm_x3f_header23_fields,SX_COUNT(sxrm_x3f_header23_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_directory_offset_fields[] = {
    SX_FIELD("directory_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxrm_x3f_directory_offset = {UINT32_C(0x601d006b),"x3f_directory_offset",sxrm_x3f_directory_offset_fields,SX_COUNT(sxrm_x3f_directory_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_directory_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxrm_x3f_directory = {UINT32_C(0x601d006c),"x3f_directory",sxrm_x3f_directory_fields,SX_COUNT(sxrm_x3f_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_directory_entry_fields[] = {
    SX_FIELD("section_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("section_size","uint32",4,4,SX_SIZE),
    SX_FIELD("section_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxrm_x3f_directory_entry = {UINT32_C(0x601d006d),"x3f_directory_entry",sxrm_x3f_directory_entry_fields,SX_COUNT(sxrm_x3f_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_image_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("image_type","uint32",8,4,SX_ID),
    SX_FIELD("image_format","uint32",12,4,SX_ID),
    SX_FIELD("width","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("row_stride","uint32",24,4,SX_SIZE),
};
static const sx_layout sxrm_x3f_image = {UINT32_C(0x601d006e),"x3f_image",sxrm_x3f_image_fields,SX_COUNT(sxrm_x3f_image_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_camf2_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("type","uint32",8,4,SX_ID),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
    SX_FIELD("information_type","uint32",16,4,SX_ID),
    SX_FIELD("information_type_version","uint32",20,4,SX_ID),
    SX_FIELD("encryption_key","uint32",24,4,SX_ID),
};
static const sx_layout sxrm_x3f_camf2 = {UINT32_C(0x601d006f),"x3f_camf2",sxrm_x3f_camf2_fields,SX_COUNT(sxrm_x3f_camf2_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_properties_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("property_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("character_format","uint32",12,4,SX_ID),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
    SX_FIELD("string_pool_codeunits","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxrm_x3f_properties = {UINT32_C(0x601d0070),"x3f_properties",sxrm_x3f_properties_fields,SX_COUNT(sxrm_x3f_properties_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_property_fields[] = {
    SX_FIELD("name_index","uint32",0,4,SX_NONE),
    SX_FIELD("value_index","uint32",4,4,SX_NONE),
};
static const sx_layout sxrm_x3f_property = {UINT32_C(0x601d0071),"x3f_property",sxrm_x3f_property_fields,SX_COUNT(sxrm_x3f_property_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_mrw_header_fields[] = {
    SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
    SX_FIELD("metadata_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxrm_mrw_header = {UINT32_C(0x601d0072),"mrw_header",sxrm_mrw_header_fields,SX_COUNT(sxrm_mrw_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_mrw_chunk_fields[] = {
    SX_FIELD("chunk_type","uint8[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxrm_mrw_chunk = {UINT32_C(0x601d0073),"mrw_chunk",sxrm_mrw_chunk_fields,SX_COUNT(sxrm_mrw_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_mrw_prd_fields[] = {
    SX_FIELD("version","char[8]",0,8,SX_STRING),
    SX_FIELD("sensor_rows","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("sensor_columns","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("image_height","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("image_width","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("storage_bits","uint8",16,1,SX_NONE),
    SX_FIELD("valid_bits","uint8",17,1,SX_NONE),
    SX_FIELD("packing","uint8",18,1,SX_ID),
    SX_FIELD("unknown","uint8[4]",19,4,SX_NONE),
    SX_FIELD("bayer_pattern","uint8",23,1,SX_ID),
};
static const sx_layout sxrm_mrw_prd = {UINT32_C(0x601d0074),"mrw_prd",sxrm_mrw_prd_fields,SX_COUNT(sxrm_mrw_prd_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_mrw_white_balance_fields[] = {
    SX_FIELD("denominator_exponents","uint8[4]",0,4,SX_NONE),
    SX_FIELD("channel0_numerator","uint16",4,2,SX_NONE),
    SX_FIELD("channel1_numerator","uint16",6,2,SX_NONE),
    SX_FIELD("channel2_numerator","uint16",8,2,SX_NONE),
    SX_FIELD("channel3_numerator","uint16",10,2,SX_NONE),
};
static const sx_layout sxrm_mrw_white_balance = {UINT32_C(0x601d0075),"mrw_white_balance",sxrm_mrw_white_balance_fields,SX_COUNT(sxrm_mrw_white_balance_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_mrw_tiff_header_le_fields[] = {
    SX_FIELD("byte_order","char[2]",0,2,SX_ID),
    SX_FIELD("version","uint16",2,2,SX_ID),
    SX_FIELD("first_ifd_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxrm_mrw_tiff_header_le = {UINT32_C(0x601d0076),"mrw_tiff_header_le",sxrm_mrw_tiff_header_le_fields,SX_COUNT(sxrm_mrw_tiff_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_mrw_tiff_header_be_fields[] = {
    SX_FIELD("byte_order","char[2]",0,2,SX_ID),
    SX_FIELD("version","uint16",2,2,SX_ID),
    SX_FIELD("first_ifd_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxrm_mrw_tiff_header_be = {UINT32_C(0x601d0077),"mrw_tiff_header_be",sxrm_mrw_tiff_header_be_fields,SX_COUNT(sxrm_mrw_tiff_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_basis_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("version","uint16",2,2,SX_ID),
    SX_FIELD("header_size","uint16",4,2,SX_SIZE),
    SX_FIELD("header_crc16","uint16",6,2,SX_CHECKSUM),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
    SX_FIELD("data_crc16","uint16",12,2,SX_CHECKSUM),
    SX_FIELD("slice_count","uint24",14,3,SX_COUNT_PROP),
    SX_FIELD("image_count","uint24",17,3,SX_COUNT_PROP),
    SX_FIELD("texture_format","uint8",20,1,SX_ID),
    SX_FIELD("flags","uint16",21,2,SX_FLAGS),
    SX_FIELD("texture_type","uint8",23,1,SX_ID),
    SX_FIELD("microseconds_per_frame","uint24",24,3,SX_NONE),
    SX_FIELD("reserved","uint32",27,4,SX_RESERVED),
    SX_FIELD("user_data0","uint32",31,4,SX_NONE),
    SX_FIELD("user_data1","uint32",35,4,SX_NONE),
    SX_FIELD("endpoint_count","uint16",39,2,SX_COUNT_PROP),
    SX_FIELD("endpoint_offset","uint32",41,4,SX_OFFSET),
    SX_FIELD("endpoint_size","uint24",45,3,SX_SIZE),
    SX_FIELD("selector_count","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("selector_offset","uint32",50,4,SX_OFFSET),
    SX_FIELD("selector_size","uint24",54,3,SX_SIZE),
    SX_FIELD("tables_offset","uint32",57,4,SX_OFFSET),
    SX_FIELD("tables_size","uint32",61,4,SX_SIZE),
    SX_FIELD("slice_descriptors_offset","uint32",65,4,SX_OFFSET),
    SX_FIELD("extended_offset","uint32",69,4,SX_OFFSET),
    SX_FIELD("extended_size","uint32",73,4,SX_SIZE),
};
static const sx_layout sxrm_basis_header = {UINT32_C(0x601d0078),"basis_header",sxrm_basis_header_fields,SX_COUNT(sxrm_basis_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_basis_slice_fields[] = {
    SX_FIELD("image_index","uint24",0,3,SX_ID),
    SX_FIELD("level_index","uint8",3,1,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("width","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",7,2,SX_COUNT_PROP),
    SX_FIELD("blocks_x","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("blocks_y","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("data_offset","uint32",13,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",17,4,SX_SIZE),
    SX_FIELD("slice_crc16","uint16",21,2,SX_CHECKSUM),
};
static const sx_layout sxrm_basis_slice = {UINT32_C(0x601d0079),"basis_slice",sxrm_basis_slice_fields,SX_COUNT(sxrm_basis_slice_fields),SX_LE};
static const sx_layout *const sx_rastermore_layouts[] = {
    &sxrm_vtf70_header,
    &sxrm_vtf72_header,
    &sxrm_exr_header,
    &sxrm_exr_attribute_length,
    &sxrm_exr_channel,
    &sxrm_exr_box2i,
    &sxrm_exr_float,
    &sxrm_exr_v2f,
    &sxrm_exr_compression,
    &sxrm_exr_line_order,
    &sxrm_exr_chunk_offset,
    &sxrm_exr_scanline_chunk,
    &sxrm_jp2_box,
    &sxrm_jp2_extended_size,
    &sxrm_jp2_signature,
    &sxrm_jp2_file_type,
    &sxrm_jp2_compatible_brand,
    &sxrm_jp2_image_header,
    &sxrm_jp2_color_header,
    &sxrm_jp2_enumerated_color,
    &sxrm_j2k_marker,
    &sxrm_j2k_segment_length,
    &sxrm_j2k_siz,
    &sxrm_j2k_component,
    &sxrm_j2k_sot,
    &sxrm_bntx_header,
    &sxrm_bntx_container,
    &sxrm_bntx_block,
    &sxrm_bntx_texture_info,
    &sxrm_bntx_pointer,
    &sxrm_bntx_string_length,
    &sxrm_bntx_relocation_header,
    &sxrm_gvr_prefix,
    &sxrm_gvr_dimensions,
    &sxrm_ilbm_form,
    &sxrm_ilbm_chunk,
    &sxrm_ilbm_bitmap_header,
    &sxrm_ilbm_palette_entry,
    &sxrm_ilbm_view_mode,
    &sxrm_utah_rle_header,
    &sxrm_utah_background,
    &sxrm_utah_colormap,
    &sxrm_utah_comment_length,
    &sxrm_utah_opcode,
    &sxrm_utah_long_opcode,
    &sxrm_utah_run_value,
    &sxrm_dpx_file_header_be,
    &sxrm_dpx_image_header_be,
    &sxrm_dpx_element_be,
    &sxrm_dpx_image_reserved_be,
    &sxrm_dpx_orientation_be,
    &sxrm_dpx_film_be,
    &sxrm_dpx_television_be,
    &sxrm_cineon_file_header_be,
    &sxrm_cineon_image_header_be,
    &sxrm_cineon_channel_be,
    &sxrm_cineon_color_be,
    &sxrm_cineon_data_format_be,
    &sxrm_cineon_origin_be,
    &sxrm_cineon_film_be,
    &sxrm_dpx_file_header_le,
    &sxrm_dpx_image_header_le,
    &sxrm_dpx_element_le,
    &sxrm_dpx_image_reserved_le,
    &sxrm_dpx_orientation_le,
    &sxrm_dpx_film_le,
    &sxrm_dpx_television_le,
    &sxrm_cineon_file_header_le,
    &sxrm_cineon_image_header_le,
    &sxrm_cineon_channel_le,
    &sxrm_cineon_color_le,
    &sxrm_cineon_data_format_le,
    &sxrm_cineon_origin_le,
    &sxrm_cineon_film_le,
    &sxrm_aseprite_header,
    &sxrm_aseprite_frame,
    &sxrm_aseprite_chunk,
    &sxrm_aseprite_layer,
    &sxrm_aseprite_layer_uuid,
    &sxrm_aseprite_cel,
    &sxrm_aseprite_cel_dimensions,
    &sxrm_aseprite_linked_cel,
    &sxrm_aseprite_palette,
    &sxrm_aseprite_palette_entry,
    &sxrm_aseprite_string_length,
    &sxrm_aseprite_user_flags,
    &sxrm_aseprite_rgba,
    &sxrm_godot_ctex_header,
    &sxrm_jbig2_file_header,
    &sxrm_jbig2_page_count,
    &sxrm_jbig2_segment_prefix,
    &sxrm_jbig2_reference1,
    &sxrm_jbig2_reference2,
    &sxrm_jbig2_reference4,
    &sxrm_jbig2_segment_tail1,
    &sxrm_jbig2_segment_tail4,
    &sxrm_jbig2_page_info,
    &sxrm_jbig2_region,
    &sxrm_jbig2_extension,
    &sxrm_raf_header,
    &sxrm_raf_metadata_count,
    &sxrm_raf_metadata_entry,
    &sxrm_raf_dimensions,
    &sxrm_x3f_header20,
    &sxrm_x3f_header21,
    &sxrm_x3f_header23,
    &sxrm_x3f_directory_offset,
    &sxrm_x3f_directory,
    &sxrm_x3f_directory_entry,
    &sxrm_x3f_image,
    &sxrm_x3f_camf2,
    &sxrm_x3f_properties,
    &sxrm_x3f_property,
    &sxrm_mrw_header,
    &sxrm_mrw_chunk,
    &sxrm_mrw_prd,
    &sxrm_mrw_white_balance,
    &sxrm_mrw_tiff_header_le,
    &sxrm_mrw_tiff_header_be,
    &sxrm_basis_header,
    &sxrm_basis_slice,
};
static bool sx_rastermore_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x601d0000U||id>=0x601e0000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x601d0001U:
        if(!xx_rt_wcscmp(r->name,L"first_frame"))text=L"Cubemaps use 65535 for six faces; other supported values include the legacy sphere-map face.";
        if(!xx_rt_wcscmp(r->name,L"low_resolution_format"))text=L"-1 means no low-resolution image.";
        break;
    case 0x601d0002U:
        if(!xx_rt_wcscmp(r->name,L"first_frame"))text=L"Cubemaps use 65535 for six faces; other supported values include the legacy sphere-map face.";
        if(!xx_rt_wcscmp(r->name,L"low_resolution_format"))text=L"-1 means no low-resolution image.";
        break;
    case 0x601d0003U:
        if(!xx_rt_wcscmp(r->name,L"version_and_flags"))text=L"Low byte is the version; upper bits are file feature flags.";
        break;
    case 0x601d0005U:
        if(!xx_rt_wcscmp(r->name,L"pixel_type"))text=L"0=UINT, 1=HALF, 2=FLOAT.";
        break;
    case 0x601d0009U:
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"0=NONE, 1=RLE, 2=ZIPS, 3=ZIP, 4=PIZ, 5=PXR24, 6=B44, 7=B44A, 8=DWAA, 9=DWAB, 10=HTJ2K256, 11=HTJ2K32.";
        break;
    case 0x601d000aU:
        if(!xx_rt_wcscmp(r->name,L"order"))text=L"0=increasing Y, 1=decreasing Y, 2=random Y.";
        break;
    case 0x601d000dU:
        if(!xx_rt_wcscmp(r->name,L"box_size"))text=L"Zero extends to parent end; one selects the following extended size.";
        break;
    case 0x601d0012U:
        if(!xx_rt_wcscmp(r->name,L"bits_per_component"))text=L"Bit 7 is signedness; bits 0..6 store bit depth minus one; 255 uses BPCC.";
        break;
    case 0x601d0016U:
        if(!xx_rt_wcscmp(r->name,L"segment_size"))text=L"Includes this length field; excludes the two-byte marker.";
        break;
    case 0x601d0018U:
        if(!xx_rt_wcscmp(r->name,L"precision_and_sign"))text=L"Bit 7 is signedness; bits 0..6 store precision minus one.";
        break;
    case 0x601d0019U:
        if(!xx_rt_wcscmp(r->name,L"tile_part_size"))text=L"Includes the SOT marker and all bytes through this tile part.";
        break;
    case 0x601d001aU:
        if(!xx_rt_wcscmp(r->name,L"alignment_shift"))text=L"Alignment is 1 shifted left by this value, in bytes.";
        break;
    case 0x601d0021U:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Byte count after the eight-byte chunk prefix.";
        if(!xx_rt_wcscmp(r->name,L"palette_format_and_flags"))text=L"High nibble is the palette format; low nibble contains texture flags.";
        break;
    case 0x601d0023U:
        if(!xx_rt_wcscmp(r->name,L"form_size"))text=L"Bytes following the eight-byte FORM prefix.";
        break;
    case 0x601d0028U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"1=clear first, 2=no background, 4=alpha, 8=comments.";
        if(!xx_rt_wcscmp(r->name,L"colormap_length_log2"))text=L"Entries per colormap channel are 1 shifted left by this value.";
        break;
    case 0x601d002cU:
        if(!xx_rt_wcscmp(r->name,L"operand"))text=L"Byte/run data counts store count minus one; other meanings depend on opcode.";
        break;
    case 0x601d002dU:
        if(!xx_rt_wcscmp(r->name,L"operand"))text=L"Byte/run data counts store count minus one; other meanings depend on opcode.";
        break;
    case 0x601d0033U:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x601d0035U:
        if(!xx_rt_wcscmp(r->name,L"time_code"))text=L"Packed SMPTE timecode, not a Unix timestamp.";
        break;
    case 0x601d003bU:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x601d0041U:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x601d0043U:
        if(!xx_rt_wcscmp(r->name,L"time_code"))text=L"Packed SMPTE timecode, not a Unix timestamp.";
        break;
    case 0x601d0049U:
        if(!xx_rt_wcscmp(r->name,L"x_offset"))text=L"Pixel displacement, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"y_offset"))text=L"Pixel displacement, not a file offset.";
        break;
    case 0x601d004bU:
        if(!xx_rt_wcscmp(r->name,L"color_count"))text=L"Zero denotes 256 colors in older sprites.";
        break;
    case 0x601d004cU:
        if(!xx_rt_wcscmp(r->name,L"chunk_count"))text=L"If zero, use old_chunk_count.";
        break;
    case 0x601d0053U:
        if(!xx_rt_wcscmp(r->name,L"palette_size"))text=L"Number of entries, not byte size.";
        break;
    case 0x601d0058U:
        if(!xx_rt_wcscmp(r->name,L"mipmap_count"))text=L"Number of additional levels after the base image.";
        break;
    case 0x601d0059U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=sequential; bit 1=page count unknown.";
        break;
    case 0x601d005bU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Low 6 bits=type; bit 6=wide page association; bit 7=deferred non-retain.";
        if(!xx_rt_wcscmp(r->name,L"reference_count_and_retention"))text=L"High 3 bits=count (native short form); low bits=retention flags.";
        break;
    case 0x601d0063U:
        if(!xx_rt_wcscmp(r->name,L"extension_type"))text=L"Bit 31 marks a necessary extension; other bits identify its type.";
        break;
    case 0x601d0064U:
        if(!xx_rt_wcscmp(r->name,L"unknown"))text=L"Uninterpreted header bytes; no field meaning is asserted.";
        break;
    case 0x601d0070U:
        if(!xx_rt_wcscmp(r->name,L"string_pool_codeunits"))text=L"Length in UTF-16 code units, not bytes.";
        break;
    case 0x601d0071U:
        if(!xx_rt_wcscmp(r->name,L"name_index"))text=L"UTF-16 code-unit index relative to the string pool.";
        if(!xx_rt_wcscmp(r->name,L"value_index"))text=L"UTF-16 code-unit index relative to the string pool.";
        break;
    case 0x601d0072U:
        if(!xx_rt_wcscmp(r->name,L"metadata_size"))text=L"Byte length after this header; raw image starts at 8 plus this value.";
        break;
    case 0x601d0074U:
        if(!xx_rt_wcscmp(r->name,L"unknown"))text=L"Uninterpreted camera-specific PRD bytes.";
        break;
    case 0x601d0075U:
        if(!xx_rt_wcscmp(r->name,L"denominator_exponents"))text=L"Four encoded gain denominators; the channel order depends on the PRD Bayer pattern.";
        break;
    case 0x601d0076U:
        if(!xx_rt_wcscmp(r->name,L"first_ifd_offset"))text=L"Relative to this embedded TIFF header.";
        break;
    case 0x601d0077U:
        if(!xx_rt_wcscmp(r->name,L"first_ifd_offset"))text=L"Relative to this embedded TIFF header.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}

/* Describes stored metadata only. Pixel decoding is deliberately outside this provider. */
static bool sxrm_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxrm_read(sx_context *c,uint64_t p,void *b,size_t n){return sxrm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxrm_uint(const uint8_t *b,unsigned n,bool be){uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return x;}
static uint16_t sxrm16(const uint8_t *b,bool be){return (uint16_t)sxrm_uint(b,2,be);}
static uint32_t sxrm32(const uint8_t *b,bool be){return (uint32_t)sxrm_uint(b,4,be);}
/* Pointer aliases are described once. Ambiguous partial overlaps remain covered by the first physical record. */
static bool sxrm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n)
{
 const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);
 if(!n)return true;if(n>20000||!sxrm_span(c,p,z*n))return false;
 for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),b=a+(uint64_t)c->items[i].total_size;if(p<b&&a<p+z*n)return true;}
 return sx_table(c,l,(int64_t)p,(int64_t)z,n);
}
static bool sxrm_add(sx_context *c,const sx_layout *l,uint64_t p){return sxrm_table(c,l,p,1);}
static bool sxrm_string(sx_context *c,uint64_t *p,uint64_t end,char *out,size_t cap)
{
 for(size_t i=0;i<cap;i++){uint8_t b;if(*p>=end||!sxrm_read(c,(*p)++,&b,1))return false;out[i]=(char)b;if(!b)return true;}return false;
}
static bool sxrm_vtf(sx_context *c)
{
 uint8_t h[16];if(!sxrm_read(c,0,h,16)||xx_rt_memcmp(h,"VTF\0",4)||sxrm32(h+4,false)!=7||sxrm32(h+8,false)>2)return false;
 return sxrm_add(c,sxrm32(h+8,false)==2?&sxrm_vtf72_header:&sxrm_vtf70_header,0);
}
static bool sxrm_exr(sx_context *c)
{
 uint8_t h[16];if(!sxrm_read(c,0,h,8)||sxrm32(h,false)!=20000630U||!sxrm_add(c,&sxrm_exr_header,0))return false;
 uint64_t p=8;int32_t ymin=0,ymax=-1;unsigned compression=99;bool terminal=false;
 for(unsigned step=0;step<4096;step++){
  char name[258],type[258];if(!sxrm_string(c,&p,(uint64_t)c->size,name,sizeof(name)))break;if(!name[0]){terminal=true;break;}
  if(!sxrm_string(c,&p,(uint64_t)c->size,type,sizeof(type))||!sxrm_read(c,p,h,4))break;uint32_t n=sxrm32(h,false);if(n>INT32_MAX||!sxrm_span(c,p+4,n))break;
  if(!sxrm_add(c,&sxrm_exr_attribute_length,p))return false;p+=4;
  if(!xx_rt_strcmp(type,"chlist")){uint64_t q=p;for(unsigned ch=0;ch<256;ch++){char channel[258];if(!sxrm_string(c,&q,p+n,channel,sizeof(channel))||!channel[0]||p+n-q<16)break;if(!sxrm_add(c,&sxrm_exr_channel,q))return false;q+=16;}}
  else if(!xx_rt_strcmp(type,"box2i")&&n==16){if(!sxrm_add(c,&sxrm_exr_box2i,p))return false;if(!xx_rt_strcmp(name,"dataWindow")){if(!sxrm_read(c,p,h,16))return false;ymin=(int32_t)sxrm32(h+4,false);ymax=(int32_t)sxrm32(h+12,false);}}
  else if(!xx_rt_strcmp(type,"float")&&n==4){if(!sxrm_add(c,&sxrm_exr_float,p))return false;}
  else if(!xx_rt_strcmp(type,"v2f")&&n==8){if(!sxrm_add(c,&sxrm_exr_v2f,p))return false;}
  else if(!xx_rt_strcmp(type,"compression")&&n==1){if(!sxrm_read(c,p,h,1)||!sxrm_add(c,&sxrm_exr_compression,p))return false;compression=h[0];}
  else if(!xx_rt_strcmp(type,"lineOrder")&&n==1){if(!sxrm_add(c,&sxrm_exr_line_order,p))return false;}
  p+=n;
 }
 if(terminal&&compression<12&&ymax>=ymin){static const unsigned lines[]={1,1,1,16,32,16,32,32,32,256,256,32};uint64_t n=((uint64_t)((int64_t)ymax-ymin+1)+lines[compression]-1)/lines[compression];
  if(n<=4096&&sxrm_span(c,p,n*8)){if(!sxrm_table(c,&sxrm_exr_chunk_offset,p,n))return false;for(uint64_t i=0;i<n;i++){if(!sxrm_read(c,p+i*8,h,8))return false;uint64_t q=sxrm_uint(h,8,false);if(q<p+n*8||!sxrm_read(c,q,h,8))continue;if(sxrm_span(c,q+8,sxrm32(h+4,false))&&!sxrm_add(c,&sxrm_exr_scanline_chunk,q))return false;}}
 }return !c->failed;
}
static bool sxrm_j2k(sx_context *c,uint64_t p,uint64_t end)
{
 uint64_t tile_end=0;for(unsigned step=0;p<end&&step<20000;step++){
  uint8_t h[40];if(end-p<2||!sxrm_read(c,p,h,2))break;uint16_t marker=sxrm16(h,true);if((marker&0xff00)!=0xff00)break;
  if(!sxrm_add(c,&sxrm_j2k_marker,p))return false;p+=2;if(marker==0xff4f)continue;if(marker==0xffd9)break;
  if(marker==0xff93){if(tile_end<p||tile_end>end)break;p=tile_end;continue;}
  if(end-p<2||!sxrm_read(c,p,h,2))break;uint32_t n=sxrm16(h,true);if(n<2||n>end-p)break;if(!sxrm_add(c,&sxrm_j2k_segment_length,p))return false;
  if(marker==0xff51&&n>=38){if(!sxrm_read(c,p+2,h,36)||!sxrm_add(c,&sxrm_j2k_siz,p+2))return false;uint32_t count=sxrm16(h+34,true);if(count&&count<=16384&&(uint64_t)count*3<=n-38&&!sxrm_table(c,&sxrm_j2k_component,p+38,count))return false;}
  else if(marker==0xff90&&n==10){if(!sxrm_read(c,p+2,h,8)||!sxrm_add(c,&sxrm_j2k_sot,p+2))return false;uint32_t z=sxrm32(h+2,true);tile_end=z&&z<=end-(p-2)?p-2+z:end;}
  p+=n;
 }return !c->failed;
}
static bool sxrm_jp2_boxes(sx_context *c,uint64_t p,uint64_t end,unsigned depth,unsigned *budget)
{
 while(p<end&&*budget<20000){(*budget)++;uint8_t h[16];if(end-p<8||!sxrm_read(c,p,h,8))break;uint64_t n=sxrm32(h,true),head=8;
  if(n==1){if(end-p<16||!sxrm_read(c,p+8,h+8,8))break;n=sxrm_uint(h+8,8,true);head=16;}else if(!n)n=end-p;if(n<head||n>end-p)break;
  if(!sxrm_add(c,&sxrm_jp2_box,p)||(head==16&&!sxrm_add(c,&sxrm_jp2_extended_size,p+8)))return false;uint64_t q=p+head,z=n-head;
  if(!xx_rt_memcmp(h+4,"jP  ",4)&&z==4){if(!sxrm_add(c,&sxrm_jp2_signature,q))return false;}
  else if(!xx_rt_memcmp(h+4,"ftyp",4)&&z>=8){if(!sxrm_add(c,&sxrm_jp2_file_type,q))return false;uint64_t count=(z-8)/4;if(count&&count<=20000&&!sxrm_table(c,&sxrm_jp2_compatible_brand,q+8,count))return false;}
  else if(!xx_rt_memcmp(h+4,"jp2h",4)&&depth<2){if(!sxrm_jp2_boxes(c,q,p+n,depth+1,budget))return false;}
  else if(!xx_rt_memcmp(h+4,"ihdr",4)&&z>=14){if(!sxrm_add(c,&sxrm_jp2_image_header,q))return false;}
  else if(!xx_rt_memcmp(h+4,"colr",4)&&z>=3){if(!sxrm_add(c,&sxrm_jp2_color_header,q)||!sxrm_read(c,q,h,1))return false;if(h[0]==1&&z>=7&&!sxrm_add(c,&sxrm_jp2_enumerated_color,q+3))return false;}
  else if(!xx_rt_memcmp(h+4,"jp2c",4)){if(!sxrm_j2k(c,q,p+n))return false;}
  p+=n;
 }return !c->failed;
}
static bool sxrm_bntx_name(sx_context *c,uint64_t p){uint8_t b[2];return !sxrm_read(c,p,b,2)||!sxrm_span(c,p+2,sxrm16(b,false))||sxrm_add(c,&sxrm_bntx_string_length,p);}
static bool sxrm_bntx(sx_context *c)
{
 uint8_t h[160];if(!sxrm_read(c,0,h,88)||xx_rt_memcmp(h,"BNTX\0\0\0\0",8)||!sxrm_add(c,&sxrm_bntx_header,0)||!sxrm_add(c,&sxrm_bntx_container,32))return false;
 uint64_t table=sxrm_uint(h+40,8,false),data=sxrm_uint(h+48,8,false);uint32_t count=sxrm32(h+36,false),reloc=sxrm32(h+24,false),name=sxrm32(h+16,false);
 if(name>=2&&!sxrm_bntx_name(c,name-2))return false;
 if(data>=88&&sxrm_read(c,data,h,16)&&!xx_rt_memcmp(h,"BRTD",4)&&!sxrm_add(c,&sxrm_bntx_block,data))return false;
 if(reloc>=88&&sxrm_read(c,reloc,h,16)&&!xx_rt_memcmp(h,"_RLT",4)&&!sxrm_add(c,&sxrm_bntx_relocation_header,reloc))return false;
 if(count>1024||table<88||!sxrm_span(c,table,(uint64_t)count*8))return true;if(!sxrm_table(c,&sxrm_bntx_pointer,table,count))return false;
 for(uint32_t i=0;i<count;i++){if(!sxrm_read(c,table+(uint64_t)i*8,h,8))return false;uint64_t q=sxrm_uint(h,8,false);if(q<88||!sxrm_read(c,q,h,160)||xx_rt_memcmp(h,"BRTI",4))continue;
  if(!sxrm_add(c,&sxrm_bntx_block,q)||!sxrm_add(c,&sxrm_bntx_texture_info,q+16))return false;uint64_t nameoff=sxrm_uint(h+96,8,false),mips=sxrm_uint(h+112,8,false);unsigned n=sxrm16(h+22,false);
  if(nameoff>=88&&!sxrm_bntx_name(c,nameoff))return false;if(n<=16&&mips>=88&&sxrm_span(c,mips,(uint64_t)n*8)&&!sxrm_table(c,&sxrm_bntx_pointer,mips,n))return false;
 }return !c->failed;
}
static bool sxrm_ilbm(sx_context *c)
{
 uint8_t h[12];if(!sxrm_read(c,0,h,12)||xx_rt_memcmp(h,"FORM",4)||xx_rt_memcmp(h+8,"ILBM",4)||!sxrm_add(c,&sxrm_ilbm_form,0))return false;
 uint64_t end=(uint64_t)sxrm32(h+4,true)+8,p=12;if(end>(uint64_t)c->size)end=(uint64_t)c->size;
 for(unsigned step=0;p<end&&step<4096;step++){if(end-p<8||!sxrm_read(c,p,h,8))break;uint32_t n=sxrm32(h+4,true);if(n>end-p-8)break;if(!sxrm_add(c,&sxrm_ilbm_chunk,p))return false;
  if(!xx_rt_memcmp(h,"BMHD",4)&&n>=20){if(!sxrm_add(c,&sxrm_ilbm_bitmap_header,p+8))return false;}
  else if(!xx_rt_memcmp(h,"CMAP",4)&&n/3<=256&&n>=3){if(!sxrm_table(c,&sxrm_ilbm_palette_entry,p+8,n/3))return false;}
  else if(!xx_rt_memcmp(h,"CAMG",4)&&n>=4){if(!sxrm_add(c,&sxrm_ilbm_view_mode,p+8))return false;}p+=8+(uint64_t)n+(n&1U);
 }return !c->failed;
}
static bool sxrm_utah(sx_context *c)
{
 uint8_t h[16];if(!sxrm_read(c,0,h,15)||sxrm16(h,false)!=0xcc52||!sxrm_add(c,&sxrm_utah_rle_header,0))return false;unsigned flags=h[10],colors=h[11],maps=h[13],log=h[14];uint64_t p=15;
 if(!(flags&2)&&colors&&colors<=4&&sxrm_span(c,p,colors)&&!sxrm_table(c,&sxrm_utah_background,p,colors))return false;p+=(flags&2)?1:1+(colors/2)*2;
 if(log>8||maps>4)return true;uint64_t n=(uint64_t)maps<<log;if(!sxrm_span(c,p,n*2))return true;if(n&&!sxrm_table(c,&sxrm_utah_colormap,p,n))return false;p+=n*2;
 if(flags&8){if(!sxrm_read(c,p,h,2))return true;n=sxrm16(h,false);if(!sxrm_span(c,p+2,n))return true;if(!sxrm_add(c,&sxrm_utah_comment_length,p))return false;p+=2+n+(n&1);}
 for(unsigned step=0;step<20000&&p<(uint64_t)c->size;step++){if(!sxrm_read(c,p,h,2))break;unsigned op=h[0]&0x3f,longop=h[0]&0x40;uint32_t count=h[1],size=longop?4:2;if(h[0]&0x80||op==0||op==4||op>7)break;
  if(longop){if(!sxrm_read(c,p,h,4))break;count=sxrm16(h+2,false);}if(!sxrm_add(c,longop?&sxrm_utah_long_opcode:&sxrm_utah_opcode,p))return false;p+=size;
  if(op==7)break;if(op==5){uint64_t z=(uint64_t)count+1;p+=z+(z&1);}else if(op==6){if(!sxrm_span(c,p,2))break;if(!sxrm_add(c,&sxrm_utah_run_value,p))return false;p+=2;}
 }return !c->failed;
}
static bool sxrm_dpx(sx_context *c)
{
 uint8_t h[36];if(!sxrm_read(c,0,h,36))return false;bool be=!xx_rt_memcmp(h,"SDPX",4);if(!be&&xx_rt_memcmp(h,"XPDS",4))return false;
 if(!sxrm_add(c,be?&sxrm_dpx_file_header_be:&sxrm_dpx_file_header_le,0))return false;
 if(sxrm_span(c,768,12)&&!sxrm_add(c,be?&sxrm_dpx_image_header_be:&sxrm_dpx_image_header_le,768))return false;
 if(sxrm_span(c,780,576)&&!sxrm_table(c,be?&sxrm_dpx_element_be:&sxrm_dpx_element_le,780,8))return false;
 if(sxrm_span(c,1356,52)&&!sxrm_add(c,be?&sxrm_dpx_image_reserved_be:&sxrm_dpx_image_reserved_le,1356))return false;
 if(sxrm_span(c,1408,256)&&!sxrm_add(c,be?&sxrm_dpx_orientation_be:&sxrm_dpx_orientation_le,1408))return false;
 if(sxrm32(h+28,be)>=384&&sxrm_span(c,1664,384)){if(!sxrm_add(c,be?&sxrm_dpx_film_be:&sxrm_dpx_film_le,1664)||!sxrm_add(c,be?&sxrm_dpx_television_be:&sxrm_dpx_television_le,1920))return false;}return !c->failed;
}
static bool sxrm_cineon(sx_context *c)
{
 uint8_t h[24];if(!sxrm_read(c,0,h,24))return false;bool be=sxrm32(h,true)==0x802a5fd7U;if(!be&&sxrm32(h,false)!=0x802a5fd7U)return false;
 if(!sxrm_add(c,be?&sxrm_cineon_file_header_be:&sxrm_cineon_file_header_le,0))return false;
 if(sxrm_span(c,192,4)&&!sxrm_add(c,be?&sxrm_cineon_image_header_be:&sxrm_cineon_image_header_le,192))return false;
 if(sxrm_span(c,196,224)&&!sxrm_table(c,be?&sxrm_cineon_channel_be:&sxrm_cineon_channel_le,196,8))return false;
 if(sxrm_span(c,420,260)&&!sxrm_add(c,be?&sxrm_cineon_color_be:&sxrm_cineon_color_le,420))return false;
 if(sxrm_span(c,680,32)&&!sxrm_add(c,be?&sxrm_cineon_data_format_be:&sxrm_cineon_data_format_le,680))return false;
 if(sxrm_span(c,712,312)&&!sxrm_add(c,be?&sxrm_cineon_origin_be:&sxrm_cineon_origin_le,712))return false;
 if(sxrm32(h+12,be)>=1024&&sxrm_span(c,1024,1024)&&!sxrm_add(c,be?&sxrm_cineon_film_be:&sxrm_cineon_film_le,1024))return false;return !c->failed;
}
static bool sxrm_ase_string(sx_context *c,uint64_t *p,uint64_t end)
{
 uint8_t h[2];if(*p>end||end-*p<2||!sxrm_read(c,*p,h,2))return false;uint32_t n=sxrm16(h,false);if(n>end-*p-2)return false;if(!sxrm_add(c,&sxrm_aseprite_string_length,*p))return false;*p+=2+n;return true;
}
static bool sxrm_aseprite(sx_context *c)
{
 uint8_t h[128];if(!sxrm_read(c,0,h,128)||sxrm16(h+4,false)!=0xa5e0||!sxrm_add(c,&sxrm_aseprite_header,0))return false;unsigned frames=sxrm16(h+6,false),flags=sxrm32(h+14,false),budget=0;uint64_t p=128;
 for(unsigned i=0;i<frames&&i<4096;i++){
  if(!sxrm_read(c,p,h,16))break;uint32_t z=sxrm32(h,false),chunks=sxrm32(h+12,false);if(!chunks)chunks=sxrm16(h+6,false);if(z<16||!sxrm_span(c,p,z)||chunks>4096)break;if(!sxrm_add(c,&sxrm_aseprite_frame,p))return false;uint64_t q=p+16,end=p+z;
  for(unsigned k=0;k<chunks&&budget++<20000;k++){
   if(end-q<6||!sxrm_read(c,q,h,6))break;uint32_t n=sxrm32(h,false);unsigned type=sxrm16(h+4,false);if(n<6||n>end-q)break;if(!sxrm_add(c,&sxrm_aseprite_chunk,q))return false;uint64_t a=q+6,stop=q+n;n-=6;
   if(type==0x2004&&n>=18){if(!sxrm_read(c,a,h,18)||!sxrm_add(c,&sxrm_aseprite_layer,a))return false;uint64_t tail=a+18+sxrm16(h+16,false);if((flags&4)&&tail<=stop&&stop-tail>=16&&!sxrm_add(c,&sxrm_aseprite_layer_uuid,tail))return false;}
   else if(type==0x2005&&n>=16){if(!sxrm_read(c,a,h,16)||!sxrm_add(c,&sxrm_aseprite_cel,a))return false;unsigned ct=sxrm16(h+7,false);if((ct==0||ct==2)&&n>=20){if(!sxrm_add(c,&sxrm_aseprite_cel_dimensions,a+16))return false;}else if(ct==1&&n>=18&&!sxrm_add(c,&sxrm_aseprite_linked_cel,a+16))return false;}
   else if(type==0x2019&&n>=20){if(!sxrm_read(c,a,h,20)||!sxrm_add(c,&sxrm_aseprite_palette,a))return false;uint32_t first=sxrm32(h+4,false),last=sxrm32(h+8,false);uint64_t r=a+20;if(last>=first&&last-first<4096)for(uint64_t j=0;j<=(uint64_t)last-first;j++){if(stop-r<6||!sxrm_read(c,r,h,6))break;if(!sxrm_add(c,&sxrm_aseprite_palette_entry,r))return false;r+=6;if((sxrm16(h,false)&1)&&!sxrm_ase_string(c,&r,stop))break;}}
   else if(type==0x2020&&n>=4){if(!sxrm_read(c,a,h,4)||!sxrm_add(c,&sxrm_aseprite_user_flags,a))return false;uint32_t uf=sxrm32(h,false);uint64_t r=a+4;bool good=!(uf&1)||sxrm_ase_string(c,&r,stop);if(good&&(uf&2)&&stop-r>=4&&!sxrm_add(c,&sxrm_aseprite_rgba,r))return false;}
   q=stop;
  }p=end;
 }return !c->failed;
}
static bool sxrm_jbig2(sx_context *c)
{
 uint8_t h[20];if(!sxrm_read(c,0,h,9)||xx_rt_memcmp(h,"\x97JB2\r\n\x1a\n",8)||!sxrm_add(c,&sxrm_jbig2_file_header,0))return false;uint64_t p=9;
 if(!(h[8]&2)){if(!sxrm_span(c,p,4))return true;if(!sxrm_add(c,&sxrm_jbig2_page_count,p))return false;p+=4;}
 for(unsigned step=0;step<4096;step++){
  if(!sxrm_read(c,p,h,6))break;uint32_t id=sxrm32(h,true);unsigned flags=h[4],type=flags&63,n=h[5]>>5,refsize=id<=256?1:id<=65536?2:4,pagesize=(flags&64)?4:1;if(n>4)break;
  uint64_t tail=p+6+(uint64_t)n*refsize;if(!sxrm_read(c,tail,h,pagesize+4))break;uint32_t z=sxrm32(h+pagesize,true);uint64_t body=tail+pagesize+4;if(!sxrm_span(c,body,z))break;
  if(!sxrm_add(c,&sxrm_jbig2_segment_prefix,p)||!sxrm_table(c,refsize==1?&sxrm_jbig2_reference1:refsize==2?&sxrm_jbig2_reference2:&sxrm_jbig2_reference4,p+6,n)||!sxrm_add(c,pagesize==1?&sxrm_jbig2_segment_tail1:&sxrm_jbig2_segment_tail4,tail))return false;
  if(type==48&&z>=19){if(!sxrm_add(c,&sxrm_jbig2_page_info,body))return false;}
  else if((type==4||type==6||type==7||type==20||type==22||type==23||type==36||type==38||type==39||type==40||type==42||type==43)&&z>=17){if(!sxrm_add(c,&sxrm_jbig2_region,body))return false;}
  else if(type==62&&z>=4&&!sxrm_add(c,&sxrm_jbig2_extension,body))return false;p=body+z;if(type==51)break;
 }return !c->failed;
}
static bool sxrm_raf(sx_context *c)
{
 uint8_t h[108];if(!sxrm_read(c,0,h,108)||xx_rt_memcmp(h,"FUJIFILMCCD-RAW ",16)||!sxrm_add(c,&sxrm_raf_header,0))return false;
 uint64_t p=sxrm32(h+92,true),z=sxrm32(h+96,true);if(p<108||z<4||!sxrm_span(c,p,z)||!sxrm_read(c,p,h,4))return true;unsigned count=sxrm32(h,true);uint64_t end=p+z;if(count>1024)return true;
 if(!sxrm_add(c,&sxrm_raf_metadata_count,p))return false;p+=4;for(unsigned i=0;i<count;i++){if(end-p<4||!sxrm_read(c,p,h,4))break;unsigned tag=sxrm16(h,true),n=sxrm16(h+2,true);if(n>end-p-4)break;if(!sxrm_add(c,&sxrm_raf_metadata_entry,p))return false;if(tag==0x100&&n==4&&!sxrm_add(c,&sxrm_raf_dimensions,p+4))return false;p+=4+n;}return !c->failed;
}
static bool sxrm_x3f(sx_context *c)
{
 uint8_t h[40];if(!sxrm_read(c,0,h,40)||xx_rt_memcmp(h,"FOVb",4))return false;uint32_t version=sxrm32(h+4,false);if(version<0x20000||version>0x20003)return false;uint64_t head=version==0x20000?40:version<0x20003?232:264;
 if(!sxrm_add(c,version==0x20000?&sxrm_x3f_header20:version<0x20003?&sxrm_x3f_header21:&sxrm_x3f_header23,0))return false;
 if(c->size<(int64_t)head+4||!sxrm_read(c,(uint64_t)c->size-4,h,4))return true;uint64_t dir=sxrm32(h,false);if(!sxrm_add(c,&sxrm_x3f_directory_offset,(uint64_t)c->size-4))return false;
 if(dir<head||!sxrm_read(c,dir,h,12)||xx_rt_memcmp(h,"SECd",4))return true;unsigned n=sxrm32(h+8,false);if(n>32||!sxrm_span(c,dir+12,(uint64_t)n*12))return true;
 if(!sxrm_add(c,&sxrm_x3f_directory,dir)||!sxrm_table(c,&sxrm_x3f_directory_entry,dir+12,n))return false;
 for(unsigned i=0;i<n;i++){if(!sxrm_read(c,dir+12+(uint64_t)i*12,h,12))return false;uint64_t q=sxrm32(h,false);uint32_t z=sxrm32(h+4,false);if(q<head||z<24||!sxrm_span(c,q,z)||!sxrm_read(c,q,h,24))continue;
  if(!xx_rt_memcmp(h,"SECi",4)&&z>=28){if(!sxrm_add(c,&sxrm_x3f_image,q))return false;}
  else if(!xx_rt_memcmp(h,"SECc",4)&&z>=28&&sxrm32(h+8,false)==2){if(!sxrm_add(c,&sxrm_x3f_camf2,q))return false;}
  else if(!xx_rt_memcmp(h,"SECp",4)){if(!sxrm_add(c,&sxrm_x3f_properties,q))return false;uint32_t count=sxrm32(h+8,false);if(count<=20000&&(uint64_t)count*8<=z-24&&!sxrm_table(c,&sxrm_x3f_property,q+24,count))return false;}
 }return !c->failed;
}
static bool sxrm_mrw(sx_context *c)
{
 uint8_t h[8];if(!sxrm_read(c,0,h,8)||xx_rt_memcmp(h,"\0MRM",4)||!sxrm_add(c,&sxrm_mrw_header,0))return false;uint64_t p=8,end=8+(uint64_t)sxrm32(h+4,true);if(end>(uint64_t)c->size)end=(uint64_t)c->size;
 for(unsigned i=0;i<32&&p<end;i++){if(end-p<8||!sxrm_read(c,p,h,8))break;uint32_t n=sxrm32(h+4,true);if(n>end-p-8)break;if(!sxrm_add(c,&sxrm_mrw_chunk,p))return false;
  if(!xx_rt_memcmp(h,"\0PRD",4)&&n>=24){if(!sxrm_add(c,&sxrm_mrw_prd,p+8))return false;}
  else if(!xx_rt_memcmp(h,"\0WBG",4)&&n>=12){if(!sxrm_add(c,&sxrm_mrw_white_balance,p+8))return false;}
  else if(!xx_rt_memcmp(h,"\0TTW",4)&&n>=8){if(!sxrm_read(c,p+8,h,8))return false;if(!xx_rt_memcmp(h,"II\x2a\0",4)){if(!sxrm_add(c,&sxrm_mrw_tiff_header_le,p+8))return false;}else if(!xx_rt_memcmp(h,"MM\0\x2a",4)&&!sxrm_add(c,&sxrm_mrw_tiff_header_be,p+8))return false;}p+=8+n;
 }return !c->failed;
}
static bool sxrm_basis(sx_context *c)
{
 uint8_t h[77];if(!sxrm_read(c,0,h,77)||xx_rt_memcmp(h,"sB",2)||!sxrm_add(c,&sxrm_basis_header,0))return false;uint64_t p=sxrm32(h+65,false),n=sxrm_uint(h+14,3,false);
 if(p>=77&&n<=4087&&sxrm_span(c,p,n*23)&&!sxrm_table(c,&sxrm_basis_slice,p,n))return false;return !c->failed;
}
static int sxrm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxrm_finish(sx_context *c)
{
 size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxrm_order);
 for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxrm_order);return !c->failed;
}
static bool sx_rastermore_supports(xx_file_type_t type)
{
 switch(type){case XX_FILE_TYPE_VALVE_VTF:case XX_FILE_TYPE_OPENEXR:case XX_FILE_TYPE_JPEG2000_JP2:case XX_FILE_TYPE_NINTENDO_BNTX:case XX_FILE_TYPE_SEGA_GVR:case XX_FILE_TYPE_IFF_ILBM:case XX_FILE_TYPE_UTAH_RLE:case XX_FILE_TYPE_DPX:case XX_FILE_TYPE_CINEON:case XX_FILE_TYPE_ASEPRITE:case XX_FILE_TYPE_GODOT_CTEX:case XX_FILE_TYPE_JBIG2:case XX_FILE_TYPE_FUJIFILM_RAF:case XX_FILE_TYPE_SIGMA_X3F:case XX_FILE_TYPE_MINOLTA_MRW:case XX_FILE_TYPE_BASIS_TEXTURE:return true;default:return false;}
}
static bool sx_rastermore_build(sx_context *c)
{
 bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_VALVE_VTF:ok=sxrm_vtf(c);break;case XX_FILE_TYPE_OPENEXR:ok=sxrm_exr(c);break;case XX_FILE_TYPE_JPEG2000_JP2:{unsigned budget=0;ok=sxrm_jp2_boxes(c,0,(uint64_t)c->size,0,&budget);break;}case XX_FILE_TYPE_NINTENDO_BNTX:ok=sxrm_bntx(c);break;case XX_FILE_TYPE_SEGA_GVR:ok=sxrm_add(c,&sxrm_gvr_prefix,0)&&sxrm_add(c,&sxrm_gvr_dimensions,12);break;case XX_FILE_TYPE_IFF_ILBM:ok=sxrm_ilbm(c);break;case XX_FILE_TYPE_UTAH_RLE:ok=sxrm_utah(c);break;case XX_FILE_TYPE_DPX:ok=sxrm_dpx(c);break;case XX_FILE_TYPE_CINEON:ok=sxrm_cineon(c);break;case XX_FILE_TYPE_ASEPRITE:ok=sxrm_aseprite(c);break;case XX_FILE_TYPE_GODOT_CTEX:ok=sxrm_add(c,&sxrm_godot_ctex_header,0);break;case XX_FILE_TYPE_JBIG2:ok=sxrm_jbig2(c);break;case XX_FILE_TYPE_FUJIFILM_RAF:ok=sxrm_raf(c);break;case XX_FILE_TYPE_SIGMA_X3F:ok=sxrm_x3f(c);break;case XX_FILE_TYPE_MINOLTA_MRW:ok=sxrm_mrw(c);break;case XX_FILE_TYPE_BASIS_TEXTURE:ok=sxrm_basis(c);break;default:break;}return ok&&c->count>0&&sxrm_finish(c);
}
