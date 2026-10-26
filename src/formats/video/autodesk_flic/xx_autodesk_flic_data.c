/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUTODESK_FLIC data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_fli_header_fields[] = {
    SX_FIELD("file_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("magic", "uint16", 4, 2, SX_SIGNATURE),
    SX_FIELD("frame_count", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("width", "uint16", 8, 2, SX_NONE),
    SX_FIELD("height", "uint16", 10, 2, SX_NONE),
    SX_FIELD("depth", "uint16", 12, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 14, 2, SX_FLAGS),
    SX_FIELD("speed_jiffies", "uint16", 16, 2, SX_NONE),
    SX_FIELD("reserved", "byte[110]", 18, 110, SX_RESERVED),
};
const sx_layout sx_st_fli_header = {0x60080045U, "fli_header", sx_st_fli_header_fields, SX_COUNT(sx_st_fli_header_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_flc_header_fields[] = {
    SX_FIELD("file_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("magic", "uint16", 4, 2, SX_SIGNATURE),
    SX_FIELD("frame_count", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("width", "uint16", 8, 2, SX_NONE),
    SX_FIELD("height", "uint16", 10, 2, SX_NONE),
    SX_FIELD("depth", "uint16", 12, 2, SX_NONE),
    SX_FIELD("flags", "uint16", 14, 2, SX_FLAGS),
    SX_FIELD("speed_milliseconds", "uint32", 16, 4, SX_NONE),
    SX_FIELD("reserved", "uint16", 20, 2, SX_RESERVED),
    SX_FIELD("created_dos_datetime", "uint32", 22, 4, SX_NONE),
    SX_FIELD("creator", "uint32", 26, 4, SX_ID),
    SX_FIELD("updated_dos_datetime", "uint32", 30, 4, SX_NONE),
    SX_FIELD("updater", "uint32", 34, 4, SX_ID),
    SX_FIELD("aspect_x", "uint16", 38, 2, SX_NONE),
    SX_FIELD("aspect_y", "uint16", 40, 2, SX_NONE),
    SX_FIELD("reserved2", "byte[38]", 42, 38, SX_RESERVED),
    SX_FIELD("first_frame_offset", "uint32", 80, 4, SX_OFFSET),
    SX_FIELD("second_frame_offset", "uint32", 84, 4, SX_OFFSET),
    SX_FIELD("reserved3", "byte[40]", 88, 40, SX_RESERVED),
};
const sx_layout sx_st_flc_header = {0x60080046U, "flc_header", sx_st_flc_header_fields, SX_COUNT(sx_st_flc_header_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_flic_chunk_fields[] = {
    SX_FIELD("size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("type", "uint16", 4, 2, SX_ID),
};
const sx_layout sx_st_flic_chunk = {0x60080047U, "flic_chunk", sx_st_flic_chunk_fields, SX_COUNT(sx_st_flic_chunk_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_flic_frame_fields[] = {
    SX_FIELD("size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("type", "uint16", 4, 2, SX_ID),
    SX_FIELD("chunk_count", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("delay", "uint16", 8, 2, SX_NONE),
    SX_FIELD("reserved", "uint16", 10, 2, SX_RESERVED),
    SX_FIELD("width_override", "uint16", 12, 2, SX_NONE),
    SX_FIELD("height_override", "uint16", 14, 2, SX_NONE),
};
const sx_layout sx_st_flic_frame = {0x60080048U, "flic_frame", sx_st_flic_frame_fields, SX_COUNT(sx_st_flic_frame_fields), SX_LE};
static bool sx_st_flic(sx_context *c)
{
    uint16_t magic;uint64_t at=128;
    if(!sx_u16(c,4,false,&magic)||!sx_add(c,magic==0xaf11?&sx_st_fli_header:&sx_st_flc_header,0,128))return false;
    while(at<(uint64_t)c->size) {
        uint32_t n;uint16_t type;
        if(!sx_u32(c,(int64_t)at,false,&n)||!sx_u16(c,(int64_t)at+4,false,&type)||n<6||!sx_st_fits(c,at,n))return false;
        if(type==0xf1fa) {
            uint16_t count;uint64_t q=at+16,end=at+n;
            if(n<16||!sx_add(c,&sx_st_flic_frame,(int64_t)at,16)||!sx_u16(c,(int64_t)at+6,false,&count))return false;
            for(uint32_t i=0;i<count&&c->count<20000;i++) {
                uint32_t z;if(end-q<6||!sx_u32(c,(int64_t)q,false,&z)||z<6||z>end-q||!sx_add(c,&sx_st_flic_chunk,(int64_t)q,6))return false;q+=z;
            }
        } else if(!sx_add(c,&sx_st_flic_chunk,(int64_t)at,6))return false;
        at+=n;if(c->count>=20000)break;
    }
    return true;
}
bool sx_autodesk_flic_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_flic(c);
    return ok&&sx_st_finish(c);
}
