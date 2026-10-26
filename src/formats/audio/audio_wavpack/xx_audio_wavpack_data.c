/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUDIO_WAVPACK data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_wavpack_block_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("size_minus_eight", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("version", "uint16", 8, 2, SX_NONE),
    SX_FIELD("track_number", "uint8", 10, 1, SX_NONE),
    SX_FIELD("index_number", "uint8", 11, 1, SX_NONE),
    SX_FIELD("total_samples", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("block_index", "uint32", 16, 4, SX_NONE),
    SX_FIELD("block_samples", "uint32", 20, 4, SX_COUNT_PROP),
    SX_FIELD("flags", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("crc32", "uint32", 28, 4, SX_CHECKSUM),
};
const sx_layout sx_st_wavpack_block = {0x60080024U, "wavpack_block", sx_st_wavpack_block_fields, SX_COUNT(sx_st_wavpack_block_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_wavpack_metadata_fields[] = {
    SX_FIELD("id_and_flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("word_count", "uint8", 1, 1, SX_COUNT_PROP),
};
const sx_layout sx_st_wavpack_metadata = {0x60080025U, "wavpack_metadata", sx_st_wavpack_metadata_fields, SX_COUNT(sx_st_wavpack_metadata_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_wavpack_metadata_large_fields[] = {
    SX_FIELD("id_and_flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("word_count", "uint24", 1, 3, SX_COUNT_PROP),
};
const sx_layout sx_st_wavpack_metadata_large = {0x60080026U, "wavpack_metadata_large", sx_st_wavpack_metadata_large_fields, SX_COUNT(sx_st_wavpack_metadata_large_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_apev2_tag_fields[] = {
    SX_FIELD("signature", "byte[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 8, 4, SX_NONE),
    SX_FIELD("tag_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("item_count", "uint32", 16, 4, SX_COUNT_PROP),
    SX_FIELD("flags", "uint32", 20, 4, SX_FLAGS),
    SX_FIELD("reserved", "byte[8]", 24, 8, SX_RESERVED),
};
const sx_layout sx_st_apev2_tag = {0x60080027U, "apev2_tag", sx_st_apev2_tag_fields, SX_COUNT(sx_st_apev2_tag_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_apev2_item_fields[] = {
    SX_FIELD("value_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("flags", "uint32", 4, 4, SX_FLAGS),
};
const sx_layout sx_st_apev2_item = {0x60080028U, "apev2_item", sx_st_apev2_item_fields, SX_COUNT(sx_st_apev2_item_fields), SX_LE};
static bool sx_st_ape(sx_context *c,uint64_t at)
{
    uint8_t h[32];uint64_t end=(uint64_t)c->size;uint32_t count,flags;
    if(end-at<32||!sx_read(c,(int64_t)end-32,h,32)||!sx_add(c,&sx_st_apev2_tag,(int64_t)end-32,32))return false;
    count=xx_data_get_u32(h,32,16,false);flags=xx_data_get_u32(h,32,20,false);end-=32;
    if(flags&0x80000000U){if(end-at<32||!sx_add(c,&sx_st_apev2_tag,(int64_t)at,32))return false;at+=32;}
    for(uint32_t j=0;j<count;j++) {
        uint32_t n;uint8_t ch=1;unsigned len=0;
        if(end-at<8||!sx_u32(c,(int64_t)at,false,&n)||!sx_add(c,&sx_st_apev2_item,(int64_t)at,8))return false;at+=8;
        while(ch&&at<end&&len++<256){if(!sx_read(c,(int64_t)at++,&ch,1))return false;}
        if(ch||n>end-at)return false;at+=n;
    }
    return at==end;
}
static bool sx_st_wavpack(sx_context *c)
{
    uint64_t at=0;
    while(at<(uint64_t)c->size) {
        uint8_t h[32];uint32_t n;
        if(!sx_read(c,(int64_t)at,h,8))return false;
        if(!xx_rt_memcmp(h,"APETAGEX",8))return sx_st_ape(c,at);
        if(!sx_read(c,(int64_t)at,h,32)||!sx_add(c,&sx_st_wavpack_block,(int64_t)at,32))return false;
        n=xx_data_get_u32(h,32,4,false);if(n<24||!sx_st_fits(c,at,8+(uint64_t)n))return false;
        uint64_t end=at+8+n;at+=32;
        while(at<end) {
            uint8_t m[4];uint32_t words;unsigned size;
            if(end-at<2||!sx_read(c,(int64_t)at,m,2))return false;size=(m[0]&128)?4:2;
            if(end-at<size||!sx_read(c,(int64_t)at,m,size)||!sx_add(c,size==4?&sx_st_wavpack_metadata_large:&sx_st_wavpack_metadata,(int64_t)at,size))return false;
            words=size==4?xx_data_get_u24(m,4,1,false):m[1];at+=size;
            if((uint64_t)words*2>end-at)return false;at+=(uint64_t)words*2;
            if(c->count>=20000)return true;
        }
        if(c->count>=20000)break;
    }
    return true;
}
bool sx_audio_wavpack_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_wavpack(c);
    return ok&&sx_st_finish(c);
}
