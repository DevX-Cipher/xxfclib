/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Hans Bergstedt's Sound Invasion Music System/In Stereo! module (.IS20) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_is_signed_value_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxmta_is_signed_value={UINT32_C(0x6081008E),"is_signed_value",sxmta_is_signed_value_fields,SX_COUNT(sxmta_is_signed_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is2_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
};
const sx_layout sxmta_is2_header={UINT32_C(0x6081008F),"is2_header",sxmta_is2_header_fields,SX_COUNT(sxmta_is2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is2_section_fields[]={
 SX_FIELD("tag","bytes",0,4,SX_ID),
 SX_FIELD("count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmta_is2_section={UINT32_C(0x60810090),"is2_section",sxmta_is2_section_fields,SX_COUNT(sxmta_is2_section_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is2_sample_name_fields[]={
 SX_FIELD("name","char[20]",0,20,SX_NONE),
};
const sx_layout sxmta_is2_sample_name={UINT32_C(0x60810094),"is2_sample_name",sxmta_is2_sample_name_fields,SX_COUNT(sxmta_is2_sample_name_fields),SX_LE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_is2_read_section(sxmta_view*v,uint64_t*p,const char*name,uint64_t*n,uint64_t end)
{return sxmta_eq(v,*p,name,4,end)&&sxmta_be(v,*p+4,4,n,end)&&MTA_TAKE(is2_section,p,1,end);}
static bool sxmta_is2(sxmta_view*v)
{uint64_t end=v->c->size,p=8,n,ns,x,total=0;
 if(!sxmta_eq(v,0,"IS20DF10",8,end)||!MTA_ROW(is2_header,0,end)||!sxmta_is2_read_section(v,&p,"STBL",&n,end)||!MTA_TAKE(is2_subsong,&p,n,end)||!sxmta_is2_read_section(v,&p,"OVTB",&n,end)||!MTA_TAKE(is_position,&p,n*4,end)||!sxmta_is2_read_section(v,&p,"NTBL",&n,end)||!MTA_TAKE(is2_event,&p,n,end)||!sxmta_is2_read_section(v,&p,"SAMP",&ns,end)||!MTA_TAKE(is2_sample,&p,ns,end)||!MTA_TAKE(is2_sample_name,&p,ns,end)||!MTA_TAKE(is2_sample_copy,&p,ns,end))return false;
 for(uint64_t i=0;i<ns;i++){if(!sxmta_be(v,p,4,&x,end)||!MTA_TAKE(is_sample_bytes,&p,1,end))return false;total+=x;}
 if(!sxmta_skip(v,&p,total,end)||!sxmta_is2_read_section(v,&p,"SYNT",&n,end)||n>4000000||!sxmta_span(v,p,n*1010,end))return false;
 for(uint64_t i=0;i<n;i++){if(!sxmta_eq(v,p,"IS20",4,end)||!MTA_TAKE(is2_synth,&p,1,end)||!MTA_TAKE(is_unsigned_value,&p,128,end)||!MTA_TAKE(is_signed_value,&p,128,end)||!MTA_TAKE(is2_arpeggio,&p,3,end)||!MTA_TAKE(is_unsigned_value,&p,128,end)||!sxmta_skip(v,&p,512,end))return false;}
 return true;}
bool sx_bergstedt_sims_instereo2_build(sxmta_view*v)
{
 return sxmta_is2(v);
}
#undef MTA_ROW
#undef MTA_TAKE
