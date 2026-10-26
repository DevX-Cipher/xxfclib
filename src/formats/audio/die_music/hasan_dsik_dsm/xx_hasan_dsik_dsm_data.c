/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Carlos Hasan's Digital Sound Interface Kit module (.DSM) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_dsm_riff_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("form","char[4]",8,4,SX_ID),
};
const sx_layout sxmn_dsm_riff={UINT32_C(0x60760034),"dsm_riff",sxmn_dsm_riff_fields,SX_COUNT(sxmn_dsm_riff_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm_chunk_fields[]={
 SX_FIELD("id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmn_dsm_chunk={UINT32_C(0x60760035),"dsm_chunk",sxmn_dsm_chunk_fields,SX_COUNT(sxmn_dsm_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm_song_fields[]={
 SX_FIELD("name","char[28]",0,28,SX_STRING),
 SX_FIELD("version","uint16",28,2,SX_ID),
 SX_FIELD("flags","uint16",30,2,SX_FLAGS),
 SX_FIELD("current_order","uint16",32,2,SX_ID),
 SX_FIELD("restart_order","uint16",34,2,SX_ID),
 SX_FIELD("orders","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("samples","uint16",38,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",40,2,SX_COUNT_PROP),
 SX_FIELD("channels","uint16",42,2,SX_COUNT_PROP),
 SX_FIELD("global_volume","uint8",44,1,SX_NONE),
 SX_FIELD("master_volume","uint8",45,1,SX_NONE),
 SX_FIELD("speed","uint8",46,1,SX_NONE),
 SX_FIELD("tempo","uint8",47,1,SX_NONE),
 SX_FIELD("channel0_pan","uint8",48,1,SX_NONE),
 SX_FIELD("channel1_pan","uint8",49,1,SX_NONE),
 SX_FIELD("channel2_pan","uint8",50,1,SX_NONE),
 SX_FIELD("channel3_pan","uint8",51,1,SX_NONE),
 SX_FIELD("channel4_pan","uint8",52,1,SX_NONE),
 SX_FIELD("channel5_pan","uint8",53,1,SX_NONE),
 SX_FIELD("channel6_pan","uint8",54,1,SX_NONE),
 SX_FIELD("channel7_pan","uint8",55,1,SX_NONE),
 SX_FIELD("channel8_pan","uint8",56,1,SX_NONE),
 SX_FIELD("channel9_pan","uint8",57,1,SX_NONE),
 SX_FIELD("channel10_pan","uint8",58,1,SX_NONE),
 SX_FIELD("channel11_pan","uint8",59,1,SX_NONE),
 SX_FIELD("channel12_pan","uint8",60,1,SX_NONE),
 SX_FIELD("channel13_pan","uint8",61,1,SX_NONE),
 SX_FIELD("channel14_pan","uint8",62,1,SX_NONE),
 SX_FIELD("channel15_pan","uint8",63,1,SX_NONE),
};
const sx_layout sxmn_dsm_song={UINT32_C(0x60760036),"dsm_song",sxmn_dsm_song_fields,SX_COUNT(sxmn_dsm_song_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_dsmriff(sxmn_view*v)
{uint64_t end=v->c->size,at=12,size;if(!MN_ROW(dsm_riff,0,end)||!sxmn_word(v,4,4,false,&size,end)||!sxmn_span(v,8,size,end))return false;end=8+size;while(at<end){uint64_t z;uint8_t id[4];if(!MN_ROW(dsm_chunk,at,end)||!sxmn_word(v,at+4,4,false,&z,end)||!sxmn_read(v,at,id,4,end)||!sxmn_span(v,at+8,z,end))return false;uint64_t p=at+8,limit=p+z;if(!xx_rt_memcmp(id,"SONG",4)){if(!MN_ROW(dsm_song,p,limit)||!sxmn_table(v,&sxmn_dsm_order,p+64,128,limit))return false;}else if(!xx_rt_memcmp(id,"INST",4)){if(!MN_ROW(dsm_sample,p,limit))return false;}at=limit;/* DSIK chunk writer stores no RIFF padding. */}return true;}
bool sx_hasan_dsik_dsm_build(sxmn_view*v)
{
 return sxmn_dsmriff(v);
}
#undef MN_ROW
