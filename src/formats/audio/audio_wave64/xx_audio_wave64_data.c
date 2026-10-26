/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUDIO_WAVE64 data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_wave64_header_fields[] = {
    SX_FIELD("riff_guid", "byte[16]", 0, 16, SX_ID),
    SX_FIELD("file_size", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("wave_guid", "byte[16]", 24, 16, SX_ID),
};
const sx_layout sx_st_wave64_header = {0x6008001EU, "wave64_header", sx_st_wave64_header_fields, SX_COUNT(sx_st_wave64_header_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_wave64_chunk_fields[] = {
    SX_FIELD("chunk_guid", "byte[16]", 0, 16, SX_ID),
    SX_FIELD("chunk_size", "uint64", 16, 8, SX_SIZE),
};
const sx_layout sx_st_wave64_chunk = {0x6008001FU, "wave64_chunk", sx_st_wave64_chunk_fields, SX_COUNT(sx_st_wave64_chunk_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_wave64_format_fields[] = {
    SX_FIELD("format_tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("channels", "uint16", 2, 2, SX_COUNT_PROP),
    SX_FIELD("sample_rate", "uint32", 4, 4, SX_NONE),
    SX_FIELD("average_bytes_per_second", "uint32", 8, 4, SX_NONE),
    SX_FIELD("block_alignment", "uint16", 12, 2, SX_SIZE),
    SX_FIELD("bits_per_sample", "uint16", 14, 2, SX_NONE),
};
const sx_layout sx_st_wave64_format = {0x60080020U, "wave64_format", sx_st_wave64_format_fields, SX_COUNT(sx_st_wave64_format_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_wave64_format_extra_fields[] = {
    SX_FIELD("extra_size", "uint16", 0, 2, SX_SIZE),
};
const sx_layout sx_st_wave64_format_extra = {0x60080021U, "wave64_format_extra", sx_st_wave64_format_extra_fields, SX_COUNT(sx_st_wave64_format_extra_fields), SX_LE};
static bool sx_st_wave64(sx_context *c)
{
    uint64_t at=40;
    if(!sx_add(c,&sx_st_wave64_header,0,40))return false;
    while(at<(uint64_t)c->size) {
        uint8_t h[24];uint64_t n;
        if(!sx_read(c,(int64_t)at,h,24)||!sx_add(c,&sx_st_wave64_chunk,(int64_t)at,24))return false;
        n=xx_data_get_u64(h,24,16,false);if(n<24||!sx_st_fits(c,at,n))return false;
        if(!xx_rt_memcmp(h,"fmt ",4)) {
            if(n<40||!sx_add(c,&sx_st_wave64_format,(int64_t)at+24,16))return false;
            if(n>=42&&!sx_add(c,&sx_st_wave64_format_extra,(int64_t)at+40,2))return false;
        }
        at+=n;if(at>UINT64_MAX-7)return false;at=(at+7)&~UINT64_C(7);
    }
    return at==(uint64_t)c->size;
}
bool sx_audio_wave64_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_wave64(c);
    return ok&&sx_st_finish(c);
}
