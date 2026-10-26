/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The volume schema family: what its family unit (xx_format_schema_volume.c)
 * and its formats' data files share. Formats: MBR partition table; GPT partition table; SGI volume header; Rio Karma partitions; Minix partitions; Atari AHDI partitions; Apricot partitions. */
#ifndef XX_FORMAT_SCHEMA_VOLUME_H
#define XX_FORMAT_SCHEMA_VOLUME_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_v_sgi_volume_header;
extern const sx_layout sx_v_sgi_device_parameters;
extern const sx_layout sx_v_sgi_volume_directory_entry;
extern const sx_layout sx_v_sgi_partition_entry;
extern const sx_layout sx_v_sgi_volume_header_footer;
extern const sx_layout sx_v_rio_karma_partition_entry;
extern const sx_layout sx_v_rio_karma_partition_footer;
extern const sx_layout sx_v_minix_mbr_partition_entry;
extern const sx_layout sx_v_minix_mbr_signature;
extern const sx_layout sx_v_atari_partition_entry;
extern const sx_layout sx_v_atari_disk_size;
extern const sx_layout sx_v_atari_bad_sector_list;
extern const sx_layout sx_v_apricot_label_header;
extern const sx_layout sx_v_apricot_parameter_block;
extern const sx_layout sx_v_apricot_configuration;
extern const sx_layout sx_v_apricot_bad_block_entry;
extern const sx_layout sx_v_apricot_label_footer;
extern const sx_layout sx_v_mbr_disk_signature;
extern const sx_layout sx_v_mbr_partition_entry;
extern const sx_layout sx_v_mbr_boot_signature;
extern const sx_layout sx_v_gpt_header;
extern const sx_layout sx_v_gpt_partition_entry;
bool sx_v_fits(const sx_context *c,uint64_t o,uint64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_mbr_build(sx_context *c);  /* filesystem/mbr/xx_mbr_data.c */
bool sx_gpt_build(sx_context *c);  /* filesystem/gpt/xx_gpt_data.c */
bool sx_sgi_volume_header_build(sx_context *c);  /* filesystem/sgi_volume_header/xx_sgi_volume_header_data.c */
bool sx_rio_karma_partitions_build(sx_context *c);  /* filesystem/rio_karma_partitions/xx_rio_karma_partitions_data.c */
bool sx_minix_partitions_build(sx_context *c);  /* filesystem/minix_partitions/xx_minix_partitions_data.c */
bool sx_atari_ahdi_build(sx_context *c);  /* filesystem/atari_ahdi/xx_atari_ahdi_data.c */
bool sx_apricot_partitions_build(sx_context *c);  /* filesystem/apricot_partitions/xx_apricot_partitions_data.c */

#endif
