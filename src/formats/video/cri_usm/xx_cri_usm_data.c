/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CRI USM data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_usm_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("payload_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("padding_size","uint16",10,2,SX_SIZE),
 SX_FIELD("channel","uint8",12,1,SX_ID),
 SX_FIELD("reserved","uint8",13,1,SX_RESERVED),
 SX_FIELD("payload_type","uint16",14,2,SX_ID),
 SX_FIELD("frame_time","uint32",16,4,SX_NONE),
 SX_FIELD("frame_rate","uint32",20,4,SX_NONE),
 SX_FIELD("reserved1","uint32",24,4,SX_RESERVED),
 SX_FIELD("reserved2","uint32",28,4,SX_RESERVED),
};
const sx_layout sxnx_usm_chunk={UINT32_C(0x603200A6),"usm_chunk",sxnx_usm_chunk_fields,SX_COUNT(sxnx_usm_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_ID),
 SX_FIELD("rows_offset","uint16",10,2,SX_OFFSET),
 SX_FIELD("strings_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("table_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("column_count","uint16",24,2,SX_COUNT_PROP),
 SX_FIELD("row_size","uint16",26,2,SX_SIZE),
 SX_FIELD("row_count","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxnx_usm_utf_header={UINT32_C(0x603200A7),"usm_utf_header",sxnx_usm_utf_header_fields,SX_COUNT(sxnx_usm_utf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_column_fields[]={
 SX_FIELD("storage_and_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint32",1,4,SX_OFFSET),
};
const sx_layout sxnx_usm_utf_column={UINT32_C(0x603200A8),"usm_utf_column",sxnx_usm_utf_column_fields,SX_COUNT(sxnx_usm_utf_column_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_u8_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_u8={UINT32_C(0x603200A9),"usm_utf_value_u8",sxnx_usm_utf_value_u8_fields,SX_COUNT(sxnx_usm_utf_value_u8_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_i8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_i8={UINT32_C(0x603200AA),"usm_utf_value_i8",sxnx_usm_utf_value_i8_fields,SX_COUNT(sxnx_usm_utf_value_i8_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_u16_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_u16={UINT32_C(0x603200AB),"usm_utf_value_u16",sxnx_usm_utf_value_u16_fields,SX_COUNT(sxnx_usm_utf_value_u16_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_i16_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_i16={UINT32_C(0x603200AC),"usm_utf_value_i16",sxnx_usm_utf_value_i16_fields,SX_COUNT(sxnx_usm_utf_value_i16_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_u32_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_u32={UINT32_C(0x603200AD),"usm_utf_value_u32",sxnx_usm_utf_value_u32_fields,SX_COUNT(sxnx_usm_utf_value_u32_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_i32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_i32={UINT32_C(0x603200AE),"usm_utf_value_i32",sxnx_usm_utf_value_i32_fields,SX_COUNT(sxnx_usm_utf_value_i32_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_u64_fields[]={
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_u64={UINT32_C(0x603200AF),"usm_utf_value_u64",sxnx_usm_utf_value_u64_fields,SX_COUNT(sxnx_usm_utf_value_u64_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_i64_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_i64={UINT32_C(0x603200B0),"usm_utf_value_i64",sxnx_usm_utf_value_i64_fields,SX_COUNT(sxnx_usm_utf_value_i64_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_f32_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_f32={UINT32_C(0x603200B1),"usm_utf_value_f32",sxnx_usm_utf_value_f32_fields,SX_COUNT(sxnx_usm_utf_value_f32_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_value_f64_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
const sx_layout sxnx_usm_utf_value_f64={UINT32_C(0x603200B2),"usm_utf_value_f64",sxnx_usm_utf_value_f64_fields,SX_COUNT(sxnx_usm_utf_value_f64_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_string_fields[]={
 SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxnx_usm_utf_string={UINT32_C(0x603200B3),"usm_utf_string",sxnx_usm_utf_string_fields,SX_COUNT(sxnx_usm_utf_string_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_data_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxnx_usm_utf_data={UINT32_C(0x603200B4),"usm_utf_data",sxnx_usm_utf_data_fields,SX_COUNT(sxnx_usm_utf_data_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_usm_utf_guid_fields[]={
 SX_FIELD("guid","bytes",0,16,SX_ID),
};
const sx_layout sxnx_usm_utf_guid={UINT32_C(0x603200B5),"usm_utf_guid",sxnx_usm_utf_guid_fields,SX_COUNT(sxnx_usm_utf_guid_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_usm_utf(sxnx_view*v,size_t base,size_t end)
{if(!SN_ROW(usm_utf_header,base,end))return false;uint64_t sz=8+(uint64_t)sxnx_u32(v->p+base+4,true);if(!sxnx_need(v,base,sz,end))return false;end=base+(size_t)sz;size_t rows=base+8+sxnx_u16(v->p+base+10,true),strings=base+8+sxnx_u32(v->p+base+12,true),p=base+32;unsigned count=sxnx_u16(v->p+base+24,true),width=sxnx_u16(v->p+base+26,true),nr=sxnx_u32(v->p+base+28,true);if(count>128||nr>1024||rows>strings||strings>end||!sxnx_need(v,rows,(uint64_t)width*nr,strings))return false;
 const sx_layout*types[]={&sxnx_usm_utf_value_u8,&sxnx_usm_utf_value_i8,&sxnx_usm_utf_value_u16,&sxnx_usm_utf_value_i16,&sxnx_usm_utf_value_u32,&sxnx_usm_utf_value_i32,&sxnx_usm_utf_value_u64,&sxnx_usm_utf_value_i64,&sxnx_usm_utf_value_f32,&sxnx_usm_utf_value_f64,&sxnx_usm_utf_string,&sxnx_usm_utf_data,&sxnx_usm_utf_guid};unsigned colsize[]={1,1,2,2,4,4,8,8,4,8,4,8,16},kind[128],flags[128],offset[128],rw=0;
 for(unsigned i=0;i<count;i++){if(!SN_ROW(usm_utf_column,p,rows))return false;kind[i]=v->p[p]&15;flags[i]=v->p[p]&0xf0;offset[i]=rw;p+=5;if(kind[i]>12)return false;if(flags[i]&0x20){if(!sxnx_row(v,types[kind[i]],p,rows))return false;p+=colsize[kind[i]];}if(flags[i]&0x40){if(rw>width||colsize[kind[i]]>width-rw)return false;rw+=colsize[kind[i]];}}
 for(unsigned j=0;j<nr;j++)for(unsigned i=0;i<count;i++)if((flags[i]&0x40)&&!sxnx_row(v,types[kind[i]],rows+(size_t)j*width+offset[i],strings))return false;return true;}
static bool sxnx_usm(sxnx_view*v)
{size_t p=0;unsigned count=0;while(p<v->n){if(++count>4096||!SN_ROW(usm_chunk,p,v->n))return false;uint64_t size=8+(uint64_t)sxnx_u32(v->p+p+4,true);unsigned offset=sxnx_u16(v->p+p+8,true),pad=sxnx_u16(v->p+p+10,true),type=sxnx_u16(v->p+p+14,true);if(size<32||!sxnx_need(v,p,size,v->n)||offset+8U>size||pad>size-offset-8)return false;size_t end=p+(size_t)size;if((type==1||type==3)&&!sxnx_usm_utf(v,p+8+offset,end-pad))return false;p=end;}return true;}
bool sx_cri_usm_build(sxnx_view*v)
{
 return sxnx_usm(v);
}
#undef SN_ROW
