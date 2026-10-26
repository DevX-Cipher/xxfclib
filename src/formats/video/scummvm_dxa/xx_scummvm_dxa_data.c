/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SCUMMVM DXA data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_dxa_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("frame_count","uint16",5,2,SX_COUNT_PROP),
 SX_FIELD("frame_duration","int32",7,4,SX_NONE),
 SX_FIELD("width","uint16",11,2,SX_NONE),
 SX_FIELD("height","uint16",13,2,SX_NONE),
 SX_FIELD("audio_tag","bytes",15,4,SX_ID),
};
const sx_layout sxnx_dxa_header={UINT32_C(0x603200D8),"dxa_header",sxnx_dxa_header_fields,SX_COUNT(sxnx_dxa_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_dxa_wave_size_fields[]={
 SX_FIELD("wave_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxnx_dxa_wave_size={UINT32_C(0x603200D9),"dxa_wave_size",sxnx_dxa_wave_size_fields,SX_COUNT(sxnx_dxa_wave_size_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_dxa_riff_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
const sx_layout sxnx_dxa_riff={UINT32_C(0x603200DA),"dxa_riff",sxnx_dxa_riff_fields,SX_COUNT(sxnx_dxa_riff_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_dxa_tag_fields[]={
 SX_FIELD("tag","bytes",0,4,SX_ID),
};
const sx_layout sxnx_dxa_tag={UINT32_C(0x603200DB),"dxa_tag",sxnx_dxa_tag_fields,SX_COUNT(sxnx_dxa_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_dxa_frame_fields[]={
 SX_FIELD("tag","bytes",0,4,SX_ID),
 SX_FIELD("compression","uint8",4,1,SX_ID),
 SX_FIELD("packed_size","uint32",5,4,SX_SIZE),
};
const sx_layout sxnx_dxa_frame={UINT32_C(0x603200DC),"dxa_frame",sxnx_dxa_frame_fields,SX_COUNT(sxnx_dxa_frame_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_dxa(sxnx_view*v)
{if(!SN_ROW(dxa_header,0,v->n))return false;size_t p=19;unsigned count=sxnx_u16(v->p+5,true);if(!xx_rt_memcmp(v->p+15,"WAVE",4)){if(!SN_ROW(dxa_wave_size,p,v->n))return false;unsigned n=sxnx_u32(v->p+p,true);p+=4;if(!sxnx_need(v,p,n,v->n)||!SN_ROW(dxa_riff,p,p+n))return false;p+=n;}
 for(unsigned i=0;i<count;i++){if(!SN_ROW(dxa_tag,p,v->n))return false;unsigned id=sxnx_u32(v->p+p,true);p+=4;if(id==UINT32_C(0x434d4150)){if(!sxnx_table(v,&sxnx_rgb_palette_entry,p,256,v->n))return false;p+=768;}if(!sxnx_need(v,p,4,v->n))return false;if(!xx_rt_memcmp(v->p+p,"FRAM",4)){if(!SN_ROW(dxa_frame,p,v->n))return false;unsigned n=sxnx_u32(v->p+p+5,true);p+=9;if(!sxnx_need(v,p,n,v->n))return false;p+=n;}else{if(!SN_ROW(dxa_tag,p,v->n))return false;p+=4;}}return p<=v->n;}
bool sx_scummvm_dxa_build(sxnx_view*v)
{
 return sxnx_dxa(v);
}
#undef SN_ROW
