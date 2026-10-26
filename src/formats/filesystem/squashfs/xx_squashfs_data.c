/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SquashFS data structures, moved out of the unixfs schema family. */
#include "../../xx_format_schema_unixfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxuf_squashfs1_superblock_le_fields[] = {
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
};
const sx_layout sxuf_squashfs1_superblock_le = {UINT32_C(0x60110011),"squashfs1_superblock_le",sxuf_squashfs1_superblock_le_fields,SX_COUNT(sxuf_squashfs1_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs1_superblock_be_fields[] = {
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
};
const sx_layout sxuf_squashfs1_superblock_be = {UINT32_C(0x60110012),"squashfs1_superblock_be",sxuf_squashfs1_superblock_be_fields,SX_COUNT(sxuf_squashfs1_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs2_superblock_le_fields[] = {
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
const sx_layout sxuf_squashfs2_superblock_le = {UINT32_C(0x60110013),"squashfs2_superblock_le",sxuf_squashfs2_superblock_le_fields,SX_COUNT(sxuf_squashfs2_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs2_superblock_be_fields[] = {
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
const sx_layout sxuf_squashfs2_superblock_be = {UINT32_C(0x60110014),"squashfs2_superblock_be",sxuf_squashfs2_superblock_be_fields,SX_COUNT(sxuf_squashfs2_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs3_superblock_le_fields[] = {
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
const sx_layout sxuf_squashfs3_superblock_le = {UINT32_C(0x60110015),"squashfs3_superblock_le",sxuf_squashfs3_superblock_le_fields,SX_COUNT(sxuf_squashfs3_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs3_superblock_be_fields[] = {
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
const sx_layout sxuf_squashfs3_superblock_be = {UINT32_C(0x60110016),"squashfs3_superblock_be",sxuf_squashfs3_superblock_be_fields,SX_COUNT(sxuf_squashfs3_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs4_superblock_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("creation_time","uint32",8,4,SX_TIME),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("compression","uint16",20,2,SX_ID),
    SX_FIELD("block_log","uint16",22,2,SX_NONE),
    SX_FIELD("flags","uint16",24,2,SX_FLAGS),
    SX_FIELD("id_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("root_inode_reference","uint64",32,8,SX_FLAGS),
    SX_FIELD("bytes_used","uint64",40,8,SX_SIZE),
    SX_FIELD("id_index_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("xattr_index_offset","uint64",56,8,SX_OFFSET),
    SX_FIELD("inode_table_offset","uint64",64,8,SX_OFFSET),
    SX_FIELD("directory_table_offset","uint64",72,8,SX_OFFSET),
    SX_FIELD("fragment_index_offset","uint64",80,8,SX_OFFSET),
    SX_FIELD("lookup_index_offset","uint64",88,8,SX_OFFSET),
};
const sx_layout sxuf_squashfs4_superblock_le = {UINT32_C(0x60110017),"squashfs4_superblock_le",sxuf_squashfs4_superblock_le_fields,SX_COUNT(sxuf_squashfs4_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs4_superblock_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("creation_time","uint32",8,4,SX_TIME),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("compression","uint16",20,2,SX_ID),
    SX_FIELD("block_log","uint16",22,2,SX_NONE),
    SX_FIELD("flags","uint16",24,2,SX_FLAGS),
    SX_FIELD("id_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("root_inode_reference","uint64",32,8,SX_FLAGS),
    SX_FIELD("bytes_used","uint64",40,8,SX_SIZE),
    SX_FIELD("id_index_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("xattr_index_offset","uint64",56,8,SX_OFFSET),
    SX_FIELD("inode_table_offset","uint64",64,8,SX_OFFSET),
    SX_FIELD("directory_table_offset","uint64",72,8,SX_OFFSET),
    SX_FIELD("fragment_index_offset","uint64",80,8,SX_OFFSET),
    SX_FIELD("lookup_index_offset","uint64",88,8,SX_OFFSET),
};
const sx_layout sxuf_squashfs4_superblock_be = {UINT32_C(0x60110018),"squashfs4_superblock_be",sxuf_squashfs4_superblock_be_fields,SX_COUNT(sxuf_squashfs4_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs_metadata_header_le_fields[] = {
    SX_FIELD("size_and_stored_flag","uint16",0,2,SX_FLAGS),
};
const sx_layout sxuf_squashfs_metadata_header_le = {UINT32_C(0x60110019),"squashfs_metadata_header_le",sxuf_squashfs_metadata_header_le_fields,SX_COUNT(sxuf_squashfs_metadata_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs_table_index_le_fields[] = {
    SX_FIELD("metadata_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxuf_squashfs_table_index_le = {UINT32_C(0x6011001a),"squashfs_table_index_le",sxuf_squashfs_table_index_le_fields,SX_COUNT(sxuf_squashfs_table_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs2_fragment_index_le_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxuf_squashfs2_fragment_index_le = {UINT32_C(0x6011001b),"squashfs2_fragment_index_le",sxuf_squashfs2_fragment_index_le_fields,SX_COUNT(sxuf_squashfs2_fragment_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs_identity_le_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
};
const sx_layout sxuf_squashfs_identity_le = {UINT32_C(0x6011001c),"squashfs_identity_le",sxuf_squashfs_identity_le_fields,SX_COUNT(sxuf_squashfs_identity_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs_xattr_table_le_fields[] = {
    SX_FIELD("xattr_table_offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("xattr_id_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sxuf_squashfs_xattr_table_le = {UINT32_C(0x6011001d),"squashfs_xattr_table_le",sxuf_squashfs_xattr_table_le_fields,SX_COUNT(sxuf_squashfs_xattr_table_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs_metadata_header_be_fields[] = {
    SX_FIELD("size_and_stored_flag","uint16",0,2,SX_FLAGS),
};
const sx_layout sxuf_squashfs_metadata_header_be = {UINT32_C(0x6011001e),"squashfs_metadata_header_be",sxuf_squashfs_metadata_header_be_fields,SX_COUNT(sxuf_squashfs_metadata_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs_table_index_be_fields[] = {
    SX_FIELD("metadata_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxuf_squashfs_table_index_be = {UINT32_C(0x6011001f),"squashfs_table_index_be",sxuf_squashfs_table_index_be_fields,SX_COUNT(sxuf_squashfs_table_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs2_fragment_index_be_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxuf_squashfs2_fragment_index_be = {UINT32_C(0x60110020),"squashfs2_fragment_index_be",sxuf_squashfs2_fragment_index_be_fields,SX_COUNT(sxuf_squashfs2_fragment_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs_identity_be_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
};
const sx_layout sxuf_squashfs_identity_be = {UINT32_C(0x60110021),"squashfs_identity_be",sxuf_squashfs_identity_be_fields,SX_COUNT(sxuf_squashfs_identity_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs_xattr_table_be_fields[] = {
    SX_FIELD("xattr_table_offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("xattr_id_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sxuf_squashfs_xattr_table_be = {UINT32_C(0x60110022),"squashfs_xattr_table_be",sxuf_squashfs_xattr_table_be_fields,SX_COUNT(sxuf_squashfs_xattr_table_be_fields),SX_BE};
/* Physical metadata only. No filesystem mount, decompression, journal replay,
 * reader factory or synthesized decoded-offset mapping is used. */
#define UF_PAIR(n,be) ((be)?&sxuf_##n##_be:&sxuf_##n##_le)
static uint64_t sxuf_64(const uint8_t *p,bool be){return xx_data_get_u64(p,8,0,be);}
/* Metadata payload may be compressed. Only its physical2-byte header is
 * structured; decoded inode/directory bytes never acquire fake file offsets. */
static bool sxuf_meta(sx_context *c,uint64_t at,uint64_t limit,bool be,unsigned *budget)
{
    while(*budget&&at<limit){uint8_t b[2];if(limit-at<2||!sxuf_read(c,at,b,2))break;uint16_t v=sxuf_16(b,be);uint32_t n=v&32767;if(!n||n>8192||n>limit-at-2)break;
        bool duplicate=false,overlap=false;for(size_t i=0;i<c->count;i++){uint64_t p=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p==at&&z==2&&c->items[i].id==UF_PAIR(squashfs_metadata_header,be)->id){duplicate=true;break;}if(at<p+z&&p<at+2+n){overlap=true;break;}}
        if(overlap)break;if(!duplicate&&(!sx_add(c,UF_PAIR(squashfs_metadata_header,be),(int64_t)at,2)||!sx_raw(c,(int64_t)at+2,n)))return false;(*budget)--;at+=2+n;
    }return true;
}
static bool sxuf_sq_index(sx_context *c,uint64_t at,uint64_t count,unsigned width,unsigned header,bool be,unsigned *budget)
{
    if(!count||count>4096||at==UINT64_MAX||!sxuf_span(c,at,count*width))return true;
    for(size_t i=0;i<c->count;i++){uint64_t p=(uint64_t)(c->items[i].offset-c->f->base_address);if(at<p+(uint64_t)c->items[i].total_size&&p<at+count*width)return true;}
    if(!sx_table(c,width==4?UF_PAIR(squashfs2_fragment_index,be):UF_PAIR(squashfs_table_index,be),(int64_t)at,width,count))return false;
    for(uint64_t i=0;i<count&&*budget;i++){uint8_t b[8];if(!sxuf_read(c,at+i*width,b,width))return false;uint64_t p=width==4?sxuf_32(b,be):sxuf_64(b,be);if(p>=header&&p<at&&!sxuf_meta(c,p,at,be,budget))return false;}return true;
}
static bool sxuf_squash(sx_context *c)
{
    uint8_t h[128];if(!sxuf_read(c,0,h,sizeof(h)))return false;uint32_t m=sxuf_32(h,false);bool be=m==0x68737173||m==0x68737174;
    if(!be&&m!=0x73717368&&m!=0x74717368&&m!=0x71736873&&m!=0x68191122)return false;
    unsigned v=sxuf_16(h+28,be);const sx_layout *l;uint64_t size,inodes,dirs,frag,lookup,uid,gid;uint32_t fragments,ninode,nu,ng;unsigned header;
    if(v==1){l=UF_PAIR(squashfs1_superblock,be);header=51;}else if(v==2){l=UF_PAIR(squashfs2_superblock,be);header=63;}else if(v==3){l=UF_PAIR(squashfs3_superblock,be);header=119;}else if(v==4){l=UF_PAIR(squashfs4_superblock,be);header=96;}else return false;
    if(!sx_add(c,l,0,header))return false;ninode=sxuf_32(h+4,be);lookup=UINT64_MAX;gid=UINT64_MAX;ng=0;
    if(v==4){size=sxuf_64(h+40,be);inodes=sxuf_64(h+64,be);dirs=sxuf_64(h+72,be);frag=sxuf_64(h+80,be);lookup=sxuf_64(h+88,be);uid=sxuf_64(h+48,be);nu=sxuf_16(h+26,be);fragments=sxuf_32(h+16,be);}
    else if(v==3){size=sxuf_64(h+63,be);inodes=sxuf_64(h+87,be);dirs=sxuf_64(h+95,be);frag=sxuf_64(h+103,be);lookup=sxuf_64(h+111,be);uid=sxuf_64(h+71,be);gid=sxuf_64(h+79,be);nu=h[37];ng=h[38];fragments=sxuf_32(h+55,be);}
    else {size=sxuf_32(h+8,be);inodes=sxuf_32(h+20,be);dirs=sxuf_32(h+24,be);frag=v==2?sxuf_32(h+59,be):UINT64_MAX;uid=sxuf_32(h+12,be);gid=sxuf_32(h+16,be);nu=h[37];ng=h[38];fragments=v==2?sxuf_32(h+55,be):0;}
    if(size<header||size>(uint64_t)c->size)size=(uint64_t)c->size;unsigned budget=4096;
    /* Indexed metadata and plain identity tables are processed first so a
     * linear metadata scan cannot mistake their bytes for framing. */
    if(!sxuf_sq_index(c,frag,((uint64_t)fragments*(v==2?8:16)+8191)/8192,v==2?4:8,header,be,&budget))return false;
    if(v>=3&&!sxuf_sq_index(c,lookup,((uint64_t)ninode*8+8191)/8192,8,header,be,&budget))return false;
    if(v==4){if(!sxuf_sq_index(c,uid,((uint64_t)nu*4+8191)/8192,8,header,be,&budget))return false;uint64_t x=sxuf_64(h+56,be);if(x>=header&&sxuf_span(c,x,16)){
        bool overlap=false;for(size_t i=0;i<c->count;i++){uint64_t p=(uint64_t)(c->items[i].offset-c->f->base_address);if(x<p+(uint64_t)c->items[i].total_size&&p<x+16)overlap=true;}
        if(!overlap&&!sx_add(c,UF_PAIR(squashfs_xattr_table,be),(int64_t)x,16))return false;
    }}else{
        uint64_t starts[2]={uid,gid};uint32_t counts[2]={nu,ng};for(unsigned k=0;k<2;k++)if(counts[k]&&starts[k]>=header&&sxuf_span(c,starts[k],(uint64_t)counts[k]*4)){
            bool overlap=false;for(size_t i=0;i<c->count;i++){uint64_t p=(uint64_t)(c->items[i].offset-c->f->base_address);if(starts[k]<p+(uint64_t)c->items[i].total_size&&p<starts[k]+(uint64_t)counts[k]*4)overlap=true;}
            if(!overlap&&!sx_table(c,UF_PAIR(squashfs_identity,be),(int64_t)starts[k],4,counts[k]))return false;
        }
    }
    if(inodes>=header&&inodes<dirs&&dirs<=size&&!sxuf_meta(c,inodes,dirs,be,&budget))return false;
    if(dirs>=header&&dirs<size){uint64_t limit=size,refs[4]={frag,lookup,uid,gid};for(unsigned i=0;i<4;i++)if(refs[i]>dirs&&refs[i]<limit)limit=refs[i];if(!sxuf_meta(c,dirs,limit,be,&budget))return false;}
    return true;
}
#undef UF_PAIR
bool sx_squashfs_build(sx_context*c)
{
return sxuf_squash(c)&&sxuf_finish(c);
}
