/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * hxc afi data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_afi_header_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version_major","uint8",16,1,SX_ID),
    SX_FIELD("version_minor","uint8",17,1,SX_ID),
    SX_FIELD("header_size","uint32",18,4,SX_SIZE),
    SX_FIELD("info_offset","uint32",22,4,SX_OFFSET),
    SX_FIELD("track_list_offset","uint32",26,4,SX_OFFSET),
    SX_FIELD("header_crc","uint16be",30,2,SX_CHECKSUM),
};
const sx_layout sxdleg_afi_header = {0x6075001eU,"afi_header",sxdleg_afi_header_fields,SX_COUNT(sxdleg_afi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_afi_info_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("info_size","uint32",16,4,SX_SIZE),
    SX_FIELD("media_type","uint32",20,4,SX_ID),
    SX_FIELD("platform_type","uint32",24,4,SX_ID),
    SX_FIELD("total_track_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("first_track","uint32",32,4,SX_NONE),
    SX_FIELD("last_track","uint32",36,4,SX_NONE),
    SX_FIELD("first_side","uint32",40,4,SX_NONE),
    SX_FIELD("last_side","uint32",44,4,SX_NONE),
    SX_FIELD("string_count","uint32",48,4,SX_COUNT_PROP),
};
const sx_layout sxdleg_afi_info = {0x6075001fU,"afi_info",sxdleg_afi_info_fields,SX_COUNT(sxdleg_afi_info_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_afi_string_offset_fields[] = {
    SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdleg_afi_string_offset = {0x60750020U,"afi_string_offset",sxdleg_afi_string_offset_fields,SX_COUNT(sxdleg_afi_string_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_afi_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdleg_afi_track_offset = {0x60750021U,"afi_track_offset",sxdleg_afi_track_offset_fields,SX_COUNT(sxdleg_afi_track_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_afi_data_offset_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdleg_afi_data_offset = {0x60750022U,"afi_data_offset",sxdleg_afi_data_offset_fields,SX_COUNT(sxdleg_afi_data_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_afi_crc_fields[] = {
    SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxdleg_afi_crc = {0x60750023U,"afi_crc",sxdleg_afi_crc_fields,SX_COUNT(sxdleg_afi_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxdleg_afi_string_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("string_type","char[16]",16,16,SX_ID),
    SX_FIELD("string_size","uint32",32,4,SX_SIZE),
};
const sx_layout sxdleg_afi_string = {0x60750024U,"afi_string",sxdleg_afi_string_fields,SX_COUNT(sxdleg_afi_string_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_afi_track_list_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("track_count","uint32",16,4,SX_COUNT_PROP),
};
const sx_layout sxdleg_afi_track_list = {0x60750025U,"afi_track_list",sxdleg_afi_track_list_fields,SX_COUNT(sxdleg_afi_track_list_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_afi_track_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("track_number","uint32",16,4,SX_NONE),
    SX_FIELD("side_number","uint32",20,4,SX_NONE),
    SX_FIELD("encoding_mode","uint32",24,4,SX_ID),
    SX_FIELD("element_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("chunk_count","uint32",32,4,SX_COUNT_PROP),
};
const sx_layout sxdleg_afi_track = {0x60750026U,"afi_track",sxdleg_afi_track_fields,SX_COUNT(sxdleg_afi_track_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_afi_data_fields[] = {
    SX_FIELD("tag","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("type_id","uint32",16,4,SX_ID),
    SX_FIELD("type_tag","char[16]",20,16,SX_ID),
    SX_FIELD("bits_per_element","uint32",36,4,SX_NONE),
    SX_FIELD("packed_size","uint32",40,4,SX_SIZE),
    SX_FIELD("packer","uint32",44,4,SX_ID),
    SX_FIELD("unpacked_size","uint32",48,4,SX_SIZE),
};
const sx_layout sxdleg_afi_data = {0x60750027U,"afi_data",sxdleg_afi_data_fields,SX_COUNT(sxdleg_afi_data_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static bool sxdleg_afi(sx_context*c){uint8_t h[54],e[4];if(!sxdleg_read(c,0,h,32)||xx_rt_memcmp(h,"AFI_FLOPPY_IMG",13)||!SXDLEG_ADD(c,afi_header,0))return false;uint64_t info=sxdleg32(h+22,0),list=sxdleg32(h+26,0);if(info<32||!sxdleg_read(c,info,h,54)||xx_rt_memcmp(h,"AFI_INFO",8))return true;uint32_t n=sxdleg32(h+48,0);if(n>256||!sxdleg_span(c,info,54+(uint64_t)n*4))return true;if(!SXDLEG_ADD(c,afi_info,info)||!SXDLEG_TABLE(c,afi_string_offset,info+52,n)||!SXDLEG_ADD(c,afi_crc,info+52+(uint64_t)n*4))return false;
 for(unsigned i=0;i<n;i++){if(!sxdleg_read(c,info+52+i*4,e,4))return false;uint64_t p=info+sxdleg32(e,0);if(!sxdleg_read(c,p,h,36)||xx_rt_memcmp(h,"STRING",6))continue;uint64_t z=sxdleg32(h+32,0);if(z>1048576||!sxdleg_span(c,p,38+z))continue;if(!SXDLEG_ADD(c,afi_string,p)||!SXDLEG_ADD(c,afi_crc,p+36+z))return false;}
 if(list<32||!sxdleg_read(c,list,h,20)||xx_rt_memcmp(h,"TRACKLIST",9))return true;n=sxdleg32(h+16,0);if(n>340||!sxdleg_span(c,list,22+(uint64_t)n*4))return true;if(!SXDLEG_ADD(c,afi_track_list,list)||!SXDLEG_TABLE(c,afi_track_offset,list+20,n)||!SXDLEG_ADD(c,afi_crc,list+20+(uint64_t)n*4))return false;
 for(unsigned i=0;i<n;i++){if(!sxdleg_read(c,list+20+i*4,e,4))return false;uint64_t p=list+sxdleg32(e,0);if(!sxdleg_read(c,p,h,36)||xx_rt_memcmp(h,"TRACK",5))continue;unsigned chunks=sxdleg32(h+32,0);if(chunks>16||!sxdleg_span(c,p,38+(uint64_t)chunks*4))continue;if(!SXDLEG_ADD(c,afi_track,p)||!SXDLEG_TABLE(c,afi_data_offset,p+36,chunks)||!SXDLEG_ADD(c,afi_crc,p+36+(uint64_t)chunks*4))return false;
 for(unsigned j=0;j<chunks;j++){if(!sxdleg_read(c,p+36+j*4,e,4))return false;uint64_t d=p+sxdleg32(e,0);if(!sxdleg_read(c,d,h,52)||xx_rt_memcmp(h,"TRACKDATA",9))continue;uint64_t z=sxdleg32(h+40,0);if(!sxdleg_span(c,d,54+z))continue;if(!SXDLEG_ADD(c,afi_data,d)||!SXDLEG_ADD(c,afi_crc,d+52+z))return false;}}
 return true;}
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
bool sx_hxc_afi_build(sx_context*c)
{
 return sxdleg_afi(c);
}
