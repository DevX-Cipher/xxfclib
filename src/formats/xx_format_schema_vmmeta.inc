/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical VM container metadata. Encoded payloads remain raw. */

static const xx_data_struct_field_desc sx_vm_java_class_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("minor_version","uint16",4,2,SX_ID),
    SX_FIELD("major_version","uint16",6,2,SX_ID),
    SX_FIELD("constant_pool_count","uint16",8,2,SX_COUNT_PROP),
};
static const sx_layout sx_vm_java_class_header = {0x60160001U,"java_class_header",sx_vm_java_class_header_fields,SX_COUNT(sx_vm_java_class_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_utf8_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("byte_length","uint16",1,2,SX_SIZE),
};
static const sx_layout sx_vm_java_constant_utf8 = {0x60160002U,"java_constant_utf8",sx_vm_java_constant_utf8_fields,SX_COUNT(sx_vm_java_constant_utf8_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_integer_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("value","int32",1,4,SX_NONE),
};
static const sx_layout sx_vm_java_constant_integer = {0x60160003U,"java_constant_integer",sx_vm_java_constant_integer_fields,SX_COUNT(sx_vm_java_constant_integer_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_float_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("ieee754_bits","uint32",1,4,SX_NONE),
};
static const sx_layout sx_vm_java_constant_float = {0x60160004U,"java_constant_float",sx_vm_java_constant_float_fields,SX_COUNT(sx_vm_java_constant_float_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_long_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("high_bytes","uint32",1,4,SX_NONE),
    SX_FIELD("low_bytes","uint32",5,4,SX_NONE),
};
static const sx_layout sx_vm_java_constant_long = {0x60160005U,"java_constant_long",sx_vm_java_constant_long_fields,SX_COUNT(sx_vm_java_constant_long_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_double_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("high_bytes","uint32",1,4,SX_NONE),
    SX_FIELD("low_bytes","uint32",5,4,SX_NONE),
};
static const sx_layout sx_vm_java_constant_double = {0x60160006U,"java_constant_double",sx_vm_java_constant_double_fields,SX_COUNT(sx_vm_java_constant_double_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_class_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("name_index","uint16",1,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_class = {0x60160007U,"java_constant_class",sx_vm_java_constant_class_fields,SX_COUNT(sx_vm_java_constant_class_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_string_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("string_index","uint16",1,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_string = {0x60160008U,"java_constant_string",sx_vm_java_constant_string_fields,SX_COUNT(sx_vm_java_constant_string_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_method_type_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("descriptor_index","uint16",1,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_method_type = {0x60160009U,"java_constant_method_type",sx_vm_java_constant_method_type_fields,SX_COUNT(sx_vm_java_constant_method_type_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_module_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("name_index","uint16",1,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_module = {0x6016000aU,"java_constant_module",sx_vm_java_constant_module_fields,SX_COUNT(sx_vm_java_constant_module_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_package_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("name_index","uint16",1,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_package = {0x6016000bU,"java_constant_package",sx_vm_java_constant_package_fields,SX_COUNT(sx_vm_java_constant_package_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_fieldref_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("class_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_fieldref = {0x6016000cU,"java_constant_fieldref",sx_vm_java_constant_fieldref_fields,SX_COUNT(sx_vm_java_constant_fieldref_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_methodref_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("class_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_methodref = {0x6016000dU,"java_constant_methodref",sx_vm_java_constant_methodref_fields,SX_COUNT(sx_vm_java_constant_methodref_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_interface_methodref_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("class_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_interface_methodref = {0x6016000eU,"java_constant_interface_methodref",sx_vm_java_constant_interface_methodref_fields,SX_COUNT(sx_vm_java_constant_interface_methodref_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_name_and_type_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("name_index","uint16",1,2,SX_ID),
    SX_FIELD("descriptor_index","uint16",3,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_name_and_type = {0x6016000fU,"java_constant_name_and_type",sx_vm_java_constant_name_and_type_fields,SX_COUNT(sx_vm_java_constant_name_and_type_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_dynamic_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("bootstrap_method_attr_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_dynamic = {0x60160010U,"java_constant_dynamic",sx_vm_java_constant_dynamic_fields,SX_COUNT(sx_vm_java_constant_dynamic_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_invoke_dynamic_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("bootstrap_method_attr_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_invoke_dynamic = {0x60160011U,"java_constant_invoke_dynamic",sx_vm_java_constant_invoke_dynamic_fields,SX_COUNT(sx_vm_java_constant_invoke_dynamic_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_constant_method_handle_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("reference_kind","uint8",1,1,SX_ID),
    SX_FIELD("reference_index","uint16",2,2,SX_ID),
};
static const sx_layout sx_vm_java_constant_method_handle = {0x60160012U,"java_constant_method_handle",sx_vm_java_constant_method_handle_fields,SX_COUNT(sx_vm_java_constant_method_handle_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_class_identity_fields[] = {
    SX_FIELD("access_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("this_class","uint16",2,2,SX_ID),
    SX_FIELD("super_class","uint16",4,2,SX_ID),
    SX_FIELD("interfaces_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sx_vm_java_class_identity = {0x60160013U,"java_class_identity",sx_vm_java_class_identity_fields,SX_COUNT(sx_vm_java_class_identity_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_interface_fields[] = {
    SX_FIELD("class_index","uint16",0,2,SX_ID),
};
static const sx_layout sx_vm_java_interface = {0x60160014U,"java_interface",sx_vm_java_interface_fields,SX_COUNT(sx_vm_java_interface_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_fields_count_fields[] = {
    SX_FIELD("fields_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sx_vm_java_fields_count = {0x60160015U,"java_fields_count",sx_vm_java_fields_count_fields,SX_COUNT(sx_vm_java_fields_count_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_methods_count_fields[] = {
    SX_FIELD("methods_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sx_vm_java_methods_count = {0x60160016U,"java_methods_count",sx_vm_java_methods_count_fields,SX_COUNT(sx_vm_java_methods_count_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_attributes_count_fields[] = {
    SX_FIELD("attributes_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sx_vm_java_attributes_count = {0x60160017U,"java_attributes_count",sx_vm_java_attributes_count_fields,SX_COUNT(sx_vm_java_attributes_count_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_field_info_fields[] = {
    SX_FIELD("access_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("name_index","uint16",2,2,SX_ID),
    SX_FIELD("descriptor_index","uint16",4,2,SX_ID),
    SX_FIELD("attributes_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sx_vm_java_field_info = {0x60160018U,"java_field_info",sx_vm_java_field_info_fields,SX_COUNT(sx_vm_java_field_info_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_method_info_fields[] = {
    SX_FIELD("access_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("name_index","uint16",2,2,SX_ID),
    SX_FIELD("descriptor_index","uint16",4,2,SX_ID),
    SX_FIELD("attributes_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sx_vm_java_method_info = {0x60160019U,"java_method_info",sx_vm_java_method_info_fields,SX_COUNT(sx_vm_java_method_info_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_java_attribute_info_fields[] = {
    SX_FIELD("attribute_name_index","uint16",0,2,SX_ID),
    SX_FIELD("attribute_length","uint32",2,4,SX_SIZE),
};
static const sx_layout sx_vm_java_attribute_info = {0x6016001aU,"java_attribute_info",sx_vm_java_attribute_info_fields,SX_COUNT(sx_vm_java_attribute_info_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_lua51_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_ID),
    SX_FIELD("format","uint8",5,1,SX_ID),
    SX_FIELD("little_endian","uint8",6,1,SX_ID),
    SX_FIELD("integer_size","uint8",7,1,SX_SIZE),
    SX_FIELD("size_t_size","uint8",8,1,SX_SIZE),
    SX_FIELD("instruction_size","uint8",9,1,SX_SIZE),
    SX_FIELD("number_size","uint8",10,1,SX_SIZE),
    SX_FIELD("integral_numbers","uint8",11,1,SX_ID),
};
static const sx_layout sx_vm_lua51_header = {0x6016001bU,"lua51_header",sx_vm_lua51_header_fields,SX_COUNT(sx_vm_lua51_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_prototype_fields[] = {
    SX_FIELD("first_line","int32",0,4,SX_NONE),
    SX_FIELD("last_line","int32",4,4,SX_NONE),
    SX_FIELD("upvalue_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("parameter_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("vararg_flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("maximum_stack_size","uint8",11,1,SX_COUNT_PROP),
};
static const sx_layout sx_vm_lua51_prototype = {0x6016001cU,"lua51_prototype",sx_vm_lua51_prototype_fields,SX_COUNT(sx_vm_lua51_prototype_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_code_count_fields[] = {
    SX_FIELD("code_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_lua51_code_count = {0x6016001dU,"lua51_code_count",sx_vm_lua51_code_count_fields,SX_COUNT(sx_vm_lua51_code_count_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_constants_count_fields[] = {
    SX_FIELD("constants_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_lua51_constants_count = {0x6016001eU,"lua51_constants_count",sx_vm_lua51_constants_count_fields,SX_COUNT(sx_vm_lua51_constants_count_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_prototypes_count_fields[] = {
    SX_FIELD("prototypes_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_lua51_prototypes_count = {0x6016001fU,"lua51_prototypes_count",sx_vm_lua51_prototypes_count_fields,SX_COUNT(sx_vm_lua51_prototypes_count_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_lineinfo_count_fields[] = {
    SX_FIELD("lineinfo_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_lua51_lineinfo_count = {0x60160020U,"lua51_lineinfo_count",sx_vm_lua51_lineinfo_count_fields,SX_COUNT(sx_vm_lua51_lineinfo_count_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_locals_count_fields[] = {
    SX_FIELD("locals_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_lua51_locals_count = {0x60160021U,"lua51_locals_count",sx_vm_lua51_locals_count_fields,SX_COUNT(sx_vm_lua51_locals_count_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_upvalues_count_fields[] = {
    SX_FIELD("upvalues_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_lua51_upvalues_count = {0x60160022U,"lua51_upvalues_count",sx_vm_lua51_upvalues_count_fields,SX_COUNT(sx_vm_lua51_upvalues_count_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_string32_fields[] = {
    SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sx_vm_lua51_string32 = {0x60160023U,"lua51_string32",sx_vm_lua51_string32_fields,SX_COUNT(sx_vm_lua51_string32_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_string64_fields[] = {
    SX_FIELD("byte_length","uint64",0,8,SX_SIZE),
};
static const sx_layout sx_vm_lua51_string64 = {0x60160024U,"lua51_string64",sx_vm_lua51_string64_fields,SX_COUNT(sx_vm_lua51_string64_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_constant_tag_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
};
static const sx_layout sx_vm_lua51_constant_tag = {0x60160025U,"lua51_constant_tag",sx_vm_lua51_constant_tag_fields,SX_COUNT(sx_vm_lua51_constant_tag_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_boolean_fields[] = {
    SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sx_vm_lua51_boolean = {0x60160026U,"lua51_boolean",sx_vm_lua51_boolean_fields,SX_COUNT(sx_vm_lua51_boolean_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_number_bits_fields[] = {
    SX_FIELD("ieee754_bits","uint64",0,8,SX_NONE),
};
static const sx_layout sx_vm_lua51_number_bits = {0x60160027U,"lua51_number_bits",sx_vm_lua51_number_bits_fields,SX_COUNT(sx_vm_lua51_number_bits_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_instruction_fields[] = {
    SX_FIELD("encoded_instruction","uint32",0,4,SX_NONE),
};
static const sx_layout sx_vm_lua51_instruction = {0x60160028U,"lua51_instruction",sx_vm_lua51_instruction_fields,SX_COUNT(sx_vm_lua51_instruction_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_setlist_extra_fields[] = {
    SX_FIELD("block_index","uint32",0,4,SX_NONE),
};
static const sx_layout sx_vm_lua51_setlist_extra = {0x60160029U,"lua51_setlist_extra",sx_vm_lua51_setlist_extra_fields,SX_COUNT(sx_vm_lua51_setlist_extra_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_lineinfo_fields[] = {
    SX_FIELD("source_line","int32",0,4,SX_NONE),
};
static const sx_layout sx_vm_lua51_lineinfo = {0x6016002aU,"lua51_lineinfo",sx_vm_lua51_lineinfo_fields,SX_COUNT(sx_vm_lua51_lineinfo_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_lua51_local_range_fields[] = {
    SX_FIELD("start_instruction_index","int32",0,4,SX_NONE),
    SX_FIELD("end_instruction_index","int32",4,4,SX_NONE),
};
static const sx_layout sx_vm_lua51_local_range = {0x6016002bU,"lua51_local_range",sx_vm_lua51_local_range_fields,SX_COUNT(sx_vm_lua51_local_range_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_beam_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("form_size","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sx_vm_beam_header = {0x6016002cU,"beam_header",sx_vm_beam_header_fields,SX_COUNT(sx_vm_beam_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_beam_chunk_header_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sx_vm_beam_chunk_header = {0x6016002dU,"beam_chunk_header",sx_vm_beam_chunk_header_fields,SX_COUNT(sx_vm_beam_chunk_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_beam_code_header_fields[] = {
    SX_FIELD("subheader_size","uint32",0,4,SX_SIZE),
    SX_FIELD("instruction_set","uint32",4,4,SX_ID),
    SX_FIELD("opcode_maximum","uint32",8,4,SX_ID),
    SX_FIELD("label_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("function_count","uint32",16,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_beam_code_header = {0x6016002eU,"beam_code_header",sx_vm_beam_code_header_fields,SX_COUNT(sx_vm_beam_code_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_beam_atom_count_fields[] = {
    SX_FIELD("atom_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_beam_atom_count = {0x6016002fU,"beam_atom_count",sx_vm_beam_atom_count_fields,SX_COUNT(sx_vm_beam_atom_count_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_beam_atom_length_fields[] = {
    SX_FIELD("byte_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sx_vm_beam_atom_length = {0x60160030U,"beam_atom_length",sx_vm_beam_atom_length_fields,SX_COUNT(sx_vm_beam_atom_length_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_beam_table_count_fields[] = {
    SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_beam_table_count = {0x60160031U,"beam_table_count",sx_vm_beam_table_count_fields,SX_COUNT(sx_vm_beam_table_count_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_beam_import_fields[] = {
    SX_FIELD("module_atom_index","uint32",0,4,SX_ID),
    SX_FIELD("function_atom_index","uint32",4,4,SX_ID),
    SX_FIELD("arity","uint32",8,4,SX_COUNT_PROP),
};
static const sx_layout sx_vm_beam_import = {0x60160032U,"beam_import",sx_vm_beam_import_fields,SX_COUNT(sx_vm_beam_import_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_beam_export_fields[] = {
    SX_FIELD("function_atom_index","uint32",0,4,SX_ID),
    SX_FIELD("arity","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("label_index","uint32",8,4,SX_ID),
};
static const sx_layout sx_vm_beam_export = {0x60160033U,"beam_export",sx_vm_beam_export_fields,SX_COUNT(sx_vm_beam_export_fields),SX_BE};

static const xx_data_struct_field_desc sx_vm_cli_metadata_root_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_ID),
    SX_FIELD("minor_version","uint16",6,2,SX_ID),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
    SX_FIELD("version_length","uint32",12,4,SX_SIZE),
};
static const sx_layout sx_vm_cli_metadata_root = {0x60160034U,"cli_metadata_root",sx_vm_cli_metadata_root_fields,SX_COUNT(sx_vm_cli_metadata_root_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_cli_storage_header_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_RESERVED),
    SX_FIELD("stream_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sx_vm_cli_storage_header = {0x60160035U,"cli_storage_header",sx_vm_cli_storage_header_fields,SX_COUNT(sx_vm_cli_storage_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_vm_cli_stream_header_fields[] = {
    SX_FIELD("stream_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("stream_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sx_vm_cli_stream_header = {0x60160036U,"cli_stream_header",sx_vm_cli_stream_header_fields,SX_COUNT(sx_vm_cli_stream_header_fields),SX_LE};

static const sx_layout *const sx_vmmeta_layouts[] = {
    &sx_vm_java_class_header,
    &sx_vm_java_constant_utf8,
    &sx_vm_java_constant_integer,
    &sx_vm_java_constant_float,
    &sx_vm_java_constant_long,
    &sx_vm_java_constant_double,
    &sx_vm_java_constant_class,
    &sx_vm_java_constant_string,
    &sx_vm_java_constant_method_type,
    &sx_vm_java_constant_module,
    &sx_vm_java_constant_package,
    &sx_vm_java_constant_fieldref,
    &sx_vm_java_constant_methodref,
    &sx_vm_java_constant_interface_methodref,
    &sx_vm_java_constant_name_and_type,
    &sx_vm_java_constant_dynamic,
    &sx_vm_java_constant_invoke_dynamic,
    &sx_vm_java_constant_method_handle,
    &sx_vm_java_class_identity,
    &sx_vm_java_interface,
    &sx_vm_java_fields_count,
    &sx_vm_java_methods_count,
    &sx_vm_java_attributes_count,
    &sx_vm_java_field_info,
    &sx_vm_java_method_info,
    &sx_vm_java_attribute_info,
    &sx_vm_lua51_header,
    &sx_vm_lua51_prototype,
    &sx_vm_lua51_code_count,
    &sx_vm_lua51_constants_count,
    &sx_vm_lua51_prototypes_count,
    &sx_vm_lua51_lineinfo_count,
    &sx_vm_lua51_locals_count,
    &sx_vm_lua51_upvalues_count,
    &sx_vm_lua51_string32,
    &sx_vm_lua51_string64,
    &sx_vm_lua51_constant_tag,
    &sx_vm_lua51_boolean,
    &sx_vm_lua51_number_bits,
    &sx_vm_lua51_instruction,
    &sx_vm_lua51_setlist_extra,
    &sx_vm_lua51_lineinfo,
    &sx_vm_lua51_local_range,
    &sx_vm_beam_header,
    &sx_vm_beam_chunk_header,
    &sx_vm_beam_code_header,
    &sx_vm_beam_atom_count,
    &sx_vm_beam_atom_length,
    &sx_vm_beam_table_count,
    &sx_vm_beam_import,
    &sx_vm_beam_export,
    &sx_vm_cli_metadata_root,
    &sx_vm_cli_storage_header,
    &sx_vm_cli_stream_header,
};

static bool sx_vmmeta_supports(xx_file_type_t type)
{
    return type==XX_FILE_TYPE_JAVA_CLASS||type==XX_FILE_TYPE_LUA_BYTECODE51||type==XX_FILE_TYPE_ERLANG_BEAM||type==XX_FILE_TYPE_DOTNET_METADATA;
}
static bool sx_vm_span(sx_context *c,uint64_t at,uint64_t n){return at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
static bool sx_vm_get16(sx_context *c,uint64_t *at,uint16_t *v){if(!sx_vm_span(c,*at,2)||!sx_u16(c,(int64_t)*at,true,v))return false;*at+=2;return true;}
static bool sx_vm_count(sx_context *c,uint64_t *at,const sx_layout *l,uint32_t *v)
{
    if(!sx_vm_span(c,*at,4)||!sx_u32(c,(int64_t)*at,false,v)||!sx_add(c,l,(int64_t)*at,4))return false;*at+=4;return true;
}
static bool sx_vm_java_attributes(sx_context *c,uint64_t *at,uint16_t count)
{
    for(uint16_t i=0;i<count;i++){
        uint8_t b[6];if(!sx_vm_span(c,*at,6)||!sx_read(c,(int64_t)*at,b,6))return false;
        uint32_t n=xx_data_get_u32(b,6,2,true);if(!sx_vm_span(c,*at+6,n)||!sx_add(c,&sx_vm_java_attribute_info,(int64_t)*at,6))return false;*at+=6+(uint64_t)n;
    }return true;
}
static bool sx_vm_java(sx_context *c)
{
    uint16_t total;uint64_t at=8;
    if(!sx_vm_get16(c,&at,&total)||total<2||!sx_add(c,&sx_vm_java_class_header,0,10))return false;
    for(uint32_t i=1;i<total;i++){
        uint8_t tag;uint32_t n=0;const sx_layout *l=NULL;
        if(!sx_vm_span(c,at,1)||!sx_read(c,(int64_t)at,&tag,1))return false;
        switch(tag){
        case 1:{uint16_t len;if(!sx_vm_span(c,at,3)||!sx_u16(c,(int64_t)at+1,true,&len)||!sx_vm_span(c,at+3,len)||!sx_add(c,&sx_vm_java_constant_utf8,(int64_t)at,3))return false;at+=3+(uint64_t)len;continue;}
        case 3:l=&sx_vm_java_constant_integer;n=5;break;
        case 4:l=&sx_vm_java_constant_float;n=5;break;
        case 5:l=&sx_vm_java_constant_long;n=9;if(++i>=total)return false;break;
        case 6:l=&sx_vm_java_constant_double;n=9;if(++i>=total)return false;break;
        case 7:l=&sx_vm_java_constant_class;n=3;break;
        case 8:l=&sx_vm_java_constant_string;n=3;break;
        case 9:l=&sx_vm_java_constant_fieldref;n=5;break;
        case 10:l=&sx_vm_java_constant_methodref;n=5;break;
        case 11:l=&sx_vm_java_constant_interface_methodref;n=5;break;
        case 12:l=&sx_vm_java_constant_name_and_type;n=5;break;
        case 15:l=&sx_vm_java_constant_method_handle;n=4;break;
        case 16:l=&sx_vm_java_constant_method_type;n=3;break;
        case 17:l=&sx_vm_java_constant_dynamic;n=5;break;
        case 18:l=&sx_vm_java_constant_invoke_dynamic;n=5;break;
        case 19:l=&sx_vm_java_constant_module;n=3;break;
        case 20:l=&sx_vm_java_constant_package;n=3;break;
        default:return false;
        }
        if(!sx_add(c,l,(int64_t)at,n))return false;at+=n;
    }
    uint16_t count;
    if(!sx_vm_span(c,at,8)||!sx_u16(c,(int64_t)at+6,true,&count)||!sx_add(c,&sx_vm_java_class_identity,(int64_t)at,8))return false;at+=8;
    if(!sx_vm_span(c,at,(uint64_t)count*2)||!sx_table(c,&sx_vm_java_interface,(int64_t)at,2,count))return false;at+=(uint64_t)count*2;
    for(unsigned k=0;k<2;k++){
        if(!sx_add(c,k?&sx_vm_java_methods_count:&sx_vm_java_fields_count,(int64_t)at,2)||!sx_vm_get16(c,&at,&count))return false;
        for(uint16_t j=0;j<count;j++){
            uint16_t attrs;if(!sx_vm_span(c,at,8)||!sx_u16(c,(int64_t)at+6,true,&attrs)||!sx_add(c,k?&sx_vm_java_method_info:&sx_vm_java_field_info,(int64_t)at,8))return false;at+=8;
            if(!sx_vm_java_attributes(c,&at,attrs))return false;
        }
    }
    if(!sx_add(c,&sx_vm_java_attributes_count,(int64_t)at,2)||!sx_vm_get16(c,&at,&count)||!sx_vm_java_attributes(c,&at,count))return false;
    return at<=(uint64_t)c->size;
}
typedef struct sx_vm_lua_state{sx_context *c;uint64_t at,instructions;unsigned width,prototypes;}sx_vm_lua_state;
static bool sx_vm_lua_string(sx_vm_lua_state *s)
{
    uint64_t size=0;
    if(!sx_vm_span(s->c,s->at,s->width))return false;
    if(s->width==4){uint32_t n;if(!sx_u32(s->c,(int64_t)s->at,false,&n))return false;size=n;}
    else if(!sx_u64(s->c,(int64_t)s->at,false,&size))return false;
    if(size>16777216||!sx_vm_span(s->c,s->at+s->width,size)||!sx_add(s->c,s->width==4?&sx_vm_lua51_string32:&sx_vm_lua51_string64,(int64_t)s->at,s->width))return false;
    s->at+=s->width+size;return true;
}
static bool sx_vm_lua_proto(sx_vm_lua_state *s,unsigned depth)
{
    sx_context *c=s->c;uint32_t count;
    if(depth>32||++s->prototypes>1024||!sx_vm_lua_string(s)||!sx_add(c,&sx_vm_lua51_prototype,(int64_t)s->at,12))return false;s->at+=12;
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_code_count,&count)||!count||count>65536||s->instructions+count>1000000||!sx_vm_span(c,s->at,(uint64_t)count*4))return false;
    uint32_t run=0;
    for(uint32_t i=0;i<count;i++){
        uint32_t word;if(!sx_u32(c,(int64_t)(s->at+(uint64_t)i*4),false,&word))return false;
        if((word&63)>37)return false;
        if((word&63)==34&&((word>>14)&511)==0){
            /* SETLIST C=0 consumes a full data word, not another opcode. */
            if(i+1>=count||!sx_table(c,&sx_vm_lua51_instruction,(int64_t)(s->at+(uint64_t)run*4),4,i-run+1)||!sx_add(c,&sx_vm_lua51_setlist_extra,(int64_t)(s->at+(uint64_t)(i+1)*4),4))return false;
            i++;run=i+1;
        }
    }
    if(run<count&&!sx_table(c,&sx_vm_lua51_instruction,(int64_t)(s->at+(uint64_t)run*4),4,count-run))return false;
    s->at+=(uint64_t)count*4;s->instructions+=count;
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_constants_count,&count)||count>65536)return false;
    for(uint32_t i=0;i<count;i++){
        uint8_t t;if(!sx_read(c,(int64_t)s->at,&t,1)||!sx_add(c,&sx_vm_lua51_constant_tag,(int64_t)s->at,1))return false;s->at++;
        if(t==0)continue;
        if(t==1){if(!sx_add(c,&sx_vm_lua51_boolean,(int64_t)s->at,1))return false;s->at++;}
        else if(t==3){if(!sx_add(c,&sx_vm_lua51_number_bits,(int64_t)s->at,8))return false;s->at+=8;}
        else if(t==4){if(!sx_vm_lua_string(s))return false;}
        else return false;
    }
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_prototypes_count,&count)||count>1024)return false;
    for(uint32_t i=0;i<count;i++)if(!sx_vm_lua_proto(s,depth+1))return false;
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_lineinfo_count,&count)||count>65536||!sx_table(c,&sx_vm_lua51_lineinfo,(int64_t)s->at,4,count))return false;s->at+=(uint64_t)count*4;
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_locals_count,&count)||count>65536)return false;
    for(uint32_t i=0;i<count;i++){if(!sx_vm_lua_string(s)||!sx_add(c,&sx_vm_lua51_local_range,(int64_t)s->at,8))return false;s->at+=8;}
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_upvalues_count,&count)||count>60)return false;
    for(uint32_t i=0;i<count;i++)if(!sx_vm_lua_string(s))return false;
    return true;
}
static bool sx_vm_lua(sx_context *c)
{
    uint8_t h[12];if(!sx_read(c,0,h,12)||h[6]!=1||h[7]!=4||(h[8]!=4&&h[8]!=8)||h[9]!=4||h[10]!=8||h[11]||!sx_add(c,&sx_vm_lua51_header,0,12))return false;
    sx_vm_lua_state s={c,12,0,h[8],0};return sx_vm_lua_proto(&s,0)&&s.at==(uint64_t)c->size;
}
static bool sx_vm_beam(sx_context *c)
{
    uint32_t form_size;if(!sx_u32(c,4,true,&form_size)||form_size<4||!sx_vm_span(c,8,form_size)||!sx_add(c,&sx_vm_beam_header,0,12))return false;
    uint64_t at=12,end=8+(uint64_t)form_size;
    for(unsigned i=0;at<end&&i<128;i++){
        uint8_t b[8];if(end-at<8||!sx_read(c,(int64_t)at,b,8))return false;
        uint32_t n=xx_data_get_u32(b,8,4,true);uint64_t padded=((uint64_t)n+3)&~UINT64_C(3),q=at+8;
        if(padded>end-q||!sx_add(c,&sx_vm_beam_chunk_header,(int64_t)at,8))return false;
        if(!xx_rt_memcmp(b,"Code",4)){if(n<20||!sx_add(c,&sx_vm_beam_code_header,(int64_t)q,20))return false;}
        else if(!xx_rt_memcmp(b,"Atom",4)||!xx_rt_memcmp(b,"AtU8",4)){
            uint32_t count;if(n<4||!sx_u32(c,(int64_t)q,true,&count)||count>65536||!sx_add(c,&sx_vm_beam_atom_count,(int64_t)q,4))return false;uint64_t p=q+4;
            for(uint32_t k=0;k<count;k++){uint8_t len;if(p>=q+n||!sx_read(c,(int64_t)p,&len,1)||len>q+n-p-1||!sx_add(c,&sx_vm_beam_atom_length,(int64_t)p,1))return false;p+=1+(uint64_t)len;}
            if(p!=q+n)return false;
        }else if(!xx_rt_memcmp(b,"ImpT",4)||!xx_rt_memcmp(b,"ExpT",4)||!xx_rt_memcmp(b,"LocT",4)){
            uint32_t count=0;bool optional=!xx_rt_memcmp(b,"LocT",4);
            /* Native validation authenticates ImpT/ExpT. LocT is optional and
             * not validated there, so malformed optional content stays raw. */
            if(n>=4&&sx_u32(c,(int64_t)q,true,&count)&&count<=65536&&n==4+(uint64_t)count*12){
                if(!sx_add(c,&sx_vm_beam_table_count,(int64_t)q,4)||!sx_table(c,!xx_rt_memcmp(b,"ImpT",4)?&sx_vm_beam_import:&sx_vm_beam_export,(int64_t)q+4,12,count))return false;
            }else if(!optional)return false;
        }
        at=q+padded;
    }return at==end;
}
static bool sx_vm_dotnet(sx_context *c)
{
    uint32_t len;uint16_t count;uint64_t at;
    if(!sx_u32(c,12,false,&len)||!len||len>256||len%4||!sx_vm_span(c,16,len)||!sx_add(c,&sx_vm_cli_metadata_root,0,16))return false;at=16+len;
    if(!sx_vm_span(c,at,4)||!sx_u16(c,(int64_t)at+2,false,&count)||!count||count>64||!sx_add(c,&sx_vm_cli_storage_header,(int64_t)at,4))return false;at+=4;
    for(uint16_t i=0;i<count;i++){
        if(!sx_add(c,&sx_vm_cli_stream_header,(int64_t)at,8))return false;at+=8;bool ended=false;
        for(unsigned j=0;j<32;j++){uint8_t b;if(!sx_read(c,(int64_t)at++,&b,1))return false;if(!b){ended=true;break;}}
        if(!ended)return false;at=(at+3)&~UINT64_C(3);if(!sx_vm_span(c,at,0))return false;
    }return true;
}
static void sx_vm_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){
        xx_data_struct d=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>d.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=d;
    }
}
static bool sx_vm_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;sx_vm_sort(c);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end||(at>end&&!sx_raw(c,end,at-end)))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;sx_vm_sort(c);return !c->failed;
}
static bool sx_vmmeta_build(sx_context *c)
{
    if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;
    switch(c->f->file_type){case XX_FILE_TYPE_JAVA_CLASS:ok=sx_vm_java(c);break;case XX_FILE_TYPE_LUA_BYTECODE51:ok=sx_vm_lua(c);break;case XX_FILE_TYPE_ERLANG_BEAM:ok=sx_vm_beam(c);break;case XX_FILE_TYPE_DOTNET_METADATA:ok=sx_vm_dotnet(c);break;default:break;}
    return ok&&sx_vm_finish(c);
}
typedef struct sx_vm_flag {uint64_t mask;const wchar_t *name;} sx_vm_flag;
static bool sx_vm_flags(xx_data_struct_record *r,const sx_vm_flag *flags,size_t count)
{
    wchar_t out[256];size_t used=0;uint64_t value=xx_var_get_u64(&r->value),known=0;
    for(size_t i=0;i<count;i++) {
        known|=flags[i].mask;if(!(value&flags[i].mask))continue;
        if(used+32>=SX_COUNT(out))return false;
        if(used)out[used++]=L'|';
        const wchar_t *p=flags[i].name;while(*p&&used+24<SX_COUNT(out))out[used++]=*p++;
        if(*p)return false;
    }
    uint64_t unknown=value&~known;
    if(unknown) {
        if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';
        bool started=false;
        for(int shift=60;shift>=0;shift-=4) {unsigned digit=(unsigned)((unknown>>shift)&15);if(digit||started||!shift){out[used++]=L"0123456789ABCDEF"[digit];started=true;}}
    }
    if(!used)out[used++]=L'0';out[used]=0;
    return xx_data_struct_record_set_comment(r,out);
}
static bool sx_vmmeta_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60160000U||id>=0x60170000U)return true;
    const wchar_t *text=NULL;
    if(!xx_rt_wcscmp(r->name,L"access_flags")) {
        static const sx_vm_flag cls[]={{1,L"ACC_PUBLIC"},{16,L"ACC_FINAL"},{32,L"ACC_SUPER"},{512,L"ACC_INTERFACE"},{1024,L"ACC_ABSTRACT"},{4096,L"ACC_SYNTHETIC"},{8192,L"ACC_ANNOTATION"},{16384,L"ACC_ENUM"},{32768,L"ACC_MODULE"}};
        static const sx_vm_flag fld[]={{1,L"ACC_PUBLIC"},{2,L"ACC_PRIVATE"},{4,L"ACC_PROTECTED"},{8,L"ACC_STATIC"},{16,L"ACC_FINAL"},{64,L"ACC_VOLATILE"},{128,L"ACC_TRANSIENT"},{4096,L"ACC_SYNTHETIC"},{16384,L"ACC_ENUM"}};
        static const sx_vm_flag met[]={{1,L"ACC_PUBLIC"},{2,L"ACC_PRIVATE"},{4,L"ACC_PROTECTED"},{8,L"ACC_STATIC"},{16,L"ACC_FINAL"},{32,L"ACC_SYNCHRONIZED"},{64,L"ACC_BRIDGE"},{128,L"ACC_VARARGS"},{256,L"ACC_NATIVE"},{1024,L"ACC_ABSTRACT"},{2048,L"ACC_STRICT (major versions46-60)"},{4096,L"ACC_SYNTHETIC"}};
        if(id==sx_vm_java_class_identity.id)return sx_vm_flags(r,cls,SX_COUNT(cls));
        if(id==sx_vm_java_field_info.id)return sx_vm_flags(r,fld,SX_COUNT(fld));
        if(id==sx_vm_java_method_info.id)return sx_vm_flags(r,met,SX_COUNT(met));
    }
    if(id==sx_vm_lua51_prototype.id&&!xx_rt_wcscmp(r->name,L"vararg_flags")) {
        static const sx_vm_flag flags[]={{1,L"VARARG_HASARG"},{2,L"VARARG_ISVARARG"},{4,L"VARARG_NEEDSARG"}};return sx_vm_flags(r,flags,SX_COUNT(flags));
    }
    if(!xx_rt_wcscmp(r->name,L"reference_kind")) {
        static const wchar_t *const kinds[]={L"",L"REF_getField",L"REF_getStatic",L"REF_putField",L"REF_putStatic",L"REF_invokeVirtual",L"REF_invokeStatic",L"REF_invokeSpecial",L"REF_newInvokeSpecial",L"REF_invokeInterface"};
        uint64_t v=xx_var_get_u64(&r->value);if(v&&v<SX_COUNT(kinds))text=kinds[v];
    }
    if(!xx_rt_wcscmp(r->name,L"tag")){
        switch(xx_var_get_u64(&r->value)){
        case 1:text=L"CONSTANT_Utf8";break;case 3:text=L"CONSTANT_Integer";break;case 4:text=L"CONSTANT_Float";break;case 5:text=L"CONSTANT_Long";break;case 6:text=L"CONSTANT_Double";break;case 7:text=L"CONSTANT_Class";break;case 8:text=L"CONSTANT_String";break;case 9:text=L"CONSTANT_Fieldref";break;case 10:text=L"CONSTANT_Methodref";break;case 11:text=L"CONSTANT_InterfaceMethodref";break;case 12:text=L"CONSTANT_NameAndType";break;case 15:text=L"CONSTANT_MethodHandle";break;case 16:text=L"CONSTANT_MethodType";break;case 17:text=L"CONSTANT_Dynamic";break;case 18:text=L"CONSTANT_InvokeDynamic";break;case 19:text=L"CONSTANT_Module";break;case 20:text=L"CONSTANT_Package";break;default:break;}
    }else if(id==sx_vm_lua51_constant_tag.id){switch(xx_var_get_u64(&r->value)){case 0:text=L"LUA_TNIL";break;case 1:text=L"LUA_TBOOLEAN";break;case 3:text=L"LUA_TNUMBER";break;case 4:text=L"LUA_TSTRING";break;default:break;}}
    else if(id==sx_vm_cli_storage_header.id&&!xx_rt_wcscmp(r->name,L"flags"))text=L"Reserved; must be zero";
    else if(!xx_rt_wcscmp(r->name,L"ieee754_bits"))text=L"Stored IEEE754 bit pattern";
    else if(!xx_rt_wcscmp(r->name,L"stream_offset"))text=L"Byte offset from the CLI metadata root";
    else if(!xx_rt_wcscmp(r->name,L"byte_length")&&(id==sx_vm_lua51_string32.id||id==sx_vm_lua51_string64.id))text=L"Stored string length including terminating zero; zero means no string";
    else if(!xx_rt_wcscmp(r->name,L"constant_pool_count"))text=L"Constant-pool index limit; long and double entries consume two indexes";
    else if(id==sx_vm_lua51_setlist_extra.id)text=L"SETLIST auxiliary block index; not an opcode or byte offset";
    else if(!xx_rt_wcscmp(r->name,L"encoded_instruction")){
        static const wchar_t *const ops[]={L"MOVE",L"LOADK",L"LOADBOOL",L"LOADNIL",L"GETUPVAL",L"GETGLOBAL",L"GETTABLE",L"SETGLOBAL",L"SETUPVAL",L"SETTABLE",L"NEWTABLE",L"SELF",L"ADD",L"SUB",L"MUL",L"DIV",L"MOD",L"POW",L"UNM",L"NOT",L"LEN",L"CONCAT",L"JMP",L"EQ",L"LT",L"LE",L"TEST",L"TESTSET",L"CALL",L"TAILCALL",L"RETURN",L"FORLOOP",L"FORPREP",L"TFORLOOP",L"SETLIST",L"CLOSE",L"CLOSURE",L"VARARG"};
        uint64_t v=xx_var_get_u64(&r->value)&63;if(v<SX_COUNT(ops))text=ops[v];
    }
    return !text||xx_data_struct_record_set_comment(r,text);
}
