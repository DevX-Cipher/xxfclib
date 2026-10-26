/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Lave Digitalmusicmaker data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_dmm_header_fields[]={
 SX_FIELD("bank_0_end_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("bank_1_end_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("bank_2_end_address","uint16",4,2,SX_ADDRESS),
 SX_FIELD("bank_3_end_address","uint16",6,2,SX_ADDRESS),
 SX_FIELD("bank_4_end_address","uint16",8,2,SX_ADDRESS),
 SX_FIELD("bank_5_end_address","uint16",10,2,SX_ADDRESS),
 SX_FIELD("pattern_line_count","uint8",12,1,SX_COUNT_PROP),
 SX_FIELD("padding","uint8",13,1,SX_RESERVED),
};
const sx_layout sxzxm_dmm_header={UINT32_C(0x608A0054),"dmm_header",sxzxm_dmm_header_fields,SX_COUNT(sxzxm_dmm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_mixing_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
 SX_FIELD("sample_parameter","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect","uint8",2,1,SX_NONE),
 SX_FIELD("period","uint8",3,1,SX_NONE),
};
const sx_layout sxzxm_dmm_mixing={UINT32_C(0x608A0056),"dmm_mixing",sxzxm_dmm_mixing_fields,SX_COUNT(sxzxm_dmm_mixing_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_sample_fields[]={
 SX_FIELD("name","char[9]",0,9,SX_NONE),
 SX_FIELD("start_address","uint16",9,2,SX_ADDRESS),
 SX_FIELD("bank","uint8",11,1,SX_ID),
 SX_FIELD("limit_address","uint16",12,2,SX_ADDRESS),
 SX_FIELD("loop_address","uint16",14,2,SX_ADDRESS),
};
const sx_layout sxzxm_dmm_sample={UINT32_C(0x608A0057),"dmm_sample",sxzxm_dmm_sample_fields,SX_COUNT(sxzxm_dmm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_event_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
 SX_FIELD("sample_parameter","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect","uint8",2,1,SX_NONE),
};
const sx_layout sxzxm_dmm_event={UINT32_C(0x608A0058),"dmm_event",sxzxm_dmm_event_fields,SX_COUNT(sxzxm_dmm_event_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_dmm(sx_context*c){
 uint8_t rows;if(!SXZXM_ADD(c,dmm_header,0))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_position,14,50)||!sxzxm_opt(c,&sxzxm_dmm_playback,64,1)||!sxzxm_opt(c,&sxzxm_dmm_mixing,69,5)||!sxzxm_opt(c,&sxzxm_dmm_sample,90,16))return false;
 if(sxzxm_u8(c,12,&rows)&&(rows==24||rows==32||rows==48||rows==64))for(unsigned i=0;i<24;i++)if(!sxzxm_opt(c,&sxzxm_dmm_event,350+(uint64_t)i*rows*9,(unsigned)rows*3))return false;
 return true;
}
bool sx_lave_digitalmusicmaker_build(sx_context*c)
{
 return sxzxm_dmm(c);
}
