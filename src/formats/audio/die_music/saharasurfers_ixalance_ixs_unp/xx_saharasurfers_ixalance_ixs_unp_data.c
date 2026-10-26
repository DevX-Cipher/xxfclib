/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Saharasurfers Ixalance Ixs Unp data structures, moved out of the musiclate schema family. */
#include "../../../xx_format_schema_musiclate.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxlate_ixs_header_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("order_count","uint16",1,2,SX_COUNT_PROP),
 SX_FIELD("instrument_count","uint16",3,2,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint16",5,2,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint16",7,2,SX_COUNT_PROP),
 SX_FIELD("global_volume","uint8",9,1,SX_NONE),
 SX_FIELD("mix_volume","uint8",10,1,SX_NONE),
 SX_FIELD("speed","uint8",11,1,SX_NONE),
 SX_FIELD("tempo","uint8",12,1,SX_NONE),
 SX_FIELD("title","char[26]",13,26,SX_NONE),
 SX_FIELD("channel_volume","uint8[64]",39,64,SX_NONE),
 SX_FIELD("channel_pan","uint8[64]",103,64,SX_NONE),
};
const sx_layout sxlate_ixs_header={0x60930017U,"ixs_header",sxlate_ixs_header_fields,SX_COUNT(sxlate_ixs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_orders_fields[]={
 SX_FIELD("pattern_index","uint8",0,0,SX_NONE),
};
const sx_layout sxlate_ixs_orders={0x60930018U,"ixs_orders",sxlate_ixs_orders_fields,SX_COUNT(sxlate_ixs_orders_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_record_tag_fields[]={
 SX_FIELD("tag","char[1]",0,1,SX_SIGNATURE),
};
const sx_layout sxlate_ixs_record_tag={0x60930019U,"ixs_record_tag",sxlate_ixs_record_tag_fields,SX_COUNT(sxlate_ixs_record_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_keyboard_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("sample","uint8",1,1,SX_NONE),
};
const sx_layout sxlate_ixs_keyboard={0x6093001bU,"ixs_keyboard",sxlate_ixs_keyboard_fields,SX_COUNT(sxlate_ixs_keyboard_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_envelope_flags_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxlate_ixs_envelope_flags={0x6093001cU,"ixs_envelope_flags",sxlate_ixs_envelope_flags_fields,SX_COUNT(sxlate_ixs_envelope_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_envelope_fields[]={
 SX_FIELD("point_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("loop_begin","uint8",1,1,SX_NONE),
 SX_FIELD("loop_end","uint8",2,1,SX_NONE),
 SX_FIELD("sustain_begin","uint8",3,1,SX_NONE),
 SX_FIELD("sustain_end","uint8",4,1,SX_NONE),
};
const sx_layout sxlate_ixs_envelope={0x6093001dU,"ixs_envelope",sxlate_ixs_envelope_fields,SX_COUNT(sxlate_ixs_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_envelope_point_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
 SX_FIELD("tick","uint16",1,2,SX_NONE),
};
const sx_layout sxlate_ixs_envelope_point={0x6093001eU,"ixs_envelope_point",sxlate_ixs_envelope_point_fields,SX_COUNT(sxlate_ixs_envelope_point_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_sample_fields[]={
 SX_FIELD("global_volume","uint8",0,1,SX_NONE),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("sample_count","uint32",3,4,SX_COUNT_PROP),
 SX_FIELD("loop_begin","uint32",7,4,SX_NONE),
 SX_FIELD("loop_end","uint32",11,4,SX_NONE),
 SX_FIELD("sustain_begin","uint32",15,4,SX_NONE),
 SX_FIELD("sustain_end","uint32",19,4,SX_NONE),
 SX_FIELD("c5_speed","uint32",23,4,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",27,1,SX_NONE),
 SX_FIELD("vibrato_depth","uint8",28,1,SX_NONE),
 SX_FIELD("vibrato_rate","uint8",29,1,SX_NONE),
 SX_FIELD("vibrato_type","uint8",30,1,SX_NONE),
 SX_FIELD("default_pan","uint8",31,1,SX_NONE),
 SX_FIELD("filename","char[13]",32,13,SX_NONE),
};
const sx_layout sxlate_ixs_sample={0x6093001fU,"ixs_sample",sxlate_ixs_sample_fields,SX_COUNT(sxlate_ixs_sample_fields),SX_LE};
static bool sxlate_ixs(sx_context*c)
{
    uint8_t h[9],tag;uint64_t end=(uint64_t)c->size,p=167;
    if(!sxlate_read(c,0,h,9,end)||h[0]!=33||!sxlate_row(c,&sxlate_ixs_header,0,167,end))return false;
    uint16_t orders=xx_data_get_u16(h,9,1,false),instruments=xx_data_get_u16(h,9,3,false),samples=xx_data_get_u16(h,9,5,false),patterns=xx_data_get_u16(h,9,7,false);
    if(!sxlate_plane(c,&sxlate_ixs_orders,&p,orders,end))return false;
    if(instruments>1024||samples>1024||patterns>4096)return true;
    for(unsigned i=0;i<instruments;i++){
        if(!sxlate_byte(c,p,&tag,end)||(tag!='I'&&tag!='i')||!sxlate_row(c,&sxlate_ixs_record_tag,p++,1,end))return false;
        if(tag=='i')continue;
        uint8_t flags;
        if(!sxlate_byte(c,p+5,&flags,end)||!sxlate_row(c,&sxlate_ixs_instrument,p,6,end))return false;p+=6;
        if(!(flags&128)&&!sxlate_table(c,&sxlate_ixs_keyboard,&p,2,119,end))return false;
        for(unsigned e=0;e<3;e++){
            if(!sxlate_byte(c,p,&flags,end)||!sxlate_row(c,&sxlate_ixs_envelope_flags,p++,1,end))return false;
            if(flags){uint8_t count;
                if(!sxlate_byte(c,p,&count,end)||!sxlate_row(c,&sxlate_ixs_envelope,p,5,end))return false;p+=5;
                if(!sxlate_table(c,&sxlate_ixs_envelope_point,&p,3,count,end))return false;
            }
        }
    }
    for(unsigned i=0;i<samples;i++){
        if(!sxlate_byte(c,p,&tag,end)||(tag!='S'&&tag!='s')||!sxlate_row(c,&sxlate_ixs_record_tag,p++,1,end))return false;
        if(tag=='S'){if(!sxlate_row(c,&sxlate_ixs_sample,p,45,end))return false;p+=45;}
    }
    for(unsigned i=0;i<patterns;i++){
        if(!sxlate_byte(c,p,&tag,end)||(tag!='P'&&tag!='p')||!sxlate_row(c,&sxlate_ixs_record_tag,p++,1,end))return false;
        if(tag=='P'){uint16_t n;
            if(!sxlate_span(c,p,4,end)||!sx_u16(c,(int64_t)p,false,&n)||!sxlate_row(c,&sxlate_ixs_pattern,p,4,end))return false;p+=4;
            if(!sxlate_span(c,p,n,end))return false;p+=n;
        }
    }
    /* External SFXI/sample-cache data is not part of this physical reader. */
    return true;
}
bool sx_saharasurfers_ixalance_ixs_unp_build(sx_context*c)
{
    return sxlate_ixs(c);
}
