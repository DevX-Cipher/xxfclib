/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * audio_monkeys_ape data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_ape_descriptor_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
 SX_FIELD("descriptor_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("header_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("seek_table_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("wav_header_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("audio_data_bytes_low","uint32",24,4,SX_NONE),
 SX_FIELD("audio_data_bytes_high","uint32",28,4,SX_NONE),
 SX_FIELD("wav_tail_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("md5","bytes",36,16,SX_CHECKSUM),
};
const sx_layout sxau_ape_descriptor={UINT32_C(0x602C0035),"ape_descriptor",sxau_ape_descriptor_fields,SX_COUNT(sxau_ape_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ape_header_fields[]={
 SX_FIELD("compression_level","uint16",0,2,SX_ID),
 SX_FIELD("format_flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("blocks_per_frame","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("final_frame_blocks","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("total_frames","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("bits_per_sample","uint16",16,2,SX_NONE),
 SX_FIELD("channels","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint32",20,4,SX_NONE),
};
const sx_layout sxau_ape_header={UINT32_C(0x602C0036),"ape_header",sxau_ape_header_fields,SX_COUNT(sxau_ape_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ape_seek_fields[]={
 SX_FIELD("frame_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxau_ape_seek={UINT32_C(0x602C0037),"ape_seek",sxau_ape_seek_fields,SX_COUNT(sxau_ape_seek_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ape_tag_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("tag_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("item_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("reserved","bytes",24,8,SX_RESERVED),
};
const sx_layout sxau_ape_tag={UINT32_C(0x602C0038),"ape_tag",sxau_ape_tag_fields,SX_COUNT(sxau_ape_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ape_tag_item_fields[]={
 SX_FIELD("value_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
const sx_layout sxau_ape_tag_item={UINT32_C(0x602C0039),"ape_tag_item",sxau_ape_tag_item_fields,SX_COUNT(sxau_ape_tag_item_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_ape(sxau_view*v)
{if(!SA_ROW(ape_descriptor,0,v->n)||!SA_ROW(ape_header,52,v->n))return false;uint32_t frames=sxau_u32(v->p+64,false);if(!sxau_table(v,&sxau_ape_seek,76,frames,v->n))return false;
 if(v->n>=32&&!xx_rt_memcmp(v->p+v->n-32,"APETAGEX",8)){size_t foot=v->n-32;uint32_t bytes=sxau_u32(v->p+foot+12,false),count=sxau_u32(v->p+foot+16,false),flags=sxau_u32(v->p+foot+20,false);if(bytes<32||bytes>v->n||count>1024||!SA_ROW(ape_tag,foot,v->n))return false;size_t at=v->n-bytes;if(flags&0x80000000U){if(at<32||!SA_ROW(ape_tag,at-32,at))return false;}for(uint32_t i=0;i<count;i++){if(!SA_ROW(ape_tag_item,at,foot))return false;uint32_t z=sxau_u32(v->p+at,false);at+=8;size_t key=0;while(at<foot&&v->p[at]&&key<256){at++;key++;}if(!key||at==foot||v->p[at]||!sxau_need(v,at+1,z,foot))return false;at+=1+z;}if(at!=foot)return false;}return true;}
bool sx_audio_monkeys_ape_build(sxau_view*v)
{
 return sxau_ape(v);
}
#undef SA_ROW
