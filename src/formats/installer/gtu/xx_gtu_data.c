/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GTU OS/2 distribution kits (*.csd, *.001, *.002) data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_gtu_header_fields[] = {
 SX_FIELD("file_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxafr_gtu_header = {UINT32_C(0x6054000e),"gtu_header",sxafr_gtu_header_fields,SX_COUNT(sxafr_gtu_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_record_fields[] = {
 SX_FIELD("block_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("tag","uint16",4,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",6,2,SX_NONE),
 SX_FIELD("reserved","uint16",8,2,SX_NONE),
 SX_FIELD("name_size","uint16",10,2,SX_SIZE),
};
const sx_layout sxafr_gtu_record = {UINT32_C(0x6054000f),"gtu_record",sxafr_gtu_record_fields,SX_COUNT(sxafr_gtu_record_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_terminator_fields[] = {
 SX_FIELD("self_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unused","uint8[8]",4,8,SX_NONE),
};
const sx_layout sxafr_gtu_terminator = {UINT32_C(0x60540010),"gtu_terminator",sxafr_gtu_terminator_fields,SX_COUNT(sxafr_gtu_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_info_fields[] = {
 SX_FIELD("dos_date","uint16",0,2,SX_NONE),
 SX_FIELD("dos_time","uint16",2,2,SX_NONE),
 SX_FIELD("opaque","uint8[8]",4,8,SX_NONE),
 SX_FIELD("uncompressed_size","int32",12,4,SX_SIZE),
 SX_FIELD("allocated_size","int32",16,4,SX_SIZE),
 SX_FIELD("attributes","uint32",20,4,SX_FLAGS),
 SX_FIELD("skip_size","int32",24,4,SX_SIZE),
};
const sx_layout sxafr_gtu_info = {UINT32_C(0x60540011),"gtu_info",sxafr_gtu_info_fields,SX_COUNT(sxafr_gtu_info_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_gtu_frame_fields[] = {
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
};
const sx_layout sxafr_gtu_frame = {UINT32_C(0x60540012),"gtu_frame",sxafr_gtu_frame_fields,SX_COUNT(sxafr_gtu_frame_fields),SX_LE};
#define SXAFR_LIMIT 20000U
static bool sxafr_gtu(sx_context*c){uint64_t p=4;if(!sxafr_add(c,&sxafr_gtu_header,0))return false;for(unsigned i=0;i<SXAFR_LIMIT;i++){uint8_t h[12];if(!sxafr_read(c,p,h,12))return false;uint64_t off=sxafr_uint(h,4,false),names=sxafr_uint(h+10,2,false);if(off==p)return sxafr_add(c,&sxafr_gtu_terminator,p);if(!names||names>4096||!sxafr_span(c,p+12,names)||!sxafr_span(c,off,12+names+28)||!sxafr_add(c,&sxafr_gtu_record,p)||!sxafr_add(c,&sxafr_gtu_record,off))return false;uint64_t q=off+12+names;uint8_t info[28];if(!sxafr_read(c,q,info,28)||!sxafr_add(c,&sxafr_gtu_info,q))return false;q+=28;uint64_t totals[2]={sxafr_uint(info+24,4,false),sxafr_uint(info+12,4,false)};for(unsigned phase=0;phase<2;phase++){uint64_t remaining=totals[phase];if(remaining>INT32_MAX)return false;while(remaining){uint8_t frame[8];if(!sxafr_read(c,q,frame,8))return false;uint64_t raw=sxafr_uint(frame,4,false),z=sxafr_uint(frame+4,4,false);if(!raw||raw>65536||raw>remaining||z>INT32_MAX||!sxafr_span(c,q+8,z)||!sxafr_add(c,&sxafr_gtu_frame,q))return false;remaining-=raw;q+=8+z;}}p+=12+names;}return true;}
bool sx_gtu_build(sx_context*c)
{
 return sxafr_gtu(c);
}
