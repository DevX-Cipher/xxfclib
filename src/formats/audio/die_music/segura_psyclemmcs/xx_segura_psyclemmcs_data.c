/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * J.M.A. Segura/Psycledelics' Psycle Modular Music Creation Studio module (.PSY) data structures, moved out of the musicportable schema family. */
#include "../../../xx_format_schema_musicportable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxportable_psy2_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("title","char[32]",8,32,SX_NONE),
 SX_FIELD("author","char[32]",40,32,SX_NONE),
 SX_FIELD("comment","char[128]",72,128,SX_NONE),
 SX_FIELD("tempo_bpm","int32",200,4,SX_NONE),
 SX_FIELD("samples_per_tick","int32",204,4,SX_NONE),
 SX_FIELD("octave","uint8",208,1,SX_NONE),
 SX_FIELD("bus_machine","uint8[64]",209,64,SX_NONE),
 SX_FIELD("play_order","uint8[128]",273,128,SX_NONE),
 SX_FIELD("sequence_length","int32",401,4,SX_COUNT_PROP),
 SX_FIELD("track_count","int32",405,4,SX_COUNT_PROP),
 SX_FIELD("pattern_count","int32",409,4,SX_COUNT_PROP),
};
const sx_layout sxportable_psy2_header={0x60910025U,"psy2_header",sxportable_psy2_header_fields,SX_COUNT(sxportable_psy2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy2_pattern_header_fields[]={
 SX_FIELD("line_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("name","char[32]",4,32,SX_NONE),
};
const sx_layout sxportable_psy2_pattern_header={0x60910026U,"psy2_pattern_header",sxportable_psy2_pattern_header_fields,SX_COUNT(sxportable_psy2_pattern_header_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("file_version","int32",8,4,SX_NONE),
 SX_FIELD("header_data_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("chunk_count","uint32",16,4,SX_COUNT_PROP),
};
const sx_layout sxportable_psy3_header={0x60910028U,"psy3_header",sxportable_psy3_header_fields,SX_COUNT(sxportable_psy3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_title_fields[]={
 SX_FIELD("title","char",0,0,SX_NONE),
};
const sx_layout sxportable_psy3_title={0x6091002aU,"psy3_title",sxportable_psy3_title_fields,SX_COUNT(sxportable_psy3_title_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_author_fields[]={
 SX_FIELD("author","char",0,0,SX_NONE),
};
const sx_layout sxportable_psy3_author={0x6091002bU,"psy3_author",sxportable_psy3_author_fields,SX_COUNT(sxportable_psy3_author_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_comment_fields[]={
 SX_FIELD("comment","char",0,0,SX_NONE),
};
const sx_layout sxportable_psy3_comment={0x6091002cU,"psy3_comment",sxportable_psy3_comment_fields,SX_COUNT(sxportable_psy3_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_sequence_name_fields[]={
 SX_FIELD("sequence_name","char",0,0,SX_NONE),
};
const sx_layout sxportable_psy3_sequence_name={0x6091002dU,"psy3_sequence_name",sxportable_psy3_sequence_name_fields,SX_COUNT(sxportable_psy3_sequence_name_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_pattern_name_fields[]={
 SX_FIELD("pattern_name","char",0,0,SX_NONE),
};
const sx_layout sxportable_psy3_pattern_name={0x6091002eU,"psy3_pattern_name",sxportable_psy3_pattern_name_fields,SX_COUNT(sxportable_psy3_pattern_name_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_track_state_fields[]={
 SX_FIELD("muted","uint8",0,1,SX_NONE),
 SX_FIELD("armed","uint8",1,1,SX_NONE),
};
const sx_layout sxportable_psy3_track_state={0x60910030U,"psy3_track_state",sxportable_psy3_track_state_fields,SX_COUNT(sxportable_psy3_track_state_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_sequence_fields[]={
 SX_FIELD("index","int32",0,4,SX_NONE),
 SX_FIELD("play_length","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxportable_psy3_sequence={0x60910031U,"psy3_sequence",sxportable_psy3_sequence_fields,SX_COUNT(sxportable_psy3_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_pattern_index_fields[]={
 SX_FIELD("pattern_index","uint32",0,4,SX_NONE),
};
const sx_layout sxportable_psy3_pattern_index={0x60910032U,"psy3_pattern_index",sxportable_psy3_pattern_index_fields,SX_COUNT(sxportable_psy3_pattern_index_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_psy3_pattern_fields[]={
 SX_FIELD("index","int32",0,4,SX_NONE),
 SX_FIELD("line_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("track_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxportable_psy3_pattern={0x60910033U,"psy3_pattern",sxportable_psy3_pattern_fields,SX_COUNT(sxportable_psy3_pattern_fields),SX_LE};
static bool sxportable_psy2(sx_context*c)
{
    uint64_t end=(uint64_t)c->size,p=413;uint32_t tracks,patterns;
    if(!sxportable_row(c,&sxportable_psy2_header,0,413,end)||
       !sx_u32(c,405,false,&tracks)||!sx_u32(c,409,false,&patterns))return false;
    if(tracks>32||patterns>256)return true;
    for(uint32_t i=0;i<patterns;i++){
        uint32_t rows;
        if(!sxportable_row(c,&sxportable_psy2_pattern_header,p,36,end)||!sx_u32(c,(int64_t)p,false,&rows))return false;
        p+=36;
        /* PSY2 stores all 32 channel slots in each row, including inactive slots. */
        if(rows>INT32_MAX)return false;
        uint64_t cells=(uint64_t)rows*32,shown=cells>32768?32768:cells;
        if(!sxportable_span(c,p,cells*5,end)||!sx_table(c,&sxportable_psy2_event,(int64_t)p,5,shown))return false;
        p+=cells*5;
    }
    return true;
}
static bool sxportable_psy3(sx_context*c)
{
    uint8_t h[20];uint64_t end=(uint64_t)c->size;
    if(!sxportable_read(c,0,h,20,end)||!sxportable_row(c,&sxportable_psy3_header,0,20,end))return false;
    uint32_t header=xx_data_get_u32(h,20,12,false),chunks=xx_data_get_u32(h,20,16,false);
    if(header<4||!sxportable_span(c,16,header,end))return false;
    uint64_t p=16U+(uint64_t)header;
    for(uint32_t i=0;i<chunks&&i<4096&&c->count<30000;i++){
        if(!sxportable_read(c,p,h,12,end)||!sxportable_row(c,&sxportable_psy3_chunk,p,12,end))return false;
        uint32_t v=xx_data_get_u32(h,12,4,false),size=xx_data_get_u32(h,12,8,false);
        uint64_t q=p+12,limit=q+(uint64_t)size;
        if(v==0&&!xx_rt_memcmp(h,"INFO",4)){
            /* Original v0 writers sometimes included twelve extra bytes in size. */
            if(!sxportable_string(c,&sxportable_psy3_title,&q,end)||
               !sxportable_string(c,&sxportable_psy3_author,&q,end)||
               !sxportable_string(c,&sxportable_psy3_comment,&q,end))return false;
            limit=q;
        }else if(v==0&&!xx_rt_memcmp(h,"SNGI",4)){
            uint32_t tracks;
            if(!sxportable_row(c,&sxportable_psy3_song_info,q,44,end)||!sx_u32(c,(int64_t)q,false,&tracks))return false;
            if(tracks>4096)return true;
            q+=44;
            if(!sxportable_span(c,q,(uint64_t)tracks*2,end)||!sx_table(c,&sxportable_psy3_track_state,(int64_t)q,2,tracks))return false;
            limit=q+(uint64_t)tracks*2;
        }else if(v==0&&!xx_rt_memcmp(h,"SEQD",4)){
            uint32_t count;
            if(!sxportable_row(c,&sxportable_psy3_sequence,q,8,limit)||!sx_u32(c,(int64_t)q+4,false,&count))return false;
            q+=8;
            if(!sxportable_string(c,&sxportable_psy3_sequence_name,&q,limit)||!sxportable_span(c,q,(uint64_t)count*4,limit))return false;
            uint64_t shown=count>32768?32768:count;
            if(!sx_table(c,&sxportable_psy3_pattern_index,(int64_t)q,4,shown))return false;
        }else if(v==0&&!xx_rt_memcmp(h,"PATD",4)){
            uint32_t packed;
            /* Original v0 writers sometimes omitted four bytes from the size. */
            uint64_t available=limit<=end&&end-limit>=4?limit+4:end;
            if(!sxportable_row(c,&sxportable_psy3_pattern,q,12,available))return false;q+=12;
            if(!sxportable_string(c,&sxportable_psy3_pattern_name,&q,available)||
               !sxportable_row(c,&sxportable_psy3_compressed_bytes,q,4,available)||!sx_u32(c,(int64_t)q,false,&packed))return false;
            q+=4;
            if(!sxportable_span(c,q,packed,available))return false;q+=packed;
            if(q==limit+4)limit=q;
            else if(q>limit)return false;
        }
        if(limit>end)return false;
        p=limit;
    }
    return true;
}
static bool sxportable_psycle(sx_context*c)
{
    uint8_t h[8];if(!sxportable_read(c,0,h,8,(uint64_t)c->size))return false;
    if(!xx_rt_memcmp(h,"PSY2SONG",8))return sxportable_psy2(c);
    if(!xx_rt_memcmp(h,"PSY3SONG",8))return sxportable_psy3(c);
    return false;
}
bool sx_segura_psyclemmcs_build(sx_context*c)
{
    return sxportable_psycle(c);
}
