/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Jess D. 'Razmo' Skov-Nielsen's Kefrens Sound Machine module (.KSM) data structures, moved out of the classicmusic schema family. */
#include "../../../xx_format_schema_classicmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcmus_kefrens_header_fields[]={
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("title","char[13]",2,13,SX_NONE),
 SX_FIELD("opaque_prefix","bytes",15,17,SX_NONE),
};
const sx_layout sxcmus_kefrens_header={UINT32_C(0x609E000F),"kefrens_header",sxcmus_kefrens_header_fields,SX_COUNT(sxcmus_kefrens_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcmus_kefrens_order_fields[]={
 SX_FIELD("track_indexes","uint8[4]",0,4,SX_NONE),
};
const sx_layout sxcmus_kefrens_order={UINT32_C(0x609E0011),"kefrens_order",sxcmus_kefrens_order_fields,SX_COUNT(sxcmus_kefrens_order_fields),SX_LE};
#define SXCMUS_ADD(c,n,p) sxcmus_put(c,&sxcmus_##n,p,1)
static bool sxcmus_kefrens(sx_context*c){
 if(!sxcmus_eq(c,0,"M.",2)||!sxcmus_span(c,0,512)||!SXCMUS_ADD(c,kefrens_header,0)||!sxcmus_put(c,&sxcmus_kefrens_sample,32,15))return false;
 uint8_t first[4];if(!sxcmus_read(c,48,first,4))return false;uint64_t sample=sxcmus_be32(first),limit=(uint64_t)c->size;
 if(sample>=1536&&sample<limit)limit=sample;
 unsigned highest=0;bool ended=false;
 for(unsigned i=0;i<256;i++){
  uint64_t p=512+4U*i;uint8_t b[4];if(!sxcmus_read(c,p,b,4))return true;
  if(b[0]==255){if(!SXCMUS_ADD(c,kefrens_end,p))return false;ended=true;break;}
  if(!SXCMUS_ADD(c,kefrens_order,p))return false;
  for(unsigned j=0;j<4;j++)if(b[j]>highest)highest=b[j];
 }
 if(ended&&limit>=1536&&(uint64_t)(highest+1)*192<=limit-1536)return sxcmus_put(c,&sxcmus_kefrens_cell,1536,(uint64_t)(highest+1)*64);
 return true;
}
bool sx_razmo_kefrenssoundmachine_build(sx_context*c)
{
 return sxcmus_kefrens(c);
}
