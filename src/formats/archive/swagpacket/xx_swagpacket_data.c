/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SWAG packets data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_swagpacket_header_fields[] = {
 SX_FIELD("banner","char[48]",0,48,SX_SIGNATURE),
 SX_FIELD("separator","char[1]",48,1,SX_RESERVED),
 SX_FIELD("entry_count","ascii_decimal[5]",49,5,SX_COUNT_PROP),
 SX_FIELD("padding","char[9]",54,9,SX_RESERVED),
 SX_FIELD("title","char[65]",63,65,SX_STRING),
};
const sx_layout sxag_swagpacket_header = {UINT32_C(0x60250029),"swagpacket_header",sxag_swagpacket_header_fields,SX_COUNT(sxag_swagpacket_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_swagpacket_entry_fields[] = {
 SX_FIELD("entry_index","ascii_decimal[8]",0,8,SX_ID),
 SX_FIELD("date","char[8]",8,8,SX_NONE),
 SX_FIELD("time","char[5]",16,5,SX_NONE),
 SX_FIELD("author","char[25]",21,25,SX_STRING),
 SX_FIELD("contributor","char[25]",46,25,SX_STRING),
 SX_FIELD("subject","char[25]",71,25,SX_STRING),
 SX_FIELD("keywords","char[20]",96,20,SX_STRING),
 SX_FIELD("block_count","ascii_decimal[7]",116,7,SX_COUNT_PROP),
 SX_FIELD("unknown123","uint8[4]",123,4,SX_NONE),
 SX_FIELD("separator","char[1]",127,1,SX_RESERVED),
};
const sx_layout sxag_swagpacket_entry = {UINT32_C(0x6025002a),"swagpacket_entry",sxag_swagpacket_entry_fields,SX_COUNT(sxag_swagpacket_entry_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_decimal(const uint8_t *b,unsigned n,uint64_t *v){uint64_t a=0;bool seen=false,tail=false;for(unsigned i=0;i<n;i++){if(b[i]==' '){if(seen)tail=true;continue;}if(tail||b[i]<'0'||b[i]>'9'||a>(UINT64_MAX-(b[i]-'0'))/10)return false;a=a*10+b[i]-'0';seen=true;}*v=a;return seen;}
static bool sxag_swag(sx_context *c){uint8_t b[128];if(!sxag_read(c,0,b,128)||!sxag_add(c,&sxag_swagpacket_header,0))return false;uint64_t n=0,p=128;if(!sxag_decimal(b+49,5,&n)||n>SXAG_LIMIT)return true;for(uint64_t i=0;i<n;i++){uint64_t blocks;if(!sxag_read(c,p,b,128)||!sxag_decimal(b+116,7,&blocks)||blocks<2||blocks>UINT64_MAX/128||!sxag_span(c,p,blocks*128))break;if(!sxag_add(c,&sxag_swagpacket_entry,p))return false;p+=blocks*128;}return true;}
bool sx_swagpacket_build(sx_context*c)
{
 return sxag_swag(c);
}
