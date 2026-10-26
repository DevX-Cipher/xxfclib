/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Trackstar APP data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_trackstar_track_header_fields[] = {
    SX_FIELD("description","char[46]",0,46,SX_NONE),
    SX_FIELD("reserved","byte[82]",46,82,SX_RESERVED),
    SX_FIELD("halftrack_image","uint8",128,1,SX_FLAGS),
};
const sx_layout sxdleg_trackstar_track_header = {0x6075003aU,"trackstar_track_header",sxdleg_trackstar_track_header_fields,SX_COUNT(sxdleg_trackstar_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_trackstar_track_size_fields[] = {
    SX_FIELD("stored_track_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxdleg_trackstar_track_size = {0x6075003bU,"trackstar_track_size",sxdleg_trackstar_track_size_fields,SX_COUNT(sxdleg_trackstar_track_size_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_trackstar(sx_context*c){if(c->size!=266240&&c->size!=532480)return false;unsigned n=(unsigned)(c->size/6656);for(unsigned i=0;i<n;i++)if(!SXDLEG_ADD(c,trackstar_track_header,(uint64_t)i*6656)||!SXDLEG_ADD(c,trackstar_track_size,(uint64_t)i*6656+6654))return false;return true;}
#undef SXDLEG_ADD
bool sx_trackstar_build(sx_context*c)
{
 return sxdleg_trackstar(c);
}
