/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lithtech rez data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_rez_header_fields[]={
 SX_FIELD("newline0","bytes",0,2,SX_SIGNATURE),
 SX_FIELD("format_text","char[60]",2,60,SX_STRING),
 SX_FIELD("newline1","bytes",62,2,SX_SIGNATURE),
 SX_FIELD("title","char[60]",64,60,SX_STRING),
 SX_FIELD("newline_eof","bytes",124,3,SX_SIGNATURE),
 SX_FIELD("version","uint32",127,4,SX_ID),
 SX_FIELD("root_offset","uint32",131,4,SX_OFFSET),
 SX_FIELD("root_size","uint32",135,4,SX_SIZE),
 SX_FIELD("root_time","uint32",139,4,SX_TIME),
 SX_FIELD("directory_boundary","uint32",143,4,SX_OFFSET),
 SX_FIELD("unknown_limits","bytes",147,20,SX_NONE),
 SX_FIELD("sorted","uint8",167,1,SX_FLAGS),
};
const sx_layout sxmx_rez_header={UINT32_C(0x602E0018),"rez_header",sxmx_rez_header_fields,SX_COUNT(sxmx_rez_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_rez_directory_entry_fields[]={
 SX_FIELD("kind","uint32",0,4,SX_ID),
 SX_FIELD("directory_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("directory_size","uint32",8,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",12,4,SX_TIME),
};
const sx_layout sxmx_rez_directory_entry={UINT32_C(0x602E0019),"rez_directory_entry",sxmx_rez_directory_entry_fields,SX_COUNT(sxmx_rez_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_rez_resource_entry_fields[]={
 SX_FIELD("kind","uint32",0,4,SX_ID),
 SX_FIELD("file_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",12,4,SX_TIME),
 SX_FIELD("resource_id","uint32",16,4,SX_ID),
 SX_FIELD("resource_type","uint32",20,4,SX_ID),
 SX_FIELD("key_count","uint32",24,4,SX_COUNT_PROP),
};
const sx_layout sxmx_rez_resource_entry={UINT32_C(0x602E001A),"rez_resource_entry",sxmx_rez_resource_entry_fields,SX_COUNT(sxmx_rez_resource_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_rez_key_fields[]={
 SX_FIELD("key","uint32",0,4,SX_ID),
};
const sx_layout sxmx_rez_key={UINT32_C(0x602E001B),"rez_key",sxmx_rez_key_fields,SX_COUNT(sxmx_rez_key_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_rez(sxmx_view*v)
{if(!SM_ROW(rez_header,0,v->n))return false;struct{size_t at,n;}q[1024];unsigned used=0,count=1;q[0].at=sxmx_u32(v->p+131,false);q[0].n=sxmx_u32(v->p+135,false);while(used<count){size_t at=q[used].at,n=q[used++].n;if(!sxmx_need(v,at,n,v->n))return false;size_t end=at+n;while(at<end){if(!sxmx_need(v,at,16,end))return false;uint32_t kind=sxmx_u32(v->p+at,false),off=sxmx_u32(v->p+at+4,false),bytes=sxmx_u32(v->p+at+8,false);if(kind==1){if(count>=1024||!SM_ROW(rez_directory_entry,at,end))return false;at+=16;if(!sxmx_cstr(v,&at,end))return false;q[count].at=off;q[count++].n=bytes;}else if(kind==0){if(!SM_ROW(rez_resource_entry,at,end))return false;uint32_t keys=sxmx_u32(v->p+at+24,false);at+=28;if(!sxmx_cstr(v,&at,end)||!sxmx_cstr(v,&at,end)||!sxmx_table(v,&sxmx_rez_key,at,keys,end))return false;at+=(size_t)keys*4;}else return false;}}return true;}
bool sx_lithtech_rez_build(sxmx_view*v)
{
 return sxmx_rez(v);
}
#undef SM_ROW
