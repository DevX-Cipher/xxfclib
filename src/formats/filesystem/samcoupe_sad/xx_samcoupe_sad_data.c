/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * samcoupe sad data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_sad_header_fields[] = {
    SX_FIELD("magic","char[18]",0,18,SX_SIGNATURE),
    SX_FIELD("side_count","uint8",18,1,SX_COUNT_PROP),
    SX_FIELD("track_count","uint8",19,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",20,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_div64","uint8",21,1,SX_NONE),
};
const sx_layout sxdleg_sad_header = {0x60750039U,"sad_header",sxdleg_sad_header_fields,SX_COUNT(sxdleg_sad_header_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_tag(sx_context*c,uint64_t p,const char*s,size_t size){uint8_t b[16];return size<=16&&sxdleg_read(c,p,b,size)&&!xx_rt_memcmp(b,s,size);}
static bool sxdleg_sad(sx_context*c){return sxdleg_tag(c,0,"Aley's disk back",15)&&SXDLEG_ADD(c,sad_header,0);}
#undef SXDLEG_ADD
bool sx_samcoupe_sad_build(sx_context*c)
{
 return sxdleg_sad(c);
}
