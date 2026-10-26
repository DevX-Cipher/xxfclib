/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FLAC data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_flac_marker_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
};
const sx_layout sx_c_flac_marker = { UINT32_C(0x6002003C), "flac_marker", sx_c_flac_marker_fields, SX_COUNT(sx_c_flac_marker_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_flac_application_header_fields[] = {
    SX_FIELD("application_id", "char[4]", 0, 4, SX_ID),
};
const sx_layout sx_c_flac_application_header = { UINT32_C(0x6002003F), "flac_application_header", sx_c_flac_application_header_fields, SX_COUNT(sx_c_flac_application_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_flac_seekpoint_fields[] = {
    SX_FIELD("sample_number", "uint64", 0, 8, SX_NONE),
    SX_FIELD("stream_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("frame_samples", "uint16", 16, 2, SX_COUNT_PROP),
};
const sx_layout sx_c_flac_seekpoint = { UINT32_C(0x60020040), "flac_seekpoint", sx_c_flac_seekpoint_fields, SX_COUNT(sx_c_flac_seekpoint_fields), SX_BE };
static bool sx_c_flac(sx_context *c)
{
    uint8_t h[4];int64_t at=4;bool last=false;unsigned blocks=0;
    if(!sx_read(c,0,h,4)||xx_rt_memcmp(h,"fLaC",4)||!sx_add(c,&sx_c_flac_marker,0,4))return false;
    while(!last){
        uint32_t n;unsigned type;uint32_t width=0;
        if(!sx_read(c,at,h,4))return false;
        type=h[0]&127U;last=(h[0]&128U)!=0;n=((uint32_t)h[1]<<16)|((uint32_t)h[2]<<8)|h[3];
        if(type==127||(!blocks&&type!=0)||!sx_c_bounds(c,at+4,n)||!sx_add(c,&sx_c_flac_metadata_block_header,at,4))return false;
        at+=4;
        if(type==0){if(n!=34||blocks||!sx_add(c,&sx_c_flac_streaminfo,at,34))return false;width=34;}
        else if(type==2){if(n<4||!sx_add(c,&sx_c_flac_application_header,at,4))return false;width=4;}
        else if(type==3){if(n%18||!sx_table(c,&sx_c_flac_seekpoint,at,18,n/18))return false;width=n;}
        if(!sx_raw(c,at+width,n-width))return false;
        at+=n;++blocks;
    }
    return sx_raw(c,at,c->size-at);
}
bool sx_flac_build(sx_context*c)
{
    return sx_c_flac(c);
}
