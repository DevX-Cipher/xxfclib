/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OS9 RBF data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_os9_disk_descriptor_fields[] = {
    SX_FIELD("total_sectors","uint24",0,3,SX_COUNT_PROP),
    SX_FIELD("track_sector_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("bitmap_bytes","uint16",4,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("root_fd_sector","uint24",8,3,SX_NONE),
    SX_FIELD("owner","uint16",11,2,SX_ID),
    SX_FIELD("attributes","uint8",13,1,SX_FLAGS),
    SX_FIELD("disk_id","uint16",14,2,SX_ID),
    SX_FIELD("format","uint8",16,1,SX_FLAGS),
    SX_FIELD("sectors_per_track","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("reserved19","byte[2]",19,2,SX_RESERVED),
    SX_FIELD("bootstrap_sector","uint24",21,3,SX_NONE),
    SX_FIELD("bootstrap_bytes","uint16",24,2,SX_SIZE),
    SX_FIELD("creation_ymdhm","byte[5]",26,5,SX_NONE),
    SX_FIELD("volume_name","byte[32]",31,32,SX_NONE),
};
const sx_layout sxrfs_os9_disk_descriptor = {0x60650024U,"os9_disk_descriptor",sxrfs_os9_disk_descriptor_fields,SX_COUNT(sxrfs_os9_disk_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_os9_path_options_fields[] = {
    SX_FIELD("device_class","uint8",0,1,SX_ID),
    SX_FIELD("drive","uint8",1,1,SX_NONE),
    SX_FIELD("step_rate","uint8",2,1,SX_NONE),
    SX_FIELD("device_type","uint8",3,1,SX_FLAGS),
    SX_FIELD("density","uint8",4,1,SX_FLAGS),
    SX_FIELD("cylinders","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("verify_disable","uint8",8,1,SX_FLAGS),
    SX_FIELD("sectors_per_track","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("track0_sectors","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("interleave","uint8",13,1,SX_NONE),
    SX_FIELD("segment_allocation_size","uint8",14,1,SX_NONE),
    SX_FIELD("dma_mode","uint8",15,1,SX_FLAGS),
    SX_FIELD("record_extension","uint16",16,2,SX_NONE),
    SX_FIELD("sector_track_offsets","uint8",18,1,SX_NONE),
    SX_FIELD("file_attributes","uint8",19,1,SX_FLAGS),
    SX_FIELD("file_descriptor_sector","uint24",20,3,SX_NONE),
    SX_FIELD("directory_descriptor_sector","uint24",23,3,SX_NONE),
    SX_FIELD("directory_entry_offset","uint32",26,4,SX_OFFSET),
    SX_FIELD("device_table_address","uint16",30,2,SX_ADDRESS),
};
const sx_layout sxrfs_os9_path_options = {0x60650025U,"os9_path_options",sxrfs_os9_path_options_fields,SX_COUNT(sxrfs_os9_path_options_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_os9_file_descriptor_fields[] = {
    SX_FIELD("attributes","uint8",0,1,SX_FLAGS),
    SX_FIELD("owner","uint16",1,2,SX_ID),
    SX_FIELD("modification_ymdhm","byte[5]",3,5,SX_NONE),
    SX_FIELD("link_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("byte_size","uint32",9,4,SX_SIZE),
    SX_FIELD("creation_ymd","byte[3]",13,3,SX_NONE),
};
const sx_layout sxrfs_os9_file_descriptor = {0x60650026U,"os9_file_descriptor",sxrfs_os9_file_descriptor_fields,SX_COUNT(sxrfs_os9_file_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_os9_segment_fields[] = {
    SX_FIELD("first_sector","uint24",0,3,SX_NONE),
    SX_FIELD("sector_count","uint16",3,2,SX_COUNT_PROP),
};
const sx_layout sxrfs_os9_segment = {0x60650027U,"os9_segment",sxrfs_os9_segment_fields,SX_COUNT(sxrfs_os9_segment_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_os9_directory_entry_fields[] = {
    SX_FIELD("name","byte[29]",0,29,SX_NONE),
    SX_FIELD("file_descriptor_sector","uint24",29,3,SX_NONE),
};
const sx_layout sxrfs_os9_directory_entry = {0x60650028U,"os9_directory_entry",sxrfs_os9_directory_entry_fields,SX_COUNT(sxrfs_os9_directory_entry_fields),SX_BE};
#define SXRFS_LIMIT 24000U
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
#define SXRFS_TABLE(c,l,p,n) sxrfs_put(c,&sxrfs_##l,p,n)
static bool sxrfs_os9(sx_context*c){uint8_t h[256];if(!sxrfs_read(c,0,h,256))return false;uint32_t sectors=sxrfs24(h,true),root=sxrfs24(h+8,true),cluster=sxrfs16(h+6,1);if(sectors<8||sectors>(uint64_t)c->size/256||root>=sectors||!cluster||cluster>32||!sxrfs_pow(cluster)||!SXRFS_ADD(c,os9_disk_descriptor,0)||!SXRFS_ADD(c,os9_path_options,63))return false;
 uint32_t*q=xx_rt_calloc(4096,sizeof(*q));if(!q)return false;size_t n=1,i=0;q[0]=root;bool ok=true;while(i<n&&c->count<SXRFS_LIMIT){uint32_t fd=q[i++];uint64_t p=(uint64_t)fd*256;if(!sxrfs_read(c,p,h,256))continue;if(!SXRFS_ADD(c,os9_file_descriptor,p)||!SXRFS_TABLE(c,os9_segment,p+16,48)){ok=false;break;}if(!(h[0]&0x80))continue;uint64_t remain=sxrfs32(h+9,1);for(unsigned seg=0;seg<48&&remain&&ok;seg++){uint32_t start=sxrfs24(h+16+seg*5,true),count=sxrfs16(h+19+seg*5,1);if(!count||start>=sectors||count>sectors-start)break;uint64_t bytes=(uint64_t)count*256;if(bytes>remain)bytes=remain;remain-=bytes;if(bytes>16777216)break;for(uint64_t off=0;off+32<=bytes&&c->count<SXRFS_LIMIT;off+=32){uint8_t e[32];uint64_t at=(uint64_t)start*256+off;if(!sxrfs_read(c,at,e,32)){ok=false;break;}if(!e[0])continue;if(!SXRFS_ADD(c,os9_directory_entry,at)){ok=false;break;}uint32_t child=sxrfs24(e+29,true);bool found=false;for(size_t j=0;j<n;j++)if(q[j]==child)found=true;if(child>0&&child<sectors&&!found&&n<4096)q[n++]=child;}}}xx_rt_free(q);return ok;}
bool sx_os9_rbf_build(sx_context*c)
{
 return sxrfs_os9(c);
}
#undef SXRFS_LIMIT
#undef SXRFS_ADD
#undef SXRFS_TABLE
