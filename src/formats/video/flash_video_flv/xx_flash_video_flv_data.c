/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FLASH_VIDEO_FLV data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_flv_header_fields[] = {
    SX_FIELD("signature", "byte[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("data_offset", "uint32", 5, 4, SX_OFFSET),
};
const sx_layout sx_st_flv_header = {0x60080030U, "flv_header", sx_st_flv_header_fields, SX_COUNT(sx_st_flv_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_flv_previous_tag_fields[] = {
    SX_FIELD("previous_tag_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_st_flv_previous_tag = {0x60080031U, "flv_previous_tag", sx_st_flv_previous_tag_fields, SX_COUNT(sx_st_flv_previous_tag_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_flv_tag_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("data_size", "uint24", 1, 3, SX_SIZE),
    SX_FIELD("timestamp_low24", "uint24", 4, 3, SX_NONE),
    SX_FIELD("timestamp_high8", "uint8", 7, 1, SX_NONE),
    SX_FIELD("stream_id", "uint24", 8, 3, SX_ID),
};
const sx_layout sx_st_flv_tag = {0x60080032U, "flv_tag", sx_st_flv_tag_fields, SX_COUNT(sx_st_flv_tag_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_flv_audio_fields[] = {
    SX_FIELD("sound_format_rate_size_type", "uint8", 0, 1, SX_FLAGS),
};
const sx_layout sx_st_flv_audio = {0x60080033U, "flv_audio", sx_st_flv_audio_fields, SX_COUNT(sx_st_flv_audio_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_flv_aac_audio_fields[] = {
    SX_FIELD("sound_format_rate_size_type", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("aac_packet_type", "uint8", 1, 1, SX_ID),
};
const sx_layout sx_st_flv_aac_audio = {0x60080034U, "flv_aac_audio", sx_st_flv_aac_audio_fields, SX_COUNT(sx_st_flv_aac_audio_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_flv_video_fields[] = {
    SX_FIELD("frame_type_and_codec_id", "uint8", 0, 1, SX_FLAGS),
};
const sx_layout sx_st_flv_video = {0x60080035U, "flv_video", sx_st_flv_video_fields, SX_COUNT(sx_st_flv_video_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_flv_avc_video_fields[] = {
    SX_FIELD("frame_type_and_codec_id", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("avc_packet_type", "uint8", 1, 1, SX_ID),
    SX_FIELD("composition_time", "int24", 2, 3, SX_NONE),
};
const sx_layout sx_st_flv_avc_video = {0x60080036U, "flv_avc_video", sx_st_flv_avc_video_fields, SX_COUNT(sx_st_flv_avc_video_fields), SX_BE};
static bool sx_st_flv(sx_context *c)
{
    uint32_t start;uint64_t at;
    if(!sx_add(c,&sx_st_flv_header,0,9)||!sx_u32(c,5,true,&start)||!sx_add(c,&sx_st_flv_previous_tag,start,4))return false;at=(uint64_t)start+4;
    while(at<(uint64_t)c->size) {
        uint8_t h[11],first;uint32_t n;
        if(!sx_read(c,(int64_t)at,h,11)||!sx_add(c,&sx_st_flv_tag,(int64_t)at,11))return false;
        n=xx_data_get_u24(h,11,1,true);at+=11;if(!n||!sx_st_fits(c,at,(uint64_t)n+4)||!sx_read(c,(int64_t)at,&first,1))return false;
        if(h[0]==8){bool aac=(first>>4)==10;if(n<(aac?2U:1U)||!sx_add(c,aac?&sx_st_flv_aac_audio:&sx_st_flv_audio,(int64_t)at,aac?2:1))return false;}
        else if(h[0]==9){bool avc=(first&15)==7;if(n<(avc?5U:1U)||!sx_add(c,avc?&sx_st_flv_avc_video:&sx_st_flv_video,(int64_t)at,avc?5:1))return false;}
        at+=n;if(!sx_add(c,&sx_st_flv_previous_tag,(int64_t)at,4))return false;at+=4;
    }
    return true;
}
bool sx_flash_video_flv_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_flv(c);
    return ok&&sx_st_finish(c);
}
