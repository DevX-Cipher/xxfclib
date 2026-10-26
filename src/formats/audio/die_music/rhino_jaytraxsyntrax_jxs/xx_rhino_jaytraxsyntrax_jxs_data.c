/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Rhino Jaytraxsyntrax Jxs data structures, moved out of the musiclate schema family. */
#include "../../../xx_format_schema_musiclate.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxlate_jxs_header_fields[]={
 SX_FIELD("version","int16",0,2,SX_NONE),
 SX_FIELD("reserved_0","int16",2,2,SX_NONE),
 SX_FIELD("pattern_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("subsong_count","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("instrument_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[36]",16,36,SX_NONE),
};
const sx_layout sxlate_jxs_header={0x6093000cU,"jxs_header",sxlate_jxs_header_fields,SX_COUNT(sxlate_jxs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_order_fields[]={
 SX_FIELD("pattern_index","int16",0,2,SX_NONE),
 SX_FIELD("pattern_length","int16",2,2,SX_COUNT_PROP),
};
const sx_layout sxlate_jxs_order={0x6093000eU,"jxs_order",sxlate_jxs_order_fields,SX_COUNT(sxlate_jxs_order_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_event_fields[]={
 SX_FIELD("source_note","uint8",0,1,SX_NONE),
 SX_FIELD("destination_note","uint8",1,1,SX_NONE),
 SX_FIELD("instrument","uint8",2,1,SX_NONE),
 SX_FIELD("parameter","int8",3,1,SX_NONE),
 SX_FIELD("script","uint8",4,1,SX_NONE),
};
const sx_layout sxlate_jxs_event={0x6093000fU,"jxs_event",sxlate_jxs_event_fields,SX_COUNT(sxlate_jxs_event_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_pattern_name_size_fields[]={
 SX_FIELD("name_bytes","int32",0,4,SX_SIZE),
};
const sx_layout sxlate_jxs_pattern_name_size={0x60930010U,"jxs_pattern_name_size",sxlate_jxs_pattern_name_size_fields,SX_COUNT(sxlate_jxs_pattern_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_pattern_name_fields[]={
 SX_FIELD("name","char",0,0,SX_NONE),
};
const sx_layout sxlate_jxs_pattern_name={0x60930011U,"jxs_pattern_name",sxlate_jxs_pattern_name_fields,SX_COUNT(sxlate_jxs_pattern_name_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_instrument_fields[]={
 SX_FIELD("version","int16",0,2,SX_NONE),
 SX_FIELD("name","char[32]",2,32,SX_NONE),
 SX_FIELD("waveform","int16",34,2,SX_NONE),
 SX_FIELD("wavelength","int16",36,2,SX_NONE),
 SX_FIELD("master_volume","int16",38,2,SX_NONE),
 SX_FIELD("am_wave","int16",40,2,SX_NONE),
 SX_FIELD("am_speed","int16",42,2,SX_NONE),
 SX_FIELD("am_loop_point","int16",44,2,SX_NONE),
 SX_FIELD("fine_tune","int16",46,2,SX_NONE),
 SX_FIELD("fm_wave","int16",48,2,SX_NONE),
 SX_FIELD("fm_speed","int16",50,2,SX_NONE),
 SX_FIELD("fm_loop_point","int16",52,2,SX_NONE),
 SX_FIELD("fm_delay","int16",54,2,SX_NONE),
 SX_FIELD("arpeggio","int16",56,2,SX_NONE),
 SX_FIELD("reset_wave","int8[16]",58,16,SX_NONE),
 SX_FIELD("pan_wave","int16",74,2,SX_NONE),
 SX_FIELD("pan_speed","int16",76,2,SX_NONE),
 SX_FIELD("pan_loop_point","int16",78,2,SX_NONE),
 SX_FIELD("reserved","uint8[12]",80,12,SX_NONE),
};
const sx_layout sxlate_jxs_instrument={0x60930012U,"jxs_instrument",sxlate_jxs_instrument_fields,SX_COUNT(sxlate_jxs_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_effect_fields[]={
 SX_FIELD("destination_effect","int32",0,4,SX_NONE),
 SX_FIELD("source_effect_1","int32",4,4,SX_NONE),
 SX_FIELD("source_effect_2","int32",8,4,SX_NONE),
 SX_FIELD("oscillator_effect","int32",12,4,SX_NONE),
 SX_FIELD("effect_variable_1","int32",16,4,SX_NONE),
 SX_FIELD("effect_variable_2","int32",20,4,SX_NONE),
 SX_FIELD("effect_speed","int32",24,4,SX_NONE),
 SX_FIELD("oscillator_speed","int32",28,4,SX_NONE),
 SX_FIELD("effect_type","int32",32,4,SX_NONE),
 SX_FIELD("oscillator_flag","int8",36,1,SX_NONE),
 SX_FIELD("reset_effect","int8",37,1,SX_NONE),
 SX_FIELD("reserved","int16",38,2,SX_NONE),
};
const sx_layout sxlate_jxs_effect={0x60930013U,"jxs_effect",sxlate_jxs_effect_fields,SX_COUNT(sxlate_jxs_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_wave_fields[]={
 SX_FIELD("sample","int16le[256]",0,512,SX_NONE),
};
const sx_layout sxlate_jxs_wave={0x60930015U,"jxs_wave",sxlate_jxs_wave_fields,SX_COUNT(sxlate_jxs_wave_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_arpeggio_fields[]={
 SX_FIELD("step","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxlate_jxs_arpeggio={0x60930016U,"jxs_arpeggio",sxlate_jxs_arpeggio_fields,SX_COUNT(sxlate_jxs_arpeggio_fields),SX_LE};
static bool sxlate_jxs(sx_context*c)
{
    uint8_t h[16];uint64_t end=(uint64_t)c->size,p=52;uint32_t patterns,songs,instruments;
    if(!sxlate_read(c,0,h,16,end))return false;
    uint16_t version=xx_data_get_u16(h,16,0,false);
    if(version<3456||version>3457||!sxlate_row(c,&sxlate_jxs_header,0,52,end))return false;
    patterns=xx_data_get_u32(h,16,4,false);songs=xx_data_get_u32(h,16,8,false);instruments=xx_data_get_u32(h,16,12,false);
    if(patterns>4096||songs>256||instruments>256)return true;
    for(uint32_t i=0;i<songs;i++){
        if(!sxlate_row(c,&sxlate_jxs_subsong,p,180,end))return false;p+=180;
        if(!sxlate_table(c,&sxlate_jxs_order,&p,4,4096,end))return false;
    }
    if(!sxlate_table(c,&sxlate_jxs_event,&p,5,(uint64_t)patterns*64,end))return false;
    for(uint32_t i=0;i<patterns;i++){
        uint32_t n;
        if(!sxlate_u32(c,p,&n,end)||!sxlate_row(c,&sxlate_jxs_pattern_name_size,p,4,end))return false;p+=4;
        if(n>4096)return true;
        if(n&&!sxlate_row(c,&sxlate_jxs_pattern_name,p,n,end))return false;p+=n;
    }
    for(uint32_t i=0;i<instruments;i++){
        uint32_t pointer,n;
        if(!sxlate_u32(c,p+512,&pointer,end)||!sxlate_u32(c,p+516,&n,end)||!sxlate_row(c,&sxlate_jxs_instrument,p,92,end))return false;p+=92;
        if(!sxlate_table(c,&sxlate_jxs_effect,&p,40,4,end)||!sxlate_row(c,&sxlate_jxs_sample_info,p,268,end))return false;p+=268;
        if(!sxlate_table(c,&sxlate_jxs_wave,&p,512,16,end))return false;
        if(pointer){if(!sxlate_span(c,p,n,end))return false;p+=n;}
    }
    return sxlate_table(c,&sxlate_jxs_arpeggio,&p,16,16,end);
}
bool sx_rhino_jaytraxsyntrax_jxs_build(sx_context*c)
{
    return sxlate_jxs(c);
}
