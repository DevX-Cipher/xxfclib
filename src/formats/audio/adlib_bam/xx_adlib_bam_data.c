/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib BAM data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_bam_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxad_adlib_bam_header = {UINT32_C(0x600f0019),"adlib_bam_header",sxad_adlib_bam_header_fields,SX_COUNT(sxad_adlib_bam_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_command_fields[] = {
    SX_FIELD("command_channel","uint8_t",0,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bam_command = {UINT32_C(0x600f001a),"adlib_bam_command",sxad_adlib_bam_command_fields,SX_COUNT(sxad_adlib_bam_command_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_note_fields[] = {
    SX_FIELD("command_channel","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("note","uint8_t",1,1,SX_NONE),
};
const sx_layout sxad_adlib_bam_note = {UINT32_C(0x600f001b),"adlib_bam_note",sxad_adlib_bam_note_fields,SX_COUNT(sxad_adlib_bam_note_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_instrument_fields[] = {
    SX_FIELD("command_channel","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("modulator_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",11,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bam_instrument = {UINT32_C(0x600f001c),"adlib_bam_instrument",sxad_adlib_bam_instrument_fields,SX_COUNT(sxad_adlib_bam_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_jump_fields[] = {
    SX_FIELD("command_label","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("repeat_mode","uint8_t",1,1,SX_FLAGS),
};
const sx_layout sxad_adlib_bam_jump = {UINT32_C(0x600f001d),"adlib_bam_jump",sxad_adlib_bam_jump_fields,SX_COUNT(sxad_adlib_bam_jump_fields),SX_LE};
static bool sxad_bam(sx_context *c)
{
    if(!sxad_tag(c,0,"CBMF",4)||!sx_add(c,&sxad_adlib_bam_header,0,4))return false;
    int64_t at=4;uint16_t labels=1;
    while(at<c->size){uint8_t v;if(!sxad_byte(c,at,&v))return false;const sx_layout *l=&sxad_adlib_bam_command;int64_t width=1;
        if(v<128){unsigned op=v&240,ch=v&15;
            if(!op)return sxad_header(c,l,&at,1)&&at==c->size;
            if(op==16){uint8_t note;if(ch>=9||!sxad_byte(c,at+1,&note)||note>=128)return false;l=&sxad_adlib_bam_note;width=2;}
            else if(op==32){if(ch>=9)return false;}
            else if(op==48){if(ch>=9)return false;l=&sxad_adlib_bam_instrument;width=12;}
            else if(op==80)labels|=(uint16_t)(1U<<ch);
            else if(op==96){if(!(labels&(1U<<ch)))return false;l=&sxad_adlib_bam_jump;width=2;}
            else if(op!=112||ch)return false;
        }if(!sxad_header(c,l,&at,width))return false;
    }return false;
}
bool sx_adlib_bam_build(sx_context*c)
{
    return sxad_bam(c);
}
