/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SONY PAMF data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_pamf_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[4]",4,4,SX_ID),
 SX_FIELD("header_blocks","uint32",8,4,SX_NONE),
 SX_FIELD("data_blocks","uint32",12,4,SX_NONE),
 SX_FIELD("psmf_marks_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("psmf_marks_size","uint32",20,4,SX_SIZE),
 SX_FIELD("unknown_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("unknown_size","uint32",28,4,SX_SIZE),
 SX_FIELD("reserved","bytes",32,48,SX_RESERVED),
};
const sx_layout sxnx_pamf_header={UINT32_C(0x6032009C),"pamf_header",sxnx_pamf_header_fields,SX_COUNT(sxnx_pamf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_sequence_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
 SX_FIELD("start_pts_high","uint16",6,2,SX_NONE),
 SX_FIELD("start_pts_low","uint32",8,4,SX_NONE),
 SX_FIELD("end_pts_high","uint16",12,2,SX_NONE),
 SX_FIELD("end_pts_low","uint32",14,4,SX_NONE),
 SX_FIELD("mux_rate_bound","uint32",18,4,SX_NONE),
 SX_FIELD("std_delay_bound","uint32",22,4,SX_NONE),
 SX_FIELD("stream_count","uint32",26,4,SX_COUNT_PROP),
 SX_FIELD("reserved2","uint8",30,1,SX_RESERVED),
 SX_FIELD("grouping_period_count","uint8",31,1,SX_COUNT_PROP),
};
const sx_layout sxnx_pamf_sequence={UINT32_C(0x6032009D),"pamf_sequence",sxnx_pamf_sequence_fields,SX_COUNT(sxnx_pamf_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_period_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("start_pts_high","uint16",4,2,SX_NONE),
 SX_FIELD("start_pts_low","uint32",6,4,SX_NONE),
 SX_FIELD("end_pts_high","uint16",10,2,SX_NONE),
 SX_FIELD("end_pts_low","uint32",12,4,SX_NONE),
 SX_FIELD("reserved","uint8",16,1,SX_RESERVED),
 SX_FIELD("group_count","uint8",17,1,SX_COUNT_PROP),
};
const sx_layout sxnx_pamf_period={UINT32_C(0x6032009E),"pamf_period",sxnx_pamf_period_fields,SX_COUNT(sxnx_pamf_period_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_group_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved","uint8",4,1,SX_RESERVED),
 SX_FIELD("stream_count","uint8",5,1,SX_COUNT_PROP),
};
const sx_layout sxnx_pamf_group={UINT32_C(0x6032009F),"pamf_group",sxnx_pamf_group_fields,SX_COUNT(sxnx_pamf_group_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_stream_fields[]={
 SX_FIELD("coding_type","uint8",0,1,SX_ID),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("stream_id","uint8",4,1,SX_ID),
 SX_FIELD("private_stream_id","uint8",5,1,SX_ID),
 SX_FIELD("std_buffer_scale_size","uint16",6,2,SX_FLAGS),
 SX_FIELD("entry_point_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("entry_point_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxnx_pamf_stream={UINT32_C(0x603200A0),"pamf_stream",sxnx_pamf_stream_fields,SX_COUNT(sxnx_pamf_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_avc_fields[]={
 SX_FIELD("profile","uint8",0,1,SX_ID),
 SX_FIELD("level","uint8",1,1,SX_ID),
 SX_FIELD("frame_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("aspect_ratio_id","uint8",3,1,SX_ID),
 SX_FIELD("sar_width","uint16",4,2,SX_NONE),
 SX_FIELD("sar_height","uint16",6,2,SX_NONE),
 SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
 SX_FIELD("width_16pixels","uint8",9,1,SX_NONE),
 SX_FIELD("reserved2","uint8",10,1,SX_RESERVED),
 SX_FIELD("height_16pixels","uint8",11,1,SX_NONE),
 SX_FIELD("crop_left","uint16",12,2,SX_NONE),
 SX_FIELD("crop_right","uint16",14,2,SX_NONE),
 SX_FIELD("crop_top","uint16",16,2,SX_NONE),
 SX_FIELD("crop_bottom","uint16",18,2,SX_NONE),
 SX_FIELD("signal_flags","uint8",20,1,SX_FLAGS),
 SX_FIELD("color_primaries","uint8",21,1,SX_ID),
 SX_FIELD("transfer_characteristics","uint8",22,1,SX_ID),
 SX_FIELD("matrix_coefficients","uint8",23,1,SX_ID),
 SX_FIELD("coding_flags","uint8",24,1,SX_FLAGS),
 SX_FIELD("max_mean_bitrate","uint8",25,1,SX_NONE),
 SX_FIELD("unused_tail","bytes",26,6,SX_NONE),
};
const sx_layout sxnx_pamf_avc={UINT32_C(0x603200A1),"pamf_avc",sxnx_pamf_avc_fields,SX_COUNT(sxnx_pamf_avc_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_m2v_fields[]={
 SX_FIELD("profile_level","uint8",0,1,SX_FLAGS),
 SX_FIELD("unused","uint8",1,1,SX_NONE),
 SX_FIELD("frame_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("aspect_ratio_id","uint8",3,1,SX_ID),
 SX_FIELD("sar_width","uint16",4,2,SX_NONE),
 SX_FIELD("sar_height","uint16",6,2,SX_NONE),
 SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
 SX_FIELD("width_16pixels","uint8",9,1,SX_NONE),
 SX_FIELD("reserved2","uint8",10,1,SX_RESERVED),
 SX_FIELD("height_16pixels","uint8",11,1,SX_NONE),
 SX_FIELD("width","uint16",12,2,SX_NONE),
 SX_FIELD("height","uint16",14,2,SX_NONE),
 SX_FIELD("unused_word","uint32",16,4,SX_NONE),
 SX_FIELD("signal_flags","uint8",20,1,SX_FLAGS),
 SX_FIELD("color_primaries","uint8",21,1,SX_ID),
 SX_FIELD("transfer_characteristics","uint8",22,1,SX_ID),
 SX_FIELD("matrix_coefficients","uint8",23,1,SX_ID),
 SX_FIELD("unused_tail","bytes",24,8,SX_NONE),
};
const sx_layout sxnx_pamf_m2v={UINT32_C(0x603200A2),"pamf_m2v",sxnx_pamf_m2v_fields,SX_COUNT(sxnx_pamf_m2v_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_audio_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
 SX_FIELD("channel_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("sample_rate_code","uint8",3,1,SX_ID),
 SX_FIELD("bits_per_sample_code","uint8",4,1,SX_ID),
 SX_FIELD("unused_tail","bytes",5,27,SX_NONE),
};
const sx_layout sxnx_pamf_audio={UINT32_C(0x603200A3),"pamf_audio",sxnx_pamf_audio_fields,SX_COUNT(sxnx_pamf_audio_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pamf_userdata_fields[]={
 SX_FIELD("specific_info","bytes",0,32,SX_NONE),
};
const sx_layout sxnx_pamf_userdata={UINT32_C(0x603200A4),"pamf_userdata",sxnx_pamf_userdata_fields,SX_COUNT(sxnx_pamf_userdata_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_pamf_entry_point_fields[]={
 SX_FIELD("index_reference_picture_blocks","uint16",0,2,SX_FLAGS),
 SX_FIELD("pts_high","uint16",2,2,SX_NONE),
 SX_FIELD("pts_low","uint32",4,4,SX_NONE),
 SX_FIELD("relative_packet_blocks","uint32",8,4,SX_NONE),
};
const sx_layout sxnx_pamf_entry_point={UINT32_C(0x603200A5),"pamf_entry_point",sxnx_pamf_entry_point_fields,SX_COUNT(sxnx_pamf_entry_point_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_pamf(sxnx_view*v)
{if(!SN_ROW(pamf_header,0,v->n)||!SN_ROW(pamf_sequence,80,v->n)||!SN_ROW(pamf_period,112,v->n)||!SN_ROW(pamf_group,130,v->n))return false;unsigned n=v->p[135];if(n>32)return false;uint64_t header=(uint64_t)sxnx_u32(v->p+8,true)*2048;if(header>v->n)return false;for(unsigned i=0;i<n;i++){size_t p=136+i*48;if(!SN_ROW(pamf_stream,p,(size_t)header))return false;unsigned type=v->p[p];const sx_layout*l=type==0x1b?&sxnx_pamf_avc:type==2?&sxnx_pamf_m2v:type==0xdc||type==0x80||type==0x81?&sxnx_pamf_audio:&sxnx_pamf_userdata;if(!sxnx_row(v,l,p+16,(size_t)header)||!sxnx_table(v,&sxnx_pamf_entry_point,sxnx_u32(v->p+p+8,true),sxnx_u32(v->p+p+12,true),(size_t)header))return false;}return true;}
bool sx_sony_pamf_build(sxnx_view*v)
{
 return sxnx_pamf(v);
}
#undef SN_ROW
