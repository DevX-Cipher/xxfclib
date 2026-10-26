/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * hxc qd data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_hxc_qd_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("revision","uint32",8,4,SX_ID),
    SX_FIELD("track_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("side_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("encoding","uint32",20,4,SX_ID),
    SX_FIELD("write_protected","uint32",24,4,SX_FLAGS),
    SX_FIELD("cell_rate","uint32",28,4,SX_NONE),
    SX_FIELD("flags","uint32",32,4,SX_FLAGS),
    SX_FIELD("track_table_offset","uint32",36,4,SX_OFFSET),
};
const sx_layout sxdleg_hxc_qd_header = {0x60750028U,"hxc_qd_header",sxdleg_hxc_qd_header_fields,SX_COUNT(sxdleg_hxc_qd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_hxc_qd_track_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("start_switch_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("stop_switch_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxdleg_hxc_qd_track = {0x60750029U,"hxc_qd_track",sxdleg_hxc_qd_track_fields,SX_COUNT(sxdleg_hxc_qd_track_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static bool sxdleg_qd(sx_context*c){uint8_t h[40];if(!sxdleg_read(c,0,h,40)||xx_rt_memcmp(h,"HXCQDDRV",8)||!SXDLEG_ADD(c,hxc_qd_header,0))return false;uint64_t tracks=sxdleg32(h+12,0),sides=sxdleg32(h+16,0),p=sxdleg32(h+36,0);if(!tracks||tracks>170||!sides||sides>2||p<40||!sxdleg_span(c,p,tracks*sides*16))return true;return SXDLEG_TABLE(c,hxc_qd_track,p,tracks*sides);}
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
bool sx_hxc_qd_build(sx_context*c)
{
 return sxdleg_qd(c);
}
