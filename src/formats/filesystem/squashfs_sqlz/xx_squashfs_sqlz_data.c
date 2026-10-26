/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Squashfs Sqlz data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_sqlz_squashfs2_superblock_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("bytes_used_legacy","uint32",8,4,SX_SIZE),
    SX_FIELD("uid_table_offset_legacy","uint32",12,4,SX_OFFSET),
    SX_FIELD("gid_table_offset_legacy","uint32",16,4,SX_OFFSET),
    SX_FIELD("inode_table_offset_legacy","uint32",20,4,SX_OFFSET),
    SX_FIELD("directory_table_offset_legacy","uint32",24,4,SX_OFFSET),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("block_size_legacy","uint16",32,2,SX_SIZE),
    SX_FIELD("block_log","uint16",34,2,SX_NONE),
    SX_FIELD("flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("uid_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("gid_count","uint8",38,1,SX_COUNT_PROP),
    SX_FIELD("creation_time","int32",39,4,SX_TIME),
    SX_FIELD("root_inode_reference","uint64",43,8,SX_FLAGS),
    SX_FIELD("block_size","uint32",51,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",55,4,SX_COUNT_PROP),
    SX_FIELD("fragment_index_offset_legacy","uint32",59,4,SX_OFFSET),
};
const sx_layout sxdn_sqlz_squashfs2_superblock_le = {0x60780054U,"sqlz_squashfs2_superblock_le",sxdn_sqlz_squashfs2_superblock_le_fields,SX_COUNT(sxdn_sqlz_squashfs2_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs2_superblock_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("bytes_used_legacy","uint32",8,4,SX_SIZE),
    SX_FIELD("uid_table_offset_legacy","uint32",12,4,SX_OFFSET),
    SX_FIELD("gid_table_offset_legacy","uint32",16,4,SX_OFFSET),
    SX_FIELD("inode_table_offset_legacy","uint32",20,4,SX_OFFSET),
    SX_FIELD("directory_table_offset_legacy","uint32",24,4,SX_OFFSET),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("block_size_legacy","uint16",32,2,SX_SIZE),
    SX_FIELD("block_log","uint16",34,2,SX_NONE),
    SX_FIELD("flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("uid_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("gid_count","uint8",38,1,SX_COUNT_PROP),
    SX_FIELD("creation_time","int32",39,4,SX_TIME),
    SX_FIELD("root_inode_reference","uint64",43,8,SX_FLAGS),
    SX_FIELD("block_size","uint32",51,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",55,4,SX_COUNT_PROP),
    SX_FIELD("fragment_index_offset_legacy","uint32",59,4,SX_OFFSET),
};
const sx_layout sxdn_sqlz_squashfs2_superblock_be = {0x60780055U,"sqlz_squashfs2_superblock_be",sxdn_sqlz_squashfs2_superblock_be_fields,SX_COUNT(sxdn_sqlz_squashfs2_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs3_superblock_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("bytes_used_legacy","uint32",8,4,SX_SIZE),
    SX_FIELD("uid_table_offset_legacy","uint32",12,4,SX_OFFSET),
    SX_FIELD("gid_table_offset_legacy","uint32",16,4,SX_OFFSET),
    SX_FIELD("inode_table_offset_legacy","uint32",20,4,SX_OFFSET),
    SX_FIELD("directory_table_offset_legacy","uint32",24,4,SX_OFFSET),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("block_size_legacy","uint16",32,2,SX_SIZE),
    SX_FIELD("block_log","uint16",34,2,SX_NONE),
    SX_FIELD("flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("uid_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("gid_count","uint8",38,1,SX_COUNT_PROP),
    SX_FIELD("creation_time","int32",39,4,SX_TIME),
    SX_FIELD("root_inode_reference","uint64",43,8,SX_FLAGS),
    SX_FIELD("block_size","uint32",51,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",55,4,SX_COUNT_PROP),
    SX_FIELD("fragment_index_offset_legacy","uint32",59,4,SX_OFFSET),
    SX_FIELD("bytes_used","uint64",63,8,SX_SIZE),
    SX_FIELD("uid_table_offset","uint64",71,8,SX_OFFSET),
    SX_FIELD("gid_table_offset","uint64",79,8,SX_OFFSET),
    SX_FIELD("inode_table_offset","uint64",87,8,SX_OFFSET),
    SX_FIELD("directory_table_offset","uint64",95,8,SX_OFFSET),
    SX_FIELD("fragment_index_offset","uint64",103,8,SX_OFFSET),
    SX_FIELD("lookup_index_offset","uint64",111,8,SX_OFFSET),
};
const sx_layout sxdn_sqlz_squashfs3_superblock_le = {0x60780056U,"sqlz_squashfs3_superblock_le",sxdn_sqlz_squashfs3_superblock_le_fields,SX_COUNT(sxdn_sqlz_squashfs3_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs3_superblock_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("bytes_used_legacy","uint32",8,4,SX_SIZE),
    SX_FIELD("uid_table_offset_legacy","uint32",12,4,SX_OFFSET),
    SX_FIELD("gid_table_offset_legacy","uint32",16,4,SX_OFFSET),
    SX_FIELD("inode_table_offset_legacy","uint32",20,4,SX_OFFSET),
    SX_FIELD("directory_table_offset_legacy","uint32",24,4,SX_OFFSET),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("block_size_legacy","uint16",32,2,SX_SIZE),
    SX_FIELD("block_log","uint16",34,2,SX_NONE),
    SX_FIELD("flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("uid_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("gid_count","uint8",38,1,SX_COUNT_PROP),
    SX_FIELD("creation_time","int32",39,4,SX_TIME),
    SX_FIELD("root_inode_reference","uint64",43,8,SX_FLAGS),
    SX_FIELD("block_size","uint32",51,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",55,4,SX_COUNT_PROP),
    SX_FIELD("fragment_index_offset_legacy","uint32",59,4,SX_OFFSET),
    SX_FIELD("bytes_used","uint64",63,8,SX_SIZE),
    SX_FIELD("uid_table_offset","uint64",71,8,SX_OFFSET),
    SX_FIELD("gid_table_offset","uint64",79,8,SX_OFFSET),
    SX_FIELD("inode_table_offset","uint64",87,8,SX_OFFSET),
    SX_FIELD("directory_table_offset","uint64",95,8,SX_OFFSET),
    SX_FIELD("fragment_index_offset","uint64",103,8,SX_OFFSET),
    SX_FIELD("lookup_index_offset","uint64",111,8,SX_OFFSET),
};
const sx_layout sxdn_sqlz_squashfs3_superblock_be = {0x60780057U,"sqlz_squashfs3_superblock_be",sxdn_sqlz_squashfs3_superblock_be_fields,SX_COUNT(sxdn_sqlz_squashfs3_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs_metadata_header_le_fields[] = {
    SX_FIELD("size_and_stored_flag","uint16",0,2,SX_FLAGS),
};
const sx_layout sxdn_sqlz_squashfs_metadata_header_le = {0x60780058U,"sqlz_squashfs_metadata_header_le",sxdn_sqlz_squashfs_metadata_header_le_fields,SX_COUNT(sxdn_sqlz_squashfs_metadata_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs_table_index_le_fields[] = {
    SX_FIELD("metadata_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxdn_sqlz_squashfs_table_index_le = {0x60780059U,"sqlz_squashfs_table_index_le",sxdn_sqlz_squashfs_table_index_le_fields,SX_COUNT(sxdn_sqlz_squashfs_table_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs2_fragment_index_le_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdn_sqlz_squashfs2_fragment_index_le = {0x6078005aU,"sqlz_squashfs2_fragment_index_le",sxdn_sqlz_squashfs2_fragment_index_le_fields,SX_COUNT(sxdn_sqlz_squashfs2_fragment_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs_identity_le_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
};
const sx_layout sxdn_sqlz_squashfs_identity_le = {0x6078005bU,"sqlz_squashfs_identity_le",sxdn_sqlz_squashfs_identity_le_fields,SX_COUNT(sxdn_sqlz_squashfs_identity_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs_metadata_header_be_fields[] = {
    SX_FIELD("size_and_stored_flag","uint16",0,2,SX_FLAGS),
};
const sx_layout sxdn_sqlz_squashfs_metadata_header_be = {0x6078005cU,"sqlz_squashfs_metadata_header_be",sxdn_sqlz_squashfs_metadata_header_be_fields,SX_COUNT(sxdn_sqlz_squashfs_metadata_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs_table_index_be_fields[] = {
    SX_FIELD("metadata_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxdn_sqlz_squashfs_table_index_be = {0x6078005dU,"sqlz_squashfs_table_index_be",sxdn_sqlz_squashfs_table_index_be_fields,SX_COUNT(sxdn_sqlz_squashfs_table_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs2_fragment_index_be_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdn_sqlz_squashfs2_fragment_index_be = {0x6078005eU,"sqlz_squashfs2_fragment_index_be",sxdn_sqlz_squashfs2_fragment_index_be_fields,SX_COUNT(sxdn_sqlz_squashfs2_fragment_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_sqlz_squashfs_identity_be_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
};
const sx_layout sxdn_sqlz_squashfs_identity_be = {0x6078005fU,"sqlz_squashfs_identity_be",sxdn_sqlz_squashfs_identity_be_fields,SX_COUNT(sxdn_sqlz_squashfs_identity_be_fields),SX_BE};
#define DN_PAIR(n,be) ((be)?&sxdn_##n##_be:&sxdn_##n##_le)
static bool sxdn_sqlz_meta(sx_context*c,uint64_t p,uint64_t end,bool be,unsigned*budget){while(p<end&&*budget){uint8_t b[2];if(end-p<2||!sxdn_read(c,p,b,2))break;uint64_t n=sxdn16(b,be)&32767;if(!n||n>8192||n>end-p-2)break;if(!sxdn_put(c,DN_PAIR(sqlz_squashfs_metadata_header,be),p,1))return false;p+=2+n;(*budget)--;}return true;}
static bool sxdn_sqlz_index(sx_context*c,uint64_t p,uint64_t count,unsigned width,unsigned header,bool be,unsigned*budget){if(!count||count>4096||p<header||!sxdn_span(c,p,count*width))return true;if(!sxdn_put(c,width==4?DN_PAIR(sqlz_squashfs2_fragment_index,be):DN_PAIR(sqlz_squashfs_table_index,be),p,count))return false;for(uint64_t i=0;i<count&&*budget;i++){uint64_t at;if(!sxdn_word(c,p+i*width,width,be,&at))return false;if(at>=header&&at<p&&!sxdn_sqlz_meta(c,at,p,be,budget))return false;}return true;}
static bool sxdn_sqlz(sx_context*c){uint8_t h[119];if(!sxdn_read(c,0,h,63))return false;bool be=!xx_rt_memcmp(h,"sqlz",4);if(!be&&xx_rt_memcmp(h,"zlqs",4))return false;unsigned v=sxdn16(h+28,be),header=v==2?63:119;if(v!=2&&v!=3)return false;if(v==3&&!sxdn_read(c,0,h,119))return false;if(!sxdn_put(c,v==2?DN_PAIR(sqlz_squashfs2_superblock,be):DN_PAIR(sqlz_squashfs3_superblock,be),0,1))return false;uint64_t size,inode,dir,frag,lookup=UINT64_MAX,uid,gid;if(v==2){size=sxdn32(h+8,be);uid=sxdn32(h+12,be);gid=sxdn32(h+16,be);inode=sxdn32(h+20,be);dir=sxdn32(h+24,be);frag=sxdn32(h+59,be);}else{size=xx_data_get_u64(h,119,63,be);uid=xx_data_get_u64(h,119,71,be);gid=xx_data_get_u64(h,119,79,be);inode=xx_data_get_u64(h,119,87,be);dir=xx_data_get_u64(h,119,95,be);frag=xx_data_get_u64(h,119,103,be);lookup=xx_data_get_u64(h,119,111,be);}if(size<header||size>(uint64_t)c->size)size=(uint64_t)c->size;unsigned budget=4096;uint64_t fragments=sxdn32(h+55,be),ninode=sxdn32(h+4,be);if(!sxdn_sqlz_index(c,frag,(fragments*(v==2?8:16)+8191)/8192,v==2?4:8,header,be,&budget))return false;if(v==3&&!sxdn_sqlz_index(c,lookup,(ninode*8+8191)/8192,8,header,be,&budget))return false;uint64_t starts[]={uid,gid};for(unsigned i=0;i<2;i++)if(h[37+i]&&starts[i]>=header&&sxdn_span(c,starts[i],(uint64_t)h[37+i]*4)&&!sxdn_put(c,DN_PAIR(sqlz_squashfs_identity,be),starts[i],h[37+i]))return false;if(inode>=header&&inode<dir&&dir<=size&&!sxdn_sqlz_meta(c,inode,dir,be,&budget))return false;if(dir>=header&&dir<size){uint64_t end=size,refs[]={frag,lookup,uid,gid};for(unsigned i=0;i<4;i++)if(refs[i]>dir&&refs[i]<end)end=refs[i];if(!sxdn_sqlz_meta(c,dir,end,be,&budget))return false;}return true;}
bool sx_squashfs_sqlz_build(sx_context*c)
{
 return sxdn_sqlz(c);
}
#undef DN_PAIR
