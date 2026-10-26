/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Instrument bank for Adlib Visual Composer (STANDARD.BNK) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_bnk_header_fields[]={
 SX_FIELD("major","uint8",0,1,SX_ID),
 SX_FIELD("minor","uint8",1,1,SX_ID),
 SX_FIELD("magic","bytes",2,6,SX_SIGNATURE),
 SX_FIELD("used_entries","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("total_entries","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("names_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("reserved","bytes",20,8,SX_RESERVED),
};
const sx_layout sxmw_bnk_header={UINT32_C(0x60870010),"bnk_header",sxmw_bnk_header_fields,SX_COUNT(sxmw_bnk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bnk_name_fields[]={
 SX_FIELD("data_index","uint16",0,2,SX_ID),
 SX_FIELD("used","uint8",2,1,SX_FLAGS),
 SX_FIELD("name","char[9]",3,9,SX_NONE),
};
const sx_layout sxmw_bnk_name={UINT32_C(0x60870011),"bnk_name",sxmw_bnk_name_fields,SX_COUNT(sxmw_bnk_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bnk_operator_fields[]={
 SX_FIELD("key_scale_level","uint8",0,1,SX_NONE),
 SX_FIELD("multiplier","uint8",1,1,SX_NONE),
 SX_FIELD("feedback","uint8",2,1,SX_NONE),
 SX_FIELD("attack","uint8",3,1,SX_NONE),
 SX_FIELD("sustain_level","uint8",4,1,SX_NONE),
 SX_FIELD("sustained","uint8",5,1,SX_FLAGS),
 SX_FIELD("decay","uint8",6,1,SX_NONE),
 SX_FIELD("release","uint8",7,1,SX_NONE),
 SX_FIELD("output_level","uint8",8,1,SX_NONE),
 SX_FIELD("tremolo","uint8",9,1,SX_FLAGS),
 SX_FIELD("vibrato","uint8",10,1,SX_FLAGS),
 SX_FIELD("key_scale_rate","uint8",11,1,SX_FLAGS),
 SX_FIELD("connection","uint8",12,1,SX_FLAGS),
};
const sx_layout sxmw_bnk_operator={UINT32_C(0x60870013),"bnk_operator",sxmw_bnk_operator_fields,SX_COUNT(sxmw_bnk_operator_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bnk_waveforms_fields[]={
 SX_FIELD("modulator_waveform","uint8",0,1,SX_ID),
 SX_FIELD("carrier_waveform","uint8",1,1,SX_ID),
};
const sx_layout sxmw_bnk_waveforms={UINT32_C(0x60870014),"bnk_waveforms",sxmw_bnk_waveforms_fields,SX_COUNT(sxmw_bnk_waveforms_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_bnk(sxmw_view*v)
{uint64_t end=v->c->size,used,total,names,data,p;
 if(!sxmw_eq(v,2,"ADLIB-",6,end)||!sxmw_u(v,8,2,&used,end)||!sxmw_u(v,10,2,&total,end)||used>total||!sxmw_u(v,12,4,&names,end)||!sxmw_u(v,16,4,&data,end)||names<28||data<names+total*12||!MW_ROW(bnk_header,0,end)||!sxmw_table(v,&sxmw_bnk_name,names,total,end)||!sxmw_span(v,data,total*30,end))return false;
 p=data;for(uint64_t i=0;i<total;i++){if(!MW_TAKE(bnk_instrument,&p,1,end)||!MW_TAKE(bnk_operator,&p,2,end)||!MW_TAKE(bnk_waveforms,&p,1,end))return false;}return true;}
bool sx_adlibvisualcomposer_standardbnk_build(sxmw_view*v)
{
 return sxmw_bnk(v);
}
#undef MW_ROW
#undef MW_TAKE
