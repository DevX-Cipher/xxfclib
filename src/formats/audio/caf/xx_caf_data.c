/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CAF data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_caf_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 4, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 6, 2, SX_FLAGS),
};
const sx_layout sx_st_caf_header = {0x60080003U, "caf_header", sx_st_caf_header_fields, SX_COUNT(sx_st_caf_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_caf_description_fields[] = {
    SX_FIELD("sample_rate", "float64", 0, 8, SX_NONE),
    SX_FIELD("format_id", "char[4]", 8, 4, SX_STRING),
    SX_FIELD("format_flags", "uint32", 12, 4, SX_FLAGS),
    SX_FIELD("bytes_per_packet", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("frames_per_packet", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("channels_per_frame", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("bits_per_channel", "uint32", 28, 4, SX_COUNT_PROP),
};
const sx_layout sx_st_caf_description = {0x60080005U, "caf_description", sx_st_caf_description_fields, SX_COUNT(sx_st_caf_description_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_caf_data_fields[] = {
    SX_FIELD("edit_count", "uint32", 0, 4, SX_COUNT_PROP),
};
const sx_layout sx_st_caf_data = {0x60080006U, "caf_data", sx_st_caf_data_fields, SX_COUNT(sx_st_caf_data_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_caf_packet_table_fields[] = {
    SX_FIELD("packet_count", "int64", 0, 8, SX_COUNT_PROP),
    SX_FIELD("valid_frame_count", "int64", 8, 8, SX_COUNT_PROP),
    SX_FIELD("priming_frame_count", "int32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("remainder_frame_count", "int32", 20, 4, SX_COUNT_PROP),
};
const sx_layout sx_st_caf_packet_table = {0x60080007U, "caf_packet_table", sx_st_caf_packet_table_fields, SX_COUNT(sx_st_caf_packet_table_fields), SX_BE};
static bool sx_st_caf(sx_context *c)
{
    uint64_t at=8;
    if(!sx_add(c,&sx_st_caf_header,0,8))return false;
    while(at<(uint64_t)c->size) {
        uint8_t h[12];uint64_t n;
        if(!sx_read(c,(int64_t)at,h,12)||!sx_add(c,&sx_st_caf_chunk,(int64_t)at,12))return false;
        n=xx_data_get_u64(h,12,4,true);at+=12;
        if(n==UINT64_MAX)n=(uint64_t)c->size-at;
        if(!sx_st_fits(c,at,n))return false;
        if(!xx_rt_memcmp(h,"desc",4)){if(n!=32||!sx_add(c,&sx_st_caf_description,(int64_t)at,32))return false;}
        else if(!xx_rt_memcmp(h,"data",4)){if(n<4||!sx_add(c,&sx_st_caf_data,(int64_t)at,4))return false;}
        else if(!xx_rt_memcmp(h,"pakt",4)){if(n<24||!sx_add(c,&sx_st_caf_packet_table,(int64_t)at,24))return false;}
        at+=n;if(c->count>=20000)break;
    }
    return true;
}
bool sx_caf_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_caf(c);
    return ok&&sx_st_finish(c);
}
