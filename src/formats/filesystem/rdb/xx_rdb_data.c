/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Amiga Rigid Disk Block (RDB) hard disk data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_rdb_rigid_disk_block_fields[] = {
    SX_FIELD("identifier","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("summed_longs","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("checksum","int32",8,4,SX_CHECKSUM),
    SX_FIELD("host_id","uint32",12,4,SX_ID),
    SX_FIELD("block_bytes","uint32",16,4,SX_SIZE),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("bad_block_list","uint32",24,4,SX_ID),
    SX_FIELD("partition_list","uint32",28,4,SX_ID),
    SX_FIELD("filesystem_header_list","uint32",32,4,SX_ID),
    SX_FIELD("drive_init","uint32",36,4,SX_ID),
    SX_FIELD("reserved1","uint32[6]",40,24,SX_RESERVED),
    SX_FIELD("cylinders","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("sectors","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("interleave","uint32",76,4,SX_NONE),
    SX_FIELD("parking_zone","uint32",80,4,SX_ID),
    SX_FIELD("reserved2","uint32[3]",84,12,SX_RESERVED),
    SX_FIELD("write_precompensation_cylinder","uint32",96,4,SX_ID),
    SX_FIELD("reduced_write_cylinder","uint32",100,4,SX_ID),
    SX_FIELD("step_rate","uint32",104,4,SX_NONE),
    SX_FIELD("reserved3","uint32[5]",108,20,SX_RESERVED),
    SX_FIELD("rdb_blocks_low","uint32",128,4,SX_ID),
    SX_FIELD("rdb_blocks_high","uint32",132,4,SX_ID),
    SX_FIELD("low_cylinder","uint32",136,4,SX_ID),
    SX_FIELD("high_cylinder","uint32",140,4,SX_ID),
    SX_FIELD("cylinder_blocks","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("autopark_seconds","uint32",148,4,SX_NONE),
    SX_FIELD("highest_rdb_block","uint32",152,4,SX_ID),
    SX_FIELD("reserved4","uint32",156,4,SX_RESERVED),
    SX_FIELD("disk_vendor","char[8]",160,8,SX_NONE),
    SX_FIELD("disk_product","char[16]",168,16,SX_NONE),
    SX_FIELD("disk_revision","char[4]",184,4,SX_NONE),
    SX_FIELD("controller_vendor","char[8]",188,8,SX_NONE),
    SX_FIELD("controller_product","char[16]",196,16,SX_NONE),
    SX_FIELD("controller_revision","char[4]",212,4,SX_NONE),
    SX_FIELD("reserved5","uint32[10]",216,40,SX_RESERVED),
};
const sx_layout sx_dm_rdb_rigid_disk_block = {0x60290054U,"rdb_rigid_disk_block",sx_dm_rdb_rigid_disk_block_fields,SX_COUNT(sx_dm_rdb_rigid_disk_block_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_rdb_partition_block_fields[] = {
    SX_FIELD("identifier","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("summed_longs","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("checksum","int32",8,4,SX_CHECKSUM),
    SX_FIELD("host_id","uint32",12,4,SX_ID),
    SX_FIELD("next_block","uint32",16,4,SX_ID),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("reserved1","uint32[2]",24,8,SX_RESERVED),
    SX_FIELD("device_flags","uint32",32,4,SX_FLAGS),
    SX_FIELD("drive_name_bcpl","byte[32]",36,32,SX_NONE),
    SX_FIELD("reserved2","uint32[15]",68,60,SX_RESERVED),
    SX_FIELD("environment_table_size","uint32",128,4,SX_COUNT_PROP),
    SX_FIELD("longs_per_sector","uint32",132,4,SX_COUNT_PROP),
    SX_FIELD("sector_origin","uint32",136,4,SX_ID),
    SX_FIELD("surfaces","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_block","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("blocks_per_track","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("reserved_blocks","uint32",152,4,SX_COUNT_PROP),
    SX_FIELD("preallocated_blocks","uint32",156,4,SX_COUNT_PROP),
    SX_FIELD("interleave","uint32",160,4,SX_NONE),
    SX_FIELD("low_cylinder","uint32",164,4,SX_ID),
    SX_FIELD("high_cylinder","uint32",168,4,SX_ID),
    SX_FIELD("buffer_count","uint32",172,4,SX_COUNT_PROP),
    SX_FIELD("buffer_memory_type","uint32",176,4,SX_FLAGS),
    SX_FIELD("max_transfer","uint32",180,4,SX_SIZE),
    SX_FIELD("address_mask","uint32",184,4,SX_FLAGS),
    SX_FIELD("boot_priority","int32",188,4,SX_NONE),
    SX_FIELD("dos_type","uint32",192,4,SX_ID),
    SX_FIELD("baud","uint32",196,4,SX_NONE),
    SX_FIELD("control","uint32",200,4,SX_FLAGS),
    SX_FIELD("boot_blocks","uint32",204,4,SX_COUNT_PROP),
    SX_FIELD("environment_reserved","uint32[12]",208,48,SX_RESERVED),
};
const sx_layout sx_dm_rdb_partition_block = {0x60290055U,"rdb_partition_block",sx_dm_rdb_partition_block_fields,SX_COUNT(sx_dm_rdb_partition_block_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_rdb_load_segment_header_fields[] = {
    SX_FIELD("identifier","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("summed_longs","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("checksum","int32",8,4,SX_CHECKSUM),
    SX_FIELD("host_id","uint32",12,4,SX_ID),
    SX_FIELD("next_block","uint32",16,4,SX_ID),
};
const sx_layout sx_dm_rdb_load_segment_header = {0x60290057U,"rdb_load_segment_header",sx_dm_rdb_load_segment_header_fields,SX_COUNT(sx_dm_rdb_load_segment_header_fields),SX_BE};
static bool sx_dm_rdb_block(sx_context*c,uint64_t p,uint32_t block,uint8_t*h,size_t z){if(!sx_dm_read(c,p,h,z))return false;uint64_t count=sx_dm_u32(h,4,true);if(count<5||count>block/4||!sx_dm_span(c,p,count*4))return false;uint32_t sum=0;for(uint64_t i=0;i<count;i++){uint32_t word;if(!sx_u32(c,(int64_t)(p+i*4),true,&word))return false;sum+=word;}return sum==0;}
static bool sx_dm_rdb_lseg(sx_context*c,uint32_t block,uint32_t next){for(unsigned i=0;next!=UINT32_MAX&&i<16384&&c->count<24000;i++){uint64_t p=(uint64_t)block*next;uint8_t h[20];if(!sx_dm_rdb_block(c,p,block,h,20)||xx_rt_memcmp(h,"LSEG",4))break;size_t old=c->count;if(!sx_dm_add(c,&sx_dm_rdb_load_segment_header,p,20))return false;if(c->count==old)break;next=sx_dm_u32(h,16,true);}return true;}
static bool sx_dm_rdb(sx_context*c){uint8_t h[256];uint64_t p;uint32_t block=0,part=UINT32_MAX,fs=UINT32_MAX;for(p=0;p<8192;p+=512){if(!sx_dm_read(c,p,h,256))break;if(xx_rt_memcmp(h,"RDSK",4))continue;uint32_t b=sx_dm_u32(h,16,true);if(b<256||b>65536||(b&(b-1))||p%b||!sx_dm_rdb_block(c,p,b,h,256))continue;block=b;part=sx_dm_u32(h,28,true);fs=sx_dm_u32(h,32,true);if(!sx_dm_add(c,&sx_dm_rdb_rigid_disk_block,p,256))return false;break;}if(!block)return false;
 for(unsigned kind=0;kind<2;kind++){uint32_t next=kind?fs:part;for(unsigned i=0;next!=UINT32_MAX&&i<(kind?64U:128U);i++){p=(uint64_t)block*next;uint32_t z=kind?80:256;if(!sx_dm_rdb_block(c,p,block,h,z)||xx_rt_memcmp(h,kind?"FSHD":"PART",4))break;size_t old=c->count;if(!sx_dm_add(c,kind?&sx_dm_rdb_filesystem_header:&sx_dm_rdb_partition_block,p,z))return false;if(c->count==old)break;next=sx_dm_u32(h,16,true);if(kind&&!sx_dm_rdb_lseg(c,block,sx_dm_u32(h,72,true)))return false;}}
 return true;}
bool sx_rdb_build(sx_context*c)
{
 return sx_dm_rdb(c);
}
