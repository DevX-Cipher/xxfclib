/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The volumeimages schema family: what its family unit (xx_format_schema_volumeimages.c)
 * and its formats' data files share. Formats: Lvm2; Md Raid; Windows Ldm; Bsd Disklabel; Sunvtoc; Nextstep Diskimage; Aff; Partimage; Btrfs Stream; Diskjuggler; Mds; Uif; Gbi; Hsf; Aaruformat; Zisofs. */
#ifndef XX_FORMAT_SCHEMA_VOLUMEIMAGES_H
#define XX_FORMAT_SCHEMA_VOLUMEIMAGES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxvi_lvm2_label_header;
extern const sx_layout sxvi_lvm2_pv_header;
extern const sx_layout sxvi_lvm2_disk_location;
extern const sx_layout sxvi_lvm2_pv_extension;
extern const sx_layout sxvi_lvm2_mda_header;
extern const sx_layout sxvi_lvm2_raw_location;
extern const sx_layout sxvi_uif_trailer;
extern const sx_layout sxvi_uif_table_header;
extern const sx_layout sxvi_uif_block_entry;
extern const sx_layout sxvi_uif_descriptor_header;
extern const sx_layout sxvi_uif_output_format;
extern const sx_layout sxvi_gbi_header100;
extern const sx_layout sxvi_gbi_header110;
extern const sx_layout sxvi_gbi_descriptor;
extern const sx_layout sxvi_gbi_part_count;
extern const sx_layout sxvi_zisofs_header;
extern const sx_layout sxvi_zisofs_block_pointer;
extern const sx_layout sxvi_btrfs_send_header;
extern const sx_layout sxvi_btrfs_send_command;
extern const sx_layout sxvi_btrfs_send_attribute;
extern const sx_layout sxvi_btrfs_send_data_attribute_v2;
extern const sx_layout sxvi_btrfs_send_uuid;
extern const sx_layout sxvi_btrfs_send_id64;
extern const sx_layout sxvi_btrfs_send_size64;
extern const sx_layout sxvi_btrfs_send_offset64;
extern const sx_layout sxvi_btrfs_send_flags64;
extern const sx_layout sxvi_btrfs_send_flags32;
extern const sx_layout sxvi_btrfs_send_codec32;
extern const sx_layout sxvi_btrfs_send_timespec;
extern const sx_layout sxvi_aaru2_header;
extern const sx_layout sxvi_aaru2_ddt_header;
extern const sx_layout sxvi_aaru2_ddt_entry;
extern const sx_layout sxvi_aaru_index3;
extern const sx_layout sxvi_aaru_index_entry;
extern const sx_layout sxvi_aaru_data_header;
extern const sx_layout sxvi_aff_segment_header;
extern const sx_layout sxvi_aff_segment_footer;
extern const sx_layout sxvi_aff_quadword;
extern const sx_layout sxvi_bsd_disklabel_le;
extern const sx_layout sxvi_bsd_disklabel_be;
extern const sx_layout sxvi_bsd_partition_le;
extern const sx_layout sxvi_bsd_partition_be;
extern const sx_layout sxvi_md1_superblock;
extern const sx_layout sxvi_md1_superblock_ppl;
extern const sx_layout sxvi_md1_device_role;
extern const sx_layout sxvi_md090_header_le;
extern const sx_layout sxvi_md090_header_be;
extern const sx_layout sxvi_md090_disk_le;
extern const sx_layout sxvi_md090_disk_be;
extern const sx_layout sxvi_sun_sparc_label;
extern const sx_layout sxvi_sun_x86_label;
extern const sx_layout sxvi_nextstep_container_header;
extern const sx_layout sxvi_mds_header;
extern const sx_layout sxvi_mds_session;
extern const sx_layout sxvi_mds_track;
extern const sx_layout sxvi_mds_track_extra;
extern const sx_layout sxvi_mds_footer;
extern const sx_layout sxvi_ldm_private_header;
extern const sx_layout sxvi_ldm_tocblock;
extern const sx_layout sxvi_ldm_vmdb_header;
extern const sx_layout sxvi_ldm_vblk_fragment;
extern const sx_layout sxvi_ldm_vblk_record_header;
extern const sx_layout sxvi_ldm_variable_length;
extern const sx_layout sxvi_hsf_volume_prefix;
extern const sx_layout sxvi_hsf_descriptor_header;
extern const sx_layout sxvi_hsf_directory_record;
extern const sx_layout sxvi_hsf_volume_identifiers;
extern const sx_layout sxvi_cdi_footer_v2;
extern const sx_layout sxvi_cdi_footer_v35;
extern const sx_layout sxvi_cdi_descriptor_header;
extern const sx_layout sxvi_cdi_track_prefix;
extern const sx_layout sxvi_cdi_index_count;
extern const sx_layout sxvi_cdi_index;
extern const sx_layout sxvi_cdi_cdtext_count;
extern const sx_layout sxvi_cdi_track_geometry;
extern const sx_layout sxvi_partimage_volume_header;
extern const sx_layout sxvi_partimage_main_header;
extern const sx_layout sxvi_partimage_local_header;
extern const sx_layout sxvi_partimage_header_checksum;
extern const sx_layout sxvi_partimage_extension_header;
extern const sx_layout sxvi_partimage_data_check;
extern const sx_layout sxvi_partimage_tail;
bool sxvi_span(sx_context*c,uint64_t p,uint64_t n);
bool sxvi_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxvi16(const uint8_t*b,unsigned o);
uint32_t sxvi32(const uint8_t*b,unsigned o);
uint64_t sxvi64(const uint8_t*b,unsigned o);
bool sxvi_pow(uint64_t v);
bool sxvi_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxvi_magic(sx_context*c,uint64_t p,const char*s,size_t n);

/* Per-format walkers, called by the family's build. */
bool sx_lvm2_build(sx_context *c);  /* filesystem/lvm2/xx_lvm2_data.c */
bool sx_md_raid_build(sx_context *c);  /* filesystem/md_raid/xx_md_raid_data.c */
bool sx_windows_ldm_build(sx_context *c);  /* filesystem/windows_ldm/xx_windows_ldm_data.c */
bool sx_bsd_disklabel_build(sx_context *c);  /* filesystem/bsd_disklabel/xx_bsd_disklabel_data.c */
bool sx_sunvtoc_build(sx_context *c);  /* filesystem/sunvtoc/xx_sunvtoc_data.c */
bool sx_nextstep_diskimage_build(sx_context *c);  /* filesystem/nextstep_diskimage/xx_nextstep_diskimage_data.c */
bool sx_aff_build(sx_context *c);  /* filesystem/aff/xx_aff_data.c */
bool sx_partimage_build(sx_context *c);  /* filesystem/partimage/xx_partimage_data.c */
bool sx_btrfs_stream_build(sx_context *c);  /* filesystem/btrfs_stream/xx_btrfs_stream_data.c */
bool sx_diskjuggler_build(sx_context *c);  /* filesystem/diskjuggler/xx_diskjuggler_data.c */
bool sx_mds_build(sx_context *c);  /* filesystem/mds/xx_mds_data.c */
bool sx_uif_build(sx_context *c);  /* filesystem/uif/xx_uif_data.c */
bool sx_gbi_build(sx_context *c);  /* filesystem/gbi/xx_gbi_data.c */
bool sx_hsf_build(sx_context *c);  /* filesystem/hsf/xx_hsf_data.c */
bool sx_aaruformat_build(sx_context *c);  /* filesystem/aaruformat/xx_aaruformat_data.c */
bool sx_zisofs_build(sx_context *c);  /* filesystem/zisofs/xx_zisofs_data.c */

#endif
