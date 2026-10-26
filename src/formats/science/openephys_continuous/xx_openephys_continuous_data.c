/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Open Ephys continuous data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_openephys_record_fields[] = {
    SX_FIELD("timestamp","int64",0,8,SX_NONE),
    SX_FIELD("sample_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("recording_number","uint16be",10,2,SX_ID),
};
const sx_layout sxsw_openephys_record = {UINT32_C(0x602d0038),"openephys_record",sxsw_openephys_record_fields,SX_COUNT(sxsw_openephys_record_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_openephys_marker_fields[] = {
    SX_FIELD("marker","uint8[10]",0,10,SX_SIGNATURE),
};
const sx_layout sxsw_openephys_marker = {UINT32_C(0x602d0039),"openephys_marker",sxsw_openephys_marker_fields,SX_COUNT(sxsw_openephys_marker_fields),SX_LE};
static bool sxsw_openephys(sx_context *c)
{
 int64_t at=1024;for(unsigned i=0;at<c->size&&i<4095;i++,at+=2070)if(!sxsw_span(c,at,2070)||!sxsw_add(c,&sxsw_openephys_record,at,12)||!sxsw_add(c,&sxsw_openephys_marker,at+2060,10))return false;return at==c->size;
}
bool sx_openephys_continuous_build(sx_context*c)
{
 return sxsw_openephys(c);
}
