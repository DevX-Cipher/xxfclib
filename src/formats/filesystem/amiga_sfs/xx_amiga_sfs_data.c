/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMIGA SFS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_sfs_root_block_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("self_block","uint32",8,4,SX_NONE),
    SX_FIELD("version","uint16",12,2,SX_ID),
    SX_FIELD("sequence","uint16",14,2,SX_NONE),
    SX_FIELD("creation_time","uint32",16,4,SX_TIME),
    SX_FIELD("flags","uint8",20,1,SX_FLAGS),
    SX_FIELD("padding1","uint8",21,1,SX_RESERVED),
    SX_FIELD("padding2","uint16",22,2,SX_RESERVED),
    SX_FIELD("reserved1","uint32[2]",24,8,SX_RESERVED),
    SX_FIELD("first_byte","uint64",32,8,SX_OFFSET),
    SX_FIELD("last_byte","uint64",40,8,SX_OFFSET),
    SX_FIELD("total_blocks","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",52,4,SX_SIZE),
    SX_FIELD("reserved2","uint32[10]",56,40,SX_RESERVED),
    SX_FIELD("bitmap_block","uint32",96,4,SX_NONE),
    SX_FIELD("admin_space_block","uint32",100,4,SX_NONE),
    SX_FIELD("root_object_block","uint32",104,4,SX_NONE),
    SX_FIELD("extent_tree_block","uint32",108,4,SX_NONE),
    SX_FIELD("object_tree_block","uint32",112,4,SX_NONE),
    SX_FIELD("reserved3","uint32[3]",116,12,SX_RESERVED),
};
const sx_layout sxmf_sfs_root_block = {0x60420016U,"sfs_root_block",sxmf_sfs_root_block_fields,SX_COUNT(sxmf_sfs_root_block_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_sfs_object_container_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("self_block","uint32",8,4,SX_NONE),
    SX_FIELD("parent_object","uint32",12,4,SX_ID),
    SX_FIELD("next_block","uint32",16,4,SX_NONE),
    SX_FIELD("previous_block","uint32",20,4,SX_NONE),
};
const sx_layout sxmf_sfs_object_container = {0x60420017U,"sfs_object_container",sxmf_sfs_object_container_fields,SX_COUNT(sxmf_sfs_object_container_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_sfs_btree_header_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("self_block","uint32",8,4,SX_NONE),
    SX_FIELD("node_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("leaf","uint8",14,1,SX_ID),
    SX_FIELD("node_size","uint8",15,1,SX_SIZE),
};
const sx_layout sxmf_sfs_btree_header = {0x60420018U,"sfs_btree_header",sxmf_sfs_btree_header_fields,SX_COUNT(sxmf_sfs_btree_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_sfs_extent16_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
    SX_FIELD("next_block","uint32",4,4,SX_NONE),
    SX_FIELD("previous_block_or_object","uint32",8,4,SX_NONE),
    SX_FIELD("block_count","uint16",12,2,SX_COUNT_PROP),
};
const sx_layout sxmf_sfs_extent16 = {0x60420019U,"sfs_extent16",sxmf_sfs_extent16_fields,SX_COUNT(sxmf_sfs_extent16_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_sfs_extent32_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
    SX_FIELD("next_block","uint32",4,4,SX_NONE),
    SX_FIELD("previous_block_or_object","uint32",8,4,SX_NONE),
    SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxmf_sfs_extent32 = {0x6042001aU,"sfs_extent32",sxmf_sfs_extent32_fields,SX_COUNT(sxmf_sfs_extent32_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_sfs_btree_index_fields[] = {
    SX_FIELD("key","uint32",0,4,SX_NONE),
    SX_FIELD("child_block","uint32",4,4,SX_NONE),
};
const sx_layout sxmf_sfs_btree_index = {0x6042001bU,"sfs_btree_index",sxmf_sfs_btree_index_fields,SX_COUNT(sxmf_sfs_btree_index_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_sfs_file_object_fields[] = {
    SX_FIELD("owner_uid","uint16",0,2,SX_ID),
    SX_FIELD("owner_gid","uint16",2,2,SX_ID),
    SX_FIELD("object_node","uint32",4,4,SX_ID),
    SX_FIELD("protection","uint32",8,4,SX_FLAGS),
    SX_FIELD("data_block","uint32",12,4,SX_NONE),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("modification_time","uint32",20,4,SX_TIME),
    SX_FIELD("type","uint8",24,1,SX_FLAGS),
};
const sx_layout sxmf_sfs_file_object = {0x6042008aU,"sfs_file_object",sxmf_sfs_file_object_fields,SX_COUNT(sxmf_sfs_file_object_fields),SX_BE};
static const xx_data_struct_field_desc sxmf_sfs_directory_object_fields[] = {
    SX_FIELD("owner_uid","uint16",0,2,SX_ID),
    SX_FIELD("owner_gid","uint16",2,2,SX_ID),
    SX_FIELD("object_node","uint32",4,4,SX_ID),
    SX_FIELD("protection","uint32",8,4,SX_FLAGS),
    SX_FIELD("hash_table_block","uint32",12,4,SX_NONE),
    SX_FIELD("first_directory_block","uint32",16,4,SX_NONE),
    SX_FIELD("modification_time","uint32",20,4,SX_TIME),
    SX_FIELD("type","uint8",24,1,SX_FLAGS),
};
const sx_layout sxmf_sfs_directory_object = {0x6042008bU,"sfs_directory_object",sxmf_sfs_directory_object_fields,SX_COUNT(sxmf_sfs_directory_object_fields),SX_BE};
#define SXMF_LIMIT 24000U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
static bool sxmf_sfs(sx_context*c){uint8_t h[128];if(!sxmf_read(c,0,h,128))return false;uint32_t magic=sxmf32(h,1);if((magic!=0x53465300U&&magic!=0x53465302U)||!SXMF_ADD(c,sfs_root_block,0))return false;uint64_t bs=sxmf32(h+52,1),blocks=sxmf32(h+48,1);if(bs<512||bs>65536||!sxmf_pow(bs)||!blocks||blocks>(uint64_t)c->size/bs)return true;
 uint8_t*b=xx_rt_malloc((size_t)bs);sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!b||!q){xx_rt_free(b);xx_rt_free(q);return false;}bool ok=true;
 if(sxmf_read(c,(blocks-1)*bs,b,128)&&sxmf32(b,1)==magic&&!SXMF_ADD(c,sfs_root_block,(blocks-1)*bs))ok=false;
 sxmf_queue_add(q,(uint64_t)sxmf32(h+104,1)*bs,0,0);sxmf_queue_add(q,(uint64_t)sxmf32(h+108,1)*bs,1,0);
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT&&!xx_pd_is_stopped(c->pd)){sxmf_task t=q->items[q->index++];if(t.p/bs>=blocks||!sxmf_read(c,t.p,b,(size_t)bs))continue;
  if(t.kind==0){if(sxmf32(b,1)!=0x4f424a43U||sxmf32(b+8,1)!=t.p/bs)continue;if(!SXMF_ADD(c,sfs_object_container,t.p)){ok=false;break;}sxmf_queue_add(q,(uint64_t)sxmf32(b+16,1)*bs,0,t.depth);
   /* SFS2 has a distinct 27-byte object prefix not interpreted here. */
   if(magic!=0x53465300U)continue;for(uint64_t p=24;p+25<=bs;){if(!sxmf32(b+p+4,1))break;bool dir=(b[p+24]&128)!=0;uint64_t end=p+25;unsigned strings=0;while(end<bs&&strings<2){if(!b[end])strings++;end++;}if(strings!=2)break;if(!sxmf_put(c,dir?&sxmf_sfs_directory_object:&sxmf_sfs_file_object,t.p+p,1)){ok=false;break;}if(dir)sxmf_queue_add(q,(uint64_t)sxmf32(b+p+16,1)*bs,0,t.depth+1);p=(end+1)&~UINT64_C(1);}
  }else{if(sxmf32(b,1)!=0x424e4443U||sxmf32(b+8,1)!=t.p/bs)continue;unsigned n=sxmf16(b+12,1),leaf=b[14],stride=b[15];if(!stride||n>(bs-16)/stride)continue;if(!SXMF_ADD(c,sfs_btree_header,t.p)){ok=false;break;}if(leaf&&stride==(magic==0x53465300U?14:16)){ok=sxmf_put(c,magic==0x53465300U?&sxmf_sfs_extent16:&sxmf_sfs_extent32,t.p+16,n);}else if(!leaf&&stride==8){ok=SXMF_TABLE(c,sfs_btree_index,t.p+16,n);for(unsigned i=0;i<n;i++)sxmf_queue_add(q,(uint64_t)sxmf32(b+20+i*8,1)*bs,1,t.depth+1);}}
 }
 xx_rt_free(b);xx_rt_free(q);return ok;
}
bool sx_amiga_sfs_build(sx_context*c)
{
 return sxmf_sfs(c);
}
#undef SXMF_LIMIT
#undef SXMF_ADD
#undef SXMF_TABLE
