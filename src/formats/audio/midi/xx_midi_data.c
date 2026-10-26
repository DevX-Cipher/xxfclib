/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MIDI data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_midi_header_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("header_length", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("format", "uint16", 8, 2, SX_ID),
    SX_FIELD("track_count", "uint16", 10, 2, SX_COUNT_PROP),
    SX_FIELD("division", "uint16", 12, 2, SX_NONE),
};
const sx_layout sx_st_midi_header = {0x60080001U, "midi_header", sx_st_midi_header_fields, SX_COUNT(sx_st_midi_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_st_midi_track_fields[] = {
    SX_FIELD("signature", "byte[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("length", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sx_st_midi_track = {0x60080002U, "midi_track", sx_st_midi_track_fields, SX_COUNT(sx_st_midi_track_fields), SX_BE};
static bool sx_st_midi(sx_context *c)
{
    uint32_t n;uint16_t tracks;uint64_t at;
    if(!sx_add(c,&sx_st_midi_header,0,14)||!sx_u32(c,4,true,&n)||!sx_u16(c,10,true,&tracks))return false;
    at=8+(uint64_t)n;
    for(uint32_t j=0;j<tracks&&c->count<20000;j++) {
        if(!sx_add(c,&sx_st_midi_track,(int64_t)at,8)||!sx_u32(c,(int64_t)at+4,true,&n)||!sx_st_fits(c,at+8,n))return false;
        at+=8+(uint64_t)n;
    }
    return true;
}
bool sx_midi_build(sx_context*c)
{
    bool ok=false;
    ok=sx_st_midi(c);
    return ok&&sx_st_finish(c);
}
