/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * emulatorii eii data structures, moved out of the samplebanks schema family. */
#include "../../xx_format_schema_samplebanks.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsb_emulator2_selected_name_fields[] = {
    SX_FIELD("selected_name","char[12]",0,12,SX_NONE),
};
const sx_layout sxsb_emulator2_selected_name = {0x603a0007U,"emulator2_selected_name",sxsb_emulator2_selected_name_fields,SX_COUNT(sxsb_emulator2_selected_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emulator2_keymaps_fields[] = {
    SX_FIELD("primary_voice_number","uint8[61]",0,61,SX_NONE),
    SX_FIELD("primary_voice_identifier","uint8[61]",61,61,SX_ID),
    SX_FIELD("primary_transpose","uint8[61]",122,61,SX_NONE),
    SX_FIELD("opaque_map_3","byte[61]",183,61,SX_NONE),
    SX_FIELD("opaque_map_4","byte[61]",244,61,SX_NONE),
    SX_FIELD("opaque_map_5","byte[61]",305,61,SX_NONE),
    SX_FIELD("opaque_map_6","byte[61]",366,61,SX_NONE),
    SX_FIELD("opaque_map_7","byte[61]",427,61,SX_NONE),
    SX_FIELD("opaque_map_8","byte[61]",488,61,SX_NONE),
    SX_FIELD("opaque_map_9","byte[61]",549,61,SX_NONE),
    SX_FIELD("opaque_map_10","byte[61]",610,61,SX_NONE),
};
const sx_layout sxsb_emulator2_keymaps = {0x603a0008U,"emulator2_keymaps",sxsb_emulator2_keymaps_fields,SX_COUNT(sxsb_emulator2_keymaps_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emulator2_preset_header_fields[] = {
    SX_FIELD("encoded_header","byte[8]",0,8,SX_NONE),
    SX_FIELD("header_flags","uint8",8,1,SX_FLAGS),
    SX_FIELD("name","char[12]",9,12,SX_NONE),
    SX_FIELD("opaque_parameters","byte[14]",21,14,SX_NONE),
};
const sx_layout sxsb_emulator2_preset_header = {0x603a0009U,"emulator2_preset_header",sxsb_emulator2_preset_header_fields,SX_COUNT(sxsb_emulator2_preset_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emulator2_selection_fields[] = {
    SX_FIELD("selected_preset","uint8",0,1,SX_NONE),
    SX_FIELD("voice_identifiers","uint8[100]",1,100,SX_ID),
};
const sx_layout sxsb_emulator2_selection = {0x603a000aU,"emulator2_selection",sxsb_emulator2_selection_fields,SX_COUNT(sxsb_emulator2_selection_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emulator2_preset_length_fields[] = {
    SX_FIELD("record_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxsb_emulator2_preset_length = {0x603a000bU,"emulator2_preset_length",sxsb_emulator2_preset_length_fields,SX_COUNT(sxsb_emulator2_preset_length_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emulator2_key_range_fields[] = {
    SX_FIELD("mode_and_key_count","uint8",0,1,SX_FLAGS),
    SX_FIELD("opaque_01","uint8",1,1,SX_NONE),
    SX_FIELD("voice_number","uint8",2,1,SX_NONE),
    SX_FIELD("transpose","uint8",3,1,SX_NONE),
    SX_FIELD("level_encoded","uint8",4,1,SX_NONE),
};
const sx_layout sxsb_emulator2_key_range = {0x603a000cU,"emulator2_key_range",sxsb_emulator2_key_range_fields,SX_COUNT(sxsb_emulator2_key_range_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emulator2_secondary_voice_fields[] = {
    SX_FIELD("voice_number","uint8",0,1,SX_NONE),
    SX_FIELD("transpose","uint8",1,1,SX_NONE),
    SX_FIELD("level_encoded","uint8",2,1,SX_NONE),
};
const sx_layout sxsb_emulator2_secondary_voice = {0x603a000dU,"emulator2_secondary_voice",sxsb_emulator2_secondary_voice_fields,SX_COUNT(sxsb_emulator2_secondary_voice_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emulator2_key_range_end_fields[] = {
    SX_FIELD("end_marker","byte[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxsb_emulator2_key_range_end = {0x603a000eU,"emulator2_key_range_end",sxsb_emulator2_key_range_end_fields,SX_COUNT(sxsb_emulator2_key_range_end_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_emulator2_voice_fields[] = {
    SX_FIELD("tag","byte[2]",0,2,SX_SIGNATURE),
    SX_FIELD("playback_start_minus_one","uint24",2,3,SX_ADDRESS),
    SX_FIELD("opaque_05","uint8",5,1,SX_NONE),
    SX_FIELD("preloop_negative_counter","uint24",6,3,SX_NONE),
    SX_FIELD("opaque_09","uint8",9,1,SX_NONE),
    SX_FIELD("loop_start_minus_one","uint24",10,3,SX_ADDRESS),
    SX_FIELD("opaque_0d","uint8",13,1,SX_NONE),
    SX_FIELD("loop_negative_counter","uint24",14,3,SX_NONE),
    SX_FIELD("opaque_11","byte[2]",17,2,SX_NONE),
    SX_FIELD("loop_negative_counter_copy","uint24",19,3,SX_NONE),
    SX_FIELD("opaque_16","byte[4]",22,4,SX_NONE),
    SX_FIELD("fine_tune","int8",26,1,SX_NONE),
    SX_FIELD("velocity_attack","uint8",27,1,SX_FLAGS),
    SX_FIELD("lfo_delay_encoded","uint8",28,1,SX_NONE),
    SX_FIELD("lfo_rate_encoded","uint8",29,1,SX_NONE),
    SX_FIELD("opaque_1e","uint8",30,1,SX_NONE),
    SX_FIELD("filter_keyboard_tracking","uint8",31,1,SX_FLAGS),
    SX_FIELD("opaque_20","byte[2]",32,2,SX_NONE),
    SX_FIELD("self_pointer_22","uint16",34,2,SX_ADDRESS),
    SX_FIELD("opaque_24","uint8",36,1,SX_NONE),
    SX_FIELD("filter_envelope_amount_encoded","uint8",37,1,SX_NONE),
    SX_FIELD("self_pointer_26","uint16",38,2,SX_ADDRESS),
    SX_FIELD("lfo_pitch_table_address","uint16",40,2,SX_ADDRESS),
    SX_FIELD("lfo_filter_table_address","uint16",42,2,SX_ADDRESS),
    SX_FIELD("lfo_level_table_address","uint16",44,2,SX_ADDRESS),
    SX_FIELD("filter_sustain_encoded","uint8",46,1,SX_NONE),
    SX_FIELD("filter_flags","uint8",47,1,SX_FLAGS),
    SX_FIELD("cutoff_velocity_table","uint8[16]",48,16,SX_NONE),
    SX_FIELD("level_velocity_table","uint8[16]",64,16,SX_NONE),
    SX_FIELD("filter_attack_passes","uint8[16]",80,16,SX_NONE),
    SX_FIELD("filter_attack_increment","uint8[16]",96,16,SX_NONE),
    SX_FIELD("amplitude_attack_passes","uint8[16]",112,16,SX_NONE),
    SX_FIELD("amplitude_attack_increment","uint8[16]",128,16,SX_NONE),
    SX_FIELD("filter_decay_passes","uint8",144,1,SX_NONE),
    SX_FIELD("opaque_91","uint8",145,1,SX_NONE),
    SX_FIELD("filter_decay_negative_increment","uint8",146,1,SX_NONE),
    SX_FIELD("filter_envelope_amount_copy","uint8",147,1,SX_NONE),
    SX_FIELD("opaque_94","byte[10]",148,10,SX_NONE),
    SX_FIELD("filter_release_passes","uint8",158,1,SX_NONE),
    SX_FIELD("opaque_9f","uint8",159,1,SX_NONE),
    SX_FIELD("filter_release_negative_increment","uint8",160,1,SX_NONE),
    SX_FIELD("opaque_a1","byte[4]",161,4,SX_NONE),
    SX_FIELD("amplitude_decay_passes","uint8",165,1,SX_NONE),
    SX_FIELD("opaque_a6","uint8",166,1,SX_NONE),
    SX_FIELD("amplitude_decay_negative_increment","uint8",167,1,SX_NONE),
    SX_FIELD("opaque_a8","uint8",168,1,SX_NONE),
    SX_FIELD("amplitude_sustain_encoded","uint8",169,1,SX_NONE),
    SX_FIELD("opaque_aa","byte[9]",170,9,SX_NONE),
    SX_FIELD("amplitude_release_passes","uint8",179,1,SX_NONE),
    SX_FIELD("opaque_b4","uint8",180,1,SX_NONE),
    SX_FIELD("amplitude_release_negative_increment","uint8",181,1,SX_NONE),
    SX_FIELD("opaque_b6","byte[4]",182,4,SX_NONE),
    SX_FIELD("name","char[12]",186,12,SX_NONE),
    SX_FIELD("flags","uint8",198,1,SX_FLAGS),
    SX_FIELD("region_offset","uint24",199,3,SX_OFFSET),
    SX_FIELD("slot_frames","uint24",202,3,SX_COUNT_PROP),
    SX_FIELD("loop_offset","uint24",205,3,SX_OFFSET),
    SX_FIELD("loop_frames","uint24",208,3,SX_COUNT_PROP),
    SX_FIELD("playback_offset","uint24",211,3,SX_OFFSET),
    SX_FIELD("playback_frames_with_padding","uint24",214,3,SX_COUNT_PROP),
    SX_FIELD("opaque_d9","byte[23]",217,23,SX_NONE),
    SX_FIELD("q_velocity_table","uint8[16]",240,16,SX_NONE),
};
const sx_layout sxsb_emulator2_voice = {0x603a000fU,"emulator2_voice",sxsb_emulator2_voice_fields,SX_COUNT(sxsb_emulator2_voice_fields),SX_LE};
#define SXSB_ADD(c,l,p) sxsb_put(c,&sxsb_##l,p,1)
/* Validate a complete optional preset before committing any part of it. */
static bool sxsb_eii_preset(sx_context*c,uint64_t p,uint16_t n,uint64_t limit,bool emit){
 uint8_t b[35],r[8];if(n<41||p>limit||n>limit-p||!sxsb_read(c,p,b,35)||!(b[8]&128))return false;
 for(unsigned i=0;i<8;i++)if(b[i]>15)return false;
 uint64_t q=p+35,end=p+n-2;unsigned keys=0;
 while(q<end){
  if(end-q<4||!sxsb_read(c,q,r,4))return false;
  unsigned mode=r[0]>>6,count=r[0]&63;
  if(!mode){if(end-q!=4||r[0]||r[1]!=61||r[2]||r[3])return false;return !emit||(SXSB_ADD(c,emulator2_key_range_end,q)&&SXSB_ADD(c,emulator2_preset_length,end));}
  unsigned width=mode==3?8:5;if(!count||keys+count>61||end-q<width||!sxsb_read(c,q,r,width))return false;
  if(r[2]>100||(mode==3&&r[5]>100))return false;
  if(emit&&(!SXSB_ADD(c,emulator2_key_range,q)||(mode==3&&!SXSB_ADD(c,emulator2_secondary_voice,q+5))))return false;
  keys+=count;q+=width;
 }
 return false;
}
static bool sxsb_eii(sx_context*c){
 if(c->size!=487424||!SXSB_ADD(c,emulator2_selected_name,0)||!SXSB_ADD(c,emulator2_keymaps,12)||!SXSB_ADD(c,emulator2_preset_header,0x2ab)||!SXSB_ADD(c,emulator2_selection,0x2ce))return false;
 uint64_t p=0x500,limit=0x76a00;unsigned voices=0,presets=0;uint8_t b[256];
 while(p<limit){
  if(limit-p<2||!sxsb_read(c,p,b,2))break;
  if(b[0]==4&&b[1]==3){
   if(voices>=100||limit-p<256||!sxsb_read(c,p,b,256))break;
   /* The two independent self-pointer pages authenticate an aligned voice slot.
    * No arbitrary scan through sample bytes is performed. */
   unsigned page=(unsigned)((p+0x9600)>>8);uint64_t data=sxsb24(b+199),frames=sxsb24(b+202);
   if(page>255||b[35]!=page||b[39]!=page||data<p+256||data>0x76a00||frames>0x76a00-data)break;
   if(!SXSB_ADD(c,emulator2_voice,p))return false;
   if(data<limit)limit=data;
   voices++;p+=256;continue;
  }
  uint16_t n=(uint16_t)sxsb16(b);uint64_t q=p+2;
  if(presets>=100||!sxsb_eii_preset(c,q,n,limit,false))break;
  if(!SXSB_ADD(c,emulator2_preset_length,p))return false;
  while(presets<100&&sxsb_eii_preset(c,q,n,limit,false)){
   if(!SXSB_ADD(c,emulator2_preset_header,q)||!sxsb_eii_preset(c,q,n,limit,true))return false;
   uint8_t len[2];if(!sxsb_read(c,q+n-2,len,2))return false;q+=n;n=(uint16_t)sxsb16(len);presets++;if(!n)break;
  }
  p=(q+255)&~UINT64_C(255);
 }
 return true;
}
#undef SXSB_ADD
bool sx_emulatorii_eii_build(sx_context*c)
{
 return sxsb_eii(c);
}
