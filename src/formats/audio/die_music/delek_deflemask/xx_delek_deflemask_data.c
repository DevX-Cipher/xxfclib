/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Leonardo 'Delek' Demartino's DeFleMask module (.DMF) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_order8_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
const sx_layout sxmw_order8={UINT32_C(0x60870005),"order8",sxmw_order8_fields,SX_COUNT(sxmw_order8_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_dmf_header_fields[]={
 SX_FIELD("magic","bytes",0,16,SX_SIGNATURE),
 SX_FIELD("version","uint8",16,1,SX_ID),
 SX_FIELD("system","uint8",17,1,SX_ID),
};
const sx_layout sxmw_dmf_header={UINT32_C(0x60870023),"dmf_header",sxmw_dmf_header_fields,SX_COUNT(sxmw_dmf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_dmf_instrument_count_fields[]={
 SX_FIELD("instruments","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxmw_dmf_instrument_count={UINT32_C(0x60870025),"dmf_instrument_count",sxmw_dmf_instrument_count_fields,SX_COUNT(sxmw_dmf_instrument_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_dmf_fm_fields[]={
 SX_FIELD("algorithm","uint8",0,1,SX_NONE),
 SX_FIELD("feedback","uint8",1,1,SX_NONE),
 SX_FIELD("frequency_modulation","uint8",2,1,SX_NONE),
 SX_FIELD("amplitude_modulation","uint8",3,1,SX_NONE),
};
const sx_layout sxmw_dmf_fm={UINT32_C(0x60870027),"dmf_fm",sxmw_dmf_fm_fields,SX_COUNT(sxmw_dmf_fm_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_dmf_operator_fields[]={
 SX_FIELD("amplitude_modulation","uint8",0,1,SX_NONE),
 SX_FIELD("attack","uint8",1,1,SX_NONE),
 SX_FIELD("decay","uint8",2,1,SX_NONE),
 SX_FIELD("multiplier","uint8",3,1,SX_NONE),
 SX_FIELD("release","uint8",4,1,SX_NONE),
 SX_FIELD("sustain_level","uint8",5,1,SX_NONE),
 SX_FIELD("total_level","uint8",6,1,SX_NONE),
 SX_FIELD("detune2","uint8",7,1,SX_NONE),
 SX_FIELD("rate_scaling","uint8",8,1,SX_NONE),
 SX_FIELD("detune","uint8",9,1,SX_NONE),
 SX_FIELD("decay2","uint8",10,1,SX_NONE),
 SX_FIELD("ssg_envelope","uint8",11,1,SX_FLAGS),
};
const sx_layout sxmw_dmf_operator={UINT32_C(0x60870028),"dmf_operator",sxmw_dmf_operator_fields,SX_COUNT(sxmw_dmf_operator_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
static bool sxmw_pascal(sxmw_view*v,uint64_t*p,uint64_t end){uint64_t n;if(!sxmw_u(v,*p,1,&n,end)||!MW_ROW(pascal_text_length,*p,end))return false;(*p)++;if(!sxmw_text_emit(v,*p,n,end))return false;*p+=n;return true;}
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_dmf(sxmw_view*v)
{uint64_t end=v->c->size,p=18,ver,system,rows,ch,n,mode;
 if(!sxmw_eq(v,0,".DelekDefleMask.",16,end)||!sxmw_u(v,16,1,&ver,end)||ver!=24||!sxmw_u(v,17,1,&system,end)||!MW_ROW(dmf_header,0,end))return false;
 switch(system){case 2:ch=10;break;case 0x42:case 8:case 9:ch=13;break;case 3:case 4:ch=4;break;case 5:ch=6;break;case 6:ch=5;break;case 7:case 0x47:ch=3;break;case 0x49:ch=16;break;default:return true;}
 if(!sxmw_pascal(v,&p,end)||!sxmw_pascal(v,&p,end)||!sxmw_u(v,p+14,1,&rows,end)||!MW_TAKE(dmf_timing,&p,1,end)||!MW_TAKE(order8,&p,ch*rows,end)||!sxmw_u(v,p,1,&n,end)||!MW_TAKE(dmf_instrument_count,&p,1,end))return false;
 for(uint64_t i=0;i<n;i++){if(!sxmw_pascal(v,&p,end)||!sxmw_u(v,p,1,&mode,end)||!MW_TAKE(dmf_instrument_mode,&p,1,end))return false;
  if(mode!=1)return true; /* Standard instrument macros vary by chip; suffix stays physical raw. */
  if(!MW_TAKE(dmf_fm,&p,1,end)||!MW_TAKE(dmf_operator,&p,4,end))return false;
 }return true;}
bool sx_delek_deflemask_build(sxmw_view*v)
{
 return sxmw_dmf(v);
}
#undef MW_ROW
#undef MW_TAKE
