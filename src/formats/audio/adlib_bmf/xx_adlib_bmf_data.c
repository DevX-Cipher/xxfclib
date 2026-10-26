/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib BMF data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_bmf_signature_fields[] = {
    SX_FIELD("signature_version","char[6]",0,6,SX_SIGNATURE),
};
const sx_layout sxad_adlib_bmf_signature = {UINT32_C(0x600f001e),"adlib_bmf_signature",sxad_adlib_bmf_signature_fields,SX_COUNT(sxad_adlib_bmf_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_settings_fields[] = {
    SX_FIELD("speed","uint8_t",0,1,SX_NONE),
    SX_FIELD("instrument_mask","uint32_t",1,4,SX_FLAGS),
};
const sx_layout sxad_adlib_bmf_settings = {UINT32_C(0x600f001f),"adlib_bmf_settings",sxad_adlib_bmf_settings_fields,SX_COUNT(sxad_adlib_bmf_settings_fields),SX_BE};
static const xx_data_struct_field_desc sxad_adlib_bmf_instrument_fields[] = {
    SX_FIELD("name","char[11]",0,11,SX_STRING),
    SX_FIELD("modulator_characteristics","uint8_t",11,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",12,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",13,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",14,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",15,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",16,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",17,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",18,1,SX_FLAGS),
    SX_FIELD("frequency_low","uint8_t",19,1,SX_FLAGS),
    SX_FIELD("frequency_high_key","uint8_t",20,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",21,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",22,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",23,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bmf_instrument = {UINT32_C(0x600f0020),"adlib_bmf_instrument",sxad_adlib_bmf_instrument_fields,SX_COUNT(sxad_adlib_bmf_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_stream_flags_fields[] = {
    SX_FIELD("channel_mask","uint32_t",0,4,SX_FLAGS),
};
const sx_layout sxad_adlib_bmf_stream_flags = {UINT32_C(0x600f0021),"adlib_bmf_stream_flags",sxad_adlib_bmf_stream_flags_fields,SX_COUNT(sxad_adlib_bmf_stream_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxad_adlib_bmf_note_or_control_fields[] = {
    SX_FIELD("note_or_control","uint8_t",0,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bmf_note_or_control = {UINT32_C(0x600f0022),"adlib_bmf_note_or_control",sxad_adlib_bmf_note_or_control_fields,SX_COUNT(sxad_adlib_bmf_note_or_control_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_loop_fields[] = {
    SX_FIELD("command","uint8_t",0,1,SX_ID),
    SX_FIELD("repeat_count_encoded","uint8_t",1,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bmf_loop = {UINT32_C(0x600f0023),"adlib_bmf_loop",sxad_adlib_bmf_loop_fields,SX_COUNT(sxad_adlib_bmf_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_note_delay_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("delay_flags","uint8_t",1,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bmf_note_delay = {UINT32_C(0x600f0024),"adlib_bmf_note_delay",sxad_adlib_bmf_note_delay_fields,SX_COUNT(sxad_adlib_bmf_note_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_note_command_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("command","uint8_t",1,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bmf_note_command = {UINT32_C(0x600f0025),"adlib_bmf_note_command",sxad_adlib_bmf_note_command_fields,SX_COUNT(sxad_adlib_bmf_note_command_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_note_delay_command_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("delay_flags","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("command","uint8_t",2,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bmf_note_delay_command = {UINT32_C(0x600f0026),"adlib_bmf_note_delay_command",sxad_adlib_bmf_note_delay_command_fields,SX_COUNT(sxad_adlib_bmf_note_delay_command_fields),SX_LE};
static bool sxad_bmf(sx_context *c)
{
    int64_t at=6;uint32_t mask;uint8_t speed;
    if(!sxad_tag(c,0,"BMF1.1",6)||!sx_add(c,&sxad_adlib_bmf_signature,0,6)||!sxad_zraw(c,&at,4096)||!sxad_zraw(c,&at,4096)||!sxad_byte(c,at,&speed)||!speed||!sx_u32(c,at+1,true,&mask)||!sxad_header(c,&sxad_adlib_bmf_settings,&at,5))return false;
    for(unsigned i=0;i<32;i++)if(mask&(UINT32_C(0x80000000)>>i))if(!sxad_header(c,&sxad_adlib_bmf_instrument,&at,24))return false;
    if(!sx_u32(c,at,true,&mask)||!mask||(mask&UINT32_C(0x007fffff))||!sxad_header(c,&sxad_adlib_bmf_stream_flags,&at,4))return false;
    for(unsigned i=0;i<9;i++)if(mask&(UINT32_C(0x80000000)>>i)){
        bool loop=false,ended=false;
        for(unsigned events=0;events<1024&&!ended;events++){
            uint8_t v,q;int64_t size=1;const sx_layout *l=&sxad_adlib_bmf_note_or_control;
            if(!sxad_byte(c,at,&v))return false;
            if(v==254)ended=true;
            else if(v==252){loop=true;size=2;l=&sxad_adlib_bmf_loop;}
            else if(v==125){if(!loop)return false;}
            else if(v&128){
                if(!sxad_byte(c,at+1,&q))return false;
                if(q&128){size=2;l=&sxad_adlib_bmf_note_delay;if(q&64){if(!sxad_byte(c,at+2,&q)||q<32||q>=128)return false;size=3;l=&sxad_adlib_bmf_note_delay_command;}}
                else {if(q<32)return false;size=2;l=&sxad_adlib_bmf_note_command;}
            }
            if(!sxad_header(c,l,&at,size))return false;
        }if(!ended)return false;
    }return at==c->size;
}
bool sx_adlib_bmf_build(sx_context*c)
{
    return sxad_bmf(c);
}
