/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NILFS2 data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_nilfs2_superblock_fields[] = {
    SX_FIELD("revision","uint32",0,4,SX_ID),
    SX_FIELD("minor_revision","uint16",4,2,SX_ID),
    SX_FIELD("magic","uint16",6,2,SX_SIGNATURE),
    SX_FIELD("checksum_bytes","uint16",8,2,SX_SIZE),
    SX_FIELD("flags","uint16",10,2,SX_FLAGS),
    SX_FIELD("crc_seed","uint32",12,4,SX_NONE),
    SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("log_block_size","uint32",20,4,SX_NONE),
    SX_FIELD("segment_count","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("device_size","uint64",32,8,SX_SIZE),
    SX_FIELD("first_data_block","uint64",40,8,SX_NONE),
    SX_FIELD("blocks_per_segment","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("reserved_segments_percent","uint32",52,4,SX_NONE),
    SX_FIELD("last_checkpoint_number","uint64",56,8,SX_NONE),
    SX_FIELD("last_partial_segment_block","uint64",64,8,SX_NONE),
    SX_FIELD("last_segment_sequence","uint64",72,8,SX_NONE),
    SX_FIELD("free_blocks","uint64",80,8,SX_COUNT_PROP),
    SX_FIELD("creation_time","uint64",88,8,SX_TIME),
    SX_FIELD("mount_time","uint64",96,8,SX_TIME),
    SX_FIELD("write_time","uint64",104,8,SX_TIME),
    SX_FIELD("mount_count","uint16",112,2,SX_COUNT_PROP),
    SX_FIELD("max_mount_count","uint16",114,2,SX_COUNT_PROP),
    SX_FIELD("state","uint16",116,2,SX_FLAGS),
    SX_FIELD("errors","uint16",118,2,SX_ID),
    SX_FIELD("last_check_time","uint64",120,8,SX_TIME),
    SX_FIELD("check_interval","uint32",128,4,SX_NONE),
    SX_FIELD("creator_os","uint32",132,4,SX_ID),
    SX_FIELD("reserved_uid","uint16",136,2,SX_ID),
    SX_FIELD("reserved_gid","uint16",138,2,SX_ID),
    SX_FIELD("first_inode","uint32",140,4,SX_ID),
    SX_FIELD("inode_size","uint16",144,2,SX_SIZE),
    SX_FIELD("dat_entry_size","uint16",146,2,SX_SIZE),
    SX_FIELD("checkpoint_size","uint16",148,2,SX_SIZE),
    SX_FIELD("segment_usage_size","uint16",150,2,SX_SIZE),
    SX_FIELD("uuid","byte[16]",152,16,SX_ID),
    SX_FIELD("volume_name","char[80]",168,80,SX_STRING),
    SX_FIELD("commit_interval","uint32",248,4,SX_NONE),
    SX_FIELD("commit_block_max","uint32",252,4,SX_COUNT_PROP),
    SX_FIELD("feature_compat","uint64",256,8,SX_FLAGS),
    SX_FIELD("feature_ro_compat","uint64",264,8,SX_FLAGS),
    SX_FIELD("feature_incompat","uint64",272,8,SX_FLAGS),
    SX_FIELD("reserved","byte[744]",280,744,SX_RESERVED),
};
const sx_layout sxmf_nilfs2_superblock = {0x60420006U,"nilfs2_superblock",sxmf_nilfs2_superblock_fields,SX_COUNT(sxmf_nilfs2_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_nilfs2_inode_fields[] = {
    SX_FIELD("block_count","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("change_time","uint64",16,8,SX_TIME),
    SX_FIELD("modification_time","uint64",24,8,SX_TIME),
    SX_FIELD("change_nanoseconds","uint32",32,4,SX_NONE),
    SX_FIELD("modification_nanoseconds","uint32",36,4,SX_NONE),
    SX_FIELD("uid","uint32",40,4,SX_ID),
    SX_FIELD("gid","uint32",44,4,SX_ID),
    SX_FIELD("mode","uint16",48,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",52,4,SX_FLAGS),
    SX_FIELD("block_map","uint64[7]",56,56,SX_NONE),
    SX_FIELD("xattr","uint64",112,8,SX_NONE),
    SX_FIELD("generation","uint32",120,4,SX_NONE),
    SX_FIELD("padding","uint32",124,4,SX_RESERVED),
};
const sx_layout sxmf_nilfs2_inode = {0x60420007U,"nilfs2_inode",sxmf_nilfs2_inode_fields,SX_COUNT(sxmf_nilfs2_inode_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_nilfs2_super_root_header_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("byte_count","uint16",4,2,SX_SIZE),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
    SX_FIELD("non_gc_creation_time","uint64",8,8,SX_TIME),
};
const sx_layout sxmf_nilfs2_super_root_header = {0x60420008U,"nilfs2_super_root_header",sxmf_nilfs2_super_root_header_fields,SX_COUNT(sxmf_nilfs2_super_root_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_nilfs2_segment_summary_fields[] = {
    SX_FIELD("data_checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("summary_checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("magic","uint32",8,4,SX_SIGNATURE),
    SX_FIELD("summary_bytes","uint16",12,2,SX_SIZE),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("sequence","uint64",16,8,SX_NONE),
    SX_FIELD("creation_time","uint64",24,8,SX_TIME),
    SX_FIELD("next_segment_block","uint64",32,8,SX_NONE),
    SX_FIELD("block_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("file_info_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("summary_total_bytes","uint32",48,4,SX_SIZE),
    SX_FIELD("padding","uint32",52,4,SX_RESERVED),
    SX_FIELD("checkpoint_number","uint64",56,8,SX_NONE),
};
const sx_layout sxmf_nilfs2_segment_summary = {0x60420009U,"nilfs2_segment_summary",sxmf_nilfs2_segment_summary_fields,SX_COUNT(sxmf_nilfs2_segment_summary_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_nilfs2_file_info_fields[] = {
    SX_FIELD("inode","uint64",0,8,SX_ID),
    SX_FIELD("checkpoint_number","uint64",8,8,SX_NONE),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("data_block_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxmf_nilfs2_file_info = {0x6042000aU,"nilfs2_file_info",sxmf_nilfs2_file_info_fields,SX_COUNT(sxmf_nilfs2_file_info_fields),SX_LE};
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
static bool sxmf_nilfs(sx_context*c){
 uint8_t h[280],b[64];if(!sxmf_read(c,1024,h,280)||sxmf16(h+6,0)!=0x3434||sxmf32(h+20,0)>6||!SXMF_ADD(c,nilfs2_superblock,1024))return false;
 uint64_t bs=UINT64_C(1024)<<sxmf32(h+20,0),blocks=sxmf64(h+32,0)/bs;
 uint64_t last=((uint64_t)c->size>>12);if(last>0){last=(last-1)<<12;if(last!=1024&&sxmf_read(c,last,b,8)&&sxmf16(b+6,0)==0x3434&&sxmf_span(c,last,1024)&&!SXMF_ADD(c,nilfs2_superblock,last))return false;}
 uint64_t block=sxmf64(h+64,0);if(!blocks||block>=blocks||!sxmf_read(c,block*bs,b,64)||sxmf32(b+8,0)!=0x1eaffa11)return true;
 uint64_t count=sxmf32(b+40,0),summary=sxmf32(b+48,0);if(!count||count>blocks-block||sxmf16(b+12,0)<64||summary<64||summary>count*bs||!sxmf_span(c,block*bs,count*bs))return true;
 if(!SXMF_ADD(c,nilfs2_segment_summary,block*bs))return false;
 /* A super-root occupies the last block only when the segment carries SS_SR. */
 if(sxmf16(b+14,0)&4){uint64_t p=(block+count-1)*bs;uint8_t root[16];if(sxmf_read(c,p,root,16)&&sxmf16(root+4,0)>=400&&sxmf16(root+4,0)<=bs){if(!SXMF_ADD(c,nilfs2_super_root_header,p)||!SXMF_TABLE(c,nilfs2_inode,p+16,3))return false;}}
 /* File-info records are separated by variable block-info records. Emit the
  * first complete descriptor; never pretend they form a fixed-width array. */
 if(sxmf32(b+44,0)&&sxmf16(b+12,0)<=summary&&24<=summary-sxmf16(b+12,0)&&!SXMF_ADD(c,nilfs2_file_info,block*bs+sxmf16(b+12,0)))return false;
 return true;
}
bool sx_nilfs2_build(sx_context*c)
{
 return sxmf_nilfs(c);
}
#undef SXMF_ADD
#undef SXMF_TABLE
