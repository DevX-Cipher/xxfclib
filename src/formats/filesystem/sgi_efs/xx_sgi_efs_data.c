/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SGI_EFS data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_efs_superblock_fields[] = {
    SX_FIELD("block_count","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("first_cylinder_group","int32",4,4,SX_NONE),
    SX_FIELD("cylinder_group_blocks","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("inode_blocks_per_group","int16",12,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","int16",14,2,SX_COUNT_PROP),
    SX_FIELD("heads","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("cylinder_group_count","int16",18,2,SX_COUNT_PROP),
    SX_FIELD("dirty","int16",20,2,SX_FLAGS),
    SX_FIELD("padding","int16",22,2,SX_RESERVED),
    SX_FIELD("last_update","int32",24,4,SX_TIME),
    SX_FIELD("magic","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("volume_name","char[6]",32,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",38,6,SX_NONE),
    SX_FIELD("bitmap_size","int32",44,4,SX_SIZE),
    SX_FIELD("free_blocks","int32",48,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","int32",52,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_block","int32",56,4,SX_NONE),
    SX_FIELD("replicated_superblock","int32",60,4,SX_NONE),
    SX_FIELD("last_allocated_inode","int32",64,4,SX_NONE),
    SX_FIELD("reserved","byte[20]",68,20,SX_RESERVED),
    SX_FIELD("checksum","uint32",88,4,SX_CHECKSUM),
};
const sx_layout sxcf_efs_superblock = {0x603d0032U,"efs_superblock",sxcf_efs_superblock_fields,SX_COUNT(sxcf_efs_superblock_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_efs_inode_header_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","int32",8,4,SX_SIZE),
    SX_FIELD("access_time","int32",12,4,SX_TIME),
    SX_FIELD("modification_time","int32",16,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",20,4,SX_TIME),
    SX_FIELD("generation","uint32",24,4,SX_NONE),
    SX_FIELD("extent_count","int16",28,2,SX_COUNT_PROP),
    SX_FIELD("version","uint8",30,1,SX_ID),
    SX_FIELD("spare","uint8",31,1,SX_RESERVED),
};
const sx_layout sxcf_efs_inode_header = {0x603d0033U,"efs_inode_header",sxcf_efs_inode_header_fields,SX_COUNT(sxcf_efs_inode_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_efs_extent_fields[] = {
    SX_FIELD("magic","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("first_block","uint24",1,3,SX_NONE),
    SX_FIELD("block_count","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("logical_block","uint24",5,3,SX_NONE),
};
const sx_layout sxcf_efs_extent = {0x603d0034U,"efs_extent",sxcf_efs_extent_fields,SX_COUNT(sxcf_efs_extent_fields),SX_BE};
#define SXCF_LIMIT 24000U
#define SXCF_INODES 262144U
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
#define SXCF_TABLE(c,l,p,n) sxcf_put(c,&sxcf_##l,p,n)
static bool sxcf_efs(sx_context*c){
 uint8_t h[92],b[128];if(!sxcf_read(c,512,h,92)||(sxcf32(h+28,1)!=0x72959&&sxcf32(h+28,1)!=0x7295a))return false;
 uint64_t blocks=sxcf32(h,1),first=sxcf32(h+4,1),group=sxcf32(h+8,1),ib=sxcf16(h+12,1),groups=sxcf16(h+18,1);
 if(!blocks||!group||!ib||!groups||ib>=group||first>=blocks||groups>(blocks-first)/group||!sxcf_span(c,0,blocks*512)||!SXCF_ADD(c,efs_superblock,512))return false;
 unsigned visits=0;for(uint64_t cg=0;cg<groups&&visits<SXCF_INODES&&c->count<SXCF_LIMIT;cg++)for(uint64_t i=0;i<ib*4&&visits<SXCF_INODES&&c->count<SXCF_LIMIT;i++,visits++){
  uint64_t p=(first+cg*group)*512+i*128;if(!sxcf_read(c,p,b,128)||!SXCF_ADD(c,efs_inode_header,p))return false;unsigned mode=sxcf16(b,1)&0xf000,count=sxcf16(b+28,1);uint64_t size=sxcf32(b+8,1);
  if(mode!=0x4000&&mode!=0x8000&&mode!=0xa000)continue;
  if(count<=12){if(!SXCF_TABLE(c,efs_extent,p+32,count))return false;if(mode==0x4000)for(unsigned k=0;k<count;k++){uint8_t*e=b+32+8*k;uint64_t at=sxcf24(e+1,1),n=e[4],logical=sxcf24(e+5,1)*512;if(e[0]||at>=blocks||n>blocks-at||logical>=size)continue;n*=512;if(n>size-logical)n=size-logical;if(!sxcf_dir(c,at*512,n,5,1,0))return false;}}
  else{/* Extent-array blocks are physically addressed by the inode extents.
         * Only complete bounded arrays are disclosed, without reconstructing files. */
   unsigned indirect=sxcf24(b+37,1);if(!indirect||indirect>12)continue;if(!SXCF_TABLE(c,efs_extent,p+32,indirect))return false;uint64_t remaining=count;
   for(unsigned k=0;k<indirect&&remaining;k++){uint8_t*e=b+32+8*k;uint64_t at=sxcf24(e+1,1),n=e[4];if(e[0]||at>=blocks||n>blocks-at)break;uint64_t slots=n*64;if(slots>remaining)slots=remaining;if(!SXCF_TABLE(c,efs_extent,at*512,slots))return false;remaining-=slots;}
  }
 }return true;
}
bool sx_sgi_efs_build(sx_context*c)
{
 return sxcf_efs(c);
}
