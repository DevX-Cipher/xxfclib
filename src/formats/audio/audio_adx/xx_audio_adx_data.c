/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUDIO_ADX data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_adx_header_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("data_offset_minus_four", "uint16", 2, 2, SX_OFFSET),
    SX_FIELD("encoding", "uint8", 4, 1, SX_ID),
    SX_FIELD("block_size", "uint8", 5, 1, SX_SIZE),
    SX_FIELD("sample_bits", "uint8", 6, 1, SX_NONE),
    SX_FIELD("channels", "uint8", 7, 1, SX_COUNT_PROP),
    SX_FIELD("sample_rate", "uint32", 8, 4, SX_NONE),
    SX_FIELD("sample_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("highpass_frequency", "uint16", 16, 2, SX_NONE),
    SX_FIELD("version", "uint8", 18, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 19, 1, SX_FLAGS),
};
const sx_layout sx_st_adx_header = {0x60080022U, "adx_header", sx_st_adx_header_fields, SX_COUNT(sx_st_adx_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_adx_terminator_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("payload_size", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("padding", "byte[14]", 4, 14, SX_RESERVED),
};
const sx_layout sx_st_adx_terminator = {0x60080023U, "adx_terminator", sx_st_adx_terminator_fields, SX_COUNT(sx_st_adx_terminator_fields), SX_BE};
bool sx_audio_adx_build(sx_context*c)
{
    bool ok=false;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_AUDIO_ADX:{uint8_t h[20];uint64_t header,frames,end;ok=sx_read(c,0,h,20)&&sx_add(c,&sx_st_adx_header,0,20);if(!ok)break;header=4+(uint64_t)xx_data_get_u16(h,20,2,true);frames=((uint64_t)xx_data_get_u32(h,20,12,true)+31)/32*h[7];end=header+frames*18;if(sx_st_fits(c,end,18)){uint16_t magic;ok=sx_u16(c,(int64_t)end,true,&magic);if(ok&&magic==0x8001)ok=sx_add(c,&sx_st_adx_terminator,(int64_t)end,18);}break;}
    }
    return ok&&sx_st_finish(c);
}
