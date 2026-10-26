/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Ken Silverman KSM data structures, moved out of the adlib schema family. */
#include "../../xx_format_schema_adlib.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxad_adlib_ksm_header_fields[] = {
    SX_FIELD("track_instruments","uint8_t[16]",0,16,SX_NONE),
    SX_FIELD("track_quantization","uint8_t[16]",16,16,SX_NONE),
    SX_FIELD("track_channel_counts","uint8_t[16]",32,16,SX_NONE),
    SX_FIELD("reserved","uint8_t[16]",48,16,SX_RESERVED),
    SX_FIELD("track_volumes","uint8_t[16]",64,16,SX_NONE),
    SX_FIELD("event_count","uint16_t",80,2,SX_COUNT_PROP),
};
const sx_layout sxad_adlib_ksm_header = {UINT32_C(0x600f0048),"adlib_ksm_header",sxad_adlib_ksm_header_fields,SX_COUNT(sxad_adlib_ksm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_ksm_event_fields[] = {
    SX_FIELD("packed_note_event","uint32_t",0,4,SX_FLAGS),
};
const sx_layout sxad_adlib_ksm_event = {UINT32_C(0x600f0049),"adlib_ksm_event",sxad_adlib_ksm_event_fields,SX_COUNT(sxad_adlib_ksm_event_fields),SX_LE};
static bool sxad_ksm(sx_context *c)
{
    uint16_t count;if(!sx_u16(c,80,false,&count)||!count||c->size!=82+(int64_t)count*4)return false;
    return sx_add(c,&sxad_adlib_ksm_header,0,82)&&sx_table(c,&sxad_adlib_ksm_event,82,4,count);
}
bool sx_ken_ksm_build(sx_context*c)
{
    return sxad_ksm(c);
}
