/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * azatoth_phapacker data structures, moved out of the modvariants schema family. */
#include "../../../xx_format_schema_modvariants.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmodv_pha_sample_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
 SX_FIELD("unknown","uint8",2,1,SX_NONE),
 SX_FIELD("volume","uint8",3,1,SX_NONE),
 SX_FIELD("loop_start_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",6,2,SX_NONE),
 SX_FIELD("sample_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("finetune_times_72","uint16",12,2,SX_NONE),
};
const sx_layout sxmodv_pha_sample={UINT32_C(0x609B0009),"pha_sample",sxmodv_pha_sample_fields,SX_COUNT(sxmodv_pha_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_pha_control_fields[]={
 SX_FIELD("unknown0","bytes",0,2,SX_NONE),
 SX_FIELD("position_table_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("unknown4","bytes",4,10,SX_NONE),
};
const sx_layout sxmodv_pha_control={UINT32_C(0x609B000A),"pha_control",sxmodv_pha_control_fields,SX_COUNT(sxmodv_pha_control_fields),SX_BE};
static const xx_data_struct_field_desc sxmodv_pha_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmodv_pha_pattern_offset={UINT32_C(0x609B000B),"pha_pattern_offset",sxmodv_pha_pattern_offset_fields,SX_COUNT(sxmodv_pha_pattern_offset_fields),SX_BE};
#define SMV_ROW(n,p) sxmodv_row(v,&sxmodv_##n,p)
static bool sxmodv_pha(sxmodv_view*v){
 if(!sxmodv_span(v,0,960))return false;
 for(unsigned i=0;i<31;i++)if(!SMV_ROW(pha_sample,i*14))return false;
 if(!SMV_ROW(pha_control,434))return false;
 for(unsigned i=0;i<128;i++)if(!SMV_ROW(pha_pattern_offset,448+i*4))return false;
 /* Repeated packed cells have player-state-dependent channel replication;
  * retain their physical bytes as raw instead of inventing decoded rows. */
 return true;
}
bool sx_azatoth_phapacker_build(sxmodv_view*v)
{
 return sxmodv_pha(v);
}
#undef SMV_ROW
