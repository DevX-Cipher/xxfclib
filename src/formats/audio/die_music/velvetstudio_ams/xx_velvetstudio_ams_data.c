/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Velvet Studio Advanced Module System track (.AMS) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_ams2_magic_fields[]={
 SX_FIELD("magic","bytes",0,7,SX_SIGNATURE),
 SX_FIELD("title_bytes","uint8",7,1,SX_SIZE),
};
const sx_layout sxmr_ams2_magic={UINT32_C(0x607D0001),"ams2_magic",sxmr_ams2_magic_fields,SX_COUNT(sxmr_ams2_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_header_fields[]={
 SX_FIELD("minor","uint8",0,1,SX_ID),
 SX_FIELD("major","uint8",1,1,SX_ID),
 SX_FIELD("instruments","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",3,2,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",5,2,SX_COUNT_PROP),
};
const sx_layout sxmr_ams2_header={UINT32_C(0x607D0002),"ams2_header",sxmr_ams2_header_fields,SX_COUNT(sxmr_ams2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_timing20_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("speed","uint8",1,1,SX_NONE),
 SX_FIELD("flags","uint8",2,1,SX_FLAGS),
};
const sx_layout sxmr_ams2_timing20={UINT32_C(0x607D0003),"ams2_timing20",sxmr_ams2_timing20_fields,SX_COUNT(sxmr_ams2_timing20_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_pascal_text_length_fields[]={
 SX_FIELD("text_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxmr_pascal_text_length={UINT32_C(0x607D0005),"pascal_text_length",sxmr_pascal_text_length_fields,SX_COUNT(sxmr_pascal_text_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_sample_count_fields[]={
 SX_FIELD("samples","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxmr_ams2_sample_count={UINT32_C(0x607D0008),"ams2_sample_count",sxmr_ams2_sample_count_fields,SX_COUNT(sxmr_ams2_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_note_sample_fields[]={
 SX_FIELD("sample_index","uint8",0,1,SX_ID),
};
const sx_layout sxmr_ams2_note_sample={UINT32_C(0x607D0009),"ams2_note_sample",sxmr_ams2_note_sample_fields,SX_COUNT(sxmr_ams2_note_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_envelope_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("sustain_point","uint8",1,1,SX_NONE),
 SX_FIELD("loop_start_point","uint8",2,1,SX_NONE),
 SX_FIELD("loop_end_point","uint8",3,1,SX_NONE),
 SX_FIELD("points","uint8",4,1,SX_COUNT_PROP),
};
const sx_layout sxmr_ams2_envelope={UINT32_C(0x607D000A),"ams2_envelope",sxmr_ams2_envelope_fields,SX_COUNT(sxmr_ams2_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_instrument_fields[]={
 SX_FIELD("shadow_instrument","uint8",0,1,SX_ID),
 SX_FIELD("vibrato_fadeout","uint16",1,2,SX_FLAGS),
 SX_FIELD("envelope_flags","uint16",3,2,SX_FLAGS),
};
const sx_layout sxmr_ams2_instrument={UINT32_C(0x607D000C),"ams2_instrument",sxmr_ams2_instrument_fields,SX_COUNT(sxmr_ams2_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_order16_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
};
const sx_layout sxmr_order16={UINT32_C(0x607D000F),"order16",sxmr_order16_fields,SX_COUNT(sxmr_order16_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_pattern_fields[]={
 SX_FIELD("packed_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("rows_minus_one","uint8",4,1,SX_NONE),
 SX_FIELD("channels_commands","uint8",5,1,SX_FLAGS),
};
const sx_layout sxmr_ams2_pattern={UINT32_C(0x607D0010),"ams2_pattern",sxmr_ams2_pattern_fields,SX_COUNT(sxmr_ams2_pattern_fields),SX_LE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_pascal(sxmr_view*v,uint64_t*p,uint64_t end){uint64_t n;if(!sxmr_u(v,*p,1,&n,end)||!MR_ROW(pascal_text_length,*p,end))return false;(*p)++;if(!sxmr_text_emit(v,*p,n,end))return false;*p+=n;return true;}
static bool sxmr_ams(sxmr_view*v)
{uint64_t end=v->c->size,p=8,n,minor,major,ins,pats,ords,x,samples;
 if(!sxmr_eq(v,0,"AMShdr\x1a",7,end)||!sxmr_u(v,7,1,&n,end)||n>30||!MR_ROW(ams2_magic,0,end)||!sxmr_text_emit(v,p,n,end))return false;p+=n;
 if(!sxmr_u(v,p,1,&minor,end)||!sxmr_u(v,p+1,1,&major,end)||major!=2||minor>2||!sxmr_u(v,p+2,1,&ins,end)||!sxmr_u(v,p+3,2,&pats,end)||!sxmr_u(v,p+5,2,&ords,end)||!MR_ROW(ams2_header,p,end))return false;p+=7;
 if(minor==2){if(!MR_ROW(ams2_timing22,p,end))return false;p+=8;}else{if(!MR_ROW(ams2_timing20,p,end))return false;p+=3;}
 for(uint64_t i=0;i<ins;i++){if(!sxmr_pascal(v,&p,end)||!sxmr_u(v,p,1,&samples,end)||!MR_ROW(ams2_sample_count,p,end))return false;p++;if(!samples)continue;
  n=minor?120:96;if(!sxmr_table(v,&sxmr_ams2_note_sample,p,n,end))return false;p+=n;
  for(unsigned j=0;j<3;j++){if(!sxmr_u(v,p+4,1,&n,end)||!MR_ROW(ams2_envelope,p,end))return false;p+=5;if(!sxmr_table(v,&sxmr_ams2_envelope_point,p,n,end))return false;p+=n*3;}
  if(!MR_ROW(ams2_instrument,p,end))return false;p+=5;
  for(uint64_t j=0;j<samples;j++){if(!sxmr_pascal(v,&p,end)||!MR_ROW(ams2_sample,p,end))return false;p+=20;}
 }
 for(unsigned j=0;j<33;j++)if(!sxmr_pascal(v,&p,end))return false;
 if(!sxmr_u(v,p,4,&n,end)||n<11||!sxmr_span(v,p,n,end)||!MR_ROW(ams2_description,p,end))return false;p+=n;
 if(!sxmr_table(v,&sxmr_order16,p,ords,end))return false;p+=2*ords;
 for(uint64_t i=0;i<pats;i++){if(!sxmr_u(v,p,4,&n,end)||n<3||!sxmr_span(v,p+4,n,end)||!MR_ROW(ams2_pattern,p,end))return false;x=p+4+n;p+=6;if(!sxmr_pascal(v,&p,x))return false;p=x;}
 /* Packed and shadow sample bodies are deliberately left raw. */
 return true;}
bool sx_velvetstudio_ams_build(sxmr_view*v)
{
 return sxmr_ams(v);
}
#undef MR_ROW
