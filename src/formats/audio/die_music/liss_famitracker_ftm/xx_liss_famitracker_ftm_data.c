/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * liss_famitracker_ftm data structures, moved out of the musicprojects schema family. */
#include "../../../xx_format_schema_musicprojects.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmp_famitracker_file_header_fields[]={
 SX_FIELD("signature","char[18]",0,18,SX_SIGNATURE),
 SX_FIELD("format_version","uint32",18,4,SX_NONE),
};
const sx_layout sxmp_famitracker_file_header={0x607b0002U,"famitracker_file_header",sxmp_famitracker_file_header_fields,SX_COUNT(sxmp_famitracker_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_block_header_fields[]={
 SX_FIELD("block_id","char[16]",0,16,SX_ID),
 SX_FIELD("block_version","int32",16,4,SX_NONE),
 SX_FIELD("block_size","int32",20,4,SX_SIZE),
};
const sx_layout sxmp_famitracker_block_header={0x607b0003U,"famitracker_block_header",sxmp_famitracker_block_header_fields,SX_COUNT(sxmp_famitracker_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_end_fields[]={
 SX_FIELD("end_marker","char[3]",0,3,SX_SIGNATURE),
};
const sx_layout sxmp_famitracker_end={0x607b0004U,"famitracker_end",sxmp_famitracker_end_fields,SX_COUNT(sxmp_famitracker_end_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_info_fields[]={
 SX_FIELD("song_name","char[32]",0,32,SX_STRING),
 SX_FIELD("artist","char[32]",32,32,SX_STRING),
 SX_FIELD("copyright","char[32]",64,32,SX_STRING),
};
const sx_layout sxmp_famitracker_info={0x607b0005U,"famitracker_info",sxmp_famitracker_info_fields,SX_COUNT(sxmp_famitracker_info_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v1_fields[]={
 SX_FIELD("initial_speed","int32",0,4,SX_NONE),
 SX_FIELD("channel_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",8,4,SX_ID),
 SX_FIELD("engine_speed","int32",12,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v1={0x607b0006U,"famitracker_parameters_v1",sxmp_famitracker_parameters_v1_fields,SX_COUNT(sxmp_famitracker_parameters_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v2_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v2={0x607b0007U,"famitracker_parameters_v2",sxmp_famitracker_parameters_v2_fields,SX_COUNT(sxmp_famitracker_parameters_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v3_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
};
const sx_layout sxmp_famitracker_parameters_v3={0x607b0008U,"famitracker_parameters_v3",sxmp_famitracker_parameters_v3_fields,SX_COUNT(sxmp_famitracker_parameters_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v4_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v4={0x607b0009U,"famitracker_parameters_v4",sxmp_famitracker_parameters_v4_fields,SX_COUNT(sxmp_famitracker_parameters_v4_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v5_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v5={0x607b000aU,"famitracker_parameters_v5",sxmp_famitracker_parameters_v5_fields,SX_COUNT(sxmp_famitracker_parameters_v5_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v5_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
 SX_FIELD("namco_channel_count","int32",25,4,SX_COUNT_PROP),
};
const sx_layout sxmp_famitracker_parameters_v5_n163={0x607b000bU,"famitracker_parameters_v5_n163",sxmp_famitracker_parameters_v5_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v5_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v6_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
 SX_FIELD("speed_split_point","int32",25,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v6={0x607b000cU,"famitracker_parameters_v6",sxmp_famitracker_parameters_v6_fields,SX_COUNT(sxmp_famitracker_parameters_v6_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v6_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
 SX_FIELD("namco_channel_count","int32",25,4,SX_COUNT_PROP),
 SX_FIELD("speed_split_point","int32",29,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v6_n163={0x607b000dU,"famitracker_parameters_v6_n163",sxmp_famitracker_parameters_v6_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v6_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v7_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("speed_split_point","int32",21,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v7={0x607b000eU,"famitracker_parameters_v7",sxmp_famitracker_parameters_v7_fields,SX_COUNT(sxmp_famitracker_parameters_v7_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v7_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("namco_channel_count","int32",21,4,SX_COUNT_PROP),
 SX_FIELD("speed_split_point","int32",25,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v7_n163={0x607b000fU,"famitracker_parameters_v7_n163",sxmp_famitracker_parameters_v7_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v7_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v8_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("speed_split_point","int32",21,4,SX_NONE),
 SX_FIELD("detune_semitone","int8",25,1,SX_NONE),
 SX_FIELD("detune_cent","int8",26,1,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v8={0x607b0010U,"famitracker_parameters_v8",sxmp_famitracker_parameters_v8_fields,SX_COUNT(sxmp_famitracker_parameters_v8_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v8_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("namco_channel_count","int32",21,4,SX_COUNT_PROP),
 SX_FIELD("speed_split_point","int32",25,4,SX_NONE),
 SX_FIELD("detune_semitone","int8",29,1,SX_NONE),
 SX_FIELD("detune_cent","int8",30,1,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v8_n163={0x607b0011U,"famitracker_parameters_v8_n163",sxmp_famitracker_parameters_v8_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v8_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v9_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("hardware_sweep_reset","int32",21,4,SX_FLAGS),
 SX_FIELD("speed_split_point","int32",25,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v9={0x607b0012U,"famitracker_parameters_v9",sxmp_famitracker_parameters_v9_fields,SX_COUNT(sxmp_famitracker_parameters_v9_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v9_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("hardware_sweep_reset","int32",21,4,SX_FLAGS),
 SX_FIELD("namco_channel_count","int32",25,4,SX_COUNT_PROP),
 SX_FIELD("speed_split_point","int32",29,4,SX_NONE),
};
const sx_layout sxmp_famitracker_parameters_v9_n163={0x607b0013U,"famitracker_parameters_v9_n163",sxmp_famitracker_parameters_v9_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v9_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_track_count_fields[]={
 SX_FIELD("tracks_minus_one","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_famitracker_track_count={0x607b0014U,"famitracker_track_count",sxmp_famitracker_track_count_fields,SX_COUNT(sxmp_famitracker_track_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_channel_type_fields[]={
 SX_FIELD("channel_type","uint8",0,1,SX_ID),
};
const sx_layout sxmp_famitracker_channel_type={0x607b0015U,"famitracker_channel_type",sxmp_famitracker_channel_type_fields,SX_COUNT(sxmp_famitracker_channel_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_effect_columns_fields[]={
 SX_FIELD("effect_columns_minus_one","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_famitracker_effect_columns={0x607b0016U,"famitracker_effect_columns",sxmp_famitracker_effect_columns_fields,SX_COUNT(sxmp_famitracker_effect_columns_fields),SX_LE};
#define MP_ROW(name,at,end) sxmp_row(v,&sxmp_##name,(at),(end))
static const sx_layout*sxmp_ftm_params(unsigned version,bool n163)
{switch(version){case 1:return &sxmp_famitracker_parameters_v1;case 2:return &sxmp_famitracker_parameters_v2;case 3:return &sxmp_famitracker_parameters_v3;case 4:return &sxmp_famitracker_parameters_v4;case 5:return n163?&sxmp_famitracker_parameters_v5_n163:&sxmp_famitracker_parameters_v5;case 6:return n163?&sxmp_famitracker_parameters_v6_n163:&sxmp_famitracker_parameters_v6;case 7:return n163?&sxmp_famitracker_parameters_v7_n163:&sxmp_famitracker_parameters_v7;case 8:return n163?&sxmp_famitracker_parameters_v8_n163:&sxmp_famitracker_parameters_v8;case 9:return n163?&sxmp_famitracker_parameters_v9_n163:&sxmp_famitracker_parameters_v9;default:return NULL;}}
static bool sxmp_famitracker(sxmp_view*v)
{uint64_t e=v->c->size,p=22,channels=0;if(!MP_ROW(famitracker_file_header,0,e))return false;
 while(p<e&&v->c->count<24000){if(sxmp_eq(v,p,"END",3,e))return MP_ROW(famitracker_end,p,e);uint64_t z,version;if(!MP_ROW(famitracker_block_header,p,e)||!sxmp_u(v,p+16,4,&version,e)||!sxmp_u(v,p+20,4,&z,e)||version>INT32_MAX||z>INT32_MAX||!sxmp_span(v,p+24,z,e))return false;uint64_t a=p+24,end=a+z;
  if(sxmp_eq(v,p,"PARAMS\0",7,e)){uint64_t chips=0;const sx_layout*l;if(version!=1&&!sxmp_u(v,a,1,&chips,end))return false;if(!sxmp_u(v,a+(version==1?4:1),4,&channels,end)||!channels||channels>256)return false;l=sxmp_ftm_params((unsigned)version,channels!=5&&(chips&16)!=0);if(l&&!sxmp_row(v,l,a,end))return false;}
  else if(sxmp_eq(v,p,"INFO\0",5,e)){if(version==1&&!MP_ROW(famitracker_info,a,end))return false;}
  else if(sxmp_eq(v,p,"HEADER\0",7,e)&&version>=1&&version<=3){uint64_t tracks=1;if(version>=2){if(!MP_ROW(famitracker_track_count,a,end)||!sxmp_u(v,a,1,&tracks,end))return false;tracks++;a++;}if(version>=3)for(uint64_t i=0;i<tracks;i++)if(!sxmp_string(v,&sxmp_music_project_name,&a,end))return false;if(channels)for(uint64_t i=0;i<channels;i++){if(!MP_ROW(famitracker_channel_type,a,end)||!sxmp_table(v,&sxmp_famitracker_effect_columns,a+1,tracks,end))return false;a+=tracks+1;}}
  p=end;
 }return true;}
bool sx_liss_famitracker_ftm_build(sxmp_view*v)
{
 return sxmp_famitracker(v);
}
#undef MP_ROW
