/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * atari stw data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_stw_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("side_count","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("track_count","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("mfm_word_count","uint16",8,2,SX_COUNT_PROP),
};
const sx_layout sxdleg_stw_header = {0x6075001aU,"stw_header",sxdleg_stw_header_fields,SX_COUNT(sxdleg_stw_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdleg_stw_track_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("side","uint8",3,1,SX_NONE),
    SX_FIELD("cylinder","uint8",4,1,SX_NONE),
};
const sx_layout sxdleg_stw_track_header = {0x6075001bU,"stw_track_header",sxdleg_stw_track_header_fields,SX_COUNT(sxdleg_stw_track_header_fields),SX_BE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_stw(sx_context*c){uint8_t h[10];if(!sxdleg_read(c,0,h,10)||xx_rt_memcmp(h,"STW\0",4))return false;unsigned sides=h[6],tracks=h[7],words=sxdleg16(h+8,1);if(!sides||sides>2||!tracks||tracks>170||words<128||words>32768||!SXDLEG_ADD(c,stw_header,0))return false;uint64_t step=5+(uint64_t)words*2;for(unsigned i=0;i<sides*tracks;i++){uint64_t p=10+i*step;if(!sxdleg_span(c,p,step))break;if(!SXDLEG_ADD(c,stw_track_header,p))return false;}return true;}
#undef SXDLEG_ADD
bool sx_atari_stw_build(sx_context*c)
{
 return sxdleg_stw(c);
}
