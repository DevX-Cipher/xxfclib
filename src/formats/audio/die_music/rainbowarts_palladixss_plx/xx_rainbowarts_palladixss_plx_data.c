/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Rainbow Arts' Palladix Sound System module (.PLX) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamip_plx_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
const sx_layout sxamip_plx_volume={UINT32_C(0x60900017),"plx_volume",sxamip_plx_volume_fields,SX_COUNT(sxamip_plx_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_speed_fields[]={
 SX_FIELD("speed","uint16",0,2,SX_NONE),
};
const sx_layout sxamip_plx_speed={UINT32_C(0x6090001A),"plx_speed",sxamip_plx_speed_fields,SX_COUNT(sxamip_plx_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_delay_fields[]={
 SX_FIELD("delay","uint8",0,1,SX_NONE),
};
const sx_layout sxamip_plx_delay={UINT32_C(0x6090001B),"plx_delay",sxamip_plx_delay_fields,SX_COUNT(sxamip_plx_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_instrument_fields[]={
 SX_FIELD("unknown","uint8",0,1,SX_NONE),
 SX_FIELD("feedback_algorithm","uint8",1,1,SX_FLAGS),
 SX_FIELD("modulator_20","uint8",2,1,SX_FLAGS),
 SX_FIELD("modulator_40","uint8",3,1,SX_FLAGS),
 SX_FIELD("modulator_60","uint8",4,1,SX_FLAGS),
 SX_FIELD("modulator_80","uint8",5,1,SX_FLAGS),
 SX_FIELD("modulator_e0","uint8",6,1,SX_FLAGS),
 SX_FIELD("carrier_23","uint8",7,1,SX_FLAGS),
 SX_FIELD("carrier_43","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_63","uint8",9,1,SX_FLAGS),
 SX_FIELD("carrier_83","uint8",10,1,SX_FLAGS),
 SX_FIELD("carrier_e3","uint8",11,1,SX_FLAGS),
};
const sx_layout sxamip_plx_instrument={UINT32_C(0x6090001C),"plx_instrument",sxamip_plx_instrument_fields,SX_COUNT(sxamip_plx_instrument_fields),SX_LE};
#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
#define AP_TAKE(l,p,n,end) sxamip_take(v,&sxamip_##l,(p),(n),(end))
static bool sxamip_plx(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,type,scale,p,flags,off;
 if(!sxamip_eq(v,0,"PLX",3,e)||!sxamip_u(v,3,1,&type,e)||type||!sxamip_u(v,4,1,&scale,e)||!AP_ROW(plx_header,0,e))return false;
 for(unsigned i=0;i<9;i++){
  if(!sxamip_u(v,7+2*i,2,&p,e))return false;if(!p)continue;
  for(unsigned step=0;step<65536;step++){
   if(!sxamip_u(v,p,1,&flags,e)||!AP_TAKE(plx_control,&p,1,e))return false;
   if(!flags)break;
   if(flags!=128){
    if(flags&1){if(!sxamip_u(v,p,2,&off,e)||!AP_TAKE(plx_instrument_offset,&p,1,e)||!AP_ROW(plx_instrument,off,e))return false;}
    if((flags&2)&&!AP_TAKE(plx_volume,&p,1,e))return false;
    if((flags&8)&&!AP_TAKE(plx_note,&p,1,e))return false;
    if((flags&16)&&!AP_TAKE(plx_frequency,&p,1,e))return false;
    if((flags&64)&&!AP_TAKE(plx_speed,&p,1,e))return false;
   }
   if(!AP_TAKE(plx_delay,&p,1,e))return false;
   if(step==65535)return false;
  }
 }
 return true;
}
bool sx_rainbowarts_palladixss_plx_build(sxamip_view*v)
{
 return sxamip_plx(v);
}
#undef AP_ROW
#undef AP_TAKE
