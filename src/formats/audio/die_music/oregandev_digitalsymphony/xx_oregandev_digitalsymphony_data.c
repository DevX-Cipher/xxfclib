/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Oregan Developments' Digital Symphony module (.DSYM) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_pascal_text_length_fields[]={
 SX_FIELD("text_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxmta_pascal_text_length={UINT32_C(0x60810002),"pascal_text_length",sxmta_pascal_text_length_fields,SX_COUNT(sxmta_pascal_text_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_order16le_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
};
const sx_layout sxmta_order16le={UINT32_C(0x60810006),"order16le",sxmta_order16le_fields,SX_COUNT(sxmta_order16le_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint8",8,1,SX_ID),
 SX_FIELD("channels","uint8",9,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("info_bytes","uint24",14,3,SX_SIZE),
};
const sx_layout sxmta_dsym_header={UINT32_C(0x60810037),"dsym_header",sxmta_dsym_header_fields,SX_COUNT(sxmta_dsym_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_sample_words_fields[]={
 SX_FIELD("sample_words","uint24",0,3,SX_COUNT_PROP),
};
const sx_layout sxmta_dsym_sample_words={UINT32_C(0x60810039),"dsym_sample_words",sxmta_dsym_sample_words_fields,SX_COUNT(sxmta_dsym_sample_words_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_commands_fields[]={
 SX_FIELD("allowed_commands","bytes",0,8,SX_FLAGS),
};
const sx_layout sxmta_dsym_commands={UINT32_C(0x6081003A),"dsym_commands",sxmta_dsym_commands_fields,SX_COUNT(sxmta_dsym_commands_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_sample_fields[]={
 SX_FIELD("loop_start_words","uint24",0,3,SX_NONE),
 SX_FIELD("loop_words","uint24",3,3,SX_COUNT_PROP),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("finetune","uint8",7,1,SX_NONE),
};
const sx_layout sxmta_dsym_sample={UINT32_C(0x6081003C),"dsym_sample",sxmta_dsym_sample_fields,SX_COUNT(sxmta_dsym_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_event_fields[]={
 SX_FIELD("note_instrument_low","uint8",0,1,SX_FLAGS),
 SX_FIELD("instrument_effect_low","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_parameter_low","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter_high","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_dsym_event={UINT32_C(0x6081003D),"dsym_event",sxmta_dsym_event_fields,SX_COUNT(sxmta_dsym_event_fields),SX_LE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
static bool sxmta_pascal(sxmta_view*v,uint64_t*p,uint64_t end){uint64_t n;if(!sxmta_u(v,*p,1,&n,end)||!MTA_ROW(pascal_text_length,*p,end))return false;(*p)++;if(!sxmta_text_emit(v,*p,n,end))return false;*p+=n;return true;}
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_dsym(sxmta_view*v)
{uint64_t end=v->c->size,p=17,orders,tracks,ch,x,len[63],flags[63];
 if(!sxmta_eq(v,0,"\x02\x01\x13\x13\x14\x12\x01\x0b",8,end)||!sxmta_u(v,9,1,&ch,end)||!ch||ch>8||!sxmta_u(v,10,2,&orders,end)||!sxmta_u(v,12,2,&tracks,end)||!MTA_ROW(dsym_header,0,end))return false;
 for(unsigned i=0;i<63;i++){if(!sxmta_u(v,p,1,&flags[i],end)||!MTA_TAKE(dsym_sample_flags,&p,1,end))return false;len[i]=0;if(!(flags[i]&128)){if(!sxmta_u(v,p,3,&len[i],end)||!MTA_TAKE(dsym_sample_words,&p,1,end))return false;len[i]*=2;}}
 if(!sxmta_pascal(v,&p,end)||!MTA_TAKE(dsym_commands,&p,1,end))return false;
 if(orders){if(!sxmta_u(v,p,1,&x,end)||!MTA_TAKE(dsym_packing,&p,1,end))return false;if(x)return true;if(!MTA_TAKE(order16le,&p,orders*ch,end))return false;}
 for(uint64_t i=0;i<tracks;){uint64_t n=tracks-i;if(n>2000)n=2000;if(!sxmta_u(v,p,1,&x,end)||!MTA_TAKE(dsym_packing,&p,1,end))return false;if(x)return true;if(!MTA_TAKE(dsym_event,&p,n*64,end))return false;i+=n;}
 for(unsigned i=0;i<63;i++){x=flags[i]&63;if(!sxmta_text_emit(v,p,x,end))return false;p+=x;if(flags[i]&128)continue;if(!MTA_TAKE(dsym_sample,&p,1,end))return false;if(len[i]){if(!sxmta_u(v,p,1,&x,end)||!MTA_TAKE(dsym_packing,&p,1,end))return false;if(x)return true;if(!sxmta_skip(v,&p,len[i],end))return false;}}
 return true;}
bool sx_oregandev_digitalsymphony_build(sxmta_view*v)
{
 return sxmta_dsym(v);
}
#undef MTA_ROW
#undef MTA_TAKE
