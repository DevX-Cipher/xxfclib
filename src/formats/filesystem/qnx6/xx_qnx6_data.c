/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QNX6 data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_qnx6_superblock_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("serial","uint64",8,8,SX_NONE),
    SX_FIELD("creation_time","uint32",16,4,SX_TIME),
    SX_FIELD("access_time","uint32",20,4,SX_TIME),
    SX_FIELD("flags","uint32",24,4,SX_FLAGS),
    SX_FIELD("version1","uint16",28,2,SX_NONE),
    SX_FIELD("version2","uint16",30,2,SX_NONE),
    SX_FIELD("volume_id","byte[16]",32,16,SX_ID),
    SX_FIELD("block_size","uint32",48,4,SX_SIZE),
    SX_FIELD("inode_count","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group","uint32",68,4,SX_NONE),
};
const sx_layout sx_dm_qnx6_superblock_header_le = {0x60290046U,"qnx6_superblock_header_le",sx_dm_qnx6_superblock_header_le_fields,SX_COUNT(sx_dm_qnx6_superblock_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_qnx6_root_node_le_fields[] = {
    SX_FIELD("size","uint64",0,8,SX_SIZE),
    SX_FIELD("block_pointers","uint32[16]",8,64,SX_ID),
    SX_FIELD("levels","uint8",72,1,SX_NONE),
    SX_FIELD("mode","uint8",73,1,SX_FLAGS),
    SX_FIELD("spare","byte[6]",74,6,SX_RESERVED),
};
const sx_layout sx_dm_qnx6_root_node_le = {0x60290047U,"qnx6_root_node_le",sx_dm_qnx6_root_node_le_fields,SX_COUNT(sx_dm_qnx6_root_node_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_qnx6_superblock_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("serial","uint64",8,8,SX_NONE),
    SX_FIELD("creation_time","uint32",16,4,SX_TIME),
    SX_FIELD("access_time","uint32",20,4,SX_TIME),
    SX_FIELD("flags","uint32",24,4,SX_FLAGS),
    SX_FIELD("version1","uint16",28,2,SX_NONE),
    SX_FIELD("version2","uint16",30,2,SX_NONE),
    SX_FIELD("volume_id","byte[16]",32,16,SX_ID),
    SX_FIELD("block_size","uint32",48,4,SX_SIZE),
    SX_FIELD("inode_count","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group","uint32",68,4,SX_NONE),
};
const sx_layout sx_dm_qnx6_superblock_header_be = {0x6029004eU,"qnx6_superblock_header_be",sx_dm_qnx6_superblock_header_be_fields,SX_COUNT(sx_dm_qnx6_superblock_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_qnx6_root_node_be_fields[] = {
    SX_FIELD("size","uint64",0,8,SX_SIZE),
    SX_FIELD("block_pointers","uint32[16]",8,64,SX_ID),
    SX_FIELD("levels","uint8",72,1,SX_NONE),
    SX_FIELD("mode","uint8",73,1,SX_FLAGS),
    SX_FIELD("spare","byte[6]",74,6,SX_RESERVED),
};
const sx_layout sx_dm_qnx6_root_node_be = {0x6029004fU,"qnx6_root_node_be",sx_dm_qnx6_root_node_be_fields,SX_COUNT(sx_dm_qnx6_root_node_be_fields),SX_BE};
/* Expose physically framed anchors at both native-supported positions.
 * Geometry is rechecked locally; no subclass cast or native constructor is used. */
static bool sx_dm_qnx(sx_context*c){uint8_t h[392];const uint64_t positions[]={8192,0};for(unsigned i=0;i<2;i++){uint64_t p=positions[i];if(!sx_dm_read(c,p,h,sizeof(h)))continue;bool be=sx_dm_u32(h,0,true)==0x68191122;if(sx_dm_u32(h,0,be)!=0x68191122)continue;uint64_t bs=sx_dm_u32(h,48,be),blocks=sx_dm_u32(h,60,be);if(bs<512||bs>65536||(bs&(bs-1))||(p+4096)%bs||!blocks||!sx_dm_u32(h,52,be)||!sx_dm_span(c,p+4096,blocks*bs)||sx_dm_u64(h,72,be)<128||h[144]>4||h[304]>4)continue;if(!sx_dm_add(c,be?&sx_dm_qnx6_superblock_header_be:&sx_dm_qnx6_superblock_header_le,p,72)||!sx_dm_table(c,be?&sx_dm_qnx6_root_node_be:&sx_dm_qnx6_root_node_le,p+72,80,4))return false;}return c->count!=0;}
bool sx_qnx6_build(sx_context*c)
{
 return sx_dm_qnx(c);
}
