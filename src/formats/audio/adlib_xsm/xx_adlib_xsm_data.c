/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib XSM data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_xsm_header_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("notes_per_channel","uint16_t",6,2,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_xsm_header = {UINT32_C(0x600f0045),"adlib_xsm_header",sxad_adlib_xsm_header_fields,SX_COUNT(sxad_adlib_xsm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_xsm_instrument_fields[] = {
    SX_FIELD("modulator_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("unused","uint8_t[5]",11,5,SX_RESERVED),
};
const sx_layout sxad_adlib_xsm_instrument = {UINT32_C(0x600f0046),"adlib_xsm_instrument",sxad_adlib_xsm_instrument_fields,SX_COUNT(sxad_adlib_xsm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_xsm_note_fields[] = {
    SX_FIELD("note","uint8_t",0,1,SX_NONE),
};
const sx_layout sxad_adlib_xsm_note = {UINT32_C(0x600f0047),"adlib_xsm_note",sxad_adlib_xsm_note_fields,SX_COUNT(sxad_adlib_xsm_note_fields),SX_LE};
static bool sxad_xsm(sx_context *c)
{
    uint16_t n;if(!sxad_tag(c,0,"ofTAZ!",6)||!sx_u16(c,6,false,&n)||!n||n>3200||c->size!=152+(int64_t)n*9)return false;
    return sx_add(c,&sxad_adlib_xsm_header,0,8)&&sx_table(c,&sxad_adlib_xsm_instrument,8,16,9)&&sx_table(c,&sxad_adlib_xsm_note,152,1,(uint64_t)n*9);
}
bool sx_adlib_xsm_build(sx_context*c)
{
    return sxad_xsm(c);
}
