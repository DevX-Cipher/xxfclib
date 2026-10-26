/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TRS-80 JV1 data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_trs80_boot_directory_fields[] = {
    SX_FIELD("directory_track_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxdr_trs80_boot_directory = {0x607f0004U,"trs80_boot_directory",sxdr_trs80_boot_directory_fields,SX_COUNT(sxdr_trs80_boot_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_gat_track_fields[] = {
    SX_FIELD("allocated_granules","uint8",0,1,SX_FLAGS),
};
const sx_layout sxdr_trs80_gat_track = {0x607f0005U,"trs80_gat_track",sxdr_trs80_gat_track_fields,SX_COUNT(sxdr_trs80_gat_track_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_gat_identity_fields[] = {
    SX_FIELD("disk_name","char[8]",0,8,SX_NONE),
    SX_FIELD("date_text","char[8]",8,8,SX_NONE),
    SX_FIELD("auto_command","char[32]",16,32,SX_NONE),
};
const sx_layout sxdr_trs80_gat_identity = {0x607f0006U,"trs80_gat_identity",sxdr_trs80_gat_identity_fields,SX_COUNT(sxdr_trs80_gat_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_hit_fields[] = {
    SX_FIELD("filename_hash","uint8",0,1,SX_CHECKSUM),
};
const sx_layout sxdr_trs80_hit = {0x607f0007U,"trs80_hit",sxdr_trs80_hit_fields,SX_COUNT(sxdr_trs80_hit_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_primary_entry_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("month_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("day_year_flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("last_sector_bytes","uint8",3,1,SX_NONE),
    SX_FIELD("logical_record_length","uint8",4,1,SX_NONE),
    SX_FIELD("name","char[8]",5,8,SX_NONE),
    SX_FIELD("extension","char[3]",13,3,SX_NONE),
    SX_FIELD("update_password_hash","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("access_password_hash","uint16",18,2,SX_CHECKSUM),
    SX_FIELD("allocated_sectors","uint16",20,2,SX_COUNT_PROP),
};
const sx_layout sxdr_trs80_primary_entry = {0x607f0008U,"trs80_primary_entry",sxdr_trs80_primary_entry_fields,SX_COUNT(sxdr_trs80_primary_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_extended_entry_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("previous_entry_code","uint8",1,1,SX_ID),
    SX_FIELD("day_year_flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("last_sector_bytes","uint8",3,1,SX_NONE),
    SX_FIELD("logical_record_length","uint8",4,1,SX_NONE),
    SX_FIELD("name","char[8]",5,8,SX_NONE),
    SX_FIELD("extension","char[3]",13,3,SX_NONE),
    SX_FIELD("update_password_hash","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("access_password_hash","uint16",18,2,SX_CHECKSUM),
    SX_FIELD("allocated_sectors","uint16",20,2,SX_COUNT_PROP),
};
const sx_layout sxdr_trs80_extended_entry = {0x607f0009U,"trs80_extended_entry",sxdr_trs80_extended_entry_fields,SX_COUNT(sxdr_trs80_extended_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_extent_fields[] = {
    SX_FIELD("start_track","uint8",0,1,SX_NONE),
    SX_FIELD("granule_start_count","uint8",1,1,SX_FLAGS),
};
const sx_layout sxdr_trs80_extent = {0x607f000aU,"trs80_extent",sxdr_trs80_extent_fields,SX_COUNT(sxdr_trs80_extent_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_extent_link_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_ID),
    SX_FIELD("next_entry_code","uint8",1,1,SX_ID),
};
const sx_layout sxdr_trs80_extent_link = {0x607f000bU,"trs80_extent_link",sxdr_trs80_extent_link_fields,SX_COUNT(sxdr_trs80_extent_link_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_gat_lockout_fields[] = {
    SX_FIELD("lockout_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxdr_trs80_gat_lockout = {0x607f0026U,"trs80_gat_lockout",sxdr_trs80_gat_lockout_fields,SX_COUNT(sxdr_trs80_gat_lockout_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_trs80_gat_system_fields[] = {
    SX_FIELD("os_version","uint8",0,1,SX_ID),
    SX_FIELD("cylinders_minus_35","uint8",1,1,SX_NONE),
    SX_FIELD("geometry_flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("master_password_hash","uint16",3,2,SX_CHECKSUM),
};
const sx_layout sxdr_trs80_gat_system = {0x607f0027U,"trs80_gat_system",sxdr_trs80_gat_system_fields,SX_COUNT(sxdr_trs80_gat_system_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_trs(sx_context*c){uint8_t boot[3],e[32];if(c->size<5120||c->size%2560||c->size>96*2560||!sxdr_read(c,0,boot,3))return false;uint64_t track=boot[2]&127,tracks=c->size/2560,base=track*2560;if(!track||track>=tracks||!sxdr_span(c,base,2560))return false;
 if(!SXDR_ADD(c,trs80_boot_directory,2)||!sxdr_put(c,&sxdr_trs80_gat_track,base,tracks)||!sxdr_put(c,&sxdr_trs80_gat_lockout,base+96,tracks)||!SXDR_ADD(c,trs80_gat_system,base+203)||!SXDR_ADD(c,trs80_gat_identity,base+208)||!sxdr_put(c,&sxdr_trs80_hit,base+256,256))return false;
 for(uint64_t i=0;i<64;i++){uint64_t p=base+512+i*32;if(!sxdr_read(c,p,e,32))return false;if(!(e[0]&16))continue;if(!sxdr_put(c,(e[0]&128)?&sxdr_trs80_extended_entry:&sxdr_trs80_primary_entry,p,1))return false;for(unsigned j=0;j<5;j++){uint8_t a=e[22+j*2];if(a==255)break;if(j==4&&a==254){if(!SXDR_ADD(c,trs80_extent_link,p+30))return false;break;}if(!SXDR_ADD(c,trs80_extent,p+22+j*2))return false;}}return true;}
#undef SXDR_ADD
bool sx_trs_80_jv1_build(sx_context*c)
{
 return sxdr_trs(c);
}
