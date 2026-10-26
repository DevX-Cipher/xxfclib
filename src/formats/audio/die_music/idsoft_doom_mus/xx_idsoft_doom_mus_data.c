/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * idSoft's DOOM music module (.MUS) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_mus_instrument_fields[]={
 SX_FIELD("instrument","uint16",0,2,SX_ID),
};
const sx_layout sxmn_mus_instrument={UINT32_C(0x60760009),"mus_instrument",sxmn_mus_instrument_fields,SX_COUNT(sxmn_mus_instrument_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_mus(sxmn_view*v)
{uint64_t e=v->c->size,n,at,z;return MN_ROW(mus_header,0,e)&&sxmn_word(v,12,2,false,&n,e)&&sxmn_table(v,&sxmn_mus_instrument,16,n,e)&&sxmn_word(v,6,2,false,&at,e)&&sxmn_word(v,4,2,false,&z,e)&&at>=16+n*2&&sxmn_span(v,at,z,e);}
bool sx_idsoft_doom_mus_build(sxmn_view*v)
{
 return sxmn_mus(v);
}
#undef MN_ROW
