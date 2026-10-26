/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * UBIFS data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_ubifs_common_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
};
const sx_layout sx_dm_ubifs_common_header = {0x60290035U,"ubifs_common_header",sx_dm_ubifs_common_header_fields,SX_COUNT(sx_dm_ubifs_common_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("padding1","byte[2]",24,2,SX_RESERVED),
    SX_FIELD("key_hash","uint8",26,1,SX_ID),
    SX_FIELD("key_format","uint8",27,1,SX_ID),
    SX_FIELD("flags","uint32",28,4,SX_FLAGS),
    SX_FIELD("min_io_size","uint32",32,4,SX_SIZE),
    SX_FIELD("leb_size","uint32",36,4,SX_SIZE),
    SX_FIELD("leb_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("max_leb_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("max_bud_bytes","uint64",48,8,SX_SIZE),
    SX_FIELD("log_lebs","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("lpt_lebs","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("orphan_lebs","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("journal_head_count","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("fanout","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("lsave_count","uint32",76,4,SX_COUNT_PROP),
    SX_FIELD("format_version","uint32",80,4,SX_NONE),
    SX_FIELD("default_compression","uint16",84,2,SX_ID),
    SX_FIELD("padding2","byte[2]",86,2,SX_RESERVED),
    SX_FIELD("reserve_pool_uid","uint32",88,4,SX_ID),
    SX_FIELD("reserve_pool_gid","uint32",92,4,SX_ID),
    SX_FIELD("reserve_pool_size","uint64",96,8,SX_SIZE),
    SX_FIELD("time_granularity_ns","uint32",104,4,SX_NONE),
    SX_FIELD("uuid","byte[16]",108,16,SX_ID),
    SX_FIELD("ro_compat_version","uint32",124,4,SX_NONE),
    SX_FIELD("hmac","byte[64]",128,64,SX_SIGNATURE),
    SX_FIELD("hmac_well_known_message","byte[64]",192,64,SX_SIGNATURE),
    SX_FIELD("hash_algorithm","uint16",256,2,SX_ID),
    SX_FIELD("master_node_hash","byte[64]",258,64,SX_CHECKSUM),
    SX_FIELD("padding3","byte[3774]",322,3774,SX_RESERVED),
};
const sx_layout sx_dm_ubifs_superblock = {0x60290036U,"ubifs_superblock",sx_dm_ubifs_superblock_fields,SX_COUNT(sx_dm_ubifs_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_master_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("highest_inode_number","uint64",24,8,SX_ID),
    SX_FIELD("commit_number","uint64",32,8,SX_NONE),
    SX_FIELD("flags","uint32",40,4,SX_FLAGS),
    SX_FIELD("log_lnum","uint32",44,4,SX_ID),
    SX_FIELD("root_lnum","uint32",48,4,SX_ID),
    SX_FIELD("root_offset","uint32",52,4,SX_OFFSET),
    SX_FIELD("root_length","uint32",56,4,SX_SIZE),
    SX_FIELD("gc_lnum","uint32",60,4,SX_ID),
    SX_FIELD("index_head_lnum","uint32",64,4,SX_ID),
    SX_FIELD("index_head_offset","uint32",68,4,SX_OFFSET),
    SX_FIELD("index_size","uint64",72,8,SX_SIZE),
    SX_FIELD("total_free","uint64",80,8,SX_SIZE),
    SX_FIELD("total_dirty","uint64",88,8,SX_SIZE),
    SX_FIELD("total_used","uint64",96,8,SX_SIZE),
    SX_FIELD("total_dead","uint64",104,8,SX_SIZE),
    SX_FIELD("total_dark","uint64",112,8,SX_SIZE),
    SX_FIELD("lpt_lnum","uint32",120,4,SX_ID),
    SX_FIELD("lpt_offset","uint32",124,4,SX_OFFSET),
    SX_FIELD("nhead_lnum","uint32",128,4,SX_ID),
    SX_FIELD("nhead_offset","uint32",132,4,SX_OFFSET),
    SX_FIELD("ltab_lnum","uint32",136,4,SX_ID),
    SX_FIELD("ltab_offset","uint32",140,4,SX_OFFSET),
    SX_FIELD("lsave_lnum","uint32",144,4,SX_ID),
    SX_FIELD("lsave_offset","uint32",148,4,SX_OFFSET),
    SX_FIELD("lscan_lnum","uint32",152,4,SX_ID),
    SX_FIELD("empty_lebs","uint32",156,4,SX_COUNT_PROP),
    SX_FIELD("index_lebs","uint32",160,4,SX_COUNT_PROP),
    SX_FIELD("leb_count","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("root_index_hash","byte[64]",168,64,SX_CHECKSUM),
    SX_FIELD("lpt_hash","byte[64]",232,64,SX_CHECKSUM),
    SX_FIELD("hmac","byte[64]",296,64,SX_SIGNATURE),
    SX_FIELD("padding1","byte[152]",360,152,SX_RESERVED),
};
const sx_layout sx_dm_ubifs_master_node = {0x60290037U,"ubifs_master_node",sx_dm_ubifs_master_node_fields,SX_COUNT(sx_dm_ubifs_master_node_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_index_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("child_count","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("level","uint16",26,2,SX_NONE),
};
const sx_layout sx_dm_ubifs_index_header = {0x60290038U,"ubifs_index_header",sx_dm_ubifs_index_header_fields,SX_COUNT(sx_dm_ubifs_index_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_index_branch_fields[] = {
    SX_FIELD("logical_block_number","uint32",0,4,SX_ID),
    SX_FIELD("offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("length","uint32",8,4,SX_SIZE),
    SX_FIELD("key_inode","uint32",12,4,SX_ID),
    SX_FIELD("key_type_and_value","uint32",16,4,SX_FLAGS),
};
const sx_layout sx_dm_ubifs_index_branch = {0x60290039U,"ubifs_index_branch",sx_dm_ubifs_index_branch_fields,SX_COUNT(sx_dm_ubifs_index_branch_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_inode_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("key_inode","uint32",24,4,SX_ID),
    SX_FIELD("key_type_and_value","uint32",28,4,SX_FLAGS),
    SX_FIELD("key_padding","byte[8]",32,8,SX_RESERVED),
    SX_FIELD("creation_sequence_number","uint64",40,8,SX_NONE),
    SX_FIELD("size","uint64",48,8,SX_SIZE),
    SX_FIELD("access_time_seconds","int64",56,8,SX_TIME),
    SX_FIELD("change_time_seconds","int64",64,8,SX_TIME),
    SX_FIELD("modification_time_seconds","int64",72,8,SX_TIME),
    SX_FIELD("access_time_nanoseconds","uint32",80,4,SX_NONE),
    SX_FIELD("change_time_nanoseconds","uint32",84,4,SX_NONE),
    SX_FIELD("modification_time_nanoseconds","uint32",88,4,SX_NONE),
    SX_FIELD("link_count","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("uid","uint32",96,4,SX_ID),
    SX_FIELD("gid","uint32",100,4,SX_ID),
    SX_FIELD("mode","uint32",104,4,SX_FLAGS),
    SX_FIELD("flags","uint32",108,4,SX_FLAGS),
    SX_FIELD("data_length","uint32",112,4,SX_SIZE),
    SX_FIELD("xattr_count","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("xattr_size","uint32",120,4,SX_SIZE),
    SX_FIELD("padding1","byte[4]",124,4,SX_RESERVED),
    SX_FIELD("xattr_names_length","uint32",128,4,SX_SIZE),
    SX_FIELD("compression_type","uint16",132,2,SX_ID),
    SX_FIELD("padding2","byte[26]",134,26,SX_RESERVED),
};
const sx_layout sx_dm_ubifs_inode_node = {0x6029003aU,"ubifs_inode_node",sx_dm_ubifs_inode_node_fields,SX_COUNT(sx_dm_ubifs_inode_node_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_directory_entry_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("key_inode","uint32",24,4,SX_ID),
    SX_FIELD("key_type_and_value","uint32",28,4,SX_FLAGS),
    SX_FIELD("key_padding","byte[8]",32,8,SX_RESERVED),
    SX_FIELD("inode_number","uint64",40,8,SX_ID),
    SX_FIELD("padding1","uint8",48,1,SX_RESERVED),
    SX_FIELD("type","uint8",49,1,SX_ID),
    SX_FIELD("name_length","uint16",50,2,SX_SIZE),
    SX_FIELD("cookie","uint32",52,4,SX_ID),
};
const sx_layout sx_dm_ubifs_directory_entry = {0x6029003bU,"ubifs_directory_entry",sx_dm_ubifs_directory_entry_fields,SX_COUNT(sx_dm_ubifs_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_data_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("key_inode","uint32",24,4,SX_ID),
    SX_FIELD("key_type_and_value","uint32",28,4,SX_FLAGS),
    SX_FIELD("key_padding","byte[8]",32,8,SX_RESERVED),
    SX_FIELD("uncompressed_size","uint32",40,4,SX_SIZE),
    SX_FIELD("compression_type","uint16",44,2,SX_ID),
    SX_FIELD("compressed_size","uint16",46,2,SX_SIZE),
};
const sx_layout sx_dm_ubifs_data_node = {0x6029003cU,"ubifs_data_node",sx_dm_ubifs_data_node_fields,SX_COUNT(sx_dm_ubifs_data_node_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_padding_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("padding_length","uint32",24,4,SX_SIZE),
};
const sx_layout sx_dm_ubifs_padding_node = {0x6029003dU,"ubifs_padding_node",sx_dm_ubifs_padding_node_fields,SX_COUNT(sx_dm_ubifs_padding_node_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_commit_start_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("commit_number","uint64",24,8,SX_NONE),
};
const sx_layout sx_dm_ubifs_commit_start = {0x6029003eU,"ubifs_commit_start",sx_dm_ubifs_commit_start_fields,SX_COUNT(sx_dm_ubifs_commit_start_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_ubifs_reference_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("logical_block_number","uint32",24,4,SX_ID),
    SX_FIELD("offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("journal_head","uint32",32,4,SX_ID),
    SX_FIELD("padding1","byte[28]",36,28,SX_RESERVED),
};
const sx_layout sx_dm_ubifs_reference_node = {0x6029003fU,"ubifs_reference_node",sx_dm_ubifs_reference_node_fields,SX_COUNT(sx_dm_ubifs_reference_node_fields),SX_LE};
/* Scan physical UBIFS nodes only; no journal replay or decompressed data.
 * CRC guards a resynchronisation on 8-byte boundaries, within 64 MiB. */
static bool sx_dm_ubifs(sx_context*c){uint8_t h[28];uint64_t limit=(uint64_t)c->size;if(limit>67108864)limit=67108864;for(uint64_t p=0;p+24<=limit&&c->count<24000;){if(!sx_dm_read(c,p,h,24))return false;uint64_t z=sx_dm_u32(h,16,false);if(sx_dm_u32(h,0,false)!=0x06101831||z<24||z>16777216||!sx_dm_span(c,p,z)||!sx_dm_crc(c,p+8,z-8,sx_dm_u32(h,4,false),false,true,false)){p+=8;continue;}const sx_layout*l=&sx_dm_ubifs_common_header;uint64_t n=24;switch(h[20]){case 0:l=&sx_dm_ubifs_inode_node;n=160;break;case 1:l=&sx_dm_ubifs_data_node;n=48;break;case 2:case 3:l=&sx_dm_ubifs_directory_entry;n=56;break;case 5:l=&sx_dm_ubifs_padding_node;n=28;break;case 6:l=&sx_dm_ubifs_superblock;n=4096;break;case 7:l=&sx_dm_ubifs_master_node;n=512;break;case 8:l=&sx_dm_ubifs_reference_node;n=64;break;case 9:l=&sx_dm_ubifs_index_header;n=28;break;case 10:l=&sx_dm_ubifs_commit_start;n=32;break;}if(n>z){l=&sx_dm_ubifs_common_header;n=24;}if(!sx_dm_add(c,l,p,n))return false;if(l==&sx_dm_ubifs_index_header&&sx_dm_read(c,p,h,28)){uint64_t count=sx_dm_u16(h,24,false);if(count<=(z-28)/20&&!sx_dm_table(c,&sx_dm_ubifs_index_branch,p+28,20,count))return false;}p+=(z+7)&~UINT64_C(7);}return c->count!=0;}
bool sx_ubifs_build(sx_context*c)
{
 return sx_dm_ubifs(c);
}
