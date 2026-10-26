/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * audio_ast data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_ast_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("encoding","uint16",8,2,SX_ID),
 SX_FIELD("bits_per_sample","uint16",10,2,SX_NONE),
 SX_FIELD("channels","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("loop_flag","uint16",14,2,SX_FLAGS),
 SX_FIELD("sample_rate","uint32",16,4,SX_NONE),
 SX_FIELD("sample_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_sample","uint32",24,4,SX_NONE),
 SX_FIELD("loop_end_sample","uint32",28,4,SX_NONE),
 SX_FIELD("first_block_size","uint32",32,4,SX_SIZE),
 SX_FIELD("unknown_tail","bytes",36,28,SX_NONE),
};
const sx_layout sxau_ast_header={UINT32_C(0x602C000E),"ast_header",sxau_ast_header_fields,SX_COUNT(sxau_ast_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ast_block_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("bytes_per_channel","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","bytes",8,24,SX_RESERVED),
};
const sx_layout sxau_ast_block={UINT32_C(0x602C000F),"ast_block",sxau_ast_block_fields,SX_COUNT(sxau_ast_block_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_ast(sxau_view*v)
{if(!SA_ROW(ast_header,0,v->n))return false;unsigned ch=sxau_u16(v->p+12,true);size_t at=64;if(!ch)return false;while(at<v->n){if(!SA_ROW(ast_block,at,v->n))return false;uint64_t z=(uint64_t)sxau_u32(v->p+at+4,true)*ch;at+=32;if(!z||!sxau_need(v,at,z,v->n))return false;at+=(size_t)z;}return true;}
bool sx_audio_ast_build(sxau_view*v)
{
 return sxau_ast(v);
}
#undef SA_ROW
