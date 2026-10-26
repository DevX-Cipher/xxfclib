/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Tero 'kometbomb' Lindeman's ProtoTracker module (.SONG) data structures, moved out of the musicportable schema family. */
#include "../../../xx_format_schema_musicportable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxportable_proto_version0_fields[]={
 SX_FIELD("version","uint8",0,1,SX_NONE),
};
const sx_layout sxportable_proto_version0={0x60910002U,"proto_version0",sxportable_proto_version0_fields,SX_COUNT(sxportable_proto_version0_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_version1_fields[]={
 SX_FIELD("version","uint8",0,1,SX_NONE),
 SX_FIELD("track_count","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxportable_proto_version1={0x60910003U,"proto_version1",sxportable_proto_version1_fields,SX_COUNT(sxportable_proto_version1_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_version17_fields[]={
 SX_FIELD("version","uint8",0,1,SX_NONE),
 SX_FIELD("track_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("effect_column_count","uint8",2,1,SX_COUNT_PROP),
};
const sx_layout sxportable_proto_version17={0x60910004U,"proto_version17",sxportable_proto_version17_fields,SX_COUNT(sxportable_proto_version17_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
const sx_layout sxportable_proto_text={0x60910005U,"proto_text",sxportable_proto_text_fields,SX_COUNT(sxportable_proto_text_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_sequence_row_count_fields[]={
 SX_FIELD("sequence_row_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxportable_proto_sequence_row_count={0x60910007U,"proto_sequence_row_count",sxportable_proto_sequence_row_count_fields,SX_COUNT(sxportable_proto_sequence_row_count_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_pattern_count_fields[]={
 SX_FIELD("pattern_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxportable_proto_pattern_count={0x60910008U,"proto_pattern_count",sxportable_proto_pattern_count_fields,SX_COUNT(sxportable_proto_pattern_count_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_macro_count_fields[]={
 SX_FIELD("macro_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxportable_proto_macro_count={0x60910009U,"proto_macro_count",sxportable_proto_macro_count_fields,SX_COUNT(sxportable_proto_macro_count_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_sequence_pattern_index_plane_fields[]={
 SX_FIELD("sequence_pattern_index","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_proto_sequence_pattern_index_plane={0x6091000bU,"proto_sequence_pattern_index_plane",sxportable_proto_sequence_pattern_index_plane_fields,SX_COUNT(sxportable_proto_sequence_pattern_index_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_note_effect_plane_fields[]={
 SX_FIELD("note_effect","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_proto_note_effect_plane={0x6091000cU,"proto_note_effect_plane",sxportable_proto_note_effect_plane_fields,SX_COUNT(sxportable_proto_note_effect_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_note_parameter_plane_fields[]={
 SX_FIELD("note_parameter","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_proto_note_parameter_plane={0x6091000dU,"proto_note_parameter_plane",sxportable_proto_note_parameter_plane_fields,SX_COUNT(sxportable_proto_note_parameter_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_effect_plane_fields[]={
 SX_FIELD("effect","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_proto_effect_plane={0x6091000eU,"proto_effect_plane",sxportable_proto_effect_plane_fields,SX_COUNT(sxportable_proto_effect_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_proto_effect_parameter_plane_fields[]={
 SX_FIELD("effect_parameter","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_proto_effect_parameter_plane={0x6091000fU,"proto_effect_parameter_plane",sxportable_proto_effect_parameter_plane_fields,SX_COUNT(sxportable_proto_effect_parameter_plane_fields),SX_LE};
static bool sxportable_proto_pattern(sx_context*c,uint64_t*p,uint64_t end,uint8_t effects)
{
    uint8_t encoded;
    if(!sxportable_byte(c,*p,&encoded,end)||!sxportable_row(c,&sxportable_proto_pattern_rows,*p,1,end))return false;
    ++*p;uint64_t rows=encoded==255?256:encoded;
    if(!sxportable_plane(c,&sxportable_proto_note_effect_plane,p,rows,end)||!sxportable_plane(c,&sxportable_proto_note_parameter_plane,p,rows,end))return false;
    for(unsigned i=0;i<effects;i++){
        if(!sxportable_plane(c,&sxportable_proto_effect_plane,p,rows,end)||!sxportable_plane(c,&sxportable_proto_effect_parameter_plane,p,rows,end))return false;
    }
    return true;
}
static bool sxportable_proto(sx_context*c)
{
    uint8_t h[12],v,tracks=4,effects=1;uint64_t end=(uint64_t)c->size,p;
    if(!sxportable_read(c,0,h,9,end)||xx_rt_memcmp(h,"SONG",4))return false;
    uint32_t declared=xx_data_get_u32(h,9,4,false);v=h[8];
    if(declared<9||declared>end||!sxportable_row(c,&sxportable_proto_section,0,8,end))return false;
    end=declared;p=9;
    if(v>17)return sxportable_row(c,&sxportable_proto_version0,8,1,end);
    if(v>=1&&!sxportable_byte(c,p++,&tracks,end))return false;
    if(v>=17&&!sxportable_byte(c,p++,&effects,end))return false;
    const sx_layout*l=v>=17?&sxportable_proto_version17:v?&sxportable_proto_version1:&sxportable_proto_version0;
    if(!sxportable_row(c,l,8,p-8,end)||!sxportable_string(c,&sxportable_proto_text,&p,end)||!sxportable_row(c,&sxportable_proto_dimensions,p,2,end))return false;
    p+=2;
    /* Resource caps preserve the valid header and leave the unwalked body raw. */
    if(tracks>32||effects>16)return true;
    for(unsigned chunks=0;p<end&&chunks<4096&&c->count<30000;chunks++){
        if(!sxportable_read(c,p,h,8,end))return false;
        uint32_t size=xx_data_get_u32(h,8,4,false);
        if(size<8||!sxportable_span(c,p,size,end)||!sxportable_row(c,&sxportable_proto_section,p,8,end))return false;
        uint64_t q=p+8,limit=p+size;uint8_t count;
        if(!xx_rt_memcmp(h,"SEQU",4)){
            if(!sxportable_byte(c,q,&count,limit)||!sxportable_row(c,&sxportable_proto_sequence_row_count,q++,1,limit)||!sxportable_plane(c,&sxportable_proto_sequence_pattern_index_plane,&q,(uint64_t)count*tracks,limit))return false;
        }else if(!xx_rt_memcmp(h,"PATT",4)){
            unsigned sets=v>=17?tracks:1;
            for(unsigned track=0;track<sets;track++){
                if(!sxportable_byte(c,q,&count,limit)||!sxportable_row(c,&sxportable_proto_pattern_count,q++,1,limit))return false;
                for(unsigned i=0;i<count;i++){
                    if(c->count>=30000)return true;
                    if(!sxportable_proto_pattern(c,&q,limit,effects))return false;
                }
            }
        }else if(!xx_rt_memcmp(h,"MACR",4)){
            if(!sxportable_byte(c,q,&count,limit)||!sxportable_row(c,&sxportable_proto_macro_count,q++,1,limit))return false;
            for(unsigned i=0;i<count;i++){
                if(c->count>=30000)return true;
                if(!sxportable_string(c,&sxportable_proto_text,&q,limit)||!sxportable_proto_pattern(c,&q,limit,effects))return false;
            }
        }
        p=limit;
    }
    return true;
}
bool sx_kometbomb_prototracker_song_build(sx_context*c)
{
    return sxportable_proto(c);
}
