/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PAQ8 data structures, moved out of the archiveresidual schema family. */
#include "../../xx_format_schema_archiveresidual.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarfinal_paq8l_stored_header_fields[]={
 SX_FIELD("revision","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("space","uint8",5,1,SX_NONE),
 SX_FIELD("option_prefix","uint8",6,1,SX_NONE),
 SX_FIELD("compression_level","ascii_decimal[1]",7,1,SX_NONE),
 SX_FIELD("line_ending","uint8[2]",8,2,SX_NONE),
};
const sx_layout sxarfinal_paq8l_stored_header={UINT32_C(0x6092020d),"paq8l_stored_header",sxarfinal_paq8l_stored_header_fields,SX_COUNT(sxarfinal_paq8l_stored_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_member_size_fields[]={
 SX_FIELD("uncompressed_size","ascii_decimal",0,0,SX_SIZE),
};
const sx_layout sxarfinal_paq8_member_size={UINT32_C(0x6092020e),"paq8_member_size",sxarfinal_paq8_member_size_fields,SX_COUNT(sxarfinal_paq8_member_size_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_member_name_fields[]={
 SX_FIELD("name","char",0,0,SX_NONE),
};
const sx_layout sxarfinal_paq8_member_name={UINT32_C(0x6092020f),"paq8_member_name",sxarfinal_paq8_member_name_fields,SX_COUNT(sxarfinal_paq8_member_name_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_tab_fields[]={
 SX_FIELD("tab","uint8",0,1,SX_NONE),
};
const sx_layout sxarfinal_paq8_tab={UINT32_C(0x60920210),"paq8_tab",sxarfinal_paq8_tab_fields,SX_COUNT(sxarfinal_paq8_tab_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_line_ending_fields[]={
 SX_FIELD("line_ending","uint8[2]",0,2,SX_NONE),
};
const sx_layout sxarfinal_paq8_line_ending={UINT32_C(0x60920211),"paq8_line_ending",sxarfinal_paq8_line_ending_fields,SX_COUNT(sxarfinal_paq8_line_ending_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_directory_end_fields[]={
 SX_FIELD("directory_terminator","uint8",0,1,SX_NONE),
};
const sx_layout sxarfinal_paq8_directory_end={UINT32_C(0x60920212),"paq8_directory_end",sxarfinal_paq8_directory_end_fields,SX_COUNT(sxarfinal_paq8_directory_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8l_stored_frame_fields[]={
 SX_FIELD("preprocessor_type","uint8",0,1,SX_ID),
 SX_FIELD("uncompressed_bytes","int32",1,4,SX_SIZE),
};
const sx_layout sxarfinal_paq8l_stored_frame={UINT32_C(0x60920213),"paq8l_stored_frame",sxarfinal_paq8l_stored_frame_fields,SX_COUNT(sxarfinal_paq8l_stored_frame_fields),SX_BE};
#define SXARFINAL_LIMIT 20000U
static bool sxarfinal_variable(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){return n&&n<=4096&&c->count<SXARFINAL_LIMIT&&sxarfinal_span(c,p,n)&&sx_add(c,l,(int64_t)p,(int64_t)n);}
static bool sxarfinal_paq8(sx_context*c){
 uint8_t h[10];uint64_t p=10,total=0;unsigned members=0;
 if(!sxarfinal_read(c,0,h,10)||xx_rt_memcmp(h,"paq8l -0\r\n",10)||!sxarfinal_put(c,&sxarfinal_paq8l_stored_header,0))return false;
 for(;members<65536;members++){
  uint8_t v;if(!sxarfinal_read(c,p,&v,1))return false;if(v==26)break;uint64_t start=p,z=0;
  while(v>='0'&&v<='9'){if(z>(UINT64_MAX-(v-'0'))/10||p-start>=24)return false;z=z*10+(v-'0');p++;if(!sxarfinal_read(c,p,&v,1))return false;}
  if(p==start||v!=9||z>UINT64_MAX-total||!sxarfinal_variable(c,&sxarfinal_paq8_member_size,start,p-start)||!sxarfinal_put(c,&sxarfinal_paq8_tab,p))return false;
  total+=z;start=++p;
  while(sxarfinal_read(c,p,&v,1)&&v!=13){if(v<32||v==127||p-start>=4096)return false;p++;}
  if(p==start||!sxarfinal_variable(c,&sxarfinal_paq8_member_name,start,p-start)||!sxarfinal_read(c,p,h,2)||h[0]!=13||h[1]!=10||!sxarfinal_put(c,&sxarfinal_paq8_line_ending,p))return false;p+=2;
 }
 if(!members||members==65536||!sxarfinal_put(c,&sxarfinal_paq8_directory_end,p++))return false;
 uint64_t output=0;for(unsigned block=0;output<total&&block<SXARFINAL_LIMIT;block++){
  if(!sxarfinal_read(c,p,h,5)||h[0])return false;uint64_t z=sxarfinal_num(h+1,4,true);
  if(!z||z>INT32_MAX||z>total-output||!sxarfinal_span(c,p+5,z)||!sxarfinal_put(c,&sxarfinal_paq8l_stored_frame,p))return false;
  output+=z;p+=5+z;
 }
 return output==total;
}
bool sx_paq8_build(sx_context*c)
{
bool ok=false;
ok=sxarfinal_paq8(c);
(void)ok;return c->count&&sxarfinal_finish(c);
}
