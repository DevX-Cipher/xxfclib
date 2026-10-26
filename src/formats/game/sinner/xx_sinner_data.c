/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sinner data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_sinner_header_fields[]={
 SX_FIELD("magic","char[10]",0,10,SX_SIGNATURE),
 SX_FIELD("unknown","bytes",10,10,SX_NONE),
 SX_FIELD("entries","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxgco_sinner_header={UINT32_C(0x60400016),"sinner_header",sxgco_sinner_header_fields,SX_COUNT(sxgco_sinner_header_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_sinner(sxgco_view*v)
{uint64_t n,e=v->c->size;return GC_ROW(sinner_header,0,e)&&sxgco_word(v,20,4,false,&n,e)&&sxgco_table(v,&sxgco_sinner_entry,24,n,e);}
bool sx_sinner_build(sxgco_view*v)
{
 return sxgco_sinner(v);
}
#undef GC_ROW
