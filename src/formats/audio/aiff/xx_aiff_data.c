/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AIFF data structures, moved out of the container schema family. */
#include "../../xx_format_schema_container.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_c_aiff_form_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("form_type", "char[4]", 8, 4, SX_ID),
};
const sx_layout sx_c_aiff_form_header = { UINT32_C(0x60020041), "aiff_form_header", sx_c_aiff_form_header_fields, SX_COUNT(sx_c_aiff_form_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_aiff_chunk_header_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_ID),
    SX_FIELD("chunk_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sx_c_aiff_chunk_header = { UINT32_C(0x60020042), "aiff_chunk_header", sx_c_aiff_chunk_header_fields, SX_COUNT(sx_c_aiff_chunk_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_aiff_common_chunk_fields[] = {
    SX_FIELD("channels", "int16", 0, 2, SX_COUNT_PROP),
    SX_FIELD("sample_frames", "uint32", 2, 4, SX_COUNT_PROP),
    SX_FIELD("sample_size_bits", "int16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("sample_rate_extended80", "bytes", 8, 10, SX_NONE),
};
const sx_layout sx_c_aiff_common_chunk = { UINT32_C(0x60020043), "aiff_common_chunk", sx_c_aiff_common_chunk_fields, SX_COUNT(sx_c_aiff_common_chunk_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_aifc_compression_type_fields[] = {
    SX_FIELD("compression_type", "char[4]", 0, 4, SX_ID),
};
const sx_layout sx_c_aifc_compression_type = { UINT32_C(0x60020044), "aifc_compression_type", sx_c_aifc_compression_type_fields, SX_COUNT(sx_c_aifc_compression_type_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_aiff_sound_data_header_fields[] = {
    SX_FIELD("offset", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("block_size", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sx_c_aiff_sound_data_header = { UINT32_C(0x60020045), "aiff_sound_data_header", sx_c_aiff_sound_data_header_fields, SX_COUNT(sx_c_aiff_sound_data_header_fields), SX_BE };
static const xx_data_struct_field_desc sx_c_aiff_format_version_fields[] = {
    SX_FIELD("timestamp", "uint32", 0, 4, SX_TIME),
};
const sx_layout sx_c_aiff_format_version = { UINT32_C(0x60020046), "aiff_format_version", sx_c_aiff_format_version_fields, SX_COUNT(sx_c_aiff_format_version_fields), SX_BE };
static bool sx_c_aiff(sx_context *c)
{
    uint8_t h[12];uint32_t n;int64_t at=12,end;bool compressed;
    if(!sx_read(c,0,h,12)||xx_rt_memcmp(h,"FORM",4)||(xx_rt_memcmp(h+8,"AIFF",4)&&xx_rt_memcmp(h+8,"AIFC",4)))return false;
    compressed=!xx_rt_memcmp(h+8,"AIFC",4);n=xx_data_get_u32(h+4,4,0,true);end=8+(int64_t)n;
    if(n<4||end>c->size||!sx_add(c,&sx_c_aiff_form_header,0,12))return false;
    while(at<end){
        uint8_t id[4];uint32_t len,width=0;int64_t body;const sx_layout *l=NULL;
        if(end-at<8||!sx_read(c,at,id,4)||!sx_u32(c,at+4,true,&len)||len>(uint64_t)(end-at-8)||!sx_add(c,&sx_c_aiff_chunk_header,at,8))return false;
        body=at+8;
        if(!xx_rt_memcmp(id,"COMM",4)){
            if(len<18||!sx_add(c,&sx_c_aiff_common_chunk,body,18))return false;width=18;
            if(compressed){if(len<22||!sx_add(c,&sx_c_aifc_compression_type,body+18,4))return false;width=22;}
        }else if(!xx_rt_memcmp(id,"SSND",4)){l=&sx_c_aiff_sound_data_header;width=8;}
        else if(!xx_rt_memcmp(id,"FVER",4)){l=&sx_c_aiff_format_version;width=4;}
        if(width>len||(l&&!sx_add(c,l,body,width))||!sx_raw(c,body+width,len-width))return false;
        at=body+len;if((len&1)&&at<end){if(!sx_raw(c,at,1))return false;++at;}
    }
    return at==end&&sx_raw(c,end,c->size-end);
}
bool sx_aiff_build(sx_context*c)
{
    return sx_c_aiff(c);
}
