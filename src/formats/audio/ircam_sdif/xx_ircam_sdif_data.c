/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ircam_sdif data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_sdif_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("format_version","uint32",8,4,SX_ID),
 SX_FIELD("types_version","uint32",12,4,SX_ID),
};
const sx_layout sxau_sdif_header={UINT32_C(0x602C003A),"sdif_header",sxau_sdif_header_fields,SX_COUNT(sxau_sdif_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_sdif_frame_fields[]={
 SX_FIELD("frame_type","char[4]",0,4,SX_ID),
 SX_FIELD("frame_data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("time_seconds","double",8,8,SX_NONE),
 SX_FIELD("stream_id","uint32",16,4,SX_ID),
 SX_FIELD("matrix_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxau_sdif_frame={UINT32_C(0x602C003B),"sdif_frame",sxau_sdif_frame_fields,SX_COUNT(sxau_sdif_frame_fields),SX_BE};
static const xx_data_struct_field_desc sxau_sdif_matrix_fields[]={
 SX_FIELD("matrix_type","char[4]",0,4,SX_ID),
 SX_FIELD("data_type","uint32",4,4,SX_ID),
 SX_FIELD("rows","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("columns","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxau_sdif_matrix={UINT32_C(0x602C003C),"sdif_matrix",sxau_sdif_matrix_fields,SX_COUNT(sxau_sdif_matrix_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_sdif(sxau_view*v)
{if(!SA_ROW(sdif_header,0,v->n))return false;size_t at=16;while(at<v->n){if(!SA_ROW(sdif_frame,at,v->n))return false;size_t end=at+8+(size_t)sxau_u32(v->p+at+4,true);if(end<at+24||end>v->n)return false;uint32_t count=sxau_u32(v->p+at+20,true);at+=24;for(uint32_t i=0;i<count;i++){if(!SA_ROW(sdif_matrix,at,end))return false;uint32_t type=sxau_u32(v->p+at+4,true),rows=sxau_u32(v->p+at+8,true),cols=sxau_u32(v->p+at+12,true);unsigned width=type&255;if(width!=1&&width!=2&&width!=4&&width!=8)return false;uint64_t z=(uint64_t)rows*cols;if(z>SIZE_MAX/width)return false;z*=width;at+=16;uint64_t pad=(8-z%8)%8;if(z>SIZE_MAX-pad||!sxau_need(v,at,z+pad,end))return false;at+=(size_t)(z+pad);}if(at!=end)return false;}return true;}
bool sx_ircam_sdif_build(sxau_view*v)
{
 return sxau_sdif(v);
}
#undef SA_ROW
