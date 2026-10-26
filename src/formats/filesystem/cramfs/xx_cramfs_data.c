/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CRAMFS data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_cramfs_superblock_le_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("future", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("signature", "byte[16]", 16, 16, SX_SIGNATURE),
    SX_FIELD("crc32", "uint32", 32, 4, SX_CHECKSUM),
    SX_FIELD("edition", "uint32", 36, 4, SX_NONE),
    SX_FIELD("block_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("file_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("name", "char[16]", 48, 16, SX_STRING),
};
const sx_layout sx_st_cramfs_superblock_le = {0x6008005BU, "cramfs_superblock_le", sx_st_cramfs_superblock_le_fields, SX_COUNT(sx_st_cramfs_superblock_le_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_cramfs_inode_le_fields[] = {
    SX_FIELD("mode_uid", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("size_gid", "uint32", 4, 4, SX_NONE),
    SX_FIELD("name_length_and_offset", "uint32", 8, 4, SX_OFFSET),
};
const sx_layout sx_st_cramfs_inode_le = {0x6008005CU, "cramfs_inode_le", sx_st_cramfs_inode_le_fields, SX_COUNT(sx_st_cramfs_inode_le_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_cramfs_block_pointer_le_fields[] = {
    SX_FIELD("end_offset_and_flags", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sx_st_cramfs_block_pointer_le = {0x6008005DU, "cramfs_block_pointer_le", sx_st_cramfs_block_pointer_le_fields, SX_COUNT(sx_st_cramfs_block_pointer_le_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_cramfs_superblock_be_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("future", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("signature", "byte[16]", 16, 16, SX_SIGNATURE),
    SX_FIELD("crc32", "uint32", 32, 4, SX_CHECKSUM),
    SX_FIELD("edition", "uint32", 36, 4, SX_NONE),
    SX_FIELD("block_count", "uint32", 40, 4, SX_COUNT_PROP),
    SX_FIELD("file_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("name", "char[16]", 48, 16, SX_STRING),
};
const sx_layout sx_st_cramfs_superblock_be = {0x6008005EU, "cramfs_superblock_be", sx_st_cramfs_superblock_be_fields, SX_COUNT(sx_st_cramfs_superblock_be_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_cramfs_block_pointer_be_fields[] = {
    SX_FIELD("end_offset_and_flags", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sx_st_cramfs_block_pointer_be = {0x60080060U, "cramfs_block_pointer_be", sx_st_cramfs_block_pointer_be_fields, SX_COUNT(sx_st_cramfs_block_pointer_be_fields), SX_BE};
static bool sx_st_cramfs_inode_walk(sx_context *c,uint64_t at,bool be,unsigned depth,bool root)
{
    uint8_t h[12];uint32_t w0,w1,w2,mode,size,off;
    if(depth>=64||!sx_st_free(c,at,12))return true;
    if(!sx_read(c,(int64_t)at,h,12)||!sx_add(c,be?&sx_st_cramfs_inode_be:&sx_st_cramfs_inode_le,(int64_t)at,12))return false;
    w0=xx_data_get_u32(h,12,0,be);w1=xx_data_get_u32(h,12,4,be);w2=xx_data_get_u32(h,12,8,be);
    mode=be?w0>>16:w0&65535;size=be?w1>>8:w1&0xffffff;off=(be?w2&0x3ffffff:w2>>6)*4;
    if((mode&0xf000)==0x4000&&off&&sx_st_fits(c,off,size)) {
        uint64_t p=off,end=p+size;
        while(end-p>=12&&c->count<20000) {
            uint32_t word;unsigned name;
            if(!sx_u32(c,(int64_t)p+8,be,&word))return false;name=(be?word>>26:word&63)*4;
            if((uint64_t)name+12>end-p)break;
            if(!sx_st_cramfs_inode_walk(c,p,be,depth+1,false))return false;p+=12+name;
        }
    } else if((mode&0xf000)==0x8000&&off&&size) {
        uint64_t count=((uint64_t)size+4095)/4096;
        if(sx_st_free(c,off,count*4)&&!sx_table(c,be?&sx_st_cramfs_block_pointer_be:&sx_st_cramfs_block_pointer_le,off,4,count))return false;
    }
    (void)root;return true;
}
bool sx_cramfs_build(sx_context*c)
{
    bool ok=false;
    uint32_t magic;ok=sx_u32(c,0,false,&magic);if(ok){bool be=magic!=0x28cd3d45U;ok=sx_add(c,be?&sx_st_cramfs_superblock_be:&sx_st_cramfs_superblock_le,0,64)&&sx_st_cramfs_inode_walk(c,64,be,0,true);}
    return ok&&sx_st_finish(c);
}
