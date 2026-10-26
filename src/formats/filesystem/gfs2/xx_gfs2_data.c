/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GFS2 data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_gfs2_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("metadata_type","uint32",4,4,SX_ID),
    SX_FIELD("reserved_generation","uint64",8,8,SX_RESERVED),
    SX_FIELD("metadata_format","uint32",16,4,SX_ID),
    SX_FIELD("journal_id","uint32",20,4,SX_ID),
    SX_FIELD("filesystem_format","uint32",24,4,SX_ID),
    SX_FIELD("multihost_format","uint32",28,4,SX_ID),
    SX_FIELD("reserved0","uint32",32,4,SX_RESERVED),
    SX_FIELD("block_size","uint32",36,4,SX_SIZE),
    SX_FIELD("log2_block_size","uint32",40,4,SX_NONE),
    SX_FIELD("reserved1","uint32",44,4,SX_RESERVED),
    SX_FIELD("master_inode","uint64",48,8,SX_ID),
    SX_FIELD("master_block","uint64",56,8,SX_NONE),
    SX_FIELD("reserved2","byte[16]",64,16,SX_RESERVED),
    SX_FIELD("root_inode","uint64",80,8,SX_ID),
    SX_FIELD("root_block","uint64",88,8,SX_NONE),
    SX_FIELD("lock_protocol","char[64]",96,64,SX_STRING),
    SX_FIELD("lock_table","char[64]",160,64,SX_STRING),
    SX_FIELD("reserved3","byte[32]",224,32,SX_RESERVED),
    SX_FIELD("uuid","byte[16]",256,16,SX_ID),
};
const sx_layout sxmf_gfs2_superblock = {0x60420028U,"gfs2_superblock",sxmf_gfs2_superblock_fields,SX_COUNT(sxmf_gfs2_superblock_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_gfs2_inode_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("metadata_type","uint32",4,4,SX_ID),
    SX_FIELD("reserved_generation","uint64",8,8,SX_RESERVED),
    SX_FIELD("metadata_format","uint32",16,4,SX_ID),
    SX_FIELD("journal_id","uint32",20,4,SX_ID),
    SX_FIELD("inode","uint64",24,8,SX_ID),
    SX_FIELD("self_block","uint64",32,8,SX_NONE),
    SX_FIELD("mode","uint32",40,4,SX_FLAGS),
    SX_FIELD("uid","uint32",44,4,SX_ID),
    SX_FIELD("gid","uint32",48,4,SX_ID),
    SX_FIELD("link_count","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("file_size","uint64",56,8,SX_SIZE),
    SX_FIELD("allocated_blocks","uint64",64,8,SX_COUNT_PROP),
    SX_FIELD("access_time","uint64",72,8,SX_TIME),
    SX_FIELD("modification_time","uint64",80,8,SX_TIME),
    SX_FIELD("change_time","uint64",88,8,SX_TIME),
    SX_FIELD("device_major","uint32",96,4,SX_ID),
    SX_FIELD("device_minor","uint32",100,4,SX_ID),
    SX_FIELD("allocation_goal_meta","uint64",104,8,SX_NONE),
    SX_FIELD("allocation_goal_data","uint64",112,8,SX_NONE),
    SX_FIELD("generation","uint64",120,8,SX_NONE),
    SX_FIELD("flags","uint32",128,4,SX_FLAGS),
    SX_FIELD("payload_format","uint32",132,4,SX_ID),
    SX_FIELD("reserved1","uint16",136,2,SX_RESERVED),
    SX_FIELD("tree_height","uint16",138,2,SX_COUNT_PROP),
    SX_FIELD("reserved2","uint32",140,4,SX_RESERVED),
    SX_FIELD("reserved3","uint16",144,2,SX_RESERVED),
    SX_FIELD("hash_depth","uint16",146,2,SX_NONE),
    SX_FIELD("directory_entries","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("reserved4","byte[16]",152,16,SX_RESERVED),
    SX_FIELD("xattr_block","uint64",168,8,SX_NONE),
    SX_FIELD("access_nanoseconds","uint32",176,4,SX_NONE),
    SX_FIELD("modification_nanoseconds","uint32",180,4,SX_NONE),
    SX_FIELD("change_nanoseconds","uint32",184,4,SX_NONE),
    SX_FIELD("reserved5","byte[44]",188,44,SX_RESERVED),
};
const sx_layout sxmf_gfs2_inode = {0x60420029U,"gfs2_inode",sxmf_gfs2_inode_fields,SX_COUNT(sxmf_gfs2_inode_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_gfs2_directory_entry_fields[] = {
    SX_FIELD("inode","uint64",0,8,SX_ID),
    SX_FIELD("block","uint64",8,8,SX_NONE),
    SX_FIELD("hash","uint32",16,4,SX_ID),
    SX_FIELD("record_length","uint16",20,2,SX_SIZE),
    SX_FIELD("name_length","uint16",22,2,SX_SIZE),
    SX_FIELD("type","uint16",24,2,SX_ID),
    SX_FIELD("read_ahead_blocks","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[12]",28,12,SX_RESERVED),
};
const sx_layout sxmf_gfs2_directory_entry = {0x6042002aU,"gfs2_directory_entry",sxmf_gfs2_directory_entry_fields,SX_COUNT(sxmf_gfs2_directory_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_gfs2_leaf_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("metadata_type","uint32",4,4,SX_ID),
    SX_FIELD("reserved_generation","uint64",8,8,SX_RESERVED),
    SX_FIELD("metadata_format","uint32",16,4,SX_ID),
    SX_FIELD("journal_id","uint32",20,4,SX_ID),
    SX_FIELD("depth","uint16",24,2,SX_NONE),
    SX_FIELD("entries","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("format","uint32",28,4,SX_ID),
    SX_FIELD("next_leaf_block","uint64",32,8,SX_NONE),
    SX_FIELD("reserved","byte[64]",40,64,SX_RESERVED),
};
const sx_layout sxmf_gfs2_leaf = {0x6042002bU,"gfs2_leaf",sxmf_gfs2_leaf_fields,SX_COUNT(sxmf_gfs2_leaf_fields),SX_BE};
#define SXMF_LIMIT 24000U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
static bool sxmf_gfs2_dir(sx_context*c,sxmf_queue*q,uint8_t*b,uint64_t p,uint64_t start,uint64_t end,unsigned depth){for(uint64_t at=start;at+40<=end;){uint64_t z=sxmf16(b+at+20,1),n=sxmf16(b+at+22,1);if(z<40||z>end-at||n>z-40||(z&7))break;if(!SXMF_ADD(c,gfs2_directory_entry,p+at))return false;uint64_t child=sxmf64(b+at+8,1);if(n&&child)sxmf_queue_add(q,child,0,depth+1);at+=z;}return true;}
static bool sxmf_gfs2(sx_context*c){uint8_t h[272];if(!sxmf_read(c,65536,h,272)||sxmf32(h,1)!=0x01161970U||sxmf32(h+4,1)!=1||!SXMF_ADD(c,gfs2_superblock,65536))return false;uint64_t bs=sxmf32(h+36,1);if(!sxmf_pow(bs)||bs<512||bs>65536)return true;uint8_t*b=xx_rt_malloc((size_t)bs);sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!b||!q){xx_rt_free(b);xx_rt_free(q);return false;}bool ok=true;sxmf_queue_add(q,sxmf64(h+56,1),0,0);sxmf_queue_add(q,sxmf64(h+88,1),0,0);
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT&&!xx_pd_is_stopped(c->pd)){sxmf_task t=q->items[q->index++];if(t.p>=(uint64_t)c->size/bs)continue;uint64_t p=t.p*bs;if(!sxmf_read(c,p,b,(size_t)bs)||sxmf32(b,1)!=0x01161970U)continue;unsigned type=sxmf32(b+4,1);
  if(t.kind==0){if(type!=4||sxmf64(b+32,1)!=t.p)continue;if(!SXMF_ADD(c,gfs2_inode,p)){ok=false;break;}uint64_t size=sxmf64(b+56,1);unsigned mode=sxmf32(b+40,1),height=sxmf16(b+138,1);if((mode&0170000)!=0040000||height)continue;
   if(!(sxmf32(b+128,1)&2)){uint64_t end=size<bs-232?232+size:bs;ok=sxmf_gfs2_dir(c,q,b,p,232,end,t.depth);}else if(size<=bs-232&&!(size&7)){for(uint64_t j=0;j<size;j+=8)sxmf_queue_add(q,sxmf64(b+232+j,1),1,t.depth+1);}
  }else{if(type!=6)continue;if(!SXMF_ADD(c,gfs2_leaf,p)){ok=false;break;}sxmf_queue_add(q,sxmf64(b+32,1),1,t.depth);ok=sxmf_gfs2_dir(c,q,b,p,104,bs,t.depth);}
 }
 xx_rt_free(b);xx_rt_free(q);return ok;
}
bool sx_gfs2_build(sx_context*c)
{
 return sxmf_gfs2(c);
}
#undef SXMF_LIMIT
#undef SXMF_ADD
