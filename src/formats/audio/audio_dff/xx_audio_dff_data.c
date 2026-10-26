/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUDIO_DFF data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_dff_form_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("form_type", "char[4]", 12, 4, SX_STRING),
};
const sx_layout sx_st_dff_form = {0x60080016U, "dff_form", sx_st_dff_form_fields, SX_COUNT(sx_st_dff_form_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_dff_chunk_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
};
const sx_layout sx_st_dff_chunk = {0x60080017U, "dff_chunk", sx_st_dff_chunk_fields, SX_COUNT(sx_st_dff_chunk_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_dff_version_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_NONE),
};
const sx_layout sx_st_dff_version = {0x60080018U, "dff_version", sx_st_dff_version_fields, SX_COUNT(sx_st_dff_version_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_dff_property_fields[] = {
    SX_FIELD("property_type", "char[4]", 0, 4, SX_STRING),
};
const sx_layout sx_st_dff_property = {0x60080019U, "dff_property", sx_st_dff_property_fields, SX_COUNT(sx_st_dff_property_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_dff_frequency_fields[] = {
    SX_FIELD("sample_rate", "uint32", 0, 4, SX_NONE),
};
const sx_layout sx_st_dff_frequency = {0x6008001AU, "dff_frequency", sx_st_dff_frequency_fields, SX_COUNT(sx_st_dff_frequency_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_dff_channels_fields[] = {
    SX_FIELD("channel_count", "uint16", 0, 2, SX_COUNT_PROP),
};
const sx_layout sx_st_dff_channels = {0x6008001BU, "dff_channels", sx_st_dff_channels_fields, SX_COUNT(sx_st_dff_channels_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_dff_channel_fields[] = {
    SX_FIELD("channel_id", "char[4]", 0, 4, SX_STRING),
};
const sx_layout sx_st_dff_channel = {0x6008001CU, "dff_channel", sx_st_dff_channel_fields, SX_COUNT(sx_st_dff_channel_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_dff_compression_fields[] = {
    SX_FIELD("compression_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("name_length", "uint8", 4, 1, SX_SIZE),
};
const sx_layout sx_st_dff_compression = {0x6008001DU, "dff_compression", sx_st_dff_compression_fields, SX_COUNT(sx_st_dff_compression_fields), SX_BE};
static bool sx_st_dff_chunks(sx_context *c,uint64_t at,uint64_t end,bool properties)
{
    while(at<end) {
        uint8_t h[12];uint64_t n;
        if(end-at<12||!sx_read(c,(int64_t)at,h,12)||!sx_add(c,&sx_st_dff_chunk,(int64_t)at,12))return false;
        n=xx_data_get_u64(h,12,4,true);at+=12;if(n>end-at)return false;
        if(!properties&&!xx_rt_memcmp(h,"PROP",4)) {
            if(n<4||!sx_add(c,&sx_st_dff_property,(int64_t)at,4)||!sx_st_dff_chunks(c,at+4,at+n,true))return false;
        } else if(!properties&&!xx_rt_memcmp(h,"FVER",4)) {
            if(n!=4||!sx_add(c,&sx_st_dff_version,(int64_t)at,4))return false;
        } else if(properties&&!xx_rt_memcmp(h,"FS  ",4)) {
            if(n!=4||!sx_add(c,&sx_st_dff_frequency,(int64_t)at,4))return false;
        } else if(properties&&!xx_rt_memcmp(h,"CHNL",4)) {
            uint16_t count;if(n<2||!sx_u16(c,(int64_t)at,true,&count)||n!=2+(uint64_t)count*4||!sx_add(c,&sx_st_dff_channels,(int64_t)at,2)||!sx_table(c,&sx_st_dff_channel,(int64_t)at+2,4,count))return false;
        } else if(properties&&!xx_rt_memcmp(h,"CMPR",4)) {
            if(n<5||!sx_add(c,&sx_st_dff_compression,(int64_t)at,5))return false;
        }
        at+=n;if(n&1){if(at>=end)return false;at++;}
    }
    return at==end;
}
bool sx_audio_dff_build(sx_context*c)
{
    bool ok=false;
    ok=sx_add(c,&sx_st_dff_form,0,16)&&sx_st_dff_chunks(c,16,(uint64_t)c->size,false);
    return ok&&sx_st_finish(c);
}
