/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SFX VMS DCX data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_dcx_ftsv_header_fields[]={
 SX_FIELD("signature","char[32]",0,32,SX_SIGNATURE),
 SX_FIELD("fdl_uncompressed_size","uint16",32,2,SX_SIZE),
 SX_FIELD("group_marker","uint32",34,4,SX_ID),
 SX_FIELD("table_size_copy","uint32",38,4,SX_SIZE),
};
const sx_layout sxaend_dcx_ftsv_header={UINT32_C(0x6084001c),"dcx_ftsv_header",sxaend_dcx_ftsv_header_fields,SX_COUNT(sxaend_dcx_ftsv_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_table_fields[]={
 SX_FIELD("table_size","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved_4","uint32",4,4,SX_RESERVED),
 SX_FIELD("signature","uint32",8,4,SX_SIGNATURE),
 SX_FIELD("reserved_12","uint32",12,4,SX_RESERVED),
 SX_FIELD("context_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("header_size","uint16",18,2,SX_SIZE),
};
const sx_layout sxaend_dcx_ftsv_table={UINT32_C(0x6084001d),"dcx_ftsv_table",sxaend_dcx_ftsv_table_fields,SX_COUNT(sxaend_dcx_ftsv_table_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_context_fields[]={
 SX_FIELD("context_size","uint16",0,2,SX_SIZE),
 SX_FIELD("first_symbol","uint8",2,1,SX_NONE),
 SX_FIELD("last_symbol","uint8",3,1,SX_NONE),
 SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("nodes_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("map_offset","uint16",10,2,SX_OFFSET),
};
const sx_layout sxaend_dcx_ftsv_context={UINT32_C(0x6084001e),"dcx_ftsv_context",sxaend_dcx_ftsv_context_fields,SX_COUNT(sxaend_dcx_ftsv_context_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_leaf_bitmap_fields[]={
 SX_FIELD("dcx_ftsv_leaf_bitmap","uint8",0,0,SX_NONE),
};
const sx_layout sxaend_dcx_ftsv_leaf_bitmap={UINT32_C(0x6084001f),"dcx_ftsv_leaf_bitmap",sxaend_dcx_ftsv_leaf_bitmap_fields,SX_COUNT(sxaend_dcx_ftsv_leaf_bitmap_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_nodes_fields[]={
 SX_FIELD("dcx_ftsv_nodes","uint8",0,0,SX_NONE),
};
const sx_layout sxaend_dcx_ftsv_nodes={UINT32_C(0x60840020),"dcx_ftsv_nodes",sxaend_dcx_ftsv_nodes_fields,SX_COUNT(sxaend_dcx_ftsv_nodes_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_map_fields[]={
 SX_FIELD("next_context","uint16",0,2,SX_NONE),
};
const sx_layout sxaend_dcx_ftsv_map={UINT32_C(0x60840021),"dcx_ftsv_map",sxaend_dcx_ftsv_map_fields,SX_COUNT(sxaend_dcx_ftsv_map_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_first_frame_fields[]={
 SX_FIELD("group_marker","uint32",0,4,SX_ID),
 SX_FIELD("packed_size","uint16",4,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxaend_dcx_ftsv_first_frame={UINT32_C(0x60840022),"dcx_ftsv_first_frame",sxaend_dcx_ftsv_first_frame_fields,SX_COUNT(sxaend_dcx_ftsv_first_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_second_group_fields[]={
 SX_FIELD("end_marker","uint32",0,4,SX_ID),
 SX_FIELD("begin_marker","uint32",4,4,SX_ID),
 SX_FIELD("table_size_copy","uint32",8,4,SX_SIZE),
};
const sx_layout sxaend_dcx_ftsv_second_group={UINT32_C(0x60840023),"dcx_ftsv_second_group",sxaend_dcx_ftsv_second_group_fields,SX_COUNT(sxaend_dcx_ftsv_second_group_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_frame_fields[]={
 SX_FIELD("frame_marker","uint16",0,2,SX_ID),
 SX_FIELD("packed_size","uint16",2,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",4,2,SX_SIZE),
};
const sx_layout sxaend_dcx_ftsv_frame={UINT32_C(0x60840024),"dcx_ftsv_frame",sxaend_dcx_ftsv_frame_fields,SX_COUNT(sxaend_dcx_ftsv_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_group_start_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
};
const sx_layout sxaend_dcx_ftsv_group_start={UINT32_C(0x60840025),"dcx_ftsv_group_start",sxaend_dcx_ftsv_group_start_fields,SX_COUNT(sxaend_dcx_ftsv_group_start_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_dcx_ftsv_group_end_fields[]={
 SX_FIELD("marker","uint32",0,4,SX_ID),
};
const sx_layout sxaend_dcx_ftsv_group_end={UINT32_C(0x60840026),"dcx_ftsv_group_end",sxaend_dcx_ftsv_group_end_fields,SX_COUNT(sxaend_dcx_ftsv_group_end_fields),SX_LE};
#define SXAEND_LIMIT 20000U
static bool sxaend_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n){if(!width||p>(uint64_t)c->size||n>(((uint64_t)c->size-p)/width))return false;for(uint64_t i=0;i<n;i++)if(!sxaend_add(c,l,p+i*width))return false;return true;}
static bool sxaend_dcx_table(sx_context*c,uint64_t p,uint64_t*end,bool emit){uint8_t h[20];if(!sxaend_read(c,p,h,20))return false;uint64_t z=sxaend_uint(h,4,false),n=sxaend_uint(h+16,2,false);if(z<20||z>1048576||!n||n>256||!sxaend_span(c,p,z)||sxaend_uint(h+8,4,false)!=0x5bf5a3a7||sxaend_uint(h+18,2,false)!=20)return false;if(emit&&!sxaend_add(c,&sxaend_dcx_ftsv_table,p))return false;*end=p+z;p+=20;for(uint64_t i=0;i<n;i++){uint8_t b[12];if(*end-p<12||!sxaend_read(c,p,b,12))return false;uint64_t len=sxaend_uint(b,2,false),nodes=sxaend_uint(b+8,2,false),map=sxaend_uint(b+10,2,false),nodeend=map?map:len;if(len>*end-p||nodes<=12||nodes-12>64||nodeend<=nodes||nodeend>len||nodeend-nodes>512||b[2]>b[3]||(map&&len-map!=2*(uint64_t)(b[3]-b[2]+1)))return false;if(emit&&(!sxaend_add(c,&sxaend_dcx_ftsv_context,p)||!sxaend_text(c,&sxaend_dcx_ftsv_leaf_bitmap,p+12,nodes-12,false)||!sxaend_text(c,&sxaend_dcx_ftsv_nodes,p+nodes,nodeend-nodes,false)||(map&&!sxaend_table(c,&sxaend_dcx_ftsv_map,p+map,2,b[3]-b[2]+1))))return false;p+=len;}return p==*end;}
static bool sxaend_dcx(sx_context*c){uint64_t payload,payloadz;if(!sxaend_first_source(c,&payload,&payloadz))return false;uint64_t cap=(uint64_t)c->size<1048576?(uint64_t)c->size:1048576;for(uint64_t p=0;p+42<=cap;p++){uint8_t h[42];if((p&4095)==0&&xx_pd_is_stopped(c->pd))return false;if(!sxaend_read(c,p,h,1))return false;if(h[0]!='O')continue;if(!sxaend_read(c,p,h,42)||xx_rt_memcmp(h,"OpenVMS DCX FTSV Compressed File",32))continue;uint64_t end;if(!sxaend_dcx_table(c,p+42,&end,false)||end+8!=payload)continue;if(!sxaend_add(c,&sxaend_dcx_ftsv_header,p)||!sxaend_dcx_table(c,p+42,&end,true)||!sxaend_add(c,&sxaend_dcx_ftsv_first_frame,end))return false;uint64_t next=payload+payloadz;if(!sxaend_add(c,&sxaend_dcx_ftsv_second_group,next)||!sxaend_dcx_table(c,next+12,&end,true)||!sxaend_add(c,&sxaend_dcx_ftsv_group_start,end))return false;end+=2;for(unsigned i=0;end+4<(uint64_t)c->size&&i<SXAEND_LIMIT;i++){uint64_t z;if(!sxaend_word(c,end+2,2,false,&z)||!z||!sxaend_span(c,end+6,z)||!sxaend_add(c,&sxaend_dcx_ftsv_frame,end))return false;end+=6+z;}return end+4==(uint64_t)c->size&&sxaend_add(c,&sxaend_dcx_ftsv_group_end,end);}return false;}
bool sx_sfx_vms_dcx_build(sx_context*c)
{
 return sxaend_dcx(c);
}
