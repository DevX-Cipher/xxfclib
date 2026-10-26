/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Sqdigitaltracker data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_sqd_sample_fields[]={
 SX_FIELD("start_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("loop_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("is_looped","uint8",4,1,SX_FLAGS),
 SX_FIELD("bank","uint8",5,1,SX_ID),
 SX_FIELD("padding","bytes",6,2,SX_RESERVED),
};
const sx_layout sxzxm_sqd_sample={UINT32_C(0x608A005A),"sqd_sample",sxzxm_sqd_sample_fields,SX_COUNT(sxzxm_sqd_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_title_fields[]={
 SX_FIELD("title","char[32]",0,32,SX_NONE),
};
const sx_layout sxzxm_sqd_title={UINT32_C(0x608A005B),"sqd_title",sxzxm_sqd_title_fields,SX_COUNT(sxzxm_sqd_title_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_event_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
 SX_FIELD("sample_volume","uint8",1,1,SX_FLAGS),
};
const sx_layout sxzxm_sqd_event={UINT32_C(0x608A005E),"sqd_event",sxzxm_sqd_event_fields,SX_COUNT(sxzxm_sqd_event_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_sqd(sx_context*c){
 if(!sxzxm_span(c,0,1024))return false;
 if(!sxzxm_put(c,&sxzxm_sqd_layout,192,8)||!SXZXM_ADD(c,sqd_title,256)||!sxzxm_put(c,&sxzxm_sqd_sample,288,16)||!sxzxm_put(c,&sxzxm_zx_position,416,100)||!SXZXM_ADD(c,sqd_positions_limit,516)||!SXZXM_ADD(c,sqd_playback,528)||!sxzxm_put(c,&sxzxm_chiptracker_sample_name,768,16))return false;
 for(unsigned i=0;i<32;i++)if(!sxzxm_opt(c,&sxzxm_sqd_event,1024+512U*i,256))return false;return true;
}
bool sx_sqdigitaltracker_build(sx_context*c)
{
 return sxzxm_sqd(c);
}
