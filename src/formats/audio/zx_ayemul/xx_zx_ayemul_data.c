/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * zx_ayemul data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_ay_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("file_version","uint8",8,1,SX_ID),
 SX_FIELD("player_version","uint8",9,1,SX_ID),
 SX_FIELD("custom_player_relative","int16",10,2,SX_OFFSET),
 SX_FIELD("author_relative","int16",12,2,SX_OFFSET),
 SX_FIELD("comment_relative","int16",14,2,SX_OFFSET),
 SX_FIELD("track_count_minus_one","uint8",16,1,SX_NONE),
 SX_FIELD("first_track","uint8",17,1,SX_ID),
 SX_FIELD("track_table_relative","int16",18,2,SX_OFFSET),
};
const sx_layout sxau_ay_header={UINT32_C(0x602C004D),"ay_header",sxau_ay_header_fields,SX_COUNT(sxau_ay_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_track_index_fields[]={
 SX_FIELD("name_relative","int16",0,2,SX_OFFSET),
 SX_FIELD("descriptor_relative","int16",2,2,SX_OFFSET),
};
const sx_layout sxau_ay_track_index={UINT32_C(0x602C004E),"ay_track_index",sxau_ay_track_index_fields,SX_COUNT(sxau_ay_track_index_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_track_fields[]={
 SX_FIELD("channel_a","uint8",0,1,SX_ID),
 SX_FIELD("channel_b","uint8",1,1,SX_ID),
 SX_FIELD("channel_c","uint8",2,1,SX_ID),
 SX_FIELD("noise_channel","uint8",3,1,SX_ID),
 SX_FIELD("duration_frames","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("fade_frames","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("register_hi","uint8",8,1,SX_NONE),
 SX_FIELD("register_lo","uint8",9,1,SX_NONE),
 SX_FIELD("cpu_state_relative","int16",10,2,SX_OFFSET),
 SX_FIELD("block_index_relative","int16",12,2,SX_OFFSET),
};
const sx_layout sxau_ay_track={UINT32_C(0x602C004F),"ay_track",sxau_ay_track_fields,SX_COUNT(sxau_ay_track_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_cpu_state_fields[]={
 SX_FIELD("stack_pointer","uint16",0,2,SX_ADDRESS),
 SX_FIELD("init_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("interrupt_address","uint16",4,2,SX_ADDRESS),
};
const sx_layout sxau_ay_cpu_state={UINT32_C(0x602C0050),"ay_cpu_state",sxau_ay_cpu_state_fields,SX_COUNT(sxau_ay_cpu_state_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_block_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("payload_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("payload_relative","int16",4,2,SX_OFFSET),
};
const sx_layout sxau_ay_block={UINT32_C(0x602C0051),"ay_block",sxau_ay_block_fields,SX_COUNT(sxau_ay_block_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_blocks_end_fields[]={
 SX_FIELD("zero_address","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxau_ay_blocks_end={UINT32_C(0x602C0052),"ay_blocks_end",sxau_ay_blocks_end_fields,SX_COUNT(sxau_ay_blocks_end_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_ayptr(sxau_view*v,size_t at,size_t z,size_t*out)
{if(!sxau_need(v,at,2,v->n))return false;int64_t n=(int64_t)at+(int16_t)sxau_u16(v->p+at,true);if(n<20||!sxau_need(v,(size_t)n,z,v->n))return false;*out=(size_t)n;return true;}
static bool sxau_ay(sxau_view*v)
{if(!SA_ROW(ay_header,0,v->n))return false;size_t table;unsigned n=(unsigned)v->p[16]+1;if(!sxau_ayptr(v,18,n*4,&table)||!sxau_table(v,&sxau_ay_track_index,table,n,v->n))return false;for(unsigned i=0;i<n;i++){size_t desc,state,blocks;if(!sxau_ayptr(v,table+i*4+2,14,&desc)||!SA_ROW(ay_track,desc,v->n)||!sxau_ayptr(v,desc+10,6,&state)||!SA_ROW(ay_cpu_state,state,v->n)||!sxau_ayptr(v,desc+12,2,&blocks))return false;unsigned count=0;for(;;){if(!sxau_need(v,blocks,2,v->n))return false;if(!sxau_u16(v->p+blocks,true)){if(!SA_ROW(ay_blocks_end,blocks,v->n))return false;break;}if(count++>=256||!SA_ROW(ay_block,blocks,v->n))return false;blocks+=6;}}return true;}
bool sx_zx_ayemul_build(sxau_view*v)
{
 return sxau_ay(v);
}
#undef SA_ROW
