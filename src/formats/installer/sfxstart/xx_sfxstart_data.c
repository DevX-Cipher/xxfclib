/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfxstart data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_sfxstart_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("payload_size","uint32",8,4,SX_SIZE),
    SX_FIELD("last_file_index","uint32",12,4,SX_NONE),
};
const sx_layout sxiex_sfxstart_header = {0x60820035U,"sfxstart_header",sxiex_sfxstart_header_fields,SX_COUNT(sxiex_sfxstart_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sfxstart_name_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("name_length","uint32",1,4,SX_SIZE),
};
const sx_layout sxiex_sfxstart_name = {0x60820036U,"sfxstart_name",sxiex_sfxstart_name_fields,SX_COUNT(sxiex_sfxstart_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sfxstart_size_fields[] = {
    SX_FIELD("marker","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("file_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxiex_sfxstart_size = {0x60820037U,"sfxstart_size",sxiex_sfxstart_size_fields,SX_COUNT(sxiex_sfxstart_size_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sfxstart_separator_fields[] = {
    SX_FIELD("marker","byte[3]",0,3,SX_SIGNATURE),
};
const sx_layout sxiex_sfxstart_separator = {0x60820038U,"sfxstart_separator",sxiex_sfxstart_separator_fields,SX_COUNT(sxiex_sfxstart_separator_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sfxstart_command_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("command_length","uint32",1,4,SX_SIZE),
};
const sx_layout sxiex_sfxstart_command = {0x60820039U,"sfxstart_command",sxiex_sfxstart_command_fields,SX_COUNT(sxiex_sfxstart_command_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_sfxstart_footer_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("header_offset","uint32",1,4,SX_OFFSET),
};
const sx_layout sxiex_sfxstart_footer = {0x6082003aU,"sfxstart_footer",sxiex_sfxstart_footer_fields,SX_COUNT(sxiex_sfxstart_footer_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_sfxstart(sx_context*c,const sxiex_records*r){
 uint64_t p=0;uint32_t footer;if(!sxiex_pe(c,&p)||!sxiex_eq(c,p,"SFXSTART",8)){if(c->size<4||!sxiex_u32(c,(uint64_t)c->size-4,&footer)||!sxiex_eq(c,footer,"SFXSTART",8))return true;p=footer;}
 if(!sxiex_span(c,p,16)||!SXIEX_ADD(c,sfxstart_header,p))return false;uint64_t end=0;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint8_t h[5];if(!sxiex_read(c,m->header,h,5)||h[0]!='*')continue;uint64_t n=sxiex32(h+1,false);if(!n||n>255||m->header_size!=11+n)continue;
 if(!SXIEX_ADD(c,sfxstart_name,m->header)||!sxiex_name(c,m->header+5,n)||!SXIEX_ADD(c,sfxstart_size,m->header+5+n))return false;
 uint64_t e=m->data+m->packed;if(sxiex_eq(c,e,"->\xf0",3)){if(!SXIEX_ADD(c,sfxstart_separator,e))return false;e+=3;}if(e>end)end=e;}
 uint8_t h[5];if(end&&sxiex_read(c,end,h,5)&&h[0]=='+'){uint64_t n=sxiex32(h+1,false);if(n<=65536&&sxiex_span(c,end+5,n+5)&&sxiex_eq(c,end+5+n,"-",1)){if(!SXIEX_ADD(c,sfxstart_command,end)||!sxiex_name(c,end+5,n)||!SXIEX_ADD(c,sfxstart_footer,end+5+n))return false;}}
 return true;
}
bool sx_sfxstart_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_sfxstart(c,records);
}
#undef SXIEX_ADD
