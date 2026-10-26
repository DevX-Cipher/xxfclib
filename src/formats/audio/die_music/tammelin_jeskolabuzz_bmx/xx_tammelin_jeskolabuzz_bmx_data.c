/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Oskari Tammelin's Jeskola Buzz module (.BMX) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_count16_fields[]={
 SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmw_count16={UINT32_C(0x60870004),"count16",sxmw_count16_fields,SX_COUNT(sxmw_count16_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bmx_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("sections","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmw_bmx_header={UINT32_C(0x60870009),"bmx_header",sxmw_bmx_header_fields,SX_COUNT(sxmw_bmx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bmx_section_fields[]={
 SX_FIELD("section_id","bytes",0,4,SX_ID),
 SX_FIELD("section_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("section_bytes","uint32",8,4,SX_SIZE),
};
const sx_layout sxmw_bmx_section={UINT32_C(0x6087000A),"bmx_section",sxmw_bmx_section_fields,SX_COUNT(sxmw_bmx_section_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bmx_sequence_fields[]={
 SX_FIELD("machine_index","uint16",0,2,SX_ID),
 SX_FIELD("event_count","uint32",2,4,SX_COUNT_PROP),
 SX_FIELD("position_bytes","uint8",6,1,SX_SIZE),
 SX_FIELD("event_bytes","uint8",7,1,SX_SIZE),
};
const sx_layout sxmw_bmx_sequence={UINT32_C(0x6087000D),"bmx_sequence",sxmw_bmx_sequence_fields,SX_COUNT(sxmw_bmx_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bmx_wave_data_fields[]={
 SX_FIELD("wave_index","uint16",0,2,SX_ID),
 SX_FIELD("encoding","uint8",2,1,SX_ID),
};
const sx_layout sxmw_bmx_wave_data={UINT32_C(0x6087000E),"bmx_wave_data",sxmw_bmx_wave_data_fields,SX_COUNT(sxmw_bmx_wave_data_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bmx_wave_bytes_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxmw_bmx_wave_bytes={UINT32_C(0x6087000F),"bmx_wave_bytes",sxmw_bmx_wave_bytes_fields,SX_COUNT(sxmw_bmx_wave_bytes_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_bmx(sxmw_view*v)
{uint64_t end=v->c->size,sections,n,at,len,p,ce,x,y;uint8_t tag[4];
 if(!sxmw_eq(v,0,"Buzz",4,end)||!sxmw_u(v,4,4,&sections,end)||sections>31||!MW_ROW(bmx_header,0,end)||!sxmw_table(v,&sxmw_bmx_section,8,sections,end))return false;
 for(uint64_t i=0;i<sections;i++){p=8+i*12;if(!sxmw_read(v,p,tag,4,end)||!sxmw_u(v,p+4,4,&at,end)||!sxmw_u(v,p+8,4,&len,end)||at<8+sections*12||!sxmw_span(v,at,len,end))return false;p=at;ce=at+len;
  if(!xx_rt_memcmp(tag,"CONN",4)){if(!sxmw_u(v,p,2,&n,ce)||!MW_TAKE(count16,&p,1,ce)||!MW_TAKE(bmx_connection,&p,n,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SEQU",4)){if(!sxmw_u(v,p+12,2,&n,ce)||!MW_TAKE(bmx_sequences,&p,1,ce))return false;for(uint64_t j=0;j<n;j++){if(!sxmw_u(v,p+2,4,&len,ce)||!sxmw_u(v,p+6,1,&x,ce)||!sxmw_u(v,p+7,1,&y,ce)||x>4||y>4||!x||!y||!MW_TAKE(bmx_sequence,&p,1,ce)||!sxmw_skip(v,&p,len*(x+y),ce))return false;}}
  else if(!xx_rt_memcmp(tag,"WAVE",4)||!xx_rt_memcmp(tag,"CWAV",4)){if(!sxmw_u(v,p,2,&n,ce)||!MW_TAKE(count16,&p,1,ce))return false;for(uint64_t j=0;j<n;j++){if(!sxmw_u(v,p+2,1,&x,ce)||!MW_TAKE(bmx_wave_data,&p,1,ce))return false;if(x)break;if(!sxmw_u(v,p,4,&len,ce)||!MW_TAKE(bmx_wave_bytes,&p,1,ce)||!sxmw_skip(v,&p,len,ce))return false;}}
  /* MACH/PATT state depends on external plugins. Preserve all such bytes raw. */
 }return true;}
bool sx_tammelin_jeskolabuzz_bmx_build(sxmw_view*v)
{
 return sxmw_bmx(v);
}
#undef MW_ROW
#undef MW_TAKE
