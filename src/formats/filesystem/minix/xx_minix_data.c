/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * minix data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_minix1_superblock_le_fields[] = {
    SX_FIELD("inode_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("zone_count_16","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_blocks","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",8,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",10,2,SX_NONE),
    SX_FIELD("max_file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("magic","uint16",16,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",18,2,SX_FLAGS),
};
const sx_layout sxcf_minix1_superblock_le = {0x603d0001U,"minix1_superblock_le",sxcf_minix1_superblock_le_fields,SX_COUNT(sxcf_minix1_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_minix1_superblock_be_fields[] = {
    SX_FIELD("inode_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("zone_count_16","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_blocks","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",8,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",10,2,SX_NONE),
    SX_FIELD("max_file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("magic","uint16",16,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",18,2,SX_FLAGS),
};
const sx_layout sxcf_minix1_superblock_be = {0x603d0002U,"minix1_superblock_be",sxcf_minix1_superblock_be_fields,SX_COUNT(sxcf_minix1_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_minix2_superblock_le_fields[] = {
    SX_FIELD("inode_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("zone_count_16","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_blocks","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",8,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",10,2,SX_NONE),
    SX_FIELD("max_file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("magic","uint16",16,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",18,2,SX_FLAGS),
    SX_FIELD("zone_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxcf_minix2_superblock_le = {0x603d0003U,"minix2_superblock_le",sxcf_minix2_superblock_le_fields,SX_COUNT(sxcf_minix2_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_minix2_superblock_be_fields[] = {
    SX_FIELD("inode_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("zone_count_16","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_blocks","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",8,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",10,2,SX_NONE),
    SX_FIELD("max_file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("magic","uint16",16,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",18,2,SX_FLAGS),
    SX_FIELD("zone_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxcf_minix2_superblock_be = {0x603d0004U,"minix2_superblock_be",sxcf_minix2_superblock_be_fields,SX_COUNT(sxcf_minix2_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_minix3_superblock_le_fields[] = {
    SX_FIELD("inode_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("padding0","uint16",4,2,SX_RESERVED),
    SX_FIELD("inode_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",10,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",12,2,SX_NONE),
    SX_FIELD("padding1","uint16",14,2,SX_RESERVED),
    SX_FIELD("max_file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("zone_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("magic","uint16",24,2,SX_SIGNATURE),
    SX_FIELD("padding2","uint16",26,2,SX_RESERVED),
    SX_FIELD("block_size","uint16",28,2,SX_SIZE),
    SX_FIELD("disk_version","uint8",30,1,SX_ID),
};
const sx_layout sxcf_minix3_superblock_le = {0x603d0005U,"minix3_superblock_le",sxcf_minix3_superblock_le_fields,SX_COUNT(sxcf_minix3_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_minix3_superblock_be_fields[] = {
    SX_FIELD("inode_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("padding0","uint16",4,2,SX_RESERVED),
    SX_FIELD("inode_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",10,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",12,2,SX_NONE),
    SX_FIELD("padding1","uint16",14,2,SX_RESERVED),
    SX_FIELD("max_file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("zone_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("magic","uint16",24,2,SX_SIGNATURE),
    SX_FIELD("padding2","uint16",26,2,SX_RESERVED),
    SX_FIELD("block_size","uint16",28,2,SX_SIZE),
    SX_FIELD("disk_version","uint8",30,1,SX_ID),
};
const sx_layout sxcf_minix3_superblock_be = {0x603d0006U,"minix3_superblock_be",sxcf_minix3_superblock_be_fields,SX_COUNT(sxcf_minix3_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_minix1_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("user_id","uint16",2,2,SX_ID),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
    SX_FIELD("modification_time","uint32",8,4,SX_TIME),
    SX_FIELD("group_id","uint8",12,1,SX_ID),
    SX_FIELD("link_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("zone_numbers","uint16[9]",14,18,SX_NONE),
};
const sx_layout sxcf_minix1_inode_le = {0x603d0007U,"minix1_inode_le",sxcf_minix1_inode_le_fields,SX_COUNT(sxcf_minix1_inode_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_minix1_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("user_id","uint16",2,2,SX_ID),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
    SX_FIELD("modification_time","uint32",8,4,SX_TIME),
    SX_FIELD("group_id","uint8",12,1,SX_ID),
    SX_FIELD("link_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("zone_numbers","uint16[9]",14,18,SX_NONE),
};
const sx_layout sxcf_minix1_inode_be = {0x603d0008U,"minix1_inode_be",sxcf_minix1_inode_be_fields,SX_COUNT(sxcf_minix1_inode_be_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_minix23_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("access_time","uint32",12,4,SX_TIME),
    SX_FIELD("modification_time","uint32",16,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32",20,4,SX_TIME),
    SX_FIELD("zone_numbers","uint32[10]",24,40,SX_NONE),
};
const sx_layout sxcf_minix23_inode_le = {0x603d0009U,"minix23_inode_le",sxcf_minix23_inode_le_fields,SX_COUNT(sxcf_minix23_inode_le_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_minix23_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("access_time","uint32",12,4,SX_TIME),
    SX_FIELD("modification_time","uint32",16,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32",20,4,SX_TIME),
    SX_FIELD("zone_numbers","uint32[10]",24,40,SX_NONE),
};
const sx_layout sxcf_minix23_inode_be = {0x603d000aU,"minix23_inode_be",sxcf_minix23_inode_be_fields,SX_COUNT(sxcf_minix23_inode_be_fields),SX_BE};
#define SXCF_LIMIT 24000U
#define SXCF_INODES 262144U
#define SXCF_ORDER(l,o) ((o)==1?&sxcf_##l##_be:&sxcf_##l##_le)
static bool sxcf_minix(sx_context*c){
 uint8_t h[32],b[64];if(!sxcf_read(c,1024,h,32))return false;unsigned o=0,v=0,names=0;uint32_t imap,zmap,first,shift,bs=1024,ninodes,zones;
 for(o=0;o<2;o++){uint16_t m=sxcf16(h+16,o);if(m==0x137f||m==0x138f||m==0x2468||m==0x2478){v=(m==0x137f||m==0x138f)?1:2;names=(m==0x137f||m==0x2468)?14:30;break;}if(sxcf16(h+24,o)==0x4d5a){v=3;names=60;break;}}
 if(!v)return false;
 if(v<3){ninodes=sxcf16(h,o);imap=sxcf16(h+4,o);zmap=sxcf16(h+6,o);first=sxcf16(h+8,o);shift=sxcf16(h+10,o);zones=v==1?sxcf16(h+2,o):sxcf32(h+20,o);if(sxcf16(h+18,o)>3)return false;}
 else{ninodes=sxcf32(h,o);imap=sxcf16(h+6,o);zmap=sxcf16(h+8,o);first=sxcf16(h+10,o);shift=sxcf16(h+12,o);zones=sxcf32(h+20,o);bs=sxcf16(h+28,o);if(bs<1024||bs>32768||!sxcf_pow(bs))return false;}
 unsigned isize=v==1?32:64;uint64_t table=(2+(uint64_t)imap+zmap)*bs,blocks=((uint64_t)ninodes*isize+bs-1)/bs;
 if(!ninodes||!imap||!zmap||!zones||shift>4||first>=zones||first!=((2+(uint64_t)imap+zmap+blocks+((UINT64_C(1)<<shift)-1))>>shift)||!sxcf_span(c,0,(uint64_t)zones*(bs<<shift))||!sxcf_span(c,table,(uint64_t)ninodes*isize))return false;
 if(!sxcf_put(c,v==1?SXCF_ORDER(minix1_superblock,o):v==2?SXCF_ORDER(minix2_superblock,o):SXCF_ORDER(minix3_superblock,o),1024,1)||!sxcf_put(c,v==1?SXCF_ORDER(minix1_inode,o):SXCF_ORDER(minix23_inode,o),table,ninodes<SXCF_INODES?ninodes:SXCF_INODES))return false;
 for(uint32_t i=0;i<ninodes&&i<SXCF_INODES&&c->count<SXCF_LIMIT;i++){if(!sxcf_read(c,table+(uint64_t)i*isize,b,isize))return false;if((sxcf16(b,o)&0xf000)!=0x4000)continue;
  sxcf_map g={c,zones,(uint64_t)bs<<shift,bs,sxcf32(b+(v==1?4:8),o),o,v==1?2U:4U,1,names+(v==3?4:2),0,{0}};
  unsigned off=v==1?14:24,ptrs=v==1?9:10;for(unsigned k=0;k<ptrs&&g.left;k++){uint32_t ptr=v==1?sxcf16(b+off+k*2,o):sxcf32(b+off+k*4,o);if(!sxcf_pointer(&g,ptr,k<7?0:k-6))break;}
 }
 return true;
}
bool sx_minix_build(sx_context*c)
{
 return sxcf_minix(c);
}
