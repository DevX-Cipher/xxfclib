/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CREATIVE_VOC data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_voc_header_fields[] = {
    SX_FIELD("signature", "byte[20]", 0, 20, SX_SIGNATURE),
    SX_FIELD("data_offset", "uint16", 20, 2, SX_OFFSET),
    SX_FIELD("version", "uint16", 22, 2, SX_NONE),
    SX_FIELD("version_checksum", "uint16", 24, 2, SX_CHECKSUM),
};
const sx_layout sx_st_voc_header = {0x60080008U, "voc_header", sx_st_voc_header_fields, SX_COUNT(sx_st_voc_header_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_voc_block_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("payload_size", "uint24", 1, 3, SX_SIZE),
};
const sx_layout sx_st_voc_block = {0x60080009U, "voc_block", sx_st_voc_block_fields, SX_COUNT(sx_st_voc_block_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_voc_terminator_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
};
const sx_layout sx_st_voc_terminator = {0x6008000AU, "voc_terminator", sx_st_voc_terminator_fields, SX_COUNT(sx_st_voc_terminator_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_voc_sound_fields[] = {
    SX_FIELD("time_constant", "uint8", 0, 1, SX_NONE),
    SX_FIELD("codec", "uint8", 1, 1, SX_ID),
};
const sx_layout sx_st_voc_sound = {0x6008000BU, "voc_sound", sx_st_voc_sound_fields, SX_COUNT(sx_st_voc_sound_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_voc_silence_fields[] = {
    SX_FIELD("sample_count_minus_one", "uint16", 0, 2, SX_NONE),
    SX_FIELD("time_constant", "uint8", 2, 1, SX_NONE),
};
const sx_layout sx_st_voc_silence = {0x6008000CU, "voc_silence", sx_st_voc_silence_fields, SX_COUNT(sx_st_voc_silence_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_voc_marker_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
};
const sx_layout sx_st_voc_marker = {0x6008000DU, "voc_marker", sx_st_voc_marker_fields, SX_COUNT(sx_st_voc_marker_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_voc_repeat_fields[] = {
    SX_FIELD("repeat_count", "uint16", 0, 2, SX_COUNT_PROP),
};
const sx_layout sx_st_voc_repeat = {0x6008000EU, "voc_repeat", sx_st_voc_repeat_fields, SX_COUNT(sx_st_voc_repeat_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_voc_sound_v2_fields[] = {
    SX_FIELD("sample_rate", "uint32", 0, 4, SX_NONE),
    SX_FIELD("bits_per_sample", "uint8", 4, 1, SX_NONE),
    SX_FIELD("channels", "uint8", 5, 1, SX_COUNT_PROP),
    SX_FIELD("codec", "uint16", 6, 2, SX_ID),
    SX_FIELD("reserved", "byte[4]", 8, 4, SX_RESERVED),
};
const sx_layout sx_st_voc_sound_v2 = {0x6008000FU, "voc_sound_v2", sx_st_voc_sound_v2_fields, SX_COUNT(sx_st_voc_sound_v2_fields), SX_LE};
static bool sx_st_voc(sx_context *c)
{
    uint16_t offset;uint64_t at;
    if(!sx_add(c,&sx_st_voc_header,0,26)||!sx_u16(c,20,false,&offset))return false;at=offset;
    while(at<(uint64_t)c->size) {
        uint8_t h[4];uint32_t n;const sx_layout *l=NULL;unsigned z=0;
        if(!sx_read(c,(int64_t)at,h,1))return false;
        if(!h[0])return sx_add(c,&sx_st_voc_terminator,(int64_t)at,1);
        if(!sx_read(c,(int64_t)at,h,4)||!sx_add(c,&sx_st_voc_block,(int64_t)at,4))return false;
        n=xx_data_get_u24(h,4,1,false);at+=4;if(!sx_st_fits(c,at,n))return false;
        switch(h[0]){case 1:l=&sx_st_voc_sound;z=2;break;case 3:l=&sx_st_voc_silence;z=3;break;case 4:l=&sx_st_voc_marker;z=2;break;case 6:l=&sx_st_voc_repeat;z=2;break;case 9:l=&sx_st_voc_sound_v2;z=12;break;default:break;}
        if(l&&(n<z||!sx_add(c,l,(int64_t)at,z)))return false;at+=n;
    }
    return false;
}
bool sx_creative_voc_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_voc(c);
    return ok&&sx_st_finish(c);
}
