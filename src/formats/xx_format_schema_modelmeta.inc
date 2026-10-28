/* SPDX-License-Identifier: MIT
 * Stored binary model metadata. Scope: docs/data_struct_modelmeta_scope.txt. */
static const xx_data_struct_field_desc sxmo_b3d_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("version","int32",8,4,SX_ID),
};
static const sx_layout sxmo_b3d_header = {UINT32_C(0x60210001),"b3d_header",sxmo_b3d_header_fields,SX_COUNT(sxmo_b3d_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_chunk_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
};
static const sx_layout sxmo_b3d_chunk = {UINT32_C(0x60210002),"b3d_chunk",sxmo_b3d_chunk_fields,SX_COUNT(sxmo_b3d_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_texture_fields[] = {
    SX_FIELD("flags","int32",0,4,SX_FLAGS),
    SX_FIELD("blend","int32",4,4,SX_ID),
    SX_FIELD("x_position","float32",8,4,SX_NONE),
    SX_FIELD("y_position","float32",12,4,SX_NONE),
    SX_FIELD("x_scale","float32",16,4,SX_NONE),
    SX_FIELD("y_scale","float32",20,4,SX_NONE),
    SX_FIELD("rotation","float32",24,4,SX_NONE),
};
static const sx_layout sxmo_b3d_texture = {UINT32_C(0x60210003),"b3d_texture",sxmo_b3d_texture_fields,SX_COUNT(sxmo_b3d_texture_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_brush_count_fields[] = {
    SX_FIELD("texture_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_b3d_brush_count = {UINT32_C(0x60210004),"b3d_brush_count",sxmo_b3d_brush_count_fields,SX_COUNT(sxmo_b3d_brush_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_texture_index_fields[] = {
    SX_FIELD("texture_index","int32",0,4,SX_ID),
};
static const sx_layout sxmo_b3d_texture_index = {UINT32_C(0x60210005),"b3d_texture_index",sxmo_b3d_texture_index_fields,SX_COUNT(sxmo_b3d_texture_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_brush_fields[] = {
    SX_FIELD("red","float32",0,4,SX_NONE),
    SX_FIELD("green","float32",4,4,SX_NONE),
    SX_FIELD("blue","float32",8,4,SX_NONE),
    SX_FIELD("alpha","float32",12,4,SX_NONE),
    SX_FIELD("shininess","float32",16,4,SX_NONE),
    SX_FIELD("blend","int32",20,4,SX_ID),
    SX_FIELD("effects","int32",24,4,SX_FLAGS),
};
static const sx_layout sxmo_b3d_brush = {UINT32_C(0x60210006),"b3d_brush",sxmo_b3d_brush_fields,SX_COUNT(sxmo_b3d_brush_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_node_fields[] = {
    SX_FIELD("position","float32[3]",0,12,SX_NONE),
    SX_FIELD("scale","float32[3]",12,12,SX_NONE),
    SX_FIELD("rotation_wxyz","float32[4]",24,16,SX_NONE),
};
static const sx_layout sxmo_b3d_node = {UINT32_C(0x60210007),"b3d_node",sxmo_b3d_node_fields,SX_COUNT(sxmo_b3d_node_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_brush_index_fields[] = {
    SX_FIELD("brush_index","int32",0,4,SX_ID),
};
static const sx_layout sxmo_b3d_brush_index = {UINT32_C(0x60210008),"b3d_brush_index",sxmo_b3d_brush_index_fields,SX_COUNT(sxmo_b3d_brush_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_vertices_fields[] = {
    SX_FIELD("flags","int32",0,4,SX_FLAGS),
    SX_FIELD("texture_coordinate_sets","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("texture_coordinate_size","int32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_b3d_vertices = {UINT32_C(0x60210009),"b3d_vertices",sxmo_b3d_vertices_fields,SX_COUNT(sxmo_b3d_vertices_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_position_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxmo_b3d_position = {UINT32_C(0x6021000a),"b3d_position",sxmo_b3d_position_fields,SX_COUNT(sxmo_b3d_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_normal_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxmo_b3d_normal = {UINT32_C(0x6021000b),"b3d_normal",sxmo_b3d_normal_fields,SX_COUNT(sxmo_b3d_normal_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_color_fields[] = {
    SX_FIELD("red","float32",0,4,SX_NONE),
    SX_FIELD("green","float32",4,4,SX_NONE),
    SX_FIELD("blue","float32",8,4,SX_NONE),
    SX_FIELD("alpha","float32",12,4,SX_NONE),
};
static const sx_layout sxmo_b3d_color = {UINT32_C(0x6021000c),"b3d_color",sxmo_b3d_color_fields,SX_COUNT(sxmo_b3d_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_texture_coordinate_fields[] = {
    SX_FIELD("coordinate","float32",0,4,SX_NONE),
};
static const sx_layout sxmo_b3d_texture_coordinate = {UINT32_C(0x6021000d),"b3d_texture_coordinate",sxmo_b3d_texture_coordinate_fields,SX_COUNT(sxmo_b3d_texture_coordinate_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_triangle_fields[] = {
    SX_FIELD("vertex0","int32",0,4,SX_ID),
    SX_FIELD("vertex1","int32",4,4,SX_ID),
    SX_FIELD("vertex2","int32",8,4,SX_ID),
};
static const sx_layout sxmo_b3d_triangle = {UINT32_C(0x6021000e),"b3d_triangle",sxmo_b3d_triangle_fields,SX_COUNT(sxmo_b3d_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_header_fields[] = {
    SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
    SX_FIELD("version","int32",10,4,SX_ID),
};
static const sx_layout sxmo_ms3d_header = {UINT32_C(0x6021000f),"ms3d_header",sxmo_ms3d_header_fields,SX_COUNT(sxmo_ms3d_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_vertex_count_fields[] = {
    SX_FIELD("vertex_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_ms3d_vertex_count = {UINT32_C(0x60210010),"ms3d_vertex_count",sxmo_ms3d_vertex_count_fields,SX_COUNT(sxmo_ms3d_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_triangle_count_fields[] = {
    SX_FIELD("triangle_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_ms3d_triangle_count = {UINT32_C(0x60210011),"ms3d_triangle_count",sxmo_ms3d_triangle_count_fields,SX_COUNT(sxmo_ms3d_triangle_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_group_count_fields[] = {
    SX_FIELD("group_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_ms3d_group_count = {UINT32_C(0x60210012),"ms3d_group_count",sxmo_ms3d_group_count_fields,SX_COUNT(sxmo_ms3d_group_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_material_count_fields[] = {
    SX_FIELD("material_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_ms3d_material_count = {UINT32_C(0x60210013),"ms3d_material_count",sxmo_ms3d_material_count_fields,SX_COUNT(sxmo_ms3d_material_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_vertex_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("position","float32[3]",1,12,SX_NONE),
    SX_FIELD("bone_index","int8",13,1,SX_ID),
    SX_FIELD("reference_count","uint8",14,1,SX_COUNT_PROP),
};
static const sx_layout sxmo_ms3d_vertex = {UINT32_C(0x60210014),"ms3d_vertex",sxmo_ms3d_vertex_fields,SX_COUNT(sxmo_ms3d_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_triangle_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("vertex_indices","uint16[3]",2,6,SX_ID),
    SX_FIELD("vertex_normals","float32[9]",8,36,SX_NONE),
    SX_FIELD("texture_s","float32[3]",44,12,SX_NONE),
    SX_FIELD("texture_t","float32[3]",56,12,SX_NONE),
    SX_FIELD("smoothing_group","uint8",68,1,SX_ID),
    SX_FIELD("group_index","uint8",69,1,SX_ID),
};
static const sx_layout sxmo_ms3d_triangle = {UINT32_C(0x60210015),"ms3d_triangle",sxmo_ms3d_triangle_fields,SX_COUNT(sxmo_ms3d_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_group_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("name","char[32]",1,32,SX_STRING),
    SX_FIELD("triangle_count","uint16",33,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_ms3d_group = {UINT32_C(0x60210016),"ms3d_group",sxmo_ms3d_group_fields,SX_COUNT(sxmo_ms3d_group_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_triangle_index_fields[] = {
    SX_FIELD("triangle_index","uint16",0,2,SX_ID),
};
static const sx_layout sxmo_ms3d_triangle_index = {UINT32_C(0x60210017),"ms3d_triangle_index",sxmo_ms3d_triangle_index_fields,SX_COUNT(sxmo_ms3d_triangle_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_material_index_fields[] = {
    SX_FIELD("material_index","int8",0,1,SX_ID),
};
static const sx_layout sxmo_ms3d_material_index = {UINT32_C(0x60210018),"ms3d_material_index",sxmo_ms3d_material_index_fields,SX_COUNT(sxmo_ms3d_material_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_material_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_STRING),
    SX_FIELD("ambient","float32[4]",32,16,SX_NONE),
    SX_FIELD("diffuse","float32[4]",48,16,SX_NONE),
    SX_FIELD("specular","float32[4]",64,16,SX_NONE),
    SX_FIELD("emissive","float32[4]",80,16,SX_NONE),
    SX_FIELD("shininess","float32",96,4,SX_NONE),
    SX_FIELD("transparency","float32",100,4,SX_NONE),
    SX_FIELD("mode","uint8",104,1,SX_FLAGS),
    SX_FIELD("texture","char[128]",105,128,SX_STRING),
    SX_FIELD("alpha_map","char[128]",233,128,SX_STRING),
};
static const sx_layout sxmo_ms3d_material = {UINT32_C(0x60210019),"ms3d_material",sxmo_ms3d_material_fields,SX_COUNT(sxmo_ms3d_material_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_animation_fields[] = {
    SX_FIELD("frames_per_second","float32",0,4,SX_NONE),
    SX_FIELD("current_time","float32",4,4,SX_NONE),
    SX_FIELD("total_frames","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("joint_count","uint16",12,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_ms3d_animation = {UINT32_C(0x6021001a),"ms3d_animation",sxmo_ms3d_animation_fields,SX_COUNT(sxmo_ms3d_animation_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_bch21_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("backward_compatibility","uint8",4,1,SX_ID),
    SX_FIELD("forward_compatibility","uint8",5,1,SX_ID),
    SX_FIELD("converter_version","uint16",6,2,SX_ID),
    SX_FIELD("contents_offset","int32",8,4,SX_OFFSET),
    SX_FIELD("strings_offset","int32",12,4,SX_OFFSET),
    SX_FIELD("commands_offset","int32",16,4,SX_OFFSET),
    SX_FIELD("raw_data_offset","int32",20,4,SX_OFFSET),
    SX_FIELD("raw_extra_offset","int32",24,4,SX_OFFSET),
    SX_FIELD("relocations_offset","int32",28,4,SX_OFFSET),
    SX_FIELD("contents_size","int32",32,4,SX_SIZE),
    SX_FIELD("strings_size","int32",36,4,SX_SIZE),
    SX_FIELD("commands_size","int32",40,4,SX_SIZE),
    SX_FIELD("raw_data_size","int32",44,4,SX_SIZE),
    SX_FIELD("raw_extra_size","int32",48,4,SX_SIZE),
    SX_FIELD("relocations_size","int32",52,4,SX_SIZE),
    SX_FIELD("uninitialized_data_size","int32",56,4,SX_SIZE),
    SX_FIELD("uninitialized_commands_size","int32",60,4,SX_SIZE),
    SX_FIELD("flags","uint8",64,1,SX_FLAGS),
    SX_FIELD("padding","uint8",65,1,SX_RESERVED),
    SX_FIELD("address_count","uint16",66,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_bch21_header = {UINT32_C(0x6021001b),"bch21_header",sxmo_bch21_header_fields,SX_COUNT(sxmo_bch21_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_bch_relocation_fields[] = {
    SX_FIELD("encoded_relocation","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmo_bch_relocation = {UINT32_C(0x6021001c),"bch_relocation",sxmo_bch_relocation_fields,SX_COUNT(sxmo_bch_relocation_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_mesh_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("serializer_version","char[24]",2,24,SX_STRING),
};
static const sx_layout sxmo_ogre_mesh_header = {UINT32_C(0x6021001d),"ogre_mesh_header",sxmo_ogre_mesh_header_fields,SX_COUNT(sxmo_ogre_mesh_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_mesh_chunk_fields[] = {
    SX_FIELD("chunk_type","uint16",0,2,SX_ID),
    SX_FIELD("chunk_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxmo_ogre_mesh_chunk = {UINT32_C(0x6021001e),"ogre_mesh_chunk",sxmo_ogre_mesh_chunk_fields,SX_COUNT(sxmo_ogre_mesh_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_mesh_animation_fields[] = {
    SX_FIELD("skeletally_animated","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxmo_ogre_mesh_animation = {UINT32_C(0x6021001f),"ogre_mesh_animation",sxmo_ogre_mesh_animation_fields,SX_COUNT(sxmo_ogre_mesh_animation_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_submesh_fields[] = {
    SX_FIELD("use_shared_vertices","uint8",0,1,SX_FLAGS),
    SX_FIELD("index_count","uint32",1,4,SX_COUNT_PROP),
    SX_FIELD("indices_are_32bit","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxmo_ogre_submesh = {UINT32_C(0x60210020),"ogre_submesh",sxmo_ogre_submesh_fields,SX_COUNT(sxmo_ogre_submesh_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_index16_fields[] = {
    SX_FIELD("vertex_index","uint16",0,2,SX_ID),
};
static const sx_layout sxmo_ogre_index16 = {UINT32_C(0x60210021),"ogre_index16",sxmo_ogre_index16_fields,SX_COUNT(sxmo_ogre_index16_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_vertex_count_fields[] = {
    SX_FIELD("vertex_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_ogre_vertex_count = {UINT32_C(0x60210022),"ogre_vertex_count",sxmo_ogre_vertex_count_fields,SX_COUNT(sxmo_ogre_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_vertex_element_fields[] = {
    SX_FIELD("source","uint16",0,2,SX_ID),
    SX_FIELD("element_type","uint16",2,2,SX_ID),
    SX_FIELD("semantic","uint16",4,2,SX_ID),
    SX_FIELD("offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("semantic_index","uint16",8,2,SX_ID),
};
static const sx_layout sxmo_ogre_vertex_element = {UINT32_C(0x60210023),"ogre_vertex_element",sxmo_ogre_vertex_element_fields,SX_COUNT(sxmo_ogre_vertex_element_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_vertex_buffer_fields[] = {
    SX_FIELD("binding_index","uint16",0,2,SX_ID),
    SX_FIELD("vertex_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxmo_ogre_vertex_buffer = {UINT32_C(0x60210024),"ogre_vertex_buffer",sxmo_ogre_vertex_buffer_fields,SX_COUNT(sxmo_ogre_vertex_buffer_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_position_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxmo_ogre_position = {UINT32_C(0x60210025),"ogre_position",sxmo_ogre_position_fields,SX_COUNT(sxmo_ogre_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_operation_fields[] = {
    SX_FIELD("operation_type","uint16",0,2,SX_ID),
};
static const sx_layout sxmo_ogre_operation = {UINT32_C(0x60210026),"ogre_operation",sxmo_ogre_operation_fields,SX_COUNT(sxmo_ogre_operation_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_bounds_fields[] = {
    SX_FIELD("minimum","float32[3]",0,12,SX_NONE),
    SX_FIELD("maximum","float32[3]",12,12,SX_NONE),
    SX_FIELD("radius","float32",24,4,SX_NONE),
};
static const sx_layout sxmo_ogre_bounds = {UINT32_C(0x60210027),"ogre_bounds",sxmo_ogre_bounds_fields,SX_COUNT(sxmo_ogre_bounds_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_header_fields[] = {
    SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("pointer_size","char[1]",7,1,SX_ID),
    SX_FIELD("byte_order","char[1]",8,1,SX_ID),
    SX_FIELD("version","char[3]",9,3,SX_ID),
};
static const sx_layout sxmo_blend_header = {UINT32_C(0x60210028),"blend_header",sxmo_blend_header_fields,SX_COUNT(sxmo_blend_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_block32_le_fields[] = {
    SX_FIELD("code","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("old_pointer","uint32",8,4,SX_POINTER),
    SX_FIELD("dna_structure_index","int32",12,4,SX_ID),
    SX_FIELD("element_count","int32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_block32_le = {UINT32_C(0x60210029),"blend_block32_le",sxmo_blend_block32_le_fields,SX_COUNT(sxmo_blend_block32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_block64_le_fields[] = {
    SX_FIELD("code","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("old_pointer","uint64",8,8,SX_POINTER),
    SX_FIELD("dna_structure_index","int32",16,4,SX_ID),
    SX_FIELD("element_count","int32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_block64_le = {UINT32_C(0x6021002a),"blend_block64_le",sxmo_blend_block64_le_fields,SX_COUNT(sxmo_blend_block64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_names_le_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("names_tag","char[4]",4,4,SX_ID),
    SX_FIELD("name_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_dna_names_le = {UINT32_C(0x6021002b),"blend_dna_names_le",sxmo_blend_dna_names_le_fields,SX_COUNT(sxmo_blend_dna_names_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_types_le_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("type_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_dna_types_le = {UINT32_C(0x6021002c),"blend_dna_types_le",sxmo_blend_dna_types_le_fields,SX_COUNT(sxmo_blend_dna_types_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_structures_le_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("structure_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_dna_structures_le = {UINT32_C(0x6021002d),"blend_dna_structures_le",sxmo_blend_dna_structures_le_fields,SX_COUNT(sxmo_blend_dna_structures_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_lengths_tag_le_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
};
static const sx_layout sxmo_blend_dna_lengths_tag_le = {UINT32_C(0x6021002e),"blend_dna_lengths_tag_le",sxmo_blend_dna_lengths_tag_le_fields,SX_COUNT(sxmo_blend_dna_lengths_tag_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_type_size_le_fields[] = {
    SX_FIELD("type_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxmo_blend_dna_type_size_le = {UINT32_C(0x6021002f),"blend_dna_type_size_le",sxmo_blend_dna_type_size_le_fields,SX_COUNT(sxmo_blend_dna_type_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_structure_le_fields[] = {
    SX_FIELD("type_index","uint16",0,2,SX_ID),
    SX_FIELD("field_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_dna_structure_le = {UINT32_C(0x60210030),"blend_dna_structure_le",sxmo_blend_dna_structure_le_fields,SX_COUNT(sxmo_blend_dna_structure_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_dna_field_le_fields[] = {
    SX_FIELD("type_index","uint16",0,2,SX_ID),
    SX_FIELD("name_index","uint16",2,2,SX_ID),
};
static const sx_layout sxmo_blend_dna_field_le = {UINT32_C(0x60210031),"blend_dna_field_le",sxmo_blend_dna_field_le_fields,SX_COUNT(sxmo_blend_dna_field_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_blend_block32_be_fields[] = {
    SX_FIELD("code","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("old_pointer","uint32",8,4,SX_POINTER),
    SX_FIELD("dna_structure_index","int32",12,4,SX_ID),
    SX_FIELD("element_count","int32",16,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_block32_be = {UINT32_C(0x60210032),"blend_block32_be",sxmo_blend_block32_be_fields,SX_COUNT(sxmo_blend_block32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_block64_be_fields[] = {
    SX_FIELD("code","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("old_pointer","uint64",8,8,SX_POINTER),
    SX_FIELD("dna_structure_index","int32",16,4,SX_ID),
    SX_FIELD("element_count","int32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_block64_be = {UINT32_C(0x60210033),"blend_block64_be",sxmo_blend_block64_be_fields,SX_COUNT(sxmo_blend_block64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_names_be_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("names_tag","char[4]",4,4,SX_ID),
    SX_FIELD("name_count","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_dna_names_be = {UINT32_C(0x60210034),"blend_dna_names_be",sxmo_blend_dna_names_be_fields,SX_COUNT(sxmo_blend_dna_names_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_types_be_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("type_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_dna_types_be = {UINT32_C(0x60210035),"blend_dna_types_be",sxmo_blend_dna_types_be_fields,SX_COUNT(sxmo_blend_dna_types_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_structures_be_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
    SX_FIELD("structure_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_dna_structures_be = {UINT32_C(0x60210036),"blend_dna_structures_be",sxmo_blend_dna_structures_be_fields,SX_COUNT(sxmo_blend_dna_structures_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_lengths_tag_be_fields[] = {
    SX_FIELD("tag","char[4]",0,4,SX_ID),
};
static const sx_layout sxmo_blend_dna_lengths_tag_be = {UINT32_C(0x60210037),"blend_dna_lengths_tag_be",sxmo_blend_dna_lengths_tag_be_fields,SX_COUNT(sxmo_blend_dna_lengths_tag_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_type_size_be_fields[] = {
    SX_FIELD("type_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxmo_blend_dna_type_size_be = {UINT32_C(0x60210038),"blend_dna_type_size_be",sxmo_blend_dna_type_size_be_fields,SX_COUNT(sxmo_blend_dna_type_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_structure_be_fields[] = {
    SX_FIELD("type_index","uint16",0,2,SX_ID),
    SX_FIELD("field_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_blend_dna_structure_be = {UINT32_C(0x60210039),"blend_dna_structure_be",sxmo_blend_dna_structure_be_fields,SX_COUNT(sxmo_blend_dna_structure_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_blend_dna_field_be_fields[] = {
    SX_FIELD("type_index","uint16",0,2,SX_ID),
    SX_FIELD("name_index","uint16",2,2,SX_ID),
};
static const sx_layout sxmo_blend_dna_field_be = {UINT32_C(0x6021003a),"blend_dna_field_be",sxmo_blend_dna_field_be_fields,SX_COUNT(sxmo_blend_dna_field_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_fbx_header_fields[] = {
    SX_FIELD("signature","char[23]",0,23,SX_SIGNATURE),
    SX_FIELD("version","uint32",23,4,SX_ID),
};
static const sx_layout sxmo_fbx_header = {UINT32_C(0x6021003b),"fbx_header",sxmo_fbx_header_fields,SX_COUNT(sxmo_fbx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_node32_fields[] = {
    SX_FIELD("end_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("property_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("property_list_size","uint32",8,4,SX_SIZE),
    SX_FIELD("name_size","uint8",12,1,SX_SIZE),
};
static const sx_layout sxmo_fbx_node32 = {UINT32_C(0x6021003c),"fbx_node32",sxmo_fbx_node32_fields,SX_COUNT(sxmo_fbx_node32_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_node64_fields[] = {
    SX_FIELD("end_offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("property_count","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("property_list_size","uint64",16,8,SX_SIZE),
    SX_FIELD("name_size","uint8",24,1,SX_SIZE),
};
static const sx_layout sxmo_fbx_node64 = {UINT32_C(0x6021003d),"fbx_node64",sxmo_fbx_node64_fields,SX_COUNT(sxmo_fbx_node64_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_y_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","int16",1,2,SX_NONE),
};
static const sx_layout sxmo_fbx_scalar_y = {UINT32_C(0x6021003e),"fbx_scalar_y",sxmo_fbx_scalar_y_fields,SX_COUNT(sxmo_fbx_scalar_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_c_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","uint8",1,1,SX_NONE),
};
static const sx_layout sxmo_fbx_scalar_c = {UINT32_C(0x6021003f),"fbx_scalar_c",sxmo_fbx_scalar_c_fields,SX_COUNT(sxmo_fbx_scalar_c_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_i_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","int32",1,4,SX_NONE),
};
static const sx_layout sxmo_fbx_scalar_i = {UINT32_C(0x60210040),"fbx_scalar_i",sxmo_fbx_scalar_i_fields,SX_COUNT(sxmo_fbx_scalar_i_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_f_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","float32",1,4,SX_NONE),
};
static const sx_layout sxmo_fbx_scalar_f = {UINT32_C(0x60210041),"fbx_scalar_f",sxmo_fbx_scalar_f_fields,SX_COUNT(sxmo_fbx_scalar_f_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_l_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","int64",1,8,SX_NONE),
};
static const sx_layout sxmo_fbx_scalar_l = {UINT32_C(0x60210042),"fbx_scalar_l",sxmo_fbx_scalar_l_fields,SX_COUNT(sxmo_fbx_scalar_l_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_scalar_d_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("value","float64",1,8,SX_NONE),
};
static const sx_layout sxmo_fbx_scalar_d = {UINT32_C(0x60210043),"fbx_scalar_d",sxmo_fbx_scalar_d_fields,SX_COUNT(sxmo_fbx_scalar_d_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_blob_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("data_size","uint32",1,4,SX_SIZE),
};
static const sx_layout sxmo_fbx_blob = {UINT32_C(0x60210044),"fbx_blob",sxmo_fbx_blob_fields,SX_COUNT(sxmo_fbx_blob_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_array_fields[] = {
    SX_FIELD("type","char[1]",0,1,SX_ID),
    SX_FIELD("element_count","uint32",1,4,SX_COUNT_PROP),
    SX_FIELD("encoding","uint32",5,4,SX_ID),
    SX_FIELD("stored_size","uint32",9,4,SX_SIZE),
};
static const sx_layout sxmo_fbx_array = {UINT32_C(0x60210045),"fbx_array",sxmo_fbx_array_fields,SX_COUNT(sxmo_fbx_array_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_footer_prefix_fields[] = {
    SX_FIELD("identifier","uint8[16]",0,16,SX_NONE),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
static const sx_layout sxmo_fbx_footer_prefix = {UINT32_C(0x60210046),"fbx_footer_prefix",sxmo_fbx_footer_prefix_fields,SX_COUNT(sxmo_fbx_footer_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_fbx_footer_tail_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("reserved","uint8[120]",4,120,SX_RESERVED),
    SX_FIELD("signature","uint8[16]",124,16,SX_SIGNATURE),
};
static const sx_layout sxmo_fbx_footer_tail = {UINT32_C(0x60210047),"fbx_footer_tail",sxmo_fbx_footer_tail_fields,SX_COUNT(sxmo_fbx_footer_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_chunk_fields[] = {
    SX_FIELD("chunk_type","uint16",0,2,SX_ID),
    SX_FIELD("chunk_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxmo_3ds_chunk = {UINT32_C(0x60210048),"3ds_chunk",sxmo_3ds_chunk_fields,SX_COUNT(sxmo_3ds_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_version_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
};
static const sx_layout sxmo_3ds_version = {UINT32_C(0x60210049),"3ds_version",sxmo_3ds_version_fields,SX_COUNT(sxmo_3ds_version_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_vertex_count_fields[] = {
    SX_FIELD("vertex_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_3ds_vertex_count = {UINT32_C(0x6021004a),"3ds_vertex_count",sxmo_3ds_vertex_count_fields,SX_COUNT(sxmo_3ds_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_face_count_fields[] = {
    SX_FIELD("face_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_3ds_face_count = {UINT32_C(0x6021004b),"3ds_face_count",sxmo_3ds_face_count_fields,SX_COUNT(sxmo_3ds_face_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_uv_count_fields[] = {
    SX_FIELD("uv_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmo_3ds_uv_count = {UINT32_C(0x6021004c),"3ds_uv_count",sxmo_3ds_uv_count_fields,SX_COUNT(sxmo_3ds_uv_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_vertex_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxmo_3ds_vertex = {UINT32_C(0x6021004d),"3ds_vertex",sxmo_3ds_vertex_fields,SX_COUNT(sxmo_3ds_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_uv_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
};
static const sx_layout sxmo_3ds_uv = {UINT32_C(0x6021004e),"3ds_uv",sxmo_3ds_uv_fields,SX_COUNT(sxmo_3ds_uv_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_face_fields[] = {
    SX_FIELD("vertex0","uint16",0,2,SX_ID),
    SX_FIELD("vertex1","uint16",2,2,SX_ID),
    SX_FIELD("vertex2","uint16",4,2,SX_ID),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
};
static const sx_layout sxmo_3ds_face = {UINT32_C(0x6021004f),"3ds_face",sxmo_3ds_face_fields,SX_COUNT(sxmo_3ds_face_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_local_matrix_fields[] = {
    SX_FIELD("x_axis","float32[3]",0,12,SX_NONE),
    SX_FIELD("y_axis","float32[3]",12,12,SX_NONE),
    SX_FIELD("z_axis","float32[3]",24,12,SX_NONE),
    SX_FIELD("origin","float32[3]",36,12,SX_NONE),
};
static const sx_layout sxmo_3ds_local_matrix = {UINT32_C(0x60210050),"3ds_local_matrix",sxmo_3ds_local_matrix_fields,SX_COUNT(sxmo_3ds_local_matrix_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_lwo2_form_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxmo_lwo2_form = {UINT32_C(0x60210051),"lwo2_form",sxmo_lwo2_form_fields,SX_COUNT(sxmo_lwo2_form_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_chunk_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmo_lwo2_chunk = {UINT32_C(0x60210052),"lwo2_chunk",sxmo_lwo2_chunk_fields,SX_COUNT(sxmo_lwo2_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_layer_fields[] = {
    SX_FIELD("number","uint16",0,2,SX_ID),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("pivot","float32[3]",4,12,SX_NONE),
};
static const sx_layout sxmo_lwo2_layer = {UINT32_C(0x60210053),"lwo2_layer",sxmo_lwo2_layer_fields,SX_COUNT(sxmo_lwo2_layer_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_point_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxmo_lwo2_point = {UINT32_C(0x60210054),"lwo2_point",sxmo_lwo2_point_fields,SX_COUNT(sxmo_lwo2_point_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_polygon_type_fields[] = {
    SX_FIELD("polygon_type","char[4]",0,4,SX_ID),
};
static const sx_layout sxmo_lwo2_polygon_type = {UINT32_C(0x60210055),"lwo2_polygon_type",sxmo_lwo2_polygon_type_fields,SX_COUNT(sxmo_lwo2_polygon_type_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_tag_type_fields[] = {
    SX_FIELD("tag_type","char[4]",0,4,SX_ID),
};
static const sx_layout sxmo_lwo2_tag_type = {UINT32_C(0x60210056),"lwo2_tag_type",sxmo_lwo2_tag_type_fields,SX_COUNT(sxmo_lwo2_tag_type_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_polygon_fields[] = {
    SX_FIELD("count_and_flags","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxmo_lwo2_polygon = {UINT32_C(0x60210057),"lwo2_polygon",sxmo_lwo2_polygon_fields,SX_COUNT(sxmo_lwo2_polygon_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_index16_fields[] = {
    SX_FIELD("index","uint16",0,2,SX_ID),
};
static const sx_layout sxmo_lwo2_index16 = {UINT32_C(0x60210058),"lwo2_index16",sxmo_lwo2_index16_fields,SX_COUNT(sxmo_lwo2_index16_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_index24_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("index","uint24",1,3,SX_ID),
};
static const sx_layout sxmo_lwo2_index24 = {UINT32_C(0x60210059),"lwo2_index24",sxmo_lwo2_index24_fields,SX_COUNT(sxmo_lwo2_index24_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_lwo2_tag_index_fields[] = {
    SX_FIELD("tag_index","uint16",0,2,SX_ID),
};
static const sx_layout sxmo_lwo2_tag_index = {UINT32_C(0x6021005a),"lwo2_tag_index",sxmo_lwo2_tag_index_fields,SX_COUNT(sxmo_lwo2_tag_index_fields),SX_BE};
static const xx_data_struct_field_desc sxmo_s3o_header_fields[] = {
    SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
    SX_FIELD("version","int32",12,4,SX_ID),
    SX_FIELD("radius","float32",16,4,SX_NONE),
    SX_FIELD("height","float32",20,4,SX_NONE),
    SX_FIELD("midpoint","float32[3]",24,12,SX_NONE),
    SX_FIELD("root_piece_offset","int32",36,4,SX_OFFSET),
    SX_FIELD("collision_data_offset","int32",40,4,SX_OFFSET),
    SX_FIELD("texture1_offset","int32",44,4,SX_OFFSET),
    SX_FIELD("texture2_offset","int32",48,4,SX_OFFSET),
};
static const sx_layout sxmo_s3o_header = {UINT32_C(0x6021005b),"s3o_header",sxmo_s3o_header_fields,SX_COUNT(sxmo_s3o_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_s3o_piece_fields[] = {
    SX_FIELD("name_offset","int32",0,4,SX_OFFSET),
    SX_FIELD("child_count","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("children_offset","int32",8,4,SX_OFFSET),
    SX_FIELD("vertex_count","int32",12,4,SX_COUNT_PROP),
    SX_FIELD("vertices_offset","int32",16,4,SX_OFFSET),
    SX_FIELD("vertex_type","int32",20,4,SX_ID),
    SX_FIELD("primitive_type","int32",24,4,SX_ID),
    SX_FIELD("index_count","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("indices_offset","int32",32,4,SX_OFFSET),
    SX_FIELD("collision_data_offset","int32",36,4,SX_OFFSET),
    SX_FIELD("offset","float32[3]",40,12,SX_NONE),
};
static const sx_layout sxmo_s3o_piece = {UINT32_C(0x6021005c),"s3o_piece",sxmo_s3o_piece_fields,SX_COUNT(sxmo_s3o_piece_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_s3o_vertex_fields[] = {
    SX_FIELD("position","float32[3]",0,12,SX_NONE),
    SX_FIELD("normal","float32[3]",12,12,SX_NONE),
    SX_FIELD("u","float32",24,4,SX_NONE),
    SX_FIELD("v","float32",28,4,SX_NONE),
};
static const sx_layout sxmo_s3o_vertex = {UINT32_C(0x6021005d),"s3o_vertex",sxmo_s3o_vertex_fields,SX_COUNT(sxmo_s3o_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_s3o_child_fields[] = {
    SX_FIELD("piece_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxmo_s3o_child = {UINT32_C(0x6021005e),"s3o_child",sxmo_s3o_child_fields,SX_COUNT(sxmo_s3o_child_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_s3o_index_fields[] = {
    SX_FIELD("vertex_index","int32",0,4,SX_ID),
};
static const sx_layout sxmo_s3o_index = {UINT32_C(0x6021005f),"s3o_index",sxmo_s3o_index_fields,SX_COUNT(sxmo_s3o_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_stl_binary_header_fields[] = {
    SX_FIELD("header","uint8[80]",0,80,SX_NONE),
    SX_FIELD("facet_count","uint32",80,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_stl_binary_header = {UINT32_C(0x60210060),"stl_binary_header",sxmo_stl_binary_header_fields,SX_COUNT(sxmo_stl_binary_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_stl_binary_facet_fields[] = {
    SX_FIELD("normal","float32[3]",0,12,SX_NONE),
    SX_FIELD("vertex0","float32[3]",12,12,SX_NONE),
    SX_FIELD("vertex1","float32[3]",24,12,SX_NONE),
    SX_FIELD("vertex2","float32[3]",36,12,SX_NONE),
    SX_FIELD("attribute_byte_count","uint16",48,2,SX_SIZE),
};
static const sx_layout sxmo_stl_binary_facet = {UINT32_C(0x60210061),"stl_binary_facet",sxmo_stl_binary_facet_fields,SX_COUNT(sxmo_stl_binary_facet_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("compression_method","char[4]",8,4,SX_ID),
    SX_FIELD("vertex_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("triangle_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("uv_map_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("attribute_map_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",28,4,SX_FLAGS),
};
static const sx_layout sxmo_openctm_header = {UINT32_C(0x60210062),"openctm_header",sxmo_openctm_header_fields,SX_COUNT(sxmo_openctm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_string_length_fields[] = {
    SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmo_openctm_string_length = {UINT32_C(0x60210063),"openctm_string_length",sxmo_openctm_string_length_fields,SX_COUNT(sxmo_openctm_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_tag_fields[] = {
    SX_FIELD("section","char[4]",0,4,SX_ID),
};
static const sx_layout sxmo_openctm_tag = {UINT32_C(0x60210064),"openctm_tag",sxmo_openctm_tag_fields,SX_COUNT(sxmo_openctm_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_triangle_fields[] = {
    SX_FIELD("vertex0","uint32",0,4,SX_ID),
    SX_FIELD("vertex1","uint32",4,4,SX_ID),
    SX_FIELD("vertex2","uint32",8,4,SX_ID),
};
static const sx_layout sxmo_openctm_triangle = {UINT32_C(0x60210065),"openctm_triangle",sxmo_openctm_triangle_fields,SX_COUNT(sxmo_openctm_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_vertex_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxmo_openctm_vertex = {UINT32_C(0x60210066),"openctm_vertex",sxmo_openctm_vertex_fields,SX_COUNT(sxmo_openctm_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_normal_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxmo_openctm_normal = {UINT32_C(0x60210067),"openctm_normal",sxmo_openctm_normal_fields,SX_COUNT(sxmo_openctm_normal_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_uv_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
};
static const sx_layout sxmo_openctm_uv = {UINT32_C(0x60210068),"openctm_uv",sxmo_openctm_uv_fields,SX_COUNT(sxmo_openctm_uv_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_attribute_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
    SX_FIELD("w","float32",12,4,SX_NONE),
};
static const sx_layout sxmo_openctm_attribute = {UINT32_C(0x60210069),"openctm_attribute",sxmo_openctm_attribute_fields,SX_COUNT(sxmo_openctm_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_header_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("color_format","uint32",4,4,SX_ID),
    SX_FIELD("z_axis_orientation","uint32",8,4,SX_ID),
    SX_FIELD("compressed","uint32",12,4,SX_FLAGS),
    SX_FIELD("visibility_mask_encoded","uint32",16,4,SX_FLAGS),
    SX_FIELD("matrix_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_qb_header = {UINT32_C(0x6021006a),"qb_header",sxmo_qb_header_fields,SX_COUNT(sxmo_qb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_name_length_fields[] = {
    SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxmo_qb_name_length = {UINT32_C(0x6021006b),"qb_name_length",sxmo_qb_name_length_fields,SX_COUNT(sxmo_qb_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_matrix_fields[] = {
    SX_FIELD("size_x","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("size_y","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("size_z","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("position_x","int32",12,4,SX_NONE),
    SX_FIELD("position_y","int32",16,4,SX_NONE),
    SX_FIELD("position_z","int32",20,4,SX_NONE),
};
static const sx_layout sxmo_qb_matrix = {UINT32_C(0x6021006c),"qb_matrix",sxmo_qb_matrix_fields,SX_COUNT(sxmo_qb_matrix_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_voxel_fields[] = {
    SX_FIELD("encoded_color","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmo_qb_voxel = {UINT32_C(0x6021006d),"qb_voxel",sxmo_qb_voxel_fields,SX_COUNT(sxmo_qb_voxel_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_rle_marker_fields[] = {
    SX_FIELD("marker","uint32",0,4,SX_ID),
};
static const sx_layout sxmo_qb_rle_marker = {UINT32_C(0x6021006e),"qb_rle_marker",sxmo_qb_rle_marker_fields,SX_COUNT(sxmo_qb_rle_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_qb_rle_run_fields[] = {
    SX_FIELD("voxel_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("encoded_color","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxmo_qb_rle_run = {UINT32_C(0x6021006f),"qb_rle_run",sxmo_qb_rle_run_fields,SX_COUNT(sxmo_qb_rle_run_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
};
static const sx_layout sxmo_ter_header = {UINT32_C(0x60210070),"ter_header",sxmo_ter_header_fields,SX_COUNT(sxmo_ter_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_end_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
};
static const sx_layout sxmo_ter_end = {UINT32_C(0x60210071),"ter_end",sxmo_ter_end_fields,SX_COUNT(sxmo_ter_end_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_size_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("size_minus_one","uint16",4,2,SX_NONE),
    SX_FIELD("padding","uint16",6,2,SX_RESERVED),
};
static const sx_layout sxmo_ter_size = {UINT32_C(0x60210072),"ter_size",sxmo_ter_size_fields,SX_COUNT(sxmo_ter_size_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_point_count_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("point_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("padding","uint16",6,2,SX_RESERVED),
};
static const sx_layout sxmo_ter_point_count = {UINT32_C(0x60210073),"ter_point_count",sxmo_ter_point_count_fields,SX_COUNT(sxmo_ter_point_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_scale_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("x","float32",4,4,SX_NONE),
    SX_FIELD("y","float32",8,4,SX_NONE),
    SX_FIELD("z","float32",12,4,SX_NONE),
};
static const sx_layout sxmo_ter_scale = {UINT32_C(0x60210074),"ter_scale",sxmo_ter_scale_fields,SX_COUNT(sxmo_ter_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_radius_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("radius","float32",4,4,SX_NONE),
};
static const sx_layout sxmo_ter_radius = {UINT32_C(0x60210075),"ter_radius",sxmo_ter_radius_fields,SX_COUNT(sxmo_ter_radius_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_curvature_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("mode","uint32",4,4,SX_ID),
};
static const sx_layout sxmo_ter_curvature = {UINT32_C(0x60210076),"ter_curvature",sxmo_ter_curvature_fields,SX_COUNT(sxmo_ter_curvature_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_altitude_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("height_scale","int16",4,2,SX_NONE),
    SX_FIELD("base_height","int16",6,2,SX_NONE),
};
static const sx_layout sxmo_ter_altitude = {UINT32_C(0x60210077),"ter_altitude",sxmo_ter_altitude_fields,SX_COUNT(sxmo_ter_altitude_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ter_height_fields[] = {
    SX_FIELD("height_sample","int16",0,2,SX_NONE),
};
static const sx_layout sxmo_ter_height = {UINT32_C(0x60210078),"ter_height",sxmo_ter_height_fields,SX_COUNT(sxmo_ter_height_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx20_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","float32",4,4,SX_ID),
    SX_FIELD("globals_size","uint8",8,1,SX_SIZE),
    SX_FIELD("encoding","uint8",9,1,SX_ID),
    SX_FIELD("additional_uv_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("vertex_index_size","uint8",11,1,SX_SIZE),
    SX_FIELD("texture_index_size","uint8",12,1,SX_SIZE),
    SX_FIELD("material_index_size","uint8",13,1,SX_SIZE),
    SX_FIELD("bone_index_size","uint8",14,1,SX_SIZE),
    SX_FIELD("morph_index_size","uint8",15,1,SX_SIZE),
    SX_FIELD("rigid_body_index_size","uint8",16,1,SX_SIZE),
};
static const sx_layout sxmo_pmx20_header = {UINT32_C(0x60210079),"pmx20_header",sxmo_pmx20_header_fields,SX_COUNT(sxmo_pmx20_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_text_length_fields[] = {
    SX_FIELD("byte_length","int32",0,4,SX_SIZE),
};
static const sx_layout sxmo_pmx_text_length = {UINT32_C(0x6021007a),"pmx_text_length",sxmo_pmx_text_length_fields,SX_COUNT(sxmo_pmx_text_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_count_fields[] = {
    SX_FIELD("vertex_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_pmx_vertex_count = {UINT32_C(0x6021007b),"pmx_vertex_count",sxmo_pmx_vertex_count_fields,SX_COUNT(sxmo_pmx_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_face_index_count_fields[] = {
    SX_FIELD("face_index_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_pmx_face_index_count = {UINT32_C(0x6021007c),"pmx_face_index_count",sxmo_pmx_face_index_count_fields,SX_COUNT(sxmo_pmx_face_index_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_texture_count_fields[] = {
    SX_FIELD("texture_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_pmx_texture_count = {UINT32_C(0x6021007d),"pmx_texture_count",sxmo_pmx_texture_count_fields,SX_COUNT(sxmo_pmx_texture_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_fields[] = {
    SX_FIELD("position","float32[3]",0,12,SX_NONE),
    SX_FIELD("normal","float32[3]",12,12,SX_NONE),
    SX_FIELD("u","float32",24,4,SX_NONE),
    SX_FIELD("v","float32",28,4,SX_NONE),
};
static const sx_layout sxmo_pmx_vertex = {UINT32_C(0x6021007e),"pmx_vertex",sxmo_pmx_vertex_fields,SX_COUNT(sxmo_pmx_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_additional_uv_fields[] = {
    SX_FIELD("coordinates","float32[4]",0,16,SX_NONE),
};
static const sx_layout sxmo_pmx_additional_uv = {UINT32_C(0x6021007f),"pmx_additional_uv",sxmo_pmx_additional_uv_fields,SX_COUNT(sxmo_pmx_additional_uv_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_skinning_fields[] = {
    SX_FIELD("deform_type","uint8",0,1,SX_ID),
};
static const sx_layout sxmo_pmx_skinning = {UINT32_C(0x60210080),"pmx_skinning",sxmo_pmx_skinning_fields,SX_COUNT(sxmo_pmx_skinning_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_bone_index1_fields[] = {
    SX_FIELD("bone_index","int8",0,1,SX_ID),
};
static const sx_layout sxmo_pmx_bone_index1 = {UINT32_C(0x60210081),"pmx_bone_index1",sxmo_pmx_bone_index1_fields,SX_COUNT(sxmo_pmx_bone_index1_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_index1_fields[] = {
    SX_FIELD("vertex_index","uint8",0,1,SX_ID),
};
static const sx_layout sxmo_pmx_vertex_index1 = {UINT32_C(0x60210082),"pmx_vertex_index1",sxmo_pmx_vertex_index1_fields,SX_COUNT(sxmo_pmx_vertex_index1_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_bone_index2_fields[] = {
    SX_FIELD("bone_index","int16",0,2,SX_ID),
};
static const sx_layout sxmo_pmx_bone_index2 = {UINT32_C(0x60210083),"pmx_bone_index2",sxmo_pmx_bone_index2_fields,SX_COUNT(sxmo_pmx_bone_index2_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_index2_fields[] = {
    SX_FIELD("vertex_index","uint16",0,2,SX_ID),
};
static const sx_layout sxmo_pmx_vertex_index2 = {UINT32_C(0x60210084),"pmx_vertex_index2",sxmo_pmx_vertex_index2_fields,SX_COUNT(sxmo_pmx_vertex_index2_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_bone_index4_fields[] = {
    SX_FIELD("bone_index","int32",0,4,SX_ID),
};
static const sx_layout sxmo_pmx_bone_index4 = {UINT32_C(0x60210085),"pmx_bone_index4",sxmo_pmx_bone_index4_fields,SX_COUNT(sxmo_pmx_bone_index4_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_vertex_index4_fields[] = {
    SX_FIELD("vertex_index","uint32",0,4,SX_ID),
};
static const sx_layout sxmo_pmx_vertex_index4 = {UINT32_C(0x60210086),"pmx_vertex_index4",sxmo_pmx_vertex_index4_fields,SX_COUNT(sxmo_pmx_vertex_index4_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_weight_fields[] = {
    SX_FIELD("weight","float32",0,4,SX_NONE),
};
static const sx_layout sxmo_pmx_weight = {UINT32_C(0x60210087),"pmx_weight",sxmo_pmx_weight_fields,SX_COUNT(sxmo_pmx_weight_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_edge_scale_fields[] = {
    SX_FIELD("edge_scale","float32",0,4,SX_NONE),
};
static const sx_layout sxmo_pmx_edge_scale = {UINT32_C(0x60210088),"pmx_edge_scale",sxmo_pmx_edge_scale_fields,SX_COUNT(sxmo_pmx_edge_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_sdef_fields[] = {
    SX_FIELD("c","float32[3]",0,12,SX_NONE),
    SX_FIELD("r0","float32[3]",12,12,SX_NONE),
    SX_FIELD("r1","float32[3]",24,12,SX_NONE),
};
static const sx_layout sxmo_pmx_sdef = {UINT32_C(0x60210089),"pmx_sdef",sxmo_pmx_sdef_fields,SX_COUNT(sxmo_pmx_sdef_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_pmx_material_count_fields[] = {
    SX_FIELD("material_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_pmx_material_count = {UINT32_C(0x6021008a),"pmx_material_count",sxmo_pmx_material_count_fields,SX_COUNT(sxmo_pmx_material_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("serializer_version","char[19]",2,19,SX_STRING),
};
static const sx_layout sxmo_ogre_skeleton_header = {UINT32_C(0x6021008b),"ogre_skeleton_header",sxmo_ogre_skeleton_header_fields,SX_COUNT(sxmo_ogre_skeleton_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_chunk_fields[] = {
    SX_FIELD("chunk_type","uint16",0,2,SX_ID),
    SX_FIELD("chunk_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxmo_ogre_skeleton_chunk = {UINT32_C(0x6021008c),"ogre_skeleton_chunk",sxmo_ogre_skeleton_chunk_fields,SX_COUNT(sxmo_ogre_skeleton_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_bone_chunk_fields[] = {
    SX_FIELD("chunk_type","uint16",0,2,SX_ID),
    SX_FIELD("fixed_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxmo_ogre_skeleton_bone_chunk = {UINT32_C(0x6021008d),"ogre_skeleton_bone_chunk",sxmo_ogre_skeleton_bone_chunk_fields,SX_COUNT(sxmo_ogre_skeleton_bone_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_bone_fields[] = {
    SX_FIELD("handle","uint16",0,2,SX_ID),
    SX_FIELD("position","float32[3]",2,12,SX_NONE),
    SX_FIELD("orientation_xyzw","float32[4]",14,16,SX_NONE),
};
static const sx_layout sxmo_ogre_skeleton_bone = {UINT32_C(0x6021008e),"ogre_skeleton_bone",sxmo_ogre_skeleton_bone_fields,SX_COUNT(sxmo_ogre_skeleton_bone_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_scale_fields[] = {
    SX_FIELD("scale","float32[3]",0,12,SX_NONE),
};
static const sx_layout sxmo_ogre_skeleton_scale = {UINT32_C(0x6021008f),"ogre_skeleton_scale",sxmo_ogre_skeleton_scale_fields,SX_COUNT(sxmo_ogre_skeleton_scale_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_parent_fields[] = {
    SX_FIELD("child","uint16",0,2,SX_ID),
    SX_FIELD("parent","uint16",2,2,SX_ID),
};
static const sx_layout sxmo_ogre_skeleton_parent = {UINT32_C(0x60210090),"ogre_skeleton_parent",sxmo_ogre_skeleton_parent_fields,SX_COUNT(sxmo_ogre_skeleton_parent_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_blend_fields[] = {
    SX_FIELD("blend_mode","uint16",0,2,SX_ID),
};
static const sx_layout sxmo_ogre_skeleton_blend = {UINT32_C(0x60210091),"ogre_skeleton_blend",sxmo_ogre_skeleton_blend_fields,SX_COUNT(sxmo_ogre_skeleton_blend_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_duration_fields[] = {
    SX_FIELD("duration","float32",0,4,SX_NONE),
};
static const sx_layout sxmo_ogre_skeleton_duration = {UINT32_C(0x60210092),"ogre_skeleton_duration",sxmo_ogre_skeleton_duration_fields,SX_COUNT(sxmo_ogre_skeleton_duration_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_track_fields[] = {
    SX_FIELD("bone_handle","uint16",0,2,SX_ID),
};
static const sx_layout sxmo_ogre_skeleton_track = {UINT32_C(0x60210093),"ogre_skeleton_track",sxmo_ogre_skeleton_track_fields,SX_COUNT(sxmo_ogre_skeleton_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_skeleton_keyframe_fields[] = {
    SX_FIELD("time","float32",0,4,SX_NONE),
    SX_FIELD("rotation_xyzw","float32[4]",4,16,SX_NONE),
    SX_FIELD("translation","float32[3]",20,12,SX_NONE),
};
static const sx_layout sxmo_ogre_skeleton_keyframe = {UINT32_C(0x60210094),"ogre_skeleton_keyframe",sxmo_ogre_skeleton_keyframe_fields,SX_COUNT(sxmo_ogre_skeleton_keyframe_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_cal3d_skeleton_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","int32",4,4,SX_ID),
    SX_FIELD("bone_count","int32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_cal3d_skeleton_header = {UINT32_C(0x60210095),"cal3d_skeleton_header",sxmo_cal3d_skeleton_header_fields,SX_COUNT(sxmo_cal3d_skeleton_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_cal3d_bone_name_fields[] = {
    SX_FIELD("name_size","int32",0,4,SX_SIZE),
};
static const sx_layout sxmo_cal3d_bone_name = {UINT32_C(0x60210096),"cal3d_bone_name",sxmo_cal3d_bone_name_fields,SX_COUNT(sxmo_cal3d_bone_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_cal3d_bone_fields[] = {
    SX_FIELD("local_translation","float32[3]",0,12,SX_NONE),
    SX_FIELD("local_rotation_xyzw","float32[4]",12,16,SX_NONE),
    SX_FIELD("bone_space_translation","float32[3]",28,12,SX_NONE),
    SX_FIELD("bone_space_rotation_xyzw","float32[4]",40,16,SX_NONE),
    SX_FIELD("parent_index","int32",56,4,SX_ID),
    SX_FIELD("child_count","int32",60,4,SX_COUNT_PROP),
};
static const sx_layout sxmo_cal3d_bone = {UINT32_C(0x60210097),"cal3d_bone",sxmo_cal3d_bone_fields,SX_COUNT(sxmo_cal3d_bone_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_cal3d_child_fields[] = {
    SX_FIELD("bone_index","int32",0,4,SX_ID),
};
static const sx_layout sxmo_cal3d_child = {UINT32_C(0x60210098),"cal3d_child",sxmo_cal3d_child_fields,SX_COUNT(sxmo_cal3d_child_fields),SX_LE};
static const sx_layout *const sx_modelmeta_layouts[] = {
    &sxmo_b3d_header,
    &sxmo_b3d_chunk,
    &sxmo_b3d_texture,
    &sxmo_b3d_brush_count,
    &sxmo_b3d_texture_index,
    &sxmo_b3d_brush,
    &sxmo_b3d_node,
    &sxmo_b3d_brush_index,
    &sxmo_b3d_vertices,
    &sxmo_b3d_position,
    &sxmo_b3d_normal,
    &sxmo_b3d_color,
    &sxmo_b3d_texture_coordinate,
    &sxmo_b3d_triangle,
    &sxmo_ms3d_header,
    &sxmo_ms3d_vertex_count,
    &sxmo_ms3d_triangle_count,
    &sxmo_ms3d_group_count,
    &sxmo_ms3d_material_count,
    &sxmo_ms3d_vertex,
    &sxmo_ms3d_triangle,
    &sxmo_ms3d_group,
    &sxmo_ms3d_triangle_index,
    &sxmo_ms3d_material_index,
    &sxmo_ms3d_material,
    &sxmo_ms3d_animation,
    &sxmo_bch21_header,
    &sxmo_bch_relocation,
    &sxmo_ogre_mesh_header,
    &sxmo_ogre_mesh_chunk,
    &sxmo_ogre_mesh_animation,
    &sxmo_ogre_submesh,
    &sxmo_ogre_index16,
    &sxmo_ogre_vertex_count,
    &sxmo_ogre_vertex_element,
    &sxmo_ogre_vertex_buffer,
    &sxmo_ogre_position,
    &sxmo_ogre_operation,
    &sxmo_ogre_bounds,
    &sxmo_blend_header,
    &sxmo_blend_block32_le,
    &sxmo_blend_block64_le,
    &sxmo_blend_dna_names_le,
    &sxmo_blend_dna_types_le,
    &sxmo_blend_dna_structures_le,
    &sxmo_blend_dna_lengths_tag_le,
    &sxmo_blend_dna_type_size_le,
    &sxmo_blend_dna_structure_le,
    &sxmo_blend_dna_field_le,
    &sxmo_blend_block32_be,
    &sxmo_blend_block64_be,
    &sxmo_blend_dna_names_be,
    &sxmo_blend_dna_types_be,
    &sxmo_blend_dna_structures_be,
    &sxmo_blend_dna_lengths_tag_be,
    &sxmo_blend_dna_type_size_be,
    &sxmo_blend_dna_structure_be,
    &sxmo_blend_dna_field_be,
    &sxmo_fbx_header,
    &sxmo_fbx_node32,
    &sxmo_fbx_node64,
    &sxmo_fbx_scalar_y,
    &sxmo_fbx_scalar_c,
    &sxmo_fbx_scalar_i,
    &sxmo_fbx_scalar_f,
    &sxmo_fbx_scalar_l,
    &sxmo_fbx_scalar_d,
    &sxmo_fbx_blob,
    &sxmo_fbx_array,
    &sxmo_fbx_footer_prefix,
    &sxmo_fbx_footer_tail,
    &sxmo_3ds_chunk,
    &sxmo_3ds_version,
    &sxmo_3ds_vertex_count,
    &sxmo_3ds_face_count,
    &sxmo_3ds_uv_count,
    &sxmo_3ds_vertex,
    &sxmo_3ds_uv,
    &sxmo_3ds_face,
    &sxmo_3ds_local_matrix,
    &sxmo_lwo2_form,
    &sxmo_lwo2_chunk,
    &sxmo_lwo2_layer,
    &sxmo_lwo2_point,
    &sxmo_lwo2_polygon_type,
    &sxmo_lwo2_tag_type,
    &sxmo_lwo2_polygon,
    &sxmo_lwo2_index16,
    &sxmo_lwo2_index24,
    &sxmo_lwo2_tag_index,
    &sxmo_s3o_header,
    &sxmo_s3o_piece,
    &sxmo_s3o_vertex,
    &sxmo_s3o_child,
    &sxmo_s3o_index,
    &sxmo_stl_binary_header,
    &sxmo_stl_binary_facet,
    &sxmo_openctm_header,
    &sxmo_openctm_string_length,
    &sxmo_openctm_tag,
    &sxmo_openctm_triangle,
    &sxmo_openctm_vertex,
    &sxmo_openctm_normal,
    &sxmo_openctm_uv,
    &sxmo_openctm_attribute,
    &sxmo_qb_header,
    &sxmo_qb_name_length,
    &sxmo_qb_matrix,
    &sxmo_qb_voxel,
    &sxmo_qb_rle_marker,
    &sxmo_qb_rle_run,
    &sxmo_ter_header,
    &sxmo_ter_end,
    &sxmo_ter_size,
    &sxmo_ter_point_count,
    &sxmo_ter_scale,
    &sxmo_ter_radius,
    &sxmo_ter_curvature,
    &sxmo_ter_altitude,
    &sxmo_ter_height,
    &sxmo_pmx20_header,
    &sxmo_pmx_text_length,
    &sxmo_pmx_vertex_count,
    &sxmo_pmx_face_index_count,
    &sxmo_pmx_texture_count,
    &sxmo_pmx_vertex,
    &sxmo_pmx_additional_uv,
    &sxmo_pmx_skinning,
    &sxmo_pmx_bone_index1,
    &sxmo_pmx_vertex_index1,
    &sxmo_pmx_bone_index2,
    &sxmo_pmx_vertex_index2,
    &sxmo_pmx_bone_index4,
    &sxmo_pmx_vertex_index4,
    &sxmo_pmx_weight,
    &sxmo_pmx_edge_scale,
    &sxmo_pmx_sdef,
    &sxmo_pmx_material_count,
    &sxmo_ogre_skeleton_header,
    &sxmo_ogre_skeleton_chunk,
    &sxmo_ogre_skeleton_bone_chunk,
    &sxmo_ogre_skeleton_bone,
    &sxmo_ogre_skeleton_scale,
    &sxmo_ogre_skeleton_parent,
    &sxmo_ogre_skeleton_blend,
    &sxmo_ogre_skeleton_duration,
    &sxmo_ogre_skeleton_track,
    &sxmo_ogre_skeleton_keyframe,
    &sxmo_cal3d_skeleton_header,
    &sxmo_cal3d_bone_name,
    &sxmo_cal3d_bone,
    &sxmo_cal3d_child,
};
static bool sx_modelmeta_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60210000U||id>=0x60220000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60210002U:
        if(!xx_rt_wcscmp(r->name,L"data_size"))text=L"Payload bytes excluding the eight-byte chunk header.";
        break;
    case 0x60210005U:
        if(!xx_rt_wcscmp(r->name,L"texture_index"))text=L"-1 means no texture.";
        break;
    case 0x60210007U:
        if(!xx_rt_wcscmp(r->name,L"rotation_wxyz"))text=L"Quaternion stored as W, X, Y, Z.";
        break;
    case 0x60210008U:
        if(!xx_rt_wcscmp(r->name,L"brush_index"))text=L"-1 means no brush.";
        break;
    case 0x60210009U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 adds normals; bit 1 adds vertex colors.";
        break;
    case 0x60210014U:
        if(!xx_rt_wcscmp(r->name,L"bone_index"))text=L"-1 means no bone.";
        break;
    case 0x60210018U:
        if(!xx_rt_wcscmp(r->name,L"material_index"))text=L"-1 means no material.";
        break;
    case 0x6021001aU:
        if(!xx_rt_wcscmp(r->name,L"current_time"))text=L"Animation time in seconds.";
        break;
    case 0x6021001cU:
        if(!xx_rt_wcscmp(r->name,L"encoded_relocation"))text=L"Bits 29..31 select source section, 25..28 target section; low 25 bits are a source byte offset for target 1, otherwise a word offset.";
        break;
    case 0x6021001eU:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Includes the six-byte chunk header.";
        break;
    case 0x60210023U:
        if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Byte offset within the vertex.";
        break;
    case 0x60210026U:
        if(!xx_rt_wcscmp(r->name,L"operation_type"))text=L"4 means triangle list.";
        break;
    case 0x60210028U:
        if(!xx_rt_wcscmp(r->name,L"pointer_size"))text=L"Underscore means 32-bit pointers; hyphen means 64-bit pointers.";
        if(!xx_rt_wcscmp(r->name,L"byte_order"))text=L"v means little-endian; V means big-endian.";
        break;
    case 0x60210029U:
        if(!xx_rt_wcscmp(r->name,L"old_pointer"))text=L"Original in-memory address before relocation.";
        break;
    case 0x6021002aU:
        if(!xx_rt_wcscmp(r->name,L"old_pointer"))text=L"Original in-memory address before relocation.";
        break;
    case 0x60210032U:
        if(!xx_rt_wcscmp(r->name,L"old_pointer"))text=L"Original in-memory address before relocation.";
        break;
    case 0x60210033U:
        if(!xx_rt_wcscmp(r->name,L"old_pointer"))text=L"Original in-memory address before relocation.";
        break;
    case 0x60210045U:
        if(!xx_rt_wcscmp(r->name,L"encoding"))text=L"0 means raw values; 1 means zlib compressed.";
        break;
    case 0x60210046U:
        if(!xx_rt_wcscmp(r->name,L"identifier"))text=L"Writer-generated footer identifier.";
        break;
    case 0x60210048U:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Includes this six-byte chunk header.";
        break;
    case 0x60210057U:
        if(!xx_rt_wcscmp(r->name,L"count_and_flags"))text=L"Low 10 bits are vertex count; upper 6 bits are polygon flags.";
        break;
    case 0x60210060U:
        if(!xx_rt_wcscmp(r->name,L"header"))text=L"Application-defined binary header bytes.";
        break;
    case 0x60210061U:
        if(!xx_rt_wcscmp(r->name,L"attribute_byte_count"))text=L"Native reader accepts zero; nonzero vendor color encodings are outside this provider.";
        break;
    case 0x60210062U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 indicates vertex normals.";
        break;
    case 0x6021006aU:
        if(!xx_rt_wcscmp(r->name,L"color_format"))text=L"0=RGBA, 1=BGRA.";
        break;
    case 0x6021006dU:
        if(!xx_rt_wcscmp(r->name,L"encoded_color"))text=L"Color byte order and alpha/visibility-mask meaning are selected by the file header.";
        break;
    case 0x6021006eU:
        if(!xx_rt_wcscmp(r->name,L"marker"))text=L"2=run; 6=end of slice.";
        break;
    case 0x60210072U:
        if(!xx_rt_wcscmp(r->name,L"size_minus_one"))text=L"Shorter terrain side is this value plus one samples.";
        break;
    case 0x60210078U:
        if(!xx_rt_wcscmp(r->name,L"height_sample"))text=L"Encoded height; convert using base_height and height_scale, then vertical scale.";
        break;
    case 0x60210079U:
        if(!xx_rt_wcscmp(r->name,L"encoding"))text=L"0=UTF-16LE, 1=UTF-8.";
        break;
    case 0x60210080U:
        if(!xx_rt_wcscmp(r->name,L"deform_type"))text=L"0=BDEF1, 1=BDEF2, 2=BDEF4, 3=SDEF.";
        break;
    case 0x60210081U:
        if(!xx_rt_wcscmp(r->name,L"bone_index"))text=L"-1 means no bone.";
        break;
    case 0x60210083U:
        if(!xx_rt_wcscmp(r->name,L"bone_index"))text=L"-1 means no bone.";
        break;
    case 0x60210085U:
        if(!xx_rt_wcscmp(r->name,L"bone_index"))text=L"-1 means no bone.";
        break;
    case 0x6021008cU:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Includes this six-byte header.";
        break;
    case 0x6021008dU:
        if(!xx_rt_wcscmp(r->name,L"fixed_size"))text=L"Historical bone length excludes the newline-terminated bone name; includes the six-byte header.";
        break;
    case 0x60210092U:
        if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Animation duration in seconds.";
        break;
    case 0x60210094U:
        if(!xx_rt_wcscmp(r->name,L"time"))text=L"Animation time in seconds.";
        break;
    case 0x60210096U:
        if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Includes the terminating NUL byte.";
        break;
    case 0x60210097U:
        if(!xx_rt_wcscmp(r->name,L"parent_index"))text=L"-1 means no parent.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}

/* Physical metadata only; unimplemented and compressed bodies stay raw. */
static bool sxmo_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxmo_read(sx_context*c,uint64_t p,void*b,size_t n){return sxmo_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxmo_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint32_t sxmo32(const uint8_t*b,bool be){return(uint32_t)sxmo_uint(b,4,be);}
static uint16_t sxmo16(const uint8_t*b,bool be){return(uint16_t)sxmo_uint(b,2,be);}
/* Alias pointers are emitted once. Partial overlaps retain the first bounded physical record. */
static bool sxmo_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n)return true;if(n>1000000||!sxmo_span(c,p,z*n))return false;if(c->count>=20000)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),b=a+(uint64_t)c->items[i].total_size;if(p<b&&a<p+z*n)return true;}return sx_table(c,l,(int64_t)p,(int64_t)z,n);}
static bool sxmo_add(sx_context*c,const sx_layout*l,uint64_t p){return sxmo_table(c,l,p,1);}
static bool sxmo_string(sx_context*c,uint64_t*p,uint64_t end,uint8_t terminal){for(unsigned i=0;i<4096;i++){uint8_t b;if(*p>=end||!sxmo_read(c,(*p)++,&b,1))return false;if(b==terminal)return true;}return false;}
static bool sxmo_take(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(*p>end||z>end-*p||!sxmo_add(c,l,*p))return false;*p+=z;return true;}
static bool sxmo_text(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end){uint8_t b[4];if(*p>end||end-*p<4||!sxmo_read(c,*p,b,4))return false;uint32_t n=sxmo32(b,false);if(n>1048576||n>end-*p-4||!sxmo_add(c,l,*p))return false;*p+=4+n;return true;}
static bool sxmo_b3d_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,unsigned*budget){while(p<end&&depth<32&&*budget<16000){(*budget)++;uint8_t h[12];if(end-p<8||!sxmo_read(c,p,h,8))break;uint32_t n=sxmo32(h+4,false);if(n>INT32_MAX||n>end-p-8)break;uint64_t q=p+8,stop=q+n;if(!sxmo_add(c,&sxmo_b3d_chunk,p))return false;
 if(!xx_rt_memcmp(h,"TEXS",4)){for(unsigned i=0;q<stop&&i<1024;i++){if(!sxmo_string(c,&q,stop,0)||stop-q<28)break;if(!sxmo_take(c,&sxmo_b3d_texture,&q,stop))return false;}}
 else if(!xx_rt_memcmp(h,"BRUS",4)&&n>=4){if(!sxmo_read(c,q,h,4))return false;unsigned refs=sxmo32(h,false);if(refs<=8){if(!sxmo_take(c,&sxmo_b3d_brush_count,&q,stop))return false;for(unsigned i=0;q<stop&&i<1024;i++){if(!sxmo_string(c,&q,stop,0)||stop-q<28+refs*4)break;if(!sxmo_take(c,&sxmo_b3d_brush,&q,stop)||!sxmo_table(c,&sxmo_b3d_texture_index,q,refs))return false;q+=refs*4;}}}
 else if(!xx_rt_memcmp(h,"NODE",4)){if(sxmo_string(c,&q,stop,0)&&stop-q>=40){if(!sxmo_take(c,&sxmo_b3d_node,&q,stop)||!sxmo_b3d_chunks(c,q,stop,depth+1,budget))return false;}}
 else if(!xx_rt_memcmp(h,"MESH",4)&&n>=4){if(!sxmo_take(c,&sxmo_b3d_brush_index,&q,stop)||!sxmo_b3d_chunks(c,q,stop,depth+1,budget))return false;}
 else if(!xx_rt_memcmp(h,"TRIS",4)&&n>=4){if(!sxmo_take(c,&sxmo_b3d_brush_index,&q,stop)||!sxmo_table(c,&sxmo_b3d_triangle,q,(stop-q)/12))return false;}
 else if(!xx_rt_memcmp(h,"VRTS",4)&&n>=12){if(!sxmo_read(c,q,h,12)||!sxmo_take(c,&sxmo_b3d_vertices,&q,stop))return false;unsigned flags=sxmo32(h,false),sets=sxmo32(h+4,false),size=sxmo32(h+8,false);if(flags<=3&&sets<=4&&size<=4){uint64_t z=12+((flags&1)?12:0)+((flags&2)?16:0)+sets*size*4;for(unsigned i=0;z<=stop-q&&i<4096;i++){if(!sxmo_take(c,&sxmo_b3d_position,&q,stop)||((flags&1)&&!sxmo_take(c,&sxmo_b3d_normal,&q,stop))||((flags&2)&&!sxmo_take(c,&sxmo_b3d_color,&q,stop))||!sxmo_table(c,&sxmo_b3d_texture_coordinate,q,sets*size))return false;q+=sets*size*4;}}}p=stop;}return !c->failed;}
static bool sxmo_b3d(sx_context*c){uint8_t h[12];if(!sxmo_read(c,0,h,12)||xx_rt_memcmp(h,"BB3D",4)||sxmo32(h+8,false)!=1||!sxmo_add(c,&sxmo_b3d_header,0))return false;uint64_t end=8+(uint64_t)sxmo32(h+4,false);if(end>(uint64_t)c->size)end=(uint64_t)c->size;unsigned budget=0;return sxmo_b3d_chunks(c,12,end,0,&budget);}
static bool sxmo_ms3d(sx_context*c){uint8_t h[35];if(!sxmo_read(c,0,h,14)||xx_rt_memcmp(h,"MS3D000000",10)||!sxmo_add(c,&sxmo_ms3d_header,0))return false;uint64_t p=14,end=(uint64_t)c->size;const sx_layout*counts[]={&sxmo_ms3d_vertex_count,&sxmo_ms3d_triangle_count,&sxmo_ms3d_group_count,&sxmo_ms3d_material_count};
 for(unsigned kind=0;kind<4;kind++){if(end-p<2||!sxmo_read(c,p,h,2))return true;unsigned n=sxmo16(h,false);if(!sxmo_take(c,counts[kind],&p,end))return false;if(kind==2){if(n>128)return true;for(unsigned i=0;i<n;i++){if(end-p<35||!sxmo_read(c,p,h,35))return true;unsigned tris=sxmo16(h+33,false);if((uint64_t)tris*2+36>end-p)return true;if(!sxmo_take(c,&sxmo_ms3d_group,&p,end)||!sxmo_table(c,&sxmo_ms3d_triangle_index,p,tris))return false;p+=tris*2;if(!sxmo_take(c,&sxmo_ms3d_material_index,&p,end))return false;}}
 else{const sx_layout*l=kind==0?&sxmo_ms3d_vertex:kind==1?&sxmo_ms3d_triangle:&sxmo_ms3d_material;uint64_t z=kind==0?15:kind==1?70:361;if(n*z>end-p)return true;if(!sxmo_table(c,l,p,n))return false;p+=n*z;}}
 return end-p<14||sxmo_add(c,&sxmo_ms3d_animation,p);}
static bool sxmo_bch(sx_context*c){uint8_t h[68];if(!sxmo_read(c,0,h,68)||xx_rt_memcmp(h,"BCH\0",4)||h[4]!=0x21||h[5]!=0x21||!sxmo_add(c,&sxmo_bch21_header,0))return false;uint64_t p=sxmo32(h+28,false),z=sxmo32(h+52,false);if(p>=68&&z%4==0&&z/4<=4096&&sxmo_span(c,p,z)&&!sxmo_table(c,&sxmo_bch_relocation,p,z/4))return false;return true;}
static bool sxmo_ogre_mesh_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,unsigned*budget){while(p<end&&depth<8&&*budget<16000){(*budget)++;uint8_t h[6];if(end-p<6||!sxmo_read(c,p,h,6))break;unsigned tag=sxmo16(h,false);uint64_t n=sxmo32(h+2,false);if(n<6||n>end-p)break;uint64_t q=p+6,stop=p+n;if(!sxmo_add(c,&sxmo_ogre_mesh_chunk,p))return false;
 if(tag==0x3000&&stop-q>=1){if(!sxmo_take(c,&sxmo_ogre_mesh_animation,&q,stop)||!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x4000&&sxmo_string(c,&q,stop,10)&&stop-q>=6){if(!sxmo_read(c,q,h,6))return false;uint64_t count=sxmo32(h+1,false),z=h[5]?4:2;if(!h[5]&&count<=1000000&&count*z<=stop-q-6){if(!sxmo_take(c,&sxmo_ogre_submesh,&q,stop)||!sxmo_table(c,&sxmo_ogre_index16,q,count))return false;q+=count*z;if(!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}}
 else if(tag==0x5000&&stop-q>=4){if(!sxmo_take(c,&sxmo_ogre_vertex_count,&q,stop)||!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x5100){if(!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x5110&&stop-q>=10){if(!sxmo_add(c,&sxmo_ogre_vertex_element,q))return false;}
 else if(tag==0x5200&&stop-q>=4){if(!sxmo_take(c,&sxmo_ogre_vertex_buffer,&q,stop)||!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x5210&&(stop-q)%12==0&&(stop-q)/12<=1000000){if(!sxmo_table(c,&sxmo_ogre_position,q,(stop-q)/12))return false;}
 else if(tag==0x4010&&stop-q>=2){if(!sxmo_add(c,&sxmo_ogre_operation,q))return false;}
 else if(tag==0x9000&&stop-q>=28&&!sxmo_add(c,&sxmo_ogre_bounds,q))return false;p=stop;}return !c->failed;}
static bool sxmo_ogre_mesh(sx_context*c){uint8_t h[26];if(!sxmo_read(c,0,h,26)||xx_rt_memcmp(h,"\0\x10[MeshSerializer_v1.100]\n",26)||!sxmo_add(c,&sxmo_ogre_mesh_header,0))return false;unsigned budget=0;return sxmo_ogre_mesh_chunks(c,26,(uint64_t)c->size,0,&budget);}
#define SXMO_E(n) (be?&sxmo_##n##_be:&sxmo_##n##_le)
static bool sxmo_blend_dna(sx_context*c,uint64_t p,uint64_t end,bool be){uint8_t h[12];if(end-p<12||!sxmo_read(c,p,h,12)||xx_rt_memcmp(h,"SDNANAME",8))return true;uint32_t n=sxmo32(h+8,be);if(n>65536)return true;if(!sxmo_add(c,SXMO_E(blend_dna_names),p))return false;p+=12;for(uint32_t i=0;i<n;i++)if(!sxmo_string(c,&p,end,0))return true;p=(p+3)&~UINT64_C(3);
 if(p>end||end-p<8||!sxmo_read(c,p,h,8)||xx_rt_memcmp(h,"TYPE",4))return true;n=sxmo32(h+4,be);if(n>65536)return true;if(!sxmo_add(c,SXMO_E(blend_dna_types),p))return false;p+=8;for(uint32_t i=0;i<n;i++)if(!sxmo_string(c,&p,end,0))return true;p=(p+3)&~UINT64_C(3);
 if(p>end||end-p<4+(uint64_t)n*2||!sxmo_read(c,p,h,4)||xx_rt_memcmp(h,"TLEN",4))return true;if(!sxmo_add(c,SXMO_E(blend_dna_lengths_tag),p)||!sxmo_table(c,SXMO_E(blend_dna_type_size),p+4,n))return false;p=(p+4+n*2+3)&~UINT64_C(3);
 if(p>end||end-p<8||!sxmo_read(c,p,h,8)||xx_rt_memcmp(h,"STRC",4))return true;n=sxmo32(h+4,be);if(n>4096)return true;if(!sxmo_add(c,SXMO_E(blend_dna_structures),p))return false;p+=8;for(uint32_t i=0;i<n;i++){if(p>end||end-p<4||!sxmo_read(c,p,h,4))break;unsigned fields=sxmo16(h+2,be);if((uint64_t)fields*4>end-p-4)break;if(!sxmo_add(c,SXMO_E(blend_dna_structure),p)||!sxmo_table(c,SXMO_E(blend_dna_field),p+4,fields))return false;p+=4+(uint64_t)fields*4;}return !c->failed;}
static bool sxmo_blend(sx_context*c){uint8_t h[24];if(!sxmo_read(c,0,h,12)||xx_rt_memcmp(h,"BLENDER",7)||(h[7]!='_'&&h[7]!='-')||(h[8]!='v'&&h[8]!='V')||!sxmo_add(c,&sxmo_blend_header,0))return false;unsigned ptr=h[7]=='_'?4:8,z=16+ptr;bool be=h[8]=='V';const sx_layout*l=ptr==4?SXMO_E(blend_block32):SXMO_E(blend_block64);uint64_t p=12,end=(uint64_t)c->size;
 for(unsigned i=0;i<4096&&p<end;i++){if(end-p<z||!sxmo_read(c,p,h,z))break;uint32_t n=sxmo32(h+4,be);if(n>INT32_MAX||n>end-p-z)break;if(!sxmo_add(c,l,p))return false;if(!xx_rt_memcmp(h,"DNA1",4)&&!sxmo_blend_dna(c,p+z,p+z+n,be))return false;if(!xx_rt_memcmp(h,"ENDB",4))break;p+=z+n;}return !c->failed;}
#undef SXMO_E
static bool sxmo_fbx_properties(sx_context*c,uint64_t p,uint64_t end,uint64_t count){for(uint64_t i=0;i<count&&i<16000;i++){uint8_t h[13];if(p>=end||!sxmo_read(c,p,h,1))break;const sx_layout*l=NULL;unsigned z=0;switch(h[0]){case'Y':l=&sxmo_fbx_scalar_y;z=3;break;case'C':l=&sxmo_fbx_scalar_c;z=2;break;case'I':l=&sxmo_fbx_scalar_i;z=5;break;case'F':l=&sxmo_fbx_scalar_f;z=5;break;case'L':l=&sxmo_fbx_scalar_l;z=9;break;case'D':l=&sxmo_fbx_scalar_d;z=9;break;default:break;}if(l){if(z>end-p)break;if(!sxmo_add(c,l,p))return false;p+=z;continue;}
 if(h[0]=='S'||h[0]=='R'){if(end-p<5||!sxmo_read(c,p,h,5))break;uint64_t n=sxmo32(h+1,false);if(n>end-p-5)break;if(!sxmo_add(c,&sxmo_fbx_blob,p))return false;p+=5+n;}
 else if(h[0]=='f'||h[0]=='d'||h[0]=='l'||h[0]=='i'||h[0]=='b'||h[0]=='c'){if(end-p<13||!sxmo_read(c,p,h,13))break;uint64_t n=sxmo32(h+9,false);if(n>end-p-13)break;if(!sxmo_add(c,&sxmo_fbx_array,p))return false;p+=13+n;}else break;}return !c->failed;}
static bool sxmo_fbx_nodes(sx_context*c,uint64_t*p,uint64_t end,unsigned width,unsigned depth,unsigned*budget){unsigned z=width*3+1;while(*p<end&&depth<32&&*budget<16000){(*budget)++;uint8_t h[25];if(end-*p<z||!sxmo_read(c,*p,h,z))break;uint64_t stop=sxmo_uint(h,width,false),count=sxmo_uint(h+width,width,false),props=sxmo_uint(h+2*width,width,false),name=h[z-1];if(!stop&&!count&&!props&&!name){if(!sxmo_add(c,width==4?&sxmo_fbx_node32:&sxmo_fbx_node64,*p))return false;*p+=z;break;}if(stop<=*p||stop>end||stop-*p<z+name||props>stop-*p-z-name)break;if(!sxmo_add(c,width==4?&sxmo_fbx_node32:&sxmo_fbx_node64,*p))return false;uint64_t q=*p+z+name;if(!sxmo_fbx_properties(c,q,q+props,count))return false;q+=props;if(q<stop&&!sxmo_fbx_nodes(c,&q,stop,width,depth+1,budget))return false;*p=stop;}return !c->failed;}
static bool sxmo_fbx(sx_context*c){uint8_t h[27];if(!sxmo_read(c,0,h,27)||xx_rt_memcmp(h,"Kaydara FBX Binary  \0\x1a\0",23)||!sxmo_add(c,&sxmo_fbx_header,0))return false;unsigned width=sxmo32(h+23,false)>=7500?8:4,budget=0;uint64_t p=27,end=(uint64_t)c->size;if(!sxmo_fbx_nodes(c,&p,end,width,0,&budget))return false;if(p<end&&end-p>=20){if(!sxmo_add(c,&sxmo_fbx_footer_prefix,p))return false;p+=20;p+=16-(p&15);if(p<=end&&end-p>=140&&!sxmo_add(c,&sxmo_fbx_footer_tail,p))return false;}return !c->failed;}
static bool sxmo_3ds_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,unsigned*budget){while(p<end&&depth<12&&*budget<16000){(*budget)++;uint8_t h[6];if(end-p<6||!sxmo_read(c,p,h,6))break;unsigned id=sxmo16(h,false);uint64_t n=sxmo32(h+2,false);if(n<6||n>end-p)break;if(!sxmo_add(c,&sxmo_3ds_chunk,p))return false;uint64_t q=p+6,stop=p+n;
 if(id==0x4d4d||id==0x3d3d||id==0x4100){if(!sxmo_3ds_chunks(c,q,stop,depth+1,budget))return false;}
 else if(id==0x4000){if(sxmo_string(c,&q,stop,0)&&!sxmo_3ds_chunks(c,q,stop,depth+1,budget))return false;}
 else if((id==2||id==0x3d3e)&&stop-q>=4){if(!sxmo_add(c,&sxmo_3ds_version,q))return false;}
 else if((id==0x4110||id==0x4120||id==0x4140)&&stop-q>=2){if(!sxmo_read(c,q,h,2))return false;unsigned count=sxmo16(h,false),z=id==0x4110?12:8;if((uint64_t)count*z<=stop-q-2){const sx_layout*a=id==0x4110?&sxmo_3ds_vertex_count:id==0x4120?&sxmo_3ds_face_count:&sxmo_3ds_uv_count,*b=id==0x4110?&sxmo_3ds_vertex:id==0x4120?&sxmo_3ds_face:&sxmo_3ds_uv;if(!sxmo_add(c,a,q)||!sxmo_table(c,b,q+2,count))return false;}}
 else if(id==0x4160&&stop-q>=48&&!sxmo_add(c,&sxmo_3ds_local_matrix,q))return false;p=stop;}return !c->failed;}
static bool sxmo_3ds(sx_context*c){uint8_t h[2];if(!sxmo_read(c,0,h,2)||sxmo16(h,false)!=0x4d4d)return false;unsigned budget=0;return sxmo_3ds_chunks(c,0,(uint64_t)c->size,0,&budget);}
static bool sxmo_lwo_index(sx_context*c,uint64_t*p,uint64_t end){uint8_t b;if(*p>=end||!sxmo_read(c,*p,&b,1))return false;return sxmo_take(c,b==255?&sxmo_lwo2_index24:&sxmo_lwo2_index16,p,end);}
static bool sxmo_lwo(sx_context*c){uint8_t h[12];if(!sxmo_read(c,0,h,12)||xx_rt_memcmp(h,"FORM",4)||xx_rt_memcmp(h+8,"LWO2",4)||!sxmo_add(c,&sxmo_lwo2_form,0))return false;uint64_t p=12,end=8+(uint64_t)sxmo32(h+4,true);if(end>(uint64_t)c->size)end=(uint64_t)c->size;
 for(unsigned i=0;p<end&&i<4096;i++){if(end-p<8||!sxmo_read(c,p,h,8))break;uint64_t z=sxmo32(h+4,true);if(z>end-p-8)break;uint64_t q=p+8,stop=q+z;if(!sxmo_add(c,&sxmo_lwo2_chunk,p))return false;
 if(!xx_rt_memcmp(h,"LAYR",4)&&z>=16){if(!sxmo_add(c,&sxmo_lwo2_layer,q))return false;}
 else if(!xx_rt_memcmp(h,"PNTS",4)&&z%12==0&&z/12<=1000000){if(!sxmo_table(c,&sxmo_lwo2_point,q,z/12))return false;}
 else if(!xx_rt_memcmp(h,"POLS",4)&&z>=4){if(!sxmo_take(c,&sxmo_lwo2_polygon_type,&q,stop))return false;for(unsigned j=0;q<stop&&j<4096;j++){if(stop-q<2||!sxmo_read(c,q,h,2))break;unsigned n=sxmo16(h,true)&1023;if(!sxmo_take(c,&sxmo_lwo2_polygon,&q,stop))return false;bool ok=true;for(unsigned k=0;k<n;k++)if(!sxmo_lwo_index(c,&q,stop)){ok=false;break;}if(!ok)break;}}
 else if(!xx_rt_memcmp(h,"PTAG",4)&&z>=4){if(!sxmo_take(c,&sxmo_lwo2_tag_type,&q,stop))return false;for(unsigned j=0;q<stop&&j<4096;j++){if(!sxmo_lwo_index(c,&q,stop)||stop-q<2)break;if(!sxmo_take(c,&sxmo_lwo2_tag_index,&q,stop))return false;}}p=stop+(z&1);}return !c->failed;}
static bool sxmo_s3o_walk_piece(sx_context*c,uint64_t p,unsigned depth,uint64_t*seen,unsigned*count){if(depth>=32||*count>=256||p<52)return true;for(unsigned i=0;i<*count;i++)if(seen[i]==p)return true;uint8_t h[52];if(!sxmo_read(c,p,h,52))return true;seen[(*count)++]=p;if(!sxmo_add(c,&sxmo_s3o_piece,p))return false;uint64_t children=sxmo32(h+8,false),verts=sxmo32(h+16,false),indices=sxmo32(h+32,false);uint32_t nc=sxmo32(h+4,false),nv=sxmo32(h+12,false),ni=sxmo32(h+28,false);
 if(nv<=65536&&verts>=52&&sxmo_span(c,verts,(uint64_t)nv*32)&&!sxmo_table(c,&sxmo_s3o_vertex,verts,nv))return false;if(ni<=262144&&indices>=52&&sxmo_span(c,indices,(uint64_t)ni*4)&&!sxmo_table(c,&sxmo_s3o_index,indices,ni))return false;
 if(nc<=256&&children>=52&&sxmo_span(c,children,(uint64_t)nc*4)){if(!sxmo_table(c,&sxmo_s3o_child,children,nc))return false;for(unsigned i=0;i<nc;i++){if(!sxmo_read(c,children+i*4,h,4)||!sxmo_s3o_walk_piece(c,sxmo32(h,false),depth+1,seen,count))return false;}}return !c->failed;}
static bool sxmo_s3o(sx_context*c){uint8_t h[52];if(!sxmo_read(c,0,h,52)||xx_rt_memcmp(h,"Spring unit\0",12)||!sxmo_add(c,&sxmo_s3o_header,0))return false;uint64_t seen[256];unsigned count=0;return sxmo_s3o_walk_piece(c,sxmo32(h+36,false),0,seen,&count);}
static bool sxmo_stl(sx_context*c){uint8_t h[84];if(!sxmo_read(c,0,h,84)||!sxmo_add(c,&sxmo_stl_binary_header,0))return false;uint64_t n=sxmo32(h+80,false);if(n<=1000000&&sxmo_span(c,84,n*50)&&!sxmo_table(c,&sxmo_stl_binary_facet,84,n))return false;return true;}
static bool sxmo_ctm(sx_context*c){uint8_t h[32];if(!sxmo_read(c,0,h,32)||xx_rt_memcmp(h,"OCTM",4)||!sxmo_add(c,&sxmo_openctm_header,0))return false;uint64_t p=32,end=(uint64_t)c->size;uint32_t verts=sxmo32(h+12,false),tris=sxmo32(h+16,false),uv=sxmo32(h+20,false),attrs=sxmo32(h+24,false),flags=sxmo32(h+28,false);if(!sxmo_text(c,&sxmo_openctm_string_length,&p,end)||xx_rt_memcmp(h+8,"RAW\0",4)||verts>1000000||tris>1000000||uv>16||attrs>16)return !c->failed;
 const sx_layout*layouts[]={&sxmo_openctm_triangle,&sxmo_openctm_vertex,&sxmo_openctm_normal};for(unsigned i=0;i<2+(flags&1);i++){uint64_t n=i==0?tris:verts;if(end-p<4+n*12)return true;if(!sxmo_take(c,&sxmo_openctm_tag,&p,end)||!sxmo_table(c,layouts[i],p,n))return false;p+=n*12;}
 for(unsigned i=0;i<uv+attrs;i++){bool tex=i<uv;if(end-p<4)return true;if(!sxmo_take(c,&sxmo_openctm_tag,&p,end)||!sxmo_text(c,&sxmo_openctm_string_length,&p,end)||(tex&&!sxmo_text(c,&sxmo_openctm_string_length,&p,end)))return !c->failed;uint64_t z=tex?8:16;if(verts*z>end-p)return true;if(!sxmo_table(c,tex?&sxmo_openctm_uv:&sxmo_openctm_attribute,p,verts))return false;p+=verts*z;}return !c->failed;}
static bool sxmo_qb(sx_context*c){uint8_t h[24];if(!sxmo_read(c,0,h,24)||sxmo32(h,false)!=0x101||!sxmo_add(c,&sxmo_qb_header,0))return false;uint32_t count=sxmo32(h+20,false),compressed=sxmo32(h+12,false);if(count>1024||compressed>1)return true;uint64_t p=24,end=(uint64_t)c->size;unsigned budget=0;
 for(unsigned i=0;i<count;i++){if(p>=end||!sxmo_read(c,p,h,1))break;unsigned z=h[0];if(25+(uint64_t)z>end-p)break;if(!sxmo_add(c,&sxmo_qb_name_length,p))return false;p+=1+z;if(!sxmo_read(c,p,h,24)||!sxmo_add(c,&sxmo_qb_matrix,p))return false;p+=24;uint64_t nx=sxmo32(h,false),ny=sxmo32(h+4,false),nz=sxmo32(h+8,false);if(!nx||!ny||!nz||nx>16777216||ny>16777216/nx||nz>16777216/(nx*ny))break;uint64_t pixels=nx*ny*nz;
 if(!compressed){if(pixels*4>end-p)break;if(pixels<=1000000&&!sxmo_table(c,&sxmo_qb_voxel,p,pixels))return false;p+=pixels*4;}
 else{bool valid=true;for(uint64_t slice=0;slice<nz&&valid;slice++){uint64_t filled=0;bool terminal=false;while(p<end&&budget++<16000){if(end-p<4||!sxmo_read(c,p,h,4)){valid=false;break;}uint32_t code=sxmo32(h,false);if(code==6){if(!sxmo_take(c,&sxmo_qb_rle_marker,&p,end))return false;terminal=true;break;}uint64_t run=1;if(code==2){if(end-p<12||!sxmo_read(c,p+4,h,8)){valid=false;break;}run=sxmo32(h,false);if(!sxmo_take(c,&sxmo_qb_rle_marker,&p,end)||!sxmo_take(c,&sxmo_qb_rle_run,&p,end))return false;}else if(!sxmo_take(c,&sxmo_qb_voxel,&p,end))return false;if(run>nx*ny-filled){valid=false;break;}filled+=run;}if(!terminal||filled!=nx*ny)valid=false;}if(!valid)break;}}return !c->failed;}
static bool sxmo_ter(sx_context*c){uint8_t h[16];if(!sxmo_read(c,0,h,16)||xx_rt_memcmp(h,"TERRAGENTERRAIN ",16)||!sxmo_add(c,&sxmo_ter_header,0))return false;uint64_t p=16,end=(uint64_t)c->size,width=0,height=0;
 for(unsigned i=0;p<end&&i<4096;i++){if(end-p<4||!sxmo_read(c,p,h,4))break;const sx_layout*l=NULL;unsigned z=0;if(!xx_rt_memcmp(h,"SIZE",4)){l=&sxmo_ter_size;z=8;}else if(!xx_rt_memcmp(h,"XPTS",4)||!xx_rt_memcmp(h,"YPTS",4)){l=&sxmo_ter_point_count;z=8;}else if(!xx_rt_memcmp(h,"SCAL",4)){l=&sxmo_ter_scale;z=16;}else if(!xx_rt_memcmp(h,"CRAD",4)){l=&sxmo_ter_radius;z=8;}else if(!xx_rt_memcmp(h,"CRVM",4)){l=&sxmo_ter_curvature;z=8;}else if(!xx_rt_memcmp(h,"ALTW",4)){l=&sxmo_ter_altitude;z=8;}else if(!xx_rt_memcmp(h,"EOF ",4)){l=&sxmo_ter_end;z=4;}else break;if(z>end-p||!sxmo_read(c,p,h,z))break;if(!sxmo_add(c,l,p))return false;p+=z;
 if(l==&sxmo_ter_size)width=height=(uint64_t)sxmo16(h+4,false)+1;else if(l==&sxmo_ter_point_count){if(h[0]=='X')width=sxmo16(h+4,false);else height=sxmo16(h+4,false);}else if(l==&sxmo_ter_altitude){if(!width||!height||height>1000000/width||width*height*2>end-p)break;if(!sxmo_table(c,&sxmo_ter_height,p,width*height))return false;p=(p+width*height*2+3)&~UINT64_C(3);if(p>end)break;}else if(l==&sxmo_ter_end)break;}return !c->failed;}
static bool sxmo_pmx(sx_context*c){uint8_t h[17];if(!sxmo_read(c,0,h,17)||xx_rt_memcmp(h,"PMX ",4)||sxmo32(h+4,false)!=0x40000000||h[8]!=8||!sxmo_add(c,&sxmo_pmx20_header,0))return false;unsigned additional=h[10],bone=h[14],vertex=h[11];if(additional>4||(bone!=1&&bone!=2&&bone!=4)||(vertex!=1&&vertex!=2&&vertex!=4))return true;uint64_t p=17,end=(uint64_t)c->size;
 for(unsigned i=0;i<4;i++)if(!sxmo_text(c,&sxmo_pmx_text_length,&p,end))return !c->failed;if(end-p<4||!sxmo_read(c,p,h,4))return true;uint32_t count=sxmo32(h,false);if(count>4096)return true;if(!sxmo_take(c,&sxmo_pmx_vertex_count,&p,end))return false;
 for(uint32_t i=0;i<count;i++){if(end-p<33+(uint64_t)additional*16)return true;if(!sxmo_take(c,&sxmo_pmx_vertex,&p,end)||!sxmo_table(c,&sxmo_pmx_additional_uv,p,additional))return false;p+=additional*16;if(!sxmo_read(c,p,h,1))return false;unsigned deform=h[0];if(deform>3)return true;if(!sxmo_take(c,&sxmo_pmx_skinning,&p,end))return false;unsigned bones=deform==0?1:deform==2?4:2,weights=deform==0?0:deform==2?4:1;uint64_t z=bones*bone+weights*4+(deform==3?36:0)+4;if(z>end-p)return true;const sx_layout*l=bone==1?&sxmo_pmx_bone_index1:bone==2?&sxmo_pmx_bone_index2:&sxmo_pmx_bone_index4;if(!sxmo_table(c,l,p,bones))return false;p+=bones*bone;if(!sxmo_table(c,&sxmo_pmx_weight,p,weights))return false;p+=weights*4;if(deform==3&&!sxmo_take(c,&sxmo_pmx_sdef,&p,end))return false;if(!sxmo_take(c,&sxmo_pmx_edge_scale,&p,end))return false;}
 if(end-p<4||!sxmo_read(c,p,h,4))return true;count=sxmo32(h,false);if(count>1000000||(uint64_t)count*vertex>end-p-4)return true;if(!sxmo_take(c,&sxmo_pmx_face_index_count,&p,end)||!sxmo_table(c,vertex==1?&sxmo_pmx_vertex_index1:vertex==2?&sxmo_pmx_vertex_index2:&sxmo_pmx_vertex_index4,p,count))return false;p+=(uint64_t)count*vertex;
 if(end-p<4||!sxmo_read(c,p,h,4))return true;count=sxmo32(h,false);if(count>65536)return true;if(!sxmo_take(c,&sxmo_pmx_texture_count,&p,end))return false;for(uint32_t i=0;i<count;i++)if(!sxmo_text(c,&sxmo_pmx_text_length,&p,end))return !c->failed;return end-p<4||sxmo_add(c,&sxmo_pmx_material_count,p);}
static bool sxmo_skeleton_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,unsigned*budget){while(p<end&&depth<3&&*budget<16000){(*budget)++;uint8_t h[6];if(end-p<6||!sxmo_read(c,p,h,6))break;unsigned tag=sxmo16(h,false);uint64_t n=sxmo32(h+2,false),q=p+6;if(n<6)break;
 if(tag==0x2000){if(n!=36&&n!=48)break;if(!sxmo_string(c,&q,end,10)||n-6>end-q)break;if(!sxmo_add(c,&sxmo_ogre_skeleton_bone_chunk,p)||!sxmo_take(c,&sxmo_ogre_skeleton_bone,&q,end))return false;if(n==48&&!sxmo_take(c,&sxmo_ogre_skeleton_scale,&q,end))return false;p=q;continue;}
 if(n>end-p)break;uint64_t stop=p+n;if(!sxmo_add(c,&sxmo_ogre_skeleton_chunk,p))return false;
 if(tag==0x1010&&n==8){if(!sxmo_add(c,&sxmo_ogre_skeleton_blend,q))return false;}else if(tag==0x3000&&n==10){if(!sxmo_add(c,&sxmo_ogre_skeleton_parent,q))return false;}
 else if(tag==0x4000&&sxmo_string(c,&q,stop,10)&&stop-q>=4){if(!sxmo_take(c,&sxmo_ogre_skeleton_duration,&q,stop)||!sxmo_skeleton_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x4100&&stop-q>=2){if(!sxmo_take(c,&sxmo_ogre_skeleton_track,&q,stop)||!sxmo_skeleton_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x4110&&(n==38||n==50)){if(!sxmo_take(c,&sxmo_ogre_skeleton_keyframe,&q,stop)||(n==50&&!sxmo_take(c,&sxmo_ogre_skeleton_scale,&q,stop)))return false;}p=stop;}return !c->failed;}
static bool sxmo_skeleton(sx_context*c){uint8_t h[21];if(!sxmo_read(c,0,h,21)||sxmo16(h,false)!=0x1000||!sxmo_add(c,&sxmo_ogre_skeleton_header,0))return false;unsigned budget=0;return sxmo_skeleton_chunks(c,21,(uint64_t)c->size,0,&budget);}
static bool sxmo_csf(sx_context*c){uint8_t h[64];if(!sxmo_read(c,0,h,12)||xx_rt_memcmp(h,"CSF\0",4)||sxmo32(h+4,false)!=700||!sxmo_add(c,&sxmo_cal3d_skeleton_header,0))return false;unsigned count=sxmo32(h+8,false);if(count>4000)return true;uint64_t p=12,end=(uint64_t)c->size;for(unsigned i=0;i<count;i++){if(!sxmo_text(c,&sxmo_cal3d_bone_name,&p,end)||end-p<64||!sxmo_read(c,p,h,64))break;uint64_t n=sxmo32(h+60,false);if(n>4000||n*4>end-p-64)break;if(!sxmo_take(c,&sxmo_cal3d_bone,&p,end)||!sxmo_table(c,&sxmo_cal3d_child,p,n))return false;p+=n*4;}return !c->failed;}
static int sxmo_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxmo_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmo_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmo_order);return !c->failed;}
static bool sx_modelmeta_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_BLITZ3D_B3D:case XX_FILE_TYPE_MILKSHAPE_MS3D:case XX_FILE_TYPE_NINTENDO_BCH:case XX_FILE_TYPE_OGRE_MESH:case XX_FILE_TYPE_BLENDER_BLEND:case XX_FILE_TYPE_AUTODESK_FBX:case XX_FILE_TYPE_AUTODESK_3DS:case XX_FILE_TYPE_LIGHTWAVE_LWO2:case XX_FILE_TYPE_SPRING_S3O:case XX_FILE_TYPE_STEREOLITHOGRAPHY_STL:case XX_FILE_TYPE_OPENCTM_MESH:case XX_FILE_TYPE_QUBICLE_QB:case XX_FILE_TYPE_TERRAGEN_TER:case XX_FILE_TYPE_MMD_PMX:case XX_FILE_TYPE_OGRE_SKELETON:case XX_FILE_TYPE_CAL3D_SKELETON:return true;default:return false;}}
static bool sx_modelmeta_build(sx_context*c){bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_BLITZ3D_B3D:ok=sxmo_b3d(c);break;case XX_FILE_TYPE_MILKSHAPE_MS3D:ok=sxmo_ms3d(c);break;case XX_FILE_TYPE_NINTENDO_BCH:ok=sxmo_bch(c);break;case XX_FILE_TYPE_OGRE_MESH:ok=sxmo_ogre_mesh(c);break;case XX_FILE_TYPE_BLENDER_BLEND:ok=sxmo_blend(c);break;case XX_FILE_TYPE_AUTODESK_FBX:ok=sxmo_fbx(c);break;case XX_FILE_TYPE_AUTODESK_3DS:ok=sxmo_3ds(c);break;case XX_FILE_TYPE_LIGHTWAVE_LWO2:ok=sxmo_lwo(c);break;case XX_FILE_TYPE_SPRING_S3O:ok=sxmo_s3o(c);break;case XX_FILE_TYPE_STEREOLITHOGRAPHY_STL:ok=sxmo_stl(c);break;case XX_FILE_TYPE_OPENCTM_MESH:ok=sxmo_ctm(c);break;case XX_FILE_TYPE_QUBICLE_QB:ok=sxmo_qb(c);break;case XX_FILE_TYPE_TERRAGEN_TER:ok=sxmo_ter(c);break;case XX_FILE_TYPE_MMD_PMX:ok=sxmo_pmx(c);break;case XX_FILE_TYPE_OGRE_SKELETON:ok=sxmo_skeleton(c);break;case XX_FILE_TYPE_CAL3D_SKELETON:ok=sxmo_csf(c);break;default:break;}return ok&&c->count>0&&sxmo_finish(c);}
