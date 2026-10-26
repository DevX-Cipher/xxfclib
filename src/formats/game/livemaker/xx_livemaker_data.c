/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * livemaker data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_livemaker_header_fields[]={
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint32",2,4,SX_ID),
 SX_FIELD("entries","uint32",6,4,SX_COUNT_PROP),
};
const sx_layout sxgco_livemaker_header={UINT32_C(0x60400024),"livemaker_header",sxgco_livemaker_header_fields,SX_COUNT(sxgco_livemaker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_livemaker_scramble_fields[]={
 SX_FIELD("chunk_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("encoded_seed","uint32",4,4,SX_NONE),
};
const sx_layout sxgco_livemaker_scramble={UINT32_C(0x60400027),"livemaker_scramble",sxgco_livemaker_scramble_fields,SX_COUNT(sxgco_livemaker_scramble_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_lm(sxgco_view*v)
{uint64_t p=10,n,z,e=v->c->size;if(!GC_ROW(livemaker_header,0,e)||!sxgco_word(v,6,4,false,&n,e)||n>UINT32_C(0x40000))return false;
 for(uint64_t i=0;i<n;i++){if(!GC_ROW(name_size32,p,e)||!sxgco_word(v,p,4,false,&z,e)||!z||z>256||!sxgco_table(v,&sxgco_encoded_byte,p+4,z,e))return false;p+=4+z;}
 if(!sxgco_table(v,&sxgco_livemaker_offset,p,n+1,e))return false;uint64_t offsets=p,flags=p+(n+1)*8;if(!sxgco_table(v,&sxgco_livemaker_flags,flags,n,e))return false;
 uint32_t state=0;uint64_t previous=0;for(uint64_t i=0;i<=n;i++){uint64_t raw,flag;state=state*5U+UINT32_C(0x75d6ee39);uint64_t mask=(uint64_t)state;if(state&UINT32_C(0x80000000))mask|=UINT64_C(0xffffffff00000000);if(!sxgco_word(v,offsets+i*8,8,false,&raw,e))return false;raw^=mask;if(raw>e||(i&&raw<previous))return false;if(i){if(!sxgco_word(v,flags+i-1,1,false,&flag,e))return false;if((flag==2||flag==3)&&raw-previous>=8&&!GC_ROW(livemaker_scramble,previous,raw))return false;}previous=raw;}return true;}
bool sx_livemaker_build(sxgco_view*v)
{
 return sxgco_lm(v);
}
#undef GC_ROW
