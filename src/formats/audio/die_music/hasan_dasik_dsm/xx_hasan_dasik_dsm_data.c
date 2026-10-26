/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Carlos Hasan's Digital Audio Sound Interface Kit module (.DSM) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_dsm1_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[28]",4,28,SX_STRING),
 SX_FIELD("unknown32","bytes",32,4,SX_NONE),
 SX_FIELD("eof_marker","uint8",36,1,SX_SIGNATURE),
 SX_FIELD("channels","uint8",37,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint8",38,1,SX_COUNT_PROP),
 SX_FIELD("instruments","uint8",39,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint8",40,1,SX_COUNT_PROP),
 SX_FIELD("speed","uint8",41,1,SX_NONE),
 SX_FIELD("tempo","uint8",42,1,SX_NONE),
 SX_FIELD("global_volume","uint8",43,1,SX_NONE),
 SX_FIELD("unknown44","bytes",44,4,SX_NONE),
};
const sx_layout sxmn_dsm1_header={UINT32_C(0x60760056),"dsm1_header",sxmn_dsm1_header_fields,SX_COUNT(sxmn_dsm1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm1_instrument_paragraph_fields[]={
 SX_FIELD("instrument_paragraph","uint16",0,2,SX_NONE),
};
const sx_layout sxmn_dsm1_instrument_paragraph={UINT32_C(0x60760057),"dsm1_instrument_paragraph",sxmn_dsm1_instrument_paragraph_fields,SX_COUNT(sxmn_dsm1_instrument_paragraph_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm1_pattern_paragraph_fields[]={
 SX_FIELD("pattern_paragraph","uint16",0,2,SX_NONE),
};
const sx_layout sxmn_dsm1_pattern_paragraph={UINT32_C(0x60760058),"dsm1_pattern_paragraph",sxmn_dsm1_pattern_paragraph_fields,SX_COUNT(sxmn_dsm1_pattern_paragraph_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm1_pattern_fields[]={
 SX_FIELD("packed_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxmn_dsm1_pattern={UINT32_C(0x6076005A),"dsm1_pattern",sxmn_dsm1_pattern_fields,SX_COUNT(sxmn_dsm1_pattern_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_dsm1(sxmn_view*v)
{uint64_t end=v->c->size,ins,patterns;if(!MN_ROW(dsm1_header,0,end)||!sxmn_word(v,39,1,false,&ins,end)||!sxmn_word(v,40,1,false,&patterns,end)||!sxmn_table(v,&sxmn_dsm_order,48,128,end)||!sxmn_table(v,&sxmn_dsm1_instrument_paragraph,176,ins,end)||!sxmn_table(v,&sxmn_dsm1_pattern_paragraph,176+2*ins,patterns,end))return false;
 for(uint64_t i=0;i<ins;i++){uint64_t para,at,hi,lo,z;if(!sxmn_word(v,176+2*i,2,false,&para,end))return false;if(!para)continue;at=para*16;if(!MN_ROW(dsm1_instrument,at,end)||!sxmn_word(v,at+35,1,false,&hi,end)||!sxmn_word(v,at+36,2,false,&lo,end)||!sxmn_word(v,at+38,2,false,&z,end)||!sxmn_span(v,((hi<<16)|lo)*16,z,end))return false;}
 for(uint64_t i=0;i<patterns;i++){uint64_t para,z;if(!sxmn_word(v,176+2*ins+2*i,2,false,&para,end))return false;if(!para)continue;uint64_t at=para*16;if(!MN_ROW(dsm1_pattern,at,end)||!sxmn_word(v,at,2,false,&z,end)||!sxmn_span(v,at+2,z,end))return false;}return true;}
bool sx_hasan_dasik_dsm_build(sxmn_view*v)
{
 return sxmn_dsm1(v);
}
#undef MN_ROW
