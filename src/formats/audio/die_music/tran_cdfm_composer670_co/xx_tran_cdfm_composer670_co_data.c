/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Tran Cdfm Composer670 Co data structures, moved out of the musiclate schema family. */
#include "../../../xx_format_schema_musiclate.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxlate_c670_sample_fields[]={
 SX_FIELD("unknown_address_placeholder","uint32",0,4,SX_NONE),
 SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("loop_begin","uint32",8,4,SX_NONE),
 SX_FIELD("loop_end","uint32",12,4,SX_NONE),
};
const sx_layout sxlate_c670_sample={0x60930024U,"c670_sample",sxlate_c670_sample_fields,SX_COUNT(sxlate_c670_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_fm_instrument_fields[]={
 SX_FIELD("feedback_connection","uint8",0,1,SX_NONE),
 SX_FIELD("modulator_characteristics","uint8",1,1,SX_NONE),
 SX_FIELD("modulator_level","uint8",2,1,SX_NONE),
 SX_FIELD("modulator_attack_decay","uint8",3,1,SX_NONE),
 SX_FIELD("modulator_sustain_release","uint8",4,1,SX_NONE),
 SX_FIELD("modulator_waveform","uint8",5,1,SX_NONE),
 SX_FIELD("carrier_characteristics","uint8",6,1,SX_NONE),
 SX_FIELD("carrier_level","uint8",7,1,SX_NONE),
 SX_FIELD("carrier_attack_decay","uint8",8,1,SX_NONE),
 SX_FIELD("carrier_sustain_release","uint8",9,1,SX_NONE),
 SX_FIELD("carrier_waveform","uint8",10,1,SX_NONE),
};
const sx_layout sxlate_c670_fm_instrument={0x60930025U,"c670_fm_instrument",sxlate_c670_fm_instrument_fields,SX_COUNT(sxlate_c670_fm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_orders_fields[]={
 SX_FIELD("pattern_index","uint8",0,0,SX_NONE),
};
const sx_layout sxlate_c670_orders={0x60930026U,"c670_orders",sxlate_c670_orders_fields,SX_COUNT(sxlate_c670_orders_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_note_fields[]={
 SX_FIELD("channel","uint8",0,1,SX_NONE),
 SX_FIELD("note_and_instrument_high","uint8",1,1,SX_NONE),
 SX_FIELD("instrument_low_and_volume","uint8",2,1,SX_NONE),
};
const sx_layout sxlate_c670_note={0x60930028U,"c670_note",sxlate_c670_note_fields,SX_COUNT(sxlate_c670_note_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_volume_fields[]={
 SX_FIELD("command_channel","uint8",0,1,SX_NONE),
 SX_FIELD("volume","uint8",1,1,SX_NONE),
};
const sx_layout sxlate_c670_volume={0x60930029U,"c670_volume",sxlate_c670_volume_fields,SX_COUNT(sxlate_c670_volume_fields),SX_LE};
static bool sxlate_c670(sx_context*c)
{
    uint64_t end=(uint64_t)c->size,p=10;uint8_t h[10];uint32_t offsets[256];
    if(!sxlate_read(c,0,h,10,end)||!h[0]||h[0]>15||!sxlate_row(c,&sxlate_c670_header,0,10,end))return false;
    uint32_t sample_offset=xx_data_get_u32(h,10,6,false);unsigned orders=h[1],patterns=h[2],samples=h[3],fm=h[4];
    if(sample_offset>end||!sxlate_plane(c,&sxlate_c670_orders,&p,orders,end))return false;
    for(unsigned i=0;i<patterns;i++)if(!sxlate_u32(c,p+i*4,&offsets[i],end))return false;
    if(!sxlate_table(c,&sxlate_c670_pattern_offset,&p,4,patterns,end)||!sxlate_table(c,&sxlate_c670_sample,&p,16,samples,end)||!sxlate_table(c,&sxlate_c670_fm_instrument,&p,11,fm,end))return false;
    uint64_t base=p;
    if(base>sample_offset)return false;
    for(unsigned i=0;i<patterns;i++){
        uint64_t q=base+offsets[i],stop=i+1<patterns?base+offsets[i+1]:sample_offset;
        if(q<base||q>stop||stop>sample_offset)return false;
        while(q<stop&&c->count<30000){uint8_t cmd;const sx_layout*l;uint64_t n;
            if(!sxlate_byte(c,q,&cmd,stop))return false;
            if(cmd<=12){l=&sxlate_c670_note;n=3;}
            else if(cmd>=32&&cmd<=44){l=&sxlate_c670_volume;n=2;}
            else if(cmd>=64&&cmd<96){l=&sxlate_c670_delay;n=2;}
            else if(cmd>=96&&cmd<128){l=&sxlate_c670_end;n=1;}
            else return true;
            if(!sxlate_row(c,l,q,n,stop))return false;q+=n;
            if(cmd>=96&&cmd<128)break;
        }
        if(c->count>=30000)return true;
    }
    return true;
}
bool sx_tran_cdfm_composer670_co_build(sx_context*c)
{
    return sxlate_c670(c);
}
