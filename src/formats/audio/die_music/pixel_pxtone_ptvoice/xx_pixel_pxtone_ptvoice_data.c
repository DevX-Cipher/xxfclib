/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Amaya 'Pixel' Daisuke's pxtone Voice instrument (.PTVOICE) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_pxt_voice_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","int32",8,4,SX_ID),
 SX_FIELD("payload_bytes","int32",12,4,SX_SIZE),
};
const sx_layout sxmn_pxt_voice_header={UINT32_C(0x60760022),"pxt_voice_header",sxmn_pxt_voice_header_fields,SX_COUNT(sxmn_pxt_voice_header_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_ptvoice(sxmn_view*v)
{uint64_t end=v->c->size,z;return MN_ROW(pxt_voice_header,0,end)&&sxmn_word(v,12,4,false,&z,end)&&z<=INT32_MAX&&sxmn_span(v,16,z,end);}
bool sx_pixel_pxtone_ptvoice_build(sxmn_view*v)
{
 return sxmn_ptvoice(v);
}
#undef MN_ROW
