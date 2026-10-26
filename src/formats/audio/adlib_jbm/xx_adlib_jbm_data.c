/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib JBM data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_jbm_header_fields[] = {
    SX_FIELD("format_marker","uint16_t",0,2,SX_SIGNATURE),
    SX_FIELD("timer_divisor","uint16_t",2,2,SX_NONE),
    SX_FIELD("sequence_table_offset","uint16_t",4,2,SX_OFFSET),
    SX_FIELD("instrument_table_offset","uint16_t",6,2,SX_OFFSET),
    SX_FIELD("flags","uint16_t",8,2,SX_FLAGS),
    SX_FIELD("voice0_order_offset","uint16_t",10,2,SX_OFFSET),
    SX_FIELD("voice1_order_offset","uint16_t",12,2,SX_OFFSET),
    SX_FIELD("voice2_order_offset","uint16_t",14,2,SX_OFFSET),
    SX_FIELD("voice3_order_offset","uint16_t",16,2,SX_OFFSET),
    SX_FIELD("voice4_order_offset","uint16_t",18,2,SX_OFFSET),
    SX_FIELD("voice5_order_offset","uint16_t",20,2,SX_OFFSET),
    SX_FIELD("voice6_order_offset","uint16_t",22,2,SX_OFFSET),
    SX_FIELD("voice7_order_offset","uint16_t",24,2,SX_OFFSET),
    SX_FIELD("voice8_order_offset","uint16_t",26,2,SX_OFFSET),
    SX_FIELD("voice9_order_offset","uint16_t",28,2,SX_OFFSET),
    SX_FIELD("voice10_order_offset","uint16_t",30,2,SX_OFFSET),
};
const sx_layout sxad_adlib_jbm_header = {UINT32_C(0x600f003e),"adlib_jbm_header",sxad_adlib_jbm_header_fields,SX_COUNT(sxad_adlib_jbm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_sequence_offset_fields[] = {
    SX_FIELD("sequence_offset","uint16_t",0,2,SX_OFFSET),
};
const sx_layout sxad_adlib_jbm_sequence_offset = {UINT32_C(0x600f003f),"adlib_jbm_sequence_offset",sxad_adlib_jbm_sequence_offset_fields,SX_COUNT(sxad_adlib_jbm_sequence_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_order_fields[] = {
    SX_FIELD("sequence_or_end","uint8_t",0,1,SX_FLAGS),
};
const sx_layout sxad_adlib_jbm_order = {UINT32_C(0x600f0040),"adlib_jbm_order",sxad_adlib_jbm_order_fields,SX_COUNT(sxad_adlib_jbm_order_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_end_fields[] = {
    SX_FIELD("terminator","uint8_t",0,1,SX_SIGNATURE),
};
const sx_layout sxad_adlib_jbm_end = {UINT32_C(0x600f0041),"adlib_jbm_end",sxad_adlib_jbm_end_fields,SX_COUNT(sxad_adlib_jbm_end_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_instrument_select_fields[] = {
    SX_FIELD("command","uint8_t",0,1,SX_ID),
    SX_FIELD("instrument_index","uint8_t",1,1,SX_ID),
};
const sx_layout sxad_adlib_jbm_instrument_select = {UINT32_C(0x600f0042),"adlib_jbm_instrument_select",sxad_adlib_jbm_instrument_select_fields,SX_COUNT(sxad_adlib_jbm_instrument_select_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_note_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("volume","uint8_t",1,1,SX_NONE),
    SX_FIELD("delay_minus_one","uint16_t",2,2,SX_NONE),
};
const sx_layout sxad_adlib_jbm_note = {UINT32_C(0x600f0043),"adlib_jbm_note",sxad_adlib_jbm_note_fields,SX_COUNT(sxad_adlib_jbm_note_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_instrument_fields[] = {
    SX_FIELD("modulator_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level_encoded","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level_encoded","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("waveforms_feedback","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("unused","uint8_t[7]",9,7,SX_RESERVED),
};
const sx_layout sxad_adlib_jbm_instrument = {UINT32_C(0x600f0044),"adlib_jbm_instrument",sxad_adlib_jbm_instrument_fields,SX_COUNT(sxad_adlib_jbm_instrument_fields),SX_LE};
static bool sxad_jbm(sx_context *c)
{
    uint16_t marker,speed,table,inst,flags,refs[11];uint32_t first=65536,pool=65536;uint8_t used[255]={0};
    if(!sx_u16(c,0,false,&marker)||marker!=2||!sx_u16(c,2,false,&speed)||!speed||!sx_u16(c,4,false,&table)||table!=32||!sx_u16(c,6,false,&inst)||inst<=32||inst>=c->size||(c->size-inst)%16||!sx_u16(c,8,false,&flags)||(flags&~1U))return false;
    uint64_t patches=(uint64_t)(c->size-inst)/16;if(!patches||patches>256)return false;
    for(unsigned i=0;i<11;i++){if(!sx_u16(c,10+2U*i,false,&refs[i]))return false;if(refs[i]){if(refs[i]<table||refs[i]>=inst)return false;if(refs[i]<first)first=refs[i];}}
    if(first<=table||first>=inst||(first-table)%2)return false;unsigned sequences=(first-table)/2;if(!sequences||sequences>255)return false;
    for(unsigned i=0;i<11;i++)if(refs[i]){uint8_t v=0;int64_t at=refs[i];while(at<inst){if(!sxad_byte(c,at++,&v))return false;if(v==255)break;if(v>=sequences)return false;used[v]=1;}if(v!=255)return false;}
    uint16_t sequence_refs[255];
    for(unsigned i=0;i<sequences;i++){if(!sx_u16(c,table+2U*i,false,&sequence_refs[i]))return false;if(used[i]){if(sequence_refs[i]<=first||sequence_refs[i]>=inst)return false;if(sequence_refs[i]<pool)pool=sequence_refs[i];}}
    if(pool>=inst||!sx_add(c,&sxad_adlib_jbm_header,0,32)||!sx_table(c,&sxad_adlib_jbm_sequence_offset,table,2,sequences)||!sx_table(c,&sxad_adlib_jbm_order,first,1,pool-first)||!sx_table(c,&sxad_adlib_jbm_instrument,inst,16,patches))return false;
    /* Verify each sequence index used by a voice points at a physical start. */
    bool found[255]={0};int64_t at=pool;
    while(at<inst){for(unsigned i=0;i<sequences;i++)if(sequence_refs[i]==at)found[i]=true;bool ended=false;
        while(at<inst&&!ended){uint8_t v;if(!sxad_byte(c,at,&v))return false;int64_t size;const sx_layout *l;
            if(v==255){size=1;l=&sxad_adlib_jbm_end;ended=true;}
            else if(v==253){uint8_t id;if(!sxad_byte(c,at+1,&id)||id>=patches)return false;size=2;l=&sxad_adlib_jbm_instrument_select;}
            else {uint8_t volume;if((v&127)>95||!sxad_byte(c,at+1,&volume)||volume>63)return false;size=4;l=&sxad_adlib_jbm_note;}
            if(size>inst-at||!sxad_header(c,l,&at,size))return false;
        }if(!ended)return false;
    }
    for(unsigned i=0;i<sequences;i++)if(used[i]&&!found[i])return false;
    for(unsigned i=0;i<11;i++)if(refs[i]){int64_t pos=refs[i];uint8_t v=0;if(pos>=pool)return false;while(pos<pool){if(!sxad_byte(c,pos++,&v))return false;if(v==255)break;}if(v!=255)return false;}
    return true;
}
bool sx_adlib_jbm_build(sx_context*c)
{
    return sxad_jbm(c);
}
