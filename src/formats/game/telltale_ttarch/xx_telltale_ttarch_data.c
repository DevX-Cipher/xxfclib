/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * telltale_ttarch data structures, moved out of the gamearchives schema family. */
#include "../../xx_format_schema_gamearchives.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxga_tt_nctt_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("inner_bytes","uint64",4,8,SX_SIZE),
};
const sx_layout sxga_tt_nctt={UINT32_C(0x603B0045),"tt_nctt",sxga_tt_nctt_fields,SX_COUNT(sxga_tt_nctt_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_chunked_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("chunk_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("chunks","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxga_tt_chunked={UINT32_C(0x603B0046),"tt_chunked",sxga_tt_chunked_fields,SX_COUNT(sxga_tt_chunked_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_header3_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown","uint32",4,4,SX_NONE),
 SX_FIELD("names_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("entries","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxga_tt_header3={UINT32_C(0x603B0048),"tt_header3",sxga_tt_header3_fields,SX_COUNT(sxga_tt_header3_fields),SX_LE};
static const xx_data_struct_field_desc sxga_tt_header4_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("names_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("entries","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxga_tt_header4={UINT32_C(0x603B0049),"tt_header4",sxga_tt_header4_fields,SX_COUNT(sxga_tt_header4_fields),SX_LE};
#define GA_ROW(l,at,end) sxga_row(v,&sxga_##l,(at),(end))
static bool sxga_tt(sxga_view*v)
{uint64_t end=v->c->size,at=0,n,z,tag;if(!sxga_word(v,0,4,false,&tag,end))return false;if(tag==UINT32_C(0x5454434e)){if(!GA_ROW(tt_nctt,0,end)||!sxga_word(v,4,8,false,&z,end)||!sxga_span(v,12,z,end))return false;at=12;end=at+z;if(!sxga_word(v,at,4,false,&tag,end))return false;}else if(tag==UINT32_C(0x5454435a)||tag==UINT32_C(0x54544345)){return GA_ROW(tt_chunked,0,end)&&sxga_word(v,8,4,false,&n,end)&&sxga_table(v,&sxga_tt_chunk_offset,12,n+1,end);}bool v3=tag==UINT32_C(0x54544133);if(!sxga_row(v,v3?&sxga_tt_header3:&sxga_tt_header4,at,end)||!sxga_word(v,at+(v3?8:4),4,false,&z,end)||!sxga_word(v,at+(v3?12:8),4,false,&n,end))return false;at+=v3?16:12;if(!sxga_table(v,&sxga_tt_entry,at,n,end))return false;at+=n*28;/* The stored name pool can contain page padding; preserve its bytes exactly. */return sxga_named(v,at,z,end,false);}
bool sx_telltale_ttarch_build(sxga_view*v)
{
 return sxga_tt(v);
}
#undef GA_ROW
