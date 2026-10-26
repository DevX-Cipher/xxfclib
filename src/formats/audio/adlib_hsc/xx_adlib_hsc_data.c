/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib HSC data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_hsc_instrument_fields[] = {
    SX_FIELD("carrier_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("modulator_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("slide_encoded","uint8_t",11,1,SX_FLAGS),
};
const sx_layout sxad_adlib_hsc_instrument = {UINT32_C(0x600f000a),"adlib_hsc_instrument",sxad_adlib_hsc_instrument_fields,SX_COUNT(sxad_adlib_hsc_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_hsc_order_fields[] = {
    SX_FIELD("pattern_or_jump_or_end","uint8_t",0,1,SX_FLAGS),
};
const sx_layout sxad_adlib_hsc_order = {UINT32_C(0x600f000b),"adlib_hsc_order",sxad_adlib_hsc_order_fields,SX_COUNT(sxad_adlib_hsc_order_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_hsc_event_fields[] = {
    SX_FIELD("note_or_instrument","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("effect_or_instrument","uint8_t",1,1,SX_FLAGS),
};
const sx_layout sxad_adlib_hsc_event = {UINT32_C(0x600f000c),"adlib_hsc_event",sxad_adlib_hsc_event_fields,SX_COUNT(sxad_adlib_hsc_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_zero_terminator_fields[] = {
    SX_FIELD("terminator","uint8_t",0,1,SX_SIGNATURE),
};
const sx_layout sxad_adlib_zero_terminator = {UINT32_C(0x600f000d),"adlib_zero_terminator",sxad_adlib_zero_terminator_fields,SX_COUNT(sxad_adlib_zero_terminator_fields),SX_LE};
static bool sxad_hsc(sx_context *c)
{
    if(c->size<2739||c->size>59188)return false;
    int64_t payload=c->size-1587;uint64_t patterns=(uint64_t)payload/1152;uint8_t pad;
    if(!patterns||patterns>50||(payload%1152!=0&&payload%1152!=1))return false;
    if(payload%1152&&(!sxad_byte(c,c->size-1,&pad)||pad))return false;
    if(!sx_table(c,&sxad_adlib_hsc_instrument,0,12,128)||!sx_table(c,&sxad_adlib_hsc_order,1536,1,51)||!sx_table(c,&sxad_adlib_hsc_event,1587,2,patterns*576))return false;
    return !(payload%1152)||sx_add(c,&sxad_adlib_zero_terminator,c->size-1,1);
}
bool sx_adlib_hsc_build(sx_context*c)
{
    return sxad_hsc(c);
}
