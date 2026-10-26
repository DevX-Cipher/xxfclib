/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * INTERPLAY MVE data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_mve_header_fields[]={
 SX_FIELD("signature","bytes",0,20,SX_SIGNATURE),
 SX_FIELD("magic1","uint16",20,2,SX_SIGNATURE),
 SX_FIELD("magic2","uint16",22,2,SX_SIGNATURE),
 SX_FIELD("magic3","uint16",24,2,SX_SIGNATURE),
};
const sx_layout sxnx_mve_header={UINT32_C(0x603200B6),"mve_header",sxnx_mve_header_fields,SX_COUNT(sxnx_mve_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_chunk_fields[]={
 SX_FIELD("data_size","uint16",0,2,SX_SIZE),
 SX_FIELD("chunk_type","uint16",2,2,SX_ID),
};
const sx_layout sxnx_mve_chunk={UINT32_C(0x603200B7),"mve_chunk",sxnx_mve_chunk_fields,SX_COUNT(sxnx_mve_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_opcode_fields[]={
 SX_FIELD("data_size","uint16",0,2,SX_SIZE),
 SX_FIELD("opcode","uint8",2,1,SX_ID),
 SX_FIELD("version","uint8",3,1,SX_ID),
};
const sx_layout sxnx_mve_opcode={UINT32_C(0x603200B8),"mve_opcode",sxnx_mve_opcode_fields,SX_COUNT(sxnx_mve_opcode_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_timer_fields[]={
 SX_FIELD("microsecond_rate","uint32",0,4,SX_NONE),
 SX_FIELD("rate_divisor","uint16",4,2,SX_NONE),
};
const sx_layout sxnx_mve_timer={UINT32_C(0x603200B9),"mve_timer",sxnx_mve_timer_fields,SX_COUNT(sxnx_mve_timer_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_audio_init_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("sample_rate","uint16",4,2,SX_NONE),
};
const sx_layout sxnx_mve_audio_init={UINT32_C(0x603200BA),"mve_audio_init",sxnx_mve_audio_init_fields,SX_COUNT(sxnx_mve_audio_init_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_video_init_0_fields[]={
 SX_FIELD("width_8pixels","uint16",0,2,SX_NONE),
 SX_FIELD("height_8pixels","uint16",2,2,SX_NONE),
};
const sx_layout sxnx_mve_video_init_0={UINT32_C(0x603200BB),"mve_video_init_0",sxnx_mve_video_init_0_fields,SX_COUNT(sxnx_mve_video_init_0_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_video_init_1_fields[]={
 SX_FIELD("width_8pixels","uint16",0,2,SX_NONE),
 SX_FIELD("height_8pixels","uint16",2,2,SX_NONE),
 SX_FIELD("buffer_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxnx_mve_video_init_1={UINT32_C(0x603200BC),"mve_video_init_1",sxnx_mve_video_init_1_fields,SX_COUNT(sxnx_mve_video_init_1_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_video_init_2_fields[]={
 SX_FIELD("width_8pixels","uint16",0,2,SX_NONE),
 SX_FIELD("height_8pixels","uint16",2,2,SX_NONE),
 SX_FIELD("buffer_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("true_color","uint16",6,2,SX_FLAGS),
};
const sx_layout sxnx_mve_video_init_2={UINT32_C(0x603200BD),"mve_video_init_2",sxnx_mve_video_init_2_fields,SX_COUNT(sxnx_mve_video_init_2_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_send_buffer_fields[]={
 SX_FIELD("palette_start","uint16",0,2,SX_ID),
 SX_FIELD("palette_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("unknown","uint16",4,2,SX_NONE),
};
const sx_layout sxnx_mve_send_buffer={UINT32_C(0x603200BE),"mve_send_buffer",sxnx_mve_send_buffer_fields,SX_COUNT(sxnx_mve_send_buffer_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_audio_frame_fields[]={
 SX_FIELD("sequence_index","uint16",0,2,SX_ID),
 SX_FIELD("stream_mask","uint16",2,2,SX_FLAGS),
 SX_FIELD("unpacked_bytes","uint16",4,2,SX_SIZE),
};
const sx_layout sxnx_mve_audio_frame={UINT32_C(0x603200BF),"mve_audio_frame",sxnx_mve_audio_frame_fields,SX_COUNT(sxnx_mve_audio_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_video_mode_fields[]={
 SX_FIELD("width","uint16",0,2,SX_NONE),
 SX_FIELD("height","uint16",2,2,SX_NONE),
 SX_FIELD("flags","uint16",4,2,SX_FLAGS),
};
const sx_layout sxnx_mve_video_mode={UINT32_C(0x603200C0),"mve_video_mode",sxnx_mve_video_mode_fields,SX_COUNT(sxnx_mve_video_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mve_palette_fields[]={
 SX_FIELD("first_index","uint16",0,2,SX_ID),
 SX_FIELD("color_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxnx_mve_palette={UINT32_C(0x603200C1),"mve_palette",sxnx_mve_palette_fields,SX_COUNT(sxnx_mve_palette_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_mve(sxnx_view*v)
{if(!SN_ROW(mve_header,0,v->n))return false;size_t p=26;while(p<v->n){if(!SN_ROW(mve_chunk,p,v->n))return false;unsigned z=sxnx_u16(v->p+p,false);p+=4;if(!sxnx_need(v,p,z,v->n))return false;size_t end=p+z;
 while(p<end){if(!SN_ROW(mve_opcode,p,end))return false;unsigned n=sxnx_u16(v->p+p,false),op=v->p[p+2],version=v->p[p+3];p+=4;if(!sxnx_need(v,p,n,end))return false;const sx_layout*l=NULL;if(op==2)l=&sxnx_mve_timer;else if(op==3)l=&sxnx_mve_audio_init;else if(op==5){if(version>2)return false;l=version==0?&sxnx_mve_video_init_0:version==1?&sxnx_mve_video_init_1:&sxnx_mve_video_init_2;}else if(op==7)l=&sxnx_mve_send_buffer;else if(op==8||op==9)l=&sxnx_mve_audio_frame;else if(op==10)l=&sxnx_mve_video_mode;else if(op==12){if(!SN_ROW(mve_palette,p,p+n)||!sxnx_table(v,&sxnx_rgb_palette_entry,p+4,sxnx_u16(v->p+p+2,false),p+n))return false;}if(l&&!sxnx_row(v,l,p,p+n))return false;p+=n;}}return true;}
bool sx_interplay_mve_build(sxnx_view*v)
{
 return sxnx_mve(v);
}
#undef SN_ROW
