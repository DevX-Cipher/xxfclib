/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RAD_BINK data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_bink_header_fields[] = {
    SX_FIELD("signature", "byte[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("file_size_minus_eight", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("frame_count", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("largest_frame_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("duplicate_frame_count", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("width", "uint32", 20, 4, SX_NONE),
    SX_FIELD("height", "uint32", 24, 4, SX_NONE),
    SX_FIELD("frame_rate_numerator", "uint32", 28, 4, SX_NONE),
    SX_FIELD("frame_rate_denominator", "uint32", 32, 4, SX_NONE),
    SX_FIELD("flags", "uint32", 36, 4, SX_FLAGS),
    SX_FIELD("audio_track_count", "uint32", 40, 4, SX_COUNT_PROP),
};
const sx_layout sx_st_bink_header = {0x60080037U, "bink_header", sx_st_bink_header_fields, SX_COUNT(sx_st_bink_header_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_bink_audio_maximum_fields[] = {
    SX_FIELD("maximum_decoded_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_st_bink_audio_maximum = {0x60080038U, "bink_audio_maximum", sx_st_bink_audio_maximum_fields, SX_COUNT(sx_st_bink_audio_maximum_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_bink_audio_format_fields[] = {
    SX_FIELD("sample_rate", "uint16", 0, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 2, 2, SX_FLAGS),
};
const sx_layout sx_st_bink_audio_format = {0x60080039U, "bink_audio_format", sx_st_bink_audio_format_fields, SX_COUNT(sx_st_bink_audio_format_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_bink_audio_id_fields[] = {
    SX_FIELD("track_id", "uint32", 0, 4, SX_ID),
};
const sx_layout sx_st_bink_audio_id = {0x6008003AU, "bink_audio_id", sx_st_bink_audio_id_fields, SX_COUNT(sx_st_bink_audio_id_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_bink_frame_index_fields[] = {
    SX_FIELD("offset_and_keyframe_flag", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sx_st_bink_frame_index = {0x6008003BU, "bink_frame_index", sx_st_bink_frame_index_fields, SX_COUNT(sx_st_bink_frame_index_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_bink_end_offset_fields[] = {
    SX_FIELD("end_offset", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sx_st_bink_end_offset = {0x6008003CU, "bink_end_offset", sx_st_bink_end_offset_fields, SX_COUNT(sx_st_bink_end_offset_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_bink_audio_packet_fields[] = {
    SX_FIELD("packet_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_st_bink_audio_packet = {0x6008003DU, "bink_audio_packet", sx_st_bink_audio_packet_fields, SX_COUNT(sx_st_bink_audio_packet_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_bink_audio_decoded_fields[] = {
    SX_FIELD("decoded_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_st_bink_audio_decoded = {0x6008003EU, "bink_audio_decoded", sx_st_bink_audio_decoded_fields, SX_COUNT(sx_st_bink_audio_decoded_fields), SX_LE};
static bool sx_st_bink(sx_context *c)
{
    uint32_t frames,tracks,first;uint64_t table;
    if(!sx_add(c,&sx_st_bink_header,0,44)||!sx_u32(c,8,false,&frames)||!sx_u32(c,40,false,&tracks)||!frames||frames>4094||tracks>16)return false;
    table=44+(uint64_t)tracks*12;
    if(!sx_table(c,&sx_st_bink_audio_maximum,44,4,tracks)||!sx_table(c,&sx_st_bink_audio_format,44+tracks*4,4,tracks)||!sx_table(c,&sx_st_bink_audio_id,44+tracks*8,4,tracks)||!sx_table(c,&sx_st_bink_frame_index,(int64_t)table,4,frames)||!sx_u32(c,(int64_t)table,false,&first))return false;
    if((first&~1U)==table+(uint64_t)frames*4+4&&!sx_add(c,&sx_st_bink_end_offset,(int64_t)(table+(uint64_t)frames*4),4))return false;
    for(uint32_t i=0;i<frames;i++) {
        uint32_t begin,next;uint64_t at,end=(uint64_t)c->size;
        if(!sx_u32(c,(int64_t)(table+(uint64_t)i*4),false,&begin))return false;at=begin&~1U;
        if(i+1<frames){if(!sx_u32(c,(int64_t)(table+(uint64_t)(i+1)*4),false,&next))return false;end=next&~1U;}
        if(at>end||!sx_st_fits(c,at,end-at))return false;
        for(uint32_t j=0;j<tracks;j++) {
            uint32_t n;if(end-at<4||!sx_u32(c,(int64_t)at,false,&n)||!sx_add(c,&sx_st_bink_audio_packet,(int64_t)at,4))return false;at+=4;
            if(n>end-at)return false;if(n&&(n<4||!sx_add(c,&sx_st_bink_audio_decoded,(int64_t)at,4)))return false;at+=n;
        }
        if(c->count>=20000)break;
    }
    return true;
}
bool sx_rad_bink_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_bink(c);
    return ok&&sx_st_finish(c);
}
