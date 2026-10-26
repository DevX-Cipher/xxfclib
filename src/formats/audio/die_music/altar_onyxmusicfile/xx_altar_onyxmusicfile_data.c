/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Altar/Onyx's Onyx Music File (.OMF) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamip_omf_identity_fields[]={
 SX_FIELD("signature","char[15]",0,15,SX_SIGNATURE),
 SX_FIELD("eof_marker","uint8",15,1,SX_ID),
 SX_FIELD("zero","uint8",16,1,SX_NONE),
 SX_FIELD("version","uint8",17,1,SX_ID),
};
const sx_layout sxamip_omf_identity={UINT32_C(0x6090000C),"omf_identity",sxamip_omf_identity_fields,SX_COUNT(sxamip_omf_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_unknown_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
};
const sx_layout sxamip_omf_unknown={UINT32_C(0x60900010),"omf_unknown",sxamip_omf_unknown_fields,SX_COUNT(sxamip_omf_unknown_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_pattern_fields[]={
 SX_FIELD("zero","uint16",0,2,SX_NONE),
 SX_FIELD("channels","uint8",2,1,SX_COUNT_PROP),
};
const sx_layout sxamip_omf_pattern={UINT32_C(0x60900011),"omf_pattern",sxamip_omf_pattern_fields,SX_COUNT(sxamip_omf_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_sample_data_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_ID),
 SX_FIELD("sample_bytes","uint16",1,2,SX_SIZE),
};
const sx_layout sxamip_omf_sample_data={UINT32_C(0x60900013),"omf_sample_data",sxamip_omf_sample_data_fields,SX_COUNT(sxamip_omf_sample_data_fields),SX_LE};
#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
#define AP_TAKE(l,p,n,end) sxamip_take(v,&sxamip_##l,(p),(n),(end))
static bool sxamip_omf(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,channels,patterns,positions,p=1306,z;
 if(!sxamip_eq(v,0,"Onyx Music File\032\000\001",18,e)||!sxamip_span(v,0,p,e)||!sxamip_u(v,402,1,&channels,e)||!sxamip_u(v,403,1,&patterns,e)||!sxamip_u(v,404,1,&positions,e)||(positions&1))return false;
 channels++;patterns++;positions=positions/2+1;
 if(positions>128||!AP_ROW(omf_identity,0,e)||!sxamip_table(v,&sxamip_omf_position,18,128,e)||!AP_ROW(omf_header_tail,402,e)||!sxamip_table(v,&sxamip_omf_sample,436,31,e)||!AP_ROW(omf_unknown,1304,e))return false;
 for(uint64_t i=0;i<patterns;i++){
  uint64_t nc,zero;if(!sxamip_u(v,p,2,&zero,e)||zero||!sxamip_u(v,p+2,1,&nc,e)||nc!=channels||!AP_TAKE(omf_pattern,&p,1,e)||!AP_TAKE(omf_event,&p,64*channels,e))return false;
 }
 for(uint64_t i=0;i<31;i++){
  uint64_t declared;if(!sxamip_u(v,436+i*28+24,2,&declared,e))return false;
  if(declared){uint64_t mark;if(!sxamip_u(v,p,1,&mark,e)||mark||!sxamip_u(v,p+1,2,&z,e)||z!=declared||!AP_TAKE(omf_sample_data,&p,1,e)||!sxamip_skip(v,&p,z,e))return false;}
 }
 return true;
}
bool sx_altar_onyxmusicfile_build(sxamip_view*v)
{
 return sxamip_omf(v);
}
#undef AP_ROW
#undef AP_TAKE
