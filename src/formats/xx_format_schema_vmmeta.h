/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The vmmeta schema family: what its family unit (xx_format_schema_vmmeta.c)
 * and its formats' data files share. Formats: Java class file; Lua 5.1 bytecode; Erlang BEAM; .NET metadata. */
#ifndef XX_FORMAT_SCHEMA_VMMETA_H
#define XX_FORMAT_SCHEMA_VMMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_vm_java_class_header;
extern const sx_layout sx_vm_java_constant_utf8;
extern const sx_layout sx_vm_java_constant_integer;
extern const sx_layout sx_vm_java_constant_float;
extern const sx_layout sx_vm_java_constant_long;
extern const sx_layout sx_vm_java_constant_double;
extern const sx_layout sx_vm_java_constant_class;
extern const sx_layout sx_vm_java_constant_string;
extern const sx_layout sx_vm_java_constant_method_type;
extern const sx_layout sx_vm_java_constant_module;
extern const sx_layout sx_vm_java_constant_package;
extern const sx_layout sx_vm_java_constant_fieldref;
extern const sx_layout sx_vm_java_constant_methodref;
extern const sx_layout sx_vm_java_constant_interface_methodref;
extern const sx_layout sx_vm_java_constant_name_and_type;
extern const sx_layout sx_vm_java_constant_dynamic;
extern const sx_layout sx_vm_java_constant_invoke_dynamic;
extern const sx_layout sx_vm_java_constant_method_handle;
extern const sx_layout sx_vm_java_class_identity;
extern const sx_layout sx_vm_java_interface;
extern const sx_layout sx_vm_java_fields_count;
extern const sx_layout sx_vm_java_methods_count;
extern const sx_layout sx_vm_java_attributes_count;
extern const sx_layout sx_vm_java_field_info;
extern const sx_layout sx_vm_java_method_info;
extern const sx_layout sx_vm_java_attribute_info;
extern const sx_layout sx_vm_lua51_header;
extern const sx_layout sx_vm_lua51_prototype;
extern const sx_layout sx_vm_lua51_code_count;
extern const sx_layout sx_vm_lua51_constants_count;
extern const sx_layout sx_vm_lua51_prototypes_count;
extern const sx_layout sx_vm_lua51_lineinfo_count;
extern const sx_layout sx_vm_lua51_locals_count;
extern const sx_layout sx_vm_lua51_upvalues_count;
extern const sx_layout sx_vm_lua51_string32;
extern const sx_layout sx_vm_lua51_string64;
extern const sx_layout sx_vm_lua51_constant_tag;
extern const sx_layout sx_vm_lua51_boolean;
extern const sx_layout sx_vm_lua51_number_bits;
extern const sx_layout sx_vm_lua51_instruction;
extern const sx_layout sx_vm_lua51_setlist_extra;
extern const sx_layout sx_vm_lua51_lineinfo;
extern const sx_layout sx_vm_lua51_local_range;
extern const sx_layout sx_vm_beam_header;
extern const sx_layout sx_vm_beam_chunk_header;
extern const sx_layout sx_vm_beam_code_header;
extern const sx_layout sx_vm_beam_atom_count;
extern const sx_layout sx_vm_beam_atom_length;
extern const sx_layout sx_vm_beam_table_count;
extern const sx_layout sx_vm_beam_import;
extern const sx_layout sx_vm_beam_export;
extern const sx_layout sx_vm_cli_metadata_root;
extern const sx_layout sx_vm_cli_storage_header;
extern const sx_layout sx_vm_cli_stream_header;
bool sx_vm_span(sx_context *c,uint64_t at,uint64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_java_class_build(sx_context *c);  /* executable/java_class/xx_java_class_data.c */
bool sx_lua_bytecode51_build(sx_context *c);  /* executable/lua_bytecode51/xx_lua_bytecode51_data.c */
bool sx_erlang_beam_build(sx_context *c);  /* executable/erlang_beam/xx_erlang_beam_data.c */
bool sx_dotnet_metadata_build(sx_context *c);  /* executable/dotnet_metadata/xx_dotnet_metadata_data.c */

#endif
