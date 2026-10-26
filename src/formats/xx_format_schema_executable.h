/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The executable schema family: what its family unit (xx_format_schema_executable.c)
 * and its formats' data files share. Formats: MSDOS; DEX; MACHOFAT; COFF object file; UEFI TE executable; wasm. */
#ifndef XX_FORMAT_SCHEMA_EXECUTABLE_H
#define XX_FORMAT_SCHEMA_EXECUTABLE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_dex_header_le;
extern const sx_layout sx_dex_header_be;
extern const sx_layout sx_dex_map_list_le;
extern const sx_layout sx_dex_map_list_be;
extern const sx_layout sx_dex_map_item_le;
extern const sx_layout sx_dex_map_item_be;
extern const sx_layout sx_dex_string_id_item_le;
extern const sx_layout sx_dex_string_id_item_be;
extern const sx_layout sx_dex_type_id_item_le;
extern const sx_layout sx_dex_type_id_item_be;
extern const sx_layout sx_dex_proto_id_item_le;
extern const sx_layout sx_dex_proto_id_item_be;
extern const sx_layout sx_dex_field_id_item_le;
extern const sx_layout sx_dex_field_id_item_be;
extern const sx_layout sx_dex_method_id_item_le;
extern const sx_layout sx_dex_method_id_item_be;
extern const sx_layout sx_dex_class_def_item_le;
extern const sx_layout sx_dex_class_def_item_be;
extern const sx_layout sx_dex_call_site_id_item_le;
extern const sx_layout sx_dex_call_site_id_item_be;
extern const sx_layout sx_dex_method_handle_item_le;
extern const sx_layout sx_dex_method_handle_item_be;
extern const sx_layout sx_fat_header_le;
extern const sx_layout sx_fat_header_be;
extern const sx_layout sx_fat_arch_le;
extern const sx_layout sx_fat_arch_be;
extern const sx_layout sx_fat_arch_64_le;
extern const sx_layout sx_fat_arch_64_be;
extern const sx_layout sx_wasm_header;
extern const sx_layout sx_wasm_section_header_1;
extern const sx_layout sx_wasm_section_header_2;
extern const sx_layout sx_wasm_section_header_3;
extern const sx_layout sx_wasm_section_header_4;
extern const sx_layout sx_wasm_section_header_5;
extern const sx_layout sx_mz_header;
extern const sx_layout sx_mz_extended_header;
extern const sx_layout sx_mz_relocation;
bool sx_coff_build(sx_context *c,bool te);

/* Per-format walkers, called by the family's build. */
bool sx_msdos_build(sx_context *c);  /* executable/msdos/xx_msdos_data.c */
bool sx_dex_schema_build(sx_context *c);  /* executable/dex/xx_dex_data.c */
bool sx_machofat_build(sx_context *c);  /* executable/machofat/xx_machofat_data.c */
bool sx_coff_object_build(sx_context *c);  /* executable/coff_object/xx_coff_object_data.c */
bool sx_te_executable_build(sx_context *c);  /* executable/te_executable/xx_te_executable_data.c */
bool sx_wasm_schema_build(sx_context *c);  /* executable/wasm/xx_wasm_data.c */

#endif
