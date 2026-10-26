/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Sierra SCI Sound Adlib chiptune (.SND) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_sci0_header_fields[]={
 SX_FIELD("resource_type","uint8",0,1,SX_ID),
 SX_FIELD("resource_header_size","uint8",1,1,SX_SIZE),
 SX_FIELD("digital_sample_flag","uint8",2,1,SX_FLAGS),
};
const sx_layout sxmw_sci0_header={UINT32_C(0x60870038),"sci0_header",sxmw_sci0_header_fields,SX_COUNT(sxmw_sci0_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sci0_channel_fields[]={
 SX_FIELD("channel_enabled","uint8",0,1,SX_FLAGS),
 SX_FIELD("initial_instrument","uint8",1,1,SX_ID),
};
const sx_layout sxmw_sci0_channel={UINT32_C(0x60870039),"sci0_channel",sxmw_sci0_channel_fields,SX_COUNT(sxmw_sci0_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sci1_header_fields[]={
 SX_FIELD("resource_type","uint8",0,1,SX_ID),
 SX_FIELD("resource_header_size","uint8",1,1,SX_SIZE),
 SX_FIELD("version_marker","uint8",2,1,SX_ID),
 SX_FIELD("opaque","bytes",3,9,SX_NONE),
};
const sx_layout sxmw_sci1_header={UINT32_C(0x6087003A),"sci1_header",sxmw_sci1_header_fields,SX_COUNT(sxmw_sci1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sci1_section_end_fields[]={
 SX_FIELD("unknown","bytes",0,2,SX_NONE),
};
const sx_layout sxmw_sci1_section_end={UINT32_C(0x6087003C),"sci1_section_end",sxmw_sci1_section_end_fields,SX_COUNT(sxmw_sci1_section_end_fields),SX_LE};
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_sci(sxmw_view*v)
{uint64_t end=v->c->size,p=0,x;if(!sxmw_eq(v,0,"\x84\0",2,end)||!sxmw_u(v,2,1,&x,end))return false;
 if(x!=0xf0)return MW_TAKE(sci0_header,&p,1,end)&&MW_TAKE(sci0_channel,&p,16,end);
 if(!MW_TAKE(sci1_header,&p,1,end))return false;
 for(unsigned section=0;section<256;section++){for(unsigned track=0;track<16;track++){uint64_t at;if(!sxmw_u(v,p+1,2,&at,end)||!sxmw_span(v,4,at,end)||!sxmw_u(v,p+5,1,&x,end)||!MW_TAKE(sci1_track,&p,1,end))return false;if(x==255)break;if(track==15)return false;}if(!sxmw_u(v,p,1,&x,end)||!MW_TAKE(sci1_section_end,&p,1,end))return false;if(x==255)return true;}return true;}
bool sx_sierra_scisound_build(sxmw_view*v)
{
 return sxmw_sci(v);
}
#undef MW_TAKE
