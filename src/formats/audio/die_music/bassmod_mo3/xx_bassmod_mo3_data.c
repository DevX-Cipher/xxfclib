/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MO3 MOD module (.MO3) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_mo3_header_fields[]={
 SX_FIELD("magic","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("decoded_music_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmw_mo3_header={UINT32_C(0x60870015),"mo3_header",sxmw_mo3_header_fields,SX_COUNT(sxmw_mo3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_mo3_packed_length_fields[]={
 SX_FIELD("packed_music_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxmw_mo3_packed_length={UINT32_C(0x60870016),"mo3_packed_length",sxmw_mo3_packed_length_fields,SX_COUNT(sxmw_mo3_packed_length_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
static bool sxmw_mo3(sxmw_view*v)
{uint64_t end=v->c->size,ver,n;if(!sxmw_eq(v,0,"MO3",3,end)||!sxmw_u(v,3,1,&ver,end)||ver>5||!sxmw_u(v,4,4,&n,end)||n<=422||n>=UINT64_C(0x20000000)||!MW_ROW(mo3_header,0,end))return false;
 if(ver==5){if(!sxmw_u(v,8,4,&n,end)||!sxmw_span(v,12,n,end)||!MW_ROW(mo3_packed_length,8,end))return false;}return true;}
bool sx_bassmod_mo3_build(sxmw_view*v)
{
 return sxmw_mo3(v);
}
#undef MW_ROW
