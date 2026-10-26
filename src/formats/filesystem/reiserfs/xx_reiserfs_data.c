/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * REISERFS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_reiser35_superblock_fields[] = {
    SX_FIELD("block_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("root_block","uint32",8,4,SX_NONE),
    SX_FIELD("journal_first_block","uint32",12,4,SX_NONE),
    SX_FIELD("journal_device","uint32",16,4,SX_ID),
    SX_FIELD("journal_blocks","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("journal_transaction_max","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("journal_magic","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("journal_max_batch","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("journal_max_commit_age","uint32",36,4,SX_NONE),
    SX_FIELD("journal_max_transaction_age","uint32",40,4,SX_NONE),
    SX_FIELD("block_size","uint16",44,2,SX_SIZE),
    SX_FIELD("objectid_max_count","uint16",46,2,SX_COUNT_PROP),
    SX_FIELD("objectid_count","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("unmount_state","uint16",50,2,SX_ID),
    SX_FIELD("magic","char[10]",52,10,SX_SIGNATURE),
    SX_FIELD("fs_state","uint16",62,2,SX_FLAGS),
    SX_FIELD("hash_function","uint32",64,4,SX_ID),
    SX_FIELD("tree_height","uint16",68,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_block_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("version","uint16",72,2,SX_ID),
    SX_FIELD("reserved_journal_blocks","uint16",74,2,SX_COUNT_PROP),
};
const sx_layout sxmf_reiser35_superblock = {0x60420011U,"reiser35_superblock",sxmf_reiser35_superblock_fields,SX_COUNT(sxmf_reiser35_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser36_superblock_fields[] = {
    SX_FIELD("block_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("root_block","uint32",8,4,SX_NONE),
    SX_FIELD("journal_first_block","uint32",12,4,SX_NONE),
    SX_FIELD("journal_device","uint32",16,4,SX_ID),
    SX_FIELD("journal_blocks","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("journal_transaction_max","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("journal_magic","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("journal_max_batch","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("journal_max_commit_age","uint32",36,4,SX_NONE),
    SX_FIELD("journal_max_transaction_age","uint32",40,4,SX_NONE),
    SX_FIELD("block_size","uint16",44,2,SX_SIZE),
    SX_FIELD("objectid_max_count","uint16",46,2,SX_COUNT_PROP),
    SX_FIELD("objectid_count","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("unmount_state","uint16",50,2,SX_ID),
    SX_FIELD("magic","char[10]",52,10,SX_SIGNATURE),
    SX_FIELD("fs_state","uint16",62,2,SX_FLAGS),
    SX_FIELD("hash_function","uint32",64,4,SX_ID),
    SX_FIELD("tree_height","uint16",68,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_block_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("version","uint16",72,2,SX_ID),
    SX_FIELD("reserved_journal_blocks","uint16",74,2,SX_COUNT_PROP),
    SX_FIELD("inode_generation","uint32",76,4,SX_NONE),
    SX_FIELD("flags","uint32",80,4,SX_FLAGS),
    SX_FIELD("uuid","byte[16]",84,16,SX_ID),
    SX_FIELD("label","char[16]",100,16,SX_STRING),
    SX_FIELD("mount_count","uint16",116,2,SX_COUNT_PROP),
    SX_FIELD("max_mount_count","uint16",118,2,SX_COUNT_PROP),
    SX_FIELD("last_check","uint32",120,4,SX_TIME),
    SX_FIELD("check_interval","uint32",124,4,SX_NONE),
    SX_FIELD("reserved","byte[76]",128,76,SX_RESERVED),
};
const sx_layout sxmf_reiser36_superblock = {0x60420012U,"reiser36_superblock",sxmf_reiser36_superblock_fields,SX_COUNT(sxmf_reiser36_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser_block_header_fields[] = {
    SX_FIELD("level","uint16",0,2,SX_NONE),
    SX_FIELD("item_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("free_space","uint16",4,2,SX_SIZE),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("right_delimiting_key","byte[16]",8,16,SX_NONE),
};
const sx_layout sxmf_reiser_block_header = {0x60420013U,"reiser_block_header",sxmf_reiser_block_header_fields,SX_COUNT(sxmf_reiser_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser_item_header_fields[] = {
    SX_FIELD("key","byte[16]",0,16,SX_NONE),
    SX_FIELD("free_space_or_entry_count","uint16",16,2,SX_NONE),
    SX_FIELD("item_length","uint16",18,2,SX_SIZE),
    SX_FIELD("item_location","uint16",20,2,SX_OFFSET),
    SX_FIELD("version","uint16",22,2,SX_ID),
};
const sx_layout sxmf_reiser_item_header = {0x60420014U,"reiser_item_header",sxmf_reiser_item_header_fields,SX_COUNT(sxmf_reiser_item_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser_child_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
    SX_FIELD("used_bytes","uint16",4,2,SX_SIZE),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
};
const sx_layout sxmf_reiser_child = {0x60420015U,"reiser_child",sxmf_reiser_child_fields,SX_COUNT(sxmf_reiser_child_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser4_master_fields[] = {
    SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("format_plugin","uint16",16,2,SX_ID),
    SX_FIELD("block_size","uint16",18,2,SX_SIZE),
    SX_FIELD("uuid","byte[16]",20,16,SX_ID),
    SX_FIELD("label","char[16]",36,16,SX_STRING),
};
const sx_layout sxmf_reiser4_master = {0x60420072U,"reiser4_master",sxmf_reiser4_master_fields,SX_COUNT(sxmf_reiser4_master_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser4_format40_superblock_fields[] = {
    SX_FIELD("block_count","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("root_block","uint64",16,8,SX_NONE),
    SX_FIELD("object_id_state","uint64[2]",24,16,SX_NONE),
    SX_FIELD("flush_count","uint64",40,8,SX_COUNT_PROP),
    SX_FIELD("mkfs_id","uint32",48,4,SX_ID),
    SX_FIELD("magic","char[16]",52,16,SX_SIGNATURE),
    SX_FIELD("tree_height","uint16",68,2,SX_COUNT_PROP),
    SX_FIELD("allocation_policy","uint16",70,2,SX_ID),
    SX_FIELD("flags","uint64",72,8,SX_FLAGS),
    SX_FIELD("version","uint32",80,4,SX_ID),
    SX_FIELD("node_plugin","uint32",84,4,SX_ID),
    SX_FIELD("reserved","byte[424]",88,424,SX_RESERVED),
};
const sx_layout sxmf_reiser4_format40_superblock = {0x60420073U,"reiser4_format40_superblock",sxmf_reiser4_format40_superblock_fields,SX_COUNT(sxmf_reiser4_format40_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser4_node40_header_fields[] = {
    SX_FIELD("plugin","uint16",0,2,SX_ID),
    SX_FIELD("item_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("free_space","uint16",4,2,SX_SIZE),
    SX_FIELD("free_space_start","uint16",6,2,SX_OFFSET),
    SX_FIELD("magic","uint32",8,4,SX_SIGNATURE),
    SX_FIELD("mkfs_id","uint32",12,4,SX_ID),
    SX_FIELD("flush_id","uint64",16,8,SX_NONE),
    SX_FIELD("flags","uint16",24,2,SX_FLAGS),
    SX_FIELD("level","uint8",26,1,SX_NONE),
    SX_FIELD("padding","uint8",27,1,SX_RESERVED),
};
const sx_layout sxmf_reiser4_node40_header = {0x60420074U,"reiser4_node40_header",sxmf_reiser4_node40_header_fields,SX_COUNT(sxmf_reiser4_node40_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser4_item_header_large_fields[] = {
    SX_FIELD("locality_and_type","uint64",0,8,SX_FLAGS),
    SX_FIELD("ordering","uint64",8,8,SX_NONE),
    SX_FIELD("object_and_type","uint64",16,8,SX_FLAGS),
    SX_FIELD("offset","uint64",24,8,SX_NONE),
    SX_FIELD("data_offset","uint16",32,2,SX_OFFSET),
    SX_FIELD("flags","uint16",34,2,SX_FLAGS),
    SX_FIELD("plugin","uint16",36,2,SX_ID),
};
const sx_layout sxmf_reiser4_item_header_large = {0x60420075U,"reiser4_item_header_large",sxmf_reiser4_item_header_large_fields,SX_COUNT(sxmf_reiser4_item_header_large_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser4_child_fields[] = {
    SX_FIELD("block","uint64",0,8,SX_NONE),
};
const sx_layout sxmf_reiser4_child = {0x60420076U,"reiser4_child",sxmf_reiser4_child_fields,SX_COUNT(sxmf_reiser4_child_fields),SX_LE};
static const xx_data_struct_field_desc sxmf_reiser4_extent_fields[] = {
    SX_FIELD("block","uint64",0,8,SX_NONE),
    SX_FIELD("block_count","uint64",8,8,SX_COUNT_PROP),
};
const sx_layout sxmf_reiser4_extent = {0x60420077U,"reiser4_extent",sxmf_reiser4_extent_fields,SX_COUNT(sxmf_reiser4_extent_fields),SX_LE};
#define SXMF_LIMIT 24000U
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
static bool sxmf_reiser(sx_context*c){uint8_t h[512];uint64_t super=65536;bool four=false;if(!sxmf_read(c,super,h,512))return false;four=!xx_rt_memcmp(h,"ReIsEr4",7);if(!four&&xx_rt_memcmp(h+52,"ReIsEr",6)){super=8192;if(!sxmf_read(c,super,h,512)||xx_rt_memcmp(h+52,"ReIsErFs",8))return false;}
 uint64_t bs,blocks,root;if(four){if(!SXMF_ADD(c,reiser4_master,super))return false;bs=sxmf16(h+18,0);if(bs<512||bs>65536||!sxmf_pow(bs)||!sxmf_read(c,super+bs,h,512)||xx_rt_memcmp(h+52,"ReIsEr40FoRmAt",13))return true;if(!SXMF_ADD(c,reiser4_format40_superblock,super+bs))return false;blocks=sxmf64(h,0);root=sxmf64(h+16,0);}
 else{bs=sxmf16(h+44,0);blocks=sxmf32(h,0);root=sxmf32(h+8,0);if(!sxmf_put(c,sxmf16(h+72,0)==2?&sxmf_reiser36_superblock:&sxmf_reiser35_superblock,super,1))return false;}
 if(bs<512||bs>65536||!sxmf_pow(bs)||!blocks||blocks>(uint64_t)c->size/bs)return true;uint8_t*b=xx_rt_malloc((size_t)bs);sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!b||!q){xx_rt_free(b);xx_rt_free(q);return false;}bool ok=true;sxmf_queue_add(q,root*bs,0,0);
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT&&!xx_pd_is_stopped(c->pd)){sxmf_task t=q->items[q->index++];if(t.p/bs>=blocks||!sxmf_read(c,t.p,b,(size_t)bs))continue;
  if(four){unsigned n=sxmf16(b+2,0);if(sxmf16(b,0)!=0||sxmf32(b+8,0)!=0x52344653U||n>(bs-28)/38)continue;if(!SXMF_ADD(c,reiser4_node40_header,t.p)){ok=false;break;}uint64_t headers=bs-(uint64_t)n*38;for(unsigned i=0;i<n;i++){uint64_t hp=bs-(uint64_t)(i+1)*38,dp=sxmf16(b+hp+32,0),end=i+1<n?sxmf16(b+hp-38+32,0):sxmf16(b+6,0);unsigned plugin=sxmf16(b+hp+36,0);if(dp<28||dp>end||end>headers)continue;if(!SXMF_ADD(c,reiser4_item_header_large,t.p+hp)){ok=false;break;}if(plugin==3&&end-dp==8){if(!SXMF_ADD(c,reiser4_child,t.p+dp)){ok=false;break;}uint64_t child=sxmf64(b+dp,0);if(child<blocks)sxmf_queue_add(q,child*bs,0,t.depth+1);}else if(plugin==5&&(end-dp)%16==0&&!SXMF_TABLE(c,reiser4_extent,t.p+dp,(end-dp)/16)){ok=false;break;}}}
  else{unsigned level=sxmf16(b,0),n=sxmf16(b+2,0);if(!level||level>16||n>(bs-24)/24)continue;if(!SXMF_ADD(c,reiser_block_header,t.p)){ok=false;break;}if(level==1){for(unsigned i=0;i<n;i++){uint64_t p=24+i*24,z=sxmf16(b+p+18,0),at=sxmf16(b+p+20,0);if(at<24+n*24||at>bs||z>bs-at)continue;if(!SXMF_ADD(c,reiser_item_header,t.p+p)){ok=false;break;}}}else{uint64_t p=24+(uint64_t)n*16;if(n+1>(bs-p)/8)continue;if(!SXMF_TABLE(c,reiser_child,t.p+p,n+1)){ok=false;break;}for(unsigned i=0;i<=n;i++){uint64_t child=sxmf32(b+p+i*8,0);if(child<blocks)sxmf_queue_add(q,child*bs,0,t.depth+1);}}}
 }
 xx_rt_free(b);xx_rt_free(q);return ok;
}
bool sx_reiserfs_build(sx_context*c)
{
 return sxmf_reiser(c);
}
#undef SXMF_LIMIT
#undef SXMF_ADD
#undef SXMF_TABLE
