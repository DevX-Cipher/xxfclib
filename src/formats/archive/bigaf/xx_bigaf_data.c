/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AIX big archives data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_bigaf_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("member_table_offset","ascii_decimal[20]",8,20,SX_OFFSET),
    SX_FIELD("symbol_table_offset","ascii_decimal[20]",28,20,SX_OFFSET),
    SX_FIELD("symbol_table64_offset","ascii_decimal[20]",48,20,SX_OFFSET),
    SX_FIELD("first_member_offset","ascii_decimal[20]",68,20,SX_OFFSET),
    SX_FIELD("last_member_offset","ascii_decimal[20]",88,20,SX_OFFSET),
    SX_FIELD("free_list_offset","ascii_decimal[20]",108,20,SX_OFFSET),
};
const sx_layout sxar_bigaf_header = {UINT32_C(0x601c0034),"bigaf_header",sxar_bigaf_header_fields,SX_COUNT(sxar_bigaf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_bigaf_member_fields[] = {
    SX_FIELD("data_size","ascii_decimal[20]",0,20,SX_SIZE),
    SX_FIELD("next_member_offset","ascii_decimal[20]",20,20,SX_OFFSET),
    SX_FIELD("previous_member_offset","ascii_decimal[20]",40,20,SX_OFFSET),
    SX_FIELD("modified","ascii_decimal[12]",60,12,SX_TIME),
    SX_FIELD("uid","ascii_decimal[12]",72,12,SX_ID),
    SX_FIELD("gid","ascii_decimal[12]",84,12,SX_ID),
    SX_FIELD("mode","ascii_octal_padded[12]",96,12,SX_FLAGS),
    SX_FIELD("name_size","ascii_decimal[4]",108,4,SX_SIZE),
};
const sx_layout sxar_bigaf_member = {UINT32_C(0x601c0035),"bigaf_member",sxar_bigaf_member_fields,SX_COUNT(sxar_bigaf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxar_bigaf_name_end_fields[] = {
    SX_FIELD("terminator","char[2]",0,2,SX_SIGNATURE),
};
const sx_layout sxar_bigaf_name_end = {UINT32_C(0x601c0036),"bigaf_name_end",sxar_bigaf_name_end_fields,SX_COUNT(sxar_bigaf_name_end_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_decimal(const uint8_t *b,size_t n,uint64_t *v){size_t a=0;*v=0;while(a<n&&(b[a]==' '||b[a]=='\t'))a++;while(n>a&&(b[n-1]==' '||b[n-1]=='\t'||b[n-1]=='\n'||b[n-1]=='\r'))n--;for(;a<n;a++){unsigned d=b[a]-'0';if(d>9||*v>(UINT64_MAX-d)/10)return false;*v=*v*10+d;}return true;}
static bool sxar_bigaf(sx_context *c){uint8_t b[128];if(!sxar_read(c,0,b,128)||!sxar_add(c,&sxar_bigaf_header,0))return false;uint64_t p,last;if(!sxar_decimal(b+68,20,&p)||!sxar_decimal(b+88,20,&last))return true;
 for(unsigned i=0;i<SXAR_LIMIT&&p>=128;i++){uint64_t next,n,name;if(!sxar_read(c,p,b,112)||!sxar_decimal(b,20,&n)||!sxar_decimal(b+20,20,&next)||!sxar_decimal(b+108,4,&name)||!name||name>4096||!sxar_span(c,p+112,name))break;
  uint64_t term=(p+112+name+1)&~UINT64_C(1);if(!sxar_span(c,term,2)||!sxar_span(c,term+2,n))break;if(!sxar_add(c,&sxar_bigaf_member,p)||!sxar_add(c,&sxar_bigaf_name_end,term))return false;if(p==last||next<=p||next<term+2+n)break;p=next;}
 return true;}
bool sx_bigaf_build(sx_context*c)
{
 return sxar_bigaf(c);
}
