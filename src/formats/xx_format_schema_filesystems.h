/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The filesystems schema family: what its family unit (xx_format_schema_filesystems.c)
 * and its formats' data files share. Formats: FAT; exFAT; NTFS. */
#ifndef XX_FORMAT_SCHEMA_FILESYSTEMS_H
#define XX_FORMAT_SCHEMA_FILESYSTEMS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_fs_fat_bpb;
extern const sx_layout sx_fs_fat16_boot_sector;
extern const sx_layout sx_fs_fat32_boot_sector;
extern const sx_layout sx_fs_fat32_fsinfo;
extern const sx_layout sx_fs_fat32_directory_entry;
extern const sx_layout sx_fs_fat16_directory_entry;
extern const sx_layout sx_fs_fat_long_name_entry;
extern const sx_layout sx_fs_fat16_entry;
extern const sx_layout sx_fs_fat32_entry;
extern const sx_layout sx_fs_boot_signature;
extern const sx_layout sx_fs_exfat_boot_sector;
extern const sx_layout sx_fs_exfat_extended_boot_signature;
extern const sx_layout sx_fs_exfat_boot_checksum;
extern const sx_layout sx_fs_exfat_bitmap_entry;
extern const sx_layout sx_fs_exfat_upcase_entry;
extern const sx_layout sx_fs_exfat_volume_label_entry;
extern const sx_layout sx_fs_exfat_file_entry;
extern const sx_layout sx_fs_exfat_stream_entry;
extern const sx_layout sx_fs_exfat_name_entry;
extern const sx_layout sx_fs_exfat_fat_entry;
extern const sx_layout sx_fs_ntfs_boot_sector;
extern const sx_layout sx_fs_ntfs_file_record_header;
extern const sx_layout sx_fs_ntfs_update_sequence;
extern const sx_layout sx_fs_ntfs_attribute_common;
extern const sx_layout sx_fs_ntfs_attribute_resident;
extern const sx_layout sx_fs_ntfs_attribute_nonresident;
extern const sx_layout sx_fs_ntfs_attribute_end;
uint64_t sx_fs_limit(const sx_context *c);
bool sx_fs_fits(const sx_context *c,uint64_t o,uint64_t n);
bool sx_fs_emit(sx_context *c,const sx_layout *l,uint64_t o,uint64_t n,uint64_t count);

/* Per-format walkers, called by the family's build. */
bool sx_fat_schema_build(sx_context *c);  /* filesystem/fat/xx_fat_data.c */
bool sx_exfat_build(sx_context *c);  /* filesystem/exfat/xx_exfat_data.c */
bool sx_ntfs_build(sx_context *c);  /* filesystem/ntfs/xx_ntfs_data.c */

#endif
