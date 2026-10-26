/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * iff_8svx data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_iff8svx_form_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("form_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
const sx_layout sxau_iff8svx_form={UINT32_C(0x602C001B),"iff8svx_form",sxau_iff8svx_form_fields,SX_COUNT(sxau_iff8svx_form_fields),SX_BE};
static const xx_data_struct_field_desc sxau_iff8svx_chunk_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxau_iff8svx_chunk={UINT32_C(0x602C001C),"iff8svx_chunk",sxau_iff8svx_chunk_fields,SX_COUNT(sxau_iff8svx_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxau_iff8svx_voice_fields[]={
 SX_FIELD("one_shot_samples","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("repeat_samples","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("samples_per_cycle","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("samples_per_second","uint16",12,2,SX_NONE),
 SX_FIELD("octaves","uint8",14,1,SX_COUNT_PROP),
 SX_FIELD("compression","uint8",15,1,SX_ID),
 SX_FIELD("volume_fixed16_16","uint32",16,4,SX_NONE),
};
const sx_layout sxau_iff8svx_voice={UINT32_C(0x602C001D),"iff8svx_voice",sxau_iff8svx_voice_fields,SX_COUNT(sxau_iff8svx_voice_fields),SX_BE};
static const xx_data_struct_field_desc sxau_iff8svx_channel_fields[]={
 SX_FIELD("channel_assignment","uint32",0,4,SX_ID),
};
const sx_layout sxau_iff8svx_channel={UINT32_C(0x602C001E),"iff8svx_channel",sxau_iff8svx_channel_fields,SX_COUNT(sxau_iff8svx_channel_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_iff(sxau_view*v)
{if(!SA_ROW(iff8svx_form,0,v->n))return false;size_t at=12;while(at<v->n){if(!SA_ROW(iff8svx_chunk,at,v->n))return false;uint32_t n=sxau_u32(v->p+at+4,true);size_t data=at+8;if(!sxau_need(v,data,(uint64_t)n+(n&1),v->n))return false;if(!xx_rt_memcmp(v->p+at,"VHDR",4)&&!SA_ROW(iff8svx_voice,data,data+n))return false;if(!xx_rt_memcmp(v->p+at,"CHAN",4)&&!SA_ROW(iff8svx_channel,data,data+n))return false;at=data+n+(n&1);}return true;}
bool sx_iff_8svx_build(sxau_view*v)
{
 return sxau_iff(v);
}
#undef SA_ROW
