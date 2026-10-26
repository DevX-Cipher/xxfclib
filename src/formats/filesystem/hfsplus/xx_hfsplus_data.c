/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HFS+ data structures, moved out of the opticalfs schema family. */
#include "../../xx_format_schema_opticalfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxo_hfsplus_btree_header_fields[] = {
    SX_FIELD("tree_depth", "uint16", 0, 2, SX_NONE),
    SX_FIELD("root_node", "uint32", 2, 4, SX_NONE),
    SX_FIELD("leaf_record_count", "uint32", 6, 4, SX_COUNT_PROP),
    SX_FIELD("first_leaf_node", "uint32", 10, 4, SX_NONE),
    SX_FIELD("last_leaf_node", "uint32", 14, 4, SX_NONE),
    SX_FIELD("node_size", "uint16", 18, 2, SX_SIZE),
    SX_FIELD("maximum_key_length", "uint16", 20, 2, SX_SIZE),
    SX_FIELD("total_nodes", "uint32", 22, 4, SX_COUNT_PROP),
    SX_FIELD("free_nodes", "uint32", 26, 4, SX_COUNT_PROP),
    SX_FIELD("reserved0", "uint16", 30, 2, SX_RESERVED),
    SX_FIELD("clump_size", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("tree_type", "uint8", 36, 1, SX_ID),
    SX_FIELD("key_compare_type", "uint8", 37, 1, SX_ID),
    SX_FIELD("attributes", "uint32", 38, 4, SX_FLAGS),
    SX_FIELD("reserved1", "uint8[64]", 42, 64, SX_RESERVED),
};
const sx_layout sxo_hfsplus_btree_header = {UINT32_C(0x6013001C),"hfsplus_btree_header",sxo_hfsplus_btree_header_fields,SX_COUNT(sxo_hfsplus_btree_header_fields),SX_BE};
static const xx_data_struct_field_desc sxo_hfsplus_btree_record_offset_fields[] = {
    SX_FIELD("record_offset", "uint16", 0, 2, SX_OFFSET),
};
const sx_layout sxo_hfsplus_btree_record_offset = {UINT32_C(0x6013001D),"hfsplus_btree_record_offset",sxo_hfsplus_btree_record_offset_fields,SX_COUNT(sxo_hfsplus_btree_record_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxo_hfsplus_catalog_key_fields[] = {
    SX_FIELD("key_length", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("parent_id", "uint32", 2, 4, SX_ID),
    SX_FIELD("name_code_units", "uint16", 6, 2, SX_COUNT_PROP),
};
const sx_layout sxo_hfsplus_catalog_key = {UINT32_C(0x6013001E),"hfsplus_catalog_key",sxo_hfsplus_catalog_key_fields,SX_COUNT(sxo_hfsplus_catalog_key_fields),SX_BE};
static const xx_data_struct_field_desc sxo_hfsplus_catalog_folder_fields[] = {
    SX_FIELD("record_type", "int16", 0, 2, SX_ID),
    SX_FIELD("flags", "uint16", 2, 2, SX_FLAGS),
    SX_FIELD("valence", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("object_id", "uint32", 8, 4, SX_ID),
    SX_FIELD("create_date", "uint32", 12, 4, SX_TIME),
    SX_FIELD("content_modification_date", "uint32", 16, 4, SX_TIME),
    SX_FIELD("attribute_modification_date", "uint32", 20, 4, SX_TIME),
    SX_FIELD("access_date", "uint32", 24, 4, SX_TIME),
    SX_FIELD("backup_date", "uint32", 28, 4, SX_TIME),
    SX_FIELD("owner_id", "uint32", 32, 4, SX_NONE),
    SX_FIELD("group_id", "uint32", 36, 4, SX_NONE),
    SX_FIELD("admin_flags", "uint8", 40, 1, SX_FLAGS),
    SX_FIELD("owner_flags", "uint8", 41, 1, SX_FLAGS),
    SX_FIELD("file_mode", "uint16", 42, 2, SX_FLAGS),
    SX_FIELD("special", "uint32", 44, 4, SX_NONE),
    SX_FIELD("window_top", "int16", 48, 2, SX_NONE),
    SX_FIELD("window_left", "int16", 50, 2, SX_NONE),
    SX_FIELD("window_bottom", "int16", 52, 2, SX_NONE),
    SX_FIELD("window_right", "int16", 54, 2, SX_NONE),
    SX_FIELD("finder_flags", "uint16", 56, 2, SX_FLAGS),
    SX_FIELD("location_vertical", "int16", 58, 2, SX_NONE),
    SX_FIELD("location_horizontal", "int16", 60, 2, SX_NONE),
    SX_FIELD("finder_opaque", "int16", 62, 2, SX_NONE),
    SX_FIELD("extended_finder_info", "uint8[16]", 64, 16, SX_NONE),
    SX_FIELD("text_encoding", "uint32", 80, 4, SX_ID),
    SX_FIELD("folder_count", "uint32", 84, 4, SX_COUNT_PROP),
};
const sx_layout sxo_hfsplus_catalog_folder = {UINT32_C(0x6013001F),"hfsplus_catalog_folder",sxo_hfsplus_catalog_folder_fields,SX_COUNT(sxo_hfsplus_catalog_folder_fields),SX_BE};
static const xx_data_struct_field_desc sxo_hfsplus_catalog_file_fields[] = {
    SX_FIELD("record_type", "int16", 0, 2, SX_ID),
    SX_FIELD("flags", "uint16", 2, 2, SX_FLAGS),
    SX_FIELD("reserved0", "uint32", 4, 4, SX_RESERVED),
    SX_FIELD("object_id", "uint32", 8, 4, SX_ID),
    SX_FIELD("create_date", "uint32", 12, 4, SX_TIME),
    SX_FIELD("content_modification_date", "uint32", 16, 4, SX_TIME),
    SX_FIELD("attribute_modification_date", "uint32", 20, 4, SX_TIME),
    SX_FIELD("access_date", "uint32", 24, 4, SX_TIME),
    SX_FIELD("backup_date", "uint32", 28, 4, SX_TIME),
    SX_FIELD("owner_id", "uint32", 32, 4, SX_NONE),
    SX_FIELD("group_id", "uint32", 36, 4, SX_NONE),
    SX_FIELD("admin_flags", "uint8", 40, 1, SX_FLAGS),
    SX_FIELD("owner_flags", "uint8", 41, 1, SX_FLAGS),
    SX_FIELD("file_mode", "uint16", 42, 2, SX_FLAGS),
    SX_FIELD("special", "uint32", 44, 4, SX_NONE),
    SX_FIELD("file_type", "uint32", 48, 4, SX_ID),
    SX_FIELD("file_creator", "uint32", 52, 4, SX_ID),
    SX_FIELD("finder_flags", "uint16", 56, 2, SX_FLAGS),
    SX_FIELD("location_vertical", "int16", 58, 2, SX_NONE),
    SX_FIELD("location_horizontal", "int16", 60, 2, SX_NONE),
    SX_FIELD("finder_opaque", "int16", 62, 2, SX_NONE),
    SX_FIELD("extended_finder_info", "uint8[16]", 64, 16, SX_NONE),
    SX_FIELD("text_encoding", "uint32", 80, 4, SX_ID),
    SX_FIELD("reserved2", "uint32", 84, 4, SX_RESERVED),
    SX_FIELD("data_logical_size", "uint64", 88, 8, SX_SIZE),
    SX_FIELD("data_clump_size", "uint32", 96, 4, SX_SIZE),
    SX_FIELD("data_total_blocks", "uint32", 100, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent0_start_block", "uint32", 104, 4, SX_NONE),
    SX_FIELD("data_extent0_block_count", "uint32", 108, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent1_start_block", "uint32", 112, 4, SX_NONE),
    SX_FIELD("data_extent1_block_count", "uint32", 116, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent2_start_block", "uint32", 120, 4, SX_NONE),
    SX_FIELD("data_extent2_block_count", "uint32", 124, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent3_start_block", "uint32", 128, 4, SX_NONE),
    SX_FIELD("data_extent3_block_count", "uint32", 132, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent4_start_block", "uint32", 136, 4, SX_NONE),
    SX_FIELD("data_extent4_block_count", "uint32", 140, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent5_start_block", "uint32", 144, 4, SX_NONE),
    SX_FIELD("data_extent5_block_count", "uint32", 148, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent6_start_block", "uint32", 152, 4, SX_NONE),
    SX_FIELD("data_extent6_block_count", "uint32", 156, 4, SX_COUNT_PROP),
    SX_FIELD("data_extent7_start_block", "uint32", 160, 4, SX_NONE),
    SX_FIELD("data_extent7_block_count", "uint32", 164, 4, SX_COUNT_PROP),
    SX_FIELD("resource_logical_size", "uint64", 168, 8, SX_SIZE),
    SX_FIELD("resource_clump_size", "uint32", 176, 4, SX_SIZE),
    SX_FIELD("resource_total_blocks", "uint32", 180, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent0_start_block", "uint32", 184, 4, SX_NONE),
    SX_FIELD("resource_extent0_block_count", "uint32", 188, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent1_start_block", "uint32", 192, 4, SX_NONE),
    SX_FIELD("resource_extent1_block_count", "uint32", 196, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent2_start_block", "uint32", 200, 4, SX_NONE),
    SX_FIELD("resource_extent2_block_count", "uint32", 204, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent3_start_block", "uint32", 208, 4, SX_NONE),
    SX_FIELD("resource_extent3_block_count", "uint32", 212, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent4_start_block", "uint32", 216, 4, SX_NONE),
    SX_FIELD("resource_extent4_block_count", "uint32", 220, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent5_start_block", "uint32", 224, 4, SX_NONE),
    SX_FIELD("resource_extent5_block_count", "uint32", 228, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent6_start_block", "uint32", 232, 4, SX_NONE),
    SX_FIELD("resource_extent6_block_count", "uint32", 236, 4, SX_COUNT_PROP),
    SX_FIELD("resource_extent7_start_block", "uint32", 240, 4, SX_NONE),
    SX_FIELD("resource_extent7_block_count", "uint32", 244, 4, SX_COUNT_PROP),
};
const sx_layout sxo_hfsplus_catalog_file = {UINT32_C(0x60130020),"hfsplus_catalog_file",sxo_hfsplus_catalog_file_fields,SX_COUNT(sxo_hfsplus_catalog_file_fields),SX_BE};
/* Only a physically contiguous node reached through the volume-header fork's
 * eight inline extents receives structures. Overflow-resolved or fragmented
 * node payloads remain raw; no fictitious contiguous file offset is emitted. */
static bool sxo_hfs_address(sx_context *c,const uint8_t fork[80],uint32_t unit,uint64_t logical,uint64_t size,int64_t *out)
{
    uint64_t start=0;
    if(logical>xx_data_get_u64(fork,8,0,true)||size>xx_data_get_u64(fork,8,0,true)-logical)return false;
    for(unsigned i=0;i<8;i++){
        uint32_t block=xx_data_get_u32(fork+16+i*8,4,0,true),count=xx_data_get_u32(fork+20+i*8,4,0,true);uint64_t bytes=(uint64_t)count*unit;
        if(logical>=start&&logical-start<bytes){uint64_t at=(uint64_t)block*unit+logical-start;if(size>bytes-(logical-start)||at>INT64_MAX||!sxo_can(c,(int64_t)at,size))return false;*out=(int64_t)at;return true;}start+=bytes;
    }return false;
}
static bool sxo_hfs_tree(sx_context *c,const uint8_t fork[80],uint32_t unit,bool catalog)
{
    uint8_t probe[120],*b=NULL;int64_t at;uint32_t node_size,nodes,first,count=1;bool ok=false;
    if(!xx_data_get_u64(fork,8,0,true))return true;
    if(!sxo_hfs_address(c,fork,unit,0,120,&at))return true;if(!sx_read(c,at,probe,120))return false;
    node_size=xx_data_get_u16(probe+32,2,0,true);nodes=xx_data_get_u32(probe+36,4,0,true);first=xx_data_get_u32(probe+24,4,0,true);
    if(node_size<512||node_size>32768||(node_size&(node_size-1))||!nodes||nodes>131072)return false;
    b=xx_mem_alloc(node_size);uint32_t *queue=xx_mem_alloc((size_t)nodes*sizeof(*queue));uint8_t *seen=xx_mem_alloc(nodes);if(!b||!queue||!seen)goto done;xx_rt_memset(seen,0,nodes);queue[0]=0;seen[0]=1;
    if(first){if(first>=nodes)goto done;queue[count++]=first;seen[first]=1;}
    for(uint32_t q=0;q<count;q++){
        if(xx_pd_is_stopped(c->pd))goto done;if(!sxo_hfs_address(c,fork,unit,(uint64_t)queue[q]*node_size,node_size,&at))continue;if(!sx_read(c,at,b,node_size))goto done;
        uint16_t n=xx_data_get_u16(b+10,2,0,true);if(n>(node_size-16)/4)goto done;
        if(!sxo_add(c,&sxo_hfsplus_btree_node_descriptor,at,14)||!sx_table(c,&sxo_hfsplus_btree_record_offset,at+node_size-2*(n+1),2,n+1))goto done;
        for(uint16_t i=0;i<n;i++){
            uint16_t begin=xx_data_get_u16(b+node_size-2-2*i,2,0,true),end=xx_data_get_u16(b+node_size-4-2*i,2,0,true);
            if(begin<14||end<=begin||end>node_size-2*(n+1))goto done;
            if(queue[q]==0&&i==0){if(end-begin<106||!sxo_add(c,&sxo_hfsplus_btree_header,at+begin,106))goto done;}
            else if(catalog&&b[8]==255){
                uint16_t key=xx_data_get_u16(b+begin,2,0,true);uint32_t payload=begin+2+key;if(key<6||payload>end||end-payload<2)goto done;
                if(!sxo_add(c,&sxo_hfsplus_catalog_key,at+begin,8))goto done;
                uint16_t type=xx_data_get_u16(b+payload,2,0,true);const sx_layout *l=type==1?&sxo_hfsplus_catalog_folder:type==2?&sxo_hfsplus_catalog_file:(type==3||type==4)?&sxo_hfsplus_catalog_thread:NULL;
                unsigned length=type==1?88:type==2?248:10;if(l&&(length>(uint32_t)(end-payload)||!sxo_add(c,l,at+payload,length)))goto done;
            }
        }
        uint32_t next=xx_data_get_u32(b,4,0,true);if(next){if(next>=nodes)goto done;if(!seen[next]){if(count>=nodes)goto done;seen[next]=1;queue[count++]=next;}}
    }ok=true;
done:xx_mem_free(b);xx_mem_free(queue);xx_mem_free(seen);return ok;
}
static bool sxo_hfs_build(sx_context *c)
{
    uint8_t h[512],alt[512];if(!sx_read(c,1024,h,512)||!sxo_add(c,&sxo_hfsplus_volume_header,1024,512))return false;
    uint32_t unit=xx_data_get_u32(h+40,4,0,true),blocks=xx_data_get_u32(h+44,4,0,true);uint64_t size=(uint64_t)unit*blocks;
    if(size<4096||size>(uint64_t)c->size)return false;
    if(sxo_can(c,(int64_t)size-1024,512)&&sx_read(c,(int64_t)size-1024,alt,512)&&!xx_rt_memcmp(h,alt,4)&&xx_data_get_u32(alt+40,4,0,true)==unit&&xx_data_get_u32(alt+44,4,0,true)==blocks)
        if(!sxo_add(c,&sxo_hfsplus_volume_header,(int64_t)size-1024,512))return false;
    return sxo_hfs_tree(c,h+192,unit,false)&&sxo_hfs_tree(c,h+272,unit,true)&&sxo_hfs_tree(c,h+352,unit,false);
}
bool sx_hfsplus_build(sx_context*c)
{
 return sxo_hfs_build(c);
}
