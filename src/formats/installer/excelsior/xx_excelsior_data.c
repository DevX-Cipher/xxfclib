/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Excelsior Installer data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_excelsior_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("unknown_0c","uint8[4]",12,4,SX_NONE),
 SX_FIELD("index_offset","uint64le",16,8,SX_OFFSET),
 SX_FIELD("decoded_index_size","uint32le",24,4,SX_SIZE),
 SX_FIELD("decoded_prefix_size","uint32le",28,4,SX_SIZE),
 SX_FIELD("data_stream_offset","uint64le",32,8,SX_OFFSET),
};
const sx_layout sxir_excelsior_header={0x60800017U,"excelsior_header",sxir_excelsior_header_fields,SX_COUNT(sxir_excelsior_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_excelsior_lzma_stream_fields[]={
 SX_FIELD("decoded_size","uint64le",0,8,SX_SIZE),
 SX_FIELD("lzma_properties","uint8",8,1,SX_NONE),
 SX_FIELD("dictionary_size","uint32le",9,4,SX_SIZE),
};
const sx_layout sxir_excelsior_lzma_stream={0x60800018U,"excelsior_lzma_stream",sxir_excelsior_lzma_stream_fields,SX_COUNT(sxir_excelsior_lzma_stream_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_excelsior(sxir_view*v)
{uint64_t end=v->c->size,at,cert,index,data;if(!sxir_pe(v,0,end,&at,&cert)||!sxir_eq(v,at,"ExcelsiorII1",12,end)||!IR_ROW(excelsior_header,at,end)||!IR_U(at+16,8,index,end)||!IR_U(at+32,8,data,end)||data<at+40||index<=data||!IR_ROW(excelsior_lzma_stream,data,index)||!IR_ROW(excelsior_lzma_stream,index,end))return false;return true;}
bool sx_excelsior_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_excelsior(v);
}
#undef IR_ROW
#undef IR_U
