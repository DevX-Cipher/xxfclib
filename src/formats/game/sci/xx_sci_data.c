/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sci data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_sci_entry_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("name","char[50]",1,50,SX_STRING),
 SX_FIELD("data_bytes","int32",51,4,SX_SIZE),
};
const sx_layout sxgco_sci_entry={UINT32_C(0x6040000A),"sci_entry",sxgco_sci_entry_fields,SX_COUNT(sxgco_sci_entry_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_sci(sxgco_view*v)
{uint64_t p=46,e=v->c->size,n;bool ok=GC_ROW(sci_header,0,e);while(ok&&p<e){if(!sxgco_span(v,p,55,e))break;if(!GC_ROW(sci_entry,p,e)||!sxgco_word(v,p+51,4,false,&n,e))return false;p+=55;if(n>INT32_MAX||n>e-p)break;p+=n;}return ok;}
bool sx_sci_build(sxgco_view*v)
{
 return sxgco_sci(v);
}
#undef GC_ROW
