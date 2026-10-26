/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * shiru_beepola data structures, moved out of the musicprojects schema family. */
#include "../../../xx_format_schema_musicprojects.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmp_beepola_header_fields[]={
 SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("version","char[5]",7,5,SX_STRING),
};
const sx_layout sxmp_beepola_header={0x607b0035U,"beepola_header",sxmp_beepola_header_fields,SX_COUNT(sxmp_beepola_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_section_fields[]={
 SX_FIELD("section_name","utf8",0,0,SX_STRING),
};
const sx_layout sxmp_beepola_section={0x607b0036U,"beepola_section",sxmp_beepola_section_fields,SX_COUNT(sxmp_beepola_section_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_property_fields[]={
 SX_FIELD("property_name","utf8",0,0,SX_STRING),
};
const sx_layout sxmp_beepola_property={0x607b0037U,"beepola_property",sxmp_beepola_property_fields,SX_COUNT(sxmp_beepola_property_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_property_value_fields[]={
 SX_FIELD("property_value","utf8",0,0,SX_STRING),
};
const sx_layout sxmp_beepola_property_value={0x607b0038U,"beepola_property_value",sxmp_beepola_property_value_fields,SX_COUNT(sxmp_beepola_property_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_count_fields[]={
 SX_FIELD("count","ascii_decimal",0,0,SX_COUNT_PROP),
};
const sx_layout sxmp_beepola_count={0x607b0039U,"beepola_count",sxmp_beepola_count_fields,SX_COUNT(sxmp_beepola_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_loop_index_fields[]={
 SX_FIELD("loop_start","ascii_decimal",0,0,SX_NONE),
};
const sx_layout sxmp_beepola_loop_index={0x607b003aU,"beepola_loop_index",sxmp_beepola_loop_index_fields,SX_COUNT(sxmp_beepola_loop_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_order_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_order={0x607b003bU,"beepola_order",sxmp_beepola_order_fields,SX_COUNT(sxmp_beepola_order_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_pattern_header_fields[]={
 SX_FIELD("row_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("tempo","int32",4,4,SX_NONE),
};
const sx_layout sxmp_beepola_pattern_header={0x607b003cU,"beepola_pattern_header",sxmp_beepola_pattern_header_fields,SX_COUNT(sxmp_beepola_pattern_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_phaser_instrument_fields[]={
 SX_FIELD("multiple","uint8",0,1,SX_NONE),
 SX_FIELD("detune","int32",1,4,SX_NONE),
 SX_FIELD("phase","uint8",5,1,SX_NONE),
};
const sx_layout sxmp_beepola_phaser_instrument={0x607b003dU,"beepola_phaser_instrument",sxmp_beepola_phaser_instrument_fields,SX_COUNT(sxmp_beepola_phaser_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_row_count_fields[]={
 SX_FIELD("row_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmp_beepola_row_count={0x607b0042U,"beepola_row_count",sxmp_beepola_row_count_fields,SX_COUNT(sxmp_beepola_row_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_note_fields[]={
 SX_FIELD("channel_one_note","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_channel_one_note={0x607b0043U,"beepola_channel_one_note",sxmp_beepola_channel_one_note_fields,SX_COUNT(sxmp_beepola_channel_one_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_note_fields[]={
 SX_FIELD("channel_two_note","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_channel_two_note={0x607b0044U,"beepola_channel_two_note",sxmp_beepola_channel_two_note_fields,SX_COUNT(sxmp_beepola_channel_two_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_drum_fields[]={
 SX_FIELD("drum","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_drum={0x607b0045U,"beepola_drum",sxmp_beepola_drum_fields,SX_COUNT(sxmp_beepola_drum_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_sustain_fields[]={
 SX_FIELD("channel_one_sustain","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_channel_one_sustain={0x607b0046U,"beepola_channel_one_sustain",sxmp_beepola_channel_one_sustain_fields,SX_COUNT(sxmp_beepola_channel_one_sustain_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_sustain_fields[]={
 SX_FIELD("channel_two_sustain","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_channel_two_sustain={0x607b0047U,"beepola_channel_two_sustain",sxmp_beepola_channel_two_sustain_fields,SX_COUNT(sxmp_beepola_channel_two_sustain_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_warp_fields[]={
 SX_FIELD("channel_one_warp","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_channel_one_warp={0x607b0048U,"beepola_channel_one_warp",sxmp_beepola_channel_one_warp_fields,SX_COUNT(sxmp_beepola_channel_one_warp_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_warp_fields[]={
 SX_FIELD("channel_two_warp","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_channel_two_warp={0x607b0049U,"beepola_channel_two_warp",sxmp_beepola_channel_two_warp_fields,SX_COUNT(sxmp_beepola_channel_two_warp_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_ornament_value_fields[]={
 SX_FIELD("ornament_value","uint8",0,1,SX_NONE),
};
const sx_layout sxmp_beepola_ornament_value={0x607b004aU,"beepola_ornament_value",sxmp_beepola_ornament_value_fields,SX_COUNT(sxmp_beepola_ornament_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_glissando_fields[]={
 SX_FIELD("channel_one_glissando","uint16",0,2,SX_NONE),
};
const sx_layout sxmp_beepola_channel_one_glissando={0x607b004bU,"beepola_channel_one_glissando",sxmp_beepola_channel_one_glissando_fields,SX_COUNT(sxmp_beepola_channel_one_glissando_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_glissando_fields[]={
 SX_FIELD("channel_two_glissando","uint16",0,2,SX_NONE),
};
const sx_layout sxmp_beepola_channel_two_glissando={0x607b004cU,"beepola_channel_two_glissando",sxmp_beepola_channel_two_glissando_fields,SX_COUNT(sxmp_beepola_channel_two_glissando_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_skew_fields[]={
 SX_FIELD("channel_one_skew","uint16",0,2,SX_NONE),
};
const sx_layout sxmp_beepola_channel_one_skew={0x607b004dU,"beepola_channel_one_skew",sxmp_beepola_channel_one_skew_fields,SX_COUNT(sxmp_beepola_channel_one_skew_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_skew_fields[]={
 SX_FIELD("channel_two_skew","uint16",0,2,SX_NONE),
};
const sx_layout sxmp_beepola_channel_two_skew={0x607b004eU,"beepola_channel_two_skew",sxmp_beepola_channel_two_skew_fields,SX_COUNT(sxmp_beepola_channel_two_skew_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_skew_xor_fields[]={
 SX_FIELD("channel_one_skew_xor","uint16",0,2,SX_NONE),
};
const sx_layout sxmp_beepola_channel_one_skew_xor={0x607b004fU,"beepola_channel_one_skew_xor",sxmp_beepola_channel_one_skew_xor_fields,SX_COUNT(sxmp_beepola_channel_one_skew_xor_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_skew_xor_fields[]={
 SX_FIELD("channel_two_skew_xor","uint16",0,2,SX_NONE),
};
const sx_layout sxmp_beepola_channel_two_skew_xor={0x607b0050U,"beepola_channel_two_skew_xor",sxmp_beepola_channel_two_skew_xor_fields,SX_COUNT(sxmp_beepola_channel_two_skew_xor_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_arpeggio_fields[]={
 SX_FIELD("channel_one_arpeggio","uint16",0,2,SX_NONE),
};
const sx_layout sxmp_beepola_channel_one_arpeggio={0x607b0051U,"beepola_channel_one_arpeggio",sxmp_beepola_channel_one_arpeggio_fields,SX_COUNT(sxmp_beepola_channel_one_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_arpeggio_fields[]={
 SX_FIELD("channel_two_arpeggio","uint16",0,2,SX_NONE),
};
const sx_layout sxmp_beepola_channel_two_arpeggio={0x607b0052U,"beepola_channel_two_arpeggio",sxmp_beepola_channel_two_arpeggio_fields,SX_COUNT(sxmp_beepola_channel_two_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_ornament_length_fields[]={
 SX_FIELD("length","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmp_beepola_ornament_length={0x607b0053U,"beepola_ornament_length",sxmp_beepola_ornament_length_fields,SX_COUNT(sxmp_beepola_ornament_length_fields),SX_LE};
#define MP_ROW(name,at,end) sxmp_row(v,&sxmp_##name,(at),(end))
static bool sxmp_beep_token(sxmp_view*v,uint64_t*p,uint64_t end,uint64_t*a,uint64_t*z)
{*a=*p;uint64_t b;while(*p<end&&*p-*a<1048576){if(!sxmp_u(v,*p,1,&b,end))return false;(*p)++;if(!b){*z=*p-*a-1;return true;}}return false;}
static bool sxmp_beep_prop(sxmp_view*v,uint64_t*p,uint64_t end,const char*key,const sx_layout*value,uint64_t*number)
{uint64_t a,z,k=xx_rt_strlen(key),at,c,n=0;if(!sxmp_beep_token(v,p,end,&a,&z)||z<=k||!sxmp_eq(v,a,key,(size_t)k,end)||!sxmp_u(v,a+k,1,&c,end)||c!='=')return false;at=a+k+1;if(!sxmp_emit(v,&sxmp_beepola_property,a,k,end)||!sxmp_emit(v,value,at,z-k-1,end))return false;
 if(number){if(z-k-1<1||z-k-1>10)return false;for(uint64_t i=at;i<a+z;i++){if(!sxmp_u(v,i,1,&c,end)||c<'0'||c>'9'||n>(UINT32_MAX-(c-'0'))/10)return false;n=n*10+c-'0';}*number=n;}return true;}
static bool sxmp_beepola(sxmp_view*v)
{uint64_t e=v->c->size,p=12,a,z;if(!MP_ROW(beepola_header,0,e)||!sxmp_eq(v,7,"0001\0",5,e))return false;
 while(p<e&&v->c->count<24000){if(!sxmp_beep_token(v,&p,e,&a,&z)||!sxmp_emit(v,&sxmp_beepola_section,a,z,e))return false;
  if(z==4&&sxmp_eq(v,a,":END",4,e))continue;
  if(z==5&&sxmp_eq(v,a,":INFO",5,e)){while(p<e){uint64_t b,n;if(!sxmp_beep_token(v,&p,e,&b,&n))return false;if(n==4&&sxmp_eq(v,b,":END",4,e)){if(!sxmp_emit(v,&sxmp_beepola_section,b,n,e))return false;break;}uint64_t k=0,c;while(k<n){if(!sxmp_u(v,b+k,1,&c,e))return false;if(c=='=')break;k++;}if(k==n)return false;if(!sxmp_emit(v,&sxmp_beepola_property,b,k,e)||!sxmp_emit(v,&sxmp_beepola_property_value,b+k+1,n-k-1,e))return false;}continue;}
  if(z==7&&sxmp_eq(v,a,":LAYOUT",7,e)){uint64_t loop,n;if(!sxmp_beep_prop(v,&p,e,"LoopStart",&sxmp_beepola_loop_index,&loop)||!sxmp_beep_prop(v,&p,e,"Length",&sxmp_beepola_count,&n)||n>256||loop>n||!sxmp_table(v,&sxmp_beepola_order,p,n,e))return false;p+=n;continue;}
  if(z==8&&sxmp_eq(v,a,":P1INSTR",8,e)){uint64_t n;if(!sxmp_beep_prop(v,&p,e,"Length",&sxmp_beepola_count,&n)||n>256||!sxmp_table(v,&sxmp_beepola_phaser_instrument,p,n,e))return false;p+=n*6;continue;}
  if(z==13&&sxmp_eq(v,a,":SVGORNAMENTS",13,e)){uint64_t n;if(!sxmp_beep_prop(v,&p,e,"OrnamentCount",&sxmp_beepola_count,&n)||n>256)return false;for(uint64_t i=0;i<n;i++){uint64_t rows;if(!MP_ROW(beepola_ornament_length,p,e)||!sxmp_u(v,p,4,&rows,e)||rows>256||!sxmp_table(v,&sxmp_beepola_ornament_value,p+4,rows,e))return false;p+=4+rows;}continue;}
  unsigned mode=z==12&&sxmp_eq(v,a,":PATTERNDATA",12,e)?1:z==15&&sxmp_eq(v,a,":SVGPATTERNDATA",15,e)?2:z==12&&sxmp_eq(v,a,":SVGWARPDATA",12,e)?3:0;
  if(!mode)return true;/* Unknown sections have no known length: preserve tail. */
  uint64_t count;if(!sxmp_beep_prop(v,&p,e,"PatternCount",&sxmp_beepola_count,&count)||count>256)return false;
  const sx_layout*plain[]={&sxmp_beepola_channel_one_note,&sxmp_beepola_channel_two_note,&sxmp_beepola_drum,&sxmp_beepola_channel_one_sustain,&sxmp_beepola_channel_two_sustain};
  const sx_layout*svg[]={&sxmp_beepola_channel_one_glissando,&sxmp_beepola_channel_two_glissando,&sxmp_beepola_channel_one_skew,&sxmp_beepola_channel_two_skew,&sxmp_beepola_channel_one_skew_xor,&sxmp_beepola_channel_two_skew_xor,&sxmp_beepola_channel_one_arpeggio,&sxmp_beepola_channel_two_arpeggio};
  const sx_layout*warp[]={&sxmp_beepola_channel_one_warp,&sxmp_beepola_channel_two_warp};
  for(uint64_t i=0;i<count;i++){uint64_t rows;if(mode==1&&!sxmp_beep_prop(v,&p,e,"PatternName",&sxmp_music_project_name,NULL))return false;if(!sxmp_u(v,p,4,&rows,e)||rows>256||!sxmp_row(v,mode==1?&sxmp_beepola_pattern_header:&sxmp_beepola_row_count,p,e))return false;p+=mode==1?8:4;unsigned cols=mode==1?5:mode==2?8:2,width=mode==2?2:1;const sx_layout**fields=mode==1?plain:mode==2?svg:warp;for(unsigned j=0;j<cols;j++){if(!sxmp_table(v,fields[j],p,rows,e))return false;p+=rows*width;}}
 }return true;}
bool sx_shiru_beepola_build(sxmp_view*v)
{
 return sxmp_beepola(v);
}
#undef MP_ROW
