/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib ROL data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_rol_header_fields[] = {
    SX_FIELD("version_minor","uint16_t",0,2,SX_NONE),
    SX_FIELD("version_major","uint16_t",2,2,SX_NONE),
    SX_FIELD("comment","char[40]",4,40,SX_STRING),
    SX_FIELD("ticks_per_beat","uint16_t",44,2,SX_NONE),
    SX_FIELD("beats_per_measure","uint16_t",46,2,SX_NONE),
    SX_FIELD("edit_scale_y","uint16_t",48,2,SX_NONE),
    SX_FIELD("edit_scale_x","uint16_t",50,2,SX_NONE),
    SX_FIELD("unused1","uint8_t[1]",52,1,SX_RESERVED),
    SX_FIELD("melodic_mode","uint8_t",53,1,SX_FLAGS),
    SX_FIELD("unused2","uint8_t[90]",54,90,SX_RESERVED),
    SX_FIELD("filler0","uint8_t[38]",144,38,SX_RESERVED),
    SX_FIELD("filler1","uint8_t[15]",182,15,SX_RESERVED),
    SX_FIELD("basic_tempo","float32",197,4,SX_NONE),
};
const sx_layout sxad_adlib_rol_header = {UINT32_C(0x600f0035),"adlib_rol_header",sxad_adlib_rol_header_fields,SX_COUNT(sxad_adlib_rol_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_tempo_count_fields[] = {
    SX_FIELD("tempo_event_count","uint16_t",0,2,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_rol_tempo_count = {UINT32_C(0x600f0036),"adlib_rol_tempo_count",sxad_adlib_rol_tempo_count_fields,SX_COUNT(sxad_adlib_rol_tempo_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_tempo_event_fields[] = {
    SX_FIELD("tick","int16",0,2,SX_NONE),
    SX_FIELD("tempo_multiplier","float32",2,4,SX_NONE),
};
const sx_layout sxad_adlib_rol_tempo_event = {UINT32_C(0x600f0037),"adlib_rol_tempo_event",sxad_adlib_rol_tempo_event_fields,SX_COUNT(sxad_adlib_rol_tempo_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_note_header_fields[] = {
    SX_FIELD("filler","uint8_t[15]",0,15,SX_RESERVED),
    SX_FIELD("total_ticks","int16",15,2,SX_NONE),
};
const sx_layout sxad_adlib_rol_note_header = {UINT32_C(0x600f0038),"adlib_rol_note_header",sxad_adlib_rol_note_header_fields,SX_COUNT(sxad_adlib_rol_note_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_note_event_fields[] = {
    SX_FIELD("note","int16",0,2,SX_NONE),
    SX_FIELD("duration_ticks","int16",2,2,SX_NONE),
};
const sx_layout sxad_adlib_rol_note_event = {UINT32_C(0x600f0039),"adlib_rol_note_event",sxad_adlib_rol_note_event_fields,SX_COUNT(sxad_adlib_rol_note_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_event_header_fields[] = {
    SX_FIELD("filler","uint8_t[15]",0,15,SX_RESERVED),
    SX_FIELD("event_count","uint16_t",15,2,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_rol_event_header = {UINT32_C(0x600f003a),"adlib_rol_event_header",sxad_adlib_rol_event_header_fields,SX_COUNT(sxad_adlib_rol_event_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_instrument_event_fields[] = {
    SX_FIELD("tick","int16",0,2,SX_NONE),
    SX_FIELD("instrument_name","char[9]",2,9,SX_STRING),
    SX_FIELD("filler","uint8_t[1]",11,1,SX_RESERVED),
    SX_FIELD("unused","uint8_t[2]",12,2,SX_RESERVED),
};
const sx_layout sxad_adlib_rol_instrument_event = {UINT32_C(0x600f003b),"adlib_rol_instrument_event",sxad_adlib_rol_instrument_event_fields,SX_COUNT(sxad_adlib_rol_instrument_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_volume_event_fields[] = {
    SX_FIELD("tick","int16",0,2,SX_NONE),
    SX_FIELD("volume_multiplier","float32",2,4,SX_NONE),
};
const sx_layout sxad_adlib_rol_volume_event = {UINT32_C(0x600f003c),"adlib_rol_volume_event",sxad_adlib_rol_volume_event_fields,SX_COUNT(sxad_adlib_rol_volume_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_pitch_event_fields[] = {
    SX_FIELD("tick","int16",0,2,SX_NONE),
    SX_FIELD("pitch_variation","float32",2,4,SX_NONE),
};
const sx_layout sxad_adlib_rol_pitch_event = {UINT32_C(0x600f003d),"adlib_rol_pitch_event",sxad_adlib_rol_pitch_event_fields,SX_COUNT(sxad_adlib_rol_pitch_event_fields),SX_LE};
static bool sxad_rol(sx_context *c)
{
    uint16_t minor,major,count;uint8_t mode;int64_t at=203;
    if(!sx_u16(c,0,false,&minor)||minor||!sx_u16(c,2,false,&major)||major!=4||!sxad_byte(c,53,&mode)||mode>1||!sx_u16(c,201,false,&count)||count>4096||!sx_add(c,&sxad_adlib_rol_header,0,201)||!sx_add(c,&sxad_adlib_rol_tempo_count,201,2)||!sx_table(c,&sxad_adlib_rol_tempo_event,at,6,count))return false;
    at+=6U*count;
    for(unsigned i=0;i<(mode?9U:11U);i++){
        uint16_t deadline;unsigned total=0;
        if(!sx_u16(c,at+15,false,&deadline)||deadline>=32768||!sxad_header(c,&sxad_adlib_rol_note_header,&at,17))return false;
        int64_t start=at;uint64_t notes=0;
        while(total<deadline){uint16_t note,duration;if(!sx_u16(c,at,false,&note)||note>127||!sx_u16(c,at+2,false,&duration)||!duration||duration>deadline-total)return false;total+=duration;at+=4;notes++;}
        if(!sx_table(c,&sxad_adlib_rol_note_event,start,4,notes))return false;
        for(unsigned j=0;j<3;j++){
            if(!sx_u16(c,at+15,false,&count)||count>4096||!sxad_header(c,&sxad_adlib_rol_event_header,&at,17))return false;
            const sx_layout *l=j==0?&sxad_adlib_rol_instrument_event:j==1?&sxad_adlib_rol_volume_event:&sxad_adlib_rol_pitch_event;int64_t size=j?6:14;
            if(!sx_table(c,l,at,size,count))return false;at+=size*count;
        }
    }return at==c->size;
}
bool sx_adlib_rol_build(sx_context*c)
{
    return sxad_rol(c);
}
