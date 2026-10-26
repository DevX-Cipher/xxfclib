/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AdLib D00 data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_d00_header_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("type","uint8_t",6,1,SX_NONE),
    SX_FIELD("version","uint8_t",7,1,SX_NONE),
    SX_FIELD("speed_hz","uint8_t",8,1,SX_NONE),
    SX_FIELD("subsong_count","uint8_t",9,1,SX_COUNT_PROP),
    SX_FIELD("sound_card","uint8_t",10,1,SX_NONE),
    SX_FIELD("song_name","char[32]",11,32,SX_STRING),
    SX_FIELD("author","char[32]",43,32,SX_STRING),
    SX_FIELD("reserved","uint8_t[32]",75,32,SX_RESERVED),
    SX_FIELD("subsong_table_offset","uint16_t",107,2,SX_OFFSET),
    SX_FIELD("sequence_index_offset","uint16_t",109,2,SX_OFFSET),
    SX_FIELD("instrument_table_offset","uint16_t",111,2,SX_OFFSET),
    SX_FIELD("data_info_offset","uint16_t",113,2,SX_OFFSET),
    SX_FIELD("special_effects_offset","uint16_t",115,2,SX_OFFSET),
    SX_FIELD("end_marker","uint16_t",117,2,SX_SIGNATURE),
};
const sx_layout sxad_adlib_d00_header = {UINT32_C(0x600f000e),"adlib_d00_header",sxad_adlib_d00_header_fields,SX_COUNT(sxad_adlib_d00_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_subsong_fields[] = {
    SX_FIELD("channel0_order_offset","uint16_t",0,2,SX_OFFSET),
    SX_FIELD("channel1_order_offset","uint16_t",2,2,SX_OFFSET),
    SX_FIELD("channel2_order_offset","uint16_t",4,2,SX_OFFSET),
    SX_FIELD("channel3_order_offset","uint16_t",6,2,SX_OFFSET),
    SX_FIELD("channel4_order_offset","uint16_t",8,2,SX_OFFSET),
    SX_FIELD("channel5_order_offset","uint16_t",10,2,SX_OFFSET),
    SX_FIELD("channel6_order_offset","uint16_t",12,2,SX_OFFSET),
    SX_FIELD("channel7_order_offset","uint16_t",14,2,SX_OFFSET),
    SX_FIELD("channel8_order_offset","uint16_t",16,2,SX_OFFSET),
    SX_FIELD("channel0_volume_flags","uint8_t",18,1,SX_FLAGS),
    SX_FIELD("channel1_volume_flags","uint8_t",19,1,SX_FLAGS),
    SX_FIELD("channel2_volume_flags","uint8_t",20,1,SX_FLAGS),
    SX_FIELD("channel3_volume_flags","uint8_t",21,1,SX_FLAGS),
    SX_FIELD("channel4_volume_flags","uint8_t",22,1,SX_FLAGS),
    SX_FIELD("channel5_volume_flags","uint8_t",23,1,SX_FLAGS),
    SX_FIELD("channel6_volume_flags","uint8_t",24,1,SX_FLAGS),
    SX_FIELD("channel7_volume_flags","uint8_t",25,1,SX_FLAGS),
    SX_FIELD("channel8_volume_flags","uint8_t",26,1,SX_FLAGS),
    SX_FIELD("reserved","uint8_t[5]",27,5,SX_RESERVED),
};
const sx_layout sxad_adlib_d00_subsong = {UINT32_C(0x600f000f),"adlib_d00_subsong",sxad_adlib_d00_subsong_fields,SX_COUNT(sxad_adlib_d00_subsong_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_order_header_fields[] = {
    SX_FIELD("channel_speed","uint16_t",0,2,SX_NONE),
};
const sx_layout sxad_adlib_d00_order_header = {UINT32_C(0x600f0010),"adlib_d00_order_header",sxad_adlib_d00_order_header_fields,SX_COUNT(sxad_adlib_d00_order_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_order_word_fields[] = {
    SX_FIELD("order_word","uint16_t",0,2,SX_FLAGS),
};
const sx_layout sxad_adlib_d00_order_word = {UINT32_C(0x600f0011),"adlib_d00_order_word",sxad_adlib_d00_order_word_fields,SX_COUNT(sxad_adlib_d00_order_word_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_sequence_offset_fields[] = {
    SX_FIELD("sequence_offset","uint16_t",0,2,SX_OFFSET),
};
const sx_layout sxad_adlib_d00_sequence_offset = {UINT32_C(0x600f0012),"adlib_d00_sequence_offset",sxad_adlib_d00_sequence_offset_fields,SX_COUNT(sxad_adlib_d00_sequence_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_sequence_word_fields[] = {
    SX_FIELD("event_word","uint16_t",0,2,SX_FLAGS),
};
const sx_layout sxad_adlib_d00_sequence_word = {UINT32_C(0x600f0013),"adlib_d00_sequence_word",sxad_adlib_d00_sequence_word_fields,SX_COUNT(sxad_adlib_d00_sequence_word_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_instrument_fields[] = {
    SX_FIELD("carrier_attack_decay","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("modulator_characteristics","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("tune_level","uint8_t",11,1,SX_FLAGS),
    SX_FIELD("timer","uint8_t",12,1,SX_NONE),
    SX_FIELD("sustain_release","uint8_t",13,1,SX_FLAGS),
    SX_FIELD("reserved","uint8_t[2]",14,2,SX_RESERVED),
};
const sx_layout sxad_adlib_d00_instrument = {UINT32_C(0x600f0014),"adlib_d00_instrument",sxad_adlib_d00_instrument_fields,SX_COUNT(sxad_adlib_d00_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_data_info_end_fields[] = {
    SX_FIELD("terminator","uint16_t",0,2,SX_SIGNATURE),
};
const sx_layout sxad_adlib_d00_data_info_end = {UINT32_C(0x600f0015),"adlib_d00_data_info_end",sxad_adlib_d00_data_info_end_fields,SX_COUNT(sxad_adlib_d00_data_info_end_fields),SX_LE};
/* Pointer-bearing streams can alias a complete previously emitted span, but
 * must not overlap unrelated physical fields. Sequential walkers need no scan. */
static int sxad_overlap(sx_context *c,int64_t off,int64_t size)
{
    if(off<0||size<=0||off>c->size||size>c->size-off)return -1;
    for(size_t i=0;i<c->count;i++){
        const xx_data_struct *d=&c->items[i];int64_t at=d->offset-c->f->base_address;
        if(at==off&&d->total_size==size)return 1;
        if(off<at+d->total_size&&at<off+size)return -1;
    }return 0;
}
static bool sxad_d00(sx_context *c)
{
    uint8_t h[119];uint16_t table,seq,inst,info;uint16_t order_starts[1024];unsigned order_count=0,max_index=0;
    if(!sx_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"JCH\x26\x02\x66",6)||h[6]||h[7]!=4||!h[8]||!h[9]||h[10]||xx_data_get_u16(h+117,2,0,false)!=65535)return false;
    table=xx_data_get_u16(h+107,2,0,false);seq=xx_data_get_u16(h+109,2,0,false);inst=xx_data_get_u16(h+111,2,0,false);info=xx_data_get_u16(h+113,2,0,false);
    if(table<119||seq<table+(uint32_t)h[9]*32||inst<=seq||info<inst||info>=c->size||xx_data_get_u16(h+115,2,0,false)!=seq||(info-inst)%16||c->size-info!=2)return false;
    unsigned patches=(info-inst)/16;if(!patches||patches>256)return false;
    if(!sx_add(c,&sxad_adlib_d00_header,0,119)||!sx_table(c,&sxad_adlib_d00_subsong,table,32,h[9])||!sx_table(c,&sxad_adlib_d00_instrument,inst,16,patches)||!sx_add(c,&sxad_adlib_d00_data_info_end,info,2))return false;
    uint16_t marker;if(!sx_u16(c,info,false,&marker)||marker!=65535)return false;
    for(unsigned i=0;i<h[9];i++)for(unsigned j=0;j<9;j++){
        uint16_t start;if(!sx_u16(c,table+32U*i+2U*j,false,&start))return false;if(!start)continue;
        bool seen=false;for(unsigned k=0;k<order_count;k++)if(order_starts[k]==start)seen=true;if(seen)continue;
        if(order_count>=SX_COUNT(order_starts)||start<119||(uint32_t)start+4>table)return false;order_starts[order_count++]=start;
        int64_t pos=start+2;unsigned words=0;bool ended=false;
        while(pos+2<=table){uint16_t v;if(!sx_u16(c,pos,false,&v))return false;pos+=2;words++;
            if(v==65534){ended=true;break;}
            if(v==65535){uint16_t target;if(pos+2>table||!sx_u16(c,pos,false,&target)||target>=words-1)return false;pos+=2;ended=true;break;}
            if(v<0x8000){if(v>=512)return false;if(v>max_index)max_index=v;}else if(v>=0xa000)return false;
        }
        if(!ended||sxad_overlap(c,start,pos-start)!=0||!sx_add(c,&sxad_adlib_d00_order_header,start,2)||!sx_table(c,&sxad_adlib_d00_order_word,start+2,2,(uint64_t)(pos-start-2)/2))return false;
    }
    unsigned n=max_index+1;uint16_t refs[512];uint16_t first=inst;
    if((uint32_t)seq+2U*n>inst||!sx_table(c,&sxad_adlib_d00_sequence_offset,seq,2,n))return false;
    for(unsigned i=0;i<n;i++){if(!sx_u16(c,seq+2U*i,false,&refs[i])||refs[i]<seq+2U*n||refs[i]>=inst)return false;if(refs[i]<first)first=refs[i];}
    if(first!=seq+2U*n)return false;
    for(unsigned i=0;i<n;i++){
        bool seen=false;for(unsigned j=0;j<i;j++)if(refs[j]==refs[i])seen=true;if(seen)continue;
        int64_t end=inst;for(unsigned j=0;j<n;j++)if(refs[j]>refs[i]&&refs[j]<end)end=refs[j];if((end-refs[i])&1)return false;
        uint16_t word=0;for(int64_t pos=refs[i];pos<end;pos+=2){if(!sx_u16(c,pos,false,&word))return false;if(word==65535){if(pos+2!=end)return false;}else if((word>>12)==11||((word>>12)==12&&(word&4095)>=patches))return false;}
        if(word!=65535||sxad_overlap(c,refs[i],end-refs[i])!=0||!sx_table(c,&sxad_adlib_d00_sequence_word,refs[i],2,(uint64_t)(end-refs[i])/2))return false;
    }return true;
}
bool sx_adlib_d00_build(sx_context*c)
{
    return sxad_d00(c);
}
