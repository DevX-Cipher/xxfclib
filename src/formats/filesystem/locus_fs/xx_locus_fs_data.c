/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LOCUS_FS data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_locus_superblock_prefix_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("global_filesystem","int32",4,4,SX_ID),
    SX_FIELD("block_count","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("commit_low_water","int32",12,4,SX_NONE),
    SX_FIELD("commit_high_water","int32",16,4,SX_NONE),
    SX_FIELD("oldest_commit","int32",20,4,SX_NONE),
    SX_FIELD("storage_mask","int32",24,4,SX_FLAGS),
    SX_FIELD("last_update","int32",28,4,SX_TIME),
    SX_FIELD("free_block_count","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("inode_table_blocks","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","int16",40,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",42,2,SX_FLAGS),
    SX_FIELD("free_inode_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("last_inode_search","int32",48,4,SX_NONE),
    SX_FIELD("estimated_prior_free_inodes","int32",52,4,SX_COUNT_PROP),
    SX_FIELD("pack_number","int16",56,2,SX_NONE),
    SX_FIELD("free_inode_cache_count","int16",58,2,SX_COUNT_PROP),
    SX_FIELD("device_information","int16[4]",60,8,SX_NONE),
    SX_FIELD("block_lock","uint8",68,1,SX_FLAGS),
    SX_FIELD("inode_lock","uint8",69,1,SX_FLAGS),
    SX_FIELD("modified","uint8",70,1,SX_FLAGS),
    SX_FIELD("version","uint8",71,1,SX_ID),
    SX_FIELD("mount_name","char[32]",72,32,SX_NONE),
    SX_FIELD("pack_name","char[8]",104,8,SX_NONE),
};
const sx_layout sxcf_locus_superblock_prefix_le = {0x603d003fU,"locus_superblock_prefix_le",sxcf_locus_superblock_prefix_le_fields,SX_COUNT(sxcf_locus_superblock_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_locus_superblock_prefix_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("global_filesystem","int32",4,4,SX_ID),
    SX_FIELD("block_count","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("commit_low_water","int32",12,4,SX_NONE),
    SX_FIELD("commit_high_water","int32",16,4,SX_NONE),
    SX_FIELD("oldest_commit","int32",20,4,SX_NONE),
    SX_FIELD("storage_mask","int32",24,4,SX_FLAGS),
    SX_FIELD("last_update","int32",28,4,SX_TIME),
    SX_FIELD("free_block_count","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("inode_table_blocks","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","int16",40,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",42,2,SX_FLAGS),
    SX_FIELD("free_inode_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("last_inode_search","int32",48,4,SX_NONE),
    SX_FIELD("estimated_prior_free_inodes","int32",52,4,SX_COUNT_PROP),
    SX_FIELD("pack_number","int16",56,2,SX_NONE),
    SX_FIELD("free_inode_cache_count","int16",58,2,SX_COUNT_PROP),
    SX_FIELD("device_information","int16[4]",60,8,SX_NONE),
    SX_FIELD("block_lock","uint8",68,1,SX_FLAGS),
    SX_FIELD("inode_lock","uint8",69,1,SX_FLAGS),
    SX_FIELD("modified","uint8",70,1,SX_FLAGS),
    SX_FIELD("version","uint8",71,1,SX_ID),
    SX_FIELD("mount_name","char[32]",72,32,SX_NONE),
    SX_FIELD("pack_name","char[8]",104,8,SX_NONE),
};
const sx_layout sxcf_locus_superblock_prefix_be = {0x603d0040U,"locus_superblock_prefix_be",sxcf_locus_superblock_prefix_be_fields,SX_COUNT(sxcf_locus_superblock_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_locus_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int16",4,2,SX_ID),
    SX_FIELD("group_id","int16",6,2,SX_ID),
    SX_FIELD("unique_identifier","int32",8,4,SX_ID),
    SX_FIELD("reserved0","int16",12,2,SX_RESERVED),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("file_size","int32",16,4,SX_SIZE),
    SX_FIELD("modification_time","int32",20,4,SX_TIME),
    SX_FIELD("access_time","int32",24,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",28,4,SX_TIME),
    SX_FIELD("commit_count","int32",32,4,SX_NONE),
    SX_FIELD("storage_mask","int32",36,4,SX_FLAGS),
    SX_FIELD("version","int32",40,4,SX_NONE),
    SX_FIELD("allocated_blocks","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[28]",48,28,SX_RESERVED),
    SX_FIELD("block_numbers","int32[13]",76,52,SX_NONE),
};
const sx_layout sxcf_locus_inode_le = {0x603d0041U,"locus_inode_le",sxcf_locus_inode_le_fields,SX_COUNT(sxcf_locus_inode_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_locus_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int16",4,2,SX_ID),
    SX_FIELD("group_id","int16",6,2,SX_ID),
    SX_FIELD("unique_identifier","int32",8,4,SX_ID),
    SX_FIELD("reserved0","int16",12,2,SX_RESERVED),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("file_size","int32",16,4,SX_SIZE),
    SX_FIELD("modification_time","int32",20,4,SX_TIME),
    SX_FIELD("access_time","int32",24,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",28,4,SX_TIME),
    SX_FIELD("commit_count","int32",32,4,SX_NONE),
    SX_FIELD("storage_mask","int32",36,4,SX_FLAGS),
    SX_FIELD("version","int32",40,4,SX_NONE),
    SX_FIELD("allocated_blocks","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[28]",48,28,SX_RESERVED),
    SX_FIELD("block_numbers","int32[13]",76,52,SX_NONE),
};
const sx_layout sxcf_locus_inode_be = {0x603d0042U,"locus_inode_be",sxcf_locus_inode_be_fields,SX_COUNT(sxcf_locus_inode_be_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_locus_inode_small_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int16",4,2,SX_ID),
    SX_FIELD("group_id","int16",6,2,SX_ID),
    SX_FIELD("unique_identifier","int32",8,4,SX_ID),
    SX_FIELD("reserved0","int16",12,2,SX_RESERVED),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("file_size","int32",16,4,SX_SIZE),
    SX_FIELD("modification_time","int32",20,4,SX_TIME),
    SX_FIELD("access_time","int32",24,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",28,4,SX_TIME),
    SX_FIELD("commit_count","int32",32,4,SX_NONE),
    SX_FIELD("storage_mask","int32",36,4,SX_FLAGS),
    SX_FIELD("version","int32",40,4,SX_NONE),
    SX_FIELD("allocated_blocks","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[27]",48,27,SX_RESERVED),
    SX_FIELD("small_block_flags","uint8",75,1,SX_FLAGS),
    SX_FIELD("block_numbers","int32[13]",76,52,SX_NONE),
};
const sx_layout sxcf_locus_inode_small_le = {0x603d0043U,"locus_inode_small_le",sxcf_locus_inode_small_le_fields,SX_COUNT(sxcf_locus_inode_small_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_locus_inode_small_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int16",4,2,SX_ID),
    SX_FIELD("group_id","int16",6,2,SX_ID),
    SX_FIELD("unique_identifier","int32",8,4,SX_ID),
    SX_FIELD("reserved0","int16",12,2,SX_RESERVED),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("file_size","int32",16,4,SX_SIZE),
    SX_FIELD("modification_time","int32",20,4,SX_TIME),
    SX_FIELD("access_time","int32",24,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",28,4,SX_TIME),
    SX_FIELD("commit_count","int32",32,4,SX_NONE),
    SX_FIELD("storage_mask","int32",36,4,SX_FLAGS),
    SX_FIELD("version","int32",40,4,SX_NONE),
    SX_FIELD("allocated_blocks","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[27]",48,27,SX_RESERVED),
    SX_FIELD("small_block_flags","uint8",75,1,SX_FLAGS),
    SX_FIELD("block_numbers","int32[13]",76,52,SX_NONE),
};
const sx_layout sxcf_locus_inode_small_be = {0x603d0044U,"locus_inode_small_be",sxcf_locus_inode_small_be_fields,SX_COUNT(sxcf_locus_inode_small_be_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_locus_directory_header_le_fields[] = {
    SX_FIELD("inode_number","int32",0,4,SX_NONE),
    SX_FIELD("record_size","uint16",4,2,SX_SIZE),
    SX_FIELD("name_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxcf_locus_directory_header_le = {0x603d0045U,"locus_directory_header_le",sxcf_locus_directory_header_le_fields,SX_COUNT(sxcf_locus_directory_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_locus_directory_header_be_fields[] = {
    SX_FIELD("inode_number","int32",0,4,SX_NONE),
    SX_FIELD("record_size","uint16",4,2,SX_SIZE),
    SX_FIELD("name_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxcf_locus_directory_header_be = {0x603d0046U,"locus_directory_header_be",sxcf_locus_directory_header_be_fields,SX_COUNT(sxcf_locus_directory_header_be_fields),SX_BE};
#define SXCF_LIMIT 24000U
#define SXCF_INODES 262144U
#define SXCF_ORDER(l,o) ((o)==1?&sxcf_##l##_be:&sxcf_##l##_le)
static bool sxcf_locus(sx_context*c){
 uint8_t h[128],b[128];uint64_t sb;unsigned o=0;bool found=false;
 for(sb=0;sb<=4096;sb+=512){if(!sxcf_read(c,sb,h,128))continue;for(o=0;o<2;o++){uint32_t m=sxcf32(h,o);if(m==0xffeeddcc||m==0xffeeddcd){found=true;break;}}if(found)break;}
 if(!found||(h[71]!=1&&h[71]!=2))return false;uint64_t bs=h[71]==1?4096:1024,blocks=sxcf32(h+8,o),ib=sxcf32(h+36,o),isize=h[71]==1?512:128;
 if(!sxcf_put(c,SXCF_ORDER(locus_superblock_prefix,o),sb,1))return false;
 if(blocks<2||!ib||ib>blocks-2||!sxcf_span(c,2*bs,ib*bs))return true;
 uint64_t nodes=ib*(bs/isize);if(nodes>SXCF_INODES)nodes=SXCF_INODES;
 for(uint64_t i=0;i<nodes&&c->count<SXCF_LIMIT;i++){uint64_t p=2*bs+i*isize;if(!sxcf_read(c,p,b,128)||!sxcf_put(c,h[71]==1?SXCF_ORDER(locus_inode_small,o):SXCF_ORDER(locus_inode,o),p,1))return false;
  unsigned flags=sxcf16(b+14,o);if((sxcf16(b,o)&0xf000)!=0x4000||(flags&0x13)!=0x12)continue;uint64_t left=sxcf32(b+16,o);if(h[71]==1&&(b[75]&1)){uint64_t n=left<384?left:384;if(!(flags&0x40)&&!sxcf_dir(c,p+128,n,0,o,16))return false;continue;}
  for(unsigned k=0;k<10&&left;k++){uint64_t nr=sxcf32(b+76+4*k,o),n=left<bs?left:bs;if(nr>=blocks)break;if(nr){if(!(flags&0x40)){if(!sxcf_dir(c,nr*bs,n,0,o,16))return false;}else for(uint64_t q=0;q+8<=n&&c->count<SXCF_LIMIT;){uint8_t e[8];if(!sxcf_read(c,nr*bs+q,e,8))return false;unsigned z=sxcf16(e+4,o),names=sxcf16(e+6,o);if(z<8||(z&3)||z>n-q||names>z-8)break;if(!sxcf_put(c,SXCF_ORDER(locus_directory_header,o),nr*bs+q,1))return false;q+=z;}}left-=n;}
 }return true;
}
bool sx_locus_fs_build(sx_context*c)
{
 return sxcf_locus(c);
}
