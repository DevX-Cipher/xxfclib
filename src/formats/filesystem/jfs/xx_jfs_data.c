/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JFS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_jfs_superblock_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("volume_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",16,4,SX_SIZE),
    SX_FIELD("log2_block_size","uint16",20,2,SX_NONE),
    SX_FIELD("log2_block_factor","uint16",22,2,SX_NONE),
    SX_FIELD("physical_block_size","uint32",24,4,SX_SIZE),
    SX_FIELD("log2_physical_block_size","uint16",28,2,SX_NONE),
    SX_FIELD("padding","uint16",30,2,SX_RESERVED),
    SX_FIELD("allocation_group_blocks","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",36,4,SX_FLAGS),
    SX_FIELD("state","uint32",40,4,SX_FLAGS),
    SX_FIELD("compression","uint32",44,4,SX_ID),
    SX_FIELD("secondary_inode_table_blocks","uint24",48,3,SX_COUNT_PROP),
    SX_FIELD("secondary_inode_table_block_high","uint8",51,1,SX_NONE),
    SX_FIELD("secondary_inode_table_block_low","uint32",52,4,SX_NONE),
    SX_FIELD("secondary_inode_map_blocks","uint24",56,3,SX_COUNT_PROP),
    SX_FIELD("secondary_inode_map_block_high","uint8",59,1,SX_NONE),
    SX_FIELD("secondary_inode_map_block_low","uint32",60,4,SX_NONE),
    SX_FIELD("log_device","uint32",64,4,SX_ID),
    SX_FIELD("log_serial","uint32",68,4,SX_NONE),
    SX_FIELD("log_extent_blocks","uint24",72,3,SX_COUNT_PROP),
    SX_FIELD("log_extent_block_high","uint8",75,1,SX_NONE),
    SX_FIELD("log_extent_block_low","uint32",76,4,SX_NONE),
    SX_FIELD("fsck_extent_blocks","uint24",80,3,SX_COUNT_PROP),
    SX_FIELD("fsck_extent_block_high","uint8",83,1,SX_NONE),
    SX_FIELD("fsck_extent_block_low","uint32",84,4,SX_NONE),
    SX_FIELD("update_seconds","uint32",88,4,SX_TIME),
    SX_FIELD("update_nanoseconds","uint32",92,4,SX_NONE),
    SX_FIELD("fsck_log_blocks","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("fsck_log_index","int8",100,1,SX_NONE),
    SX_FIELD("pack_name","char[11]",101,11,SX_STRING),
    SX_FIELD("extension_blocks","uint64",112,8,SX_COUNT_PROP),
    SX_FIELD("extension_fsck_blocks","uint24",120,3,SX_COUNT_PROP),
    SX_FIELD("extension_fsck_block_high","uint8",123,1,SX_NONE),
    SX_FIELD("extension_fsck_block_low","uint32",124,4,SX_NONE),
    SX_FIELD("extension_log_blocks","uint24",128,3,SX_COUNT_PROP),
    SX_FIELD("extension_log_block_high","uint8",131,1,SX_NONE),
    SX_FIELD("extension_log_block_low","uint32",132,4,SX_NONE),
    SX_FIELD("uuid","byte[16]",136,16,SX_ID),
    SX_FIELD("label","char[16]",152,16,SX_STRING),
    SX_FIELD("log_uuid","byte[16]",168,16,SX_ID),
};
const sx_layout sxmf_jfs_superblock = {0x60420005U,"jfs_superblock",sxmf_jfs_superblock_fields,SX_COUNT(sxmf_jfs_superblock_fields),SX_LE};
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
static bool sxmf_jfs(sx_context*c){uint8_t h[4];bool any=false;const uint64_t at[]={32768,61440};for(unsigned i=0;i<2;i++)if(sxmf_read(c,at[i],h,4)&&!xx_rt_memcmp(h,"JFS1",4)&&sxmf_span(c,at[i],184)){if(!SXMF_ADD(c,jfs_superblock,at[i]))return false;any=true;}return any;}
bool sx_jfs_build(sx_context*c)
{
 return sxmf_jfs(c);
}
#undef SXMF_ADD
