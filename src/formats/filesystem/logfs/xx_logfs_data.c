/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LogFS data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_logfs_superblock_fields[] = {
    SX_FIELD("segment_crc","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("segment_padding","uint16",4,2,SX_RESERVED),
    SX_FIELD("segment_type","uint8",6,1,SX_ID),
    SX_FIELD("level","uint8",7,1,SX_NONE),
    SX_FIELD("segment_number","uint32",8,4,SX_ID),
    SX_FIELD("erase_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("global_erase_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("magic","uint64",24,8,SX_SIGNATURE),
    SX_FIELD("superblock_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("inode_file_levels","uint8",36,1,SX_NONE),
    SX_FIELD("inode_block_levels","uint8",37,1,SX_NONE),
    SX_FIELD("data_levels","uint8",38,1,SX_NONE),
    SX_FIELD("segment_shift","uint8",39,1,SX_NONE),
    SX_FIELD("block_shift","uint8",40,1,SX_NONE),
    SX_FIELD("write_shift","uint8",41,1,SX_NONE),
    SX_FIELD("padding0","byte[6]",42,6,SX_RESERVED),
    SX_FIELD("filesystem_size","uint64",48,8,SX_SIZE),
    SX_FIELD("segment_size","uint32",56,4,SX_SIZE),
    SX_FIELD("bad_segment_reserve","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("incompatible_features","uint64",64,8,SX_FLAGS),
    SX_FIELD("ro_compatible_features","uint64",72,8,SX_FLAGS),
    SX_FIELD("compatible_features","uint64",80,8,SX_FLAGS),
    SX_FIELD("feature_flags","uint64",88,8,SX_FLAGS),
    SX_FIELD("root_reserve","uint64",96,8,SX_SIZE),
    SX_FIELD("speed_reserve","uint64",104,8,SX_SIZE),
    SX_FIELD("journal_segments","uint32[16]",112,64,SX_ID),
    SX_FIELD("superblock_offsets","uint64[2]",176,16,SX_OFFSET),
    SX_FIELD("padding3","byte[64]",192,64,SX_RESERVED),
};
const sx_layout sx_dm_logfs_superblock = {0x60290050U,"logfs_superblock",sx_dm_logfs_superblock_fields,SX_COUNT(sx_dm_logfs_superblock_fields),SX_BE};
static bool sx_dm_logfs(sx_context*c){uint64_t pos[2]={0,((uint64_t)c->size&~UINT64_C(4095))};if(pos[1]>=4096)pos[1]-=4096;for(unsigned i=0;i<2;i++){uint8_t h[256];if(i&&pos[i]==0)continue;if(sx_dm_read(c,pos[i],h,256)&&sx_dm_u64(h,24,true)==UINT64_C(0x7a3a8e5cb9d5bf67)&&sx_dm_u32(h,0,true)==~xx_crc32_calc(0,h+4,20)&&sx_dm_u32(h,32,true)==~xx_crc32_calc(0,h+36,220)&&!sx_dm_add(c,&sx_dm_logfs_superblock,pos[i],256))return false;}return c->count!=0;}
bool sx_logfs_build(sx_context*c)
{
 return sx_dm_logfs(c);
}
