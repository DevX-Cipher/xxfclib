/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Michel 'Bananmos' Iwaniec/Nerds 'R' Us Nerd Tracker 2 module (.NED) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_ned10_header_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("initial_tempo","uint8",4,1,SX_NONE),
 SX_FIELD("instrument_count","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("order_count","uint8",7,1,SX_COUNT_PROP),
};
const sx_layout sxchip_chip_ned10_header={UINT32_C(0x608F001A),"chip_ned10_header",sxchip_chip_ned10_header_fields,SX_COUNT(sxchip_chip_ned10_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned10_instrument_fields[]={
 SX_FIELD("control_register_1","uint8",0,1,SX_FLAGS),
 SX_FIELD("control_register_2","uint8",1,1,SX_FLAGS),
 SX_FIELD("control_register_4","uint8",2,1,SX_FLAGS),
};
const sx_layout sxchip_chip_ned10_instrument={UINT32_C(0x608F001B),"chip_ned10_instrument",sxchip_chip_ned10_instrument_fields,SX_COUNT(sxchip_chip_ned10_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned_order_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
const sx_layout sxchip_chip_ned_order={UINT32_C(0x608F001C),"chip_ned_order",sxchip_chip_ned_order_fields,SX_COUNT(sxchip_chip_ned_order_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned10_pattern_fields[]={
 SX_FIELD("pattern_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxchip_chip_ned10_pattern={UINT32_C(0x608F001D),"chip_ned10_pattern",sxchip_chip_ned10_pattern_fields,SX_COUNT(sxchip_chip_ned10_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned20_header_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("module_name","char[29]",5,29,SX_NONE),
 SX_FIELD("terminator","uint8",34,1,SX_ID),
 SX_FIELD("header_size","uint32",35,4,SX_SIZE),
 SX_FIELD("version","uint8",39,1,SX_ID),
 SX_FIELD("flags","uint16",40,2,SX_FLAGS),
 SX_FIELD("ntsc_sample_instrument_count","uint8",42,1,SX_COUNT_PROP),
 SX_FIELD("pal_sample_instrument_count","uint8",43,1,SX_COUNT_PROP),
 SX_FIELD("ntsc_sample_data_size","uint32",44,4,SX_SIZE),
 SX_FIELD("pal_sample_data_size","uint32",48,4,SX_SIZE),
};
const sx_layout sxchip_chip_ned20_header={UINT32_C(0x608F001E),"chip_ned20_header",sxchip_chip_ned20_header_fields,SX_COUNT(sxchip_chip_ned20_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned20_data_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("header_size","uint8",1,1,SX_SIZE),
 SX_FIELD("flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("initial_tempo","uint8",3,1,SX_NONE),
 SX_FIELD("restart_position","uint8",4,1,SX_NONE),
 SX_FIELD("instrument_count","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("dpcm_instrument_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("order_count","uint8",7,1,SX_COUNT_PROP),
 SX_FIELD("square1_pattern_count","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("square2_pattern_count","uint8",9,1,SX_COUNT_PROP),
 SX_FIELD("triangle_pattern_count","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("noise_pattern_count","uint8",11,1,SX_COUNT_PROP),
 SX_FIELD("dpcm_pattern_count","uint8",12,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",13,3,SX_RESERVED),
};
const sx_layout sxchip_chip_ned20_data={UINT32_C(0x608F001F),"chip_ned20_data",sxchip_chip_ned20_data_fields,SX_COUNT(sxchip_chip_ned20_data_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned20_instrument_fields[]={
 SX_FIELD("control_register_0","uint8",0,1,SX_FLAGS),
 SX_FIELD("portamento","uint8",1,1,SX_NONE),
 SX_FIELD("auto_vibrato","uint8",2,1,SX_FLAGS),
 SX_FIELD("auto_tremolo","uint8",3,1,SX_FLAGS),
 SX_FIELD("length_slide_direction","uint8",4,1,SX_FLAGS),
 SX_FIELD("volume_slide","uint8",5,1,SX_FLAGS),
 SX_FIELD("arpeggio_z_flags","uint8",6,1,SX_FLAGS),
 SX_FIELD("arpeggio_xy","uint8",7,1,SX_FLAGS),
};
const sx_layout sxchip_chip_ned20_instrument={UINT32_C(0x608F0020),"chip_ned20_instrument",sxchip_chip_ned20_instrument_fields,SX_COUNT(sxchip_chip_ned20_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned20_order_fields[]={
 SX_FIELD("packed_channel_patterns","uint32",0,4,SX_FLAGS),
};
const sx_layout sxchip_chip_ned20_order={UINT32_C(0x608F0022),"chip_ned20_order",sxchip_chip_ned20_order_fields,SX_COUNT(sxchip_chip_ned20_order_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned_sample_instrument_fields[]={
 SX_FIELD("note_map","bytes",0,48,SX_NONE),
 SX_FIELD("name","char[12]",48,12,SX_NONE),
 SX_FIELD("sample_count","uint8",60,1,SX_COUNT_PROP),
};
const sx_layout sxchip_chip_ned_sample_instrument={UINT32_C(0x608F0024),"chip_ned_sample_instrument",sxchip_chip_ned_sample_instrument_fields,SX_COUNT(sxchip_chip_ned_sample_instrument_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static uint32_t sxchip32(const uint8_t*b){return (uint32_t)b[0]|(uint32_t)b[1]<<8|(uint32_t)b[2]<<16|(uint32_t)b[3]<<24;}
static bool sxchip_ned(sx_context*c){
 uint8_t h[52];if(!sxchip_read(c,0,h,8)||xx_rt_memcmp(h,"NED",3))return false;
 if(h[3]==0x10){if(!SXCHIP_ADD(c,chip_ned10_header,0))return false;uint64_t p=8;
  if(!sxchip_span(c,p,3U*h[5]+h[7]+2U*h[6]))return true;
  if(!sxchip_put(c,&sxchip_chip_ned10_instrument,p,h[5]))return false;p+=3U*h[5];
  if(!sxchip_put(c,&sxchip_chip_ned_order,p,h[7]))return false;p+=h[7];
  return sxchip_put(c,&sxchip_chip_ned10_pattern,p,h[6]);
 }
 if(!sxchip_read(c,0,h,52)||xx_rt_memcmp(h,"NED: ",5))return false;
 if(!SXCHIP_ADD(c,chip_ned20_header,0))return false;
 uint64_t p=sxchip32(h+35);if(p<52)return true;
 if(h[39]==0x20||h[39]==0x21){uint64_t count=h[42],n=count*229U+sxchip32(h+44);
  if(p!=52||!sxchip_span(c,p,n))return true;
  for(uint64_t i=0;i<count;i++){uint64_t q=p+229*i;if(!SXCHIP_ADD(c,chip_ned_sample_instrument,q)||!sxchip_put(c,&sxchip_chip_ned_sample,q+61,8))return false;}
  p+=n;
 }
 uint8_t d[16];if(!sxchip_read(c,p,d,16)||d[0]!=0x20||d[1]<16)return true;
 if(!SXCHIP_ADD(c,chip_ned20_data,p))return false;p+=d[1];
 uint64_t pn=0;for(unsigned i=8;i<13;i++)pn+=d[i];uint64_t span=8U*d[5]+17U*d[6]+4U*d[7]+2*pn;
 if(!sxchip_span(c,p,span))return true;
 if(!sxchip_put(c,&sxchip_chip_ned20_instrument,p,d[5]))return false;p+=8U*d[5];
 if(!sxchip_put(c,&sxchip_chip_ned20_dpcm_instrument,p,d[6]))return false;p+=17U*d[6];
 if(!sxchip_put(c,&sxchip_chip_ned20_order,p,d[7]))return false;p+=4U*d[7];
 return sxchip_put(c,&sxchip_chip_ned20_pattern,p,pn);
}
bool sx_nerdsrus_nerdtracker2_ned_build(sx_context*c)
{
 return sxchip_ned(c);
}
