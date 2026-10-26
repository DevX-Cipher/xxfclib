/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * krml data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_krml_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entries","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxgco_krml_header={UINT32_C(0x60400007),"krml_header",sxgco_krml_header_fields,SX_COUNT(sxgco_krml_header_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_krml(sxgco_view*v)
{uint64_t n,e=v->c->size;return GC_ROW(krml_header,0,e)&&sxgco_word(v,4,2,false,&n,e)&&sxgco_table(v,&sxgco_krml_entry,6,n,e);}
bool sx_krml_build(sxgco_view*v)
{
 return sxgco_krml(v);
}
#undef GC_ROW
