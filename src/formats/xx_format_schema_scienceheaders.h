/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The scienceheaders schema family: what its family unit (xx_format_schema_scienceheaders.c)
 * and its formats' data files share. Formats: BLACKROCK_NSX; BLACKROCK_NEV; PRINCETON_SPE; CHARMM_DCD; GROMACS_TRR; NETCDF_CLASSIC; FCS; EDF; BIOMEDICAL_BDF; SEISMIC_SEGY. */
#ifndef XX_FORMAT_SCHEMA_SCIENCEHEADERS_H
#define XX_FORMAT_SCHEMA_SCIENCEHEADERS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsh_nsx_header;
extern const sx_layout sxsh_nsx_channel;
extern const sx_layout sxsh_nsx_packet;
extern const sx_layout sxsh_nev_header;
extern const sx_layout sxsh_nev_extension;
extern const sx_layout sxsh_nev_text_extension;
extern const sx_layout sxsh_nev_waveform_extension;
extern const sx_layout sxsh_nev_label_extension;
extern const sx_layout sxsh_nev_filter_extension;
extern const sx_layout sxsh_nev_spike;
extern const sx_layout sxsh_nev_digital;
extern const sx_layout sxsh_spe_header;
extern const sx_layout sxsh_dcd_header_le;
extern const sx_layout sxsh_dcd_record_size_le;
extern const sx_layout sxsh_dcd_title_count_le;
extern const sx_layout sxsh_dcd_atom_count_le;
extern const sx_layout sxsh_dcd_cell_le;
extern const sx_layout sxsh_dcd_header_be;
extern const sx_layout sxsh_dcd_record_size_be;
extern const sx_layout sxsh_dcd_title_count_be;
extern const sx_layout sxsh_dcd_atom_count_be;
extern const sx_layout sxsh_dcd_cell_be;
extern const sx_layout sxsh_dcd_title;
extern const sx_layout sxsh_trr_header;
extern const sx_layout sxsh_trr_time32;
extern const sx_layout sxsh_trr_time64;
extern const sx_layout sxsh_netcdf_header;
extern const sx_layout sxsh_netcdf_list;
extern const sx_layout sxsh_netcdf_name_size;
extern const sx_layout sxsh_netcdf_dimension;
extern const sx_layout sxsh_netcdf_rank;
extern const sx_layout sxsh_netcdf_dimension_id;
extern const sx_layout sxsh_netcdf_attribute;
extern const sx_layout sxsh_netcdf_variable32;
extern const sx_layout sxsh_netcdf_variable64;
extern const sx_layout sxsh_fcs_header;
extern const sx_layout sxsh_segy_binary_header;
extern const sx_layout sxsh_segy_trace_header;
extern const sx_layout sxsh_segy_text_card;
uint16_t sxsh16(const uint8_t *p,bool be);
uint32_t sxsh32(const uint8_t *p,bool be);
bool sxsh_span(sx_context *c,int64_t at,uint64_t n);
bool sxsh_add(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes);
bool sxsh_table(sx_context *c,const sx_layout *l,int64_t at,int64_t bytes,uint64_t count);
bool sxsh_finish(sx_context *c);
bool sxsh_edf(sx_context *c);

/* Per-format walkers, called by the family's build. */
bool sx_blackrock_nsx_build(sx_context *c);  /* science/blackrock_nsx/xx_blackrock_nsx_data.c */
bool sx_blackrock_nev_build(sx_context *c);  /* science/blackrock_nev/xx_blackrock_nev_data.c */
bool sx_princeton_spe_build(sx_context *c);  /* science/princeton_spe/xx_princeton_spe_data.c */
bool sx_charmm_dcd_build(sx_context *c);  /* science/charmm_dcd/xx_charmm_dcd_data.c */
bool sx_gromacs_trr_build(sx_context *c);  /* science/gromacs_trr/xx_gromacs_trr_data.c */
bool sx_netcdf_classic_build(sx_context *c);  /* science/netcdf_classic/xx_netcdf_classic_data.c */
bool sx_fcs_build(sx_context *c);  /* science/fcs/xx_fcs_data.c */
bool sx_edf_build(sx_context *c);  /* science/edf/xx_edf_data.c */
bool sx_biomedical_bdf_build(sx_context *c);  /* science/biomedical_bdf/xx_biomedical_bdf_data.c */
bool sx_seismic_segy_build(sx_context *c);  /* science/seismic_segy/xx_seismic_segy_data.c */

#endif
