/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HFS data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_hfs_master_directory_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("creation_time","uint32",2,4,SX_TIME),
    SX_FIELD("modification_time","uint32",6,4,SX_TIME),
    SX_FIELD("attributes","uint16",10,2,SX_FLAGS),
    SX_FIELD("root_file_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_start_sector","uint16",14,2,SX_NONE),
    SX_FIELD("allocation_search_pointer","uint16",16,2,SX_NONE),
    SX_FIELD("allocation_block_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("allocation_block_size","uint32",20,4,SX_SIZE),
    SX_FIELD("clump_size","uint32",24,4,SX_SIZE),
    SX_FIELD("allocation_start_sector","uint16",28,2,SX_NONE),
    SX_FIELD("next_catalog_id","uint32",30,4,SX_ID),
    SX_FIELD("free_blocks","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("volume_name_length","uint8",36,1,SX_SIZE),
    SX_FIELD("volume_name_macroman","byte[27]",37,27,SX_NONE),
    SX_FIELD("backup_time","uint32",64,4,SX_TIME),
    SX_FIELD("backup_sequence","uint16",68,2,SX_NONE),
    SX_FIELD("write_count","uint32",70,4,SX_COUNT_PROP),
    SX_FIELD("extents_clump_size","uint32",74,4,SX_SIZE),
    SX_FIELD("catalog_clump_size","uint32",78,4,SX_SIZE),
    SX_FIELD("root_directory_count","uint16",82,2,SX_COUNT_PROP),
    SX_FIELD("file_count","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("directory_count","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("finder_info","uint32[8]",92,32,SX_NONE),
    SX_FIELD("volume_cache_or_embedded_signature","uint16",124,2,SX_NONE),
    SX_FIELD("bitmap_cache_or_embedded_start","uint16",126,2,SX_NONE),
    SX_FIELD("control_cache_or_embedded_count","uint16",128,2,SX_NONE),
    SX_FIELD("extents_file_size","uint32",130,4,SX_SIZE),
    SX_FIELD("extents_file_initial_extents","uint16[6]",134,12,SX_NONE),
    SX_FIELD("catalog_file_size","uint32",146,4,SX_SIZE),
    SX_FIELD("catalog_file_initial_extents","uint16[6]",150,12,SX_NONE),
};
const sx_layout sxrfs_hfs_master_directory = {0x6065003fU,"hfs_master_directory",sxrfs_hfs_master_directory_fields,SX_COUNT(sxrfs_hfs_master_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_btree_node_fields[] = {
    SX_FIELD("forward_link","uint32",0,4,SX_NONE),
    SX_FIELD("backward_link","uint32",4,4,SX_NONE),
    SX_FIELD("kind","int8",8,1,SX_ID),
    SX_FIELD("height","uint8",9,1,SX_NONE),
    SX_FIELD("record_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("reserved","uint16",12,2,SX_RESERVED),
};
const sx_layout sxrfs_hfs_btree_node = {0x60650040U,"hfs_btree_node",sxrfs_hfs_btree_node_fields,SX_COUNT(sxrfs_hfs_btree_node_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_btree_header_fields[] = {
    SX_FIELD("tree_depth","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("root_node","uint32",2,4,SX_NONE),
    SX_FIELD("leaf_records","uint32",6,4,SX_COUNT_PROP),
    SX_FIELD("first_leaf_node","uint32",10,4,SX_NONE),
    SX_FIELD("last_leaf_node","uint32",14,4,SX_NONE),
    SX_FIELD("node_size","uint16",18,2,SX_SIZE),
    SX_FIELD("maximum_key_length","uint16",20,2,SX_SIZE),
    SX_FIELD("total_nodes","uint32",22,4,SX_COUNT_PROP),
    SX_FIELD("free_nodes","uint32",26,4,SX_COUNT_PROP),
    SX_FIELD("reserved16","uint16",30,2,SX_RESERVED),
    SX_FIELD("clump_size","uint32",32,4,SX_SIZE),
    SX_FIELD("tree_type","uint8",36,1,SX_ID),
    SX_FIELD("key_compare_type","uint8",37,1,SX_ID),
    SX_FIELD("attributes","uint32",38,4,SX_FLAGS),
    SX_FIELD("reserved32","uint32[16]",42,64,SX_RESERVED),
};
const sx_layout sxrfs_hfs_btree_header = {0x60650041U,"hfs_btree_header",sxrfs_hfs_btree_header_fields,SX_COUNT(sxrfs_hfs_btree_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_node_record_offset_fields[] = {
    SX_FIELD("record_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxrfs_hfs_node_record_offset = {0x60650042U,"hfs_node_record_offset",sxrfs_hfs_node_record_offset_fields,SX_COUNT(sxrfs_hfs_node_record_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_catalog_key_prefix_fields[] = {
    SX_FIELD("key_length","uint8",0,1,SX_SIZE),
    SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
    SX_FIELD("parent_catalog_id","uint32",2,4,SX_ID),
    SX_FIELD("name_length","uint8",6,1,SX_SIZE),
};
const sx_layout sxrfs_hfs_catalog_key_prefix = {0x60650043U,"hfs_catalog_key_prefix",sxrfs_hfs_catalog_key_prefix_fields,SX_COUNT(sxrfs_hfs_catalog_key_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_extents_key_fields[] = {
    SX_FIELD("key_length","uint8",0,1,SX_SIZE),
    SX_FIELD("fork_type","uint8",1,1,SX_ID),
    SX_FIELD("file_id","uint32",2,4,SX_ID),
    SX_FIELD("first_allocation_block","uint16",6,2,SX_NONE),
};
const sx_layout sxrfs_hfs_extents_key = {0x60650044U,"hfs_extents_key",sxrfs_hfs_extents_key_fields,SX_COUNT(sxrfs_hfs_extents_key_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_extent_fields[] = {
    SX_FIELD("first_allocation_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxrfs_hfs_extent = {0x60650045U,"hfs_extent",sxrfs_hfs_extent_fields,SX_COUNT(sxrfs_hfs_extent_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_btree_child_fields[] = {
    SX_FIELD("child_node","uint32",0,4,SX_NONE),
};
const sx_layout sxrfs_hfs_btree_child = {0x60650046U,"hfs_btree_child",sxrfs_hfs_btree_child_fields,SX_COUNT(sxrfs_hfs_btree_child_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_catalog_folder_fields[] = {
    SX_FIELD("record_type","int16",0,2,SX_ID),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("valence","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("folder_id","uint32",6,4,SX_ID),
    SX_FIELD("creation_time","uint32",10,4,SX_TIME),
    SX_FIELD("modification_time","uint32",14,4,SX_TIME),
    SX_FIELD("backup_time","uint32",18,4,SX_TIME),
    SX_FIELD("finder_folder_info","byte[16]",22,16,SX_NONE),
    SX_FIELD("finder_extended_info","byte[16]",38,16,SX_NONE),
    SX_FIELD("reserved","uint32[4]",54,16,SX_RESERVED),
};
const sx_layout sxrfs_hfs_catalog_folder = {0x60650047U,"hfs_catalog_folder",sxrfs_hfs_catalog_folder_fields,SX_COUNT(sxrfs_hfs_catalog_folder_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_catalog_file_fields[] = {
    SX_FIELD("record_type","int16",0,2,SX_ID),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("file_type","int8",3,1,SX_ID),
    SX_FIELD("finder_type","uint32",4,4,SX_ID),
    SX_FIELD("finder_creator","uint32",8,4,SX_ID),
    SX_FIELD("finder_flags","uint16",12,2,SX_FLAGS),
    SX_FIELD("finder_vertical","int16",14,2,SX_NONE),
    SX_FIELD("finder_horizontal","int16",16,2,SX_NONE),
    SX_FIELD("finder_folder","int16",18,2,SX_NONE),
    SX_FIELD("file_id","uint32",20,4,SX_ID),
    SX_FIELD("data_start_block","uint16",24,2,SX_NONE),
    SX_FIELD("data_logical_size","int32",26,4,SX_SIZE),
    SX_FIELD("data_physical_size","int32",30,4,SX_SIZE),
    SX_FIELD("resource_start_block","uint16",34,2,SX_NONE),
    SX_FIELD("resource_logical_size","int32",36,4,SX_SIZE),
    SX_FIELD("resource_physical_size","int32",40,4,SX_SIZE),
    SX_FIELD("creation_time","uint32",44,4,SX_TIME),
    SX_FIELD("modification_time","uint32",48,4,SX_TIME),
    SX_FIELD("backup_time","uint32",52,4,SX_TIME),
    SX_FIELD("finder_extended_info","byte[16]",56,16,SX_NONE),
    SX_FIELD("clump_size","uint16",72,2,SX_SIZE),
    SX_FIELD("data_initial_extents","uint16[6]",74,12,SX_NONE),
    SX_FIELD("resource_initial_extents","uint16[6]",86,12,SX_NONE),
    SX_FIELD("reserved","uint32",98,4,SX_RESERVED),
};
const sx_layout sxrfs_hfs_catalog_file = {0x60650048U,"hfs_catalog_file",sxrfs_hfs_catalog_file_fields,SX_COUNT(sxrfs_hfs_catalog_file_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_hfs_catalog_thread_fields[] = {
    SX_FIELD("record_type","int16",0,2,SX_ID),
    SX_FIELD("reserved","int32[2]",2,8,SX_RESERVED),
    SX_FIELD("parent_catalog_id","uint32",10,4,SX_ID),
    SX_FIELD("name_length","uint8",14,1,SX_SIZE),
    SX_FIELD("name_macroman","byte[31]",15,31,SX_NONE),
};
const sx_layout sxrfs_hfs_catalog_thread = {0x60650049U,"hfs_catalog_thread",sxrfs_hfs_catalog_thread_fields,SX_COUNT(sxrfs_hfs_catalog_thread_fields),SX_BE};
#define SXRFS_LIMIT 24000U
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
#define SXRFS_TABLE(c,l,p,n) sxrfs_put(c,&sxrfs_##l,p,n)
/* Only initial physical extents are mapped here. Overflow/reconstructed forks
 * remain raw, as do node records crossing a noncontiguous extent boundary. */
static bool sxrfs_hfs_pos(const uint8_t*extent,uint64_t base,uint64_t bs,uint64_t logical,uint64_t n,uint64_t*out){for(unsigned i=0;i<3;i++){uint64_t first=sxrfs16(extent+i*4,1),z=(uint64_t)sxrfs16(extent+i*4+2,1)*bs;if(logical>=z){logical-=z;continue;}if(n>z-logical)return false;*out=base+first*bs+logical;return true;}return false;}
static bool sxrfs_hfs_tree(sx_context*c,const uint8_t*extent,uint64_t base,uint64_t bs,uint64_t size,bool catalog){uint64_t p;uint8_t h[120];if(size<512||!sxrfs_hfs_pos(extent,base,bs,0,120,&p)||!sxrfs_read(c,p,h,120)||h[8]!=1)return true;unsigned node=sxrfs16(h+32,1);uint32_t total=sxrfs32(h+36,1);if(node<512||node>32768||!sxrfs_pow(node)||!total||total>size/node)return true;uint8_t*b=xx_rt_malloc(node);if(!b)return false;bool ok=true;uint8_t bitmap[256];if(!sxrfs_hfs_pos(extent,base,bs,248,256,&p)||!sxrfs_read(c,p,bitmap,256)){xx_rt_free(b);return true;}
 for(uint32_t i=0;i<total&&i<2048&&c->count<SXRFS_LIMIT;i++){if(!(bitmap[i/8]&(0x80U>>(i%8))))continue;if(!sxrfs_hfs_pos(extent,base,bs,(uint64_t)i*node,node,&p)||!sxrfs_read(c,p,b,node))continue;int kind=(int8_t)b[8];unsigned n=sxrfs16(b+10,1);if(n>(node-14)/2-1||(kind!=-1&&kind!=0&&kind!=1&&kind!=2))continue;if(!SXRFS_ADD(c,hfs_btree_node,p)||!SXRFS_TABLE(c,hfs_node_record_offset,p+node-(n+1)*2,n+1)){ok=false;break;}
  for(unsigned j=0;j<n&&ok;j++){unsigned a=sxrfs16(b+node-2*(j+1),1),z=sxrfs16(b+node-2*(j+2),1);if(a<14||z<a||z>node-(n+1)*2)continue;if(kind==1){if(j==0&&z-a>=106&&!SXRFS_ADD(c,hfs_btree_header,p+a))ok=false;continue;}if(kind==2||z-a<2)continue;unsigned key=b[a];unsigned data=a+((key+2)&~1U);if(data>z)continue;if(catalog){if(key<6||b[a+6]>31||b[a+6]>key-6)continue;if(!SXRFS_ADD(c,hfs_catalog_key_prefix,p+a)){ok=false;break;}}else{if(key!=7||!SXRFS_ADD(c,hfs_extents_key,p+a)){ok=false;break;}}
   if(kind==0){if(z-data>=4&&!SXRFS_ADD(c,hfs_btree_child,p+data))ok=false;}else if(!catalog){if(z-data>=12&&!SXRFS_TABLE(c,hfs_extent,p+data,3))ok=false;}else if(z-data>=2){int type=(int16_t)sxrfs16(b+data,1);const sx_layout*l=type==0x100?&sxrfs_hfs_catalog_folder:type==0x200?&sxrfs_hfs_catalog_file:(type==0x300||type==0x400)?&sxrfs_hfs_catalog_thread:NULL;if(l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;if((uint64_t)(f->rel_offset+f->size)<=z-data&&!sxrfs_put(c,l,p+data,1))ok=false;}}
  }
 }xx_rt_free(b);return ok;}
static bool sxrfs_hfs(sx_context*c){uint8_t h[162];if(!sxrfs_read(c,1024,h,162)||sxrfs16(h,1)!=0x4244||!SXRFS_ADD(c,hfs_master_directory,1024))return false;uint64_t bs=sxrfs32(h+20,1),base=(uint64_t)sxrfs16(h+28,1)*512;if(bs<512||bs>16777216||bs%512||!sxrfs_span(c,base,(uint64_t)sxrfs16(h+18,1)*bs))return true;return sxrfs_hfs_tree(c,h+134,base,bs,sxrfs32(h+130,1),false)&&sxrfs_hfs_tree(c,h+150,base,bs,sxrfs32(h+146,1),true);}
bool sx_hfs_build(sx_context*c)
{
 return sxrfs_hfs(c);
}
#undef SXRFS_LIMIT
#undef SXRFS_ADD
#undef SXRFS_TABLE
