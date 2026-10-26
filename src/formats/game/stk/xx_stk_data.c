/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * stk data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_size32_fields[]={
 SX_FIELD("bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxgco_size32={UINT32_C(0x60400005),"size32",sxgco_size32_fields,SX_COUNT(sxgco_size32_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_stk(sxgco_view*v)
{uint64_t e=v->c->size,n,at,meta,stored,plain,p=32;uint8_t h[6];if(!sxgco_read(v,0,h,6,e))return false;
 if(!xx_rt_memcmp(h,"STK2.",5)){if(!GC_ROW(stk2_header,0,e)||!sxgco_word(v,28,4,false,&at,e)||!GC_ROW(stk2_directory,at,e)||!sxgco_word(v,at,4,false,&n,e)||!sxgco_word(v,at+4,4,false,&meta,e)||meta<at+8||!sxgco_table(v,&sxgco_filename_byte,at+8,meta-at-8,e)||!sxgco_table(v,&sxgco_stk2_entry,meta,n,e))return false;
 for(uint64_t i=0;i<n;i++){if(!sxgco_word(v,meta+61*i+40,4,false,&stored,e)||!sxgco_word(v,meta+61*i+44,4,false,&plain,e)||!sxgco_span(v,p,stored,at))return false;if(stored>=4&&stored!=plain&&!GC_ROW(size32,p,at))return false;p+=stored;}return p==at;}
 if(!GC_ROW(count16,0,e)||!sxgco_word(v,0,2,false,&n,e)||!sxgco_table(v,&sxgco_stk_entry,2,n,e))return false;
 for(uint64_t i=0;i<n;i++){uint64_t method;if(!sxgco_word(v,2+i*22+17,4,false,&p,e)||!sxgco_word(v,2+i*22+21,1,false,&method,e))return false;if(method&&!GC_ROW(size32,p,e))return false;}return true;}
bool sx_stk_build(sxgco_view*v)
{
 return sxgco_stk(v);
}
#undef GC_ROW
