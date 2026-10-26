/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The executabletail schema family: what its family unit (xx_format_schema_executabletail.c)
 * and its formats' data files share. Formats: MoleBox; Executable overlay. */
#ifndef XX_FORMAT_SCHEMA_EXECUTABLETAIL_H
#define XX_FORMAT_SCHEMA_EXECUTABLETAIL_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxexo_molebox_package_prefix;
extern const sx_layout sxexo_molebox_encrypted_tree;
extern const sx_layout sxexo_molebox_encrypted_header;
extern const sx_layout sxexo_molebox_encrypted_catalog;
extern const sx_layout sxexo_molebox_encrypted_catalog_footer;
extern const sx_layout sxexo_overlay_dos_header;
extern const sx_layout sxexo_overlay_dos_e_res;
extern const sx_layout sxexo_overlay_dos_e_oemid;
extern const sx_layout sxexo_overlay_dos_e_oeminfo;
extern const sx_layout sxexo_overlay_dos_e_res2;
extern const sx_layout sxexo_overlay_dos_e_lfanew;
extern const sx_layout sxexo_overlay_dos_relocation;
extern const sx_layout sxexo_overlay_pe_signature;
extern const sx_layout sxexo_overlay_coff_header;
extern const sx_layout sxexo_overlay_pe_optional32;
extern const sx_layout sxexo_overlay_pe_optional64;
extern const sx_layout sxexo_overlay_pe_directory;
extern const sx_layout sxexo_overlay_pe_security_directory;
extern const sx_layout sxexo_overlay_pe_section;
extern const sx_layout sxexo_overlay_ne_header;
extern const sx_layout sxexo_overlay_ne_segment;

/* Per-format walkers, called by the family's build. */
bool sx_molebox_build(sx_context *c);  /* executable/molebox/xx_molebox_data.c */
bool sx_executable_overlay_build(sx_context *c);  /* executable/executable_overlay/xx_executable_overlay_data.c */

#endif
