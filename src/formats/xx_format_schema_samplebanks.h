/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The samplebanks schema family: what its family unit (xx_format_schema_samplebanks.c)
 * and its formats' data files share. Formats: emax disk; emulatorii eii; casio fzf. */
#ifndef XX_FORMAT_SCHEMA_SAMPLEBANKS_H
#define XX_FORMAT_SCHEMA_SAMPLEBANKS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsb_emaxutil_marker;
extern const sx_layout sxsb_emax_bank_header;
extern const sx_layout sxsb_emax_preset_header;
extern const sx_layout sxsb_emax_key_area;
extern const sx_layout sxsb_emax_voice;
extern const sx_layout sxsb_emax_sample_entry;
extern const sx_layout sxsb_emulator2_selected_name;
extern const sx_layout sxsb_emulator2_keymaps;
extern const sx_layout sxsb_emulator2_preset_header;
extern const sx_layout sxsb_emulator2_selection;
extern const sx_layout sxsb_emulator2_preset_length;
extern const sx_layout sxsb_emulator2_key_range;
extern const sx_layout sxsb_emulator2_secondary_voice;
extern const sx_layout sxsb_emulator2_key_range_end;
extern const sx_layout sxsb_emulator2_voice;
extern const sx_layout sxsb_casio_fz_bank;
extern const sx_layout sxsb_casio_fz_voice;
extern const sx_layout sxsb_casio_fz_effect;
extern const sx_layout sxsb_casio_fzf_dump_workspace;
bool sxsb_read(sx_context*c,uint64_t p,void*b,size_t n);
uint32_t sxsb16(const uint8_t*b);
uint32_t sxsb24(const uint8_t*b);
uint32_t sxsb32(const uint8_t*b);
bool sxsb_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_emax_disk_build(sx_context *c);  /* audio/emax_disk/xx_emax_disk_data.c */
bool sx_emulatorii_eii_build(sx_context *c);  /* audio/emulatorii_eii/xx_emulatorii_eii_data.c */
bool sx_casio_fzf_build(sx_context *c);  /* audio/casio_fzf/xx_casio_fzf_data.c */

#endif
