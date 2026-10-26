/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * seadata data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_seadata_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxgco_seadata_header={UINT32_C(0x6040000B),"seadata_header",sxgco_seadata_header_fields,SX_COUNT(sxgco_seadata_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_seadata_end_fields[]={
 SX_FIELD("terminator","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxgco_seadata_end={UINT32_C(0x6040000D),"seadata_end",sxgco_seadata_end_fields,SX_COUNT(sxgco_seadata_end_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_seadata(sxgco_view*v)
{uint64_t p=4,e=v->c->size,t,next,n;if(!GC_ROW(seadata_header,0,e))return false;while(p<e){if(!sxgco_word(v,p,4,false,&t,e))return false;if(!t)return GC_ROW(seadata_end,p,e);if(t!=UINT32_C(0x23324554)||!GC_ROW(seadata_entry,p,e)||!sxgco_word(v,p+4,4,false,&next,e)||!sxgco_word(v,p+8,4,false,&n,e)||next>INT32_MAX||n>INT32_MAX||next<=p||!sxgco_span(v,p+12,n+1,next)||!sxgco_table(v,&sxgco_filename_byte,p+12,n+1,next))return false;p=next;}return false;}
bool sx_seadata_build(sxgco_view*v)
{
 return sxgco_seadata(v);
}
#undef GC_ROW
