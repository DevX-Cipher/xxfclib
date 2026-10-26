/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * F2FS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_f2fs_superblock_prefix_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_ID),
    SX_FIELD("minor_version","uint16",6,2,SX_ID),
    SX_FIELD("log2_sector_size","uint32",8,4,SX_NONE),
    SX_FIELD("log2_sectors_per_block","uint32",12,4,SX_NONE),
    SX_FIELD("log2_block_size","uint32",16,4,SX_NONE),
    SX_FIELD("log2_blocks_per_segment","uint32",20,4,SX_NONE),
    SX_FIELD("segments_per_section","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("sections_per_zone","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("checksum_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("block_count","uint64",36,8,SX_COUNT_PROP),
    SX_FIELD("section_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("segment_count","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("checkpoint_segments","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("sit_segments","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("nat_segments","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("ssa_segments","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("main_segments","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("segment0_block","uint32",72,4,SX_NONE),
    SX_FIELD("checkpoint_block","uint32",76,4,SX_NONE),
    SX_FIELD("sit_block","uint32",80,4,SX_NONE),
    SX_FIELD("nat_block","uint32",84,4,SX_NONE),
    SX_FIELD("ssa_block","uint32",88,4,SX_NONE),
    SX_FIELD("main_block","uint32",92,4,SX_NONE),
    SX_FIELD("root_inode","uint32",96,4,SX_ID),
    SX_FIELD("node_inode","uint32",100,4,SX_ID),
    SX_FIELD("meta_inode","uint32",104,4,SX_ID),
    SX_FIELD("uuid","byte[16]",108,16,SX_ID),
    SX_FIELD("volume_name","uint16[512]",124,1024,SX_NONE),
    SX_FIELD("extension_count","uint32",1148,4,SX_COUNT_PROP),
    SX_FIELD("extension_list","byte[512]",1152,512,SX_NONE),
    SX_FIELD("checkpoint_payload_blocks","uint32",1664,4,SX_COUNT_PROP),
    SX_FIELD("version","char[256]",1668,256,SX_STRING),
    SX_FIELD("initial_version","char[256]",1924,256,SX_STRING),
    SX_FIELD("features","uint32",2180,4,SX_FLAGS),
    SX_FIELD("encryption_level","uint8",2184,1,SX_ID),
    SX_FIELD("encryption_salt","byte[16]",2185,16,SX_NONE),
};
const sx_layout sxmf_f2fs_superblock_prefix = {0x6042000bU,"f2fs_superblock_prefix",sxmf_f2fs_superblock_prefix_fields,SX_COUNT(sxmf_f2fs_superblock_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_f2fs_device_fields[] = {
    SX_FIELD("path","char[64]",0,64,SX_STRING),
    SX_FIELD("total_segments","uint32",64,4,SX_COUNT_PROP),
};
const sx_layout sxmf_f2fs_device = {0x6042000cU,"f2fs_device",sxmf_f2fs_device_fields,SX_COUNT(sxmf_f2fs_device_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_f2fs_superblock_tail_fields[] = {
    SX_FIELD("quota_inodes","uint32[3]",0,12,SX_ID),
    SX_FIELD("hot_extension_count","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("encoding","uint16",13,2,SX_ID),
    SX_FIELD("encoding_flags","uint16",15,2,SX_FLAGS),
    SX_FIELD("checkpoint_stop_reasons","byte[32]",17,32,SX_FLAGS),
    SX_FIELD("errors","byte[16]",49,16,SX_FLAGS),
    SX_FIELD("reserved","byte[258]",65,258,SX_RESERVED),
    SX_FIELD("crc","uint32",323,4,SX_CHECKSUM),
};
const sx_layout sxmf_f2fs_superblock_tail = {0x6042000dU,"f2fs_superblock_tail",sxmf_f2fs_superblock_tail_fields,SX_COUNT(sxmf_f2fs_superblock_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_f2fs_checkpoint_header_fields[] = {
    SX_FIELD("version","uint64",0,8,SX_NONE),
    SX_FIELD("user_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("valid_blocks","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("reserved_segments","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("overprovision_segments","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("free_segments","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("current_node_segments","uint32[8]",36,32,SX_NONE),
    SX_FIELD("current_node_block_offsets","uint16[8]",68,16,SX_NONE),
    SX_FIELD("current_data_segments","uint32[8]",84,32,SX_NONE),
    SX_FIELD("current_data_block_offsets","uint16[8]",116,16,SX_NONE),
    SX_FIELD("flags","uint32",132,4,SX_FLAGS),
    SX_FIELD("pack_total_blocks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("pack_summary_start","uint32",140,4,SX_NONE),
    SX_FIELD("valid_nodes","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("valid_inodes","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("next_free_node","uint32",152,4,SX_ID),
    SX_FIELD("sit_bitmap_bytes","uint32",156,4,SX_SIZE),
    SX_FIELD("nat_bitmap_bytes","uint32",160,4,SX_SIZE),
    SX_FIELD("checksum_offset","uint32",164,4,SX_OFFSET),
    SX_FIELD("elapsed_time","uint64",168,8,SX_NONE),
    SX_FIELD("allocation_type","uint8[16]",176,16,SX_ID),
};
const sx_layout sxmf_f2fs_checkpoint_header = {0x6042000eU,"f2fs_checkpoint_header",sxmf_f2fs_checkpoint_header_fields,SX_COUNT(sxmf_f2fs_checkpoint_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_f2fs_nat_entry_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("inode","uint32",1,4,SX_ID),
    SX_FIELD("block","uint32",5,4,SX_NONE),
};
const sx_layout sxmf_f2fs_nat_entry = {0x6042000fU,"f2fs_nat_entry",sxmf_f2fs_nat_entry_fields,SX_COUNT(sxmf_f2fs_nat_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_f2fs_node_footer_fields[] = {
    SX_FIELD("node_id","uint32",0,4,SX_ID),
    SX_FIELD("inode","uint32",4,4,SX_ID),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("checkpoint_version","uint64",12,8,SX_NONE),
    SX_FIELD("next_block","uint32",20,4,SX_NONE),
};
const sx_layout sxmf_f2fs_node_footer = {0x60420010U,"f2fs_node_footer",sxmf_f2fs_node_footer_fields,SX_COUNT(sxmf_f2fs_node_footer_fields),SX_LE};
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
static bool sxmf_f2fs_sb(sx_context*c,uint64_t p){return SXMF_ADD(c,f2fs_superblock_prefix,p)&&SXMF_TABLE(c,f2fs_device,p+2201,8)&&SXMF_ADD(c,f2fs_superblock_tail,p+2745);}
static bool sxmf_f2fs(sx_context*c){
 uint8_t h[128],b[192];if(!sxmf_read(c,1024,h,128)||sxmf32(h,0)!=0xf2f52010U||sxmf32(h+16,0)!=12)return false;
 uint64_t blocks=sxmf64(h+36,0);if(!blocks||blocks>(uint64_t)c->size/4096||!sxmf_f2fs_sb(c,1024))return false;
 if(sxmf_read(c,5120,b,4)&&sxmf32(b,0)==0xf2f52010U&&sxmf_span(c,5120,3072)&&!sxmf_f2fs_sb(c,5120))return false;
 uint64_t cp=sxmf32(h+76,0),nat=sxmf32(h+84,0),seglog=sxmf32(h+20,0);uint32_t root=sxmf32(h+96,0);
 for(unsigned i=0;i<2;i++){uint64_t block=cp;if(i){if(seglog>31)break;block+=UINT64_C(1)<<seglog;}if(block>=blocks||!sxmf_read(c,block*4096,b,192))continue;
  uint64_t total=sxmf32(b+136,0),crc=sxmf32(b+164,0);if(!sxmf64(b,0)||total<2||total>blocks-block||crc<192||crc>4092)continue;
  if(!SXMF_ADD(c,f2fs_checkpoint_header,block*4096))return false;
 }
 if(nat&&nat<blocks&&sxmf32(h+60,0)&&!SXMF_TABLE(c,f2fs_nat_entry,nat*4096,4096/9))return false;
 if(nat&&nat<blocks&&root<4096/9&&sxmf_read(c,nat*4096+(uint64_t)root*9,b,9)){
  uint64_t node=sxmf32(b+5,0);if(node&&node<blocks&&sxmf_read(c,node*4096+4072,b,24)&&sxmf32(b,0)==root&&sxmf32(b+4,0)==root&&!SXMF_ADD(c,f2fs_node_footer,node*4096+4072))return false;
 }
 return true;
}
bool sx_f2fs_build(sx_context*c)
{
 return sxmf_f2fs(c);
}
#undef SXMF_ADD
#undef SXMF_TABLE
