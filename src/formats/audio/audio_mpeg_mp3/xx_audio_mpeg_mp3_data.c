/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * audio_mpeg_mp3 data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_mp3_frame_header_fields[]={
 SX_FIELD("sync_version_layer_protection","uint16",0,2,SX_FLAGS),
 SX_FIELD("bitrate_rate_padding_private","uint8",2,1,SX_FLAGS),
 SX_FIELD("channel_mode_extension_flags","uint8",3,1,SX_FLAGS),
};
const sx_layout sxau_mp3_frame_header={UINT32_C(0x602C002F),"mp3_frame_header",sxau_mp3_frame_header_fields,SX_COUNT(sxau_mp3_frame_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_id3_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("major_version","uint8",3,1,SX_ID),
 SX_FIELD("revision","uint8",4,1,SX_ID),
 SX_FIELD("flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("synchsafe_size","bytes",6,4,SX_NONE),
};
const sx_layout sxau_id3_header={UINT32_C(0x602C0030),"id3_header",sxau_id3_header_fields,SX_COUNT(sxau_id3_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_id3v23_frame_fields[]={
 SX_FIELD("frame_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
};
const sx_layout sxau_id3v23_frame={UINT32_C(0x602C0031),"id3v23_frame",sxau_id3v23_frame_fields,SX_COUNT(sxau_id3v23_frame_fields),SX_BE};
static const xx_data_struct_field_desc sxau_id3v24_frame_fields[]={
 SX_FIELD("frame_id","char[4]",0,4,SX_ID),
 SX_FIELD("synchsafe_size","bytes",4,4,SX_NONE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
};
const sx_layout sxau_id3v24_frame={UINT32_C(0x602C0032),"id3v24_frame",sxau_id3v24_frame_fields,SX_COUNT(sxau_id3v24_frame_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static uint32_t sxau_syncsafe(const uint8_t*p){return ((uint32_t)p[0]<<21)|((uint32_t)p[1]<<14)|((uint32_t)p[2]<<7)|p[3];}
static bool sxau_mp3(sxau_view*v)
{size_t at=0;if(v->n>=3&&!xx_rt_memcmp(v->p,"ID3",3)){if(!SA_ROW(id3_header,0,v->n))return false;size_t end=10+(size_t)sxau_syncsafe(v->p+6);if(end>v->n)return false;at=10;while(at<end&&v->p[at]){bool v4=v->p[3]==4;if(!sxau_row(v,v4?&sxau_id3v24_frame:&sxau_id3v23_frame,at,end))return false;uint32_t z=v4?sxau_syncsafe(v->p+at+4):sxau_u32(v->p+at+4,true);at+=10;if(!sxau_need(v,at,z,end))return false;at+=z;}at=end;}
 while(at<v->n){static const uint16_t br[]={0,32,40,48,56,64,80,96,112,128,160,192,224,256,320};static const uint32_t rates[]={44100,48000,32000};if(!SA_ROW(mp3_frame_header,at,v->n))return false;unsigned bi=v->p[at+2]>>4,ri=(v->p[at+2]>>2)&3;if(!bi||bi>=15||ri>=3)return false;size_t z=144000U*br[bi]/rates[ri]+((v->p[at+2]>>1)&1);if(!sxau_need(v,at,z,v->n))return false;at+=z;}return true;}
bool sx_audio_mpeg_mp3_build(sxau_view*v)
{
 return sxau_mp3(v);
}
#undef SA_ROW
