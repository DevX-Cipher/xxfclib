/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BLACKROCK_NSX data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsh_nsx_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("major_version","uint8",8,1,SX_ID),
    SX_FIELD("minor_version","uint8",9,1,SX_ID),
    SX_FIELD("header_size","uint32",10,4,SX_SIZE),
    SX_FIELD("label","char[16]",14,16,SX_STRING),
    SX_FIELD("comment","char[256]",30,256,SX_STRING),
    SX_FIELD("period","uint32",286,4,SX_NONE),
    SX_FIELD("time_resolution","uint32",290,4,SX_NONE),
    SX_FIELD("year","uint16",294,2,SX_NONE),
    SX_FIELD("month","uint16",296,2,SX_NONE),
    SX_FIELD("day_of_week","uint16",298,2,SX_NONE),
    SX_FIELD("day","uint16",300,2,SX_NONE),
    SX_FIELD("hour","uint16",302,2,SX_NONE),
    SX_FIELD("minute","uint16",304,2,SX_NONE),
    SX_FIELD("second","uint16",306,2,SX_NONE),
    SX_FIELD("millisecond","uint16",308,2,SX_NONE),
    SX_FIELD("channel_count","uint32",310,4,SX_COUNT_PROP),
};
const sx_layout sxsh_nsx_header = {UINT32_C(0x602a0001),"nsx_header",sxsh_nsx_header_fields,SX_COUNT(sxsh_nsx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsh_nsx_packet_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("timestamp","uint32",1,4,SX_NONE),
    SX_FIELD("sample_count","uint32",5,4,SX_COUNT_PROP),
};
const sx_layout sxsh_nsx_packet = {UINT32_C(0x602a0003),"nsx_packet",sxsh_nsx_packet_fields,SX_COUNT(sxsh_nsx_packet_fields),SX_LE};
static bool sxsh_nsx(sx_context *c)
{
 uint8_t b[314];if(!sx_read(c,0,b,314)||xx_rt_memcmp(b,"NEURALCD",8))return false;
 uint32_t count=sxsh32(b+310,false),header=sxsh32(b+10,false);int64_t at=header;
 if(!count||count>1024||header!=314U+66U*count||!sxsh_add(c,&sxsh_nsx_header,0,314)||!sxsh_table(c,&sxsh_nsx_channel,314,66,count))return false;
 for(unsigned i=0;at<c->size;i++){if(i>=4095||!sx_read(c,at,b,9)||b[0]!=1)return false;uint64_t n=(uint64_t)sxsh32(b+5,false)*count*2;if(!n||!sxsh_span(c,at+9,n)||!sxsh_add(c,&sxsh_nsx_packet,at,9))return false;at+=9+(int64_t)n;}
 return at==c->size;
}
bool sx_blackrock_nsx_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_nsx(c);
 return ok&&sxsh_finish(c);
}
