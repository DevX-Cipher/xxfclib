/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib RAD data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_rad_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint8_t",16,1,SX_NONE),
    SX_FIELD("flags","uint8_t",17,1,SX_FLAGS),
};
const sx_layout sxad_adlib_rad_header = {UINT32_C(0x600f0001),"adlib_rad_header",sxad_adlib_rad_header_fields,SX_COUNT(sxad_adlib_rad_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_instrument_fields[] = {
    SX_FIELD("instrument_number","uint8_t",0,1,SX_ID),
    SX_FIELD("modulator_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",11,1,SX_FLAGS),
};
const sx_layout sxad_adlib_rad_instrument = {UINT32_C(0x600f0002),"adlib_rad_instrument",sxad_adlib_rad_instrument_fields,SX_COUNT(sxad_adlib_rad_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_instrument_end_fields[] = {
    SX_FIELD("terminator","uint8_t",0,1,SX_SIGNATURE),
};
const sx_layout sxad_adlib_instrument_end = {UINT32_C(0x600f0003),"adlib_instrument_end",sxad_adlib_instrument_end_fields,SX_COUNT(sxad_adlib_instrument_end_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_order_count_fields[] = {
    SX_FIELD("order_count","uint8_t",0,1,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_rad_order_count = {UINT32_C(0x600f0004),"adlib_rad_order_count",sxad_adlib_rad_order_count_fields,SX_COUNT(sxad_adlib_rad_order_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_order_fields[] = {
    SX_FIELD("pattern_or_jump","uint8_t",0,1,SX_FLAGS),
};
const sx_layout sxad_adlib_rad_order = {UINT32_C(0x600f0005),"adlib_rad_order",sxad_adlib_rad_order_fields,SX_COUNT(sxad_adlib_rad_order_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_pattern_offset_fields[] = {
    SX_FIELD("pattern_offset","uint16_t",0,2,SX_OFFSET),
};
const sx_layout sxad_adlib_rad_pattern_offset = {UINT32_C(0x600f0006),"adlib_rad_pattern_offset",sxad_adlib_rad_pattern_offset_fields,SX_COUNT(sxad_adlib_rad_pattern_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_row_fields[] = {
    SX_FIELD("row_flags","uint8_t",0,1,SX_FLAGS),
};
const sx_layout sxad_adlib_rad_row = {UINT32_C(0x600f0007),"adlib_rad_row",sxad_adlib_rad_row_fields,SX_COUNT(sxad_adlib_rad_row_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_event_fields[] = {
    SX_FIELD("channel_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("note_octave","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("instrument_effect","uint8_t",2,1,SX_FLAGS),
};
const sx_layout sxad_adlib_rad_event = {UINT32_C(0x600f0008),"adlib_rad_event",sxad_adlib_rad_event_fields,SX_COUNT(sxad_adlib_rad_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_effect_event_fields[] = {
    SX_FIELD("channel_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("note_octave","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("instrument_effect","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("effect_parameter","uint8_t",3,1,SX_NONE),
};
const sx_layout sxad_adlib_rad_effect_event = {UINT32_C(0x600f0009),"adlib_rad_effect_event",sxad_adlib_rad_effect_event_fields,SX_COUNT(sxad_adlib_rad_effect_event_fields),SX_LE};
static bool sxad_rad(sx_context *c)
{
    uint8_t v,flags;int64_t at=18;unsigned last=0;uint16_t refs[32];
    if(!sxad_tag(c,0,"RAD by REALiTY!!",16)||!sxad_byte(c,16,&v)||v!=0x10||!sxad_byte(c,17,&flags)||(flags&0x20)||!sx_add(c,&sxad_adlib_rad_header,0,18))return false;
    if((flags&128)&&!sxad_zraw(c,&at,65536))return false;
    for(;;){if(!sxad_byte(c,at,&v))return false;if(!v){if(!sxad_header(c,&sxad_adlib_instrument_end,&at,1))return false;break;}
        if(v>31||v<=last||!sxad_header(c,&sxad_adlib_rad_instrument,&at,12))return false;last=v;
    }
    if(!sxad_byte(c,at,&v)||!v||v>128||!sxad_header(c,&sxad_adlib_rad_order_count,&at,1)||!sx_table(c,&sxad_adlib_rad_order,at,1,v))return false;
    unsigned orders=v;for(unsigned i=0;i<orders;i++){if(!sxad_byte(c,at+i,&v)||((v&128)?(v&127)>=orders:v>=32))return false;}at+=orders;
    if(!sx_table(c,&sxad_adlib_rad_pattern_offset,at,2,32))return false;
    for(unsigned i=0;i<32;i++)if(!sx_u16(c,at+2U*i,false,&refs[i]))return false;at+=64;
    int64_t max_end=0;
    for(unsigned i=0;i<32;i++)if(refs[i]){
        int64_t pos=refs[i],limit=c->size;unsigned previous=0;bool first=true,ended=false;
        if(pos<at)return false;
        for(unsigned j=0;j<32;j++)if(j!=i&&refs[j]){if(refs[j]==refs[i])return false;if(refs[j]>refs[i]&&refs[j]<limit)limit=refs[j];}
        for(unsigned rows=0;rows<64&&!ended;rows++){
            if(pos>=limit||!sxad_byte(c,pos,&v)||(v&127)>=64||(!first&&(v&127)<=previous))return false;
            previous=v&127;first=false;ended=(v&128)!=0;if(!sxad_header(c,&sxad_adlib_rad_row,&pos,1))return false;
            bool channel_end=false;
            for(unsigned channels=0;channels<1024&&!channel_end;channels++){
                uint8_t b[3];if(pos>limit||limit-pos<3||!sx_read(c,pos,b,3)||(b[0]&15)>=9||(b[0]&0x70))return false;
                int64_t size=(b[2]&15)?4:3;channel_end=(b[0]&128)!=0;
                if(size>limit-pos||!sxad_header(c,size==4?&sxad_adlib_rad_effect_event:&sxad_adlib_rad_event,&pos,size))return false;
            }if(!channel_end)return false;
        }if(!ended)return false;if(pos>max_end)max_end=pos;
    }return max_end==c->size;
}
bool sx_adlib_rad_build(sx_context*c)
{
    return sxad_rad(c);
}
