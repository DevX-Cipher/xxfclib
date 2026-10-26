/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The executablemore schema family: what its family unit (xx_format_schema_executablemore.c)
 * and its formats' data files share. Formats: AMIGAHUNK; DOS16M/DOS4G; RESOURCEFORK; XBOX_XBE; MICROSOFT_MSF; PYC; VTECH_VZ; XAMARIN_COMPRESSED_ASSEMBLY; MUB; CGC; NINTENDO_NRO; NINTENDO_NSO; WINDOWS_DMP64; OMF; XTAC; PEBBLE; HP_SOM; QNX_LMF; NINTENDO_REL; XCOFF. */
#ifndef XX_FORMAT_SCHEMA_EXECUTABLEMORE_H
#define XX_FORMAT_SCHEMA_EXECUTABLEMORE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxexm_vz_header;
extern const sx_layout sxexm_xalz_header;
extern const sx_layout sxexm_pyc_header8;
extern const sx_layout sxexm_pyc_header12;
extern const sx_layout sxexm_pyc_header16_timestamp;
extern const sx_layout sxexm_pyc_header16_hash;
extern const sx_layout sxexm_msf7_superblock;
extern const sx_layout sxexm_msf7_directory_block;
extern const sx_layout sxexm_msf7_stream_count;
extern const sx_layout sxexm_msf7_stream_size;
extern const sx_layout sxexm_msf7_stream_block;
extern const sx_layout sxexm_mub_header_le;
extern const sx_layout sxexm_mub_arch32_le;
extern const sx_layout sxexm_mub_header_be;
extern const sx_layout sxexm_mub_arch32_be;
extern const sx_layout sxexm_mub_arch64_be;
extern const sx_layout sxexm_resource_fork_header;
extern const sx_layout sxexm_resource_map_header;
extern const sx_layout sxexm_resource_type_count;
extern const sx_layout sxexm_resource_type_entry;
extern const sx_layout sxexm_resource_reference;
extern const sx_layout sxexm_resource_data_length;
extern const sx_layout sxexm_resource_name_length;
extern const sx_layout sxexm_pebble_header;
extern const sx_layout sxexm_pebble_relocation;
extern const sx_layout sxexm_nro_start;
extern const sx_layout sxexm_nro_header;
extern const sx_layout sxexm_nro_asset_header;
extern const sx_layout sxexm_nso_header;
extern const sx_layout sxexm_xbe_header;
extern const sx_layout sxexm_xbe_section;
extern const sx_layout sxexm_xbe_certificate;
extern const sx_layout sxexm_dmp64_prefix;
extern const sx_layout sxexm_dmp64_type;
extern const sx_layout sxexm_dmp64_required_space;
extern const sx_layout sxexm_dmp64_product;
extern const sx_layout sxexm_dmp64_bitmap_header;
extern const sx_layout sxexm_cgc_header_le;
extern const sx_layout sxexm_cgc_header_be;
extern const sx_layout sxexm_cgc_program_header_le;
extern const sx_layout sxexm_cgc_program_header_be;
extern const sx_layout sxexm_cgc_section_header_le;
extern const sx_layout sxexm_cgc_section_header_be;
extern const sx_layout sxexm_rel_header;
extern const sx_layout sxexm_rel_v2_extension;
extern const sx_layout sxexm_rel_v3_extension;
extern const sx_layout sxexm_rel_section;
extern const sx_layout sxexm_rel_import;
extern const sx_layout sxexm_rel_relocation;
extern const sx_layout sxexm_xtac_header;
extern const sx_layout sxexm_xtac_address_pair;
extern const sx_layout sxexm_xtac_block_stub;
extern const sx_layout sxexm_xtac_linked_entry0;
extern const sx_layout sxexm_xtac_linked_entry1;
extern const sx_layout sxexm_xtac_linked_entry2;
extern const sx_layout sxexm_xtac_linked_entry3;
extern const sx_layout sxexm_qnx_record_header;
extern const sx_layout sxexm_qnx_module_header;
extern const sx_layout sxexm_qnx_segment;
extern const sx_layout sxexm_qnx_load_header;
extern const sx_layout sxexm_qnx_resource_header;
extern const sx_layout sxexm_qnx_read_write_end;
extern const sx_layout sxexm_qnx_image_end;
extern const sx_layout sxexm_omf_record_header;
extern const sx_layout sxexm_omf_checksum;
extern const sx_layout sxexm_omf_name_length;
extern const sx_layout sxexm_dos_extender_mz;
extern const sx_layout sxexm_dos16m_bw_header;
extern const sx_layout sxexm_dos16m_mf_header;
extern const sx_layout sxexm_amiga_hunk_tag;
extern const sx_layout sxexm_amiga_hunk_length;
extern const sx_layout sxexm_amiga_hunk_table;
extern const sx_layout sxexm_amiga_hunk_allocation;
extern const sx_layout sxexm_amiga_memory_flags;
extern const sx_layout sxexm_amiga_relocation_count16;
extern const sx_layout sxexm_amiga_relocation_target16;
extern const sx_layout sxexm_amiga_relocation_offset16;
extern const sx_layout sxexm_amiga_relocation_count32;
extern const sx_layout sxexm_amiga_relocation_target32;
extern const sx_layout sxexm_amiga_relocation_offset32;
extern const sx_layout sxexm_amiga_symbol_value;
extern const sx_layout sxexm_amiga_ext_name;
extern const sx_layout sxexm_amiga_common_size;
extern const sx_layout sxexm_som_header;
extern const sx_layout sxexm_som_space;
extern const sx_layout sxexm_som_subspace_initialized;
extern const sx_layout sxexm_som_subspace_pattern;
extern const sx_layout sxexm_som_symbol;
extern const sx_layout sxexm_xcoff32_file_header;
extern const sx_layout sxexm_xcoff32_optional_header;
extern const sx_layout sxexm_xcoff32_section;
extern const sx_layout sxexm_xcoff32_loader;
extern const sx_layout sxexm_xcoff32_loader_symbol_inline;
extern const sx_layout sxexm_xcoff32_loader_symbol_external;
bool sxexm_span(sx_context *c,uint64_t p,uint64_t n);
bool sxexm_read(sx_context *c,uint64_t p,void *b,size_t n);
uint64_t sxexm_uint(const uint8_t *b,unsigned n,bool be);
uint16_t sxexm16(const uint8_t *b,bool be);
uint32_t sxexm32(const uint8_t *b,bool be);
bool sxexm_free(sx_context *c,uint64_t p,uint64_t n);
bool sxexm_add(sx_context *c,const sx_layout *l,uint64_t p);
bool sxexm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n);
bool sxexm_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v);
bool sxexm_finish(sx_context *c);

/* Per-format walkers, called by the family's build. */
bool sx_amigahunk_build(sx_context *c);  /* executable/amigahunk/xx_amigahunk_data.c */
bool sx_dos16m_build(sx_context *c);  /* executable/dos16m/xx_dos16m_data.c */
bool sx_resourcefork_build(sx_context *c);  /* executable/resourcefork/xx_resourcefork_data.c */
bool sx_xbox_xbe_build(sx_context *c);  /* executable/xbox_xbe/xx_xbox_xbe_data.c */
bool sx_microsoft_msf_build(sx_context *c);  /* executable/microsoft_msf/xx_microsoft_msf_data.c */
bool sx_pyc_build(sx_context *c);  /* executable/pyc/xx_pyc_data.c */
bool sx_vtech_vz_build(sx_context *c);  /* executable/vtech_vz/xx_vtech_vz_data.c */
bool sx_xamarin_compressed_assembly_build(sx_context *c);  /* executable/xamarin_compressed_assembly/xx_xamarin_compressed_assembly_data.c */
bool sx_mub_build(sx_context *c);  /* executable/mub/xx_mub_data.c */
bool sx_cgc_build(sx_context *c);  /* executable/cgc/xx_cgc_data.c */
bool sx_nintendo_nro_build(sx_context *c);  /* executable/nintendo_nro/xx_nintendo_nro_data.c */
bool sx_nintendo_nso_build(sx_context *c);  /* executable/nintendo_nso/xx_nintendo_nso_data.c */
bool sx_windows_dmp64_build(sx_context *c);  /* executable/windows_dmp64/xx_windows_dmp64_data.c */
bool sx_omf_build(sx_context *c);  /* executable/omf/xx_omf_data.c */
bool sx_xtac_build(sx_context *c);  /* executable/xtac/xx_xtac_data.c */
bool sx_pebble_build(sx_context *c);  /* executable/pebble/xx_pebble_data.c */
bool sx_hp_som_build(sx_context *c);  /* executable/hp_som/xx_hp_som_data.c */
bool sx_qnx_lmf_build(sx_context *c);  /* executable/qnx_lmf/xx_qnx_lmf_data.c */
bool sx_nintendo_rel_build(sx_context *c);  /* executable/nintendo_rel/xx_nintendo_rel_data.c */
bool sx_xcoff_build(sx_context *c);  /* executable/xcoff/xx_xcoff_data.c */

#endif
