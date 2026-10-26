/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * beatthehouse data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_bth_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("payload_kind","uint8",3,1,SX_ID),
 SX_FIELD("decoded_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxgco_bth_header={UINT32_C(0x60400012),"bth_header",sxgco_bth_header_fields,SX_COUNT(sxgco_bth_header_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_house(sxgco_view*v){return GC_ROW(bth_header,0,v->c->size);}
bool sx_beatthehouse_build(sxgco_view*v)
{
 return sxgco_house(v);
}
#undef GC_ROW
