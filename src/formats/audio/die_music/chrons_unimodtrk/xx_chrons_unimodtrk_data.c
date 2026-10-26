/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Otto Chrons/libmikmod UNIMOD/UNITRK module (.UNI) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_text_length16_fields[]={
 SX_FIELD("text_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxmta_text_length16={UINT32_C(0x60810003),"text_length16",sxmta_text_length16_fields,SX_COUNT(sxmta_text_length16_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_uni4_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("channels","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",5,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",7,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",9,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",11,2,SX_COUNT_PROP),
 SX_FIELD("speed","uint8",13,1,SX_NONE),
 SX_FIELD("tempo","uint8",14,1,SX_NONE),
 SX_FIELD("orders_fixed","bytes",15,256,SX_NONE),
 SX_FIELD("pan_fixed","bytes",271,32,SX_NONE),
 SX_FIELD("flags","uint8",303,1,SX_FLAGS),
};
const sx_layout sxmta_uni4_header={UINT32_C(0x60810080),"uni4_header",sxmta_uni4_header_fields,SX_COUNT(sxmta_uni4_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_uni5_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("channels","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",5,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",7,2,SX_NONE),
 SX_FIELD("patterns","uint16",9,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",11,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",13,2,SX_COUNT_PROP),
 SX_FIELD("speed","uint8",15,1,SX_NONE),
 SX_FIELD("tempo","uint8",16,1,SX_NONE),
 SX_FIELD("orders_fixed","bytes",17,256,SX_NONE),
 SX_FIELD("pan_fixed","bytes",273,32,SX_NONE),
 SX_FIELD("flags","uint8",305,1,SX_FLAGS),
};
const sx_layout sxmta_uni5_header={UINT32_C(0x60810081),"uni5_header",sxmta_uni5_header_fields,SX_COUNT(sxmta_uni5_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_uni6_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("unused","uint8",4,1,SX_NONE),
 SX_FIELD("flags","uint16",5,2,SX_FLAGS),
 SX_FIELD("channels","uint8",7,1,SX_COUNT_PROP),
 SX_FIELD("voices","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",9,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",11,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",13,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",15,2,SX_COUNT_PROP),
 SX_FIELD("samples","uint16",17,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",19,2,SX_NONE),
 SX_FIELD("speed","uint8",21,1,SX_NONE),
 SX_FIELD("tempo","uint8",22,1,SX_NONE),
 SX_FIELD("volume","uint8",23,1,SX_NONE),
};
const sx_layout sxmta_uni6_header={UINT32_C(0x60810082),"uni6_header",sxmta_uni6_header_fields,SX_COUNT(sxmta_uni6_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_apun_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("channels","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("voices","uint8",9,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("samples","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",20,2,SX_NONE),
 SX_FIELD("speed","uint8",22,1,SX_NONE),
 SX_FIELD("tempo","uint8",23,1,SX_NONE),
 SX_FIELD("volume","uint8",24,1,SX_NONE),
};
const sx_layout sxmta_apun_header={UINT32_C(0x60810083),"apun_header",sxmta_apun_header_fields,SX_COUNT(sxmta_apun_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_uni_bpm_limit_fields[]={
 SX_FIELD("bpm_limit","uint16",0,2,SX_NONE),
};
const sx_layout sxmta_uni_bpm_limit={UINT32_C(0x60810084),"uni_bpm_limit",sxmta_uni_bpm_limit_fields,SX_COUNT(sxmta_uni_bpm_limit_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_uni_sample_fields[]={
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("sample_rate","uint32",2,4,SX_NONE),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("pan","uint16",7,2,SX_NONE),
 SX_FIELD("sample_frames","uint32",9,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_frame","uint32",13,4,SX_NONE),
 SX_FIELD("loop_end_frame","uint32",17,4,SX_NONE),
 SX_FIELD("sustain_start_frame","uint32",21,4,SX_NONE),
 SX_FIELD("sustain_end_frame","uint32",25,4,SX_NONE),
 SX_FIELD("global_volume","uint8",29,1,SX_NONE),
 SX_FIELD("vibrato_flags","uint8",30,1,SX_FLAGS),
 SX_FIELD("vibrato_type","uint8",31,1,SX_ID),
 SX_FIELD("vibrato_sweep","uint8",32,1,SX_NONE),
 SX_FIELD("vibrato_depth","uint8",33,1,SX_NONE),
 SX_FIELD("vibrato_rate","uint8",34,1,SX_NONE),
};
const sx_layout sxmta_uni_sample={UINT32_C(0x60810085),"uni_sample",sxmta_uni_sample_fields,SX_COUNT(sxmta_uni_sample_fields),SX_BE};
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_uni_string(sxmta_view*v,uint64_t*p,uint64_t end)
{uint64_t n;if(!sxmta_u(v,*p,2,&n,end)||!MTA_TAKE(text_length16,p,1,end)||!sxmta_text_emit(v,*p,n,end))return false;*p+=n;return true;}
static bool sxmta_uni(sxmta_view*v)
{uint64_t end=v->c->size,p=0,ver,ch,orders,ns=0;
 if(sxmta_eq(v,0,"APUN",4,end)){if(!sxmta_be(v,4,2,&ver,end)||ver<0x101||ver>0x106||!sxmta_u(v,8,1,&ch,end)||!sxmta_be(v,10,2,&orders,end)||!sxmta_be(v,18,2,&ns,end)||!MTA_TAKE(apun_header,&p,1,end))return false;if(ver>=0x106&&!MTA_TAKE(uni_bpm_limit,&p,1,end))return false;}
 else{if(!sxmta_eq(v,0,"UN0",3,end)||!sxmta_u(v,3,1,&ver,end)||ver<'4'||ver>'6')return false;ver-='0';if(ver==6){if(!sxmta_u(v,7,1,&ch,end)||!sxmta_be(v,9,2,&orders,end)||!sxmta_be(v,17,2,&ns,end)||!MTA_TAKE(uni6_header,&p,1,end))return false;}else if(!sxmta_take(v,ver==4?&sxmta_uni4_header:&sxmta_uni5_header,&p,1,end))return false;}
 if(!sxmta_uni_string(v,&p,end)||(ver<0x102&&!sxmta_uni_string(v,&p,end))||!sxmta_uni_string(v,&p,end))return false;
 if(ver>=6){if(ch>64||!sxmta_take(v,ver>=0x100?&sxmta_order16be:&sxmta_order8,&p,orders,end)||!MTA_TAKE(pan16be,&p,ch,end)||!MTA_TAKE(volume8,&p,ch,end))return false;for(uint64_t i=0;i<ns;i++)if(!MTA_TAKE(uni_sample,&p,1,end)||!sxmta_uni_string(v,&p,end))return false;}
 /* Instrument envelopes, bytecode tracks and PCM bodies are not decoded here. */
 return true;}
bool sx_chrons_unimodtrk_build(sxmta_view*v)
{
 return sxmta_uni(v);
}
#undef MTA_TAKE
