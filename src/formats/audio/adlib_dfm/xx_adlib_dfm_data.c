/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib DFM data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_dfm_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint8_t",4,1,SX_NONE),
    SX_FIELD("version_minor","uint8_t",5,1,SX_NONE),
    SX_FIELD("title_length","uint8_t",6,1,SX_COUNT_PROP),
    SX_FIELD("title","char[32]",7,32,SX_STRING),
    SX_FIELD("initial_speed","uint8_t",39,1,SX_NONE),
};
const sx_layout sxad_adlib_dfm_header = {UINT32_C(0x600f0027),"adlib_dfm_header",sxad_adlib_dfm_header_fields,SX_COUNT(sxad_adlib_dfm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_instrument_name_fields[] = {
    SX_FIELD("name_length","uint8_t",0,1,SX_COUNT_PROP),
    SX_FIELD("name","char[11]",1,11,SX_STRING),
};
const sx_layout sxad_adlib_dfm_instrument_name = {UINT32_C(0x600f0028),"adlib_dfm_instrument_name",sxad_adlib_dfm_instrument_name_fields,SX_COUNT(sxad_adlib_dfm_instrument_name_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_instrument_fields[] = {
    SX_FIELD("modulator_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",10,1,SX_FLAGS),
};
const sx_layout sxad_adlib_dfm_instrument = {UINT32_C(0x600f0029),"adlib_dfm_instrument",sxad_adlib_dfm_instrument_fields,SX_COUNT(sxad_adlib_dfm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_order_fields[] = {
    SX_FIELD("pattern_or_end","uint8_t",0,1,SX_FLAGS),
};
const sx_layout sxad_adlib_dfm_order = {UINT32_C(0x600f002a),"adlib_dfm_order",sxad_adlib_dfm_order_fields,SX_COUNT(sxad_adlib_dfm_order_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_pattern_count_fields[] = {
    SX_FIELD("pattern_count","uint8_t",0,1,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_dfm_pattern_count = {UINT32_C(0x600f002b),"adlib_dfm_pattern_count",sxad_adlib_dfm_pattern_count_fields,SX_COUNT(sxad_adlib_dfm_pattern_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_pattern_header_fields[] = {
    SX_FIELD("pattern_id","uint8_t",0,1,SX_ID),
};
const sx_layout sxad_adlib_dfm_pattern_header = {UINT32_C(0x600f002c),"adlib_dfm_pattern_header",sxad_adlib_dfm_pattern_header_fields,SX_COUNT(sxad_adlib_dfm_pattern_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_note_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
};
const sx_layout sxad_adlib_dfm_note = {UINT32_C(0x600f002d),"adlib_dfm_note",sxad_adlib_dfm_note_fields,SX_COUNT(sxad_adlib_dfm_note_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_note_effect_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("effect_parameter","uint8_t",1,1,SX_FLAGS),
};
const sx_layout sxad_adlib_dfm_note_effect = {UINT32_C(0x600f002e),"adlib_dfm_note_effect",sxad_adlib_dfm_note_effect_fields,SX_COUNT(sxad_adlib_dfm_note_effect_fields),SX_LE};
static bool sxad_dfm(sx_context *c)
{
    uint8_t major,count;int64_t at=905;uint64_t seen=0;
    if(!sxad_tag(c,0,"DFM\032",4)||!sxad_byte(c,4,&major)||major||!sxad_byte(c,904,&count)||!count||count>64)return false;
    if(!sx_add(c,&sxad_adlib_dfm_header,0,40)||!sx_table(c,&sxad_adlib_dfm_instrument_name,40,12,32)||!sx_table(c,&sxad_adlib_dfm_instrument,424,11,32)||!sx_table(c,&sxad_adlib_dfm_order,776,1,128)||!sx_add(c,&sxad_adlib_dfm_pattern_count,904,1))return false;
    for(unsigned i=0;i<count;i++){
        uint8_t id;if(!sxad_byte(c,at,&id)||id>=count||(seen&(UINT64_C(1)<<id))||!sxad_header(c,&sxad_adlib_dfm_pattern_header,&at,1))return false;seen|=UINT64_C(1)<<id;
        for(unsigned j=0;j<576;j++){uint8_t v;if(!sxad_byte(c,at,&v)||!sxad_header(c,v&128?&sxad_adlib_dfm_note_effect:&sxad_adlib_dfm_note,&at,v&128?2:1))return false;}
    }return at==c->size;
}
bool sx_adlib_dfm_build(sx_context*c)
{
    return sxad_dfm(c);
}
