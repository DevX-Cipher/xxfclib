/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RAD_SMACKER data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_smacker_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("width", "uint32", 4, 4, SX_NONE),
    SX_FIELD("height", "uint32", 8, 4, SX_NONE),
    SX_FIELD("frame_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("frame_duration", "int32", 16, 4, SX_NONE),
    SX_FIELD("flags", "uint32", 20, 4, SX_FLAGS),
    SX_FIELD("audio_buffer_size_0", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_1", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_2", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_3", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_4", "uint32", 40, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_5", "uint32", 44, 4, SX_SIZE),
    SX_FIELD("audio_buffer_size_6", "uint32", 48, 4, SX_SIZE),
    SX_FIELD("trees_size", "uint32", 52, 4, SX_SIZE),
    SX_FIELD("mmap_size", "uint32", 56, 4, SX_SIZE),
    SX_FIELD("mclr_size", "uint32", 60, 4, SX_SIZE),
    SX_FIELD("full_size", "uint32", 64, 4, SX_SIZE),
    SX_FIELD("type_size", "uint32", 68, 4, SX_SIZE),
    SX_FIELD("audio_rate_flags_0", "uint32", 72, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_1", "uint32", 76, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_2", "uint32", 80, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_3", "uint32", 84, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_4", "uint32", 88, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_5", "uint32", 92, 4, SX_FLAGS),
    SX_FIELD("audio_rate_flags_6", "uint32", 96, 4, SX_FLAGS),
    SX_FIELD("dummy", "uint32", 100, 4, SX_RESERVED),
};
const sx_layout sx_st_smacker_header = {0x6008003FU, "smacker_header", sx_st_smacker_header_fields, SX_COUNT(sx_st_smacker_header_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_smacker_frame_size_fields[] = {
    SX_FIELD("size_and_flags", "uint32", 0, 4, SX_FLAGS),
};
const sx_layout sx_st_smacker_frame_size = {0x60080040U, "smacker_frame_size", sx_st_smacker_frame_size_fields, SX_COUNT(sx_st_smacker_frame_size_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_smacker_frame_type_fields[] = {
    SX_FIELD("flags", "uint8", 0, 1, SX_FLAGS),
};
const sx_layout sx_st_smacker_frame_type = {0x60080041U, "smacker_frame_type", sx_st_smacker_frame_type_fields, SX_COUNT(sx_st_smacker_frame_type_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_smacker_audio_packet_fields[] = {
    SX_FIELD("packet_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_st_smacker_audio_packet = {0x60080042U, "smacker_audio_packet", sx_st_smacker_audio_packet_fields, SX_COUNT(sx_st_smacker_audio_packet_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_smacker_audio_decoded_fields[] = {
    SX_FIELD("decoded_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sx_st_smacker_audio_decoded = {0x60080043U, "smacker_audio_decoded", sx_st_smacker_audio_decoded_fields, SX_COUNT(sx_st_smacker_audio_decoded_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_smacker_palette_fields[] = {
    SX_FIELD("four_byte_units", "uint8", 0, 1, SX_COUNT_PROP),
};
const sx_layout sx_st_smacker_palette = {0x60080044U, "smacker_palette", sx_st_smacker_palette_fields, SX_COUNT(sx_st_smacker_palette_fields), SX_LE};
static bool sx_st_smacker(sx_context *c)
{
    uint8_t h[104];uint32_t frames,flags,trees;uint64_t at,types;
    if(!sx_read(c,0,h,104)||!sx_add(c,&sx_st_smacker_header,0,104))return false;
    frames=xx_data_get_u32(h,104,12,false);flags=xx_data_get_u32(h,104,20,false);trees=xx_data_get_u32(h,104,52,false);
    if(frames>4092)return false;frames+=flags&1;types=104+(uint64_t)frames*4;at=types+frames+trees;
    if(!sx_table(c,&sx_st_smacker_frame_size,104,4,frames)||!sx_table(c,&sx_st_smacker_frame_type,(int64_t)types,1,frames)||!sx_st_fits(c,types+frames,trees))return false;
    for(uint32_t i=0;i<frames;i++) {
        uint32_t size;uint8_t type;uint64_t q=at,end;
        if(!sx_u32(c,104+(int64_t)i*4,false,&size)||!sx_read(c,(int64_t)types+i,&type,1))return false;size&=~3U;
        if(!sx_st_fits(c,at,size))return false;end=at+size;
        if(type&1){uint8_t units;if(!sx_read(c,(int64_t)q,&units,1)||!units||(uint64_t)units*4>end-q||!sx_add(c,&sx_st_smacker_palette,(int64_t)q,1))return false;q+=(uint64_t)units*4;}
        for(unsigned j=0;j<7;j++)if(type&(2U<<j)) {
            uint32_t n,af=xx_data_get_u32(h,104,72+j*4,false)>>24;bool prefix=(af&0x8c)||!(af&0x20);
            if(end-q<4||!sx_u32(c,(int64_t)q,false,&n)||n<(prefix?8U:4U)||n>end-q||!sx_add(c,&sx_st_smacker_audio_packet,(int64_t)q,4))return false;
            if(prefix&&!sx_add(c,&sx_st_smacker_audio_decoded,(int64_t)q+4,4))return false;q+=n;
        }
        at=end;if(c->count>=20000)break;
    }
    return true;
}
bool sx_rad_smacker_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_smacker(c);
    return ok&&sx_st_finish(c);
}
