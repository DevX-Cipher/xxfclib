/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ROMFS data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_romfs_superblock_fields[] = {
    SX_FIELD("signature", "byte[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("full_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("checksum", "uint32", 12, 4, SX_CHECKSUM),
};
const sx_layout sx_st_romfs_superblock = {0x60080059U, "romfs_superblock", sx_st_romfs_superblock_fields, SX_COUNT(sx_st_romfs_superblock_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_romfs_inode_fields[] = {
    SX_FIELD("next_offset_and_type", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("spec_info", "uint32", 4, 4, SX_NONE),
    SX_FIELD("size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("checksum", "uint32", 12, 4, SX_CHECKSUM),
};
const sx_layout sx_st_romfs_inode = {0x6008005AU, "romfs_inode", sx_st_romfs_inode_fields, SX_COUNT(sx_st_romfs_inode_fields), SX_BE};
static bool sx_st_romfs_chain(sx_context *c,uint64_t at,unsigned depth)
{
    if(depth>=64)return true;
    while(at&&sx_st_free(c,at,16)) {
        uint8_t h[16];uint32_t next,spec;
        if(!sx_read(c,(int64_t)at,h,16)||!sx_add(c,&sx_st_romfs_inode,(int64_t)at,16))return false;
        next=xx_data_get_u32(h,16,0,true);spec=xx_data_get_u32(h,16,4,true);
        if((next&7)==1&&spec&&!sx_st_romfs_chain(c,spec,depth+1))return false;
        /* Hardlink destinations contain the same inode header; follow them too
         * because a valid hardlink may target a header outside directory chains. */
        if(!(next&7)&&spec&&!sx_st_romfs_chain(c,spec,depth+1))return false;
        at=next&~UINT32_C(15);
    }
    return true;
}
static bool sx_st_romfs(sx_context *c)
{
    uint64_t at=16;uint8_t ch=1;unsigned count=0;
    if(!sx_add(c,&sx_st_romfs_superblock,0,16))return false;
    while(ch&&at<(uint64_t)c->size&&count++<4096)if(!sx_read(c,(int64_t)at++,&ch,1))return false;
    if(ch)return false;at=(at+15)&~UINT64_C(15);
    return sx_st_romfs_chain(c,at,0);
}
bool sx_romfs_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_romfs(c);
    return ok&&sx_st_finish(c);
}
