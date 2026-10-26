/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bastian 'Twice' Spiegel's Art of Noise/Chorus module (.AON) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_aon_arpeggio_fields[]={
 SX_FIELD("note0","uint8",0,1,SX_NONE),
 SX_FIELD("note1","uint8",1,1,SX_NONE),
 SX_FIELD("note2","uint8",2,1,SX_NONE),
 SX_FIELD("note3","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_aon_arpeggio={UINT32_C(0x60810052),"aon_arpeggio",sxmta_aon_arpeggio_fields,SX_COUNT(sxmta_aon_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("identification","char[42]",4,42,SX_NONE),
};
const sx_layout sxmta_aon_header={UINT32_C(0x60810054),"aon_header",sxmta_aon_header_fields,SX_COUNT(sxmta_aon_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","int32",4,4,SX_SIZE),
};
const sx_layout sxmta_aon_chunk={UINT32_C(0x60810055),"aon_chunk",sxmta_aon_chunk_fields,SX_COUNT(sxmta_aon_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_aon_info_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("orders","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint8",2,1,SX_NONE),
};
const sx_layout sxmta_aon_info={UINT32_C(0x60810056),"aon_info",sxmta_aon_info_fields,SX_COUNT(sxmta_aon_info_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument_arpeggio","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_aon_event={UINT32_C(0x60810059),"aon_event",sxmta_aon_event_fields,SX_COUNT(sxmta_aon_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_wave_length_fields[]={
 SX_FIELD("wave_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxmta_aon_wave_length={UINT32_C(0x6081005A),"aon_wave_length",sxmta_aon_wave_length_fields,SX_COUNT(sxmta_aon_wave_length_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_aon_instrument_name_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
};
const sx_layout sxmta_aon_instrument_name={UINT32_C(0x6081005B),"aon_instrument_name",sxmta_aon_instrument_name_fields,SX_COUNT(sxmta_aon_instrument_name_fields),SX_LE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_aon(sxmta_view*v)
{uint64_t end=v->c->size,p=46,n,ce,x,ch;uint8_t tag[4];
 if((!sxmta_eq(v,0,"AON4",4,end)&&!sxmta_eq(v,0,"AON8",4,end))||!sxmta_u(v,3,1,&ch,end)||!MTA_ROW(aon_header,0,end))return false;ch-='0';
 while(p<end){if(!sxmta_u(v,p,1,&x,end))return false;if(x=='?')return true;
  if(!sxmta_read(v,p,tag,4,end)||!sxmta_be(v,p+4,4,&n,end)||n>INT32_MAX||!sxmta_span(v,p+8,n,end)||!MTA_ROW(aon_chunk,p,end))return false;p+=8;ce=p+n;
  if(!xx_rt_memcmp(tag,"NAME",4)||!xx_rt_memcmp(tag,"AUTH",4)||!xx_rt_memcmp(tag,"RMRK",4)){if(!sxmta_text_emit(v,p,n,ce))return false;}
  else if(!xx_rt_memcmp(tag,"INFO",4)){if(!MTA_ROW(aon_info,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"ARPG",4)){if(!MTA_TAKE(aon_arpeggio,&p,16,ce))return false;}
  else if(!xx_rt_memcmp(tag,"PLST",4)){if(!MTA_TAKE(order8,&p,n,ce))return false;}
  else if(!xx_rt_memcmp(tag,"PATT",4)){if(n%(ch*64*4)||!MTA_TAKE(aon_event,&p,n/4,ce))return false;}
  else if(!xx_rt_memcmp(tag,"INST",4)){if(n%32)return false;while(p<ce){if(!sxmta_u(v,p,1,&x,ce)||(x>1?!sxmta_skip(v,&p,32,ce):!sxmta_take(v,x?&sxmta_aon_synth:&sxmta_aon_sample,&p,1,ce)))return false;}}
  else if(!xx_rt_memcmp(tag,"INAM",4)){if(n%32||!MTA_TAKE(aon_instrument_name,&p,n/32,ce))return false;}
  else if(!xx_rt_memcmp(tag,"WLEN",4)){if(n%4||!MTA_TAKE(aon_wave_length,&p,n/4,ce))return false;}
  p=ce;
 }return true;}
bool sx_twice_artofnoise_build(sxmta_view*v)
{
 return sxmta_aon(v);
}
#undef MTA_ROW
#undef MTA_TAKE
