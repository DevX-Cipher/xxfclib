/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Android logical partitions (super) data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_lp_geometry_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("struct_size","uint32",4,4,SX_SIZE),
    SX_FIELD("checksum","uint8[32]",8,32,SX_CHECKSUM),
    SX_FIELD("metadata_max_size","uint32",40,4,SX_SIZE),
    SX_FIELD("metadata_slot_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("logical_block_size","uint32",48,4,SX_SIZE),
};
const sx_layout sxbrs_lp_geometry = {UINT32_C(0x603e0003),"lp_geometry",sxbrs_lp_geometry_fields,SX_COUNT(sxbrs_lp_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_NONE),
    SX_FIELD("minor_version","uint16",6,2,SX_NONE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_checksum","uint8[32]",12,32,SX_CHECKSUM),
    SX_FIELD("tables_size","uint32",44,4,SX_SIZE),
    SX_FIELD("tables_checksum","uint8[32]",48,32,SX_CHECKSUM),
    SX_FIELD("partitions_offset","uint32",80,4,SX_OFFSET),
    SX_FIELD("partitions_num_entries","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("partitions_entry_size","uint32",88,4,SX_SIZE),
    SX_FIELD("extents_offset","uint32",92,4,SX_OFFSET),
    SX_FIELD("extents_num_entries","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("extents_entry_size","uint32",100,4,SX_SIZE),
    SX_FIELD("groups_offset","uint32",104,4,SX_OFFSET),
    SX_FIELD("groups_num_entries","uint32",108,4,SX_COUNT_PROP),
    SX_FIELD("groups_entry_size","uint32",112,4,SX_SIZE),
    SX_FIELD("block_devices_offset","uint32",116,4,SX_OFFSET),
    SX_FIELD("block_devices_num_entries","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("block_devices_entry_size","uint32",124,4,SX_SIZE),
};
const sx_layout sxbrs_lp_header = {UINT32_C(0x603e0004),"lp_header",sxbrs_lp_header_fields,SX_COUNT(sxbrs_lp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_header_extended_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_NONE),
    SX_FIELD("minor_version","uint16",6,2,SX_NONE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_checksum","uint8[32]",12,32,SX_CHECKSUM),
    SX_FIELD("tables_size","uint32",44,4,SX_SIZE),
    SX_FIELD("tables_checksum","uint8[32]",48,32,SX_CHECKSUM),
    SX_FIELD("partitions_offset","uint32",80,4,SX_OFFSET),
    SX_FIELD("partitions_num_entries","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("partitions_entry_size","uint32",88,4,SX_SIZE),
    SX_FIELD("extents_offset","uint32",92,4,SX_OFFSET),
    SX_FIELD("extents_num_entries","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("extents_entry_size","uint32",100,4,SX_SIZE),
    SX_FIELD("groups_offset","uint32",104,4,SX_OFFSET),
    SX_FIELD("groups_num_entries","uint32",108,4,SX_COUNT_PROP),
    SX_FIELD("groups_entry_size","uint32",112,4,SX_SIZE),
    SX_FIELD("block_devices_offset","uint32",116,4,SX_OFFSET),
    SX_FIELD("block_devices_num_entries","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("block_devices_entry_size","uint32",124,4,SX_SIZE),
    SX_FIELD("flags","uint32",128,4,SX_FLAGS),
    SX_FIELD("reserved","uint8[124]",132,124,SX_RESERVED),
};
const sx_layout sxbrs_lp_header_extended = {UINT32_C(0x603e0005),"lp_header_extended",sxbrs_lp_header_extended_fields,SX_COUNT(sxbrs_lp_header_extended_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_partition_fields[] = {
    SX_FIELD("name","char[36]",0,36,SX_STRING),
    SX_FIELD("attributes","uint32",36,4,SX_FLAGS),
    SX_FIELD("first_extent_index","uint32",40,4,SX_NONE),
    SX_FIELD("num_extents","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("group_index","uint32",48,4,SX_NONE),
};
const sx_layout sxbrs_lp_partition = {UINT32_C(0x603e0006),"lp_partition",sxbrs_lp_partition_fields,SX_COUNT(sxbrs_lp_partition_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_extent_fields[] = {
    SX_FIELD("num_sectors","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("target_type","uint32",8,4,SX_ID),
    SX_FIELD("target_data","uint64",12,8,SX_NONE),
    SX_FIELD("target_source","uint32",20,4,SX_NONE),
};
const sx_layout sxbrs_lp_extent = {UINT32_C(0x603e0007),"lp_extent",sxbrs_lp_extent_fields,SX_COUNT(sxbrs_lp_extent_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_group_fields[] = {
    SX_FIELD("name","char[36]",0,36,SX_STRING),
    SX_FIELD("flags","uint32",36,4,SX_FLAGS),
    SX_FIELD("maximum_size","uint64",40,8,SX_SIZE),
};
const sx_layout sxbrs_lp_group = {UINT32_C(0x603e0008),"lp_group",sxbrs_lp_group_fields,SX_COUNT(sxbrs_lp_group_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_block_device_fields[] = {
    SX_FIELD("first_logical_sector","uint64",0,8,SX_NONE),
    SX_FIELD("alignment","uint32",8,4,SX_SIZE),
    SX_FIELD("alignment_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("size","uint64",16,8,SX_SIZE),
    SX_FIELD("partition_name","char[36]",24,36,SX_STRING),
    SX_FIELD("flags","uint32",60,4,SX_FLAGS),
};
const sx_layout sxbrs_lp_block_device = {UINT32_C(0x603e0009),"lp_block_device",sxbrs_lp_block_device_fields,SX_COUNT(sxbrs_lp_block_device_fields),SX_LE};
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_lp(sx_context*c)
{
 if(c->size<12416||N(4096,4)!=0x616c4467U||N(4100,4)!=52||N(12288,4)!=0x414c5030U)return false;
 if(!sxbrs_add(c,&sxbrs_lp_geometry,4096))return false;
 /* The second physical geometry copy is independent; native uses the first. */
 if(N(8192,4)==0x616c4467U&&N(8196,4)==52&&!sxbrs_add(c,&sxbrs_lp_geometry,8192))return false;
 uint64_t header=N(12296,4),bytes=N(12332,4);if(header!=128&&header!=256)return false;
 if(!sxbrs_add(c,header==128?&sxbrs_lp_header:&sxbrs_lp_header_extended,12288))return false;
 int64_t data=12288+(int64_t)header;if(bytes>(uint64_t)(c->size-data))return false;
 const sx_layout*layouts[]={&sxbrs_lp_partition,&sxbrs_lp_extent,&sxbrs_lp_group,&sxbrs_lp_block_device};
 for(unsigned i=0;i<4;i++){
  uint64_t o=N(12368+12*i,4),count=N(12372+12*i,4),stride=N(12376+12*i,4),known=sxbrs_width(layouts[i]);
  if(o>bytes||stride<known||count>(bytes-o)/stride)return false;
  if(stride==known){int64_t at=data+(int64_t)o;if(!sxbrs_take(c,layouts[i],&at,data+(int64_t)bytes,count))return false;}
  else for(uint64_t j=0;j<count&&j<65536&&c->count<32000;j++)if(!sxbrs_add(c,layouts[i],data+(int64_t)(o+j*stride)))return false;
 }
 return !c->failed;
}
bool sx_android_lp_build(sx_context*c)
{
 return sxbrs_lp(c);
}
#undef N
