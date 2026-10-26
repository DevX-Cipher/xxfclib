/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * audio_dolby_ac3 data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_ac3_sync_info_fields[]={
 SX_FIELD("sync_word","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("crc1","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("sample_rate_and_frame_size_code","uint8",4,1,SX_FLAGS),
 SX_FIELD("bitstream_id_and_mode","uint8",5,1,SX_FLAGS),
};
const sx_layout sxau_ac3_sync_info={UINT32_C(0x602C002D),"ac3_sync_info",sxau_ac3_sync_info_fields,SX_COUNT(sxau_ac3_sync_info_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ac3_checksum2_fields[]={
 SX_FIELD("crc2","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxau_ac3_checksum2={UINT32_C(0x602C002E),"ac3_checksum2",sxau_ac3_checksum2_fields,SX_COUNT(sxau_ac3_checksum2_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_ac3(sxau_view*v)
{static const uint16_t br[]={32,40,48,56,64,80,96,112,128,160,192,224,256,320,384,448,512,576,640},w44[]={69,87,104,121,139,174,208,243,278,348,417,487,557,696,835,975,1114,1253,1393};size_t at=0;while(at<v->n){if(!SA_ROW(ac3_sync_info,at,v->n))return false;unsigned sr=v->p[at+4]>>6,code=v->p[at+4]&63;if(sr>=3||code>=38)return false;size_t z=2*(sr==0?br[code/2]*2:sr==2?br[code/2]*3:w44[code/2]+(code&1));if(!sxau_need(v,at,z,v->n)||!SA_ROW(ac3_checksum2,at+z-2,v->n))return false;at+=z;}return true;}
bool sx_audio_dolby_ac3_build(sxau_view*v)
{
 return sxau_ac3(v);
}
#undef SA_ROW
