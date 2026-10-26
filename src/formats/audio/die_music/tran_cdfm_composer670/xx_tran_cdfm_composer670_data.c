/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Thomas 'Tran' Pytel's CDFM/Composer 670 module (.C67) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_c67_header_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("restart_order","uint8",1,1,SX_NONE),
};
const sx_layout sxmta_c67_header={UINT32_C(0x60810031),"c67_header",sxmta_c67_header_fields,SX_COUNT(sxmta_c67_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_name_fields[]={
 SX_FIELD("name","char[13]",0,13,SX_NONE),
};
const sx_layout sxmta_c67_name={UINT32_C(0x60810032),"c67_name",sxmta_c67_name_fields,SX_COUNT(sxmta_c67_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_fm_instrument_fields[]={
 SX_FIELD("feedback_connection","uint8",0,1,SX_FLAGS),
 SX_FIELD("modulator_characteristics","uint8",1,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",2,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",3,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",4,1,SX_FLAGS),
 SX_FIELD("modulator_waveform","uint8",5,1,SX_ID),
 SX_FIELD("carrier_characteristics","uint8",6,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",7,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",9,1,SX_FLAGS),
 SX_FIELD("carrier_waveform","uint8",10,1,SX_ID),
};
const sx_layout sxmta_c67_fm_instrument={UINT32_C(0x60810034),"c67_fm_instrument",sxmta_c67_fm_instrument_fields,SX_COUNT(sxmta_c67_fm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_pattern_bytes_fields[]={
 SX_FIELD("pattern_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxmta_c67_pattern_bytes={UINT32_C(0x60810036),"c67_pattern_bytes",sxmta_c67_pattern_bytes_fields,SX_COUNT(sxmta_c67_pattern_bytes_fields),SX_LE};
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_c67(sxmta_view*v)
{uint64_t end=v->c->size,p=0,x,n,total=0,max=2978;
 if(!MTA_TAKE(c67_header,&p,1,end)||!MTA_TAKE(c67_name,&p,32,end))return false;
 for(unsigned i=0;i<32;i++){if(!sxmta_u(v,p+4,4,&x,end)||!MTA_TAKE(c67_sample,&p,1,end))return false;total+=x;}
 if(!MTA_TAKE(c67_name,&p,32,end)||!MTA_TAKE(c67_fm_instrument,&p,32,end)||!MTA_TAKE(order8,&p,256,end)||!MTA_TAKE(c67_pattern_offset,&p,128,end)||!MTA_TAKE(c67_pattern_bytes,&p,128,end))return false;
 for(unsigned i=0;i<128;i++){if(!sxmta_u(v,1954+i*4,4,&x,end)||!sxmta_u(v,2466+i*4,4,&n,end)||!sxmta_span(v,2978+x,n,end))return false;if(2978+x+n>max)max=2978+x+n;}
 return sxmta_span(v,max,total,end);}
bool sx_tran_cdfm_composer670_build(sxmta_view*v)
{
 return sxmta_c67(v);
}
#undef MTA_TAKE
