/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * F.Sauer & Y.Grolet's Art & Magic module (.AAM) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamip_art_marker_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
};
const sx_layout sxamip_art_marker={UINT32_C(0x60900037),"art_marker",sxamip_art_marker_fields,SX_COUNT(sxamip_art_marker_fields),SX_LE};
#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
static bool sxamip_art(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,x,p,q;
 if(e<0x160||!sxamip_eq(v,26,"EXIT",4,e)||!sxamip_eq(v,e-4,"EXIT",4,e)||!sxamip_be(v,0xe2,2,&x,e))return false;
 p=(x+0xe2)&65535;if(p&32768)return false;
 if(!sxamip_be(v,0x15e,2,&x,e))return false;q=(x+0x155)&65535;
 if(q&32768||q<p+40||(q-p-40)%4||!sxamip_span(v,p,q-p+4,e))return false;
 if(!AP_ROW(art_table_operand,0xe2,e)||!AP_ROW(art_limit_operand,0x15e,e)||!AP_ROW(art_marker,26,e)||!AP_ROW(art_marker,e-4,e))return false;
 for(unsigned i=0;i<5;i++)if(!AP_ROW(art_relocation,p+i*8,e))return false;
 return sxamip_table(v,&sxamip_art_relocation,p+40,(q-p-40)/4+1,e);
}
bool sx_sauer_artandmagic_build(sxamip_view*v)
{
 return sxamip_art(v);
}
#undef AP_ROW
