/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MFS data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_mfs_master_directory_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("creation_time","uint32",2,4,SX_TIME),
    SX_FIELD("modification_time","uint32",6,4,SX_TIME),
    SX_FIELD("attributes","uint16",10,2,SX_FLAGS),
    SX_FIELD("file_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("directory_start_sector","uint16",14,2,SX_NONE),
    SX_FIELD("directory_sector_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("allocation_block_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("allocation_block_size","uint32",20,4,SX_SIZE),
    SX_FIELD("clump_size","uint32",24,4,SX_SIZE),
    SX_FIELD("allocation_start_sector","uint16",28,2,SX_NONE),
    SX_FIELD("next_file_id","uint32",30,4,SX_ID),
    SX_FIELD("free_blocks","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("volume_name_length","uint8",36,1,SX_SIZE),
    SX_FIELD("volume_name_macroman","byte[27]",37,27,SX_NONE),
};
const sx_layout sxrfs_mfs_master_directory = {0x60650011U,"mfs_master_directory",sxrfs_mfs_master_directory_fields,SX_COUNT(sxrfs_mfs_master_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_mfs_allocation_pair_fields[] = {
    SX_FIELD("two_packed_12bit_links","uint24",0,3,SX_NONE),
};
const sx_layout sxrfs_mfs_allocation_pair = {0x60650012U,"mfs_allocation_pair",sxrfs_mfs_allocation_pair_fields,SX_COUNT(sxrfs_mfs_allocation_pair_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_mfs_file_entry_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("version","uint8",1,1,SX_ID),
    SX_FIELD("finder_type","uint32",2,4,SX_ID),
    SX_FIELD("finder_creator","uint32",6,4,SX_ID),
    SX_FIELD("finder_flags","uint16",10,2,SX_FLAGS),
    SX_FIELD("finder_vertical","int16",12,2,SX_NONE),
    SX_FIELD("finder_horizontal","int16",14,2,SX_NONE),
    SX_FIELD("finder_folder","int16",16,2,SX_NONE),
    SX_FIELD("file_id","uint32",18,4,SX_ID),
    SX_FIELD("data_first_block","uint16",22,2,SX_NONE),
    SX_FIELD("data_logical_size","uint32",24,4,SX_SIZE),
    SX_FIELD("data_physical_size","uint32",28,4,SX_SIZE),
    SX_FIELD("resource_first_block","uint16",32,2,SX_NONE),
    SX_FIELD("resource_logical_size","uint32",34,4,SX_SIZE),
    SX_FIELD("resource_physical_size","uint32",38,4,SX_SIZE),
    SX_FIELD("creation_time","uint32",42,4,SX_TIME),
    SX_FIELD("modification_time","uint32",46,4,SX_TIME),
    SX_FIELD("name_length","uint8",50,1,SX_SIZE),
};
const sx_layout sxrfs_mfs_file_entry = {0x60650013U,"mfs_file_entry",sxrfs_mfs_file_entry_fields,SX_COUNT(sxrfs_mfs_file_entry_fields),SX_BE};
#define SXRFS_LIMIT 24000U
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
#define SXRFS_TABLE(c,l,p,n) sxrfs_put(c,&sxrfs_##l,p,n)
static bool sxrfs_mfs(sx_context*c){uint8_t h[64],b[512];if(!sxrfs_read(c,1024,h,64)||sxrfs16(h,1)!=0xd2d7||!SXRFS_ADD(c,mfs_master_directory,1024))return false;unsigned units=sxrfs16(h+18,1),start=sxrfs16(h+14,1),sectors=sxrfs16(h+16,1);if(units&&units<=640&&!SXRFS_TABLE(c,mfs_allocation_pair,1088,(units+1)/2))return false;if(!sectors||sectors>32768||!sxrfs_span(c,(uint64_t)start*512,(uint64_t)sectors*512))return true;
 for(unsigned i=0;i<sectors&&c->count<SXRFS_LIMIT;i++){uint64_t p=(uint64_t)(start+i)*512;if(!sxrfs_read(c,p,b,512))break;for(unsigned q=0;q+51<=512;){if(!(b[q]&0x80))break;unsigned len=b[q+50],z=(51+len+1)&~1U;if(!len||z>512-q)break;if(!SXRFS_ADD(c,mfs_file_entry,p+q))return false;q+=z;}}return true;}
bool sx_mfs_build(sx_context*c)
{
 return sxrfs_mfs(c);
}
#undef SXRFS_LIMIT
#undef SXRFS_ADD
#undef SXRFS_TABLE
