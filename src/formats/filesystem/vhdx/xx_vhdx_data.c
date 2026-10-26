/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VHDX data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_vhdx_file_identifier_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("creator_utf16","uint16[256]",8,512,SX_NONE),
};
const sx_layout sx_dm_vhdx_file_identifier = {0x60290001U,"vhdx_file_identifier",sx_dm_vhdx_file_identifier_fields,SX_COUNT(sx_dm_vhdx_file_identifier_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_header_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("file_write_guid","byte[16]",16,16,SX_ID),
    SX_FIELD("data_write_guid","byte[16]",32,16,SX_ID),
    SX_FIELD("log_guid","byte[16]",48,16,SX_ID),
    SX_FIELD("log_version","uint16",64,2,SX_NONE),
    SX_FIELD("version","uint16",66,2,SX_NONE),
    SX_FIELD("log_length","uint32",68,4,SX_SIZE),
    SX_FIELD("log_offset","uint64",72,8,SX_OFFSET),
    SX_FIELD("reserved","byte[4016]",80,4016,SX_RESERVED),
};
const sx_layout sx_dm_vhdx_header = {0x60290002U,"vhdx_header",sx_dm_vhdx_header_fields,SX_COUNT(sx_dm_vhdx_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_region_table_header_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sx_dm_vhdx_region_table_header = {0x60290003U,"vhdx_region_table_header",sx_dm_vhdx_region_table_header_fields,SX_COUNT(sx_dm_vhdx_region_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_region_table_entry_fields[] = {
    SX_FIELD("guid","byte[16]",0,16,SX_ID),
    SX_FIELD("file_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("length","uint32",24,4,SX_SIZE),
    SX_FIELD("flags","uint32",28,4,SX_FLAGS),
};
const sx_layout sx_dm_vhdx_region_table_entry = {0x60290004U,"vhdx_region_table_entry",sx_dm_vhdx_region_table_entry_fields,SX_COUNT(sx_dm_vhdx_region_table_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_metadata_table_header_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("reserved1","uint16",8,2,SX_RESERVED),
    SX_FIELD("entry_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("reserved2","byte[20]",12,20,SX_RESERVED),
};
const sx_layout sx_dm_vhdx_metadata_table_header = {0x60290005U,"vhdx_metadata_table_header",sx_dm_vhdx_metadata_table_header_fields,SX_COUNT(sx_dm_vhdx_metadata_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_file_parameters_fields[] = {
    SX_FIELD("block_size","uint32",0,4,SX_SIZE),
    SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
const sx_layout sx_dm_vhdx_file_parameters = {0x60290007U,"vhdx_file_parameters",sx_dm_vhdx_file_parameters_fields,SX_COUNT(sx_dm_vhdx_file_parameters_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_disk_size_fields[] = {
    SX_FIELD("virtual_disk_size","uint64",0,8,SX_SIZE),
};
const sx_layout sx_dm_vhdx_disk_size = {0x60290008U,"vhdx_disk_size",sx_dm_vhdx_disk_size_fields,SX_COUNT(sx_dm_vhdx_disk_size_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_logical_sector_size_fields[] = {
    SX_FIELD("logical_sector_size","uint32",0,4,SX_SIZE),
};
const sx_layout sx_dm_vhdx_logical_sector_size = {0x60290009U,"vhdx_logical_sector_size",sx_dm_vhdx_logical_sector_size_fields,SX_COUNT(sx_dm_vhdx_logical_sector_size_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_physical_sector_size_fields[] = {
    SX_FIELD("physical_sector_size","uint32",0,4,SX_SIZE),
};
const sx_layout sx_dm_vhdx_physical_sector_size = {0x6029000aU,"vhdx_physical_sector_size",sx_dm_vhdx_physical_sector_size_fields,SX_COUNT(sx_dm_vhdx_physical_sector_size_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_virtual_disk_id_fields[] = {
    SX_FIELD("virtual_disk_id","byte[16]",0,16,SX_ID),
};
const sx_layout sx_dm_vhdx_virtual_disk_id = {0x6029000bU,"vhdx_virtual_disk_id",sx_dm_vhdx_virtual_disk_id_fields,SX_COUNT(sx_dm_vhdx_virtual_disk_id_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_parent_locator_fields[] = {
    SX_FIELD("locator_type","byte[16]",0,16,SX_ID),
    SX_FIELD("reserved","uint16",16,2,SX_RESERVED),
    SX_FIELD("key_value_count","uint16",18,2,SX_COUNT_PROP),
};
const sx_layout sx_dm_vhdx_parent_locator = {0x6029000cU,"vhdx_parent_locator",sx_dm_vhdx_parent_locator_fields,SX_COUNT(sx_dm_vhdx_parent_locator_fields),SX_LE};
static const uint8_t sx_dm_guid_bat[16] = {0x66, 0x77, 0xC2, 0x2D, 0x23, 0xF6, 0x00, 0x42, 0x9D, 0x64, 0x11, 0x5E, 0x9B, 0xFD, 0x4A, 0x08};
static const uint8_t sx_dm_guid_metadata[16] = {0x06, 0xA2, 0x7C, 0x8B, 0x90, 0x47, 0x9A, 0x4B, 0xB8, 0xFE, 0x57, 0x5F, 0x05, 0x0F, 0x88, 0x6E};
static const uint8_t sx_dm_guid_file_parameters[16] = {0x37, 0x67, 0xA1, 0xCA, 0x36, 0xFA, 0x43, 0x4D, 0xB3, 0xB6, 0x33, 0xF0, 0xAA, 0x44, 0xE7, 0x6B};
static const uint8_t sx_dm_guid_disk_size[16] = {0x24, 0x42, 0xA5, 0x2F, 0x1B, 0xCD, 0x76, 0x48, 0xB2, 0x11, 0x5D, 0xBE, 0xD8, 0x3B, 0xF4, 0xB8};
static const uint8_t sx_dm_guid_disk_id[16] = {0xAB, 0x12, 0xCA, 0xBE, 0xE6, 0xB2, 0x23, 0x45, 0x93, 0xEF, 0xC3, 0x09, 0xE0, 0x00, 0xC7, 0x46};
static const uint8_t sx_dm_guid_logical_sector[16] = {0x1D, 0xBF, 0x41, 0x81, 0x6F, 0xA9, 0x09, 0x47, 0xBA, 0x47, 0xF2, 0x33, 0xA8, 0xFA, 0xAB, 0x5F};
static const uint8_t sx_dm_guid_physical_sector[16] = {0xC7, 0x48, 0xA3, 0xCD, 0x5D, 0x44, 0x71, 0x44, 0x9C, 0xC9, 0xE9, 0x88, 0x52, 0x51, 0xC5, 0x56};
static const uint8_t sx_dm_guid_parent_locator[16] = {0x2D, 0x5F, 0xD3, 0xA8, 0x0B, 0xB3, 0x4D, 0x45, 0xAB, 0xF7, 0xD3, 0xD8, 0x48, 0x34, 0xAB, 0x0C};
static bool sx_dm_vhdx_metadata(sx_context*c,uint64_t p,uint64_t z,uint64_t bat,uint64_t batsz){uint8_t h[32],v[20];if(z<65536||!sx_dm_read(c,p,h,32)||xx_rt_memcmp(h,"metadata",8))return true;uint32_t n=sx_dm_u16(h,10,false);if(n>2047||32+(uint64_t)n*32>z)return true;if(!sx_dm_add(c,&sx_dm_vhdx_metadata_table_header,p,32)||!sx_dm_table(c,&sx_dm_vhdx_metadata_table_entry,p+32,32,n))return false;uint64_t disk=0;uint32_t block=0,logical=0,flags=0;
 for(uint32_t i=0;i<n;i++){if(!sx_dm_read(c,p+32+i*32,h,32))return false;uint64_t o=sx_dm_u32(h,16,false),len=sx_dm_u32(h,20,false);if(o<65536||o>z||len>z-o||!sx_dm_span(c,p+o,len)||(sx_dm_u32(h,24,false)&1))continue;const sx_layout*l=NULL;uint32_t need=0;
  if(!xx_rt_memcmp(h,sx_dm_guid_file_parameters,16)){l=&sx_dm_vhdx_file_parameters;need=8;if(len==8&&sx_dm_read(c,p+o,v,8)){block=sx_dm_u32(v,0,false);flags=sx_dm_u32(v,4,false);}}
  else if(!xx_rt_memcmp(h,sx_dm_guid_disk_size,16)){l=&sx_dm_vhdx_disk_size;need=8;if(len==8&&sx_dm_read(c,p+o,v,8))disk=sx_dm_u64(v,0,false);}
  else if(!xx_rt_memcmp(h,sx_dm_guid_logical_sector,16)){l=&sx_dm_vhdx_logical_sector_size;need=4;if(len==4&&sx_dm_read(c,p+o,v,4))logical=sx_dm_u32(v,0,false);}
  else if(!xx_rt_memcmp(h,sx_dm_guid_physical_sector,16)){l=&sx_dm_vhdx_physical_sector_size;need=4;}
  else if(!xx_rt_memcmp(h,sx_dm_guid_disk_id,16)){l=&sx_dm_vhdx_virtual_disk_id;need=16;}
  else if(!xx_rt_memcmp(h,sx_dm_guid_parent_locator,16)&&len>=20&&sx_dm_read(c,p+o,v,20)){uint32_t cnt=sx_dm_u16(v,18,false);if(20+(uint64_t)cnt*12<=len){if(!sx_dm_add(c,&sx_dm_vhdx_parent_locator,p+o,20)||!sx_dm_table(c,&sx_dm_vhdx_parent_locator_entry,p+o+20,12,cnt))return false;}}
  if(l&&len==need&&!sx_dm_add(c,l,p+o,need))return false;
 }
 if(block>=1048576&&block<=268435456&&(logical==512||logical==4096)&&disk&&disk<=UINT64_C(64)<<40){uint64_t blocks=(disk-1)/block+1,ratio=((uint64_t)logical<<23)/block;uint64_t entries=(flags&2)?((blocks-1)/ratio+1)*(ratio+1):blocks+(blocks-1)/ratio;if(entries<=batsz/8&&sx_dm_span(c,bat,entries*8)&&!sx_dm_table(c,&sx_dm_vhdx_bat_entry,bat,8,entries))return false;}return true;}
static bool sx_dm_vhdx(sx_context*c){uint8_t h[32];if(!sx_dm_read(c,0,h,8)||xx_rt_memcmp(h,"vhdxfile",8)||!sx_dm_add(c,&sx_dm_vhdx_file_identifier,0,520))return false;
 for(unsigned i=1;i<=2;i++){uint64_t p=(uint64_t)i*65536;if(sx_dm_read(c,p,h,8)&&!xx_rt_memcmp(h,"head",4)&&sx_dm_span(c,p,4096)&&!sx_dm_add(c,&sx_dm_vhdx_header,p,4096))return false;}
 for(unsigned copy=3;copy<=4;copy++){uint64_t p=(uint64_t)copy*65536;if(!sx_dm_read(c,p,h,16)||xx_rt_memcmp(h,"regi",4)||!sx_dm_crc(c,p,65536,sx_dm_u32(h,4,false),true,false,true))continue;uint32_t n=sx_dm_u32(h,8,false);if(n>2047)continue;if(!sx_dm_add(c,&sx_dm_vhdx_region_table_header,p,16)||!sx_dm_table(c,&sx_dm_vhdx_region_table_entry,p+16,32,n))return false;uint64_t bat=0,batsz=0,meta=0,metasz=0;
  for(uint32_t i=0;i<n;i++){if(!sx_dm_read(c,p+16+i*32,h,32))return false;uint64_t o=sx_dm_u64(h,16,false),z=sx_dm_u32(h,24,false);if(!sx_dm_span(c,o,z))continue;if(!xx_rt_memcmp(h,sx_dm_guid_bat,16)){bat=o;batsz=z;}if(!xx_rt_memcmp(h,sx_dm_guid_metadata,16)){meta=o;metasz=z;}}
  if(meta&&!sx_dm_vhdx_metadata(c,meta,metasz,bat,batsz))return false;
 }return true;}
bool sx_vhdx_build(sx_context*c)
{
 return sx_dm_vhdx(c);
}
