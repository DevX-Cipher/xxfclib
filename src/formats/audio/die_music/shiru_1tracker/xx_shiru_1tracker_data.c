/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Shiru's 1tracker module (.1TM) data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_1tracker_section_fields[]={
 SX_FIELD("section","char",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_section={UINT32_C(0x608F0055),"chip_1tracker_section",sxchip_chip_1tracker_section_fields,SX_COUNT(sxchip_chip_1tracker_section_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_key_fields[]={
 SX_FIELD("key","char",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_key={UINT32_C(0x608F0056),"chip_1tracker_key",sxchip_chip_1tracker_key_fields,SX_COUNT(sxchip_chip_1tracker_key_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_engine_fields[]={
 SX_FIELD("engine","char",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_engine={UINT32_C(0x608F0057),"chip_1tracker_engine",sxchip_chip_1tracker_engine_fields,SX_COUNT(sxchip_chip_1tracker_engine_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_title_fields[]={
 SX_FIELD("title","char",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_title={UINT32_C(0x608F0058),"chip_1tracker_title",sxchip_chip_1tracker_title_fields,SX_COUNT(sxchip_chip_1tracker_title_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_author_fields[]={
 SX_FIELD("author","char",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_author={UINT32_C(0x608F0059),"chip_1tracker_author",sxchip_chip_1tracker_author_fields,SX_COUNT(sxchip_chip_1tracker_author_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_measure_fields[]={
 SX_FIELD("measure","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_measure={UINT32_C(0x608F005D),"chip_1tracker_measure",sxchip_chip_1tracker_measure_fields,SX_COUNT(sxchip_chip_1tracker_measure_fields),SX_LE};
#define SXCHIP_LIMIT 24000U
static bool sxchip_text_row(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n||n>4096||!sxchip_span(c,p,n))return true;
 if(c->count>=SXCHIP_LIMIT)return true;
 return sx_add(c,l,(int64_t)p,(int64_t)n);
}
static bool sxchip_1tracker(sx_context*c){
 if(!sxchip_eq(c,0,"[1tracker module]\r\n",19))return true;
 uint64_t p=0,limit=(uint64_t)c->size;if(limit>8U*1024U*1024U)limit=8U*1024U*1024U;
 bool metadata=true;unsigned lines=0;
 while(p<limit&&lines++<65536){
  uint64_t start=p;uint8_t b[4097],ch=0;size_t used=0;
  while(p<limit&&sxchip_u8(c,p,&ch)){p++;if(ch==10)break;if(used<sizeof(b))b[used++]=ch;}
  uint64_t n=p-start;if(n&&ch==10)n--;if(n&&used&&b[used-1]==13){n--;used--;}
  if(!n||n>4096||used!=n)continue;
  if(b[0]=='['&&b[n-1]==']'){
   metadata=(n==17&&!xx_rt_memcmp(b,"[1tracker module]",17))||(n==10&&!xx_rt_memcmp(b,"[Settings]",10));
   if(!sxchip_text_row(c,&sxchip_chip_1tracker_section,start,n))return false;
   if(!metadata)break;continue;
  }
  if(!metadata)break;uint64_t eq=0;while(eq<n&&b[eq]!='=')eq++;if(!eq||eq==n)continue;
  const sx_layout*l=NULL;
#define SXCHIP_KEY(k,v) if(eq==sizeof(k)-1&&!xx_rt_memcmp(b,k,sizeof(k)-1))l=&sxchip_chip_1tracker_##v;
  SXCHIP_KEY("Engine",engine) else SXCHIP_KEY("Title",title) else SXCHIP_KEY("Author",author)
  else SXCHIP_KEY("Speed",speed) else SXCHIP_KEY("LoopStart",loop_start) else SXCHIP_KEY("LoopEnd",loop_end)
  else SXCHIP_KEY("Measure",measure) else SXCHIP_KEY("PatternFormat",pattern_format)
#undef SXCHIP_KEY
  if(l&&(!sxchip_text_row(c,&sxchip_chip_1tracker_key,start,eq)||!sxchip_text_row(c,l,start+eq+1,n-eq-1)))return false;
 }
 return true;
}
bool sx_shiru_1tracker_build(sx_context*c)
{
 return sxchip_1tracker(c);
}
