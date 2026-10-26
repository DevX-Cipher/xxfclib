/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * rpg_maker_rgssad data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_rgss_header_fields[]={
 SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("version","uint8",7,1,SX_ID),
};
const sx_layout sxgco_rgss_header={UINT32_C(0x6040002B),"rgss_header",sxgco_rgss_header_fields,SX_COUNT(sxgco_rgss_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_rgss_seed_fields[]={
 SX_FIELD("seed","uint32",0,4,SX_NONE),
};
const sx_layout sxgco_rgss_seed={UINT32_C(0x6040002C),"rgss_seed",sxgco_rgss_seed_fields,SX_COUNT(sxgco_rgss_seed_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_rgss(sxgco_view*v)
{uint64_t e=v->c->size,p=8,x,n,off,version;uint32_t key=UINT32_C(0xDEADCAFE);if(!GC_ROW(rgss_header,0,e)||!sxgco_word(v,7,1,false,&version,e))return false;
 if(version==1){while(p<e){if(!GC_ROW(rgss_name_size,p,e)||!sxgco_word(v,p,4,false,&x,e))return false;n=(uint32_t)x^key;key=key*7U+3U;p+=4;if(!n||n>1024||!sxgco_table(v,&sxgco_encoded_byte,p,n,e))return false;p+=n;for(uint64_t i=0;i<n;i++)key=key*7U+3U;if(!GC_ROW(rgss_data_size,p,e)||!sxgco_word(v,p,4,false,&x,e))return false;n=(uint32_t)x^key;key=key*7U+3U;p+=4;if(!sxgco_span(v,p,n,e))return false;p+=n;}return true;}
 if(version!=3||!GC_ROW(rgss_seed,8,e)||!sxgco_word(v,8,4,false,&x,e))return false;key=(uint32_t)x*9U+3U;p=12;
 while(p<e){if(!sxgco_word(v,p,4,false,&off,e))return false;off=(uint32_t)off^key;if(!off)return GC_ROW(rgss_end3,p,e);if(!GC_ROW(rgss_entry3,p,e)||!sxgco_word(v,p+12,4,false,&x,e))return false;n=(uint32_t)x^key;if(!n||n>1024||!sxgco_table(v,&sxgco_encoded_byte,p+16,n,e))return false;p+=16+n;}return false;}
bool sx_rpg_maker_rgssad_build(sxgco_view*v)
{
 return sxgco_rgss(v);
}
#undef GC_ROW
