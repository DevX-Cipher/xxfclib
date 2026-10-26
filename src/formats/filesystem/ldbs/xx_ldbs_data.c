/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LibDsk LDBS disk image data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_ldbs_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("subtype","byte[4]",4,4,SX_SIGNATURE),
    SX_FIELD("used_head_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("free_head_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("track_directory_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxdleg_ldbs_header = {0x6075000aU,"ldbs_header",sxdleg_ldbs_header_fields,SX_COUNT(sxdleg_ldbs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_block_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("block_type","byte[4]",4,4,SX_ID),
    SX_FIELD("allocated_size","uint32",8,4,SX_SIZE),
    SX_FIELD("used_size","uint32",12,4,SX_SIZE),
    SX_FIELD("next_block_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxdleg_ldbs_block_header = {0x6075000bU,"ldbs_block_header",sxdleg_ldbs_block_header_fields,SX_COUNT(sxdleg_ldbs_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_directory_header_fields[] = {
    SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxdleg_ldbs_directory_header = {0x6075000cU,"ldbs_directory_header",sxdleg_ldbs_directory_header_fields,SX_COUNT(sxdleg_ldbs_directory_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_directory_entry_fields[] = {
    SX_FIELD("block_type","byte[4]",0,4,SX_ID),
    SX_FIELD("block_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxdleg_ldbs_directory_entry = {0x6075000dU,"ldbs_directory_entry",sxdleg_ldbs_directory_entry_fields,SX_COUNT(sxdleg_ldbs_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_track_header_fields[] = {
    SX_FIELD("fixed_header_size","uint16",0,2,SX_SIZE),
    SX_FIELD("sector_descriptor_size","uint16",2,2,SX_SIZE),
    SX_FIELD("sector_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("data_rate","uint8",6,1,SX_ID),
    SX_FIELD("recording_mode","uint8",7,1,SX_ID),
    SX_FIELD("gap3_length","uint8",8,1,SX_SIZE),
    SX_FIELD("filler","uint8",9,1,SX_ID),
    SX_FIELD("track_length","uint16",10,2,SX_SIZE),
};
const sx_layout sxdleg_ldbs_track_header = {0x6075000eU,"ldbs_track_header",sxdleg_ldbs_track_header_fields,SX_COUNT(sxdleg_ldbs_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_sector16_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("status1","uint8",4,1,SX_FLAGS),
    SX_FIELD("status2","uint8",5,1,SX_FLAGS),
    SX_FIELD("copies","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("filler","uint8",7,1,SX_ID),
    SX_FIELD("data_block_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("trailing_size","uint16",12,2,SX_SIZE),
    SX_FIELD("track_offset","uint16",14,2,SX_OFFSET),
};
const sx_layout sxdleg_ldbs_sector16 = {0x6075000fU,"ldbs_sector16",sxdleg_ldbs_sector16_fields,SX_COUNT(sxdleg_ldbs_sector16_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_sector18_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("status1","uint8",4,1,SX_FLAGS),
    SX_FIELD("status2","uint8",5,1,SX_FLAGS),
    SX_FIELD("copies","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("filler","uint8",7,1,SX_ID),
    SX_FIELD("data_block_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("trailing_size","uint16",12,2,SX_SIZE),
    SX_FIELD("track_offset","uint16",14,2,SX_OFFSET),
    SX_FIELD("data_size","uint16",16,2,SX_SIZE),
};
const sx_layout sxdleg_ldbs_sector18 = {0x60750010U,"ldbs_sector18",sxdleg_ldbs_sector18_fields,SX_COUNT(sxdleg_ldbs_sector18_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_geometry_fields[] = {
    SX_FIELD("sidedness","uint8",0,1,SX_ID),
    SX_FIELD("cylinder_count","uint16",1,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("first_sector_id","uint8",5,1,SX_ID),
    SX_FIELD("sector_size","uint16",6,2,SX_SIZE),
    SX_FIELD("data_rate","uint8",8,1,SX_ID),
    SX_FIELD("read_write_gap","uint8",9,1,SX_SIZE),
    SX_FIELD("format_gap","uint8",10,1,SX_SIZE),
    SX_FIELD("recording_mode","uint8",11,1,SX_ID),
    SX_FIELD("complement_flag","uint8",12,1,SX_FLAGS),
    SX_FIELD("no_multitrack","uint8",13,1,SX_FLAGS),
    SX_FIELD("no_skip_deleted","uint8",14,1,SX_FLAGS),
};
const sx_layout sxdleg_ldbs_geometry = {0x60750011U,"ldbs_geometry",sxdleg_ldbs_geometry_fields,SX_COUNT(sxdleg_ldbs_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_track_directory_entry_fields[] = {
    SX_FIELD("block_kind","uint8",0,1,SX_ID),
    SX_FIELD("cylinder","uint16",1,2,SX_NONE),
    SX_FIELD("head","uint8",3,1,SX_NONE),
    SX_FIELD("block_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxdleg_ldbs_track_directory_entry = {0x60750049U,"ldbs_track_directory_entry",sxdleg_ldbs_track_directory_entry_fields,SX_COUNT(sxdleg_ldbs_track_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_track_block_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("block_kind","uint8",4,1,SX_ID),
    SX_FIELD("cylinder","uint16",5,2,SX_NONE),
    SX_FIELD("head","uint8",7,1,SX_NONE),
    SX_FIELD("allocated_size","uint32",8,4,SX_SIZE),
    SX_FIELD("used_size","uint32",12,4,SX_SIZE),
    SX_FIELD("next_block_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxdleg_ldbs_track_block_header = {0x6075004aU,"ldbs_track_block_header",sxdleg_ldbs_track_block_header_fields,SX_COUNT(sxdleg_ldbs_track_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ldbs_sector_block_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("block_kind","uint8",4,1,SX_ID),
    SX_FIELD("cylinder","uint8",5,1,SX_NONE),
    SX_FIELD("head","uint8",6,1,SX_NONE),
    SX_FIELD("sector_id","uint8",7,1,SX_ID),
    SX_FIELD("allocated_size","uint32",8,4,SX_SIZE),
    SX_FIELD("used_size","uint32",12,4,SX_SIZE),
    SX_FIELD("next_block_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxdleg_ldbs_sector_block_header = {0x6075004bU,"ldbs_sector_block_header",sxdleg_ldbs_sector_block_header_fields,SX_COUNT(sxdleg_ldbs_sector_block_header_fields),SX_LE};
#define SXDLEG_LIMIT 24000U
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_ldbs(sx_context*c){uint8_t h[20],b[18];if(!sxdleg_read(c,0,h,20)||xx_rt_memcmp(h,"LBS\1DSK\2",8)||!SXDLEG_ADD(c,ldbs_header,0))return false;
 for(uint64_t p=20,walk=0;walk<32768&&p<(uint64_t)c->size&&c->count<SXDLEG_LIMIT;walk++){if(!sxdleg_read(c,p,h,20)||xx_rt_memcmp(h,"LDB\1",4))break;uint32_t alloc=sxdleg32(h+8,0),used=sxdleg32(h+12,0);if(used>alloc||!sxdleg_span(c,p+20,alloc))break;if(!sxdleg_put(c,h[4]=='T'?&sxdleg_ldbs_track_block_header:h[4]=='S'?&sxdleg_ldbs_sector_block_header:&sxdleg_ldbs_block_header,p,1))return false;uint64_t q=p+20;
 if(!xx_rt_memcmp(h+4,"DIR\1",4)&&used>=2&&sxdleg_read(c,q,b,2)){unsigned n=sxdleg16(b,0);if(n<=(used-2)/8){if(!SXDLEG_ADD(c,ldbs_directory_header,q))return false;for(unsigned j=0;j<n;j++){uint8_t tag;if(!sxdleg_read(c,q+2+(uint64_t)j*8,&tag,1))return false;if(!sxdleg_put(c,tag=='T'?&sxdleg_ldbs_track_directory_entry:&sxdleg_ldbs_directory_entry,q+2+(uint64_t)j*8,1))return false;}}}
 else if(h[4]=='T'&&used>=12&&sxdleg_read(c,q,b,12)){unsigned z=sxdleg16(b,0),step=sxdleg16(b+2,0),n=sxdleg16(b+4,0);if(z>=12&&z<=used&&step>=16&&n<=64&&n<=(used-z)/step){if(!SXDLEG_ADD(c,ldbs_track_header,q))return false;for(unsigned i=0;i<n;i++)if(!sxdleg_put(c,step>=18?&sxdleg_ldbs_sector18:&sxdleg_ldbs_sector16,q+z+(uint64_t)i*step,1))return false;}}
 else if(!xx_rt_memcmp(h+4,"GEOM",4)&&used>=15&&!SXDLEG_ADD(c,ldbs_geometry,q))return false;p=q+alloc;
 }return true;}
#undef SXDLEG_LIMIT
#undef SXDLEG_ADD
bool sx_ldbs_build(sx_context*c)
{
 return sxdleg_ldbs(c);
}
