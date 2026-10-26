/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WESTWOOD VQA data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_vqa_form_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
const sx_layout sxnx_vqa_form={UINT32_C(0x603200C2),"vqa_form",sxnx_vqa_form_fields,SX_COUNT(sxnx_vqa_form_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_vqa_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxnx_vqa_chunk={UINT32_C(0x603200C3),"vqa_chunk",sxnx_vqa_chunk_fields,SX_COUNT(sxnx_vqa_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_vqa_header_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("frame_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("width","uint16",6,2,SX_NONE),
 SX_FIELD("height","uint16",8,2,SX_NONE),
 SX_FIELD("block_width","uint8",10,1,SX_NONE),
 SX_FIELD("block_height","uint8",11,1,SX_NONE),
 SX_FIELD("frame_rate","uint8",12,1,SX_NONE),
 SX_FIELD("codebook_parts","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("color_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("max_blocks","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("opaque1","bytes",18,6,SX_NONE),
 SX_FIELD("sample_rate","uint16",24,2,SX_NONE),
 SX_FIELD("channel_count","uint8",26,1,SX_COUNT_PROP),
 SX_FIELD("sample_bits","uint8",27,1,SX_NONE),
 SX_FIELD("opaque2","bytes",28,14,SX_NONE),
};
const sx_layout sxnx_vqa_header={UINT32_C(0x603200C4),"vqa_header",sxnx_vqa_header_fields,SX_COUNT(sxnx_vqa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_vqa_frame_index_fields[]={
 SX_FIELD("word_offset_and_flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxnx_vqa_frame_index={UINT32_C(0x603200C5),"vqa_frame_index",sxnx_vqa_frame_index_fields,SX_COUNT(sxnx_vqa_frame_index_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_vqa_sound_fields[]={
 SX_FIELD("unpacked_bytes","uint16",0,2,SX_SIZE),
 SX_FIELD("packed_bytes","uint16",2,2,SX_SIZE),
};
const sx_layout sxnx_vqa_sound={UINT32_C(0x603200C6),"vqa_sound",sxnx_vqa_sound_fields,SX_COUNT(sxnx_vqa_sound_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_vqa_chunks(sxnx_view*v,size_t p,size_t end,bool nested)
{while(p<end){if(!SN_ROW(vqa_chunk,p,end))return false;unsigned z=sxnx_u32(v->p+p+4,true),id=sxnx_u32(v->p+p,true);p+=8;if(!sxnx_need(v,p,(uint64_t)z+(z&1),end))return false;if(id==UINT32_C(0x46494e46)){if(z%4||!sxnx_table(v,&sxnx_vqa_frame_index,p,z/4,p+z))return false;}else if(!nested&&(id==UINT32_C(0x56514652)||id==UINT32_C(0x5651464c))){if(!sxnx_vqa_chunks(v,p,p+z,true))return false;}else if(id==UINT32_C(0x534e4431)){if(!SN_ROW(vqa_sound,p,p+z))return false;}else if(id==UINT32_C(0x43504c30)){if(z%3||!sxnx_table(v,&sxnx_rgb_palette_entry,p,z/3,p+z))return false;}p+=z+(z&1);}return p==end;}
static bool sxnx_vqa(sxnx_view*v){return SN_ROW(vqa_form,0,v->n)&&SN_ROW(vqa_chunk,12,v->n)&&SN_ROW(vqa_header,20,v->n)&&sxnx_vqa_chunks(v,62,v->n,false);}
bool sx_westwood_vqa_build(sxnx_view*v)
{
 return sxnx_vqa(v);
}
#undef SN_ROW
