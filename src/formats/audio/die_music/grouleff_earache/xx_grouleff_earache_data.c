/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Morten Grouleff's EarAche module (.EA,.EAS) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamip_ea_pattern_fields[]={
 SX_FIELD("channel0_note","uint8",0,1,SX_NONE),
 SX_FIELD("channel0_instrument","uint8",1,1,SX_ID),
 SX_FIELD("channel1_note","uint8",2,1,SX_NONE),
 SX_FIELD("channel1_instrument","uint8",3,1,SX_ID),
 SX_FIELD("channel2_note","uint8",4,1,SX_NONE),
 SX_FIELD("channel2_instrument","uint8",5,1,SX_ID),
 SX_FIELD("channel3_note","uint8",6,1,SX_NONE),
 SX_FIELD("channel3_instrument","uint8",7,1,SX_ID),
};
const sx_layout sxamip_ea_pattern={UINT32_C(0x6090001F),"ea_pattern",sxamip_ea_pattern_fields,SX_COUNT(sxamip_ea_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_ea_magic_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
};
const sx_layout sxamip_ea_magic={UINT32_C(0x60900023),"ea_magic",sxamip_ea_magic_fields,SX_COUNT(sxamip_ea_magic_fields),SX_LE};
#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
#define AP_TAKE(l,p,n,end) sxamip_take(v,&sxamip_##l,(p),(n),(end))
static bool sxamip_ea(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,base=0,off[6],p,maxpat=0,maxins=0;
 if(sxamip_eq(v,0,"EASO",4,e)){base=4;if(!AP_ROW(ea_magic,0,e))return false;}
 else return false;
 if(!sxamip_span(v,base,24,e))return false;
 for(unsigned i=0;i<6;i++){if(!sxamip_be(v,base+4*i,4,&off[i],e)||off[i]>e-base)return false;off[i]+=base;}
 if(off[0]!=base+24||off[1]<=off[0]||(off[1]-off[0])%8||off[4]<=off[2]||(off[4]-off[2])%16||!AP_ROW(ea_header,base,e))return false;
 p=off[1];for(unsigned i=0;i<65536;i++){
  uint64_t a,b;if(!sxamip_be(v,p,2,&a,e)||!sxamip_be(v,p+2,2,&b,e)||!AP_TAKE(ea_position,&p,1,e))return false;if(a==65535)break;
  if((a&4095)>maxpat)maxpat=a&4095;if((b&4095)>maxpat)maxpat=b&4095;
  if(i==65535)return false;
 }
 if(maxpat+1>(off[1]-off[0])/8)return false;
 for(uint64_t i=0;i<=maxpat;i++){
  p=off[0]+i*8;if(!AP_ROW(ea_pattern,p,e))return false;
  for(unsigned ch=0;ch<4;ch++){uint64_t a,b;if(!sxamip_be(v,p+ch*2,2,&a,e))return false;b=a&255;if(a&&b>maxins)maxins=b;}
 }
 if(!sxamip_table(v,&sxamip_ea_instrument,off[2],maxins+1,e))return false;
 p=off[3];for(unsigned i=0;i<128;i++){
  uint64_t a,z;if(!sxamip_be(v,p,2,&a,e)||!sxamip_be(v,p+2,2,&z,e)||!AP_TAKE(ea_sample,&p,1,e))return false;
  if(!a&&!z)break;if(!sxamip_span(v,base+a*4,z*2,e))return false;if(i==127)return false;
 }
 return true;
}
bool sx_grouleff_earache_build(sxamip_view*v)
{
 return sxamip_ea(v);
}
#undef AP_ROW
#undef AP_TAKE
