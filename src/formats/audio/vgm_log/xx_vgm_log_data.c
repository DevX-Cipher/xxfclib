/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * vgm_log data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_vgm_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("eof_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("sn76489_clock","uint32",12,4,SX_NONE),
 SX_FIELD("ym2413_clock","uint32",16,4,SX_NONE),
 SX_FIELD("gd3_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("total_samples","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("loop_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("loop_samples","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("rate","uint32",36,4,SX_NONE),
 SX_FIELD("sn76489_feedback","uint16",40,2,SX_FLAGS),
 SX_FIELD("sn76489_shift_width","uint8",42,1,SX_NONE),
 SX_FIELD("sn76489_flags","uint8",43,1,SX_FLAGS),
 SX_FIELD("ym2612_clock","uint32",44,4,SX_NONE),
 SX_FIELD("ym2151_clock","uint32",48,4,SX_NONE),
 SX_FIELD("data_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("sega_pcm_clock","uint32",56,4,SX_NONE),
 SX_FIELD("sega_pcm_interface","uint32",60,4,SX_FLAGS),
};
const sx_layout sxau_vgm_header={UINT32_C(0x602C001F),"vgm_header",sxau_vgm_header_fields,SX_COUNT(sxau_vgm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_gd3_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("text_bytes","uint32",8,4,SX_SIZE),
};
const sx_layout sxau_vgm_gd3={UINT32_C(0x602C0020),"vgm_gd3",sxau_vgm_gd3_fields,SX_COUNT(sxau_vgm_gd3_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_command_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
};
const sx_layout sxau_vgm_command={UINT32_C(0x602C0021),"vgm_command",sxau_vgm_command_fields,SX_COUNT(sxau_vgm_command_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_register8_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("value","uint8",1,1,SX_FLAGS),
};
const sx_layout sxau_vgm_register8={UINT32_C(0x602C0022),"vgm_register8",sxau_vgm_register8_fields,SX_COUNT(sxau_vgm_register8_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_register16_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("register","uint8",1,1,SX_ID),
 SX_FIELD("value","uint8",2,1,SX_FLAGS),
};
const sx_layout sxau_vgm_register16={UINT32_C(0x602C0023),"vgm_register16",sxau_vgm_register16_fields,SX_COUNT(sxau_vgm_register16_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_wait_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("wait_samples","uint16",1,2,SX_COUNT_PROP),
};
const sx_layout sxau_vgm_wait={UINT32_C(0x602C0024),"vgm_wait",sxau_vgm_wait_fields,SX_COUNT(sxau_vgm_wait_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_data_block_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("compatibility","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("block_type","uint8",2,1,SX_ID),
 SX_FIELD("data_bytes","uint32",3,4,SX_SIZE),
};
const sx_layout sxau_vgm_data_block={UINT32_C(0x602C0025),"vgm_data_block",sxau_vgm_data_block_fields,SX_COUNT(sxau_vgm_data_block_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_pcm_seek_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("pcm_bank_offset","uint32",1,4,SX_OFFSET),
};
const sx_layout sxau_vgm_pcm_seek={UINT32_C(0x602C0026),"vgm_pcm_seek",sxau_vgm_pcm_seek_fields,SX_COUNT(sxau_vgm_pcm_seek_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_setup_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("chip_type","uint8",2,1,SX_ID),
 SX_FIELD("port","uint8",3,1,SX_ID),
 SX_FIELD("command","uint8",4,1,SX_ID),
};
const sx_layout sxau_vgm_dac_setup={UINT32_C(0x602C0027),"vgm_dac_setup",sxau_vgm_dac_setup_fields,SX_COUNT(sxau_vgm_dac_setup_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_data_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("data_bank","uint8",2,1,SX_ID),
 SX_FIELD("step_size","uint8",3,1,SX_SIZE),
 SX_FIELD("step_base","uint8",4,1,SX_OFFSET),
};
const sx_layout sxau_vgm_dac_data={UINT32_C(0x602C0028),"vgm_dac_data",sxau_vgm_dac_data_fields,SX_COUNT(sxau_vgm_dac_data_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_frequency_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("frequency","uint32",2,4,SX_NONE),
};
const sx_layout sxau_vgm_dac_frequency={UINT32_C(0x602C0029),"vgm_dac_frequency",sxau_vgm_dac_frequency_fields,SX_COUNT(sxau_vgm_dac_frequency_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_start_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("data_start_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("length_mode","uint8",6,1,SX_FLAGS),
 SX_FIELD("data_length","uint32",7,4,SX_NONE),
};
const sx_layout sxau_vgm_dac_start={UINT32_C(0x602C002A),"vgm_dac_start",sxau_vgm_dac_start_fields,SX_COUNT(sxau_vgm_dac_start_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_stop_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
};
const sx_layout sxau_vgm_dac_stop={UINT32_C(0x602C002B),"vgm_dac_stop",sxau_vgm_dac_stop_fields,SX_COUNT(sxau_vgm_dac_stop_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_fast_start_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("block_id","uint16",2,2,SX_ID),
 SX_FIELD("flags","uint8",4,1,SX_FLAGS),
};
const sx_layout sxau_vgm_dac_fast_start={UINT32_C(0x602C002C),"vgm_dac_fast_start",sxau_vgm_dac_fast_start_fields,SX_COUNT(sxau_vgm_dac_fast_start_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_vgm(sxau_view*v)
{if(!SA_ROW(vgm_header,0,v->n))return false;uint32_t ver=sxau_u32(v->p+8,false),rel=sxau_u32(v->p+52,false);size_t at=ver>=0x150&&rel?52+(size_t)rel:64;size_t gd3=sxau_u32(v->p+20,false);if(gd3){gd3+=20;if(!SA_ROW(vgm_gd3,gd3,v->n)||!sxau_need(v,gd3+12,sxau_u32(v->p+gd3+8,false),v->n))return false;}size_t end=gd3?gd3:v->n;
 if(at<64||at>=end)return false;while(at<end){unsigned op=v->p[at];const sx_layout*l=&sxau_vgm_command;size_t z=1;
  if(op==0x4f||op==0x50){l=&sxau_vgm_register8;z=2;}else if(op>=0x51&&op<=0x5f){l=&sxau_vgm_register16;z=3;}else if(op==0x61){l=&sxau_vgm_wait;z=3;}else if(op==0x67){l=&sxau_vgm_data_block;z=7;}else if(op==0xe0){l=&sxau_vgm_pcm_seek;z=5;}else if(op>=0x90&&op<=0x95){static const sx_layout*const a[]={&sxau_vgm_dac_setup,&sxau_vgm_dac_data,&sxau_vgm_dac_frequency,&sxau_vgm_dac_start,&sxau_vgm_dac_stop,&sxau_vgm_dac_fast_start};static const uint8_t lens[]={5,5,6,11,2,5};l=a[op-0x90];z=lens[op-0x90];}else if(!(op==0x62||op==0x63||op==0x66||(op>=0x70&&op<=0x8f)))return false;
  if(!sxau_row(v,l,at,end))return false;if(op==0x67){uint32_t bytes=sxau_u32(v->p+at+3,false);if(!sxau_need(v,at+7,bytes,end))return false;z+=bytes;}at+=z;if(op==0x66)return at==end;
 }return false;}
bool sx_vgm_log_build(sxau_view*v)
{
 return sxau_vgm(v);
}
#undef SA_ROW
