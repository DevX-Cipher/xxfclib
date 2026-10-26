/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical binary metadata. Scope and references: docs/data_struct_binary_scope.txt.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_b_spirv_header_le_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("generator", "uint32", 8, 4, SX_NONE),
    SX_FIELD("bound", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("schema", "uint32", 16, 4, SX_NONE),
};
static const sx_layout sx_b_spirv_header_le = { UINT32_C(0x60090001), "spirv_header_le", sx_b_spirv_header_le_fields, SX_COUNT(sx_b_spirv_header_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_spirv_instruction_le_fields[] = {
    SX_FIELD("opcode", "uint16", 0, 2, SX_ID),
    SX_FIELD("word_count", "uint16", 2, 2, SX_COUNT_PROP),
};
static const sx_layout sx_b_spirv_instruction_le = { UINT32_C(0x60090002), "spirv_instruction_le", sx_b_spirv_instruction_le_fields, SX_COUNT(sx_b_spirv_instruction_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_spirv_header_be_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("generator", "uint32", 8, 4, SX_NONE),
    SX_FIELD("bound", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("schema", "uint32", 16, 4, SX_NONE),
};
static const sx_layout sx_b_spirv_header_be = { UINT32_C(0x60090003), "spirv_header_be", sx_b_spirv_header_be_fields, SX_COUNT(sx_b_spirv_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_spirv_instruction_be_fields[] = {
    SX_FIELD("opcode", "uint16", 2, 2, SX_ID),
    SX_FIELD("word_count", "uint16", 0, 2, SX_COUNT_PROP),
};
static const sx_layout sx_b_spirv_instruction_be = { UINT32_C(0x60090004), "spirv_instruction_be", sx_b_spirv_instruction_be_fields, SX_COUNT(sx_b_spirv_instruction_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_dxbc_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("hash", "bytes", 4, 16, SX_CHECKSUM),
    SX_FIELD("version", "uint32", 20, 4, SX_NONE),
    SX_FIELD("total_size", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("chunk_count", "uint32", 28, 4, SX_COUNT_PROP),
};
static const sx_layout sx_b_dxbc_header = { UINT32_C(0x60090005), "dxbc_header", sx_b_dxbc_header_fields, SX_COUNT(sx_b_dxbc_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_dxbc_chunk_offset_fields[] = {
    SX_FIELD("chunk_offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sx_b_dxbc_chunk_offset = { UINT32_C(0x60090006), "dxbc_chunk_offset", sx_b_dxbc_chunk_offset_fields, SX_COUNT(sx_b_dxbc_chunk_offset_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_dxbc_chunk_header_fields[] = {
    SX_FIELD("fourcc", "char[4]", 0, 4, SX_ID),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_b_dxbc_chunk_header = { UINT32_C(0x60090007), "dxbc_chunk_header", sx_b_dxbc_chunk_header_fields, SX_COUNT(sx_b_dxbc_chunk_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_llvm_bitcode_wrapper_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("cpu_type", "uint32", 16, 4, SX_ID),
};
static const sx_layout sx_b_llvm_bitcode_wrapper = { UINT32_C(0x60090008), "llvm_bitcode_wrapper", sx_b_llvm_bitcode_wrapper_fields, SX_COUNT(sx_b_llvm_bitcode_wrapper_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_nintendo_3dsx_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("header_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("relocation_header_size", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("version", "uint32", 8, 4, SX_NONE),
    SX_FIELD("flags", "uint32", 12, 4, SX_FLAGS),
    SX_FIELD("code_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("rodata_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("data_size", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("bss_size", "uint32", 28, 4, SX_SIZE),
};
static const sx_layout sx_b_nintendo_3dsx_header = { UINT32_C(0x60090009), "nintendo_3dsx_header", sx_b_nintendo_3dsx_header_fields, SX_COUNT(sx_b_nintendo_3dsx_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_nintendo_3dsx_relocation_header_fields[] = {
    SX_FIELD("absolute_count", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("relative_count", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sx_b_nintendo_3dsx_relocation_header = { UINT32_C(0x6009000A), "nintendo_3dsx_relocation_header", sx_b_nintendo_3dsx_relocation_header_fields, SX_COUNT(sx_b_nintendo_3dsx_relocation_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_nintendo_3dsx_relocation_fields[] = {
    SX_FIELD("skip_words", "uint16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("patch_words", "uint16", 2, 2, SX_COUNT_PROP),
};
static const sx_layout sx_b_nintendo_3dsx_relocation = { UINT32_C(0x6009000B), "nintendo_3dsx_relocation", sx_b_nintendo_3dsx_relocation_fields, SX_COUNT(sx_b_nintendo_3dsx_relocation_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_psx_exe_header_fields[] = {
    SX_FIELD("magic", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("reserved", "bytes", 8, 8, SX_RESERVED),
    SX_FIELD("initial_pc", "uint32", 16, 4, SX_ADDRESS),
    SX_FIELD("initial_gp", "uint32", 20, 4, SX_ADDRESS),
    SX_FIELD("load_address", "uint32", 24, 4, SX_ADDRESS),
    SX_FIELD("text_size", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("data_address", "uint32", 32, 4, SX_ADDRESS),
    SX_FIELD("data_size", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("bss_address", "uint32", 40, 4, SX_ADDRESS),
    SX_FIELD("bss_size", "uint32", 44, 4, SX_SIZE),
    SX_FIELD("stack_base", "uint32", 48, 4, SX_ADDRESS),
    SX_FIELD("stack_offset", "int32", 52, 4, SX_OFFSET),
    SX_FIELD("saved_sp", "uint32", 56, 4, SX_ADDRESS),
    SX_FIELD("saved_fp", "uint32", 60, 4, SX_ADDRESS),
    SX_FIELD("saved_gp", "uint32", 64, 4, SX_ADDRESS),
    SX_FIELD("saved_ra", "uint32", 68, 4, SX_ADDRESS),
    SX_FIELD("saved_s0", "uint32", 72, 4, SX_NONE),
    SX_FIELD("marker", "bytes", 76, 1972, SX_NONE),
};
static const sx_layout sx_b_psx_exe_header = { UINT32_C(0x6009000C), "psx_exe_header", sx_b_psx_exe_header_fields, SX_COUNT(sx_b_psx_exe_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_nintendo_dol_header_fields[] = {
    SX_FIELD("text_file_offset_0", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("text_file_offset_1", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("text_file_offset_2", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("text_file_offset_3", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("text_file_offset_4", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("text_file_offset_5", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("text_file_offset_6", "uint32", 24, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_0", "uint32", 28, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_1", "uint32", 32, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_2", "uint32", 36, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_3", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_4", "uint32", 44, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_5", "uint32", 48, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_6", "uint32", 52, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_7", "uint32", 56, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_8", "uint32", 60, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_9", "uint32", 64, 4, SX_OFFSET),
    SX_FIELD("data_file_offset_10", "uint32", 68, 4, SX_OFFSET),
    SX_FIELD("text_address_0", "uint32", 72, 4, SX_ADDRESS),
    SX_FIELD("text_address_1", "uint32", 76, 4, SX_ADDRESS),
    SX_FIELD("text_address_2", "uint32", 80, 4, SX_ADDRESS),
    SX_FIELD("text_address_3", "uint32", 84, 4, SX_ADDRESS),
    SX_FIELD("text_address_4", "uint32", 88, 4, SX_ADDRESS),
    SX_FIELD("text_address_5", "uint32", 92, 4, SX_ADDRESS),
    SX_FIELD("text_address_6", "uint32", 96, 4, SX_ADDRESS),
    SX_FIELD("data_address_0", "uint32", 100, 4, SX_ADDRESS),
    SX_FIELD("data_address_1", "uint32", 104, 4, SX_ADDRESS),
    SX_FIELD("data_address_2", "uint32", 108, 4, SX_ADDRESS),
    SX_FIELD("data_address_3", "uint32", 112, 4, SX_ADDRESS),
    SX_FIELD("data_address_4", "uint32", 116, 4, SX_ADDRESS),
    SX_FIELD("data_address_5", "uint32", 120, 4, SX_ADDRESS),
    SX_FIELD("data_address_6", "uint32", 124, 4, SX_ADDRESS),
    SX_FIELD("data_address_7", "uint32", 128, 4, SX_ADDRESS),
    SX_FIELD("data_address_8", "uint32", 132, 4, SX_ADDRESS),
    SX_FIELD("data_address_9", "uint32", 136, 4, SX_ADDRESS),
    SX_FIELD("data_address_10", "uint32", 140, 4, SX_ADDRESS),
    SX_FIELD("text_size_0", "uint32", 144, 4, SX_SIZE),
    SX_FIELD("text_size_1", "uint32", 148, 4, SX_SIZE),
    SX_FIELD("text_size_2", "uint32", 152, 4, SX_SIZE),
    SX_FIELD("text_size_3", "uint32", 156, 4, SX_SIZE),
    SX_FIELD("text_size_4", "uint32", 160, 4, SX_SIZE),
    SX_FIELD("text_size_5", "uint32", 164, 4, SX_SIZE),
    SX_FIELD("text_size_6", "uint32", 168, 4, SX_SIZE),
    SX_FIELD("data_size_0", "uint32", 172, 4, SX_SIZE),
    SX_FIELD("data_size_1", "uint32", 176, 4, SX_SIZE),
    SX_FIELD("data_size_2", "uint32", 180, 4, SX_SIZE),
    SX_FIELD("data_size_3", "uint32", 184, 4, SX_SIZE),
    SX_FIELD("data_size_4", "uint32", 188, 4, SX_SIZE),
    SX_FIELD("data_size_5", "uint32", 192, 4, SX_SIZE),
    SX_FIELD("data_size_6", "uint32", 196, 4, SX_SIZE),
    SX_FIELD("data_size_7", "uint32", 200, 4, SX_SIZE),
    SX_FIELD("data_size_8", "uint32", 204, 4, SX_SIZE),
    SX_FIELD("data_size_9", "uint32", 208, 4, SX_SIZE),
    SX_FIELD("data_size_10", "uint32", 212, 4, SX_SIZE),
    SX_FIELD("bss_address", "uint32", 216, 4, SX_ADDRESS),
    SX_FIELD("bss_size", "uint32", 220, 4, SX_SIZE),
    SX_FIELD("entry_point", "uint32", 224, 4, SX_ADDRESS),
    SX_FIELD("reserved", "bytes", 228, 28, SX_RESERVED),
};
static const sx_layout sx_b_nintendo_dol_header = { UINT32_C(0x6009000D), "nintendo_dol_header", sx_b_nintendo_dol_header_fields, SX_COUNT(sx_b_nintendo_dol_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_bflt_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("revision", "uint32", 4, 4, SX_NONE),
    SX_FIELD("entry", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("data_start", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("data_end", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("bss_end", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("stack_size", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("relocation_start", "uint32", 28, 4, SX_OFFSET),
    SX_FIELD("relocation_count", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("flags", "uint32", 36, 4, SX_FLAGS),
    SX_FIELD("build_date", "uint32", 40, 4, SX_TIME),
    SX_FIELD("filler0", "uint32", 44, 4, SX_RESERVED),
    SX_FIELD("filler1", "uint32", 48, 4, SX_RESERVED),
    SX_FIELD("filler2", "uint32", 52, 4, SX_RESERVED),
    SX_FIELD("filler3", "uint32", 56, 4, SX_RESERVED),
    SX_FIELD("cpu_type_or_filler4", "uint32", 60, 4, SX_ID),
};
static const sx_layout sx_b_bflt_header = { UINT32_C(0x6009000E), "bflt_header", sx_b_bflt_header_fields, SX_COUNT(sx_b_bflt_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_bflt_relocation_fields[] = {
    SX_FIELD("encoded_relocation", "uint32", 0, 4, SX_FLAGS),
};
static const sx_layout sx_b_bflt_relocation = { UINT32_C(0x6009000F), "bflt_relocation", sx_b_bflt_relocation_fields, SX_COUNT(sx_b_bflt_relocation_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_btf_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 2, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 3, 1, SX_FLAGS),
    SX_FIELD("header_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("type_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("type_length", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("string_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("string_length", "uint32", 20, 4, SX_SIZE),
};
static const sx_layout sx_b_btf_header = { UINT32_C(0x60090010), "btf_header", sx_b_btf_header_fields, SX_COUNT(sx_b_btf_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_type_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("info", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("size_or_type", "uint32", 8, 4, SX_NONE),
};
static const sx_layout sx_b_btf_type = { UINT32_C(0x60090011), "btf_type", sx_b_btf_type_fields, SX_COUNT(sx_b_btf_type_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_integer_fields[] = {
    SX_FIELD("encoding", "uint32", 0, 4, SX_FLAGS),
};
static const sx_layout sx_b_btf_integer = { UINT32_C(0x60090012), "btf_integer", sx_b_btf_integer_fields, SX_COUNT(sx_b_btf_integer_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_array_fields[] = {
    SX_FIELD("type", "uint32", 0, 4, SX_NONE),
    SX_FIELD("index_type", "uint32", 4, 4, SX_NONE),
    SX_FIELD("element_count", "uint32", 8, 4, SX_COUNT_PROP),
};
static const sx_layout sx_b_btf_array = { UINT32_C(0x60090013), "btf_array", sx_b_btf_array_fields, SX_COUNT(sx_b_btf_array_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_member_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("type", "uint32", 4, 4, SX_NONE),
    SX_FIELD("bit_offset", "uint32", 8, 4, SX_FLAGS),
};
static const sx_layout sx_b_btf_member = { UINT32_C(0x60090014), "btf_member", sx_b_btf_member_fields, SX_COUNT(sx_b_btf_member_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_enum_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("value", "int32", 4, 4, SX_NONE),
};
static const sx_layout sx_b_btf_enum = { UINT32_C(0x60090015), "btf_enum", sx_b_btf_enum_fields, SX_COUNT(sx_b_btf_enum_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_enum64_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("value_low", "uint32", 4, 4, SX_NONE),
    SX_FIELD("value_high", "uint32", 8, 4, SX_NONE),
};
static const sx_layout sx_b_btf_enum64 = { UINT32_C(0x60090016), "btf_enum64", sx_b_btf_enum64_fields, SX_COUNT(sx_b_btf_enum64_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_parameter_fields[] = {
    SX_FIELD("name_offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("type", "uint32", 4, 4, SX_NONE),
};
static const sx_layout sx_b_btf_parameter = { UINT32_C(0x60090017), "btf_parameter", sx_b_btf_parameter_fields, SX_COUNT(sx_b_btf_parameter_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_variable_fields[] = {
    SX_FIELD("linkage", "uint32", 0, 4, SX_ID),
};
static const sx_layout sx_b_btf_variable = { UINT32_C(0x60090018), "btf_variable", sx_b_btf_variable_fields, SX_COUNT(sx_b_btf_variable_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_datasec_entry_fields[] = {
    SX_FIELD("type", "uint32", 0, 4, SX_NONE),
    SX_FIELD("offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_b_btf_datasec_entry = { UINT32_C(0x60090019), "btf_datasec_entry", sx_b_btf_datasec_entry_fields, SX_COUNT(sx_b_btf_datasec_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btf_decl_tag_fields[] = {
    SX_FIELD("component_index", "int32", 0, 4, SX_NONE),
};
static const sx_layout sx_b_btf_decl_tag = { UINT32_C(0x6009001A), "btf_decl_tag", sx_b_btf_decl_tag_fields, SX_COUNT(sx_b_btf_decl_tag_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_minidump_header_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("stream_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("directory_rva", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("checksum", "uint32", 16, 4, SX_CHECKSUM),
    SX_FIELD("timestamp", "uint32", 20, 4, SX_TIME),
    SX_FIELD("flags", "uint64", 24, 8, SX_FLAGS),
};
static const sx_layout sx_b_minidump_header = { UINT32_C(0x6009001B), "minidump_header", sx_b_minidump_header_fields, SX_COUNT(sx_b_minidump_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_minidump_directory_fields[] = {
    SX_FIELD("stream_type", "uint32", 0, 4, SX_ID),
    SX_FIELD("data_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("rva", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sx_b_minidump_directory = { UINT32_C(0x6009001C), "minidump_directory", sx_b_minidump_directory_fields, SX_COUNT(sx_b_minidump_directory_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_menuet_header_fields[] = {
    SX_FIELD("magic", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 8, 4, SX_NONE),
    SX_FIELD("entry_point", "uint32", 12, 4, SX_ADDRESS),
    SX_FIELD("image_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("memory_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("stack_pointer", "uint32", 24, 4, SX_ADDRESS),
    SX_FIELD("command_line", "uint32", 28, 4, SX_ADDRESS),
    SX_FIELD("executable_path", "uint32", 32, 4, SX_ADDRESS),
};
static const sx_layout sx_b_menuet_header = { UINT32_C(0x6009001D), "menuet_header", sx_b_menuet_header_fields, SX_COUNT(sx_b_menuet_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_plan9_header_be_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("text_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("data_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("bss_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("symbol_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("entry_point", "uint32", 20, 4, SX_ADDRESS),
    SX_FIELD("sp_table_size", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("pc_table_size", "uint32", 28, 4, SX_SIZE),
};
static const sx_layout sx_b_plan9_header_be = { UINT32_C(0x6009001E), "plan9_header_be", sx_b_plan9_header_be_fields, SX_COUNT(sx_b_plan9_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_plan9_entry64_fields[] = {
    SX_FIELD("entry_point", "uint64", 0, 8, SX_ADDRESS),
};
static const sx_layout sx_b_plan9_entry64 = { UINT32_C(0x6009001F), "plan9_entry64", sx_b_plan9_entry64_fields, SX_COUNT(sx_b_plan9_entry64_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_menuet_header0_fields[] = {
    SX_FIELD("magic", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("required_os", "uint32", 8, 4, SX_NONE),
    SX_FIELD("entry_point", "uint32", 12, 4, SX_ADDRESS),
    SX_FIELD("image_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("memory_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("extended_header", "uint32", 24, 4, SX_RESERVED),
};
static const sx_layout sx_b_menuet_header0 = { UINT32_C(0x60090020), "menuet_header0", sx_b_menuet_header0_fields, SX_COUNT(sx_b_menuet_header0_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_menuet_header2_fields[] = {
    SX_FIELD("magic", "char[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 8, 4, SX_NONE),
    SX_FIELD("entry_point", "uint32", 12, 4, SX_ADDRESS),
    SX_FIELD("image_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("memory_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("stack_pointer", "uint32", 24, 4, SX_ADDRESS),
    SX_FIELD("command_line", "uint32", 28, 4, SX_ADDRESS),
    SX_FIELD("executable_path", "uint32", 32, 4, SX_ADDRESS),
    SX_FIELD("subsystem", "uint32", 36, 4, SX_ID),
    SX_FIELD("import_start", "uint32", 40, 4, SX_ADDRESS),
    SX_FIELD("import_end", "uint32", 44, 4, SX_ADDRESS),
    SX_FIELD("main_entry", "uint32", 48, 4, SX_ADDRESS),
};
static const sx_layout sx_b_menuet_header2 = { UINT32_C(0x60090021), "menuet_header2", sx_b_menuet_header2_fields, SX_COUNT(sx_b_menuet_header2_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_leveldb_writebatch_header_fields[] = {
    SX_FIELD("sequence_number", "uint64", 0, 8, SX_NONE),
    SX_FIELD("operation_count", "uint32", 8, 4, SX_COUNT_PROP),
};
static const sx_layout sx_b_leveldb_writebatch_header = { UINT32_C(0x60090022), "leveldb_writebatch_header", sx_b_leveldb_writebatch_header_fields, SX_COUNT(sx_b_leveldb_writebatch_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_uimage_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("header_crc", "uint32", 4, 4, SX_CHECKSUM),
    SX_FIELD("timestamp", "uint32", 8, 4, SX_TIME),
    SX_FIELD("data_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("load_address", "uint32", 16, 4, SX_ADDRESS),
    SX_FIELD("entry_point", "uint32", 20, 4, SX_ADDRESS),
    SX_FIELD("data_crc", "uint32", 24, 4, SX_CHECKSUM),
    SX_FIELD("os", "uint8", 28, 1, SX_ID),
    SX_FIELD("architecture", "uint8", 29, 1, SX_ID),
    SX_FIELD("image_type", "uint8", 30, 1, SX_ID),
    SX_FIELD("compression", "uint8", 31, 1, SX_ID),
    SX_FIELD("name", "char[32]", 32, 32, SX_STRING),
};
static const sx_layout sx_b_uimage_header = { UINT32_C(0x60090023), "uimage_header", sx_b_uimage_header_fields, SX_COUNT(sx_b_uimage_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_uimage_component_size_fields[] = {
    SX_FIELD("component_size", "uint32", 0, 4, SX_SIZE),
};
static const sx_layout sx_b_uimage_component_size = { UINT32_C(0x60090024), "uimage_component_size", sx_b_uimage_component_size_fields, SX_COUNT(sx_b_uimage_component_size_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_dtb_header_v2_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("total_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("structure_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("strings_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("reserve_map_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("version", "uint32", 20, 4, SX_NONE),
    SX_FIELD("last_compatible_version", "uint32", 24, 4, SX_NONE),
    SX_FIELD("boot_cpuid_phys", "uint32", 28, 4, SX_NONE),
};
static const sx_layout sx_b_dtb_header_v2 = { UINT32_C(0x60090025), "dtb_header_v2", sx_b_dtb_header_v2_fields, SX_COUNT(sx_b_dtb_header_v2_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_dtb_header_v3_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("total_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("structure_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("strings_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("reserve_map_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("version", "uint32", 20, 4, SX_NONE),
    SX_FIELD("last_compatible_version", "uint32", 24, 4, SX_NONE),
    SX_FIELD("boot_cpuid_phys", "uint32", 28, 4, SX_NONE),
    SX_FIELD("string_size", "uint32", 32, 4, SX_SIZE),
};
static const sx_layout sx_b_dtb_header_v3 = { UINT32_C(0x60090026), "dtb_header_v3", sx_b_dtb_header_v3_fields, SX_COUNT(sx_b_dtb_header_v3_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_dtb_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("total_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("structure_offset", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("strings_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("reserve_map_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("version", "uint32", 20, 4, SX_NONE),
    SX_FIELD("last_compatible_version", "uint32", 24, 4, SX_NONE),
    SX_FIELD("boot_cpuid_phys", "uint32", 28, 4, SX_NONE),
    SX_FIELD("string_size", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("structure_size", "uint32", 36, 4, SX_SIZE),
};
static const sx_layout sx_b_dtb_header = { UINT32_C(0x60090027), "dtb_header", sx_b_dtb_header_fields, SX_COUNT(sx_b_dtb_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_dtb_reservation_fields[] = {
    SX_FIELD("address", "uint64", 0, 8, SX_ADDRESS),
    SX_FIELD("size", "uint64", 8, 8, SX_SIZE),
};
static const sx_layout sx_b_dtb_reservation = { UINT32_C(0x60090028), "dtb_reservation", sx_b_dtb_reservation_fields, SX_COUNT(sx_b_dtb_reservation_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_dtb_token_fields[] = {
    SX_FIELD("token", "uint32", 0, 4, SX_ID),
};
static const sx_layout sx_b_dtb_token = { UINT32_C(0x60090029), "dtb_token", sx_b_dtb_token_fields, SX_COUNT(sx_b_dtb_token_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_dtb_property_header_fields[] = {
    SX_FIELD("token", "uint32", 0, 4, SX_ID),
    SX_FIELD("length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("name_offset", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sx_b_dtb_property_header = { UINT32_C(0x6009002A), "dtb_property_header", sx_b_dtb_property_header_fields, SX_COUNT(sx_b_dtb_property_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_trx_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("total_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("crc32", "uint32", 8, 4, SX_CHECKSUM),
    SX_FIELD("flags", "uint16", 12, 2, SX_FLAGS),
    SX_FIELD("version", "uint16", 14, 2, SX_NONE),
    SX_FIELD("partition0_offset", "uint32", 16, 4, SX_OFFSET),
    SX_FIELD("partition1_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("partition2_offset", "uint32", 24, 4, SX_OFFSET),
};
static const sx_layout sx_b_trx_header = { UINT32_C(0x6009002B), "trx_header", sx_b_trx_header_fields, SX_COUNT(sx_b_trx_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_seama_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("reserved", "uint16", 4, 2, SX_RESERVED),
    SX_FIELD("metadata_size", "uint16", 6, 2, SX_SIZE),
    SX_FIELD("image_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_b_seama_header = { UINT32_C(0x6009002C), "seama_header", sx_b_seama_header_fields, SX_COUNT(sx_b_seama_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_seama_digest_fields[] = {
    SX_FIELD("md5", "bytes", 0, 16, SX_CHECKSUM),
};
static const sx_layout sx_b_seama_digest = { UINT32_C(0x6009002D), "seama_digest", sx_b_seama_digest_fields, SX_COUNT(sx_b_seama_digest_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_android_sparse_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("major_version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("minor_version", "uint16", 6, 2, SX_NONE),
    SX_FIELD("file_header_size", "uint16", 8, 2, SX_SIZE),
    SX_FIELD("chunk_header_size", "uint16", 10, 2, SX_SIZE),
    SX_FIELD("block_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("total_blocks", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("total_chunks", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("image_checksum", "uint32", 24, 4, SX_CHECKSUM),
};
static const sx_layout sx_b_android_sparse_header = { UINT32_C(0x6009002E), "android_sparse_header", sx_b_android_sparse_header_fields, SX_COUNT(sx_b_android_sparse_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_android_sparse_chunk_fields[] = {
    SX_FIELD("chunk_type", "uint16", 0, 2, SX_ID),
    SX_FIELD("reserved", "uint16", 2, 2, SX_RESERVED),
    SX_FIELD("chunk_blocks", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("total_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_b_android_sparse_chunk = { UINT32_C(0x6009002F), "android_sparse_chunk", sx_b_android_sparse_chunk_fields, SX_COUNT(sx_b_android_sparse_chunk_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_linux_arm64_header_fields[] = {
    SX_FIELD("code0", "uint32", 0, 4, SX_NONE),
    SX_FIELD("code1", "uint32", 4, 4, SX_NONE),
    SX_FIELD("text_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("image_size", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("flags", "uint64", 24, 8, SX_FLAGS),
    SX_FIELD("reserved2", "uint64", 32, 8, SX_RESERVED),
    SX_FIELD("reserved3", "uint64", 40, 8, SX_RESERVED),
    SX_FIELD("reserved4", "uint64", 48, 8, SX_RESERVED),
    SX_FIELD("magic", "uint32", 56, 4, SX_SIGNATURE),
    SX_FIELD("pe_header_offset", "uint32", 60, 4, SX_OFFSET),
};
static const sx_layout sx_b_linux_arm64_header = { UINT32_C(0x60090030), "linux_arm64_header", sx_b_linux_arm64_header_fields, SX_COUNT(sx_b_linux_arm64_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_linux_zimage_header_le_fields[] = {
    SX_FIELD("startup_code", "bytes", 0, 36, SX_NONE),
    SX_FIELD("magic", "uint32", 36, 4, SX_SIGNATURE),
    SX_FIELD("start", "uint32", 40, 4, SX_ADDRESS),
    SX_FIELD("end", "uint32", 44, 4, SX_ADDRESS),
};
static const sx_layout sx_b_linux_zimage_header_le = { UINT32_C(0x60090031), "linux_zimage_header_le", sx_b_linux_zimage_header_le_fields, SX_COUNT(sx_b_linux_zimage_header_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_linux_zimage_header_be_fields[] = {
    SX_FIELD("startup_code", "bytes", 0, 36, SX_NONE),
    SX_FIELD("magic", "uint32", 36, 4, SX_SIGNATURE),
    SX_FIELD("start", "uint32", 40, 4, SX_ADDRESS),
    SX_FIELD("end", "uint32", 44, 4, SX_ADDRESS),
};
static const sx_layout sx_b_linux_zimage_header_be = { UINT32_C(0x60090032), "linux_zimage_header_be", sx_b_linux_zimage_header_be_fields, SX_COUNT(sx_b_linux_zimage_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_uefi_capsule_header_fields[] = {
    SX_FIELD("capsule_guid", "bytes", 0, 16, SX_ID),
    SX_FIELD("header_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 20, 4, SX_FLAGS),
    SX_FIELD("capsule_image_size", "uint32", 24, 4, SX_SIZE),
};
static const sx_layout sx_b_uefi_capsule_header = { UINT32_C(0x60090033), "uefi_capsule_header", sx_b_uefi_capsule_header_fields, SX_COUNT(sx_b_uefi_capsule_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_uefi_fv_header_fields[] = {
    SX_FIELD("zero_vector", "bytes", 0, 16, SX_RESERVED),
    SX_FIELD("filesystem_guid", "bytes", 16, 16, SX_ID),
    SX_FIELD("volume_length", "uint64", 32, 8, SX_SIZE),
    SX_FIELD("signature", "char[4]", 40, 4, SX_SIGNATURE),
    SX_FIELD("attributes", "uint32", 44, 4, SX_FLAGS),
    SX_FIELD("header_length", "uint16", 48, 2, SX_SIZE),
    SX_FIELD("checksum", "uint16", 50, 2, SX_CHECKSUM),
    SX_FIELD("extension_header_offset", "uint16", 52, 2, SX_OFFSET),
    SX_FIELD("reserved", "uint8", 54, 1, SX_RESERVED),
    SX_FIELD("revision", "uint8", 55, 1, SX_NONE),
};
static const sx_layout sx_b_uefi_fv_header = { UINT32_C(0x60090034), "uefi_fv_header", sx_b_uefi_fv_header_fields, SX_COUNT(sx_b_uefi_fv_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_uefi_fv_block_map_fields[] = {
    SX_FIELD("block_count", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("block_length", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_b_uefi_fv_block_map = { UINT32_C(0x60090035), "uefi_fv_block_map", sx_b_uefi_fv_block_map_fields, SX_COUNT(sx_b_uefi_fv_block_map_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_uf2_block_header_fields[] = {
    SX_FIELD("magic_start0", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("magic_start1", "uint32", 4, 4, SX_SIGNATURE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("target_address", "uint32", 12, 4, SX_ADDRESS),
    SX_FIELD("payload_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("block_number", "uint32", 20, 4, SX_NONE),
    SX_FIELD("block_count", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("file_size_or_family_id", "uint32", 28, 4, SX_NONE),
};
static const sx_layout sx_b_uf2_block_header = { UINT32_C(0x60090036), "uf2_block_header", sx_b_uf2_block_header_fields, SX_COUNT(sx_b_uf2_block_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_uf2_block_end_fields[] = {
    SX_FIELD("magic_end", "uint32", 0, 4, SX_SIGNATURE),
};
static const sx_layout sx_b_uf2_block_end = { UINT32_C(0x60090037), "uf2_block_end", sx_b_uf2_block_end_fields, SX_COUNT(sx_b_uf2_block_end_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_android_dtbo_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("total_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("entry_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("entry_count", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("entries_offset", "uint32", 20, 4, SX_OFFSET),
    SX_FIELD("page_size", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("version", "uint32", 28, 4, SX_NONE),
};
static const sx_layout sx_b_android_dtbo_header = { UINT32_C(0x60090038), "android_dtbo_header", sx_b_android_dtbo_header_fields, SX_COUNT(sx_b_android_dtbo_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_android_dtbo_entry_fields[] = {
    SX_FIELD("dt_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("dt_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("id", "uint32", 8, 4, SX_ID),
    SX_FIELD("revision", "uint32", 12, 4, SX_NONE),
    SX_FIELD("custom0", "uint32", 16, 4, SX_NONE),
    SX_FIELD("custom1", "uint32", 20, 4, SX_NONE),
    SX_FIELD("custom2", "uint32", 24, 4, SX_NONE),
    SX_FIELD("custom3", "uint32", 28, 4, SX_NONE),
};
static const sx_layout sx_b_android_dtbo_entry = { UINT32_C(0x60090039), "android_dtbo_entry", sx_b_android_dtbo_entry_fields, SX_COUNT(sx_b_android_dtbo_entry_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_avb_vbmeta_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("required_major", "uint32", 4, 4, SX_NONE),
    SX_FIELD("required_minor", "uint32", 8, 4, SX_NONE),
    SX_FIELD("authentication_size", "uint64", 12, 8, SX_SIZE),
    SX_FIELD("auxiliary_size", "uint64", 20, 8, SX_SIZE),
    SX_FIELD("algorithm_type", "uint32", 28, 4, SX_ID),
    SX_FIELD("hash_offset", "uint64", 32, 8, SX_OFFSET),
    SX_FIELD("hash_size", "uint64", 40, 8, SX_SIZE),
    SX_FIELD("signature_offset", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("signature_size", "uint64", 56, 8, SX_SIZE),
    SX_FIELD("public_key_offset", "uint64", 64, 8, SX_OFFSET),
    SX_FIELD("public_key_size", "uint64", 72, 8, SX_SIZE),
    SX_FIELD("public_key_metadata_offset", "uint64", 80, 8, SX_OFFSET),
    SX_FIELD("public_key_metadata_size", "uint64", 88, 8, SX_SIZE),
    SX_FIELD("descriptors_offset", "uint64", 96, 8, SX_OFFSET),
    SX_FIELD("descriptors_size", "uint64", 104, 8, SX_SIZE),
    SX_FIELD("rollback_index", "uint64", 112, 8, SX_NONE),
    SX_FIELD("flags", "uint32", 120, 4, SX_FLAGS),
    SX_FIELD("rollback_index_location", "uint32", 124, 4, SX_NONE),
    SX_FIELD("release_string", "char[48]", 128, 48, SX_STRING),
    SX_FIELD("reserved", "bytes", 176, 80, SX_RESERVED),
};
static const sx_layout sx_b_avb_vbmeta_header = { UINT32_C(0x6009003A), "avb_vbmeta_header", sx_b_avb_vbmeta_header_fields, SX_COUNT(sx_b_avb_vbmeta_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_avb_descriptor_fields[] = {
    SX_FIELD("tag", "uint64", 0, 8, SX_ID),
    SX_FIELD("bytes_following", "uint64", 8, 8, SX_SIZE),
};
static const sx_layout sx_b_avb_descriptor = { UINT32_C(0x6009003B), "avb_descriptor", sx_b_avb_descriptor_fields, SX_COUNT(sx_b_avb_descriptor_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_quake_pak_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("directory_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("directory_size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_b_quake_pak_header = { UINT32_C(0x6009003C), "quake_pak_header", sx_b_quake_pak_header_fields, SX_COUNT(sx_b_quake_pak_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_quake_pak_entry_fields[] = {
    SX_FIELD("name", "char[56]", 0, 56, SX_STRING),
    SX_FIELD("offset", "uint32", 56, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 60, 4, SX_SIZE),
};
static const sx_layout sx_b_quake_pak_entry = { UINT32_C(0x6009003D), "quake_pak_entry", sx_b_quake_pak_entry_fields, SX_COUNT(sx_b_quake_pak_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_wad_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("lump_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("directory_offset", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sx_b_wad_header = { UINT32_C(0x6009003E), "wad_header", sx_b_wad_header_fields, SX_COUNT(sx_b_wad_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_doom_wad_entry_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("name", "char[8]", 8, 8, SX_STRING),
};
static const sx_layout sx_b_doom_wad_entry = { UINT32_C(0x6009003F), "doom_wad_entry", sx_b_doom_wad_entry_fields, SX_COUNT(sx_b_doom_wad_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_quake_wad_entry_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("disk_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("type", "uint8", 12, 1, SX_ID),
    SX_FIELD("compression", "uint8", 13, 1, SX_ID),
    SX_FIELD("reserved", "uint16", 14, 2, SX_RESERVED),
    SX_FIELD("name", "char[16]", 16, 16, SX_STRING),
};
static const sx_layout sx_b_quake_wad_entry = { UINT32_C(0x60090040), "quake_wad_entry", sx_b_quake_wad_entry_fields, SX_COUNT(sx_b_quake_wad_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_build_grp_header_fields[] = {
    SX_FIELD("magic", "char[12]", 0, 12, SX_SIGNATURE),
    SX_FIELD("file_count", "uint32", 12, 4, SX_COUNT_PROP),
};
static const sx_layout sx_b_build_grp_header = { UINT32_C(0x60090041), "build_grp_header", sx_b_build_grp_header_fields, SX_COUNT(sx_b_build_grp_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_build_grp_entry_fields[] = {
    SX_FIELD("name", "char[12]", 0, 12, SX_STRING),
    SX_FIELD("size", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_b_build_grp_entry = { UINT32_C(0x60090042), "build_grp_entry", sx_b_build_grp_entry_fields, SX_COUNT(sx_b_build_grp_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_afs_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("file_count", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sx_b_afs_header = { UINT32_C(0x60090043), "afs_header", sx_b_afs_header_fields, SX_COUNT(sx_b_afs_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_afs_entry_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_b_afs_entry = { UINT32_C(0x60090044), "afs_entry", sx_b_afs_entry_fields, SX_COUNT(sx_b_afs_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_nintendo_u8_header_le_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("root_node_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("data_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("reserved", "bytes", 16, 16, SX_RESERVED),
};
static const sx_layout sx_b_nintendo_u8_header_le = { UINT32_C(0x60090045), "nintendo_u8_header_le", sx_b_nintendo_u8_header_le_fields, SX_COUNT(sx_b_nintendo_u8_header_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_nintendo_u8_file_node_le_fields[] = {
    SX_FIELD("type_and_name_offset", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_b_nintendo_u8_file_node_le = { UINT32_C(0x60090046), "nintendo_u8_file_node_le", sx_b_nintendo_u8_file_node_le_fields, SX_COUNT(sx_b_nintendo_u8_file_node_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_nintendo_u8_directory_node_le_fields[] = {
    SX_FIELD("type_and_name_offset", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("parent_index", "uint32", 4, 4, SX_NONE),
    SX_FIELD("end_index", "uint32", 8, 4, SX_NONE),
};
static const sx_layout sx_b_nintendo_u8_directory_node_le = { UINT32_C(0x60090047), "nintendo_u8_directory_node_le", sx_b_nintendo_u8_directory_node_le_fields, SX_COUNT(sx_b_nintendo_u8_directory_node_le_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_nintendo_u8_header_be_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("root_node_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("data_offset", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("reserved", "bytes", 16, 16, SX_RESERVED),
};
static const sx_layout sx_b_nintendo_u8_header_be = { UINT32_C(0x60090048), "nintendo_u8_header_be", sx_b_nintendo_u8_header_be_fields, SX_COUNT(sx_b_nintendo_u8_header_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_nintendo_u8_file_node_be_fields[] = {
    SX_FIELD("type_and_name_offset", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("data_offset", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 8, 4, SX_SIZE),
};
static const sx_layout sx_b_nintendo_u8_file_node_be = { UINT32_C(0x60090049), "nintendo_u8_file_node_be", sx_b_nintendo_u8_file_node_be_fields, SX_COUNT(sx_b_nintendo_u8_file_node_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_nintendo_u8_directory_node_be_fields[] = {
    SX_FIELD("type_and_name_offset", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("parent_index", "uint32", 4, 4, SX_NONE),
    SX_FIELD("end_index", "uint32", 8, 4, SX_NONE),
};
static const sx_layout sx_b_nintendo_u8_directory_node_be = { UINT32_C(0x6009004A), "nintendo_u8_directory_node_be", sx_b_nintendo_u8_directory_node_be_fields, SX_COUNT(sx_b_nintendo_u8_directory_node_be_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_bigf_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("archive_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_b_bigf_header = { UINT32_C(0x6009004B), "bigf_header", sx_b_bigf_header_fields, SX_COUNT(sx_b_bigf_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_bigf_directory_header_fields[] = {
    SX_FIELD("file_count", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("header_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_b_bigf_directory_header = { UINT32_C(0x6009004C), "bigf_directory_header", sx_b_bigf_directory_header_fields, SX_COUNT(sx_b_bigf_directory_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_bigf_terminal_filler_fields[] = {
    SX_FIELD("offset_filler", "uint32", 0, 4, SX_RESERVED),
    SX_FIELD("size_filler", "uint32", 4, 4, SX_RESERVED),
};
static const sx_layout sx_b_bigf_terminal_filler = { UINT32_C(0x6009004D), "bigf_terminal_filler", sx_b_bigf_terminal_filler_fields, SX_COUNT(sx_b_bigf_terminal_filler_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_bigf_entry_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_b_bigf_entry = { UINT32_C(0x6009004E), "bigf_entry", sx_b_bigf_entry_fields, SX_COUNT(sx_b_bigf_entry_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_hog_header_fields[] = {
    SX_FIELD("magic", "char[3]", 0, 3, SX_SIGNATURE),
};
static const sx_layout sx_b_hog_header = { UINT32_C(0x6009004F), "hog_header", sx_b_hog_header_fields, SX_COUNT(sx_b_hog_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_hog_entry_fields[] = {
    SX_FIELD("name", "char[13]", 0, 13, SX_STRING),
    SX_FIELD("size", "uint32", 13, 4, SX_SIZE),
};
static const sx_layout sx_b_hog_entry = { UINT32_C(0x60090050), "hog_entry", sx_b_hog_entry_fields, SX_COUNT(sx_b_hog_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_gob_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("directory_offset", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sx_b_gob_header = { UINT32_C(0x60090051), "gob_header", sx_b_gob_header_fields, SX_COUNT(sx_b_gob_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_gob_jk_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("directory_offset", "uint32", 8, 4, SX_OFFSET),
};
static const sx_layout sx_b_gob_jk_header = { UINT32_C(0x60090052), "gob_jk_header", sx_b_gob_jk_header_fields, SX_COUNT(sx_b_gob_jk_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_gob_directory_header_fields[] = {
    SX_FIELD("file_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sx_b_gob_directory_header = { UINT32_C(0x60090053), "gob_directory_header", sx_b_gob_directory_header_fields, SX_COUNT(sx_b_gob_directory_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_gob_entry_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("name", "char[13]", 8, 13, SX_STRING),
};
static const sx_layout sx_b_gob_entry = { UINT32_C(0x60090054), "gob_entry", sx_b_gob_entry_fields, SX_COUNT(sx_b_gob_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_gob_jk_entry_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("name", "char[128]", 8, 128, SX_STRING),
};
static const sx_layout sx_b_gob_jk_entry = { UINT32_C(0x60090055), "gob_jk_entry", sx_b_gob_jk_entry_fields, SX_COUNT(sx_b_gob_jk_entry_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_mysql_binlog_header_fields[] = {
    SX_FIELD("magic", "bytes", 0, 4, SX_SIGNATURE),
};
static const sx_layout sx_b_mysql_binlog_header = { UINT32_C(0x60090056), "mysql_binlog_header", sx_b_mysql_binlog_header_fields, SX_COUNT(sx_b_mysql_binlog_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_mysql_binlog_event_fields[] = {
    SX_FIELD("timestamp", "uint32", 0, 4, SX_TIME),
    SX_FIELD("event_type", "uint8", 4, 1, SX_ID),
    SX_FIELD("server_id", "uint32", 5, 4, SX_NONE),
    SX_FIELD("event_size", "uint32", 9, 4, SX_SIZE),
    SX_FIELD("next_position", "uint32", 13, 4, SX_OFFSET),
    SX_FIELD("flags", "uint16", 17, 2, SX_FLAGS),
};
static const sx_layout sx_b_mysql_binlog_event = { UINT32_C(0x60090057), "mysql_binlog_event", sx_b_mysql_binlog_event_fields, SX_COUNT(sx_b_mysql_binlog_event_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_sqlite_journal_header_fields[] = {
    SX_FIELD("magic", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("record_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("checksum_nonce", "uint32", 12, 4, SX_NONE),
    SX_FIELD("initial_page_count", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("sector_size", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("page_size", "uint32", 24, 4, SX_SIZE),
};
static const sx_layout sx_b_sqlite_journal_header = { UINT32_C(0x60090058), "sqlite_journal_header", sx_b_sqlite_journal_header_fields, SX_COUNT(sx_b_sqlite_journal_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_sqlite_journal_page_number_fields[] = {
    SX_FIELD("page_number", "uint32", 0, 4, SX_NONE),
};
static const sx_layout sx_b_sqlite_journal_page_number = { UINT32_C(0x60090059), "sqlite_journal_page_number", sx_b_sqlite_journal_page_number_fields, SX_COUNT(sx_b_sqlite_journal_page_number_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_sqlite_journal_checksum_fields[] = {
    SX_FIELD("checksum", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_b_sqlite_journal_checksum = { UINT32_C(0x6009005A), "sqlite_journal_checksum", sx_b_sqlite_journal_checksum_fields, SX_COUNT(sx_b_sqlite_journal_checksum_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_leveldb_log_record_fields[] = {
    SX_FIELD("masked_crc32c", "uint32", 0, 4, SX_CHECKSUM),
    SX_FIELD("length", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("type", "uint8", 6, 1, SX_ID),
};
static const sx_layout sx_b_leveldb_log_record = { UINT32_C(0x6009005B), "leveldb_log_record", sx_b_leveldb_log_record_fields, SX_COUNT(sx_b_leveldb_log_record_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_rocksdb_blob_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("column_family_id", "uint32", 8, 4, SX_NONE),
    SX_FIELD("flags", "uint8", 12, 1, SX_FLAGS),
    SX_FIELD("compression", "uint8", 13, 1, SX_ID),
    SX_FIELD("expiration_start", "uint64", 14, 8, SX_NONE),
    SX_FIELD("expiration_end", "uint64", 22, 8, SX_NONE),
};
static const sx_layout sx_b_rocksdb_blob_header = { UINT32_C(0x6009005C), "rocksdb_blob_header", sx_b_rocksdb_blob_header_fields, SX_COUNT(sx_b_rocksdb_blob_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_rocksdb_blob_record_fields[] = {
    SX_FIELD("key_size", "uint64", 0, 8, SX_SIZE),
    SX_FIELD("value_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("expiration", "uint64", 16, 8, SX_NONE),
    SX_FIELD("header_crc32c", "uint32", 24, 4, SX_CHECKSUM),
    SX_FIELD("blob_crc32c", "uint32", 28, 4, SX_CHECKSUM),
};
static const sx_layout sx_b_rocksdb_blob_record = { UINT32_C(0x6009005D), "rocksdb_blob_record", sx_b_rocksdb_blob_record_fields, SX_COUNT(sx_b_rocksdb_blob_record_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_rocksdb_blob_footer_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("blob_count", "uint64", 4, 8, SX_COUNT_PROP),
    SX_FIELD("expiration_start", "uint64", 12, 8, SX_NONE),
    SX_FIELD("expiration_end", "uint64", 20, 8, SX_NONE),
    SX_FIELD("footer_crc32c", "uint32", 28, 4, SX_CHECKSUM),
};
static const sx_layout sx_b_rocksdb_blob_footer = { UINT32_C(0x6009005E), "rocksdb_blob_footer", sx_b_rocksdb_blob_footer_fields, SX_COUNT(sx_b_rocksdb_blob_footer_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_cdb_hash_table_header_fields[] = {
    SX_FIELD("position", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("slot_count", "uint32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sx_b_cdb_hash_table_header = { UINT32_C(0x6009005F), "cdb_hash_table_header", sx_b_cdb_hash_table_header_fields, SX_COUNT(sx_b_cdb_hash_table_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_cdb_record_header_fields[] = {
    SX_FIELD("key_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("value_size", "uint32", 4, 4, SX_SIZE),
};
static const sx_layout sx_b_cdb_record_header = { UINT32_C(0x60090060), "cdb_record_header", sx_b_cdb_record_header_fields, SX_COUNT(sx_b_cdb_record_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_cdb_hash_slot_fields[] = {
    SX_FIELD("hash", "uint32", 0, 4, SX_CHECKSUM),
    SX_FIELD("record_position", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sx_b_cdb_hash_slot = { UINT32_C(0x60090061), "cdb_hash_slot", sx_b_cdb_hash_slot_fields, SX_COUNT(sx_b_cdb_hash_slot_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_btsnoop_header_fields[] = {
    SX_FIELD("magic", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 8, 4, SX_NONE),
    SX_FIELD("datalink_type", "uint32", 12, 4, SX_ID),
};
static const sx_layout sx_b_btsnoop_header = { UINT32_C(0x60090062), "btsnoop_header", sx_b_btsnoop_header_fields, SX_COUNT(sx_b_btsnoop_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_btsnoop_packet_fields[] = {
    SX_FIELD("original_length", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("included_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("cumulative_drops", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("timestamp_us", "uint64", 16, 8, SX_NONE),
};
static const sx_layout sx_b_btsnoop_packet = { UINT32_C(0x60090063), "btsnoop_packet", sx_b_btsnoop_packet_fields, SX_COUNT(sx_b_btsnoop_packet_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_tfrecord_header_fields[] = {
    SX_FIELD("length", "uint64", 0, 8, SX_SIZE),
    SX_FIELD("length_crc32c", "uint32", 8, 4, SX_CHECKSUM),
};
static const sx_layout sx_b_tfrecord_header = { UINT32_C(0x60090064), "tfrecord_header", sx_b_tfrecord_header_fields, SX_COUNT(sx_b_tfrecord_header_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_tfrecord_trailer_fields[] = {
    SX_FIELD("data_crc32c", "uint32", 0, 4, SX_CHECKSUM),
};
static const sx_layout sx_b_tfrecord_trailer = { UINT32_C(0x60090065), "tfrecord_trailer", sx_b_tfrecord_trailer_fields, SX_COUNT(sx_b_tfrecord_trailer_fields), SX_LE };

static const xx_data_struct_field_desc sx_b_binary_plist_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("version", "char[2]", 6, 2, SX_NONE),
};
static const sx_layout sx_b_binary_plist_header = { UINT32_C(0x60090066), "binary_plist_header", sx_b_binary_plist_header_fields, SX_COUNT(sx_b_binary_plist_header_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_trailer_fields[] = {
    SX_FIELD("reserved", "bytes", 0, 6, SX_RESERVED),
    SX_FIELD("offset_size", "uint8", 6, 1, SX_SIZE),
    SX_FIELD("object_reference_size", "uint8", 7, 1, SX_SIZE),
    SX_FIELD("object_count", "uint64", 8, 8, SX_COUNT_PROP),
    SX_FIELD("top_object", "uint64", 16, 8, SX_NONE),
    SX_FIELD("offset_table_offset", "uint64", 24, 8, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_trailer = { UINT32_C(0x60090067), "binary_plist_trailer", sx_b_binary_plist_trailer_fields, SX_COUNT(sx_b_binary_plist_trailer_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_offset1_fields[] = {
    SX_FIELD("object_offset", "uint8", 0, 1, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_offset1 = { UINT32_C(0x60090068), "binary_plist_offset1", sx_b_binary_plist_offset1_fields, SX_COUNT(sx_b_binary_plist_offset1_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_offset2_fields[] = {
    SX_FIELD("object_offset", "uint16", 0, 2, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_offset2 = { UINT32_C(0x60090069), "binary_plist_offset2", sx_b_binary_plist_offset2_fields, SX_COUNT(sx_b_binary_plist_offset2_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_offset3_fields[] = {
    SX_FIELD("object_offset", "uint24", 0, 3, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_offset3 = { UINT32_C(0x6009006A), "binary_plist_offset3", sx_b_binary_plist_offset3_fields, SX_COUNT(sx_b_binary_plist_offset3_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_offset4_fields[] = {
    SX_FIELD("object_offset", "uint32", 0, 4, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_offset4 = { UINT32_C(0x6009006B), "binary_plist_offset4", sx_b_binary_plist_offset4_fields, SX_COUNT(sx_b_binary_plist_offset4_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_offset5_fields[] = {
    SX_FIELD("object_offset", "uint40", 0, 5, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_offset5 = { UINT32_C(0x6009006C), "binary_plist_offset5", sx_b_binary_plist_offset5_fields, SX_COUNT(sx_b_binary_plist_offset5_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_offset6_fields[] = {
    SX_FIELD("object_offset", "uint48", 0, 6, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_offset6 = { UINT32_C(0x6009006D), "binary_plist_offset6", sx_b_binary_plist_offset6_fields, SX_COUNT(sx_b_binary_plist_offset6_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_offset7_fields[] = {
    SX_FIELD("object_offset", "uint56", 0, 7, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_offset7 = { UINT32_C(0x6009006E), "binary_plist_offset7", sx_b_binary_plist_offset7_fields, SX_COUNT(sx_b_binary_plist_offset7_fields), SX_BE };

static const xx_data_struct_field_desc sx_b_binary_plist_offset8_fields[] = {
    SX_FIELD("object_offset", "uint64", 0, 8, SX_OFFSET),
};
static const sx_layout sx_b_binary_plist_offset8 = { UINT32_C(0x6009006F), "binary_plist_offset8", sx_b_binary_plist_offset8_fields, SX_COUNT(sx_b_binary_plist_offset8_fields), SX_BE };

static const sx_layout *const sx_binary_layouts[] = {
    &sx_b_spirv_header_le,
    &sx_b_spirv_instruction_le,
    &sx_b_spirv_header_be,
    &sx_b_spirv_instruction_be,
    &sx_b_dxbc_header,
    &sx_b_dxbc_chunk_offset,
    &sx_b_dxbc_chunk_header,
    &sx_b_llvm_bitcode_wrapper,
    &sx_b_nintendo_3dsx_header,
    &sx_b_nintendo_3dsx_relocation_header,
    &sx_b_nintendo_3dsx_relocation,
    &sx_b_psx_exe_header,
    &sx_b_nintendo_dol_header,
    &sx_b_bflt_header,
    &sx_b_bflt_relocation,
    &sx_b_btf_header,
    &sx_b_btf_type,
    &sx_b_btf_integer,
    &sx_b_btf_array,
    &sx_b_btf_member,
    &sx_b_btf_enum,
    &sx_b_btf_enum64,
    &sx_b_btf_parameter,
    &sx_b_btf_variable,
    &sx_b_btf_datasec_entry,
    &sx_b_btf_decl_tag,
    &sx_b_minidump_header,
    &sx_b_minidump_directory,
    &sx_b_menuet_header,
    &sx_b_plan9_header_be,
    &sx_b_plan9_entry64,
    &sx_b_menuet_header0,
    &sx_b_menuet_header2,
    &sx_b_leveldb_writebatch_header,
    &sx_b_uimage_header,
    &sx_b_uimage_component_size,
    &sx_b_dtb_header_v2,
    &sx_b_dtb_header_v3,
    &sx_b_dtb_header,
    &sx_b_dtb_reservation,
    &sx_b_dtb_token,
    &sx_b_dtb_property_header,
    &sx_b_trx_header,
    &sx_b_seama_header,
    &sx_b_seama_digest,
    &sx_b_android_sparse_header,
    &sx_b_android_sparse_chunk,
    &sx_b_linux_arm64_header,
    &sx_b_linux_zimage_header_le,
    &sx_b_linux_zimage_header_be,
    &sx_b_uefi_capsule_header,
    &sx_b_uefi_fv_header,
    &sx_b_uefi_fv_block_map,
    &sx_b_uf2_block_header,
    &sx_b_uf2_block_end,
    &sx_b_android_dtbo_header,
    &sx_b_android_dtbo_entry,
    &sx_b_avb_vbmeta_header,
    &sx_b_avb_descriptor,
    &sx_b_quake_pak_header,
    &sx_b_quake_pak_entry,
    &sx_b_wad_header,
    &sx_b_doom_wad_entry,
    &sx_b_quake_wad_entry,
    &sx_b_build_grp_header,
    &sx_b_build_grp_entry,
    &sx_b_afs_header,
    &sx_b_afs_entry,
    &sx_b_nintendo_u8_header_le,
    &sx_b_nintendo_u8_file_node_le,
    &sx_b_nintendo_u8_directory_node_le,
    &sx_b_nintendo_u8_header_be,
    &sx_b_nintendo_u8_file_node_be,
    &sx_b_nintendo_u8_directory_node_be,
    &sx_b_bigf_header,
    &sx_b_bigf_directory_header,
    &sx_b_bigf_terminal_filler,
    &sx_b_bigf_entry,
    &sx_b_hog_header,
    &sx_b_hog_entry,
    &sx_b_gob_header,
    &sx_b_gob_jk_header,
    &sx_b_gob_directory_header,
    &sx_b_gob_entry,
    &sx_b_gob_jk_entry,
    &sx_b_mysql_binlog_header,
    &sx_b_mysql_binlog_event,
    &sx_b_sqlite_journal_header,
    &sx_b_sqlite_journal_page_number,
    &sx_b_sqlite_journal_checksum,
    &sx_b_leveldb_log_record,
    &sx_b_rocksdb_blob_header,
    &sx_b_rocksdb_blob_record,
    &sx_b_rocksdb_blob_footer,
    &sx_b_cdb_hash_table_header,
    &sx_b_cdb_record_header,
    &sx_b_cdb_hash_slot,
    &sx_b_btsnoop_header,
    &sx_b_btsnoop_packet,
    &sx_b_tfrecord_header,
    &sx_b_tfrecord_trailer,
    &sx_b_binary_plist_header,
    &sx_b_binary_plist_trailer,
    &sx_b_binary_plist_offset1,
    &sx_b_binary_plist_offset2,
    &sx_b_binary_plist_offset3,
    &sx_b_binary_plist_offset4,
    &sx_b_binary_plist_offset5,
    &sx_b_binary_plist_offset6,
    &sx_b_binary_plist_offset7,
    &sx_b_binary_plist_offset8,
};

static bool sx_binary_supports(xx_file_type_t type) {
    switch(type) {
    case XX_FILE_TYPE_SPIRV:
    case XX_FILE_TYPE_DXBC:
    case XX_FILE_TYPE_LLVM_BITCODE_WRAPPER:
    case XX_FILE_TYPE_NINTENDO_3DSX:
    case XX_FILE_TYPE_SONY_PSX_EXE:
    case XX_FILE_TYPE_NINTENDO_DOL:
    case XX_FILE_TYPE_BFLT:
    case XX_FILE_TYPE_LINUX_BTF:
    case XX_FILE_TYPE_MINIDUMP:
    case XX_FILE_TYPE_MENUET:
    case XX_FILE_TYPE_PLAN9_EXEC:
    case XX_FILE_TYPE_UIMAGE:
    case XX_FILE_TYPE_DTB:
    case XX_FILE_TYPE_TRX:
    case XX_FILE_TYPE_SEAMA:
    case XX_FILE_TYPE_SPARSE:
    case XX_FILE_TYPE_LINUX_ARM64:
    case XX_FILE_TYPE_LINUX_ZIMAGE:
    case XX_FILE_TYPE_UEFI_CAPSULE:
    case XX_FILE_TYPE_UEFI_FV:
    case XX_FILE_TYPE_UF2:
    case XX_FILE_TYPE_ANDROID_DTBO:
    case XX_FILE_TYPE_ANDROID_VBMETA:
    case XX_FILE_TYPE_QUAKE_PAK:
    case XX_FILE_TYPE_DOOM_WAD:
    case XX_FILE_TYPE_QUAKE_WAD2:
    case XX_FILE_TYPE_HALFLIFE_WAD3:
    case XX_FILE_TYPE_BUILD_GRP:
    case XX_FILE_TYPE_CRI_AFS:
    case XX_FILE_TYPE_NINTENDO_U8:
    case XX_FILE_TYPE_BIGF:
    case XX_FILE_TYPE_HOG:
    case XX_FILE_TYPE_GOB:
    case XX_FILE_TYPE_MYSQL_BINLOG:
    case XX_FILE_TYPE_SQLITE_ROLLBACK_JOURNAL:
    case XX_FILE_TYPE_LEVELDB_LOG:
    case XX_FILE_TYPE_ROCKSDB_BLOB:
    case XX_FILE_TYPE_CDB_DATABASE:
    case XX_FILE_TYPE_BTSNOOP:
    case XX_FILE_TYPE_TENSORFLOW_TFRECORD:
    case XX_FILE_TYPE_BINARY_PLIST:
        return true;
    default:return false;
    }
}

/* Native readers establish validity; this layer exposes bounded physical
 * metadata only. Unknown payloads, opcode operands, and extensions stay raw. */
static uint32_t sx_b_u32(sx_context *c,uint64_t o,bool be) {uint32_t v=0;if(o>INT64_MAX||!sx_u32(c,(int64_t)o,be,&v))c->failed=true;return v;}
static uint64_t sx_b_u64(sx_context *c,uint64_t o,bool be) {uint64_t v=0;if(o>INT64_MAX||!sx_u64(c,(int64_t)o,be,&v))c->failed=true;return v;}
static uint16_t sx_b_u16(sx_context *c,uint64_t o,bool be) {uint16_t v=0;if(o>INT64_MAX||!sx_u16(c,(int64_t)o,be,&v))c->failed=true;return v;}
static uint8_t sx_b_u8(sx_context *c,uint64_t o) {uint8_t v=0;if(o>INT64_MAX||!sx_read(c,(int64_t)o,&v,1))c->failed=true;return v;}
static bool sx_b_range(sx_context *c,uint64_t o,uint64_t n) {return o<=INT64_MAX&&sx_range(c,(int64_t)o,n);}
static int64_t sx_b_extent(const sx_layout *l) {int64_t n=0;for(size_t i=0;i<l->field_count;i++){int64_t e=l->fields[i].rel_offset+l->fields[i].size;if(e>n)n=e;}return n;}
static bool sx_b_record(sx_context *c,const sx_layout *l,uint64_t o) {return o<=INT64_MAX&&sx_add(c,l,(int64_t)o,sx_b_extent(l));}
static bool sx_b_table(sx_context *c,const sx_layout *l,uint64_t o,uint64_t n) {return o<=INT64_MAX&&sx_table(c,l,(int64_t)o,sx_b_extent(l),n);}
/* Heap sorting keeps pathological reverse-order directory pointers O(n log n). */
static void sx_b_sift(xx_data_struct *a,size_t n,size_t root) {
    while(root<n/2){size_t child=root*2+1;if(child+1<n&&a[child].offset<a[child+1].offset)child++;if(a[root].offset>=a[child].offset)break;xx_data_struct t=a[root];a[root]=a[child];a[child]=t;root=child;}
}
static void sx_b_sort(xx_data_struct *a,size_t n) {
    for(size_t i=n/2;i>0;i--)sx_b_sift(a,n,i-1);
    for(size_t i=n;i>1;i--){xx_data_struct t=a[0];a[0]=a[i-1];a[i-1]=t;sx_b_sift(a,i-1,0);}
}
static bool sx_b_finish(sx_context *c) {
    size_t n=c->count;uint64_t end=0;sx_b_sort(c->items,n);
    for(size_t i=0;i<n;i++) {xx_data_struct d=c->items[i];uint64_t at=(uint64_t)(d.offset-c->f->base_address);
        if(at<end)return false;
        if(at>end&&!sx_raw(c,(int64_t)end,(int64_t)(at-end)))return false;
        end=at+(uint64_t)d.total_size;
    }
    if(end>(uint64_t)c->size||!sx_raw(c,(int64_t)end,c->size-(int64_t)end))return false;
    sx_b_sort(c->items,c->count);return !c->failed;
}
static bool sx_b_btf(sx_context *c) {
    uint64_t h=sx_b_u32(c,4,false),at=h+sx_b_u32(c,8,false),end=at+sx_b_u32(c,12,false);
    if(!sx_b_record(c,&sx_b_btf_header,0)||end<at||!sx_b_range(c,at,end-at))return false;
    while(at<end) {
        uint32_t info=sx_b_u32(c,at+4,false),kind=(info>>24)&31,n=info&65535;uint64_t extra=0;const sx_layout *l=NULL;
        if(!sx_b_record(c,&sx_b_btf_type,at)||end-at<12)return false;at+=12;
        switch(kind){case 1:l=&sx_b_btf_integer;n=1;break;case 3:l=&sx_b_btf_array;n=1;break;
            case 4:case 5:l=&sx_b_btf_member;break;case 6:l=&sx_b_btf_enum;break;
            case 13:l=&sx_b_btf_parameter;break;case 14:l=&sx_b_btf_variable;n=1;break;
            case 15:l=&sx_b_btf_datasec_entry;break;case 17:l=&sx_b_btf_decl_tag;n=1;break;
            case 19:l=&sx_b_btf_enum64;break;default:n=0;break;}
        if(l){extra=(uint64_t)sx_b_extent(l)*n;if(extra>end-at||!sx_b_table(c,l,at,n))return false;}at+=extra;
    }return at==end;
}
static bool sx_b_dtb(sx_context *c) {
    uint32_t version=sx_b_u32(c,20,true);
    uint64_t total=sx_b_u32(c,4,true),at=sx_b_u32(c,16,true);
    uint64_t start=sx_b_u32(c,8,true),strings=sx_b_u32(c,12,true),length,end;
    const sx_layout *header=version==2?&sx_b_dtb_header_v2:version<17?&sx_b_dtb_header_v3:&sx_b_dtb_header;
    if(version<2||version>17||total>(uint64_t)c->size||start>total||!sx_b_record(c,header,0))return false;
    length=version>=17?sx_b_u32(c,36,true):(strings>start?strings-start:total-start);
    if(length>total-start||!sx_b_range(c,start,length))return false;end=start+length;
    for(unsigned n=0;n<65536;n++) {
        if(at>total||total-at<16)return false;
        uint64_t addr=sx_b_u64(c,at,true),len=sx_b_u64(c,at+8,true);
        if(!sx_b_record(c,&sx_b_dtb_reservation,at))return false;
        at+=16;if(!addr&&!len)break;if(n==65535)return false;
    }
    at=start;
    while(at<end) {
        if(end-at<4)return false;
        uint32_t token=sx_b_u32(c,at,true);
        if(token==3) {
            if(end-at<12)return false;
            uint32_t len=sx_b_u32(c,at+4,true);
            if(!sx_b_record(c,&sx_b_dtb_property_header,at))return false;at+=12;
            /* The legacy reader aligns the cursor within the structure block. */
            if(version<16&&len>=8)at=start+((at-start+7)&~UINT64_C(7));
            if(at>end||len>end-at)return false;at+=len;
        } else {
            if(!sx_b_record(c,&sx_b_dtb_token,at))return false;at+=4;
            if(token==9)return true; /* Remaining block padding is not a token. */
            if(token==1) {bool nul=false;while(at<end){if(!sx_b_u8(c,at++)){nul=true;break;}}if(!nul)return false;}
            else if(token!=2&&token!=4)return false;
        }
        at=start+((at-start+3)&~UINT64_C(3));
    }
    return false; /* A complete tree must contain FDT_END. */
}
static bool sx_binary_walk(sx_context *c) {
    uint64_t at=0,n=0,off=0,size=0,end=0;bool be=false;uint32_t v=0;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_SPIRV:
        be=sx_b_u32(c,0,true)==UINT32_C(0x07230203);
        if(!sx_b_record(c,be?&sx_b_spirv_header_be:&sx_b_spirv_header_le,0))return false;
        at=20;while(at<(uint64_t)c->size){v=sx_b_u32(c,at,be);size=(uint64_t)(v>>16)*4;if(size<4||!sx_b_range(c,at,size)||!sx_b_record(c,be?&sx_b_spirv_instruction_be:&sx_b_spirv_instruction_le,at))return false;at+=size;}break;
    case XX_FILE_TYPE_DXBC:
        n=sx_b_u32(c,28,false);if(!sx_b_record(c,&sx_b_dxbc_header,0)||!sx_b_table(c,&sx_b_dxbc_chunk_offset,32,n))return false;
        for(uint64_t i=0;i<n;i++){off=sx_b_u32(c,32+i*4,false);size=sx_b_u32(c,off+4,false);if(!sx_b_range(c,off,8+size)||!sx_b_record(c,&sx_b_dxbc_chunk_header,off))return false;}break;
    case XX_FILE_TYPE_LLVM_BITCODE_WRAPPER:return sx_b_record(c,&sx_b_llvm_bitcode_wrapper,0);
    case XX_FILE_TYPE_NINTENDO_3DSX:
        if(!sx_b_record(c,&sx_b_nintendo_3dsx_header,0)||!sx_b_table(c,&sx_b_nintendo_3dsx_relocation_header,32,3))return false;
        at=56+(uint64_t)sx_b_u32(c,16,false)+sx_b_u32(c,20,false)+sx_b_u32(c,24,false)-sx_b_u32(c,28,false);
        for(unsigned i=0;i<6;i++){n=sx_b_u32(c,32+i*4,false);if(!sx_b_table(c,&sx_b_nintendo_3dsx_relocation,at,n))return false;at+=n*4;}break;
    case XX_FILE_TYPE_SONY_PSX_EXE:return sx_b_record(c,&sx_b_psx_exe_header,0);
    case XX_FILE_TYPE_NINTENDO_DOL:return sx_b_record(c,&sx_b_nintendo_dol_header,0);
    case XX_FILE_TYPE_BFLT:
        if(!sx_b_record(c,&sx_b_bflt_header,0))return false;
        if(!(sx_b_u32(c,36,true)&12)){off=sx_b_u32(c,28,true);n=sx_b_u32(c,32,true);
            /* Native validity deliberately tolerates a missing relocation table. */
            if(n&&off>=64&&off<=(uint64_t)c->size&&n<=((uint64_t)c->size-off)/4&&n<=(UINT32_MAX-off)/4&&
               !sx_b_table(c,&sx_b_bflt_relocation,off,n))return false;}break;
    case XX_FILE_TYPE_LINUX_BTF:return sx_b_btf(c);
    case XX_FILE_TYPE_MINIDUMP:
        n=sx_b_u32(c,8,false);off=sx_b_u32(c,12,false);return sx_b_record(c,&sx_b_minidump_header,0)&&sx_b_table(c,&sx_b_minidump_directory,off,n);
    case XX_FILE_TYPE_MENUET:
        v=sx_b_u8(c,7);return v=='0'?sx_b_record(c,&sx_b_menuet_header0,0):v=='1'?sx_b_record(c,&sx_b_menuet_header,0):v=='2'?sx_b_record(c,&sx_b_menuet_header2,0):false;
    case XX_FILE_TYPE_PLAN9_EXEC:
        if(!sx_b_record(c,&sx_b_plan9_header_be,0))return false;
        if(sx_b_u32(c,0,true)&0x8000)return sx_b_record(c,&sx_b_plan9_entry64,32);break;
    case XX_FILE_TYPE_UIMAGE:
        if(!sx_b_record(c,&sx_b_uimage_header,0))return false;
        if(sx_b_u8(c,30)==4&&sx_b_u8(c,31)==0){at=64;do{v=sx_b_u32(c,at,true);if(!sx_b_record(c,&sx_b_uimage_component_size,at))return false;at+=4;}while(v);}break;
    case XX_FILE_TYPE_DTB:return sx_b_dtb(c);
    case XX_FILE_TYPE_TRX:return sx_b_record(c,&sx_b_trx_header,0);
    case XX_FILE_TYPE_SEAMA:
        at=0;while(at<(uint64_t)c->size){n=sx_b_u16(c,at+6,true);size=sx_b_u32(c,at+8,true);if(!sx_b_record(c,&sx_b_seama_header,at))return false;at+=12;if(size){if(!sx_b_record(c,&sx_b_seama_digest,at))return false;at+=16;}if(!sx_b_range(c,at,n+size))return false;at+=n+size;}break;
    case XX_FILE_TYPE_SPARSE:
        n=sx_b_u32(c,20,false);at=sx_b_u16(c,8,false);v=sx_b_u16(c,10,false);if(v<12||!sx_b_record(c,&sx_b_android_sparse_header,0))return false;
        for(uint64_t i=0;i<n;i++){size=sx_b_u32(c,at+8,false);if(size<v||!sx_b_range(c,at,size)||!sx_b_record(c,&sx_b_android_sparse_chunk,at))return false;at+=size;}break;
    case XX_FILE_TYPE_LINUX_ARM64:return sx_b_record(c,&sx_b_linux_arm64_header,0);
    case XX_FILE_TYPE_LINUX_ZIMAGE:
        be=sx_b_u32(c,36,true)==UINT32_C(0x016f2818);return sx_b_record(c,be?&sx_b_linux_zimage_header_be:&sx_b_linux_zimage_header_le,0);
    case XX_FILE_TYPE_UEFI_CAPSULE:return sx_b_record(c,&sx_b_uefi_capsule_header,0);
    case XX_FILE_TYPE_UEFI_FV:
        if(!sx_b_record(c,&sx_b_uefi_fv_header,0))return false;end=sx_b_u16(c,48,false);at=56;
        while(at<end){n=sx_b_u32(c,at,false);size=sx_b_u32(c,at+4,false);if(end-at<8||!sx_b_record(c,&sx_b_uefi_fv_block_map,at))return false;at+=8;if(!n&&!size)break;}break;
    case XX_FILE_TYPE_UF2:
        for(at=0;at<(uint64_t)c->size;at+=512)if(!sx_b_range(c,at,512)||!sx_b_record(c,&sx_b_uf2_block_header,at)||!sx_b_record(c,&sx_b_uf2_block_end,at+508))return false;break;
    case XX_FILE_TYPE_ANDROID_DTBO:
        if(sx_b_u32(c,12,true)!=32)return false;return sx_b_record(c,&sx_b_android_dtbo_header,0)&&sx_b_table(c,&sx_b_android_dtbo_entry,sx_b_u32(c,20,true),sx_b_u32(c,16,true));
    case XX_FILE_TYPE_ANDROID_VBMETA:
        if(!sx_b_record(c,&sx_b_avb_vbmeta_header,0))return false;
        off=sx_b_u64(c,12,true);at=sx_b_u64(c,96,true);size=sx_b_u64(c,104,true);if(off>INT64_MAX-256||at>INT64_MAX-256-off)return false;at+=256+off;if(!sx_b_range(c,at,size))return false;end=at+size;
        while(at<end){size=sx_b_u64(c,at+8,true);if(end-at<16||size>end-at-16||!sx_b_record(c,&sx_b_avb_descriptor,at))return false;at+=16+size;}break;
    case XX_FILE_TYPE_QUAKE_PAK:
        size=sx_b_u32(c,8,false);return !(size%64)&&sx_b_record(c,&sx_b_quake_pak_header,0)&&sx_b_table(c,&sx_b_quake_pak_entry,sx_b_u32(c,4,false),size/64);
    case XX_FILE_TYPE_DOOM_WAD:case XX_FILE_TYPE_QUAKE_WAD2:case XX_FILE_TYPE_HALFLIFE_WAD3:
        return sx_b_record(c,&sx_b_wad_header,0)&&sx_b_table(c,c->f->file_type==XX_FILE_TYPE_DOOM_WAD?&sx_b_doom_wad_entry:&sx_b_quake_wad_entry,sx_b_u32(c,8,false),sx_b_u32(c,4,false));
    case XX_FILE_TYPE_BUILD_GRP:return sx_b_record(c,&sx_b_build_grp_header,0)&&sx_b_table(c,&sx_b_build_grp_entry,16,sx_b_u32(c,12,false));
    case XX_FILE_TYPE_CRI_AFS:return sx_b_record(c,&sx_b_afs_header,0)&&sx_b_table(c,&sx_b_afs_entry,8,sx_b_u32(c,4,false));
    case XX_FILE_TYPE_NINTENDO_U8:
        be=sx_b_u32(c,0,true)==UINT32_C(0x55aa382d);off=sx_b_u32(c,4,be);n=sx_b_u32(c,off+8,be);
        if(!sx_b_record(c,be?&sx_b_nintendo_u8_header_be:&sx_b_nintendo_u8_header_le,0)||!sx_b_range(c,off,n*12))return false;
        for(uint64_t i=0;i<n;i++){at=off+i*12;v=sx_b_u32(c,at,be)>>24;const sx_layout *l=v?(be?&sx_b_nintendo_u8_directory_node_be:&sx_b_nintendo_u8_directory_node_le):(be?&sx_b_nintendo_u8_file_node_be:&sx_b_nintendo_u8_file_node_le);if(!sx_b_record(c,l,at))return false;}break;
    case XX_FILE_TYPE_BIGF:
        if(!sx_b_record(c,&sx_b_bigf_header,0)||!sx_b_record(c,&sx_b_bigf_directory_header,8))return false;n=sx_b_u32(c,8,true);at=16;
        for(uint64_t i=0;i<n;i++){
            if(i+1==n&&sx_b_u32(c,at,true)==UINT32_C(0xcdcdcdcd)&&sx_b_u32(c,at+4,true)==UINT32_C(0xcdcdcdcd)) {
                if(!sx_b_record(c,&sx_b_bigf_terminal_filler,at))return false;break;
            }
            if(!sx_b_record(c,&sx_b_bigf_entry,at))return false;at+=8;bool nul=false;
            for(unsigned j=0;j<=4096&&at<(uint64_t)c->size;j++){if(!sx_b_u8(c,at++)){nul=true;break;}}if(!nul)return false;
        }break;
    case XX_FILE_TYPE_HOG:
        if(!sx_b_record(c,&sx_b_hog_header,0))return false;at=3;
        while(at<(uint64_t)c->size){size=sx_b_u32(c,at+13,false);if(!sx_b_range(c,at,17+size)||!sx_b_record(c,&sx_b_hog_entry,at))return false;at+=17+size;}break;
    case XX_FILE_TYPE_GOB:
        be=sx_b_u8(c,3)==' ';off=sx_b_u32(c,be?8:4,false);n=sx_b_u32(c,off,false);
        return sx_b_record(c,be?&sx_b_gob_jk_header:&sx_b_gob_header,0)&&sx_b_record(c,&sx_b_gob_directory_header,off)&&sx_b_table(c,be?&sx_b_gob_jk_entry:&sx_b_gob_entry,off+4,n);
    case XX_FILE_TYPE_MYSQL_BINLOG:
        if(!sx_b_record(c,&sx_b_mysql_binlog_header,0))return false;at=4;
        while(at<(uint64_t)c->size){size=sx_b_u32(c,at+9,false);if(size<19||!sx_b_range(c,at,size)||!sx_b_record(c,&sx_b_mysql_binlog_event,at))return false;at+=size;}break;
    case XX_FILE_TYPE_SQLITE_ROLLBACK_JOURNAL:
        while(at<(uint64_t)c->size){n=sx_b_u32(c,at+8,true);size=sx_b_u32(c,at+24,true);off=sx_b_u32(c,at+20,true);if(!off||size>65536||!sx_b_record(c,&sx_b_sqlite_journal_header,at)||!sx_b_range(c,at,off))return false;at+=off;if(n==UINT32_MAX)n=((uint64_t)c->size-at)/(size+8);
            for(uint64_t i=0;i<n;i++){if(!sx_b_range(c,at,size+8)||!sx_b_record(c,&sx_b_sqlite_journal_page_number,at)||!sx_b_record(c,&sx_b_sqlite_journal_checksum,at+4+size))return false;at+=size+8;}
            if(at<(uint64_t)c->size){if(at>INT64_MAX-off)return false;at=(at+off-1)/off*off;}}
        break;
    case XX_FILE_TYPE_LEVELDB_LOG:
        while(at<(uint64_t)c->size){off=32768-at%32768;if(off<7){if(!sx_b_range(c,at,off))return false;at+=off;continue;}size=sx_b_u16(c,at+4,false);if(size>off-7||!sx_b_range(c,at,7+size)||!sx_b_record(c,&sx_b_leveldb_log_record,at))return false;if(size>=12&&sx_b_u8(c,at+6)==1&&!sx_b_record(c,&sx_b_leveldb_writebatch_header,at+7))return false;at+=7+size;}break;
    case XX_FILE_TYPE_ROCKSDB_BLOB:
        if(c->size<62||!sx_b_record(c,&sx_b_rocksdb_blob_header,0)||!sx_b_record(c,&sx_b_rocksdb_blob_footer,(uint64_t)c->size-32))return false;at=30;end=(uint64_t)c->size-32;
        while(at<end){n=sx_b_u64(c,at,false);size=sx_b_u64(c,at+8,false);if(end-at<32||n>end-at-32||size>end-at-32-n||!sx_b_record(c,&sx_b_rocksdb_blob_record,at))return false;at+=32+n+size;}break;
    case XX_FILE_TYPE_CDB_DATABASE:
        if(!sx_b_table(c,&sx_b_cdb_hash_table_header,0,256))return false;end=(uint64_t)c->size;
        for(unsigned i=0;i<256;i++){off=sx_b_u32(c,i*8,false);n=sx_b_u32(c,i*8+4,false);if(n){if(off<end)end=off;if(!sx_b_table(c,&sx_b_cdb_hash_slot,off,n))return false;}}
        at=2048;while(at<end){n=sx_b_u32(c,at,false);size=sx_b_u32(c,at+4,false);if(end-at<8||n>end-at-8||size>end-at-8-n||!sx_b_record(c,&sx_b_cdb_record_header,at))return false;at+=8+n+size;}break;
    case XX_FILE_TYPE_BTSNOOP:
        if(!sx_b_record(c,&sx_b_btsnoop_header,0))return false;at=16;while(at<(uint64_t)c->size){size=sx_b_u32(c,at+4,true);if(!sx_b_range(c,at,24+size)||!sx_b_record(c,&sx_b_btsnoop_packet,at))return false;at+=24+size;}break;
    case XX_FILE_TYPE_TENSORFLOW_TFRECORD:
        while(at<(uint64_t)c->size){size=sx_b_u64(c,at,false);if((uint64_t)c->size-at<16||size>(uint64_t)c->size-at-16||!sx_b_record(c,&sx_b_tfrecord_header,at)||!sx_b_record(c,&sx_b_tfrecord_trailer,at+12+size))return false;at+=16+size;}break;
    case XX_FILE_TYPE_BINARY_PLIST:
        if(c->size<40)return false;at=(uint64_t)c->size-32;n=sx_b_u64(c,at+8,true);off=sx_b_u64(c,at+24,true);v=sx_b_u8(c,at+6);
        if(!sx_b_record(c,&sx_b_binary_plist_header,0)||!sx_b_record(c,&sx_b_binary_plist_trailer,at))return false;
        const sx_layout *const widths[]={&sx_b_binary_plist_offset1,&sx_b_binary_plist_offset2,&sx_b_binary_plist_offset3,&sx_b_binary_plist_offset4,&sx_b_binary_plist_offset5,&sx_b_binary_plist_offset6,&sx_b_binary_plist_offset7,&sx_b_binary_plist_offset8};
        return v>=1&&v<=8&&off>=8&&off<=at&&n<=(at-off)/v&&sx_b_table(c,widths[v-1],off,n);
    default:return false;
    }return !c->failed;
}
static bool sx_binary_build(sx_context *c) {
    if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    return sx_binary_walk(c)&&c->count>0&&sx_b_finish(c);
}
static bool sx_binary_comment(xx_data_struct_record *r,uint32_t id) {
    if(!r||!r->name||id<UINT32_C(0x60090000)||id>UINT32_C(0x6009ffff))return true;
    const wchar_t *comment=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(id==sx_b_spirv_instruction_le.id||id==sx_b_spirv_instruction_be.id){if(!xx_rt_wcscmp(r->name,L"word_count"))comment=L"Number of 32-bit words, including the instruction word";else if(v==14)comment=L"OpMemoryModel";else if(v==17)comment=L"OpCapability";}
    else if((id==sx_b_dtb_token.id||id==sx_b_dtb_property_header.id)&&!xx_rt_wcscmp(r->name,L"token"))comment=v==1?L"FDT_BEGIN_NODE":v==2?L"FDT_END_NODE":v==3?L"FDT_PROP":v==4?L"FDT_NOP":v==9?L"FDT_END":NULL;
    else if(id==sx_b_spirv_header_le.id||id==sx_b_spirv_header_be.id){if(!xx_rt_wcscmp(r->name,L"bound"))comment=L"Upper bound of all result identifiers; not the instruction count";}
    else if(id==sx_b_bflt_header.id&&!xx_rt_wcscmp(r->name,L"cpu_type_or_filler4"))comment=L"Fifth filler word; some toolchains store the CPU identifier here";
    else if(id==sx_b_bigf_terminal_filler.id)comment=L"Terminal 0xCDCDCDCD padding; no member payload or name";
    else if(id==sx_b_btf_type.id&&!xx_rt_wcscmp(r->name,L"info"))comment=L"Kind bits 24..28; vlen bits 0..15; kind_flag bit 31";
    else if(id==sx_b_btf_member.id&&!xx_rt_wcscmp(r->name,L"bit_offset"))comment=L"Bit offset; with kind_flag, upper 8 bits hold bitfield width";
    else if((id==sx_b_nintendo_u8_file_node_le.id||id==sx_b_nintendo_u8_file_node_be.id||id==sx_b_nintendo_u8_directory_node_le.id||id==sx_b_nintendo_u8_directory_node_be.id)&&!xx_rt_wcscmp(r->name,L"type_and_name_offset"))comment=L"Node type in upper 8 bits; string-table byte offset in lower 24 bits";
    else if(id==sx_b_android_sparse_chunk.id){if(!xx_rt_wcscmp(r->name,L"chunk_blocks"))comment=L"Logical output blocks";else if(!xx_rt_wcscmp(r->name,L"chunk_type"))comment=v==0xcac1?L"CHUNK_TYPE_RAW":v==0xcac2?L"CHUNK_TYPE_FILL":v==0xcac3?L"CHUNK_TYPE_DONT_CARE":v==0xcac4?L"CHUNK_TYPE_CRC32":NULL;}
    else if(id==sx_b_uf2_block_header.id&&!xx_rt_wcscmp(r->name,L"file_size_or_family_id"))comment=L"Family identifier when flag 0x2000 is set; otherwise file size";
    else if(id==sx_b_btsnoop_packet.id&&!xx_rt_wcscmp(r->name,L"timestamp_us"))comment=L"Microseconds in the BTSnoop epoch";
    else if(id==sx_b_leveldb_log_record.id&&!xx_rt_wcscmp(r->name,L"type"))comment=v==1?L"FULL":v==2?L"FIRST":v==3?L"MIDDLE":v==4?L"LAST":NULL;
    else if(id==sx_b_avb_vbmeta_header.id&&!xx_rt_wcscmp(r->name,L"algorithm_type"))comment=v==0?L"AVB_ALGORITHM_TYPE_NONE":NULL;
    return !comment||xx_data_struct_record_set_comment(r,comment);
}

const sx_family sx_binary_family={sx_binary_supports,sx_binary_build,sx_binary_layouts,SX_COUNT(sx_binary_layouts),sx_binary_comment};
