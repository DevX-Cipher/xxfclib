/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * UNICOS_FS data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_unicos_superblock_prefix_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("filesystem_name","char[8]",8,8,SX_NONE),
    SX_FIELD("pack_name","char[8]",16,8,SX_NONE),
    SX_FIELD("device","int64",24,8,SX_ID),
    SX_FIELD("block_count","int64",32,8,SX_COUNT_PROP),
    SX_FIELD("inode_count","int64",40,8,SX_COUNT_PROP),
    SX_FIELD("big_file_threshold","int64",48,8,SX_SIZE),
    SX_FIELD("big_file_minimum_blocks","int64",56,8,SX_COUNT_PROP),
    SX_FIELD("secure_label","uint64",64,8,SX_SIGNATURE),
    SX_FIELD("maximum_security_level","int64",72,8,SX_NONE),
    SX_FIELD("minimum_security_level","int64",80,8,SX_NONE),
    SX_FIELD("valid_security_compartments","int64",88,8,SX_FLAGS),
    SX_FIELD("last_update","int64",96,8,SX_TIME),
    SX_FIELD("dynamic_block","int64",104,8,SX_NONE),
    SX_FIELD("root_inode","int64",112,8,SX_NONE),
    SX_FIELD("filesystem_error","int64",120,8,SX_ID),
    SX_FIELD("first_map_block","int64",128,8,SX_NONE),
    SX_FIELD("last_map_block","int64",136,8,SX_NONE),
    SX_FIELD("superblock_copies","int64",144,8,SX_COUNT_PROP),
    SX_FIELD("partition_count","int64",152,8,SX_COUNT_PROP),
    SX_FIELD("inode_block_ratio","int64",160,8,SX_NONE),
    SX_FIELD("shared_filesystem_extent","int64",168,8,SX_NONE),
    SX_FIELD("flags","int64",176,8,SX_FLAGS),
};
const sx_layout sxcf_unicos_superblock_prefix = {0x603d0060U,"unicos_superblock_prefix",sxcf_unicos_superblock_prefix_fields,SX_COUNT(sxcf_unicos_superblock_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_unicos_partition_fields[] = {
    SX_FIELD("device_name","int64",0,8,SX_ID),
    SX_FIELD("first_block","uint32",8,4,SX_NONE),
    SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("region0_reserved","uint16",16,2,SX_RESERVED),
    SX_FIELD("region0_blocks","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("region0_first_block","uint32",20,4,SX_NONE),
    SX_FIELD("region1_reserved","uint16",24,2,SX_RESERVED),
    SX_FIELD("region1_blocks","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("region1_first_block","uint32",28,4,SX_NONE),
    SX_FIELD("region2_reserved","uint16",32,2,SX_RESERVED),
    SX_FIELD("region2_blocks","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("region2_first_block","uint32",36,4,SX_NONE),
    SX_FIELD("region3_reserved","uint16",40,2,SX_RESERVED),
    SX_FIELD("region3_blocks","uint16",42,2,SX_COUNT_PROP),
    SX_FIELD("region3_first_block","uint32",44,4,SX_NONE),
};
const sx_layout sxcf_unicos_partition = {0x603d0061U,"unicos_partition",sxcf_unicos_partition_fields,SX_COUNT(sxcf_unicos_partition_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_unicos_superblock_tail_fields[] = {
    SX_FIELD("io_unit","int64",0,8,SX_NONE),
    SX_FIELD("inode_reservation_blocks_minus_one","int64",8,8,SX_NONE),
    SX_FIELD("primary_partitions","int64",16,8,SX_FLAGS),
    SX_FIELD("primary_block_words_minus_one","int64",24,8,SX_NONE),
    SX_FIELD("primary_blocks","int64",32,8,SX_COUNT_PROP),
    SX_FIELD("secondary_partitions","int64",40,8,SX_FLAGS),
    SX_FIELD("secondary_block_words_minus_one","int64",48,8,SX_NONE),
    SX_FIELD("secondary_blocks","int64",56,8,SX_COUNT_PROP),
    SX_FIELD("filesystem_data_partitions","int64",64,8,SX_FLAGS),
    SX_FIELD("root_directory_partitions","int64",72,8,SX_FLAGS),
    SX_FIELD("no_user_data_partitions","int64",80,8,SX_FLAGS),
    SX_FIELD("semaphore_count","int64",88,8,SX_COUNT_PROP),
    SX_FIELD("active_primary_partitions","int64",96,8,SX_FLAGS),
    SX_FIELD("arbiter_identifier","int64",104,8,SX_ID),
    SX_FIELD("reserved","byte[728]",112,728,SX_RESERVED),
};
const sx_layout sxcf_unicos_superblock_tail = {0x603d0062U,"unicos_superblock_tail",sxcf_unicos_superblock_tail_fields,SX_COUNT(sxcf_unicos_superblock_tail_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_unicos_inode_prefix_fields[] = {
    SX_FIELD("mode_encoded","uint32",0,4,SX_FLAGS),
    SX_FIELD("links_encoded","uint32",4,4,SX_FLAGS),
    SX_FIELD("opaque_08","byte[16]",8,16,SX_NONE),
    SX_FIELD("file_size","uint64",24,8,SX_SIZE),
    SX_FIELD("opaque_20","byte[49]",32,49,SX_NONE),
    SX_FIELD("allocation_device_flags","uint8",81,1,SX_FLAGS),
    SX_FIELD("opaque_52","byte[6]",82,6,SX_NONE),
    SX_FIELD("allocation_type_flags","uint8",88,1,SX_FLAGS),
    SX_FIELD("opaque_59","byte[39]",89,39,SX_NONE),
};
const sx_layout sxcf_unicos_inode_prefix = {0x603d0063U,"unicos_inode_prefix",sxcf_unicos_inode_prefix_fields,SX_COUNT(sxcf_unicos_inode_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_unicos_extent_fields[] = {
    SX_FIELD("blocks_encoded","uint32",0,4,SX_FLAGS),
    SX_FIELD("first_block","uint32",4,4,SX_NONE),
};
const sx_layout sxcf_unicos_extent = {0x603d0064U,"unicos_extent",sxcf_unicos_extent_fields,SX_COUNT(sxcf_unicos_extent_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_unicos_inode_tail_fields[] = {
    SX_FIELD("opaque_c0","byte[46]",0,46,SX_NONE),
    SX_FIELD("external_device","uint16",46,2,SX_NONE),
    SX_FIELD("opaque_f0","byte[16]",48,16,SX_NONE),
};
const sx_layout sxcf_unicos_inode_tail = {0x603d0065U,"unicos_inode_tail",sxcf_unicos_inode_tail_fields,SX_COUNT(sxcf_unicos_inode_tail_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_unicos_directory_header_fields[] = {
    SX_FIELD("inode_number","uint64",0,8,SX_NONE),
    SX_FIELD("opaque_08","byte[8]",8,8,SX_NONE),
    SX_FIELD("record_and_name_lengths","uint64",16,8,SX_FLAGS),
};
const sx_layout sxcf_unicos_directory_header = {0x603d0066U,"unicos_directory_header",sxcf_unicos_directory_header_fields,SX_COUNT(sxcf_unicos_directory_header_fields),SX_BE};
#define SXCF_LIMIT 24000U
#define SXCF_INODES 262144U
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
#define SXCF_TABLE(c,l,p,n) sxcf_put(c,&sxcf_##l,p,n)
static bool sxcf_unicos(sx_context*c){
 uint8_t h[4096],b[256],d[24];uint64_t sb=0;if(!sxcf_read(c,0,h,4096)||sxcf64(h,1)!=UINT64_C(0x6e6331667331636e)){sb=4096;if(!sxcf_read(c,sb,h,4096)||sxcf64(h,1)!=UINT64_C(0x6e6331667331636e))return false;}
 uint64_t blocks=sxcf64(h+32,1),a=sxcf64(h+3264,1),v=sxcf64(h+3280,1);if(!blocks||a>15||v>15||sxcf64(h+152,1)!=1)return false;
 if(!SXCF_ADD(c,unicos_superblock_prefix,sb)||!SXCF_TABLE(c,unicos_partition,sb+184,64)||!SXCF_ADD(c,unicos_superblock_tail,sb+3256))return false;unsigned visits=0;
 for(unsigned region=0;region<4;region++){uint64_t first=sxcf32(h+204+region*8,1),count=sxcf16(h+202+region*8,1),bitmap=(a+1)*(v+1);if(!count||first>=blocks||count>blocks-first||bitmap>=count)continue;
  for(uint64_t i=0;i<(count-bitmap)*16&&visits<SXCF_INODES&&c->count<SXCF_LIMIT;i++,visits++){uint64_t p=(first+bitmap)*4096+i*256;if(!sxcf_read(c,p,b,256))break;if(!sxcf32(b,1))continue;if(!SXCF_ADD(c,unicos_inode_prefix,p)||!SXCF_TABLE(c,unicos_extent,p+128,8)||!SXCF_ADD(c,unicos_inode_tail,p+192))return false;
   if((sxcf32(b,1)&0xf000)!=0x4000||(b[88]&15)!=1)continue;uint64_t left=sxcf64(b+24,1);
   for(unsigned k=0;k<8&&left&&c->count<SXCF_LIMIT;k++){uint64_t n=sxcf32(b+128+8*k,1),at=sxcf32(b+132+8*k,1);if(!n||(n&0x80000000)||at>=blocks||n>blocks-at)break;n*=4096;if(n>left)n=left;
    for(uint64_t q=0;q+24<=n&&c->count<SXCF_LIMIT;){if(!sxcf_read(c,at*4096+q,d,24))return false;uint64_t word=sxcf64(d+16,1),z=(word>>10)&0x3fffff,names=word&1023;if(z<24||(z&7)||z>n-q||z>4096-q%4096||names>z-24)break;if(!SXCF_ADD(c,unicos_directory_header,at*4096+q))return false;q+=z;}left-=n;
   }
  }
 }return true;
}
bool sx_unicos_fs_build(sx_context*c)
{
 return sxcf_unicos(c);
}
