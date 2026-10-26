/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Konami's X68k Music Data eXtended module (.MDX) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_mdx_title_byte_fields[]={
 SX_FIELD("title_byte","char[1]",0,1,SX_STRING),
};
const sx_layout sxmn_mdx_title_byte={UINT32_C(0x6076002E),"mdx_title_byte",sxmn_mdx_title_byte_fields,SX_COUNT(sxmn_mdx_title_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mdx_title_end_fields[]={
 SX_FIELD("terminator","bytes",0,3,SX_SIGNATURE),
};
const sx_layout sxmn_mdx_title_end={UINT32_C(0x6076002F),"mdx_title_end",sxmn_mdx_title_end_fields,SX_COUNT(sxmn_mdx_title_end_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mdx_pdx_byte_fields[]={
 SX_FIELD("bank_name_byte","char[1]",0,1,SX_STRING),
};
const sx_layout sxmn_mdx_pdx_byte={UINT32_C(0x60760030),"mdx_pdx_byte",sxmn_mdx_pdx_byte_fields,SX_COUNT(sxmn_mdx_pdx_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mdx_voice_offset_fields[]={
 SX_FIELD("voice_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmn_mdx_voice_offset={UINT32_C(0x60760031),"mdx_voice_offset",sxmn_mdx_voice_offset_fields,SX_COUNT(sxmn_mdx_voice_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_mdx_track_offset_fields[]={
 SX_FIELD("track_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmn_mdx_track_offset={UINT32_C(0x60760032),"mdx_track_offset",sxmn_mdx_track_offset_fields,SX_COUNT(sxmn_mdx_track_offset_fields),SX_BE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_mdx(sxmn_view*v)
{uint64_t end=v->c->size,at=0,start,b,base,first;while(at<end&&!sxmn_magic(v,at,"\r\n\032",3,end)){if(at>65536||++v->work>4000000)return false;at++;}if(!sxmn_table(v,&sxmn_mdx_title_byte,0,at,end)||!MN_ROW(mdx_title_end,at,end))return false;at+=3;start=at;if(!sxmn_cstring(v,&at,end,65536)||!sxmn_table(v,&sxmn_mdx_pdx_byte,start,at-start,end))return false;base=at;if(!MN_ROW(mdx_voice_offset,base,end)||!sxmn_word(v,base+2,2,true,&first,end)||!sxmn_word(v,base+first,1,false,&b,end))return false;unsigned tracks=b==0xe8?16:9;uint64_t voice;if(!sxmn_word(v,base,2,true,&voice,end)||!sxmn_span(v,base,voice,end)||!sxmn_table(v,&sxmn_mdx_track_offset,base+2,tracks,end))return false;for(unsigned i=0;i<tracks;i++){uint64_t rel;if(!sxmn_word(v,base+2+2*i,2,true,&rel,end)||rel<2+2*tracks||!sxmn_span(v,base+rel,1,end))return false;}return true;}
bool sx_konami_musicdataextended_mdx_build(sxmn_view*v)
{
 return sxmn_mdx(v);
}
#undef MN_ROW
