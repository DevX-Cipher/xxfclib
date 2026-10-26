/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apple Partition Map data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_apm_driver_descriptor_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("block_size","uint16",2,2,SX_SIZE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("device_type","uint16",8,2,SX_ID),
    SX_FIELD("device_id","uint16",10,2,SX_ID),
    SX_FIELD("reserved_data","uint32",12,4,SX_RESERVED),
    SX_FIELD("driver_count","uint16",16,2,SX_COUNT_PROP),
};
const sx_layout sx_dm_apm_driver_descriptor_header = {0x60290051U,"apm_driver_descriptor_header",sx_dm_apm_driver_descriptor_header_fields,SX_COUNT(sx_dm_apm_driver_descriptor_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_apm_driver_descriptor_fields[] = {
    SX_FIELD("driver_block","uint32",0,4,SX_ID),
    SX_FIELD("driver_size_sectors","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("driver_type","uint16",6,2,SX_ID),
};
const sx_layout sx_dm_apm_driver_descriptor = {0x60290052U,"apm_driver_descriptor",sx_dm_apm_driver_descriptor_fields,SX_COUNT(sx_dm_apm_driver_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_apm_partition_entry_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("signature_padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("map_block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("physical_partition_start_block","uint32",8,4,SX_ID),
    SX_FIELD("partition_block_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("partition_name","char[32]",16,32,SX_NONE),
    SX_FIELD("partition_type","char[32]",48,32,SX_NONE),
    SX_FIELD("logical_data_start_block","uint32",80,4,SX_ID),
    SX_FIELD("data_block_count","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("partition_status","uint32",88,4,SX_FLAGS),
    SX_FIELD("logical_boot_start_block","uint32",92,4,SX_ID),
    SX_FIELD("boot_size","uint32",96,4,SX_SIZE),
    SX_FIELD("boot_load_address","uint32",100,4,SX_ADDRESS),
    SX_FIELD("boot_load_address2","uint32",104,4,SX_ADDRESS),
    SX_FIELD("boot_entry_address","uint32",108,4,SX_ADDRESS),
    SX_FIELD("boot_entry_address2","uint32",112,4,SX_ADDRESS),
    SX_FIELD("boot_checksum","uint32",116,4,SX_CHECKSUM),
    SX_FIELD("processor","char[16]",120,16,SX_NONE),
    SX_FIELD("padding","byte[376]",136,376,SX_RESERVED),
};
const sx_layout sx_dm_apm_partition_entry = {0x60290053U,"apm_partition_entry",sx_dm_apm_partition_entry_fields,SX_COUNT(sx_dm_apm_partition_entry_fields),SX_BE};
static bool sx_dm_apm(sx_context*c){uint8_t h[512];if(!sx_dm_read(c,0,h,18)||sx_dm_u16(h,0,true)!=0x4552||!sx_dm_add(c,&sx_dm_apm_driver_descriptor_header,0,18))return false;uint64_t step=sx_dm_u16(h,2,true),n=sx_dm_u16(h,16,true);if(n<=(512-18)/8&&!sx_dm_table(c,&sx_dm_apm_driver_descriptor,18,8,n))return false;if(step!=512&&step!=1024&&step!=2048&&step!=4096)return true;if(step>512&&sx_dm_read(c,512,h,512)&&sx_dm_u16(h,0,true)==0x504d&&sx_dm_u32(h,8,true)==1)step=512;if(!sx_dm_read(c,step,h,512)||sx_dm_u16(h,0,true)!=0x504d)return true;n=sx_dm_u32(h,4,true);if(n>256)n=256;for(uint64_t i=1;i<=n;i++){uint64_t p=i*step;if(!sx_dm_read(c,p,h,512)||sx_dm_u16(h,0,true)!=0x504d)break;if(!sx_dm_add(c,&sx_dm_apm_partition_entry,p,512))return false;}return true;}
bool sx_apm_build(sx_context*c)
{
 return sx_dm_apm(c);
}
