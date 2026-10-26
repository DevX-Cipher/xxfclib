/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical EXT/SquashFS layouts; docs/data_struct_unixfs_scope.txt describes limits. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_unixfs.h"
static const sx_layout *const sx_unixfs_layouts[] = {
    &sxuf_ext_dynamic_superblock,
    &sxuf_ext_original_superblock,
    &sxuf_ext_group_descriptor_64,
    &sxuf_ext_group_descriptor_32,
    &sxuf_ext_original_group_descriptor,
    &sxuf_ext_linux_inode,
    &sxuf_ext_other_os_inode,
    &sxuf_ext_inode_extra_2,
    &sxuf_ext_inode_extra_4,
    &sxuf_ext_inode_extra_8,
    &sxuf_ext_inode_extra_12,
    &sxuf_ext_inode_extra_16,
    &sxuf_ext_inode_extra_20,
    &sxuf_ext_inode_extra_24,
    &sxuf_ext_inode_extra_28,
    &sxuf_ext_inode_extra_32,
    &sxuf_squashfs1_superblock_le,
    &sxuf_squashfs1_superblock_be,
    &sxuf_squashfs2_superblock_le,
    &sxuf_squashfs2_superblock_be,
    &sxuf_squashfs3_superblock_le,
    &sxuf_squashfs3_superblock_be,
    &sxuf_squashfs4_superblock_le,
    &sxuf_squashfs4_superblock_be,
    &sxuf_squashfs_metadata_header_le,
    &sxuf_squashfs_table_index_le,
    &sxuf_squashfs2_fragment_index_le,
    &sxuf_squashfs_identity_le,
    &sxuf_squashfs_xattr_table_le,
    &sxuf_squashfs_metadata_header_be,
    &sxuf_squashfs_table_index_be,
    &sxuf_squashfs2_fragment_index_be,
    &sxuf_squashfs_identity_be,
    &sxuf_squashfs_xattr_table_be,
};
static bool sx_unixfs_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60110000)||id>=UINT32_C(0x60120000))return true;
    const wchar_t *comment=NULL;switch(id){
    case UINT32_C(0x60110001):
        if(!xx_rt_wcscmp(r->name,L"blocks_count_lo"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"r_blocks_count_lo"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"free_blocks_count_lo"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"log_block_size"))comment=L"Block size in bytes is 1024 shifted left by this exponent.";
        if(!xx_rt_wcscmp(r->name,L"log_cluster_or_fragment_size"))comment=L"Signed exponent relative to 1024 bytes: allocation clusters with BIGALLOC, legacy fragments otherwise; not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"clusters_or_fragments_per_group"))comment=L"Allocation clusters per group with BIGALLOC, legacy fragments otherwise.";
        if(!xx_rt_wcscmp(r->name,L"mtime"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"wtime"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"max_mnt_count"))comment=L"Signed mount-count limit; -1 disables mount-count checks.";
        if(!xx_rt_wcscmp(r->name,L"lastcheck"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"checkinterval"))comment=L"Duration in seconds, not a timestamp.";
        if(!xx_rt_wcscmp(r->name,L"mkfs_time"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"blocks_count_hi"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"r_blocks_count_hi"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"free_blocks_count_hi"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"raid_stride"))comment=L"Filesystem block units, not bytes.";
        if(!xx_rt_wcscmp(r->name,L"mmp_update_interval"))comment=L"Duration in seconds, not a timestamp.";
        if(!xx_rt_wcscmp(r->name,L"mmp_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"raid_stripe_width"))comment=L"Filesystem block units, not bytes.";
        if(!xx_rt_wcscmp(r->name,L"log_groups_per_flex"))comment=L"Encoded logarithm/shift; not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"kbytes_written"))comment=L"Lifetime written quantity in KiB, not bytes.";
        if(!xx_rt_wcscmp(r->name,L"first_error_time"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"first_error_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"last_error_time"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"last_error_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"wtime_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"mtime_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"mkfs_time_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"lastcheck_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"first_error_time_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"last_error_time_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        break;
    case UINT32_C(0x60110002):
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"log_block_size"))comment=L"Block size in bytes is 1024 shifted left by this exponent.";
        if(!xx_rt_wcscmp(r->name,L"log_fragment_size"))comment=L"Signed fragment-size exponent relative to 1024 bytes; not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"fragments_per_group"))comment=L"Fragments per block group.";
        if(!xx_rt_wcscmp(r->name,L"mtime"))comment=L"Unix timestamp in seconds.";
        if(!xx_rt_wcscmp(r->name,L"wtime"))comment=L"Unix timestamp in seconds.";
        if(!xx_rt_wcscmp(r->name,L"max_mnt_count"))comment=L"Signed mount-count limit; -1 disables mount-count checks.";
        if(!xx_rt_wcscmp(r->name,L"lastcheck"))comment=L"Unix timestamp in seconds.";
        if(!xx_rt_wcscmp(r->name,L"checkinterval"))comment=L"Duration in seconds, not a timestamp.";
        break;
    case UINT32_C(0x60110003):
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_lo"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_lo"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_table_lo"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"free_blocks_count_lo"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"free_inodes_count_lo"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"used_dirs_count_lo"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"flags"))comment=L"EXT 4 group descriptor flags; this word is padding in older EXT 2 layouts.";
        if(!xx_rt_wcscmp(r->name,L"exclude_bitmap_lo"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_csum_lo"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_csum_lo"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"itable_unused_lo"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"checksum"))comment=L"Group descriptor checksum when GDT_CSUM or METADATA_CSUM is enabled; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_hi"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_hi"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_table_hi"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"free_blocks_count_hi"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"free_inodes_count_hi"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"used_dirs_count_hi"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"itable_unused_hi"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"exclude_bitmap_hi"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_csum_hi"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_csum_hi"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        break;
    case UINT32_C(0x60110004):
        if(!xx_rt_wcscmp(r->name,L"block_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_table"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"flags"))comment=L"EXT 4 group descriptor flags; this word is padding in older EXT 2 layouts.";
        if(!xx_rt_wcscmp(r->name,L"exclude_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_csum"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_csum"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"checksum"))comment=L"Group descriptor checksum when GDT_CSUM or METADATA_CSUM is enabled; reserved otherwise.";
        break;
    case UINT32_C(0x60110005):
        if(!xx_rt_wcscmp(r->name,L"block_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_table"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        break;
    case UINT32_C(0x60110006):
        if(!xx_rt_wcscmp(r->name,L"size_low"))comment=L"Low 32 bits of file size in bytes; combine size_high for regular files.";
        if(!xx_rt_wcscmp(r->name,L"atime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"ctime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"mtime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"deletion_time_or_next_orphan"))comment=L"Unix deletion time for a deleted inode; next orphan inode number while linked in the legacy orphan chain.";
        if(!xx_rt_wcscmp(r->name,L"blocks_low"))comment=L"Low 32 bits of allocated block count; units are 512-byte sectors unless HUGE_FILE flags select filesystem blocks.";
        if(!xx_rt_wcscmp(r->name,L"version_low_or_reserved"))comment=L"Low 32-bit inode version in EXT 4; reserved OS-dependent word in legacy Linux EXT 2/3.";
        if(!xx_rt_wcscmp(r->name,L"block_map_or_inline_data"))comment=L"Union of block-number map, extent-tree root, inline data or fast symlink bytes; interpretation depends on mode/features/flags.";
        if(!xx_rt_wcscmp(r->name,L"file_acl_block_low"))comment=L"Low 32 bits of the extended-attribute block number.";
        if(!xx_rt_wcscmp(r->name,L"size_high_or_dir_acl"))comment=L"High file-size word for regular files; legacy directory ACL field for other inode kinds.";
        if(!xx_rt_wcscmp(r->name,L"blocks_high_or_fragment_bytes"))comment=L"High 16-bit block count with HUGE_FILE; legacy EXT 2 Linux fragment number and size bytes otherwise.";
        if(!xx_rt_wcscmp(r->name,L"file_acl_block_high_or_reserved"))comment=L"High 16-bit extended-attribute block number with 64BIT; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"uid_high"))comment=L"High 16 bits of the Linux owner UID.";
        if(!xx_rt_wcscmp(r->name,L"gid_high"))comment=L"High 16 bits of the Linux group ID.";
        if(!xx_rt_wcscmp(r->name,L"checksum_low_or_reserved"))comment=L"Low 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        break;
    case UINT32_C(0x60110007):
        if(!xx_rt_wcscmp(r->name,L"size_low"))comment=L"Low 32 bits of file size in bytes; combine size_high for regular files.";
        if(!xx_rt_wcscmp(r->name,L"atime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"ctime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"mtime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"deletion_time_or_next_orphan"))comment=L"Unix deletion time for a deleted inode; next orphan inode number while linked in the legacy orphan chain.";
        if(!xx_rt_wcscmp(r->name,L"blocks_low"))comment=L"Low 32 bits of allocated block count; units are 512-byte sectors unless HUGE_FILE flags select filesystem blocks.";
        if(!xx_rt_wcscmp(r->name,L"block_map_or_inline_data"))comment=L"Union of block-number map, extent-tree root, inline data or fast symlink bytes; interpretation depends on mode/features/flags.";
        if(!xx_rt_wcscmp(r->name,L"file_acl_block_low"))comment=L"Low 32 bits of the extended-attribute block number.";
        if(!xx_rt_wcscmp(r->name,L"size_high_or_dir_acl"))comment=L"High file-size word for regular files; legacy directory ACL field for other inode kinds.";
        break;
    case UINT32_C(0x60110009):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        break;
    case UINT32_C(0x6011000a):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x6011000b):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x6011000c):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x6011000d):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_low"))comment=L"Signed low 32-bit Unix seconds; combine epoch bits from creation_time_extra.";
        break;
    case UINT32_C(0x6011000e):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_low"))comment=L"Signed low 32-bit Unix seconds; combine epoch bits from creation_time_extra.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x6011000f):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_low"))comment=L"Signed low 32-bit Unix seconds; combine epoch bits from creation_time_extra.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x60110010):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_low"))comment=L"Signed low 32-bit Unix seconds; combine epoch bits from creation_time_extra.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x60110011):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110012):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110013):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110014):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110015):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110016):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110017):
        if(!xx_rt_wcscmp(r->name,L"compression"))comment=L"1=ZLIB,2=LZMA,3=LZO,4=XZ,5=LZ 4,6=ZSTD.";
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110018):
        if(!xx_rt_wcscmp(r->name,L"compression"))comment=L"1=ZLIB,2=LZMA,3=LZO,4=XZ,5=LZ 4,6=ZSTD.";
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110019):
        if(!xx_rt_wcscmp(r->name,L"size_and_stored_flag"))comment=L"Low 15 bits: encoded payload byte length; bit 15: uncompressed payload. Not a plain size field.";
        break;
    case UINT32_C(0x6011001a):
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))comment=L"Absolute byte offset of a metadata block from the filesystem image start.";
        break;
    case UINT32_C(0x6011001e):
        if(!xx_rt_wcscmp(r->name,L"size_and_stored_flag"))comment=L"Low 15 bits: encoded payload byte length; bit 15: uncompressed payload. Not a plain size field.";
        break;
    case UINT32_C(0x6011001f):
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))comment=L"Absolute byte offset of a metadata block from the filesystem image start.";
        break;
    default:break;}
    return !comment||xx_data_struct_record_set_comment(r,comment);
}
bool sxuf_span(sx_context *c,uint64_t at,uint64_t n){return c->size>=0&&at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
bool sxuf_read(sx_context *c,uint64_t at,void *b,size_t n){return sxuf_span(c,at,n)&&sx_read(c,(int64_t)at,b,n);}
uint16_t sxuf_16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
uint32_t sxuf_32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
static int sxuf_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sxuf_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxuf_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxuf_order);return !c->failed;
}
static bool sx_unixfs_supports(xx_file_type_t t){return t==XX_FILE_TYPE_EXT||t==XX_FILE_TYPE_SQUASHFS;}
static bool sx_unixfs_build(sx_context *c){
if(c->f->file_type==XX_FILE_TYPE_EXT)return sx_ext_build(c);
if(c->f->file_type==XX_FILE_TYPE_SQUASHFS)return sx_squashfs_build(c);
return false;}
const sx_family sx_unixfs_family={sx_unixfs_supports,sx_unixfs_build,sx_unixfs_layouts,SX_COUNT(sx_unixfs_layouts),sx_unixfs_comment};
