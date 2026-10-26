/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib LDS data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_lds_header_fields[] = {
    SX_FIELD("mode","uint8_t",0,1,SX_NONE),
    SX_FIELD("timer_divisor","uint16_t",1,2,SX_NONE),
    SX_FIELD("tempo","uint8_t",3,1,SX_NONE),
    SX_FIELD("pattern_row_count","uint8_t",4,1,SX_COUNT_PROP),
    SX_FIELD("channel0_delay","uint8_t",5,1,SX_NONE),
    SX_FIELD("channel1_delay","uint8_t",6,1,SX_NONE),
    SX_FIELD("channel2_delay","uint8_t",7,1,SX_NONE),
    SX_FIELD("channel3_delay","uint8_t",8,1,SX_NONE),
    SX_FIELD("channel4_delay","uint8_t",9,1,SX_NONE),
    SX_FIELD("channel5_delay","uint8_t",10,1,SX_NONE),
    SX_FIELD("channel6_delay","uint8_t",11,1,SX_NONE),
    SX_FIELD("channel7_delay","uint8_t",12,1,SX_NONE),
    SX_FIELD("channel8_delay","uint8_t",13,1,SX_NONE),
    SX_FIELD("rhythm_register","uint8_t",14,1,SX_FLAGS),
    SX_FIELD("patch_count","uint16_t",15,2,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_lds_header = {UINT32_C(0x600f002f),"adlib_lds_header",sxad_adlib_lds_header_fields,SX_COUNT(sxad_adlib_lds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_patch_fields[] = {
    SX_FIELD("modulator_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("key_off","uint8_t",11,1,SX_NONE),
    SX_FIELD("portamento","uint8_t",12,1,SX_NONE),
    SX_FIELD("glide","uint8_t",13,1,SX_NONE),
    SX_FIELD("fine_tune","uint8_t",14,1,SX_NONE),
    SX_FIELD("vibrato","uint8_t",15,1,SX_FLAGS),
    SX_FIELD("vibrato_delay","uint8_t",16,1,SX_NONE),
    SX_FIELD("modulator_tremolo","uint8_t",17,1,SX_FLAGS),
    SX_FIELD("carrier_tremolo","uint8_t",18,1,SX_FLAGS),
    SX_FIELD("tremolo_wait","uint8_t",19,1,SX_NONE),
    SX_FIELD("arpeggio","uint8_t",20,1,SX_FLAGS),
    SX_FIELD("arpeggio_table","uint8_t[12]",21,12,SX_NONE),
    SX_FIELD("digital_start","uint16_t",33,2,SX_NONE),
    SX_FIELD("digital_size","uint16_t",35,2,SX_NONE),
    SX_FIELD("fms","uint8_t",37,1,SX_NONE),
    SX_FIELD("transpose","uint16_t",38,2,SX_NONE),
    SX_FIELD("midi_instrument","uint8_t",40,1,SX_ID),
    SX_FIELD("midi_velocity","uint8_t",41,1,SX_NONE),
    SX_FIELD("midi_key","uint8_t",42,1,SX_NONE),
    SX_FIELD("midi_transpose","uint8_t",43,1,SX_NONE),
    SX_FIELD("midi_reserved","uint8_t[2]",44,2,SX_RESERVED),
};
const sx_layout sxad_adlib_lds_patch = {UINT32_C(0x600f0030),"adlib_lds_patch",sxad_adlib_lds_patch_fields,SX_COUNT(sxad_adlib_lds_patch_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_position_count_fields[] = {
    SX_FIELD("position_count","uint16_t",0,2,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_lds_position_count = {UINT32_C(0x600f0031),"adlib_lds_position_count",sxad_adlib_lds_position_count_fields,SX_COUNT(sxad_adlib_lds_position_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_position_fields[] = {
    SX_FIELD("pattern_offset","uint16_t",0,2,SX_OFFSET),
    SX_FIELD("transpose_flags","uint8_t",2,1,SX_FLAGS),
};
const sx_layout sxad_adlib_lds_position = {UINT32_C(0x600f0032),"adlib_lds_position",sxad_adlib_lds_position_fields,SX_COUNT(sxad_adlib_lds_position_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_digital_count_fields[] = {
    SX_FIELD("digital_sound_count","uint16_t",0,2,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_lds_digital_count = {UINT32_C(0x600f0033),"adlib_lds_digital_count",sxad_adlib_lds_digital_count_fields,SX_COUNT(sxad_adlib_lds_digital_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_pattern_word_fields[] = {
    SX_FIELD("event_word","uint16_t",0,2,SX_FLAGS),
};
const sx_layout sxad_adlib_lds_pattern_word = {UINT32_C(0x600f0034),"adlib_lds_pattern_word",sxad_adlib_lds_pattern_word_fields,SX_COUNT(sxad_adlib_lds_pattern_word_fields),SX_LE};
static bool sxad_lds(sx_context *c)
{
    uint8_t mode,tempo,len;uint16_t speed,patches,positions;int64_t at=17;
    if(!sxad_byte(c,0,&mode)||mode>2||!sx_u16(c,1,false,&speed)||!speed||!sxad_byte(c,3,&tempo)||!tempo||!sxad_byte(c,4,&len)||!len||!sx_u16(c,15,false,&patches)||!patches||patches>64||!sx_add(c,&sxad_adlib_lds_header,0,17)||!sx_table(c,&sxad_adlib_lds_patch,at,46,patches))return false;
    at+=46U*patches;
    if(!sx_u16(c,at,false,&positions)||!positions||positions>256||!sxad_header(c,&sxad_adlib_lds_position_count,&at,2)||!sx_table(c,&sxad_adlib_lds_position,at,3,9U*positions))return false;
    int64_t position_start=at;at+=27U*positions;
    if(!sxad_header(c,&sxad_adlib_lds_digital_count,&at,2)||at>=c->size||((c->size-at)&1))return false;
    for(unsigned i=0;i<9U*positions;i++){uint16_t off;if(!sx_u16(c,position_start+3U*i,false,&off)||(off&1)||off>=c->size-at)return false;}
    return sx_table(c,&sxad_adlib_lds_pattern_word,at,2,(uint64_t)(c->size-at)/2);
}
bool sx_adlib_lds_build(sx_context*c)
{
    return sxad_lds(c);
}
