/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * obi_soundtracker_stk data structures, moved out of the modvariants schema family. */
#include "../../../xx_format_schema_modvariants.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmodv_soundtracker_title_fields[]={
 SX_FIELD("title","char[20]",0,20,SX_NONE),
};
const sx_layout sxmodv_soundtracker_title={UINT32_C(0x609B000C),"soundtracker_title",sxmodv_soundtracker_title_fields,SX_COUNT(sxmodv_soundtracker_title_fields),SX_BE};
#define SMV_ROW(n,p) sxmodv_row(v,&sxmodv_##n,p)
static bool sxmodv_soundtracker(sxmodv_view*v){
 uint64_t n=0,x;if(!SMV_ROW(soundtracker_title,0)||!sxmodv_span(v,20,580))return false;
 for(unsigned i=0;i<15;i++)if(!SMV_ROW(soundtracker_sample,20+i*30))return false;
 if(!SMV_ROW(soundtracker_controls,470))return false;
 /* The original loader scans every stored order slot to locate sample data. */
 for(unsigned i=0;i<128;i++){if(!sxmodv_word(v,472+i,1,&x)||!SMV_ROW(mod_order,472+i))return false;if(n<x+1)n=x+1;}
 if(n>64)return false;
 for(uint64_t i=0;i<n;i++)for(unsigned j=0;j<256;j++)if(!SMV_ROW(soundtracker_cell,600+i*1024+j*4))return false;
 return true;
}
bool sx_obi_soundtracker_stk_build(sxmodv_view*v)
{
 return sxmodv_soundtracker(v);
}
#undef SMV_ROW
