/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * fmod_sample_bank data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_fsb1_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("sample_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("sample_data_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sxau_fsb1_header={UINT32_C(0x602C0053),"fsb1_header",sxau_fsb1_header_fields,SX_COUNT(sxau_fsb1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb1_sample_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_STRING),
 SX_FIELD("sample_count","int32",32,4,SX_COUNT_PROP),
 SX_FIELD("stored_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("sample_rate","int32",40,4,SX_NONE),
 SX_FIELD("opaque_2c","bytes",44,8,SX_NONE),
 SX_FIELD("mode","uint32",52,4,SX_FLAGS),
 SX_FIELD("loop_start_sample","int32",56,4,SX_NONE),
 SX_FIELD("loop_end_sample","int32",60,4,SX_NONE),
};
const sx_layout sxau_fsb1_sample={UINT32_C(0x602C0054),"fsb1_sample",sxau_fsb1_sample_fields,SX_COUNT(sxau_fsb1_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("sample_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("sample_header_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("sample_data_bytes","uint32",12,4,SX_SIZE),
};
const sx_layout sxau_fsb2_header={UINT32_C(0x602C0055),"fsb2_header",sxau_fsb2_header_fields,SX_COUNT(sxau_fsb2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb34_version_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
const sx_layout sxau_fsb34_version={UINT32_C(0x602C0056),"fsb34_version",sxau_fsb34_version_fields,SX_COUNT(sxau_fsb34_version_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb4_hash_fields[]={
 SX_FIELD("hash","bytes",0,8,SX_CHECKSUM),
 SX_FIELD("guid","bytes",8,16,SX_ID),
};
const sx_layout sxau_fsb4_hash={UINT32_C(0x602C0057),"fsb4_hash",sxau_fsb4_hash_fields,SX_COUNT(sxau_fsb4_hash_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb_sample_fields[]={
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("name","char[30]",2,30,SX_STRING),
 SX_FIELD("sample_count","int32",32,4,SX_COUNT_PROP),
 SX_FIELD("stored_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("loop_start_sample","int32",40,4,SX_NONE),
 SX_FIELD("loop_end_sample","int32",44,4,SX_NONE),
 SX_FIELD("mode","uint32",48,4,SX_FLAGS),
 SX_FIELD("sample_rate","int32",52,4,SX_NONE),
 SX_FIELD("default_volume","uint16",56,2,SX_NONE),
 SX_FIELD("default_pan","int16",58,2,SX_NONE),
 SX_FIELD("default_priority","uint16",60,2,SX_NONE),
 SX_FIELD("channels","uint16",62,2,SX_COUNT_PROP),
};
const sx_layout sxau_fsb_sample={UINT32_C(0x602C0058),"fsb_sample",sxau_fsb_sample_fields,SX_COUNT(sxau_fsb_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb_sample_basic_fields[]={
 SX_FIELD("sample_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("stored_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxau_fsb_sample_basic={UINT32_C(0x602C0059),"fsb_sample_basic",sxau_fsb_sample_basic_fields,SX_COUNT(sxau_fsb_sample_basic_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("sample_count","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("sample_header_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("name_table_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("sample_data_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("codec","uint32",24,4,SX_ID),
};
const sx_layout sxau_fsb5_header={UINT32_C(0x602C005A),"fsb5_header",sxau_fsb5_header_fields,SX_COUNT(sxau_fsb5_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_sample_fields[]={
 SX_FIELD("packed_sample_metadata","uint64",0,8,SX_FLAGS),
};
const sx_layout sxau_fsb5_sample={UINT32_C(0x602C005B),"fsb5_sample",sxau_fsb5_sample_fields,SX_COUNT(sxau_fsb5_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_chunk_fields[]={
 SX_FIELD("more_size_type","uint32",0,4,SX_FLAGS),
};
const sx_layout sxau_fsb5_chunk={UINT32_C(0x602C005C),"fsb5_chunk",sxau_fsb5_chunk_fields,SX_COUNT(sxau_fsb5_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_channels_fields[]={
 SX_FIELD("channels","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxau_fsb5_channels={UINT32_C(0x602C005D),"fsb5_channels",sxau_fsb5_channels_fields,SX_COUNT(sxau_fsb5_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_frequency_fields[]={
 SX_FIELD("sample_rate","uint32",0,4,SX_NONE),
};
const sx_layout sxau_fsb5_frequency={UINT32_C(0x602C005E),"fsb5_frequency",sxau_fsb5_frequency_fields,SX_COUNT(sxau_fsb5_frequency_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_name_offset_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxau_fsb5_name_offset={UINT32_C(0x602C005F),"fsb5_name_offset",sxau_fsb5_name_offset_fields,SX_COUNT(sxau_fsb5_name_offset_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_fsb(sxau_view*v)
{if(!sxau_need(v,0,16,v->n))return false;unsigned ver=v->p[3]-'0';uint32_t n=sxau_u32(v->p+4,false);if(ver==1)return SA_ROW(fsb1_header,0,v->n)&&sxau_table(v,&sxau_fsb1_sample,16,n,v->n);
 if(ver>=2&&ver<=4){if(!SA_ROW(fsb2_header,0,v->n))return false;size_t h=ver==2?16:ver==3?24:48;if(ver>2&&!SA_ROW(fsb34_version,16,v->n))return false;if(ver==4&&!SA_ROW(fsb4_hash,24,v->n))return false;uint32_t flags=ver>2?sxau_u32(v->p+20,false):0,bytes=sxau_u32(v->p+8,false);if(n>1000000||!sxau_need(v,h,bytes,v->n))return false;size_t at=h,end=h+bytes;
  for(uint32_t i=0;i<n;i++){if(i&&(flags&2)){if(!SA_ROW(fsb_sample_basic,at,end))return false;at+=8;}else{if(!SA_ROW(fsb_sample,at,end))return false;uint16_t z=sxau_u16(v->p+at,false);if(z<64||!sxau_need(v,at,z,end))return false;at+=z;}}return at<=end;
 }if(ver==5){if(!SA_ROW(fsb5_header,0,v->n))return false;unsigned revision=sxau_u32(v->p+4,false);n=sxau_u32(v->p+8,false);size_t h=revision?60:64;uint32_t bytes=sxau_u32(v->p+12,false),names=sxau_u32(v->p+16,false);if(revision>1||n>1000000||!sxau_need(v,h,(uint64_t)bytes+names,v->n))return false;size_t at=h,end=h+bytes;
  for(uint32_t i=0;i<n;i++){if(!SA_ROW(fsb5_sample,at,end))return false;bool more=(v->p[at]&1)!=0;at+=8;while(more){if(!SA_ROW(fsb5_chunk,at,end))return false;uint32_t m=sxau_u32(v->p+at,false),z=(m>>1)&0xffffff,type=m>>25;more=(m&1)!=0;at+=4;if(!sxau_need(v,at,z,end))return false;if(type==1&&z==1&&!SA_ROW(fsb5_channels,at,at+z))return false;if(type==2&&z==4&&!SA_ROW(fsb5_frequency,at,at+z))return false;at+=z;}}
  return !names||sxau_table(v,&sxau_fsb5_name_offset,end,n,end+names);
 }return false;}
bool sx_fmod_sample_bank_build(sxau_view*v)
{
 return sxau_fsb(v);
}
#undef SA_ROW
