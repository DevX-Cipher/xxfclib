/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC HELLSTROM SBSTUDIO PAC data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_order16_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
};
const sx_layout sxmw_order16={UINT32_C(0x60870006),"order16",sxmw_order16_fields,SX_COUNT(sxmw_order16_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_pac_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmw_pac_header={UINT32_C(0x6087001D),"pac_header",sxmw_pac_header_fields,SX_COUNT(sxmw_pac_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_pac_info_fields[]={
 SX_FIELD("package_version","uint16",0,2,SX_ID),
 SX_FIELD("writer_version","uint16",2,2,SX_ID),
 SX_FIELD("sounds","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxmw_pac_info={UINT32_C(0x6087001E),"pac_info",sxmw_pac_info_fields,SX_COUNT(sxmw_pac_info_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_pac_song_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("tempo","uint8",1,1,SX_NONE),
 SX_FIELD("sheets","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("channels","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("lines_per_sheet","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("bytes_per_cell","uint8",6,1,SX_SIZE),
 SX_FIELD("packing","uint8",7,1,SX_FLAGS),
};
const sx_layout sxmw_pac_song={UINT32_C(0x6087001F),"pac_song",sxmw_pac_song_fields,SX_COUNT(sxmw_pac_song_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_pac_pan_fields[]={
 SX_FIELD("pan","uint8",0,1,SX_NONE),
};
const sx_layout sxmw_pac_pan={UINT32_C(0x60870020),"pac_pan",sxmw_pac_pan_fields,SX_COUNT(sxmw_pac_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_pac_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("sound","uint8",1,1,SX_ID),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("effect","uint8",3,1,SX_ID),
 SX_FIELD("argument","uint8",4,1,SX_NONE),
};
const sx_layout sxmw_pac_event={UINT32_C(0x60870022),"pac_event",sxmw_pac_event_fields,SX_COUNT(sxmw_pac_event_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_pac(sxmw_view*v)
{uint64_t end=v->c->size,p=8,n,ce,ch=0,packing=1,lines=0,cell=0;uint8_t tag[4];
 if(!sxmw_eq(v,0,"PACG",4,end)||!sxmw_u(v,4,4,&n,end)||n>end-8||!MW_ROW(pac_header,0,end))return false;end=n+8;
 while(p<end){if(!sxmw_read(v,p,tag,4,end)||!sxmw_u(v,p+4,4,&n,end)||!sxmw_span(v,p+8,n,end)||!MW_TAKE(chunk_le,&p,1,end))return false;ce=p+n;
  if(!xx_rt_memcmp(tag,"PAIN",4)){if(!MW_ROW(pac_info,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SOIN",4)){if(!sxmw_u(v,p+4,1,&ch,ce)||!sxmw_u(v,p+5,1,&lines,ce)||!sxmw_u(v,p+6,1,&cell,ce)||!sxmw_u(v,p+7,1,&packing,ce)||!MW_TAKE(pac_song,&p,1,ce)||!MW_TAKE(pac_pan,&p,ch,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SNIN",4)){if(!MW_ROW(pac_sound,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SOOR",4)){if(n%2||!MW_TAKE(order16,&p,n/2,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SONA",4)||!xx_rt_memcmp(tag,"SNNA",4)||!xx_rt_memcmp(tag,"PAOR",4)){if(!sxmw_text_emit(v,p,n,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SOSH",4)&&ch&&lines==64&&cell==5&&!packing){if(n!=ch*lines*cell||!MW_TAKE(pac_event,&p,ch*lines,ce))return false;}
  else if(!xx_rt_memcmp(tag,"END ",4))return n==0;
  p=ce;
 }return true;}
bool sx_hellstrom_sbstudio_pac_build(sxmw_view*v)
{
 return sxmw_pac(v);
}
#undef MW_ROW
#undef MW_TAKE
