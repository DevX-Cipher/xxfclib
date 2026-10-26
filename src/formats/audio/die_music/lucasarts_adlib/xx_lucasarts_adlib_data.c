/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Lucas Arts Adlib chiptune (.LAA) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_laa_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmw_laa_header={UINT32_C(0x60870032),"laa_header",sxmw_laa_header_fields,SX_COUNT(sxmw_laa_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmw_laa_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmw_laa_chunk={UINT32_C(0x60870033),"laa_chunk",sxmw_laa_chunk_fields,SX_COUNT(sxmw_laa_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmw_laa_mdhd_fields[]={
 SX_FIELD("opaque_driver_data","bytes",0,8,SX_NONE),
};
const sx_layout sxmw_laa_mdhd={UINT32_C(0x60870034),"laa_mdhd",sxmw_laa_mdhd_fields,SX_COUNT(sxmw_laa_mdhd_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_midi_header_fields[]={
 SX_FIELD("format","uint16",0,2,SX_ID),
 SX_FIELD("tracks","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("division","uint16",4,2,SX_NONE),
};
const sx_layout sxmw_midi_header={UINT32_C(0x60870035),"midi_header",sxmw_midi_header_fields,SX_COUNT(sxmw_midi_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmw_laa_old_header_fields[]={
 SX_FIELD("file_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("magic","bytes",4,2,SX_SIGNATURE),
 SX_FIELD("unknown","bytes",6,3,SX_NONE),
 SX_FIELD("ticks_per_quarter","uint8",9,1,SX_NONE),
 SX_FIELD("opaque","bytes",10,15,SX_NONE),
};
const sx_layout sxmw_laa_old_header={UINT32_C(0x60870036),"laa_old_header",sxmw_laa_old_header_fields,SX_COUNT(sxmw_laa_old_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_laa_old_instrument_fields[]={
 SX_FIELD("unknown_prefix","bytes",0,2,SX_NONE),
 SX_FIELD("feedback_connection","uint8",2,1,SX_FLAGS),
 SX_FIELD("mod_characteristics","uint8",3,1,SX_FLAGS),
 SX_FIELD("mod_level","uint8",4,1,SX_FLAGS),
 SX_FIELD("mod_attack_decay","uint8",5,1,SX_FLAGS),
 SX_FIELD("mod_sustain_release","uint8",6,1,SX_FLAGS),
 SX_FIELD("mod_wave","uint8",7,1,SX_ID),
 SX_FIELD("carrier_characteristics","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",9,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",10,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",11,1,SX_FLAGS),
 SX_FIELD("carrier_wave","uint8",12,1,SX_ID),
 SX_FIELD("unknown_suffix","bytes",13,3,SX_NONE),
};
const sx_layout sxmw_laa_old_instrument={UINT32_C(0x60870037),"laa_old_instrument",sxmw_laa_old_instrument_fields,SX_COUNT(sxmw_laa_old_instrument_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_laa(sxmw_view*v)
{uint64_t end=v->c->size,p=0,n,ce;uint8_t tag[4];
 if(sxmw_eq(v,0,"ADL ",4,end)){if(!sxmw_be(v,4,4,&n,end)||!MW_ROW(laa_header,0,end))return false;p=8;
  while(p<end){if(!sxmw_read(v,p,tag,4,end)||!sxmw_be(v,p+4,4,&n,end)||!sxmw_span(v,p+8,n,end)||!MW_TAKE(laa_chunk,&p,1,end))return false;ce=p+n;
   if(!xx_rt_memcmp(tag,"MDhd",4)&&n==8){if(!MW_ROW(laa_mdhd,p,ce))return false;}
   else if(!xx_rt_memcmp(tag,"MThd",4)&&n>=6){if(!MW_ROW(midi_header,p,ce))return false;}
   p=ce;
  }return true;
 }
 return sxmw_eq(v,4,"AD",2,end)&&sxmw_u(v,0,4,&n,end)&&n==end&&MW_TAKE(laa_old_header,&p,1,end)&&MW_TAKE(laa_old_instrument,&p,8,end);}
bool sx_lucasarts_adlib_build(sxmw_view*v)
{
 return sxmw_laa(v);
}
#undef MW_ROW
#undef MW_TAKE
