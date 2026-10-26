/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WINDOWS ANI data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_ani_riff_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
const sx_layout sxnx_ani_riff={UINT32_C(0x60320093),"ani_riff",sxnx_ani_riff_fields,SX_COUNT(sxnx_ani_riff_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxnx_ani_chunk={UINT32_C(0x60320094),"ani_chunk",sxnx_ani_chunk_fields,SX_COUNT(sxnx_ani_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_list_fields[]={
 SX_FIELD("list_type","bytes",0,4,SX_ID),
};
const sx_layout sxnx_ani_list={UINT32_C(0x60320095),"ani_list",sxnx_ani_list_fields,SX_COUNT(sxnx_ani_list_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_header_fields[]={
 SX_FIELD("header_size","uint32",0,4,SX_SIZE),
 SX_FIELD("frame_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("step_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("width","uint32",12,4,SX_NONE),
 SX_FIELD("height","uint32",16,4,SX_NONE),
 SX_FIELD("pixel_bits","uint32",20,4,SX_NONE),
 SX_FIELD("plane_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("display_rate_jiffies","uint32",28,4,SX_NONE),
 SX_FIELD("flags","uint32",32,4,SX_FLAGS),
};
const sx_layout sxnx_ani_header={UINT32_C(0x60320096),"ani_header",sxnx_ani_header_fields,SX_COUNT(sxnx_ani_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_rate_fields[]={
 SX_FIELD("duration_jiffies","uint32",0,4,SX_NONE),
};
const sx_layout sxnx_ani_rate={UINT32_C(0x60320097),"ani_rate",sxnx_ani_rate_fields,SX_COUNT(sxnx_ani_rate_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_sequence_fields[]={
 SX_FIELD("frame_index","uint32",0,4,SX_ID),
};
const sx_layout sxnx_ani_sequence={UINT32_C(0x60320098),"ani_sequence",sxnx_ani_sequence_fields,SX_COUNT(sxnx_ani_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_icon_header_fields[]={
 SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
 SX_FIELD("image_type","uint16",2,2,SX_ID),
 SX_FIELD("image_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxnx_ani_icon_header={UINT32_C(0x60320099),"ani_icon_header",sxnx_ani_icon_header_fields,SX_COUNT(sxnx_ani_icon_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_icon_entry_fields[]={
 SX_FIELD("width","uint8",0,1,SX_NONE),
 SX_FIELD("height","uint8",1,1,SX_NONE),
 SX_FIELD("color_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("planes","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("bit_count","uint16",6,2,SX_NONE),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxnx_ani_icon_entry={UINT32_C(0x6032009A),"ani_icon_entry",sxnx_ani_icon_entry_fields,SX_COUNT(sxnx_ani_icon_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_ani_cursor_entry_fields[]={
 SX_FIELD("width","uint8",0,1,SX_NONE),
 SX_FIELD("height","uint8",1,1,SX_NONE),
 SX_FIELD("color_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("hotspot_x","uint16",4,2,SX_NONE),
 SX_FIELD("hotspot_y","uint16",6,2,SX_NONE),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxnx_ani_cursor_entry={UINT32_C(0x6032009B),"ani_cursor_entry",sxnx_ani_cursor_entry_fields,SX_COUNT(sxnx_ani_cursor_entry_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_ani_chunks(sxnx_view*v,size_t p,size_t end,bool frames)
{while(p<end){if(!SN_ROW(ani_chunk,p,end))return false;uint32_t id=sxnx_u32(v->p+p,true),z=sxnx_u32(v->p+p+4,false);p+=8;if(!sxnx_need(v,p,(uint64_t)z+(z&1),end))return false;size_t next=p+z+(z&1);
 if(id==UINT32_C(0x616e6968)){if(!SN_ROW(ani_header,p,p+z))return false;}else if(id==UINT32_C(0x4c495354)){if(!SN_ROW(ani_list,p,p+z))return false;if(!frames&&sxnx_u32(v->p+p,true)==UINT32_C(0x6672616d)&&!sxnx_ani_chunks(v,p+4,p+z,true))return false;}else if(id==UINT32_C(0x72617465)||id==UINT32_C(0x73657120)){if(z%4||!sxnx_table(v,id==UINT32_C(0x72617465)?&sxnx_ani_rate:&sxnx_ani_sequence,p,z/4,p+z))return false;}else if(frames&&id==UINT32_C(0x69636f6e)){if(!SN_ROW(ani_icon_header,p,p+z))return false;unsigned count=sxnx_u16(v->p+p+4,false);if(!sxnx_table(v,sxnx_u16(v->p+p+2,false)==2?&sxnx_ani_cursor_entry:&sxnx_ani_icon_entry,p+6,count,p+z))return false;}p=next;}return p==end;}
static bool sxnx_ani(sxnx_view*v){return SN_ROW(ani_riff,0,v->n)&&sxnx_ani_chunks(v,12,v->n,false);}
bool sx_windows_ani_build(sxnx_view*v)
{
 return sxnx_ani(v);
}
#undef SN_ROW
