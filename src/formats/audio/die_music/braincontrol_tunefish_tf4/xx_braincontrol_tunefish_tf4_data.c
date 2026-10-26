/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Brain Control's TuneFish module (.TF4) data structures, moved out of the musicportable schema family. */
#include "../../../xx_format_schema_musicportable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxportable_tf4_song_header_fields[]={
 SX_FIELD("instrument_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("tempo_bpm","uint16",2,2,SX_NONE),
};
const sx_layout sxportable_tf4_song_header={0x60910010U,"tf4_song_header",sxportable_tf4_song_header_fields,SX_COUNT(sxportable_tf4_song_header_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_tf4_event_count_fields[]={
 SX_FIELD("event_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxportable_tf4_event_count={0x60910011U,"tf4_event_count",sxportable_tf4_event_count_fields,SX_COUNT(sxportable_tf4_event_count_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_tf4_tag_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxportable_tf4_tag={0x60910012U,"tf4_tag",sxportable_tf4_tag_fields,SX_COUNT(sxportable_tf4_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_tf4_note_plane_fields[]={
 SX_FIELD("note","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_tf4_note_plane={0x60910015U,"tf4_note_plane",sxportable_tf4_note_plane_fields,SX_COUNT(sxportable_tf4_note_plane_fields),SX_LE};
static const xx_data_struct_field_desc sxportable_tf4_velocity_plane_fields[]={
 SX_FIELD("velocity","uint8",0,0,SX_NONE),
};
const sx_layout sxportable_tf4_velocity_plane={0x60910016U,"tf4_velocity_plane",sxportable_tf4_velocity_plane_fields,SX_COUNT(sxportable_tf4_velocity_plane_fields),SX_LE};
static bool sxportable_tf4(sx_context*c)
{
    uint16_t count,events[32];uint64_t end=(uint64_t)c->size,p=4;uint8_t tag[4];
    if(!sx_u16(c,0,false,&count)||count>32||!sxportable_row(c,&sxportable_tf4_song_header,0,4,end))return false;
    for(unsigned i=0;i<count;i++){
        if(!sx_u16(c,(int64_t)p,false,&events[i])||!sxportable_row(c,&sxportable_tf4_event_count,p,2,end))return false;p+=2;
    }
    if(!sxportable_read(c,p,tag,4,end)||xx_rt_memcmp(tag,"INST",4)||!sxportable_row(c,&sxportable_tf4_tag,p,4,end))return false;p+=4;
    if(!sxportable_span(c,p,(uint64_t)count*112,end)||!sx_table(c,&sxportable_tf4_instrument,(int64_t)p,112,count))return false;p+=(uint64_t)count*112;
    if(!sxportable_read(c,p,tag,4,end)||xx_rt_memcmp(tag,"SONG",4)||!sxportable_row(c,&sxportable_tf4_tag,p,4,end))return false;p+=4;
    for(unsigned i=0;i<count;i++){
        uint64_t n=events[i],shown=n>16384?16384:n;
        if(!sxportable_span(c,p,n*2,end)||!sx_table(c,&sxportable_tf4_row_delta,(int64_t)p,2,shown))return false;p+=n*2;
        if(!sxportable_plane(c,&sxportable_tf4_note_plane,&p,n,end)||!sxportable_plane(c,&sxportable_tf4_velocity_plane,&p,n,end))return false;
    }
    return sxportable_read(c,p,tag,4,end)&&!xx_rt_memcmp(tag,"ENDS",4)&&sxportable_row(c,&sxportable_tf4_tag,p,4,end);
}
bool sx_braincontrol_tunefish_tf4_build(sx_context*c)
{
    return sxportable_tf4(c);
}
