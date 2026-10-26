/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib BNK data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_bnk_header_fields[] = {
    SX_FIELD("version_major","uint8_t",0,1,SX_NONE),
    SX_FIELD("version_minor","uint8_t",1,1,SX_NONE),
    SX_FIELD("signature","char[6]",2,6,SX_SIGNATURE),
    SX_FIELD("used_entry_count","uint16_t",8,2,SX_COUNT_PROP),
    SX_FIELD("total_entry_count","uint16_t",10,2,SX_COUNT_PROP),
    SX_FIELD("name_list_offset","uint32_t",12,4,SX_OFFSET),
    SX_FIELD("instrument_data_offset","uint32_t",16,4,SX_OFFSET),
};
const sx_layout sxad_adlib_bnk_header = {UINT32_C(0x600f0016),"adlib_bnk_header",sxad_adlib_bnk_header_fields,SX_COUNT(sxad_adlib_bnk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bnk_name_fields[] = {
    SX_FIELD("instrument_index","uint16_t",0,2,SX_ID),
    SX_FIELD("record_used","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("name","char[9]",3,9,SX_STRING),
};
const sx_layout sxad_adlib_bnk_name = {UINT32_C(0x600f0017),"adlib_bnk_name",sxad_adlib_bnk_name_fields,SX_COUNT(sxad_adlib_bnk_name_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bnk_instrument_fields[] = {
    SX_FIELD("mode","uint8_t",0,1,SX_NONE),
    SX_FIELD("voice_number","uint8_t",1,1,SX_NONE),
    SX_FIELD("modulator_key_scale_level","uint8_t",2,1,SX_NONE),
    SX_FIELD("modulator_frequency_multiplier","uint8_t",3,1,SX_NONE),
    SX_FIELD("modulator_feedback","uint8_t",4,1,SX_NONE),
    SX_FIELD("modulator_attack_rate","uint8_t",5,1,SX_NONE),
    SX_FIELD("modulator_sustain_level","uint8_t",6,1,SX_NONE),
    SX_FIELD("modulator_sustaining_sound","uint8_t",7,1,SX_NONE),
    SX_FIELD("modulator_decay_rate","uint8_t",8,1,SX_NONE),
    SX_FIELD("modulator_release_rate","uint8_t",9,1,SX_NONE),
    SX_FIELD("modulator_output_level","uint8_t",10,1,SX_NONE),
    SX_FIELD("modulator_amplitude_vibrato","uint8_t",11,1,SX_NONE),
    SX_FIELD("modulator_frequency_vibrato","uint8_t",12,1,SX_NONE),
    SX_FIELD("modulator_envelope_scaling","uint8_t",13,1,SX_NONE),
    SX_FIELD("modulator_fm_type","uint8_t",14,1,SX_NONE),
    SX_FIELD("carrier_key_scale_level","uint8_t",15,1,SX_NONE),
    SX_FIELD("carrier_frequency_multiplier","uint8_t",16,1,SX_NONE),
    SX_FIELD("carrier_feedback","uint8_t",17,1,SX_NONE),
    SX_FIELD("carrier_attack_rate","uint8_t",18,1,SX_NONE),
    SX_FIELD("carrier_sustain_level","uint8_t",19,1,SX_NONE),
    SX_FIELD("carrier_sustaining_sound","uint8_t",20,1,SX_NONE),
    SX_FIELD("carrier_decay_rate","uint8_t",21,1,SX_NONE),
    SX_FIELD("carrier_release_rate","uint8_t",22,1,SX_NONE),
    SX_FIELD("carrier_output_level","uint8_t",23,1,SX_NONE),
    SX_FIELD("carrier_amplitude_vibrato","uint8_t",24,1,SX_NONE),
    SX_FIELD("carrier_frequency_vibrato","uint8_t",25,1,SX_NONE),
    SX_FIELD("carrier_envelope_scaling","uint8_t",26,1,SX_NONE),
    SX_FIELD("carrier_fm_type","uint8_t",27,1,SX_NONE),
    SX_FIELD("modulator_waveform","uint8_t",28,1,SX_NONE),
    SX_FIELD("carrier_waveform","uint8_t",29,1,SX_NONE),
};
const sx_layout sxad_adlib_bnk_instrument = {UINT32_C(0x600f0018),"adlib_bnk_instrument",sxad_adlib_bnk_instrument_fields,SX_COUNT(sxad_adlib_bnk_instrument_fields),SX_LE};
static bool sxad_bnk(sx_context *c)
{
    uint8_t version[2];uint16_t used,total;uint32_t names,data;
    if(!sx_read(c,0,version,2)||version[0]!=1||version[1]||!sxad_tag(c,2,"ADLIB-",6)||!sx_u16(c,8,false,&used)||!sx_u16(c,10,false,&total)||!sx_u32(c,12,false,&names)||!sx_u32(c,16,false,&data))return false;
    if(!used||used>total||total>1000||names<20||data<(uint64_t)names+12U*total||data>(uint64_t)c->size||(c->size-data)%30)return false;
    uint64_t count=(uint64_t)(c->size-data)/30;if(!count||count>1000)return false;
    return sx_add(c,&sxad_adlib_bnk_header,0,20)&&sx_table(c,&sxad_adlib_bnk_name,names,12,total)&&sx_table(c,&sxad_adlib_bnk_instrument,data,30,count);
}
bool sx_adlib_bnk_build(sx_context*c)
{
    return sxad_bnk(c);
}
