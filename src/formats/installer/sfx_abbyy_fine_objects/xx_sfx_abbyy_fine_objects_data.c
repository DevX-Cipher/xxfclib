/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_abbyy_fine_objects data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_abbyy_count_fields[] = {
    SX_FIELD("string_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxiex_abbyy_count = {0x6082001cU,"abbyy_count",sxiex_abbyy_count_fields,SX_COUNT(sxiex_abbyy_count_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_abbyy_string_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
};
const sx_layout sxiex_abbyy_string = {0x6082001dU,"abbyy_string",sxiex_abbyy_string_fields,SX_COUNT(sxiex_abbyy_string_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_abbyy_stream_size_fields[] = {
    SX_FIELD("stream_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_abbyy_stream_size = {0x6082001eU,"abbyy_stream_size",sxiex_abbyy_stream_size_fields,SX_COUNT(sxiex_abbyy_stream_size_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_abbyy_dates_fields[] = {
    SX_FIELD("first_date","uint32",0,4,SX_TIME),
    SX_FIELD("second_date","uint32",4,4,SX_TIME),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
const sx_layout sxiex_abbyy_dates = {0x6082001fU,"abbyy_dates",sxiex_abbyy_dates_fields,SX_COUNT(sxiex_abbyy_dates_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_abbyy_finear_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("marker","byte[3]",6,3,SX_SIGNATURE),
    SX_FIELD("crc16_arc","uint32",9,4,SX_CHECKSUM),
    SX_FIELD("unpacked_size","uint32",13,4,SX_SIZE),
};
const sx_layout sxiex_abbyy_finear = {0x60820020U,"abbyy_finear",sxiex_abbyy_finear_fields,SX_COUNT(sxiex_abbyy_finear_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_abbyy_trailer_fields[] = {
    SX_FIELD("overlay_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("signature","char[15]",4,15,SX_SIGNATURE),
};
const sx_layout sxiex_abbyy_trailer = {0x60820021U,"abbyy_trailer",sxiex_abbyy_trailer_fields,SX_COUNT(sxiex_abbyy_trailer_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_abbyy(sx_context*c,const sxiex_records*r){
 uint64_t p=0,at;uint32_t n,z;uint8_t q;
 if(c->size>=19&&sxiex_eq(c,(uint64_t)c->size-15,"ArcUpdateABBYY\0",15)&&sxiex_u32(c,(uint64_t)c->size-19,&z)){p=z;if(!SXIEX_ADD(c,abbyy_trailer,(uint64_t)c->size-19))return false;}else if(!sxiex_pe(c,&p))return true;
 at=p;if(!sxiex_u32(c,at,&n)||n>65535)return true;if(!SXIEX_ADD(c,abbyy_count,at))return false;at+=4;
 for(unsigned group=0;group<3;group++){
  for(uint32_t i=0;i<n;i++){if(!sxiex_read(c,at,&q,1)||!sxiex_span(c,at+1,q))return true;if(!SXIEX_ADD(c,abbyy_string,at)||!sxiex_name(c,at+1,q))return false;at+=1+q;}
  if(group==0){uint32_t count;if(!sxiex_u32(c,at,&count)||count!=n)return true;if(!SXIEX_ADD(c,abbyy_count,at))return false;at+=4;if(!sxiex_span(c,at,(uint64_t)n*4))return true;if(!sxiex_put(c,&sxiex_abbyy_stream_size,at,n))return false;at+=(uint64_t)n*4;if(!sxiex_u32(c,at,&n)||n>65535)return true;if(!SXIEX_ADD(c,abbyy_count,at))return false;at+=4;}
  else if(group==1)n=3;
 }
 if(sxiex_span(c,at,12)&&!SXIEX_ADD(c,abbyy_dates,at))return false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;if(m->header_size==17&&sxiex_eq(c,m->header,"FINEAR",6)&&!SXIEX_ADD(c,abbyy_finear,m->header))return false;}
 return true;
}
bool sx_sfx_abbyy_fine_objects_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_abbyy(c,records);
}
#undef SXIEX_ADD
